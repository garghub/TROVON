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
void F_26 ( struct V_1 * V_2 , struct V_3 * V_31 , T_2 V_35 )
{
struct V_36 * V_36 = F_27 ( V_2 -> V_24 -> V_37 . V_38 ) ;
F_28 ( L_1 , V_39 , V_2 , V_31 ,
V_31 && V_31 -> V_40 ?
F_29 ( F_30 ( V_31 -> V_40 -> type ) ) :
L_2 ) ;
if ( F_31 ( V_31 ) ) {
F_28 ( L_3 ,
V_39 , V_2 , V_31 , V_31 && V_31 -> V_40 ?
F_29 ( F_30 ( V_31 -> V_40 -> type ) ) :
L_2 ) ;
F_7 ( V_2 , V_31 ) ;
if ( V_31 -> V_24 -> V_41 . V_42 &&
F_32 ( V_31 -> V_43 . V_44 ) )
V_31 -> V_24 -> V_45 ++ ;
if ( V_31 -> V_40 -> V_46 & V_47 )
F_33 ( V_36 , V_48 ) ;
else
F_33 ( V_36 , V_49 ) ;
} else {
F_8 ( & V_31 -> V_5 , & V_2 -> V_25 ) ;
F_33 ( V_36 , V_50 ) ;
}
if ( ! V_2 -> V_51 )
F_34 ( V_2 , 0 , V_35 ) ;
}
static void F_35 ( struct V_10 * V_52 , struct V_10 * V_53 )
{
struct V_10 * V_54 ;
struct V_3 * V_55 , * V_29 ;
T_1 V_56 , V_57 ;
int V_58 = 0 ;
V_55 = F_5 ( V_53 , struct V_3 , V_34 ) ;
V_56 = F_36 ( V_55 -> V_59 . V_60 -> V_20 ) ;
F_37 (pos, head) {
V_29 = F_5 ( V_54 , struct V_3 , V_34 ) ;
V_57 = F_36 ( V_29 -> V_59 . V_60 -> V_20 ) ;
if ( F_13 ( V_56 , V_57 ) ) {
F_2 ( V_53 , V_54 -> V_61 ) ;
V_58 = 1 ;
break;
}
}
if ( ! V_58 )
F_8 ( V_53 , V_52 ) ;
}
static int F_38 ( struct V_23 * V_24 ,
struct V_62 * V_43 ,
struct V_10 * V_63 , int V_64 )
{
struct V_3 * V_65 , * V_30 ;
F_23 (chk, temp, queue, transmitted_list) {
struct V_66 * V_67 ;
if ( ! F_32 ( V_65 -> V_43 . V_44 ) ||
V_65 -> V_43 . V_68 <= V_43 -> V_68 )
continue;
F_6 ( & V_65 -> V_34 ) ;
F_35 ( & V_24 -> V_69 . V_28 ,
& V_65 -> V_34 ) ;
V_67 = & V_24 -> V_70 . V_71 [ V_65 -> V_43 . V_72 ] ;
V_24 -> V_45 -- ;
V_24 -> V_73 [ F_39 ( V_74 ) ] ++ ;
V_67 -> V_73 [ F_39 ( V_74 ) ] ++ ;
if ( ! V_65 -> V_75 ) {
if ( V_65 -> V_15 )
V_65 -> V_15 -> V_76 -=
F_40 ( V_65 ) ;
V_24 -> V_69 . V_77 -= F_40 ( V_65 ) ;
}
V_64 -= F_41 ( V_65 ) +
sizeof( struct V_78 ) +
sizeof( struct V_3 ) ;
if ( V_64 <= 0 )
break;
}
return V_64 ;
}
static int F_42 ( struct V_23 * V_24 ,
struct V_62 * V_43 , int V_64 )
{
struct V_1 * V_2 = & V_24 -> V_69 ;
struct V_3 * V_65 , * V_30 ;
F_23 (chk, temp, &q->out_chunk_list, list) {
if ( ! F_32 ( V_65 -> V_43 . V_44 ) ||
V_65 -> V_43 . V_68 <= V_43 -> V_68 )
continue;
F_6 ( & V_65 -> V_5 ) ;
V_2 -> V_7 -= V_65 -> V_8 -> V_9 ;
V_24 -> V_45 -- ;
V_24 -> V_79 [ F_39 ( V_74 ) ] ++ ;
if ( V_65 -> V_43 . V_72 < V_24 -> V_70 . V_80 ) {
struct V_66 * V_67 =
& V_24 -> V_70 . V_71 [ V_65 -> V_43 . V_72 ] ;
V_67 -> V_79 [ F_39 ( V_74 ) ] ++ ;
}
V_64 -= F_41 ( V_65 ) +
sizeof( struct V_78 ) +
sizeof( struct V_3 ) ;
F_21 ( V_65 ) ;
if ( V_64 <= 0 )
break;
}
return V_64 ;
}
void F_43 ( struct V_23 * V_24 ,
struct V_62 * V_43 , int V_64 )
{
struct V_13 * V_15 ;
if ( ! V_24 -> V_41 . V_42 || ! V_24 -> V_45 )
return;
V_64 = F_38 ( V_24 , V_43 ,
& V_24 -> V_69 . V_26 ,
V_64 ) ;
if ( V_64 <= 0 )
return;
F_18 (transport, &asoc->peer.transport_addr_list,
transports) {
V_64 = F_38 ( V_24 , V_43 ,
& V_15 -> V_33 ,
V_64 ) ;
if ( V_64 <= 0 )
return;
}
F_42 ( V_24 , V_43 , V_64 ) ;
}
void F_44 ( struct V_1 * V_2 ,
struct V_13 * V_15 ,
T_3 V_81 )
{
struct V_10 * V_29 , * V_82 ;
struct V_3 * V_31 ;
F_22 (lchunk, ltemp, &transport->transmitted) {
V_31 = F_5 ( V_29 , struct V_3 ,
V_34 ) ;
if ( F_45 ( V_31 ) ) {
F_6 ( V_29 ) ;
F_35 ( & V_2 -> V_28 , V_29 ) ;
if ( ! V_31 -> V_75 ) {
if ( V_31 -> V_15 )
V_31 -> V_15 -> V_76 -=
F_40 ( V_31 ) ;
V_2 -> V_77 -= F_40 ( V_31 ) ;
V_2 -> V_24 -> V_41 . V_83 += F_40 ( V_31 ) ;
}
continue;
}
if ( ( V_81 == V_84 &&
( V_31 -> V_85 == V_86 ) ) ||
( V_81 != V_84 && ! V_31 -> V_75 ) ) {
V_2 -> V_24 -> V_41 . V_83 += F_40 ( V_31 ) ;
V_2 -> V_77 -= F_40 ( V_31 ) ;
if ( V_31 -> V_15 )
V_15 -> V_76 -= F_40 ( V_31 ) ;
V_31 -> V_87 = 0 ;
if ( V_31 -> V_88 ) {
V_31 -> V_88 = 0 ;
V_15 -> V_89 = 0 ;
}
F_6 ( V_29 ) ;
F_35 ( & V_2 -> V_26 , V_29 ) ;
}
}
F_28 ( L_4
L_5 , V_39 , V_15 , V_81 ,
V_15 -> V_90 , V_15 -> V_91 , V_15 -> V_76 ,
V_15 -> V_92 ) ;
}
void F_46 ( struct V_1 * V_2 , struct V_13 * V_15 ,
enum V_93 V_81 )
{
struct V_36 * V_36 = F_27 ( V_2 -> V_24 -> V_37 . V_38 ) ;
switch ( V_81 ) {
case V_94 :
F_33 ( V_36 , V_95 ) ;
F_47 ( V_15 , V_96 ) ;
if ( V_15 == V_15 -> V_24 -> V_41 . V_97 )
F_48 ( V_15 -> V_24 ) ;
V_15 -> V_24 -> V_98 +=
V_15 -> V_24 -> V_99 ;
break;
case V_84 :
F_33 ( V_36 , V_100 ) ;
F_47 ( V_15 , V_101 ) ;
V_2 -> V_102 = 1 ;
break;
case V_103 :
F_33 ( V_36 , V_104 ) ;
break;
case V_105 :
F_33 ( V_36 , V_106 ) ;
V_15 -> V_24 -> V_107 ++ ;
break;
default:
F_49 () ;
}
F_44 ( V_2 , V_15 , V_81 ) ;
if ( V_81 == V_94 )
F_50 ( V_2 , V_2 -> V_24 -> V_108 ) ;
if ( V_81 != V_84 )
F_34 ( V_2 , 1 , V_109 ) ;
}
static int F_51 ( struct V_1 * V_2 , struct V_110 * V_111 ,
int V_112 , int * V_113 )
{
struct V_13 * V_15 = V_111 -> V_15 ;
struct V_3 * V_31 , * V_114 ;
struct V_10 * V_115 ;
enum V_116 V_117 ;
int error = 0 ;
int V_118 = 0 ;
int V_58 = 0 ;
int V_102 ;
V_115 = & V_2 -> V_26 ;
V_102 = V_2 -> V_102 ;
F_23 (chunk, chunk1, lqueue, transmitted_list) {
if ( F_45 ( V_31 ) ) {
F_6 ( & V_31 -> V_34 ) ;
F_35 ( & V_2 -> V_28 ,
& V_31 -> V_34 ) ;
continue;
}
if ( V_31 -> V_75 ) {
F_52 ( & V_31 -> V_34 ,
& V_15 -> V_33 ) ;
continue;
}
if ( V_102 && ! V_31 -> V_85 )
continue;
V_119:
V_117 = F_53 ( V_111 , V_31 ) ;
switch ( V_117 ) {
case V_120 :
if ( ! V_111 -> V_121 && ! V_111 -> V_122 ) {
F_54 ( V_111 , V_109 ) ;
goto V_119;
}
error = F_54 ( V_111 , V_109 ) ;
if ( V_112 || V_102 )
V_58 = 1 ;
else
goto V_119;
break;
case V_123 :
error = F_54 ( V_111 , V_109 ) ;
V_58 = 1 ;
break;
case V_124 :
error = F_54 ( V_111 , V_109 ) ;
V_58 = 1 ;
break;
default:
F_52 ( & V_31 -> V_34 ,
& V_15 -> V_33 ) ;
if ( V_31 -> V_85 == V_86 )
V_31 -> V_85 = V_125 ;
V_2 -> V_24 -> V_126 . V_127 ++ ;
break;
}
if ( ! error && ! V_118 )
V_118 = 1 ;
if ( V_58 )
break;
}
if ( V_112 || V_102 ) {
F_18 (chunk1, lqueue, transmitted_list) {
if ( V_114 -> V_85 == V_86 )
V_114 -> V_85 = V_125 ;
}
}
* V_113 = V_118 ;
if ( V_102 )
V_2 -> V_102 = 0 ;
return error ;
}
void F_55 ( struct V_1 * V_2 , T_2 V_35 )
{
if ( V_2 -> V_51 )
V_2 -> V_51 = 0 ;
F_34 ( V_2 , 0 , V_35 ) ;
}
static void F_34 ( struct V_1 * V_2 , int V_112 , T_2 V_35 )
{
struct V_110 * V_128 ;
struct V_110 V_129 ;
struct V_23 * V_24 = V_2 -> V_24 ;
T_4 V_130 = V_24 -> V_37 . V_131 . V_132 ;
T_4 V_133 = V_24 -> V_41 . V_132 ;
T_1 V_134 = V_24 -> V_41 . V_135 . V_136 ;
struct V_13 * V_15 = NULL ;
struct V_13 * V_137 ;
struct V_3 * V_31 , * V_32 ;
enum V_116 V_117 ;
int error = 0 ;
int V_113 = 0 ;
int V_138 = 0 ;
struct V_10 V_139 ;
struct V_10 * V_140 ;
F_16 ( & V_139 ) ;
V_128 = NULL ;
F_23 (chunk, tmp, &q->control_chunk_list, list) {
if ( V_24 -> V_141 &&
V_31 -> V_40 -> type != V_142 )
continue;
F_6 ( & V_31 -> V_5 ) ;
V_137 = V_31 -> V_15 ;
if ( ! V_137 ) {
if ( V_15 &&
F_56 ( & V_31 -> V_143 ,
& V_15 -> V_144 ) )
V_137 = V_15 ;
else
V_137 = F_57 ( V_24 ,
& V_31 -> V_143 ) ;
if ( ! V_137 )
V_137 = V_24 -> V_41 . V_145 ;
} else if ( ( V_137 -> V_146 == V_147 ) ||
( V_137 -> V_146 == V_148 ) ||
( V_137 -> V_146 == V_149 ) ) {
if ( V_31 -> V_40 -> type != V_150 &&
V_31 -> V_40 -> type != V_151 &&
V_31 -> V_40 -> type != V_152 )
V_137 = V_24 -> V_41 . V_145 ;
}
if ( V_137 != V_15 ) {
V_15 = V_137 ;
if ( F_4 ( & V_15 -> V_153 ) ) {
F_8 ( & V_15 -> V_153 ,
& V_139 ) ;
}
V_128 = & V_15 -> V_128 ;
F_58 ( V_128 , V_134 ,
V_24 -> V_41 . V_154 ) ;
}
switch ( V_31 -> V_40 -> type ) {
case V_155 :
case V_156 :
case V_157 :
F_59 ( & V_129 , V_15 , V_130 , V_133 ) ;
F_58 ( & V_129 , V_134 , 0 ) ;
F_53 ( & V_129 , V_31 ) ;
error = F_54 ( & V_129 , V_35 ) ;
if ( error < 0 ) {
V_24 -> V_37 . V_38 -> V_158 = - error ;
return;
}
break;
case V_159 :
if ( F_60 ( V_31 ) ) {
V_128 -> V_134 = V_24 -> V_160 . V_161 ;
}
case V_151 :
case V_162 :
case V_163 :
case V_164 :
case V_165 :
case V_166 :
case V_152 :
V_138 = 1 ;
case V_167 :
case V_150 :
case V_168 :
case V_169 :
case V_142 :
case V_170 :
case V_171 :
V_117 = F_61 ( V_128 , V_31 ,
V_138 , V_35 ) ;
if ( V_117 != V_172 ) {
F_2 ( & V_31 -> V_5 , & V_2 -> V_25 ) ;
break;
}
V_24 -> V_126 . V_173 ++ ;
if ( V_31 -> V_40 -> type == V_170 ) {
F_62 ( V_15 ) ;
V_15 -> V_174 = V_175 ;
}
if ( V_31 == V_24 -> V_176 )
F_63 ( V_15 ) ;
break;
default:
F_49 () ;
}
}
if ( V_2 -> V_24 -> V_141 )
goto V_177;
switch ( V_24 -> V_146 ) {
case V_178 :
if ( ! V_128 || ! V_128 -> V_122 )
break;
case V_179 :
case V_180 :
case V_181 :
if ( ! F_4 ( & V_2 -> V_26 ) ) {
if ( V_24 -> V_41 . V_97 -> V_146 == V_148 )
goto V_177;
if ( V_15 == V_24 -> V_41 . V_97 )
goto V_182;
V_15 = V_24 -> V_41 . V_97 ;
if ( F_4 ( & V_15 -> V_153 ) ) {
F_8 ( & V_15 -> V_153 ,
& V_139 ) ;
}
V_128 = & V_15 -> V_128 ;
F_58 ( V_128 , V_134 ,
V_24 -> V_41 . V_154 ) ;
V_182:
error = F_51 ( V_2 , V_128 ,
V_112 , & V_113 ) ;
if ( error < 0 )
V_24 -> V_37 . V_38 -> V_158 = - error ;
if ( V_113 ) {
F_62 ( V_15 ) ;
V_15 -> V_174 = V_175 ;
}
if ( V_128 -> V_122 )
goto V_177;
if ( ! F_4 ( & V_2 -> V_26 ) )
goto V_177;
}
if ( V_15 )
F_64 ( V_15 ) ;
while ( ( V_31 = F_3 ( V_2 ) ) != NULL ) {
T_1 V_183 = F_65 ( V_31 -> V_59 . V_60 -> V_70 ) ;
if ( V_31 -> V_43 . V_72 >= V_24 -> V_70 . V_80 ) {
F_20 ( V_31 , V_184 ) ;
if ( V_24 -> V_41 . V_42 &&
F_32 ( V_31 -> V_43 . V_44 ) )
V_24 -> V_45 -- ;
F_21 ( V_31 ) ;
continue;
}
if ( F_45 ( V_31 ) ) {
F_20 ( V_31 , 0 ) ;
F_21 ( V_31 ) ;
continue;
}
if ( V_24 -> V_70 . V_71 [ V_183 ] . V_146 == V_185 ) {
F_1 ( V_2 , V_31 ) ;
goto V_177;
}
V_137 = V_31 -> V_15 ;
if ( ! V_137 ||
( ( V_137 -> V_146 == V_147 ) ||
( V_137 -> V_146 == V_148 ) ||
( V_137 -> V_146 == V_149 ) ) )
V_137 = V_24 -> V_41 . V_145 ;
if ( V_137 -> V_146 == V_148 ) {
F_66 ( 1 , L_6 ) ;
F_20 ( V_31 , 0 ) ;
F_21 ( V_31 ) ;
continue;
}
if ( V_137 != V_15 ) {
V_15 = V_137 ;
if ( F_4 ( & V_15 -> V_153 ) ) {
F_8 ( & V_15 -> V_153 ,
& V_139 ) ;
}
V_128 = & V_15 -> V_128 ;
F_58 ( V_128 , V_134 ,
V_24 -> V_41 . V_154 ) ;
F_64 ( V_15 ) ;
}
F_28 ( L_7
L_8 ,
V_39 , V_2 , V_31 , V_31 && V_31 -> V_40 ?
F_29 ( F_30 ( V_31 -> V_40 -> type ) ) :
L_2 , F_36 ( V_31 -> V_59 . V_60 -> V_20 ) ,
V_31 -> V_8 ? V_31 -> V_8 -> V_52 : NULL , V_31 -> V_8 ?
F_67 ( & V_31 -> V_8 -> V_186 ) : - 1 ) ;
V_117 = F_61 ( V_128 , V_31 , 0 , V_35 ) ;
switch ( V_117 ) {
case V_120 :
case V_123 :
case V_124 :
F_28 ( L_9 ,
V_39 , F_36 ( V_31 -> V_59 . V_60 -> V_20 ) ,
V_117 ) ;
F_1 ( V_2 , V_31 ) ;
goto V_177;
case V_172 :
if ( V_24 -> V_146 == V_180 )
V_31 -> V_40 -> V_46 |= V_187 ;
if ( V_31 -> V_40 -> V_46 & V_47 )
V_24 -> V_126 . V_188 ++ ;
else
V_24 -> V_126 . V_189 ++ ;
break;
default:
F_49 () ;
}
F_8 ( & V_31 -> V_34 ,
& V_15 -> V_33 ) ;
F_62 ( V_15 ) ;
V_15 -> V_174 = V_175 ;
if ( V_128 -> V_122 )
goto V_177;
}
break;
default:
break;
}
V_177:
while ( ( V_140 = F_19 ( & V_139 ) ) != NULL ) {
struct V_13 * V_190 = F_5 ( V_140 ,
struct V_13 ,
V_153 ) ;
V_128 = & V_190 -> V_128 ;
if ( ! F_68 ( V_128 ) ) {
error = F_54 ( V_128 , V_35 ) ;
if ( error < 0 )
V_24 -> V_37 . V_38 -> V_158 = - error ;
}
F_69 ( V_190 ) ;
}
}
static void F_70 ( struct V_23 * V_191 ,
struct V_192 * V_193 )
{
union V_194 * V_195 ;
T_4 V_99 ;
int V_135 ;
V_99 = V_191 -> V_196 - V_191 -> V_108 - 1 ;
V_195 = V_193 -> V_197 ;
for ( V_135 = 0 ; V_135 < F_65 ( V_193 -> V_198 ) ; V_135 ++ ) {
V_99 -= ( ( F_65 ( V_195 [ V_135 ] . V_199 . V_200 ) -
F_65 ( V_195 [ V_135 ] . V_199 . V_201 ) + 1 ) ) ;
}
V_191 -> V_99 = V_99 ;
}
int F_71 ( struct V_1 * V_2 , struct V_3 * V_31 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_192 * V_193 = V_31 -> V_59 . V_202 ;
struct V_13 * V_15 ;
struct V_3 * V_203 = NULL ;
struct V_10 * V_29 , * V_139 , * V_30 ;
union V_194 * V_195 = V_193 -> V_197 ;
T_1 V_204 , V_205 , V_20 ;
T_1 V_206 , V_207 ;
T_1 V_208 ;
unsigned int V_209 ;
struct V_13 * V_14 = V_24 -> V_41 . V_210 ;
int V_16 = 0 ;
int V_211 ;
T_5 V_212 = 0 ;
V_139 = & V_24 -> V_41 . V_213 ;
V_204 = F_36 ( V_193 -> V_214 ) ;
V_211 = F_65 ( V_193 -> V_198 ) ;
V_24 -> V_126 . V_215 += V_211 ;
if ( V_14 -> V_17 . V_22 ) {
T_5 V_216 = 0 ;
if ( F_72 ( V_14 -> V_17 . V_21 , V_204 ) ) {
V_14 -> V_17 . V_22 = 0 ;
V_216 = 1 ;
}
if ( V_216 || V_211 ) {
F_18 (transport, transport_list,
transports) {
if ( V_216 )
V_15 -> V_17 . V_19 = 0 ;
if ( V_211 )
V_15 -> V_17 . V_18 = 0 ;
}
}
}
V_206 = V_204 ;
if ( V_211 )
V_206 += F_65 ( V_195 [ V_211 - 1 ] . V_199 . V_200 ) ;
if ( F_13 ( V_24 -> V_217 , V_206 ) )
V_24 -> V_217 = V_206 ;
V_207 = V_204 ;
F_73 ( V_2 , & V_2 -> V_26 , NULL , NULL , V_193 , & V_207 ) ;
F_18 (transport, transport_list, transports) {
F_73 ( V_2 , & V_15 -> V_33 ,
V_15 , & V_31 -> V_218 , V_193 ,
& V_207 ) ;
if ( V_15 -> V_17 . V_18 )
V_16 ++ ;
}
if ( F_13 ( V_24 -> V_108 , V_204 ) ) {
V_24 -> V_108 = V_204 ;
V_212 = 1 ;
}
if ( V_211 ) {
if ( V_24 -> V_219 && V_212 )
V_207 = V_206 ;
F_18 (transport, transport_list, transports)
F_74 ( V_2 , & V_15 -> V_33 , V_15 ,
V_207 , V_16 ) ;
}
F_70 ( V_24 , V_193 ) ;
V_205 = V_24 -> V_108 ;
F_22 (lchunk, temp, &q->sacked) {
V_203 = F_5 ( V_29 , struct V_3 ,
V_34 ) ;
V_20 = F_36 ( V_203 -> V_59 . V_60 -> V_20 ) ;
if ( F_72 ( V_20 , V_205 ) ) {
F_6 ( & V_203 -> V_34 ) ;
if ( V_24 -> V_41 . V_42 &&
F_32 ( V_31 -> V_43 . V_44 ) )
V_24 -> V_45 -- ;
F_21 ( V_203 ) ;
}
}
V_208 = F_36 ( V_193 -> V_220 ) ;
V_24 -> V_41 . V_221 = ! V_208 ;
V_209 = V_2 -> V_77 ;
if ( V_209 < V_208 )
V_208 -= V_209 ;
else
V_208 = 0 ;
V_24 -> V_41 . V_83 = V_208 ;
F_50 ( V_2 , V_204 ) ;
F_28 ( L_10 , V_39 , V_204 ) ;
F_28 ( L_11
L_12 , V_39 , V_24 , V_205 ,
V_24 -> V_222 ) ;
return F_75 ( V_2 ) ;
}
int F_75 ( const struct V_1 * V_2 )
{
return V_2 -> V_7 == 0 && V_2 -> V_77 == 0 &&
F_4 ( & V_2 -> V_26 ) ;
}
static void F_73 ( struct V_1 * V_2 ,
struct V_10 * V_223 ,
struct V_13 * V_15 ,
union V_224 * V_225 ,
struct V_192 * V_193 ,
T_1 * V_226 )
{
struct V_10 * V_29 ;
struct V_3 * V_203 ;
struct V_10 V_227 ;
T_1 V_20 ;
T_1 V_204 ;
T_1 V_228 ;
T_3 V_229 = 0 ;
int V_230 = 0 ;
int V_231 = 0 ;
bool V_232 = false ;
V_204 = F_36 ( V_193 -> V_214 ) ;
F_16 ( & V_227 ) ;
while ( NULL != ( V_29 = F_19 ( V_223 ) ) ) {
V_203 = F_5 ( V_29 , struct V_3 ,
V_34 ) ;
if ( F_45 ( V_203 ) ) {
F_35 ( & V_2 -> V_28 , V_29 ) ;
if ( ! V_203 -> V_75 ) {
if ( V_203 -> V_15 )
V_203 -> V_15 -> V_76 -=
F_40 ( V_203 ) ;
V_2 -> V_77 -= F_40 ( V_203 ) ;
}
continue;
}
V_20 = F_36 ( V_203 -> V_59 . V_60 -> V_20 ) ;
if ( F_76 ( V_193 , V_20 ) ) {
if ( V_15 ) {
if ( ! V_203 -> V_75 &&
! F_77 ( V_203 ) &&
V_203 -> V_88 ) {
V_203 -> V_88 = 0 ;
V_228 = V_175 - V_203 -> V_233 ;
F_78 ( V_15 ,
V_228 ) ;
}
}
if ( ! V_203 -> V_75 ) {
V_203 -> V_75 = 1 ;
if ( F_13 ( * V_226 , V_20 ) )
* V_226 = V_20 ;
V_230 += F_40 ( V_203 ) ;
if ( ! V_203 -> V_15 )
V_231 += F_40 ( V_203 ) ;
V_232 = true ;
}
if ( F_72 ( V_20 , V_204 ) ) {
V_229 = 1 ;
V_232 = true ;
if ( ! V_203 -> V_75 ) {
if ( V_15 &&
V_193 -> V_198 &&
V_2 -> V_24 -> V_41 . V_210 -> V_17 .
V_22 )
V_15 -> V_17 . V_18
= 1 ;
}
F_8 ( & V_203 -> V_34 ,
& V_2 -> V_27 ) ;
} else {
F_8 ( V_29 , & V_227 ) ;
}
} else {
if ( V_203 -> V_75 ) {
F_28 ( L_13 ,
V_39 , V_20 ) ;
V_203 -> V_75 = 0 ;
if ( V_203 -> V_15 )
V_230 -= F_40 ( V_203 ) ;
V_229 = 1 ;
}
F_8 ( V_29 , & V_227 ) ;
}
}
if ( V_15 ) {
if ( V_230 ) {
struct V_23 * V_24 = V_15 -> V_24 ;
V_230 -= V_231 ;
V_15 -> V_234 = 0 ;
V_15 -> V_24 -> V_235 = 0 ;
V_232 = true ;
if ( V_24 -> V_146 == V_180 &&
F_79 ( & V_24 -> V_236
[ V_237 ] ) )
F_80 ( V_24 ) ;
if ( ( V_15 -> V_146 == V_147 ||
V_15 -> V_146 == V_148 ) &&
F_56 ( & V_15 -> V_144 , V_225 ) ) {
F_81 (
V_15 -> V_24 ,
V_15 ,
V_238 ,
V_239 ) ;
}
F_82 ( V_15 , V_204 ,
V_230 ) ;
V_15 -> V_76 -= V_230 ;
if ( V_15 -> V_76 == 0 )
V_15 -> V_92 = 0 ;
V_2 -> V_77 -= V_230 + V_231 ;
} else {
if ( ! V_2 -> V_24 -> V_41 . V_83 &&
! F_4 ( & V_227 ) &&
( V_204 + 2 == V_2 -> V_24 -> V_196 ) &&
V_2 -> V_24 -> V_146 < V_180 ) {
F_28 ( L_14
L_15 , V_39 , V_204 ) ;
V_2 -> V_24 -> V_235 = 0 ;
V_15 -> V_234 = 0 ;
}
}
if ( ! V_15 -> V_76 ) {
if ( F_79 ( & V_15 -> V_240 ) )
F_83 ( V_15 ) ;
} else if ( V_229 ) {
if ( ! F_84 ( & V_15 -> V_240 ,
V_175 + V_15 -> V_241 ) )
F_85 ( V_15 ) ;
}
if ( V_232 ) {
if ( V_15 -> V_242 )
F_86 ( V_15 ) ;
}
}
F_87 ( & V_227 , V_223 ) ;
}
static void F_74 ( struct V_1 * V_2 ,
struct V_10 * V_223 ,
struct V_13 * V_15 ,
T_1 V_226 ,
int V_16 )
{
struct V_3 * V_31 ;
T_1 V_20 ;
char V_243 = 0 ;
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_13 * V_14 = V_24 -> V_41 . V_210 ;
F_18 (chunk, transmitted_queue, transmitted_list) {
V_20 = F_36 ( V_31 -> V_59 . V_60 -> V_20 ) ;
if ( V_31 -> V_85 == V_244 &&
! V_31 -> V_75 &&
F_13 ( V_20 , V_226 ) ) {
if ( ! V_15 || ! F_14 ( V_14 ,
V_31 -> V_15 ,
V_16 , V_20 ) ) {
V_31 -> V_87 ++ ;
F_28 ( L_16 ,
V_39 , V_20 , V_31 -> V_87 ) ;
}
}
if ( V_31 -> V_87 >= 3 ) {
V_31 -> V_85 = V_86 ;
V_243 = 1 ;
}
}
if ( V_15 ) {
if ( V_243 )
F_46 ( V_2 , V_15 , V_84 ) ;
F_28 ( L_17
L_5 , V_39 , V_15 ,
V_15 -> V_90 , V_15 -> V_91 ,
V_15 -> V_76 , V_15 -> V_92 ) ;
}
}
static int F_76 ( struct V_192 * V_193 , T_1 V_20 )
{
T_1 V_205 = F_36 ( V_193 -> V_214 ) ;
union V_194 * V_195 ;
T_4 V_245 , V_246 ;
int V_135 ;
if ( F_72 ( V_20 , V_205 ) )
goto V_247;
V_195 = V_193 -> V_197 ;
V_246 = F_65 ( V_193 -> V_198 ) ;
V_245 = V_20 - V_205 ;
for ( V_135 = 0 ; V_135 < V_246 ; ++ V_135 ) {
if ( V_245 >= F_65 ( V_195 [ V_135 ] . V_199 . V_201 ) &&
V_245 <= F_65 ( V_195 [ V_135 ] . V_199 . V_200 ) )
goto V_247;
}
return 0 ;
V_247:
return 1 ;
}
static inline int F_88 ( struct V_248 * V_249 ,
int V_250 , T_6 V_70 )
{
int V_135 ;
for ( V_135 = 0 ; V_135 < V_250 ; V_135 ++ ) {
if ( V_249 [ V_135 ] . V_70 == V_70 )
return V_135 ;
}
return V_135 ;
}
static void F_50 ( struct V_1 * V_2 , T_1 V_205 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_3 * V_251 = NULL ;
struct V_248 V_252 [ 10 ] ;
int V_250 = 0 ;
int V_253 = 0 ;
T_1 V_20 ;
struct V_3 * V_31 ;
struct V_10 * V_29 , * V_30 ;
if ( ! V_24 -> V_41 . V_42 )
return;
if ( F_13 ( V_24 -> V_222 , V_205 ) )
V_24 -> V_222 = V_205 ;
F_22 (lchunk, temp, &q->abandoned) {
V_31 = F_5 ( V_29 , struct V_3 ,
V_34 ) ;
V_20 = F_36 ( V_31 -> V_59 . V_60 -> V_20 ) ;
if ( F_72 ( V_20 , V_205 ) ) {
F_6 ( V_29 ) ;
F_21 ( V_31 ) ;
} else {
if ( F_72 ( V_20 , V_24 -> V_222 + 1 ) ) {
V_24 -> V_222 = V_20 ;
if ( V_31 -> V_40 -> V_46 &
V_47 )
continue;
V_253 = F_88 ( & V_252 [ 0 ] ,
V_250 ,
V_31 -> V_59 . V_60 -> V_70 ) ;
V_252 [ V_253 ] . V_70 =
V_31 -> V_59 . V_60 -> V_70 ;
V_252 [ V_253 ] . V_254 =
V_31 -> V_59 . V_60 -> V_254 ;
if ( V_253 == V_250 )
V_250 ++ ;
if ( V_250 == 10 )
break;
} else
break;
}
}
if ( V_24 -> V_222 > V_205 )
V_251 = F_89 ( V_24 , V_24 -> V_222 ,
V_250 , & V_252 [ 0 ] ) ;
if ( V_251 ) {
F_8 ( & V_251 -> V_5 , & V_2 -> V_25 ) ;
F_33 ( F_27 ( V_24 -> V_37 . V_38 ) , V_50 ) ;
}
}
