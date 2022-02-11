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
switch ( V_12 -> V_19 -> V_20 [ 0 ] * 8 ) {
case 16 :
( ( T_1 * ) V_7 -> V_21 ) [ V_1 ] = V_14 ;
break;
case 24 :
case 32 :
( ( T_1 * ) V_7 -> V_21 ) [ V_1 ] = V_14 ;
break;
}
}
return 0 ;
}
static int F_3 ( struct V_22 * V_16 , struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_23 * V_24 = & V_9 -> V_25 ;
struct V_26 * V_27 = V_24 -> V_28 . V_27 ;
if ( V_24 -> V_29 -> V_30 ) {
int V_31 = V_7 -> V_32 . V_33 >> 12 ;
F_4 ( V_27 , V_24 -> V_29 , V_16 -> V_34 * V_31 ) ;
}
return 0 ;
}
static int F_5 ( struct V_35 * V_36 )
{
struct V_37 * V_38 = V_36 -> V_38 ;
struct V_23 * V_24 = V_38 -> V_39 ;
struct V_26 * V_27 = V_24 -> V_28 . V_27 ;
struct V_40 * V_41 = V_27 -> V_42 ;
int V_43 ;
int V_44 ;
unsigned long V_45 ;
int V_46 ;
unsigned long V_47 ;
unsigned long V_48 = ( unsigned long ) V_41 -> V_49 +
V_24 -> V_29 -> V_18 ;
V_43 = F_6 ( V_38 ) ;
V_45 = V_36 -> V_45 - ( V_36 -> V_50 << V_51 ) ;
V_38 -> V_52 = F_7 ( V_38 -> V_52 ) ;
for ( V_44 = 0 ; V_44 < V_43 ; V_44 ++ ) {
V_47 = ( V_48 >> V_51 ) ;
V_46 = F_8 ( V_38 , V_45 ,
F_9 ( V_47 , V_53 ) ) ;
if ( F_10 ( ( V_46 == - V_54 ) || ( V_46 != 0 && V_44 > 0 ) ) )
break;
else if ( F_10 ( V_46 != 0 ) ) {
V_46 = ( V_46 == - V_15 ) ? V_55 : V_56 ;
return V_46 ;
}
V_45 += V_57 ;
V_48 += V_57 ;
}
return V_58 ;
}
static void F_11 ( struct V_37 * V_38 )
{
}
static void F_12 ( struct V_37 * V_38 )
{
}
static int F_13 ( struct V_6 * V_7 , struct V_37 * V_38 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_23 * V_24 = & V_9 -> V_25 ;
if ( V_38 -> V_59 != 0 )
return - V_60 ;
if ( V_38 -> V_59 > ( ~ 0UL >> V_51 ) )
return - V_60 ;
if ( ! V_24 -> V_61 )
V_24 -> V_61 = V_38 -> V_62 -> V_63 ;
V_38 -> V_64 = & V_65 ;
V_38 -> V_39 = ( void * ) V_24 ;
V_38 -> V_66 |= V_67 | V_68 | V_69 | V_70 ;
return 0 ;
}
static int F_14 ( struct V_26 * V_27 ,
struct V_23 * V_12 ,
const struct V_71 * V_72 ,
struct V_73 * V_74 )
{
const struct V_75 * V_7 ;
int V_46 ;
V_7 = V_75 ( V_72 -> V_76 ) ;
if ( ! V_7 || ! V_7 -> V_77 || V_7 -> V_20 [ 0 ] > 4 )
return - V_60 ;
if ( V_72 -> V_78 [ 0 ] & 63 )
return - V_60 ;
F_15 ( V_27 , & V_12 -> V_28 , V_72 ) ;
V_12 -> V_29 = V_74 ;
V_46 = F_16 ( V_27 , & V_12 -> V_28 , & V_79 ) ;
if ( V_46 ) {
F_17 ( V_27 -> V_27 , L_1 , V_46 ) ;
return V_46 ;
}
return 0 ;
}
static struct V_11 * F_18
( struct V_26 * V_27 ,
const struct V_71 * V_72 ,
struct V_73 * V_74 )
{
struct V_23 * V_12 ;
int V_46 ;
V_12 = F_19 ( sizeof( * V_12 ) , V_80 ) ;
if ( ! V_12 )
return F_20 ( - V_15 ) ;
V_46 = F_14 ( V_27 , V_12 , V_72 , V_74 ) ;
if ( V_46 ) {
F_21 ( V_12 ) ;
return F_20 ( V_46 ) ;
}
return & V_12 -> V_28 ;
}
static struct V_73 * F_22 ( struct V_26 * V_27 , int V_81 )
{
struct V_73 * V_82 ;
V_82 = F_23 ( V_27 , V_81 , L_2 , 1 , V_57 ) ;
if ( V_82 ) {
F_24 ( V_27 , & V_82 -> V_83 , V_81 ) ;
return V_82 ;
}
return NULL ;
}
static int F_25 ( struct V_8 * V_9 ,
struct V_84 * V_85 )
{
struct V_26 * V_27 = V_9 -> V_13 . V_27 ;
struct V_40 * V_41 = V_27 -> V_42 ;
struct V_6 * V_7 ;
struct V_11 * V_12 ;
struct V_23 * V_24 = & V_9 -> V_25 ;
struct V_71 V_72 ;
int V_86 ;
int V_46 ;
struct V_73 * V_82 ;
T_2 V_87 , V_77 ;
int V_88 = 0 ;
int V_89 = 0 ;
V_72 . V_90 = V_85 -> V_91 ;
V_72 . V_92 = V_85 -> V_93 ;
V_87 = V_85 -> V_94 ;
V_77 = V_85 -> V_95 ;
if ( V_87 == 24 )
V_87 = 32 ;
do {
V_72 . V_78 [ 0 ] = F_26 ( V_72 . V_90 * ( ( V_87 + 7 ) / 8 ) , 4096 >> V_89 ) ;
V_86 = V_72 . V_78 [ 0 ] * V_72 . V_92 ;
V_86 = F_26 ( V_86 , V_57 ) ;
V_82 = F_22 ( V_27 , V_86 ) ;
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
V_72 . V_78 [ 0 ] = F_26 ( V_72 . V_90 * ( ( V_87 + 7 ) / 8 ) , 64 ) ;
V_86 = V_72 . V_78 [ 0 ] * V_72 . V_92 ;
V_86 = F_26 ( V_86 , V_57 ) ;
V_82 = F_22 ( V_27 , V_86 ) ;
if ( V_82 == NULL )
return - V_15 ;
}
memset ( V_41 -> V_96 + V_82 -> V_18 , 0 , V_86 ) ;
V_7 = F_27 ( & V_9 -> V_13 ) ;
if ( F_28 ( V_7 ) ) {
V_46 = F_29 ( V_7 ) ;
goto V_97;
}
V_7 -> V_10 = V_9 ;
V_72 . V_76 = F_30 ( V_87 , V_77 ) ;
V_46 = F_14 ( V_27 , V_24 , & V_72 , V_82 ) ;
if ( V_46 )
goto V_97;
V_12 = & V_24 -> V_28 ;
V_24 -> V_9 = V_7 ;
V_9 -> V_13 . V_12 = V_12 ;
F_31 ( V_7 , V_12 -> V_78 [ 0 ] , V_12 -> V_19 -> V_77 ) ;
strcpy ( V_7 -> V_32 . V_98 , L_3 ) ;
V_7 -> V_99 = V_100 ;
if ( V_41 -> V_101 -> V_102 && V_89 > 8 )
V_7 -> V_103 = & V_104 ;
else if ( V_88 ) {
V_7 -> V_103 = & V_105 ;
V_7 -> V_99 |= V_106 ;
} else
V_7 -> V_103 = & V_107 ;
V_7 -> V_32 . V_108 = V_27 -> V_109 . V_110 ;
V_7 -> V_32 . V_111 = V_86 ;
V_7 -> V_32 . V_112 = V_88 ;
V_7 -> V_32 . V_113 = 0 ;
V_7 -> V_114 = V_41 -> V_96 + V_82 -> V_18 ;
V_7 -> V_115 = V_86 ;
if ( V_41 -> V_29 . V_116 ) {
V_7 -> V_117 -> V_118 [ 0 ] . V_28 = V_27 -> V_109 . V_110 ;
V_7 -> V_117 -> V_118 [ 0 ] . V_86 = V_41 -> V_29 . V_116 ;
}
F_32 ( V_7 , & V_9 -> V_13 ,
V_85 -> V_119 , V_85 -> V_120 ) ;
V_7 -> V_32 . V_121 = F_33 ( V_27 -> V_122 , 0 ) ;
V_7 -> V_32 . V_123 = F_34 ( V_27 -> V_122 , 0 ) ;
F_35 ( V_27 -> V_27 , L_4 ,
V_24 -> V_28 . V_90 , V_24 -> V_28 . V_92 ) ;
return 0 ;
V_97:
F_36 ( V_27 , V_82 ) ;
return V_46 ;
}
static struct V_11 * F_37
( struct V_26 * V_27 , struct V_124 * V_125 ,
const struct V_71 * V_126 )
{
struct V_73 * V_127 ;
struct V_128 * V_129 ;
V_129 = F_38 ( V_125 , V_126 -> V_130 [ 0 ] ) ;
if ( V_129 == NULL )
return F_20 ( - V_131 ) ;
V_127 = F_39 ( V_129 , struct V_73 , V_83 ) ;
return F_18 ( V_27 , V_126 , V_127 ) ;
}
static void F_40 ( struct V_132 * V_133 , T_3 V_2 , T_3 V_3 ,
T_3 V_4 , int V_1 )
{
struct V_134 * V_134 = F_41 ( V_133 ) ;
V_134 -> V_135 [ V_1 ] = V_2 >> 8 ;
V_134 -> V_136 [ V_1 ] = V_3 >> 8 ;
V_134 -> V_137 [ V_1 ] = V_4 >> 8 ;
}
static void F_42 ( struct V_132 * V_133 , T_3 * V_2 ,
T_3 * V_3 , T_3 * V_4 , int V_1 )
{
struct V_134 * V_134 = F_41 ( V_133 ) ;
* V_2 = V_134 -> V_135 [ V_1 ] << 8 ;
* V_3 = V_134 -> V_136 [ V_1 ] << 8 ;
* V_4 = V_134 -> V_137 [ V_1 ] << 8 ;
}
static int F_43 ( struct V_138 * V_139 ,
struct V_84 * V_85 )
{
struct V_8 * V_8 =
F_39 ( V_139 , struct V_8 , V_13 ) ;
struct V_26 * V_27 = V_8 -> V_13 . V_27 ;
struct V_40 * V_41 = V_27 -> V_42 ;
int V_140 ;
V_140 = V_85 -> V_94 / 8 ;
if ( V_140 == 3 )
V_140 = 4 ;
if ( F_26 ( V_85 -> V_119 * V_140 , 64 ) * V_85 -> V_120 >
V_41 -> V_141 ) {
V_85 -> V_94 = 16 ;
V_85 -> V_95 = 16 ;
}
return F_25 ( V_8 , V_85 ) ;
}
static int F_44 ( struct V_26 * V_27 , struct V_8 * V_9 )
{
struct V_23 * V_24 = & V_9 -> V_25 ;
F_45 ( & V_9 -> V_13 ) ;
F_46 ( & V_9 -> V_13 ) ;
F_47 ( & V_24 -> V_28 ) ;
F_48 ( & V_24 -> V_28 ) ;
if ( V_24 -> V_29 )
F_49 ( & V_24 -> V_29 -> V_83 ) ;
return 0 ;
}
int F_50 ( struct V_26 * V_27 )
{
struct V_8 * V_9 ;
struct V_40 * V_41 = V_27 -> V_42 ;
int V_46 ;
V_9 = F_19 ( sizeof( struct V_8 ) , V_80 ) ;
if ( ! V_9 ) {
F_17 ( V_27 -> V_27 , L_5 ) ;
return - V_15 ;
}
V_41 -> V_9 = V_9 ;
F_51 ( V_27 , & V_9 -> V_13 , & V_142 ) ;
V_46 = F_52 ( V_27 , & V_9 -> V_13 ,
V_143 ) ;
if ( V_46 )
goto free;
V_46 = F_53 ( & V_9 -> V_13 ) ;
if ( V_46 )
goto V_144;
F_54 ( V_27 ) ;
V_46 = F_55 ( & V_9 -> V_13 , 32 ) ;
if ( V_46 )
goto V_144;
return 0 ;
V_144:
F_46 ( & V_9 -> V_13 ) ;
free:
F_21 ( V_9 ) ;
return V_46 ;
}
static void F_56 ( struct V_26 * V_27 )
{
struct V_40 * V_41 = V_27 -> V_42 ;
if ( ! V_41 -> V_9 )
return;
F_44 ( V_27 , V_41 -> V_9 ) ;
F_21 ( V_41 -> V_9 ) ;
V_41 -> V_9 = NULL ;
}
static void F_57 ( struct V_26 * V_27 )
{
struct V_40 * V_41 = V_27 -> V_42 ;
struct V_8 * V_9 = (struct V_8 * ) V_41 -> V_9 ;
F_58 ( & V_9 -> V_13 ) ;
}
static int F_59 ( struct V_11 * V_12 ,
struct V_124 * V_145 ,
unsigned int * V_146 )
{
struct V_23 * V_24 = F_60 ( V_12 ) ;
struct V_73 * V_127 = V_24 -> V_29 ;
return F_61 ( V_145 , & V_127 -> V_83 , V_146 ) ;
}
static void F_62 ( struct V_11 * V_12 )
{
struct V_23 * V_24 = F_60 ( V_12 ) ;
struct V_73 * V_127 = V_24 -> V_29 ;
F_48 ( V_12 ) ;
F_49 ( & V_127 -> V_83 ) ;
F_21 ( V_12 ) ;
}
static void F_63 ( struct V_26 * V_27 )
{
struct V_40 * V_41 = V_27 -> V_42 ;
struct V_147 * V_148 ;
F_64 ( V_27 ) ;
if ( ! V_41 -> V_149 )
V_41 -> V_149 = F_65 ( V_27 , 0 ,
L_6 , 0 , 100 ) ;
V_41 -> V_101 -> V_150 ( V_27 ) ;
F_66 (connector, &dev->mode_config.connector_list,
head) {
struct V_151 * V_151 = F_67 ( V_148 ) ;
struct V_152 * V_153 = & V_151 -> V_28 ;
int V_154 = 0 , V_155 = 0 ;
switch ( V_151 -> type ) {
case V_156 :
V_154 = ( 1 << 0 ) ;
V_155 = ( 1 << V_156 ) ;
break;
case V_157 :
V_154 = V_41 -> V_101 -> V_158 ;
V_155 = ( 1 << V_157 ) ;
break;
case V_159 :
V_154 = V_41 -> V_101 -> V_160 ;
V_155 = ( 1 << V_159 ) ;
break;
case V_161 :
V_154 = ( 1 << 0 ) ;
V_155 = ( 1 << V_161 ) ;
break;
case V_162 :
V_154 = ( 1 << 2 ) ;
V_155 = ( 1 << V_162 ) ;
break;
case V_163 :
V_154 = V_41 -> V_101 -> V_164 ;
V_155 = ( 1 << V_163 ) ;
break;
case V_165 :
V_154 = ( 1 << 0 ) | ( 1 << 1 ) ;
V_155 = ( 1 << V_165 ) ;
break;
case V_166 :
V_154 = ( 1 << 1 ) ;
V_155 = ( 1 << V_166 ) ;
}
V_153 -> V_167 = V_154 ;
V_153 -> V_168 =
F_68 ( V_27 , V_155 ) ;
}
}
void F_69 ( struct V_26 * V_27 )
{
struct V_40 * V_41 = V_27 -> V_42 ;
struct V_169 * V_170 = & V_41 -> V_170 ;
int V_44 ;
F_70 ( V_27 ) ;
V_27 -> V_109 . V_171 = 0 ;
V_27 -> V_109 . V_172 = 0 ;
V_27 -> V_109 . V_173 = & V_174 ;
F_71 ( V_27 -> V_122 , V_175 , ( T_2 * )
& ( V_27 -> V_109 . V_110 ) ) ;
for ( V_44 = 0 ; V_44 < V_41 -> V_176 ; V_44 ++ )
F_72 ( V_27 , V_44 , V_170 ) ;
V_27 -> V_109 . V_177 = 4096 ;
V_27 -> V_109 . V_178 = 4096 ;
F_63 ( V_27 ) ;
if ( V_41 -> V_101 -> V_179 )
V_41 -> V_101 -> V_179 ( V_27 ) ;
V_41 -> V_180 = true ;
}
void F_73 ( struct V_26 * V_27 )
{
struct V_40 * V_41 = V_27 -> V_42 ;
if ( V_41 -> V_180 ) {
F_74 ( V_27 ) ;
F_56 ( V_27 ) ;
F_75 ( V_27 ) ;
}
}
