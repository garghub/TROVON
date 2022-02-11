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
V_67 = & V_24 -> V_70 -> V_71 [ V_65 -> V_43 . V_72 ] ;
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
if ( V_65 -> V_43 . V_72 < V_24 -> V_70 -> V_80 ) {
struct V_66 * V_67 =
& V_24 -> V_70 -> V_71 [ V_65 -> V_43 . V_72 ] ;
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
T_4 V_81 )
{
struct V_36 * V_36 = F_27 ( V_2 -> V_24 -> V_37 . V_38 ) ;
switch ( V_81 ) {
case V_93 :
F_33 ( V_36 , V_94 ) ;
F_47 ( V_15 , V_95 ) ;
if ( V_15 == V_15 -> V_24 -> V_41 . V_96 )
F_48 ( V_15 -> V_24 ) ;
V_15 -> V_24 -> V_97 +=
V_15 -> V_24 -> V_98 ;
break;
case V_84 :
F_33 ( V_36 , V_99 ) ;
F_47 ( V_15 , V_100 ) ;
V_2 -> V_101 = 1 ;
break;
case V_102 :
F_33 ( V_36 , V_103 ) ;
break;
case V_104 :
F_33 ( V_36 , V_105 ) ;
V_15 -> V_24 -> V_106 ++ ;
break;
default:
F_49 () ;
}
F_44 ( V_2 , V_15 , V_81 ) ;
if ( V_81 == V_93 )
F_50 ( V_2 , V_2 -> V_24 -> V_107 ) ;
if ( V_81 != V_84 )
F_34 ( V_2 , 1 , V_108 ) ;
}
static int F_51 ( struct V_1 * V_2 , struct V_109 * V_110 ,
int V_111 , int * V_112 )
{
struct V_10 * V_113 ;
struct V_13 * V_15 = V_110 -> V_15 ;
T_5 V_114 ;
struct V_3 * V_31 , * V_115 ;
int V_101 ;
int error = 0 ;
int V_116 = 0 ;
int V_58 = 0 ;
V_113 = & V_2 -> V_26 ;
V_101 = V_2 -> V_101 ;
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
if ( V_101 && ! V_31 -> V_85 )
continue;
V_117:
V_114 = F_53 ( V_110 , V_31 ) ;
switch ( V_114 ) {
case V_118 :
if ( ! V_110 -> V_119 && ! V_110 -> V_120 ) {
F_54 ( V_110 , V_108 ) ;
goto V_117;
}
error = F_54 ( V_110 , V_108 ) ;
if ( V_111 || V_101 )
V_58 = 1 ;
else
goto V_117;
break;
case V_121 :
error = F_54 ( V_110 , V_108 ) ;
V_58 = 1 ;
break;
case V_122 :
error = F_54 ( V_110 , V_108 ) ;
V_58 = 1 ;
break;
default:
F_52 ( & V_31 -> V_34 ,
& V_15 -> V_33 ) ;
if ( V_31 -> V_85 == V_86 )
V_31 -> V_85 = V_123 ;
V_2 -> V_24 -> V_124 . V_125 ++ ;
break;
}
if ( ! error && ! V_116 )
V_116 = 1 ;
if ( V_58 )
break;
}
if ( V_111 || V_101 ) {
F_18 (chunk1, lqueue, transmitted_list) {
if ( V_115 -> V_85 == V_86 )
V_115 -> V_85 = V_123 ;
}
}
* V_112 = V_116 ;
if ( V_101 )
V_2 -> V_101 = 0 ;
return error ;
}
void F_55 ( struct V_1 * V_2 , T_2 V_35 )
{
if ( V_2 -> V_51 )
V_2 -> V_51 = 0 ;
F_34 ( V_2 , 0 , V_35 ) ;
}
static void F_34 ( struct V_1 * V_2 , int V_111 , T_2 V_35 )
{
struct V_109 * V_126 ;
struct V_109 V_127 ;
struct V_23 * V_24 = V_2 -> V_24 ;
T_6 V_128 = V_24 -> V_37 . V_129 . V_130 ;
T_6 V_131 = V_24 -> V_41 . V_130 ;
T_1 V_132 = V_24 -> V_41 . V_133 . V_134 ;
struct V_13 * V_15 = NULL ;
struct V_13 * V_135 ;
struct V_3 * V_31 , * V_32 ;
T_5 V_114 ;
int error = 0 ;
int V_112 = 0 ;
int V_136 = 0 ;
struct V_10 V_137 ;
struct V_10 * V_138 ;
F_16 ( & V_137 ) ;
V_126 = NULL ;
F_23 (chunk, tmp, &q->control_chunk_list, list) {
if ( V_24 -> V_139 &&
V_31 -> V_40 -> type != V_140 )
continue;
F_6 ( & V_31 -> V_5 ) ;
V_135 = V_31 -> V_15 ;
if ( ! V_135 ) {
if ( V_15 &&
F_56 ( & V_31 -> V_141 ,
& V_15 -> V_142 ) )
V_135 = V_15 ;
else
V_135 = F_57 ( V_24 ,
& V_31 -> V_141 ) ;
if ( ! V_135 )
V_135 = V_24 -> V_41 . V_143 ;
} else if ( ( V_135 -> V_144 == V_145 ) ||
( V_135 -> V_144 == V_146 ) ||
( V_135 -> V_144 == V_147 ) ) {
if ( V_31 -> V_40 -> type != V_148 &&
V_31 -> V_40 -> type != V_149 &&
V_31 -> V_40 -> type != V_150 )
V_135 = V_24 -> V_41 . V_143 ;
}
if ( V_135 != V_15 ) {
V_15 = V_135 ;
if ( F_4 ( & V_15 -> V_151 ) ) {
F_8 ( & V_15 -> V_151 ,
& V_137 ) ;
}
V_126 = & V_15 -> V_126 ;
F_58 ( V_126 , V_132 ,
V_24 -> V_41 . V_152 ) ;
}
switch ( V_31 -> V_40 -> type ) {
case V_153 :
case V_154 :
case V_155 :
F_59 ( & V_127 , V_15 , V_128 , V_131 ) ;
F_58 ( & V_127 , V_132 , 0 ) ;
F_53 ( & V_127 , V_31 ) ;
error = F_54 ( & V_127 , V_35 ) ;
if ( error < 0 ) {
V_24 -> V_37 . V_38 -> V_156 = - error ;
return;
}
break;
case V_157 :
if ( F_60 ( V_31 ) ) {
V_126 -> V_132 = V_24 -> V_158 . V_159 ;
}
case V_149 :
case V_160 :
case V_161 :
case V_162 :
case V_163 :
case V_164 :
case V_150 :
V_136 = 1 ;
case V_165 :
case V_148 :
case V_166 :
case V_167 :
case V_140 :
case V_168 :
case V_169 :
V_114 = F_61 ( V_126 , V_31 ,
V_136 , V_35 ) ;
if ( V_114 != V_170 ) {
F_2 ( & V_31 -> V_5 , & V_2 -> V_25 ) ;
break;
}
V_24 -> V_124 . V_171 ++ ;
if ( V_31 -> V_40 -> type == V_168 ) {
F_62 ( V_15 ) ;
V_15 -> V_172 = V_173 ;
}
if ( V_31 == V_24 -> V_174 )
F_63 ( V_15 ) ;
break;
default:
F_49 () ;
}
}
if ( V_2 -> V_24 -> V_139 )
goto V_175;
switch ( V_24 -> V_144 ) {
case V_176 :
if ( ! V_126 || ! V_126 -> V_120 )
break;
case V_177 :
case V_178 :
case V_179 :
if ( ! F_4 ( & V_2 -> V_26 ) ) {
if ( V_24 -> V_41 . V_96 -> V_144 == V_146 )
goto V_175;
if ( V_15 == V_24 -> V_41 . V_96 )
goto V_180;
V_15 = V_24 -> V_41 . V_96 ;
if ( F_4 ( & V_15 -> V_151 ) ) {
F_8 ( & V_15 -> V_151 ,
& V_137 ) ;
}
V_126 = & V_15 -> V_126 ;
F_58 ( V_126 , V_132 ,
V_24 -> V_41 . V_152 ) ;
V_180:
error = F_51 ( V_2 , V_126 ,
V_111 , & V_112 ) ;
if ( error < 0 )
V_24 -> V_37 . V_38 -> V_156 = - error ;
if ( V_112 ) {
F_62 ( V_15 ) ;
V_15 -> V_172 = V_173 ;
}
if ( V_126 -> V_120 )
goto V_175;
if ( ! F_4 ( & V_2 -> V_26 ) )
goto V_175;
}
if ( V_15 )
F_64 ( V_15 ) ;
while ( ( V_31 = F_3 ( V_2 ) ) != NULL ) {
T_1 V_181 = F_65 ( V_31 -> V_59 . V_60 -> V_70 ) ;
if ( V_31 -> V_43 . V_72 >= V_24 -> V_70 -> V_80 ) {
F_20 ( V_31 , V_182 ) ;
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
if ( V_24 -> V_70 -> V_71 [ V_181 ] . V_144 == V_183 ) {
F_1 ( V_2 , V_31 ) ;
goto V_175;
}
V_135 = V_31 -> V_15 ;
if ( ! V_135 ||
( ( V_135 -> V_144 == V_145 ) ||
( V_135 -> V_144 == V_146 ) ||
( V_135 -> V_144 == V_147 ) ) )
V_135 = V_24 -> V_41 . V_143 ;
if ( V_135 -> V_144 == V_146 ) {
F_66 ( 1 , L_6 ) ;
F_20 ( V_31 , 0 ) ;
F_21 ( V_31 ) ;
continue;
}
if ( V_135 != V_15 ) {
V_15 = V_135 ;
if ( F_4 ( & V_15 -> V_151 ) ) {
F_8 ( & V_15 -> V_151 ,
& V_137 ) ;
}
V_126 = & V_15 -> V_126 ;
F_58 ( V_126 , V_132 ,
V_24 -> V_41 . V_152 ) ;
F_64 ( V_15 ) ;
}
F_28 ( L_7
L_8 ,
V_39 , V_2 , V_31 , V_31 && V_31 -> V_40 ?
F_29 ( F_30 ( V_31 -> V_40 -> type ) ) :
L_2 , F_36 ( V_31 -> V_59 . V_60 -> V_20 ) ,
V_31 -> V_8 ? V_31 -> V_8 -> V_52 : NULL , V_31 -> V_8 ?
F_67 ( & V_31 -> V_8 -> V_184 ) : - 1 ) ;
V_114 = F_61 ( V_126 , V_31 , 0 , V_35 ) ;
switch ( V_114 ) {
case V_118 :
case V_121 :
case V_122 :
F_28 ( L_9 ,
V_39 , F_36 ( V_31 -> V_59 . V_60 -> V_20 ) ,
V_114 ) ;
F_1 ( V_2 , V_31 ) ;
goto V_175;
case V_170 :
if ( V_24 -> V_144 == V_178 )
V_31 -> V_40 -> V_46 |= V_185 ;
if ( V_31 -> V_40 -> V_46 & V_47 )
V_24 -> V_124 . V_186 ++ ;
else
V_24 -> V_124 . V_187 ++ ;
break;
default:
F_49 () ;
}
F_8 ( & V_31 -> V_34 ,
& V_15 -> V_33 ) ;
F_62 ( V_15 ) ;
V_15 -> V_172 = V_173 ;
if ( V_126 -> V_120 )
goto V_175;
}
break;
default:
break;
}
V_175:
while ( ( V_138 = F_19 ( & V_137 ) ) != NULL ) {
struct V_13 * V_188 = F_5 ( V_138 ,
struct V_13 ,
V_151 ) ;
V_126 = & V_188 -> V_126 ;
if ( ! F_68 ( V_126 ) ) {
error = F_54 ( V_126 , V_35 ) ;
if ( error < 0 )
V_24 -> V_37 . V_38 -> V_156 = - error ;
}
F_69 ( V_188 ) ;
}
}
static void F_70 ( struct V_23 * V_189 ,
struct V_190 * V_191 )
{
T_7 * V_192 ;
T_6 V_98 ;
int V_133 ;
V_98 = V_189 -> V_193 - V_189 -> V_107 - 1 ;
V_192 = V_191 -> V_194 ;
for ( V_133 = 0 ; V_133 < F_65 ( V_191 -> V_195 ) ; V_133 ++ ) {
V_98 -= ( ( F_65 ( V_192 [ V_133 ] . V_196 . V_197 ) -
F_65 ( V_192 [ V_133 ] . V_196 . V_198 ) + 1 ) ) ;
}
V_189 -> V_98 = V_98 ;
}
int F_71 ( struct V_1 * V_2 , struct V_3 * V_31 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_190 * V_191 = V_31 -> V_59 . V_199 ;
struct V_13 * V_15 ;
struct V_3 * V_200 = NULL ;
struct V_10 * V_29 , * V_137 , * V_30 ;
T_7 * V_192 = V_191 -> V_194 ;
T_1 V_201 , V_202 , V_20 ;
T_1 V_203 , V_204 ;
T_1 V_205 ;
unsigned int V_206 ;
struct V_13 * V_14 = V_24 -> V_41 . V_207 ;
int V_16 = 0 ;
int V_208 ;
T_8 V_209 = 0 ;
V_137 = & V_24 -> V_41 . V_210 ;
V_201 = F_36 ( V_191 -> V_211 ) ;
V_208 = F_65 ( V_191 -> V_195 ) ;
V_24 -> V_124 . V_212 += V_208 ;
if ( V_14 -> V_17 . V_22 ) {
T_8 V_213 = 0 ;
if ( F_72 ( V_14 -> V_17 . V_21 , V_201 ) ) {
V_14 -> V_17 . V_22 = 0 ;
V_213 = 1 ;
}
if ( V_213 || V_208 ) {
F_18 (transport, transport_list,
transports) {
if ( V_213 )
V_15 -> V_17 . V_19 = 0 ;
if ( V_208 )
V_15 -> V_17 . V_18 = 0 ;
}
}
}
V_203 = V_201 ;
if ( V_208 )
V_203 += F_65 ( V_192 [ V_208 - 1 ] . V_196 . V_197 ) ;
if ( F_13 ( V_24 -> V_214 , V_203 ) )
V_24 -> V_214 = V_203 ;
V_204 = V_201 ;
F_73 ( V_2 , & V_2 -> V_26 , NULL , NULL , V_191 , & V_204 ) ;
F_18 (transport, transport_list, transports) {
F_73 ( V_2 , & V_15 -> V_33 ,
V_15 , & V_31 -> V_215 , V_191 ,
& V_204 ) ;
if ( V_15 -> V_17 . V_18 )
V_16 ++ ;
}
if ( F_13 ( V_24 -> V_107 , V_201 ) ) {
V_24 -> V_107 = V_201 ;
V_209 = 1 ;
}
if ( V_208 ) {
if ( V_24 -> V_216 && V_209 )
V_204 = V_203 ;
F_18 (transport, transport_list, transports)
F_74 ( V_2 , & V_15 -> V_33 , V_15 ,
V_204 , V_16 ) ;
}
F_70 ( V_24 , V_191 ) ;
V_202 = V_24 -> V_107 ;
F_22 (lchunk, temp, &q->sacked) {
V_200 = F_5 ( V_29 , struct V_3 ,
V_34 ) ;
V_20 = F_36 ( V_200 -> V_59 . V_60 -> V_20 ) ;
if ( F_72 ( V_20 , V_202 ) ) {
F_6 ( & V_200 -> V_34 ) ;
if ( V_24 -> V_41 . V_42 &&
F_32 ( V_31 -> V_43 . V_44 ) )
V_24 -> V_45 -- ;
F_21 ( V_200 ) ;
}
}
V_205 = F_36 ( V_191 -> V_217 ) ;
V_24 -> V_41 . V_218 = ! V_205 ;
V_206 = V_2 -> V_77 ;
if ( V_206 < V_205 )
V_205 -= V_206 ;
else
V_205 = 0 ;
V_24 -> V_41 . V_83 = V_205 ;
F_50 ( V_2 , V_201 ) ;
F_28 ( L_10 , V_39 , V_201 ) ;
F_28 ( L_11
L_12 , V_39 , V_24 , V_202 ,
V_24 -> V_219 ) ;
return F_75 ( V_2 ) ;
}
int F_75 ( const struct V_1 * V_2 )
{
return V_2 -> V_7 == 0 && V_2 -> V_77 == 0 &&
F_4 ( & V_2 -> V_26 ) ;
}
static void F_73 ( struct V_1 * V_2 ,
struct V_10 * V_220 ,
struct V_13 * V_15 ,
union V_221 * V_222 ,
struct V_190 * V_191 ,
T_1 * V_223 )
{
struct V_10 * V_29 ;
struct V_3 * V_200 ;
struct V_10 V_224 ;
T_1 V_20 ;
T_1 V_201 ;
T_1 V_225 ;
T_3 V_226 = 0 ;
int V_227 = 0 ;
int V_228 = 0 ;
bool V_229 = false ;
V_201 = F_36 ( V_191 -> V_211 ) ;
F_16 ( & V_224 ) ;
while ( NULL != ( V_29 = F_19 ( V_220 ) ) ) {
V_200 = F_5 ( V_29 , struct V_3 ,
V_34 ) ;
if ( F_45 ( V_200 ) ) {
F_35 ( & V_2 -> V_28 , V_29 ) ;
if ( ! V_200 -> V_75 ) {
if ( V_200 -> V_15 )
V_200 -> V_15 -> V_76 -=
F_40 ( V_200 ) ;
V_2 -> V_77 -= F_40 ( V_200 ) ;
}
continue;
}
V_20 = F_36 ( V_200 -> V_59 . V_60 -> V_20 ) ;
if ( F_76 ( V_191 , V_20 ) ) {
if ( V_15 ) {
if ( ! V_200 -> V_75 &&
! F_77 ( V_200 ) &&
V_200 -> V_88 ) {
V_200 -> V_88 = 0 ;
V_225 = V_173 - V_200 -> V_230 ;
F_78 ( V_15 ,
V_225 ) ;
}
}
if ( ! V_200 -> V_75 ) {
V_200 -> V_75 = 1 ;
if ( F_13 ( * V_223 , V_20 ) )
* V_223 = V_20 ;
V_227 += F_40 ( V_200 ) ;
if ( ! V_200 -> V_15 )
V_228 += F_40 ( V_200 ) ;
V_229 = true ;
}
if ( F_72 ( V_20 , V_201 ) ) {
V_226 = 1 ;
V_229 = true ;
if ( ! V_200 -> V_75 ) {
if ( V_15 &&
V_191 -> V_195 &&
V_2 -> V_24 -> V_41 . V_207 -> V_17 .
V_22 )
V_15 -> V_17 . V_18
= 1 ;
}
F_8 ( & V_200 -> V_34 ,
& V_2 -> V_27 ) ;
} else {
F_8 ( V_29 , & V_224 ) ;
}
} else {
if ( V_200 -> V_75 ) {
F_28 ( L_13 ,
V_39 , V_20 ) ;
V_200 -> V_75 = 0 ;
if ( V_200 -> V_15 )
V_227 -= F_40 ( V_200 ) ;
V_226 = 1 ;
}
F_8 ( V_29 , & V_224 ) ;
}
}
if ( V_15 ) {
if ( V_227 ) {
struct V_23 * V_24 = V_15 -> V_24 ;
V_227 -= V_228 ;
V_15 -> V_231 = 0 ;
V_15 -> V_24 -> V_232 = 0 ;
V_229 = true ;
if ( V_24 -> V_144 == V_178 &&
F_79 ( & V_24 -> V_233
[ V_234 ] ) )
F_80 ( V_24 ) ;
if ( ( V_15 -> V_144 == V_145 ||
V_15 -> V_144 == V_146 ) &&
F_56 ( & V_15 -> V_142 , V_222 ) ) {
F_81 (
V_15 -> V_24 ,
V_15 ,
V_235 ,
V_236 ) ;
}
F_82 ( V_15 , V_201 ,
V_227 ) ;
V_15 -> V_76 -= V_227 ;
if ( V_15 -> V_76 == 0 )
V_15 -> V_92 = 0 ;
V_2 -> V_77 -= V_227 + V_228 ;
} else {
if ( ! V_2 -> V_24 -> V_41 . V_83 &&
! F_4 ( & V_224 ) &&
( V_201 + 2 == V_2 -> V_24 -> V_193 ) &&
V_2 -> V_24 -> V_144 < V_178 ) {
F_28 ( L_14
L_15 , V_39 , V_201 ) ;
V_2 -> V_24 -> V_232 = 0 ;
V_15 -> V_231 = 0 ;
}
}
if ( ! V_15 -> V_76 ) {
if ( F_79 ( & V_15 -> V_237 ) )
F_83 ( V_15 ) ;
} else if ( V_226 ) {
if ( ! F_84 ( & V_15 -> V_237 ,
V_173 + V_15 -> V_238 ) )
F_85 ( V_15 ) ;
}
if ( V_229 ) {
if ( V_15 -> V_239 )
F_86 ( V_15 ) ;
}
}
F_87 ( & V_224 , V_220 ) ;
}
static void F_74 ( struct V_1 * V_2 ,
struct V_10 * V_220 ,
struct V_13 * V_15 ,
T_1 V_223 ,
int V_16 )
{
struct V_3 * V_31 ;
T_1 V_20 ;
char V_240 = 0 ;
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_13 * V_14 = V_24 -> V_41 . V_207 ;
F_18 (chunk, transmitted_queue, transmitted_list) {
V_20 = F_36 ( V_31 -> V_59 . V_60 -> V_20 ) ;
if ( V_31 -> V_85 == V_241 &&
! V_31 -> V_75 &&
F_13 ( V_20 , V_223 ) ) {
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
V_240 = 1 ;
}
}
if ( V_15 ) {
if ( V_240 )
F_46 ( V_2 , V_15 , V_84 ) ;
F_28 ( L_17
L_5 , V_39 , V_15 ,
V_15 -> V_90 , V_15 -> V_91 ,
V_15 -> V_76 , V_15 -> V_92 ) ;
}
}
static int F_76 ( struct V_190 * V_191 , T_1 V_20 )
{
int V_133 ;
T_7 * V_192 ;
T_6 V_242 , V_243 ;
T_1 V_202 = F_36 ( V_191 -> V_211 ) ;
if ( F_72 ( V_20 , V_202 ) )
goto V_244;
V_192 = V_191 -> V_194 ;
V_243 = F_65 ( V_191 -> V_195 ) ;
V_242 = V_20 - V_202 ;
for ( V_133 = 0 ; V_133 < V_243 ; ++ V_133 ) {
if ( V_242 >= F_65 ( V_192 [ V_133 ] . V_196 . V_198 ) &&
V_242 <= F_65 ( V_192 [ V_133 ] . V_196 . V_197 ) )
goto V_244;
}
return 0 ;
V_244:
return 1 ;
}
static inline int F_88 ( struct V_245 * V_246 ,
int V_247 , T_9 V_70 )
{
int V_133 ;
for ( V_133 = 0 ; V_133 < V_247 ; V_133 ++ ) {
if ( V_246 [ V_133 ] . V_70 == V_70 )
return V_133 ;
}
return V_133 ;
}
static void F_50 ( struct V_1 * V_2 , T_1 V_202 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_3 * V_248 = NULL ;
struct V_245 V_249 [ 10 ] ;
int V_247 = 0 ;
int V_250 = 0 ;
T_1 V_20 ;
struct V_3 * V_31 ;
struct V_10 * V_29 , * V_30 ;
if ( ! V_24 -> V_41 . V_42 )
return;
if ( F_13 ( V_24 -> V_219 , V_202 ) )
V_24 -> V_219 = V_202 ;
F_22 (lchunk, temp, &q->abandoned) {
V_31 = F_5 ( V_29 , struct V_3 ,
V_34 ) ;
V_20 = F_36 ( V_31 -> V_59 . V_60 -> V_20 ) ;
if ( F_72 ( V_20 , V_202 ) ) {
F_6 ( V_29 ) ;
F_21 ( V_31 ) ;
} else {
if ( F_72 ( V_20 , V_24 -> V_219 + 1 ) ) {
V_24 -> V_219 = V_20 ;
if ( V_31 -> V_40 -> V_46 &
V_47 )
continue;
V_250 = F_88 ( & V_249 [ 0 ] ,
V_247 ,
V_31 -> V_59 . V_60 -> V_70 ) ;
V_249 [ V_250 ] . V_70 =
V_31 -> V_59 . V_60 -> V_70 ;
V_249 [ V_250 ] . V_251 =
V_31 -> V_59 . V_60 -> V_251 ;
if ( V_250 == V_247 )
V_247 ++ ;
if ( V_247 == 10 )
break;
} else
break;
}
}
if ( V_24 -> V_219 > V_202 )
V_248 = F_89 ( V_24 , V_24 -> V_219 ,
V_247 , & V_249 [ 0 ] ) ;
if ( V_248 ) {
F_8 ( & V_248 -> V_5 , & V_2 -> V_25 ) ;
F_33 ( F_27 ( V_24 -> V_37 . V_38 ) , V_50 ) ;
}
}
