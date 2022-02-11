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
static int F_5 ( struct V_34 * V_35 , struct V_36 * V_37 )
{
struct V_22 * V_23 = V_35 -> V_38 ;
struct V_25 * V_26 = V_23 -> V_27 . V_26 ;
struct V_39 * V_40 = V_26 -> V_41 ;
int V_42 ;
int V_43 ;
unsigned long V_44 ;
int V_45 ;
unsigned long V_46 ;
unsigned long V_47 = ( unsigned long ) V_40 -> V_48 ;
V_42 = ( V_35 -> V_49 - V_35 -> V_50 ) >> V_51 ;
V_44 = ( unsigned long ) V_37 -> V_52 - ( V_37 -> V_53 << V_51 ) ;
V_35 -> V_54 = F_6 ( V_35 -> V_54 ) ;
for ( V_43 = 0 ; V_43 < V_42 ; V_43 ++ ) {
V_46 = ( V_47 >> V_51 ) ;
V_45 = F_7 ( V_35 , V_44 , V_46 ) ;
if ( F_8 ( ( V_45 == - V_55 ) || ( V_45 != 0 && V_43 > 0 ) ) )
break;
else if ( F_8 ( V_45 != 0 ) ) {
V_45 = ( V_45 == - V_15 ) ? V_56 : V_57 ;
return V_45 ;
}
V_44 += V_58 ;
V_47 += V_58 ;
}
return V_59 ;
}
static void F_9 ( struct V_34 * V_35 )
{
}
static void F_10 ( struct V_34 * V_35 )
{
}
static int F_11 ( struct V_6 * V_7 , struct V_34 * V_35 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_22 * V_23 = & V_9 -> V_24 ;
if ( V_35 -> V_60 != 0 )
return - V_61 ;
if ( V_35 -> V_60 > ( ~ 0UL >> V_51 ) )
return - V_61 ;
if ( ! V_23 -> V_62 )
V_23 -> V_62 = V_35 -> V_63 -> V_64 ;
V_35 -> V_65 = & V_66 ;
V_35 -> V_38 = ( void * ) V_23 ;
V_35 -> V_67 |= V_68 | V_69 | V_70 | V_71 ;
return 0 ;
}
static int F_12 ( struct V_6 * V_7 , unsigned int V_72 ,
unsigned long V_73 )
{
return - V_74 ;
}
static int F_13 ( struct V_25 * V_26 ,
struct V_22 * V_12 ,
struct V_75 * V_76 ,
struct V_77 * V_78 )
{
T_2 V_79 , V_80 ;
int V_45 ;
F_14 ( V_76 -> V_81 , & V_80 , & V_79 ) ;
if ( V_76 -> V_82 [ 0 ] & 63 )
return - V_61 ;
switch ( V_79 ) {
case 8 :
case 16 :
case 24 :
case 32 :
break;
default:
return - V_61 ;
}
V_45 = F_15 ( V_26 , & V_12 -> V_27 , & V_83 ) ;
if ( V_45 ) {
F_16 ( V_26 -> V_26 , L_1 , V_45 ) ;
return V_45 ;
}
F_17 ( & V_12 -> V_27 , V_76 ) ;
V_12 -> V_28 = V_78 ;
return 0 ;
}
static struct V_11 * F_18
( struct V_25 * V_26 ,
struct V_75 * V_76 ,
struct V_77 * V_78 )
{
struct V_22 * V_12 ;
int V_45 ;
V_12 = F_19 ( sizeof( * V_12 ) , V_84 ) ;
if ( ! V_12 )
return F_20 ( - V_15 ) ;
V_45 = F_13 ( V_26 , V_12 , V_76 , V_78 ) ;
if ( V_45 ) {
F_21 ( V_12 ) ;
return F_20 ( V_45 ) ;
}
return & V_12 -> V_27 ;
}
static struct V_77 * F_22 ( struct V_25 * V_26 , int V_85 )
{
struct V_77 * V_86 ;
V_86 = F_23 ( V_26 , V_85 , L_2 , 1 ) ;
if ( V_86 ) {
if ( F_24 ( V_26 ,
& V_86 -> V_87 , V_85 ) == 0 )
return V_86 ;
F_25 ( V_26 , V_86 ) ;
}
return NULL ;
}
static int F_26 ( struct V_8 * V_9 ,
struct V_88 * V_89 )
{
struct V_25 * V_26 = V_9 -> V_13 . V_26 ;
struct V_39 * V_40 = V_26 -> V_41 ;
struct V_6 * V_7 ;
struct V_11 * V_12 ;
struct V_22 * V_23 = & V_9 -> V_24 ;
struct V_75 V_76 ;
struct V_90 * V_90 = & V_26 -> V_91 -> V_26 ;
int V_92 ;
int V_45 ;
struct V_77 * V_86 ;
T_2 V_79 , V_80 ;
int V_93 = 0 ;
int V_94 = 0 ;
V_76 . V_95 = V_89 -> V_96 ;
V_76 . V_97 = V_89 -> V_98 ;
V_79 = V_89 -> V_99 ;
V_80 = V_89 -> V_100 ;
if ( V_79 == 24 )
V_79 = 32 ;
do {
V_76 . V_82 [ 0 ] = F_27 ( V_76 . V_95 * ( ( V_79 + 7 ) / 8 ) , 4096 >> V_94 ) ;
V_92 = V_76 . V_82 [ 0 ] * V_76 . V_97 ;
V_92 = F_27 ( V_92 , V_58 ) ;
V_86 = F_22 ( V_26 , V_92 ) ;
if ( V_94 )
V_94 *= 2 ;
else
V_94 = 1 ;
V_93 ++ ;
} while ( V_86 == NULL && V_94 <= 16 );
V_94 /= 2 ;
if ( V_86 == NULL ) {
V_93 = 0 ;
V_94 = 64 ;
V_76 . V_82 [ 0 ] = F_27 ( V_76 . V_95 * ( ( V_79 + 7 ) / 8 ) , 64 ) ;
V_92 = V_76 . V_82 [ 0 ] * V_76 . V_97 ;
V_92 = F_27 ( V_92 , V_58 ) ;
V_86 = F_22 ( V_26 , V_92 ) ;
if ( V_86 == NULL )
return - V_15 ;
}
memset ( V_40 -> V_101 + V_86 -> V_18 , 0 , V_92 ) ;
F_28 ( & V_26 -> V_102 ) ;
V_7 = F_29 ( 0 , V_90 ) ;
if ( ! V_7 ) {
V_45 = - V_15 ;
goto V_103;
}
V_7 -> V_10 = V_9 ;
V_76 . V_81 = F_30 ( V_79 , V_80 ) ;
V_45 = F_13 ( V_26 , V_23 , & V_76 , V_86 ) ;
if ( V_45 )
goto V_104;
V_12 = & V_23 -> V_27 ;
V_23 -> V_9 = V_7 ;
V_9 -> V_13 . V_12 = V_12 ;
V_9 -> V_13 . V_9 = V_7 ;
F_31 ( V_7 , V_12 -> V_82 [ 0 ] , V_12 -> V_80 ) ;
strcpy ( V_7 -> V_31 . V_105 , L_3 ) ;
V_7 -> V_106 = V_107 ;
if ( V_40 -> V_108 -> V_109 && V_94 > 8 )
V_7 -> V_110 = & V_111 ;
else if ( V_93 ) {
V_7 -> V_110 = & V_112 ;
V_7 -> V_106 |= V_113 ;
} else
V_7 -> V_110 = & V_114 ;
V_45 = F_32 ( & V_7 -> V_115 , 256 , 0 ) ;
if ( V_45 ) {
V_45 = - V_15 ;
goto V_104;
}
V_7 -> V_31 . V_116 = V_26 -> V_117 . V_118 ;
V_7 -> V_31 . V_119 = V_92 ;
V_7 -> V_31 . V_120 = V_93 ;
V_7 -> V_31 . V_121 = 0 ;
V_7 -> V_122 = V_40 -> V_101 + V_86 -> V_18 ;
V_7 -> V_123 = V_92 ;
if ( V_40 -> V_28 . V_124 ) {
V_7 -> V_125 = F_33 ( 1 ) ;
if ( ! V_7 -> V_125 ) {
V_45 = - V_15 ;
goto V_104;
}
V_7 -> V_125 -> V_126 [ 0 ] . V_27 = V_26 -> V_117 . V_118 ;
V_7 -> V_125 -> V_126 [ 0 ] . V_92 = V_40 -> V_28 . V_124 ;
}
F_34 ( V_7 , & V_9 -> V_13 ,
V_89 -> V_127 , V_89 -> V_128 ) ;
V_7 -> V_31 . V_129 = F_35 ( V_26 -> V_91 , 0 ) ;
V_7 -> V_31 . V_130 = F_36 ( V_26 -> V_91 , 0 ) ;
F_37 ( V_26 -> V_26 , L_4 ,
V_23 -> V_27 . V_95 , V_23 -> V_27 . V_97 ) ;
F_38 ( & V_26 -> V_102 ) ;
return 0 ;
V_104:
if ( V_86 -> V_131 )
F_25 ( V_26 , V_86 ) ;
else
F_39 ( & V_86 -> V_87 ) ;
V_103:
F_38 ( & V_26 -> V_102 ) ;
F_25 ( V_26 , V_86 ) ;
return V_45 ;
}
static struct V_11 * F_40
( struct V_25 * V_26 , struct V_132 * V_133 ,
struct V_75 * V_72 )
{
struct V_77 * V_134 ;
struct V_135 * V_136 ;
V_136 = F_41 ( V_26 , V_133 , V_72 -> V_137 [ 0 ] ) ;
if ( V_136 == NULL )
return F_20 ( - V_138 ) ;
V_134 = F_42 ( V_136 , struct V_77 , V_87 ) ;
return F_18 ( V_26 , V_72 , V_134 ) ;
}
static void F_43 ( struct V_139 * V_140 , T_3 V_2 , T_3 V_3 ,
T_3 V_4 , int V_1 )
{
struct V_141 * V_142 = F_44 ( V_140 ) ;
V_142 -> V_143 [ V_1 ] = V_2 >> 8 ;
V_142 -> V_144 [ V_1 ] = V_3 >> 8 ;
V_142 -> V_145 [ V_1 ] = V_4 >> 8 ;
}
static void F_45 ( struct V_139 * V_140 , T_3 * V_2 ,
T_3 * V_3 , T_3 * V_4 , int V_1 )
{
struct V_141 * V_142 = F_44 ( V_140 ) ;
* V_2 = V_142 -> V_143 [ V_1 ] << 8 ;
* V_3 = V_142 -> V_144 [ V_1 ] << 8 ;
* V_4 = V_142 -> V_145 [ V_1 ] << 8 ;
}
static int F_46 ( struct V_146 * V_147 ,
struct V_88 * V_89 )
{
struct V_8 * V_8 = (struct V_8 * ) V_147 ;
struct V_25 * V_26 = V_8 -> V_13 . V_26 ;
struct V_39 * V_40 = V_26 -> V_41 ;
int V_148 = 0 ;
int V_149 ;
int V_45 ;
V_149 = V_89 -> V_99 / 8 ;
if ( V_149 == 3 )
V_149 = 4 ;
if ( F_27 ( V_89 -> V_127 * V_149 , 64 ) * V_89 -> V_128 >
V_40 -> V_150 ) {
V_89 -> V_99 = 16 ;
V_89 -> V_100 = 16 ;
}
if ( ! V_147 -> V_12 ) {
V_45 = F_26 ( V_8 , V_89 ) ;
if ( V_45 )
return V_45 ;
V_148 = 1 ;
}
return V_148 ;
}
static int F_47 ( struct V_25 * V_26 , struct V_8 * V_9 )
{
struct V_6 * V_7 ;
struct V_22 * V_23 = & V_9 -> V_24 ;
if ( V_9 -> V_13 . V_9 ) {
V_7 = V_9 -> V_13 . V_9 ;
F_48 ( V_7 ) ;
if ( V_7 -> V_115 . V_151 )
F_49 ( & V_7 -> V_115 ) ;
F_50 ( V_7 ) ;
}
F_51 ( & V_9 -> V_13 ) ;
F_52 ( & V_23 -> V_27 ) ;
if ( V_23 -> V_28 )
F_39 ( & V_23 -> V_28 -> V_87 ) ;
return 0 ;
}
int F_53 ( struct V_25 * V_26 )
{
struct V_8 * V_9 ;
struct V_39 * V_40 = V_26 -> V_41 ;
V_9 = F_19 ( sizeof( struct V_8 ) , V_84 ) ;
if ( ! V_9 ) {
F_16 ( V_26 -> V_26 , L_5 ) ;
return - V_15 ;
}
V_40 -> V_9 = V_9 ;
V_9 -> V_13 . V_152 = & V_153 ;
F_54 ( V_26 , & V_9 -> V_13 , V_40 -> V_108 -> V_154 ,
V_155 ) ;
F_55 ( & V_9 -> V_13 ) ;
F_56 ( & V_9 -> V_13 , 32 ) ;
return 0 ;
}
static void F_57 ( struct V_25 * V_26 )
{
struct V_39 * V_40 = V_26 -> V_41 ;
if ( ! V_40 -> V_9 )
return;
F_47 ( V_26 , V_40 -> V_9 ) ;
F_21 ( V_40 -> V_9 ) ;
V_40 -> V_9 = NULL ;
}
static void F_58 ( struct V_25 * V_26 )
{
struct V_39 * V_40 = V_26 -> V_41 ;
struct V_8 * V_9 = (struct V_8 * ) V_40 -> V_9 ;
F_59 ( & V_9 -> V_13 ) ;
}
static int F_60 ( struct V_11 * V_12 ,
struct V_132 * V_156 ,
unsigned int * V_157 )
{
struct V_22 * V_23 = F_61 ( V_12 ) ;
struct V_77 * V_134 = V_23 -> V_28 ;
return F_62 ( V_156 , & V_134 -> V_87 , V_157 ) ;
}
static void F_63 ( struct V_11 * V_12 )
{
struct V_22 * V_23 = F_61 ( V_12 ) ;
struct V_77 * V_134 = V_23 -> V_28 ;
struct V_25 * V_26 = V_12 -> V_26 ;
struct V_39 * V_40 = V_26 -> V_41 ;
struct V_8 * V_9 = V_40 -> V_9 ;
struct V_139 * V_140 ;
int V_158 = 0 ;
F_64 ( V_134 -> V_131 ) ;
F_65 (crtc, &dev->mode_config.crtc_list, head)
if ( V_140 -> V_12 == V_12 )
V_158 = 1 ;
if ( V_158 )
F_66 ( & V_9 -> V_13 ) ;
F_52 ( V_12 ) ;
F_67 ( & V_134 -> V_87 ) ;
F_21 ( V_12 ) ;
}
static int F_68 ( struct V_25 * V_26 )
{
struct V_39 * V_40 = V_26 -> V_41 ;
struct V_159 * V_160 ;
if ( V_40 -> V_161 )
return 0 ;
V_160 = F_69 ( V_26 , 0 , L_6 , 0 , 100 ) ;
V_40 -> V_161 = V_160 ;
return 0 ;
}
static void F_70 ( struct V_25 * V_26 )
{
struct V_39 * V_40 = V_26 -> V_41 ;
struct V_162 * V_163 ;
F_71 ( V_26 ) ;
F_68 ( V_26 ) ;
V_40 -> V_108 -> V_164 ( V_26 ) ;
F_65 (connector, &dev->mode_config.connector_list,
head) {
struct V_165 * V_165 =
F_72 ( V_163 ) ;
struct V_166 * V_167 = & V_165 -> V_27 ;
int V_168 = 0 , V_169 = 0 ;
switch ( V_165 -> type ) {
case V_170 :
V_168 = ( 1 << 0 ) ;
V_169 = ( 1 << V_170 ) ;
break;
case V_171 :
V_168 = ( ( 1 << 0 ) | ( 1 << 1 ) ) ;
V_169 = ( 1 << V_171 ) ;
break;
case V_172 :
V_168 = V_40 -> V_108 -> V_173 ;
V_169 = ( 1 << V_172 ) ;
break;
case V_174 :
V_168 = ( 1 << 0 ) ;
V_169 = ( 1 << V_174 ) ;
break;
case V_175 :
V_168 = ( 1 << 2 ) ;
V_169 = ( 1 << V_175 ) ;
break;
case V_176 :
V_168 = V_40 -> V_108 -> V_177 ;
V_169 = ( 1 << V_176 ) ;
break;
case V_178 :
V_168 = ( 1 << 0 ) | ( 1 << 1 ) ;
V_169 = ( 1 << V_178 ) ;
break;
case V_179 :
V_168 = ( 1 << 1 ) ;
V_169 = ( 1 << V_179 ) ;
}
V_167 -> V_180 = V_168 ;
V_167 -> V_181 =
F_73 ( V_26 , V_169 ) ;
}
}
void F_74 ( struct V_25 * V_26 )
{
struct V_39 * V_40 = V_26 -> V_41 ;
struct V_182 * V_183 = & V_40 -> V_183 ;
int V_43 ;
F_75 ( V_26 ) ;
V_26 -> V_117 . V_184 = 0 ;
V_26 -> V_117 . V_185 = 0 ;
V_26 -> V_117 . V_152 = & V_186 ;
F_76 ( V_26 -> V_91 , V_187 , ( T_2 * )
& ( V_26 -> V_117 . V_118 ) ) ;
for ( V_43 = 0 ; V_43 < V_40 -> V_188 ; V_43 ++ )
F_77 ( V_26 , V_43 , V_183 ) ;
V_26 -> V_117 . V_189 = 2048 ;
V_26 -> V_117 . V_190 = 2048 ;
F_70 ( V_26 ) ;
if ( V_40 -> V_108 -> V_191 )
V_40 -> V_108 -> V_191 ( V_26 ) ;
V_40 -> V_192 = true ;
}
void F_78 ( struct V_25 * V_26 )
{
struct V_39 * V_40 = V_26 -> V_41 ;
if ( V_40 -> V_192 ) {
F_28 ( & V_26 -> V_102 ) ;
F_79 ( V_26 ) ;
F_57 ( V_26 ) ;
F_80 ( V_26 ) ;
F_38 ( & V_26 -> V_102 ) ;
}
}
