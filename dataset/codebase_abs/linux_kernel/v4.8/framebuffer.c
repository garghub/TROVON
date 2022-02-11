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
static int F_13 ( struct V_25 * V_26 ,
struct V_22 * V_12 ,
const struct V_73 * V_74 ,
struct V_75 * V_76 )
{
T_2 V_77 , V_78 ;
int V_45 ;
F_14 ( V_74 -> V_79 , & V_78 , & V_77 ) ;
if ( V_74 -> V_80 [ 0 ] & 63 )
return - V_62 ;
switch ( V_77 ) {
case 8 :
case 16 :
case 24 :
case 32 :
break;
default:
return - V_62 ;
}
F_15 ( & V_12 -> V_27 , V_74 ) ;
V_12 -> V_28 = V_76 ;
V_45 = F_16 ( V_26 , & V_12 -> V_27 , & V_81 ) ;
if ( V_45 ) {
F_17 ( V_26 -> V_26 , L_1 , V_45 ) ;
return V_45 ;
}
return 0 ;
}
static struct V_11 * F_18
( struct V_25 * V_26 ,
const struct V_73 * V_74 ,
struct V_75 * V_76 )
{
struct V_22 * V_12 ;
int V_45 ;
V_12 = F_19 ( sizeof( * V_12 ) , V_82 ) ;
if ( ! V_12 )
return F_20 ( - V_15 ) ;
V_45 = F_13 ( V_26 , V_12 , V_74 , V_76 ) ;
if ( V_45 ) {
F_21 ( V_12 ) ;
return F_20 ( V_45 ) ;
}
return & V_12 -> V_27 ;
}
static struct V_75 * F_22 ( struct V_25 * V_26 , int V_83 )
{
struct V_75 * V_84 ;
V_84 = F_23 ( V_26 , V_83 , L_2 , 1 , V_59 ) ;
if ( V_84 ) {
F_24 ( V_26 , & V_84 -> V_85 , V_83 ) ;
return V_84 ;
}
return NULL ;
}
static int F_25 ( struct V_8 * V_9 ,
struct V_86 * V_87 )
{
struct V_25 * V_26 = V_9 -> V_13 . V_26 ;
struct V_39 * V_40 = V_26 -> V_41 ;
struct V_6 * V_7 ;
struct V_11 * V_12 ;
struct V_22 * V_23 = & V_9 -> V_24 ;
struct V_73 V_74 ;
int V_88 ;
int V_45 ;
struct V_75 * V_84 ;
T_2 V_77 , V_78 ;
int V_89 = 0 ;
int V_90 = 0 ;
V_74 . V_91 = V_87 -> V_92 ;
V_74 . V_93 = V_87 -> V_94 ;
V_77 = V_87 -> V_95 ;
V_78 = V_87 -> V_96 ;
if ( V_77 == 24 )
V_77 = 32 ;
do {
V_74 . V_80 [ 0 ] = F_26 ( V_74 . V_91 * ( ( V_77 + 7 ) / 8 ) , 4096 >> V_90 ) ;
V_88 = V_74 . V_80 [ 0 ] * V_74 . V_93 ;
V_88 = F_26 ( V_88 , V_59 ) ;
V_84 = F_22 ( V_26 , V_88 ) ;
if ( V_90 )
V_90 *= 2 ;
else
V_90 = 1 ;
V_89 ++ ;
} while ( V_84 == NULL && V_90 <= 16 );
V_90 /= 2 ;
if ( V_84 == NULL ) {
V_89 = 0 ;
V_90 = 64 ;
V_74 . V_80 [ 0 ] = F_26 ( V_74 . V_91 * ( ( V_77 + 7 ) / 8 ) , 64 ) ;
V_88 = V_74 . V_80 [ 0 ] * V_74 . V_93 ;
V_88 = F_26 ( V_88 , V_59 ) ;
V_84 = F_22 ( V_26 , V_88 ) ;
if ( V_84 == NULL )
return - V_15 ;
}
memset ( V_40 -> V_97 + V_84 -> V_18 , 0 , V_88 ) ;
V_7 = F_27 ( & V_9 -> V_13 ) ;
if ( F_28 ( V_7 ) ) {
V_45 = F_29 ( V_7 ) ;
goto V_98;
}
V_7 -> V_10 = V_9 ;
V_74 . V_79 = F_30 ( V_77 , V_78 ) ;
V_45 = F_13 ( V_26 , V_23 , & V_74 , V_84 ) ;
if ( V_45 )
goto V_99;
V_12 = & V_23 -> V_27 ;
V_23 -> V_9 = V_7 ;
V_9 -> V_13 . V_12 = V_12 ;
F_31 ( V_7 , V_12 -> V_80 [ 0 ] , V_12 -> V_78 ) ;
strcpy ( V_7 -> V_31 . V_100 , L_3 ) ;
V_7 -> V_101 = V_102 ;
if ( V_40 -> V_103 -> V_104 && V_90 > 8 )
V_7 -> V_105 = & V_106 ;
else if ( V_89 ) {
V_7 -> V_105 = & V_107 ;
V_7 -> V_101 |= V_108 ;
} else
V_7 -> V_105 = & V_109 ;
V_7 -> V_31 . V_110 = V_26 -> V_111 . V_112 ;
V_7 -> V_31 . V_113 = V_88 ;
V_7 -> V_31 . V_114 = V_89 ;
V_7 -> V_31 . V_115 = 0 ;
V_7 -> V_116 = V_40 -> V_97 + V_84 -> V_18 ;
V_7 -> V_117 = V_88 ;
if ( V_40 -> V_28 . V_118 ) {
V_7 -> V_119 -> V_120 [ 0 ] . V_27 = V_26 -> V_111 . V_112 ;
V_7 -> V_119 -> V_120 [ 0 ] . V_88 = V_40 -> V_28 . V_118 ;
}
F_32 ( V_7 , & V_9 -> V_13 ,
V_87 -> V_121 , V_87 -> V_122 ) ;
V_7 -> V_31 . V_123 = F_33 ( V_26 -> V_124 , 0 ) ;
V_7 -> V_31 . V_125 = F_34 ( V_26 -> V_124 , 0 ) ;
F_35 ( V_26 -> V_26 , L_4 ,
V_23 -> V_27 . V_91 , V_23 -> V_27 . V_93 ) ;
return 0 ;
V_99:
F_36 ( & V_9 -> V_13 ) ;
V_98:
F_37 ( V_26 , V_84 ) ;
return V_45 ;
}
static struct V_11 * F_38
( struct V_25 * V_26 , struct V_126 * V_127 ,
const struct V_73 * V_128 )
{
struct V_75 * V_129 ;
struct V_130 * V_131 ;
V_131 = F_39 ( V_127 , V_128 -> V_132 [ 0 ] ) ;
if ( V_131 == NULL )
return F_20 ( - V_133 ) ;
V_129 = F_40 ( V_131 , struct V_75 , V_85 ) ;
return F_18 ( V_26 , V_128 , V_129 ) ;
}
static void F_41 ( struct V_134 * V_135 , T_3 V_2 , T_3 V_3 ,
T_3 V_4 , int V_1 )
{
struct V_136 * V_136 = F_42 ( V_135 ) ;
V_136 -> V_137 [ V_1 ] = V_2 >> 8 ;
V_136 -> V_138 [ V_1 ] = V_3 >> 8 ;
V_136 -> V_139 [ V_1 ] = V_4 >> 8 ;
}
static void F_43 ( struct V_134 * V_135 , T_3 * V_2 ,
T_3 * V_3 , T_3 * V_4 , int V_1 )
{
struct V_136 * V_136 = F_42 ( V_135 ) ;
* V_2 = V_136 -> V_137 [ V_1 ] << 8 ;
* V_3 = V_136 -> V_138 [ V_1 ] << 8 ;
* V_4 = V_136 -> V_139 [ V_1 ] << 8 ;
}
static int F_44 ( struct V_140 * V_141 ,
struct V_86 * V_87 )
{
struct V_8 * V_8 =
F_40 ( V_141 , struct V_8 , V_13 ) ;
struct V_25 * V_26 = V_8 -> V_13 . V_26 ;
struct V_39 * V_40 = V_26 -> V_41 ;
int V_142 ;
V_142 = V_87 -> V_95 / 8 ;
if ( V_142 == 3 )
V_142 = 4 ;
if ( F_26 ( V_87 -> V_121 * V_142 , 64 ) * V_87 -> V_122 >
V_40 -> V_143 ) {
V_87 -> V_95 = 16 ;
V_87 -> V_96 = 16 ;
}
return F_25 ( V_8 , V_87 ) ;
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
F_50 ( & V_23 -> V_28 -> V_85 ) ;
return 0 ;
}
int F_51 ( struct V_25 * V_26 )
{
struct V_8 * V_9 ;
struct V_39 * V_40 = V_26 -> V_41 ;
int V_45 ;
V_9 = F_19 ( sizeof( struct V_8 ) , V_82 ) ;
if ( ! V_9 ) {
F_17 ( V_26 -> V_26 , L_5 ) ;
return - V_15 ;
}
V_40 -> V_9 = V_9 ;
F_52 ( V_26 , & V_9 -> V_13 , & V_144 ) ;
V_45 = F_53 ( V_26 , & V_9 -> V_13 ,
V_40 -> V_103 -> V_145 , V_146 ) ;
if ( V_45 )
goto free;
V_45 = F_54 ( & V_9 -> V_13 ) ;
if ( V_45 )
goto V_147;
F_55 ( V_26 ) ;
V_45 = F_56 ( & V_9 -> V_13 , 32 ) ;
if ( V_45 )
goto V_147;
return 0 ;
V_147:
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
struct V_126 * V_148 ,
unsigned int * V_149 )
{
struct V_22 * V_23 = F_61 ( V_12 ) ;
struct V_75 * V_129 = V_23 -> V_28 ;
return F_62 ( V_148 , & V_129 -> V_85 , V_149 ) ;
}
static void F_63 ( struct V_11 * V_12 )
{
struct V_22 * V_23 = F_61 ( V_12 ) ;
struct V_75 * V_129 = V_23 -> V_28 ;
F_49 ( V_12 ) ;
F_50 ( & V_129 -> V_85 ) ;
F_21 ( V_12 ) ;
}
static void F_64 ( struct V_25 * V_26 )
{
struct V_39 * V_40 = V_26 -> V_41 ;
struct V_150 * V_151 ;
F_65 ( V_26 ) ;
if ( ! V_40 -> V_152 )
V_40 -> V_152 = F_66 ( V_26 , 0 ,
L_6 , 0 , 100 ) ;
V_40 -> V_103 -> V_153 ( V_26 ) ;
F_67 (connector, &dev->mode_config.connector_list,
head) {
struct V_154 * V_154 = F_68 ( V_151 ) ;
struct V_155 * V_156 = & V_154 -> V_27 ;
int V_157 = 0 , V_158 = 0 ;
switch ( V_154 -> type ) {
case V_159 :
V_157 = ( 1 << 0 ) ;
V_158 = ( 1 << V_159 ) ;
break;
case V_160 :
V_157 = V_40 -> V_103 -> V_161 ;
V_158 = ( 1 << V_160 ) ;
break;
case V_162 :
V_157 = V_40 -> V_103 -> V_163 ;
V_158 = ( 1 << V_162 ) ;
break;
case V_164 :
V_157 = ( 1 << 0 ) ;
V_158 = ( 1 << V_164 ) ;
break;
case V_165 :
V_157 = ( 1 << 2 ) ;
V_158 = ( 1 << V_165 ) ;
break;
case V_166 :
V_157 = V_40 -> V_103 -> V_167 ;
V_158 = ( 1 << V_166 ) ;
break;
case V_168 :
V_157 = ( 1 << 0 ) | ( 1 << 1 ) ;
V_158 = ( 1 << V_168 ) ;
break;
case V_169 :
V_157 = ( 1 << 1 ) ;
V_158 = ( 1 << V_169 ) ;
}
V_156 -> V_170 = V_157 ;
V_156 -> V_171 =
F_69 ( V_26 , V_158 ) ;
}
}
void F_70 ( struct V_25 * V_26 )
{
struct V_39 * V_40 = V_26 -> V_41 ;
struct V_172 * V_173 = & V_40 -> V_173 ;
int V_43 ;
F_71 ( V_26 ) ;
V_26 -> V_111 . V_174 = 0 ;
V_26 -> V_111 . V_175 = 0 ;
V_26 -> V_111 . V_176 = & V_177 ;
F_72 ( V_26 -> V_124 , V_178 , ( T_2 * )
& ( V_26 -> V_111 . V_112 ) ) ;
for ( V_43 = 0 ; V_43 < V_40 -> V_179 ; V_43 ++ )
F_73 ( V_26 , V_43 , V_173 ) ;
V_26 -> V_111 . V_180 = 4096 ;
V_26 -> V_111 . V_181 = 4096 ;
F_64 ( V_26 ) ;
if ( V_40 -> V_103 -> V_182 )
V_40 -> V_103 -> V_182 ( V_26 ) ;
V_40 -> V_183 = true ;
}
void F_74 ( struct V_25 * V_26 )
{
struct V_39 * V_40 = V_26 -> V_41 ;
if ( V_40 -> V_183 ) {
F_75 ( V_26 ) ;
F_57 ( V_26 ) ;
F_76 ( V_26 ) ;
}
}
