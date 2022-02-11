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
if ( V_31 -> V_24 -> V_48 . V_49 &&
F_33 ( V_31 -> V_50 . V_51 ) )
V_31 -> V_24 -> V_52 ++ ;
if ( V_31 -> V_40 -> V_53 & V_54 )
F_34 ( V_36 , V_55 ) ;
else
F_34 ( V_36 , V_56 ) ;
break;
}
} else {
F_8 ( & V_31 -> V_5 , & V_2 -> V_25 ) ;
F_34 ( V_36 , V_57 ) ;
}
if ( error < 0 )
return error ;
if ( ! V_2 -> V_58 )
error = F_35 ( V_2 , 0 , V_35 ) ;
return error ;
}
static void F_36 ( struct V_10 * V_59 , struct V_10 * V_60 )
{
struct V_10 * V_61 ;
struct V_3 * V_62 , * V_29 ;
T_1 V_63 , V_64 ;
int V_65 = 0 ;
V_62 = F_5 ( V_60 , struct V_3 , V_34 ) ;
V_63 = F_37 ( V_62 -> V_66 . V_67 -> V_20 ) ;
F_38 (pos, head) {
V_29 = F_5 ( V_61 , struct V_3 , V_34 ) ;
V_64 = F_37 ( V_29 -> V_66 . V_67 -> V_20 ) ;
if ( F_13 ( V_63 , V_64 ) ) {
F_2 ( V_60 , V_61 -> V_68 ) ;
V_65 = 1 ;
break;
}
}
if ( ! V_65 )
F_8 ( V_60 , V_59 ) ;
}
static int F_39 ( struct V_23 * V_24 ,
struct V_69 * V_50 ,
struct V_10 * V_70 , int V_71 )
{
struct V_3 * V_72 , * V_30 ;
F_23 (chk, temp, queue, transmitted_list) {
if ( ! F_33 ( V_72 -> V_50 . V_51 ) ||
V_72 -> V_50 . V_73 <= V_50 -> V_73 )
continue;
F_6 ( & V_72 -> V_34 ) ;
F_36 ( & V_24 -> V_74 . V_28 ,
& V_72 -> V_34 ) ;
V_24 -> V_52 -- ;
V_24 -> V_75 [ F_40 ( V_76 ) ] ++ ;
if ( ! V_72 -> V_77 ) {
if ( V_72 -> V_15 )
V_72 -> V_15 -> V_78 -=
F_41 ( V_72 ) ;
V_24 -> V_74 . V_79 -= F_41 ( V_72 ) ;
}
V_71 -= F_42 ( V_72 ) +
sizeof( struct V_80 ) +
sizeof( struct V_3 ) ;
if ( V_71 <= 0 )
break;
}
return V_71 ;
}
static int F_43 ( struct V_23 * V_24 ,
struct V_69 * V_50 ,
struct V_10 * V_70 , int V_71 )
{
struct V_3 * V_72 , * V_30 ;
F_23 (chk, temp, queue, list) {
if ( ! F_33 ( V_72 -> V_50 . V_51 ) ||
V_72 -> V_50 . V_73 <= V_50 -> V_73 )
continue;
F_6 ( & V_72 -> V_5 ) ;
V_24 -> V_52 -- ;
V_24 -> V_81 [ F_40 ( V_76 ) ] ++ ;
V_71 -= F_42 ( V_72 ) +
sizeof( struct V_80 ) +
sizeof( struct V_3 ) ;
F_21 ( V_72 ) ;
if ( V_71 <= 0 )
break;
}
return V_71 ;
}
void F_44 ( struct V_23 * V_24 ,
struct V_69 * V_50 , int V_71 )
{
struct V_13 * V_15 ;
if ( ! V_24 -> V_48 . V_49 || ! V_24 -> V_52 )
return;
V_71 = F_39 ( V_24 , V_50 ,
& V_24 -> V_74 . V_26 ,
V_71 ) ;
if ( V_71 <= 0 )
return;
F_18 (transport, &asoc->peer.transport_addr_list,
transports) {
V_71 = F_39 ( V_24 , V_50 ,
& V_15 -> V_33 ,
V_71 ) ;
if ( V_71 <= 0 )
return;
}
F_43 ( V_24 , V_50 ,
& V_24 -> V_74 . V_6 ,
V_71 ) ;
}
void F_45 ( struct V_1 * V_2 ,
struct V_13 * V_15 ,
T_3 V_82 )
{
struct V_10 * V_29 , * V_83 ;
struct V_3 * V_31 ;
F_22 (lchunk, ltemp, &transport->transmitted) {
V_31 = F_5 ( V_29 , struct V_3 ,
V_34 ) ;
if ( F_46 ( V_31 ) ) {
F_6 ( V_29 ) ;
F_36 ( & V_2 -> V_28 , V_29 ) ;
if ( ! V_31 -> V_77 ) {
if ( V_31 -> V_15 )
V_31 -> V_15 -> V_78 -=
F_41 ( V_31 ) ;
V_2 -> V_79 -= F_41 ( V_31 ) ;
V_2 -> V_24 -> V_48 . V_84 += F_41 ( V_31 ) ;
}
continue;
}
if ( ( V_82 == V_85 &&
( V_31 -> V_86 == V_87 ) ) ||
( V_82 != V_85 && ! V_31 -> V_77 ) ) {
V_2 -> V_24 -> V_48 . V_84 += F_41 ( V_31 ) ;
V_2 -> V_79 -= F_41 ( V_31 ) ;
if ( V_31 -> V_15 )
V_15 -> V_78 -= F_41 ( V_31 ) ;
V_31 -> V_88 = 0 ;
if ( V_31 -> V_89 ) {
V_31 -> V_89 = 0 ;
V_15 -> V_90 = 0 ;
}
V_31 -> V_91 = 1 ;
F_6 ( V_29 ) ;
F_36 ( & V_2 -> V_26 , V_29 ) ;
}
}
F_28 ( L_4
L_5 , V_39 , V_15 , V_82 ,
V_15 -> V_92 , V_15 -> V_93 , V_15 -> V_78 ,
V_15 -> V_94 ) ;
}
void F_47 ( struct V_1 * V_2 , struct V_13 * V_15 ,
T_4 V_82 )
{
struct V_36 * V_36 = F_27 ( V_2 -> V_24 -> V_37 . V_38 ) ;
int error = 0 ;
switch ( V_82 ) {
case V_95 :
F_34 ( V_36 , V_96 ) ;
F_48 ( V_15 , V_97 ) ;
if ( V_15 == V_15 -> V_24 -> V_48 . V_98 )
F_49 ( V_15 -> V_24 ) ;
V_15 -> V_24 -> V_99 +=
V_15 -> V_24 -> V_100 ;
break;
case V_85 :
F_34 ( V_36 , V_101 ) ;
F_48 ( V_15 , V_102 ) ;
V_2 -> V_103 = 1 ;
break;
case V_104 :
F_34 ( V_36 , V_105 ) ;
break;
case V_106 :
F_34 ( V_36 , V_107 ) ;
V_15 -> V_24 -> V_108 ++ ;
break;
default:
F_50 () ;
}
F_45 ( V_2 , V_15 , V_82 ) ;
if ( V_82 == V_95 )
F_51 ( V_2 , V_2 -> V_24 -> V_109 ) ;
if ( V_82 != V_85 )
error = F_35 ( V_2 , 1 , V_110 ) ;
if ( error )
V_2 -> V_24 -> V_37 . V_38 -> V_111 = - error ;
}
static int F_52 ( struct V_1 * V_2 , struct V_112 * V_113 ,
int V_114 , int * V_115 )
{
struct V_10 * V_116 ;
struct V_13 * V_15 = V_113 -> V_15 ;
T_5 V_117 ;
struct V_3 * V_31 , * V_118 ;
int V_103 ;
int error = 0 ;
int V_119 = 0 ;
int V_65 = 0 ;
V_116 = & V_2 -> V_26 ;
V_103 = V_2 -> V_103 ;
F_23 (chunk, chunk1, lqueue, transmitted_list) {
if ( F_46 ( V_31 ) ) {
F_6 ( & V_31 -> V_34 ) ;
F_36 ( & V_2 -> V_28 ,
& V_31 -> V_34 ) ;
continue;
}
if ( V_31 -> V_77 ) {
F_53 ( & V_31 -> V_34 ,
& V_15 -> V_33 ) ;
continue;
}
if ( V_103 && ! V_31 -> V_86 )
continue;
V_120:
V_117 = F_54 ( V_113 , V_31 ) ;
switch ( V_117 ) {
case V_121 :
if ( ! V_113 -> V_122 && ! V_113 -> V_123 ) {
F_55 ( V_113 , V_110 ) ;
goto V_120;
}
error = F_55 ( V_113 , V_110 ) ;
if ( V_114 || V_103 )
V_65 = 1 ;
else
goto V_120;
break;
case V_124 :
error = F_55 ( V_113 , V_110 ) ;
V_65 = 1 ;
break;
case V_125 :
error = F_55 ( V_113 , V_110 ) ;
V_65 = 1 ;
break;
default:
F_53 ( & V_31 -> V_34 ,
& V_15 -> V_33 ) ;
if ( V_31 -> V_86 == V_87 )
V_31 -> V_86 = V_126 ;
V_2 -> V_24 -> V_127 . V_128 ++ ;
break;
}
if ( ! error && ! V_119 )
V_119 = 1 ;
if ( V_65 )
break;
}
if ( V_114 || V_103 ) {
F_18 (chunk1, lqueue, transmitted_list) {
if ( V_118 -> V_86 == V_87 )
V_118 -> V_86 = V_126 ;
}
}
* V_115 = V_119 ;
if ( V_103 )
V_2 -> V_103 = 0 ;
return error ;
}
int F_56 ( struct V_1 * V_2 , T_2 V_35 )
{
if ( V_2 -> V_58 )
V_2 -> V_58 = 0 ;
return F_35 ( V_2 , 0 , V_35 ) ;
}
static int F_35 ( struct V_1 * V_2 , int V_114 , T_2 V_35 )
{
struct V_112 * V_129 ;
struct V_112 V_130 ;
struct V_23 * V_24 = V_2 -> V_24 ;
T_6 V_131 = V_24 -> V_37 . V_132 . V_133 ;
T_6 V_134 = V_24 -> V_48 . V_133 ;
T_1 V_135 = V_24 -> V_48 . V_136 . V_137 ;
struct V_13 * V_15 = NULL ;
struct V_13 * V_138 ;
struct V_3 * V_31 , * V_32 ;
T_5 V_117 ;
int error = 0 ;
int V_115 = 0 ;
int V_139 = 0 ;
struct V_10 V_140 ;
struct V_10 * V_141 ;
F_16 ( & V_140 ) ;
V_129 = NULL ;
F_23 (chunk, tmp, &q->control_chunk_list, list) {
if ( V_24 -> V_142 &&
V_31 -> V_40 -> type != V_143 )
continue;
F_6 ( & V_31 -> V_5 ) ;
V_138 = V_31 -> V_15 ;
if ( ! V_138 ) {
if ( V_15 &&
F_57 ( & V_31 -> V_144 ,
& V_15 -> V_145 ) )
V_138 = V_15 ;
else
V_138 = F_58 ( V_24 ,
& V_31 -> V_144 ) ;
if ( ! V_138 )
V_138 = V_24 -> V_48 . V_146 ;
} else if ( ( V_138 -> V_41 == V_147 ) ||
( V_138 -> V_41 == V_148 ) ||
( V_138 -> V_41 == V_149 ) ) {
if ( V_31 -> V_40 -> type != V_150 &&
V_31 -> V_40 -> type != V_151 &&
V_31 -> V_40 -> type != V_152 )
V_138 = V_24 -> V_48 . V_146 ;
}
if ( V_138 != V_15 ) {
V_15 = V_138 ;
if ( F_4 ( & V_15 -> V_153 ) ) {
F_8 ( & V_15 -> V_153 ,
& V_140 ) ;
}
V_129 = & V_15 -> V_129 ;
F_59 ( V_129 , V_135 ,
V_24 -> V_48 . V_154 ) ;
}
switch ( V_31 -> V_40 -> type ) {
case V_155 :
case V_156 :
case V_157 :
F_60 ( & V_130 , V_15 , V_131 , V_134 ) ;
F_59 ( & V_130 , V_135 , 0 ) ;
F_54 ( & V_130 , V_31 ) ;
error = F_55 ( & V_130 , V_35 ) ;
if ( error < 0 )
return error ;
break;
case V_158 :
if ( F_61 ( V_31 ) ) {
V_129 -> V_135 = V_24 -> V_159 . V_160 ;
}
case V_151 :
case V_161 :
case V_162 :
case V_163 :
case V_164 :
case V_165 :
case V_152 :
V_139 = 1 ;
case V_166 :
case V_150 :
case V_167 :
case V_168 :
case V_143 :
case V_169 :
V_117 = F_62 ( V_129 , V_31 ,
V_139 , V_35 ) ;
if ( V_117 != V_170 ) {
F_2 ( & V_31 -> V_5 , & V_2 -> V_25 ) ;
} else {
V_24 -> V_127 . V_171 ++ ;
if ( V_31 -> V_40 -> type == V_169 ) {
F_63 ( V_15 ) ;
V_15 -> V_172 = V_173 ;
}
}
break;
default:
F_50 () ;
}
}
if ( V_2 -> V_24 -> V_142 )
goto V_174;
switch ( V_24 -> V_41 ) {
case V_175 :
if ( ! V_129 || ! V_129 -> V_123 )
break;
case V_176 :
case V_43 :
case V_45 :
if ( ! F_4 ( & V_2 -> V_26 ) ) {
if ( V_24 -> V_48 . V_98 -> V_41 == V_148 )
goto V_174;
if ( V_15 == V_24 -> V_48 . V_98 )
goto V_177;
V_15 = V_24 -> V_48 . V_98 ;
if ( F_4 ( & V_15 -> V_153 ) ) {
F_8 ( & V_15 -> V_153 ,
& V_140 ) ;
}
V_129 = & V_15 -> V_129 ;
F_59 ( V_129 , V_135 ,
V_24 -> V_48 . V_154 ) ;
V_177:
error = F_52 ( V_2 , V_129 ,
V_114 , & V_115 ) ;
if ( V_115 ) {
F_63 ( V_15 ) ;
V_15 -> V_172 = V_173 ;
}
if ( V_129 -> V_123 )
goto V_174;
if ( ! F_4 ( & V_2 -> V_26 ) )
goto V_174;
}
if ( V_15 )
F_64 ( V_15 ) ;
while ( ( V_31 = F_3 ( V_2 ) ) != NULL ) {
if ( V_31 -> V_50 . V_178 >=
V_24 -> V_159 . V_179 ) {
F_20 ( V_31 , V_180 ) ;
if ( V_24 -> V_48 . V_49 &&
F_33 ( V_31 -> V_50 . V_51 ) )
V_24 -> V_52 -- ;
F_21 ( V_31 ) ;
continue;
}
if ( F_46 ( V_31 ) ) {
F_20 ( V_31 , 0 ) ;
F_21 ( V_31 ) ;
continue;
}
V_138 = V_31 -> V_15 ;
if ( ! V_138 ||
( ( V_138 -> V_41 == V_147 ) ||
( V_138 -> V_41 == V_148 ) ||
( V_138 -> V_41 == V_149 ) ) )
V_138 = V_24 -> V_48 . V_146 ;
if ( V_138 -> V_41 == V_148 ) {
F_65 ( 1 , L_6 ) ;
F_20 ( V_31 , 0 ) ;
F_21 ( V_31 ) ;
continue;
}
if ( V_138 != V_15 ) {
V_15 = V_138 ;
if ( F_4 ( & V_15 -> V_153 ) ) {
F_8 ( & V_15 -> V_153 ,
& V_140 ) ;
}
V_129 = & V_15 -> V_129 ;
F_59 ( V_129 , V_135 ,
V_24 -> V_48 . V_154 ) ;
F_64 ( V_15 ) ;
}
F_28 ( L_7
L_8 ,
V_39 , V_2 , V_31 , V_31 && V_31 -> V_40 ?
F_29 ( F_30 ( V_31 -> V_40 -> type ) ) :
L_2 , F_37 ( V_31 -> V_66 . V_67 -> V_20 ) ,
V_31 -> V_8 ? V_31 -> V_8 -> V_59 : NULL , V_31 -> V_8 ?
F_66 ( & V_31 -> V_8 -> V_181 ) : - 1 ) ;
V_117 = F_62 ( V_129 , V_31 , 0 , V_35 ) ;
switch ( V_117 ) {
case V_121 :
case V_124 :
case V_125 :
F_28 ( L_9 ,
V_39 , F_37 ( V_31 -> V_66 . V_67 -> V_20 ) ,
V_117 ) ;
F_1 ( V_2 , V_31 ) ;
goto V_174;
case V_170 :
if ( V_24 -> V_41 == V_43 )
V_31 -> V_40 -> V_53 |= V_182 ;
if ( V_31 -> V_40 -> V_53 & V_54 )
V_24 -> V_127 . V_183 ++ ;
else
V_24 -> V_127 . V_184 ++ ;
break;
default:
F_50 () ;
}
F_8 ( & V_31 -> V_34 ,
& V_15 -> V_33 ) ;
F_63 ( V_15 ) ;
V_15 -> V_172 = V_173 ;
if ( V_129 -> V_123 )
goto V_174;
}
break;
default:
break;
}
V_174:
while ( ( V_141 = F_19 ( & V_140 ) ) != NULL ) {
struct V_13 * V_185 = F_5 ( V_141 ,
struct V_13 ,
V_153 ) ;
V_129 = & V_185 -> V_129 ;
if ( ! F_67 ( V_129 ) )
error = F_55 ( V_129 , V_35 ) ;
F_68 ( V_185 ) ;
}
return error ;
}
static void F_69 ( struct V_23 * V_186 ,
struct V_187 * V_188 )
{
T_7 * V_189 ;
T_6 V_100 ;
int V_136 ;
V_100 = V_186 -> V_190 - V_186 -> V_109 - 1 ;
V_189 = V_188 -> V_191 ;
for ( V_136 = 0 ; V_136 < F_70 ( V_188 -> V_192 ) ; V_136 ++ ) {
V_100 -= ( ( F_70 ( V_189 [ V_136 ] . V_193 . V_194 ) -
F_70 ( V_189 [ V_136 ] . V_193 . V_195 ) + 1 ) ) ;
}
V_186 -> V_100 = V_100 ;
}
int F_71 ( struct V_1 * V_2 , struct V_3 * V_31 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_187 * V_188 = V_31 -> V_66 . V_196 ;
struct V_13 * V_15 ;
struct V_3 * V_197 = NULL ;
struct V_10 * V_29 , * V_140 , * V_30 ;
T_7 * V_189 = V_188 -> V_191 ;
T_1 V_198 , V_199 , V_20 ;
T_1 V_200 , V_201 ;
T_1 V_202 ;
unsigned int V_203 ;
struct V_13 * V_14 = V_24 -> V_48 . V_204 ;
int V_16 = 0 ;
int V_205 ;
T_8 V_206 = 0 ;
V_140 = & V_24 -> V_48 . V_207 ;
V_198 = F_37 ( V_188 -> V_208 ) ;
V_205 = F_70 ( V_188 -> V_192 ) ;
V_24 -> V_127 . V_209 += V_205 ;
if ( V_14 -> V_17 . V_22 ) {
T_8 V_210 = 0 ;
if ( F_72 ( V_14 -> V_17 . V_21 , V_198 ) ) {
V_14 -> V_17 . V_22 = 0 ;
V_210 = 1 ;
}
if ( V_210 || V_205 ) {
F_18 (transport, transport_list,
transports) {
if ( V_210 )
V_15 -> V_17 . V_19 = 0 ;
if ( V_205 )
V_15 -> V_17 . V_18 = 0 ;
}
}
}
V_200 = V_198 ;
if ( V_205 )
V_200 += F_70 ( V_189 [ V_205 - 1 ] . V_193 . V_194 ) ;
if ( F_13 ( V_24 -> V_211 , V_200 ) )
V_24 -> V_211 = V_200 ;
V_201 = V_198 ;
F_73 ( V_2 , & V_2 -> V_26 , NULL , NULL , V_188 , & V_201 ) ;
F_18 (transport, transport_list, transports) {
F_73 ( V_2 , & V_15 -> V_33 ,
V_15 , & V_31 -> V_212 , V_188 ,
& V_201 ) ;
if ( V_15 -> V_17 . V_18 )
V_16 ++ ;
}
if ( F_13 ( V_24 -> V_109 , V_198 ) ) {
V_24 -> V_109 = V_198 ;
V_206 = 1 ;
}
if ( V_205 ) {
if ( V_24 -> V_213 && V_206 )
V_201 = V_200 ;
F_18 (transport, transport_list, transports)
F_74 ( V_2 , & V_15 -> V_33 , V_15 ,
V_201 , V_16 ) ;
}
F_69 ( V_24 , V_188 ) ;
V_199 = V_24 -> V_109 ;
F_22 (lchunk, temp, &q->sacked) {
V_197 = F_5 ( V_29 , struct V_3 ,
V_34 ) ;
V_20 = F_37 ( V_197 -> V_66 . V_67 -> V_20 ) ;
if ( F_72 ( V_20 , V_199 ) ) {
F_6 ( & V_197 -> V_34 ) ;
if ( V_24 -> V_48 . V_49 &&
F_33 ( V_31 -> V_50 . V_51 ) )
V_24 -> V_52 -- ;
F_21 ( V_197 ) ;
}
}
V_202 = F_37 ( V_188 -> V_214 ) ;
V_24 -> V_48 . V_215 = ! V_202 ;
V_203 = V_2 -> V_79 ;
if ( V_203 < V_202 )
V_202 -= V_203 ;
else
V_202 = 0 ;
V_24 -> V_48 . V_84 = V_202 ;
F_51 ( V_2 , V_198 ) ;
F_28 ( L_10 , V_39 , V_198 ) ;
F_28 ( L_11
L_12 , V_39 , V_24 , V_199 ,
V_24 -> V_216 ) ;
return F_75 ( V_2 ) ;
}
int F_75 ( const struct V_1 * V_2 )
{
return V_2 -> V_7 == 0 && V_2 -> V_79 == 0 &&
F_4 ( & V_2 -> V_26 ) ;
}
static void F_73 ( struct V_1 * V_2 ,
struct V_10 * V_217 ,
struct V_13 * V_15 ,
union V_218 * V_219 ,
struct V_187 * V_188 ,
T_1 * V_220 )
{
struct V_10 * V_29 ;
struct V_3 * V_197 ;
struct V_10 V_221 ;
T_1 V_20 ;
T_1 V_198 ;
T_1 V_222 ;
T_3 V_223 = 0 ;
int V_224 = 0 ;
int V_225 = 0 ;
bool V_226 = false ;
V_198 = F_37 ( V_188 -> V_208 ) ;
F_16 ( & V_221 ) ;
while ( NULL != ( V_29 = F_19 ( V_217 ) ) ) {
V_197 = F_5 ( V_29 , struct V_3 ,
V_34 ) ;
if ( F_46 ( V_197 ) ) {
F_36 ( & V_2 -> V_28 , V_29 ) ;
if ( ! V_197 -> V_77 ) {
if ( V_197 -> V_15 )
V_197 -> V_15 -> V_78 -=
F_41 ( V_197 ) ;
V_2 -> V_79 -= F_41 ( V_197 ) ;
}
continue;
}
V_20 = F_37 ( V_197 -> V_66 . V_67 -> V_20 ) ;
if ( F_76 ( V_188 , V_20 ) ) {
if ( V_15 ) {
if ( ! V_197 -> V_77 &&
! V_197 -> V_91 &&
V_197 -> V_89 ) {
V_197 -> V_89 = 0 ;
V_222 = V_173 - V_197 -> V_227 ;
F_77 ( V_15 ,
V_222 ) ;
}
}
if ( ! V_197 -> V_77 ) {
V_197 -> V_77 = 1 ;
if ( F_13 ( * V_220 , V_20 ) )
* V_220 = V_20 ;
V_224 += F_41 ( V_197 ) ;
if ( ! V_197 -> V_15 )
V_225 += F_41 ( V_197 ) ;
V_226 = true ;
}
if ( F_72 ( V_20 , V_198 ) ) {
V_223 = 1 ;
V_226 = true ;
if ( ! V_197 -> V_77 ) {
if ( V_15 &&
V_188 -> V_192 &&
V_2 -> V_24 -> V_48 . V_204 -> V_17 .
V_22 )
V_15 -> V_17 . V_18
= 1 ;
}
F_8 ( & V_197 -> V_34 ,
& V_2 -> V_27 ) ;
} else {
F_8 ( V_29 , & V_221 ) ;
}
} else {
if ( V_197 -> V_77 ) {
F_28 ( L_13 ,
V_39 , V_20 ) ;
V_197 -> V_77 = 0 ;
if ( V_197 -> V_15 )
V_224 -= F_41 ( V_197 ) ;
V_223 = 1 ;
}
F_8 ( V_29 , & V_221 ) ;
}
}
if ( V_15 ) {
if ( V_224 ) {
struct V_23 * V_24 = V_15 -> V_24 ;
V_224 -= V_225 ;
V_15 -> V_228 = 0 ;
V_15 -> V_24 -> V_229 = 0 ;
V_226 = true ;
if ( V_24 -> V_41 == V_43 &&
F_78 ( & V_24 -> V_230
[ V_231 ] ) )
F_79 ( V_24 ) ;
if ( ( V_15 -> V_41 == V_147 ||
V_15 -> V_41 == V_148 ) &&
F_57 ( & V_15 -> V_145 , V_219 ) ) {
F_80 (
V_15 -> V_24 ,
V_15 ,
V_232 ,
V_233 ) ;
}
F_81 ( V_15 , V_198 ,
V_224 ) ;
V_15 -> V_78 -= V_224 ;
if ( V_15 -> V_78 == 0 )
V_15 -> V_94 = 0 ;
V_2 -> V_79 -= V_224 + V_225 ;
} else {
if ( ! V_2 -> V_24 -> V_48 . V_84 &&
! F_4 ( & V_221 ) &&
( V_198 + 2 == V_2 -> V_24 -> V_190 ) &&
V_2 -> V_24 -> V_41 < V_43 ) {
F_28 ( L_14
L_15 , V_39 , V_198 ) ;
V_2 -> V_24 -> V_229 = 0 ;
V_15 -> V_228 = 0 ;
}
}
if ( ! V_15 -> V_78 ) {
if ( F_78 ( & V_15 -> V_234 ) )
F_82 ( V_15 ) ;
} else if ( V_223 ) {
if ( ! F_83 ( & V_15 -> V_234 ,
V_173 + V_15 -> V_235 ) )
F_84 ( V_15 ) ;
}
if ( V_226 ) {
if ( V_15 -> V_236 )
F_85 ( V_15 -> V_236 ) ;
}
}
F_86 ( & V_221 , V_217 ) ;
}
static void F_74 ( struct V_1 * V_2 ,
struct V_10 * V_217 ,
struct V_13 * V_15 ,
T_1 V_220 ,
int V_16 )
{
struct V_3 * V_31 ;
T_1 V_20 ;
char V_237 = 0 ;
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_13 * V_14 = V_24 -> V_48 . V_204 ;
F_18 (chunk, transmitted_queue, transmitted_list) {
V_20 = F_37 ( V_31 -> V_66 . V_67 -> V_20 ) ;
if ( V_31 -> V_86 == V_238 &&
! V_31 -> V_77 &&
F_13 ( V_20 , V_220 ) ) {
if ( ! V_15 || ! F_14 ( V_14 ,
V_31 -> V_15 ,
V_16 , V_20 ) ) {
V_31 -> V_88 ++ ;
F_28 ( L_16 ,
V_39 , V_20 , V_31 -> V_88 ) ;
}
}
if ( V_31 -> V_88 >= 3 ) {
V_31 -> V_86 = V_87 ;
V_237 = 1 ;
}
}
if ( V_15 ) {
if ( V_237 )
F_47 ( V_2 , V_15 , V_85 ) ;
F_28 ( L_17
L_5 , V_39 , V_15 ,
V_15 -> V_92 , V_15 -> V_93 ,
V_15 -> V_78 , V_15 -> V_94 ) ;
}
}
static int F_76 ( struct V_187 * V_188 , T_1 V_20 )
{
int V_136 ;
T_7 * V_189 ;
T_6 V_239 ;
T_1 V_199 = F_37 ( V_188 -> V_208 ) ;
if ( F_72 ( V_20 , V_199 ) )
goto V_240;
V_189 = V_188 -> V_191 ;
V_239 = V_20 - V_199 ;
for ( V_136 = 0 ; V_136 < F_70 ( V_188 -> V_192 ) ; ++ V_136 ) {
if ( F_72 ( F_70 ( V_189 [ V_136 ] . V_193 . V_195 ) , V_239 ) &&
F_72 ( V_239 , F_70 ( V_189 [ V_136 ] . V_193 . V_194 ) ) )
goto V_240;
}
return 0 ;
V_240:
return 1 ;
}
static inline int F_87 ( struct V_241 * V_242 ,
int V_243 , T_9 V_244 )
{
int V_136 ;
for ( V_136 = 0 ; V_136 < V_243 ; V_136 ++ ) {
if ( V_242 [ V_136 ] . V_244 == V_244 )
return V_136 ;
}
return V_136 ;
}
static void F_51 ( struct V_1 * V_2 , T_1 V_199 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_3 * V_245 = NULL ;
struct V_241 V_246 [ 10 ] ;
int V_243 = 0 ;
int V_247 = 0 ;
T_1 V_20 ;
struct V_3 * V_31 ;
struct V_10 * V_29 , * V_30 ;
if ( ! V_24 -> V_48 . V_49 )
return;
if ( F_13 ( V_24 -> V_216 , V_199 ) )
V_24 -> V_216 = V_199 ;
F_22 (lchunk, temp, &q->abandoned) {
V_31 = F_5 ( V_29 , struct V_3 ,
V_34 ) ;
V_20 = F_37 ( V_31 -> V_66 . V_67 -> V_20 ) ;
if ( F_72 ( V_20 , V_199 ) ) {
F_6 ( V_29 ) ;
F_21 ( V_31 ) ;
} else {
if ( F_72 ( V_20 , V_24 -> V_216 + 1 ) ) {
V_24 -> V_216 = V_20 ;
if ( V_31 -> V_40 -> V_53 &
V_54 )
continue;
V_247 = F_87 ( & V_246 [ 0 ] ,
V_243 ,
V_31 -> V_66 . V_67 -> V_244 ) ;
V_246 [ V_247 ] . V_244 =
V_31 -> V_66 . V_67 -> V_244 ;
V_246 [ V_247 ] . V_248 =
V_31 -> V_66 . V_67 -> V_248 ;
if ( V_247 == V_243 )
V_243 ++ ;
if ( V_243 == 10 )
break;
} else
break;
}
}
if ( V_24 -> V_216 > V_199 )
V_245 = F_88 ( V_24 , V_24 -> V_216 ,
V_243 , & V_246 [ 0 ] ) ;
if ( V_245 ) {
F_8 ( & V_245 -> V_5 , & V_2 -> V_25 ) ;
F_34 ( F_27 ( V_24 -> V_37 . V_38 ) , V_57 ) ;
}
}
