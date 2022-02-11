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
struct V_10 * V_11 = V_2 -> V_12 -> V_2 . V_11 ;
unsigned int V_13 , V_14 , V_15 , V_16 , V_17 = 256 ;
V_13 = F_16 ( V_2 ) ;
while ( ( V_13 & V_18 ) && V_17 -- ) {
V_14 = F_17 ( V_2 ) ;
V_16 = V_19 ;
V_2 -> V_20 . V_21 ++ ;
V_15 = F_16 ( V_2 ) | V_22 ;
if ( F_18 ( V_15 & ( V_23 | V_24 | V_25 | V_26 ) ) ) {
if ( V_15 & V_23 ) {
V_15 &= ~ ( V_25 | V_24 ) ;
V_2 -> V_20 . V_27 ++ ;
if ( F_19 ( V_2 ) )
goto V_28;
}
if ( V_15 & V_24 )
V_2 -> V_20 . V_29 ++ ;
if ( V_15 & V_25 )
V_2 -> V_20 . V_30 ++ ;
if ( V_15 & V_26 )
V_2 -> V_20 . V_31 ++ ;
V_15 &= V_2 -> V_32 ;
if ( V_15 & V_23 )
V_16 = V_33 ;
else if ( V_15 & V_24 )
V_16 = V_34 ;
else if ( V_15 & V_25 )
V_16 = V_35 ;
}
if ( F_20 ( V_2 , V_14 ) )
goto V_28;
F_21 ( V_2 , V_15 , V_26 , V_14 , V_16 ) ;
V_28:
V_13 = F_16 ( V_2 ) ;
}
F_22 ( V_11 ) ;
return V_36 ;
}
static T_1 F_23 ( int V_8 , void * V_9 )
{
struct V_1 * V_2 = V_9 ;
struct V_37 * V_38 = & V_2 -> V_12 -> V_38 ;
unsigned int V_39 ;
if ( V_2 -> V_40 ) {
F_24 () ;
F_25 ( V_2 , V_2 -> V_40 ) ;
V_2 -> V_20 . V_41 ++ ;
V_2 -> V_40 = 0 ;
return V_36 ;
}
if ( F_26 ( V_2 ) || F_27 ( V_38 ) ) {
F_7 ( V_2 ) ;
return V_36 ;
}
V_39 = 16 ;
while ( ! F_27 ( V_38 ) && ( V_39 -- > 0 ) ) {
F_24 () ;
F_25 ( V_2 , V_38 -> V_42 [ V_38 -> V_43 ] ) ;
V_38 -> V_43 = ( V_38 -> V_43 + 1 ) & ( V_44 - 1 ) ;
V_2 -> V_20 . V_41 ++ ;
}
if ( F_28 ( V_38 ) < V_45 )
F_29 ( V_2 ) ;
if ( F_27 ( V_38 ) )
F_7 ( V_2 ) ;
return V_36 ;
}
static T_1 F_30 ( int V_8 , void * V_9 )
{
struct V_1 * V_2 = V_9 ;
unsigned int V_13 ;
V_13 = F_31 ( V_2 ) ;
if ( V_13 & V_46 )
F_32 ( V_2 , V_13 & V_46 ) ;
if ( V_13 & V_47 )
V_2 -> V_20 . V_48 ++ ;
if ( V_13 & V_49 )
F_33 ( V_2 , V_13 & V_49 ) ;
if ( V_13 & V_50 )
V_2 -> V_20 . V_51 ++ ;
F_34 ( & V_2 -> V_12 -> V_2 . V_52 ) ;
return V_36 ;
}
static unsigned int F_35 ( struct V_1 * V_2 )
{
return ( F_16 ( V_2 ) & V_53 ) ? V_54 : 0 ;
}
static unsigned int F_36 ( struct V_1 * V_2 )
{
unsigned int V_55 = 0 ;
unsigned int V_13 ;
V_13 = F_31 ( V_2 ) ;
if ( V_13 & V_56 )
V_55 |= V_57 ;
if ( V_13 & V_58 )
V_55 |= V_59 ;
if ( V_13 & V_60 )
V_55 |= V_61 ;
if ( V_13 & V_62 )
V_55 |= V_63 ;
return V_55 ;
}
static void F_37 ( struct V_1 * V_2 , T_2 V_64 )
{
unsigned int V_65 ;
V_65 = F_38 ( V_2 ) ;
if ( V_64 & V_66 )
V_65 |= V_67 ;
else
V_65 &= ~ V_67 ;
if ( V_64 & V_68 )
V_65 |= V_69 ;
else
V_65 &= ~ V_69 ;
F_39 ( V_2 , V_65 ) ;
}
static void F_40 ( struct V_1 * V_2 , int V_70 )
{
unsigned int V_71 ;
V_71 = F_41 ( V_2 ) ;
if ( V_70 == - 1 )
V_71 |= V_72 ;
else
V_71 &= ~ V_72 ;
F_42 ( V_2 , V_71 ) ;
}
static int F_43 ( struct V_1 * V_2 )
{
int V_73 ;
F_44 ( V_5 , V_74 | V_75 ) ;
F_6 ( V_2 , 0 ) ;
F_5 ( V_2 , 1 ) ;
F_4 ( V_2 , 1 ) ;
V_73 = F_45 ( V_5 , F_23 , 0 , L_1 , V_2 ) ;
if ( V_73 )
goto V_76;
V_73 = F_45 ( V_6 , F_15 , 0 , L_2 , V_2 ) ;
if ( V_73 )
goto V_77;
V_73 = F_45 ( V_78 , F_15 , 0 , L_3 , V_2 ) ;
if ( V_73 )
goto V_79;
V_73 = F_45 ( V_7 , F_30 , 0 , L_4 , V_2 ) ;
if ( V_73 )
goto V_80;
return 0 ;
V_80:
F_46 ( V_78 , V_2 ) ;
V_79:
F_46 ( V_6 , V_2 ) ;
V_77:
F_46 ( V_5 , V_2 ) ;
V_76:
return V_73 ;
}
static void F_47 ( struct V_1 * V_2 )
{
F_46 ( V_6 , V_2 ) ;
F_46 ( V_5 , V_2 ) ;
F_46 ( V_7 , V_2 ) ;
F_46 ( V_78 , V_2 ) ;
F_42 ( V_2 , F_41 ( V_2 ) & ~ V_72 ) ;
F_48 ( V_2 , F_49 ( V_2 ) & ~ V_81 ) ;
}
static void F_50 ( struct V_1 * V_2 , struct V_82 * V_83 , struct V_82 * V_84 )
{
unsigned int V_71 , V_85 = 0 ;
unsigned long V_86 ;
unsigned int V_87 , V_88 ;
V_87 = F_51 ( V_2 , V_83 , V_84 , 0 , V_2 -> V_89 / 16 ) ;
V_88 = F_52 ( V_2 , V_87 ) ;
switch ( V_83 -> V_90 & V_91 ) {
case V_92 :
V_71 = V_93 ;
break;
case V_94 :
V_71 = V_95 ;
break;
case V_96 :
V_71 = V_97 ;
break;
default:
V_71 = V_98 ;
break;
}
if ( V_83 -> V_90 & V_99 )
V_71 |= V_100 ;
if ( V_83 -> V_90 & V_101 ) {
if ( V_83 -> V_90 & V_102 ) {
if ( V_83 -> V_90 & V_103 )
V_71 |= V_104 ;
else
V_71 |= V_105 ;
}
else if ( V_83 -> V_90 & V_103 )
V_71 |= V_106 ;
else
V_71 |= V_107 ;
}
if ( V_2 -> V_108 > 1 )
V_85 = V_109 | V_110 | V_111 | V_81 ;
F_53 ( & V_2 -> V_112 , V_86 ) ;
F_54 ( V_2 , V_83 -> V_90 , V_87 ) ;
V_2 -> V_32 = V_26 ;
if ( V_83 -> V_113 & V_114 )
V_2 -> V_32 |= ( V_25 | V_24 ) ;
if ( V_83 -> V_113 & ( V_115 | V_116 ) )
V_2 -> V_32 |= V_23 ;
V_2 -> V_117 = 0 ;
if ( V_83 -> V_113 & V_118 )
V_2 -> V_117 |= ( V_25 | V_24 ) ;
if ( V_83 -> V_113 & V_119 ) {
V_2 -> V_117 |= V_23 ;
if ( V_83 -> V_113 & V_118 )
V_2 -> V_117 |= V_26 ;
}
if ( ( V_83 -> V_90 & V_120 ) == 0 )
V_2 -> V_117 |= V_22 ;
if ( F_55 ( V_2 , V_83 -> V_90 ) )
F_13 ( V_2 ) ;
else
F_14 ( V_2 ) ;
F_56 ( V_2 , V_88 ) ;
F_42 ( V_2 , V_71 ) ;
F_48 ( V_2 , V_85 ) ;
F_57 ( & V_2 -> V_112 , V_86 ) ;
}
static const char * F_58 ( struct V_1 * V_2 )
{
return V_2 -> type == V_121 ? L_5 : NULL ;
}
static void F_59 ( struct V_1 * V_2 )
{
F_60 ( V_2 -> V_122 , V_123 ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
return F_62 ( V_2 -> V_122 , V_123 ,
L_6 ) != NULL ? 0 : - V_124 ;
}
static void F_63 ( struct V_1 * V_2 , int V_86 )
{
if ( V_86 & V_125 ) {
V_2 -> type = V_121 ;
F_61 ( V_2 ) ;
}
}
static int F_64 ( struct V_1 * V_2 , struct V_126 * V_127 )
{
int V_128 = 0 ;
if ( V_127 -> type != V_129 && V_127 -> type != V_121 )
V_128 = - V_130 ;
if ( V_127 -> V_8 != V_2 -> V_8 )
V_128 = - V_130 ;
if ( V_127 -> V_131 < 9600 )
V_128 = - V_130 ;
return V_128 ;
}
static void F_65 ( struct V_1 * V_2 , int V_14 )
{
while ( ! ( F_16 ( V_2 ) & V_132 ) )
F_66 () ;
F_25 ( V_2 , V_14 ) ;
}
static void F_67 ( struct V_133 * V_134 , const char * V_135 , T_2 V_39 )
{
struct V_1 * V_2 = V_136 + V_134 -> V_137 ;
F_68 ( V_2 , V_135 , V_39 , F_65 ) ;
}
static void T_3 F_69 ( struct V_1 * V_2 , int * V_87 , int * V_29 , int * V_138 )
{
unsigned int V_71 ;
V_71 = F_41 ( V_2 ) ;
switch ( V_71 & V_139 ) {
case V_106 :
* V_29 = 'o' ;
break;
case V_107 :
* V_29 = 'e' ;
break;
default:
* V_29 = 'n' ;
}
switch ( V_71 & V_140 ) {
case V_93 :
* V_138 = 5 ;
break;
case V_95 :
* V_138 = 6 ;
break;
case V_97 :
* V_138 = 7 ;
break;
default:
* V_138 = 8 ;
}
* V_87 = V_2 -> V_89 / ( F_70 ( V_2 ) & 0x0FFF ) ;
* V_87 /= 16 ;
* V_87 &= 0xFFFFFFF0 ;
}
static int T_3 F_71 ( struct V_133 * V_134 , char * V_141 )
{
struct V_1 * V_2 ;
int V_87 = 115200 ;
int V_138 = 8 ;
int V_29 = 'n' ;
int V_142 = 'n' ;
V_2 = F_72 ( V_136 , V_143 , V_134 ) ;
if ( V_141 )
F_73 ( V_141 , & V_87 , & V_29 , & V_138 , & V_142 ) ;
else
F_69 ( V_2 , & V_87 , & V_29 , & V_138 ) ;
return F_74 ( V_2 , V_134 , V_87 , V_29 , V_138 , V_142 ) ;
}
static int T_3 F_75 ( void )
{
F_76 ( V_144 , 0 , NULL ) ;
F_77 ( & V_145 ) ;
return 0 ;
}
static int T_3 F_78 ( void )
{
int V_146 , V_128 ;
F_79 ( V_147 L_7 ) ;
V_128 = F_80 ( & V_148 ) ;
if ( V_128 )
return V_128 ;
for ( V_146 = 0 ; V_146 < V_143 ; V_146 ++ )
F_81 ( & V_148 , & V_136 [ 0 ] ) ;
return 0 ;
}
static void T_4 F_82 ( void )
{
int V_146 ;
for ( V_146 = 0 ; V_146 < V_143 ; V_146 ++ )
F_83 ( & V_148 , & V_136 [ 0 ] ) ;
F_84 ( & V_148 ) ;
}
