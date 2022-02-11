void F_1 ( unsigned int V_1 , unsigned int V_2 )
{
unsigned long V_3 ;
F_2 ( V_3 ) ;
V_4 = ( V_4 & ~ V_1 ) | V_2 ;
V_5 = V_4 ;
F_3 ( V_3 ) ;
}
static void F_4 ( int V_6 )
{
#ifndef F_5
if ( V_6 )
F_6 ( V_7 ) ;
else
#endif
F_7 ( V_7 ) ;
}
static void F_8 ( int V_6 )
{
#ifndef F_5
if ( V_6 ) {
F_6 ( V_8 ) ;
F_9 ( 500 ) ;
} else
#endif
F_7 ( V_8 ) ;
}
static int F_10 ( struct V_9 * V_10 , unsigned int V_11 )
{
static unsigned int V_12 [ 4 ] = {
V_13 ,
V_14 | V_13 ,
V_14 ,
0
} ;
if ( V_11 < 4 ) {
V_11 = V_12 [ V_11 ] ;
F_7 ( V_11 ^ ( V_14 |
V_13 ) ) ;
F_6 ( V_11 ) ;
}
return 0 ;
}
static void F_11 ( struct V_9 * V_10 , unsigned int V_15 )
{
if ( V_15 < 4000000 )
F_7 ( V_16 ) ;
else
F_6 ( V_16 ) ;
}
static void T_1 F_12 ( void )
{
V_17 |= V_18 ;
V_19 = V_18 ;
V_17 |= V_20 | V_21 | V_22 ;
V_23 = V_20 | V_21 | V_22 ;
V_24 = V_25 ;
V_26 = 0 ;
V_27 = 0 ;
V_28 = 0 ;
V_29 |= V_30 | V_31 ;
V_32 |= V_30 | V_31 ;
V_33 = F_8 ;
V_34 = F_4 ;
if ( F_13 () ) {
V_5 = V_4 = V_35 ;
#ifndef F_14
F_15 ( L_1
L_2 ) ;
#endif
}
F_16 ( & V_36 , V_37 ,
F_17 ( V_37 ) ) ;
F_18 ( & V_38 ) ;
F_19 ( & V_39 ) ;
}
static void T_1 F_20 ( void )
{
unsigned long V_40 = F_21 ( V_41 ) & V_42 ;
unsigned long V_43 = F_22 ( V_40 ) ;
int V_44 = V_45 | V_46 | F_23 ( V_47 ) ;
T_2 * V_48 ;
V_48 = F_24 ( F_25 ( F_26 ( V_43 ) , V_43 ) , V_43 ) ;
* V_48 = F_27 ( V_40 | V_44 ) ;
F_28 ( V_48 ) ;
}
static void T_1 F_29 ( void )
{
unsigned long V_49 , V_50 ;
V_17 |= 0x3fc ;
V_19 = 0x3fc ;
V_17 &= ~ ( 0x3fc ) ;
for( V_50 = 100 ; V_50 -- ; )
V_49 = V_41 ;
V_17 |= 0x3fc ;
V_49 &= 0x3fc ;
V_51 = V_49 ;
}
static void T_1
F_30 ( struct V_52 * V_53 , char * * V_54 , struct V_55 * V_56 )
{
F_20 () ;
F_29 () ;
if ( F_13 () )
F_15 ( L_3 ) ;
}
static void F_31 ( struct V_57 * V_58 , T_3 V_11 , T_3 V_59 )
{
if ( V_58 -> V_60 == V_61 ) {
if ( V_11 )
F_7 ( V_62 |
V_63 |
V_64 ) ;
else
F_6 ( V_62 |
V_63 |
V_64 ) ;
}
}
static void F_32 ( struct V_57 * V_58 , T_3 V_65 )
{
if ( V_58 -> V_60 == V_61 ) {
T_3 V_66 = 0 , V_67 = 0 ;
if ( V_65 & V_68 )
V_67 |= V_63 ;
else
V_66 |= V_63 ;
if ( V_65 & V_69 )
V_67 |= V_64 ;
else
V_66 |= V_64 ;
F_7 ( V_67 ) ;
F_6 ( V_66 ) ;
}
}
static T_3 F_33 ( struct V_57 * V_58 )
{
T_3 V_70 = 0 ;
T_3 V_71 = V_72 ;
V_71 = V_72 ;
if ( V_58 -> V_60 == V_61 ) {
if ( V_71 & V_73 )
V_70 |= V_74 ;
if ( V_71 & V_75 )
V_70 |= V_76 ;
if ( V_71 & V_77 )
V_70 |= V_78 ;
} else if ( V_58 -> V_60 == V_79 ) {
if ( V_71 & V_80 )
V_70 |= V_74 ;
if ( V_71 & V_81 )
V_70 |= V_76 ;
if ( V_71 & V_82 )
V_70 |= V_78 ;
if ( V_71 & V_83 )
V_70 |= V_84 ;
} else {
V_70 = V_74 | V_76 | V_78 ;
}
return V_70 ;
}
static void T_1 F_34 ( void )
{
F_35 () ;
F_36 ( V_85 , F_17 ( V_85 ) ) ;
V_86 |= V_87 ;
if ( F_13 () ) {
#ifdef F_14
extern void V_88 ( void ) ;
V_88 () ;
#endif
} else {
F_37 ( & V_89 ) ;
}
F_38 ( 0 , 1 ) ;
F_38 ( 2 , 3 ) ;
}
