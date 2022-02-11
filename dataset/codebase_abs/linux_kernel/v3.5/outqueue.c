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
int error = 0 ;
F_27 ( L_1 ,
V_2 , V_36 , V_36 && V_36 -> V_40 ?
F_28 ( F_29 ( V_36 -> V_40 -> type ) )
: L_2 ) ;
if ( F_30 ( V_36 ) ) {
switch ( V_2 -> V_24 -> V_41 ) {
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
error = - V_47 ;
break;
default:
F_27 ( L_3 ,
V_2 , V_36 , V_36 && V_36 -> V_40 ?
F_28 ( F_29 ( V_36 -> V_40 -> type ) )
: L_2 ) ;
F_7 ( V_2 , V_36 ) ;
if ( V_36 -> V_40 -> V_48 & V_49 )
F_31 ( V_50 ) ;
else
F_31 ( V_51 ) ;
V_2 -> V_31 = 0 ;
break;
}
} else {
F_8 ( & V_36 -> V_5 , & V_2 -> V_25 ) ;
F_31 ( V_52 ) ;
}
if ( error < 0 )
return error ;
if ( ! V_2 -> V_32 )
error = F_32 ( V_2 , 0 ) ;
return error ;
}
static void F_33 ( struct V_10 * V_53 , struct V_10 * V_54 )
{
struct V_10 * V_55 ;
struct V_3 * V_56 , * V_34 ;
T_1 V_57 , V_58 ;
int V_59 = 0 ;
V_56 = F_5 ( V_54 , struct V_3 , V_39 ) ;
V_57 = F_34 ( V_56 -> V_60 . V_61 -> V_20 ) ;
F_35 (pos, head) {
V_34 = F_5 ( V_55 , struct V_3 , V_39 ) ;
V_58 = F_34 ( V_34 -> V_60 . V_61 -> V_20 ) ;
if ( F_13 ( V_57 , V_58 ) ) {
F_2 ( V_54 , V_55 -> V_62 ) ;
V_59 = 1 ;
break;
}
}
if ( ! V_59 )
F_8 ( V_54 , V_53 ) ;
}
void F_36 ( struct V_1 * V_2 ,
struct V_13 * V_15 ,
T_2 V_63 )
{
struct V_10 * V_34 , * V_64 ;
struct V_3 * V_36 ;
F_22 (lchunk, ltemp, &transport->transmitted) {
V_36 = F_5 ( V_34 , struct V_3 ,
V_39 ) ;
if ( F_37 ( V_36 ) ) {
F_6 ( V_34 ) ;
F_33 ( & V_2 -> V_28 , V_34 ) ;
if ( ! V_36 -> V_65 ) {
if ( V_36 -> V_15 )
V_36 -> V_15 -> V_66 -=
F_38 ( V_36 ) ;
V_2 -> V_30 -= F_38 ( V_36 ) ;
V_2 -> V_24 -> V_67 . V_68 += F_38 ( V_36 ) ;
}
continue;
}
if ( ( V_63 == V_69 &&
( V_36 -> V_70 == V_71 ) ) ||
( V_63 != V_69 && ! V_36 -> V_65 ) ) {
V_2 -> V_24 -> V_67 . V_68 += F_38 ( V_36 ) ;
V_2 -> V_30 -= F_38 ( V_36 ) ;
if ( V_36 -> V_15 )
V_15 -> V_66 -= F_38 ( V_36 ) ;
V_36 -> V_72 = 0 ;
if ( V_36 -> V_73 ) {
V_36 -> V_73 = 0 ;
V_15 -> V_74 = 0 ;
}
F_6 ( V_34 ) ;
F_33 ( & V_2 -> V_26 , V_34 ) ;
}
}
F_27 ( L_4
L_5
L_6 , V_75 ,
V_15 , V_63 ,
V_15 -> V_76 , V_15 -> V_77 ,
V_15 -> V_66 ,
V_15 -> V_78 ) ;
}
void F_39 ( struct V_1 * V_2 , struct V_13 * V_15 ,
T_3 V_63 )
{
int error = 0 ;
switch( V_63 ) {
case V_79 :
F_31 ( V_80 ) ;
F_40 ( V_15 , V_81 ) ;
if ( V_15 == V_15 -> V_24 -> V_67 . V_82 )
F_41 ( V_15 -> V_24 ) ;
V_15 -> V_24 -> V_83 +=
V_15 -> V_24 -> V_84 ;
break;
case V_69 :
F_31 ( V_85 ) ;
F_40 ( V_15 , V_86 ) ;
V_2 -> V_29 = 1 ;
break;
case V_87 :
F_31 ( V_88 ) ;
break;
case V_89 :
F_31 ( V_90 ) ;
V_15 -> V_24 -> V_91 ++ ;
break;
default:
F_42 () ;
}
F_36 ( V_2 , V_15 , V_63 ) ;
if ( V_63 == V_79 )
F_43 ( V_2 , V_2 -> V_24 -> V_92 ) ;
if ( V_63 != V_69 )
error = F_32 ( V_2 , 1 ) ;
if ( error )
V_2 -> V_24 -> V_93 . V_94 -> V_95 = - error ;
}
static int F_44 ( struct V_1 * V_2 , struct V_96 * V_97 ,
int V_98 , int * V_99 )
{
struct V_10 * V_100 ;
struct V_13 * V_15 = V_97 -> V_15 ;
T_4 V_101 ;
struct V_3 * V_36 , * V_102 ;
int V_29 ;
int error = 0 ;
int V_103 = 0 ;
int V_59 = 0 ;
V_100 = & V_2 -> V_26 ;
V_29 = V_2 -> V_29 ;
F_23 (chunk, chunk1, lqueue, transmitted_list) {
if ( F_37 ( V_36 ) ) {
F_6 ( & V_36 -> V_39 ) ;
F_33 ( & V_2 -> V_28 ,
& V_36 -> V_39 ) ;
continue;
}
if ( V_36 -> V_65 ) {
F_45 ( & V_36 -> V_39 ) ;
F_8 ( & V_36 -> V_39 ,
& V_15 -> V_38 ) ;
continue;
}
if ( V_29 && ! V_36 -> V_70 )
continue;
V_104:
V_101 = F_46 ( V_97 , V_36 ) ;
switch ( V_101 ) {
case V_105 :
if ( ! V_97 -> V_106 && ! V_97 -> V_107 ) {
F_47 ( V_97 ) ;
goto V_104;
}
error = F_47 ( V_97 ) ;
if ( V_98 || V_29 )
V_59 = 1 ;
else
goto V_104;
break;
case V_108 :
error = F_47 ( V_97 ) ;
V_59 = 1 ;
break;
case V_109 :
error = F_47 ( V_97 ) ;
V_59 = 1 ;
break;
default:
F_45 ( & V_36 -> V_39 ) ;
F_8 ( & V_36 -> V_39 ,
& V_15 -> V_38 ) ;
if ( V_36 -> V_70 == V_71 )
V_36 -> V_70 = V_110 ;
V_2 -> V_31 = 0 ;
break;
}
if ( ! error && ! V_103 )
V_103 = 1 ;
if ( V_59 )
break;
}
if ( V_98 || V_29 ) {
F_18 (chunk1, lqueue, transmitted_list) {
if ( V_102 -> V_70 == V_71 )
V_102 -> V_70 = V_110 ;
}
}
* V_99 = V_103 ;
if ( V_29 )
V_2 -> V_29 = 0 ;
return error ;
}
int F_48 ( struct V_1 * V_2 )
{
int error = 0 ;
if ( V_2 -> V_32 )
V_2 -> V_32 = 0 ;
error = F_32 ( V_2 , 0 ) ;
return error ;
}
static int F_32 ( struct V_1 * V_2 , int V_98 )
{
struct V_96 * V_111 ;
struct V_96 V_112 ;
struct V_23 * V_24 = V_2 -> V_24 ;
T_5 V_113 = V_24 -> V_93 . V_114 . V_115 ;
T_5 V_116 = V_24 -> V_67 . V_115 ;
T_1 V_117 = V_24 -> V_67 . V_118 . V_119 ;
struct V_13 * V_15 = NULL ;
struct V_13 * V_120 ;
struct V_3 * V_36 , * V_37 ;
T_4 V_101 ;
int error = 0 ;
int V_99 = 0 ;
int V_121 = 0 ;
struct V_10 V_122 ;
struct V_10 * V_123 ;
F_16 ( & V_122 ) ;
V_111 = NULL ;
F_23 (chunk, tmp, &q->control_chunk_list, list) {
if ( V_24 -> V_124 &&
V_36 -> V_40 -> type != V_125 )
continue;
F_6 ( & V_36 -> V_5 ) ;
V_120 = V_36 -> V_15 ;
if ( ! V_120 ) {
if ( V_15 &&
F_49 ( & V_36 -> V_126 ,
& V_15 -> V_127 ) )
V_120 = V_15 ;
else
V_120 = F_50 ( V_24 ,
& V_36 -> V_126 ) ;
if ( ! V_120 )
V_120 = V_24 -> V_67 . V_128 ;
} else if ( ( V_120 -> V_41 == V_129 ) ||
( V_120 -> V_41 == V_130 ) ) {
if ( V_36 -> V_40 -> type != V_131 &&
V_36 -> V_40 -> type != V_132 &&
V_36 -> V_40 -> type != V_133 )
V_120 = V_24 -> V_67 . V_128 ;
}
if ( V_120 != V_15 ) {
V_15 = V_120 ;
if ( F_4 ( & V_15 -> V_134 ) ) {
F_8 ( & V_15 -> V_134 ,
& V_122 ) ;
}
V_111 = & V_15 -> V_111 ;
F_51 ( V_111 , V_117 ,
V_24 -> V_67 . V_135 ) ;
}
switch ( V_36 -> V_40 -> type ) {
case V_136 :
case V_137 :
case V_138 :
F_52 ( & V_112 , V_15 , V_113 , V_116 ) ;
F_51 ( & V_112 , V_117 , 0 ) ;
F_46 ( & V_112 , V_36 ) ;
error = F_47 ( & V_112 ) ;
if ( error < 0 )
return error ;
break;
case V_139 :
if ( F_53 ( V_36 ) ) {
V_111 -> V_117 = V_24 -> V_140 . V_141 ;
}
case V_132 :
case V_142 :
case V_143 :
case V_144 :
case V_145 :
case V_146 :
case V_133 :
V_121 = 1 ;
case V_147 :
case V_131 :
case V_148 :
case V_149 :
case V_125 :
case V_150 :
V_101 = F_54 ( V_111 , V_36 ,
V_121 ) ;
if ( V_101 != V_151 ) {
F_2 ( & V_36 -> V_5 , & V_2 -> V_25 ) ;
} else if ( V_36 -> V_40 -> type == V_150 ) {
F_55 ( V_15 ) ;
}
break;
default:
F_42 () ;
}
}
if ( V_2 -> V_24 -> V_124 )
goto V_152;
switch ( V_24 -> V_41 ) {
case V_153 :
if ( ! V_111 || ! V_111 -> V_107 )
break;
case V_154 :
case V_43 :
case V_45 :
if ( ! F_4 ( & V_2 -> V_26 ) ) {
if ( V_24 -> V_67 . V_82 -> V_41 == V_130 )
goto V_152;
if ( V_15 == V_24 -> V_67 . V_82 )
goto V_155;
V_15 = V_24 -> V_67 . V_82 ;
if ( F_4 ( & V_15 -> V_134 ) ) {
F_8 ( & V_15 -> V_134 ,
& V_122 ) ;
}
V_111 = & V_15 -> V_111 ;
F_51 ( V_111 , V_117 ,
V_24 -> V_67 . V_135 ) ;
V_155:
error = F_44 ( V_2 , V_111 ,
V_98 , & V_99 ) ;
if ( V_99 )
F_55 ( V_15 ) ;
if ( V_111 -> V_107 )
goto V_152;
if ( ! F_4 ( & V_2 -> V_26 ) )
goto V_152;
}
if ( V_15 )
F_56 ( V_15 ) ;
while ( ( V_36 = F_3 ( V_2 ) ) != NULL ) {
if ( V_36 -> V_156 . V_157 >=
V_24 -> V_140 . V_158 ) {
F_20 ( V_36 , V_159 ) ;
F_21 ( V_36 ) ;
continue;
}
if ( F_37 ( V_36 ) ) {
F_20 ( V_36 , 0 ) ;
F_21 ( V_36 ) ;
continue;
}
V_120 = V_36 -> V_15 ;
if ( ! V_120 ||
( ( V_120 -> V_41 == V_129 ) ||
( V_120 -> V_41 == V_130 ) ) )
V_120 = V_24 -> V_67 . V_128 ;
if ( V_120 -> V_41 == V_130 )
continue;
if ( V_120 != V_15 ) {
V_15 = V_120 ;
if ( F_4 ( & V_15 -> V_134 ) ) {
F_8 ( & V_15 -> V_134 ,
& V_122 ) ;
}
V_111 = & V_15 -> V_111 ;
F_51 ( V_111 , V_117 ,
V_24 -> V_67 . V_135 ) ;
F_56 ( V_15 ) ;
}
F_27 ( L_7 ,
V_2 , V_36 ,
V_36 && V_36 -> V_40 ?
F_28 ( F_29 (
V_36 -> V_40 -> type ) )
: L_2 ) ;
F_27 ( L_8
L_9 ,
F_34 ( V_36 -> V_60 . V_61 -> V_20 ) ,
V_36 -> V_8 ? V_36 -> V_8 -> V_53 : NULL ,
V_36 -> V_8 ?
F_57 ( & V_36 -> V_8 -> V_160 ) : - 1 ) ;
V_101 = F_54 ( V_111 , V_36 , 0 ) ;
switch ( V_101 ) {
case V_105 :
case V_108 :
case V_109 :
F_27 ( L_10
L_11 ,
F_34 ( V_36 -> V_60 . V_61 -> V_20 ) ,
V_101 ) ;
F_1 ( V_2 , V_36 ) ;
goto V_152;
break;
case V_151 :
if ( V_24 -> V_41 == V_43 )
V_36 -> V_40 -> V_48 |= V_161 ;
break;
default:
F_42 () ;
}
F_8 ( & V_36 -> V_39 ,
& V_15 -> V_38 ) ;
F_55 ( V_15 ) ;
V_2 -> V_31 = 0 ;
if ( V_111 -> V_107 )
goto V_152;
}
break;
default:
break;
}
V_152:
while ( ( V_123 = F_19 ( & V_122 ) ) != NULL ) {
struct V_13 * V_162 = F_5 ( V_123 ,
struct V_13 ,
V_134 ) ;
V_111 = & V_162 -> V_111 ;
if ( ! F_58 ( V_111 ) )
error = F_47 ( V_111 ) ;
F_59 ( V_162 ) ;
}
return error ;
}
static void F_60 ( struct V_23 * V_163 ,
struct V_164 * V_165 )
{
T_6 * V_166 ;
T_5 V_84 ;
int V_118 ;
V_84 = V_163 -> V_167 - V_163 -> V_92 - 1 ;
V_166 = V_165 -> V_168 ;
for ( V_118 = 0 ; V_118 < F_61 ( V_165 -> V_169 ) ; V_118 ++ ) {
V_84 -= ( ( F_61 ( V_166 [ V_118 ] . V_170 . V_171 ) -
F_61 ( V_166 [ V_118 ] . V_170 . V_172 ) + 1 ) ) ;
}
V_163 -> V_84 = V_84 ;
}
int F_62 ( struct V_1 * V_2 , struct V_164 * V_165 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_13 * V_15 ;
struct V_3 * V_173 = NULL ;
struct V_10 * V_34 , * V_122 , * V_35 ;
T_6 * V_166 = V_165 -> V_168 ;
T_1 V_174 , V_175 , V_20 ;
T_1 V_176 , V_177 ;
T_1 V_178 ;
unsigned int V_179 ;
struct V_13 * V_14 = V_24 -> V_67 . V_180 ;
int V_16 = 0 ;
int V_181 ;
T_7 V_182 = 0 ;
V_122 = & V_24 -> V_67 . V_183 ;
V_174 = F_34 ( V_165 -> V_184 ) ;
V_181 = F_61 ( V_165 -> V_169 ) ;
if ( V_14 -> V_17 . V_22 ) {
T_7 V_185 = 0 ;
if ( F_63 ( V_14 -> V_17 . V_21 , V_174 ) ) {
V_14 -> V_17 . V_22 = 0 ;
V_185 = 1 ;
}
if ( V_185 || V_181 ) {
F_18 (transport, transport_list,
transports) {
if ( V_185 )
V_15 -> V_17 . V_19 = 0 ;
if ( V_181 )
V_15 -> V_17 . V_18 = 0 ;
}
}
}
V_176 = V_174 ;
if ( V_181 )
V_176 += F_61 ( V_166 [ V_181 - 1 ] . V_170 . V_171 ) ;
if ( F_13 ( V_24 -> V_186 , V_176 ) )
V_24 -> V_186 = V_176 ;
V_177 = V_174 ;
F_64 ( V_2 , & V_2 -> V_26 , NULL , V_165 , & V_177 ) ;
F_18 (transport, transport_list, transports) {
F_64 ( V_2 , & V_15 -> V_38 ,
V_15 , V_165 , & V_177 ) ;
if ( V_15 -> V_17 . V_18 )
V_16 ++ ;
}
if ( F_13 ( V_24 -> V_92 , V_174 ) ) {
V_24 -> V_92 = V_174 ;
V_182 = 1 ;
}
if ( V_181 ) {
if ( V_24 -> V_187 && V_182 )
V_177 = V_176 ;
F_18 (transport, transport_list, transports)
F_65 ( V_2 , & V_15 -> V_38 , V_15 ,
V_177 , V_16 ) ;
}
F_60 ( V_24 , V_165 ) ;
V_175 = V_24 -> V_92 ;
F_22 (lchunk, temp, &q->sacked) {
V_173 = F_5 ( V_34 , struct V_3 ,
V_39 ) ;
V_20 = F_34 ( V_173 -> V_60 . V_61 -> V_20 ) ;
if ( F_63 ( V_20 , V_175 ) ) {
F_6 ( & V_173 -> V_39 ) ;
F_21 ( V_173 ) ;
}
}
V_178 = F_34 ( V_165 -> V_188 ) ;
V_179 = V_2 -> V_30 ;
if ( V_179 < V_178 )
V_178 -= V_179 ;
else
V_178 = 0 ;
V_24 -> V_67 . V_68 = V_178 ;
F_43 ( V_2 , V_174 ) ;
F_27 ( L_12 ,
V_75 , V_174 ) ;
F_27 ( L_13
L_14 ,
V_75 , V_24 , V_175 , V_24 -> V_189 ) ;
V_2 -> V_31 = ( F_4 ( & V_2 -> V_6 ) &&
F_4 ( & V_2 -> V_26 ) ) ;
if ( ! V_2 -> V_31 )
goto V_190;
F_18 (transport, transport_list, transports) {
V_2 -> V_31 = V_2 -> V_31 && F_4 ( & V_15 -> V_38 ) ;
if ( ! V_2 -> V_31 )
goto V_190;
}
F_27 ( L_15 ) ;
V_190:
return V_2 -> V_31 ;
}
int F_66 ( const struct V_1 * V_2 )
{
return V_2 -> V_31 ;
}
static void F_64 ( struct V_1 * V_2 ,
struct V_10 * V_191 ,
struct V_13 * V_15 ,
struct V_164 * V_165 ,
T_1 * V_192 )
{
struct V_10 * V_34 ;
struct V_3 * V_173 ;
struct V_10 V_193 ;
T_1 V_20 ;
T_1 V_174 ;
T_1 V_194 ;
T_2 V_195 = 0 ;
int V_196 = 0 ;
int V_197 = 0 ;
#if V_198
T_1 V_199 = 0 ;
T_1 V_200 = 0 ;
T_1 V_201 = 0 ;
T_1 V_202 = 0 ;
int V_203 = - 1 ;
#endif
V_174 = F_34 ( V_165 -> V_184 ) ;
F_16 ( & V_193 ) ;
while ( NULL != ( V_34 = F_19 ( V_191 ) ) ) {
V_173 = F_5 ( V_34 , struct V_3 ,
V_39 ) ;
if ( F_37 ( V_173 ) ) {
F_33 ( & V_2 -> V_28 , V_34 ) ;
if ( ! V_173 -> V_65 ) {
if ( V_173 -> V_15 )
V_173 -> V_15 -> V_66 -=
F_38 ( V_173 ) ;
V_2 -> V_30 -= F_38 ( V_173 ) ;
}
continue;
}
V_20 = F_34 ( V_173 -> V_60 . V_61 -> V_20 ) ;
if ( F_67 ( V_165 , V_20 ) ) {
if ( V_15 ) {
if ( ! V_173 -> V_65 &&
V_173 -> V_73 ) {
V_173 -> V_73 = 0 ;
V_194 = V_204 - V_173 -> V_205 ;
F_68 ( V_15 ,
V_194 ) ;
}
}
if ( ! V_173 -> V_65 ) {
V_173 -> V_65 = 1 ;
* V_192 = V_20 ;
V_196 += F_38 ( V_173 ) ;
if ( ! V_173 -> V_15 )
V_197 += F_38 ( V_173 ) ;
}
if ( F_63 ( V_20 , V_174 ) ) {
V_195 = 1 ;
if ( ! V_173 -> V_65 ) {
if ( V_15 &&
V_165 -> V_169 &&
V_2 -> V_24 -> V_67 . V_180 -> V_17 .
V_22 )
V_15 -> V_17 . V_18
= 1 ;
}
F_8 ( & V_173 -> V_39 ,
& V_2 -> V_27 ) ;
} else {
F_8 ( V_34 , & V_193 ) ;
}
#if V_198
switch ( V_203 ) {
case 0 :
if ( V_200 + 1 == V_20 ) {
break;
}
if ( V_200 != V_199 ) {
F_69 ( L_16 ,
V_200 ) ;
}
F_69 ( L_17 , V_20 ) ;
V_199 = V_20 ;
break;
case 1 :
if ( V_202 != V_201 ) {
F_69 ( L_16 ,
V_202 ) ;
}
F_69 ( L_18 ) ;
default:
F_27 ( L_19 , V_20 ) ;
V_203 = 0 ;
V_199 = V_20 ;
}
V_200 = V_20 ;
#endif
} else {
if ( V_173 -> V_65 ) {
F_27 ( L_20
L_21 ,
V_75 ,
V_20 ) ;
V_173 -> V_65 = 0 ;
if ( V_173 -> V_15 )
V_196 -= F_38 ( V_173 ) ;
V_195 = 1 ;
}
F_8 ( V_34 , & V_193 ) ;
#if V_198
switch ( V_203 ) {
case 1 :
if ( V_202 + 1 == V_20 )
break;
if ( V_202 != V_201 )
F_69 ( L_16 ,
V_202 ) ;
F_69 ( L_17 , V_20 ) ;
V_201 = V_20 ;
break;
case 0 :
if ( V_200 != V_199 )
F_69 ( L_16 ,
V_200 ) ;
F_69 ( L_18 ) ;
default:
F_27 ( L_22 , V_20 ) ;
V_203 = 1 ;
V_201 = V_20 ;
}
V_202 = V_20 ;
#endif
}
}
#if V_198
switch ( V_203 ) {
case 0 :
if ( V_200 != V_199 ) {
F_69 ( L_23 , V_200 ) ;
} else {
F_69 ( L_18 ) ;
}
break;
case 1 :
if ( V_202 != V_201 ) {
F_69 ( L_23 , V_202 ) ;
} else {
F_69 ( L_18 ) ;
}
}
#endif
if ( V_15 ) {
if ( V_196 ) {
struct V_23 * V_24 = V_15 -> V_24 ;
V_196 -= V_197 ;
V_15 -> V_206 = 0 ;
V_15 -> V_24 -> V_207 = 0 ;
if ( V_24 -> V_41 == V_43 &&
F_70 ( & V_24 -> V_208
[ V_209 ] ) )
F_71 ( V_24 ) ;
if ( ( V_15 -> V_41 == V_129 ) ||
( V_15 -> V_41 == V_130 ) ) {
F_72 (
V_15 -> V_24 ,
V_15 ,
V_210 ,
V_211 ) ;
}
F_73 ( V_15 , V_174 ,
V_196 ) ;
V_15 -> V_66 -= V_196 ;
if ( V_15 -> V_66 == 0 )
V_15 -> V_78 = 0 ;
V_2 -> V_30 -= V_196 + V_197 ;
} else {
if ( ! V_2 -> V_24 -> V_67 . V_68 &&
! F_4 ( & V_193 ) &&
( V_174 + 2 == V_2 -> V_24 -> V_167 ) &&
V_2 -> V_24 -> V_41 < V_43 ) {
F_27 ( L_24
L_25 ,
V_75 , V_174 ) ;
V_2 -> V_24 -> V_207 = 0 ;
V_15 -> V_206 = 0 ;
}
}
if ( ! V_15 -> V_66 ) {
if ( F_74 ( & V_15 -> V_212 ) &&
F_70 ( & V_15 -> V_212 ) ) {
F_75 ( V_15 ) ;
}
} else if ( V_195 ) {
if ( ! F_76 ( & V_15 -> V_212 ,
V_204 + V_15 -> V_213 ) )
F_77 ( V_15 ) ;
}
}
F_78 ( & V_193 , V_191 ) ;
}
static void F_65 ( struct V_1 * V_2 ,
struct V_10 * V_191 ,
struct V_13 * V_15 ,
T_1 V_192 ,
int V_16 )
{
struct V_3 * V_36 ;
T_1 V_20 ;
char V_214 = 0 ;
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_13 * V_14 = V_24 -> V_67 . V_180 ;
F_18 (chunk, transmitted_queue, transmitted_list) {
V_20 = F_34 ( V_36 -> V_60 . V_61 -> V_20 ) ;
if ( V_36 -> V_70 == V_215 &&
! V_36 -> V_65 &&
F_13 ( V_20 , V_192 ) ) {
if ( ! V_15 || ! F_14 ( V_14 ,
V_36 -> V_15 ,
V_16 , V_20 ) ) {
V_36 -> V_72 ++ ;
F_27 (
L_26 ,
V_75 , V_20 ,
V_36 -> V_72 ) ;
}
}
if ( V_36 -> V_72 >= 3 ) {
V_36 -> V_70 = V_71 ;
V_214 = 1 ;
}
}
if ( V_15 ) {
if ( V_214 )
F_39 ( V_2 , V_15 , V_69 ) ;
F_27 ( L_27
L_28 ,
V_75 , V_15 , V_15 -> V_76 ,
V_15 -> V_77 , V_15 -> V_66 ,
V_15 -> V_78 ) ;
}
}
static int F_67 ( struct V_164 * V_165 , T_1 V_20 )
{
int V_118 ;
T_6 * V_166 ;
T_5 V_216 ;
T_1 V_175 = F_34 ( V_165 -> V_184 ) ;
if ( F_63 ( V_20 , V_175 ) )
goto V_217;
V_166 = V_165 -> V_168 ;
V_216 = V_20 - V_175 ;
for ( V_118 = 0 ; V_118 < F_61 ( V_165 -> V_169 ) ; ++ V_118 ) {
if ( F_63 ( F_61 ( V_166 [ V_118 ] . V_170 . V_172 ) , V_216 ) &&
F_63 ( V_216 , F_61 ( V_166 [ V_118 ] . V_170 . V_171 ) ) )
goto V_217;
}
return 0 ;
V_217:
return 1 ;
}
static inline int F_79 ( struct V_218 * V_219 ,
int V_220 , T_8 V_221 )
{
int V_118 ;
for ( V_118 = 0 ; V_118 < V_220 ; V_118 ++ ) {
if ( V_219 [ V_118 ] . V_221 == V_221 )
return V_118 ;
}
return V_118 ;
}
static void F_43 ( struct V_1 * V_2 , T_1 V_175 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_3 * V_222 = NULL ;
struct V_218 V_223 [ 10 ] ;
int V_220 = 0 ;
int V_224 = 0 ;
T_1 V_20 ;
struct V_3 * V_36 ;
struct V_10 * V_34 , * V_35 ;
if ( ! V_24 -> V_67 . V_225 )
return;
if ( F_13 ( V_24 -> V_189 , V_175 ) )
V_24 -> V_189 = V_175 ;
F_22 (lchunk, temp, &q->abandoned) {
V_36 = F_5 ( V_34 , struct V_3 ,
V_39 ) ;
V_20 = F_34 ( V_36 -> V_60 . V_61 -> V_20 ) ;
if ( F_63 ( V_20 , V_175 ) ) {
F_6 ( V_34 ) ;
F_21 ( V_36 ) ;
} else {
if ( F_63 ( V_20 , V_24 -> V_189 + 1 ) ) {
V_24 -> V_189 = V_20 ;
if ( V_36 -> V_40 -> V_48 &
V_49 )
continue;
V_224 = F_79 ( & V_223 [ 0 ] ,
V_220 ,
V_36 -> V_60 . V_61 -> V_221 ) ;
V_223 [ V_224 ] . V_221 =
V_36 -> V_60 . V_61 -> V_221 ;
V_223 [ V_224 ] . V_226 =
V_36 -> V_60 . V_61 -> V_226 ;
if ( V_224 == V_220 )
V_220 ++ ;
if ( V_220 == 10 )
break;
} else
break;
}
}
if ( V_24 -> V_189 > V_175 )
V_222 = F_80 ( V_24 , V_24 -> V_189 ,
V_220 , & V_223 [ 0 ] ) ;
if ( V_222 ) {
F_8 ( & V_222 -> V_5 , & V_2 -> V_25 ) ;
F_31 ( V_52 ) ;
}
}
