import mysql.connector

conn = mysql.connector.connect(
  host="localhost",
  user="admin",
  password="123456",
  database="Temp_db"
)

cursor = conn.cursor()

sql = "insert into sensors(temp,humid) values (32,76)"
cursor.execute(sql)

conn.commit()

cursor.execute("SELECT * FROM sensors")

result = cursor.fetchall()

for x in result:
  print(x)
  print(type(x))