const input = document.getElementById('todo-input');
const addButton = document.getElementById('add-btn');
const todoList = document.getElementById('todo-list');


function addTodo() {
    const task = input.value;
    if (task.trim() === "") return;
    
    const listItem = document.createElement('li');

    const taskText = document.createElement('span');
    taskText.textContent = task;

    const completeButton = document.createElement('button');
    completeButton.textContent = 'Complete';
    completeButton.addEventListener('click', () => {
        listItem.classList.toggle('completed');
    });

    const deleteButton = document.createElement('button');
    deleteButton.textContent = 'Delete';
    deleteButton.addEventListener('click', () => {
        todoList.removeChild(listItem);
    });

    listItem.appendChild(taskText);
    listItem.appendChild(completeBtn);
    listItem.appendChild(deleteBtn);
    todoList.appendChild(listItem);

    input.value = '';
}

addButton.addEventListener('click', addTodo);

input.addEventListener('keypress', (e) => {
    if (e.key === 'Enter') {
        addTodo();

    }
});


