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
V_73 = F_45 ( V_5 , F_23 , V_76 , L_1 , V_2 ) ;
if ( V_73 )
goto V_77;
V_73 = F_45 ( V_6 , F_15 , V_76 , L_2 , V_2 ) ;
if ( V_73 )
goto V_78;
V_73 = F_45 ( V_79 , F_15 , V_76 , L_3 , V_2 ) ;
if ( V_73 )
goto V_80;
V_73 = F_45 ( V_7 , F_30 , V_76 , L_4 , V_2 ) ;
if ( V_73 )
goto V_81;
return 0 ;
V_81:
F_46 ( V_79 , V_2 ) ;
V_80:
F_46 ( V_6 , V_2 ) ;
V_78:
F_46 ( V_5 , V_2 ) ;
V_77:
return V_73 ;
}
static void F_47 ( struct V_1 * V_2 )
{
F_46 ( V_6 , V_2 ) ;
F_46 ( V_5 , V_2 ) ;
F_46 ( V_7 , V_2 ) ;
F_46 ( V_79 , V_2 ) ;
F_42 ( V_2 , F_41 ( V_2 ) & ~ V_72 ) ;
F_48 ( V_2 , F_49 ( V_2 ) & ~ V_82 ) ;
}
static void F_50 ( struct V_1 * V_2 , struct V_83 * V_84 , struct V_83 * V_85 )
{
unsigned int V_71 , V_86 = 0 ;
unsigned long V_87 ;
unsigned int V_88 , V_89 ;
V_88 = F_51 ( V_2 , V_84 , V_85 , 0 , V_2 -> V_90 / 16 ) ;
V_89 = F_52 ( V_2 , V_88 ) ;
switch ( V_84 -> V_91 & V_92 ) {
case V_93 :
V_71 = V_94 ;
break;
case V_95 :
V_71 = V_96 ;
break;
case V_97 :
V_71 = V_98 ;
break;
default:
V_71 = V_99 ;
break;
}
if ( V_84 -> V_91 & V_100 )
V_71 |= V_101 ;
if ( V_84 -> V_91 & V_102 ) {
if ( V_84 -> V_91 & V_103 ) {
if ( V_84 -> V_91 & V_104 )
V_71 |= V_105 ;
else
V_71 |= V_106 ;
}
else if ( V_84 -> V_91 & V_104 )
V_71 |= V_107 ;
else
V_71 |= V_108 ;
}
if ( V_2 -> V_109 > 1 )
V_86 = V_110 | V_111 | V_112 | V_82 ;
F_53 ( & V_2 -> V_113 , V_87 ) ;
F_54 ( V_2 , V_84 -> V_91 , V_88 ) ;
V_2 -> V_32 = V_26 ;
if ( V_84 -> V_114 & V_115 )
V_2 -> V_32 |= ( V_25 | V_24 ) ;
if ( V_84 -> V_114 & ( V_116 | V_117 ) )
V_2 -> V_32 |= V_23 ;
V_2 -> V_118 = 0 ;
if ( V_84 -> V_114 & V_119 )
V_2 -> V_118 |= ( V_25 | V_24 ) ;
if ( V_84 -> V_114 & V_120 ) {
V_2 -> V_118 |= V_23 ;
if ( V_84 -> V_114 & V_119 )
V_2 -> V_118 |= V_26 ;
}
if ( ( V_84 -> V_91 & V_121 ) == 0 )
V_2 -> V_118 |= V_22 ;
if ( F_55 ( V_2 , V_84 -> V_91 ) )
F_13 ( V_2 ) ;
else
F_14 ( V_2 ) ;
F_56 ( V_2 , V_89 ) ;
F_42 ( V_2 , V_71 ) ;
F_48 ( V_2 , V_86 ) ;
F_57 ( & V_2 -> V_113 , V_87 ) ;
}
static const char * F_58 ( struct V_1 * V_2 )
{
return V_2 -> type == V_122 ? L_5 : NULL ;
}
static void F_59 ( struct V_1 * V_2 )
{
F_60 ( V_2 -> V_123 , V_124 ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
return F_62 ( V_2 -> V_123 , V_124 ,
L_6 ) != NULL ? 0 : - V_125 ;
}
static void F_63 ( struct V_1 * V_2 , int V_87 )
{
if ( V_87 & V_126 ) {
V_2 -> type = V_122 ;
F_61 ( V_2 ) ;
}
}
static int F_64 ( struct V_1 * V_2 , struct V_127 * V_128 )
{
int V_129 = 0 ;
if ( V_128 -> type != V_130 && V_128 -> type != V_122 )
V_129 = - V_131 ;
if ( V_128 -> V_8 != V_2 -> V_8 )
V_129 = - V_131 ;
if ( V_128 -> V_132 < 9600 )
V_129 = - V_131 ;
return V_129 ;
}
static void F_65 ( struct V_1 * V_2 , int V_14 )
{
while ( ! ( F_16 ( V_2 ) & V_133 ) )
F_66 () ;
F_25 ( V_2 , V_14 ) ;
}
static void F_67 ( struct V_134 * V_135 , const char * V_136 , T_2 V_39 )
{
struct V_1 * V_2 = V_137 + V_135 -> V_138 ;
F_68 ( V_2 , V_136 , V_39 , F_65 ) ;
}
static void T_3 F_69 ( struct V_1 * V_2 , int * V_88 , int * V_29 , int * V_139 )
{
unsigned int V_71 ;
V_71 = F_41 ( V_2 ) ;
switch ( V_71 & V_140 ) {
case V_107 :
* V_29 = 'o' ;
break;
case V_108 :
* V_29 = 'e' ;
break;
default:
* V_29 = 'n' ;
}
switch ( V_71 & V_141 ) {
case V_94 :
* V_139 = 5 ;
break;
case V_96 :
* V_139 = 6 ;
break;
case V_98 :
* V_139 = 7 ;
break;
default:
* V_139 = 8 ;
}
* V_88 = V_2 -> V_90 / ( F_70 ( V_2 ) & 0x0FFF ) ;
* V_88 /= 16 ;
* V_88 &= 0xFFFFFFF0 ;
}
static int T_3 F_71 ( struct V_134 * V_135 , char * V_142 )
{
struct V_1 * V_2 ;
int V_88 = 115200 ;
int V_139 = 8 ;
int V_29 = 'n' ;
int V_143 = 'n' ;
V_2 = F_72 ( V_137 , V_144 , V_135 ) ;
if ( V_142 )
F_73 ( V_142 , & V_88 , & V_29 , & V_139 , & V_143 ) ;
else
F_69 ( V_2 , & V_88 , & V_29 , & V_139 ) ;
return F_74 ( V_2 , V_135 , V_88 , V_29 , V_139 , V_143 ) ;
}
static int T_3 F_75 ( void )
{
F_76 ( V_145 , 0 , NULL ) ;
F_77 ( & V_146 ) ;
return 0 ;
}
static int T_3 F_78 ( void )
{
int V_147 , V_129 ;
F_79 ( V_148 L_7 ) ;
V_129 = F_80 ( & V_149 ) ;
if ( V_129 )
return V_129 ;
for ( V_147 = 0 ; V_147 < V_144 ; V_147 ++ )
F_81 ( & V_149 , & V_137 [ 0 ] ) ;
return 0 ;
}
static void T_4 F_82 ( void )
{
int V_147 ;
for ( V_147 = 0 ; V_147 < V_144 ; V_147 ++ )
F_83 ( & V_149 , & V_137 [ 0 ] ) ;
F_84 ( & V_149 ) ;
}
