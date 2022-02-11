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
if ( ! F_32 ( V_65 -> V_43 . V_44 ) ||
V_65 -> V_43 . V_66 <= V_43 -> V_66 )
continue;
F_6 ( & V_65 -> V_34 ) ;
F_35 ( & V_24 -> V_67 . V_28 ,
& V_65 -> V_34 ) ;
V_24 -> V_45 -- ;
V_24 -> V_68 [ F_39 ( V_69 ) ] ++ ;
if ( ! V_65 -> V_70 ) {
if ( V_65 -> V_15 )
V_65 -> V_15 -> V_71 -=
F_40 ( V_65 ) ;
V_24 -> V_67 . V_72 -= F_40 ( V_65 ) ;
}
V_64 -= F_41 ( V_65 ) +
sizeof( struct V_73 ) +
sizeof( struct V_3 ) ;
if ( V_64 <= 0 )
break;
}
return V_64 ;
}
static int F_42 ( struct V_23 * V_24 ,
struct V_62 * V_43 , int V_64 )
{
struct V_1 * V_2 = & V_24 -> V_67 ;
struct V_3 * V_65 , * V_30 ;
F_23 (chk, temp, &q->out_chunk_list, list) {
if ( ! F_32 ( V_65 -> V_43 . V_44 ) ||
V_65 -> V_43 . V_66 <= V_43 -> V_66 )
continue;
F_6 ( & V_65 -> V_5 ) ;
V_2 -> V_7 -= V_65 -> V_8 -> V_9 ;
V_24 -> V_45 -- ;
V_24 -> V_74 [ F_39 ( V_69 ) ] ++ ;
V_64 -= F_41 ( V_65 ) +
sizeof( struct V_73 ) +
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
& V_24 -> V_67 . V_26 ,
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
T_3 V_75 )
{
struct V_10 * V_29 , * V_76 ;
struct V_3 * V_31 ;
F_22 (lchunk, ltemp, &transport->transmitted) {
V_31 = F_5 ( V_29 , struct V_3 ,
V_34 ) ;
if ( F_45 ( V_31 ) ) {
F_6 ( V_29 ) ;
F_35 ( & V_2 -> V_28 , V_29 ) ;
if ( ! V_31 -> V_70 ) {
if ( V_31 -> V_15 )
V_31 -> V_15 -> V_71 -=
F_40 ( V_31 ) ;
V_2 -> V_72 -= F_40 ( V_31 ) ;
V_2 -> V_24 -> V_41 . V_77 += F_40 ( V_31 ) ;
}
continue;
}
if ( ( V_75 == V_78 &&
( V_31 -> V_79 == V_80 ) ) ||
( V_75 != V_78 && ! V_31 -> V_70 ) ) {
V_2 -> V_24 -> V_41 . V_77 += F_40 ( V_31 ) ;
V_2 -> V_72 -= F_40 ( V_31 ) ;
if ( V_31 -> V_15 )
V_15 -> V_71 -= F_40 ( V_31 ) ;
V_31 -> V_81 = 0 ;
if ( V_31 -> V_82 ) {
V_31 -> V_82 = 0 ;
V_15 -> V_83 = 0 ;
}
F_6 ( V_29 ) ;
F_35 ( & V_2 -> V_26 , V_29 ) ;
}
}
F_28 ( L_4
L_5 , V_39 , V_15 , V_75 ,
V_15 -> V_84 , V_15 -> V_85 , V_15 -> V_71 ,
V_15 -> V_86 ) ;
}
void F_46 ( struct V_1 * V_2 , struct V_13 * V_15 ,
T_4 V_75 )
{
struct V_36 * V_36 = F_27 ( V_2 -> V_24 -> V_37 . V_38 ) ;
switch ( V_75 ) {
case V_87 :
F_33 ( V_36 , V_88 ) ;
F_47 ( V_15 , V_89 ) ;
if ( V_15 == V_15 -> V_24 -> V_41 . V_90 )
F_48 ( V_15 -> V_24 ) ;
V_15 -> V_24 -> V_91 +=
V_15 -> V_24 -> V_92 ;
break;
case V_78 :
F_33 ( V_36 , V_93 ) ;
F_47 ( V_15 , V_94 ) ;
V_2 -> V_95 = 1 ;
break;
case V_96 :
F_33 ( V_36 , V_97 ) ;
break;
case V_98 :
F_33 ( V_36 , V_99 ) ;
V_15 -> V_24 -> V_100 ++ ;
break;
default:
F_49 () ;
}
F_44 ( V_2 , V_15 , V_75 ) ;
if ( V_75 == V_87 )
F_50 ( V_2 , V_2 -> V_24 -> V_101 ) ;
if ( V_75 != V_78 )
F_34 ( V_2 , 1 , V_102 ) ;
}
static int F_51 ( struct V_1 * V_2 , struct V_103 * V_104 ,
int V_105 , int * V_106 )
{
struct V_10 * V_107 ;
struct V_13 * V_15 = V_104 -> V_15 ;
T_5 V_108 ;
struct V_3 * V_31 , * V_109 ;
int V_95 ;
int error = 0 ;
int V_110 = 0 ;
int V_58 = 0 ;
V_107 = & V_2 -> V_26 ;
V_95 = V_2 -> V_95 ;
F_23 (chunk, chunk1, lqueue, transmitted_list) {
if ( F_45 ( V_31 ) ) {
F_6 ( & V_31 -> V_34 ) ;
F_35 ( & V_2 -> V_28 ,
& V_31 -> V_34 ) ;
continue;
}
if ( V_31 -> V_70 ) {
F_52 ( & V_31 -> V_34 ,
& V_15 -> V_33 ) ;
continue;
}
if ( V_95 && ! V_31 -> V_79 )
continue;
V_111:
V_108 = F_53 ( V_104 , V_31 ) ;
switch ( V_108 ) {
case V_112 :
if ( ! V_104 -> V_113 && ! V_104 -> V_114 ) {
F_54 ( V_104 , V_102 ) ;
goto V_111;
}
error = F_54 ( V_104 , V_102 ) ;
if ( V_105 || V_95 )
V_58 = 1 ;
else
goto V_111;
break;
case V_115 :
error = F_54 ( V_104 , V_102 ) ;
V_58 = 1 ;
break;
case V_116 :
error = F_54 ( V_104 , V_102 ) ;
V_58 = 1 ;
break;
default:
F_52 ( & V_31 -> V_34 ,
& V_15 -> V_33 ) ;
if ( V_31 -> V_79 == V_80 )
V_31 -> V_79 = V_117 ;
V_2 -> V_24 -> V_118 . V_119 ++ ;
break;
}
if ( ! error && ! V_110 )
V_110 = 1 ;
if ( V_58 )
break;
}
if ( V_105 || V_95 ) {
F_18 (chunk1, lqueue, transmitted_list) {
if ( V_109 -> V_79 == V_80 )
V_109 -> V_79 = V_117 ;
}
}
* V_106 = V_110 ;
if ( V_95 )
V_2 -> V_95 = 0 ;
return error ;
}
void F_55 ( struct V_1 * V_2 , T_2 V_35 )
{
if ( V_2 -> V_51 )
V_2 -> V_51 = 0 ;
F_34 ( V_2 , 0 , V_35 ) ;
}
static void F_34 ( struct V_1 * V_2 , int V_105 , T_2 V_35 )
{
struct V_103 * V_120 ;
struct V_103 V_121 ;
struct V_23 * V_24 = V_2 -> V_24 ;
T_6 V_122 = V_24 -> V_37 . V_123 . V_124 ;
T_6 V_125 = V_24 -> V_41 . V_124 ;
T_1 V_126 = V_24 -> V_41 . V_127 . V_128 ;
struct V_13 * V_15 = NULL ;
struct V_13 * V_129 ;
struct V_3 * V_31 , * V_32 ;
T_5 V_108 ;
int error = 0 ;
int V_106 = 0 ;
int V_130 = 0 ;
struct V_10 V_131 ;
struct V_10 * V_132 ;
F_16 ( & V_131 ) ;
V_120 = NULL ;
F_23 (chunk, tmp, &q->control_chunk_list, list) {
if ( V_24 -> V_133 &&
V_31 -> V_40 -> type != V_134 )
continue;
F_6 ( & V_31 -> V_5 ) ;
V_129 = V_31 -> V_15 ;
if ( ! V_129 ) {
if ( V_15 &&
F_56 ( & V_31 -> V_135 ,
& V_15 -> V_136 ) )
V_129 = V_15 ;
else
V_129 = F_57 ( V_24 ,
& V_31 -> V_135 ) ;
if ( ! V_129 )
V_129 = V_24 -> V_41 . V_137 ;
} else if ( ( V_129 -> V_138 == V_139 ) ||
( V_129 -> V_138 == V_140 ) ||
( V_129 -> V_138 == V_141 ) ) {
if ( V_31 -> V_40 -> type != V_142 &&
V_31 -> V_40 -> type != V_143 &&
V_31 -> V_40 -> type != V_144 )
V_129 = V_24 -> V_41 . V_137 ;
}
if ( V_129 != V_15 ) {
V_15 = V_129 ;
if ( F_4 ( & V_15 -> V_145 ) ) {
F_8 ( & V_15 -> V_145 ,
& V_131 ) ;
}
V_120 = & V_15 -> V_120 ;
F_58 ( V_120 , V_126 ,
V_24 -> V_41 . V_146 ) ;
}
switch ( V_31 -> V_40 -> type ) {
case V_147 :
case V_148 :
case V_149 :
F_59 ( & V_121 , V_15 , V_122 , V_125 ) ;
F_58 ( & V_121 , V_126 , 0 ) ;
F_53 ( & V_121 , V_31 ) ;
error = F_54 ( & V_121 , V_35 ) ;
if ( error < 0 ) {
V_24 -> V_37 . V_38 -> V_150 = - error ;
return;
}
break;
case V_151 :
if ( F_60 ( V_31 ) ) {
V_120 -> V_126 = V_24 -> V_152 . V_153 ;
}
case V_143 :
case V_154 :
case V_155 :
case V_156 :
case V_157 :
case V_158 :
case V_144 :
V_130 = 1 ;
case V_159 :
case V_142 :
case V_160 :
case V_161 :
case V_134 :
case V_162 :
case V_163 :
V_108 = F_61 ( V_120 , V_31 ,
V_130 , V_35 ) ;
if ( V_108 != V_164 ) {
F_2 ( & V_31 -> V_5 , & V_2 -> V_25 ) ;
break;
}
V_24 -> V_118 . V_165 ++ ;
if ( V_31 -> V_40 -> type == V_162 ) {
F_62 ( V_15 ) ;
V_15 -> V_166 = V_167 ;
}
if ( V_31 == V_24 -> V_168 )
F_63 ( V_15 ) ;
break;
default:
F_49 () ;
}
}
if ( V_2 -> V_24 -> V_133 )
goto V_169;
switch ( V_24 -> V_138 ) {
case V_170 :
if ( ! V_120 || ! V_120 -> V_114 )
break;
case V_171 :
case V_172 :
case V_173 :
if ( ! F_4 ( & V_2 -> V_26 ) ) {
if ( V_24 -> V_41 . V_90 -> V_138 == V_140 )
goto V_169;
if ( V_15 == V_24 -> V_41 . V_90 )
goto V_174;
V_15 = V_24 -> V_41 . V_90 ;
if ( F_4 ( & V_15 -> V_145 ) ) {
F_8 ( & V_15 -> V_145 ,
& V_131 ) ;
}
V_120 = & V_15 -> V_120 ;
F_58 ( V_120 , V_126 ,
V_24 -> V_41 . V_146 ) ;
V_174:
error = F_51 ( V_2 , V_120 ,
V_105 , & V_106 ) ;
if ( error < 0 )
V_24 -> V_37 . V_38 -> V_150 = - error ;
if ( V_106 ) {
F_62 ( V_15 ) ;
V_15 -> V_166 = V_167 ;
}
if ( V_120 -> V_114 )
goto V_169;
if ( ! F_4 ( & V_2 -> V_26 ) )
goto V_169;
}
if ( V_15 )
F_64 ( V_15 ) ;
while ( ( V_31 = F_3 ( V_2 ) ) != NULL ) {
T_1 V_175 = F_65 ( V_31 -> V_59 . V_60 -> V_176 ) ;
if ( V_31 -> V_43 . V_177 >= V_24 -> V_176 -> V_178 ) {
F_20 ( V_31 , V_179 ) ;
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
if ( V_24 -> V_176 -> V_180 [ V_175 ] . V_138 == V_181 ) {
F_1 ( V_2 , V_31 ) ;
goto V_169;
}
V_129 = V_31 -> V_15 ;
if ( ! V_129 ||
( ( V_129 -> V_138 == V_139 ) ||
( V_129 -> V_138 == V_140 ) ||
( V_129 -> V_138 == V_141 ) ) )
V_129 = V_24 -> V_41 . V_137 ;
if ( V_129 -> V_138 == V_140 ) {
F_66 ( 1 , L_6 ) ;
F_20 ( V_31 , 0 ) ;
F_21 ( V_31 ) ;
continue;
}
if ( V_129 != V_15 ) {
V_15 = V_129 ;
if ( F_4 ( & V_15 -> V_145 ) ) {
F_8 ( & V_15 -> V_145 ,
& V_131 ) ;
}
V_120 = & V_15 -> V_120 ;
F_58 ( V_120 , V_126 ,
V_24 -> V_41 . V_146 ) ;
F_64 ( V_15 ) ;
}
F_28 ( L_7
L_8 ,
V_39 , V_2 , V_31 , V_31 && V_31 -> V_40 ?
F_29 ( F_30 ( V_31 -> V_40 -> type ) ) :
L_2 , F_36 ( V_31 -> V_59 . V_60 -> V_20 ) ,
V_31 -> V_8 ? V_31 -> V_8 -> V_52 : NULL , V_31 -> V_8 ?
F_67 ( & V_31 -> V_8 -> V_182 ) : - 1 ) ;
V_108 = F_61 ( V_120 , V_31 , 0 , V_35 ) ;
switch ( V_108 ) {
case V_112 :
case V_115 :
case V_116 :
F_28 ( L_9 ,
V_39 , F_36 ( V_31 -> V_59 . V_60 -> V_20 ) ,
V_108 ) ;
F_1 ( V_2 , V_31 ) ;
goto V_169;
case V_164 :
if ( V_24 -> V_138 == V_172 )
V_31 -> V_40 -> V_46 |= V_183 ;
if ( V_31 -> V_40 -> V_46 & V_47 )
V_24 -> V_118 . V_184 ++ ;
else
V_24 -> V_118 . V_185 ++ ;
break;
default:
F_49 () ;
}
F_8 ( & V_31 -> V_34 ,
& V_15 -> V_33 ) ;
F_62 ( V_15 ) ;
V_15 -> V_166 = V_167 ;
if ( V_120 -> V_114 )
goto V_169;
}
break;
default:
break;
}
V_169:
while ( ( V_132 = F_19 ( & V_131 ) ) != NULL ) {
struct V_13 * V_186 = F_5 ( V_132 ,
struct V_13 ,
V_145 ) ;
V_120 = & V_186 -> V_120 ;
if ( ! F_68 ( V_120 ) ) {
error = F_54 ( V_120 , V_35 ) ;
if ( error < 0 )
V_24 -> V_37 . V_38 -> V_150 = - error ;
}
F_69 ( V_186 ) ;
}
}
static void F_70 ( struct V_23 * V_187 ,
struct V_188 * V_189 )
{
T_7 * V_190 ;
T_6 V_92 ;
int V_127 ;
V_92 = V_187 -> V_191 - V_187 -> V_101 - 1 ;
V_190 = V_189 -> V_192 ;
for ( V_127 = 0 ; V_127 < F_65 ( V_189 -> V_193 ) ; V_127 ++ ) {
V_92 -= ( ( F_65 ( V_190 [ V_127 ] . V_194 . V_195 ) -
F_65 ( V_190 [ V_127 ] . V_194 . V_196 ) + 1 ) ) ;
}
V_187 -> V_92 = V_92 ;
}
int F_71 ( struct V_1 * V_2 , struct V_3 * V_31 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_188 * V_189 = V_31 -> V_59 . V_197 ;
struct V_13 * V_15 ;
struct V_3 * V_198 = NULL ;
struct V_10 * V_29 , * V_131 , * V_30 ;
T_7 * V_190 = V_189 -> V_192 ;
T_1 V_199 , V_200 , V_20 ;
T_1 V_201 , V_202 ;
T_1 V_203 ;
unsigned int V_204 ;
struct V_13 * V_14 = V_24 -> V_41 . V_205 ;
int V_16 = 0 ;
int V_206 ;
T_8 V_207 = 0 ;
V_131 = & V_24 -> V_41 . V_208 ;
V_199 = F_36 ( V_189 -> V_209 ) ;
V_206 = F_65 ( V_189 -> V_193 ) ;
V_24 -> V_118 . V_210 += V_206 ;
if ( V_14 -> V_17 . V_22 ) {
T_8 V_211 = 0 ;
if ( F_72 ( V_14 -> V_17 . V_21 , V_199 ) ) {
V_14 -> V_17 . V_22 = 0 ;
V_211 = 1 ;
}
if ( V_211 || V_206 ) {
F_18 (transport, transport_list,
transports) {
if ( V_211 )
V_15 -> V_17 . V_19 = 0 ;
if ( V_206 )
V_15 -> V_17 . V_18 = 0 ;
}
}
}
V_201 = V_199 ;
if ( V_206 )
V_201 += F_65 ( V_190 [ V_206 - 1 ] . V_194 . V_195 ) ;
if ( F_13 ( V_24 -> V_212 , V_201 ) )
V_24 -> V_212 = V_201 ;
V_202 = V_199 ;
F_73 ( V_2 , & V_2 -> V_26 , NULL , NULL , V_189 , & V_202 ) ;
F_18 (transport, transport_list, transports) {
F_73 ( V_2 , & V_15 -> V_33 ,
V_15 , & V_31 -> V_213 , V_189 ,
& V_202 ) ;
if ( V_15 -> V_17 . V_18 )
V_16 ++ ;
}
if ( F_13 ( V_24 -> V_101 , V_199 ) ) {
V_24 -> V_101 = V_199 ;
V_207 = 1 ;
}
if ( V_206 ) {
if ( V_24 -> V_214 && V_207 )
V_202 = V_201 ;
F_18 (transport, transport_list, transports)
F_74 ( V_2 , & V_15 -> V_33 , V_15 ,
V_202 , V_16 ) ;
}
F_70 ( V_24 , V_189 ) ;
V_200 = V_24 -> V_101 ;
F_22 (lchunk, temp, &q->sacked) {
V_198 = F_5 ( V_29 , struct V_3 ,
V_34 ) ;
V_20 = F_36 ( V_198 -> V_59 . V_60 -> V_20 ) ;
if ( F_72 ( V_20 , V_200 ) ) {
F_6 ( & V_198 -> V_34 ) ;
if ( V_24 -> V_41 . V_42 &&
F_32 ( V_31 -> V_43 . V_44 ) )
V_24 -> V_45 -- ;
F_21 ( V_198 ) ;
}
}
V_203 = F_36 ( V_189 -> V_215 ) ;
V_24 -> V_41 . V_216 = ! V_203 ;
V_204 = V_2 -> V_72 ;
if ( V_204 < V_203 )
V_203 -= V_204 ;
else
V_203 = 0 ;
V_24 -> V_41 . V_77 = V_203 ;
F_50 ( V_2 , V_199 ) ;
F_28 ( L_10 , V_39 , V_199 ) ;
F_28 ( L_11
L_12 , V_39 , V_24 , V_200 ,
V_24 -> V_217 ) ;
return F_75 ( V_2 ) ;
}
int F_75 ( const struct V_1 * V_2 )
{
return V_2 -> V_7 == 0 && V_2 -> V_72 == 0 &&
F_4 ( & V_2 -> V_26 ) ;
}
static void F_73 ( struct V_1 * V_2 ,
struct V_10 * V_218 ,
struct V_13 * V_15 ,
union V_219 * V_220 ,
struct V_188 * V_189 ,
T_1 * V_221 )
{
struct V_10 * V_29 ;
struct V_3 * V_198 ;
struct V_10 V_222 ;
T_1 V_20 ;
T_1 V_199 ;
T_1 V_223 ;
T_3 V_224 = 0 ;
int V_225 = 0 ;
int V_226 = 0 ;
bool V_227 = false ;
V_199 = F_36 ( V_189 -> V_209 ) ;
F_16 ( & V_222 ) ;
while ( NULL != ( V_29 = F_19 ( V_218 ) ) ) {
V_198 = F_5 ( V_29 , struct V_3 ,
V_34 ) ;
if ( F_45 ( V_198 ) ) {
F_35 ( & V_2 -> V_28 , V_29 ) ;
if ( ! V_198 -> V_70 ) {
if ( V_198 -> V_15 )
V_198 -> V_15 -> V_71 -=
F_40 ( V_198 ) ;
V_2 -> V_72 -= F_40 ( V_198 ) ;
}
continue;
}
V_20 = F_36 ( V_198 -> V_59 . V_60 -> V_20 ) ;
if ( F_76 ( V_189 , V_20 ) ) {
if ( V_15 ) {
if ( ! V_198 -> V_70 &&
! F_77 ( V_198 ) &&
V_198 -> V_82 ) {
V_198 -> V_82 = 0 ;
V_223 = V_167 - V_198 -> V_228 ;
F_78 ( V_15 ,
V_223 ) ;
}
}
if ( ! V_198 -> V_70 ) {
V_198 -> V_70 = 1 ;
if ( F_13 ( * V_221 , V_20 ) )
* V_221 = V_20 ;
V_225 += F_40 ( V_198 ) ;
if ( ! V_198 -> V_15 )
V_226 += F_40 ( V_198 ) ;
V_227 = true ;
}
if ( F_72 ( V_20 , V_199 ) ) {
V_224 = 1 ;
V_227 = true ;
if ( ! V_198 -> V_70 ) {
if ( V_15 &&
V_189 -> V_193 &&
V_2 -> V_24 -> V_41 . V_205 -> V_17 .
V_22 )
V_15 -> V_17 . V_18
= 1 ;
}
F_8 ( & V_198 -> V_34 ,
& V_2 -> V_27 ) ;
} else {
F_8 ( V_29 , & V_222 ) ;
}
} else {
if ( V_198 -> V_70 ) {
F_28 ( L_13 ,
V_39 , V_20 ) ;
V_198 -> V_70 = 0 ;
if ( V_198 -> V_15 )
V_225 -= F_40 ( V_198 ) ;
V_224 = 1 ;
}
F_8 ( V_29 , & V_222 ) ;
}
}
if ( V_15 ) {
if ( V_225 ) {
struct V_23 * V_24 = V_15 -> V_24 ;
V_225 -= V_226 ;
V_15 -> V_229 = 0 ;
V_15 -> V_24 -> V_230 = 0 ;
V_227 = true ;
if ( V_24 -> V_138 == V_172 &&
F_79 ( & V_24 -> V_231
[ V_232 ] ) )
F_80 ( V_24 ) ;
if ( ( V_15 -> V_138 == V_139 ||
V_15 -> V_138 == V_140 ) &&
F_56 ( & V_15 -> V_136 , V_220 ) ) {
F_81 (
V_15 -> V_24 ,
V_15 ,
V_233 ,
V_234 ) ;
}
F_82 ( V_15 , V_199 ,
V_225 ) ;
V_15 -> V_71 -= V_225 ;
if ( V_15 -> V_71 == 0 )
V_15 -> V_86 = 0 ;
V_2 -> V_72 -= V_225 + V_226 ;
} else {
if ( ! V_2 -> V_24 -> V_41 . V_77 &&
! F_4 ( & V_222 ) &&
( V_199 + 2 == V_2 -> V_24 -> V_191 ) &&
V_2 -> V_24 -> V_138 < V_172 ) {
F_28 ( L_14
L_15 , V_39 , V_199 ) ;
V_2 -> V_24 -> V_230 = 0 ;
V_15 -> V_229 = 0 ;
}
}
if ( ! V_15 -> V_71 ) {
if ( F_79 ( & V_15 -> V_235 ) )
F_83 ( V_15 ) ;
} else if ( V_224 ) {
if ( ! F_84 ( & V_15 -> V_235 ,
V_167 + V_15 -> V_236 ) )
F_85 ( V_15 ) ;
}
if ( V_227 ) {
if ( V_15 -> V_237 )
F_86 ( V_15 ) ;
}
}
F_87 ( & V_222 , V_218 ) ;
}
static void F_74 ( struct V_1 * V_2 ,
struct V_10 * V_218 ,
struct V_13 * V_15 ,
T_1 V_221 ,
int V_16 )
{
struct V_3 * V_31 ;
T_1 V_20 ;
char V_238 = 0 ;
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_13 * V_14 = V_24 -> V_41 . V_205 ;
F_18 (chunk, transmitted_queue, transmitted_list) {
V_20 = F_36 ( V_31 -> V_59 . V_60 -> V_20 ) ;
if ( V_31 -> V_79 == V_239 &&
! V_31 -> V_70 &&
F_13 ( V_20 , V_221 ) ) {
if ( ! V_15 || ! F_14 ( V_14 ,
V_31 -> V_15 ,
V_16 , V_20 ) ) {
V_31 -> V_81 ++ ;
F_28 ( L_16 ,
V_39 , V_20 , V_31 -> V_81 ) ;
}
}
if ( V_31 -> V_81 >= 3 ) {
V_31 -> V_79 = V_80 ;
V_238 = 1 ;
}
}
if ( V_15 ) {
if ( V_238 )
F_46 ( V_2 , V_15 , V_78 ) ;
F_28 ( L_17
L_5 , V_39 , V_15 ,
V_15 -> V_84 , V_15 -> V_85 ,
V_15 -> V_71 , V_15 -> V_86 ) ;
}
}
static int F_76 ( struct V_188 * V_189 , T_1 V_20 )
{
int V_127 ;
T_7 * V_190 ;
T_6 V_240 , V_241 ;
T_1 V_200 = F_36 ( V_189 -> V_209 ) ;
if ( F_72 ( V_20 , V_200 ) )
goto V_242;
V_190 = V_189 -> V_192 ;
V_241 = F_65 ( V_189 -> V_193 ) ;
V_240 = V_20 - V_200 ;
for ( V_127 = 0 ; V_127 < V_241 ; ++ V_127 ) {
if ( V_240 >= F_65 ( V_190 [ V_127 ] . V_194 . V_196 ) &&
V_240 <= F_65 ( V_190 [ V_127 ] . V_194 . V_195 ) )
goto V_242;
}
return 0 ;
V_242:
return 1 ;
}
static inline int F_88 ( struct V_243 * V_244 ,
int V_245 , T_9 V_176 )
{
int V_127 ;
for ( V_127 = 0 ; V_127 < V_245 ; V_127 ++ ) {
if ( V_244 [ V_127 ] . V_176 == V_176 )
return V_127 ;
}
return V_127 ;
}
static void F_50 ( struct V_1 * V_2 , T_1 V_200 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_3 * V_246 = NULL ;
struct V_243 V_247 [ 10 ] ;
int V_245 = 0 ;
int V_248 = 0 ;
T_1 V_20 ;
struct V_3 * V_31 ;
struct V_10 * V_29 , * V_30 ;
if ( ! V_24 -> V_41 . V_42 )
return;
if ( F_13 ( V_24 -> V_217 , V_200 ) )
V_24 -> V_217 = V_200 ;
F_22 (lchunk, temp, &q->abandoned) {
V_31 = F_5 ( V_29 , struct V_3 ,
V_34 ) ;
V_20 = F_36 ( V_31 -> V_59 . V_60 -> V_20 ) ;
if ( F_72 ( V_20 , V_200 ) ) {
F_6 ( V_29 ) ;
F_21 ( V_31 ) ;
} else {
if ( F_72 ( V_20 , V_24 -> V_217 + 1 ) ) {
V_24 -> V_217 = V_20 ;
if ( V_31 -> V_40 -> V_46 &
V_47 )
continue;
V_248 = F_88 ( & V_247 [ 0 ] ,
V_245 ,
V_31 -> V_59 . V_60 -> V_176 ) ;
V_247 [ V_248 ] . V_176 =
V_31 -> V_59 . V_60 -> V_176 ;
V_247 [ V_248 ] . V_249 =
V_31 -> V_59 . V_60 -> V_249 ;
if ( V_248 == V_245 )
V_245 ++ ;
if ( V_245 == 10 )
break;
} else
break;
}
}
if ( V_24 -> V_217 > V_200 )
V_246 = F_89 ( V_24 , V_24 -> V_217 ,
V_245 , & V_247 [ 0 ] ) ;
if ( V_246 ) {
F_8 ( & V_246 -> V_5 , & V_2 -> V_25 ) ;
F_33 ( F_27 ( V_24 -> V_37 . V_38 ) , V_50 ) ;
}
}
