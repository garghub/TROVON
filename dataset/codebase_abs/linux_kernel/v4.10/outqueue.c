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
struct V_62 * V_43 ,
struct V_10 * V_63 , int V_64 )
{
struct V_3 * V_65 , * V_30 ;
F_23 (chk, temp, queue, list) {
if ( ! F_32 ( V_65 -> V_43 . V_44 ) ||
V_65 -> V_43 . V_66 <= V_43 -> V_66 )
continue;
F_6 ( & V_65 -> V_5 ) ;
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
F_42 ( V_24 , V_43 ,
& V_24 -> V_67 . V_6 ,
V_64 ) ;
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
V_108 = F_61 ( V_120 , V_31 ,
V_130 , V_35 ) ;
if ( V_108 != V_163 ) {
F_2 ( & V_31 -> V_5 , & V_2 -> V_25 ) ;
} else {
V_24 -> V_118 . V_164 ++ ;
if ( V_31 -> V_40 -> type == V_162 ) {
F_62 ( V_15 ) ;
V_15 -> V_165 = V_166 ;
}
}
break;
default:
F_49 () ;
}
}
if ( V_2 -> V_24 -> V_133 )
goto V_167;
switch ( V_24 -> V_138 ) {
case V_168 :
if ( ! V_120 || ! V_120 -> V_114 )
break;
case V_169 :
case V_170 :
case V_171 :
if ( ! F_4 ( & V_2 -> V_26 ) ) {
if ( V_24 -> V_41 . V_90 -> V_138 == V_140 )
goto V_167;
if ( V_15 == V_24 -> V_41 . V_90 )
goto V_172;
V_15 = V_24 -> V_41 . V_90 ;
if ( F_4 ( & V_15 -> V_145 ) ) {
F_8 ( & V_15 -> V_145 ,
& V_131 ) ;
}
V_120 = & V_15 -> V_120 ;
F_58 ( V_120 , V_126 ,
V_24 -> V_41 . V_146 ) ;
V_172:
error = F_51 ( V_2 , V_120 ,
V_105 , & V_106 ) ;
if ( error < 0 )
V_24 -> V_37 . V_38 -> V_150 = - error ;
if ( V_106 ) {
F_62 ( V_15 ) ;
V_15 -> V_165 = V_166 ;
}
if ( V_120 -> V_114 )
goto V_167;
if ( ! F_4 ( & V_2 -> V_26 ) )
goto V_167;
}
if ( V_15 )
F_63 ( V_15 ) ;
while ( ( V_31 = F_3 ( V_2 ) ) != NULL ) {
if ( V_31 -> V_43 . V_173 >=
V_24 -> V_152 . V_174 ) {
F_20 ( V_31 , V_175 ) ;
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
V_129 = V_31 -> V_15 ;
if ( ! V_129 ||
( ( V_129 -> V_138 == V_139 ) ||
( V_129 -> V_138 == V_140 ) ||
( V_129 -> V_138 == V_141 ) ) )
V_129 = V_24 -> V_41 . V_137 ;
if ( V_129 -> V_138 == V_140 ) {
F_64 ( 1 , L_6 ) ;
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
F_63 ( V_15 ) ;
}
F_28 ( L_7
L_8 ,
V_39 , V_2 , V_31 , V_31 && V_31 -> V_40 ?
F_29 ( F_30 ( V_31 -> V_40 -> type ) ) :
L_2 , F_36 ( V_31 -> V_59 . V_60 -> V_20 ) ,
V_31 -> V_8 ? V_31 -> V_8 -> V_52 : NULL , V_31 -> V_8 ?
F_65 ( & V_31 -> V_8 -> V_176 ) : - 1 ) ;
V_108 = F_61 ( V_120 , V_31 , 0 , V_35 ) ;
switch ( V_108 ) {
case V_112 :
case V_115 :
case V_116 :
F_28 ( L_9 ,
V_39 , F_36 ( V_31 -> V_59 . V_60 -> V_20 ) ,
V_108 ) ;
F_1 ( V_2 , V_31 ) ;
goto V_167;
case V_163 :
if ( V_24 -> V_138 == V_170 )
V_31 -> V_40 -> V_46 |= V_177 ;
if ( V_31 -> V_40 -> V_46 & V_47 )
V_24 -> V_118 . V_178 ++ ;
else
V_24 -> V_118 . V_179 ++ ;
break;
default:
F_49 () ;
}
F_8 ( & V_31 -> V_34 ,
& V_15 -> V_33 ) ;
F_62 ( V_15 ) ;
V_15 -> V_165 = V_166 ;
if ( V_120 -> V_114 )
goto V_167;
}
break;
default:
break;
}
V_167:
while ( ( V_132 = F_19 ( & V_131 ) ) != NULL ) {
struct V_13 * V_180 = F_5 ( V_132 ,
struct V_13 ,
V_145 ) ;
V_120 = & V_180 -> V_120 ;
if ( ! F_66 ( V_120 ) ) {
error = F_54 ( V_120 , V_35 ) ;
if ( error < 0 )
V_24 -> V_37 . V_38 -> V_150 = - error ;
}
F_67 ( V_180 ) ;
}
}
static void F_68 ( struct V_23 * V_181 ,
struct V_182 * V_183 )
{
T_7 * V_184 ;
T_6 V_92 ;
int V_127 ;
V_92 = V_181 -> V_185 - V_181 -> V_101 - 1 ;
V_184 = V_183 -> V_186 ;
for ( V_127 = 0 ; V_127 < F_69 ( V_183 -> V_187 ) ; V_127 ++ ) {
V_92 -= ( ( F_69 ( V_184 [ V_127 ] . V_188 . V_189 ) -
F_69 ( V_184 [ V_127 ] . V_188 . V_190 ) + 1 ) ) ;
}
V_181 -> V_92 = V_92 ;
}
int F_70 ( struct V_1 * V_2 , struct V_3 * V_31 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_182 * V_183 = V_31 -> V_59 . V_191 ;
struct V_13 * V_15 ;
struct V_3 * V_192 = NULL ;
struct V_10 * V_29 , * V_131 , * V_30 ;
T_7 * V_184 = V_183 -> V_186 ;
T_1 V_193 , V_194 , V_20 ;
T_1 V_195 , V_196 ;
T_1 V_197 ;
unsigned int V_198 ;
struct V_13 * V_14 = V_24 -> V_41 . V_199 ;
int V_16 = 0 ;
int V_200 ;
T_8 V_201 = 0 ;
V_131 = & V_24 -> V_41 . V_202 ;
V_193 = F_36 ( V_183 -> V_203 ) ;
V_200 = F_69 ( V_183 -> V_187 ) ;
V_24 -> V_118 . V_204 += V_200 ;
if ( V_14 -> V_17 . V_22 ) {
T_8 V_205 = 0 ;
if ( F_71 ( V_14 -> V_17 . V_21 , V_193 ) ) {
V_14 -> V_17 . V_22 = 0 ;
V_205 = 1 ;
}
if ( V_205 || V_200 ) {
F_18 (transport, transport_list,
transports) {
if ( V_205 )
V_15 -> V_17 . V_19 = 0 ;
if ( V_200 )
V_15 -> V_17 . V_18 = 0 ;
}
}
}
V_195 = V_193 ;
if ( V_200 )
V_195 += F_69 ( V_184 [ V_200 - 1 ] . V_188 . V_189 ) ;
if ( F_13 ( V_24 -> V_206 , V_195 ) )
V_24 -> V_206 = V_195 ;
V_196 = V_193 ;
F_72 ( V_2 , & V_2 -> V_26 , NULL , NULL , V_183 , & V_196 ) ;
F_18 (transport, transport_list, transports) {
F_72 ( V_2 , & V_15 -> V_33 ,
V_15 , & V_31 -> V_207 , V_183 ,
& V_196 ) ;
if ( V_15 -> V_17 . V_18 )
V_16 ++ ;
}
if ( F_13 ( V_24 -> V_101 , V_193 ) ) {
V_24 -> V_101 = V_193 ;
V_201 = 1 ;
}
if ( V_200 ) {
if ( V_24 -> V_208 && V_201 )
V_196 = V_195 ;
F_18 (transport, transport_list, transports)
F_73 ( V_2 , & V_15 -> V_33 , V_15 ,
V_196 , V_16 ) ;
}
F_68 ( V_24 , V_183 ) ;
V_194 = V_24 -> V_101 ;
F_22 (lchunk, temp, &q->sacked) {
V_192 = F_5 ( V_29 , struct V_3 ,
V_34 ) ;
V_20 = F_36 ( V_192 -> V_59 . V_60 -> V_20 ) ;
if ( F_71 ( V_20 , V_194 ) ) {
F_6 ( & V_192 -> V_34 ) ;
if ( V_24 -> V_41 . V_42 &&
F_32 ( V_31 -> V_43 . V_44 ) )
V_24 -> V_45 -- ;
F_21 ( V_192 ) ;
}
}
V_197 = F_36 ( V_183 -> V_209 ) ;
V_24 -> V_41 . V_210 = ! V_197 ;
V_198 = V_2 -> V_72 ;
if ( V_198 < V_197 )
V_197 -= V_198 ;
else
V_197 = 0 ;
V_24 -> V_41 . V_77 = V_197 ;
F_50 ( V_2 , V_193 ) ;
F_28 ( L_10 , V_39 , V_193 ) ;
F_28 ( L_11
L_12 , V_39 , V_24 , V_194 ,
V_24 -> V_211 ) ;
return F_74 ( V_2 ) ;
}
int F_74 ( const struct V_1 * V_2 )
{
return V_2 -> V_7 == 0 && V_2 -> V_72 == 0 &&
F_4 ( & V_2 -> V_26 ) ;
}
static void F_72 ( struct V_1 * V_2 ,
struct V_10 * V_212 ,
struct V_13 * V_15 ,
union V_213 * V_214 ,
struct V_182 * V_183 ,
T_1 * V_215 )
{
struct V_10 * V_29 ;
struct V_3 * V_192 ;
struct V_10 V_216 ;
T_1 V_20 ;
T_1 V_193 ;
T_1 V_217 ;
T_3 V_218 = 0 ;
int V_219 = 0 ;
int V_220 = 0 ;
bool V_221 = false ;
V_193 = F_36 ( V_183 -> V_203 ) ;
F_16 ( & V_216 ) ;
while ( NULL != ( V_29 = F_19 ( V_212 ) ) ) {
V_192 = F_5 ( V_29 , struct V_3 ,
V_34 ) ;
if ( F_45 ( V_192 ) ) {
F_35 ( & V_2 -> V_28 , V_29 ) ;
if ( ! V_192 -> V_70 ) {
if ( V_192 -> V_15 )
V_192 -> V_15 -> V_71 -=
F_40 ( V_192 ) ;
V_2 -> V_72 -= F_40 ( V_192 ) ;
}
continue;
}
V_20 = F_36 ( V_192 -> V_59 . V_60 -> V_20 ) ;
if ( F_75 ( V_183 , V_20 ) ) {
if ( V_15 ) {
if ( ! V_192 -> V_70 &&
! F_76 ( V_192 ) &&
V_192 -> V_82 ) {
V_192 -> V_82 = 0 ;
V_217 = V_166 - V_192 -> V_222 ;
F_77 ( V_15 ,
V_217 ) ;
}
}
if ( ! V_192 -> V_70 ) {
V_192 -> V_70 = 1 ;
if ( F_13 ( * V_215 , V_20 ) )
* V_215 = V_20 ;
V_219 += F_40 ( V_192 ) ;
if ( ! V_192 -> V_15 )
V_220 += F_40 ( V_192 ) ;
V_221 = true ;
}
if ( F_71 ( V_20 , V_193 ) ) {
V_218 = 1 ;
V_221 = true ;
if ( ! V_192 -> V_70 ) {
if ( V_15 &&
V_183 -> V_187 &&
V_2 -> V_24 -> V_41 . V_199 -> V_17 .
V_22 )
V_15 -> V_17 . V_18
= 1 ;
}
F_8 ( & V_192 -> V_34 ,
& V_2 -> V_27 ) ;
} else {
F_8 ( V_29 , & V_216 ) ;
}
} else {
if ( V_192 -> V_70 ) {
F_28 ( L_13 ,
V_39 , V_20 ) ;
V_192 -> V_70 = 0 ;
if ( V_192 -> V_15 )
V_219 -= F_40 ( V_192 ) ;
V_218 = 1 ;
}
F_8 ( V_29 , & V_216 ) ;
}
}
if ( V_15 ) {
if ( V_219 ) {
struct V_23 * V_24 = V_15 -> V_24 ;
V_219 -= V_220 ;
V_15 -> V_223 = 0 ;
V_15 -> V_24 -> V_224 = 0 ;
V_221 = true ;
if ( V_24 -> V_138 == V_170 &&
F_78 ( & V_24 -> V_225
[ V_226 ] ) )
F_79 ( V_24 ) ;
if ( ( V_15 -> V_138 == V_139 ||
V_15 -> V_138 == V_140 ) &&
F_56 ( & V_15 -> V_136 , V_214 ) ) {
F_80 (
V_15 -> V_24 ,
V_15 ,
V_227 ,
V_228 ) ;
}
F_81 ( V_15 , V_193 ,
V_219 ) ;
V_15 -> V_71 -= V_219 ;
if ( V_15 -> V_71 == 0 )
V_15 -> V_86 = 0 ;
V_2 -> V_72 -= V_219 + V_220 ;
} else {
if ( ! V_2 -> V_24 -> V_41 . V_77 &&
! F_4 ( & V_216 ) &&
( V_193 + 2 == V_2 -> V_24 -> V_185 ) &&
V_2 -> V_24 -> V_138 < V_170 ) {
F_28 ( L_14
L_15 , V_39 , V_193 ) ;
V_2 -> V_24 -> V_224 = 0 ;
V_15 -> V_223 = 0 ;
}
}
if ( ! V_15 -> V_71 ) {
if ( F_78 ( & V_15 -> V_229 ) )
F_82 ( V_15 ) ;
} else if ( V_218 ) {
if ( ! F_83 ( & V_15 -> V_229 ,
V_166 + V_15 -> V_230 ) )
F_84 ( V_15 ) ;
}
if ( V_221 ) {
if ( V_15 -> V_231 )
F_85 ( V_15 -> V_231 ) ;
}
}
F_86 ( & V_216 , V_212 ) ;
}
static void F_73 ( struct V_1 * V_2 ,
struct V_10 * V_212 ,
struct V_13 * V_15 ,
T_1 V_215 ,
int V_16 )
{
struct V_3 * V_31 ;
T_1 V_20 ;
char V_232 = 0 ;
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_13 * V_14 = V_24 -> V_41 . V_199 ;
F_18 (chunk, transmitted_queue, transmitted_list) {
V_20 = F_36 ( V_31 -> V_59 . V_60 -> V_20 ) ;
if ( V_31 -> V_79 == V_233 &&
! V_31 -> V_70 &&
F_13 ( V_20 , V_215 ) ) {
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
V_232 = 1 ;
}
}
if ( V_15 ) {
if ( V_232 )
F_46 ( V_2 , V_15 , V_78 ) ;
F_28 ( L_17
L_5 , V_39 , V_15 ,
V_15 -> V_84 , V_15 -> V_85 ,
V_15 -> V_71 , V_15 -> V_86 ) ;
}
}
static int F_75 ( struct V_182 * V_183 , T_1 V_20 )
{
int V_127 ;
T_7 * V_184 ;
T_6 V_234 , V_235 ;
T_1 V_194 = F_36 ( V_183 -> V_203 ) ;
if ( F_71 ( V_20 , V_194 ) )
goto V_236;
V_184 = V_183 -> V_186 ;
V_235 = F_69 ( V_183 -> V_187 ) ;
V_234 = V_20 - V_194 ;
for ( V_127 = 0 ; V_127 < V_235 ; ++ V_127 ) {
if ( V_234 >= F_69 ( V_184 [ V_127 ] . V_188 . V_190 ) &&
V_234 <= F_69 ( V_184 [ V_127 ] . V_188 . V_189 ) )
goto V_236;
}
return 0 ;
V_236:
return 1 ;
}
static inline int F_87 ( struct V_237 * V_238 ,
int V_239 , T_9 V_240 )
{
int V_127 ;
for ( V_127 = 0 ; V_127 < V_239 ; V_127 ++ ) {
if ( V_238 [ V_127 ] . V_240 == V_240 )
return V_127 ;
}
return V_127 ;
}
static void F_50 ( struct V_1 * V_2 , T_1 V_194 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_3 * V_241 = NULL ;
struct V_237 V_242 [ 10 ] ;
int V_239 = 0 ;
int V_243 = 0 ;
T_1 V_20 ;
struct V_3 * V_31 ;
struct V_10 * V_29 , * V_30 ;
if ( ! V_24 -> V_41 . V_42 )
return;
if ( F_13 ( V_24 -> V_211 , V_194 ) )
V_24 -> V_211 = V_194 ;
F_22 (lchunk, temp, &q->abandoned) {
V_31 = F_5 ( V_29 , struct V_3 ,
V_34 ) ;
V_20 = F_36 ( V_31 -> V_59 . V_60 -> V_20 ) ;
if ( F_71 ( V_20 , V_194 ) ) {
F_6 ( V_29 ) ;
F_21 ( V_31 ) ;
} else {
if ( F_71 ( V_20 , V_24 -> V_211 + 1 ) ) {
V_24 -> V_211 = V_20 ;
if ( V_31 -> V_40 -> V_46 &
V_47 )
continue;
V_243 = F_87 ( & V_242 [ 0 ] ,
V_239 ,
V_31 -> V_59 . V_60 -> V_240 ) ;
V_242 [ V_243 ] . V_240 =
V_31 -> V_59 . V_60 -> V_240 ;
V_242 [ V_243 ] . V_244 =
V_31 -> V_59 . V_60 -> V_244 ;
if ( V_243 == V_239 )
V_239 ++ ;
if ( V_239 == 10 )
break;
} else
break;
}
}
if ( V_24 -> V_211 > V_194 )
V_241 = F_88 ( V_24 , V_24 -> V_211 ,
V_239 , & V_242 [ 0 ] ) ;
if ( V_241 ) {
F_8 ( & V_241 -> V_5 , & V_2 -> V_25 ) ;
F_33 ( F_27 ( V_24 -> V_37 . V_38 ) , V_50 ) ;
}
}
