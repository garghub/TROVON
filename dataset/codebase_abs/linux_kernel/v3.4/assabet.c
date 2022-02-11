void F_1 ( unsigned int V_1 , unsigned int V_2 )
{
unsigned long V_3 ;
F_2 ( V_3 ) ;
V_4 = ( V_4 & ~ V_1 ) | V_2 ;
V_5 = V_4 ;
F_3 ( V_3 ) ;
}
static void F_4 ( enum V_6 V_7 )
{
if ( V_7 == V_8 )
F_5 ( V_9 ) ;
}
static int F_6 ( struct V_10 * V_11 , unsigned int V_7 )
{
static unsigned int V_12 [ 4 ] = {
V_13 ,
V_14 | V_13 ,
V_14 ,
0
} ;
if ( V_7 < 4 ) {
V_7 = V_12 [ V_7 ] ;
F_7 ( V_7 ^ ( V_14 |
V_13 ) ) ;
F_5 ( V_7 ) ;
}
return 0 ;
}
static void F_8 ( struct V_10 * V_11 , unsigned int V_15 )
{
if ( V_15 < 4000000 )
F_7 ( V_16 ) ;
else
F_5 ( V_16 ) ;
}
static void F_9 ( T_1 V_17 )
{
T_2 V_18 = V_17 == V_19 ;
if ( F_10 () ) {
#if 1
if ( V_18 )
F_5 ( V_20 ) ;
else
F_7 ( V_20 ) ;
#else
if ( V_18 )
F_7 ( V_20 ) ;
else
F_5 ( V_20 ) ;
#endif
}
}
static void F_11 ( int V_21 )
{
if ( V_21 )
F_5 ( V_22 ) ;
else
F_7 ( V_22 ) ;
}
static void F_12 ( int V_21 )
{
if ( V_21 ) {
F_5 ( V_23 ) ;
F_13 ( 500 ) ;
} else
F_7 ( V_23 ) ;
}
static void F_14 ( int V_21 )
{
F_7 ( V_22 ) ;
}
static void F_15 ( int V_21 )
{
F_7 ( V_23 ) ;
}
static void T_3 F_16 ( void )
{
V_24 = V_25 ;
V_26 |= V_25 ;
V_27 = V_28 | V_29 | V_30 ;
V_26 |= V_28 | V_29 | V_30 ;
V_27 = V_31 ;
V_26 |= V_31 ;
V_32 = V_33 ;
V_34 = 0 ;
V_35 = 0 ;
V_36 = 0 ;
V_37 |= V_38 | V_39 ;
V_40 |= V_38 | V_39 ;
F_17 () ;
if ( F_18 () ) {
V_5 = V_4 = V_41 ;
#ifndef F_19
F_20 ( L_1
L_2 ) ;
#else
F_21 ( L_3 , 0 ,
V_42 , F_22 ( V_42 ) ) ;
#endif
}
#ifndef F_23
F_24 ( & V_43 ) ;
#else
F_24 ( & V_44 ) ;
#endif
F_25 ( & V_45 , V_46 ,
F_22 ( V_46 ) ) ;
F_26 ( & V_47 ) ;
F_27 ( & V_48 ) ;
}
static void T_3 F_28 ( void )
{
unsigned long V_49 = F_29 ( V_50 ) & V_51 ;
unsigned long V_52 = F_30 ( V_49 ) ;
int V_53 = V_54 | V_55 | F_31 ( V_56 ) ;
T_4 * V_57 ;
V_57 = F_32 ( F_33 ( F_34 ( V_52 ) , V_52 ) , V_52 ) ;
* V_57 = F_35 ( V_49 | V_53 ) ;
F_36 ( V_57 ) ;
}
static void T_3 F_37 ( void )
{
unsigned long V_58 , V_59 ;
V_26 |= 0x3fc ;
V_24 = 0x3fc ;
V_26 &= ~ ( 0x3fc ) ;
for( V_59 = 100 ; V_59 -- ; )
V_58 = V_50 ;
V_26 |= 0x3fc ;
V_58 &= 0x3fc ;
V_60 = V_58 ;
}
static void T_3
F_38 ( struct V_61 * V_62 , char * * V_63 , struct V_64 * V_65 )
{
F_28 () ;
F_37 () ;
if ( F_18 () )
F_20 ( L_4 ) ;
}
static void F_39 ( struct V_66 * V_67 , T_2 V_7 , T_2 V_68 )
{
if ( V_67 -> V_69 == V_70 ) {
if ( V_7 )
F_7 ( V_71 |
V_72 |
V_73 ) ;
else
F_5 ( V_71 |
V_72 |
V_73 ) ;
}
}
static void F_40 ( struct V_66 * V_67 , T_2 V_74 )
{
if ( V_67 -> V_69 == V_70 ) {
T_2 V_75 = 0 , V_76 = 0 ;
if ( V_74 & V_77 )
V_76 |= V_72 ;
else
V_75 |= V_72 ;
if ( V_74 & V_78 )
V_76 |= V_73 ;
else
V_75 |= V_73 ;
F_7 ( V_76 ) ;
F_5 ( V_75 ) ;
}
}
static T_2 F_41 ( struct V_66 * V_67 )
{
T_2 V_79 = 0 ;
T_2 V_80 = V_81 ;
V_80 = V_81 ;
if ( V_67 -> V_69 == V_70 ) {
if ( V_80 & V_82 )
V_79 |= V_83 ;
if ( V_80 & V_84 )
V_79 |= V_85 ;
if ( V_80 & V_86 )
V_79 |= V_87 ;
} else if ( V_67 -> V_69 == V_88 ) {
if ( V_80 & V_89 )
V_79 |= V_83 ;
if ( V_80 & V_90 )
V_79 |= V_85 ;
if ( V_80 & V_91 )
V_79 |= V_87 ;
if ( V_80 & V_92 )
V_79 |= V_93 ;
} else {
V_79 = V_83 | V_85 | V_87 ;
}
return V_79 ;
}
static void T_3 F_42 ( void )
{
F_43 () ;
F_44 ( V_94 , F_22 ( V_94 ) ) ;
V_95 |= V_96 ;
if ( ! F_18 () )
F_45 ( & V_97 ) ;
F_46 ( 0 , 1 ) ;
F_46 ( 2 , 3 ) ;
}
