static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 ,
T_1 V_5 , T_1 V_6 ,
T_2 V_7 , void * V_8 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
V_10 -> type = V_12 ;
V_10 -> V_3 = V_3 ;
V_10 -> V_4 = V_4 ;
V_10 -> V_5 = V_5 ;
V_10 -> V_6 = V_6 ;
if ( V_7 > V_13 - sizeof( * V_10 ) ) {
F_2 ( & V_2 -> V_14 -> V_15 , L_1 , V_7 ) ;
return - V_16 ;
}
V_10 -> V_7 = V_7 ;
memcpy ( V_10 -> V_17 , V_8 , V_7 ) ;
F_3 ( L_2 , V_18 ,
V_10 , V_7 + sizeof( * V_10 ) ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_1 V_5 , T_1 V_6 ,
void * V_8 , T_2 V_7 )
{
int V_19 = 0 ;
V_19 = F_1 ( V_2 , V_3 ,
V_4 , V_5 , V_6 , V_7 , V_8 ) ;
if ( V_19 < 0 )
return V_19 ;
return V_20 -> V_21 -> V_22 ( V_20 -> V_15 , V_2 -> V_11 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_1 V_5 , T_1 V_6 ,
void * V_8 , T_2 V_7 )
{
int V_19 ;
F_6 ( & V_2 -> V_23 ) ;
V_19 = F_4 ( V_2 , V_3 , V_4 ,
V_5 , V_6 , V_8 , V_7 ) ;
F_7 ( & V_2 -> V_23 ) ;
return V_19 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_24 V_25 ;
F_9 ( V_25 . V_26 . V_27 ) ;
V_25 . V_26 . V_28 = V_29 ;
V_25 . V_26 . V_30 = sizeof( struct V_24 )
- sizeof( struct V_31 ) ;
V_25 . V_32 = V_29 ;
V_25 . V_33 = sizeof( V_25 . V_34 ) + sizeof( V_25 . V_35 )
+ sizeof( V_25 . V_36 ) ;
V_25 . V_36 = V_37 ;
memcpy ( V_25 . V_34 , & V_38 [ 0 ] , sizeof( V_25 . V_34 ) ) ;
memcpy ( V_25 . V_35 , & V_39 [ 0 ] , sizeof( V_25 . V_35 ) ) ;
return F_4 ( V_2 , V_40 ,
V_41 , V_42 , 0 , & V_25 ,
sizeof( V_25 . V_26 ) + V_25 . V_26 . V_30 ) ;
}
int F_10 ( struct V_43 * V_44 ,
struct V_45 * V_46 )
{
struct V_47 * V_48 = (struct V_47 * ) V_44 -> V_49 ;
V_46 -> type = V_50 ;
V_46 -> V_51 = 1 ;
V_46 -> V_52 . V_53 . V_54 = V_48 -> V_55 ;
if ( V_46 -> V_52 . V_53 . V_56 > V_48 -> V_55 - 1 )
V_46 -> V_52 . V_53 . V_56 = V_48 -> V_55 - 1 ;
strcpy ( V_46 -> V_52 . V_53 . V_57 ,
V_48 -> V_58 [ V_46 -> V_52 . V_53 . V_56 ] ) ;
return 0 ;
}
static int F_11 ( struct V_43 * V_44 ,
struct V_59 * V_60 )
{
struct V_47 * V_48 = ( void * ) V_44 -> V_49 ;
struct V_61 * V_62 = F_12 ( V_44 ) ;
struct V_1 * V_2 = F_13 ( V_62 ) ;
unsigned int V_63 = V_48 -> V_64 ;
unsigned int V_65 = V_48 -> V_66 ;
unsigned int V_67 , V_68 ;
T_1 * V_69 = V_65 ? V_39 : V_38 ;
F_6 ( & V_2 -> V_23 ) ;
V_67 = 1 << V_63 ;
for ( V_68 = V_48 -> V_55 ; V_68 > 0 ; V_68 -- )
if ( V_69 [ V_68 - 1 ] & V_67 )
break;
V_60 -> V_52 . V_53 . V_56 [ 0 ] = V_68 ;
F_7 ( & V_2 -> V_23 ) ;
F_14 ( V_62 -> V_15 , L_3 ,
V_65 ? L_4 : L_5 ,
V_48 -> V_58 [ V_68 ] , V_68 ? V_69 [ V_68 - 1 ] : - 1 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
struct V_47 * V_48 = ( void * ) V_44 -> V_49 ;
int V_19 = 0 ;
if ( V_48 -> V_70 && V_48 -> V_70 -> V_71 )
V_19 = F_8 ( V_2 ) ;
else
F_2 ( & V_2 -> V_14 -> V_15 , L_6 ,
V_44 -> V_72 . V_57 ) ;
return V_19 ;
}
static int F_16 ( struct V_43 * V_44 ,
struct V_59 * V_60 )
{
struct V_61 * V_62 = F_17 ( V_44 ) ;
struct V_1 * V_2 = F_13 ( V_62 ) ;
struct V_47 * V_48 = ( void * ) V_44 -> V_49 ;
int V_73 , V_19 = 0 ;
unsigned int V_63 = V_48 -> V_64 ;
unsigned int V_65 = V_48 -> V_66 ;
unsigned int V_74 ;
unsigned int V_67 , V_68 ;
T_1 * V_69 ;
V_69 = V_65 ? V_39 : V_38 ;
V_67 = 1 << V_63 ;
V_68 = V_60 -> V_52 . V_53 . V_56 [ 0 ] ;
if ( V_68 > V_48 -> V_55 - 1 )
return - V_16 ;
F_6 ( & V_2 -> V_23 ) ;
for ( V_73 = 0 ; V_73 < V_48 -> V_55 ; V_73 ++ )
V_69 [ V_73 ] &= ~ V_67 ;
if ( V_68 == 0 ) {
V_19 = F_15 ( V_2 , V_44 ) ;
F_7 ( & V_2 -> V_23 ) ;
return V_19 ;
}
V_74 = V_68 - 1 ;
V_69 [ V_74 ] |= V_67 ;
F_14 ( V_62 -> V_15 , L_7 ,
V_65 ? L_4 : L_5 ,
V_48 -> V_58 [ V_68 ] , V_69 [ V_74 ] ) ;
V_19 = F_15 ( V_2 , V_44 ) ;
F_7 ( & V_2 -> V_23 ) ;
return V_19 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_75 * V_76 )
{
int V_7 , V_19 = 0 ;
struct V_77 * V_25 ;
V_7 = sizeof( V_25 -> V_27 ) + sizeof( V_25 -> V_28 ) + V_76 -> V_55 ;
V_25 = F_19 ( V_7 , V_78 ) ;
if ( V_25 == NULL )
return - V_79 ;
F_20 ( 2 , V_25 -> V_27 , V_76 -> V_6 , V_76 -> V_80 ) ;
V_25 -> V_28 = V_76 -> V_81 ;
memcpy ( V_25 -> V_82 , V_76 -> V_82 , V_76 -> V_55 ) ;
V_19 = F_4 ( V_2 , V_40 ,
V_41 , V_76 -> V_5 , 0 , V_25 , V_7 ) ;
F_21 ( V_25 ) ;
return V_19 ;
}
static int F_22 ( struct V_1 * V_2 ,
const char * V_83 , struct V_84 * V_85 )
{
int V_19 = 0 ;
struct V_75 * V_76 ;
struct V_86 * V_87 = NULL ;
F_14 ( & V_2 -> V_14 -> V_15 , L_8 , V_83 ) ;
F_23 (algo, &ids->algo_list, node) {
V_76 = ( void * ) V_87 -> V_88 -> V_49 ;
F_14 ( & V_2 -> V_14 -> V_15 , L_9 ,
V_87 -> V_88 -> V_72 . V_57 , V_83 ) ;
V_19 = F_18 ( V_2 , V_76 ) ;
if ( V_19 )
return V_19 ;
}
return V_19 ;
}
static int F_24 ( struct V_43 * V_44 ,
struct V_45 * V_46 )
{
struct V_75 * V_76 = ( void * ) V_44 -> V_49 ;
V_46 -> type = V_89 ;
V_46 -> V_51 = V_76 -> V_55 ;
return 0 ;
}
static int F_25 ( struct V_43 * V_44 ,
struct V_59 * V_60 )
{
struct V_75 * V_76 = ( void * ) V_44 -> V_49 ;
struct V_61 * V_90 = F_12 ( V_44 ) ;
switch ( V_76 -> type ) {
case V_91 :
memcpy ( V_60 -> V_52 . V_17 . V_92 , V_76 -> V_82 , V_76 -> V_55 ) ;
break;
default:
F_2 ( V_90 -> V_15 , L_10 ,
V_76 -> type ) ;
return - V_16 ;
}
return 0 ;
}
static int F_26 ( struct V_43 * V_44 ,
struct V_59 * V_60 )
{
int V_19 = 0 ;
struct V_61 * V_93 = F_17 ( V_44 ) ;
struct V_1 * V_2 = F_13 ( V_93 ) ;
struct V_75 * V_76 = ( void * ) V_44 -> V_49 ;
F_14 ( V_93 -> V_15 , L_11 , V_44 -> V_72 . V_57 ) ;
F_6 ( & V_2 -> V_23 ) ;
switch ( V_76 -> type ) {
case V_91 :
memcpy ( V_76 -> V_82 , V_60 -> V_52 . V_17 . V_92 , V_76 -> V_55 ) ;
break;
default:
F_7 ( & V_2 -> V_23 ) ;
F_2 ( V_93 -> V_15 , L_10 ,
V_76 -> type ) ;
return - V_16 ;
}
if ( V_76 -> V_70 && V_76 -> V_70 -> V_71 )
V_19 = F_18 ( V_2 , V_76 ) ;
F_7 ( & V_2 -> V_23 ) ;
return V_19 ;
}
static int F_27 ( struct V_43 * V_44 ,
struct V_45 * V_46 )
{
struct V_94 * V_95 = ( void * ) V_44 -> V_49 ;
V_46 -> type = V_96 ;
V_46 -> V_51 = V_95 -> V_97 ? 2 : 1 ;
V_46 -> V_52 . integer . V_98 = V_95 -> V_98 ;
V_46 -> V_52 . integer . V_55 = V_95 -> V_55 ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , struct V_99 * V_100 ,
T_2 V_5 , T_2 V_101 , T_2 V_80 , int V_102 )
{
struct V_103 V_25 ;
F_14 ( & V_2 -> V_14 -> V_15 , L_12 ) ;
V_25 . V_26 . V_28 = V_104 ;
F_9 ( V_25 . V_26 . V_27 ) ;
V_25 . V_105 = 1 ;
if ( V_102 || V_100 -> V_102 ) {
V_25 . V_106 [ 0 ] . V_107 = V_108 ;
V_25 . V_106 [ 0 ] . V_109 = V_108 ;
} else {
V_25 . V_106 [ 0 ] . V_107 = V_100 -> V_110 ;
V_25 . V_106 [ 0 ] . V_109 = V_100 -> V_111 ;
}
F_20 ( 2 , V_25 . V_106 [ 0 ] . V_112 ,
V_101 , V_80 ) ;
V_25 . V_106 [ 0 ] . V_113 = V_100 -> V_114 ;
V_25 . V_26 . V_30 = sizeof( struct V_103 )
- sizeof( struct V_31 ) ;
return F_4 ( V_2 , V_40 ,
V_41 , V_5 , 0 , & V_25 ,
sizeof( V_25 . V_26 ) + V_25 . V_26 . V_30 ) ;
}
static int F_29 ( struct V_43 * V_44 ,
struct V_59 * V_60 )
{
struct V_61 * V_90 = F_12 ( V_44 ) ;
struct V_94 * V_95 = ( void * ) V_44 -> V_49 ;
struct V_99 * V_100 = V_95 -> V_115 ;
switch ( V_95 -> type ) {
case V_116 :
V_60 -> V_52 . integer . V_52 [ 0 ] = V_100 -> V_110 ;
V_60 -> V_52 . integer . V_52 [ 1 ] = V_100 -> V_111 ;
break;
case V_117 :
V_60 -> V_52 . integer . V_52 [ 0 ] = V_100 -> V_102 ? 1 : 0 ;
break;
case V_118 :
V_60 -> V_52 . integer . V_52 [ 0 ] = V_100 -> V_114 ;
break;
default:
F_2 ( V_90 -> V_15 , L_13 ,
V_95 -> type ) ;
return - V_16 ;
}
return 0 ;
}
static int F_30 ( struct V_43 * V_44 ,
struct V_59 * V_60 )
{
int V_19 = 0 ;
struct V_61 * V_93 = F_17 ( V_44 ) ;
struct V_1 * V_2 = F_13 ( V_93 ) ;
struct V_94 * V_95 = ( void * ) V_44 -> V_49 ;
struct V_99 * V_100 = V_95 -> V_115 ;
F_6 ( & V_2 -> V_23 ) ;
switch ( V_95 -> type ) {
case V_116 :
V_100 -> V_110 = V_60 -> V_52 . integer . V_52 [ 0 ] ;
V_100 -> V_111 = V_60 -> V_52 . integer . V_52 [ 1 ] ;
F_14 ( V_93 -> V_15 , L_14 ,
V_95 -> V_119 , V_100 -> V_110 , V_100 -> V_111 ) ;
break;
case V_117 :
V_100 -> V_102 = ! ! V_60 -> V_52 . integer . V_52 [ 0 ] ;
F_14 ( V_93 -> V_15 , L_15 , V_95 -> V_119 , V_100 -> V_102 ) ;
break;
case V_118 :
V_100 -> V_114 = V_60 -> V_52 . integer . V_52 [ 0 ] ;
F_14 ( V_93 -> V_15 , L_16 ,
V_95 -> V_119 , V_100 -> V_114 ) ;
break;
default:
F_7 ( & V_2 -> V_23 ) ;
F_2 ( V_93 -> V_15 , L_13 ,
V_95 -> type ) ;
return - V_16 ;
}
if ( V_95 -> V_70 && V_95 -> V_70 -> V_71 )
V_19 = F_28 ( V_2 , V_100 , V_95 -> V_5 ,
V_95 -> V_6 | V_95 -> V_120 , V_95 -> V_80 , 0 ) ;
F_7 ( & V_2 -> V_23 ) ;
return V_19 ;
}
static int F_31 ( struct V_121 * V_70 ,
struct V_43 * V_44 )
{
struct V_61 * V_62 = F_32 ( V_70 -> V_122 ) ;
struct V_1 * V_2 = F_13 ( V_62 ) ;
struct V_84 * V_85 = V_70 -> V_123 ;
F_6 ( & V_2 -> V_23 ) ;
F_22 ( V_2 , V_70 -> V_57 , V_85 ) ;
F_33 ( V_85 , V_2 , 0 ) ;
F_7 ( & V_2 -> V_23 ) ;
return 0 ;
}
static int F_34 ( struct V_121 * V_70 ,
struct V_43 * V_124 , int V_125 )
{
if ( F_35 ( V_125 ) )
return F_31 ( V_70 , V_124 ) ;
return 0 ;
}
static int F_36 ( struct V_61 * V_93 ,
struct V_126 * V_127 , unsigned int V_64 )
{
T_3 V_73 , V_128 , V_129 = 0 ;
T_2 V_130 ;
F_14 ( V_93 -> V_15 , L_17 , V_64 ) ;
for ( V_73 = 0 ; V_73 < V_131 ; V_73 ++ ) {
V_128 = V_64 & F_37 ( V_73 ) ;
if ( ! V_128 )
continue;
V_130 = V_132 [ V_73 ] ;
F_20 ( 2 , V_127 -> V_133 ,
V_130 , V_134 ) ;
V_129 ++ ;
V_127 ++ ;
F_14 ( V_93 -> V_15 , L_18 ,
V_130 , V_129 ) ;
if ( V_129 == V_135 ) {
F_38 ( V_93 -> V_15 , L_19 ) ;
break;
}
}
return V_129 ;
}
static int F_33 ( struct V_84 * V_85 ,
struct V_1 * V_2 , int V_102 )
{
int V_19 = 0 ;
struct V_94 * V_95 ;
struct V_99 * V_100 ;
struct V_86 * V_136 = NULL ;
F_23 (gain, &ids->gain_list, node) {
struct V_43 * V_88 = V_136 -> V_88 ;
F_14 ( & V_2 -> V_14 -> V_15 , L_20 , V_88 -> V_72 . V_57 ) ;
V_95 = ( void * ) V_88 -> V_49 ;
V_100 = V_95 -> V_115 ;
V_19 = F_28 ( V_2 , V_100 , V_95 -> V_5 ,
V_95 -> V_6 | V_95 -> V_120 , V_95 -> V_80 , V_102 ) ;
if ( V_19 )
return V_19 ;
}
return V_19 ;
}
static int F_39 ( struct V_121 * V_70 ,
struct V_43 * V_124 , int V_125 )
{
struct V_137 V_25 ;
struct V_61 * V_93 = F_32 ( V_70 -> V_122 ) ;
struct V_1 * V_2 = F_13 ( V_93 ) ;
struct V_84 * V_85 = V_70 -> V_123 ;
bool V_138 = false ;
struct V_139 * V_95 ;
int V_67 = 0 ;
int V_73 = 0 ;
F_14 ( V_93 -> V_15 , L_21 , V_70 -> V_57 ) ;
for ( V_73 = 0 ; V_73 < V_70 -> V_140 ; V_73 ++ ) {
if ( F_40 ( V_70 -> V_141 [ V_73 ] ) ) {
V_95 = (struct V_139 * ) ( V_70 -> V_141 [ V_73 ] ) -> V_49 ;
V_67 |= 1 << V_95 -> V_142 ;
}
}
F_14 ( V_93 -> V_15 , L_22 , V_67 ) ;
switch ( V_125 ) {
case V_143 :
case V_144 :
V_138 = true ;
break;
case V_145 :
if ( V_70 -> V_71 )
V_138 = true ;
break;
default:
V_138 = false ;
}
if ( V_138 == false )
return 0 ;
if ( F_35 ( V_125 ) ||
V_125 == V_145 )
V_25 . V_146 = V_147 ;
else
V_25 . V_146 = V_148 ;
F_9 ( V_25 . V_26 . V_27 ) ;
V_25 . V_26 . V_28 = V_149 ;
F_20 ( 2 , V_25 . V_150 ,
V_85 -> V_151 , V_134 ) ;
V_25 . V_129 = F_36 ( V_93 , & V_25 . V_152 [ 0 ] , V_67 ) ;
V_25 . V_26 . V_30 = F_41 ( struct V_137 , V_152 )
- sizeof( struct V_31 )
+ ( V_25 . V_129 * sizeof( V_25 . V_152 [ 0 ] ) ) ;
return F_5 ( V_2 , V_153 , V_41 ,
V_85 -> V_5 , 0 , & V_25 ,
sizeof( V_25 . V_26 ) + V_25 . V_26 . V_30 ) ;
}
int F_42 ( struct V_154 * V_155 , bool V_156 )
{
int V_19 = 0 ;
struct V_157 V_25 ;
struct V_1 * V_2 = F_43 ( V_155 ) ;
static int V_158 ;
if ( V_156 )
V_25 . V_26 . V_28 = V_159 ;
else
V_25 . V_26 . V_28 = V_160 ;
F_14 ( V_155 -> V_15 , L_23 , V_156 , V_158 ) ;
F_9 ( V_25 . V_26 . V_27 ) ;
V_25 . V_26 . V_30 = 0 ;
if ( V_156 ) {
V_19 = V_20 -> V_21 -> V_71 ( V_20 -> V_15 , true ) ;
if ( V_19 < 0 )
return V_19 ;
}
F_6 ( & V_2 -> V_23 ) ;
if ( V_156 )
V_158 ++ ;
else
V_158 -- ;
if ( ( V_156 && ( V_158 == 1 ) ) ||
( ! V_156 && ( V_158 == 0 ) ) ) {
V_19 = F_4 ( V_2 , V_153 ,
V_41 , V_42 , 0 , & V_25 ,
sizeof( V_25 . V_26 ) + V_25 . V_26 . V_30 ) ;
if ( V_19 && V_156 ) {
V_158 -- ;
V_156 = false ;
}
}
F_7 ( & V_2 -> V_23 ) ;
if ( ! V_156 )
V_20 -> V_21 -> V_71 ( V_20 -> V_15 , false ) ;
return V_19 ;
}
int F_44 ( struct V_154 * V_155 , const char * V_72 , bool V_156 )
{
struct V_161 V_25 ;
struct V_1 * V_2 = F_43 ( V_155 ) ;
const struct V_162 * V_163 ;
F_45 ( V_155 -> V_15 , L_24 , V_156 , V_72 ) ;
F_9 ( V_25 . V_26 . V_27 ) ;
V_25 . V_26 . V_28 = V_164 ;
V_25 . V_26 . V_30 = sizeof( struct V_161 )
- sizeof( struct V_31 ) ;
V_163 = & V_165 ;
F_14 ( V_155 -> V_15 , L_25 , V_163 -> V_166 ) ;
if ( V_156 )
V_25 . V_146 = V_167 ;
else
V_25 . V_146 = V_168 ;
V_25 . V_169 = V_163 -> V_166 ;
V_25 . V_170 = V_163 -> V_171 ;
V_25 . V_172 = V_163 -> V_173 ;
V_25 . V_174 = V_163 -> V_175 | ( V_163 -> V_176 << 1 ) ;
V_25 . V_177 = V_163 -> V_177 ;
V_25 . V_178 = V_163 -> V_179 ;
V_25 . V_180 = V_163 -> V_179 ;
V_25 . V_181 = V_163 -> V_182 ;
V_25 . V_183 = V_184 ;
V_25 . V_185 = 1 ;
V_25 . V_186 = V_163 -> V_187 ;
V_25 . V_188 = V_163 -> V_188 ;
V_25 . V_189 = V_163 -> V_189 ;
V_25 . V_190 = V_25 . V_191 = 0xFF ;
return F_5 ( V_2 , V_153 , V_41 ,
V_42 , 0 , & V_25 ,
sizeof( V_25 . V_26 ) + V_25 . V_26 . V_30 ) ;
}
static int F_46 ( struct V_121 * V_70 ,
struct V_43 * V_124 , int V_125 )
{
int V_19 = 0 ;
struct V_61 * V_62 = F_32 ( V_70 -> V_122 ) ;
struct V_1 * V_2 = F_13 ( V_62 ) ;
F_14 ( V_62 -> V_15 , L_8 , V_70 -> V_57 ) ;
if ( F_35 ( V_125 ) ) {
V_19 = F_8 ( V_2 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_31 ( V_70 , V_124 ) ;
}
return V_19 ;
}
static int F_47 ( struct V_121 * V_70 ,
struct V_43 * V_124 , int V_125 )
{
int V_19 = 0 ;
struct V_192 V_25 ;
struct V_61 * V_62 = F_32 ( V_70 -> V_122 ) ;
struct V_1 * V_2 = F_13 ( V_62 ) ;
struct V_84 * V_85 = V_70 -> V_123 ;
F_14 ( V_62 -> V_15 , L_26 , V_70 -> V_57 ) ;
F_14 ( V_62 -> V_15 , L_27 ,
V_85 -> V_5 , V_85 -> V_151 ) ;
if ( F_35 ( V_125 ) )
V_25 . V_146 = V_193 ;
else
V_25 . V_146 = V_194 ;
F_20 ( 2 , V_25 . V_26 . V_27 ,
V_85 -> V_151 , V_134 ) ;
V_25 . V_26 . V_28 = V_195 ;
V_25 . V_26 . V_30 = sizeof( struct V_192 )
- sizeof( struct V_31 ) ;
V_19 = F_5 ( V_2 , V_153 , V_41 ,
V_85 -> V_5 , 0 , & V_25 ,
sizeof( V_25 . V_26 ) + V_25 . V_26 . V_30 ) ;
if ( V_19 )
return V_19 ;
if ( F_35 ( V_125 ) )
V_19 = F_31 ( V_70 , V_124 ) ;
return V_19 ;
}
static int F_48 ( struct V_121 * V_70 ,
struct V_43 * V_124 , int V_125 )
{
int V_19 = 0 ;
struct V_196 V_25 ;
struct V_61 * V_62 = F_32 ( V_70 -> V_122 ) ;
struct V_1 * V_2 = F_13 ( V_62 ) ;
struct V_84 * V_85 = V_70 -> V_123 ;
F_14 ( V_62 -> V_15 , L_28 , V_70 -> V_57 ) ;
if ( F_35 ( V_125 ) )
V_25 . V_146 = V_167 ;
else
V_25 . V_146 = V_168 ;
F_20 ( 2 , V_25 . V_26 . V_27 ,
V_85 -> V_151 , V_134 ) ;
V_25 . V_26 . V_28 = V_197 ;
V_25 . V_26 . V_30 = sizeof( struct V_196 )
- sizeof( struct V_31 ) ;
V_25 . V_198 . V_199 . V_200 . V_201 = 2 ;
V_25 . V_198 . V_199 . V_200 . V_202 = V_85 -> V_202 ;
V_25 . V_198 . V_199 . V_200 . V_203 = 1 ;
V_25 . V_69 = 0 ;
V_19 = F_5 ( V_2 , V_153 , V_41 ,
V_42 , 0 , & V_25 ,
sizeof( V_25 . V_26 ) + V_25 . V_26 . V_30 ) ;
if ( V_19 )
return V_19 ;
if ( F_35 ( V_125 ) )
V_19 = F_31 ( V_70 , V_124 ) ;
return V_19 ;
}
static int F_49 ( struct V_204 * V_15 )
{
int V_73 = 0 ;
struct V_75 * V_76 ;
for ( V_73 = 0 ; V_73 < F_50 ( V_205 ) ; V_73 ++ ) {
V_76 = (struct V_75 * ) V_205 [ V_73 ] . V_49 ;
V_76 -> V_82 = F_51 ( V_15 , V_76 -> V_55 , V_78 ) ;
if ( V_76 -> V_82 == NULL )
return - V_79 ;
}
return 0 ;
}
static bool F_52 ( struct V_121 * V_70 )
{
switch ( V_70 -> V_72 ) {
case V_206 :
case V_207 :
case V_208 :
case V_209 :
case V_210 :
case V_211 :
return true ;
default:
return false ;
}
}
int F_53 ( struct V_154 * V_155 , int V_212 , int V_102 )
{
struct V_1 * V_2 = F_43 ( V_155 ) ;
struct V_121 * V_70 ;
struct V_213 * V_214 = NULL ;
F_14 ( V_155 -> V_15 , L_29 , V_155 -> V_57 , V_212 ) ;
if ( V_212 == V_215 ) {
F_14 ( V_155 -> V_15 , L_30 ,
V_155 -> V_216 -> V_57 ) ;
V_70 = V_155 -> V_216 ;
F_23 (p, &w->sinks, list_source) {
if ( V_214 -> V_217 && ! V_214 -> V_217 ( V_70 , V_214 -> V_218 ) )
continue;
if ( V_214 -> V_219 && V_214 -> V_218 -> V_71 &&
F_52 ( V_214 -> V_218 ) ) {
struct V_84 * V_85 = V_214 -> V_218 -> V_123 ;
F_14 ( V_155 -> V_15 , L_31 ,
V_214 -> V_218 -> V_57 ) ;
F_6 ( & V_2 -> V_23 ) ;
F_33 ( V_85 , V_2 , V_102 ) ;
F_7 ( & V_2 -> V_23 ) ;
}
}
} else {
F_14 ( V_155 -> V_15 , L_30 ,
V_155 -> V_220 -> V_57 ) ;
V_70 = V_155 -> V_220 ;
F_23 (p, &w->sources, list_sink) {
if ( V_214 -> V_217 && ! V_214 -> V_217 ( V_70 , V_214 -> V_218 ) )
continue;
if ( V_214 -> V_219 && V_214 -> V_221 -> V_71 &&
F_52 ( V_214 -> V_221 ) ) {
struct V_84 * V_85 = V_214 -> V_221 -> V_123 ;
F_14 ( V_155 -> V_15 , L_32 ,
V_214 -> V_221 -> V_57 ) ;
F_6 ( & V_2 -> V_23 ) ;
F_33 ( V_85 , V_2 , V_102 ) ;
F_7 ( & V_2 -> V_23 ) ;
}
}
}
return 0 ;
}
static int F_54 ( struct V_43 * V_88 ,
struct V_121 * V_70 , int type )
{
struct V_86 * V_222 = NULL ;
struct V_61 * V_62 = F_32 ( V_70 -> V_122 ) ;
struct V_84 * V_85 = V_70 -> V_123 ;
int V_19 = 0 ;
V_222 = F_51 ( V_62 -> V_15 , sizeof( * V_222 ) , V_78 ) ;
if ( ! V_222 )
return - V_79 ;
if ( type == V_223 ) {
struct V_94 * V_95 = ( void * ) V_88 -> V_49 ;
V_95 -> V_70 = V_70 ;
V_222 -> V_88 = V_88 ;
F_55 ( & V_222 -> V_224 , & V_85 -> V_225 ) ;
} else if ( type == V_226 ) {
struct V_75 * V_76 = ( void * ) V_88 -> V_49 ;
V_76 -> V_70 = V_70 ;
V_222 -> V_88 = V_88 ;
F_55 ( & V_222 -> V_224 , & V_85 -> V_227 ) ;
} else {
F_2 ( V_62 -> V_15 , L_33 ,
type , V_88 -> V_72 . V_57 ) ;
V_19 = - V_16 ;
}
return V_19 ;
}
static int F_56 ( struct V_121 * V_70 ,
struct V_228 * V_229 )
{
struct V_43 * V_88 ;
int V_230 , V_19 = 0 ;
struct V_231 * V_232 = V_229 -> V_90 . V_232 -> V_231 ;
char * V_233 ;
F_57 ( & V_232 -> V_234 ) ;
F_23 (kctl, &card->controls, list) {
V_233 = strstr ( V_88 -> V_72 . V_57 , L_34 ) ;
if ( V_233 == NULL )
continue;
V_230 = strlen ( V_88 -> V_72 . V_57 ) - strlen ( V_233 ) ;
if ( strstr ( V_88 -> V_72 . V_57 , L_35 ) &&
! strncmp ( V_88 -> V_72 . V_57 , V_70 -> V_57 , V_230 ) )
V_19 = F_54 ( V_88 , V_70 , V_223 ) ;
else if ( strstr ( V_88 -> V_72 . V_57 , L_36 ) &&
! strncmp ( V_88 -> V_72 . V_57 , V_70 -> V_57 , V_230 ) )
V_19 = F_54 ( V_88 , V_70 , V_226 ) ;
else if ( strstr ( V_88 -> V_72 . V_57 , L_37 ) &&
! strncmp ( V_88 -> V_72 . V_57 , V_70 -> V_57 , V_230 ) &&
strstr ( V_88 -> V_72 . V_57 , L_38 ) ) {
struct V_94 * V_95 =
( void * ) V_88 -> V_49 ;
V_95 -> V_70 = V_70 ;
} else if ( strstr ( V_88 -> V_72 . V_57 , L_39 ) &&
! strncmp ( V_88 -> V_72 . V_57 , V_70 -> V_57 , V_230 ) ) {
struct V_47 * V_48 = ( void * ) V_88 -> V_49 ;
V_48 -> V_70 = V_70 ;
} else if ( strstr ( V_88 -> V_72 . V_57 , L_40 ) &&
! strncmp ( V_88 -> V_72 . V_57 , V_70 -> V_57 , V_230 ) ) {
struct V_47 * V_48 = ( void * ) V_88 -> V_49 ;
V_48 -> V_70 = V_70 ;
}
if ( V_19 < 0 ) {
F_58 ( & V_232 -> V_234 ) ;
return V_19 ;
}
}
F_58 ( & V_232 -> V_234 ) ;
return 0 ;
}
static void F_59 ( struct V_228 * V_229 ,
struct V_84 * V_85 )
{
struct V_121 * V_70 ;
unsigned int V_7 = strlen ( V_85 -> V_235 ) ;
F_23 (w, &platform->component.card->widgets, list) {
if ( ! strncmp ( V_85 -> V_235 , V_70 -> V_57 , V_7 ) ) {
V_85 -> V_236 = V_70 ;
break;
}
}
}
static int F_60 ( struct V_228 * V_229 )
{
struct V_121 * V_70 ;
int V_19 = 0 ;
F_23 (w, &platform->component.card->widgets, list) {
if ( F_52 ( V_70 ) && ( V_70 -> V_123 ) ) {
struct V_84 * V_85 = V_70 -> V_123 ;
F_14 ( V_229 -> V_15 , L_41 ,
V_70 -> V_72 , V_70 -> V_57 ) ;
F_61 ( & V_85 -> V_227 ) ;
F_61 ( & V_85 -> V_225 ) ;
V_19 = F_56 ( V_70 , V_229 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_85 -> V_235 != NULL )
F_59 ( V_229 , V_85 ) ;
}
}
return 0 ;
}
int F_62 ( struct V_228 * V_229 )
{
int V_73 , V_19 = 0 ;
struct V_237 * V_122 =
F_63 ( & V_229 -> V_90 ) ;
struct V_1 * V_2 = F_64 ( V_229 ) ;
unsigned int V_238 = F_50 ( V_239 ) / 3 ;
V_2 -> V_11 = F_51 ( V_229 -> V_15 ,
V_13 , V_78 ) ;
if ( ! V_2 -> V_11 )
return - V_79 ;
F_65 ( V_122 , V_240 ,
F_50 ( V_240 ) ) ;
F_66 ( V_122 , V_241 ,
F_50 ( V_241 ) ) ;
F_67 ( V_122 -> V_232 ) ;
for ( V_73 = 0 ; V_73 < V_238 ; V_73 ++ ) {
V_242 [ V_73 ] . V_102 = V_243 ;
V_242 [ V_73 ] . V_110 = V_244 ;
V_242 [ V_73 ] . V_111 = V_244 ;
V_242 [ V_73 ] . V_114 = V_245 ;
}
V_19 = F_68 ( V_229 , V_239 ,
F_50 ( V_239 ) ) ;
if ( V_19 )
return V_19 ;
V_19 = F_49 ( V_229 -> V_15 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_68 ( V_229 , V_205 ,
F_50 ( V_205 ) ) ;
if ( V_19 )
return V_19 ;
V_19 = F_68 ( V_229 , V_246 ,
F_50 ( V_246 ) ) ;
if ( V_19 )
return V_19 ;
V_19 = F_60 ( V_229 ) ;
return V_19 ;
}
