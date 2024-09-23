const input = document.getElementById('todo-input');
const addButton = document.getElementById('add-btn');
const todoList = document.getElementById('todo-list');


function addTodo() {
    const task = input.value;
    if (task.trim() === "") return;
    
    const listItem = document.createElement('li');

    const taskText = document.createElement('span');
    taskText.textContent = task;

    const completeBtn = document.createElement('button');
    completeBtn.textContent = 'Complete';
    completeBtn.addEventListener('click', () => {
        listItem.classList.toggle('completed');
    });

    const deleteBtn = document.createElement('button');
    deleteBtn.textContent = 'Delete';
    deleteBtn.addEventListener('click', () => {
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


