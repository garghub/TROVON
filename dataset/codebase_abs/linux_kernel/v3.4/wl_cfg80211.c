static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
V_2 -> V_4 = V_3 ;
}
static void * F_2 ( struct V_1 * V_2 )
{
void * V_3 = NULL ;
if ( V_2 )
V_3 = V_2 -> V_4 ;
return V_3 ;
}
static
struct V_5 * F_3 ( struct V_1 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_6 ) ;
return V_8 -> V_9 ;
}
static bool F_4 ( struct V_10 * V_10 )
{
struct V_5 * V_9 = F_5 ( V_10 ) ;
if ( ! F_6 ( V_11 , & V_9 -> V_12 ) ) {
F_7 ( L_1 ,
( int ) V_9 -> V_12 ) ;
return false ;
}
return true ;
}
static T_1 F_8 ( T_2 V_13 )
{
T_3 V_14 = 1 ;
int V_15 = V_13 - V_16 ;
if ( V_15 >= V_17 )
return 0xFFFF ;
while ( V_15 < 0 ) {
V_15 += 40 ;
V_14 *= 10 ;
}
return ( V_18 [ V_15 ] + V_14 / 2 ) / V_14 ;
}
static T_2 F_9 ( T_1 V_19 )
{
T_2 V_13 ;
int V_20 ;
T_3 V_21 = V_19 ;
T_3 V_22 ;
if ( V_21 <= 1 )
return 0 ;
V_20 = V_16 ;
while ( V_21 < V_23 ) {
V_21 *= 10 ;
V_20 -= 40 ;
}
for ( V_13 = 0 ; V_13 < V_17 - 1 ; V_13 ++ ) {
V_22 = V_18 [ V_13 ] + ( V_18 [ V_13 + 1 ] -
V_18 [ V_13 ] ) / 2 ;
if ( V_21 < V_22 )
break;
}
V_13 += ( T_2 ) V_20 ;
return V_13 ;
}
static int
F_10 ( struct V_24 * V_25 , T_4 V_26 , T_4 * V_27 )
{
int V_28 ;
T_5 V_29 = F_11 ( * V_27 ) ;
V_28 = F_12 ( V_25 , V_26 , & V_29 , sizeof( T_5 ) ) ;
* V_27 = F_13 ( V_29 ) ;
return V_28 ;
}
static void F_14 ( struct V_30 * V_31 ,
struct V_32 * V_33 )
{
V_33 -> V_34 = F_11 ( V_31 -> V_34 ) ;
V_33 -> V_35 = F_11 ( V_31 -> V_35 ) ;
V_33 -> V_36 = F_11 ( V_31 -> V_36 ) ;
V_33 -> V_37 = F_11 ( V_31 -> V_37 ) ;
V_33 -> V_38 . V_39 = F_11 ( V_31 -> V_38 . V_39 ) ;
V_33 -> V_38 . V_40 = F_15 ( V_31 -> V_38 . V_40 ) ;
V_33 -> V_41 = F_11 ( V_31 -> V_41 ) ;
memcpy ( V_33 -> V_3 , V_31 -> V_3 , sizeof( V_31 -> V_3 ) ) ;
memcpy ( V_33 -> V_42 , V_31 -> V_42 , sizeof( V_31 -> V_42 ) ) ;
}
static int F_16 ( struct V_24 * V_25 ,
struct V_30 * V_31 )
{
int V_28 ;
struct V_32 V_33 ;
F_14 ( V_31 , & V_33 ) ;
V_28 = F_12 ( V_25 , V_43 , & V_33 , sizeof( V_33 ) ) ;
if ( V_28 )
F_17 ( L_2 , V_28 ) ;
return V_28 ;
}
static T_6
F_18 ( struct V_10 * V_10 , struct V_24 * V_25 ,
enum V_44 type , T_4 * V_37 ,
struct V_45 * V_46 )
{
struct V_5 * V_9 = F_5 ( V_10 ) ;
struct V_47 * V_48 ;
T_6 V_49 = 0 ;
T_6 V_28 = 0 ;
F_19 ( L_3 ) ;
if ( ! F_4 ( V_10 ) )
return - V_50 ;
switch ( type ) {
case V_51 :
case V_52 :
F_17 ( L_4 ,
type ) ;
return - V_53 ;
case V_54 :
V_9 -> V_55 -> V_56 = V_57 ;
V_49 = 0 ;
break;
case V_58 :
V_9 -> V_55 -> V_56 = V_59 ;
V_49 = 1 ;
break;
default:
V_28 = - V_60 ;
goto V_61;
}
V_28 = F_10 ( V_25 , V_62 , & V_49 ) ;
if ( V_28 ) {
F_17 ( L_5 , V_28 ) ;
V_28 = - V_63 ;
} else {
V_48 = V_25 -> V_64 ;
V_48 -> V_65 = type ;
}
F_7 ( L_6 ,
( V_9 -> V_55 -> V_56 == V_57 ) ? L_7 : L_8 ) ;
V_61:
F_19 ( L_9 ) ;
return V_28 ;
}
static T_6 F_20 ( struct V_24 * V_25 , T_7 * V_66 , T_6 V_67 )
{
T_7 V_68 [ V_69 ] ;
T_4 V_35 ;
T_6 V_28 = 0 ;
T_5 V_70 ;
V_70 = F_11 ( V_67 ) ;
V_35 = F_21 ( V_66 , ( char * ) ( & V_70 ) , sizeof( V_70 ) , V_68 ,
sizeof( V_68 ) ) ;
F_22 ( ! V_35 ) ;
V_28 = F_12 ( V_25 , V_71 , V_68 , V_35 ) ;
if ( V_28 )
F_17 ( L_10 , V_28 ) ;
return V_28 ;
}
static T_6
F_23 ( struct V_24 * V_25 , T_7 * V_66 , T_6 * V_72 )
{
union {
T_7 V_68 [ V_69 ] ;
T_5 V_67 ;
} V_73 ;
T_4 V_35 ;
T_4 V_74 ;
T_6 V_28 = 0 ;
V_35 =
F_21 ( V_66 , ( char * ) ( & V_74 ) , 0 , ( char * ) ( & V_73 ) ,
sizeof( V_73 . V_68 ) ) ;
F_22 ( ! V_35 ) ;
V_28 = F_12 ( V_25 , V_75 , & V_73 , V_35 ) ;
if ( V_28 )
F_17 ( L_10 , V_28 ) ;
* V_72 = F_13 ( V_73 . V_67 ) ;
return V_28 ;
}
static void F_24 ( struct V_24 * V_25 , int V_76 )
{
T_6 V_28 = 0 ;
struct V_5 * V_9 = F_25 ( V_25 ) ;
if ( F_6 ( V_11 , & V_9 -> V_12 ) ) {
V_28 = F_20 ( V_25 , L_11 , V_76 ) ;
if ( V_28 ) {
F_17 ( L_12 ) ;
return;
}
F_7 ( L_13 , V_76 ) ;
}
}
static void F_26 ( struct V_77 * V_78 ,
struct V_79 * V_80 )
{
memcpy ( V_78 -> V_81 , V_82 , V_83 ) ;
V_78 -> V_84 = V_85 ;
V_78 -> V_86 = 0 ;
V_78 -> V_87 = 0 ;
V_78 -> V_88 = F_11 ( - 1 ) ;
V_78 -> V_89 = F_11 ( - 1 ) ;
V_78 -> V_90 = F_11 ( - 1 ) ;
V_78 -> V_91 = F_11 ( - 1 ) ;
if ( V_80 && V_80 -> V_92 )
memcpy ( & V_78 -> V_93 , V_80 , sizeof( struct V_79 ) ) ;
}
static T_6
F_27 ( struct V_24 * V_25 , T_7 * V_94 , void * V_95 ,
T_6 V_96 , void * V_97 , T_6 V_98 )
{
T_6 V_99 ;
V_99 = F_21 ( V_94 , V_95 , V_96 , V_97 , V_98 ) ;
F_22 ( ! V_99 ) ;
return F_12 ( V_25 , V_71 , V_97 , V_99 ) ;
}
static T_6
F_28 ( struct V_24 * V_25 , T_7 * V_94 , void * V_95 ,
T_6 V_96 , void * V_97 , T_6 V_98 )
{
T_6 V_99 ;
V_99 = F_21 ( V_94 , V_95 , V_96 , V_97 , V_98 ) ;
F_22 ( ! V_99 ) ;
return F_12 ( V_25 , V_75 , V_97 , V_98 ) ;
}
static T_6
F_29 ( struct V_100 * V_101 ,
struct V_79 * V_80 , T_1 V_102 )
{
T_6 V_103 = V_104 +
F_30 ( struct V_105 , V_78 ) ;
struct V_105 * V_46 ;
T_6 V_28 = 0 ;
if ( V_80 && V_80 -> V_92 )
V_103 += sizeof( struct V_79 ) ;
V_46 = F_31 ( V_103 , V_106 ) ;
if ( ! V_46 )
return - V_107 ;
F_22 ( V_103 >= V_69 ) ;
F_26 ( & V_46 -> V_78 , V_80 ) ;
V_46 -> V_108 = F_11 ( V_109 ) ;
V_46 -> V_102 = F_15 ( V_102 ) ;
V_46 -> V_110 = F_15 ( 0 ) ;
V_28 = F_27 ( V_101 -> V_25 , L_14 , V_46 , V_103 ,
V_101 -> V_111 , V_69 ) ;
if ( V_28 ) {
if ( V_28 == - V_112 )
F_7 ( L_15 ) ;
else
F_17 ( L_10 , V_28 ) ;
}
F_32 ( V_46 ) ;
return V_28 ;
}
static T_6 F_33 ( struct V_5 * V_9 )
{
struct V_100 * V_101 = F_34 ( V_9 ) ;
struct V_24 * V_25 = F_35 ( V_9 ) ;
struct V_79 V_80 ;
T_5 V_113 ;
T_6 V_28 = 0 ;
memset ( & V_80 , 0 , sizeof( V_80 ) ) ;
V_101 -> V_114 = V_115 ;
V_113 = V_9 -> V_116 ? 0 : F_11 ( 1 ) ;
V_28 = F_12 ( F_35 ( V_9 ) , V_117 ,
& V_113 , sizeof( V_113 ) ) ;
if ( V_28 ) {
F_17 ( L_10 , V_28 ) ;
return V_28 ;
}
F_24 ( V_25 , 0 ) ;
V_9 -> V_118 = true ;
V_28 = F_29 ( V_101 , & V_80 , V_119 ) ;
if ( V_28 ) {
F_24 ( V_25 , 1 ) ;
V_9 -> V_118 = false ;
return V_28 ;
}
F_36 ( & V_101 -> V_120 , V_121 + V_101 -> V_122 * V_123 / 1000 ) ;
V_101 -> V_124 = 1 ;
return V_28 ;
}
static T_6
F_37 ( struct V_10 * V_10 , struct V_24 * V_25 ,
struct V_125 * V_126 ,
struct V_127 * V_128 )
{
struct V_5 * V_9 = F_25 ( V_25 ) ;
struct V_127 * V_129 ;
struct V_130 * V_131 = V_9 -> V_132 ;
T_5 V_113 ;
bool V_133 ;
bool V_134 ;
T_6 V_28 = 0 ;
T_4 V_92 ;
if ( F_6 ( V_135 , & V_9 -> V_12 ) ) {
F_17 ( L_16 , V_9 -> V_12 ) ;
return - V_63 ;
}
if ( F_6 ( V_136 , & V_9 -> V_12 ) ) {
F_17 ( L_17 ,
V_9 -> V_12 ) ;
return - V_63 ;
}
if ( F_6 ( V_137 , & V_9 -> V_12 ) ) {
F_17 ( L_18 ,
V_9 -> V_12 ) ;
return - V_63 ;
}
V_133 = false ;
V_134 = false ;
if ( V_126 ) {
V_129 = V_126 -> V_129 ;
if ( V_9 -> V_138 && ( ! V_129 || ! V_129 -> V_139 ) )
V_133 = true ;
} else {
V_129 = V_128 ;
}
V_9 -> V_140 = V_126 ;
F_38 ( V_135 , & V_9 -> V_12 ) ;
if ( V_133 ) {
V_28 = F_33 ( V_9 ) ;
if ( ! V_28 )
return V_28 ;
else
goto V_141;
} else {
F_39 ( L_19 ,
V_129 -> V_80 , V_129 -> V_139 ) ;
memset ( & V_131 -> V_93 , 0 , sizeof( V_131 -> V_93 ) ) ;
V_92 = F_40 ( T_2 , sizeof( V_131 -> V_93 . V_142 ) , V_129 -> V_139 ) ;
V_131 -> V_93 . V_92 = F_11 ( 0 ) ;
if ( V_92 ) {
memcpy ( V_131 -> V_93 . V_142 , V_129 -> V_80 , V_92 ) ;
V_131 -> V_93 . V_92 = F_11 ( V_92 ) ;
V_134 = true ;
} else {
F_39 ( L_20 ) ;
}
V_113 = V_9 -> V_116 ? 0 : F_11 ( 1 ) ;
V_28 = F_12 ( V_25 , V_117 ,
& V_113 , sizeof( V_113 ) ) ;
if ( V_28 ) {
F_17 ( L_21 , V_28 ) ;
goto V_141;
}
F_24 ( V_25 , 0 ) ;
V_28 = F_12 ( V_25 , V_143 , & V_131 -> V_93 ,
sizeof( V_131 -> V_93 ) ) ;
if ( V_28 ) {
if ( V_28 == - V_112 )
F_7 ( L_22
L_23 , V_131 -> V_93 . V_142 ) ;
else
F_17 ( L_24 , V_28 ) ;
F_24 ( V_25 , 1 ) ;
goto V_141;
}
}
return 0 ;
V_141:
F_41 ( V_135 , & V_9 -> V_12 ) ;
V_9 -> V_140 = NULL ;
return V_28 ;
}
static T_6
F_42 ( struct V_10 * V_10 , struct V_24 * V_25 ,
struct V_125 * V_126 )
{
T_6 V_28 = 0 ;
F_19 ( L_3 ) ;
if ( ! F_4 ( V_10 ) )
return - V_50 ;
V_28 = F_37 ( V_10 , V_25 , V_126 , NULL ) ;
if ( V_28 )
F_17 ( L_25 , V_28 ) ;
F_19 ( L_9 ) ;
return V_28 ;
}
static T_6 F_43 ( struct V_24 * V_25 , T_4 V_144 )
{
T_6 V_28 = 0 ;
V_28 = F_20 ( V_25 , L_26 , V_144 ) ;
if ( V_28 )
F_17 ( L_27 , V_28 ) ;
return V_28 ;
}
static T_6 F_44 ( struct V_24 * V_25 , T_4 V_145 )
{
T_6 V_28 = 0 ;
V_28 = F_20 ( V_25 , L_28 , V_145 ) ;
if ( V_28 )
F_17 ( L_27 , V_28 ) ;
return V_28 ;
}
static T_6 F_45 ( struct V_24 * V_25 , T_4 V_146 , bool V_147 )
{
T_6 V_28 = 0 ;
T_4 V_26 = ( V_147 ? V_148 : V_149 ) ;
V_28 = F_10 ( V_25 , V_26 , & V_146 ) ;
if ( V_28 ) {
F_17 ( L_29 , V_26 , V_28 ) ;
return V_28 ;
}
return V_28 ;
}
static T_6 F_46 ( struct V_10 * V_10 , T_4 V_150 )
{
struct V_5 * V_9 = F_5 ( V_10 ) ;
struct V_24 * V_25 = F_35 ( V_9 ) ;
T_6 V_28 = 0 ;
F_19 ( L_3 ) ;
if ( ! F_4 ( V_10 ) )
return - V_50 ;
if ( V_150 & V_151 &&
( V_9 -> V_55 -> V_144 != V_10 -> V_144 ) ) {
V_9 -> V_55 -> V_144 = V_10 -> V_144 ;
V_28 = F_43 ( V_25 , V_9 -> V_55 -> V_144 ) ;
if ( ! V_28 )
goto V_61;
}
if ( V_150 & V_152 &&
( V_9 -> V_55 -> V_145 != V_10 -> V_145 ) ) {
V_9 -> V_55 -> V_145 = V_10 -> V_145 ;
V_28 = F_44 ( V_25 , V_9 -> V_55 -> V_145 ) ;
if ( ! V_28 )
goto V_61;
}
if ( V_150 & V_153
&& ( V_9 -> V_55 -> V_154 != V_10 -> V_154 ) ) {
V_9 -> V_55 -> V_154 = V_10 -> V_154 ;
V_28 = F_45 ( V_25 , V_9 -> V_55 -> V_154 , true ) ;
if ( ! V_28 )
goto V_61;
}
if ( V_150 & V_155
&& ( V_9 -> V_55 -> V_156 != V_10 -> V_156 ) ) {
V_9 -> V_55 -> V_156 = V_10 -> V_156 ;
V_28 = F_45 ( V_25 , V_9 -> V_55 -> V_156 , false ) ;
if ( ! V_28 )
goto V_61;
}
V_61:
F_19 ( L_9 ) ;
return V_28 ;
}
static void * F_47 ( struct V_5 * V_9 , T_6 V_157 )
{
switch ( V_157 ) {
case V_158 :
return & V_9 -> V_159 -> V_160 ;
case V_161 :
return & V_9 -> V_159 -> V_81 ;
case V_162 :
return & V_9 -> V_159 -> V_80 ;
}
F_17 ( L_30 , V_157 ) ;
return NULL ;
}
static T_6
F_48 ( struct V_5 * V_9 ,
const struct V_163 * V_164 , void * V_3 , T_6 V_157 )
{
T_6 V_28 = 0 ;
struct V_79 * V_80 ;
switch ( V_157 ) {
case V_162 :
V_80 = (struct V_79 * ) V_3 ;
memset ( V_9 -> V_159 -> V_80 . V_142 , 0 ,
sizeof( V_9 -> V_159 -> V_80 . V_142 ) ) ;
memcpy ( V_9 -> V_159 -> V_80 . V_142 ,
V_80 -> V_142 , V_80 -> V_92 ) ;
V_9 -> V_159 -> V_80 . V_92 = V_80 -> V_92 ;
break;
case V_161 :
if ( V_3 )
memcpy ( V_9 -> V_159 -> V_81 , V_3 , V_83 ) ;
else
memset ( V_9 -> V_159 -> V_81 , 0 , V_83 ) ;
break;
case V_158 :
memcpy ( & V_9 -> V_159 -> V_160 , V_3 ,
sizeof( V_9 -> V_159 -> V_160 ) ) ;
break;
case V_165 :
V_9 -> V_159 -> V_166 = * ( T_1 * ) V_3 ;
break;
case V_167 :
V_9 -> V_159 -> V_168 = * ( T_2 * ) V_3 ;
break;
default:
F_17 ( L_31 , V_157 ) ;
V_28 = - V_53 ;
break;
}
return V_28 ;
}
static void F_49 ( struct V_169 * V_170 )
{
memset ( V_170 , 0 , sizeof( * V_170 ) ) ;
}
static void F_50 ( int V_171 , struct V_172 * V_173 ,
T_8 * V_174 )
{
T_1 V_175 = 0 ;
if ( V_171 != 0 ) {
if ( V_171 <= V_176 )
V_175 |= V_177 ;
else
V_175 |= V_178 ;
V_175 |= V_179 ;
V_175 |= V_180 ;
* V_174 += V_181 +
sizeof( T_1 ) ;
V_175 |= ( V_171 & V_182 ) ;
V_173 -> V_78 . V_183 [ 0 ] = F_15 ( V_175 ) ;
V_173 -> V_78 . V_184 = F_11 ( 1 ) ;
F_51 ( L_32
L_33 ,
V_175 , V_171 , V_175 ) ;
}
}
static void F_52 ( struct V_5 * V_9 )
{
struct V_24 * V_25 = NULL ;
T_6 V_28 = 0 ;
F_19 ( L_3 ) ;
if ( V_9 -> V_185 ) {
V_25 = F_35 ( V_9 ) ;
F_7 ( L_34 ) ;
V_28 = F_12 ( V_25 , V_186 , NULL , 0 ) ;
if ( V_28 )
F_17 ( L_35 , V_28 ) ;
V_9 -> V_185 = false ;
}
F_19 ( L_9 ) ;
}
static T_6
F_53 ( struct V_10 * V_10 , struct V_24 * V_25 ,
struct V_187 * V_46 )
{
struct V_5 * V_9 = F_5 ( V_10 ) ;
struct V_172 V_173 ;
T_8 V_174 = 0 ;
T_6 V_28 = 0 ;
T_6 V_188 = 0 ;
T_6 V_189 ;
struct V_79 V_80 ;
F_19 ( L_3 ) ;
if ( ! F_4 ( V_10 ) )
return - V_50 ;
if ( V_46 -> V_80 )
F_51 ( L_36 , V_46 -> V_80 ) ;
else {
F_51 ( L_37 ) ;
return - V_53 ;
}
F_38 ( V_137 , & V_9 -> V_12 ) ;
if ( V_46 -> V_81 )
F_51 ( L_38 ,
V_46 -> V_81 [ 0 ] , V_46 -> V_81 [ 1 ] , V_46 -> V_81 [ 2 ] ,
V_46 -> V_81 [ 3 ] , V_46 -> V_81 [ 4 ] , V_46 -> V_81 [ 5 ] ) ;
else
F_51 ( L_39 ) ;
if ( V_46 -> V_190 )
F_51 ( L_40 , V_46 -> V_190 -> V_191 ) ;
else
F_51 ( L_41 ) ;
if ( V_46 -> V_192 )
F_51 ( L_42 ) ;
else
F_51 ( L_43 ) ;
if ( V_46 -> V_193 && V_46 -> V_194 )
F_51 ( L_44 , V_46 -> V_194 ) ;
else
F_51 ( L_45 ) ;
if ( V_46 -> V_166 )
F_51 ( L_46 , V_46 -> V_166 ) ;
else
F_51 ( L_47 ) ;
if ( V_46 -> V_195 )
F_51 ( L_48 , V_46 -> V_195 ) ;
else
F_51 ( L_49 ) ;
if ( V_46 -> V_196 )
F_51 ( L_50 ) ;
else
F_51 ( L_51 ) ;
if ( V_46 -> V_196 )
V_188 |= V_197 ;
V_28 = F_20 ( V_25 , L_52 , V_188 ) ;
if ( V_28 ) {
F_17 ( L_53 , V_28 ) ;
goto V_61;
}
if ( V_46 -> V_166 )
V_189 = V_46 -> V_166 ;
else
V_189 = 100 ;
V_28 = F_10 ( V_25 , V_198 , & V_189 ) ;
if ( V_28 ) {
F_17 ( L_54 , V_28 ) ;
goto V_61;
}
memset ( & V_173 , 0 , sizeof( struct V_172 ) ) ;
V_80 . V_92 = F_40 ( T_4 , V_46 -> V_139 , 32 ) ;
memcpy ( V_80 . V_142 , V_46 -> V_80 , V_80 . V_92 ) ;
memcpy ( V_173 . V_93 . V_142 , V_46 -> V_80 , V_80 . V_92 ) ;
V_173 . V_93 . V_92 = F_11 ( V_80 . V_92 ) ;
V_174 = sizeof( V_173 . V_93 ) ;
F_48 ( V_9 , NULL , & V_80 , V_162 ) ;
if ( V_46 -> V_81 ) {
memcpy ( V_173 . V_78 . V_81 , V_46 -> V_81 , V_83 ) ;
V_174 = sizeof( V_173 . V_93 ) +
V_181 ;
} else {
memcpy ( V_173 . V_78 . V_81 , V_82 , V_83 ) ;
}
F_48 ( V_9 , NULL ,
& V_173 . V_78 . V_81 , V_161 ) ;
if ( V_46 -> V_190 ) {
T_4 V_199 ;
V_9 -> V_190 =
F_54 (
V_46 -> V_190 -> V_191 ) ;
if ( V_46 -> V_192 ) {
F_50 ( V_9 -> V_190 ,
& V_173 , & V_174 ) ;
}
V_199 = V_9 -> V_190 ;
V_28 = F_10 ( V_25 , V_200 ,
& V_199 ) ;
if ( V_28 ) {
F_17 ( L_55 , V_28 ) ;
goto V_61;
}
} else
V_9 -> V_190 = 0 ;
V_9 -> V_201 = false ;
V_28 = F_12 ( V_25 , V_202 ,
& V_173 , V_174 ) ;
if ( V_28 ) {
F_17 ( L_56 , V_28 ) ;
goto V_61;
}
V_61:
if ( V_28 )
F_41 ( V_137 , & V_9 -> V_12 ) ;
F_19 ( L_9 ) ;
return V_28 ;
}
static T_6
F_55 ( struct V_10 * V_10 , struct V_24 * V_25 )
{
struct V_5 * V_9 = F_5 ( V_10 ) ;
T_6 V_28 = 0 ;
F_19 ( L_3 ) ;
if ( ! F_4 ( V_10 ) )
return - V_50 ;
F_52 ( V_9 ) ;
F_19 ( L_9 ) ;
return V_28 ;
}
static T_6 F_56 ( struct V_24 * V_25 ,
struct V_203 * V_204 )
{
struct V_5 * V_9 = F_25 ( V_25 ) ;
struct V_205 * V_160 ;
T_6 V_67 = 0 ;
T_6 V_28 = 0 ;
if ( V_204 -> V_206 . V_207 & V_208 )
V_67 = V_209 | V_210 ;
else if ( V_204 -> V_206 . V_207 & V_211 )
V_67 = V_212 | V_213 ;
else
V_67 = V_214 ;
F_51 ( L_57 , V_67 ) ;
V_28 = F_20 ( V_25 , L_58 , V_67 ) ;
if ( V_28 ) {
F_17 ( L_59 , V_28 ) ;
return V_28 ;
}
V_160 = F_47 ( V_9 , V_158 ) ;
V_160 -> V_207 = V_204 -> V_206 . V_207 ;
return V_28 ;
}
static T_6 F_57 ( struct V_24 * V_25 ,
struct V_203 * V_204 )
{
struct V_5 * V_9 = F_25 ( V_25 ) ;
struct V_205 * V_160 ;
T_6 V_67 = 0 ;
T_6 V_28 = 0 ;
switch ( V_204 -> V_215 ) {
case V_216 :
V_67 = 0 ;
F_51 ( L_60 ) ;
break;
case V_217 :
V_67 = 1 ;
F_51 ( L_61 ) ;
break;
case V_218 :
V_67 = 2 ;
F_51 ( L_62 ) ;
break;
case V_219 :
F_51 ( L_63 ) ;
default:
V_67 = 2 ;
F_17 ( L_64 , V_204 -> V_215 ) ;
break;
}
V_28 = F_20 ( V_25 , L_65 , V_67 ) ;
if ( V_28 ) {
F_17 ( L_66 , V_28 ) ;
return V_28 ;
}
V_160 = F_47 ( V_9 , V_158 ) ;
V_160 -> V_215 = V_204 -> V_215 ;
return V_28 ;
}
static T_6
F_58 ( struct V_24 * V_25 ,
struct V_203 * V_204 )
{
struct V_5 * V_9 = F_25 ( V_25 ) ;
struct V_205 * V_160 ;
T_6 V_220 = 0 ;
T_6 V_221 = 0 ;
T_6 V_28 = 0 ;
if ( V_204 -> V_206 . V_222 ) {
switch ( V_204 -> V_206 . V_223 [ 0 ] ) {
case V_224 :
case V_225 :
V_220 = V_197 ;
break;
case V_226 :
V_220 = V_227 ;
break;
case V_228 :
V_220 = V_229 ;
break;
case V_230 :
V_220 = V_229 ;
break;
default:
F_17 ( L_67 ,
V_204 -> V_206 . V_223 [ 0 ] ) ;
return - V_60 ;
}
}
if ( V_204 -> V_206 . V_231 ) {
switch ( V_204 -> V_206 . V_231 ) {
case V_224 :
case V_225 :
V_221 = V_197 ;
break;
case V_226 :
V_221 = V_227 ;
break;
case V_228 :
V_221 = V_229 ;
break;
case V_230 :
V_221 = V_229 ;
break;
default:
F_17 ( L_68 ,
V_204 -> V_206 . V_231 ) ;
return - V_60 ;
}
}
F_51 ( L_69 , V_220 , V_221 ) ;
V_28 = F_20 ( V_25 , L_52 , V_220 | V_221 ) ;
if ( V_28 ) {
F_17 ( L_10 , V_28 ) ;
return V_28 ;
}
V_160 = F_47 ( V_9 , V_158 ) ;
V_160 -> V_232 = V_204 -> V_206 . V_223 [ 0 ] ;
V_160 -> V_231 = V_204 -> V_206 . V_231 ;
return V_28 ;
}
static T_6
F_59 ( struct V_24 * V_25 , struct V_203 * V_204 )
{
struct V_5 * V_9 = F_25 ( V_25 ) ;
struct V_205 * V_160 ;
T_6 V_67 = 0 ;
T_6 V_28 = 0 ;
if ( V_204 -> V_206 . V_233 ) {
V_28 = F_23 ( V_25 , L_58 , & V_67 ) ;
if ( V_28 ) {
F_17 ( L_70 , V_28 ) ;
return V_28 ;
}
if ( V_67 & ( V_209 | V_210 ) ) {
switch ( V_204 -> V_206 . V_234 [ 0 ] ) {
case V_235 :
V_67 = V_210 ;
break;
case V_236 :
V_67 = V_209 ;
break;
default:
F_17 ( L_68 ,
V_204 -> V_206 . V_231 ) ;
return - V_60 ;
}
} else if ( V_67 & ( V_212 | V_213 ) ) {
switch ( V_204 -> V_206 . V_234 [ 0 ] ) {
case V_235 :
V_67 = V_213 ;
break;
case V_236 :
V_67 = V_212 ;
break;
default:
F_17 ( L_68 ,
V_204 -> V_206 . V_231 ) ;
return - V_60 ;
}
}
F_51 ( L_71 , V_67 ) ;
V_28 = F_20 ( V_25 , L_58 , V_67 ) ;
if ( V_28 ) {
F_17 ( L_72 , V_28 ) ;
return V_28 ;
}
}
V_160 = F_47 ( V_9 , V_158 ) ;
V_160 -> V_237 = V_204 -> V_206 . V_234 [ 0 ] ;
return V_28 ;
}
static T_6
F_60 ( struct V_24 * V_25 ,
struct V_203 * V_204 )
{
struct V_5 * V_9 = F_25 ( V_25 ) ;
struct V_205 * V_160 ;
struct V_30 V_31 ;
T_6 V_67 ;
T_6 V_28 = 0 ;
F_51 ( L_73 , V_204 -> V_238 ) ;
if ( V_204 -> V_238 == 0 )
return 0 ;
V_160 = F_47 ( V_9 , V_158 ) ;
F_51 ( L_74 ,
V_160 -> V_207 , V_160 -> V_232 ) ;
if ( V_160 -> V_207 & ( V_208 | V_211 ) )
return 0 ;
if ( V_160 -> V_232 &
( V_224 | V_225 ) ) {
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_35 = ( T_4 ) V_204 -> V_238 ;
V_31 . V_34 = ( T_4 ) V_204 -> V_239 ;
if ( V_31 . V_35 > sizeof( V_31 . V_3 ) ) {
F_17 ( L_75 , V_31 . V_35 ) ;
return - V_60 ;
}
memcpy ( V_31 . V_3 , V_204 -> V_31 , V_31 . V_35 ) ;
V_31 . V_37 = V_240 ;
switch ( V_160 -> V_232 ) {
case V_224 :
V_31 . V_36 = V_241 ;
break;
case V_225 :
V_31 . V_36 = V_242 ;
break;
default:
F_17 ( L_76 ,
V_204 -> V_206 . V_223 [ 0 ] ) ;
return - V_60 ;
}
F_51 ( L_77 ,
V_31 . V_35 , V_31 . V_34 , V_31 . V_36 ) ;
F_51 ( L_78 , V_31 . V_3 ) ;
V_28 = F_16 ( V_25 , & V_31 ) ;
if ( V_28 )
return V_28 ;
if ( V_160 -> V_215 == V_216 ) {
F_51 ( L_79 ) ;
V_67 = 1 ;
V_28 = F_20 ( V_25 , L_65 , V_67 ) ;
if ( V_28 ) {
F_17 ( L_66 , V_28 ) ;
return V_28 ;
}
}
}
return V_28 ;
}
static T_6
F_61 ( struct V_10 * V_10 , struct V_24 * V_25 ,
struct V_203 * V_204 )
{
struct V_5 * V_9 = F_5 ( V_10 ) ;
struct V_243 * V_244 = V_204 -> V_190 ;
struct V_172 V_173 ;
T_8 V_174 ;
struct V_79 V_80 ;
T_6 V_28 = 0 ;
F_19 ( L_3 ) ;
if ( ! F_4 ( V_10 ) )
return - V_50 ;
if ( ! V_204 -> V_80 ) {
F_17 ( L_80 ) ;
return - V_53 ;
}
F_38 ( V_137 , & V_9 -> V_12 ) ;
if ( V_244 ) {
V_9 -> V_190 =
F_54 ( V_244 -> V_191 ) ;
F_51 ( L_81 ,
V_9 -> V_190 , V_244 -> V_191 ) ;
} else
V_9 -> V_190 = 0 ;
F_7 ( L_82 , V_204 -> V_193 , V_204 -> V_194 ) ;
V_28 = F_56 ( V_25 , V_204 ) ;
if ( V_28 ) {
F_17 ( L_83 , V_28 ) ;
goto V_61;
}
V_28 = F_57 ( V_25 , V_204 ) ;
if ( V_28 ) {
F_17 ( L_84 , V_28 ) ;
goto V_61;
}
V_28 = F_58 ( V_25 , V_204 ) ;
if ( V_28 ) {
F_17 ( L_85 , V_28 ) ;
goto V_61;
}
V_28 = F_59 ( V_25 , V_204 ) ;
if ( V_28 ) {
F_17 ( L_86 , V_28 ) ;
goto V_61;
}
V_28 = F_60 ( V_25 , V_204 ) ;
if ( V_28 ) {
F_17 ( L_87 , V_28 ) ;
goto V_61;
}
memset ( & V_173 , 0 , sizeof( V_173 ) ) ;
V_174 = sizeof( V_173 . V_93 ) ;
V_80 . V_92 = F_40 ( T_4 , sizeof( V_80 . V_142 ) , ( T_4 ) V_204 -> V_139 ) ;
memcpy ( & V_173 . V_93 . V_142 , V_204 -> V_80 , V_80 . V_92 ) ;
memcpy ( & V_80 . V_142 , V_204 -> V_80 , V_80 . V_92 ) ;
V_173 . V_93 . V_92 = F_11 ( V_80 . V_92 ) ;
F_48 ( V_9 , NULL , & V_80 , V_162 ) ;
memcpy ( V_173 . V_78 . V_81 , V_82 , V_83 ) ;
if ( V_80 . V_92 < V_245 )
F_51 ( L_88 ,
V_80 . V_142 , V_80 . V_92 ) ;
F_50 ( V_9 -> V_190 ,
& V_173 , & V_174 ) ;
V_28 = F_12 ( V_25 , V_202 ,
& V_173 , V_174 ) ;
if ( V_28 )
F_17 ( L_56 , V_28 ) ;
V_61:
if ( V_28 )
F_41 ( V_137 , & V_9 -> V_12 ) ;
F_19 ( L_9 ) ;
return V_28 ;
}
static T_6
F_62 ( struct V_10 * V_10 , struct V_24 * V_25 ,
T_1 V_246 )
{
struct V_5 * V_9 = F_5 ( V_10 ) ;
struct V_247 V_248 ;
T_6 V_28 = 0 ;
F_19 ( L_89 , V_246 ) ;
if ( ! F_4 ( V_10 ) )
return - V_50 ;
F_41 ( V_249 , & V_9 -> V_12 ) ;
memcpy ( & V_248 . V_42 , F_47 ( V_9 , V_161 ) , V_83 ) ;
V_248 . V_67 = F_11 ( V_246 ) ;
V_28 = F_12 ( V_25 , V_186 , & V_248 ,
sizeof( struct V_247 ) ) ;
if ( V_28 )
F_17 ( L_10 , V_28 ) ;
V_9 -> V_185 = false ;
F_19 ( L_9 ) ;
return V_28 ;
}
static T_6
F_63 ( struct V_10 * V_10 ,
enum V_250 type , T_6 V_251 )
{
struct V_5 * V_9 = F_5 ( V_10 ) ;
struct V_24 * V_25 = F_35 ( V_9 ) ;
T_1 V_252 ;
T_6 V_28 = 0 ;
T_6 V_253 = 0 ;
T_6 V_254 = F_64 ( V_251 ) ;
F_19 ( L_3 ) ;
if ( ! F_4 ( V_10 ) )
return - V_50 ;
switch ( type ) {
case V_255 :
break;
case V_256 :
case V_257 :
if ( V_254 < 0 ) {
F_17 ( L_90 ) ;
V_28 = - V_60 ;
goto V_61;
}
break;
}
V_253 = V_258 << 16 ;
V_28 = F_10 ( V_25 , V_259 , & V_253 ) ;
if ( V_28 )
F_17 ( L_91 , V_28 ) ;
if ( V_254 > 0xffff )
V_252 = 0xffff ;
else
V_252 = ( T_1 ) V_254 ;
V_28 = F_20 ( V_25 , L_92 ,
( T_6 ) ( F_9 ( V_252 ) ) ) ;
if ( V_28 )
F_17 ( L_93 , V_28 ) ;
V_9 -> V_55 -> V_260 = V_254 ;
V_61:
F_19 ( L_9 ) ;
return V_28 ;
}
static T_6 F_65 ( struct V_10 * V_10 , T_6 * V_254 )
{
struct V_5 * V_9 = F_5 ( V_10 ) ;
struct V_24 * V_25 = F_35 ( V_9 ) ;
T_6 V_261 ;
T_2 V_262 ;
T_6 V_28 = 0 ;
F_19 ( L_3 ) ;
if ( ! F_4 ( V_10 ) )
return - V_50 ;
V_28 = F_23 ( V_25 , L_92 , & V_261 ) ;
if ( V_28 ) {
F_17 ( L_10 , V_28 ) ;
goto V_61;
}
V_262 = ( T_2 ) ( V_261 & ~ V_263 ) ;
* V_254 = ( T_6 ) F_8 ( V_262 ) ;
V_61:
F_19 ( L_9 ) ;
return V_28 ;
}
static T_6
F_66 ( struct V_10 * V_10 , struct V_24 * V_25 ,
T_2 V_239 , bool V_264 , bool V_265 )
{
T_4 V_34 ;
T_4 V_188 ;
T_6 V_28 = 0 ;
F_19 ( L_3 ) ;
F_51 ( L_94 , V_239 ) ;
if ( ! F_4 ( V_10 ) )
return - V_50 ;
V_28 = F_10 ( V_25 , V_266 , & V_188 ) ;
if ( V_28 ) {
F_17 ( L_95 , V_28 ) ;
goto V_61;
}
if ( V_188 & V_197 ) {
V_34 = V_239 ;
V_28 = F_10 ( V_25 , V_267 ,
& V_34 ) ;
if ( V_28 )
F_17 ( L_10 , V_28 ) ;
}
V_61:
F_19 ( L_9 ) ;
return V_28 ;
}
static T_6
F_67 ( struct V_10 * V_10 , struct V_24 * V_25 ,
T_2 V_239 , const T_2 * V_268 , struct V_269 * V_46 )
{
struct V_30 V_31 ;
struct V_32 V_33 ;
T_6 V_28 = 0 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_34 = ( T_4 ) V_239 ;
if ( ! F_68 ( V_268 ) )
memcpy ( ( char * ) & V_31 . V_42 , ( void * ) V_268 , V_83 ) ;
V_31 . V_35 = ( T_4 ) V_46 -> V_238 ;
if ( V_31 . V_35 == 0 ) {
V_28 = F_16 ( V_25 , & V_31 ) ;
if ( V_28 )
return V_28 ;
} else {
if ( V_31 . V_35 > sizeof( V_31 . V_3 ) ) {
F_17 ( L_96 , V_31 . V_35 ) ;
return - V_60 ;
}
F_51 ( L_97 , V_31 . V_34 ) ;
memcpy ( V_31 . V_3 , V_46 -> V_31 , V_31 . V_35 ) ;
if ( V_46 -> V_270 == V_226 ) {
T_2 V_271 [ 8 ] ;
memcpy ( V_271 , & V_31 . V_3 [ 24 ] , sizeof( V_271 ) ) ;
memcpy ( & V_31 . V_3 [ 24 ] , & V_31 . V_3 [ 16 ] , sizeof( V_271 ) ) ;
memcpy ( & V_31 . V_3 [ 16 ] , V_271 , sizeof( V_271 ) ) ;
}
if ( V_46 -> V_272 && V_46 -> V_273 == 6 ) {
T_2 * V_274 ;
V_274 = ( T_2 * ) V_46 -> V_272 ;
V_31 . V_38 . V_39 = ( V_274 [ 5 ] << 24 ) | ( V_274 [ 4 ] << 16 ) |
( V_274 [ 3 ] << 8 ) | V_274 [ 2 ] ;
V_31 . V_38 . V_40 = ( V_274 [ 1 ] << 8 ) | V_274 [ 0 ] ;
V_31 . V_41 = true ;
}
switch ( V_46 -> V_270 ) {
case V_224 :
V_31 . V_36 = V_241 ;
F_51 ( L_98 ) ;
break;
case V_225 :
V_31 . V_36 = V_242 ;
F_51 ( L_99 ) ;
break;
case V_226 :
V_31 . V_36 = V_275 ;
F_51 ( L_100 ) ;
break;
case V_230 :
V_31 . V_36 = V_276 ;
F_51 ( L_101 ) ;
break;
case V_228 :
V_31 . V_36 = V_276 ;
F_51 ( L_102 ) ;
break;
default:
F_17 ( L_103 , V_46 -> V_270 ) ;
return - V_60 ;
}
F_14 ( & V_31 , & V_33 ) ;
F_69 ( V_25 ) ;
V_28 = F_12 ( V_25 , V_43 , & V_33 ,
sizeof( V_33 ) ) ;
if ( V_28 ) {
F_17 ( L_2 , V_28 ) ;
return V_28 ;
}
}
return V_28 ;
}
static T_6
F_70 ( struct V_10 * V_10 , struct V_24 * V_25 ,
T_2 V_239 , bool V_277 , const T_2 * V_268 ,
struct V_269 * V_46 )
{
struct V_30 V_31 ;
T_6 V_67 ;
T_6 V_188 ;
T_6 V_28 = 0 ;
T_2 V_271 [ 8 ] ;
F_19 ( L_3 ) ;
F_51 ( L_94 , V_239 ) ;
if ( ! F_4 ( V_10 ) )
return - V_50 ;
if ( V_268 ) {
F_19 ( L_104 ) ;
return F_67 ( V_10 , V_25 , V_239 , V_268 , V_46 ) ;
}
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_35 = ( T_4 ) V_46 -> V_238 ;
V_31 . V_34 = ( T_4 ) V_239 ;
if ( V_31 . V_35 > sizeof( V_31 . V_3 ) ) {
F_17 ( L_75 , V_31 . V_35 ) ;
V_28 = - V_60 ;
goto V_61;
}
memcpy ( V_31 . V_3 , V_46 -> V_31 , V_31 . V_35 ) ;
V_31 . V_37 = V_240 ;
switch ( V_46 -> V_270 ) {
case V_224 :
V_31 . V_36 = V_241 ;
F_51 ( L_98 ) ;
break;
case V_225 :
V_31 . V_36 = V_242 ;
F_51 ( L_99 ) ;
break;
case V_226 :
memcpy ( V_271 , & V_31 . V_3 [ 24 ] , sizeof( V_271 ) ) ;
memcpy ( & V_31 . V_3 [ 24 ] , & V_31 . V_3 [ 16 ] , sizeof( V_271 ) ) ;
memcpy ( & V_31 . V_3 [ 16 ] , V_271 , sizeof( V_271 ) ) ;
V_31 . V_36 = V_275 ;
F_51 ( L_100 ) ;
break;
case V_230 :
V_31 . V_36 = V_276 ;
F_51 ( L_101 ) ;
break;
case V_228 :
V_31 . V_36 = V_276 ;
F_51 ( L_102 ) ;
break;
default:
F_17 ( L_103 , V_46 -> V_270 ) ;
V_28 = - V_60 ;
goto V_61;
}
V_28 = F_16 ( V_25 , & V_31 ) ;
if ( V_28 )
goto V_61;
V_67 = V_197 ;
V_28 = F_23 ( V_25 , L_52 , & V_188 ) ;
if ( V_28 ) {
F_17 ( L_105 , V_28 ) ;
goto V_61;
}
V_188 &= ~ ( V_197 ) ;
V_188 |= V_67 ;
V_28 = F_20 ( V_25 , L_52 , V_188 ) ;
if ( V_28 ) {
F_17 ( L_106 , V_28 ) ;
goto V_61;
}
V_67 = 1 ;
V_28 = F_10 ( V_25 , V_278 , & V_67 ) ;
if ( V_28 )
F_17 ( L_107 , V_28 ) ;
V_61:
F_19 ( L_9 ) ;
return V_28 ;
}
static T_6
F_71 ( struct V_10 * V_10 , struct V_24 * V_25 ,
T_2 V_239 , bool V_277 , const T_2 * V_268 )
{
struct V_30 V_31 ;
T_6 V_28 = 0 ;
T_6 V_67 ;
T_6 V_188 ;
F_19 ( L_3 ) ;
if ( ! F_4 ( V_10 ) )
return - V_50 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_34 = ( T_4 ) V_239 ;
V_31 . V_37 = V_240 ;
V_31 . V_36 = V_279 ;
F_51 ( L_94 , V_239 ) ;
V_28 = F_16 ( V_25 , & V_31 ) ;
if ( V_28 ) {
if ( V_28 == - V_60 ) {
if ( V_31 . V_34 >= V_280 )
F_17 ( L_108 , V_239 ) ;
}
V_28 = - V_63 ;
goto V_61;
}
V_67 = 0 ;
V_28 = F_23 ( V_25 , L_52 , & V_188 ) ;
if ( V_28 ) {
F_17 ( L_105 , V_28 ) ;
V_28 = - V_63 ;
goto V_61;
}
V_188 &= ~ ( V_197 ) ;
V_188 |= V_67 ;
V_28 = F_20 ( V_25 , L_52 , V_188 ) ;
if ( V_28 ) {
F_17 ( L_106 , V_28 ) ;
V_28 = - V_63 ;
goto V_61;
}
V_67 = 0 ;
V_28 = F_10 ( V_25 , V_278 , & V_67 ) ;
if ( V_28 ) {
F_17 ( L_107 , V_28 ) ;
V_28 = - V_63 ;
}
V_61:
F_19 ( L_9 ) ;
return V_28 ;
}
static T_6
F_72 ( struct V_10 * V_10 , struct V_24 * V_25 ,
T_2 V_239 , bool V_277 , const T_2 * V_268 , void * V_281 ,
void (* F_73) ( void * V_281 , struct V_269 * V_46 ) )
{
struct V_269 V_46 ;
struct V_5 * V_9 = F_5 ( V_10 ) ;
struct V_205 * V_160 ;
T_6 V_188 ;
T_6 V_28 = 0 ;
F_19 ( L_3 ) ;
F_51 ( L_94 , V_239 ) ;
if ( ! F_4 ( V_10 ) )
return - V_50 ;
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
V_28 = F_10 ( V_25 , V_266 , & V_188 ) ;
if ( V_28 ) {
F_17 ( L_95 , V_28 ) ;
V_28 = - V_63 ;
goto V_61;
}
switch ( V_188 ) {
case V_197 :
V_160 = F_47 ( V_9 , V_158 ) ;
if ( V_160 -> V_232 & V_224 ) {
V_46 . V_270 = V_224 ;
F_51 ( L_98 ) ;
} else if ( V_160 -> V_232 & V_225 ) {
V_46 . V_270 = V_225 ;
F_51 ( L_99 ) ;
}
break;
case V_227 :
V_46 . V_270 = V_226 ;
F_51 ( L_100 ) ;
break;
case V_229 :
V_46 . V_270 = V_230 ;
F_51 ( L_101 ) ;
break;
default:
F_17 ( L_109 , V_188 ) ;
V_28 = - V_60 ;
goto V_61;
}
F_73 ( V_281 , & V_46 ) ;
V_61:
F_19 ( L_9 ) ;
return V_28 ;
}
static T_6
F_74 ( struct V_10 * V_10 ,
struct V_24 * V_25 , T_2 V_239 )
{
F_7 ( L_110 ) ;
return - V_53 ;
}
static T_6
F_75 ( struct V_10 * V_10 , struct V_24 * V_25 ,
T_2 * V_282 , struct V_283 * V_284 )
{
struct V_5 * V_9 = F_5 ( V_10 ) ;
struct V_247 V_285 ;
int V_286 ;
T_6 V_287 ;
T_6 V_28 = 0 ;
T_2 * V_81 = F_47 ( V_9 , V_161 ) ;
F_19 ( L_3 ) ;
if ( ! F_4 ( V_10 ) )
return - V_50 ;
if ( memcmp ( V_282 , V_81 , V_83 ) ) {
F_17 ( L_111
L_112 ,
V_282 [ 0 ] , V_282 [ 1 ] , V_282 [ 2 ] , V_282 [ 3 ] , V_282 [ 4 ] , V_282 [ 5 ] ,
V_81 [ 0 ] , V_81 [ 1 ] , V_81 [ 2 ] , V_81 [ 3 ] ,
V_81 [ 4 ] , V_81 [ 5 ] ) ;
V_28 = - V_288 ;
goto V_61;
}
V_28 = F_10 ( V_25 , V_289 , & V_287 ) ;
if ( V_28 ) {
F_17 ( L_113 , V_28 ) ;
} else {
V_284 -> V_290 |= V_291 ;
V_284 -> V_292 . V_293 = V_287 * 5 ;
F_51 ( L_114 , V_287 / 2 ) ;
}
if ( F_6 ( V_249 , & V_9 -> V_12 ) ) {
V_285 . V_67 = F_11 ( 0 ) ;
V_28 = F_12 ( V_25 , V_294 , & V_285 ,
sizeof( struct V_247 ) ) ;
if ( V_28 )
F_17 ( L_115 , V_28 ) ;
V_286 = F_13 ( V_285 . V_67 ) ;
V_284 -> V_290 |= V_295 ;
V_284 -> signal = V_286 ;
F_51 ( L_116 , V_286 ) ;
}
V_61:
F_19 ( L_9 ) ;
return V_28 ;
}
static T_6
F_76 ( struct V_10 * V_10 , struct V_24 * V_25 ,
bool V_296 , T_6 V_297 )
{
T_6 V_298 ;
T_6 V_28 = 0 ;
struct V_5 * V_9 = F_5 ( V_10 ) ;
F_19 ( L_3 ) ;
V_9 -> V_299 = V_296 ;
if ( ! F_6 ( V_11 , & V_9 -> V_12 ) ) {
F_7 ( L_117
L_118 ) ;
goto V_61;
}
V_298 = V_296 ? V_300 : V_301 ;
F_7 ( L_119 , ( V_298 ? L_120 : L_121 ) ) ;
V_28 = F_10 ( V_25 , V_302 , & V_298 ) ;
if ( V_28 ) {
if ( V_28 == - V_303 )
F_17 ( L_122 ) ;
else
F_17 ( L_10 , V_28 ) ;
}
V_61:
F_19 ( L_9 ) ;
return V_28 ;
}
static T_6
F_77 ( struct V_10 * V_10 , struct V_24 * V_25 ,
const T_2 * V_304 ,
const struct V_305 * V_306 )
{
struct V_307 V_308 ;
T_6 V_287 ;
T_6 V_67 ;
T_6 V_309 ;
T_6 V_310 ;
T_4 V_293 ;
T_6 V_28 = 0 ;
F_19 ( L_3 ) ;
if ( ! F_4 ( V_10 ) )
return - V_50 ;
V_28 = F_12 ( V_25 , V_311 , & V_308 ,
sizeof( V_308 ) ) ;
if ( V_28 ) {
F_17 ( L_123 , V_28 ) ;
goto V_61;
}
V_293 = F_78 ( V_306 -> V_312 [ V_313 ] . V_293 & 0xFFFF ) ;
if ( ! V_293 )
V_293 = F_78 ( V_306 -> V_312 [ V_314 ] . V_293 &
0xFFFF ) ;
V_67 = V_315 [ V_293 - 1 ] . V_316 * 100000 ;
if ( V_67 < F_13 ( V_308 . V_317 ) )
V_287 = V_308 . V_318 [ V_67 ] & 0x7f ;
else
V_287 = V_67 / 500000 ;
F_51 ( L_124 , V_287 / 2 ) ;
V_309 = F_20 ( V_25 , L_125 , V_287 ) ;
V_310 = F_20 ( V_25 , L_126 , V_287 ) ;
if ( V_309 && V_310 ) {
F_17 ( L_127 , V_309 , V_310 ) ;
V_28 = V_309 | V_310 ;
}
V_61:
F_19 ( L_9 ) ;
return V_28 ;
}
static T_6 F_79 ( struct V_5 * V_9 ,
struct V_319 * V_320 )
{
struct V_10 * V_10 = F_80 ( V_9 ) ;
struct V_243 * V_321 ;
struct V_322 * V_323 ;
struct V_324 * V_325 ;
T_6 V_28 = 0 ;
T_1 V_190 ;
T_4 V_326 ;
T_1 V_327 ;
T_1 V_328 ;
T_2 * V_329 ;
T_8 V_330 ;
T_6 V_331 ;
if ( F_13 ( V_320 -> V_332 ) > V_333 ) {
F_17 ( L_128 ) ;
return 0 ;
}
V_190 = V_320 -> V_334 ? V_320 -> V_334 :
F_81 ( F_82 ( V_320 -> V_175 ) ) ;
if ( V_190 <= V_176 )
V_325 = V_10 -> V_335 [ V_313 ] ;
else
V_325 = V_10 -> V_335 [ V_314 ] ;
V_326 = F_83 ( V_190 , V_325 -> V_325 ) ;
V_321 = F_84 ( V_10 , V_326 ) ;
V_327 = F_82 ( V_320 -> V_336 ) ;
V_328 = F_82 ( V_320 -> V_337 ) ;
V_329 = ( T_2 * ) V_320 + F_82 ( V_320 -> V_338 ) ;
V_330 = F_13 ( V_320 -> V_339 ) ;
V_331 = ( V_340 ) F_82 ( V_320 -> V_341 ) * 100 ;
F_51 ( L_129 ,
V_320 -> V_342 [ 0 ] , V_320 -> V_342 [ 1 ] , V_320 -> V_342 [ 2 ] ,
V_320 -> V_342 [ 3 ] , V_320 -> V_342 [ 4 ] , V_320 -> V_342 [ 5 ] ) ;
F_51 ( L_130 , V_190 , V_326 ) ;
F_51 ( L_131 , V_327 ) ;
F_51 ( L_132 , V_328 ) ;
F_51 ( L_133 , V_331 ) ;
V_323 = F_85 ( V_10 , V_321 , ( const T_2 * ) V_320 -> V_342 ,
0 , V_327 , V_328 , V_329 ,
V_330 , V_331 , V_106 ) ;
if ( ! V_323 )
return - V_107 ;
F_86 ( V_323 ) ;
return V_28 ;
}
static struct V_319 *
F_87 ( struct V_343 * V_344 , struct V_319 * V_323 )
{
if ( V_323 == NULL )
return V_344 -> V_345 ;
return (struct V_319 * ) ( ( unsigned long ) V_323 +
F_13 ( V_323 -> V_332 ) ) ;
}
static T_6 F_88 ( struct V_5 * V_9 )
{
struct V_343 * V_346 ;
struct V_319 * V_320 = NULL ;
T_6 V_28 = 0 ;
int V_347 ;
V_346 = V_9 -> V_346 ;
if ( V_346 -> V_108 != V_348 ) {
F_17 ( L_134 ,
V_346 -> V_108 ) ;
return - V_53 ;
}
F_39 ( L_135 , V_346 -> V_317 ) ;
for ( V_347 = 0 ; V_347 < V_346 -> V_317 && V_347 < V_349 ; V_347 ++ ) {
V_320 = F_87 ( V_346 , V_320 ) ;
V_28 = F_79 ( V_9 , V_320 ) ;
if ( V_28 )
break;
}
return V_28 ;
}
static T_6 F_89 ( struct V_5 * V_9 ,
struct V_24 * V_25 , const T_2 * V_81 )
{
struct V_10 * V_10 = F_80 ( V_9 ) ;
struct V_243 * V_321 ;
struct V_319 * V_320 = NULL ;
struct V_324 * V_325 ;
struct V_322 * V_323 ;
T_2 * V_68 = NULL ;
T_6 V_28 = 0 ;
T_1 V_190 ;
T_4 V_326 ;
T_1 V_327 ;
T_1 V_328 ;
T_2 * V_329 ;
T_8 V_330 ;
T_6 V_331 ;
F_19 ( L_3 ) ;
V_68 = F_31 ( V_333 , V_106 ) ;
if ( V_68 == NULL ) {
V_28 = - V_107 ;
goto V_350;
}
* ( T_5 * ) V_68 = F_11 ( V_333 ) ;
V_28 = F_12 ( V_25 , V_351 , V_68 , V_333 ) ;
if ( V_28 ) {
F_17 ( L_136 , V_28 ) ;
goto V_350;
}
V_320 = (struct V_319 * ) ( V_68 + 4 ) ;
V_190 = V_320 -> V_334 ? V_320 -> V_334 :
F_81 ( F_82 ( V_320 -> V_175 ) ) ;
if ( V_190 <= V_176 )
V_325 = V_10 -> V_335 [ V_313 ] ;
else
V_325 = V_10 -> V_335 [ V_314 ] ;
V_326 = F_83 ( V_190 , V_325 -> V_325 ) ;
V_321 = F_84 ( V_10 , V_326 ) ;
V_327 = F_82 ( V_320 -> V_336 ) ;
V_328 = F_82 ( V_320 -> V_337 ) ;
V_329 = ( T_2 * ) V_320 + F_82 ( V_320 -> V_338 ) ;
V_330 = F_13 ( V_320 -> V_339 ) ;
V_331 = ( V_340 ) F_82 ( V_320 -> V_341 ) * 100 ;
F_51 ( L_137 , V_190 , V_326 ) ;
F_51 ( L_138 , V_327 ) ;
F_51 ( L_46 , V_328 ) ;
F_51 ( L_139 , V_331 ) ;
V_323 = F_85 ( V_10 , V_321 , V_81 ,
0 , V_327 , V_328 ,
V_329 , V_330 , V_331 , V_106 ) ;
if ( ! V_323 ) {
V_28 = - V_107 ;
goto V_350;
}
F_86 ( V_323 ) ;
V_350:
F_32 ( V_68 ) ;
F_19 ( L_9 ) ;
return V_28 ;
}
static bool F_90 ( struct V_5 * V_9 )
{
return V_9 -> V_55 -> V_56 == V_57 ;
}
static struct V_352 * F_91 ( void * V_68 , int V_98 , T_3 V_31 )
{
struct V_352 * V_353 ;
int V_354 ;
V_353 = (struct V_352 * ) V_68 ;
V_354 = V_98 ;
while ( V_354 >= 2 ) {
int V_35 = V_353 -> V_35 ;
if ( ( V_353 -> V_355 == V_31 ) && ( V_354 >= ( V_35 + 2 ) ) )
return V_353 ;
V_353 = (struct V_352 * ) ( ( T_2 * ) V_353 + ( V_35 + 2 ) ) ;
V_354 -= ( V_35 + 2 ) ;
}
return NULL ;
}
static T_6 F_92 ( struct V_5 * V_9 )
{
struct V_319 * V_320 ;
struct V_79 * V_80 ;
struct V_352 * V_356 ;
T_1 V_166 ;
T_2 V_168 ;
T_8 V_194 ;
T_2 * V_193 ;
T_6 V_28 = 0 ;
F_19 ( L_3 ) ;
if ( F_90 ( V_9 ) )
return V_28 ;
V_80 = (struct V_79 * ) F_47 ( V_9 , V_162 ) ;
* ( T_5 * ) V_9 -> V_357 = F_11 ( V_358 ) ;
V_28 = F_12 ( F_35 ( V_9 ) , V_351 ,
V_9 -> V_357 , V_358 ) ;
if ( V_28 ) {
F_17 ( L_140 , V_28 ) ;
goto V_359;
}
V_320 = (struct V_319 * ) ( V_9 -> V_357 + 4 ) ;
V_28 = F_79 ( V_9 , V_320 ) ;
if ( V_28 )
goto V_359;
V_193 = ( ( T_2 * ) V_320 ) + F_82 ( V_320 -> V_338 ) ;
V_194 = F_13 ( V_320 -> V_339 ) ;
V_166 = F_82 ( V_320 -> V_337 ) ;
V_356 = F_91 ( V_193 , V_194 , V_360 ) ;
if ( V_356 )
V_168 = V_356 -> V_3 [ 1 ] ;
else {
T_4 V_73 ;
V_28 = F_23 ( F_35 ( V_9 ) ,
L_141 , & V_73 ) ;
if ( V_28 ) {
F_17 ( L_142 , V_28 ) ;
goto V_359;
}
V_168 = ( T_2 ) V_73 ;
}
F_48 ( V_9 , NULL , & V_166 , V_165 ) ;
F_48 ( V_9 , NULL , & V_168 , V_167 ) ;
V_359:
F_19 ( L_104 ) ;
return V_28 ;
}
static void F_93 ( struct V_5 * V_9 )
{
struct V_100 * V_101 = F_34 ( V_9 ) ;
struct V_79 V_80 ;
if ( V_9 -> V_138 ) {
V_101 -> V_114 = V_361 ;
if ( V_101 -> V_124 ) {
F_94 ( & V_101 -> V_120 ) ;
V_101 -> V_124 = 0 ;
}
F_95 ( & V_101 -> V_362 ) ;
memset ( & V_80 , 0 , sizeof( V_80 ) ) ;
F_29 ( V_101 , & V_80 , V_363 ) ;
}
}
static void F_96 ( struct V_100 * V_101 ,
bool V_364 )
{
struct V_5 * V_9 = F_97 ( V_101 ) ;
struct V_24 * V_25 = F_35 ( V_9 ) ;
if ( ! F_98 ( V_135 , & V_9 -> V_12 ) ) {
F_17 ( L_143 ) ;
return;
}
if ( V_9 -> V_140 ) {
F_39 ( L_144 ,
V_364 ? L_145 : L_146 ) ;
F_99 ( V_9 -> V_140 , V_364 ) ;
F_24 ( V_25 , 1 ) ;
V_9 -> V_140 = NULL ;
}
V_9 -> V_118 = false ;
}
static T_6 F_100 ( struct V_100 * V_101 )
{
if ( V_101 -> V_114 != V_361 ) {
F_39 ( L_147 ) ;
F_101 ( & V_101 -> V_362 ) ;
return 0 ;
}
return - V_50 ;
}
static T_6
F_102 ( struct V_100 * V_101 , T_4 * V_12 ,
struct V_343 * * V_346 )
{
struct V_365 V_344 ;
struct V_343 * V_366 ;
struct V_367 * V_368 ;
struct V_365 * V_369 ;
T_6 V_28 = 0 ;
memset ( V_101 -> V_370 , 0 , V_371 ) ;
V_369 = (struct V_365 * ) V_101 -> V_370 ;
V_366 = & V_369 -> V_366 ;
V_368 = & V_369 -> V_368 ;
V_366 -> V_98 = V_372 ;
V_366 -> V_108 = 0 ;
V_366 -> V_317 = 0 ;
memset ( & V_344 , 0 , sizeof( V_344 ) ) ;
V_344 . V_368 . V_98 = F_11 ( V_371 ) ;
V_28 = F_28 ( V_101 -> V_25 , L_148 , & V_344 ,
V_372 ,
V_101 -> V_370 , V_371 ) ;
if ( V_28 ) {
F_17 ( L_10 , V_28 ) ;
return V_28 ;
}
V_366 -> V_98 = F_13 ( V_368 -> V_98 ) ;
V_366 -> V_108 = F_13 ( V_368 -> V_108 ) ;
V_366 -> V_317 = F_13 ( V_368 -> V_317 ) ;
F_39 ( L_149 , V_368 -> V_317 ) ;
F_39 ( L_150 , V_368 -> V_98 ) ;
* V_12 = F_13 ( V_369 -> V_373 ) ;
F_39 ( L_151 , * V_12 ) ;
* V_346 = V_366 ;
return V_28 ;
}
static T_6 F_103 ( struct V_5 * V_9 )
{
struct V_100 * V_101 = V_9 -> V_101 ;
T_6 V_28 = 0 ;
V_101 -> V_114 = V_361 ;
F_88 ( V_9 ) ;
F_96 ( V_101 , false ) ;
return V_28 ;
}
static T_6 F_104 ( struct V_5 * V_9 )
{
struct V_100 * V_101 = V_9 -> V_101 ;
T_6 V_28 = 0 ;
F_36 ( & V_101 -> V_120 , V_121 + V_101 -> V_122 * V_123 / 1000 ) ;
V_101 -> V_124 = 1 ;
return V_28 ;
}
static T_6 F_105 ( struct V_5 * V_9 )
{
struct V_100 * V_101 = V_9 -> V_101 ;
T_6 V_28 = 0 ;
F_88 ( V_9 ) ;
F_29 ( V_101 , NULL , V_374 ) ;
F_36 ( & V_101 -> V_120 , V_121 + V_101 -> V_122 * V_123 / 1000 ) ;
V_101 -> V_124 = 1 ;
return V_28 ;
}
static T_6 F_106 ( struct V_5 * V_9 )
{
struct V_100 * V_101 = V_9 -> V_101 ;
T_6 V_28 = 0 ;
V_101 -> V_114 = V_361 ;
F_96 ( V_101 , true ) ;
return V_28 ;
}
static void F_107 ( struct V_375 * V_362 )
{
struct V_100 * V_101 =
F_108 ( V_362 , struct V_100 ,
V_362 ) ;
struct V_5 * V_9 = F_97 ( V_101 ) ;
struct V_376 * V_377 = & V_101 -> V_377 ;
T_4 V_12 = V_378 ;
if ( V_101 -> V_124 ) {
F_94 ( & V_101 -> V_120 ) ;
V_101 -> V_124 = 0 ;
}
if ( F_102 ( V_101 , & V_12 , & V_9 -> V_346 ) ) {
V_12 = V_379 ;
F_17 ( L_152 ) ;
}
V_377 -> V_380 [ V_12 ] ( V_9 ) ;
}
static void F_109 ( unsigned long V_3 )
{
struct V_100 * V_101 =
(struct V_100 * ) V_3 ;
if ( V_101 ) {
V_101 -> V_124 = 0 ;
F_39 ( L_153 ) ;
F_100 ( V_101 ) ;
}
}
static T_6 F_110 ( struct V_5 * V_9 )
{
struct V_100 * V_101 = F_34 ( V_9 ) ;
if ( V_9 -> V_138 ) {
V_101 -> V_114 = V_361 ;
F_111 ( & V_101 -> V_362 , F_107 ) ;
}
return 0 ;
}
static void F_112 ( struct V_376 * V_377 )
{
memset ( V_377 , 0 , sizeof( * V_377 ) ) ;
V_377 -> V_380 [ V_381 ] = F_103 ;
V_377 -> V_380 [ V_378 ] = F_105 ;
V_377 -> V_380 [ V_382 ] = F_104 ;
V_377 -> V_380 [ V_379 ] = F_106 ;
V_377 -> V_380 [ V_383 ] = F_106 ;
}
static T_6 F_113 ( struct V_5 * V_9 )
{
struct V_100 * V_101 = F_34 ( V_9 ) ;
int V_28 = 0 ;
if ( V_9 -> V_138 ) {
V_101 -> V_25 = F_35 ( V_9 ) ;
F_112 ( & V_101 -> V_377 ) ;
V_101 -> V_122 = V_384 ;
F_114 ( & V_101 -> V_120 ) ;
V_101 -> V_120 . V_3 = ( unsigned long ) V_101 ;
V_101 -> V_120 . V_385 = F_109 ;
V_28 = F_110 ( V_9 ) ;
if ( ! V_28 )
V_101 -> V_3 = V_9 ;
}
return V_28 ;
}
static T_9 void F_115 ( T_4 V_386 )
{
if ( V_386 < 1000 / V_123 ) {
F_116 () ;
F_117 ( V_386 ) ;
} else {
F_118 ( V_386 ) ;
}
}
static T_6 F_119 ( struct V_10 * V_10 )
{
struct V_5 * V_9 = F_5 ( V_10 ) ;
F_19 ( L_3 ) ;
if ( F_6 ( V_11 , & V_9 -> V_12 ) )
F_110 ( F_5 ( V_10 ) ) ;
F_19 ( L_9 ) ;
return 0 ;
}
static T_6 F_120 ( struct V_10 * V_10 ,
struct V_387 * V_388 )
{
struct V_5 * V_9 = F_5 ( V_10 ) ;
struct V_24 * V_25 = F_35 ( V_9 ) ;
F_19 ( L_3 ) ;
if ( ( F_6 ( V_249 , & V_9 -> V_12 ) ||
F_6 ( V_137 , & V_9 -> V_12 ) ) &&
F_6 ( V_11 , & V_9 -> V_12 ) ) {
F_7 ( L_154
L_155 ) ;
F_52 ( V_9 ) ;
F_115 ( 500 ) ;
}
F_38 ( V_136 , & V_9 -> V_12 ) ;
if ( F_6 ( V_11 , & V_9 -> V_12 ) )
F_93 ( V_9 ) ;
if ( V_9 -> V_140 ) {
F_7 ( L_156 ) ;
F_99 ( V_9 -> V_140 , true ) ;
V_9 -> V_140 = NULL ;
}
F_41 ( V_135 , & V_9 -> V_12 ) ;
F_41 ( V_136 , & V_9 -> V_12 ) ;
if ( F_6 ( V_11 , & V_9 -> V_12 ) ) {
F_7 ( L_157 ) ;
F_24 ( V_25 , 1 ) ;
}
F_19 ( L_9 ) ;
return 0 ;
}
static T_10 T_6
F_121 ( struct V_24 * V_25 , T_7 * V_66 , T_7 * V_68 , T_6 V_35 )
{
struct V_5 * V_9 = F_25 ( V_25 ) ;
T_4 V_98 ;
V_98 = F_21 ( V_66 , V_68 , V_35 , V_9 -> V_111 ,
V_389 ) ;
F_22 ( ! V_98 ) ;
return F_12 ( V_25 , V_71 , V_9 -> V_111 ,
V_98 ) ;
}
static T_6
F_122 ( struct V_24 * V_25 , T_7 * V_66 , T_7 * V_68 ,
T_6 V_390 )
{
struct V_5 * V_9 = F_25 ( V_25 ) ;
T_4 V_35 ;
T_6 V_28 = 0 ;
V_35 = F_21 ( V_66 , NULL , 0 , V_9 -> V_111 ,
V_389 ) ;
F_22 ( ! V_35 ) ;
V_28 = F_12 ( V_25 , V_75 , V_9 -> V_111 ,
V_389 ) ;
if ( V_28 ) {
F_17 ( L_10 , V_28 ) ;
return V_28 ;
}
memcpy ( V_68 , V_9 -> V_111 , V_390 ) ;
return V_28 ;
}
static T_10 T_6
F_123 ( struct V_24 * V_25 ,
struct V_391 * V_392 , T_6 V_28 )
{
int V_347 , V_393 ;
int V_394 ;
V_394 = F_13 ( V_392 -> V_395 . V_396 ) ;
F_51 ( L_158 , V_394 ) ;
for ( V_347 = 0 ; V_347 < V_394 ; V_347 ++ ) {
F_51 ( L_159 , V_347 ,
& V_392 -> V_395 . V_397 [ V_347 ] . V_342 ) ;
for ( V_393 = 0 ; V_393 < V_398 ; V_393 ++ )
F_51 ( L_160 , V_392 -> V_395 . V_397 [ V_347 ] . V_399 [ V_393 ] ) ;
}
if ( ! V_28 )
F_121 ( V_25 , L_161 , ( char * ) V_392 ,
sizeof( * V_392 ) ) ;
return V_28 ;
}
static T_6
F_124 ( struct V_10 * V_10 , struct V_24 * V_25 ,
struct V_400 * V_401 )
{
struct V_5 * V_9 = F_5 ( V_10 ) ;
struct V_402 * V_395 = & V_9 -> V_392 -> V_395 ;
T_6 V_28 = 0 ;
int V_347 ;
int V_394 ;
F_19 ( L_3 ) ;
if ( ! F_4 ( V_10 ) )
return - V_50 ;
V_394 = F_13 ( V_395 -> V_396 ) ;
for ( V_347 = 0 ; V_347 < V_394 ; V_347 ++ )
if ( ! memcmp ( V_401 -> V_81 , V_395 -> V_397 [ V_347 ] . V_342 , V_83 ) )
break;
if ( V_347 < V_403 ) {
memcpy ( V_395 -> V_397 [ V_347 ] . V_342 , V_401 -> V_81 , V_83 ) ;
memcpy ( V_395 -> V_397 [ V_347 ] . V_399 , V_401 -> V_397 , V_398 ) ;
if ( V_347 == V_394 ) {
V_394 ++ ;
V_395 -> V_396 = F_11 ( V_394 ) ;
}
} else
V_28 = - V_60 ;
F_51 ( L_162 ,
V_395 -> V_397 [ V_394 ] . V_342 ) ;
for ( V_347 = 0 ; V_347 < V_398 ; V_347 ++ )
F_51 ( L_160 , V_395 -> V_397 [ V_394 ] . V_399 [ V_347 ] ) ;
V_28 = F_123 ( V_25 , V_9 -> V_392 , V_28 ) ;
F_19 ( L_9 ) ;
return V_28 ;
}
static T_6
F_125 ( struct V_10 * V_10 , struct V_24 * V_25 ,
struct V_400 * V_401 )
{
struct V_5 * V_9 = F_5 ( V_10 ) ;
struct V_402 V_397 ;
T_6 V_28 = 0 ;
int V_347 , V_394 ;
F_19 ( L_3 ) ;
if ( ! F_4 ( V_10 ) )
return - V_50 ;
memcpy ( & V_397 . V_397 [ 0 ] . V_342 , V_401 -> V_81 , V_83 ) ;
memcpy ( & V_397 . V_397 [ 0 ] . V_399 , V_401 -> V_397 , V_398 ) ;
F_51 ( L_163 ,
& V_397 . V_397 [ 0 ] . V_342 ) ;
for ( V_347 = 0 ; V_347 < V_398 ; V_347 ++ )
F_51 ( L_160 , V_397 . V_397 [ 0 ] . V_399 [ V_347 ] ) ;
V_394 = F_13 ( V_9 -> V_392 -> V_395 . V_396 ) ;
for ( V_347 = 0 ; V_347 < V_394 ; V_347 ++ )
if ( ! memcmp
( V_401 -> V_81 , & V_9 -> V_392 -> V_395 . V_397 [ V_347 ] . V_342 ,
V_83 ) )
break;
if ( ( V_394 > 0 )
&& ( V_347 < V_394 ) ) {
memset ( & V_9 -> V_392 -> V_395 . V_397 [ V_347 ] , 0 ,
sizeof( struct V_397 ) ) ;
for (; V_347 < ( V_394 - 1 ) ; V_347 ++ ) {
memcpy ( & V_9 -> V_392 -> V_395 . V_397 [ V_347 ] . V_342 ,
& V_9 -> V_392 -> V_395 . V_397 [ V_347 + 1 ] . V_342 ,
V_83 ) ;
memcpy ( & V_9 -> V_392 -> V_395 . V_397 [ V_347 ] . V_399 ,
& V_9 -> V_392 -> V_395 . V_397 [ V_347 + 1 ] . V_399 ,
V_398 ) ;
}
V_9 -> V_392 -> V_395 . V_396 = F_11 ( V_394 - 1 ) ;
} else
V_28 = - V_60 ;
V_28 = F_123 ( V_25 , V_9 -> V_392 , V_28 ) ;
F_19 ( L_9 ) ;
return V_28 ;
}
static T_6
F_126 ( struct V_10 * V_10 , struct V_24 * V_25 )
{
struct V_5 * V_9 = F_5 ( V_10 ) ;
T_6 V_28 = 0 ;
F_19 ( L_3 ) ;
if ( ! F_4 ( V_10 ) )
return - V_50 ;
memset ( V_9 -> V_392 , 0 , sizeof( * V_9 -> V_392 ) ) ;
V_28 = F_123 ( V_25 , V_9 -> V_392 , V_28 ) ;
F_19 ( L_9 ) ;
return V_28 ;
}
static T_6 F_127 ( T_6 V_56 )
{
T_6 V_28 = 0 ;
switch ( V_56 ) {
case V_59 :
return V_58 ;
case V_57 :
return V_54 ;
default:
return V_404 ;
}
return V_28 ;
}
static struct V_47 * F_128 ( T_6 V_405 ,
struct V_406 * V_25 )
{
struct V_47 * V_48 ;
T_6 V_28 = 0 ;
V_48 = F_31 ( sizeof( * V_48 ) , V_106 ) ;
if ( ! V_48 )
return F_129 ( - V_107 ) ;
V_48 -> V_10 =
F_130 ( & V_407 ,
sizeof( struct V_5 ) + V_405 ) ;
if ( ! V_48 -> V_10 ) {
F_17 ( L_164 ) ;
V_28 = - V_107 ;
goto V_408;
}
F_131 ( V_48 -> V_10 , V_25 ) ;
V_48 -> V_10 -> V_409 = V_410 ;
V_48 -> V_10 -> V_411 = V_403 ;
V_48 -> V_10 -> V_412 =
F_132 ( V_58 ) | F_132 ( V_54 ) ;
V_48 -> V_10 -> V_335 [ V_313 ] = & V_413 ;
V_48 -> V_10 -> V_335 [ V_314 ] = & V_414 ;
V_48 -> V_10 -> V_415 = V_416 ;
V_48 -> V_10 -> V_417 = V_418 ;
V_48 -> V_10 -> V_419 = F_133 ( V_418 ) ;
V_48 -> V_10 -> V_37 |= V_420 ;
V_28 = F_134 ( V_48 -> V_10 ) ;
if ( V_28 < 0 ) {
F_17 ( L_165 , V_28 ) ;
goto V_421;
}
return V_48 ;
V_421:
F_135 ( V_48 -> V_10 ) ;
V_408:
F_32 ( V_48 ) ;
return F_129 ( V_28 ) ;
}
static void F_136 ( struct V_5 * V_9 )
{
struct V_47 * V_48 = V_9 -> V_48 ;
if ( ! V_48 ) {
F_17 ( L_166 ) ;
return;
}
F_137 ( V_48 -> V_10 ) ;
F_135 ( V_48 -> V_10 ) ;
F_32 ( V_48 ) ;
V_9 -> V_48 = NULL ;
}
static bool F_138 ( struct V_5 * V_9 ,
const struct V_163 * V_164 )
{
T_4 V_422 = F_139 ( V_164 -> V_423 ) ;
T_4 V_12 = F_139 ( V_164 -> V_12 ) ;
if ( V_422 == V_424 && V_12 == V_425 ) {
F_51 ( L_167 ) ;
V_9 -> V_185 = true ;
return true ;
}
return false ;
}
static bool F_140 ( struct V_5 * V_9 ,
const struct V_163 * V_164 )
{
T_4 V_422 = F_139 ( V_164 -> V_423 ) ;
T_1 V_37 = F_141 ( V_164 -> V_37 ) ;
if ( V_422 == V_426 && ( ! ( V_37 & V_427 ) ) ) {
F_51 ( L_168 ) ;
return true ;
}
return false ;
}
static bool F_142 ( struct V_5 * V_9 ,
const struct V_163 * V_164 )
{
T_4 V_422 = F_139 ( V_164 -> V_423 ) ;
T_4 V_12 = F_139 ( V_164 -> V_12 ) ;
if ( V_422 == V_426 && V_12 == V_428 ) {
F_51 ( L_169 ,
F_141 ( V_164 -> V_37 ) & V_427 ?
L_170 : L_171 ) ;
return true ;
}
if ( V_422 == V_424 && V_12 != V_425 ) {
F_51 ( L_172 ) ;
return true ;
}
return false ;
}
static void F_143 ( struct V_5 * V_9 )
{
struct V_429 * V_430 = F_144 ( V_9 ) ;
F_32 ( V_430 -> V_431 ) ;
V_430 -> V_431 = NULL ;
V_430 -> V_432 = 0 ;
F_32 ( V_430 -> V_433 ) ;
V_430 -> V_433 = NULL ;
V_430 -> V_434 = 0 ;
}
static T_6 F_145 ( struct V_5 * V_9 )
{
struct V_24 * V_25 = F_35 ( V_9 ) ;
struct V_435 * V_436 ;
struct V_429 * V_430 = F_144 ( V_9 ) ;
T_4 V_437 ;
T_4 V_438 ;
T_6 V_28 = 0 ;
F_143 ( V_9 ) ;
V_28 = F_122 ( V_25 , L_173 , V_9 -> V_357 ,
V_439 ) ;
if ( V_28 ) {
F_17 ( L_174 , V_28 ) ;
return V_28 ;
}
V_436 =
(struct V_435 * ) V_9 -> V_357 ;
V_437 = F_13 ( V_436 -> V_437 ) ;
V_438 = F_13 ( V_436 -> V_438 ) ;
if ( V_437 ) {
V_28 = F_122 ( V_25 , L_175 ,
V_9 -> V_357 ,
V_439 ) ;
if ( V_28 ) {
F_17 ( L_176 , V_28 ) ;
return V_28 ;
}
V_430 -> V_432 = V_437 ;
V_430 -> V_431 =
F_146 ( V_9 -> V_357 , V_430 -> V_432 ,
V_106 ) ;
} else {
V_430 -> V_432 = 0 ;
V_430 -> V_431 = NULL ;
}
if ( V_438 ) {
V_28 = F_122 ( V_25 , L_177 ,
V_9 -> V_357 ,
V_439 ) ;
if ( V_28 ) {
F_17 ( L_178 , V_28 ) ;
return V_28 ;
}
V_430 -> V_434 = V_438 ;
V_430 -> V_433 =
F_146 ( V_9 -> V_357 , V_430 -> V_434 ,
V_106 ) ;
} else {
V_430 -> V_434 = 0 ;
V_430 -> V_433 = NULL ;
}
F_51 ( L_179 ,
V_430 -> V_432 , V_430 -> V_434 ) ;
return V_28 ;
}
static T_6
F_147 ( struct V_5 * V_9 ,
struct V_24 * V_25 ,
const struct V_163 * V_164 )
{
struct V_429 * V_430 = F_144 ( V_9 ) ;
struct V_10 * V_10 = F_80 ( V_9 ) ;
struct V_440 V_441 ;
struct V_243 * V_321 ;
struct V_324 * V_325 ;
T_4 V_326 ;
T_6 V_28 = 0 ;
T_4 V_199 ;
F_19 ( L_3 ) ;
F_145 ( V_9 ) ;
F_48 ( V_9 , NULL , & V_164 -> V_304 , V_161 ) ;
F_92 ( V_9 ) ;
F_12 ( V_25 , V_442 , & V_441 ,
sizeof( V_441 ) ) ;
V_199 = F_13 ( V_441 . V_199 ) ;
F_51 ( L_180 , V_199 ) ;
if ( V_199 <= V_176 )
V_325 = V_10 -> V_335 [ V_313 ] ;
else
V_325 = V_10 -> V_335 [ V_314 ] ;
V_326 = F_83 ( V_199 , V_325 -> V_325 ) ;
V_321 = F_84 ( V_10 , V_326 ) ;
F_148 ( V_25 , V_321 ,
( T_2 * ) F_47 ( V_9 , V_161 ) ,
V_430 -> V_431 , V_430 -> V_432 ,
V_430 -> V_433 , V_430 -> V_434 , V_106 ) ;
F_51 ( L_181 ) ;
F_38 ( V_249 , & V_9 -> V_12 ) ;
F_19 ( L_9 ) ;
return V_28 ;
}
static T_6
F_149 ( struct V_5 * V_9 ,
struct V_24 * V_25 , const struct V_163 * V_164 ,
bool V_443 )
{
struct V_429 * V_430 = F_144 ( V_9 ) ;
T_6 V_28 = 0 ;
F_19 ( L_3 ) ;
if ( F_98 ( V_137 , & V_9 -> V_12 ) ) {
if ( V_443 ) {
F_145 ( V_9 ) ;
F_48 ( V_9 , NULL , & V_164 -> V_304 ,
V_161 ) ;
F_92 ( V_9 ) ;
}
F_150 ( V_25 ,
( T_2 * ) F_47 ( V_9 ,
V_161 ) ,
V_430 -> V_431 ,
V_430 -> V_432 ,
V_430 -> V_433 ,
V_430 -> V_434 ,
V_443 ? V_444 :
V_445 ,
V_106 ) ;
if ( V_443 )
F_38 ( V_249 , & V_9 -> V_12 ) ;
F_51 ( L_182 ,
V_443 ? L_183 : L_184 ) ;
}
F_19 ( L_9 ) ;
return V_28 ;
}
static T_6
F_151 ( struct V_5 * V_9 ,
struct V_24 * V_25 ,
const struct V_163 * V_164 , void * V_3 )
{
T_6 V_28 = 0 ;
if ( F_138 ( V_9 , V_164 ) ) {
F_51 ( L_185 ) ;
if ( F_90 ( V_9 ) ) {
F_48 ( V_9 , NULL , ( void * ) V_164 -> V_304 ,
V_161 ) ;
F_89 ( V_9 , V_25 , V_164 -> V_304 ) ;
F_152 ( V_25 , V_164 -> V_304 , V_106 ) ;
F_41 ( V_137 , & V_9 -> V_12 ) ;
F_38 ( V_249 , & V_9 -> V_12 ) ;
} else
F_149 ( V_9 , V_25 , V_164 , true ) ;
} else if ( F_140 ( V_9 , V_164 ) ) {
F_51 ( L_186 ) ;
if ( F_90 ( V_9 ) ) {
F_41 ( V_137 , & V_9 -> V_12 ) ;
if ( F_98 ( V_249 ,
& V_9 -> V_12 ) )
F_52 ( V_9 ) ;
} else {
F_149 ( V_9 , V_25 , V_164 , false ) ;
if ( F_98 ( V_249 ,
& V_9 -> V_12 ) ) {
F_153 ( V_25 , 0 , NULL , 0 ,
V_106 ) ;
F_52 ( V_9 ) ;
}
}
F_49 ( V_9 -> V_159 ) ;
} else if ( F_142 ( V_9 , V_164 ) ) {
if ( F_90 ( V_9 ) )
F_41 ( V_137 , & V_9 -> V_12 ) ;
else
F_149 ( V_9 , V_25 , V_164 , false ) ;
}
return V_28 ;
}
static T_6
F_154 ( struct V_5 * V_9 ,
struct V_24 * V_25 ,
const struct V_163 * V_164 , void * V_3 )
{
T_6 V_28 = 0 ;
T_4 V_422 = F_139 ( V_164 -> V_423 ) ;
T_4 V_12 = F_139 ( V_164 -> V_12 ) ;
if ( V_422 == V_446 && V_12 == V_425 ) {
if ( F_6 ( V_249 , & V_9 -> V_12 ) )
F_147 ( V_9 , V_25 , V_164 ) ;
else
F_149 ( V_9 , V_25 , V_164 , true ) ;
}
return V_28 ;
}
static T_6
F_155 ( struct V_5 * V_9 ,
struct V_24 * V_25 ,
const struct V_163 * V_164 , void * V_3 )
{
T_1 V_37 = F_141 ( V_164 -> V_37 ) ;
enum V_447 V_448 ;
if ( V_37 & V_449 )
V_448 = V_450 ;
else
V_448 = V_451 ;
F_156 ( V_25 , ( T_2 * ) & V_164 -> V_304 , V_448 , - 1 ,
NULL , V_106 ) ;
return 0 ;
}
static T_6
F_157 ( struct V_5 * V_9 ,
struct V_24 * V_25 ,
const struct V_163 * V_164 , void * V_3 )
{
struct V_440 V_452 ;
struct V_367 * V_453 ;
T_4 V_35 = V_454 ;
T_6 V_28 = 0 ;
bool V_455 = false ;
T_4 V_456 ;
F_19 ( L_3 ) ;
if ( V_9 -> V_138 && V_9 -> V_118 ) {
F_19 ( L_9 ) ;
return F_100 ( F_34 ( V_9 ) ) ;
}
if ( ! F_98 ( V_135 , & V_9 -> V_12 ) ) {
F_17 ( L_143 ) ;
V_455 = true ;
V_28 = - V_60 ;
goto V_457;
}
V_28 = F_12 ( V_25 , V_442 , & V_452 ,
sizeof( V_452 ) ) ;
if ( V_28 ) {
F_17 ( L_187 , V_28 ) ;
V_455 = true ;
goto V_457;
}
V_456 = F_13 ( V_452 . V_456 ) ;
if ( V_456 )
F_51 ( L_188 , V_456 ) ;
V_9 -> V_346 = V_9 -> V_458 ;
V_453 = (struct V_367 * ) V_9 -> V_346 ;
memset ( V_9 -> V_458 , 0 , V_35 ) ;
V_453 -> V_98 = F_11 ( V_35 ) ;
V_28 = F_12 ( V_25 , V_459 ,
V_9 -> V_458 , V_35 ) ;
if ( V_28 ) {
F_17 ( L_189 , V_25 -> V_66 , V_28 ) ;
V_28 = - V_60 ;
V_455 = true ;
goto V_457;
}
V_9 -> V_458 -> V_98 = F_13 ( V_453 -> V_98 ) ;
V_9 -> V_458 -> V_108 = F_13 ( V_453 -> V_108 ) ;
V_9 -> V_458 -> V_317 = F_13 ( V_453 -> V_317 ) ;
V_28 = F_88 ( V_9 ) ;
if ( V_28 ) {
V_455 = true ;
goto V_457;
}
V_457:
if ( V_9 -> V_140 ) {
F_39 ( L_190 ) ;
F_99 ( V_9 -> V_140 , V_455 ) ;
F_24 ( V_25 , 1 ) ;
V_9 -> V_140 = NULL ;
}
F_19 ( L_9 ) ;
return V_28 ;
}
static void F_158 ( struct V_460 * V_55 )
{
V_55 -> V_56 = ( T_4 ) - 1 ;
V_55 -> V_145 = ( T_4 ) - 1 ;
V_55 -> V_144 = ( T_4 ) - 1 ;
V_55 -> V_156 = ( T_4 ) - 1 ;
V_55 -> V_154 = ( T_4 ) - 1 ;
V_55 -> V_260 = - 1 ;
}
static void F_159 ( struct V_461 * V_377 )
{
memset ( V_377 , 0 , sizeof( * V_377 ) ) ;
V_377 -> V_380 [ V_462 ] = F_157 ;
V_377 -> V_380 [ V_426 ] = F_151 ;
V_377 -> V_380 [ V_446 ] = F_154 ;
V_377 -> V_380 [ V_463 ] = F_155 ;
V_377 -> V_380 [ V_424 ] = F_151 ;
}
static void F_160 ( struct V_5 * V_9 )
{
F_32 ( V_9 -> V_458 ) ;
V_9 -> V_458 = NULL ;
F_32 ( V_9 -> V_464 ) ;
V_9 -> V_464 = NULL ;
F_32 ( V_9 -> V_55 ) ;
V_9 -> V_55 = NULL ;
F_32 ( V_9 -> V_159 ) ;
V_9 -> V_159 = NULL ;
F_32 ( V_9 -> V_132 ) ;
V_9 -> V_132 = NULL ;
F_32 ( V_9 -> V_111 ) ;
V_9 -> V_111 = NULL ;
F_32 ( V_9 -> V_357 ) ;
V_9 -> V_357 = NULL ;
F_32 ( V_9 -> V_101 ) ;
V_9 -> V_101 = NULL ;
F_32 ( V_9 -> V_392 ) ;
V_9 -> V_392 = NULL ;
}
static T_6 F_161 ( struct V_5 * V_9 )
{
V_9 -> V_458 = F_31 ( V_454 , V_106 ) ;
if ( ! V_9 -> V_458 )
goto V_465;
V_9 -> V_55 = F_31 ( sizeof( * V_9 -> V_55 ) , V_106 ) ;
if ( ! V_9 -> V_55 )
goto V_465;
V_9 -> V_159 = F_31 ( sizeof( * V_9 -> V_159 ) , V_106 ) ;
if ( ! V_9 -> V_159 )
goto V_465;
V_9 -> V_464 = F_31 ( V_333 , V_106 ) ;
if ( ! V_9 -> V_464 )
goto V_465;
V_9 -> V_132 = F_31 ( sizeof( * V_9 -> V_132 ) ,
V_106 ) ;
if ( ! V_9 -> V_132 )
goto V_465;
V_9 -> V_111 = F_31 ( V_389 , V_106 ) ;
if ( ! V_9 -> V_111 )
goto V_465;
V_9 -> V_357 = F_31 ( V_358 , V_106 ) ;
if ( ! V_9 -> V_357 )
goto V_465;
V_9 -> V_101 = F_31 ( sizeof( * V_9 -> V_101 ) , V_106 ) ;
if ( ! V_9 -> V_101 )
goto V_465;
V_9 -> V_392 = F_31 ( sizeof( * V_9 -> V_392 ) , V_106 ) ;
if ( ! V_9 -> V_392 )
goto V_465;
return 0 ;
V_465:
F_160 ( V_9 ) ;
return - V_107 ;
}
static struct V_466 * F_162 (
struct V_5 * V_9 )
{
struct V_466 * V_164 = NULL ;
F_163 ( & V_9 -> V_467 ) ;
if ( ! F_164 ( & V_9 -> V_468 ) ) {
V_164 = F_165 ( & V_9 -> V_468 ,
struct V_466 , V_468 ) ;
F_166 ( & V_164 -> V_468 ) ;
}
F_167 ( & V_9 -> V_467 ) ;
return V_164 ;
}
static T_6
F_168 ( struct V_5 * V_9 , T_4 V_422 ,
const struct V_163 * V_469 )
{
struct V_466 * V_164 ;
T_6 V_28 = 0 ;
T_11 V_37 ;
V_164 = F_31 ( sizeof( struct V_466 ) , V_470 ) ;
if ( ! V_164 )
return - V_107 ;
V_164 -> V_471 = V_422 ;
memcpy ( & V_164 -> V_472 , V_469 , sizeof( struct V_163 ) ) ;
F_169 ( & V_9 -> V_467 , V_37 ) ;
F_170 ( & V_164 -> V_468 , & V_9 -> V_468 ) ;
F_171 ( & V_9 -> V_467 , V_37 ) ;
return V_28 ;
}
static void F_172 ( struct V_466 * V_164 )
{
F_32 ( V_164 ) ;
}
static void F_173 ( struct V_375 * V_362 )
{
struct V_5 * V_9 =
F_108 ( V_362 , struct V_5 ,
V_473 ) ;
struct V_466 * V_164 ;
V_164 = F_162 ( V_9 ) ;
if ( F_174 ( ! V_164 ) ) {
F_17 ( L_191 ) ;
return;
}
do {
F_7 ( L_192 , V_164 -> V_471 ) ;
if ( V_9 -> V_377 . V_380 [ V_164 -> V_471 ] )
V_9 -> V_377 . V_380 [ V_164 -> V_471 ] ( V_9 ,
F_35 ( V_9 ) ,
& V_164 -> V_472 , V_164 -> V_474 ) ;
else
F_7 ( L_193 , V_164 -> V_471 ) ;
F_172 ( V_164 ) ;
} while ( ( V_164 = F_162 ( V_9 ) ) );
}
static void F_175 ( struct V_5 * V_9 )
{
F_176 ( & V_9 -> V_467 ) ;
F_177 ( & V_9 -> V_468 ) ;
}
static void F_178 ( struct V_5 * V_9 )
{
struct V_466 * V_164 ;
F_163 ( & V_9 -> V_467 ) ;
while ( ! F_164 ( & V_9 -> V_468 ) ) {
V_164 = F_165 ( & V_9 -> V_468 ,
struct V_466 , V_468 ) ;
F_166 ( & V_164 -> V_468 ) ;
F_32 ( V_164 ) ;
}
F_167 ( & V_9 -> V_467 ) ;
}
static T_6 F_179 ( struct V_5 * V_9 )
{
T_6 V_28 = 0 ;
V_9 -> V_140 = NULL ;
V_9 -> V_299 = true ;
V_9 -> V_138 = true ;
V_9 -> V_475 = true ;
V_9 -> V_118 = false ;
V_9 -> V_116 = true ;
V_9 -> V_476 = false ;
F_175 ( V_9 ) ;
V_28 = F_161 ( V_9 ) ;
if ( V_28 )
return V_28 ;
F_111 ( & V_9 -> V_473 , F_173 ) ;
F_159 ( & V_9 -> V_377 ) ;
F_180 ( & V_9 -> V_477 ) ;
V_28 = F_113 ( V_9 ) ;
if ( V_28 )
return V_28 ;
F_158 ( V_9 -> V_55 ) ;
F_49 ( V_9 -> V_159 ) ;
F_52 ( V_9 ) ;
return V_28 ;
}
static void F_181 ( struct V_5 * V_9 )
{
F_95 ( & V_9 -> V_473 ) ;
V_9 -> V_476 = false ;
F_178 ( V_9 ) ;
F_52 ( V_9 ) ;
F_93 ( V_9 ) ;
F_160 ( V_9 ) ;
}
struct V_1 * F_182 ( struct V_24 * V_25 ,
struct V_406 * V_478 ,
void * V_3 )
{
struct V_47 * V_48 ;
struct V_5 * V_9 ;
struct V_7 * V_8 ;
struct V_1 * V_6 ;
T_6 V_28 = 0 ;
if ( ! V_25 ) {
F_17 ( L_194 ) ;
return NULL ;
}
V_6 = F_31 ( sizeof( struct V_1 ) , V_106 ) ;
if ( ! V_6 )
return NULL ;
V_48 = F_128 ( sizeof( struct V_7 ) , V_478 ) ;
if ( F_183 ( V_48 ) ) {
F_32 ( V_6 ) ;
return NULL ;
}
V_48 -> V_65 = F_127 ( V_59 ) ;
V_9 = F_184 ( V_48 ) ;
V_9 -> V_48 = V_48 ;
V_9 -> V_479 = V_3 ;
V_8 = (struct V_7 * ) & V_9 -> V_8 ;
V_8 -> V_9 = V_9 ;
V_25 -> V_64 = V_48 ;
F_185 ( V_25 , F_186 ( V_48 -> V_10 ) ) ;
V_48 -> V_480 = V_25 ;
V_28 = F_179 ( V_9 ) ;
if ( V_28 ) {
F_17 ( L_195 , V_28 ) ;
goto V_481;
}
F_1 ( V_6 , V_8 ) ;
return V_6 ;
V_481:
F_136 ( V_9 ) ;
F_32 ( V_6 ) ;
return NULL ;
}
void F_187 ( struct V_1 * V_6 )
{
struct V_5 * V_9 ;
V_9 = F_3 ( V_6 ) ;
F_181 ( V_9 ) ;
F_136 ( V_9 ) ;
F_1 ( V_6 , NULL ) ;
F_32 ( V_6 ) ;
}
void
F_188 ( struct V_24 * V_25 ,
const struct V_163 * V_164 , void * V_3 )
{
T_4 V_423 = F_139 ( V_164 -> V_423 ) ;
struct V_5 * V_9 = F_25 ( V_25 ) ;
if ( ! F_168 ( V_9 , V_423 , V_164 ) )
F_101 ( & V_9 -> V_473 ) ;
}
static T_6 F_189 ( struct V_24 * V_25 , T_6 V_65 )
{
T_6 V_49 = 0 ;
T_6 V_28 = 0 ;
switch ( V_65 ) {
case V_51 :
case V_52 :
F_17 ( L_196 ,
V_65 ) ;
V_28 = - V_60 ;
return V_28 ;
case V_54 :
V_49 = 0 ;
break;
case V_58 :
V_49 = 1 ;
break;
default:
V_28 = - V_60 ;
F_17 ( L_197 , V_65 ) ;
return V_28 ;
}
V_28 = F_10 ( V_25 , V_62 , & V_49 ) ;
if ( V_28 ) {
F_17 ( L_5 , V_28 ) ;
return V_28 ;
}
return 0 ;
}
static T_6 F_190 ( struct V_24 * V_25 )
{
T_7 V_482 [ V_483 + 12 ] ;
T_7 V_484 [ V_483 ] ;
T_6 V_28 = 0 ;
F_19 ( L_3 ) ;
F_21 ( L_198 , V_484 , V_483 ,
V_482 , sizeof( V_482 ) ) ;
V_28 = F_12 ( V_25 , V_75 , V_482 , sizeof( V_482 ) ) ;
if ( V_28 ) {
F_17 ( L_199 , V_28 ) ;
goto V_485;
}
memcpy ( V_484 , V_482 , V_483 ) ;
F_191 ( V_484 , V_424 ) ;
F_191 ( V_484 , V_446 ) ;
F_191 ( V_484 , V_486 ) ;
F_191 ( V_484 , V_487 ) ;
F_191 ( V_484 , V_488 ) ;
F_191 ( V_484 , V_489 ) ;
F_191 ( V_484 , V_490 ) ;
F_191 ( V_484 , V_491 ) ;
F_191 ( V_484 , V_492 ) ;
F_191 ( V_484 , V_493 ) ;
F_191 ( V_484 , V_494 ) ;
F_191 ( V_484 , V_495 ) ;
F_191 ( V_484 , V_426 ) ;
F_191 ( V_484 , V_496 ) ;
F_191 ( V_484 , V_463 ) ;
F_191 ( V_484 , V_497 ) ;
F_191 ( V_484 , V_498 ) ;
F_191 ( V_484 , V_499 ) ;
F_191 ( V_484 , V_462 ) ;
F_21 ( L_198 , V_484 , V_483 ,
V_482 , sizeof( V_482 ) ) ;
V_28 = F_12 ( V_25 , V_71 , V_482 , sizeof( V_482 ) ) ;
if ( V_28 ) {
F_17 ( L_200 , V_28 ) ;
goto V_485;
}
V_485:
F_19 ( L_9 ) ;
return V_28 ;
}
static T_6
F_192 ( struct V_24 * V_25 , T_4 V_500 , T_4 V_501 )
{
T_7 V_482 [ 32 ] ;
T_6 V_28 = 0 ;
T_5 V_502 [ 2 ] ;
T_5 V_503 [ 2 ] ;
T_5 V_504 ;
T_5 V_505 ;
if ( V_500 ) {
V_504 = F_11 ( V_501 ) ;
F_21 ( L_201 , ( char * ) & V_504 ,
sizeof( V_504 ) , V_482 , sizeof( V_482 ) ) ;
V_28 = F_12 ( V_25 , V_71 ,
V_482 , sizeof( V_482 ) ) ;
if ( V_28 ) {
F_17 ( L_202 , V_28 ) ;
goto V_506;
}
}
F_7 ( L_203 , V_500 ? L_204 : L_205 ) ;
V_505 = F_11 ( V_500 ) ;
F_21 ( L_206 , ( char * ) & V_505 ,
sizeof( V_505 ) , V_482 , sizeof( V_482 ) ) ;
V_28 = F_12 ( V_25 , V_71 , V_482 , sizeof( V_482 ) ) ;
if ( V_28 ) {
F_17 ( L_207 , V_28 ) ;
goto V_506;
}
V_502 [ 0 ] = F_11 ( V_507 ) ;
V_502 [ 1 ] = F_11 ( V_508 ) ;
V_28 = F_12 ( V_25 , V_509 ,
( void * ) V_502 , sizeof( V_502 ) ) ;
if ( V_28 ) {
F_17 ( L_208 , V_28 ) ;
goto V_506;
}
V_503 [ 0 ] = F_11 ( V_510 ) ;
V_503 [ 1 ] = F_11 ( V_508 ) ;
V_28 = F_12 ( V_25 , V_511 ,
( void * ) V_503 , sizeof( V_503 ) ) ;
if ( V_28 ) {
F_17 ( L_209 , V_28 ) ;
goto V_506;
}
V_506:
return V_28 ;
}
static T_6
F_193 ( struct V_24 * V_25 , T_6 V_512 ,
T_6 V_513 , T_6 V_514 )
{
T_6 V_28 = 0 ;
T_5 V_515 = F_11 ( V_512 ) ;
T_5 V_516 = F_11 ( V_513 ) ;
T_5 V_517 = F_11 ( V_514 ) ;
V_28 = F_12 ( V_25 , V_518 ,
& V_515 , sizeof( V_515 ) ) ;
if ( V_28 ) {
if ( V_28 == - V_53 )
F_7 ( L_210 ) ;
else
F_17 ( L_211 , V_28 ) ;
goto V_519;
}
V_28 = F_12 ( V_25 , V_520 ,
& V_516 , sizeof( V_516 ) ) ;
if ( V_28 ) {
if ( V_28 == - V_53 )
F_7 ( L_212 ) ;
else
F_17 ( L_213 , V_28 ) ;
goto V_519;
}
V_28 = F_12 ( V_25 , V_521 ,
& V_517 , sizeof( V_517 ) ) ;
if ( V_28 ) {
if ( V_28 == - V_53 )
F_7 ( L_214 ) ;
else
F_17 ( L_215 , V_28 ) ;
goto V_519;
}
V_519:
return V_28 ;
}
static T_6 F_194 ( struct V_5 * V_9 )
{
struct V_10 * V_10 ;
T_6 V_522 ;
T_7 V_523 ;
T_6 V_28 = 0 ;
V_28 = F_12 ( F_35 ( V_9 ) , V_524 ,
& V_522 , sizeof( V_522 ) ) ;
if ( V_28 ) {
F_17 ( L_10 , V_28 ) ;
return V_28 ;
}
V_523 = ( ( char * ) & V_522 ) [ 1 ] ;
F_7 ( L_216 , V_523 ) ;
if ( V_523 == 'n' || V_523 == 'a' ) {
V_10 = F_80 ( V_9 ) ;
V_10 -> V_335 [ V_314 ] = & V_525 ;
}
return V_28 ;
}
static T_6 F_195 ( struct V_5 * V_9 )
{
return F_194 ( V_9 ) ;
}
static T_6 F_196 ( struct V_5 * V_9 )
{
struct V_24 * V_25 ;
struct V_47 * V_48 ;
T_6 V_526 ;
T_6 V_28 = 0 ;
if ( V_9 -> V_476 )
return V_28 ;
V_25 = F_35 ( V_9 ) ;
V_48 = V_25 -> V_64 ;
F_193 ( V_25 , V_527 ,
V_528 , V_529 ) ;
V_28 = F_190 ( V_25 ) ;
if ( V_28 )
goto V_530;
V_526 = V_9 -> V_299 ? V_300 : V_301 ;
V_28 = F_10 ( V_25 , V_302 , & V_526 ) ;
if ( V_28 )
goto V_530;
F_7 ( L_217 ,
( V_526 ? L_120 : L_121 ) ) ;
V_28 = F_192 ( V_25 , ( V_9 -> V_475 ? 0 : 1 ) ,
V_531 ) ;
if ( V_28 )
goto V_530;
V_28 = F_189 ( V_25 , V_48 -> V_65 ) ;
if ( V_28 && V_28 != - V_532 )
goto V_530;
V_28 = F_195 ( V_9 ) ;
if ( V_28 )
goto V_530;
V_530:
V_9 -> V_476 = true ;
return V_28 ;
}
static int F_197 ( struct V_5 * V_9 )
{
char V_68 [ 10 + V_533 ] ;
struct V_534 * V_535 ;
T_6 V_28 = 0 ;
sprintf ( V_68 , L_218 , F_35 ( V_9 ) -> V_66 ) ;
V_9 -> V_536 = F_198 ( V_68 ,
F_80 ( V_9 ) -> V_536 ) ;
V_535 = F_199 ( L_219 , V_537 , V_9 -> V_536 ,
( T_1 * ) & V_9 -> V_159 -> V_166 ) ;
if ( ! V_535 ) {
V_28 = - V_107 ;
goto V_538;
}
V_535 = F_200 ( L_220 , V_537 , V_9 -> V_536 ,
( T_2 * ) & V_9 -> V_159 -> V_168 ) ;
if ( ! V_535 ) {
V_28 = - V_107 ;
goto V_538;
}
V_538:
return V_28 ;
}
static void F_201 ( struct V_5 * V_9 )
{
F_202 ( V_9 -> V_536 ) ;
V_9 -> V_536 = NULL ;
}
static T_6 F_203 ( struct V_5 * V_9 )
{
T_6 V_28 = 0 ;
F_38 ( V_11 , & V_9 -> V_12 ) ;
F_197 ( V_9 ) ;
V_28 = F_196 ( V_9 ) ;
if ( V_28 )
return V_28 ;
F_110 ( V_9 ) ;
return V_28 ;
}
static T_6 F_204 ( struct V_5 * V_9 )
{
if ( ( F_6 ( V_249 , & V_9 -> V_12 ) ||
F_6 ( V_137 , & V_9 -> V_12 ) ) &&
F_6 ( V_11 , & V_9 -> V_12 ) ) {
F_7 ( L_154 ) ;
F_52 ( V_9 ) ;
F_115 ( 500 ) ;
}
F_38 ( V_136 , & V_9 -> V_12 ) ;
F_93 ( V_9 ) ;
if ( V_9 -> V_140 ) {
F_99 ( V_9 -> V_140 , true ) ;
V_9 -> V_140 = NULL ;
}
F_41 ( V_11 , & V_9 -> V_12 ) ;
F_41 ( V_135 , & V_9 -> V_12 ) ;
F_41 ( V_136 , & V_9 -> V_12 ) ;
F_201 ( V_9 ) ;
return 0 ;
}
T_6 F_205 ( struct V_1 * V_6 )
{
struct V_5 * V_9 ;
T_6 V_28 = 0 ;
V_9 = F_3 ( V_6 ) ;
F_206 ( & V_9 -> V_477 ) ;
V_28 = F_203 ( V_9 ) ;
F_207 ( & V_9 -> V_477 ) ;
return V_28 ;
}
T_6 F_208 ( struct V_1 * V_6 )
{
struct V_5 * V_9 ;
T_6 V_28 = 0 ;
V_9 = F_3 ( V_6 ) ;
F_206 ( & V_9 -> V_477 ) ;
V_28 = F_204 ( V_9 ) ;
F_207 ( & V_9 -> V_477 ) ;
return V_28 ;
}
static T_10 T_6 F_209 ( struct V_5 * V_9 ,
T_2 V_539 , T_2 V_147 , T_2 * V_540 )
{
struct V_541 * V_193 = & V_9 -> V_193 ;
T_6 V_28 = 0 ;
if ( V_193 -> V_20 + V_147 + 2 > V_542 ) {
F_17 ( L_221 ) ;
return - V_543 ;
}
V_193 -> V_68 [ V_193 -> V_20 ] = V_539 ;
V_193 -> V_68 [ V_193 -> V_20 + 1 ] = V_147 ;
memcpy ( & V_193 -> V_68 [ V_193 -> V_20 + 2 ] , V_540 , V_147 ) ;
V_193 -> V_20 += V_147 + 2 ;
return V_28 ;
}
