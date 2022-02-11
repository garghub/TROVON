void F_1 ( void )
{
if ( F_2 () && ( V_1 & V_2 ) )
V_1 |= V_2 ;
}
void F_3 ( int V_3 , bool V_4 )
{
if ( V_3 == 113 )
F_4 ( V_4 ? & V_5 [ 0 ] :
& V_5 [ 1 ] , 1 ) ;
if ( V_3 == 95 )
F_4 ( V_4 ? & V_5 [ 2 ] :
& V_5 [ 3 ] , 1 ) ;
}
unsigned int F_5 ( int V_6 )
{
unsigned long V_7 , V_8 ;
unsigned int V_9 , V_10 , V_11 , V_12 , V_13 , V_14 , V_15 ;
int V_16 , V_17 , V_18 , V_19 ;
V_7 = V_20 ;
V_16 = V_21 & ( 1 << 25 ) ;
asm( "mrc\tp14, 0, %0, c6, c0, 0" : "=r" (clkcfg) );
V_17 = V_8 & ( 1 << 0 ) ;
V_18 = V_8 & ( 1 << 2 ) ;
V_19 = V_8 & ( 1 << 3 ) ;
V_9 = V_7 & 0x1f ;
V_13 = ( V_7 >> 7 ) & 0xf ;
V_11 = ( V_9 <= 10 ) ? 1 : ( V_9 <= 20 ) ? 2 : 4 ;
V_10 = V_9 * V_22 ;
V_14 = ( V_10 * V_13 ) / 2 ;
V_12 = ( ! V_16 ) ? ( V_10 / V_11 ) : ( ( V_19 ) ? V_10 : ( V_10 / 2 ) ) ;
V_15 = ( V_19 ) ? V_10 : ( V_10 / 2 ) ;
if ( V_6 ) {
F_6 ( V_23 L_1 ,
V_10 / 1000000 , ( V_10 % 1000000 ) / 10000 , V_9 ) ;
F_6 ( V_23 L_2 ,
V_14 / 1000000 , ( V_14 % 1000000 ) / 10000 , V_13 / 2 , ( V_13 % 2 ) * 5 ,
( V_17 ) ? L_3 : L_4 ) ;
F_6 ( V_23 L_5 ,
V_12 / 1000000 , ( V_12 % 1000000 ) / 10000 , V_11 ) ;
F_6 ( V_23 L_6 ,
V_15 / 1000000 , ( V_15 % 1000000 ) / 10000 ) ;
}
return ( V_17 ) ? ( V_14 / 1000 ) : ( V_10 / 1000 ) ;
}
static unsigned long F_7 ( struct V_24 * V_24 )
{
unsigned long V_7 , V_8 ;
unsigned int V_9 , V_10 , V_11 , V_12 ;
int V_16 , V_19 ;
V_7 = V_20 ;
V_16 = V_21 & ( 1 << 25 ) ;
asm( "mrc\tp14, 0, %0, c6, c0, 0" : "=r" (clkcfg) );
V_19 = V_8 & ( 1 << 3 ) ;
V_9 = V_7 & 0x1f ;
V_11 = ( V_9 <= 10 ) ? 1 : ( V_9 <= 20 ) ? 2 : 4 ;
V_10 = V_9 * V_22 ;
V_12 = ( ! V_16 ) ? ( V_10 / V_11 ) : ( ( V_19 ) ? V_10 : ( V_10 / 2 ) ) ;
return V_12 ;
}
static unsigned int F_8 ( void )
{
unsigned long V_7 ;
unsigned int V_9 , V_10 , V_25 , V_26 ;
V_7 = V_20 ;
V_9 = V_7 & 0x1f ;
V_25 = ( V_9 <= 7 ) ? 1 : ( V_9 <= 16 ) ? 2 : 4 ;
V_10 = V_9 * V_22 ;
V_26 = V_10 / V_25 ;
return ( V_26 / 10000 ) ;
}
static unsigned long F_9 ( struct V_24 * V_24 )
{
return F_8 () * 10000 ;
}
int T_1 F_10 ( unsigned int V_27 )
{
switch ( V_27 ) {
case V_28 :
case V_29 :
V_30 = V_27 ;
return 0 ;
}
return - V_31 ;
}
void F_11 ( unsigned long * V_32 )
{
V_32 [ V_33 ] = F_12 ( V_34 ) ;
F_13 ( V_35 ) ;
F_13 ( V_36 ) ;
}
void F_14 ( unsigned long * V_32 )
{
F_15 ( V_32 [ V_33 ] , V_34 ) ;
F_16 ( V_35 ) ;
V_1 = V_37 | V_38 ;
F_16 ( V_36 ) ;
}
void F_17 ( T_2 V_39 )
{
extern void V_40 ( void ) ;
#ifndef F_18
T_3 V_41 ;
asm volatile("mra %Q0, %R0, acc0" : "=r" (acc0));
#endif
V_35 &= ~ V_42 ;
V_43 = 0xDF12FE1B ;
V_44 = V_45 | V_46 | V_47 | V_48 ;
switch ( V_39 ) {
case V_49 :
V_40 () ;
break;
case V_50 :
F_19 ( V_30 , V_51 ) ;
#ifndef F_18
asm volatile("mar acc0, %Q0, %R0" : "=r" (acc0));
#endif
break;
}
}
static int F_20 ( T_2 V_39 )
{
return V_39 == V_50 || V_39 == V_49 ;
}
static int F_21 ( void )
{
V_52 = F_22 ( V_53 ) ;
return 0 ;
}
static void F_23 ( void )
{
V_52 = 0 ;
}
static void T_1 F_24 ( void )
{
V_54 = & V_55 ;
}
static inline void F_24 ( void ) {}
static int F_25 ( struct V_56 * V_57 , unsigned int V_58 )
{
int V_59 = F_26 ( V_57 -> V_60 ) ;
T_4 V_61 ;
if ( V_59 >= 0 && V_59 < 128 )
return F_27 ( V_59 , V_58 ) ;
if ( V_57 -> V_60 == V_62 )
return F_28 ( V_58 ) ;
switch ( V_57 -> V_60 ) {
case V_63 :
V_61 = V_64 ;
break;
case V_65 :
V_61 = 1u << 26 ;
break;
default:
return - V_31 ;
}
if ( V_58 )
V_66 |= V_61 ;
else
V_66 &= ~ V_61 ;
return 0 ;
}
void T_1 F_29 ( void )
{
F_30 ( 34 , F_25 ) ;
}
void T_1 F_31 ( void )
{
if ( F_32 ( V_67 ) )
F_33 ( F_25 ) ;
}
void T_1 F_34 ( void )
{
F_35 () ;
F_36 ( F_37 ( V_68 ) ) ;
F_5 ( 1 ) ;
}
void T_1 F_38 ( struct V_69 * V_6 )
{
F_39 () ;
V_35 |= V_70 ;
F_40 () ;
F_41 ( & V_71 , V_6 ) ;
}
static int T_1 F_42 ( void )
{
int V_72 = 0 ;
if ( F_2 () ) {
V_73 = V_44 ;
F_43 ( V_74 , F_44 ( V_74 ) ) ;
if ( ( V_72 = F_45 ( V_75 , 32 ) ) )
return V_72 ;
F_24 () ;
F_46 ( & V_76 ) ;
F_46 ( & V_77 ) ;
F_46 ( & V_78 ) ;
F_41 ( & V_79 , & V_80 ) ;
V_72 = F_47 ( V_81 , F_44 ( V_81 ) ) ;
}
return V_72 ;
}
