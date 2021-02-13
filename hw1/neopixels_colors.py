# Original source: AdaFruit
import time
import board
import neopixel
import requests

pixel_pin = board.D21

num_pixels = 8

ORDER = neopixel.RGB

pixels = neopixel.NeoPixel(
    pixel_pin, num_pixels, brightness=0.2, auto_write=False, pixel_order=ORDER
)


def random_colors():
    params = {"format": "json"}
    response = requests.get(f"http://www.colr.org/json/colors/random/5", 
            params=params,
            headers={}
    )
    data = response.json()
    colors = data['colors']
    color_vals = []

    if len(colors) == 0:
        print('waiting for colors...')
        sleep(10)

    for c in colors:
        color_string = c['hex']
        if len(color_string) != 6:
            continue
        r = int(color_string[0:2], 16)
        g = int(color_string[2:4], 16)
        b = int(color_string[4:6], 16)
        color = (r, g, b)
        color_vals.append(color)
        print(color)

    return color_vals

while True:
    colors = random_colors()
    for c in colors:
        pixels.fill(c)
        pixels.show()
        time.sleep(1)


