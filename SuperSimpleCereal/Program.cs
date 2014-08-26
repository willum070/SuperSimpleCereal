using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO.Ports;

namespace SuperSimpleCereal
{
    class Program
    {
        static void Main(string[] args)
        {
            // Declare the serial port object.
            SerialPort sp = new SerialPort("COM6", 9600, Parity.None, 8, StopBits.One);

            // Open the serial port (close first if it's already open).
            if (sp.IsOpen == true) sp.Close();
            sp.Open();

            // Send "?" command to get device string.
            sp.Write("[?]");

            // Read the result.
            string rawData = sp.ReadTo("]");

            // Print the result to the console.
            Console.WriteLine(rawData);

            // Hold the window open.
            Console.Read();
        }
    }
}
