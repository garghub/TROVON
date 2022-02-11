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
V_10 -> V_28 = F_6 ( V_12 -> V_29 ) ;
V_10 -> V_30 = V_12 ;
V_10 -> V_15 = NULL ;
V_10 -> V_31 = 0 ;
V_10 -> V_32 = 0 ;
if ( ! V_16 )
return 0 ;
V_15 = (struct V_14 * ) * ( ++ V_17 ) ;
if ( ! V_15 ||
( V_15 -> V_3 != V_33 ) )
return - V_18 ;
V_10 -> V_15 = V_15 ;
if ( V_6 -> V_19 == V_20 ) {
switch ( F_7 ( V_10 -> V_30 ) ) {
case V_34 :
case V_35 :
V_10 -> V_31 = V_15 -> V_36 ;
break;
case V_37 :
V_10 -> V_32 = V_15 -> V_38 & 0x3 ;
break;
default:
break;
}
}
return 0 ;
}
int F_8 ( struct V_39 * V_40 ,
struct V_7 * V_41 )
{
int V_42 = - V_43 ;
F_9 ( V_40 -> V_44 , L_1 ,
V_41 -> V_45 , V_41 ,
V_40 -> V_46 , V_40 ) ;
if ( ! V_41 -> V_47 || ! V_41 -> V_48 )
goto V_49;
V_41 -> V_40 = V_40 ;
F_10 ( & V_41 -> V_50 , & V_40 -> V_51 ) ;
if ( V_41 -> V_52 ) {
V_42 = V_41 -> V_52 ( V_40 , V_41 ) ;
if ( V_42 < 0 ) {
F_11 ( & V_41 -> V_50 ) ;
V_41 -> V_40 = NULL ;
}
} else
V_42 = 0 ;
if ( ! V_40 -> V_53 && V_41 -> V_24 )
V_40 -> V_53 = true ;
if ( ! V_40 -> V_54 && V_41 -> V_23 )
V_40 -> V_54 = true ;
if ( ! V_40 -> V_55 && V_41 -> V_21 )
V_40 -> V_55 = true ;
V_49:
if ( V_42 )
F_9 ( V_40 -> V_44 , L_2 ,
V_41 -> V_45 , V_41 , V_42 ) ;
return V_42 ;
}
int F_12 ( struct V_7 * V_41 )
{
struct V_56 * V_44 = V_41 -> V_40 -> V_44 ;
unsigned long V_57 ;
int V_58 = 0 ;
F_13 ( & V_44 -> V_59 , V_57 ) ;
if ( V_44 -> V_60 == 0 )
V_58 = F_14 ( V_44 -> V_61 ) ;
if ( V_58 == 0 )
V_44 -> V_60 ++ ;
F_15 ( & V_44 -> V_59 , V_57 ) ;
return V_58 ;
}
int F_16 ( struct V_7 * V_41 )
{
struct V_56 * V_44 = V_41 -> V_40 -> V_44 ;
int V_58 = 0 ;
F_17 ( & V_44 -> V_59 ) ;
if ( F_18 ( V_44 -> V_60 == 0 ) )
V_58 = - V_43 ;
else {
V_44 -> V_60 -- ;
if ( V_44 -> V_60 == 0 )
V_58 = F_19 ( V_44 -> V_61 ) ;
}
F_20 ( & V_44 -> V_59 ) ;
return V_58 ;
}
int F_21 ( struct V_39 * V_40 ,
struct V_7 * V_41 )
{
unsigned V_62 = V_40 -> V_63 ;
if ( V_62 < V_64 ) {
V_40 -> V_65 [ V_62 ] = V_41 ;
V_40 -> V_63 = V_62 + 1 ;
return V_62 ;
}
return - V_66 ;
}
static int F_22 ( struct V_39 * V_40 ,
enum V_67 V_19 , void * V_68 , T_1 type )
{
struct V_69 * V_70 = V_68 ;
void * V_71 = V_68 + V_72 ;
int V_73 = V_74 - V_72 ;
struct V_7 * V_8 ;
int V_58 ;
V_70 = V_68 ;
V_70 -> V_75 = V_72 ;
V_70 -> V_3 = type ;
V_70 -> V_76 = V_40 -> V_63 ;
V_70 -> V_77 = V_40 -> V_77 ;
V_70 -> V_78 = V_40 -> V_78 ;
V_70 -> V_38 = V_79 | V_40 -> V_38 ;
V_70 -> V_80 = V_40 -> V_80 ? : ( V_81 / 2 ) ;
if ( V_40 -> V_24 ) {
V_58 = F_23 ( V_71 , V_73 ,
V_40 -> V_24 ) ;
if ( V_58 < 0 )
return V_58 ;
V_73 -= V_58 ;
V_71 += V_58 ;
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
V_58 = F_23 ( V_71 , V_73 ,
( const struct V_1 * * ) V_24 ) ;
if ( V_58 < 0 )
return V_58 ;
V_73 -= V_58 ;
V_71 += V_58 ;
}
V_73 = V_71 - V_68 ;
V_70 -> V_82 = F_25 ( V_73 ) ;
return V_73 ;
}
static int F_26 ( struct V_56 * V_44 , unsigned V_83 )
{
struct V_5 * V_61 = V_44 -> V_61 ;
struct V_39 * V_70 ;
T_1 type = V_83 >> 8 ;
enum V_67 V_19 = V_84 ;
if ( V_61 -> V_19 == V_20 )
V_19 = V_61 -> V_19 ;
else if ( F_4 ( V_61 ) ) {
int V_85 = 0 ;
if ( V_61 -> V_19 == V_22 )
V_85 = 1 ;
if ( type == V_86 )
V_85 = ! V_85 ;
if ( V_85 )
V_19 = V_22 ;
}
V_83 &= 0xff ;
F_24 (c, &cdev->configs, list) {
switch ( V_19 ) {
case V_20 :
if ( ! V_70 -> V_55 )
continue;
break;
case V_22 :
if ( ! V_70 -> V_54 )
continue;
break;
default:
if ( ! V_70 -> V_53 )
continue;
}
if ( V_83 == 0 )
return F_22 ( V_70 , V_19 , V_44 -> V_87 -> V_68 , type ) ;
V_83 -- ;
}
return - V_43 ;
}
static int F_27 ( struct V_56 * V_44 , unsigned type )
{
struct V_5 * V_61 = V_44 -> V_61 ;
struct V_39 * V_70 ;
unsigned V_88 = 0 ;
int V_85 = 0 ;
int V_89 = 0 ;
if ( F_4 ( V_61 ) ) {
if ( V_61 -> V_19 == V_22 )
V_85 = 1 ;
if ( V_61 -> V_19 == V_20 )
V_89 = 1 ;
if ( type == V_90 )
V_85 = ! V_85 ;
}
F_24 (c, &cdev->configs, list) {
if ( V_89 ) {
if ( ! V_70 -> V_55 )
continue;
} else if ( V_85 ) {
if ( ! V_70 -> V_54 )
continue;
} else {
if ( ! V_70 -> V_53 )
continue;
}
V_88 ++ ;
}
return V_88 ;
}
static int F_28 ( struct V_56 * V_44 )
{
struct V_91 * V_92 ;
struct V_93 * V_94 ;
struct V_95 V_96 ;
struct V_97 * V_98 = V_44 -> V_87 -> V_68 ;
V_98 -> V_75 = V_99 ;
V_98 -> V_3 = V_100 ;
V_98 -> V_82 = F_25 ( V_99 ) ;
V_98 -> V_101 = 0 ;
V_92 = V_44 -> V_87 -> V_68 + F_6 ( V_98 -> V_82 ) ;
V_98 -> V_101 ++ ;
F_29 ( & V_98 -> V_82 , V_102 ) ;
V_92 -> V_75 = V_102 ;
V_92 -> V_3 = V_103 ;
V_92 -> V_104 = V_105 ;
V_92 -> V_38 = F_30 ( V_106 ) ;
V_94 = V_44 -> V_87 -> V_68 + F_6 ( V_98 -> V_82 ) ;
V_98 -> V_101 ++ ;
F_29 ( & V_98 -> V_82 , V_107 ) ;
V_94 -> V_75 = V_107 ;
V_94 -> V_3 = V_103 ;
V_94 -> V_104 = V_108 ;
V_94 -> V_38 = 0 ;
V_94 -> V_109 = F_25 ( V_110 |
V_111 |
V_112 |
V_113 ) ;
V_94 -> V_114 = V_110 ;
if ( V_44 -> V_61 -> V_115 -> V_116 )
V_44 -> V_61 -> V_115 -> V_116 ( & V_96 ) ;
else {
V_96 . V_117 = V_118 ;
V_96 . V_119 =
F_25 ( V_120 ) ;
}
V_94 -> V_117 = V_96 . V_117 ;
V_94 -> V_119 = V_96 . V_119 ;
return F_6 ( V_98 -> V_82 ) ;
}
static void F_31 ( struct V_56 * V_44 )
{
struct V_121 * V_122 = V_44 -> V_87 -> V_68 ;
V_122 -> V_75 = sizeof( * V_122 ) ;
V_122 -> V_3 = V_90 ;
V_122 -> V_123 = V_44 -> V_30 . V_123 ;
V_122 -> V_124 = V_44 -> V_30 . V_124 ;
V_122 -> V_125 = V_44 -> V_30 . V_125 ;
V_122 -> V_126 = V_44 -> V_30 . V_126 ;
V_122 -> V_127 = V_44 -> V_61 -> V_128 -> V_28 ;
V_122 -> V_129 = F_27 ( V_44 , V_90 ) ;
V_122 -> V_130 = 0 ;
}
static void F_32 ( struct V_56 * V_44 )
{
struct V_7 * V_8 ;
F_9 ( V_44 , L_3 ) ;
F_24 (f, &cdev->config->functions, list) {
if ( V_8 -> V_48 )
V_8 -> V_48 ( V_8 ) ;
F_33 ( V_8 -> V_131 , 32 ) ;
}
V_44 -> V_40 = NULL ;
}
static int F_34 ( struct V_56 * V_44 ,
const struct V_132 * V_133 , unsigned V_134 )
{
struct V_5 * V_61 = V_44 -> V_61 ;
struct V_39 * V_70 = NULL ;
int V_135 = - V_43 ;
unsigned V_136 = F_35 ( V_61 ) ? 8 : 100 ;
int V_137 ;
if ( V_134 ) {
F_24 (c, &cdev->configs, list) {
if ( V_70 -> V_77 == V_134 ) {
if ( V_44 -> V_40 )
F_32 ( V_44 ) ;
V_135 = 0 ;
break;
}
}
if ( V_135 < 0 )
goto V_49;
} else {
if ( V_44 -> V_40 )
F_32 ( V_44 ) ;
V_135 = 0 ;
}
F_36 (cdev, L_4 ,
({ char *speed;
switch (gadget->speed) {
case USB_SPEED_LOW:
speed = L_5;
break;
case USB_SPEED_FULL:
speed = L_6;
break;
case USB_SPEED_HIGH:
speed = L_7;
break;
case USB_SPEED_SUPER:
speed = L_8;
break;
default:
speed = L_9;
break;
} ; speed; }), number, c ? c->label : L_10 ) ;
if ( ! V_70 )
goto V_49;
V_44 -> V_40 = V_70 ;
for ( V_137 = 0 ; V_137 < V_64 ; V_137 ++ ) {
struct V_7 * V_8 = V_70 -> V_65 [ V_137 ] ;
struct V_1 * * V_24 ;
if ( ! V_8 )
break;
switch ( V_61 -> V_19 ) {
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
struct V_11 * V_138 ;
int V_139 ;
if ( ( * V_24 ) -> V_3 != V_4 )
continue;
V_138 = (struct V_11 * ) * V_24 ;
V_139 = ( ( V_138 -> V_25 & 0x80 ) >> 3 )
| ( V_138 -> V_25 & 0x0f ) ;
F_37 ( V_139 , V_8 -> V_131 ) ;
}
V_135 = V_8 -> V_47 ( V_8 , V_137 , 0 ) ;
if ( V_135 < 0 ) {
F_9 ( V_44 , L_11 ,
V_137 , V_8 -> V_45 , V_8 , V_135 ) ;
F_32 ( V_44 ) ;
goto V_49;
}
if ( V_135 == V_140 ) {
F_9 ( V_44 ,
L_12 ,
V_141 , V_137 , V_8 -> V_45 ) ;
V_44 -> V_142 ++ ;
F_9 ( V_44 , L_13 ,
V_44 -> V_142 ) ;
}
}
V_136 = V_70 -> V_80 ? ( 2 * V_70 -> V_80 ) : V_81 ;
V_49:
F_38 ( V_61 , V_136 ) ;
if ( V_135 >= 0 && V_44 -> V_142 )
V_135 = V_140 ;
return V_135 ;
}
int F_39 ( struct V_56 * V_44 ,
struct V_39 * V_40 ,
int (* V_52)( struct V_39 * ) )
{
int V_58 = - V_43 ;
struct V_39 * V_70 ;
F_9 ( V_44 , L_14 ,
V_40 -> V_77 ,
V_40 -> V_46 , V_40 ) ;
if ( ! V_40 -> V_77 || ! V_52 )
goto V_49;
F_24 (c, &cdev->configs, list) {
if ( V_70 -> V_77 == V_40 -> V_77 ) {
V_58 = - V_143 ;
goto V_49;
}
}
V_40 -> V_44 = V_44 ;
F_10 ( & V_40 -> V_50 , & V_44 -> V_144 ) ;
F_40 ( & V_40 -> V_51 ) ;
V_40 -> V_63 = 0 ;
V_58 = V_52 ( V_40 ) ;
if ( V_58 < 0 ) {
F_11 ( & V_40 -> V_50 ) ;
V_40 -> V_44 = NULL ;
} else {
unsigned V_145 ;
F_9 ( V_44 , L_15 ,
V_40 -> V_77 , V_40 ,
V_40 -> V_55 ? L_16 : L_17 ,
V_40 -> V_54 ? L_18 : L_17 ,
V_40 -> V_53
? ( F_4 ( V_44 -> V_61 )
? L_19
: L_20 )
: L_17 ) ;
for ( V_145 = 0 ; V_145 < V_64 ; V_145 ++ ) {
struct V_7 * V_8 = V_40 -> V_65 [ V_145 ] ;
if ( ! V_8 )
continue;
F_9 ( V_44 , L_21 ,
V_145 , V_8 -> V_45 , V_8 ) ;
}
}
F_41 ( V_44 -> V_61 ) ;
V_49:
if ( V_58 )
F_9 ( V_44 , L_22 , V_40 -> V_46 ,
V_40 -> V_77 , V_58 ) ;
return V_58 ;
}
static void F_42 ( struct V_146 * * V_147 , T_2 * V_68 )
{
const struct V_146 * V_148 ;
T_3 V_149 ;
T_2 * V_137 ;
while ( * V_147 ) {
V_148 = * V_147 ;
V_149 = F_25 ( V_148 -> V_149 ) ;
for ( V_137 = V_68 ; * V_137 && V_137 < & V_68 [ 126 ] ; V_137 ++ ) {
if ( * V_137 == V_149 )
goto V_150;
}
* V_137 ++ = V_149 ;
V_150:
V_147 ++ ;
}
}
static int F_43 (
struct V_146 * * V_147 ,
void * V_68 ,
T_3 V_149 ,
int V_62
)
{
struct V_146 * V_148 ;
int V_42 ;
while ( * V_147 ) {
V_148 = * V_147 ++ ;
if ( V_148 -> V_149 != V_149 )
continue;
V_42 = F_44 ( V_148 , V_62 , V_68 ) ;
if ( V_42 > 0 )
return V_42 ;
}
return - V_43 ;
}
static int F_45 ( struct V_56 * V_44 ,
void * V_68 , T_3 V_149 , int V_62 )
{
struct V_39 * V_70 ;
struct V_7 * V_8 ;
int V_73 ;
const char * V_151 ;
if ( V_62 == 0 ) {
struct V_152 * V_148 = V_68 ;
struct V_146 * * V_147 ;
memset ( V_148 , 0 , 256 ) ;
V_148 -> V_3 = V_153 ;
V_147 = V_154 -> V_155 ;
if ( V_147 )
F_42 ( V_147 , V_148 -> V_156 ) ;
F_24 (c, &cdev->configs, list) {
V_147 = V_70 -> V_155 ;
if ( V_147 )
F_42 ( V_147 , V_148 -> V_156 ) ;
F_24 (f, &c->functions, list) {
V_147 = V_8 -> V_155 ;
if ( V_147 )
F_42 ( V_147 , V_148 -> V_156 ) ;
}
}
for ( V_73 = 0 ; V_73 <= 126 && V_148 -> V_156 [ V_73 ] ; V_73 ++ )
continue;
if ( ! V_73 )
return - V_43 ;
V_148 -> V_75 = 2 * ( V_73 + 1 ) ;
return V_148 -> V_75 ;
}
if ( V_44 -> V_157 == V_62 )
V_151 = V_158 ? : V_154 -> V_158 ? :
V_159 ;
else if ( V_44 -> V_160 == V_62 )
V_151 = V_161 ? : V_154 -> V_161 ;
else if ( V_44 -> V_162 == V_62 )
V_151 = V_163 ;
else
V_151 = NULL ;
if ( V_151 ) {
struct V_146 V_155 = {
. V_149 = V_149 ,
. V_155 = & (struct V_164 ) { 0xff , V_151 }
} ;
return F_44 ( & V_155 , 0xff , V_68 ) ;
}
if ( V_154 -> V_155 ) {
V_73 = F_43 ( V_154 -> V_155 , V_68 , V_149 , V_62 ) ;
if ( V_73 > 0 )
return V_73 ;
}
F_24 (c, &cdev->configs, list) {
if ( V_70 -> V_155 ) {
V_73 = F_43 ( V_70 -> V_155 , V_68 , V_149 , V_62 ) ;
if ( V_73 > 0 )
return V_73 ;
}
F_24 (f, &c->functions, list) {
if ( ! V_8 -> V_155 )
continue;
V_73 = F_43 ( V_8 -> V_155 , V_68 , V_149 , V_62 ) ;
if ( V_73 > 0 )
return V_73 ;
}
}
return - V_43 ;
}
int F_46 ( struct V_56 * V_44 )
{
if ( V_44 -> V_165 < 254 ) {
V_44 -> V_165 ++ ;
return V_44 -> V_165 ;
}
return - V_66 ;
}
int F_47 ( struct V_56 * V_44 , struct V_164 * V_151 )
{
int V_71 = V_44 -> V_165 ;
for (; V_151 -> V_148 ; ++ V_151 ) {
if ( F_48 ( V_71 >= 254 ) )
return - V_66 ;
V_151 -> V_62 = ++ V_71 ;
}
V_44 -> V_165 = V_71 ;
return 0 ;
}
int F_49 ( struct V_56 * V_70 , unsigned V_166 )
{
unsigned V_71 = V_70 -> V_165 ;
if ( F_48 ( V_166 > 254 || ( unsigned ) V_71 + V_166 > 254 ) )
return - V_66 ;
V_70 -> V_165 += V_166 ;
return V_71 + 1 ;
}
static void F_50 ( struct V_9 * V_138 , struct V_167 * V_87 )
{
if ( V_87 -> V_58 || V_87 -> V_168 != V_87 -> V_169 )
F_9 ( (struct V_56 * ) V_138 -> V_170 ,
L_23 ,
V_87 -> V_58 , V_87 -> V_168 , V_87 -> V_169 ) ;
}
static int
F_51 ( struct V_5 * V_61 , const struct V_132 * V_133 )
{
struct V_56 * V_44 = F_52 ( V_61 ) ;
struct V_167 * V_87 = V_44 -> V_87 ;
int V_42 = - V_171 ;
int V_58 = 0 ;
T_3 V_172 = F_6 ( V_133 -> V_173 ) ;
T_1 V_174 = V_172 & 0xFF ;
T_3 V_83 = F_6 ( V_133 -> V_175 ) ;
T_3 V_176 = F_6 ( V_133 -> V_177 ) ;
struct V_7 * V_8 = NULL ;
T_1 V_178 ;
V_87 -> V_179 = 0 ;
V_87 -> V_180 = F_50 ;
V_87 -> V_169 = 0 ;
V_61 -> V_128 -> V_170 = V_44 ;
switch ( V_133 -> V_181 ) {
case V_182 :
if ( V_133 -> V_183 != V_184 )
goto V_185;
switch ( V_83 >> 8 ) {
case V_186 :
V_44 -> V_30 . V_129 =
F_27 ( V_44 , V_186 ) ;
V_44 -> V_30 . V_127 =
V_44 -> V_61 -> V_128 -> V_28 ;
if ( F_3 ( V_61 ) ) {
if ( V_61 -> V_19 >= V_20 ) {
V_44 -> V_30 . V_123 = F_25 ( 0x0300 ) ;
V_44 -> V_30 . V_127 = 9 ;
} else {
V_44 -> V_30 . V_123 = F_25 ( 0x0210 ) ;
}
}
V_42 = F_53 ( V_176 , ( T_3 ) sizeof V_44 -> V_30 ) ;
memcpy ( V_87 -> V_68 , & V_44 -> V_30 , V_42 ) ;
break;
case V_90 :
if ( ! F_4 ( V_61 ) ||
V_61 -> V_19 >= V_20 )
break;
F_31 ( V_44 ) ;
V_42 = F_54 ( int , V_176 ,
sizeof( struct V_121 ) ) ;
break;
case V_86 :
if ( ! F_4 ( V_61 ) ||
V_61 -> V_19 >= V_20 )
break;
case V_187 :
V_42 = F_26 ( V_44 , V_83 ) ;
if ( V_42 >= 0 )
V_42 = F_53 ( V_176 , ( T_3 ) V_42 ) ;
break;
case V_153 :
V_42 = F_45 ( V_44 , V_87 -> V_68 ,
V_172 , V_83 & 0xff ) ;
if ( V_42 >= 0 )
V_42 = F_53 ( V_176 , ( T_3 ) V_42 ) ;
break;
case V_100 :
if ( F_3 ( V_61 ) ) {
V_42 = F_28 ( V_44 ) ;
V_42 = F_53 ( V_176 , ( T_3 ) V_42 ) ;
}
break;
}
break;
case V_188 :
if ( V_133 -> V_183 != 0 )
goto V_185;
if ( F_35 ( V_61 ) ) {
if ( V_61 -> V_189 )
F_9 ( V_44 , L_24 ) ;
else if ( V_61 -> V_190 )
F_9 ( V_44 , L_25 ) ;
else
F_55 ( V_44 , L_26 ) ;
}
F_17 ( & V_44 -> V_59 ) ;
V_42 = F_34 ( V_44 , V_133 , V_83 ) ;
F_20 ( & V_44 -> V_59 ) ;
break;
case V_191 :
if ( V_133 -> V_183 != V_184 )
goto V_185;
if ( V_44 -> V_40 )
* ( T_1 * ) V_87 -> V_68 = V_44 -> V_40 -> V_77 ;
else
* ( T_1 * ) V_87 -> V_68 = 0 ;
V_42 = F_53 ( V_176 , ( T_3 ) 1 ) ;
break;
case V_192 :
if ( V_133 -> V_183 != V_193 )
goto V_185;
if ( ! V_44 -> V_40 || V_174 >= V_64 )
break;
V_8 = V_44 -> V_40 -> V_65 [ V_174 ] ;
if ( ! V_8 )
break;
if ( V_83 && ! V_8 -> V_47 )
break;
V_42 = V_8 -> V_47 ( V_8 , V_172 , V_83 ) ;
if ( V_42 == V_140 ) {
F_9 ( V_44 ,
L_12 ,
V_141 , V_174 , V_8 -> V_45 ) ;
V_44 -> V_142 ++ ;
F_9 ( V_44 , L_13 ,
V_44 -> V_142 ) ;
}
break;
case V_194 :
if ( V_133 -> V_183 != ( V_184 | V_193 ) )
goto V_185;
if ( ! V_44 -> V_40 || V_174 >= V_64 )
break;
V_8 = V_44 -> V_40 -> V_65 [ V_174 ] ;
if ( ! V_8 )
break;
V_42 = V_8 -> V_195 ? V_8 -> V_195 ( V_8 , V_172 ) : 0 ;
if ( V_42 < 0 )
break;
* ( ( T_1 * ) V_87 -> V_68 ) = V_42 ;
V_42 = F_53 ( V_176 , ( T_3 ) 1 ) ;
break;
case V_196 :
if ( ! F_3 ( V_61 ) )
goto V_185;
if ( V_133 -> V_183 != ( V_184 | V_193 ) )
goto V_185;
V_42 = 2 ;
F_56 ( 0 , V_87 -> V_68 ) ;
if ( ! V_44 -> V_40 || V_174 >= V_64 )
break;
V_8 = V_44 -> V_40 -> V_65 [ V_174 ] ;
if ( ! V_8 )
break;
V_58 = V_8 -> V_197 ? V_8 -> V_197 ( V_8 ) : 0 ;
if ( V_58 < 0 )
break;
F_56 ( V_58 & 0x0000ffff , V_87 -> V_68 ) ;
break;
case V_198 :
case V_199 :
if ( ! F_3 ( V_61 ) )
goto V_185;
if ( V_133 -> V_183 != ( V_200 | V_193 ) )
goto V_185;
switch ( V_83 ) {
case V_201 :
if ( ! V_44 -> V_40 || V_174 >= V_64 )
break;
V_8 = V_44 -> V_40 -> V_65 [ V_174 ] ;
if ( ! V_8 )
break;
V_42 = 0 ;
if ( V_8 -> V_202 )
V_42 = V_8 -> V_202 ( V_8 , V_172 >> 8 ) ;
if ( V_42 < 0 ) {
ERROR ( V_44 ,
L_27 ,
V_42 ) ;
V_42 = 0 ;
}
break;
}
break;
default:
V_185:
F_55 ( V_44 ,
L_28 ,
V_133 -> V_183 , V_133 -> V_181 ,
V_83 , V_172 , V_176 ) ;
switch ( V_133 -> V_183 & V_203 ) {
case V_193 :
if ( ! V_44 -> V_40 || V_174 >= V_64 )
break;
V_8 = V_44 -> V_40 -> V_65 [ V_174 ] ;
break;
case V_204 :
V_178 = ( ( V_172 & 0x80 ) >> 3 ) | ( V_172 & 0x0f ) ;
F_24 (f, &cdev->config->functions, list) {
if ( F_57 ( V_178 , V_8 -> V_131 ) )
break;
}
if ( & V_8 -> V_50 == & V_44 -> V_40 -> V_51 )
V_8 = NULL ;
break;
}
if ( V_8 && V_8 -> V_205 )
V_42 = V_8 -> V_205 ( V_8 , V_133 ) ;
else {
struct V_39 * V_70 ;
V_70 = V_44 -> V_40 ;
if ( V_70 && V_70 -> V_205 )
V_42 = V_70 -> V_205 ( V_70 , V_133 ) ;
}
goto V_49;
}
if ( V_42 >= 0 && V_42 != V_140 ) {
V_87 -> V_169 = V_42 ;
V_87 -> V_179 = V_42 < V_176 ;
V_42 = F_58 ( V_61 -> V_128 , V_87 , V_206 ) ;
if ( V_42 < 0 ) {
F_9 ( V_44 , L_29 , V_42 ) ;
V_87 -> V_58 = 0 ;
F_50 ( V_61 -> V_128 , V_87 ) ;
}
} else if ( V_42 == V_140 && V_176 != 0 ) {
F_59 ( V_44 ,
L_30 ,
V_141 ) ;
}
V_49:
return V_42 ;
}
static void F_60 ( struct V_5 * V_61 )
{
struct V_56 * V_44 = F_52 ( V_61 ) ;
unsigned long V_57 ;
F_13 ( & V_44 -> V_59 , V_57 ) ;
if ( V_44 -> V_40 )
F_32 ( V_44 ) ;
if ( V_154 -> V_207 )
V_154 -> V_207 ( V_44 ) ;
F_15 ( & V_44 -> V_59 , V_57 ) ;
}
static T_4 F_61 ( struct V_208 * V_209 ,
struct V_210 * V_211 ,
char * V_68 )
{
struct V_5 * V_61 = F_62 ( V_209 ) ;
struct V_56 * V_44 = F_52 ( V_61 ) ;
return sprintf ( V_68 , L_31 , V_44 -> V_212 ) ;
}
static void
F_63 ( struct V_5 * V_61 )
{
struct V_56 * V_44 = F_52 ( V_61 ) ;
F_18 ( V_44 -> V_40 ) ;
while ( ! F_64 ( & V_44 -> V_144 ) ) {
struct V_39 * V_70 ;
V_70 = F_65 ( & V_44 -> V_144 ,
struct V_39 , V_50 ) ;
while ( ! F_64 ( & V_70 -> V_51 ) ) {
struct V_7 * V_8 ;
V_8 = F_65 ( & V_70 -> V_51 ,
struct V_7 , V_50 ) ;
F_11 ( & V_8 -> V_50 ) ;
if ( V_8 -> V_213 ) {
F_9 ( V_44 , L_32 ,
V_8 -> V_45 , V_8 ) ;
V_8 -> V_213 ( V_70 , V_8 ) ;
}
}
F_11 ( & V_70 -> V_50 ) ;
if ( V_70 -> V_213 ) {
F_9 ( V_44 , L_33 , V_70 -> V_46 , V_70 ) ;
V_70 -> V_213 ( V_70 ) ;
}
}
if ( V_154 -> V_213 )
V_154 -> V_213 ( V_44 ) ;
if ( V_44 -> V_87 ) {
F_66 ( V_44 -> V_87 -> V_68 ) ;
F_67 ( V_61 -> V_128 , V_44 -> V_87 ) ;
}
F_68 ( & V_61 -> V_209 , & V_214 ) ;
F_66 ( V_44 ) ;
F_69 ( V_61 , NULL ) ;
V_154 = NULL ;
}
static T_1 F_70 ( struct V_56 * V_44 , T_1 * V_30 )
{
if ( ! * V_30 ) {
int V_215 = F_46 ( V_44 ) ;
if ( F_48 ( V_215 < 0 ) )
F_71 ( V_44 , L_34 ) ;
else
* V_30 = V_215 ;
}
return * V_30 ;
}
static int F_72 ( struct V_5 * V_61 )
{
struct V_56 * V_44 ;
int V_58 = - V_216 ;
V_44 = F_73 ( sizeof *V_44 , V_217 ) ;
if ( ! V_44 )
return V_58 ;
F_74 ( & V_44 -> V_59 ) ;
V_44 -> V_61 = V_61 ;
F_69 ( V_61 , V_44 ) ;
F_40 ( & V_44 -> V_144 ) ;
V_44 -> V_87 = F_75 ( V_61 -> V_128 , V_217 ) ;
if ( ! V_44 -> V_87 )
goto V_218;
V_44 -> V_87 -> V_68 = F_76 ( V_74 , V_217 ) ;
if ( ! V_44 -> V_87 -> V_68 )
goto V_218;
V_44 -> V_87 -> V_180 = F_50 ;
V_61 -> V_128 -> V_170 = V_44 ;
V_44 -> V_219 = V_74 ;
V_44 -> V_220 = V_154 ;
if ( V_81 <= V_221 )
F_77 ( V_61 ) ;
F_41 ( V_44 -> V_61 ) ;
V_58 = F_78 ( V_44 ) ;
if ( V_58 < 0 )
goto V_218;
V_44 -> V_30 = * V_154 -> V_209 ;
if ( V_222 )
V_44 -> V_30 . V_222 = F_25 ( V_222 ) ;
if ( V_223 )
V_44 -> V_30 . V_223 = F_25 ( V_223 ) ;
if ( V_224 )
V_44 -> V_30 . V_224 = F_25 ( V_224 ) ;
if ( V_158 || ! V_44 -> V_30 . V_158 ) {
if ( ! V_158 && ! V_154 -> V_158 &&
! * V_159 )
snprintf ( V_159 ,
sizeof V_159 ,
L_35 ,
F_79 () -> V_225 ,
F_79 () -> V_226 ,
V_61 -> V_45 ) ;
V_44 -> V_157 =
F_70 ( V_44 , & V_44 -> V_30 . V_158 ) ;
}
if ( V_161 || ( ! V_44 -> V_30 . V_161 && V_154 -> V_161 ) )
V_44 -> V_160 =
F_70 ( V_44 , & V_44 -> V_30 . V_161 ) ;
if ( V_163 )
V_44 -> V_162 =
F_70 ( V_44 , & V_44 -> V_30 . V_163 ) ;
if ( V_154 -> V_227 && ! V_44 -> V_30 . V_163 )
F_71 ( V_44 , L_36 ) ;
V_58 = F_80 ( & V_61 -> V_209 , & V_214 ) ;
if ( V_58 )
goto V_218;
F_36 ( V_44 , L_37 , V_154 -> V_45 ) ;
return 0 ;
V_218:
F_63 ( V_61 ) ;
return V_58 ;
}
static void
F_81 ( struct V_5 * V_61 )
{
struct V_56 * V_44 = F_52 ( V_61 ) ;
struct V_7 * V_8 ;
F_9 ( V_44 , L_38 ) ;
if ( V_44 -> V_40 ) {
F_24 (f, &cdev->config->functions, list) {
if ( V_8 -> V_228 )
V_8 -> V_228 ( V_8 ) ;
}
}
if ( V_154 -> V_228 )
V_154 -> V_228 ( V_44 ) ;
V_44 -> V_212 = 1 ;
F_38 ( V_61 , 2 ) ;
}
static void
F_82 ( struct V_5 * V_61 )
{
struct V_56 * V_44 = F_52 ( V_61 ) ;
struct V_7 * V_8 ;
T_1 V_229 ;
F_9 ( V_44 , L_39 ) ;
if ( V_154 -> V_230 )
V_154 -> V_230 ( V_44 ) ;
if ( V_44 -> V_40 ) {
F_24 (f, &cdev->config->functions, list) {
if ( V_8 -> V_230 )
V_8 -> V_230 ( V_8 ) ;
}
V_229 = V_44 -> V_40 -> V_80 ;
F_38 ( V_61 , V_229 ?
( 2 * V_229 ) : V_81 ) ;
}
V_44 -> V_212 = 0 ;
}
int F_83 ( struct V_231 * V_220 ,
int (* V_52)( struct V_56 * V_44 ) )
{
if ( ! V_220 || ! V_220 -> V_209 || ! V_52 || V_154 )
return - V_43 ;
if ( ! V_220 -> V_45 )
V_220 -> V_45 = L_40 ;
if ( ! V_220 -> V_161 )
V_220 -> V_161 = V_220 -> V_45 ;
V_232 . V_41 = ( char * ) V_220 -> V_45 ;
V_232 . V_220 . V_45 = V_220 -> V_45 ;
V_232 . V_19 = F_53 ( ( T_1 ) V_232 . V_19 ,
( T_1 ) V_220 -> V_233 ) ;
V_154 = V_220 ;
F_78 = V_52 ;
return F_84 ( & V_232 , F_72 ) ;
}
void F_85 ( struct V_231 * V_220 )
{
if ( V_154 != V_220 )
return;
F_86 ( & V_232 ) ;
}
void F_87 ( struct V_56 * V_44 )
{
int V_42 ;
struct V_167 * V_87 = V_44 -> V_87 ;
unsigned long V_57 ;
F_9 ( V_44 , L_41 , V_141 ) ;
F_13 ( & V_44 -> V_59 , V_57 ) ;
if ( V_44 -> V_142 == 0 ) {
F_59 ( V_44 , L_42 , V_141 ) ;
} else if ( -- V_44 -> V_142 == 0 ) {
F_9 ( V_44 , L_43 , V_141 ) ;
V_87 -> V_169 = 0 ;
V_42 = F_58 ( V_44 -> V_61 -> V_128 , V_87 , V_206 ) ;
if ( V_42 < 0 ) {
F_9 ( V_44 , L_29 , V_42 ) ;
V_87 -> V_58 = 0 ;
F_50 ( V_44 -> V_61 -> V_128 , V_87 ) ;
}
}
F_15 ( & V_44 -> V_59 , V_57 ) ;
}
