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
if ( V_5 )
F_6 ( V_5 -> V_9 ) ;
F_7 ( & V_3 -> V_8 ) ;
return V_5 ;
}
static struct V_1 * F_8 ( struct V_2 * V_3 , T_2 V_10 )
{
struct V_1 * V_5 ;
F_2 (c, &conn->chan_l, list) {
if ( V_5 -> V_10 == V_10 )
return V_5 ;
}
return NULL ;
}
static inline struct V_1 * F_9 ( struct V_2 * V_3 , T_2 V_10 )
{
struct V_1 * V_5 ;
F_5 ( & V_3 -> V_8 ) ;
V_5 = F_8 ( V_3 , V_10 ) ;
if ( V_5 )
F_6 ( V_5 -> V_9 ) ;
F_7 ( & V_3 -> V_8 ) ;
return V_5 ;
}
static struct V_1 * F_10 ( T_3 V_11 , T_4 * V_12 )
{
struct V_1 * V_5 ;
F_2 (c, &chan_list, global_l) {
if ( V_5 -> V_13 == V_11 && ! F_11 ( & F_12 ( V_5 -> V_9 ) -> V_12 , V_12 ) )
goto V_14;
}
V_5 = NULL ;
V_14:
return V_5 ;
}
int F_13 ( struct V_1 * V_15 , T_4 * V_12 , T_3 V_11 )
{
int V_16 ;
F_14 ( & V_17 ) ;
if ( V_11 && F_10 ( V_11 , V_12 ) ) {
V_16 = - V_18 ;
goto V_19;
}
if ( V_11 ) {
V_15 -> V_11 = V_11 ;
V_15 -> V_13 = V_11 ;
V_16 = 0 ;
} else {
T_1 V_20 ;
V_16 = - V_21 ;
for ( V_20 = 0x1001 ; V_20 < 0x1100 ; V_20 += 2 )
if ( ! F_10 ( F_15 ( V_20 ) , V_12 ) ) {
V_15 -> V_11 = F_15 ( V_20 ) ;
V_15 -> V_13 = F_15 ( V_20 ) ;
V_16 = 0 ;
break;
}
}
V_19:
F_16 ( & V_17 ) ;
return V_16 ;
}
int F_17 ( struct V_1 * V_15 , T_5 V_7 )
{
F_14 ( & V_17 ) ;
V_15 -> V_7 = V_7 ;
F_16 ( & V_17 ) ;
return 0 ;
}
static T_1 F_18 ( struct V_2 * V_3 )
{
T_1 V_4 = V_22 ;
for (; V_4 < V_23 ; V_4 ++ ) {
if ( ! F_3 ( V_3 , V_4 ) )
return V_4 ;
}
return 0 ;
}
struct V_1 * F_19 ( struct V_24 * V_9 )
{
struct V_1 * V_15 ;
V_15 = F_20 ( sizeof( * V_15 ) , V_25 ) ;
if ( ! V_15 )
return NULL ;
V_15 -> V_9 = V_9 ;
F_14 ( & V_17 ) ;
F_21 ( & V_15 -> V_26 , & V_27 ) ;
F_16 ( & V_17 ) ;
return V_15 ;
}
void F_22 ( struct V_1 * V_15 )
{
F_14 ( & V_17 ) ;
F_23 ( & V_15 -> V_26 ) ;
F_16 ( & V_17 ) ;
F_24 ( V_15 ) ;
}
static void F_25 ( struct V_2 * V_3 , struct V_1 * V_15 )
{
struct V_24 * V_9 = V_15 -> V_9 ;
F_26 ( L_1 , V_3 ,
V_15 -> V_11 , V_15 -> V_6 ) ;
V_3 -> V_28 = 0x13 ;
V_15 -> V_3 = V_3 ;
if ( V_9 -> V_29 == V_30 || V_9 -> V_29 == V_31 ) {
if ( V_3 -> V_32 -> type == V_33 ) {
V_15 -> V_34 = V_35 ;
V_15 -> V_7 = V_36 ;
V_15 -> V_6 = V_36 ;
} else {
V_15 -> V_7 = F_18 ( V_3 ) ;
V_15 -> V_34 = V_37 ;
}
} else if ( V_9 -> V_29 == V_38 ) {
V_15 -> V_7 = V_39 ;
V_15 -> V_6 = V_39 ;
V_15 -> V_34 = V_37 ;
} else {
V_15 -> V_7 = V_40 ;
V_15 -> V_6 = V_40 ;
V_15 -> V_34 = V_37 ;
}
F_27 ( V_9 ) ;
F_21 ( & V_15 -> V_41 , & V_3 -> V_42 ) ;
}
void F_28 ( struct V_1 * V_15 , int V_16 )
{
struct V_24 * V_9 = V_15 -> V_9 ;
struct V_2 * V_3 = V_15 -> V_3 ;
struct V_24 * V_43 = F_12 ( V_9 ) -> V_43 ;
F_29 ( V_9 ) ;
F_26 ( L_2 , V_15 , V_3 , V_16 ) ;
if ( V_3 ) {
F_14 ( & V_3 -> V_8 ) ;
F_23 ( & V_15 -> V_41 ) ;
F_16 ( & V_3 -> V_8 ) ;
F_30 ( V_9 ) ;
V_15 -> V_3 = NULL ;
F_31 ( V_3 -> V_32 ) ;
}
V_9 -> V_44 = V_45 ;
F_32 ( V_9 , V_46 ) ;
if ( V_16 )
V_9 -> V_47 = V_16 ;
if ( V_43 ) {
F_33 ( V_9 ) ;
V_43 -> V_48 ( V_43 , 0 ) ;
} else
V_9 -> V_49 ( V_9 ) ;
if ( ! ( V_15 -> V_50 & V_51 &&
V_15 -> V_50 & V_52 ) )
return;
F_34 ( & V_15 -> V_53 ) ;
if ( V_15 -> V_54 == V_55 ) {
struct V_56 * V_57 , * V_58 ;
F_35 ( & V_15 -> V_59 ) ;
F_35 ( & V_15 -> V_60 ) ;
F_35 ( & V_15 -> V_61 ) ;
F_34 ( & V_15 -> V_62 ) ;
F_34 ( & V_15 -> V_63 ) ;
F_36 (l, tmp, &chan->srej_l, list) {
F_23 ( & V_57 -> V_41 ) ;
F_24 ( V_57 ) ;
}
}
}
static inline T_2 F_37 ( struct V_1 * V_15 )
{
struct V_24 * V_9 = V_15 -> V_9 ;
if ( V_9 -> V_29 == V_64 ) {
switch ( V_15 -> V_65 ) {
case V_66 :
return V_67 ;
case V_68 :
return V_69 ;
default:
return V_70 ;
}
} else if ( V_15 -> V_11 == F_15 ( 0x0001 ) ) {
if ( V_15 -> V_65 == V_71 )
V_15 -> V_65 = V_72 ;
if ( V_15 -> V_65 == V_66 )
return V_73 ;
else
return V_70 ;
} else {
switch ( V_15 -> V_65 ) {
case V_66 :
return V_74 ;
case V_68 :
return V_75 ;
default:
return V_70 ;
}
}
}
static inline int F_38 ( struct V_1 * V_15 )
{
struct V_2 * V_3 = V_15 -> V_3 ;
T_6 V_76 ;
V_76 = F_37 ( V_15 ) ;
return F_39 ( V_3 -> V_32 , V_15 -> V_65 , V_76 ) ;
}
T_2 F_40 ( struct V_2 * V_3 )
{
T_2 V_77 ;
F_41 ( & V_3 -> V_78 ) ;
if ( ++ V_3 -> V_79 > 128 )
V_3 -> V_79 = 1 ;
V_77 = V_3 -> V_79 ;
F_42 ( & V_3 -> V_78 ) ;
return V_77 ;
}
void F_43 ( struct V_2 * V_3 , T_2 V_10 , T_2 V_80 , T_1 V_81 , void * V_82 )
{
struct V_83 * V_84 = F_44 ( V_3 , V_80 , V_10 , V_81 , V_82 ) ;
T_2 V_85 ;
F_26 ( L_3 , V_80 ) ;
if ( ! V_84 )
return;
if ( F_45 ( V_3 -> V_32 -> V_86 ) )
V_85 = V_87 ;
else
V_85 = V_88 ;
F_46 ( V_3 -> V_32 , V_84 , V_85 ) ;
}
static inline void F_47 ( struct V_1 * V_15 , T_1 V_89 )
{
struct V_83 * V_84 ;
struct V_90 * V_91 ;
struct V_92 * V_93 = F_48 ( V_15 -> V_9 ) ;
struct V_2 * V_3 = V_15 -> V_3 ;
struct V_24 * V_9 = (struct V_24 * ) V_93 ;
int V_94 , V_95 = V_96 + 2 ;
T_2 V_85 ;
if ( V_9 -> V_44 != V_97 )
return;
if ( V_15 -> V_98 == V_99 )
V_95 += 2 ;
F_26 ( L_4 , V_15 , V_89 ) ;
V_94 = F_49 (unsigned int, conn->mtu, hlen) ;
V_89 |= V_100 ;
if ( V_15 -> V_101 & V_102 ) {
V_89 |= V_103 ;
V_15 -> V_101 &= ~ V_102 ;
}
if ( V_15 -> V_101 & V_104 ) {
V_89 |= V_105 ;
V_15 -> V_101 &= ~ V_104 ;
}
V_84 = F_50 ( V_94 , V_25 ) ;
if ( ! V_84 )
return;
V_91 = (struct V_90 * ) F_51 ( V_84 , V_96 ) ;
V_91 -> V_81 = F_15 ( V_95 - V_96 ) ;
V_91 -> V_4 = F_15 ( V_15 -> V_6 ) ;
F_52 ( V_89 , F_51 ( V_84 , 2 ) ) ;
if ( V_15 -> V_98 == V_99 ) {
T_1 V_98 = F_53 ( 0 , ( T_2 * ) V_91 , V_94 - 2 ) ;
F_52 ( V_98 , F_51 ( V_84 , 2 ) ) ;
}
if ( F_45 ( V_3 -> V_32 -> V_86 ) )
V_85 = V_87 ;
else
V_85 = V_88 ;
F_46 ( V_15 -> V_3 -> V_32 , V_84 , V_85 ) ;
}
static inline void F_54 ( struct V_1 * V_15 , T_1 V_89 )
{
if ( V_15 -> V_101 & V_106 ) {
V_89 |= V_107 ;
V_15 -> V_101 |= V_108 ;
} else
V_89 |= V_109 ;
V_89 |= V_15 -> V_110 << V_111 ;
F_47 ( V_15 , V_89 ) ;
}
static inline int F_55 ( struct V_1 * V_15 )
{
return ! ( V_15 -> V_50 & V_112 ) ;
}
static void F_56 ( struct V_1 * V_15 )
{
struct V_2 * V_3 = V_15 -> V_3 ;
if ( V_3 -> V_113 & V_114 ) {
if ( ! ( V_3 -> V_113 & V_115 ) )
return;
if ( F_38 ( V_15 ) &&
F_55 ( V_15 ) ) {
struct V_116 V_117 ;
V_117 . V_7 = F_15 ( V_15 -> V_7 ) ;
V_117 . V_11 = V_15 -> V_11 ;
V_15 -> V_10 = F_40 ( V_3 ) ;
V_15 -> V_50 |= V_112 ;
F_43 ( V_3 , V_15 -> V_10 , V_118 ,
sizeof( V_117 ) , & V_117 ) ;
}
} else {
struct V_119 V_117 ;
V_117 . type = F_15 ( V_120 ) ;
V_3 -> V_113 |= V_114 ;
V_3 -> V_121 = F_40 ( V_3 ) ;
F_57 ( & V_3 -> V_122 , V_123 +
F_58 ( V_124 ) ) ;
F_43 ( V_3 , V_3 -> V_121 ,
V_125 , sizeof( V_117 ) , & V_117 ) ;
}
}
static inline int F_59 ( T_6 V_54 , T_7 V_126 )
{
T_8 V_127 = V_128 ;
if ( ! V_129 )
V_127 |= V_130 | V_131 ;
switch ( V_54 ) {
case V_55 :
return V_130 & V_126 & V_127 ;
case V_132 :
return V_131 & V_126 & V_127 ;
default:
return 0x00 ;
}
}
void F_60 ( struct V_2 * V_3 , struct V_1 * V_15 , int V_16 )
{
struct V_24 * V_9 ;
struct V_133 V_117 ;
if ( ! V_3 )
return;
V_9 = V_15 -> V_9 ;
if ( V_15 -> V_54 == V_55 ) {
F_35 ( & V_15 -> V_59 ) ;
F_35 ( & V_15 -> V_60 ) ;
F_35 ( & V_15 -> V_61 ) ;
}
V_117 . V_6 = F_15 ( V_15 -> V_6 ) ;
V_117 . V_7 = F_15 ( V_15 -> V_7 ) ;
F_43 ( V_3 , F_40 ( V_3 ) ,
V_134 , sizeof( V_117 ) , & V_117 ) ;
V_9 -> V_44 = V_135 ;
V_9 -> V_47 = V_16 ;
}
static void F_61 ( struct V_2 * V_3 )
{
struct V_1 * V_15 , * V_58 ;
F_26 ( L_5 , V_3 ) ;
F_5 ( & V_3 -> V_8 ) ;
F_36 (chan, tmp, &conn->chan_l, list) {
struct V_24 * V_9 = V_15 -> V_9 ;
F_6 ( V_9 ) ;
if ( V_9 -> V_29 != V_30 &&
V_9 -> V_29 != V_31 ) {
F_62 ( V_9 ) ;
continue;
}
if ( V_9 -> V_44 == V_136 ) {
struct V_116 V_117 ;
if ( ! F_38 ( V_15 ) ||
! F_55 ( V_15 ) ) {
F_62 ( V_9 ) ;
continue;
}
if ( ! F_59 ( V_15 -> V_54 ,
V_3 -> V_126 )
&& V_15 -> V_50 &
V_137 ) {
F_63 ( & V_3 -> V_8 ) ;
F_64 ( V_9 , V_138 ) ;
F_65 ( & V_3 -> V_8 ) ;
F_62 ( V_9 ) ;
continue;
}
V_117 . V_7 = F_15 ( V_15 -> V_7 ) ;
V_117 . V_11 = V_15 -> V_11 ;
V_15 -> V_10 = F_40 ( V_3 ) ;
V_15 -> V_50 |= V_112 ;
F_43 ( V_3 , V_15 -> V_10 , V_118 ,
sizeof( V_117 ) , & V_117 ) ;
} else if ( V_9 -> V_44 == V_139 ) {
struct V_140 V_141 ;
char V_142 [ 128 ] ;
V_141 . V_7 = F_15 ( V_15 -> V_6 ) ;
V_141 . V_6 = F_15 ( V_15 -> V_7 ) ;
if ( F_38 ( V_15 ) ) {
if ( F_12 ( V_9 ) -> V_143 ) {
struct V_24 * V_43 = F_12 ( V_9 ) -> V_43 ;
V_141 . V_144 = F_15 ( V_145 ) ;
V_141 . V_146 = F_15 ( V_147 ) ;
if ( V_43 )
V_43 -> V_48 ( V_43 , 0 ) ;
} else {
V_9 -> V_44 = V_148 ;
V_141 . V_144 = F_15 ( V_149 ) ;
V_141 . V_146 = F_15 ( V_150 ) ;
}
} else {
V_141 . V_144 = F_15 ( V_145 ) ;
V_141 . V_146 = F_15 ( V_151 ) ;
}
F_43 ( V_3 , V_15 -> V_10 , V_152 ,
sizeof( V_141 ) , & V_141 ) ;
if ( V_15 -> V_50 & V_153 ||
V_141 . V_144 != V_149 ) {
F_62 ( V_9 ) ;
continue;
}
V_15 -> V_50 |= V_153 ;
F_43 ( V_3 , F_40 ( V_3 ) , V_154 ,
F_66 ( V_15 , V_142 ) , V_142 ) ;
V_15 -> V_155 ++ ;
}
F_62 ( V_9 ) ;
}
F_7 ( & V_3 -> V_8 ) ;
}
static struct V_1 * F_67 ( int V_156 , T_3 V_4 , T_4 * V_12 )
{
struct V_1 * V_5 , * V_157 = NULL ;
F_5 ( & V_17 ) ;
F_2 (c, &chan_list, global_l) {
struct V_24 * V_9 = V_5 -> V_9 ;
if ( V_156 && V_9 -> V_44 != V_156 )
continue;
if ( V_5 -> V_7 == V_4 ) {
if ( ! F_11 ( & F_12 ( V_9 ) -> V_12 , V_12 ) ) {
F_7 ( & V_17 ) ;
return V_5 ;
}
if ( ! F_11 ( & F_12 ( V_9 ) -> V_12 , V_158 ) )
V_157 = V_5 ;
}
}
F_7 ( & V_17 ) ;
return V_157 ;
}
static void F_68 ( struct V_2 * V_3 )
{
struct V_24 * V_43 , * V_9 ;
struct V_1 * V_15 , * V_159 ;
F_26 ( L_6 ) ;
V_159 = F_67 ( V_160 , V_36 ,
V_3 -> V_12 ) ;
if ( ! V_159 )
return;
V_43 = V_159 -> V_9 ;
F_6 ( V_43 ) ;
if ( F_69 ( V_43 ) ) {
F_26 ( L_7 , V_43 -> V_161 ) ;
goto V_162;
}
V_9 = F_70 ( F_71 ( V_43 ) , NULL , V_163 , V_25 ) ;
if ( ! V_9 )
goto V_162;
V_15 = F_19 ( V_9 ) ;
if ( ! V_15 ) {
F_72 ( V_9 ) ;
goto V_162;
}
F_48 ( V_9 ) -> V_15 = V_15 ;
F_14 ( & V_3 -> V_8 ) ;
F_73 ( V_3 -> V_32 ) ;
F_74 ( V_9 , V_43 ) ;
F_75 ( & F_12 ( V_9 ) -> V_12 , V_3 -> V_12 ) ;
F_75 ( & F_12 ( V_9 ) -> V_164 , V_3 -> V_164 ) ;
F_76 ( V_43 , V_9 ) ;
F_25 ( V_3 , V_15 ) ;
F_77 ( V_9 , V_9 -> V_165 ) ;
V_9 -> V_44 = V_97 ;
V_43 -> V_48 ( V_43 , 0 ) ;
F_16 ( & V_3 -> V_8 ) ;
V_162:
F_62 ( V_43 ) ;
}
static void F_78 ( struct V_2 * V_3 )
{
struct V_1 * V_15 ;
F_26 ( L_5 , V_3 ) ;
if ( ! V_3 -> V_32 -> V_166 && V_3 -> V_32 -> type == V_33 )
F_68 ( V_3 ) ;
F_5 ( & V_3 -> V_8 ) ;
F_2 (chan, &conn->chan_l, list) {
struct V_24 * V_9 = V_15 -> V_9 ;
F_6 ( V_9 ) ;
if ( V_3 -> V_32 -> type == V_33 ) {
F_29 ( V_9 ) ;
V_9 -> V_44 = V_97 ;
V_9 -> V_49 ( V_9 ) ;
}
if ( V_9 -> V_29 != V_30 &&
V_9 -> V_29 != V_31 ) {
F_29 ( V_9 ) ;
V_9 -> V_44 = V_97 ;
V_9 -> V_49 ( V_9 ) ;
} else if ( V_9 -> V_44 == V_136 )
F_56 ( V_15 ) ;
F_62 ( V_9 ) ;
}
F_7 ( & V_3 -> V_8 ) ;
}
static void F_79 ( struct V_2 * V_3 , int V_16 )
{
struct V_1 * V_15 ;
F_26 ( L_5 , V_3 ) ;
F_5 ( & V_3 -> V_8 ) ;
F_2 (chan, &conn->chan_l, list) {
struct V_24 * V_9 = V_15 -> V_9 ;
if ( V_15 -> V_167 )
V_9 -> V_47 = V_16 ;
}
F_7 ( & V_3 -> V_8 ) ;
}
static void F_80 ( unsigned long V_168 )
{
struct V_2 * V_3 = ( void * ) V_168 ;
V_3 -> V_113 |= V_115 ;
V_3 -> V_121 = 0 ;
F_61 ( V_3 ) ;
}
static struct V_2 * F_81 ( struct V_169 * V_32 , T_2 V_146 )
{
struct V_2 * V_3 = V_32 -> V_170 ;
if ( V_3 || V_146 )
return V_3 ;
V_3 = F_20 ( sizeof( struct V_2 ) , V_25 ) ;
if ( ! V_3 )
return NULL ;
V_32 -> V_170 = V_3 ;
V_3 -> V_32 = V_32 ;
F_26 ( L_8 , V_32 , V_3 ) ;
if ( V_32 -> V_86 -> V_171 && V_32 -> type == V_33 )
V_3 -> V_172 = V_32 -> V_86 -> V_171 ;
else
V_3 -> V_172 = V_32 -> V_86 -> V_173 ;
V_3 -> V_12 = & V_32 -> V_86 -> V_174 ;
V_3 -> V_164 = & V_32 -> V_164 ;
V_3 -> V_126 = 0 ;
F_82 ( & V_3 -> V_78 ) ;
F_83 ( & V_3 -> V_8 ) ;
F_84 ( & V_3 -> V_42 ) ;
if ( V_32 -> type != V_33 )
F_85 ( & V_3 -> V_122 , F_80 ,
( unsigned long ) V_3 ) ;
V_3 -> V_28 = 0x13 ;
return V_3 ;
}
static void F_86 ( struct V_169 * V_32 , int V_16 )
{
struct V_2 * V_3 = V_32 -> V_170 ;
struct V_1 * V_15 , * V_57 ;
struct V_24 * V_9 ;
if ( ! V_3 )
return;
F_26 ( L_9 , V_32 , V_3 , V_16 ) ;
F_87 ( V_3 -> V_175 ) ;
F_36 (chan, l, &conn->chan_l, list) {
V_9 = V_15 -> V_9 ;
F_6 ( V_9 ) ;
F_28 ( V_15 , V_16 ) ;
F_62 ( V_9 ) ;
F_72 ( V_9 ) ;
}
if ( V_3 -> V_113 & V_114 )
F_88 ( & V_3 -> V_122 ) ;
V_32 -> V_170 = NULL ;
F_24 ( V_3 ) ;
}
static inline void F_89 ( struct V_2 * V_3 , struct V_1 * V_15 )
{
F_14 ( & V_3 -> V_8 ) ;
F_25 ( V_3 , V_15 ) ;
F_16 ( & V_3 -> V_8 ) ;
}
static struct V_1 * F_90 ( int V_156 , T_3 V_11 , T_4 * V_12 )
{
struct V_1 * V_5 , * V_157 = NULL ;
F_5 ( & V_17 ) ;
F_2 (c, &chan_list, global_l) {
struct V_24 * V_9 = V_5 -> V_9 ;
if ( V_156 && V_9 -> V_44 != V_156 )
continue;
if ( V_5 -> V_11 == V_11 ) {
if ( ! F_11 ( & F_12 ( V_9 ) -> V_12 , V_12 ) ) {
F_7 ( & V_17 ) ;
return V_5 ;
}
if ( ! F_11 ( & F_12 ( V_9 ) -> V_12 , V_158 ) )
V_157 = V_5 ;
}
}
F_7 ( & V_17 ) ;
return V_157 ;
}
int F_91 ( struct V_1 * V_15 )
{
struct V_24 * V_9 = V_15 -> V_9 ;
T_4 * V_12 = & F_12 ( V_9 ) -> V_12 ;
T_4 * V_164 = & F_12 ( V_9 ) -> V_164 ;
struct V_2 * V_3 ;
struct V_169 * V_32 ;
struct V_176 * V_86 ;
T_6 V_76 ;
int V_16 ;
F_26 ( L_10 , F_92 ( V_12 ) , F_92 ( V_164 ) ,
V_15 -> V_11 ) ;
V_86 = F_93 ( V_164 , V_12 ) ;
if ( ! V_86 )
return - V_177 ;
F_94 ( V_86 ) ;
V_76 = F_37 ( V_15 ) ;
if ( V_15 -> V_6 == V_36 )
V_32 = F_95 ( V_86 , V_33 , V_164 ,
V_15 -> V_65 , V_76 ) ;
else
V_32 = F_95 ( V_86 , V_178 , V_164 ,
V_15 -> V_65 , V_76 ) ;
if ( F_96 ( V_32 ) ) {
V_16 = F_97 ( V_32 ) ;
goto V_19;
}
V_3 = F_81 ( V_32 , 0 ) ;
if ( ! V_3 ) {
F_31 ( V_32 ) ;
V_16 = - V_179 ;
goto V_19;
}
F_75 ( V_12 , V_3 -> V_12 ) ;
F_89 ( V_3 , V_15 ) ;
V_9 -> V_44 = V_136 ;
F_77 ( V_9 , V_9 -> V_165 ) ;
if ( V_32 -> V_156 == V_97 ) {
if ( V_9 -> V_29 != V_30 &&
V_9 -> V_29 != V_31 ) {
F_29 ( V_9 ) ;
if ( F_38 ( V_15 ) )
V_9 -> V_44 = V_97 ;
} else
F_56 ( V_15 ) ;
}
V_16 = 0 ;
V_19:
F_98 ( V_86 ) ;
F_99 ( V_86 ) ;
return V_16 ;
}
int F_100 ( struct V_24 * V_9 )
{
struct V_1 * V_15 = F_48 ( V_9 ) -> V_15 ;
F_101 ( V_180 , V_181 ) ;
int V_16 = 0 ;
int V_182 = V_183 / 5 ;
F_102 ( F_103 ( V_9 ) , & V_180 ) ;
while ( ( V_15 -> V_184 > 0 && V_15 -> V_3 ) ) {
F_104 ( V_185 ) ;
if ( ! V_182 )
V_182 = V_183 / 5 ;
if ( F_105 ( V_181 ) ) {
V_16 = F_106 ( V_182 ) ;
break;
}
F_107 ( V_9 ) ;
V_182 = F_108 ( V_182 ) ;
F_109 ( V_9 ) ;
V_16 = F_110 ( V_9 ) ;
if ( V_16 )
break;
}
F_104 ( V_186 ) ;
F_111 ( F_103 ( V_9 ) , & V_180 ) ;
return V_16 ;
}
static void F_112 ( unsigned long V_168 )
{
struct V_1 * V_15 = ( void * ) V_168 ;
struct V_24 * V_9 = V_15 -> V_9 ;
F_26 ( L_11 , V_15 ) ;
F_6 ( V_9 ) ;
if ( V_15 -> V_187 >= V_15 -> V_188 ) {
F_60 ( V_15 -> V_3 , V_15 , V_189 ) ;
F_62 ( V_9 ) ;
return;
}
V_15 -> V_187 ++ ;
F_113 () ;
F_54 ( V_15 , V_105 ) ;
F_62 ( V_9 ) ;
}
static void F_114 ( unsigned long V_168 )
{
struct V_1 * V_15 = ( void * ) V_168 ;
struct V_24 * V_9 = V_15 -> V_9 ;
F_26 ( L_11 , V_15 ) ;
F_6 ( V_9 ) ;
V_15 -> V_187 = 1 ;
F_113 () ;
V_15 -> V_101 |= V_190 ;
F_54 ( V_15 , V_105 ) ;
F_62 ( V_9 ) ;
}
static void F_115 ( struct V_1 * V_15 )
{
struct V_83 * V_84 ;
while ( ( V_84 = F_116 ( & V_15 -> V_53 ) ) &&
V_15 -> V_184 ) {
if ( F_117 ( V_84 ) -> V_191 == V_15 -> V_192 )
break;
V_84 = F_118 ( & V_15 -> V_53 ) ;
F_87 ( V_84 ) ;
V_15 -> V_184 -- ;
}
if ( ! V_15 -> V_184 )
F_35 ( & V_15 -> V_59 ) ;
}
void F_119 ( struct V_1 * V_15 , struct V_83 * V_84 )
{
struct V_169 * V_32 = V_15 -> V_3 -> V_32 ;
T_1 V_85 ;
F_26 ( L_12 , V_15 , V_84 , V_84 -> V_81 ) ;
if ( ! V_15 -> V_193 && F_45 ( V_32 -> V_86 ) )
V_85 = V_87 ;
else
V_85 = V_88 ;
F_46 ( V_32 , V_84 , V_85 ) ;
}
void F_120 ( struct V_1 * V_15 )
{
struct V_83 * V_84 ;
T_1 V_89 , V_98 ;
while ( ( V_84 = F_118 ( & V_15 -> V_53 ) ) ) {
V_89 = F_121 ( V_84 -> V_82 + V_96 ) ;
V_89 |= V_15 -> V_194 << V_195 ;
F_52 ( V_89 , V_84 -> V_82 + V_96 ) ;
if ( V_15 -> V_98 == V_99 ) {
V_98 = F_53 ( 0 , ( T_2 * ) V_84 -> V_82 , V_84 -> V_81 - 2 ) ;
F_52 ( V_98 , V_84 -> V_82 + V_84 -> V_81 - 2 ) ;
}
F_119 ( V_15 , V_84 ) ;
V_15 -> V_194 = ( V_15 -> V_194 + 1 ) % 64 ;
}
}
static void F_122 ( struct V_1 * V_15 , T_2 V_191 )
{
struct V_83 * V_84 , * V_196 ;
T_1 V_89 , V_98 ;
V_84 = F_116 ( & V_15 -> V_53 ) ;
if ( ! V_84 )
return;
do {
if ( F_117 ( V_84 ) -> V_191 == V_191 )
break;
if ( F_123 ( & V_15 -> V_53 , V_84 ) )
return;
} while ( ( V_84 = F_124 ( & V_15 -> V_53 , V_84 ) ) );
if ( V_15 -> V_188 &&
F_117 ( V_84 ) -> V_197 == V_15 -> V_188 ) {
F_60 ( V_15 -> V_3 , V_15 , V_189 ) ;
return;
}
V_196 = F_125 ( V_84 , V_25 ) ;
F_117 ( V_84 ) -> V_197 ++ ;
V_89 = F_121 ( V_196 -> V_82 + V_96 ) ;
V_89 &= V_198 ;
if ( V_15 -> V_101 & V_102 ) {
V_89 |= V_103 ;
V_15 -> V_101 &= ~ V_102 ;
}
V_89 |= ( V_15 -> V_110 << V_111 )
| ( V_191 << V_195 ) ;
F_52 ( V_89 , V_196 -> V_82 + V_96 ) ;
if ( V_15 -> V_98 == V_99 ) {
V_98 = F_53 ( 0 , ( T_2 * ) V_196 -> V_82 , V_196 -> V_81 - 2 ) ;
F_52 ( V_98 , V_196 -> V_82 + V_196 -> V_81 - 2 ) ;
}
F_119 ( V_15 , V_196 ) ;
}
int F_126 ( struct V_1 * V_15 )
{
struct V_83 * V_84 , * V_196 ;
struct V_24 * V_9 = V_15 -> V_9 ;
T_1 V_89 , V_98 ;
int V_199 = 0 ;
if ( V_9 -> V_44 != V_97 )
return - V_200 ;
while ( ( V_84 = V_15 -> V_201 ) && ( ! F_127 ( V_15 ) ) ) {
if ( V_15 -> V_188 &&
F_117 ( V_84 ) -> V_197 == V_15 -> V_188 ) {
F_60 ( V_15 -> V_3 , V_15 , V_189 ) ;
break;
}
V_196 = F_125 ( V_84 , V_25 ) ;
F_117 ( V_84 ) -> V_197 ++ ;
V_89 = F_121 ( V_196 -> V_82 + V_96 ) ;
V_89 &= V_198 ;
if ( V_15 -> V_101 & V_102 ) {
V_89 |= V_103 ;
V_15 -> V_101 &= ~ V_102 ;
}
V_89 |= ( V_15 -> V_110 << V_111 )
| ( V_15 -> V_194 << V_195 ) ;
F_52 ( V_89 , V_196 -> V_82 + V_96 ) ;
if ( V_15 -> V_98 == V_99 ) {
V_98 = F_53 ( 0 , ( T_2 * ) V_84 -> V_82 , V_196 -> V_81 - 2 ) ;
F_52 ( V_98 , V_84 -> V_82 + V_196 -> V_81 - 2 ) ;
}
F_119 ( V_15 , V_196 ) ;
F_128 () ;
F_117 ( V_84 ) -> V_191 = V_15 -> V_194 ;
V_15 -> V_194 = ( V_15 -> V_194 + 1 ) % 64 ;
if ( F_117 ( V_84 ) -> V_197 == 1 )
V_15 -> V_184 ++ ;
V_15 -> V_202 ++ ;
if ( F_123 ( & V_15 -> V_53 , V_84 ) )
V_15 -> V_201 = NULL ;
else
V_15 -> V_201 = F_124 ( & V_15 -> V_53 , V_84 ) ;
V_199 ++ ;
}
return V_199 ;
}
static int F_129 ( struct V_1 * V_15 )
{
int V_203 ;
if ( ! F_130 ( & V_15 -> V_53 ) )
V_15 -> V_201 = V_15 -> V_53 . V_204 ;
V_15 -> V_194 = V_15 -> V_192 ;
V_203 = F_126 ( V_15 ) ;
return V_203 ;
}
static void F_131 ( struct V_1 * V_15 )
{
T_1 V_89 = 0 ;
V_89 |= V_15 -> V_110 << V_111 ;
if ( V_15 -> V_101 & V_106 ) {
V_89 |= V_107 ;
V_15 -> V_101 |= V_108 ;
F_47 ( V_15 , V_89 ) ;
return;
}
if ( F_126 ( V_15 ) > 0 )
return;
V_89 |= V_109 ;
F_47 ( V_15 , V_89 ) ;
}
static void F_132 ( struct V_1 * V_15 )
{
struct V_56 * V_205 ;
T_1 V_89 ;
V_89 = V_206 ;
V_89 |= V_103 ;
V_205 = F_133 ( ( & V_15 -> V_207 ) -> V_208 , struct V_56 , V_41 ) ;
V_89 |= V_205 -> V_191 << V_111 ;
F_47 ( V_15 , V_89 ) ;
}
static inline int F_134 ( struct V_24 * V_9 , struct V_209 * V_210 , int V_81 , int V_94 , struct V_83 * V_84 )
{
struct V_2 * V_3 = F_48 ( V_9 ) -> V_15 -> V_3 ;
struct V_83 * * V_211 ;
int V_16 , V_212 = 0 ;
if ( F_135 ( F_51 ( V_84 , V_94 ) , V_210 -> V_213 , V_94 ) )
return - V_214 ;
V_212 += V_94 ;
V_81 -= V_94 ;
V_211 = & F_136 ( V_84 ) -> V_215 ;
while ( V_81 ) {
V_94 = F_49 (unsigned int, conn->mtu, len) ;
* V_211 = F_137 ( V_9 , V_94 , V_210 -> V_216 & V_217 , & V_16 ) ;
if ( ! * V_211 )
return V_16 ;
if ( F_135 ( F_51 ( * V_211 , V_94 ) , V_210 -> V_213 , V_94 ) )
return - V_214 ;
V_212 += V_94 ;
V_81 -= V_94 ;
V_211 = & ( * V_211 ) -> V_204 ;
}
return V_212 ;
}
struct V_83 * F_138 ( struct V_1 * V_15 , struct V_209 * V_210 , T_9 V_81 )
{
struct V_24 * V_9 = V_15 -> V_9 ;
struct V_2 * V_3 = V_15 -> V_3 ;
struct V_83 * V_84 ;
int V_16 , V_94 , V_95 = V_96 + 2 ;
struct V_90 * V_91 ;
F_26 ( L_13 , V_9 , ( int ) V_81 ) ;
V_94 = F_49 (unsigned int, (conn->mtu - hlen), len) ;
V_84 = F_137 ( V_9 , V_94 + V_95 ,
V_210 -> V_216 & V_217 , & V_16 ) ;
if ( ! V_84 )
return F_139 ( V_16 ) ;
V_91 = (struct V_90 * ) F_51 ( V_84 , V_96 ) ;
V_91 -> V_4 = F_15 ( V_15 -> V_6 ) ;
V_91 -> V_81 = F_15 ( V_81 + ( V_95 - V_96 ) ) ;
F_52 ( V_15 -> V_11 , F_51 ( V_84 , 2 ) ) ;
V_16 = F_134 ( V_9 , V_210 , V_81 , V_94 , V_84 ) ;
if ( F_140 ( V_16 < 0 ) ) {
F_87 ( V_84 ) ;
return F_139 ( V_16 ) ;
}
return V_84 ;
}
struct V_83 * F_141 ( struct V_1 * V_15 , struct V_209 * V_210 , T_9 V_81 )
{
struct V_24 * V_9 = V_15 -> V_9 ;
struct V_2 * V_3 = V_15 -> V_3 ;
struct V_83 * V_84 ;
int V_16 , V_94 , V_95 = V_96 ;
struct V_90 * V_91 ;
F_26 ( L_13 , V_9 , ( int ) V_81 ) ;
V_94 = F_49 (unsigned int, (conn->mtu - hlen), len) ;
V_84 = F_137 ( V_9 , V_94 + V_95 ,
V_210 -> V_216 & V_217 , & V_16 ) ;
if ( ! V_84 )
return F_139 ( V_16 ) ;
V_91 = (struct V_90 * ) F_51 ( V_84 , V_96 ) ;
V_91 -> V_4 = F_15 ( V_15 -> V_6 ) ;
V_91 -> V_81 = F_15 ( V_81 + ( V_95 - V_96 ) ) ;
V_16 = F_134 ( V_9 , V_210 , V_81 , V_94 , V_84 ) ;
if ( F_140 ( V_16 < 0 ) ) {
F_87 ( V_84 ) ;
return F_139 ( V_16 ) ;
}
return V_84 ;
}
struct V_83 * F_142 ( struct V_1 * V_15 , struct V_209 * V_210 , T_9 V_81 , T_1 V_89 , T_1 V_218 )
{
struct V_24 * V_9 = V_15 -> V_9 ;
struct V_2 * V_3 = V_15 -> V_3 ;
struct V_83 * V_84 ;
int V_16 , V_94 , V_95 = V_96 + 2 ;
struct V_90 * V_91 ;
F_26 ( L_13 , V_9 , ( int ) V_81 ) ;
if ( ! V_3 )
return F_139 ( - V_200 ) ;
if ( V_218 )
V_95 += 2 ;
if ( V_15 -> V_98 == V_99 )
V_95 += 2 ;
V_94 = F_49 (unsigned int, (conn->mtu - hlen), len) ;
V_84 = F_137 ( V_9 , V_94 + V_95 ,
V_210 -> V_216 & V_217 , & V_16 ) ;
if ( ! V_84 )
return F_139 ( V_16 ) ;
V_91 = (struct V_90 * ) F_51 ( V_84 , V_96 ) ;
V_91 -> V_4 = F_15 ( V_15 -> V_6 ) ;
V_91 -> V_81 = F_15 ( V_81 + ( V_95 - V_96 ) ) ;
F_52 ( V_89 , F_51 ( V_84 , 2 ) ) ;
if ( V_218 )
F_52 ( V_218 , F_51 ( V_84 , 2 ) ) ;
V_16 = F_134 ( V_9 , V_210 , V_81 , V_94 , V_84 ) ;
if ( F_140 ( V_16 < 0 ) ) {
F_87 ( V_84 ) ;
return F_139 ( V_16 ) ;
}
if ( V_15 -> V_98 == V_99 )
F_52 ( 0 , F_51 ( V_84 , 2 ) ) ;
F_117 ( V_84 ) -> V_197 = 0 ;
return V_84 ;
}
int F_143 ( struct V_1 * V_15 , struct V_209 * V_210 , T_9 V_81 )
{
struct V_83 * V_84 ;
struct V_219 V_220 ;
T_1 V_89 ;
T_9 V_221 = 0 ;
F_144 ( & V_220 ) ;
V_89 = V_222 ;
V_84 = F_142 ( V_15 , V_210 , V_15 -> V_223 , V_89 , V_81 ) ;
if ( F_96 ( V_84 ) )
return F_97 ( V_84 ) ;
F_145 ( & V_220 , V_84 ) ;
V_81 -= V_15 -> V_223 ;
V_221 += V_15 -> V_223 ;
while ( V_81 > 0 ) {
T_9 V_224 ;
if ( V_81 > V_15 -> V_223 ) {
V_89 = V_225 ;
V_224 = V_15 -> V_223 ;
} else {
V_89 = V_226 ;
V_224 = V_81 ;
}
V_84 = F_142 ( V_15 , V_210 , V_224 , V_89 , 0 ) ;
if ( F_96 ( V_84 ) ) {
F_34 ( & V_220 ) ;
return F_97 ( V_84 ) ;
}
F_145 ( & V_220 , V_84 ) ;
V_81 -= V_224 ;
V_221 += V_224 ;
}
F_146 ( & V_220 , & V_15 -> V_53 ) ;
if ( V_15 -> V_201 == NULL )
V_15 -> V_201 = V_220 . V_204 ;
return V_221 ;
}
static void F_147 ( struct V_24 * V_9 )
{
struct V_24 * V_43 = F_12 ( V_9 ) -> V_43 ;
struct V_1 * V_15 = F_48 ( V_9 ) -> V_15 ;
F_26 ( L_14 , V_9 , V_43 ) ;
V_15 -> V_50 = 0 ;
F_29 ( V_9 ) ;
if ( ! V_43 ) {
V_9 -> V_44 = V_97 ;
V_9 -> V_49 ( V_9 ) ;
} else {
V_43 -> V_48 ( V_43 , 0 ) ;
}
}
static void F_148 ( struct V_2 * V_3 , struct V_83 * V_84 )
{
struct V_83 * V_227 ;
struct V_1 * V_15 ;
F_26 ( L_5 , V_3 ) ;
F_5 ( & V_3 -> V_8 ) ;
F_2 (chan, &conn->chan_l, list) {
struct V_24 * V_9 = V_15 -> V_9 ;
if ( V_9 -> V_29 != V_64 )
continue;
if ( V_84 -> V_9 == V_9 )
continue;
V_227 = F_125 ( V_84 , V_25 ) ;
if ( ! V_227 )
continue;
if ( F_149 ( V_9 , V_227 ) )
F_87 ( V_227 ) ;
}
F_7 ( & V_3 -> V_8 ) ;
}
static struct V_83 * F_44 ( struct V_2 * V_3 ,
T_2 V_80 , T_2 V_10 , T_1 V_228 , void * V_82 )
{
struct V_83 * V_84 , * * V_211 ;
struct V_229 * V_230 ;
struct V_90 * V_91 ;
int V_81 , V_94 ;
F_26 ( L_15 ,
V_3 , V_80 , V_10 , V_228 ) ;
V_81 = V_96 + V_231 + V_228 ;
V_94 = F_49 (unsigned int, conn->mtu, len) ;
V_84 = F_50 ( V_94 , V_25 ) ;
if ( ! V_84 )
return NULL ;
V_91 = (struct V_90 * ) F_51 ( V_84 , V_96 ) ;
V_91 -> V_81 = F_15 ( V_231 + V_228 ) ;
if ( V_3 -> V_32 -> type == V_33 )
V_91 -> V_4 = F_15 ( V_232 ) ;
else
V_91 -> V_4 = F_15 ( V_40 ) ;
V_230 = (struct V_229 * ) F_51 ( V_84 , V_231 ) ;
V_230 -> V_80 = V_80 ;
V_230 -> V_10 = V_10 ;
V_230 -> V_81 = F_15 ( V_228 ) ;
if ( V_228 ) {
V_94 -= V_96 + V_231 ;
memcpy ( F_51 ( V_84 , V_94 ) , V_82 , V_94 ) ;
V_82 += V_94 ;
}
V_81 -= V_84 -> V_81 ;
V_211 = & F_136 ( V_84 ) -> V_215 ;
while ( V_81 ) {
V_94 = F_49 (unsigned int, conn->mtu, len) ;
* V_211 = F_50 ( V_94 , V_25 ) ;
if ( ! * V_211 )
goto V_233;
memcpy ( F_51 ( * V_211 , V_94 ) , V_82 , V_94 ) ;
V_81 -= V_94 ;
V_82 += V_94 ;
V_211 = & ( * V_211 ) -> V_204 ;
}
return V_84 ;
V_233:
F_87 ( V_84 ) ;
return NULL ;
}
static inline int F_150 ( void * * V_234 , int * type , int * V_235 , unsigned long * V_236 )
{
struct V_237 * V_238 = * V_234 ;
int V_81 ;
V_81 = V_239 + V_238 -> V_81 ;
* V_234 += V_81 ;
* type = V_238 -> type ;
* V_235 = V_238 -> V_81 ;
switch ( V_238 -> V_81 ) {
case 1 :
* V_236 = * ( ( T_2 * ) V_238 -> V_236 ) ;
break;
case 2 :
* V_236 = F_121 ( V_238 -> V_236 ) ;
break;
case 4 :
* V_236 = F_151 ( V_238 -> V_236 ) ;
break;
default:
* V_236 = ( unsigned long ) V_238 -> V_236 ;
break;
}
F_26 ( L_16 , * type , V_238 -> V_81 , * V_236 ) ;
return V_81 ;
}
static void F_152 ( void * * V_234 , T_2 type , T_2 V_81 , unsigned long V_236 )
{
struct V_237 * V_238 = * V_234 ;
F_26 ( L_16 , type , V_81 , V_236 ) ;
V_238 -> type = type ;
V_238 -> V_81 = V_81 ;
switch ( V_81 ) {
case 1 :
* ( ( T_2 * ) V_238 -> V_236 ) = V_236 ;
break;
case 2 :
F_52 ( V_236 , V_238 -> V_236 ) ;
break;
case 4 :
F_153 ( V_236 , V_238 -> V_236 ) ;
break;
default:
memcpy ( V_238 -> V_236 , ( void * ) V_236 , V_81 ) ;
break;
}
* V_234 += V_239 + V_81 ;
}
static void F_154 ( unsigned long V_168 )
{
struct V_1 * V_15 = ( void * ) V_168 ;
F_6 ( V_15 -> V_9 ) ;
F_131 ( V_15 ) ;
F_62 ( V_15 -> V_9 ) ;
}
static inline void F_155 ( struct V_1 * V_15 )
{
struct V_24 * V_9 = V_15 -> V_9 ;
V_15 -> V_192 = 0 ;
V_15 -> V_184 = 0 ;
V_15 -> V_110 = 0 ;
V_15 -> V_240 = 0 ;
V_15 -> V_202 = 0 ;
F_85 ( & V_15 -> V_59 , F_114 ,
( unsigned long ) V_15 ) ;
F_85 ( & V_15 -> V_60 , F_112 ,
( unsigned long ) V_15 ) ;
F_85 ( & V_15 -> V_61 , F_154 , ( unsigned long ) V_15 ) ;
F_144 ( & V_15 -> V_62 ) ;
F_144 ( & V_15 -> V_63 ) ;
F_84 ( & V_15 -> V_207 ) ;
F_156 ( & V_15 -> V_241 , V_242 ) ;
V_9 -> V_243 = V_244 ;
}
static inline T_6 F_157 ( T_6 V_54 , T_5 V_245 )
{
switch ( V_54 ) {
case V_132 :
case V_55 :
if ( F_59 ( V_54 , V_245 ) )
return V_54 ;
default:
return V_246 ;
}
}
static int F_66 ( struct V_1 * V_15 , void * V_82 )
{
struct V_247 * V_117 = V_82 ;
struct V_248 V_249 = { . V_54 = V_15 -> V_54 } ;
void * V_234 = V_117 -> V_82 ;
F_26 ( L_11 , V_15 ) ;
if ( V_15 -> V_155 || V_15 -> V_250 )
goto V_19;
switch ( V_15 -> V_54 ) {
case V_132 :
case V_55 :
if ( V_15 -> V_50 & V_137 )
break;
default:
V_15 -> V_54 = F_157 ( V_249 . V_54 , V_15 -> V_3 -> V_126 ) ;
break;
}
V_19:
if ( V_15 -> V_251 != V_37 )
F_152 ( & V_234 , V_252 , 2 , V_15 -> V_251 ) ;
switch ( V_15 -> V_54 ) {
case V_246 :
if ( ! ( V_15 -> V_3 -> V_126 & V_130 ) &&
! ( V_15 -> V_3 -> V_126 & V_131 ) )
break;
V_249 . V_54 = V_246 ;
V_249 . V_253 = 0 ;
V_249 . V_254 = 0 ;
V_249 . V_255 = 0 ;
V_249 . V_256 = 0 ;
V_249 . V_257 = 0 ;
F_152 ( & V_234 , V_258 , sizeof( V_249 ) ,
( unsigned long ) & V_249 ) ;
break;
case V_55 :
V_249 . V_54 = V_55 ;
V_249 . V_253 = V_15 -> V_259 ;
V_249 . V_254 = V_15 -> V_260 ;
V_249 . V_255 = 0 ;
V_249 . V_256 = 0 ;
V_249 . V_257 = F_15 ( V_261 ) ;
if ( V_261 > V_15 -> V_3 -> V_172 - 10 )
V_249 . V_257 = F_15 ( V_15 -> V_3 -> V_172 - 10 ) ;
F_152 ( & V_234 , V_258 , sizeof( V_249 ) ,
( unsigned long ) & V_249 ) ;
if ( ! ( V_15 -> V_3 -> V_126 & V_262 ) )
break;
if ( V_15 -> V_98 == V_263 ||
V_15 -> V_50 & V_264 ) {
V_15 -> V_98 = V_263 ;
F_152 ( & V_234 , V_265 , 1 , V_15 -> V_98 ) ;
}
break;
case V_132 :
V_249 . V_54 = V_132 ;
V_249 . V_253 = 0 ;
V_249 . V_254 = 0 ;
V_249 . V_255 = 0 ;
V_249 . V_256 = 0 ;
V_249 . V_257 = F_15 ( V_261 ) ;
if ( V_261 > V_15 -> V_3 -> V_172 - 10 )
V_249 . V_257 = F_15 ( V_15 -> V_3 -> V_172 - 10 ) ;
F_152 ( & V_234 , V_258 , sizeof( V_249 ) ,
( unsigned long ) & V_249 ) ;
if ( ! ( V_15 -> V_3 -> V_126 & V_262 ) )
break;
if ( V_15 -> V_98 == V_263 ||
V_15 -> V_50 & V_264 ) {
V_15 -> V_98 = V_263 ;
F_152 ( & V_234 , V_265 , 1 , V_15 -> V_98 ) ;
}
break;
}
V_117 -> V_6 = F_15 ( V_15 -> V_6 ) ;
V_117 -> V_85 = F_15 ( 0 ) ;
return V_234 - V_82 ;
}
static int F_158 ( struct V_1 * V_15 , void * V_82 )
{
struct V_266 * V_141 = V_82 ;
void * V_234 = V_141 -> V_82 ;
void * V_117 = V_15 -> V_267 ;
int V_81 = V_15 -> V_268 ;
int type , V_269 , V_235 ;
unsigned long V_236 ;
struct V_248 V_249 = { . V_54 = V_246 } ;
T_1 V_172 = V_37 ;
T_1 V_144 = V_270 ;
F_26 ( L_11 , V_15 ) ;
while ( V_81 >= V_239 ) {
V_81 -= F_150 ( & V_117 , & type , & V_235 , & V_236 ) ;
V_269 = type & V_271 ;
type &= V_272 ;
switch ( type ) {
case V_252 :
V_172 = V_236 ;
break;
case V_273 :
V_15 -> V_274 = V_236 ;
break;
case V_275 :
break;
case V_258 :
if ( V_235 == sizeof( V_249 ) )
memcpy ( & V_249 , ( void * ) V_236 , V_235 ) ;
break;
case V_265 :
if ( V_236 == V_263 )
V_15 -> V_50 |= V_264 ;
break;
default:
if ( V_269 )
break;
V_144 = V_276 ;
* ( ( T_2 * ) V_234 ++ ) = type ;
break;
}
}
if ( V_15 -> V_250 || V_15 -> V_155 > 1 )
goto V_19;
switch ( V_15 -> V_54 ) {
case V_132 :
case V_55 :
if ( ! ( V_15 -> V_50 & V_137 ) ) {
V_15 -> V_54 = F_157 ( V_249 . V_54 ,
V_15 -> V_3 -> V_126 ) ;
break;
}
if ( V_15 -> V_54 != V_249 . V_54 )
return - V_277 ;
break;
}
V_19:
if ( V_15 -> V_54 != V_249 . V_54 ) {
V_144 = V_278 ;
V_249 . V_54 = V_15 -> V_54 ;
if ( V_15 -> V_250 == 1 )
return - V_277 ;
F_152 ( & V_234 , V_258 ,
sizeof( V_249 ) , ( unsigned long ) & V_249 ) ;
}
if ( V_144 == V_270 ) {
if ( V_172 < V_279 )
V_144 = V_278 ;
else {
V_15 -> V_34 = V_172 ;
V_15 -> V_50 |= V_280 ;
}
F_152 ( & V_234 , V_252 , 2 , V_15 -> V_34 ) ;
switch ( V_249 . V_54 ) {
case V_246 :
V_15 -> V_98 = V_263 ;
V_15 -> V_50 |= V_281 ;
break;
case V_55 :
V_15 -> V_282 = V_249 . V_253 ;
V_15 -> V_188 = V_249 . V_254 ;
if ( F_159 ( V_249 . V_257 ) > V_15 -> V_3 -> V_172 - 10 )
V_249 . V_257 = F_15 ( V_15 -> V_3 -> V_172 - 10 ) ;
V_15 -> V_223 = F_159 ( V_249 . V_257 ) ;
V_249 . V_255 =
F_159 ( V_283 ) ;
V_249 . V_256 =
F_159 ( V_284 ) ;
V_15 -> V_50 |= V_281 ;
F_152 ( & V_234 , V_258 ,
sizeof( V_249 ) , ( unsigned long ) & V_249 ) ;
break;
case V_132 :
if ( F_159 ( V_249 . V_257 ) > V_15 -> V_3 -> V_172 - 10 )
V_249 . V_257 = F_15 ( V_15 -> V_3 -> V_172 - 10 ) ;
V_15 -> V_223 = F_159 ( V_249 . V_257 ) ;
V_15 -> V_50 |= V_281 ;
F_152 ( & V_234 , V_258 ,
sizeof( V_249 ) , ( unsigned long ) & V_249 ) ;
break;
default:
V_144 = V_278 ;
memset ( & V_249 , 0 , sizeof( V_249 ) ) ;
V_249 . V_54 = V_15 -> V_54 ;
}
if ( V_144 == V_270 )
V_15 -> V_50 |= V_51 ;
}
V_141 -> V_7 = F_15 ( V_15 -> V_6 ) ;
V_141 -> V_144 = F_15 ( V_144 ) ;
V_141 -> V_85 = F_15 ( 0x0000 ) ;
return V_234 - V_82 ;
}
static int F_160 ( struct V_1 * V_15 , void * V_141 , int V_81 , void * V_82 , T_1 * V_144 )
{
struct V_247 * V_117 = V_82 ;
void * V_234 = V_117 -> V_82 ;
int type , V_235 ;
unsigned long V_236 ;
struct V_248 V_249 ;
F_26 ( L_17 , V_15 , V_141 , V_81 , V_82 ) ;
while ( V_81 >= V_239 ) {
V_81 -= F_150 ( & V_141 , & type , & V_235 , & V_236 ) ;
switch ( type ) {
case V_252 :
if ( V_236 < V_279 ) {
* V_144 = V_278 ;
V_15 -> V_251 = V_279 ;
} else
V_15 -> V_251 = V_236 ;
F_152 ( & V_234 , V_252 , 2 , V_15 -> V_251 ) ;
break;
case V_273 :
V_15 -> V_274 = V_236 ;
F_152 ( & V_234 , V_273 ,
2 , V_15 -> V_274 ) ;
break;
case V_258 :
if ( V_235 == sizeof( V_249 ) )
memcpy ( & V_249 , ( void * ) V_236 , V_235 ) ;
if ( ( V_15 -> V_50 & V_137 ) &&
V_249 . V_54 != V_15 -> V_54 )
return - V_277 ;
V_15 -> V_98 = 0 ;
F_152 ( & V_234 , V_258 ,
sizeof( V_249 ) , ( unsigned long ) & V_249 ) ;
break;
}
}
if ( V_15 -> V_54 == V_246 && V_15 -> V_54 != V_249 . V_54 )
return - V_277 ;
V_15 -> V_54 = V_249 . V_54 ;
if ( * V_144 == V_270 ) {
switch ( V_249 . V_54 ) {
case V_55 :
V_15 -> V_255 = F_159 ( V_249 . V_255 ) ;
V_15 -> V_256 = F_159 ( V_249 . V_256 ) ;
V_15 -> V_285 = F_159 ( V_249 . V_257 ) ;
break;
case V_132 :
V_15 -> V_285 = F_159 ( V_249 . V_257 ) ;
}
}
V_117 -> V_6 = F_15 ( V_15 -> V_6 ) ;
V_117 -> V_85 = F_15 ( 0x0000 ) ;
return V_234 - V_82 ;
}
static int F_161 ( struct V_1 * V_15 , void * V_82 , T_1 V_144 , T_1 V_85 )
{
struct V_266 * V_141 = V_82 ;
void * V_234 = V_141 -> V_82 ;
F_26 ( L_11 , V_15 ) ;
V_141 -> V_7 = F_15 ( V_15 -> V_6 ) ;
V_141 -> V_144 = F_15 ( V_144 ) ;
V_141 -> V_85 = F_15 ( V_85 ) ;
return V_234 - V_82 ;
}
void F_162 ( struct V_1 * V_15 )
{
struct V_140 V_141 ;
struct V_2 * V_3 = V_15 -> V_3 ;
T_2 V_142 [ 128 ] ;
V_141 . V_7 = F_15 ( V_15 -> V_6 ) ;
V_141 . V_6 = F_15 ( V_15 -> V_7 ) ;
V_141 . V_144 = F_15 ( V_149 ) ;
V_141 . V_146 = F_15 ( V_150 ) ;
F_43 ( V_3 , V_15 -> V_10 ,
V_152 , sizeof( V_141 ) , & V_141 ) ;
if ( V_15 -> V_50 & V_153 )
return;
V_15 -> V_50 |= V_153 ;
F_43 ( V_3 , F_40 ( V_3 ) , V_154 ,
F_66 ( V_15 , V_142 ) , V_142 ) ;
V_15 -> V_155 ++ ;
}
static void F_163 ( struct V_1 * V_15 , void * V_141 , int V_81 )
{
int type , V_235 ;
unsigned long V_236 ;
struct V_248 V_249 ;
F_26 ( L_18 , V_15 , V_141 , V_81 ) ;
if ( ( V_15 -> V_54 != V_55 ) && ( V_15 -> V_54 != V_132 ) )
return;
while ( V_81 >= V_239 ) {
V_81 -= F_150 ( & V_141 , & type , & V_235 , & V_236 ) ;
switch ( type ) {
case V_258 :
if ( V_235 == sizeof( V_249 ) )
memcpy ( & V_249 , ( void * ) V_236 , V_235 ) ;
goto V_19;
}
}
V_19:
switch ( V_249 . V_54 ) {
case V_55 :
V_15 -> V_255 = F_159 ( V_249 . V_255 ) ;
V_15 -> V_256 = F_159 ( V_249 . V_256 ) ;
V_15 -> V_285 = F_159 ( V_249 . V_257 ) ;
break;
case V_132 :
V_15 -> V_285 = F_159 ( V_249 . V_257 ) ;
}
}
static inline int F_164 ( struct V_2 * V_3 , struct V_229 * V_230 , T_2 * V_82 )
{
struct V_286 * V_287 = (struct V_286 * ) V_82 ;
if ( V_287 -> V_288 != 0x0000 )
return 0 ;
if ( ( V_3 -> V_113 & V_114 ) &&
V_230 -> V_10 == V_3 -> V_121 ) {
F_35 ( & V_3 -> V_122 ) ;
V_3 -> V_113 |= V_115 ;
V_3 -> V_121 = 0 ;
F_61 ( V_3 ) ;
}
return 0 ;
}
static inline int F_165 ( struct V_2 * V_3 , struct V_229 * V_230 , T_2 * V_82 )
{
struct V_116 * V_117 = (struct V_116 * ) V_82 ;
struct V_140 V_141 ;
struct V_1 * V_15 = NULL , * V_159 ;
struct V_24 * V_43 , * V_9 = NULL ;
int V_144 , V_146 = V_150 ;
T_1 V_6 = 0 , V_7 = F_166 ( V_117 -> V_7 ) ;
T_3 V_11 = V_117 -> V_11 ;
F_26 ( L_19 , V_11 , V_7 ) ;
V_159 = F_90 ( V_160 , V_11 , V_3 -> V_12 ) ;
if ( ! V_159 ) {
V_144 = V_289 ;
goto V_290;
}
V_43 = V_159 -> V_9 ;
F_6 ( V_43 ) ;
if ( V_11 != F_15 ( 0x0001 ) &&
! F_167 ( V_3 -> V_32 ) ) {
V_3 -> V_28 = 0x05 ;
V_144 = V_291 ;
goto V_292;
}
V_144 = V_293 ;
if ( F_69 ( V_43 ) ) {
F_26 ( L_7 , V_43 -> V_161 ) ;
goto V_292;
}
V_9 = F_70 ( F_71 ( V_43 ) , NULL , V_163 , V_25 ) ;
if ( ! V_9 )
goto V_292;
V_15 = F_19 ( V_9 ) ;
if ( ! V_15 ) {
F_72 ( V_9 ) ;
goto V_292;
}
F_48 ( V_9 ) -> V_15 = V_15 ;
F_14 ( & V_3 -> V_8 ) ;
if ( F_1 ( V_3 , V_7 ) ) {
F_16 ( & V_3 -> V_8 ) ;
F_32 ( V_9 , V_46 ) ;
F_72 ( V_9 ) ;
goto V_292;
}
F_73 ( V_3 -> V_32 ) ;
F_74 ( V_9 , V_43 ) ;
F_75 ( & F_12 ( V_9 ) -> V_12 , V_3 -> V_12 ) ;
F_75 ( & F_12 ( V_9 ) -> V_164 , V_3 -> V_164 ) ;
V_15 -> V_11 = V_11 ;
V_15 -> V_6 = V_7 ;
F_76 ( V_43 , V_9 ) ;
F_25 ( V_3 , V_15 ) ;
V_6 = V_15 -> V_7 ;
F_77 ( V_9 , V_9 -> V_165 ) ;
V_15 -> V_10 = V_230 -> V_10 ;
if ( V_3 -> V_113 & V_115 ) {
if ( F_38 ( V_15 ) ) {
if ( F_12 ( V_9 ) -> V_143 ) {
V_9 -> V_44 = V_139 ;
V_144 = V_145 ;
V_146 = V_147 ;
V_43 -> V_48 ( V_43 , 0 ) ;
} else {
V_9 -> V_44 = V_148 ;
V_144 = V_149 ;
V_146 = V_150 ;
}
} else {
V_9 -> V_44 = V_139 ;
V_144 = V_145 ;
V_146 = V_151 ;
}
} else {
V_9 -> V_44 = V_139 ;
V_144 = V_145 ;
V_146 = V_150 ;
}
F_16 ( & V_3 -> V_8 ) ;
V_292:
F_62 ( V_43 ) ;
V_290:
V_141 . V_7 = F_15 ( V_7 ) ;
V_141 . V_6 = F_15 ( V_6 ) ;
V_141 . V_144 = F_15 ( V_144 ) ;
V_141 . V_146 = F_15 ( V_146 ) ;
F_43 ( V_3 , V_230 -> V_10 , V_152 , sizeof( V_141 ) , & V_141 ) ;
if ( V_144 == V_145 && V_146 == V_150 ) {
struct V_119 V_294 ;
V_294 . type = F_15 ( V_120 ) ;
V_3 -> V_113 |= V_114 ;
V_3 -> V_121 = F_40 ( V_3 ) ;
F_57 ( & V_3 -> V_122 , V_123 +
F_58 ( V_124 ) ) ;
F_43 ( V_3 , V_3 -> V_121 ,
V_125 , sizeof( V_294 ) , & V_294 ) ;
}
if ( V_15 && ! ( V_15 -> V_50 & V_153 ) &&
V_144 == V_149 ) {
T_2 V_142 [ 128 ] ;
V_15 -> V_50 |= V_153 ;
F_43 ( V_3 , F_40 ( V_3 ) , V_154 ,
F_66 ( V_15 , V_142 ) , V_142 ) ;
V_15 -> V_155 ++ ;
}
return 0 ;
}
static inline int F_168 ( struct V_2 * V_3 , struct V_229 * V_230 , T_2 * V_82 )
{
struct V_140 * V_141 = (struct V_140 * ) V_82 ;
T_1 V_7 , V_6 , V_144 , V_146 ;
struct V_1 * V_15 ;
struct V_24 * V_9 ;
T_2 V_117 [ 128 ] ;
V_7 = F_166 ( V_141 -> V_7 ) ;
V_6 = F_166 ( V_141 -> V_6 ) ;
V_144 = F_166 ( V_141 -> V_144 ) ;
V_146 = F_166 ( V_141 -> V_146 ) ;
F_26 ( L_20 , V_6 , V_7 , V_144 , V_146 ) ;
if ( V_7 ) {
V_15 = F_4 ( V_3 , V_7 ) ;
if ( ! V_15 )
return - V_214 ;
} else {
V_15 = F_9 ( V_3 , V_230 -> V_10 ) ;
if ( ! V_15 )
return - V_214 ;
}
V_9 = V_15 -> V_9 ;
switch ( V_144 ) {
case V_149 :
V_9 -> V_44 = V_148 ;
V_15 -> V_10 = 0 ;
V_15 -> V_6 = V_6 ;
V_15 -> V_50 &= ~ V_112 ;
if ( V_15 -> V_50 & V_153 )
break;
V_15 -> V_50 |= V_153 ;
F_43 ( V_3 , F_40 ( V_3 ) , V_154 ,
F_66 ( V_15 , V_117 ) , V_117 ) ;
V_15 -> V_155 ++ ;
break;
case V_145 :
V_15 -> V_50 |= V_112 ;
break;
default:
if ( F_169 ( V_9 ) ) {
V_9 -> V_44 = V_135 ;
F_29 ( V_9 ) ;
F_77 ( V_9 , V_183 / 5 ) ;
break;
}
F_28 ( V_15 , V_277 ) ;
break;
}
F_62 ( V_9 ) ;
return 0 ;
}
static inline void F_170 ( struct V_1 * V_15 )
{
struct V_92 * V_93 = F_48 ( V_15 -> V_9 ) ;
if ( V_15 -> V_54 != V_55 && V_15 -> V_54 != V_132 )
V_15 -> V_98 = V_263 ;
else if ( ! ( V_93 -> V_15 -> V_50 & V_264 ) )
V_15 -> V_98 = V_99 ;
}
static inline int F_171 ( struct V_2 * V_3 , struct V_229 * V_230 , T_1 V_295 , T_2 * V_82 )
{
struct V_247 * V_117 = (struct V_247 * ) V_82 ;
T_1 V_6 , V_85 ;
T_2 V_141 [ 64 ] ;
struct V_1 * V_15 ;
struct V_24 * V_9 ;
int V_81 ;
V_6 = F_166 ( V_117 -> V_6 ) ;
V_85 = F_166 ( V_117 -> V_85 ) ;
F_26 ( L_21 , V_6 , V_85 ) ;
V_15 = F_4 ( V_3 , V_6 ) ;
if ( ! V_15 )
return - V_296 ;
V_9 = V_15 -> V_9 ;
if ( V_9 -> V_44 != V_148 && V_9 -> V_44 != V_139 ) {
struct V_286 V_287 ;
V_287 . V_288 = F_15 ( 0x0002 ) ;
F_43 ( V_3 , V_230 -> V_10 , V_297 ,
sizeof( V_287 ) , & V_287 ) ;
goto V_298;
}
V_81 = V_295 - sizeof( * V_117 ) ;
if ( V_81 < 0 || V_15 -> V_268 + V_81 > sizeof( V_15 -> V_267 ) ) {
F_43 ( V_3 , V_230 -> V_10 , V_299 ,
F_161 ( V_15 , V_141 ,
V_300 , V_85 ) , V_141 ) ;
goto V_298;
}
memcpy ( V_15 -> V_267 + V_15 -> V_268 , V_117 -> V_82 , V_81 ) ;
V_15 -> V_268 += V_81 ;
if ( V_85 & 0x0001 ) {
F_43 ( V_3 , V_230 -> V_10 , V_299 ,
F_161 ( V_15 , V_141 ,
V_270 , 0x0001 ) , V_141 ) ;
goto V_298;
}
V_81 = F_158 ( V_15 , V_141 ) ;
if ( V_81 < 0 ) {
F_60 ( V_3 , V_15 , V_138 ) ;
goto V_298;
}
F_43 ( V_3 , V_230 -> V_10 , V_299 , V_81 , V_141 ) ;
V_15 -> V_250 ++ ;
V_15 -> V_268 = 0 ;
if ( ! ( V_15 -> V_50 & V_51 ) )
goto V_298;
if ( V_15 -> V_50 & V_52 ) {
F_170 ( V_15 ) ;
V_9 -> V_44 = V_97 ;
V_15 -> V_194 = 0 ;
V_15 -> V_301 = 0 ;
F_144 ( & V_15 -> V_53 ) ;
if ( V_15 -> V_54 == V_55 )
F_155 ( V_15 ) ;
F_147 ( V_9 ) ;
goto V_298;
}
if ( ! ( V_15 -> V_50 & V_153 ) ) {
T_2 V_142 [ 64 ] ;
V_15 -> V_50 |= V_153 ;
F_43 ( V_3 , F_40 ( V_3 ) , V_154 ,
F_66 ( V_15 , V_142 ) , V_142 ) ;
V_15 -> V_155 ++ ;
}
V_298:
F_62 ( V_9 ) ;
return 0 ;
}
static inline int F_172 ( struct V_2 * V_3 , struct V_229 * V_230 , T_2 * V_82 )
{
struct V_266 * V_141 = (struct V_266 * ) V_82 ;
T_1 V_7 , V_85 , V_144 ;
struct V_1 * V_15 ;
struct V_24 * V_9 ;
int V_81 = V_230 -> V_81 - sizeof( * V_141 ) ;
V_7 = F_166 ( V_141 -> V_7 ) ;
V_85 = F_166 ( V_141 -> V_85 ) ;
V_144 = F_166 ( V_141 -> V_144 ) ;
F_26 ( L_22 ,
V_7 , V_85 , V_144 ) ;
V_15 = F_4 ( V_3 , V_7 ) ;
if ( ! V_15 )
return 0 ;
V_9 = V_15 -> V_9 ;
switch ( V_144 ) {
case V_270 :
F_163 ( V_15 , V_141 -> V_82 , V_81 ) ;
break;
case V_278 :
if ( V_15 -> V_250 <= V_302 ) {
char V_117 [ 64 ] ;
if ( V_81 > sizeof( V_117 ) - sizeof( struct V_247 ) ) {
F_60 ( V_3 , V_15 , V_138 ) ;
goto V_19;
}
V_144 = V_270 ;
V_81 = F_160 ( V_15 , V_141 -> V_82 , V_81 ,
V_117 , & V_144 ) ;
if ( V_81 < 0 ) {
F_60 ( V_3 , V_15 , V_138 ) ;
goto V_19;
}
F_43 ( V_3 , F_40 ( V_3 ) ,
V_154 , V_81 , V_117 ) ;
V_15 -> V_155 ++ ;
if ( V_144 != V_270 )
goto V_19;
break;
}
default:
V_9 -> V_47 = V_138 ;
F_77 ( V_9 , V_183 * 5 ) ;
F_60 ( V_3 , V_15 , V_138 ) ;
goto V_19;
}
if ( V_85 & 0x01 )
goto V_19;
V_15 -> V_50 |= V_52 ;
if ( V_15 -> V_50 & V_51 ) {
F_170 ( V_15 ) ;
V_9 -> V_44 = V_97 ;
V_15 -> V_194 = 0 ;
V_15 -> V_301 = 0 ;
F_144 ( & V_15 -> V_53 ) ;
if ( V_15 -> V_54 == V_55 )
F_155 ( V_15 ) ;
F_147 ( V_9 ) ;
}
V_19:
F_62 ( V_9 ) ;
return 0 ;
}
static inline int F_173 ( struct V_2 * V_3 , struct V_229 * V_230 , T_2 * V_82 )
{
struct V_133 * V_117 = (struct V_133 * ) V_82 ;
struct V_303 V_141 ;
T_1 V_6 , V_7 ;
struct V_1 * V_15 ;
struct V_24 * V_9 ;
V_7 = F_166 ( V_117 -> V_7 ) ;
V_6 = F_166 ( V_117 -> V_6 ) ;
F_26 ( L_23 , V_7 , V_6 ) ;
V_15 = F_4 ( V_3 , V_6 ) ;
if ( ! V_15 )
return 0 ;
V_9 = V_15 -> V_9 ;
V_141 . V_6 = F_15 ( V_15 -> V_7 ) ;
V_141 . V_7 = F_15 ( V_15 -> V_6 ) ;
F_43 ( V_3 , V_230 -> V_10 , V_304 , sizeof( V_141 ) , & V_141 ) ;
V_9 -> V_305 = V_306 ;
if ( F_169 ( V_9 ) ) {
V_9 -> V_44 = V_135 ;
F_29 ( V_9 ) ;
F_77 ( V_9 , V_183 / 5 ) ;
F_62 ( V_9 ) ;
return 0 ;
}
F_28 ( V_15 , V_138 ) ;
F_62 ( V_9 ) ;
F_72 ( V_9 ) ;
return 0 ;
}
static inline int F_174 ( struct V_2 * V_3 , struct V_229 * V_230 , T_2 * V_82 )
{
struct V_303 * V_141 = (struct V_303 * ) V_82 ;
T_1 V_6 , V_7 ;
struct V_1 * V_15 ;
struct V_24 * V_9 ;
V_7 = F_166 ( V_141 -> V_7 ) ;
V_6 = F_166 ( V_141 -> V_6 ) ;
F_26 ( L_24 , V_6 , V_7 ) ;
V_15 = F_4 ( V_3 , V_7 ) ;
if ( ! V_15 )
return 0 ;
V_9 = V_15 -> V_9 ;
if ( F_169 ( V_9 ) ) {
V_9 -> V_44 = V_135 ;
F_29 ( V_9 ) ;
F_77 ( V_9 , V_183 / 5 ) ;
F_62 ( V_9 ) ;
return 0 ;
}
F_28 ( V_15 , 0 ) ;
F_62 ( V_9 ) ;
F_72 ( V_9 ) ;
return 0 ;
}
static inline int F_175 ( struct V_2 * V_3 , struct V_229 * V_230 , T_2 * V_82 )
{
struct V_119 * V_117 = (struct V_119 * ) V_82 ;
T_1 type ;
type = F_166 ( V_117 -> type ) ;
F_26 ( L_25 , type ) ;
if ( type == V_120 ) {
T_2 V_142 [ 8 ] ;
T_8 V_126 = V_128 ;
struct V_307 * V_141 = (struct V_307 * ) V_142 ;
V_141 -> type = F_15 ( V_120 ) ;
V_141 -> V_144 = F_15 ( V_308 ) ;
if ( ! V_129 )
V_126 |= V_130 | V_131
| V_262 ;
F_153 ( V_126 , V_141 -> V_82 ) ;
F_43 ( V_3 , V_230 -> V_10 ,
V_309 , sizeof( V_142 ) , V_142 ) ;
} else if ( type == V_310 ) {
T_2 V_142 [ 12 ] ;
struct V_307 * V_141 = (struct V_307 * ) V_142 ;
V_141 -> type = F_15 ( V_310 ) ;
V_141 -> V_144 = F_15 ( V_308 ) ;
memcpy ( V_142 + 4 , V_311 , 8 ) ;
F_43 ( V_3 , V_230 -> V_10 ,
V_309 , sizeof( V_142 ) , V_142 ) ;
} else {
struct V_307 V_141 ;
V_141 . type = F_15 ( type ) ;
V_141 . V_144 = F_15 ( V_312 ) ;
F_43 ( V_3 , V_230 -> V_10 ,
V_309 , sizeof( V_141 ) , & V_141 ) ;
}
return 0 ;
}
static inline int F_176 ( struct V_2 * V_3 , struct V_229 * V_230 , T_2 * V_82 )
{
struct V_307 * V_141 = (struct V_307 * ) V_82 ;
T_1 type , V_144 ;
type = F_166 ( V_141 -> type ) ;
V_144 = F_166 ( V_141 -> V_144 ) ;
F_26 ( L_26 , type , V_144 ) ;
if ( V_230 -> V_10 != V_3 -> V_121 ||
V_3 -> V_113 & V_115 )
return 0 ;
F_35 ( & V_3 -> V_122 ) ;
if ( V_144 != V_308 ) {
V_3 -> V_113 |= V_115 ;
V_3 -> V_121 = 0 ;
F_61 ( V_3 ) ;
return 0 ;
}
if ( type == V_120 ) {
V_3 -> V_126 = F_151 ( V_141 -> V_82 ) ;
if ( V_3 -> V_126 & V_313 ) {
struct V_119 V_117 ;
V_117 . type = F_15 ( V_310 ) ;
V_3 -> V_121 = F_40 ( V_3 ) ;
F_43 ( V_3 , V_3 -> V_121 ,
V_125 , sizeof( V_117 ) , & V_117 ) ;
} else {
V_3 -> V_113 |= V_115 ;
V_3 -> V_121 = 0 ;
F_61 ( V_3 ) ;
}
} else if ( type == V_310 ) {
V_3 -> V_113 |= V_115 ;
V_3 -> V_121 = 0 ;
F_61 ( V_3 ) ;
}
return 0 ;
}
static inline int F_177 ( T_1 V_314 , T_1 V_315 , T_1 V_316 ,
T_1 V_317 )
{
T_1 V_318 ;
if ( V_314 > V_315 || V_314 < 6 || V_315 > 3200 )
return - V_21 ;
if ( V_317 < 10 || V_317 > 3200 )
return - V_21 ;
if ( V_315 >= V_317 * 8 )
return - V_21 ;
V_318 = ( V_317 * 8 / V_315 ) - 1 ;
if ( V_316 > 499 || V_316 > V_318 )
return - V_21 ;
return 0 ;
}
static inline int F_178 ( struct V_2 * V_3 ,
struct V_229 * V_230 , T_2 * V_82 )
{
struct V_169 * V_32 = V_3 -> V_32 ;
struct F_178 * V_117 ;
struct V_319 V_141 ;
T_1 V_314 , V_315 , V_316 , V_317 , V_295 ;
int V_16 ;
if ( ! ( V_32 -> V_320 & V_321 ) )
return - V_21 ;
V_295 = F_166 ( V_230 -> V_81 ) ;
if ( V_295 != sizeof( struct F_178 ) )
return - V_322 ;
V_117 = (struct F_178 * ) V_82 ;
V_314 = F_166 ( V_117 -> V_314 ) ;
V_315 = F_166 ( V_117 -> V_315 ) ;
V_316 = F_166 ( V_117 -> V_316 ) ;
V_317 = F_166 ( V_117 -> V_317 ) ;
F_26 ( L_27 ,
V_314 , V_315 , V_316 , V_317 ) ;
memset ( & V_141 , 0 , sizeof( V_141 ) ) ;
V_16 = F_177 ( V_314 , V_315 , V_316 , V_317 ) ;
if ( V_16 )
V_141 . V_144 = F_15 ( V_323 ) ;
else
V_141 . V_144 = F_15 ( V_324 ) ;
F_43 ( V_3 , V_230 -> V_10 , V_325 ,
sizeof( V_141 ) , & V_141 ) ;
if ( ! V_16 )
F_179 ( V_32 , V_314 , V_315 , V_316 , V_317 ) ;
return 0 ;
}
static inline int F_180 ( struct V_2 * V_3 ,
struct V_229 * V_230 , T_1 V_295 , T_2 * V_82 )
{
int V_16 = 0 ;
switch ( V_230 -> V_80 ) {
case V_297 :
F_164 ( V_3 , V_230 , V_82 ) ;
break;
case V_118 :
V_16 = F_165 ( V_3 , V_230 , V_82 ) ;
break;
case V_152 :
V_16 = F_168 ( V_3 , V_230 , V_82 ) ;
break;
case V_154 :
V_16 = F_171 ( V_3 , V_230 , V_295 , V_82 ) ;
break;
case V_299 :
V_16 = F_172 ( V_3 , V_230 , V_82 ) ;
break;
case V_134 :
V_16 = F_173 ( V_3 , V_230 , V_82 ) ;
break;
case V_304 :
V_16 = F_174 ( V_3 , V_230 , V_82 ) ;
break;
case V_326 :
F_43 ( V_3 , V_230 -> V_10 , V_327 , V_295 , V_82 ) ;
break;
case V_327 :
break;
case V_125 :
V_16 = F_175 ( V_3 , V_230 , V_82 ) ;
break;
case V_309 :
V_16 = F_176 ( V_3 , V_230 , V_82 ) ;
break;
default:
F_181 ( L_28 , V_230 -> V_80 ) ;
V_16 = - V_21 ;
break;
}
return V_16 ;
}
static inline int F_182 ( struct V_2 * V_3 ,
struct V_229 * V_230 , T_2 * V_82 )
{
switch ( V_230 -> V_80 ) {
case V_297 :
return 0 ;
case V_328 :
return F_178 ( V_3 , V_230 , V_82 ) ;
case V_325 :
return 0 ;
default:
F_181 ( L_29 , V_230 -> V_80 ) ;
return - V_21 ;
}
}
static inline void F_183 ( struct V_2 * V_3 ,
struct V_83 * V_84 )
{
T_2 * V_82 = V_84 -> V_82 ;
int V_81 = V_84 -> V_81 ;
struct V_229 V_230 ;
int V_16 ;
F_148 ( V_3 , V_84 ) ;
while ( V_81 >= V_231 ) {
T_1 V_295 ;
memcpy ( & V_230 , V_82 , V_231 ) ;
V_82 += V_231 ;
V_81 -= V_231 ;
V_295 = F_159 ( V_230 . V_81 ) ;
F_26 ( L_30 , V_230 . V_80 , V_295 , V_230 . V_10 ) ;
if ( V_295 > V_81 || ! V_230 . V_10 ) {
F_26 ( L_31 ) ;
break;
}
if ( V_3 -> V_32 -> type == V_33 )
V_16 = F_182 ( V_3 , & V_230 , V_82 ) ;
else
V_16 = F_180 ( V_3 , & V_230 , V_295 , V_82 ) ;
if ( V_16 ) {
struct V_286 V_287 ;
F_181 ( L_32 , V_16 ) ;
V_287 . V_288 = F_15 ( 0 ) ;
F_43 ( V_3 , V_230 . V_10 , V_297 , sizeof( V_287 ) , & V_287 ) ;
}
V_82 += V_295 ;
V_81 -= V_295 ;
}
F_87 ( V_84 ) ;
}
static int F_184 ( struct V_1 * V_15 , struct V_83 * V_84 )
{
T_1 V_329 , V_330 ;
int V_331 = V_96 + 2 ;
if ( V_15 -> V_98 == V_99 ) {
F_185 ( V_84 , V_84 -> V_81 - 2 ) ;
V_330 = F_121 ( V_84 -> V_82 + V_84 -> V_81 ) ;
V_329 = F_53 ( 0 , V_84 -> V_82 - V_331 , V_84 -> V_81 + V_331 ) ;
if ( V_329 != V_330 )
return - V_332 ;
}
return 0 ;
}
static inline void F_186 ( struct V_1 * V_15 )
{
T_1 V_89 = 0 ;
V_15 -> V_202 = 0 ;
V_89 |= V_15 -> V_110 << V_111 ;
if ( V_15 -> V_101 & V_106 ) {
V_89 |= V_107 ;
F_47 ( V_15 , V_89 ) ;
V_15 -> V_101 |= V_108 ;
}
if ( V_15 -> V_101 & V_333 )
F_129 ( V_15 ) ;
F_126 ( V_15 ) ;
if ( ! ( V_15 -> V_101 & V_106 ) &&
V_15 -> V_202 == 0 ) {
V_89 |= V_109 ;
F_47 ( V_15 , V_89 ) ;
}
}
static int F_187 ( struct V_1 * V_15 , struct V_83 * V_84 , T_2 V_191 , T_2 V_334 )
{
struct V_83 * V_335 ;
int V_336 , V_337 ;
F_117 ( V_84 ) -> V_191 = V_191 ;
F_117 ( V_84 ) -> V_334 = V_334 ;
V_335 = F_116 ( & V_15 -> V_62 ) ;
if ( ! V_335 ) {
F_145 ( & V_15 -> V_62 , V_84 ) ;
return 0 ;
}
V_336 = ( V_191 - V_15 -> V_110 ) % 64 ;
if ( V_336 < 0 )
V_336 += 64 ;
do {
if ( F_117 ( V_335 ) -> V_191 == V_191 )
return - V_21 ;
V_337 = ( F_117 ( V_335 ) -> V_191 -
V_15 -> V_110 ) % 64 ;
if ( V_337 < 0 )
V_337 += 64 ;
if ( V_337 > V_336 ) {
F_188 ( & V_15 -> V_62 , V_335 , V_84 ) ;
return 0 ;
}
if ( F_123 ( & V_15 -> V_62 , V_335 ) )
break;
} while ( ( V_335 = F_124 ( & V_15 -> V_62 , V_335 ) ) );
F_145 ( & V_15 -> V_62 , V_84 ) ;
return 0 ;
}
static int F_189 ( struct V_1 * V_15 , struct V_83 * V_84 , T_1 V_89 )
{
struct V_83 * V_338 ;
int V_16 ;
switch ( V_89 & V_198 ) {
case V_339 :
if ( V_15 -> V_101 & V_340 )
goto V_341;
V_16 = F_149 ( V_15 -> V_9 , V_84 ) ;
if ( ! V_16 )
return V_16 ;
break;
case V_222 :
if ( V_15 -> V_101 & V_340 )
goto V_341;
V_15 -> V_342 = F_121 ( V_84 -> V_82 ) ;
if ( V_15 -> V_342 > V_15 -> V_251 )
goto V_343;
V_15 -> V_344 = F_50 ( V_15 -> V_342 , V_25 ) ;
if ( ! V_15 -> V_344 )
return - V_179 ;
F_190 ( V_84 , 2 ) ;
memcpy ( F_51 ( V_15 -> V_344 , V_84 -> V_81 ) , V_84 -> V_82 , V_84 -> V_81 ) ;
V_15 -> V_101 |= V_340 ;
V_15 -> V_345 = V_84 -> V_81 ;
break;
case V_225 :
if ( ! ( V_15 -> V_101 & V_340 ) )
goto V_343;
if ( ! V_15 -> V_344 )
goto V_343;
V_15 -> V_345 += V_84 -> V_81 ;
if ( V_15 -> V_345 > V_15 -> V_342 )
goto V_341;
memcpy ( F_51 ( V_15 -> V_344 , V_84 -> V_81 ) , V_84 -> V_82 , V_84 -> V_81 ) ;
break;
case V_226 :
if ( ! ( V_15 -> V_101 & V_340 ) )
goto V_343;
if ( ! V_15 -> V_344 )
goto V_343;
if ( ! ( V_15 -> V_101 & V_346 ) ) {
V_15 -> V_345 += V_84 -> V_81 ;
if ( V_15 -> V_345 > V_15 -> V_251 )
goto V_341;
if ( V_15 -> V_345 != V_15 -> V_342 )
goto V_341;
memcpy ( F_51 ( V_15 -> V_344 , V_84 -> V_81 ) , V_84 -> V_82 , V_84 -> V_81 ) ;
}
V_338 = F_125 ( V_15 -> V_344 , V_25 ) ;
if ( ! V_338 ) {
V_15 -> V_101 |= V_346 ;
return - V_179 ;
}
V_16 = F_149 ( V_15 -> V_9 , V_338 ) ;
if ( V_16 < 0 ) {
F_87 ( V_338 ) ;
V_15 -> V_101 |= V_346 ;
return V_16 ;
}
V_15 -> V_101 &= ~ V_346 ;
V_15 -> V_101 &= ~ V_340 ;
F_87 ( V_15 -> V_344 ) ;
break;
}
F_87 ( V_84 ) ;
return 0 ;
V_341:
F_87 ( V_15 -> V_344 ) ;
V_15 -> V_344 = NULL ;
V_343:
F_60 ( V_15 -> V_3 , V_15 , V_138 ) ;
F_87 ( V_84 ) ;
return 0 ;
}
static int F_191 ( struct V_1 * V_15 )
{
struct V_83 * V_84 ;
T_1 V_89 ;
int V_16 ;
while ( ( V_84 = F_118 ( & V_15 -> V_63 ) ) ) {
V_89 = F_117 ( V_84 ) -> V_334 << V_347 ;
V_16 = F_189 ( V_15 , V_84 , V_89 ) ;
if ( V_16 < 0 ) {
F_192 ( & V_15 -> V_63 , V_84 ) ;
return - V_348 ;
}
V_15 -> V_110 = ( V_15 -> V_110 + 1 ) % 64 ;
}
if ( ! ( V_15 -> V_101 & V_108 ) )
goto V_19;
V_89 = V_15 -> V_110 << V_111 ;
V_89 |= V_109 | V_105 ;
F_47 ( V_15 , V_89 ) ;
V_15 -> V_187 = 1 ;
F_35 ( & V_15 -> V_59 ) ;
F_113 () ;
V_15 -> V_101 |= V_190 ;
V_19:
V_15 -> V_101 &= ~ V_106 ;
V_15 -> V_101 &= ~ V_108 ;
F_26 ( L_33 , V_15 ) ;
return 0 ;
}
static void V_242 ( struct V_349 * V_350 )
{
F_101 ( V_180 , V_181 ) ;
struct V_1 * V_15 =
F_193 ( V_350 , struct V_1 , V_241 ) ;
struct V_24 * V_9 = V_15 -> V_9 ;
int V_351 = 0 , V_182 = V_183 / 5 , V_16 ;
struct V_83 * V_84 ;
F_109 ( V_9 ) ;
F_102 ( F_103 ( V_9 ) , & V_180 ) ;
while ( ( V_84 = F_116 ( & V_15 -> V_63 ) ) ) {
F_104 ( V_185 ) ;
if ( V_351 ++ > V_352 ) {
V_16 = - V_348 ;
F_60 ( V_15 -> V_3 , V_15 , V_348 ) ;
break;
}
if ( ! V_182 )
V_182 = V_183 / 5 ;
if ( F_105 ( V_181 ) ) {
V_16 = F_106 ( V_182 ) ;
break;
}
F_107 ( V_9 ) ;
V_182 = F_108 ( V_182 ) ;
F_109 ( V_9 ) ;
V_16 = F_110 ( V_9 ) ;
if ( V_16 )
break;
if ( F_191 ( V_15 ) == 0 )
break;
}
F_104 ( V_186 ) ;
F_111 ( F_103 ( V_9 ) , & V_180 ) ;
F_107 ( V_9 ) ;
}
static int F_194 ( struct V_1 * V_15 , struct V_83 * V_84 , T_1 V_89 )
{
int V_353 , V_16 ;
if ( V_15 -> V_101 & V_106 ) {
F_117 ( V_84 ) -> V_334 = V_89 >> V_347 ;
F_145 ( & V_15 -> V_63 , V_84 ) ;
return F_191 ( V_15 ) ;
}
V_16 = F_189 ( V_15 , V_84 , V_89 ) ;
if ( V_16 >= 0 ) {
V_15 -> V_110 = ( V_15 -> V_110 + 1 ) % 64 ;
return V_16 ;
}
F_26 ( L_34 , V_15 ) ;
V_15 -> V_101 |= V_106 ;
F_117 ( V_84 ) -> V_334 = V_89 >> V_347 ;
F_145 ( & V_15 -> V_63 , V_84 ) ;
V_353 = V_15 -> V_110 << V_111 ;
V_353 |= V_107 ;
F_47 ( V_15 , V_353 ) ;
V_15 -> V_101 |= V_108 ;
F_35 ( & V_15 -> V_61 ) ;
F_195 ( V_354 , & V_15 -> V_241 ) ;
return V_16 ;
}
static int F_196 ( struct V_1 * V_15 , struct V_83 * V_84 , T_1 V_89 )
{
struct V_83 * V_338 ;
int V_16 = - V_21 ;
switch ( V_89 & V_198 ) {
case V_339 :
if ( V_15 -> V_101 & V_340 ) {
F_87 ( V_15 -> V_344 ) ;
break;
}
V_16 = F_149 ( V_15 -> V_9 , V_84 ) ;
if ( ! V_16 )
return 0 ;
break;
case V_222 :
if ( V_15 -> V_101 & V_340 ) {
F_87 ( V_15 -> V_344 ) ;
break;
}
V_15 -> V_342 = F_121 ( V_84 -> V_82 ) ;
F_190 ( V_84 , 2 ) ;
if ( V_15 -> V_342 > V_15 -> V_251 ) {
V_16 = - V_355 ;
break;
}
V_15 -> V_344 = F_50 ( V_15 -> V_342 , V_25 ) ;
if ( ! V_15 -> V_344 ) {
V_16 = - V_179 ;
break;
}
memcpy ( F_51 ( V_15 -> V_344 , V_84 -> V_81 ) , V_84 -> V_82 , V_84 -> V_81 ) ;
V_15 -> V_101 |= V_340 ;
V_15 -> V_345 = V_84 -> V_81 ;
V_16 = 0 ;
break;
case V_225 :
if ( ! ( V_15 -> V_101 & V_340 ) )
break;
memcpy ( F_51 ( V_15 -> V_344 , V_84 -> V_81 ) , V_84 -> V_82 , V_84 -> V_81 ) ;
V_15 -> V_345 += V_84 -> V_81 ;
if ( V_15 -> V_345 > V_15 -> V_342 )
F_87 ( V_15 -> V_344 ) ;
else
V_16 = 0 ;
break;
case V_226 :
if ( ! ( V_15 -> V_101 & V_340 ) )
break;
memcpy ( F_51 ( V_15 -> V_344 , V_84 -> V_81 ) , V_84 -> V_82 , V_84 -> V_81 ) ;
V_15 -> V_101 &= ~ V_340 ;
V_15 -> V_345 += V_84 -> V_81 ;
if ( V_15 -> V_345 > V_15 -> V_251 )
goto V_341;
if ( V_15 -> V_345 == V_15 -> V_342 ) {
V_338 = F_125 ( V_15 -> V_344 , V_25 ) ;
V_16 = F_149 ( V_15 -> V_9 , V_338 ) ;
if ( V_16 < 0 )
F_87 ( V_338 ) ;
}
V_16 = 0 ;
V_341:
F_87 ( V_15 -> V_344 ) ;
break;
}
F_87 ( V_84 ) ;
return V_16 ;
}
static void F_197 ( struct V_1 * V_15 , T_2 V_191 )
{
struct V_83 * V_84 ;
T_1 V_89 ;
while ( ( V_84 = F_116 ( & V_15 -> V_62 ) ) ) {
if ( F_117 ( V_84 ) -> V_191 != V_191 )
break;
V_84 = F_118 ( & V_15 -> V_62 ) ;
V_89 = F_117 ( V_84 ) -> V_334 << V_347 ;
F_189 ( V_15 , V_84 , V_89 ) ;
V_15 -> V_356 =
( V_15 -> V_356 + 1 ) % 64 ;
V_191 = ( V_191 + 1 ) % 64 ;
}
}
static void F_198 ( struct V_1 * V_15 , T_2 V_191 )
{
struct V_56 * V_57 , * V_58 ;
T_1 V_89 ;
F_36 (l, tmp, &chan->srej_l, list) {
if ( V_57 -> V_191 == V_191 ) {
F_23 ( & V_57 -> V_41 ) ;
F_24 ( V_57 ) ;
return;
}
V_89 = V_206 ;
V_89 |= V_57 -> V_191 << V_111 ;
F_47 ( V_15 , V_89 ) ;
F_23 ( & V_57 -> V_41 ) ;
F_199 ( & V_57 -> V_41 , & V_15 -> V_207 ) ;
}
}
static void F_200 ( struct V_1 * V_15 , T_2 V_191 )
{
struct V_56 * V_357 ;
T_1 V_89 ;
while ( V_191 != V_15 -> V_301 ) {
V_89 = V_206 ;
V_89 |= V_15 -> V_301 << V_111 ;
F_47 ( V_15 , V_89 ) ;
V_357 = F_20 ( sizeof( struct V_56 ) , V_25 ) ;
V_357 -> V_191 = V_15 -> V_301 ;
V_15 -> V_301 = ( V_15 -> V_301 + 1 ) % 64 ;
F_199 ( & V_357 -> V_41 , & V_15 -> V_207 ) ;
}
V_15 -> V_301 = ( V_15 -> V_301 + 1 ) % 64 ;
}
static inline int F_201 ( struct V_1 * V_15 , T_1 V_358 , struct V_83 * V_84 )
{
T_2 V_191 = F_202 ( V_358 ) ;
T_2 V_359 = F_203 ( V_358 ) ;
T_2 V_334 = V_358 >> V_347 ;
int V_336 , V_360 ;
int V_361 = ( V_15 -> V_259 / 6 ) + 1 ;
int V_16 = 0 ;
F_26 ( L_35 , V_15 , V_84 -> V_81 ,
V_191 , V_358 ) ;
if ( V_103 & V_358 &&
V_15 -> V_101 & V_190 ) {
F_35 ( & V_15 -> V_60 ) ;
if ( V_15 -> V_184 > 0 )
F_128 () ;
V_15 -> V_101 &= ~ V_190 ;
}
V_15 -> V_192 = V_359 ;
F_115 ( V_15 ) ;
if ( V_191 == V_15 -> V_301 )
goto V_362;
V_336 = ( V_191 - V_15 -> V_110 ) % 64 ;
if ( V_336 < 0 )
V_336 += 64 ;
if ( V_336 >= V_15 -> V_259 ) {
F_60 ( V_15 -> V_3 , V_15 , V_138 ) ;
goto V_341;
}
if ( V_15 -> V_101 == V_106 )
goto V_341;
if ( V_15 -> V_101 & V_363 ) {
struct V_56 * V_364 ;
V_364 = F_204 ( & V_15 -> V_207 ,
struct V_56 , V_41 ) ;
if ( V_191 == V_364 -> V_191 ) {
F_187 ( V_15 , V_84 , V_191 , V_334 ) ;
F_197 ( V_15 , V_191 ) ;
F_23 ( & V_364 -> V_41 ) ;
F_24 ( V_364 ) ;
if ( F_205 ( & V_15 -> V_207 ) ) {
V_15 -> V_110 = V_15 -> V_356 ;
V_15 -> V_101 &= ~ V_363 ;
F_131 ( V_15 ) ;
F_26 ( L_36 , V_15 ) ;
}
} else {
struct V_56 * V_57 ;
if ( F_187 ( V_15 , V_84 , V_191 , V_334 ) < 0 )
goto V_341;
F_2 (l, &chan->srej_l, list) {
if ( V_57 -> V_191 == V_191 ) {
F_198 ( V_15 , V_191 ) ;
return 0 ;
}
}
F_200 ( V_15 , V_191 ) ;
}
} else {
V_360 =
( V_15 -> V_301 - V_15 -> V_110 ) % 64 ;
if ( V_360 < 0 )
V_360 += 64 ;
if ( V_336 < V_360 )
goto V_341;
V_15 -> V_101 |= V_363 ;
F_26 ( L_37 , V_15 ) ;
F_84 ( & V_15 -> V_207 ) ;
V_15 -> V_356 = V_15 -> V_110 ;
F_206 ( & V_15 -> V_62 ) ;
F_206 ( & V_15 -> V_63 ) ;
F_187 ( V_15 , V_84 , V_191 , V_334 ) ;
V_15 -> V_101 |= V_104 ;
F_200 ( V_15 , V_191 ) ;
F_35 ( & V_15 -> V_61 ) ;
}
return 0 ;
V_362:
V_15 -> V_301 = ( V_15 -> V_301 + 1 ) % 64 ;
if ( V_15 -> V_101 & V_363 ) {
F_117 ( V_84 ) -> V_191 = V_191 ;
F_117 ( V_84 ) -> V_334 = V_334 ;
F_145 ( & V_15 -> V_62 , V_84 ) ;
return 0 ;
}
V_16 = F_194 ( V_15 , V_84 , V_358 ) ;
if ( V_16 < 0 )
return 0 ;
if ( V_358 & V_103 ) {
if ( V_15 -> V_101 & V_365 )
V_15 -> V_101 &= ~ V_365 ;
else
F_129 ( V_15 ) ;
}
F_207 () ;
V_15 -> V_240 = ( V_15 -> V_240 + 1 ) % V_361 ;
if ( V_15 -> V_240 == V_361 - 1 )
F_131 ( V_15 ) ;
return 0 ;
V_341:
F_87 ( V_84 ) ;
return 0 ;
}
static inline void F_208 ( struct V_1 * V_15 , T_1 V_358 )
{
F_26 ( L_38 , V_15 , F_203 ( V_358 ) ,
V_358 ) ;
V_15 -> V_192 = F_203 ( V_358 ) ;
F_115 ( V_15 ) ;
if ( V_358 & V_105 ) {
V_15 -> V_101 |= V_102 ;
if ( V_15 -> V_101 & V_363 ) {
if ( ( V_15 -> V_101 & V_333 ) &&
( V_15 -> V_184 > 0 ) )
F_128 () ;
V_15 -> V_101 &= ~ V_333 ;
F_132 ( V_15 ) ;
} else {
F_186 ( V_15 ) ;
}
} else if ( V_358 & V_103 ) {
V_15 -> V_101 &= ~ V_333 ;
if ( V_15 -> V_101 & V_365 )
V_15 -> V_101 &= ~ V_365 ;
else
F_129 ( V_15 ) ;
} else {
if ( ( V_15 -> V_101 & V_333 ) &&
( V_15 -> V_184 > 0 ) )
F_128 () ;
V_15 -> V_101 &= ~ V_333 ;
if ( V_15 -> V_101 & V_363 )
F_131 ( V_15 ) ;
else
F_126 ( V_15 ) ;
}
}
static inline void F_209 ( struct V_1 * V_15 , T_1 V_358 )
{
T_2 V_191 = F_203 ( V_358 ) ;
F_26 ( L_38 , V_15 , V_191 , V_358 ) ;
V_15 -> V_101 &= ~ V_333 ;
V_15 -> V_192 = V_191 ;
F_115 ( V_15 ) ;
if ( V_358 & V_103 ) {
if ( V_15 -> V_101 & V_365 )
V_15 -> V_101 &= ~ V_365 ;
else
F_129 ( V_15 ) ;
} else {
F_129 ( V_15 ) ;
if ( V_15 -> V_101 & V_190 )
V_15 -> V_101 |= V_365 ;
}
}
static inline void F_210 ( struct V_1 * V_15 , T_1 V_358 )
{
T_2 V_191 = F_203 ( V_358 ) ;
F_26 ( L_38 , V_15 , V_191 , V_358 ) ;
V_15 -> V_101 &= ~ V_333 ;
if ( V_358 & V_105 ) {
V_15 -> V_192 = V_191 ;
F_115 ( V_15 ) ;
V_15 -> V_101 |= V_102 ;
F_122 ( V_15 , V_191 ) ;
F_126 ( V_15 ) ;
if ( V_15 -> V_101 & V_190 ) {
V_15 -> V_366 = V_191 ;
V_15 -> V_101 |= V_367 ;
}
} else if ( V_358 & V_103 ) {
if ( ( V_15 -> V_101 & V_367 ) &&
V_15 -> V_366 == V_191 )
V_15 -> V_101 &= ~ V_367 ;
else
F_122 ( V_15 , V_191 ) ;
} else {
F_122 ( V_15 , V_191 ) ;
if ( V_15 -> V_101 & V_190 ) {
V_15 -> V_366 = V_191 ;
V_15 -> V_101 |= V_367 ;
}
}
}
static inline void F_211 ( struct V_1 * V_15 , T_1 V_358 )
{
T_2 V_191 = F_203 ( V_358 ) ;
F_26 ( L_38 , V_15 , V_191 , V_358 ) ;
V_15 -> V_101 |= V_333 ;
V_15 -> V_192 = V_191 ;
F_115 ( V_15 ) ;
if ( V_358 & V_105 )
V_15 -> V_101 |= V_102 ;
if ( ! ( V_15 -> V_101 & V_363 ) ) {
F_35 ( & V_15 -> V_59 ) ;
if ( V_358 & V_105 )
F_54 ( V_15 , V_103 ) ;
return;
}
if ( V_358 & V_105 )
F_132 ( V_15 ) ;
else
F_47 ( V_15 , V_109 ) ;
}
static inline int F_212 ( struct V_1 * V_15 , T_1 V_358 , struct V_83 * V_84 )
{
F_26 ( L_39 , V_15 , V_358 , V_84 -> V_81 ) ;
if ( V_103 & V_358 &&
V_15 -> V_101 & V_190 ) {
F_35 ( & V_15 -> V_60 ) ;
if ( V_15 -> V_184 > 0 )
F_128 () ;
V_15 -> V_101 &= ~ V_190 ;
}
switch ( V_358 & V_368 ) {
case V_109 :
F_208 ( V_15 , V_358 ) ;
break;
case V_369 :
F_209 ( V_15 , V_358 ) ;
break;
case V_206 :
F_210 ( V_15 , V_358 ) ;
break;
case V_107 :
F_211 ( V_15 , V_358 ) ;
break;
}
F_87 ( V_84 ) ;
return 0 ;
}
static int V_244 ( struct V_24 * V_9 , struct V_83 * V_84 )
{
struct V_1 * V_15 = F_48 ( V_9 ) -> V_15 ;
T_1 V_89 ;
T_2 V_359 ;
int V_81 , V_337 , V_370 ;
V_89 = F_121 ( V_84 -> V_82 ) ;
F_190 ( V_84 , 2 ) ;
V_81 = V_84 -> V_81 ;
if ( F_184 ( V_15 , V_84 ) )
goto V_341;
if ( F_213 ( V_89 ) && F_214 ( V_89 ) )
V_81 -= 2 ;
if ( V_15 -> V_98 == V_99 )
V_81 -= 2 ;
if ( V_81 > V_15 -> V_285 ) {
F_60 ( V_15 -> V_3 , V_15 , V_138 ) ;
goto V_341;
}
V_359 = F_203 ( V_89 ) ;
V_370 = ( V_359 - V_15 -> V_192 ) % 64 ;
if ( V_370 < 0 )
V_370 += 64 ;
V_337 =
( V_15 -> V_194 - V_15 -> V_192 ) % 64 ;
if ( V_337 < 0 )
V_337 += 64 ;
if ( V_370 > V_337 ) {
F_60 ( V_15 -> V_3 , V_15 , V_138 ) ;
goto V_341;
}
if ( F_214 ( V_89 ) ) {
if ( V_81 < 0 ) {
F_60 ( V_15 -> V_3 , V_15 , V_138 ) ;
goto V_341;
}
F_201 ( V_15 , V_89 , V_84 ) ;
} else {
if ( V_81 != 0 ) {
F_181 ( L_40 , V_81 ) ;
F_60 ( V_15 -> V_3 , V_15 , V_138 ) ;
goto V_341;
}
F_212 ( V_15 , V_89 , V_84 ) ;
}
return 0 ;
V_341:
F_87 ( V_84 ) ;
return 0 ;
}
static inline int F_215 ( struct V_2 * V_3 , T_1 V_4 , struct V_83 * V_84 )
{
struct V_1 * V_15 ;
struct V_24 * V_9 = NULL ;
struct V_92 * V_93 ;
T_1 V_89 ;
T_2 V_191 ;
int V_81 ;
V_15 = F_4 ( V_3 , V_4 ) ;
if ( ! V_15 ) {
F_26 ( L_41 , V_4 ) ;
goto V_341;
}
V_9 = V_15 -> V_9 ;
V_93 = F_48 ( V_9 ) ;
F_26 ( L_42 , V_15 , V_84 -> V_81 ) ;
if ( V_9 -> V_44 != V_97 )
goto V_341;
switch ( V_15 -> V_54 ) {
case V_246 :
if ( V_15 -> V_251 < V_84 -> V_81 )
goto V_341;
if ( ! F_149 ( V_9 , V_84 ) )
goto V_19;
break;
case V_55 :
if ( ! F_169 ( V_9 ) ) {
V_244 ( V_9 , V_84 ) ;
} else {
if ( F_216 ( V_9 , V_84 ) )
goto V_341;
}
goto V_19;
case V_132 :
V_89 = F_121 ( V_84 -> V_82 ) ;
F_190 ( V_84 , 2 ) ;
V_81 = V_84 -> V_81 ;
if ( F_184 ( V_15 , V_84 ) )
goto V_341;
if ( F_213 ( V_89 ) )
V_81 -= 2 ;
if ( V_15 -> V_98 == V_99 )
V_81 -= 2 ;
if ( V_81 > V_15 -> V_285 || V_81 < 0 || F_217 ( V_89 ) )
goto V_341;
V_191 = F_202 ( V_89 ) ;
if ( V_15 -> V_301 == V_191 )
V_15 -> V_301 = ( V_15 -> V_301 + 1 ) % 64 ;
else
V_15 -> V_301 = ( V_191 + 1 ) % 64 ;
F_196 ( V_15 , V_84 , V_89 ) ;
goto V_19;
default:
F_26 ( L_43 , V_15 , V_15 -> V_54 ) ;
break;
}
V_341:
F_87 ( V_84 ) ;
V_19:
if ( V_9 )
F_62 ( V_9 ) ;
return 0 ;
}
static inline int F_218 ( struct V_2 * V_3 , T_3 V_11 , struct V_83 * V_84 )
{
struct V_24 * V_9 = NULL ;
struct V_1 * V_15 ;
V_15 = F_90 ( 0 , V_11 , V_3 -> V_12 ) ;
if ( ! V_15 )
goto V_341;
V_9 = V_15 -> V_9 ;
F_6 ( V_9 ) ;
F_26 ( L_44 , V_9 , V_84 -> V_81 ) ;
if ( V_9 -> V_44 != V_371 && V_9 -> V_44 != V_97 )
goto V_341;
if ( F_48 ( V_9 ) -> V_15 -> V_251 < V_84 -> V_81 )
goto V_341;
if ( ! F_149 ( V_9 , V_84 ) )
goto V_19;
V_341:
F_87 ( V_84 ) ;
V_19:
if ( V_9 )
F_62 ( V_9 ) ;
return 0 ;
}
static inline int F_219 ( struct V_2 * V_3 , T_3 V_4 , struct V_83 * V_84 )
{
struct V_24 * V_9 = NULL ;
struct V_1 * V_15 ;
V_15 = F_67 ( 0 , V_4 , V_3 -> V_12 ) ;
if ( ! V_15 )
goto V_341;
V_9 = V_15 -> V_9 ;
F_6 ( V_9 ) ;
F_26 ( L_44 , V_9 , V_84 -> V_81 ) ;
if ( V_9 -> V_44 != V_371 && V_9 -> V_44 != V_97 )
goto V_341;
if ( F_48 ( V_9 ) -> V_15 -> V_251 < V_84 -> V_81 )
goto V_341;
if ( ! F_149 ( V_9 , V_84 ) )
goto V_19;
V_341:
F_87 ( V_84 ) ;
V_19:
if ( V_9 )
F_62 ( V_9 ) ;
return 0 ;
}
static void F_220 ( struct V_2 * V_3 , struct V_83 * V_84 )
{
struct V_90 * V_91 = ( void * ) V_84 -> V_82 ;
T_1 V_4 , V_81 ;
T_3 V_11 ;
F_190 ( V_84 , V_96 ) ;
V_4 = F_166 ( V_91 -> V_4 ) ;
V_81 = F_166 ( V_91 -> V_81 ) ;
if ( V_81 != V_84 -> V_81 ) {
F_87 ( V_84 ) ;
return;
}
F_26 ( L_45 , V_81 , V_4 ) ;
switch ( V_4 ) {
case V_232 :
case V_40 :
F_183 ( V_3 , V_84 ) ;
break;
case V_39 :
V_11 = F_121 ( V_84 -> V_82 ) ;
F_190 ( V_84 , 2 ) ;
F_218 ( V_3 , V_11 , V_84 ) ;
break;
case V_36 :
F_219 ( V_3 , V_4 , V_84 ) ;
break;
default:
F_215 ( V_3 , V_4 , V_84 ) ;
break;
}
}
static int F_221 ( struct V_176 * V_86 , T_4 * V_174 , T_2 type )
{
int V_372 = 0 , V_373 = 0 , V_374 = 0 ;
struct V_1 * V_5 ;
if ( type != V_178 )
return - V_21 ;
F_26 ( L_46 , V_86 -> V_375 , F_92 ( V_174 ) ) ;
F_5 ( & V_17 ) ;
F_2 (c, &chan_list, global_l) {
struct V_24 * V_9 = V_5 -> V_9 ;
if ( V_9 -> V_44 != V_160 )
continue;
if ( ! F_11 ( & F_12 ( V_9 ) -> V_12 , & V_86 -> V_174 ) ) {
V_373 |= V_376 ;
if ( V_5 -> V_377 )
V_373 |= V_321 ;
V_372 ++ ;
} else if ( ! F_11 ( & F_12 ( V_9 ) -> V_12 , V_158 ) ) {
V_374 |= V_376 ;
if ( V_5 -> V_377 )
V_374 |= V_321 ;
}
}
F_7 ( & V_17 ) ;
return V_372 ? V_373 : V_374 ;
}
static int F_222 ( struct V_169 * V_32 , T_2 V_146 )
{
struct V_2 * V_3 ;
F_26 ( L_47 , V_32 , F_92 ( & V_32 -> V_164 ) , V_146 ) ;
if ( ! ( V_32 -> type == V_178 || V_32 -> type == V_33 ) )
return - V_21 ;
if ( ! V_146 ) {
V_3 = F_81 ( V_32 , V_146 ) ;
if ( V_3 )
F_78 ( V_3 ) ;
} else
F_86 ( V_32 , F_223 ( V_146 ) ) ;
return 0 ;
}
static int F_224 ( struct V_169 * V_32 )
{
struct V_2 * V_3 = V_32 -> V_170 ;
F_26 ( L_48 , V_32 ) ;
if ( V_32 -> type != V_178 || ! V_3 )
return 0x13 ;
return V_3 -> V_28 ;
}
static int F_225 ( struct V_169 * V_32 , T_2 V_288 )
{
F_26 ( L_49 , V_32 , V_288 ) ;
if ( ! ( V_32 -> type == V_178 || V_32 -> type == V_33 ) )
return - V_21 ;
F_86 ( V_32 , F_223 ( V_288 ) ) ;
return 0 ;
}
static inline void F_226 ( struct V_1 * V_15 , T_2 V_378 )
{
struct V_24 * V_9 = V_15 -> V_9 ;
if ( V_9 -> V_29 != V_30 && V_9 -> V_29 != V_31 )
return;
if ( V_378 == 0x00 ) {
if ( V_15 -> V_65 == V_68 ) {
F_29 ( V_9 ) ;
F_77 ( V_9 , V_183 * 5 ) ;
} else if ( V_15 -> V_65 == V_66 )
F_64 ( V_9 , V_277 ) ;
} else {
if ( V_15 -> V_65 == V_68 )
F_29 ( V_9 ) ;
}
}
static int F_227 ( struct V_169 * V_32 , T_2 V_146 , T_2 V_378 )
{
struct V_2 * V_3 = V_32 -> V_170 ;
struct V_1 * V_15 ;
if ( ! V_3 )
return 0 ;
F_26 ( L_5 , V_3 ) ;
F_5 ( & V_3 -> V_8 ) ;
F_2 (chan, &conn->chan_l, list) {
struct V_24 * V_9 = V_15 -> V_9 ;
F_6 ( V_9 ) ;
if ( V_15 -> V_50 & V_112 ) {
F_62 ( V_9 ) ;
continue;
}
if ( ! V_146 && ( V_9 -> V_44 == V_97 ||
V_9 -> V_44 == V_148 ) ) {
F_226 ( V_15 , V_378 ) ;
F_62 ( V_9 ) ;
continue;
}
if ( V_9 -> V_44 == V_136 ) {
if ( ! V_146 ) {
struct V_116 V_117 ;
V_117 . V_7 = F_15 ( V_15 -> V_7 ) ;
V_117 . V_11 = V_15 -> V_11 ;
V_15 -> V_10 = F_40 ( V_3 ) ;
V_15 -> V_50 |= V_112 ;
F_43 ( V_3 , V_15 -> V_10 ,
V_118 , sizeof( V_117 ) , & V_117 ) ;
} else {
F_29 ( V_9 ) ;
F_77 ( V_9 , V_183 / 10 ) ;
}
} else if ( V_9 -> V_44 == V_139 ) {
struct V_140 V_141 ;
T_5 V_379 , V_380 ;
if ( ! V_146 ) {
if ( F_12 ( V_9 ) -> V_143 ) {
struct V_24 * V_43 = F_12 ( V_9 ) -> V_43 ;
V_379 = V_145 ;
V_380 = V_147 ;
if ( V_43 )
V_43 -> V_48 ( V_43 , 0 ) ;
} else {
V_9 -> V_44 = V_148 ;
V_379 = V_149 ;
V_380 = V_150 ;
}
} else {
V_9 -> V_44 = V_135 ;
F_77 ( V_9 , V_183 / 10 ) ;
V_379 = V_291 ;
V_380 = V_150 ;
}
V_141 . V_7 = F_15 ( V_15 -> V_6 ) ;
V_141 . V_6 = F_15 ( V_15 -> V_7 ) ;
V_141 . V_144 = F_15 ( V_379 ) ;
V_141 . V_146 = F_15 ( V_380 ) ;
F_43 ( V_3 , V_15 -> V_10 , V_152 ,
sizeof( V_141 ) , & V_141 ) ;
}
F_62 ( V_9 ) ;
}
F_7 ( & V_3 -> V_8 ) ;
return 0 ;
}
static int F_228 ( struct V_169 * V_32 , struct V_83 * V_84 , T_1 V_85 )
{
struct V_2 * V_3 = V_32 -> V_170 ;
if ( ! V_3 )
V_3 = F_81 ( V_32 , 0 ) ;
if ( ! V_3 )
goto V_341;
F_26 ( L_50 , V_3 , V_84 -> V_81 , V_85 ) ;
if ( ! ( V_85 & V_381 ) ) {
struct V_90 * V_382 ;
struct V_1 * V_15 ;
T_1 V_4 ;
int V_81 ;
if ( V_3 -> V_383 ) {
F_181 ( L_51 , V_84 -> V_81 ) ;
F_87 ( V_3 -> V_175 ) ;
V_3 -> V_175 = NULL ;
V_3 -> V_383 = 0 ;
F_79 ( V_3 , V_384 ) ;
}
if ( V_84 -> V_81 < V_96 ) {
F_181 ( L_52 , V_84 -> V_81 ) ;
F_79 ( V_3 , V_384 ) ;
goto V_341;
}
V_382 = (struct V_90 * ) V_84 -> V_82 ;
V_81 = F_166 ( V_382 -> V_81 ) + V_96 ;
V_4 = F_166 ( V_382 -> V_4 ) ;
if ( V_81 == V_84 -> V_81 ) {
F_220 ( V_3 , V_84 ) ;
return 0 ;
}
F_26 ( L_53 , V_81 , V_84 -> V_81 ) ;
if ( V_84 -> V_81 > V_81 ) {
F_181 ( L_54 ,
V_84 -> V_81 , V_81 ) ;
F_79 ( V_3 , V_384 ) ;
goto V_341;
}
V_15 = F_4 ( V_3 , V_4 ) ;
if ( V_15 && V_15 -> V_9 ) {
struct V_24 * V_9 = V_15 -> V_9 ;
if ( V_15 -> V_251 < V_81 - V_96 ) {
F_181 ( L_55
L_56 , V_81 ,
V_15 -> V_251 ) ;
F_62 ( V_9 ) ;
F_79 ( V_3 , V_384 ) ;
goto V_341;
}
F_62 ( V_9 ) ;
}
V_3 -> V_175 = F_50 ( V_81 , V_25 ) ;
if ( ! V_3 -> V_175 )
goto V_341;
F_229 ( V_84 , F_51 ( V_3 -> V_175 , V_84 -> V_81 ) ,
V_84 -> V_81 ) ;
V_3 -> V_383 = V_81 - V_84 -> V_81 ;
} else {
F_26 ( L_57 , V_84 -> V_81 , V_3 -> V_383 ) ;
if ( ! V_3 -> V_383 ) {
F_181 ( L_58 , V_84 -> V_81 ) ;
F_79 ( V_3 , V_384 ) ;
goto V_341;
}
if ( V_84 -> V_81 > V_3 -> V_383 ) {
F_181 ( L_59 ,
V_84 -> V_81 , V_3 -> V_383 ) ;
F_87 ( V_3 -> V_175 ) ;
V_3 -> V_175 = NULL ;
V_3 -> V_383 = 0 ;
F_79 ( V_3 , V_384 ) ;
goto V_341;
}
F_229 ( V_84 , F_51 ( V_3 -> V_175 , V_84 -> V_81 ) ,
V_84 -> V_81 ) ;
V_3 -> V_383 -= V_84 -> V_81 ;
if ( ! V_3 -> V_383 ) {
F_220 ( V_3 , V_3 -> V_175 ) ;
V_3 -> V_175 = NULL ;
}
}
V_341:
F_87 ( V_84 ) ;
return 0 ;
}
static int F_230 ( struct V_385 * V_386 , void * V_20 )
{
struct V_1 * V_5 ;
F_65 ( & V_17 ) ;
F_2 (c, &chan_list, global_l) {
struct V_24 * V_9 = V_5 -> V_9 ;
F_231 ( V_386 , L_60 ,
F_92 ( & F_12 ( V_9 ) -> V_12 ) ,
F_92 ( & F_12 ( V_9 ) -> V_164 ) ,
V_9 -> V_44 , F_166 ( V_5 -> V_11 ) ,
V_5 -> V_7 , V_5 -> V_6 , V_5 -> V_251 , V_5 -> V_34 ,
V_5 -> V_65 , V_5 -> V_54 ) ;
}
F_63 ( & V_17 ) ;
return 0 ;
}
static int F_232 ( struct V_387 * V_387 , struct V_388 * V_388 )
{
return F_233 ( V_388 , F_230 , V_387 -> V_389 ) ;
}
int T_10 F_234 ( void )
{
int V_16 ;
V_16 = F_235 () ;
if ( V_16 < 0 )
return V_16 ;
V_354 = F_236 ( L_61 ) ;
if ( ! V_354 ) {
V_16 = - V_179 ;
goto error;
}
V_16 = F_237 ( & V_390 ) ;
if ( V_16 < 0 ) {
F_181 ( L_62 ) ;
F_238 ( V_163 ) ;
goto error;
}
if ( V_391 ) {
V_392 = F_239 ( L_61 , 0444 ,
V_391 , NULL , & V_393 ) ;
if ( ! V_392 )
F_181 ( L_63 ) ;
}
return 0 ;
error:
F_240 ( V_354 ) ;
F_241 () ;
return V_16 ;
}
void F_242 ( void )
{
F_243 ( V_392 ) ;
F_244 ( V_354 ) ;
F_240 ( V_354 ) ;
if ( F_245 ( & V_390 ) < 0 )
F_181 ( L_64 ) ;
F_241 () ;
}
