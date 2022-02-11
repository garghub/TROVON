static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( V_4 ) ;
F_3 ( & V_4 -> V_5 ) ;
return V_6 ;
}
static inline int F_4 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = & V_4 -> V_7 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
int V_11 ;
V_11 = ( ( V_10 -> V_12 - V_8 -> V_13 ) * 8 )
/ ( V_8 -> V_14 * V_8 -> V_15 ) ;
return F_5 ( V_11 , 2 ) ;
}
static inline bool F_6 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = & V_4 -> V_7 ;
if ( F_7 ( V_4 ) || F_8 ( V_4 ) ) {
if ( V_8 -> V_14 == 14 )
return false ;
if ( V_8 -> V_11 > V_16 )
return false ;
} else if ( F_9 ( V_4 ) ) {
if ( V_8 -> V_11 > V_17 )
return false ;
}
return true ;
}
static bool F_10 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = & V_4 -> V_7 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
struct V_18 * V_19 = V_10 -> V_20 ;
struct V_21 * V_22 = V_23 . V_24 ;
unsigned int V_25 ;
if ( ! ( V_19 -> V_26 > 0 && V_19 -> V_27 > 0 ) )
return false ;
switch ( V_19 -> V_27 ) {
case V_28 :
V_8 -> V_14 = 13 ;
break;
case V_29 :
V_8 -> V_14 = 14 ;
break;
default:
F_11 ( V_4 -> V_30 ,
L_1 ,
V_19 -> V_26 , V_19 -> V_27 ) ;
return false ;
}
V_8 -> V_31 = V_19 -> V_27 ;
V_8 -> V_11 = F_12 ( V_19 -> V_26 , 2 ) ;
if ( ! F_6 ( V_4 ) )
return false ;
if ( V_8 -> V_31 < V_10 -> V_12 ) {
F_11 ( V_4 -> V_30 ,
L_2 ,
V_19 -> V_27 , V_10 -> V_12 ) ;
return false ;
}
V_8 -> V_13 = 10 ;
V_8 -> V_15 = V_10 -> V_32 / V_8 -> V_31 ;
V_8 -> V_33 = V_10 -> V_32 + V_8 -> V_13 +
( V_8 -> V_14 * V_8 -> V_11 * V_8 -> V_15 ) / 8 ;
if ( V_8 -> V_33 < V_10 -> V_32 + V_10 -> V_12 ) {
V_22 -> V_34 = V_8 -> V_33 - V_10 -> V_32 ;
V_22 -> V_35 = V_10 -> V_12 - V_22 -> V_34 ;
}
V_8 -> V_36 = V_10 -> V_32 ;
V_8 -> V_37 = F_13 ( V_8 -> V_13 , 4 ) ;
V_8 -> V_38 = F_13 ( V_8 -> V_13 , 4 )
+ F_13 ( V_8 -> V_15 , 4 ) ;
if ( ! V_4 -> V_39 )
return true ;
V_25 = V_10 -> V_32 * 8 -
( V_8 -> V_11 * V_8 -> V_14 * ( V_8 -> V_15 - 1 )
+ V_8 -> V_13 * 8 ) ;
V_8 -> V_40 = V_25 / 8 ;
V_8 -> V_25 = V_25 % 8 ;
return true ;
}
static int F_14 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = & V_4 -> V_7 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
unsigned int V_13 ;
unsigned int V_41 ;
unsigned int V_25 ;
V_8 -> V_13 = 10 ;
V_8 -> V_14 = 13 ;
V_8 -> V_31 = 512 ;
while ( V_8 -> V_31 < V_10 -> V_12 ) {
V_8 -> V_31 *= 2 ;
V_8 -> V_14 = 14 ;
}
V_8 -> V_15 = V_10 -> V_32 / V_8 -> V_31 ;
V_8 -> V_11 = F_4 ( V_4 ) ;
if ( ! F_6 ( V_4 ) ) {
F_11 ( V_4 -> V_30 ,
L_3
L_4
L_5 , V_8 -> V_11 ,
( F_9 ( V_4 ) ? V_17
: V_16 ) ) ;
return - V_42 ;
}
V_8 -> V_33 = V_10 -> V_32 + V_10 -> V_12 ;
V_8 -> V_36 = V_10 -> V_32 ;
V_13 = F_13 ( V_8 -> V_13 , 4 ) ;
V_41 = F_13 ( V_8 -> V_15 , 4 ) ;
V_8 -> V_38 = V_13 + V_41 ;
V_8 -> V_37 = V_13 ;
if ( ! V_4 -> V_39 )
return 0 ;
V_25 = V_10 -> V_32 * 8 -
( V_8 -> V_11 * V_8 -> V_14 * ( V_8 -> V_15 - 1 )
+ V_8 -> V_13 * 8 ) ;
V_8 -> V_40 = V_25 / 8 ;
V_8 -> V_25 = V_25 % 8 ;
return 0 ;
}
int F_15 ( struct V_3 * V_4 )
{
return F_14 ( V_4 ) ;
}
struct V_43 * F_16 ( struct V_3 * V_4 )
{
int V_44 = V_4 -> V_45 ;
return V_4 -> V_46 [ V_44 ] ;
}
void F_17 ( struct V_3 * V_4 , enum V_47 V_48 )
{
struct V_49 * V_50 = & V_4 -> V_51 ;
int V_52 ;
V_4 -> V_53 = true ;
F_18 ( V_50 , V_4 -> V_54 , V_4 -> V_55 ) ;
V_52 = F_19 ( V_4 -> V_30 , V_50 , 1 , V_48 ) ;
if ( V_52 == 0 ) {
F_18 ( V_50 , V_4 -> V_56 , V_57 ) ;
if ( V_48 == V_58 )
memcpy ( V_4 -> V_56 , V_4 -> V_54 ,
V_4 -> V_55 ) ;
V_52 = F_19 ( V_4 -> V_30 , V_50 , 1 , V_48 ) ;
if ( V_52 == 0 )
F_20 ( L_6 ) ;
V_4 -> V_53 = false ;
}
}
static void F_21 ( void * V_59 )
{
struct V_3 * V_4 = V_59 ;
struct V_60 * V_61 = & V_4 -> V_62 ;
F_3 ( V_61 ) ;
switch ( V_4 -> V_63 ) {
case V_64 :
F_22 ( V_4 -> V_30 , & V_4 -> V_65 , 1 , V_58 ) ;
break;
case V_66 :
F_22 ( V_4 -> V_30 , & V_4 -> V_51 , 1 , V_67 ) ;
if ( V_4 -> V_53 == false )
memcpy ( V_4 -> V_54 , V_4 -> V_56 ,
V_4 -> V_55 ) ;
break;
case V_68 :
F_22 ( V_4 -> V_30 , & V_4 -> V_51 , 1 , V_58 ) ;
break;
case V_69 :
case V_70 :
break;
default:
F_20 ( L_7 ) ;
}
}
int F_23 ( struct V_3 * V_4 ,
struct V_71 * V_72 )
{
struct V_60 * V_61 = & V_4 -> V_62 ;
int V_73 ;
F_24 ( V_61 ) ;
V_72 -> V_74 = F_21 ;
V_72 -> V_75 = V_4 ;
F_25 ( V_72 ) ;
F_26 ( F_16 ( V_4 ) ) ;
V_73 = F_27 ( V_61 , F_28 ( 1000 ) ) ;
if ( ! V_73 ) {
F_20 ( L_8 , V_4 -> V_76 ) ;
F_29 ( V_4 ) ;
return - V_77 ;
}
return 0 ;
}
int F_30 ( struct V_3 * V_4 ,
struct V_71 * V_72 )
{
struct V_60 * V_78 = & V_4 -> V_5 ;
int V_73 ;
F_24 ( V_78 ) ;
F_23 ( V_4 , V_72 ) ;
V_73 = F_27 ( V_78 , F_28 ( 1000 ) ) ;
if ( ! V_73 ) {
F_20 ( L_9 , V_4 -> V_76 ) ;
F_29 ( V_4 ) ;
return - V_77 ;
}
return 0 ;
}
static int F_31 ( struct V_3 * V_4 ,
const char * V_79 )
{
struct V_80 * V_81 = V_4 -> V_81 ;
struct V_82 * V_83 = & V_4 -> V_82 ;
struct V_84 * V_85 ;
void T_2 * V_86 ;
V_85 = F_32 ( V_81 , V_87 , V_79 ) ;
if ( ! V_85 ) {
F_20 ( L_10 , V_79 ) ;
return - V_88 ;
}
V_86 = F_33 ( V_85 -> V_89 , F_34 ( V_85 ) ) ;
if ( ! V_86 ) {
F_20 ( L_11 , V_79 ) ;
return - V_90 ;
}
if ( ! strcmp ( V_79 , V_91 ) )
V_83 -> V_92 = V_86 ;
else if ( ! strcmp ( V_79 , V_93 ) )
V_83 -> V_94 = V_86 ;
else
F_20 ( L_12 , V_79 ) ;
return 0 ;
}
static void F_35 ( struct V_3 * V_4 )
{
struct V_82 * V_83 = & V_4 -> V_82 ;
if ( V_83 -> V_92 )
F_36 ( V_83 -> V_92 ) ;
if ( V_83 -> V_94 )
F_36 ( V_83 -> V_94 ) ;
V_83 -> V_92 = NULL ;
V_83 -> V_94 = NULL ;
}
static int F_37 ( struct V_3 * V_4 , T_3 V_95 )
{
struct V_80 * V_81 = V_4 -> V_81 ;
struct V_82 * V_83 = & V_4 -> V_82 ;
const char * V_79 = V_96 ;
struct V_84 * V_85 ;
int V_73 ;
V_85 = F_32 ( V_81 , V_97 , V_79 ) ;
if ( ! V_85 ) {
F_20 ( L_10 , V_79 ) ;
return - V_88 ;
}
V_73 = F_38 ( V_85 -> V_89 , V_95 , 0 , V_79 , V_4 ) ;
if ( V_73 ) {
F_20 ( L_13 , V_79 ) ;
return V_73 ;
}
V_83 -> V_98 = V_85 -> V_89 ;
V_83 -> V_99 = V_85 -> V_100 ;
return 0 ;
}
static void F_39 ( struct V_3 * V_4 )
{
struct V_82 * V_83 = & V_4 -> V_82 ;
int V_101 = V_83 -> V_98 ;
for (; V_101 <= V_83 -> V_99 ; V_101 ++ )
F_40 ( V_101 , V_4 ) ;
}
static void F_41 ( struct V_3 * V_4 )
{
unsigned int V_101 ;
for ( V_101 = 0 ; V_101 < V_102 ; V_101 ++ )
if ( V_4 -> V_46 [ V_101 ] ) {
F_42 ( V_4 -> V_46 [ V_101 ] ) ;
V_4 -> V_46 [ V_101 ] = NULL ;
}
}
static int F_43 ( struct V_3 * V_4 )
{
struct V_80 * V_81 = V_4 -> V_81 ;
struct V_43 * V_43 ;
V_43 = F_44 ( & V_81 -> V_30 , L_14 ) ;
if ( ! V_43 ) {
F_20 ( L_15 ) ;
goto V_103;
}
V_4 -> V_46 [ 0 ] = V_43 ;
return 0 ;
V_103:
F_41 ( V_4 ) ;
return - V_42 ;
}
static void F_45 ( struct V_3 * V_4 )
{
struct V_82 * V_85 = & V_4 -> V_82 ;
struct V_104 * V_104 ;
int V_101 ;
for ( V_101 = 0 ; V_101 < V_105 ; V_101 ++ ) {
V_104 = V_85 -> clock [ V_101 ] ;
if ( V_104 ) {
F_46 ( V_104 ) ;
V_85 -> clock [ V_101 ] = NULL ;
}
}
}
static int F_47 ( struct V_3 * V_4 )
{
struct V_82 * V_85 = & V_4 -> V_82 ;
char * * V_106 = NULL ;
struct V_104 * V_104 ;
int V_73 , V_101 ;
V_85 -> clock [ 0 ] = F_48 ( V_4 -> V_30 , L_16 ) ;
if ( F_49 ( V_85 -> clock [ 0 ] ) ) {
V_73 = F_50 ( V_85 -> clock [ 0 ] ) ;
goto V_107;
}
if ( F_9 ( V_4 ) )
V_106 = V_108 ;
if ( ! V_106 )
return 0 ;
for ( V_101 = 1 ; V_101 < V_105 ; V_101 ++ ) {
if ( V_106 [ V_101 - 1 ] == NULL )
break;
V_104 = F_48 ( V_4 -> V_30 , V_106 [ V_101 - 1 ] ) ;
if ( F_49 ( V_104 ) ) {
V_73 = F_50 ( V_104 ) ;
goto V_107;
}
V_85 -> clock [ V_101 ] = V_104 ;
}
if ( F_9 ( V_4 ) )
F_51 ( V_85 -> clock [ 0 ] , 22000000 ) ;
return 0 ;
V_107:
F_52 ( V_4 -> V_30 , L_17 ) ;
F_45 ( V_4 ) ;
return V_73 ;
}
static int F_53 ( struct V_3 * V_4 )
{
int V_52 ;
V_52 = F_31 ( V_4 , V_91 ) ;
if ( V_52 )
goto V_109;
V_52 = F_31 ( V_4 , V_93 ) ;
if ( V_52 )
goto V_109;
V_52 = F_37 ( V_4 , F_1 ) ;
if ( V_52 )
goto V_109;
V_52 = F_43 ( V_4 ) ;
if ( V_52 )
goto V_110;
V_52 = F_47 ( V_4 ) ;
if ( V_52 )
goto V_111;
return 0 ;
V_111:
F_41 ( V_4 ) ;
V_110:
F_39 ( V_4 ) ;
V_109:
F_35 ( V_4 ) ;
return V_52 ;
}
static void F_54 ( struct V_3 * V_4 )
{
F_45 ( V_4 ) ;
F_35 ( V_4 ) ;
F_39 ( V_4 ) ;
F_41 ( V_4 ) ;
}
static int F_55 ( struct V_3 * V_4 )
{
int V_52 ;
struct V_112 V_113 = {
. V_114 = 80 ,
. V_115 = 60 ,
. V_116 = 25 ,
. V_117 = 6 ,
. V_118 = - 1 ,
. V_119 = - 1 ,
. V_120 = - 1 ,
} ;
V_52 = F_56 ( V_4 ) ;
if ( V_52 )
return V_52 ;
V_4 -> V_121 = V_113 ;
return 0 ;
}
static int F_57 ( struct V_3 * V_4 ,
void * V_122 , unsigned V_35 ,
void * V_123 , T_4 V_124 , unsigned V_125 ,
void * * V_126 , T_4 * V_127 )
{
struct V_128 * V_30 = V_4 -> V_30 ;
if ( F_58 ( V_122 ) ) {
T_4 V_129 ;
V_129 = F_59 ( V_30 , V_122 ,
V_35 , V_67 ) ;
if ( F_60 ( V_30 , V_129 ) ) {
if ( V_125 < V_35 ) {
F_20 ( L_18 ,
V_130 ) ;
return - V_90 ;
}
goto V_131;
}
* V_126 = V_122 ;
* V_127 = V_129 ;
V_4 -> V_53 = true ;
return 0 ;
}
V_131:
* V_126 = V_123 ;
* V_127 = V_124 ;
V_4 -> V_53 = false ;
return 0 ;
}
static inline void F_61 ( struct V_3 * V_4 ,
void * V_122 , unsigned V_35 ,
void * V_123 , T_4 V_124 , unsigned V_125 ,
void * V_132 , T_4 V_133 )
{
if ( V_4 -> V_53 )
F_62 ( V_4 -> V_30 , V_133 , V_35 , V_67 ) ;
}
static inline void F_63 ( struct V_3 * V_4 ,
void * V_122 , unsigned V_35 ,
void * V_123 , T_4 V_124 , unsigned V_125 ,
void * V_132 , T_4 V_133 )
{
if ( ! V_4 -> V_53 )
memcpy ( V_122 , V_123 , V_35 ) ;
}
static int F_64 ( struct V_3 * V_4 ,
const void * V_134 , unsigned V_35 ,
void * V_123 , T_4 V_124 , unsigned V_125 ,
const void * * V_126 , T_4 * V_127 )
{
struct V_128 * V_30 = V_4 -> V_30 ;
if ( F_58 ( V_134 ) ) {
T_4 V_135 ;
V_135 = F_59 ( V_30 , ( void * ) V_134 , V_35 ,
V_58 ) ;
if ( F_60 ( V_30 , V_135 ) ) {
if ( V_125 < V_35 ) {
F_20 ( L_18 ,
V_130 ) ;
return - V_90 ;
}
goto V_131;
}
* V_126 = V_134 ;
* V_127 = V_135 ;
return 0 ;
}
V_131:
memcpy ( V_123 , V_134 , V_35 ) ;
* V_126 = V_123 ;
* V_127 = V_124 ;
return 0 ;
}
static void F_65 ( struct V_3 * V_4 ,
const void * V_134 , unsigned V_35 ,
void * V_123 , T_4 V_124 , unsigned V_125 ,
const void * V_132 , T_4 V_133 )
{
struct V_128 * V_30 = V_4 -> V_30 ;
if ( V_132 == V_134 )
F_62 ( V_30 , V_133 , V_35 , V_58 ) ;
}
static void F_66 ( struct V_3 * V_4 )
{
struct V_128 * V_30 = V_4 -> V_30 ;
if ( V_4 -> V_136 && F_58 ( V_4 -> V_136 ) )
F_67 ( V_30 , V_4 -> V_137 ,
V_4 -> V_136 ,
V_4 -> V_138 ) ;
F_68 ( V_4 -> V_139 ) ;
F_68 ( V_4 -> V_56 ) ;
V_4 -> V_139 = NULL ;
V_4 -> V_56 = NULL ;
V_4 -> V_136 = NULL ;
V_4 -> V_137 = 0 ;
}
static int F_69 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = & V_4 -> V_7 ;
struct V_128 * V_30 = V_4 -> V_30 ;
V_4 -> V_139 = F_70 ( V_57 , V_140 | V_141 ) ;
if ( V_4 -> V_139 == NULL )
goto V_142;
V_4 -> V_56 = F_70 ( V_57 , V_140 | V_141 ) ;
if ( V_4 -> V_56 == NULL )
goto V_142;
V_4 -> V_137 = V_8 -> V_36 + V_8 -> V_38 ;
V_4 -> V_136 = F_71 ( V_30 , V_4 -> V_137 ,
& V_4 -> V_138 , V_140 ) ;
if ( ! V_4 -> V_136 )
goto V_142;
V_4 -> V_143 = V_4 -> V_136 ;
V_4 -> V_144 = V_4 -> V_138 ;
V_4 -> V_145 = V_4 -> V_143 + V_8 -> V_36 ;
V_4 -> V_146 = V_4 -> V_144 + V_8 -> V_36 ;
return 0 ;
V_142:
F_66 ( V_4 ) ;
F_20 ( L_19 ) ;
return - V_90 ;
}
static void F_72 ( struct V_9 * V_10 , int V_147 , unsigned int V_148 )
{
struct V_18 * V_19 = V_10 -> V_20 ;
struct V_3 * V_4 = V_19 -> V_20 ;
int V_52 ;
if ( ( V_148 & ( V_149 | V_150 ) ) ) {
if ( V_147 != V_151 )
V_4 -> V_139 [ V_4 -> V_152 ++ ] = V_147 ;
return;
}
if ( ! V_4 -> V_152 )
return;
V_52 = F_73 ( V_4 ) ;
if ( V_52 )
F_20 ( L_20 , V_4 -> V_45 , V_52 ) ;
V_4 -> V_152 = 0 ;
}
static int F_74 ( struct V_9 * V_10 )
{
struct V_18 * V_19 = V_10 -> V_20 ;
struct V_3 * V_4 = V_19 -> V_20 ;
return F_75 ( V_4 , V_4 -> V_45 ) ;
}
static void F_76 ( struct V_9 * V_10 , int V_44 )
{
struct V_18 * V_19 = V_10 -> V_20 ;
struct V_3 * V_4 = V_19 -> V_20 ;
if ( ( V_4 -> V_45 < 0 ) && ( V_44 >= 0 ) )
F_77 ( V_4 ) ;
else if ( ( V_4 -> V_45 >= 0 ) && ( V_44 < 0 ) )
F_78 ( V_4 ) ;
V_4 -> V_45 = V_44 ;
}
static void F_79 ( struct V_9 * V_10 , T_5 * V_153 , int V_154 )
{
struct V_18 * V_19 = V_10 -> V_20 ;
struct V_3 * V_4 = V_19 -> V_20 ;
F_80 ( L_21 , V_154 ) ;
V_4 -> V_54 = V_153 ;
V_4 -> V_55 = V_154 ;
F_81 ( V_4 ) ;
}
static void F_82 ( struct V_9 * V_10 , const T_5 * V_153 , int V_154 )
{
struct V_18 * V_19 = V_10 -> V_20 ;
struct V_3 * V_4 = V_19 -> V_20 ;
F_80 ( L_21 , V_154 ) ;
V_4 -> V_54 = ( T_5 * ) V_153 ;
V_4 -> V_55 = V_154 ;
F_83 ( V_4 ) ;
}
static T_5 F_84 ( struct V_9 * V_10 )
{
struct V_18 * V_19 = V_10 -> V_20 ;
struct V_3 * V_4 = V_19 -> V_20 ;
T_5 * V_153 = V_4 -> V_56 ;
F_79 ( V_10 , V_153 , 1 ) ;
return V_153 [ 0 ] ;
}
static void F_85 ( struct V_3 * V_4 ,
void * V_155 , void * V_156 )
{
struct V_7 * V_157 = & V_4 -> V_7 ;
unsigned char * V_86 ;
unsigned char * V_158 ;
unsigned int V_159 ;
unsigned char V_160 ;
unsigned char V_161 ;
unsigned char V_162 ;
if ( ! V_4 -> V_39 )
return;
V_159 = V_157 -> V_25 ;
V_86 = V_155 + V_157 -> V_40 ;
V_158 = V_156 ;
V_161 = ( V_86 [ 0 ] >> V_159 ) | ( V_86 [ 1 ] << ( 8 - V_159 ) ) ;
V_162 = V_158 [ 0 ] ;
V_158 [ 0 ] = V_161 ;
V_160 = ( 0x1 << V_159 ) - 1 ;
V_86 [ 0 ] = ( V_86 [ 0 ] & V_160 ) | ( V_162 << V_159 ) ;
V_160 = ~ 0 << V_159 ;
V_86 [ 1 ] = ( V_86 [ 1 ] & V_160 ) | ( V_162 >> ( 8 - V_159 ) ) ;
}
static int F_86 ( struct V_9 * V_10 , struct V_18 * V_19 ,
T_5 * V_153 , int V_163 , int V_164 )
{
struct V_3 * V_4 = V_19 -> V_20 ;
struct V_7 * V_157 = & V_4 -> V_7 ;
void * V_143 ;
T_4 V_144 ;
void * V_145 ;
T_4 V_146 ;
unsigned int V_101 ;
unsigned char * V_165 ;
unsigned int V_166 = 0 ;
int V_52 ;
F_80 ( L_22 , V_164 ) ;
V_52 = F_57 ( V_4 , V_153 , V_10 -> V_32 ,
V_4 -> V_143 , V_4 -> V_144 ,
V_157 -> V_36 ,
& V_143 , & V_144 ) ;
if ( V_52 ) {
F_20 ( L_23 ) ;
V_52 = - V_90 ;
return V_52 ;
}
V_145 = V_4 -> V_145 ;
V_146 = V_4 -> V_146 ;
V_52 = F_87 ( V_4 , V_144 , V_146 ) ;
F_61 ( V_4 , V_153 , V_10 -> V_32 ,
V_4 -> V_143 , V_4 -> V_144 ,
V_157 -> V_36 ,
V_143 , V_144 ) ;
if ( V_52 ) {
F_20 ( L_24 , V_52 ) ;
return V_52 ;
}
F_85 ( V_4 , V_143 , V_145 ) ;
V_165 = V_145 + V_157 -> V_37 ;
for ( V_101 = 0 ; V_101 < V_157 -> V_15 ; V_101 ++ , V_165 ++ ) {
if ( ( * V_165 == V_167 ) || ( * V_165 == V_168 ) )
continue;
if ( * V_165 == V_169 ) {
V_10 -> V_170 . V_171 ++ ;
continue;
}
V_10 -> V_170 . V_172 += * V_165 ;
V_166 = F_88 (unsigned int, max_bitflips, *status) ;
}
if ( V_163 ) {
memset ( V_19 -> V_173 , ~ 0 , V_10 -> V_12 ) ;
V_19 -> V_173 [ 0 ] = ( ( T_5 * ) V_145 ) [ 0 ] ;
}
F_63 ( V_4 , V_153 , V_10 -> V_32 ,
V_4 -> V_143 , V_4 -> V_144 ,
V_157 -> V_36 ,
V_143 , V_144 ) ;
return V_166 ;
}
static int F_89 ( struct V_9 * V_10 , struct V_18 * V_19 ,
const T_5 * V_153 , int V_163 )
{
struct V_3 * V_4 = V_19 -> V_20 ;
struct V_7 * V_157 = & V_4 -> V_7 ;
const void * V_143 ;
T_4 V_144 ;
const void * V_145 ;
T_4 V_146 ;
int V_52 ;
F_80 ( L_25 ) ;
if ( V_4 -> V_39 ) {
memcpy ( V_4 -> V_143 , V_153 , V_10 -> V_32 ) ;
V_143 = V_4 -> V_143 ;
V_144 = V_4 -> V_144 ;
memcpy ( V_4 -> V_145 , V_19 -> V_173 ,
V_157 -> V_38 ) ;
V_145 = V_4 -> V_145 ;
V_146 = V_4 -> V_146 ;
F_85 ( V_4 ,
( void * ) V_143 , ( void * ) V_145 ) ;
} else {
V_52 = F_64 ( V_4 ,
V_153 , V_10 -> V_32 ,
V_4 -> V_143 , V_4 -> V_144 ,
V_157 -> V_36 ,
& V_143 , & V_144 ) ;
if ( V_52 ) {
F_20 ( L_26 ) ;
return 0 ;
}
V_52 = F_64 ( V_4 ,
V_19 -> V_173 , V_10 -> V_12 ,
V_4 -> V_145 , V_4 -> V_146 ,
V_157 -> V_38 ,
& V_145 , & V_146 ) ;
if ( V_52 ) {
F_20 ( L_27 ) ;
goto V_174;
}
}
V_52 = F_90 ( V_4 , V_144 , V_146 ) ;
if ( V_52 )
F_20 ( L_28 , V_52 ) ;
if ( ! V_4 -> V_39 ) {
F_65 ( V_4 , V_19 -> V_173 , V_10 -> V_12 ,
V_4 -> V_145 , V_4 -> V_146 ,
V_157 -> V_38 ,
V_145 , V_146 ) ;
V_174:
F_65 ( V_4 , V_153 , V_10 -> V_32 ,
V_4 -> V_143 , V_4 -> V_144 ,
V_157 -> V_36 ,
V_143 , V_144 ) ;
}
return 0 ;
}
static int F_91 ( struct V_9 * V_10 , struct V_18 * V_19 ,
int V_164 )
{
struct V_3 * V_4 = V_19 -> V_20 ;
F_80 ( L_29 , V_164 ) ;
memset ( V_19 -> V_173 , ~ 0 , V_10 -> V_12 ) ;
V_19 -> V_175 ( V_10 , V_176 , V_10 -> V_32 , V_164 ) ;
V_19 -> V_177 ( V_10 , V_19 -> V_173 , V_10 -> V_12 ) ;
if ( ! V_4 -> V_39 ) {
V_19 -> V_175 ( V_10 , V_176 , 0 , V_164 ) ;
V_19 -> V_173 [ 0 ] = V_19 -> V_178 ( V_10 ) ;
}
return 0 ;
}
static int
F_92 ( struct V_9 * V_10 , struct V_18 * V_19 , int V_164 )
{
return - V_179 ;
}
static int F_93 ( struct V_9 * V_10 , T_6 V_180 )
{
struct V_18 * V_19 = V_10 -> V_20 ;
struct V_3 * V_4 = V_19 -> V_20 ;
int V_52 = 0 ;
T_5 * V_181 ;
int V_182 , V_164 , V_165 , V_44 ;
V_44 = ( int ) ( V_180 >> V_19 -> V_183 ) ;
V_19 -> V_184 ( V_10 , V_44 ) ;
V_182 = V_4 -> V_39 ? V_10 -> V_32 : 0 ;
V_181 = V_4 -> V_56 ;
V_181 [ 0 ] = 0 ;
V_164 = ( int ) ( V_180 >> V_19 -> V_185 ) ;
V_19 -> V_175 ( V_10 , V_186 , V_182 , V_164 ) ;
V_19 -> V_187 ( V_10 , V_181 , 1 ) ;
V_19 -> V_175 ( V_10 , V_188 , - 1 , - 1 ) ;
V_165 = V_19 -> V_189 ( V_10 , V_19 ) ;
if ( V_165 & V_190 )
V_52 = - V_191 ;
V_19 -> V_184 ( V_10 , - 1 ) ;
return V_52 ;
}
static int F_94 ( struct V_3 * V_4 )
{
struct V_192 * V_193 = & V_4 -> V_194 ;
V_193 -> V_195 = 64 ;
V_193 -> V_196 = 2 ;
return 0 ;
}
static int F_95 ( struct V_3 * V_4 )
{
struct V_192 * V_197 = & V_4 -> V_194 ;
struct V_128 * V_30 = V_4 -> V_30 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
struct V_18 * V_19 = & V_4 -> V_198 ;
unsigned int V_199 ;
unsigned int V_200 ;
unsigned int V_164 ;
T_5 * V_201 = V_19 -> V_202 -> V_203 ;
int V_204 ;
int V_205 = false ;
V_199 = 1 << V_197 -> V_196 ;
V_204 = V_4 -> V_45 ;
V_19 -> V_184 ( V_10 , 0 ) ;
F_52 ( V_30 , L_30 ) ;
for ( V_200 = 0 ; V_200 < V_199 ; V_200 ++ ) {
V_164 = V_200 * V_197 -> V_195 ;
F_52 ( V_30 , L_31 , V_164 ) ;
V_19 -> V_175 ( V_10 , V_176 , 12 , V_164 ) ;
V_19 -> V_177 ( V_10 , V_201 , strlen ( V_206 ) ) ;
if ( ! memcmp ( V_201 , V_206 , strlen ( V_206 ) ) ) {
V_205 = true ;
break;
}
}
V_19 -> V_184 ( V_10 , V_204 ) ;
if ( V_205 )
F_52 ( V_30 , L_32 ) ;
else
F_52 ( V_30 , L_33 ) ;
return V_205 ;
}
static int F_96 ( struct V_3 * V_4 )
{
struct V_128 * V_30 = V_4 -> V_30 ;
struct V_192 * V_197 = & V_4 -> V_194 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
struct V_18 * V_19 = & V_4 -> V_198 ;
unsigned int V_207 ;
unsigned int V_199 ;
unsigned int V_208 ;
unsigned int V_209 ;
unsigned int V_210 ;
unsigned int V_200 ;
unsigned int V_164 ;
T_5 * V_201 = V_19 -> V_202 -> V_203 ;
int V_204 ;
int V_165 ;
V_207 = V_10 -> V_211 / V_10 -> V_32 ;
V_199 = 1 << V_197 -> V_196 ;
V_208 = V_199 *
V_197 -> V_195 ;
V_209 =
( V_208 + ( V_207 - 1 ) ) /
V_207 ;
F_52 ( V_30 , L_34 ) ;
F_52 ( V_30 , L_35 , V_209 ) ;
F_52 ( V_30 , L_36 , V_199 ) ;
F_52 ( V_30 , L_37 , V_208 ) ;
V_204 = V_4 -> V_45 ;
V_19 -> V_184 ( V_10 , 0 ) ;
F_52 ( V_30 , L_38 ) ;
for ( V_210 = 0 ; V_210 < V_209 ; V_210 ++ ) {
V_164 = V_210 * V_207 ;
F_52 ( V_30 , L_39 , V_210 ) ;
V_19 -> V_175 ( V_10 , V_212 , - 1 , V_164 ) ;
V_19 -> V_175 ( V_10 , V_213 , - 1 , - 1 ) ;
V_165 = V_19 -> V_189 ( V_10 , V_19 ) ;
if ( V_165 & V_190 )
F_11 ( V_30 , L_40 , V_130 ) ;
}
memset ( V_201 , ~ 0 , V_10 -> V_32 ) ;
memset ( V_19 -> V_173 , ~ 0 , V_10 -> V_12 ) ;
memcpy ( V_201 + 12 , V_206 , strlen ( V_206 ) ) ;
F_52 ( V_30 , L_41 ) ;
for ( V_200 = 0 ; V_200 < V_199 ; V_200 ++ ) {
V_164 = V_200 * V_197 -> V_195 ;
F_52 ( V_30 , L_42 , V_164 ) ;
V_19 -> V_175 ( V_10 , V_186 , 0x00 , V_164 ) ;
V_19 -> V_214 . V_215 ( V_10 , V_19 , V_201 , 0 ) ;
V_19 -> V_175 ( V_10 , V_188 , - 1 , - 1 ) ;
V_165 = V_19 -> V_189 ( V_10 , V_19 ) ;
if ( V_165 & V_190 )
F_11 ( V_30 , L_43 , V_130 ) ;
}
V_19 -> V_184 ( V_10 , V_204 ) ;
return 0 ;
}
static int F_97 ( struct V_3 * V_4 )
{
struct V_128 * V_30 = V_4 -> V_30 ;
struct V_18 * V_19 = & V_4 -> V_198 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
unsigned int V_216 ;
unsigned int V_210 ;
int V_44 ;
int V_164 ;
T_6 V_217 ;
T_5 V_181 ;
int V_52 = 0 ;
if ( F_95 ( V_4 ) )
return 0 ;
F_52 ( V_30 , L_44 ) ;
V_216 = V_19 -> V_218 >> V_19 -> V_219 ;
for ( V_210 = 0 ; V_210 < V_216 ; V_210 ++ ) {
V_44 = V_210 >> ( V_19 -> V_183 - V_19 -> V_219 ) ;
V_164 = V_210 << ( V_19 -> V_219 - V_19 -> V_185 ) ;
V_217 = V_210 << V_19 -> V_219 ;
V_19 -> V_184 ( V_10 , V_44 ) ;
V_19 -> V_175 ( V_10 , V_176 , V_10 -> V_32 , V_164 ) ;
V_181 = V_19 -> V_178 ( V_10 ) ;
V_19 -> V_184 ( V_10 , - 1 ) ;
if ( V_181 != 0xff ) {
F_52 ( V_30 , L_45 , V_210 ) ;
V_52 = V_19 -> V_220 ( V_10 , V_217 ) ;
if ( V_52 )
F_11 ( V_30 , L_46
L_47 , V_52 ) ;
}
}
F_96 ( V_4 ) ;
return 0 ;
}
static int F_98 ( struct V_3 * V_4 )
{
F_94 ( V_4 ) ;
if ( F_7 ( V_4 ) )
return F_97 ( V_4 ) ;
return 0 ;
}
static int F_99 ( struct V_3 * V_4 )
{
int V_52 ;
F_66 ( V_4 ) ;
V_52 = F_100 ( V_4 ) ;
if ( V_52 ) {
F_20 ( L_48 , V_52 ) ;
return V_52 ;
}
return F_69 ( V_4 ) ;
}
static int F_101 ( struct V_3 * V_4 )
{
int V_52 ;
if ( F_7 ( V_4 ) )
V_4 -> V_39 = false ;
else
V_4 -> V_39 = true ;
V_52 = F_99 ( V_4 ) ;
if ( V_52 )
return V_52 ;
return F_98 ( V_4 ) ;
}
static void F_102 ( struct V_3 * V_4 )
{
F_103 ( & V_4 -> V_10 ) ;
F_66 ( V_4 ) ;
}
static int F_104 ( struct V_3 * V_4 )
{
struct V_9 * V_10 = & V_4 -> V_10 ;
struct V_18 * V_19 = V_10 -> V_20 ;
struct V_221 * V_214 = & V_19 -> V_214 ;
struct V_7 * V_222 = & V_4 -> V_7 ;
int V_52 ;
V_52 = F_101 ( V_4 ) ;
if ( V_52 )
return V_52 ;
V_214 -> V_223 = F_86 ;
V_214 -> V_224 = F_89 ;
V_214 -> V_225 = F_91 ;
V_214 -> V_226 = F_92 ;
V_214 -> V_227 = V_228 ;
V_214 -> V_229 = V_222 -> V_31 ;
V_214 -> V_230 = V_222 -> V_11 ;
V_214 -> V_231 = & V_23 ;
F_105 ( V_4 ) ;
return 0 ;
}
static int F_106 ( struct V_3 * V_4 )
{
struct V_9 * V_10 = & V_4 -> V_10 ;
struct V_18 * V_19 = & V_4 -> V_198 ;
struct V_232 V_233 = {} ;
int V_52 ;
V_4 -> V_45 = - 1 ;
V_10 -> V_20 = V_19 ;
V_10 -> V_234 = L_49 ;
V_10 -> V_235 = V_236 ;
V_19 -> V_20 = V_4 ;
V_19 -> V_184 = F_76 ;
V_19 -> V_237 = F_72 ;
V_19 -> V_238 = F_74 ;
V_19 -> V_178 = F_84 ;
V_19 -> V_177 = F_79 ;
V_19 -> V_187 = F_82 ;
V_19 -> V_239 = & V_240 ;
V_19 -> V_220 = F_93 ;
V_19 -> V_241 |= V_242 ;
if ( F_107 ( V_4 -> V_30 -> V_243 ) )
V_19 -> V_244 |= V_245 | V_246 ;
V_4 -> V_7 . V_36 = 1024 ;
V_4 -> V_7 . V_38 = 128 ;
V_52 = F_69 ( V_4 ) ;
if ( V_52 )
goto V_247;
V_52 = F_108 ( V_10 , 1 , NULL ) ;
if ( V_52 )
goto V_247;
V_52 = F_104 ( V_4 ) ;
if ( V_52 )
goto V_247;
V_52 = F_109 ( V_10 ) ;
if ( V_52 )
goto V_247;
V_233 . V_243 = V_4 -> V_81 -> V_30 . V_243 ;
V_52 = F_110 ( V_10 , NULL , & V_233 , NULL , 0 ) ;
if ( V_52 )
goto V_247;
return 0 ;
V_247:
F_102 ( V_4 ) ;
return V_52 ;
}
static int F_111 ( struct V_80 * V_81 )
{
struct V_3 * V_4 ;
const struct V_248 * V_249 ;
int V_52 ;
V_249 = F_112 ( V_250 , & V_81 -> V_30 ) ;
if ( V_249 ) {
V_81 -> V_251 = V_249 -> V_147 ;
} else {
F_20 ( L_50 ) ;
return - V_88 ;
}
V_4 = F_70 ( sizeof( * V_4 ) , V_141 ) ;
if ( ! V_4 ) {
F_20 ( L_51 ) ;
return - V_90 ;
}
F_113 ( V_81 , V_4 ) ;
V_4 -> V_81 = V_81 ;
V_4 -> V_30 = & V_81 -> V_30 ;
V_52 = F_53 ( V_4 ) ;
if ( V_52 )
goto V_252;
V_52 = F_55 ( V_4 ) ;
if ( V_52 )
goto V_253;
V_52 = F_106 ( V_4 ) ;
if ( V_52 )
goto V_253;
F_114 ( V_4 -> V_30 , L_52 ) ;
return 0 ;
V_253:
F_54 ( V_4 ) ;
V_252:
F_11 ( V_4 -> V_30 , L_53 , V_52 ) ;
F_68 ( V_4 ) ;
return V_52 ;
}
static int F_115 ( struct V_80 * V_81 )
{
struct V_3 * V_4 = F_116 ( V_81 ) ;
F_102 ( V_4 ) ;
F_54 ( V_4 ) ;
F_68 ( V_4 ) ;
return 0 ;
}
