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
static T_2 F_31 ( unsigned long V_6 )
{
unsigned long V_7 ;
( void ) F_32 ( V_6 , & V_7 ) ;
return V_7 ;
}
static void F_33 ( unsigned long V_6 , T_2 V_7 )
{
( void ) F_34 ( V_6 , V_7 ) ;
}
static int T_4 F_35 ( void )
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
case V_30 :
V_20 = V_31 ;
break;
default:
return - V_32 ;
}
V_33 = 1 ;
V_34 = 0 ;
V_15 = F_36 ( V_20 ,
V_33 ,
& V_34 ) ;
if ( V_15 ) {
F_37 ( L_1 ,
V_15 ) ;
return - V_32 ;
}
}
return 0 ;
}
static void T_4 F_38 ( void )
{
if ( V_16 != V_17 )
return;
F_39 ( V_20 ) ;
}
static int T_4 F_40 ( void )
{
int V_11 = 0 ;
switch ( V_18 ) {
case V_19 :
case V_22 :
case V_24 :
V_35 = & V_36 ;
break;
case V_26 :
V_35 = & V_37 ;
break;
case V_28 :
V_35 = & V_38 ;
break;
case V_30 :
V_35 = & V_39 ;
break;
default:
V_11 = - V_32 ;
break;
}
return V_11 ;
}
int T_4 F_41 ( void )
{
int V_40 = F_35 () ;
if ( V_40 )
return V_40 ;
switch ( V_16 ) {
case V_17 :
V_40 = F_40 () ;
if ( V_40 )
goto V_41;
break;
case V_42 :
case V_43 :
V_35 = & V_44 ;
break;
case V_45 :
default:
V_40 = - V_32 ;
goto V_41;
}
return F_42 () ;
V_41:
F_38 () ;
return V_40 ;
}
