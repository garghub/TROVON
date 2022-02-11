static void T_1 F_1 ( void )
{
unsigned int V_1 , V_2 ;
V_1 = V_3 & 7 ;
if ( V_1 == 0 ) {
F_2 ( L_1 ) ;
return;
}
if ( V_1 >= 6 ) {
F_2 ( L_2
L_3 ) ;
V_3 = 0 ;
return;
}
V_2 = 128 << V_1 ;
F_2 ( L_4 , V_2 ) ;
V_3 = 0 ;
}
static inline void F_3 ( void )
{
char V_4 [ 80 ] ;
unsigned char V_5 ;
char * V_6 = V_4 ;
unsigned int V_7 ;
V_5 = * ( volatile unsigned char * ) V_8 ;
V_6 += sprintf ( V_6 , L_5 , ( V_5 & 0x80 ) ? L_6 : L_7 ) ;
if ( ( V_5 & 0x80 ) == 0 )
V_6 += sprintf ( V_6 , L_8 ,
( V_5 & 0x20 ) ? L_9 : L_10 ) ;
V_7 = V_5 & 0x80 ;
V_7 = ( V_5 & 0x08 ) ? V_7 : ! V_7 ;
V_6 += sprintf ( V_6 , L_11 , V_7 ? L_12 : L_13 ) ;
F_2 ( L_14 , V_4 ) ;
}
static void T_1 F_4 ( void )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < F_5 ( V_10 ) ; V_9 ++ )
F_6 ( & V_11 , V_10 + V_9 ) ;
for ( V_9 = 0 ; V_9 < F_5 ( V_12 ) ; V_9 ++ )
F_6 ( & V_13 , V_12 + V_9 ) ;
}
static void F_7 ( struct V_14 * V_15 )
{
unsigned int V_16 = 1 << ( V_15 -> V_17 - V_18 ) ;
* ( volatile V_19 * ) V_20 |= V_16 ;
}
void F_8 ( struct V_14 * V_15 )
{
unsigned int V_16 = ~ ( 1 << ( V_15 -> V_17 - V_18 ) ) ;
* ( volatile V_19 * ) V_20 &= V_16 ;
}
static void F_9 ( void )
{
F_10 ( L_15 ) ;
}
static void F_11 ( void )
{
V_19 V_21 = * ( volatile char * ) V_22 ;
unsigned long V_23 ;
if ( V_21 & V_24 ) {
int V_17 ;
V_17 = F_12 () ;
if ( F_13 ( V_17 < 0 ) )
return;
F_14 ( V_17 ) ;
}
if ( ! ( V_21 & V_25 ) ) {
V_23 = F_15 () ;
F_16 ( V_26 ) ;
F_14 ( V_27 ) ;
F_17 ( V_23 ) ;
}
}
static void F_18 ( void )
{
V_19 V_21 = * ( volatile char * ) V_22 ;
int V_17 ;
V_21 &= ( V_28 | V_29 | V_30 | V_31 ) ;
V_21 ^= ( V_28 | V_29 | V_30 | V_31 ) ;
F_16 ( V_32 ) ;
V_17 = V_18 + F_19 ( V_21 ) - 1 ;
F_14 ( V_17 ) ;
F_20 ( V_32 ) ;
}
static void F_21 ( void )
{
T_2 V_33 = F_22 () & F_15 () ;
if ( V_33 & V_34 )
F_14 ( V_35 + 7 ) ;
else if ( V_33 & V_36 )
F_14 ( V_35 + 6 ) ;
else if ( V_33 & V_37 )
F_18 () ;
else if ( V_33 & V_38 )
F_11 () ;
else if ( V_33 & V_39 ) {
F_9 () ;
}
}
void T_1 F_23 ( void )
{
int V_9 ;
* ( volatile V_19 * ) V_20 = V_40 | V_24 ;
F_24 () ;
for ( V_9 = V_18 ; V_9 <= V_27 ; V_9 ++ )
F_25 ( V_9 , & V_41 , V_42 ) ;
V_43 = F_21 ;
F_26 ( V_26 , V_44 | V_32 ) ;
}
void T_1 F_27 ( void )
{
F_3 () ;
F_1 () ;
V_45 . V_46 = V_11 . V_46 ;
#ifdef F_28
V_47 = 0x9000 ;
F_29 ( & V_48 ) ;
#endif
F_4 () ;
}
static int T_1 F_30 ( void )
{
switch ( V_49 ) {
case V_50 :
case V_51 :
case V_52 :
F_31 ( & V_53 ) ;
F_31 ( & V_54 ) ;
break;
}
return 0 ;
}
