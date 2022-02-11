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
static int F_5 ( void )
{
T_1 V_5 = V_22 ;
T_1 V_2 , V_16 , V_13 , V_1 , V_4 ;
V_1 = ( V_8 & 0xffffff00 ) | ( V_9 & 0xff ) ;
F_3 ( L_7
L_8 , V_1 , V_10 ) ;
__asm__ __volatile__(
"push %%ebp\n"
"out %%al, (%%dx)\n"
"pop %%ebp\n"
: "=a" (result),
"=b" (state), "=D" (edi),
"=c" (dummy), "=d" (dummy), "=S" (dummy)
: "a" (command), "b" (function), "c" (0),
"d" (smi_port), "S" (0), "D" (0)
);
F_3 ( L_9 , V_16 , V_2 ) ;
return V_16 & 1 ;
}
static void F_6 ( unsigned int V_16 )
{
unsigned int V_2 = 0 , V_1 , V_23 , V_4 ;
unsigned long V_24 ;
unsigned int V_5 = V_25 ;
unsigned int V_26 = 0 ;
if ( V_16 > 0x1 )
return;
F_7 ( V_24 ) ;
V_1 = ( V_8 & 0xffffff00 ) | ( V_9 & 0xff ) ;
F_3 ( L_10
L_11 ,
V_16 , V_1 , V_10 ) ;
do {
if ( V_26 ) {
F_3 ( L_12 ,
V_26 , V_2 ) ;
F_8 ( V_26 * 50 ) ;
}
V_26 ++ ;
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
} while ( ( V_23 != V_16 ) && ( V_26 <= V_27 ) );
F_9 ( V_24 ) ;
if ( V_23 == V_16 )
F_3 ( L_13
L_14 ,
( V_28 [ V_23 ] . V_29 / 1000 ) ,
V_26 , V_2 ) ;
else
F_10 ( V_30 L_15
L_16 ,
V_16 , V_23 , V_2 ) ;
return;
}
static int F_11 ( struct V_31 * V_32 ,
unsigned int V_33 , unsigned int V_34 )
{
unsigned int V_35 = 0 ;
struct V_36 V_37 ;
if ( F_12 ( V_32 , & V_28 [ 0 ] ,
V_33 , V_34 , & V_35 ) )
return - V_21 ;
V_37 . V_38 = V_28 [ F_5 () ] . V_29 ;
V_37 . V_39 = V_28 [ V_35 ] . V_29 ;
V_37 . V_40 = 0 ;
if ( V_37 . V_38 == V_37 . V_39 )
return 0 ;
F_13 ( & V_37 , V_41 ) ;
F_6 ( V_35 ) ;
F_13 ( & V_37 , V_42 ) ;
return 0 ;
}
static int F_14 ( struct V_31 * V_32 )
{
return F_15 ( V_32 , & V_28 [ 0 ] ) ;
}
static int F_16 ( struct V_31 * V_32 )
{
int V_2 ;
unsigned int V_43 , V_16 ;
unsigned int * V_11 , * V_12 ;
if ( V_32 -> V_40 != 0 )
return - V_20 ;
V_2 = F_1 () ;
if ( V_2 ) {
F_3 ( L_17 ) ;
return - V_21 ;
}
V_11 = & V_28 [ V_44 ] . V_29 ;
V_12 = & V_28 [ V_45 ] . V_29 ;
V_2 = F_4 ( V_11 , V_12 ) ;
if ( V_2 ) {
F_3 ( L_18
L_19 ) ;
V_2 = F_17 ( V_46 ,
V_11 , V_12 ,
NULL ,
& F_6 ) ;
if ( V_2 ) {
F_3 ( L_20
L_21 ) ;
return V_2 ;
} else
F_3 ( L_22 ) ;
}
V_16 = F_5 () ;
V_43 = V_28 [ V_16 ] . V_29 ;
F_3 ( L_23 ,
( V_43 == V_28 [ V_44 ] . V_29 )
? L_24 : L_25 ,
( V_43 / 1000 ) ) ;
V_32 -> V_47 . V_48 = V_49 ;
V_32 -> V_50 = V_43 ;
V_2 = F_18 ( V_32 , V_28 ) ;
if ( V_2 )
return V_2 ;
F_19 ( V_28 , V_32 -> V_40 ) ;
return 0 ;
}
static int F_20 ( struct V_31 * V_32 )
{
F_21 ( V_32 -> V_40 ) ;
return 0 ;
}
static unsigned int F_22 ( unsigned int V_40 )
{
if ( V_40 )
return - V_20 ;
return F_23 ( V_46 ) ;
}
static int F_24 ( struct V_31 * V_32 )
{
int V_2 = F_1 () ;
if ( V_2 )
F_3 ( L_26 ) ;
return V_2 ;
}
static int T_2 F_25 ( void )
{
V_46 = F_26 () ;
switch ( V_46 ) {
case V_51 :
case V_52 :
case V_53 :
break;
default:
V_46 = 0 ;
}
if ( ! V_46 ) {
F_3 ( L_27 ) ;
return - V_20 ;
}
F_3 ( L_28
L_29 ,
V_18 . V_54 , V_18 . V_1 ,
V_18 . V_19 , V_18 . V_55 ) ;
if ( ( V_18 . V_54 != 0x47534943 ) && (
( V_10 == 0 ) || ( V_9 == 0 ) ) )
return - V_20 ;
if ( V_8 == 1 )
V_8 = 0x47534943 ;
else
V_8 = V_18 . V_54 ;
if ( ( V_10 > 0xff ) || ( V_10 < 0 ) )
return - V_21 ;
else if ( V_10 == 0 )
V_10 = V_18 . V_1 & 0xff ;
if ( ( V_9 > 0xff ) || ( V_9 < 0 ) )
return - V_21 ;
else if ( V_9 == 0 )
V_9 = ( V_18 . V_1 >> 16 ) & 0xff ;
return F_27 ( & V_56 ) ;
}
static void T_3 F_28 ( void )
{
F_29 ( & V_56 ) ;
}
