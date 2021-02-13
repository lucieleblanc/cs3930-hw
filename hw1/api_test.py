import requests
params = {"words": 10, "paragraphs": 1, "format": "json"}
response = requests.get(f"http://www.colr.org/json/colors/random/5", 
	params=params,
 	headers={}
)
data = response.json()
colors = data['colors']

for c in colors:
    color_string = c['hex']
    r = color_string[0:2]
    g = color_string[2:4]
    b = color_string[4:6]
    print(r, g, b)
