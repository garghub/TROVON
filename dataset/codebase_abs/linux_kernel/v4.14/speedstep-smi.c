static int F_1 ( void )
{
T_1 V_1 , V_2 , V_3 , V_4 ;
T_1 V_5 = V_6 ;
unsigned char V_7 [] = L_1 ;
V_1 = ( V_8 & 0xffffff00 ) | ( V_9 & 0xff ) ;
V_3 = F_2 ( V_7 ) ;
F_3 ( L_2 ,
V_1 , V_10 ) ;
__asm__ __volatile__(
"push %%ebp\n"
"out %%al, (%%dx)\n"
"pop %%ebp\n"
: "=D" (result),
"=a" (dummy), "=b" (dummy), "=c" (dummy), "=d" (dummy),
"=S" (dummy)
: "a" (command), "b" (function), "c" (0), "d" (smi_port),
"D" (0), "S" (magic)
: "memory"
);
F_3 ( L_3 , V_2 ) ;
return V_2 ;
}
static int F_4 ( unsigned int * V_11 , unsigned int * V_12 )
{
T_1 V_1 , V_2 = 0 , V_13 , V_14 , V_15 , V_4 ;
T_1 V_16 = 0 ;
T_1 V_5 = V_17 ;
if ( ! ( V_18 . V_19 & 0xFFFF ) ) {
F_3 ( L_4 ) ;
return - V_20 ;
}
V_1 = ( V_8 & 0xffffff00 ) | ( V_9 & 0xff ) ;
F_3 ( L_5 ,
V_1 , V_10 ) ;
__asm__ __volatile__(
"push %%ebp\n"
"out %%al, (%%dx)\n"
"pop %%ebp"
: "=a" (result),
"=b" (high_mhz),
"=c" (low_mhz),
"=d" (state), "=D" (edi), "=S" (dummy)
: "a" (command),
"b" (function),
"c" (state),
"d" (smi_port), "S" (0), "D" (0)
);
F_3 ( L_6 ,
V_2 , V_15 , V_14 ) ;
if ( ( V_14 + V_15 ) < 600 )
return - V_21 ;
* V_12 = V_14 * 1000 ;
* V_11 = V_15 * 1000 ;
return V_2 ;
}
static void F_5 ( unsigned int V_16 )
{
unsigned int V_2 = 0 , V_1 , V_22 , V_4 ;
unsigned long V_23 ;
unsigned int V_5 = V_24 ;
unsigned int V_25 = 0 ;
if ( V_16 > 0x1 )
return;
F_6 () ;
F_7 ( V_23 ) ;
V_1 = ( V_8 & 0xffffff00 ) | ( V_9 & 0xff ) ;
F_3 ( L_7
L_8 ,
V_16 , V_1 , V_10 ) ;
do {
if ( V_25 ) {
F_3 ( L_9 ,
V_25 , V_2 ) ;
F_8 () ;
F_9 ( V_25 * 50 ) ;
F_10 () ;
}
V_25 ++ ;
__asm__ __volatile__(
"push %%ebp\n"
"out %%al, (%%dx)\n"
"pop %%ebp"
: "=b" (new_state), "=D" (result),
"=c" (dummy), "=a" (dummy),
"=d" (dummy), "=S" (dummy)
: "a" (command), "b" (function), "c" (state),
"d" (smi_port), "S" (0), "D" (0)
);
} while ( ( V_22 != V_16 ) && ( V_25 <= V_26 ) );
F_11 ( V_23 ) ;
F_12 () ;
if ( V_22 == V_16 )
F_3 ( L_10
L_11 ,
( V_27 [ V_22 ] . V_28 / 1000 ) ,
V_25 , V_2 ) ;
else
F_13 ( L_12 ,
V_16 , V_22 , V_2 ) ;
return;
}
static int F_14 ( struct V_29 * V_30 , unsigned int V_31 )
{
F_5 ( V_31 ) ;
return 0 ;
}
static int F_15 ( struct V_29 * V_30 )
{
int V_2 ;
unsigned int * V_11 , * V_12 ;
if ( V_30 -> V_32 != 0 )
return - V_20 ;
V_2 = F_1 () ;
if ( V_2 ) {
F_3 ( L_13 ) ;
return - V_21 ;
}
V_11 = & V_27 [ V_33 ] . V_28 ;
V_12 = & V_27 [ V_34 ] . V_28 ;
V_2 = F_4 ( V_11 , V_12 ) ;
if ( V_2 ) {
F_3 ( L_14
L_15 ) ;
V_2 = F_16 ( V_35 ,
V_11 , V_12 ,
NULL ,
& F_5 ) ;
if ( V_2 ) {
F_3 ( L_16
L_17 ) ;
return V_2 ;
} else
F_3 ( L_18 ) ;
}
return F_17 ( V_30 , V_27 ) ;
}
static unsigned int F_18 ( unsigned int V_32 )
{
if ( V_32 )
return - V_20 ;
return F_19 ( V_35 ) ;
}
static int F_20 ( struct V_29 * V_30 )
{
int V_2 = F_1 () ;
if ( V_2 )
F_3 ( L_19 ) ;
return V_2 ;
}
static int T_2 F_21 ( void )
{
if ( ! F_22 ( V_36 ) )
return - V_20 ;
V_35 = F_23 () ;
switch ( V_35 ) {
case V_37 :
case V_38 :
case V_39 :
break;
default:
V_35 = 0 ;
}
if ( ! V_35 ) {
F_3 ( L_20 ) ;
return - V_20 ;
}
F_3 ( L_21
L_22 ,
V_18 . V_40 , V_18 . V_1 ,
V_18 . V_19 , V_18 . V_41 ) ;
if ( ( V_18 . V_40 != 0x47534943 ) && (
( V_10 == 0 ) || ( V_9 == 0 ) ) )
return - V_20 ;
if ( V_8 == 1 )
V_8 = 0x47534943 ;
else
V_8 = V_18 . V_40 ;
if ( ( V_10 > 0xff ) || ( V_10 < 0 ) )
return - V_21 ;
else if ( V_10 == 0 )
V_10 = V_18 . V_1 & 0xff ;
if ( ( V_9 > 0xff ) || ( V_9 < 0 ) )
return - V_21 ;
else if ( V_9 == 0 )
V_9 = ( V_18 . V_1 >> 16 ) & 0xff ;
return F_24 ( & V_42 ) ;
}
static void T_3 F_25 ( void )
{
F_26 ( & V_42 ) ;
}
