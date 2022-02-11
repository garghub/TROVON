static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = 10000 ;
do {
if ( F_2 ( F_3 ( F_4 (
V_2 -> V_4 ) ) ) == 0 )
break;
if ( -- V_3 == 0 )
break;
F_5 ( 1 ) ;
} while ( 1 );
}
static void F_6 ( struct V_1 * V_2 )
{
unsigned int V_3 = 10000 ;
while ( 1 ) {
if ( F_2 ( F_3 ( F_4 (
V_2 -> V_4 ) ) ) < 32 )
break;
if ( -- V_3 == 0 )
break;
F_5 ( 1 ) ;
}
}
static void F_7 ( struct V_1 * V_2 , int V_5 )
{
F_6 ( V_2 ) ;
F_8 ( ( V_6 ) V_5 , F_9 ( V_2 -> V_4 ) ) ;
}
static void F_10 ( struct V_7 * V_8 , const char * V_9 ,
unsigned int V_10 )
{
struct V_11 * V_12 = & V_13 [ V_8 -> V_14 ] ;
unsigned long V_15 ;
int V_16 = 1 ;
F_11 () ;
F_12 ( V_15 ) ;
if ( V_12 -> V_2 . V_17 )
V_16 = 0 ;
else if ( V_18 )
V_16 = F_13 ( & V_12 -> V_2 . V_19 ) ;
else
F_14 ( & V_12 -> V_2 . V_19 ) ;
F_15 ( & V_12 -> V_2 , V_9 , V_10 , F_7 ) ;
F_1 ( & V_12 -> V_2 ) ;
if ( V_16 )
F_16 ( & V_12 -> V_2 . V_19 ) ;
F_17 ( V_15 ) ;
}
static int T_1 F_18 ( struct V_7 * V_8 ,
char * V_20 )
{
struct V_1 * V_2 ;
int V_21 = 115200 ;
int V_22 = 8 ;
int V_23 = 'n' ;
int V_24 = 'n' ;
if ( V_8 -> V_14 >= V_25 )
V_8 -> V_14 = 0 ;
V_2 = & V_13 [ V_8 -> V_14 ] . V_2 ;
if ( ! V_2 -> V_4 )
return - V_26 ;
if ( V_20 )
F_19 ( V_20 , & V_21 , & V_23 , & V_22 , & V_24 ) ;
return F_20 ( V_2 , V_8 , V_21 , V_23 , V_22 , V_24 ) ;
}
static int T_1 F_21 ( void )
{
F_22 ( & V_27 ) ;
return 0 ;
}
static unsigned int F_23 ( unsigned long V_28 ,
unsigned long V_29 )
{
V_6 div , V_30 , V_31 , V_32 , V_33 ;
V_6 V_34 ;
div = V_28 / V_29 ;
V_30 = V_31 = ( div / 14 ) - 1 ;
if ( V_31 != 0 )
V_31 -- ;
V_32 = V_31 + 3 ;
V_34 = 0xFFFFFFFF ;
while ( V_31 < V_32 ) {
V_33 = V_28 / ( ( V_31 + 1 ) * 14 ) ;
if ( abs ( V_33 - V_29 ) < V_34 ) {
V_30 = V_31 ;
V_34 = abs ( V_33 - V_29 ) ;
}
V_31 ++ ;
}
if ( V_31 > 0xFF )
V_31 = 0xFF ;
return V_30 ;
}
static void F_24 ( struct V_1 * V_2 )
{
V_6 V_35 ;
int V_36 = 0 ;
while ( ( F_3 ( F_4 ( V_2 -> V_4 ) ) > 0 ) &&
( V_36 ++ < V_37 ) )
V_35 = F_3 ( F_9 ( V_2 -> V_4 ) ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = & V_2 -> V_40 -> V_2 ;
unsigned int V_35 , V_41 ;
V_35 = F_3 ( F_9 ( V_2 -> V_4 ) ) ;
while ( ! ( V_35 & V_42 ) ) {
V_41 = V_43 ;
V_2 -> V_44 . V_45 ++ ;
if ( V_35 & V_46 ) {
F_8 ( V_47 ,
F_26 ( V_2 -> V_4 ) ) ;
V_2 -> V_44 . V_48 ++ ;
V_41 = V_49 ;
F_27 ( V_39 , 0 , V_49 ) ;
}
F_27 ( V_39 , ( V_35 & 0xFF ) , V_41 ) ;
V_35 = F_3 ( F_9 ( V_2 -> V_4 ) ) ;
}
F_16 ( & V_2 -> V_19 ) ;
F_28 ( V_39 ) ;
F_14 ( & V_2 -> V_19 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = & V_2 -> V_40 -> V_51 ;
unsigned int V_35 ;
if ( V_2 -> V_52 ) {
F_8 ( ( V_6 ) V_2 -> V_52 , F_9 ( V_2 -> V_4 ) ) ;
V_2 -> V_44 . V_53 ++ ;
V_2 -> V_52 = 0 ;
return;
}
if ( F_30 ( V_51 ) || F_31 ( V_2 ) )
goto V_54;
while ( F_2 ( F_3 (
F_4 ( V_2 -> V_4 ) ) ) < 64 ) {
F_8 ( ( V_6 ) V_51 -> V_55 [ V_51 -> V_56 ] ,
F_9 ( V_2 -> V_4 ) ) ;
V_51 -> V_56 = ( V_51 -> V_56 + 1 ) & ( V_57 - 1 ) ;
V_2 -> V_44 . V_53 ++ ;
if ( F_30 ( V_51 ) )
break;
}
if ( F_32 ( V_51 ) < V_58 )
F_33 ( V_2 ) ;
V_54:
if ( F_30 ( V_51 ) ) {
V_35 = F_3 ( F_34 ( V_2 -> V_4 ) ) ;
V_35 &= ~ V_59 ;
F_8 ( V_35 , F_34 ( V_2 -> V_4 ) ) ;
}
}
static T_2 F_35 ( int V_60 , void * V_61 )
{
struct V_1 * V_2 = V_61 ;
struct V_38 * V_39 = & V_2 -> V_40 -> V_2 ;
V_6 V_62 ;
F_14 ( & V_2 -> V_19 ) ;
V_62 = F_3 ( F_26 ( V_2 -> V_4 ) ) ;
if ( V_62 & V_63 ) {
F_8 ( V_63 , F_26 ( V_2 -> V_4 ) ) ;
V_2 -> V_44 . V_64 ++ ;
F_36 ( V_2 ) ;
}
if ( V_62 & V_47 )
F_8 ( V_47 , F_26 ( V_2 -> V_4 ) ) ;
if ( V_62 & V_65 ) {
F_8 ( V_65 ,
F_26 ( V_2 -> V_4 ) ) ;
V_2 -> V_44 . V_66 ++ ;
F_27 ( V_39 , 0 , V_67 ) ;
F_37 ( V_39 ) ;
}
if ( V_62 & ( V_68 | V_69 ) )
F_25 ( V_2 ) ;
if ( ( V_62 & V_70 ) && ( ! F_31 ( V_2 ) ) ) {
F_8 ( V_70 , F_26 ( V_2 -> V_4 ) ) ;
F_29 ( V_2 ) ;
}
F_16 ( & V_2 -> V_19 ) ;
return V_71 ;
}
static unsigned int F_38 ( struct V_1 * V_2 )
{
unsigned int V_72 = 0 ;
if ( F_2 ( F_3 ( F_4 ( V_2 -> V_4 ) ) ) == 0 )
V_72 = V_73 ;
return V_72 ;
}
static void F_39 ( struct V_1 * V_2 ,
unsigned int V_74 )
{
}
static unsigned int F_40 ( struct V_1 * V_2 )
{
return V_75 | V_76 | V_77 ;
}
static void F_41 ( struct V_1 * V_2 )
{
V_6 V_35 ;
V_35 = F_3 ( F_34 ( V_2 -> V_4 ) ) ;
V_35 &= ~ V_59 ;
F_8 ( V_35 , F_34 ( V_2 -> V_4 ) ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
V_6 V_35 ;
F_29 ( V_2 ) ;
V_35 = F_3 ( F_34 ( V_2 -> V_4 ) ) ;
V_35 |= V_59 ;
F_8 ( V_35 , F_34 ( V_2 -> V_4 ) ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
V_6 V_35 ;
V_35 = F_3 ( F_34 ( V_2 -> V_4 ) ) ;
V_35 &= ~ ( V_78 | V_79 ) ;
F_8 ( V_35 , F_34 ( V_2 -> V_4 ) ) ;
F_8 ( ( V_63 | V_65 |
V_47 ) , F_26 ( V_2 -> V_4 ) ) ;
}
static void F_44 ( struct V_1 * V_2 ,
int V_80 )
{
unsigned long V_15 ;
V_6 V_35 ;
F_45 ( & V_2 -> V_19 , V_15 ) ;
V_35 = F_3 ( F_34 ( V_2 -> V_4 ) ) ;
if ( V_80 != 0 )
V_35 |= V_81 ;
else
V_35 &= ~ V_81 ;
F_8 ( V_35 , F_34 ( V_2 -> V_4 ) ) ;
F_46 ( & V_2 -> V_19 , V_15 ) ;
}
static void F_47 ( T_3 V_82 , int V_40 )
{
int V_83 ;
V_6 V_35 ;
switch ( V_82 ) {
case V_84 :
V_83 = 0 ;
break;
case V_85 :
V_83 = 1 ;
break;
case V_86 :
V_83 = 6 ;
break;
default:
F_48 ( 1 , L_1 , V_82 ) ;
return;
}
V_35 = F_3 ( V_87 ) ;
if ( V_40 )
V_35 |= ( 1 << V_83 ) ;
else
V_35 &= ~ ( 1 << V_83 ) ;
F_8 ( V_35 , V_87 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
int V_88 ;
unsigned long V_15 ;
V_6 V_35 ;
F_45 ( & V_2 -> V_19 , V_15 ) ;
F_24 ( V_2 ) ;
F_8 ( ( V_70 | V_47 |
V_63 | V_65 ) ,
F_26 ( V_2 -> V_4 ) ) ;
F_8 ( 0xFF , F_50 ( V_2 -> V_4 ) ) ;
V_35 = V_89 | V_90 |
F_51 ( 20 ) | V_91 ;
F_8 ( V_35 , F_34 ( V_2 -> V_4 ) ) ;
F_47 ( V_2 -> V_82 , 0 ) ;
F_46 ( & V_2 -> V_19 , V_15 ) ;
V_88 = F_52 ( V_2 -> V_60 , F_35 ,
0 , V_92 , V_2 ) ;
if ( ! V_88 )
F_8 ( ( V_35 | V_78 | V_79 ) ,
F_34 ( V_2 -> V_4 ) ) ;
return V_88 ;
}
static void F_53 ( struct V_1 * V_2 )
{
V_6 V_35 ;
unsigned long V_15 ;
F_45 ( & V_2 -> V_19 , V_15 ) ;
V_35 = V_89 | V_90 |
F_51 ( 20 ) | V_91 ;
F_8 ( V_35 , F_34 ( V_2 -> V_4 ) ) ;
F_47 ( V_2 -> V_82 , 1 ) ;
F_46 ( & V_2 -> V_19 , V_15 ) ;
F_54 ( V_2 -> V_60 , V_2 ) ;
}
static void F_55 ( struct V_1 * V_2 ,
struct V_93 * V_94 ,
struct V_93 * V_95 )
{
unsigned long V_15 ;
unsigned int V_21 , V_96 ;
V_6 V_35 ;
V_94 -> V_97 &= ~ ( V_98 | V_99 | V_100 | V_101 ) ;
V_94 -> V_97 |= V_102 ;
V_94 -> V_97 &= ~ ( V_103 | V_104 | V_105 | V_106 ) ;
V_21 = F_56 ( V_2 , V_94 , V_95 , 0 ,
V_2 -> V_28 / 14 ) ;
V_96 = F_23 ( V_2 -> V_28 , V_21 ) ;
F_45 ( & V_2 -> V_19 , V_15 ) ;
V_35 = F_3 ( F_34 ( V_2 -> V_4 ) ) ;
if ( ( V_94 -> V_97 & V_107 ) == 0 )
V_35 &= ~ ( V_78 | V_79 ) ;
else
V_35 |= V_78 | V_79 ;
F_8 ( V_35 , F_34 ( V_2 -> V_4 ) ) ;
F_8 ( V_96 , F_50 ( V_2 -> V_4 ) ) ;
F_57 ( V_2 , V_94 -> V_97 , V_21 ) ;
F_46 ( & V_2 -> V_19 , V_15 ) ;
if ( F_58 ( V_94 ) )
F_59 ( V_94 , V_21 , V_21 ) ;
}
static const char * F_60 ( struct V_1 * V_2 )
{
return V_92 ;
}
static void F_61 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_108 == V_109 ) && ( V_2 -> V_82 ) ) {
if ( V_2 -> V_15 & V_110 ) {
F_62 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
}
F_63 ( V_2 -> V_82 , V_111 ) ;
}
}
static int F_64 ( struct V_1 * V_2 )
{
int V_72 = - V_26 ;
if ( ( V_2 -> V_108 == V_109 ) && ( V_2 -> V_82 ) ) {
V_72 = 0 ;
if ( ! F_65 ( V_2 -> V_82 , V_111 , V_92 ) )
V_72 = - V_112 ;
else if ( V_2 -> V_15 & V_110 ) {
V_2 -> V_4 = F_66 ( V_2 -> V_82 , V_111 ) ;
if ( ! V_2 -> V_4 ) {
F_63 ( V_2 -> V_82 , V_111 ) ;
V_72 = - V_113 ;
}
}
}
return V_72 ;
}
static void F_67 ( struct V_1 * V_2 , int V_114 )
{
int V_72 ;
V_72 = F_64 ( V_2 ) ;
if ( V_72 < 0 )
return;
V_2 -> type = V_115 ;
V_2 -> V_116 = 64 ;
F_24 ( V_2 ) ;
F_8 ( ( V_70 | V_47 |
V_63 | V_65 ) ,
F_26 ( V_2 -> V_4 ) ) ;
F_8 ( 0xFF , F_50 ( V_2 -> V_4 ) ) ;
F_8 ( V_89 | V_90 |
F_51 ( 20 ) | V_91 ,
F_34 ( V_2 -> V_4 ) ) ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_117 * V_118 )
{
int V_72 = 0 ;
if ( V_118 -> type != V_115 )
V_72 = - V_119 ;
return V_72 ;
}
static int F_69 ( struct V_120 * V_121 )
{
struct V_11 * V_122 = & V_13 [ V_123 ] ;
int V_72 = 0 ;
struct V_124 * V_125 ;
if ( V_123 >= V_25 ) {
F_70 ( & V_121 -> V_126 ,
L_2 ,
V_123 + 1 ) ;
return - V_127 ;
}
memset ( V_122 , 0 , sizeof( * V_122 ) ) ;
V_125 = F_71 ( V_121 , V_128 , 0 ) ;
if ( ! V_125 ) {
F_70 ( & V_121 -> V_126 ,
L_3 ,
V_123 ) ;
return - V_127 ;
}
V_122 -> V_2 . V_82 = V_125 -> V_129 ;
V_122 -> V_2 . V_4 = NULL ;
V_122 -> V_2 . V_60 = F_72 ( V_121 , 0 ) ;
if ( V_122 -> V_2 . V_60 < 0 ) {
F_70 ( & V_121 -> V_126 , L_4 ,
V_123 ) ;
return V_122 -> V_2 . V_60 ;
}
V_122 -> V_2 . V_108 = V_109 ;
V_122 -> V_2 . V_28 = V_130 ;
V_122 -> V_2 . V_131 = 2 ;
V_122 -> V_2 . V_15 = V_132 | V_133 | V_110 ;
V_122 -> V_2 . V_126 = & V_121 -> V_126 ;
V_122 -> V_2 . V_134 = & V_135 ;
V_122 -> V_2 . line = V_123 ++ ;
F_73 ( & V_122 -> V_2 . V_19 ) ;
F_47 ( V_122 -> V_2 . V_82 , 1 ) ;
V_72 = F_74 ( & V_136 , & V_122 -> V_2 ) ;
F_75 ( V_121 , V_122 ) ;
return V_72 ;
}
static int F_76 ( struct V_120 * V_121 )
{
struct V_11 * V_122 = F_77 ( V_121 ) ;
F_78 ( & V_136 , & V_122 -> V_2 ) ;
return 0 ;
}
static int F_79 ( struct V_120 * V_121 ,
T_4 V_40 )
{
struct V_11 * V_122 = F_77 ( V_121 ) ;
F_80 ( & V_136 , & V_122 -> V_2 ) ;
return 0 ;
}
static int F_81 ( struct V_120 * V_121 )
{
struct V_11 * V_122 = F_77 ( V_121 ) ;
F_82 ( & V_136 , & V_122 -> V_2 ) ;
return 0 ;
}
static int T_1 F_83 ( void )
{
int V_72 ;
V_72 = F_84 ( & V_136 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_85 ( & V_137 ) ;
if ( V_72 )
F_86 ( & V_136 ) ;
return V_72 ;
}
static void T_5 F_87 ( void )
{
F_88 ( & V_137 ) ;
F_86 ( & V_136 ) ;
}
