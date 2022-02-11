static inline int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 [ 0 ] & 1 ;
}
static inline int F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_3 [ 0 ] & 2 ;
}
static inline int F_3 ( struct V_1 * V_2 )
{
return V_2 -> V_3 [ 0 ] & 4 ;
}
static inline void F_4 ( struct V_1 * V_2 , int V_4 )
{
if( V_4 )
V_2 -> V_3 [ 0 ] |= 4 ;
else
V_2 -> V_3 [ 0 ] &= ~ 4 ;
}
static inline void F_5 ( struct V_1 * V_2 , int V_4 )
{
if( V_4 )
V_2 -> V_3 [ 0 ] |= 2 ;
else
V_2 -> V_3 [ 0 ] &= ~ 2 ;
}
static inline void F_6 ( struct V_1 * V_2 , int V_4 )
{
if( V_4 )
V_2 -> V_3 [ 0 ] |= 1 ;
else
V_2 -> V_3 [ 0 ] &= ~ 1 ;
}
static void F_7 ( struct V_1 * V_2 )
{
if ( F_1 ( V_2 ) ) {
F_8 ( V_5 ) ;
F_6 ( V_2 , 0 ) ;
}
}
static void F_9 ( struct V_1 * V_2 )
{
if ( ! F_1 ( V_2 ) ) {
F_10 ( V_5 ) ;
F_6 ( V_2 , 1 ) ;
}
}
static void F_11 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) ) {
F_12 ( V_6 ) ;
F_5 ( V_2 , 0 ) ;
}
}
static void F_13 ( struct V_1 * V_2 )
{
if ( ! F_3 ( V_2 ) ) {
F_10 ( V_7 ) ;
F_4 ( V_2 , 1 ) ;
}
}
static void F_14 ( struct V_1 * V_2 )
{
if ( F_3 ( V_2 ) ) {
F_12 ( V_7 ) ;
F_4 ( V_2 , 0 ) ;
}
}
static T_1 F_15 ( int V_8 , void * V_9 )
{
struct V_1 * V_2 = V_9 ;
unsigned int V_10 , V_11 , V_12 , V_13 , V_14 = 256 ;
V_10 = F_16 ( V_2 ) ;
while ( ( V_10 & V_15 ) && V_14 -- ) {
V_11 = F_17 ( V_2 ) ;
V_13 = V_16 ;
V_2 -> V_17 . V_18 ++ ;
V_12 = F_16 ( V_2 ) | V_19 ;
if ( F_18 ( V_12 & ( V_20 | V_21 | V_22 | V_23 ) ) ) {
if ( V_12 & V_20 ) {
V_12 &= ~ ( V_22 | V_21 ) ;
V_2 -> V_17 . V_24 ++ ;
if ( F_19 ( V_2 ) )
goto V_25;
}
if ( V_12 & V_21 )
V_2 -> V_17 . V_26 ++ ;
if ( V_12 & V_22 )
V_2 -> V_17 . V_27 ++ ;
if ( V_12 & V_23 )
V_2 -> V_17 . V_28 ++ ;
V_12 &= V_2 -> V_29 ;
if ( V_12 & V_20 )
V_13 = V_30 ;
else if ( V_12 & V_21 )
V_13 = V_31 ;
else if ( V_12 & V_22 )
V_13 = V_32 ;
}
if ( F_20 ( V_2 , V_11 ) )
goto V_25;
F_21 ( V_2 , V_12 , V_23 , V_11 , V_13 ) ;
V_25:
V_10 = F_16 ( V_2 ) ;
}
F_22 ( & V_2 -> V_33 -> V_2 ) ;
return V_34 ;
}
static T_1 F_23 ( int V_8 , void * V_9 )
{
struct V_1 * V_2 = V_9 ;
struct V_35 * V_36 = & V_2 -> V_33 -> V_36 ;
unsigned int V_37 ;
if ( V_2 -> V_38 ) {
F_24 () ;
F_25 ( V_2 , V_2 -> V_38 ) ;
V_2 -> V_17 . V_39 ++ ;
V_2 -> V_38 = 0 ;
return V_34 ;
}
if ( F_26 ( V_2 ) || F_27 ( V_36 ) ) {
F_7 ( V_2 ) ;
return V_34 ;
}
V_37 = 16 ;
while ( ! F_27 ( V_36 ) && ( V_37 -- > 0 ) ) {
F_24 () ;
F_25 ( V_2 , V_36 -> V_40 [ V_36 -> V_41 ] ) ;
V_36 -> V_41 = ( V_36 -> V_41 + 1 ) & ( V_42 - 1 ) ;
V_2 -> V_17 . V_39 ++ ;
}
if ( F_28 ( V_36 ) < V_43 )
F_29 ( V_2 ) ;
if ( F_27 ( V_36 ) )
F_7 ( V_2 ) ;
return V_34 ;
}
static T_1 F_30 ( int V_8 , void * V_9 )
{
struct V_1 * V_2 = V_9 ;
unsigned int V_10 ;
V_10 = F_31 ( V_2 ) ;
if ( V_10 & V_44 )
F_32 ( V_2 , V_10 & V_44 ) ;
if ( V_10 & V_45 )
V_2 -> V_17 . V_46 ++ ;
if ( V_10 & V_47 )
F_33 ( V_2 , V_10 & V_47 ) ;
if ( V_10 & V_48 )
V_2 -> V_17 . V_49 ++ ;
F_34 ( & V_2 -> V_33 -> V_2 . V_50 ) ;
return V_34 ;
}
static unsigned int F_35 ( struct V_1 * V_2 )
{
return ( F_16 ( V_2 ) & V_51 ) ? V_52 : 0 ;
}
static unsigned int F_36 ( struct V_1 * V_2 )
{
unsigned int V_53 = 0 ;
unsigned int V_10 ;
V_10 = F_31 ( V_2 ) ;
if ( V_10 & V_54 )
V_53 |= V_55 ;
if ( V_10 & V_56 )
V_53 |= V_57 ;
if ( V_10 & V_58 )
V_53 |= V_59 ;
if ( V_10 & V_60 )
V_53 |= V_61 ;
return V_53 ;
}
static void F_37 ( struct V_1 * V_2 , T_2 V_62 )
{
unsigned int V_63 ;
V_63 = F_38 ( V_2 ) ;
if ( V_62 & V_64 )
V_63 |= V_65 ;
else
V_63 &= ~ V_65 ;
if ( V_62 & V_66 )
V_63 |= V_67 ;
else
V_63 &= ~ V_67 ;
F_39 ( V_2 , V_63 ) ;
}
static void F_40 ( struct V_1 * V_2 , int V_68 )
{
unsigned int V_69 ;
V_69 = F_41 ( V_2 ) ;
if ( V_68 == - 1 )
V_69 |= V_70 ;
else
V_69 &= ~ V_70 ;
F_42 ( V_2 , V_69 ) ;
}
static int F_43 ( struct V_1 * V_2 )
{
int V_71 ;
F_44 ( V_5 , V_72 , V_73 ) ;
F_6 ( V_2 , 0 ) ;
F_5 ( V_2 , 1 ) ;
F_4 ( V_2 , 1 ) ;
V_71 = F_45 ( V_5 , F_23 , 0 , L_1 , V_2 ) ;
if ( V_71 )
goto V_74;
V_71 = F_45 ( V_6 , F_15 , 0 , L_2 , V_2 ) ;
if ( V_71 )
goto V_75;
V_71 = F_45 ( V_76 , F_15 , 0 , L_3 , V_2 ) ;
if ( V_71 )
goto V_77;
V_71 = F_45 ( V_7 , F_30 , 0 , L_4 , V_2 ) ;
if ( V_71 )
goto V_78;
return 0 ;
V_78:
F_46 ( V_76 , V_2 ) ;
V_77:
F_46 ( V_6 , V_2 ) ;
V_75:
F_46 ( V_5 , V_2 ) ;
V_74:
return V_71 ;
}
static void F_47 ( struct V_1 * V_2 )
{
F_46 ( V_6 , V_2 ) ;
F_46 ( V_5 , V_2 ) ;
F_46 ( V_7 , V_2 ) ;
F_46 ( V_76 , V_2 ) ;
F_42 ( V_2 , F_41 ( V_2 ) & ~ V_70 ) ;
F_48 ( V_2 , F_49 ( V_2 ) & ~ V_79 ) ;
}
static void F_50 ( struct V_1 * V_2 , struct V_80 * V_81 , struct V_80 * V_82 )
{
unsigned int V_69 , V_83 = 0 ;
unsigned long V_84 ;
unsigned int V_85 , V_86 ;
V_85 = F_51 ( V_2 , V_81 , V_82 , 0 , V_2 -> V_87 / 16 ) ;
V_86 = F_52 ( V_2 , V_85 ) ;
switch ( V_81 -> V_88 & V_89 ) {
case V_90 :
V_69 = V_91 ;
break;
case V_92 :
V_69 = V_93 ;
break;
case V_94 :
V_69 = V_95 ;
break;
default:
V_69 = V_96 ;
break;
}
if ( V_81 -> V_88 & V_97 )
V_69 |= V_98 ;
if ( V_81 -> V_88 & V_99 ) {
if ( V_81 -> V_88 & V_100 ) {
if ( V_81 -> V_88 & V_101 )
V_69 |= V_102 ;
else
V_69 |= V_103 ;
}
else if ( V_81 -> V_88 & V_101 )
V_69 |= V_104 ;
else
V_69 |= V_105 ;
}
if ( V_2 -> V_106 > 1 )
V_83 = V_107 | V_108 | V_109 | V_79 ;
F_53 ( & V_2 -> V_110 , V_84 ) ;
F_54 ( V_2 , V_81 -> V_88 , V_85 ) ;
V_2 -> V_29 = V_23 ;
if ( V_81 -> V_111 & V_112 )
V_2 -> V_29 |= ( V_22 | V_21 ) ;
if ( V_81 -> V_111 & ( V_113 | V_114 | V_115 ) )
V_2 -> V_29 |= V_20 ;
V_2 -> V_116 = 0 ;
if ( V_81 -> V_111 & V_117 )
V_2 -> V_116 |= ( V_22 | V_21 ) ;
if ( V_81 -> V_111 & V_113 ) {
V_2 -> V_116 |= V_20 ;
if ( V_81 -> V_111 & V_117 )
V_2 -> V_116 |= V_23 ;
}
if ( ( V_81 -> V_88 & V_118 ) == 0 )
V_2 -> V_116 |= V_19 ;
if ( F_55 ( V_2 , V_81 -> V_88 ) )
F_13 ( V_2 ) ;
else
F_14 ( V_2 ) ;
F_56 ( V_2 , V_86 ) ;
F_42 ( V_2 , V_69 ) ;
F_48 ( V_2 , V_83 ) ;
F_57 ( & V_2 -> V_110 , V_84 ) ;
}
static const char * F_58 ( struct V_1 * V_2 )
{
return V_2 -> type == V_119 ? L_5 : NULL ;
}
static void F_59 ( struct V_1 * V_2 )
{
F_60 ( V_2 -> V_120 , V_121 ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
return F_62 ( V_2 -> V_120 , V_121 ,
L_6 ) != NULL ? 0 : - V_122 ;
}
static void F_63 ( struct V_1 * V_2 , int V_84 )
{
if ( V_84 & V_123 ) {
V_2 -> type = V_119 ;
F_61 ( V_2 ) ;
}
}
static int F_64 ( struct V_1 * V_2 , struct V_124 * V_125 )
{
int V_126 = 0 ;
if ( V_125 -> type != V_127 && V_125 -> type != V_119 )
V_126 = - V_128 ;
if ( V_125 -> V_8 != V_2 -> V_8 )
V_126 = - V_128 ;
if ( V_125 -> V_129 < 9600 )
V_126 = - V_128 ;
return V_126 ;
}
static void F_65 ( struct V_1 * V_2 , int V_11 )
{
while ( ! ( F_16 ( V_2 ) & V_130 ) )
F_66 () ;
F_25 ( V_2 , V_11 ) ;
}
static void F_67 ( struct V_131 * V_132 , const char * V_133 , T_2 V_37 )
{
struct V_1 * V_2 = V_134 + V_132 -> V_135 ;
F_68 ( V_2 , V_133 , V_37 , F_65 ) ;
}
static void T_3 F_69 ( struct V_1 * V_2 , int * V_85 , int * V_26 , int * V_136 )
{
unsigned int V_69 ;
V_69 = F_41 ( V_2 ) ;
switch ( V_69 & V_137 ) {
case V_104 :
* V_26 = 'o' ;
break;
case V_105 :
* V_26 = 'e' ;
break;
default:
* V_26 = 'n' ;
}
switch ( V_69 & V_138 ) {
case V_91 :
* V_136 = 5 ;
break;
case V_93 :
* V_136 = 6 ;
break;
case V_95 :
* V_136 = 7 ;
break;
default:
* V_136 = 8 ;
}
* V_85 = V_2 -> V_87 / ( F_70 ( V_2 ) & 0x0FFF ) ;
* V_85 /= 16 ;
* V_85 &= 0xFFFFFFF0 ;
}
static int T_3 F_71 ( struct V_131 * V_132 , char * V_139 )
{
struct V_1 * V_2 ;
int V_85 = 115200 ;
int V_136 = 8 ;
int V_26 = 'n' ;
int V_140 = 'n' ;
V_2 = F_72 ( V_134 , V_141 , V_132 ) ;
if ( V_139 )
F_73 ( V_139 , & V_85 , & V_26 , & V_136 , & V_140 ) ;
else
F_69 ( V_2 , & V_85 , & V_26 , & V_136 ) ;
return F_74 ( V_2 , V_132 , V_85 , V_26 , V_136 , V_140 ) ;
}
static int T_3 F_75 ( void )
{
F_76 ( V_142 , 0 , NULL ) ;
F_77 ( & V_143 ) ;
return 0 ;
}
static int T_3 F_78 ( void )
{
int V_144 , V_126 ;
F_79 ( V_145 L_7 ) ;
V_126 = F_80 ( & V_146 ) ;
if ( V_126 )
return V_126 ;
for ( V_144 = 0 ; V_144 < V_141 ; V_144 ++ )
F_81 ( & V_146 , & V_134 [ 0 ] ) ;
return 0 ;
}
static void T_4 F_82 ( void )
{
int V_144 ;
for ( V_144 = 0 ; V_144 < V_141 ; V_144 ++ )
F_83 ( & V_146 , & V_134 [ 0 ] ) ;
F_84 ( & V_146 ) ;
}
