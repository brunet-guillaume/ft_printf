# ft_printf (42 school)
> 📑 &ensp;Subject [here](/subject/subject_ft_printf.pdf) <br />
✅ &ensp;**125**/100

Project in the first circle in 42 school.

## Mandatory part

The idea here, is to implement some parts of the printf function :

<table>
    <tr><td width="50"><strong>%c</strong></td><td>prints a single character</td></tr>
    <tr><td><strong>%s</strong></td><td>prints a string</td></tr>
    <tr><td><strong>%p</strong></td><td>prints the address of a pointer in hexadecimal format</td></tr>
    <tr><td><strong>%d</strong></td><td>prints a decimal (base 10) number</td></tr>
    <tr><td><strong>%i</strong></td><td>prints an integer in base 10</td></tr>
    <tr><td><strong>%u</strong></td><td>prints an unsigned decimal (base 10) number</td></tr>
    <tr><td><strong>%x</strong></td><td>prints a number in hexadecimal (base 16) lowercase format</td></tr>
    <tr><td><strong>%X</strong></td><td>prints a number in hexadecimal (base 16) uppercase format</td></tr>
    <tr><td><strong>%%</strong></td><td>prints a percent sign</td></tr>
</table>

## Bonus part

In the bonus part, we need to manage any combination of the field minimum width and the following flags :

<table>
    <tr><td width="50"><strong>'-'</strong></td><td>left-justify within the given field width</td></tr>
    <tr><td><strong>'0'</strong></td><td>left-pads the number with zeroes (0) instead of spaces when padding is specified</td></tr>
    <tr><td><strong>'.'</strong></td><td>for integer specifiers (d, i, u, x, X): precision ('.precision') specifies the minimum number of digits to be written</td></tr>
    <tr><td><strong>'#'</strong></td><td>used with x or X specifiers the value is preceeded with 0x or 0X respectively for values different than zero</td></tr>
    <tr><td><strong>' '</strong></td><td>if no sign is going to be written, a blank space is inserted before the value</td></tr>
    <tr><td><strong>'+'</strong></td><td>forces to preceed the result with a plus or minus sign (+ or -) even for positive numbers</td></tr>
</table>

### Compilation
```bash
git clone https://gitlab.com/uotiug42/unix/ft_printf.git
cd ft_printf
# mandatory + bonus part :
make
```