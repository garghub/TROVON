static struct V_1 * *
F_1 ( struct V_1 * * V_2 )
{
for (; * V_2 ; V_2 ++ ) {
if ( ( * V_2 ) -> V_3 == V_4 )
return V_2 ;
}
return NULL ;
}
int F_2 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_11 * V_12 = F_3 ( V_6 ) ;
struct V_13 * V_14 = NULL ;
struct V_1 * * V_15 = NULL ;
struct V_16 * V_17 = NULL ;
int V_18 = 0 ;
struct V_1 * * V_19 ;
if ( ! V_6 || ! V_8 || ! V_10 )
return - V_20 ;
switch ( V_6 -> V_21 ) {
case V_22 :
if ( F_4 ( V_6 ) ) {
V_15 = V_8 -> V_23 ;
V_18 = 1 ;
break;
}
case V_24 :
if ( F_5 ( V_6 ) ) {
V_15 = V_8 -> V_25 ;
break;
}
default:
V_15 = V_8 -> V_26 ;
}
F_6 (speed_desc, d_spd) {
V_14 = (struct V_13 * ) * V_19 ;
if ( V_14 -> V_27 == V_10 -> V_28 )
goto V_29;
}
return - V_20 ;
V_29:
V_10 -> V_30 = F_7 ( V_14 ) ;
V_10 -> V_31 = V_14 ;
V_10 -> V_17 = NULL ;
V_10 -> V_32 = 0 ;
V_10 -> V_33 = 0 ;
if ( ! V_18 )
return 0 ;
V_17 = (struct V_16 * ) * ( ++ V_19 ) ;
if ( ! V_17 ||
( V_17 -> V_3 != V_34 ) )
return - V_20 ;
V_10 -> V_17 = V_17 ;
if ( V_6 -> V_21 == V_22 ) {
switch ( F_8 ( V_10 -> V_31 ) ) {
case V_35 :
V_10 -> V_33 = V_17 -> V_36 & 0x3 ;
case V_37 :
case V_38 :
V_10 -> V_32 = V_17 -> V_39 + 1 ;
break;
default:
if ( V_17 -> V_39 != 0 )
ERROR ( V_12 , L_1 ) ;
V_10 -> V_32 = 1 ;
break;
}
}
return 0 ;
}
int F_9 ( struct V_40 * V_41 ,
struct V_7 * V_42 )
{
int V_43 = - V_44 ;
F_10 ( V_41 -> V_12 , L_2 ,
V_42 -> V_45 , V_42 ,
V_41 -> V_46 , V_41 ) ;
if ( ! V_42 -> V_47 || ! V_42 -> V_48 )
goto V_49;
V_42 -> V_41 = V_41 ;
F_11 ( & V_42 -> V_50 , & V_41 -> V_51 ) ;
if ( V_42 -> V_52 ) {
V_43 = V_42 -> V_52 ( V_41 , V_42 ) ;
if ( V_43 < 0 ) {
F_12 ( & V_42 -> V_50 ) ;
V_42 -> V_41 = NULL ;
}
} else
V_43 = 0 ;
if ( ! V_41 -> V_53 && V_42 -> V_26 )
V_41 -> V_53 = true ;
if ( ! V_41 -> V_54 && V_42 -> V_25 )
V_41 -> V_54 = true ;
if ( ! V_41 -> V_55 && V_42 -> V_23 )
V_41 -> V_55 = true ;
V_49:
if ( V_43 )
F_10 ( V_41 -> V_12 , L_3 ,
V_42 -> V_45 , V_42 , V_43 ) ;
return V_43 ;
}
int F_13 ( struct V_7 * V_42 )
{
struct V_11 * V_12 = V_42 -> V_41 -> V_12 ;
unsigned long V_56 ;
int V_57 = 0 ;
F_14 ( & V_12 -> V_58 , V_56 ) ;
if ( V_12 -> V_59 == 0 )
V_57 = F_15 ( V_12 -> V_60 ) ;
if ( V_57 == 0 )
V_12 -> V_59 ++ ;
F_16 ( & V_12 -> V_58 , V_56 ) ;
return V_57 ;
}
int F_17 ( struct V_7 * V_42 )
{
struct V_11 * V_12 = V_42 -> V_41 -> V_12 ;
unsigned long V_56 ;
int V_57 = 0 ;
F_14 ( & V_12 -> V_58 , V_56 ) ;
if ( F_18 ( V_12 -> V_59 == 0 ) )
V_57 = - V_44 ;
else {
V_12 -> V_59 -- ;
if ( V_12 -> V_59 == 0 )
V_57 = F_19 ( V_12 -> V_60 ) ;
}
F_16 ( & V_12 -> V_58 , V_56 ) ;
return V_57 ;
}
int F_20 ( struct V_40 * V_41 ,
struct V_7 * V_42 )
{
unsigned V_61 = V_41 -> V_62 ;
if ( V_61 < V_63 ) {
V_41 -> V_64 [ V_61 ] = V_42 ;
V_41 -> V_62 = V_61 + 1 ;
return V_61 ;
}
return - V_65 ;
}
static int F_21 ( struct V_40 * V_41 ,
enum V_66 V_21 , void * V_67 , T_1 type )
{
struct V_68 * V_69 = V_67 ;
void * V_70 = V_67 + V_71 ;
int V_72 = V_73 - V_71 ;
struct V_7 * V_8 ;
int V_57 ;
V_69 = V_67 ;
V_69 -> V_74 = V_71 ;
V_69 -> V_3 = type ;
V_69 -> V_75 = V_41 -> V_62 ;
V_69 -> V_76 = V_41 -> V_76 ;
V_69 -> V_77 = V_41 -> V_77 ;
V_69 -> V_36 = V_78 | V_41 -> V_36 ;
V_69 -> V_79 = V_41 -> V_79 ? : ( V_80 / 2 ) ;
if ( V_41 -> V_26 ) {
V_57 = F_22 ( V_70 , V_72 ,
V_41 -> V_26 ) ;
if ( V_57 < 0 )
return V_57 ;
V_72 -= V_57 ;
V_70 += V_57 ;
}
F_23 (f, &config->functions, list) {
struct V_1 * * V_26 ;
switch ( V_21 ) {
case V_22 :
V_26 = V_8 -> V_23 ;
break;
case V_24 :
V_26 = V_8 -> V_25 ;
break;
default:
V_26 = V_8 -> V_26 ;
}
if ( ! V_26 )
continue;
V_57 = F_22 ( V_70 , V_72 ,
( const struct V_1 * * ) V_26 ) ;
if ( V_57 < 0 )
return V_57 ;
V_72 -= V_57 ;
V_70 += V_57 ;
}
V_72 = V_70 - V_67 ;
V_69 -> V_81 = F_24 ( V_72 ) ;
return V_72 ;
}
static int F_25 ( struct V_11 * V_12 , unsigned V_82 )
{
struct V_5 * V_60 = V_12 -> V_60 ;
struct V_40 * V_69 ;
T_1 type = V_82 >> 8 ;
enum V_66 V_21 = V_83 ;
if ( V_60 -> V_21 == V_22 )
V_21 = V_60 -> V_21 ;
else if ( F_5 ( V_60 ) ) {
int V_84 = 0 ;
if ( V_60 -> V_21 == V_24 )
V_84 = 1 ;
if ( type == V_85 )
V_84 = ! V_84 ;
if ( V_84 )
V_21 = V_24 ;
}
V_82 &= 0xff ;
F_23 (c, &cdev->configs, list) {
switch ( V_21 ) {
case V_22 :
if ( ! V_69 -> V_55 )
continue;
break;
case V_24 :
if ( ! V_69 -> V_54 )
continue;
break;
default:
if ( ! V_69 -> V_53 )
continue;
}
if ( V_82 == 0 )
return F_21 ( V_69 , V_21 , V_12 -> V_86 -> V_67 , type ) ;
V_82 -- ;
}
return - V_44 ;
}
static int F_26 ( struct V_11 * V_12 , unsigned type )
{
struct V_5 * V_60 = V_12 -> V_60 ;
struct V_40 * V_69 ;
unsigned V_87 = 0 ;
int V_84 = 0 ;
int V_88 = 0 ;
if ( F_5 ( V_60 ) ) {
if ( V_60 -> V_21 == V_24 )
V_84 = 1 ;
if ( V_60 -> V_21 == V_22 )
V_88 = 1 ;
if ( type == V_89 )
V_84 = ! V_84 ;
}
F_23 (c, &cdev->configs, list) {
if ( V_88 ) {
if ( ! V_69 -> V_55 )
continue;
} else if ( V_84 ) {
if ( ! V_69 -> V_54 )
continue;
} else {
if ( ! V_69 -> V_53 )
continue;
}
V_87 ++ ;
}
return V_87 ;
}
static int F_27 ( struct V_11 * V_12 )
{
struct V_90 * V_91 ;
struct V_92 * V_93 ;
struct V_94 V_95 ;
struct V_96 * V_97 = V_12 -> V_86 -> V_67 ;
V_97 -> V_74 = V_98 ;
V_97 -> V_3 = V_99 ;
V_97 -> V_81 = F_24 ( V_98 ) ;
V_97 -> V_100 = 0 ;
V_91 = V_12 -> V_86 -> V_67 + F_28 ( V_97 -> V_81 ) ;
V_97 -> V_100 ++ ;
F_29 ( & V_97 -> V_81 , V_101 ) ;
V_91 -> V_74 = V_101 ;
V_91 -> V_3 = V_102 ;
V_91 -> V_103 = V_104 ;
V_91 -> V_36 = F_30 ( V_105 ) ;
V_93 = V_12 -> V_86 -> V_67 + F_28 ( V_97 -> V_81 ) ;
V_97 -> V_100 ++ ;
F_29 ( & V_97 -> V_81 , V_106 ) ;
V_93 -> V_74 = V_106 ;
V_93 -> V_3 = V_102 ;
V_93 -> V_103 = V_107 ;
V_93 -> V_36 = 0 ;
V_93 -> V_108 = F_24 ( V_109 |
V_110 |
V_111 |
V_112 ) ;
V_93 -> V_113 = V_109 ;
if ( V_12 -> V_60 -> V_114 -> V_115 )
V_12 -> V_60 -> V_114 -> V_115 ( & V_95 ) ;
else {
V_95 . V_116 = V_117 ;
V_95 . V_118 =
F_24 ( V_119 ) ;
}
V_93 -> V_116 = V_95 . V_116 ;
V_93 -> V_118 = V_95 . V_118 ;
return F_28 ( V_97 -> V_81 ) ;
}
static void F_31 ( struct V_11 * V_12 )
{
struct V_120 * V_121 = V_12 -> V_86 -> V_67 ;
V_121 -> V_74 = sizeof( * V_121 ) ;
V_121 -> V_3 = V_89 ;
V_121 -> V_122 = V_12 -> V_31 . V_122 ;
V_121 -> V_123 = V_12 -> V_31 . V_123 ;
V_121 -> V_124 = V_12 -> V_31 . V_124 ;
V_121 -> V_125 = V_12 -> V_31 . V_125 ;
V_121 -> V_126 = V_12 -> V_60 -> V_127 -> V_30 ;
V_121 -> V_128 = F_26 ( V_12 , V_89 ) ;
V_121 -> V_129 = 0 ;
}
static void F_32 ( struct V_11 * V_12 )
{
struct V_7 * V_8 ;
F_10 ( V_12 , L_4 ) ;
F_23 (f, &cdev->config->functions, list) {
if ( V_8 -> V_48 )
V_8 -> V_48 ( V_8 ) ;
F_33 ( V_8 -> V_130 , 32 ) ;
}
V_12 -> V_41 = NULL ;
}
static int F_34 ( struct V_11 * V_12 ,
const struct V_131 * V_132 , unsigned V_133 )
{
struct V_5 * V_60 = V_12 -> V_60 ;
struct V_40 * V_69 = NULL ;
int V_134 = - V_44 ;
unsigned V_135 = F_35 ( V_60 ) ? 8 : 100 ;
int V_136 ;
if ( V_133 ) {
F_23 (c, &cdev->configs, list) {
if ( V_69 -> V_76 == V_133 ) {
if ( V_12 -> V_41 )
F_32 ( V_12 ) ;
V_134 = 0 ;
break;
}
}
if ( V_134 < 0 )
goto V_49;
} else {
if ( V_12 -> V_41 )
F_32 ( V_12 ) ;
V_134 = 0 ;
}
F_36 ( V_12 , L_5 ,
F_37 ( V_60 -> V_21 ) ,
V_133 , V_69 ? V_69 -> V_46 : L_6 ) ;
if ( ! V_69 )
goto V_49;
V_12 -> V_41 = V_69 ;
for ( V_136 = 0 ; V_136 < V_63 ; V_136 ++ ) {
struct V_7 * V_8 = V_69 -> V_64 [ V_136 ] ;
struct V_1 * * V_26 ;
if ( ! V_8 )
break;
switch ( V_60 -> V_21 ) {
case V_22 :
V_26 = V_8 -> V_23 ;
break;
case V_24 :
V_26 = V_8 -> V_25 ;
break;
default:
V_26 = V_8 -> V_26 ;
}
for (; * V_26 ; ++ V_26 ) {
struct V_13 * V_137 ;
int V_138 ;
if ( ( * V_26 ) -> V_3 != V_4 )
continue;
V_137 = (struct V_13 * ) * V_26 ;
V_138 = ( ( V_137 -> V_27 & 0x80 ) >> 3 )
| ( V_137 -> V_27 & 0x0f ) ;
F_38 ( V_138 , V_8 -> V_130 ) ;
}
V_134 = V_8 -> V_47 ( V_8 , V_136 , 0 ) ;
if ( V_134 < 0 ) {
F_10 ( V_12 , L_7 ,
V_136 , V_8 -> V_45 , V_8 , V_134 ) ;
F_32 ( V_12 ) ;
goto V_49;
}
if ( V_134 == V_139 ) {
F_10 ( V_12 ,
L_8 ,
V_140 , V_136 , V_8 -> V_45 ) ;
V_12 -> V_141 ++ ;
F_10 ( V_12 , L_9 ,
V_12 -> V_141 ) ;
}
}
V_135 = V_69 -> V_79 ? ( 2 * V_69 -> V_79 ) : V_80 ;
V_49:
F_39 ( V_60 , V_135 ) ;
if ( V_134 >= 0 && V_12 -> V_141 )
V_134 = V_139 ;
return V_134 ;
}
int F_40 ( struct V_11 * V_12 ,
struct V_40 * V_41 ,
int (* V_52)( struct V_40 * ) )
{
int V_57 = - V_44 ;
struct V_40 * V_69 ;
F_10 ( V_12 , L_10 ,
V_41 -> V_76 ,
V_41 -> V_46 , V_41 ) ;
if ( ! V_41 -> V_76 || ! V_52 )
goto V_49;
F_23 (c, &cdev->configs, list) {
if ( V_69 -> V_76 == V_41 -> V_76 ) {
V_57 = - V_142 ;
goto V_49;
}
}
V_41 -> V_12 = V_12 ;
F_11 ( & V_41 -> V_50 , & V_12 -> V_143 ) ;
F_41 ( & V_41 -> V_51 ) ;
V_41 -> V_62 = 0 ;
memset ( V_41 -> V_64 , 0 , sizeof( V_41 -> V_64 ) ) ;
V_57 = V_52 ( V_41 ) ;
if ( V_57 < 0 ) {
while ( ! F_42 ( & V_41 -> V_51 ) ) {
struct V_7 * V_8 ;
V_8 = F_43 ( & V_41 -> V_51 ,
struct V_7 , V_50 ) ;
F_12 ( & V_8 -> V_50 ) ;
if ( V_8 -> V_144 ) {
F_10 ( V_12 , L_11 ,
V_8 -> V_45 , V_8 ) ;
V_8 -> V_144 ( V_41 , V_8 ) ;
}
}
F_12 ( & V_41 -> V_50 ) ;
V_41 -> V_12 = NULL ;
} else {
unsigned V_145 ;
F_10 ( V_12 , L_12 ,
V_41 -> V_76 , V_41 ,
V_41 -> V_55 ? L_13 : L_14 ,
V_41 -> V_54 ? L_15 : L_14 ,
V_41 -> V_53
? ( F_5 ( V_12 -> V_60 )
? L_16
: L_17 )
: L_14 ) ;
for ( V_145 = 0 ; V_145 < V_63 ; V_145 ++ ) {
struct V_7 * V_8 = V_41 -> V_64 [ V_145 ] ;
if ( ! V_8 )
continue;
F_10 ( V_12 , L_18 ,
V_145 , V_8 -> V_45 , V_8 ) ;
}
}
F_44 ( V_12 -> V_60 ) ;
V_49:
if ( V_57 )
F_10 ( V_12 , L_19 , V_41 -> V_46 ,
V_41 -> V_76 , V_57 ) ;
return V_57 ;
}
static void F_45 ( struct V_11 * V_12 ,
struct V_40 * V_41 )
{
while ( ! F_42 ( & V_41 -> V_51 ) ) {
struct V_7 * V_8 ;
V_8 = F_43 ( & V_41 -> V_51 ,
struct V_7 , V_50 ) ;
F_12 ( & V_8 -> V_50 ) ;
if ( V_8 -> V_144 ) {
F_10 ( V_12 , L_11 , V_8 -> V_45 , V_8 ) ;
V_8 -> V_144 ( V_41 , V_8 ) ;
}
}
F_12 ( & V_41 -> V_50 ) ;
if ( V_41 -> V_144 ) {
F_10 ( V_12 , L_20 , V_41 -> V_46 , V_41 ) ;
V_41 -> V_144 ( V_41 ) ;
}
}
void F_46 ( struct V_11 * V_12 ,
struct V_40 * V_41 )
{
unsigned long V_56 ;
F_14 ( & V_12 -> V_58 , V_56 ) ;
if ( V_12 -> V_41 == V_41 )
F_32 ( V_12 ) ;
F_16 ( & V_12 -> V_58 , V_56 ) ;
F_45 ( V_12 , V_41 ) ;
}
static void F_47 ( struct V_146 * * V_147 , T_2 * V_67 )
{
const struct V_146 * V_148 ;
T_2 V_149 ;
T_2 * V_136 ;
while ( * V_147 ) {
V_148 = * V_147 ;
V_149 = F_24 ( V_148 -> V_149 ) ;
for ( V_136 = V_67 ; * V_136 && V_136 < & V_67 [ 126 ] ; V_136 ++ ) {
if ( * V_136 == V_149 )
goto V_150;
}
* V_136 ++ = V_149 ;
V_150:
V_147 ++ ;
}
}
static int F_48 (
struct V_146 * * V_147 ,
void * V_67 ,
T_3 V_149 ,
int V_61
)
{
struct V_146 * V_148 ;
int V_43 ;
while ( * V_147 ) {
V_148 = * V_147 ++ ;
if ( V_148 -> V_149 != V_149 )
continue;
V_43 = F_49 ( V_148 , V_61 , V_67 ) ;
if ( V_43 > 0 )
return V_43 ;
}
return - V_44 ;
}
static int F_50 ( struct V_11 * V_12 ,
void * V_67 , T_3 V_149 , int V_61 )
{
struct V_40 * V_69 ;
struct V_7 * V_8 ;
int V_72 ;
const char * V_151 ;
if ( V_61 == 0 ) {
struct V_152 * V_148 = V_67 ;
struct V_146 * * V_147 ;
memset ( V_148 , 0 , 256 ) ;
V_148 -> V_3 = V_153 ;
V_147 = V_154 -> V_155 ;
if ( V_147 )
F_47 ( V_147 , V_148 -> V_156 ) ;
F_23 (c, &cdev->configs, list) {
V_147 = V_69 -> V_155 ;
if ( V_147 )
F_47 ( V_147 , V_148 -> V_156 ) ;
F_23 (f, &c->functions, list) {
V_147 = V_8 -> V_155 ;
if ( V_147 )
F_47 ( V_147 , V_148 -> V_156 ) ;
}
}
for ( V_72 = 0 ; V_72 <= 126 && V_148 -> V_156 [ V_72 ] ; V_72 ++ )
continue;
if ( ! V_72 )
return - V_44 ;
V_148 -> V_74 = 2 * ( V_72 + 1 ) ;
return V_148 -> V_74 ;
}
if ( V_12 -> V_157 == V_61 )
V_151 = V_158 ? : V_154 -> V_158 ? :
V_159 ;
else if ( V_12 -> V_160 == V_61 )
V_151 = V_161 ? : V_154 -> V_161 ;
else if ( V_12 -> V_162 == V_61 )
V_151 = V_163 ? : V_154 -> V_163 ;
else
V_151 = NULL ;
if ( V_151 ) {
struct V_146 V_155 = {
. V_149 = V_149 ,
. V_155 = & (struct V_164 ) { 0xff , V_151 }
} ;
return F_49 ( & V_155 , 0xff , V_67 ) ;
}
if ( V_154 -> V_155 ) {
V_72 = F_48 ( V_154 -> V_155 , V_67 , V_149 , V_61 ) ;
if ( V_72 > 0 )
return V_72 ;
}
F_23 (c, &cdev->configs, list) {
if ( V_69 -> V_155 ) {
V_72 = F_48 ( V_69 -> V_155 , V_67 , V_149 , V_61 ) ;
if ( V_72 > 0 )
return V_72 ;
}
F_23 (f, &c->functions, list) {
if ( ! V_8 -> V_155 )
continue;
V_72 = F_48 ( V_8 -> V_155 , V_67 , V_149 , V_61 ) ;
if ( V_72 > 0 )
return V_72 ;
}
}
return - V_44 ;
}
int F_51 ( struct V_11 * V_12 )
{
if ( V_12 -> V_165 < 254 ) {
V_12 -> V_165 ++ ;
return V_12 -> V_165 ;
}
return - V_65 ;
}
int F_52 ( struct V_11 * V_12 , struct V_164 * V_151 )
{
int V_70 = V_12 -> V_165 ;
for (; V_151 -> V_148 ; ++ V_151 ) {
if ( F_53 ( V_70 >= 254 ) )
return - V_65 ;
V_151 -> V_61 = ++ V_70 ;
}
V_12 -> V_165 = V_70 ;
return 0 ;
}
int F_54 ( struct V_11 * V_69 , unsigned V_166 )
{
unsigned V_70 = V_69 -> V_165 ;
if ( F_53 ( V_166 > 254 || ( unsigned ) V_70 + V_166 > 254 ) )
return - V_65 ;
V_69 -> V_165 += V_166 ;
return V_70 + 1 ;
}
static void F_55 ( struct V_9 * V_137 , struct V_167 * V_86 )
{
if ( V_86 -> V_57 || V_86 -> V_168 != V_86 -> V_169 )
F_10 ( (struct V_11 * ) V_137 -> V_170 ,
L_21 ,
V_86 -> V_57 , V_86 -> V_168 , V_86 -> V_169 ) ;
}
static int
F_56 ( struct V_5 * V_60 , const struct V_131 * V_132 )
{
struct V_11 * V_12 = F_3 ( V_60 ) ;
struct V_167 * V_86 = V_12 -> V_86 ;
int V_43 = - V_171 ;
int V_57 = 0 ;
T_3 V_172 = F_28 ( V_132 -> V_173 ) ;
T_1 V_174 = V_172 & 0xFF ;
T_3 V_82 = F_28 ( V_132 -> V_175 ) ;
T_3 V_176 = F_28 ( V_132 -> V_177 ) ;
struct V_7 * V_8 = NULL ;
T_1 V_178 ;
V_86 -> V_179 = 0 ;
V_86 -> V_180 = F_55 ;
V_86 -> V_169 = 0 ;
V_60 -> V_127 -> V_170 = V_12 ;
switch ( V_132 -> V_181 ) {
case V_182 :
if ( V_132 -> V_183 != V_184 )
goto V_185;
switch ( V_82 >> 8 ) {
case V_186 :
V_12 -> V_31 . V_128 =
F_26 ( V_12 , V_186 ) ;
V_12 -> V_31 . V_126 =
V_12 -> V_60 -> V_127 -> V_30 ;
if ( F_4 ( V_60 ) ) {
if ( V_60 -> V_21 >= V_22 ) {
V_12 -> V_31 . V_122 = F_24 ( 0x0300 ) ;
V_12 -> V_31 . V_126 = 9 ;
} else {
V_12 -> V_31 . V_122 = F_24 ( 0x0210 ) ;
}
}
V_43 = F_57 ( V_176 , ( T_3 ) sizeof V_12 -> V_31 ) ;
memcpy ( V_86 -> V_67 , & V_12 -> V_31 , V_43 ) ;
break;
case V_89 :
if ( ! F_5 ( V_60 ) ||
V_60 -> V_21 >= V_22 )
break;
F_31 ( V_12 ) ;
V_43 = F_58 ( int , V_176 ,
sizeof( struct V_120 ) ) ;
break;
case V_85 :
if ( ! F_5 ( V_60 ) ||
V_60 -> V_21 >= V_22 )
break;
case V_187 :
V_43 = F_25 ( V_12 , V_82 ) ;
if ( V_43 >= 0 )
V_43 = F_57 ( V_176 , ( T_3 ) V_43 ) ;
break;
case V_153 :
V_43 = F_50 ( V_12 , V_86 -> V_67 ,
V_172 , V_82 & 0xff ) ;
if ( V_43 >= 0 )
V_43 = F_57 ( V_176 , ( T_3 ) V_43 ) ;
break;
case V_99 :
if ( F_4 ( V_60 ) ) {
V_43 = F_27 ( V_12 ) ;
V_43 = F_57 ( V_176 , ( T_3 ) V_43 ) ;
}
break;
}
break;
case V_188 :
if ( V_132 -> V_183 != 0 )
goto V_185;
if ( F_35 ( V_60 ) ) {
if ( V_60 -> V_189 )
F_10 ( V_12 , L_22 ) ;
else if ( V_60 -> V_190 )
F_10 ( V_12 , L_23 ) ;
else
F_59 ( V_12 , L_24 ) ;
}
F_60 ( & V_12 -> V_58 ) ;
V_43 = F_34 ( V_12 , V_132 , V_82 ) ;
F_61 ( & V_12 -> V_58 ) ;
break;
case V_191 :
if ( V_132 -> V_183 != V_184 )
goto V_185;
if ( V_12 -> V_41 )
* ( T_1 * ) V_86 -> V_67 = V_12 -> V_41 -> V_76 ;
else
* ( T_1 * ) V_86 -> V_67 = 0 ;
V_43 = F_57 ( V_176 , ( T_3 ) 1 ) ;
break;
case V_192 :
if ( V_132 -> V_183 != V_193 )
goto V_185;
if ( ! V_12 -> V_41 || V_174 >= V_63 )
break;
V_8 = V_12 -> V_41 -> V_64 [ V_174 ] ;
if ( ! V_8 )
break;
if ( V_82 && ! V_8 -> V_47 )
break;
V_43 = V_8 -> V_47 ( V_8 , V_172 , V_82 ) ;
if ( V_43 == V_139 ) {
F_10 ( V_12 ,
L_8 ,
V_140 , V_174 , V_8 -> V_45 ) ;
V_12 -> V_141 ++ ;
F_10 ( V_12 , L_9 ,
V_12 -> V_141 ) ;
}
break;
case V_194 :
if ( V_132 -> V_183 != ( V_184 | V_193 ) )
goto V_185;
if ( ! V_12 -> V_41 || V_174 >= V_63 )
break;
V_8 = V_12 -> V_41 -> V_64 [ V_174 ] ;
if ( ! V_8 )
break;
V_43 = V_8 -> V_195 ? V_8 -> V_195 ( V_8 , V_172 ) : 0 ;
if ( V_43 < 0 )
break;
* ( ( T_1 * ) V_86 -> V_67 ) = V_43 ;
V_43 = F_57 ( V_176 , ( T_3 ) 1 ) ;
break;
case V_196 :
if ( ! F_4 ( V_60 ) )
goto V_185;
if ( V_132 -> V_183 != ( V_184 | V_193 ) )
goto V_185;
V_43 = 2 ;
F_62 ( 0 , V_86 -> V_67 ) ;
if ( ! V_12 -> V_41 || V_174 >= V_63 )
break;
V_8 = V_12 -> V_41 -> V_64 [ V_174 ] ;
if ( ! V_8 )
break;
V_57 = V_8 -> V_197 ? V_8 -> V_197 ( V_8 ) : 0 ;
if ( V_57 < 0 )
break;
F_62 ( V_57 & 0x0000ffff , V_86 -> V_67 ) ;
break;
case V_198 :
case V_199 :
if ( ! F_4 ( V_60 ) )
goto V_185;
if ( V_132 -> V_183 != ( V_200 | V_193 ) )
goto V_185;
switch ( V_82 ) {
case V_201 :
if ( ! V_12 -> V_41 || V_174 >= V_63 )
break;
V_8 = V_12 -> V_41 -> V_64 [ V_174 ] ;
if ( ! V_8 )
break;
V_43 = 0 ;
if ( V_8 -> V_202 )
V_43 = V_8 -> V_202 ( V_8 , V_172 >> 8 ) ;
if ( V_43 < 0 ) {
ERROR ( V_12 ,
L_25 ,
V_43 ) ;
V_43 = 0 ;
}
break;
}
break;
default:
V_185:
F_59 ( V_12 ,
L_26 ,
V_132 -> V_183 , V_132 -> V_181 ,
V_82 , V_172 , V_176 ) ;
switch ( V_132 -> V_183 & V_203 ) {
case V_193 :
if ( ! V_12 -> V_41 || V_174 >= V_63 )
break;
V_8 = V_12 -> V_41 -> V_64 [ V_174 ] ;
break;
case V_204 :
V_178 = ( ( V_172 & 0x80 ) >> 3 ) | ( V_172 & 0x0f ) ;
F_23 (f, &cdev->config->functions, list) {
if ( F_63 ( V_178 , V_8 -> V_130 ) )
break;
}
if ( & V_8 -> V_50 == & V_12 -> V_41 -> V_51 )
V_8 = NULL ;
break;
}
if ( V_8 && V_8 -> V_205 )
V_43 = V_8 -> V_205 ( V_8 , V_132 ) ;
else {
struct V_40 * V_69 ;
V_69 = V_12 -> V_41 ;
if ( V_69 && V_69 -> V_205 )
V_43 = V_69 -> V_205 ( V_69 , V_132 ) ;
}
goto V_49;
}
if ( V_43 >= 0 && V_43 != V_139 ) {
V_86 -> V_169 = V_43 ;
V_86 -> V_179 = V_43 < V_176 ;
V_43 = F_64 ( V_60 -> V_127 , V_86 , V_206 ) ;
if ( V_43 < 0 ) {
F_10 ( V_12 , L_27 , V_43 ) ;
V_86 -> V_57 = 0 ;
F_55 ( V_60 -> V_127 , V_86 ) ;
}
} else if ( V_43 == V_139 && V_176 != 0 ) {
F_65 ( V_12 ,
L_28 ,
V_140 ) ;
}
V_49:
return V_43 ;
}
static void F_66 ( struct V_5 * V_60 )
{
struct V_11 * V_12 = F_3 ( V_60 ) ;
unsigned long V_56 ;
F_14 ( & V_12 -> V_58 , V_56 ) ;
if ( V_12 -> V_41 )
F_32 ( V_12 ) ;
if ( V_154 -> V_207 )
V_154 -> V_207 ( V_12 ) ;
F_16 ( & V_12 -> V_58 , V_56 ) ;
}
static T_4 F_67 ( struct V_208 * V_209 ,
struct V_210 * V_211 ,
char * V_67 )
{
struct V_5 * V_60 = F_68 ( V_209 ) ;
struct V_11 * V_12 = F_3 ( V_60 ) ;
return sprintf ( V_67 , L_29 , V_12 -> V_212 ) ;
}
static void
F_69 ( struct V_5 * V_60 )
{
struct V_11 * V_12 = F_3 ( V_60 ) ;
F_18 ( V_12 -> V_41 ) ;
while ( ! F_42 ( & V_12 -> V_143 ) ) {
struct V_40 * V_69 ;
V_69 = F_43 ( & V_12 -> V_143 ,
struct V_40 , V_50 ) ;
F_45 ( V_12 , V_69 ) ;
}
if ( V_154 -> V_144 )
V_154 -> V_144 ( V_12 ) ;
if ( V_12 -> V_86 ) {
F_70 ( V_12 -> V_86 -> V_67 ) ;
F_71 ( V_60 -> V_127 , V_12 -> V_86 ) ;
}
F_72 ( & V_60 -> V_209 , & V_213 ) ;
F_70 ( V_12 ) ;
F_73 ( V_60 , NULL ) ;
V_154 = NULL ;
}
static T_1 F_74 ( struct V_11 * V_12 , T_1 * V_31 )
{
if ( ! * V_31 ) {
int V_214 = F_51 ( V_12 ) ;
if ( F_53 ( V_214 < 0 ) )
F_75 ( V_12 , L_30 ) ;
else
* V_31 = V_214 ;
}
return * V_31 ;
}
static int F_76 ( struct V_5 * V_60 ,
struct V_215 * V_216 )
{
struct V_11 * V_12 ;
int V_57 = - V_217 ;
V_12 = F_77 ( sizeof *V_12 , V_218 ) ;
if ( ! V_12 )
return V_57 ;
F_78 ( & V_12 -> V_58 ) ;
V_12 -> V_60 = V_60 ;
F_73 ( V_60 , V_12 ) ;
F_41 ( & V_12 -> V_143 ) ;
V_12 -> V_86 = F_79 ( V_60 -> V_127 , V_218 ) ;
if ( ! V_12 -> V_86 )
goto V_219;
V_12 -> V_86 -> V_67 = F_80 ( V_73 , V_218 ) ;
if ( ! V_12 -> V_86 -> V_67 )
goto V_219;
V_12 -> V_86 -> V_180 = F_55 ;
V_60 -> V_127 -> V_170 = V_12 ;
V_12 -> V_220 = V_73 ;
V_12 -> V_216 = V_154 ;
if ( V_80 <= V_221 )
F_81 ( V_60 ) ;
F_44 ( V_12 -> V_60 ) ;
V_57 = V_154 -> V_52 ( V_12 ) ;
if ( V_57 < 0 )
goto V_219;
V_12 -> V_31 = * V_154 -> V_209 ;
if ( V_222 )
V_12 -> V_31 . V_222 = F_24 ( V_222 ) ;
else
V_222 = F_28 ( V_12 -> V_31 . V_222 ) ;
if ( V_223 )
V_12 -> V_31 . V_223 = F_24 ( V_223 ) ;
else
V_223 = F_28 ( V_12 -> V_31 . V_223 ) ;
if ( V_224 )
V_12 -> V_31 . V_224 = F_24 ( V_224 ) ;
else
V_224 = F_28 ( V_12 -> V_31 . V_224 ) ;
if ( V_158 || ! V_12 -> V_31 . V_158 ) {
if ( ! V_158 && ! V_154 -> V_158 &&
! * V_159 )
snprintf ( V_159 ,
sizeof V_159 ,
L_31 ,
F_82 () -> V_225 ,
F_82 () -> V_226 ,
V_60 -> V_45 ) ;
V_12 -> V_157 =
F_74 ( V_12 , & V_12 -> V_31 . V_158 ) ;
}
if ( V_161 || ( ! V_12 -> V_31 . V_161 && V_154 -> V_161 ) )
V_12 -> V_160 =
F_74 ( V_12 , & V_12 -> V_31 . V_161 ) ;
if ( V_163 ||
( ! V_12 -> V_31 . V_163 && V_154 -> V_163 ) )
V_12 -> V_162 =
F_74 ( V_12 , & V_12 -> V_31 . V_163 ) ;
if ( V_154 -> V_227 && ! V_12 -> V_31 . V_163 )
F_75 ( V_12 , L_32 ) ;
V_57 = F_83 ( & V_60 -> V_209 , & V_213 ) ;
if ( V_57 )
goto V_219;
F_36 ( V_12 , L_33 , V_154 -> V_45 ) ;
return 0 ;
V_219:
F_69 ( V_60 ) ;
return V_57 ;
}
static void
F_84 ( struct V_5 * V_60 )
{
struct V_11 * V_12 = F_3 ( V_60 ) ;
struct V_7 * V_8 ;
F_10 ( V_12 , L_34 ) ;
if ( V_12 -> V_41 ) {
F_23 (f, &cdev->config->functions, list) {
if ( V_8 -> V_228 )
V_8 -> V_228 ( V_8 ) ;
}
}
if ( V_154 -> V_228 )
V_154 -> V_228 ( V_12 ) ;
V_12 -> V_212 = 1 ;
F_39 ( V_60 , 2 ) ;
}
static void
F_85 ( struct V_5 * V_60 )
{
struct V_11 * V_12 = F_3 ( V_60 ) ;
struct V_7 * V_8 ;
T_1 V_229 ;
F_10 ( V_12 , L_35 ) ;
if ( V_154 -> V_230 )
V_154 -> V_230 ( V_12 ) ;
if ( V_12 -> V_41 ) {
F_23 (f, &cdev->config->functions, list) {
if ( V_8 -> V_230 )
V_8 -> V_230 ( V_8 ) ;
}
V_229 = V_12 -> V_41 -> V_79 ;
F_39 ( V_60 , V_229 ?
( 2 * V_229 ) : V_80 ) ;
}
V_12 -> V_212 = 0 ;
}
int F_86 ( struct V_231 * V_216 )
{
if ( ! V_216 || ! V_216 -> V_209 || V_154 || ! V_216 -> V_52 )
return - V_44 ;
if ( ! V_216 -> V_45 )
V_216 -> V_45 = L_36 ;
if ( ! V_216 -> V_161 )
V_216 -> V_161 = V_216 -> V_45 ;
V_232 . V_42 = ( char * ) V_216 -> V_45 ;
V_232 . V_216 . V_45 = V_216 -> V_45 ;
V_232 . V_233 = V_216 -> V_233 ;
V_154 = V_216 ;
return F_87 ( & V_232 ) ;
}
void F_88 ( struct V_231 * V_216 )
{
if ( V_154 != V_216 )
return;
F_89 ( & V_232 ) ;
}
void F_90 ( struct V_11 * V_12 )
{
int V_43 ;
struct V_167 * V_86 = V_12 -> V_86 ;
unsigned long V_56 ;
F_10 ( V_12 , L_37 , V_140 ) ;
F_14 ( & V_12 -> V_58 , V_56 ) ;
if ( V_12 -> V_141 == 0 ) {
F_65 ( V_12 , L_38 , V_140 ) ;
} else if ( -- V_12 -> V_141 == 0 ) {
F_10 ( V_12 , L_39 , V_140 ) ;
V_86 -> V_169 = 0 ;
V_43 = F_64 ( V_12 -> V_60 -> V_127 , V_86 , V_206 ) ;
if ( V_43 < 0 ) {
F_10 ( V_12 , L_27 , V_43 ) ;
V_86 -> V_57 = 0 ;
F_55 ( V_12 -> V_60 -> V_127 , V_86 ) ;
}
}
F_16 ( & V_12 -> V_58 , V_56 ) ;
}
