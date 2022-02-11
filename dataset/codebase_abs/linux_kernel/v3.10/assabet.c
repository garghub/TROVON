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
unsigned long V_52 = ( unsigned long ) F_30 ( V_49 ) ;
int V_53 = V_54 | V_55 | F_31 ( V_56 ) ;
T_4 * V_57 ;
V_57 = F_32 ( F_33 ( F_34 ( V_52 ) , V_52 ) , V_52 ) ;
* V_57 = F_35 ( V_49 | V_53 ) ;
F_36 ( V_57 ) ;
}
static void T_3 F_37 ( void )
{
unsigned long V_58 ( V_59 ) , V_60 ;
V_26 |= 0x3fc ;
V_24 = 0x3fc ;
V_26 &= ~ ( 0x3fc ) ;
for( V_60 = 100 ; V_60 -- ; )
V_59 = V_50 ;
V_26 |= 0x3fc ;
V_59 &= 0x3fc ;
V_61 = V_59 ;
}
static void T_3
F_38 ( struct V_62 * V_63 , char * * V_64 , struct V_65 * V_66 )
{
F_28 () ;
F_37 () ;
if ( F_18 () )
F_20 ( L_4 ) ;
}
static void F_39 ( struct V_67 * V_68 , T_2 V_7 , T_2 V_69 )
{
if ( V_68 -> V_70 == V_71 ) {
if ( V_7 )
F_7 ( V_72 |
V_73 |
V_74 ) ;
else
F_5 ( V_72 |
V_73 |
V_74 ) ;
}
}
static void F_40 ( struct V_67 * V_68 , T_2 V_75 )
{
if ( V_68 -> V_70 == V_71 ) {
T_2 V_76 = 0 , V_77 = 0 ;
if ( V_75 & V_78 )
V_77 |= V_73 ;
else
V_76 |= V_73 ;
if ( V_75 & V_79 )
V_77 |= V_74 ;
else
V_76 |= V_74 ;
F_7 ( V_77 ) ;
F_5 ( V_76 ) ;
}
}
static T_2 F_41 ( struct V_67 * V_68 )
{
T_2 V_80 = 0 ;
T_2 V_81 = V_82 ;
V_81 = V_82 ;
if ( V_68 -> V_70 == V_71 ) {
if ( V_81 & V_83 )
V_80 |= V_84 ;
if ( V_81 & V_85 )
V_80 |= V_86 ;
if ( V_81 & V_87 )
V_80 |= V_88 ;
} else if ( V_68 -> V_70 == V_89 ) {
if ( V_81 & V_90 )
V_80 |= V_84 ;
if ( V_81 & V_91 )
V_80 |= V_86 ;
if ( V_81 & V_92 )
V_80 |= V_88 ;
if ( V_81 & V_93 )
V_80 |= V_94 ;
} else {
V_80 = V_84 | V_86 | V_88 ;
}
return V_80 ;
}
static void T_3 F_42 ( void )
{
F_43 () ;
F_44 ( V_95 , F_22 ( V_95 ) ) ;
V_96 |= V_97 ;
if ( ! F_18 () )
F_45 ( & V_98 ) ;
F_46 ( 0 , 1 ) ;
F_46 ( 2 , 3 ) ;
}
static void F_47 ( struct V_99 * V_100 ,
enum V_101 V_102 )
{
struct V_103 * V_104 = F_48 ( V_100 ,
struct V_103 , V_100 ) ;
if ( V_102 != V_105 )
F_7 ( V_104 -> V_1 ) ;
else
F_5 ( V_104 -> V_1 ) ;
}
static enum V_101 F_49 ( struct V_99 * V_100 )
{
struct V_103 * V_104 = F_48 ( V_100 ,
struct V_103 , V_100 ) ;
return ( V_5 & V_104 -> V_1 ) ? V_105 : V_106 ;
}
static int T_3 F_50 ( void )
{
int V_60 ;
if ( ! F_10 () )
return - V_107 ;
for ( V_60 = 0 ; V_60 < F_22 ( V_108 ) ; V_60 ++ ) {
struct V_103 * V_104 ;
V_104 = F_51 ( sizeof( * V_104 ) , V_109 ) ;
if ( ! V_104 )
break;
V_104 -> V_100 . V_110 = V_108 [ V_60 ] . V_110 ;
V_104 -> V_100 . V_111 = F_47 ;
V_104 -> V_100 . V_112 = F_49 ;
V_104 -> V_100 . V_113 = V_108 [ V_60 ] . V_114 ;
if ( ! V_60 )
V_104 -> V_1 = V_115 ;
else
V_104 -> V_1 = V_116 ;
if ( F_52 ( NULL , & V_104 -> V_100 ) < 0 ) {
F_53 ( V_104 ) ;
break;
}
}
return 0 ;
}
