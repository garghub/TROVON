static int F_1 ( struct V_1 * V_2 )
{
unsigned long free = V_2 -> V_3 ;
F_2 ( free >= V_4 ) ;
V_2 -> V_3 = V_2 -> V_5 [ free ] . V_6 . V_7 ;
V_2 -> V_5 [ free ] . V_6 . V_7 = 0x0fffffee ;
return free ;
}
static void F_3 ( struct V_1 * V_2 ,
unsigned long V_7 )
{
V_2 -> V_5 [ V_7 ] . V_6 . V_7 = V_2 -> V_3 ;
V_2 -> V_5 [ V_7 ] . V_8 = NULL ;
V_2 -> V_3 = V_7 ;
}
static int F_4 ( unsigned int V_9 , unsigned int V_10 )
{
unsigned int V_11 = V_9 + V_10 ;
int V_12 ;
if ( V_11 > V_13 ) {
unsigned long * V_14 , * V_15 ;
V_14 = F_5 ( F_6 ( V_11 ) * sizeof( * V_14 ) ,
V_16 ) ;
if ( V_14 == NULL )
return - V_17 ;
F_7 ( & V_18 ) ;
if ( V_11 > V_13 ) {
V_15 = V_19 ;
memcpy ( V_14 , V_19 ,
F_6 ( V_13 ) * sizeof( * V_14 ) ) ;
V_19 = V_14 ;
V_13 = F_6 ( V_11 ) * V_20 ;
} else
V_15 = V_14 ;
F_8 ( & V_18 ) ;
F_9 ( V_15 ) ;
}
F_7 ( & V_18 ) ;
if ( F_10 ( V_19 , V_11 , V_9 ) >= V_11 ) {
for (; V_9 < V_11 ; ++ V_9 )
F_11 ( V_9 , V_19 ) ;
V_12 = 0 ;
} else
V_12 = - V_21 ;
F_8 ( & V_18 ) ;
return V_12 ;
}
static void F_12 ( unsigned int V_9 , unsigned int V_10 )
{
unsigned int V_11 = V_9 + V_10 ;
F_2 ( V_11 > V_13 ) ;
F_7 ( & V_18 ) ;
for (; V_9 < V_11 ; ++ V_9 )
F_13 ( V_9 , V_19 ) ;
F_8 ( & V_18 ) ;
}
static void F_14 ( void * V_22 )
{
struct V_1 * V_2 = (struct V_1 * ) V_22 ;
F_15 ( & V_2 -> V_23 ) ;
}
static int F_16 ( struct V_24 * V_25 , struct V_26 * V_27 )
{
T_1 V_28 = F_17 ( V_25 -> V_29 ) ;
T_1 V_30 = V_28 ;
V_27 -> V_31 = 0xff ;
V_27 -> V_32 = 0x3f ;
F_18 ( V_30 , V_27 -> V_31 * V_27 -> V_32 ) ;
V_27 -> V_30 = V_30 ;
if ( ( T_1 ) ( V_27 -> V_30 + 1 ) * V_27 -> V_31 * V_27 -> V_32 < V_28 )
V_27 -> V_30 = 0xffff ;
return 0 ;
}
static int F_19 ( struct V_24 * V_33 , T_2 V_34 ,
unsigned V_35 , unsigned long V_36 )
{
struct V_1 * V_2 = V_33 -> V_29 -> V_37 ;
int V_38 ;
F_20 ( & V_2 -> V_39 -> V_40 , L_1 ,
V_35 , ( long ) V_36 ) ;
switch ( V_35 ) {
case V_41 :
F_20 ( & V_2 -> V_39 -> V_40 , L_2 ) ;
for ( V_38 = 0 ; V_38 < sizeof( struct V_42 ) ; V_38 ++ )
if ( F_21 ( 0 , ( char V_43 * ) ( V_36 + V_38 ) ) )
return - V_44 ;
return 0 ;
case V_45 : {
struct V_46 * V_47 = V_2 -> V_47 ;
if ( V_47 -> V_48 & V_49 )
return 0 ;
return - V_50 ;
}
default:
return - V_50 ;
}
return 0 ;
}
static int F_22 ( struct V_8 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_51 -> V_37 ;
unsigned long V_52 ;
struct V_53 * V_54 ;
unsigned long V_7 ;
unsigned int V_55 , V_56 ;
int V_38 , V_57 ;
T_3 V_58 ;
struct V_59 * V_60 ;
if ( F_23 ( V_2 -> V_61 != V_62 ) )
return 1 ;
if ( F_24 (
V_63 , & V_58 ) < 0 ) {
F_25 (
& V_2 -> V_64 ,
F_14 ,
V_2 ,
V_63 ) ;
return 1 ;
}
V_54 = F_26 ( & V_2 -> V_65 , V_2 -> V_65 . V_66 ) ;
V_7 = F_1 ( V_2 ) ;
V_2 -> V_5 [ V_7 ] . V_8 = V_6 ;
V_54 -> V_7 = V_7 ;
V_54 -> V_67 . V_68 . V_69 = ( V_70 ) F_27 ( V_6 ) ;
V_54 -> V_71 = V_2 -> V_71 ;
V_54 -> V_72 = F_28 ( V_6 ) ?
V_73 : V_74 ;
if ( V_6 -> V_75 & ( V_76 | V_77 ) ) {
V_54 -> V_72 = V_2 -> V_78 ;
}
if ( F_23 ( V_6 -> V_75 & V_79 ) ) {
V_54 -> V_72 = V_80 ;
V_54 -> V_81 = 0 ;
V_54 -> V_67 . V_82 . V_83 = F_29 ( V_6 ) ;
} else {
V_54 -> V_81 = F_30 ( V_6 -> V_84 , V_6 , V_2 -> V_60 ) ;
F_2 ( V_54 -> V_81 > V_63 ) ;
F_31 (info->sg, sg, ring_req->nr_segments, i) {
V_52 = F_32 ( F_33 ( F_34 ( V_60 ) ) ) ;
V_55 = V_60 -> V_85 >> 9 ;
V_56 = V_55 + ( V_60 -> V_86 >> 9 ) - 1 ;
V_57 = F_35 ( & V_58 ) ;
F_2 ( V_57 == - V_87 ) ;
F_36 (
V_57 ,
V_2 -> V_39 -> V_88 ,
V_52 ,
F_28 ( V_6 ) ) ;
V_2 -> V_5 [ V_7 ] . V_89 [ V_38 ] = F_37 ( V_52 ) ;
V_54 -> V_67 . V_68 . V_90 [ V_38 ] =
(struct V_91 ) {
. V_92 = V_57 ,
. V_93 = V_55 ,
. V_94 = V_56 } ;
}
}
V_2 -> V_65 . V_66 ++ ;
V_2 -> V_5 [ V_7 ] . V_6 = * V_54 ;
F_38 ( V_58 ) ;
return 0 ;
}
static inline void F_39 ( struct V_1 * V_2 )
{
int V_95 ;
F_40 ( & V_2 -> V_65 , V_95 ) ;
if ( V_95 )
F_41 ( V_2 -> V_96 ) ;
}
static void F_42 ( struct V_97 * V_98 )
{
struct V_1 * V_2 = NULL ;
struct V_8 * V_6 ;
int V_99 ;
F_43 ( L_3 ) ;
V_99 = 0 ;
while ( ( V_6 = F_44 ( V_98 ) ) != NULL ) {
V_2 = V_6 -> V_51 -> V_37 ;
if ( F_45 ( & V_2 -> V_65 ) )
goto V_100;
F_46 ( V_6 ) ;
if ( ( V_6 -> V_101 != V_102 ) ||
( ( V_6 -> V_75 & ( V_76 | V_77 ) ) &&
! V_2 -> V_78 ) ) {
F_47 ( V_6 , - V_103 ) ;
continue;
}
F_43 ( L_4
L_5 ,
V_6 , V_6 -> V_104 , ( unsigned long ) F_27 ( V_6 ) ,
F_48 ( V_6 ) , F_29 ( V_6 ) ,
V_6 -> V_105 , F_28 ( V_6 ) ? L_6 : L_7 ) ;
if ( F_22 ( V_6 ) ) {
F_49 ( V_98 , V_6 ) ;
V_100:
F_50 ( V_98 ) ;
break;
}
V_99 ++ ;
}
if ( V_99 != 0 )
F_39 ( V_2 ) ;
}
static int F_51 ( struct V_46 * V_47 , T_4 V_106 )
{
struct V_97 * V_98 ;
struct V_1 * V_2 = V_47 -> V_37 ;
V_98 = F_52 ( F_42 , & V_107 ) ;
if ( V_98 == NULL )
return - 1 ;
F_53 ( V_108 , V_98 ) ;
if ( V_2 -> V_109 ) {
F_53 ( V_110 , V_98 ) ;
F_54 ( V_98 , F_17 ( V_47 ) ) ;
V_98 -> V_111 . V_112 = V_2 -> V_112 ;
V_98 -> V_111 . V_113 = V_2 -> V_113 ;
}
F_55 ( V_98 , V_106 ) ;
F_56 ( V_98 , 512 ) ;
F_57 ( V_98 , V_114 - 1 ) ;
F_58 ( V_98 , V_114 ) ;
F_59 ( V_98 , V_63 ) ;
F_60 ( V_98 , 511 ) ;
F_61 ( V_98 , V_115 ) ;
V_47 -> V_116 = V_98 ;
return 0 ;
}
static void F_62 ( struct V_1 * V_2 )
{
F_63 ( V_2 -> V_98 , V_2 -> V_117 ) ;
F_64 ( V_118 L_8 ,
V_2 -> V_47 -> V_119 ,
V_2 -> V_78 == V_120 ?
L_9 : ( V_2 -> V_78 == V_121 ?
L_10 : L_11 ) ,
V_2 -> V_117 ? L_12 : L_13 ) ;
}
static int F_65 ( int V_122 , int * V_9 , unsigned int * V_85 )
{
int V_123 ;
V_123 = F_66 ( V_122 ) ;
* V_9 = F_67 ( V_122 ) ;
switch ( V_123 ) {
case V_124 :
* V_85 = ( * V_9 / 64 ) + V_125 ;
* V_9 = ( ( * V_9 / 64 ) * V_126 ) +
V_127 ;
break;
case V_128 :
* V_85 = ( * V_9 / 64 ) + 2 + V_125 ;
* V_9 = ( ( ( * V_9 / 64 ) + 2 ) * V_126 ) +
V_127 ;
break;
case V_129 :
* V_85 = ( * V_9 / V_126 ) + V_130 ;
* V_9 = * V_9 + V_131 ;
break;
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
* V_85 = ( * V_9 / V_126 ) +
( ( V_123 - V_132 + 1 ) * 16 ) +
V_130 ;
* V_9 = * V_9 +
( ( V_123 - V_132 + 1 ) * 16 * V_126 ) +
V_131 ;
break;
case V_139 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
case V_145 :
case V_146 :
* V_85 = ( * V_9 / V_126 ) +
( ( V_123 - V_139 + 8 ) * 16 ) +
V_130 ;
* V_9 = * V_9 +
( ( V_123 - V_139 + 8 ) * 16 * V_126 ) +
V_131 ;
break;
case V_147 :
* V_85 = * V_9 / V_126 ;
break;
default:
F_64 ( V_148 L_14
L_15 ) ;
return - V_149 ;
}
return 0 ;
}
static int F_68 ( V_70 V_150 ,
struct V_1 * V_2 ,
T_4 V_151 , T_4 V_106 )
{
struct V_46 * V_47 ;
int V_13 = 1 ;
int V_152 ;
unsigned int V_85 ;
int V_9 ;
int V_153 ;
F_2 ( V_2 -> V_47 != NULL ) ;
F_2 ( V_2 -> V_98 != NULL ) ;
if ( ( V_2 -> V_122 >> V_154 ) > 1 ) {
F_64 ( V_148 L_16 , V_2 -> V_122 ) ;
return - V_149 ;
}
if ( ! F_69 ( V_2 -> V_122 ) ) {
V_152 = F_65 ( V_2 -> V_122 , & V_9 , & V_85 ) ;
if ( V_152 )
return V_152 ;
V_153 = V_126 ;
} else {
V_9 = F_70 ( V_2 -> V_122 ) ;
V_153 = V_155 ;
V_85 = V_9 / V_153 ;
if ( F_71 () && V_85 < V_125 + 4 )
F_64 ( V_148 L_17
L_18
L_19 , V_2 -> V_122 ) ;
}
V_152 = - V_149 ;
if ( ( V_9 % V_153 ) == 0 )
V_13 = V_153 ;
V_152 = F_4 ( V_9 , V_13 ) ;
if ( V_152 )
goto V_156;
V_152 = - V_149 ;
V_47 = F_72 ( V_13 ) ;
if ( V_47 == NULL )
goto V_157;
if ( V_13 > 1 ) {
if ( V_85 < 26 )
sprintf ( V_47 -> V_119 , L_20 , V_158 , 'a' + V_85 ) ;
else
sprintf ( V_47 -> V_119 , L_21 , V_158 ,
'a' + ( ( V_85 / 26 ) - 1 ) , 'a' + ( V_85 % 26 ) ) ;
} else {
if ( V_85 < 26 )
sprintf ( V_47 -> V_119 , L_22 , V_158 ,
'a' + V_85 ,
V_9 & ( V_153 - 1 ) ) ;
else
sprintf ( V_47 -> V_119 , L_23 , V_158 ,
'a' + ( ( V_85 / 26 ) - 1 ) ,
'a' + ( V_85 % 26 ) ,
V_9 & ( V_153 - 1 ) ) ;
}
V_47 -> V_123 = V_147 ;
V_47 -> V_159 = V_9 ;
V_47 -> V_160 = & V_161 ;
V_47 -> V_37 = V_2 ;
V_47 -> V_162 = & ( V_2 -> V_39 -> V_40 ) ;
F_73 ( V_47 , V_150 ) ;
if ( F_51 ( V_47 , V_106 ) ) {
F_74 ( V_47 ) ;
goto V_157;
}
V_2 -> V_98 = V_47 -> V_116 ;
V_2 -> V_47 = V_47 ;
F_62 ( V_2 ) ;
if ( V_151 & V_163 )
F_75 ( V_47 , 1 ) ;
if ( V_151 & V_164 )
V_47 -> V_48 |= V_165 ;
if ( V_151 & V_166 )
V_47 -> V_48 |= V_49 ;
return 0 ;
V_157:
F_12 ( V_9 , V_13 ) ;
V_156:
return V_152 ;
}
static void F_76 ( struct V_1 * V_2 )
{
unsigned int V_9 , V_13 ;
unsigned long V_48 ;
if ( V_2 -> V_98 == NULL )
return;
F_77 ( & V_107 , V_48 ) ;
F_50 ( V_2 -> V_98 ) ;
F_78 ( & V_2 -> V_64 ) ;
F_79 ( & V_107 , V_48 ) ;
F_80 ( & V_2 -> V_23 ) ;
F_74 ( V_2 -> V_47 ) ;
V_9 = V_2 -> V_47 -> V_159 ;
V_13 = V_2 -> V_47 -> V_19 ;
F_12 ( V_9 , V_13 ) ;
F_81 ( V_2 -> V_98 ) ;
V_2 -> V_98 = NULL ;
F_82 ( V_2 -> V_47 ) ;
V_2 -> V_47 = NULL ;
}
static void F_83 ( struct V_1 * V_2 )
{
if ( ! F_45 ( & V_2 -> V_65 ) ) {
F_84 ( V_2 -> V_98 ) ;
F_42 ( V_2 -> V_98 ) ;
}
}
static void F_85 ( struct V_167 * V_23 )
{
struct V_1 * V_2 = F_86 ( V_23 , struct V_1 , V_23 ) ;
F_87 ( & V_107 ) ;
if ( V_2 -> V_61 == V_62 )
F_83 ( V_2 ) ;
F_88 ( & V_107 ) ;
}
static void F_89 ( struct V_1 * V_2 , int V_168 )
{
F_87 ( & V_107 ) ;
V_2 -> V_61 = V_168 ?
V_169 : V_170 ;
if ( V_2 -> V_98 )
F_50 ( V_2 -> V_98 ) ;
F_78 ( & V_2 -> V_64 ) ;
F_88 ( & V_107 ) ;
F_80 ( & V_2 -> V_23 ) ;
if ( V_2 -> V_171 != V_172 ) {
F_90 ( V_2 -> V_171 , 0 ,
( unsigned long ) V_2 -> V_65 . V_173 ) ;
V_2 -> V_171 = V_172 ;
V_2 -> V_65 . V_173 = NULL ;
}
if ( V_2 -> V_96 )
F_91 ( V_2 -> V_96 , V_2 ) ;
V_2 -> V_174 = V_2 -> V_96 = 0 ;
}
static void F_92 ( struct V_175 * V_176 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_176 -> V_6 . V_81 ; V_38 ++ )
F_90 ( V_176 -> V_6 . V_67 . V_68 . V_90 [ V_38 ] . V_92 , 0 , 0UL ) ;
}
static T_5 F_93 ( int V_96 , void * V_177 )
{
struct V_8 * V_6 ;
struct V_178 * V_179 ;
T_6 V_38 , V_180 ;
unsigned long V_48 ;
struct V_1 * V_2 = (struct V_1 * ) V_177 ;
int error ;
F_77 ( & V_107 , V_48 ) ;
if ( F_23 ( V_2 -> V_61 != V_62 ) ) {
F_79 ( & V_107 , V_48 ) ;
return V_181 ;
}
V_182:
V_180 = V_2 -> V_65 . V_173 -> V_183 ;
F_94 () ;
for ( V_38 = V_2 -> V_65 . V_184 ; V_38 != V_180 ; V_38 ++ ) {
unsigned long V_7 ;
V_179 = F_95 ( & V_2 -> V_65 , V_38 ) ;
V_7 = V_179 -> V_7 ;
V_6 = V_2 -> V_5 [ V_7 ] . V_8 ;
F_92 ( & V_2 -> V_5 [ V_7 ] ) ;
F_3 ( V_2 , V_7 ) ;
error = ( V_179 -> V_185 == V_186 ) ? 0 : - V_103 ;
switch ( V_179 -> V_72 ) {
case V_80 :
if ( F_23 ( V_179 -> V_185 == V_187 ) ) {
struct V_97 * V_98 = V_2 -> V_98 ;
F_64 ( V_148 L_24 ,
V_2 -> V_47 -> V_119 ) ;
error = - V_188 ;
V_2 -> V_109 = 0 ;
F_96 ( V_110 , V_98 ) ;
}
F_47 ( V_6 , error ) ;
break;
case V_121 :
case V_120 :
if ( F_23 ( V_179 -> V_185 == V_187 ) ) {
F_64 ( V_148 L_25 ,
V_2 -> V_78 == V_120 ?
L_9 : L_26 ,
V_2 -> V_47 -> V_119 ) ;
error = - V_188 ;
}
if ( F_23 ( V_179 -> V_185 == V_189 &&
V_2 -> V_5 [ V_7 ] . V_6 . V_81 == 0 ) ) {
F_64 ( V_148 L_27 ,
V_2 -> V_78 == V_120 ?
L_9 : L_26 ,
V_2 -> V_47 -> V_119 ) ;
error = - V_188 ;
}
if ( F_23 ( error ) ) {
if ( error == - V_188 )
error = 0 ;
V_2 -> V_117 = 0 ;
V_2 -> V_78 = 0 ;
F_62 ( V_2 ) ;
}
case V_74 :
case V_73 :
if ( F_23 ( V_179 -> V_185 != V_186 ) )
F_20 ( & V_2 -> V_39 -> V_40 , L_28
L_29 , V_179 -> V_185 ) ;
F_47 ( V_6 , error ) ;
break;
default:
F_97 () ;
}
}
V_2 -> V_65 . V_184 = V_38 ;
if ( V_38 != V_2 -> V_65 . V_66 ) {
int V_190 ;
F_98 ( & V_2 -> V_65 , V_190 ) ;
if ( V_190 )
goto V_182;
} else
V_2 -> V_65 . V_173 -> V_191 = V_38 + 1 ;
F_83 ( V_2 ) ;
F_79 ( & V_107 , V_48 ) ;
return V_181 ;
}
static int F_99 ( struct V_192 * V_40 ,
struct V_1 * V_2 )
{
struct V_193 * V_173 ;
int V_152 ;
V_2 -> V_171 = V_172 ;
V_173 = (struct V_193 * ) F_100 ( V_194 | V_195 ) ;
if ( ! V_173 ) {
F_101 ( V_40 , - V_17 , L_30 ) ;
return - V_17 ;
}
F_102 ( V_173 ) ;
F_103 ( & V_2 -> V_65 , V_173 , V_114 ) ;
F_104 ( V_2 -> V_60 , V_63 ) ;
V_152 = F_105 ( V_40 , F_106 ( V_2 -> V_65 . V_173 ) ) ;
if ( V_152 < 0 ) {
F_107 ( ( unsigned long ) V_173 ) ;
V_2 -> V_65 . V_173 = NULL ;
goto V_196;
}
V_2 -> V_171 = V_152 ;
V_152 = F_108 ( V_40 , & V_2 -> V_174 ) ;
if ( V_152 )
goto V_196;
V_152 = F_109 ( V_2 -> V_174 ,
F_93 ,
V_197 , L_31 , V_2 ) ;
if ( V_152 <= 0 ) {
F_101 ( V_40 , V_152 ,
L_32 ) ;
goto V_196;
}
V_2 -> V_96 = V_152 ;
return 0 ;
V_196:
F_89 ( V_2 , 0 ) ;
return V_152 ;
}
static int F_110 ( struct V_192 * V_40 ,
struct V_1 * V_2 )
{
const char * V_198 = NULL ;
struct V_199 V_200 ;
int V_152 ;
V_152 = F_99 ( V_40 , V_2 ) ;
if ( V_152 )
goto V_156;
V_182:
V_152 = F_111 ( & V_200 ) ;
if ( V_152 ) {
F_101 ( V_40 , V_152 , L_33 ) ;
goto V_201;
}
V_152 = F_112 ( V_200 , V_40 -> V_202 ,
L_34 , L_35 , V_2 -> V_171 ) ;
if ( V_152 ) {
V_198 = L_36 ;
goto V_203;
}
V_152 = F_112 ( V_200 , V_40 -> V_202 ,
L_37 , L_35 , V_2 -> V_174 ) ;
if ( V_152 ) {
V_198 = L_38 ;
goto V_203;
}
V_152 = F_112 ( V_200 , V_40 -> V_202 , L_39 , L_40 ,
V_204 ) ;
if ( V_152 ) {
V_198 = L_41 ;
goto V_203;
}
V_152 = F_113 ( V_200 , 0 ) ;
if ( V_152 ) {
if ( V_152 == - V_205 )
goto V_182;
F_101 ( V_40 , V_152 , L_42 ) ;
goto V_201;
}
F_114 ( V_40 , V_206 ) ;
return 0 ;
V_203:
F_113 ( V_200 , 1 ) ;
if ( V_198 )
F_101 ( V_40 , V_152 , L_40 , V_198 ) ;
V_201:
F_89 ( V_2 , 0 ) ;
V_156:
return V_152 ;
}
static int F_115 ( struct V_192 * V_40 ,
const struct V_207 * V_7 )
{
int V_152 , V_122 , V_38 ;
struct V_1 * V_2 ;
V_152 = F_116 ( V_208 , V_40 -> V_202 ,
L_43 , L_44 , & V_122 ) ;
if ( V_152 != 1 ) {
V_152 = F_116 ( V_208 , V_40 -> V_202 , L_45 ,
L_44 , & V_122 ) ;
if ( V_152 != 1 ) {
F_101 ( V_40 , V_152 , L_46 ) ;
return V_152 ;
}
}
if ( F_71 () ) {
char * type ;
int V_209 ;
if ( V_210 & V_211 ) {
int V_123 ;
if ( ! F_69 ( V_122 ) )
V_123 = F_66 ( V_122 ) ;
else
V_123 = V_147 ;
if ( V_123 != V_147 ) {
F_64 ( V_118
L_47 ,
V_212 , V_122 ) ;
return - V_149 ;
}
}
type = F_117 ( V_208 , V_40 -> V_202 , L_48 , & V_209 ) ;
if ( F_118 ( type ) )
return - V_149 ;
if ( strncmp ( type , L_49 , 5 ) == 0 ) {
F_9 ( type ) ;
return - V_149 ;
}
F_9 ( type ) ;
}
V_2 = F_5 ( sizeof( * V_2 ) , V_16 ) ;
if ( ! V_2 ) {
F_101 ( V_40 , - V_17 , L_50 ) ;
return - V_17 ;
}
F_119 ( & V_2 -> V_213 ) ;
V_2 -> V_39 = V_40 ;
V_2 -> V_122 = V_122 ;
V_2 -> V_61 = V_170 ;
F_120 ( & V_2 -> V_23 , F_85 ) ;
for ( V_38 = 0 ; V_38 < V_4 ; V_38 ++ )
V_2 -> V_5 [ V_38 ] . V_6 . V_7 = V_38 + 1 ;
V_2 -> V_5 [ V_4 - 1 ] . V_6 . V_7 = 0x0fffffff ;
V_2 -> V_71 = F_121 ( strrchr ( V_40 -> V_202 , '/' ) + 1 , NULL , 0 ) ;
F_122 ( & V_40 -> V_40 , V_2 ) ;
V_152 = F_110 ( V_40 , V_2 ) ;
if ( V_152 ) {
F_9 ( V_2 ) ;
F_122 ( & V_40 -> V_40 , NULL ) ;
return V_152 ;
}
return 0 ;
}
static int F_123 ( struct V_1 * V_2 )
{
int V_38 ;
struct V_53 * V_6 ;
struct V_175 * V_214 ;
int V_215 ;
V_214 = F_124 ( sizeof( V_2 -> V_5 ) ,
V_194 | V_216 | V_195 ) ;
if ( ! V_214 )
return - V_17 ;
memcpy ( V_214 , V_2 -> V_5 , sizeof( V_2 -> V_5 ) ) ;
memset ( & V_2 -> V_5 , 0 , sizeof( V_2 -> V_5 ) ) ;
for ( V_38 = 0 ; V_38 < V_4 ; V_38 ++ )
V_2 -> V_5 [ V_38 ] . V_6 . V_7 = V_38 + 1 ;
V_2 -> V_3 = V_2 -> V_65 . V_66 ;
V_2 -> V_5 [ V_4 - 1 ] . V_6 . V_7 = 0x0fffffff ;
for ( V_38 = 0 ; V_38 < V_4 ; V_38 ++ ) {
if ( ! V_214 [ V_38 ] . V_8 )
continue;
V_6 = F_26 ( & V_2 -> V_65 , V_2 -> V_65 . V_66 ) ;
* V_6 = V_214 [ V_38 ] . V_6 ;
V_6 -> V_7 = F_1 ( V_2 ) ;
memcpy ( & V_2 -> V_5 [ V_6 -> V_7 ] , & V_214 [ V_38 ] , sizeof( V_214 [ V_38 ] ) ) ;
for ( V_215 = 0 ; V_215 < V_6 -> V_81 ; V_215 ++ )
F_36 (
V_6 -> V_67 . V_68 . V_90 [ V_215 ] . V_92 ,
V_2 -> V_39 -> V_88 ,
F_32 ( V_2 -> V_5 [ V_6 -> V_7 ] . V_89 [ V_215 ] ) ,
F_28 ( V_2 -> V_5 [ V_6 -> V_7 ] . V_8 ) ) ;
V_2 -> V_5 [ V_6 -> V_7 ] . V_6 = * V_6 ;
V_2 -> V_65 . V_66 ++ ;
}
F_9 ( V_214 ) ;
F_114 ( V_2 -> V_39 , V_217 ) ;
F_87 ( & V_107 ) ;
V_2 -> V_61 = V_62 ;
F_39 ( V_2 ) ;
F_83 ( V_2 ) ;
F_88 ( & V_107 ) ;
return 0 ;
}
static int F_125 ( struct V_192 * V_40 )
{
struct V_1 * V_2 = F_126 ( & V_40 -> V_40 ) ;
int V_152 ;
F_20 ( & V_40 -> V_40 , L_51 , V_40 -> V_202 ) ;
F_89 ( V_2 , V_2 -> V_61 == V_62 ) ;
V_152 = F_110 ( V_40 , V_2 ) ;
if ( V_2 -> V_61 == V_169 && ! V_152 )
V_152 = F_123 ( V_2 ) ;
return V_152 ;
}
static void
F_127 ( struct V_1 * V_2 )
{
struct V_192 * V_39 = V_2 -> V_39 ;
struct V_24 * V_33 = NULL ;
F_128 ( & V_2 -> V_213 ) ;
if ( V_39 -> V_218 == V_219 ) {
F_129 ( & V_2 -> V_213 ) ;
return;
}
if ( V_2 -> V_47 )
V_33 = F_130 ( V_2 -> V_47 , 0 ) ;
F_129 ( & V_2 -> V_213 ) ;
if ( ! V_33 ) {
F_131 ( V_39 ) ;
return;
}
F_128 ( & V_33 -> V_220 ) ;
if ( V_33 -> V_221 ) {
F_132 ( V_39 , - V_21 ,
L_52 ) ;
F_114 ( V_39 , V_219 ) ;
} else {
F_76 ( V_2 ) ;
F_131 ( V_39 ) ;
}
F_129 ( & V_33 -> V_220 ) ;
F_133 ( V_33 ) ;
}
static void F_134 ( struct V_1 * V_2 )
{
int V_152 ;
char * type ;
unsigned int V_112 ;
unsigned int V_113 ;
type = F_117 ( V_208 , V_2 -> V_39 -> V_222 , L_53 , NULL ) ;
if ( F_118 ( type ) )
return;
if ( strncmp ( type , L_54 , 3 ) == 0 ) {
V_152 = F_135 ( V_208 , V_2 -> V_39 -> V_222 ,
L_55 , L_35 , & V_112 ,
L_56 , L_35 , & V_113 ,
NULL ) ;
if ( ! V_152 ) {
V_2 -> V_109 = 1 ;
V_2 -> V_112 = V_112 ;
V_2 -> V_113 = V_113 ;
}
} else if ( strncmp ( type , L_57 , 4 ) == 0 )
V_2 -> V_109 = 1 ;
F_9 ( type ) ;
}
static void F_136 ( struct V_1 * V_2 )
{
unsigned long long V_32 ;
unsigned long V_106 ;
unsigned int V_223 ;
int V_152 ;
int V_224 , V_225 , V_82 ;
switch ( V_2 -> V_61 ) {
case V_62 :
V_152 = F_116 ( V_208 , V_2 -> V_39 -> V_222 ,
L_58 , L_59 , & V_32 ) ;
if ( F_137 ( V_152 ) )
return;
F_64 ( V_118 L_60 ,
V_32 ) ;
F_73 ( V_2 -> V_47 , V_32 ) ;
F_138 ( V_2 -> V_47 ) ;
case V_169 :
return;
default:
break;
}
F_20 ( & V_2 -> V_39 -> V_40 , L_61 ,
V_226 , V_2 -> V_39 -> V_222 ) ;
V_152 = F_135 ( V_208 , V_2 -> V_39 -> V_222 ,
L_58 , L_62 , & V_32 ,
L_63 , L_35 , & V_223 ,
L_64 , L_65 , & V_106 ,
NULL ) ;
if ( V_152 ) {
F_101 ( V_2 -> V_39 , V_152 ,
L_66 ,
V_2 -> V_39 -> V_222 ) ;
return;
}
V_2 -> V_117 = 0 ;
V_2 -> V_78 = 0 ;
V_152 = F_135 ( V_208 , V_2 -> V_39 -> V_222 ,
L_67 , L_68 , & V_224 ,
NULL ) ;
if ( ! V_152 && V_224 ) {
V_2 -> V_117 = V_76 | V_77 ;
V_2 -> V_78 = V_120 ;
}
V_152 = F_135 ( V_208 , V_2 -> V_39 -> V_222 ,
L_69 , L_68 , & V_225 ,
NULL ) ;
if ( ! V_152 && V_225 ) {
V_2 -> V_117 = V_76 ;
V_2 -> V_78 = V_121 ;
}
V_152 = F_135 ( V_208 , V_2 -> V_39 -> V_222 ,
L_70 , L_68 , & V_82 ,
NULL ) ;
if ( ! V_152 && V_82 )
F_134 ( V_2 ) ;
V_152 = F_68 ( V_32 , V_2 , V_223 , V_106 ) ;
if ( V_152 ) {
F_101 ( V_2 -> V_39 , V_152 , L_71 ,
V_2 -> V_39 -> V_222 ) ;
return;
}
F_114 ( V_2 -> V_39 , V_217 ) ;
F_87 ( & V_107 ) ;
V_2 -> V_61 = V_62 ;
F_83 ( V_2 ) ;
F_88 ( & V_107 ) ;
F_139 ( V_2 -> V_47 ) ;
V_2 -> V_227 = 1 ;
}
static void F_140 ( struct V_192 * V_40 ,
enum V_228 V_229 )
{
struct V_1 * V_2 = F_126 ( & V_40 -> V_40 ) ;
F_20 ( & V_40 -> V_40 , L_72 , V_229 ) ;
switch ( V_229 ) {
case V_230 :
case V_231 :
case V_206 :
case V_232 :
case V_233 :
case V_234 :
case V_235 :
break;
case V_217 :
F_136 ( V_2 ) ;
break;
case V_219 :
F_127 ( V_2 ) ;
break;
}
}
static int F_141 ( struct V_192 * V_39 )
{
struct V_1 * V_2 = F_126 ( & V_39 -> V_40 ) ;
struct V_24 * V_33 = NULL ;
struct V_46 * V_236 ;
F_20 ( & V_39 -> V_40 , L_73 , V_39 -> V_202 ) ;
F_89 ( V_2 , 0 ) ;
F_128 ( & V_2 -> V_213 ) ;
V_236 = V_2 -> V_47 ;
if ( V_236 )
V_33 = F_130 ( V_236 , 0 ) ;
V_2 -> V_39 = NULL ;
F_129 ( & V_2 -> V_213 ) ;
if ( ! V_33 ) {
F_9 ( V_2 ) ;
return 0 ;
}
F_128 ( & V_33 -> V_220 ) ;
V_2 = V_236 -> V_37 ;
F_142 ( F_143 ( V_236 ) ,
L_74 ,
V_39 -> V_202 , V_33 -> V_221 ) ;
if ( V_2 && ! V_33 -> V_221 ) {
F_76 ( V_2 ) ;
V_236 -> V_37 = NULL ;
F_9 ( V_2 ) ;
}
F_129 ( & V_33 -> V_220 ) ;
F_133 ( V_33 ) ;
return 0 ;
}
static int F_144 ( struct V_192 * V_40 )
{
struct V_1 * V_2 = F_126 ( & V_40 -> V_40 ) ;
return V_2 -> V_227 && V_2 -> V_39 ;
}
static int F_145 ( struct V_24 * V_33 , T_2 V_34 )
{
struct V_46 * V_236 = V_33 -> V_29 ;
struct V_1 * V_2 ;
int V_152 = 0 ;
F_128 ( & V_237 ) ;
V_2 = V_236 -> V_37 ;
if ( ! V_2 ) {
V_152 = - V_238 ;
goto V_156;
}
F_128 ( & V_2 -> V_213 ) ;
if ( ! V_2 -> V_47 )
V_152 = - V_238 ;
F_129 ( & V_2 -> V_213 ) ;
V_156:
F_129 ( & V_237 ) ;
return V_152 ;
}
static int F_146 ( struct V_46 * V_236 , T_2 V_34 )
{
struct V_1 * V_2 = V_236 -> V_37 ;
struct V_24 * V_33 ;
struct V_192 * V_39 ;
F_128 ( & V_237 ) ;
V_33 = F_130 ( V_236 , 0 ) ;
F_133 ( V_33 ) ;
if ( V_33 -> V_221 )
goto V_156;
F_128 ( & V_2 -> V_213 ) ;
V_39 = V_2 -> V_39 ;
if ( V_39 && V_39 -> V_218 == V_219 ) {
F_147 ( F_143 ( V_33 -> V_29 ) , L_75 ) ;
F_76 ( V_2 ) ;
F_131 ( V_2 -> V_39 ) ;
}
F_129 ( & V_2 -> V_213 ) ;
if ( ! V_39 ) {
F_147 ( F_143 ( V_33 -> V_29 ) , L_75 ) ;
F_76 ( V_2 ) ;
V_236 -> V_37 = NULL ;
F_9 ( V_2 ) ;
}
V_156:
F_129 ( & V_237 ) ;
return 0 ;
}
static int T_7 F_148 ( void )
{
int V_239 ;
if ( ! F_149 () )
return - V_149 ;
if ( F_150 ( V_147 , V_158 ) ) {
F_64 ( V_148 L_76 ,
V_147 , V_158 ) ;
return - V_149 ;
}
V_239 = F_151 ( & V_240 ) ;
if ( V_239 ) {
F_152 ( V_147 , V_158 ) ;
return V_239 ;
}
return 0 ;
}
static void T_8 F_153 ( void )
{
return F_154 ( & V_240 ) ;
}
