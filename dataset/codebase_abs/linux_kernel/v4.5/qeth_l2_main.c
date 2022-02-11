static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 ;
int V_11 = 0 ;
if ( ! V_7 )
return - V_12 ;
if ( ! F_2 ( V_7 ) )
return - V_12 ;
if ( V_7 -> V_13 . type == V_14 )
return - V_15 ;
switch ( V_5 ) {
case V_16 :
V_11 = F_3 ( V_7 , V_4 -> V_17 . V_18 ) ;
break;
case V_19 :
if ( ( V_7 -> V_13 . type == V_20 ||
V_7 -> V_13 . type == V_21 ||
V_7 -> V_13 . type == V_22 ) &&
! V_7 -> V_13 . V_23 )
return 1 ;
return 0 ;
break;
case V_24 :
V_10 = F_4 ( V_4 ) ;
V_10 -> V_25 = 0 ;
break;
case V_26 :
V_10 = F_4 ( V_4 ) ;
if ( V_10 -> V_25 != 0 )
V_11 = - V_27 ;
else
V_10 -> V_28 = F_5 ( V_2 ,
V_10 -> V_25 , V_10 -> V_29 ) ;
break;
case V_30 :
V_11 = F_6 ( V_7 , V_4 -> V_17 . V_18 ) ;
break;
default:
V_11 = - V_31 ;
}
if ( V_11 )
F_7 ( V_7 , 2 , L_1 , V_11 ) ;
return V_11 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
unsigned long V_32 ;
int V_11 = 0 ;
F_9 ( & V_33 . V_34 , V_32 ) ;
F_10 (card, &qeth_core_card_list.list, list) {
if ( V_7 -> V_2 == V_2 ) {
V_11 = V_35 ;
break;
}
}
F_11 ( & V_33 . V_34 , V_32 ) ;
return V_11 ;
}
static struct V_1 * F_12 ( unsigned char * V_36 )
{
struct V_6 * V_7 ;
struct V_1 * V_37 ;
T_1 V_38 ;
unsigned long V_32 ;
struct V_39 V_40 ;
V_37 = NULL ;
memcpy ( & V_38 , V_36 , 2 ) ;
F_9 ( & V_33 . V_34 , V_32 ) ;
F_10 (card, &qeth_core_card_list.list, list) {
F_13 ( F_14 ( V_7 ) , & V_40 ) ;
if ( V_40 . V_41 == V_38 ) {
V_37 = V_7 -> V_2 ;
break;
}
}
F_11 ( & V_33 . V_34 , V_32 ) ;
return V_37 ;
}
static int F_15 ( struct V_6 * V_7 , int V_42 )
{
int V_11 ;
if ( V_42 )
F_7 ( V_7 , 2 , L_2 , V_42 ) ;
switch ( V_42 ) {
case V_43 :
V_11 = 0 ;
break;
case V_44 :
V_11 = - V_31 ;
break;
case V_45 :
V_11 = - V_46 ;
break;
case V_47 :
case V_48 :
V_11 = - V_49 ;
break;
case V_50 :
case V_51 :
V_11 = - V_15 ;
break;
case V_52 :
V_11 = - V_53 ;
break;
case - V_54 :
V_11 = - V_54 ;
break;
default:
V_11 = - V_55 ;
break;
}
return V_11 ;
}
static int F_16 ( struct V_6 * V_7 , T_2 * V_56 )
{
int V_11 ;
F_17 ( V_7 , 2 , L_3 ) ;
V_11 = F_15 ( V_7 , F_18 ( V_7 , V_56 ,
V_57 ) ) ;
if ( V_11 == - V_49 )
F_19 ( 2 , L_4 ,
V_56 , F_20 ( V_7 ) ) ;
else if ( V_11 )
F_19 ( 2 , L_5 ,
V_56 , F_20 ( V_7 ) , V_11 ) ;
return V_11 ;
}
static int F_21 ( struct V_6 * V_7 , T_2 * V_56 )
{
int V_11 ;
F_17 ( V_7 , 2 , L_6 ) ;
V_11 = F_15 ( V_7 , F_18 ( V_7 , V_56 ,
V_58 ) ) ;
if ( V_11 )
F_19 ( 2 ,
L_7 ,
V_56 , F_20 ( V_7 ) , V_11 ) ;
return V_11 ;
}
static inline T_3 F_22 ( const T_4 * V_59 )
{
return F_23 ( ( T_3 * ) ( & V_59 [ 2 ] ) ) ;
}
static int F_24 ( struct V_6 * V_7 , struct V_60 * V_56 )
{
int V_11 ;
if ( V_56 -> V_61 ) {
V_11 = F_15 ( V_7 ,
F_18 ( V_7 , V_56 -> V_62 ,
V_63 ) ) ;
} else {
V_11 = F_15 ( V_7 ,
F_16 ( V_7 , V_56 -> V_62 ) ) ;
}
return V_11 ;
}
static void F_25 ( struct V_6 * V_7 , int V_64 )
{
struct V_60 * V_56 ;
struct V_65 * V_66 ;
int V_67 ;
F_26 ( & V_7 -> V_68 ) ;
F_27 (card->mac_htable, i, tmp, mac, hnode) {
if ( V_64 ) {
if ( V_56 -> V_61 )
F_18 ( V_7 , V_56 -> V_62 ,
V_69 ) ;
else
F_21 ( V_7 , V_56 -> V_62 ) ;
}
F_28 ( & V_56 -> V_70 ) ;
F_29 ( V_56 ) ;
}
F_30 ( & V_7 -> V_68 ) ;
}
static inline int F_31 ( struct V_6 * V_7 ,
struct V_71 * V_72 )
{
if ( V_7 -> V_13 . type == V_14 )
return V_73 ;
if ( F_32 ( V_72 -> V_74 ) )
return V_75 ;
if ( F_33 ( V_72 -> V_74 ) )
return V_76 ;
return V_73 ;
}
static inline void F_34 ( struct V_6 * V_7 ,
struct V_77 * V_78 , struct V_71 * V_72 )
{
struct V_79 * V_80 = F_35 ( V_72 ) ;
if ( V_80 -> V_81 == V_82 )
V_78 -> V_78 . V_83 . V_32 [ 1 ] |= V_84 ;
V_78 -> V_78 . V_83 . V_32 [ 1 ] |= V_85 |
V_86 ;
V_80 -> V_87 = 0 ;
if ( V_7 -> V_88 . V_89 )
V_7 -> V_90 . V_91 ++ ;
}
static void F_36 ( struct V_6 * V_7 , struct V_77 * V_78 ,
struct V_71 * V_72 , int V_92 )
{
struct V_93 * V_94 = (struct V_93 * ) F_37 ( V_72 ) ;
memset ( V_78 , 0 , sizeof( struct V_77 ) ) ;
V_78 -> V_78 . V_83 . V_95 = V_96 ;
if ( V_92 == V_76 )
V_78 -> V_78 . V_83 . V_32 [ 2 ] |= V_97 ;
else if ( V_92 == V_75 )
V_78 -> V_78 . V_83 . V_32 [ 2 ] |= V_98 ;
else
V_78 -> V_78 . V_83 . V_32 [ 2 ] |= V_99 ;
V_78 -> V_78 . V_83 . V_100 = V_72 -> V_101 - V_102 ;
if ( V_94 -> V_103 == F_38 ( V_104 ) ) {
V_78 -> V_78 . V_83 . V_32 [ 2 ] |= V_105 ;
V_78 -> V_78 . V_83 . V_106 = F_39 ( V_94 -> V_107 ) ;
}
}
static int F_40 ( struct V_6 * V_7 ,
struct V_108 * V_109 , unsigned long V_74 )
{
struct V_110 * V_5 ;
F_17 ( V_7 , 2 , L_8 ) ;
V_5 = (struct V_110 * ) V_74 ;
if ( V_5 -> V_78 . V_111 ) {
F_19 ( 2 , L_9
L_10 , V_5 -> V_74 . V_112 . V_106 ,
F_20 ( V_7 ) , V_5 -> V_78 . V_111 ) ;
F_7 ( V_7 , 2 , L_11 , V_5 -> V_78 . V_113 ) ;
F_7 ( V_7 , 2 , L_12 , V_5 -> V_78 . V_111 ) ;
}
return 0 ;
}
static int F_41 ( struct V_6 * V_7 , T_1 V_67 ,
enum V_114 V_115 )
{
struct V_110 * V_5 ;
struct V_116 * V_117 ;
F_7 ( V_7 , 4 , L_13 , V_115 ) ;
V_117 = F_42 ( V_7 , V_115 , V_118 ) ;
if ( ! V_117 )
return - V_54 ;
V_5 = (struct V_110 * ) ( V_117 -> V_74 + V_119 ) ;
V_5 -> V_74 . V_112 . V_106 = V_67 ;
return F_43 ( V_7 , V_117 ,
F_40 , NULL ) ;
}
static void F_44 ( struct V_6 * V_7 )
{
struct V_120 * V_95 ;
F_17 ( V_7 , 3 , L_14 ) ;
F_26 ( & V_7 -> V_121 ) ;
F_10 (id, &card->vid_list, list) {
F_41 ( V_7 , V_95 -> V_122 , V_123 ) ;
}
F_30 ( & V_7 -> V_121 ) ;
}
static int F_45 ( struct V_1 * V_2 ,
T_5 V_124 , T_6 V_122 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_120 * V_95 ;
int V_11 ;
F_7 ( V_7 , 4 , L_15 , V_122 ) ;
if ( ! V_122 )
return 0 ;
if ( V_7 -> V_13 . type == V_21 ) {
F_17 ( V_7 , 3 , L_16 ) ;
return 0 ;
}
if ( F_46 ( V_7 , V_125 ) ) {
F_17 ( V_7 , 3 , L_17 ) ;
return 0 ;
}
V_95 = F_47 ( sizeof( struct V_120 ) , V_126 ) ;
if ( V_95 ) {
V_95 -> V_122 = V_122 ;
V_11 = F_41 ( V_7 , V_122 , V_123 ) ;
if ( V_11 ) {
F_29 ( V_95 ) ;
return V_11 ;
}
F_26 ( & V_7 -> V_121 ) ;
F_48 ( & V_95 -> V_127 , & V_7 -> V_128 ) ;
F_30 ( & V_7 -> V_121 ) ;
} else {
return - V_54 ;
}
return 0 ;
}
static int F_49 ( struct V_1 * V_2 ,
T_5 V_124 , T_6 V_122 )
{
struct V_120 * V_95 , * V_129 = NULL ;
struct V_6 * V_7 = V_2 -> V_8 ;
int V_11 = 0 ;
F_7 ( V_7 , 4 , L_18 , V_122 ) ;
if ( V_7 -> V_13 . type == V_21 ) {
F_17 ( V_7 , 3 , L_19 ) ;
return 0 ;
}
if ( F_46 ( V_7 , V_125 ) ) {
F_17 ( V_7 , 3 , L_20 ) ;
return 0 ;
}
F_26 ( & V_7 -> V_121 ) ;
F_10 (id, &card->vid_list, list) {
if ( V_95 -> V_122 == V_122 ) {
F_50 ( & V_95 -> V_127 ) ;
V_129 = V_95 ;
break;
}
}
F_30 ( & V_7 -> V_121 ) ;
if ( V_129 ) {
V_11 = F_41 ( V_7 , V_122 , V_130 ) ;
F_29 ( V_129 ) ;
}
F_51 ( V_7 -> V_2 ) ;
return V_11 ;
}
static T_7 F_52 ( struct V_1 * V_2 ,
T_7 V_131 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_53 ( V_132 , 2 , L_21 ) ;
if ( ! F_54 ( V_7 , V_133 ) )
V_131 &= ~ V_134 ;
if ( ! F_54 ( V_7 , V_135 ) )
V_131 &= ~ V_136 ;
F_55 ( V_132 , 2 , & V_131 , sizeof( V_131 ) ) ;
return V_131 ;
}
static int F_56 ( struct V_1 * V_2 ,
T_7 V_131 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
T_7 V_137 = V_2 -> V_131 ^ V_131 ;
F_53 ( V_132 , 2 , L_22 ) ;
F_55 ( V_132 , 2 , & V_131 , sizeof( V_131 ) ) ;
if ( V_7 -> V_138 == V_139 ||
V_7 -> V_138 == V_140 )
return 0 ;
if ( ! ( V_137 & V_136 ) )
return 0 ;
return F_57 ( V_7 , V_131 & V_136 ? 1 : 0 ) ;
}
static void F_58 ( struct V_6 * V_7 , int V_141 )
{
F_53 ( V_132 , 2 , L_23 ) ;
F_55 ( V_132 , 2 , & V_7 , sizeof( void * ) ) ;
F_59 ( V_7 , 0 , 1 ) ;
if ( V_7 -> V_142 . V_138 == V_143 &&
V_7 -> V_144 . V_138 == V_143 &&
( V_7 -> V_138 == V_145 ) ) {
if ( V_141 &&
V_7 -> V_13 . type != V_14 ) {
F_60 ( V_7 -> V_2 ) ;
} else {
F_61 () ;
F_62 ( V_7 -> V_2 ) ;
F_63 () ;
}
V_7 -> V_13 . V_146 &= ~ V_147 ;
V_7 -> V_138 = V_148 ;
}
if ( V_7 -> V_138 == V_148 ) {
F_25 ( V_7 , 0 ) ;
F_64 ( V_7 ) ;
V_7 -> V_138 = V_149 ;
}
if ( V_7 -> V_138 == V_149 ) {
F_65 ( V_7 , 0 ) ;
F_66 ( V_7 ) ;
F_67 ( V_7 ) ;
V_7 -> V_138 = V_139 ;
}
if ( V_7 -> V_138 == V_139 ) {
F_68 ( & V_7 -> V_142 ) ;
F_68 ( & V_7 -> V_144 ) ;
}
}
static int F_69 ( struct V_6 * V_7 ,
int V_150 , int * V_151 )
{
int V_152 = 0 ;
struct V_71 * V_72 ;
struct V_77 * V_78 ;
unsigned int V_101 ;
* V_151 = 0 ;
F_70 ( ! V_150 ) ;
while ( V_150 ) {
V_72 = F_71 ( V_7 ,
& V_7 -> V_153 . V_154 -> V_155 [ V_7 -> V_156 . V_157 ] ,
& V_7 -> V_156 . V_158 , & V_7 -> V_156 . V_159 , & V_78 ) ;
if ( ! V_72 ) {
* V_151 = 1 ;
break;
}
V_72 -> V_2 = V_7 -> V_2 ;
switch ( V_78 -> V_78 . V_83 . V_95 ) {
case V_96 :
V_72 -> V_160 = V_161 ;
V_72 -> V_81 = F_72 ( V_72 , V_72 -> V_2 ) ;
if ( ( V_7 -> V_2 -> V_131 & V_136 )
&& ( ( V_78 -> V_78 . V_83 . V_32 [ 1 ] &
( V_86 |
V_85 ) ) ==
( V_86 |
V_85 ) ) )
V_72 -> V_162 = V_163 ;
else
V_72 -> V_162 = V_164 ;
if ( V_72 -> V_81 == F_73 ( V_165 ) )
* ( ( V_166 * ) V_72 -> V_167 ) = ++ V_7 -> V_168 . V_169 ;
V_101 = V_72 -> V_101 ;
F_74 ( & V_7 -> V_170 , V_72 ) ;
break;
case V_171 :
if ( V_7 -> V_13 . type == V_14 ) {
F_75 ( V_72 , sizeof( struct V_77 ) ) ;
F_76 ( V_72 , V_78 ,
sizeof( struct V_77 ) ) ;
V_101 = V_72 -> V_101 ;
V_7 -> V_172 . V_173 ( V_72 ) ;
break;
}
default:
F_77 ( V_72 ) ;
F_17 ( V_7 , 3 , L_24 ) ;
F_55 ( V_174 , 3 , V_78 , V_175 ) ;
continue;
}
V_152 ++ ;
V_150 -- ;
V_7 -> V_176 . V_177 ++ ;
V_7 -> V_176 . V_178 += V_101 ;
}
return V_152 ;
}
static int F_78 ( struct V_179 * V_170 , int V_150 )
{
struct V_6 * V_7 = F_79 ( V_170 , struct V_6 , V_170 ) ;
int V_152 = 0 ;
struct V_180 * V_181 ;
int V_151 ;
int V_182 = V_150 ;
if ( V_7 -> V_88 . V_89 ) {
V_7 -> V_90 . V_183 ++ ;
V_7 -> V_90 . V_184 = F_80 () ;
}
while ( 1 ) {
if ( ! V_7 -> V_156 . V_185 ) {
V_7 -> V_156 . V_186 = 0 ;
V_7 -> V_156 . V_185 = F_81 (
V_7 -> V_74 . V_187 , 0 , & V_7 -> V_156 . V_157 ,
& V_7 -> V_156 . V_186 ) ;
if ( V_7 -> V_156 . V_185 <= 0 ) {
V_7 -> V_156 . V_185 = 0 ;
break;
}
V_7 -> V_156 . V_158 =
& V_7 -> V_153 . V_154 -> V_155 [ V_7 -> V_156 . V_157 ]
. V_181 -> V_188 [ 0 ] ;
V_7 -> V_156 . V_159 = 0 ;
}
while ( V_7 -> V_156 . V_185 ) {
V_181 = & V_7 -> V_153 . V_154 -> V_155 [ V_7 -> V_156 . V_157 ] ;
if ( ! ( V_7 -> V_156 . V_186 &&
F_82 ( V_7 , V_181 -> V_181 ,
V_7 -> V_156 . V_186 , L_25 ) ) )
V_152 += F_69 (
V_7 , V_182 , & V_151 ) ;
else
V_151 = 1 ;
if ( V_151 ) {
if ( V_7 -> V_88 . V_89 )
V_7 -> V_90 . V_189 ++ ;
F_83 ( V_7 ,
V_181 -> V_190 ) ;
F_84 ( V_7 , V_7 -> V_156 . V_157 ) ;
V_7 -> V_156 . V_185 -- ;
if ( V_7 -> V_156 . V_185 ) {
V_7 -> V_156 . V_157 =
( V_7 -> V_156 . V_157 + 1 ) %
V_191 ;
V_7 -> V_156 . V_158 =
& V_7 -> V_153 . V_154
-> V_155 [ V_7 -> V_156 . V_157 ]
. V_181 -> V_188 [ 0 ] ;
V_7 -> V_156 . V_159 = 0 ;
}
}
if ( V_152 >= V_150 )
goto V_192;
else
V_182 = V_150 - V_152 ;
}
}
F_85 ( V_170 ) ;
if ( F_86 ( V_7 -> V_74 . V_187 , 0 ) )
F_87 ( & V_7 -> V_170 ) ;
V_192:
if ( V_7 -> V_88 . V_89 )
V_7 -> V_90 . V_193 += F_80 () -
V_7 -> V_90 . V_184 ;
return V_152 ;
}
static int F_18 ( struct V_6 * V_7 , T_2 * V_56 ,
enum V_114 V_115 )
{
struct V_110 * V_5 ;
struct V_116 * V_117 ;
F_17 ( V_7 , 2 , L_26 ) ;
V_117 = F_42 ( V_7 , V_115 , V_118 ) ;
if ( ! V_117 )
return - V_54 ;
V_5 = (struct V_110 * ) ( V_117 -> V_74 + V_119 ) ;
V_5 -> V_74 . V_194 . V_195 = V_196 ;
memcpy ( & V_5 -> V_74 . V_194 . V_56 , V_56 , V_196 ) ;
return F_43 ( V_7 , V_117 , NULL , NULL ) ;
}
static int F_88 ( struct V_6 * V_7 , T_2 * V_56 )
{
int V_11 ;
F_17 ( V_7 , 2 , L_27 ) ;
V_11 = F_15 ( V_7 , F_18 ( V_7 , V_56 ,
V_63 ) ) ;
if ( V_11 == 0 ) {
V_7 -> V_13 . V_146 |= V_147 ;
memcpy ( V_7 -> V_2 -> V_197 , V_56 , V_196 ) ;
F_89 ( & V_7 -> V_198 -> V_2 ,
L_28 ,
V_7 -> V_2 -> V_197 , V_7 -> V_2 -> V_199 ) ;
} else {
V_7 -> V_13 . V_146 &= ~ V_147 ;
switch ( V_11 ) {
case - V_49 :
F_90 ( & V_7 -> V_198 -> V_2 ,
L_29 , V_56 ) ;
break;
case - V_15 :
F_90 ( & V_7 -> V_198 -> V_2 ,
L_30 , V_56 ) ;
break;
}
}
return V_11 ;
}
static int F_91 ( struct V_6 * V_7 , T_2 * V_56 )
{
int V_11 ;
F_17 ( V_7 , 2 , L_31 ) ;
if ( ! ( V_7 -> V_13 . V_146 & V_147 ) )
return 0 ;
V_11 = F_15 ( V_7 , F_18 ( V_7 , V_56 ,
V_69 ) ) ;
if ( V_11 == 0 )
V_7 -> V_13 . V_146 &= ~ V_147 ;
return V_11 ;
}
static int F_92 ( struct V_6 * V_7 )
{
int V_11 = 0 ;
char V_200 [] = { 0x02 , 0x00 , 0x00 } ;
F_53 ( V_132 , 2 , L_32 ) ;
F_93 ( V_132 , 2 , L_33 , F_94 ( V_7 ) ) ;
if ( F_54 ( V_7 , V_201 ) ) {
V_11 = F_95 ( V_7 ) ;
if ( V_11 ) {
F_19 ( 2 , L_34
L_35 ,
F_94 ( V_7 ) , V_11 ) ;
}
}
if ( V_7 -> V_13 . type == V_202 ||
V_7 -> V_13 . type == V_21 ||
V_7 -> V_13 . type == V_22 ||
V_7 -> V_13 . V_23 ) {
V_11 = F_96 ( V_7 ) ;
if ( V_11 ) {
F_19 ( 2 , L_36
L_37 , F_94 ( V_7 ) , V_11 ) ;
F_93 ( V_132 , 2 , L_38 , V_11 ) ;
return V_11 ;
}
F_55 ( V_132 , 2 , V_7 -> V_2 -> V_197 , V_196 ) ;
} else {
F_97 ( V_7 -> V_2 -> V_197 ) ;
memcpy ( V_7 -> V_2 -> V_197 , V_200 , 3 ) ;
}
return 0 ;
}
static int F_98 ( struct V_1 * V_2 , void * V_203 )
{
struct V_204 * V_59 = V_203 ;
struct V_6 * V_7 = V_2 -> V_8 ;
int V_11 = 0 ;
F_17 ( V_7 , 3 , L_39 ) ;
if ( F_8 ( V_2 ) != V_35 ) {
F_17 ( V_7 , 3 , L_40 ) ;
return - V_31 ;
}
if ( V_7 -> V_13 . type == V_14 ||
V_7 -> V_13 . type == V_21 ||
V_7 -> V_13 . type == V_22 ) {
F_17 ( V_7 , 3 , L_41 ) ;
return - V_31 ;
}
F_99 ( V_7 , 3 , V_59 -> V_205 , V_196 ) ;
if ( F_46 ( V_7 , V_125 ) ) {
F_17 ( V_7 , 3 , L_42 ) ;
return - V_206 ;
}
V_11 = F_91 ( V_7 , & V_7 -> V_2 -> V_197 [ 0 ] ) ;
if ( ! V_11 || ( V_11 == - V_53 ) )
V_11 = F_88 ( V_7 , V_59 -> V_205 ) ;
return V_11 ? - V_27 : 0 ;
}
static void F_100 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
enum V_207 V_208 ;
int V_209 ;
int V_11 ;
F_17 ( V_7 , 3 , L_43 ) ;
if ( ! V_7 -> V_88 . V_210 . V_211 )
return;
V_208 = ( V_2 -> V_32 & V_212 ) ? V_213
: V_214 ;
if ( V_208 == V_7 -> V_13 . V_208 )
return;
if ( V_208 == V_213 ) {
if ( V_7 -> V_88 . V_210 . V_215 )
V_209 = V_216 ;
else
V_209 = V_217 ;
} else
V_209 = V_218 ;
V_11 = F_101 ( V_7 , V_209 ) ;
F_93 ( V_132 , 2 , L_44 ,
( V_208 == V_213 ) ? '+' : '-' , V_11 ) ;
if ( ! V_11 ) {
V_7 -> V_88 . V_210 . V_209 = V_209 ;
V_7 -> V_13 . V_208 = V_208 ;
}
}
static void
F_102 ( struct V_6 * V_7 , struct V_219 * V_220 , T_4 V_61 )
{
struct V_60 * V_56 ;
F_103 (card->mac_htable, mac, hnode,
qeth_l2_mac_hash(ha->addr)) {
if ( V_61 == V_56 -> V_61 &&
! memcmp ( V_220 -> V_59 , V_56 -> V_62 , V_196 ) ) {
V_56 -> V_221 = V_222 ;
return;
}
}
V_56 = F_104 ( sizeof( struct V_60 ) , V_126 ) ;
if ( ! V_56 )
return;
memcpy ( V_56 -> V_62 , V_220 -> V_59 , V_196 ) ;
V_56 -> V_61 = V_61 ;
V_56 -> V_221 = V_223 ;
F_105 ( V_7 -> V_224 , & V_56 -> V_70 ,
F_22 ( V_56 -> V_62 ) ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_219 * V_220 ;
struct V_60 * V_56 ;
struct V_65 * V_66 ;
int V_67 ;
int V_11 ;
if ( V_7 -> V_13 . type == V_14 )
return;
F_17 ( V_7 , 3 , L_45 ) ;
if ( F_106 ( V_7 , V_125 ) &&
( V_7 -> V_138 != V_145 ) )
return;
F_26 ( & V_7 -> V_68 ) ;
F_107 (ha, dev)
F_102 ( V_7 , V_220 , 0 ) ;
F_108 (ha, dev)
F_102 ( V_7 , V_220 , 1 ) ;
F_27 (card->mac_htable, i, tmp, mac, hnode) {
if ( V_56 -> V_221 == V_225 ) {
if ( ! V_56 -> V_61 )
V_11 = F_21 ( V_7 ,
V_56 -> V_62 ) ;
else {
V_11 = F_18 ( V_7 , V_56 -> V_62 ,
V_69 ) ;
}
F_28 ( & V_56 -> V_70 ) ;
F_29 ( V_56 ) ;
} else if ( V_56 -> V_221 == V_223 ) {
V_11 = F_24 ( V_7 , V_56 ) ;
if ( V_11 ) {
F_28 ( & V_56 -> V_70 ) ;
F_29 ( V_56 ) ;
} else
V_56 -> V_221 = V_225 ;
} else
V_56 -> V_221 = V_225 ;
}
F_30 ( & V_7 -> V_68 ) ;
if ( F_109 ( V_7 , V_226 ) )
F_110 ( V_7 ) ;
else
F_100 ( V_7 ) ;
}
static int F_111 ( struct V_71 * V_72 , struct V_1 * V_2 )
{
int V_11 ;
struct V_77 * V_78 = NULL ;
int V_227 = 0 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_71 * V_228 = V_72 ;
int V_92 = F_31 ( V_7 , V_72 ) ;
struct V_229 * V_230 ;
int V_231 = V_72 -> V_101 ;
int V_232 = - 1 ;
int V_233 = 0 ;
int V_234 = 0 ;
if ( V_7 -> V_153 . V_235 || ( V_92 &&
V_7 -> V_13 . V_236 ) )
V_230 = V_7 -> V_153 . V_237 [ F_112 ( V_7 , V_72 ,
F_113 ( V_72 ) , V_92 ) ] ;
else
V_230 = V_7 -> V_153 . V_237 [ V_7 -> V_153 . V_238 ] ;
if ( ( V_7 -> V_138 != V_145 ) || ! V_7 -> V_239 ) {
V_7 -> V_176 . V_240 ++ ;
goto V_241;
}
if ( ( V_7 -> V_13 . type == V_14 ) &&
( V_72 -> V_81 == F_73 ( V_242 ) ) )
goto V_241;
if ( V_7 -> V_88 . V_89 ) {
V_7 -> V_90 . V_243 ++ ;
V_7 -> V_90 . V_244 = F_80 () ;
}
F_114 ( V_2 ) ;
if ( V_7 -> V_13 . type == V_14 )
V_78 = (struct V_77 * ) V_72 -> V_74 ;
else {
if ( V_7 -> V_13 . type == V_202 ) {
V_228 = V_72 ;
V_232 = V_245 ;
V_234 = V_245 ;
V_78 = F_115 ( V_246 ,
V_126 ) ;
if ( ! V_78 )
goto V_241;
V_233 ++ ;
F_116 ( V_228 ) ;
F_36 ( V_7 , V_78 , V_228 , V_92 ) ;
V_78 -> V_78 . V_83 . V_100 = V_228 -> V_101 ;
memcpy ( ( ( char * ) V_78 ) + sizeof( struct V_77 ) ,
F_37 ( V_228 ) , V_245 ) ;
} else {
V_228 = F_117 ( V_72 ,
sizeof( struct V_77 ) ) ;
if ( ! V_228 )
goto V_241;
V_78 = (struct V_77 * ) F_75 ( V_228 ,
sizeof( struct V_77 ) ) ;
F_118 ( V_228 , sizeof( struct V_77 ) ) ;
F_36 ( V_7 , V_78 , V_228 , V_92 ) ;
if ( V_228 -> V_162 == V_247 )
F_34 ( V_7 , V_78 , V_228 ) ;
}
}
V_227 = F_119 ( V_7 , V_228 , V_233 ) ;
if ( ! V_227 ) {
if ( V_232 >= 0 )
F_120 ( V_246 , V_78 ) ;
goto V_241;
}
if ( V_7 -> V_13 . type != V_202 ) {
if ( F_121 ( V_228 , & V_78 ,
sizeof( struct V_248 ) ) )
goto V_241;
V_11 = F_122 ( V_7 , V_230 , V_228 , V_78 ,
V_227 ) ;
} else
V_11 = F_123 ( V_7 , V_230 , V_228 , V_78 ,
V_227 , V_232 , V_234 ) ;
if ( ! V_11 ) {
V_7 -> V_176 . V_249 ++ ;
V_7 -> V_176 . V_231 += V_231 ;
if ( V_228 != V_72 )
F_77 ( V_72 ) ;
V_11 = V_250 ;
} else {
if ( V_232 >= 0 )
F_120 ( V_246 , V_78 ) ;
if ( V_11 == - V_251 ) {
if ( V_228 != V_72 )
F_77 ( V_228 ) ;
return V_252 ;
} else
goto V_241;
}
F_124 ( V_2 ) ;
if ( V_7 -> V_88 . V_89 )
V_7 -> V_90 . V_253 += F_80 () -
V_7 -> V_90 . V_244 ;
return V_11 ;
V_241:
V_7 -> V_176 . V_254 ++ ;
V_7 -> V_176 . V_255 ++ ;
if ( ( V_228 != V_72 ) && V_228 )
F_77 ( V_228 ) ;
F_77 ( V_72 ) ;
F_124 ( V_2 ) ;
return V_250 ;
}
static int F_125 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_11 = 0 ;
F_17 ( V_7 , 4 , L_46 ) ;
if ( V_7 -> V_138 == V_145 )
return V_11 ;
if ( V_7 -> V_138 != V_148 )
return - V_12 ;
if ( ( V_7 -> V_13 . type != V_14 ) &&
( ! ( V_7 -> V_13 . V_146 & V_147 ) ) ) {
F_17 ( V_7 , 4 , L_47 ) ;
return - V_15 ;
}
V_7 -> V_74 . V_138 = V_143 ;
V_7 -> V_138 = V_145 ;
F_126 ( V_2 ) ;
if ( F_127 ( V_7 -> V_74 . V_187 , 0 ) >= 0 ) {
F_128 ( & V_7 -> V_170 ) ;
F_87 ( & V_7 -> V_170 ) ;
} else
V_11 = - V_55 ;
return V_11 ;
}
static int F_129 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_17 ( V_7 , 5 , L_48 ) ;
if ( F_46 ( V_7 , V_125 ) ) {
F_17 ( V_7 , 3 , L_49 ) ;
return - V_206 ;
}
return F_125 ( V_2 ) ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_17 ( V_7 , 4 , L_50 ) ;
F_130 ( V_2 ) ;
if ( V_7 -> V_138 == V_145 ) {
V_7 -> V_138 = V_148 ;
F_131 ( & V_7 -> V_170 ) ;
}
return 0 ;
}
static int F_132 ( struct V_256 * V_198 )
{
struct V_6 * V_7 = F_133 ( & V_198 -> V_2 ) ;
F_134 ( & V_198 -> V_2 ) ;
F_135 ( & V_7 -> V_128 ) ;
F_136 ( V_7 -> V_224 ) ;
V_7 -> V_88 . V_257 = 1 ;
V_7 -> V_13 . V_258 = 0 ;
return 0 ;
}
static void F_137 ( struct V_256 * V_259 )
{
struct V_6 * V_7 = F_133 ( & V_259 -> V_2 ) ;
F_138 ( & V_259 -> V_2 ) ;
F_59 ( V_7 , 0 , 1 ) ;
F_139 ( V_7 -> V_260 , F_106 ( V_7 , 0xffffffff ) == 0 ) ;
if ( V_259 -> V_138 == V_261 )
F_140 ( V_259 ) ;
if ( V_7 -> V_2 ) {
F_141 ( V_7 -> V_2 ) ;
V_7 -> V_2 = NULL ;
}
return;
}
static int F_142 ( struct V_6 * V_7 )
{
switch ( V_7 -> V_13 . type ) {
case V_202 :
V_7 -> V_2 = F_143 ( 0 , L_51 , V_262 ,
V_263 ) ;
break;
case V_14 :
V_7 -> V_2 = F_143 ( 0 , L_52 , V_262 ,
V_263 ) ;
V_7 -> V_2 -> V_32 |= V_264 ;
break;
default:
V_7 -> V_2 = F_144 ( 0 ) ;
}
if ( ! V_7 -> V_2 )
return - V_12 ;
V_7 -> V_2 -> V_8 = V_7 ;
V_7 -> V_2 -> V_265 = V_266 ;
V_7 -> V_2 -> V_267 = V_7 -> V_13 . V_268 ;
V_7 -> V_2 -> V_269 = & V_270 ;
V_7 -> V_2 -> V_271 =
( V_7 -> V_13 . type != V_14 ) ?
& V_272 : & V_273 ;
V_7 -> V_2 -> V_131 |= V_274 ;
if ( V_7 -> V_13 . type == V_20 && ! V_7 -> V_13 . V_23 ) {
V_7 -> V_2 -> V_275 = V_134 | V_136 ;
V_7 -> V_2 -> V_131 |= V_136 ;
}
V_7 -> V_13 . V_276 = 1 ;
F_92 ( V_7 ) ;
F_145 ( V_7 -> V_2 , & V_7 -> V_198 -> V_2 ) ;
F_146 ( V_7 -> V_2 , & V_7 -> V_170 , F_78 , V_277 ) ;
F_147 ( V_7 -> V_2 ) ;
return F_148 ( V_7 -> V_2 ) ;
}
static int F_149 ( struct V_6 * V_7 )
{
if ( F_150 ( V_7 , 0 ) )
return - V_12 ;
if ( F_54 ( V_7 , V_135 ) )
F_57 ( V_7 , 1 ) ;
F_151 ( V_7 ) ;
return 0 ;
}
static int F_152 ( struct V_256 * V_198 , int V_141 )
{
struct V_6 * V_7 = F_133 ( & V_198 -> V_2 ) ;
int V_11 = 0 ;
enum V_278 V_279 ;
F_153 ( & V_7 -> V_280 ) ;
F_153 ( & V_7 -> V_281 ) ;
F_53 ( V_132 , 2 , L_53 ) ;
F_55 ( V_132 , 2 , & V_7 , sizeof( void * ) ) ;
V_279 = V_7 -> V_138 ;
V_11 = F_154 ( V_7 ) ;
if ( V_11 ) {
F_93 ( V_132 , 2 , L_54 , V_11 ) ;
V_11 = - V_12 ;
goto V_282;
}
F_155 ( V_7 ) ;
if ( V_7 -> V_88 . V_210 . V_283 )
F_89 ( & V_7 -> V_198 -> V_2 ,
L_55 ) ;
F_156 ( V_7 ) ;
if ( ! V_7 -> V_2 && F_142 ( V_7 ) ) {
V_11 = - V_12 ;
goto V_282;
}
if ( V_7 -> V_13 . type != V_14 )
F_88 ( V_7 , & V_7 -> V_2 -> V_197 [ 0 ] ) ;
if ( F_157 ( V_7 , V_284 ) ) {
if ( V_7 -> V_13 . V_258 &&
F_158 ( V_7 , V_285 ) )
V_7 -> V_13 . V_258 = 0 ;
} else
V_7 -> V_13 . V_258 = 0 ;
F_159 ( V_7 ) ;
V_7 -> V_138 = V_149 ;
memset ( & V_7 -> V_156 , 0 , sizeof( struct V_286 ) ) ;
F_160 ( V_7 ) ;
F_53 ( V_132 , 2 , L_56 ) ;
V_11 = F_161 ( V_7 ) ;
if ( V_11 ) {
F_93 ( V_132 , 2 , L_57 , V_11 ) ;
if ( V_11 == 0xe080 ) {
F_90 ( & V_7 -> V_198 -> V_2 ,
L_58 ) ;
V_7 -> V_239 = 0 ;
goto V_287;
}
V_11 = - V_12 ;
goto V_282;
} else
V_7 -> V_239 = 1 ;
V_287:
if ( ( V_7 -> V_13 . type == V_20 ) ||
( V_7 -> V_13 . type == V_22 ) ) {
if ( F_149 ( V_7 ) )
goto V_282;
}
if ( V_7 -> V_13 . type != V_14 &&
V_7 -> V_13 . type != V_21 )
F_44 ( V_7 ) ;
F_130 ( V_7 -> V_2 ) ;
V_11 = F_162 ( V_7 ) ;
if ( V_11 ) {
F_93 ( V_132 , 2 , L_59 , V_11 ) ;
V_11 = - V_12 ;
goto V_282;
}
V_7 -> V_138 = V_148 ;
if ( V_7 -> V_239 )
F_163 ( V_7 -> V_2 ) ;
else
F_147 ( V_7 -> V_2 ) ;
F_59 ( V_7 , 0xffffffff , 0 ) ;
if ( V_279 == V_140 ) {
if ( V_141 &&
V_7 -> V_13 . type != V_14 ) {
F_125 ( V_7 -> V_2 ) ;
} else {
F_61 () ;
F_164 ( V_7 -> V_2 ) ;
F_63 () ;
}
F_51 ( V_7 -> V_2 ) ;
}
F_165 ( & V_198 -> V_2 . V_288 , V_289 ) ;
F_166 ( & V_7 -> V_281 ) ;
F_166 ( & V_7 -> V_280 ) ;
return 0 ;
V_282:
F_58 ( V_7 , 0 ) ;
F_167 ( F_168 ( V_7 ) ) ;
F_167 ( F_169 ( V_7 ) ) ;
F_167 ( F_14 ( V_7 ) ) ;
F_170 ( F_168 ( V_7 ) ) ;
if ( V_279 == V_140 )
V_7 -> V_138 = V_140 ;
else
V_7 -> V_138 = V_139 ;
F_166 ( & V_7 -> V_281 ) ;
F_166 ( & V_7 -> V_280 ) ;
return V_11 ;
}
static int F_171 ( struct V_256 * V_198 )
{
return F_152 ( V_198 , 0 ) ;
}
static int F_172 ( struct V_256 * V_259 ,
int V_141 )
{
struct V_6 * V_7 = F_133 ( & V_259 -> V_2 ) ;
int V_11 = 0 , V_290 = 0 , V_291 = 0 ;
enum V_278 V_279 ;
F_153 ( & V_7 -> V_280 ) ;
F_153 ( & V_7 -> V_281 ) ;
F_53 ( V_132 , 3 , L_60 ) ;
F_55 ( V_132 , 3 , & V_7 , sizeof( void * ) ) ;
if ( V_7 -> V_2 && F_173 ( V_7 -> V_2 ) )
F_147 ( V_7 -> V_2 ) ;
V_279 = V_7 -> V_138 ;
if ( ( ! V_141 && V_7 -> V_13 . V_258 ) || V_7 -> V_13 . V_258 == 2 ) {
F_158 ( V_7 , V_292 ) ;
V_7 -> V_13 . V_258 = 1 ;
}
F_58 ( V_7 , V_141 ) ;
V_11 = F_167 ( F_168 ( V_7 ) ) ;
V_290 = F_167 ( F_169 ( V_7 ) ) ;
V_291 = F_167 ( F_14 ( V_7 ) ) ;
if ( ! V_11 )
V_11 = ( V_290 ) ? V_290 : V_291 ;
if ( V_11 )
F_93 ( V_132 , 2 , L_57 , V_11 ) ;
F_170 ( F_168 ( V_7 ) ) ;
if ( V_279 == V_145 )
V_7 -> V_138 = V_140 ;
F_165 ( & V_259 -> V_2 . V_288 , V_289 ) ;
F_166 ( & V_7 -> V_281 ) ;
F_166 ( & V_7 -> V_280 ) ;
return 0 ;
}
static int F_140 ( struct V_256 * V_259 )
{
return F_172 ( V_259 , 0 ) ;
}
static int F_174 ( void * V_293 )
{
struct V_6 * V_7 ;
int V_11 = 0 ;
V_7 = (struct V_6 * ) V_293 ;
F_17 ( V_7 , 2 , L_61 ) ;
if ( ! F_175 ( V_7 , V_125 ) )
return 0 ;
F_17 ( V_7 , 2 , L_62 ) ;
F_90 ( & V_7 -> V_198 -> V_2 ,
L_63 ) ;
F_176 ( V_7 ) ;
F_172 ( V_7 -> V_198 , 1 ) ;
V_11 = F_152 ( V_7 -> V_198 , 1 ) ;
if ( ! V_11 )
F_89 ( & V_7 -> V_198 -> V_2 ,
L_64 ) ;
else {
F_177 ( V_7 ) ;
F_90 ( & V_7 -> V_198 -> V_2 , L_65
L_66 ) ;
}
F_178 ( V_7 ) ;
F_179 ( V_7 , V_125 ) ;
F_180 ( V_7 , V_125 ) ;
return 0 ;
}
static int T_8 F_181 ( void )
{
F_182 ( L_67 ) ;
return 0 ;
}
static void T_9 F_183 ( void )
{
F_182 ( L_68 ) ;
}
static void F_184 ( struct V_256 * V_198 )
{
struct V_6 * V_7 = F_133 ( & V_198 -> V_2 ) ;
F_59 ( V_7 , 0 , 1 ) ;
if ( ( V_198 -> V_138 == V_261 ) && V_7 -> V_13 . V_258 )
F_158 ( V_7 , V_292 ) ;
F_65 ( V_7 , 0 ) ;
F_66 ( V_7 ) ;
F_170 ( F_168 ( V_7 ) ) ;
}
static int F_185 ( struct V_256 * V_198 )
{
struct V_6 * V_7 = F_133 ( & V_198 -> V_2 ) ;
if ( V_7 -> V_2 )
F_186 ( V_7 -> V_2 ) ;
F_59 ( V_7 , 0 , 1 ) ;
F_139 ( V_7 -> V_260 , F_106 ( V_7 , 0xffffffff ) == 0 ) ;
if ( V_198 -> V_138 == V_294 )
return 0 ;
if ( V_7 -> V_138 == V_145 ) {
if ( V_7 -> V_13 . V_258 )
F_158 ( V_7 , V_292 ) ;
F_172 ( V_7 -> V_198 , 1 ) ;
} else
F_172 ( V_7 -> V_198 , 0 ) ;
return 0 ;
}
static int F_187 ( struct V_256 * V_198 )
{
struct V_6 * V_7 = F_133 ( & V_198 -> V_2 ) ;
int V_11 = 0 ;
if ( V_198 -> V_138 == V_294 )
goto V_192;
if ( V_7 -> V_138 == V_140 ) {
V_11 = F_152 ( V_7 -> V_198 , 1 ) ;
if ( V_11 ) {
F_61 () ;
F_62 ( V_7 -> V_2 ) ;
F_63 () ;
}
} else
V_11 = F_152 ( V_7 -> V_198 , 0 ) ;
V_192:
F_59 ( V_7 , 0xffffffff , 0 ) ;
if ( V_7 -> V_2 )
F_188 ( V_7 -> V_2 ) ;
if ( V_11 )
F_90 ( & V_7 -> V_198 -> V_2 , L_65
L_66 ) ;
return V_11 ;
}
static int F_189 ( struct V_6 * V_7 ,
struct V_110 * V_5 )
{
switch ( V_5 -> V_78 . V_113 ) {
case V_295 :
case V_296 :
if ( V_5 -> V_74 . V_210 . V_78 . V_297 ==
V_298 ) {
F_190 ( V_7 , V_5 ) ;
return 0 ;
} else
return 1 ;
case V_299 :
F_191 ( V_7 , V_5 ) ;
return 0 ;
default:
return 1 ;
}
}
static int F_192 ( struct V_6 * V_7 , int V_101 ,
struct V_116 * V_117 )
{
unsigned long V_32 ;
int V_11 = 0 ;
F_17 ( V_7 , 5 , L_69 ) ;
F_139 ( V_7 -> V_260 ,
F_193 ( & V_7 -> V_144 . V_300 , 0 , 1 ) == 0 ) ;
F_194 ( V_7 , V_101 , V_117 ) ;
F_17 ( V_7 , 6 , L_70 ) ;
F_195 ( F_196 ( V_7 -> V_144 . V_187 ) , V_32 ) ;
V_11 = F_197 ( V_7 -> V_144 . V_187 , & V_7 -> V_144 . V_301 ,
( V_302 ) V_117 , 0 , 0 ) ;
F_198 ( F_196 ( V_7 -> V_144 . V_187 ) , V_32 ) ;
if ( V_11 ) {
F_19 ( 2 , L_71
L_72 , V_11 ) ;
F_7 ( V_7 , 2 , L_73 , V_11 ) ;
F_199 ( V_117 -> V_303 , V_117 ) ;
F_200 ( & V_7 -> V_144 . V_300 , 0 ) ;
F_201 ( & V_7 -> V_260 ) ;
}
return V_11 ;
}
static int F_202 ( struct V_6 * V_7 ,
struct V_116 * V_117 , int V_304 )
{
T_6 V_305 , V_306 ;
F_17 ( V_7 , 4 , L_74 ) ;
F_203 ( V_7 , V_117 , V_307 ) ;
V_305 = ( T_6 ) ( V_119 + V_304 ) ;
V_306 = ( T_6 ) V_304 ;
memcpy ( F_204 ( V_117 -> V_74 ) , & V_305 , 2 ) ;
memcpy ( F_205 ( V_117 -> V_74 ) , & V_306 , 2 ) ;
memcpy ( F_206 ( V_117 -> V_74 ) , & V_306 , 2 ) ;
memcpy ( F_207 ( V_117 -> V_74 ) , & V_306 , 2 ) ;
return F_192 ( V_7 , V_305 , V_117 ) ;
}
int F_208 ( struct V_1 * V_2 , void * V_74 , int V_304 )
{
struct V_116 * V_117 ;
struct V_6 * V_7 ;
int V_11 ;
if ( ! V_2 )
return - V_12 ;
V_7 = V_2 -> V_8 ;
if ( ! V_7 )
return - V_12 ;
F_17 ( V_7 , 2 , L_75 ) ;
if ( ! F_2 ( V_7 ) )
return - V_12 ;
V_117 = F_209 ( & V_7 -> V_144 ) ;
memcpy ( V_117 -> V_74 + V_119 , V_74 , V_304 ) ;
V_11 = F_202 ( V_7 , V_117 , V_304 ) ;
return V_11 ;
}
int F_210 ( unsigned char * V_36 , struct V_1 * * V_2 ,
int (* F_211)( struct V_1 * , void * ) ,
int (* V_173)( struct V_71 * ) )
{
struct V_6 * V_7 ;
* V_2 = F_12 ( V_36 ) ;
if ( * V_2 == NULL )
return - V_12 ;
V_7 = ( * V_2 ) -> V_8 ;
if ( ! V_7 )
return - V_12 ;
F_17 ( V_7 , 2 , L_76 ) ;
if ( ( F_211 == NULL ) || ( V_173 == NULL ) )
return - V_27 ;
V_7 -> V_172 . F_211 = F_211 ;
V_7 -> V_172 . V_173 = V_173 ;
return 0 ;
}
void F_212 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
if ( ! V_2 )
return;
V_7 = V_2 -> V_8 ;
if ( ! V_7 )
return;
F_17 ( V_7 , 2 , L_77 ) ;
V_7 -> V_172 . F_211 = NULL ;
V_7 -> V_172 . V_173 = NULL ;
return;
}
static void F_213 ( struct V_6 * V_7 ,
enum V_308 V_309 ,
T_4 V_310 , struct V_311 * V_312 , struct V_313 * V_314 )
{
char V_315 [ 7 ] [ 32 ] ;
char * V_316 [ 8 ] ;
int V_67 = 0 ;
switch ( V_309 ) {
case V_317 :
snprintf ( V_315 [ V_67 ] , sizeof( V_315 [ V_67 ] ) , L_78 ,
( V_310 & V_318 )
? L_79 : L_80 ) ;
V_316 [ V_67 ] = V_315 [ V_67 ] ; V_67 ++ ;
if ( V_310 & V_319 ) {
snprintf ( V_315 [ V_67 ] , sizeof( V_315 [ V_67 ] ) , L_81 ,
V_314 -> V_320 ) ;
V_316 [ V_67 ] = V_315 [ V_67 ] ; V_67 ++ ;
}
if ( V_310 & V_321 ) {
snprintf ( V_315 [ V_67 ] , sizeof( V_315 [ V_67 ] ) , L_82 ,
V_314 -> V_56 ) ;
V_316 [ V_67 ] = V_315 [ V_67 ] ; V_67 ++ ;
}
snprintf ( V_315 [ V_67 ] , sizeof( V_315 [ V_67 ] ) , L_83 ,
V_312 -> V_322 , V_312 -> V_323 , V_312 -> V_324 ) ;
V_316 [ V_67 ] = V_315 [ V_67 ] ; V_67 ++ ;
snprintf ( V_315 [ V_67 ] , sizeof( V_315 [ V_67 ] ) , L_84 , V_312 -> V_325 ) ;
V_316 [ V_67 ] = V_315 [ V_67 ] ; V_67 ++ ;
snprintf ( V_315 [ V_67 ] , sizeof( V_315 [ V_67 ] ) , L_85 ,
V_312 -> V_326 ) ;
V_316 [ V_67 ] = V_315 [ V_67 ] ; V_67 ++ ;
snprintf ( V_315 [ V_67 ] , sizeof( V_315 [ V_67 ] ) , L_86 , V_312 -> V_327 ) ;
V_316 [ V_67 ] = V_315 [ V_67 ] ; V_67 ++ ;
break;
case V_328 :
snprintf ( V_315 [ V_67 ] , sizeof( V_315 [ V_67 ] ) , L_87 ) ;
V_316 [ V_67 ] = V_315 [ V_67 ] ; V_67 ++ ;
break;
case V_329 :
snprintf ( V_315 [ V_67 ] , sizeof( V_315 [ V_67 ] ) , L_88 ) ;
V_316 [ V_67 ] = V_315 [ V_67 ] ; V_67 ++ ;
break;
}
V_316 [ V_67 ] = NULL ;
F_214 ( & V_7 -> V_198 -> V_2 . V_288 , V_289 , V_316 ) ;
}
static void F_215 ( struct V_330 * V_331 )
{
struct V_332 * V_74 =
F_79 ( V_331 , struct V_332 , V_333 ) ;
struct V_334 * V_335 = & V_74 -> V_336 . V_335 [ 0 ] ;
char V_337 [ 32 ] ;
char V_338 [ 32 ] ;
char V_339 [ 32 ] ;
char * V_316 [] = {
V_337 ,
V_338 ,
V_339 ,
NULL
} ;
F_153 ( & V_74 -> V_7 -> V_281 ) ;
V_74 -> V_7 -> V_88 . V_210 . V_209 = V_335 -> V_209 ;
F_166 ( & V_74 -> V_7 -> V_281 ) ;
snprintf ( V_337 , sizeof( V_337 ) , L_89 ) ;
snprintf ( V_338 , sizeof( V_338 ) , L_90 ,
( V_335 -> V_209 == V_218 ) ? L_91 :
( V_335 -> V_209 == V_216 ) ? L_92 :
( V_335 -> V_209 == V_217 ) ? L_93 :
L_94 ) ;
snprintf ( V_339 , sizeof( V_339 ) , L_95 ,
( V_335 -> V_138 == V_340 ) ? L_96 :
( V_335 -> V_138 == V_341 ) ? L_97 :
( V_335 -> V_138 == V_342 ) ? L_98 :
L_94 ) ;
F_214 ( & V_74 -> V_7 -> V_198 -> V_2 . V_288 ,
V_289 , V_316 ) ;
F_29 ( V_74 ) ;
}
static void F_190 ( struct V_6 * V_7 ,
struct V_110 * V_5 )
{
struct V_343 * V_336 =
& V_5 -> V_74 . V_210 . V_74 . V_344 ;
struct V_332 * V_74 ;
int V_345 ;
F_17 ( V_7 , 2 , L_99 ) ;
if ( V_336 -> V_346 != sizeof( struct V_334 ) ) {
F_7 ( V_7 , 2 , L_100 , V_336 -> V_346 ) ;
return;
}
V_345 = sizeof( struct V_334 ) * V_336 -> V_347 ;
V_74 = F_104 ( sizeof( struct V_332 ) + V_345 ,
V_126 ) ;
if ( ! V_74 ) {
F_17 ( V_7 , 2 , L_101 ) ;
return;
}
F_216 ( & V_74 -> V_333 , F_215 ) ;
V_74 -> V_7 = V_7 ;
memcpy ( & V_74 -> V_336 , V_336 ,
sizeof( struct V_343 ) + V_345 ) ;
F_217 ( V_348 , & V_74 -> V_333 ) ;
}
static void F_218 ( struct V_330 * V_331 )
{
struct V_349 * V_74 =
F_79 ( V_331 , struct V_349 , V_333 ) ;
int V_67 ;
if ( V_74 -> V_350 . V_351 ) {
F_89 ( & V_74 -> V_7 -> V_198 -> V_2 ,
L_102 ,
V_74 -> V_7 -> V_2 -> V_199 ,
( V_74 -> V_350 . V_351 == 0x01 )
? L_103
: ( V_74 -> V_350 . V_351 == 0x02 )
? L_104
: L_105 ) ;
F_153 ( & V_74 -> V_7 -> V_281 ) ;
V_74 -> V_7 -> V_88 . V_210 . V_352 = 0 ;
F_166 ( & V_74 -> V_7 -> V_281 ) ;
F_213 ( V_74 -> V_7 , V_328 ,
0 , NULL , NULL ) ;
} else
for ( V_67 = 0 ; V_67 < V_74 -> V_350 . V_347 ; V_67 ++ ) {
struct V_353 * V_335 =
& V_74 -> V_350 . V_335 [ V_67 ] ;
F_213 ( V_74 -> V_7 ,
V_317 ,
V_335 -> V_354 ,
& V_335 -> V_312 , & V_335 -> V_314 ) ;
}
F_29 ( V_74 ) ;
}
static void F_191 ( struct V_6 * V_7 ,
struct V_110 * V_5 )
{
struct V_355 * V_350 =
& V_5 -> V_74 . V_356 ;
struct V_349 * V_74 ;
int V_345 ;
F_17 ( V_7 , 2 , L_106 ) ;
if ( V_5 -> V_78 . V_111 != 0x0000 ) {
if ( V_5 -> V_78 . V_111 == 0x0010 ) {
if ( V_350 -> V_351 == 0x00 )
V_350 -> V_351 = 0xff ;
} else {
F_7 ( V_7 , 2 , L_107 ,
V_5 -> V_78 . V_111 ) ;
return;
}
}
V_345 = sizeof( struct V_353 ) *
V_350 -> V_347 ;
V_74 = F_104 ( sizeof( struct V_349 ) + V_345 ,
V_126 ) ;
if ( ! V_74 ) {
F_17 ( V_7 , 2 , L_108 ) ;
return;
}
F_216 ( & V_74 -> V_333 , F_218 ) ;
V_74 -> V_7 = V_7 ;
memcpy ( & V_74 -> V_350 , V_350 ,
sizeof( struct V_355 ) + V_345 ) ;
F_217 ( V_348 , & V_74 -> V_333 ) ;
}
static int F_219 ( struct V_6 * V_7 ,
struct V_357 * V_358 , enum V_359 V_360 )
{
int V_11 ;
int V_361 = ( V_7 -> V_13 . type == V_202 ) ;
if ( ( V_361 && ( V_358 -> V_362 == V_43 ) ) ||
( ! V_361 && ( V_358 -> V_362 == V_358 -> V_363 ) ) )
switch ( V_358 -> V_363 ) {
case 0x0000 :
V_11 = 0 ;
break;
case 0x2B04 :
case 0x0004 :
V_11 = - V_31 ;
break;
case 0x2B0C :
case 0x000C :
V_11 = - V_12 ;
F_220 ( & V_7 -> V_198 -> V_2 ,
L_109 ) ;
break;
case 0x2B14 :
case 0x0014 :
switch ( V_360 ) {
case V_364 :
V_11 = - V_49 ;
F_220 ( & V_7 -> V_198 -> V_2 ,
L_110 ) ;
break;
case V_365 :
V_11 = - V_251 ;
F_220 ( & V_7 -> V_198 -> V_2 ,
L_111 ) ;
break;
default:
V_11 = - V_55 ;
}
break;
case 0x2B18 :
case 0x0018 :
V_11 = - V_251 ;
F_220 ( & V_7 -> V_198 -> V_2 ,
L_112 ) ;
break;
case 0x2B1C :
case 0x001C :
V_11 = - V_49 ;
F_220 ( & V_7 -> V_198 -> V_2 ,
L_113 ) ;
break;
case 0x2B24 :
case 0x0024 :
V_11 = - V_251 ;
F_220 ( & V_7 -> V_198 -> V_2 ,
L_111 ) ;
break;
case 0x2B20 :
case 0x0020 :
V_11 = - V_366 ;
F_220 ( & V_7 -> V_198 -> V_2 ,
L_114 ) ;
break;
default:
V_11 = - V_55 ;
}
else
switch ( V_358 -> V_362 ) {
case V_367 :
V_11 = - V_31 ;
break;
case V_368 :
V_11 = - V_31 ;
break;
default:
V_11 = - V_55 ;
}
if ( V_11 ) {
F_7 ( V_7 , 2 , L_115 , V_358 -> V_362 ) ;
F_7 ( V_7 , 2 , L_116 , V_358 -> V_363 ) ;
}
return V_11 ;
}
static inline int F_221 ( struct V_6 * V_7 )
{
return ( V_7 -> V_13 . type == V_202 ) ?
V_296 :
V_295 ;
}
static int F_222 ( struct V_6 * V_7 ,
struct V_108 * V_109 , unsigned long V_74 )
{
struct V_110 * V_5 = (struct V_110 * ) V_74 ;
struct V_357 * V_358 = (struct V_357 * ) V_109 -> V_369 ;
F_17 ( V_7 , 2 , L_117 ) ;
V_358 -> V_362 = V_5 -> V_78 . V_111 ;
V_358 -> V_363 = V_5 -> V_74 . V_210 . V_78 . V_111 ;
if ( ( V_358 -> V_362 == 0 ) && ( V_358 -> V_363 == 0 ) ) {
V_358 -> V_74 . V_370 =
V_5 -> V_74 . V_210 . V_74 . V_371 . V_372 ;
} else {
V_358 -> V_74 . V_370 = 0 ;
}
return 0 ;
}
static void F_155 ( struct V_6 * V_7 )
{
struct V_116 * V_117 ;
struct V_110 * V_5 ;
struct V_357 V_358 ;
F_17 ( V_7 , 2 , L_118 ) ;
V_117 = F_42 ( V_7 , F_221 ( V_7 ) , 0 ) ;
if ( ! V_117 )
return;
V_5 = (struct V_110 * ) ( V_117 -> V_74 + V_119 ) ;
V_5 -> V_74 . V_210 . V_78 . V_373 =
sizeof( struct V_374 ) +
sizeof( struct V_375 ) ;
V_5 -> V_74 . V_210 . V_78 . V_297 =
V_376 ;
V_5 -> V_74 . V_210 . V_78 . V_377 = 1 ;
V_5 -> V_74 . V_210 . V_78 . V_378 = 1 ;
if ( F_43 ( V_7 , V_117 , F_222 ,
( void * ) & V_358 ) ||
F_219 ( V_7 , & V_358 ,
V_376 ) ) {
V_7 -> V_88 . V_210 . V_209 = V_218 ;
return;
}
V_7 -> V_88 . V_210 . V_283 = V_358 . V_74 . V_370 ;
}
static int F_223 ( struct V_6 * V_7 ,
struct V_108 * V_109 , unsigned long V_74 )
{
struct V_110 * V_5 = (struct V_110 * ) V_74 ;
struct V_379 * V_336 = & V_5 -> V_74 . V_210 . V_74 . V_380 ;
struct V_357 * V_358 = (struct V_357 * ) V_109 -> V_369 ;
F_17 ( V_7 , 2 , L_119 ) ;
V_358 -> V_362 = V_5 -> V_78 . V_111 ;
V_358 -> V_363 = V_5 -> V_74 . V_210 . V_78 . V_111 ;
if ( ( V_358 -> V_362 != 0 ) || ( V_358 -> V_363 != 0 ) )
return 0 ;
if ( V_336 -> V_346 != sizeof( struct V_334 ) ) {
V_358 -> V_363 = 0xffff ;
F_7 ( V_7 , 2 , L_120 , V_336 -> V_346 ) ;
return 0 ;
}
if ( V_336 -> V_347 > 0 ) {
if ( V_358 -> V_74 . V_336 . V_209 )
* V_358 -> V_74 . V_336 . V_209 = V_336 -> V_335 [ 0 ] . V_209 ;
if ( V_358 -> V_74 . V_336 . V_138 )
* V_358 -> V_74 . V_336 . V_138 = V_336 -> V_335 [ 0 ] . V_138 ;
}
return 0 ;
}
int F_224 ( struct V_6 * V_7 ,
enum V_381 * V_209 , enum V_382 * V_138 )
{
int V_11 = 0 ;
struct V_116 * V_117 ;
struct V_110 * V_5 ;
struct V_357 V_358 = {
. V_74 = {
. V_336 = {
. V_209 = V_209 ,
. V_138 = V_138 ,
} ,
} ,
} ;
F_17 ( V_7 , 2 , L_121 ) ;
if ( ! ( V_7 -> V_88 . V_210 . V_283 & V_383 ) )
return - V_31 ;
V_117 = F_42 ( V_7 , F_221 ( V_7 ) , 0 ) ;
if ( ! V_117 )
return - V_54 ;
V_5 = (struct V_110 * ) ( V_117 -> V_74 + V_119 ) ;
V_5 -> V_74 . V_210 . V_78 . V_373 =
sizeof( struct V_374 ) ;
V_5 -> V_74 . V_210 . V_78 . V_297 =
V_383 ;
V_5 -> V_74 . V_210 . V_78 . V_377 = 1 ;
V_5 -> V_74 . V_210 . V_78 . V_378 = 1 ;
V_11 = F_43 ( V_7 , V_117 , F_223 ,
( void * ) & V_358 ) ;
if ( V_11 < 0 )
return V_11 ;
return F_219 ( V_7 , & V_358 , V_383 ) ;
}
static int F_225 ( struct V_6 * V_7 ,
struct V_108 * V_109 , unsigned long V_74 )
{
struct V_110 * V_5 = (struct V_110 * ) V_74 ;
struct V_357 * V_358 = (struct V_357 * ) V_109 -> V_369 ;
F_17 ( V_7 , 2 , L_122 ) ;
V_358 -> V_362 = V_5 -> V_78 . V_111 ;
V_358 -> V_363 = V_5 -> V_74 . V_210 . V_78 . V_111 ;
return 0 ;
}
int F_101 ( struct V_6 * V_7 , enum V_381 V_209 )
{
int V_11 = 0 ;
int V_373 ;
struct V_116 * V_117 ;
struct V_110 * V_5 ;
struct V_357 V_358 ;
enum V_359 V_360 ;
F_17 ( V_7 , 2 , L_123 ) ;
switch ( V_209 ) {
case V_218 :
V_360 = V_384 ;
V_373 = sizeof( struct V_374 ) +
sizeof( struct V_385 ) ;
break;
case V_216 :
V_360 = V_364 ;
V_373 = sizeof( struct V_374 ) +
sizeof( struct V_386 ) ;
break;
case V_217 :
V_360 = V_365 ;
V_373 = sizeof( struct V_374 ) +
sizeof( struct V_387 ) ;
break;
default:
return - V_27 ;
}
if ( ! ( V_7 -> V_88 . V_210 . V_283 & V_360 ) )
return - V_31 ;
V_117 = F_42 ( V_7 , F_221 ( V_7 ) , 0 ) ;
if ( ! V_117 )
return - V_54 ;
V_5 = (struct V_110 * ) ( V_117 -> V_74 + V_119 ) ;
V_5 -> V_74 . V_210 . V_78 . V_373 = V_373 ;
V_5 -> V_74 . V_210 . V_78 . V_297 = V_360 ;
V_5 -> V_74 . V_210 . V_78 . V_377 = 1 ;
V_5 -> V_74 . V_210 . V_78 . V_378 = 1 ;
V_11 = F_43 ( V_7 , V_117 , F_225 ,
( void * ) & V_358 ) ;
if ( V_11 < 0 )
return V_11 ;
return F_219 ( V_7 , & V_358 , V_360 ) ;
}
static int F_226 ( struct V_6 * V_7 , int V_388 , T_6 V_389 )
{
int V_11 ;
if ( V_388 == 0 )
switch ( V_389 ) {
case 0x0001 :
V_11 = 0 ;
break;
case 0x0004 :
case 0x0100 :
case 0x0106 :
V_11 = - V_31 ;
F_220 ( & V_7 -> V_198 -> V_2 ,
L_124 ) ;
break;
case 0x0107 :
V_11 = - V_390 ;
break;
default:
V_11 = - V_55 ;
}
else
V_11 = - V_55 ;
if ( V_11 ) {
F_7 ( V_7 , 2 , L_125 , V_388 ) ;
F_7 ( V_7 , 2 , L_126 , V_389 ) ;
}
return V_11 ;
}
static void F_227 ( void * V_391 ,
enum V_392 type , void * V_335 )
{
struct V_6 * V_7 = (struct V_6 * ) V_391 ;
struct V_393 * V_394 ;
T_4 V_310 ;
if ( type != V_395 ) {
F_70 ( 1 ) ;
return;
}
V_394 = (struct V_393 * ) V_335 ;
V_310 = V_321 ;
if ( V_394 -> V_314 . V_320 )
V_310 |= V_319 ;
F_213 ( V_7 , V_317 , V_310 ,
(struct V_311 * ) & V_394 -> V_396 ,
(struct V_313 * ) & V_394 -> V_314 ) ;
}
int F_228 ( struct V_6 * V_7 , int V_397 )
{
int V_11 ;
T_6 V_389 ;
struct V_398 * V_399 ;
struct V_400 V_401 ;
if ( ! V_7 )
return - V_27 ;
if ( ! V_7 -> V_88 . V_210 . V_283 )
return - V_31 ;
V_399 = F_168 ( V_7 ) ;
F_229 ( V_399 , & V_401 ) ;
if ( V_397 ) {
F_213 ( V_7 , V_329 , 0 , NULL , NULL ) ;
V_11 = F_230 ( V_401 , 1 , & V_389 ,
F_227 , V_7 ) ;
} else
V_11 = F_230 ( V_401 , 0 , & V_389 , NULL , NULL ) ;
return F_226 ( V_7 , V_11 , V_389 ) ;
}
