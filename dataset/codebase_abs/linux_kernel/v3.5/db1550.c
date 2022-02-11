const char * F_1 ( void )
{
return L_1 ;
}
static void T_1 F_2 ( void )
{
void T_2 * V_1 ;
F_3 ( 203 , 0 ) ;
V_1 = ( void T_2 * ) V_2 ;
F_4 ( F_5 ( V_1 ) | 0x000001e0 , V_1 ) ;
V_1 = ( void T_2 * ) V_3 ;
F_4 ( F_5 ( V_1 ) | 1 , V_1 ) ;
F_6 () ;
V_1 = ( void T_2 * ) F_7 ( V_4 ) ;
F_4 ( V_5 | V_6 ,
V_1 + V_7 ) ;
F_4 ( V_8 , V_1 + V_9 ) ;
F_6 () ;
F_4 ( V_10 , V_1 + V_11 ) ;
F_6 () ;
F_3 ( 202 , 0 ) ;
}
void T_1 F_8 ( void )
{
unsigned short V_12 ;
F_9 ( V_13 ,
V_13 + V_14 ) ;
V_12 = F_10 ( V_15 ) ;
F_11 ( V_16 L_2
L_3 ,
( V_12 >> 4 ) & 0xf , ( V_12 >> 8 ) & 0xf , V_12 & 0xf ) ;
F_2 () ;
}
static void F_12 ( struct V_17 * V_18 , int V_19 ,
unsigned int V_20 )
{
struct V_21 * V_22 = V_18 -> V_23 ;
unsigned long V_24 = ( unsigned long ) V_22 -> V_25 ;
V_24 &= 0xffffff00 ;
if ( V_20 & V_26 ) {
V_24 += V_27 ;
} else if ( V_20 & V_28 ) {
V_24 += V_29 ;
} else {
V_24 += V_30 ;
}
V_22 -> V_31 = V_22 -> V_25 = ( void T_2 * ) V_24 ;
if ( V_19 != V_32 ) {
F_13 ( V_19 , V_22 -> V_25 ) ;
F_6 () ;
}
}
static int F_14 ( struct V_17 * V_18 )
{
return F_5 ( ( void T_2 * ) V_33 ) & 1 ;
}
static void F_15 ( struct V_34 * V_35 , int V_36 , int V_37 )
{
if ( V_36 )
F_16 ( V_38 , 0 , V_39 ) ;
else
F_16 ( V_38 , V_39 , 0 ) ;
}
static int F_17 ( const struct V_40 * V_41 , T_3 V_42 , T_3 V_43 )
{
if ( ( V_42 < 11 ) || ( V_42 > 13 ) || V_43 == 0 )
return - 1 ;
if ( V_42 == 11 )
return ( V_43 == 1 ) ? V_44 : 0xff ;
if ( V_42 == 12 ) {
switch ( V_43 ) {
case 1 : return V_45 ;
case 2 : return V_44 ;
case 3 : return V_46 ;
case 4 : return V_47 ;
}
}
if ( V_42 == 13 ) {
switch ( V_43 ) {
case 1 : return V_47 ;
case 2 : return V_45 ;
case 3 : return V_44 ;
case 4 : return V_46 ;
}
}
return - 1 ;
}
static int T_1 F_18 ( void )
{
return F_19 ( & V_48 ) ;
}
static int T_1 F_20 ( void )
{
int V_49 ;
F_21 ( V_50 , V_51 ) ;
F_21 ( V_52 , V_51 ) ;
F_21 ( V_53 , V_54 ) ;
F_21 ( V_55 , V_54 ) ;
F_21 ( V_56 , V_54 ) ;
F_21 ( V_57 , V_54 ) ;
F_22 ( 0 , V_58 ,
F_23 ( V_58 ) ) ;
F_24 ( V_59 ,
F_23 ( V_58 ) ) ;
F_4 ( V_5 ,
( void T_2 * ) F_7 ( V_4 ) + V_7 ) ;
F_6 () ;
F_4 ( V_5 ,
( void T_2 * ) F_7 ( V_60 ) + V_7 ) ;
F_6 () ;
F_4 ( V_61 ,
( void T_2 * ) F_7 ( V_62 ) + V_7 ) ;
F_6 () ;
F_4 ( V_61 ,
( void T_2 * ) F_7 ( V_63 ) + V_7 ) ;
F_6 () ;
F_25 (
V_64 ,
V_64 + 0x000400000 - 1 ,
V_65 ,
V_65 + 0x000400000 - 1 ,
V_66 ,
V_66 + 0x000010000 - 1 ,
V_53 , V_50 ,
0 , 0 , 0 ) ;
F_25 (
V_64 + 0x004000000 ,
V_64 + 0x004400000 - 1 ,
V_65 + 0x004000000 ,
V_65 + 0x004400000 - 1 ,
V_66 + 0x004000000 ,
V_66 + 0x004010000 - 1 ,
V_55 , V_52 ,
0 , 0 , 1 ) ;
V_49 = F_10 ( V_67 ) & V_68 ;
F_26 ( 128 << 20 , 4 , V_49 ) ;
return F_27 ( V_69 , F_23 ( V_69 ) ) ;
}
