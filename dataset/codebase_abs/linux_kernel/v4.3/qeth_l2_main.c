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
static void F_22 ( struct V_6 * V_7 , T_2 * V_56 , int V_59 )
{
struct V_60 * V_61 ;
int V_11 ;
V_61 = F_23 ( sizeof( struct V_60 ) , V_62 ) ;
if ( ! V_61 )
return;
memcpy ( V_61 -> V_63 , V_56 , V_64 ) ;
V_61 -> V_65 = V_64 ;
V_61 -> V_66 = V_59 ;
if ( V_59 ) {
V_11 = F_15 ( V_7 ,
F_18 ( V_7 , V_56 , V_67 ) ) ;
} else {
V_11 = F_15 ( V_7 ,
F_16 ( V_7 , V_56 ) ) ;
}
if ( ! V_11 )
F_24 ( & V_61 -> V_68 , & V_7 -> V_69 ) ;
else
F_25 ( V_61 ) ;
}
static void F_26 ( struct V_6 * V_7 , int V_70 )
{
struct V_60 * V_61 , * V_71 ;
F_27 ( & V_7 -> V_72 ) ;
F_28 (mc, tmp, &card->mc_list, list) {
if ( V_70 ) {
if ( V_61 -> V_66 )
F_18 ( V_7 , V_61 -> V_63 ,
V_73 ) ;
else
F_21 ( V_7 , V_61 -> V_63 ) ;
}
F_29 ( & V_61 -> V_68 ) ;
F_25 ( V_61 ) ;
}
F_30 ( & V_7 -> V_72 ) ;
}
static inline int F_31 ( struct V_6 * V_7 ,
struct V_74 * V_75 )
{
if ( V_7 -> V_13 . type == V_14 )
return V_76 ;
if ( F_32 ( V_75 -> V_77 ) )
return V_78 ;
if ( F_33 ( V_75 -> V_77 ) )
return V_79 ;
return V_76 ;
}
static void F_34 ( struct V_6 * V_7 , struct V_80 * V_81 ,
struct V_74 * V_75 , int V_82 )
{
struct V_83 * V_84 = (struct V_83 * ) F_35 ( V_75 ) ;
memset ( V_81 , 0 , sizeof( struct V_80 ) ) ;
V_81 -> V_81 . V_85 . V_86 = V_87 ;
if ( V_82 == V_79 )
V_81 -> V_81 . V_85 . V_32 [ 2 ] |= V_88 ;
else if ( V_82 == V_78 )
V_81 -> V_81 . V_85 . V_32 [ 2 ] |= V_89 ;
else
V_81 -> V_81 . V_85 . V_32 [ 2 ] |= V_90 ;
V_81 -> V_81 . V_85 . V_91 = V_75 -> V_92 - V_93 ;
if ( V_84 -> V_94 == F_36 ( V_95 ) ) {
V_81 -> V_81 . V_85 . V_32 [ 2 ] |= V_96 ;
V_81 -> V_81 . V_85 . V_97 = F_37 ( V_84 -> V_98 ) ;
}
}
static int F_38 ( struct V_6 * V_7 ,
struct V_99 * V_100 , unsigned long V_77 )
{
struct V_101 * V_5 ;
F_17 ( V_7 , 2 , L_8 ) ;
V_5 = (struct V_101 * ) V_77 ;
if ( V_5 -> V_81 . V_102 ) {
F_19 ( 2 , L_9
L_10 , V_5 -> V_77 . V_103 . V_97 ,
F_20 ( V_7 ) , V_5 -> V_81 . V_102 ) ;
F_7 ( V_7 , 2 , L_11 , V_5 -> V_81 . V_104 ) ;
F_7 ( V_7 , 2 , L_12 , V_5 -> V_81 . V_102 ) ;
}
return 0 ;
}
static int F_39 ( struct V_6 * V_7 , T_1 V_105 ,
enum V_106 V_107 )
{
struct V_101 * V_5 ;
struct V_108 * V_109 ;
F_7 ( V_7 , 4 , L_13 , V_107 ) ;
V_109 = F_40 ( V_7 , V_107 , V_110 ) ;
if ( ! V_109 )
return - V_54 ;
V_5 = (struct V_101 * ) ( V_109 -> V_77 + V_111 ) ;
V_5 -> V_77 . V_103 . V_97 = V_105 ;
return F_41 ( V_7 , V_109 ,
F_38 , NULL ) ;
}
static void F_42 ( struct V_6 * V_7 )
{
struct V_112 * V_86 ;
F_17 ( V_7 , 3 , L_14 ) ;
F_27 ( & V_7 -> V_113 ) ;
F_10 (id, &card->vid_list, list) {
F_39 ( V_7 , V_86 -> V_114 , V_115 ) ;
}
F_30 ( & V_7 -> V_113 ) ;
}
static int F_43 ( struct V_1 * V_2 ,
T_3 V_116 , T_4 V_114 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_112 * V_86 ;
int V_11 ;
F_7 ( V_7 , 4 , L_15 , V_114 ) ;
if ( ! V_114 )
return 0 ;
if ( V_7 -> V_13 . type == V_21 ) {
F_17 ( V_7 , 3 , L_16 ) ;
return 0 ;
}
if ( F_44 ( V_7 , V_117 ) ) {
F_17 ( V_7 , 3 , L_17 ) ;
return 0 ;
}
V_86 = F_23 ( sizeof( struct V_112 ) , V_62 ) ;
if ( V_86 ) {
V_86 -> V_114 = V_114 ;
V_11 = F_39 ( V_7 , V_114 , V_115 ) ;
if ( V_11 ) {
F_25 ( V_86 ) ;
return V_11 ;
}
F_27 ( & V_7 -> V_113 ) ;
F_24 ( & V_86 -> V_68 , & V_7 -> V_118 ) ;
F_30 ( & V_7 -> V_113 ) ;
} else {
return - V_54 ;
}
return 0 ;
}
static int F_45 ( struct V_1 * V_2 ,
T_3 V_116 , T_4 V_114 )
{
struct V_112 * V_86 , * V_119 = NULL ;
struct V_6 * V_7 = V_2 -> V_8 ;
int V_11 = 0 ;
F_7 ( V_7 , 4 , L_18 , V_114 ) ;
if ( V_7 -> V_13 . type == V_21 ) {
F_17 ( V_7 , 3 , L_19 ) ;
return 0 ;
}
if ( F_44 ( V_7 , V_117 ) ) {
F_17 ( V_7 , 3 , L_20 ) ;
return 0 ;
}
F_27 ( & V_7 -> V_113 ) ;
F_10 (id, &card->vid_list, list) {
if ( V_86 -> V_114 == V_114 ) {
F_29 ( & V_86 -> V_68 ) ;
V_119 = V_86 ;
break;
}
}
F_30 ( & V_7 -> V_113 ) ;
if ( V_119 ) {
V_11 = F_39 ( V_7 , V_114 , V_120 ) ;
F_25 ( V_119 ) ;
}
F_46 ( V_7 -> V_2 ) ;
return V_11 ;
}
static void F_47 ( struct V_6 * V_7 , int V_121 )
{
F_48 ( V_122 , 2 , L_21 ) ;
F_49 ( V_122 , 2 , & V_7 , sizeof( void * ) ) ;
F_50 ( V_7 , 0 , 1 ) ;
if ( V_7 -> V_123 . V_124 == V_125 &&
V_7 -> V_126 . V_124 == V_125 &&
( V_7 -> V_124 == V_127 ) ) {
if ( V_121 &&
V_7 -> V_13 . type != V_14 ) {
F_51 ( V_7 -> V_2 ) ;
} else {
F_52 () ;
F_53 ( V_7 -> V_2 ) ;
F_54 () ;
}
V_7 -> V_13 . V_128 &= ~ V_129 ;
V_7 -> V_124 = V_130 ;
}
if ( V_7 -> V_124 == V_130 ) {
F_26 ( V_7 , 0 ) ;
F_55 ( V_7 ) ;
V_7 -> V_124 = V_131 ;
}
if ( V_7 -> V_124 == V_131 ) {
F_56 ( V_7 , 0 ) ;
F_57 ( V_7 ) ;
F_58 ( V_7 ) ;
V_7 -> V_124 = V_132 ;
}
if ( V_7 -> V_124 == V_132 ) {
F_59 ( & V_7 -> V_123 ) ;
F_59 ( & V_7 -> V_126 ) ;
}
}
static int F_60 ( struct V_6 * V_7 ,
int V_133 , int * V_134 )
{
int V_135 = 0 ;
struct V_74 * V_75 ;
struct V_80 * V_81 ;
unsigned int V_92 ;
* V_134 = 0 ;
F_61 ( ! V_133 ) ;
while ( V_133 ) {
V_75 = F_62 ( V_7 ,
& V_7 -> V_136 . V_137 -> V_138 [ V_7 -> V_139 . V_140 ] ,
& V_7 -> V_139 . V_141 , & V_7 -> V_139 . V_142 , & V_81 ) ;
if ( ! V_75 ) {
* V_134 = 1 ;
break;
}
V_75 -> V_2 = V_7 -> V_2 ;
switch ( V_81 -> V_81 . V_85 . V_86 ) {
case V_87 :
V_75 -> V_143 = V_144 ;
V_75 -> V_145 = F_63 ( V_75 , V_75 -> V_2 ) ;
V_75 -> V_146 = V_147 ;
if ( V_75 -> V_145 == F_64 ( V_148 ) )
* ( ( V_149 * ) V_75 -> V_150 ) = ++ V_7 -> V_151 . V_152 ;
V_92 = V_75 -> V_92 ;
F_65 ( V_75 ) ;
break;
case V_153 :
if ( V_7 -> V_13 . type == V_14 ) {
F_66 ( V_75 , sizeof( struct V_80 ) ) ;
F_67 ( V_75 , V_81 ,
sizeof( struct V_80 ) ) ;
V_92 = V_75 -> V_92 ;
V_7 -> V_154 . V_155 ( V_75 ) ;
break;
}
default:
F_68 ( V_75 ) ;
F_17 ( V_7 , 3 , L_22 ) ;
F_49 ( V_156 , 3 , V_81 , V_157 ) ;
continue;
}
V_135 ++ ;
V_133 -- ;
V_7 -> V_158 . V_159 ++ ;
V_7 -> V_158 . V_160 += V_92 ;
}
return V_135 ;
}
static int F_69 ( struct V_161 * V_162 , int V_133 )
{
struct V_6 * V_7 = F_70 ( V_162 , struct V_6 , V_162 ) ;
int V_135 = 0 ;
struct V_163 * V_164 ;
int V_134 ;
int V_165 = V_133 ;
if ( V_7 -> V_166 . V_167 ) {
V_7 -> V_168 . V_169 ++ ;
V_7 -> V_168 . V_170 = F_71 () ;
}
while ( 1 ) {
if ( ! V_7 -> V_139 . V_171 ) {
V_7 -> V_139 . V_172 = 0 ;
V_7 -> V_139 . V_171 = F_72 (
V_7 -> V_77 . V_173 , 0 , & V_7 -> V_139 . V_140 ,
& V_7 -> V_139 . V_172 ) ;
if ( V_7 -> V_139 . V_171 <= 0 ) {
V_7 -> V_139 . V_171 = 0 ;
break;
}
V_7 -> V_139 . V_141 =
& V_7 -> V_136 . V_137 -> V_138 [ V_7 -> V_139 . V_140 ]
. V_164 -> V_174 [ 0 ] ;
V_7 -> V_139 . V_142 = 0 ;
}
while ( V_7 -> V_139 . V_171 ) {
V_164 = & V_7 -> V_136 . V_137 -> V_138 [ V_7 -> V_139 . V_140 ] ;
if ( ! ( V_7 -> V_139 . V_172 &&
F_73 ( V_7 , V_164 -> V_164 ,
V_7 -> V_139 . V_172 , L_23 ) ) )
V_135 += F_60 (
V_7 , V_165 , & V_134 ) ;
else
V_134 = 1 ;
if ( V_134 ) {
if ( V_7 -> V_166 . V_167 )
V_7 -> V_168 . V_175 ++ ;
F_74 ( V_7 ,
V_164 -> V_176 ) ;
F_75 ( V_7 , V_7 -> V_139 . V_140 ) ;
V_7 -> V_139 . V_171 -- ;
if ( V_7 -> V_139 . V_171 ) {
V_7 -> V_139 . V_140 =
( V_7 -> V_139 . V_140 + 1 ) %
V_177 ;
V_7 -> V_139 . V_141 =
& V_7 -> V_136 . V_137
-> V_138 [ V_7 -> V_139 . V_140 ]
. V_164 -> V_174 [ 0 ] ;
V_7 -> V_139 . V_142 = 0 ;
}
}
if ( V_135 >= V_133 )
goto V_178;
else
V_165 = V_133 - V_135 ;
}
}
F_76 ( V_162 ) ;
if ( F_77 ( V_7 -> V_77 . V_173 , 0 ) )
F_78 ( & V_7 -> V_162 ) ;
V_178:
if ( V_7 -> V_166 . V_167 )
V_7 -> V_168 . V_179 += F_71 () -
V_7 -> V_168 . V_170 ;
return V_135 ;
}
static int F_18 ( struct V_6 * V_7 , T_2 * V_56 ,
enum V_106 V_107 )
{
struct V_101 * V_5 ;
struct V_108 * V_109 ;
F_17 ( V_7 , 2 , L_24 ) ;
V_109 = F_40 ( V_7 , V_107 , V_110 ) ;
if ( ! V_109 )
return - V_54 ;
V_5 = (struct V_101 * ) ( V_109 -> V_77 + V_111 ) ;
V_5 -> V_77 . V_180 . V_181 = V_64 ;
memcpy ( & V_5 -> V_77 . V_180 . V_56 , V_56 , V_64 ) ;
return F_41 ( V_7 , V_109 , NULL , NULL ) ;
}
static int F_79 ( struct V_6 * V_7 , T_2 * V_56 )
{
int V_11 ;
F_17 ( V_7 , 2 , L_25 ) ;
V_11 = F_15 ( V_7 , F_18 ( V_7 , V_56 ,
V_67 ) ) ;
if ( V_11 == 0 ) {
V_7 -> V_13 . V_128 |= V_129 ;
memcpy ( V_7 -> V_2 -> V_182 , V_56 , V_64 ) ;
F_80 ( & V_7 -> V_183 -> V_2 ,
L_26 ,
V_7 -> V_2 -> V_182 , V_7 -> V_2 -> V_184 ) ;
} else {
V_7 -> V_13 . V_128 &= ~ V_129 ;
switch ( V_11 ) {
case - V_49 :
F_81 ( & V_7 -> V_183 -> V_2 ,
L_27 , V_56 ) ;
break;
case - V_15 :
F_81 ( & V_7 -> V_183 -> V_2 ,
L_28 , V_56 ) ;
break;
}
}
return V_11 ;
}
static int F_82 ( struct V_6 * V_7 , T_2 * V_56 )
{
int V_11 ;
F_17 ( V_7 , 2 , L_29 ) ;
if ( ! ( V_7 -> V_13 . V_128 & V_129 ) )
return 0 ;
V_11 = F_15 ( V_7 , F_18 ( V_7 , V_56 ,
V_73 ) ) ;
if ( V_11 == 0 )
V_7 -> V_13 . V_128 &= ~ V_129 ;
return V_11 ;
}
static int F_83 ( struct V_6 * V_7 )
{
int V_11 = 0 ;
char V_185 [] = { 0x02 , 0x00 , 0x00 } ;
F_48 ( V_122 , 2 , L_30 ) ;
F_84 ( V_122 , 2 , L_31 , F_85 ( V_7 ) ) ;
if ( F_86 ( V_7 , V_186 ) ) {
V_11 = F_87 ( V_7 ) ;
if ( V_11 ) {
F_19 ( 2 , L_32
L_33 ,
F_85 ( V_7 ) , V_11 ) ;
}
}
if ( V_7 -> V_13 . type == V_187 ||
V_7 -> V_13 . type == V_21 ||
V_7 -> V_13 . type == V_22 ||
V_7 -> V_13 . V_23 ) {
V_11 = F_88 ( V_7 ) ;
if ( V_11 ) {
F_19 ( 2 , L_34
L_35 , F_85 ( V_7 ) , V_11 ) ;
F_84 ( V_122 , 2 , L_36 , V_11 ) ;
return V_11 ;
}
F_49 ( V_122 , 2 , V_7 -> V_2 -> V_182 , V_64 ) ;
} else {
F_89 ( V_7 -> V_2 -> V_182 ) ;
memcpy ( V_7 -> V_2 -> V_182 , V_185 , 3 ) ;
}
return 0 ;
}
static int F_90 ( struct V_1 * V_2 , void * V_188 )
{
struct V_189 * V_190 = V_188 ;
struct V_6 * V_7 = V_2 -> V_8 ;
int V_11 = 0 ;
F_17 ( V_7 , 3 , L_37 ) ;
if ( F_8 ( V_2 ) != V_35 ) {
F_17 ( V_7 , 3 , L_38 ) ;
return - V_31 ;
}
if ( V_7 -> V_13 . type == V_14 ||
V_7 -> V_13 . type == V_21 ||
V_7 -> V_13 . type == V_22 ) {
F_17 ( V_7 , 3 , L_39 ) ;
return - V_31 ;
}
F_91 ( V_7 , 3 , V_190 -> V_191 , V_64 ) ;
if ( F_44 ( V_7 , V_117 ) ) {
F_17 ( V_7 , 3 , L_40 ) ;
return - V_192 ;
}
V_11 = F_82 ( V_7 , & V_7 -> V_2 -> V_182 [ 0 ] ) ;
if ( ! V_11 || ( V_11 == - V_53 ) )
V_11 = F_79 ( V_7 , V_190 -> V_191 ) ;
return V_11 ? - V_27 : 0 ;
}
static void F_92 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
enum V_193 V_194 ;
int V_195 ;
int V_11 ;
F_17 ( V_7 , 3 , L_41 ) ;
if ( ! V_7 -> V_166 . V_196 . V_197 )
return;
V_194 = ( V_2 -> V_32 & V_198 ) ? V_199
: V_200 ;
if ( V_194 == V_7 -> V_13 . V_194 )
return;
if ( V_194 == V_199 ) {
if ( V_7 -> V_166 . V_196 . V_201 )
V_195 = V_202 ;
else
V_195 = V_203 ;
} else
V_195 = V_204 ;
V_11 = F_93 ( V_7 , V_195 ) ;
F_84 ( V_122 , 2 , L_42 ,
( V_194 == V_199 ) ? '+' : '-' , V_11 ) ;
if ( ! V_11 ) {
V_7 -> V_166 . V_196 . V_195 = V_195 ;
V_7 -> V_13 . V_194 = V_194 ;
}
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_205 * V_206 ;
if ( V_7 -> V_13 . type == V_14 )
return ;
F_17 ( V_7 , 3 , L_43 ) ;
if ( F_94 ( V_7 , V_117 ) &&
( V_7 -> V_124 != V_127 ) )
return;
F_26 ( V_7 , 1 ) ;
F_27 ( & V_7 -> V_72 ) ;
F_95 (ha, dev)
F_22 ( V_7 , V_206 -> V_190 , 0 ) ;
F_96 (ha, dev)
F_22 ( V_7 , V_206 -> V_190 , 1 ) ;
F_30 ( & V_7 -> V_72 ) ;
if ( F_97 ( V_7 , V_207 ) )
F_98 ( V_7 ) ;
else
F_92 ( V_7 ) ;
}
static int F_99 ( struct V_74 * V_75 , struct V_1 * V_2 )
{
int V_11 ;
struct V_80 * V_81 = NULL ;
int V_208 = 0 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_74 * V_209 = V_75 ;
int V_82 = F_31 ( V_7 , V_75 ) ;
struct V_210 * V_211 ;
int V_212 = V_75 -> V_92 ;
int V_213 = - 1 ;
int V_214 = 0 ;
int V_215 = 0 ;
if ( V_7 -> V_136 . V_216 || ( V_82 &&
V_7 -> V_13 . V_217 ) )
V_211 = V_7 -> V_136 . V_218 [ F_100 ( V_7 , V_75 ,
F_101 ( V_75 ) , V_82 ) ] ;
else
V_211 = V_7 -> V_136 . V_218 [ V_7 -> V_136 . V_219 ] ;
if ( ( V_7 -> V_124 != V_127 ) || ! V_7 -> V_220 ) {
V_7 -> V_158 . V_221 ++ ;
goto V_222;
}
if ( ( V_7 -> V_13 . type == V_14 ) &&
( V_75 -> V_145 == F_64 ( V_223 ) ) )
goto V_222;
if ( V_7 -> V_166 . V_167 ) {
V_7 -> V_168 . V_224 ++ ;
V_7 -> V_168 . V_225 = F_71 () ;
}
F_102 ( V_2 ) ;
if ( V_7 -> V_13 . type == V_14 )
V_81 = (struct V_80 * ) V_75 -> V_77 ;
else {
if ( V_7 -> V_13 . type == V_187 ) {
V_209 = V_75 ;
V_213 = V_226 ;
V_215 = V_226 ;
V_81 = F_103 ( V_227 ,
V_62 ) ;
if ( ! V_81 )
goto V_222;
V_214 ++ ;
F_104 ( V_209 ) ;
F_34 ( V_7 , V_81 , V_209 , V_82 ) ;
V_81 -> V_81 . V_85 . V_91 = V_209 -> V_92 ;
memcpy ( ( ( char * ) V_81 ) + sizeof( struct V_80 ) ,
F_35 ( V_209 ) , V_226 ) ;
} else {
V_209 = F_105 ( V_75 ,
sizeof( struct V_80 ) ) ;
if ( ! V_209 )
goto V_222;
V_81 = (struct V_80 * ) F_66 ( V_209 ,
sizeof( struct V_80 ) ) ;
F_106 ( V_209 , sizeof( struct V_80 ) ) ;
F_34 ( V_7 , V_81 , V_209 , V_82 ) ;
}
}
V_208 = F_107 ( V_7 , V_209 , V_214 ) ;
if ( ! V_208 ) {
if ( V_213 >= 0 )
F_108 ( V_227 , V_81 ) ;
goto V_222;
}
if ( V_7 -> V_13 . type != V_187 ) {
if ( F_109 ( V_209 , & V_81 ,
sizeof( struct V_228 ) ) )
goto V_222;
V_11 = F_110 ( V_7 , V_211 , V_209 , V_81 ,
V_208 ) ;
} else
V_11 = F_111 ( V_7 , V_211 , V_209 , V_81 ,
V_208 , V_213 , V_215 ) ;
if ( ! V_11 ) {
V_7 -> V_158 . V_229 ++ ;
V_7 -> V_158 . V_212 += V_212 ;
if ( V_209 != V_75 )
F_68 ( V_75 ) ;
V_11 = V_230 ;
} else {
if ( V_213 >= 0 )
F_108 ( V_227 , V_81 ) ;
if ( V_11 == - V_231 ) {
if ( V_209 != V_75 )
F_68 ( V_209 ) ;
return V_232 ;
} else
goto V_222;
}
F_112 ( V_2 ) ;
if ( V_7 -> V_166 . V_167 )
V_7 -> V_168 . V_233 += F_71 () -
V_7 -> V_168 . V_225 ;
return V_11 ;
V_222:
V_7 -> V_158 . V_234 ++ ;
V_7 -> V_158 . V_235 ++ ;
if ( ( V_209 != V_75 ) && V_209 )
F_68 ( V_209 ) ;
F_68 ( V_75 ) ;
F_112 ( V_2 ) ;
return V_230 ;
}
static int F_113 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_11 = 0 ;
F_17 ( V_7 , 4 , L_44 ) ;
if ( V_7 -> V_124 == V_127 )
return V_11 ;
if ( V_7 -> V_124 != V_130 )
return - V_12 ;
if ( ( V_7 -> V_13 . type != V_14 ) &&
( ! ( V_7 -> V_13 . V_128 & V_129 ) ) ) {
F_17 ( V_7 , 4 , L_45 ) ;
return - V_15 ;
}
V_7 -> V_77 . V_124 = V_125 ;
V_7 -> V_124 = V_127 ;
F_114 ( V_2 ) ;
if ( F_115 ( V_7 -> V_77 . V_173 , 0 ) >= 0 ) {
F_116 ( & V_7 -> V_162 ) ;
F_78 ( & V_7 -> V_162 ) ;
} else
V_11 = - V_55 ;
return V_11 ;
}
static int F_117 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_17 ( V_7 , 5 , L_46 ) ;
if ( F_44 ( V_7 , V_117 ) ) {
F_17 ( V_7 , 3 , L_47 ) ;
return - V_192 ;
}
return F_113 ( V_2 ) ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_17 ( V_7 , 4 , L_48 ) ;
F_118 ( V_2 ) ;
if ( V_7 -> V_124 == V_127 ) {
V_7 -> V_124 = V_130 ;
F_119 ( & V_7 -> V_162 ) ;
}
return 0 ;
}
static int F_120 ( struct V_236 * V_183 )
{
struct V_6 * V_7 = F_121 ( & V_183 -> V_2 ) ;
F_122 ( & V_183 -> V_2 ) ;
F_123 ( & V_7 -> V_118 ) ;
F_123 ( & V_7 -> V_69 ) ;
V_7 -> V_166 . V_237 = 1 ;
V_7 -> V_13 . V_238 = 0 ;
return 0 ;
}
static void F_124 ( struct V_236 * V_239 )
{
struct V_6 * V_7 = F_121 ( & V_239 -> V_2 ) ;
F_125 ( & V_239 -> V_2 ) ;
F_50 ( V_7 , 0 , 1 ) ;
F_126 ( V_7 -> V_240 , F_94 ( V_7 , 0xffffffff ) == 0 ) ;
if ( V_239 -> V_124 == V_241 )
F_127 ( V_239 ) ;
if ( V_7 -> V_2 ) {
F_128 ( V_7 -> V_2 ) ;
V_7 -> V_2 = NULL ;
}
return;
}
static int F_129 ( struct V_6 * V_7 )
{
switch ( V_7 -> V_13 . type ) {
case V_187 :
V_7 -> V_2 = F_130 ( 0 , L_49 , V_242 ,
V_243 ) ;
break;
case V_14 :
V_7 -> V_2 = F_130 ( 0 , L_50 , V_242 ,
V_243 ) ;
V_7 -> V_2 -> V_32 |= V_244 ;
break;
default:
V_7 -> V_2 = F_131 ( 0 ) ;
}
if ( ! V_7 -> V_2 )
return - V_12 ;
V_7 -> V_2 -> V_8 = V_7 ;
V_7 -> V_2 -> V_245 = V_246 ;
V_7 -> V_2 -> V_247 = V_7 -> V_13 . V_248 ;
V_7 -> V_2 -> V_249 = & V_250 ;
V_7 -> V_2 -> V_251 =
( V_7 -> V_13 . type != V_14 ) ?
& V_252 : & V_253 ;
V_7 -> V_2 -> V_254 |= V_255 ;
V_7 -> V_13 . V_256 = 1 ;
F_83 ( V_7 ) ;
F_132 ( V_7 -> V_2 , & V_7 -> V_183 -> V_2 ) ;
F_133 ( V_7 -> V_2 , & V_7 -> V_162 , F_69 , V_257 ) ;
return F_134 ( V_7 -> V_2 ) ;
}
static int F_135 ( struct V_236 * V_183 , int V_121 )
{
struct V_6 * V_7 = F_121 ( & V_183 -> V_2 ) ;
int V_11 = 0 ;
enum V_258 V_259 ;
F_136 ( & V_7 -> V_260 ) ;
F_136 ( & V_7 -> V_261 ) ;
F_48 ( V_122 , 2 , L_51 ) ;
F_49 ( V_122 , 2 , & V_7 , sizeof( void * ) ) ;
V_259 = V_7 -> V_124 ;
V_11 = F_137 ( V_7 ) ;
if ( V_11 ) {
F_84 ( V_122 , 2 , L_52 , V_11 ) ;
V_11 = - V_12 ;
goto V_262;
}
F_138 ( V_7 ) ;
if ( V_7 -> V_166 . V_196 . V_263 )
F_80 ( & V_7 -> V_183 -> V_2 ,
L_53 ) ;
F_139 ( V_7 ) ;
if ( ! V_7 -> V_2 && F_129 ( V_7 ) ) {
V_11 = - V_12 ;
goto V_262;
}
if ( V_7 -> V_13 . type != V_14 )
F_79 ( V_7 , & V_7 -> V_2 -> V_182 [ 0 ] ) ;
if ( F_140 ( V_7 , V_264 ) ) {
if ( V_7 -> V_13 . V_238 &&
F_141 ( V_7 , V_265 ) )
V_7 -> V_13 . V_238 = 0 ;
} else
V_7 -> V_13 . V_238 = 0 ;
F_142 ( V_7 ) ;
V_7 -> V_124 = V_131 ;
memset ( & V_7 -> V_139 , 0 , sizeof( struct V_266 ) ) ;
F_143 ( V_7 ) ;
F_48 ( V_122 , 2 , L_54 ) ;
V_11 = F_144 ( V_7 ) ;
if ( V_11 ) {
F_84 ( V_122 , 2 , L_55 , V_11 ) ;
if ( V_11 == 0xe080 ) {
F_81 ( & V_7 -> V_183 -> V_2 ,
L_56 ) ;
V_7 -> V_220 = 0 ;
goto V_267;
}
V_11 = - V_12 ;
goto V_262;
} else
V_7 -> V_220 = 1 ;
V_267:
if ( ( V_7 -> V_13 . type == V_20 ) ||
( V_7 -> V_13 . type == V_22 ) ) {
V_11 = F_145 ( V_7 , 0 ) ;
if ( V_11 ) {
V_11 = - V_12 ;
goto V_262;
}
}
if ( V_7 -> V_13 . type != V_14 &&
V_7 -> V_13 . type != V_21 )
F_42 ( V_7 ) ;
F_118 ( V_7 -> V_2 ) ;
V_11 = F_146 ( V_7 ) ;
if ( V_11 ) {
F_84 ( V_122 , 2 , L_57 , V_11 ) ;
V_11 = - V_12 ;
goto V_262;
}
V_7 -> V_124 = V_130 ;
if ( V_7 -> V_220 )
F_147 ( V_7 -> V_2 ) ;
else
F_148 ( V_7 -> V_2 ) ;
F_50 ( V_7 , 0xffffffff , 0 ) ;
if ( V_259 == V_268 ) {
if ( V_121 &&
V_7 -> V_13 . type != V_14 ) {
F_113 ( V_7 -> V_2 ) ;
} else {
F_52 () ;
F_149 ( V_7 -> V_2 ) ;
F_54 () ;
}
F_46 ( V_7 -> V_2 ) ;
}
F_150 ( & V_183 -> V_2 . V_269 , V_270 ) ;
F_151 ( & V_7 -> V_261 ) ;
F_151 ( & V_7 -> V_260 ) ;
return 0 ;
V_262:
F_47 ( V_7 , 0 ) ;
F_152 ( F_153 ( V_7 ) ) ;
F_152 ( F_154 ( V_7 ) ) ;
F_152 ( F_14 ( V_7 ) ) ;
F_155 ( F_153 ( V_7 ) ) ;
if ( V_259 == V_268 )
V_7 -> V_124 = V_268 ;
else
V_7 -> V_124 = V_132 ;
F_151 ( & V_7 -> V_261 ) ;
F_151 ( & V_7 -> V_260 ) ;
return V_11 ;
}
static int F_156 ( struct V_236 * V_183 )
{
return F_135 ( V_183 , 0 ) ;
}
static int F_157 ( struct V_236 * V_239 ,
int V_121 )
{
struct V_6 * V_7 = F_121 ( & V_239 -> V_2 ) ;
int V_11 = 0 , V_271 = 0 , V_272 = 0 ;
enum V_258 V_259 ;
F_136 ( & V_7 -> V_260 ) ;
F_136 ( & V_7 -> V_261 ) ;
F_48 ( V_122 , 3 , L_58 ) ;
F_49 ( V_122 , 3 , & V_7 , sizeof( void * ) ) ;
if ( V_7 -> V_2 && F_158 ( V_7 -> V_2 ) )
F_148 ( V_7 -> V_2 ) ;
V_259 = V_7 -> V_124 ;
if ( ( ! V_121 && V_7 -> V_13 . V_238 ) || V_7 -> V_13 . V_238 == 2 ) {
F_141 ( V_7 , V_273 ) ;
V_7 -> V_13 . V_238 = 1 ;
}
F_47 ( V_7 , V_121 ) ;
V_11 = F_152 ( F_153 ( V_7 ) ) ;
V_271 = F_152 ( F_154 ( V_7 ) ) ;
V_272 = F_152 ( F_14 ( V_7 ) ) ;
if ( ! V_11 )
V_11 = ( V_271 ) ? V_271 : V_272 ;
if ( V_11 )
F_84 ( V_122 , 2 , L_55 , V_11 ) ;
F_155 ( F_153 ( V_7 ) ) ;
if ( V_259 == V_127 )
V_7 -> V_124 = V_268 ;
F_150 ( & V_239 -> V_2 . V_269 , V_270 ) ;
F_151 ( & V_7 -> V_261 ) ;
F_151 ( & V_7 -> V_260 ) ;
return 0 ;
}
static int F_127 ( struct V_236 * V_239 )
{
return F_157 ( V_239 , 0 ) ;
}
static int F_159 ( void * V_274 )
{
struct V_6 * V_7 ;
int V_11 = 0 ;
V_7 = (struct V_6 * ) V_274 ;
F_17 ( V_7 , 2 , L_59 ) ;
if ( ! F_160 ( V_7 , V_117 ) )
return 0 ;
F_17 ( V_7 , 2 , L_60 ) ;
F_81 ( & V_7 -> V_183 -> V_2 ,
L_61 ) ;
F_161 ( V_7 ) ;
F_157 ( V_7 -> V_183 , 1 ) ;
V_11 = F_135 ( V_7 -> V_183 , 1 ) ;
if ( ! V_11 )
F_80 ( & V_7 -> V_183 -> V_2 ,
L_62 ) ;
else {
F_162 ( V_7 ) ;
F_81 ( & V_7 -> V_183 -> V_2 , L_63
L_64 ) ;
}
F_163 ( V_7 ) ;
F_164 ( V_7 , V_117 ) ;
F_165 ( V_7 , V_117 ) ;
return 0 ;
}
static int T_5 F_166 ( void )
{
F_167 ( L_65 ) ;
return 0 ;
}
static void T_6 F_168 ( void )
{
F_167 ( L_66 ) ;
}
static void F_169 ( struct V_236 * V_183 )
{
struct V_6 * V_7 = F_121 ( & V_183 -> V_2 ) ;
F_50 ( V_7 , 0 , 1 ) ;
if ( ( V_183 -> V_124 == V_241 ) && V_7 -> V_13 . V_238 )
F_141 ( V_7 , V_273 ) ;
F_56 ( V_7 , 0 ) ;
F_57 ( V_7 ) ;
F_155 ( F_153 ( V_7 ) ) ;
}
static int F_170 ( struct V_236 * V_183 )
{
struct V_6 * V_7 = F_121 ( & V_183 -> V_2 ) ;
if ( V_7 -> V_2 )
F_171 ( V_7 -> V_2 ) ;
F_50 ( V_7 , 0 , 1 ) ;
F_126 ( V_7 -> V_240 , F_94 ( V_7 , 0xffffffff ) == 0 ) ;
if ( V_183 -> V_124 == V_275 )
return 0 ;
if ( V_7 -> V_124 == V_127 ) {
if ( V_7 -> V_13 . V_238 )
F_141 ( V_7 , V_273 ) ;
F_157 ( V_7 -> V_183 , 1 ) ;
} else
F_157 ( V_7 -> V_183 , 0 ) ;
return 0 ;
}
static int F_172 ( struct V_236 * V_183 )
{
struct V_6 * V_7 = F_121 ( & V_183 -> V_2 ) ;
int V_11 = 0 ;
if ( V_183 -> V_124 == V_275 )
goto V_178;
if ( V_7 -> V_124 == V_268 ) {
V_11 = F_135 ( V_7 -> V_183 , 1 ) ;
if ( V_11 ) {
F_52 () ;
F_53 ( V_7 -> V_2 ) ;
F_54 () ;
}
} else
V_11 = F_135 ( V_7 -> V_183 , 0 ) ;
V_178:
F_50 ( V_7 , 0xffffffff , 0 ) ;
if ( V_7 -> V_2 )
F_173 ( V_7 -> V_2 ) ;
if ( V_11 )
F_81 ( & V_7 -> V_183 -> V_2 , L_63
L_64 ) ;
return V_11 ;
}
static int F_174 ( struct V_6 * V_7 ,
struct V_101 * V_5 )
{
switch ( V_5 -> V_81 . V_104 ) {
case V_276 :
case V_277 :
if ( V_5 -> V_77 . V_196 . V_81 . V_278 ==
V_279 ) {
F_175 ( V_7 , V_5 ) ;
return 0 ;
} else
return 1 ;
case V_280 :
F_176 ( V_7 , V_5 ) ;
return 0 ;
default:
return 1 ;
}
}
static int F_177 ( struct V_6 * V_7 , int V_92 ,
struct V_108 * V_109 )
{
unsigned long V_32 ;
int V_11 = 0 ;
F_17 ( V_7 , 5 , L_67 ) ;
F_126 ( V_7 -> V_240 ,
F_178 ( & V_7 -> V_126 . V_281 , 0 , 1 ) == 0 ) ;
F_179 ( V_7 , V_92 , V_109 ) ;
F_17 ( V_7 , 6 , L_68 ) ;
F_180 ( F_181 ( V_7 -> V_126 . V_173 ) , V_32 ) ;
V_11 = F_182 ( V_7 -> V_126 . V_173 , & V_7 -> V_126 . V_282 ,
( V_283 ) V_109 , 0 , 0 ) ;
F_183 ( F_181 ( V_7 -> V_126 . V_173 ) , V_32 ) ;
if ( V_11 ) {
F_19 ( 2 , L_69
L_70 , V_11 ) ;
F_7 ( V_7 , 2 , L_71 , V_11 ) ;
F_184 ( V_109 -> V_284 , V_109 ) ;
F_185 ( & V_7 -> V_126 . V_281 , 0 ) ;
F_186 ( & V_7 -> V_240 ) ;
}
return V_11 ;
}
static int F_187 ( struct V_6 * V_7 ,
struct V_108 * V_109 , int V_285 )
{
T_4 V_286 , V_287 ;
F_17 ( V_7 , 4 , L_72 ) ;
F_188 ( V_7 , V_109 , V_288 ) ;
V_286 = ( T_4 ) ( V_111 + V_285 ) ;
V_287 = ( T_4 ) V_285 ;
memcpy ( F_189 ( V_109 -> V_77 ) , & V_286 , 2 ) ;
memcpy ( F_190 ( V_109 -> V_77 ) , & V_287 , 2 ) ;
memcpy ( F_191 ( V_109 -> V_77 ) , & V_287 , 2 ) ;
memcpy ( F_192 ( V_109 -> V_77 ) , & V_287 , 2 ) ;
return F_177 ( V_7 , V_286 , V_109 ) ;
}
int F_193 ( struct V_1 * V_2 , void * V_77 , int V_285 )
{
struct V_108 * V_109 ;
struct V_6 * V_7 ;
int V_11 ;
if ( ! V_2 )
return - V_12 ;
V_7 = V_2 -> V_8 ;
if ( ! V_7 )
return - V_12 ;
F_17 ( V_7 , 2 , L_73 ) ;
if ( ! F_2 ( V_7 ) )
return - V_12 ;
V_109 = F_194 ( & V_7 -> V_126 ) ;
memcpy ( V_109 -> V_77 + V_111 , V_77 , V_285 ) ;
V_11 = F_187 ( V_7 , V_109 , V_285 ) ;
return V_11 ;
}
int F_195 ( unsigned char * V_36 , struct V_1 * * V_2 ,
int (* F_196)( struct V_1 * , void * ) ,
int (* V_155)( struct V_74 * ) )
{
struct V_6 * V_7 ;
* V_2 = F_12 ( V_36 ) ;
if ( * V_2 == NULL )
return - V_12 ;
V_7 = ( * V_2 ) -> V_8 ;
if ( ! V_7 )
return - V_12 ;
F_17 ( V_7 , 2 , L_74 ) ;
if ( ( F_196 == NULL ) || ( V_155 == NULL ) )
return - V_27 ;
V_7 -> V_154 . F_196 = F_196 ;
V_7 -> V_154 . V_155 = V_155 ;
return 0 ;
}
void F_197 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
if ( ! V_2 )
return;
V_7 = V_2 -> V_8 ;
if ( ! V_7 )
return;
F_17 ( V_7 , 2 , L_75 ) ;
V_7 -> V_154 . F_196 = NULL ;
V_7 -> V_154 . V_155 = NULL ;
return;
}
static void F_198 ( struct V_6 * V_7 ,
enum V_289 V_290 ,
T_7 V_291 , struct V_292 * V_293 , struct V_294 * V_295 )
{
char V_296 [ 7 ] [ 32 ] ;
char * V_297 [ 8 ] ;
int V_105 = 0 ;
switch ( V_290 ) {
case V_298 :
snprintf ( V_296 [ V_105 ] , sizeof( V_296 [ V_105 ] ) , L_76 ,
( V_291 & V_299 )
? L_77 : L_78 ) ;
V_297 [ V_105 ] = V_296 [ V_105 ] ; V_105 ++ ;
if ( V_291 & V_300 ) {
snprintf ( V_296 [ V_105 ] , sizeof( V_296 [ V_105 ] ) , L_79 ,
V_295 -> V_301 ) ;
V_297 [ V_105 ] = V_296 [ V_105 ] ; V_105 ++ ;
}
if ( V_291 & V_302 ) {
snprintf ( V_296 [ V_105 ] , sizeof( V_296 [ V_105 ] ) , L_80 ,
& V_295 -> V_56 ) ;
V_297 [ V_105 ] = V_296 [ V_105 ] ; V_105 ++ ;
}
snprintf ( V_296 [ V_105 ] , sizeof( V_296 [ V_105 ] ) , L_81 ,
V_293 -> V_303 , V_293 -> V_304 , V_293 -> V_305 ) ;
V_297 [ V_105 ] = V_296 [ V_105 ] ; V_105 ++ ;
snprintf ( V_296 [ V_105 ] , sizeof( V_296 [ V_105 ] ) , L_82 , V_293 -> V_306 ) ;
V_297 [ V_105 ] = V_296 [ V_105 ] ; V_105 ++ ;
snprintf ( V_296 [ V_105 ] , sizeof( V_296 [ V_105 ] ) , L_83 ,
V_293 -> V_307 ) ;
V_297 [ V_105 ] = V_296 [ V_105 ] ; V_105 ++ ;
snprintf ( V_296 [ V_105 ] , sizeof( V_296 [ V_105 ] ) , L_84 , V_293 -> V_308 ) ;
V_297 [ V_105 ] = V_296 [ V_105 ] ; V_105 ++ ;
break;
case V_309 :
snprintf ( V_296 [ V_105 ] , sizeof( V_296 [ V_105 ] ) , L_85 ) ;
V_297 [ V_105 ] = V_296 [ V_105 ] ; V_105 ++ ;
break;
case V_310 :
snprintf ( V_296 [ V_105 ] , sizeof( V_296 [ V_105 ] ) , L_86 ) ;
V_297 [ V_105 ] = V_296 [ V_105 ] ; V_105 ++ ;
break;
}
V_297 [ V_105 ] = NULL ;
F_199 ( & V_7 -> V_183 -> V_2 . V_269 , V_270 , V_297 ) ;
}
static void F_200 ( struct V_311 * V_312 )
{
struct V_313 * V_77 =
F_70 ( V_312 , struct V_313 , V_314 ) ;
struct V_315 * V_316 = & V_77 -> V_317 . V_316 [ 0 ] ;
char V_318 [ 32 ] ;
char V_319 [ 32 ] ;
char V_320 [ 32 ] ;
char * V_297 [] = {
V_318 ,
V_319 ,
V_320 ,
NULL
} ;
F_136 ( & V_77 -> V_7 -> V_261 ) ;
V_77 -> V_7 -> V_166 . V_196 . V_195 = V_316 -> V_195 ;
F_151 ( & V_77 -> V_7 -> V_261 ) ;
snprintf ( V_318 , sizeof( V_318 ) , L_87 ) ;
snprintf ( V_319 , sizeof( V_319 ) , L_88 ,
( V_316 -> V_195 == V_204 ) ? L_89 :
( V_316 -> V_195 == V_202 ) ? L_90 :
( V_316 -> V_195 == V_203 ) ? L_91 :
L_92 ) ;
snprintf ( V_320 , sizeof( V_320 ) , L_93 ,
( V_316 -> V_124 == V_321 ) ? L_94 :
( V_316 -> V_124 == V_322 ) ? L_95 :
( V_316 -> V_124 == V_323 ) ? L_96 :
L_92 ) ;
F_199 ( & V_77 -> V_7 -> V_183 -> V_2 . V_269 ,
V_270 , V_297 ) ;
F_25 ( V_77 ) ;
}
static void F_175 ( struct V_6 * V_7 ,
struct V_101 * V_5 )
{
struct V_324 * V_317 =
& V_5 -> V_77 . V_196 . V_77 . V_325 ;
struct V_313 * V_77 ;
int V_326 ;
F_17 ( V_7 , 2 , L_97 ) ;
if ( V_317 -> V_327 != sizeof( struct V_315 ) ) {
F_7 ( V_7 , 2 , L_98 , V_317 -> V_327 ) ;
return;
}
V_326 = sizeof( struct V_315 ) * V_317 -> V_328 ;
V_77 = F_201 ( sizeof( struct V_313 ) + V_326 ,
V_62 ) ;
if ( ! V_77 ) {
F_17 ( V_7 , 2 , L_99 ) ;
return;
}
F_202 ( & V_77 -> V_314 , F_200 ) ;
V_77 -> V_7 = V_7 ;
memcpy ( & V_77 -> V_317 , V_317 ,
sizeof( struct V_324 ) + V_326 ) ;
F_203 ( V_329 , & V_77 -> V_314 ) ;
}
static void F_204 ( struct V_311 * V_312 )
{
struct V_330 * V_77 =
F_70 ( V_312 , struct V_330 , V_314 ) ;
int V_105 ;
if ( V_77 -> V_331 . V_332 ) {
F_80 ( & V_77 -> V_7 -> V_183 -> V_2 ,
L_100 ,
V_77 -> V_7 -> V_2 -> V_184 ,
( V_77 -> V_331 . V_332 == 0x01 )
? L_101
: ( V_77 -> V_331 . V_332 == 0x02 )
? L_102
: L_103 ) ;
F_136 ( & V_77 -> V_7 -> V_261 ) ;
V_77 -> V_7 -> V_166 . V_196 . V_333 = 0 ;
F_151 ( & V_77 -> V_7 -> V_261 ) ;
F_198 ( V_77 -> V_7 , V_309 ,
0 , NULL , NULL ) ;
} else
for ( V_105 = 0 ; V_105 < V_77 -> V_331 . V_328 ; V_105 ++ ) {
struct V_334 * V_316 =
& V_77 -> V_331 . V_316 [ V_105 ] ;
F_198 ( V_77 -> V_7 ,
V_298 ,
V_316 -> V_335 ,
& V_316 -> V_293 , & V_316 -> V_295 ) ;
}
F_25 ( V_77 ) ;
}
static void F_176 ( struct V_6 * V_7 ,
struct V_101 * V_5 )
{
struct V_336 * V_331 =
& V_5 -> V_77 . V_337 ;
struct V_330 * V_77 ;
int V_326 ;
F_17 ( V_7 , 2 , L_104 ) ;
if ( V_5 -> V_81 . V_102 != 0x0000 ) {
if ( V_5 -> V_81 . V_102 == 0x0010 ) {
if ( V_331 -> V_332 == 0x00 )
V_331 -> V_332 = 0xff ;
} else {
F_7 ( V_7 , 2 , L_105 ,
V_5 -> V_81 . V_102 ) ;
return;
}
}
V_326 = sizeof( struct V_334 ) *
V_331 -> V_328 ;
V_77 = F_201 ( sizeof( struct V_330 ) + V_326 ,
V_62 ) ;
if ( ! V_77 ) {
F_17 ( V_7 , 2 , L_106 ) ;
return;
}
F_202 ( & V_77 -> V_314 , F_204 ) ;
V_77 -> V_7 = V_7 ;
memcpy ( & V_77 -> V_331 , V_331 ,
sizeof( struct V_336 ) + V_326 ) ;
F_203 ( V_329 , & V_77 -> V_314 ) ;
}
static int F_205 ( struct V_6 * V_7 ,
struct V_338 * V_339 , enum V_340 V_341 )
{
int V_11 ;
int V_342 = ( V_7 -> V_13 . type == V_187 ) ;
if ( ( V_342 && ( V_339 -> V_343 == V_43 ) ) ||
( ! V_342 && ( V_339 -> V_343 == V_339 -> V_344 ) ) )
switch ( V_339 -> V_344 ) {
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
F_206 ( & V_7 -> V_183 -> V_2 ,
L_107 ) ;
break;
case 0x2B14 :
case 0x0014 :
switch ( V_341 ) {
case V_345 :
V_11 = - V_49 ;
F_206 ( & V_7 -> V_183 -> V_2 ,
L_108 ) ;
break;
case V_346 :
V_11 = - V_231 ;
F_206 ( & V_7 -> V_183 -> V_2 ,
L_109 ) ;
break;
default:
V_11 = - V_55 ;
}
break;
case 0x2B18 :
case 0x0018 :
V_11 = - V_231 ;
F_206 ( & V_7 -> V_183 -> V_2 ,
L_110 ) ;
break;
case 0x2B1C :
case 0x001C :
V_11 = - V_49 ;
F_206 ( & V_7 -> V_183 -> V_2 ,
L_111 ) ;
break;
case 0x2B24 :
case 0x0024 :
V_11 = - V_231 ;
F_206 ( & V_7 -> V_183 -> V_2 ,
L_109 ) ;
break;
case 0x2B20 :
case 0x0020 :
V_11 = - V_347 ;
F_206 ( & V_7 -> V_183 -> V_2 ,
L_112 ) ;
break;
default:
V_11 = - V_55 ;
}
else
switch ( V_339 -> V_343 ) {
case V_348 :
V_11 = - V_31 ;
break;
case V_349 :
V_11 = - V_31 ;
break;
default:
V_11 = - V_55 ;
}
if ( V_11 ) {
F_7 ( V_7 , 2 , L_113 , V_339 -> V_343 ) ;
F_7 ( V_7 , 2 , L_114 , V_339 -> V_344 ) ;
}
return V_11 ;
}
static inline int F_207 ( struct V_6 * V_7 )
{
return ( V_7 -> V_13 . type == V_187 ) ?
V_277 :
V_276 ;
}
static int F_208 ( struct V_6 * V_7 ,
struct V_99 * V_100 , unsigned long V_77 )
{
struct V_101 * V_5 = (struct V_101 * ) V_77 ;
struct V_338 * V_339 = (struct V_338 * ) V_100 -> V_350 ;
F_17 ( V_7 , 2 , L_115 ) ;
V_339 -> V_343 = V_5 -> V_81 . V_102 ;
V_339 -> V_344 = V_5 -> V_77 . V_196 . V_81 . V_102 ;
if ( ( V_339 -> V_343 == 0 ) && ( V_339 -> V_344 == 0 ) ) {
V_339 -> V_77 . V_351 =
V_5 -> V_77 . V_196 . V_77 . V_352 . V_353 ;
} else {
V_339 -> V_77 . V_351 = 0 ;
}
return 0 ;
}
static void F_138 ( struct V_6 * V_7 )
{
struct V_108 * V_109 ;
struct V_101 * V_5 ;
struct V_338 V_339 ;
F_17 ( V_7 , 2 , L_116 ) ;
V_109 = F_40 ( V_7 , F_207 ( V_7 ) , 0 ) ;
if ( ! V_109 )
return;
V_5 = (struct V_101 * ) ( V_109 -> V_77 + V_111 ) ;
V_5 -> V_77 . V_196 . V_81 . V_354 =
sizeof( struct V_355 ) +
sizeof( struct V_356 ) ;
V_5 -> V_77 . V_196 . V_81 . V_278 =
V_357 ;
V_5 -> V_77 . V_196 . V_81 . V_358 = 1 ;
V_5 -> V_77 . V_196 . V_81 . V_359 = 1 ;
if ( F_41 ( V_7 , V_109 , F_208 ,
( void * ) & V_339 ) ||
F_205 ( V_7 , & V_339 ,
V_357 ) ) {
V_7 -> V_166 . V_196 . V_195 = V_204 ;
return;
}
V_7 -> V_166 . V_196 . V_263 = V_339 . V_77 . V_351 ;
}
static int F_209 ( struct V_6 * V_7 ,
struct V_99 * V_100 , unsigned long V_77 )
{
struct V_101 * V_5 = (struct V_101 * ) V_77 ;
struct V_360 * V_317 = & V_5 -> V_77 . V_196 . V_77 . V_361 ;
struct V_338 * V_339 = (struct V_338 * ) V_100 -> V_350 ;
F_17 ( V_7 , 2 , L_117 ) ;
V_339 -> V_343 = V_5 -> V_81 . V_102 ;
V_339 -> V_344 = V_5 -> V_77 . V_196 . V_81 . V_102 ;
if ( ( V_339 -> V_343 != 0 ) || ( V_339 -> V_344 != 0 ) )
return 0 ;
if ( V_317 -> V_327 != sizeof( struct V_315 ) ) {
V_339 -> V_344 = 0xffff ;
F_7 ( V_7 , 2 , L_118 , V_317 -> V_327 ) ;
return 0 ;
}
if ( V_317 -> V_328 > 0 ) {
if ( V_339 -> V_77 . V_317 . V_195 )
* V_339 -> V_77 . V_317 . V_195 = V_317 -> V_316 [ 0 ] . V_195 ;
if ( V_339 -> V_77 . V_317 . V_124 )
* V_339 -> V_77 . V_317 . V_124 = V_317 -> V_316 [ 0 ] . V_124 ;
}
return 0 ;
}
int F_210 ( struct V_6 * V_7 ,
enum V_362 * V_195 , enum V_363 * V_124 )
{
int V_11 = 0 ;
struct V_108 * V_109 ;
struct V_101 * V_5 ;
struct V_338 V_339 = {
. V_77 = {
. V_317 = {
. V_195 = V_195 ,
. V_124 = V_124 ,
} ,
} ,
} ;
F_17 ( V_7 , 2 , L_119 ) ;
if ( ! ( V_7 -> V_166 . V_196 . V_263 & V_364 ) )
return - V_31 ;
V_109 = F_40 ( V_7 , F_207 ( V_7 ) , 0 ) ;
if ( ! V_109 )
return - V_54 ;
V_5 = (struct V_101 * ) ( V_109 -> V_77 + V_111 ) ;
V_5 -> V_77 . V_196 . V_81 . V_354 =
sizeof( struct V_355 ) ;
V_5 -> V_77 . V_196 . V_81 . V_278 =
V_364 ;
V_5 -> V_77 . V_196 . V_81 . V_358 = 1 ;
V_5 -> V_77 . V_196 . V_81 . V_359 = 1 ;
V_11 = F_41 ( V_7 , V_109 , F_209 ,
( void * ) & V_339 ) ;
if ( V_11 < 0 )
return V_11 ;
return F_205 ( V_7 , & V_339 , V_364 ) ;
}
static int F_211 ( struct V_6 * V_7 ,
struct V_99 * V_100 , unsigned long V_77 )
{
struct V_101 * V_5 = (struct V_101 * ) V_77 ;
struct V_338 * V_339 = (struct V_338 * ) V_100 -> V_350 ;
F_17 ( V_7 , 2 , L_120 ) ;
V_339 -> V_343 = V_5 -> V_81 . V_102 ;
V_339 -> V_344 = V_5 -> V_77 . V_196 . V_81 . V_102 ;
return 0 ;
}
int F_93 ( struct V_6 * V_7 , enum V_362 V_195 )
{
int V_11 = 0 ;
int V_354 ;
struct V_108 * V_109 ;
struct V_101 * V_5 ;
struct V_338 V_339 ;
enum V_340 V_341 ;
F_17 ( V_7 , 2 , L_121 ) ;
switch ( V_195 ) {
case V_204 :
V_341 = V_365 ;
V_354 = sizeof( struct V_355 ) +
sizeof( struct V_366 ) ;
break;
case V_202 :
V_341 = V_345 ;
V_354 = sizeof( struct V_355 ) +
sizeof( struct V_367 ) ;
break;
case V_203 :
V_341 = V_346 ;
V_354 = sizeof( struct V_355 ) +
sizeof( struct V_368 ) ;
break;
default:
return - V_27 ;
}
if ( ! ( V_7 -> V_166 . V_196 . V_263 & V_341 ) )
return - V_31 ;
V_109 = F_40 ( V_7 , F_207 ( V_7 ) , 0 ) ;
if ( ! V_109 )
return - V_54 ;
V_5 = (struct V_101 * ) ( V_109 -> V_77 + V_111 ) ;
V_5 -> V_77 . V_196 . V_81 . V_354 = V_354 ;
V_5 -> V_77 . V_196 . V_81 . V_278 = V_341 ;
V_5 -> V_77 . V_196 . V_81 . V_358 = 1 ;
V_5 -> V_77 . V_196 . V_81 . V_359 = 1 ;
V_11 = F_41 ( V_7 , V_109 , F_211 ,
( void * ) & V_339 ) ;
if ( V_11 < 0 )
return V_11 ;
return F_205 ( V_7 , & V_339 , V_341 ) ;
}
static int F_212 ( struct V_6 * V_7 , int V_369 , T_4 V_370 )
{
int V_11 ;
if ( V_369 == 0 )
switch ( V_370 ) {
case 0x0001 :
V_11 = 0 ;
break;
case 0x0004 :
case 0x0100 :
case 0x0106 :
V_11 = - V_31 ;
F_206 ( & V_7 -> V_183 -> V_2 ,
L_122 ) ;
break;
case 0x0107 :
V_11 = - V_371 ;
break;
default:
V_11 = - V_55 ;
}
else
V_11 = - V_55 ;
if ( V_11 ) {
F_7 ( V_7 , 2 , L_123 , V_369 ) ;
F_7 ( V_7 , 2 , L_124 , V_370 ) ;
}
return V_11 ;
}
static void F_213 ( void * V_372 ,
enum V_373 type , void * V_316 )
{
struct V_6 * V_7 = (struct V_6 * ) V_372 ;
struct V_374 * V_375 ;
T_7 V_291 ;
if ( type != V_376 ) {
F_61 ( 1 ) ;
return;
}
V_375 = (struct V_374 * ) V_316 ;
V_291 = V_302 ;
if ( V_375 -> V_295 . V_301 )
V_291 |= V_300 ;
F_198 ( V_7 , V_298 , V_291 ,
(struct V_292 * ) & V_375 -> V_377 ,
(struct V_294 * ) & V_375 -> V_295 ) ;
}
int F_214 ( struct V_6 * V_7 , int V_378 )
{
int V_11 ;
T_4 V_370 ;
struct V_379 * V_380 ;
struct V_381 V_382 ;
if ( ! V_7 )
return - V_27 ;
if ( ! V_7 -> V_166 . V_196 . V_263 )
return - V_31 ;
V_380 = F_153 ( V_7 ) ;
F_215 ( V_380 , & V_382 ) ;
if ( V_378 ) {
F_198 ( V_7 , V_310 , 0 , NULL , NULL ) ;
V_11 = F_216 ( V_382 , 1 , & V_370 ,
F_213 , V_7 ) ;
} else
V_11 = F_216 ( V_382 , 0 , & V_370 , NULL , NULL ) ;
return F_212 ( V_7 , V_11 , V_370 ) ;
}
