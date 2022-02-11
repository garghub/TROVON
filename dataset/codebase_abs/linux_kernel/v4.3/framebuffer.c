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
F_15 ( & V_12 -> V_27 , V_76 ) ;
V_12 -> V_28 = V_78 ;
V_45 = F_16 ( V_26 , & V_12 -> V_27 , & V_83 ) ;
if ( V_45 ) {
F_17 ( V_26 -> V_26 , L_1 , V_45 ) ;
return V_45 ;
}
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
V_86 = F_23 ( V_26 , V_85 , L_2 , 1 , V_58 ) ;
if ( V_86 ) {
F_24 ( V_26 , & V_86 -> V_87 , V_85 ) ;
return V_86 ;
}
return NULL ;
}
static int F_25 ( struct V_8 * V_9 ,
struct V_88 * V_89 )
{
struct V_25 * V_26 = V_9 -> V_13 . V_26 ;
struct V_39 * V_40 = V_26 -> V_41 ;
struct V_6 * V_7 ;
struct V_11 * V_12 ;
struct V_22 * V_23 = & V_9 -> V_24 ;
struct V_75 V_76 ;
int V_90 ;
int V_45 ;
struct V_77 * V_86 ;
T_2 V_79 , V_80 ;
int V_91 = 0 ;
int V_92 = 0 ;
V_76 . V_93 = V_89 -> V_94 ;
V_76 . V_95 = V_89 -> V_96 ;
V_79 = V_89 -> V_97 ;
V_80 = V_89 -> V_98 ;
if ( V_79 == 24 )
V_79 = 32 ;
do {
V_76 . V_82 [ 0 ] = F_26 ( V_76 . V_93 * ( ( V_79 + 7 ) / 8 ) , 4096 >> V_92 ) ;
V_90 = V_76 . V_82 [ 0 ] * V_76 . V_95 ;
V_90 = F_26 ( V_90 , V_58 ) ;
V_86 = F_22 ( V_26 , V_90 ) ;
if ( V_92 )
V_92 *= 2 ;
else
V_92 = 1 ;
V_91 ++ ;
} while ( V_86 == NULL && V_92 <= 16 );
V_92 /= 2 ;
if ( V_86 == NULL ) {
V_91 = 0 ;
V_92 = 64 ;
V_76 . V_82 [ 0 ] = F_26 ( V_76 . V_93 * ( ( V_79 + 7 ) / 8 ) , 64 ) ;
V_90 = V_76 . V_82 [ 0 ] * V_76 . V_95 ;
V_90 = F_26 ( V_90 , V_58 ) ;
V_86 = F_22 ( V_26 , V_90 ) ;
if ( V_86 == NULL )
return - V_15 ;
}
memset ( V_40 -> V_99 + V_86 -> V_18 , 0 , V_90 ) ;
F_27 ( & V_26 -> V_100 ) ;
V_7 = F_28 ( & V_9 -> V_13 ) ;
if ( F_29 ( V_7 ) ) {
V_45 = F_30 ( V_7 ) ;
goto V_101;
}
V_7 -> V_10 = V_9 ;
V_76 . V_81 = F_31 ( V_79 , V_80 ) ;
V_45 = F_13 ( V_26 , V_23 , & V_76 , V_86 ) ;
if ( V_45 )
goto V_102;
V_12 = & V_23 -> V_27 ;
V_23 -> V_9 = V_7 ;
V_9 -> V_13 . V_12 = V_12 ;
F_32 ( V_7 , V_12 -> V_82 [ 0 ] , V_12 -> V_80 ) ;
strcpy ( V_7 -> V_31 . V_103 , L_3 ) ;
V_7 -> V_104 = V_105 ;
if ( V_40 -> V_106 -> V_107 && V_92 > 8 )
V_7 -> V_108 = & V_109 ;
else if ( V_91 ) {
V_7 -> V_108 = & V_110 ;
V_7 -> V_104 |= V_111 ;
} else
V_7 -> V_108 = & V_112 ;
V_7 -> V_31 . V_113 = V_26 -> V_114 . V_115 ;
V_7 -> V_31 . V_116 = V_90 ;
V_7 -> V_31 . V_117 = V_91 ;
V_7 -> V_31 . V_118 = 0 ;
V_7 -> V_119 = V_40 -> V_99 + V_86 -> V_18 ;
V_7 -> V_120 = V_90 ;
if ( V_40 -> V_28 . V_121 ) {
V_7 -> V_122 -> V_123 [ 0 ] . V_27 = V_26 -> V_114 . V_115 ;
V_7 -> V_122 -> V_123 [ 0 ] . V_90 = V_40 -> V_28 . V_121 ;
}
F_33 ( V_7 , & V_9 -> V_13 ,
V_89 -> V_124 , V_89 -> V_125 ) ;
V_7 -> V_31 . V_126 = F_34 ( V_26 -> V_127 , 0 ) ;
V_7 -> V_31 . V_128 = F_35 ( V_26 -> V_127 , 0 ) ;
F_36 ( V_26 -> V_26 , L_4 ,
V_23 -> V_27 . V_93 , V_23 -> V_27 . V_95 ) ;
F_37 ( & V_26 -> V_100 ) ;
return 0 ;
V_102:
if ( V_86 -> V_129 )
F_38 ( V_26 , V_86 ) ;
else
F_39 ( & V_86 -> V_87 ) ;
F_40 ( & V_9 -> V_13 ) ;
V_101:
F_37 ( & V_26 -> V_100 ) ;
F_38 ( V_26 , V_86 ) ;
return V_45 ;
}
static struct V_11 * F_41
( struct V_25 * V_26 , struct V_130 * V_131 ,
struct V_75 * V_72 )
{
struct V_77 * V_132 ;
struct V_133 * V_134 ;
V_134 = F_42 ( V_26 , V_131 , V_72 -> V_135 [ 0 ] ) ;
if ( V_134 == NULL )
return F_20 ( - V_136 ) ;
V_132 = F_43 ( V_134 , struct V_77 , V_87 ) ;
return F_18 ( V_26 , V_72 , V_132 ) ;
}
static void F_44 ( struct V_137 * V_138 , T_3 V_2 , T_3 V_3 ,
T_3 V_4 , int V_1 )
{
struct V_139 * V_139 = F_45 ( V_138 ) ;
V_139 -> V_140 [ V_1 ] = V_2 >> 8 ;
V_139 -> V_141 [ V_1 ] = V_3 >> 8 ;
V_139 -> V_142 [ V_1 ] = V_4 >> 8 ;
}
static void F_46 ( struct V_137 * V_138 , T_3 * V_2 ,
T_3 * V_3 , T_3 * V_4 , int V_1 )
{
struct V_139 * V_139 = F_45 ( V_138 ) ;
* V_2 = V_139 -> V_140 [ V_1 ] << 8 ;
* V_3 = V_139 -> V_141 [ V_1 ] << 8 ;
* V_4 = V_139 -> V_142 [ V_1 ] << 8 ;
}
static int F_47 ( struct V_143 * V_144 ,
struct V_88 * V_89 )
{
struct V_8 * V_8 =
F_43 ( V_144 , struct V_8 , V_13 ) ;
struct V_25 * V_26 = V_8 -> V_13 . V_26 ;
struct V_39 * V_40 = V_26 -> V_41 ;
int V_145 ;
V_145 = V_89 -> V_97 / 8 ;
if ( V_145 == 3 )
V_145 = 4 ;
if ( F_26 ( V_89 -> V_124 * V_145 , 64 ) * V_89 -> V_125 >
V_40 -> V_146 ) {
V_89 -> V_97 = 16 ;
V_89 -> V_98 = 16 ;
}
return F_25 ( V_8 , V_89 ) ;
}
static int F_48 ( struct V_25 * V_26 , struct V_8 * V_9 )
{
struct V_22 * V_23 = & V_9 -> V_24 ;
F_49 ( & V_9 -> V_13 ) ;
F_40 ( & V_9 -> V_13 ) ;
F_50 ( & V_9 -> V_13 ) ;
F_51 ( & V_23 -> V_27 ) ;
F_52 ( & V_23 -> V_27 ) ;
if ( V_23 -> V_28 )
F_39 ( & V_23 -> V_28 -> V_87 ) ;
return 0 ;
}
int F_53 ( struct V_25 * V_26 )
{
struct V_8 * V_9 ;
struct V_39 * V_40 = V_26 -> V_41 ;
int V_45 ;
V_9 = F_19 ( sizeof( struct V_8 ) , V_84 ) ;
if ( ! V_9 ) {
F_17 ( V_26 -> V_26 , L_5 ) ;
return - V_15 ;
}
V_40 -> V_9 = V_9 ;
F_54 ( V_26 , & V_9 -> V_13 , & V_147 ) ;
V_45 = F_55 ( V_26 , & V_9 -> V_13 ,
V_40 -> V_106 -> V_148 , V_149 ) ;
if ( V_45 )
goto free;
V_45 = F_56 ( & V_9 -> V_13 ) ;
if ( V_45 )
goto V_150;
F_57 ( V_26 ) ;
V_45 = F_58 ( & V_9 -> V_13 , 32 ) ;
if ( V_45 )
goto V_150;
return 0 ;
V_150:
F_50 ( & V_9 -> V_13 ) ;
free:
F_21 ( V_9 ) ;
return V_45 ;
}
static void F_59 ( struct V_25 * V_26 )
{
struct V_39 * V_40 = V_26 -> V_41 ;
if ( ! V_40 -> V_9 )
return;
F_48 ( V_26 , V_40 -> V_9 ) ;
F_21 ( V_40 -> V_9 ) ;
V_40 -> V_9 = NULL ;
}
static void F_60 ( struct V_25 * V_26 )
{
struct V_39 * V_40 = V_26 -> V_41 ;
struct V_8 * V_9 = (struct V_8 * ) V_40 -> V_9 ;
F_61 ( & V_9 -> V_13 ) ;
}
static int F_62 ( struct V_11 * V_12 ,
struct V_130 * V_151 ,
unsigned int * V_152 )
{
struct V_22 * V_23 = F_63 ( V_12 ) ;
struct V_77 * V_132 = V_23 -> V_28 ;
return F_64 ( V_151 , & V_132 -> V_87 , V_152 ) ;
}
static void F_65 ( struct V_11 * V_12 )
{
struct V_22 * V_23 = F_63 ( V_12 ) ;
struct V_77 * V_132 = V_23 -> V_28 ;
F_52 ( V_12 ) ;
F_66 ( & V_132 -> V_87 ) ;
F_21 ( V_12 ) ;
}
static int F_67 ( struct V_25 * V_26 )
{
struct V_39 * V_40 = V_26 -> V_41 ;
struct V_153 * V_154 ;
if ( V_40 -> V_155 )
return 0 ;
V_154 = F_68 ( V_26 , 0 , L_6 , 0 , 100 ) ;
V_40 -> V_155 = V_154 ;
return 0 ;
}
static void F_69 ( struct V_25 * V_26 )
{
struct V_39 * V_40 = V_26 -> V_41 ;
struct V_156 * V_157 ;
F_70 ( V_26 ) ;
F_67 ( V_26 ) ;
V_40 -> V_106 -> V_158 ( V_26 ) ;
F_71 (connector, &dev->mode_config.connector_list,
head) {
struct V_159 * V_159 = F_72 ( V_157 ) ;
struct V_160 * V_161 = & V_159 -> V_27 ;
int V_162 = 0 , V_163 = 0 ;
switch ( V_159 -> type ) {
case V_164 :
V_162 = ( 1 << 0 ) ;
V_163 = ( 1 << V_164 ) ;
break;
case V_165 :
V_162 = V_40 -> V_106 -> V_166 ;
V_163 = ( 1 << V_165 ) ;
break;
case V_167 :
V_162 = V_40 -> V_106 -> V_168 ;
V_163 = ( 1 << V_167 ) ;
break;
case V_169 :
V_162 = ( 1 << 0 ) ;
V_163 = ( 1 << V_169 ) ;
break;
case V_170 :
V_162 = ( 1 << 2 ) ;
V_163 = ( 1 << V_170 ) ;
break;
case V_171 :
V_162 = V_40 -> V_106 -> V_172 ;
V_163 = ( 1 << V_171 ) ;
break;
case V_173 :
V_162 = ( 1 << 0 ) | ( 1 << 1 ) ;
V_163 = ( 1 << V_173 ) ;
break;
case V_174 :
V_162 = ( 1 << 1 ) ;
V_163 = ( 1 << V_174 ) ;
}
V_161 -> V_175 = V_162 ;
V_161 -> V_176 =
F_73 ( V_26 , V_163 ) ;
}
}
void F_74 ( struct V_25 * V_26 )
{
struct V_39 * V_40 = V_26 -> V_41 ;
struct V_177 * V_178 = & V_40 -> V_178 ;
int V_43 ;
F_75 ( V_26 ) ;
V_26 -> V_114 . V_179 = 0 ;
V_26 -> V_114 . V_180 = 0 ;
V_26 -> V_114 . V_181 = & V_182 ;
F_76 ( V_26 -> V_127 , V_183 , ( T_2 * )
& ( V_26 -> V_114 . V_115 ) ) ;
for ( V_43 = 0 ; V_43 < V_40 -> V_184 ; V_43 ++ )
F_77 ( V_26 , V_43 , V_178 ) ;
V_26 -> V_114 . V_185 = 4096 ;
V_26 -> V_114 . V_186 = 4096 ;
F_69 ( V_26 ) ;
if ( V_40 -> V_106 -> V_187 )
V_40 -> V_106 -> V_187 ( V_26 ) ;
V_40 -> V_188 = true ;
}
void F_78 ( struct V_25 * V_26 )
{
struct V_39 * V_40 = V_26 -> V_41 ;
if ( V_40 -> V_188 ) {
F_27 ( & V_26 -> V_100 ) ;
F_79 ( V_26 ) ;
F_59 ( V_26 ) ;
F_80 ( V_26 ) ;
F_37 ( & V_26 -> V_100 ) ;
}
}
