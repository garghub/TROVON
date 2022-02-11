static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 )
{
if ( F_4 ( & V_2 -> V_3 ) )
F_5 ( V_2 ) ;
}
static struct V_1 * F_6 ( struct V_4 * V_5 , T_1 V_6 )
{
struct V_1 * V_2 ;
F_7 (c, &conn->chan_l, list) {
if ( V_2 -> V_7 == V_6 )
return V_2 ;
}
return NULL ;
}
static struct V_1 * F_8 ( struct V_4 * V_5 , T_1 V_6 )
{
struct V_1 * V_2 ;
F_7 (c, &conn->chan_l, list) {
if ( V_2 -> V_8 == V_6 )
return V_2 ;
}
return NULL ;
}
static struct V_1 * F_9 ( struct V_4 * V_5 , T_1 V_6 )
{
struct V_1 * V_2 ;
F_10 ( & V_5 -> V_9 ) ;
V_2 = F_8 ( V_5 , V_6 ) ;
if ( V_2 )
F_11 ( V_2 -> V_10 ) ;
F_12 ( & V_5 -> V_9 ) ;
return V_2 ;
}
static struct V_1 * F_13 ( struct V_4 * V_5 , T_2 V_11 )
{
struct V_1 * V_2 ;
F_7 (c, &conn->chan_l, list) {
if ( V_2 -> V_11 == V_11 )
return V_2 ;
}
return NULL ;
}
static inline struct V_1 * F_14 ( struct V_4 * V_5 , T_2 V_11 )
{
struct V_1 * V_2 ;
F_10 ( & V_5 -> V_9 ) ;
V_2 = F_13 ( V_5 , V_11 ) ;
if ( V_2 )
F_11 ( V_2 -> V_10 ) ;
F_12 ( & V_5 -> V_9 ) ;
return V_2 ;
}
static struct V_1 * F_15 ( T_3 V_12 , T_4 * V_13 )
{
struct V_1 * V_2 ;
F_7 (c, &chan_list, global_l) {
if ( V_2 -> V_14 == V_12 && ! F_16 ( & F_17 ( V_2 -> V_10 ) -> V_13 , V_13 ) )
goto V_15;
}
V_2 = NULL ;
V_15:
return V_2 ;
}
int F_18 ( struct V_1 * V_16 , T_4 * V_13 , T_3 V_12 )
{
int V_17 ;
F_19 ( & V_18 ) ;
if ( V_12 && F_15 ( V_12 , V_13 ) ) {
V_17 = - V_19 ;
goto V_20;
}
if ( V_12 ) {
V_16 -> V_12 = V_12 ;
V_16 -> V_14 = V_12 ;
V_17 = 0 ;
} else {
T_1 V_21 ;
V_17 = - V_22 ;
for ( V_21 = 0x1001 ; V_21 < 0x1100 ; V_21 += 2 )
if ( ! F_15 ( F_20 ( V_21 ) , V_13 ) ) {
V_16 -> V_12 = F_20 ( V_21 ) ;
V_16 -> V_14 = F_20 ( V_21 ) ;
V_17 = 0 ;
break;
}
}
V_20:
F_21 ( & V_18 ) ;
return V_17 ;
}
int F_22 ( struct V_1 * V_16 , T_5 V_8 )
{
F_19 ( & V_18 ) ;
V_16 -> V_8 = V_8 ;
F_21 ( & V_18 ) ;
return 0 ;
}
static T_1 F_23 ( struct V_4 * V_5 )
{
T_1 V_6 = V_23 ;
for (; V_6 < V_24 ; V_6 ++ ) {
if ( ! F_8 ( V_5 , V_6 ) )
return V_6 ;
}
return 0 ;
}
static void F_24 ( struct V_1 * V_16 , struct V_25 * V_26 , long V_27 )
{
F_25 ( L_1 , V_16 -> V_10 , V_16 -> V_28 , V_27 ) ;
if ( ! F_26 ( V_26 , V_29 + F_27 ( V_27 ) ) )
F_1 ( V_16 ) ;
}
static void F_28 ( struct V_1 * V_16 , struct V_25 * V_26 )
{
F_25 ( L_2 , V_16 , V_16 -> V_28 ) ;
if ( F_29 ( V_26 ) && F_30 ( V_26 ) )
F_3 ( V_16 ) ;
}
static void F_31 ( struct V_1 * V_16 , int V_28 )
{
V_16 -> V_28 = V_28 ;
V_16 -> V_30 -> V_31 ( V_16 -> V_32 , V_28 ) ;
}
static void F_32 ( unsigned long V_33 )
{
struct V_1 * V_16 = (struct V_1 * ) V_33 ;
struct V_34 * V_10 = V_16 -> V_10 ;
int V_35 ;
F_25 ( L_2 , V_16 , V_16 -> V_28 ) ;
F_11 ( V_10 ) ;
if ( F_33 ( V_10 ) ) {
F_34 ( V_16 , V_36 ) ;
F_35 ( V_10 ) ;
F_3 ( V_16 ) ;
return;
}
if ( V_16 -> V_28 == V_37 || V_16 -> V_28 == V_38 )
V_35 = V_39 ;
else if ( V_16 -> V_28 == V_40 &&
V_16 -> V_41 != V_42 )
V_35 = V_39 ;
else
V_35 = V_43 ;
F_36 ( V_16 , V_35 ) ;
F_35 ( V_10 ) ;
V_16 -> V_30 -> V_44 ( V_16 -> V_32 ) ;
F_3 ( V_16 ) ;
}
struct V_1 * F_37 ( struct V_34 * V_10 )
{
struct V_1 * V_16 ;
V_16 = F_38 ( sizeof( * V_16 ) , V_45 ) ;
if ( ! V_16 )
return NULL ;
V_16 -> V_10 = V_10 ;
F_19 ( & V_18 ) ;
F_39 ( & V_16 -> V_46 , & V_47 ) ;
F_21 ( & V_18 ) ;
F_40 ( & V_16 -> V_48 , F_32 , ( unsigned long ) V_16 ) ;
V_16 -> V_28 = V_49 ;
F_41 ( & V_16 -> V_3 , 1 ) ;
return V_16 ;
}
void F_42 ( struct V_1 * V_16 )
{
F_19 ( & V_18 ) ;
F_43 ( & V_16 -> V_46 ) ;
F_21 ( & V_18 ) ;
F_3 ( V_16 ) ;
}
static void F_44 ( struct V_4 * V_5 , struct V_1 * V_16 )
{
F_25 ( L_3 , V_5 ,
V_16 -> V_12 , V_16 -> V_7 ) ;
V_5 -> V_50 = 0x13 ;
V_16 -> V_5 = V_5 ;
if ( V_16 -> V_51 == V_52 ) {
if ( V_5 -> V_53 -> type == V_54 ) {
V_16 -> V_55 = V_56 ;
V_16 -> V_8 = V_57 ;
V_16 -> V_7 = V_57 ;
} else {
V_16 -> V_8 = F_23 ( V_5 ) ;
V_16 -> V_55 = V_58 ;
}
} else if ( V_16 -> V_51 == V_59 ) {
V_16 -> V_8 = V_60 ;
V_16 -> V_7 = V_60 ;
V_16 -> V_55 = V_58 ;
} else {
V_16 -> V_8 = V_61 ;
V_16 -> V_7 = V_61 ;
V_16 -> V_55 = V_58 ;
}
F_1 ( V_16 ) ;
F_39 ( & V_16 -> V_62 , & V_5 -> V_63 ) ;
}
static void F_45 ( struct V_1 * V_16 , int V_17 )
{
struct V_34 * V_10 = V_16 -> V_10 ;
struct V_4 * V_5 = V_16 -> V_5 ;
struct V_34 * V_64 = F_17 ( V_10 ) -> V_64 ;
F_46 ( V_16 ) ;
F_25 ( L_4 , V_16 , V_5 , V_17 ) ;
if ( V_5 ) {
F_19 ( & V_5 -> V_9 ) ;
F_43 ( & V_16 -> V_62 ) ;
F_21 ( & V_5 -> V_9 ) ;
F_3 ( V_16 ) ;
V_16 -> V_5 = NULL ;
F_47 ( V_5 -> V_53 ) ;
}
F_31 ( V_16 , V_65 ) ;
F_48 ( V_10 , V_66 ) ;
if ( V_17 )
V_10 -> V_67 = V_17 ;
if ( V_64 ) {
F_49 ( V_10 ) ;
V_64 -> V_68 ( V_64 , 0 ) ;
} else
V_10 -> V_69 ( V_10 ) ;
if ( ! ( F_50 ( V_70 , & V_16 -> V_71 ) &&
F_50 ( V_72 , & V_16 -> V_71 ) ) )
return;
F_51 ( & V_16 -> V_73 ) ;
if ( V_16 -> V_74 == V_75 ) {
struct V_76 * V_77 , * V_78 ;
F_52 ( V_16 ) ;
F_53 ( V_16 ) ;
F_54 ( V_16 ) ;
F_51 ( & V_16 -> V_79 ) ;
F_55 (l, tmp, &chan->srej_l, list) {
F_43 ( & V_77 -> V_62 ) ;
F_5 ( V_77 ) ;
}
}
}
static void F_56 ( struct V_34 * V_64 )
{
struct V_34 * V_10 ;
F_25 ( L_5 , V_64 ) ;
while ( ( V_10 = F_57 ( V_64 , NULL ) ) ) {
struct V_1 * V_16 = F_58 ( V_10 ) -> V_16 ;
F_46 ( V_16 ) ;
F_59 ( V_10 ) ;
F_36 ( V_16 , V_80 ) ;
F_60 ( V_10 ) ;
V_16 -> V_30 -> V_44 ( V_16 -> V_32 ) ;
}
}
void F_36 ( struct V_1 * V_16 , int V_35 )
{
struct V_4 * V_5 = V_16 -> V_5 ;
struct V_34 * V_10 = V_16 -> V_10 ;
F_25 ( L_6 , V_16 , V_16 -> V_28 , V_10 -> V_81 ) ;
switch ( V_16 -> V_28 ) {
case V_82 :
F_56 ( V_10 ) ;
F_31 ( V_16 , V_65 ) ;
F_48 ( V_10 , V_66 ) ;
break;
case V_37 :
case V_38 :
if ( V_16 -> V_51 == V_52 &&
V_5 -> V_53 -> type == V_83 ) {
F_46 ( V_16 ) ;
F_34 ( V_16 , V_10 -> V_84 ) ;
F_61 ( V_5 , V_16 , V_35 ) ;
} else
F_45 ( V_16 , V_35 ) ;
break;
case V_85 :
if ( V_16 -> V_51 == V_52 &&
V_5 -> V_53 -> type == V_83 ) {
struct V_86 V_87 ;
T_5 V_88 ;
if ( F_17 ( V_10 ) -> V_89 )
V_88 = V_90 ;
else
V_88 = V_91 ;
F_31 ( V_16 , V_92 ) ;
V_87 . V_8 = F_20 ( V_16 -> V_7 ) ;
V_87 . V_7 = F_20 ( V_16 -> V_8 ) ;
V_87 . V_88 = F_20 ( V_88 ) ;
V_87 . V_93 = F_20 ( V_94 ) ;
F_62 ( V_5 , V_16 -> V_11 , V_95 ,
sizeof( V_87 ) , & V_87 ) ;
}
F_45 ( V_16 , V_35 ) ;
break;
case V_40 :
case V_92 :
F_45 ( V_16 , V_35 ) ;
break;
default:
F_48 ( V_10 , V_66 ) ;
break;
}
}
static inline T_2 F_63 ( struct V_1 * V_16 )
{
if ( V_16 -> V_51 == V_96 ) {
switch ( V_16 -> V_41 ) {
case V_97 :
return V_98 ;
case V_99 :
return V_100 ;
default:
return V_101 ;
}
} else if ( V_16 -> V_12 == F_20 ( 0x0001 ) ) {
if ( V_16 -> V_41 == V_102 )
V_16 -> V_41 = V_42 ;
if ( V_16 -> V_41 == V_97 )
return V_103 ;
else
return V_101 ;
} else {
switch ( V_16 -> V_41 ) {
case V_97 :
return V_104 ;
case V_99 :
return V_105 ;
default:
return V_101 ;
}
}
}
static inline int F_64 ( struct V_1 * V_16 )
{
struct V_4 * V_5 = V_16 -> V_5 ;
T_6 V_106 ;
V_106 = F_63 ( V_16 ) ;
return F_65 ( V_5 -> V_53 , V_16 -> V_41 , V_106 ) ;
}
static T_2 F_66 ( struct V_4 * V_5 )
{
T_2 V_107 ;
F_67 ( & V_5 -> V_108 ) ;
if ( ++ V_5 -> V_109 > 128 )
V_5 -> V_109 = 1 ;
V_107 = V_5 -> V_109 ;
F_68 ( & V_5 -> V_108 ) ;
return V_107 ;
}
static void F_62 ( struct V_4 * V_5 , T_2 V_11 , T_2 V_110 , T_1 V_111 , void * V_32 )
{
struct V_112 * V_113 = F_69 ( V_5 , V_110 , V_11 , V_111 , V_32 ) ;
T_2 V_114 ;
F_25 ( L_7 , V_110 ) ;
if ( ! V_113 )
return;
if ( F_70 ( V_5 -> V_53 -> V_115 ) )
V_114 = V_116 ;
else
V_114 = V_117 ;
F_71 ( V_113 ) -> V_118 = V_119 ;
F_72 ( V_5 -> V_53 , V_113 , V_114 ) ;
}
static inline void F_73 ( struct V_1 * V_16 , T_1 V_120 )
{
struct V_112 * V_113 ;
struct V_121 * V_122 ;
struct V_4 * V_5 = V_16 -> V_5 ;
int V_123 , V_124 = V_125 + 2 ;
T_2 V_114 ;
if ( V_16 -> V_28 != V_37 )
return;
if ( V_16 -> V_126 == V_127 )
V_124 += 2 ;
F_25 ( L_8 , V_16 , V_120 ) ;
V_123 = F_74 (unsigned int, conn->mtu, hlen) ;
V_120 |= V_128 ;
if ( F_75 ( V_129 , & V_16 -> V_130 ) )
V_120 |= V_131 ;
if ( F_75 ( V_132 , & V_16 -> V_130 ) )
V_120 |= V_133 ;
V_113 = F_76 ( V_123 , V_45 ) ;
if ( ! V_113 )
return;
V_122 = (struct V_121 * ) F_77 ( V_113 , V_125 ) ;
V_122 -> V_111 = F_20 ( V_124 - V_125 ) ;
V_122 -> V_6 = F_20 ( V_16 -> V_7 ) ;
F_78 ( V_120 , F_77 ( V_113 , 2 ) ) ;
if ( V_16 -> V_126 == V_127 ) {
T_1 V_126 = F_79 ( 0 , ( T_2 * ) V_122 , V_123 - 2 ) ;
F_78 ( V_126 , F_77 ( V_113 , 2 ) ) ;
}
if ( F_70 ( V_5 -> V_53 -> V_115 ) )
V_114 = V_116 ;
else
V_114 = V_117 ;
F_71 ( V_113 ) -> V_118 = V_16 -> V_118 ;
F_72 ( V_16 -> V_5 -> V_53 , V_113 , V_114 ) ;
}
static inline void F_80 ( struct V_1 * V_16 , T_1 V_120 )
{
if ( F_50 ( V_134 , & V_16 -> V_130 ) ) {
V_120 |= V_135 ;
F_81 ( V_136 , & V_16 -> V_130 ) ;
} else
V_120 |= V_137 ;
V_120 |= V_16 -> V_138 << V_139 ;
F_73 ( V_16 , V_120 ) ;
}
static inline int F_82 ( struct V_1 * V_16 )
{
return ! F_50 ( V_140 , & V_16 -> V_71 ) ;
}
static void F_83 ( struct V_1 * V_16 )
{
struct V_4 * V_5 = V_16 -> V_5 ;
if ( V_5 -> V_141 & V_142 ) {
if ( ! ( V_5 -> V_141 & V_143 ) )
return;
if ( F_64 ( V_16 ) &&
F_82 ( V_16 ) ) {
struct V_144 V_145 ;
V_145 . V_8 = F_20 ( V_16 -> V_8 ) ;
V_145 . V_12 = V_16 -> V_12 ;
V_16 -> V_11 = F_66 ( V_5 ) ;
F_81 ( V_140 , & V_16 -> V_71 ) ;
F_62 ( V_5 , V_16 -> V_11 , V_146 ,
sizeof( V_145 ) , & V_145 ) ;
}
} else {
struct V_147 V_145 ;
V_145 . type = F_20 ( V_148 ) ;
V_5 -> V_141 |= V_142 ;
V_5 -> V_149 = F_66 ( V_5 ) ;
F_26 ( & V_5 -> V_150 , V_29 +
F_27 ( V_151 ) ) ;
F_62 ( V_5 , V_5 -> V_149 ,
V_152 , sizeof( V_145 ) , & V_145 ) ;
}
}
static inline int F_84 ( T_6 V_74 , T_7 V_153 )
{
T_8 V_154 = V_155 ;
if ( ! V_156 )
V_154 |= V_157 | V_158 ;
switch ( V_74 ) {
case V_75 :
return V_157 & V_153 & V_154 ;
case V_159 :
return V_158 & V_153 & V_154 ;
default:
return 0x00 ;
}
}
static void F_61 ( struct V_4 * V_5 , struct V_1 * V_16 , int V_17 )
{
struct V_34 * V_10 ;
struct V_160 V_145 ;
if ( ! V_5 )
return;
V_10 = V_16 -> V_10 ;
if ( V_16 -> V_74 == V_75 ) {
F_52 ( V_16 ) ;
F_53 ( V_16 ) ;
F_54 ( V_16 ) ;
}
V_145 . V_7 = F_20 ( V_16 -> V_7 ) ;
V_145 . V_8 = F_20 ( V_16 -> V_8 ) ;
F_62 ( V_5 , F_66 ( V_5 ) ,
V_161 , sizeof( V_145 ) , & V_145 ) ;
F_31 ( V_16 , V_92 ) ;
V_10 -> V_67 = V_17 ;
}
static void F_85 ( struct V_4 * V_5 )
{
struct V_1 * V_16 , * V_78 ;
F_25 ( L_9 , V_5 ) ;
F_10 ( & V_5 -> V_9 ) ;
F_55 (chan, tmp, &conn->chan_l, list) {
struct V_34 * V_10 = V_16 -> V_10 ;
F_11 ( V_10 ) ;
if ( V_16 -> V_51 != V_52 ) {
F_35 ( V_10 ) ;
continue;
}
if ( V_16 -> V_28 == V_40 ) {
struct V_144 V_145 ;
if ( ! F_64 ( V_16 ) ||
! F_82 ( V_16 ) ) {
F_35 ( V_10 ) ;
continue;
}
if ( ! F_84 ( V_16 -> V_74 , V_5 -> V_153 )
&& F_50 ( V_162 ,
& V_16 -> V_71 ) ) {
F_12 ( & V_5 -> V_9 ) ;
F_36 ( V_16 , V_80 ) ;
F_10 ( & V_5 -> V_9 ) ;
F_35 ( V_10 ) ;
continue;
}
V_145 . V_8 = F_20 ( V_16 -> V_8 ) ;
V_145 . V_12 = V_16 -> V_12 ;
V_16 -> V_11 = F_66 ( V_5 ) ;
F_81 ( V_140 , & V_16 -> V_71 ) ;
F_62 ( V_5 , V_16 -> V_11 , V_146 ,
sizeof( V_145 ) , & V_145 ) ;
} else if ( V_16 -> V_28 == V_85 ) {
struct V_86 V_87 ;
char V_163 [ 128 ] ;
V_87 . V_8 = F_20 ( V_16 -> V_7 ) ;
V_87 . V_7 = F_20 ( V_16 -> V_8 ) ;
if ( F_64 ( V_16 ) ) {
if ( F_17 ( V_10 ) -> V_89 ) {
struct V_34 * V_64 = F_17 ( V_10 ) -> V_64 ;
V_87 . V_88 = F_20 ( V_164 ) ;
V_87 . V_93 = F_20 ( V_165 ) ;
if ( V_64 )
V_64 -> V_68 ( V_64 , 0 ) ;
} else {
F_31 ( V_16 , V_38 ) ;
V_87 . V_88 = F_20 ( V_166 ) ;
V_87 . V_93 = F_20 ( V_94 ) ;
}
} else {
V_87 . V_88 = F_20 ( V_164 ) ;
V_87 . V_93 = F_20 ( V_167 ) ;
}
F_62 ( V_5 , V_16 -> V_11 , V_95 ,
sizeof( V_87 ) , & V_87 ) ;
if ( F_50 ( V_168 , & V_16 -> V_71 ) ||
V_87 . V_88 != V_166 ) {
F_35 ( V_10 ) ;
continue;
}
F_81 ( V_168 , & V_16 -> V_71 ) ;
F_62 ( V_5 , F_66 ( V_5 ) , V_169 ,
F_86 ( V_16 , V_163 ) , V_163 ) ;
V_16 -> V_170 ++ ;
}
F_35 ( V_10 ) ;
}
F_12 ( & V_5 -> V_9 ) ;
}
static struct V_1 * F_87 ( int V_28 , T_3 V_6 , T_4 * V_13 )
{
struct V_1 * V_2 , * V_171 = NULL ;
F_10 ( & V_18 ) ;
F_7 (c, &chan_list, global_l) {
struct V_34 * V_10 = V_2 -> V_10 ;
if ( V_28 && V_2 -> V_28 != V_28 )
continue;
if ( V_2 -> V_8 == V_6 ) {
if ( ! F_16 ( & F_17 ( V_10 ) -> V_13 , V_13 ) ) {
F_12 ( & V_18 ) ;
return V_2 ;
}
if ( ! F_16 ( & F_17 ( V_10 ) -> V_13 , V_172 ) )
V_171 = V_2 ;
}
}
F_12 ( & V_18 ) ;
return V_171 ;
}
static void F_88 ( struct V_4 * V_5 )
{
struct V_34 * V_64 , * V_10 ;
struct V_1 * V_16 , * V_173 ;
F_25 ( L_10 ) ;
V_173 = F_87 ( V_82 , V_57 ,
V_5 -> V_13 ) ;
if ( ! V_173 )
return;
V_64 = V_173 -> V_10 ;
F_11 ( V_64 ) ;
if ( F_89 ( V_64 ) ) {
F_25 ( L_11 , V_64 -> V_174 ) ;
goto V_175;
}
V_16 = V_173 -> V_30 -> V_176 ( V_173 -> V_32 ) ;
if ( ! V_16 )
goto V_175;
V_10 = V_16 -> V_10 ;
F_19 ( & V_5 -> V_9 ) ;
F_90 ( V_5 -> V_53 ) ;
F_91 ( & F_17 ( V_10 ) -> V_13 , V_5 -> V_13 ) ;
F_91 ( & F_17 ( V_10 ) -> V_177 , V_5 -> V_177 ) ;
F_92 ( V_64 , V_10 ) ;
F_44 ( V_5 , V_16 ) ;
F_34 ( V_16 , V_10 -> V_84 ) ;
F_31 ( V_16 , V_37 ) ;
V_64 -> V_68 ( V_64 , 0 ) ;
F_21 ( & V_5 -> V_9 ) ;
V_175:
F_35 ( V_64 ) ;
}
static void F_93 ( struct V_34 * V_10 )
{
struct V_1 * V_16 = F_58 ( V_10 ) -> V_16 ;
struct V_34 * V_64 = F_17 ( V_10 ) -> V_64 ;
F_25 ( L_12 , V_10 , V_64 ) ;
V_16 -> V_71 = 0 ;
F_46 ( V_16 ) ;
F_31 ( V_16 , V_37 ) ;
V_10 -> V_69 ( V_10 ) ;
if ( V_64 )
V_64 -> V_68 ( V_64 , 0 ) ;
}
static void F_94 ( struct V_4 * V_5 )
{
struct V_1 * V_16 ;
F_25 ( L_9 , V_5 ) ;
if ( ! V_5 -> V_53 -> V_178 && V_5 -> V_53 -> type == V_54 )
F_88 ( V_5 ) ;
if ( V_5 -> V_53 -> V_178 && V_5 -> V_53 -> type == V_54 )
F_95 ( V_5 , V_5 -> V_53 -> V_179 ) ;
F_10 ( & V_5 -> V_9 ) ;
F_7 (chan, &conn->chan_l, list) {
struct V_34 * V_10 = V_16 -> V_10 ;
F_11 ( V_10 ) ;
if ( V_5 -> V_53 -> type == V_54 ) {
if ( F_95 ( V_5 , V_16 -> V_41 ) )
F_93 ( V_10 ) ;
} else if ( V_16 -> V_51 != V_52 ) {
F_46 ( V_16 ) ;
F_31 ( V_16 , V_37 ) ;
V_10 -> V_69 ( V_10 ) ;
} else if ( V_16 -> V_28 == V_40 )
F_83 ( V_16 ) ;
F_35 ( V_10 ) ;
}
F_12 ( & V_5 -> V_9 ) ;
}
static void F_96 ( struct V_4 * V_5 , int V_17 )
{
struct V_1 * V_16 ;
F_25 ( L_9 , V_5 ) ;
F_10 ( & V_5 -> V_9 ) ;
F_7 (chan, &conn->chan_l, list) {
struct V_34 * V_10 = V_16 -> V_10 ;
if ( V_16 -> V_180 )
V_10 -> V_67 = V_17 ;
}
F_12 ( & V_5 -> V_9 ) ;
}
static void F_97 ( unsigned long V_33 )
{
struct V_4 * V_5 = ( void * ) V_33 ;
V_5 -> V_141 |= V_143 ;
V_5 -> V_149 = 0 ;
F_85 ( V_5 ) ;
}
static void F_98 ( struct V_181 * V_53 , int V_17 )
{
struct V_4 * V_5 = V_53 -> V_182 ;
struct V_1 * V_16 , * V_77 ;
struct V_34 * V_10 ;
if ( ! V_5 )
return;
F_25 ( L_13 , V_53 , V_5 , V_17 ) ;
F_99 ( V_5 -> V_183 ) ;
F_55 (chan, l, &conn->chan_l, list) {
V_10 = V_16 -> V_10 ;
F_11 ( V_10 ) ;
F_45 ( V_16 , V_17 ) ;
F_35 ( V_10 ) ;
V_16 -> V_30 -> V_44 ( V_16 -> V_32 ) ;
}
if ( V_5 -> V_141 & V_142 )
F_100 ( & V_5 -> V_150 ) ;
if ( F_75 ( V_184 , & V_53 -> V_185 ) ) {
F_30 ( & V_5 -> V_186 ) ;
F_101 ( V_5 ) ;
}
V_53 -> V_182 = NULL ;
F_5 ( V_5 ) ;
}
static void F_102 ( unsigned long V_33 )
{
struct V_4 * V_5 = ( void * ) V_33 ;
F_98 ( V_5 -> V_53 , V_43 ) ;
}
static struct V_4 * F_103 ( struct V_181 * V_53 , T_2 V_93 )
{
struct V_4 * V_5 = V_53 -> V_182 ;
if ( V_5 || V_93 )
return V_5 ;
V_5 = F_38 ( sizeof( struct V_4 ) , V_45 ) ;
if ( ! V_5 )
return NULL ;
V_53 -> V_182 = V_5 ;
V_5 -> V_53 = V_53 ;
F_25 ( L_14 , V_53 , V_5 ) ;
if ( V_53 -> V_115 -> V_187 && V_53 -> type == V_54 )
V_5 -> V_188 = V_53 -> V_115 -> V_187 ;
else
V_5 -> V_188 = V_53 -> V_115 -> V_189 ;
V_5 -> V_13 = & V_53 -> V_115 -> V_190 ;
V_5 -> V_177 = & V_53 -> V_177 ;
V_5 -> V_153 = 0 ;
F_104 ( & V_5 -> V_108 ) ;
F_105 ( & V_5 -> V_9 ) ;
F_106 ( & V_5 -> V_63 ) ;
if ( V_53 -> type == V_54 )
F_40 ( & V_5 -> V_186 , F_102 ,
( unsigned long ) V_5 ) ;
else
F_40 ( & V_5 -> V_150 , F_97 ,
( unsigned long ) V_5 ) ;
V_5 -> V_50 = 0x13 ;
return V_5 ;
}
static inline void F_107 ( struct V_4 * V_5 , struct V_1 * V_16 )
{
F_19 ( & V_5 -> V_9 ) ;
F_44 ( V_5 , V_16 ) ;
F_21 ( & V_5 -> V_9 ) ;
}
static struct V_1 * F_108 ( int V_28 , T_3 V_12 , T_4 * V_13 )
{
struct V_1 * V_2 , * V_171 = NULL ;
F_10 ( & V_18 ) ;
F_7 (c, &chan_list, global_l) {
struct V_34 * V_10 = V_2 -> V_10 ;
if ( V_28 && V_2 -> V_28 != V_28 )
continue;
if ( V_2 -> V_12 == V_12 ) {
if ( ! F_16 ( & F_17 ( V_10 ) -> V_13 , V_13 ) ) {
F_12 ( & V_18 ) ;
return V_2 ;
}
if ( ! F_16 ( & F_17 ( V_10 ) -> V_13 , V_172 ) )
V_171 = V_2 ;
}
}
F_12 ( & V_18 ) ;
return V_171 ;
}
int F_109 ( struct V_1 * V_16 )
{
struct V_34 * V_10 = V_16 -> V_10 ;
T_4 * V_13 = & F_17 ( V_10 ) -> V_13 ;
T_4 * V_177 = & F_17 ( V_10 ) -> V_177 ;
struct V_4 * V_5 ;
struct V_181 * V_53 ;
struct V_191 * V_115 ;
T_6 V_106 ;
int V_17 ;
F_25 ( L_15 , F_110 ( V_13 ) , F_110 ( V_177 ) ,
V_16 -> V_12 ) ;
V_115 = F_111 ( V_177 , V_13 ) ;
if ( ! V_115 )
return - V_192 ;
F_112 ( V_115 ) ;
V_106 = F_63 ( V_16 ) ;
if ( V_16 -> V_7 == V_57 )
V_53 = F_113 ( V_115 , V_54 , V_177 ,
V_16 -> V_41 , V_106 ) ;
else
V_53 = F_113 ( V_115 , V_83 , V_177 ,
V_16 -> V_41 , V_106 ) ;
if ( F_114 ( V_53 ) ) {
V_17 = F_115 ( V_53 ) ;
goto V_20;
}
V_5 = F_103 ( V_53 , 0 ) ;
if ( ! V_5 ) {
F_47 ( V_53 ) ;
V_17 = - V_193 ;
goto V_20;
}
F_91 ( V_13 , V_5 -> V_13 ) ;
F_107 ( V_5 , V_16 ) ;
F_31 ( V_16 , V_40 ) ;
F_34 ( V_16 , V_10 -> V_84 ) ;
if ( V_53 -> V_28 == V_37 ) {
if ( V_16 -> V_51 != V_52 ) {
F_46 ( V_16 ) ;
if ( F_64 ( V_16 ) )
F_31 ( V_16 , V_37 ) ;
} else
F_83 ( V_16 ) ;
}
V_17 = 0 ;
V_20:
F_116 ( V_115 ) ;
F_117 ( V_115 ) ;
return V_17 ;
}
int F_118 ( struct V_34 * V_10 )
{
struct V_1 * V_16 = F_58 ( V_10 ) -> V_16 ;
F_119 ( V_194 , V_195 ) ;
int V_17 = 0 ;
int V_196 = V_197 / 5 ;
F_120 ( F_121 ( V_10 ) , & V_194 ) ;
F_122 ( V_198 ) ;
while ( V_16 -> V_199 > 0 && V_16 -> V_5 ) {
if ( ! V_196 )
V_196 = V_197 / 5 ;
if ( F_123 ( V_195 ) ) {
V_17 = F_124 ( V_196 ) ;
break;
}
F_60 ( V_10 ) ;
V_196 = F_125 ( V_196 ) ;
F_59 ( V_10 ) ;
F_122 ( V_198 ) ;
V_17 = F_126 ( V_10 ) ;
if ( V_17 )
break;
}
F_122 ( V_200 ) ;
F_127 ( F_121 ( V_10 ) , & V_194 ) ;
return V_17 ;
}
static void F_128 ( unsigned long V_33 )
{
struct V_1 * V_16 = ( void * ) V_33 ;
struct V_34 * V_10 = V_16 -> V_10 ;
F_25 ( L_16 , V_16 ) ;
F_11 ( V_10 ) ;
if ( V_16 -> V_201 >= V_16 -> V_202 ) {
F_61 ( V_16 -> V_5 , V_16 , V_203 ) ;
F_35 ( V_10 ) ;
return;
}
V_16 -> V_201 ++ ;
F_129 ( V_16 ) ;
F_80 ( V_16 , V_133 ) ;
F_35 ( V_10 ) ;
}
static void F_130 ( unsigned long V_33 )
{
struct V_1 * V_16 = ( void * ) V_33 ;
struct V_34 * V_10 = V_16 -> V_10 ;
F_25 ( L_16 , V_16 ) ;
F_11 ( V_10 ) ;
V_16 -> V_201 = 1 ;
F_129 ( V_16 ) ;
F_81 ( V_204 , & V_16 -> V_130 ) ;
F_80 ( V_16 , V_133 ) ;
F_35 ( V_10 ) ;
}
static void F_131 ( struct V_1 * V_16 )
{
struct V_112 * V_113 ;
while ( ( V_113 = F_132 ( & V_16 -> V_73 ) ) &&
V_16 -> V_199 ) {
if ( F_71 ( V_113 ) -> V_205 == V_16 -> V_206 )
break;
V_113 = F_133 ( & V_16 -> V_73 ) ;
F_99 ( V_113 ) ;
V_16 -> V_199 -- ;
}
if ( ! V_16 -> V_199 )
F_52 ( V_16 ) ;
}
static void F_134 ( struct V_1 * V_16 , struct V_112 * V_113 )
{
struct V_181 * V_53 = V_16 -> V_5 -> V_53 ;
T_1 V_114 ;
F_25 ( L_17 , V_16 , V_113 , V_113 -> V_111 ) ;
if ( ! V_16 -> V_207 && F_70 ( V_53 -> V_115 ) )
V_114 = V_116 ;
else
V_114 = V_117 ;
F_71 ( V_113 ) -> V_118 = V_16 -> V_118 ;
F_72 ( V_53 , V_113 , V_114 ) ;
}
static void F_135 ( struct V_1 * V_16 )
{
struct V_112 * V_113 ;
T_1 V_120 , V_126 ;
while ( ( V_113 = F_133 ( & V_16 -> V_73 ) ) ) {
V_120 = F_136 ( V_113 -> V_32 + V_125 ) ;
V_120 |= V_16 -> V_208 << V_209 ;
F_78 ( V_120 , V_113 -> V_32 + V_125 ) ;
if ( V_16 -> V_126 == V_127 ) {
V_126 = F_79 ( 0 , ( T_2 * ) V_113 -> V_32 , V_113 -> V_111 - 2 ) ;
F_78 ( V_126 , V_113 -> V_32 + V_113 -> V_111 - 2 ) ;
}
F_134 ( V_16 , V_113 ) ;
V_16 -> V_208 = ( V_16 -> V_208 + 1 ) % 64 ;
}
}
static void F_137 ( struct V_1 * V_16 , T_2 V_205 )
{
struct V_112 * V_113 , * V_210 ;
T_1 V_120 , V_126 ;
V_113 = F_132 ( & V_16 -> V_73 ) ;
if ( ! V_113 )
return;
do {
if ( F_71 ( V_113 ) -> V_205 == V_205 )
break;
if ( F_138 ( & V_16 -> V_73 , V_113 ) )
return;
} while ( ( V_113 = F_139 ( & V_16 -> V_73 , V_113 ) ) );
if ( V_16 -> V_202 &&
F_71 ( V_113 ) -> V_211 == V_16 -> V_202 ) {
F_61 ( V_16 -> V_5 , V_16 , V_203 ) ;
return;
}
V_210 = F_140 ( V_113 , V_45 ) ;
F_71 ( V_113 ) -> V_211 ++ ;
V_120 = F_136 ( V_210 -> V_32 + V_125 ) ;
V_120 &= V_212 ;
if ( F_75 ( V_129 , & V_16 -> V_130 ) )
V_120 |= V_131 ;
V_120 |= ( V_16 -> V_138 << V_139 )
| ( V_205 << V_209 ) ;
F_78 ( V_120 , V_210 -> V_32 + V_125 ) ;
if ( V_16 -> V_126 == V_127 ) {
V_126 = F_79 ( 0 , ( T_2 * ) V_210 -> V_32 , V_210 -> V_111 - 2 ) ;
F_78 ( V_126 , V_210 -> V_32 + V_210 -> V_111 - 2 ) ;
}
F_134 ( V_16 , V_210 ) ;
}
static int F_141 ( struct V_1 * V_16 )
{
struct V_112 * V_113 , * V_210 ;
T_1 V_120 , V_126 ;
int V_213 = 0 ;
if ( V_16 -> V_28 != V_37 )
return - V_214 ;
while ( ( V_113 = V_16 -> V_215 ) && ( ! F_142 ( V_16 ) ) ) {
if ( V_16 -> V_202 &&
F_71 ( V_113 ) -> V_211 == V_16 -> V_202 ) {
F_61 ( V_16 -> V_5 , V_16 , V_203 ) ;
break;
}
V_210 = F_140 ( V_113 , V_45 ) ;
F_71 ( V_113 ) -> V_211 ++ ;
V_120 = F_136 ( V_210 -> V_32 + V_125 ) ;
V_120 &= V_212 ;
if ( F_75 ( V_129 , & V_16 -> V_130 ) )
V_120 |= V_131 ;
V_120 |= ( V_16 -> V_138 << V_139 )
| ( V_16 -> V_208 << V_209 ) ;
F_78 ( V_120 , V_210 -> V_32 + V_125 ) ;
if ( V_16 -> V_126 == V_127 ) {
V_126 = F_79 ( 0 , ( T_2 * ) V_113 -> V_32 , V_210 -> V_111 - 2 ) ;
F_78 ( V_126 , V_113 -> V_32 + V_210 -> V_111 - 2 ) ;
}
F_134 ( V_16 , V_210 ) ;
F_143 ( V_16 ) ;
F_71 ( V_113 ) -> V_205 = V_16 -> V_208 ;
V_16 -> V_208 = ( V_16 -> V_208 + 1 ) % 64 ;
if ( F_71 ( V_113 ) -> V_211 == 1 )
V_16 -> V_199 ++ ;
V_16 -> V_216 ++ ;
if ( F_138 ( & V_16 -> V_73 , V_113 ) )
V_16 -> V_215 = NULL ;
else
V_16 -> V_215 = F_139 ( & V_16 -> V_73 , V_113 ) ;
V_213 ++ ;
}
return V_213 ;
}
static int F_144 ( struct V_1 * V_16 )
{
int V_217 ;
if ( ! F_145 ( & V_16 -> V_73 ) )
V_16 -> V_215 = V_16 -> V_73 . V_218 ;
V_16 -> V_208 = V_16 -> V_206 ;
V_217 = F_141 ( V_16 ) ;
return V_217 ;
}
static void F_146 ( struct V_1 * V_16 )
{
T_1 V_120 = 0 ;
V_120 |= V_16 -> V_138 << V_139 ;
if ( F_50 ( V_134 , & V_16 -> V_130 ) ) {
V_120 |= V_135 ;
F_81 ( V_136 , & V_16 -> V_130 ) ;
F_73 ( V_16 , V_120 ) ;
return;
}
if ( F_141 ( V_16 ) > 0 )
return;
V_120 |= V_137 ;
F_73 ( V_16 , V_120 ) ;
}
static void F_147 ( struct V_1 * V_16 )
{
struct V_76 * V_219 ;
T_1 V_120 ;
V_120 = V_220 ;
V_120 |= V_131 ;
V_219 = F_148 ( ( & V_16 -> V_221 ) -> V_222 , struct V_76 , V_62 ) ;
V_120 |= V_219 -> V_205 << V_139 ;
F_73 ( V_16 , V_120 ) ;
}
static inline int F_149 ( struct V_34 * V_10 , struct V_223 * V_224 , int V_111 , int V_123 , struct V_112 * V_113 )
{
struct V_4 * V_5 = F_58 ( V_10 ) -> V_16 -> V_5 ;
struct V_112 * * V_225 ;
int V_17 , V_226 = 0 ;
if ( F_150 ( F_77 ( V_113 , V_123 ) , V_224 -> V_227 , V_123 ) )
return - V_228 ;
V_226 += V_123 ;
V_111 -= V_123 ;
V_225 = & F_151 ( V_113 ) -> V_229 ;
while ( V_111 ) {
V_123 = F_74 (unsigned int, conn->mtu, len) ;
* V_225 = F_152 ( V_10 , V_123 , V_224 -> V_230 & V_231 , & V_17 ) ;
if ( ! * V_225 )
return V_17 ;
if ( F_150 ( F_77 ( * V_225 , V_123 ) , V_224 -> V_227 , V_123 ) )
return - V_228 ;
V_226 += V_123 ;
V_111 -= V_123 ;
V_225 = & ( * V_225 ) -> V_218 ;
}
return V_226 ;
}
static struct V_112 * F_153 ( struct V_1 * V_16 , struct V_223 * V_224 , T_9 V_111 )
{
struct V_34 * V_10 = V_16 -> V_10 ;
struct V_4 * V_5 = V_16 -> V_5 ;
struct V_112 * V_113 ;
int V_17 , V_123 , V_124 = V_125 + 2 ;
struct V_121 * V_122 ;
F_25 ( L_18 , V_10 , ( int ) V_111 ) ;
V_123 = F_74 (unsigned int, (conn->mtu - hlen), len) ;
V_113 = F_152 ( V_10 , V_123 + V_124 ,
V_224 -> V_230 & V_231 , & V_17 ) ;
if ( ! V_113 )
return F_154 ( V_17 ) ;
V_122 = (struct V_121 * ) F_77 ( V_113 , V_125 ) ;
V_122 -> V_6 = F_20 ( V_16 -> V_7 ) ;
V_122 -> V_111 = F_20 ( V_111 + ( V_124 - V_125 ) ) ;
F_78 ( V_16 -> V_12 , F_77 ( V_113 , 2 ) ) ;
V_17 = F_149 ( V_10 , V_224 , V_111 , V_123 , V_113 ) ;
if ( F_155 ( V_17 < 0 ) ) {
F_99 ( V_113 ) ;
return F_154 ( V_17 ) ;
}
return V_113 ;
}
static struct V_112 * F_156 ( struct V_1 * V_16 , struct V_223 * V_224 , T_9 V_111 )
{
struct V_34 * V_10 = V_16 -> V_10 ;
struct V_4 * V_5 = V_16 -> V_5 ;
struct V_112 * V_113 ;
int V_17 , V_123 , V_124 = V_125 ;
struct V_121 * V_122 ;
F_25 ( L_18 , V_10 , ( int ) V_111 ) ;
V_123 = F_74 (unsigned int, (conn->mtu - hlen), len) ;
V_113 = F_152 ( V_10 , V_123 + V_124 ,
V_224 -> V_230 & V_231 , & V_17 ) ;
if ( ! V_113 )
return F_154 ( V_17 ) ;
V_122 = (struct V_121 * ) F_77 ( V_113 , V_125 ) ;
V_122 -> V_6 = F_20 ( V_16 -> V_7 ) ;
V_122 -> V_111 = F_20 ( V_111 + ( V_124 - V_125 ) ) ;
V_17 = F_149 ( V_10 , V_224 , V_111 , V_123 , V_113 ) ;
if ( F_155 ( V_17 < 0 ) ) {
F_99 ( V_113 ) ;
return F_154 ( V_17 ) ;
}
return V_113 ;
}
static struct V_112 * F_157 ( struct V_1 * V_16 ,
struct V_223 * V_224 , T_9 V_111 ,
T_1 V_120 , T_1 V_232 )
{
struct V_34 * V_10 = V_16 -> V_10 ;
struct V_4 * V_5 = V_16 -> V_5 ;
struct V_112 * V_113 ;
int V_17 , V_123 , V_124 = V_125 + 2 ;
struct V_121 * V_122 ;
F_25 ( L_18 , V_10 , ( int ) V_111 ) ;
if ( ! V_5 )
return F_154 ( - V_214 ) ;
if ( V_232 )
V_124 += 2 ;
if ( V_16 -> V_126 == V_127 )
V_124 += 2 ;
V_123 = F_74 (unsigned int, (conn->mtu - hlen), len) ;
V_113 = F_152 ( V_10 , V_123 + V_124 ,
V_224 -> V_230 & V_231 , & V_17 ) ;
if ( ! V_113 )
return F_154 ( V_17 ) ;
V_122 = (struct V_121 * ) F_77 ( V_113 , V_125 ) ;
V_122 -> V_6 = F_20 ( V_16 -> V_7 ) ;
V_122 -> V_111 = F_20 ( V_111 + ( V_124 - V_125 ) ) ;
F_78 ( V_120 , F_77 ( V_113 , 2 ) ) ;
if ( V_232 )
F_78 ( V_232 , F_77 ( V_113 , 2 ) ) ;
V_17 = F_149 ( V_10 , V_224 , V_111 , V_123 , V_113 ) ;
if ( F_155 ( V_17 < 0 ) ) {
F_99 ( V_113 ) ;
return F_154 ( V_17 ) ;
}
if ( V_16 -> V_126 == V_127 )
F_78 ( 0 , F_77 ( V_113 , 2 ) ) ;
F_71 ( V_113 ) -> V_211 = 0 ;
return V_113 ;
}
static int F_158 ( struct V_1 * V_16 , struct V_223 * V_224 , T_9 V_111 )
{
struct V_112 * V_113 ;
struct V_233 V_234 ;
T_1 V_120 ;
T_9 V_235 = 0 ;
F_159 ( & V_234 ) ;
V_120 = V_236 ;
V_113 = F_157 ( V_16 , V_224 , V_16 -> V_237 , V_120 , V_111 ) ;
if ( F_114 ( V_113 ) )
return F_115 ( V_113 ) ;
F_160 ( & V_234 , V_113 ) ;
V_111 -= V_16 -> V_237 ;
V_235 += V_16 -> V_237 ;
while ( V_111 > 0 ) {
T_9 V_238 ;
if ( V_111 > V_16 -> V_237 ) {
V_120 = V_239 ;
V_238 = V_16 -> V_237 ;
} else {
V_120 = V_240 ;
V_238 = V_111 ;
}
V_113 = F_157 ( V_16 , V_224 , V_238 , V_120 , 0 ) ;
if ( F_114 ( V_113 ) ) {
F_51 ( & V_234 ) ;
return F_115 ( V_113 ) ;
}
F_160 ( & V_234 , V_113 ) ;
V_111 -= V_238 ;
V_235 += V_238 ;
}
F_161 ( & V_234 , & V_16 -> V_73 ) ;
if ( V_16 -> V_215 == NULL )
V_16 -> V_215 = V_234 . V_218 ;
return V_235 ;
}
int F_162 ( struct V_1 * V_16 , struct V_223 * V_224 , T_9 V_111 )
{
struct V_112 * V_113 ;
T_1 V_120 ;
int V_17 ;
if ( V_16 -> V_51 == V_59 ) {
V_113 = F_153 ( V_16 , V_224 , V_111 ) ;
if ( F_114 ( V_113 ) )
return F_115 ( V_113 ) ;
F_134 ( V_16 , V_113 ) ;
return V_111 ;
}
switch ( V_16 -> V_74 ) {
case V_241 :
if ( V_111 > V_16 -> V_55 )
return - V_242 ;
V_113 = F_156 ( V_16 , V_224 , V_111 ) ;
if ( F_114 ( V_113 ) )
return F_115 ( V_113 ) ;
F_134 ( V_16 , V_113 ) ;
V_17 = V_111 ;
break;
case V_75 :
case V_159 :
if ( V_111 <= V_16 -> V_237 ) {
V_120 = V_243 ;
V_113 = F_157 ( V_16 , V_224 , V_111 , V_120 ,
0 ) ;
if ( F_114 ( V_113 ) )
return F_115 ( V_113 ) ;
F_160 ( & V_16 -> V_73 , V_113 ) ;
if ( V_16 -> V_215 == NULL )
V_16 -> V_215 = V_113 ;
} else {
V_17 = F_158 ( V_16 , V_224 , V_111 ) ;
if ( V_17 < 0 )
return V_17 ;
}
if ( V_16 -> V_74 == V_159 ) {
F_135 ( V_16 ) ;
V_17 = V_111 ;
break;
}
if ( F_50 ( V_244 , & V_16 -> V_130 ) &&
F_50 ( V_204 , & V_16 -> V_130 ) ) {
V_17 = V_111 ;
break;
}
V_17 = F_141 ( V_16 ) ;
if ( V_17 >= 0 )
V_17 = V_111 ;
break;
default:
F_25 ( L_19 , V_16 -> V_74 ) ;
V_17 = - V_245 ;
}
return V_17 ;
}
static void F_163 ( struct V_4 * V_5 , struct V_112 * V_113 )
{
struct V_112 * V_246 ;
struct V_1 * V_16 ;
F_25 ( L_9 , V_5 ) ;
F_10 ( & V_5 -> V_9 ) ;
F_7 (chan, &conn->chan_l, list) {
struct V_34 * V_10 = V_16 -> V_10 ;
if ( V_16 -> V_51 != V_96 )
continue;
if ( V_113 -> V_10 == V_10 )
continue;
V_246 = F_140 ( V_113 , V_45 ) ;
if ( ! V_246 )
continue;
if ( V_16 -> V_30 -> V_247 ( V_16 -> V_32 , V_246 ) )
F_99 ( V_246 ) ;
}
F_12 ( & V_5 -> V_9 ) ;
}
static struct V_112 * F_69 ( struct V_4 * V_5 ,
T_2 V_110 , T_2 V_11 , T_1 V_248 , void * V_32 )
{
struct V_112 * V_113 , * * V_225 ;
struct V_249 * V_250 ;
struct V_121 * V_122 ;
int V_111 , V_123 ;
F_25 ( L_20 ,
V_5 , V_110 , V_11 , V_248 ) ;
V_111 = V_125 + V_251 + V_248 ;
V_123 = F_74 (unsigned int, conn->mtu, len) ;
V_113 = F_76 ( V_123 , V_45 ) ;
if ( ! V_113 )
return NULL ;
V_122 = (struct V_121 * ) F_77 ( V_113 , V_125 ) ;
V_122 -> V_111 = F_20 ( V_251 + V_248 ) ;
if ( V_5 -> V_53 -> type == V_54 )
V_122 -> V_6 = F_20 ( V_252 ) ;
else
V_122 -> V_6 = F_20 ( V_61 ) ;
V_250 = (struct V_249 * ) F_77 ( V_113 , V_251 ) ;
V_250 -> V_110 = V_110 ;
V_250 -> V_11 = V_11 ;
V_250 -> V_111 = F_20 ( V_248 ) ;
if ( V_248 ) {
V_123 -= V_125 + V_251 ;
memcpy ( F_77 ( V_113 , V_123 ) , V_32 , V_123 ) ;
V_32 += V_123 ;
}
V_111 -= V_113 -> V_111 ;
V_225 = & F_151 ( V_113 ) -> V_229 ;
while ( V_111 ) {
V_123 = F_74 (unsigned int, conn->mtu, len) ;
* V_225 = F_76 ( V_123 , V_45 ) ;
if ( ! * V_225 )
goto V_253;
memcpy ( F_77 ( * V_225 , V_123 ) , V_32 , V_123 ) ;
V_111 -= V_123 ;
V_32 += V_123 ;
V_225 = & ( * V_225 ) -> V_218 ;
}
return V_113 ;
V_253:
F_99 ( V_113 ) ;
return NULL ;
}
static inline int F_164 ( void * * V_254 , int * type , int * V_255 , unsigned long * V_256 )
{
struct V_257 * V_258 = * V_254 ;
int V_111 ;
V_111 = V_259 + V_258 -> V_111 ;
* V_254 += V_111 ;
* type = V_258 -> type ;
* V_255 = V_258 -> V_111 ;
switch ( V_258 -> V_111 ) {
case 1 :
* V_256 = * ( ( T_2 * ) V_258 -> V_256 ) ;
break;
case 2 :
* V_256 = F_136 ( V_258 -> V_256 ) ;
break;
case 4 :
* V_256 = F_165 ( V_258 -> V_256 ) ;
break;
default:
* V_256 = ( unsigned long ) V_258 -> V_256 ;
break;
}
F_25 ( L_21 , * type , V_258 -> V_111 , * V_256 ) ;
return V_111 ;
}
static void F_166 ( void * * V_254 , T_2 type , T_2 V_111 , unsigned long V_256 )
{
struct V_257 * V_258 = * V_254 ;
F_25 ( L_21 , type , V_111 , V_256 ) ;
V_258 -> type = type ;
V_258 -> V_111 = V_111 ;
switch ( V_111 ) {
case 1 :
* ( ( T_2 * ) V_258 -> V_256 ) = V_256 ;
break;
case 2 :
F_78 ( V_256 , V_258 -> V_256 ) ;
break;
case 4 :
F_167 ( V_256 , V_258 -> V_256 ) ;
break;
default:
memcpy ( V_258 -> V_256 , ( void * ) V_256 , V_111 ) ;
break;
}
* V_254 += V_259 + V_111 ;
}
static void F_168 ( unsigned long V_33 )
{
struct V_1 * V_16 = ( void * ) V_33 ;
F_11 ( V_16 -> V_10 ) ;
F_146 ( V_16 ) ;
F_35 ( V_16 -> V_10 ) ;
}
static inline void F_169 ( struct V_1 * V_16 )
{
struct V_34 * V_10 = V_16 -> V_10 ;
V_16 -> V_206 = 0 ;
V_16 -> V_199 = 0 ;
V_16 -> V_138 = 0 ;
V_16 -> V_260 = 0 ;
V_16 -> V_216 = 0 ;
F_40 ( & V_16 -> V_261 , F_130 ,
( unsigned long ) V_16 ) ;
F_40 ( & V_16 -> V_262 , F_128 ,
( unsigned long ) V_16 ) ;
F_40 ( & V_16 -> V_263 , F_168 , ( unsigned long ) V_16 ) ;
F_159 ( & V_16 -> V_79 ) ;
F_106 ( & V_16 -> V_221 ) ;
V_10 -> V_264 = V_265 ;
}
static inline T_6 F_170 ( T_6 V_74 , T_5 V_266 )
{
switch ( V_74 ) {
case V_159 :
case V_75 :
if ( F_84 ( V_74 , V_266 ) )
return V_74 ;
default:
return V_241 ;
}
}
static int F_86 ( struct V_1 * V_16 , void * V_32 )
{
struct V_267 * V_145 = V_32 ;
struct V_268 V_269 = { . V_74 = V_16 -> V_74 } ;
void * V_254 = V_145 -> V_32 ;
F_25 ( L_16 , V_16 ) ;
if ( V_16 -> V_170 || V_16 -> V_270 )
goto V_20;
switch ( V_16 -> V_74 ) {
case V_159 :
case V_75 :
if ( F_50 ( V_162 , & V_16 -> V_71 ) )
break;
default:
V_16 -> V_74 = F_170 ( V_269 . V_74 , V_16 -> V_5 -> V_153 ) ;
break;
}
V_20:
if ( V_16 -> V_271 != V_58 )
F_166 ( & V_254 , V_272 , 2 , V_16 -> V_271 ) ;
switch ( V_16 -> V_74 ) {
case V_241 :
if ( ! ( V_16 -> V_5 -> V_153 & V_157 ) &&
! ( V_16 -> V_5 -> V_153 & V_158 ) )
break;
V_269 . V_74 = V_241 ;
V_269 . V_273 = 0 ;
V_269 . V_274 = 0 ;
V_269 . V_275 = 0 ;
V_269 . V_276 = 0 ;
V_269 . V_277 = 0 ;
F_166 ( & V_254 , V_278 , sizeof( V_269 ) ,
( unsigned long ) & V_269 ) ;
break;
case V_75 :
V_269 . V_74 = V_75 ;
V_269 . V_273 = V_16 -> V_279 ;
V_269 . V_274 = V_16 -> V_280 ;
V_269 . V_275 = 0 ;
V_269 . V_276 = 0 ;
V_269 . V_277 = F_20 ( V_281 ) ;
if ( V_281 > V_16 -> V_5 -> V_188 - 10 )
V_269 . V_277 = F_20 ( V_16 -> V_5 -> V_188 - 10 ) ;
F_166 ( & V_254 , V_278 , sizeof( V_269 ) ,
( unsigned long ) & V_269 ) ;
if ( ! ( V_16 -> V_5 -> V_153 & V_282 ) )
break;
if ( V_16 -> V_126 == V_283 ||
F_50 ( V_284 , & V_16 -> V_71 ) ) {
V_16 -> V_126 = V_283 ;
F_166 ( & V_254 , V_285 , 1 , V_16 -> V_126 ) ;
}
break;
case V_159 :
V_269 . V_74 = V_159 ;
V_269 . V_273 = 0 ;
V_269 . V_274 = 0 ;
V_269 . V_275 = 0 ;
V_269 . V_276 = 0 ;
V_269 . V_277 = F_20 ( V_281 ) ;
if ( V_281 > V_16 -> V_5 -> V_188 - 10 )
V_269 . V_277 = F_20 ( V_16 -> V_5 -> V_188 - 10 ) ;
F_166 ( & V_254 , V_278 , sizeof( V_269 ) ,
( unsigned long ) & V_269 ) ;
if ( ! ( V_16 -> V_5 -> V_153 & V_282 ) )
break;
if ( V_16 -> V_126 == V_283 ||
F_50 ( V_284 , & V_16 -> V_71 ) ) {
V_16 -> V_126 = V_283 ;
F_166 ( & V_254 , V_285 , 1 , V_16 -> V_126 ) ;
}
break;
}
V_145 -> V_7 = F_20 ( V_16 -> V_7 ) ;
V_145 -> V_114 = F_20 ( 0 ) ;
return V_254 - V_32 ;
}
static int F_171 ( struct V_1 * V_16 , void * V_32 )
{
struct V_286 * V_87 = V_32 ;
void * V_254 = V_87 -> V_32 ;
void * V_145 = V_16 -> V_287 ;
int V_111 = V_16 -> V_288 ;
int type , V_289 , V_255 ;
unsigned long V_256 ;
struct V_268 V_269 = { . V_74 = V_241 } ;
T_1 V_188 = V_58 ;
T_1 V_88 = V_290 ;
F_25 ( L_16 , V_16 ) ;
while ( V_111 >= V_259 ) {
V_111 -= F_164 ( & V_145 , & type , & V_255 , & V_256 ) ;
V_289 = type & V_291 ;
type &= V_292 ;
switch ( type ) {
case V_272 :
V_188 = V_256 ;
break;
case V_293 :
V_16 -> V_294 = V_256 ;
break;
case V_295 :
break;
case V_278 :
if ( V_255 == sizeof( V_269 ) )
memcpy ( & V_269 , ( void * ) V_256 , V_255 ) ;
break;
case V_285 :
if ( V_256 == V_283 )
F_81 ( V_284 , & V_16 -> V_71 ) ;
break;
default:
if ( V_289 )
break;
V_88 = V_296 ;
* ( ( T_2 * ) V_254 ++ ) = type ;
break;
}
}
if ( V_16 -> V_270 || V_16 -> V_170 > 1 )
goto V_20;
switch ( V_16 -> V_74 ) {
case V_159 :
case V_75 :
if ( ! F_50 ( V_162 , & V_16 -> V_71 ) ) {
V_16 -> V_74 = F_170 ( V_269 . V_74 ,
V_16 -> V_5 -> V_153 ) ;
break;
}
if ( V_16 -> V_74 != V_269 . V_74 )
return - V_39 ;
break;
}
V_20:
if ( V_16 -> V_74 != V_269 . V_74 ) {
V_88 = V_297 ;
V_269 . V_74 = V_16 -> V_74 ;
if ( V_16 -> V_270 == 1 )
return - V_39 ;
F_166 ( & V_254 , V_278 ,
sizeof( V_269 ) , ( unsigned long ) & V_269 ) ;
}
if ( V_88 == V_290 ) {
if ( V_188 < V_298 )
V_88 = V_297 ;
else {
V_16 -> V_55 = V_188 ;
F_81 ( V_299 , & V_16 -> V_71 ) ;
}
F_166 ( & V_254 , V_272 , 2 , V_16 -> V_55 ) ;
switch ( V_269 . V_74 ) {
case V_241 :
V_16 -> V_126 = V_283 ;
F_81 ( V_300 , & V_16 -> V_71 ) ;
break;
case V_75 :
V_16 -> V_301 = V_269 . V_273 ;
V_16 -> V_202 = V_269 . V_274 ;
if ( F_172 ( V_269 . V_277 ) > V_16 -> V_5 -> V_188 - 10 )
V_269 . V_277 = F_20 ( V_16 -> V_5 -> V_188 - 10 ) ;
V_16 -> V_237 = F_172 ( V_269 . V_277 ) ;
V_269 . V_275 =
F_172 ( V_302 ) ;
V_269 . V_276 =
F_172 ( V_303 ) ;
F_81 ( V_300 , & V_16 -> V_71 ) ;
F_166 ( & V_254 , V_278 ,
sizeof( V_269 ) , ( unsigned long ) & V_269 ) ;
break;
case V_159 :
if ( F_172 ( V_269 . V_277 ) > V_16 -> V_5 -> V_188 - 10 )
V_269 . V_277 = F_20 ( V_16 -> V_5 -> V_188 - 10 ) ;
V_16 -> V_237 = F_172 ( V_269 . V_277 ) ;
F_81 ( V_300 , & V_16 -> V_71 ) ;
F_166 ( & V_254 , V_278 ,
sizeof( V_269 ) , ( unsigned long ) & V_269 ) ;
break;
default:
V_88 = V_297 ;
memset ( & V_269 , 0 , sizeof( V_269 ) ) ;
V_269 . V_74 = V_16 -> V_74 ;
}
if ( V_88 == V_290 )
F_81 ( V_70 , & V_16 -> V_71 ) ;
}
V_87 -> V_8 = F_20 ( V_16 -> V_7 ) ;
V_87 -> V_88 = F_20 ( V_88 ) ;
V_87 -> V_114 = F_20 ( 0x0000 ) ;
return V_254 - V_32 ;
}
static int F_173 ( struct V_1 * V_16 , void * V_87 , int V_111 , void * V_32 , T_1 * V_88 )
{
struct V_267 * V_145 = V_32 ;
void * V_254 = V_145 -> V_32 ;
int type , V_255 ;
unsigned long V_256 ;
struct V_268 V_269 = { . V_74 = V_241 } ;
F_25 ( L_22 , V_16 , V_87 , V_111 , V_32 ) ;
while ( V_111 >= V_259 ) {
V_111 -= F_164 ( & V_87 , & type , & V_255 , & V_256 ) ;
switch ( type ) {
case V_272 :
if ( V_256 < V_298 ) {
* V_88 = V_297 ;
V_16 -> V_271 = V_298 ;
} else
V_16 -> V_271 = V_256 ;
F_166 ( & V_254 , V_272 , 2 , V_16 -> V_271 ) ;
break;
case V_293 :
V_16 -> V_294 = V_256 ;
F_166 ( & V_254 , V_293 ,
2 , V_16 -> V_294 ) ;
break;
case V_278 :
if ( V_255 == sizeof( V_269 ) )
memcpy ( & V_269 , ( void * ) V_256 , V_255 ) ;
if ( F_50 ( V_162 , & V_16 -> V_71 ) &&
V_269 . V_74 != V_16 -> V_74 )
return - V_39 ;
V_16 -> V_126 = 0 ;
F_166 ( & V_254 , V_278 ,
sizeof( V_269 ) , ( unsigned long ) & V_269 ) ;
break;
}
}
if ( V_16 -> V_74 == V_241 && V_16 -> V_74 != V_269 . V_74 )
return - V_39 ;
V_16 -> V_74 = V_269 . V_74 ;
if ( * V_88 == V_290 ) {
switch ( V_269 . V_74 ) {
case V_75 :
V_16 -> V_275 = F_172 ( V_269 . V_275 ) ;
V_16 -> V_276 = F_172 ( V_269 . V_276 ) ;
V_16 -> V_304 = F_172 ( V_269 . V_277 ) ;
break;
case V_159 :
V_16 -> V_304 = F_172 ( V_269 . V_277 ) ;
}
}
V_145 -> V_7 = F_20 ( V_16 -> V_7 ) ;
V_145 -> V_114 = F_20 ( 0x0000 ) ;
return V_254 - V_32 ;
}
static int F_174 ( struct V_1 * V_16 , void * V_32 , T_1 V_88 , T_1 V_114 )
{
struct V_286 * V_87 = V_32 ;
void * V_254 = V_87 -> V_32 ;
F_25 ( L_16 , V_16 ) ;
V_87 -> V_8 = F_20 ( V_16 -> V_7 ) ;
V_87 -> V_88 = F_20 ( V_88 ) ;
V_87 -> V_114 = F_20 ( V_114 ) ;
return V_254 - V_32 ;
}
void F_175 ( struct V_1 * V_16 )
{
struct V_86 V_87 ;
struct V_4 * V_5 = V_16 -> V_5 ;
T_2 V_163 [ 128 ] ;
V_87 . V_8 = F_20 ( V_16 -> V_7 ) ;
V_87 . V_7 = F_20 ( V_16 -> V_8 ) ;
V_87 . V_88 = F_20 ( V_166 ) ;
V_87 . V_93 = F_20 ( V_94 ) ;
F_62 ( V_5 , V_16 -> V_11 ,
V_95 , sizeof( V_87 ) , & V_87 ) ;
if ( F_176 ( V_168 , & V_16 -> V_71 ) )
return;
F_62 ( V_5 , F_66 ( V_5 ) , V_169 ,
F_86 ( V_16 , V_163 ) , V_163 ) ;
V_16 -> V_170 ++ ;
}
static void F_177 ( struct V_1 * V_16 , void * V_87 , int V_111 )
{
int type , V_255 ;
unsigned long V_256 ;
struct V_268 V_269 ;
F_25 ( L_23 , V_16 , V_87 , V_111 ) ;
if ( ( V_16 -> V_74 != V_75 ) && ( V_16 -> V_74 != V_159 ) )
return;
while ( V_111 >= V_259 ) {
V_111 -= F_164 ( & V_87 , & type , & V_255 , & V_256 ) ;
switch ( type ) {
case V_278 :
if ( V_255 == sizeof( V_269 ) )
memcpy ( & V_269 , ( void * ) V_256 , V_255 ) ;
goto V_20;
}
}
V_269 . V_74 = V_16 -> V_74 ;
V_269 . V_275 = F_20 ( V_302 ) ;
V_269 . V_276 = F_20 ( V_303 ) ;
V_269 . V_277 = F_20 ( V_16 -> V_271 ) ;
F_178 ( L_24 ) ;
V_20:
switch ( V_269 . V_74 ) {
case V_75 :
V_16 -> V_275 = F_172 ( V_269 . V_275 ) ;
V_16 -> V_276 = F_172 ( V_269 . V_276 ) ;
V_16 -> V_304 = F_172 ( V_269 . V_277 ) ;
break;
case V_159 :
V_16 -> V_304 = F_172 ( V_269 . V_277 ) ;
}
}
static inline int F_179 ( struct V_4 * V_5 , struct V_249 * V_250 , T_2 * V_32 )
{
struct V_305 * V_306 = (struct V_305 * ) V_32 ;
if ( V_306 -> V_35 != V_307 )
return 0 ;
if ( ( V_5 -> V_141 & V_142 ) &&
V_250 -> V_11 == V_5 -> V_149 ) {
F_30 ( & V_5 -> V_150 ) ;
V_5 -> V_141 |= V_143 ;
V_5 -> V_149 = 0 ;
F_85 ( V_5 ) ;
}
return 0 ;
}
static inline int F_180 ( struct V_4 * V_5 , struct V_249 * V_250 , T_2 * V_32 )
{
struct V_144 * V_145 = (struct V_144 * ) V_32 ;
struct V_86 V_87 ;
struct V_1 * V_16 = NULL , * V_173 ;
struct V_34 * V_64 , * V_10 = NULL ;
int V_88 , V_93 = V_94 ;
T_1 V_7 = 0 , V_8 = F_181 ( V_145 -> V_8 ) ;
T_3 V_12 = V_145 -> V_12 ;
F_25 ( L_25 , V_12 , V_8 ) ;
V_173 = F_108 ( V_82 , V_12 , V_5 -> V_13 ) ;
if ( ! V_173 ) {
V_88 = V_91 ;
goto V_308;
}
V_64 = V_173 -> V_10 ;
F_11 ( V_64 ) ;
if ( V_12 != F_20 ( 0x0001 ) &&
! F_182 ( V_5 -> V_53 ) ) {
V_5 -> V_50 = 0x05 ;
V_88 = V_90 ;
goto V_309;
}
V_88 = V_310 ;
if ( F_89 ( V_64 ) ) {
F_25 ( L_11 , V_64 -> V_174 ) ;
goto V_309;
}
V_16 = V_173 -> V_30 -> V_176 ( V_173 -> V_32 ) ;
if ( ! V_16 )
goto V_309;
V_10 = V_16 -> V_10 ;
F_19 ( & V_5 -> V_9 ) ;
if ( F_6 ( V_5 , V_8 ) ) {
F_21 ( & V_5 -> V_9 ) ;
F_48 ( V_10 , V_66 ) ;
V_16 -> V_30 -> V_44 ( V_16 -> V_32 ) ;
goto V_309;
}
F_90 ( V_5 -> V_53 ) ;
F_91 ( & F_17 ( V_10 ) -> V_13 , V_5 -> V_13 ) ;
F_91 ( & F_17 ( V_10 ) -> V_177 , V_5 -> V_177 ) ;
V_16 -> V_12 = V_12 ;
V_16 -> V_7 = V_8 ;
F_92 ( V_64 , V_10 ) ;
F_44 ( V_5 , V_16 ) ;
V_7 = V_16 -> V_8 ;
F_34 ( V_16 , V_10 -> V_84 ) ;
V_16 -> V_11 = V_250 -> V_11 ;
if ( V_5 -> V_141 & V_143 ) {
if ( F_64 ( V_16 ) ) {
if ( F_17 ( V_10 ) -> V_89 ) {
F_31 ( V_16 , V_85 ) ;
V_88 = V_164 ;
V_93 = V_165 ;
V_64 -> V_68 ( V_64 , 0 ) ;
} else {
F_31 ( V_16 , V_38 ) ;
V_88 = V_166 ;
V_93 = V_94 ;
}
} else {
F_31 ( V_16 , V_85 ) ;
V_88 = V_164 ;
V_93 = V_167 ;
}
} else {
F_31 ( V_16 , V_85 ) ;
V_88 = V_164 ;
V_93 = V_94 ;
}
F_21 ( & V_5 -> V_9 ) ;
V_309:
F_35 ( V_64 ) ;
V_308:
V_87 . V_8 = F_20 ( V_8 ) ;
V_87 . V_7 = F_20 ( V_7 ) ;
V_87 . V_88 = F_20 ( V_88 ) ;
V_87 . V_93 = F_20 ( V_93 ) ;
F_62 ( V_5 , V_250 -> V_11 , V_95 , sizeof( V_87 ) , & V_87 ) ;
if ( V_88 == V_164 && V_93 == V_94 ) {
struct V_147 V_311 ;
V_311 . type = F_20 ( V_148 ) ;
V_5 -> V_141 |= V_142 ;
V_5 -> V_149 = F_66 ( V_5 ) ;
F_26 ( & V_5 -> V_150 , V_29 +
F_27 ( V_151 ) ) ;
F_62 ( V_5 , V_5 -> V_149 ,
V_152 , sizeof( V_311 ) , & V_311 ) ;
}
if ( V_16 && ! F_50 ( V_168 , & V_16 -> V_71 ) &&
V_88 == V_166 ) {
T_2 V_163 [ 128 ] ;
F_81 ( V_168 , & V_16 -> V_71 ) ;
F_62 ( V_5 , F_66 ( V_5 ) , V_169 ,
F_86 ( V_16 , V_163 ) , V_163 ) ;
V_16 -> V_170 ++ ;
}
return 0 ;
}
static inline int F_183 ( struct V_4 * V_5 , struct V_249 * V_250 , T_2 * V_32 )
{
struct V_86 * V_87 = (struct V_86 * ) V_32 ;
T_1 V_8 , V_7 , V_88 , V_93 ;
struct V_1 * V_16 ;
struct V_34 * V_10 ;
T_2 V_145 [ 128 ] ;
V_8 = F_181 ( V_87 -> V_8 ) ;
V_7 = F_181 ( V_87 -> V_7 ) ;
V_88 = F_181 ( V_87 -> V_88 ) ;
V_93 = F_181 ( V_87 -> V_93 ) ;
F_25 ( L_26 , V_7 , V_8 , V_88 , V_93 ) ;
if ( V_8 ) {
V_16 = F_9 ( V_5 , V_8 ) ;
if ( ! V_16 )
return - V_228 ;
} else {
V_16 = F_14 ( V_5 , V_250 -> V_11 ) ;
if ( ! V_16 )
return - V_228 ;
}
V_10 = V_16 -> V_10 ;
switch ( V_88 ) {
case V_166 :
F_31 ( V_16 , V_38 ) ;
V_16 -> V_11 = 0 ;
V_16 -> V_7 = V_7 ;
F_184 ( V_140 , & V_16 -> V_71 ) ;
if ( F_176 ( V_168 , & V_16 -> V_71 ) )
break;
F_62 ( V_5 , F_66 ( V_5 ) , V_169 ,
F_86 ( V_16 , V_145 ) , V_145 ) ;
V_16 -> V_170 ++ ;
break;
case V_164 :
F_81 ( V_140 , & V_16 -> V_71 ) ;
break;
default:
if ( F_33 ( V_10 ) ) {
F_31 ( V_16 , V_92 ) ;
F_46 ( V_16 ) ;
F_34 ( V_16 , V_36 ) ;
break;
}
F_45 ( V_16 , V_39 ) ;
break;
}
F_35 ( V_10 ) ;
return 0 ;
}
static inline void F_185 ( struct V_1 * V_16 )
{
if ( V_16 -> V_74 != V_75 && V_16 -> V_74 != V_159 )
V_16 -> V_126 = V_283 ;
else if ( ! F_50 ( V_284 , & V_16 -> V_71 ) )
V_16 -> V_126 = V_127 ;
}
static inline int F_186 ( struct V_4 * V_5 , struct V_249 * V_250 , T_1 V_312 , T_2 * V_32 )
{
struct V_267 * V_145 = (struct V_267 * ) V_32 ;
T_1 V_7 , V_114 ;
T_2 V_87 [ 64 ] ;
struct V_1 * V_16 ;
struct V_34 * V_10 ;
int V_111 ;
V_7 = F_181 ( V_145 -> V_7 ) ;
V_114 = F_181 ( V_145 -> V_114 ) ;
F_25 ( L_27 , V_7 , V_114 ) ;
V_16 = F_9 ( V_5 , V_7 ) ;
if ( ! V_16 )
return - V_313 ;
V_10 = V_16 -> V_10 ;
if ( V_16 -> V_28 != V_38 && V_16 -> V_28 != V_85 ) {
struct V_314 V_306 ;
V_306 . V_35 = F_20 ( V_315 ) ;
V_306 . V_8 = F_20 ( V_16 -> V_8 ) ;
V_306 . V_7 = F_20 ( V_16 -> V_7 ) ;
F_62 ( V_5 , V_250 -> V_11 , V_316 ,
sizeof( V_306 ) , & V_306 ) ;
goto V_317;
}
V_111 = V_312 - sizeof( * V_145 ) ;
if ( V_111 < 0 || V_16 -> V_288 + V_111 > sizeof( V_16 -> V_287 ) ) {
F_62 ( V_5 , V_250 -> V_11 , V_318 ,
F_174 ( V_16 , V_87 ,
V_319 , V_114 ) , V_87 ) ;
goto V_317;
}
memcpy ( V_16 -> V_287 + V_16 -> V_288 , V_145 -> V_32 , V_111 ) ;
V_16 -> V_288 += V_111 ;
if ( V_114 & 0x0001 ) {
F_62 ( V_5 , V_250 -> V_11 , V_318 ,
F_174 ( V_16 , V_87 ,
V_290 , 0x0001 ) , V_87 ) ;
goto V_317;
}
V_111 = F_171 ( V_16 , V_87 ) ;
if ( V_111 < 0 ) {
F_61 ( V_5 , V_16 , V_80 ) ;
goto V_317;
}
F_62 ( V_5 , V_250 -> V_11 , V_318 , V_111 , V_87 ) ;
V_16 -> V_270 ++ ;
V_16 -> V_288 = 0 ;
if ( ! F_50 ( V_70 , & V_16 -> V_71 ) )
goto V_317;
if ( F_50 ( V_72 , & V_16 -> V_71 ) ) {
F_185 ( V_16 ) ;
F_31 ( V_16 , V_37 ) ;
V_16 -> V_208 = 0 ;
V_16 -> V_320 = 0 ;
F_159 ( & V_16 -> V_73 ) ;
if ( V_16 -> V_74 == V_75 )
F_169 ( V_16 ) ;
F_93 ( V_10 ) ;
goto V_317;
}
if ( ! F_176 ( V_168 , & V_16 -> V_71 ) ) {
T_2 V_163 [ 64 ] ;
F_62 ( V_5 , F_66 ( V_5 ) , V_169 ,
F_86 ( V_16 , V_163 ) , V_163 ) ;
V_16 -> V_170 ++ ;
}
V_317:
F_35 ( V_10 ) ;
return 0 ;
}
static inline int F_187 ( struct V_4 * V_5 , struct V_249 * V_250 , T_2 * V_32 )
{
struct V_286 * V_87 = (struct V_286 * ) V_32 ;
T_1 V_8 , V_114 , V_88 ;
struct V_1 * V_16 ;
struct V_34 * V_10 ;
int V_111 = V_250 -> V_111 - sizeof( * V_87 ) ;
V_8 = F_181 ( V_87 -> V_8 ) ;
V_114 = F_181 ( V_87 -> V_114 ) ;
V_88 = F_181 ( V_87 -> V_88 ) ;
F_25 ( L_28 ,
V_8 , V_114 , V_88 ) ;
V_16 = F_9 ( V_5 , V_8 ) ;
if ( ! V_16 )
return 0 ;
V_10 = V_16 -> V_10 ;
switch ( V_88 ) {
case V_290 :
F_177 ( V_16 , V_87 -> V_32 , V_111 ) ;
break;
case V_297 :
if ( V_16 -> V_270 <= V_321 ) {
char V_145 [ 64 ] ;
if ( V_111 > sizeof( V_145 ) - sizeof( struct V_267 ) ) {
F_61 ( V_5 , V_16 , V_80 ) ;
goto V_20;
}
V_88 = V_290 ;
V_111 = F_173 ( V_16 , V_87 -> V_32 , V_111 ,
V_145 , & V_88 ) ;
if ( V_111 < 0 ) {
F_61 ( V_5 , V_16 , V_80 ) ;
goto V_20;
}
F_62 ( V_5 , F_66 ( V_5 ) ,
V_169 , V_111 , V_145 ) ;
V_16 -> V_170 ++ ;
if ( V_88 != V_290 )
goto V_20;
break;
}
default:
V_10 -> V_67 = V_80 ;
F_34 ( V_16 , V_322 ) ;
F_61 ( V_5 , V_16 , V_80 ) ;
goto V_20;
}
if ( V_114 & 0x01 )
goto V_20;
F_81 ( V_72 , & V_16 -> V_71 ) ;
if ( F_50 ( V_70 , & V_16 -> V_71 ) ) {
F_185 ( V_16 ) ;
F_31 ( V_16 , V_37 ) ;
V_16 -> V_208 = 0 ;
V_16 -> V_320 = 0 ;
F_159 ( & V_16 -> V_73 ) ;
if ( V_16 -> V_74 == V_75 )
F_169 ( V_16 ) ;
F_93 ( V_10 ) ;
}
V_20:
F_35 ( V_10 ) ;
return 0 ;
}
static inline int F_188 ( struct V_4 * V_5 , struct V_249 * V_250 , T_2 * V_32 )
{
struct V_160 * V_145 = (struct V_160 * ) V_32 ;
struct V_323 V_87 ;
T_1 V_7 , V_8 ;
struct V_1 * V_16 ;
struct V_34 * V_10 ;
V_8 = F_181 ( V_145 -> V_8 ) ;
V_7 = F_181 ( V_145 -> V_7 ) ;
F_25 ( L_29 , V_8 , V_7 ) ;
V_16 = F_9 ( V_5 , V_7 ) ;
if ( ! V_16 )
return 0 ;
V_10 = V_16 -> V_10 ;
V_87 . V_7 = F_20 ( V_16 -> V_8 ) ;
V_87 . V_8 = F_20 ( V_16 -> V_7 ) ;
F_62 ( V_5 , V_250 -> V_11 , V_324 , sizeof( V_87 ) , & V_87 ) ;
V_10 -> V_325 = V_326 ;
if ( F_33 ( V_10 ) ) {
F_31 ( V_16 , V_92 ) ;
F_46 ( V_16 ) ;
F_34 ( V_16 , V_36 ) ;
F_35 ( V_10 ) ;
return 0 ;
}
F_45 ( V_16 , V_80 ) ;
F_35 ( V_10 ) ;
V_16 -> V_30 -> V_44 ( V_16 -> V_32 ) ;
return 0 ;
}
static inline int F_189 ( struct V_4 * V_5 , struct V_249 * V_250 , T_2 * V_32 )
{
struct V_323 * V_87 = (struct V_323 * ) V_32 ;
T_1 V_7 , V_8 ;
struct V_1 * V_16 ;
struct V_34 * V_10 ;
V_8 = F_181 ( V_87 -> V_8 ) ;
V_7 = F_181 ( V_87 -> V_7 ) ;
F_25 ( L_30 , V_7 , V_8 ) ;
V_16 = F_9 ( V_5 , V_8 ) ;
if ( ! V_16 )
return 0 ;
V_10 = V_16 -> V_10 ;
if ( F_33 ( V_10 ) ) {
F_31 ( V_16 , V_92 ) ;
F_46 ( V_16 ) ;
F_34 ( V_16 , V_36 ) ;
F_35 ( V_10 ) ;
return 0 ;
}
F_45 ( V_16 , 0 ) ;
F_35 ( V_10 ) ;
V_16 -> V_30 -> V_44 ( V_16 -> V_32 ) ;
return 0 ;
}
static inline int F_190 ( struct V_4 * V_5 , struct V_249 * V_250 , T_2 * V_32 )
{
struct V_147 * V_145 = (struct V_147 * ) V_32 ;
T_1 type ;
type = F_181 ( V_145 -> type ) ;
F_25 ( L_31 , type ) ;
if ( type == V_148 ) {
T_2 V_163 [ 8 ] ;
T_8 V_153 = V_155 ;
struct V_327 * V_87 = (struct V_327 * ) V_163 ;
V_87 -> type = F_20 ( V_148 ) ;
V_87 -> V_88 = F_20 ( V_328 ) ;
if ( ! V_156 )
V_153 |= V_157 | V_158
| V_282 ;
F_167 ( V_153 , V_87 -> V_32 ) ;
F_62 ( V_5 , V_250 -> V_11 ,
V_329 , sizeof( V_163 ) , V_163 ) ;
} else if ( type == V_330 ) {
T_2 V_163 [ 12 ] ;
struct V_327 * V_87 = (struct V_327 * ) V_163 ;
V_87 -> type = F_20 ( V_330 ) ;
V_87 -> V_88 = F_20 ( V_328 ) ;
memcpy ( V_163 + 4 , V_331 , 8 ) ;
F_62 ( V_5 , V_250 -> V_11 ,
V_329 , sizeof( V_163 ) , V_163 ) ;
} else {
struct V_327 V_87 ;
V_87 . type = F_20 ( type ) ;
V_87 . V_88 = F_20 ( V_332 ) ;
F_62 ( V_5 , V_250 -> V_11 ,
V_329 , sizeof( V_87 ) , & V_87 ) ;
}
return 0 ;
}
static inline int F_191 ( struct V_4 * V_5 , struct V_249 * V_250 , T_2 * V_32 )
{
struct V_327 * V_87 = (struct V_327 * ) V_32 ;
T_1 type , V_88 ;
type = F_181 ( V_87 -> type ) ;
V_88 = F_181 ( V_87 -> V_88 ) ;
F_25 ( L_32 , type , V_88 ) ;
if ( V_250 -> V_11 != V_5 -> V_149 ||
V_5 -> V_141 & V_143 )
return 0 ;
F_30 ( & V_5 -> V_150 ) ;
if ( V_88 != V_328 ) {
V_5 -> V_141 |= V_143 ;
V_5 -> V_149 = 0 ;
F_85 ( V_5 ) ;
return 0 ;
}
if ( type == V_148 ) {
V_5 -> V_153 = F_165 ( V_87 -> V_32 ) ;
if ( V_5 -> V_153 & V_333 ) {
struct V_147 V_145 ;
V_145 . type = F_20 ( V_330 ) ;
V_5 -> V_149 = F_66 ( V_5 ) ;
F_62 ( V_5 , V_5 -> V_149 ,
V_152 , sizeof( V_145 ) , & V_145 ) ;
} else {
V_5 -> V_141 |= V_143 ;
V_5 -> V_149 = 0 ;
F_85 ( V_5 ) ;
}
} else if ( type == V_330 ) {
V_5 -> V_141 |= V_143 ;
V_5 -> V_149 = 0 ;
F_85 ( V_5 ) ;
}
return 0 ;
}
static inline int F_192 ( T_1 V_334 , T_1 V_335 , T_1 V_336 ,
T_1 V_337 )
{
T_1 V_338 ;
if ( V_334 > V_335 || V_334 < 6 || V_335 > 3200 )
return - V_22 ;
if ( V_337 < 10 || V_337 > 3200 )
return - V_22 ;
if ( V_335 >= V_337 * 8 )
return - V_22 ;
V_338 = ( V_337 * 8 / V_335 ) - 1 ;
if ( V_336 > 499 || V_336 > V_338 )
return - V_22 ;
return 0 ;
}
static inline int F_193 ( struct V_4 * V_5 ,
struct V_249 * V_250 , T_2 * V_32 )
{
struct V_181 * V_53 = V_5 -> V_53 ;
struct F_193 * V_145 ;
struct V_339 V_87 ;
T_1 V_334 , V_335 , V_336 , V_337 , V_312 ;
int V_17 ;
if ( ! ( V_53 -> V_340 & V_341 ) )
return - V_22 ;
V_312 = F_181 ( V_250 -> V_111 ) ;
if ( V_312 != sizeof( struct F_193 ) )
return - V_342 ;
V_145 = (struct F_193 * ) V_32 ;
V_334 = F_181 ( V_145 -> V_334 ) ;
V_335 = F_181 ( V_145 -> V_335 ) ;
V_336 = F_181 ( V_145 -> V_336 ) ;
V_337 = F_181 ( V_145 -> V_337 ) ;
F_25 ( L_33 ,
V_334 , V_335 , V_336 , V_337 ) ;
memset ( & V_87 , 0 , sizeof( V_87 ) ) ;
V_17 = F_192 ( V_334 , V_335 , V_336 , V_337 ) ;
if ( V_17 )
V_87 . V_88 = F_20 ( V_343 ) ;
else
V_87 . V_88 = F_20 ( V_344 ) ;
F_62 ( V_5 , V_250 -> V_11 , V_345 ,
sizeof( V_87 ) , & V_87 ) ;
if ( ! V_17 )
F_194 ( V_53 , V_334 , V_335 , V_336 , V_337 ) ;
return 0 ;
}
static inline int F_195 ( struct V_4 * V_5 ,
struct V_249 * V_250 , T_1 V_312 , T_2 * V_32 )
{
int V_17 = 0 ;
switch ( V_250 -> V_110 ) {
case V_316 :
F_179 ( V_5 , V_250 , V_32 ) ;
break;
case V_146 :
V_17 = F_180 ( V_5 , V_250 , V_32 ) ;
break;
case V_95 :
V_17 = F_183 ( V_5 , V_250 , V_32 ) ;
break;
case V_169 :
V_17 = F_186 ( V_5 , V_250 , V_312 , V_32 ) ;
break;
case V_318 :
V_17 = F_187 ( V_5 , V_250 , V_32 ) ;
break;
case V_161 :
V_17 = F_188 ( V_5 , V_250 , V_32 ) ;
break;
case V_324 :
V_17 = F_189 ( V_5 , V_250 , V_32 ) ;
break;
case V_346 :
F_62 ( V_5 , V_250 -> V_11 , V_347 , V_312 , V_32 ) ;
break;
case V_347 :
break;
case V_152 :
V_17 = F_190 ( V_5 , V_250 , V_32 ) ;
break;
case V_329 :
V_17 = F_191 ( V_5 , V_250 , V_32 ) ;
break;
default:
F_178 ( L_34 , V_250 -> V_110 ) ;
V_17 = - V_22 ;
break;
}
return V_17 ;
}
static inline int F_196 ( struct V_4 * V_5 ,
struct V_249 * V_250 , T_2 * V_32 )
{
switch ( V_250 -> V_110 ) {
case V_316 :
return 0 ;
case V_348 :
return F_193 ( V_5 , V_250 , V_32 ) ;
case V_345 :
return 0 ;
default:
F_178 ( L_35 , V_250 -> V_110 ) ;
return - V_22 ;
}
}
static inline void F_197 ( struct V_4 * V_5 ,
struct V_112 * V_113 )
{
T_2 * V_32 = V_113 -> V_32 ;
int V_111 = V_113 -> V_111 ;
struct V_249 V_250 ;
int V_17 ;
F_163 ( V_5 , V_113 ) ;
while ( V_111 >= V_251 ) {
T_1 V_312 ;
memcpy ( & V_250 , V_32 , V_251 ) ;
V_32 += V_251 ;
V_111 -= V_251 ;
V_312 = F_172 ( V_250 . V_111 ) ;
F_25 ( L_36 , V_250 . V_110 , V_312 , V_250 . V_11 ) ;
if ( V_312 > V_111 || ! V_250 . V_11 ) {
F_25 ( L_37 ) ;
break;
}
if ( V_5 -> V_53 -> type == V_54 )
V_17 = F_196 ( V_5 , & V_250 , V_32 ) ;
else
V_17 = F_195 ( V_5 , & V_250 , V_312 , V_32 ) ;
if ( V_17 ) {
struct V_305 V_306 ;
F_178 ( L_38 , V_17 ) ;
V_306 . V_35 = F_20 ( V_307 ) ;
F_62 ( V_5 , V_250 . V_11 , V_316 , sizeof( V_306 ) , & V_306 ) ;
}
V_32 += V_312 ;
V_111 -= V_312 ;
}
F_99 ( V_113 ) ;
}
static int F_198 ( struct V_1 * V_16 , struct V_112 * V_113 )
{
T_1 V_349 , V_350 ;
int V_351 = V_125 + 2 ;
if ( V_16 -> V_126 == V_127 ) {
F_199 ( V_113 , V_113 -> V_111 - 2 ) ;
V_350 = F_136 ( V_113 -> V_32 + V_113 -> V_111 ) ;
V_349 = F_79 ( 0 , V_113 -> V_32 - V_351 , V_113 -> V_111 + V_351 ) ;
if ( V_349 != V_350 )
return - V_352 ;
}
return 0 ;
}
static inline void F_200 ( struct V_1 * V_16 )
{
T_1 V_120 = 0 ;
V_16 -> V_216 = 0 ;
V_120 |= V_16 -> V_138 << V_139 ;
if ( F_50 ( V_134 , & V_16 -> V_130 ) ) {
V_120 |= V_135 ;
F_73 ( V_16 , V_120 ) ;
F_81 ( V_136 , & V_16 -> V_130 ) ;
}
if ( F_50 ( V_244 , & V_16 -> V_130 ) )
F_144 ( V_16 ) ;
F_141 ( V_16 ) ;
if ( ! F_50 ( V_134 , & V_16 -> V_130 ) &&
V_16 -> V_216 == 0 ) {
V_120 |= V_137 ;
F_73 ( V_16 , V_120 ) ;
}
}
static int F_201 ( struct V_1 * V_16 , struct V_112 * V_113 , T_2 V_205 , T_2 V_353 )
{
struct V_112 * V_354 ;
int V_355 , V_356 ;
F_71 ( V_113 ) -> V_205 = V_205 ;
F_71 ( V_113 ) -> V_353 = V_353 ;
V_354 = F_132 ( & V_16 -> V_79 ) ;
if ( ! V_354 ) {
F_160 ( & V_16 -> V_79 , V_113 ) ;
return 0 ;
}
V_355 = ( V_205 - V_16 -> V_138 ) % 64 ;
if ( V_355 < 0 )
V_355 += 64 ;
do {
if ( F_71 ( V_354 ) -> V_205 == V_205 )
return - V_22 ;
V_356 = ( F_71 ( V_354 ) -> V_205 -
V_16 -> V_138 ) % 64 ;
if ( V_356 < 0 )
V_356 += 64 ;
if ( V_356 > V_355 ) {
F_202 ( & V_16 -> V_79 , V_354 , V_113 ) ;
return 0 ;
}
if ( F_138 ( & V_16 -> V_79 , V_354 ) )
break;
} while ( ( V_354 = F_139 ( & V_16 -> V_79 , V_354 ) ) );
F_160 ( & V_16 -> V_79 , V_113 ) ;
return 0 ;
}
static void F_203 ( struct V_112 * V_113 ,
struct V_112 * V_357 , struct V_112 * * V_358 )
{
if ( ! F_204 ( V_113 ) )
F_151 ( V_113 ) -> V_229 = V_357 ;
V_357 -> V_218 = NULL ;
( * V_358 ) -> V_218 = V_357 ;
* V_358 = V_357 ;
V_113 -> V_111 += V_357 -> V_111 ;
V_113 -> V_359 += V_357 -> V_111 ;
V_113 -> V_360 += V_357 -> V_360 ;
}
static int F_205 ( struct V_1 * V_16 , struct V_112 * V_113 , T_1 V_120 )
{
int V_17 = - V_22 ;
switch ( V_120 & V_212 ) {
case V_243 :
if ( V_16 -> V_361 )
break;
V_17 = V_16 -> V_30 -> V_247 ( V_16 -> V_32 , V_113 ) ;
break;
case V_236 :
if ( V_16 -> V_361 )
break;
V_16 -> V_362 = F_136 ( V_113 -> V_32 ) ;
F_206 ( V_113 , 2 ) ;
if ( V_16 -> V_362 > V_16 -> V_271 ) {
V_17 = - V_242 ;
break;
}
if ( V_113 -> V_111 >= V_16 -> V_362 )
break;
V_16 -> V_361 = V_113 ;
V_16 -> V_363 = V_113 ;
V_113 = NULL ;
V_17 = 0 ;
break;
case V_239 :
if ( ! V_16 -> V_361 )
break;
F_203 ( V_16 -> V_361 , V_113 ,
& V_16 -> V_363 ) ;
V_113 = NULL ;
if ( V_16 -> V_361 -> V_111 >= V_16 -> V_362 )
break;
V_17 = 0 ;
break;
case V_240 :
if ( ! V_16 -> V_361 )
break;
F_203 ( V_16 -> V_361 , V_113 ,
& V_16 -> V_363 ) ;
V_113 = NULL ;
if ( V_16 -> V_361 -> V_111 != V_16 -> V_362 )
break;
V_17 = V_16 -> V_30 -> V_247 ( V_16 -> V_32 , V_16 -> V_361 ) ;
if ( ! V_17 ) {
V_16 -> V_361 = NULL ;
V_16 -> V_363 = NULL ;
V_16 -> V_362 = 0 ;
}
break;
}
if ( V_17 ) {
F_99 ( V_113 ) ;
F_99 ( V_16 -> V_361 ) ;
V_16 -> V_361 = NULL ;
V_16 -> V_363 = NULL ;
V_16 -> V_362 = 0 ;
}
return V_17 ;
}
static void F_207 ( struct V_1 * V_16 )
{
T_1 V_120 ;
F_25 ( L_39 , V_16 ) ;
F_81 ( V_134 , & V_16 -> V_130 ) ;
V_120 = V_16 -> V_138 << V_139 ;
V_120 |= V_135 ;
F_73 ( V_16 , V_120 ) ;
F_81 ( V_136 , & V_16 -> V_130 ) ;
F_54 ( V_16 ) ;
}
static void F_208 ( struct V_1 * V_16 )
{
T_1 V_120 ;
if ( ! F_50 ( V_136 , & V_16 -> V_130 ) )
goto V_20;
V_120 = V_16 -> V_138 << V_139 ;
V_120 |= V_137 | V_133 ;
F_73 ( V_16 , V_120 ) ;
V_16 -> V_201 = 1 ;
F_52 ( V_16 ) ;
F_129 ( V_16 ) ;
F_81 ( V_204 , & V_16 -> V_130 ) ;
V_20:
F_184 ( V_134 , & V_16 -> V_130 ) ;
F_184 ( V_136 , & V_16 -> V_130 ) ;
F_25 ( L_40 , V_16 ) ;
}
void F_209 ( struct V_1 * V_16 , int V_364 )
{
if ( V_16 -> V_74 == V_75 ) {
if ( V_364 )
F_207 ( V_16 ) ;
else
F_208 ( V_16 ) ;
}
}
static void F_210 ( struct V_1 * V_16 , T_2 V_205 )
{
struct V_112 * V_113 ;
T_1 V_120 ;
while ( ( V_113 = F_132 ( & V_16 -> V_79 ) ) &&
! F_50 ( V_134 , & V_16 -> V_130 ) ) {
int V_17 ;
if ( F_71 ( V_113 ) -> V_205 != V_205 )
break;
V_113 = F_133 ( & V_16 -> V_79 ) ;
V_120 = F_71 ( V_113 ) -> V_353 << V_365 ;
V_17 = F_205 ( V_16 , V_113 , V_120 ) ;
if ( V_17 < 0 ) {
F_61 ( V_16 -> V_5 , V_16 , V_80 ) ;
break;
}
V_16 -> V_366 =
( V_16 -> V_366 + 1 ) % 64 ;
V_205 = ( V_205 + 1 ) % 64 ;
}
}
static void F_211 ( struct V_1 * V_16 , T_2 V_205 )
{
struct V_76 * V_77 , * V_78 ;
T_1 V_120 ;
F_55 (l, tmp, &chan->srej_l, list) {
if ( V_77 -> V_205 == V_205 ) {
F_43 ( & V_77 -> V_62 ) ;
F_5 ( V_77 ) ;
return;
}
V_120 = V_220 ;
V_120 |= V_77 -> V_205 << V_139 ;
F_73 ( V_16 , V_120 ) ;
F_43 ( & V_77 -> V_62 ) ;
F_212 ( & V_77 -> V_62 , & V_16 -> V_221 ) ;
}
}
static void F_213 ( struct V_1 * V_16 , T_2 V_205 )
{
struct V_76 * V_367 ;
T_1 V_120 ;
while ( V_205 != V_16 -> V_320 ) {
V_120 = V_220 ;
V_120 |= V_16 -> V_320 << V_139 ;
F_73 ( V_16 , V_120 ) ;
V_367 = F_38 ( sizeof( struct V_76 ) , V_45 ) ;
V_367 -> V_205 = V_16 -> V_320 ;
V_16 -> V_320 = ( V_16 -> V_320 + 1 ) % 64 ;
F_212 ( & V_367 -> V_62 , & V_16 -> V_221 ) ;
}
V_16 -> V_320 = ( V_16 -> V_320 + 1 ) % 64 ;
}
static inline int F_214 ( struct V_1 * V_16 , T_1 V_368 , struct V_112 * V_113 )
{
T_2 V_205 = F_215 ( V_368 ) ;
T_2 V_369 = F_216 ( V_368 ) ;
T_2 V_353 = V_368 >> V_365 ;
int V_355 , V_370 ;
int V_371 = ( V_16 -> V_279 / 6 ) + 1 ;
int V_17 = 0 ;
F_25 ( L_41 , V_16 , V_113 -> V_111 ,
V_205 , V_368 ) ;
if ( V_131 & V_368 &&
F_50 ( V_204 , & V_16 -> V_130 ) ) {
F_53 ( V_16 ) ;
if ( V_16 -> V_199 > 0 )
F_143 ( V_16 ) ;
F_184 ( V_204 , & V_16 -> V_130 ) ;
}
V_16 -> V_206 = V_369 ;
F_131 ( V_16 ) ;
V_355 = ( V_205 - V_16 -> V_138 ) % 64 ;
if ( V_355 < 0 )
V_355 += 64 ;
if ( V_355 >= V_16 -> V_279 ) {
F_61 ( V_16 -> V_5 , V_16 , V_80 ) ;
goto V_372;
}
if ( F_50 ( V_134 , & V_16 -> V_130 ) )
goto V_372;
if ( V_205 == V_16 -> V_320 )
goto V_373;
if ( F_50 ( V_374 , & V_16 -> V_130 ) ) {
struct V_76 * V_375 ;
V_375 = F_217 ( & V_16 -> V_221 ,
struct V_76 , V_62 ) ;
if ( V_205 == V_375 -> V_205 ) {
F_201 ( V_16 , V_113 , V_205 , V_353 ) ;
F_210 ( V_16 , V_205 ) ;
F_43 ( & V_375 -> V_62 ) ;
F_5 ( V_375 ) ;
if ( F_218 ( & V_16 -> V_221 ) ) {
V_16 -> V_138 = V_16 -> V_366 ;
F_184 ( V_374 , & V_16 -> V_130 ) ;
F_146 ( V_16 ) ;
F_25 ( L_42 , V_16 ) ;
}
} else {
struct V_76 * V_77 ;
if ( F_201 ( V_16 , V_113 , V_205 , V_353 ) < 0 )
goto V_372;
F_7 (l, &chan->srej_l, list) {
if ( V_77 -> V_205 == V_205 ) {
F_211 ( V_16 , V_205 ) ;
return 0 ;
}
}
F_213 ( V_16 , V_205 ) ;
}
} else {
V_370 =
( V_16 -> V_320 - V_16 -> V_138 ) % 64 ;
if ( V_370 < 0 )
V_370 += 64 ;
if ( V_355 < V_370 )
goto V_372;
F_81 ( V_374 , & V_16 -> V_130 ) ;
F_25 ( L_43 , V_16 ) ;
F_106 ( & V_16 -> V_221 ) ;
V_16 -> V_366 = V_16 -> V_138 ;
F_219 ( & V_16 -> V_79 ) ;
F_201 ( V_16 , V_113 , V_205 , V_353 ) ;
F_81 ( V_132 , & V_16 -> V_130 ) ;
F_213 ( V_16 , V_205 ) ;
F_54 ( V_16 ) ;
}
return 0 ;
V_373:
V_16 -> V_320 = ( V_16 -> V_320 + 1 ) % 64 ;
if ( F_50 ( V_374 , & V_16 -> V_130 ) ) {
F_71 ( V_113 ) -> V_205 = V_205 ;
F_71 ( V_113 ) -> V_353 = V_353 ;
F_160 ( & V_16 -> V_79 , V_113 ) ;
return 0 ;
}
V_17 = F_205 ( V_16 , V_113 , V_368 ) ;
V_16 -> V_138 = ( V_16 -> V_138 + 1 ) % 64 ;
if ( V_17 < 0 ) {
F_61 ( V_16 -> V_5 , V_16 , V_80 ) ;
return V_17 ;
}
if ( V_368 & V_131 ) {
if ( ! F_75 ( V_376 , & V_16 -> V_130 ) )
F_144 ( V_16 ) ;
}
F_220 ( V_16 ) ;
V_16 -> V_260 = ( V_16 -> V_260 + 1 ) % V_371 ;
if ( V_16 -> V_260 == V_371 - 1 )
F_146 ( V_16 ) ;
return 0 ;
V_372:
F_99 ( V_113 ) ;
return 0 ;
}
static inline void F_221 ( struct V_1 * V_16 , T_1 V_368 )
{
F_25 ( L_44 , V_16 , F_216 ( V_368 ) ,
V_368 ) ;
V_16 -> V_206 = F_216 ( V_368 ) ;
F_131 ( V_16 ) ;
if ( V_368 & V_133 ) {
F_81 ( V_129 , & V_16 -> V_130 ) ;
if ( F_50 ( V_374 , & V_16 -> V_130 ) ) {
if ( F_50 ( V_244 , & V_16 -> V_130 ) &&
( V_16 -> V_199 > 0 ) )
F_143 ( V_16 ) ;
F_184 ( V_244 , & V_16 -> V_130 ) ;
F_147 ( V_16 ) ;
} else {
F_200 ( V_16 ) ;
}
} else if ( V_368 & V_131 ) {
F_184 ( V_244 , & V_16 -> V_130 ) ;
if ( ! F_75 ( V_376 , & V_16 -> V_130 ) )
F_144 ( V_16 ) ;
} else {
if ( F_50 ( V_244 , & V_16 -> V_130 ) &&
( V_16 -> V_199 > 0 ) )
F_143 ( V_16 ) ;
F_184 ( V_244 , & V_16 -> V_130 ) ;
if ( F_50 ( V_374 , & V_16 -> V_130 ) )
F_146 ( V_16 ) ;
else
F_141 ( V_16 ) ;
}
}
static inline void F_222 ( struct V_1 * V_16 , T_1 V_368 )
{
T_2 V_205 = F_216 ( V_368 ) ;
F_25 ( L_44 , V_16 , V_205 , V_368 ) ;
F_184 ( V_244 , & V_16 -> V_130 ) ;
V_16 -> V_206 = V_205 ;
F_131 ( V_16 ) ;
if ( V_368 & V_131 ) {
if ( ! F_75 ( V_376 , & V_16 -> V_130 ) )
F_144 ( V_16 ) ;
} else {
F_144 ( V_16 ) ;
if ( F_50 ( V_204 , & V_16 -> V_130 ) )
F_81 ( V_376 , & V_16 -> V_130 ) ;
}
}
static inline void F_223 ( struct V_1 * V_16 , T_1 V_368 )
{
T_2 V_205 = F_216 ( V_368 ) ;
F_25 ( L_44 , V_16 , V_205 , V_368 ) ;
F_184 ( V_244 , & V_16 -> V_130 ) ;
if ( V_368 & V_133 ) {
V_16 -> V_206 = V_205 ;
F_131 ( V_16 ) ;
F_81 ( V_129 , & V_16 -> V_130 ) ;
F_137 ( V_16 , V_205 ) ;
F_141 ( V_16 ) ;
if ( F_50 ( V_204 , & V_16 -> V_130 ) ) {
V_16 -> V_377 = V_205 ;
F_81 ( V_378 , & V_16 -> V_130 ) ;
}
} else if ( V_368 & V_131 ) {
if ( F_50 ( V_378 , & V_16 -> V_130 ) &&
V_16 -> V_377 == V_205 )
F_184 ( V_378 , & V_16 -> V_130 ) ;
else
F_137 ( V_16 , V_205 ) ;
} else {
F_137 ( V_16 , V_205 ) ;
if ( F_50 ( V_204 , & V_16 -> V_130 ) ) {
V_16 -> V_377 = V_205 ;
F_81 ( V_378 , & V_16 -> V_130 ) ;
}
}
}
static inline void F_224 ( struct V_1 * V_16 , T_1 V_368 )
{
T_2 V_205 = F_216 ( V_368 ) ;
F_25 ( L_44 , V_16 , V_205 , V_368 ) ;
F_81 ( V_244 , & V_16 -> V_130 ) ;
V_16 -> V_206 = V_205 ;
F_131 ( V_16 ) ;
if ( V_368 & V_133 )
F_81 ( V_129 , & V_16 -> V_130 ) ;
if ( ! F_50 ( V_374 , & V_16 -> V_130 ) ) {
F_52 ( V_16 ) ;
if ( V_368 & V_133 )
F_80 ( V_16 , V_131 ) ;
return;
}
if ( V_368 & V_133 )
F_147 ( V_16 ) ;
else
F_73 ( V_16 , V_137 ) ;
}
static inline int F_225 ( struct V_1 * V_16 , T_1 V_368 , struct V_112 * V_113 )
{
F_25 ( L_45 , V_16 , V_368 , V_113 -> V_111 ) ;
if ( V_131 & V_368 &&
F_50 ( V_204 , & V_16 -> V_130 ) ) {
F_53 ( V_16 ) ;
if ( V_16 -> V_199 > 0 )
F_143 ( V_16 ) ;
F_184 ( V_204 , & V_16 -> V_130 ) ;
}
switch ( V_368 & V_379 ) {
case V_137 :
F_221 ( V_16 , V_368 ) ;
break;
case V_380 :
F_222 ( V_16 , V_368 ) ;
break;
case V_220 :
F_223 ( V_16 , V_368 ) ;
break;
case V_135 :
F_224 ( V_16 , V_368 ) ;
break;
}
F_99 ( V_113 ) ;
return 0 ;
}
static int V_265 ( struct V_34 * V_10 , struct V_112 * V_113 )
{
struct V_1 * V_16 = F_58 ( V_10 ) -> V_16 ;
T_1 V_120 ;
T_2 V_369 ;
int V_111 , V_356 , V_381 ;
V_120 = F_136 ( V_113 -> V_32 ) ;
F_206 ( V_113 , 2 ) ;
V_111 = V_113 -> V_111 ;
if ( F_198 ( V_16 , V_113 ) )
goto V_372;
if ( F_226 ( V_120 ) && F_227 ( V_120 ) )
V_111 -= 2 ;
if ( V_16 -> V_126 == V_127 )
V_111 -= 2 ;
if ( V_111 > V_16 -> V_304 ) {
F_61 ( V_16 -> V_5 , V_16 , V_80 ) ;
goto V_372;
}
V_369 = F_216 ( V_120 ) ;
V_381 = ( V_369 - V_16 -> V_206 ) % 64 ;
if ( V_381 < 0 )
V_381 += 64 ;
V_356 =
( V_16 -> V_208 - V_16 -> V_206 ) % 64 ;
if ( V_356 < 0 )
V_356 += 64 ;
if ( V_381 > V_356 ) {
F_61 ( V_16 -> V_5 , V_16 , V_80 ) ;
goto V_372;
}
if ( F_227 ( V_120 ) ) {
if ( V_111 < 0 ) {
F_61 ( V_16 -> V_5 , V_16 , V_80 ) ;
goto V_372;
}
F_214 ( V_16 , V_120 , V_113 ) ;
} else {
if ( V_111 != 0 ) {
F_178 ( L_46 , V_111 ) ;
F_61 ( V_16 -> V_5 , V_16 , V_80 ) ;
goto V_372;
}
F_225 ( V_16 , V_120 , V_113 ) ;
}
return 0 ;
V_372:
F_99 ( V_113 ) ;
return 0 ;
}
static inline int F_228 ( struct V_4 * V_5 , T_1 V_6 , struct V_112 * V_113 )
{
struct V_1 * V_16 ;
struct V_34 * V_10 = NULL ;
T_1 V_120 ;
T_2 V_205 ;
int V_111 ;
V_16 = F_9 ( V_5 , V_6 ) ;
if ( ! V_16 ) {
F_25 ( L_47 , V_6 ) ;
goto V_372;
}
V_10 = V_16 -> V_10 ;
F_25 ( L_48 , V_16 , V_113 -> V_111 ) ;
if ( V_16 -> V_28 != V_37 )
goto V_372;
switch ( V_16 -> V_74 ) {
case V_241 :
if ( V_16 -> V_271 < V_113 -> V_111 )
goto V_372;
if ( ! V_16 -> V_30 -> V_247 ( V_16 -> V_32 , V_113 ) )
goto V_20;
break;
case V_75 :
if ( ! F_33 ( V_10 ) ) {
V_265 ( V_10 , V_113 ) ;
} else {
if ( F_229 ( V_10 , V_113 ) )
goto V_372;
}
goto V_20;
case V_159 :
V_120 = F_136 ( V_113 -> V_32 ) ;
F_206 ( V_113 , 2 ) ;
V_111 = V_113 -> V_111 ;
if ( F_198 ( V_16 , V_113 ) )
goto V_372;
if ( F_226 ( V_120 ) )
V_111 -= 2 ;
if ( V_16 -> V_126 == V_127 )
V_111 -= 2 ;
if ( V_111 > V_16 -> V_304 || V_111 < 0 || F_230 ( V_120 ) )
goto V_372;
V_205 = F_215 ( V_120 ) ;
if ( V_16 -> V_320 != V_205 ) {
F_99 ( V_16 -> V_361 ) ;
V_16 -> V_361 = NULL ;
V_16 -> V_363 = NULL ;
V_16 -> V_362 = 0 ;
}
V_16 -> V_320 = ( V_205 + 1 ) % 64 ;
if ( F_205 ( V_16 , V_113 , V_120 ) == - V_242 )
F_61 ( V_16 -> V_5 , V_16 , V_80 ) ;
goto V_20;
default:
F_25 ( L_49 , V_16 , V_16 -> V_74 ) ;
break;
}
V_372:
F_99 ( V_113 ) ;
V_20:
if ( V_10 )
F_35 ( V_10 ) ;
return 0 ;
}
static inline int F_231 ( struct V_4 * V_5 , T_3 V_12 , struct V_112 * V_113 )
{
struct V_34 * V_10 = NULL ;
struct V_1 * V_16 ;
V_16 = F_108 ( 0 , V_12 , V_5 -> V_13 ) ;
if ( ! V_16 )
goto V_372;
V_10 = V_16 -> V_10 ;
F_11 ( V_10 ) ;
F_25 ( L_50 , V_10 , V_113 -> V_111 ) ;
if ( V_16 -> V_28 != V_382 && V_16 -> V_28 != V_37 )
goto V_372;
if ( V_16 -> V_271 < V_113 -> V_111 )
goto V_372;
if ( ! V_16 -> V_30 -> V_247 ( V_16 -> V_32 , V_113 ) )
goto V_20;
V_372:
F_99 ( V_113 ) ;
V_20:
if ( V_10 )
F_35 ( V_10 ) ;
return 0 ;
}
static inline int F_232 ( struct V_4 * V_5 , T_3 V_6 , struct V_112 * V_113 )
{
struct V_34 * V_10 = NULL ;
struct V_1 * V_16 ;
V_16 = F_87 ( 0 , V_6 , V_5 -> V_13 ) ;
if ( ! V_16 )
goto V_372;
V_10 = V_16 -> V_10 ;
F_11 ( V_10 ) ;
F_25 ( L_50 , V_10 , V_113 -> V_111 ) ;
if ( V_16 -> V_28 != V_382 && V_16 -> V_28 != V_37 )
goto V_372;
if ( V_16 -> V_271 < V_113 -> V_111 )
goto V_372;
if ( ! V_16 -> V_30 -> V_247 ( V_16 -> V_32 , V_113 ) )
goto V_20;
V_372:
F_99 ( V_113 ) ;
V_20:
if ( V_10 )
F_35 ( V_10 ) ;
return 0 ;
}
static void F_233 ( struct V_4 * V_5 , struct V_112 * V_113 )
{
struct V_121 * V_122 = ( void * ) V_113 -> V_32 ;
T_1 V_6 , V_111 ;
T_3 V_12 ;
F_206 ( V_113 , V_125 ) ;
V_6 = F_181 ( V_122 -> V_6 ) ;
V_111 = F_181 ( V_122 -> V_111 ) ;
if ( V_111 != V_113 -> V_111 ) {
F_99 ( V_113 ) ;
return;
}
F_25 ( L_51 , V_111 , V_6 ) ;
switch ( V_6 ) {
case V_252 :
case V_61 :
F_197 ( V_5 , V_113 ) ;
break;
case V_60 :
V_12 = F_136 ( V_113 -> V_32 ) ;
F_206 ( V_113 , 2 ) ;
F_231 ( V_5 , V_12 , V_113 ) ;
break;
case V_57 :
F_232 ( V_5 , V_6 , V_113 ) ;
break;
case V_383 :
if ( F_234 ( V_5 , V_113 ) )
F_98 ( V_5 -> V_53 , V_384 ) ;
break;
default:
F_228 ( V_5 , V_6 , V_113 ) ;
break;
}
}
static int F_235 ( struct V_191 * V_115 , T_4 * V_190 , T_2 type )
{
int V_385 = 0 , V_386 = 0 , V_387 = 0 ;
struct V_1 * V_2 ;
if ( type != V_83 )
return - V_22 ;
F_25 ( L_52 , V_115 -> V_388 , F_110 ( V_190 ) ) ;
F_10 ( & V_18 ) ;
F_7 (c, &chan_list, global_l) {
struct V_34 * V_10 = V_2 -> V_10 ;
if ( V_2 -> V_28 != V_82 )
continue;
if ( ! F_16 ( & F_17 ( V_10 ) -> V_13 , & V_115 -> V_190 ) ) {
V_386 |= V_389 ;
if ( V_2 -> V_390 )
V_386 |= V_341 ;
V_385 ++ ;
} else if ( ! F_16 ( & F_17 ( V_10 ) -> V_13 , V_172 ) ) {
V_387 |= V_389 ;
if ( V_2 -> V_390 )
V_387 |= V_341 ;
}
}
F_12 ( & V_18 ) ;
return V_385 ? V_386 : V_387 ;
}
static int F_236 ( struct V_181 * V_53 , T_2 V_93 )
{
struct V_4 * V_5 ;
F_25 ( L_53 , V_53 , F_110 ( & V_53 -> V_177 ) , V_93 ) ;
if ( ! ( V_53 -> type == V_83 || V_53 -> type == V_54 ) )
return - V_22 ;
if ( ! V_93 ) {
V_5 = F_103 ( V_53 , V_93 ) ;
if ( V_5 )
F_94 ( V_5 ) ;
} else
F_98 ( V_53 , F_237 ( V_93 ) ) ;
return 0 ;
}
static int F_238 ( struct V_181 * V_53 )
{
struct V_4 * V_5 = V_53 -> V_182 ;
F_25 ( L_54 , V_53 ) ;
if ( ( V_53 -> type != V_83 && V_53 -> type != V_54 ) || ! V_5 )
return 0x13 ;
return V_5 -> V_50 ;
}
static int F_239 ( struct V_181 * V_53 , T_2 V_35 )
{
F_25 ( L_55 , V_53 , V_35 ) ;
if ( ! ( V_53 -> type == V_83 || V_53 -> type == V_54 ) )
return - V_22 ;
F_98 ( V_53 , F_237 ( V_35 ) ) ;
return 0 ;
}
static inline void F_240 ( struct V_1 * V_16 , T_2 V_391 )
{
if ( V_16 -> V_51 != V_52 )
return;
if ( V_391 == 0x00 ) {
if ( V_16 -> V_41 == V_99 ) {
F_46 ( V_16 ) ;
F_34 ( V_16 , V_392 ) ;
} else if ( V_16 -> V_41 == V_97 )
F_36 ( V_16 , V_39 ) ;
} else {
if ( V_16 -> V_41 == V_99 )
F_46 ( V_16 ) ;
}
}
static int F_241 ( struct V_181 * V_53 , T_2 V_93 , T_2 V_391 )
{
struct V_4 * V_5 = V_53 -> V_182 ;
struct V_1 * V_16 ;
if ( ! V_5 )
return 0 ;
F_25 ( L_9 , V_5 ) ;
if ( V_53 -> type == V_54 ) {
F_242 ( V_5 , 0 ) ;
F_30 ( & V_5 -> V_186 ) ;
}
F_10 ( & V_5 -> V_9 ) ;
F_7 (chan, &conn->chan_l, list) {
struct V_34 * V_10 = V_16 -> V_10 ;
F_11 ( V_10 ) ;
F_25 ( L_56 , V_16 -> V_8 ) ;
if ( V_16 -> V_8 == V_57 ) {
if ( ! V_93 && V_391 ) {
V_16 -> V_41 = V_53 -> V_41 ;
F_93 ( V_10 ) ;
}
F_35 ( V_10 ) ;
continue;
}
if ( F_50 ( V_140 , & V_16 -> V_71 ) ) {
F_35 ( V_10 ) ;
continue;
}
if ( ! V_93 && ( V_16 -> V_28 == V_37 ||
V_16 -> V_28 == V_38 ) ) {
F_240 ( V_16 , V_391 ) ;
F_35 ( V_10 ) ;
continue;
}
if ( V_16 -> V_28 == V_40 ) {
if ( ! V_93 ) {
struct V_144 V_145 ;
V_145 . V_8 = F_20 ( V_16 -> V_8 ) ;
V_145 . V_12 = V_16 -> V_12 ;
V_16 -> V_11 = F_66 ( V_5 ) ;
F_81 ( V_140 , & V_16 -> V_71 ) ;
F_62 ( V_5 , V_16 -> V_11 ,
V_146 , sizeof( V_145 ) , & V_145 ) ;
} else {
F_46 ( V_16 ) ;
F_34 ( V_16 , V_36 ) ;
}
} else if ( V_16 -> V_28 == V_85 ) {
struct V_86 V_87 ;
T_5 V_393 , V_394 ;
if ( ! V_93 ) {
if ( F_17 ( V_10 ) -> V_89 ) {
struct V_34 * V_64 = F_17 ( V_10 ) -> V_64 ;
V_393 = V_164 ;
V_394 = V_165 ;
if ( V_64 )
V_64 -> V_68 ( V_64 , 0 ) ;
} else {
F_31 ( V_16 , V_38 ) ;
V_393 = V_166 ;
V_394 = V_94 ;
}
} else {
F_31 ( V_16 , V_92 ) ;
F_34 ( V_16 , V_36 ) ;
V_393 = V_90 ;
V_394 = V_94 ;
}
V_87 . V_8 = F_20 ( V_16 -> V_7 ) ;
V_87 . V_7 = F_20 ( V_16 -> V_8 ) ;
V_87 . V_88 = F_20 ( V_393 ) ;
V_87 . V_93 = F_20 ( V_394 ) ;
F_62 ( V_5 , V_16 -> V_11 , V_95 ,
sizeof( V_87 ) , & V_87 ) ;
}
F_35 ( V_10 ) ;
}
F_12 ( & V_5 -> V_9 ) ;
return 0 ;
}
static int F_243 ( struct V_181 * V_53 , struct V_112 * V_113 , T_1 V_114 )
{
struct V_4 * V_5 = V_53 -> V_182 ;
if ( ! V_5 )
V_5 = F_103 ( V_53 , 0 ) ;
if ( ! V_5 )
goto V_372;
F_25 ( L_57 , V_5 , V_113 -> V_111 , V_114 ) ;
if ( ! ( V_114 & V_395 ) ) {
struct V_121 * V_396 ;
struct V_1 * V_16 ;
T_1 V_6 ;
int V_111 ;
if ( V_5 -> V_397 ) {
F_178 ( L_58 , V_113 -> V_111 ) ;
F_99 ( V_5 -> V_183 ) ;
V_5 -> V_183 = NULL ;
V_5 -> V_397 = 0 ;
F_96 ( V_5 , V_398 ) ;
}
if ( V_113 -> V_111 < V_125 ) {
F_178 ( L_59 , V_113 -> V_111 ) ;
F_96 ( V_5 , V_398 ) ;
goto V_372;
}
V_396 = (struct V_121 * ) V_113 -> V_32 ;
V_111 = F_181 ( V_396 -> V_111 ) + V_125 ;
V_6 = F_181 ( V_396 -> V_6 ) ;
if ( V_111 == V_113 -> V_111 ) {
F_233 ( V_5 , V_113 ) ;
return 0 ;
}
F_25 ( L_60 , V_111 , V_113 -> V_111 ) ;
if ( V_113 -> V_111 > V_111 ) {
F_178 ( L_61 ,
V_113 -> V_111 , V_111 ) ;
F_96 ( V_5 , V_398 ) ;
goto V_372;
}
V_16 = F_9 ( V_5 , V_6 ) ;
if ( V_16 && V_16 -> V_10 ) {
struct V_34 * V_10 = V_16 -> V_10 ;
if ( V_16 -> V_271 < V_111 - V_125 ) {
F_178 ( L_62
L_63 , V_111 ,
V_16 -> V_271 ) ;
F_35 ( V_10 ) ;
F_96 ( V_5 , V_398 ) ;
goto V_372;
}
F_35 ( V_10 ) ;
}
V_5 -> V_183 = F_76 ( V_111 , V_45 ) ;
if ( ! V_5 -> V_183 )
goto V_372;
F_244 ( V_113 , F_77 ( V_5 -> V_183 , V_113 -> V_111 ) ,
V_113 -> V_111 ) ;
V_5 -> V_397 = V_111 - V_113 -> V_111 ;
} else {
F_25 ( L_64 , V_113 -> V_111 , V_5 -> V_397 ) ;
if ( ! V_5 -> V_397 ) {
F_178 ( L_65 , V_113 -> V_111 ) ;
F_96 ( V_5 , V_398 ) ;
goto V_372;
}
if ( V_113 -> V_111 > V_5 -> V_397 ) {
F_178 ( L_66 ,
V_113 -> V_111 , V_5 -> V_397 ) ;
F_99 ( V_5 -> V_183 ) ;
V_5 -> V_183 = NULL ;
V_5 -> V_397 = 0 ;
F_96 ( V_5 , V_398 ) ;
goto V_372;
}
F_244 ( V_113 , F_77 ( V_5 -> V_183 , V_113 -> V_111 ) ,
V_113 -> V_111 ) ;
V_5 -> V_397 -= V_113 -> V_111 ;
if ( ! V_5 -> V_397 ) {
F_233 ( V_5 , V_5 -> V_183 ) ;
V_5 -> V_183 = NULL ;
}
}
V_372:
F_99 ( V_113 ) ;
return 0 ;
}
static int F_245 ( struct V_399 * V_400 , void * V_21 )
{
struct V_1 * V_2 ;
F_246 ( & V_18 ) ;
F_7 (c, &chan_list, global_l) {
struct V_34 * V_10 = V_2 -> V_10 ;
F_247 ( V_400 , L_67 ,
F_110 ( & F_17 ( V_10 ) -> V_13 ) ,
F_110 ( & F_17 ( V_10 ) -> V_177 ) ,
V_2 -> V_28 , F_181 ( V_2 -> V_12 ) ,
V_2 -> V_8 , V_2 -> V_7 , V_2 -> V_271 , V_2 -> V_55 ,
V_2 -> V_41 , V_2 -> V_74 ) ;
}
F_248 ( & V_18 ) ;
return 0 ;
}
static int F_249 ( struct V_401 * V_401 , struct V_402 * V_402 )
{
return F_250 ( V_402 , F_245 , V_401 -> V_403 ) ;
}
int T_10 F_251 ( void )
{
int V_17 ;
V_17 = F_252 () ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_253 ( & V_404 ) ;
if ( V_17 < 0 ) {
F_178 ( L_68 ) ;
F_254 ( V_405 ) ;
goto error;
}
if ( V_406 ) {
V_407 = F_255 ( L_69 , 0444 ,
V_406 , NULL , & V_408 ) ;
if ( ! V_407 )
F_178 ( L_70 ) ;
}
return 0 ;
error:
F_256 () ;
return V_17 ;
}
void F_257 ( void )
{
F_258 ( V_407 ) ;
if ( F_259 ( & V_404 ) < 0 )
F_178 ( L_71 ) ;
F_256 () ;
}
