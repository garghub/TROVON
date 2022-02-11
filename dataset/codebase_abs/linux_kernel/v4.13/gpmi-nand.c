static int F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = & V_9 -> V_10 ;
if ( V_3 )
return - V_12 ;
V_5 -> V_13 = 0 ;
V_5 -> V_14 = V_11 -> V_15 - V_2 -> V_16 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = & V_9 -> V_10 ;
if ( V_3 )
return - V_12 ;
if ( V_11 -> V_15 < V_2 -> V_16 + V_2 -> V_17 ) {
V_5 -> V_13 = V_11 -> V_15 - V_2 -> V_16 ;
V_5 -> V_14 = V_2 -> V_17 - V_5 -> V_13 ;
}
return 0 ;
}
static T_1 F_5 ( int V_18 , void * V_19 )
{
struct V_8 * V_9 = V_19 ;
F_6 ( V_9 ) ;
F_7 ( & V_9 -> V_20 ) ;
return V_21 ;
}
static inline int F_8 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_10 ;
struct V_1 * V_2 = F_9 ( & V_9 -> V_22 ) ;
int V_23 ;
V_23 = ( ( V_2 -> V_17 - V_11 -> V_24 ) * 8 )
/ ( V_11 -> V_25 * V_11 -> V_26 ) ;
return F_10 ( V_23 , 2 ) ;
}
static inline bool F_11 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_10 ;
if ( F_12 ( V_9 ) || F_13 ( V_9 ) ) {
if ( V_11 -> V_25 == 14 )
return false ;
}
return V_11 -> V_23 <= V_9 -> V_27 -> V_28 ;
}
static int F_14 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_10 ;
struct V_6 * V_7 = & V_9 -> V_22 ;
struct V_1 * V_2 = F_9 ( V_7 ) ;
unsigned int V_29 ;
if ( ! ( V_7 -> V_30 > 0 && V_7 -> V_31 > 0 ) )
return - V_32 ;
switch ( V_7 -> V_31 ) {
case V_33 :
V_11 -> V_25 = 13 ;
break;
case V_34 :
V_11 -> V_25 = 14 ;
break;
default:
F_15 ( V_9 -> V_35 ,
L_1 ,
V_7 -> V_30 , V_7 -> V_31 ) ;
return - V_32 ;
}
V_11 -> V_36 = V_7 -> V_31 ;
V_11 -> V_23 = F_16 ( V_7 -> V_30 , 2 ) ;
if ( ! F_11 ( V_9 ) )
return - V_32 ;
if ( V_11 -> V_36 < V_2 -> V_17 ) {
F_15 ( V_9 -> V_35 ,
L_2 ,
V_7 -> V_31 , V_2 -> V_17 ) ;
return - V_32 ;
}
V_11 -> V_24 = 10 ;
V_11 -> V_26 = V_2 -> V_16 / V_11 -> V_36 ;
V_11 -> V_15 = V_2 -> V_16 + V_11 -> V_24 +
( V_11 -> V_25 * V_11 -> V_23 * V_11 -> V_26 ) / 8 ;
V_11 -> V_37 = V_2 -> V_16 ;
V_11 -> V_38 = F_17 ( V_11 -> V_24 , 4 ) ;
V_11 -> V_39 = F_17 ( V_11 -> V_24 , 4 )
+ F_17 ( V_11 -> V_26 , 4 ) ;
if ( ! V_9 -> V_40 )
return 0 ;
V_29 = V_2 -> V_16 * 8 -
( V_11 -> V_23 * V_11 -> V_25 * ( V_11 -> V_26 - 1 )
+ V_11 -> V_24 * 8 ) ;
V_11 -> V_41 = V_29 / 8 ;
V_11 -> V_29 = V_29 % 8 ;
return 0 ;
}
static int F_18 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_10 ;
struct V_1 * V_2 = F_9 ( & V_9 -> V_22 ) ;
unsigned int V_24 ;
unsigned int V_42 ;
unsigned int V_29 ;
V_11 -> V_24 = 10 ;
V_11 -> V_25 = 13 ;
V_11 -> V_36 = 512 ;
while ( V_11 -> V_36 < V_2 -> V_17 ) {
V_11 -> V_36 *= 2 ;
V_11 -> V_25 = 14 ;
}
V_11 -> V_26 = V_2 -> V_16 / V_11 -> V_36 ;
V_11 -> V_23 = F_8 ( V_9 ) ;
if ( ! F_11 ( V_9 ) ) {
F_15 ( V_9 -> V_35 ,
L_3
L_4 ,
V_11 -> V_23 ,
V_9 -> V_27 -> V_28 ) ;
return - V_32 ;
}
V_11 -> V_15 = V_2 -> V_16 + V_11 -> V_24 +
( V_11 -> V_25 * V_11 -> V_23 * V_11 -> V_26 ) / 8 ;
V_11 -> V_37 = V_2 -> V_16 ;
V_24 = F_17 ( V_11 -> V_24 , 4 ) ;
V_42 = F_17 ( V_11 -> V_26 , 4 ) ;
V_11 -> V_39 = V_24 + V_42 ;
V_11 -> V_38 = V_24 ;
if ( ! V_9 -> V_40 )
return 0 ;
V_29 = V_2 -> V_16 * 8 -
( V_11 -> V_23 * V_11 -> V_25 * ( V_11 -> V_26 - 1 )
+ V_11 -> V_24 * 8 ) ;
V_11 -> V_41 = V_29 / 8 ;
V_11 -> V_29 = V_29 % 8 ;
return 0 ;
}
int F_19 ( struct V_8 * V_9 )
{
if ( ( F_20 ( V_9 -> V_35 -> V_43 , L_5 ) )
|| F_18 ( V_9 ) )
return F_14 ( V_9 ) ;
return 0 ;
}
struct V_44 * F_21 ( struct V_8 * V_9 )
{
return V_9 -> V_45 [ 0 ] ;
}
void F_22 ( struct V_8 * V_9 , enum V_46 V_47 )
{
struct V_48 * V_49 = & V_9 -> V_50 ;
int V_51 ;
if ( F_23 ( V_9 -> V_52 ) &&
! F_24 ( V_9 -> V_52 ) ) {
F_25 ( V_49 , V_9 -> V_52 , V_9 -> V_53 ) ;
V_51 = F_26 ( V_9 -> V_35 , V_49 , 1 , V_47 ) ;
if ( V_51 == 0 )
goto V_54;
V_9 -> V_55 = true ;
return;
}
V_54:
F_25 ( V_49 , V_9 -> V_56 , V_9 -> V_53 ) ;
if ( V_47 == V_57 )
memcpy ( V_9 -> V_56 , V_9 -> V_52 , V_9 -> V_53 ) ;
F_26 ( V_9 -> V_35 , V_49 , 1 , V_47 ) ;
V_9 -> V_55 = false ;
}
static void F_27 ( void * V_58 )
{
struct V_8 * V_9 = V_58 ;
struct V_59 * V_60 = & V_9 -> V_61 ;
switch ( V_9 -> V_62 ) {
case V_63 :
F_28 ( V_9 -> V_35 , & V_9 -> V_64 , 1 , V_57 ) ;
break;
case V_65 :
F_28 ( V_9 -> V_35 , & V_9 -> V_50 , 1 , V_66 ) ;
if ( V_9 -> V_55 == false )
memcpy ( V_9 -> V_52 , V_9 -> V_56 ,
V_9 -> V_53 ) ;
break;
case V_67 :
F_28 ( V_9 -> V_35 , & V_9 -> V_50 , 1 , V_57 ) ;
break;
case V_68 :
case V_69 :
break;
default:
F_15 ( V_9 -> V_35 , L_6 ) ;
}
F_7 ( V_60 ) ;
}
int F_29 ( struct V_8 * V_9 ,
struct V_70 * V_71 )
{
struct V_59 * V_60 = & V_9 -> V_61 ;
unsigned long V_72 ;
F_30 ( V_60 ) ;
V_71 -> V_73 = F_27 ;
V_71 -> V_74 = V_9 ;
F_31 ( V_71 ) ;
F_32 ( F_21 ( V_9 ) ) ;
V_72 = F_33 ( V_60 , F_34 ( 1000 ) ) ;
if ( ! V_72 ) {
F_15 ( V_9 -> V_35 , L_7 ,
V_9 -> V_75 ) ;
F_35 ( V_9 ) ;
return - V_76 ;
}
return 0 ;
}
int F_36 ( struct V_8 * V_9 ,
struct V_70 * V_71 )
{
struct V_59 * V_77 = & V_9 -> V_20 ;
unsigned long V_72 ;
F_30 ( V_77 ) ;
F_29 ( V_9 , V_71 ) ;
V_72 = F_33 ( V_77 , F_34 ( 1000 ) ) ;
if ( ! V_72 ) {
F_15 ( V_9 -> V_35 , L_8 ,
V_9 -> V_75 ) ;
F_35 ( V_9 ) ;
return - V_76 ;
}
return 0 ;
}
static int F_37 ( struct V_8 * V_9 ,
const char * V_78 )
{
struct V_79 * V_80 = V_9 -> V_80 ;
struct V_81 * V_82 = & V_9 -> V_81 ;
struct V_83 * V_84 ;
void T_2 * V_85 ;
V_84 = F_38 ( V_80 , V_86 , V_78 ) ;
V_85 = F_39 ( & V_80 -> V_35 , V_84 ) ;
if ( F_40 ( V_85 ) )
return F_41 ( V_85 ) ;
if ( ! strcmp ( V_78 , V_87 ) )
V_82 -> V_88 = V_85 ;
else if ( ! strcmp ( V_78 , V_89 ) )
V_82 -> V_90 = V_85 ;
else
F_15 ( V_9 -> V_35 , L_9 , V_78 ) ;
return 0 ;
}
static int F_42 ( struct V_8 * V_9 , T_3 V_91 )
{
struct V_79 * V_80 = V_9 -> V_80 ;
const char * V_78 = V_92 ;
struct V_83 * V_84 ;
int V_93 ;
V_84 = F_38 ( V_80 , V_94 , V_78 ) ;
if ( ! V_84 ) {
F_15 ( V_9 -> V_35 , L_10 , V_78 ) ;
return - V_95 ;
}
V_93 = F_43 ( V_9 -> V_35 , V_84 -> V_96 , V_91 , 0 , V_78 , V_9 ) ;
if ( V_93 )
F_15 ( V_9 -> V_35 , L_11 ) ;
return V_93 ;
}
static void F_44 ( struct V_8 * V_9 )
{
unsigned int V_97 ;
for ( V_97 = 0 ; V_97 < V_98 ; V_97 ++ )
if ( V_9 -> V_45 [ V_97 ] ) {
F_45 ( V_9 -> V_45 [ V_97 ] ) ;
V_9 -> V_45 [ V_97 ] = NULL ;
}
}
static int F_46 ( struct V_8 * V_9 )
{
struct V_79 * V_80 = V_9 -> V_80 ;
struct V_44 * V_44 ;
V_44 = F_47 ( & V_80 -> V_35 , L_12 ) ;
if ( ! V_44 ) {
F_15 ( V_9 -> V_35 , L_13 ) ;
goto V_99;
}
V_9 -> V_45 [ 0 ] = V_44 ;
return 0 ;
V_99:
F_44 ( V_9 ) ;
return - V_32 ;
}
static int F_48 ( struct V_8 * V_9 )
{
struct V_81 * V_84 = & V_9 -> V_81 ;
struct V_100 * V_100 ;
int V_93 , V_97 ;
for ( V_97 = 0 ; V_97 < V_9 -> V_27 -> V_101 ; V_97 ++ ) {
V_100 = F_49 ( V_9 -> V_35 , V_9 -> V_27 -> V_102 [ V_97 ] ) ;
if ( F_40 ( V_100 ) ) {
V_93 = F_41 ( V_100 ) ;
goto V_103;
}
V_84 -> clock [ V_97 ] = V_100 ;
}
if ( F_50 ( V_9 ) )
F_51 ( V_84 -> clock [ 0 ] , 22000000 ) ;
return 0 ;
V_103:
F_52 ( V_9 -> V_35 , L_14 ) ;
return V_93 ;
}
static int F_53 ( struct V_8 * V_9 )
{
int V_51 ;
V_51 = F_37 ( V_9 , V_87 ) ;
if ( V_51 )
goto V_104;
V_51 = F_37 ( V_9 , V_89 ) ;
if ( V_51 )
goto V_104;
V_51 = F_42 ( V_9 , F_5 ) ;
if ( V_51 )
goto V_104;
V_51 = F_46 ( V_9 ) ;
if ( V_51 )
goto V_104;
V_51 = F_48 ( V_9 ) ;
if ( V_51 )
goto V_105;
return 0 ;
V_105:
F_44 ( V_9 ) ;
V_104:
return V_51 ;
}
static void F_54 ( struct V_8 * V_9 )
{
F_44 ( V_9 ) ;
}
static int F_55 ( struct V_8 * V_9 )
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
V_51 = F_56 ( V_9 ) ;
if ( V_51 )
return V_51 ;
V_9 -> V_115 = V_107 ;
return 0 ;
}
static int F_57 ( struct V_8 * V_9 ,
void * V_116 , unsigned V_14 ,
void * V_117 , T_4 V_118 , unsigned V_119 ,
void * * V_120 , T_4 * V_121 )
{
struct V_122 * V_35 = V_9 -> V_35 ;
if ( F_23 ( V_116 ) ) {
T_4 V_123 ;
V_123 = F_58 ( V_35 , V_116 ,
V_14 , V_66 ) ;
if ( F_59 ( V_35 , V_123 ) ) {
if ( V_119 < V_14 ) {
F_15 ( V_35 , L_15 ) ;
return - V_124 ;
}
goto V_125;
}
* V_120 = V_116 ;
* V_121 = V_123 ;
V_9 -> V_55 = true ;
return 0 ;
}
V_125:
* V_120 = V_117 ;
* V_121 = V_118 ;
V_9 -> V_55 = false ;
return 0 ;
}
static inline void F_60 ( struct V_8 * V_9 ,
void * V_116 , unsigned V_14 ,
void * V_117 , T_4 V_118 , unsigned V_119 ,
void * V_126 , T_4 V_127 )
{
if ( V_9 -> V_55 )
F_61 ( V_9 -> V_35 , V_127 , V_14 , V_66 ) ;
}
static inline void F_62 ( struct V_8 * V_9 ,
void * V_116 , unsigned V_14 ,
void * V_117 , T_4 V_118 , unsigned V_119 ,
void * V_126 , T_4 V_127 )
{
if ( ! V_9 -> V_55 )
memcpy ( V_116 , V_117 , V_14 ) ;
}
static int F_63 ( struct V_8 * V_9 ,
const void * V_128 , unsigned V_14 ,
void * V_117 , T_4 V_118 , unsigned V_119 ,
const void * * V_120 , T_4 * V_121 )
{
struct V_122 * V_35 = V_9 -> V_35 ;
if ( F_23 ( V_128 ) ) {
T_4 V_129 ;
V_129 = F_58 ( V_35 , ( void * ) V_128 , V_14 ,
V_57 ) ;
if ( F_59 ( V_35 , V_129 ) ) {
if ( V_119 < V_14 ) {
F_15 ( V_35 , L_15 ) ;
return - V_124 ;
}
goto V_125;
}
* V_120 = V_128 ;
* V_121 = V_129 ;
return 0 ;
}
V_125:
memcpy ( V_117 , V_128 , V_14 ) ;
* V_120 = V_117 ;
* V_121 = V_118 ;
return 0 ;
}
static void F_64 ( struct V_8 * V_9 ,
const void * V_128 , unsigned V_14 ,
void * V_117 , T_4 V_118 , unsigned V_119 ,
const void * V_126 , T_4 V_127 )
{
struct V_122 * V_35 = V_9 -> V_35 ;
if ( V_126 == V_128 )
F_61 ( V_35 , V_127 , V_14 , V_57 ) ;
}
static void F_65 ( struct V_8 * V_9 )
{
struct V_122 * V_35 = V_9 -> V_35 ;
if ( V_9 -> V_130 && F_23 ( V_9 -> V_130 ) )
F_66 ( V_35 , V_9 -> V_131 ,
V_9 -> V_130 ,
V_9 -> V_132 ) ;
F_67 ( V_9 -> V_133 ) ;
F_67 ( V_9 -> V_56 ) ;
F_67 ( V_9 -> V_134 ) ;
V_9 -> V_133 = NULL ;
V_9 -> V_56 = NULL ;
V_9 -> V_134 = NULL ;
V_9 -> V_130 = NULL ;
V_9 -> V_131 = 0 ;
}
static int F_68 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_10 ;
struct V_122 * V_35 = V_9 -> V_35 ;
struct V_1 * V_2 = F_9 ( & V_9 -> V_22 ) ;
V_9 -> V_133 = F_69 ( V_135 , V_136 | V_137 ) ;
if ( V_9 -> V_133 == NULL )
goto V_138;
V_9 -> V_56 = F_69 ( V_2 -> V_16 ? : V_135 ,
V_136 | V_137 ) ;
if ( V_9 -> V_56 == NULL )
goto V_138;
V_9 -> V_131 = V_11 -> V_37 + V_11 -> V_39 ;
V_9 -> V_130 = F_70 ( V_35 , V_9 -> V_131 ,
& V_9 -> V_132 , V_136 ) ;
if ( ! V_9 -> V_130 )
goto V_138;
V_9 -> V_134 = F_69 ( V_2 -> V_16 + V_2 -> V_17 , V_137 ) ;
if ( ! V_9 -> V_134 )
goto V_138;
V_9 -> V_139 = V_9 -> V_130 ;
V_9 -> V_140 = V_9 -> V_132 ;
V_9 -> V_141 = V_9 -> V_139 + V_11 -> V_37 ;
V_9 -> V_142 = V_9 -> V_140 + V_11 -> V_37 ;
return 0 ;
V_138:
F_65 ( V_9 ) ;
return - V_124 ;
}
static void F_71 ( struct V_1 * V_2 , int V_143 , unsigned int V_144 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_51 ;
if ( ( V_144 & ( V_145 | V_146 ) ) ) {
if ( V_143 != V_147 )
V_9 -> V_133 [ V_9 -> V_148 ++ ] = V_143 ;
return;
}
if ( ! V_9 -> V_148 )
return;
V_51 = F_72 ( V_9 ) ;
if ( V_51 )
F_15 ( V_9 -> V_35 , L_16 ,
V_9 -> V_149 , V_51 ) ;
V_9 -> V_148 = 0 ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
return F_74 ( V_9 , V_9 -> V_149 ) ;
}
static void F_75 ( struct V_1 * V_2 , int V_150 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
if ( ( V_9 -> V_149 < 0 ) && ( V_150 >= 0 ) )
F_76 ( V_9 ) ;
else if ( ( V_9 -> V_149 >= 0 ) && ( V_150 < 0 ) )
F_77 ( V_9 ) ;
V_9 -> V_149 = V_150 ;
}
static void F_78 ( struct V_1 * V_2 , T_5 * V_151 , int V_152 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
F_52 ( V_9 -> V_35 , L_17 , V_152 ) ;
V_9 -> V_52 = V_151 ;
V_9 -> V_53 = V_152 ;
F_79 ( V_9 ) ;
}
static void F_80 ( struct V_1 * V_2 , const T_5 * V_151 , int V_152 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
F_52 ( V_9 -> V_35 , L_17 , V_152 ) ;
V_9 -> V_52 = ( T_5 * ) V_151 ;
V_9 -> V_53 = V_152 ;
F_81 ( V_9 ) ;
}
static T_5 F_82 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
T_5 * V_151 = V_9 -> V_56 ;
F_78 ( V_2 , V_151 , 1 ) ;
return V_151 [ 0 ] ;
}
static void F_83 ( struct V_8 * V_9 ,
void * V_153 , void * V_154 )
{
struct V_10 * V_155 = & V_9 -> V_10 ;
unsigned char * V_85 ;
unsigned char * V_156 ;
unsigned int V_157 ;
unsigned char V_158 ;
unsigned char V_159 ;
unsigned char V_160 ;
if ( ! V_9 -> V_40 )
return;
V_157 = V_155 -> V_29 ;
V_85 = V_153 + V_155 -> V_41 ;
V_156 = V_154 ;
V_159 = ( V_85 [ 0 ] >> V_157 ) | ( V_85 [ 1 ] << ( 8 - V_157 ) ) ;
V_160 = V_156 [ 0 ] ;
V_156 [ 0 ] = V_159 ;
V_158 = ( 0x1 << V_157 ) - 1 ;
V_85 [ 0 ] = ( V_85 [ 0 ] & V_158 ) | ( V_160 << V_157 ) ;
V_158 = ~ 0 << V_157 ;
V_85 [ 1 ] = ( V_85 [ 1 ] & V_158 ) | ( V_160 >> ( 8 - V_157 ) ) ;
}
static int F_84 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_5 * V_151 , int V_161 , int V_162 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_155 = & V_9 -> V_10 ;
void * V_139 ;
T_4 V_140 ;
void * V_141 ;
T_4 V_142 ;
unsigned int V_97 ;
unsigned char * V_163 ;
unsigned int V_164 = 0 ;
int V_51 ;
F_52 ( V_9 -> V_35 , L_18 , V_162 ) ;
V_51 = F_57 ( V_9 , V_151 , V_155 -> V_37 ,
V_9 -> V_139 , V_9 -> V_140 ,
V_155 -> V_37 ,
& V_139 , & V_140 ) ;
if ( V_51 ) {
F_15 ( V_9 -> V_35 , L_19 ) ;
V_51 = - V_124 ;
return V_51 ;
}
V_141 = V_9 -> V_141 ;
V_142 = V_9 -> V_142 ;
V_51 = F_85 ( V_9 , V_140 , V_142 ) ;
F_60 ( V_9 , V_151 , V_155 -> V_37 ,
V_9 -> V_139 , V_9 -> V_140 ,
V_155 -> V_37 ,
V_139 , V_140 ) ;
if ( V_51 ) {
F_15 ( V_9 -> V_35 , L_20 , V_51 ) ;
return V_51 ;
}
F_83 ( V_9 , V_139 , V_141 ) ;
V_163 = V_141 + V_155 -> V_38 ;
F_62 ( V_9 , V_151 , V_155 -> V_37 ,
V_9 -> V_139 , V_9 -> V_140 ,
V_155 -> V_37 ,
V_139 , V_140 ) ;
for ( V_97 = 0 ; V_97 < V_155 -> V_26 ; V_97 ++ , V_163 ++ ) {
if ( ( * V_163 == V_165 ) || ( * V_163 == V_166 ) )
continue;
if ( * V_163 == V_167 ) {
int V_168 = V_155 -> V_23 * V_155 -> V_25 ;
T_6 * V_169 = V_9 -> V_134 ;
int V_13 , V_170 ;
int V_171 ;
int V_172 ;
V_13 = V_155 -> V_24 * 8 ;
V_13 += ( ( 8 * V_155 -> V_36 ) + V_168 ) * ( V_97 + 1 ) ;
V_13 -= V_168 ;
V_170 = V_13 % 8 ;
V_171 = F_86 ( V_13 + V_168 , 8 ) ;
V_13 /= 8 ;
V_171 -= V_13 ;
V_7 -> V_173 ( V_2 , V_174 , V_13 , - 1 ) ;
V_7 -> V_175 ( V_2 , V_169 , V_171 ) ;
if ( V_170 )
V_169 [ 0 ] |= F_87 ( V_170 - 1 , 0 ) ;
V_170 = ( V_170 + V_168 ) % 8 ;
if ( V_170 )
V_169 [ V_171 - 1 ] |= F_87 ( 7 , V_170 ) ;
if ( V_97 == 0 ) {
V_172 = F_88 (
V_151 + V_97 * V_155 -> V_36 ,
V_155 -> V_36 ,
V_169 , V_171 ,
V_141 ,
V_155 -> V_24 ,
V_155 -> V_23 ) ;
} else {
V_172 = F_88 (
V_151 + V_97 * V_155 -> V_36 ,
V_155 -> V_36 ,
V_169 , V_171 ,
NULL , 0 ,
V_155 -> V_23 ) ;
}
if ( V_172 > 0 ) {
V_164 = F_89 (unsigned int, max_bitflips,
flips) ;
V_2 -> V_176 . V_177 += V_172 ;
continue;
}
V_2 -> V_176 . V_178 ++ ;
continue;
}
V_2 -> V_176 . V_177 += * V_163 ;
V_164 = F_89 (unsigned int, max_bitflips, *status) ;
}
if ( V_161 ) {
memset ( V_7 -> V_179 , ~ 0 , V_2 -> V_17 ) ;
V_7 -> V_179 [ 0 ] = ( ( T_5 * ) V_141 ) [ 0 ] ;
}
return V_164 ;
}
static int F_90 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_7 V_180 , T_7 V_152 , T_5 * V_151 , int V_162 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
void T_2 * V_90 = V_9 -> V_81 . V_90 ;
struct V_10 V_181 = V_9 -> V_10 ;
struct V_10 * V_11 = & V_9 -> V_10 ;
int V_182 = V_7 -> V_183 . V_182 ;
int V_184 , V_185 , V_15 ;
T_8 V_186 , V_187 , V_188 , V_189 ;
unsigned int V_164 ;
int V_190 , V_191 , V_192 ;
int V_193 ;
int V_194 = 0 ;
int V_195 = V_9 -> V_40 ;
V_193 = V_11 -> V_25 * V_11 -> V_23 / 8 ;
V_190 = V_180 / V_182 ;
V_191 = ( V_180 + V_152 - 1 ) / V_182 ;
if ( V_9 -> V_40 ) {
V_192 = V_11 -> V_41 / V_182 ;
if ( V_191 >= V_192 && V_190 <= V_192 ) {
F_52 ( V_9 -> V_35 ,
L_21 ,
V_162 , V_190 , V_191 , V_192 ) ;
return F_84 ( V_2 , V_7 , V_151 , 0 , V_162 ) ;
}
}
V_184 = V_11 -> V_24 ;
if ( V_190 ) {
V_194 = V_184 + ( V_182 + V_193 ) * V_190 ;
V_7 -> V_173 ( V_2 , V_174 , V_194 , - 1 ) ;
V_184 = 0 ;
V_151 = V_151 + V_190 * V_182 ;
}
V_186 = V_188 = F_91 ( V_90 + V_196 ) ;
V_187 = V_189 = F_91 ( V_90 + V_197 ) ;
V_185 = V_191 - V_190 + 1 ;
V_15 = V_184 + ( V_182 + V_193 ) * V_185 ;
V_188 &= ~ ( V_198 |
V_199 ) ;
V_188 |= F_92 ( V_185 - 1 )
| F_93 ( V_184 ) ;
F_94 ( V_188 , V_90 + V_196 ) ;
V_189 &= ~ V_200 ;
V_189 |= F_95 ( V_15 ) ;
F_94 ( V_189 , V_90 + V_197 ) ;
V_11 -> V_26 = V_185 ;
V_11 -> V_37 = V_185 * V_182 ;
V_11 -> V_15 = V_15 ;
V_11 -> V_38 = F_17 ( V_184 , 4 ) ;
F_52 ( V_9 -> V_35 , L_22 ,
V_162 , V_180 , V_152 , V_194 , V_190 , V_185 , V_15 ) ;
V_9 -> V_40 = false ;
V_164 = F_84 ( V_2 , V_7 , V_151 , 0 , V_162 ) ;
F_94 ( V_186 , V_90 + V_196 ) ;
F_94 ( V_187 , V_90 + V_197 ) ;
V_9 -> V_10 = V_181 ;
V_9 -> V_40 = V_195 ;
return V_164 ;
}
static int F_96 ( struct V_1 * V_2 , struct V_6 * V_7 ,
const T_5 * V_151 , int V_161 , int V_162 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_155 = & V_9 -> V_10 ;
const void * V_139 ;
T_4 V_140 ;
const void * V_141 ;
T_4 V_142 ;
int V_51 ;
F_52 ( V_9 -> V_35 , L_23 ) ;
if ( V_9 -> V_40 ) {
memcpy ( V_9 -> V_139 , V_151 , V_2 -> V_16 ) ;
V_139 = V_9 -> V_139 ;
V_140 = V_9 -> V_140 ;
memcpy ( V_9 -> V_141 , V_7 -> V_179 ,
V_155 -> V_39 ) ;
V_141 = V_9 -> V_141 ;
V_142 = V_9 -> V_142 ;
F_83 ( V_9 ,
( void * ) V_139 , ( void * ) V_141 ) ;
} else {
V_51 = F_63 ( V_9 ,
V_151 , V_2 -> V_16 ,
V_9 -> V_139 , V_9 -> V_140 ,
V_155 -> V_37 ,
& V_139 , & V_140 ) ;
if ( V_51 ) {
F_15 ( V_9 -> V_35 , L_24 ) ;
return 0 ;
}
V_51 = F_63 ( V_9 ,
V_7 -> V_179 , V_2 -> V_17 ,
V_9 -> V_141 , V_9 -> V_142 ,
V_155 -> V_39 ,
& V_141 , & V_142 ) ;
if ( V_51 ) {
F_15 ( V_9 -> V_35 , L_25 ) ;
goto V_201;
}
}
V_51 = F_97 ( V_9 , V_140 , V_142 ) ;
if ( V_51 )
F_15 ( V_9 -> V_35 , L_26 , V_51 ) ;
if ( ! V_9 -> V_40 ) {
F_64 ( V_9 , V_7 -> V_179 , V_2 -> V_17 ,
V_9 -> V_141 , V_9 -> V_142 ,
V_155 -> V_39 ,
V_141 , V_142 ) ;
V_201:
F_64 ( V_9 , V_151 , V_2 -> V_16 ,
V_9 -> V_139 , V_9 -> V_140 ,
V_155 -> V_37 ,
V_139 , V_140 ) ;
}
return 0 ;
}
static int F_98 ( struct V_1 * V_2 , struct V_6 * V_7 ,
int V_162 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
F_52 ( V_9 -> V_35 , L_27 , V_162 ) ;
memset ( V_7 -> V_179 , ~ 0 , V_2 -> V_17 ) ;
V_7 -> V_173 ( V_2 , V_202 , V_2 -> V_16 , V_162 ) ;
V_7 -> V_175 ( V_2 , V_7 -> V_179 , V_2 -> V_17 ) ;
if ( F_12 ( V_9 ) ) {
V_7 -> V_173 ( V_2 , V_202 , 0 , V_162 ) ;
V_7 -> V_179 [ 0 ] = V_7 -> V_203 ( V_2 ) ;
}
return 0 ;
}
static int
F_99 ( struct V_1 * V_2 , struct V_6 * V_7 , int V_162 )
{
struct V_4 V_204 = { } ;
int V_163 = 0 ;
F_100 ( V_2 , 0 , & V_204 ) ;
if ( ! V_204 . V_14 )
return - V_205 ;
if ( ! F_101 ( V_7 ) )
return - V_205 ;
V_7 -> V_173 ( V_2 , V_206 , V_2 -> V_16 + V_204 . V_13 , V_162 ) ;
V_7 -> V_207 ( V_2 , V_7 -> V_179 + V_204 . V_13 , V_204 . V_14 ) ;
V_7 -> V_173 ( V_2 , V_208 , - 1 , - 1 ) ;
V_163 = V_7 -> V_209 ( V_2 , V_7 ) ;
return V_163 & V_210 ? - V_211 : 0 ;
}
static int F_102 ( struct V_1 * V_2 ,
struct V_6 * V_7 , T_5 * V_151 ,
int V_161 , int V_162 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_155 = & V_9 -> V_10 ;
int V_212 = V_155 -> V_36 ;
int V_168 = V_155 -> V_23 * V_155 -> V_25 ;
T_6 * V_213 = V_9 -> V_134 ;
T_9 V_214 ;
T_9 V_215 ;
T_9 V_216 ;
T_5 * V_217 = V_7 -> V_179 ;
int V_218 ;
V_7 -> V_175 ( V_2 , V_213 ,
V_2 -> V_16 + V_2 -> V_17 ) ;
if ( V_9 -> V_40 ) {
T_6 V_219 = V_213 [ 0 ] ;
V_213 [ 0 ] = V_213 [ V_2 -> V_16 ] ;
V_213 [ V_2 -> V_16 ] = V_219 ;
}
if ( V_161 )
memcpy ( V_217 , V_213 , V_155 -> V_24 ) ;
V_215 = V_155 -> V_24 * 8 ;
V_214 = V_215 ;
for ( V_218 = 0 ; V_218 < V_155 -> V_26 ; V_218 ++ ) {
if ( V_151 )
F_103 ( V_151 , V_218 * V_212 * 8 ,
V_213 , V_214 ,
V_212 * 8 ) ;
V_214 += V_212 * 8 ;
if ( V_218 == V_155 -> V_26 - 1 &&
( V_215 + V_168 ) % 8 )
V_168 += 8 - ( ( V_215 + V_168 ) % 8 ) ;
if ( V_161 )
F_103 ( V_217 , V_215 ,
V_213 , V_214 ,
V_168 ) ;
V_214 += V_168 ;
V_215 += V_168 ;
}
if ( V_161 ) {
V_216 = V_215 / 8 ;
if ( V_216 < V_2 -> V_17 )
memcpy ( V_217 + V_216 ,
V_213 + V_2 -> V_16 + V_216 ,
V_2 -> V_17 - V_216 ) ;
}
return 0 ;
}
static int F_104 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
const T_5 * V_151 ,
int V_161 , int V_162 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_155 = & V_9 -> V_10 ;
int V_212 = V_155 -> V_36 ;
int V_168 = V_155 -> V_23 * V_155 -> V_25 ;
T_6 * V_213 = V_9 -> V_134 ;
T_5 * V_217 = V_7 -> V_179 ;
T_9 V_220 ;
T_9 V_215 ;
T_9 V_216 ;
int V_218 ;
if ( ! V_151 || ! V_161 )
memset ( V_213 , 0xff , V_2 -> V_16 + V_2 -> V_17 ) ;
memcpy ( V_213 , V_217 , V_155 -> V_24 ) ;
V_215 = V_155 -> V_24 * 8 ;
V_220 = V_215 ;
for ( V_218 = 0 ; V_218 < V_155 -> V_26 ; V_218 ++ ) {
if ( V_151 )
F_103 ( V_213 , V_220 ,
V_151 , V_218 * V_212 * 8 , V_212 * 8 ) ;
V_220 += V_212 * 8 ;
if ( V_218 == V_155 -> V_26 - 1 &&
( V_215 + V_168 ) % 8 )
V_168 += 8 - ( ( V_215 + V_168 ) % 8 ) ;
if ( V_161 )
F_103 ( V_213 , V_220 ,
V_217 , V_215 , V_168 ) ;
V_220 += V_168 ;
V_215 += V_168 ;
}
V_216 = V_215 / 8 ;
if ( V_161 && V_216 < V_2 -> V_17 )
memcpy ( V_213 + V_2 -> V_16 + V_216 ,
V_217 + V_216 , V_2 -> V_17 - V_216 ) ;
if ( V_9 -> V_40 ) {
T_6 V_219 = V_213 [ 0 ] ;
V_213 [ 0 ] = V_213 [ V_2 -> V_16 ] ;
V_213 [ V_2 -> V_16 ] = V_219 ;
}
V_7 -> V_207 ( V_2 , V_213 , V_2 -> V_16 + V_2 -> V_17 ) ;
return 0 ;
}
static int F_105 ( struct V_1 * V_2 , struct V_6 * V_7 ,
int V_162 )
{
V_7 -> V_173 ( V_2 , V_202 , 0 , V_162 ) ;
return F_102 ( V_2 , V_7 , NULL , 1 , V_162 ) ;
}
static int F_106 ( struct V_1 * V_2 , struct V_6 * V_7 ,
int V_162 )
{
V_7 -> V_173 ( V_2 , V_206 , 0 , V_162 ) ;
return F_104 ( V_2 , V_7 , NULL , 1 , V_162 ) ;
}
static int F_107 ( struct V_1 * V_2 , T_10 V_221 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_51 = 0 ;
T_5 * V_222 ;
int V_223 , V_162 , V_163 , V_150 ;
V_150 = ( int ) ( V_221 >> V_7 -> V_224 ) ;
V_7 -> V_225 ( V_2 , V_150 ) ;
V_223 = ! F_12 ( V_9 ) ? V_2 -> V_16 : 0 ;
V_222 = V_9 -> V_56 ;
V_222 [ 0 ] = 0 ;
V_162 = ( int ) ( V_221 >> V_7 -> V_226 ) ;
V_7 -> V_173 ( V_2 , V_206 , V_223 , V_162 ) ;
V_7 -> V_207 ( V_2 , V_222 , 1 ) ;
V_7 -> V_173 ( V_2 , V_208 , - 1 , - 1 ) ;
V_163 = V_7 -> V_209 ( V_2 , V_7 ) ;
if ( V_163 & V_210 )
V_51 = - V_211 ;
V_7 -> V_225 ( V_2 , - 1 ) ;
return V_51 ;
}
static int F_108 ( struct V_8 * V_9 )
{
struct V_227 * V_228 = & V_9 -> V_229 ;
V_228 -> V_230 = 64 ;
V_228 -> V_231 = 2 ;
return 0 ;
}
static int F_109 ( struct V_8 * V_9 )
{
struct V_227 * V_232 = & V_9 -> V_229 ;
struct V_122 * V_35 = V_9 -> V_35 ;
struct V_6 * V_7 = & V_9 -> V_22 ;
struct V_1 * V_2 = F_9 ( V_7 ) ;
unsigned int V_233 ;
unsigned int V_234 ;
unsigned int V_162 ;
T_5 * V_235 = V_7 -> V_236 -> V_237 ;
int V_238 ;
int V_239 = false ;
V_233 = 1 << V_232 -> V_231 ;
V_238 = V_9 -> V_149 ;
V_7 -> V_225 ( V_2 , 0 ) ;
F_52 ( V_35 , L_28 ) ;
for ( V_234 = 0 ; V_234 < V_233 ; V_234 ++ ) {
V_162 = V_234 * V_232 -> V_230 ;
F_52 ( V_35 , L_29 , V_162 ) ;
V_7 -> V_173 ( V_2 , V_202 , 12 , V_162 ) ;
V_7 -> V_175 ( V_2 , V_235 , strlen ( V_240 ) ) ;
if ( ! memcmp ( V_235 , V_240 , strlen ( V_240 ) ) ) {
V_239 = true ;
break;
}
}
V_7 -> V_225 ( V_2 , V_238 ) ;
if ( V_239 )
F_52 ( V_35 , L_30 ) ;
else
F_52 ( V_35 , L_31 ) ;
return V_239 ;
}
static int F_110 ( struct V_8 * V_9 )
{
struct V_122 * V_35 = V_9 -> V_35 ;
struct V_227 * V_232 = & V_9 -> V_229 ;
struct V_6 * V_7 = & V_9 -> V_22 ;
struct V_1 * V_2 = F_9 ( V_7 ) ;
unsigned int V_241 ;
unsigned int V_233 ;
unsigned int V_242 ;
unsigned int V_243 ;
unsigned int V_244 ;
unsigned int V_234 ;
unsigned int V_162 ;
T_5 * V_235 = V_7 -> V_236 -> V_237 ;
int V_238 ;
int V_163 ;
V_241 = V_2 -> V_245 / V_2 -> V_16 ;
V_233 = 1 << V_232 -> V_231 ;
V_242 = V_233 *
V_232 -> V_230 ;
V_243 =
( V_242 + ( V_241 - 1 ) ) /
V_241 ;
F_52 ( V_35 , L_32 ) ;
F_52 ( V_35 , L_33 , V_243 ) ;
F_52 ( V_35 , L_34 , V_233 ) ;
F_52 ( V_35 , L_35 , V_242 ) ;
V_238 = V_9 -> V_149 ;
V_7 -> V_225 ( V_2 , 0 ) ;
F_52 ( V_35 , L_36 ) ;
for ( V_244 = 0 ; V_244 < V_243 ; V_244 ++ ) {
V_162 = V_244 * V_241 ;
F_52 ( V_35 , L_37 , V_244 ) ;
V_7 -> V_173 ( V_2 , V_246 , - 1 , V_162 ) ;
V_7 -> V_173 ( V_2 , V_247 , - 1 , - 1 ) ;
V_163 = V_7 -> V_209 ( V_2 , V_7 ) ;
if ( V_163 & V_210 )
F_15 ( V_35 , L_38 , V_248 ) ;
}
memset ( V_235 , ~ 0 , V_2 -> V_16 ) ;
memcpy ( V_235 + 12 , V_240 , strlen ( V_240 ) ) ;
F_52 ( V_35 , L_39 ) ;
for ( V_234 = 0 ; V_234 < V_233 ; V_234 ++ ) {
V_162 = V_234 * V_232 -> V_230 ;
F_52 ( V_35 , L_40 , V_162 ) ;
V_7 -> V_173 ( V_2 , V_206 , 0x00 , V_162 ) ;
V_7 -> V_183 . V_249 ( V_2 , V_7 , V_235 , 0 , V_162 ) ;
V_7 -> V_173 ( V_2 , V_208 , - 1 , - 1 ) ;
V_163 = V_7 -> V_209 ( V_2 , V_7 ) ;
if ( V_163 & V_210 )
F_15 ( V_35 , L_41 , V_248 ) ;
}
V_7 -> V_225 ( V_2 , V_238 ) ;
return 0 ;
}
static int F_111 ( struct V_8 * V_9 )
{
struct V_122 * V_35 = V_9 -> V_35 ;
struct V_6 * V_7 = & V_9 -> V_22 ;
struct V_1 * V_2 = F_9 ( V_7 ) ;
unsigned int V_250 ;
unsigned int V_244 ;
int V_150 ;
int V_162 ;
T_10 V_251 ;
T_5 V_222 ;
int V_51 = 0 ;
if ( F_109 ( V_9 ) )
return 0 ;
F_52 ( V_35 , L_42 ) ;
V_250 = V_7 -> V_252 >> V_7 -> V_253 ;
for ( V_244 = 0 ; V_244 < V_250 ; V_244 ++ ) {
V_150 = V_244 >> ( V_7 -> V_224 - V_7 -> V_253 ) ;
V_162 = V_244 << ( V_7 -> V_253 - V_7 -> V_226 ) ;
V_251 = V_244 << V_7 -> V_253 ;
V_7 -> V_225 ( V_2 , V_150 ) ;
V_7 -> V_173 ( V_2 , V_202 , V_2 -> V_16 , V_162 ) ;
V_222 = V_7 -> V_203 ( V_2 ) ;
V_7 -> V_225 ( V_2 , - 1 ) ;
if ( V_222 != 0xff ) {
F_52 ( V_35 , L_43 , V_244 ) ;
V_51 = V_7 -> V_254 ( V_2 , V_251 ) ;
if ( V_51 )
F_15 ( V_35 ,
L_44 ,
V_51 ) ;
}
}
F_110 ( V_9 ) ;
return 0 ;
}
static int F_112 ( struct V_8 * V_9 )
{
F_108 ( V_9 ) ;
if ( F_12 ( V_9 ) )
return F_111 ( V_9 ) ;
return 0 ;
}
static int F_113 ( struct V_8 * V_9 )
{
int V_51 ;
F_65 ( V_9 ) ;
V_51 = F_114 ( V_9 ) ;
if ( V_51 ) {
F_15 ( V_9 -> V_35 , L_45 , V_51 ) ;
return V_51 ;
}
return F_68 ( V_9 ) ;
}
static int F_115 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = & V_9 -> V_22 ;
struct V_1 * V_2 = F_9 ( V_7 ) ;
struct V_255 * V_183 = & V_7 -> V_183 ;
struct V_10 * V_256 = & V_9 -> V_10 ;
int V_51 ;
V_51 = F_113 ( V_9 ) ;
if ( V_51 )
return V_51 ;
V_183 -> V_257 = F_84 ;
V_183 -> V_258 = F_96 ;
V_183 -> V_259 = F_98 ;
V_183 -> V_260 = F_99 ;
V_183 -> V_261 = F_102 ;
V_183 -> V_249 = F_104 ;
V_183 -> V_262 = F_105 ;
V_183 -> V_263 = F_106 ;
V_183 -> V_264 = V_265 ;
V_183 -> V_182 = V_256 -> V_36 ;
V_183 -> V_266 = V_256 -> V_23 ;
F_116 ( V_2 , & V_267 ) ;
if ( F_50 ( V_9 ) &&
( ( V_256 -> V_25 * V_256 -> V_23 ) % 8 ) == 0 ) {
V_183 -> V_268 = F_90 ;
V_7 -> V_269 |= V_270 ;
}
F_117 ( V_9 ) ;
return 0 ;
}
static int F_118 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = & V_9 -> V_22 ;
struct V_1 * V_2 = F_9 ( V_7 ) ;
int V_51 ;
V_9 -> V_149 = - 1 ;
V_2 -> V_271 = L_46 ;
V_2 -> V_35 . V_272 = V_9 -> V_35 ;
F_119 ( V_7 , V_9 ) ;
F_120 ( V_7 , V_9 -> V_80 -> V_35 . V_43 ) ;
V_7 -> V_225 = F_75 ;
V_7 -> V_273 = F_71 ;
V_7 -> V_274 = F_73 ;
V_7 -> V_203 = F_82 ;
V_7 -> V_175 = F_78 ;
V_7 -> V_207 = F_80 ;
V_7 -> V_275 = & V_276 ;
V_7 -> V_254 = F_107 ;
V_7 -> V_269 |= V_277 ;
V_9 -> V_40 = ! F_12 ( V_9 ) ;
V_9 -> V_10 . V_37 = 1024 ;
V_9 -> V_10 . V_39 = 128 ;
V_51 = F_68 ( V_9 ) ;
if ( V_51 )
goto V_278;
V_51 = F_121 ( V_2 , F_50 ( V_9 ) ? 2 : 1 , NULL ) ;
if ( V_51 )
goto V_278;
if ( V_7 -> V_279 & V_280 ) {
V_7 -> V_279 |= V_281 ;
if ( F_20 ( V_9 -> V_35 -> V_43 ,
L_47 ) )
V_9 -> V_40 = false ;
}
F_52 ( V_9 -> V_35 , L_48 ,
V_9 -> V_40 ? L_49 : L_50 ) ;
V_51 = F_115 ( V_9 ) ;
if ( V_51 )
goto V_278;
V_7 -> V_269 |= V_282 ;
V_51 = F_122 ( V_2 ) ;
if ( V_51 )
goto V_278;
V_51 = F_112 ( V_9 ) ;
if ( V_51 )
goto V_283;
V_51 = V_7 -> V_284 ( V_2 ) ;
if ( V_51 )
goto V_283;
V_51 = F_123 ( V_2 , NULL , 0 ) ;
if ( V_51 )
goto V_283;
return 0 ;
V_283:
F_124 ( V_7 ) ;
V_278:
F_65 ( V_9 ) ;
return V_51 ;
}
static int F_125 ( struct V_79 * V_80 )
{
struct V_8 * V_9 ;
const struct V_285 * V_286 ;
int V_51 ;
V_9 = F_126 ( & V_80 -> V_35 , sizeof( * V_9 ) , V_137 ) ;
if ( ! V_9 )
return - V_124 ;
V_286 = F_127 ( V_287 , & V_80 -> V_35 ) ;
if ( V_286 ) {
V_9 -> V_27 = V_286 -> V_143 ;
} else {
F_15 ( & V_80 -> V_35 , L_51 ) ;
return - V_95 ;
}
F_128 ( V_80 , V_9 ) ;
V_9 -> V_80 = V_80 ;
V_9 -> V_35 = & V_80 -> V_35 ;
V_51 = F_53 ( V_9 ) ;
if ( V_51 )
goto V_288;
V_51 = F_55 ( V_9 ) ;
if ( V_51 )
goto V_289;
V_51 = F_118 ( V_9 ) ;
if ( V_51 )
goto V_289;
F_129 ( V_9 -> V_35 , L_52 ) ;
return 0 ;
V_289:
F_54 ( V_9 ) ;
V_288:
return V_51 ;
}
static int F_130 ( struct V_79 * V_80 )
{
struct V_8 * V_9 = F_131 ( V_80 ) ;
F_132 ( F_9 ( & V_9 -> V_22 ) ) ;
F_65 ( V_9 ) ;
F_54 ( V_9 ) ;
return 0 ;
}
static int F_133 ( struct V_122 * V_35 )
{
struct V_8 * V_9 = F_134 ( V_35 ) ;
F_44 ( V_9 ) ;
return 0 ;
}
static int F_135 ( struct V_122 * V_35 )
{
struct V_8 * V_9 = F_134 ( V_35 ) ;
int V_51 ;
V_51 = F_46 ( V_9 ) ;
if ( V_51 < 0 )
return V_51 ;
V_9 -> V_290 &= ~ V_291 ;
V_51 = F_56 ( V_9 ) ;
if ( V_51 ) {
F_15 ( V_9 -> V_35 , L_53 , V_51 ) ;
return V_51 ;
}
V_51 = F_114 ( V_9 ) ;
if ( V_51 ) {
F_15 ( V_9 -> V_35 , L_54 , V_51 ) ;
return V_51 ;
}
F_117 ( V_9 ) ;
return 0 ;
}
