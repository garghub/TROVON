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
static void F_52 ( struct V_6 * V_7 , int V_131 )
{
F_53 ( V_132 , 2 , L_21 ) ;
F_54 ( V_132 , 2 , & V_7 , sizeof( void * ) ) ;
F_55 ( V_7 , 0 , 1 ) ;
if ( V_7 -> V_133 . V_134 == V_135 &&
V_7 -> V_136 . V_134 == V_135 &&
( V_7 -> V_134 == V_137 ) ) {
if ( V_131 &&
V_7 -> V_13 . type != V_14 ) {
F_56 ( V_7 -> V_2 ) ;
} else {
F_57 () ;
F_58 ( V_7 -> V_2 ) ;
F_59 () ;
}
V_7 -> V_13 . V_138 &= ~ V_139 ;
V_7 -> V_134 = V_140 ;
}
if ( V_7 -> V_134 == V_140 ) {
F_25 ( V_7 , 0 ) ;
F_60 ( V_7 ) ;
V_7 -> V_134 = V_141 ;
}
if ( V_7 -> V_134 == V_141 ) {
F_61 ( V_7 , 0 ) ;
F_62 ( V_7 ) ;
F_63 ( V_7 ) ;
V_7 -> V_134 = V_142 ;
}
if ( V_7 -> V_134 == V_142 ) {
F_64 ( & V_7 -> V_133 ) ;
F_64 ( & V_7 -> V_136 ) ;
}
}
static int F_65 ( struct V_6 * V_7 ,
int V_143 , int * V_144 )
{
int V_145 = 0 ;
struct V_71 * V_72 ;
struct V_77 * V_78 ;
unsigned int V_101 ;
* V_144 = 0 ;
F_66 ( ! V_143 ) ;
while ( V_143 ) {
V_72 = F_67 ( V_7 ,
& V_7 -> V_146 . V_147 -> V_148 [ V_7 -> V_149 . V_150 ] ,
& V_7 -> V_149 . V_151 , & V_7 -> V_149 . V_152 , & V_78 ) ;
if ( ! V_72 ) {
* V_144 = 1 ;
break;
}
V_72 -> V_2 = V_7 -> V_2 ;
switch ( V_78 -> V_78 . V_83 . V_95 ) {
case V_96 :
V_72 -> V_153 = V_154 ;
V_72 -> V_81 = F_68 ( V_72 , V_72 -> V_2 ) ;
if ( ( V_7 -> V_2 -> V_155 & V_156 )
&& ( ( V_78 -> V_78 . V_83 . V_32 [ 1 ] &
( V_86 |
V_85 ) ) ==
( V_86 |
V_85 ) ) )
V_72 -> V_157 = V_158 ;
else
V_72 -> V_157 = V_159 ;
if ( V_72 -> V_81 == F_69 ( V_160 ) )
* ( ( V_161 * ) V_72 -> V_162 ) = ++ V_7 -> V_163 . V_164 ;
V_101 = V_72 -> V_101 ;
F_70 ( & V_7 -> V_165 , V_72 ) ;
break;
case V_166 :
if ( V_7 -> V_13 . type == V_14 ) {
F_71 ( V_72 , sizeof( struct V_77 ) ) ;
F_72 ( V_72 , V_78 ,
sizeof( struct V_77 ) ) ;
V_101 = V_72 -> V_101 ;
V_7 -> V_167 . V_168 ( V_72 ) ;
break;
}
default:
F_73 ( V_72 ) ;
F_17 ( V_7 , 3 , L_22 ) ;
F_54 ( V_169 , 3 , V_78 , V_170 ) ;
continue;
}
V_145 ++ ;
V_143 -- ;
V_7 -> V_171 . V_172 ++ ;
V_7 -> V_171 . V_173 += V_101 ;
}
return V_145 ;
}
static int F_74 ( struct V_174 * V_165 , int V_143 )
{
struct V_6 * V_7 = F_75 ( V_165 , struct V_6 , V_165 ) ;
int V_145 = 0 ;
struct V_175 * V_176 ;
int V_144 ;
int V_177 = V_143 ;
if ( V_7 -> V_88 . V_89 ) {
V_7 -> V_90 . V_178 ++ ;
V_7 -> V_90 . V_179 = F_76 () ;
}
while ( 1 ) {
if ( ! V_7 -> V_149 . V_180 ) {
V_7 -> V_149 . V_181 = 0 ;
V_7 -> V_149 . V_180 = F_77 (
V_7 -> V_74 . V_182 , 0 , & V_7 -> V_149 . V_150 ,
& V_7 -> V_149 . V_181 ) ;
if ( V_7 -> V_149 . V_180 <= 0 ) {
V_7 -> V_149 . V_180 = 0 ;
break;
}
V_7 -> V_149 . V_151 =
& V_7 -> V_146 . V_147 -> V_148 [ V_7 -> V_149 . V_150 ]
. V_176 -> V_183 [ 0 ] ;
V_7 -> V_149 . V_152 = 0 ;
}
while ( V_7 -> V_149 . V_180 ) {
V_176 = & V_7 -> V_146 . V_147 -> V_148 [ V_7 -> V_149 . V_150 ] ;
if ( ! ( V_7 -> V_149 . V_181 &&
F_78 ( V_7 , V_176 -> V_176 ,
V_7 -> V_149 . V_181 , L_23 ) ) )
V_145 += F_65 (
V_7 , V_177 , & V_144 ) ;
else
V_144 = 1 ;
if ( V_144 ) {
if ( V_7 -> V_88 . V_89 )
V_7 -> V_90 . V_184 ++ ;
F_79 ( V_7 ,
V_176 -> V_185 ) ;
F_80 ( V_7 , V_7 -> V_149 . V_150 ) ;
V_7 -> V_149 . V_180 -- ;
if ( V_7 -> V_149 . V_180 ) {
V_7 -> V_149 . V_150 =
( V_7 -> V_149 . V_150 + 1 ) %
V_186 ;
V_7 -> V_149 . V_151 =
& V_7 -> V_146 . V_147
-> V_148 [ V_7 -> V_149 . V_150 ]
. V_176 -> V_183 [ 0 ] ;
V_7 -> V_149 . V_152 = 0 ;
}
}
if ( V_145 >= V_143 )
goto V_187;
else
V_177 = V_143 - V_145 ;
}
}
F_81 ( V_165 ) ;
if ( F_82 ( V_7 -> V_74 . V_182 , 0 ) )
F_83 ( & V_7 -> V_165 ) ;
V_187:
if ( V_7 -> V_88 . V_89 )
V_7 -> V_90 . V_188 += F_76 () -
V_7 -> V_90 . V_179 ;
return V_145 ;
}
static int F_18 ( struct V_6 * V_7 , T_2 * V_56 ,
enum V_114 V_115 )
{
struct V_110 * V_5 ;
struct V_116 * V_117 ;
F_17 ( V_7 , 2 , L_24 ) ;
V_117 = F_42 ( V_7 , V_115 , V_118 ) ;
if ( ! V_117 )
return - V_54 ;
V_5 = (struct V_110 * ) ( V_117 -> V_74 + V_119 ) ;
V_5 -> V_74 . V_189 . V_190 = V_191 ;
memcpy ( & V_5 -> V_74 . V_189 . V_56 , V_56 , V_191 ) ;
return F_43 ( V_7 , V_117 , NULL , NULL ) ;
}
static int F_84 ( struct V_6 * V_7 , T_2 * V_56 )
{
int V_11 ;
F_17 ( V_7 , 2 , L_25 ) ;
V_11 = F_15 ( V_7 , F_18 ( V_7 , V_56 ,
V_63 ) ) ;
if ( V_11 == 0 ) {
V_7 -> V_13 . V_138 |= V_139 ;
memcpy ( V_7 -> V_2 -> V_192 , V_56 , V_191 ) ;
F_85 ( & V_7 -> V_193 -> V_2 ,
L_26 ,
V_7 -> V_2 -> V_192 , V_7 -> V_2 -> V_194 ) ;
} else {
V_7 -> V_13 . V_138 &= ~ V_139 ;
switch ( V_11 ) {
case - V_49 :
F_86 ( & V_7 -> V_193 -> V_2 ,
L_27 , V_56 ) ;
break;
case - V_15 :
F_86 ( & V_7 -> V_193 -> V_2 ,
L_28 , V_56 ) ;
break;
}
}
return V_11 ;
}
static int F_87 ( struct V_6 * V_7 , T_2 * V_56 )
{
int V_11 ;
F_17 ( V_7 , 2 , L_29 ) ;
if ( ! ( V_7 -> V_13 . V_138 & V_139 ) )
return 0 ;
V_11 = F_15 ( V_7 , F_18 ( V_7 , V_56 ,
V_69 ) ) ;
if ( V_11 == 0 )
V_7 -> V_13 . V_138 &= ~ V_139 ;
return V_11 ;
}
static int F_88 ( struct V_6 * V_7 )
{
int V_11 = 0 ;
char V_195 [] = { 0x02 , 0x00 , 0x00 } ;
F_53 ( V_132 , 2 , L_30 ) ;
F_89 ( V_132 , 2 , L_31 , F_90 ( V_7 ) ) ;
if ( F_91 ( V_7 , V_196 ) ) {
V_11 = F_92 ( V_7 ) ;
if ( V_11 ) {
F_19 ( 2 , L_32
L_33 ,
F_90 ( V_7 ) , V_11 ) ;
}
}
if ( V_7 -> V_13 . type == V_197 ||
V_7 -> V_13 . type == V_21 ||
V_7 -> V_13 . type == V_22 ||
V_7 -> V_13 . V_23 ) {
V_11 = F_93 ( V_7 ) ;
if ( V_11 ) {
F_19 ( 2 , L_34
L_35 , F_90 ( V_7 ) , V_11 ) ;
F_89 ( V_132 , 2 , L_36 , V_11 ) ;
return V_11 ;
}
F_54 ( V_132 , 2 , V_7 -> V_2 -> V_192 , V_191 ) ;
} else {
F_94 ( V_7 -> V_2 -> V_192 ) ;
memcpy ( V_7 -> V_2 -> V_192 , V_195 , 3 ) ;
}
return 0 ;
}
static int F_95 ( struct V_1 * V_2 , void * V_198 )
{
struct V_199 * V_59 = V_198 ;
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
F_96 ( V_7 , 3 , V_59 -> V_200 , V_191 ) ;
if ( F_46 ( V_7 , V_125 ) ) {
F_17 ( V_7 , 3 , L_40 ) ;
return - V_201 ;
}
V_11 = F_87 ( V_7 , & V_7 -> V_2 -> V_192 [ 0 ] ) ;
if ( ! V_11 || ( V_11 == - V_53 ) )
V_11 = F_84 ( V_7 , V_59 -> V_200 ) ;
return V_11 ? - V_27 : 0 ;
}
static void F_97 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
enum V_202 V_203 ;
int V_204 ;
int V_11 ;
F_17 ( V_7 , 3 , L_41 ) ;
if ( ! V_7 -> V_88 . V_205 . V_206 )
return;
V_203 = ( V_2 -> V_32 & V_207 ) ? V_208
: V_209 ;
if ( V_203 == V_7 -> V_13 . V_203 )
return;
if ( V_203 == V_208 ) {
if ( V_7 -> V_88 . V_205 . V_210 )
V_204 = V_211 ;
else
V_204 = V_212 ;
} else
V_204 = V_213 ;
V_11 = F_98 ( V_7 , V_204 ) ;
F_89 ( V_132 , 2 , L_42 ,
( V_203 == V_208 ) ? '+' : '-' , V_11 ) ;
if ( ! V_11 ) {
V_7 -> V_88 . V_205 . V_204 = V_204 ;
V_7 -> V_13 . V_203 = V_203 ;
}
}
static void
F_99 ( struct V_6 * V_7 , struct V_214 * V_215 , T_4 V_61 )
{
struct V_60 * V_56 ;
F_100 (card->mac_htable, mac, hnode,
qeth_l2_mac_hash(ha->addr)) {
if ( V_61 == V_56 -> V_61 &&
! memcmp ( V_215 -> V_59 , V_56 -> V_62 , V_191 ) ) {
V_56 -> V_216 = V_217 ;
return;
}
}
V_56 = F_101 ( sizeof( struct V_60 ) , V_126 ) ;
if ( ! V_56 )
return;
memcpy ( V_56 -> V_62 , V_215 -> V_59 , V_191 ) ;
V_56 -> V_61 = V_61 ;
V_56 -> V_216 = V_218 ;
F_102 ( V_7 -> V_219 , & V_56 -> V_70 ,
F_22 ( V_56 -> V_62 ) ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_214 * V_215 ;
struct V_60 * V_56 ;
struct V_65 * V_66 ;
int V_67 ;
int V_11 ;
if ( V_7 -> V_13 . type == V_14 )
return;
F_17 ( V_7 , 3 , L_43 ) ;
if ( F_103 ( V_7 , V_125 ) &&
( V_7 -> V_134 != V_137 ) )
return;
F_26 ( & V_7 -> V_68 ) ;
F_104 (ha, dev)
F_99 ( V_7 , V_215 , 0 ) ;
F_105 (ha, dev)
F_99 ( V_7 , V_215 , 1 ) ;
F_27 (card->mac_htable, i, tmp, mac, hnode) {
if ( V_56 -> V_216 == V_220 ) {
if ( ! V_56 -> V_61 )
V_11 = F_21 ( V_7 ,
V_56 -> V_62 ) ;
else {
V_11 = F_18 ( V_7 , V_56 -> V_62 ,
V_69 ) ;
}
F_28 ( & V_56 -> V_70 ) ;
F_29 ( V_56 ) ;
} else if ( V_56 -> V_216 == V_218 ) {
V_11 = F_24 ( V_7 , V_56 ) ;
if ( V_11 ) {
F_28 ( & V_56 -> V_70 ) ;
F_29 ( V_56 ) ;
} else
V_56 -> V_216 = V_220 ;
} else
V_56 -> V_216 = V_220 ;
}
F_30 ( & V_7 -> V_68 ) ;
if ( F_106 ( V_7 , V_221 ) )
F_107 ( V_7 ) ;
else
F_97 ( V_7 ) ;
}
static int F_108 ( struct V_71 * V_72 , struct V_1 * V_2 )
{
int V_11 ;
struct V_77 * V_78 = NULL ;
int V_222 = 0 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_71 * V_223 = V_72 ;
int V_92 = F_31 ( V_7 , V_72 ) ;
struct V_224 * V_225 ;
int V_226 = V_72 -> V_101 ;
int V_227 = - 1 ;
int V_228 = 0 ;
int V_229 = 0 ;
int V_230 ;
if ( V_7 -> V_146 . V_231 || ( V_92 &&
V_7 -> V_13 . V_232 ) )
V_225 = V_7 -> V_146 . V_233 [ F_109 ( V_7 , V_72 ,
F_110 ( V_72 ) , V_92 ) ] ;
else
V_225 = V_7 -> V_146 . V_233 [ V_7 -> V_146 . V_234 ] ;
if ( ( V_7 -> V_134 != V_137 ) || ! V_7 -> V_235 ) {
V_7 -> V_171 . V_236 ++ ;
goto V_237;
}
if ( ( V_7 -> V_13 . type == V_14 ) &&
( V_72 -> V_81 == F_69 ( V_238 ) ) )
goto V_237;
if ( V_7 -> V_88 . V_89 ) {
V_7 -> V_90 . V_239 ++ ;
V_7 -> V_90 . V_240 = F_76 () ;
}
F_111 ( V_2 ) ;
if ( ( V_7 -> V_13 . type != V_197 ) &&
! F_112 ( V_7 , V_223 , 0 ) ) {
int V_241 = F_113 ( V_223 ) ;
if ( V_7 -> V_88 . V_89 ) {
if ( V_241 )
V_7 -> V_90 . V_242 ++ ;
else
V_7 -> V_90 . V_243 ++ ;
}
if ( V_241 )
goto V_237;
}
if ( V_7 -> V_13 . type == V_14 )
V_78 = (struct V_77 * ) V_72 -> V_74 ;
else {
if ( V_7 -> V_13 . type == V_197 ) {
V_223 = V_72 ;
V_227 = V_244 ;
V_229 = V_244 ;
V_78 = F_114 ( V_245 ,
V_126 ) ;
if ( ! V_78 )
goto V_237;
V_228 ++ ;
F_115 ( V_223 ) ;
F_36 ( V_7 , V_78 , V_223 , V_92 ) ;
V_78 -> V_78 . V_83 . V_100 = V_223 -> V_101 ;
memcpy ( ( ( char * ) V_78 ) + sizeof( struct V_77 ) ,
F_37 ( V_223 ) , V_244 ) ;
} else {
V_223 = F_116 ( V_72 ,
sizeof( struct V_77 ) ) ;
if ( ! V_223 )
goto V_237;
V_78 = (struct V_77 * ) F_71 ( V_223 ,
sizeof( struct V_77 ) ) ;
F_117 ( V_223 , sizeof( struct V_77 ) ) ;
F_36 ( V_7 , V_78 , V_223 , V_92 ) ;
if ( V_223 -> V_157 == V_246 )
F_34 ( V_7 , V_78 , V_223 ) ;
}
}
V_222 = F_112 ( V_7 , V_223 , V_228 ) ;
if ( ! V_222 ) {
if ( V_227 >= 0 )
F_118 ( V_245 , V_78 ) ;
goto V_237;
}
if ( V_7 -> V_13 . type != V_197 ) {
if ( F_119 ( V_223 , & V_78 ,
sizeof( struct V_247 ) ) )
goto V_237;
V_11 = F_120 ( V_7 , V_225 , V_223 , V_78 ,
V_222 ) ;
} else
V_11 = F_121 ( V_7 , V_225 , V_223 , V_78 ,
V_222 , V_227 , V_229 ) ;
if ( ! V_11 ) {
V_7 -> V_171 . V_248 ++ ;
V_7 -> V_171 . V_226 += V_226 ;
if ( V_7 -> V_88 . V_89 ) {
V_230 = F_122 ( V_223 ) -> V_230 ;
if ( V_230 ) {
V_7 -> V_90 . V_249 ++ ;
V_7 -> V_90 . V_250 += V_230 + 1 ;
}
}
if ( V_223 != V_72 )
F_73 ( V_72 ) ;
V_11 = V_251 ;
} else {
if ( V_227 >= 0 )
F_118 ( V_245 , V_78 ) ;
if ( V_11 == - V_252 ) {
if ( V_223 != V_72 )
F_73 ( V_223 ) ;
return V_253 ;
} else
goto V_237;
}
F_123 ( V_2 ) ;
if ( V_7 -> V_88 . V_89 )
V_7 -> V_90 . V_254 += F_76 () -
V_7 -> V_90 . V_240 ;
return V_11 ;
V_237:
V_7 -> V_171 . V_255 ++ ;
V_7 -> V_171 . V_256 ++ ;
if ( ( V_223 != V_72 ) && V_223 )
F_73 ( V_223 ) ;
F_73 ( V_72 ) ;
F_123 ( V_2 ) ;
return V_251 ;
}
static int F_124 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_11 = 0 ;
F_17 ( V_7 , 4 , L_44 ) ;
if ( V_7 -> V_134 == V_137 )
return V_11 ;
if ( V_7 -> V_134 != V_140 )
return - V_12 ;
if ( ( V_7 -> V_13 . type != V_14 ) &&
( ! ( V_7 -> V_13 . V_138 & V_139 ) ) ) {
F_17 ( V_7 , 4 , L_45 ) ;
return - V_15 ;
}
V_7 -> V_74 . V_134 = V_135 ;
V_7 -> V_134 = V_137 ;
F_125 ( V_2 ) ;
if ( F_126 ( V_7 -> V_74 . V_182 , 0 ) >= 0 ) {
F_127 ( & V_7 -> V_165 ) ;
F_83 ( & V_7 -> V_165 ) ;
} else
V_11 = - V_55 ;
return V_11 ;
}
static int F_128 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_17 ( V_7 , 5 , L_46 ) ;
if ( F_46 ( V_7 , V_125 ) ) {
F_17 ( V_7 , 3 , L_47 ) ;
return - V_201 ;
}
return F_124 ( V_2 ) ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_17 ( V_7 , 4 , L_48 ) ;
F_129 ( V_2 ) ;
if ( V_7 -> V_134 == V_137 ) {
V_7 -> V_134 = V_140 ;
F_130 ( & V_7 -> V_165 ) ;
}
return 0 ;
}
static int F_131 ( struct V_257 * V_193 )
{
struct V_6 * V_7 = F_132 ( & V_193 -> V_2 ) ;
F_133 ( & V_193 -> V_2 ) ;
F_134 ( & V_7 -> V_128 ) ;
F_135 ( V_7 -> V_219 ) ;
V_7 -> V_88 . V_258 = 1 ;
V_7 -> V_13 . V_259 = 0 ;
return 0 ;
}
static void F_136 ( struct V_257 * V_260 )
{
struct V_6 * V_7 = F_132 ( & V_260 -> V_2 ) ;
F_137 ( & V_260 -> V_2 ) ;
F_55 ( V_7 , 0 , 1 ) ;
F_138 ( V_7 -> V_261 , F_103 ( V_7 , 0xffffffff ) == 0 ) ;
if ( V_260 -> V_134 == V_262 )
F_139 ( V_260 ) ;
if ( V_7 -> V_2 ) {
F_140 ( & V_7 -> V_165 ) ;
F_141 ( V_7 -> V_2 ) ;
V_7 -> V_2 = NULL ;
}
return;
}
static int F_142 ( struct V_6 * V_7 )
{
switch ( V_7 -> V_13 . type ) {
case V_197 :
V_7 -> V_2 = F_143 ( 0 , L_49 , V_263 ,
V_264 ) ;
break;
case V_14 :
V_7 -> V_2 = F_143 ( 0 , L_50 , V_263 ,
V_264 ) ;
V_7 -> V_2 -> V_32 |= V_265 ;
break;
default:
V_7 -> V_2 = F_144 ( 0 ) ;
}
if ( ! V_7 -> V_2 )
return - V_12 ;
V_7 -> V_2 -> V_8 = V_7 ;
V_7 -> V_2 -> V_266 = V_267 ;
V_7 -> V_2 -> V_268 = V_7 -> V_13 . V_269 ;
V_7 -> V_2 -> V_270 = 64 ;
V_7 -> V_2 -> V_271 = V_272 ;
V_7 -> V_2 -> V_273 = & V_274 ;
V_7 -> V_2 -> V_275 =
( V_7 -> V_13 . type != V_14 ) ?
& V_276 : & V_277 ;
V_7 -> V_2 -> V_155 |= V_278 ;
if ( V_7 -> V_13 . type == V_20 && ! V_7 -> V_13 . V_23 ) {
V_7 -> V_2 -> V_279 = V_280 ;
V_7 -> V_2 -> V_281 = V_280 ;
if ( F_91 ( V_7 , V_282 ) ) {
V_7 -> V_2 -> V_279 |= V_283 ;
V_7 -> V_2 -> V_281 |= V_283 ;
}
if ( F_91 ( V_7 , V_284 ) ) {
V_7 -> V_2 -> V_279 |= V_156 ;
V_7 -> V_2 -> V_281 |= V_156 ;
}
}
V_7 -> V_13 . V_285 = 1 ;
F_88 ( V_7 ) ;
V_7 -> V_2 -> V_286 = ( F_145 ( V_7 ) - 1 ) *
V_287 ;
F_146 ( V_7 -> V_2 , & V_7 -> V_193 -> V_2 ) ;
F_147 ( V_7 -> V_2 , & V_7 -> V_165 , F_74 , V_288 ) ;
F_148 ( V_7 -> V_2 ) ;
return F_149 ( V_7 -> V_2 ) ;
}
static int F_150 ( struct V_6 * V_7 )
{
if ( F_151 ( V_7 , 0 ) )
return - V_12 ;
return 0 ;
}
static int F_152 ( struct V_257 * V_193 , int V_131 )
{
struct V_6 * V_7 = F_132 ( & V_193 -> V_2 ) ;
int V_11 = 0 ;
enum V_289 V_290 ;
F_153 ( & V_7 -> V_291 ) ;
F_153 ( & V_7 -> V_292 ) ;
F_53 ( V_132 , 2 , L_51 ) ;
F_54 ( V_132 , 2 , & V_7 , sizeof( void * ) ) ;
V_290 = V_7 -> V_134 ;
V_11 = F_154 ( V_7 ) ;
if ( V_11 ) {
F_89 ( V_132 , 2 , L_52 , V_11 ) ;
V_11 = - V_12 ;
goto V_293;
}
F_155 ( V_7 ) ;
if ( V_7 -> V_88 . V_205 . V_294 )
F_85 ( & V_7 -> V_193 -> V_2 ,
L_53 ) ;
F_156 ( V_7 ) ;
if ( ! V_7 -> V_2 && F_142 ( V_7 ) ) {
V_11 = - V_12 ;
goto V_293;
}
if ( V_7 -> V_13 . type != V_14 )
F_84 ( V_7 , & V_7 -> V_2 -> V_192 [ 0 ] ) ;
if ( F_157 ( V_7 , V_295 ) ) {
if ( V_7 -> V_13 . V_259 &&
F_158 ( V_7 , V_296 ) )
V_7 -> V_13 . V_259 = 0 ;
} else
V_7 -> V_13 . V_259 = 0 ;
F_159 ( V_7 ) ;
V_7 -> V_134 = V_141 ;
memset ( & V_7 -> V_149 , 0 , sizeof( struct V_297 ) ) ;
F_160 ( V_7 ) ;
F_53 ( V_132 , 2 , L_54 ) ;
V_11 = F_161 ( V_7 ) ;
if ( V_11 ) {
F_89 ( V_132 , 2 , L_55 , V_11 ) ;
if ( V_11 == 0xe080 ) {
F_86 ( & V_7 -> V_193 -> V_2 ,
L_56 ) ;
V_7 -> V_235 = 0 ;
goto V_298;
}
V_11 = - V_12 ;
goto V_293;
} else
V_7 -> V_235 = 1 ;
V_298:
if ( ( V_7 -> V_13 . type == V_20 ) ||
( V_7 -> V_13 . type == V_22 ) ) {
V_11 = F_150 ( V_7 ) ;
if ( V_11 )
goto V_293;
}
if ( V_7 -> V_13 . type != V_14 &&
V_7 -> V_13 . type != V_21 )
F_44 ( V_7 ) ;
F_129 ( V_7 -> V_2 ) ;
V_11 = F_162 ( V_7 ) ;
if ( V_11 ) {
F_89 ( V_132 , 2 , L_57 , V_11 ) ;
V_11 = - V_12 ;
goto V_293;
}
V_7 -> V_134 = V_140 ;
if ( V_7 -> V_235 )
F_163 ( V_7 -> V_2 ) ;
else
F_148 ( V_7 -> V_2 ) ;
F_55 ( V_7 , 0xffffffff , 0 ) ;
if ( V_290 == V_299 ) {
if ( V_131 &&
V_7 -> V_13 . type != V_14 ) {
F_124 ( V_7 -> V_2 ) ;
} else {
F_57 () ;
F_164 ( V_7 -> V_2 ) ;
F_59 () ;
}
F_51 ( V_7 -> V_2 ) ;
F_57 () ;
F_165 ( V_7 -> V_2 ) ;
F_59 () ;
}
F_166 ( & V_193 -> V_2 . V_300 , V_301 ) ;
F_167 ( & V_7 -> V_292 ) ;
F_167 ( & V_7 -> V_291 ) ;
return 0 ;
V_293:
F_52 ( V_7 , 0 ) ;
F_168 ( F_169 ( V_7 ) ) ;
F_168 ( F_170 ( V_7 ) ) ;
F_168 ( F_14 ( V_7 ) ) ;
F_171 ( F_169 ( V_7 ) ) ;
if ( V_290 == V_299 )
V_7 -> V_134 = V_299 ;
else
V_7 -> V_134 = V_142 ;
F_167 ( & V_7 -> V_292 ) ;
F_167 ( & V_7 -> V_291 ) ;
return V_11 ;
}
static int F_172 ( struct V_257 * V_193 )
{
return F_152 ( V_193 , 0 ) ;
}
static int F_173 ( struct V_257 * V_260 ,
int V_131 )
{
struct V_6 * V_7 = F_132 ( & V_260 -> V_2 ) ;
int V_11 = 0 , V_302 = 0 , V_303 = 0 ;
enum V_289 V_290 ;
F_153 ( & V_7 -> V_291 ) ;
F_153 ( & V_7 -> V_292 ) ;
F_53 ( V_132 , 3 , L_58 ) ;
F_54 ( V_132 , 3 , & V_7 , sizeof( void * ) ) ;
if ( V_7 -> V_2 && F_174 ( V_7 -> V_2 ) )
F_148 ( V_7 -> V_2 ) ;
V_290 = V_7 -> V_134 ;
if ( ( ! V_131 && V_7 -> V_13 . V_259 ) || V_7 -> V_13 . V_259 == 2 ) {
F_158 ( V_7 , V_304 ) ;
V_7 -> V_13 . V_259 = 1 ;
}
F_52 ( V_7 , V_131 ) ;
V_11 = F_168 ( F_169 ( V_7 ) ) ;
V_302 = F_168 ( F_170 ( V_7 ) ) ;
V_303 = F_168 ( F_14 ( V_7 ) ) ;
if ( ! V_11 )
V_11 = ( V_302 ) ? V_302 : V_303 ;
if ( V_11 )
F_89 ( V_132 , 2 , L_55 , V_11 ) ;
F_171 ( F_169 ( V_7 ) ) ;
if ( V_290 == V_137 )
V_7 -> V_134 = V_299 ;
F_166 ( & V_260 -> V_2 . V_300 , V_301 ) ;
F_167 ( & V_7 -> V_292 ) ;
F_167 ( & V_7 -> V_291 ) ;
return 0 ;
}
static int F_139 ( struct V_257 * V_260 )
{
return F_173 ( V_260 , 0 ) ;
}
static int F_175 ( void * V_305 )
{
struct V_6 * V_7 ;
int V_11 = 0 ;
V_7 = (struct V_6 * ) V_305 ;
F_17 ( V_7 , 2 , L_59 ) ;
if ( ! F_176 ( V_7 , V_125 ) )
return 0 ;
F_17 ( V_7 , 2 , L_60 ) ;
F_86 ( & V_7 -> V_193 -> V_2 ,
L_61 ) ;
F_177 ( V_7 ) ;
F_173 ( V_7 -> V_193 , 1 ) ;
V_11 = F_152 ( V_7 -> V_193 , 1 ) ;
if ( ! V_11 )
F_85 ( & V_7 -> V_193 -> V_2 ,
L_62 ) ;
else {
F_178 ( V_7 ) ;
F_86 ( & V_7 -> V_193 -> V_2 , L_63
L_64 ) ;
}
F_179 ( V_7 ) ;
F_180 ( V_7 , V_125 ) ;
F_181 ( V_7 , V_125 ) ;
return 0 ;
}
static int T_7 F_182 ( void )
{
F_183 ( L_65 ) ;
return 0 ;
}
static void T_8 F_184 ( void )
{
F_183 ( L_66 ) ;
}
static void F_185 ( struct V_257 * V_193 )
{
struct V_6 * V_7 = F_132 ( & V_193 -> V_2 ) ;
F_55 ( V_7 , 0 , 1 ) ;
if ( ( V_193 -> V_134 == V_262 ) && V_7 -> V_13 . V_259 )
F_158 ( V_7 , V_304 ) ;
F_61 ( V_7 , 0 ) ;
F_62 ( V_7 ) ;
F_171 ( F_169 ( V_7 ) ) ;
}
static int F_186 ( struct V_257 * V_193 )
{
struct V_6 * V_7 = F_132 ( & V_193 -> V_2 ) ;
if ( V_7 -> V_2 )
F_187 ( V_7 -> V_2 ) ;
F_55 ( V_7 , 0 , 1 ) ;
F_138 ( V_7 -> V_261 , F_103 ( V_7 , 0xffffffff ) == 0 ) ;
if ( V_193 -> V_134 == V_306 )
return 0 ;
if ( V_7 -> V_134 == V_137 ) {
if ( V_7 -> V_13 . V_259 )
F_158 ( V_7 , V_304 ) ;
F_173 ( V_7 -> V_193 , 1 ) ;
} else
F_173 ( V_7 -> V_193 , 0 ) ;
return 0 ;
}
static int F_188 ( struct V_257 * V_193 )
{
struct V_6 * V_7 = F_132 ( & V_193 -> V_2 ) ;
int V_11 = 0 ;
if ( V_193 -> V_134 == V_306 )
goto V_187;
if ( V_7 -> V_134 == V_299 ) {
V_11 = F_152 ( V_7 -> V_193 , 1 ) ;
if ( V_11 ) {
F_57 () ;
F_58 ( V_7 -> V_2 ) ;
F_59 () ;
}
} else
V_11 = F_152 ( V_7 -> V_193 , 0 ) ;
V_187:
F_55 ( V_7 , 0xffffffff , 0 ) ;
if ( V_7 -> V_2 )
F_189 ( V_7 -> V_2 ) ;
if ( V_11 )
F_86 ( & V_7 -> V_193 -> V_2 , L_63
L_64 ) ;
return V_11 ;
}
static int F_190 ( struct V_6 * V_7 ,
struct V_110 * V_5 )
{
switch ( V_5 -> V_78 . V_113 ) {
case V_307 :
case V_308 :
if ( V_5 -> V_74 . V_205 . V_78 . V_309 ==
V_310 ) {
F_191 ( V_7 , V_5 ) ;
return 0 ;
} else
return 1 ;
case V_311 :
F_192 ( V_7 , V_5 ) ;
return 0 ;
default:
return 1 ;
}
}
static int F_193 ( struct V_6 * V_7 , int V_101 ,
struct V_116 * V_117 )
{
unsigned long V_32 ;
int V_11 = 0 ;
F_17 ( V_7 , 5 , L_67 ) ;
F_138 ( V_7 -> V_261 ,
F_194 ( & V_7 -> V_136 . V_312 , 0 , 1 ) == 0 ) ;
F_195 ( V_7 , V_101 , V_117 ) ;
F_17 ( V_7 , 6 , L_68 ) ;
F_196 ( F_197 ( V_7 -> V_136 . V_182 ) , V_32 ) ;
V_11 = F_198 ( V_7 -> V_136 . V_182 , & V_7 -> V_136 . V_313 ,
( V_314 ) V_117 , 0 , 0 ) ;
F_199 ( F_197 ( V_7 -> V_136 . V_182 ) , V_32 ) ;
if ( V_11 ) {
F_19 ( 2 , L_69
L_70 , V_11 ) ;
F_7 ( V_7 , 2 , L_71 , V_11 ) ;
F_200 ( V_117 -> V_315 , V_117 ) ;
F_201 ( & V_7 -> V_136 . V_312 , 0 ) ;
F_202 ( & V_7 -> V_261 ) ;
}
return V_11 ;
}
static int F_203 ( struct V_6 * V_7 ,
struct V_116 * V_117 , int V_316 )
{
T_6 V_317 , V_318 ;
F_17 ( V_7 , 4 , L_72 ) ;
F_204 ( V_7 , V_117 , V_319 ) ;
V_317 = ( T_6 ) ( V_119 + V_316 ) ;
V_318 = ( T_6 ) V_316 ;
memcpy ( F_205 ( V_117 -> V_74 ) , & V_317 , 2 ) ;
memcpy ( F_206 ( V_117 -> V_74 ) , & V_318 , 2 ) ;
memcpy ( F_207 ( V_117 -> V_74 ) , & V_318 , 2 ) ;
memcpy ( F_208 ( V_117 -> V_74 ) , & V_318 , 2 ) ;
return F_193 ( V_7 , V_317 , V_117 ) ;
}
int F_209 ( struct V_1 * V_2 , void * V_74 , int V_316 )
{
struct V_116 * V_117 ;
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
V_117 = F_210 ( & V_7 -> V_136 ) ;
memcpy ( V_117 -> V_74 + V_119 , V_74 , V_316 ) ;
V_11 = F_203 ( V_7 , V_117 , V_316 ) ;
return V_11 ;
}
int F_211 ( unsigned char * V_36 , struct V_1 * * V_2 ,
int (* F_212)( struct V_1 * , void * ) ,
int (* V_168)( struct V_71 * ) )
{
struct V_6 * V_7 ;
* V_2 = F_12 ( V_36 ) ;
if ( * V_2 == NULL )
return - V_12 ;
V_7 = ( * V_2 ) -> V_8 ;
if ( ! V_7 )
return - V_12 ;
F_17 ( V_7 , 2 , L_74 ) ;
if ( ( F_212 == NULL ) || ( V_168 == NULL ) )
return - V_27 ;
V_7 -> V_167 . F_212 = F_212 ;
V_7 -> V_167 . V_168 = V_168 ;
return 0 ;
}
void F_213 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
if ( ! V_2 )
return;
V_7 = V_2 -> V_8 ;
if ( ! V_7 )
return;
F_17 ( V_7 , 2 , L_75 ) ;
V_7 -> V_167 . F_212 = NULL ;
V_7 -> V_167 . V_168 = NULL ;
return;
}
static void F_214 ( struct V_6 * V_7 ,
enum V_320 V_321 ,
T_4 V_322 , struct V_323 * V_324 , struct V_325 * V_326 )
{
char V_327 [ 7 ] [ 32 ] ;
char * V_328 [ 8 ] ;
int V_67 = 0 ;
switch ( V_321 ) {
case V_329 :
snprintf ( V_327 [ V_67 ] , sizeof( V_327 [ V_67 ] ) , L_76 ,
( V_322 & V_330 )
? L_77 : L_78 ) ;
V_328 [ V_67 ] = V_327 [ V_67 ] ; V_67 ++ ;
if ( V_322 & V_331 ) {
snprintf ( V_327 [ V_67 ] , sizeof( V_327 [ V_67 ] ) , L_79 ,
V_326 -> V_332 ) ;
V_328 [ V_67 ] = V_327 [ V_67 ] ; V_67 ++ ;
}
if ( V_322 & V_333 ) {
snprintf ( V_327 [ V_67 ] , sizeof( V_327 [ V_67 ] ) , L_80 ,
V_326 -> V_56 ) ;
V_328 [ V_67 ] = V_327 [ V_67 ] ; V_67 ++ ;
}
snprintf ( V_327 [ V_67 ] , sizeof( V_327 [ V_67 ] ) , L_81 ,
V_324 -> V_334 , V_324 -> V_335 , V_324 -> V_336 ) ;
V_328 [ V_67 ] = V_327 [ V_67 ] ; V_67 ++ ;
snprintf ( V_327 [ V_67 ] , sizeof( V_327 [ V_67 ] ) , L_82 , V_324 -> V_337 ) ;
V_328 [ V_67 ] = V_327 [ V_67 ] ; V_67 ++ ;
snprintf ( V_327 [ V_67 ] , sizeof( V_327 [ V_67 ] ) , L_83 ,
V_324 -> V_338 ) ;
V_328 [ V_67 ] = V_327 [ V_67 ] ; V_67 ++ ;
snprintf ( V_327 [ V_67 ] , sizeof( V_327 [ V_67 ] ) , L_84 , V_324 -> V_339 ) ;
V_328 [ V_67 ] = V_327 [ V_67 ] ; V_67 ++ ;
break;
case V_340 :
snprintf ( V_327 [ V_67 ] , sizeof( V_327 [ V_67 ] ) , L_85 ) ;
V_328 [ V_67 ] = V_327 [ V_67 ] ; V_67 ++ ;
break;
case V_341 :
snprintf ( V_327 [ V_67 ] , sizeof( V_327 [ V_67 ] ) , L_86 ) ;
V_328 [ V_67 ] = V_327 [ V_67 ] ; V_67 ++ ;
break;
}
V_328 [ V_67 ] = NULL ;
F_215 ( & V_7 -> V_193 -> V_2 . V_300 , V_301 , V_328 ) ;
}
static void F_216 ( struct V_342 * V_343 )
{
struct V_344 * V_74 =
F_75 ( V_343 , struct V_344 , V_345 ) ;
struct V_346 * V_347 = & V_74 -> V_348 . V_347 [ 0 ] ;
char V_349 [ 32 ] ;
char V_350 [ 32 ] ;
char V_351 [ 32 ] ;
char * V_328 [] = {
V_349 ,
V_350 ,
V_351 ,
NULL
} ;
F_153 ( & V_74 -> V_7 -> V_292 ) ;
V_74 -> V_7 -> V_88 . V_205 . V_204 = V_347 -> V_204 ;
F_167 ( & V_74 -> V_7 -> V_292 ) ;
snprintf ( V_349 , sizeof( V_349 ) , L_87 ) ;
snprintf ( V_350 , sizeof( V_350 ) , L_88 ,
( V_347 -> V_204 == V_213 ) ? L_89 :
( V_347 -> V_204 == V_211 ) ? L_90 :
( V_347 -> V_204 == V_212 ) ? L_91 :
L_92 ) ;
snprintf ( V_351 , sizeof( V_351 ) , L_93 ,
( V_347 -> V_134 == V_352 ) ? L_94 :
( V_347 -> V_134 == V_353 ) ? L_95 :
( V_347 -> V_134 == V_354 ) ? L_96 :
L_92 ) ;
F_215 ( & V_74 -> V_7 -> V_193 -> V_2 . V_300 ,
V_301 , V_328 ) ;
F_29 ( V_74 ) ;
}
static void F_191 ( struct V_6 * V_7 ,
struct V_110 * V_5 )
{
struct V_355 * V_348 =
& V_5 -> V_74 . V_205 . V_74 . V_356 ;
struct V_344 * V_74 ;
int V_357 ;
F_17 ( V_7 , 2 , L_97 ) ;
if ( V_348 -> V_358 != sizeof( struct V_346 ) ) {
F_7 ( V_7 , 2 , L_98 , V_348 -> V_358 ) ;
return;
}
V_357 = sizeof( struct V_346 ) * V_348 -> V_359 ;
V_74 = F_101 ( sizeof( struct V_344 ) + V_357 ,
V_126 ) ;
if ( ! V_74 ) {
F_17 ( V_7 , 2 , L_99 ) ;
return;
}
F_217 ( & V_74 -> V_345 , F_216 ) ;
V_74 -> V_7 = V_7 ;
memcpy ( & V_74 -> V_348 , V_348 ,
sizeof( struct V_355 ) + V_357 ) ;
F_218 ( V_360 , & V_74 -> V_345 ) ;
}
static void F_219 ( struct V_342 * V_343 )
{
struct V_361 * V_74 =
F_75 ( V_343 , struct V_361 , V_345 ) ;
int V_67 ;
if ( V_74 -> V_362 . V_363 ) {
F_85 ( & V_74 -> V_7 -> V_193 -> V_2 ,
L_100 ,
V_74 -> V_7 -> V_2 -> V_194 ,
( V_74 -> V_362 . V_363 == 0x01 )
? L_101
: ( V_74 -> V_362 . V_363 == 0x02 )
? L_102
: L_103 ) ;
F_153 ( & V_74 -> V_7 -> V_292 ) ;
V_74 -> V_7 -> V_88 . V_205 . V_364 = 0 ;
F_167 ( & V_74 -> V_7 -> V_292 ) ;
F_214 ( V_74 -> V_7 , V_340 ,
0 , NULL , NULL ) ;
} else
for ( V_67 = 0 ; V_67 < V_74 -> V_362 . V_359 ; V_67 ++ ) {
struct V_365 * V_347 =
& V_74 -> V_362 . V_347 [ V_67 ] ;
F_214 ( V_74 -> V_7 ,
V_329 ,
V_347 -> V_366 ,
& V_347 -> V_324 , & V_347 -> V_326 ) ;
}
F_29 ( V_74 ) ;
}
static void F_192 ( struct V_6 * V_7 ,
struct V_110 * V_5 )
{
struct V_367 * V_362 =
& V_5 -> V_74 . V_368 ;
struct V_361 * V_74 ;
int V_357 ;
F_17 ( V_7 , 2 , L_104 ) ;
if ( V_5 -> V_78 . V_111 != 0x0000 ) {
if ( V_5 -> V_78 . V_111 == 0x0010 ) {
if ( V_362 -> V_363 == 0x00 )
V_362 -> V_363 = 0xff ;
} else {
F_7 ( V_7 , 2 , L_105 ,
V_5 -> V_78 . V_111 ) ;
return;
}
}
V_357 = sizeof( struct V_365 ) *
V_362 -> V_359 ;
V_74 = F_101 ( sizeof( struct V_361 ) + V_357 ,
V_126 ) ;
if ( ! V_74 ) {
F_17 ( V_7 , 2 , L_106 ) ;
return;
}
F_217 ( & V_74 -> V_345 , F_219 ) ;
V_74 -> V_7 = V_7 ;
memcpy ( & V_74 -> V_362 , V_362 ,
sizeof( struct V_367 ) + V_357 ) ;
F_218 ( V_360 , & V_74 -> V_345 ) ;
}
static int F_220 ( struct V_6 * V_7 ,
struct V_369 * V_370 , enum V_371 V_372 )
{
int V_11 ;
int V_373 = ( V_7 -> V_13 . type == V_197 ) ;
if ( ( V_373 && ( V_370 -> V_374 == V_43 ) ) ||
( ! V_373 && ( V_370 -> V_374 == V_370 -> V_375 ) ) )
switch ( V_370 -> V_375 ) {
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
F_221 ( & V_7 -> V_193 -> V_2 ,
L_107 ) ;
break;
case 0x2B10 :
case 0x0010 :
V_11 = - V_15 ;
F_221 ( & V_7 -> V_193 -> V_2 ,
L_108 ) ;
break;
case 0x2B14 :
case 0x0014 :
switch ( V_372 ) {
case V_376 :
V_11 = - V_49 ;
F_221 ( & V_7 -> V_193 -> V_2 ,
L_109 ) ;
break;
case V_377 :
V_11 = - V_252 ;
F_221 ( & V_7 -> V_193 -> V_2 ,
L_110 ) ;
break;
default:
V_11 = - V_55 ;
}
break;
case 0x2B18 :
case 0x0018 :
V_11 = - V_252 ;
F_221 ( & V_7 -> V_193 -> V_2 ,
L_111 ) ;
break;
case 0x2B1C :
case 0x001C :
V_11 = - V_49 ;
F_221 ( & V_7 -> V_193 -> V_2 ,
L_112 ) ;
break;
case 0x2B24 :
case 0x0024 :
V_11 = - V_252 ;
F_221 ( & V_7 -> V_193 -> V_2 ,
L_110 ) ;
break;
case 0x2B20 :
case 0x0020 :
V_11 = - V_378 ;
F_221 ( & V_7 -> V_193 -> V_2 ,
L_113 ) ;
break;
default:
V_11 = - V_55 ;
}
else
switch ( V_370 -> V_374 ) {
case V_379 :
V_11 = - V_31 ;
break;
case V_380 :
V_11 = - V_31 ;
break;
default:
V_11 = - V_55 ;
}
if ( V_11 ) {
F_7 ( V_7 , 2 , L_114 , V_370 -> V_374 ) ;
F_7 ( V_7 , 2 , L_115 , V_370 -> V_375 ) ;
}
return V_11 ;
}
static inline int F_222 ( struct V_6 * V_7 )
{
return ( V_7 -> V_13 . type == V_197 ) ?
V_308 :
V_307 ;
}
static int F_223 ( struct V_6 * V_7 ,
struct V_108 * V_109 , unsigned long V_74 )
{
struct V_110 * V_5 = (struct V_110 * ) V_74 ;
struct V_369 * V_370 = (struct V_369 * ) V_109 -> V_381 ;
F_17 ( V_7 , 2 , L_116 ) ;
V_370 -> V_374 = V_5 -> V_78 . V_111 ;
V_370 -> V_375 = V_5 -> V_74 . V_205 . V_78 . V_111 ;
if ( ( V_370 -> V_374 == 0 ) && ( V_370 -> V_375 == 0 ) ) {
V_370 -> V_74 . V_382 =
V_5 -> V_74 . V_205 . V_74 . V_383 . V_384 ;
} else {
V_370 -> V_74 . V_382 = 0 ;
}
return 0 ;
}
static void F_155 ( struct V_6 * V_7 )
{
struct V_116 * V_117 ;
struct V_110 * V_5 ;
struct V_369 V_370 ;
F_17 ( V_7 , 2 , L_117 ) ;
V_117 = F_42 ( V_7 , F_222 ( V_7 ) , 0 ) ;
if ( ! V_117 )
return;
V_5 = (struct V_110 * ) ( V_117 -> V_74 + V_119 ) ;
V_5 -> V_74 . V_205 . V_78 . V_385 =
sizeof( struct V_386 ) +
sizeof( struct V_387 ) ;
V_5 -> V_74 . V_205 . V_78 . V_309 =
V_388 ;
V_5 -> V_74 . V_205 . V_78 . V_389 = 1 ;
V_5 -> V_74 . V_205 . V_78 . V_390 = 1 ;
if ( F_43 ( V_7 , V_117 , F_223 ,
( void * ) & V_370 ) ||
F_220 ( V_7 , & V_370 ,
V_388 ) ) {
V_7 -> V_88 . V_205 . V_204 = V_213 ;
return;
}
V_7 -> V_88 . V_205 . V_294 = V_370 . V_74 . V_382 ;
}
static int F_224 ( struct V_6 * V_7 ,
struct V_108 * V_109 , unsigned long V_74 )
{
struct V_110 * V_5 = (struct V_110 * ) V_74 ;
struct V_391 * V_348 = & V_5 -> V_74 . V_205 . V_74 . V_392 ;
struct V_369 * V_370 = (struct V_369 * ) V_109 -> V_381 ;
F_17 ( V_7 , 2 , L_118 ) ;
V_370 -> V_374 = V_5 -> V_78 . V_111 ;
V_370 -> V_375 = V_5 -> V_74 . V_205 . V_78 . V_111 ;
if ( ( V_370 -> V_374 != 0 ) || ( V_370 -> V_375 != 0 ) )
return 0 ;
if ( V_348 -> V_358 != sizeof( struct V_346 ) ) {
V_370 -> V_375 = 0xffff ;
F_7 ( V_7 , 2 , L_119 , V_348 -> V_358 ) ;
return 0 ;
}
if ( V_348 -> V_359 > 0 ) {
if ( V_370 -> V_74 . V_348 . V_204 )
* V_370 -> V_74 . V_348 . V_204 = V_348 -> V_347 [ 0 ] . V_204 ;
if ( V_370 -> V_74 . V_348 . V_134 )
* V_370 -> V_74 . V_348 . V_134 = V_348 -> V_347 [ 0 ] . V_134 ;
}
return 0 ;
}
int F_225 ( struct V_6 * V_7 ,
enum V_393 * V_204 , enum V_394 * V_134 )
{
int V_11 = 0 ;
struct V_116 * V_117 ;
struct V_110 * V_5 ;
struct V_369 V_370 = {
. V_74 = {
. V_348 = {
. V_204 = V_204 ,
. V_134 = V_134 ,
} ,
} ,
} ;
F_17 ( V_7 , 2 , L_120 ) ;
if ( ! ( V_7 -> V_88 . V_205 . V_294 & V_395 ) )
return - V_31 ;
V_117 = F_42 ( V_7 , F_222 ( V_7 ) , 0 ) ;
if ( ! V_117 )
return - V_54 ;
V_5 = (struct V_110 * ) ( V_117 -> V_74 + V_119 ) ;
V_5 -> V_74 . V_205 . V_78 . V_385 =
sizeof( struct V_386 ) ;
V_5 -> V_74 . V_205 . V_78 . V_309 =
V_395 ;
V_5 -> V_74 . V_205 . V_78 . V_389 = 1 ;
V_5 -> V_74 . V_205 . V_78 . V_390 = 1 ;
V_11 = F_43 ( V_7 , V_117 , F_224 ,
( void * ) & V_370 ) ;
if ( V_11 < 0 )
return V_11 ;
return F_220 ( V_7 , & V_370 , V_395 ) ;
}
static int F_226 ( struct V_6 * V_7 ,
struct V_108 * V_109 , unsigned long V_74 )
{
struct V_110 * V_5 = (struct V_110 * ) V_74 ;
struct V_369 * V_370 = (struct V_369 * ) V_109 -> V_381 ;
F_17 ( V_7 , 2 , L_121 ) ;
V_370 -> V_374 = V_5 -> V_78 . V_111 ;
V_370 -> V_375 = V_5 -> V_74 . V_205 . V_78 . V_111 ;
return 0 ;
}
int F_98 ( struct V_6 * V_7 , enum V_393 V_204 )
{
int V_11 = 0 ;
int V_385 ;
struct V_116 * V_117 ;
struct V_110 * V_5 ;
struct V_369 V_370 ;
enum V_371 V_372 ;
F_17 ( V_7 , 2 , L_122 ) ;
switch ( V_204 ) {
case V_213 :
V_372 = V_396 ;
V_385 = sizeof( struct V_386 ) +
sizeof( struct V_397 ) ;
break;
case V_211 :
V_372 = V_376 ;
V_385 = sizeof( struct V_386 ) +
sizeof( struct V_398 ) ;
break;
case V_212 :
V_372 = V_377 ;
V_385 = sizeof( struct V_386 ) +
sizeof( struct V_399 ) ;
break;
default:
return - V_27 ;
}
if ( ! ( V_7 -> V_88 . V_205 . V_294 & V_372 ) )
return - V_31 ;
V_117 = F_42 ( V_7 , F_222 ( V_7 ) , 0 ) ;
if ( ! V_117 )
return - V_54 ;
V_5 = (struct V_110 * ) ( V_117 -> V_74 + V_119 ) ;
V_5 -> V_74 . V_205 . V_78 . V_385 = V_385 ;
V_5 -> V_74 . V_205 . V_78 . V_309 = V_372 ;
V_5 -> V_74 . V_205 . V_78 . V_389 = 1 ;
V_5 -> V_74 . V_205 . V_78 . V_390 = 1 ;
V_11 = F_43 ( V_7 , V_117 , F_226 ,
( void * ) & V_370 ) ;
if ( V_11 < 0 )
return V_11 ;
return F_220 ( V_7 , & V_370 , V_372 ) ;
}
static int F_227 ( struct V_6 * V_7 , int V_400 , T_6 V_401 )
{
int V_11 ;
if ( V_400 == 0 )
switch ( V_401 ) {
case 0x0001 :
V_11 = 0 ;
break;
case 0x0004 :
case 0x0100 :
case 0x0106 :
V_11 = - V_31 ;
F_221 ( & V_7 -> V_193 -> V_2 ,
L_123 ) ;
break;
case 0x0107 :
V_11 = - V_402 ;
break;
default:
V_11 = - V_55 ;
}
else
V_11 = - V_55 ;
if ( V_11 ) {
F_7 ( V_7 , 2 , L_124 , V_400 ) ;
F_7 ( V_7 , 2 , L_125 , V_401 ) ;
}
return V_11 ;
}
static void F_228 ( void * V_403 ,
enum V_404 type , void * V_347 )
{
struct V_6 * V_7 = (struct V_6 * ) V_403 ;
struct V_405 * V_406 ;
T_4 V_322 ;
if ( type != V_407 ) {
F_66 ( 1 ) ;
return;
}
V_406 = (struct V_405 * ) V_347 ;
V_322 = V_333 ;
if ( V_406 -> V_326 . V_332 )
V_322 |= V_331 ;
F_214 ( V_7 , V_329 , V_322 ,
(struct V_323 * ) & V_406 -> V_408 ,
(struct V_325 * ) & V_406 -> V_326 ) ;
}
int F_229 ( struct V_6 * V_7 , int V_409 )
{
int V_11 ;
T_6 V_401 ;
struct V_410 * V_411 ;
struct V_412 V_413 ;
if ( ! V_7 )
return - V_27 ;
if ( ! V_7 -> V_88 . V_205 . V_294 )
return - V_31 ;
V_411 = F_169 ( V_7 ) ;
F_230 ( V_411 , & V_413 ) ;
if ( V_409 ) {
F_214 ( V_7 , V_341 , 0 , NULL , NULL ) ;
V_11 = F_231 ( V_413 , 1 , & V_401 ,
F_228 , V_7 ) ;
} else
V_11 = F_231 ( V_413 , 0 , & V_401 , NULL , NULL ) ;
return F_227 ( V_7 , V_11 , V_401 ) ;
}
