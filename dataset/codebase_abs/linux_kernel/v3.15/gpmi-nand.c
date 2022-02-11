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
if ( F_16 ( V_4 -> V_30 -> V_43 , L_6 )
&& F_10 ( V_4 ) )
return 0 ;
return F_14 ( V_4 ) ;
}
struct V_44 * F_17 ( struct V_3 * V_4 )
{
return V_4 -> V_45 [ 0 ] ;
}
void F_18 ( struct V_3 * V_4 , enum V_46 V_47 )
{
struct V_48 * V_49 = & V_4 -> V_50 ;
int V_51 ;
if ( F_19 ( V_4 -> V_52 ) &&
! F_20 ( V_4 -> V_52 ) ) {
F_21 ( V_49 , V_4 -> V_52 , V_4 -> V_53 ) ;
V_51 = F_22 ( V_4 -> V_30 , V_49 , 1 , V_47 ) ;
if ( V_51 == 0 )
goto V_54;
V_4 -> V_55 = true ;
return;
}
V_54:
F_21 ( V_49 , V_4 -> V_56 , V_4 -> V_53 ) ;
if ( V_47 == V_57 )
memcpy ( V_4 -> V_56 , V_4 -> V_52 , V_4 -> V_53 ) ;
F_22 ( V_4 -> V_30 , V_49 , 1 , V_47 ) ;
V_4 -> V_55 = false ;
}
static void F_23 ( void * V_58 )
{
struct V_3 * V_4 = V_58 ;
struct V_59 * V_60 = & V_4 -> V_61 ;
switch ( V_4 -> V_62 ) {
case V_63 :
F_24 ( V_4 -> V_30 , & V_4 -> V_64 , 1 , V_57 ) ;
break;
case V_65 :
F_24 ( V_4 -> V_30 , & V_4 -> V_50 , 1 , V_66 ) ;
if ( V_4 -> V_55 == false )
memcpy ( V_4 -> V_52 , V_4 -> V_56 ,
V_4 -> V_53 ) ;
break;
case V_67 :
F_24 ( V_4 -> V_30 , & V_4 -> V_50 , 1 , V_57 ) ;
break;
case V_68 :
case V_69 :
break;
default:
F_11 ( V_4 -> V_30 , L_7 ) ;
}
F_3 ( V_60 ) ;
}
int F_25 ( struct V_3 * V_4 ,
struct V_70 * V_71 )
{
struct V_59 * V_60 = & V_4 -> V_61 ;
int V_72 ;
F_26 ( V_60 ) ;
V_71 -> V_73 = F_23 ;
V_71 -> V_74 = V_4 ;
F_27 ( V_71 ) ;
F_28 ( F_17 ( V_4 ) ) ;
V_72 = F_29 ( V_60 , F_30 ( 1000 ) ) ;
if ( ! V_72 ) {
F_11 ( V_4 -> V_30 , L_8 ,
V_4 -> V_75 ) ;
F_31 ( V_4 ) ;
return - V_76 ;
}
return 0 ;
}
int F_32 ( struct V_3 * V_4 ,
struct V_70 * V_71 )
{
struct V_59 * V_77 = & V_4 -> V_5 ;
int V_72 ;
F_26 ( V_77 ) ;
F_25 ( V_4 , V_71 ) ;
V_72 = F_29 ( V_77 , F_30 ( 1000 ) ) ;
if ( ! V_72 ) {
F_11 ( V_4 -> V_30 , L_9 ,
V_4 -> V_75 ) ;
F_31 ( V_4 ) ;
return - V_76 ;
}
return 0 ;
}
static int F_33 ( struct V_3 * V_4 ,
const char * V_78 )
{
struct V_79 * V_80 = V_4 -> V_80 ;
struct V_81 * V_82 = & V_4 -> V_81 ;
struct V_83 * V_84 ;
void T_2 * V_85 ;
V_84 = F_34 ( V_80 , V_86 , V_78 ) ;
V_85 = F_35 ( & V_80 -> V_30 , V_84 ) ;
if ( F_36 ( V_85 ) )
return F_37 ( V_85 ) ;
if ( ! strcmp ( V_78 , V_87 ) )
V_82 -> V_88 = V_85 ;
else if ( ! strcmp ( V_78 , V_89 ) )
V_82 -> V_90 = V_85 ;
else
F_11 ( V_4 -> V_30 , L_10 , V_78 ) ;
return 0 ;
}
static int F_38 ( struct V_3 * V_4 , T_3 V_91 )
{
struct V_79 * V_80 = V_4 -> V_80 ;
const char * V_78 = V_92 ;
struct V_83 * V_84 ;
int V_72 ;
V_84 = F_34 ( V_80 , V_93 , V_78 ) ;
if ( ! V_84 ) {
F_11 ( V_4 -> V_30 , L_11 , V_78 ) ;
return - V_94 ;
}
V_72 = F_39 ( V_4 -> V_30 , V_84 -> V_95 , V_91 , 0 , V_78 , V_4 ) ;
if ( V_72 )
F_11 ( V_4 -> V_30 , L_12 ) ;
return V_72 ;
}
static void F_40 ( struct V_3 * V_4 )
{
unsigned int V_96 ;
for ( V_96 = 0 ; V_96 < V_97 ; V_96 ++ )
if ( V_4 -> V_45 [ V_96 ] ) {
F_41 ( V_4 -> V_45 [ V_96 ] ) ;
V_4 -> V_45 [ V_96 ] = NULL ;
}
}
static int F_42 ( struct V_3 * V_4 )
{
struct V_79 * V_80 = V_4 -> V_80 ;
struct V_44 * V_44 ;
V_44 = F_43 ( & V_80 -> V_30 , L_13 ) ;
if ( ! V_44 ) {
F_11 ( V_4 -> V_30 , L_14 ) ;
goto V_98;
}
V_4 -> V_45 [ 0 ] = V_44 ;
return 0 ;
V_98:
F_40 ( V_4 ) ;
return - V_42 ;
}
static int F_44 ( struct V_3 * V_4 )
{
struct V_81 * V_84 = & V_4 -> V_81 ;
char * * V_99 = NULL ;
struct V_100 * V_100 ;
int V_72 , V_96 ;
V_84 -> clock [ 0 ] = F_45 ( V_4 -> V_30 , L_15 ) ;
if ( F_36 ( V_84 -> clock [ 0 ] ) ) {
V_72 = F_37 ( V_84 -> clock [ 0 ] ) ;
goto V_101;
}
if ( F_9 ( V_4 ) )
V_99 = V_102 ;
if ( ! V_99 )
return 0 ;
for ( V_96 = 1 ; V_96 < V_103 ; V_96 ++ ) {
if ( V_99 [ V_96 - 1 ] == NULL )
break;
V_100 = F_45 ( V_4 -> V_30 , V_99 [ V_96 - 1 ] ) ;
if ( F_36 ( V_100 ) ) {
V_72 = F_37 ( V_100 ) ;
goto V_101;
}
V_84 -> clock [ V_96 ] = V_100 ;
}
if ( F_9 ( V_4 ) )
F_46 ( V_84 -> clock [ 0 ] , 22000000 ) ;
return 0 ;
V_101:
F_47 ( V_4 -> V_30 , L_16 ) ;
return V_72 ;
}
static int F_48 ( struct V_3 * V_4 )
{
int V_51 ;
V_51 = F_33 ( V_4 , V_87 ) ;
if ( V_51 )
goto V_104;
V_51 = F_33 ( V_4 , V_89 ) ;
if ( V_51 )
goto V_104;
V_51 = F_38 ( V_4 , F_1 ) ;
if ( V_51 )
goto V_104;
V_51 = F_42 ( V_4 ) ;
if ( V_51 )
goto V_104;
V_51 = F_44 ( V_4 ) ;
if ( V_51 )
goto V_105;
return 0 ;
V_105:
F_40 ( V_4 ) ;
V_104:
return V_51 ;
}
static void F_49 ( struct V_3 * V_4 )
{
F_40 ( V_4 ) ;
}
static int F_50 ( struct V_3 * V_4 )
{
int V_51 ;
struct V_106 V_107 = {
. V_108 = 80 ,
. V_109 = 60 ,
. V_110 = 25 ,
. V_111 = 6 ,
. V_112 = - 1 ,
. V_113 = - 1 ,
. V_114 = - 1 ,
} ;
V_51 = F_51 ( V_4 ) ;
if ( V_51 )
return V_51 ;
V_4 -> V_115 = V_107 ;
return 0 ;
}
static int F_52 ( struct V_3 * V_4 ,
void * V_116 , unsigned V_35 ,
void * V_117 , T_4 V_118 , unsigned V_119 ,
void * * V_120 , T_4 * V_121 )
{
struct V_122 * V_30 = V_4 -> V_30 ;
if ( F_19 ( V_116 ) ) {
T_4 V_123 ;
V_123 = F_53 ( V_30 , V_116 ,
V_35 , V_66 ) ;
if ( F_54 ( V_30 , V_123 ) ) {
if ( V_119 < V_35 ) {
F_11 ( V_30 , L_17 ) ;
return - V_124 ;
}
goto V_125;
}
* V_120 = V_116 ;
* V_121 = V_123 ;
V_4 -> V_55 = true ;
return 0 ;
}
V_125:
* V_120 = V_117 ;
* V_121 = V_118 ;
V_4 -> V_55 = false ;
return 0 ;
}
static inline void F_55 ( struct V_3 * V_4 ,
void * V_116 , unsigned V_35 ,
void * V_117 , T_4 V_118 , unsigned V_119 ,
void * V_126 , T_4 V_127 )
{
if ( V_4 -> V_55 )
F_56 ( V_4 -> V_30 , V_127 , V_35 , V_66 ) ;
}
static inline void F_57 ( struct V_3 * V_4 ,
void * V_116 , unsigned V_35 ,
void * V_117 , T_4 V_118 , unsigned V_119 ,
void * V_126 , T_4 V_127 )
{
if ( ! V_4 -> V_55 )
memcpy ( V_116 , V_117 , V_35 ) ;
}
static int F_58 ( struct V_3 * V_4 ,
const void * V_128 , unsigned V_35 ,
void * V_117 , T_4 V_118 , unsigned V_119 ,
const void * * V_120 , T_4 * V_121 )
{
struct V_122 * V_30 = V_4 -> V_30 ;
if ( F_19 ( V_128 ) ) {
T_4 V_129 ;
V_129 = F_53 ( V_30 , ( void * ) V_128 , V_35 ,
V_57 ) ;
if ( F_54 ( V_30 , V_129 ) ) {
if ( V_119 < V_35 ) {
F_11 ( V_30 , L_17 ) ;
return - V_124 ;
}
goto V_125;
}
* V_120 = V_128 ;
* V_121 = V_129 ;
return 0 ;
}
V_125:
memcpy ( V_117 , V_128 , V_35 ) ;
* V_120 = V_117 ;
* V_121 = V_118 ;
return 0 ;
}
static void F_59 ( struct V_3 * V_4 ,
const void * V_128 , unsigned V_35 ,
void * V_117 , T_4 V_118 , unsigned V_119 ,
const void * V_126 , T_4 V_127 )
{
struct V_122 * V_30 = V_4 -> V_30 ;
if ( V_126 == V_128 )
F_56 ( V_30 , V_127 , V_35 , V_57 ) ;
}
static void F_60 ( struct V_3 * V_4 )
{
struct V_122 * V_30 = V_4 -> V_30 ;
if ( V_4 -> V_130 && F_19 ( V_4 -> V_130 ) )
F_61 ( V_30 , V_4 -> V_131 ,
V_4 -> V_130 ,
V_4 -> V_132 ) ;
F_62 ( V_4 -> V_133 ) ;
F_62 ( V_4 -> V_56 ) ;
V_4 -> V_133 = NULL ;
V_4 -> V_56 = NULL ;
V_4 -> V_130 = NULL ;
V_4 -> V_131 = 0 ;
}
static int F_63 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = & V_4 -> V_7 ;
struct V_122 * V_30 = V_4 -> V_30 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
V_4 -> V_133 = F_64 ( V_134 , V_135 | V_136 ) ;
if ( V_4 -> V_133 == NULL )
goto V_137;
V_4 -> V_56 = F_64 ( V_10 -> V_32 ? : V_134 ,
V_135 | V_136 ) ;
if ( V_4 -> V_56 == NULL )
goto V_137;
V_4 -> V_131 = V_8 -> V_36 + V_8 -> V_38 ;
V_4 -> V_130 = F_65 ( V_30 , V_4 -> V_131 ,
& V_4 -> V_132 , V_135 ) ;
if ( ! V_4 -> V_130 )
goto V_137;
V_4 -> V_138 = V_4 -> V_130 ;
V_4 -> V_139 = V_4 -> V_132 ;
V_4 -> V_140 = V_4 -> V_138 + V_8 -> V_36 ;
V_4 -> V_141 = V_4 -> V_139 + V_8 -> V_36 ;
return 0 ;
V_137:
F_60 ( V_4 ) ;
return - V_124 ;
}
static void F_66 ( struct V_9 * V_10 , int V_142 , unsigned int V_143 )
{
struct V_18 * V_19 = V_10 -> V_20 ;
struct V_3 * V_4 = V_19 -> V_20 ;
int V_51 ;
if ( ( V_143 & ( V_144 | V_145 ) ) ) {
if ( V_142 != V_146 )
V_4 -> V_133 [ V_4 -> V_147 ++ ] = V_142 ;
return;
}
if ( ! V_4 -> V_147 )
return;
V_51 = F_67 ( V_4 ) ;
if ( V_51 )
F_11 ( V_4 -> V_30 , L_18 ,
V_4 -> V_148 , V_51 ) ;
V_4 -> V_147 = 0 ;
}
static int F_68 ( struct V_9 * V_10 )
{
struct V_18 * V_19 = V_10 -> V_20 ;
struct V_3 * V_4 = V_19 -> V_20 ;
return F_69 ( V_4 , V_4 -> V_148 ) ;
}
static void F_70 ( struct V_9 * V_10 , int V_149 )
{
struct V_18 * V_19 = V_10 -> V_20 ;
struct V_3 * V_4 = V_19 -> V_20 ;
if ( ( V_4 -> V_148 < 0 ) && ( V_149 >= 0 ) )
F_71 ( V_4 ) ;
else if ( ( V_4 -> V_148 >= 0 ) && ( V_149 < 0 ) )
F_72 ( V_4 ) ;
V_4 -> V_148 = V_149 ;
}
static void F_73 ( struct V_9 * V_10 , T_5 * V_150 , int V_151 )
{
struct V_18 * V_19 = V_10 -> V_20 ;
struct V_3 * V_4 = V_19 -> V_20 ;
F_47 ( V_4 -> V_30 , L_19 , V_151 ) ;
V_4 -> V_52 = V_150 ;
V_4 -> V_53 = V_151 ;
F_74 ( V_4 ) ;
}
static void F_75 ( struct V_9 * V_10 , const T_5 * V_150 , int V_151 )
{
struct V_18 * V_19 = V_10 -> V_20 ;
struct V_3 * V_4 = V_19 -> V_20 ;
F_47 ( V_4 -> V_30 , L_19 , V_151 ) ;
V_4 -> V_52 = ( T_5 * ) V_150 ;
V_4 -> V_53 = V_151 ;
F_76 ( V_4 ) ;
}
static T_5 F_77 ( struct V_9 * V_10 )
{
struct V_18 * V_19 = V_10 -> V_20 ;
struct V_3 * V_4 = V_19 -> V_20 ;
T_5 * V_150 = V_4 -> V_56 ;
F_73 ( V_10 , V_150 , 1 ) ;
return V_150 [ 0 ] ;
}
static void F_78 ( struct V_3 * V_4 ,
void * V_152 , void * V_153 )
{
struct V_7 * V_154 = & V_4 -> V_7 ;
unsigned char * V_85 ;
unsigned char * V_155 ;
unsigned int V_156 ;
unsigned char V_157 ;
unsigned char V_158 ;
unsigned char V_159 ;
if ( ! V_4 -> V_39 )
return;
V_156 = V_154 -> V_25 ;
V_85 = V_152 + V_154 -> V_40 ;
V_155 = V_153 ;
V_158 = ( V_85 [ 0 ] >> V_156 ) | ( V_85 [ 1 ] << ( 8 - V_156 ) ) ;
V_159 = V_155 [ 0 ] ;
V_155 [ 0 ] = V_158 ;
V_157 = ( 0x1 << V_156 ) - 1 ;
V_85 [ 0 ] = ( V_85 [ 0 ] & V_157 ) | ( V_159 << V_156 ) ;
V_157 = ~ 0 << V_156 ;
V_85 [ 1 ] = ( V_85 [ 1 ] & V_157 ) | ( V_159 >> ( 8 - V_156 ) ) ;
}
static int F_79 ( struct V_9 * V_10 , struct V_18 * V_19 ,
T_5 * V_150 , int V_160 , int V_161 )
{
struct V_3 * V_4 = V_19 -> V_20 ;
struct V_7 * V_154 = & V_4 -> V_7 ;
void * V_138 ;
T_4 V_139 ;
void * V_140 ;
T_4 V_141 ;
unsigned int V_96 ;
unsigned char * V_162 ;
unsigned int V_163 = 0 ;
int V_51 ;
F_47 ( V_4 -> V_30 , L_20 , V_161 ) ;
V_51 = F_52 ( V_4 , V_150 , V_154 -> V_36 ,
V_4 -> V_138 , V_4 -> V_139 ,
V_154 -> V_36 ,
& V_138 , & V_139 ) ;
if ( V_51 ) {
F_11 ( V_4 -> V_30 , L_21 ) ;
V_51 = - V_124 ;
return V_51 ;
}
V_140 = V_4 -> V_140 ;
V_141 = V_4 -> V_141 ;
V_51 = F_80 ( V_4 , V_139 , V_141 ) ;
F_55 ( V_4 , V_150 , V_154 -> V_36 ,
V_4 -> V_138 , V_4 -> V_139 ,
V_154 -> V_36 ,
V_138 , V_139 ) ;
if ( V_51 ) {
F_11 ( V_4 -> V_30 , L_22 , V_51 ) ;
return V_51 ;
}
F_78 ( V_4 , V_138 , V_140 ) ;
V_162 = V_140 + V_154 -> V_37 ;
for ( V_96 = 0 ; V_96 < V_154 -> V_15 ; V_96 ++ , V_162 ++ ) {
if ( ( * V_162 == V_164 ) || ( * V_162 == V_165 ) )
continue;
if ( * V_162 == V_166 ) {
V_10 -> V_167 . V_168 ++ ;
continue;
}
V_10 -> V_167 . V_169 += * V_162 ;
V_163 = F_81 (unsigned int, max_bitflips, *status) ;
}
if ( V_160 ) {
memset ( V_19 -> V_170 , ~ 0 , V_10 -> V_12 ) ;
V_19 -> V_170 [ 0 ] = ( ( T_5 * ) V_140 ) [ 0 ] ;
}
F_57 ( V_4 , V_150 , V_154 -> V_36 ,
V_4 -> V_138 , V_4 -> V_139 ,
V_154 -> V_36 ,
V_138 , V_139 ) ;
return V_163 ;
}
static int F_82 ( struct V_9 * V_10 , struct V_18 * V_19 ,
T_6 V_171 , T_6 V_151 , T_5 * V_150 , int V_161 )
{
struct V_3 * V_4 = V_19 -> V_20 ;
void T_2 * V_90 = V_4 -> V_81 . V_90 ;
struct V_7 V_172 = V_4 -> V_7 ;
struct V_7 * V_8 = & V_4 -> V_7 ;
int V_173 = V_19 -> V_174 . V_173 ;
int V_175 , V_176 , V_33 ;
T_7 V_177 , V_178 , V_179 , V_180 ;
unsigned int V_163 ;
int V_181 , V_182 , V_183 ;
int V_184 ;
int V_185 = 0 ;
V_184 = V_8 -> V_14 * V_8 -> V_11 / 8 ;
V_181 = V_171 / V_173 ;
V_182 = ( V_171 + V_151 - 1 ) / V_173 ;
V_183 = V_8 -> V_40 / V_173 ;
if ( V_182 >= V_183 && V_181 <= V_183 ) {
F_47 ( V_4 -> V_30 , L_23 ,
V_161 , V_181 , V_182 , V_183 ) ;
return F_79 ( V_10 , V_19 , V_150 , 0 , V_161 ) ;
}
V_175 = V_8 -> V_13 ;
if ( V_181 ) {
V_185 = V_175 + ( V_173 + V_184 ) * V_181 ;
V_19 -> V_186 ( V_10 , V_187 , V_185 , - 1 ) ;
V_175 = 0 ;
V_150 = V_150 + V_181 * V_173 ;
}
V_177 = V_179 = F_83 ( V_90 + V_188 ) ;
V_178 = V_180 = F_83 ( V_90 + V_189 ) ;
V_176 = V_182 - V_181 + 1 ;
V_33 = V_175 + ( V_173 + V_184 ) * V_176 ;
V_179 &= ~ ( V_190 |
V_191 ) ;
V_179 |= F_84 ( V_176 - 1 )
| F_85 ( V_175 ) ;
F_86 ( V_179 , V_90 + V_188 ) ;
V_180 &= ~ V_192 ;
V_180 |= F_87 ( V_33 ) ;
F_86 ( V_180 , V_90 + V_189 ) ;
V_8 -> V_15 = V_176 ;
V_8 -> V_36 = V_176 * V_173 ;
V_8 -> V_33 = V_33 ;
V_8 -> V_37 = F_13 ( V_175 , 4 ) ;
F_47 ( V_4 -> V_30 , L_24 ,
V_161 , V_171 , V_151 , V_185 , V_181 , V_176 , V_33 ) ;
V_4 -> V_39 = false ;
V_163 = F_79 ( V_10 , V_19 , V_150 , 0 , V_161 ) ;
F_86 ( V_177 , V_90 + V_188 ) ;
F_86 ( V_178 , V_90 + V_189 ) ;
V_4 -> V_7 = V_172 ;
V_4 -> V_39 = true ;
return V_163 ;
}
static int F_88 ( struct V_9 * V_10 , struct V_18 * V_19 ,
const T_5 * V_150 , int V_160 )
{
struct V_3 * V_4 = V_19 -> V_20 ;
struct V_7 * V_154 = & V_4 -> V_7 ;
const void * V_138 ;
T_4 V_139 ;
const void * V_140 ;
T_4 V_141 ;
int V_51 ;
F_47 ( V_4 -> V_30 , L_25 ) ;
if ( V_4 -> V_39 ) {
memcpy ( V_4 -> V_138 , V_150 , V_10 -> V_32 ) ;
V_138 = V_4 -> V_138 ;
V_139 = V_4 -> V_139 ;
memcpy ( V_4 -> V_140 , V_19 -> V_170 ,
V_154 -> V_38 ) ;
V_140 = V_4 -> V_140 ;
V_141 = V_4 -> V_141 ;
F_78 ( V_4 ,
( void * ) V_138 , ( void * ) V_140 ) ;
} else {
V_51 = F_58 ( V_4 ,
V_150 , V_10 -> V_32 ,
V_4 -> V_138 , V_4 -> V_139 ,
V_154 -> V_36 ,
& V_138 , & V_139 ) ;
if ( V_51 ) {
F_11 ( V_4 -> V_30 , L_26 ) ;
return 0 ;
}
V_51 = F_58 ( V_4 ,
V_19 -> V_170 , V_10 -> V_12 ,
V_4 -> V_140 , V_4 -> V_141 ,
V_154 -> V_38 ,
& V_140 , & V_141 ) ;
if ( V_51 ) {
F_11 ( V_4 -> V_30 , L_27 ) ;
goto V_193;
}
}
V_51 = F_89 ( V_4 , V_139 , V_141 ) ;
if ( V_51 )
F_11 ( V_4 -> V_30 , L_28 , V_51 ) ;
if ( ! V_4 -> V_39 ) {
F_59 ( V_4 , V_19 -> V_170 , V_10 -> V_12 ,
V_4 -> V_140 , V_4 -> V_141 ,
V_154 -> V_38 ,
V_140 , V_141 ) ;
V_193:
F_59 ( V_4 , V_150 , V_10 -> V_32 ,
V_4 -> V_138 , V_4 -> V_139 ,
V_154 -> V_36 ,
V_138 , V_139 ) ;
}
return 0 ;
}
static int F_90 ( struct V_9 * V_10 , struct V_18 * V_19 ,
int V_161 )
{
struct V_3 * V_4 = V_19 -> V_20 ;
F_47 ( V_4 -> V_30 , L_29 , V_161 ) ;
memset ( V_19 -> V_170 , ~ 0 , V_10 -> V_12 ) ;
V_19 -> V_186 ( V_10 , V_194 , V_10 -> V_32 , V_161 ) ;
V_19 -> V_195 ( V_10 , V_19 -> V_170 , V_10 -> V_12 ) ;
if ( ! V_4 -> V_39 ) {
V_19 -> V_186 ( V_10 , V_194 , 0 , V_161 ) ;
V_19 -> V_170 [ 0 ] = V_19 -> V_196 ( V_10 ) ;
}
return 0 ;
}
static int
F_91 ( struct V_9 * V_10 , struct V_18 * V_19 , int V_161 )
{
struct V_21 * V_22 = V_10 -> V_197 -> V_24 ;
int V_162 = 0 ;
if ( ! V_22 -> V_35 )
return - V_198 ;
if ( ! F_92 ( V_19 ) )
return - V_198 ;
V_19 -> V_186 ( V_10 , V_199 , V_10 -> V_32 + V_22 -> V_34 , V_161 ) ;
V_19 -> V_200 ( V_10 , V_19 -> V_170 + V_22 -> V_34 , V_22 -> V_35 ) ;
V_19 -> V_186 ( V_10 , V_201 , - 1 , - 1 ) ;
V_162 = V_19 -> V_202 ( V_10 , V_19 ) ;
return V_162 & V_203 ? - V_204 : 0 ;
}
static int F_93 ( struct V_9 * V_10 , T_8 V_205 )
{
struct V_18 * V_19 = V_10 -> V_20 ;
struct V_3 * V_4 = V_19 -> V_20 ;
int V_51 = 0 ;
T_5 * V_206 ;
int V_207 , V_161 , V_162 , V_149 ;
V_149 = ( int ) ( V_205 >> V_19 -> V_208 ) ;
V_19 -> V_209 ( V_10 , V_149 ) ;
V_207 = V_4 -> V_39 ? V_10 -> V_32 : 0 ;
V_206 = V_4 -> V_56 ;
V_206 [ 0 ] = 0 ;
V_161 = ( int ) ( V_205 >> V_19 -> V_210 ) ;
V_19 -> V_186 ( V_10 , V_199 , V_207 , V_161 ) ;
V_19 -> V_200 ( V_10 , V_206 , 1 ) ;
V_19 -> V_186 ( V_10 , V_201 , - 1 , - 1 ) ;
V_162 = V_19 -> V_202 ( V_10 , V_19 ) ;
if ( V_162 & V_203 )
V_51 = - V_204 ;
V_19 -> V_209 ( V_10 , - 1 ) ;
return V_51 ;
}
static int F_94 ( struct V_3 * V_4 )
{
struct V_211 * V_212 = & V_4 -> V_213 ;
V_212 -> V_214 = 64 ;
V_212 -> V_215 = 2 ;
return 0 ;
}
static int F_95 ( struct V_3 * V_4 )
{
struct V_211 * V_216 = & V_4 -> V_213 ;
struct V_122 * V_30 = V_4 -> V_30 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
struct V_18 * V_19 = & V_4 -> V_217 ;
unsigned int V_218 ;
unsigned int V_219 ;
unsigned int V_161 ;
T_5 * V_220 = V_19 -> V_221 -> V_222 ;
int V_223 ;
int V_224 = false ;
V_218 = 1 << V_216 -> V_215 ;
V_223 = V_4 -> V_148 ;
V_19 -> V_209 ( V_10 , 0 ) ;
F_47 ( V_30 , L_30 ) ;
for ( V_219 = 0 ; V_219 < V_218 ; V_219 ++ ) {
V_161 = V_219 * V_216 -> V_214 ;
F_47 ( V_30 , L_31 , V_161 ) ;
V_19 -> V_186 ( V_10 , V_194 , 12 , V_161 ) ;
V_19 -> V_195 ( V_10 , V_220 , strlen ( V_225 ) ) ;
if ( ! memcmp ( V_220 , V_225 , strlen ( V_225 ) ) ) {
V_224 = true ;
break;
}
}
V_19 -> V_209 ( V_10 , V_223 ) ;
if ( V_224 )
F_47 ( V_30 , L_32 ) ;
else
F_47 ( V_30 , L_33 ) ;
return V_224 ;
}
static int F_96 ( struct V_3 * V_4 )
{
struct V_122 * V_30 = V_4 -> V_30 ;
struct V_211 * V_216 = & V_4 -> V_213 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
struct V_18 * V_19 = & V_4 -> V_217 ;
unsigned int V_226 ;
unsigned int V_218 ;
unsigned int V_227 ;
unsigned int V_228 ;
unsigned int V_229 ;
unsigned int V_219 ;
unsigned int V_161 ;
T_5 * V_220 = V_19 -> V_221 -> V_222 ;
int V_223 ;
int V_162 ;
V_226 = V_10 -> V_230 / V_10 -> V_32 ;
V_218 = 1 << V_216 -> V_215 ;
V_227 = V_218 *
V_216 -> V_214 ;
V_228 =
( V_227 + ( V_226 - 1 ) ) /
V_226 ;
F_47 ( V_30 , L_34 ) ;
F_47 ( V_30 , L_35 , V_228 ) ;
F_47 ( V_30 , L_36 , V_218 ) ;
F_47 ( V_30 , L_37 , V_227 ) ;
V_223 = V_4 -> V_148 ;
V_19 -> V_209 ( V_10 , 0 ) ;
F_47 ( V_30 , L_38 ) ;
for ( V_229 = 0 ; V_229 < V_228 ; V_229 ++ ) {
V_161 = V_229 * V_226 ;
F_47 ( V_30 , L_39 , V_229 ) ;
V_19 -> V_186 ( V_10 , V_231 , - 1 , V_161 ) ;
V_19 -> V_186 ( V_10 , V_232 , - 1 , - 1 ) ;
V_162 = V_19 -> V_202 ( V_10 , V_19 ) ;
if ( V_162 & V_203 )
F_11 ( V_30 , L_40 , V_233 ) ;
}
memset ( V_220 , ~ 0 , V_10 -> V_32 ) ;
memcpy ( V_220 + 12 , V_225 , strlen ( V_225 ) ) ;
F_47 ( V_30 , L_41 ) ;
for ( V_219 = 0 ; V_219 < V_218 ; V_219 ++ ) {
V_161 = V_219 * V_216 -> V_214 ;
F_47 ( V_30 , L_42 , V_161 ) ;
V_19 -> V_186 ( V_10 , V_199 , 0x00 , V_161 ) ;
V_19 -> V_174 . V_234 ( V_10 , V_19 , V_220 , 0 ) ;
V_19 -> V_186 ( V_10 , V_201 , - 1 , - 1 ) ;
V_162 = V_19 -> V_202 ( V_10 , V_19 ) ;
if ( V_162 & V_203 )
F_11 ( V_30 , L_43 , V_233 ) ;
}
V_19 -> V_209 ( V_10 , V_223 ) ;
return 0 ;
}
static int F_97 ( struct V_3 * V_4 )
{
struct V_122 * V_30 = V_4 -> V_30 ;
struct V_18 * V_19 = & V_4 -> V_217 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
unsigned int V_235 ;
unsigned int V_229 ;
int V_149 ;
int V_161 ;
T_8 V_236 ;
T_5 V_206 ;
int V_51 = 0 ;
if ( F_95 ( V_4 ) )
return 0 ;
F_47 ( V_30 , L_44 ) ;
V_235 = V_19 -> V_237 >> V_19 -> V_238 ;
for ( V_229 = 0 ; V_229 < V_235 ; V_229 ++ ) {
V_149 = V_229 >> ( V_19 -> V_208 - V_19 -> V_238 ) ;
V_161 = V_229 << ( V_19 -> V_238 - V_19 -> V_210 ) ;
V_236 = V_229 << V_19 -> V_238 ;
V_19 -> V_209 ( V_10 , V_149 ) ;
V_19 -> V_186 ( V_10 , V_194 , V_10 -> V_32 , V_161 ) ;
V_206 = V_19 -> V_196 ( V_10 ) ;
V_19 -> V_209 ( V_10 , - 1 ) ;
if ( V_206 != 0xff ) {
F_47 ( V_30 , L_45 , V_229 ) ;
V_51 = V_19 -> V_239 ( V_10 , V_236 ) ;
if ( V_51 )
F_11 ( V_30 , L_46
L_47 , V_51 ) ;
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
int V_51 ;
F_60 ( V_4 ) ;
V_51 = F_100 ( V_4 ) ;
if ( V_51 ) {
F_11 ( V_4 -> V_30 , L_48 , V_51 ) ;
return V_51 ;
}
return F_63 ( V_4 ) ;
}
static void F_101 ( struct V_3 * V_4 )
{
F_102 ( & V_4 -> V_10 ) ;
F_60 ( V_4 ) ;
}
static int F_103 ( struct V_3 * V_4 )
{
struct V_9 * V_10 = & V_4 -> V_10 ;
struct V_18 * V_19 = V_10 -> V_20 ;
struct V_240 * V_174 = & V_19 -> V_174 ;
struct V_7 * V_241 = & V_4 -> V_7 ;
int V_51 ;
V_4 -> V_39 = ! F_7 ( V_4 ) ;
V_51 = F_99 ( V_4 ) ;
if ( V_51 )
return V_51 ;
V_174 -> V_242 = F_79 ;
V_174 -> V_243 = F_88 ;
V_174 -> V_244 = F_90 ;
V_174 -> V_245 = F_91 ;
V_174 -> V_246 = V_247 ;
V_174 -> V_173 = V_241 -> V_31 ;
V_174 -> V_248 = V_241 -> V_11 ;
V_174 -> V_249 = & V_23 ;
if ( F_9 ( V_4 ) &&
( ( V_241 -> V_14 * V_241 -> V_11 ) % 8 ) == 0 ) {
V_174 -> V_250 = F_82 ;
V_19 -> V_251 |= V_252 ;
}
F_104 ( V_4 ) ;
return 0 ;
}
static int F_105 ( struct V_3 * V_4 )
{
struct V_9 * V_10 = & V_4 -> V_10 ;
struct V_18 * V_19 = & V_4 -> V_217 ;
struct V_253 V_254 = {} ;
int V_51 ;
V_4 -> V_148 = - 1 ;
V_10 -> V_20 = V_19 ;
V_10 -> V_255 = L_49 ;
V_10 -> V_256 = V_257 ;
V_19 -> V_20 = V_4 ;
V_19 -> V_209 = F_70 ;
V_19 -> V_258 = F_66 ;
V_19 -> V_259 = F_68 ;
V_19 -> V_196 = F_77 ;
V_19 -> V_195 = F_73 ;
V_19 -> V_200 = F_75 ;
V_19 -> V_260 = & V_261 ;
V_19 -> V_239 = F_93 ;
V_19 -> V_251 |= V_262 ;
if ( F_106 ( V_4 -> V_30 -> V_43 ) )
V_19 -> V_263 |= V_264 | V_265 ;
V_4 -> V_7 . V_36 = 1024 ;
V_4 -> V_7 . V_38 = 128 ;
V_51 = F_63 ( V_4 ) ;
if ( V_51 )
goto V_266;
V_51 = F_107 ( V_10 , F_9 ( V_4 ) ? 2 : 1 , NULL ) ;
if ( V_51 )
goto V_266;
V_51 = F_103 ( V_4 ) ;
if ( V_51 )
goto V_266;
V_19 -> V_251 |= V_267 ;
V_51 = F_108 ( V_10 ) ;
if ( V_51 )
goto V_266;
V_51 = F_98 ( V_4 ) ;
if ( V_51 )
goto V_266;
V_19 -> V_268 ( V_10 ) ;
V_254 . V_43 = V_4 -> V_80 -> V_30 . V_43 ;
V_51 = F_109 ( V_10 , NULL , & V_254 , NULL , 0 ) ;
if ( V_51 )
goto V_266;
return 0 ;
V_266:
F_101 ( V_4 ) ;
return V_51 ;
}
static int F_110 ( struct V_79 * V_80 )
{
struct V_3 * V_4 ;
const struct V_269 * V_270 ;
int V_51 ;
V_270 = F_111 ( V_271 , & V_80 -> V_30 ) ;
if ( V_270 ) {
V_80 -> V_272 = V_270 -> V_142 ;
} else {
F_11 ( & V_80 -> V_30 , L_50 ) ;
return - V_94 ;
}
V_4 = F_112 ( & V_80 -> V_30 , sizeof( * V_4 ) , V_136 ) ;
if ( ! V_4 )
return - V_124 ;
F_113 ( V_80 , V_4 ) ;
V_4 -> V_80 = V_80 ;
V_4 -> V_30 = & V_80 -> V_30 ;
V_51 = F_48 ( V_4 ) ;
if ( V_51 )
goto V_273;
V_51 = F_50 ( V_4 ) ;
if ( V_51 )
goto V_274;
V_51 = F_105 ( V_4 ) ;
if ( V_51 )
goto V_274;
F_114 ( V_4 -> V_30 , L_51 ) ;
return 0 ;
V_274:
F_49 ( V_4 ) ;
V_273:
F_11 ( V_4 -> V_30 , L_52 , V_51 ) ;
return V_51 ;
}
static int F_115 ( struct V_79 * V_80 )
{
struct V_3 * V_4 = F_116 ( V_80 ) ;
F_101 ( V_4 ) ;
F_49 ( V_4 ) ;
return 0 ;
}
