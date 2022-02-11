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
V_31 -> V_84 = 1 ;
F_6 ( V_29 ) ;
F_35 ( & V_2 -> V_26 , V_29 ) ;
}
}
F_28 ( L_4
L_5 , V_39 , V_15 , V_75 ,
V_15 -> V_85 , V_15 -> V_86 , V_15 -> V_71 ,
V_15 -> V_87 ) ;
}
void F_46 ( struct V_1 * V_2 , struct V_13 * V_15 ,
T_4 V_75 )
{
struct V_36 * V_36 = F_27 ( V_2 -> V_24 -> V_37 . V_38 ) ;
switch ( V_75 ) {
case V_88 :
F_33 ( V_36 , V_89 ) ;
F_47 ( V_15 , V_90 ) ;
if ( V_15 == V_15 -> V_24 -> V_41 . V_91 )
F_48 ( V_15 -> V_24 ) ;
V_15 -> V_24 -> V_92 +=
V_15 -> V_24 -> V_93 ;
break;
case V_78 :
F_33 ( V_36 , V_94 ) ;
F_47 ( V_15 , V_95 ) ;
V_2 -> V_96 = 1 ;
break;
case V_97 :
F_33 ( V_36 , V_98 ) ;
break;
case V_99 :
F_33 ( V_36 , V_100 ) ;
V_15 -> V_24 -> V_101 ++ ;
break;
default:
F_49 () ;
}
F_44 ( V_2 , V_15 , V_75 ) ;
if ( V_75 == V_88 )
F_50 ( V_2 , V_2 -> V_24 -> V_102 ) ;
if ( V_75 != V_78 )
F_34 ( V_2 , 1 , V_103 ) ;
}
static int F_51 ( struct V_1 * V_2 , struct V_104 * V_105 ,
int V_106 , int * V_107 )
{
struct V_10 * V_108 ;
struct V_13 * V_15 = V_105 -> V_15 ;
T_5 V_109 ;
struct V_3 * V_31 , * V_110 ;
int V_96 ;
int error = 0 ;
int V_111 = 0 ;
int V_58 = 0 ;
V_108 = & V_2 -> V_26 ;
V_96 = V_2 -> V_96 ;
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
if ( V_96 && ! V_31 -> V_79 )
continue;
V_112:
V_109 = F_53 ( V_105 , V_31 ) ;
switch ( V_109 ) {
case V_113 :
if ( ! V_105 -> V_114 && ! V_105 -> V_115 ) {
F_54 ( V_105 , V_103 ) ;
goto V_112;
}
error = F_54 ( V_105 , V_103 ) ;
if ( V_106 || V_96 )
V_58 = 1 ;
else
goto V_112;
break;
case V_116 :
error = F_54 ( V_105 , V_103 ) ;
V_58 = 1 ;
break;
case V_117 :
error = F_54 ( V_105 , V_103 ) ;
V_58 = 1 ;
break;
default:
F_52 ( & V_31 -> V_34 ,
& V_15 -> V_33 ) ;
if ( V_31 -> V_79 == V_80 )
V_31 -> V_79 = V_118 ;
V_2 -> V_24 -> V_119 . V_120 ++ ;
break;
}
if ( ! error && ! V_111 )
V_111 = 1 ;
if ( V_58 )
break;
}
if ( V_106 || V_96 ) {
F_18 (chunk1, lqueue, transmitted_list) {
if ( V_110 -> V_79 == V_80 )
V_110 -> V_79 = V_118 ;
}
}
* V_107 = V_111 ;
if ( V_96 )
V_2 -> V_96 = 0 ;
return error ;
}
void F_55 ( struct V_1 * V_2 , T_2 V_35 )
{
if ( V_2 -> V_51 )
V_2 -> V_51 = 0 ;
F_34 ( V_2 , 0 , V_35 ) ;
}
static void F_34 ( struct V_1 * V_2 , int V_106 , T_2 V_35 )
{
struct V_104 * V_121 ;
struct V_104 V_122 ;
struct V_23 * V_24 = V_2 -> V_24 ;
T_6 V_123 = V_24 -> V_37 . V_124 . V_125 ;
T_6 V_126 = V_24 -> V_41 . V_125 ;
T_1 V_127 = V_24 -> V_41 . V_128 . V_129 ;
struct V_13 * V_15 = NULL ;
struct V_13 * V_130 ;
struct V_3 * V_31 , * V_32 ;
T_5 V_109 ;
int error = 0 ;
int V_107 = 0 ;
int V_131 = 0 ;
struct V_10 V_132 ;
struct V_10 * V_133 ;
F_16 ( & V_132 ) ;
V_121 = NULL ;
F_23 (chunk, tmp, &q->control_chunk_list, list) {
if ( V_24 -> V_134 &&
V_31 -> V_40 -> type != V_135 )
continue;
F_6 ( & V_31 -> V_5 ) ;
V_130 = V_31 -> V_15 ;
if ( ! V_130 ) {
if ( V_15 &&
F_56 ( & V_31 -> V_136 ,
& V_15 -> V_137 ) )
V_130 = V_15 ;
else
V_130 = F_57 ( V_24 ,
& V_31 -> V_136 ) ;
if ( ! V_130 )
V_130 = V_24 -> V_41 . V_138 ;
} else if ( ( V_130 -> V_139 == V_140 ) ||
( V_130 -> V_139 == V_141 ) ||
( V_130 -> V_139 == V_142 ) ) {
if ( V_31 -> V_40 -> type != V_143 &&
V_31 -> V_40 -> type != V_144 &&
V_31 -> V_40 -> type != V_145 )
V_130 = V_24 -> V_41 . V_138 ;
}
if ( V_130 != V_15 ) {
V_15 = V_130 ;
if ( F_4 ( & V_15 -> V_146 ) ) {
F_8 ( & V_15 -> V_146 ,
& V_132 ) ;
}
V_121 = & V_15 -> V_121 ;
F_58 ( V_121 , V_127 ,
V_24 -> V_41 . V_147 ) ;
}
switch ( V_31 -> V_40 -> type ) {
case V_148 :
case V_149 :
case V_150 :
F_59 ( & V_122 , V_15 , V_123 , V_126 ) ;
F_58 ( & V_122 , V_127 , 0 ) ;
F_53 ( & V_122 , V_31 ) ;
error = F_54 ( & V_122 , V_35 ) ;
if ( error < 0 ) {
V_24 -> V_37 . V_38 -> V_151 = - error ;
return;
}
break;
case V_152 :
if ( F_60 ( V_31 ) ) {
V_121 -> V_127 = V_24 -> V_153 . V_154 ;
}
case V_144 :
case V_155 :
case V_156 :
case V_157 :
case V_158 :
case V_159 :
case V_145 :
V_131 = 1 ;
case V_160 :
case V_143 :
case V_161 :
case V_162 :
case V_135 :
case V_163 :
V_109 = F_61 ( V_121 , V_31 ,
V_131 , V_35 ) ;
if ( V_109 != V_164 ) {
F_2 ( & V_31 -> V_5 , & V_2 -> V_25 ) ;
} else {
V_24 -> V_119 . V_165 ++ ;
if ( V_31 -> V_40 -> type == V_163 ) {
F_62 ( V_15 ) ;
V_15 -> V_166 = V_167 ;
}
}
break;
default:
F_49 () ;
}
}
if ( V_2 -> V_24 -> V_134 )
goto V_168;
switch ( V_24 -> V_139 ) {
case V_169 :
if ( ! V_121 || ! V_121 -> V_115 )
break;
case V_170 :
case V_171 :
case V_172 :
if ( ! F_4 ( & V_2 -> V_26 ) ) {
if ( V_24 -> V_41 . V_91 -> V_139 == V_141 )
goto V_168;
if ( V_15 == V_24 -> V_41 . V_91 )
goto V_173;
V_15 = V_24 -> V_41 . V_91 ;
if ( F_4 ( & V_15 -> V_146 ) ) {
F_8 ( & V_15 -> V_146 ,
& V_132 ) ;
}
V_121 = & V_15 -> V_121 ;
F_58 ( V_121 , V_127 ,
V_24 -> V_41 . V_147 ) ;
V_173:
error = F_51 ( V_2 , V_121 ,
V_106 , & V_107 ) ;
if ( error < 0 )
V_24 -> V_37 . V_38 -> V_151 = - error ;
if ( V_107 ) {
F_62 ( V_15 ) ;
V_15 -> V_166 = V_167 ;
}
if ( V_121 -> V_115 )
goto V_168;
if ( ! F_4 ( & V_2 -> V_26 ) )
goto V_168;
}
if ( V_15 )
F_63 ( V_15 ) ;
while ( ( V_31 = F_3 ( V_2 ) ) != NULL ) {
if ( V_31 -> V_43 . V_174 >=
V_24 -> V_153 . V_175 ) {
F_20 ( V_31 , V_176 ) ;
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
V_130 = V_31 -> V_15 ;
if ( ! V_130 ||
( ( V_130 -> V_139 == V_140 ) ||
( V_130 -> V_139 == V_141 ) ||
( V_130 -> V_139 == V_142 ) ) )
V_130 = V_24 -> V_41 . V_138 ;
if ( V_130 -> V_139 == V_141 ) {
F_64 ( 1 , L_6 ) ;
F_20 ( V_31 , 0 ) ;
F_21 ( V_31 ) ;
continue;
}
if ( V_130 != V_15 ) {
V_15 = V_130 ;
if ( F_4 ( & V_15 -> V_146 ) ) {
F_8 ( & V_15 -> V_146 ,
& V_132 ) ;
}
V_121 = & V_15 -> V_121 ;
F_58 ( V_121 , V_127 ,
V_24 -> V_41 . V_147 ) ;
F_63 ( V_15 ) ;
}
F_28 ( L_7
L_8 ,
V_39 , V_2 , V_31 , V_31 && V_31 -> V_40 ?
F_29 ( F_30 ( V_31 -> V_40 -> type ) ) :
L_2 , F_36 ( V_31 -> V_59 . V_60 -> V_20 ) ,
V_31 -> V_8 ? V_31 -> V_8 -> V_52 : NULL , V_31 -> V_8 ?
F_65 ( & V_31 -> V_8 -> V_177 ) : - 1 ) ;
V_109 = F_61 ( V_121 , V_31 , 0 , V_35 ) ;
switch ( V_109 ) {
case V_113 :
case V_116 :
case V_117 :
F_28 ( L_9 ,
V_39 , F_36 ( V_31 -> V_59 . V_60 -> V_20 ) ,
V_109 ) ;
F_1 ( V_2 , V_31 ) ;
goto V_168;
case V_164 :
if ( V_24 -> V_139 == V_171 )
V_31 -> V_40 -> V_46 |= V_178 ;
if ( V_31 -> V_40 -> V_46 & V_47 )
V_24 -> V_119 . V_179 ++ ;
else
V_24 -> V_119 . V_180 ++ ;
break;
default:
F_49 () ;
}
F_8 ( & V_31 -> V_34 ,
& V_15 -> V_33 ) ;
F_62 ( V_15 ) ;
V_15 -> V_166 = V_167 ;
if ( V_121 -> V_115 )
goto V_168;
}
break;
default:
break;
}
V_168:
while ( ( V_133 = F_19 ( & V_132 ) ) != NULL ) {
struct V_13 * V_181 = F_5 ( V_133 ,
struct V_13 ,
V_146 ) ;
V_121 = & V_181 -> V_121 ;
if ( ! F_66 ( V_121 ) ) {
error = F_54 ( V_121 , V_35 ) ;
if ( error < 0 )
V_24 -> V_37 . V_38 -> V_151 = - error ;
}
F_67 ( V_181 ) ;
}
}
static void F_68 ( struct V_23 * V_182 ,
struct V_183 * V_184 )
{
T_7 * V_185 ;
T_6 V_93 ;
int V_128 ;
V_93 = V_182 -> V_186 - V_182 -> V_102 - 1 ;
V_185 = V_184 -> V_187 ;
for ( V_128 = 0 ; V_128 < F_69 ( V_184 -> V_188 ) ; V_128 ++ ) {
V_93 -= ( ( F_69 ( V_185 [ V_128 ] . V_189 . V_190 ) -
F_69 ( V_185 [ V_128 ] . V_189 . V_191 ) + 1 ) ) ;
}
V_182 -> V_93 = V_93 ;
}
int F_70 ( struct V_1 * V_2 , struct V_3 * V_31 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_183 * V_184 = V_31 -> V_59 . V_192 ;
struct V_13 * V_15 ;
struct V_3 * V_193 = NULL ;
struct V_10 * V_29 , * V_132 , * V_30 ;
T_7 * V_185 = V_184 -> V_187 ;
T_1 V_194 , V_195 , V_20 ;
T_1 V_196 , V_197 ;
T_1 V_198 ;
unsigned int V_199 ;
struct V_13 * V_14 = V_24 -> V_41 . V_200 ;
int V_16 = 0 ;
int V_201 ;
T_8 V_202 = 0 ;
V_132 = & V_24 -> V_41 . V_203 ;
V_194 = F_36 ( V_184 -> V_204 ) ;
V_201 = F_69 ( V_184 -> V_188 ) ;
V_24 -> V_119 . V_205 += V_201 ;
if ( V_14 -> V_17 . V_22 ) {
T_8 V_206 = 0 ;
if ( F_71 ( V_14 -> V_17 . V_21 , V_194 ) ) {
V_14 -> V_17 . V_22 = 0 ;
V_206 = 1 ;
}
if ( V_206 || V_201 ) {
F_18 (transport, transport_list,
transports) {
if ( V_206 )
V_15 -> V_17 . V_19 = 0 ;
if ( V_201 )
V_15 -> V_17 . V_18 = 0 ;
}
}
}
V_196 = V_194 ;
if ( V_201 )
V_196 += F_69 ( V_185 [ V_201 - 1 ] . V_189 . V_190 ) ;
if ( F_13 ( V_24 -> V_207 , V_196 ) )
V_24 -> V_207 = V_196 ;
V_197 = V_194 ;
F_72 ( V_2 , & V_2 -> V_26 , NULL , NULL , V_184 , & V_197 ) ;
F_18 (transport, transport_list, transports) {
F_72 ( V_2 , & V_15 -> V_33 ,
V_15 , & V_31 -> V_208 , V_184 ,
& V_197 ) ;
if ( V_15 -> V_17 . V_18 )
V_16 ++ ;
}
if ( F_13 ( V_24 -> V_102 , V_194 ) ) {
V_24 -> V_102 = V_194 ;
V_202 = 1 ;
}
if ( V_201 ) {
if ( V_24 -> V_209 && V_202 )
V_197 = V_196 ;
F_18 (transport, transport_list, transports)
F_73 ( V_2 , & V_15 -> V_33 , V_15 ,
V_197 , V_16 ) ;
}
F_68 ( V_24 , V_184 ) ;
V_195 = V_24 -> V_102 ;
F_22 (lchunk, temp, &q->sacked) {
V_193 = F_5 ( V_29 , struct V_3 ,
V_34 ) ;
V_20 = F_36 ( V_193 -> V_59 . V_60 -> V_20 ) ;
if ( F_71 ( V_20 , V_195 ) ) {
F_6 ( & V_193 -> V_34 ) ;
if ( V_24 -> V_41 . V_42 &&
F_32 ( V_31 -> V_43 . V_44 ) )
V_24 -> V_45 -- ;
F_21 ( V_193 ) ;
}
}
V_198 = F_36 ( V_184 -> V_210 ) ;
V_24 -> V_41 . V_211 = ! V_198 ;
V_199 = V_2 -> V_72 ;
if ( V_199 < V_198 )
V_198 -= V_199 ;
else
V_198 = 0 ;
V_24 -> V_41 . V_77 = V_198 ;
F_50 ( V_2 , V_194 ) ;
F_28 ( L_10 , V_39 , V_194 ) ;
F_28 ( L_11
L_12 , V_39 , V_24 , V_195 ,
V_24 -> V_212 ) ;
return F_74 ( V_2 ) ;
}
int F_74 ( const struct V_1 * V_2 )
{
return V_2 -> V_7 == 0 && V_2 -> V_72 == 0 &&
F_4 ( & V_2 -> V_26 ) ;
}
static void F_72 ( struct V_1 * V_2 ,
struct V_10 * V_213 ,
struct V_13 * V_15 ,
union V_214 * V_215 ,
struct V_183 * V_184 ,
T_1 * V_216 )
{
struct V_10 * V_29 ;
struct V_3 * V_193 ;
struct V_10 V_217 ;
T_1 V_20 ;
T_1 V_194 ;
T_1 V_218 ;
T_3 V_219 = 0 ;
int V_220 = 0 ;
int V_221 = 0 ;
bool V_222 = false ;
V_194 = F_36 ( V_184 -> V_204 ) ;
F_16 ( & V_217 ) ;
while ( NULL != ( V_29 = F_19 ( V_213 ) ) ) {
V_193 = F_5 ( V_29 , struct V_3 ,
V_34 ) ;
if ( F_45 ( V_193 ) ) {
F_35 ( & V_2 -> V_28 , V_29 ) ;
if ( ! V_193 -> V_70 ) {
if ( V_193 -> V_15 )
V_193 -> V_15 -> V_71 -=
F_40 ( V_193 ) ;
V_2 -> V_72 -= F_40 ( V_193 ) ;
}
continue;
}
V_20 = F_36 ( V_193 -> V_59 . V_60 -> V_20 ) ;
if ( F_75 ( V_184 , V_20 ) ) {
if ( V_15 ) {
if ( ! V_193 -> V_70 &&
! V_193 -> V_84 &&
V_193 -> V_82 ) {
V_193 -> V_82 = 0 ;
V_218 = V_167 - V_193 -> V_223 ;
F_76 ( V_15 ,
V_218 ) ;
}
}
if ( ! V_193 -> V_70 ) {
V_193 -> V_70 = 1 ;
if ( F_13 ( * V_216 , V_20 ) )
* V_216 = V_20 ;
V_220 += F_40 ( V_193 ) ;
if ( ! V_193 -> V_15 )
V_221 += F_40 ( V_193 ) ;
V_222 = true ;
}
if ( F_71 ( V_20 , V_194 ) ) {
V_219 = 1 ;
V_222 = true ;
if ( ! V_193 -> V_70 ) {
if ( V_15 &&
V_184 -> V_188 &&
V_2 -> V_24 -> V_41 . V_200 -> V_17 .
V_22 )
V_15 -> V_17 . V_18
= 1 ;
}
F_8 ( & V_193 -> V_34 ,
& V_2 -> V_27 ) ;
} else {
F_8 ( V_29 , & V_217 ) ;
}
} else {
if ( V_193 -> V_70 ) {
F_28 ( L_13 ,
V_39 , V_20 ) ;
V_193 -> V_70 = 0 ;
if ( V_193 -> V_15 )
V_220 -= F_40 ( V_193 ) ;
V_219 = 1 ;
}
F_8 ( V_29 , & V_217 ) ;
}
}
if ( V_15 ) {
if ( V_220 ) {
struct V_23 * V_24 = V_15 -> V_24 ;
V_220 -= V_221 ;
V_15 -> V_224 = 0 ;
V_15 -> V_24 -> V_225 = 0 ;
V_222 = true ;
if ( V_24 -> V_139 == V_171 &&
F_77 ( & V_24 -> V_226
[ V_227 ] ) )
F_78 ( V_24 ) ;
if ( ( V_15 -> V_139 == V_140 ||
V_15 -> V_139 == V_141 ) &&
F_56 ( & V_15 -> V_137 , V_215 ) ) {
F_79 (
V_15 -> V_24 ,
V_15 ,
V_228 ,
V_229 ) ;
}
F_80 ( V_15 , V_194 ,
V_220 ) ;
V_15 -> V_71 -= V_220 ;
if ( V_15 -> V_71 == 0 )
V_15 -> V_87 = 0 ;
V_2 -> V_72 -= V_220 + V_221 ;
} else {
if ( ! V_2 -> V_24 -> V_41 . V_77 &&
! F_4 ( & V_217 ) &&
( V_194 + 2 == V_2 -> V_24 -> V_186 ) &&
V_2 -> V_24 -> V_139 < V_171 ) {
F_28 ( L_14
L_15 , V_39 , V_194 ) ;
V_2 -> V_24 -> V_225 = 0 ;
V_15 -> V_224 = 0 ;
}
}
if ( ! V_15 -> V_71 ) {
if ( F_77 ( & V_15 -> V_230 ) )
F_81 ( V_15 ) ;
} else if ( V_219 ) {
if ( ! F_82 ( & V_15 -> V_230 ,
V_167 + V_15 -> V_231 ) )
F_83 ( V_15 ) ;
}
if ( V_222 ) {
if ( V_15 -> V_232 )
F_84 ( V_15 -> V_232 ) ;
}
}
F_85 ( & V_217 , V_213 ) ;
}
static void F_73 ( struct V_1 * V_2 ,
struct V_10 * V_213 ,
struct V_13 * V_15 ,
T_1 V_216 ,
int V_16 )
{
struct V_3 * V_31 ;
T_1 V_20 ;
char V_233 = 0 ;
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_13 * V_14 = V_24 -> V_41 . V_200 ;
F_18 (chunk, transmitted_queue, transmitted_list) {
V_20 = F_36 ( V_31 -> V_59 . V_60 -> V_20 ) ;
if ( V_31 -> V_79 == V_234 &&
! V_31 -> V_70 &&
F_13 ( V_20 , V_216 ) ) {
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
V_233 = 1 ;
}
}
if ( V_15 ) {
if ( V_233 )
F_46 ( V_2 , V_15 , V_78 ) ;
F_28 ( L_17
L_5 , V_39 , V_15 ,
V_15 -> V_85 , V_15 -> V_86 ,
V_15 -> V_71 , V_15 -> V_87 ) ;
}
}
static int F_75 ( struct V_183 * V_184 , T_1 V_20 )
{
int V_128 ;
T_7 * V_185 ;
T_6 V_235 , V_236 ;
T_1 V_195 = F_36 ( V_184 -> V_204 ) ;
if ( F_71 ( V_20 , V_195 ) )
goto V_237;
V_185 = V_184 -> V_187 ;
V_236 = F_69 ( V_184 -> V_188 ) ;
V_235 = V_20 - V_195 ;
for ( V_128 = 0 ; V_128 < V_236 ; ++ V_128 ) {
if ( V_235 >= F_69 ( V_185 [ V_128 ] . V_189 . V_191 ) &&
V_235 <= F_69 ( V_185 [ V_128 ] . V_189 . V_190 ) )
goto V_237;
}
return 0 ;
V_237:
return 1 ;
}
static inline int F_86 ( struct V_238 * V_239 ,
int V_240 , T_9 V_241 )
{
int V_128 ;
for ( V_128 = 0 ; V_128 < V_240 ; V_128 ++ ) {
if ( V_239 [ V_128 ] . V_241 == V_241 )
return V_128 ;
}
return V_128 ;
}
static void F_50 ( struct V_1 * V_2 , T_1 V_195 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_3 * V_242 = NULL ;
struct V_238 V_243 [ 10 ] ;
int V_240 = 0 ;
int V_244 = 0 ;
T_1 V_20 ;
struct V_3 * V_31 ;
struct V_10 * V_29 , * V_30 ;
if ( ! V_24 -> V_41 . V_42 )
return;
if ( F_13 ( V_24 -> V_212 , V_195 ) )
V_24 -> V_212 = V_195 ;
F_22 (lchunk, temp, &q->abandoned) {
V_31 = F_5 ( V_29 , struct V_3 ,
V_34 ) ;
V_20 = F_36 ( V_31 -> V_59 . V_60 -> V_20 ) ;
if ( F_71 ( V_20 , V_195 ) ) {
F_6 ( V_29 ) ;
F_21 ( V_31 ) ;
} else {
if ( F_71 ( V_20 , V_24 -> V_212 + 1 ) ) {
V_24 -> V_212 = V_20 ;
if ( V_31 -> V_40 -> V_46 &
V_47 )
continue;
V_244 = F_86 ( & V_243 [ 0 ] ,
V_240 ,
V_31 -> V_59 . V_60 -> V_241 ) ;
V_243 [ V_244 ] . V_241 =
V_31 -> V_59 . V_60 -> V_241 ;
V_243 [ V_244 ] . V_245 =
V_31 -> V_59 . V_60 -> V_245 ;
if ( V_244 == V_240 )
V_240 ++ ;
if ( V_240 == 10 )
break;
} else
break;
}
}
if ( V_24 -> V_212 > V_195 )
V_242 = F_87 ( V_24 , V_24 -> V_212 ,
V_240 , & V_243 [ 0 ] ) ;
if ( V_242 ) {
F_8 ( & V_242 -> V_5 , & V_2 -> V_25 ) ;
F_33 ( F_27 ( V_24 -> V_37 . V_38 ) , V_50 ) ;
}
}
