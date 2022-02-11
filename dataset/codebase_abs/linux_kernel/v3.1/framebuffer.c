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
void F_3 ( struct V_21 * V_22 )
{
struct V_11 * V_12 = 0 ;
struct V_23 * V_24 = F_4 ( V_12 ) ;
F_5 () ;
F_6 ( & V_22 -> V_25 . V_26 ) ;
F_7 (fb, &dev->mode_config.fb_list, head) {
struct V_6 * V_7 = V_24 -> V_9 ;
F_8 ( V_7 , 1 ) ;
F_9 ( V_27 , V_7 ) ;
}
F_10 ( & V_22 -> V_25 . V_26 ) ;
F_11 () ;
}
void F_12 ( struct V_21 * V_22 )
{
struct V_11 * V_12 = 0 ;
struct V_23 * V_24 = F_4 ( V_12 ) ;
F_5 () ;
F_6 ( & V_22 -> V_25 . V_26 ) ;
F_7 (fb, &dev->mode_config.fb_list, head) {
struct V_6 * V_7 = V_24 -> V_9 ;
F_8 ( V_7 , 0 ) ;
F_9 ( V_28 , V_7 ) ;
}
F_10 ( & V_22 -> V_25 . V_26 ) ;
F_11 () ;
F_13 ( V_22 ) ;
}
static int F_14 ( struct V_29 * V_30 , struct V_31 * V_32 )
{
struct V_23 * V_24 = V_30 -> V_33 ;
struct V_21 * V_22 = V_24 -> V_34 . V_22 ;
struct V_35 * V_36 = V_22 -> V_37 ;
int V_38 ;
int V_39 ;
unsigned long V_40 ;
int V_41 ;
unsigned long V_42 ;
unsigned long V_43 = ( unsigned long ) V_36 -> V_44 ;
V_38 = ( V_30 -> V_45 - V_30 -> V_46 ) >> V_47 ;
V_40 = ( unsigned long ) V_32 -> V_48 ;
V_30 -> V_49 = F_15 ( V_30 -> V_49 ) ;
for ( V_39 = 0 ; V_39 < V_38 ; V_39 ++ ) {
V_42 = ( V_43 >> V_47 ) ;
V_41 = F_16 ( V_30 , V_40 , V_42 ) ;
if ( F_17 ( ( V_41 == - V_50 ) || ( V_41 != 0 && V_39 > 0 ) ) )
break;
else if ( F_17 ( V_41 != 0 ) ) {
V_41 = ( V_41 == - V_15 ) ? V_51 : V_52 ;
return V_41 ;
}
V_40 += V_53 ;
V_43 += V_53 ;
}
return V_54 ;
}
static void F_18 ( struct V_29 * V_30 )
{
}
static void F_19 ( struct V_29 * V_30 )
{
}
static int F_20 ( struct V_6 * V_7 , struct V_29 * V_30 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_23 * V_24 = & V_9 -> V_55 ;
if ( V_30 -> V_56 != 0 )
return - V_57 ;
if ( V_30 -> V_56 > ( ~ 0UL >> V_47 ) )
return - V_57 ;
if ( ! V_24 -> V_58 )
V_24 -> V_58 = V_30 -> V_59 -> V_60 ;
V_30 -> V_61 = & V_62 ;
V_30 -> V_33 = ( void * ) V_24 ;
V_30 -> V_63 |= V_64 | V_65 |
V_66 | V_67 ;
return 0 ;
}
static int F_21 ( struct V_6 * V_7 , unsigned int V_68 ,
unsigned long V_69 )
{
return - V_70 ;
}
static int F_22 ( struct V_21 * V_22 ,
struct V_23 * V_12 ,
struct V_71 * V_72 ,
struct V_73 * V_74 )
{
int V_41 ;
if ( V_72 -> V_75 & 63 )
return - V_57 ;
switch ( V_72 -> V_76 ) {
case 8 :
case 16 :
case 24 :
case 32 :
break;
default:
return - V_57 ;
}
V_41 = F_23 ( V_22 , & V_12 -> V_34 , & V_77 ) ;
if ( V_41 ) {
F_24 ( V_22 -> V_22 , L_1 , V_41 ) ;
return V_41 ;
}
F_25 ( & V_12 -> V_34 , V_72 ) ;
V_12 -> V_78 = V_74 ;
return 0 ;
}
static struct V_11 * F_26
( struct V_21 * V_22 ,
struct V_71 * V_72 ,
struct V_73 * V_74 )
{
struct V_23 * V_12 ;
int V_41 ;
V_12 = F_27 ( sizeof( * V_12 ) , V_79 ) ;
if ( ! V_12 )
return F_28 ( - V_15 ) ;
V_41 = F_22 ( V_22 , V_12 , V_72 , V_74 ) ;
if ( V_41 ) {
F_29 ( V_12 ) ;
return F_28 ( V_41 ) ;
}
return & V_12 -> V_34 ;
}
static struct V_73 * F_30 ( struct V_21 * V_22 , int V_80 )
{
struct V_73 * V_81 ;
V_81 = F_31 ( V_22 , V_80 , L_2 , 1 ) ;
if ( V_81 ) {
if ( F_32 ( V_22 ,
& V_81 -> V_82 , V_80 ) == 0 )
return V_81 ;
F_33 ( V_22 , V_81 ) ;
}
V_81 = F_31 ( V_22 , V_80 , L_3 , 0 ) ;
if ( V_81 == NULL )
return NULL ;
if ( F_34 ( V_22 , & V_81 -> V_82 , V_80 ) != 0 ) {
F_33 ( V_22 , V_81 ) ;
return NULL ;
}
return V_81 ;
}
static int F_35 ( struct V_8 * V_9 ,
struct V_83 * V_84 )
{
struct V_21 * V_22 = V_9 -> V_13 . V_22 ;
struct V_35 * V_36 = V_22 -> V_37 ;
struct V_6 * V_7 ;
struct V_11 * V_12 ;
struct V_23 * V_24 = & V_9 -> V_55 ;
struct V_71 V_72 ;
struct V_85 * V_85 = & V_22 -> V_86 -> V_22 ;
int V_87 ;
int V_41 ;
struct V_73 * V_81 ;
V_72 . V_88 = V_84 -> V_89 ;
V_72 . V_90 = V_84 -> V_91 ;
V_72 . V_76 = V_84 -> V_92 ;
if ( V_72 . V_76 == 24 )
V_72 . V_76 = 32 ;
V_72 . V_75 = F_36 ( V_72 . V_88 * ( ( V_72 . V_76 + 7 ) / 8 ) , 64 ) ;
V_72 . V_93 = V_84 -> V_94 ;
V_87 = V_72 . V_75 * V_72 . V_90 ;
V_87 = F_36 ( V_87 , V_53 ) ;
V_81 = F_30 ( V_22 , V_87 ) ;
if ( V_81 == NULL )
return - V_15 ;
F_6 ( & V_22 -> V_95 ) ;
V_7 = F_37 ( 0 , V_85 ) ;
if ( ! V_7 ) {
V_41 = - V_15 ;
goto V_96;
}
V_7 -> V_10 = V_9 ;
V_41 = F_22 ( V_22 , V_24 , & V_72 , V_81 ) ;
if ( V_41 )
goto V_97;
V_12 = & V_24 -> V_34 ;
V_24 -> V_9 = V_7 ;
V_9 -> V_13 . V_12 = V_12 ;
V_9 -> V_13 . V_9 = V_7 ;
strcpy ( V_7 -> V_98 . V_99 , L_4 ) ;
V_7 -> V_100 = V_101 ;
if ( ! V_36 -> V_102 -> V_103 )
V_7 -> V_104 = & V_105 ;
else
V_7 -> V_104 = & V_106 ;
V_41 = F_38 ( & V_7 -> V_107 , 256 , 0 ) ;
if ( V_41 ) {
V_41 = - V_15 ;
goto V_97;
}
V_7 -> V_98 . V_108 = V_22 -> V_25 . V_109 ;
V_7 -> V_98 . V_110 = V_87 ;
if ( V_81 -> V_111 ) {
V_7 -> V_112 = ( char * ) V_36 -> V_113 +
V_81 -> V_18 ;
} else {
F_39 ( V_81 ) ;
V_7 -> V_112 = F_40 ( V_81 -> V_114 , V_81 -> V_115 ,
- 1 , V_116 ) ;
if ( V_7 -> V_112 == NULL ) {
F_41 ( V_81 ) ;
V_41 = - V_15 ;
goto V_97;
}
V_24 -> V_117 = 1 ;
}
V_7 -> V_118 = V_87 ;
if ( V_36 -> V_78 . V_119 ) {
V_7 -> V_120 = F_42 ( 1 ) ;
if ( ! V_7 -> V_120 ) {
V_41 = - V_15 ;
goto V_97;
}
V_7 -> V_120 -> V_121 [ 0 ] . V_34 = V_22 -> V_25 . V_109 ;
V_7 -> V_120 -> V_121 [ 0 ] . V_87 = V_36 -> V_78 . V_119 ;
}
F_43 ( V_7 , V_12 -> V_75 , V_12 -> V_93 ) ;
F_44 ( V_7 , & V_9 -> V_13 ,
V_84 -> V_122 , V_84 -> V_123 ) ;
V_7 -> V_98 . V_124 = F_45 ( V_22 -> V_86 , 0 ) ;
V_7 -> V_98 . V_125 = F_46 ( V_22 -> V_86 , 0 ) ;
V_7 -> V_126 . V_87 = 64 * 1024 ;
V_7 -> V_126 . V_127 = 8 ;
V_7 -> V_126 . V_128 = 32 ;
V_7 -> V_126 . V_100 = V_129 ;
V_7 -> V_126 . V_130 = 1 ;
F_47 ( V_22 -> V_22 , L_5 ,
V_24 -> V_34 . V_88 , V_24 -> V_34 . V_90 ) ;
F_10 ( & V_22 -> V_95 ) ;
return 0 ;
V_97:
if ( V_81 -> V_111 )
F_33 ( V_22 , V_81 ) ;
else {
if ( V_24 -> V_117 )
F_48 ( V_7 -> V_112 , V_81 -> V_115 ) ;
F_49 ( & V_81 -> V_82 ) ;
}
V_96:
F_10 ( & V_22 -> V_95 ) ;
F_33 ( V_22 , V_81 ) ;
return V_41 ;
}
static struct V_11 * F_50
( struct V_21 * V_22 , struct V_131 * V_132 ,
struct V_71 * V_68 )
{
struct V_73 * V_133 ;
struct V_134 * V_135 ;
V_135 = F_51 ( V_22 , V_132 , V_68 -> V_136 ) ;
if ( V_135 == NULL )
return F_28 ( - V_137 ) ;
V_133 = F_52 ( V_135 , struct V_73 , V_82 ) ;
return F_26 ( V_22 , V_68 , V_133 ) ;
}
static void F_53 ( struct V_138 * V_139 , T_2 V_2 , T_2 V_3 ,
T_2 V_4 , int V_1 )
{
}
static void F_54 ( struct V_138 * V_139 , T_2 * V_2 ,
T_2 * V_3 , T_2 * V_4 , int V_1 )
{
}
static int F_55 ( struct V_140 * V_141 ,
struct V_83 * V_84 )
{
struct V_8 * V_8 = (struct V_8 * ) V_141 ;
int V_142 = 0 ;
int V_41 ;
if ( ! V_141 -> V_12 ) {
V_41 = F_35 ( V_8 , V_84 ) ;
if ( V_41 )
return V_41 ;
V_142 = 1 ;
}
return V_142 ;
}
int F_56 ( struct V_21 * V_22 , struct V_8 * V_9 )
{
struct V_6 * V_7 ;
struct V_23 * V_24 = & V_9 -> V_55 ;
if ( V_9 -> V_13 . V_9 ) {
V_7 = V_9 -> V_13 . V_9 ;
if ( V_24 -> V_117 ) {
F_48 ( V_7 -> V_112 , V_24 -> V_78 -> V_115 ) ;
F_41 ( V_24 -> V_78 ) ;
}
F_57 ( V_7 ) ;
if ( V_7 -> V_107 . V_143 )
F_58 ( & V_7 -> V_107 ) ;
F_59 ( V_7 ) ;
}
F_60 ( & V_9 -> V_13 ) ;
F_61 ( & V_24 -> V_34 ) ;
if ( V_24 -> V_78 )
F_49 ( & V_24 -> V_78 -> V_82 ) ;
return 0 ;
}
int F_62 ( struct V_21 * V_22 )
{
struct V_8 * V_9 ;
struct V_35 * V_36 = V_22 -> V_37 ;
V_9 = F_27 ( sizeof( struct V_8 ) , V_79 ) ;
if ( ! V_9 ) {
F_24 ( V_22 -> V_22 , L_6 ) ;
return - V_15 ;
}
V_36 -> V_9 = V_9 ;
V_9 -> V_13 . V_144 = & V_145 ;
F_63 ( V_22 , & V_9 -> V_13 , V_36 -> V_102 -> V_146 ,
V_147 ) ;
F_64 ( & V_9 -> V_13 ) ;
F_65 ( & V_9 -> V_13 , 32 ) ;
return 0 ;
}
void F_66 ( struct V_21 * V_22 )
{
struct V_35 * V_36 = V_22 -> V_37 ;
if ( ! V_36 -> V_9 )
return;
F_56 ( V_22 , V_36 -> V_9 ) ;
F_29 ( V_36 -> V_9 ) ;
V_36 -> V_9 = NULL ;
}
static void F_67 ( struct V_21 * V_22 )
{
struct V_35 * V_36 = V_22 -> V_37 ;
struct V_8 * V_9 = (struct V_8 * ) V_36 -> V_9 ;
F_68 ( & V_9 -> V_13 ) ;
}
static int F_69 ( struct V_11 * V_12 ,
struct V_131 * V_148 ,
unsigned int * V_136 )
{
struct V_23 * V_24 = F_4 ( V_12 ) ;
struct V_73 * V_133 = V_24 -> V_78 ;
return F_70 ( V_148 , & V_133 -> V_82 , V_136 ) ;
}
static void F_71 ( struct V_11 * V_12 )
{
struct V_23 * V_24 = F_4 ( V_12 ) ;
struct V_73 * V_133 = V_24 -> V_78 ;
struct V_21 * V_22 = V_12 -> V_22 ;
struct V_35 * V_36 = V_22 -> V_37 ;
struct V_8 * V_9 = V_36 -> V_9 ;
struct V_138 * V_139 ;
int V_149 = 0 ;
F_72 ( V_133 -> V_111 ) ;
F_7 (crtc, &dev->mode_config.crtc_list, head)
if ( V_139 -> V_12 == V_12 )
V_149 = 1 ;
if ( V_149 )
F_73 ( & V_9 -> V_13 ) ;
F_61 ( V_12 ) ;
F_74 ( & V_133 -> V_82 ) ;
F_29 ( V_12 ) ;
}
static int F_75 ( struct V_21 * V_22 )
{
struct V_35 * V_36 = V_22 -> V_37 ;
struct V_150 * V_151 ;
if ( V_36 -> V_152 )
return 0 ;
V_151 = F_76 ( V_22 , V_153 ,
L_7 , 2 ) ;
V_151 -> V_154 [ 0 ] = 0 ;
V_151 -> V_154 [ 1 ] = 100 ;
V_36 -> V_152 = V_151 ;
return 0 ;
}
static void F_77 ( struct V_21 * V_22 )
{
struct V_35 * V_36 = V_22 -> V_37 ;
struct V_155 * V_156 ;
F_78 ( V_22 ) ;
F_75 ( V_22 ) ;
V_36 -> V_102 -> V_157 ( V_22 ) ;
F_7 (connector, &dev->mode_config.connector_list,
head) {
struct V_158 * V_158 =
F_79 ( V_156 ) ;
struct V_159 * V_160 = & V_158 -> V_161 ;
int V_162 = 0 , V_163 = 0 ;
switch ( V_158 -> type ) {
case V_164 :
V_162 = ( 1 << 0 ) ;
V_163 = ( 1 << V_164 ) ;
break;
case V_165 :
V_162 = ( ( 1 << 0 ) | ( 1 << 1 ) ) ;
V_163 = ( 1 << V_165 ) ;
break;
case V_166 :
if ( F_80 ( V_22 ) )
V_162 = ( 1 << 0 ) ;
else
V_162 = ( 1 << 1 ) ;
V_163 = ( 1 << V_166 ) ;
break;
case V_167 :
V_162 = ( 1 << 0 ) ;
V_163 = ( 1 << V_167 ) ;
break;
case V_168 :
V_162 = ( 1 << 2 ) ;
V_163 = ( 1 << V_168 ) ;
break;
case V_169 :
if ( F_81 ( V_22 ) )
V_162 = ( 1 << 1 ) ;
else
V_162 = ( 1 << 0 ) ;
V_163 = ( 1 << V_169 ) ;
break;
}
V_160 -> V_170 = V_162 ;
V_160 -> V_171 =
F_82 ( V_22 , V_163 ) ;
}
}
void F_83 ( struct V_21 * V_22 )
{
struct V_35 * V_36 =
(struct V_35 * ) V_22 -> V_37 ;
struct V_172 * V_173 = & V_36 -> V_173 ;
int V_39 ;
F_84 ( V_22 ) ;
V_22 -> V_25 . V_174 = 0 ;
V_22 -> V_25 . V_175 = 0 ;
V_22 -> V_25 . V_144 = ( void * ) & V_176 ;
F_85 ( V_22 -> V_86 , V_177 , ( V_178 * )
& ( V_22 -> V_25 . V_109 ) ) ;
for ( V_39 = 0 ; V_39 < V_36 -> V_179 ; V_39 ++ )
F_86 ( V_22 , V_39 , V_173 ) ;
V_22 -> V_25 . V_180 = 2048 ;
V_22 -> V_25 . V_181 = 2048 ;
F_77 ( V_22 ) ;
}
void F_87 ( struct V_21 * V_22 )
{
F_6 ( & V_22 -> V_95 ) ;
F_88 ( V_22 ) ;
F_66 ( V_22 ) ;
F_89 ( V_22 ) ;
F_10 ( & V_22 -> V_95 ) ;
}
