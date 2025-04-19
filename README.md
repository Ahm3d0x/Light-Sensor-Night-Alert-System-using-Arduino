# 🔦 Light Sensor & Night Alert System using Arduino

A smart and simple project using a Light Dependent Resistor (LDR) to detect ambient light level and automatically activate warning LEDs based on the percentage of darkness. If darkness reaches a critical level, a buzzer is triggered as an alert system.

---

## 🎯 Project Concept

The system operates based on the surrounding light intensity:

- If the **light is strong (darkness < 30%)**, a green LED turns on to indicate safety.
- As darkness increases by every 10%, one additional warning LED is activated.
- When **darkness reaches 70% or above**, **all 5 warning LEDs** and the **buzzer** are triggered.

---

## 🧠 Components Used

| Component       | Quantity | Notes                        |
|----------------|----------|-------------------------------|
| Arduino UNO     | 1        | Or any compatible board       |
| LDR Sensor      | 1        | Light sensor                  |
| 10K Resistor    | 1        | Used with the LDR             |
| LEDs            | 6        | 5 for warning, 1 green for light |
| Buzzer          | 1        | For night alert               |
| Jumper Wires    | Several  | For connections               |
| Breadboard      | 1        | For assembling the circuit    |

---

## ⚡ Circuit Connections

| Arduino Pin     | Connected To             |
|----------------|---------------------------|
| A0              | LDR sensor input          |
| 2               | Green LED (for daylight)  |
| 3 → 7           | 5 Warning LEDs            |
| 8               | Buzzer                    |
| GND / 5V        | Power lines for components|

- The LDR is connected between 5V and A0, with a 10K resistor between A0 and GND.
- Light level is mapped from analog value to a percentage between 0% and 100%.

---

## 💡 Code Features

- Efficient use of **arrays** and **for loops** to reduce redundancy.
- Easily configurable number of LEDs or sensitivity threshold.
- Real-time monitoring via **Serial Monitor** for light percentage display.

---

## 🧾 Sample Serial Output

**


---

## 📁 Project Files

- `sketch.ino` → Arduino code for the system.
- `README.md` → This documentation file.

---

## 👨‍💻 Developer Info

- 👨‍🎓 **Name**: Ahmed Mohamed Atiya  
- 🏫 **University**: Zagazig University – Faculty of Engineering – Communications Department  
- 📧 **Email**: ah2005211@gmail.com  
- 🌍 **GitHub**: [github.com/ahmedatya](https://github.com/ahmedatya) *(Update with your actual username)*

---

## 🔧 Future Enhancements

- Add an LCD display to show light level visually.
- Use Wi-Fi or Bluetooth to send remote alerts.
- Integrate with a battery for emergency power.
- Add a motion sensor for smart activation.

---

## 📸 Project Images

*Add real photos of your setup here if available.*

---

## ⭐ Thank You!

If you found this project helpful, give it a ⭐ on GitHub and feel free to fork or enhance it!
