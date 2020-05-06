import threading
import time
from tkinter import *

def test_thread(target):
    for i in range(3):
        print('from test_thread ', threading.current_thread())
        time.sleep(1)
        target.event_generate('<<progress>>', x=i, y=3)
    
def progress(*args):
    print('progress ', threading.current_thread(), args)

print('from main ', threading.current_thread())
window = Tk()
window.bind('<<progress>>', progress)
window.geometry("300x400")
thread = threading.Thread(target=test_thread, args=(window,))
thread.start()
window.mainloop()
