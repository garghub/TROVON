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
if ( V_80 && V_80 -> V_92 ) {
V_78 -> V_93 . V_92 = F_11 ( V_80 -> V_92 ) ;
memcpy ( & V_78 -> V_93 . V_94 , V_80 -> V_94 , V_80 -> V_92 ) ;
}
}
static T_6
F_27 ( struct V_24 * V_25 , T_7 * V_95 , void * V_96 ,
T_6 V_97 , void * V_98 , T_6 V_99 )
{
T_6 V_100 ;
V_100 = F_21 ( V_95 , V_96 , V_97 , V_98 , V_99 ) ;
F_22 ( ! V_100 ) ;
return F_12 ( V_25 , V_71 , V_98 , V_100 ) ;
}
static T_6
F_28 ( struct V_24 * V_25 , T_7 * V_95 , void * V_96 ,
T_6 V_97 , void * V_98 , T_6 V_99 )
{
T_6 V_100 ;
V_100 = F_21 ( V_95 , V_96 , V_97 , V_98 , V_99 ) ;
F_22 ( ! V_100 ) ;
return F_12 ( V_25 , V_75 , V_98 , V_99 ) ;
}
static T_6
F_29 ( struct V_101 * V_102 ,
struct V_79 * V_80 , T_1 V_103 )
{
T_6 V_104 = V_105 +
F_30 ( struct V_106 , V_78 ) ;
struct V_106 * V_46 ;
T_6 V_28 = 0 ;
if ( V_80 && V_80 -> V_92 )
V_104 += sizeof( struct V_79 ) ;
V_46 = F_31 ( V_104 , V_107 ) ;
if ( ! V_46 )
return - V_108 ;
F_22 ( V_104 >= V_69 ) ;
F_26 ( & V_46 -> V_78 , V_80 ) ;
V_46 -> V_109 = F_11 ( V_110 ) ;
V_46 -> V_103 = F_15 ( V_103 ) ;
V_46 -> V_111 = F_15 ( 0 ) ;
V_28 = F_27 ( V_102 -> V_25 , L_14 , V_46 , V_104 ,
V_102 -> V_112 , V_69 ) ;
if ( V_28 ) {
if ( V_28 == - V_113 )
F_7 ( L_15 ) ;
else
F_17 ( L_10 , V_28 ) ;
}
F_32 ( V_46 ) ;
return V_28 ;
}
static T_6 F_33 ( struct V_5 * V_9 )
{
struct V_101 * V_102 = F_34 ( V_9 ) ;
struct V_24 * V_25 = F_35 ( V_9 ) ;
struct V_79 V_80 ;
T_5 V_114 ;
T_6 V_28 = 0 ;
memset ( & V_80 , 0 , sizeof( V_80 ) ) ;
V_102 -> V_115 = V_116 ;
V_114 = V_9 -> V_117 ? 0 : F_11 ( 1 ) ;
V_28 = F_12 ( F_35 ( V_9 ) , V_118 ,
& V_114 , sizeof( V_114 ) ) ;
if ( V_28 ) {
F_17 ( L_10 , V_28 ) ;
return V_28 ;
}
F_24 ( V_25 , 0 ) ;
V_9 -> V_119 = true ;
V_28 = F_29 ( V_102 , & V_80 , V_120 ) ;
if ( V_28 ) {
F_24 ( V_25 , 1 ) ;
V_9 -> V_119 = false ;
return V_28 ;
}
F_36 ( & V_102 -> V_121 , V_122 + V_102 -> V_123 * V_124 / 1000 ) ;
V_102 -> V_125 = 1 ;
return V_28 ;
}
static T_6
F_37 ( struct V_10 * V_10 , struct V_24 * V_25 ,
struct V_126 * V_127 ,
struct V_128 * V_129 )
{
struct V_5 * V_9 = F_25 ( V_25 ) ;
struct V_128 * V_130 ;
struct V_131 * V_132 = V_9 -> V_133 ;
T_5 V_114 ;
bool V_134 ;
bool V_135 ;
T_6 V_28 = 0 ;
T_4 V_92 ;
if ( F_6 ( V_136 , & V_9 -> V_12 ) ) {
F_17 ( L_16 , V_9 -> V_12 ) ;
return - V_63 ;
}
if ( F_6 ( V_137 , & V_9 -> V_12 ) ) {
F_17 ( L_17 ,
V_9 -> V_12 ) ;
return - V_63 ;
}
if ( F_6 ( V_138 , & V_9 -> V_12 ) ) {
F_17 ( L_18 ,
V_9 -> V_12 ) ;
return - V_63 ;
}
V_134 = false ;
V_135 = false ;
if ( V_127 ) {
V_130 = V_127 -> V_130 ;
if ( V_9 -> V_139 && ( ! V_130 || ! V_130 -> V_140 ) )
V_134 = true ;
} else {
V_130 = V_129 ;
}
V_9 -> V_141 = V_127 ;
F_38 ( V_136 , & V_9 -> V_12 ) ;
if ( V_134 ) {
V_28 = F_33 ( V_9 ) ;
if ( ! V_28 )
return V_28 ;
else
goto V_142;
} else {
F_39 ( L_19 ,
V_130 -> V_80 , V_130 -> V_140 ) ;
memset ( & V_132 -> V_93 , 0 , sizeof( V_132 -> V_93 ) ) ;
V_92 = F_40 ( T_2 , sizeof( V_132 -> V_93 . V_94 ) , V_130 -> V_140 ) ;
V_132 -> V_93 . V_92 = F_11 ( 0 ) ;
if ( V_92 ) {
memcpy ( V_132 -> V_93 . V_94 , V_130 -> V_80 , V_92 ) ;
V_132 -> V_93 . V_92 = F_11 ( V_92 ) ;
V_135 = true ;
} else {
F_39 ( L_20 ) ;
}
V_114 = V_9 -> V_117 ? 0 : F_11 ( 1 ) ;
V_28 = F_12 ( V_25 , V_118 ,
& V_114 , sizeof( V_114 ) ) ;
if ( V_28 ) {
F_17 ( L_21 , V_28 ) ;
goto V_142;
}
F_24 ( V_25 , 0 ) ;
V_28 = F_12 ( V_25 , V_143 , & V_132 -> V_93 ,
sizeof( V_132 -> V_93 ) ) ;
if ( V_28 ) {
if ( V_28 == - V_113 )
F_7 ( L_22
L_23 , V_132 -> V_93 . V_94 ) ;
else
F_17 ( L_24 , V_28 ) ;
F_24 ( V_25 , 1 ) ;
goto V_142;
}
}
return 0 ;
V_142:
F_41 ( V_136 , & V_9 -> V_12 ) ;
V_9 -> V_141 = NULL ;
return V_28 ;
}
static T_6
F_42 ( struct V_10 * V_10 ,
struct V_126 * V_127 )
{
struct V_24 * V_25 = V_127 -> V_48 -> V_144 ;
T_6 V_28 = 0 ;
F_19 ( L_3 ) ;
if ( ! F_4 ( V_10 ) )
return - V_50 ;
V_28 = F_37 ( V_10 , V_25 , V_127 , NULL ) ;
if ( V_28 )
F_17 ( L_25 , V_28 ) ;
F_19 ( L_9 ) ;
return V_28 ;
}
static T_6 F_43 ( struct V_24 * V_25 , T_4 V_145 )
{
T_6 V_28 = 0 ;
V_28 = F_20 ( V_25 , L_26 , V_145 ) ;
if ( V_28 )
F_17 ( L_27 , V_28 ) ;
return V_28 ;
}
static T_6 F_44 ( struct V_24 * V_25 , T_4 V_146 )
{
T_6 V_28 = 0 ;
V_28 = F_20 ( V_25 , L_28 , V_146 ) ;
if ( V_28 )
F_17 ( L_27 , V_28 ) ;
return V_28 ;
}
static T_6 F_45 ( struct V_24 * V_25 , T_4 V_147 , bool V_148 )
{
T_6 V_28 = 0 ;
T_4 V_26 = ( V_148 ? V_149 : V_150 ) ;
V_28 = F_10 ( V_25 , V_26 , & V_147 ) ;
if ( V_28 ) {
F_17 ( L_29 , V_26 , V_28 ) ;
return V_28 ;
}
return V_28 ;
}
static T_6 F_46 ( struct V_10 * V_10 , T_4 V_151 )
{
struct V_5 * V_9 = F_5 ( V_10 ) ;
struct V_24 * V_25 = F_35 ( V_9 ) ;
T_6 V_28 = 0 ;
F_19 ( L_3 ) ;
if ( ! F_4 ( V_10 ) )
return - V_50 ;
if ( V_151 & V_152 &&
( V_9 -> V_55 -> V_145 != V_10 -> V_145 ) ) {
V_9 -> V_55 -> V_145 = V_10 -> V_145 ;
V_28 = F_43 ( V_25 , V_9 -> V_55 -> V_145 ) ;
if ( ! V_28 )
goto V_61;
}
if ( V_151 & V_153 &&
( V_9 -> V_55 -> V_146 != V_10 -> V_146 ) ) {
V_9 -> V_55 -> V_146 = V_10 -> V_146 ;
V_28 = F_44 ( V_25 , V_9 -> V_55 -> V_146 ) ;
if ( ! V_28 )
goto V_61;
}
if ( V_151 & V_154
&& ( V_9 -> V_55 -> V_155 != V_10 -> V_155 ) ) {
V_9 -> V_55 -> V_155 = V_10 -> V_155 ;
V_28 = F_45 ( V_25 , V_9 -> V_55 -> V_155 , true ) ;
if ( ! V_28 )
goto V_61;
}
if ( V_151 & V_156
&& ( V_9 -> V_55 -> V_157 != V_10 -> V_157 ) ) {
V_9 -> V_55 -> V_157 = V_10 -> V_157 ;
V_28 = F_45 ( V_25 , V_9 -> V_55 -> V_157 , false ) ;
if ( ! V_28 )
goto V_61;
}
V_61:
F_19 ( L_9 ) ;
return V_28 ;
}
static void * F_47 ( struct V_5 * V_9 , T_6 V_158 )
{
switch ( V_158 ) {
case V_159 :
return & V_9 -> V_160 -> V_161 ;
case V_162 :
return & V_9 -> V_160 -> V_81 ;
case V_163 :
return & V_9 -> V_160 -> V_80 ;
}
F_17 ( L_30 , V_158 ) ;
return NULL ;
}
static T_6
F_48 ( struct V_5 * V_9 ,
const struct V_164 * V_165 , void * V_3 , T_6 V_158 )
{
T_6 V_28 = 0 ;
struct V_79 * V_80 ;
switch ( V_158 ) {
case V_163 :
V_80 = (struct V_79 * ) V_3 ;
memset ( V_9 -> V_160 -> V_80 . V_94 , 0 ,
sizeof( V_9 -> V_160 -> V_80 . V_94 ) ) ;
memcpy ( V_9 -> V_160 -> V_80 . V_94 ,
V_80 -> V_94 , V_80 -> V_92 ) ;
V_9 -> V_160 -> V_80 . V_92 = V_80 -> V_92 ;
break;
case V_162 :
if ( V_3 )
memcpy ( V_9 -> V_160 -> V_81 , V_3 , V_83 ) ;
else
memset ( V_9 -> V_160 -> V_81 , 0 , V_83 ) ;
break;
case V_159 :
memcpy ( & V_9 -> V_160 -> V_161 , V_3 ,
sizeof( V_9 -> V_160 -> V_161 ) ) ;
break;
case V_166 :
V_9 -> V_160 -> V_167 = * ( T_1 * ) V_3 ;
break;
case V_168 :
V_9 -> V_160 -> V_169 = * ( T_2 * ) V_3 ;
break;
default:
F_17 ( L_31 , V_158 ) ;
V_28 = - V_53 ;
break;
}
return V_28 ;
}
static void F_49 ( struct V_170 * V_171 )
{
memset ( V_171 , 0 , sizeof( * V_171 ) ) ;
}
static void F_50 ( int V_172 , struct V_173 * V_174 ,
T_8 * V_175 )
{
T_1 V_176 = 0 ;
if ( V_172 != 0 ) {
if ( V_172 <= V_177 )
V_176 |= V_178 ;
else
V_176 |= V_179 ;
V_176 |= V_180 ;
V_176 |= V_181 ;
* V_175 += V_182 +
sizeof( T_1 ) ;
V_176 |= ( V_172 & V_183 ) ;
V_174 -> V_78 . V_184 [ 0 ] = F_15 ( V_176 ) ;
V_174 -> V_78 . V_185 = F_11 ( 1 ) ;
F_51 ( L_32
L_33 ,
V_176 , V_172 , V_176 ) ;
}
}
static void F_52 ( struct V_5 * V_9 )
{
struct V_24 * V_25 = NULL ;
T_6 V_28 = 0 ;
F_19 ( L_3 ) ;
if ( V_9 -> V_186 ) {
V_25 = F_35 ( V_9 ) ;
F_7 ( L_34 ) ;
V_28 = F_12 ( V_25 , V_187 , NULL , 0 ) ;
if ( V_28 )
F_17 ( L_35 , V_28 ) ;
V_9 -> V_186 = false ;
}
F_19 ( L_9 ) ;
}
static T_6
F_53 ( struct V_10 * V_10 , struct V_24 * V_25 ,
struct V_188 * V_46 )
{
struct V_5 * V_9 = F_5 ( V_10 ) ;
struct V_173 V_174 ;
T_8 V_175 = 0 ;
T_6 V_28 = 0 ;
T_6 V_189 = 0 ;
T_6 V_190 ;
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
F_38 ( V_138 , & V_9 -> V_12 ) ;
if ( V_46 -> V_81 )
F_51 ( L_38 , V_46 -> V_81 ) ;
else
F_51 ( L_39 ) ;
if ( V_46 -> V_191 )
F_51 ( L_40 , V_46 -> V_191 -> V_192 ) ;
else
F_51 ( L_41 ) ;
if ( V_46 -> V_193 )
F_51 ( L_42 ) ;
else
F_51 ( L_43 ) ;
if ( V_46 -> V_194 && V_46 -> V_195 )
F_51 ( L_44 , V_46 -> V_195 ) ;
else
F_51 ( L_45 ) ;
if ( V_46 -> V_167 )
F_51 ( L_46 , V_46 -> V_167 ) ;
else
F_51 ( L_47 ) ;
if ( V_46 -> V_196 )
F_51 ( L_48 , V_46 -> V_196 ) ;
else
F_51 ( L_49 ) ;
if ( V_46 -> V_197 )
F_51 ( L_50 ) ;
else
F_51 ( L_51 ) ;
if ( V_46 -> V_197 )
V_189 |= V_198 ;
V_28 = F_20 ( V_25 , L_52 , V_189 ) ;
if ( V_28 ) {
F_17 ( L_53 , V_28 ) ;
goto V_61;
}
if ( V_46 -> V_167 )
V_190 = V_46 -> V_167 ;
else
V_190 = 100 ;
V_28 = F_10 ( V_25 , V_199 , & V_190 ) ;
if ( V_28 ) {
F_17 ( L_54 , V_28 ) ;
goto V_61;
}
memset ( & V_174 , 0 , sizeof( struct V_173 ) ) ;
V_80 . V_92 = F_40 ( T_4 , V_46 -> V_140 , 32 ) ;
memcpy ( V_80 . V_94 , V_46 -> V_80 , V_80 . V_92 ) ;
memcpy ( V_174 . V_93 . V_94 , V_46 -> V_80 , V_80 . V_92 ) ;
V_174 . V_93 . V_92 = F_11 ( V_80 . V_92 ) ;
V_175 = sizeof( V_174 . V_93 ) ;
F_48 ( V_9 , NULL , & V_80 , V_163 ) ;
if ( V_46 -> V_81 ) {
memcpy ( V_174 . V_78 . V_81 , V_46 -> V_81 , V_83 ) ;
V_175 = sizeof( V_174 . V_93 ) +
V_182 ;
} else {
memcpy ( V_174 . V_78 . V_81 , V_82 , V_83 ) ;
}
F_48 ( V_9 , NULL ,
& V_174 . V_78 . V_81 , V_162 ) ;
if ( V_46 -> V_191 ) {
T_4 V_200 ;
V_9 -> V_191 =
F_54 (
V_46 -> V_191 -> V_192 ) ;
if ( V_46 -> V_193 ) {
F_50 ( V_9 -> V_191 ,
& V_174 , & V_175 ) ;
}
V_200 = V_9 -> V_191 ;
V_28 = F_10 ( V_25 , V_201 ,
& V_200 ) ;
if ( V_28 ) {
F_17 ( L_55 , V_28 ) ;
goto V_61;
}
} else
V_9 -> V_191 = 0 ;
V_9 -> V_202 = false ;
V_28 = F_12 ( V_25 , V_203 ,
& V_174 , V_175 ) ;
if ( V_28 ) {
F_17 ( L_56 , V_28 ) ;
goto V_61;
}
V_61:
if ( V_28 )
F_41 ( V_138 , & V_9 -> V_12 ) ;
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
struct V_204 * V_205 )
{
struct V_5 * V_9 = F_25 ( V_25 ) ;
struct V_206 * V_161 ;
T_6 V_67 = 0 ;
T_6 V_28 = 0 ;
if ( V_205 -> V_207 . V_208 & V_209 )
V_67 = V_210 | V_211 ;
else if ( V_205 -> V_207 . V_208 & V_212 )
V_67 = V_213 | V_214 ;
else
V_67 = V_215 ;
F_51 ( L_57 , V_67 ) ;
V_28 = F_20 ( V_25 , L_58 , V_67 ) ;
if ( V_28 ) {
F_17 ( L_59 , V_28 ) ;
return V_28 ;
}
V_161 = F_47 ( V_9 , V_159 ) ;
V_161 -> V_208 = V_205 -> V_207 . V_208 ;
return V_28 ;
}
static T_6 F_57 ( struct V_24 * V_25 ,
struct V_204 * V_205 )
{
struct V_5 * V_9 = F_25 ( V_25 ) ;
struct V_206 * V_161 ;
T_6 V_67 = 0 ;
T_6 V_28 = 0 ;
switch ( V_205 -> V_216 ) {
case V_217 :
V_67 = 0 ;
F_51 ( L_60 ) ;
break;
case V_218 :
V_67 = 1 ;
F_51 ( L_61 ) ;
break;
case V_219 :
V_67 = 2 ;
F_51 ( L_62 ) ;
break;
case V_220 :
F_51 ( L_63 ) ;
default:
V_67 = 2 ;
F_17 ( L_64 , V_205 -> V_216 ) ;
break;
}
V_28 = F_20 ( V_25 , L_65 , V_67 ) ;
if ( V_28 ) {
F_17 ( L_66 , V_28 ) ;
return V_28 ;
}
V_161 = F_47 ( V_9 , V_159 ) ;
V_161 -> V_216 = V_205 -> V_216 ;
return V_28 ;
}
static T_6
F_58 ( struct V_24 * V_25 ,
struct V_204 * V_205 )
{
struct V_5 * V_9 = F_25 ( V_25 ) ;
struct V_206 * V_161 ;
T_6 V_221 = 0 ;
T_6 V_222 = 0 ;
T_6 V_28 = 0 ;
if ( V_205 -> V_207 . V_223 ) {
switch ( V_205 -> V_207 . V_224 [ 0 ] ) {
case V_225 :
case V_226 :
V_221 = V_198 ;
break;
case V_227 :
V_221 = V_228 ;
break;
case V_229 :
V_221 = V_230 ;
break;
case V_231 :
V_221 = V_230 ;
break;
default:
F_17 ( L_67 ,
V_205 -> V_207 . V_224 [ 0 ] ) ;
return - V_60 ;
}
}
if ( V_205 -> V_207 . V_232 ) {
switch ( V_205 -> V_207 . V_232 ) {
case V_225 :
case V_226 :
V_222 = V_198 ;
break;
case V_227 :
V_222 = V_228 ;
break;
case V_229 :
V_222 = V_230 ;
break;
case V_231 :
V_222 = V_230 ;
break;
default:
F_17 ( L_68 ,
V_205 -> V_207 . V_232 ) ;
return - V_60 ;
}
}
F_51 ( L_69 , V_221 , V_222 ) ;
V_28 = F_20 ( V_25 , L_52 , V_221 | V_222 ) ;
if ( V_28 ) {
F_17 ( L_10 , V_28 ) ;
return V_28 ;
}
V_161 = F_47 ( V_9 , V_159 ) ;
V_161 -> V_233 = V_205 -> V_207 . V_224 [ 0 ] ;
V_161 -> V_232 = V_205 -> V_207 . V_232 ;
return V_28 ;
}
static T_6
F_59 ( struct V_24 * V_25 , struct V_204 * V_205 )
{
struct V_5 * V_9 = F_25 ( V_25 ) ;
struct V_206 * V_161 ;
T_6 V_67 = 0 ;
T_6 V_28 = 0 ;
if ( V_205 -> V_207 . V_234 ) {
V_28 = F_23 ( V_25 , L_58 , & V_67 ) ;
if ( V_28 ) {
F_17 ( L_70 , V_28 ) ;
return V_28 ;
}
if ( V_67 & ( V_210 | V_211 ) ) {
switch ( V_205 -> V_207 . V_235 [ 0 ] ) {
case V_236 :
V_67 = V_211 ;
break;
case V_237 :
V_67 = V_210 ;
break;
default:
F_17 ( L_68 ,
V_205 -> V_207 . V_232 ) ;
return - V_60 ;
}
} else if ( V_67 & ( V_213 | V_214 ) ) {
switch ( V_205 -> V_207 . V_235 [ 0 ] ) {
case V_236 :
V_67 = V_214 ;
break;
case V_237 :
V_67 = V_213 ;
break;
default:
F_17 ( L_68 ,
V_205 -> V_207 . V_232 ) ;
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
V_161 = F_47 ( V_9 , V_159 ) ;
V_161 -> V_238 = V_205 -> V_207 . V_235 [ 0 ] ;
return V_28 ;
}
static T_6
F_60 ( struct V_24 * V_25 ,
struct V_204 * V_205 )
{
struct V_5 * V_9 = F_25 ( V_25 ) ;
struct V_206 * V_161 ;
struct V_30 V_31 ;
T_6 V_67 ;
T_6 V_28 = 0 ;
F_51 ( L_73 , V_205 -> V_239 ) ;
if ( V_205 -> V_239 == 0 )
return 0 ;
V_161 = F_47 ( V_9 , V_159 ) ;
F_51 ( L_74 ,
V_161 -> V_208 , V_161 -> V_233 ) ;
if ( V_161 -> V_208 & ( V_209 | V_212 ) )
return 0 ;
if ( V_161 -> V_233 &
( V_225 | V_226 ) ) {
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_35 = ( T_4 ) V_205 -> V_239 ;
V_31 . V_34 = ( T_4 ) V_205 -> V_240 ;
if ( V_31 . V_35 > sizeof( V_31 . V_3 ) ) {
F_17 ( L_75 , V_31 . V_35 ) ;
return - V_60 ;
}
memcpy ( V_31 . V_3 , V_205 -> V_31 , V_31 . V_35 ) ;
V_31 . V_37 = V_241 ;
switch ( V_161 -> V_233 ) {
case V_225 :
V_31 . V_36 = V_242 ;
break;
case V_226 :
V_31 . V_36 = V_243 ;
break;
default:
F_17 ( L_76 ,
V_205 -> V_207 . V_224 [ 0 ] ) ;
return - V_60 ;
}
F_51 ( L_77 ,
V_31 . V_35 , V_31 . V_34 , V_31 . V_36 ) ;
F_51 ( L_78 , V_31 . V_3 ) ;
V_28 = F_16 ( V_25 , & V_31 ) ;
if ( V_28 )
return V_28 ;
if ( V_161 -> V_216 == V_217 ) {
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
struct V_204 * V_205 )
{
struct V_5 * V_9 = F_5 ( V_10 ) ;
struct V_244 * V_245 = V_205 -> V_191 ;
struct V_173 V_174 ;
T_8 V_175 ;
struct V_79 V_80 ;
T_6 V_28 = 0 ;
F_19 ( L_3 ) ;
if ( ! F_4 ( V_10 ) )
return - V_50 ;
if ( ! V_205 -> V_80 ) {
F_17 ( L_80 ) ;
return - V_53 ;
}
F_38 ( V_138 , & V_9 -> V_12 ) ;
if ( V_245 ) {
V_9 -> V_191 =
F_54 ( V_245 -> V_192 ) ;
F_51 ( L_81 ,
V_9 -> V_191 , V_245 -> V_192 ) ;
} else
V_9 -> V_191 = 0 ;
F_7 ( L_82 , V_205 -> V_194 , V_205 -> V_195 ) ;
V_28 = F_56 ( V_25 , V_205 ) ;
if ( V_28 ) {
F_17 ( L_83 , V_28 ) ;
goto V_61;
}
V_28 = F_57 ( V_25 , V_205 ) ;
if ( V_28 ) {
F_17 ( L_84 , V_28 ) ;
goto V_61;
}
V_28 = F_58 ( V_25 , V_205 ) ;
if ( V_28 ) {
F_17 ( L_85 , V_28 ) ;
goto V_61;
}
V_28 = F_59 ( V_25 , V_205 ) ;
if ( V_28 ) {
F_17 ( L_86 , V_28 ) ;
goto V_61;
}
V_28 = F_60 ( V_25 , V_205 ) ;
if ( V_28 ) {
F_17 ( L_87 , V_28 ) ;
goto V_61;
}
memset ( & V_174 , 0 , sizeof( V_174 ) ) ;
V_175 = sizeof( V_174 . V_93 ) ;
V_80 . V_92 = F_40 ( T_4 , sizeof( V_80 . V_94 ) , ( T_4 ) V_205 -> V_140 ) ;
memcpy ( & V_174 . V_93 . V_94 , V_205 -> V_80 , V_80 . V_92 ) ;
memcpy ( & V_80 . V_94 , V_205 -> V_80 , V_80 . V_92 ) ;
V_174 . V_93 . V_92 = F_11 ( V_80 . V_92 ) ;
F_48 ( V_9 , NULL , & V_80 , V_163 ) ;
memcpy ( V_174 . V_78 . V_81 , V_82 , V_83 ) ;
if ( V_80 . V_92 < V_246 )
F_51 ( L_88 ,
V_80 . V_94 , V_80 . V_92 ) ;
F_50 ( V_9 -> V_191 ,
& V_174 , & V_175 ) ;
V_28 = F_12 ( V_25 , V_203 ,
& V_174 , V_175 ) ;
if ( V_28 )
F_17 ( L_56 , V_28 ) ;
V_61:
if ( V_28 )
F_41 ( V_138 , & V_9 -> V_12 ) ;
F_19 ( L_9 ) ;
return V_28 ;
}
static T_6
F_62 ( struct V_10 * V_10 , struct V_24 * V_25 ,
T_1 V_247 )
{
struct V_5 * V_9 = F_5 ( V_10 ) ;
struct V_248 V_249 ;
T_6 V_28 = 0 ;
F_19 ( L_89 , V_247 ) ;
if ( ! F_4 ( V_10 ) )
return - V_50 ;
F_41 ( V_250 , & V_9 -> V_12 ) ;
memcpy ( & V_249 . V_42 , F_47 ( V_9 , V_162 ) , V_83 ) ;
V_249 . V_67 = F_11 ( V_247 ) ;
V_28 = F_12 ( V_25 , V_187 , & V_249 ,
sizeof( struct V_248 ) ) ;
if ( V_28 )
F_17 ( L_10 , V_28 ) ;
V_9 -> V_186 = false ;
F_19 ( L_9 ) ;
return V_28 ;
}
static T_6
F_63 ( struct V_10 * V_10 ,
enum V_251 type , T_6 V_252 )
{
struct V_5 * V_9 = F_5 ( V_10 ) ;
struct V_24 * V_25 = F_35 ( V_9 ) ;
T_1 V_253 ;
T_6 V_28 = 0 ;
T_6 V_254 = 0 ;
T_6 V_255 = F_64 ( V_252 ) ;
F_19 ( L_3 ) ;
if ( ! F_4 ( V_10 ) )
return - V_50 ;
switch ( type ) {
case V_256 :
break;
case V_257 :
case V_258 :
if ( V_255 < 0 ) {
F_17 ( L_90 ) ;
V_28 = - V_60 ;
goto V_61;
}
break;
}
V_254 = V_259 << 16 ;
V_28 = F_10 ( V_25 , V_260 , & V_254 ) ;
if ( V_28 )
F_17 ( L_91 , V_28 ) ;
if ( V_255 > 0xffff )
V_253 = 0xffff ;
else
V_253 = ( T_1 ) V_255 ;
V_28 = F_20 ( V_25 , L_92 ,
( T_6 ) ( F_9 ( V_253 ) ) ) ;
if ( V_28 )
F_17 ( L_93 , V_28 ) ;
V_9 -> V_55 -> V_261 = V_255 ;
V_61:
F_19 ( L_9 ) ;
return V_28 ;
}
static T_6 F_65 ( struct V_10 * V_10 , T_6 * V_255 )
{
struct V_5 * V_9 = F_5 ( V_10 ) ;
struct V_24 * V_25 = F_35 ( V_9 ) ;
T_6 V_262 ;
T_2 V_263 ;
T_6 V_28 = 0 ;
F_19 ( L_3 ) ;
if ( ! F_4 ( V_10 ) )
return - V_50 ;
V_28 = F_23 ( V_25 , L_92 , & V_262 ) ;
if ( V_28 ) {
F_17 ( L_10 , V_28 ) ;
goto V_61;
}
V_263 = ( T_2 ) ( V_262 & ~ V_264 ) ;
* V_255 = ( T_6 ) F_8 ( V_263 ) ;
V_61:
F_19 ( L_9 ) ;
return V_28 ;
}
static T_6
F_66 ( struct V_10 * V_10 , struct V_24 * V_25 ,
T_2 V_240 , bool V_265 , bool V_266 )
{
T_4 V_34 ;
T_4 V_189 ;
T_6 V_28 = 0 ;
F_19 ( L_3 ) ;
F_51 ( L_94 , V_240 ) ;
if ( ! F_4 ( V_10 ) )
return - V_50 ;
V_28 = F_10 ( V_25 , V_267 , & V_189 ) ;
if ( V_28 ) {
F_17 ( L_95 , V_28 ) ;
goto V_61;
}
if ( V_189 & V_198 ) {
V_34 = V_240 ;
V_28 = F_10 ( V_25 , V_268 ,
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
T_2 V_240 , const T_2 * V_269 , struct V_270 * V_46 )
{
struct V_30 V_31 ;
struct V_32 V_33 ;
T_6 V_28 = 0 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_34 = ( T_4 ) V_240 ;
if ( ! F_68 ( V_269 ) )
memcpy ( ( char * ) & V_31 . V_42 , ( void * ) V_269 , V_83 ) ;
V_31 . V_35 = ( T_4 ) V_46 -> V_239 ;
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
if ( V_46 -> V_271 == V_227 ) {
T_2 V_272 [ 8 ] ;
memcpy ( V_272 , & V_31 . V_3 [ 24 ] , sizeof( V_272 ) ) ;
memcpy ( & V_31 . V_3 [ 24 ] , & V_31 . V_3 [ 16 ] , sizeof( V_272 ) ) ;
memcpy ( & V_31 . V_3 [ 16 ] , V_272 , sizeof( V_272 ) ) ;
}
if ( V_46 -> V_273 && V_46 -> V_274 == 6 ) {
T_2 * V_275 ;
V_275 = ( T_2 * ) V_46 -> V_273 ;
V_31 . V_38 . V_39 = ( V_275 [ 5 ] << 24 ) | ( V_275 [ 4 ] << 16 ) |
( V_275 [ 3 ] << 8 ) | V_275 [ 2 ] ;
V_31 . V_38 . V_40 = ( V_275 [ 1 ] << 8 ) | V_275 [ 0 ] ;
V_31 . V_41 = true ;
}
switch ( V_46 -> V_271 ) {
case V_225 :
V_31 . V_36 = V_242 ;
F_51 ( L_98 ) ;
break;
case V_226 :
V_31 . V_36 = V_243 ;
F_51 ( L_99 ) ;
break;
case V_227 :
V_31 . V_36 = V_276 ;
F_51 ( L_100 ) ;
break;
case V_231 :
V_31 . V_36 = V_277 ;
F_51 ( L_101 ) ;
break;
case V_229 :
V_31 . V_36 = V_277 ;
F_51 ( L_102 ) ;
break;
default:
F_17 ( L_103 , V_46 -> V_271 ) ;
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
T_2 V_240 , bool V_278 , const T_2 * V_269 ,
struct V_270 * V_46 )
{
struct V_30 V_31 ;
T_6 V_67 ;
T_6 V_189 ;
T_6 V_28 = 0 ;
T_2 V_272 [ 8 ] ;
F_19 ( L_3 ) ;
F_51 ( L_94 , V_240 ) ;
if ( ! F_4 ( V_10 ) )
return - V_50 ;
if ( V_269 ) {
F_19 ( L_104 ) ;
return F_67 ( V_10 , V_25 , V_240 , V_269 , V_46 ) ;
}
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_35 = ( T_4 ) V_46 -> V_239 ;
V_31 . V_34 = ( T_4 ) V_240 ;
if ( V_31 . V_35 > sizeof( V_31 . V_3 ) ) {
F_17 ( L_75 , V_31 . V_35 ) ;
V_28 = - V_60 ;
goto V_61;
}
memcpy ( V_31 . V_3 , V_46 -> V_31 , V_31 . V_35 ) ;
V_31 . V_37 = V_241 ;
switch ( V_46 -> V_271 ) {
case V_225 :
V_31 . V_36 = V_242 ;
F_51 ( L_98 ) ;
break;
case V_226 :
V_31 . V_36 = V_243 ;
F_51 ( L_99 ) ;
break;
case V_227 :
memcpy ( V_272 , & V_31 . V_3 [ 24 ] , sizeof( V_272 ) ) ;
memcpy ( & V_31 . V_3 [ 24 ] , & V_31 . V_3 [ 16 ] , sizeof( V_272 ) ) ;
memcpy ( & V_31 . V_3 [ 16 ] , V_272 , sizeof( V_272 ) ) ;
V_31 . V_36 = V_276 ;
F_51 ( L_100 ) ;
break;
case V_231 :
V_31 . V_36 = V_277 ;
F_51 ( L_101 ) ;
break;
case V_229 :
V_31 . V_36 = V_277 ;
F_51 ( L_102 ) ;
break;
default:
F_17 ( L_103 , V_46 -> V_271 ) ;
V_28 = - V_60 ;
goto V_61;
}
V_28 = F_16 ( V_25 , & V_31 ) ;
if ( V_28 )
goto V_61;
V_67 = V_198 ;
V_28 = F_23 ( V_25 , L_52 , & V_189 ) ;
if ( V_28 ) {
F_17 ( L_105 , V_28 ) ;
goto V_61;
}
V_189 &= ~ ( V_198 ) ;
V_189 |= V_67 ;
V_28 = F_20 ( V_25 , L_52 , V_189 ) ;
if ( V_28 ) {
F_17 ( L_106 , V_28 ) ;
goto V_61;
}
V_67 = 1 ;
V_28 = F_10 ( V_25 , V_279 , & V_67 ) ;
if ( V_28 )
F_17 ( L_107 , V_28 ) ;
V_61:
F_19 ( L_9 ) ;
return V_28 ;
}
static T_6
F_71 ( struct V_10 * V_10 , struct V_24 * V_25 ,
T_2 V_240 , bool V_278 , const T_2 * V_269 )
{
struct V_30 V_31 ;
T_6 V_28 = 0 ;
T_6 V_67 ;
T_6 V_189 ;
F_19 ( L_3 ) ;
if ( ! F_4 ( V_10 ) )
return - V_50 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_34 = ( T_4 ) V_240 ;
V_31 . V_37 = V_241 ;
V_31 . V_36 = V_280 ;
F_51 ( L_94 , V_240 ) ;
V_28 = F_16 ( V_25 , & V_31 ) ;
if ( V_28 ) {
if ( V_28 == - V_60 ) {
if ( V_31 . V_34 >= V_281 )
F_17 ( L_108 , V_240 ) ;
}
V_28 = - V_63 ;
goto V_61;
}
V_67 = 0 ;
V_28 = F_23 ( V_25 , L_52 , & V_189 ) ;
if ( V_28 ) {
F_17 ( L_105 , V_28 ) ;
V_28 = - V_63 ;
goto V_61;
}
V_189 &= ~ ( V_198 ) ;
V_189 |= V_67 ;
V_28 = F_20 ( V_25 , L_52 , V_189 ) ;
if ( V_28 ) {
F_17 ( L_106 , V_28 ) ;
V_28 = - V_63 ;
goto V_61;
}
V_67 = 0 ;
V_28 = F_10 ( V_25 , V_279 , & V_67 ) ;
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
T_2 V_240 , bool V_278 , const T_2 * V_269 , void * V_282 ,
void (* F_73) ( void * V_282 , struct V_270 * V_46 ) )
{
struct V_270 V_46 ;
struct V_5 * V_9 = F_5 ( V_10 ) ;
struct V_206 * V_161 ;
T_6 V_189 ;
T_6 V_28 = 0 ;
F_19 ( L_3 ) ;
F_51 ( L_94 , V_240 ) ;
if ( ! F_4 ( V_10 ) )
return - V_50 ;
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
V_28 = F_10 ( V_25 , V_267 , & V_189 ) ;
if ( V_28 ) {
F_17 ( L_95 , V_28 ) ;
V_28 = - V_63 ;
goto V_61;
}
switch ( V_189 ) {
case V_198 :
V_161 = F_47 ( V_9 , V_159 ) ;
if ( V_161 -> V_233 & V_225 ) {
V_46 . V_271 = V_225 ;
F_51 ( L_98 ) ;
} else if ( V_161 -> V_233 & V_226 ) {
V_46 . V_271 = V_226 ;
F_51 ( L_99 ) ;
}
break;
case V_228 :
V_46 . V_271 = V_227 ;
F_51 ( L_100 ) ;
break;
case V_230 :
V_46 . V_271 = V_231 ;
F_51 ( L_101 ) ;
break;
default:
F_17 ( L_109 , V_189 ) ;
V_28 = - V_60 ;
goto V_61;
}
F_73 ( V_282 , & V_46 ) ;
V_61:
F_19 ( L_9 ) ;
return V_28 ;
}
static T_6
F_74 ( struct V_10 * V_10 ,
struct V_24 * V_25 , T_2 V_240 )
{
F_7 ( L_110 ) ;
return - V_53 ;
}
static T_6
F_75 ( struct V_10 * V_10 , struct V_24 * V_25 ,
T_2 * V_283 , struct V_284 * V_285 )
{
struct V_5 * V_9 = F_5 ( V_10 ) ;
struct V_248 V_286 ;
int V_287 ;
T_6 V_288 ;
T_6 V_28 = 0 ;
T_2 * V_81 = F_47 ( V_9 , V_162 ) ;
F_19 ( L_3 ) ;
if ( ! F_4 ( V_10 ) )
return - V_50 ;
if ( memcmp ( V_283 , V_81 , V_83 ) ) {
F_17 ( L_111
L_112 ,
V_283 [ 0 ] , V_283 [ 1 ] , V_283 [ 2 ] , V_283 [ 3 ] , V_283 [ 4 ] , V_283 [ 5 ] ,
V_81 [ 0 ] , V_81 [ 1 ] , V_81 [ 2 ] , V_81 [ 3 ] ,
V_81 [ 4 ] , V_81 [ 5 ] ) ;
V_28 = - V_289 ;
goto V_61;
}
V_28 = F_10 ( V_25 , V_290 , & V_288 ) ;
if ( V_28 ) {
F_17 ( L_113 , V_28 ) ;
} else {
V_285 -> V_291 |= V_292 ;
V_285 -> V_293 . V_294 = V_288 * 5 ;
F_51 ( L_114 , V_288 / 2 ) ;
}
if ( F_6 ( V_250 , & V_9 -> V_12 ) ) {
memset ( & V_286 , 0 , sizeof( V_286 ) ) ;
V_28 = F_12 ( V_25 , V_295 , & V_286 ,
sizeof( struct V_248 ) ) ;
if ( V_28 ) {
F_17 ( L_115 , V_28 ) ;
} else {
V_287 = F_13 ( V_286 . V_67 ) ;
V_285 -> V_291 |= V_296 ;
V_285 -> signal = V_287 ;
F_51 ( L_116 , V_287 ) ;
}
}
V_61:
F_19 ( L_9 ) ;
return V_28 ;
}
static T_6
F_76 ( struct V_10 * V_10 , struct V_24 * V_25 ,
bool V_297 , T_6 V_298 )
{
T_6 V_299 ;
T_6 V_28 = 0 ;
struct V_5 * V_9 = F_5 ( V_10 ) ;
F_19 ( L_3 ) ;
V_9 -> V_300 = V_297 ;
if ( ! F_6 ( V_11 , & V_9 -> V_12 ) ) {
F_7 ( L_117
L_118 ) ;
goto V_61;
}
V_299 = V_297 ? V_301 : V_302 ;
F_7 ( L_119 , ( V_299 ? L_120 : L_121 ) ) ;
V_28 = F_10 ( V_25 , V_303 , & V_299 ) ;
if ( V_28 ) {
if ( V_28 == - V_304 )
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
const T_2 * V_305 ,
const struct V_306 * V_307 )
{
struct V_308 V_309 ;
T_6 V_288 ;
T_6 V_67 ;
T_6 V_310 ;
T_6 V_311 ;
T_4 V_294 ;
T_6 V_28 = 0 ;
F_19 ( L_3 ) ;
if ( ! F_4 ( V_10 ) )
return - V_50 ;
V_28 = F_12 ( V_25 , V_312 , & V_309 ,
sizeof( V_309 ) ) ;
if ( V_28 ) {
F_17 ( L_123 , V_28 ) ;
goto V_61;
}
V_294 = F_78 ( V_307 -> V_313 [ V_314 ] . V_294 & 0xFFFF ) ;
if ( ! V_294 )
V_294 = F_78 ( V_307 -> V_313 [ V_315 ] . V_294 &
0xFFFF ) ;
V_67 = V_316 [ V_294 - 1 ] . V_317 * 100000 ;
if ( V_67 < F_13 ( V_309 . V_318 ) )
V_288 = V_309 . V_319 [ V_67 ] & 0x7f ;
else
V_288 = V_67 / 500000 ;
F_51 ( L_124 , V_288 / 2 ) ;
V_310 = F_20 ( V_25 , L_125 , V_288 ) ;
V_311 = F_20 ( V_25 , L_126 , V_288 ) ;
if ( V_310 && V_311 ) {
F_17 ( L_127 , V_310 , V_311 ) ;
V_28 = V_310 | V_311 ;
}
V_61:
F_19 ( L_9 ) ;
return V_28 ;
}
static T_6 F_79 ( struct V_5 * V_9 ,
struct V_320 * V_321 )
{
struct V_10 * V_10 = F_80 ( V_9 ) ;
struct V_244 * V_322 ;
struct V_323 * V_324 ;
struct V_325 * V_326 ;
T_6 V_28 = 0 ;
T_1 V_191 ;
T_4 V_327 ;
T_1 V_328 ;
T_1 V_329 ;
T_2 * V_330 ;
T_8 V_331 ;
T_6 V_332 ;
if ( F_13 ( V_321 -> V_333 ) > V_334 ) {
F_17 ( L_128 ) ;
return 0 ;
}
V_191 = V_321 -> V_335 ? V_321 -> V_335 :
F_81 ( F_82 ( V_321 -> V_176 ) ) ;
if ( V_191 <= V_177 )
V_326 = V_10 -> V_336 [ V_314 ] ;
else
V_326 = V_10 -> V_336 [ V_315 ] ;
V_327 = F_83 ( V_191 , V_326 -> V_326 ) ;
V_322 = F_84 ( V_10 , V_327 ) ;
V_328 = F_82 ( V_321 -> V_337 ) ;
V_329 = F_82 ( V_321 -> V_338 ) ;
V_330 = ( T_2 * ) V_321 + F_82 ( V_321 -> V_339 ) ;
V_331 = F_13 ( V_321 -> V_340 ) ;
V_332 = ( V_341 ) F_82 ( V_321 -> V_342 ) * 100 ;
F_51 ( L_129 ,
V_321 -> V_343 [ 0 ] , V_321 -> V_343 [ 1 ] , V_321 -> V_343 [ 2 ] ,
V_321 -> V_343 [ 3 ] , V_321 -> V_343 [ 4 ] , V_321 -> V_343 [ 5 ] ) ;
F_51 ( L_130 , V_191 , V_327 ) ;
F_51 ( L_131 , V_328 ) ;
F_51 ( L_132 , V_329 ) ;
F_51 ( L_133 , V_332 ) ;
V_324 = F_85 ( V_10 , V_322 , ( const T_2 * ) V_321 -> V_343 ,
0 , V_328 , V_329 , V_330 ,
V_331 , V_332 , V_107 ) ;
if ( ! V_324 )
return - V_108 ;
F_86 ( V_324 ) ;
return V_28 ;
}
static struct V_320 *
F_87 ( struct V_344 * V_345 , struct V_320 * V_324 )
{
if ( V_324 == NULL )
return V_345 -> V_346 ;
return (struct V_320 * ) ( ( unsigned long ) V_324 +
F_13 ( V_324 -> V_333 ) ) ;
}
static T_6 F_88 ( struct V_5 * V_9 )
{
struct V_344 * V_347 ;
struct V_320 * V_321 = NULL ;
T_6 V_28 = 0 ;
int V_348 ;
V_347 = V_9 -> V_347 ;
if ( V_347 -> V_109 != V_349 ) {
F_17 ( L_134 ,
V_347 -> V_109 ) ;
return - V_53 ;
}
F_39 ( L_135 , V_347 -> V_318 ) ;
for ( V_348 = 0 ; V_348 < V_347 -> V_318 && V_348 < V_350 ; V_348 ++ ) {
V_321 = F_87 ( V_347 , V_321 ) ;
V_28 = F_79 ( V_9 , V_321 ) ;
if ( V_28 )
break;
}
return V_28 ;
}
static T_6 F_89 ( struct V_5 * V_9 ,
struct V_24 * V_25 , const T_2 * V_81 )
{
struct V_10 * V_10 = F_80 ( V_9 ) ;
struct V_244 * V_322 ;
struct V_320 * V_321 = NULL ;
struct V_325 * V_326 ;
struct V_323 * V_324 ;
T_2 * V_68 = NULL ;
T_6 V_28 = 0 ;
T_1 V_191 ;
T_4 V_327 ;
T_1 V_328 ;
T_1 V_329 ;
T_2 * V_330 ;
T_8 V_331 ;
T_6 V_332 ;
F_19 ( L_3 ) ;
V_68 = F_31 ( V_334 , V_107 ) ;
if ( V_68 == NULL ) {
V_28 = - V_108 ;
goto V_351;
}
* ( T_5 * ) V_68 = F_11 ( V_334 ) ;
V_28 = F_12 ( V_25 , V_352 , V_68 , V_334 ) ;
if ( V_28 ) {
F_17 ( L_136 , V_28 ) ;
goto V_351;
}
V_321 = (struct V_320 * ) ( V_68 + 4 ) ;
V_191 = V_321 -> V_335 ? V_321 -> V_335 :
F_81 ( F_82 ( V_321 -> V_176 ) ) ;
if ( V_191 <= V_177 )
V_326 = V_10 -> V_336 [ V_314 ] ;
else
V_326 = V_10 -> V_336 [ V_315 ] ;
V_327 = F_83 ( V_191 , V_326 -> V_326 ) ;
V_322 = F_84 ( V_10 , V_327 ) ;
V_328 = F_82 ( V_321 -> V_337 ) ;
V_329 = F_82 ( V_321 -> V_338 ) ;
V_330 = ( T_2 * ) V_321 + F_82 ( V_321 -> V_339 ) ;
V_331 = F_13 ( V_321 -> V_340 ) ;
V_332 = ( V_341 ) F_82 ( V_321 -> V_342 ) * 100 ;
F_51 ( L_137 , V_191 , V_327 ) ;
F_51 ( L_138 , V_328 ) ;
F_51 ( L_46 , V_329 ) ;
F_51 ( L_139 , V_332 ) ;
V_324 = F_85 ( V_10 , V_322 , V_81 ,
0 , V_328 , V_329 ,
V_330 , V_331 , V_332 , V_107 ) ;
if ( ! V_324 ) {
V_28 = - V_108 ;
goto V_351;
}
F_86 ( V_324 ) ;
V_351:
F_32 ( V_68 ) ;
F_19 ( L_9 ) ;
return V_28 ;
}
static bool F_90 ( struct V_5 * V_9 )
{
return V_9 -> V_55 -> V_56 == V_57 ;
}
static struct V_353 * F_91 ( void * V_68 , int V_99 , T_3 V_31 )
{
struct V_353 * V_354 ;
int V_355 ;
V_354 = (struct V_353 * ) V_68 ;
V_355 = V_99 ;
while ( V_355 >= 2 ) {
int V_35 = V_354 -> V_35 ;
if ( ( V_354 -> V_356 == V_31 ) && ( V_355 >= ( V_35 + 2 ) ) )
return V_354 ;
V_354 = (struct V_353 * ) ( ( T_2 * ) V_354 + ( V_35 + 2 ) ) ;
V_355 -= ( V_35 + 2 ) ;
}
return NULL ;
}
static T_6 F_92 ( struct V_5 * V_9 )
{
struct V_320 * V_321 ;
struct V_79 * V_80 ;
struct V_353 * V_357 ;
T_1 V_167 ;
T_2 V_169 ;
T_8 V_195 ;
T_2 * V_194 ;
T_6 V_28 = 0 ;
F_19 ( L_3 ) ;
if ( F_90 ( V_9 ) )
return V_28 ;
V_80 = (struct V_79 * ) F_47 ( V_9 , V_163 ) ;
* ( T_5 * ) V_9 -> V_358 = F_11 ( V_359 ) ;
V_28 = F_12 ( F_35 ( V_9 ) , V_352 ,
V_9 -> V_358 , V_359 ) ;
if ( V_28 ) {
F_17 ( L_140 , V_28 ) ;
goto V_360;
}
V_321 = (struct V_320 * ) ( V_9 -> V_358 + 4 ) ;
V_28 = F_79 ( V_9 , V_321 ) ;
if ( V_28 )
goto V_360;
V_194 = ( ( T_2 * ) V_321 ) + F_82 ( V_321 -> V_339 ) ;
V_195 = F_13 ( V_321 -> V_340 ) ;
V_167 = F_82 ( V_321 -> V_338 ) ;
V_357 = F_91 ( V_194 , V_195 , V_361 ) ;
if ( V_357 )
V_169 = V_357 -> V_3 [ 1 ] ;
else {
T_4 V_73 ;
V_28 = F_23 ( F_35 ( V_9 ) ,
L_141 , & V_73 ) ;
if ( V_28 ) {
F_17 ( L_142 , V_28 ) ;
goto V_360;
}
V_169 = ( T_2 ) V_73 ;
}
F_48 ( V_9 , NULL , & V_167 , V_166 ) ;
F_48 ( V_9 , NULL , & V_169 , V_168 ) ;
V_360:
F_19 ( L_104 ) ;
return V_28 ;
}
static void F_93 ( struct V_5 * V_9 )
{
struct V_101 * V_102 = F_34 ( V_9 ) ;
struct V_79 V_80 ;
if ( V_9 -> V_139 ) {
V_102 -> V_115 = V_362 ;
if ( V_102 -> V_125 ) {
F_94 ( & V_102 -> V_121 ) ;
V_102 -> V_125 = 0 ;
}
F_95 ( & V_102 -> V_363 ) ;
memset ( & V_80 , 0 , sizeof( V_80 ) ) ;
F_29 ( V_102 , & V_80 , V_364 ) ;
}
}
static void F_96 ( struct V_101 * V_102 ,
bool V_365 )
{
struct V_5 * V_9 = F_97 ( V_102 ) ;
struct V_24 * V_25 = F_35 ( V_9 ) ;
if ( ! F_98 ( V_136 , & V_9 -> V_12 ) ) {
F_17 ( L_143 ) ;
return;
}
if ( V_9 -> V_141 ) {
F_39 ( L_144 ,
V_365 ? L_145 : L_146 ) ;
F_99 ( V_9 -> V_141 , V_365 ) ;
F_24 ( V_25 , 1 ) ;
V_9 -> V_141 = NULL ;
}
V_9 -> V_119 = false ;
}
static T_6 F_100 ( struct V_101 * V_102 )
{
if ( V_102 -> V_115 != V_362 ) {
F_39 ( L_147 ) ;
F_101 ( & V_102 -> V_363 ) ;
return 0 ;
}
return - V_50 ;
}
static T_6
F_102 ( struct V_101 * V_102 , T_4 * V_12 ,
struct V_344 * * V_347 )
{
struct V_366 V_345 ;
struct V_344 * V_367 ;
struct V_368 * V_369 ;
struct V_366 * V_370 ;
T_6 V_28 = 0 ;
memset ( V_102 -> V_371 , 0 , V_372 ) ;
V_370 = (struct V_366 * ) V_102 -> V_371 ;
V_367 = & V_370 -> V_367 ;
V_369 = & V_370 -> V_369 ;
V_367 -> V_99 = V_373 ;
V_367 -> V_109 = 0 ;
V_367 -> V_318 = 0 ;
memset ( & V_345 , 0 , sizeof( V_345 ) ) ;
V_345 . V_369 . V_99 = F_11 ( V_372 ) ;
V_28 = F_28 ( V_102 -> V_25 , L_148 , & V_345 ,
V_373 ,
V_102 -> V_371 , V_372 ) ;
if ( V_28 ) {
F_17 ( L_10 , V_28 ) ;
return V_28 ;
}
V_367 -> V_99 = F_13 ( V_369 -> V_99 ) ;
V_367 -> V_109 = F_13 ( V_369 -> V_109 ) ;
V_367 -> V_318 = F_13 ( V_369 -> V_318 ) ;
F_39 ( L_149 , V_369 -> V_318 ) ;
F_39 ( L_150 , V_369 -> V_99 ) ;
* V_12 = F_13 ( V_370 -> V_374 ) ;
F_39 ( L_151 , * V_12 ) ;
* V_347 = V_367 ;
return V_28 ;
}
static T_6 F_103 ( struct V_5 * V_9 )
{
struct V_101 * V_102 = V_9 -> V_102 ;
T_6 V_28 = 0 ;
V_102 -> V_115 = V_362 ;
F_88 ( V_9 ) ;
F_96 ( V_102 , false ) ;
return V_28 ;
}
static T_6 F_104 ( struct V_5 * V_9 )
{
struct V_101 * V_102 = V_9 -> V_102 ;
T_6 V_28 = 0 ;
F_36 ( & V_102 -> V_121 , V_122 + V_102 -> V_123 * V_124 / 1000 ) ;
V_102 -> V_125 = 1 ;
return V_28 ;
}
static T_6 F_105 ( struct V_5 * V_9 )
{
struct V_101 * V_102 = V_9 -> V_102 ;
T_6 V_28 = 0 ;
F_88 ( V_9 ) ;
F_29 ( V_102 , NULL , V_375 ) ;
F_36 ( & V_102 -> V_121 , V_122 + V_102 -> V_123 * V_124 / 1000 ) ;
V_102 -> V_125 = 1 ;
return V_28 ;
}
static T_6 F_106 ( struct V_5 * V_9 )
{
struct V_101 * V_102 = V_9 -> V_102 ;
T_6 V_28 = 0 ;
V_102 -> V_115 = V_362 ;
F_96 ( V_102 , true ) ;
return V_28 ;
}
static void F_107 ( struct V_376 * V_363 )
{
struct V_101 * V_102 =
F_108 ( V_363 , struct V_101 ,
V_363 ) ;
struct V_5 * V_9 = F_97 ( V_102 ) ;
struct V_377 * V_378 = & V_102 -> V_378 ;
T_4 V_12 = V_379 ;
if ( V_102 -> V_125 ) {
F_94 ( & V_102 -> V_121 ) ;
V_102 -> V_125 = 0 ;
}
if ( F_102 ( V_102 , & V_12 , & V_9 -> V_347 ) ) {
V_12 = V_380 ;
F_17 ( L_152 ) ;
}
V_378 -> V_381 [ V_12 ] ( V_9 ) ;
}
static void F_109 ( unsigned long V_3 )
{
struct V_101 * V_102 =
(struct V_101 * ) V_3 ;
if ( V_102 ) {
V_102 -> V_125 = 0 ;
F_39 ( L_153 ) ;
F_100 ( V_102 ) ;
}
}
static T_6 F_110 ( struct V_5 * V_9 )
{
struct V_101 * V_102 = F_34 ( V_9 ) ;
if ( V_9 -> V_139 ) {
V_102 -> V_115 = V_362 ;
F_111 ( & V_102 -> V_363 , F_107 ) ;
}
return 0 ;
}
static void F_112 ( struct V_377 * V_378 )
{
memset ( V_378 , 0 , sizeof( * V_378 ) ) ;
V_378 -> V_381 [ V_382 ] = F_103 ;
V_378 -> V_381 [ V_379 ] = F_105 ;
V_378 -> V_381 [ V_383 ] = F_104 ;
V_378 -> V_381 [ V_380 ] = F_106 ;
V_378 -> V_381 [ V_384 ] = F_106 ;
}
static T_6 F_113 ( struct V_5 * V_9 )
{
struct V_101 * V_102 = F_34 ( V_9 ) ;
int V_28 = 0 ;
if ( V_9 -> V_139 ) {
V_102 -> V_25 = F_35 ( V_9 ) ;
F_112 ( & V_102 -> V_378 ) ;
V_102 -> V_123 = V_385 ;
F_114 ( & V_102 -> V_121 ) ;
V_102 -> V_121 . V_3 = ( unsigned long ) V_102 ;
V_102 -> V_121 . V_386 = F_109 ;
V_28 = F_110 ( V_9 ) ;
if ( ! V_28 )
V_102 -> V_3 = V_9 ;
}
return V_28 ;
}
static T_9 void F_115 ( T_4 V_387 )
{
if ( V_387 < 1000 / V_124 ) {
F_116 () ;
F_117 ( V_387 ) ;
} else {
F_118 ( V_387 ) ;
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
struct V_388 * V_389 )
{
struct V_5 * V_9 = F_5 ( V_10 ) ;
struct V_24 * V_25 = F_35 ( V_9 ) ;
F_19 ( L_3 ) ;
if ( ( F_6 ( V_250 , & V_9 -> V_12 ) ||
F_6 ( V_138 , & V_9 -> V_12 ) ) &&
F_6 ( V_11 , & V_9 -> V_12 ) ) {
F_7 ( L_154
L_155 ) ;
F_52 ( V_9 ) ;
F_115 ( 500 ) ;
}
F_38 ( V_137 , & V_9 -> V_12 ) ;
if ( F_6 ( V_11 , & V_9 -> V_12 ) )
F_93 ( V_9 ) ;
if ( V_9 -> V_141 ) {
F_7 ( L_156 ) ;
F_99 ( V_9 -> V_141 , true ) ;
V_9 -> V_141 = NULL ;
}
F_41 ( V_136 , & V_9 -> V_12 ) ;
F_41 ( V_137 , & V_9 -> V_12 ) ;
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
T_4 V_99 ;
V_99 = F_21 ( V_66 , V_68 , V_35 , V_9 -> V_112 ,
V_390 ) ;
F_22 ( ! V_99 ) ;
return F_12 ( V_25 , V_71 , V_9 -> V_112 ,
V_99 ) ;
}
static T_6
F_122 ( struct V_24 * V_25 , T_7 * V_66 , T_7 * V_68 ,
T_6 V_391 )
{
struct V_5 * V_9 = F_25 ( V_25 ) ;
T_4 V_35 ;
T_6 V_28 = 0 ;
V_35 = F_21 ( V_66 , NULL , 0 , V_9 -> V_112 ,
V_390 ) ;
F_22 ( ! V_35 ) ;
V_28 = F_12 ( V_25 , V_75 , V_9 -> V_112 ,
V_390 ) ;
if ( V_28 ) {
F_17 ( L_10 , V_28 ) ;
return V_28 ;
}
memcpy ( V_68 , V_9 -> V_112 , V_391 ) ;
return V_28 ;
}
static T_10 T_6
F_123 ( struct V_24 * V_25 ,
struct V_392 * V_393 , T_6 V_28 )
{
int V_348 , V_394 ;
int V_395 ;
V_395 = F_13 ( V_393 -> V_396 . V_397 ) ;
F_51 ( L_158 , V_395 ) ;
for ( V_348 = 0 ; V_348 < V_395 ; V_348 ++ ) {
F_51 ( L_159 , V_348 ,
& V_393 -> V_396 . V_398 [ V_348 ] . V_343 ) ;
for ( V_394 = 0 ; V_394 < V_399 ; V_394 ++ )
F_51 ( L_160 , V_393 -> V_396 . V_398 [ V_348 ] . V_400 [ V_394 ] ) ;
}
if ( ! V_28 )
F_121 ( V_25 , L_161 , ( char * ) V_393 ,
sizeof( * V_393 ) ) ;
return V_28 ;
}
static T_6
F_124 ( struct V_10 * V_10 , struct V_24 * V_25 ,
struct V_401 * V_402 )
{
struct V_5 * V_9 = F_5 ( V_10 ) ;
struct V_403 * V_396 = & V_9 -> V_393 -> V_396 ;
T_6 V_28 = 0 ;
int V_348 ;
int V_395 ;
F_19 ( L_3 ) ;
if ( ! F_4 ( V_10 ) )
return - V_50 ;
V_395 = F_13 ( V_396 -> V_397 ) ;
for ( V_348 = 0 ; V_348 < V_395 ; V_348 ++ )
if ( ! memcmp ( V_402 -> V_81 , V_396 -> V_398 [ V_348 ] . V_343 , V_83 ) )
break;
if ( V_348 < V_404 ) {
memcpy ( V_396 -> V_398 [ V_348 ] . V_343 , V_402 -> V_81 , V_83 ) ;
memcpy ( V_396 -> V_398 [ V_348 ] . V_400 , V_402 -> V_398 , V_399 ) ;
if ( V_348 == V_395 ) {
V_395 ++ ;
V_396 -> V_397 = F_11 ( V_395 ) ;
}
} else
V_28 = - V_60 ;
F_51 ( L_162 ,
V_396 -> V_398 [ V_395 ] . V_343 ) ;
for ( V_348 = 0 ; V_348 < V_399 ; V_348 ++ )
F_51 ( L_160 , V_396 -> V_398 [ V_395 ] . V_400 [ V_348 ] ) ;
V_28 = F_123 ( V_25 , V_9 -> V_393 , V_28 ) ;
F_19 ( L_9 ) ;
return V_28 ;
}
static T_6
F_125 ( struct V_10 * V_10 , struct V_24 * V_25 ,
struct V_401 * V_402 )
{
struct V_5 * V_9 = F_5 ( V_10 ) ;
struct V_403 V_398 ;
T_6 V_28 = 0 ;
int V_348 , V_395 ;
F_19 ( L_3 ) ;
if ( ! F_4 ( V_10 ) )
return - V_50 ;
memcpy ( & V_398 . V_398 [ 0 ] . V_343 , V_402 -> V_81 , V_83 ) ;
memcpy ( & V_398 . V_398 [ 0 ] . V_400 , V_402 -> V_398 , V_399 ) ;
F_51 ( L_163 ,
& V_398 . V_398 [ 0 ] . V_343 ) ;
for ( V_348 = 0 ; V_348 < V_399 ; V_348 ++ )
F_51 ( L_160 , V_398 . V_398 [ 0 ] . V_400 [ V_348 ] ) ;
V_395 = F_13 ( V_9 -> V_393 -> V_396 . V_397 ) ;
for ( V_348 = 0 ; V_348 < V_395 ; V_348 ++ )
if ( ! memcmp
( V_402 -> V_81 , & V_9 -> V_393 -> V_396 . V_398 [ V_348 ] . V_343 ,
V_83 ) )
break;
if ( ( V_395 > 0 )
&& ( V_348 < V_395 ) ) {
memset ( & V_9 -> V_393 -> V_396 . V_398 [ V_348 ] , 0 ,
sizeof( struct V_398 ) ) ;
for (; V_348 < ( V_395 - 1 ) ; V_348 ++ ) {
memcpy ( & V_9 -> V_393 -> V_396 . V_398 [ V_348 ] . V_343 ,
& V_9 -> V_393 -> V_396 . V_398 [ V_348 + 1 ] . V_343 ,
V_83 ) ;
memcpy ( & V_9 -> V_393 -> V_396 . V_398 [ V_348 ] . V_400 ,
& V_9 -> V_393 -> V_396 . V_398 [ V_348 + 1 ] . V_400 ,
V_399 ) ;
}
V_9 -> V_393 -> V_396 . V_397 = F_11 ( V_395 - 1 ) ;
} else
V_28 = - V_60 ;
V_28 = F_123 ( V_25 , V_9 -> V_393 , V_28 ) ;
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
memset ( V_9 -> V_393 , 0 , sizeof( * V_9 -> V_393 ) ) ;
V_28 = F_123 ( V_25 , V_9 -> V_393 , V_28 ) ;
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
return V_405 ;
}
return V_28 ;
}
static struct V_47 * F_128 ( T_6 V_406 ,
struct V_407 * V_25 )
{
struct V_47 * V_48 ;
T_6 V_28 = 0 ;
V_48 = F_31 ( sizeof( * V_48 ) , V_107 ) ;
if ( ! V_48 )
return F_129 ( - V_108 ) ;
V_48 -> V_10 =
F_130 ( & V_408 ,
sizeof( struct V_5 ) + V_406 ) ;
if ( ! V_48 -> V_10 ) {
F_17 ( L_164 ) ;
V_28 = - V_108 ;
goto V_409;
}
F_131 ( V_48 -> V_10 , V_25 ) ;
V_48 -> V_10 -> V_410 = V_411 ;
V_48 -> V_10 -> V_412 = V_404 ;
V_48 -> V_10 -> V_413 =
F_132 ( V_58 ) | F_132 ( V_54 ) ;
V_48 -> V_10 -> V_336 [ V_314 ] = & V_414 ;
V_48 -> V_10 -> V_336 [ V_315 ] = & V_415 ;
V_48 -> V_10 -> V_416 = V_417 ;
V_48 -> V_10 -> V_418 = V_419 ;
V_48 -> V_10 -> V_420 = F_133 ( V_419 ) ;
V_48 -> V_10 -> V_37 |= V_421 ;
V_28 = F_134 ( V_48 -> V_10 ) ;
if ( V_28 < 0 ) {
F_17 ( L_165 , V_28 ) ;
goto V_422;
}
return V_48 ;
V_422:
F_135 ( V_48 -> V_10 ) ;
V_409:
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
const struct V_164 * V_165 )
{
T_4 V_423 = F_139 ( V_165 -> V_424 ) ;
T_4 V_12 = F_139 ( V_165 -> V_12 ) ;
if ( V_423 == V_425 && V_12 == V_426 ) {
F_51 ( L_167 ) ;
V_9 -> V_186 = true ;
return true ;
}
return false ;
}
static bool F_140 ( struct V_5 * V_9 ,
const struct V_164 * V_165 )
{
T_4 V_423 = F_139 ( V_165 -> V_424 ) ;
T_1 V_37 = F_141 ( V_165 -> V_37 ) ;
if ( V_423 == V_427 && ( ! ( V_37 & V_428 ) ) ) {
F_51 ( L_168 ) ;
return true ;
}
return false ;
}
static bool F_142 ( struct V_5 * V_9 ,
const struct V_164 * V_165 )
{
T_4 V_423 = F_139 ( V_165 -> V_424 ) ;
T_4 V_12 = F_139 ( V_165 -> V_12 ) ;
if ( V_423 == V_427 && V_12 == V_429 ) {
F_51 ( L_169 ,
F_141 ( V_165 -> V_37 ) & V_428 ?
L_170 : L_171 ) ;
return true ;
}
if ( V_423 == V_425 && V_12 != V_426 ) {
F_51 ( L_172 ) ;
return true ;
}
return false ;
}
static void F_143 ( struct V_5 * V_9 )
{
struct V_430 * V_431 = F_144 ( V_9 ) ;
F_32 ( V_431 -> V_432 ) ;
V_431 -> V_432 = NULL ;
V_431 -> V_433 = 0 ;
F_32 ( V_431 -> V_434 ) ;
V_431 -> V_434 = NULL ;
V_431 -> V_435 = 0 ;
}
static T_6 F_145 ( struct V_5 * V_9 )
{
struct V_24 * V_25 = F_35 ( V_9 ) ;
struct V_436 * V_437 ;
struct V_430 * V_431 = F_144 ( V_9 ) ;
T_4 V_438 ;
T_4 V_439 ;
T_6 V_28 = 0 ;
F_143 ( V_9 ) ;
V_28 = F_122 ( V_25 , L_173 , V_9 -> V_358 ,
V_440 ) ;
if ( V_28 ) {
F_17 ( L_174 , V_28 ) ;
return V_28 ;
}
V_437 =
(struct V_436 * ) V_9 -> V_358 ;
V_438 = F_13 ( V_437 -> V_438 ) ;
V_439 = F_13 ( V_437 -> V_439 ) ;
if ( V_438 ) {
V_28 = F_122 ( V_25 , L_175 ,
V_9 -> V_358 ,
V_440 ) ;
if ( V_28 ) {
F_17 ( L_176 , V_28 ) ;
return V_28 ;
}
V_431 -> V_433 = V_438 ;
V_431 -> V_432 =
F_146 ( V_9 -> V_358 , V_431 -> V_433 ,
V_107 ) ;
} else {
V_431 -> V_433 = 0 ;
V_431 -> V_432 = NULL ;
}
if ( V_439 ) {
V_28 = F_122 ( V_25 , L_177 ,
V_9 -> V_358 ,
V_440 ) ;
if ( V_28 ) {
F_17 ( L_178 , V_28 ) ;
return V_28 ;
}
V_431 -> V_435 = V_439 ;
V_431 -> V_434 =
F_146 ( V_9 -> V_358 , V_431 -> V_435 ,
V_107 ) ;
} else {
V_431 -> V_435 = 0 ;
V_431 -> V_434 = NULL ;
}
F_51 ( L_179 ,
V_431 -> V_433 , V_431 -> V_435 ) ;
return V_28 ;
}
static T_6
F_147 ( struct V_5 * V_9 ,
struct V_24 * V_25 ,
const struct V_164 * V_165 )
{
struct V_430 * V_431 = F_144 ( V_9 ) ;
struct V_10 * V_10 = F_80 ( V_9 ) ;
struct V_441 V_442 ;
struct V_244 * V_322 ;
struct V_325 * V_326 ;
T_4 V_327 ;
T_6 V_28 = 0 ;
T_4 V_200 ;
F_19 ( L_3 ) ;
F_145 ( V_9 ) ;
F_48 ( V_9 , NULL , & V_165 -> V_305 , V_162 ) ;
F_92 ( V_9 ) ;
F_12 ( V_25 , V_443 , & V_442 ,
sizeof( V_442 ) ) ;
V_200 = F_13 ( V_442 . V_200 ) ;
F_51 ( L_180 , V_200 ) ;
if ( V_200 <= V_177 )
V_326 = V_10 -> V_336 [ V_314 ] ;
else
V_326 = V_10 -> V_336 [ V_315 ] ;
V_327 = F_83 ( V_200 , V_326 -> V_326 ) ;
V_322 = F_84 ( V_10 , V_327 ) ;
F_148 ( V_25 , V_322 ,
( T_2 * ) F_47 ( V_9 , V_162 ) ,
V_431 -> V_432 , V_431 -> V_433 ,
V_431 -> V_434 , V_431 -> V_435 , V_107 ) ;
F_51 ( L_181 ) ;
F_38 ( V_250 , & V_9 -> V_12 ) ;
F_19 ( L_9 ) ;
return V_28 ;
}
static T_6
F_149 ( struct V_5 * V_9 ,
struct V_24 * V_25 , const struct V_164 * V_165 ,
bool V_444 )
{
struct V_430 * V_431 = F_144 ( V_9 ) ;
T_6 V_28 = 0 ;
F_19 ( L_3 ) ;
if ( F_98 ( V_138 , & V_9 -> V_12 ) ) {
if ( V_444 ) {
F_145 ( V_9 ) ;
F_48 ( V_9 , NULL , & V_165 -> V_305 ,
V_162 ) ;
F_92 ( V_9 ) ;
}
F_150 ( V_25 ,
( T_2 * ) F_47 ( V_9 ,
V_162 ) ,
V_431 -> V_432 ,
V_431 -> V_433 ,
V_431 -> V_434 ,
V_431 -> V_435 ,
V_444 ? V_445 :
V_446 ,
V_107 ) ;
if ( V_444 )
F_38 ( V_250 , & V_9 -> V_12 ) ;
F_51 ( L_182 ,
V_444 ? L_183 : L_184 ) ;
}
F_19 ( L_9 ) ;
return V_28 ;
}
static T_6
F_151 ( struct V_5 * V_9 ,
struct V_24 * V_25 ,
const struct V_164 * V_165 , void * V_3 )
{
T_6 V_28 = 0 ;
if ( F_138 ( V_9 , V_165 ) ) {
F_51 ( L_185 ) ;
if ( F_90 ( V_9 ) ) {
F_48 ( V_9 , NULL , ( void * ) V_165 -> V_305 ,
V_162 ) ;
F_89 ( V_9 , V_25 , V_165 -> V_305 ) ;
F_152 ( V_25 , V_165 -> V_305 , V_107 ) ;
F_41 ( V_138 , & V_9 -> V_12 ) ;
F_38 ( V_250 , & V_9 -> V_12 ) ;
} else
F_149 ( V_9 , V_25 , V_165 , true ) ;
} else if ( F_140 ( V_9 , V_165 ) ) {
F_51 ( L_186 ) ;
if ( F_90 ( V_9 ) ) {
F_41 ( V_138 , & V_9 -> V_12 ) ;
if ( F_98 ( V_250 ,
& V_9 -> V_12 ) )
F_52 ( V_9 ) ;
} else {
F_149 ( V_9 , V_25 , V_165 , false ) ;
if ( F_98 ( V_250 ,
& V_9 -> V_12 ) ) {
F_153 ( V_25 , 0 , NULL , 0 ,
V_107 ) ;
F_52 ( V_9 ) ;
}
}
F_49 ( V_9 -> V_160 ) ;
} else if ( F_142 ( V_9 , V_165 ) ) {
if ( F_90 ( V_9 ) )
F_41 ( V_138 , & V_9 -> V_12 ) ;
else
F_149 ( V_9 , V_25 , V_165 , false ) ;
}
return V_28 ;
}
static T_6
F_154 ( struct V_5 * V_9 ,
struct V_24 * V_25 ,
const struct V_164 * V_165 , void * V_3 )
{
T_6 V_28 = 0 ;
T_4 V_423 = F_139 ( V_165 -> V_424 ) ;
T_4 V_12 = F_139 ( V_165 -> V_12 ) ;
if ( V_423 == V_447 && V_12 == V_426 ) {
if ( F_6 ( V_250 , & V_9 -> V_12 ) )
F_147 ( V_9 , V_25 , V_165 ) ;
else
F_149 ( V_9 , V_25 , V_165 , true ) ;
}
return V_28 ;
}
static T_6
F_155 ( struct V_5 * V_9 ,
struct V_24 * V_25 ,
const struct V_164 * V_165 , void * V_3 )
{
T_1 V_37 = F_141 ( V_165 -> V_37 ) ;
enum V_448 V_449 ;
if ( V_37 & V_450 )
V_449 = V_451 ;
else
V_449 = V_452 ;
F_156 ( V_25 , ( T_2 * ) & V_165 -> V_305 , V_449 , - 1 ,
NULL , V_107 ) ;
return 0 ;
}
static T_6
F_157 ( struct V_5 * V_9 ,
struct V_24 * V_25 ,
const struct V_164 * V_165 , void * V_3 )
{
struct V_441 V_453 ;
struct V_368 * V_454 ;
T_4 V_35 = V_455 ;
T_6 V_28 = 0 ;
bool V_456 = false ;
T_4 V_457 ;
F_19 ( L_3 ) ;
if ( V_9 -> V_139 && V_9 -> V_119 ) {
F_19 ( L_9 ) ;
return F_100 ( F_34 ( V_9 ) ) ;
}
if ( ! F_98 ( V_136 , & V_9 -> V_12 ) ) {
F_17 ( L_143 ) ;
V_456 = true ;
V_28 = - V_60 ;
goto V_458;
}
V_28 = F_12 ( V_25 , V_443 , & V_453 ,
sizeof( V_453 ) ) ;
if ( V_28 ) {
F_17 ( L_187 , V_28 ) ;
V_456 = true ;
goto V_458;
}
V_457 = F_13 ( V_453 . V_457 ) ;
if ( V_457 )
F_51 ( L_188 , V_457 ) ;
V_9 -> V_347 = V_9 -> V_459 ;
V_454 = (struct V_368 * ) V_9 -> V_347 ;
memset ( V_9 -> V_459 , 0 , V_35 ) ;
V_454 -> V_99 = F_11 ( V_35 ) ;
V_28 = F_12 ( V_25 , V_460 ,
V_9 -> V_459 , V_35 ) ;
if ( V_28 ) {
F_17 ( L_189 , V_25 -> V_66 , V_28 ) ;
V_28 = - V_60 ;
V_456 = true ;
goto V_458;
}
V_9 -> V_459 -> V_99 = F_13 ( V_454 -> V_99 ) ;
V_9 -> V_459 -> V_109 = F_13 ( V_454 -> V_109 ) ;
V_9 -> V_459 -> V_318 = F_13 ( V_454 -> V_318 ) ;
V_28 = F_88 ( V_9 ) ;
if ( V_28 ) {
V_456 = true ;
goto V_458;
}
V_458:
if ( V_9 -> V_141 ) {
F_39 ( L_190 ) ;
F_99 ( V_9 -> V_141 , V_456 ) ;
F_24 ( V_25 , 1 ) ;
V_9 -> V_141 = NULL ;
}
F_19 ( L_9 ) ;
return V_28 ;
}
static void F_158 ( struct V_461 * V_55 )
{
V_55 -> V_56 = ( T_4 ) - 1 ;
V_55 -> V_146 = ( T_4 ) - 1 ;
V_55 -> V_145 = ( T_4 ) - 1 ;
V_55 -> V_157 = ( T_4 ) - 1 ;
V_55 -> V_155 = ( T_4 ) - 1 ;
V_55 -> V_261 = - 1 ;
}
static void F_159 ( struct V_462 * V_378 )
{
memset ( V_378 , 0 , sizeof( * V_378 ) ) ;
V_378 -> V_381 [ V_463 ] = F_157 ;
V_378 -> V_381 [ V_427 ] = F_151 ;
V_378 -> V_381 [ V_447 ] = F_154 ;
V_378 -> V_381 [ V_464 ] = F_155 ;
V_378 -> V_381 [ V_425 ] = F_151 ;
}
static void F_160 ( struct V_5 * V_9 )
{
F_32 ( V_9 -> V_459 ) ;
V_9 -> V_459 = NULL ;
F_32 ( V_9 -> V_465 ) ;
V_9 -> V_465 = NULL ;
F_32 ( V_9 -> V_55 ) ;
V_9 -> V_55 = NULL ;
F_32 ( V_9 -> V_160 ) ;
V_9 -> V_160 = NULL ;
F_32 ( V_9 -> V_133 ) ;
V_9 -> V_133 = NULL ;
F_32 ( V_9 -> V_112 ) ;
V_9 -> V_112 = NULL ;
F_32 ( V_9 -> V_358 ) ;
V_9 -> V_358 = NULL ;
F_32 ( V_9 -> V_102 ) ;
V_9 -> V_102 = NULL ;
F_32 ( V_9 -> V_393 ) ;
V_9 -> V_393 = NULL ;
}
static T_6 F_161 ( struct V_5 * V_9 )
{
V_9 -> V_459 = F_31 ( V_455 , V_107 ) ;
if ( ! V_9 -> V_459 )
goto V_466;
V_9 -> V_55 = F_31 ( sizeof( * V_9 -> V_55 ) , V_107 ) ;
if ( ! V_9 -> V_55 )
goto V_466;
V_9 -> V_160 = F_31 ( sizeof( * V_9 -> V_160 ) , V_107 ) ;
if ( ! V_9 -> V_160 )
goto V_466;
V_9 -> V_465 = F_31 ( V_334 , V_107 ) ;
if ( ! V_9 -> V_465 )
goto V_466;
V_9 -> V_133 = F_31 ( sizeof( * V_9 -> V_133 ) ,
V_107 ) ;
if ( ! V_9 -> V_133 )
goto V_466;
V_9 -> V_112 = F_31 ( V_390 , V_107 ) ;
if ( ! V_9 -> V_112 )
goto V_466;
V_9 -> V_358 = F_31 ( V_359 , V_107 ) ;
if ( ! V_9 -> V_358 )
goto V_466;
V_9 -> V_102 = F_31 ( sizeof( * V_9 -> V_102 ) , V_107 ) ;
if ( ! V_9 -> V_102 )
goto V_466;
V_9 -> V_393 = F_31 ( sizeof( * V_9 -> V_393 ) , V_107 ) ;
if ( ! V_9 -> V_393 )
goto V_466;
return 0 ;
V_466:
F_160 ( V_9 ) ;
return - V_108 ;
}
static struct V_467 * F_162 (
struct V_5 * V_9 )
{
struct V_467 * V_165 = NULL ;
F_163 ( & V_9 -> V_468 ) ;
if ( ! F_164 ( & V_9 -> V_469 ) ) {
V_165 = F_165 ( & V_9 -> V_469 ,
struct V_467 , V_469 ) ;
F_166 ( & V_165 -> V_469 ) ;
}
F_167 ( & V_9 -> V_468 ) ;
return V_165 ;
}
static T_6
F_168 ( struct V_5 * V_9 , T_4 V_423 ,
const struct V_164 * V_470 )
{
struct V_467 * V_165 ;
T_6 V_28 = 0 ;
T_11 V_37 ;
V_165 = F_31 ( sizeof( struct V_467 ) , V_471 ) ;
if ( ! V_165 )
return - V_108 ;
V_165 -> V_472 = V_423 ;
memcpy ( & V_165 -> V_473 , V_470 , sizeof( struct V_164 ) ) ;
F_169 ( & V_9 -> V_468 , V_37 ) ;
F_170 ( & V_165 -> V_469 , & V_9 -> V_469 ) ;
F_171 ( & V_9 -> V_468 , V_37 ) ;
return V_28 ;
}
static void F_172 ( struct V_467 * V_165 )
{
F_32 ( V_165 ) ;
}
static void F_173 ( struct V_376 * V_363 )
{
struct V_5 * V_9 =
F_108 ( V_363 , struct V_5 ,
V_474 ) ;
struct V_467 * V_165 ;
V_165 = F_162 ( V_9 ) ;
if ( F_174 ( ! V_165 ) ) {
F_17 ( L_191 ) ;
return;
}
do {
F_7 ( L_192 , V_165 -> V_472 ) ;
if ( V_9 -> V_378 . V_381 [ V_165 -> V_472 ] )
V_9 -> V_378 . V_381 [ V_165 -> V_472 ] ( V_9 ,
F_35 ( V_9 ) ,
& V_165 -> V_473 , V_165 -> V_475 ) ;
else
F_7 ( L_193 , V_165 -> V_472 ) ;
F_172 ( V_165 ) ;
} while ( ( V_165 = F_162 ( V_9 ) ) );
}
static void F_175 ( struct V_5 * V_9 )
{
F_176 ( & V_9 -> V_468 ) ;
F_177 ( & V_9 -> V_469 ) ;
}
static void F_178 ( struct V_5 * V_9 )
{
struct V_467 * V_165 ;
F_163 ( & V_9 -> V_468 ) ;
while ( ! F_164 ( & V_9 -> V_469 ) ) {
V_165 = F_165 ( & V_9 -> V_469 ,
struct V_467 , V_469 ) ;
F_166 ( & V_165 -> V_469 ) ;
F_32 ( V_165 ) ;
}
F_167 ( & V_9 -> V_468 ) ;
}
static T_6 F_179 ( struct V_5 * V_9 )
{
T_6 V_28 = 0 ;
V_9 -> V_141 = NULL ;
V_9 -> V_300 = true ;
V_9 -> V_139 = true ;
V_9 -> V_476 = true ;
V_9 -> V_119 = false ;
V_9 -> V_117 = true ;
V_9 -> V_477 = false ;
F_175 ( V_9 ) ;
V_28 = F_161 ( V_9 ) ;
if ( V_28 )
return V_28 ;
F_111 ( & V_9 -> V_474 , F_173 ) ;
F_159 ( & V_9 -> V_378 ) ;
F_180 ( & V_9 -> V_478 ) ;
V_28 = F_113 ( V_9 ) ;
if ( V_28 )
return V_28 ;
F_158 ( V_9 -> V_55 ) ;
F_49 ( V_9 -> V_160 ) ;
F_52 ( V_9 ) ;
return V_28 ;
}
static void F_181 ( struct V_5 * V_9 )
{
F_95 ( & V_9 -> V_474 ) ;
V_9 -> V_477 = false ;
F_178 ( V_9 ) ;
F_52 ( V_9 ) ;
F_93 ( V_9 ) ;
F_160 ( V_9 ) ;
}
struct V_1 * F_182 ( struct V_24 * V_25 ,
struct V_407 * V_479 ,
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
V_6 = F_31 ( sizeof( struct V_1 ) , V_107 ) ;
if ( ! V_6 )
return NULL ;
V_48 = F_128 ( sizeof( struct V_7 ) , V_479 ) ;
if ( F_183 ( V_48 ) ) {
F_32 ( V_6 ) ;
return NULL ;
}
V_48 -> V_65 = F_127 ( V_59 ) ;
V_9 = F_184 ( V_48 ) ;
V_9 -> V_48 = V_48 ;
V_9 -> V_480 = V_3 ;
V_8 = (struct V_7 * ) & V_9 -> V_8 ;
V_8 -> V_9 = V_9 ;
V_25 -> V_64 = V_48 ;
F_185 ( V_25 , F_186 ( V_48 -> V_10 ) ) ;
V_48 -> V_144 = V_25 ;
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
const struct V_164 * V_165 , void * V_3 )
{
T_4 V_424 = F_139 ( V_165 -> V_424 ) ;
struct V_5 * V_9 = F_25 ( V_25 ) ;
if ( ! F_168 ( V_9 , V_424 , V_165 ) )
F_101 ( & V_9 -> V_474 ) ;
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
F_191 ( V_484 , V_425 ) ;
F_191 ( V_484 , V_447 ) ;
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
F_191 ( V_484 , V_427 ) ;
F_191 ( V_484 , V_496 ) ;
F_191 ( V_484 , V_464 ) ;
F_191 ( V_484 , V_497 ) ;
F_191 ( V_484 , V_498 ) ;
F_191 ( V_484 , V_499 ) ;
F_191 ( V_484 , V_463 ) ;
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
V_10 -> V_336 [ V_315 ] = & V_525 ;
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
if ( V_9 -> V_477 )
return V_28 ;
V_25 = F_35 ( V_9 ) ;
V_48 = V_25 -> V_64 ;
F_193 ( V_25 , V_527 ,
V_528 , V_529 ) ;
V_28 = F_190 ( V_25 ) ;
if ( V_28 )
goto V_530;
V_526 = V_9 -> V_300 ? V_301 : V_302 ;
V_28 = F_10 ( V_25 , V_303 , & V_526 ) ;
if ( V_28 )
goto V_530;
F_7 ( L_217 ,
( V_526 ? L_120 : L_121 ) ) ;
V_28 = F_192 ( V_25 , ( V_9 -> V_476 ? 0 : 1 ) ,
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
V_9 -> V_477 = true ;
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
( T_1 * ) & V_9 -> V_160 -> V_167 ) ;
if ( ! V_535 ) {
V_28 = - V_108 ;
goto V_538;
}
V_535 = F_200 ( L_220 , V_537 , V_9 -> V_536 ,
( T_2 * ) & V_9 -> V_160 -> V_169 ) ;
if ( ! V_535 ) {
V_28 = - V_108 ;
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
if ( ( F_6 ( V_250 , & V_9 -> V_12 ) ||
F_6 ( V_138 , & V_9 -> V_12 ) ) &&
F_6 ( V_11 , & V_9 -> V_12 ) ) {
F_7 ( L_154 ) ;
F_52 ( V_9 ) ;
F_115 ( 500 ) ;
}
F_38 ( V_137 , & V_9 -> V_12 ) ;
F_93 ( V_9 ) ;
if ( V_9 -> V_141 ) {
F_99 ( V_9 -> V_141 , true ) ;
V_9 -> V_141 = NULL ;
}
F_41 ( V_11 , & V_9 -> V_12 ) ;
F_41 ( V_136 , & V_9 -> V_12 ) ;
F_41 ( V_137 , & V_9 -> V_12 ) ;
F_201 ( V_9 ) ;
return 0 ;
}
T_6 F_205 ( struct V_1 * V_6 )
{
struct V_5 * V_9 ;
T_6 V_28 = 0 ;
V_9 = F_3 ( V_6 ) ;
F_206 ( & V_9 -> V_478 ) ;
V_28 = F_203 ( V_9 ) ;
F_207 ( & V_9 -> V_478 ) ;
return V_28 ;
}
T_6 F_208 ( struct V_1 * V_6 )
{
struct V_5 * V_9 ;
T_6 V_28 = 0 ;
V_9 = F_3 ( V_6 ) ;
F_206 ( & V_9 -> V_478 ) ;
V_28 = F_204 ( V_9 ) ;
F_207 ( & V_9 -> V_478 ) ;
return V_28 ;
}
static T_10 T_6 F_209 ( struct V_5 * V_9 ,
T_2 V_539 , T_2 V_148 , T_2 * V_540 )
{
struct V_541 * V_194 = & V_9 -> V_194 ;
T_6 V_28 = 0 ;
if ( V_194 -> V_20 + V_148 + 2 > V_542 ) {
F_17 ( L_221 ) ;
return - V_543 ;
}
V_194 -> V_68 [ V_194 -> V_20 ] = V_539 ;
V_194 -> V_68 [ V_194 -> V_20 + 1 ] = V_148 ;
memcpy ( & V_194 -> V_68 [ V_194 -> V_20 + 2 ] , V_540 , V_148 ) ;
V_194 -> V_20 += V_148 + 2 ;
return V_28 ;
}
