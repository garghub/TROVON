static inline void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( & V_4 -> V_5 , & V_2 -> V_6 ) ;
V_2 -> V_7 += V_4 -> V_8 -> V_9 ;
}
static inline struct V_3 * F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = NULL ;
if ( ! F_4 ( & V_2 -> V_6 ) ) {
struct V_10 * V_11 = V_2 -> V_6 . V_12 ;
V_4 = F_5 ( V_11 , struct V_3 , V_5 ) ;
F_6 ( V_11 ) ;
V_2 -> V_7 -= V_4 -> V_8 -> V_9 ;
}
return V_4 ;
}
static inline void F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_8 ( & V_4 -> V_5 , & V_2 -> V_6 ) ;
V_2 -> V_7 += V_4 -> V_8 -> V_9 ;
}
static inline int F_9 ( struct V_13 * V_14 ,
struct V_13 * V_15 ,
int V_16 )
{
if ( V_16 >= 2 && V_15 != V_14 )
return 1 ;
return 0 ;
}
static inline int F_10 ( struct V_13 * V_15 ,
int V_16 )
{
if ( V_16 < 2 &&
( V_15 && ! V_15 -> V_17 . V_18 ) )
return 1 ;
return 0 ;
}
static inline int F_11 ( struct V_13 * V_14 ,
struct V_13 * V_15 ,
int V_16 )
{
if ( ! V_14 -> V_17 . V_19 ) {
if ( F_9 ( V_14 , V_15 , V_16 ) )
return 1 ;
if ( F_10 ( V_15 , V_16 ) )
return 1 ;
return 0 ;
}
return 0 ;
}
static inline int F_12 ( struct V_13 * V_14 , T_1 V_20 )
{
if ( V_14 -> V_17 . V_19 &&
F_13 ( V_20 , V_14 -> V_17 . V_21 ) )
return 1 ;
return 0 ;
}
static inline int F_14 ( struct V_13 * V_14 ,
struct V_13 * V_15 ,
int V_16 ,
T_1 V_20 )
{
if ( V_14 -> V_17 . V_22 &&
( F_11 ( V_14 , V_15 , V_16 ) ||
F_12 ( V_14 , V_20 ) ) )
return 1 ;
return 0 ;
}
void F_15 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_24 = V_24 ;
F_16 ( & V_2 -> V_6 ) ;
F_16 ( & V_2 -> V_25 ) ;
F_16 ( & V_2 -> V_26 ) ;
F_16 ( & V_2 -> V_27 ) ;
F_16 ( & V_2 -> V_28 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_13 * V_15 ;
struct V_10 * V_29 , * V_30 ;
struct V_3 * V_31 , * V_32 ;
F_18 (transport, &q->asoc->peer.transport_addr_list,
transports) {
while ( ( V_29 = F_19 ( & V_15 -> V_33 ) ) != NULL ) {
V_31 = F_5 ( V_29 , struct V_3 ,
V_34 ) ;
F_20 ( V_31 , V_2 -> error ) ;
F_21 ( V_31 ) ;
}
}
F_22 (lchunk, temp, &q->sacked) {
F_6 ( V_29 ) ;
V_31 = F_5 ( V_29 , struct V_3 ,
V_34 ) ;
F_20 ( V_31 , V_2 -> error ) ;
F_21 ( V_31 ) ;
}
F_22 (lchunk, temp, &q->retransmit) {
F_6 ( V_29 ) ;
V_31 = F_5 ( V_29 , struct V_3 ,
V_34 ) ;
F_20 ( V_31 , V_2 -> error ) ;
F_21 ( V_31 ) ;
}
F_22 (lchunk, temp, &q->abandoned) {
F_6 ( V_29 ) ;
V_31 = F_5 ( V_29 , struct V_3 ,
V_34 ) ;
F_20 ( V_31 , V_2 -> error ) ;
F_21 ( V_31 ) ;
}
while ( ( V_31 = F_3 ( V_2 ) ) != NULL ) {
F_20 ( V_31 , V_2 -> error ) ;
F_21 ( V_31 ) ;
}
F_23 (chunk, tmp, &q->control_chunk_list, list) {
F_6 ( & V_31 -> V_5 ) ;
F_21 ( V_31 ) ;
}
}
void F_24 ( struct V_1 * V_2 )
{
F_17 ( V_2 ) ;
F_15 ( V_2 -> V_24 , V_2 ) ;
}
void F_25 ( struct V_1 * V_2 )
{
F_17 ( V_2 ) ;
}
int F_26 ( struct V_1 * V_2 , struct V_3 * V_31 , T_2 V_35 )
{
struct V_36 * V_36 = F_27 ( V_2 -> V_24 -> V_37 . V_38 ) ;
int error = 0 ;
F_28 ( L_1 , V_39 , V_2 , V_31 ,
V_31 && V_31 -> V_40 ?
F_29 ( F_30 ( V_31 -> V_40 -> type ) ) :
L_2 ) ;
if ( F_31 ( V_31 ) ) {
switch ( V_2 -> V_24 -> V_41 ) {
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
error = - V_47 ;
break;
default:
F_28 ( L_3 ,
V_39 , V_2 , V_31 , V_31 && V_31 -> V_40 ?
F_29 ( F_30 ( V_31 -> V_40 -> type ) ) :
L_2 ) ;
F_32 ( V_31 ) ;
F_7 ( V_2 , V_31 ) ;
if ( V_31 -> V_40 -> V_48 & V_49 )
F_33 ( V_36 , V_50 ) ;
else
F_33 ( V_36 , V_51 ) ;
break;
}
} else {
F_8 ( & V_31 -> V_5 , & V_2 -> V_25 ) ;
F_33 ( V_36 , V_52 ) ;
}
if ( error < 0 )
return error ;
if ( ! V_2 -> V_53 )
error = F_34 ( V_2 , 0 , V_35 ) ;
return error ;
}
static void F_35 ( struct V_10 * V_54 , struct V_10 * V_55 )
{
struct V_10 * V_56 ;
struct V_3 * V_57 , * V_29 ;
T_1 V_58 , V_59 ;
int V_60 = 0 ;
V_57 = F_5 ( V_55 , struct V_3 , V_34 ) ;
V_58 = F_36 ( V_57 -> V_61 . V_62 -> V_20 ) ;
F_37 (pos, head) {
V_29 = F_5 ( V_56 , struct V_3 , V_34 ) ;
V_59 = F_36 ( V_29 -> V_61 . V_62 -> V_20 ) ;
if ( F_13 ( V_58 , V_59 ) ) {
F_2 ( V_55 , V_56 -> V_63 ) ;
V_60 = 1 ;
break;
}
}
if ( ! V_60 )
F_8 ( V_55 , V_54 ) ;
}
void F_38 ( struct V_1 * V_2 ,
struct V_13 * V_15 ,
T_3 V_64 )
{
struct V_10 * V_29 , * V_65 ;
struct V_3 * V_31 ;
F_22 (lchunk, ltemp, &transport->transmitted) {
V_31 = F_5 ( V_29 , struct V_3 ,
V_34 ) ;
if ( F_39 ( V_31 ) ) {
F_6 ( V_29 ) ;
F_35 ( & V_2 -> V_28 , V_29 ) ;
if ( ! V_31 -> V_66 ) {
if ( V_31 -> V_15 )
V_31 -> V_15 -> V_67 -=
F_40 ( V_31 ) ;
V_2 -> V_68 -= F_40 ( V_31 ) ;
V_2 -> V_24 -> V_69 . V_70 += F_40 ( V_31 ) ;
}
continue;
}
if ( ( V_64 == V_71 &&
( V_31 -> V_72 == V_73 ) ) ||
( V_64 != V_71 && ! V_31 -> V_66 ) ) {
V_2 -> V_24 -> V_69 . V_70 += F_40 ( V_31 ) ;
V_2 -> V_68 -= F_40 ( V_31 ) ;
if ( V_31 -> V_15 )
V_15 -> V_67 -= F_40 ( V_31 ) ;
V_31 -> V_74 = 0 ;
if ( V_31 -> V_75 ) {
V_31 -> V_75 = 0 ;
V_15 -> V_76 = 0 ;
}
V_31 -> V_77 = 1 ;
F_6 ( V_29 ) ;
F_35 ( & V_2 -> V_26 , V_29 ) ;
}
}
F_28 ( L_4
L_5 , V_39 , V_15 , V_64 ,
V_15 -> V_78 , V_15 -> V_79 , V_15 -> V_67 ,
V_15 -> V_80 ) ;
}
void F_41 ( struct V_1 * V_2 , struct V_13 * V_15 ,
T_4 V_64 )
{
struct V_36 * V_36 = F_27 ( V_2 -> V_24 -> V_37 . V_38 ) ;
int error = 0 ;
switch ( V_64 ) {
case V_81 :
F_33 ( V_36 , V_82 ) ;
F_42 ( V_15 , V_83 ) ;
if ( V_15 == V_15 -> V_24 -> V_69 . V_84 )
F_43 ( V_15 -> V_24 ) ;
V_15 -> V_24 -> V_85 +=
V_15 -> V_24 -> V_86 ;
break;
case V_71 :
F_33 ( V_36 , V_87 ) ;
F_42 ( V_15 , V_88 ) ;
V_2 -> V_89 = 1 ;
break;
case V_90 :
F_33 ( V_36 , V_91 ) ;
break;
case V_92 :
F_33 ( V_36 , V_93 ) ;
V_15 -> V_24 -> V_94 ++ ;
break;
default:
F_44 () ;
}
F_38 ( V_2 , V_15 , V_64 ) ;
if ( V_64 == V_81 )
F_45 ( V_2 , V_2 -> V_24 -> V_95 ) ;
if ( V_64 != V_71 )
error = F_34 ( V_2 , 1 , V_96 ) ;
if ( error )
V_2 -> V_24 -> V_37 . V_38 -> V_97 = - error ;
}
static int F_46 ( struct V_1 * V_2 , struct V_98 * V_99 ,
int V_100 , int * V_101 )
{
struct V_10 * V_102 ;
struct V_13 * V_15 = V_99 -> V_15 ;
T_5 V_103 ;
struct V_3 * V_31 , * V_104 ;
int V_89 ;
int error = 0 ;
int V_105 = 0 ;
int V_60 = 0 ;
V_102 = & V_2 -> V_26 ;
V_89 = V_2 -> V_89 ;
F_23 (chunk, chunk1, lqueue, transmitted_list) {
if ( F_39 ( V_31 ) ) {
F_6 ( & V_31 -> V_34 ) ;
F_35 ( & V_2 -> V_28 ,
& V_31 -> V_34 ) ;
continue;
}
if ( V_31 -> V_66 ) {
F_47 ( & V_31 -> V_34 ,
& V_15 -> V_33 ) ;
continue;
}
if ( V_89 && ! V_31 -> V_72 )
continue;
V_106:
V_103 = F_48 ( V_99 , V_31 ) ;
switch ( V_103 ) {
case V_107 :
if ( ! V_99 -> V_108 && ! V_99 -> V_109 ) {
F_49 ( V_99 , V_96 ) ;
goto V_106;
}
error = F_49 ( V_99 , V_96 ) ;
if ( V_100 || V_89 )
V_60 = 1 ;
else
goto V_106;
break;
case V_110 :
error = F_49 ( V_99 , V_96 ) ;
V_60 = 1 ;
break;
case V_111 :
error = F_49 ( V_99 , V_96 ) ;
V_60 = 1 ;
break;
default:
F_47 ( & V_31 -> V_34 ,
& V_15 -> V_33 ) ;
if ( V_31 -> V_72 == V_73 )
V_31 -> V_72 = V_112 ;
V_2 -> V_24 -> V_113 . V_114 ++ ;
break;
}
if ( ! error && ! V_105 )
V_105 = 1 ;
if ( V_60 )
break;
}
if ( V_100 || V_89 ) {
F_18 (chunk1, lqueue, transmitted_list) {
if ( V_104 -> V_72 == V_73 )
V_104 -> V_72 = V_112 ;
}
}
* V_101 = V_105 ;
if ( V_89 )
V_2 -> V_89 = 0 ;
return error ;
}
int F_50 ( struct V_1 * V_2 , T_2 V_35 )
{
if ( V_2 -> V_53 )
V_2 -> V_53 = 0 ;
return F_34 ( V_2 , 0 , V_35 ) ;
}
static int F_34 ( struct V_1 * V_2 , int V_100 , T_2 V_35 )
{
struct V_98 * V_115 ;
struct V_98 V_116 ;
struct V_23 * V_24 = V_2 -> V_24 ;
T_6 V_117 = V_24 -> V_37 . V_118 . V_119 ;
T_6 V_120 = V_24 -> V_69 . V_119 ;
T_1 V_121 = V_24 -> V_69 . V_122 . V_123 ;
struct V_13 * V_15 = NULL ;
struct V_13 * V_124 ;
struct V_3 * V_31 , * V_32 ;
T_5 V_103 ;
int error = 0 ;
int V_101 = 0 ;
int V_125 = 0 ;
struct V_10 V_126 ;
struct V_10 * V_127 ;
F_16 ( & V_126 ) ;
V_115 = NULL ;
F_23 (chunk, tmp, &q->control_chunk_list, list) {
if ( V_24 -> V_128 &&
V_31 -> V_40 -> type != V_129 )
continue;
F_6 ( & V_31 -> V_5 ) ;
V_124 = V_31 -> V_15 ;
if ( ! V_124 ) {
if ( V_15 &&
F_51 ( & V_31 -> V_130 ,
& V_15 -> V_131 ) )
V_124 = V_15 ;
else
V_124 = F_52 ( V_24 ,
& V_31 -> V_130 ) ;
if ( ! V_124 )
V_124 = V_24 -> V_69 . V_132 ;
} else if ( ( V_124 -> V_41 == V_133 ) ||
( V_124 -> V_41 == V_134 ) ||
( V_124 -> V_41 == V_135 ) ) {
if ( V_31 -> V_40 -> type != V_136 &&
V_31 -> V_40 -> type != V_137 &&
V_31 -> V_40 -> type != V_138 )
V_124 = V_24 -> V_69 . V_132 ;
}
if ( V_124 != V_15 ) {
V_15 = V_124 ;
if ( F_4 ( & V_15 -> V_139 ) ) {
F_8 ( & V_15 -> V_139 ,
& V_126 ) ;
}
V_115 = & V_15 -> V_115 ;
F_53 ( V_115 , V_121 ,
V_24 -> V_69 . V_140 ) ;
}
switch ( V_31 -> V_40 -> type ) {
case V_141 :
case V_142 :
case V_143 :
F_54 ( & V_116 , V_15 , V_117 , V_120 ) ;
F_53 ( & V_116 , V_121 , 0 ) ;
F_48 ( & V_116 , V_31 ) ;
error = F_49 ( & V_116 , V_35 ) ;
if ( error < 0 )
return error ;
break;
case V_144 :
if ( F_55 ( V_31 ) ) {
V_115 -> V_121 = V_24 -> V_145 . V_146 ;
}
case V_137 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_138 :
V_125 = 1 ;
case V_152 :
case V_136 :
case V_153 :
case V_154 :
case V_129 :
case V_155 :
V_103 = F_56 ( V_115 , V_31 ,
V_125 , V_35 ) ;
if ( V_103 != V_156 ) {
F_2 ( & V_31 -> V_5 , & V_2 -> V_25 ) ;
} else {
V_24 -> V_113 . V_157 ++ ;
if ( V_31 -> V_40 -> type == V_155 ) {
F_57 ( V_15 ) ;
V_15 -> V_158 = V_159 ;
}
}
break;
default:
F_44 () ;
}
}
if ( V_2 -> V_24 -> V_128 )
goto V_160;
switch ( V_24 -> V_41 ) {
case V_161 :
if ( ! V_115 || ! V_115 -> V_109 )
break;
case V_162 :
case V_43 :
case V_45 :
if ( ! F_4 ( & V_2 -> V_26 ) ) {
if ( V_24 -> V_69 . V_84 -> V_41 == V_134 )
goto V_160;
if ( V_15 == V_24 -> V_69 . V_84 )
goto V_163;
V_15 = V_24 -> V_69 . V_84 ;
if ( F_4 ( & V_15 -> V_139 ) ) {
F_8 ( & V_15 -> V_139 ,
& V_126 ) ;
}
V_115 = & V_15 -> V_115 ;
F_53 ( V_115 , V_121 ,
V_24 -> V_69 . V_140 ) ;
V_163:
error = F_46 ( V_2 , V_115 ,
V_100 , & V_101 ) ;
if ( V_101 ) {
F_57 ( V_15 ) ;
V_15 -> V_158 = V_159 ;
}
if ( V_115 -> V_109 )
goto V_160;
if ( ! F_4 ( & V_2 -> V_26 ) )
goto V_160;
}
if ( V_15 )
F_58 ( V_15 ) ;
while ( ( V_31 = F_3 ( V_2 ) ) != NULL ) {
if ( V_31 -> V_164 . V_165 >=
V_24 -> V_145 . V_166 ) {
F_20 ( V_31 , V_167 ) ;
F_21 ( V_31 ) ;
continue;
}
if ( F_39 ( V_31 ) ) {
F_20 ( V_31 , 0 ) ;
F_21 ( V_31 ) ;
continue;
}
V_124 = V_31 -> V_15 ;
if ( ! V_124 ||
( ( V_124 -> V_41 == V_133 ) ||
( V_124 -> V_41 == V_134 ) ||
( V_124 -> V_41 == V_135 ) ) )
V_124 = V_24 -> V_69 . V_132 ;
if ( V_124 -> V_41 == V_134 ) {
F_59 ( 1 , L_6 ) ;
F_20 ( V_31 , 0 ) ;
F_21 ( V_31 ) ;
continue;
}
if ( V_124 != V_15 ) {
V_15 = V_124 ;
if ( F_4 ( & V_15 -> V_139 ) ) {
F_8 ( & V_15 -> V_139 ,
& V_126 ) ;
}
V_115 = & V_15 -> V_115 ;
F_53 ( V_115 , V_121 ,
V_24 -> V_69 . V_140 ) ;
F_58 ( V_15 ) ;
}
F_28 ( L_7
L_8 ,
V_39 , V_2 , V_31 , V_31 && V_31 -> V_40 ?
F_29 ( F_30 ( V_31 -> V_40 -> type ) ) :
L_2 , F_36 ( V_31 -> V_61 . V_62 -> V_20 ) ,
V_31 -> V_8 ? V_31 -> V_8 -> V_54 : NULL , V_31 -> V_8 ?
F_60 ( & V_31 -> V_8 -> V_168 ) : - 1 ) ;
V_103 = F_56 ( V_115 , V_31 , 0 , V_35 ) ;
switch ( V_103 ) {
case V_107 :
case V_110 :
case V_111 :
F_28 ( L_9 ,
V_39 , F_36 ( V_31 -> V_61 . V_62 -> V_20 ) ,
V_103 ) ;
F_1 ( V_2 , V_31 ) ;
goto V_160;
case V_156 :
if ( V_24 -> V_41 == V_43 )
V_31 -> V_40 -> V_48 |= V_169 ;
if ( V_31 -> V_40 -> V_48 & V_49 )
V_24 -> V_113 . V_170 ++ ;
else
V_24 -> V_113 . V_171 ++ ;
break;
default:
F_44 () ;
}
F_8 ( & V_31 -> V_34 ,
& V_15 -> V_33 ) ;
F_57 ( V_15 ) ;
V_15 -> V_158 = V_159 ;
if ( V_115 -> V_109 )
goto V_160;
}
break;
default:
break;
}
V_160:
while ( ( V_127 = F_19 ( & V_126 ) ) != NULL ) {
struct V_13 * V_172 = F_5 ( V_127 ,
struct V_13 ,
V_139 ) ;
V_115 = & V_172 -> V_115 ;
if ( ! F_61 ( V_115 ) )
error = F_49 ( V_115 , V_35 ) ;
F_62 ( V_172 ) ;
}
return error ;
}
static void F_63 ( struct V_23 * V_173 ,
struct V_174 * V_175 )
{
T_7 * V_176 ;
T_6 V_86 ;
int V_122 ;
V_86 = V_173 -> V_177 - V_173 -> V_95 - 1 ;
V_176 = V_175 -> V_178 ;
for ( V_122 = 0 ; V_122 < F_64 ( V_175 -> V_179 ) ; V_122 ++ ) {
V_86 -= ( ( F_64 ( V_176 [ V_122 ] . V_180 . V_181 ) -
F_64 ( V_176 [ V_122 ] . V_180 . V_182 ) + 1 ) ) ;
}
V_173 -> V_86 = V_86 ;
}
int F_65 ( struct V_1 * V_2 , struct V_3 * V_31 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_174 * V_175 = V_31 -> V_61 . V_183 ;
struct V_13 * V_15 ;
struct V_3 * V_184 = NULL ;
struct V_10 * V_29 , * V_126 , * V_30 ;
T_7 * V_176 = V_175 -> V_178 ;
T_1 V_185 , V_186 , V_20 ;
T_1 V_187 , V_188 ;
T_1 V_189 ;
unsigned int V_190 ;
struct V_13 * V_14 = V_24 -> V_69 . V_191 ;
int V_16 = 0 ;
int V_192 ;
T_8 V_193 = 0 ;
V_126 = & V_24 -> V_69 . V_194 ;
V_185 = F_36 ( V_175 -> V_195 ) ;
V_192 = F_64 ( V_175 -> V_179 ) ;
V_24 -> V_113 . V_196 += V_192 ;
if ( V_14 -> V_17 . V_22 ) {
T_8 V_197 = 0 ;
if ( F_66 ( V_14 -> V_17 . V_21 , V_185 ) ) {
V_14 -> V_17 . V_22 = 0 ;
V_197 = 1 ;
}
if ( V_197 || V_192 ) {
F_18 (transport, transport_list,
transports) {
if ( V_197 )
V_15 -> V_17 . V_19 = 0 ;
if ( V_192 )
V_15 -> V_17 . V_18 = 0 ;
}
}
}
V_187 = V_185 ;
if ( V_192 )
V_187 += F_64 ( V_176 [ V_192 - 1 ] . V_180 . V_181 ) ;
if ( F_13 ( V_24 -> V_198 , V_187 ) )
V_24 -> V_198 = V_187 ;
V_188 = V_185 ;
F_67 ( V_2 , & V_2 -> V_26 , NULL , NULL , V_175 , & V_188 ) ;
F_18 (transport, transport_list, transports) {
F_67 ( V_2 , & V_15 -> V_33 ,
V_15 , & V_31 -> V_199 , V_175 ,
& V_188 ) ;
if ( V_15 -> V_17 . V_18 )
V_16 ++ ;
}
if ( F_13 ( V_24 -> V_95 , V_185 ) ) {
V_24 -> V_95 = V_185 ;
V_193 = 1 ;
}
if ( V_192 ) {
if ( V_24 -> V_200 && V_193 )
V_188 = V_187 ;
F_18 (transport, transport_list, transports)
F_68 ( V_2 , & V_15 -> V_33 , V_15 ,
V_188 , V_16 ) ;
}
F_63 ( V_24 , V_175 ) ;
V_186 = V_24 -> V_95 ;
F_22 (lchunk, temp, &q->sacked) {
V_184 = F_5 ( V_29 , struct V_3 ,
V_34 ) ;
V_20 = F_36 ( V_184 -> V_61 . V_62 -> V_20 ) ;
if ( F_66 ( V_20 , V_186 ) ) {
F_6 ( & V_184 -> V_34 ) ;
F_21 ( V_184 ) ;
}
}
V_189 = F_36 ( V_175 -> V_201 ) ;
V_24 -> V_69 . V_202 = ! V_189 ;
V_190 = V_2 -> V_68 ;
if ( V_190 < V_189 )
V_189 -= V_190 ;
else
V_189 = 0 ;
V_24 -> V_69 . V_70 = V_189 ;
F_45 ( V_2 , V_185 ) ;
F_28 ( L_10 , V_39 , V_185 ) ;
F_28 ( L_11
L_12 , V_39 , V_24 , V_186 ,
V_24 -> V_203 ) ;
return F_69 ( V_2 ) ;
}
int F_69 ( const struct V_1 * V_2 )
{
return V_2 -> V_7 == 0 && V_2 -> V_68 == 0 &&
F_4 ( & V_2 -> V_26 ) ;
}
static void F_67 ( struct V_1 * V_2 ,
struct V_10 * V_204 ,
struct V_13 * V_15 ,
union V_205 * V_206 ,
struct V_174 * V_175 ,
T_1 * V_207 )
{
struct V_10 * V_29 ;
struct V_3 * V_184 ;
struct V_10 V_208 ;
T_1 V_20 ;
T_1 V_185 ;
T_1 V_209 ;
T_3 V_210 = 0 ;
int V_211 = 0 ;
int V_212 = 0 ;
bool V_213 = false ;
V_185 = F_36 ( V_175 -> V_195 ) ;
F_16 ( & V_208 ) ;
while ( NULL != ( V_29 = F_19 ( V_204 ) ) ) {
V_184 = F_5 ( V_29 , struct V_3 ,
V_34 ) ;
if ( F_39 ( V_184 ) ) {
F_35 ( & V_2 -> V_28 , V_29 ) ;
if ( ! V_184 -> V_66 ) {
if ( V_184 -> V_15 )
V_184 -> V_15 -> V_67 -=
F_40 ( V_184 ) ;
V_2 -> V_68 -= F_40 ( V_184 ) ;
}
continue;
}
V_20 = F_36 ( V_184 -> V_61 . V_62 -> V_20 ) ;
if ( F_70 ( V_175 , V_20 ) ) {
if ( V_15 ) {
if ( ! V_184 -> V_66 &&
! V_184 -> V_77 &&
V_184 -> V_75 ) {
V_184 -> V_75 = 0 ;
V_209 = V_159 - V_184 -> V_214 ;
F_71 ( V_15 ,
V_209 ) ;
}
}
if ( ! V_184 -> V_66 ) {
V_184 -> V_66 = 1 ;
if ( F_13 ( * V_207 , V_20 ) )
* V_207 = V_20 ;
V_211 += F_40 ( V_184 ) ;
if ( ! V_184 -> V_15 )
V_212 += F_40 ( V_184 ) ;
V_213 = true ;
}
if ( F_66 ( V_20 , V_185 ) ) {
V_210 = 1 ;
V_213 = true ;
if ( ! V_184 -> V_66 ) {
if ( V_15 &&
V_175 -> V_179 &&
V_2 -> V_24 -> V_69 . V_191 -> V_17 .
V_22 )
V_15 -> V_17 . V_18
= 1 ;
}
F_8 ( & V_184 -> V_34 ,
& V_2 -> V_27 ) ;
} else {
F_8 ( V_29 , & V_208 ) ;
}
} else {
if ( V_184 -> V_66 ) {
F_28 ( L_13 ,
V_39 , V_20 ) ;
V_184 -> V_66 = 0 ;
if ( V_184 -> V_15 )
V_211 -= F_40 ( V_184 ) ;
V_210 = 1 ;
}
F_8 ( V_29 , & V_208 ) ;
}
}
if ( V_15 ) {
if ( V_211 ) {
struct V_23 * V_24 = V_15 -> V_24 ;
V_211 -= V_212 ;
V_15 -> V_215 = 0 ;
V_15 -> V_24 -> V_216 = 0 ;
V_213 = true ;
if ( V_24 -> V_41 == V_43 &&
F_72 ( & V_24 -> V_217
[ V_218 ] ) )
F_73 ( V_24 ) ;
if ( ( V_15 -> V_41 == V_133 ||
V_15 -> V_41 == V_134 ) &&
F_51 ( & V_15 -> V_131 , V_206 ) ) {
F_74 (
V_15 -> V_24 ,
V_15 ,
V_219 ,
V_220 ) ;
}
F_75 ( V_15 , V_185 ,
V_211 ) ;
V_15 -> V_67 -= V_211 ;
if ( V_15 -> V_67 == 0 )
V_15 -> V_80 = 0 ;
V_2 -> V_68 -= V_211 + V_212 ;
} else {
if ( ! V_2 -> V_24 -> V_69 . V_70 &&
! F_4 ( & V_208 ) &&
( V_185 + 2 == V_2 -> V_24 -> V_177 ) &&
V_2 -> V_24 -> V_41 < V_43 ) {
F_28 ( L_14
L_15 , V_39 , V_185 ) ;
V_2 -> V_24 -> V_216 = 0 ;
V_15 -> V_215 = 0 ;
}
}
if ( ! V_15 -> V_67 ) {
if ( F_72 ( & V_15 -> V_221 ) )
F_76 ( V_15 ) ;
} else if ( V_210 ) {
if ( ! F_77 ( & V_15 -> V_221 ,
V_159 + V_15 -> V_222 ) )
F_78 ( V_15 ) ;
}
if ( V_213 ) {
if ( V_15 -> V_223 )
F_79 ( V_15 -> V_223 ) ;
}
}
F_80 ( & V_208 , V_204 ) ;
}
static void F_68 ( struct V_1 * V_2 ,
struct V_10 * V_204 ,
struct V_13 * V_15 ,
T_1 V_207 ,
int V_16 )
{
struct V_3 * V_31 ;
T_1 V_20 ;
char V_224 = 0 ;
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_13 * V_14 = V_24 -> V_69 . V_191 ;
F_18 (chunk, transmitted_queue, transmitted_list) {
V_20 = F_36 ( V_31 -> V_61 . V_62 -> V_20 ) ;
if ( V_31 -> V_72 == V_225 &&
! V_31 -> V_66 &&
F_13 ( V_20 , V_207 ) ) {
if ( ! V_15 || ! F_14 ( V_14 ,
V_31 -> V_15 ,
V_16 , V_20 ) ) {
V_31 -> V_74 ++ ;
F_28 ( L_16 ,
V_39 , V_20 , V_31 -> V_74 ) ;
}
}
if ( V_31 -> V_74 >= 3 ) {
V_31 -> V_72 = V_73 ;
V_224 = 1 ;
}
}
if ( V_15 ) {
if ( V_224 )
F_41 ( V_2 , V_15 , V_71 ) ;
F_28 ( L_17
L_5 , V_39 , V_15 ,
V_15 -> V_78 , V_15 -> V_79 ,
V_15 -> V_67 , V_15 -> V_80 ) ;
}
}
static int F_70 ( struct V_174 * V_175 , T_1 V_20 )
{
int V_122 ;
T_7 * V_176 ;
T_6 V_226 ;
T_1 V_186 = F_36 ( V_175 -> V_195 ) ;
if ( F_66 ( V_20 , V_186 ) )
goto V_227;
V_176 = V_175 -> V_178 ;
V_226 = V_20 - V_186 ;
for ( V_122 = 0 ; V_122 < F_64 ( V_175 -> V_179 ) ; ++ V_122 ) {
if ( F_66 ( F_64 ( V_176 [ V_122 ] . V_180 . V_182 ) , V_226 ) &&
F_66 ( V_226 , F_64 ( V_176 [ V_122 ] . V_180 . V_181 ) ) )
goto V_227;
}
return 0 ;
V_227:
return 1 ;
}
static inline int F_81 ( struct V_228 * V_229 ,
int V_230 , T_9 V_231 )
{
int V_122 ;
for ( V_122 = 0 ; V_122 < V_230 ; V_122 ++ ) {
if ( V_229 [ V_122 ] . V_231 == V_231 )
return V_122 ;
}
return V_122 ;
}
static void F_45 ( struct V_1 * V_2 , T_1 V_186 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_3 * V_232 = NULL ;
struct V_228 V_233 [ 10 ] ;
int V_230 = 0 ;
int V_234 = 0 ;
T_1 V_20 ;
struct V_3 * V_31 ;
struct V_10 * V_29 , * V_30 ;
if ( ! V_24 -> V_69 . V_235 )
return;
if ( F_13 ( V_24 -> V_203 , V_186 ) )
V_24 -> V_203 = V_186 ;
F_22 (lchunk, temp, &q->abandoned) {
V_31 = F_5 ( V_29 , struct V_3 ,
V_34 ) ;
V_20 = F_36 ( V_31 -> V_61 . V_62 -> V_20 ) ;
if ( F_66 ( V_20 , V_186 ) ) {
F_6 ( V_29 ) ;
F_21 ( V_31 ) ;
} else {
if ( F_66 ( V_20 , V_24 -> V_203 + 1 ) ) {
V_24 -> V_203 = V_20 ;
if ( V_31 -> V_40 -> V_48 &
V_49 )
continue;
V_234 = F_81 ( & V_233 [ 0 ] ,
V_230 ,
V_31 -> V_61 . V_62 -> V_231 ) ;
V_233 [ V_234 ] . V_231 =
V_31 -> V_61 . V_62 -> V_231 ;
V_233 [ V_234 ] . V_236 =
V_31 -> V_61 . V_62 -> V_236 ;
if ( V_234 == V_230 )
V_230 ++ ;
if ( V_230 == 10 )
break;
} else
break;
}
}
if ( V_24 -> V_203 > V_186 )
V_232 = F_82 ( V_24 , V_24 -> V_203 ,
V_230 , & V_233 [ 0 ] ) ;
if ( V_232 ) {
F_8 ( & V_232 -> V_5 , & V_2 -> V_25 ) ;
F_33 ( F_27 ( V_24 -> V_37 . V_38 ) , V_52 ) ;
}
}
