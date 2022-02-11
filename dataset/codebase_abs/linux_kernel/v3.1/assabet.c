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
V_48 = F_24 ( F_25 ( V_43 ) , V_43 ) ;
* V_48 = F_26 ( V_40 | V_44 ) ;
F_27 ( V_48 ) ;
}
static void T_1 F_28 ( void )
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
F_29 ( struct V_52 * V_53 , struct V_54 * V_55 ,
char * * V_56 , struct V_57 * V_58 )
{
F_20 () ;
F_28 () ;
if ( F_13 () )
F_15 ( L_3 ) ;
}
static void F_30 ( struct V_59 * V_60 , T_3 V_11 , T_3 V_61 )
{
if ( V_60 -> V_62 == V_63 ) {
if ( V_11 )
F_7 ( V_64 |
V_65 |
V_66 ) ;
else
F_6 ( V_64 |
V_65 |
V_66 ) ;
}
}
static void F_31 ( struct V_59 * V_60 , T_3 V_67 )
{
if ( V_60 -> V_62 == V_63 ) {
T_3 V_68 = 0 , V_69 = 0 ;
if ( V_67 & V_70 )
V_69 |= V_65 ;
else
V_68 |= V_65 ;
if ( V_67 & V_71 )
V_69 |= V_66 ;
else
V_68 |= V_66 ;
F_7 ( V_69 ) ;
F_6 ( V_68 ) ;
}
}
static T_3 F_32 ( struct V_59 * V_60 )
{
T_3 V_72 = 0 ;
T_3 V_73 = V_74 ;
V_73 = V_74 ;
if ( V_60 -> V_62 == V_63 ) {
if ( V_73 & V_75 )
V_72 |= V_76 ;
if ( V_73 & V_77 )
V_72 |= V_78 ;
if ( V_73 & V_79 )
V_72 |= V_80 ;
} else if ( V_60 -> V_62 == V_81 ) {
if ( V_73 & V_82 )
V_72 |= V_76 ;
if ( V_73 & V_83 )
V_72 |= V_78 ;
if ( V_73 & V_84 )
V_72 |= V_80 ;
if ( V_73 & V_85 )
V_72 |= V_86 ;
} else {
V_72 = V_76 | V_78 | V_80 ;
}
return V_72 ;
}
static void T_1 F_33 ( void )
{
F_34 () ;
F_35 ( V_87 , F_17 ( V_87 ) ) ;
V_88 |= V_89 ;
if ( F_13 () ) {
#ifdef F_14
extern void V_90 ( void ) ;
V_90 () ;
#endif
} else {
F_36 ( & V_91 ) ;
}
F_37 ( 0 , 1 ) ;
F_37 ( 2 , 3 ) ;
}
