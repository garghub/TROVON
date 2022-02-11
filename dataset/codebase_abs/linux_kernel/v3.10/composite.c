static struct V_1 * * F_1 (
struct V_2 * V_3 )
{
return (struct V_1 * * ) V_3 -> V_4 ;
}
static struct V_5 * *
F_2 ( struct V_5 * * V_6 )
{
for (; * V_6 ; V_6 ++ ) {
if ( ( * V_6 ) -> V_7 == V_8 )
return V_6 ;
}
return NULL ;
}
int F_3 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_15 * V_16 = F_4 ( V_10 ) ;
struct V_17 * V_18 = NULL ;
struct V_5 * * V_19 = NULL ;
struct V_20 * V_21 = NULL ;
int V_22 = 0 ;
struct V_5 * * V_23 ;
if ( ! V_10 || ! V_12 || ! V_14 )
return - V_24 ;
switch ( V_10 -> V_25 ) {
case V_26 :
if ( F_5 ( V_10 ) ) {
V_19 = V_12 -> V_27 ;
V_22 = 1 ;
break;
}
case V_28 :
if ( F_6 ( V_10 ) ) {
V_19 = V_12 -> V_29 ;
break;
}
default:
V_19 = V_12 -> V_30 ;
}
F_7 (speed_desc, d_spd) {
V_18 = (struct V_17 * ) * V_23 ;
if ( V_18 -> V_31 == V_14 -> V_32 )
goto V_33;
}
return - V_24 ;
V_33:
V_14 -> V_34 = F_8 ( V_18 ) ;
V_14 -> V_35 = V_18 ;
V_14 -> V_21 = NULL ;
V_14 -> V_36 = 0 ;
V_14 -> V_37 = 0 ;
if ( ! V_22 )
return 0 ;
V_21 = (struct V_20 * ) * ( ++ V_23 ) ;
if ( ! V_21 ||
( V_21 -> V_7 != V_38 ) )
return - V_24 ;
V_14 -> V_21 = V_21 ;
if ( V_10 -> V_25 == V_26 ) {
switch ( F_9 ( V_14 -> V_35 ) ) {
case V_39 :
V_14 -> V_37 = V_21 -> V_40 & 0x3 ;
case V_41 :
case V_42 :
V_14 -> V_36 = V_21 -> V_43 + 1 ;
break;
default:
if ( V_21 -> V_43 != 0 )
ERROR ( V_16 , L_1 ) ;
V_14 -> V_36 = 1 ;
break;
}
}
return 0 ;
}
int F_10 ( struct V_44 * V_45 ,
struct V_11 * V_46 )
{
int V_47 = - V_48 ;
F_11 ( V_45 -> V_16 , L_2 ,
V_46 -> V_49 , V_46 ,
V_45 -> V_50 , V_45 ) ;
if ( ! V_46 -> V_51 || ! V_46 -> V_52 )
goto V_53;
V_46 -> V_45 = V_45 ;
F_12 ( & V_46 -> V_54 , & V_45 -> V_55 ) ;
if ( V_46 -> V_56 ) {
V_47 = V_46 -> V_56 ( V_45 , V_46 ) ;
if ( V_47 < 0 ) {
F_13 ( & V_46 -> V_54 ) ;
V_46 -> V_45 = NULL ;
}
} else
V_47 = 0 ;
if ( ! V_45 -> V_57 && V_46 -> V_30 )
V_45 -> V_57 = true ;
if ( ! V_45 -> V_58 && V_46 -> V_29 )
V_45 -> V_58 = true ;
if ( ! V_45 -> V_59 && V_46 -> V_27 )
V_45 -> V_59 = true ;
V_53:
if ( V_47 )
F_11 ( V_45 -> V_16 , L_3 ,
V_46 -> V_49 , V_46 , V_47 ) ;
return V_47 ;
}
void F_14 ( struct V_44 * V_60 , struct V_11 * V_12 )
{
if ( V_12 -> V_52 )
V_12 -> V_52 ( V_12 ) ;
F_15 ( V_12 -> V_61 , 32 ) ;
F_13 ( & V_12 -> V_54 ) ;
if ( V_12 -> V_62 )
V_12 -> V_62 ( V_60 , V_12 ) ;
}
int F_16 ( struct V_11 * V_46 )
{
struct V_15 * V_16 = V_46 -> V_45 -> V_16 ;
unsigned long V_63 ;
int V_64 = 0 ;
F_17 ( & V_16 -> V_65 , V_63 ) ;
if ( V_16 -> V_66 == 0 )
V_64 = F_18 ( V_16 -> V_67 ) ;
if ( V_64 == 0 )
V_16 -> V_66 ++ ;
F_19 ( & V_16 -> V_65 , V_63 ) ;
return V_64 ;
}
int F_20 ( struct V_11 * V_46 )
{
struct V_15 * V_16 = V_46 -> V_45 -> V_16 ;
unsigned long V_63 ;
int V_64 = 0 ;
F_17 ( & V_16 -> V_65 , V_63 ) ;
if ( F_21 ( V_16 -> V_66 == 0 ) )
V_64 = - V_48 ;
else {
V_16 -> V_66 -- ;
if ( V_16 -> V_66 == 0 )
V_64 = F_22 ( V_16 -> V_67 ) ;
}
F_19 ( & V_16 -> V_65 , V_63 ) ;
return V_64 ;
}
int F_23 ( struct V_44 * V_45 ,
struct V_11 * V_46 )
{
unsigned V_68 = V_45 -> V_69 ;
if ( V_68 < V_70 ) {
V_45 -> V_71 [ V_68 ] = V_46 ;
V_45 -> V_69 = V_68 + 1 ;
return V_68 ;
}
return - V_72 ;
}
static T_1 F_24 ( enum V_73 V_25 ,
struct V_44 * V_60 )
{
unsigned V_74 ;
if ( V_60 -> V_75 )
V_74 = V_60 -> V_75 ;
else
V_74 = V_76 ;
if ( ! V_74 )
return 0 ;
switch ( V_25 ) {
case V_26 :
return F_25 ( V_74 , 8 ) ;
default:
return F_25 ( V_74 , 2 ) ;
} ;
}
static int F_26 ( struct V_44 * V_45 ,
enum V_73 V_25 , void * V_77 , T_1 type )
{
struct V_78 * V_60 = V_77 ;
void * V_79 = V_77 + V_80 ;
int V_81 ;
struct V_11 * V_12 ;
int V_64 ;
V_81 = V_82 - V_80 ;
V_60 = V_77 ;
V_60 -> V_83 = V_80 ;
V_60 -> V_7 = type ;
V_60 -> V_84 = V_45 -> V_69 ;
V_60 -> V_85 = V_45 -> V_85 ;
V_60 -> V_86 = V_45 -> V_86 ;
V_60 -> V_40 = V_87 | V_45 -> V_40 ;
V_60 -> V_88 = F_24 ( V_25 , V_45 ) ;
if ( V_45 -> V_89 ) {
V_64 = F_27 ( V_79 , V_81 ,
V_45 -> V_89 ) ;
if ( V_64 < 0 )
return V_64 ;
V_81 -= V_64 ;
V_79 += V_64 ;
}
F_28 (f, &config->functions, list) {
struct V_5 * * V_89 ;
switch ( V_25 ) {
case V_26 :
V_89 = V_12 -> V_27 ;
break;
case V_28 :
V_89 = V_12 -> V_29 ;
break;
default:
V_89 = V_12 -> V_30 ;
}
if ( ! V_89 )
continue;
V_64 = F_27 ( V_79 , V_81 ,
( const struct V_5 * * ) V_89 ) ;
if ( V_64 < 0 )
return V_64 ;
V_81 -= V_64 ;
V_79 += V_64 ;
}
V_81 = V_79 - V_77 ;
V_60 -> V_90 = F_29 ( V_81 ) ;
return V_81 ;
}
static int F_30 ( struct V_15 * V_16 , unsigned V_91 )
{
struct V_9 * V_67 = V_16 -> V_67 ;
struct V_44 * V_60 ;
T_1 type = V_91 >> 8 ;
enum V_73 V_25 = V_92 ;
if ( V_67 -> V_25 == V_26 )
V_25 = V_67 -> V_25 ;
else if ( F_6 ( V_67 ) ) {
int V_93 = 0 ;
if ( V_67 -> V_25 == V_28 )
V_93 = 1 ;
if ( type == V_94 )
V_93 = ! V_93 ;
if ( V_93 )
V_25 = V_28 ;
}
V_91 &= 0xff ;
F_28 (c, &cdev->configs, list) {
switch ( V_25 ) {
case V_26 :
if ( ! V_60 -> V_59 )
continue;
break;
case V_28 :
if ( ! V_60 -> V_58 )
continue;
break;
default:
if ( ! V_60 -> V_57 )
continue;
}
if ( V_91 == 0 )
return F_26 ( V_60 , V_25 , V_16 -> V_95 -> V_77 , type ) ;
V_91 -- ;
}
return - V_48 ;
}
static int F_31 ( struct V_15 * V_16 , unsigned type )
{
struct V_9 * V_67 = V_16 -> V_67 ;
struct V_44 * V_60 ;
unsigned V_96 = 0 ;
int V_93 = 0 ;
int V_97 = 0 ;
if ( F_6 ( V_67 ) ) {
if ( V_67 -> V_25 == V_28 )
V_93 = 1 ;
if ( V_67 -> V_25 == V_26 )
V_97 = 1 ;
if ( type == V_98 )
V_93 = ! V_93 ;
}
F_28 (c, &cdev->configs, list) {
if ( V_97 ) {
if ( ! V_60 -> V_59 )
continue;
} else if ( V_93 ) {
if ( ! V_60 -> V_58 )
continue;
} else {
if ( ! V_60 -> V_57 )
continue;
}
V_96 ++ ;
}
return V_96 ;
}
static int F_32 ( struct V_15 * V_16 )
{
struct V_99 * V_100 ;
struct V_101 * V_102 ;
struct V_103 V_104 ;
struct V_105 * V_106 = V_16 -> V_95 -> V_77 ;
V_106 -> V_83 = V_107 ;
V_106 -> V_7 = V_108 ;
V_106 -> V_90 = F_29 ( V_107 ) ;
V_106 -> V_109 = 0 ;
V_100 = V_16 -> V_95 -> V_77 + F_33 ( V_106 -> V_90 ) ;
V_106 -> V_109 ++ ;
F_34 ( & V_106 -> V_90 , V_110 ) ;
V_100 -> V_83 = V_110 ;
V_100 -> V_7 = V_111 ;
V_100 -> V_112 = V_113 ;
V_100 -> V_40 = F_35 ( V_114 ) ;
V_102 = V_16 -> V_95 -> V_77 + F_33 ( V_106 -> V_90 ) ;
V_106 -> V_109 ++ ;
F_34 ( & V_106 -> V_90 , V_115 ) ;
V_102 -> V_83 = V_115 ;
V_102 -> V_7 = V_111 ;
V_102 -> V_112 = V_116 ;
V_102 -> V_40 = 0 ;
V_102 -> V_117 = F_29 ( V_118 |
V_119 |
V_120 |
V_121 ) ;
V_102 -> V_122 = V_118 ;
if ( V_16 -> V_67 -> V_123 -> V_124 )
V_16 -> V_67 -> V_123 -> V_124 ( & V_104 ) ;
else {
V_104 . V_125 = V_126 ;
V_104 . V_127 =
F_29 ( V_128 ) ;
}
V_102 -> V_125 = V_104 . V_125 ;
V_102 -> V_127 = V_104 . V_127 ;
return F_33 ( V_106 -> V_90 ) ;
}
static void F_36 ( struct V_15 * V_16 )
{
struct V_129 * V_130 = V_16 -> V_95 -> V_77 ;
V_130 -> V_83 = sizeof( * V_130 ) ;
V_130 -> V_7 = V_98 ;
V_130 -> V_131 = V_16 -> V_35 . V_131 ;
V_130 -> V_132 = V_16 -> V_35 . V_132 ;
V_130 -> V_133 = V_16 -> V_35 . V_133 ;
V_130 -> V_134 = V_16 -> V_35 . V_134 ;
V_130 -> V_135 = V_16 -> V_67 -> V_136 -> V_34 ;
V_130 -> V_137 = F_31 ( V_16 , V_98 ) ;
V_130 -> V_138 = 0 ;
}
static void F_37 ( struct V_15 * V_16 )
{
struct V_11 * V_12 ;
F_11 ( V_16 , L_4 ) ;
F_28 (f, &cdev->config->functions, list) {
if ( V_12 -> V_52 )
V_12 -> V_52 ( V_12 ) ;
F_15 ( V_12 -> V_61 , 32 ) ;
}
V_16 -> V_45 = NULL ;
}
static int F_38 ( struct V_15 * V_16 ,
const struct V_139 * V_140 , unsigned V_141 )
{
struct V_9 * V_67 = V_16 -> V_67 ;
struct V_44 * V_60 = NULL ;
int V_142 = - V_48 ;
unsigned V_143 = F_39 ( V_67 ) ? 8 : 100 ;
int V_144 ;
if ( V_141 ) {
F_28 (c, &cdev->configs, list) {
if ( V_60 -> V_85 == V_141 ) {
if ( V_16 -> V_45 )
F_37 ( V_16 ) ;
V_142 = 0 ;
break;
}
}
if ( V_142 < 0 )
goto V_53;
} else {
if ( V_16 -> V_45 )
F_37 ( V_16 ) ;
V_142 = 0 ;
}
F_40 ( V_16 , L_5 ,
F_41 ( V_67 -> V_25 ) ,
V_141 , V_60 ? V_60 -> V_50 : L_6 ) ;
if ( ! V_60 )
goto V_53;
V_16 -> V_45 = V_60 ;
for ( V_144 = 0 ; V_144 < V_70 ; V_144 ++ ) {
struct V_11 * V_12 = V_60 -> V_71 [ V_144 ] ;
struct V_5 * * V_89 ;
if ( ! V_12 )
break;
switch ( V_67 -> V_25 ) {
case V_26 :
V_89 = V_12 -> V_27 ;
break;
case V_28 :
V_89 = V_12 -> V_29 ;
break;
default:
V_89 = V_12 -> V_30 ;
}
for (; * V_89 ; ++ V_89 ) {
struct V_17 * V_145 ;
int V_146 ;
if ( ( * V_89 ) -> V_7 != V_8 )
continue;
V_145 = (struct V_17 * ) * V_89 ;
V_146 = ( ( V_145 -> V_31 & 0x80 ) >> 3 )
| ( V_145 -> V_31 & 0x0f ) ;
F_42 ( V_146 , V_12 -> V_61 ) ;
}
V_142 = V_12 -> V_51 ( V_12 , V_144 , 0 ) ;
if ( V_142 < 0 ) {
F_11 ( V_16 , L_7 ,
V_144 , V_12 -> V_49 , V_12 , V_142 ) ;
F_37 ( V_16 ) ;
goto V_53;
}
if ( V_142 == V_147 ) {
F_11 ( V_16 ,
L_8 ,
V_148 , V_144 , V_12 -> V_49 ) ;
V_16 -> V_149 ++ ;
F_11 ( V_16 , L_9 ,
V_16 -> V_149 ) ;
}
}
V_143 = V_60 -> V_75 ? V_60 -> V_75 : V_76 ;
V_53:
F_43 ( V_67 , V_143 ) ;
if ( V_142 >= 0 && V_16 -> V_149 )
V_142 = V_147 ;
return V_142 ;
}
int F_44 ( struct V_15 * V_16 ,
struct V_44 * V_45 )
{
struct V_44 * V_60 ;
if ( ! V_45 -> V_85 )
return - V_48 ;
F_28 (c, &cdev->configs, list) {
if ( V_60 -> V_85 == V_45 -> V_85 )
return - V_150 ;
}
V_45 -> V_16 = V_16 ;
F_12 ( & V_45 -> V_54 , & V_16 -> V_151 ) ;
F_45 ( & V_45 -> V_55 ) ;
V_45 -> V_69 = 0 ;
memset ( V_45 -> V_71 , 0 , sizeof( V_45 -> V_71 ) ) ;
return 0 ;
}
int F_46 ( struct V_15 * V_16 ,
struct V_44 * V_45 ,
int (* V_56)( struct V_44 * ) )
{
int V_64 = - V_48 ;
if ( ! V_56 )
goto V_53;
F_11 ( V_16 , L_10 ,
V_45 -> V_85 ,
V_45 -> V_50 , V_45 ) ;
V_64 = F_44 ( V_16 , V_45 ) ;
if ( V_64 )
goto V_53;
V_64 = V_56 ( V_45 ) ;
if ( V_64 < 0 ) {
while ( ! F_47 ( & V_45 -> V_55 ) ) {
struct V_11 * V_12 ;
V_12 = F_48 ( & V_45 -> V_55 ,
struct V_11 , V_54 ) ;
F_13 ( & V_12 -> V_54 ) ;
if ( V_12 -> V_62 ) {
F_11 ( V_16 , L_11 ,
V_12 -> V_49 , V_12 ) ;
V_12 -> V_62 ( V_45 , V_12 ) ;
}
}
F_13 ( & V_45 -> V_54 ) ;
V_45 -> V_16 = NULL ;
} else {
unsigned V_152 ;
F_11 ( V_16 , L_12 ,
V_45 -> V_85 , V_45 ,
V_45 -> V_59 ? L_13 : L_14 ,
V_45 -> V_58 ? L_15 : L_14 ,
V_45 -> V_57
? ( F_6 ( V_16 -> V_67 )
? L_16
: L_17 )
: L_14 ) ;
for ( V_152 = 0 ; V_152 < V_70 ; V_152 ++ ) {
struct V_11 * V_12 = V_45 -> V_71 [ V_152 ] ;
if ( ! V_12 )
continue;
F_11 ( V_16 , L_18 ,
V_152 , V_12 -> V_49 , V_12 ) ;
}
}
F_49 ( V_16 -> V_67 ) ;
V_53:
if ( V_64 )
F_11 ( V_16 , L_19 , V_45 -> V_50 ,
V_45 -> V_85 , V_64 ) ;
return V_64 ;
}
static void F_50 ( struct V_15 * V_16 ,
struct V_44 * V_45 )
{
while ( ! F_47 ( & V_45 -> V_55 ) ) {
struct V_11 * V_12 ;
V_12 = F_48 ( & V_45 -> V_55 ,
struct V_11 , V_54 ) ;
F_13 ( & V_12 -> V_54 ) ;
if ( V_12 -> V_62 ) {
F_11 ( V_16 , L_11 , V_12 -> V_49 , V_12 ) ;
V_12 -> V_62 ( V_45 , V_12 ) ;
}
}
F_13 ( & V_45 -> V_54 ) ;
if ( V_45 -> V_62 ) {
F_11 ( V_16 , L_20 , V_45 -> V_50 , V_45 ) ;
V_45 -> V_62 ( V_45 ) ;
}
}
void F_51 ( struct V_15 * V_16 ,
struct V_44 * V_45 )
{
unsigned long V_63 ;
F_17 ( & V_16 -> V_65 , V_63 ) ;
if ( V_16 -> V_45 == V_45 )
F_37 ( V_16 ) ;
F_19 ( & V_16 -> V_65 , V_63 ) ;
F_50 ( V_16 , V_45 ) ;
}
static void F_52 ( struct V_1 * * V_153 , T_2 * V_77 )
{
const struct V_1 * V_154 ;
T_2 V_155 ;
T_2 * V_144 ;
while ( * V_153 ) {
V_154 = * V_153 ;
V_155 = F_29 ( V_154 -> V_155 ) ;
for ( V_144 = V_77 ; * V_144 && V_144 < & V_77 [ 126 ] ; V_144 ++ ) {
if ( * V_144 == V_155 )
goto V_156;
}
* V_144 ++ = V_155 ;
V_156:
V_153 ++ ;
}
}
static int F_53 (
struct V_1 * * V_153 ,
void * V_77 ,
T_3 V_155 ,
int V_68
)
{
struct V_1 * V_154 ;
int V_47 ;
while ( * V_153 ) {
V_154 = * V_153 ++ ;
if ( V_154 -> V_155 != V_155 )
continue;
V_47 = F_54 ( V_154 , V_68 , V_77 ) ;
if ( V_47 > 0 )
return V_47 ;
}
return - V_48 ;
}
static int F_55 ( struct V_15 * V_16 ,
void * V_77 , T_3 V_155 , int V_68 )
{
struct V_157 * V_158 = V_16 -> V_159 ;
struct V_2 * V_3 ;
struct V_44 * V_60 ;
struct V_11 * V_12 ;
int V_81 ;
if ( V_68 == 0 ) {
struct V_160 * V_154 = V_77 ;
struct V_1 * * V_153 ;
memset ( V_154 , 0 , 256 ) ;
V_154 -> V_7 = V_161 ;
V_153 = V_158 -> V_162 ;
if ( V_153 )
F_52 ( V_153 , V_154 -> V_163 ) ;
F_28 (c, &cdev->configs, list) {
V_153 = V_60 -> V_162 ;
if ( V_153 )
F_52 ( V_153 , V_154 -> V_163 ) ;
F_28 (f, &c->functions, list) {
V_153 = V_12 -> V_162 ;
if ( V_153 )
F_52 ( V_153 , V_154 -> V_163 ) ;
}
}
F_28 (uc, &cdev->gstrings, list) {
struct V_1 * * V_153 ;
V_153 = F_1 ( V_3 ) ;
F_52 ( V_153 , V_154 -> V_163 ) ;
}
for ( V_81 = 0 ; V_81 <= 126 && V_154 -> V_163 [ V_81 ] ; V_81 ++ )
continue;
if ( ! V_81 )
return - V_48 ;
V_154 -> V_83 = 2 * ( V_81 + 1 ) ;
return V_154 -> V_83 ;
}
F_28 (uc, &cdev->gstrings, list) {
struct V_1 * * V_153 ;
V_153 = F_1 ( V_3 ) ;
V_81 = F_53 ( V_153 , V_77 , V_155 , V_68 ) ;
if ( V_81 > 0 )
return V_81 ;
}
if ( V_158 -> V_162 ) {
V_81 = F_53 ( V_158 -> V_162 , V_77 , V_155 , V_68 ) ;
if ( V_81 > 0 )
return V_81 ;
}
F_28 (c, &cdev->configs, list) {
if ( V_60 -> V_162 ) {
V_81 = F_53 ( V_60 -> V_162 , V_77 , V_155 , V_68 ) ;
if ( V_81 > 0 )
return V_81 ;
}
F_28 (f, &c->functions, list) {
if ( ! V_12 -> V_162 )
continue;
V_81 = F_53 ( V_12 -> V_162 , V_77 , V_155 , V_68 ) ;
if ( V_81 > 0 )
return V_81 ;
}
}
return - V_48 ;
}
int F_56 ( struct V_15 * V_16 )
{
if ( V_16 -> V_164 < 254 ) {
V_16 -> V_164 ++ ;
return V_16 -> V_164 ;
}
return - V_72 ;
}
int F_57 ( struct V_15 * V_16 , struct V_165 * V_166 )
{
int V_79 = V_16 -> V_164 ;
for (; V_166 -> V_154 ; ++ V_166 ) {
if ( F_58 ( V_79 >= 254 ) )
return - V_72 ;
V_166 -> V_68 = ++ V_79 ;
}
V_16 -> V_164 = V_79 ;
return 0 ;
}
static struct V_2 * F_59 (
struct V_1 * * V_153 , unsigned V_167 ,
unsigned V_168 )
{
struct V_2 * V_3 ;
struct V_1 * * V_169 ;
struct V_1 * V_170 ;
struct V_165 * V_154 ;
unsigned V_171 ;
unsigned V_172 ;
unsigned V_173 ;
void * V_4 ;
V_171 = sizeof( * V_3 ) ;
V_171 += sizeof( void * ) * ( V_167 + 1 ) ;
V_171 += sizeof( struct V_1 ) * V_167 ;
V_171 += sizeof( struct V_165 ) * ( V_168 + 1 ) * ( V_167 ) ;
V_3 = F_60 ( V_171 , V_174 ) ;
if ( ! V_3 )
return F_61 ( - V_175 ) ;
V_169 = F_1 ( V_3 ) ;
V_4 = V_3 -> V_4 ;
V_4 += sizeof( void * ) * ( V_167 + 1 ) ;
for ( V_172 = 0 ; V_172 < V_167 ; V_172 ++ ) {
struct V_165 * V_176 ;
V_169 [ V_172 ] = V_4 ;
V_170 = V_169 [ V_172 ] ;
V_4 += sizeof( struct V_1 ) ;
V_170 -> V_155 = V_153 [ V_172 ] -> V_155 ;
V_170 -> V_162 = V_4 ;
V_176 = V_153 [ V_172 ] -> V_162 ;
for ( V_173 = 0 ; V_173 < V_168 ; V_173 ++ ) {
V_154 = V_4 ;
V_4 += sizeof( struct V_165 ) ;
if ( V_176 -> V_154 )
V_154 -> V_154 = V_176 -> V_154 ;
else
V_154 -> V_154 = L_14 ;
V_176 ++ ;
}
V_154 = V_4 ;
V_154 -> V_154 = NULL ;
V_4 += sizeof( struct V_165 ) ;
}
V_169 [ V_172 ] = NULL ;
return V_3 ;
}
struct V_165 * F_62 ( struct V_15 * V_16 ,
struct V_1 * * V_153 , unsigned V_168 )
{
struct V_2 * V_3 ;
struct V_1 * * V_172 ;
unsigned V_167 = 0 ;
unsigned V_152 ;
int V_177 ;
for ( V_152 = 0 ; V_153 [ V_152 ] ; V_152 ++ )
V_167 ++ ;
if ( ! V_167 )
return F_61 ( - V_48 ) ;
V_3 = F_59 ( V_153 , V_167 , V_168 ) ;
if ( F_63 ( V_3 ) )
return F_61 ( F_64 ( V_3 ) ) ;
V_172 = F_1 ( V_3 ) ;
V_177 = F_57 ( V_16 , V_172 [ 0 ] -> V_162 ) ;
if ( V_177 )
goto V_178;
for ( V_152 = 1 ; V_152 < V_167 ; V_152 ++ ) {
struct V_165 * V_179 ;
struct V_165 * V_154 ;
unsigned V_180 ;
V_179 = V_172 [ 0 ] -> V_162 ;
V_154 = V_172 [ V_152 ] -> V_162 ;
for ( V_180 = 0 ; V_180 < V_168 ; V_180 ++ ) {
V_154 -> V_68 = V_179 -> V_68 ;
V_154 ++ ;
V_179 ++ ;
}
}
F_12 ( & V_3 -> V_54 , & V_16 -> V_181 ) ;
return V_172 [ 0 ] -> V_162 ;
V_178:
F_65 ( V_3 ) ;
return F_61 ( V_177 ) ;
}
int F_66 ( struct V_15 * V_60 , unsigned V_180 )
{
unsigned V_79 = V_60 -> V_164 ;
if ( F_58 ( V_180 > 254 || ( unsigned ) V_79 + V_180 > 254 ) )
return - V_72 ;
V_60 -> V_164 += V_180 ;
return V_79 + 1 ;
}
static void F_67 ( struct V_13 * V_145 , struct V_182 * V_95 )
{
if ( V_95 -> V_64 || V_95 -> V_183 != V_95 -> V_184 )
F_11 ( (struct V_15 * ) V_145 -> V_185 ,
L_21 ,
V_95 -> V_64 , V_95 -> V_183 , V_95 -> V_184 ) ;
}
int
F_68 ( struct V_9 * V_67 , const struct V_139 * V_140 )
{
struct V_15 * V_16 = F_4 ( V_67 ) ;
struct V_182 * V_95 = V_16 -> V_95 ;
int V_47 = - V_186 ;
int V_64 = 0 ;
T_3 V_187 = F_33 ( V_140 -> V_188 ) ;
T_1 V_189 = V_187 & 0xFF ;
T_3 V_91 = F_33 ( V_140 -> V_190 ) ;
T_3 V_191 = F_33 ( V_140 -> V_192 ) ;
struct V_11 * V_12 = NULL ;
T_1 V_193 ;
V_95 -> V_194 = 0 ;
V_95 -> V_195 = F_67 ;
V_95 -> V_184 = 0 ;
V_67 -> V_136 -> V_185 = V_16 ;
switch ( V_140 -> V_196 ) {
case V_197 :
if ( V_140 -> V_198 != V_199 )
goto V_200;
switch ( V_91 >> 8 ) {
case V_201 :
V_16 -> V_35 . V_137 =
F_31 ( V_16 , V_201 ) ;
V_16 -> V_35 . V_135 =
V_16 -> V_67 -> V_136 -> V_34 ;
if ( F_5 ( V_67 ) ) {
if ( V_67 -> V_25 >= V_26 ) {
V_16 -> V_35 . V_131 = F_29 ( 0x0300 ) ;
V_16 -> V_35 . V_135 = 9 ;
} else {
V_16 -> V_35 . V_131 = F_29 ( 0x0210 ) ;
}
}
V_47 = F_69 ( V_191 , ( T_3 ) sizeof V_16 -> V_35 ) ;
memcpy ( V_95 -> V_77 , & V_16 -> V_35 , V_47 ) ;
break;
case V_98 :
if ( ! F_6 ( V_67 ) ||
V_67 -> V_25 >= V_26 )
break;
F_36 ( V_16 ) ;
V_47 = F_70 ( int , V_191 ,
sizeof( struct V_129 ) ) ;
break;
case V_94 :
if ( ! F_6 ( V_67 ) ||
V_67 -> V_25 >= V_26 )
break;
case V_202 :
V_47 = F_30 ( V_16 , V_91 ) ;
if ( V_47 >= 0 )
V_47 = F_69 ( V_191 , ( T_3 ) V_47 ) ;
break;
case V_161 :
V_47 = F_55 ( V_16 , V_95 -> V_77 ,
V_187 , V_91 & 0xff ) ;
if ( V_47 >= 0 )
V_47 = F_69 ( V_191 , ( T_3 ) V_47 ) ;
break;
case V_108 :
if ( F_5 ( V_67 ) ) {
V_47 = F_32 ( V_16 ) ;
V_47 = F_69 ( V_191 , ( T_3 ) V_47 ) ;
}
break;
}
break;
case V_203 :
if ( V_140 -> V_198 != 0 )
goto V_200;
if ( F_39 ( V_67 ) ) {
if ( V_67 -> V_204 )
F_11 ( V_16 , L_22 ) ;
else if ( V_67 -> V_205 )
F_11 ( V_16 , L_23 ) ;
else
F_71 ( V_16 , L_24 ) ;
}
F_72 ( & V_16 -> V_65 ) ;
V_47 = F_38 ( V_16 , V_140 , V_91 ) ;
F_73 ( & V_16 -> V_65 ) ;
break;
case V_206 :
if ( V_140 -> V_198 != V_199 )
goto V_200;
if ( V_16 -> V_45 )
* ( T_1 * ) V_95 -> V_77 = V_16 -> V_45 -> V_85 ;
else
* ( T_1 * ) V_95 -> V_77 = 0 ;
V_47 = F_69 ( V_191 , ( T_3 ) 1 ) ;
break;
case V_207 :
if ( V_140 -> V_198 != V_208 )
goto V_200;
if ( ! V_16 -> V_45 || V_189 >= V_70 )
break;
V_12 = V_16 -> V_45 -> V_71 [ V_189 ] ;
if ( ! V_12 )
break;
if ( V_91 && ! V_12 -> V_51 )
break;
V_47 = V_12 -> V_51 ( V_12 , V_187 , V_91 ) ;
if ( V_47 == V_147 ) {
F_11 ( V_16 ,
L_8 ,
V_148 , V_189 , V_12 -> V_49 ) ;
V_16 -> V_149 ++ ;
F_11 ( V_16 , L_9 ,
V_16 -> V_149 ) ;
}
break;
case V_209 :
if ( V_140 -> V_198 != ( V_199 | V_208 ) )
goto V_200;
if ( ! V_16 -> V_45 || V_189 >= V_70 )
break;
V_12 = V_16 -> V_45 -> V_71 [ V_189 ] ;
if ( ! V_12 )
break;
V_47 = V_12 -> V_210 ? V_12 -> V_210 ( V_12 , V_187 ) : 0 ;
if ( V_47 < 0 )
break;
* ( ( T_1 * ) V_95 -> V_77 ) = V_47 ;
V_47 = F_69 ( V_191 , ( T_3 ) 1 ) ;
break;
case V_211 :
if ( ! F_5 ( V_67 ) )
goto V_200;
if ( V_140 -> V_198 != ( V_199 | V_208 ) )
goto V_200;
V_47 = 2 ;
F_74 ( 0 , V_95 -> V_77 ) ;
if ( ! V_16 -> V_45 || V_189 >= V_70 )
break;
V_12 = V_16 -> V_45 -> V_71 [ V_189 ] ;
if ( ! V_12 )
break;
V_64 = V_12 -> V_212 ? V_12 -> V_212 ( V_12 ) : 0 ;
if ( V_64 < 0 )
break;
F_74 ( V_64 & 0x0000ffff , V_95 -> V_77 ) ;
break;
case V_213 :
case V_214 :
if ( ! F_5 ( V_67 ) )
goto V_200;
if ( V_140 -> V_198 != ( V_215 | V_208 ) )
goto V_200;
switch ( V_91 ) {
case V_216 :
if ( ! V_16 -> V_45 || V_189 >= V_70 )
break;
V_12 = V_16 -> V_45 -> V_71 [ V_189 ] ;
if ( ! V_12 )
break;
V_47 = 0 ;
if ( V_12 -> V_217 )
V_47 = V_12 -> V_217 ( V_12 , V_187 >> 8 ) ;
if ( V_47 < 0 ) {
ERROR ( V_16 ,
L_25 ,
V_47 ) ;
V_47 = 0 ;
}
break;
}
break;
default:
V_200:
F_71 ( V_16 ,
L_26 ,
V_140 -> V_198 , V_140 -> V_196 ,
V_91 , V_187 , V_191 ) ;
switch ( V_140 -> V_198 & V_218 ) {
case V_208 :
if ( ! V_16 -> V_45 || V_189 >= V_70 )
break;
V_12 = V_16 -> V_45 -> V_71 [ V_189 ] ;
break;
case V_219 :
V_193 = ( ( V_187 & 0x80 ) >> 3 ) | ( V_187 & 0x0f ) ;
F_28 (f, &cdev->config->functions, list) {
if ( F_75 ( V_193 , V_12 -> V_61 ) )
break;
}
if ( & V_12 -> V_54 == & V_16 -> V_45 -> V_55 )
V_12 = NULL ;
break;
}
if ( V_12 && V_12 -> V_220 )
V_47 = V_12 -> V_220 ( V_12 , V_140 ) ;
else {
struct V_44 * V_60 ;
V_60 = V_16 -> V_45 ;
if ( V_60 && V_60 -> V_220 )
V_47 = V_60 -> V_220 ( V_60 , V_140 ) ;
}
goto V_53;
}
if ( V_47 >= 0 && V_47 != V_147 ) {
V_95 -> V_184 = V_47 ;
V_95 -> V_194 = V_47 < V_191 ;
V_47 = F_76 ( V_67 -> V_136 , V_95 , V_221 ) ;
if ( V_47 < 0 ) {
F_11 ( V_16 , L_27 , V_47 ) ;
V_95 -> V_64 = 0 ;
F_67 ( V_67 -> V_136 , V_95 ) ;
}
} else if ( V_47 == V_147 && V_191 != 0 ) {
F_77 ( V_16 ,
L_28 ,
V_148 ) ;
}
V_53:
return V_47 ;
}
void F_78 ( struct V_9 * V_67 )
{
struct V_15 * V_16 = F_4 ( V_67 ) ;
unsigned long V_63 ;
F_17 ( & V_16 -> V_65 , V_63 ) ;
if ( V_16 -> V_45 )
F_37 ( V_16 ) ;
if ( V_16 -> V_159 -> V_222 )
V_16 -> V_159 -> V_222 ( V_16 ) ;
F_19 ( & V_16 -> V_65 , V_63 ) ;
}
static T_4 F_79 ( struct V_223 * V_224 ,
struct V_225 * V_226 ,
char * V_77 )
{
struct V_9 * V_67 = F_80 ( V_224 ) ;
struct V_15 * V_16 = F_4 ( V_67 ) ;
return sprintf ( V_77 , L_29 , V_16 -> V_227 ) ;
}
static void F_81 ( struct V_9 * V_67 , bool V_228 )
{
struct V_15 * V_16 = F_4 ( V_67 ) ;
F_21 ( V_16 -> V_45 ) ;
while ( ! F_47 ( & V_16 -> V_151 ) ) {
struct V_44 * V_60 ;
V_60 = F_48 ( & V_16 -> V_151 ,
struct V_44 , V_54 ) ;
F_50 ( V_16 , V_60 ) ;
}
if ( V_16 -> V_159 -> V_62 && V_228 )
V_16 -> V_159 -> V_62 ( V_16 ) ;
F_82 ( V_16 ) ;
F_65 ( V_16 -> V_229 ) ;
F_65 ( V_16 ) ;
F_83 ( V_67 , NULL ) ;
}
static void F_84 ( struct V_9 * V_67 )
{
F_81 ( V_67 , true ) ;
}
static void F_85 ( struct V_230 * V_231 ,
const struct V_230 * V_232 )
{
T_2 V_233 ;
T_2 V_234 ;
T_2 V_235 ;
T_1 V_236 ;
T_1 V_237 ;
T_1 V_238 ;
V_233 = V_231 -> V_233 ;
V_234 = V_231 -> V_234 ;
V_235 = V_231 -> V_235 ;
V_236 = V_231 -> V_236 ;
V_237 = V_231 -> V_237 ;
V_238 = V_231 -> V_238 ;
* V_231 = * V_232 ;
if ( V_233 )
V_231 -> V_233 = V_233 ;
if ( V_234 )
V_231 -> V_234 = V_234 ;
if ( V_235 )
V_231 -> V_235 = V_235 ;
else
V_231 -> V_235 = F_29 ( F_86 () ) ;
if ( V_236 )
V_231 -> V_236 = V_236 ;
if ( V_237 )
V_231 -> V_237 = V_237 ;
if ( V_238 )
V_231 -> V_238 = V_238 ;
}
int F_87 ( struct V_157 * V_158 ,
struct V_15 * V_16 )
{
struct V_9 * V_67 = V_16 -> V_67 ;
int V_177 = - V_175 ;
V_16 -> V_95 = F_88 ( V_67 -> V_136 , V_174 ) ;
if ( ! V_16 -> V_95 )
return - V_175 ;
V_16 -> V_95 -> V_77 = F_60 ( V_82 , V_174 ) ;
if ( ! V_16 -> V_95 -> V_77 )
goto V_239;
V_177 = F_89 ( & V_67 -> V_224 , & V_240 ) ;
if ( V_177 )
goto V_241;
V_16 -> V_95 -> V_195 = F_67 ;
V_67 -> V_136 -> V_185 = V_16 ;
V_16 -> V_159 = V_158 ;
if ( V_76 <= V_242 )
F_90 ( V_67 ) ;
F_49 ( V_67 ) ;
return 0 ;
V_241:
F_65 ( V_16 -> V_95 -> V_77 ) ;
V_239:
F_91 ( V_67 -> V_136 , V_16 -> V_95 ) ;
V_16 -> V_95 = NULL ;
return V_177 ;
}
void F_82 ( struct V_15 * V_16 )
{
struct V_2 * V_3 , * V_144 ;
F_92 (uc, tmp, &cdev->gstrings, list) {
F_13 ( & V_3 -> V_54 ) ;
F_65 ( V_3 ) ;
}
if ( V_16 -> V_95 ) {
F_65 ( V_16 -> V_95 -> V_77 ) ;
F_91 ( V_16 -> V_67 -> V_136 , V_16 -> V_95 ) ;
}
V_16 -> V_164 = 0 ;
F_93 ( & V_16 -> V_67 -> V_224 , & V_240 ) ;
}
static int F_94 ( struct V_9 * V_67 ,
struct V_243 * V_244 )
{
struct V_15 * V_16 ;
struct V_157 * V_158 = F_95 ( V_244 ) ;
int V_64 = - V_175 ;
V_16 = F_96 ( sizeof *V_16 , V_174 ) ;
if ( ! V_16 )
return V_64 ;
F_97 ( & V_16 -> V_65 ) ;
V_16 -> V_67 = V_67 ;
F_83 ( V_67 , V_16 ) ;
F_45 ( & V_16 -> V_151 ) ;
F_45 ( & V_16 -> V_181 ) ;
V_64 = F_87 ( V_158 , V_16 ) ;
if ( V_64 )
goto V_239;
V_64 = V_158 -> V_56 ( V_16 ) ;
if ( V_64 < 0 )
goto V_239;
F_85 ( & V_16 -> V_35 , V_158 -> V_224 ) ;
if ( V_158 -> V_245 && ! V_16 -> V_35 . V_236 )
F_98 ( V_16 , L_30 ) ;
F_40 ( V_16 , L_31 , V_158 -> V_49 ) ;
return 0 ;
V_239:
F_81 ( V_67 , false ) ;
return V_64 ;
}
static void
F_99 ( struct V_9 * V_67 )
{
struct V_15 * V_16 = F_4 ( V_67 ) ;
struct V_11 * V_12 ;
F_11 ( V_16 , L_32 ) ;
if ( V_16 -> V_45 ) {
F_28 (f, &cdev->config->functions, list) {
if ( V_12 -> V_246 )
V_12 -> V_246 ( V_12 ) ;
}
}
if ( V_16 -> V_159 -> V_246 )
V_16 -> V_159 -> V_246 ( V_16 ) ;
V_16 -> V_227 = 1 ;
F_43 ( V_67 , 2 ) ;
}
static void
F_100 ( struct V_9 * V_67 )
{
struct V_15 * V_16 = F_4 ( V_67 ) ;
struct V_11 * V_12 ;
T_1 V_247 ;
F_11 ( V_16 , L_33 ) ;
if ( V_16 -> V_159 -> V_248 )
V_16 -> V_159 -> V_248 ( V_16 ) ;
if ( V_16 -> V_45 ) {
F_28 (f, &cdev->config->functions, list) {
if ( V_12 -> V_248 )
V_12 -> V_248 ( V_12 ) ;
}
V_247 = V_16 -> V_45 -> V_75 ;
F_43 ( V_67 , V_247 ?
V_247 : V_76 ) ;
}
V_16 -> V_227 = 0 ;
}
int F_101 ( struct V_157 * V_159 )
{
struct V_243 * V_249 ;
if ( ! V_159 || ! V_159 -> V_224 || ! V_159 -> V_56 )
return - V_48 ;
if ( ! V_159 -> V_49 )
V_159 -> V_49 = L_34 ;
V_159 -> V_249 = V_250 ;
V_249 = & V_159 -> V_249 ;
V_249 -> V_46 = ( char * ) V_159 -> V_49 ;
V_249 -> V_159 . V_49 = V_159 -> V_49 ;
V_249 -> V_251 = V_159 -> V_251 ;
return F_102 ( V_249 ) ;
}
void F_103 ( struct V_157 * V_159 )
{
F_104 ( & V_159 -> V_249 ) ;
}
void F_105 ( struct V_15 * V_16 )
{
int V_47 ;
struct V_182 * V_95 = V_16 -> V_95 ;
unsigned long V_63 ;
F_11 ( V_16 , L_35 , V_148 ) ;
F_17 ( & V_16 -> V_65 , V_63 ) ;
if ( V_16 -> V_149 == 0 ) {
F_77 ( V_16 , L_36 , V_148 ) ;
} else if ( -- V_16 -> V_149 == 0 ) {
F_11 ( V_16 , L_37 , V_148 ) ;
V_95 -> V_184 = 0 ;
V_47 = F_76 ( V_16 -> V_67 -> V_136 , V_95 , V_221 ) ;
if ( V_47 < 0 ) {
F_11 ( V_16 , L_27 , V_47 ) ;
V_95 -> V_64 = 0 ;
F_67 ( V_16 -> V_67 -> V_136 , V_95 ) ;
}
}
F_19 ( & V_16 -> V_65 , V_63 ) ;
}
static char * F_106 ( struct V_9 * V_67 )
{
char * V_252 ;
int V_81 ;
V_81 = snprintf ( NULL , 0 , L_38 , F_107 () -> V_253 ,
F_107 () -> V_254 , V_67 -> V_49 ) ;
V_81 ++ ;
V_252 = F_60 ( V_81 , V_174 ) ;
if ( ! V_252 )
return NULL ;
snprintf ( V_252 , V_81 , L_38 , F_107 () -> V_253 ,
F_107 () -> V_254 , V_67 -> V_49 ) ;
return V_252 ;
}
void F_108 ( struct V_15 * V_16 ,
struct V_255 * V_256 )
{
struct V_230 * V_35 = & V_16 -> V_35 ;
struct V_1 * V_257 = V_16 -> V_159 -> V_162 [ 0 ] ;
struct V_165 * V_258 = V_257 -> V_162 ;
if ( V_256 -> V_233 )
V_35 -> V_233 = F_29 ( V_256 -> V_233 ) ;
if ( V_256 -> V_234 )
V_35 -> V_234 = F_29 ( V_256 -> V_234 ) ;
if ( V_256 -> V_235 )
V_35 -> V_235 = F_29 ( V_256 -> V_235 ) ;
if ( V_256 -> V_259 ) {
V_35 -> V_236 = V_258 [ V_260 ] . V_68 ;
V_258 [ V_260 ] . V_154 = V_256 -> V_259 ;
}
if ( V_256 -> V_261 ) {
V_35 -> V_237 = V_258 [ V_262 ] . V_68 ;
V_258 [ V_262 ] . V_154 = V_256 -> V_261 ;
} else if ( ! strlen ( V_258 [ V_262 ] . V_154 ) ) {
V_35 -> V_237 = V_258 [ V_262 ] . V_68 ;
V_16 -> V_229 = F_106 ( V_16 -> V_67 ) ;
V_258 [ V_262 ] . V_154 = V_16 -> V_229 ;
}
if ( V_256 -> V_263 ) {
V_35 -> V_238 = V_258 [ V_264 ] . V_68 ;
V_258 [ V_264 ] . V_154 = V_256 -> V_263 ;
}
}
