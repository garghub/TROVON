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
V_42 = F_6 ( V_35 ) ;
V_44 = V_37 -> V_44 - ( V_37 -> V_49 << V_50 ) ;
V_35 -> V_51 = F_7 ( V_35 -> V_51 ) ;
for ( V_43 = 0 ; V_43 < V_42 ; V_43 ++ ) {
V_46 = ( V_47 >> V_50 ) ;
V_45 = F_8 ( V_35 , V_44 ,
F_9 ( V_46 , V_52 ) ) ;
if ( F_10 ( ( V_45 == - V_53 ) || ( V_45 != 0 && V_43 > 0 ) ) )
break;
else if ( F_10 ( V_45 != 0 ) ) {
V_45 = ( V_45 == - V_15 ) ? V_54 : V_55 ;
return V_45 ;
}
V_44 += V_56 ;
V_47 += V_56 ;
}
return V_57 ;
}
static void F_11 ( struct V_34 * V_35 )
{
}
static void F_12 ( struct V_34 * V_35 )
{
}
static int F_13 ( struct V_6 * V_7 , struct V_34 * V_35 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_22 * V_23 = & V_9 -> V_24 ;
if ( V_35 -> V_58 != 0 )
return - V_59 ;
if ( V_35 -> V_58 > ( ~ 0UL >> V_50 ) )
return - V_59 ;
if ( ! V_23 -> V_60 )
V_23 -> V_60 = V_35 -> V_61 -> V_62 ;
V_35 -> V_63 = & V_64 ;
V_35 -> V_38 = ( void * ) V_23 ;
V_35 -> V_65 |= V_66 | V_67 | V_68 | V_69 ;
return 0 ;
}
static int F_14 ( struct V_25 * V_26 ,
struct V_22 * V_12 ,
const struct V_70 * V_71 ,
struct V_72 * V_73 )
{
const struct V_74 * V_7 ;
int V_45 ;
V_7 = V_74 ( V_71 -> V_75 ) ;
if ( ! V_7 || ! V_7 -> V_76 || V_7 -> V_77 [ 0 ] > 4 )
return - V_59 ;
if ( V_71 -> V_78 [ 0 ] & 63 )
return - V_59 ;
F_15 ( & V_12 -> V_27 , V_71 ) ;
V_12 -> V_28 = V_73 ;
V_45 = F_16 ( V_26 , & V_12 -> V_27 , & V_79 ) ;
if ( V_45 ) {
F_17 ( V_26 -> V_26 , L_1 , V_45 ) ;
return V_45 ;
}
return 0 ;
}
static struct V_11 * F_18
( struct V_25 * V_26 ,
const struct V_70 * V_71 ,
struct V_72 * V_73 )
{
struct V_22 * V_12 ;
int V_45 ;
V_12 = F_19 ( sizeof( * V_12 ) , V_80 ) ;
if ( ! V_12 )
return F_20 ( - V_15 ) ;
V_45 = F_14 ( V_26 , V_12 , V_71 , V_73 ) ;
if ( V_45 ) {
F_21 ( V_12 ) ;
return F_20 ( V_45 ) ;
}
return & V_12 -> V_27 ;
}
static struct V_72 * F_22 ( struct V_25 * V_26 , int V_81 )
{
struct V_72 * V_82 ;
V_82 = F_23 ( V_26 , V_81 , L_2 , 1 , V_56 ) ;
if ( V_82 ) {
F_24 ( V_26 , & V_82 -> V_83 , V_81 ) ;
return V_82 ;
}
return NULL ;
}
static int F_25 ( struct V_8 * V_9 ,
struct V_84 * V_85 )
{
struct V_25 * V_26 = V_9 -> V_13 . V_26 ;
struct V_39 * V_40 = V_26 -> V_41 ;
struct V_6 * V_7 ;
struct V_11 * V_12 ;
struct V_22 * V_23 = & V_9 -> V_24 ;
struct V_70 V_71 ;
int V_86 ;
int V_45 ;
struct V_72 * V_82 ;
T_2 V_87 , V_76 ;
int V_88 = 0 ;
int V_89 = 0 ;
V_71 . V_90 = V_85 -> V_91 ;
V_71 . V_92 = V_85 -> V_93 ;
V_87 = V_85 -> V_94 ;
V_76 = V_85 -> V_95 ;
if ( V_87 == 24 )
V_87 = 32 ;
do {
V_71 . V_78 [ 0 ] = F_26 ( V_71 . V_90 * ( ( V_87 + 7 ) / 8 ) , 4096 >> V_89 ) ;
V_86 = V_71 . V_78 [ 0 ] * V_71 . V_92 ;
V_86 = F_26 ( V_86 , V_56 ) ;
V_82 = F_22 ( V_26 , V_86 ) ;
if ( V_89 )
V_89 *= 2 ;
else
V_89 = 1 ;
V_88 ++ ;
} while ( V_82 == NULL && V_89 <= 16 );
V_89 /= 2 ;
if ( V_82 == NULL ) {
V_88 = 0 ;
V_89 = 64 ;
V_71 . V_78 [ 0 ] = F_26 ( V_71 . V_90 * ( ( V_87 + 7 ) / 8 ) , 64 ) ;
V_86 = V_71 . V_78 [ 0 ] * V_71 . V_92 ;
V_86 = F_26 ( V_86 , V_56 ) ;
V_82 = F_22 ( V_26 , V_86 ) ;
if ( V_82 == NULL )
return - V_15 ;
}
memset ( V_40 -> V_96 + V_82 -> V_18 , 0 , V_86 ) ;
V_7 = F_27 ( & V_9 -> V_13 ) ;
if ( F_28 ( V_7 ) ) {
V_45 = F_29 ( V_7 ) ;
goto V_97;
}
V_7 -> V_10 = V_9 ;
V_71 . V_75 = F_30 ( V_87 , V_76 ) ;
V_45 = F_14 ( V_26 , V_23 , & V_71 , V_82 ) ;
if ( V_45 )
goto V_98;
V_12 = & V_23 -> V_27 ;
V_23 -> V_9 = V_7 ;
V_9 -> V_13 . V_12 = V_12 ;
F_31 ( V_7 , V_12 -> V_78 [ 0 ] , V_12 -> V_76 ) ;
strcpy ( V_7 -> V_31 . V_99 , L_3 ) ;
V_7 -> V_100 = V_101 ;
if ( V_40 -> V_102 -> V_103 && V_89 > 8 )
V_7 -> V_104 = & V_105 ;
else if ( V_88 ) {
V_7 -> V_104 = & V_106 ;
V_7 -> V_100 |= V_107 ;
} else
V_7 -> V_104 = & V_108 ;
V_7 -> V_31 . V_109 = V_26 -> V_110 . V_111 ;
V_7 -> V_31 . V_112 = V_86 ;
V_7 -> V_31 . V_113 = V_88 ;
V_7 -> V_31 . V_114 = 0 ;
V_7 -> V_115 = V_40 -> V_96 + V_82 -> V_18 ;
V_7 -> V_116 = V_86 ;
if ( V_40 -> V_28 . V_117 ) {
V_7 -> V_118 -> V_119 [ 0 ] . V_27 = V_26 -> V_110 . V_111 ;
V_7 -> V_118 -> V_119 [ 0 ] . V_86 = V_40 -> V_28 . V_117 ;
}
F_32 ( V_7 , & V_9 -> V_13 ,
V_85 -> V_120 , V_85 -> V_121 ) ;
V_7 -> V_31 . V_122 = F_33 ( V_26 -> V_123 , 0 ) ;
V_7 -> V_31 . V_124 = F_34 ( V_26 -> V_123 , 0 ) ;
F_35 ( V_26 -> V_26 , L_4 ,
V_23 -> V_27 . V_90 , V_23 -> V_27 . V_92 ) ;
return 0 ;
V_98:
F_36 ( & V_9 -> V_13 ) ;
V_97:
F_37 ( V_26 , V_82 ) ;
return V_45 ;
}
static struct V_11 * F_38
( struct V_25 * V_26 , struct V_125 * V_126 ,
const struct V_70 * V_127 )
{
struct V_72 * V_128 ;
struct V_129 * V_130 ;
V_130 = F_39 ( V_126 , V_127 -> V_131 [ 0 ] ) ;
if ( V_130 == NULL )
return F_20 ( - V_132 ) ;
V_128 = F_40 ( V_130 , struct V_72 , V_83 ) ;
return F_18 ( V_26 , V_127 , V_128 ) ;
}
static void F_41 ( struct V_133 * V_134 , T_3 V_2 , T_3 V_3 ,
T_3 V_4 , int V_1 )
{
struct V_135 * V_135 = F_42 ( V_134 ) ;
V_135 -> V_136 [ V_1 ] = V_2 >> 8 ;
V_135 -> V_137 [ V_1 ] = V_3 >> 8 ;
V_135 -> V_138 [ V_1 ] = V_4 >> 8 ;
}
static void F_43 ( struct V_133 * V_134 , T_3 * V_2 ,
T_3 * V_3 , T_3 * V_4 , int V_1 )
{
struct V_135 * V_135 = F_42 ( V_134 ) ;
* V_2 = V_135 -> V_136 [ V_1 ] << 8 ;
* V_3 = V_135 -> V_137 [ V_1 ] << 8 ;
* V_4 = V_135 -> V_138 [ V_1 ] << 8 ;
}
static int F_44 ( struct V_139 * V_140 ,
struct V_84 * V_85 )
{
struct V_8 * V_8 =
F_40 ( V_140 , struct V_8 , V_13 ) ;
struct V_25 * V_26 = V_8 -> V_13 . V_26 ;
struct V_39 * V_40 = V_26 -> V_41 ;
int V_141 ;
V_141 = V_85 -> V_94 / 8 ;
if ( V_141 == 3 )
V_141 = 4 ;
if ( F_26 ( V_85 -> V_120 * V_141 , 64 ) * V_85 -> V_121 >
V_40 -> V_142 ) {
V_85 -> V_94 = 16 ;
V_85 -> V_95 = 16 ;
}
return F_25 ( V_8 , V_85 ) ;
}
static int F_45 ( struct V_25 * V_26 , struct V_8 * V_9 )
{
struct V_22 * V_23 = & V_9 -> V_24 ;
F_46 ( & V_9 -> V_13 ) ;
F_36 ( & V_9 -> V_13 ) ;
F_47 ( & V_9 -> V_13 ) ;
F_48 ( & V_23 -> V_27 ) ;
F_49 ( & V_23 -> V_27 ) ;
if ( V_23 -> V_28 )
F_50 ( & V_23 -> V_28 -> V_83 ) ;
return 0 ;
}
int F_51 ( struct V_25 * V_26 )
{
struct V_8 * V_9 ;
struct V_39 * V_40 = V_26 -> V_41 ;
int V_45 ;
V_9 = F_19 ( sizeof( struct V_8 ) , V_80 ) ;
if ( ! V_9 ) {
F_17 ( V_26 -> V_26 , L_5 ) ;
return - V_15 ;
}
V_40 -> V_9 = V_9 ;
F_52 ( V_26 , & V_9 -> V_13 , & V_143 ) ;
V_45 = F_53 ( V_26 , & V_9 -> V_13 ,
V_40 -> V_102 -> V_144 , V_145 ) ;
if ( V_45 )
goto free;
V_45 = F_54 ( & V_9 -> V_13 ) ;
if ( V_45 )
goto V_146;
F_55 ( V_26 ) ;
V_45 = F_56 ( & V_9 -> V_13 , 32 ) ;
if ( V_45 )
goto V_146;
return 0 ;
V_146:
F_47 ( & V_9 -> V_13 ) ;
free:
F_21 ( V_9 ) ;
return V_45 ;
}
static void F_57 ( struct V_25 * V_26 )
{
struct V_39 * V_40 = V_26 -> V_41 ;
if ( ! V_40 -> V_9 )
return;
F_45 ( V_26 , V_40 -> V_9 ) ;
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
struct V_125 * V_147 ,
unsigned int * V_148 )
{
struct V_22 * V_23 = F_61 ( V_12 ) ;
struct V_72 * V_128 = V_23 -> V_28 ;
return F_62 ( V_147 , & V_128 -> V_83 , V_148 ) ;
}
static void F_63 ( struct V_11 * V_12 )
{
struct V_22 * V_23 = F_61 ( V_12 ) ;
struct V_72 * V_128 = V_23 -> V_28 ;
F_49 ( V_12 ) ;
F_50 ( & V_128 -> V_83 ) ;
F_21 ( V_12 ) ;
}
static void F_64 ( struct V_25 * V_26 )
{
struct V_39 * V_40 = V_26 -> V_41 ;
struct V_149 * V_150 ;
F_65 ( V_26 ) ;
if ( ! V_40 -> V_151 )
V_40 -> V_151 = F_66 ( V_26 , 0 ,
L_6 , 0 , 100 ) ;
V_40 -> V_102 -> V_152 ( V_26 ) ;
F_67 (connector, &dev->mode_config.connector_list,
head) {
struct V_153 * V_153 = F_68 ( V_150 ) ;
struct V_154 * V_155 = & V_153 -> V_27 ;
int V_156 = 0 , V_157 = 0 ;
switch ( V_153 -> type ) {
case V_158 :
V_156 = ( 1 << 0 ) ;
V_157 = ( 1 << V_158 ) ;
break;
case V_159 :
V_156 = V_40 -> V_102 -> V_160 ;
V_157 = ( 1 << V_159 ) ;
break;
case V_161 :
V_156 = V_40 -> V_102 -> V_162 ;
V_157 = ( 1 << V_161 ) ;
break;
case V_163 :
V_156 = ( 1 << 0 ) ;
V_157 = ( 1 << V_163 ) ;
break;
case V_164 :
V_156 = ( 1 << 2 ) ;
V_157 = ( 1 << V_164 ) ;
break;
case V_165 :
V_156 = V_40 -> V_102 -> V_166 ;
V_157 = ( 1 << V_165 ) ;
break;
case V_167 :
V_156 = ( 1 << 0 ) | ( 1 << 1 ) ;
V_157 = ( 1 << V_167 ) ;
break;
case V_168 :
V_156 = ( 1 << 1 ) ;
V_157 = ( 1 << V_168 ) ;
}
V_155 -> V_169 = V_156 ;
V_155 -> V_170 =
F_69 ( V_26 , V_157 ) ;
}
}
void F_70 ( struct V_25 * V_26 )
{
struct V_39 * V_40 = V_26 -> V_41 ;
struct V_171 * V_172 = & V_40 -> V_172 ;
int V_43 ;
F_71 ( V_26 ) ;
V_26 -> V_110 . V_173 = 0 ;
V_26 -> V_110 . V_174 = 0 ;
V_26 -> V_110 . V_175 = & V_176 ;
F_72 ( V_26 -> V_123 , V_177 , ( T_2 * )
& ( V_26 -> V_110 . V_111 ) ) ;
for ( V_43 = 0 ; V_43 < V_40 -> V_178 ; V_43 ++ )
F_73 ( V_26 , V_43 , V_172 ) ;
V_26 -> V_110 . V_179 = 4096 ;
V_26 -> V_110 . V_180 = 4096 ;
F_64 ( V_26 ) ;
if ( V_40 -> V_102 -> V_181 )
V_40 -> V_102 -> V_181 ( V_26 ) ;
V_40 -> V_182 = true ;
}
void F_74 ( struct V_25 * V_26 )
{
struct V_39 * V_40 = V_26 -> V_41 ;
if ( V_40 -> V_182 ) {
F_75 ( V_26 ) ;
F_57 ( V_26 ) ;
F_76 ( V_26 ) ;
}
}
