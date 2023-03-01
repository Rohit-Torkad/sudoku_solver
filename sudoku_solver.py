from flask import Flask, request, jsonify
import subprocess

app = Flask(__name__)

@app.route('/solve', methods=['POST'])
def solve():
  # Extract the puzzle from the JSON request body
  data = request.get_json()
  puzzle = data['puzzle']

  # Call the C program as a subprocess to solve the puzzle
  result = subprocess.run(['./sudoku', puzzle], capture_output=True)

  # Extract the solved puzzle from the stdout output of the C program
  solution = result.stdout.decode().strip()

  # Return the solved puzzle as a JSON response
  return jsonify({ 'solution': solution })

if __name__ == '__main__':
  app.run(debug=True)
