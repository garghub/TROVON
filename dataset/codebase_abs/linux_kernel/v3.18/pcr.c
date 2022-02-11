void T_1 F_1 ( int V_1 , struct V_2 * V_3 )
{
struct V_2 * V_4 ;
F_2 ( 1 << V_5 ) ;
V_4 = F_3 ( V_3 ) ;
F_4 () ;
#ifdef F_5
F_6 () ;
#endif
F_7 () ;
F_3 ( V_4 ) ;
}
void F_8 ( void )
{
F_9 ( 1 << V_5 ) ;
}
static T_2 F_10 ( unsigned long V_6 )
{
T_2 V_7 ;
F_11 ( V_6 != 0 ) ;
__asm__ __volatile__("rd %%pcr, %0" : "=r" (val));
return V_7 ;
}
static void F_12 ( unsigned long V_6 , T_2 V_7 )
{
F_11 ( V_6 != 0 ) ;
__asm__ __volatile__("wr %0, 0x0, %%pcr" : : "r" (val));
}
static T_2 F_13 ( unsigned long V_6 )
{
T_2 V_7 ;
F_11 ( V_6 != 0 ) ;
__asm__ __volatile__("rd %%pic, %0" : "=r" (val));
return V_7 ;
}
static void F_14 ( unsigned long V_6 , T_2 V_7 )
{
F_11 ( V_6 != 0 ) ;
__asm__ __volatile__("ba,pt %%xcc, 99f\n\t"
" nop\n\t"
".align 64\n"
"99:wr %0, 0x0, %%pic\n\t"
"rd %%pic, %%g0" : : "r" (val));
}
static T_2 F_15 ( unsigned int V_8 )
{
T_3 V_9 = F_16 () . V_10 / V_8 ;
return ( ( T_2 ) ( ( 0 - V_9 ) & 0xffffffff ) ) << 32 ;
}
static void F_17 ( unsigned long V_6 , T_2 V_7 )
{
unsigned long V_11 ;
F_11 ( V_6 != 0 ) ;
if ( V_7 & V_12 ) {
V_11 = F_18 ( V_13 , V_7 ) ;
if ( V_11 != V_14 )
F_12 ( V_6 , V_7 ) ;
} else
F_12 ( V_6 , V_7 ) ;
}
static T_2 F_19 ( unsigned int V_8 )
{
T_3 V_9 = F_16 () . V_10 / ( V_8 << 2 ) ;
return ( ( T_2 ) ( ( 0 - V_9 ) & 0xffffffff ) ) << 32 ;
}
static T_2 F_20 ( unsigned long V_6 )
{
unsigned long V_7 ;
( void ) F_21 ( V_6 , & V_7 ) ;
return V_7 ;
}
static void F_22 ( unsigned long V_6 , T_2 V_7 )
{
( void ) F_23 ( V_6 , V_7 ) ;
}
static T_2 F_24 ( unsigned long V_6 )
{
unsigned long V_7 ;
__asm__ __volatile__("ldxa [%1] %2, %0"
: "=r" (val)
: "r" (reg_num * 0x8UL), "i" (ASI_PIC));
return V_7 ;
}
static void F_25 ( unsigned long V_6 , T_2 V_7 )
{
__asm__ __volatile__("stxa %0, [%1] %2"
:
: "r" (val), "r" (reg_num * 0x8UL), "i" (ASI_PIC));
}
static T_2 F_26 ( unsigned int V_8 )
{
T_3 V_9 = F_16 () . V_10 / ( V_8 << 2 ) ;
return ( ( T_2 ) ( ( 0 - V_9 ) & 0xffffffff ) ) ;
}
static T_2 F_27 ( unsigned long V_6 )
{
unsigned long V_7 ;
( void ) F_28 ( V_6 , & V_7 ) ;
return V_7 ;
}
static void F_29 ( unsigned long V_6 , T_2 V_7 )
{
( void ) F_30 ( V_6 , V_7 ) ;
}
static int T_4 F_31 ( void )
{
unsigned long V_15 ;
if ( V_16 == V_17 ) {
switch ( V_18 ) {
case V_19 :
V_20 = V_21 ;
break;
case V_22 :
V_20 = V_23 ;
break;
case V_24 :
V_20 = V_25 ;
break;
case V_26 :
V_20 = V_27 ;
break;
case V_28 :
V_20 = V_29 ;
break;
default:
return - V_30 ;
}
V_31 = 1 ;
V_32 = 0 ;
V_15 = F_32 ( V_20 ,
V_31 ,
& V_32 ) ;
if ( V_15 ) {
F_33 ( L_1 ,
V_15 ) ;
return - V_30 ;
}
}
return 0 ;
}
static void T_4 F_34 ( void )
{
if ( V_16 != V_17 )
return;
F_35 ( V_20 ) ;
}
static int T_4 F_36 ( void )
{
int V_11 = 0 ;
switch ( V_18 ) {
case V_19 :
case V_22 :
case V_24 :
V_33 = & V_34 ;
break;
case V_26 :
V_33 = & V_35 ;
break;
case V_28 :
V_33 = & V_36 ;
break;
default:
V_11 = - V_30 ;
break;
}
return V_11 ;
}
int T_4 F_37 ( void )
{
int V_37 = F_31 () ;
if ( V_37 )
return V_37 ;
switch ( V_16 ) {
case V_17 :
V_37 = F_36 () ;
if ( V_37 )
goto V_38;
break;
case V_39 :
case V_40 :
V_33 = & V_41 ;
break;
case V_42 :
default:
V_37 = - V_30 ;
goto V_38;
}
return F_38 () ;
V_38:
F_34 () ;
return V_37 ;
}
