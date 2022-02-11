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
V_54 -> V_79 = F_29 ( V_6 -> V_80 , V_6 , V_2 -> V_60 ) ;
F_2 ( V_54 -> V_79 > V_63 ) ;
F_30 (info->sg, sg, ring_req->nr_segments, i) {
V_52 = F_31 ( F_32 ( F_33 ( V_60 ) ) ) ;
V_55 = V_60 -> V_81 >> 9 ;
V_56 = V_55 + ( V_60 -> V_82 >> 9 ) - 1 ;
V_57 = F_34 ( & V_58 ) ;
F_2 ( V_57 == - V_83 ) ;
F_35 (
V_57 ,
V_2 -> V_39 -> V_84 ,
V_52 ,
F_28 ( V_6 ) ) ;
V_2 -> V_5 [ V_7 ] . V_85 [ V_38 ] = F_36 ( V_52 ) ;
V_54 -> V_67 . V_68 . V_86 [ V_38 ] =
(struct V_87 ) {
. V_88 = V_57 ,
. V_89 = V_55 ,
. V_90 = V_56 } ;
}
V_2 -> V_65 . V_66 ++ ;
V_2 -> V_5 [ V_7 ] . V_6 = * V_54 ;
F_37 ( V_58 ) ;
return 0 ;
}
static inline void F_38 ( struct V_1 * V_2 )
{
int V_91 ;
F_39 ( & V_2 -> V_65 , V_91 ) ;
if ( V_91 )
F_40 ( V_2 -> V_92 ) ;
}
static void F_41 ( struct V_93 * V_94 )
{
struct V_1 * V_2 = NULL ;
struct V_8 * V_6 ;
int V_95 ;
F_42 ( L_3 ) ;
V_95 = 0 ;
while ( ( V_6 = F_43 ( V_94 ) ) != NULL ) {
V_2 = V_6 -> V_51 -> V_37 ;
if ( F_44 ( & V_2 -> V_65 ) )
goto V_96;
F_45 ( V_6 ) ;
if ( V_6 -> V_97 != V_98 ) {
F_46 ( V_6 , - V_99 ) ;
continue;
}
F_42 ( L_4
L_5 ,
V_6 , V_6 -> V_100 , ( unsigned long ) F_27 ( V_6 ) ,
F_47 ( V_6 ) , F_48 ( V_6 ) ,
V_6 -> V_101 , F_28 ( V_6 ) ? L_6 : L_7 ) ;
if ( F_22 ( V_6 ) ) {
F_49 ( V_94 , V_6 ) ;
V_96:
F_50 ( V_94 ) ;
break;
}
V_95 ++ ;
}
if ( V_95 != 0 )
F_38 ( V_2 ) ;
}
static int F_51 ( struct V_46 * V_47 , T_4 V_102 )
{
struct V_93 * V_94 ;
V_94 = F_52 ( F_41 , & V_103 ) ;
if ( V_94 == NULL )
return - 1 ;
F_53 ( V_104 , V_94 ) ;
F_54 ( V_94 , V_102 ) ;
F_55 ( V_94 , 512 ) ;
F_56 ( V_94 , V_105 - 1 ) ;
F_57 ( V_94 , V_105 ) ;
F_58 ( V_94 , V_63 ) ;
F_59 ( V_94 , 511 ) ;
F_60 ( V_94 , V_106 ) ;
V_47 -> V_107 = V_94 ;
return 0 ;
}
static void F_61 ( struct V_1 * V_2 )
{
F_62 ( V_2 -> V_94 , V_2 -> V_108 ) ;
F_63 ( V_109 L_8 ,
V_2 -> V_47 -> V_110 ,
V_2 -> V_78 == V_111 ?
L_9 : ( V_2 -> V_78 == V_112 ?
L_10 : L_11 ) ,
V_2 -> V_108 ? L_12 : L_13 ) ;
}
static int F_64 ( int V_113 , int * V_9 , unsigned int * V_81 )
{
int V_114 ;
V_114 = F_65 ( V_113 ) ;
* V_9 = F_66 ( V_113 ) ;
switch ( V_114 ) {
case V_115 :
* V_81 = ( * V_9 / 64 ) + V_116 ;
* V_9 = ( ( * V_9 / 64 ) * V_117 ) +
V_118 ;
break;
case V_119 :
* V_81 = ( * V_9 / 64 ) + 2 + V_116 ;
* V_9 = ( ( ( * V_9 / 64 ) + 2 ) * V_117 ) +
V_118 ;
break;
case V_120 :
* V_81 = ( * V_9 / V_117 ) + V_121 ;
* V_9 = * V_9 + V_122 ;
break;
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_127 :
case V_128 :
case V_129 :
* V_81 = ( * V_9 / V_117 ) +
( ( V_114 - V_123 + 1 ) * 16 ) +
V_121 ;
* V_9 = * V_9 +
( ( V_114 - V_123 + 1 ) * 16 * V_117 ) +
V_122 ;
break;
case V_130 :
case V_131 :
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
* V_81 = ( * V_9 / V_117 ) +
( ( V_114 - V_130 + 8 ) * 16 ) +
V_121 ;
* V_9 = * V_9 +
( ( V_114 - V_130 + 8 ) * 16 * V_117 ) +
V_122 ;
break;
case V_138 :
* V_81 = * V_9 / V_117 ;
break;
default:
F_63 ( V_139 L_14
L_15 ) ;
return - V_140 ;
}
return 0 ;
}
static int F_67 ( V_70 V_141 ,
struct V_1 * V_2 ,
T_4 V_142 , T_4 V_102 )
{
struct V_46 * V_47 ;
int V_13 = 1 ;
int V_143 ;
unsigned int V_81 ;
int V_9 ;
int V_144 ;
F_2 ( V_2 -> V_47 != NULL ) ;
F_2 ( V_2 -> V_94 != NULL ) ;
if ( ( V_2 -> V_113 >> V_145 ) > 1 ) {
F_63 ( V_139 L_16 , V_2 -> V_113 ) ;
return - V_140 ;
}
if ( ! F_68 ( V_2 -> V_113 ) ) {
V_143 = F_64 ( V_2 -> V_113 , & V_9 , & V_81 ) ;
if ( V_143 )
return V_143 ;
V_144 = V_117 ;
} else {
V_9 = F_69 ( V_2 -> V_113 ) ;
V_144 = V_146 ;
V_81 = V_9 / V_144 ;
if ( F_70 () && V_81 <= V_116 + 4 )
F_63 ( V_139 L_17
L_18
L_19 , V_2 -> V_113 ) ;
}
V_143 = - V_140 ;
if ( ( V_9 % V_144 ) == 0 )
V_13 = V_144 ;
V_143 = F_4 ( V_9 , V_13 ) ;
if ( V_143 )
goto V_147;
V_143 = - V_140 ;
V_47 = F_71 ( V_13 ) ;
if ( V_47 == NULL )
goto V_148;
if ( V_13 > 1 ) {
if ( V_81 < 26 )
sprintf ( V_47 -> V_110 , L_20 , V_149 , 'a' + V_81 ) ;
else
sprintf ( V_47 -> V_110 , L_21 , V_149 ,
'a' + ( ( V_81 / 26 ) - 1 ) , 'a' + ( V_81 % 26 ) ) ;
} else {
if ( V_81 < 26 )
sprintf ( V_47 -> V_110 , L_22 , V_149 ,
'a' + V_81 ,
V_9 & ( V_144 - 1 ) ) ;
else
sprintf ( V_47 -> V_110 , L_23 , V_149 ,
'a' + ( ( V_81 / 26 ) - 1 ) ,
'a' + ( V_81 % 26 ) ,
V_9 & ( V_144 - 1 ) ) ;
}
V_47 -> V_114 = V_138 ;
V_47 -> V_150 = V_9 ;
V_47 -> V_151 = & V_152 ;
V_47 -> V_37 = V_2 ;
V_47 -> V_153 = & ( V_2 -> V_39 -> V_40 ) ;
F_72 ( V_47 , V_141 ) ;
if ( F_51 ( V_47 , V_102 ) ) {
F_73 ( V_47 ) ;
goto V_148;
}
V_2 -> V_94 = V_47 -> V_107 ;
V_2 -> V_47 = V_47 ;
F_61 ( V_2 ) ;
if ( V_142 & V_154 )
F_74 ( V_47 , 1 ) ;
if ( V_142 & V_155 )
V_47 -> V_48 |= V_156 ;
if ( V_142 & V_157 )
V_47 -> V_48 |= V_49 ;
return 0 ;
V_148:
F_12 ( V_9 , V_13 ) ;
V_147:
return V_143 ;
}
static void F_75 ( struct V_1 * V_2 )
{
unsigned int V_9 , V_13 ;
unsigned long V_48 ;
if ( V_2 -> V_94 == NULL )
return;
F_76 ( & V_103 , V_48 ) ;
F_50 ( V_2 -> V_94 ) ;
F_77 ( & V_2 -> V_64 ) ;
F_78 ( & V_103 , V_48 ) ;
F_79 ( & V_2 -> V_23 ) ;
F_73 ( V_2 -> V_47 ) ;
V_9 = V_2 -> V_47 -> V_150 ;
V_13 = V_2 -> V_47 -> V_19 ;
F_12 ( V_9 , V_13 ) ;
F_80 ( V_2 -> V_94 ) ;
V_2 -> V_94 = NULL ;
F_81 ( V_2 -> V_47 ) ;
V_2 -> V_47 = NULL ;
}
static void F_82 ( struct V_1 * V_2 )
{
if ( ! F_44 ( & V_2 -> V_65 ) ) {
F_83 ( V_2 -> V_94 ) ;
F_41 ( V_2 -> V_94 ) ;
}
}
static void F_84 ( struct V_158 * V_23 )
{
struct V_1 * V_2 = F_85 ( V_23 , struct V_1 , V_23 ) ;
F_86 ( & V_103 ) ;
if ( V_2 -> V_61 == V_62 )
F_82 ( V_2 ) ;
F_87 ( & V_103 ) ;
}
static void F_88 ( struct V_1 * V_2 , int V_159 )
{
F_86 ( & V_103 ) ;
V_2 -> V_61 = V_159 ?
V_160 : V_161 ;
if ( V_2 -> V_94 )
F_50 ( V_2 -> V_94 ) ;
F_77 ( & V_2 -> V_64 ) ;
F_87 ( & V_103 ) ;
F_79 ( & V_2 -> V_23 ) ;
if ( V_2 -> V_162 != V_163 ) {
F_89 ( V_2 -> V_162 , 0 ,
( unsigned long ) V_2 -> V_65 . V_164 ) ;
V_2 -> V_162 = V_163 ;
V_2 -> V_65 . V_164 = NULL ;
}
if ( V_2 -> V_92 )
F_90 ( V_2 -> V_92 , V_2 ) ;
V_2 -> V_165 = V_2 -> V_92 = 0 ;
}
static void F_91 ( struct V_166 * V_167 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_167 -> V_6 . V_79 ; V_38 ++ )
F_89 ( V_167 -> V_6 . V_67 . V_68 . V_86 [ V_38 ] . V_88 , 0 , 0UL ) ;
}
static T_5 F_92 ( int V_92 , void * V_168 )
{
struct V_8 * V_6 ;
struct V_169 * V_170 ;
T_6 V_38 , V_171 ;
unsigned long V_48 ;
struct V_1 * V_2 = (struct V_1 * ) V_168 ;
int error ;
F_76 ( & V_103 , V_48 ) ;
if ( F_23 ( V_2 -> V_61 != V_62 ) ) {
F_78 ( & V_103 , V_48 ) ;
return V_172 ;
}
V_173:
V_171 = V_2 -> V_65 . V_164 -> V_174 ;
F_93 () ;
for ( V_38 = V_2 -> V_65 . V_175 ; V_38 != V_171 ; V_38 ++ ) {
unsigned long V_7 ;
V_170 = F_94 ( & V_2 -> V_65 , V_38 ) ;
V_7 = V_170 -> V_7 ;
V_6 = V_2 -> V_5 [ V_7 ] . V_8 ;
F_91 ( & V_2 -> V_5 [ V_7 ] ) ;
F_3 ( V_2 , V_7 ) ;
error = ( V_170 -> V_176 == V_177 ) ? 0 : - V_99 ;
switch ( V_170 -> V_72 ) {
case V_112 :
case V_111 :
if ( F_23 ( V_170 -> V_176 == V_178 ) ) {
F_63 ( V_139 L_24 ,
V_2 -> V_78 == V_111 ?
L_9 : L_25 ,
V_2 -> V_47 -> V_110 ) ;
error = - V_179 ;
}
if ( F_23 ( V_170 -> V_176 == V_180 &&
V_2 -> V_5 [ V_7 ] . V_6 . V_79 == 0 ) ) {
F_63 ( V_139 L_26 ,
V_2 -> V_78 == V_111 ?
L_9 : L_25 ,
V_2 -> V_47 -> V_110 ) ;
error = - V_179 ;
}
if ( F_23 ( error ) ) {
if ( error == - V_179 )
error = 0 ;
V_2 -> V_108 = 0 ;
V_2 -> V_78 = 0 ;
F_61 ( V_2 ) ;
}
case V_74 :
case V_73 :
if ( F_23 ( V_170 -> V_176 != V_177 ) )
F_20 ( & V_2 -> V_39 -> V_40 , L_27
L_28 , V_170 -> V_176 ) ;
F_46 ( V_6 , error ) ;
break;
default:
F_95 () ;
}
}
V_2 -> V_65 . V_175 = V_38 ;
if ( V_38 != V_2 -> V_65 . V_66 ) {
int V_181 ;
F_96 ( & V_2 -> V_65 , V_181 ) ;
if ( V_181 )
goto V_173;
} else
V_2 -> V_65 . V_164 -> V_182 = V_38 + 1 ;
F_82 ( V_2 ) ;
F_78 ( & V_103 , V_48 ) ;
return V_172 ;
}
static int F_97 ( struct V_183 * V_40 ,
struct V_1 * V_2 )
{
struct V_184 * V_164 ;
int V_143 ;
V_2 -> V_162 = V_163 ;
V_164 = (struct V_184 * ) F_98 ( V_185 | V_186 ) ;
if ( ! V_164 ) {
F_99 ( V_40 , - V_17 , L_29 ) ;
return - V_17 ;
}
F_100 ( V_164 ) ;
F_101 ( & V_2 -> V_65 , V_164 , V_105 ) ;
F_102 ( V_2 -> V_60 , V_63 ) ;
V_143 = F_103 ( V_40 , F_104 ( V_2 -> V_65 . V_164 ) ) ;
if ( V_143 < 0 ) {
F_105 ( ( unsigned long ) V_164 ) ;
V_2 -> V_65 . V_164 = NULL ;
goto V_187;
}
V_2 -> V_162 = V_143 ;
V_143 = F_106 ( V_40 , & V_2 -> V_165 ) ;
if ( V_143 )
goto V_187;
V_143 = F_107 ( V_2 -> V_165 ,
F_92 ,
V_188 , L_30 , V_2 ) ;
if ( V_143 <= 0 ) {
F_99 ( V_40 , V_143 ,
L_31 ) ;
goto V_187;
}
V_2 -> V_92 = V_143 ;
return 0 ;
V_187:
F_88 ( V_2 , 0 ) ;
return V_143 ;
}
static int F_108 ( struct V_183 * V_40 ,
struct V_1 * V_2 )
{
const char * V_189 = NULL ;
struct V_190 V_191 ;
int V_143 ;
V_143 = F_97 ( V_40 , V_2 ) ;
if ( V_143 )
goto V_147;
V_173:
V_143 = F_109 ( & V_191 ) ;
if ( V_143 ) {
F_99 ( V_40 , V_143 , L_32 ) ;
goto V_192;
}
V_143 = F_110 ( V_191 , V_40 -> V_193 ,
L_33 , L_34 , V_2 -> V_162 ) ;
if ( V_143 ) {
V_189 = L_35 ;
goto V_194;
}
V_143 = F_110 ( V_191 , V_40 -> V_193 ,
L_36 , L_34 , V_2 -> V_165 ) ;
if ( V_143 ) {
V_189 = L_37 ;
goto V_194;
}
V_143 = F_110 ( V_191 , V_40 -> V_193 , L_38 , L_39 ,
V_195 ) ;
if ( V_143 ) {
V_189 = L_40 ;
goto V_194;
}
V_143 = F_111 ( V_191 , 0 ) ;
if ( V_143 ) {
if ( V_143 == - V_196 )
goto V_173;
F_99 ( V_40 , V_143 , L_41 ) ;
goto V_192;
}
F_112 ( V_40 , V_197 ) ;
return 0 ;
V_194:
F_111 ( V_191 , 1 ) ;
if ( V_189 )
F_99 ( V_40 , V_143 , L_39 , V_189 ) ;
V_192:
F_88 ( V_2 , 0 ) ;
V_147:
return V_143 ;
}
static int F_113 ( struct V_183 * V_40 ,
const struct V_198 * V_7 )
{
int V_143 , V_113 , V_38 ;
struct V_1 * V_2 ;
V_143 = F_114 ( V_199 , V_40 -> V_193 ,
L_42 , L_43 , & V_113 ) ;
if ( V_143 != 1 ) {
V_143 = F_114 ( V_199 , V_40 -> V_193 , L_44 ,
L_43 , & V_113 ) ;
if ( V_143 != 1 ) {
F_99 ( V_40 , V_143 , L_45 ) ;
return V_143 ;
}
}
if ( F_70 () ) {
char * type ;
int V_200 ;
if ( V_201 & V_202 ) {
int V_114 ;
if ( ! F_68 ( V_113 ) )
V_114 = F_65 ( V_113 ) ;
else
V_114 = V_138 ;
if ( V_114 != V_138 ) {
F_63 ( V_109
L_46 ,
V_203 , V_113 ) ;
return - V_140 ;
}
}
type = F_115 ( V_199 , V_40 -> V_193 , L_47 , & V_200 ) ;
if ( F_116 ( type ) )
return - V_140 ;
if ( strncmp ( type , L_48 , 5 ) == 0 ) {
F_9 ( type ) ;
return - V_140 ;
}
F_9 ( type ) ;
}
V_2 = F_5 ( sizeof( * V_2 ) , V_16 ) ;
if ( ! V_2 ) {
F_99 ( V_40 , - V_17 , L_49 ) ;
return - V_17 ;
}
F_117 ( & V_2 -> V_204 ) ;
V_2 -> V_39 = V_40 ;
V_2 -> V_113 = V_113 ;
V_2 -> V_61 = V_161 ;
F_118 ( & V_2 -> V_23 , F_84 ) ;
for ( V_38 = 0 ; V_38 < V_4 ; V_38 ++ )
V_2 -> V_5 [ V_38 ] . V_6 . V_7 = V_38 + 1 ;
V_2 -> V_5 [ V_4 - 1 ] . V_6 . V_7 = 0x0fffffff ;
V_2 -> V_71 = F_119 ( strrchr ( V_40 -> V_193 , '/' ) + 1 , NULL , 0 ) ;
F_120 ( & V_40 -> V_40 , V_2 ) ;
V_143 = F_108 ( V_40 , V_2 ) ;
if ( V_143 ) {
F_9 ( V_2 ) ;
F_120 ( & V_40 -> V_40 , NULL ) ;
return V_143 ;
}
return 0 ;
}
static int F_121 ( struct V_1 * V_2 )
{
int V_38 ;
struct V_53 * V_6 ;
struct V_166 * V_205 ;
int V_206 ;
V_205 = F_122 ( sizeof( V_2 -> V_5 ) ,
V_185 | V_207 | V_186 ) ;
if ( ! V_205 )
return - V_17 ;
memcpy ( V_205 , V_2 -> V_5 , sizeof( V_2 -> V_5 ) ) ;
memset ( & V_2 -> V_5 , 0 , sizeof( V_2 -> V_5 ) ) ;
for ( V_38 = 0 ; V_38 < V_4 ; V_38 ++ )
V_2 -> V_5 [ V_38 ] . V_6 . V_7 = V_38 + 1 ;
V_2 -> V_3 = V_2 -> V_65 . V_66 ;
V_2 -> V_5 [ V_4 - 1 ] . V_6 . V_7 = 0x0fffffff ;
for ( V_38 = 0 ; V_38 < V_4 ; V_38 ++ ) {
if ( ! V_205 [ V_38 ] . V_8 )
continue;
V_6 = F_26 ( & V_2 -> V_65 , V_2 -> V_65 . V_66 ) ;
* V_6 = V_205 [ V_38 ] . V_6 ;
V_6 -> V_7 = F_1 ( V_2 ) ;
memcpy ( & V_2 -> V_5 [ V_6 -> V_7 ] , & V_205 [ V_38 ] , sizeof( V_205 [ V_38 ] ) ) ;
for ( V_206 = 0 ; V_206 < V_6 -> V_79 ; V_206 ++ )
F_35 (
V_6 -> V_67 . V_68 . V_86 [ V_206 ] . V_88 ,
V_2 -> V_39 -> V_84 ,
F_31 ( V_2 -> V_5 [ V_6 -> V_7 ] . V_85 [ V_206 ] ) ,
F_28 ( V_2 -> V_5 [ V_6 -> V_7 ] . V_8 ) ) ;
V_2 -> V_5 [ V_6 -> V_7 ] . V_6 = * V_6 ;
V_2 -> V_65 . V_66 ++ ;
}
F_9 ( V_205 ) ;
F_112 ( V_2 -> V_39 , V_208 ) ;
F_86 ( & V_103 ) ;
V_2 -> V_61 = V_62 ;
F_38 ( V_2 ) ;
F_82 ( V_2 ) ;
F_87 ( & V_103 ) ;
return 0 ;
}
static int F_123 ( struct V_183 * V_40 )
{
struct V_1 * V_2 = F_124 ( & V_40 -> V_40 ) ;
int V_143 ;
F_20 ( & V_40 -> V_40 , L_50 , V_40 -> V_193 ) ;
F_88 ( V_2 , V_2 -> V_61 == V_62 ) ;
V_143 = F_108 ( V_40 , V_2 ) ;
if ( V_2 -> V_61 == V_160 && ! V_143 )
V_143 = F_121 ( V_2 ) ;
return V_143 ;
}
static void
F_125 ( struct V_1 * V_2 )
{
struct V_183 * V_39 = V_2 -> V_39 ;
struct V_24 * V_33 = NULL ;
F_126 ( & V_2 -> V_204 ) ;
if ( V_39 -> V_209 == V_210 ) {
F_127 ( & V_2 -> V_204 ) ;
return;
}
if ( V_2 -> V_47 )
V_33 = F_128 ( V_2 -> V_47 , 0 ) ;
F_127 ( & V_2 -> V_204 ) ;
if ( ! V_33 ) {
F_129 ( V_39 ) ;
return;
}
F_126 ( & V_33 -> V_211 ) ;
if ( V_33 -> V_212 ) {
F_130 ( V_39 , - V_21 ,
L_51 ) ;
F_112 ( V_39 , V_210 ) ;
} else {
F_75 ( V_2 ) ;
F_129 ( V_39 ) ;
}
F_127 ( & V_33 -> V_211 ) ;
F_131 ( V_33 ) ;
}
static void F_132 ( struct V_1 * V_2 )
{
unsigned long long V_32 ;
unsigned long V_102 ;
unsigned int V_213 ;
int V_143 ;
int V_214 , V_215 ;
switch ( V_2 -> V_61 ) {
case V_62 :
V_143 = F_114 ( V_199 , V_2 -> V_39 -> V_216 ,
L_52 , L_53 , & V_32 ) ;
if ( F_133 ( V_143 ) )
return;
F_63 ( V_109 L_54 ,
V_32 ) ;
F_72 ( V_2 -> V_47 , V_32 ) ;
F_134 ( V_2 -> V_47 ) ;
case V_160 :
return;
default:
break;
}
F_20 ( & V_2 -> V_39 -> V_40 , L_55 ,
V_217 , V_2 -> V_39 -> V_216 ) ;
V_143 = F_135 ( V_199 , V_2 -> V_39 -> V_216 ,
L_52 , L_56 , & V_32 ,
L_57 , L_34 , & V_213 ,
L_58 , L_59 , & V_102 ,
NULL ) ;
if ( V_143 ) {
F_99 ( V_2 -> V_39 , V_143 ,
L_60 ,
V_2 -> V_39 -> V_216 ) ;
return;
}
V_2 -> V_108 = 0 ;
V_2 -> V_78 = 0 ;
V_143 = F_135 ( V_199 , V_2 -> V_39 -> V_216 ,
L_61 , L_62 , & V_214 ,
NULL ) ;
if ( ! V_143 && V_214 ) {
V_2 -> V_108 = V_76 | V_77 ;
V_2 -> V_78 = V_111 ;
}
V_143 = F_135 ( V_199 , V_2 -> V_39 -> V_216 ,
L_63 , L_62 , & V_215 ,
NULL ) ;
if ( ! V_143 && V_215 ) {
V_2 -> V_108 = V_76 ;
V_2 -> V_78 = V_112 ;
}
V_143 = F_67 ( V_32 , V_2 , V_213 , V_102 ) ;
if ( V_143 ) {
F_99 ( V_2 -> V_39 , V_143 , L_64 ,
V_2 -> V_39 -> V_216 ) ;
return;
}
F_112 ( V_2 -> V_39 , V_208 ) ;
F_86 ( & V_103 ) ;
V_2 -> V_61 = V_62 ;
F_82 ( V_2 ) ;
F_87 ( & V_103 ) ;
F_136 ( V_2 -> V_47 ) ;
V_2 -> V_218 = 1 ;
}
static void F_137 ( struct V_183 * V_40 ,
enum V_219 V_220 )
{
struct V_1 * V_2 = F_124 ( & V_40 -> V_40 ) ;
F_20 ( & V_40 -> V_40 , L_65 , V_220 ) ;
switch ( V_220 ) {
case V_221 :
case V_222 :
case V_197 :
case V_223 :
case V_224 :
case V_225 :
case V_226 :
break;
case V_208 :
F_132 ( V_2 ) ;
break;
case V_210 :
F_125 ( V_2 ) ;
break;
}
}
static int F_138 ( struct V_183 * V_39 )
{
struct V_1 * V_2 = F_124 ( & V_39 -> V_40 ) ;
struct V_24 * V_33 = NULL ;
struct V_46 * V_227 ;
F_20 ( & V_39 -> V_40 , L_66 , V_39 -> V_193 ) ;
F_88 ( V_2 , 0 ) ;
F_126 ( & V_2 -> V_204 ) ;
V_227 = V_2 -> V_47 ;
if ( V_227 )
V_33 = F_128 ( V_227 , 0 ) ;
V_2 -> V_39 = NULL ;
F_127 ( & V_2 -> V_204 ) ;
if ( ! V_33 ) {
F_9 ( V_2 ) ;
return 0 ;
}
F_126 ( & V_33 -> V_211 ) ;
V_2 = V_227 -> V_37 ;
F_139 ( F_140 ( V_227 ) ,
L_67 ,
V_39 -> V_193 , V_33 -> V_212 ) ;
if ( V_2 && ! V_33 -> V_212 ) {
F_75 ( V_2 ) ;
V_227 -> V_37 = NULL ;
F_9 ( V_2 ) ;
}
F_127 ( & V_33 -> V_211 ) ;
F_131 ( V_33 ) ;
return 0 ;
}
static int F_141 ( struct V_183 * V_40 )
{
struct V_1 * V_2 = F_124 ( & V_40 -> V_40 ) ;
return V_2 -> V_218 && V_2 -> V_39 ;
}
static int F_142 ( struct V_24 * V_33 , T_2 V_34 )
{
struct V_46 * V_227 = V_33 -> V_29 ;
struct V_1 * V_2 ;
int V_143 = 0 ;
F_126 ( & V_228 ) ;
V_2 = V_227 -> V_37 ;
if ( ! V_2 ) {
V_143 = - V_229 ;
goto V_147;
}
F_126 ( & V_2 -> V_204 ) ;
if ( ! V_2 -> V_47 )
V_143 = - V_229 ;
F_127 ( & V_2 -> V_204 ) ;
V_147:
F_127 ( & V_228 ) ;
return V_143 ;
}
static int F_143 ( struct V_46 * V_227 , T_2 V_34 )
{
struct V_1 * V_2 = V_227 -> V_37 ;
struct V_24 * V_33 ;
struct V_183 * V_39 ;
F_126 ( & V_228 ) ;
V_33 = F_128 ( V_227 , 0 ) ;
F_131 ( V_33 ) ;
if ( V_33 -> V_212 )
goto V_147;
F_126 ( & V_2 -> V_204 ) ;
V_39 = V_2 -> V_39 ;
if ( V_39 && V_39 -> V_209 == V_210 ) {
F_144 ( F_140 ( V_33 -> V_29 ) , L_68 ) ;
F_75 ( V_2 ) ;
F_129 ( V_2 -> V_39 ) ;
}
F_127 ( & V_2 -> V_204 ) ;
if ( ! V_39 ) {
F_144 ( F_140 ( V_33 -> V_29 ) , L_68 ) ;
F_75 ( V_2 ) ;
V_227 -> V_37 = NULL ;
F_9 ( V_2 ) ;
}
V_147:
F_127 ( & V_228 ) ;
return 0 ;
}
static int T_7 F_145 ( void )
{
if ( ! F_146 () )
return - V_140 ;
if ( F_147 ( V_138 , V_149 ) ) {
F_63 ( V_139 L_69 ,
V_138 , V_149 ) ;
return - V_140 ;
}
return F_148 ( & V_230 ) ;
}
static void T_8 F_149 ( void )
{
return F_150 ( & V_230 ) ;
}
