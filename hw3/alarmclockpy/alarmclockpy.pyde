import socket

# use ifconfig -a to find this IP.
# If your pi is the first and only device connected to the ESP32, 
# this should be the correct IP by default on the raspberry pi
LOCAL_UDP_IP = "192.168.1.2"
SHARED_UDP_PORT = 4210
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)  # Internet  # UDP
sock.bind((LOCAL_UDP_IP, SHARED_UDP_PORT))

panic = False

alarmSize = 200
alarmX = 200
alarmY = 200

def calmBg():
    background(255, 255, 255)
    noStroke()

    fill(66, 38, 17)
    rect(width / 2, height * (5.0/6), width, height / 3.0)
    fill(153, 73, 15)
    rect(width / 2, height * (3.0/4), width, height / 6.0)

    fill(153, 153, 153)
    arc(alarmX - 80, alarmY - 70, 100, 100, radians(135), radians(320))
    arc(alarmX + 80, alarmY - 70, 100, 100, radians(220), radians(405))

    fill(197, 235, 225)
    ellipse(alarmX, alarmY, alarmSize * 1.1, alarmSize * 1.1)
    fill(255, 255, 255)
    ellipse(alarmX, alarmY, alarmSize, alarmSize)

    fill(130, 130, 130)
    ellipse(alarmX + 110, alarmY - 110, alarmSize / 15, alarmSize / 15)
    ellipse(alarmX - 110, alarmY - 110, alarmSize / 15, alarmSize / 15)

    fill(46, 46, 46)
    pushMatrix()
    translate(alarmX, alarmY)
    for i in range(12):
        rect(0, alarmSize/2.5, alarmSize / 25, alarmSize / 15)
        rotate(radians(30))

    popMatrix()

    pushMatrix()
    translate(alarmX, alarmY)
    rotate(radians(40))
    fill(150, 150, 150)
    rect(0, alarmSize/1.7, alarmSize / 10, alarmSize / 10)
    rotate(radians(-80))
    rect(0, alarmSize/1.7, alarmSize / 10, alarmSize / 10)
    popMatrix()


def panicBg():

    pushMatrix()

    rotate(radians(random(-5, 5)))

    background(237, 121, 121)

    fill(173, 88, 28)
    rect(width / 2, height * (5.0/6), width, height / 3.0)
    fill(219, 124, 57)
    rect(width / 2, height * (3.0/4), width, height / 6.0)

    noStroke()
    fill(0, 0, 0)
    ellipse(alarmX, alarmY, alarmSize * 1.1, alarmSize * 1.1)
    fill(255, 136, 0)
    ellipse(alarmX, alarmY, alarmSize, alarmSize)

    fill(57, 97, 150)
    arc(alarmX - 80, alarmY - 70, 100, 100, radians(135), radians(320))
    arc(alarmX + 80, alarmY - 70, 100, 100, radians(220), radians(405))
    fill(28, 28, 28)
    ellipse(alarmX + 110, alarmY - 110, alarmSize / 15, alarmSize / 15)
    ellipse(alarmX - 110, alarmY - 110, alarmSize / 15, alarmSize / 15)

    fill(46, 46, 46)
    pushMatrix()
    translate(alarmX, alarmY)
    for i in range(12):
        rect(0, alarmSize/2.5, alarmSize / 25, alarmSize / 15)
        rotate(radians(30))

    popMatrix()

    pushMatrix()
    translate(alarmX, alarmY)
    rotate(radians(40))
    fill(61, 61, 61)
    rect(0, alarmSize/1.7, alarmSize / 10, alarmSize / 10)
    rotate(radians(-80))
    rect(0, alarmSize/1.7, alarmSize / 10, alarmSize / 10)
    popMatrix()

    popMatrix()


def drawCalm():
    fill(255, 255, 255)
    ellipse(alarmX, alarmY, alarmSize / 1.5, alarmSize / 1.5)

    fill(82, 82, 82)
    text("rest time", alarmX, alarmY - 20)

    fill(0, 0, 0)
    ellipse(alarmX, alarmY, alarmSize / 40, alarmSize / 40)

    pushMatrix()
    translate(alarmX, alarmY)
    rotate(radians(millis()/10))
    ellipse(0, alarmSize/6.5, alarmSize / 20, alarmSize / 3)
    popMatrix()

    pushMatrix()
    translate(alarmX, alarmY)
    rotate(radians(millis()/600))
    ellipse(0, alarmSize/10, alarmSize / 20, alarmSize / 5)
    popMatrix()


def drawPanic():
    fill(255, 136, 0)
    ellipse(alarmX, alarmY, alarmSize / 1.5, alarmSize / 1.5)

    fill(255, 0, 4)
    text("WAKE UP", alarmX, alarmY - 20)

    fill(0, 0, 0)
    ellipse(alarmX, alarmY, alarmSize / 40, alarmSize / 40)

    pushMatrix()
    translate(alarmX, alarmY)
    rotate(radians(random(0, 360)))
    ellipse(random(-5, 5), alarmSize/random(6,9), alarmSize / 20, alarmSize / 3)
    popMatrix()

    pushMatrix()
    translate(alarmX, alarmY)
    rotate(radians(random(0, 360)))
    ellipse(random(5, -5), alarmSize/random(6,8), alarmSize / 20, alarmSize / 5)
    popMatrix()

def setup():
    size(400, 400)
    rectMode(CENTER)
    textAlign(CENTER, CENTER)
    calmBg()
    noStroke()

def draw():
	
	data, addr = sock.recvfrom(2048)
	if data == "2":
		panic = True
		pass
	print(data)
	
	if (panic):
		panicBg()
		drawPanic()
		pass
	else:
		pass
		drawCalm()

"""
def loop():
    while True:

if __name__ == "__main__":
    loop()
	"""

