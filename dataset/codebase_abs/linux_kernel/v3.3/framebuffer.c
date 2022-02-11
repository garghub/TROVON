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
if ( V_23 -> V_28 -> V_29 ) {
int V_30 = V_7 -> V_31 . V_32 >> 12 ;
F_4 ( V_26 , V_23 -> V_28 , V_16 -> V_33 * V_30 ) ;
}
return 0 ;
}
void F_5 ( struct V_25 * V_26 )
{
struct V_11 * V_12 ;
F_6 () ;
F_7 ( & V_26 -> V_34 . V_35 ) ;
F_8 (fb, &dev->mode_config.fb_list, head) {
struct V_22 * V_23 = F_9 ( V_12 ) ;
struct V_6 * V_7 = V_23 -> V_9 ;
F_10 ( V_7 , 1 ) ;
F_11 ( V_36 , V_7 ) ;
}
F_12 ( & V_26 -> V_34 . V_35 ) ;
F_13 () ;
}
void F_14 ( struct V_25 * V_26 )
{
struct V_11 * V_12 ;
F_6 () ;
F_7 ( & V_26 -> V_34 . V_35 ) ;
F_8 (fb, &dev->mode_config.fb_list, head) {
struct V_22 * V_23 = F_9 ( V_12 ) ;
struct V_6 * V_7 = V_23 -> V_9 ;
F_10 ( V_7 , 0 ) ;
F_11 ( V_37 , V_7 ) ;
}
F_12 ( & V_26 -> V_34 . V_35 ) ;
F_13 () ;
F_15 ( V_26 ) ;
}
static int F_16 ( struct V_38 * V_39 , struct V_40 * V_41 )
{
struct V_22 * V_23 = V_39 -> V_42 ;
struct V_25 * V_26 = V_23 -> V_27 . V_26 ;
struct V_43 * V_44 = V_26 -> V_45 ;
int V_46 ;
int V_47 ;
unsigned long V_48 ;
int V_49 ;
unsigned long V_50 ;
unsigned long V_51 = ( unsigned long ) V_44 -> V_52 ;
V_46 = ( V_39 -> V_53 - V_39 -> V_54 ) >> V_55 ;
V_48 = ( unsigned long ) V_41 -> V_56 ;
V_39 -> V_57 = F_17 ( V_39 -> V_57 ) ;
for ( V_47 = 0 ; V_47 < V_46 ; V_47 ++ ) {
V_50 = ( V_51 >> V_55 ) ;
V_49 = F_18 ( V_39 , V_48 , V_50 ) ;
if ( F_19 ( ( V_49 == - V_58 ) || ( V_49 != 0 && V_47 > 0 ) ) )
break;
else if ( F_19 ( V_49 != 0 ) ) {
V_49 = ( V_49 == - V_15 ) ? V_59 : V_60 ;
return V_49 ;
}
V_48 += V_61 ;
V_51 += V_61 ;
}
return V_62 ;
}
static void F_20 ( struct V_38 * V_39 )
{
}
static void F_21 ( struct V_38 * V_39 )
{
}
static int F_22 ( struct V_6 * V_7 , struct V_38 * V_39 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_22 * V_23 = & V_9 -> V_24 ;
if ( V_39 -> V_63 != 0 )
return - V_64 ;
if ( V_39 -> V_63 > ( ~ 0UL >> V_55 ) )
return - V_64 ;
if ( ! V_23 -> V_65 )
V_23 -> V_65 = V_39 -> V_66 -> V_67 ;
V_39 -> V_68 = & V_69 ;
V_39 -> V_42 = ( void * ) V_23 ;
V_39 -> V_70 |= V_71 | V_72 |
V_73 | V_74 ;
return 0 ;
}
static int F_23 ( struct V_6 * V_7 , unsigned int V_75 ,
unsigned long V_76 )
{
return - V_77 ;
}
static int F_24 ( struct V_25 * V_26 ,
struct V_22 * V_12 ,
struct V_78 * V_79 ,
struct V_80 * V_81 )
{
T_2 V_82 , V_83 ;
int V_49 ;
F_25 ( V_79 -> V_84 , & V_83 , & V_82 ) ;
if ( V_79 -> V_85 [ 0 ] & 63 )
return - V_64 ;
switch ( V_82 ) {
case 8 :
case 16 :
case 24 :
case 32 :
break;
default:
return - V_64 ;
}
V_49 = F_26 ( V_26 , & V_12 -> V_27 , & V_86 ) ;
if ( V_49 ) {
F_27 ( V_26 -> V_26 , L_1 , V_49 ) ;
return V_49 ;
}
F_28 ( & V_12 -> V_27 , V_79 ) ;
V_12 -> V_28 = V_81 ;
return 0 ;
}
static struct V_11 * F_29
( struct V_25 * V_26 ,
struct V_78 * V_79 ,
struct V_80 * V_81 )
{
struct V_22 * V_12 ;
int V_49 ;
V_12 = F_30 ( sizeof( * V_12 ) , V_87 ) ;
if ( ! V_12 )
return F_31 ( - V_15 ) ;
V_49 = F_24 ( V_26 , V_12 , V_79 , V_81 ) ;
if ( V_49 ) {
F_32 ( V_12 ) ;
return F_31 ( V_49 ) ;
}
return & V_12 -> V_27 ;
}
static struct V_80 * F_33 ( struct V_25 * V_26 , int V_88 )
{
struct V_80 * V_89 ;
V_89 = F_34 ( V_26 , V_88 , L_2 , 1 ) ;
if ( V_89 ) {
if ( F_35 ( V_26 ,
& V_89 -> V_90 , V_88 ) == 0 )
return V_89 ;
F_36 ( V_26 , V_89 ) ;
}
return NULL ;
}
static int F_37 ( struct V_8 * V_9 ,
struct V_91 * V_92 )
{
struct V_25 * V_26 = V_9 -> V_13 . V_26 ;
struct V_43 * V_44 = V_26 -> V_45 ;
struct V_6 * V_7 ;
struct V_11 * V_12 ;
struct V_22 * V_23 = & V_9 -> V_24 ;
struct V_78 V_79 ;
struct V_93 * V_93 = & V_26 -> V_94 -> V_26 ;
int V_95 ;
int V_49 ;
struct V_80 * V_89 ;
T_2 V_82 , V_83 ;
int V_96 = 0 ;
int V_97 = 0 ;
V_79 . V_98 = V_92 -> V_99 ;
V_79 . V_100 = V_92 -> V_101 ;
V_82 = V_92 -> V_102 ;
if ( V_82 == 24 )
V_82 = 32 ;
do {
V_79 . V_85 [ 0 ] = F_38 ( V_79 . V_98 * ( ( V_82 + 7 ) / 8 ) , 4096 >> V_97 ) ;
V_83 = V_92 -> V_103 ;
V_95 = V_79 . V_85 [ 0 ] * V_79 . V_100 ;
V_95 = F_38 ( V_95 , V_61 ) ;
V_89 = F_33 ( V_26 , V_95 ) ;
if ( V_97 )
V_97 *= 2 ;
else
V_97 = 1 ;
V_96 ++ ;
} while ( V_89 == NULL && V_97 <= 16 );
V_97 /= 2 ;
if ( V_89 == NULL ) {
V_96 = 0 ;
V_97 = 64 ;
V_79 . V_85 [ 0 ] = F_38 ( V_79 . V_98 * ( ( V_82 + 7 ) / 8 ) , 64 ) ;
V_95 = V_79 . V_85 [ 0 ] * V_79 . V_100 ;
V_95 = F_38 ( V_95 , V_61 ) ;
V_89 = F_33 ( V_26 , V_95 ) ;
if ( V_89 == NULL )
return - V_15 ;
}
F_7 ( & V_26 -> V_104 ) ;
V_7 = F_39 ( 0 , V_93 ) ;
if ( ! V_7 ) {
V_49 = - V_15 ;
goto V_105;
}
V_7 -> V_10 = V_9 ;
V_79 . V_84 = F_40 ( V_82 , V_83 ) ;
V_49 = F_24 ( V_26 , V_23 , & V_79 , V_89 ) ;
if ( V_49 )
goto V_106;
V_12 = & V_23 -> V_27 ;
V_23 -> V_9 = V_7 ;
V_9 -> V_13 . V_12 = V_12 ;
V_9 -> V_13 . V_9 = V_7 ;
strcpy ( V_7 -> V_31 . V_107 , L_3 ) ;
V_7 -> V_108 = V_109 ;
if ( V_44 -> V_110 -> V_111 && V_97 > 8 )
V_7 -> V_112 = & V_113 ;
else if ( V_96 ) {
V_7 -> V_112 = & V_114 ;
V_7 -> V_108 |= V_115 ;
} else
V_7 -> V_112 = & V_116 ;
V_49 = F_41 ( & V_7 -> V_117 , 256 , 0 ) ;
if ( V_49 ) {
V_49 = - V_15 ;
goto V_106;
}
V_7 -> V_31 . V_118 = V_26 -> V_34 . V_119 ;
V_7 -> V_31 . V_120 = V_95 ;
V_7 -> V_31 . V_121 = V_96 ;
V_7 -> V_31 . V_122 = 0 ;
V_7 -> V_123 = ( char * ) V_44 -> V_124 +
V_89 -> V_18 ;
V_7 -> V_125 = V_95 ;
if ( V_44 -> V_28 . V_126 ) {
V_7 -> V_127 = F_42 ( 1 ) ;
if ( ! V_7 -> V_127 ) {
V_49 = - V_15 ;
goto V_106;
}
V_7 -> V_127 -> V_128 [ 0 ] . V_27 = V_26 -> V_34 . V_119 ;
V_7 -> V_127 -> V_128 [ 0 ] . V_95 = V_44 -> V_28 . V_126 ;
}
F_43 ( V_7 , V_12 -> V_85 [ 0 ] , V_12 -> V_83 ) ;
F_44 ( V_7 , & V_9 -> V_13 ,
V_92 -> V_129 , V_92 -> V_130 ) ;
V_7 -> V_31 . V_131 = F_45 ( V_26 -> V_94 , 0 ) ;
V_7 -> V_31 . V_132 = F_46 ( V_26 -> V_94 , 0 ) ;
V_7 -> V_133 . V_95 = 64 * 1024 ;
V_7 -> V_133 . V_134 = 8 ;
V_7 -> V_133 . V_135 = 32 ;
V_7 -> V_133 . V_108 = V_136 ;
V_7 -> V_133 . V_137 = 1 ;
F_47 ( V_26 -> V_26 , L_4 ,
V_23 -> V_27 . V_98 , V_23 -> V_27 . V_100 ) ;
F_12 ( & V_26 -> V_104 ) ;
return 0 ;
V_106:
if ( V_89 -> V_138 )
F_36 ( V_26 , V_89 ) ;
else
F_48 ( & V_89 -> V_90 ) ;
V_105:
F_12 ( & V_26 -> V_104 ) ;
F_36 ( V_26 , V_89 ) ;
return V_49 ;
}
static struct V_11 * F_49
( struct V_25 * V_26 , struct V_139 * V_140 ,
struct V_78 * V_75 )
{
struct V_80 * V_141 ;
struct V_142 * V_143 ;
V_143 = F_50 ( V_26 , V_140 , V_75 -> V_144 [ 0 ] ) ;
if ( V_143 == NULL )
return F_31 ( - V_145 ) ;
V_141 = F_51 ( V_143 , struct V_80 , V_90 ) ;
return F_29 ( V_26 , V_75 , V_141 ) ;
}
static void F_52 ( struct V_146 * V_147 , T_3 V_2 , T_3 V_3 ,
T_3 V_4 , int V_1 )
{
}
static void F_53 ( struct V_146 * V_147 , T_3 * V_2 ,
T_3 * V_3 , T_3 * V_4 , int V_1 )
{
}
static int F_54 ( struct V_148 * V_149 ,
struct V_91 * V_92 )
{
struct V_8 * V_8 = (struct V_8 * ) V_149 ;
int V_150 = 0 ;
int V_49 ;
if ( ! V_149 -> V_12 ) {
V_49 = F_37 ( V_8 , V_92 ) ;
if ( V_49 )
return V_49 ;
V_150 = 1 ;
}
return V_150 ;
}
int F_55 ( struct V_25 * V_26 , struct V_8 * V_9 )
{
struct V_6 * V_7 ;
struct V_22 * V_23 = & V_9 -> V_24 ;
if ( V_9 -> V_13 . V_9 ) {
V_7 = V_9 -> V_13 . V_9 ;
F_56 ( V_7 ) ;
if ( V_7 -> V_117 . V_151 )
F_57 ( & V_7 -> V_117 ) ;
F_58 ( V_7 ) ;
}
F_59 ( & V_9 -> V_13 ) ;
F_60 ( & V_23 -> V_27 ) ;
if ( V_23 -> V_28 )
F_48 ( & V_23 -> V_28 -> V_90 ) ;
return 0 ;
}
int F_61 ( struct V_25 * V_26 )
{
struct V_8 * V_9 ;
struct V_43 * V_44 = V_26 -> V_45 ;
V_9 = F_30 ( sizeof( struct V_8 ) , V_87 ) ;
if ( ! V_9 ) {
F_27 ( V_26 -> V_26 , L_5 ) ;
return - V_15 ;
}
V_44 -> V_9 = V_9 ;
V_9 -> V_13 . V_152 = & V_153 ;
F_62 ( V_26 , & V_9 -> V_13 , V_44 -> V_110 -> V_154 ,
V_155 ) ;
F_63 ( & V_9 -> V_13 ) ;
F_64 ( & V_9 -> V_13 , 32 ) ;
return 0 ;
}
void F_65 ( struct V_25 * V_26 )
{
struct V_43 * V_44 = V_26 -> V_45 ;
if ( ! V_44 -> V_9 )
return;
F_55 ( V_26 , V_44 -> V_9 ) ;
F_32 ( V_44 -> V_9 ) ;
V_44 -> V_9 = NULL ;
}
static void F_66 ( struct V_25 * V_26 )
{
struct V_43 * V_44 = V_26 -> V_45 ;
struct V_8 * V_9 = (struct V_8 * ) V_44 -> V_9 ;
F_67 ( & V_9 -> V_13 ) ;
}
static int F_68 ( struct V_11 * V_12 ,
struct V_139 * V_156 ,
unsigned int * V_157 )
{
struct V_22 * V_23 = F_9 ( V_12 ) ;
struct V_80 * V_141 = V_23 -> V_28 ;
return F_69 ( V_156 , & V_141 -> V_90 , V_157 ) ;
}
static void F_70 ( struct V_11 * V_12 )
{
struct V_22 * V_23 = F_9 ( V_12 ) ;
struct V_80 * V_141 = V_23 -> V_28 ;
struct V_25 * V_26 = V_12 -> V_26 ;
struct V_43 * V_44 = V_26 -> V_45 ;
struct V_8 * V_9 = V_44 -> V_9 ;
struct V_146 * V_147 ;
int V_158 = 0 ;
F_71 ( V_141 -> V_138 ) ;
F_8 (crtc, &dev->mode_config.crtc_list, head)
if ( V_147 -> V_12 == V_12 )
V_158 = 1 ;
if ( V_158 )
F_72 ( & V_9 -> V_13 ) ;
F_60 ( V_12 ) ;
F_73 ( & V_141 -> V_90 ) ;
F_32 ( V_12 ) ;
}
static int F_74 ( struct V_25 * V_26 )
{
struct V_43 * V_44 = V_26 -> V_45 ;
struct V_159 * V_160 ;
if ( V_44 -> V_161 )
return 0 ;
V_160 = F_75 ( V_26 , V_162 ,
L_6 , 2 ) ;
V_160 -> V_163 [ 0 ] = 0 ;
V_160 -> V_163 [ 1 ] = 100 ;
V_44 -> V_161 = V_160 ;
return 0 ;
}
static void F_76 ( struct V_25 * V_26 )
{
struct V_43 * V_44 = V_26 -> V_45 ;
struct V_164 * V_165 ;
F_77 ( V_26 ) ;
F_74 ( V_26 ) ;
V_44 -> V_110 -> V_166 ( V_26 ) ;
F_8 (connector, &dev->mode_config.connector_list,
head) {
struct V_167 * V_167 =
F_78 ( V_165 ) ;
struct V_168 * V_169 = & V_167 -> V_27 ;
int V_170 = 0 , V_171 = 0 ;
switch ( V_167 -> type ) {
case V_172 :
V_170 = ( 1 << 0 ) ;
V_171 = ( 1 << V_172 ) ;
break;
case V_173 :
V_170 = ( ( 1 << 0 ) | ( 1 << 1 ) ) ;
V_171 = ( 1 << V_173 ) ;
break;
case V_174 :
if ( F_79 ( V_26 ) )
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
if ( F_80 ( V_26 ) )
V_170 = ( 1 << 1 ) ;
else
V_170 = ( 1 << 0 ) ;
V_171 = ( 1 << V_177 ) ;
break;
}
V_169 -> V_178 = V_170 ;
V_169 -> V_179 =
F_81 ( V_26 , V_171 ) ;
}
}
void F_82 ( struct V_25 * V_26 )
{
struct V_43 * V_44 = V_26 -> V_45 ;
struct V_180 * V_181 = & V_44 -> V_181 ;
int V_47 ;
F_83 ( V_26 ) ;
V_26 -> V_34 . V_182 = 0 ;
V_26 -> V_34 . V_183 = 0 ;
V_26 -> V_34 . V_152 = ( void * ) & V_184 ;
F_84 ( V_26 -> V_94 , V_185 , ( T_2 * )
& ( V_26 -> V_34 . V_119 ) ) ;
for ( V_47 = 0 ; V_47 < V_44 -> V_186 ; V_47 ++ )
F_85 ( V_26 , V_47 , V_181 ) ;
V_26 -> V_34 . V_187 = 2048 ;
V_26 -> V_34 . V_188 = 2048 ;
F_76 ( V_26 ) ;
}
void F_86 ( struct V_25 * V_26 )
{
F_7 ( & V_26 -> V_104 ) ;
F_87 ( V_26 ) ;
F_65 ( V_26 ) ;
F_88 ( V_26 ) ;
F_12 ( & V_26 -> V_104 ) ;
}
