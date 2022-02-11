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
V_2 -> V_24 = V_24 ;
F_16 ( & V_2 -> V_6 ) ;
F_16 ( & V_2 -> V_25 ) ;
F_16 ( & V_2 -> V_26 ) ;
F_16 ( & V_2 -> V_27 ) ;
F_16 ( & V_2 -> V_28 ) ;
V_2 -> V_29 = 0 ;
V_2 -> V_30 = 0 ;
V_2 -> V_31 = 1 ;
V_2 -> V_32 = 0 ;
V_2 -> V_33 = 0 ;
V_2 -> V_7 = 0 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_13 * V_15 ;
struct V_10 * V_34 , * V_35 ;
struct V_3 * V_36 , * V_37 ;
F_18 (transport, &q->asoc->peer.transport_addr_list,
transports) {
while ( ( V_34 = F_19 ( & V_15 -> V_38 ) ) != NULL ) {
V_36 = F_5 ( V_34 , struct V_3 ,
V_39 ) ;
F_20 ( V_36 , V_2 -> error ) ;
F_21 ( V_36 ) ;
}
}
F_22 (lchunk, temp, &q->sacked) {
F_6 ( V_34 ) ;
V_36 = F_5 ( V_34 , struct V_3 ,
V_39 ) ;
F_20 ( V_36 , V_2 -> error ) ;
F_21 ( V_36 ) ;
}
F_22 (lchunk, temp, &q->retransmit) {
F_6 ( V_34 ) ;
V_36 = F_5 ( V_34 , struct V_3 ,
V_39 ) ;
F_20 ( V_36 , V_2 -> error ) ;
F_21 ( V_36 ) ;
}
F_22 (lchunk, temp, &q->abandoned) {
F_6 ( V_34 ) ;
V_36 = F_5 ( V_34 , struct V_3 ,
V_39 ) ;
F_20 ( V_36 , V_2 -> error ) ;
F_21 ( V_36 ) ;
}
while ( ( V_36 = F_3 ( V_2 ) ) != NULL ) {
F_20 ( V_36 , V_2 -> error ) ;
F_21 ( V_36 ) ;
}
F_23 (chunk, tmp, &q->control_chunk_list, list) {
F_6 ( & V_36 -> V_5 ) ;
F_21 ( V_36 ) ;
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
if ( V_2 -> V_33 )
F_26 ( V_2 ) ;
}
int F_27 ( struct V_1 * V_2 , struct V_3 * V_36 )
{
struct V_40 * V_40 = F_28 ( V_2 -> V_24 -> V_41 . V_42 ) ;
int error = 0 ;
F_29 ( L_1 ,
V_2 , V_36 , V_36 && V_36 -> V_43 ?
F_30 ( F_31 ( V_36 -> V_43 -> type ) )
: L_2 ) ;
if ( F_32 ( V_36 ) ) {
switch ( V_2 -> V_24 -> V_44 ) {
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
error = - V_50 ;
break;
default:
F_29 ( L_3 ,
V_2 , V_36 , V_36 && V_36 -> V_43 ?
F_30 ( F_31 ( V_36 -> V_43 -> type ) )
: L_2 ) ;
F_7 ( V_2 , V_36 ) ;
if ( V_36 -> V_43 -> V_51 & V_52 )
F_33 ( V_40 , V_53 ) ;
else
F_33 ( V_40 , V_54 ) ;
V_2 -> V_31 = 0 ;
break;
}
} else {
F_8 ( & V_36 -> V_5 , & V_2 -> V_25 ) ;
F_33 ( V_40 , V_55 ) ;
}
if ( error < 0 )
return error ;
if ( ! V_2 -> V_32 )
error = F_34 ( V_2 , 0 ) ;
return error ;
}
static void F_35 ( struct V_10 * V_56 , struct V_10 * V_57 )
{
struct V_10 * V_58 ;
struct V_3 * V_59 , * V_34 ;
T_1 V_60 , V_61 ;
int V_62 = 0 ;
V_59 = F_5 ( V_57 , struct V_3 , V_39 ) ;
V_60 = F_36 ( V_59 -> V_63 . V_64 -> V_20 ) ;
F_37 (pos, head) {
V_34 = F_5 ( V_58 , struct V_3 , V_39 ) ;
V_61 = F_36 ( V_34 -> V_63 . V_64 -> V_20 ) ;
if ( F_13 ( V_60 , V_61 ) ) {
F_2 ( V_57 , V_58 -> V_65 ) ;
V_62 = 1 ;
break;
}
}
if ( ! V_62 )
F_8 ( V_57 , V_56 ) ;
}
void F_38 ( struct V_1 * V_2 ,
struct V_13 * V_15 ,
T_2 V_66 )
{
struct V_10 * V_34 , * V_67 ;
struct V_3 * V_36 ;
F_22 (lchunk, ltemp, &transport->transmitted) {
V_36 = F_5 ( V_34 , struct V_3 ,
V_39 ) ;
if ( F_39 ( V_36 ) ) {
F_6 ( V_34 ) ;
F_35 ( & V_2 -> V_28 , V_34 ) ;
if ( ! V_36 -> V_68 ) {
if ( V_36 -> V_15 )
V_36 -> V_15 -> V_69 -=
F_40 ( V_36 ) ;
V_2 -> V_30 -= F_40 ( V_36 ) ;
V_2 -> V_24 -> V_70 . V_71 += F_40 ( V_36 ) ;
}
continue;
}
if ( ( V_66 == V_72 &&
( V_36 -> V_73 == V_74 ) ) ||
( V_66 != V_72 && ! V_36 -> V_68 ) ) {
V_2 -> V_24 -> V_70 . V_71 += F_40 ( V_36 ) ;
V_2 -> V_30 -= F_40 ( V_36 ) ;
if ( V_36 -> V_15 )
V_15 -> V_69 -= F_40 ( V_36 ) ;
V_36 -> V_75 = 0 ;
if ( V_36 -> V_76 ) {
V_36 -> V_76 = 0 ;
V_15 -> V_77 = 0 ;
}
F_6 ( V_34 ) ;
F_35 ( & V_2 -> V_26 , V_34 ) ;
}
}
F_29 ( L_4
L_5
L_6 , V_78 ,
V_15 , V_66 ,
V_15 -> V_79 , V_15 -> V_80 ,
V_15 -> V_69 ,
V_15 -> V_81 ) ;
}
void F_41 ( struct V_1 * V_2 , struct V_13 * V_15 ,
T_3 V_66 )
{
struct V_40 * V_40 = F_28 ( V_2 -> V_24 -> V_41 . V_42 ) ;
int error = 0 ;
switch( V_66 ) {
case V_82 :
F_33 ( V_40 , V_83 ) ;
F_42 ( V_15 , V_84 ) ;
if ( V_15 == V_15 -> V_24 -> V_70 . V_85 )
F_43 ( V_15 -> V_24 ) ;
V_15 -> V_24 -> V_86 +=
V_15 -> V_24 -> V_87 ;
break;
case V_72 :
F_33 ( V_40 , V_88 ) ;
F_42 ( V_15 , V_89 ) ;
V_2 -> V_29 = 1 ;
break;
case V_90 :
F_33 ( V_40 , V_91 ) ;
break;
case V_92 :
F_33 ( V_40 , V_93 ) ;
V_15 -> V_24 -> V_94 ++ ;
break;
default:
F_44 () ;
}
F_38 ( V_2 , V_15 , V_66 ) ;
if ( V_66 == V_82 )
F_45 ( V_2 , V_2 -> V_24 -> V_95 ) ;
if ( V_66 != V_72 )
error = F_34 ( V_2 , 1 ) ;
if ( error )
V_2 -> V_24 -> V_41 . V_42 -> V_96 = - error ;
}
static int F_46 ( struct V_1 * V_2 , struct V_97 * V_98 ,
int V_99 , int * V_100 )
{
struct V_10 * V_101 ;
struct V_13 * V_15 = V_98 -> V_15 ;
T_4 V_102 ;
struct V_3 * V_36 , * V_103 ;
int V_29 ;
int error = 0 ;
int V_104 = 0 ;
int V_62 = 0 ;
V_101 = & V_2 -> V_26 ;
V_29 = V_2 -> V_29 ;
F_23 (chunk, chunk1, lqueue, transmitted_list) {
if ( F_39 ( V_36 ) ) {
F_6 ( & V_36 -> V_39 ) ;
F_35 ( & V_2 -> V_28 ,
& V_36 -> V_39 ) ;
continue;
}
if ( V_36 -> V_68 ) {
F_47 ( & V_36 -> V_39 ,
& V_15 -> V_38 ) ;
continue;
}
if ( V_29 && ! V_36 -> V_73 )
continue;
V_105:
V_102 = F_48 ( V_98 , V_36 ) ;
switch ( V_102 ) {
case V_106 :
if ( ! V_98 -> V_107 && ! V_98 -> V_108 ) {
F_49 ( V_98 ) ;
goto V_105;
}
error = F_49 ( V_98 ) ;
if ( V_99 || V_29 )
V_62 = 1 ;
else
goto V_105;
break;
case V_109 :
error = F_49 ( V_98 ) ;
V_62 = 1 ;
break;
case V_110 :
error = F_49 ( V_98 ) ;
V_62 = 1 ;
break;
default:
F_47 ( & V_36 -> V_39 ,
& V_15 -> V_38 ) ;
if ( V_36 -> V_73 == V_74 )
V_36 -> V_73 = V_111 ;
V_2 -> V_31 = 0 ;
V_2 -> V_24 -> V_112 . V_113 ++ ;
break;
}
if ( ! error && ! V_104 )
V_104 = 1 ;
if ( V_62 )
break;
}
if ( V_99 || V_29 ) {
F_18 (chunk1, lqueue, transmitted_list) {
if ( V_103 -> V_73 == V_74 )
V_103 -> V_73 = V_111 ;
}
}
* V_100 = V_104 ;
if ( V_29 )
V_2 -> V_29 = 0 ;
return error ;
}
int F_50 ( struct V_1 * V_2 )
{
int error = 0 ;
if ( V_2 -> V_32 )
V_2 -> V_32 = 0 ;
error = F_34 ( V_2 , 0 ) ;
return error ;
}
static int F_34 ( struct V_1 * V_2 , int V_99 )
{
struct V_97 * V_114 ;
struct V_97 V_115 ;
struct V_23 * V_24 = V_2 -> V_24 ;
T_5 V_116 = V_24 -> V_41 . V_117 . V_118 ;
T_5 V_119 = V_24 -> V_70 . V_118 ;
T_1 V_120 = V_24 -> V_70 . V_121 . V_122 ;
struct V_13 * V_15 = NULL ;
struct V_13 * V_123 ;
struct V_3 * V_36 , * V_37 ;
T_4 V_102 ;
int error = 0 ;
int V_100 = 0 ;
int V_124 = 0 ;
struct V_10 V_125 ;
struct V_10 * V_126 ;
F_16 ( & V_125 ) ;
V_114 = NULL ;
F_23 (chunk, tmp, &q->control_chunk_list, list) {
if ( V_24 -> V_127 &&
V_36 -> V_43 -> type != V_128 )
continue;
F_6 ( & V_36 -> V_5 ) ;
V_123 = V_36 -> V_15 ;
if ( ! V_123 ) {
if ( V_15 &&
F_51 ( & V_36 -> V_129 ,
& V_15 -> V_130 ) )
V_123 = V_15 ;
else
V_123 = F_52 ( V_24 ,
& V_36 -> V_129 ) ;
if ( ! V_123 )
V_123 = V_24 -> V_70 . V_131 ;
} else if ( ( V_123 -> V_44 == V_132 ) ||
( V_123 -> V_44 == V_133 ) ||
( V_123 -> V_44 == V_134 ) ) {
if ( V_36 -> V_43 -> type != V_135 &&
V_36 -> V_43 -> type != V_136 &&
V_36 -> V_43 -> type != V_137 )
V_123 = V_24 -> V_70 . V_131 ;
}
if ( V_123 != V_15 ) {
V_15 = V_123 ;
if ( F_4 ( & V_15 -> V_138 ) ) {
F_8 ( & V_15 -> V_138 ,
& V_125 ) ;
}
V_114 = & V_15 -> V_114 ;
F_53 ( V_114 , V_120 ,
V_24 -> V_70 . V_139 ) ;
}
switch ( V_36 -> V_43 -> type ) {
case V_140 :
case V_141 :
case V_142 :
F_54 ( & V_115 , V_15 , V_116 , V_119 ) ;
F_53 ( & V_115 , V_120 , 0 ) ;
F_48 ( & V_115 , V_36 ) ;
error = F_49 ( & V_115 ) ;
if ( error < 0 )
return error ;
break;
case V_143 :
if ( F_55 ( V_36 ) ) {
V_114 -> V_120 = V_24 -> V_144 . V_145 ;
}
case V_136 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_137 :
V_124 = 1 ;
case V_151 :
case V_135 :
case V_152 :
case V_153 :
case V_128 :
case V_154 :
V_102 = F_56 ( V_114 , V_36 ,
V_124 ) ;
if ( V_102 != V_155 ) {
F_2 ( & V_36 -> V_5 , & V_2 -> V_25 ) ;
} else {
V_24 -> V_112 . V_156 ++ ;
if ( V_36 -> V_43 -> type == V_154 )
F_57 ( V_15 ) ;
}
break;
default:
F_44 () ;
}
}
if ( V_2 -> V_24 -> V_127 )
goto V_157;
switch ( V_24 -> V_44 ) {
case V_158 :
if ( ! V_114 || ! V_114 -> V_108 )
break;
case V_159 :
case V_46 :
case V_48 :
if ( ! F_4 ( & V_2 -> V_26 ) ) {
if ( V_24 -> V_70 . V_85 -> V_44 == V_133 )
goto V_157;
if ( V_15 == V_24 -> V_70 . V_85 )
goto V_160;
V_15 = V_24 -> V_70 . V_85 ;
if ( F_4 ( & V_15 -> V_138 ) ) {
F_8 ( & V_15 -> V_138 ,
& V_125 ) ;
}
V_114 = & V_15 -> V_114 ;
F_53 ( V_114 , V_120 ,
V_24 -> V_70 . V_139 ) ;
V_160:
error = F_46 ( V_2 , V_114 ,
V_99 , & V_100 ) ;
if ( V_100 )
F_57 ( V_15 ) ;
if ( V_114 -> V_108 )
goto V_157;
if ( ! F_4 ( & V_2 -> V_26 ) )
goto V_157;
}
if ( V_15 )
F_58 ( V_15 ) ;
while ( ( V_36 = F_3 ( V_2 ) ) != NULL ) {
if ( V_36 -> V_161 . V_162 >=
V_24 -> V_144 . V_163 ) {
F_20 ( V_36 , V_164 ) ;
F_21 ( V_36 ) ;
continue;
}
if ( F_39 ( V_36 ) ) {
F_20 ( V_36 , 0 ) ;
F_21 ( V_36 ) ;
continue;
}
V_123 = V_36 -> V_15 ;
if ( ! V_123 ||
( ( V_123 -> V_44 == V_132 ) ||
( V_123 -> V_44 == V_133 ) ||
( V_123 -> V_44 == V_134 ) ) )
V_123 = V_24 -> V_70 . V_131 ;
if ( V_123 -> V_44 == V_133 )
continue;
if ( V_123 != V_15 ) {
V_15 = V_123 ;
if ( F_4 ( & V_15 -> V_138 ) ) {
F_8 ( & V_15 -> V_138 ,
& V_125 ) ;
}
V_114 = & V_15 -> V_114 ;
F_53 ( V_114 , V_120 ,
V_24 -> V_70 . V_139 ) ;
F_58 ( V_15 ) ;
}
F_29 ( L_7 ,
V_2 , V_36 ,
V_36 && V_36 -> V_43 ?
F_30 ( F_31 (
V_36 -> V_43 -> type ) )
: L_2 ) ;
F_29 ( L_8
L_9 ,
F_36 ( V_36 -> V_63 . V_64 -> V_20 ) ,
V_36 -> V_8 ? V_36 -> V_8 -> V_56 : NULL ,
V_36 -> V_8 ?
F_59 ( & V_36 -> V_8 -> V_165 ) : - 1 ) ;
V_102 = F_56 ( V_114 , V_36 , 0 ) ;
switch ( V_102 ) {
case V_106 :
case V_109 :
case V_110 :
F_29 ( L_10
L_11 ,
F_36 ( V_36 -> V_63 . V_64 -> V_20 ) ,
V_102 ) ;
F_1 ( V_2 , V_36 ) ;
goto V_157;
break;
case V_155 :
if ( V_24 -> V_44 == V_46 )
V_36 -> V_43 -> V_51 |= V_166 ;
if ( V_36 -> V_43 -> V_51 & V_52 )
V_24 -> V_112 . V_167 ++ ;
else
V_24 -> V_112 . V_168 ++ ;
break;
default:
F_44 () ;
}
F_8 ( & V_36 -> V_39 ,
& V_15 -> V_38 ) ;
F_57 ( V_15 ) ;
V_2 -> V_31 = 0 ;
if ( V_114 -> V_108 )
goto V_157;
}
break;
default:
break;
}
V_157:
while ( ( V_126 = F_19 ( & V_125 ) ) != NULL ) {
struct V_13 * V_169 = F_5 ( V_126 ,
struct V_13 ,
V_138 ) ;
V_114 = & V_169 -> V_114 ;
if ( ! F_60 ( V_114 ) )
error = F_49 ( V_114 ) ;
F_61 ( V_169 ) ;
}
return error ;
}
static void F_62 ( struct V_23 * V_170 ,
struct V_171 * V_172 )
{
T_6 * V_173 ;
T_5 V_87 ;
int V_121 ;
V_87 = V_170 -> V_174 - V_170 -> V_95 - 1 ;
V_173 = V_172 -> V_175 ;
for ( V_121 = 0 ; V_121 < F_63 ( V_172 -> V_176 ) ; V_121 ++ ) {
V_87 -= ( ( F_63 ( V_173 [ V_121 ] . V_177 . V_178 ) -
F_63 ( V_173 [ V_121 ] . V_177 . V_179 ) + 1 ) ) ;
}
V_170 -> V_87 = V_87 ;
}
int F_64 ( struct V_1 * V_2 , struct V_3 * V_36 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_171 * V_172 = V_36 -> V_63 . V_180 ;
struct V_13 * V_15 ;
struct V_3 * V_181 = NULL ;
struct V_10 * V_34 , * V_125 , * V_35 ;
T_6 * V_173 = V_172 -> V_175 ;
T_1 V_182 , V_183 , V_20 ;
T_1 V_184 , V_185 ;
T_1 V_186 ;
unsigned int V_187 ;
struct V_13 * V_14 = V_24 -> V_70 . V_188 ;
int V_16 = 0 ;
int V_189 ;
T_7 V_190 = 0 ;
V_125 = & V_24 -> V_70 . V_191 ;
V_182 = F_36 ( V_172 -> V_192 ) ;
V_189 = F_63 ( V_172 -> V_176 ) ;
V_24 -> V_112 . V_193 += V_189 ;
if ( V_14 -> V_17 . V_22 ) {
T_7 V_194 = 0 ;
if ( F_65 ( V_14 -> V_17 . V_21 , V_182 ) ) {
V_14 -> V_17 . V_22 = 0 ;
V_194 = 1 ;
}
if ( V_194 || V_189 ) {
F_18 (transport, transport_list,
transports) {
if ( V_194 )
V_15 -> V_17 . V_19 = 0 ;
if ( V_189 )
V_15 -> V_17 . V_18 = 0 ;
}
}
}
V_184 = V_182 ;
if ( V_189 )
V_184 += F_63 ( V_173 [ V_189 - 1 ] . V_177 . V_178 ) ;
if ( F_13 ( V_24 -> V_195 , V_184 ) )
V_24 -> V_195 = V_184 ;
V_185 = V_182 ;
F_66 ( V_2 , & V_2 -> V_26 , NULL , NULL , V_172 , & V_185 ) ;
F_18 (transport, transport_list, transports) {
F_66 ( V_2 , & V_15 -> V_38 ,
V_15 , & V_36 -> V_196 , V_172 ,
& V_185 ) ;
if ( V_15 -> V_17 . V_18 )
V_16 ++ ;
}
if ( F_13 ( V_24 -> V_95 , V_182 ) ) {
V_24 -> V_95 = V_182 ;
V_190 = 1 ;
}
if ( V_189 ) {
if ( V_24 -> V_197 && V_190 )
V_185 = V_184 ;
F_18 (transport, transport_list, transports)
F_67 ( V_2 , & V_15 -> V_38 , V_15 ,
V_185 , V_16 ) ;
}
F_62 ( V_24 , V_172 ) ;
V_183 = V_24 -> V_95 ;
F_22 (lchunk, temp, &q->sacked) {
V_181 = F_5 ( V_34 , struct V_3 ,
V_39 ) ;
V_20 = F_36 ( V_181 -> V_63 . V_64 -> V_20 ) ;
if ( F_65 ( V_20 , V_183 ) ) {
F_6 ( & V_181 -> V_39 ) ;
F_21 ( V_181 ) ;
}
}
V_186 = F_36 ( V_172 -> V_198 ) ;
V_187 = V_2 -> V_30 ;
if ( V_187 < V_186 )
V_186 -= V_187 ;
else
V_186 = 0 ;
V_24 -> V_70 . V_71 = V_186 ;
F_45 ( V_2 , V_182 ) ;
F_29 ( L_12 ,
V_78 , V_182 ) ;
F_29 ( L_13
L_14 ,
V_78 , V_24 , V_183 , V_24 -> V_199 ) ;
V_2 -> V_31 = ( F_4 ( & V_2 -> V_6 ) &&
F_4 ( & V_2 -> V_26 ) ) ;
if ( ! V_2 -> V_31 )
goto V_200;
F_18 (transport, transport_list, transports) {
V_2 -> V_31 = V_2 -> V_31 && F_4 ( & V_15 -> V_38 ) ;
if ( ! V_2 -> V_31 )
goto V_200;
}
F_29 ( L_15 ) ;
V_200:
return V_2 -> V_31 ;
}
int F_68 ( const struct V_1 * V_2 )
{
return V_2 -> V_31 ;
}
static void F_66 ( struct V_1 * V_2 ,
struct V_10 * V_201 ,
struct V_13 * V_15 ,
union V_202 * V_203 ,
struct V_171 * V_172 ,
T_1 * V_204 )
{
struct V_10 * V_34 ;
struct V_3 * V_181 ;
struct V_10 V_205 ;
T_1 V_20 ;
T_1 V_182 ;
T_1 V_206 ;
T_2 V_207 = 0 ;
int V_208 = 0 ;
int V_209 = 0 ;
#if V_210
T_1 V_211 = 0 ;
T_1 V_212 = 0 ;
T_1 V_213 = 0 ;
T_1 V_214 = 0 ;
int V_215 = - 1 ;
#endif
V_182 = F_36 ( V_172 -> V_192 ) ;
F_16 ( & V_205 ) ;
while ( NULL != ( V_34 = F_19 ( V_201 ) ) ) {
V_181 = F_5 ( V_34 , struct V_3 ,
V_39 ) ;
if ( F_39 ( V_181 ) ) {
F_35 ( & V_2 -> V_28 , V_34 ) ;
if ( ! V_181 -> V_68 ) {
if ( V_181 -> V_15 )
V_181 -> V_15 -> V_69 -=
F_40 ( V_181 ) ;
V_2 -> V_30 -= F_40 ( V_181 ) ;
}
continue;
}
V_20 = F_36 ( V_181 -> V_63 . V_64 -> V_20 ) ;
if ( F_69 ( V_172 , V_20 ) ) {
if ( V_15 ) {
if ( ! V_181 -> V_68 &&
V_181 -> V_76 ) {
V_181 -> V_76 = 0 ;
V_206 = V_216 - V_181 -> V_217 ;
F_70 ( V_15 ,
V_206 ) ;
}
}
if ( ! V_181 -> V_68 ) {
V_181 -> V_68 = 1 ;
* V_204 = V_20 ;
V_208 += F_40 ( V_181 ) ;
if ( ! V_181 -> V_15 )
V_209 += F_40 ( V_181 ) ;
}
if ( F_65 ( V_20 , V_182 ) ) {
V_207 = 1 ;
if ( ! V_181 -> V_68 ) {
if ( V_15 &&
V_172 -> V_176 &&
V_2 -> V_24 -> V_70 . V_188 -> V_17 .
V_22 )
V_15 -> V_17 . V_18
= 1 ;
}
F_8 ( & V_181 -> V_39 ,
& V_2 -> V_27 ) ;
} else {
F_8 ( V_34 , & V_205 ) ;
}
#if V_210
switch ( V_215 ) {
case 0 :
if ( V_212 + 1 == V_20 ) {
break;
}
if ( V_212 != V_211 ) {
F_71 ( L_16 ,
V_212 ) ;
}
F_71 ( L_17 , V_20 ) ;
V_211 = V_20 ;
break;
case 1 :
if ( V_214 != V_213 ) {
F_71 ( L_16 ,
V_214 ) ;
}
F_71 ( L_18 ) ;
default:
F_29 ( L_19 , V_20 ) ;
V_215 = 0 ;
V_211 = V_20 ;
}
V_212 = V_20 ;
#endif
} else {
if ( V_181 -> V_68 ) {
F_29 ( L_20
L_21 ,
V_78 ,
V_20 ) ;
V_181 -> V_68 = 0 ;
if ( V_181 -> V_15 )
V_208 -= F_40 ( V_181 ) ;
V_207 = 1 ;
}
F_8 ( V_34 , & V_205 ) ;
#if V_210
switch ( V_215 ) {
case 1 :
if ( V_214 + 1 == V_20 )
break;
if ( V_214 != V_213 )
F_71 ( L_16 ,
V_214 ) ;
F_71 ( L_17 , V_20 ) ;
V_213 = V_20 ;
break;
case 0 :
if ( V_212 != V_211 )
F_71 ( L_16 ,
V_212 ) ;
F_71 ( L_18 ) ;
default:
F_29 ( L_22 , V_20 ) ;
V_215 = 1 ;
V_213 = V_20 ;
}
V_214 = V_20 ;
#endif
}
}
#if V_210
switch ( V_215 ) {
case 0 :
if ( V_212 != V_211 ) {
F_71 ( L_23 , V_212 ) ;
} else {
F_71 ( L_18 ) ;
}
break;
case 1 :
if ( V_214 != V_213 ) {
F_71 ( L_23 , V_214 ) ;
} else {
F_71 ( L_18 ) ;
}
}
#endif
if ( V_15 ) {
if ( V_208 ) {
struct V_23 * V_24 = V_15 -> V_24 ;
V_208 -= V_209 ;
V_15 -> V_218 = 0 ;
V_15 -> V_24 -> V_219 = 0 ;
if ( V_24 -> V_44 == V_46 &&
F_72 ( & V_24 -> V_220
[ V_221 ] ) )
F_73 ( V_24 ) ;
if ( ( V_15 -> V_44 == V_132 ||
V_15 -> V_44 == V_133 ) &&
F_51 ( & V_15 -> V_130 , V_203 ) ) {
F_74 (
V_15 -> V_24 ,
V_15 ,
V_222 ,
V_223 ) ;
}
F_75 ( V_15 , V_182 ,
V_208 ) ;
V_15 -> V_69 -= V_208 ;
if ( V_15 -> V_69 == 0 )
V_15 -> V_81 = 0 ;
V_2 -> V_30 -= V_208 + V_209 ;
} else {
if ( ! V_2 -> V_24 -> V_70 . V_71 &&
! F_4 ( & V_205 ) &&
( V_182 + 2 == V_2 -> V_24 -> V_174 ) &&
V_2 -> V_24 -> V_44 < V_46 ) {
F_29 ( L_24
L_25 ,
V_78 , V_182 ) ;
V_2 -> V_24 -> V_219 = 0 ;
V_15 -> V_218 = 0 ;
}
}
if ( ! V_15 -> V_69 ) {
if ( F_72 ( & V_15 -> V_224 ) )
F_76 ( V_15 ) ;
} else if ( V_207 ) {
if ( ! F_77 ( & V_15 -> V_224 ,
V_216 + V_15 -> V_225 ) )
F_78 ( V_15 ) ;
}
}
F_79 ( & V_205 , V_201 ) ;
}
static void F_67 ( struct V_1 * V_2 ,
struct V_10 * V_201 ,
struct V_13 * V_15 ,
T_1 V_204 ,
int V_16 )
{
struct V_3 * V_36 ;
T_1 V_20 ;
char V_226 = 0 ;
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_13 * V_14 = V_24 -> V_70 . V_188 ;
F_18 (chunk, transmitted_queue, transmitted_list) {
V_20 = F_36 ( V_36 -> V_63 . V_64 -> V_20 ) ;
if ( V_36 -> V_73 == V_227 &&
! V_36 -> V_68 &&
F_13 ( V_20 , V_204 ) ) {
if ( ! V_15 || ! F_14 ( V_14 ,
V_36 -> V_15 ,
V_16 , V_20 ) ) {
V_36 -> V_75 ++ ;
F_29 (
L_26 ,
V_78 , V_20 ,
V_36 -> V_75 ) ;
}
}
if ( V_36 -> V_75 >= 3 ) {
V_36 -> V_73 = V_74 ;
V_226 = 1 ;
}
}
if ( V_15 ) {
if ( V_226 )
F_41 ( V_2 , V_15 , V_72 ) ;
F_29 ( L_27
L_28 ,
V_78 , V_15 , V_15 -> V_79 ,
V_15 -> V_80 , V_15 -> V_69 ,
V_15 -> V_81 ) ;
}
}
static int F_69 ( struct V_171 * V_172 , T_1 V_20 )
{
int V_121 ;
T_6 * V_173 ;
T_5 V_228 ;
T_1 V_183 = F_36 ( V_172 -> V_192 ) ;
if ( F_65 ( V_20 , V_183 ) )
goto V_229;
V_173 = V_172 -> V_175 ;
V_228 = V_20 - V_183 ;
for ( V_121 = 0 ; V_121 < F_63 ( V_172 -> V_176 ) ; ++ V_121 ) {
if ( F_65 ( F_63 ( V_173 [ V_121 ] . V_177 . V_179 ) , V_228 ) &&
F_65 ( V_228 , F_63 ( V_173 [ V_121 ] . V_177 . V_178 ) ) )
goto V_229;
}
return 0 ;
V_229:
return 1 ;
}
static inline int F_80 ( struct V_230 * V_231 ,
int V_232 , T_8 V_233 )
{
int V_121 ;
for ( V_121 = 0 ; V_121 < V_232 ; V_121 ++ ) {
if ( V_231 [ V_121 ] . V_233 == V_233 )
return V_121 ;
}
return V_121 ;
}
static void F_45 ( struct V_1 * V_2 , T_1 V_183 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_3 * V_234 = NULL ;
struct V_230 V_235 [ 10 ] ;
int V_232 = 0 ;
int V_236 = 0 ;
T_1 V_20 ;
struct V_3 * V_36 ;
struct V_10 * V_34 , * V_35 ;
if ( ! V_24 -> V_70 . V_237 )
return;
if ( F_13 ( V_24 -> V_199 , V_183 ) )
V_24 -> V_199 = V_183 ;
F_22 (lchunk, temp, &q->abandoned) {
V_36 = F_5 ( V_34 , struct V_3 ,
V_39 ) ;
V_20 = F_36 ( V_36 -> V_63 . V_64 -> V_20 ) ;
if ( F_65 ( V_20 , V_183 ) ) {
F_6 ( V_34 ) ;
F_21 ( V_36 ) ;
} else {
if ( F_65 ( V_20 , V_24 -> V_199 + 1 ) ) {
V_24 -> V_199 = V_20 ;
if ( V_36 -> V_43 -> V_51 &
V_52 )
continue;
V_236 = F_80 ( & V_235 [ 0 ] ,
V_232 ,
V_36 -> V_63 . V_64 -> V_233 ) ;
V_235 [ V_236 ] . V_233 =
V_36 -> V_63 . V_64 -> V_233 ;
V_235 [ V_236 ] . V_238 =
V_36 -> V_63 . V_64 -> V_238 ;
if ( V_236 == V_232 )
V_232 ++ ;
if ( V_232 == 10 )
break;
} else
break;
}
}
if ( V_24 -> V_199 > V_183 )
V_234 = F_81 ( V_24 , V_24 -> V_199 ,
V_232 , & V_235 [ 0 ] ) ;
if ( V_234 ) {
F_8 ( & V_234 -> V_5 , & V_2 -> V_25 ) ;
F_33 ( F_28 ( V_24 -> V_41 . V_42 ) , V_55 ) ;
}
}
