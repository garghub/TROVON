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
static int F_16 ( struct V_6 * V_7 , T_2 * V_56 ,
enum V_57 V_58 )
{
struct V_59 * V_5 ;
struct V_60 * V_61 ;
F_17 ( V_7 , 2 , L_3 ) ;
V_61 = F_18 ( V_7 , V_58 , V_62 ) ;
if ( ! V_61 )
return - V_54 ;
V_5 = (struct V_59 * ) ( V_61 -> V_63 + V_64 ) ;
V_5 -> V_63 . V_65 . V_66 = V_67 ;
memcpy ( & V_5 -> V_63 . V_65 . V_56 , V_56 , V_67 ) ;
return F_15 ( V_7 , F_19 ( V_7 , V_61 ,
NULL , NULL ) ) ;
}
static int F_20 ( struct V_6 * V_7 , T_2 * V_56 )
{
int V_11 ;
F_17 ( V_7 , 2 , L_4 ) ;
V_11 = F_16 ( V_7 , V_56 , V_68 ) ;
if ( V_11 == 0 ) {
V_7 -> V_13 . V_69 |= V_70 ;
memcpy ( V_7 -> V_2 -> V_71 , V_56 , V_67 ) ;
F_21 ( & V_7 -> V_72 -> V_2 ,
L_5 ,
V_7 -> V_2 -> V_71 , V_7 -> V_2 -> V_73 ) ;
} else {
V_7 -> V_13 . V_69 &= ~ V_70 ;
switch ( V_11 ) {
case - V_49 :
F_22 ( & V_7 -> V_72 -> V_2 ,
L_6 , V_56 ) ;
break;
case - V_15 :
F_22 ( & V_7 -> V_72 -> V_2 ,
L_7 , V_56 ) ;
break;
}
}
return V_11 ;
}
static int F_23 ( struct V_6 * V_7 , T_2 * V_56 )
{
int V_11 ;
F_17 ( V_7 , 2 , L_8 ) ;
if ( ! ( V_7 -> V_13 . V_69 & V_70 ) )
return 0 ;
V_11 = F_16 ( V_7 , V_56 , V_74 ) ;
if ( V_11 == 0 )
V_7 -> V_13 . V_69 &= ~ V_70 ;
return V_11 ;
}
static int F_24 ( struct V_6 * V_7 , T_2 * V_56 )
{
int V_11 ;
F_17 ( V_7 , 2 , L_9 ) ;
V_11 = F_16 ( V_7 , V_56 , V_75 ) ;
if ( V_11 == - V_49 )
F_25 ( 2 , L_10 ,
V_56 , F_26 ( V_7 ) ) ;
else if ( V_11 )
F_25 ( 2 , L_11 ,
V_56 , F_26 ( V_7 ) , V_11 ) ;
return V_11 ;
}
static int F_27 ( struct V_6 * V_7 , T_2 * V_56 )
{
int V_11 ;
F_17 ( V_7 , 2 , L_12 ) ;
V_11 = F_16 ( V_7 , V_56 , V_76 ) ;
if ( V_11 )
F_25 ( 2 ,
L_13 ,
V_56 , F_26 ( V_7 ) , V_11 ) ;
return V_11 ;
}
static int F_28 ( struct V_6 * V_7 , struct V_77 * V_56 )
{
if ( V_56 -> V_78 ) {
return F_16 ( V_7 , V_56 -> V_79 ,
V_68 ) ;
} else {
return F_24 ( V_7 , V_56 -> V_79 ) ;
}
}
static int F_29 ( struct V_6 * V_7 , struct V_77 * V_56 )
{
if ( V_56 -> V_78 ) {
return F_16 ( V_7 , V_56 -> V_79 ,
V_74 ) ;
} else {
return F_27 ( V_7 , V_56 -> V_79 ) ;
}
}
static void F_30 ( struct V_6 * V_7 )
{
struct V_77 * V_56 ;
struct V_80 * V_81 ;
int V_82 ;
F_31 ( & V_7 -> V_83 ) ;
F_32 (card->mac_htable, i, tmp, mac, hnode) {
F_33 ( & V_56 -> V_84 ) ;
F_34 ( V_56 ) ;
}
F_35 ( & V_7 -> V_83 ) ;
}
static inline T_3 F_36 ( const T_4 * V_85 )
{
return F_37 ( ( T_3 * ) ( & V_85 [ 2 ] ) ) ;
}
static inline int F_38 ( struct V_6 * V_7 ,
struct V_86 * V_87 )
{
if ( V_7 -> V_13 . type == V_14 )
return V_88 ;
if ( F_39 ( V_87 -> V_63 ) )
return V_89 ;
if ( F_40 ( V_87 -> V_63 ) )
return V_90 ;
return V_88 ;
}
static inline void F_41 ( struct V_6 * V_7 ,
struct V_91 * V_92 , struct V_86 * V_87 )
{
struct V_93 * V_94 = F_42 ( V_87 ) ;
if ( V_94 -> V_95 == V_96 )
V_92 -> V_92 . V_97 . V_32 [ 1 ] |= V_98 ;
V_92 -> V_92 . V_97 . V_32 [ 1 ] |= V_99 |
V_100 ;
V_94 -> V_101 = 0 ;
if ( V_7 -> V_102 . V_103 )
V_7 -> V_104 . V_105 ++ ;
}
static void F_43 ( struct V_6 * V_7 , struct V_91 * V_92 ,
struct V_86 * V_87 , int V_106 )
{
struct V_107 * V_108 = (struct V_107 * ) F_44 ( V_87 ) ;
memset ( V_92 , 0 , sizeof( struct V_91 ) ) ;
V_92 -> V_92 . V_97 . V_109 = V_110 ;
if ( V_106 == V_90 )
V_92 -> V_92 . V_97 . V_32 [ 2 ] |= V_111 ;
else if ( V_106 == V_89 )
V_92 -> V_92 . V_97 . V_32 [ 2 ] |= V_112 ;
else
V_92 -> V_92 . V_97 . V_32 [ 2 ] |= V_113 ;
V_92 -> V_92 . V_97 . V_114 = V_87 -> V_115 - V_116 ;
if ( V_108 -> V_117 == F_45 ( V_118 ) ) {
V_92 -> V_92 . V_97 . V_32 [ 2 ] |= V_119 ;
V_92 -> V_92 . V_97 . V_120 = F_46 ( V_108 -> V_121 ) ;
}
}
static int F_47 ( struct V_6 * V_7 ,
struct V_122 * V_123 , unsigned long V_63 )
{
struct V_59 * V_5 ;
F_17 ( V_7 , 2 , L_14 ) ;
V_5 = (struct V_59 * ) V_63 ;
if ( V_5 -> V_92 . V_124 ) {
F_25 ( 2 , L_15
L_16 , V_5 -> V_63 . V_125 . V_120 ,
F_26 ( V_7 ) , V_5 -> V_92 . V_124 ) ;
F_7 ( V_7 , 2 , L_17 , V_5 -> V_92 . V_126 ) ;
F_7 ( V_7 , 2 , L_18 , V_5 -> V_92 . V_124 ) ;
}
return 0 ;
}
static int F_48 ( struct V_6 * V_7 , T_1 V_82 ,
enum V_57 V_58 )
{
struct V_59 * V_5 ;
struct V_60 * V_61 ;
F_7 ( V_7 , 4 , L_19 , V_58 ) ;
V_61 = F_18 ( V_7 , V_58 , V_62 ) ;
if ( ! V_61 )
return - V_54 ;
V_5 = (struct V_59 * ) ( V_61 -> V_63 + V_64 ) ;
V_5 -> V_63 . V_125 . V_120 = V_82 ;
return F_19 ( V_7 , V_61 ,
F_47 , NULL ) ;
}
static void F_49 ( struct V_6 * V_7 )
{
struct V_127 * V_109 ;
F_17 ( V_7 , 3 , L_20 ) ;
F_31 ( & V_7 -> V_128 ) ;
F_10 (id, &card->vid_list, list) {
F_48 ( V_7 , V_109 -> V_129 , V_130 ) ;
}
F_35 ( & V_7 -> V_128 ) ;
}
static int F_50 ( struct V_1 * V_2 ,
T_5 V_131 , T_6 V_129 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_127 * V_109 ;
int V_11 ;
F_7 ( V_7 , 4 , L_21 , V_129 ) ;
if ( ! V_129 )
return 0 ;
if ( V_7 -> V_13 . type == V_21 ) {
F_17 ( V_7 , 3 , L_22 ) ;
return 0 ;
}
if ( F_51 ( V_7 , V_132 ) ) {
F_17 ( V_7 , 3 , L_23 ) ;
return 0 ;
}
V_109 = F_52 ( sizeof( struct V_127 ) , V_133 ) ;
if ( V_109 ) {
V_109 -> V_129 = V_129 ;
V_11 = F_48 ( V_7 , V_129 , V_130 ) ;
if ( V_11 ) {
F_34 ( V_109 ) ;
return V_11 ;
}
F_31 ( & V_7 -> V_128 ) ;
F_53 ( & V_109 -> V_134 , & V_7 -> V_135 ) ;
F_35 ( & V_7 -> V_128 ) ;
} else {
return - V_54 ;
}
return 0 ;
}
static int F_54 ( struct V_1 * V_2 ,
T_5 V_131 , T_6 V_129 )
{
struct V_127 * V_109 , * V_136 = NULL ;
struct V_6 * V_7 = V_2 -> V_8 ;
int V_11 = 0 ;
F_7 ( V_7 , 4 , L_24 , V_129 ) ;
if ( V_7 -> V_13 . type == V_21 ) {
F_17 ( V_7 , 3 , L_25 ) ;
return 0 ;
}
if ( F_51 ( V_7 , V_132 ) ) {
F_17 ( V_7 , 3 , L_26 ) ;
return 0 ;
}
F_31 ( & V_7 -> V_128 ) ;
F_10 (id, &card->vid_list, list) {
if ( V_109 -> V_129 == V_129 ) {
F_55 ( & V_109 -> V_134 ) ;
V_136 = V_109 ;
break;
}
}
F_35 ( & V_7 -> V_128 ) ;
if ( V_136 ) {
V_11 = F_48 ( V_7 , V_129 , V_137 ) ;
F_34 ( V_136 ) ;
}
F_56 ( V_7 -> V_2 ) ;
return V_11 ;
}
static void F_57 ( struct V_6 * V_7 , int V_138 )
{
F_58 ( V_139 , 2 , L_27 ) ;
F_59 ( V_139 , 2 , & V_7 , sizeof( void * ) ) ;
F_60 ( V_7 , 0 , 1 ) ;
if ( V_7 -> V_140 . V_141 == V_142 &&
V_7 -> V_143 . V_141 == V_142 &&
( V_7 -> V_141 == V_144 ) ) {
if ( V_138 &&
V_7 -> V_13 . type != V_14 ) {
F_61 ( V_7 -> V_2 ) ;
} else {
F_62 () ;
F_63 ( V_7 -> V_2 ) ;
F_64 () ;
}
V_7 -> V_13 . V_69 &= ~ V_70 ;
V_7 -> V_141 = V_145 ;
}
if ( V_7 -> V_141 == V_145 ) {
F_30 ( V_7 ) ;
F_65 ( V_7 ) ;
V_7 -> V_141 = V_146 ;
}
if ( V_7 -> V_141 == V_146 ) {
F_66 ( V_7 , 0 ) ;
F_67 ( V_7 ) ;
F_68 ( V_7 ) ;
V_7 -> V_141 = V_147 ;
}
if ( V_7 -> V_141 == V_147 ) {
F_69 ( & V_7 -> V_140 ) ;
F_69 ( & V_7 -> V_143 ) ;
}
}
static int F_70 ( struct V_6 * V_7 ,
int V_148 , int * V_149 )
{
int V_150 = 0 ;
struct V_86 * V_87 ;
struct V_91 * V_92 ;
unsigned int V_115 ;
* V_149 = 0 ;
F_71 ( ! V_148 ) ;
while ( V_148 ) {
V_87 = F_72 ( V_7 ,
& V_7 -> V_151 . V_152 -> V_153 [ V_7 -> V_154 . V_155 ] ,
& V_7 -> V_154 . V_156 , & V_7 -> V_154 . V_157 , & V_92 ) ;
if ( ! V_87 ) {
* V_149 = 1 ;
break;
}
V_87 -> V_2 = V_7 -> V_2 ;
switch ( V_92 -> V_92 . V_97 . V_109 ) {
case V_110 :
V_87 -> V_158 = V_159 ;
V_87 -> V_95 = F_73 ( V_87 , V_87 -> V_2 ) ;
if ( ( V_7 -> V_2 -> V_160 & V_161 )
&& ( ( V_92 -> V_92 . V_97 . V_32 [ 1 ] &
( V_100 |
V_99 ) ) ==
( V_100 |
V_99 ) ) )
V_87 -> V_162 = V_163 ;
else
V_87 -> V_162 = V_164 ;
if ( V_87 -> V_95 == F_74 ( V_165 ) )
* ( ( V_166 * ) V_87 -> V_167 ) = ++ V_7 -> V_168 . V_169 ;
V_115 = V_87 -> V_115 ;
F_75 ( & V_7 -> V_170 , V_87 ) ;
break;
case V_171 :
if ( V_7 -> V_13 . type == V_14 ) {
F_76 ( V_87 , sizeof( struct V_91 ) ) ;
F_77 ( V_87 , V_92 ,
sizeof( struct V_91 ) ) ;
V_115 = V_87 -> V_115 ;
V_7 -> V_172 . V_173 ( V_87 ) ;
break;
}
default:
F_78 ( V_87 ) ;
F_17 ( V_7 , 3 , L_28 ) ;
F_59 ( V_174 , 3 , V_92 , V_175 ) ;
continue;
}
V_150 ++ ;
V_148 -- ;
V_7 -> V_176 . V_177 ++ ;
V_7 -> V_176 . V_178 += V_115 ;
}
return V_150 ;
}
static int F_79 ( struct V_179 * V_170 , int V_148 )
{
struct V_6 * V_7 = F_80 ( V_170 , struct V_6 , V_170 ) ;
int V_150 = 0 ;
struct V_180 * V_181 ;
int V_149 ;
int V_182 = V_148 ;
if ( V_7 -> V_102 . V_103 ) {
V_7 -> V_104 . V_183 ++ ;
V_7 -> V_104 . V_184 = F_81 () ;
}
while ( 1 ) {
if ( ! V_7 -> V_154 . V_185 ) {
V_7 -> V_154 . V_186 = 0 ;
V_7 -> V_154 . V_185 = F_82 (
V_7 -> V_63 . V_187 , 0 , & V_7 -> V_154 . V_155 ,
& V_7 -> V_154 . V_186 ) ;
if ( V_7 -> V_154 . V_185 <= 0 ) {
V_7 -> V_154 . V_185 = 0 ;
break;
}
V_7 -> V_154 . V_156 =
& V_7 -> V_151 . V_152 -> V_153 [ V_7 -> V_154 . V_155 ]
. V_181 -> V_188 [ 0 ] ;
V_7 -> V_154 . V_157 = 0 ;
}
while ( V_7 -> V_154 . V_185 ) {
V_181 = & V_7 -> V_151 . V_152 -> V_153 [ V_7 -> V_154 . V_155 ] ;
if ( ! ( V_7 -> V_154 . V_186 &&
F_83 ( V_7 , V_181 -> V_181 ,
V_7 -> V_154 . V_186 , L_29 ) ) )
V_150 += F_70 (
V_7 , V_182 , & V_149 ) ;
else
V_149 = 1 ;
if ( V_149 ) {
if ( V_7 -> V_102 . V_103 )
V_7 -> V_104 . V_189 ++ ;
F_84 ( V_7 ,
V_181 -> V_190 ) ;
F_85 ( V_7 , V_7 -> V_154 . V_155 ) ;
V_7 -> V_154 . V_185 -- ;
if ( V_7 -> V_154 . V_185 ) {
V_7 -> V_154 . V_155 =
( V_7 -> V_154 . V_155 + 1 ) %
V_191 ;
V_7 -> V_154 . V_156 =
& V_7 -> V_151 . V_152
-> V_153 [ V_7 -> V_154 . V_155 ]
. V_181 -> V_188 [ 0 ] ;
V_7 -> V_154 . V_157 = 0 ;
}
}
if ( V_150 >= V_148 )
goto V_192;
else
V_182 = V_148 - V_150 ;
}
}
F_86 ( V_170 ) ;
if ( F_87 ( V_7 -> V_63 . V_187 , 0 ) )
F_88 ( & V_7 -> V_170 ) ;
V_192:
if ( V_7 -> V_102 . V_103 )
V_7 -> V_104 . V_193 += F_81 () -
V_7 -> V_104 . V_184 ;
return V_150 ;
}
static int F_89 ( struct V_6 * V_7 )
{
int V_11 = 0 ;
char V_194 [] = { 0x02 , 0x00 , 0x00 } ;
F_58 ( V_139 , 2 , L_30 ) ;
F_90 ( V_139 , 2 , L_31 , F_91 ( V_7 ) ) ;
if ( F_92 ( V_7 , V_195 ) ) {
V_11 = F_93 ( V_7 ) ;
if ( V_11 ) {
F_25 ( 2 , L_32
L_33 ,
F_91 ( V_7 ) , V_11 ) ;
}
}
if ( V_7 -> V_13 . type == V_196 ||
V_7 -> V_13 . type == V_21 ||
V_7 -> V_13 . type == V_22 ||
V_7 -> V_13 . V_23 ) {
V_11 = F_94 ( V_7 ) ;
if ( V_11 ) {
F_25 ( 2 , L_34
L_35 , F_91 ( V_7 ) , V_11 ) ;
F_90 ( V_139 , 2 , L_36 , V_11 ) ;
return V_11 ;
}
F_59 ( V_139 , 2 , V_7 -> V_2 -> V_71 , V_67 ) ;
} else {
F_95 ( V_7 -> V_2 -> V_71 ) ;
memcpy ( V_7 -> V_2 -> V_71 , V_194 , 3 ) ;
}
return 0 ;
}
static int F_96 ( struct V_1 * V_2 , void * V_197 )
{
struct V_198 * V_85 = V_197 ;
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
F_97 ( V_7 , 3 , V_85 -> V_199 , V_67 ) ;
if ( F_51 ( V_7 , V_132 ) ) {
F_17 ( V_7 , 3 , L_40 ) ;
return - V_200 ;
}
V_11 = F_23 ( V_7 , & V_7 -> V_2 -> V_71 [ 0 ] ) ;
if ( ! V_11 || ( V_11 == - V_53 ) )
V_11 = F_20 ( V_7 , V_85 -> V_199 ) ;
return V_11 ? - V_27 : 0 ;
}
static void F_98 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
enum V_201 V_202 ;
int V_203 ;
int V_11 ;
F_17 ( V_7 , 3 , L_41 ) ;
if ( ! V_7 -> V_102 . V_204 . V_205 )
return;
V_202 = ( V_2 -> V_32 & V_206 ) ? V_207
: V_208 ;
if ( V_202 == V_7 -> V_13 . V_202 )
return;
if ( V_202 == V_207 ) {
if ( V_7 -> V_102 . V_204 . V_209 )
V_203 = V_210 ;
else
V_203 = V_211 ;
} else
V_203 = V_212 ;
V_11 = F_99 ( V_7 , V_203 ) ;
F_90 ( V_139 , 2 , L_42 ,
( V_202 == V_207 ) ? '+' : '-' , V_11 ) ;
if ( ! V_11 ) {
V_7 -> V_102 . V_204 . V_203 = V_203 ;
V_7 -> V_13 . V_202 = V_202 ;
}
}
static void
F_100 ( struct V_6 * V_7 , struct V_213 * V_214 , T_4 V_78 )
{
struct V_77 * V_56 ;
F_101 (card->mac_htable, mac, hnode,
qeth_l2_mac_hash(ha->addr)) {
if ( V_78 == V_56 -> V_78 &&
! memcmp ( V_214 -> V_85 , V_56 -> V_79 , V_67 ) ) {
V_56 -> V_215 = V_216 ;
return;
}
}
V_56 = F_102 ( sizeof( struct V_77 ) , V_133 ) ;
if ( ! V_56 )
return;
memcpy ( V_56 -> V_79 , V_214 -> V_85 , V_67 ) ;
V_56 -> V_78 = V_78 ;
V_56 -> V_215 = V_217 ;
F_103 ( V_7 -> V_218 , & V_56 -> V_84 ,
F_36 ( V_56 -> V_79 ) ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_213 * V_214 ;
struct V_77 * V_56 ;
struct V_80 * V_81 ;
int V_82 ;
int V_11 ;
if ( V_7 -> V_13 . type == V_14 )
return;
F_17 ( V_7 , 3 , L_43 ) ;
if ( F_104 ( V_7 , V_132 ) &&
( V_7 -> V_141 != V_144 ) )
return;
F_31 ( & V_7 -> V_83 ) ;
F_105 (ha, dev)
F_100 ( V_7 , V_214 , 0 ) ;
F_106 (ha, dev)
F_100 ( V_7 , V_214 , 1 ) ;
F_32 (card->mac_htable, i, tmp, mac, hnode) {
if ( V_56 -> V_215 == V_219 ) {
F_29 ( V_7 , V_56 ) ;
F_33 ( & V_56 -> V_84 ) ;
F_34 ( V_56 ) ;
} else if ( V_56 -> V_215 == V_217 ) {
V_11 = F_28 ( V_7 , V_56 ) ;
if ( V_11 ) {
F_33 ( & V_56 -> V_84 ) ;
F_34 ( V_56 ) ;
} else
V_56 -> V_215 = V_219 ;
} else
V_56 -> V_215 = V_219 ;
}
F_35 ( & V_7 -> V_83 ) ;
if ( F_107 ( V_7 , V_220 ) )
F_108 ( V_7 ) ;
else
F_98 ( V_7 ) ;
}
static int F_109 ( struct V_86 * V_87 , struct V_1 * V_2 )
{
int V_11 ;
struct V_91 * V_92 = NULL ;
int V_221 = 0 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_86 * V_222 = V_87 ;
int V_106 = F_38 ( V_7 , V_87 ) ;
struct V_223 * V_224 ;
int V_225 = V_87 -> V_115 ;
int V_226 = - 1 ;
int V_227 = 0 ;
int V_228 = 0 ;
int V_229 ;
if ( V_7 -> V_151 . V_230 || ( V_106 &&
V_7 -> V_13 . V_231 ) )
V_224 = V_7 -> V_151 . V_232 [ F_110 ( V_7 , V_87 ,
F_111 ( V_87 ) , V_106 ) ] ;
else
V_224 = V_7 -> V_151 . V_232 [ V_7 -> V_151 . V_233 ] ;
if ( ( V_7 -> V_141 != V_144 ) || ! V_7 -> V_234 ) {
V_7 -> V_176 . V_235 ++ ;
goto V_236;
}
if ( ( V_7 -> V_13 . type == V_14 ) &&
( V_87 -> V_95 == F_74 ( V_237 ) ) )
goto V_236;
if ( V_7 -> V_102 . V_103 ) {
V_7 -> V_104 . V_238 ++ ;
V_7 -> V_104 . V_239 = F_81 () ;
}
F_112 ( V_2 ) ;
if ( ( V_7 -> V_13 . type != V_196 ) &&
! F_113 ( V_7 , V_222 , 0 , 0 ) ) {
int V_240 = F_114 ( V_222 ) ;
if ( V_7 -> V_102 . V_103 ) {
if ( V_240 )
V_7 -> V_104 . V_241 ++ ;
else
V_7 -> V_104 . V_242 ++ ;
}
if ( V_240 )
goto V_236;
}
if ( V_7 -> V_13 . type == V_14 )
V_92 = (struct V_91 * ) V_87 -> V_63 ;
else {
if ( V_7 -> V_13 . type == V_196 ) {
V_222 = V_87 ;
V_226 = V_243 ;
V_228 = V_243 ;
V_92 = F_115 ( V_244 ,
V_133 ) ;
if ( ! V_92 )
goto V_236;
V_227 ++ ;
F_116 ( V_222 ) ;
F_43 ( V_7 , V_92 , V_222 , V_106 ) ;
V_92 -> V_92 . V_97 . V_114 = V_222 -> V_115 ;
memcpy ( ( ( char * ) V_92 ) + sizeof( struct V_91 ) ,
F_44 ( V_222 ) , V_243 ) ;
} else {
V_222 = F_117 ( V_87 ,
sizeof( struct V_91 ) ) ;
if ( ! V_222 )
goto V_236;
V_92 = (struct V_91 * ) F_76 ( V_222 ,
sizeof( struct V_91 ) ) ;
F_118 ( V_222 , sizeof( struct V_91 ) ) ;
F_43 ( V_7 , V_92 , V_222 , V_106 ) ;
if ( V_222 -> V_162 == V_245 )
F_41 ( V_7 , V_92 , V_222 ) ;
}
}
V_221 = F_113 ( V_7 , V_222 , V_227 ,
( V_226 > 0 ) ? V_226 : 0 ) ;
if ( ! V_221 ) {
if ( V_226 >= 0 )
F_119 ( V_244 , V_92 ) ;
goto V_236;
}
if ( V_7 -> V_13 . type != V_196 ) {
if ( F_120 ( V_222 , & V_92 ,
sizeof( struct V_246 ) ) )
goto V_236;
V_11 = F_121 ( V_7 , V_224 , V_222 , V_92 ,
V_221 ) ;
} else
V_11 = F_122 ( V_7 , V_224 , V_222 , V_92 ,
V_221 , V_226 , V_228 ) ;
if ( ! V_11 ) {
V_7 -> V_176 . V_247 ++ ;
V_7 -> V_176 . V_225 += V_225 ;
if ( V_7 -> V_102 . V_103 ) {
V_229 = F_123 ( V_222 ) -> V_229 ;
if ( V_229 ) {
V_7 -> V_104 . V_248 ++ ;
V_7 -> V_104 . V_249 += V_229 + 1 ;
}
}
if ( V_222 != V_87 )
F_78 ( V_87 ) ;
V_11 = V_250 ;
} else {
if ( V_226 >= 0 )
F_119 ( V_244 , V_92 ) ;
if ( V_11 == - V_251 ) {
if ( V_222 != V_87 )
F_78 ( V_222 ) ;
return V_252 ;
} else
goto V_236;
}
F_124 ( V_2 ) ;
if ( V_7 -> V_102 . V_103 )
V_7 -> V_104 . V_253 += F_81 () -
V_7 -> V_104 . V_239 ;
return V_11 ;
V_236:
V_7 -> V_176 . V_254 ++ ;
V_7 -> V_176 . V_255 ++ ;
if ( ( V_222 != V_87 ) && V_222 )
F_78 ( V_222 ) ;
F_78 ( V_87 ) ;
F_124 ( V_2 ) ;
return V_250 ;
}
static int F_125 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_11 = 0 ;
F_17 ( V_7 , 4 , L_44 ) ;
if ( V_7 -> V_141 == V_144 )
return V_11 ;
if ( V_7 -> V_141 != V_145 )
return - V_12 ;
if ( ( V_7 -> V_13 . type != V_14 ) &&
( ! ( V_7 -> V_13 . V_69 & V_70 ) ) ) {
F_17 ( V_7 , 4 , L_45 ) ;
return - V_15 ;
}
V_7 -> V_63 . V_141 = V_142 ;
V_7 -> V_141 = V_144 ;
F_126 ( V_2 ) ;
if ( F_127 ( V_7 -> V_63 . V_187 , 0 ) >= 0 ) {
F_128 ( & V_7 -> V_170 ) ;
F_88 ( & V_7 -> V_170 ) ;
} else
V_11 = - V_55 ;
return V_11 ;
}
static int F_129 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_17 ( V_7 , 5 , L_46 ) ;
if ( F_51 ( V_7 , V_132 ) ) {
F_17 ( V_7 , 3 , L_47 ) ;
return - V_200 ;
}
return F_125 ( V_2 ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_17 ( V_7 , 4 , L_48 ) ;
F_130 ( V_2 ) ;
if ( V_7 -> V_141 == V_144 ) {
V_7 -> V_141 = V_145 ;
F_131 ( & V_7 -> V_170 ) ;
}
return 0 ;
}
static int F_132 ( struct V_256 * V_72 )
{
struct V_6 * V_7 = F_133 ( & V_72 -> V_2 ) ;
F_134 ( & V_72 -> V_2 ) ;
F_135 ( & V_7 -> V_135 ) ;
F_136 ( V_7 -> V_218 ) ;
V_7 -> V_102 . V_257 = 1 ;
V_7 -> V_13 . V_258 = 0 ;
return 0 ;
}
static void F_137 ( struct V_256 * V_259 )
{
struct V_6 * V_7 = F_133 ( & V_259 -> V_2 ) ;
F_138 ( & V_259 -> V_2 ) ;
F_60 ( V_7 , 0 , 1 ) ;
F_139 ( V_7 -> V_260 , F_104 ( V_7 , 0xffffffff ) == 0 ) ;
if ( V_259 -> V_141 == V_261 )
F_140 ( V_259 ) ;
if ( V_7 -> V_2 ) {
F_141 ( & V_7 -> V_170 ) ;
F_142 ( V_7 -> V_2 ) ;
V_7 -> V_2 = NULL ;
}
return;
}
static int F_143 ( struct V_6 * V_7 )
{
switch ( V_7 -> V_13 . type ) {
case V_196 :
V_7 -> V_2 = F_144 ( 0 , L_49 , V_262 ,
V_263 ) ;
break;
case V_14 :
V_7 -> V_2 = F_144 ( 0 , L_50 , V_262 ,
V_263 ) ;
V_7 -> V_2 -> V_32 |= V_264 ;
break;
default:
V_7 -> V_2 = F_145 ( 0 ) ;
}
if ( ! V_7 -> V_2 )
return - V_12 ;
V_7 -> V_2 -> V_8 = V_7 ;
V_7 -> V_2 -> V_265 = V_266 ;
V_7 -> V_2 -> V_267 = V_7 -> V_13 . V_268 ;
V_7 -> V_2 -> V_269 = 64 ;
V_7 -> V_2 -> V_270 = V_271 ;
V_7 -> V_2 -> V_272 = & V_273 ;
V_7 -> V_2 -> V_274 =
( V_7 -> V_13 . type != V_14 ) ?
& V_275 : & V_276 ;
V_7 -> V_2 -> V_160 |= V_277 ;
if ( V_7 -> V_13 . type == V_20 && ! V_7 -> V_13 . V_23 ) {
V_7 -> V_2 -> V_278 = V_279 ;
V_7 -> V_2 -> V_280 = V_279 ;
if ( F_92 ( V_7 , V_281 ) ) {
V_7 -> V_2 -> V_278 |= V_282 ;
V_7 -> V_2 -> V_280 |= V_282 ;
}
if ( F_92 ( V_7 , V_283 ) ) {
V_7 -> V_2 -> V_278 |= V_161 ;
V_7 -> V_2 -> V_280 |= V_161 ;
}
}
V_7 -> V_13 . V_284 = 1 ;
F_89 ( V_7 ) ;
V_7 -> V_2 -> V_285 = ( F_146 ( V_7 ) - 1 ) *
V_286 ;
F_147 ( V_7 -> V_2 , & V_7 -> V_72 -> V_2 ) ;
F_148 ( V_7 -> V_2 , & V_7 -> V_170 , F_79 , V_287 ) ;
F_149 ( V_7 -> V_2 ) ;
return F_150 ( V_7 -> V_2 ) ;
}
static int F_151 ( struct V_6 * V_7 )
{
if ( F_152 ( V_7 , 0 ) )
return - V_12 ;
return 0 ;
}
static int F_153 ( struct V_256 * V_72 , int V_138 )
{
struct V_6 * V_7 = F_133 ( & V_72 -> V_2 ) ;
int V_11 = 0 ;
enum V_288 V_289 ;
F_154 ( & V_7 -> V_290 ) ;
F_154 ( & V_7 -> V_291 ) ;
F_58 ( V_139 , 2 , L_51 ) ;
F_59 ( V_139 , 2 , & V_7 , sizeof( void * ) ) ;
V_289 = V_7 -> V_141 ;
V_11 = F_155 ( V_7 ) ;
if ( V_11 ) {
F_90 ( V_139 , 2 , L_52 , V_11 ) ;
V_11 = - V_12 ;
goto V_292;
}
F_156 ( V_7 ) ;
if ( V_7 -> V_102 . V_204 . V_293 )
F_21 ( & V_7 -> V_72 -> V_2 ,
L_53 ) ;
F_157 ( V_7 ) ;
if ( ! V_7 -> V_2 && F_143 ( V_7 ) ) {
V_11 = - V_12 ;
goto V_292;
}
if ( V_7 -> V_13 . type != V_14 )
F_20 ( V_7 , & V_7 -> V_2 -> V_71 [ 0 ] ) ;
if ( F_158 ( V_7 , V_294 ) ) {
if ( V_7 -> V_13 . V_258 &&
F_159 ( V_7 , V_295 ) )
V_7 -> V_13 . V_258 = 0 ;
} else
V_7 -> V_13 . V_258 = 0 ;
F_160 ( V_7 ) ;
V_7 -> V_141 = V_146 ;
memset ( & V_7 -> V_154 , 0 , sizeof( struct V_296 ) ) ;
F_161 ( V_7 ) ;
F_58 ( V_139 , 2 , L_54 ) ;
if ( ( V_7 -> V_13 . type == V_20 ) ||
( V_7 -> V_13 . type == V_22 ) ) {
V_11 = F_151 ( V_7 ) ;
if ( V_11 )
goto V_292;
}
if ( V_7 -> V_13 . type != V_14 &&
V_7 -> V_13 . type != V_21 )
F_49 ( V_7 ) ;
F_130 ( V_7 -> V_2 ) ;
V_11 = F_162 ( V_7 ) ;
if ( V_11 ) {
F_90 ( V_139 , 2 , L_55 , V_11 ) ;
V_11 = - V_12 ;
goto V_292;
}
V_7 -> V_141 = V_145 ;
if ( V_7 -> V_234 )
F_163 ( V_7 -> V_2 ) ;
else
F_149 ( V_7 -> V_2 ) ;
F_60 ( V_7 , 0xffffffff , 0 ) ;
if ( V_289 == V_297 ) {
if ( V_138 &&
V_7 -> V_13 . type != V_14 ) {
F_125 ( V_7 -> V_2 ) ;
} else {
F_62 () ;
F_164 ( V_7 -> V_2 ) ;
F_64 () ;
}
F_56 ( V_7 -> V_2 ) ;
F_62 () ;
F_165 ( V_7 -> V_2 ) ;
F_64 () ;
}
F_166 ( & V_72 -> V_2 . V_298 , V_299 ) ;
F_167 ( & V_7 -> V_291 ) ;
F_167 ( & V_7 -> V_290 ) ;
return 0 ;
V_292:
F_57 ( V_7 , 0 ) ;
F_168 ( F_169 ( V_7 ) ) ;
F_168 ( F_170 ( V_7 ) ) ;
F_168 ( F_14 ( V_7 ) ) ;
F_171 ( F_169 ( V_7 ) ) ;
if ( V_289 == V_297 )
V_7 -> V_141 = V_297 ;
else
V_7 -> V_141 = V_147 ;
F_167 ( & V_7 -> V_291 ) ;
F_167 ( & V_7 -> V_290 ) ;
return V_11 ;
}
static int F_172 ( struct V_256 * V_72 )
{
return F_153 ( V_72 , 0 ) ;
}
static int F_173 ( struct V_256 * V_259 ,
int V_138 )
{
struct V_6 * V_7 = F_133 ( & V_259 -> V_2 ) ;
int V_11 = 0 , V_300 = 0 , V_301 = 0 ;
enum V_288 V_289 ;
F_154 ( & V_7 -> V_290 ) ;
F_154 ( & V_7 -> V_291 ) ;
F_58 ( V_139 , 3 , L_56 ) ;
F_59 ( V_139 , 3 , & V_7 , sizeof( void * ) ) ;
if ( V_7 -> V_2 && F_174 ( V_7 -> V_2 ) )
F_149 ( V_7 -> V_2 ) ;
V_289 = V_7 -> V_141 ;
if ( ( ! V_138 && V_7 -> V_13 . V_258 ) || V_7 -> V_13 . V_258 == 2 ) {
F_159 ( V_7 , V_302 ) ;
V_7 -> V_13 . V_258 = 1 ;
}
F_57 ( V_7 , V_138 ) ;
V_11 = F_168 ( F_169 ( V_7 ) ) ;
V_300 = F_168 ( F_170 ( V_7 ) ) ;
V_301 = F_168 ( F_14 ( V_7 ) ) ;
if ( ! V_11 )
V_11 = ( V_300 ) ? V_300 : V_301 ;
if ( V_11 )
F_90 ( V_139 , 2 , L_57 , V_11 ) ;
F_171 ( F_169 ( V_7 ) ) ;
if ( V_289 == V_144 )
V_7 -> V_141 = V_297 ;
F_166 ( & V_259 -> V_2 . V_298 , V_299 ) ;
F_167 ( & V_7 -> V_291 ) ;
F_167 ( & V_7 -> V_290 ) ;
return 0 ;
}
static int F_140 ( struct V_256 * V_259 )
{
return F_173 ( V_259 , 0 ) ;
}
static int F_175 ( void * V_303 )
{
struct V_6 * V_7 ;
int V_11 = 0 ;
V_7 = (struct V_6 * ) V_303 ;
F_17 ( V_7 , 2 , L_58 ) ;
if ( ! F_176 ( V_7 , V_132 ) )
return 0 ;
F_17 ( V_7 , 2 , L_59 ) ;
F_22 ( & V_7 -> V_72 -> V_2 ,
L_60 ) ;
F_177 ( V_7 ) ;
F_173 ( V_7 -> V_72 , 1 ) ;
V_11 = F_153 ( V_7 -> V_72 , 1 ) ;
if ( ! V_11 )
F_21 ( & V_7 -> V_72 -> V_2 ,
L_61 ) ;
else {
F_178 ( V_7 ) ;
F_22 ( & V_7 -> V_72 -> V_2 , L_62
L_63 ) ;
}
F_179 ( V_7 ) ;
F_180 ( V_7 , V_132 ) ;
F_181 ( V_7 , V_132 ) ;
return 0 ;
}
static int T_7 F_182 ( void )
{
F_183 ( L_64 ) ;
return 0 ;
}
static void T_8 F_184 ( void )
{
F_183 ( L_65 ) ;
}
static void F_185 ( struct V_256 * V_72 )
{
struct V_6 * V_7 = F_133 ( & V_72 -> V_2 ) ;
F_60 ( V_7 , 0 , 1 ) ;
if ( ( V_72 -> V_141 == V_261 ) && V_7 -> V_13 . V_258 )
F_159 ( V_7 , V_302 ) ;
F_66 ( V_7 , 0 ) ;
F_67 ( V_7 ) ;
F_171 ( F_169 ( V_7 ) ) ;
}
static int F_186 ( struct V_256 * V_72 )
{
struct V_6 * V_7 = F_133 ( & V_72 -> V_2 ) ;
if ( V_7 -> V_2 )
F_187 ( V_7 -> V_2 ) ;
F_60 ( V_7 , 0 , 1 ) ;
F_139 ( V_7 -> V_260 , F_104 ( V_7 , 0xffffffff ) == 0 ) ;
if ( V_72 -> V_141 == V_304 )
return 0 ;
if ( V_7 -> V_141 == V_144 ) {
if ( V_7 -> V_13 . V_258 )
F_159 ( V_7 , V_302 ) ;
F_173 ( V_7 -> V_72 , 1 ) ;
} else
F_173 ( V_7 -> V_72 , 0 ) ;
return 0 ;
}
static int F_188 ( struct V_256 * V_72 )
{
struct V_6 * V_7 = F_133 ( & V_72 -> V_2 ) ;
int V_11 = 0 ;
if ( V_72 -> V_141 == V_304 )
goto V_192;
if ( V_7 -> V_141 == V_297 ) {
V_11 = F_153 ( V_7 -> V_72 , 1 ) ;
if ( V_11 ) {
F_62 () ;
F_63 ( V_7 -> V_2 ) ;
F_64 () ;
}
} else
V_11 = F_153 ( V_7 -> V_72 , 0 ) ;
V_192:
F_60 ( V_7 , 0xffffffff , 0 ) ;
if ( V_7 -> V_2 )
F_189 ( V_7 -> V_2 ) ;
if ( V_11 )
F_22 ( & V_7 -> V_72 -> V_2 , L_62
L_63 ) ;
return V_11 ;
}
static int F_190 ( struct V_6 * V_7 ,
struct V_59 * V_5 )
{
switch ( V_5 -> V_92 . V_126 ) {
case V_305 :
case V_306 :
if ( V_5 -> V_63 . V_204 . V_92 . V_307 ==
V_308 ) {
F_191 ( V_7 , V_5 ) ;
return 0 ;
} else
return 1 ;
case V_309 :
F_192 ( V_7 , V_5 ) ;
return 0 ;
default:
return 1 ;
}
}
static int F_193 ( struct V_6 * V_7 , int V_115 ,
struct V_60 * V_61 )
{
unsigned long V_32 ;
int V_11 = 0 ;
F_17 ( V_7 , 5 , L_66 ) ;
F_139 ( V_7 -> V_260 ,
F_194 ( & V_7 -> V_143 . V_310 , 0 , 1 ) == 0 ) ;
F_195 ( V_7 , V_115 , V_61 ) ;
F_17 ( V_7 , 6 , L_67 ) ;
F_196 ( F_197 ( V_7 -> V_143 . V_187 ) , V_32 ) ;
V_11 = F_198 ( V_7 -> V_143 . V_187 , & V_7 -> V_143 . V_311 ,
( V_312 ) V_61 , 0 , 0 ) ;
F_199 ( F_197 ( V_7 -> V_143 . V_187 ) , V_32 ) ;
if ( V_11 ) {
F_25 ( 2 , L_68
L_69 , V_11 ) ;
F_7 ( V_7 , 2 , L_70 , V_11 ) ;
F_200 ( V_61 -> V_313 , V_61 ) ;
F_201 ( & V_7 -> V_143 . V_310 , 0 ) ;
F_202 ( & V_7 -> V_260 ) ;
}
return V_11 ;
}
static int F_203 ( struct V_6 * V_7 ,
struct V_60 * V_61 , int V_314 )
{
T_6 V_315 , V_316 ;
F_17 ( V_7 , 4 , L_71 ) ;
F_204 ( V_7 , V_61 , V_317 ) ;
V_315 = ( T_6 ) ( V_64 + V_314 ) ;
V_316 = ( T_6 ) V_314 ;
memcpy ( F_205 ( V_61 -> V_63 ) , & V_315 , 2 ) ;
memcpy ( F_206 ( V_61 -> V_63 ) , & V_316 , 2 ) ;
memcpy ( F_207 ( V_61 -> V_63 ) , & V_316 , 2 ) ;
memcpy ( F_208 ( V_61 -> V_63 ) , & V_316 , 2 ) ;
return F_193 ( V_7 , V_315 , V_61 ) ;
}
int F_209 ( struct V_1 * V_2 , void * V_63 , int V_314 )
{
struct V_60 * V_61 ;
struct V_6 * V_7 ;
int V_11 ;
if ( ! V_2 )
return - V_12 ;
V_7 = V_2 -> V_8 ;
if ( ! V_7 )
return - V_12 ;
F_17 ( V_7 , 2 , L_72 ) ;
if ( ! F_2 ( V_7 ) )
return - V_12 ;
V_61 = F_210 ( & V_7 -> V_143 ) ;
memcpy ( V_61 -> V_63 + V_64 , V_63 , V_314 ) ;
V_11 = F_203 ( V_7 , V_61 , V_314 ) ;
return V_11 ;
}
int F_211 ( unsigned char * V_36 , struct V_1 * * V_2 ,
int (* F_212)( struct V_1 * , void * ) ,
int (* V_173)( struct V_86 * ) )
{
struct V_6 * V_7 ;
* V_2 = F_12 ( V_36 ) ;
if ( * V_2 == NULL )
return - V_12 ;
V_7 = ( * V_2 ) -> V_8 ;
if ( ! V_7 )
return - V_12 ;
F_17 ( V_7 , 2 , L_73 ) ;
if ( ( F_212 == NULL ) || ( V_173 == NULL ) )
return - V_27 ;
V_7 -> V_172 . F_212 = F_212 ;
V_7 -> V_172 . V_173 = V_173 ;
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
F_17 ( V_7 , 2 , L_74 ) ;
V_7 -> V_172 . F_212 = NULL ;
V_7 -> V_172 . V_173 = NULL ;
return;
}
static void F_214 ( struct V_6 * V_7 ,
enum V_318 V_319 ,
T_4 V_320 , struct V_321 * V_322 , struct V_323 * V_324 )
{
char V_325 [ 7 ] [ 32 ] ;
char * V_326 [ 8 ] ;
int V_82 = 0 ;
switch ( V_319 ) {
case V_327 :
snprintf ( V_325 [ V_82 ] , sizeof( V_325 [ V_82 ] ) , L_75 ,
( V_320 & V_328 )
? L_76 : L_77 ) ;
V_326 [ V_82 ] = V_325 [ V_82 ] ; V_82 ++ ;
if ( V_320 & V_329 ) {
snprintf ( V_325 [ V_82 ] , sizeof( V_325 [ V_82 ] ) , L_78 ,
V_324 -> V_330 ) ;
V_326 [ V_82 ] = V_325 [ V_82 ] ; V_82 ++ ;
}
if ( V_320 & V_331 ) {
snprintf ( V_325 [ V_82 ] , sizeof( V_325 [ V_82 ] ) , L_79 ,
V_324 -> V_56 ) ;
V_326 [ V_82 ] = V_325 [ V_82 ] ; V_82 ++ ;
}
snprintf ( V_325 [ V_82 ] , sizeof( V_325 [ V_82 ] ) , L_80 ,
V_322 -> V_332 , V_322 -> V_333 , V_322 -> V_334 ) ;
V_326 [ V_82 ] = V_325 [ V_82 ] ; V_82 ++ ;
snprintf ( V_325 [ V_82 ] , sizeof( V_325 [ V_82 ] ) , L_81 , V_322 -> V_335 ) ;
V_326 [ V_82 ] = V_325 [ V_82 ] ; V_82 ++ ;
snprintf ( V_325 [ V_82 ] , sizeof( V_325 [ V_82 ] ) , L_82 ,
V_322 -> V_336 ) ;
V_326 [ V_82 ] = V_325 [ V_82 ] ; V_82 ++ ;
snprintf ( V_325 [ V_82 ] , sizeof( V_325 [ V_82 ] ) , L_83 , V_322 -> V_337 ) ;
V_326 [ V_82 ] = V_325 [ V_82 ] ; V_82 ++ ;
break;
case V_338 :
snprintf ( V_325 [ V_82 ] , sizeof( V_325 [ V_82 ] ) , L_84 ) ;
V_326 [ V_82 ] = V_325 [ V_82 ] ; V_82 ++ ;
break;
case V_339 :
snprintf ( V_325 [ V_82 ] , sizeof( V_325 [ V_82 ] ) , L_85 ) ;
V_326 [ V_82 ] = V_325 [ V_82 ] ; V_82 ++ ;
break;
}
V_326 [ V_82 ] = NULL ;
F_215 ( & V_7 -> V_72 -> V_2 . V_298 , V_299 , V_326 ) ;
}
static void F_216 ( struct V_340 * V_341 )
{
struct V_342 * V_63 =
F_80 ( V_341 , struct V_342 , V_343 ) ;
struct V_344 * V_345 = & V_63 -> V_346 . V_345 [ 0 ] ;
char V_347 [ 32 ] ;
char V_348 [ 32 ] ;
char V_349 [ 32 ] ;
char * V_326 [] = {
V_347 ,
V_348 ,
V_349 ,
NULL
} ;
F_154 ( & V_63 -> V_7 -> V_291 ) ;
V_63 -> V_7 -> V_102 . V_204 . V_203 = V_345 -> V_203 ;
F_167 ( & V_63 -> V_7 -> V_291 ) ;
snprintf ( V_347 , sizeof( V_347 ) , L_86 ) ;
snprintf ( V_348 , sizeof( V_348 ) , L_87 ,
( V_345 -> V_203 == V_212 ) ? L_88 :
( V_345 -> V_203 == V_210 ) ? L_89 :
( V_345 -> V_203 == V_211 ) ? L_90 :
L_91 ) ;
snprintf ( V_349 , sizeof( V_349 ) , L_92 ,
( V_345 -> V_141 == V_350 ) ? L_93 :
( V_345 -> V_141 == V_351 ) ? L_94 :
( V_345 -> V_141 == V_352 ) ? L_95 :
L_91 ) ;
F_215 ( & V_63 -> V_7 -> V_72 -> V_2 . V_298 ,
V_299 , V_326 ) ;
F_34 ( V_63 ) ;
}
static void F_191 ( struct V_6 * V_7 ,
struct V_59 * V_5 )
{
struct V_353 * V_346 =
& V_5 -> V_63 . V_204 . V_63 . V_354 ;
struct V_342 * V_63 ;
int V_355 ;
F_17 ( V_7 , 2 , L_96 ) ;
if ( V_346 -> V_356 != sizeof( struct V_344 ) ) {
F_7 ( V_7 , 2 , L_97 , V_346 -> V_356 ) ;
return;
}
V_355 = sizeof( struct V_344 ) * V_346 -> V_357 ;
V_63 = F_102 ( sizeof( struct V_342 ) + V_355 ,
V_133 ) ;
if ( ! V_63 ) {
F_17 ( V_7 , 2 , L_98 ) ;
return;
}
F_217 ( & V_63 -> V_343 , F_216 ) ;
V_63 -> V_7 = V_7 ;
memcpy ( & V_63 -> V_346 , V_346 ,
sizeof( struct V_353 ) + V_355 ) ;
F_218 ( V_358 , & V_63 -> V_343 ) ;
}
static void F_219 ( struct V_340 * V_341 )
{
struct V_359 * V_63 =
F_80 ( V_341 , struct V_359 , V_343 ) ;
int V_82 ;
if ( V_63 -> V_360 . V_361 ) {
F_21 ( & V_63 -> V_7 -> V_72 -> V_2 ,
L_99 ,
V_63 -> V_7 -> V_2 -> V_73 ,
( V_63 -> V_360 . V_361 == 0x01 )
? L_100
: ( V_63 -> V_360 . V_361 == 0x02 )
? L_101
: L_102 ) ;
F_154 ( & V_63 -> V_7 -> V_291 ) ;
V_63 -> V_7 -> V_102 . V_204 . V_362 = 0 ;
F_167 ( & V_63 -> V_7 -> V_291 ) ;
F_214 ( V_63 -> V_7 , V_338 ,
0 , NULL , NULL ) ;
} else
for ( V_82 = 0 ; V_82 < V_63 -> V_360 . V_357 ; V_82 ++ ) {
struct V_363 * V_345 =
& V_63 -> V_360 . V_345 [ V_82 ] ;
F_214 ( V_63 -> V_7 ,
V_327 ,
V_345 -> V_364 ,
& V_345 -> V_322 , & V_345 -> V_324 ) ;
}
F_34 ( V_63 ) ;
}
static void F_192 ( struct V_6 * V_7 ,
struct V_59 * V_5 )
{
struct V_365 * V_360 =
& V_5 -> V_63 . V_366 ;
struct V_359 * V_63 ;
int V_355 ;
F_17 ( V_7 , 2 , L_103 ) ;
if ( V_5 -> V_92 . V_124 != 0x0000 ) {
if ( V_5 -> V_92 . V_124 == 0x0010 ) {
if ( V_360 -> V_361 == 0x00 )
V_360 -> V_361 = 0xff ;
} else {
F_7 ( V_7 , 2 , L_104 ,
V_5 -> V_92 . V_124 ) ;
return;
}
}
V_355 = sizeof( struct V_363 ) *
V_360 -> V_357 ;
V_63 = F_102 ( sizeof( struct V_359 ) + V_355 ,
V_133 ) ;
if ( ! V_63 ) {
F_17 ( V_7 , 2 , L_105 ) ;
return;
}
F_217 ( & V_63 -> V_343 , F_219 ) ;
V_63 -> V_7 = V_7 ;
memcpy ( & V_63 -> V_360 , V_360 ,
sizeof( struct V_365 ) + V_355 ) ;
F_218 ( V_358 , & V_63 -> V_343 ) ;
}
static int F_220 ( struct V_6 * V_7 ,
struct V_367 * V_368 , enum V_369 V_370 )
{
int V_11 ;
int V_371 = ( V_7 -> V_13 . type == V_196 ) ;
if ( ( V_371 && ( V_368 -> V_372 == V_43 ) ) ||
( ! V_371 && ( V_368 -> V_372 == V_368 -> V_373 ) ) )
switch ( V_368 -> V_373 ) {
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
F_221 ( & V_7 -> V_72 -> V_2 ,
L_106 ) ;
break;
case 0x2B10 :
case 0x0010 :
V_11 = - V_15 ;
F_221 ( & V_7 -> V_72 -> V_2 ,
L_107 ) ;
break;
case 0x2B14 :
case 0x0014 :
switch ( V_370 ) {
case V_374 :
V_11 = - V_49 ;
F_221 ( & V_7 -> V_72 -> V_2 ,
L_108 ) ;
break;
case V_375 :
V_11 = - V_251 ;
F_221 ( & V_7 -> V_72 -> V_2 ,
L_109 ) ;
break;
default:
V_11 = - V_55 ;
}
break;
case 0x2B18 :
case 0x0018 :
V_11 = - V_251 ;
F_221 ( & V_7 -> V_72 -> V_2 ,
L_110 ) ;
break;
case 0x2B1C :
case 0x001C :
V_11 = - V_49 ;
F_221 ( & V_7 -> V_72 -> V_2 ,
L_111 ) ;
break;
case 0x2B24 :
case 0x0024 :
V_11 = - V_251 ;
F_221 ( & V_7 -> V_72 -> V_2 ,
L_109 ) ;
break;
case 0x2B20 :
case 0x0020 :
V_11 = - V_376 ;
F_221 ( & V_7 -> V_72 -> V_2 ,
L_112 ) ;
break;
default:
V_11 = - V_55 ;
}
else
switch ( V_368 -> V_372 ) {
case V_377 :
V_11 = - V_31 ;
break;
case V_378 :
V_11 = - V_31 ;
break;
default:
V_11 = - V_55 ;
}
if ( V_11 ) {
F_7 ( V_7 , 2 , L_113 , V_368 -> V_372 ) ;
F_7 ( V_7 , 2 , L_114 , V_368 -> V_373 ) ;
}
return V_11 ;
}
static inline int F_222 ( struct V_6 * V_7 )
{
return ( V_7 -> V_13 . type == V_196 ) ?
V_306 :
V_305 ;
}
static int F_223 ( struct V_6 * V_7 ,
struct V_122 * V_123 , unsigned long V_63 )
{
struct V_59 * V_5 = (struct V_59 * ) V_63 ;
struct V_367 * V_368 = (struct V_367 * ) V_123 -> V_379 ;
F_17 ( V_7 , 2 , L_115 ) ;
V_368 -> V_372 = V_5 -> V_92 . V_124 ;
V_368 -> V_373 = V_5 -> V_63 . V_204 . V_92 . V_124 ;
if ( ( V_368 -> V_372 == 0 ) && ( V_368 -> V_373 == 0 ) ) {
V_368 -> V_63 . V_380 =
V_5 -> V_63 . V_204 . V_63 . V_381 . V_382 ;
} else {
V_368 -> V_63 . V_380 = 0 ;
}
return 0 ;
}
static void F_156 ( struct V_6 * V_7 )
{
struct V_60 * V_61 ;
struct V_59 * V_5 ;
struct V_367 V_368 ;
F_17 ( V_7 , 2 , L_116 ) ;
V_61 = F_18 ( V_7 , F_222 ( V_7 ) , 0 ) ;
if ( ! V_61 )
return;
V_5 = (struct V_59 * ) ( V_61 -> V_63 + V_64 ) ;
V_5 -> V_63 . V_204 . V_92 . V_383 =
sizeof( struct V_384 ) +
sizeof( struct V_385 ) ;
V_5 -> V_63 . V_204 . V_92 . V_307 =
V_386 ;
V_5 -> V_63 . V_204 . V_92 . V_387 = 1 ;
V_5 -> V_63 . V_204 . V_92 . V_388 = 1 ;
if ( F_19 ( V_7 , V_61 , F_223 ,
( void * ) & V_368 ) ||
F_220 ( V_7 , & V_368 ,
V_386 ) ) {
V_7 -> V_102 . V_204 . V_203 = V_212 ;
return;
}
V_7 -> V_102 . V_204 . V_293 = V_368 . V_63 . V_380 ;
}
static int F_224 ( struct V_6 * V_7 ,
struct V_122 * V_123 , unsigned long V_63 )
{
struct V_59 * V_5 = (struct V_59 * ) V_63 ;
struct V_389 * V_346 = & V_5 -> V_63 . V_204 . V_63 . V_390 ;
struct V_367 * V_368 = (struct V_367 * ) V_123 -> V_379 ;
F_17 ( V_7 , 2 , L_117 ) ;
V_368 -> V_372 = V_5 -> V_92 . V_124 ;
V_368 -> V_373 = V_5 -> V_63 . V_204 . V_92 . V_124 ;
if ( ( V_368 -> V_372 != 0 ) || ( V_368 -> V_373 != 0 ) )
return 0 ;
if ( V_346 -> V_356 != sizeof( struct V_344 ) ) {
V_368 -> V_373 = 0xffff ;
F_7 ( V_7 , 2 , L_118 , V_346 -> V_356 ) ;
return 0 ;
}
if ( V_346 -> V_357 > 0 ) {
if ( V_368 -> V_63 . V_346 . V_203 )
* V_368 -> V_63 . V_346 . V_203 = V_346 -> V_345 [ 0 ] . V_203 ;
if ( V_368 -> V_63 . V_346 . V_141 )
* V_368 -> V_63 . V_346 . V_141 = V_346 -> V_345 [ 0 ] . V_141 ;
}
return 0 ;
}
int F_225 ( struct V_6 * V_7 ,
enum V_391 * V_203 , enum V_392 * V_141 )
{
int V_11 = 0 ;
struct V_60 * V_61 ;
struct V_59 * V_5 ;
struct V_367 V_368 = {
. V_63 = {
. V_346 = {
. V_203 = V_203 ,
. V_141 = V_141 ,
} ,
} ,
} ;
F_17 ( V_7 , 2 , L_119 ) ;
if ( ! ( V_7 -> V_102 . V_204 . V_293 & V_393 ) )
return - V_31 ;
V_61 = F_18 ( V_7 , F_222 ( V_7 ) , 0 ) ;
if ( ! V_61 )
return - V_54 ;
V_5 = (struct V_59 * ) ( V_61 -> V_63 + V_64 ) ;
V_5 -> V_63 . V_204 . V_92 . V_383 =
sizeof( struct V_384 ) ;
V_5 -> V_63 . V_204 . V_92 . V_307 =
V_393 ;
V_5 -> V_63 . V_204 . V_92 . V_387 = 1 ;
V_5 -> V_63 . V_204 . V_92 . V_388 = 1 ;
V_11 = F_19 ( V_7 , V_61 , F_224 ,
( void * ) & V_368 ) ;
if ( V_11 < 0 )
return V_11 ;
return F_220 ( V_7 , & V_368 , V_393 ) ;
}
static int F_226 ( struct V_6 * V_7 ,
struct V_122 * V_123 , unsigned long V_63 )
{
struct V_59 * V_5 = (struct V_59 * ) V_63 ;
struct V_367 * V_368 = (struct V_367 * ) V_123 -> V_379 ;
F_17 ( V_7 , 2 , L_120 ) ;
V_368 -> V_372 = V_5 -> V_92 . V_124 ;
V_368 -> V_373 = V_5 -> V_63 . V_204 . V_92 . V_124 ;
return 0 ;
}
int F_99 ( struct V_6 * V_7 , enum V_391 V_203 )
{
int V_11 = 0 ;
int V_383 ;
struct V_60 * V_61 ;
struct V_59 * V_5 ;
struct V_367 V_368 ;
enum V_369 V_370 ;
F_17 ( V_7 , 2 , L_121 ) ;
switch ( V_203 ) {
case V_212 :
V_370 = V_394 ;
V_383 = sizeof( struct V_384 ) +
sizeof( struct V_395 ) ;
break;
case V_210 :
V_370 = V_374 ;
V_383 = sizeof( struct V_384 ) +
sizeof( struct V_396 ) ;
break;
case V_211 :
V_370 = V_375 ;
V_383 = sizeof( struct V_384 ) +
sizeof( struct V_397 ) ;
break;
default:
return - V_27 ;
}
if ( ! ( V_7 -> V_102 . V_204 . V_293 & V_370 ) )
return - V_31 ;
V_61 = F_18 ( V_7 , F_222 ( V_7 ) , 0 ) ;
if ( ! V_61 )
return - V_54 ;
V_5 = (struct V_59 * ) ( V_61 -> V_63 + V_64 ) ;
V_5 -> V_63 . V_204 . V_92 . V_383 = V_383 ;
V_5 -> V_63 . V_204 . V_92 . V_307 = V_370 ;
V_5 -> V_63 . V_204 . V_92 . V_387 = 1 ;
V_5 -> V_63 . V_204 . V_92 . V_388 = 1 ;
V_11 = F_19 ( V_7 , V_61 , F_226 ,
( void * ) & V_368 ) ;
if ( V_11 < 0 )
return V_11 ;
return F_220 ( V_7 , & V_368 , V_370 ) ;
}
static int F_227 ( struct V_6 * V_7 , int V_398 , T_6 V_399 )
{
int V_11 ;
if ( V_398 == 0 )
switch ( V_399 ) {
case 0x0001 :
V_11 = 0 ;
break;
case 0x0004 :
case 0x0100 :
case 0x0106 :
V_11 = - V_31 ;
F_221 ( & V_7 -> V_72 -> V_2 ,
L_122 ) ;
break;
case 0x0107 :
V_11 = - V_400 ;
break;
default:
V_11 = - V_55 ;
}
else
V_11 = - V_55 ;
if ( V_11 ) {
F_7 ( V_7 , 2 , L_123 , V_398 ) ;
F_7 ( V_7 , 2 , L_124 , V_399 ) ;
}
return V_11 ;
}
static void F_228 ( void * V_401 ,
enum V_402 type , void * V_345 )
{
struct V_6 * V_7 = (struct V_6 * ) V_401 ;
struct V_403 * V_404 ;
T_4 V_320 ;
if ( type != V_405 ) {
F_71 ( 1 ) ;
return;
}
V_404 = (struct V_403 * ) V_345 ;
V_320 = V_331 ;
if ( V_404 -> V_324 . V_330 )
V_320 |= V_329 ;
F_214 ( V_7 , V_327 , V_320 ,
(struct V_321 * ) & V_404 -> V_406 ,
(struct V_323 * ) & V_404 -> V_324 ) ;
}
int F_229 ( struct V_6 * V_7 , int V_407 )
{
int V_11 ;
T_6 V_399 ;
struct V_408 * V_409 ;
struct V_410 V_411 ;
if ( ! V_7 )
return - V_27 ;
if ( ! V_7 -> V_102 . V_204 . V_293 )
return - V_31 ;
V_409 = F_169 ( V_7 ) ;
F_230 ( V_409 , & V_411 ) ;
if ( V_407 ) {
F_214 ( V_7 , V_339 , 0 , NULL , NULL ) ;
V_11 = F_231 ( V_411 , 1 , & V_399 ,
F_228 , V_7 ) ;
} else
V_11 = F_231 ( V_411 , 0 , & V_399 , NULL , NULL ) ;
return F_227 ( V_7 , V_11 , V_399 ) ;
}
