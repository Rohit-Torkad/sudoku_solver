$(document).ready(function() {
    // Handle form submit event
    $('#sudoku-form').submit(function(event) {
      event.preventDefault();
  
      // Get the puzzle from the form
      var puzzle = $('#sudoku-puzzle').val();
  
      // Send the puzzle to the server using an AJAX request
      $.ajax({
        url: '/solve',
        type: 'POST',
        contentType: 'application/json',
        data: JSON.stringify({'puzzle': puzzle}),
        success: function(response) {
          // Update the web page with the solved puzzle
          $('#sudoku-solution').text(response.solved_puzzle);
        },
        error: function(error) {
          console.log(error);
        }
      });
    });
  });
  
  document.getElementById('submit-button').addEventListener('click', function() {
    // Get the Sudoku puzzle from the input field
    var puzzle = document.getElementById('puzzle-input').value;
  
    // Send the puzzle to the server using an AJAX request
    fetch('/solve', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json'
      },
      body: JSON.stringify({ puzzle: puzzle })
    })
    .then(function(response) {
      return response.json();
    })
    .then(function(data) {
      // Update the contents of the <div> tag with the solved puzzle
      document.getElementById('solution-output').textContent = data.solution;
    })
    .catch(function(error) {
      console.log(error);
    });
  });
  