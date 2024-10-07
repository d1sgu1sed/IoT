import serial
responses = {'d': 7,  # "led_off" 
             'u': 6,  # "led_on" 
             'p': 4}  # 0 -> 1023 zero fill to leftside
port_led = "/dev/ttyUSB1" # "COM4" or similar for windows
port_photo = "/dev/ttyUSB0" # "COM4" or similar for windows
connection_led = serial.Serial(port_led, baudrate=9600, timeout=1) # baudrate=9600
connection_photo = serial.Serial(port_photo, baudrate=9600, timeout=1) # baudrate=9600

def send_command(cmd: str, response_len: int, connection: serial.Serial) -> str:
    str_resp: str = ""
    connection.write(cmd.encode())
    if response_len > 0:
        if connection.in_waiting >= response_len:
            resp = connection.read(response_len)
            str_resp = resp.decode()
    return str_resp

while True:
    photo_val_resp: str = send_command('p', responses['p'], connection_photo)
    photo_val = int(photo_val_resp)
    print(photo_val)
    if photo_val > 100:
        resp = send_command('u', responses['u'], connection_led)
    else:
        resp = send_command('d', responses['d'], connection_led)