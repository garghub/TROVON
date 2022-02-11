static struct V_1 * F_1 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_1 * V_5 ;
F_2 (c, &conn->chan_l, list) {
if ( V_5 -> V_6 == V_4 )
return V_5 ;
}
return NULL ;
}
static struct V_1 * F_3 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_1 * V_5 ;
F_2 (c, &conn->chan_l, list) {
if ( V_5 -> V_7 == V_4 )
return V_5 ;
}
return NULL ;
}
static struct V_1 * F_4 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_1 * V_5 ;
F_5 ( & V_3 -> V_8 ) ;
V_5 = F_3 ( V_3 , V_4 ) ;
F_6 ( & V_3 -> V_8 ) ;
return V_5 ;
}
static struct V_1 * F_7 ( struct V_2 * V_3 , T_2 V_9 )
{
struct V_1 * V_5 ;
F_2 (c, &conn->chan_l, list) {
if ( V_5 -> V_9 == V_9 )
return V_5 ;
}
return NULL ;
}
static inline struct V_1 * F_8 ( struct V_2 * V_3 , T_2 V_9 )
{
struct V_1 * V_5 ;
F_5 ( & V_3 -> V_8 ) ;
V_5 = F_7 ( V_3 , V_9 ) ;
F_6 ( & V_3 -> V_8 ) ;
return V_5 ;
}
static struct V_1 * F_9 ( T_3 V_10 , T_4 * V_11 )
{
struct V_1 * V_5 ;
F_2 (c, &chan_list, global_l) {
if ( V_5 -> V_12 == V_10 && ! F_10 ( & F_11 ( V_5 -> V_13 ) -> V_11 , V_11 ) )
return V_5 ;
}
return NULL ;
}
int F_12 ( struct V_1 * V_14 , T_4 * V_11 , T_3 V_10 )
{
int V_15 ;
F_13 ( & V_16 ) ;
if ( V_10 && F_9 ( V_10 , V_11 ) ) {
V_15 = - V_17 ;
goto V_18;
}
if ( V_10 ) {
V_14 -> V_10 = V_10 ;
V_14 -> V_12 = V_10 ;
V_15 = 0 ;
} else {
T_1 V_19 ;
V_15 = - V_20 ;
for ( V_19 = 0x1001 ; V_19 < 0x1100 ; V_19 += 2 )
if ( ! F_9 ( F_14 ( V_19 ) , V_11 ) ) {
V_14 -> V_10 = F_14 ( V_19 ) ;
V_14 -> V_12 = F_14 ( V_19 ) ;
V_15 = 0 ;
break;
}
}
V_18:
F_15 ( & V_16 ) ;
return V_15 ;
}
int F_16 ( struct V_1 * V_14 , T_5 V_7 )
{
F_13 ( & V_16 ) ;
V_14 -> V_7 = V_7 ;
F_15 ( & V_16 ) ;
return 0 ;
}
static T_1 F_17 ( struct V_2 * V_3 )
{
T_1 V_4 = V_21 ;
for (; V_4 < V_22 ; V_4 ++ ) {
if ( ! F_3 ( V_3 , V_4 ) )
return V_4 ;
}
return 0 ;
}
static void F_18 ( struct V_1 * V_14 , int V_23 )
{
F_19 ( L_1 , V_14 , F_20 ( V_14 -> V_23 ) ,
F_20 ( V_23 ) ) ;
V_14 -> V_23 = V_23 ;
V_14 -> V_24 -> V_25 ( V_14 -> V_26 , V_23 ) ;
}
static void F_21 ( struct V_1 * V_14 , int V_23 )
{
struct V_27 * V_13 = V_14 -> V_13 ;
F_22 ( V_13 ) ;
F_18 ( V_14 , V_23 ) ;
F_23 ( V_13 ) ;
}
static inline void F_24 ( struct V_1 * V_14 , int V_15 )
{
struct V_27 * V_13 = V_14 -> V_13 ;
V_13 -> V_28 = V_15 ;
}
static inline void F_25 ( struct V_1 * V_14 , int V_15 )
{
struct V_27 * V_13 = V_14 -> V_13 ;
F_22 ( V_13 ) ;
F_24 ( V_14 , V_15 ) ;
F_23 ( V_13 ) ;
}
static void F_26 ( struct V_29 * V_30 )
{
struct V_1 * V_14 = F_27 ( V_30 , struct V_1 ,
V_31 . V_30 ) ;
struct V_2 * V_3 = V_14 -> V_3 ;
int V_32 ;
F_19 ( L_2 , V_14 , F_20 ( V_14 -> V_23 ) ) ;
F_5 ( & V_3 -> V_8 ) ;
F_28 ( V_14 ) ;
if ( V_14 -> V_23 == V_33 || V_14 -> V_23 == V_34 )
V_32 = V_35 ;
else if ( V_14 -> V_23 == V_36 &&
V_14 -> V_37 != V_38 )
V_32 = V_35 ;
else
V_32 = V_39 ;
F_29 ( V_14 , V_32 ) ;
F_30 ( V_14 ) ;
V_14 -> V_24 -> V_40 ( V_14 -> V_26 ) ;
F_6 ( & V_3 -> V_8 ) ;
F_31 ( V_14 ) ;
}
struct V_1 * F_32 ( struct V_27 * V_13 )
{
struct V_1 * V_14 ;
V_14 = F_33 ( sizeof( * V_14 ) , V_41 ) ;
if ( ! V_14 )
return NULL ;
F_34 ( & V_14 -> V_42 ) ;
V_14 -> V_13 = V_13 ;
F_13 ( & V_16 ) ;
F_35 ( & V_14 -> V_43 , & V_44 ) ;
F_15 ( & V_16 ) ;
F_36 ( & V_14 -> V_31 , F_26 ) ;
V_14 -> V_23 = V_45 ;
F_37 ( & V_14 -> V_46 , 1 ) ;
F_19 ( L_3 , V_13 , V_14 ) ;
return V_14 ;
}
void F_38 ( struct V_1 * V_14 )
{
F_13 ( & V_16 ) ;
F_39 ( & V_14 -> V_43 ) ;
F_15 ( & V_16 ) ;
F_31 ( V_14 ) ;
}
void F_40 ( struct V_2 * V_3 , struct V_1 * V_14 )
{
F_19 ( L_4 , V_3 ,
V_14 -> V_10 , V_14 -> V_6 ) ;
V_3 -> V_47 = V_48 ;
V_14 -> V_3 = V_3 ;
switch ( V_14 -> V_49 ) {
case V_50 :
if ( V_3 -> V_51 -> type == V_52 ) {
V_14 -> V_53 = V_54 ;
V_14 -> V_7 = V_55 ;
V_14 -> V_6 = V_55 ;
} else {
V_14 -> V_7 = F_17 ( V_3 ) ;
V_14 -> V_53 = V_56 ;
}
break;
case V_57 :
V_14 -> V_7 = V_58 ;
V_14 -> V_6 = V_58 ;
V_14 -> V_53 = V_56 ;
break;
default:
V_14 -> V_7 = V_59 ;
V_14 -> V_6 = V_59 ;
V_14 -> V_53 = V_56 ;
}
V_14 -> V_60 = V_61 ;
V_14 -> V_62 = V_63 ;
V_14 -> V_64 = V_65 ;
V_14 -> V_66 = V_67 ;
V_14 -> V_68 = V_69 ;
V_14 -> V_70 = V_71 ;
F_41 ( V_14 ) ;
F_35 ( & V_14 -> V_72 , & V_3 -> V_73 ) ;
}
void F_42 ( struct V_2 * V_3 , struct V_1 * V_14 )
{
F_5 ( & V_3 -> V_8 ) ;
F_40 ( V_3 , V_14 ) ;
F_6 ( & V_3 -> V_8 ) ;
}
static void F_43 ( struct V_1 * V_14 , int V_15 )
{
struct V_27 * V_13 = V_14 -> V_13 ;
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_27 * V_74 = F_11 ( V_13 ) -> V_74 ;
F_44 ( V_14 ) ;
F_19 ( L_5 , V_14 , V_3 , V_15 ) ;
if ( V_3 ) {
F_39 ( & V_14 -> V_72 ) ;
F_31 ( V_14 ) ;
V_14 -> V_3 = NULL ;
F_45 ( V_3 -> V_51 ) ;
}
F_22 ( V_13 ) ;
F_18 ( V_14 , V_75 ) ;
F_46 ( V_13 , V_76 ) ;
if ( V_15 )
F_24 ( V_14 , V_15 ) ;
if ( V_74 ) {
F_47 ( V_13 ) ;
V_74 -> V_77 ( V_74 , 0 ) ;
} else
V_13 -> V_78 ( V_13 ) ;
F_23 ( V_13 ) ;
if ( ! ( F_48 ( V_79 , & V_14 -> V_80 ) &&
F_48 ( V_81 , & V_14 -> V_80 ) ) )
return;
F_49 ( & V_14 -> V_82 ) ;
if ( V_14 -> V_83 == V_84 ) {
struct V_85 * V_86 , * V_87 ;
F_50 ( V_14 ) ;
F_51 ( V_14 ) ;
F_52 ( V_14 ) ;
F_49 ( & V_14 -> V_88 ) ;
F_53 (l, tmp, &chan->srej_l, list) {
F_39 ( & V_86 -> V_72 ) ;
F_54 ( V_86 ) ;
}
}
}
static void F_55 ( struct V_27 * V_74 )
{
struct V_27 * V_13 ;
F_19 ( L_6 , V_74 ) ;
while ( ( V_13 = F_56 ( V_74 , NULL ) ) ) {
struct V_1 * V_14 = F_57 ( V_13 ) -> V_14 ;
F_28 ( V_14 ) ;
F_44 ( V_14 ) ;
F_29 ( V_14 , V_89 ) ;
F_30 ( V_14 ) ;
V_14 -> V_24 -> V_40 ( V_14 -> V_26 ) ;
}
}
void F_29 ( struct V_1 * V_14 , int V_32 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_27 * V_13 = V_14 -> V_13 ;
F_19 ( L_7 , V_14 ,
F_20 ( V_14 -> V_23 ) , V_13 ) ;
switch ( V_14 -> V_23 ) {
case V_90 :
F_22 ( V_13 ) ;
F_55 ( V_13 ) ;
F_18 ( V_14 , V_75 ) ;
F_46 ( V_13 , V_76 ) ;
F_23 ( V_13 ) ;
break;
case V_33 :
case V_34 :
if ( V_14 -> V_49 == V_50 &&
V_3 -> V_51 -> type == V_91 ) {
F_44 ( V_14 ) ;
F_58 ( V_14 , V_13 -> V_92 ) ;
F_59 ( V_3 , V_14 , V_32 ) ;
} else
F_43 ( V_14 , V_32 ) ;
break;
case V_93 :
if ( V_14 -> V_49 == V_50 &&
V_3 -> V_51 -> type == V_91 ) {
struct V_94 V_95 ;
T_5 V_96 ;
if ( F_11 ( V_13 ) -> V_97 )
V_96 = V_98 ;
else
V_96 = V_99 ;
F_21 ( V_14 , V_100 ) ;
V_95 . V_7 = F_14 ( V_14 -> V_6 ) ;
V_95 . V_6 = F_14 ( V_14 -> V_7 ) ;
V_95 . V_96 = F_14 ( V_96 ) ;
V_95 . V_101 = F_14 ( V_102 ) ;
F_60 ( V_3 , V_14 -> V_9 , V_103 ,
sizeof( V_95 ) , & V_95 ) ;
}
F_43 ( V_14 , V_32 ) ;
break;
case V_36 :
case V_100 :
F_43 ( V_14 , V_32 ) ;
break;
default:
F_22 ( V_13 ) ;
F_46 ( V_13 , V_76 ) ;
F_23 ( V_13 ) ;
break;
}
}
static inline T_2 F_61 ( struct V_1 * V_14 )
{
if ( V_14 -> V_49 == V_104 ) {
switch ( V_14 -> V_37 ) {
case V_105 :
return V_106 ;
case V_107 :
return V_108 ;
default:
return V_109 ;
}
} else if ( V_14 -> V_10 == F_14 ( 0x0001 ) ) {
if ( V_14 -> V_37 == V_110 )
V_14 -> V_37 = V_38 ;
if ( V_14 -> V_37 == V_105 )
return V_111 ;
else
return V_109 ;
} else {
switch ( V_14 -> V_37 ) {
case V_105 :
return V_112 ;
case V_107 :
return V_113 ;
default:
return V_109 ;
}
}
}
int F_62 ( struct V_1 * V_14 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
T_6 V_114 ;
V_114 = F_61 ( V_14 ) ;
return F_63 ( V_3 -> V_51 , V_14 -> V_37 , V_114 ) ;
}
static T_2 F_64 ( struct V_2 * V_3 )
{
T_2 V_115 ;
F_65 ( & V_3 -> V_42 ) ;
if ( ++ V_3 -> V_116 > 128 )
V_3 -> V_116 = 1 ;
V_115 = V_3 -> V_116 ;
F_66 ( & V_3 -> V_42 ) ;
return V_115 ;
}
static void F_60 ( struct V_2 * V_3 , T_2 V_9 , T_2 V_117 , T_1 V_118 , void * V_26 )
{
struct V_119 * V_120 = F_67 ( V_3 , V_117 , V_9 , V_118 , V_26 ) ;
T_2 V_121 ;
F_19 ( L_8 , V_117 ) ;
if ( ! V_120 )
return;
if ( F_68 ( V_3 -> V_51 -> V_122 ) )
V_121 = V_123 ;
else
V_121 = V_124 ;
F_69 ( V_120 ) -> V_125 = V_126 ;
V_120 -> V_127 = V_128 ;
F_70 ( V_3 -> V_129 , V_120 , V_121 ) ;
}
static void F_71 ( struct V_1 * V_14 , struct V_119 * V_120 )
{
struct V_130 * V_51 = V_14 -> V_3 -> V_51 ;
T_1 V_121 ;
F_19 ( L_9 , V_14 , V_120 , V_120 -> V_118 ,
V_120 -> V_127 ) ;
if ( ! F_48 ( V_131 , & V_14 -> V_121 ) &&
F_68 ( V_51 -> V_122 ) )
V_121 = V_123 ;
else
V_121 = V_124 ;
F_69 ( V_120 ) -> V_125 = F_48 ( V_132 , & V_14 -> V_121 ) ;
F_70 ( V_14 -> V_3 -> V_129 , V_120 , V_121 ) ;
}
static inline void F_72 ( struct V_1 * V_14 , T_7 V_133 )
{
struct V_119 * V_120 ;
struct V_134 * V_135 ;
struct V_2 * V_3 = V_14 -> V_3 ;
int V_136 , V_137 ;
if ( V_14 -> V_23 != V_33 )
return;
if ( F_48 ( V_138 , & V_14 -> V_121 ) )
V_137 = V_139 ;
else
V_137 = V_140 ;
if ( V_14 -> V_141 == V_142 )
V_137 += V_143 ;
F_19 ( L_10 , V_14 , V_133 ) ;
V_136 = F_73 (unsigned int, conn->mtu, hlen) ;
V_133 |= F_74 ( V_14 ) ;
if ( F_75 ( V_144 , & V_14 -> V_145 ) )
V_133 |= F_76 ( V_14 ) ;
if ( F_75 ( V_146 , & V_14 -> V_145 ) )
V_133 |= F_77 ( V_14 ) ;
V_120 = F_78 ( V_136 , V_41 ) ;
if ( ! V_120 )
return;
V_135 = (struct V_134 * ) F_79 ( V_120 , V_147 ) ;
V_135 -> V_118 = F_14 ( V_137 - V_147 ) ;
V_135 -> V_4 = F_14 ( V_14 -> V_6 ) ;
F_80 ( V_14 , V_133 , F_79 ( V_120 , F_81 ( V_14 ) ) ) ;
if ( V_14 -> V_141 == V_142 ) {
T_1 V_141 = F_82 ( 0 , ( T_2 * ) V_135 , V_136 - V_143 ) ;
F_83 ( V_141 , F_79 ( V_120 , V_143 ) ) ;
}
V_120 -> V_127 = V_128 ;
F_71 ( V_14 , V_120 ) ;
}
static inline void F_84 ( struct V_1 * V_14 , T_7 V_133 )
{
if ( F_48 ( V_148 , & V_14 -> V_145 ) ) {
V_133 |= F_85 ( V_14 , V_149 ) ;
F_86 ( V_150 , & V_14 -> V_145 ) ;
} else
V_133 |= F_85 ( V_14 , V_151 ) ;
V_133 |= F_87 ( V_14 , V_14 -> V_152 ) ;
F_72 ( V_14 , V_133 ) ;
}
static inline int F_88 ( struct V_1 * V_14 )
{
return ! F_48 ( V_153 , & V_14 -> V_80 ) ;
}
static void F_89 ( struct V_1 * V_14 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_154 V_155 ;
V_155 . V_7 = F_14 ( V_14 -> V_7 ) ;
V_155 . V_10 = V_14 -> V_10 ;
V_14 -> V_9 = F_64 ( V_3 ) ;
F_86 ( V_153 , & V_14 -> V_80 ) ;
F_60 ( V_3 , V_14 -> V_9 , V_156 , sizeof( V_155 ) , & V_155 ) ;
}
static void F_90 ( struct V_1 * V_14 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
if ( V_3 -> V_157 & V_158 ) {
if ( ! ( V_3 -> V_157 & V_159 ) )
return;
if ( F_62 ( V_14 ) &&
F_88 ( V_14 ) )
F_89 ( V_14 ) ;
} else {
struct V_160 V_155 ;
V_155 . type = F_14 ( V_161 ) ;
V_3 -> V_157 |= V_158 ;
V_3 -> V_162 = F_64 ( V_3 ) ;
F_91 ( & V_3 -> V_163 , V_164 ) ;
F_60 ( V_3 , V_3 -> V_162 ,
V_165 , sizeof( V_155 ) , & V_155 ) ;
}
}
static inline int F_92 ( T_6 V_83 , T_8 V_166 )
{
T_7 V_167 = V_168 ;
if ( ! V_169 )
V_167 |= V_170 | V_171 ;
switch ( V_83 ) {
case V_84 :
return V_170 & V_166 & V_167 ;
case V_172 :
return V_171 & V_166 & V_167 ;
default:
return 0x00 ;
}
}
static void F_59 ( struct V_2 * V_3 , struct V_1 * V_14 , int V_15 )
{
struct V_27 * V_13 = V_14 -> V_13 ;
struct V_173 V_155 ;
if ( ! V_3 )
return;
if ( V_14 -> V_83 == V_84 ) {
F_50 ( V_14 ) ;
F_51 ( V_14 ) ;
F_52 ( V_14 ) ;
}
V_155 . V_6 = F_14 ( V_14 -> V_6 ) ;
V_155 . V_7 = F_14 ( V_14 -> V_7 ) ;
F_60 ( V_3 , F_64 ( V_3 ) ,
V_174 , sizeof( V_155 ) , & V_155 ) ;
F_22 ( V_13 ) ;
F_18 ( V_14 , V_100 ) ;
F_24 ( V_14 , V_15 ) ;
F_23 ( V_13 ) ;
}
static void F_93 ( struct V_2 * V_3 )
{
struct V_1 * V_14 , * V_87 ;
F_19 ( L_11 , V_3 ) ;
F_5 ( & V_3 -> V_8 ) ;
F_53 (chan, tmp, &conn->chan_l, list) {
struct V_27 * V_13 = V_14 -> V_13 ;
F_28 ( V_14 ) ;
if ( V_14 -> V_49 != V_50 ) {
F_30 ( V_14 ) ;
continue;
}
if ( V_14 -> V_23 == V_36 ) {
if ( ! F_62 ( V_14 ) ||
! F_88 ( V_14 ) ) {
F_30 ( V_14 ) ;
continue;
}
if ( ! F_92 ( V_14 -> V_83 , V_3 -> V_166 )
&& F_48 ( V_175 ,
& V_14 -> V_80 ) ) {
F_29 ( V_14 , V_89 ) ;
F_30 ( V_14 ) ;
continue;
}
F_89 ( V_14 ) ;
} else if ( V_14 -> V_23 == V_93 ) {
struct V_94 V_95 ;
char V_176 [ 128 ] ;
V_95 . V_7 = F_14 ( V_14 -> V_6 ) ;
V_95 . V_6 = F_14 ( V_14 -> V_7 ) ;
if ( F_62 ( V_14 ) ) {
F_22 ( V_13 ) ;
if ( F_11 ( V_13 ) -> V_97 ) {
struct V_27 * V_74 = F_11 ( V_13 ) -> V_74 ;
V_95 . V_96 = F_14 ( V_177 ) ;
V_95 . V_101 = F_14 ( V_178 ) ;
if ( V_74 )
V_74 -> V_77 ( V_74 , 0 ) ;
} else {
F_18 ( V_14 , V_34 ) ;
V_95 . V_96 = F_14 ( V_179 ) ;
V_95 . V_101 = F_14 ( V_102 ) ;
}
F_23 ( V_13 ) ;
} else {
V_95 . V_96 = F_14 ( V_177 ) ;
V_95 . V_101 = F_14 ( V_180 ) ;
}
F_60 ( V_3 , V_14 -> V_9 , V_103 ,
sizeof( V_95 ) , & V_95 ) ;
if ( F_48 ( V_181 , & V_14 -> V_80 ) ||
V_95 . V_96 != V_179 ) {
F_30 ( V_14 ) ;
continue;
}
F_86 ( V_181 , & V_14 -> V_80 ) ;
F_60 ( V_3 , F_64 ( V_3 ) , V_182 ,
F_94 ( V_14 , V_176 ) , V_176 ) ;
V_14 -> V_183 ++ ;
}
F_30 ( V_14 ) ;
}
F_6 ( & V_3 -> V_8 ) ;
}
static struct V_1 * F_95 ( int V_23 , T_3 V_4 , T_4 * V_11 )
{
struct V_1 * V_5 , * V_184 = NULL ;
F_96 ( & V_16 ) ;
F_2 (c, &chan_list, global_l) {
struct V_27 * V_13 = V_5 -> V_13 ;
if ( V_23 && V_5 -> V_23 != V_23 )
continue;
if ( V_5 -> V_7 == V_4 ) {
if ( ! F_10 ( & F_11 ( V_13 ) -> V_11 , V_11 ) ) {
F_97 ( & V_16 ) ;
return V_5 ;
}
if ( ! F_10 ( & F_11 ( V_13 ) -> V_11 , V_185 ) )
V_184 = V_5 ;
}
}
F_97 ( & V_16 ) ;
return V_184 ;
}
static void F_98 ( struct V_2 * V_3 )
{
struct V_27 * V_74 , * V_13 ;
struct V_1 * V_14 , * V_186 ;
F_19 ( L_12 ) ;
V_186 = F_95 ( V_90 , V_55 ,
V_3 -> V_11 ) ;
if ( ! V_186 )
return;
V_74 = V_186 -> V_13 ;
F_22 ( V_74 ) ;
if ( F_99 ( V_74 ) ) {
F_19 ( L_13 , V_74 -> V_187 ) ;
goto V_188;
}
V_14 = V_186 -> V_24 -> V_189 ( V_186 -> V_26 ) ;
if ( ! V_14 )
goto V_188;
V_13 = V_14 -> V_13 ;
F_100 ( V_3 -> V_51 ) ;
F_101 ( & F_11 ( V_13 ) -> V_11 , V_3 -> V_11 ) ;
F_101 ( & F_11 ( V_13 ) -> V_190 , V_3 -> V_190 ) ;
F_102 ( V_74 , V_13 ) ;
F_42 ( V_3 , V_14 ) ;
F_58 ( V_14 , V_13 -> V_92 ) ;
F_18 ( V_14 , V_33 ) ;
V_74 -> V_77 ( V_74 , 0 ) ;
V_188:
F_23 ( V_74 ) ;
}
static void F_103 ( struct V_1 * V_14 )
{
struct V_27 * V_13 = V_14 -> V_13 ;
struct V_27 * V_74 ;
F_22 ( V_13 ) ;
V_74 = F_11 ( V_13 ) -> V_74 ;
F_19 ( L_14 , V_13 , V_74 ) ;
V_14 -> V_80 = 0 ;
F_44 ( V_14 ) ;
F_18 ( V_14 , V_33 ) ;
V_13 -> V_78 ( V_13 ) ;
if ( V_74 )
V_74 -> V_77 ( V_74 , 0 ) ;
F_23 ( V_13 ) ;
}
static void F_104 ( struct V_2 * V_3 )
{
struct V_1 * V_14 ;
F_19 ( L_11 , V_3 ) ;
if ( ! V_3 -> V_51 -> V_191 && V_3 -> V_51 -> type == V_52 )
F_98 ( V_3 ) ;
if ( V_3 -> V_51 -> V_191 && V_3 -> V_51 -> type == V_52 )
F_105 ( V_3 , V_3 -> V_51 -> V_192 ) ;
F_5 ( & V_3 -> V_8 ) ;
F_2 (chan, &conn->chan_l, list) {
F_28 ( V_14 ) ;
if ( V_3 -> V_51 -> type == V_52 ) {
if ( F_105 ( V_3 , V_14 -> V_37 ) )
F_103 ( V_14 ) ;
} else if ( V_14 -> V_49 != V_50 ) {
struct V_27 * V_13 = V_14 -> V_13 ;
F_44 ( V_14 ) ;
F_22 ( V_13 ) ;
F_18 ( V_14 , V_33 ) ;
V_13 -> V_78 ( V_13 ) ;
F_23 ( V_13 ) ;
} else if ( V_14 -> V_23 == V_36 )
F_90 ( V_14 ) ;
F_30 ( V_14 ) ;
}
F_6 ( & V_3 -> V_8 ) ;
}
static void F_106 ( struct V_2 * V_3 , int V_15 )
{
struct V_1 * V_14 ;
F_19 ( L_11 , V_3 ) ;
F_5 ( & V_3 -> V_8 ) ;
F_2 (chan, &conn->chan_l, list) {
if ( F_48 ( V_193 , & V_14 -> V_121 ) )
F_24 ( V_14 , V_15 ) ;
}
F_6 ( & V_3 -> V_8 ) ;
}
static void F_107 ( struct V_29 * V_30 )
{
struct V_2 * V_3 = F_27 ( V_30 , struct V_2 ,
V_163 . V_30 ) ;
V_3 -> V_157 |= V_159 ;
V_3 -> V_162 = 0 ;
F_93 ( V_3 ) ;
}
static void F_108 ( struct V_130 * V_51 , int V_15 )
{
struct V_2 * V_3 = V_51 -> V_194 ;
struct V_1 * V_14 , * V_86 ;
if ( ! V_3 )
return;
F_19 ( L_15 , V_51 , V_3 , V_15 ) ;
F_109 ( V_3 -> V_195 ) ;
F_5 ( & V_3 -> V_8 ) ;
F_53 (chan, l, &conn->chan_l, list) {
F_28 ( V_14 ) ;
F_43 ( V_14 , V_15 ) ;
F_30 ( V_14 ) ;
V_14 -> V_24 -> V_40 ( V_14 -> V_26 ) ;
}
F_6 ( & V_3 -> V_8 ) ;
F_110 ( V_3 -> V_129 ) ;
if ( V_3 -> V_157 & V_158 )
F_111 ( & V_3 -> V_163 ) ;
if ( F_75 ( V_196 , & V_51 -> V_121 ) ) {
F_111 ( & V_3 -> V_197 ) ;
F_112 ( V_3 ) ;
}
V_51 -> V_194 = NULL ;
F_54 ( V_3 ) ;
}
static void F_113 ( struct V_29 * V_30 )
{
struct V_2 * V_3 = F_27 ( V_30 , struct V_2 ,
V_197 . V_30 ) ;
F_108 ( V_3 -> V_51 , V_39 ) ;
}
static struct V_2 * F_114 ( struct V_130 * V_51 , T_2 V_101 )
{
struct V_2 * V_3 = V_51 -> V_194 ;
struct V_198 * V_129 ;
if ( V_3 || V_101 )
return V_3 ;
V_129 = F_115 ( V_51 ) ;
if ( ! V_129 )
return NULL ;
V_3 = F_33 ( sizeof( struct V_2 ) , V_41 ) ;
if ( ! V_3 ) {
F_110 ( V_129 ) ;
return NULL ;
}
V_51 -> V_194 = V_3 ;
V_3 -> V_51 = V_51 ;
V_3 -> V_129 = V_129 ;
F_19 ( L_16 , V_51 , V_3 , V_129 ) ;
if ( V_51 -> V_122 -> V_199 && V_51 -> type == V_52 )
V_3 -> V_200 = V_51 -> V_122 -> V_199 ;
else
V_3 -> V_200 = V_51 -> V_122 -> V_201 ;
V_3 -> V_11 = & V_51 -> V_122 -> V_202 ;
V_3 -> V_190 = & V_51 -> V_190 ;
V_3 -> V_166 = 0 ;
F_116 ( & V_3 -> V_42 ) ;
F_34 ( & V_3 -> V_8 ) ;
F_117 ( & V_3 -> V_73 ) ;
if ( V_51 -> type == V_52 )
F_36 ( & V_3 -> V_197 , F_113 ) ;
else
F_36 ( & V_3 -> V_163 , F_107 ) ;
V_3 -> V_47 = V_48 ;
return V_3 ;
}
static struct V_1 * F_118 ( int V_23 , T_3 V_10 , T_4 * V_11 )
{
struct V_1 * V_5 , * V_184 = NULL ;
F_96 ( & V_16 ) ;
F_2 (c, &chan_list, global_l) {
struct V_27 * V_13 = V_5 -> V_13 ;
if ( V_23 && V_5 -> V_23 != V_23 )
continue;
if ( V_5 -> V_10 == V_10 ) {
if ( ! F_10 ( & F_11 ( V_13 ) -> V_11 , V_11 ) ) {
F_97 ( & V_16 ) ;
return V_5 ;
}
if ( ! F_10 ( & F_11 ( V_13 ) -> V_11 , V_185 ) )
V_184 = V_5 ;
}
}
F_97 ( & V_16 ) ;
return V_184 ;
}
int F_119 ( struct V_1 * V_14 , T_3 V_10 , T_1 V_4 , T_4 * V_190 )
{
struct V_27 * V_13 = V_14 -> V_13 ;
T_4 * V_11 = & F_11 ( V_13 ) -> V_11 ;
struct V_2 * V_3 ;
struct V_130 * V_51 ;
struct V_203 * V_122 ;
T_6 V_114 ;
int V_15 ;
F_19 ( L_17 , F_120 ( V_11 ) , F_120 ( V_190 ) ,
V_14 -> V_10 ) ;
V_122 = F_121 ( V_190 , V_11 ) ;
if ( ! V_122 )
return - V_204 ;
F_122 ( V_122 ) ;
F_28 ( V_14 ) ;
if ( ( F_123 ( V_10 ) & 0x0101 ) != 0x0001 && ! V_4 &&
V_14 -> V_49 != V_104 ) {
V_15 = - V_20 ;
goto V_18;
}
if ( V_14 -> V_49 == V_50 && ! ( V_10 || V_4 ) ) {
V_15 = - V_20 ;
goto V_18;
}
switch ( V_14 -> V_83 ) {
case V_205 :
break;
case V_84 :
case V_172 :
if ( ! V_169 )
break;
default:
V_15 = - V_206 ;
goto V_18;
}
F_22 ( V_13 ) ;
switch ( V_13 -> V_207 ) {
case V_36 :
case V_93 :
case V_34 :
V_15 = 0 ;
F_23 ( V_13 ) ;
goto V_18;
case V_33 :
V_15 = - V_208 ;
F_23 ( V_13 ) ;
goto V_18;
case V_45 :
case V_209 :
break;
default:
V_15 = - V_210 ;
F_23 ( V_13 ) ;
goto V_18;
}
F_101 ( & F_11 ( V_13 ) -> V_190 , V_190 ) ;
F_23 ( V_13 ) ;
V_14 -> V_10 = V_10 ;
V_14 -> V_6 = V_4 ;
V_114 = F_61 ( V_14 ) ;
if ( V_14 -> V_6 == V_55 )
V_51 = F_124 ( V_122 , V_52 , V_190 ,
V_14 -> V_37 , V_114 ) ;
else
V_51 = F_124 ( V_122 , V_91 , V_190 ,
V_14 -> V_37 , V_114 ) ;
if ( F_125 ( V_51 ) ) {
V_15 = F_126 ( V_51 ) ;
goto V_18;
}
V_3 = F_114 ( V_51 , 0 ) ;
if ( ! V_3 ) {
F_45 ( V_51 ) ;
V_15 = - V_211 ;
goto V_18;
}
F_101 ( V_11 , V_3 -> V_11 ) ;
F_30 ( V_14 ) ;
F_42 ( V_3 , V_14 ) ;
F_28 ( V_14 ) ;
F_21 ( V_14 , V_36 ) ;
F_58 ( V_14 , V_13 -> V_92 ) ;
if ( V_51 -> V_23 == V_33 ) {
if ( V_14 -> V_49 != V_50 ) {
F_44 ( V_14 ) ;
if ( F_62 ( V_14 ) )
F_21 ( V_14 , V_33 ) ;
} else
F_90 ( V_14 ) ;
}
V_15 = 0 ;
V_18:
F_30 ( V_14 ) ;
F_127 ( V_122 ) ;
F_128 ( V_122 ) ;
return V_15 ;
}
int F_129 ( struct V_27 * V_13 )
{
struct V_1 * V_14 = F_57 ( V_13 ) -> V_14 ;
F_130 ( V_212 , V_213 ) ;
int V_15 = 0 ;
int V_214 = V_215 / 5 ;
F_131 ( F_132 ( V_13 ) , & V_212 ) ;
F_133 ( V_216 ) ;
while ( V_14 -> V_217 > 0 && V_14 -> V_3 ) {
if ( ! V_214 )
V_214 = V_215 / 5 ;
if ( F_134 ( V_213 ) ) {
V_15 = F_135 ( V_214 ) ;
break;
}
F_23 ( V_13 ) ;
V_214 = F_136 ( V_214 ) ;
F_22 ( V_13 ) ;
F_133 ( V_216 ) ;
V_15 = F_137 ( V_13 ) ;
if ( V_15 )
break;
}
F_133 ( V_218 ) ;
F_138 ( F_132 ( V_13 ) , & V_212 ) ;
return V_15 ;
}
static void F_139 ( struct V_29 * V_30 )
{
struct V_1 * V_14 = F_27 ( V_30 , struct V_1 ,
V_219 . V_30 ) ;
F_19 ( L_18 , V_14 ) ;
F_28 ( V_14 ) ;
if ( V_14 -> V_220 >= V_14 -> V_221 ) {
F_59 ( V_14 -> V_3 , V_14 , V_222 ) ;
F_30 ( V_14 ) ;
F_31 ( V_14 ) ;
return;
}
V_14 -> V_220 ++ ;
F_140 ( V_14 ) ;
F_84 ( V_14 , V_223 ) ;
F_30 ( V_14 ) ;
F_31 ( V_14 ) ;
}
static void F_141 ( struct V_29 * V_30 )
{
struct V_1 * V_14 = F_27 ( V_30 , struct V_1 ,
V_224 . V_30 ) ;
F_19 ( L_18 , V_14 ) ;
F_28 ( V_14 ) ;
V_14 -> V_220 = 1 ;
F_140 ( V_14 ) ;
F_86 ( V_225 , & V_14 -> V_145 ) ;
F_84 ( V_14 , V_223 ) ;
F_30 ( V_14 ) ;
F_31 ( V_14 ) ;
}
static void F_142 ( struct V_1 * V_14 )
{
struct V_119 * V_120 ;
while ( ( V_120 = F_143 ( & V_14 -> V_82 ) ) &&
V_14 -> V_217 ) {
if ( F_69 ( V_120 ) -> V_226 == V_14 -> V_227 )
break;
V_120 = F_144 ( & V_14 -> V_82 ) ;
F_109 ( V_120 ) ;
V_14 -> V_217 -- ;
}
if ( ! V_14 -> V_217 )
F_50 ( V_14 ) ;
}
static void F_145 ( struct V_1 * V_14 )
{
struct V_119 * V_120 ;
T_7 V_133 ;
T_1 V_141 ;
while ( ( V_120 = F_144 ( & V_14 -> V_82 ) ) ) {
V_133 = F_146 ( V_14 , V_120 -> V_26 + V_147 ) ;
V_133 |= F_147 ( V_14 , V_14 -> V_228 ) ;
F_80 ( V_14 , V_133 , V_120 -> V_26 + V_147 ) ;
if ( V_14 -> V_141 == V_142 ) {
V_141 = F_82 ( 0 , ( T_2 * ) V_120 -> V_26 ,
V_120 -> V_118 - V_143 ) ;
F_83 ( V_141 ,
V_120 -> V_26 + V_120 -> V_118 - V_143 ) ;
}
F_71 ( V_14 , V_120 ) ;
V_14 -> V_228 = F_148 ( V_14 , V_14 -> V_228 ) ;
}
}
static void F_149 ( struct V_1 * V_14 , T_1 V_226 )
{
struct V_119 * V_120 , * V_229 ;
T_1 V_141 ;
T_7 V_133 ;
V_120 = F_143 ( & V_14 -> V_82 ) ;
if ( ! V_120 )
return;
while ( F_69 ( V_120 ) -> V_226 != V_226 ) {
if ( F_150 ( & V_14 -> V_82 , V_120 ) )
return;
V_120 = F_151 ( & V_14 -> V_82 , V_120 ) ;
}
if ( V_14 -> V_221 &&
F_69 ( V_120 ) -> V_230 == V_14 -> V_221 ) {
F_59 ( V_14 -> V_3 , V_14 , V_222 ) ;
return;
}
V_229 = F_152 ( V_120 , V_41 ) ;
F_69 ( V_120 ) -> V_230 ++ ;
V_133 = F_146 ( V_14 , V_229 -> V_26 + V_147 ) ;
V_133 &= F_153 ( V_14 ) ;
if ( F_75 ( V_144 , & V_14 -> V_145 ) )
V_133 |= F_76 ( V_14 ) ;
V_133 |= F_87 ( V_14 , V_14 -> V_152 ) ;
V_133 |= F_147 ( V_14 , V_226 ) ;
F_80 ( V_14 , V_133 , V_229 -> V_26 + V_147 ) ;
if ( V_14 -> V_141 == V_142 ) {
V_141 = F_82 ( 0 , ( T_2 * ) V_229 -> V_26 ,
V_229 -> V_118 - V_143 ) ;
F_83 ( V_141 ,
V_229 -> V_26 + V_229 -> V_118 - V_143 ) ;
}
F_71 ( V_14 , V_229 ) ;
}
static int F_154 ( struct V_1 * V_14 )
{
struct V_119 * V_120 , * V_229 ;
T_1 V_141 ;
T_7 V_133 ;
int V_231 = 0 ;
if ( V_14 -> V_23 != V_33 )
return - V_232 ;
while ( ( V_120 = V_14 -> V_233 ) && ( ! F_155 ( V_14 ) ) ) {
if ( V_14 -> V_221 &&
F_69 ( V_120 ) -> V_230 == V_14 -> V_221 ) {
F_59 ( V_14 -> V_3 , V_14 , V_222 ) ;
break;
}
V_229 = F_152 ( V_120 , V_41 ) ;
F_69 ( V_120 ) -> V_230 ++ ;
V_133 = F_146 ( V_14 , V_229 -> V_26 + V_147 ) ;
V_133 &= F_153 ( V_14 ) ;
if ( F_75 ( V_144 , & V_14 -> V_145 ) )
V_133 |= F_76 ( V_14 ) ;
V_133 |= F_87 ( V_14 , V_14 -> V_152 ) ;
V_133 |= F_147 ( V_14 , V_14 -> V_228 ) ;
F_80 ( V_14 , V_133 , V_229 -> V_26 + V_147 ) ;
if ( V_14 -> V_141 == V_142 ) {
V_141 = F_82 ( 0 , ( T_2 * ) V_120 -> V_26 ,
V_229 -> V_118 - V_143 ) ;
F_83 ( V_141 , V_120 -> V_26 +
V_229 -> V_118 - V_143 ) ;
}
F_71 ( V_14 , V_229 ) ;
F_156 ( V_14 ) ;
F_69 ( V_120 ) -> V_226 = V_14 -> V_228 ;
V_14 -> V_228 = F_148 ( V_14 , V_14 -> V_228 ) ;
if ( F_69 ( V_120 ) -> V_230 == 1 ) {
V_14 -> V_217 ++ ;
if ( ! V_231 ++ )
F_52 ( V_14 ) ;
}
V_14 -> V_234 ++ ;
if ( F_150 ( & V_14 -> V_82 , V_120 ) )
V_14 -> V_233 = NULL ;
else
V_14 -> V_233 = F_151 ( & V_14 -> V_82 , V_120 ) ;
}
return V_231 ;
}
static int F_157 ( struct V_1 * V_14 )
{
int V_235 ;
if ( ! F_158 ( & V_14 -> V_82 ) )
V_14 -> V_233 = V_14 -> V_82 . V_236 ;
V_14 -> V_228 = V_14 -> V_227 ;
V_235 = F_154 ( V_14 ) ;
return V_235 ;
}
static void F_159 ( struct V_1 * V_14 )
{
T_7 V_133 = 0 ;
V_133 |= F_87 ( V_14 , V_14 -> V_152 ) ;
if ( F_48 ( V_148 , & V_14 -> V_145 ) ) {
V_133 |= F_85 ( V_14 , V_149 ) ;
F_86 ( V_150 , & V_14 -> V_145 ) ;
F_72 ( V_14 , V_133 ) ;
return;
}
if ( F_154 ( V_14 ) > 0 )
return;
V_133 |= F_85 ( V_14 , V_151 ) ;
F_72 ( V_14 , V_133 ) ;
}
static void F_160 ( struct V_1 * V_14 )
{
F_52 ( V_14 ) ;
F_159 ( V_14 ) ;
}
static void F_161 ( struct V_1 * V_14 )
{
struct V_85 * V_237 ;
T_7 V_133 ;
V_133 = F_85 ( V_14 , V_238 ) ;
V_133 |= F_76 ( V_14 ) ;
V_237 = F_162 ( ( & V_14 -> V_239 ) -> V_240 , struct V_85 , V_72 ) ;
V_133 |= F_87 ( V_14 , V_237 -> V_226 ) ;
F_72 ( V_14 , V_133 ) ;
}
static inline int F_163 ( struct V_1 * V_14 ,
struct V_241 * V_242 , int V_118 ,
int V_136 , struct V_119 * V_120 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_119 * * V_243 ;
int V_15 , V_244 = 0 ;
if ( F_164 ( F_79 ( V_120 , V_136 ) , V_242 -> V_245 , V_136 ) )
return - V_246 ;
V_244 += V_136 ;
V_118 -= V_136 ;
V_243 = & F_165 ( V_120 ) -> V_247 ;
while ( V_118 ) {
V_136 = F_73 (unsigned int, conn->mtu, len) ;
* V_243 = V_14 -> V_24 -> V_248 ( V_14 , V_136 ,
V_242 -> V_249 & V_250 ,
& V_15 ) ;
if ( ! * V_243 )
return V_15 ;
if ( F_164 ( F_79 ( * V_243 , V_136 ) , V_242 -> V_245 , V_136 ) )
return - V_246 ;
( * V_243 ) -> V_127 = V_120 -> V_127 ;
V_244 += V_136 ;
V_118 -= V_136 ;
V_243 = & ( * V_243 ) -> V_236 ;
}
return V_244 ;
}
static struct V_119 * F_166 ( struct V_1 * V_14 ,
struct V_241 * V_242 , T_9 V_118 ,
T_7 V_127 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_119 * V_120 ;
int V_15 , V_136 , V_137 = V_147 + V_251 ;
struct V_134 * V_135 ;
F_19 ( L_19 , V_14 , ( int ) V_118 , V_127 ) ;
V_136 = F_73 (unsigned int, (conn->mtu - hlen), len) ;
V_120 = V_14 -> V_24 -> V_248 ( V_14 , V_136 + V_137 ,
V_242 -> V_249 & V_250 , & V_15 ) ;
if ( ! V_120 )
return F_167 ( V_15 ) ;
V_120 -> V_127 = V_127 ;
V_135 = (struct V_134 * ) F_79 ( V_120 , V_147 ) ;
V_135 -> V_4 = F_14 ( V_14 -> V_6 ) ;
V_135 -> V_118 = F_14 ( V_118 + ( V_137 - V_147 ) ) ;
F_83 ( V_14 -> V_10 , F_79 ( V_120 , 2 ) ) ;
V_15 = F_163 ( V_14 , V_242 , V_118 , V_136 , V_120 ) ;
if ( F_168 ( V_15 < 0 ) ) {
F_109 ( V_120 ) ;
return F_167 ( V_15 ) ;
}
return V_120 ;
}
static struct V_119 * F_169 ( struct V_1 * V_14 ,
struct V_241 * V_242 , T_9 V_118 ,
T_7 V_127 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_119 * V_120 ;
int V_15 , V_136 , V_137 = V_147 ;
struct V_134 * V_135 ;
F_19 ( L_20 , V_14 , ( int ) V_118 ) ;
V_136 = F_73 (unsigned int, (conn->mtu - hlen), len) ;
V_120 = V_14 -> V_24 -> V_248 ( V_14 , V_136 + V_137 ,
V_242 -> V_249 & V_250 , & V_15 ) ;
if ( ! V_120 )
return F_167 ( V_15 ) ;
V_120 -> V_127 = V_127 ;
V_135 = (struct V_134 * ) F_79 ( V_120 , V_147 ) ;
V_135 -> V_4 = F_14 ( V_14 -> V_6 ) ;
V_135 -> V_118 = F_14 ( V_118 + ( V_137 - V_147 ) ) ;
V_15 = F_163 ( V_14 , V_242 , V_118 , V_136 , V_120 ) ;
if ( F_168 ( V_15 < 0 ) ) {
F_109 ( V_120 ) ;
return F_167 ( V_15 ) ;
}
return V_120 ;
}
static struct V_119 * F_170 ( struct V_1 * V_14 ,
struct V_241 * V_242 , T_9 V_118 ,
T_7 V_133 , T_1 V_252 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_119 * V_120 ;
int V_15 , V_136 , V_137 ;
struct V_134 * V_135 ;
F_19 ( L_20 , V_14 , ( int ) V_118 ) ;
if ( ! V_3 )
return F_167 ( - V_232 ) ;
if ( F_48 ( V_138 , & V_14 -> V_121 ) )
V_137 = V_139 ;
else
V_137 = V_140 ;
if ( V_252 )
V_137 += V_253 ;
if ( V_14 -> V_141 == V_142 )
V_137 += V_143 ;
V_136 = F_73 (unsigned int, (conn->mtu - hlen), len) ;
V_120 = V_14 -> V_24 -> V_248 ( V_14 , V_136 + V_137 ,
V_242 -> V_249 & V_250 , & V_15 ) ;
if ( ! V_120 )
return F_167 ( V_15 ) ;
V_135 = (struct V_134 * ) F_79 ( V_120 , V_147 ) ;
V_135 -> V_4 = F_14 ( V_14 -> V_6 ) ;
V_135 -> V_118 = F_14 ( V_118 + ( V_137 - V_147 ) ) ;
F_80 ( V_14 , V_133 , F_79 ( V_120 , F_81 ( V_14 ) ) ) ;
if ( V_252 )
F_83 ( V_252 , F_79 ( V_120 , V_253 ) ) ;
V_15 = F_163 ( V_14 , V_242 , V_118 , V_136 , V_120 ) ;
if ( F_168 ( V_15 < 0 ) ) {
F_109 ( V_120 ) ;
return F_167 ( V_15 ) ;
}
if ( V_14 -> V_141 == V_142 )
F_83 ( 0 , F_79 ( V_120 , V_143 ) ) ;
F_69 ( V_120 ) -> V_230 = 0 ;
return V_120 ;
}
static int F_171 ( struct V_1 * V_14 , struct V_241 * V_242 , T_9 V_118 )
{
struct V_119 * V_120 ;
struct V_254 V_255 ;
T_7 V_133 ;
T_9 V_256 = 0 ;
F_172 ( & V_255 ) ;
V_133 = F_173 ( V_14 , V_257 ) ;
V_120 = F_170 ( V_14 , V_242 , V_14 -> V_258 , V_133 , V_118 ) ;
if ( F_125 ( V_120 ) )
return F_126 ( V_120 ) ;
F_174 ( & V_255 , V_120 ) ;
V_118 -= V_14 -> V_258 ;
V_256 += V_14 -> V_258 ;
while ( V_118 > 0 ) {
T_9 V_259 ;
if ( V_118 > V_14 -> V_258 ) {
V_133 = F_173 ( V_14 , V_260 ) ;
V_259 = V_14 -> V_258 ;
} else {
V_133 = F_173 ( V_14 , V_261 ) ;
V_259 = V_118 ;
}
V_120 = F_170 ( V_14 , V_242 , V_259 , V_133 , 0 ) ;
if ( F_125 ( V_120 ) ) {
F_49 ( & V_255 ) ;
return F_126 ( V_120 ) ;
}
F_174 ( & V_255 , V_120 ) ;
V_118 -= V_259 ;
V_256 += V_259 ;
}
F_175 ( & V_255 , & V_14 -> V_82 ) ;
if ( V_14 -> V_233 == NULL )
V_14 -> V_233 = V_255 . V_236 ;
return V_256 ;
}
int F_176 ( struct V_1 * V_14 , struct V_241 * V_242 , T_9 V_118 ,
T_7 V_127 )
{
struct V_119 * V_120 ;
T_7 V_133 ;
int V_15 ;
if ( V_14 -> V_49 == V_57 ) {
V_120 = F_166 ( V_14 , V_242 , V_118 , V_127 ) ;
if ( F_125 ( V_120 ) )
return F_126 ( V_120 ) ;
F_71 ( V_14 , V_120 ) ;
return V_118 ;
}
switch ( V_14 -> V_83 ) {
case V_205 :
if ( V_118 > V_14 -> V_53 )
return - V_262 ;
V_120 = F_169 ( V_14 , V_242 , V_118 , V_127 ) ;
if ( F_125 ( V_120 ) )
return F_126 ( V_120 ) ;
F_71 ( V_14 , V_120 ) ;
V_15 = V_118 ;
break;
case V_84 :
case V_172 :
if ( V_118 <= V_14 -> V_258 ) {
V_133 = F_173 ( V_14 , V_263 ) ;
V_120 = F_170 ( V_14 , V_242 , V_118 , V_133 ,
0 ) ;
if ( F_125 ( V_120 ) )
return F_126 ( V_120 ) ;
F_174 ( & V_14 -> V_82 , V_120 ) ;
if ( V_14 -> V_233 == NULL )
V_14 -> V_233 = V_120 ;
} else {
V_15 = F_171 ( V_14 , V_242 , V_118 ) ;
if ( V_15 < 0 )
return V_15 ;
}
if ( V_14 -> V_83 == V_172 ) {
F_145 ( V_14 ) ;
V_15 = V_118 ;
break;
}
if ( F_48 ( V_264 , & V_14 -> V_145 ) &&
F_48 ( V_225 , & V_14 -> V_145 ) ) {
V_15 = V_118 ;
break;
}
V_15 = F_154 ( V_14 ) ;
if ( V_15 >= 0 )
V_15 = V_118 ;
break;
default:
F_19 ( L_21 , V_14 -> V_83 ) ;
V_15 = - V_210 ;
}
return V_15 ;
}
static void F_177 ( struct V_2 * V_3 , struct V_119 * V_120 )
{
struct V_119 * V_265 ;
struct V_1 * V_14 ;
F_19 ( L_11 , V_3 ) ;
F_5 ( & V_3 -> V_8 ) ;
F_2 (chan, &conn->chan_l, list) {
struct V_27 * V_13 = V_14 -> V_13 ;
if ( V_14 -> V_49 != V_104 )
continue;
if ( V_120 -> V_13 == V_13 )
continue;
V_265 = F_152 ( V_120 , V_41 ) ;
if ( ! V_265 )
continue;
if ( V_14 -> V_24 -> V_266 ( V_14 -> V_26 , V_265 ) )
F_109 ( V_265 ) ;
}
F_6 ( & V_3 -> V_8 ) ;
}
static struct V_119 * F_67 ( struct V_2 * V_3 ,
T_2 V_117 , T_2 V_9 , T_1 V_267 , void * V_26 )
{
struct V_119 * V_120 , * * V_243 ;
struct V_268 * V_269 ;
struct V_134 * V_135 ;
int V_118 , V_136 ;
F_19 ( L_22 ,
V_3 , V_117 , V_9 , V_267 ) ;
V_118 = V_147 + V_270 + V_267 ;
V_136 = F_73 (unsigned int, conn->mtu, len) ;
V_120 = F_78 ( V_136 , V_41 ) ;
if ( ! V_120 )
return NULL ;
V_135 = (struct V_134 * ) F_79 ( V_120 , V_147 ) ;
V_135 -> V_118 = F_14 ( V_270 + V_267 ) ;
if ( V_3 -> V_51 -> type == V_52 )
V_135 -> V_4 = F_14 ( V_271 ) ;
else
V_135 -> V_4 = F_14 ( V_59 ) ;
V_269 = (struct V_268 * ) F_79 ( V_120 , V_270 ) ;
V_269 -> V_117 = V_117 ;
V_269 -> V_9 = V_9 ;
V_269 -> V_118 = F_14 ( V_267 ) ;
if ( V_267 ) {
V_136 -= V_147 + V_270 ;
memcpy ( F_79 ( V_120 , V_136 ) , V_26 , V_136 ) ;
V_26 += V_136 ;
}
V_118 -= V_120 -> V_118 ;
V_243 = & F_165 ( V_120 ) -> V_247 ;
while ( V_118 ) {
V_136 = F_73 (unsigned int, conn->mtu, len) ;
* V_243 = F_78 ( V_136 , V_41 ) ;
if ( ! * V_243 )
goto V_272;
memcpy ( F_79 ( * V_243 , V_136 ) , V_26 , V_136 ) ;
V_118 -= V_136 ;
V_26 += V_136 ;
V_243 = & ( * V_243 ) -> V_236 ;
}
return V_120 ;
V_272:
F_109 ( V_120 ) ;
return NULL ;
}
static inline int F_178 ( void * * V_273 , int * type , int * V_274 , unsigned long * V_275 )
{
struct V_276 * V_277 = * V_273 ;
int V_118 ;
V_118 = V_278 + V_277 -> V_118 ;
* V_273 += V_118 ;
* type = V_277 -> type ;
* V_274 = V_277 -> V_118 ;
switch ( V_277 -> V_118 ) {
case 1 :
* V_275 = * ( ( T_2 * ) V_277 -> V_275 ) ;
break;
case 2 :
* V_275 = F_179 ( V_277 -> V_275 ) ;
break;
case 4 :
* V_275 = F_180 ( V_277 -> V_275 ) ;
break;
default:
* V_275 = ( unsigned long ) V_277 -> V_275 ;
break;
}
F_19 ( L_23 , * type , V_277 -> V_118 , * V_275 ) ;
return V_118 ;
}
static void F_181 ( void * * V_273 , T_2 type , T_2 V_118 , unsigned long V_275 )
{
struct V_276 * V_277 = * V_273 ;
F_19 ( L_23 , type , V_118 , V_275 ) ;
V_277 -> type = type ;
V_277 -> V_118 = V_118 ;
switch ( V_118 ) {
case 1 :
* ( ( T_2 * ) V_277 -> V_275 ) = V_275 ;
break;
case 2 :
F_83 ( V_275 , V_277 -> V_275 ) ;
break;
case 4 :
F_182 ( V_275 , V_277 -> V_275 ) ;
break;
default:
memcpy ( V_277 -> V_275 , ( void * ) V_275 , V_118 ) ;
break;
}
* V_273 += V_278 + V_118 ;
}
static void F_183 ( void * * V_273 , struct V_1 * V_14 )
{
struct V_279 V_280 ;
switch ( V_14 -> V_83 ) {
case V_84 :
V_280 . V_115 = V_14 -> V_60 ;
V_280 . V_281 = V_14 -> V_62 ;
V_280 . V_282 = F_14 ( V_14 -> V_64 ) ;
V_280 . V_283 = F_184 ( V_14 -> V_66 ) ;
V_280 . V_284 = F_184 ( V_69 ) ;
V_280 . V_285 = F_184 ( V_71 ) ;
break;
case V_172 :
V_280 . V_115 = 1 ;
V_280 . V_281 = V_63 ;
V_280 . V_282 = F_14 ( V_14 -> V_64 ) ;
V_280 . V_283 = F_184 ( V_14 -> V_66 ) ;
V_280 . V_284 = 0 ;
V_280 . V_285 = 0 ;
break;
default:
return;
}
F_181 ( V_273 , V_286 , sizeof( V_280 ) ,
( unsigned long ) & V_280 ) ;
}
static void F_185 ( struct V_29 * V_30 )
{
struct V_1 * V_14 = F_27 ( V_30 , struct V_1 ,
V_287 . V_30 ) ;
F_19 ( L_18 , V_14 ) ;
F_28 ( V_14 ) ;
F_159 ( V_14 ) ;
F_30 ( V_14 ) ;
F_31 ( V_14 ) ;
}
static inline void F_186 ( struct V_1 * V_14 )
{
V_14 -> V_227 = 0 ;
V_14 -> V_217 = 0 ;
V_14 -> V_152 = 0 ;
V_14 -> V_288 = 0 ;
V_14 -> V_234 = 0 ;
F_36 ( & V_14 -> V_224 , F_141 ) ;
F_36 ( & V_14 -> V_219 , F_139 ) ;
F_36 ( & V_14 -> V_287 , F_185 ) ;
F_172 ( & V_14 -> V_88 ) ;
F_117 ( & V_14 -> V_239 ) ;
}
static inline T_6 F_187 ( T_6 V_83 , T_5 V_289 )
{
switch ( V_83 ) {
case V_172 :
case V_84 :
if ( F_92 ( V_83 , V_289 ) )
return V_83 ;
default:
return V_205 ;
}
}
static inline bool F_188 ( struct V_1 * V_14 )
{
return V_290 && V_14 -> V_3 -> V_166 & V_291 ;
}
static inline bool F_189 ( struct V_1 * V_14 )
{
return V_290 && V_14 -> V_3 -> V_166 & V_292 ;
}
static inline void F_190 ( struct V_1 * V_14 )
{
if ( V_14 -> V_293 > V_294 &&
F_188 ( V_14 ) ) {
F_86 ( V_138 , & V_14 -> V_121 ) ;
V_14 -> V_295 = V_296 ;
} else {
V_14 -> V_293 = F_73 ( T_1 , V_14 -> V_293 ,
V_294 ) ;
V_14 -> V_295 = V_294 ;
}
}
static int F_94 ( struct V_1 * V_14 , void * V_26 )
{
struct V_297 * V_155 = V_26 ;
struct V_298 V_299 = { . V_83 = V_14 -> V_83 } ;
void * V_273 = V_155 -> V_26 ;
T_1 V_256 ;
F_19 ( L_18 , V_14 ) ;
if ( V_14 -> V_183 || V_14 -> V_300 )
goto V_18;
switch ( V_14 -> V_83 ) {
case V_172 :
case V_84 :
if ( F_48 ( V_175 , & V_14 -> V_80 ) )
break;
if ( F_189 ( V_14 ) )
F_86 ( V_301 , & V_14 -> V_121 ) ;
default:
V_14 -> V_83 = F_187 ( V_299 . V_83 , V_14 -> V_3 -> V_166 ) ;
break;
}
V_18:
if ( V_14 -> V_302 != V_56 )
F_181 ( & V_273 , V_303 , 2 , V_14 -> V_302 ) ;
switch ( V_14 -> V_83 ) {
case V_205 :
if ( ! ( V_14 -> V_3 -> V_166 & V_170 ) &&
! ( V_14 -> V_3 -> V_166 & V_171 ) )
break;
V_299 . V_83 = V_205 ;
V_299 . V_304 = 0 ;
V_299 . V_305 = 0 ;
V_299 . V_306 = 0 ;
V_299 . V_307 = 0 ;
V_299 . V_308 = 0 ;
F_181 ( & V_273 , V_309 , sizeof( V_299 ) ,
( unsigned long ) & V_299 ) ;
break;
case V_84 :
V_299 . V_83 = V_84 ;
V_299 . V_305 = V_14 -> V_310 ;
V_299 . V_306 = 0 ;
V_299 . V_307 = 0 ;
V_256 = F_73 ( T_1 , V_311 , V_14 -> V_3 -> V_200 -
V_139 -
V_253 -
V_143 ) ;
V_299 . V_308 = F_14 ( V_256 ) ;
F_190 ( V_14 ) ;
V_299 . V_304 = F_73 ( T_1 , V_14 -> V_293 ,
V_294 ) ;
F_181 ( & V_273 , V_309 , sizeof( V_299 ) ,
( unsigned long ) & V_299 ) ;
if ( F_48 ( V_301 , & V_14 -> V_121 ) )
F_183 ( & V_273 , V_14 ) ;
if ( ! ( V_14 -> V_3 -> V_166 & V_312 ) )
break;
if ( V_14 -> V_141 == V_313 ||
F_48 ( V_314 , & V_14 -> V_80 ) ) {
V_14 -> V_141 = V_313 ;
F_181 ( & V_273 , V_315 , 1 , V_14 -> V_141 ) ;
}
if ( F_48 ( V_138 , & V_14 -> V_121 ) )
F_181 ( & V_273 , V_316 , 2 ,
V_14 -> V_293 ) ;
break;
case V_172 :
V_299 . V_83 = V_172 ;
V_299 . V_304 = 0 ;
V_299 . V_305 = 0 ;
V_299 . V_306 = 0 ;
V_299 . V_307 = 0 ;
V_256 = F_73 ( T_1 , V_311 , V_14 -> V_3 -> V_200 -
V_139 -
V_253 -
V_143 ) ;
V_299 . V_308 = F_14 ( V_256 ) ;
F_181 ( & V_273 , V_309 , sizeof( V_299 ) ,
( unsigned long ) & V_299 ) ;
if ( F_48 ( V_301 , & V_14 -> V_121 ) )
F_183 ( & V_273 , V_14 ) ;
if ( ! ( V_14 -> V_3 -> V_166 & V_312 ) )
break;
if ( V_14 -> V_141 == V_313 ||
F_48 ( V_314 , & V_14 -> V_80 ) ) {
V_14 -> V_141 = V_313 ;
F_181 ( & V_273 , V_315 , 1 , V_14 -> V_141 ) ;
}
break;
}
V_155 -> V_6 = F_14 ( V_14 -> V_6 ) ;
V_155 -> V_121 = F_14 ( 0 ) ;
return V_273 - V_26 ;
}
static int F_191 ( struct V_1 * V_14 , void * V_26 )
{
struct V_317 * V_95 = V_26 ;
void * V_273 = V_95 -> V_26 ;
void * V_155 = V_14 -> V_318 ;
int V_118 = V_14 -> V_319 ;
int type , V_320 , V_274 ;
unsigned long V_275 ;
struct V_298 V_299 = { . V_83 = V_205 } ;
struct V_279 V_280 ;
T_2 V_321 = 0 ;
T_1 V_200 = V_56 ;
T_1 V_96 = V_322 ;
T_1 V_256 ;
F_19 ( L_18 , V_14 ) ;
while ( V_118 >= V_278 ) {
V_118 -= F_178 ( & V_155 , & type , & V_274 , & V_275 ) ;
V_320 = type & V_323 ;
type &= V_324 ;
switch ( type ) {
case V_303 :
V_200 = V_275 ;
break;
case V_325 :
V_14 -> V_285 = V_275 ;
break;
case V_326 :
break;
case V_309 :
if ( V_274 == sizeof( V_299 ) )
memcpy ( & V_299 , ( void * ) V_275 , V_274 ) ;
break;
case V_315 :
if ( V_275 == V_313 )
F_86 ( V_314 , & V_14 -> V_80 ) ;
break;
case V_286 :
V_321 = 1 ;
if ( V_274 == sizeof( V_280 ) )
memcpy ( & V_280 , ( void * ) V_275 , V_274 ) ;
break;
case V_316 :
if ( ! V_290 )
return - V_35 ;
F_86 ( V_138 , & V_14 -> V_121 ) ;
F_86 ( V_327 , & V_14 -> V_80 ) ;
V_14 -> V_295 = V_296 ;
V_14 -> V_328 = V_275 ;
break;
default:
if ( V_320 )
break;
V_96 = V_329 ;
* ( ( T_2 * ) V_273 ++ ) = type ;
break;
}
}
if ( V_14 -> V_300 || V_14 -> V_183 > 1 )
goto V_18;
switch ( V_14 -> V_83 ) {
case V_172 :
case V_84 :
if ( ! F_48 ( V_175 , & V_14 -> V_80 ) ) {
V_14 -> V_83 = F_187 ( V_299 . V_83 ,
V_14 -> V_3 -> V_166 ) ;
break;
}
if ( V_321 ) {
if ( F_189 ( V_14 ) )
F_86 ( V_301 , & V_14 -> V_121 ) ;
else
return - V_35 ;
}
if ( V_14 -> V_83 != V_299 . V_83 )
return - V_35 ;
break;
}
V_18:
if ( V_14 -> V_83 != V_299 . V_83 ) {
V_96 = V_330 ;
V_299 . V_83 = V_14 -> V_83 ;
if ( V_14 -> V_300 == 1 )
return - V_35 ;
F_181 ( & V_273 , V_309 ,
sizeof( V_299 ) , ( unsigned long ) & V_299 ) ;
}
if ( V_96 == V_322 ) {
if ( V_200 < V_331 )
V_96 = V_330 ;
else {
V_14 -> V_53 = V_200 ;
F_86 ( V_332 , & V_14 -> V_80 ) ;
}
F_181 ( & V_273 , V_303 , 2 , V_14 -> V_53 ) ;
if ( V_321 ) {
if ( V_14 -> V_62 != V_333 &&
V_280 . V_281 != V_333 &&
V_280 . V_281 != V_14 -> V_62 ) {
V_96 = V_330 ;
if ( V_14 -> V_183 >= 1 )
return - V_35 ;
F_181 ( & V_273 , V_286 ,
sizeof( V_280 ) ,
( unsigned long ) & V_280 ) ;
} else {
V_96 = V_334 ;
F_86 ( V_335 , & V_14 -> V_80 ) ;
}
}
switch ( V_299 . V_83 ) {
case V_205 :
V_14 -> V_141 = V_313 ;
F_86 ( V_336 , & V_14 -> V_80 ) ;
break;
case V_84 :
if ( ! F_48 ( V_327 , & V_14 -> V_80 ) )
V_14 -> V_328 = V_299 . V_304 ;
else
V_299 . V_304 = V_294 ;
V_14 -> V_221 = V_299 . V_305 ;
V_256 = F_73 ( T_1 , F_192 ( V_299 . V_308 ) ,
V_14 -> V_3 -> V_200 -
V_139 -
V_253 -
V_143 ) ;
V_299 . V_308 = F_14 ( V_256 ) ;
V_14 -> V_258 = V_256 ;
V_299 . V_306 =
F_192 ( V_337 ) ;
V_299 . V_307 =
F_192 ( V_338 ) ;
F_86 ( V_336 , & V_14 -> V_80 ) ;
F_181 ( & V_273 , V_309 ,
sizeof( V_299 ) , ( unsigned long ) & V_299 ) ;
if ( F_48 ( V_301 , & V_14 -> V_121 ) ) {
V_14 -> V_339 = V_280 . V_115 ;
V_14 -> V_340 = V_280 . V_281 ;
V_14 -> V_341 = F_192 ( V_280 . V_282 ) ;
V_14 -> V_342 =
F_193 ( V_280 . V_285 ) ;
V_14 -> V_343 =
F_193 ( V_280 . V_284 ) ;
V_14 -> V_344 =
F_193 ( V_280 . V_283 ) ;
F_181 ( & V_273 , V_286 ,
sizeof( V_280 ) , ( unsigned long ) & V_280 ) ;
}
break;
case V_172 :
V_256 = F_73 ( T_1 , F_192 ( V_299 . V_308 ) ,
V_14 -> V_3 -> V_200 -
V_139 -
V_253 -
V_143 ) ;
V_299 . V_308 = F_14 ( V_256 ) ;
V_14 -> V_258 = V_256 ;
F_86 ( V_336 , & V_14 -> V_80 ) ;
F_181 ( & V_273 , V_309 ,
sizeof( V_299 ) , ( unsigned long ) & V_299 ) ;
break;
default:
V_96 = V_330 ;
memset ( & V_299 , 0 , sizeof( V_299 ) ) ;
V_299 . V_83 = V_14 -> V_83 ;
}
if ( V_96 == V_322 )
F_86 ( V_79 , & V_14 -> V_80 ) ;
}
V_95 -> V_7 = F_14 ( V_14 -> V_6 ) ;
V_95 -> V_96 = F_14 ( V_96 ) ;
V_95 -> V_121 = F_14 ( 0x0000 ) ;
return V_273 - V_26 ;
}
static int F_194 ( struct V_1 * V_14 , void * V_95 , int V_118 , void * V_26 , T_1 * V_96 )
{
struct V_297 * V_155 = V_26 ;
void * V_273 = V_155 -> V_26 ;
int type , V_274 ;
unsigned long V_275 ;
struct V_298 V_299 = { . V_83 = V_205 } ;
struct V_279 V_280 ;
F_19 ( L_24 , V_14 , V_95 , V_118 , V_26 ) ;
while ( V_118 >= V_278 ) {
V_118 -= F_178 ( & V_95 , & type , & V_274 , & V_275 ) ;
switch ( type ) {
case V_303 :
if ( V_275 < V_331 ) {
* V_96 = V_330 ;
V_14 -> V_302 = V_331 ;
} else
V_14 -> V_302 = V_275 ;
F_181 ( & V_273 , V_303 , 2 , V_14 -> V_302 ) ;
break;
case V_325 :
V_14 -> V_285 = V_275 ;
F_181 ( & V_273 , V_325 ,
2 , V_14 -> V_285 ) ;
break;
case V_309 :
if ( V_274 == sizeof( V_299 ) )
memcpy ( & V_299 , ( void * ) V_275 , V_274 ) ;
if ( F_48 ( V_175 , & V_14 -> V_80 ) &&
V_299 . V_83 != V_14 -> V_83 )
return - V_35 ;
V_14 -> V_141 = 0 ;
F_181 ( & V_273 , V_309 ,
sizeof( V_299 ) , ( unsigned long ) & V_299 ) ;
break;
case V_316 :
V_14 -> V_293 = F_73 ( T_1 , V_275 ,
V_296 ) ;
F_181 ( & V_273 , V_316 , 2 ,
V_14 -> V_293 ) ;
break;
case V_286 :
if ( V_274 == sizeof( V_280 ) )
memcpy ( & V_280 , ( void * ) V_275 , V_274 ) ;
if ( V_14 -> V_62 != V_333 &&
V_280 . V_281 != V_333 &&
V_280 . V_281 != V_14 -> V_62 )
return - V_35 ;
F_181 ( & V_273 , V_286 ,
sizeof( V_280 ) , ( unsigned long ) & V_280 ) ;
break;
}
}
if ( V_14 -> V_83 == V_205 && V_14 -> V_83 != V_299 . V_83 )
return - V_35 ;
V_14 -> V_83 = V_299 . V_83 ;
if ( * V_96 == V_322 || * V_96 == V_334 ) {
switch ( V_299 . V_83 ) {
case V_84 :
V_14 -> V_306 = F_192 ( V_299 . V_306 ) ;
V_14 -> V_307 = F_192 ( V_299 . V_307 ) ;
V_14 -> V_345 = F_192 ( V_299 . V_308 ) ;
if ( F_48 ( V_301 , & V_14 -> V_121 ) ) {
V_14 -> V_64 = F_192 ( V_280 . V_282 ) ;
V_14 -> V_66 =
F_193 ( V_280 . V_283 ) ;
V_14 -> V_68 = F_193 ( V_280 . V_284 ) ;
V_14 -> V_70 =
F_193 ( V_280 . V_285 ) ;
}
break;
case V_172 :
V_14 -> V_345 = F_192 ( V_299 . V_308 ) ;
}
}
V_155 -> V_6 = F_14 ( V_14 -> V_6 ) ;
V_155 -> V_121 = F_14 ( 0x0000 ) ;
return V_273 - V_26 ;
}
static int F_195 ( struct V_1 * V_14 , void * V_26 , T_1 V_96 , T_1 V_121 )
{
struct V_317 * V_95 = V_26 ;
void * V_273 = V_95 -> V_26 ;
F_19 ( L_18 , V_14 ) ;
V_95 -> V_7 = F_14 ( V_14 -> V_6 ) ;
V_95 -> V_96 = F_14 ( V_96 ) ;
V_95 -> V_121 = F_14 ( V_121 ) ;
return V_273 - V_26 ;
}
void F_196 ( struct V_1 * V_14 )
{
struct V_94 V_95 ;
struct V_2 * V_3 = V_14 -> V_3 ;
T_2 V_176 [ 128 ] ;
V_95 . V_7 = F_14 ( V_14 -> V_6 ) ;
V_95 . V_6 = F_14 ( V_14 -> V_7 ) ;
V_95 . V_96 = F_14 ( V_179 ) ;
V_95 . V_101 = F_14 ( V_102 ) ;
F_60 ( V_3 , V_14 -> V_9 ,
V_103 , sizeof( V_95 ) , & V_95 ) ;
if ( F_197 ( V_181 , & V_14 -> V_80 ) )
return;
F_60 ( V_3 , F_64 ( V_3 ) , V_182 ,
F_94 ( V_14 , V_176 ) , V_176 ) ;
V_14 -> V_183 ++ ;
}
static void F_198 ( struct V_1 * V_14 , void * V_95 , int V_118 )
{
int type , V_274 ;
unsigned long V_275 ;
struct V_298 V_299 ;
F_19 ( L_25 , V_14 , V_95 , V_118 ) ;
if ( ( V_14 -> V_83 != V_84 ) && ( V_14 -> V_83 != V_172 ) )
return;
while ( V_118 >= V_278 ) {
V_118 -= F_178 ( & V_95 , & type , & V_274 , & V_275 ) ;
switch ( type ) {
case V_309 :
if ( V_274 == sizeof( V_299 ) )
memcpy ( & V_299 , ( void * ) V_275 , V_274 ) ;
goto V_18;
}
}
V_299 . V_83 = V_14 -> V_83 ;
V_299 . V_306 = F_14 ( V_337 ) ;
V_299 . V_307 = F_14 ( V_338 ) ;
V_299 . V_308 = F_14 ( V_14 -> V_302 ) ;
F_199 ( L_26 ) ;
V_18:
switch ( V_299 . V_83 ) {
case V_84 :
V_14 -> V_306 = F_192 ( V_299 . V_306 ) ;
V_14 -> V_307 = F_192 ( V_299 . V_307 ) ;
V_14 -> V_345 = F_192 ( V_299 . V_308 ) ;
break;
case V_172 :
V_14 -> V_345 = F_192 ( V_299 . V_308 ) ;
}
}
static inline int F_200 ( struct V_2 * V_3 , struct V_268 * V_269 , T_2 * V_26 )
{
struct V_346 * V_347 = (struct V_346 * ) V_26 ;
if ( V_347 -> V_32 != V_348 )
return 0 ;
if ( ( V_3 -> V_157 & V_158 ) &&
V_269 -> V_9 == V_3 -> V_162 ) {
F_201 ( & V_3 -> V_163 ) ;
V_3 -> V_157 |= V_159 ;
V_3 -> V_162 = 0 ;
F_93 ( V_3 ) ;
}
return 0 ;
}
static inline int F_202 ( struct V_2 * V_3 , struct V_268 * V_269 , T_2 * V_26 )
{
struct V_154 * V_155 = (struct V_154 * ) V_26 ;
struct V_94 V_95 ;
struct V_1 * V_14 = NULL , * V_186 ;
struct V_27 * V_74 , * V_13 = NULL ;
int V_96 , V_101 = V_102 ;
T_1 V_6 = 0 , V_7 = F_123 ( V_155 -> V_7 ) ;
T_3 V_10 = V_155 -> V_10 ;
F_19 ( L_27 , V_10 , V_7 ) ;
V_186 = F_118 ( V_90 , V_10 , V_3 -> V_11 ) ;
if ( ! V_186 ) {
V_96 = V_99 ;
goto V_349;
}
V_74 = V_186 -> V_13 ;
F_5 ( & V_3 -> V_8 ) ;
F_22 ( V_74 ) ;
if ( V_10 != F_14 ( 0x0001 ) &&
! F_203 ( V_3 -> V_51 ) ) {
V_3 -> V_47 = V_350 ;
V_96 = V_98 ;
goto V_351;
}
V_96 = V_352 ;
if ( F_99 ( V_74 ) ) {
F_19 ( L_13 , V_74 -> V_187 ) ;
goto V_351;
}
V_14 = V_186 -> V_24 -> V_189 ( V_186 -> V_26 ) ;
if ( ! V_14 )
goto V_351;
V_13 = V_14 -> V_13 ;
if ( F_1 ( V_3 , V_7 ) ) {
F_46 ( V_13 , V_76 ) ;
V_14 -> V_24 -> V_40 ( V_14 -> V_26 ) ;
goto V_351;
}
F_100 ( V_3 -> V_51 ) ;
F_101 ( & F_11 ( V_13 ) -> V_11 , V_3 -> V_11 ) ;
F_101 ( & F_11 ( V_13 ) -> V_190 , V_3 -> V_190 ) ;
V_14 -> V_10 = V_10 ;
V_14 -> V_6 = V_7 ;
F_102 ( V_74 , V_13 ) ;
F_40 ( V_3 , V_14 ) ;
V_6 = V_14 -> V_7 ;
F_58 ( V_14 , V_13 -> V_92 ) ;
V_14 -> V_9 = V_269 -> V_9 ;
if ( V_3 -> V_157 & V_159 ) {
if ( F_62 ( V_14 ) ) {
if ( F_11 ( V_13 ) -> V_97 ) {
F_18 ( V_14 , V_93 ) ;
V_96 = V_177 ;
V_101 = V_178 ;
V_74 -> V_77 ( V_74 , 0 ) ;
} else {
F_18 ( V_14 , V_34 ) ;
V_96 = V_179 ;
V_101 = V_102 ;
}
} else {
F_18 ( V_14 , V_93 ) ;
V_96 = V_177 ;
V_101 = V_180 ;
}
} else {
F_18 ( V_14 , V_93 ) ;
V_96 = V_177 ;
V_101 = V_102 ;
}
V_351:
F_23 ( V_74 ) ;
F_6 ( & V_3 -> V_8 ) ;
V_349:
V_95 . V_7 = F_14 ( V_7 ) ;
V_95 . V_6 = F_14 ( V_6 ) ;
V_95 . V_96 = F_14 ( V_96 ) ;
V_95 . V_101 = F_14 ( V_101 ) ;
F_60 ( V_3 , V_269 -> V_9 , V_103 , sizeof( V_95 ) , & V_95 ) ;
if ( V_96 == V_177 && V_101 == V_102 ) {
struct V_160 V_353 ;
V_353 . type = F_14 ( V_161 ) ;
V_3 -> V_157 |= V_158 ;
V_3 -> V_162 = F_64 ( V_3 ) ;
F_91 ( & V_3 -> V_163 , V_164 ) ;
F_60 ( V_3 , V_3 -> V_162 ,
V_165 , sizeof( V_353 ) , & V_353 ) ;
}
if ( V_14 && ! F_48 ( V_181 , & V_14 -> V_80 ) &&
V_96 == V_179 ) {
T_2 V_176 [ 128 ] ;
F_86 ( V_181 , & V_14 -> V_80 ) ;
F_60 ( V_3 , F_64 ( V_3 ) , V_182 ,
F_94 ( V_14 , V_176 ) , V_176 ) ;
V_14 -> V_183 ++ ;
}
return 0 ;
}
static inline int F_204 ( struct V_2 * V_3 , struct V_268 * V_269 , T_2 * V_26 )
{
struct V_94 * V_95 = (struct V_94 * ) V_26 ;
T_1 V_7 , V_6 , V_96 , V_101 ;
struct V_1 * V_14 ;
T_2 V_155 [ 128 ] ;
int V_15 ;
V_7 = F_123 ( V_95 -> V_7 ) ;
V_6 = F_123 ( V_95 -> V_6 ) ;
V_96 = F_123 ( V_95 -> V_96 ) ;
V_101 = F_123 ( V_95 -> V_101 ) ;
F_19 ( L_28 ,
V_6 , V_7 , V_96 , V_101 ) ;
F_5 ( & V_3 -> V_8 ) ;
if ( V_7 ) {
V_14 = F_3 ( V_3 , V_7 ) ;
if ( ! V_14 ) {
V_15 = - V_246 ;
goto V_354;
}
} else {
V_14 = F_7 ( V_3 , V_269 -> V_9 ) ;
if ( ! V_14 ) {
V_15 = - V_246 ;
goto V_354;
}
}
V_15 = 0 ;
F_28 ( V_14 ) ;
switch ( V_96 ) {
case V_179 :
F_21 ( V_14 , V_34 ) ;
V_14 -> V_9 = 0 ;
V_14 -> V_6 = V_6 ;
F_205 ( V_153 , & V_14 -> V_80 ) ;
if ( F_197 ( V_181 , & V_14 -> V_80 ) )
break;
F_60 ( V_3 , F_64 ( V_3 ) , V_182 ,
F_94 ( V_14 , V_155 ) , V_155 ) ;
V_14 -> V_183 ++ ;
break;
case V_177 :
F_86 ( V_153 , & V_14 -> V_80 ) ;
break;
default:
F_43 ( V_14 , V_35 ) ;
break;
}
F_30 ( V_14 ) ;
V_354:
F_6 ( & V_3 -> V_8 ) ;
return V_15 ;
}
static inline void F_206 ( struct V_1 * V_14 )
{
if ( V_14 -> V_83 != V_84 && V_14 -> V_83 != V_172 )
V_14 -> V_141 = V_313 ;
else if ( ! F_48 ( V_314 , & V_14 -> V_80 ) )
V_14 -> V_141 = V_142 ;
}
static inline int F_207 ( struct V_2 * V_3 , struct V_268 * V_269 , T_1 V_355 , T_2 * V_26 )
{
struct V_297 * V_155 = (struct V_297 * ) V_26 ;
T_1 V_6 , V_121 ;
T_2 V_95 [ 64 ] ;
struct V_1 * V_14 ;
int V_118 ;
V_6 = F_123 ( V_155 -> V_6 ) ;
V_121 = F_123 ( V_155 -> V_121 ) ;
F_19 ( L_29 , V_6 , V_121 ) ;
V_14 = F_4 ( V_3 , V_6 ) ;
if ( ! V_14 )
return - V_356 ;
F_28 ( V_14 ) ;
if ( V_14 -> V_23 != V_34 && V_14 -> V_23 != V_93 ) {
struct V_357 V_347 ;
V_347 . V_32 = F_14 ( V_358 ) ;
V_347 . V_7 = F_14 ( V_14 -> V_7 ) ;
V_347 . V_6 = F_14 ( V_14 -> V_6 ) ;
F_60 ( V_3 , V_269 -> V_9 , V_359 ,
sizeof( V_347 ) , & V_347 ) ;
goto V_354;
}
V_118 = V_355 - sizeof( * V_155 ) ;
if ( V_118 < 0 || V_14 -> V_319 + V_118 > sizeof( V_14 -> V_318 ) ) {
F_60 ( V_3 , V_269 -> V_9 , V_360 ,
F_195 ( V_14 , V_95 ,
V_361 , V_121 ) , V_95 ) ;
goto V_354;
}
memcpy ( V_14 -> V_318 + V_14 -> V_319 , V_155 -> V_26 , V_118 ) ;
V_14 -> V_319 += V_118 ;
if ( V_121 & 0x0001 ) {
F_60 ( V_3 , V_269 -> V_9 , V_360 ,
F_195 ( V_14 , V_95 ,
V_322 , 0x0001 ) , V_95 ) ;
goto V_354;
}
V_118 = F_191 ( V_14 , V_95 ) ;
if ( V_118 < 0 ) {
F_59 ( V_3 , V_14 , V_89 ) ;
goto V_354;
}
F_60 ( V_3 , V_269 -> V_9 , V_360 , V_118 , V_95 ) ;
V_14 -> V_300 ++ ;
V_14 -> V_319 = 0 ;
if ( ! F_48 ( V_79 , & V_14 -> V_80 ) )
goto V_354;
if ( F_48 ( V_81 , & V_14 -> V_80 ) ) {
F_206 ( V_14 ) ;
F_21 ( V_14 , V_33 ) ;
V_14 -> V_228 = 0 ;
V_14 -> V_362 = 0 ;
F_172 ( & V_14 -> V_82 ) ;
if ( V_14 -> V_83 == V_84 )
F_186 ( V_14 ) ;
F_103 ( V_14 ) ;
goto V_354;
}
if ( ! F_197 ( V_181 , & V_14 -> V_80 ) ) {
T_2 V_176 [ 64 ] ;
F_60 ( V_3 , F_64 ( V_3 ) , V_182 ,
F_94 ( V_14 , V_176 ) , V_176 ) ;
V_14 -> V_183 ++ ;
}
if ( F_48 ( V_363 , & V_14 -> V_80 ) &&
F_48 ( V_335 , & V_14 -> V_80 ) ) {
F_205 ( V_335 , & V_14 -> V_80 ) ;
F_86 ( V_79 , & V_14 -> V_80 ) ;
F_60 ( V_3 , V_269 -> V_9 , V_360 ,
F_195 ( V_14 , V_95 ,
V_322 , 0x0000 ) , V_95 ) ;
}
V_354:
F_30 ( V_14 ) ;
return 0 ;
}
static inline int F_208 ( struct V_2 * V_3 , struct V_268 * V_269 , T_2 * V_26 )
{
struct V_317 * V_95 = (struct V_317 * ) V_26 ;
T_1 V_7 , V_121 , V_96 ;
struct V_1 * V_14 ;
int V_118 = V_269 -> V_118 - sizeof( * V_95 ) ;
V_7 = F_123 ( V_95 -> V_7 ) ;
V_121 = F_123 ( V_95 -> V_121 ) ;
V_96 = F_123 ( V_95 -> V_96 ) ;
F_19 ( L_30 ,
V_7 , V_121 , V_96 ) ;
V_14 = F_4 ( V_3 , V_7 ) ;
if ( ! V_14 )
return 0 ;
F_28 ( V_14 ) ;
switch ( V_96 ) {
case V_322 :
F_198 ( V_14 , V_95 -> V_26 , V_118 ) ;
F_205 ( V_363 , & V_14 -> V_80 ) ;
break;
case V_334 :
F_86 ( V_363 , & V_14 -> V_80 ) ;
if ( F_48 ( V_335 , & V_14 -> V_80 ) ) {
char V_176 [ 64 ] ;
V_118 = F_194 ( V_14 , V_95 -> V_26 , V_118 ,
V_176 , & V_96 ) ;
if ( V_118 < 0 ) {
F_59 ( V_3 , V_14 , V_89 ) ;
goto V_18;
}
F_205 ( V_335 , & V_14 -> V_80 ) ;
F_86 ( V_79 , & V_14 -> V_80 ) ;
F_60 ( V_3 , V_269 -> V_9 , V_360 ,
F_195 ( V_14 , V_176 ,
V_322 , 0x0000 ) , V_176 ) ;
}
goto V_18;
case V_330 :
if ( V_14 -> V_300 <= V_364 ) {
char V_155 [ 64 ] ;
if ( V_118 > sizeof( V_155 ) - sizeof( struct V_297 ) ) {
F_59 ( V_3 , V_14 , V_89 ) ;
goto V_18;
}
V_96 = V_322 ;
V_118 = F_194 ( V_14 , V_95 -> V_26 , V_118 ,
V_155 , & V_96 ) ;
if ( V_118 < 0 ) {
F_59 ( V_3 , V_14 , V_89 ) ;
goto V_18;
}
F_60 ( V_3 , F_64 ( V_3 ) ,
V_182 , V_118 , V_155 ) ;
V_14 -> V_183 ++ ;
if ( V_96 != V_322 )
goto V_18;
break;
}
default:
F_25 ( V_14 , V_89 ) ;
F_58 ( V_14 , V_365 ) ;
F_59 ( V_3 , V_14 , V_89 ) ;
goto V_18;
}
if ( V_121 & 0x01 )
goto V_18;
F_86 ( V_81 , & V_14 -> V_80 ) ;
if ( F_48 ( V_79 , & V_14 -> V_80 ) ) {
F_206 ( V_14 ) ;
F_21 ( V_14 , V_33 ) ;
V_14 -> V_228 = 0 ;
V_14 -> V_362 = 0 ;
F_172 ( & V_14 -> V_82 ) ;
if ( V_14 -> V_83 == V_84 )
F_186 ( V_14 ) ;
F_103 ( V_14 ) ;
}
V_18:
F_30 ( V_14 ) ;
return 0 ;
}
static inline int F_209 ( struct V_2 * V_3 , struct V_268 * V_269 , T_2 * V_26 )
{
struct V_173 * V_155 = (struct V_173 * ) V_26 ;
struct V_366 V_95 ;
T_1 V_6 , V_7 ;
struct V_1 * V_14 ;
struct V_27 * V_13 ;
V_7 = F_123 ( V_155 -> V_7 ) ;
V_6 = F_123 ( V_155 -> V_6 ) ;
F_19 ( L_31 , V_7 , V_6 ) ;
F_5 ( & V_3 -> V_8 ) ;
V_14 = F_3 ( V_3 , V_6 ) ;
if ( ! V_14 ) {
F_6 ( & V_3 -> V_8 ) ;
return 0 ;
}
F_28 ( V_14 ) ;
V_13 = V_14 -> V_13 ;
V_95 . V_6 = F_14 ( V_14 -> V_7 ) ;
V_95 . V_7 = F_14 ( V_14 -> V_6 ) ;
F_60 ( V_3 , V_269 -> V_9 , V_367 , sizeof( V_95 ) , & V_95 ) ;
F_22 ( V_13 ) ;
V_13 -> V_368 = V_369 ;
F_23 ( V_13 ) ;
F_43 ( V_14 , V_89 ) ;
F_30 ( V_14 ) ;
V_14 -> V_24 -> V_40 ( V_14 -> V_26 ) ;
F_6 ( & V_3 -> V_8 ) ;
return 0 ;
}
static inline int F_210 ( struct V_2 * V_3 , struct V_268 * V_269 , T_2 * V_26 )
{
struct V_366 * V_95 = (struct V_366 * ) V_26 ;
T_1 V_6 , V_7 ;
struct V_1 * V_14 ;
V_7 = F_123 ( V_95 -> V_7 ) ;
V_6 = F_123 ( V_95 -> V_6 ) ;
F_19 ( L_32 , V_6 , V_7 ) ;
F_5 ( & V_3 -> V_8 ) ;
V_14 = F_3 ( V_3 , V_7 ) ;
if ( ! V_14 ) {
F_6 ( & V_3 -> V_8 ) ;
return 0 ;
}
F_28 ( V_14 ) ;
F_43 ( V_14 , 0 ) ;
F_30 ( V_14 ) ;
V_14 -> V_24 -> V_40 ( V_14 -> V_26 ) ;
F_6 ( & V_3 -> V_8 ) ;
return 0 ;
}
static inline int F_211 ( struct V_2 * V_3 , struct V_268 * V_269 , T_2 * V_26 )
{
struct V_160 * V_155 = (struct V_160 * ) V_26 ;
T_1 type ;
type = F_123 ( V_155 -> type ) ;
F_19 ( L_33 , type ) ;
if ( type == V_161 ) {
T_2 V_176 [ 8 ] ;
T_7 V_166 = V_168 ;
struct V_370 * V_95 = (struct V_370 * ) V_176 ;
V_95 -> type = F_14 ( V_161 ) ;
V_95 -> V_96 = F_14 ( V_371 ) ;
if ( ! V_169 )
V_166 |= V_170 | V_171
| V_312 ;
if ( V_290 )
V_166 |= V_292
| V_291 ;
F_182 ( V_166 , V_95 -> V_26 ) ;
F_60 ( V_3 , V_269 -> V_9 ,
V_372 , sizeof( V_176 ) , V_176 ) ;
} else if ( type == V_373 ) {
T_2 V_176 [ 12 ] ;
struct V_370 * V_95 = (struct V_370 * ) V_176 ;
if ( V_290 )
V_374 [ 0 ] |= V_375 ;
else
V_374 [ 0 ] &= ~ V_375 ;
V_95 -> type = F_14 ( V_373 ) ;
V_95 -> V_96 = F_14 ( V_371 ) ;
memcpy ( V_95 -> V_26 , V_374 , sizeof( V_374 ) ) ;
F_60 ( V_3 , V_269 -> V_9 ,
V_372 , sizeof( V_176 ) , V_176 ) ;
} else {
struct V_370 V_95 ;
V_95 . type = F_14 ( type ) ;
V_95 . V_96 = F_14 ( V_376 ) ;
F_60 ( V_3 , V_269 -> V_9 ,
V_372 , sizeof( V_95 ) , & V_95 ) ;
}
return 0 ;
}
static inline int F_212 ( struct V_2 * V_3 , struct V_268 * V_269 , T_2 * V_26 )
{
struct V_370 * V_95 = (struct V_370 * ) V_26 ;
T_1 type , V_96 ;
type = F_123 ( V_95 -> type ) ;
V_96 = F_123 ( V_95 -> V_96 ) ;
F_19 ( L_34 , type , V_96 ) ;
if ( V_269 -> V_9 != V_3 -> V_162 ||
V_3 -> V_157 & V_159 )
return 0 ;
F_201 ( & V_3 -> V_163 ) ;
if ( V_96 != V_371 ) {
V_3 -> V_157 |= V_159 ;
V_3 -> V_162 = 0 ;
F_93 ( V_3 ) ;
return 0 ;
}
switch ( type ) {
case V_161 :
V_3 -> V_166 = F_180 ( V_95 -> V_26 ) ;
if ( V_3 -> V_166 & V_377 ) {
struct V_160 V_155 ;
V_155 . type = F_14 ( V_373 ) ;
V_3 -> V_162 = F_64 ( V_3 ) ;
F_60 ( V_3 , V_3 -> V_162 ,
V_165 , sizeof( V_155 ) , & V_155 ) ;
} else {
V_3 -> V_157 |= V_159 ;
V_3 -> V_162 = 0 ;
F_93 ( V_3 ) ;
}
break;
case V_373 :
V_3 -> V_378 = V_95 -> V_26 [ 0 ] ;
V_3 -> V_157 |= V_159 ;
V_3 -> V_162 = 0 ;
F_93 ( V_3 ) ;
break;
}
return 0 ;
}
static inline int F_213 ( struct V_2 * V_3 ,
struct V_268 * V_269 , T_1 V_355 ,
void * V_26 )
{
struct V_379 * V_155 = V_26 ;
struct V_380 V_95 ;
T_1 V_10 , V_7 ;
if ( V_355 != sizeof( * V_155 ) )
return - V_381 ;
if ( ! V_290 )
return - V_20 ;
V_10 = F_192 ( V_155 -> V_10 ) ;
V_7 = F_192 ( V_155 -> V_7 ) ;
F_19 ( L_35 , V_10 , V_7 , V_155 -> V_382 ) ;
V_95 . V_6 = 0 ;
V_95 . V_7 = F_14 ( V_7 ) ;
V_95 . V_96 = V_352 ;
V_95 . V_101 = V_102 ;
F_60 ( V_3 , V_269 -> V_9 , V_383 ,
sizeof( V_95 ) , & V_95 ) ;
return 0 ;
}
static inline int F_214 ( struct V_2 * V_3 ,
struct V_268 * V_269 , void * V_26 )
{
F_19 ( L_11 , V_3 ) ;
return F_204 ( V_3 , V_269 , V_26 ) ;
}
static void F_215 ( struct V_2 * V_3 , T_2 V_9 ,
T_1 V_384 , T_1 V_96 )
{
struct V_385 V_95 ;
F_19 ( L_36 , V_384 , V_96 ) ;
V_95 . V_384 = F_14 ( V_384 ) ;
V_95 . V_96 = F_14 ( V_96 ) ;
F_60 ( V_3 , V_9 , V_386 , sizeof( V_95 ) , & V_95 ) ;
}
static void F_216 ( struct V_2 * V_3 ,
struct V_1 * V_14 , T_1 V_384 , T_1 V_96 )
{
struct V_387 V_388 ;
T_2 V_9 ;
F_19 ( L_36 , V_384 , V_96 ) ;
V_9 = F_64 ( V_3 ) ;
if ( V_14 )
V_14 -> V_9 = V_9 ;
V_388 . V_384 = F_14 ( V_384 ) ;
V_388 . V_96 = F_14 ( V_96 ) ;
F_60 ( V_3 , V_9 , V_389 , sizeof( V_388 ) , & V_388 ) ;
}
static void F_217 ( struct V_2 * V_3 , T_2 V_9 ,
T_1 V_384 )
{
struct V_390 V_95 ;
F_19 ( L_37 , V_384 ) ;
V_95 . V_384 = F_14 ( V_384 ) ;
F_60 ( V_3 , V_9 , V_391 , sizeof( V_95 ) , & V_95 ) ;
}
static inline int F_218 ( struct V_2 * V_3 ,
struct V_268 * V_269 , T_1 V_355 , void * V_26 )
{
struct V_392 * V_155 = V_26 ;
T_1 V_384 = 0 ;
T_1 V_96 = V_393 ;
if ( V_355 != sizeof( * V_155 ) )
return - V_381 ;
V_384 = F_192 ( V_155 -> V_384 ) ;
F_19 ( L_38 , V_384 , V_155 -> V_394 ) ;
if ( ! V_290 )
return - V_20 ;
F_215 ( V_3 , V_269 -> V_9 , V_384 , V_96 ) ;
return 0 ;
}
static inline int F_219 ( struct V_2 * V_3 ,
struct V_268 * V_269 , T_1 V_355 , void * V_26 )
{
struct V_385 * V_95 = V_26 ;
T_1 V_384 , V_96 ;
if ( V_355 != sizeof( * V_95 ) )
return - V_381 ;
V_384 = F_192 ( V_95 -> V_384 ) ;
V_96 = F_192 ( V_95 -> V_96 ) ;
F_19 ( L_36 , V_384 , V_96 ) ;
F_216 ( V_3 , NULL , V_384 , V_395 ) ;
return 0 ;
}
static inline int F_220 ( struct V_2 * V_3 ,
struct V_268 * V_269 , T_1 V_355 , void * V_26 )
{
struct V_387 * V_388 = V_26 ;
T_1 V_384 , V_96 ;
if ( V_355 != sizeof( * V_388 ) )
return - V_381 ;
V_384 = F_192 ( V_388 -> V_384 ) ;
V_96 = F_192 ( V_388 -> V_96 ) ;
F_19 ( L_36 , V_384 , V_96 ) ;
F_217 ( V_3 , V_269 -> V_9 , V_384 ) ;
return 0 ;
}
static inline int F_221 ( struct V_2 * V_3 ,
struct V_268 * V_269 , T_1 V_355 , void * V_26 )
{
struct V_390 * V_95 = V_26 ;
T_1 V_384 ;
if ( V_355 != sizeof( * V_95 ) )
return - V_381 ;
V_384 = F_192 ( V_95 -> V_384 ) ;
F_19 ( L_37 , V_384 ) ;
return 0 ;
}
static inline int F_222 ( T_1 V_396 , T_1 V_397 , T_1 V_398 ,
T_1 V_399 )
{
T_1 V_400 ;
if ( V_396 > V_397 || V_396 < 6 || V_397 > 3200 )
return - V_20 ;
if ( V_399 < 10 || V_399 > 3200 )
return - V_20 ;
if ( V_397 >= V_399 * 8 )
return - V_20 ;
V_400 = ( V_399 * 8 / V_397 ) - 1 ;
if ( V_398 > 499 || V_398 > V_400 )
return - V_20 ;
return 0 ;
}
static inline int F_223 ( struct V_2 * V_3 ,
struct V_268 * V_269 , T_2 * V_26 )
{
struct V_130 * V_51 = V_3 -> V_51 ;
struct F_223 * V_155 ;
struct V_401 V_95 ;
T_1 V_396 , V_397 , V_398 , V_399 , V_355 ;
int V_15 ;
if ( ! ( V_51 -> V_402 & V_403 ) )
return - V_20 ;
V_355 = F_123 ( V_269 -> V_118 ) ;
if ( V_355 != sizeof( struct F_223 ) )
return - V_381 ;
V_155 = (struct F_223 * ) V_26 ;
V_396 = F_123 ( V_155 -> V_396 ) ;
V_397 = F_123 ( V_155 -> V_397 ) ;
V_398 = F_123 ( V_155 -> V_398 ) ;
V_399 = F_123 ( V_155 -> V_399 ) ;
F_19 ( L_39 ,
V_396 , V_397 , V_398 , V_399 ) ;
memset ( & V_95 , 0 , sizeof( V_95 ) ) ;
V_15 = F_222 ( V_396 , V_397 , V_398 , V_399 ) ;
if ( V_15 )
V_95 . V_96 = F_14 ( V_404 ) ;
else
V_95 . V_96 = F_14 ( V_405 ) ;
F_60 ( V_3 , V_269 -> V_9 , V_406 ,
sizeof( V_95 ) , & V_95 ) ;
if ( ! V_15 )
F_224 ( V_51 , V_396 , V_397 , V_398 , V_399 ) ;
return 0 ;
}
static inline int F_225 ( struct V_2 * V_3 ,
struct V_268 * V_269 , T_1 V_355 , T_2 * V_26 )
{
int V_15 = 0 ;
switch ( V_269 -> V_117 ) {
case V_359 :
F_200 ( V_3 , V_269 , V_26 ) ;
break;
case V_156 :
V_15 = F_202 ( V_3 , V_269 , V_26 ) ;
break;
case V_103 :
V_15 = F_204 ( V_3 , V_269 , V_26 ) ;
break;
case V_182 :
V_15 = F_207 ( V_3 , V_269 , V_355 , V_26 ) ;
break;
case V_360 :
V_15 = F_208 ( V_3 , V_269 , V_26 ) ;
break;
case V_174 :
V_15 = F_209 ( V_3 , V_269 , V_26 ) ;
break;
case V_367 :
V_15 = F_210 ( V_3 , V_269 , V_26 ) ;
break;
case V_407 :
F_60 ( V_3 , V_269 -> V_9 , V_408 , V_355 , V_26 ) ;
break;
case V_408 :
break;
case V_165 :
V_15 = F_211 ( V_3 , V_269 , V_26 ) ;
break;
case V_372 :
V_15 = F_212 ( V_3 , V_269 , V_26 ) ;
break;
case V_409 :
V_15 = F_213 ( V_3 , V_269 , V_355 , V_26 ) ;
break;
case V_383 :
V_15 = F_214 ( V_3 , V_269 , V_26 ) ;
break;
case V_410 :
V_15 = F_218 ( V_3 , V_269 , V_355 , V_26 ) ;
break;
case V_386 :
V_15 = F_219 ( V_3 , V_269 , V_355 , V_26 ) ;
break;
case V_389 :
V_15 = F_220 ( V_3 , V_269 , V_355 , V_26 ) ;
break;
case V_391 :
V_15 = F_221 ( V_3 , V_269 , V_355 , V_26 ) ;
break;
default:
F_199 ( L_40 , V_269 -> V_117 ) ;
V_15 = - V_20 ;
break;
}
return V_15 ;
}
static inline int F_226 ( struct V_2 * V_3 ,
struct V_268 * V_269 , T_2 * V_26 )
{
switch ( V_269 -> V_117 ) {
case V_359 :
return 0 ;
case V_411 :
return F_223 ( V_3 , V_269 , V_26 ) ;
case V_406 :
return 0 ;
default:
F_199 ( L_41 , V_269 -> V_117 ) ;
return - V_20 ;
}
}
static inline void F_227 ( struct V_2 * V_3 ,
struct V_119 * V_120 )
{
T_2 * V_26 = V_120 -> V_26 ;
int V_118 = V_120 -> V_118 ;
struct V_268 V_269 ;
int V_15 ;
F_177 ( V_3 , V_120 ) ;
while ( V_118 >= V_270 ) {
T_1 V_355 ;
memcpy ( & V_269 , V_26 , V_270 ) ;
V_26 += V_270 ;
V_118 -= V_270 ;
V_355 = F_192 ( V_269 . V_118 ) ;
F_19 ( L_42 , V_269 . V_117 , V_355 , V_269 . V_9 ) ;
if ( V_355 > V_118 || ! V_269 . V_9 ) {
F_19 ( L_43 ) ;
break;
}
if ( V_3 -> V_51 -> type == V_52 )
V_15 = F_226 ( V_3 , & V_269 , V_26 ) ;
else
V_15 = F_225 ( V_3 , & V_269 , V_355 , V_26 ) ;
if ( V_15 ) {
struct V_346 V_347 ;
F_199 ( L_44 , V_15 ) ;
V_347 . V_32 = F_14 ( V_348 ) ;
F_60 ( V_3 , V_269 . V_9 , V_359 , sizeof( V_347 ) , & V_347 ) ;
}
V_26 += V_355 ;
V_118 -= V_355 ;
}
F_109 ( V_120 ) ;
}
static int F_228 ( struct V_1 * V_14 , struct V_119 * V_120 )
{
T_1 V_412 , V_413 ;
int V_414 ;
if ( F_48 ( V_138 , & V_14 -> V_121 ) )
V_414 = V_139 ;
else
V_414 = V_140 ;
if ( V_14 -> V_141 == V_142 ) {
F_229 ( V_120 , V_120 -> V_118 - V_143 ) ;
V_413 = F_179 ( V_120 -> V_26 + V_120 -> V_118 ) ;
V_412 = F_82 ( 0 , V_120 -> V_26 - V_414 , V_120 -> V_118 + V_414 ) ;
if ( V_412 != V_413 )
return - V_415 ;
}
return 0 ;
}
static inline void F_230 ( struct V_1 * V_14 )
{
T_7 V_133 = 0 ;
V_14 -> V_234 = 0 ;
V_133 |= F_87 ( V_14 , V_14 -> V_152 ) ;
if ( F_48 ( V_148 , & V_14 -> V_145 ) ) {
V_133 |= F_85 ( V_14 , V_149 ) ;
F_72 ( V_14 , V_133 ) ;
F_86 ( V_150 , & V_14 -> V_145 ) ;
}
if ( F_48 ( V_264 , & V_14 -> V_145 ) )
F_157 ( V_14 ) ;
F_154 ( V_14 ) ;
if ( ! F_48 ( V_148 , & V_14 -> V_145 ) &&
V_14 -> V_234 == 0 ) {
V_133 |= F_85 ( V_14 , V_151 ) ;
F_72 ( V_14 , V_133 ) ;
}
}
static int F_231 ( struct V_1 * V_14 , struct V_119 * V_120 , T_1 V_226 , T_2 V_416 )
{
struct V_119 * V_417 ;
int V_418 , V_419 ;
F_69 ( V_120 ) -> V_226 = V_226 ;
F_69 ( V_120 ) -> V_416 = V_416 ;
V_417 = F_143 ( & V_14 -> V_88 ) ;
V_418 = F_232 ( V_14 , V_226 , V_14 -> V_152 ) ;
while ( V_417 ) {
if ( F_69 ( V_417 ) -> V_226 == V_226 )
return - V_20 ;
V_419 = F_232 ( V_14 ,
F_69 ( V_417 ) -> V_226 , V_14 -> V_152 ) ;
if ( V_419 > V_418 ) {
F_233 ( & V_14 -> V_88 , V_417 , V_120 ) ;
return 0 ;
}
if ( F_150 ( & V_14 -> V_88 , V_417 ) )
V_417 = NULL ;
else
V_417 = F_151 ( & V_14 -> V_88 , V_417 ) ;
}
F_174 ( & V_14 -> V_88 , V_120 ) ;
return 0 ;
}
static void F_234 ( struct V_119 * V_120 ,
struct V_119 * V_420 , struct V_119 * * V_421 )
{
if ( ! F_235 ( V_120 ) )
F_165 ( V_120 ) -> V_247 = V_420 ;
V_420 -> V_236 = NULL ;
( * V_421 ) -> V_236 = V_420 ;
* V_421 = V_420 ;
V_120 -> V_118 += V_420 -> V_118 ;
V_120 -> V_422 += V_420 -> V_118 ;
V_120 -> V_423 += V_420 -> V_423 ;
}
static int F_236 ( struct V_1 * V_14 , struct V_119 * V_120 , T_7 V_133 )
{
int V_15 = - V_20 ;
switch ( F_237 ( V_14 , V_133 ) ) {
case V_263 :
if ( V_14 -> V_424 )
break;
V_15 = V_14 -> V_24 -> V_266 ( V_14 -> V_26 , V_120 ) ;
break;
case V_257 :
if ( V_14 -> V_424 )
break;
V_14 -> V_425 = F_179 ( V_120 -> V_26 ) ;
F_238 ( V_120 , V_253 ) ;
if ( V_14 -> V_425 > V_14 -> V_302 ) {
V_15 = - V_262 ;
break;
}
if ( V_120 -> V_118 >= V_14 -> V_425 )
break;
V_14 -> V_424 = V_120 ;
V_14 -> V_426 = V_120 ;
V_120 = NULL ;
V_15 = 0 ;
break;
case V_260 :
if ( ! V_14 -> V_424 )
break;
F_234 ( V_14 -> V_424 , V_120 ,
& V_14 -> V_426 ) ;
V_120 = NULL ;
if ( V_14 -> V_424 -> V_118 >= V_14 -> V_425 )
break;
V_15 = 0 ;
break;
case V_261 :
if ( ! V_14 -> V_424 )
break;
F_234 ( V_14 -> V_424 , V_120 ,
& V_14 -> V_426 ) ;
V_120 = NULL ;
if ( V_14 -> V_424 -> V_118 != V_14 -> V_425 )
break;
V_15 = V_14 -> V_24 -> V_266 ( V_14 -> V_26 , V_14 -> V_424 ) ;
if ( ! V_15 ) {
V_14 -> V_424 = NULL ;
V_14 -> V_426 = NULL ;
V_14 -> V_425 = 0 ;
}
break;
}
if ( V_15 ) {
F_109 ( V_120 ) ;
F_109 ( V_14 -> V_424 ) ;
V_14 -> V_424 = NULL ;
V_14 -> V_426 = NULL ;
V_14 -> V_425 = 0 ;
}
return V_15 ;
}
static void F_239 ( struct V_1 * V_14 )
{
F_19 ( L_45 , V_14 ) ;
F_86 ( V_148 , & V_14 -> V_145 ) ;
F_240 ( V_14 ) ;
}
static void F_241 ( struct V_1 * V_14 )
{
T_7 V_133 ;
if ( ! F_48 ( V_150 , & V_14 -> V_145 ) )
goto V_18;
V_133 = F_87 ( V_14 , V_14 -> V_152 ) ;
V_133 |= F_77 ( V_14 ) ;
V_133 |= F_85 ( V_14 , V_151 ) ;
F_72 ( V_14 , V_133 ) ;
V_14 -> V_220 = 1 ;
F_50 ( V_14 ) ;
F_140 ( V_14 ) ;
F_86 ( V_225 , & V_14 -> V_145 ) ;
V_18:
F_205 ( V_148 , & V_14 -> V_145 ) ;
F_205 ( V_150 , & V_14 -> V_145 ) ;
F_19 ( L_46 , V_14 ) ;
}
void F_242 ( struct V_1 * V_14 , int V_427 )
{
if ( V_14 -> V_83 == V_84 ) {
if ( V_427 )
F_239 ( V_14 ) ;
else
F_241 ( V_14 ) ;
}
}
static void F_243 ( struct V_1 * V_14 , T_1 V_226 )
{
struct V_119 * V_120 ;
T_7 V_133 ;
while ( ( V_120 = F_143 ( & V_14 -> V_88 ) ) &&
! F_48 ( V_148 , & V_14 -> V_145 ) ) {
int V_15 ;
if ( F_69 ( V_120 ) -> V_226 != V_226 )
break;
V_120 = F_144 ( & V_14 -> V_88 ) ;
V_133 = F_173 ( V_14 , F_69 ( V_120 ) -> V_416 ) ;
V_15 = F_236 ( V_14 , V_120 , V_133 ) ;
if ( V_15 < 0 ) {
F_59 ( V_14 -> V_3 , V_14 , V_89 ) ;
break;
}
V_14 -> V_428 = F_148 ( V_14 , V_14 -> V_428 ) ;
V_226 = F_148 ( V_14 , V_226 ) ;
}
}
static void F_244 ( struct V_1 * V_14 , T_1 V_226 )
{
struct V_85 * V_86 , * V_87 ;
T_7 V_133 ;
F_53 (l, tmp, &chan->srej_l, list) {
if ( V_86 -> V_226 == V_226 ) {
F_39 ( & V_86 -> V_72 ) ;
F_54 ( V_86 ) ;
return;
}
V_133 = F_85 ( V_14 , V_238 ) ;
V_133 |= F_87 ( V_14 , V_86 -> V_226 ) ;
F_72 ( V_14 , V_133 ) ;
F_39 ( & V_86 -> V_72 ) ;
F_245 ( & V_86 -> V_72 , & V_14 -> V_239 ) ;
}
}
static int F_246 ( struct V_1 * V_14 , T_1 V_226 )
{
struct V_85 * V_429 ;
T_7 V_133 ;
while ( V_226 != V_14 -> V_362 ) {
V_133 = F_85 ( V_14 , V_238 ) ;
V_133 |= F_87 ( V_14 , V_14 -> V_362 ) ;
F_72 ( V_14 , V_133 ) ;
V_429 = F_33 ( sizeof( struct V_85 ) , V_41 ) ;
if ( ! V_429 )
return - V_211 ;
V_429 -> V_226 = V_14 -> V_362 ;
V_14 -> V_362 = F_148 ( V_14 , V_14 -> V_362 ) ;
F_245 ( & V_429 -> V_72 , & V_14 -> V_239 ) ;
}
V_14 -> V_362 = F_148 ( V_14 , V_14 -> V_362 ) ;
return 0 ;
}
static inline int F_247 ( struct V_1 * V_14 , T_7 V_430 , struct V_119 * V_120 )
{
T_1 V_226 = F_248 ( V_14 , V_430 ) ;
T_1 V_431 = F_249 ( V_14 , V_430 ) ;
T_2 V_416 = F_237 ( V_14 , V_430 ) ;
int V_418 , V_432 ;
int V_433 = ( V_14 -> V_293 / 6 ) + 1 ;
int V_15 = 0 ;
F_19 ( L_47 , V_14 , V_120 -> V_118 ,
V_226 , V_430 ) ;
if ( F_250 ( V_14 , V_430 ) &&
F_48 ( V_225 , & V_14 -> V_145 ) ) {
F_51 ( V_14 ) ;
if ( V_14 -> V_217 > 0 )
F_156 ( V_14 ) ;
F_205 ( V_225 , & V_14 -> V_145 ) ;
}
V_14 -> V_227 = V_431 ;
F_142 ( V_14 ) ;
V_418 = F_232 ( V_14 , V_226 , V_14 -> V_152 ) ;
if ( V_418 >= V_14 -> V_293 ) {
F_59 ( V_14 -> V_3 , V_14 , V_89 ) ;
goto V_434;
}
if ( F_48 ( V_148 , & V_14 -> V_145 ) ) {
if ( ! F_48 ( V_150 , & V_14 -> V_145 ) )
F_160 ( V_14 ) ;
goto V_434;
}
if ( V_226 == V_14 -> V_362 )
goto V_435;
if ( F_48 ( V_436 , & V_14 -> V_145 ) ) {
struct V_85 * V_437 ;
V_437 = F_251 ( & V_14 -> V_239 ,
struct V_85 , V_72 ) ;
if ( V_226 == V_437 -> V_226 ) {
F_231 ( V_14 , V_120 , V_226 , V_416 ) ;
F_243 ( V_14 , V_226 ) ;
F_39 ( & V_437 -> V_72 ) ;
F_54 ( V_437 ) ;
if ( F_252 ( & V_14 -> V_239 ) ) {
V_14 -> V_152 = V_14 -> V_428 ;
F_205 ( V_436 , & V_14 -> V_145 ) ;
F_160 ( V_14 ) ;
F_19 ( L_48 , V_14 ) ;
}
} else {
struct V_85 * V_86 ;
if ( F_231 ( V_14 , V_120 , V_226 , V_416 ) < 0 )
goto V_434;
F_2 (l, &chan->srej_l, list) {
if ( V_86 -> V_226 == V_226 ) {
F_244 ( V_14 , V_226 ) ;
return 0 ;
}
}
V_15 = F_246 ( V_14 , V_226 ) ;
if ( V_15 < 0 ) {
F_59 ( V_14 -> V_3 , V_14 , - V_15 ) ;
return V_15 ;
}
}
} else {
V_432 = F_232 ( V_14 ,
V_14 -> V_362 , V_14 -> V_152 ) ;
if ( V_418 < V_432 )
goto V_434;
F_86 ( V_436 , & V_14 -> V_145 ) ;
F_19 ( L_49 , V_14 ) ;
F_117 ( & V_14 -> V_239 ) ;
V_14 -> V_428 = V_14 -> V_152 ;
F_253 ( & V_14 -> V_88 ) ;
F_231 ( V_14 , V_120 , V_226 , V_416 ) ;
if ( F_52 ( V_14 ) )
F_86 ( V_146 , & V_14 -> V_145 ) ;
V_15 = F_246 ( V_14 , V_226 ) ;
if ( V_15 < 0 ) {
F_59 ( V_14 -> V_3 , V_14 , - V_15 ) ;
return V_15 ;
}
}
return 0 ;
V_435:
V_14 -> V_362 = F_148 ( V_14 , V_14 -> V_362 ) ;
if ( F_48 ( V_436 , & V_14 -> V_145 ) ) {
F_69 ( V_120 ) -> V_226 = V_226 ;
F_69 ( V_120 ) -> V_416 = V_416 ;
F_174 ( & V_14 -> V_88 , V_120 ) ;
return 0 ;
}
V_15 = F_236 ( V_14 , V_120 , V_430 ) ;
V_14 -> V_152 = F_148 ( V_14 , V_14 -> V_152 ) ;
if ( V_15 < 0 ) {
F_59 ( V_14 -> V_3 , V_14 , V_89 ) ;
return V_15 ;
}
if ( F_250 ( V_14 , V_430 ) ) {
if ( ! F_75 ( V_438 , & V_14 -> V_145 ) )
F_157 ( V_14 ) ;
}
V_14 -> V_288 = ( V_14 -> V_288 + 1 ) % V_433 ;
if ( V_14 -> V_288 == V_433 - 1 )
F_160 ( V_14 ) ;
else
F_240 ( V_14 ) ;
return 0 ;
V_434:
F_109 ( V_120 ) ;
return 0 ;
}
static inline void F_254 ( struct V_1 * V_14 , T_7 V_430 )
{
F_19 ( L_50 , V_14 ,
F_249 ( V_14 , V_430 ) , V_430 ) ;
V_14 -> V_227 = F_249 ( V_14 , V_430 ) ;
F_142 ( V_14 ) ;
if ( F_255 ( V_14 , V_430 ) ) {
F_86 ( V_144 , & V_14 -> V_145 ) ;
if ( F_48 ( V_436 , & V_14 -> V_145 ) ) {
if ( F_48 ( V_264 , & V_14 -> V_145 ) &&
( V_14 -> V_217 > 0 ) )
F_156 ( V_14 ) ;
F_205 ( V_264 , & V_14 -> V_145 ) ;
F_161 ( V_14 ) ;
} else {
F_230 ( V_14 ) ;
}
} else if ( F_250 ( V_14 , V_430 ) ) {
F_205 ( V_264 , & V_14 -> V_145 ) ;
if ( ! F_75 ( V_438 , & V_14 -> V_145 ) )
F_157 ( V_14 ) ;
} else {
if ( F_48 ( V_264 , & V_14 -> V_145 ) &&
( V_14 -> V_217 > 0 ) )
F_156 ( V_14 ) ;
F_205 ( V_264 , & V_14 -> V_145 ) ;
if ( F_48 ( V_436 , & V_14 -> V_145 ) )
F_160 ( V_14 ) ;
else
F_154 ( V_14 ) ;
}
}
static inline void F_256 ( struct V_1 * V_14 , T_7 V_430 )
{
T_1 V_226 = F_249 ( V_14 , V_430 ) ;
F_19 ( L_50 , V_14 , V_226 , V_430 ) ;
F_205 ( V_264 , & V_14 -> V_145 ) ;
V_14 -> V_227 = V_226 ;
F_142 ( V_14 ) ;
if ( F_250 ( V_14 , V_430 ) ) {
if ( ! F_75 ( V_438 , & V_14 -> V_145 ) )
F_157 ( V_14 ) ;
} else {
F_157 ( V_14 ) ;
if ( F_48 ( V_225 , & V_14 -> V_145 ) )
F_86 ( V_438 , & V_14 -> V_145 ) ;
}
}
static inline void F_257 ( struct V_1 * V_14 , T_7 V_430 )
{
T_1 V_226 = F_249 ( V_14 , V_430 ) ;
F_19 ( L_50 , V_14 , V_226 , V_430 ) ;
F_205 ( V_264 , & V_14 -> V_145 ) ;
if ( F_255 ( V_14 , V_430 ) ) {
V_14 -> V_227 = V_226 ;
F_142 ( V_14 ) ;
F_86 ( V_144 , & V_14 -> V_145 ) ;
F_149 ( V_14 , V_226 ) ;
F_154 ( V_14 ) ;
if ( F_48 ( V_225 , & V_14 -> V_145 ) ) {
V_14 -> V_439 = V_226 ;
F_86 ( V_440 , & V_14 -> V_145 ) ;
}
} else if ( F_250 ( V_14 , V_430 ) ) {
if ( F_48 ( V_440 , & V_14 -> V_145 ) &&
V_14 -> V_439 == V_226 )
F_205 ( V_440 , & V_14 -> V_145 ) ;
else
F_149 ( V_14 , V_226 ) ;
} else {
F_149 ( V_14 , V_226 ) ;
if ( F_48 ( V_225 , & V_14 -> V_145 ) ) {
V_14 -> V_439 = V_226 ;
F_86 ( V_440 , & V_14 -> V_145 ) ;
}
}
}
static inline void F_258 ( struct V_1 * V_14 , T_7 V_430 )
{
T_1 V_226 = F_249 ( V_14 , V_430 ) ;
F_19 ( L_50 , V_14 , V_226 , V_430 ) ;
F_86 ( V_264 , & V_14 -> V_145 ) ;
V_14 -> V_227 = V_226 ;
F_142 ( V_14 ) ;
if ( F_255 ( V_14 , V_430 ) )
F_86 ( V_144 , & V_14 -> V_145 ) ;
if ( ! F_48 ( V_436 , & V_14 -> V_145 ) ) {
F_50 ( V_14 ) ;
if ( F_255 ( V_14 , V_430 ) )
F_84 ( V_14 , V_441 ) ;
return;
}
if ( F_255 ( V_14 , V_430 ) ) {
F_161 ( V_14 ) ;
} else {
V_430 = F_85 ( V_14 , V_151 ) ;
F_72 ( V_14 , V_430 ) ;
}
}
static inline int F_259 ( struct V_1 * V_14 , T_7 V_430 , struct V_119 * V_120 )
{
F_19 ( L_51 , V_14 , V_430 , V_120 -> V_118 ) ;
if ( F_250 ( V_14 , V_430 ) &&
F_48 ( V_225 , & V_14 -> V_145 ) ) {
F_51 ( V_14 ) ;
if ( V_14 -> V_217 > 0 )
F_156 ( V_14 ) ;
F_205 ( V_225 , & V_14 -> V_145 ) ;
}
switch ( F_260 ( V_14 , V_430 ) ) {
case V_151 :
F_254 ( V_14 , V_430 ) ;
break;
case V_442 :
F_256 ( V_14 , V_430 ) ;
break;
case V_238 :
F_257 ( V_14 , V_430 ) ;
break;
case V_149 :
F_258 ( V_14 , V_430 ) ;
break;
}
F_109 ( V_120 ) ;
return 0 ;
}
static int F_261 ( struct V_1 * V_14 , struct V_119 * V_120 )
{
T_7 V_133 ;
T_1 V_431 ;
int V_118 , V_419 , V_443 ;
V_133 = F_146 ( V_14 , V_120 -> V_26 ) ;
F_238 ( V_120 , F_81 ( V_14 ) ) ;
V_118 = V_120 -> V_118 ;
if ( F_228 ( V_14 , V_120 ) )
goto V_434;
if ( F_262 ( V_14 , V_133 ) && ! F_263 ( V_14 , V_133 ) )
V_118 -= V_253 ;
if ( V_14 -> V_141 == V_142 )
V_118 -= V_143 ;
if ( V_118 > V_14 -> V_345 ) {
F_59 ( V_14 -> V_3 , V_14 , V_89 ) ;
goto V_434;
}
V_431 = F_249 ( V_14 , V_133 ) ;
V_443 = F_232 ( V_14 , V_431 , V_14 -> V_227 ) ;
V_419 = F_232 ( V_14 , V_14 -> V_228 ,
V_14 -> V_227 ) ;
if ( V_443 > V_419 ) {
F_59 ( V_14 -> V_3 , V_14 , V_89 ) ;
goto V_434;
}
if ( ! F_263 ( V_14 , V_133 ) ) {
if ( V_118 < 0 ) {
F_59 ( V_14 -> V_3 , V_14 , V_89 ) ;
goto V_434;
}
F_247 ( V_14 , V_133 , V_120 ) ;
} else {
if ( V_118 != 0 ) {
F_199 ( L_52 , V_118 ) ;
F_59 ( V_14 -> V_3 , V_14 , V_89 ) ;
goto V_434;
}
F_259 ( V_14 , V_133 , V_120 ) ;
}
return 0 ;
V_434:
F_109 ( V_120 ) ;
return 0 ;
}
static inline int F_264 ( struct V_2 * V_3 , T_1 V_4 , struct V_119 * V_120 )
{
struct V_1 * V_14 ;
T_7 V_133 ;
T_1 V_226 ;
int V_118 ;
V_14 = F_4 ( V_3 , V_4 ) ;
if ( ! V_14 ) {
F_19 ( L_53 , V_4 ) ;
F_109 ( V_120 ) ;
return 0 ;
}
F_28 ( V_14 ) ;
F_19 ( L_54 , V_14 , V_120 -> V_118 ) ;
if ( V_14 -> V_23 != V_33 )
goto V_434;
switch ( V_14 -> V_83 ) {
case V_205 :
if ( V_14 -> V_302 < V_120 -> V_118 )
goto V_434;
if ( ! V_14 -> V_24 -> V_266 ( V_14 -> V_26 , V_120 ) )
goto V_18;
break;
case V_84 :
F_261 ( V_14 , V_120 ) ;
goto V_18;
case V_172 :
V_133 = F_146 ( V_14 , V_120 -> V_26 ) ;
F_238 ( V_120 , F_81 ( V_14 ) ) ;
V_118 = V_120 -> V_118 ;
if ( F_228 ( V_14 , V_120 ) )
goto V_434;
if ( F_262 ( V_14 , V_133 ) )
V_118 -= V_253 ;
if ( V_14 -> V_141 == V_142 )
V_118 -= V_143 ;
if ( V_118 > V_14 -> V_345 || V_118 < 0 || F_263 ( V_14 , V_133 ) )
goto V_434;
V_226 = F_248 ( V_14 , V_133 ) ;
if ( V_14 -> V_362 != V_226 ) {
F_109 ( V_14 -> V_424 ) ;
V_14 -> V_424 = NULL ;
V_14 -> V_426 = NULL ;
V_14 -> V_425 = 0 ;
}
V_14 -> V_362 = F_148 ( V_14 , V_226 ) ;
if ( F_236 ( V_14 , V_120 , V_133 ) == - V_262 )
F_59 ( V_14 -> V_3 , V_14 , V_89 ) ;
goto V_18;
default:
F_19 ( L_55 , V_14 , V_14 -> V_83 ) ;
break;
}
V_434:
F_109 ( V_120 ) ;
V_18:
F_30 ( V_14 ) ;
return 0 ;
}
static inline int F_265 ( struct V_2 * V_3 , T_3 V_10 , struct V_119 * V_120 )
{
struct V_1 * V_14 ;
V_14 = F_118 ( 0 , V_10 , V_3 -> V_11 ) ;
if ( ! V_14 )
goto V_434;
F_19 ( L_54 , V_14 , V_120 -> V_118 ) ;
if ( V_14 -> V_23 != V_209 && V_14 -> V_23 != V_33 )
goto V_434;
if ( V_14 -> V_302 < V_120 -> V_118 )
goto V_434;
if ( ! V_14 -> V_24 -> V_266 ( V_14 -> V_26 , V_120 ) )
return 0 ;
V_434:
F_109 ( V_120 ) ;
return 0 ;
}
static inline int F_266 ( struct V_2 * V_3 , T_3 V_4 , struct V_119 * V_120 )
{
struct V_1 * V_14 ;
V_14 = F_95 ( 0 , V_4 , V_3 -> V_11 ) ;
if ( ! V_14 )
goto V_434;
F_19 ( L_54 , V_14 , V_120 -> V_118 ) ;
if ( V_14 -> V_23 != V_209 && V_14 -> V_23 != V_33 )
goto V_434;
if ( V_14 -> V_302 < V_120 -> V_118 )
goto V_434;
if ( ! V_14 -> V_24 -> V_266 ( V_14 -> V_26 , V_120 ) )
return 0 ;
V_434:
F_109 ( V_120 ) ;
return 0 ;
}
static void F_267 ( struct V_2 * V_3 , struct V_119 * V_120 )
{
struct V_134 * V_135 = ( void * ) V_120 -> V_26 ;
T_1 V_4 , V_118 ;
T_3 V_10 ;
F_238 ( V_120 , V_147 ) ;
V_4 = F_123 ( V_135 -> V_4 ) ;
V_118 = F_123 ( V_135 -> V_118 ) ;
if ( V_118 != V_120 -> V_118 ) {
F_109 ( V_120 ) ;
return;
}
F_19 ( L_56 , V_118 , V_4 ) ;
switch ( V_4 ) {
case V_271 :
case V_59 :
F_227 ( V_3 , V_120 ) ;
break;
case V_58 :
V_10 = F_179 ( V_120 -> V_26 ) ;
F_238 ( V_120 , 2 ) ;
F_265 ( V_3 , V_10 , V_120 ) ;
break;
case V_55 :
F_266 ( V_3 , V_4 , V_120 ) ;
break;
case V_444 :
if ( F_268 ( V_3 , V_120 ) )
F_108 ( V_3 -> V_51 , V_445 ) ;
break;
default:
F_264 ( V_3 , V_4 , V_120 ) ;
break;
}
}
int F_269 ( struct V_203 * V_122 , T_4 * V_202 )
{
int V_446 = 0 , V_447 = 0 , V_448 = 0 ;
struct V_1 * V_5 ;
F_19 ( L_57 , V_122 -> V_449 , F_120 ( V_202 ) ) ;
F_96 ( & V_16 ) ;
F_2 (c, &chan_list, global_l) {
struct V_27 * V_13 = V_5 -> V_13 ;
if ( V_5 -> V_23 != V_90 )
continue;
if ( ! F_10 ( & F_11 ( V_13 ) -> V_11 , & V_122 -> V_202 ) ) {
V_447 |= V_450 ;
if ( F_48 ( V_451 , & V_5 -> V_121 ) )
V_447 |= V_403 ;
V_446 ++ ;
} else if ( ! F_10 ( & F_11 ( V_13 ) -> V_11 , V_185 ) ) {
V_448 |= V_450 ;
if ( F_48 ( V_451 , & V_5 -> V_121 ) )
V_448 |= V_403 ;
}
}
F_97 ( & V_16 ) ;
return V_446 ? V_447 : V_448 ;
}
int F_270 ( struct V_130 * V_51 , T_2 V_101 )
{
struct V_2 * V_3 ;
F_19 ( L_58 , V_51 , F_120 ( & V_51 -> V_190 ) , V_101 ) ;
if ( ! V_101 ) {
V_3 = F_114 ( V_51 , V_101 ) ;
if ( V_3 )
F_104 ( V_3 ) ;
} else
F_108 ( V_51 , F_271 ( V_101 ) ) ;
return 0 ;
}
int F_272 ( struct V_130 * V_51 )
{
struct V_2 * V_3 = V_51 -> V_194 ;
F_19 ( L_59 , V_51 ) ;
if ( ! V_3 )
return V_48 ;
return V_3 -> V_47 ;
}
int F_273 ( struct V_130 * V_51 , T_2 V_32 )
{
F_19 ( L_60 , V_51 , V_32 ) ;
F_108 ( V_51 , F_271 ( V_32 ) ) ;
return 0 ;
}
static inline void F_274 ( struct V_1 * V_14 , T_2 V_452 )
{
if ( V_14 -> V_49 != V_50 )
return;
if ( V_452 == 0x00 ) {
if ( V_14 -> V_37 == V_107 ) {
F_44 ( V_14 ) ;
F_58 ( V_14 , V_453 ) ;
} else if ( V_14 -> V_37 == V_105 )
F_29 ( V_14 , V_35 ) ;
} else {
if ( V_14 -> V_37 == V_107 )
F_44 ( V_14 ) ;
}
}
int F_275 ( struct V_130 * V_51 , T_2 V_101 , T_2 V_452 )
{
struct V_2 * V_3 = V_51 -> V_194 ;
struct V_1 * V_14 ;
if ( ! V_3 )
return 0 ;
F_19 ( L_11 , V_3 ) ;
if ( V_51 -> type == V_52 ) {
F_276 ( V_3 , 0 ) ;
F_201 ( & V_3 -> V_197 ) ;
}
F_5 ( & V_3 -> V_8 ) ;
F_2 (chan, &conn->chan_l, list) {
F_28 ( V_14 ) ;
F_19 ( L_61 , V_14 -> V_7 ) ;
if ( V_14 -> V_7 == V_55 ) {
if ( ! V_101 && V_452 ) {
V_14 -> V_37 = V_51 -> V_37 ;
F_103 ( V_14 ) ;
}
F_30 ( V_14 ) ;
continue;
}
if ( F_48 ( V_153 , & V_14 -> V_80 ) ) {
F_30 ( V_14 ) ;
continue;
}
if ( ! V_101 && ( V_14 -> V_23 == V_33 ||
V_14 -> V_23 == V_34 ) ) {
struct V_27 * V_13 = V_14 -> V_13 ;
F_11 ( V_13 ) -> V_454 = false ;
V_13 -> V_78 ( V_13 ) ;
F_274 ( V_14 , V_452 ) ;
F_30 ( V_14 ) ;
continue;
}
if ( V_14 -> V_23 == V_36 ) {
if ( ! V_101 ) {
F_89 ( V_14 ) ;
} else {
F_44 ( V_14 ) ;
F_58 ( V_14 , V_455 ) ;
}
} else if ( V_14 -> V_23 == V_93 ) {
struct V_27 * V_13 = V_14 -> V_13 ;
struct V_94 V_95 ;
T_5 V_456 , V_457 ;
F_22 ( V_13 ) ;
if ( ! V_101 ) {
if ( F_11 ( V_13 ) -> V_97 ) {
struct V_27 * V_74 = F_11 ( V_13 ) -> V_74 ;
V_456 = V_177 ;
V_457 = V_178 ;
if ( V_74 )
V_74 -> V_77 ( V_74 , 0 ) ;
} else {
F_18 ( V_14 , V_34 ) ;
V_456 = V_179 ;
V_457 = V_102 ;
}
} else {
F_18 ( V_14 , V_100 ) ;
F_58 ( V_14 , V_455 ) ;
V_456 = V_98 ;
V_457 = V_102 ;
}
F_23 ( V_13 ) ;
V_95 . V_7 = F_14 ( V_14 -> V_6 ) ;
V_95 . V_6 = F_14 ( V_14 -> V_7 ) ;
V_95 . V_96 = F_14 ( V_456 ) ;
V_95 . V_101 = F_14 ( V_457 ) ;
F_60 ( V_3 , V_14 -> V_9 , V_103 ,
sizeof( V_95 ) , & V_95 ) ;
}
F_30 ( V_14 ) ;
}
F_6 ( & V_3 -> V_8 ) ;
return 0 ;
}
int F_277 ( struct V_130 * V_51 , struct V_119 * V_120 , T_1 V_121 )
{
struct V_2 * V_3 = V_51 -> V_194 ;
if ( ! V_3 )
V_3 = F_114 ( V_51 , 0 ) ;
if ( ! V_3 )
goto V_434;
F_19 ( L_62 , V_3 , V_120 -> V_118 , V_121 ) ;
if ( ! ( V_121 & V_458 ) ) {
struct V_134 * V_459 ;
struct V_1 * V_14 ;
T_1 V_4 ;
int V_118 ;
if ( V_3 -> V_460 ) {
F_199 ( L_63 , V_120 -> V_118 ) ;
F_109 ( V_3 -> V_195 ) ;
V_3 -> V_195 = NULL ;
V_3 -> V_460 = 0 ;
F_106 ( V_3 , V_461 ) ;
}
if ( V_120 -> V_118 < V_147 ) {
F_199 ( L_64 , V_120 -> V_118 ) ;
F_106 ( V_3 , V_461 ) ;
goto V_434;
}
V_459 = (struct V_134 * ) V_120 -> V_26 ;
V_118 = F_123 ( V_459 -> V_118 ) + V_147 ;
V_4 = F_123 ( V_459 -> V_4 ) ;
if ( V_118 == V_120 -> V_118 ) {
F_267 ( V_3 , V_120 ) ;
return 0 ;
}
F_19 ( L_65 , V_118 , V_120 -> V_118 ) ;
if ( V_120 -> V_118 > V_118 ) {
F_199 ( L_66 ,
V_120 -> V_118 , V_118 ) ;
F_106 ( V_3 , V_461 ) ;
goto V_434;
}
V_14 = F_4 ( V_3 , V_4 ) ;
if ( V_14 && V_14 -> V_13 ) {
struct V_27 * V_13 = V_14 -> V_13 ;
F_22 ( V_13 ) ;
if ( V_14 -> V_302 < V_118 - V_147 ) {
F_199 ( L_67
L_68 , V_118 ,
V_14 -> V_302 ) ;
F_23 ( V_13 ) ;
F_106 ( V_3 , V_461 ) ;
goto V_434;
}
F_23 ( V_13 ) ;
}
V_3 -> V_195 = F_78 ( V_118 , V_41 ) ;
if ( ! V_3 -> V_195 )
goto V_434;
F_278 ( V_120 , F_79 ( V_3 -> V_195 , V_120 -> V_118 ) ,
V_120 -> V_118 ) ;
V_3 -> V_460 = V_118 - V_120 -> V_118 ;
} else {
F_19 ( L_69 , V_120 -> V_118 , V_3 -> V_460 ) ;
if ( ! V_3 -> V_460 ) {
F_199 ( L_70 , V_120 -> V_118 ) ;
F_106 ( V_3 , V_461 ) ;
goto V_434;
}
if ( V_120 -> V_118 > V_3 -> V_460 ) {
F_199 ( L_71 ,
V_120 -> V_118 , V_3 -> V_460 ) ;
F_109 ( V_3 -> V_195 ) ;
V_3 -> V_195 = NULL ;
V_3 -> V_460 = 0 ;
F_106 ( V_3 , V_461 ) ;
goto V_434;
}
F_278 ( V_120 , F_79 ( V_3 -> V_195 , V_120 -> V_118 ) ,
V_120 -> V_118 ) ;
V_3 -> V_460 -= V_120 -> V_118 ;
if ( ! V_3 -> V_460 ) {
F_267 ( V_3 , V_3 -> V_195 ) ;
V_3 -> V_195 = NULL ;
}
}
V_434:
F_109 ( V_120 ) ;
return 0 ;
}
static int F_279 ( struct V_462 * V_463 , void * V_19 )
{
struct V_1 * V_5 ;
F_96 ( & V_16 ) ;
F_2 (c, &chan_list, global_l) {
struct V_27 * V_13 = V_5 -> V_13 ;
F_280 ( V_463 , L_72 ,
F_120 ( & F_11 ( V_13 ) -> V_11 ) ,
F_120 ( & F_11 ( V_13 ) -> V_190 ) ,
V_5 -> V_23 , F_123 ( V_5 -> V_10 ) ,
V_5 -> V_7 , V_5 -> V_6 , V_5 -> V_302 , V_5 -> V_53 ,
V_5 -> V_37 , V_5 -> V_83 ) ;
}
F_97 ( & V_16 ) ;
return 0 ;
}
static int F_281 ( struct V_464 * V_464 , struct V_465 * V_465 )
{
return F_282 ( V_465 , F_279 , V_464 -> V_466 ) ;
}
int T_10 F_283 ( void )
{
int V_15 ;
V_15 = F_284 () ;
if ( V_15 < 0 )
return V_15 ;
if ( V_467 ) {
V_468 = F_285 ( L_73 , 0444 ,
V_467 , NULL , & V_469 ) ;
if ( ! V_468 )
F_199 ( L_74 ) ;
}
return 0 ;
}
void F_286 ( void )
{
F_287 ( V_468 ) ;
F_288 () ;
}
