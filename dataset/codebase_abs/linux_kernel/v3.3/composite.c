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
struct V_11 * V_12 = NULL ;
struct V_1 * * V_13 = NULL ;
struct V_14 * V_15 = NULL ;
int V_16 = 0 ;
struct V_1 * * V_17 ;
if ( ! V_6 || ! V_8 || ! V_10 )
return - V_18 ;
switch ( V_6 -> V_19 ) {
case V_20 :
if ( F_3 ( V_6 ) ) {
V_13 = V_8 -> V_21 ;
V_16 = 1 ;
break;
}
case V_22 :
if ( F_4 ( V_6 ) ) {
V_13 = V_8 -> V_23 ;
break;
}
default:
V_13 = V_8 -> V_24 ;
}
F_5 (speed_desc, d_spd) {
V_12 = (struct V_11 * ) * V_17 ;
if ( V_12 -> V_25 == V_10 -> V_26 )
goto V_27;
}
return - V_18 ;
V_27:
V_10 -> V_28 = F_6 ( V_12 ) ;
V_10 -> V_29 = V_12 ;
V_10 -> V_15 = NULL ;
V_10 -> V_30 = 0 ;
V_10 -> V_31 = 0 ;
if ( ! V_16 )
return 0 ;
V_15 = (struct V_14 * ) * ( ++ V_17 ) ;
if ( ! V_15 ||
( V_15 -> V_3 != V_32 ) )
return - V_18 ;
V_10 -> V_15 = V_15 ;
if ( V_6 -> V_19 == V_20 ) {
switch ( F_7 ( V_10 -> V_29 ) ) {
case V_33 :
V_10 -> V_31 = V_15 -> V_34 & 0x3 ;
case V_35 :
case V_36 :
V_10 -> V_30 = V_15 -> V_37 ;
break;
default:
break;
}
}
return 0 ;
}
int F_8 ( struct V_38 * V_39 ,
struct V_7 * V_40 )
{
int V_41 = - V_42 ;
F_9 ( V_39 -> V_43 , L_1 ,
V_40 -> V_44 , V_40 ,
V_39 -> V_45 , V_39 ) ;
if ( ! V_40 -> V_46 || ! V_40 -> V_47 )
goto V_48;
V_40 -> V_39 = V_39 ;
F_10 ( & V_40 -> V_49 , & V_39 -> V_50 ) ;
if ( V_40 -> V_51 ) {
V_41 = V_40 -> V_51 ( V_39 , V_40 ) ;
if ( V_41 < 0 ) {
F_11 ( & V_40 -> V_49 ) ;
V_40 -> V_39 = NULL ;
}
} else
V_41 = 0 ;
if ( ! V_39 -> V_52 && V_40 -> V_24 )
V_39 -> V_52 = true ;
if ( ! V_39 -> V_53 && V_40 -> V_23 )
V_39 -> V_53 = true ;
if ( ! V_39 -> V_54 && V_40 -> V_21 )
V_39 -> V_54 = true ;
V_48:
if ( V_41 )
F_9 ( V_39 -> V_43 , L_2 ,
V_40 -> V_44 , V_40 , V_41 ) ;
return V_41 ;
}
int F_12 ( struct V_7 * V_40 )
{
struct V_55 * V_43 = V_40 -> V_39 -> V_43 ;
unsigned long V_56 ;
int V_57 = 0 ;
F_13 ( & V_43 -> V_58 , V_56 ) ;
if ( V_43 -> V_59 == 0 )
V_57 = F_14 ( V_43 -> V_60 ) ;
if ( V_57 == 0 )
V_43 -> V_59 ++ ;
F_15 ( & V_43 -> V_58 , V_56 ) ;
return V_57 ;
}
int F_16 ( struct V_7 * V_40 )
{
struct V_55 * V_43 = V_40 -> V_39 -> V_43 ;
int V_57 = 0 ;
F_17 ( & V_43 -> V_58 ) ;
if ( F_18 ( V_43 -> V_59 == 0 ) )
V_57 = - V_42 ;
else {
V_43 -> V_59 -- ;
if ( V_43 -> V_59 == 0 )
V_57 = F_19 ( V_43 -> V_60 ) ;
}
F_20 ( & V_43 -> V_58 ) ;
return V_57 ;
}
int F_21 ( struct V_38 * V_39 ,
struct V_7 * V_40 )
{
unsigned V_61 = V_39 -> V_62 ;
if ( V_61 < V_63 ) {
V_39 -> V_64 [ V_61 ] = V_40 ;
V_39 -> V_62 = V_61 + 1 ;
return V_61 ;
}
return - V_65 ;
}
static int F_22 ( struct V_38 * V_39 ,
enum V_66 V_19 , void * V_67 , T_1 type )
{
struct V_68 * V_69 = V_67 ;
void * V_70 = V_67 + V_71 ;
int V_72 = V_73 - V_71 ;
struct V_7 * V_8 ;
int V_57 ;
V_69 = V_67 ;
V_69 -> V_74 = V_71 ;
V_69 -> V_3 = type ;
V_69 -> V_75 = V_39 -> V_62 ;
V_69 -> V_76 = V_39 -> V_76 ;
V_69 -> V_77 = V_39 -> V_77 ;
V_69 -> V_34 = V_78 | V_39 -> V_34 ;
V_69 -> V_79 = V_39 -> V_79 ? : ( V_80 / 2 ) ;
if ( V_39 -> V_24 ) {
V_57 = F_23 ( V_70 , V_72 ,
V_39 -> V_24 ) ;
if ( V_57 < 0 )
return V_57 ;
V_72 -= V_57 ;
V_70 += V_57 ;
}
F_24 (f, &config->functions, list) {
struct V_1 * * V_24 ;
switch ( V_19 ) {
case V_20 :
V_24 = V_8 -> V_21 ;
break;
case V_22 :
V_24 = V_8 -> V_23 ;
break;
default:
V_24 = V_8 -> V_24 ;
}
if ( ! V_24 )
continue;
V_57 = F_23 ( V_70 , V_72 ,
( const struct V_1 * * ) V_24 ) ;
if ( V_57 < 0 )
return V_57 ;
V_72 -= V_57 ;
V_70 += V_57 ;
}
V_72 = V_70 - V_67 ;
V_69 -> V_81 = F_25 ( V_72 ) ;
return V_72 ;
}
static int F_26 ( struct V_55 * V_43 , unsigned V_82 )
{
struct V_5 * V_60 = V_43 -> V_60 ;
struct V_38 * V_69 ;
T_1 type = V_82 >> 8 ;
enum V_66 V_19 = V_83 ;
if ( V_60 -> V_19 == V_20 )
V_19 = V_60 -> V_19 ;
else if ( F_4 ( V_60 ) ) {
int V_84 = 0 ;
if ( V_60 -> V_19 == V_22 )
V_84 = 1 ;
if ( type == V_85 )
V_84 = ! V_84 ;
if ( V_84 )
V_19 = V_22 ;
}
V_82 &= 0xff ;
F_24 (c, &cdev->configs, list) {
switch ( V_19 ) {
case V_20 :
if ( ! V_69 -> V_54 )
continue;
break;
case V_22 :
if ( ! V_69 -> V_53 )
continue;
break;
default:
if ( ! V_69 -> V_52 )
continue;
}
if ( V_82 == 0 )
return F_22 ( V_69 , V_19 , V_43 -> V_86 -> V_67 , type ) ;
V_82 -- ;
}
return - V_42 ;
}
static int F_27 ( struct V_55 * V_43 , unsigned type )
{
struct V_5 * V_60 = V_43 -> V_60 ;
struct V_38 * V_69 ;
unsigned V_87 = 0 ;
int V_84 = 0 ;
int V_88 = 0 ;
if ( F_4 ( V_60 ) ) {
if ( V_60 -> V_19 == V_22 )
V_84 = 1 ;
if ( V_60 -> V_19 == V_20 )
V_88 = 1 ;
if ( type == V_89 )
V_84 = ! V_84 ;
}
F_24 (c, &cdev->configs, list) {
if ( V_88 ) {
if ( ! V_69 -> V_54 )
continue;
} else if ( V_84 ) {
if ( ! V_69 -> V_53 )
continue;
} else {
if ( ! V_69 -> V_52 )
continue;
}
V_87 ++ ;
}
return V_87 ;
}
static int F_28 ( struct V_55 * V_43 )
{
struct V_90 * V_91 ;
struct V_92 * V_93 ;
struct V_94 V_95 ;
struct V_96 * V_97 = V_43 -> V_86 -> V_67 ;
V_97 -> V_74 = V_98 ;
V_97 -> V_3 = V_99 ;
V_97 -> V_81 = F_25 ( V_98 ) ;
V_97 -> V_100 = 0 ;
V_91 = V_43 -> V_86 -> V_67 + F_29 ( V_97 -> V_81 ) ;
V_97 -> V_100 ++ ;
F_30 ( & V_97 -> V_81 , V_101 ) ;
V_91 -> V_74 = V_101 ;
V_91 -> V_3 = V_102 ;
V_91 -> V_103 = V_104 ;
V_91 -> V_34 = F_31 ( V_105 ) ;
V_93 = V_43 -> V_86 -> V_67 + F_29 ( V_97 -> V_81 ) ;
V_97 -> V_100 ++ ;
F_30 ( & V_97 -> V_81 , V_106 ) ;
V_93 -> V_74 = V_106 ;
V_93 -> V_3 = V_102 ;
V_93 -> V_103 = V_107 ;
V_93 -> V_34 = 0 ;
V_93 -> V_108 = F_25 ( V_109 |
V_110 |
V_111 |
V_112 ) ;
V_93 -> V_113 = V_109 ;
if ( V_43 -> V_60 -> V_114 -> V_115 )
V_43 -> V_60 -> V_114 -> V_115 ( & V_95 ) ;
else {
V_95 . V_116 = V_117 ;
V_95 . V_118 =
F_25 ( V_119 ) ;
}
V_93 -> V_116 = V_95 . V_116 ;
V_93 -> V_118 = V_95 . V_118 ;
return F_29 ( V_97 -> V_81 ) ;
}
static void F_32 ( struct V_55 * V_43 )
{
struct V_120 * V_121 = V_43 -> V_86 -> V_67 ;
V_121 -> V_74 = sizeof( * V_121 ) ;
V_121 -> V_3 = V_89 ;
V_121 -> V_122 = V_43 -> V_29 . V_122 ;
V_121 -> V_123 = V_43 -> V_29 . V_123 ;
V_121 -> V_124 = V_43 -> V_29 . V_124 ;
V_121 -> V_125 = V_43 -> V_29 . V_125 ;
V_121 -> V_126 = V_43 -> V_60 -> V_127 -> V_28 ;
V_121 -> V_128 = F_27 ( V_43 , V_89 ) ;
V_121 -> V_129 = 0 ;
}
static void F_33 ( struct V_55 * V_43 )
{
struct V_7 * V_8 ;
F_9 ( V_43 , L_3 ) ;
F_24 (f, &cdev->config->functions, list) {
if ( V_8 -> V_47 )
V_8 -> V_47 ( V_8 ) ;
F_34 ( V_8 -> V_130 , 32 ) ;
}
V_43 -> V_39 = NULL ;
}
static int F_35 ( struct V_55 * V_43 ,
const struct V_131 * V_132 , unsigned V_133 )
{
struct V_5 * V_60 = V_43 -> V_60 ;
struct V_38 * V_69 = NULL ;
int V_134 = - V_42 ;
unsigned V_135 = F_36 ( V_60 ) ? 8 : 100 ;
int V_136 ;
if ( V_133 ) {
F_24 (c, &cdev->configs, list) {
if ( V_69 -> V_76 == V_133 ) {
if ( V_43 -> V_39 )
F_33 ( V_43 ) ;
V_134 = 0 ;
break;
}
}
if ( V_134 < 0 )
goto V_48;
} else {
if ( V_43 -> V_39 )
F_33 ( V_43 ) ;
V_134 = 0 ;
}
F_37 ( V_43 , L_4 ,
F_38 ( V_60 -> V_19 ) ,
V_133 , V_69 ? V_69 -> V_45 : L_5 ) ;
if ( ! V_69 )
goto V_48;
V_43 -> V_39 = V_69 ;
for ( V_136 = 0 ; V_136 < V_63 ; V_136 ++ ) {
struct V_7 * V_8 = V_69 -> V_64 [ V_136 ] ;
struct V_1 * * V_24 ;
if ( ! V_8 )
break;
switch ( V_60 -> V_19 ) {
case V_20 :
V_24 = V_8 -> V_21 ;
break;
case V_22 :
V_24 = V_8 -> V_23 ;
break;
default:
V_24 = V_8 -> V_24 ;
}
for (; * V_24 ; ++ V_24 ) {
struct V_11 * V_137 ;
int V_138 ;
if ( ( * V_24 ) -> V_3 != V_4 )
continue;
V_137 = (struct V_11 * ) * V_24 ;
V_138 = ( ( V_137 -> V_25 & 0x80 ) >> 3 )
| ( V_137 -> V_25 & 0x0f ) ;
F_39 ( V_138 , V_8 -> V_130 ) ;
}
V_134 = V_8 -> V_46 ( V_8 , V_136 , 0 ) ;
if ( V_134 < 0 ) {
F_9 ( V_43 , L_6 ,
V_136 , V_8 -> V_44 , V_8 , V_134 ) ;
F_33 ( V_43 ) ;
goto V_48;
}
if ( V_134 == V_139 ) {
F_9 ( V_43 ,
L_7 ,
V_140 , V_136 , V_8 -> V_44 ) ;
V_43 -> V_141 ++ ;
F_9 ( V_43 , L_8 ,
V_43 -> V_141 ) ;
}
}
V_135 = V_69 -> V_79 ? ( 2 * V_69 -> V_79 ) : V_80 ;
V_48:
F_40 ( V_60 , V_135 ) ;
if ( V_134 >= 0 && V_43 -> V_141 )
V_134 = V_139 ;
return V_134 ;
}
int F_41 ( struct V_55 * V_43 ,
struct V_38 * V_39 ,
int (* V_51)( struct V_38 * ) )
{
int V_57 = - V_42 ;
struct V_38 * V_69 ;
F_9 ( V_43 , L_9 ,
V_39 -> V_76 ,
V_39 -> V_45 , V_39 ) ;
if ( ! V_39 -> V_76 || ! V_51 )
goto V_48;
F_24 (c, &cdev->configs, list) {
if ( V_69 -> V_76 == V_39 -> V_76 ) {
V_57 = - V_142 ;
goto V_48;
}
}
V_39 -> V_43 = V_43 ;
F_10 ( & V_39 -> V_49 , & V_43 -> V_143 ) ;
F_42 ( & V_39 -> V_50 ) ;
V_39 -> V_62 = 0 ;
V_57 = V_51 ( V_39 ) ;
if ( V_57 < 0 ) {
F_11 ( & V_39 -> V_49 ) ;
V_39 -> V_43 = NULL ;
} else {
unsigned V_144 ;
F_9 ( V_43 , L_10 ,
V_39 -> V_76 , V_39 ,
V_39 -> V_54 ? L_11 : L_12 ,
V_39 -> V_53 ? L_13 : L_12 ,
V_39 -> V_52
? ( F_4 ( V_43 -> V_60 )
? L_14
: L_15 )
: L_12 ) ;
for ( V_144 = 0 ; V_144 < V_63 ; V_144 ++ ) {
struct V_7 * V_8 = V_39 -> V_64 [ V_144 ] ;
if ( ! V_8 )
continue;
F_9 ( V_43 , L_16 ,
V_144 , V_8 -> V_44 , V_8 ) ;
}
}
F_43 ( V_43 -> V_60 ) ;
V_48:
if ( V_57 )
F_9 ( V_43 , L_17 , V_39 -> V_45 ,
V_39 -> V_76 , V_57 ) ;
return V_57 ;
}
static void F_44 ( struct V_145 * * V_146 , T_2 * V_67 )
{
const struct V_145 * V_147 ;
T_3 V_148 ;
T_2 * V_136 ;
while ( * V_146 ) {
V_147 = * V_146 ;
V_148 = F_25 ( V_147 -> V_148 ) ;
for ( V_136 = V_67 ; * V_136 && V_136 < & V_67 [ 126 ] ; V_136 ++ ) {
if ( * V_136 == V_148 )
goto V_149;
}
* V_136 ++ = V_148 ;
V_149:
V_146 ++ ;
}
}
static int F_45 (
struct V_145 * * V_146 ,
void * V_67 ,
T_3 V_148 ,
int V_61
)
{
struct V_145 * V_147 ;
int V_41 ;
while ( * V_146 ) {
V_147 = * V_146 ++ ;
if ( V_147 -> V_148 != V_148 )
continue;
V_41 = F_46 ( V_147 , V_61 , V_67 ) ;
if ( V_41 > 0 )
return V_41 ;
}
return - V_42 ;
}
static int F_47 ( struct V_55 * V_43 ,
void * V_67 , T_3 V_148 , int V_61 )
{
struct V_38 * V_69 ;
struct V_7 * V_8 ;
int V_72 ;
const char * V_150 ;
if ( V_61 == 0 ) {
struct V_151 * V_147 = V_67 ;
struct V_145 * * V_146 ;
memset ( V_147 , 0 , 256 ) ;
V_147 -> V_3 = V_152 ;
V_146 = V_153 -> V_154 ;
if ( V_146 )
F_44 ( V_146 , V_147 -> V_155 ) ;
F_24 (c, &cdev->configs, list) {
V_146 = V_69 -> V_154 ;
if ( V_146 )
F_44 ( V_146 , V_147 -> V_155 ) ;
F_24 (f, &c->functions, list) {
V_146 = V_8 -> V_154 ;
if ( V_146 )
F_44 ( V_146 , V_147 -> V_155 ) ;
}
}
for ( V_72 = 0 ; V_72 <= 126 && V_147 -> V_155 [ V_72 ] ; V_72 ++ )
continue;
if ( ! V_72 )
return - V_42 ;
V_147 -> V_74 = 2 * ( V_72 + 1 ) ;
return V_147 -> V_74 ;
}
if ( V_43 -> V_156 == V_61 )
V_150 = V_157 ? : V_153 -> V_157 ? :
V_158 ;
else if ( V_43 -> V_159 == V_61 )
V_150 = V_160 ? : V_153 -> V_160 ;
else if ( V_43 -> V_161 == V_61 )
V_150 = V_162 ;
else
V_150 = NULL ;
if ( V_150 ) {
struct V_145 V_154 = {
. V_148 = V_148 ,
. V_154 = & (struct V_163 ) { 0xff , V_150 }
} ;
return F_46 ( & V_154 , 0xff , V_67 ) ;
}
if ( V_153 -> V_154 ) {
V_72 = F_45 ( V_153 -> V_154 , V_67 , V_148 , V_61 ) ;
if ( V_72 > 0 )
return V_72 ;
}
F_24 (c, &cdev->configs, list) {
if ( V_69 -> V_154 ) {
V_72 = F_45 ( V_69 -> V_154 , V_67 , V_148 , V_61 ) ;
if ( V_72 > 0 )
return V_72 ;
}
F_24 (f, &c->functions, list) {
if ( ! V_8 -> V_154 )
continue;
V_72 = F_45 ( V_8 -> V_154 , V_67 , V_148 , V_61 ) ;
if ( V_72 > 0 )
return V_72 ;
}
}
return - V_42 ;
}
int F_48 ( struct V_55 * V_43 )
{
if ( V_43 -> V_164 < 254 ) {
V_43 -> V_164 ++ ;
return V_43 -> V_164 ;
}
return - V_65 ;
}
int F_49 ( struct V_55 * V_43 , struct V_163 * V_150 )
{
int V_70 = V_43 -> V_164 ;
for (; V_150 -> V_147 ; ++ V_150 ) {
if ( F_50 ( V_70 >= 254 ) )
return - V_65 ;
V_150 -> V_61 = ++ V_70 ;
}
V_43 -> V_164 = V_70 ;
return 0 ;
}
int F_51 ( struct V_55 * V_69 , unsigned V_165 )
{
unsigned V_70 = V_69 -> V_164 ;
if ( F_50 ( V_165 > 254 || ( unsigned ) V_70 + V_165 > 254 ) )
return - V_65 ;
V_69 -> V_164 += V_165 ;
return V_70 + 1 ;
}
static void F_52 ( struct V_9 * V_137 , struct V_166 * V_86 )
{
if ( V_86 -> V_57 || V_86 -> V_167 != V_86 -> V_168 )
F_9 ( (struct V_55 * ) V_137 -> V_169 ,
L_18 ,
V_86 -> V_57 , V_86 -> V_167 , V_86 -> V_168 ) ;
}
static int
F_53 ( struct V_5 * V_60 , const struct V_131 * V_132 )
{
struct V_55 * V_43 = F_54 ( V_60 ) ;
struct V_166 * V_86 = V_43 -> V_86 ;
int V_41 = - V_170 ;
int V_57 = 0 ;
T_3 V_171 = F_29 ( V_132 -> V_172 ) ;
T_1 V_173 = V_171 & 0xFF ;
T_3 V_82 = F_29 ( V_132 -> V_174 ) ;
T_3 V_175 = F_29 ( V_132 -> V_176 ) ;
struct V_7 * V_8 = NULL ;
T_1 V_177 ;
V_86 -> V_178 = 0 ;
V_86 -> V_179 = F_52 ;
V_86 -> V_168 = 0 ;
V_60 -> V_127 -> V_169 = V_43 ;
switch ( V_132 -> V_180 ) {
case V_181 :
if ( V_132 -> V_182 != V_183 )
goto V_184;
switch ( V_82 >> 8 ) {
case V_185 :
V_43 -> V_29 . V_128 =
F_27 ( V_43 , V_185 ) ;
V_43 -> V_29 . V_126 =
V_43 -> V_60 -> V_127 -> V_28 ;
if ( F_3 ( V_60 ) ) {
if ( V_60 -> V_19 >= V_20 ) {
V_43 -> V_29 . V_122 = F_25 ( 0x0300 ) ;
V_43 -> V_29 . V_126 = 9 ;
} else {
V_43 -> V_29 . V_122 = F_25 ( 0x0210 ) ;
}
}
V_41 = F_55 ( V_175 , ( T_3 ) sizeof V_43 -> V_29 ) ;
memcpy ( V_86 -> V_67 , & V_43 -> V_29 , V_41 ) ;
break;
case V_89 :
if ( ! F_4 ( V_60 ) ||
V_60 -> V_19 >= V_20 )
break;
F_32 ( V_43 ) ;
V_41 = F_56 ( int , V_175 ,
sizeof( struct V_120 ) ) ;
break;
case V_85 :
if ( ! F_4 ( V_60 ) ||
V_60 -> V_19 >= V_20 )
break;
case V_186 :
V_41 = F_26 ( V_43 , V_82 ) ;
if ( V_41 >= 0 )
V_41 = F_55 ( V_175 , ( T_3 ) V_41 ) ;
break;
case V_152 :
V_41 = F_47 ( V_43 , V_86 -> V_67 ,
V_171 , V_82 & 0xff ) ;
if ( V_41 >= 0 )
V_41 = F_55 ( V_175 , ( T_3 ) V_41 ) ;
break;
case V_99 :
if ( F_3 ( V_60 ) ) {
V_41 = F_28 ( V_43 ) ;
V_41 = F_55 ( V_175 , ( T_3 ) V_41 ) ;
}
break;
}
break;
case V_187 :
if ( V_132 -> V_182 != 0 )
goto V_184;
if ( F_36 ( V_60 ) ) {
if ( V_60 -> V_188 )
F_9 ( V_43 , L_19 ) ;
else if ( V_60 -> V_189 )
F_9 ( V_43 , L_20 ) ;
else
F_57 ( V_43 , L_21 ) ;
}
F_17 ( & V_43 -> V_58 ) ;
V_41 = F_35 ( V_43 , V_132 , V_82 ) ;
F_20 ( & V_43 -> V_58 ) ;
break;
case V_190 :
if ( V_132 -> V_182 != V_183 )
goto V_184;
if ( V_43 -> V_39 )
* ( T_1 * ) V_86 -> V_67 = V_43 -> V_39 -> V_76 ;
else
* ( T_1 * ) V_86 -> V_67 = 0 ;
V_41 = F_55 ( V_175 , ( T_3 ) 1 ) ;
break;
case V_191 :
if ( V_132 -> V_182 != V_192 )
goto V_184;
if ( ! V_43 -> V_39 || V_173 >= V_63 )
break;
V_8 = V_43 -> V_39 -> V_64 [ V_173 ] ;
if ( ! V_8 )
break;
if ( V_82 && ! V_8 -> V_46 )
break;
V_41 = V_8 -> V_46 ( V_8 , V_171 , V_82 ) ;
if ( V_41 == V_139 ) {
F_9 ( V_43 ,
L_7 ,
V_140 , V_173 , V_8 -> V_44 ) ;
V_43 -> V_141 ++ ;
F_9 ( V_43 , L_8 ,
V_43 -> V_141 ) ;
}
break;
case V_193 :
if ( V_132 -> V_182 != ( V_183 | V_192 ) )
goto V_184;
if ( ! V_43 -> V_39 || V_173 >= V_63 )
break;
V_8 = V_43 -> V_39 -> V_64 [ V_173 ] ;
if ( ! V_8 )
break;
V_41 = V_8 -> V_194 ? V_8 -> V_194 ( V_8 , V_171 ) : 0 ;
if ( V_41 < 0 )
break;
* ( ( T_1 * ) V_86 -> V_67 ) = V_41 ;
V_41 = F_55 ( V_175 , ( T_3 ) 1 ) ;
break;
case V_195 :
if ( ! F_3 ( V_60 ) )
goto V_184;
if ( V_132 -> V_182 != ( V_183 | V_192 ) )
goto V_184;
V_41 = 2 ;
F_58 ( 0 , V_86 -> V_67 ) ;
if ( ! V_43 -> V_39 || V_173 >= V_63 )
break;
V_8 = V_43 -> V_39 -> V_64 [ V_173 ] ;
if ( ! V_8 )
break;
V_57 = V_8 -> V_196 ? V_8 -> V_196 ( V_8 ) : 0 ;
if ( V_57 < 0 )
break;
F_58 ( V_57 & 0x0000ffff , V_86 -> V_67 ) ;
break;
case V_197 :
case V_198 :
if ( ! F_3 ( V_60 ) )
goto V_184;
if ( V_132 -> V_182 != ( V_199 | V_192 ) )
goto V_184;
switch ( V_82 ) {
case V_200 :
if ( ! V_43 -> V_39 || V_173 >= V_63 )
break;
V_8 = V_43 -> V_39 -> V_64 [ V_173 ] ;
if ( ! V_8 )
break;
V_41 = 0 ;
if ( V_8 -> V_201 )
V_41 = V_8 -> V_201 ( V_8 , V_171 >> 8 ) ;
if ( V_41 < 0 ) {
ERROR ( V_43 ,
L_22 ,
V_41 ) ;
V_41 = 0 ;
}
break;
}
break;
default:
V_184:
F_57 ( V_43 ,
L_23 ,
V_132 -> V_182 , V_132 -> V_180 ,
V_82 , V_171 , V_175 ) ;
switch ( V_132 -> V_182 & V_202 ) {
case V_192 :
if ( ! V_43 -> V_39 || V_173 >= V_63 )
break;
V_8 = V_43 -> V_39 -> V_64 [ V_173 ] ;
break;
case V_203 :
V_177 = ( ( V_171 & 0x80 ) >> 3 ) | ( V_171 & 0x0f ) ;
F_24 (f, &cdev->config->functions, list) {
if ( F_59 ( V_177 , V_8 -> V_130 ) )
break;
}
if ( & V_8 -> V_49 == & V_43 -> V_39 -> V_50 )
V_8 = NULL ;
break;
}
if ( V_8 && V_8 -> V_204 )
V_41 = V_8 -> V_204 ( V_8 , V_132 ) ;
else {
struct V_38 * V_69 ;
V_69 = V_43 -> V_39 ;
if ( V_69 && V_69 -> V_204 )
V_41 = V_69 -> V_204 ( V_69 , V_132 ) ;
}
goto V_48;
}
if ( V_41 >= 0 && V_41 != V_139 ) {
V_86 -> V_168 = V_41 ;
V_86 -> V_178 = V_41 < V_175 ;
V_41 = F_60 ( V_60 -> V_127 , V_86 , V_205 ) ;
if ( V_41 < 0 ) {
F_9 ( V_43 , L_24 , V_41 ) ;
V_86 -> V_57 = 0 ;
F_52 ( V_60 -> V_127 , V_86 ) ;
}
} else if ( V_41 == V_139 && V_175 != 0 ) {
F_61 ( V_43 ,
L_25 ,
V_140 ) ;
}
V_48:
return V_41 ;
}
static void F_62 ( struct V_5 * V_60 )
{
struct V_55 * V_43 = F_54 ( V_60 ) ;
unsigned long V_56 ;
F_13 ( & V_43 -> V_58 , V_56 ) ;
if ( V_43 -> V_39 )
F_33 ( V_43 ) ;
if ( V_153 -> V_206 )
V_153 -> V_206 ( V_43 ) ;
F_15 ( & V_43 -> V_58 , V_56 ) ;
}
static T_4 F_63 ( struct V_207 * V_208 ,
struct V_209 * V_210 ,
char * V_67 )
{
struct V_5 * V_60 = F_64 ( V_208 ) ;
struct V_55 * V_43 = F_54 ( V_60 ) ;
return sprintf ( V_67 , L_26 , V_43 -> V_211 ) ;
}
static void
F_65 ( struct V_5 * V_60 )
{
struct V_55 * V_43 = F_54 ( V_60 ) ;
F_18 ( V_43 -> V_39 ) ;
while ( ! F_66 ( & V_43 -> V_143 ) ) {
struct V_38 * V_69 ;
V_69 = F_67 ( & V_43 -> V_143 ,
struct V_38 , V_49 ) ;
while ( ! F_66 ( & V_69 -> V_50 ) ) {
struct V_7 * V_8 ;
V_8 = F_67 ( & V_69 -> V_50 ,
struct V_7 , V_49 ) ;
F_11 ( & V_8 -> V_49 ) ;
if ( V_8 -> V_212 ) {
F_9 ( V_43 , L_27 ,
V_8 -> V_44 , V_8 ) ;
V_8 -> V_212 ( V_69 , V_8 ) ;
}
}
F_11 ( & V_69 -> V_49 ) ;
if ( V_69 -> V_212 ) {
F_9 ( V_43 , L_28 , V_69 -> V_45 , V_69 ) ;
V_69 -> V_212 ( V_69 ) ;
}
}
if ( V_153 -> V_212 )
V_153 -> V_212 ( V_43 ) ;
if ( V_43 -> V_86 ) {
F_68 ( V_43 -> V_86 -> V_67 ) ;
F_69 ( V_60 -> V_127 , V_43 -> V_86 ) ;
}
F_70 ( & V_60 -> V_208 , & V_213 ) ;
F_68 ( V_43 ) ;
F_71 ( V_60 , NULL ) ;
V_153 = NULL ;
}
static T_1 F_72 ( struct V_55 * V_43 , T_1 * V_29 )
{
if ( ! * V_29 ) {
int V_214 = F_48 ( V_43 ) ;
if ( F_50 ( V_214 < 0 ) )
F_73 ( V_43 , L_29 ) ;
else
* V_29 = V_214 ;
}
return * V_29 ;
}
static int F_74 ( struct V_5 * V_60 )
{
struct V_55 * V_43 ;
int V_57 = - V_215 ;
V_43 = F_75 ( sizeof *V_43 , V_216 ) ;
if ( ! V_43 )
return V_57 ;
F_76 ( & V_43 -> V_58 ) ;
V_43 -> V_60 = V_60 ;
F_71 ( V_60 , V_43 ) ;
F_42 ( & V_43 -> V_143 ) ;
V_43 -> V_86 = F_77 ( V_60 -> V_127 , V_216 ) ;
if ( ! V_43 -> V_86 )
goto V_217;
V_43 -> V_86 -> V_67 = F_78 ( V_73 , V_216 ) ;
if ( ! V_43 -> V_86 -> V_67 )
goto V_217;
V_43 -> V_86 -> V_179 = F_52 ;
V_60 -> V_127 -> V_169 = V_43 ;
V_43 -> V_218 = V_73 ;
V_43 -> V_219 = V_153 ;
if ( V_80 <= V_220 )
F_79 ( V_60 ) ;
F_43 ( V_43 -> V_60 ) ;
V_57 = F_80 ( V_43 ) ;
if ( V_57 < 0 )
goto V_217;
V_43 -> V_29 = * V_153 -> V_208 ;
if ( V_221 )
V_43 -> V_29 . V_221 = F_25 ( V_221 ) ;
if ( V_222 )
V_43 -> V_29 . V_222 = F_25 ( V_222 ) ;
if ( V_223 )
V_43 -> V_29 . V_223 = F_25 ( V_223 ) ;
if ( V_157 || ! V_43 -> V_29 . V_157 ) {
if ( ! V_157 && ! V_153 -> V_157 &&
! * V_158 )
snprintf ( V_158 ,
sizeof V_158 ,
L_30 ,
F_81 () -> V_224 ,
F_81 () -> V_225 ,
V_60 -> V_44 ) ;
V_43 -> V_156 =
F_72 ( V_43 , & V_43 -> V_29 . V_157 ) ;
}
if ( V_160 || ( ! V_43 -> V_29 . V_160 && V_153 -> V_160 ) )
V_43 -> V_159 =
F_72 ( V_43 , & V_43 -> V_29 . V_160 ) ;
if ( V_162 )
V_43 -> V_161 =
F_72 ( V_43 , & V_43 -> V_29 . V_162 ) ;
if ( V_153 -> V_226 && ! V_43 -> V_29 . V_162 )
F_73 ( V_43 , L_31 ) ;
V_57 = F_82 ( & V_60 -> V_208 , & V_213 ) ;
if ( V_57 )
goto V_217;
F_37 ( V_43 , L_32 , V_153 -> V_44 ) ;
return 0 ;
V_217:
F_65 ( V_60 ) ;
return V_57 ;
}
static void
F_83 ( struct V_5 * V_60 )
{
struct V_55 * V_43 = F_54 ( V_60 ) ;
struct V_7 * V_8 ;
F_9 ( V_43 , L_33 ) ;
if ( V_43 -> V_39 ) {
F_24 (f, &cdev->config->functions, list) {
if ( V_8 -> V_227 )
V_8 -> V_227 ( V_8 ) ;
}
}
if ( V_153 -> V_227 )
V_153 -> V_227 ( V_43 ) ;
V_43 -> V_211 = 1 ;
F_40 ( V_60 , 2 ) ;
}
static void
F_84 ( struct V_5 * V_60 )
{
struct V_55 * V_43 = F_54 ( V_60 ) ;
struct V_7 * V_8 ;
T_1 V_228 ;
F_9 ( V_43 , L_34 ) ;
if ( V_153 -> V_229 )
V_153 -> V_229 ( V_43 ) ;
if ( V_43 -> V_39 ) {
F_24 (f, &cdev->config->functions, list) {
if ( V_8 -> V_229 )
V_8 -> V_229 ( V_8 ) ;
}
V_228 = V_43 -> V_39 -> V_79 ;
F_40 ( V_60 , V_228 ?
( 2 * V_228 ) : V_80 ) ;
}
V_43 -> V_211 = 0 ;
}
int F_85 ( struct V_230 * V_219 ,
int (* V_51)( struct V_55 * V_43 ) )
{
if ( ! V_219 || ! V_219 -> V_208 || ! V_51 || V_153 )
return - V_42 ;
if ( ! V_219 -> V_44 )
V_219 -> V_44 = L_35 ;
if ( ! V_219 -> V_160 )
V_219 -> V_160 = V_219 -> V_44 ;
V_231 . V_40 = ( char * ) V_219 -> V_44 ;
V_231 . V_219 . V_44 = V_219 -> V_44 ;
V_231 . V_232 =
F_56 ( T_1 , V_231 . V_232 , V_219 -> V_232 ) ;
V_153 = V_219 ;
F_80 = V_51 ;
return F_86 ( & V_231 , F_74 ) ;
}
void F_87 ( struct V_230 * V_219 )
{
if ( V_153 != V_219 )
return;
F_88 ( & V_231 ) ;
}
void F_89 ( struct V_55 * V_43 )
{
int V_41 ;
struct V_166 * V_86 = V_43 -> V_86 ;
unsigned long V_56 ;
F_9 ( V_43 , L_36 , V_140 ) ;
F_13 ( & V_43 -> V_58 , V_56 ) ;
if ( V_43 -> V_141 == 0 ) {
F_61 ( V_43 , L_37 , V_140 ) ;
} else if ( -- V_43 -> V_141 == 0 ) {
F_9 ( V_43 , L_38 , V_140 ) ;
V_86 -> V_168 = 0 ;
V_41 = F_60 ( V_43 -> V_60 -> V_127 , V_86 , V_205 ) ;
if ( V_41 < 0 ) {
F_9 ( V_43 , L_24 , V_41 ) ;
V_86 -> V_57 = 0 ;
F_52 ( V_43 -> V_60 -> V_127 , V_86 ) ;
}
}
F_15 ( & V_43 -> V_58 , V_56 ) ;
}
