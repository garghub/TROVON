static int F_1 ( unsigned V_1 , unsigned V_2 , unsigned V_3 ,
unsigned V_4 , unsigned V_5 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_11 * V_12 = V_9 -> V_13 . V_12 ;
T_1 V_14 ;
if ( ! V_12 )
return - V_15 ;
if ( V_1 > 255 )
return 1 ;
V_2 = F_2 ( V_2 , V_7 -> V_16 . V_2 . V_17 ) ;
V_4 = F_2 ( V_4 , V_7 -> V_16 . V_4 . V_17 ) ;
V_3 = F_2 ( V_3 , V_7 -> V_16 . V_3 . V_17 ) ;
V_5 = F_2 ( V_5 , V_7 -> V_16 . V_5 . V_17 ) ;
V_14 = ( V_2 << V_7 -> V_16 . V_2 . V_18 ) |
( V_3 << V_7 -> V_16 . V_3 . V_18 ) |
( V_4 << V_7 -> V_16 . V_4 . V_18 ) |
( V_5 << V_7 -> V_16 . V_5 . V_18 ) ;
if ( V_1 < 16 ) {
switch ( V_12 -> V_19 ) {
case 16 :
( ( T_1 * ) V_7 -> V_20 ) [ V_1 ] = V_14 ;
break;
case 24 :
case 32 :
( ( T_1 * ) V_7 -> V_20 ) [ V_1 ] = V_14 ;
break;
}
}
return 0 ;
}
static int F_3 ( struct V_21 * V_16 , struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_22 * V_23 = & V_9 -> V_24 ;
struct V_25 * V_26 = V_23 -> V_27 . V_26 ;
if ( V_23 -> V_28 -> V_29 )
F_4 ( V_26 , V_23 -> V_28 , V_16 -> V_30 ) ;
return 0 ;
}
void F_5 ( struct V_25 * V_26 )
{
struct V_11 * V_12 = 0 ;
struct V_22 * V_23 = F_6 ( V_12 ) ;
F_7 () ;
F_8 ( & V_26 -> V_31 . V_32 ) ;
F_9 (fb, &dev->mode_config.fb_list, head) {
struct V_6 * V_7 = V_23 -> V_9 ;
F_10 ( V_7 , 1 ) ;
F_11 ( V_33 , V_7 ) ;
}
F_12 ( & V_26 -> V_31 . V_32 ) ;
F_13 () ;
}
void F_14 ( struct V_25 * V_26 )
{
struct V_11 * V_12 = 0 ;
struct V_22 * V_23 = F_6 ( V_12 ) ;
F_7 () ;
F_8 ( & V_26 -> V_31 . V_32 ) ;
F_9 (fb, &dev->mode_config.fb_list, head) {
struct V_6 * V_7 = V_23 -> V_9 ;
F_10 ( V_7 , 0 ) ;
F_11 ( V_34 , V_7 ) ;
}
F_12 ( & V_26 -> V_31 . V_32 ) ;
F_13 () ;
F_15 ( V_26 ) ;
}
static int F_16 ( struct V_35 * V_36 , struct V_37 * V_38 )
{
struct V_22 * V_23 = V_36 -> V_39 ;
struct V_25 * V_26 = V_23 -> V_27 . V_26 ;
struct V_40 * V_41 = V_26 -> V_42 ;
int V_43 ;
int V_44 ;
unsigned long V_45 ;
int V_46 ;
unsigned long V_47 ;
unsigned long V_48 = ( unsigned long ) V_41 -> V_49 ;
V_43 = ( V_36 -> V_50 - V_36 -> V_51 ) >> V_52 ;
V_45 = ( unsigned long ) V_38 -> V_53 ;
V_36 -> V_54 = F_17 ( V_36 -> V_54 ) ;
for ( V_44 = 0 ; V_44 < V_43 ; V_44 ++ ) {
V_47 = ( V_48 >> V_52 ) ;
V_46 = F_18 ( V_36 , V_45 , V_47 ) ;
if ( F_19 ( ( V_46 == - V_55 ) || ( V_46 != 0 && V_44 > 0 ) ) )
break;
else if ( F_19 ( V_46 != 0 ) ) {
V_46 = ( V_46 == - V_15 ) ? V_56 : V_57 ;
return V_46 ;
}
V_45 += V_58 ;
V_48 += V_58 ;
}
return V_59 ;
}
static void F_20 ( struct V_35 * V_36 )
{
}
static void F_21 ( struct V_35 * V_36 )
{
}
static int F_22 ( struct V_6 * V_7 , struct V_35 * V_36 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_22 * V_23 = & V_9 -> V_24 ;
if ( V_36 -> V_60 != 0 )
return - V_61 ;
if ( V_36 -> V_60 > ( ~ 0UL >> V_52 ) )
return - V_61 ;
if ( ! V_23 -> V_62 )
V_23 -> V_62 = V_36 -> V_63 -> V_64 ;
V_36 -> V_65 = & V_66 ;
V_36 -> V_39 = ( void * ) V_23 ;
V_36 -> V_67 |= V_68 | V_69 |
V_70 | V_71 ;
return 0 ;
}
static int F_23 ( struct V_6 * V_7 , unsigned int V_72 ,
unsigned long V_73 )
{
return - V_74 ;
}
static int F_24 ( struct V_25 * V_26 ,
struct V_22 * V_12 ,
struct V_75 * V_76 ,
struct V_77 * V_78 )
{
int V_46 ;
if ( V_76 -> V_79 & 63 )
return - V_61 ;
switch ( V_76 -> V_80 ) {
case 8 :
case 16 :
case 24 :
case 32 :
break;
default:
return - V_61 ;
}
V_46 = F_25 ( V_26 , & V_12 -> V_27 , & V_81 ) ;
if ( V_46 ) {
F_26 ( V_26 -> V_26 , L_1 , V_46 ) ;
return V_46 ;
}
F_27 ( & V_12 -> V_27 , V_76 ) ;
V_12 -> V_28 = V_78 ;
return 0 ;
}
static struct V_11 * F_28
( struct V_25 * V_26 ,
struct V_75 * V_76 ,
struct V_77 * V_78 )
{
struct V_22 * V_12 ;
int V_46 ;
V_12 = F_29 ( sizeof( * V_12 ) , V_82 ) ;
if ( ! V_12 )
return F_30 ( - V_15 ) ;
V_46 = F_24 ( V_26 , V_12 , V_76 , V_78 ) ;
if ( V_46 ) {
F_31 ( V_12 ) ;
return F_30 ( V_46 ) ;
}
return & V_12 -> V_27 ;
}
static struct V_77 * F_32 ( struct V_25 * V_26 ,
int V_83 , int V_84 )
{
struct V_77 * V_85 ;
V_85 = F_33 ( V_26 , V_83 , L_2 , 1 ) ;
if ( V_85 ) {
if ( F_34 ( V_26 ,
& V_85 -> V_86 , V_83 ) == 0 )
return V_85 ;
F_35 ( V_26 , V_85 ) ;
}
if ( ! V_84 )
return NULL ;
V_85 = F_33 ( V_26 , V_83 , L_3 , 0 ) ;
if ( V_85 == NULL )
return NULL ;
if ( F_36 ( V_26 , & V_85 -> V_86 , V_83 ) != 0 ) {
F_35 ( V_26 , V_85 ) ;
return NULL ;
}
return V_85 ;
}
static int F_37 ( struct V_8 * V_9 ,
struct V_87 * V_88 )
{
struct V_25 * V_26 = V_9 -> V_13 . V_26 ;
struct V_40 * V_41 = V_26 -> V_42 ;
struct V_6 * V_7 ;
struct V_11 * V_12 ;
struct V_22 * V_23 = & V_9 -> V_24 ;
struct V_75 V_76 ;
struct V_89 * V_89 = & V_26 -> V_90 -> V_26 ;
int V_91 ;
int V_46 ;
struct V_77 * V_85 ;
int V_92 = 1 ;
V_76 . V_93 = V_88 -> V_94 ;
V_76 . V_95 = V_88 -> V_96 ;
V_76 . V_80 = V_88 -> V_97 ;
if ( V_76 . V_80 == 24 )
V_76 . V_80 = 32 ;
V_76 . V_79 = F_38 ( V_76 . V_93 * ( ( V_76 . V_80 + 7 ) / 8 ) , 4096 ) ;
V_76 . V_98 = V_88 -> V_99 ;
V_91 = V_76 . V_79 * V_76 . V_95 ;
V_91 = F_38 ( V_91 , V_58 ) ;
V_85 = F_32 ( V_26 , V_91 , 0 ) ;
if ( V_85 == NULL ) {
V_92 = 0 ;
V_76 . V_79 = F_38 ( V_76 . V_93 * ( ( V_76 . V_80 + 7 ) / 8 ) , 64 ) ;
V_76 . V_98 = V_88 -> V_99 ;
V_91 = V_76 . V_79 * V_76 . V_95 ;
V_91 = F_38 ( V_91 , V_58 ) ;
V_85 = F_32 ( V_26 , V_91 , 1 ) ;
if ( V_85 == NULL )
return - V_15 ;
}
F_8 ( & V_26 -> V_100 ) ;
V_7 = F_39 ( 0 , V_89 ) ;
if ( ! V_7 ) {
V_46 = - V_15 ;
goto V_101;
}
V_7 -> V_10 = V_9 ;
V_46 = F_24 ( V_26 , V_23 , & V_76 , V_85 ) ;
if ( V_46 )
goto V_102;
V_12 = & V_23 -> V_27 ;
V_23 -> V_9 = V_7 ;
V_9 -> V_13 . V_12 = V_12 ;
V_9 -> V_13 . V_9 = V_7 ;
strcpy ( V_7 -> V_103 . V_104 , L_4 ) ;
V_7 -> V_105 = V_106 ;
if ( V_92 ) {
V_7 -> V_107 = & V_108 ;
V_7 -> V_105 |= V_109 ;
}
else if ( V_41 -> V_110 -> V_111 )
V_7 -> V_107 = & V_112 ;
else
V_7 -> V_107 = & V_113 ;
V_46 = F_40 ( & V_7 -> V_114 , 256 , 0 ) ;
if ( V_46 ) {
V_46 = - V_15 ;
goto V_102;
}
V_7 -> V_103 . V_115 = V_26 -> V_31 . V_116 ;
V_7 -> V_103 . V_117 = V_91 ;
V_7 -> V_103 . V_118 = V_92 ;
V_7 -> V_103 . V_119 = V_92 ;
if ( V_85 -> V_120 ) {
V_7 -> V_121 = ( char * ) V_41 -> V_122 +
V_85 -> V_18 ;
} else {
F_41 ( V_85 ) ;
V_7 -> V_121 = F_42 ( V_85 -> V_123 , V_85 -> V_29 ,
- 1 , V_124 ) ;
if ( V_7 -> V_121 == NULL ) {
F_43 ( V_85 ) ;
V_46 = - V_15 ;
goto V_102;
}
V_23 -> V_125 = 1 ;
}
V_7 -> V_126 = V_91 ;
if ( V_41 -> V_28 . V_127 ) {
V_7 -> V_128 = F_44 ( 1 ) ;
if ( ! V_7 -> V_128 ) {
V_46 = - V_15 ;
goto V_102;
}
V_7 -> V_128 -> V_129 [ 0 ] . V_27 = V_26 -> V_31 . V_116 ;
V_7 -> V_128 -> V_129 [ 0 ] . V_91 = V_41 -> V_28 . V_127 ;
}
F_45 ( V_7 , V_12 -> V_79 , V_12 -> V_98 ) ;
F_46 ( V_7 , & V_9 -> V_13 ,
V_88 -> V_130 , V_88 -> V_131 ) ;
V_7 -> V_103 . V_132 = F_47 ( V_26 -> V_90 , 0 ) ;
V_7 -> V_103 . V_133 = F_48 ( V_26 -> V_90 , 0 ) ;
V_7 -> V_134 . V_91 = 64 * 1024 ;
V_7 -> V_134 . V_135 = 8 ;
V_7 -> V_134 . V_136 = 32 ;
V_7 -> V_134 . V_105 = V_137 ;
V_7 -> V_134 . V_138 = 1 ;
F_49 ( V_26 -> V_26 , L_5 ,
V_23 -> V_27 . V_93 , V_23 -> V_27 . V_95 ) ;
F_12 ( & V_26 -> V_100 ) ;
return 0 ;
V_102:
if ( V_85 -> V_120 )
F_35 ( V_26 , V_85 ) ;
else {
if ( V_23 -> V_125 )
F_50 ( V_7 -> V_121 , V_85 -> V_29 ) ;
F_51 ( & V_85 -> V_86 ) ;
}
V_101:
F_12 ( & V_26 -> V_100 ) ;
F_35 ( V_26 , V_85 ) ;
return V_46 ;
}
static struct V_11 * F_52
( struct V_25 * V_26 , struct V_139 * V_140 ,
struct V_75 * V_72 )
{
struct V_77 * V_141 ;
struct V_142 * V_143 ;
V_143 = F_53 ( V_26 , V_140 , V_72 -> V_144 ) ;
if ( V_143 == NULL )
return F_30 ( - V_145 ) ;
V_141 = F_54 ( V_143 , struct V_77 , V_86 ) ;
return F_28 ( V_26 , V_72 , V_141 ) ;
}
static void F_55 ( struct V_146 * V_147 , T_2 V_2 , T_2 V_3 ,
T_2 V_4 , int V_1 )
{
}
static void F_56 ( struct V_146 * V_147 , T_2 * V_2 ,
T_2 * V_3 , T_2 * V_4 , int V_1 )
{
}
static int F_57 ( struct V_148 * V_149 ,
struct V_87 * V_88 )
{
struct V_8 * V_8 = (struct V_8 * ) V_149 ;
int V_150 = 0 ;
int V_46 ;
if ( ! V_149 -> V_12 ) {
V_46 = F_37 ( V_8 , V_88 ) ;
if ( V_46 )
return V_46 ;
V_150 = 1 ;
}
return V_150 ;
}
int F_58 ( struct V_25 * V_26 , struct V_8 * V_9 )
{
struct V_6 * V_7 ;
struct V_22 * V_23 = & V_9 -> V_24 ;
if ( V_9 -> V_13 . V_9 ) {
V_7 = V_9 -> V_13 . V_9 ;
if ( V_23 -> V_125 ) {
F_50 ( V_7 -> V_121 , V_23 -> V_28 -> V_29 ) ;
F_43 ( V_23 -> V_28 ) ;
}
F_59 ( V_7 ) ;
if ( V_7 -> V_114 . V_151 )
F_60 ( & V_7 -> V_114 ) ;
F_61 ( V_7 ) ;
}
F_62 ( & V_9 -> V_13 ) ;
F_63 ( & V_23 -> V_27 ) ;
if ( V_23 -> V_28 )
F_51 ( & V_23 -> V_28 -> V_86 ) ;
return 0 ;
}
int F_64 ( struct V_25 * V_26 )
{
struct V_8 * V_9 ;
struct V_40 * V_41 = V_26 -> V_42 ;
V_9 = F_29 ( sizeof( struct V_8 ) , V_82 ) ;
if ( ! V_9 ) {
F_26 ( V_26 -> V_26 , L_6 ) ;
return - V_15 ;
}
V_41 -> V_9 = V_9 ;
V_9 -> V_13 . V_152 = & V_153 ;
F_65 ( V_26 , & V_9 -> V_13 , V_41 -> V_110 -> V_154 ,
V_155 ) ;
F_66 ( & V_9 -> V_13 ) ;
F_67 ( & V_9 -> V_13 , 32 ) ;
return 0 ;
}
void F_68 ( struct V_25 * V_26 )
{
struct V_40 * V_41 = V_26 -> V_42 ;
if ( ! V_41 -> V_9 )
return;
F_58 ( V_26 , V_41 -> V_9 ) ;
F_31 ( V_41 -> V_9 ) ;
V_41 -> V_9 = NULL ;
}
static void F_69 ( struct V_25 * V_26 )
{
struct V_40 * V_41 = V_26 -> V_42 ;
struct V_8 * V_9 = (struct V_8 * ) V_41 -> V_9 ;
F_70 ( & V_9 -> V_13 ) ;
}
static int F_71 ( struct V_11 * V_12 ,
struct V_139 * V_156 ,
unsigned int * V_144 )
{
struct V_22 * V_23 = F_6 ( V_12 ) ;
struct V_77 * V_141 = V_23 -> V_28 ;
return F_72 ( V_156 , & V_141 -> V_86 , V_144 ) ;
}
static void F_73 ( struct V_11 * V_12 )
{
struct V_22 * V_23 = F_6 ( V_12 ) ;
struct V_77 * V_141 = V_23 -> V_28 ;
struct V_25 * V_26 = V_12 -> V_26 ;
struct V_40 * V_41 = V_26 -> V_42 ;
struct V_8 * V_9 = V_41 -> V_9 ;
struct V_146 * V_147 ;
int V_157 = 0 ;
F_74 ( V_141 -> V_120 ) ;
F_9 (crtc, &dev->mode_config.crtc_list, head)
if ( V_147 -> V_12 == V_12 )
V_157 = 1 ;
if ( V_157 )
F_75 ( & V_9 -> V_13 ) ;
F_63 ( V_12 ) ;
F_76 ( & V_141 -> V_86 ) ;
F_31 ( V_12 ) ;
}
static int F_77 ( struct V_25 * V_26 )
{
struct V_40 * V_41 = V_26 -> V_42 ;
struct V_158 * V_159 ;
if ( V_41 -> V_160 )
return 0 ;
V_159 = F_78 ( V_26 , V_161 ,
L_7 , 2 ) ;
V_159 -> V_162 [ 0 ] = 0 ;
V_159 -> V_162 [ 1 ] = 100 ;
V_41 -> V_160 = V_159 ;
return 0 ;
}
static void F_79 ( struct V_25 * V_26 )
{
struct V_40 * V_41 = V_26 -> V_42 ;
struct V_163 * V_164 ;
F_80 ( V_26 ) ;
F_77 ( V_26 ) ;
V_41 -> V_110 -> V_165 ( V_26 ) ;
F_9 (connector, &dev->mode_config.connector_list,
head) {
struct V_166 * V_166 =
F_81 ( V_164 ) ;
struct V_167 * V_168 = & V_166 -> V_169 ;
int V_170 = 0 , V_171 = 0 ;
switch ( V_166 -> type ) {
case V_172 :
V_170 = ( 1 << 0 ) ;
V_171 = ( 1 << V_172 ) ;
break;
case V_173 :
V_170 = ( ( 1 << 0 ) | ( 1 << 1 ) ) ;
V_171 = ( 1 << V_173 ) ;
break;
case V_174 :
if ( F_82 ( V_26 ) )
V_170 = ( 1 << 0 ) ;
else
V_170 = ( 1 << 1 ) ;
V_171 = ( 1 << V_174 ) ;
break;
case V_175 :
V_170 = ( 1 << 0 ) ;
V_171 = ( 1 << V_175 ) ;
break;
case V_176 :
V_170 = ( 1 << 2 ) ;
V_171 = ( 1 << V_176 ) ;
break;
case V_177 :
if ( F_83 ( V_26 ) || F_82 ( V_26 ) )
V_170 = ( 1 << 1 ) ;
else
V_170 = ( 1 << 0 ) ;
V_171 = ( 1 << V_177 ) ;
break;
}
V_168 -> V_178 = V_170 ;
V_168 -> V_179 =
F_84 ( V_26 , V_171 ) ;
}
}
void F_85 ( struct V_25 * V_26 )
{
struct V_40 * V_41 =
(struct V_40 * ) V_26 -> V_42 ;
struct V_180 * V_181 = & V_41 -> V_181 ;
int V_44 ;
F_86 ( V_26 ) ;
V_26 -> V_31 . V_182 = 0 ;
V_26 -> V_31 . V_183 = 0 ;
V_26 -> V_31 . V_152 = ( void * ) & V_184 ;
F_87 ( V_26 -> V_90 , V_185 , ( V_186 * )
& ( V_26 -> V_31 . V_116 ) ) ;
for ( V_44 = 0 ; V_44 < V_41 -> V_187 ; V_44 ++ )
F_88 ( V_26 , V_44 , V_181 ) ;
V_26 -> V_31 . V_188 = 2048 ;
V_26 -> V_31 . V_189 = 2048 ;
F_79 ( V_26 ) ;
}
void F_89 ( struct V_25 * V_26 )
{
F_8 ( & V_26 -> V_100 ) ;
F_90 ( V_26 ) ;
F_68 ( V_26 ) ;
F_91 ( V_26 ) ;
F_12 ( & V_26 -> V_100 ) ;
}
