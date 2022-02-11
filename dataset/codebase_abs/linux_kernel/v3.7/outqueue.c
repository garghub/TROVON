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
void F_17 ( struct V_1 * V_2 )
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
V_2 -> error = 0 ;
F_23 (chunk, tmp, &q->control_chunk_list, list) {
F_6 ( & V_36 -> V_5 ) ;
F_21 ( V_36 ) ;
}
}
void F_24 ( struct V_1 * V_2 )
{
F_17 ( V_2 ) ;
if ( V_2 -> V_33 )
F_25 ( V_2 ) ;
}
int F_26 ( struct V_1 * V_2 , struct V_3 * V_36 )
{
struct V_40 * V_40 = F_27 ( V_2 -> V_24 -> V_41 . V_42 ) ;
int error = 0 ;
F_28 ( L_1 ,
V_2 , V_36 , V_36 && V_36 -> V_43 ?
F_29 ( F_30 ( V_36 -> V_43 -> type ) )
: L_2 ) ;
if ( F_31 ( V_36 ) ) {
switch ( V_2 -> V_24 -> V_44 ) {
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
error = - V_50 ;
break;
default:
F_28 ( L_3 ,
V_2 , V_36 , V_36 && V_36 -> V_43 ?
F_29 ( F_30 ( V_36 -> V_43 -> type ) )
: L_2 ) ;
F_7 ( V_2 , V_36 ) ;
if ( V_36 -> V_43 -> V_51 & V_52 )
F_32 ( V_40 , V_53 ) ;
else
F_32 ( V_40 , V_54 ) ;
V_2 -> V_31 = 0 ;
break;
}
} else {
F_8 ( & V_36 -> V_5 , & V_2 -> V_25 ) ;
F_32 ( V_40 , V_55 ) ;
}
if ( error < 0 )
return error ;
if ( ! V_2 -> V_32 )
error = F_33 ( V_2 , 0 ) ;
return error ;
}
static void F_34 ( struct V_10 * V_56 , struct V_10 * V_57 )
{
struct V_10 * V_58 ;
struct V_3 * V_59 , * V_34 ;
T_1 V_60 , V_61 ;
int V_62 = 0 ;
V_59 = F_5 ( V_57 , struct V_3 , V_39 ) ;
V_60 = F_35 ( V_59 -> V_63 . V_64 -> V_20 ) ;
F_36 (pos, head) {
V_34 = F_5 ( V_58 , struct V_3 , V_39 ) ;
V_61 = F_35 ( V_34 -> V_63 . V_64 -> V_20 ) ;
if ( F_13 ( V_60 , V_61 ) ) {
F_2 ( V_57 , V_58 -> V_65 ) ;
V_62 = 1 ;
break;
}
}
if ( ! V_62 )
F_8 ( V_57 , V_56 ) ;
}
void F_37 ( struct V_1 * V_2 ,
struct V_13 * V_15 ,
T_2 V_66 )
{
struct V_10 * V_34 , * V_67 ;
struct V_3 * V_36 ;
F_22 (lchunk, ltemp, &transport->transmitted) {
V_36 = F_5 ( V_34 , struct V_3 ,
V_39 ) ;
if ( F_38 ( V_36 ) ) {
F_6 ( V_34 ) ;
F_34 ( & V_2 -> V_28 , V_34 ) ;
if ( ! V_36 -> V_68 ) {
if ( V_36 -> V_15 )
V_36 -> V_15 -> V_69 -=
F_39 ( V_36 ) ;
V_2 -> V_30 -= F_39 ( V_36 ) ;
V_2 -> V_24 -> V_70 . V_71 += F_39 ( V_36 ) ;
}
continue;
}
if ( ( V_66 == V_72 &&
( V_36 -> V_73 == V_74 ) ) ||
( V_66 != V_72 && ! V_36 -> V_68 ) ) {
V_2 -> V_24 -> V_70 . V_71 += F_39 ( V_36 ) ;
V_2 -> V_30 -= F_39 ( V_36 ) ;
if ( V_36 -> V_15 )
V_15 -> V_69 -= F_39 ( V_36 ) ;
V_36 -> V_75 = 0 ;
if ( V_36 -> V_76 ) {
V_36 -> V_76 = 0 ;
V_15 -> V_77 = 0 ;
}
F_6 ( V_34 ) ;
F_34 ( & V_2 -> V_26 , V_34 ) ;
}
}
F_28 ( L_4
L_5
L_6 , V_78 ,
V_15 , V_66 ,
V_15 -> V_79 , V_15 -> V_80 ,
V_15 -> V_69 ,
V_15 -> V_81 ) ;
}
void F_40 ( struct V_1 * V_2 , struct V_13 * V_15 ,
T_3 V_66 )
{
struct V_40 * V_40 = F_27 ( V_2 -> V_24 -> V_41 . V_42 ) ;
int error = 0 ;
switch( V_66 ) {
case V_82 :
F_32 ( V_40 , V_83 ) ;
F_41 ( V_15 , V_84 ) ;
if ( V_15 == V_15 -> V_24 -> V_70 . V_85 )
F_42 ( V_15 -> V_24 ) ;
V_15 -> V_24 -> V_86 +=
V_15 -> V_24 -> V_87 ;
break;
case V_72 :
F_32 ( V_40 , V_88 ) ;
F_41 ( V_15 , V_89 ) ;
V_2 -> V_29 = 1 ;
break;
case V_90 :
F_32 ( V_40 , V_91 ) ;
break;
case V_92 :
F_32 ( V_40 , V_93 ) ;
V_15 -> V_24 -> V_94 ++ ;
break;
default:
F_43 () ;
}
F_37 ( V_2 , V_15 , V_66 ) ;
if ( V_66 == V_82 )
F_44 ( V_2 , V_2 -> V_24 -> V_95 ) ;
if ( V_66 != V_72 )
error = F_33 ( V_2 , 1 ) ;
if ( error )
V_2 -> V_24 -> V_41 . V_42 -> V_96 = - error ;
}
static int F_45 ( struct V_1 * V_2 , struct V_97 * V_98 ,
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
if ( F_38 ( V_36 ) ) {
F_6 ( & V_36 -> V_39 ) ;
F_34 ( & V_2 -> V_28 ,
& V_36 -> V_39 ) ;
continue;
}
if ( V_36 -> V_68 ) {
F_46 ( & V_36 -> V_39 ,
& V_15 -> V_38 ) ;
continue;
}
if ( V_29 && ! V_36 -> V_73 )
continue;
V_105:
V_102 = F_47 ( V_98 , V_36 ) ;
switch ( V_102 ) {
case V_106 :
if ( ! V_98 -> V_107 && ! V_98 -> V_108 ) {
F_48 ( V_98 ) ;
goto V_105;
}
error = F_48 ( V_98 ) ;
if ( V_99 || V_29 )
V_62 = 1 ;
else
goto V_105;
break;
case V_109 :
error = F_48 ( V_98 ) ;
V_62 = 1 ;
break;
case V_110 :
error = F_48 ( V_98 ) ;
V_62 = 1 ;
break;
default:
F_46 ( & V_36 -> V_39 ,
& V_15 -> V_38 ) ;
if ( V_36 -> V_73 == V_74 )
V_36 -> V_73 = V_111 ;
V_2 -> V_31 = 0 ;
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
int F_49 ( struct V_1 * V_2 )
{
int error = 0 ;
if ( V_2 -> V_32 )
V_2 -> V_32 = 0 ;
error = F_33 ( V_2 , 0 ) ;
return error ;
}
static int F_33 ( struct V_1 * V_2 , int V_99 )
{
struct V_97 * V_112 ;
struct V_97 V_113 ;
struct V_23 * V_24 = V_2 -> V_24 ;
T_5 V_114 = V_24 -> V_41 . V_115 . V_116 ;
T_5 V_117 = V_24 -> V_70 . V_116 ;
T_1 V_118 = V_24 -> V_70 . V_119 . V_120 ;
struct V_13 * V_15 = NULL ;
struct V_13 * V_121 ;
struct V_3 * V_36 , * V_37 ;
T_4 V_102 ;
int error = 0 ;
int V_100 = 0 ;
int V_122 = 0 ;
struct V_10 V_123 ;
struct V_10 * V_124 ;
F_16 ( & V_123 ) ;
V_112 = NULL ;
F_23 (chunk, tmp, &q->control_chunk_list, list) {
if ( V_24 -> V_125 &&
V_36 -> V_43 -> type != V_126 )
continue;
F_6 ( & V_36 -> V_5 ) ;
V_121 = V_36 -> V_15 ;
if ( ! V_121 ) {
if ( V_15 &&
F_50 ( & V_36 -> V_127 ,
& V_15 -> V_128 ) )
V_121 = V_15 ;
else
V_121 = F_51 ( V_24 ,
& V_36 -> V_127 ) ;
if ( ! V_121 )
V_121 = V_24 -> V_70 . V_129 ;
} else if ( ( V_121 -> V_44 == V_130 ) ||
( V_121 -> V_44 == V_131 ) ||
( V_121 -> V_44 == V_132 ) ) {
if ( V_36 -> V_43 -> type != V_133 &&
V_36 -> V_43 -> type != V_134 &&
V_36 -> V_43 -> type != V_135 )
V_121 = V_24 -> V_70 . V_129 ;
}
if ( V_121 != V_15 ) {
V_15 = V_121 ;
if ( F_4 ( & V_15 -> V_136 ) ) {
F_8 ( & V_15 -> V_136 ,
& V_123 ) ;
}
V_112 = & V_15 -> V_112 ;
F_52 ( V_112 , V_118 ,
V_24 -> V_70 . V_137 ) ;
}
switch ( V_36 -> V_43 -> type ) {
case V_138 :
case V_139 :
case V_140 :
F_53 ( & V_113 , V_15 , V_114 , V_117 ) ;
F_52 ( & V_113 , V_118 , 0 ) ;
F_47 ( & V_113 , V_36 ) ;
error = F_48 ( & V_113 ) ;
if ( error < 0 )
return error ;
break;
case V_141 :
if ( F_54 ( V_36 ) ) {
V_112 -> V_118 = V_24 -> V_142 . V_143 ;
}
case V_134 :
case V_144 :
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_135 :
V_122 = 1 ;
case V_149 :
case V_133 :
case V_150 :
case V_151 :
case V_126 :
case V_152 :
V_102 = F_55 ( V_112 , V_36 ,
V_122 ) ;
if ( V_102 != V_153 ) {
F_2 ( & V_36 -> V_5 , & V_2 -> V_25 ) ;
} else if ( V_36 -> V_43 -> type == V_152 ) {
F_56 ( V_15 ) ;
}
break;
default:
F_43 () ;
}
}
if ( V_2 -> V_24 -> V_125 )
goto V_154;
switch ( V_24 -> V_44 ) {
case V_155 :
if ( ! V_112 || ! V_112 -> V_108 )
break;
case V_156 :
case V_46 :
case V_48 :
if ( ! F_4 ( & V_2 -> V_26 ) ) {
if ( V_24 -> V_70 . V_85 -> V_44 == V_131 )
goto V_154;
if ( V_15 == V_24 -> V_70 . V_85 )
goto V_157;
V_15 = V_24 -> V_70 . V_85 ;
if ( F_4 ( & V_15 -> V_136 ) ) {
F_8 ( & V_15 -> V_136 ,
& V_123 ) ;
}
V_112 = & V_15 -> V_112 ;
F_52 ( V_112 , V_118 ,
V_24 -> V_70 . V_137 ) ;
V_157:
error = F_45 ( V_2 , V_112 ,
V_99 , & V_100 ) ;
if ( V_100 )
F_56 ( V_15 ) ;
if ( V_112 -> V_108 )
goto V_154;
if ( ! F_4 ( & V_2 -> V_26 ) )
goto V_154;
}
if ( V_15 )
F_57 ( V_15 ) ;
while ( ( V_36 = F_3 ( V_2 ) ) != NULL ) {
if ( V_36 -> V_158 . V_159 >=
V_24 -> V_142 . V_160 ) {
F_20 ( V_36 , V_161 ) ;
F_21 ( V_36 ) ;
continue;
}
if ( F_38 ( V_36 ) ) {
F_20 ( V_36 , 0 ) ;
F_21 ( V_36 ) ;
continue;
}
V_121 = V_36 -> V_15 ;
if ( ! V_121 ||
( ( V_121 -> V_44 == V_130 ) ||
( V_121 -> V_44 == V_131 ) ||
( V_121 -> V_44 == V_132 ) ) )
V_121 = V_24 -> V_70 . V_129 ;
if ( V_121 -> V_44 == V_131 )
continue;
if ( V_121 != V_15 ) {
V_15 = V_121 ;
if ( F_4 ( & V_15 -> V_136 ) ) {
F_8 ( & V_15 -> V_136 ,
& V_123 ) ;
}
V_112 = & V_15 -> V_112 ;
F_52 ( V_112 , V_118 ,
V_24 -> V_70 . V_137 ) ;
F_57 ( V_15 ) ;
}
F_28 ( L_7 ,
V_2 , V_36 ,
V_36 && V_36 -> V_43 ?
F_29 ( F_30 (
V_36 -> V_43 -> type ) )
: L_2 ) ;
F_28 ( L_8
L_9 ,
F_35 ( V_36 -> V_63 . V_64 -> V_20 ) ,
V_36 -> V_8 ? V_36 -> V_8 -> V_56 : NULL ,
V_36 -> V_8 ?
F_58 ( & V_36 -> V_8 -> V_162 ) : - 1 ) ;
V_102 = F_55 ( V_112 , V_36 , 0 ) ;
switch ( V_102 ) {
case V_106 :
case V_109 :
case V_110 :
F_28 ( L_10
L_11 ,
F_35 ( V_36 -> V_63 . V_64 -> V_20 ) ,
V_102 ) ;
F_1 ( V_2 , V_36 ) ;
goto V_154;
break;
case V_153 :
if ( V_24 -> V_44 == V_46 )
V_36 -> V_43 -> V_51 |= V_163 ;
break;
default:
F_43 () ;
}
F_8 ( & V_36 -> V_39 ,
& V_15 -> V_38 ) ;
F_56 ( V_15 ) ;
V_2 -> V_31 = 0 ;
if ( V_112 -> V_108 )
goto V_154;
}
break;
default:
break;
}
V_154:
while ( ( V_124 = F_19 ( & V_123 ) ) != NULL ) {
struct V_13 * V_164 = F_5 ( V_124 ,
struct V_13 ,
V_136 ) ;
V_112 = & V_164 -> V_112 ;
if ( ! F_59 ( V_112 ) )
error = F_48 ( V_112 ) ;
F_60 ( V_164 ) ;
}
return error ;
}
static void F_61 ( struct V_23 * V_165 ,
struct V_166 * V_167 )
{
T_6 * V_168 ;
T_5 V_87 ;
int V_119 ;
V_87 = V_165 -> V_169 - V_165 -> V_95 - 1 ;
V_168 = V_167 -> V_170 ;
for ( V_119 = 0 ; V_119 < F_62 ( V_167 -> V_171 ) ; V_119 ++ ) {
V_87 -= ( ( F_62 ( V_168 [ V_119 ] . V_172 . V_173 ) -
F_62 ( V_168 [ V_119 ] . V_172 . V_174 ) + 1 ) ) ;
}
V_165 -> V_87 = V_87 ;
}
int F_63 ( struct V_1 * V_2 , struct V_3 * V_36 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_166 * V_167 = V_36 -> V_63 . V_175 ;
struct V_13 * V_15 ;
struct V_3 * V_176 = NULL ;
struct V_10 * V_34 , * V_123 , * V_35 ;
T_6 * V_168 = V_167 -> V_170 ;
T_1 V_177 , V_178 , V_20 ;
T_1 V_179 , V_180 ;
T_1 V_181 ;
unsigned int V_182 ;
struct V_13 * V_14 = V_24 -> V_70 . V_183 ;
int V_16 = 0 ;
int V_184 ;
T_7 V_185 = 0 ;
V_123 = & V_24 -> V_70 . V_186 ;
V_177 = F_35 ( V_167 -> V_187 ) ;
V_184 = F_62 ( V_167 -> V_171 ) ;
if ( V_14 -> V_17 . V_22 ) {
T_7 V_188 = 0 ;
if ( F_64 ( V_14 -> V_17 . V_21 , V_177 ) ) {
V_14 -> V_17 . V_22 = 0 ;
V_188 = 1 ;
}
if ( V_188 || V_184 ) {
F_18 (transport, transport_list,
transports) {
if ( V_188 )
V_15 -> V_17 . V_19 = 0 ;
if ( V_184 )
V_15 -> V_17 . V_18 = 0 ;
}
}
}
V_179 = V_177 ;
if ( V_184 )
V_179 += F_62 ( V_168 [ V_184 - 1 ] . V_172 . V_173 ) ;
if ( F_13 ( V_24 -> V_189 , V_179 ) )
V_24 -> V_189 = V_179 ;
V_180 = V_177 ;
F_65 ( V_2 , & V_2 -> V_26 , NULL , NULL , V_167 , & V_180 ) ;
F_18 (transport, transport_list, transports) {
F_65 ( V_2 , & V_15 -> V_38 ,
V_15 , & V_36 -> V_190 , V_167 ,
& V_180 ) ;
if ( V_15 -> V_17 . V_18 )
V_16 ++ ;
}
if ( F_13 ( V_24 -> V_95 , V_177 ) ) {
V_24 -> V_95 = V_177 ;
V_185 = 1 ;
}
if ( V_184 ) {
if ( V_24 -> V_191 && V_185 )
V_180 = V_179 ;
F_18 (transport, transport_list, transports)
F_66 ( V_2 , & V_15 -> V_38 , V_15 ,
V_180 , V_16 ) ;
}
F_61 ( V_24 , V_167 ) ;
V_178 = V_24 -> V_95 ;
F_22 (lchunk, temp, &q->sacked) {
V_176 = F_5 ( V_34 , struct V_3 ,
V_39 ) ;
V_20 = F_35 ( V_176 -> V_63 . V_64 -> V_20 ) ;
if ( F_64 ( V_20 , V_178 ) ) {
F_6 ( & V_176 -> V_39 ) ;
F_21 ( V_176 ) ;
}
}
V_181 = F_35 ( V_167 -> V_192 ) ;
V_182 = V_2 -> V_30 ;
if ( V_182 < V_181 )
V_181 -= V_182 ;
else
V_181 = 0 ;
V_24 -> V_70 . V_71 = V_181 ;
F_44 ( V_2 , V_177 ) ;
F_28 ( L_12 ,
V_78 , V_177 ) ;
F_28 ( L_13
L_14 ,
V_78 , V_24 , V_178 , V_24 -> V_193 ) ;
V_2 -> V_31 = ( F_4 ( & V_2 -> V_6 ) &&
F_4 ( & V_2 -> V_26 ) ) ;
if ( ! V_2 -> V_31 )
goto V_194;
F_18 (transport, transport_list, transports) {
V_2 -> V_31 = V_2 -> V_31 && F_4 ( & V_15 -> V_38 ) ;
if ( ! V_2 -> V_31 )
goto V_194;
}
F_28 ( L_15 ) ;
V_194:
return V_2 -> V_31 ;
}
int F_67 ( const struct V_1 * V_2 )
{
return V_2 -> V_31 ;
}
static void F_65 ( struct V_1 * V_2 ,
struct V_10 * V_195 ,
struct V_13 * V_15 ,
union V_196 * V_197 ,
struct V_166 * V_167 ,
T_1 * V_198 )
{
struct V_10 * V_34 ;
struct V_3 * V_176 ;
struct V_10 V_199 ;
T_1 V_20 ;
T_1 V_177 ;
T_1 V_200 ;
T_2 V_201 = 0 ;
int V_202 = 0 ;
int V_203 = 0 ;
#if V_204
T_1 V_205 = 0 ;
T_1 V_206 = 0 ;
T_1 V_207 = 0 ;
T_1 V_208 = 0 ;
int V_209 = - 1 ;
#endif
V_177 = F_35 ( V_167 -> V_187 ) ;
F_16 ( & V_199 ) ;
while ( NULL != ( V_34 = F_19 ( V_195 ) ) ) {
V_176 = F_5 ( V_34 , struct V_3 ,
V_39 ) ;
if ( F_38 ( V_176 ) ) {
F_34 ( & V_2 -> V_28 , V_34 ) ;
if ( ! V_176 -> V_68 ) {
if ( V_176 -> V_15 )
V_176 -> V_15 -> V_69 -=
F_39 ( V_176 ) ;
V_2 -> V_30 -= F_39 ( V_176 ) ;
}
continue;
}
V_20 = F_35 ( V_176 -> V_63 . V_64 -> V_20 ) ;
if ( F_68 ( V_167 , V_20 ) ) {
if ( V_15 ) {
if ( ! V_176 -> V_68 &&
V_176 -> V_76 ) {
V_176 -> V_76 = 0 ;
V_200 = V_210 - V_176 -> V_211 ;
F_69 ( V_15 ,
V_200 ) ;
}
}
if ( ! V_176 -> V_68 ) {
V_176 -> V_68 = 1 ;
* V_198 = V_20 ;
V_202 += F_39 ( V_176 ) ;
if ( ! V_176 -> V_15 )
V_203 += F_39 ( V_176 ) ;
}
if ( F_64 ( V_20 , V_177 ) ) {
V_201 = 1 ;
if ( ! V_176 -> V_68 ) {
if ( V_15 &&
V_167 -> V_171 &&
V_2 -> V_24 -> V_70 . V_183 -> V_17 .
V_22 )
V_15 -> V_17 . V_18
= 1 ;
}
F_8 ( & V_176 -> V_39 ,
& V_2 -> V_27 ) ;
} else {
F_8 ( V_34 , & V_199 ) ;
}
#if V_204
switch ( V_209 ) {
case 0 :
if ( V_206 + 1 == V_20 ) {
break;
}
if ( V_206 != V_205 ) {
F_70 ( L_16 ,
V_206 ) ;
}
F_70 ( L_17 , V_20 ) ;
V_205 = V_20 ;
break;
case 1 :
if ( V_208 != V_207 ) {
F_70 ( L_16 ,
V_208 ) ;
}
F_70 ( L_18 ) ;
default:
F_28 ( L_19 , V_20 ) ;
V_209 = 0 ;
V_205 = V_20 ;
}
V_206 = V_20 ;
#endif
} else {
if ( V_176 -> V_68 ) {
F_28 ( L_20
L_21 ,
V_78 ,
V_20 ) ;
V_176 -> V_68 = 0 ;
if ( V_176 -> V_15 )
V_202 -= F_39 ( V_176 ) ;
V_201 = 1 ;
}
F_8 ( V_34 , & V_199 ) ;
#if V_204
switch ( V_209 ) {
case 1 :
if ( V_208 + 1 == V_20 )
break;
if ( V_208 != V_207 )
F_70 ( L_16 ,
V_208 ) ;
F_70 ( L_17 , V_20 ) ;
V_207 = V_20 ;
break;
case 0 :
if ( V_206 != V_205 )
F_70 ( L_16 ,
V_206 ) ;
F_70 ( L_18 ) ;
default:
F_28 ( L_22 , V_20 ) ;
V_209 = 1 ;
V_207 = V_20 ;
}
V_208 = V_20 ;
#endif
}
}
#if V_204
switch ( V_209 ) {
case 0 :
if ( V_206 != V_205 ) {
F_70 ( L_23 , V_206 ) ;
} else {
F_70 ( L_18 ) ;
}
break;
case 1 :
if ( V_208 != V_207 ) {
F_70 ( L_23 , V_208 ) ;
} else {
F_70 ( L_18 ) ;
}
}
#endif
if ( V_15 ) {
if ( V_202 ) {
struct V_23 * V_24 = V_15 -> V_24 ;
V_202 -= V_203 ;
V_15 -> V_212 = 0 ;
V_15 -> V_24 -> V_213 = 0 ;
if ( V_24 -> V_44 == V_46 &&
F_71 ( & V_24 -> V_214
[ V_215 ] ) )
F_72 ( V_24 ) ;
if ( ( V_15 -> V_44 == V_130 ||
V_15 -> V_44 == V_131 ) &&
F_50 ( & V_15 -> V_128 , V_197 ) ) {
F_73 (
V_15 -> V_24 ,
V_15 ,
V_216 ,
V_217 ) ;
}
F_74 ( V_15 , V_177 ,
V_202 ) ;
V_15 -> V_69 -= V_202 ;
if ( V_15 -> V_69 == 0 )
V_15 -> V_81 = 0 ;
V_2 -> V_30 -= V_202 + V_203 ;
} else {
if ( ! V_2 -> V_24 -> V_70 . V_71 &&
! F_4 ( & V_199 ) &&
( V_177 + 2 == V_2 -> V_24 -> V_169 ) &&
V_2 -> V_24 -> V_44 < V_46 ) {
F_28 ( L_24
L_25 ,
V_78 , V_177 ) ;
V_2 -> V_24 -> V_213 = 0 ;
V_15 -> V_212 = 0 ;
}
}
if ( ! V_15 -> V_69 ) {
if ( F_75 ( & V_15 -> V_218 ) &&
F_71 ( & V_15 -> V_218 ) ) {
F_76 ( V_15 ) ;
}
} else if ( V_201 ) {
if ( ! F_77 ( & V_15 -> V_218 ,
V_210 + V_15 -> V_219 ) )
F_78 ( V_15 ) ;
}
}
F_79 ( & V_199 , V_195 ) ;
}
static void F_66 ( struct V_1 * V_2 ,
struct V_10 * V_195 ,
struct V_13 * V_15 ,
T_1 V_198 ,
int V_16 )
{
struct V_3 * V_36 ;
T_1 V_20 ;
char V_220 = 0 ;
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_13 * V_14 = V_24 -> V_70 . V_183 ;
F_18 (chunk, transmitted_queue, transmitted_list) {
V_20 = F_35 ( V_36 -> V_63 . V_64 -> V_20 ) ;
if ( V_36 -> V_73 == V_221 &&
! V_36 -> V_68 &&
F_13 ( V_20 , V_198 ) ) {
if ( ! V_15 || ! F_14 ( V_14 ,
V_36 -> V_15 ,
V_16 , V_20 ) ) {
V_36 -> V_75 ++ ;
F_28 (
L_26 ,
V_78 , V_20 ,
V_36 -> V_75 ) ;
}
}
if ( V_36 -> V_75 >= 3 ) {
V_36 -> V_73 = V_74 ;
V_220 = 1 ;
}
}
if ( V_15 ) {
if ( V_220 )
F_40 ( V_2 , V_15 , V_72 ) ;
F_28 ( L_27
L_28 ,
V_78 , V_15 , V_15 -> V_79 ,
V_15 -> V_80 , V_15 -> V_69 ,
V_15 -> V_81 ) ;
}
}
static int F_68 ( struct V_166 * V_167 , T_1 V_20 )
{
int V_119 ;
T_6 * V_168 ;
T_5 V_222 ;
T_1 V_178 = F_35 ( V_167 -> V_187 ) ;
if ( F_64 ( V_20 , V_178 ) )
goto V_223;
V_168 = V_167 -> V_170 ;
V_222 = V_20 - V_178 ;
for ( V_119 = 0 ; V_119 < F_62 ( V_167 -> V_171 ) ; ++ V_119 ) {
if ( F_64 ( F_62 ( V_168 [ V_119 ] . V_172 . V_174 ) , V_222 ) &&
F_64 ( V_222 , F_62 ( V_168 [ V_119 ] . V_172 . V_173 ) ) )
goto V_223;
}
return 0 ;
V_223:
return 1 ;
}
static inline int F_80 ( struct V_224 * V_225 ,
int V_226 , T_8 V_227 )
{
int V_119 ;
for ( V_119 = 0 ; V_119 < V_226 ; V_119 ++ ) {
if ( V_225 [ V_119 ] . V_227 == V_227 )
return V_119 ;
}
return V_119 ;
}
static void F_44 ( struct V_1 * V_2 , T_1 V_178 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_3 * V_228 = NULL ;
struct V_224 V_229 [ 10 ] ;
int V_226 = 0 ;
int V_230 = 0 ;
T_1 V_20 ;
struct V_3 * V_36 ;
struct V_10 * V_34 , * V_35 ;
if ( ! V_24 -> V_70 . V_231 )
return;
if ( F_13 ( V_24 -> V_193 , V_178 ) )
V_24 -> V_193 = V_178 ;
F_22 (lchunk, temp, &q->abandoned) {
V_36 = F_5 ( V_34 , struct V_3 ,
V_39 ) ;
V_20 = F_35 ( V_36 -> V_63 . V_64 -> V_20 ) ;
if ( F_64 ( V_20 , V_178 ) ) {
F_6 ( V_34 ) ;
F_21 ( V_36 ) ;
} else {
if ( F_64 ( V_20 , V_24 -> V_193 + 1 ) ) {
V_24 -> V_193 = V_20 ;
if ( V_36 -> V_43 -> V_51 &
V_52 )
continue;
V_230 = F_80 ( & V_229 [ 0 ] ,
V_226 ,
V_36 -> V_63 . V_64 -> V_227 ) ;
V_229 [ V_230 ] . V_227 =
V_36 -> V_63 . V_64 -> V_227 ;
V_229 [ V_230 ] . V_232 =
V_36 -> V_63 . V_64 -> V_232 ;
if ( V_230 == V_226 )
V_226 ++ ;
if ( V_226 == 10 )
break;
} else
break;
}
}
if ( V_24 -> V_193 > V_178 )
V_228 = F_81 ( V_24 , V_24 -> V_193 ,
V_226 , & V_229 [ 0 ] ) ;
if ( V_228 ) {
F_8 ( & V_228 -> V_5 , & V_2 -> V_25 ) ;
F_32 ( F_27 ( V_24 -> V_41 . V_42 ) , V_55 ) ;
}
}
