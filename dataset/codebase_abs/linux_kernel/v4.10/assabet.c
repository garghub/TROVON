void F_1 ( unsigned int V_1 , unsigned int V_2 )
{
unsigned long V_3 ;
F_2 ( V_3 ) ;
V_4 = ( V_4 & ~ V_1 ) | V_2 ;
V_5 = V_4 ;
F_3 ( V_3 ) ;
}
static void F_4 ( void )
{
V_6 = V_7 ;
F_5 ( 1 ) ;
V_6 = V_8 ;
F_5 ( 2 ) ;
V_9 = V_8 ;
}
static void F_6 ( void )
{
V_6 = V_7 ;
F_5 ( 2 ) ;
V_6 = V_8 ;
F_5 ( 1 ) ;
}
static void F_7 ( unsigned V_10 )
{
unsigned V_11 ;
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ , V_10 <<= 1 ) {
V_9 = V_7 ;
F_5 ( 1 ) ;
if ( V_10 & 0x80 )
V_6 = V_8 ;
else
V_9 = V_8 ;
F_5 ( 1 ) ;
V_6 = V_7 ;
F_5 ( 1 ) ;
}
V_9 = V_7 ;
F_5 ( 1 ) ;
V_6 = V_8 ;
F_5 ( 1 ) ;
V_12 &= ~ V_8 ;
V_6 = V_7 ;
F_5 ( 1 ) ;
if ( V_13 & V_8 )
F_8 ( V_14 L_1 ) ;
F_5 ( 1 ) ;
V_9 = V_7 | V_8 ;
F_5 ( 1 ) ;
V_12 |= V_8 ;
F_5 ( 1 ) ;
}
static void F_9 ( unsigned V_15 , unsigned V_2 )
{
unsigned V_16 = V_12 ;
unsigned V_17 = V_13 ;
V_5 = V_4 | V_18 ;
F_5 ( 100 ) ;
V_9 = V_8 | V_7 | V_19 ;
V_12 = ( V_12 | V_7 | V_19 ) & ~ V_8 ;
F_5 ( 10 ) ;
if ( ! ( V_13 & V_8 ) )
F_8 ( V_14 L_2 ) ;
V_12 |= V_8 ;
F_4 () ;
F_7 ( 0x54 ) ;
F_7 ( V_15 ) ;
F_7 ( V_2 ) ;
F_6 () ;
V_6 = V_17 & ( V_8 | V_7 | V_19 ) ;
V_9 = ( ~ V_17 ) & ( V_8 | V_7 | V_19 ) ;
V_12 = V_16 ;
}
static void F_10 ( void )
{
F_9 ( 0x04 , 0x40 ) ;
}
static void F_11 ( unsigned V_1 , int V_20 )
{
unsigned long V_3 ;
bool V_21 ;
F_2 ( V_3 ) ;
V_21 = ! V_22 ;
if ( V_20 )
V_22 &= ~ V_1 ;
else
V_22 |= V_1 ;
if ( V_21 != ! V_22 ) {
if ( V_22 ) {
F_12 ( V_23 ) ;
F_10 () ;
} else {
F_13 ( V_23 ) ;
}
}
F_3 ( V_3 ) ;
}
static void F_14 ( enum V_24 V_25 )
{
int V_20 = V_25 == V_26 || V_25 == V_27 ||
V_25 == V_28 ;
F_11 ( V_29 , V_20 ) ;
}
void F_15 ( int V_20 )
{
F_11 ( V_30 , V_20 ) ;
}
static int F_16 ( struct V_31 * V_32 , unsigned int V_25 )
{
static unsigned int V_33 [ 4 ] = {
V_34 ,
V_35 | V_34 ,
V_35 ,
0
} ;
if ( V_25 < 4 )
F_1 ( V_35 | V_34 ,
V_33 [ V_25 ] ) ;
return 0 ;
}
static void F_17 ( struct V_31 * V_32 , unsigned int V_36 )
{
if ( V_36 < 4000000 )
F_13 ( V_37 ) ;
else
F_12 ( V_37 ) ;
}
static void F_18 ( T_1 V_38 )
{
T_2 V_39 = V_38 == V_40 ;
if ( F_19 () ) {
#if 1
if ( V_39 )
F_12 ( V_41 ) ;
else
F_13 ( V_41 ) ;
#else
if ( V_39 )
F_13 ( V_41 ) ;
else
F_12 ( V_41 ) ;
#endif
}
}
static void F_20 ( int V_42 )
{
if ( V_42 )
F_12 ( V_43 ) ;
else
F_13 ( V_43 ) ;
}
static void F_21 ( int V_42 )
{
if ( V_42 ) {
F_12 ( V_44 ) ;
F_5 ( 500 ) ;
} else
F_13 ( V_44 ) ;
}
static void F_22 ( int V_42 )
{
F_13 ( V_43 ) ;
}
static void F_23 ( int V_42 )
{
F_13 ( V_44 ) ;
}
static void T_3 F_24 ( void )
{
V_6 = V_45 ;
V_12 |= V_45 ;
V_9 = V_46 | V_47 | V_48 ;
V_12 |= V_46 | V_47 | V_48 ;
V_9 = V_49 ;
V_12 |= V_49 ;
V_50 = V_51 ;
V_52 = 0 ;
V_53 = 0 ;
V_54 = 0 ;
V_55 |= V_56 | V_57 ;
V_58 |= V_56 | V_57 ;
F_25 () ;
if ( F_26 () ) {
V_5 = V_4 = V_59 ;
#ifndef F_27
F_8 ( L_3
L_4 ) ;
#else
F_28 ( L_5 , 0 ,
V_60 , F_29 ( V_60 ) ) ;
#endif
}
#ifndef F_30
F_31 ( & V_61 ) ;
#else
F_31 ( & V_62 ) ;
#endif
F_32 ( & V_63 , V_64 ,
F_29 ( V_64 ) ) ;
F_33 ( & V_65 ) ;
F_34 ( & V_66 ) ;
}
static void T_3 F_35 ( void )
{
unsigned long V_67 = F_36 ( V_13 ) & V_68 ;
unsigned long V_69 = ( unsigned long ) F_37 ( V_67 ) ;
int V_70 = V_71 | V_72 | F_38 ( V_73 ) ;
T_4 * V_74 ;
V_74 = F_39 ( F_40 ( F_41 ( V_69 ) , V_69 ) , V_69 ) ;
* V_74 = F_42 ( V_67 | V_70 ) ;
F_43 ( V_74 ) ;
}
static void T_3 F_44 ( void )
{
unsigned long V_75 ( V_76 ) , V_11 ;
V_12 |= 0x3fc ;
V_6 = 0x3fc ;
V_12 &= ~ ( 0x3fc ) ;
for( V_11 = 100 ; V_11 -- ; )
V_76 = V_13 ;
V_12 |= 0x3fc ;
V_76 &= 0x3fc ;
V_77 = V_76 ;
}
static void T_3
F_45 ( struct V_78 * V_79 , char * * V_80 )
{
F_35 () ;
F_44 () ;
if ( F_26 () )
F_8 ( L_6 ) ;
}
static void F_46 ( struct V_81 * V_82 , T_2 V_25 , T_2 V_83 )
{
if ( V_82 -> V_84 == V_85 ) {
if ( V_25 )
F_13 ( V_86 |
V_87 |
V_88 ) ;
else
F_12 ( V_86 |
V_87 |
V_88 ) ;
}
}
static void F_47 ( struct V_81 * V_82 , T_2 V_89 )
{
if ( V_82 -> V_84 == V_85 ) {
T_2 V_20 = 0 , V_90 = 0 ;
if ( V_89 & V_91 )
V_90 |= V_87 ;
else
V_20 |= V_87 ;
if ( V_89 & V_92 )
V_90 |= V_88 ;
else
V_20 |= V_88 ;
F_13 ( V_90 ) ;
F_12 ( V_20 ) ;
}
}
static T_2 F_48 ( struct V_81 * V_82 )
{
T_2 V_93 = 0 ;
T_2 V_94 = V_95 ;
V_94 = V_95 ;
if ( V_82 -> V_84 == V_85 ) {
if ( V_94 & V_96 )
V_93 |= V_97 ;
if ( V_94 & V_98 )
V_93 |= V_99 ;
if ( V_94 & V_100 )
V_93 |= V_101 ;
} else if ( V_82 -> V_84 == V_102 ) {
if ( V_94 & V_103 )
V_93 |= V_97 ;
if ( V_94 & V_104 )
V_93 |= V_99 ;
if ( V_94 & V_105 )
V_93 |= V_101 ;
if ( V_94 & V_106 )
V_93 |= V_107 ;
} else {
V_93 = V_97 | V_99 | V_101 ;
}
return V_93 ;
}
static void T_3 F_49 ( void )
{
F_50 () ;
F_51 ( V_108 , F_29 ( V_108 ) ) ;
V_109 |= V_110 ;
V_111 = ( V_111 & ~ 0xffff ) |
V_112 | V_113 |
F_52 ( 2 ) | F_53 ( 2 ) | F_54 ( 0 ) ;
if ( ! F_26 () )
F_55 ( & V_114 ) ;
F_56 ( 0 , 1 ) ;
F_56 ( 2 , 3 ) ;
}
static void F_57 ( struct V_115 * V_116 ,
enum V_117 V_118 )
{
struct V_119 * V_120 = F_58 ( V_116 ,
struct V_119 , V_116 ) ;
if ( V_118 != V_121 )
F_13 ( V_120 -> V_1 ) ;
else
F_12 ( V_120 -> V_1 ) ;
}
static enum V_117 F_59 ( struct V_115 * V_116 )
{
struct V_119 * V_120 = F_58 ( V_116 ,
struct V_119 , V_116 ) ;
return ( V_5 & V_120 -> V_1 ) ? V_121 : V_122 ;
}
static int T_3 F_60 ( void )
{
int V_11 ;
if ( ! F_19 () )
return - V_123 ;
for ( V_11 = 0 ; V_11 < F_29 ( V_124 ) ; V_11 ++ ) {
struct V_119 * V_120 ;
V_120 = F_61 ( sizeof( * V_120 ) , V_125 ) ;
if ( ! V_120 )
break;
V_120 -> V_116 . V_126 = V_124 [ V_11 ] . V_126 ;
V_120 -> V_116 . V_127 = F_57 ;
V_120 -> V_116 . V_128 = F_59 ;
V_120 -> V_116 . V_129 = V_124 [ V_11 ] . V_130 ;
if ( ! V_11 )
V_120 -> V_1 = V_131 ;
else
V_120 -> V_1 = V_132 ;
if ( F_62 ( NULL , & V_120 -> V_116 ) < 0 ) {
F_63 ( V_120 ) ;
break;
}
}
return 0 ;
}
