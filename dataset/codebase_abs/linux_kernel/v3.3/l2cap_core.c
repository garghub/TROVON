static struct V_1 * F_1 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_1 * V_5 , * V_6 = NULL ;
F_2 () ;
F_3 (c, &conn->chan_l, list) {
if ( V_5 -> V_7 == V_4 ) {
V_6 = V_5 ;
break;
}
}
F_4 () ;
return V_6 ;
}
static struct V_1 * F_5 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_1 * V_5 , * V_6 = NULL ;
F_2 () ;
F_3 (c, &conn->chan_l, list) {
if ( V_5 -> V_8 == V_4 ) {
V_6 = V_5 ;
break;
}
}
F_4 () ;
return V_6 ;
}
static struct V_1 * F_6 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_1 * V_5 ;
V_5 = F_5 ( V_3 , V_4 ) ;
if ( V_5 )
F_7 ( V_5 -> V_9 ) ;
return V_5 ;
}
static struct V_1 * F_8 ( struct V_2 * V_3 , T_2 V_10 )
{
struct V_1 * V_5 , * V_6 = NULL ;
F_2 () ;
F_3 (c, &conn->chan_l, list) {
if ( V_5 -> V_10 == V_10 ) {
V_6 = V_5 ;
break;
}
}
F_4 () ;
return V_6 ;
}
static inline struct V_1 * F_9 ( struct V_2 * V_3 , T_2 V_10 )
{
struct V_1 * V_5 ;
V_5 = F_8 ( V_3 , V_10 ) ;
if ( V_5 )
F_7 ( V_5 -> V_9 ) ;
return V_5 ;
}
static struct V_1 * F_10 ( T_3 V_11 , T_4 * V_12 )
{
struct V_1 * V_5 ;
F_11 (c, &chan_list, global_l) {
if ( V_5 -> V_13 == V_11 && ! F_12 ( & F_13 ( V_5 -> V_9 ) -> V_12 , V_12 ) )
return V_5 ;
}
return NULL ;
}
int F_14 ( struct V_1 * V_14 , T_4 * V_12 , T_3 V_11 )
{
int V_15 ;
F_15 ( & V_16 ) ;
if ( V_11 && F_10 ( V_11 , V_12 ) ) {
V_15 = - V_17 ;
goto V_18;
}
if ( V_11 ) {
V_14 -> V_11 = V_11 ;
V_14 -> V_13 = V_11 ;
V_15 = 0 ;
} else {
T_1 V_19 ;
V_15 = - V_20 ;
for ( V_19 = 0x1001 ; V_19 < 0x1100 ; V_19 += 2 )
if ( ! F_10 ( F_16 ( V_19 ) , V_12 ) ) {
V_14 -> V_11 = F_16 ( V_19 ) ;
V_14 -> V_13 = F_16 ( V_19 ) ;
V_15 = 0 ;
break;
}
}
V_18:
F_17 ( & V_16 ) ;
return V_15 ;
}
int F_18 ( struct V_1 * V_14 , T_5 V_8 )
{
F_15 ( & V_16 ) ;
V_14 -> V_8 = V_8 ;
F_17 ( & V_16 ) ;
return 0 ;
}
static T_1 F_19 ( struct V_2 * V_3 )
{
T_1 V_4 = V_21 ;
for (; V_4 < V_22 ; V_4 ++ ) {
if ( ! F_5 ( V_3 , V_4 ) )
return V_4 ;
}
return 0 ;
}
static char * F_20 ( int V_23 )
{
switch( V_23 ) {
case V_24 :
return L_1 ;
case V_25 :
return L_2 ;
case V_26 :
return L_3 ;
case V_27 :
return L_4 ;
case V_28 :
return L_5 ;
case V_29 :
return L_6 ;
case V_30 :
return L_7 ;
case V_31 :
return L_8 ;
case V_32 :
return L_9 ;
}
return L_10 ;
}
static void F_21 ( struct V_1 * V_14 , int V_23 )
{
F_22 ( L_11 , V_14 , F_20 ( V_14 -> V_23 ) ,
F_20 ( V_23 ) ) ;
V_14 -> V_23 = V_23 ;
V_14 -> V_33 -> V_34 ( V_14 -> V_35 , V_23 ) ;
}
static void F_23 ( struct V_36 * V_37 )
{
struct V_1 * V_14 = F_24 ( V_37 , struct V_1 ,
V_38 . V_37 ) ;
struct V_39 * V_9 = V_14 -> V_9 ;
int V_40 ;
F_22 ( L_12 , V_14 , V_14 -> V_23 ) ;
F_7 ( V_9 ) ;
if ( V_14 -> V_23 == V_24 || V_14 -> V_23 == V_30 )
V_40 = V_41 ;
else if ( V_14 -> V_23 == V_28 &&
V_14 -> V_42 != V_43 )
V_40 = V_41 ;
else
V_40 = V_44 ;
F_25 ( V_14 , V_40 ) ;
F_26 ( V_9 ) ;
V_14 -> V_33 -> V_45 ( V_14 -> V_35 ) ;
F_27 ( V_14 ) ;
}
struct V_1 * F_28 ( struct V_39 * V_9 )
{
struct V_1 * V_14 ;
V_14 = F_29 ( sizeof( * V_14 ) , V_46 ) ;
if ( ! V_14 )
return NULL ;
V_14 -> V_9 = V_9 ;
F_15 ( & V_16 ) ;
F_30 ( & V_14 -> V_47 , & V_48 ) ;
F_17 ( & V_16 ) ;
F_31 ( & V_14 -> V_38 , F_23 ) ;
V_14 -> V_23 = V_25 ;
F_32 ( & V_14 -> V_49 , 1 ) ;
F_22 ( L_13 , V_9 , V_14 ) ;
return V_14 ;
}
void F_33 ( struct V_1 * V_14 )
{
F_15 ( & V_16 ) ;
F_34 ( & V_14 -> V_47 ) ;
F_17 ( & V_16 ) ;
F_27 ( V_14 ) ;
}
static void F_35 ( struct V_2 * V_3 , struct V_1 * V_14 )
{
F_22 ( L_14 , V_3 ,
V_14 -> V_11 , V_14 -> V_7 ) ;
V_3 -> V_50 = V_51 ;
V_14 -> V_3 = V_3 ;
if ( V_14 -> V_52 == V_53 ) {
if ( V_3 -> V_54 -> type == V_55 ) {
V_14 -> V_56 = V_57 ;
V_14 -> V_8 = V_58 ;
V_14 -> V_7 = V_58 ;
} else {
V_14 -> V_8 = F_19 ( V_3 ) ;
V_14 -> V_56 = V_59 ;
}
} else if ( V_14 -> V_52 == V_60 ) {
V_14 -> V_8 = V_61 ;
V_14 -> V_7 = V_61 ;
V_14 -> V_56 = V_59 ;
} else {
V_14 -> V_8 = V_62 ;
V_14 -> V_7 = V_62 ;
V_14 -> V_56 = V_59 ;
}
V_14 -> V_63 = V_64 ;
V_14 -> V_65 = V_66 ;
V_14 -> V_67 = V_68 ;
V_14 -> V_69 = V_70 ;
V_14 -> V_71 = V_72 ;
V_14 -> V_73 = V_74 ;
F_36 ( V_14 ) ;
F_37 ( & V_14 -> V_75 , & V_3 -> V_76 ) ;
}
static void F_38 ( struct V_1 * V_14 , int V_15 )
{
struct V_39 * V_9 = V_14 -> V_9 ;
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_39 * V_77 = F_13 ( V_9 ) -> V_77 ;
F_39 ( V_14 ) ;
F_22 ( L_15 , V_14 , V_3 , V_15 ) ;
if ( V_3 ) {
F_40 ( & V_14 -> V_75 ) ;
F_41 () ;
F_27 ( V_14 ) ;
V_14 -> V_3 = NULL ;
F_42 ( V_3 -> V_54 ) ;
}
F_21 ( V_14 , V_32 ) ;
F_43 ( V_9 , V_78 ) ;
if ( V_15 )
V_9 -> V_79 = V_15 ;
if ( V_77 ) {
F_44 ( V_9 ) ;
V_77 -> V_80 ( V_77 , 0 ) ;
} else
V_9 -> V_81 ( V_9 ) ;
if ( ! ( F_45 ( V_82 , & V_14 -> V_83 ) &&
F_45 ( V_84 , & V_14 -> V_83 ) ) )
return;
F_46 ( & V_14 -> V_85 ) ;
if ( V_14 -> V_86 == V_87 ) {
struct V_88 * V_89 , * V_90 ;
F_47 ( V_14 ) ;
F_48 ( V_14 ) ;
F_49 ( V_14 ) ;
F_46 ( & V_14 -> V_91 ) ;
F_50 (l, tmp, &chan->srej_l, list) {
F_34 ( & V_89 -> V_75 ) ;
F_51 ( V_89 ) ;
}
}
}
static void F_52 ( struct V_39 * V_77 )
{
struct V_39 * V_9 ;
F_22 ( L_16 , V_77 ) ;
while ( ( V_9 = F_53 ( V_77 , NULL ) ) ) {
struct V_1 * V_14 = F_54 ( V_9 ) -> V_14 ;
F_39 ( V_14 ) ;
F_7 ( V_9 ) ;
F_25 ( V_14 , V_92 ) ;
F_26 ( V_9 ) ;
V_14 -> V_33 -> V_45 ( V_14 -> V_35 ) ;
}
}
void F_25 ( struct V_1 * V_14 , int V_40 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_39 * V_9 = V_14 -> V_9 ;
F_22 ( L_17 , V_14 , V_14 -> V_23 , V_9 -> V_93 ) ;
switch ( V_14 -> V_23 ) {
case V_27 :
F_52 ( V_9 ) ;
F_21 ( V_14 , V_32 ) ;
F_43 ( V_9 , V_78 ) ;
break;
case V_24 :
case V_30 :
if ( V_14 -> V_52 == V_53 &&
V_3 -> V_54 -> type == V_94 ) {
F_39 ( V_14 ) ;
F_55 ( V_14 , V_9 -> V_95 ) ;
F_56 ( V_3 , V_14 , V_40 ) ;
} else
F_38 ( V_14 , V_40 ) ;
break;
case V_29 :
if ( V_14 -> V_52 == V_53 &&
V_3 -> V_54 -> type == V_94 ) {
struct V_96 V_97 ;
T_5 V_98 ;
if ( F_13 ( V_9 ) -> V_99 )
V_98 = V_100 ;
else
V_98 = V_101 ;
F_21 ( V_14 , V_31 ) ;
V_97 . V_8 = F_16 ( V_14 -> V_7 ) ;
V_97 . V_7 = F_16 ( V_14 -> V_8 ) ;
V_97 . V_98 = F_16 ( V_98 ) ;
V_97 . V_102 = F_16 ( V_103 ) ;
F_57 ( V_3 , V_14 -> V_10 , V_104 ,
sizeof( V_97 ) , & V_97 ) ;
}
F_38 ( V_14 , V_40 ) ;
break;
case V_28 :
case V_31 :
F_38 ( V_14 , V_40 ) ;
break;
default:
F_43 ( V_9 , V_78 ) ;
break;
}
}
static inline T_2 F_58 ( struct V_1 * V_14 )
{
if ( V_14 -> V_52 == V_105 ) {
switch ( V_14 -> V_42 ) {
case V_106 :
return V_107 ;
case V_108 :
return V_109 ;
default:
return V_110 ;
}
} else if ( V_14 -> V_11 == F_16 ( 0x0001 ) ) {
if ( V_14 -> V_42 == V_111 )
V_14 -> V_42 = V_43 ;
if ( V_14 -> V_42 == V_106 )
return V_112 ;
else
return V_110 ;
} else {
switch ( V_14 -> V_42 ) {
case V_106 :
return V_113 ;
case V_108 :
return V_114 ;
default:
return V_110 ;
}
}
}
int F_59 ( struct V_1 * V_14 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
T_6 V_115 ;
V_115 = F_58 ( V_14 ) ;
return F_60 ( V_3 -> V_54 , V_14 -> V_42 , V_115 ) ;
}
static T_2 F_61 ( struct V_2 * V_3 )
{
T_2 V_116 ;
F_62 ( & V_3 -> V_117 ) ;
if ( ++ V_3 -> V_118 > 128 )
V_3 -> V_118 = 1 ;
V_116 = V_3 -> V_118 ;
F_63 ( & V_3 -> V_117 ) ;
return V_116 ;
}
static void F_57 ( struct V_2 * V_3 , T_2 V_10 , T_2 V_119 , T_1 V_120 , void * V_35 )
{
struct V_121 * V_122 = F_64 ( V_3 , V_119 , V_10 , V_120 , V_35 ) ;
T_2 V_123 ;
F_22 ( L_18 , V_119 ) ;
if ( ! V_122 )
return;
if ( F_65 ( V_3 -> V_54 -> V_124 ) )
V_123 = V_125 ;
else
V_123 = V_126 ;
F_66 ( V_122 ) -> V_127 = V_128 ;
V_122 -> V_129 = V_130 ;
F_67 ( V_3 -> V_131 , V_122 , V_123 ) ;
}
static void F_68 ( struct V_1 * V_14 , struct V_121 * V_122 )
{
struct V_132 * V_54 = V_14 -> V_3 -> V_54 ;
T_1 V_123 ;
F_22 ( L_19 , V_14 , V_122 , V_122 -> V_120 ,
V_122 -> V_129 ) ;
if ( ! F_45 ( V_133 , & V_14 -> V_123 ) &&
F_65 ( V_54 -> V_124 ) )
V_123 = V_125 ;
else
V_123 = V_126 ;
F_66 ( V_122 ) -> V_127 = F_45 ( V_134 , & V_14 -> V_123 ) ;
F_67 ( V_14 -> V_3 -> V_131 , V_122 , V_123 ) ;
}
static inline void F_69 ( struct V_1 * V_14 , T_7 V_135 )
{
struct V_121 * V_122 ;
struct V_136 * V_137 ;
struct V_2 * V_3 = V_14 -> V_3 ;
int V_138 , V_139 ;
if ( V_14 -> V_23 != V_24 )
return;
if ( F_45 ( V_140 , & V_14 -> V_123 ) )
V_139 = V_141 ;
else
V_139 = V_142 ;
if ( V_14 -> V_143 == V_144 )
V_139 += V_145 ;
F_22 ( L_20 , V_14 , V_135 ) ;
V_138 = F_70 (unsigned int, conn->mtu, hlen) ;
V_135 |= F_71 ( V_14 ) ;
if ( F_72 ( V_146 , & V_14 -> V_147 ) )
V_135 |= F_73 ( V_14 ) ;
if ( F_72 ( V_148 , & V_14 -> V_147 ) )
V_135 |= F_74 ( V_14 ) ;
V_122 = F_75 ( V_138 , V_46 ) ;
if ( ! V_122 )
return;
V_137 = (struct V_136 * ) F_76 ( V_122 , V_149 ) ;
V_137 -> V_120 = F_16 ( V_139 - V_149 ) ;
V_137 -> V_4 = F_16 ( V_14 -> V_7 ) ;
F_77 ( V_14 , V_135 , F_76 ( V_122 , F_78 ( V_14 ) ) ) ;
if ( V_14 -> V_143 == V_144 ) {
T_1 V_143 = F_79 ( 0 , ( T_2 * ) V_137 , V_138 - V_145 ) ;
F_80 ( V_143 , F_76 ( V_122 , V_145 ) ) ;
}
V_122 -> V_129 = V_130 ;
F_68 ( V_14 , V_122 ) ;
}
static inline void F_81 ( struct V_1 * V_14 , T_7 V_135 )
{
if ( F_45 ( V_150 , & V_14 -> V_147 ) ) {
V_135 |= F_82 ( V_14 , V_151 ) ;
F_83 ( V_152 , & V_14 -> V_147 ) ;
} else
V_135 |= F_82 ( V_14 , V_153 ) ;
V_135 |= F_84 ( V_14 , V_14 -> V_154 ) ;
F_69 ( V_14 , V_135 ) ;
}
static inline int F_85 ( struct V_1 * V_14 )
{
return ! F_45 ( V_155 , & V_14 -> V_83 ) ;
}
static void F_86 ( struct V_1 * V_14 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
if ( V_3 -> V_156 & V_157 ) {
if ( ! ( V_3 -> V_156 & V_158 ) )
return;
if ( F_59 ( V_14 ) &&
F_85 ( V_14 ) ) {
struct V_159 V_160 ;
V_160 . V_8 = F_16 ( V_14 -> V_8 ) ;
V_160 . V_11 = V_14 -> V_11 ;
V_14 -> V_10 = F_61 ( V_3 ) ;
F_83 ( V_155 , & V_14 -> V_83 ) ;
F_57 ( V_3 , V_14 -> V_10 , V_161 ,
sizeof( V_160 ) , & V_160 ) ;
}
} else {
struct V_162 V_160 ;
V_160 . type = F_16 ( V_163 ) ;
V_3 -> V_156 |= V_157 ;
V_3 -> V_164 = F_61 ( V_3 ) ;
F_87 ( & V_3 -> V_165 ,
F_88 ( V_166 ) ) ;
F_57 ( V_3 , V_3 -> V_164 ,
V_167 , sizeof( V_160 ) , & V_160 ) ;
}
}
static inline int F_89 ( T_6 V_86 , T_8 V_168 )
{
T_7 V_169 = V_170 ;
if ( ! V_171 )
V_169 |= V_172 | V_173 ;
switch ( V_86 ) {
case V_87 :
return V_172 & V_168 & V_169 ;
case V_174 :
return V_173 & V_168 & V_169 ;
default:
return 0x00 ;
}
}
static void F_56 ( struct V_2 * V_3 , struct V_1 * V_14 , int V_15 )
{
struct V_39 * V_9 ;
struct V_175 V_160 ;
if ( ! V_3 )
return;
V_9 = V_14 -> V_9 ;
if ( V_14 -> V_86 == V_87 ) {
F_47 ( V_14 ) ;
F_48 ( V_14 ) ;
F_49 ( V_14 ) ;
}
V_160 . V_7 = F_16 ( V_14 -> V_7 ) ;
V_160 . V_8 = F_16 ( V_14 -> V_8 ) ;
F_57 ( V_3 , F_61 ( V_3 ) ,
V_176 , sizeof( V_160 ) , & V_160 ) ;
F_21 ( V_14 , V_31 ) ;
V_9 -> V_79 = V_15 ;
}
static void F_90 ( struct V_2 * V_3 )
{
struct V_1 * V_14 ;
F_22 ( L_21 , V_3 ) ;
F_2 () ;
F_3 (chan, &conn->chan_l, list) {
struct V_39 * V_9 = V_14 -> V_9 ;
F_91 ( V_9 ) ;
if ( V_14 -> V_52 != V_53 ) {
F_92 ( V_9 ) ;
continue;
}
if ( V_14 -> V_23 == V_28 ) {
struct V_159 V_160 ;
if ( ! F_59 ( V_14 ) ||
! F_85 ( V_14 ) ) {
F_92 ( V_9 ) ;
continue;
}
if ( ! F_89 ( V_14 -> V_86 , V_3 -> V_168 )
&& F_45 ( V_177 ,
& V_14 -> V_83 ) ) {
F_25 ( V_14 , V_92 ) ;
F_92 ( V_9 ) ;
continue;
}
V_160 . V_8 = F_16 ( V_14 -> V_8 ) ;
V_160 . V_11 = V_14 -> V_11 ;
V_14 -> V_10 = F_61 ( V_3 ) ;
F_83 ( V_155 , & V_14 -> V_83 ) ;
F_57 ( V_3 , V_14 -> V_10 , V_161 ,
sizeof( V_160 ) , & V_160 ) ;
} else if ( V_14 -> V_23 == V_29 ) {
struct V_96 V_97 ;
char V_178 [ 128 ] ;
V_97 . V_8 = F_16 ( V_14 -> V_7 ) ;
V_97 . V_7 = F_16 ( V_14 -> V_8 ) ;
if ( F_59 ( V_14 ) ) {
if ( F_13 ( V_9 ) -> V_99 ) {
struct V_39 * V_77 = F_13 ( V_9 ) -> V_77 ;
V_97 . V_98 = F_16 ( V_179 ) ;
V_97 . V_102 = F_16 ( V_180 ) ;
if ( V_77 )
V_77 -> V_80 ( V_77 , 0 ) ;
} else {
F_21 ( V_14 , V_30 ) ;
V_97 . V_98 = F_16 ( V_181 ) ;
V_97 . V_102 = F_16 ( V_103 ) ;
}
} else {
V_97 . V_98 = F_16 ( V_179 ) ;
V_97 . V_102 = F_16 ( V_182 ) ;
}
F_57 ( V_3 , V_14 -> V_10 , V_104 ,
sizeof( V_97 ) , & V_97 ) ;
if ( F_45 ( V_183 , & V_14 -> V_83 ) ||
V_97 . V_98 != V_181 ) {
F_92 ( V_9 ) ;
continue;
}
F_83 ( V_183 , & V_14 -> V_83 ) ;
F_57 ( V_3 , F_61 ( V_3 ) , V_184 ,
F_93 ( V_14 , V_178 ) , V_178 ) ;
V_14 -> V_185 ++ ;
}
F_92 ( V_9 ) ;
}
F_4 () ;
}
static struct V_1 * F_94 ( int V_23 , T_3 V_4 , T_4 * V_12 )
{
struct V_1 * V_5 , * V_186 = NULL ;
F_95 ( & V_16 ) ;
F_11 (c, &chan_list, global_l) {
struct V_39 * V_9 = V_5 -> V_9 ;
if ( V_23 && V_5 -> V_23 != V_23 )
continue;
if ( V_5 -> V_8 == V_4 ) {
if ( ! F_12 ( & F_13 ( V_9 ) -> V_12 , V_12 ) ) {
F_96 ( & V_16 ) ;
return V_5 ;
}
if ( ! F_12 ( & F_13 ( V_9 ) -> V_12 , V_187 ) )
V_186 = V_5 ;
}
}
F_96 ( & V_16 ) ;
return V_186 ;
}
static void F_97 ( struct V_2 * V_3 )
{
struct V_39 * V_77 , * V_9 ;
struct V_1 * V_14 , * V_188 ;
F_22 ( L_22 ) ;
V_188 = F_94 ( V_27 , V_58 ,
V_3 -> V_12 ) ;
if ( ! V_188 )
return;
V_77 = V_188 -> V_9 ;
F_7 ( V_77 ) ;
if ( F_98 ( V_77 ) ) {
F_22 ( L_23 , V_77 -> V_189 ) ;
goto V_190;
}
V_14 = V_188 -> V_33 -> V_191 ( V_188 -> V_35 ) ;
if ( ! V_14 )
goto V_190;
V_9 = V_14 -> V_9 ;
F_99 ( V_3 -> V_54 ) ;
F_100 ( & F_13 ( V_9 ) -> V_12 , V_3 -> V_12 ) ;
F_100 ( & F_13 ( V_9 ) -> V_192 , V_3 -> V_192 ) ;
F_101 ( V_77 , V_9 ) ;
F_35 ( V_3 , V_14 ) ;
F_55 ( V_14 , V_9 -> V_95 ) ;
F_21 ( V_14 , V_24 ) ;
V_77 -> V_80 ( V_77 , 0 ) ;
V_190:
F_26 ( V_77 ) ;
}
static void F_102 ( struct V_39 * V_9 )
{
struct V_1 * V_14 = F_54 ( V_9 ) -> V_14 ;
struct V_39 * V_77 = F_13 ( V_9 ) -> V_77 ;
F_22 ( L_24 , V_9 , V_77 ) ;
V_14 -> V_83 = 0 ;
F_39 ( V_14 ) ;
F_21 ( V_14 , V_24 ) ;
V_9 -> V_81 ( V_9 ) ;
if ( V_77 )
V_77 -> V_80 ( V_77 , 0 ) ;
}
static void F_103 ( struct V_2 * V_3 )
{
struct V_1 * V_14 ;
F_22 ( L_21 , V_3 ) ;
if ( ! V_3 -> V_54 -> V_193 && V_3 -> V_54 -> type == V_55 )
F_97 ( V_3 ) ;
if ( V_3 -> V_54 -> V_193 && V_3 -> V_54 -> type == V_55 )
F_104 ( V_3 , V_3 -> V_54 -> V_194 ) ;
F_2 () ;
F_3 (chan, &conn->chan_l, list) {
struct V_39 * V_9 = V_14 -> V_9 ;
F_91 ( V_9 ) ;
if ( V_3 -> V_54 -> type == V_55 ) {
if ( F_104 ( V_3 , V_14 -> V_42 ) )
F_102 ( V_9 ) ;
} else if ( V_14 -> V_52 != V_53 ) {
F_39 ( V_14 ) ;
F_21 ( V_14 , V_24 ) ;
V_9 -> V_81 ( V_9 ) ;
} else if ( V_14 -> V_23 == V_28 )
F_86 ( V_14 ) ;
F_92 ( V_9 ) ;
}
F_4 () ;
}
static void F_105 ( struct V_2 * V_3 , int V_15 )
{
struct V_1 * V_14 ;
F_22 ( L_21 , V_3 ) ;
F_2 () ;
F_3 (chan, &conn->chan_l, list) {
struct V_39 * V_9 = V_14 -> V_9 ;
if ( F_45 ( V_195 , & V_14 -> V_123 ) )
V_9 -> V_79 = V_15 ;
}
F_4 () ;
}
static void F_106 ( struct V_36 * V_37 )
{
struct V_2 * V_3 = F_24 ( V_37 , struct V_2 ,
V_165 . V_37 ) ;
V_3 -> V_156 |= V_158 ;
V_3 -> V_164 = 0 ;
F_90 ( V_3 ) ;
}
static void F_107 ( struct V_132 * V_54 , int V_15 )
{
struct V_2 * V_3 = V_54 -> V_196 ;
struct V_1 * V_14 , * V_89 ;
struct V_39 * V_9 ;
if ( ! V_3 )
return;
F_22 ( L_25 , V_54 , V_3 , V_15 ) ;
F_108 ( V_3 -> V_197 ) ;
F_50 (chan, l, &conn->chan_l, list) {
V_9 = V_14 -> V_9 ;
F_7 ( V_9 ) ;
F_38 ( V_14 , V_15 ) ;
F_26 ( V_9 ) ;
V_14 -> V_33 -> V_45 ( V_14 -> V_35 ) ;
}
F_109 ( V_3 -> V_131 ) ;
if ( V_3 -> V_156 & V_157 )
F_110 ( & V_3 -> V_165 ) ;
if ( F_72 ( V_198 , & V_54 -> V_199 ) ) {
F_110 ( & V_3 -> V_200 ) ;
F_111 ( V_3 ) ;
}
V_54 -> V_196 = NULL ;
F_51 ( V_3 ) ;
}
static void F_112 ( struct V_36 * V_37 )
{
struct V_2 * V_3 = F_24 ( V_37 , struct V_2 ,
V_200 . V_37 ) ;
F_107 ( V_3 -> V_54 , V_44 ) ;
}
static struct V_2 * F_113 ( struct V_132 * V_54 , T_2 V_102 )
{
struct V_2 * V_3 = V_54 -> V_196 ;
struct V_201 * V_131 ;
if ( V_3 || V_102 )
return V_3 ;
V_131 = F_114 ( V_54 ) ;
if ( ! V_131 )
return NULL ;
V_3 = F_29 ( sizeof( struct V_2 ) , V_46 ) ;
if ( ! V_3 ) {
F_109 ( V_131 ) ;
return NULL ;
}
V_54 -> V_196 = V_3 ;
V_3 -> V_54 = V_54 ;
V_3 -> V_131 = V_131 ;
F_22 ( L_26 , V_54 , V_3 , V_131 ) ;
if ( V_54 -> V_124 -> V_202 && V_54 -> type == V_55 )
V_3 -> V_203 = V_54 -> V_124 -> V_202 ;
else
V_3 -> V_203 = V_54 -> V_124 -> V_204 ;
V_3 -> V_12 = & V_54 -> V_124 -> V_205 ;
V_3 -> V_192 = & V_54 -> V_192 ;
V_3 -> V_168 = 0 ;
F_115 ( & V_3 -> V_117 ) ;
F_116 ( & V_3 -> V_76 ) ;
if ( V_54 -> type == V_55 )
F_31 ( & V_3 -> V_200 , F_112 ) ;
else
F_31 ( & V_3 -> V_165 , F_106 ) ;
V_3 -> V_50 = V_51 ;
return V_3 ;
}
static struct V_1 * F_117 ( int V_23 , T_3 V_11 , T_4 * V_12 )
{
struct V_1 * V_5 , * V_186 = NULL ;
F_95 ( & V_16 ) ;
F_11 (c, &chan_list, global_l) {
struct V_39 * V_9 = V_5 -> V_9 ;
if ( V_23 && V_5 -> V_23 != V_23 )
continue;
if ( V_5 -> V_11 == V_11 ) {
if ( ! F_12 ( & F_13 ( V_9 ) -> V_12 , V_12 ) ) {
F_96 ( & V_16 ) ;
return V_5 ;
}
if ( ! F_12 ( & F_13 ( V_9 ) -> V_12 , V_187 ) )
V_186 = V_5 ;
}
}
F_96 ( & V_16 ) ;
return V_186 ;
}
int F_118 ( struct V_1 * V_14 , T_3 V_11 , T_1 V_4 , T_4 * V_192 )
{
struct V_39 * V_9 = V_14 -> V_9 ;
T_4 * V_12 = & F_13 ( V_9 ) -> V_12 ;
struct V_2 * V_3 ;
struct V_132 * V_54 ;
struct V_206 * V_124 ;
T_6 V_115 ;
int V_15 ;
F_22 ( L_27 , F_119 ( V_12 ) , F_119 ( V_192 ) ,
V_14 -> V_11 ) ;
V_124 = F_120 ( V_192 , V_12 ) ;
if ( ! V_124 )
return - V_207 ;
F_121 ( V_124 ) ;
F_7 ( V_9 ) ;
if ( ( F_122 ( V_11 ) & 0x0101 ) != 0x0001 && ! V_4 &&
V_14 -> V_52 != V_105 ) {
V_15 = - V_20 ;
goto V_18;
}
if ( V_14 -> V_52 == V_53 && ! ( V_11 || V_4 ) ) {
V_15 = - V_20 ;
goto V_18;
}
switch ( V_14 -> V_86 ) {
case V_208 :
break;
case V_87 :
case V_174 :
if ( ! V_171 )
break;
default:
V_15 = - V_209 ;
goto V_18;
}
switch ( V_9 -> V_210 ) {
case V_28 :
case V_29 :
case V_30 :
V_15 = 0 ;
goto V_18;
case V_24 :
V_15 = - V_211 ;
goto V_18;
case V_25 :
case V_26 :
break;
default:
V_15 = - V_212 ;
goto V_18;
}
F_100 ( & F_13 ( V_9 ) -> V_192 , V_192 ) ;
V_14 -> V_11 = V_11 ;
V_14 -> V_7 = V_4 ;
V_115 = F_58 ( V_14 ) ;
if ( V_14 -> V_7 == V_58 )
V_54 = F_123 ( V_124 , V_55 , V_192 ,
V_14 -> V_42 , V_115 ) ;
else
V_54 = F_123 ( V_124 , V_94 , V_192 ,
V_14 -> V_42 , V_115 ) ;
if ( F_124 ( V_54 ) ) {
V_15 = F_125 ( V_54 ) ;
goto V_18;
}
V_3 = F_113 ( V_54 , 0 ) ;
if ( ! V_3 ) {
F_42 ( V_54 ) ;
V_15 = - V_213 ;
goto V_18;
}
F_100 ( V_12 , V_3 -> V_12 ) ;
F_35 ( V_3 , V_14 ) ;
F_21 ( V_14 , V_28 ) ;
F_55 ( V_14 , V_9 -> V_95 ) ;
if ( V_54 -> V_23 == V_24 ) {
if ( V_14 -> V_52 != V_53 ) {
F_39 ( V_14 ) ;
if ( F_59 ( V_14 ) )
F_21 ( V_14 , V_24 ) ;
} else
F_86 ( V_14 ) ;
}
V_15 = 0 ;
V_18:
F_126 ( V_124 ) ;
F_127 ( V_124 ) ;
return V_15 ;
}
int F_128 ( struct V_39 * V_9 )
{
struct V_1 * V_14 = F_54 ( V_9 ) -> V_14 ;
F_129 ( V_214 , V_215 ) ;
int V_15 = 0 ;
int V_216 = V_217 / 5 ;
F_130 ( F_131 ( V_9 ) , & V_214 ) ;
F_132 ( V_218 ) ;
while ( V_14 -> V_219 > 0 && V_14 -> V_3 ) {
if ( ! V_216 )
V_216 = V_217 / 5 ;
if ( F_133 ( V_215 ) ) {
V_15 = F_134 ( V_216 ) ;
break;
}
F_26 ( V_9 ) ;
V_216 = F_135 ( V_216 ) ;
F_7 ( V_9 ) ;
F_132 ( V_218 ) ;
V_15 = F_136 ( V_9 ) ;
if ( V_15 )
break;
}
F_132 ( V_220 ) ;
F_137 ( F_131 ( V_9 ) , & V_214 ) ;
return V_15 ;
}
static void F_138 ( struct V_36 * V_37 )
{
struct V_1 * V_14 = F_24 ( V_37 , struct V_1 ,
V_221 . V_37 ) ;
struct V_39 * V_9 = V_14 -> V_9 ;
F_22 ( L_28 , V_14 ) ;
F_7 ( V_9 ) ;
if ( V_14 -> V_222 >= V_14 -> V_223 ) {
F_56 ( V_14 -> V_3 , V_14 , V_224 ) ;
F_26 ( V_9 ) ;
return;
}
V_14 -> V_222 ++ ;
F_139 ( V_14 ) ;
F_81 ( V_14 , V_225 ) ;
F_26 ( V_9 ) ;
}
static void F_140 ( struct V_36 * V_37 )
{
struct V_1 * V_14 = F_24 ( V_37 , struct V_1 ,
V_226 . V_37 ) ;
struct V_39 * V_9 = V_14 -> V_9 ;
F_22 ( L_28 , V_14 ) ;
F_7 ( V_9 ) ;
V_14 -> V_222 = 1 ;
F_139 ( V_14 ) ;
F_83 ( V_227 , & V_14 -> V_147 ) ;
F_81 ( V_14 , V_225 ) ;
F_26 ( V_9 ) ;
}
static void F_141 ( struct V_1 * V_14 )
{
struct V_121 * V_122 ;
while ( ( V_122 = F_142 ( & V_14 -> V_85 ) ) &&
V_14 -> V_219 ) {
if ( F_66 ( V_122 ) -> V_228 == V_14 -> V_229 )
break;
V_122 = F_143 ( & V_14 -> V_85 ) ;
F_108 ( V_122 ) ;
V_14 -> V_219 -- ;
}
if ( ! V_14 -> V_219 )
F_47 ( V_14 ) ;
}
static void F_144 ( struct V_1 * V_14 )
{
struct V_121 * V_122 ;
T_7 V_135 ;
T_1 V_143 ;
while ( ( V_122 = F_143 ( & V_14 -> V_85 ) ) ) {
V_135 = F_145 ( V_14 , V_122 -> V_35 + V_149 ) ;
V_135 |= F_146 ( V_14 , V_14 -> V_230 ) ;
F_77 ( V_14 , V_135 , V_122 -> V_35 + V_149 ) ;
if ( V_14 -> V_143 == V_144 ) {
V_143 = F_79 ( 0 , ( T_2 * ) V_122 -> V_35 ,
V_122 -> V_120 - V_145 ) ;
F_80 ( V_143 ,
V_122 -> V_35 + V_122 -> V_120 - V_145 ) ;
}
F_68 ( V_14 , V_122 ) ;
V_14 -> V_230 = F_147 ( V_14 , V_14 -> V_230 ) ;
}
}
static void F_148 ( struct V_1 * V_14 , T_1 V_228 )
{
struct V_121 * V_122 , * V_231 ;
T_1 V_143 ;
T_7 V_135 ;
V_122 = F_142 ( & V_14 -> V_85 ) ;
if ( ! V_122 )
return;
while ( F_66 ( V_122 ) -> V_228 != V_228 ) {
if ( F_149 ( & V_14 -> V_85 , V_122 ) )
return;
V_122 = F_150 ( & V_14 -> V_85 , V_122 ) ;
}
if ( V_14 -> V_223 &&
F_66 ( V_122 ) -> V_232 == V_14 -> V_223 ) {
F_56 ( V_14 -> V_3 , V_14 , V_224 ) ;
return;
}
V_231 = F_151 ( V_122 , V_46 ) ;
F_66 ( V_122 ) -> V_232 ++ ;
V_135 = F_145 ( V_14 , V_231 -> V_35 + V_149 ) ;
V_135 &= F_152 ( V_14 ) ;
if ( F_72 ( V_146 , & V_14 -> V_147 ) )
V_135 |= F_73 ( V_14 ) ;
V_135 |= F_84 ( V_14 , V_14 -> V_154 ) ;
V_135 |= F_146 ( V_14 , V_228 ) ;
F_77 ( V_14 , V_135 , V_231 -> V_35 + V_149 ) ;
if ( V_14 -> V_143 == V_144 ) {
V_143 = F_79 ( 0 , ( T_2 * ) V_231 -> V_35 ,
V_231 -> V_120 - V_145 ) ;
F_80 ( V_143 ,
V_231 -> V_35 + V_231 -> V_120 - V_145 ) ;
}
F_68 ( V_14 , V_231 ) ;
}
static int F_153 ( struct V_1 * V_14 )
{
struct V_121 * V_122 , * V_231 ;
T_1 V_143 ;
T_7 V_135 ;
int V_233 = 0 ;
if ( V_14 -> V_23 != V_24 )
return - V_234 ;
while ( ( V_122 = V_14 -> V_235 ) && ( ! F_154 ( V_14 ) ) ) {
if ( V_14 -> V_223 &&
F_66 ( V_122 ) -> V_232 == V_14 -> V_223 ) {
F_56 ( V_14 -> V_3 , V_14 , V_224 ) ;
break;
}
V_231 = F_151 ( V_122 , V_46 ) ;
F_66 ( V_122 ) -> V_232 ++ ;
V_135 = F_145 ( V_14 , V_231 -> V_35 + V_149 ) ;
V_135 &= F_152 ( V_14 ) ;
if ( F_72 ( V_146 , & V_14 -> V_147 ) )
V_135 |= F_73 ( V_14 ) ;
V_135 |= F_84 ( V_14 , V_14 -> V_154 ) ;
V_135 |= F_146 ( V_14 , V_14 -> V_230 ) ;
F_77 ( V_14 , V_135 , V_231 -> V_35 + V_149 ) ;
if ( V_14 -> V_143 == V_144 ) {
V_143 = F_79 ( 0 , ( T_2 * ) V_122 -> V_35 ,
V_231 -> V_120 - V_145 ) ;
F_80 ( V_143 , V_122 -> V_35 +
V_231 -> V_120 - V_145 ) ;
}
F_68 ( V_14 , V_231 ) ;
F_155 ( V_14 ) ;
F_66 ( V_122 ) -> V_228 = V_14 -> V_230 ;
V_14 -> V_230 = F_147 ( V_14 , V_14 -> V_230 ) ;
if ( F_66 ( V_122 ) -> V_232 == 1 )
V_14 -> V_219 ++ ;
V_14 -> V_236 ++ ;
if ( F_149 ( & V_14 -> V_85 , V_122 ) )
V_14 -> V_235 = NULL ;
else
V_14 -> V_235 = F_150 ( & V_14 -> V_85 , V_122 ) ;
V_233 ++ ;
}
return V_233 ;
}
static int F_156 ( struct V_1 * V_14 )
{
int V_237 ;
if ( ! F_157 ( & V_14 -> V_85 ) )
V_14 -> V_235 = V_14 -> V_85 . V_238 ;
V_14 -> V_230 = V_14 -> V_229 ;
V_237 = F_153 ( V_14 ) ;
return V_237 ;
}
static void F_158 ( struct V_1 * V_14 )
{
T_7 V_135 = 0 ;
V_135 |= F_84 ( V_14 , V_14 -> V_154 ) ;
if ( F_45 ( V_150 , & V_14 -> V_147 ) ) {
V_135 |= F_82 ( V_14 , V_151 ) ;
F_83 ( V_152 , & V_14 -> V_147 ) ;
F_69 ( V_14 , V_135 ) ;
return;
}
if ( F_153 ( V_14 ) > 0 )
return;
V_135 |= F_82 ( V_14 , V_153 ) ;
F_69 ( V_14 , V_135 ) ;
}
static void F_159 ( struct V_1 * V_14 )
{
struct V_88 * V_239 ;
T_7 V_135 ;
V_135 = F_82 ( V_14 , V_240 ) ;
V_135 |= F_73 ( V_14 ) ;
V_239 = F_160 ( ( & V_14 -> V_241 ) -> V_242 , struct V_88 , V_75 ) ;
V_135 |= F_84 ( V_14 , V_239 -> V_228 ) ;
F_69 ( V_14 , V_135 ) ;
}
static inline int F_161 ( struct V_39 * V_9 , struct V_243 * V_244 , int V_120 , int V_138 , struct V_121 * V_122 )
{
struct V_2 * V_3 = F_54 ( V_9 ) -> V_14 -> V_3 ;
struct V_121 * * V_245 ;
int V_15 , V_246 = 0 ;
if ( F_162 ( F_76 ( V_122 , V_138 ) , V_244 -> V_247 , V_138 ) )
return - V_248 ;
V_246 += V_138 ;
V_120 -= V_138 ;
V_245 = & F_163 ( V_122 ) -> V_249 ;
while ( V_120 ) {
V_138 = F_70 (unsigned int, conn->mtu, len) ;
* V_245 = F_164 ( V_9 , V_138 , V_244 -> V_250 & V_251 , & V_15 ) ;
if ( ! * V_245 )
return V_15 ;
if ( F_162 ( F_76 ( * V_245 , V_138 ) , V_244 -> V_247 , V_138 ) )
return - V_248 ;
( * V_245 ) -> V_129 = V_122 -> V_129 ;
V_246 += V_138 ;
V_120 -= V_138 ;
V_245 = & ( * V_245 ) -> V_238 ;
}
return V_246 ;
}
static struct V_121 * F_165 ( struct V_1 * V_14 ,
struct V_243 * V_244 , T_9 V_120 ,
T_7 V_129 )
{
struct V_39 * V_9 = V_14 -> V_9 ;
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_121 * V_122 ;
int V_15 , V_138 , V_139 = V_149 + V_252 ;
struct V_136 * V_137 ;
F_22 ( L_29 , V_9 , ( int ) V_120 , V_129 ) ;
V_138 = F_70 (unsigned int, (conn->mtu - hlen), len) ;
V_122 = F_164 ( V_9 , V_138 + V_139 ,
V_244 -> V_250 & V_251 , & V_15 ) ;
if ( ! V_122 )
return F_166 ( V_15 ) ;
V_122 -> V_129 = V_129 ;
V_137 = (struct V_136 * ) F_76 ( V_122 , V_149 ) ;
V_137 -> V_4 = F_16 ( V_14 -> V_7 ) ;
V_137 -> V_120 = F_16 ( V_120 + ( V_139 - V_149 ) ) ;
F_80 ( V_14 -> V_11 , F_76 ( V_122 , 2 ) ) ;
V_15 = F_161 ( V_9 , V_244 , V_120 , V_138 , V_122 ) ;
if ( F_167 ( V_15 < 0 ) ) {
F_108 ( V_122 ) ;
return F_166 ( V_15 ) ;
}
return V_122 ;
}
static struct V_121 * F_168 ( struct V_1 * V_14 ,
struct V_243 * V_244 , T_9 V_120 ,
T_7 V_129 )
{
struct V_39 * V_9 = V_14 -> V_9 ;
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_121 * V_122 ;
int V_15 , V_138 , V_139 = V_149 ;
struct V_136 * V_137 ;
F_22 ( L_30 , V_9 , ( int ) V_120 ) ;
V_138 = F_70 (unsigned int, (conn->mtu - hlen), len) ;
V_122 = F_164 ( V_9 , V_138 + V_139 ,
V_244 -> V_250 & V_251 , & V_15 ) ;
if ( ! V_122 )
return F_166 ( V_15 ) ;
V_122 -> V_129 = V_129 ;
V_137 = (struct V_136 * ) F_76 ( V_122 , V_149 ) ;
V_137 -> V_4 = F_16 ( V_14 -> V_7 ) ;
V_137 -> V_120 = F_16 ( V_120 + ( V_139 - V_149 ) ) ;
V_15 = F_161 ( V_9 , V_244 , V_120 , V_138 , V_122 ) ;
if ( F_167 ( V_15 < 0 ) ) {
F_108 ( V_122 ) ;
return F_166 ( V_15 ) ;
}
return V_122 ;
}
static struct V_121 * F_169 ( struct V_1 * V_14 ,
struct V_243 * V_244 , T_9 V_120 ,
T_7 V_135 , T_1 V_253 )
{
struct V_39 * V_9 = V_14 -> V_9 ;
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_121 * V_122 ;
int V_15 , V_138 , V_139 ;
struct V_136 * V_137 ;
F_22 ( L_30 , V_9 , ( int ) V_120 ) ;
if ( ! V_3 )
return F_166 ( - V_234 ) ;
if ( F_45 ( V_140 , & V_14 -> V_123 ) )
V_139 = V_141 ;
else
V_139 = V_142 ;
if ( V_253 )
V_139 += V_254 ;
if ( V_14 -> V_143 == V_144 )
V_139 += V_145 ;
V_138 = F_70 (unsigned int, (conn->mtu - hlen), len) ;
V_122 = F_164 ( V_9 , V_138 + V_139 ,
V_244 -> V_250 & V_251 , & V_15 ) ;
if ( ! V_122 )
return F_166 ( V_15 ) ;
V_137 = (struct V_136 * ) F_76 ( V_122 , V_149 ) ;
V_137 -> V_4 = F_16 ( V_14 -> V_7 ) ;
V_137 -> V_120 = F_16 ( V_120 + ( V_139 - V_149 ) ) ;
F_77 ( V_14 , V_135 , F_76 ( V_122 , F_78 ( V_14 ) ) ) ;
if ( V_253 )
F_80 ( V_253 , F_76 ( V_122 , V_254 ) ) ;
V_15 = F_161 ( V_9 , V_244 , V_120 , V_138 , V_122 ) ;
if ( F_167 ( V_15 < 0 ) ) {
F_108 ( V_122 ) ;
return F_166 ( V_15 ) ;
}
if ( V_14 -> V_143 == V_144 )
F_80 ( 0 , F_76 ( V_122 , V_145 ) ) ;
F_66 ( V_122 ) -> V_232 = 0 ;
return V_122 ;
}
static int F_170 ( struct V_1 * V_14 , struct V_243 * V_244 , T_9 V_120 )
{
struct V_121 * V_122 ;
struct V_255 V_256 ;
T_7 V_135 ;
T_9 V_257 = 0 ;
F_171 ( & V_256 ) ;
V_135 = F_172 ( V_14 , V_258 ) ;
V_122 = F_169 ( V_14 , V_244 , V_14 -> V_259 , V_135 , V_120 ) ;
if ( F_124 ( V_122 ) )
return F_125 ( V_122 ) ;
F_173 ( & V_256 , V_122 ) ;
V_120 -= V_14 -> V_259 ;
V_257 += V_14 -> V_259 ;
while ( V_120 > 0 ) {
T_9 V_260 ;
if ( V_120 > V_14 -> V_259 ) {
V_135 = F_172 ( V_14 , V_261 ) ;
V_260 = V_14 -> V_259 ;
} else {
V_135 = F_172 ( V_14 , V_262 ) ;
V_260 = V_120 ;
}
V_122 = F_169 ( V_14 , V_244 , V_260 , V_135 , 0 ) ;
if ( F_124 ( V_122 ) ) {
F_46 ( & V_256 ) ;
return F_125 ( V_122 ) ;
}
F_173 ( & V_256 , V_122 ) ;
V_120 -= V_260 ;
V_257 += V_260 ;
}
F_174 ( & V_256 , & V_14 -> V_85 ) ;
if ( V_14 -> V_235 == NULL )
V_14 -> V_235 = V_256 . V_238 ;
return V_257 ;
}
int F_175 ( struct V_1 * V_14 , struct V_243 * V_244 , T_9 V_120 ,
T_7 V_129 )
{
struct V_121 * V_122 ;
T_7 V_135 ;
int V_15 ;
if ( V_14 -> V_52 == V_60 ) {
V_122 = F_165 ( V_14 , V_244 , V_120 , V_129 ) ;
if ( F_124 ( V_122 ) )
return F_125 ( V_122 ) ;
F_68 ( V_14 , V_122 ) ;
return V_120 ;
}
switch ( V_14 -> V_86 ) {
case V_208 :
if ( V_120 > V_14 -> V_56 )
return - V_263 ;
V_122 = F_168 ( V_14 , V_244 , V_120 , V_129 ) ;
if ( F_124 ( V_122 ) )
return F_125 ( V_122 ) ;
F_68 ( V_14 , V_122 ) ;
V_15 = V_120 ;
break;
case V_87 :
case V_174 :
if ( V_120 <= V_14 -> V_259 ) {
V_135 = F_172 ( V_14 , V_264 ) ;
V_122 = F_169 ( V_14 , V_244 , V_120 , V_135 ,
0 ) ;
if ( F_124 ( V_122 ) )
return F_125 ( V_122 ) ;
F_173 ( & V_14 -> V_85 , V_122 ) ;
if ( V_14 -> V_235 == NULL )
V_14 -> V_235 = V_122 ;
} else {
V_15 = F_170 ( V_14 , V_244 , V_120 ) ;
if ( V_15 < 0 )
return V_15 ;
}
if ( V_14 -> V_86 == V_174 ) {
F_144 ( V_14 ) ;
V_15 = V_120 ;
break;
}
if ( F_45 ( V_265 , & V_14 -> V_147 ) &&
F_45 ( V_227 , & V_14 -> V_147 ) ) {
V_15 = V_120 ;
break;
}
V_15 = F_153 ( V_14 ) ;
if ( V_15 >= 0 )
V_15 = V_120 ;
break;
default:
F_22 ( L_31 , V_14 -> V_86 ) ;
V_15 = - V_212 ;
}
return V_15 ;
}
static void F_176 ( struct V_2 * V_3 , struct V_121 * V_122 )
{
struct V_121 * V_266 ;
struct V_1 * V_14 ;
F_22 ( L_21 , V_3 ) ;
F_2 () ;
F_3 (chan, &conn->chan_l, list) {
struct V_39 * V_9 = V_14 -> V_9 ;
if ( V_14 -> V_52 != V_105 )
continue;
if ( V_122 -> V_9 == V_9 )
continue;
V_266 = F_151 ( V_122 , V_46 ) ;
if ( ! V_266 )
continue;
if ( V_14 -> V_33 -> V_267 ( V_14 -> V_35 , V_266 ) )
F_108 ( V_266 ) ;
}
F_4 () ;
}
static struct V_121 * F_64 ( struct V_2 * V_3 ,
T_2 V_119 , T_2 V_10 , T_1 V_268 , void * V_35 )
{
struct V_121 * V_122 , * * V_245 ;
struct V_269 * V_270 ;
struct V_136 * V_137 ;
int V_120 , V_138 ;
F_22 ( L_32 ,
V_3 , V_119 , V_10 , V_268 ) ;
V_120 = V_149 + V_271 + V_268 ;
V_138 = F_70 (unsigned int, conn->mtu, len) ;
V_122 = F_75 ( V_138 , V_46 ) ;
if ( ! V_122 )
return NULL ;
V_137 = (struct V_136 * ) F_76 ( V_122 , V_149 ) ;
V_137 -> V_120 = F_16 ( V_271 + V_268 ) ;
if ( V_3 -> V_54 -> type == V_55 )
V_137 -> V_4 = F_16 ( V_272 ) ;
else
V_137 -> V_4 = F_16 ( V_62 ) ;
V_270 = (struct V_269 * ) F_76 ( V_122 , V_271 ) ;
V_270 -> V_119 = V_119 ;
V_270 -> V_10 = V_10 ;
V_270 -> V_120 = F_16 ( V_268 ) ;
if ( V_268 ) {
V_138 -= V_149 + V_271 ;
memcpy ( F_76 ( V_122 , V_138 ) , V_35 , V_138 ) ;
V_35 += V_138 ;
}
V_120 -= V_122 -> V_120 ;
V_245 = & F_163 ( V_122 ) -> V_249 ;
while ( V_120 ) {
V_138 = F_70 (unsigned int, conn->mtu, len) ;
* V_245 = F_75 ( V_138 , V_46 ) ;
if ( ! * V_245 )
goto V_273;
memcpy ( F_76 ( * V_245 , V_138 ) , V_35 , V_138 ) ;
V_120 -= V_138 ;
V_35 += V_138 ;
V_245 = & ( * V_245 ) -> V_238 ;
}
return V_122 ;
V_273:
F_108 ( V_122 ) ;
return NULL ;
}
static inline int F_177 ( void * * V_274 , int * type , int * V_275 , unsigned long * V_276 )
{
struct V_277 * V_278 = * V_274 ;
int V_120 ;
V_120 = V_279 + V_278 -> V_120 ;
* V_274 += V_120 ;
* type = V_278 -> type ;
* V_275 = V_278 -> V_120 ;
switch ( V_278 -> V_120 ) {
case 1 :
* V_276 = * ( ( T_2 * ) V_278 -> V_276 ) ;
break;
case 2 :
* V_276 = F_178 ( V_278 -> V_276 ) ;
break;
case 4 :
* V_276 = F_179 ( V_278 -> V_276 ) ;
break;
default:
* V_276 = ( unsigned long ) V_278 -> V_276 ;
break;
}
F_22 ( L_33 , * type , V_278 -> V_120 , * V_276 ) ;
return V_120 ;
}
static void F_180 ( void * * V_274 , T_2 type , T_2 V_120 , unsigned long V_276 )
{
struct V_277 * V_278 = * V_274 ;
F_22 ( L_33 , type , V_120 , V_276 ) ;
V_278 -> type = type ;
V_278 -> V_120 = V_120 ;
switch ( V_120 ) {
case 1 :
* ( ( T_2 * ) V_278 -> V_276 ) = V_276 ;
break;
case 2 :
F_80 ( V_276 , V_278 -> V_276 ) ;
break;
case 4 :
F_181 ( V_276 , V_278 -> V_276 ) ;
break;
default:
memcpy ( V_278 -> V_276 , ( void * ) V_276 , V_120 ) ;
break;
}
* V_274 += V_279 + V_120 ;
}
static void F_182 ( void * * V_274 , struct V_1 * V_14 )
{
struct V_280 V_281 ;
switch ( V_14 -> V_86 ) {
case V_87 :
V_281 . V_116 = V_14 -> V_63 ;
V_281 . V_282 = V_14 -> V_65 ;
V_281 . V_283 = F_16 ( V_14 -> V_67 ) ;
V_281 . V_284 = F_183 ( V_14 -> V_69 ) ;
V_281 . V_285 = F_183 ( V_72 ) ;
V_281 . V_286 = F_183 ( V_74 ) ;
break;
case V_174 :
V_281 . V_116 = 1 ;
V_281 . V_282 = V_66 ;
V_281 . V_283 = F_16 ( V_14 -> V_67 ) ;
V_281 . V_284 = F_183 ( V_14 -> V_69 ) ;
V_281 . V_285 = 0 ;
V_281 . V_286 = 0 ;
break;
default:
return;
}
F_180 ( V_274 , V_287 , sizeof( V_281 ) ,
( unsigned long ) & V_281 ) ;
}
static void F_184 ( struct V_36 * V_37 )
{
struct V_1 * V_14 = F_24 ( V_37 , struct V_1 ,
V_288 . V_37 ) ;
F_22 ( L_28 , V_14 ) ;
F_7 ( V_14 -> V_9 ) ;
F_158 ( V_14 ) ;
F_26 ( V_14 -> V_9 ) ;
}
static inline void F_185 ( struct V_1 * V_14 )
{
V_14 -> V_229 = 0 ;
V_14 -> V_219 = 0 ;
V_14 -> V_154 = 0 ;
V_14 -> V_289 = 0 ;
V_14 -> V_236 = 0 ;
F_31 ( & V_14 -> V_226 , F_140 ) ;
F_31 ( & V_14 -> V_221 , F_138 ) ;
F_31 ( & V_14 -> V_288 , F_184 ) ;
F_171 ( & V_14 -> V_91 ) ;
F_116 ( & V_14 -> V_241 ) ;
}
static inline T_6 F_186 ( T_6 V_86 , T_5 V_290 )
{
switch ( V_86 ) {
case V_174 :
case V_87 :
if ( F_89 ( V_86 , V_290 ) )
return V_86 ;
default:
return V_208 ;
}
}
static inline bool F_187 ( struct V_1 * V_14 )
{
return V_291 && V_14 -> V_3 -> V_168 & V_292 ;
}
static inline bool F_188 ( struct V_1 * V_14 )
{
return V_291 && V_14 -> V_3 -> V_168 & V_293 ;
}
static inline void F_189 ( struct V_1 * V_14 )
{
if ( V_14 -> V_294 > V_295 &&
F_187 ( V_14 ) ) {
F_83 ( V_140 , & V_14 -> V_123 ) ;
V_14 -> V_296 = V_297 ;
} else {
V_14 -> V_294 = F_70 ( T_1 , V_14 -> V_294 ,
V_295 ) ;
V_14 -> V_296 = V_295 ;
}
}
static int F_93 ( struct V_1 * V_14 , void * V_35 )
{
struct V_298 * V_160 = V_35 ;
struct V_299 V_300 = { . V_86 = V_14 -> V_86 } ;
void * V_274 = V_160 -> V_35 ;
T_1 V_257 ;
F_22 ( L_28 , V_14 ) ;
if ( V_14 -> V_185 || V_14 -> V_301 )
goto V_18;
switch ( V_14 -> V_86 ) {
case V_174 :
case V_87 :
if ( F_45 ( V_177 , & V_14 -> V_83 ) )
break;
if ( F_188 ( V_14 ) )
F_83 ( V_302 , & V_14 -> V_123 ) ;
default:
V_14 -> V_86 = F_186 ( V_300 . V_86 , V_14 -> V_3 -> V_168 ) ;
break;
}
V_18:
if ( V_14 -> V_303 != V_59 )
F_180 ( & V_274 , V_304 , 2 , V_14 -> V_303 ) ;
switch ( V_14 -> V_86 ) {
case V_208 :
if ( ! ( V_14 -> V_3 -> V_168 & V_172 ) &&
! ( V_14 -> V_3 -> V_168 & V_173 ) )
break;
V_300 . V_86 = V_208 ;
V_300 . V_305 = 0 ;
V_300 . V_306 = 0 ;
V_300 . V_307 = 0 ;
V_300 . V_308 = 0 ;
V_300 . V_309 = 0 ;
F_180 ( & V_274 , V_310 , sizeof( V_300 ) ,
( unsigned long ) & V_300 ) ;
break;
case V_87 :
V_300 . V_86 = V_87 ;
V_300 . V_306 = V_14 -> V_311 ;
V_300 . V_307 = 0 ;
V_300 . V_308 = 0 ;
V_257 = F_70 ( T_1 , V_312 , V_14 -> V_3 -> V_203 -
V_141 -
V_254 -
V_145 ) ;
V_300 . V_309 = F_16 ( V_257 ) ;
F_189 ( V_14 ) ;
V_300 . V_305 = F_70 ( T_1 , V_14 -> V_294 ,
V_295 ) ;
F_180 ( & V_274 , V_310 , sizeof( V_300 ) ,
( unsigned long ) & V_300 ) ;
if ( F_45 ( V_302 , & V_14 -> V_123 ) )
F_182 ( & V_274 , V_14 ) ;
if ( ! ( V_14 -> V_3 -> V_168 & V_313 ) )
break;
if ( V_14 -> V_143 == V_314 ||
F_45 ( V_315 , & V_14 -> V_83 ) ) {
V_14 -> V_143 = V_314 ;
F_180 ( & V_274 , V_316 , 1 , V_14 -> V_143 ) ;
}
if ( F_45 ( V_140 , & V_14 -> V_123 ) )
F_180 ( & V_274 , V_317 , 2 ,
V_14 -> V_294 ) ;
break;
case V_174 :
V_300 . V_86 = V_174 ;
V_300 . V_305 = 0 ;
V_300 . V_306 = 0 ;
V_300 . V_307 = 0 ;
V_300 . V_308 = 0 ;
V_257 = F_70 ( T_1 , V_312 , V_14 -> V_3 -> V_203 -
V_141 -
V_254 -
V_145 ) ;
V_300 . V_309 = F_16 ( V_257 ) ;
F_180 ( & V_274 , V_310 , sizeof( V_300 ) ,
( unsigned long ) & V_300 ) ;
if ( F_45 ( V_302 , & V_14 -> V_123 ) )
F_182 ( & V_274 , V_14 ) ;
if ( ! ( V_14 -> V_3 -> V_168 & V_313 ) )
break;
if ( V_14 -> V_143 == V_314 ||
F_45 ( V_315 , & V_14 -> V_83 ) ) {
V_14 -> V_143 = V_314 ;
F_180 ( & V_274 , V_316 , 1 , V_14 -> V_143 ) ;
}
break;
}
V_160 -> V_7 = F_16 ( V_14 -> V_7 ) ;
V_160 -> V_123 = F_16 ( 0 ) ;
return V_274 - V_35 ;
}
static int F_190 ( struct V_1 * V_14 , void * V_35 )
{
struct V_318 * V_97 = V_35 ;
void * V_274 = V_97 -> V_35 ;
void * V_160 = V_14 -> V_319 ;
int V_120 = V_14 -> V_320 ;
int type , V_321 , V_275 ;
unsigned long V_276 ;
struct V_299 V_300 = { . V_86 = V_208 } ;
struct V_280 V_281 ;
T_2 V_322 = 0 ;
T_1 V_203 = V_59 ;
T_1 V_98 = V_323 ;
T_1 V_257 ;
F_22 ( L_28 , V_14 ) ;
while ( V_120 >= V_279 ) {
V_120 -= F_177 ( & V_160 , & type , & V_275 , & V_276 ) ;
V_321 = type & V_324 ;
type &= V_325 ;
switch ( type ) {
case V_304 :
V_203 = V_276 ;
break;
case V_326 :
V_14 -> V_286 = V_276 ;
break;
case V_327 :
break;
case V_310 :
if ( V_275 == sizeof( V_300 ) )
memcpy ( & V_300 , ( void * ) V_276 , V_275 ) ;
break;
case V_316 :
if ( V_276 == V_314 )
F_83 ( V_315 , & V_14 -> V_83 ) ;
break;
case V_287 :
V_322 = 1 ;
if ( V_275 == sizeof( V_281 ) )
memcpy ( & V_281 , ( void * ) V_276 , V_275 ) ;
break;
case V_317 :
if ( ! V_291 )
return - V_41 ;
F_83 ( V_140 , & V_14 -> V_123 ) ;
F_83 ( V_328 , & V_14 -> V_83 ) ;
V_14 -> V_296 = V_297 ;
V_14 -> V_329 = V_276 ;
break;
default:
if ( V_321 )
break;
V_98 = V_330 ;
* ( ( T_2 * ) V_274 ++ ) = type ;
break;
}
}
if ( V_14 -> V_301 || V_14 -> V_185 > 1 )
goto V_18;
switch ( V_14 -> V_86 ) {
case V_174 :
case V_87 :
if ( ! F_45 ( V_177 , & V_14 -> V_83 ) ) {
V_14 -> V_86 = F_186 ( V_300 . V_86 ,
V_14 -> V_3 -> V_168 ) ;
break;
}
if ( V_322 ) {
if ( F_188 ( V_14 ) )
F_83 ( V_302 , & V_14 -> V_123 ) ;
else
return - V_41 ;
}
if ( V_14 -> V_86 != V_300 . V_86 )
return - V_41 ;
break;
}
V_18:
if ( V_14 -> V_86 != V_300 . V_86 ) {
V_98 = V_331 ;
V_300 . V_86 = V_14 -> V_86 ;
if ( V_14 -> V_301 == 1 )
return - V_41 ;
F_180 ( & V_274 , V_310 ,
sizeof( V_300 ) , ( unsigned long ) & V_300 ) ;
}
if ( V_98 == V_323 ) {
if ( V_203 < V_332 )
V_98 = V_331 ;
else {
V_14 -> V_56 = V_203 ;
F_83 ( V_333 , & V_14 -> V_83 ) ;
}
F_180 ( & V_274 , V_304 , 2 , V_14 -> V_56 ) ;
if ( V_322 ) {
if ( V_14 -> V_65 != V_334 &&
V_281 . V_282 != V_334 &&
V_281 . V_282 != V_14 -> V_65 ) {
V_98 = V_331 ;
if ( V_14 -> V_185 >= 1 )
return - V_41 ;
F_180 ( & V_274 , V_287 ,
sizeof( V_281 ) ,
( unsigned long ) & V_281 ) ;
} else {
V_98 = V_335 ;
F_83 ( V_336 , & V_14 -> V_83 ) ;
}
}
switch ( V_300 . V_86 ) {
case V_208 :
V_14 -> V_143 = V_314 ;
F_83 ( V_337 , & V_14 -> V_83 ) ;
break;
case V_87 :
if ( ! F_45 ( V_328 , & V_14 -> V_83 ) )
V_14 -> V_329 = V_300 . V_305 ;
else
V_300 . V_305 = V_295 ;
V_14 -> V_223 = V_300 . V_306 ;
V_257 = F_70 ( T_1 , F_191 ( V_300 . V_309 ) ,
V_14 -> V_3 -> V_203 -
V_141 -
V_254 -
V_145 ) ;
V_300 . V_309 = F_16 ( V_257 ) ;
V_14 -> V_259 = V_257 ;
V_300 . V_307 =
F_191 ( V_338 ) ;
V_300 . V_308 =
F_191 ( V_339 ) ;
F_83 ( V_337 , & V_14 -> V_83 ) ;
F_180 ( & V_274 , V_310 ,
sizeof( V_300 ) , ( unsigned long ) & V_300 ) ;
if ( F_45 ( V_302 , & V_14 -> V_123 ) ) {
V_14 -> V_340 = V_281 . V_116 ;
V_14 -> V_341 = V_281 . V_282 ;
V_14 -> V_342 = F_191 ( V_281 . V_283 ) ;
V_14 -> V_343 =
F_192 ( V_281 . V_286 ) ;
V_14 -> V_344 =
F_192 ( V_281 . V_285 ) ;
V_14 -> V_345 =
F_192 ( V_281 . V_284 ) ;
F_180 ( & V_274 , V_287 ,
sizeof( V_281 ) , ( unsigned long ) & V_281 ) ;
}
break;
case V_174 :
V_257 = F_70 ( T_1 , F_191 ( V_300 . V_309 ) ,
V_14 -> V_3 -> V_203 -
V_141 -
V_254 -
V_145 ) ;
V_300 . V_309 = F_16 ( V_257 ) ;
V_14 -> V_259 = V_257 ;
F_83 ( V_337 , & V_14 -> V_83 ) ;
F_180 ( & V_274 , V_310 ,
sizeof( V_300 ) , ( unsigned long ) & V_300 ) ;
break;
default:
V_98 = V_331 ;
memset ( & V_300 , 0 , sizeof( V_300 ) ) ;
V_300 . V_86 = V_14 -> V_86 ;
}
if ( V_98 == V_323 )
F_83 ( V_82 , & V_14 -> V_83 ) ;
}
V_97 -> V_8 = F_16 ( V_14 -> V_7 ) ;
V_97 -> V_98 = F_16 ( V_98 ) ;
V_97 -> V_123 = F_16 ( 0x0000 ) ;
return V_274 - V_35 ;
}
static int F_193 ( struct V_1 * V_14 , void * V_97 , int V_120 , void * V_35 , T_1 * V_98 )
{
struct V_298 * V_160 = V_35 ;
void * V_274 = V_160 -> V_35 ;
int type , V_275 ;
unsigned long V_276 ;
struct V_299 V_300 = { . V_86 = V_208 } ;
struct V_280 V_281 ;
F_22 ( L_34 , V_14 , V_97 , V_120 , V_35 ) ;
while ( V_120 >= V_279 ) {
V_120 -= F_177 ( & V_97 , & type , & V_275 , & V_276 ) ;
switch ( type ) {
case V_304 :
if ( V_276 < V_332 ) {
* V_98 = V_331 ;
V_14 -> V_303 = V_332 ;
} else
V_14 -> V_303 = V_276 ;
F_180 ( & V_274 , V_304 , 2 , V_14 -> V_303 ) ;
break;
case V_326 :
V_14 -> V_286 = V_276 ;
F_180 ( & V_274 , V_326 ,
2 , V_14 -> V_286 ) ;
break;
case V_310 :
if ( V_275 == sizeof( V_300 ) )
memcpy ( & V_300 , ( void * ) V_276 , V_275 ) ;
if ( F_45 ( V_177 , & V_14 -> V_83 ) &&
V_300 . V_86 != V_14 -> V_86 )
return - V_41 ;
V_14 -> V_143 = 0 ;
F_180 ( & V_274 , V_310 ,
sizeof( V_300 ) , ( unsigned long ) & V_300 ) ;
break;
case V_317 :
V_14 -> V_294 = F_70 ( T_1 , V_276 ,
V_297 ) ;
F_180 ( & V_274 , V_317 , 2 ,
V_14 -> V_294 ) ;
break;
case V_287 :
if ( V_275 == sizeof( V_281 ) )
memcpy ( & V_281 , ( void * ) V_276 , V_275 ) ;
if ( V_14 -> V_65 != V_334 &&
V_281 . V_282 != V_334 &&
V_281 . V_282 != V_14 -> V_65 )
return - V_41 ;
F_180 ( & V_274 , V_287 ,
sizeof( V_281 ) , ( unsigned long ) & V_281 ) ;
break;
}
}
if ( V_14 -> V_86 == V_208 && V_14 -> V_86 != V_300 . V_86 )
return - V_41 ;
V_14 -> V_86 = V_300 . V_86 ;
if ( * V_98 == V_323 || * V_98 == V_335 ) {
switch ( V_300 . V_86 ) {
case V_87 :
V_14 -> V_307 = F_191 ( V_300 . V_307 ) ;
V_14 -> V_308 = F_191 ( V_300 . V_308 ) ;
V_14 -> V_346 = F_191 ( V_300 . V_309 ) ;
if ( F_45 ( V_302 , & V_14 -> V_123 ) ) {
V_14 -> V_67 = F_191 ( V_281 . V_283 ) ;
V_14 -> V_69 =
F_192 ( V_281 . V_284 ) ;
V_14 -> V_71 = F_192 ( V_281 . V_285 ) ;
V_14 -> V_73 =
F_192 ( V_281 . V_286 ) ;
}
break;
case V_174 :
V_14 -> V_346 = F_191 ( V_300 . V_309 ) ;
}
}
V_160 -> V_7 = F_16 ( V_14 -> V_7 ) ;
V_160 -> V_123 = F_16 ( 0x0000 ) ;
return V_274 - V_35 ;
}
static int F_194 ( struct V_1 * V_14 , void * V_35 , T_1 V_98 , T_1 V_123 )
{
struct V_318 * V_97 = V_35 ;
void * V_274 = V_97 -> V_35 ;
F_22 ( L_28 , V_14 ) ;
V_97 -> V_8 = F_16 ( V_14 -> V_7 ) ;
V_97 -> V_98 = F_16 ( V_98 ) ;
V_97 -> V_123 = F_16 ( V_123 ) ;
return V_274 - V_35 ;
}
void F_195 ( struct V_1 * V_14 )
{
struct V_96 V_97 ;
struct V_2 * V_3 = V_14 -> V_3 ;
T_2 V_178 [ 128 ] ;
V_97 . V_8 = F_16 ( V_14 -> V_7 ) ;
V_97 . V_7 = F_16 ( V_14 -> V_8 ) ;
V_97 . V_98 = F_16 ( V_181 ) ;
V_97 . V_102 = F_16 ( V_103 ) ;
F_57 ( V_3 , V_14 -> V_10 ,
V_104 , sizeof( V_97 ) , & V_97 ) ;
if ( F_196 ( V_183 , & V_14 -> V_83 ) )
return;
F_57 ( V_3 , F_61 ( V_3 ) , V_184 ,
F_93 ( V_14 , V_178 ) , V_178 ) ;
V_14 -> V_185 ++ ;
}
static void F_197 ( struct V_1 * V_14 , void * V_97 , int V_120 )
{
int type , V_275 ;
unsigned long V_276 ;
struct V_299 V_300 ;
F_22 ( L_35 , V_14 , V_97 , V_120 ) ;
if ( ( V_14 -> V_86 != V_87 ) && ( V_14 -> V_86 != V_174 ) )
return;
while ( V_120 >= V_279 ) {
V_120 -= F_177 ( & V_97 , & type , & V_275 , & V_276 ) ;
switch ( type ) {
case V_310 :
if ( V_275 == sizeof( V_300 ) )
memcpy ( & V_300 , ( void * ) V_276 , V_275 ) ;
goto V_18;
}
}
V_300 . V_86 = V_14 -> V_86 ;
V_300 . V_307 = F_16 ( V_338 ) ;
V_300 . V_308 = F_16 ( V_339 ) ;
V_300 . V_309 = F_16 ( V_14 -> V_303 ) ;
F_198 ( L_36 ) ;
V_18:
switch ( V_300 . V_86 ) {
case V_87 :
V_14 -> V_307 = F_191 ( V_300 . V_307 ) ;
V_14 -> V_308 = F_191 ( V_300 . V_308 ) ;
V_14 -> V_346 = F_191 ( V_300 . V_309 ) ;
break;
case V_174 :
V_14 -> V_346 = F_191 ( V_300 . V_309 ) ;
}
}
static inline int F_199 ( struct V_2 * V_3 , struct V_269 * V_270 , T_2 * V_35 )
{
struct V_347 * V_348 = (struct V_347 * ) V_35 ;
if ( V_348 -> V_40 != V_349 )
return 0 ;
if ( ( V_3 -> V_156 & V_157 ) &&
V_270 -> V_10 == V_3 -> V_164 ) {
F_200 ( & V_3 -> V_165 ) ;
V_3 -> V_156 |= V_158 ;
V_3 -> V_164 = 0 ;
F_90 ( V_3 ) ;
}
return 0 ;
}
static inline int F_201 ( struct V_2 * V_3 , struct V_269 * V_270 , T_2 * V_35 )
{
struct V_159 * V_160 = (struct V_159 * ) V_35 ;
struct V_96 V_97 ;
struct V_1 * V_14 = NULL , * V_188 ;
struct V_39 * V_77 , * V_9 = NULL ;
int V_98 , V_102 = V_103 ;
T_1 V_7 = 0 , V_8 = F_122 ( V_160 -> V_8 ) ;
T_3 V_11 = V_160 -> V_11 ;
F_22 ( L_37 , V_11 , V_8 ) ;
V_188 = F_117 ( V_27 , V_11 , V_3 -> V_12 ) ;
if ( ! V_188 ) {
V_98 = V_101 ;
goto V_350;
}
V_77 = V_188 -> V_9 ;
F_7 ( V_77 ) ;
if ( V_11 != F_16 ( 0x0001 ) &&
! F_202 ( V_3 -> V_54 ) ) {
V_3 -> V_50 = V_351 ;
V_98 = V_100 ;
goto V_352;
}
V_98 = V_353 ;
if ( F_98 ( V_77 ) ) {
F_22 ( L_23 , V_77 -> V_189 ) ;
goto V_352;
}
V_14 = V_188 -> V_33 -> V_191 ( V_188 -> V_35 ) ;
if ( ! V_14 )
goto V_352;
V_9 = V_14 -> V_9 ;
if ( F_1 ( V_3 , V_8 ) ) {
F_43 ( V_9 , V_78 ) ;
V_14 -> V_33 -> V_45 ( V_14 -> V_35 ) ;
goto V_352;
}
F_99 ( V_3 -> V_54 ) ;
F_100 ( & F_13 ( V_9 ) -> V_12 , V_3 -> V_12 ) ;
F_100 ( & F_13 ( V_9 ) -> V_192 , V_3 -> V_192 ) ;
V_14 -> V_11 = V_11 ;
V_14 -> V_7 = V_8 ;
F_101 ( V_77 , V_9 ) ;
F_35 ( V_3 , V_14 ) ;
V_7 = V_14 -> V_8 ;
F_55 ( V_14 , V_9 -> V_95 ) ;
V_14 -> V_10 = V_270 -> V_10 ;
if ( V_3 -> V_156 & V_158 ) {
if ( F_59 ( V_14 ) ) {
if ( F_13 ( V_9 ) -> V_99 ) {
F_21 ( V_14 , V_29 ) ;
V_98 = V_179 ;
V_102 = V_180 ;
V_77 -> V_80 ( V_77 , 0 ) ;
} else {
F_21 ( V_14 , V_30 ) ;
V_98 = V_181 ;
V_102 = V_103 ;
}
} else {
F_21 ( V_14 , V_29 ) ;
V_98 = V_179 ;
V_102 = V_182 ;
}
} else {
F_21 ( V_14 , V_29 ) ;
V_98 = V_179 ;
V_102 = V_103 ;
}
V_352:
F_26 ( V_77 ) ;
V_350:
V_97 . V_8 = F_16 ( V_8 ) ;
V_97 . V_7 = F_16 ( V_7 ) ;
V_97 . V_98 = F_16 ( V_98 ) ;
V_97 . V_102 = F_16 ( V_102 ) ;
F_57 ( V_3 , V_270 -> V_10 , V_104 , sizeof( V_97 ) , & V_97 ) ;
if ( V_98 == V_179 && V_102 == V_103 ) {
struct V_162 V_354 ;
V_354 . type = F_16 ( V_163 ) ;
V_3 -> V_156 |= V_157 ;
V_3 -> V_164 = F_61 ( V_3 ) ;
F_87 ( & V_3 -> V_165 ,
F_88 ( V_166 ) ) ;
F_57 ( V_3 , V_3 -> V_164 ,
V_167 , sizeof( V_354 ) , & V_354 ) ;
}
if ( V_14 && ! F_45 ( V_183 , & V_14 -> V_83 ) &&
V_98 == V_181 ) {
T_2 V_178 [ 128 ] ;
F_83 ( V_183 , & V_14 -> V_83 ) ;
F_57 ( V_3 , F_61 ( V_3 ) , V_184 ,
F_93 ( V_14 , V_178 ) , V_178 ) ;
V_14 -> V_185 ++ ;
}
return 0 ;
}
static inline int F_203 ( struct V_2 * V_3 , struct V_269 * V_270 , T_2 * V_35 )
{
struct V_96 * V_97 = (struct V_96 * ) V_35 ;
T_1 V_8 , V_7 , V_98 , V_102 ;
struct V_1 * V_14 ;
struct V_39 * V_9 ;
T_2 V_160 [ 128 ] ;
V_8 = F_122 ( V_97 -> V_8 ) ;
V_7 = F_122 ( V_97 -> V_7 ) ;
V_98 = F_122 ( V_97 -> V_98 ) ;
V_102 = F_122 ( V_97 -> V_102 ) ;
F_22 ( L_38 , V_7 , V_8 , V_98 , V_102 ) ;
if ( V_8 ) {
V_14 = F_6 ( V_3 , V_8 ) ;
if ( ! V_14 )
return - V_248 ;
} else {
V_14 = F_9 ( V_3 , V_270 -> V_10 ) ;
if ( ! V_14 )
return - V_248 ;
}
V_9 = V_14 -> V_9 ;
switch ( V_98 ) {
case V_181 :
F_21 ( V_14 , V_30 ) ;
V_14 -> V_10 = 0 ;
V_14 -> V_7 = V_7 ;
F_204 ( V_155 , & V_14 -> V_83 ) ;
if ( F_196 ( V_183 , & V_14 -> V_83 ) )
break;
F_57 ( V_3 , F_61 ( V_3 ) , V_184 ,
F_93 ( V_14 , V_160 ) , V_160 ) ;
V_14 -> V_185 ++ ;
break;
case V_179 :
F_83 ( V_155 , & V_14 -> V_83 ) ;
break;
default:
F_38 ( V_14 , V_41 ) ;
break;
}
F_26 ( V_9 ) ;
return 0 ;
}
static inline void F_205 ( struct V_1 * V_14 )
{
if ( V_14 -> V_86 != V_87 && V_14 -> V_86 != V_174 )
V_14 -> V_143 = V_314 ;
else if ( ! F_45 ( V_315 , & V_14 -> V_83 ) )
V_14 -> V_143 = V_144 ;
}
static inline int F_206 ( struct V_2 * V_3 , struct V_269 * V_270 , T_1 V_355 , T_2 * V_35 )
{
struct V_298 * V_160 = (struct V_298 * ) V_35 ;
T_1 V_7 , V_123 ;
T_2 V_97 [ 64 ] ;
struct V_1 * V_14 ;
struct V_39 * V_9 ;
int V_120 ;
V_7 = F_122 ( V_160 -> V_7 ) ;
V_123 = F_122 ( V_160 -> V_123 ) ;
F_22 ( L_39 , V_7 , V_123 ) ;
V_14 = F_6 ( V_3 , V_7 ) ;
if ( ! V_14 )
return - V_356 ;
V_9 = V_14 -> V_9 ;
if ( V_14 -> V_23 != V_30 && V_14 -> V_23 != V_29 ) {
struct V_357 V_348 ;
V_348 . V_40 = F_16 ( V_358 ) ;
V_348 . V_8 = F_16 ( V_14 -> V_8 ) ;
V_348 . V_7 = F_16 ( V_14 -> V_7 ) ;
F_57 ( V_3 , V_270 -> V_10 , V_359 ,
sizeof( V_348 ) , & V_348 ) ;
goto V_360;
}
V_120 = V_355 - sizeof( * V_160 ) ;
if ( V_120 < 0 || V_14 -> V_320 + V_120 > sizeof( V_14 -> V_319 ) ) {
F_57 ( V_3 , V_270 -> V_10 , V_361 ,
F_194 ( V_14 , V_97 ,
V_362 , V_123 ) , V_97 ) ;
goto V_360;
}
memcpy ( V_14 -> V_319 + V_14 -> V_320 , V_160 -> V_35 , V_120 ) ;
V_14 -> V_320 += V_120 ;
if ( V_123 & 0x0001 ) {
F_57 ( V_3 , V_270 -> V_10 , V_361 ,
F_194 ( V_14 , V_97 ,
V_323 , 0x0001 ) , V_97 ) ;
goto V_360;
}
V_120 = F_190 ( V_14 , V_97 ) ;
if ( V_120 < 0 ) {
F_56 ( V_3 , V_14 , V_92 ) ;
goto V_360;
}
F_57 ( V_3 , V_270 -> V_10 , V_361 , V_120 , V_97 ) ;
V_14 -> V_301 ++ ;
V_14 -> V_320 = 0 ;
if ( ! F_45 ( V_82 , & V_14 -> V_83 ) )
goto V_360;
if ( F_45 ( V_84 , & V_14 -> V_83 ) ) {
F_205 ( V_14 ) ;
F_21 ( V_14 , V_24 ) ;
V_14 -> V_230 = 0 ;
V_14 -> V_363 = 0 ;
F_171 ( & V_14 -> V_85 ) ;
if ( V_14 -> V_86 == V_87 )
F_185 ( V_14 ) ;
F_102 ( V_9 ) ;
goto V_360;
}
if ( ! F_196 ( V_183 , & V_14 -> V_83 ) ) {
T_2 V_178 [ 64 ] ;
F_57 ( V_3 , F_61 ( V_3 ) , V_184 ,
F_93 ( V_14 , V_178 ) , V_178 ) ;
V_14 -> V_185 ++ ;
}
if ( F_45 ( V_364 , & V_14 -> V_83 ) &&
F_45 ( V_336 , & V_14 -> V_83 ) ) {
F_204 ( V_336 , & V_14 -> V_83 ) ;
F_83 ( V_82 , & V_14 -> V_83 ) ;
F_57 ( V_3 , V_270 -> V_10 , V_361 ,
F_194 ( V_14 , V_97 ,
V_323 , 0x0000 ) , V_97 ) ;
}
V_360:
F_26 ( V_9 ) ;
return 0 ;
}
static inline int F_207 ( struct V_2 * V_3 , struct V_269 * V_270 , T_2 * V_35 )
{
struct V_318 * V_97 = (struct V_318 * ) V_35 ;
T_1 V_8 , V_123 , V_98 ;
struct V_1 * V_14 ;
struct V_39 * V_9 ;
int V_120 = V_270 -> V_120 - sizeof( * V_97 ) ;
V_8 = F_122 ( V_97 -> V_8 ) ;
V_123 = F_122 ( V_97 -> V_123 ) ;
V_98 = F_122 ( V_97 -> V_98 ) ;
F_22 ( L_40 ,
V_8 , V_123 , V_98 ) ;
V_14 = F_6 ( V_3 , V_8 ) ;
if ( ! V_14 )
return 0 ;
V_9 = V_14 -> V_9 ;
switch ( V_98 ) {
case V_323 :
F_197 ( V_14 , V_97 -> V_35 , V_120 ) ;
F_204 ( V_364 , & V_14 -> V_83 ) ;
break;
case V_335 :
F_83 ( V_364 , & V_14 -> V_83 ) ;
if ( F_45 ( V_336 , & V_14 -> V_83 ) ) {
char V_178 [ 64 ] ;
V_120 = F_193 ( V_14 , V_97 -> V_35 , V_120 ,
V_178 , & V_98 ) ;
if ( V_120 < 0 ) {
F_56 ( V_3 , V_14 , V_92 ) ;
goto V_18;
}
F_204 ( V_336 , & V_14 -> V_83 ) ;
F_83 ( V_82 , & V_14 -> V_83 ) ;
F_57 ( V_3 , V_270 -> V_10 , V_361 ,
F_194 ( V_14 , V_178 ,
V_323 , 0x0000 ) , V_178 ) ;
}
goto V_18;
case V_331 :
if ( V_14 -> V_301 <= V_365 ) {
char V_160 [ 64 ] ;
if ( V_120 > sizeof( V_160 ) - sizeof( struct V_298 ) ) {
F_56 ( V_3 , V_14 , V_92 ) ;
goto V_18;
}
V_98 = V_323 ;
V_120 = F_193 ( V_14 , V_97 -> V_35 , V_120 ,
V_160 , & V_98 ) ;
if ( V_120 < 0 ) {
F_56 ( V_3 , V_14 , V_92 ) ;
goto V_18;
}
F_57 ( V_3 , F_61 ( V_3 ) ,
V_184 , V_120 , V_160 ) ;
V_14 -> V_185 ++ ;
if ( V_98 != V_323 )
goto V_18;
break;
}
default:
V_9 -> V_79 = V_92 ;
F_55 ( V_14 ,
F_88 ( V_366 ) ) ;
F_56 ( V_3 , V_14 , V_92 ) ;
goto V_18;
}
if ( V_123 & 0x01 )
goto V_18;
F_83 ( V_84 , & V_14 -> V_83 ) ;
if ( F_45 ( V_82 , & V_14 -> V_83 ) ) {
F_205 ( V_14 ) ;
F_21 ( V_14 , V_24 ) ;
V_14 -> V_230 = 0 ;
V_14 -> V_363 = 0 ;
F_171 ( & V_14 -> V_85 ) ;
if ( V_14 -> V_86 == V_87 )
F_185 ( V_14 ) ;
F_102 ( V_9 ) ;
}
V_18:
F_26 ( V_9 ) ;
return 0 ;
}
static inline int F_208 ( struct V_2 * V_3 , struct V_269 * V_270 , T_2 * V_35 )
{
struct V_175 * V_160 = (struct V_175 * ) V_35 ;
struct V_367 V_97 ;
T_1 V_7 , V_8 ;
struct V_1 * V_14 ;
struct V_39 * V_9 ;
V_8 = F_122 ( V_160 -> V_8 ) ;
V_7 = F_122 ( V_160 -> V_7 ) ;
F_22 ( L_41 , V_8 , V_7 ) ;
V_14 = F_6 ( V_3 , V_7 ) ;
if ( ! V_14 )
return 0 ;
V_9 = V_14 -> V_9 ;
V_97 . V_7 = F_16 ( V_14 -> V_8 ) ;
V_97 . V_8 = F_16 ( V_14 -> V_7 ) ;
F_57 ( V_3 , V_270 -> V_10 , V_368 , sizeof( V_97 ) , & V_97 ) ;
V_9 -> V_369 = V_370 ;
F_38 ( V_14 , V_92 ) ;
F_26 ( V_9 ) ;
V_14 -> V_33 -> V_45 ( V_14 -> V_35 ) ;
return 0 ;
}
static inline int F_209 ( struct V_2 * V_3 , struct V_269 * V_270 , T_2 * V_35 )
{
struct V_367 * V_97 = (struct V_367 * ) V_35 ;
T_1 V_7 , V_8 ;
struct V_1 * V_14 ;
struct V_39 * V_9 ;
V_8 = F_122 ( V_97 -> V_8 ) ;
V_7 = F_122 ( V_97 -> V_7 ) ;
F_22 ( L_42 , V_7 , V_8 ) ;
V_14 = F_6 ( V_3 , V_8 ) ;
if ( ! V_14 )
return 0 ;
V_9 = V_14 -> V_9 ;
F_38 ( V_14 , 0 ) ;
F_26 ( V_9 ) ;
V_14 -> V_33 -> V_45 ( V_14 -> V_35 ) ;
return 0 ;
}
static inline int F_210 ( struct V_2 * V_3 , struct V_269 * V_270 , T_2 * V_35 )
{
struct V_162 * V_160 = (struct V_162 * ) V_35 ;
T_1 type ;
type = F_122 ( V_160 -> type ) ;
F_22 ( L_43 , type ) ;
if ( type == V_163 ) {
T_2 V_178 [ 8 ] ;
T_7 V_168 = V_170 ;
struct V_371 * V_97 = (struct V_371 * ) V_178 ;
V_97 -> type = F_16 ( V_163 ) ;
V_97 -> V_98 = F_16 ( V_372 ) ;
if ( ! V_171 )
V_168 |= V_172 | V_173
| V_313 ;
if ( V_291 )
V_168 |= V_293
| V_292 ;
F_181 ( V_168 , V_97 -> V_35 ) ;
F_57 ( V_3 , V_270 -> V_10 ,
V_373 , sizeof( V_178 ) , V_178 ) ;
} else if ( type == V_374 ) {
T_2 V_178 [ 12 ] ;
struct V_371 * V_97 = (struct V_371 * ) V_178 ;
if ( V_291 )
V_375 [ 0 ] |= V_376 ;
else
V_375 [ 0 ] &= ~ V_376 ;
V_97 -> type = F_16 ( V_374 ) ;
V_97 -> V_98 = F_16 ( V_372 ) ;
memcpy ( V_97 -> V_35 , V_375 , sizeof( V_375 ) ) ;
F_57 ( V_3 , V_270 -> V_10 ,
V_373 , sizeof( V_178 ) , V_178 ) ;
} else {
struct V_371 V_97 ;
V_97 . type = F_16 ( type ) ;
V_97 . V_98 = F_16 ( V_377 ) ;
F_57 ( V_3 , V_270 -> V_10 ,
V_373 , sizeof( V_97 ) , & V_97 ) ;
}
return 0 ;
}
static inline int F_211 ( struct V_2 * V_3 , struct V_269 * V_270 , T_2 * V_35 )
{
struct V_371 * V_97 = (struct V_371 * ) V_35 ;
T_1 type , V_98 ;
type = F_122 ( V_97 -> type ) ;
V_98 = F_122 ( V_97 -> V_98 ) ;
F_22 ( L_44 , type , V_98 ) ;
if ( V_270 -> V_10 != V_3 -> V_164 ||
V_3 -> V_156 & V_158 )
return 0 ;
F_200 ( & V_3 -> V_165 ) ;
if ( V_98 != V_372 ) {
V_3 -> V_156 |= V_158 ;
V_3 -> V_164 = 0 ;
F_90 ( V_3 ) ;
return 0 ;
}
if ( type == V_163 ) {
V_3 -> V_168 = F_179 ( V_97 -> V_35 ) ;
if ( V_3 -> V_168 & V_378 ) {
struct V_162 V_160 ;
V_160 . type = F_16 ( V_374 ) ;
V_3 -> V_164 = F_61 ( V_3 ) ;
F_57 ( V_3 , V_3 -> V_164 ,
V_167 , sizeof( V_160 ) , & V_160 ) ;
} else {
V_3 -> V_156 |= V_158 ;
V_3 -> V_164 = 0 ;
F_90 ( V_3 ) ;
}
} else if ( type == V_374 ) {
V_3 -> V_156 |= V_158 ;
V_3 -> V_164 = 0 ;
F_90 ( V_3 ) ;
}
return 0 ;
}
static inline int F_212 ( struct V_2 * V_3 ,
struct V_269 * V_270 , T_1 V_355 ,
void * V_35 )
{
struct V_379 * V_160 = V_35 ;
struct V_380 V_97 ;
T_1 V_11 , V_8 ;
if ( V_355 != sizeof( * V_160 ) )
return - V_381 ;
if ( ! V_291 )
return - V_20 ;
V_11 = F_191 ( V_160 -> V_11 ) ;
V_8 = F_191 ( V_160 -> V_8 ) ;
F_22 ( L_45 , V_11 , V_8 , V_160 -> V_382 ) ;
V_97 . V_7 = 0 ;
V_97 . V_8 = F_16 ( V_8 ) ;
V_97 . V_98 = V_353 ;
V_97 . V_102 = V_103 ;
F_57 ( V_3 , V_270 -> V_10 , V_383 ,
sizeof( V_97 ) , & V_97 ) ;
return 0 ;
}
static inline int F_213 ( struct V_2 * V_3 ,
struct V_269 * V_270 , void * V_35 )
{
F_22 ( L_21 , V_3 ) ;
return F_203 ( V_3 , V_270 , V_35 ) ;
}
static void F_214 ( struct V_2 * V_3 , T_2 V_10 ,
T_1 V_384 , T_1 V_98 )
{
struct V_385 V_97 ;
F_22 ( L_46 , V_384 , V_98 ) ;
V_97 . V_384 = F_16 ( V_384 ) ;
V_97 . V_98 = F_16 ( V_98 ) ;
F_57 ( V_3 , V_10 , V_386 , sizeof( V_97 ) , & V_97 ) ;
}
static void F_215 ( struct V_2 * V_3 ,
struct V_1 * V_14 , T_1 V_384 , T_1 V_98 )
{
struct V_387 V_388 ;
T_2 V_10 ;
F_22 ( L_46 , V_384 , V_98 ) ;
V_10 = F_61 ( V_3 ) ;
if ( V_14 )
V_14 -> V_10 = V_10 ;
V_388 . V_384 = F_16 ( V_384 ) ;
V_388 . V_98 = F_16 ( V_98 ) ;
F_57 ( V_3 , V_10 , V_389 , sizeof( V_388 ) , & V_388 ) ;
}
static void F_216 ( struct V_2 * V_3 , T_2 V_10 ,
T_1 V_384 )
{
struct V_390 V_97 ;
F_22 ( L_47 , V_384 ) ;
V_97 . V_384 = F_16 ( V_384 ) ;
F_57 ( V_3 , V_10 , V_391 , sizeof( V_97 ) , & V_97 ) ;
}
static inline int F_217 ( struct V_2 * V_3 ,
struct V_269 * V_270 , T_1 V_355 , void * V_35 )
{
struct V_392 * V_160 = V_35 ;
T_1 V_384 = 0 ;
T_1 V_98 = V_393 ;
if ( V_355 != sizeof( * V_160 ) )
return - V_381 ;
V_384 = F_191 ( V_160 -> V_384 ) ;
F_22 ( L_48 , V_384 , V_160 -> V_394 ) ;
if ( ! V_291 )
return - V_20 ;
F_214 ( V_3 , V_270 -> V_10 , V_384 , V_98 ) ;
return 0 ;
}
static inline int F_218 ( struct V_2 * V_3 ,
struct V_269 * V_270 , T_1 V_355 , void * V_35 )
{
struct V_385 * V_97 = V_35 ;
T_1 V_384 , V_98 ;
if ( V_355 != sizeof( * V_97 ) )
return - V_381 ;
V_384 = F_191 ( V_97 -> V_384 ) ;
V_98 = F_191 ( V_97 -> V_98 ) ;
F_22 ( L_46 , V_384 , V_98 ) ;
F_215 ( V_3 , NULL , V_384 , V_395 ) ;
return 0 ;
}
static inline int F_219 ( struct V_2 * V_3 ,
struct V_269 * V_270 , T_1 V_355 , void * V_35 )
{
struct V_387 * V_388 = V_35 ;
T_1 V_384 , V_98 ;
if ( V_355 != sizeof( * V_388 ) )
return - V_381 ;
V_384 = F_191 ( V_388 -> V_384 ) ;
V_98 = F_191 ( V_388 -> V_98 ) ;
F_22 ( L_46 , V_384 , V_98 ) ;
F_216 ( V_3 , V_270 -> V_10 , V_384 ) ;
return 0 ;
}
static inline int F_220 ( struct V_2 * V_3 ,
struct V_269 * V_270 , T_1 V_355 , void * V_35 )
{
struct V_390 * V_97 = V_35 ;
T_1 V_384 ;
if ( V_355 != sizeof( * V_97 ) )
return - V_381 ;
V_384 = F_191 ( V_97 -> V_384 ) ;
F_22 ( L_47 , V_384 ) ;
return 0 ;
}
static inline int F_221 ( T_1 V_396 , T_1 V_397 , T_1 V_398 ,
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
static inline int F_222 ( struct V_2 * V_3 ,
struct V_269 * V_270 , T_2 * V_35 )
{
struct V_132 * V_54 = V_3 -> V_54 ;
struct F_222 * V_160 ;
struct V_401 V_97 ;
T_1 V_396 , V_397 , V_398 , V_399 , V_355 ;
int V_15 ;
if ( ! ( V_54 -> V_402 & V_403 ) )
return - V_20 ;
V_355 = F_122 ( V_270 -> V_120 ) ;
if ( V_355 != sizeof( struct F_222 ) )
return - V_381 ;
V_160 = (struct F_222 * ) V_35 ;
V_396 = F_122 ( V_160 -> V_396 ) ;
V_397 = F_122 ( V_160 -> V_397 ) ;
V_398 = F_122 ( V_160 -> V_398 ) ;
V_399 = F_122 ( V_160 -> V_399 ) ;
F_22 ( L_49 ,
V_396 , V_397 , V_398 , V_399 ) ;
memset ( & V_97 , 0 , sizeof( V_97 ) ) ;
V_15 = F_221 ( V_396 , V_397 , V_398 , V_399 ) ;
if ( V_15 )
V_97 . V_98 = F_16 ( V_404 ) ;
else
V_97 . V_98 = F_16 ( V_405 ) ;
F_57 ( V_3 , V_270 -> V_10 , V_406 ,
sizeof( V_97 ) , & V_97 ) ;
if ( ! V_15 )
F_223 ( V_54 , V_396 , V_397 , V_398 , V_399 ) ;
return 0 ;
}
static inline int F_224 ( struct V_2 * V_3 ,
struct V_269 * V_270 , T_1 V_355 , T_2 * V_35 )
{
int V_15 = 0 ;
switch ( V_270 -> V_119 ) {
case V_359 :
F_199 ( V_3 , V_270 , V_35 ) ;
break;
case V_161 :
V_15 = F_201 ( V_3 , V_270 , V_35 ) ;
break;
case V_104 :
V_15 = F_203 ( V_3 , V_270 , V_35 ) ;
break;
case V_184 :
V_15 = F_206 ( V_3 , V_270 , V_355 , V_35 ) ;
break;
case V_361 :
V_15 = F_207 ( V_3 , V_270 , V_35 ) ;
break;
case V_176 :
V_15 = F_208 ( V_3 , V_270 , V_35 ) ;
break;
case V_368 :
V_15 = F_209 ( V_3 , V_270 , V_35 ) ;
break;
case V_407 :
F_57 ( V_3 , V_270 -> V_10 , V_408 , V_355 , V_35 ) ;
break;
case V_408 :
break;
case V_167 :
V_15 = F_210 ( V_3 , V_270 , V_35 ) ;
break;
case V_373 :
V_15 = F_211 ( V_3 , V_270 , V_35 ) ;
break;
case V_409 :
V_15 = F_212 ( V_3 , V_270 , V_355 , V_35 ) ;
break;
case V_383 :
V_15 = F_213 ( V_3 , V_270 , V_35 ) ;
break;
case V_410 :
V_15 = F_217 ( V_3 , V_270 , V_355 , V_35 ) ;
break;
case V_386 :
V_15 = F_218 ( V_3 , V_270 , V_355 , V_35 ) ;
break;
case V_389 :
V_15 = F_219 ( V_3 , V_270 , V_355 , V_35 ) ;
break;
case V_391 :
V_15 = F_220 ( V_3 , V_270 , V_355 , V_35 ) ;
break;
default:
F_198 ( L_50 , V_270 -> V_119 ) ;
V_15 = - V_20 ;
break;
}
return V_15 ;
}
static inline int F_225 ( struct V_2 * V_3 ,
struct V_269 * V_270 , T_2 * V_35 )
{
switch ( V_270 -> V_119 ) {
case V_359 :
return 0 ;
case V_411 :
return F_222 ( V_3 , V_270 , V_35 ) ;
case V_406 :
return 0 ;
default:
F_198 ( L_51 , V_270 -> V_119 ) ;
return - V_20 ;
}
}
static inline void F_226 ( struct V_2 * V_3 ,
struct V_121 * V_122 )
{
T_2 * V_35 = V_122 -> V_35 ;
int V_120 = V_122 -> V_120 ;
struct V_269 V_270 ;
int V_15 ;
F_176 ( V_3 , V_122 ) ;
while ( V_120 >= V_271 ) {
T_1 V_355 ;
memcpy ( & V_270 , V_35 , V_271 ) ;
V_35 += V_271 ;
V_120 -= V_271 ;
V_355 = F_191 ( V_270 . V_120 ) ;
F_22 ( L_52 , V_270 . V_119 , V_355 , V_270 . V_10 ) ;
if ( V_355 > V_120 || ! V_270 . V_10 ) {
F_22 ( L_53 ) ;
break;
}
if ( V_3 -> V_54 -> type == V_55 )
V_15 = F_225 ( V_3 , & V_270 , V_35 ) ;
else
V_15 = F_224 ( V_3 , & V_270 , V_355 , V_35 ) ;
if ( V_15 ) {
struct V_347 V_348 ;
F_198 ( L_54 , V_15 ) ;
V_348 . V_40 = F_16 ( V_349 ) ;
F_57 ( V_3 , V_270 . V_10 , V_359 , sizeof( V_348 ) , & V_348 ) ;
}
V_35 += V_355 ;
V_120 -= V_355 ;
}
F_108 ( V_122 ) ;
}
static int F_227 ( struct V_1 * V_14 , struct V_121 * V_122 )
{
T_1 V_412 , V_413 ;
int V_414 ;
if ( F_45 ( V_140 , & V_14 -> V_123 ) )
V_414 = V_141 ;
else
V_414 = V_142 ;
if ( V_14 -> V_143 == V_144 ) {
F_228 ( V_122 , V_122 -> V_120 - V_145 ) ;
V_413 = F_178 ( V_122 -> V_35 + V_122 -> V_120 ) ;
V_412 = F_79 ( 0 , V_122 -> V_35 - V_414 , V_122 -> V_120 + V_414 ) ;
if ( V_412 != V_413 )
return - V_415 ;
}
return 0 ;
}
static inline void F_229 ( struct V_1 * V_14 )
{
T_7 V_135 = 0 ;
V_14 -> V_236 = 0 ;
V_135 |= F_84 ( V_14 , V_14 -> V_154 ) ;
if ( F_45 ( V_150 , & V_14 -> V_147 ) ) {
V_135 |= F_82 ( V_14 , V_151 ) ;
F_69 ( V_14 , V_135 ) ;
F_83 ( V_152 , & V_14 -> V_147 ) ;
}
if ( F_45 ( V_265 , & V_14 -> V_147 ) )
F_156 ( V_14 ) ;
F_153 ( V_14 ) ;
if ( ! F_45 ( V_150 , & V_14 -> V_147 ) &&
V_14 -> V_236 == 0 ) {
V_135 |= F_82 ( V_14 , V_153 ) ;
F_69 ( V_14 , V_135 ) ;
}
}
static int F_230 ( struct V_1 * V_14 , struct V_121 * V_122 , T_1 V_228 , T_2 V_416 )
{
struct V_121 * V_417 ;
int V_418 , V_419 ;
F_66 ( V_122 ) -> V_228 = V_228 ;
F_66 ( V_122 ) -> V_416 = V_416 ;
V_417 = F_142 ( & V_14 -> V_91 ) ;
V_418 = F_231 ( V_14 , V_228 , V_14 -> V_154 ) ;
while ( V_417 ) {
if ( F_66 ( V_417 ) -> V_228 == V_228 )
return - V_20 ;
V_419 = F_231 ( V_14 ,
F_66 ( V_417 ) -> V_228 , V_14 -> V_154 ) ;
if ( V_419 > V_418 ) {
F_232 ( & V_14 -> V_91 , V_417 , V_122 ) ;
return 0 ;
}
if ( F_149 ( & V_14 -> V_91 , V_417 ) )
V_417 = NULL ;
else
V_417 = F_150 ( & V_14 -> V_91 , V_417 ) ;
}
F_173 ( & V_14 -> V_91 , V_122 ) ;
return 0 ;
}
static void F_233 ( struct V_121 * V_122 ,
struct V_121 * V_420 , struct V_121 * * V_421 )
{
if ( ! F_234 ( V_122 ) )
F_163 ( V_122 ) -> V_249 = V_420 ;
V_420 -> V_238 = NULL ;
( * V_421 ) -> V_238 = V_420 ;
* V_421 = V_420 ;
V_122 -> V_120 += V_420 -> V_120 ;
V_122 -> V_422 += V_420 -> V_120 ;
V_122 -> V_423 += V_420 -> V_423 ;
}
static int F_235 ( struct V_1 * V_14 , struct V_121 * V_122 , T_7 V_135 )
{
int V_15 = - V_20 ;
switch ( F_236 ( V_14 , V_135 ) ) {
case V_264 :
if ( V_14 -> V_424 )
break;
V_15 = V_14 -> V_33 -> V_267 ( V_14 -> V_35 , V_122 ) ;
break;
case V_258 :
if ( V_14 -> V_424 )
break;
V_14 -> V_425 = F_178 ( V_122 -> V_35 ) ;
F_237 ( V_122 , V_254 ) ;
if ( V_14 -> V_425 > V_14 -> V_303 ) {
V_15 = - V_263 ;
break;
}
if ( V_122 -> V_120 >= V_14 -> V_425 )
break;
V_14 -> V_424 = V_122 ;
V_14 -> V_426 = V_122 ;
V_122 = NULL ;
V_15 = 0 ;
break;
case V_261 :
if ( ! V_14 -> V_424 )
break;
F_233 ( V_14 -> V_424 , V_122 ,
& V_14 -> V_426 ) ;
V_122 = NULL ;
if ( V_14 -> V_424 -> V_120 >= V_14 -> V_425 )
break;
V_15 = 0 ;
break;
case V_262 :
if ( ! V_14 -> V_424 )
break;
F_233 ( V_14 -> V_424 , V_122 ,
& V_14 -> V_426 ) ;
V_122 = NULL ;
if ( V_14 -> V_424 -> V_120 != V_14 -> V_425 )
break;
V_15 = V_14 -> V_33 -> V_267 ( V_14 -> V_35 , V_14 -> V_424 ) ;
if ( ! V_15 ) {
V_14 -> V_424 = NULL ;
V_14 -> V_426 = NULL ;
V_14 -> V_425 = 0 ;
}
break;
}
if ( V_15 ) {
F_108 ( V_122 ) ;
F_108 ( V_14 -> V_424 ) ;
V_14 -> V_424 = NULL ;
V_14 -> V_426 = NULL ;
V_14 -> V_425 = 0 ;
}
return V_15 ;
}
static void F_238 ( struct V_1 * V_14 )
{
T_7 V_135 ;
F_22 ( L_55 , V_14 ) ;
F_83 ( V_150 , & V_14 -> V_147 ) ;
V_135 = F_84 ( V_14 , V_14 -> V_154 ) ;
V_135 |= F_82 ( V_14 , V_151 ) ;
F_69 ( V_14 , V_135 ) ;
F_83 ( V_152 , & V_14 -> V_147 ) ;
F_49 ( V_14 ) ;
}
static void F_239 ( struct V_1 * V_14 )
{
T_7 V_135 ;
if ( ! F_45 ( V_152 , & V_14 -> V_147 ) )
goto V_18;
V_135 = F_84 ( V_14 , V_14 -> V_154 ) ;
V_135 |= F_74 ( V_14 ) ;
V_135 |= F_82 ( V_14 , V_153 ) ;
F_69 ( V_14 , V_135 ) ;
V_14 -> V_222 = 1 ;
F_47 ( V_14 ) ;
F_139 ( V_14 ) ;
F_83 ( V_227 , & V_14 -> V_147 ) ;
V_18:
F_204 ( V_150 , & V_14 -> V_147 ) ;
F_204 ( V_152 , & V_14 -> V_147 ) ;
F_22 ( L_56 , V_14 ) ;
}
void F_240 ( struct V_1 * V_14 , int V_427 )
{
if ( V_14 -> V_86 == V_87 ) {
if ( V_427 )
F_238 ( V_14 ) ;
else
F_239 ( V_14 ) ;
}
}
static void F_241 ( struct V_1 * V_14 , T_1 V_228 )
{
struct V_121 * V_122 ;
T_7 V_135 ;
while ( ( V_122 = F_142 ( & V_14 -> V_91 ) ) &&
! F_45 ( V_150 , & V_14 -> V_147 ) ) {
int V_15 ;
if ( F_66 ( V_122 ) -> V_228 != V_228 )
break;
V_122 = F_143 ( & V_14 -> V_91 ) ;
V_135 = F_172 ( V_14 , F_66 ( V_122 ) -> V_416 ) ;
V_15 = F_235 ( V_14 , V_122 , V_135 ) ;
if ( V_15 < 0 ) {
F_56 ( V_14 -> V_3 , V_14 , V_92 ) ;
break;
}
V_14 -> V_428 = F_147 ( V_14 , V_14 -> V_428 ) ;
V_228 = F_147 ( V_14 , V_228 ) ;
}
}
static void F_242 ( struct V_1 * V_14 , T_1 V_228 )
{
struct V_88 * V_89 , * V_90 ;
T_7 V_135 ;
F_50 (l, tmp, &chan->srej_l, list) {
if ( V_89 -> V_228 == V_228 ) {
F_34 ( & V_89 -> V_75 ) ;
F_51 ( V_89 ) ;
return;
}
V_135 = F_82 ( V_14 , V_240 ) ;
V_135 |= F_84 ( V_14 , V_89 -> V_228 ) ;
F_69 ( V_14 , V_135 ) ;
F_34 ( & V_89 -> V_75 ) ;
F_243 ( & V_89 -> V_75 , & V_14 -> V_241 ) ;
}
}
static int F_244 ( struct V_1 * V_14 , T_1 V_228 )
{
struct V_88 * V_429 ;
T_7 V_135 ;
while ( V_228 != V_14 -> V_363 ) {
V_135 = F_82 ( V_14 , V_240 ) ;
V_135 |= F_84 ( V_14 , V_14 -> V_363 ) ;
F_69 ( V_14 , V_135 ) ;
V_429 = F_29 ( sizeof( struct V_88 ) , V_46 ) ;
if ( ! V_429 )
return - V_213 ;
V_429 -> V_228 = V_14 -> V_363 ;
V_14 -> V_363 = F_147 ( V_14 , V_14 -> V_363 ) ;
F_243 ( & V_429 -> V_75 , & V_14 -> V_241 ) ;
}
V_14 -> V_363 = F_147 ( V_14 , V_14 -> V_363 ) ;
return 0 ;
}
static inline int F_245 ( struct V_1 * V_14 , T_7 V_430 , struct V_121 * V_122 )
{
T_1 V_228 = F_246 ( V_14 , V_430 ) ;
T_1 V_431 = F_247 ( V_14 , V_430 ) ;
T_2 V_416 = F_236 ( V_14 , V_430 ) ;
int V_418 , V_432 ;
int V_433 = ( V_14 -> V_294 / 6 ) + 1 ;
int V_15 = 0 ;
F_22 ( L_57 , V_14 , V_122 -> V_120 ,
V_228 , V_430 ) ;
if ( F_248 ( V_14 , V_430 ) &&
F_45 ( V_227 , & V_14 -> V_147 ) ) {
F_48 ( V_14 ) ;
if ( V_14 -> V_219 > 0 )
F_155 ( V_14 ) ;
F_204 ( V_227 , & V_14 -> V_147 ) ;
}
V_14 -> V_229 = V_431 ;
F_141 ( V_14 ) ;
V_418 = F_231 ( V_14 , V_228 , V_14 -> V_154 ) ;
if ( V_418 >= V_14 -> V_294 ) {
F_56 ( V_14 -> V_3 , V_14 , V_92 ) ;
goto V_434;
}
if ( F_45 ( V_150 , & V_14 -> V_147 ) )
goto V_434;
if ( V_228 == V_14 -> V_363 )
goto V_435;
if ( F_45 ( V_436 , & V_14 -> V_147 ) ) {
struct V_88 * V_437 ;
V_437 = F_249 ( & V_14 -> V_241 ,
struct V_88 , V_75 ) ;
if ( V_228 == V_437 -> V_228 ) {
F_230 ( V_14 , V_122 , V_228 , V_416 ) ;
F_241 ( V_14 , V_228 ) ;
F_34 ( & V_437 -> V_75 ) ;
F_51 ( V_437 ) ;
if ( F_250 ( & V_14 -> V_241 ) ) {
V_14 -> V_154 = V_14 -> V_428 ;
F_204 ( V_436 , & V_14 -> V_147 ) ;
F_158 ( V_14 ) ;
F_22 ( L_58 , V_14 ) ;
}
} else {
struct V_88 * V_89 ;
if ( F_230 ( V_14 , V_122 , V_228 , V_416 ) < 0 )
goto V_434;
F_11 (l, &chan->srej_l, list) {
if ( V_89 -> V_228 == V_228 ) {
F_242 ( V_14 , V_228 ) ;
return 0 ;
}
}
V_15 = F_244 ( V_14 , V_228 ) ;
if ( V_15 < 0 ) {
F_56 ( V_14 -> V_3 , V_14 , - V_15 ) ;
return V_15 ;
}
}
} else {
V_432 = F_231 ( V_14 ,
V_14 -> V_363 , V_14 -> V_154 ) ;
if ( V_418 < V_432 )
goto V_434;
F_83 ( V_436 , & V_14 -> V_147 ) ;
F_22 ( L_59 , V_14 ) ;
F_116 ( & V_14 -> V_241 ) ;
V_14 -> V_428 = V_14 -> V_154 ;
F_251 ( & V_14 -> V_91 ) ;
F_230 ( V_14 , V_122 , V_228 , V_416 ) ;
F_83 ( V_148 , & V_14 -> V_147 ) ;
V_15 = F_244 ( V_14 , V_228 ) ;
if ( V_15 < 0 ) {
F_56 ( V_14 -> V_3 , V_14 , - V_15 ) ;
return V_15 ;
}
F_49 ( V_14 ) ;
}
return 0 ;
V_435:
V_14 -> V_363 = F_147 ( V_14 , V_14 -> V_363 ) ;
if ( F_45 ( V_436 , & V_14 -> V_147 ) ) {
F_66 ( V_122 ) -> V_228 = V_228 ;
F_66 ( V_122 ) -> V_416 = V_416 ;
F_173 ( & V_14 -> V_91 , V_122 ) ;
return 0 ;
}
V_15 = F_235 ( V_14 , V_122 , V_430 ) ;
V_14 -> V_154 = F_147 ( V_14 , V_14 -> V_154 ) ;
if ( V_15 < 0 ) {
F_56 ( V_14 -> V_3 , V_14 , V_92 ) ;
return V_15 ;
}
if ( F_248 ( V_14 , V_430 ) ) {
if ( ! F_72 ( V_438 , & V_14 -> V_147 ) )
F_156 ( V_14 ) ;
}
V_14 -> V_289 = ( V_14 -> V_289 + 1 ) % V_433 ;
if ( V_14 -> V_289 == V_433 - 1 )
F_158 ( V_14 ) ;
else
F_252 ( V_14 ) ;
return 0 ;
V_434:
F_108 ( V_122 ) ;
return 0 ;
}
static inline void F_253 ( struct V_1 * V_14 , T_7 V_430 )
{
F_22 ( L_60 , V_14 ,
F_247 ( V_14 , V_430 ) , V_430 ) ;
V_14 -> V_229 = F_247 ( V_14 , V_430 ) ;
F_141 ( V_14 ) ;
if ( F_254 ( V_14 , V_430 ) ) {
F_83 ( V_146 , & V_14 -> V_147 ) ;
if ( F_45 ( V_436 , & V_14 -> V_147 ) ) {
if ( F_45 ( V_265 , & V_14 -> V_147 ) &&
( V_14 -> V_219 > 0 ) )
F_155 ( V_14 ) ;
F_204 ( V_265 , & V_14 -> V_147 ) ;
F_159 ( V_14 ) ;
} else {
F_229 ( V_14 ) ;
}
} else if ( F_248 ( V_14 , V_430 ) ) {
F_204 ( V_265 , & V_14 -> V_147 ) ;
if ( ! F_72 ( V_438 , & V_14 -> V_147 ) )
F_156 ( V_14 ) ;
} else {
if ( F_45 ( V_265 , & V_14 -> V_147 ) &&
( V_14 -> V_219 > 0 ) )
F_155 ( V_14 ) ;
F_204 ( V_265 , & V_14 -> V_147 ) ;
if ( F_45 ( V_436 , & V_14 -> V_147 ) )
F_158 ( V_14 ) ;
else
F_153 ( V_14 ) ;
}
}
static inline void F_255 ( struct V_1 * V_14 , T_7 V_430 )
{
T_1 V_228 = F_247 ( V_14 , V_430 ) ;
F_22 ( L_60 , V_14 , V_228 , V_430 ) ;
F_204 ( V_265 , & V_14 -> V_147 ) ;
V_14 -> V_229 = V_228 ;
F_141 ( V_14 ) ;
if ( F_248 ( V_14 , V_430 ) ) {
if ( ! F_72 ( V_438 , & V_14 -> V_147 ) )
F_156 ( V_14 ) ;
} else {
F_156 ( V_14 ) ;
if ( F_45 ( V_227 , & V_14 -> V_147 ) )
F_83 ( V_438 , & V_14 -> V_147 ) ;
}
}
static inline void F_256 ( struct V_1 * V_14 , T_7 V_430 )
{
T_1 V_228 = F_247 ( V_14 , V_430 ) ;
F_22 ( L_60 , V_14 , V_228 , V_430 ) ;
F_204 ( V_265 , & V_14 -> V_147 ) ;
if ( F_254 ( V_14 , V_430 ) ) {
V_14 -> V_229 = V_228 ;
F_141 ( V_14 ) ;
F_83 ( V_146 , & V_14 -> V_147 ) ;
F_148 ( V_14 , V_228 ) ;
F_153 ( V_14 ) ;
if ( F_45 ( V_227 , & V_14 -> V_147 ) ) {
V_14 -> V_439 = V_228 ;
F_83 ( V_440 , & V_14 -> V_147 ) ;
}
} else if ( F_248 ( V_14 , V_430 ) ) {
if ( F_45 ( V_440 , & V_14 -> V_147 ) &&
V_14 -> V_439 == V_228 )
F_204 ( V_440 , & V_14 -> V_147 ) ;
else
F_148 ( V_14 , V_228 ) ;
} else {
F_148 ( V_14 , V_228 ) ;
if ( F_45 ( V_227 , & V_14 -> V_147 ) ) {
V_14 -> V_439 = V_228 ;
F_83 ( V_440 , & V_14 -> V_147 ) ;
}
}
}
static inline void F_257 ( struct V_1 * V_14 , T_7 V_430 )
{
T_1 V_228 = F_247 ( V_14 , V_430 ) ;
F_22 ( L_60 , V_14 , V_228 , V_430 ) ;
F_83 ( V_265 , & V_14 -> V_147 ) ;
V_14 -> V_229 = V_228 ;
F_141 ( V_14 ) ;
if ( F_254 ( V_14 , V_430 ) )
F_83 ( V_146 , & V_14 -> V_147 ) ;
if ( ! F_45 ( V_436 , & V_14 -> V_147 ) ) {
F_47 ( V_14 ) ;
if ( F_254 ( V_14 , V_430 ) )
F_81 ( V_14 , V_441 ) ;
return;
}
if ( F_254 ( V_14 , V_430 ) ) {
F_159 ( V_14 ) ;
} else {
V_430 = F_82 ( V_14 , V_153 ) ;
F_69 ( V_14 , V_430 ) ;
}
}
static inline int F_258 ( struct V_1 * V_14 , T_7 V_430 , struct V_121 * V_122 )
{
F_22 ( L_61 , V_14 , V_430 , V_122 -> V_120 ) ;
if ( F_248 ( V_14 , V_430 ) &&
F_45 ( V_227 , & V_14 -> V_147 ) ) {
F_48 ( V_14 ) ;
if ( V_14 -> V_219 > 0 )
F_155 ( V_14 ) ;
F_204 ( V_227 , & V_14 -> V_147 ) ;
}
switch ( F_259 ( V_14 , V_430 ) ) {
case V_153 :
F_253 ( V_14 , V_430 ) ;
break;
case V_442 :
F_255 ( V_14 , V_430 ) ;
break;
case V_240 :
F_256 ( V_14 , V_430 ) ;
break;
case V_151 :
F_257 ( V_14 , V_430 ) ;
break;
}
F_108 ( V_122 ) ;
return 0 ;
}
static int F_260 ( struct V_39 * V_9 , struct V_121 * V_122 )
{
struct V_1 * V_14 = F_54 ( V_9 ) -> V_14 ;
T_7 V_135 ;
T_1 V_431 ;
int V_120 , V_419 , V_443 ;
V_135 = F_145 ( V_14 , V_122 -> V_35 ) ;
F_237 ( V_122 , F_78 ( V_14 ) ) ;
V_120 = V_122 -> V_120 ;
if ( F_227 ( V_14 , V_122 ) )
goto V_434;
if ( F_261 ( V_14 , V_135 ) && ! F_262 ( V_14 , V_135 ) )
V_120 -= V_254 ;
if ( V_14 -> V_143 == V_144 )
V_120 -= V_145 ;
if ( V_120 > V_14 -> V_346 ) {
F_56 ( V_14 -> V_3 , V_14 , V_92 ) ;
goto V_434;
}
V_431 = F_247 ( V_14 , V_135 ) ;
V_443 = F_231 ( V_14 , V_431 , V_14 -> V_229 ) ;
V_419 = F_231 ( V_14 , V_14 -> V_230 ,
V_14 -> V_229 ) ;
if ( V_443 > V_419 ) {
F_56 ( V_14 -> V_3 , V_14 , V_92 ) ;
goto V_434;
}
if ( ! F_262 ( V_14 , V_135 ) ) {
if ( V_120 < 0 ) {
F_56 ( V_14 -> V_3 , V_14 , V_92 ) ;
goto V_434;
}
F_245 ( V_14 , V_135 , V_122 ) ;
} else {
if ( V_120 != 0 ) {
F_198 ( L_62 , V_120 ) ;
F_56 ( V_14 -> V_3 , V_14 , V_92 ) ;
goto V_434;
}
F_258 ( V_14 , V_135 , V_122 ) ;
}
return 0 ;
V_434:
F_108 ( V_122 ) ;
return 0 ;
}
static inline int F_263 ( struct V_2 * V_3 , T_1 V_4 , struct V_121 * V_122 )
{
struct V_1 * V_14 ;
struct V_39 * V_9 = NULL ;
T_7 V_135 ;
T_1 V_228 ;
int V_120 ;
V_14 = F_6 ( V_3 , V_4 ) ;
if ( ! V_14 ) {
F_22 ( L_63 , V_4 ) ;
goto V_434;
}
V_9 = V_14 -> V_9 ;
F_22 ( L_64 , V_14 , V_122 -> V_120 ) ;
if ( V_14 -> V_23 != V_24 )
goto V_434;
switch ( V_14 -> V_86 ) {
case V_208 :
if ( V_14 -> V_303 < V_122 -> V_120 )
goto V_434;
if ( ! V_14 -> V_33 -> V_267 ( V_14 -> V_35 , V_122 ) )
goto V_18;
break;
case V_87 :
F_260 ( V_9 , V_122 ) ;
goto V_18;
case V_174 :
V_135 = F_145 ( V_14 , V_122 -> V_35 ) ;
F_237 ( V_122 , F_78 ( V_14 ) ) ;
V_120 = V_122 -> V_120 ;
if ( F_227 ( V_14 , V_122 ) )
goto V_434;
if ( F_261 ( V_14 , V_135 ) )
V_120 -= V_254 ;
if ( V_14 -> V_143 == V_144 )
V_120 -= V_145 ;
if ( V_120 > V_14 -> V_346 || V_120 < 0 || F_262 ( V_14 , V_135 ) )
goto V_434;
V_228 = F_246 ( V_14 , V_135 ) ;
if ( V_14 -> V_363 != V_228 ) {
F_108 ( V_14 -> V_424 ) ;
V_14 -> V_424 = NULL ;
V_14 -> V_426 = NULL ;
V_14 -> V_425 = 0 ;
}
V_14 -> V_363 = F_147 ( V_14 , V_228 ) ;
if ( F_235 ( V_14 , V_122 , V_135 ) == - V_263 )
F_56 ( V_14 -> V_3 , V_14 , V_92 ) ;
goto V_18;
default:
F_22 ( L_65 , V_14 , V_14 -> V_86 ) ;
break;
}
V_434:
F_108 ( V_122 ) ;
V_18:
if ( V_9 )
F_26 ( V_9 ) ;
return 0 ;
}
static inline int F_264 ( struct V_2 * V_3 , T_3 V_11 , struct V_121 * V_122 )
{
struct V_39 * V_9 = NULL ;
struct V_1 * V_14 ;
V_14 = F_117 ( 0 , V_11 , V_3 -> V_12 ) ;
if ( ! V_14 )
goto V_434;
V_9 = V_14 -> V_9 ;
F_7 ( V_9 ) ;
F_22 ( L_66 , V_9 , V_122 -> V_120 ) ;
if ( V_14 -> V_23 != V_26 && V_14 -> V_23 != V_24 )
goto V_434;
if ( V_14 -> V_303 < V_122 -> V_120 )
goto V_434;
if ( ! V_14 -> V_33 -> V_267 ( V_14 -> V_35 , V_122 ) )
goto V_18;
V_434:
F_108 ( V_122 ) ;
V_18:
if ( V_9 )
F_26 ( V_9 ) ;
return 0 ;
}
static inline int F_265 ( struct V_2 * V_3 , T_3 V_4 , struct V_121 * V_122 )
{
struct V_39 * V_9 = NULL ;
struct V_1 * V_14 ;
V_14 = F_94 ( 0 , V_4 , V_3 -> V_12 ) ;
if ( ! V_14 )
goto V_434;
V_9 = V_14 -> V_9 ;
F_7 ( V_9 ) ;
F_22 ( L_66 , V_9 , V_122 -> V_120 ) ;
if ( V_14 -> V_23 != V_26 && V_14 -> V_23 != V_24 )
goto V_434;
if ( V_14 -> V_303 < V_122 -> V_120 )
goto V_434;
if ( ! V_14 -> V_33 -> V_267 ( V_14 -> V_35 , V_122 ) )
goto V_18;
V_434:
F_108 ( V_122 ) ;
V_18:
if ( V_9 )
F_26 ( V_9 ) ;
return 0 ;
}
static void F_266 ( struct V_2 * V_3 , struct V_121 * V_122 )
{
struct V_136 * V_137 = ( void * ) V_122 -> V_35 ;
T_1 V_4 , V_120 ;
T_3 V_11 ;
F_237 ( V_122 , V_149 ) ;
V_4 = F_122 ( V_137 -> V_4 ) ;
V_120 = F_122 ( V_137 -> V_120 ) ;
if ( V_120 != V_122 -> V_120 ) {
F_108 ( V_122 ) ;
return;
}
F_22 ( L_67 , V_120 , V_4 ) ;
switch ( V_4 ) {
case V_272 :
case V_62 :
F_226 ( V_3 , V_122 ) ;
break;
case V_61 :
V_11 = F_178 ( V_122 -> V_35 ) ;
F_237 ( V_122 , 2 ) ;
F_264 ( V_3 , V_11 , V_122 ) ;
break;
case V_58 :
F_265 ( V_3 , V_4 , V_122 ) ;
break;
case V_444 :
if ( F_267 ( V_3 , V_122 ) )
F_107 ( V_3 -> V_54 , V_445 ) ;
break;
default:
F_263 ( V_3 , V_4 , V_122 ) ;
break;
}
}
int F_268 ( struct V_206 * V_124 , T_4 * V_205 )
{
int V_446 = 0 , V_447 = 0 , V_448 = 0 ;
struct V_1 * V_5 ;
F_22 ( L_68 , V_124 -> V_449 , F_119 ( V_205 ) ) ;
F_95 ( & V_16 ) ;
F_11 (c, &chan_list, global_l) {
struct V_39 * V_9 = V_5 -> V_9 ;
if ( V_5 -> V_23 != V_27 )
continue;
if ( ! F_12 ( & F_13 ( V_9 ) -> V_12 , & V_124 -> V_205 ) ) {
V_447 |= V_450 ;
if ( F_45 ( V_451 , & V_5 -> V_123 ) )
V_447 |= V_403 ;
V_446 ++ ;
} else if ( ! F_12 ( & F_13 ( V_9 ) -> V_12 , V_187 ) ) {
V_448 |= V_450 ;
if ( F_45 ( V_451 , & V_5 -> V_123 ) )
V_448 |= V_403 ;
}
}
F_96 ( & V_16 ) ;
return V_446 ? V_447 : V_448 ;
}
int F_269 ( struct V_132 * V_54 , T_2 V_102 )
{
struct V_2 * V_3 ;
F_22 ( L_69 , V_54 , F_119 ( & V_54 -> V_192 ) , V_102 ) ;
if ( ! V_102 ) {
V_3 = F_113 ( V_54 , V_102 ) ;
if ( V_3 )
F_103 ( V_3 ) ;
} else
F_107 ( V_54 , F_270 ( V_102 ) ) ;
return 0 ;
}
int F_271 ( struct V_132 * V_54 )
{
struct V_2 * V_3 = V_54 -> V_196 ;
F_22 ( L_70 , V_54 ) ;
if ( ! V_3 )
return V_51 ;
return V_3 -> V_50 ;
}
int F_272 ( struct V_132 * V_54 , T_2 V_40 )
{
F_22 ( L_71 , V_54 , V_40 ) ;
F_107 ( V_54 , F_270 ( V_40 ) ) ;
return 0 ;
}
static inline void F_273 ( struct V_1 * V_14 , T_2 V_452 )
{
if ( V_14 -> V_52 != V_53 )
return;
if ( V_452 == 0x00 ) {
if ( V_14 -> V_42 == V_108 ) {
F_39 ( V_14 ) ;
F_55 ( V_14 ,
F_88 ( V_453 ) ) ;
} else if ( V_14 -> V_42 == V_106 )
F_25 ( V_14 , V_41 ) ;
} else {
if ( V_14 -> V_42 == V_108 )
F_39 ( V_14 ) ;
}
}
int F_274 ( struct V_132 * V_54 , T_2 V_102 , T_2 V_452 )
{
struct V_2 * V_3 = V_54 -> V_196 ;
struct V_1 * V_14 ;
if ( ! V_3 )
return 0 ;
F_22 ( L_21 , V_3 ) ;
if ( V_54 -> type == V_55 ) {
F_275 ( V_3 , 0 ) ;
F_200 ( & V_3 -> V_200 ) ;
}
F_2 () ;
F_3 (chan, &conn->chan_l, list) {
struct V_39 * V_9 = V_14 -> V_9 ;
F_91 ( V_9 ) ;
F_22 ( L_72 , V_14 -> V_8 ) ;
if ( V_14 -> V_8 == V_58 ) {
if ( ! V_102 && V_452 ) {
V_14 -> V_42 = V_54 -> V_42 ;
F_102 ( V_9 ) ;
}
F_92 ( V_9 ) ;
continue;
}
if ( F_45 ( V_155 , & V_14 -> V_83 ) ) {
F_92 ( V_9 ) ;
continue;
}
if ( ! V_102 && ( V_14 -> V_23 == V_24 ||
V_14 -> V_23 == V_30 ) ) {
F_273 ( V_14 , V_452 ) ;
F_92 ( V_9 ) ;
continue;
}
if ( V_14 -> V_23 == V_28 ) {
if ( ! V_102 ) {
struct V_159 V_160 ;
V_160 . V_8 = F_16 ( V_14 -> V_8 ) ;
V_160 . V_11 = V_14 -> V_11 ;
V_14 -> V_10 = F_61 ( V_3 ) ;
F_83 ( V_155 , & V_14 -> V_83 ) ;
F_57 ( V_3 , V_14 -> V_10 ,
V_161 , sizeof( V_160 ) , & V_160 ) ;
} else {
F_39 ( V_14 ) ;
F_55 ( V_14 ,
F_88 ( V_454 ) ) ;
}
} else if ( V_14 -> V_23 == V_29 ) {
struct V_96 V_97 ;
T_5 V_455 , V_456 ;
if ( ! V_102 ) {
if ( F_13 ( V_9 ) -> V_99 ) {
struct V_39 * V_77 = F_13 ( V_9 ) -> V_77 ;
V_455 = V_179 ;
V_456 = V_180 ;
if ( V_77 )
V_77 -> V_80 ( V_77 , 0 ) ;
} else {
F_21 ( V_14 , V_30 ) ;
V_455 = V_181 ;
V_456 = V_103 ;
}
} else {
F_21 ( V_14 , V_31 ) ;
F_55 ( V_14 ,
F_88 ( V_454 ) ) ;
V_455 = V_100 ;
V_456 = V_103 ;
}
V_97 . V_8 = F_16 ( V_14 -> V_7 ) ;
V_97 . V_7 = F_16 ( V_14 -> V_8 ) ;
V_97 . V_98 = F_16 ( V_455 ) ;
V_97 . V_102 = F_16 ( V_456 ) ;
F_57 ( V_3 , V_14 -> V_10 , V_104 ,
sizeof( V_97 ) , & V_97 ) ;
}
F_92 ( V_9 ) ;
}
F_4 () ;
return 0 ;
}
int F_276 ( struct V_132 * V_54 , struct V_121 * V_122 , T_1 V_123 )
{
struct V_2 * V_3 = V_54 -> V_196 ;
if ( ! V_3 )
V_3 = F_113 ( V_54 , 0 ) ;
if ( ! V_3 )
goto V_434;
F_22 ( L_73 , V_3 , V_122 -> V_120 , V_123 ) ;
if ( ! ( V_123 & V_457 ) ) {
struct V_136 * V_458 ;
struct V_1 * V_14 ;
T_1 V_4 ;
int V_120 ;
if ( V_3 -> V_459 ) {
F_198 ( L_74 , V_122 -> V_120 ) ;
F_108 ( V_3 -> V_197 ) ;
V_3 -> V_197 = NULL ;
V_3 -> V_459 = 0 ;
F_105 ( V_3 , V_460 ) ;
}
if ( V_122 -> V_120 < V_149 ) {
F_198 ( L_75 , V_122 -> V_120 ) ;
F_105 ( V_3 , V_460 ) ;
goto V_434;
}
V_458 = (struct V_136 * ) V_122 -> V_35 ;
V_120 = F_122 ( V_458 -> V_120 ) + V_149 ;
V_4 = F_122 ( V_458 -> V_4 ) ;
if ( V_120 == V_122 -> V_120 ) {
F_266 ( V_3 , V_122 ) ;
return 0 ;
}
F_22 ( L_76 , V_120 , V_122 -> V_120 ) ;
if ( V_122 -> V_120 > V_120 ) {
F_198 ( L_77 ,
V_122 -> V_120 , V_120 ) ;
F_105 ( V_3 , V_460 ) ;
goto V_434;
}
V_14 = F_6 ( V_3 , V_4 ) ;
if ( V_14 && V_14 -> V_9 ) {
struct V_39 * V_9 = V_14 -> V_9 ;
if ( V_14 -> V_303 < V_120 - V_149 ) {
F_198 ( L_78
L_79 , V_120 ,
V_14 -> V_303 ) ;
F_26 ( V_9 ) ;
F_105 ( V_3 , V_460 ) ;
goto V_434;
}
F_26 ( V_9 ) ;
}
V_3 -> V_197 = F_75 ( V_120 , V_46 ) ;
if ( ! V_3 -> V_197 )
goto V_434;
F_277 ( V_122 , F_76 ( V_3 -> V_197 , V_122 -> V_120 ) ,
V_122 -> V_120 ) ;
V_3 -> V_459 = V_120 - V_122 -> V_120 ;
} else {
F_22 ( L_80 , V_122 -> V_120 , V_3 -> V_459 ) ;
if ( ! V_3 -> V_459 ) {
F_198 ( L_81 , V_122 -> V_120 ) ;
F_105 ( V_3 , V_460 ) ;
goto V_434;
}
if ( V_122 -> V_120 > V_3 -> V_459 ) {
F_198 ( L_82 ,
V_122 -> V_120 , V_3 -> V_459 ) ;
F_108 ( V_3 -> V_197 ) ;
V_3 -> V_197 = NULL ;
V_3 -> V_459 = 0 ;
F_105 ( V_3 , V_460 ) ;
goto V_434;
}
F_277 ( V_122 , F_76 ( V_3 -> V_197 , V_122 -> V_120 ) ,
V_122 -> V_120 ) ;
V_3 -> V_459 -= V_122 -> V_120 ;
if ( ! V_3 -> V_459 ) {
F_266 ( V_3 , V_3 -> V_197 ) ;
V_3 -> V_197 = NULL ;
}
}
V_434:
F_108 ( V_122 ) ;
return 0 ;
}
static int F_278 ( struct V_461 * V_462 , void * V_19 )
{
struct V_1 * V_5 ;
F_95 ( & V_16 ) ;
F_11 (c, &chan_list, global_l) {
struct V_39 * V_9 = V_5 -> V_9 ;
F_279 ( V_462 , L_83 ,
F_119 ( & F_13 ( V_9 ) -> V_12 ) ,
F_119 ( & F_13 ( V_9 ) -> V_192 ) ,
V_5 -> V_23 , F_122 ( V_5 -> V_11 ) ,
V_5 -> V_8 , V_5 -> V_7 , V_5 -> V_303 , V_5 -> V_56 ,
V_5 -> V_42 , V_5 -> V_86 ) ;
}
F_96 ( & V_16 ) ;
return 0 ;
}
static int F_280 ( struct V_463 * V_463 , struct V_464 * V_464 )
{
return F_281 ( V_464 , F_278 , V_463 -> V_465 ) ;
}
int T_10 F_282 ( void )
{
int V_15 ;
V_15 = F_283 () ;
if ( V_15 < 0 )
return V_15 ;
if ( V_466 ) {
V_467 = F_284 ( L_84 , 0444 ,
V_466 , NULL , & V_468 ) ;
if ( ! V_467 )
F_198 ( L_85 ) ;
}
return 0 ;
}
void F_285 ( void )
{
F_286 ( V_467 ) ;
F_287 () ;
}
