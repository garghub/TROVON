static unsigned long T_1 F_1 ( unsigned long V_1 )
{
unsigned char V_2 ;
unsigned long V_3 ;
unsigned long V_4 ;
unsigned long V_5 ;
int V_6 ;
V_3 = V_4 = V_1 ;
V_5 = V_3 + 1 ;
#define F_2 5
for ( V_6 = 0 ; V_6 < F_2 ; V_6 ++ )
{
F_3 ( V_7 , V_3 ) ;
F_3 ( V_7 , V_3 ) ;
F_3 ( V_8 , V_4 ) ;
V_2 = F_4 ( V_5 ) ;
if ( V_2 == V_9 ) {
F_3 ( V_10 , V_4 ) ;
F_4 ( V_5 ) ;
break;
}
else
F_5 ( 100 ) ;
}
return ( V_6 != F_2 ) ? V_1 : 0L ;
}
static void T_1 F_6 ( unsigned long V_1 )
{
F_3 ( V_11 , V_1 ) ;
}
static unsigned long T_1 F_7 ( void )
{
unsigned long V_1 ;
V_1 = 0x3F0 ;
if ( ( V_1 = F_1 ( V_1 ) ) == 0x3F0 ) {
return ( V_1 ) ;
}
V_1 = 0x370 ;
if ( ( V_1 = F_1 ( V_1 ) ) == 0x370 ) {
return ( V_1 ) ;
}
return ( ( unsigned long ) 0 ) ;
}
static void T_1 F_8 ( unsigned long V_1 ,
unsigned long V_12 ,
unsigned long V_13 ,
unsigned long V_14 )
{
unsigned long V_4 ;
unsigned long V_5 ;
V_4 = V_1 ;
V_5 = V_1 + 1 ;
F_3 ( V_15 , V_4 ) ;
F_3 ( V_12 , V_5 ) ;
F_3 ( V_16 , V_4 ) ;
F_3 ( ( V_13 & 0xFF ) , V_5 ) ;
F_3 ( V_17 , V_4 ) ;
F_3 ( ( V_13 >> 8 ) & 0xFF , V_5 ) ;
F_3 ( V_18 , V_4 ) ;
F_3 ( V_14 , V_5 ) ;
F_3 ( V_19 , V_4 ) ;
F_3 ( V_20 , V_5 ) ;
}
static void T_1 F_9 ( unsigned long V_1 )
{
unsigned long V_4 ;
unsigned long V_5 ;
V_4 = V_1 ;
V_5 = V_1 + 1 ;
F_3 ( V_15 , V_4 ) ;
F_3 ( V_21 , V_5 ) ;
F_3 ( V_18 , V_4 ) ;
F_3 ( V_22 , V_5 ) ;
F_3 ( V_23 , V_4 ) ;
F_3 ( V_24 , V_5 ) ;
F_3 ( V_19 , V_4 ) ;
F_3 ( V_20 , V_5 ) ;
}
static void T_1 F_10 ( unsigned long V_1 )
{
unsigned long V_4 ;
unsigned long V_5 ;
unsigned char V_25 ;
V_4 = V_1 ;
V_5 = V_1 + 1 ;
F_3 ( V_15 , V_4 ) ;
F_3 ( V_26 , V_5 ) ;
F_3 ( V_27 , V_4 ) ;
V_25 = F_4 ( V_5 ) ;
V_25 |= 0x0E ;
F_3 ( V_25 , V_5 ) ;
F_3 ( V_18 , V_4 ) ;
F_3 ( 0x06 , V_5 ) ;
F_3 ( V_28 , V_4 ) ;
F_3 ( 0x02 , V_5 ) ;
F_3 ( V_19 , V_4 ) ;
F_3 ( V_20 , V_5 ) ;
}
static void T_1 F_11 ( unsigned long V_1 )
{
unsigned long V_4 ;
unsigned long V_5 ;
unsigned char V_29 ;
V_4 = V_1 ;
V_5 = V_1 + 1 ;
F_3 ( V_30 , V_4 ) ;
V_29 = F_4 ( V_5 ) ;
F_12 ( V_29 & ( 1 << V_26 )
? L_1 : L_2 ) ;
F_12 ( V_29 & ( 1 << V_31 )
? L_3 : L_4 ) ;
F_12 ( V_29 & ( 1 << V_32 )
? L_5 : L_6 ) ;
F_12 ( V_29 & ( 1 << V_33 )
? L_7 : L_8 ) ;
F_12 ( V_29 & ( 1 << V_34 )
? L_9 : L_10 ) ;
F_12 ( V_29 & ( 1 << V_35 )
? L_11 : L_12 ) ;
F_12 ( L_13 ) ;
}
int T_1 F_13 ( void )
{
unsigned long V_36 ;
unsigned long V_37 ;
F_14 ( V_37 ) ;
if ( ( V_36 = F_7 () ) != 0UL ) {
#if V_38
F_11 ( V_36 ) ;
#endif
F_8 ( V_36 , V_34 , V_39 , V_40 ) ;
F_15 ( ( L_14 ) ) ;
F_8 ( V_36 , V_35 , V_41 , V_42 ) ;
F_15 ( ( L_15 ) ) ;
F_8 ( V_36 , V_33 , V_43 , V_44 ) ;
F_15 ( ( L_16 ) ) ;
F_9 ( V_36 ) ;
F_15 ( ( L_17 ) ) ;
F_10 ( V_36 ) ;
F_15 ( ( L_18 ) ) ;
#if V_38
F_11 ( V_36 ) ;
#endif
F_6 ( V_36 ) ;
F_16 ( V_37 ) ;
F_12 ( L_19 ,
V_36 ) ;
return 1 ;
}
else {
F_16 ( V_37 ) ;
F_15 ( ( L_20 ) ) ;
return 0 ;
}
}
