void T_1 F_1 ( void )
{
switch ( V_1 ) {
case V_2 :
case V_3 :
V_4 = V_5 ;
break;
case V_6 :
V_4 = V_7 ;
break;
case V_8 :
case V_9 :
case V_10 :
case V_11 :
default:
V_4 = V_12 ;
break;
}
}
static void V_5 ( void )
{
asm(".set\tpush\n\t"
".set\tnoreorder\n\t"
"1:\tbc0f\t1b\n\t"
"nop\n\t"
".set\tpop");
}
static void V_7 ( void )
{
asm(".set\tpush\n\t"
".set\tnoreorder\n\t"
"mfc0\t$2,$12\n\t"
"lui\t$3,0x8000\n\t"
"or\t$3,$2,$3\n\t"
"mtc0\t$3,$12\n\t"
"nop\n"
"1:\tbc3f\t1b\n\t"
"nop\n\t"
"mtc0\t$2,$12\n\t"
"nop\n\t"
".set\tpop"
: : : "$2", "$3");
}
static void V_12 ( void )
{
F_2 () ;
}
