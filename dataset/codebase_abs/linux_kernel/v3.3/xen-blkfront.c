static int F_1 ( struct V_1 * V_2 )
{
unsigned long free = V_2 -> V_3 ;
F_2 ( free >= V_4 ) ;
V_2 -> V_3 = V_2 -> V_5 [ free ] . V_6 . V_7 . V_8 . V_9 ;
V_2 -> V_5 [ free ] . V_6 . V_7 . V_8 . V_9 = 0x0fffffee ;
return free ;
}
static void F_3 ( struct V_1 * V_2 ,
unsigned long V_9 )
{
V_2 -> V_5 [ V_9 ] . V_6 . V_7 . V_8 . V_9 = V_2 -> V_3 ;
V_2 -> V_5 [ V_9 ] . V_10 = NULL ;
V_2 -> V_3 = V_9 ;
}
static int F_4 ( unsigned int V_11 , unsigned int V_12 )
{
unsigned int V_13 = V_11 + V_12 ;
int V_14 ;
if ( V_13 > V_15 ) {
unsigned long * V_16 , * V_17 ;
V_16 = F_5 ( F_6 ( V_13 ) , sizeof( * V_16 ) ,
V_18 ) ;
if ( V_16 == NULL )
return - V_19 ;
F_7 ( & V_20 ) ;
if ( V_13 > V_15 ) {
V_17 = V_21 ;
memcpy ( V_16 , V_21 ,
F_6 ( V_15 ) * sizeof( * V_16 ) ) ;
V_21 = V_16 ;
V_15 = F_6 ( V_13 ) * V_22 ;
} else
V_17 = V_16 ;
F_8 ( & V_20 ) ;
F_9 ( V_17 ) ;
}
F_7 ( & V_20 ) ;
if ( F_10 ( V_21 , V_13 , V_11 ) >= V_13 ) {
for (; V_11 < V_13 ; ++ V_11 )
F_11 ( V_11 , V_21 ) ;
V_14 = 0 ;
} else
V_14 = - V_23 ;
F_8 ( & V_20 ) ;
return V_14 ;
}
static void F_12 ( unsigned int V_11 , unsigned int V_12 )
{
unsigned int V_13 = V_11 + V_12 ;
F_2 ( V_13 > V_15 ) ;
F_7 ( & V_20 ) ;
for (; V_11 < V_13 ; ++ V_11 )
F_13 ( V_11 , V_21 ) ;
F_8 ( & V_20 ) ;
}
static void F_14 ( void * V_24 )
{
struct V_1 * V_2 = (struct V_1 * ) V_24 ;
F_15 ( & V_2 -> V_25 ) ;
}
static int F_16 ( struct V_26 * V_27 , struct V_28 * V_29 )
{
T_1 V_30 = F_17 ( V_27 -> V_31 ) ;
T_1 V_32 = V_30 ;
V_29 -> V_33 = 0xff ;
V_29 -> V_34 = 0x3f ;
F_18 ( V_32 , V_29 -> V_33 * V_29 -> V_34 ) ;
V_29 -> V_32 = V_32 ;
if ( ( T_1 ) ( V_29 -> V_32 + 1 ) * V_29 -> V_33 * V_29 -> V_34 < V_30 )
V_29 -> V_32 = 0xffff ;
return 0 ;
}
static int F_19 ( struct V_26 * V_35 , T_2 V_36 ,
unsigned V_37 , unsigned long V_38 )
{
struct V_1 * V_2 = V_35 -> V_31 -> V_39 ;
int V_40 ;
F_20 ( & V_2 -> V_41 -> V_42 , L_1 ,
V_37 , ( long ) V_38 ) ;
switch ( V_37 ) {
case V_43 :
F_20 ( & V_2 -> V_41 -> V_42 , L_2 ) ;
for ( V_40 = 0 ; V_40 < sizeof( struct V_44 ) ; V_40 ++ )
if ( F_21 ( 0 , ( char V_45 * ) ( V_38 + V_40 ) ) )
return - V_46 ;
return 0 ;
case V_47 : {
struct V_48 * V_49 = V_2 -> V_49 ;
if ( V_49 -> V_50 & V_51 )
return 0 ;
return - V_52 ;
}
default:
return - V_52 ;
}
return 0 ;
}
static int F_22 ( struct V_10 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_53 -> V_39 ;
unsigned long V_54 ;
struct V_55 * V_56 ;
unsigned long V_9 ;
unsigned int V_57 , V_58 ;
int V_40 , V_59 ;
T_3 V_60 ;
struct V_61 * V_62 ;
if ( F_23 ( V_2 -> V_63 != V_64 ) )
return 1 ;
if ( F_24 (
V_65 , & V_60 ) < 0 ) {
F_25 (
& V_2 -> V_66 ,
F_14 ,
V_2 ,
V_65 ) ;
return 1 ;
}
V_56 = F_26 ( & V_2 -> V_67 , V_2 -> V_67 . V_68 ) ;
V_9 = F_1 ( V_2 ) ;
V_2 -> V_5 [ V_9 ] . V_10 = V_6 ;
V_56 -> V_7 . V_8 . V_9 = V_9 ;
V_56 -> V_7 . V_8 . V_69 = ( V_70 ) F_27 ( V_6 ) ;
V_56 -> V_7 . V_8 . V_71 = V_2 -> V_71 ;
V_56 -> V_72 = F_28 ( V_6 ) ?
V_73 : V_74 ;
if ( V_6 -> V_75 & ( V_76 | V_77 ) ) {
V_56 -> V_72 = V_2 -> V_78 ;
}
if ( F_23 ( V_6 -> V_75 & ( V_79 | V_80 ) ) ) {
V_56 -> V_72 = V_81 ;
V_56 -> V_7 . V_82 . V_83 = F_29 ( V_6 ) ;
if ( ( V_6 -> V_75 & V_80 ) && V_2 -> V_84 )
V_56 -> V_7 . V_82 . V_85 = V_86 ;
else
V_56 -> V_7 . V_82 . V_85 = 0 ;
} else {
V_56 -> V_7 . V_8 . V_87 = F_30 ( V_6 -> V_88 , V_6 ,
V_2 -> V_62 ) ;
F_2 ( V_56 -> V_7 . V_8 . V_87 >
V_65 ) ;
F_31 (info->sg, sg, ring_req->u.rw.nr_segments, i) {
V_54 = F_32 ( F_33 ( F_34 ( V_62 ) ) ) ;
V_57 = V_62 -> V_89 >> 9 ;
V_58 = V_57 + ( V_62 -> V_90 >> 9 ) - 1 ;
V_59 = F_35 ( & V_60 ) ;
F_2 ( V_59 == - V_91 ) ;
F_36 (
V_59 ,
V_2 -> V_41 -> V_92 ,
V_54 ,
F_28 ( V_6 ) ) ;
V_2 -> V_5 [ V_9 ] . V_93 [ V_40 ] = F_37 ( V_54 ) ;
V_56 -> V_7 . V_8 . V_94 [ V_40 ] =
(struct V_95 ) {
. V_96 = V_59 ,
. V_97 = V_57 ,
. V_98 = V_58 } ;
}
}
V_2 -> V_67 . V_68 ++ ;
V_2 -> V_5 [ V_9 ] . V_6 = * V_56 ;
F_38 ( V_60 ) ;
return 0 ;
}
static inline void F_39 ( struct V_1 * V_2 )
{
int V_99 ;
F_40 ( & V_2 -> V_67 , V_99 ) ;
if ( V_99 )
F_41 ( V_2 -> V_100 ) ;
}
static void F_42 ( struct V_101 * V_102 )
{
struct V_1 * V_2 = NULL ;
struct V_10 * V_6 ;
int V_103 ;
F_43 ( L_3 ) ;
V_103 = 0 ;
while ( ( V_6 = F_44 ( V_102 ) ) != NULL ) {
V_2 = V_6 -> V_53 -> V_39 ;
if ( F_45 ( & V_2 -> V_67 ) )
goto V_104;
F_46 ( V_6 ) ;
if ( ( V_6 -> V_105 != V_106 ) ||
( ( V_6 -> V_75 & ( V_76 | V_77 ) ) &&
! V_2 -> V_78 ) ) {
F_47 ( V_6 , - V_107 ) ;
continue;
}
F_43 ( L_4
L_5 ,
V_6 , V_6 -> V_108 , ( unsigned long ) F_27 ( V_6 ) ,
F_48 ( V_6 ) , F_29 ( V_6 ) ,
V_6 -> V_109 , F_28 ( V_6 ) ? L_6 : L_7 ) ;
if ( F_22 ( V_6 ) ) {
F_49 ( V_102 , V_6 ) ;
V_104:
F_50 ( V_102 ) ;
break;
}
V_103 ++ ;
}
if ( V_103 != 0 )
F_39 ( V_2 ) ;
}
static int F_51 ( struct V_48 * V_49 , T_4 V_110 )
{
struct V_101 * V_102 ;
struct V_1 * V_2 = V_49 -> V_39 ;
V_102 = F_52 ( F_42 , & V_111 ) ;
if ( V_102 == NULL )
return - 1 ;
F_53 ( V_112 , V_102 ) ;
if ( V_2 -> V_113 ) {
F_53 ( V_114 , V_102 ) ;
F_54 ( V_102 , F_17 ( V_49 ) ) ;
V_102 -> V_115 . V_116 = V_2 -> V_116 ;
V_102 -> V_115 . V_117 = V_2 -> V_117 ;
if ( V_2 -> V_84 )
F_53 ( V_118 , V_102 ) ;
}
F_55 ( V_102 , V_110 ) ;
F_56 ( V_102 , 512 ) ;
F_57 ( V_102 , V_119 - 1 ) ;
F_58 ( V_102 , V_119 ) ;
F_59 ( V_102 , V_65 ) ;
F_60 ( V_102 , 511 ) ;
F_61 ( V_102 , V_120 ) ;
V_49 -> V_121 = V_102 ;
return 0 ;
}
static void F_62 ( struct V_1 * V_2 )
{
F_63 ( V_2 -> V_102 , V_2 -> V_122 ) ;
F_64 ( V_123 L_8 ,
V_2 -> V_49 -> V_124 ,
V_2 -> V_78 == V_125 ?
L_9 : ( V_2 -> V_78 == V_126 ?
L_10 : L_11 ) ,
V_2 -> V_122 ? L_12 : L_13 ) ;
}
static int F_65 ( int V_127 , int * V_11 , unsigned int * V_89 )
{
int V_128 ;
V_128 = F_66 ( V_127 ) ;
* V_11 = F_67 ( V_127 ) ;
switch ( V_128 ) {
case V_129 :
* V_89 = ( * V_11 / 64 ) + V_130 ;
* V_11 = ( ( * V_11 / 64 ) * V_131 ) +
V_132 ;
break;
case V_133 :
* V_89 = ( * V_11 / 64 ) + 2 + V_130 ;
* V_11 = ( ( ( * V_11 / 64 ) + 2 ) * V_131 ) +
V_132 ;
break;
case V_134 :
* V_89 = ( * V_11 / V_131 ) + V_135 ;
* V_11 = * V_11 + V_136 ;
break;
case V_137 :
case V_138 :
case V_139 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
* V_89 = ( * V_11 / V_131 ) +
( ( V_128 - V_137 + 1 ) * 16 ) +
V_135 ;
* V_11 = * V_11 +
( ( V_128 - V_137 + 1 ) * 16 * V_131 ) +
V_136 ;
break;
case V_144 :
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
* V_89 = ( * V_11 / V_131 ) +
( ( V_128 - V_144 + 8 ) * 16 ) +
V_135 ;
* V_11 = * V_11 +
( ( V_128 - V_144 + 8 ) * 16 * V_131 ) +
V_136 ;
break;
case V_152 :
* V_89 = * V_11 / V_131 ;
break;
default:
F_64 ( V_153 L_14
L_15 ) ;
return - V_154 ;
}
return 0 ;
}
static int F_68 ( V_70 V_155 ,
struct V_1 * V_2 ,
T_4 V_156 , T_4 V_110 )
{
struct V_48 * V_49 ;
int V_15 = 1 ;
int V_157 ;
unsigned int V_89 ;
int V_11 ;
int V_158 ;
F_2 ( V_2 -> V_49 != NULL ) ;
F_2 ( V_2 -> V_102 != NULL ) ;
if ( ( V_2 -> V_127 >> V_159 ) > 1 ) {
F_64 ( V_153 L_16 , V_2 -> V_127 ) ;
return - V_154 ;
}
if ( ! F_69 ( V_2 -> V_127 ) ) {
V_157 = F_65 ( V_2 -> V_127 , & V_11 , & V_89 ) ;
if ( V_157 )
return V_157 ;
V_158 = V_131 ;
} else {
V_11 = F_70 ( V_2 -> V_127 ) ;
V_158 = V_160 ;
V_89 = V_11 / V_158 ;
if ( F_71 () && V_89 < V_130 + 4 )
F_64 ( V_153 L_17
L_18
L_19 , V_2 -> V_127 ) ;
}
V_157 = - V_154 ;
if ( ( V_11 % V_158 ) == 0 )
V_15 = V_158 ;
V_157 = F_4 ( V_11 , V_15 ) ;
if ( V_157 )
goto V_161;
V_157 = - V_154 ;
V_49 = F_72 ( V_15 ) ;
if ( V_49 == NULL )
goto V_162;
if ( V_15 > 1 ) {
if ( V_89 < 26 )
sprintf ( V_49 -> V_124 , L_20 , V_163 , 'a' + V_89 ) ;
else
sprintf ( V_49 -> V_124 , L_21 , V_163 ,
'a' + ( ( V_89 / 26 ) - 1 ) , 'a' + ( V_89 % 26 ) ) ;
} else {
if ( V_89 < 26 )
sprintf ( V_49 -> V_124 , L_22 , V_163 ,
'a' + V_89 ,
V_11 & ( V_158 - 1 ) ) ;
else
sprintf ( V_49 -> V_124 , L_23 , V_163 ,
'a' + ( ( V_89 / 26 ) - 1 ) ,
'a' + ( V_89 % 26 ) ,
V_11 & ( V_158 - 1 ) ) ;
}
V_49 -> V_128 = V_152 ;
V_49 -> V_164 = V_11 ;
V_49 -> V_165 = & V_166 ;
V_49 -> V_39 = V_2 ;
V_49 -> V_167 = & ( V_2 -> V_41 -> V_42 ) ;
F_73 ( V_49 , V_155 ) ;
if ( F_51 ( V_49 , V_110 ) ) {
F_74 ( V_49 ) ;
goto V_162;
}
V_2 -> V_102 = V_49 -> V_121 ;
V_2 -> V_49 = V_49 ;
F_62 ( V_2 ) ;
if ( V_156 & V_168 )
F_75 ( V_49 , 1 ) ;
if ( V_156 & V_169 )
V_49 -> V_50 |= V_170 ;
if ( V_156 & V_171 )
V_49 -> V_50 |= V_51 ;
return 0 ;
V_162:
F_12 ( V_11 , V_15 ) ;
V_161:
return V_157 ;
}
static void F_76 ( struct V_1 * V_2 )
{
unsigned int V_11 , V_15 ;
unsigned long V_50 ;
if ( V_2 -> V_102 == NULL )
return;
F_77 ( & V_111 , V_50 ) ;
F_50 ( V_2 -> V_102 ) ;
F_78 ( & V_2 -> V_66 ) ;
F_79 ( & V_111 , V_50 ) ;
F_80 ( & V_2 -> V_25 ) ;
F_74 ( V_2 -> V_49 ) ;
V_11 = V_2 -> V_49 -> V_164 ;
V_15 = V_2 -> V_49 -> V_21 ;
F_12 ( V_11 , V_15 ) ;
F_81 ( V_2 -> V_102 ) ;
V_2 -> V_102 = NULL ;
F_82 ( V_2 -> V_49 ) ;
V_2 -> V_49 = NULL ;
}
static void F_83 ( struct V_1 * V_2 )
{
if ( ! F_45 ( & V_2 -> V_67 ) ) {
F_84 ( V_2 -> V_102 ) ;
F_42 ( V_2 -> V_102 ) ;
}
}
static void F_85 ( struct V_172 * V_25 )
{
struct V_1 * V_2 = F_86 ( V_25 , struct V_1 , V_25 ) ;
F_87 ( & V_111 ) ;
if ( V_2 -> V_63 == V_64 )
F_83 ( V_2 ) ;
F_88 ( & V_111 ) ;
}
static void F_89 ( struct V_1 * V_2 , int V_173 )
{
F_87 ( & V_111 ) ;
V_2 -> V_63 = V_173 ?
V_174 : V_175 ;
if ( V_2 -> V_102 )
F_50 ( V_2 -> V_102 ) ;
F_78 ( & V_2 -> V_66 ) ;
F_88 ( & V_111 ) ;
F_80 ( & V_2 -> V_25 ) ;
if ( V_2 -> V_176 != V_177 ) {
F_90 ( V_2 -> V_176 , 0 ,
( unsigned long ) V_2 -> V_67 . V_178 ) ;
V_2 -> V_176 = V_177 ;
V_2 -> V_67 . V_178 = NULL ;
}
if ( V_2 -> V_100 )
F_91 ( V_2 -> V_100 , V_2 ) ;
V_2 -> V_179 = V_2 -> V_100 = 0 ;
}
static void F_92 ( struct V_180 * V_181 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_181 -> V_6 . V_7 . V_8 . V_87 ; V_40 ++ )
F_90 ( V_181 -> V_6 . V_7 . V_8 . V_94 [ V_40 ] . V_96 , 0 , 0UL ) ;
}
static T_5 F_93 ( int V_100 , void * V_182 )
{
struct V_10 * V_6 ;
struct V_183 * V_184 ;
T_6 V_40 , V_185 ;
unsigned long V_50 ;
struct V_1 * V_2 = (struct V_1 * ) V_182 ;
int error ;
F_77 ( & V_111 , V_50 ) ;
if ( F_23 ( V_2 -> V_63 != V_64 ) ) {
F_79 ( & V_111 , V_50 ) ;
return V_186 ;
}
V_187:
V_185 = V_2 -> V_67 . V_178 -> V_188 ;
F_94 () ;
for ( V_40 = V_2 -> V_67 . V_189 ; V_40 != V_185 ; V_40 ++ ) {
unsigned long V_9 ;
V_184 = F_95 ( & V_2 -> V_67 , V_40 ) ;
V_9 = V_184 -> V_9 ;
V_6 = V_2 -> V_5 [ V_9 ] . V_10 ;
if ( V_184 -> V_72 != V_81 )
F_92 ( & V_2 -> V_5 [ V_9 ] ) ;
F_3 ( V_2 , V_9 ) ;
error = ( V_184 -> V_190 == V_191 ) ? 0 : - V_107 ;
switch ( V_184 -> V_72 ) {
case V_81 :
if ( F_23 ( V_184 -> V_190 == V_192 ) ) {
struct V_101 * V_102 = V_2 -> V_102 ;
F_64 ( V_153 L_24 ,
V_2 -> V_49 -> V_124 ) ;
error = - V_193 ;
V_2 -> V_113 = 0 ;
V_2 -> V_84 = 0 ;
F_96 ( V_114 , V_102 ) ;
F_96 ( V_118 , V_102 ) ;
}
F_47 ( V_6 , error ) ;
break;
case V_126 :
case V_125 :
if ( F_23 ( V_184 -> V_190 == V_192 ) ) {
F_64 ( V_153 L_25 ,
V_2 -> V_78 == V_125 ?
L_9 : L_26 ,
V_2 -> V_49 -> V_124 ) ;
error = - V_193 ;
}
if ( F_23 ( V_184 -> V_190 == V_194 &&
V_2 -> V_5 [ V_9 ] . V_6 . V_7 . V_8 . V_87 == 0 ) ) {
F_64 ( V_153 L_27 ,
V_2 -> V_78 == V_125 ?
L_9 : L_26 ,
V_2 -> V_49 -> V_124 ) ;
error = - V_193 ;
}
if ( F_23 ( error ) ) {
if ( error == - V_193 )
error = 0 ;
V_2 -> V_122 = 0 ;
V_2 -> V_78 = 0 ;
F_62 ( V_2 ) ;
}
case V_74 :
case V_73 :
if ( F_23 ( V_184 -> V_190 != V_191 ) )
F_20 ( & V_2 -> V_41 -> V_42 , L_28
L_29 , V_184 -> V_190 ) ;
F_47 ( V_6 , error ) ;
break;
default:
F_97 () ;
}
}
V_2 -> V_67 . V_189 = V_40 ;
if ( V_40 != V_2 -> V_67 . V_68 ) {
int V_195 ;
F_98 ( & V_2 -> V_67 , V_195 ) ;
if ( V_195 )
goto V_187;
} else
V_2 -> V_67 . V_178 -> V_196 = V_40 + 1 ;
F_83 ( V_2 ) ;
F_79 ( & V_111 , V_50 ) ;
return V_186 ;
}
static int F_99 ( struct V_197 * V_42 ,
struct V_1 * V_2 )
{
struct V_198 * V_178 ;
int V_157 ;
V_2 -> V_176 = V_177 ;
V_178 = (struct V_198 * ) F_100 ( V_199 | V_200 ) ;
if ( ! V_178 ) {
F_101 ( V_42 , - V_19 , L_30 ) ;
return - V_19 ;
}
F_102 ( V_178 ) ;
F_103 ( & V_2 -> V_67 , V_178 , V_119 ) ;
F_104 ( V_2 -> V_62 , V_65 ) ;
V_157 = F_105 ( V_42 , F_106 ( V_2 -> V_67 . V_178 ) ) ;
if ( V_157 < 0 ) {
F_107 ( ( unsigned long ) V_178 ) ;
V_2 -> V_67 . V_178 = NULL ;
goto V_201;
}
V_2 -> V_176 = V_157 ;
V_157 = F_108 ( V_42 , & V_2 -> V_179 ) ;
if ( V_157 )
goto V_201;
V_157 = F_109 ( V_2 -> V_179 ,
F_93 ,
V_202 , L_31 , V_2 ) ;
if ( V_157 <= 0 ) {
F_101 ( V_42 , V_157 ,
L_32 ) ;
goto V_201;
}
V_2 -> V_100 = V_157 ;
return 0 ;
V_201:
F_89 ( V_2 , 0 ) ;
return V_157 ;
}
static int F_110 ( struct V_197 * V_42 ,
struct V_1 * V_2 )
{
const char * V_203 = NULL ;
struct V_204 V_205 ;
int V_157 ;
V_157 = F_99 ( V_42 , V_2 ) ;
if ( V_157 )
goto V_161;
V_187:
V_157 = F_111 ( & V_205 ) ;
if ( V_157 ) {
F_101 ( V_42 , V_157 , L_33 ) ;
goto V_206;
}
V_157 = F_112 ( V_205 , V_42 -> V_207 ,
L_34 , L_35 , V_2 -> V_176 ) ;
if ( V_157 ) {
V_203 = L_36 ;
goto V_208;
}
V_157 = F_112 ( V_205 , V_42 -> V_207 ,
L_37 , L_35 , V_2 -> V_179 ) ;
if ( V_157 ) {
V_203 = L_38 ;
goto V_208;
}
V_157 = F_112 ( V_205 , V_42 -> V_207 , L_39 , L_40 ,
V_209 ) ;
if ( V_157 ) {
V_203 = L_41 ;
goto V_208;
}
V_157 = F_113 ( V_205 , 0 ) ;
if ( V_157 ) {
if ( V_157 == - V_210 )
goto V_187;
F_101 ( V_42 , V_157 , L_42 ) ;
goto V_206;
}
F_114 ( V_42 , V_211 ) ;
return 0 ;
V_208:
F_113 ( V_205 , 1 ) ;
if ( V_203 )
F_101 ( V_42 , V_157 , L_40 , V_203 ) ;
V_206:
F_89 ( V_2 , 0 ) ;
V_161:
return V_157 ;
}
static int F_115 ( struct V_197 * V_42 ,
const struct V_212 * V_9 )
{
int V_157 , V_127 , V_40 ;
struct V_1 * V_2 ;
V_157 = F_116 ( V_213 , V_42 -> V_207 ,
L_43 , L_44 , & V_127 ) ;
if ( V_157 != 1 ) {
V_157 = F_116 ( V_213 , V_42 -> V_207 , L_45 ,
L_44 , & V_127 ) ;
if ( V_157 != 1 ) {
F_101 ( V_42 , V_157 , L_46 ) ;
return V_157 ;
}
}
if ( F_71 () ) {
char * type ;
int V_214 ;
if ( V_215 & V_216 ) {
int V_128 ;
if ( ! F_69 ( V_127 ) )
V_128 = F_66 ( V_127 ) ;
else
V_128 = V_152 ;
if ( V_128 != V_152 ) {
F_64 ( V_123
L_47 ,
V_217 , V_127 ) ;
return - V_154 ;
}
}
type = F_117 ( V_213 , V_42 -> V_207 , L_48 , & V_214 ) ;
if ( F_118 ( type ) )
return - V_154 ;
if ( strncmp ( type , L_49 , 5 ) == 0 ) {
F_9 ( type ) ;
return - V_154 ;
}
F_9 ( type ) ;
}
V_2 = F_119 ( sizeof( * V_2 ) , V_18 ) ;
if ( ! V_2 ) {
F_101 ( V_42 , - V_19 , L_50 ) ;
return - V_19 ;
}
F_120 ( & V_2 -> V_218 ) ;
V_2 -> V_41 = V_42 ;
V_2 -> V_127 = V_127 ;
V_2 -> V_63 = V_175 ;
F_121 ( & V_2 -> V_25 , F_85 ) ;
for ( V_40 = 0 ; V_40 < V_4 ; V_40 ++ )
V_2 -> V_5 [ V_40 ] . V_6 . V_7 . V_8 . V_9 = V_40 + 1 ;
V_2 -> V_5 [ V_4 - 1 ] . V_6 . V_7 . V_8 . V_9 = 0x0fffffff ;
V_2 -> V_71 = F_122 ( strrchr ( V_42 -> V_207 , '/' ) + 1 , NULL , 0 ) ;
F_123 ( & V_42 -> V_42 , V_2 ) ;
V_157 = F_110 ( V_42 , V_2 ) ;
if ( V_157 ) {
F_9 ( V_2 ) ;
F_123 ( & V_42 -> V_42 , NULL ) ;
return V_157 ;
}
return 0 ;
}
static int F_124 ( struct V_1 * V_2 )
{
int V_40 ;
struct V_55 * V_6 ;
struct V_180 * V_219 ;
int V_220 ;
V_219 = F_125 ( sizeof( V_2 -> V_5 ) ,
V_199 | V_221 | V_200 ) ;
if ( ! V_219 )
return - V_19 ;
memcpy ( V_219 , V_2 -> V_5 , sizeof( V_2 -> V_5 ) ) ;
memset ( & V_2 -> V_5 , 0 , sizeof( V_2 -> V_5 ) ) ;
for ( V_40 = 0 ; V_40 < V_4 ; V_40 ++ )
V_2 -> V_5 [ V_40 ] . V_6 . V_7 . V_8 . V_9 = V_40 + 1 ;
V_2 -> V_3 = V_2 -> V_67 . V_68 ;
V_2 -> V_5 [ V_4 - 1 ] . V_6 . V_7 . V_8 . V_9 = 0x0fffffff ;
for ( V_40 = 0 ; V_40 < V_4 ; V_40 ++ ) {
if ( ! V_219 [ V_40 ] . V_10 )
continue;
V_6 = F_26 ( & V_2 -> V_67 , V_2 -> V_67 . V_68 ) ;
* V_6 = V_219 [ V_40 ] . V_6 ;
V_6 -> V_7 . V_8 . V_9 = F_1 ( V_2 ) ;
memcpy ( & V_2 -> V_5 [ V_6 -> V_7 . V_8 . V_9 ] , & V_219 [ V_40 ] , sizeof( V_219 [ V_40 ] ) ) ;
if ( V_6 -> V_72 != V_81 ) {
for ( V_220 = 0 ; V_220 < V_6 -> V_7 . V_8 . V_87 ; V_220 ++ )
F_36 (
V_6 -> V_7 . V_8 . V_94 [ V_220 ] . V_96 ,
V_2 -> V_41 -> V_92 ,
F_32 ( V_2 -> V_5 [ V_6 -> V_7 . V_8 . V_9 ] . V_93 [ V_220 ] ) ,
F_28 ( V_2 -> V_5 [ V_6 -> V_7 . V_8 . V_9 ] . V_10 ) ) ;
}
V_2 -> V_5 [ V_6 -> V_7 . V_8 . V_9 ] . V_6 = * V_6 ;
V_2 -> V_67 . V_68 ++ ;
}
F_9 ( V_219 ) ;
F_114 ( V_2 -> V_41 , V_222 ) ;
F_87 ( & V_111 ) ;
V_2 -> V_63 = V_64 ;
F_39 ( V_2 ) ;
F_83 ( V_2 ) ;
F_88 ( & V_111 ) ;
return 0 ;
}
static int F_126 ( struct V_197 * V_42 )
{
struct V_1 * V_2 = F_127 ( & V_42 -> V_42 ) ;
int V_157 ;
F_20 ( & V_42 -> V_42 , L_51 , V_42 -> V_207 ) ;
F_89 ( V_2 , V_2 -> V_63 == V_64 ) ;
V_157 = F_110 ( V_42 , V_2 ) ;
if ( V_2 -> V_63 == V_174 && ! V_157 )
V_157 = F_124 ( V_2 ) ;
return V_157 ;
}
static void
F_128 ( struct V_1 * V_2 )
{
struct V_197 * V_41 = V_2 -> V_41 ;
struct V_26 * V_35 = NULL ;
F_129 ( & V_2 -> V_218 ) ;
if ( V_41 -> V_223 == V_224 ) {
F_130 ( & V_2 -> V_218 ) ;
return;
}
if ( V_2 -> V_49 )
V_35 = F_131 ( V_2 -> V_49 , 0 ) ;
F_130 ( & V_2 -> V_218 ) ;
if ( ! V_35 ) {
F_132 ( V_41 ) ;
return;
}
F_129 ( & V_35 -> V_225 ) ;
if ( V_35 -> V_226 ) {
F_133 ( V_41 , - V_23 ,
L_52 ) ;
F_114 ( V_41 , V_224 ) ;
} else {
F_76 ( V_2 ) ;
F_132 ( V_41 ) ;
}
F_130 ( & V_35 -> V_225 ) ;
F_134 ( V_35 ) ;
}
static void F_135 ( struct V_1 * V_2 )
{
int V_157 ;
char * type ;
unsigned int V_116 ;
unsigned int V_117 ;
unsigned int V_227 ;
type = F_117 ( V_213 , V_2 -> V_41 -> V_228 , L_53 , NULL ) ;
if ( F_118 ( type ) )
return;
V_2 -> V_84 = 0 ;
if ( strncmp ( type , L_54 , 3 ) == 0 ) {
V_157 = F_136 ( V_213 , V_2 -> V_41 -> V_228 ,
L_55 , L_35 , & V_116 ,
L_56 , L_35 , & V_117 ,
NULL ) ;
if ( ! V_157 ) {
V_2 -> V_113 = 1 ;
V_2 -> V_116 = V_116 ;
V_2 -> V_117 = V_117 ;
}
V_157 = F_136 ( V_213 , V_2 -> V_41 -> V_228 ,
L_57 , L_58 , & V_227 ,
NULL ) ;
if ( ! V_157 )
V_2 -> V_84 = V_227 ;
} else if ( strncmp ( type , L_59 , 4 ) == 0 )
V_2 -> V_113 = 1 ;
F_9 ( type ) ;
}
static void F_137 ( struct V_1 * V_2 )
{
unsigned long long V_34 ;
unsigned long V_110 ;
unsigned int V_229 ;
int V_157 ;
int V_230 , V_231 , V_82 ;
switch ( V_2 -> V_63 ) {
case V_64 :
V_157 = F_116 ( V_213 , V_2 -> V_41 -> V_228 ,
L_60 , L_61 , & V_34 ) ;
if ( F_138 ( V_157 ) )
return;
F_64 ( V_123 L_62 ,
V_34 ) ;
F_73 ( V_2 -> V_49 , V_34 ) ;
F_139 ( V_2 -> V_49 ) ;
case V_174 :
return;
default:
break;
}
F_20 ( & V_2 -> V_41 -> V_42 , L_63 ,
V_232 , V_2 -> V_41 -> V_228 ) ;
V_157 = F_136 ( V_213 , V_2 -> V_41 -> V_228 ,
L_60 , L_64 , & V_34 ,
L_65 , L_35 , & V_229 ,
L_66 , L_67 , & V_110 ,
NULL ) ;
if ( V_157 ) {
F_101 ( V_2 -> V_41 , V_157 ,
L_68 ,
V_2 -> V_41 -> V_228 ) ;
return;
}
V_2 -> V_122 = 0 ;
V_2 -> V_78 = 0 ;
V_157 = F_136 ( V_213 , V_2 -> V_41 -> V_228 ,
L_69 , L_58 , & V_230 ,
NULL ) ;
if ( ! V_157 && V_230 ) {
V_2 -> V_122 = V_76 | V_77 ;
V_2 -> V_78 = V_125 ;
}
V_157 = F_136 ( V_213 , V_2 -> V_41 -> V_228 ,
L_70 , L_58 , & V_231 ,
NULL ) ;
if ( ! V_157 && V_231 ) {
V_2 -> V_122 = V_76 ;
V_2 -> V_78 = V_126 ;
}
V_157 = F_136 ( V_213 , V_2 -> V_41 -> V_228 ,
L_71 , L_58 , & V_82 ,
NULL ) ;
if ( ! V_157 && V_82 )
F_135 ( V_2 ) ;
V_157 = F_68 ( V_34 , V_2 , V_229 , V_110 ) ;
if ( V_157 ) {
F_101 ( V_2 -> V_41 , V_157 , L_72 ,
V_2 -> V_41 -> V_228 ) ;
return;
}
F_114 ( V_2 -> V_41 , V_222 ) ;
F_87 ( & V_111 ) ;
V_2 -> V_63 = V_64 ;
F_83 ( V_2 ) ;
F_88 ( & V_111 ) ;
F_140 ( V_2 -> V_49 ) ;
V_2 -> V_233 = 1 ;
}
static void F_141 ( struct V_197 * V_42 ,
enum V_234 V_235 )
{
struct V_1 * V_2 = F_127 ( & V_42 -> V_42 ) ;
F_20 ( & V_42 -> V_42 , L_73 , V_235 ) ;
switch ( V_235 ) {
case V_236 :
case V_237 :
case V_211 :
case V_238 :
case V_239 :
case V_240 :
case V_241 :
break;
case V_222 :
F_137 ( V_2 ) ;
break;
case V_224 :
F_128 ( V_2 ) ;
break;
}
}
static int F_142 ( struct V_197 * V_41 )
{
struct V_1 * V_2 = F_127 ( & V_41 -> V_42 ) ;
struct V_26 * V_35 = NULL ;
struct V_48 * V_242 ;
F_20 ( & V_41 -> V_42 , L_74 , V_41 -> V_207 ) ;
F_89 ( V_2 , 0 ) ;
F_129 ( & V_2 -> V_218 ) ;
V_242 = V_2 -> V_49 ;
if ( V_242 )
V_35 = F_131 ( V_242 , 0 ) ;
V_2 -> V_41 = NULL ;
F_130 ( & V_2 -> V_218 ) ;
if ( ! V_35 ) {
F_9 ( V_2 ) ;
return 0 ;
}
F_129 ( & V_35 -> V_225 ) ;
V_2 = V_242 -> V_39 ;
F_143 ( F_144 ( V_242 ) ,
L_75 ,
V_41 -> V_207 , V_35 -> V_226 ) ;
if ( V_2 && ! V_35 -> V_226 ) {
F_76 ( V_2 ) ;
V_242 -> V_39 = NULL ;
F_9 ( V_2 ) ;
}
F_130 ( & V_35 -> V_225 ) ;
F_134 ( V_35 ) ;
return 0 ;
}
static int F_145 ( struct V_197 * V_42 )
{
struct V_1 * V_2 = F_127 ( & V_42 -> V_42 ) ;
return V_2 -> V_233 && V_2 -> V_41 ;
}
static int F_146 ( struct V_26 * V_35 , T_2 V_36 )
{
struct V_48 * V_242 = V_35 -> V_31 ;
struct V_1 * V_2 ;
int V_157 = 0 ;
F_129 ( & V_243 ) ;
V_2 = V_242 -> V_39 ;
if ( ! V_2 ) {
V_157 = - V_244 ;
goto V_161;
}
F_129 ( & V_2 -> V_218 ) ;
if ( ! V_2 -> V_49 )
V_157 = - V_244 ;
F_130 ( & V_2 -> V_218 ) ;
V_161:
F_130 ( & V_243 ) ;
return V_157 ;
}
static int F_147 ( struct V_48 * V_242 , T_2 V_36 )
{
struct V_1 * V_2 = V_242 -> V_39 ;
struct V_26 * V_35 ;
struct V_197 * V_41 ;
F_129 ( & V_243 ) ;
V_35 = F_131 ( V_242 , 0 ) ;
F_134 ( V_35 ) ;
if ( V_35 -> V_226 )
goto V_161;
F_129 ( & V_2 -> V_218 ) ;
V_41 = V_2 -> V_41 ;
if ( V_41 && V_41 -> V_223 == V_224 ) {
F_148 ( F_144 ( V_35 -> V_31 ) , L_76 ) ;
F_76 ( V_2 ) ;
F_132 ( V_2 -> V_41 ) ;
}
F_130 ( & V_2 -> V_218 ) ;
if ( ! V_41 ) {
F_148 ( F_144 ( V_35 -> V_31 ) , L_76 ) ;
F_76 ( V_2 ) ;
V_242 -> V_39 = NULL ;
F_9 ( V_2 ) ;
}
V_161:
F_130 ( & V_243 ) ;
return 0 ;
}
static int T_7 F_149 ( void )
{
int V_245 ;
if ( ! F_150 () )
return - V_154 ;
if ( F_151 ( V_152 , V_163 ) ) {
F_64 ( V_153 L_77 ,
V_152 , V_163 ) ;
return - V_154 ;
}
V_245 = F_152 ( & V_246 ) ;
if ( V_245 ) {
F_153 ( V_152 , V_163 ) ;
return V_245 ;
}
return 0 ;
}
static void T_8 F_154 ( void )
{
return F_155 ( & V_246 ) ;
}
