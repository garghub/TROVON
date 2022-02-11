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
}
return V_8 -> V_11 <= V_4 -> V_16 -> V_17 ;
}
static bool F_9 ( struct V_3 * V_4 )
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
F_10 ( V_4 -> V_30 ,
L_1 ,
V_19 -> V_26 , V_19 -> V_27 ) ;
return false ;
}
V_8 -> V_31 = V_19 -> V_27 ;
V_8 -> V_11 = F_11 ( V_19 -> V_26 , 2 ) ;
if ( ! F_6 ( V_4 ) )
return false ;
if ( V_8 -> V_31 < V_10 -> V_12 ) {
F_10 ( V_4 -> V_30 ,
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
V_8 -> V_37 = F_12 ( V_8 -> V_13 , 4 ) ;
V_8 -> V_38 = F_12 ( V_8 -> V_13 , 4 )
+ F_12 ( V_8 -> V_15 , 4 ) ;
if ( ! V_4 -> V_39 )
return true ;
V_25 = V_10 -> V_32 * 8 -
( V_8 -> V_11 * V_8 -> V_14 * ( V_8 -> V_15 - 1 )
+ V_8 -> V_13 * 8 ) ;
V_8 -> V_40 = V_25 / 8 ;
V_8 -> V_25 = V_25 % 8 ;
return true ;
}
static int F_13 ( struct V_3 * V_4 )
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
F_10 ( V_4 -> V_30 ,
L_3 ,
V_8 -> V_11 ,
V_4 -> V_16 -> V_17 ) ;
return - V_42 ;
}
V_8 -> V_33 = V_10 -> V_32 + V_10 -> V_12 ;
V_8 -> V_36 = V_10 -> V_32 ;
V_13 = F_12 ( V_8 -> V_13 , 4 ) ;
V_41 = F_12 ( V_8 -> V_15 , 4 ) ;
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
int F_14 ( struct V_3 * V_4 )
{
if ( F_15 ( V_4 -> V_30 -> V_43 , L_4 )
&& F_9 ( V_4 ) )
return 0 ;
return F_13 ( V_4 ) ;
}
struct V_44 * F_16 ( struct V_3 * V_4 )
{
return V_4 -> V_45 [ 0 ] ;
}
void F_17 ( struct V_3 * V_4 , enum V_46 V_47 )
{
struct V_48 * V_49 = & V_4 -> V_50 ;
int V_51 ;
if ( F_18 ( V_4 -> V_52 ) &&
! F_19 ( V_4 -> V_52 ) ) {
F_20 ( V_49 , V_4 -> V_52 , V_4 -> V_53 ) ;
V_51 = F_21 ( V_4 -> V_30 , V_49 , 1 , V_47 ) ;
if ( V_51 == 0 )
goto V_54;
V_4 -> V_55 = true ;
return;
}
V_54:
F_20 ( V_49 , V_4 -> V_56 , V_4 -> V_53 ) ;
if ( V_47 == V_57 )
memcpy ( V_4 -> V_56 , V_4 -> V_52 , V_4 -> V_53 ) ;
F_21 ( V_4 -> V_30 , V_49 , 1 , V_47 ) ;
V_4 -> V_55 = false ;
}
static void F_22 ( void * V_58 )
{
struct V_3 * V_4 = V_58 ;
struct V_59 * V_60 = & V_4 -> V_61 ;
switch ( V_4 -> V_62 ) {
case V_63 :
F_23 ( V_4 -> V_30 , & V_4 -> V_64 , 1 , V_57 ) ;
break;
case V_65 :
F_23 ( V_4 -> V_30 , & V_4 -> V_50 , 1 , V_66 ) ;
if ( V_4 -> V_55 == false )
memcpy ( V_4 -> V_52 , V_4 -> V_56 ,
V_4 -> V_53 ) ;
break;
case V_67 :
F_23 ( V_4 -> V_30 , & V_4 -> V_50 , 1 , V_57 ) ;
break;
case V_68 :
case V_69 :
break;
default:
F_10 ( V_4 -> V_30 , L_5 ) ;
}
F_3 ( V_60 ) ;
}
int F_24 ( struct V_3 * V_4 ,
struct V_70 * V_71 )
{
struct V_59 * V_60 = & V_4 -> V_61 ;
int V_72 ;
F_25 ( V_60 ) ;
V_71 -> V_73 = F_22 ;
V_71 -> V_74 = V_4 ;
F_26 ( V_71 ) ;
F_27 ( F_16 ( V_4 ) ) ;
V_72 = F_28 ( V_60 , F_29 ( 1000 ) ) ;
if ( ! V_72 ) {
F_10 ( V_4 -> V_30 , L_6 ,
V_4 -> V_75 ) ;
F_30 ( V_4 ) ;
return - V_76 ;
}
return 0 ;
}
int F_31 ( struct V_3 * V_4 ,
struct V_70 * V_71 )
{
struct V_59 * V_77 = & V_4 -> V_5 ;
int V_72 ;
F_25 ( V_77 ) ;
F_24 ( V_4 , V_71 ) ;
V_72 = F_28 ( V_77 , F_29 ( 1000 ) ) ;
if ( ! V_72 ) {
F_10 ( V_4 -> V_30 , L_7 ,
V_4 -> V_75 ) ;
F_30 ( V_4 ) ;
return - V_76 ;
}
return 0 ;
}
static int F_32 ( struct V_3 * V_4 ,
const char * V_78 )
{
struct V_79 * V_80 = V_4 -> V_80 ;
struct V_81 * V_82 = & V_4 -> V_81 ;
struct V_83 * V_84 ;
void T_2 * V_85 ;
V_84 = F_33 ( V_80 , V_86 , V_78 ) ;
V_85 = F_34 ( & V_80 -> V_30 , V_84 ) ;
if ( F_35 ( V_85 ) )
return F_36 ( V_85 ) ;
if ( ! strcmp ( V_78 , V_87 ) )
V_82 -> V_88 = V_85 ;
else if ( ! strcmp ( V_78 , V_89 ) )
V_82 -> V_90 = V_85 ;
else
F_10 ( V_4 -> V_30 , L_8 , V_78 ) ;
return 0 ;
}
static int F_37 ( struct V_3 * V_4 , T_3 V_91 )
{
struct V_79 * V_80 = V_4 -> V_80 ;
const char * V_78 = V_92 ;
struct V_83 * V_84 ;
int V_72 ;
V_84 = F_33 ( V_80 , V_93 , V_78 ) ;
if ( ! V_84 ) {
F_10 ( V_4 -> V_30 , L_9 , V_78 ) ;
return - V_94 ;
}
V_72 = F_38 ( V_4 -> V_30 , V_84 -> V_95 , V_91 , 0 , V_78 , V_4 ) ;
if ( V_72 )
F_10 ( V_4 -> V_30 , L_10 ) ;
return V_72 ;
}
static void F_39 ( struct V_3 * V_4 )
{
unsigned int V_96 ;
for ( V_96 = 0 ; V_96 < V_97 ; V_96 ++ )
if ( V_4 -> V_45 [ V_96 ] ) {
F_40 ( V_4 -> V_45 [ V_96 ] ) ;
V_4 -> V_45 [ V_96 ] = NULL ;
}
}
static int F_41 ( struct V_3 * V_4 )
{
struct V_79 * V_80 = V_4 -> V_80 ;
struct V_44 * V_44 ;
V_44 = F_42 ( & V_80 -> V_30 , L_11 ) ;
if ( ! V_44 ) {
F_10 ( V_4 -> V_30 , L_12 ) ;
goto V_98;
}
V_4 -> V_45 [ 0 ] = V_44 ;
return 0 ;
V_98:
F_39 ( V_4 ) ;
return - V_42 ;
}
static int F_43 ( struct V_3 * V_4 )
{
struct V_81 * V_84 = & V_4 -> V_81 ;
char * * V_99 = NULL ;
struct V_100 * V_100 ;
int V_72 , V_96 ;
V_84 -> clock [ 0 ] = F_44 ( V_4 -> V_30 , L_13 ) ;
if ( F_35 ( V_84 -> clock [ 0 ] ) ) {
V_72 = F_36 ( V_84 -> clock [ 0 ] ) ;
goto V_101;
}
if ( F_45 ( V_4 ) )
V_99 = V_102 ;
if ( ! V_99 )
return 0 ;
for ( V_96 = 1 ; V_96 < V_103 ; V_96 ++ ) {
if ( V_99 [ V_96 - 1 ] == NULL )
break;
V_100 = F_44 ( V_4 -> V_30 , V_99 [ V_96 - 1 ] ) ;
if ( F_35 ( V_100 ) ) {
V_72 = F_36 ( V_100 ) ;
goto V_101;
}
V_84 -> clock [ V_96 ] = V_100 ;
}
if ( F_45 ( V_4 ) )
F_46 ( V_84 -> clock [ 0 ] , 22000000 ) ;
return 0 ;
V_101:
F_47 ( V_4 -> V_30 , L_14 ) ;
return V_72 ;
}
static int F_48 ( struct V_3 * V_4 )
{
int V_51 ;
V_51 = F_32 ( V_4 , V_87 ) ;
if ( V_51 )
goto V_104;
V_51 = F_32 ( V_4 , V_89 ) ;
if ( V_51 )
goto V_104;
V_51 = F_37 ( V_4 , F_1 ) ;
if ( V_51 )
goto V_104;
V_51 = F_41 ( V_4 ) ;
if ( V_51 )
goto V_104;
V_51 = F_43 ( V_4 ) ;
if ( V_51 )
goto V_105;
return 0 ;
V_105:
F_39 ( V_4 ) ;
V_104:
return V_51 ;
}
static void F_49 ( struct V_3 * V_4 )
{
F_39 ( V_4 ) ;
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
if ( F_18 ( V_116 ) ) {
T_4 V_123 ;
V_123 = F_53 ( V_30 , V_116 ,
V_35 , V_66 ) ;
if ( F_54 ( V_30 , V_123 ) ) {
if ( V_119 < V_35 ) {
F_10 ( V_30 , L_15 ) ;
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
if ( F_18 ( V_128 ) ) {
T_4 V_129 ;
V_129 = F_53 ( V_30 , ( void * ) V_128 , V_35 ,
V_57 ) ;
if ( F_54 ( V_30 , V_129 ) ) {
if ( V_119 < V_35 ) {
F_10 ( V_30 , L_15 ) ;
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
if ( V_4 -> V_130 && F_18 ( V_4 -> V_130 ) )
F_61 ( V_30 , V_4 -> V_131 ,
V_4 -> V_130 ,
V_4 -> V_132 ) ;
F_62 ( V_4 -> V_133 ) ;
F_62 ( V_4 -> V_56 ) ;
F_62 ( V_4 -> V_134 ) ;
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
V_4 -> V_133 = F_64 ( V_135 , V_136 | V_137 ) ;
if ( V_4 -> V_133 == NULL )
goto V_138;
V_4 -> V_56 = F_64 ( V_10 -> V_32 ? : V_135 ,
V_136 | V_137 ) ;
if ( V_4 -> V_56 == NULL )
goto V_138;
V_4 -> V_131 = V_8 -> V_36 + V_8 -> V_38 ;
V_4 -> V_130 = F_65 ( V_30 , V_4 -> V_131 ,
& V_4 -> V_132 , V_136 ) ;
if ( ! V_4 -> V_130 )
goto V_138;
V_4 -> V_134 = F_64 ( V_10 -> V_32 + V_10 -> V_12 , V_137 ) ;
if ( ! V_4 -> V_134 )
goto V_138;
V_4 -> V_139 = V_4 -> V_130 ;
V_4 -> V_140 = V_4 -> V_132 ;
V_4 -> V_141 = V_4 -> V_139 + V_8 -> V_36 ;
V_4 -> V_142 = V_4 -> V_140 + V_8 -> V_36 ;
return 0 ;
V_138:
F_60 ( V_4 ) ;
return - V_124 ;
}
static void F_66 ( struct V_9 * V_10 , int V_143 , unsigned int V_144 )
{
struct V_18 * V_19 = V_10 -> V_20 ;
struct V_3 * V_4 = V_19 -> V_20 ;
int V_51 ;
if ( ( V_144 & ( V_145 | V_146 ) ) ) {
if ( V_143 != V_147 )
V_4 -> V_133 [ V_4 -> V_148 ++ ] = V_143 ;
return;
}
if ( ! V_4 -> V_148 )
return;
V_51 = F_67 ( V_4 ) ;
if ( V_51 )
F_10 ( V_4 -> V_30 , L_16 ,
V_4 -> V_149 , V_51 ) ;
V_4 -> V_148 = 0 ;
}
static int F_68 ( struct V_9 * V_10 )
{
struct V_18 * V_19 = V_10 -> V_20 ;
struct V_3 * V_4 = V_19 -> V_20 ;
return F_69 ( V_4 , V_4 -> V_149 ) ;
}
static void F_70 ( struct V_9 * V_10 , int V_150 )
{
struct V_18 * V_19 = V_10 -> V_20 ;
struct V_3 * V_4 = V_19 -> V_20 ;
if ( ( V_4 -> V_149 < 0 ) && ( V_150 >= 0 ) )
F_71 ( V_4 ) ;
else if ( ( V_4 -> V_149 >= 0 ) && ( V_150 < 0 ) )
F_72 ( V_4 ) ;
V_4 -> V_149 = V_150 ;
}
static void F_73 ( struct V_9 * V_10 , T_5 * V_151 , int V_152 )
{
struct V_18 * V_19 = V_10 -> V_20 ;
struct V_3 * V_4 = V_19 -> V_20 ;
F_47 ( V_4 -> V_30 , L_17 , V_152 ) ;
V_4 -> V_52 = V_151 ;
V_4 -> V_53 = V_152 ;
F_74 ( V_4 ) ;
}
static void F_75 ( struct V_9 * V_10 , const T_5 * V_151 , int V_152 )
{
struct V_18 * V_19 = V_10 -> V_20 ;
struct V_3 * V_4 = V_19 -> V_20 ;
F_47 ( V_4 -> V_30 , L_17 , V_152 ) ;
V_4 -> V_52 = ( T_5 * ) V_151 ;
V_4 -> V_53 = V_152 ;
F_76 ( V_4 ) ;
}
static T_5 F_77 ( struct V_9 * V_10 )
{
struct V_18 * V_19 = V_10 -> V_20 ;
struct V_3 * V_4 = V_19 -> V_20 ;
T_5 * V_151 = V_4 -> V_56 ;
F_73 ( V_10 , V_151 , 1 ) ;
return V_151 [ 0 ] ;
}
static void F_78 ( struct V_3 * V_4 ,
void * V_153 , void * V_154 )
{
struct V_7 * V_155 = & V_4 -> V_7 ;
unsigned char * V_85 ;
unsigned char * V_156 ;
unsigned int V_157 ;
unsigned char V_158 ;
unsigned char V_159 ;
unsigned char V_160 ;
if ( ! V_4 -> V_39 )
return;
V_157 = V_155 -> V_25 ;
V_85 = V_153 + V_155 -> V_40 ;
V_156 = V_154 ;
V_159 = ( V_85 [ 0 ] >> V_157 ) | ( V_85 [ 1 ] << ( 8 - V_157 ) ) ;
V_160 = V_156 [ 0 ] ;
V_156 [ 0 ] = V_159 ;
V_158 = ( 0x1 << V_157 ) - 1 ;
V_85 [ 0 ] = ( V_85 [ 0 ] & V_158 ) | ( V_160 << V_157 ) ;
V_158 = ~ 0 << V_157 ;
V_85 [ 1 ] = ( V_85 [ 1 ] & V_158 ) | ( V_160 >> ( 8 - V_157 ) ) ;
}
static int F_79 ( struct V_9 * V_10 , struct V_18 * V_19 ,
T_5 * V_151 , int V_161 , int V_162 )
{
struct V_3 * V_4 = V_19 -> V_20 ;
struct V_7 * V_155 = & V_4 -> V_7 ;
void * V_139 ;
T_4 V_140 ;
void * V_141 ;
T_4 V_142 ;
unsigned int V_96 ;
unsigned char * V_163 ;
unsigned int V_164 = 0 ;
int V_51 ;
F_47 ( V_4 -> V_30 , L_18 , V_162 ) ;
V_51 = F_52 ( V_4 , V_151 , V_155 -> V_36 ,
V_4 -> V_139 , V_4 -> V_140 ,
V_155 -> V_36 ,
& V_139 , & V_140 ) ;
if ( V_51 ) {
F_10 ( V_4 -> V_30 , L_19 ) ;
V_51 = - V_124 ;
return V_51 ;
}
V_141 = V_4 -> V_141 ;
V_142 = V_4 -> V_142 ;
V_51 = F_80 ( V_4 , V_140 , V_142 ) ;
F_55 ( V_4 , V_151 , V_155 -> V_36 ,
V_4 -> V_139 , V_4 -> V_140 ,
V_155 -> V_36 ,
V_139 , V_140 ) ;
if ( V_51 ) {
F_10 ( V_4 -> V_30 , L_20 , V_51 ) ;
return V_51 ;
}
F_78 ( V_4 , V_139 , V_141 ) ;
V_163 = V_141 + V_155 -> V_37 ;
for ( V_96 = 0 ; V_96 < V_155 -> V_15 ; V_96 ++ , V_163 ++ ) {
if ( ( * V_163 == V_165 ) || ( * V_163 == V_166 ) )
continue;
if ( * V_163 == V_167 ) {
V_10 -> V_168 . V_169 ++ ;
continue;
}
V_10 -> V_168 . V_170 += * V_163 ;
V_164 = F_81 (unsigned int, max_bitflips, *status) ;
}
if ( V_161 ) {
memset ( V_19 -> V_171 , ~ 0 , V_10 -> V_12 ) ;
V_19 -> V_171 [ 0 ] = ( ( T_5 * ) V_141 ) [ 0 ] ;
}
F_57 ( V_4 , V_151 , V_155 -> V_36 ,
V_4 -> V_139 , V_4 -> V_140 ,
V_155 -> V_36 ,
V_139 , V_140 ) ;
return V_164 ;
}
static int F_82 ( struct V_9 * V_10 , struct V_18 * V_19 ,
T_6 V_172 , T_6 V_152 , T_5 * V_151 , int V_162 )
{
struct V_3 * V_4 = V_19 -> V_20 ;
void T_2 * V_90 = V_4 -> V_81 . V_90 ;
struct V_7 V_173 = V_4 -> V_7 ;
struct V_7 * V_8 = & V_4 -> V_7 ;
int V_174 = V_19 -> V_175 . V_174 ;
int V_176 , V_177 , V_33 ;
T_7 V_178 , V_179 , V_180 , V_181 ;
unsigned int V_164 ;
int V_182 , V_183 , V_184 ;
int V_185 ;
int V_186 = 0 ;
int V_187 = V_4 -> V_39 ;
V_185 = V_8 -> V_14 * V_8 -> V_11 / 8 ;
V_182 = V_172 / V_174 ;
V_183 = ( V_172 + V_152 - 1 ) / V_174 ;
if ( V_4 -> V_39 ) {
V_184 = V_8 -> V_40 / V_174 ;
if ( V_183 >= V_184 && V_182 <= V_184 ) {
F_47 ( V_4 -> V_30 ,
L_21 ,
V_162 , V_182 , V_183 , V_184 ) ;
return F_79 ( V_10 , V_19 , V_151 , 0 , V_162 ) ;
}
}
V_176 = V_8 -> V_13 ;
if ( V_182 ) {
V_186 = V_176 + ( V_174 + V_185 ) * V_182 ;
V_19 -> V_188 ( V_10 , V_189 , V_186 , - 1 ) ;
V_176 = 0 ;
V_151 = V_151 + V_182 * V_174 ;
}
V_178 = V_180 = F_83 ( V_90 + V_190 ) ;
V_179 = V_181 = F_83 ( V_90 + V_191 ) ;
V_177 = V_183 - V_182 + 1 ;
V_33 = V_176 + ( V_174 + V_185 ) * V_177 ;
V_180 &= ~ ( V_192 |
V_193 ) ;
V_180 |= F_84 ( V_177 - 1 )
| F_85 ( V_176 ) ;
F_86 ( V_180 , V_90 + V_190 ) ;
V_181 &= ~ V_194 ;
V_181 |= F_87 ( V_33 ) ;
F_86 ( V_181 , V_90 + V_191 ) ;
V_8 -> V_15 = V_177 ;
V_8 -> V_36 = V_177 * V_174 ;
V_8 -> V_33 = V_33 ;
V_8 -> V_37 = F_12 ( V_176 , 4 ) ;
F_47 ( V_4 -> V_30 , L_22 ,
V_162 , V_172 , V_152 , V_186 , V_182 , V_177 , V_33 ) ;
V_4 -> V_39 = false ;
V_164 = F_79 ( V_10 , V_19 , V_151 , 0 , V_162 ) ;
F_86 ( V_178 , V_90 + V_190 ) ;
F_86 ( V_179 , V_90 + V_191 ) ;
V_4 -> V_7 = V_173 ;
V_4 -> V_39 = V_187 ;
return V_164 ;
}
static int F_88 ( struct V_9 * V_10 , struct V_18 * V_19 ,
const T_5 * V_151 , int V_161 )
{
struct V_3 * V_4 = V_19 -> V_20 ;
struct V_7 * V_155 = & V_4 -> V_7 ;
const void * V_139 ;
T_4 V_140 ;
const void * V_141 ;
T_4 V_142 ;
int V_51 ;
F_47 ( V_4 -> V_30 , L_23 ) ;
if ( V_4 -> V_39 ) {
memcpy ( V_4 -> V_139 , V_151 , V_10 -> V_32 ) ;
V_139 = V_4 -> V_139 ;
V_140 = V_4 -> V_140 ;
memcpy ( V_4 -> V_141 , V_19 -> V_171 ,
V_155 -> V_38 ) ;
V_141 = V_4 -> V_141 ;
V_142 = V_4 -> V_142 ;
F_78 ( V_4 ,
( void * ) V_139 , ( void * ) V_141 ) ;
} else {
V_51 = F_58 ( V_4 ,
V_151 , V_10 -> V_32 ,
V_4 -> V_139 , V_4 -> V_140 ,
V_155 -> V_36 ,
& V_139 , & V_140 ) ;
if ( V_51 ) {
F_10 ( V_4 -> V_30 , L_24 ) ;
return 0 ;
}
V_51 = F_58 ( V_4 ,
V_19 -> V_171 , V_10 -> V_12 ,
V_4 -> V_141 , V_4 -> V_142 ,
V_155 -> V_38 ,
& V_141 , & V_142 ) ;
if ( V_51 ) {
F_10 ( V_4 -> V_30 , L_25 ) ;
goto V_195;
}
}
V_51 = F_89 ( V_4 , V_140 , V_142 ) ;
if ( V_51 )
F_10 ( V_4 -> V_30 , L_26 , V_51 ) ;
if ( ! V_4 -> V_39 ) {
F_59 ( V_4 , V_19 -> V_171 , V_10 -> V_12 ,
V_4 -> V_141 , V_4 -> V_142 ,
V_155 -> V_38 ,
V_141 , V_142 ) ;
V_195:
F_59 ( V_4 , V_151 , V_10 -> V_32 ,
V_4 -> V_139 , V_4 -> V_140 ,
V_155 -> V_36 ,
V_139 , V_140 ) ;
}
return 0 ;
}
static int F_90 ( struct V_9 * V_10 , struct V_18 * V_19 ,
int V_162 )
{
struct V_3 * V_4 = V_19 -> V_20 ;
F_47 ( V_4 -> V_30 , L_27 , V_162 ) ;
memset ( V_19 -> V_171 , ~ 0 , V_10 -> V_12 ) ;
V_19 -> V_188 ( V_10 , V_196 , V_10 -> V_32 , V_162 ) ;
V_19 -> V_197 ( V_10 , V_19 -> V_171 , V_10 -> V_12 ) ;
if ( F_7 ( V_4 ) ) {
V_19 -> V_188 ( V_10 , V_196 , 0 , V_162 ) ;
V_19 -> V_171 [ 0 ] = V_19 -> V_198 ( V_10 ) ;
}
return 0 ;
}
static int
F_91 ( struct V_9 * V_10 , struct V_18 * V_19 , int V_162 )
{
struct V_21 * V_22 = V_10 -> V_199 -> V_24 ;
int V_163 = 0 ;
if ( ! V_22 -> V_35 )
return - V_200 ;
if ( ! F_92 ( V_19 ) )
return - V_200 ;
V_19 -> V_188 ( V_10 , V_201 , V_10 -> V_32 + V_22 -> V_34 , V_162 ) ;
V_19 -> V_202 ( V_10 , V_19 -> V_171 + V_22 -> V_34 , V_22 -> V_35 ) ;
V_19 -> V_188 ( V_10 , V_203 , - 1 , - 1 ) ;
V_163 = V_19 -> V_204 ( V_10 , V_19 ) ;
return V_163 & V_205 ? - V_206 : 0 ;
}
static int F_93 ( struct V_9 * V_10 ,
struct V_18 * V_19 , T_5 * V_151 ,
int V_161 , int V_162 )
{
struct V_3 * V_4 = V_19 -> V_20 ;
struct V_7 * V_155 = & V_4 -> V_7 ;
int V_207 = V_155 -> V_31 ;
int V_208 = V_155 -> V_11 * V_155 -> V_14 ;
T_8 * V_209 = V_4 -> V_134 ;
T_9 V_210 ;
T_9 V_211 ;
T_9 V_212 ;
T_5 * V_213 = V_19 -> V_171 ;
int V_214 ;
V_19 -> V_197 ( V_10 , V_209 ,
V_10 -> V_32 + V_10 -> V_12 ) ;
if ( V_4 -> V_39 ) {
T_8 V_215 = V_209 [ 0 ] ;
V_209 [ 0 ] = V_209 [ V_10 -> V_32 ] ;
V_209 [ V_10 -> V_32 ] = V_215 ;
}
if ( V_161 )
memcpy ( V_213 , V_209 , V_155 -> V_13 ) ;
V_211 = V_155 -> V_13 * 8 ;
V_210 = V_211 ;
for ( V_214 = 0 ; V_214 < V_155 -> V_15 ; V_214 ++ ) {
if ( V_151 )
F_94 ( V_151 , V_214 * V_207 * 8 ,
V_209 , V_210 ,
V_207 * 8 ) ;
V_210 += V_207 * 8 ;
if ( V_214 == V_155 -> V_15 - 1 &&
( V_211 + V_208 ) % 8 )
V_208 += 8 - ( ( V_211 + V_208 ) % 8 ) ;
if ( V_161 )
F_94 ( V_213 , V_211 ,
V_209 , V_210 ,
V_208 ) ;
V_210 += V_208 ;
V_211 += V_208 ;
}
if ( V_161 ) {
V_212 = V_211 / 8 ;
if ( V_212 < V_10 -> V_12 )
memcpy ( V_213 + V_212 ,
V_209 + V_10 -> V_32 + V_212 ,
V_10 -> V_12 - V_212 ) ;
}
return 0 ;
}
static int F_95 ( struct V_9 * V_10 ,
struct V_18 * V_19 ,
const T_5 * V_151 ,
int V_161 )
{
struct V_3 * V_4 = V_19 -> V_20 ;
struct V_7 * V_155 = & V_4 -> V_7 ;
int V_207 = V_155 -> V_31 ;
int V_208 = V_155 -> V_11 * V_155 -> V_14 ;
T_8 * V_209 = V_4 -> V_134 ;
T_5 * V_213 = V_19 -> V_171 ;
T_9 V_216 ;
T_9 V_211 ;
T_9 V_212 ;
int V_214 ;
if ( ! V_151 || ! V_161 )
memset ( V_209 , 0xff , V_10 -> V_32 + V_10 -> V_12 ) ;
memcpy ( V_209 , V_213 , V_155 -> V_13 ) ;
V_211 = V_155 -> V_13 * 8 ;
V_216 = V_211 ;
for ( V_214 = 0 ; V_214 < V_155 -> V_15 ; V_214 ++ ) {
if ( V_151 )
F_94 ( V_209 , V_216 ,
V_151 , V_214 * V_207 * 8 , V_207 * 8 ) ;
V_216 += V_207 * 8 ;
if ( V_214 == V_155 -> V_15 - 1 &&
( V_211 + V_208 ) % 8 )
V_208 += 8 - ( ( V_211 + V_208 ) % 8 ) ;
if ( V_161 )
F_94 ( V_209 , V_216 ,
V_213 , V_211 , V_208 ) ;
V_216 += V_208 ;
V_211 += V_208 ;
}
V_212 = V_211 / 8 ;
if ( V_161 && V_212 < V_10 -> V_12 )
memcpy ( V_209 + V_10 -> V_32 + V_212 ,
V_213 + V_212 , V_10 -> V_12 - V_212 ) ;
if ( V_4 -> V_39 ) {
T_8 V_215 = V_209 [ 0 ] ;
V_209 [ 0 ] = V_209 [ V_10 -> V_32 ] ;
V_209 [ V_10 -> V_32 ] = V_215 ;
}
V_19 -> V_202 ( V_10 , V_209 , V_10 -> V_32 + V_10 -> V_12 ) ;
return 0 ;
}
static int F_96 ( struct V_9 * V_10 , struct V_18 * V_19 ,
int V_162 )
{
V_19 -> V_188 ( V_10 , V_196 , 0 , V_162 ) ;
return F_93 ( V_10 , V_19 , NULL , 1 , V_162 ) ;
}
static int F_97 ( struct V_9 * V_10 , struct V_18 * V_19 ,
int V_162 )
{
V_19 -> V_188 ( V_10 , V_201 , 0 , V_162 ) ;
return F_95 ( V_10 , V_19 , NULL , 1 ) ;
}
static int F_98 ( struct V_9 * V_10 , T_10 V_217 )
{
struct V_18 * V_19 = V_10 -> V_20 ;
struct V_3 * V_4 = V_19 -> V_20 ;
int V_51 = 0 ;
T_5 * V_218 ;
int V_219 , V_162 , V_163 , V_150 ;
V_150 = ( int ) ( V_217 >> V_19 -> V_220 ) ;
V_19 -> V_221 ( V_10 , V_150 ) ;
V_219 = ! F_7 ( V_4 ) ? V_10 -> V_32 : 0 ;
V_218 = V_4 -> V_56 ;
V_218 [ 0 ] = 0 ;
V_162 = ( int ) ( V_217 >> V_19 -> V_222 ) ;
V_19 -> V_188 ( V_10 , V_201 , V_219 , V_162 ) ;
V_19 -> V_202 ( V_10 , V_218 , 1 ) ;
V_19 -> V_188 ( V_10 , V_203 , - 1 , - 1 ) ;
V_163 = V_19 -> V_204 ( V_10 , V_19 ) ;
if ( V_163 & V_205 )
V_51 = - V_206 ;
V_19 -> V_221 ( V_10 , - 1 ) ;
return V_51 ;
}
static int F_99 ( struct V_3 * V_4 )
{
struct V_223 * V_224 = & V_4 -> V_225 ;
V_224 -> V_226 = 64 ;
V_224 -> V_227 = 2 ;
return 0 ;
}
static int F_100 ( struct V_3 * V_4 )
{
struct V_223 * V_228 = & V_4 -> V_225 ;
struct V_122 * V_30 = V_4 -> V_30 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
struct V_18 * V_19 = & V_4 -> V_229 ;
unsigned int V_230 ;
unsigned int V_231 ;
unsigned int V_162 ;
T_5 * V_232 = V_19 -> V_233 -> V_234 ;
int V_235 ;
int V_236 = false ;
V_230 = 1 << V_228 -> V_227 ;
V_235 = V_4 -> V_149 ;
V_19 -> V_221 ( V_10 , 0 ) ;
F_47 ( V_30 , L_28 ) ;
for ( V_231 = 0 ; V_231 < V_230 ; V_231 ++ ) {
V_162 = V_231 * V_228 -> V_226 ;
F_47 ( V_30 , L_29 , V_162 ) ;
V_19 -> V_188 ( V_10 , V_196 , 12 , V_162 ) ;
V_19 -> V_197 ( V_10 , V_232 , strlen ( V_237 ) ) ;
if ( ! memcmp ( V_232 , V_237 , strlen ( V_237 ) ) ) {
V_236 = true ;
break;
}
}
V_19 -> V_221 ( V_10 , V_235 ) ;
if ( V_236 )
F_47 ( V_30 , L_30 ) ;
else
F_47 ( V_30 , L_31 ) ;
return V_236 ;
}
static int F_101 ( struct V_3 * V_4 )
{
struct V_122 * V_30 = V_4 -> V_30 ;
struct V_223 * V_228 = & V_4 -> V_225 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
struct V_18 * V_19 = & V_4 -> V_229 ;
unsigned int V_238 ;
unsigned int V_230 ;
unsigned int V_239 ;
unsigned int V_240 ;
unsigned int V_241 ;
unsigned int V_231 ;
unsigned int V_162 ;
T_5 * V_232 = V_19 -> V_233 -> V_234 ;
int V_235 ;
int V_163 ;
V_238 = V_10 -> V_242 / V_10 -> V_32 ;
V_230 = 1 << V_228 -> V_227 ;
V_239 = V_230 *
V_228 -> V_226 ;
V_240 =
( V_239 + ( V_238 - 1 ) ) /
V_238 ;
F_47 ( V_30 , L_32 ) ;
F_47 ( V_30 , L_33 , V_240 ) ;
F_47 ( V_30 , L_34 , V_230 ) ;
F_47 ( V_30 , L_35 , V_239 ) ;
V_235 = V_4 -> V_149 ;
V_19 -> V_221 ( V_10 , 0 ) ;
F_47 ( V_30 , L_36 ) ;
for ( V_241 = 0 ; V_241 < V_240 ; V_241 ++ ) {
V_162 = V_241 * V_238 ;
F_47 ( V_30 , L_37 , V_241 ) ;
V_19 -> V_188 ( V_10 , V_243 , - 1 , V_162 ) ;
V_19 -> V_188 ( V_10 , V_244 , - 1 , - 1 ) ;
V_163 = V_19 -> V_204 ( V_10 , V_19 ) ;
if ( V_163 & V_205 )
F_10 ( V_30 , L_38 , V_245 ) ;
}
memset ( V_232 , ~ 0 , V_10 -> V_32 ) ;
memcpy ( V_232 + 12 , V_237 , strlen ( V_237 ) ) ;
F_47 ( V_30 , L_39 ) ;
for ( V_231 = 0 ; V_231 < V_230 ; V_231 ++ ) {
V_162 = V_231 * V_228 -> V_226 ;
F_47 ( V_30 , L_40 , V_162 ) ;
V_19 -> V_188 ( V_10 , V_201 , 0x00 , V_162 ) ;
V_19 -> V_175 . V_246 ( V_10 , V_19 , V_232 , 0 ) ;
V_19 -> V_188 ( V_10 , V_203 , - 1 , - 1 ) ;
V_163 = V_19 -> V_204 ( V_10 , V_19 ) ;
if ( V_163 & V_205 )
F_10 ( V_30 , L_41 , V_245 ) ;
}
V_19 -> V_221 ( V_10 , V_235 ) ;
return 0 ;
}
static int F_102 ( struct V_3 * V_4 )
{
struct V_122 * V_30 = V_4 -> V_30 ;
struct V_18 * V_19 = & V_4 -> V_229 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
unsigned int V_247 ;
unsigned int V_241 ;
int V_150 ;
int V_162 ;
T_10 V_248 ;
T_5 V_218 ;
int V_51 = 0 ;
if ( F_100 ( V_4 ) )
return 0 ;
F_47 ( V_30 , L_42 ) ;
V_247 = V_19 -> V_249 >> V_19 -> V_250 ;
for ( V_241 = 0 ; V_241 < V_247 ; V_241 ++ ) {
V_150 = V_241 >> ( V_19 -> V_220 - V_19 -> V_250 ) ;
V_162 = V_241 << ( V_19 -> V_250 - V_19 -> V_222 ) ;
V_248 = V_241 << V_19 -> V_250 ;
V_19 -> V_221 ( V_10 , V_150 ) ;
V_19 -> V_188 ( V_10 , V_196 , V_10 -> V_32 , V_162 ) ;
V_218 = V_19 -> V_198 ( V_10 ) ;
V_19 -> V_221 ( V_10 , - 1 ) ;
if ( V_218 != 0xff ) {
F_47 ( V_30 , L_43 , V_241 ) ;
V_51 = V_19 -> V_251 ( V_10 , V_248 ) ;
if ( V_51 )
F_10 ( V_30 ,
L_44 ,
V_51 ) ;
}
}
F_101 ( V_4 ) ;
return 0 ;
}
static int F_103 ( struct V_3 * V_4 )
{
F_99 ( V_4 ) ;
if ( F_7 ( V_4 ) )
return F_102 ( V_4 ) ;
return 0 ;
}
static int F_104 ( struct V_3 * V_4 )
{
int V_51 ;
F_60 ( V_4 ) ;
V_51 = F_105 ( V_4 ) ;
if ( V_51 ) {
F_10 ( V_4 -> V_30 , L_45 , V_51 ) ;
return V_51 ;
}
return F_63 ( V_4 ) ;
}
static void F_106 ( struct V_3 * V_4 )
{
F_107 ( & V_4 -> V_10 ) ;
F_60 ( V_4 ) ;
}
static int F_108 ( struct V_3 * V_4 )
{
struct V_9 * V_10 = & V_4 -> V_10 ;
struct V_18 * V_19 = V_10 -> V_20 ;
struct V_252 * V_175 = & V_19 -> V_175 ;
struct V_7 * V_253 = & V_4 -> V_7 ;
int V_51 ;
V_51 = F_104 ( V_4 ) ;
if ( V_51 )
return V_51 ;
V_175 -> V_254 = F_79 ;
V_175 -> V_255 = F_88 ;
V_175 -> V_256 = F_90 ;
V_175 -> V_257 = F_91 ;
V_175 -> V_258 = F_93 ;
V_175 -> V_246 = F_95 ;
V_175 -> V_259 = F_96 ;
V_175 -> V_260 = F_97 ;
V_175 -> V_261 = V_262 ;
V_175 -> V_174 = V_253 -> V_31 ;
V_175 -> V_263 = V_253 -> V_11 ;
V_175 -> V_264 = & V_23 ;
if ( F_45 ( V_4 ) &&
( ( V_253 -> V_14 * V_253 -> V_11 ) % 8 ) == 0 ) {
V_175 -> V_265 = F_82 ;
V_19 -> V_266 |= V_267 ;
}
F_109 ( V_4 ) ;
return 0 ;
}
static int F_110 ( struct V_3 * V_4 )
{
struct V_9 * V_10 = & V_4 -> V_10 ;
struct V_18 * V_19 = & V_4 -> V_229 ;
struct V_268 V_269 = {} ;
int V_51 ;
V_4 -> V_149 = - 1 ;
V_10 -> V_20 = V_19 ;
V_10 -> V_270 = L_46 ;
V_10 -> V_271 = V_272 ;
V_19 -> V_20 = V_4 ;
V_19 -> V_221 = F_70 ;
V_19 -> V_273 = F_66 ;
V_19 -> V_274 = F_68 ;
V_19 -> V_198 = F_77 ;
V_19 -> V_197 = F_73 ;
V_19 -> V_202 = F_75 ;
V_19 -> V_275 = & V_276 ;
V_19 -> V_251 = F_98 ;
V_19 -> V_266 |= V_277 ;
V_4 -> V_39 = ! F_7 ( V_4 ) ;
if ( F_111 ( V_4 -> V_30 -> V_43 ) ) {
V_19 -> V_278 |= V_279 | V_280 ;
if ( F_15 ( V_4 -> V_30 -> V_43 ,
L_47 ) )
V_4 -> V_39 = false ;
}
F_47 ( V_4 -> V_30 , L_48 ,
V_4 -> V_39 ? L_49 : L_50 ) ;
V_4 -> V_7 . V_36 = 1024 ;
V_4 -> V_7 . V_38 = 128 ;
V_51 = F_63 ( V_4 ) ;
if ( V_51 )
goto V_281;
V_51 = F_112 ( V_10 , F_45 ( V_4 ) ? 2 : 1 , NULL ) ;
if ( V_51 )
goto V_281;
V_51 = F_108 ( V_4 ) ;
if ( V_51 )
goto V_281;
V_19 -> V_266 |= V_282 ;
V_51 = F_113 ( V_10 ) ;
if ( V_51 )
goto V_281;
V_51 = F_103 ( V_4 ) ;
if ( V_51 )
goto V_281;
V_19 -> V_283 ( V_10 ) ;
V_269 . V_43 = V_4 -> V_80 -> V_30 . V_43 ;
V_51 = F_114 ( V_10 , NULL , & V_269 , NULL , 0 ) ;
if ( V_51 )
goto V_281;
return 0 ;
V_281:
F_106 ( V_4 ) ;
return V_51 ;
}
static int F_115 ( struct V_79 * V_80 )
{
struct V_3 * V_4 ;
const struct V_284 * V_285 ;
int V_51 ;
V_4 = F_116 ( & V_80 -> V_30 , sizeof( * V_4 ) , V_137 ) ;
if ( ! V_4 )
return - V_124 ;
V_285 = F_117 ( V_286 , & V_80 -> V_30 ) ;
if ( V_285 ) {
V_4 -> V_16 = V_285 -> V_143 ;
} else {
F_10 ( & V_80 -> V_30 , L_51 ) ;
return - V_94 ;
}
F_118 ( V_80 , V_4 ) ;
V_4 -> V_80 = V_80 ;
V_4 -> V_30 = & V_80 -> V_30 ;
V_51 = F_48 ( V_4 ) ;
if ( V_51 )
goto V_287;
V_51 = F_50 ( V_4 ) ;
if ( V_51 )
goto V_288;
V_51 = F_110 ( V_4 ) ;
if ( V_51 )
goto V_288;
F_119 ( V_4 -> V_30 , L_52 ) ;
return 0 ;
V_288:
F_49 ( V_4 ) ;
V_287:
return V_51 ;
}
static int F_120 ( struct V_79 * V_80 )
{
struct V_3 * V_4 = F_121 ( V_80 ) ;
F_106 ( V_4 ) ;
F_49 ( V_4 ) ;
return 0 ;
}
