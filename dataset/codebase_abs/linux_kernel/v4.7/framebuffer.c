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
unsigned long V_47 = ( unsigned long ) V_40 -> V_48 +
V_23 -> V_28 -> V_18 ;
V_42 = ( V_35 -> V_49 - V_35 -> V_50 ) >> V_51 ;
V_44 = ( unsigned long ) V_37 -> V_52 - ( V_37 -> V_53 << V_51 ) ;
V_35 -> V_54 = F_6 ( V_35 -> V_54 ) ;
for ( V_43 = 0 ; V_43 < V_42 ; V_43 ++ ) {
V_46 = ( V_47 >> V_51 ) ;
V_45 = F_7 ( V_35 , V_44 ,
F_8 ( V_46 , V_55 ) ) ;
if ( F_9 ( ( V_45 == - V_56 ) || ( V_45 != 0 && V_43 > 0 ) ) )
break;
else if ( F_9 ( V_45 != 0 ) ) {
V_45 = ( V_45 == - V_15 ) ? V_57 : V_58 ;
return V_45 ;
}
V_44 += V_59 ;
V_47 += V_59 ;
}
return V_60 ;
}
static void F_10 ( struct V_34 * V_35 )
{
}
static void F_11 ( struct V_34 * V_35 )
{
}
static int F_12 ( struct V_6 * V_7 , struct V_34 * V_35 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_22 * V_23 = & V_9 -> V_24 ;
if ( V_35 -> V_61 != 0 )
return - V_62 ;
if ( V_35 -> V_61 > ( ~ 0UL >> V_51 ) )
return - V_62 ;
if ( ! V_23 -> V_63 )
V_23 -> V_63 = V_35 -> V_64 -> V_65 ;
V_35 -> V_66 = & V_67 ;
V_35 -> V_38 = ( void * ) V_23 ;
V_35 -> V_68 |= V_69 | V_70 | V_71 | V_72 ;
return 0 ;
}
static int F_13 ( struct V_6 * V_7 , unsigned int V_73 ,
unsigned long V_74 )
{
return - V_75 ;
}
static int F_14 ( struct V_25 * V_26 ,
struct V_22 * V_12 ,
const struct V_76 * V_77 ,
struct V_78 * V_79 )
{
T_2 V_80 , V_81 ;
int V_45 ;
F_15 ( V_77 -> V_82 , & V_81 , & V_80 ) ;
if ( V_77 -> V_83 [ 0 ] & 63 )
return - V_62 ;
switch ( V_80 ) {
case 8 :
case 16 :
case 24 :
case 32 :
break;
default:
return - V_62 ;
}
F_16 ( & V_12 -> V_27 , V_77 ) ;
V_12 -> V_28 = V_79 ;
V_45 = F_17 ( V_26 , & V_12 -> V_27 , & V_84 ) ;
if ( V_45 ) {
F_18 ( V_26 -> V_26 , L_1 , V_45 ) ;
return V_45 ;
}
return 0 ;
}
static struct V_11 * F_19
( struct V_25 * V_26 ,
const struct V_76 * V_77 ,
struct V_78 * V_79 )
{
struct V_22 * V_12 ;
int V_45 ;
V_12 = F_20 ( sizeof( * V_12 ) , V_85 ) ;
if ( ! V_12 )
return F_21 ( - V_15 ) ;
V_45 = F_14 ( V_26 , V_12 , V_77 , V_79 ) ;
if ( V_45 ) {
F_22 ( V_12 ) ;
return F_21 ( V_45 ) ;
}
return & V_12 -> V_27 ;
}
static struct V_78 * F_23 ( struct V_25 * V_26 , int V_86 )
{
struct V_78 * V_87 ;
V_87 = F_24 ( V_26 , V_86 , L_2 , 1 , V_59 ) ;
if ( V_87 ) {
F_25 ( V_26 , & V_87 -> V_88 , V_86 ) ;
return V_87 ;
}
return NULL ;
}
static int F_26 ( struct V_8 * V_9 ,
struct V_89 * V_90 )
{
struct V_25 * V_26 = V_9 -> V_13 . V_26 ;
struct V_39 * V_40 = V_26 -> V_41 ;
struct V_6 * V_7 ;
struct V_11 * V_12 ;
struct V_22 * V_23 = & V_9 -> V_24 ;
struct V_76 V_77 ;
int V_91 ;
int V_45 ;
struct V_78 * V_87 ;
T_2 V_80 , V_81 ;
int V_92 = 0 ;
int V_93 = 0 ;
V_77 . V_94 = V_90 -> V_95 ;
V_77 . V_96 = V_90 -> V_97 ;
V_80 = V_90 -> V_98 ;
V_81 = V_90 -> V_99 ;
if ( V_80 == 24 )
V_80 = 32 ;
do {
V_77 . V_83 [ 0 ] = F_27 ( V_77 . V_94 * ( ( V_80 + 7 ) / 8 ) , 4096 >> V_93 ) ;
V_91 = V_77 . V_83 [ 0 ] * V_77 . V_96 ;
V_91 = F_27 ( V_91 , V_59 ) ;
V_87 = F_23 ( V_26 , V_91 ) ;
if ( V_93 )
V_93 *= 2 ;
else
V_93 = 1 ;
V_92 ++ ;
} while ( V_87 == NULL && V_93 <= 16 );
V_93 /= 2 ;
if ( V_87 == NULL ) {
V_92 = 0 ;
V_93 = 64 ;
V_77 . V_83 [ 0 ] = F_27 ( V_77 . V_94 * ( ( V_80 + 7 ) / 8 ) , 64 ) ;
V_91 = V_77 . V_83 [ 0 ] * V_77 . V_96 ;
V_91 = F_27 ( V_91 , V_59 ) ;
V_87 = F_23 ( V_26 , V_91 ) ;
if ( V_87 == NULL )
return - V_15 ;
}
memset ( V_40 -> V_100 + V_87 -> V_18 , 0 , V_91 ) ;
V_7 = F_28 ( & V_9 -> V_13 ) ;
if ( F_29 ( V_7 ) ) {
V_45 = F_30 ( V_7 ) ;
goto V_101;
}
V_7 -> V_10 = V_9 ;
V_77 . V_82 = F_31 ( V_80 , V_81 ) ;
V_45 = F_14 ( V_26 , V_23 , & V_77 , V_87 ) ;
if ( V_45 )
goto V_102;
V_12 = & V_23 -> V_27 ;
V_23 -> V_9 = V_7 ;
V_9 -> V_13 . V_12 = V_12 ;
F_32 ( V_7 , V_12 -> V_83 [ 0 ] , V_12 -> V_81 ) ;
strcpy ( V_7 -> V_31 . V_103 , L_3 ) ;
V_7 -> V_104 = V_105 ;
if ( V_40 -> V_106 -> V_107 && V_93 > 8 )
V_7 -> V_108 = & V_109 ;
else if ( V_92 ) {
V_7 -> V_108 = & V_110 ;
V_7 -> V_104 |= V_111 ;
} else
V_7 -> V_108 = & V_112 ;
V_7 -> V_31 . V_113 = V_26 -> V_114 . V_115 ;
V_7 -> V_31 . V_116 = V_91 ;
V_7 -> V_31 . V_117 = V_92 ;
V_7 -> V_31 . V_118 = 0 ;
V_7 -> V_119 = V_40 -> V_100 + V_87 -> V_18 ;
V_7 -> V_120 = V_91 ;
if ( V_40 -> V_28 . V_121 ) {
V_7 -> V_122 -> V_123 [ 0 ] . V_27 = V_26 -> V_114 . V_115 ;
V_7 -> V_122 -> V_123 [ 0 ] . V_91 = V_40 -> V_28 . V_121 ;
}
F_33 ( V_7 , & V_9 -> V_13 ,
V_90 -> V_124 , V_90 -> V_125 ) ;
V_7 -> V_31 . V_126 = F_34 ( V_26 -> V_127 , 0 ) ;
V_7 -> V_31 . V_128 = F_35 ( V_26 -> V_127 , 0 ) ;
F_36 ( V_26 -> V_26 , L_4 ,
V_23 -> V_27 . V_94 , V_23 -> V_27 . V_96 ) ;
return 0 ;
V_102:
F_37 ( & V_9 -> V_13 ) ;
V_101:
F_38 ( V_26 , V_87 ) ;
return V_45 ;
}
static struct V_11 * F_39
( struct V_25 * V_26 , struct V_129 * V_130 ,
const struct V_76 * V_73 )
{
struct V_78 * V_131 ;
struct V_132 * V_133 ;
V_133 = F_40 ( V_130 , V_73 -> V_134 [ 0 ] ) ;
if ( V_133 == NULL )
return F_21 ( - V_135 ) ;
V_131 = F_41 ( V_133 , struct V_78 , V_88 ) ;
return F_19 ( V_26 , V_73 , V_131 ) ;
}
static void F_42 ( struct V_136 * V_137 , T_3 V_2 , T_3 V_3 ,
T_3 V_4 , int V_1 )
{
struct V_138 * V_138 = F_43 ( V_137 ) ;
V_138 -> V_139 [ V_1 ] = V_2 >> 8 ;
V_138 -> V_140 [ V_1 ] = V_3 >> 8 ;
V_138 -> V_141 [ V_1 ] = V_4 >> 8 ;
}
static void F_44 ( struct V_136 * V_137 , T_3 * V_2 ,
T_3 * V_3 , T_3 * V_4 , int V_1 )
{
struct V_138 * V_138 = F_43 ( V_137 ) ;
* V_2 = V_138 -> V_139 [ V_1 ] << 8 ;
* V_3 = V_138 -> V_140 [ V_1 ] << 8 ;
* V_4 = V_138 -> V_141 [ V_1 ] << 8 ;
}
static int F_45 ( struct V_142 * V_143 ,
struct V_89 * V_90 )
{
struct V_8 * V_8 =
F_41 ( V_143 , struct V_8 , V_13 ) ;
struct V_25 * V_26 = V_8 -> V_13 . V_26 ;
struct V_39 * V_40 = V_26 -> V_41 ;
int V_144 ;
V_144 = V_90 -> V_98 / 8 ;
if ( V_144 == 3 )
V_144 = 4 ;
if ( F_27 ( V_90 -> V_124 * V_144 , 64 ) * V_90 -> V_125 >
V_40 -> V_145 ) {
V_90 -> V_98 = 16 ;
V_90 -> V_99 = 16 ;
}
return F_26 ( V_8 , V_90 ) ;
}
static int F_46 ( struct V_25 * V_26 , struct V_8 * V_9 )
{
struct V_22 * V_23 = & V_9 -> V_24 ;
F_47 ( & V_9 -> V_13 ) ;
F_37 ( & V_9 -> V_13 ) ;
F_48 ( & V_9 -> V_13 ) ;
F_49 ( & V_23 -> V_27 ) ;
F_50 ( & V_23 -> V_27 ) ;
if ( V_23 -> V_28 )
F_51 ( & V_23 -> V_28 -> V_88 ) ;
return 0 ;
}
int F_52 ( struct V_25 * V_26 )
{
struct V_8 * V_9 ;
struct V_39 * V_40 = V_26 -> V_41 ;
int V_45 ;
V_9 = F_20 ( sizeof( struct V_8 ) , V_85 ) ;
if ( ! V_9 ) {
F_18 ( V_26 -> V_26 , L_5 ) ;
return - V_15 ;
}
V_40 -> V_9 = V_9 ;
F_53 ( V_26 , & V_9 -> V_13 , & V_146 ) ;
V_45 = F_54 ( V_26 , & V_9 -> V_13 ,
V_40 -> V_106 -> V_147 , V_148 ) ;
if ( V_45 )
goto free;
V_45 = F_55 ( & V_9 -> V_13 ) ;
if ( V_45 )
goto V_149;
F_56 ( V_26 ) ;
V_45 = F_57 ( & V_9 -> V_13 , 32 ) ;
if ( V_45 )
goto V_149;
return 0 ;
V_149:
F_48 ( & V_9 -> V_13 ) ;
free:
F_22 ( V_9 ) ;
return V_45 ;
}
static void F_58 ( struct V_25 * V_26 )
{
struct V_39 * V_40 = V_26 -> V_41 ;
if ( ! V_40 -> V_9 )
return;
F_46 ( V_26 , V_40 -> V_9 ) ;
F_22 ( V_40 -> V_9 ) ;
V_40 -> V_9 = NULL ;
}
static void F_59 ( struct V_25 * V_26 )
{
struct V_39 * V_40 = V_26 -> V_41 ;
struct V_8 * V_9 = (struct V_8 * ) V_40 -> V_9 ;
F_60 ( & V_9 -> V_13 ) ;
}
static int F_61 ( struct V_11 * V_12 ,
struct V_129 * V_150 ,
unsigned int * V_151 )
{
struct V_22 * V_23 = F_62 ( V_12 ) ;
struct V_78 * V_131 = V_23 -> V_28 ;
return F_63 ( V_150 , & V_131 -> V_88 , V_151 ) ;
}
static void F_64 ( struct V_11 * V_12 )
{
struct V_22 * V_23 = F_62 ( V_12 ) ;
struct V_78 * V_131 = V_23 -> V_28 ;
F_50 ( V_12 ) ;
F_51 ( & V_131 -> V_88 ) ;
F_22 ( V_12 ) ;
}
static void F_65 ( struct V_25 * V_26 )
{
struct V_39 * V_40 = V_26 -> V_41 ;
struct V_152 * V_153 ;
F_66 ( V_26 ) ;
if ( ! V_40 -> V_154 )
V_40 -> V_154 = F_67 ( V_26 , 0 ,
L_6 , 0 , 100 ) ;
V_40 -> V_106 -> V_155 ( V_26 ) ;
F_68 (connector, &dev->mode_config.connector_list,
head) {
struct V_156 * V_156 = F_69 ( V_153 ) ;
struct V_157 * V_158 = & V_156 -> V_27 ;
int V_159 = 0 , V_160 = 0 ;
switch ( V_156 -> type ) {
case V_161 :
V_159 = ( 1 << 0 ) ;
V_160 = ( 1 << V_161 ) ;
break;
case V_162 :
V_159 = V_40 -> V_106 -> V_163 ;
V_160 = ( 1 << V_162 ) ;
break;
case V_164 :
V_159 = V_40 -> V_106 -> V_165 ;
V_160 = ( 1 << V_164 ) ;
break;
case V_166 :
V_159 = ( 1 << 0 ) ;
V_160 = ( 1 << V_166 ) ;
break;
case V_167 :
V_159 = ( 1 << 2 ) ;
V_160 = ( 1 << V_167 ) ;
break;
case V_168 :
V_159 = V_40 -> V_106 -> V_169 ;
V_160 = ( 1 << V_168 ) ;
break;
case V_170 :
V_159 = ( 1 << 0 ) | ( 1 << 1 ) ;
V_160 = ( 1 << V_170 ) ;
break;
case V_171 :
V_159 = ( 1 << 1 ) ;
V_160 = ( 1 << V_171 ) ;
}
V_158 -> V_172 = V_159 ;
V_158 -> V_173 =
F_70 ( V_26 , V_160 ) ;
}
}
void F_71 ( struct V_25 * V_26 )
{
struct V_39 * V_40 = V_26 -> V_41 ;
struct V_174 * V_175 = & V_40 -> V_175 ;
int V_43 ;
F_72 ( V_26 ) ;
V_26 -> V_114 . V_176 = 0 ;
V_26 -> V_114 . V_177 = 0 ;
V_26 -> V_114 . V_178 = & V_179 ;
F_73 ( V_26 -> V_127 , V_180 , ( T_2 * )
& ( V_26 -> V_114 . V_115 ) ) ;
for ( V_43 = 0 ; V_43 < V_40 -> V_181 ; V_43 ++ )
F_74 ( V_26 , V_43 , V_175 ) ;
V_26 -> V_114 . V_182 = 4096 ;
V_26 -> V_114 . V_183 = 4096 ;
F_65 ( V_26 ) ;
if ( V_40 -> V_106 -> V_184 )
V_40 -> V_106 -> V_184 ( V_26 ) ;
V_40 -> V_185 = true ;
}
void F_75 ( struct V_25 * V_26 )
{
struct V_39 * V_40 = V_26 -> V_41 ;
if ( V_40 -> V_185 ) {
F_76 ( V_26 ) ;
F_58 ( V_26 ) ;
F_77 ( V_26 ) ;
}
}
