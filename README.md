# Stack-Applications
Stack applications in data structure: 
      1. Converting an expression from infix to postfix. 
      2. Evaluating a postfix expression.
 
<b>Converting an expression from infix to postfix:</b>
-algorithm
opstk= the empty stack;
while (not end of input)
{
symb=next input character;
if (symb is an operand)
add symb to the postfix string
 else
 {
while (!empty()&&prcd(stacktop(), symb))
{
topsym=pop();
add topsymbto the postfix string;
 } /*end while*/
 if (empty() II symb != ‘)’)
 push(symb);
 else /* pop the open parenthesis and discard it */
 topsymb= pop();
} /* end else*/
} /* end while*/
/*output any remaining operators*/
while (!empty())
{
topsymb=pop();
add topsymb to the postfix string;
} /* end while*/
