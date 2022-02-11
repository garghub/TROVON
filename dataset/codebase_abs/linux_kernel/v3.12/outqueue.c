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
V_2 -> V_29 = 1 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_13 * V_15 ;
struct V_10 * V_30 , * V_31 ;
struct V_3 * V_32 , * V_33 ;
F_18 (transport, &q->asoc->peer.transport_addr_list,
transports) {
while ( ( V_30 = F_19 ( & V_15 -> V_34 ) ) != NULL ) {
V_32 = F_5 ( V_30 , struct V_3 ,
V_35 ) ;
F_20 ( V_32 , V_2 -> error ) ;
F_21 ( V_32 ) ;
}
}
F_22 (lchunk, temp, &q->sacked) {
F_6 ( V_30 ) ;
V_32 = F_5 ( V_30 , struct V_3 ,
V_35 ) ;
F_20 ( V_32 , V_2 -> error ) ;
F_21 ( V_32 ) ;
}
F_22 (lchunk, temp, &q->retransmit) {
F_6 ( V_30 ) ;
V_32 = F_5 ( V_30 , struct V_3 ,
V_35 ) ;
F_20 ( V_32 , V_2 -> error ) ;
F_21 ( V_32 ) ;
}
F_22 (lchunk, temp, &q->abandoned) {
F_6 ( V_30 ) ;
V_32 = F_5 ( V_30 , struct V_3 ,
V_35 ) ;
F_20 ( V_32 , V_2 -> error ) ;
F_21 ( V_32 ) ;
}
while ( ( V_32 = F_3 ( V_2 ) ) != NULL ) {
F_20 ( V_32 , V_2 -> error ) ;
F_21 ( V_32 ) ;
}
F_23 (chunk, tmp, &q->control_chunk_list, list) {
F_6 ( & V_32 -> V_5 ) ;
F_21 ( V_32 ) ;
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
int F_26 ( struct V_1 * V_2 , struct V_3 * V_32 )
{
struct V_36 * V_36 = F_27 ( V_2 -> V_24 -> V_37 . V_38 ) ;
int error = 0 ;
F_28 ( L_1 , V_39 , V_2 , V_32 ,
V_32 && V_32 -> V_40 ?
F_29 ( F_30 ( V_32 -> V_40 -> type ) ) :
L_2 ) ;
if ( F_31 ( V_32 ) ) {
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
V_39 , V_2 , V_32 , V_32 && V_32 -> V_40 ?
F_29 ( F_30 ( V_32 -> V_40 -> type ) ) :
L_2 ) ;
F_7 ( V_2 , V_32 ) ;
if ( V_32 -> V_40 -> V_48 & V_49 )
F_32 ( V_36 , V_50 ) ;
else
F_32 ( V_36 , V_51 ) ;
V_2 -> V_29 = 0 ;
break;
}
} else {
F_8 ( & V_32 -> V_5 , & V_2 -> V_25 ) ;
F_32 ( V_36 , V_52 ) ;
}
if ( error < 0 )
return error ;
if ( ! V_2 -> V_53 )
error = F_33 ( V_2 , 0 ) ;
return error ;
}
static void F_34 ( struct V_10 * V_54 , struct V_10 * V_55 )
{
struct V_10 * V_56 ;
struct V_3 * V_57 , * V_30 ;
T_1 V_58 , V_59 ;
int V_60 = 0 ;
V_57 = F_5 ( V_55 , struct V_3 , V_35 ) ;
V_58 = F_35 ( V_57 -> V_61 . V_62 -> V_20 ) ;
F_36 (pos, head) {
V_30 = F_5 ( V_56 , struct V_3 , V_35 ) ;
V_59 = F_35 ( V_30 -> V_61 . V_62 -> V_20 ) ;
if ( F_13 ( V_58 , V_59 ) ) {
F_2 ( V_55 , V_56 -> V_63 ) ;
V_60 = 1 ;
break;
}
}
if ( ! V_60 )
F_8 ( V_55 , V_54 ) ;
}
void F_37 ( struct V_1 * V_2 ,
struct V_13 * V_15 ,
T_2 V_64 )
{
struct V_10 * V_30 , * V_65 ;
struct V_3 * V_32 ;
F_22 (lchunk, ltemp, &transport->transmitted) {
V_32 = F_5 ( V_30 , struct V_3 ,
V_35 ) ;
if ( F_38 ( V_32 ) ) {
F_6 ( V_30 ) ;
F_34 ( & V_2 -> V_28 , V_30 ) ;
if ( ! V_32 -> V_66 ) {
if ( V_32 -> V_15 )
V_32 -> V_15 -> V_67 -=
F_39 ( V_32 ) ;
V_2 -> V_68 -= F_39 ( V_32 ) ;
V_2 -> V_24 -> V_69 . V_70 += F_39 ( V_32 ) ;
}
continue;
}
if ( ( V_64 == V_71 &&
( V_32 -> V_72 == V_73 ) ) ||
( V_64 != V_71 && ! V_32 -> V_66 ) ) {
V_2 -> V_24 -> V_69 . V_70 += F_39 ( V_32 ) ;
V_2 -> V_68 -= F_39 ( V_32 ) ;
if ( V_32 -> V_15 )
V_15 -> V_67 -= F_39 ( V_32 ) ;
V_32 -> V_74 = 0 ;
if ( V_32 -> V_75 ) {
V_32 -> V_75 = 0 ;
V_15 -> V_76 = 0 ;
}
F_6 ( V_30 ) ;
F_34 ( & V_2 -> V_26 , V_30 ) ;
}
}
F_28 ( L_4
L_5 , V_39 , V_15 , V_64 ,
V_15 -> V_77 , V_15 -> V_78 , V_15 -> V_67 ,
V_15 -> V_79 ) ;
}
void F_40 ( struct V_1 * V_2 , struct V_13 * V_15 ,
T_3 V_64 )
{
struct V_36 * V_36 = F_27 ( V_2 -> V_24 -> V_37 . V_38 ) ;
int error = 0 ;
switch( V_64 ) {
case V_80 :
F_32 ( V_36 , V_81 ) ;
F_41 ( V_15 , V_82 ) ;
if ( V_15 == V_15 -> V_24 -> V_69 . V_83 )
F_42 ( V_15 -> V_24 ) ;
V_15 -> V_24 -> V_84 +=
V_15 -> V_24 -> V_85 ;
break;
case V_71 :
F_32 ( V_36 , V_86 ) ;
F_41 ( V_15 , V_87 ) ;
V_2 -> V_88 = 1 ;
break;
case V_89 :
F_32 ( V_36 , V_90 ) ;
break;
case V_91 :
F_32 ( V_36 , V_92 ) ;
V_15 -> V_24 -> V_93 ++ ;
break;
default:
F_43 () ;
}
F_37 ( V_2 , V_15 , V_64 ) ;
if ( V_64 == V_80 )
F_44 ( V_2 , V_2 -> V_24 -> V_94 ) ;
if ( V_64 != V_71 )
error = F_33 ( V_2 , 1 ) ;
if ( error )
V_2 -> V_24 -> V_37 . V_38 -> V_95 = - error ;
}
static int F_45 ( struct V_1 * V_2 , struct V_96 * V_97 ,
int V_98 , int * V_99 )
{
struct V_10 * V_100 ;
struct V_13 * V_15 = V_97 -> V_15 ;
T_4 V_101 ;
struct V_3 * V_32 , * V_102 ;
int V_88 ;
int error = 0 ;
int V_103 = 0 ;
int V_60 = 0 ;
V_100 = & V_2 -> V_26 ;
V_88 = V_2 -> V_88 ;
F_23 (chunk, chunk1, lqueue, transmitted_list) {
if ( F_38 ( V_32 ) ) {
F_6 ( & V_32 -> V_35 ) ;
F_34 ( & V_2 -> V_28 ,
& V_32 -> V_35 ) ;
continue;
}
if ( V_32 -> V_66 ) {
F_46 ( & V_32 -> V_35 ,
& V_15 -> V_34 ) ;
continue;
}
if ( V_88 && ! V_32 -> V_72 )
continue;
V_104:
V_101 = F_47 ( V_97 , V_32 ) ;
switch ( V_101 ) {
case V_105 :
if ( ! V_97 -> V_106 && ! V_97 -> V_107 ) {
F_48 ( V_97 ) ;
goto V_104;
}
error = F_48 ( V_97 ) ;
if ( V_98 || V_88 )
V_60 = 1 ;
else
goto V_104;
break;
case V_108 :
error = F_48 ( V_97 ) ;
V_60 = 1 ;
break;
case V_109 :
error = F_48 ( V_97 ) ;
V_60 = 1 ;
break;
default:
F_46 ( & V_32 -> V_35 ,
& V_15 -> V_34 ) ;
if ( V_32 -> V_72 == V_73 )
V_32 -> V_72 = V_110 ;
V_2 -> V_29 = 0 ;
V_2 -> V_24 -> V_111 . V_112 ++ ;
break;
}
if ( ! error && ! V_103 )
V_103 = 1 ;
if ( V_60 )
break;
}
if ( V_98 || V_88 ) {
F_18 (chunk1, lqueue, transmitted_list) {
if ( V_102 -> V_72 == V_73 )
V_102 -> V_72 = V_110 ;
}
}
* V_99 = V_103 ;
if ( V_88 )
V_2 -> V_88 = 0 ;
return error ;
}
int F_49 ( struct V_1 * V_2 )
{
if ( V_2 -> V_53 )
V_2 -> V_53 = 0 ;
return F_33 ( V_2 , 0 ) ;
}
static int F_33 ( struct V_1 * V_2 , int V_98 )
{
struct V_96 * V_113 ;
struct V_96 V_114 ;
struct V_23 * V_24 = V_2 -> V_24 ;
T_5 V_115 = V_24 -> V_37 . V_116 . V_117 ;
T_5 V_118 = V_24 -> V_69 . V_117 ;
T_1 V_119 = V_24 -> V_69 . V_120 . V_121 ;
struct V_13 * V_15 = NULL ;
struct V_13 * V_122 ;
struct V_3 * V_32 , * V_33 ;
T_4 V_101 ;
int error = 0 ;
int V_99 = 0 ;
int V_123 = 0 ;
struct V_10 V_124 ;
struct V_10 * V_125 ;
F_16 ( & V_124 ) ;
V_113 = NULL ;
F_23 (chunk, tmp, &q->control_chunk_list, list) {
if ( V_24 -> V_126 &&
V_32 -> V_40 -> type != V_127 )
continue;
F_6 ( & V_32 -> V_5 ) ;
V_122 = V_32 -> V_15 ;
if ( ! V_122 ) {
if ( V_15 &&
F_50 ( & V_32 -> V_128 ,
& V_15 -> V_129 ) )
V_122 = V_15 ;
else
V_122 = F_51 ( V_24 ,
& V_32 -> V_128 ) ;
if ( ! V_122 )
V_122 = V_24 -> V_69 . V_130 ;
} else if ( ( V_122 -> V_41 == V_131 ) ||
( V_122 -> V_41 == V_132 ) ||
( V_122 -> V_41 == V_133 ) ) {
if ( V_32 -> V_40 -> type != V_134 &&
V_32 -> V_40 -> type != V_135 &&
V_32 -> V_40 -> type != V_136 )
V_122 = V_24 -> V_69 . V_130 ;
}
if ( V_122 != V_15 ) {
V_15 = V_122 ;
if ( F_4 ( & V_15 -> V_137 ) ) {
F_8 ( & V_15 -> V_137 ,
& V_124 ) ;
}
V_113 = & V_15 -> V_113 ;
F_52 ( V_113 , V_119 ,
V_24 -> V_69 . V_138 ) ;
}
switch ( V_32 -> V_40 -> type ) {
case V_139 :
case V_140 :
case V_141 :
F_53 ( & V_114 , V_15 , V_115 , V_118 ) ;
F_52 ( & V_114 , V_119 , 0 ) ;
F_47 ( & V_114 , V_32 ) ;
error = F_48 ( & V_114 ) ;
if ( error < 0 )
return error ;
break;
case V_142 :
if ( F_54 ( V_32 ) ) {
V_113 -> V_119 = V_24 -> V_143 . V_144 ;
}
case V_135 :
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_136 :
V_123 = 1 ;
case V_150 :
case V_134 :
case V_151 :
case V_152 :
case V_127 :
case V_153 :
V_101 = F_55 ( V_113 , V_32 ,
V_123 ) ;
if ( V_101 != V_154 ) {
F_2 ( & V_32 -> V_5 , & V_2 -> V_25 ) ;
} else {
V_24 -> V_111 . V_155 ++ ;
if ( V_32 -> V_40 -> type == V_153 )
F_56 ( V_15 ) ;
}
break;
default:
F_43 () ;
}
}
if ( V_2 -> V_24 -> V_126 )
goto V_156;
switch ( V_24 -> V_41 ) {
case V_157 :
if ( ! V_113 || ! V_113 -> V_107 )
break;
case V_158 :
case V_43 :
case V_45 :
if ( ! F_4 ( & V_2 -> V_26 ) ) {
if ( V_24 -> V_69 . V_83 -> V_41 == V_132 )
goto V_156;
if ( V_15 == V_24 -> V_69 . V_83 )
goto V_159;
V_15 = V_24 -> V_69 . V_83 ;
if ( F_4 ( & V_15 -> V_137 ) ) {
F_8 ( & V_15 -> V_137 ,
& V_124 ) ;
}
V_113 = & V_15 -> V_113 ;
F_52 ( V_113 , V_119 ,
V_24 -> V_69 . V_138 ) ;
V_159:
error = F_45 ( V_2 , V_113 ,
V_98 , & V_99 ) ;
if ( V_99 )
F_56 ( V_15 ) ;
if ( V_113 -> V_107 )
goto V_156;
if ( ! F_4 ( & V_2 -> V_26 ) )
goto V_156;
}
if ( V_15 )
F_57 ( V_15 ) ;
while ( ( V_32 = F_3 ( V_2 ) ) != NULL ) {
if ( V_32 -> V_160 . V_161 >=
V_24 -> V_143 . V_162 ) {
F_20 ( V_32 , V_163 ) ;
F_21 ( V_32 ) ;
continue;
}
if ( F_38 ( V_32 ) ) {
F_20 ( V_32 , 0 ) ;
F_21 ( V_32 ) ;
continue;
}
V_122 = V_32 -> V_15 ;
if ( ! V_122 ||
( ( V_122 -> V_41 == V_131 ) ||
( V_122 -> V_41 == V_132 ) ||
( V_122 -> V_41 == V_133 ) ) )
V_122 = V_24 -> V_69 . V_130 ;
if ( V_122 -> V_41 == V_132 )
continue;
if ( V_122 != V_15 ) {
V_15 = V_122 ;
if ( F_4 ( & V_15 -> V_137 ) ) {
F_8 ( & V_15 -> V_137 ,
& V_124 ) ;
}
V_113 = & V_15 -> V_113 ;
F_52 ( V_113 , V_119 ,
V_24 -> V_69 . V_138 ) ;
F_57 ( V_15 ) ;
}
F_28 ( L_6
L_7 ,
V_39 , V_2 , V_32 , V_32 && V_32 -> V_40 ?
F_29 ( F_30 ( V_32 -> V_40 -> type ) ) :
L_2 , F_35 ( V_32 -> V_61 . V_62 -> V_20 ) ,
V_32 -> V_8 ? V_32 -> V_8 -> V_54 : NULL , V_32 -> V_8 ?
F_58 ( & V_32 -> V_8 -> V_164 ) : - 1 ) ;
V_101 = F_55 ( V_113 , V_32 , 0 ) ;
switch ( V_101 ) {
case V_105 :
case V_108 :
case V_109 :
F_28 ( L_8 ,
V_39 , F_35 ( V_32 -> V_61 . V_62 -> V_20 ) ,
V_101 ) ;
F_1 ( V_2 , V_32 ) ;
goto V_156;
break;
case V_154 :
if ( V_24 -> V_41 == V_43 )
V_32 -> V_40 -> V_48 |= V_165 ;
if ( V_32 -> V_40 -> V_48 & V_49 )
V_24 -> V_111 . V_166 ++ ;
else
V_24 -> V_111 . V_167 ++ ;
break;
default:
F_43 () ;
}
F_8 ( & V_32 -> V_35 ,
& V_15 -> V_34 ) ;
F_56 ( V_15 ) ;
V_2 -> V_29 = 0 ;
if ( V_113 -> V_107 )
goto V_156;
}
break;
default:
break;
}
V_156:
while ( ( V_125 = F_19 ( & V_124 ) ) != NULL ) {
struct V_13 * V_168 = F_5 ( V_125 ,
struct V_13 ,
V_137 ) ;
V_113 = & V_168 -> V_113 ;
if ( ! F_59 ( V_113 ) )
error = F_48 ( V_113 ) ;
F_60 ( V_168 ) ;
}
return error ;
}
static void F_61 ( struct V_23 * V_169 ,
struct V_170 * V_171 )
{
T_6 * V_172 ;
T_5 V_85 ;
int V_120 ;
V_85 = V_169 -> V_173 - V_169 -> V_94 - 1 ;
V_172 = V_171 -> V_174 ;
for ( V_120 = 0 ; V_120 < F_62 ( V_171 -> V_175 ) ; V_120 ++ ) {
V_85 -= ( ( F_62 ( V_172 [ V_120 ] . V_176 . V_177 ) -
F_62 ( V_172 [ V_120 ] . V_176 . V_178 ) + 1 ) ) ;
}
V_169 -> V_85 = V_85 ;
}
int F_63 ( struct V_1 * V_2 , struct V_3 * V_32 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_170 * V_171 = V_32 -> V_61 . V_179 ;
struct V_13 * V_15 ;
struct V_3 * V_180 = NULL ;
struct V_10 * V_30 , * V_124 , * V_31 ;
T_6 * V_172 = V_171 -> V_174 ;
T_1 V_181 , V_182 , V_20 ;
T_1 V_183 , V_184 ;
T_1 V_185 ;
unsigned int V_186 ;
struct V_13 * V_14 = V_24 -> V_69 . V_187 ;
int V_16 = 0 ;
int V_188 ;
T_7 V_189 = 0 ;
V_124 = & V_24 -> V_69 . V_190 ;
V_181 = F_35 ( V_171 -> V_191 ) ;
V_188 = F_62 ( V_171 -> V_175 ) ;
V_24 -> V_111 . V_192 += V_188 ;
if ( V_14 -> V_17 . V_22 ) {
T_7 V_193 = 0 ;
if ( F_64 ( V_14 -> V_17 . V_21 , V_181 ) ) {
V_14 -> V_17 . V_22 = 0 ;
V_193 = 1 ;
}
if ( V_193 || V_188 ) {
F_18 (transport, transport_list,
transports) {
if ( V_193 )
V_15 -> V_17 . V_19 = 0 ;
if ( V_188 )
V_15 -> V_17 . V_18 = 0 ;
}
}
}
V_183 = V_181 ;
if ( V_188 )
V_183 += F_62 ( V_172 [ V_188 - 1 ] . V_176 . V_177 ) ;
if ( F_13 ( V_24 -> V_194 , V_183 ) )
V_24 -> V_194 = V_183 ;
V_184 = V_181 ;
F_65 ( V_2 , & V_2 -> V_26 , NULL , NULL , V_171 , & V_184 ) ;
F_18 (transport, transport_list, transports) {
F_65 ( V_2 , & V_15 -> V_34 ,
V_15 , & V_32 -> V_195 , V_171 ,
& V_184 ) ;
if ( V_15 -> V_17 . V_18 )
V_16 ++ ;
}
if ( F_13 ( V_24 -> V_94 , V_181 ) ) {
V_24 -> V_94 = V_181 ;
V_189 = 1 ;
}
if ( V_188 ) {
if ( V_24 -> V_196 && V_189 )
V_184 = V_183 ;
F_18 (transport, transport_list, transports)
F_66 ( V_2 , & V_15 -> V_34 , V_15 ,
V_184 , V_16 ) ;
}
F_61 ( V_24 , V_171 ) ;
V_182 = V_24 -> V_94 ;
F_22 (lchunk, temp, &q->sacked) {
V_180 = F_5 ( V_30 , struct V_3 ,
V_35 ) ;
V_20 = F_35 ( V_180 -> V_61 . V_62 -> V_20 ) ;
if ( F_64 ( V_20 , V_182 ) ) {
F_6 ( & V_180 -> V_35 ) ;
F_21 ( V_180 ) ;
}
}
V_185 = F_35 ( V_171 -> V_197 ) ;
V_186 = V_2 -> V_68 ;
if ( V_186 < V_185 )
V_185 -= V_186 ;
else
V_185 = 0 ;
V_24 -> V_69 . V_70 = V_185 ;
F_44 ( V_2 , V_181 ) ;
F_28 ( L_9 , V_39 , V_181 ) ;
F_28 ( L_10
L_11 , V_39 , V_24 , V_182 ,
V_24 -> V_198 ) ;
V_2 -> V_29 = ( F_4 ( & V_2 -> V_6 ) &&
F_4 ( & V_2 -> V_26 ) ) ;
if ( ! V_2 -> V_29 )
goto V_199;
F_18 (transport, transport_list, transports) {
V_2 -> V_29 = V_2 -> V_29 && F_4 ( & V_15 -> V_34 ) ;
if ( ! V_2 -> V_29 )
goto V_199;
}
F_28 ( L_12 , V_39 ) ;
V_199:
return V_2 -> V_29 ;
}
int F_67 ( const struct V_1 * V_2 )
{
return V_2 -> V_29 ;
}
static void F_65 ( struct V_1 * V_2 ,
struct V_10 * V_200 ,
struct V_13 * V_15 ,
union V_201 * V_202 ,
struct V_170 * V_171 ,
T_1 * V_203 )
{
struct V_10 * V_30 ;
struct V_3 * V_180 ;
struct V_10 V_204 ;
T_1 V_20 ;
T_1 V_181 ;
T_1 V_205 ;
T_2 V_206 = 0 ;
int V_207 = 0 ;
int V_208 = 0 ;
bool V_209 = false ;
V_181 = F_35 ( V_171 -> V_191 ) ;
F_16 ( & V_204 ) ;
while ( NULL != ( V_30 = F_19 ( V_200 ) ) ) {
V_180 = F_5 ( V_30 , struct V_3 ,
V_35 ) ;
if ( F_38 ( V_180 ) ) {
F_34 ( & V_2 -> V_28 , V_30 ) ;
if ( ! V_180 -> V_66 ) {
if ( V_180 -> V_15 )
V_180 -> V_15 -> V_67 -=
F_39 ( V_180 ) ;
V_2 -> V_68 -= F_39 ( V_180 ) ;
}
continue;
}
V_20 = F_35 ( V_180 -> V_61 . V_62 -> V_20 ) ;
if ( F_68 ( V_171 , V_20 ) ) {
if ( V_15 ) {
if ( ! V_180 -> V_66 &&
V_180 -> V_75 ) {
V_180 -> V_75 = 0 ;
V_205 = V_210 - V_180 -> V_211 ;
F_69 ( V_15 ,
V_205 ) ;
}
}
if ( ! V_180 -> V_66 ) {
V_180 -> V_66 = 1 ;
* V_203 = V_20 ;
V_207 += F_39 ( V_180 ) ;
if ( ! V_180 -> V_15 )
V_208 += F_39 ( V_180 ) ;
V_209 = true ;
}
if ( F_64 ( V_20 , V_181 ) ) {
V_206 = 1 ;
V_209 = true ;
if ( ! V_180 -> V_66 ) {
if ( V_15 &&
V_171 -> V_175 &&
V_2 -> V_24 -> V_69 . V_187 -> V_17 .
V_22 )
V_15 -> V_17 . V_18
= 1 ;
}
F_8 ( & V_180 -> V_35 ,
& V_2 -> V_27 ) ;
} else {
F_8 ( V_30 , & V_204 ) ;
}
} else {
if ( V_180 -> V_66 ) {
F_28 ( L_13 ,
V_39 , V_20 ) ;
V_180 -> V_66 = 0 ;
if ( V_180 -> V_15 )
V_207 -= F_39 ( V_180 ) ;
V_206 = 1 ;
}
F_8 ( V_30 , & V_204 ) ;
}
}
if ( V_15 ) {
if ( V_207 ) {
struct V_23 * V_24 = V_15 -> V_24 ;
V_207 -= V_208 ;
V_15 -> V_212 = 0 ;
V_15 -> V_24 -> V_213 = 0 ;
V_209 = true ;
if ( V_24 -> V_41 == V_43 &&
F_70 ( & V_24 -> V_214
[ V_215 ] ) )
F_71 ( V_24 ) ;
if ( ( V_15 -> V_41 == V_131 ||
V_15 -> V_41 == V_132 ) &&
F_50 ( & V_15 -> V_129 , V_202 ) ) {
F_72 (
V_15 -> V_24 ,
V_15 ,
V_216 ,
V_217 ) ;
}
F_73 ( V_15 , V_181 ,
V_207 ) ;
V_15 -> V_67 -= V_207 ;
if ( V_15 -> V_67 == 0 )
V_15 -> V_79 = 0 ;
V_2 -> V_68 -= V_207 + V_208 ;
} else {
if ( ! V_2 -> V_24 -> V_69 . V_70 &&
! F_4 ( & V_204 ) &&
( V_181 + 2 == V_2 -> V_24 -> V_173 ) &&
V_2 -> V_24 -> V_41 < V_43 ) {
F_28 ( L_14
L_15 , V_39 , V_181 ) ;
V_2 -> V_24 -> V_213 = 0 ;
V_15 -> V_212 = 0 ;
}
}
if ( ! V_15 -> V_67 ) {
if ( F_70 ( & V_15 -> V_218 ) )
F_74 ( V_15 ) ;
} else if ( V_206 ) {
if ( ! F_75 ( & V_15 -> V_218 ,
V_210 + V_15 -> V_219 ) )
F_76 ( V_15 ) ;
}
if ( V_209 ) {
if ( V_15 -> V_220 )
F_77 ( V_15 -> V_220 ) ;
}
}
F_78 ( & V_204 , V_200 ) ;
}
static void F_66 ( struct V_1 * V_2 ,
struct V_10 * V_200 ,
struct V_13 * V_15 ,
T_1 V_203 ,
int V_16 )
{
struct V_3 * V_32 ;
T_1 V_20 ;
char V_221 = 0 ;
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_13 * V_14 = V_24 -> V_69 . V_187 ;
F_18 (chunk, transmitted_queue, transmitted_list) {
V_20 = F_35 ( V_32 -> V_61 . V_62 -> V_20 ) ;
if ( V_32 -> V_72 == V_222 &&
! V_32 -> V_66 &&
F_13 ( V_20 , V_203 ) ) {
if ( ! V_15 || ! F_14 ( V_14 ,
V_32 -> V_15 ,
V_16 , V_20 ) ) {
V_32 -> V_74 ++ ;
F_28 ( L_16 ,
V_39 , V_20 , V_32 -> V_74 ) ;
}
}
if ( V_32 -> V_74 >= 3 ) {
V_32 -> V_72 = V_73 ;
V_221 = 1 ;
}
}
if ( V_15 ) {
if ( V_221 )
F_40 ( V_2 , V_15 , V_71 ) ;
F_28 ( L_17
L_5 , V_39 , V_15 ,
V_15 -> V_77 , V_15 -> V_78 ,
V_15 -> V_67 , V_15 -> V_79 ) ;
}
}
static int F_68 ( struct V_170 * V_171 , T_1 V_20 )
{
int V_120 ;
T_6 * V_172 ;
T_5 V_223 ;
T_1 V_182 = F_35 ( V_171 -> V_191 ) ;
if ( F_64 ( V_20 , V_182 ) )
goto V_224;
V_172 = V_171 -> V_174 ;
V_223 = V_20 - V_182 ;
for ( V_120 = 0 ; V_120 < F_62 ( V_171 -> V_175 ) ; ++ V_120 ) {
if ( F_64 ( F_62 ( V_172 [ V_120 ] . V_176 . V_178 ) , V_223 ) &&
F_64 ( V_223 , F_62 ( V_172 [ V_120 ] . V_176 . V_177 ) ) )
goto V_224;
}
return 0 ;
V_224:
return 1 ;
}
static inline int F_79 ( struct V_225 * V_226 ,
int V_227 , T_8 V_228 )
{
int V_120 ;
for ( V_120 = 0 ; V_120 < V_227 ; V_120 ++ ) {
if ( V_226 [ V_120 ] . V_228 == V_228 )
return V_120 ;
}
return V_120 ;
}
static void F_44 ( struct V_1 * V_2 , T_1 V_182 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_3 * V_229 = NULL ;
struct V_225 V_230 [ 10 ] ;
int V_227 = 0 ;
int V_231 = 0 ;
T_1 V_20 ;
struct V_3 * V_32 ;
struct V_10 * V_30 , * V_31 ;
if ( ! V_24 -> V_69 . V_232 )
return;
if ( F_13 ( V_24 -> V_198 , V_182 ) )
V_24 -> V_198 = V_182 ;
F_22 (lchunk, temp, &q->abandoned) {
V_32 = F_5 ( V_30 , struct V_3 ,
V_35 ) ;
V_20 = F_35 ( V_32 -> V_61 . V_62 -> V_20 ) ;
if ( F_64 ( V_20 , V_182 ) ) {
F_6 ( V_30 ) ;
F_21 ( V_32 ) ;
} else {
if ( F_64 ( V_20 , V_24 -> V_198 + 1 ) ) {
V_24 -> V_198 = V_20 ;
if ( V_32 -> V_40 -> V_48 &
V_49 )
continue;
V_231 = F_79 ( & V_230 [ 0 ] ,
V_227 ,
V_32 -> V_61 . V_62 -> V_228 ) ;
V_230 [ V_231 ] . V_228 =
V_32 -> V_61 . V_62 -> V_228 ;
V_230 [ V_231 ] . V_233 =
V_32 -> V_61 . V_62 -> V_233 ;
if ( V_231 == V_227 )
V_227 ++ ;
if ( V_227 == 10 )
break;
} else
break;
}
}
if ( V_24 -> V_198 > V_182 )
V_229 = F_80 ( V_24 , V_24 -> V_198 ,
V_227 , & V_230 [ 0 ] ) ;
if ( V_229 ) {
F_8 ( & V_229 -> V_5 , & V_2 -> V_25 ) ;
F_32 ( F_27 ( V_24 -> V_37 . V_38 ) , V_52 ) ;
}
}
