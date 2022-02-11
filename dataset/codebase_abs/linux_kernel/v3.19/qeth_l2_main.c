static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 ;
int V_11 = 0 ;
if ( ! V_7 )
return - V_12 ;
if ( ( V_7 -> V_13 != V_14 ) &&
( V_7 -> V_13 != V_15 ) )
return - V_12 ;
if ( V_7 -> V_16 . type == V_17 )
return - V_18 ;
switch ( V_5 ) {
case V_19 :
V_11 = F_2 ( V_7 , V_4 -> V_20 . V_21 ) ;
break;
case V_22 :
if ( ( V_7 -> V_16 . type == V_23 ||
V_7 -> V_16 . type == V_24 ||
V_7 -> V_16 . type == V_25 ) &&
! V_7 -> V_16 . V_26 )
return 1 ;
return 0 ;
break;
case V_27 :
V_10 = F_3 ( V_4 ) ;
V_10 -> V_28 = 0 ;
break;
case V_29 :
V_10 = F_3 ( V_4 ) ;
if ( V_10 -> V_28 != 0 )
V_11 = - V_30 ;
else
V_10 -> V_31 = F_4 ( V_2 ,
V_10 -> V_28 , V_10 -> V_32 ) ;
break;
case V_33 :
V_11 = F_5 ( V_7 , V_4 -> V_20 . V_21 ) ;
break;
default:
V_11 = - V_34 ;
}
if ( V_11 )
F_6 ( V_7 , 2 , L_1 , V_11 ) ;
return V_11 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
unsigned long V_35 ;
int V_11 = 0 ;
F_8 ( & V_36 . V_37 , V_35 ) ;
F_9 (card, &qeth_core_card_list.list, list) {
if ( V_7 -> V_2 == V_2 ) {
V_11 = V_38 ;
break;
}
}
F_10 ( & V_36 . V_37 , V_35 ) ;
return V_11 ;
}
static struct V_1 * F_11 ( unsigned char * V_39 )
{
struct V_6 * V_7 ;
struct V_1 * V_40 ;
T_1 V_41 ;
unsigned long V_35 ;
struct V_42 V_43 ;
V_40 = NULL ;
memcpy ( & V_41 , V_39 , 2 ) ;
F_8 ( & V_36 . V_37 , V_35 ) ;
F_9 (card, &qeth_core_card_list.list, list) {
F_12 ( F_13 ( V_7 ) , & V_43 ) ;
if ( V_43 . V_44 == V_41 ) {
V_40 = V_7 -> V_2 ;
break;
}
}
F_10 ( & V_36 . V_37 , V_35 ) ;
return V_40 ;
}
static int F_14 ( struct V_6 * V_7 , int V_45 )
{
int V_11 ;
if ( V_45 )
F_6 ( V_7 , 2 , L_2 , V_45 ) ;
switch ( V_45 ) {
case V_46 :
V_11 = 0 ;
break;
case V_47 :
V_11 = - V_48 ;
break;
case V_49 :
V_11 = - V_50 ;
break;
case V_51 :
case V_52 :
V_11 = - V_53 ;
break;
case V_54 :
case V_55 :
V_11 = - V_18 ;
break;
case V_56 :
V_11 = - V_57 ;
break;
case - V_58 :
V_11 = - V_58 ;
break;
default:
V_11 = - V_59 ;
break;
}
return V_11 ;
}
static int F_15 ( struct V_6 * V_7 , T_2 * V_60 )
{
int V_11 ;
F_16 ( V_7 , 2 , L_3 ) ;
V_11 = F_14 ( V_7 , F_17 ( V_7 , V_60 ,
V_61 ) ) ;
if ( V_11 == - V_53 )
F_18 ( 2 , L_4 ,
V_60 , F_19 ( V_7 ) ) ;
else if ( V_11 )
F_18 ( 2 , L_5 ,
V_60 , F_19 ( V_7 ) , V_11 ) ;
return V_11 ;
}
static int F_20 ( struct V_6 * V_7 , T_2 * V_60 )
{
int V_11 ;
F_16 ( V_7 , 2 , L_6 ) ;
V_11 = F_14 ( V_7 , F_17 ( V_7 , V_60 ,
V_62 ) ) ;
if ( V_11 )
F_18 ( 2 ,
L_7 ,
V_60 , F_19 ( V_7 ) , V_11 ) ;
return V_11 ;
}
static void F_21 ( struct V_6 * V_7 , T_2 * V_60 , int V_63 )
{
struct V_64 * V_65 ;
int V_11 ;
V_65 = F_22 ( sizeof( struct V_64 ) , V_66 ) ;
if ( ! V_65 )
return;
memcpy ( V_65 -> V_67 , V_60 , V_68 ) ;
V_65 -> V_69 = V_68 ;
V_65 -> V_70 = V_63 ;
if ( V_63 ) {
V_11 = F_14 ( V_7 ,
F_17 ( V_7 , V_60 , V_71 ) ) ;
} else {
V_11 = F_14 ( V_7 ,
F_15 ( V_7 , V_60 ) ) ;
}
if ( ! V_11 )
F_23 ( & V_65 -> V_72 , & V_7 -> V_73 ) ;
else
F_24 ( V_65 ) ;
}
static void F_25 ( struct V_6 * V_7 , int V_74 )
{
struct V_64 * V_65 , * V_75 ;
F_26 ( & V_7 -> V_76 ) ;
F_27 (mc, tmp, &card->mc_list, list) {
if ( V_74 ) {
if ( V_65 -> V_70 )
F_17 ( V_7 , V_65 -> V_67 ,
V_77 ) ;
else
F_20 ( V_7 , V_65 -> V_67 ) ;
}
F_28 ( & V_65 -> V_72 ) ;
F_24 ( V_65 ) ;
}
F_29 ( & V_7 -> V_76 ) ;
}
static inline int F_30 ( struct V_6 * V_7 ,
struct V_78 * V_79 )
{
if ( V_7 -> V_16 . type == V_17 )
return V_80 ;
if ( F_31 ( V_79 -> V_81 ) )
return V_82 ;
if ( F_32 ( V_79 -> V_81 ) )
return V_83 ;
return V_80 ;
}
static void F_33 ( struct V_6 * V_7 , struct V_84 * V_85 ,
struct V_78 * V_79 , int V_86 )
{
struct V_87 * V_88 = (struct V_87 * ) F_34 ( V_79 ) ;
memset ( V_85 , 0 , sizeof( struct V_84 ) ) ;
V_85 -> V_85 . V_89 . V_90 = V_91 ;
if ( V_86 == V_83 )
V_85 -> V_85 . V_89 . V_35 [ 2 ] |= V_92 ;
else if ( V_86 == V_82 )
V_85 -> V_85 . V_89 . V_35 [ 2 ] |= V_93 ;
else
V_85 -> V_85 . V_89 . V_35 [ 2 ] |= V_94 ;
V_85 -> V_85 . V_89 . V_95 = V_79 -> V_96 - V_97 ;
if ( V_88 -> V_98 == F_35 ( V_99 ) ) {
V_85 -> V_85 . V_89 . V_35 [ 2 ] |= V_100 ;
V_85 -> V_85 . V_89 . V_101 = F_36 ( V_88 -> V_102 ) ;
}
}
static int F_37 ( struct V_6 * V_7 ,
struct V_103 * V_104 , unsigned long V_81 )
{
struct V_105 * V_5 ;
F_16 ( V_7 , 2 , L_8 ) ;
V_5 = (struct V_105 * ) V_81 ;
if ( V_5 -> V_85 . V_106 ) {
F_18 ( 2 , L_9
L_10 , V_5 -> V_81 . V_107 . V_101 ,
F_19 ( V_7 ) , V_5 -> V_85 . V_106 ) ;
F_6 ( V_7 , 2 , L_11 , V_5 -> V_85 . V_108 ) ;
F_6 ( V_7 , 2 , L_12 , V_5 -> V_85 . V_106 ) ;
}
return 0 ;
}
static int F_38 ( struct V_6 * V_7 , T_1 V_109 ,
enum V_110 V_111 )
{
struct V_105 * V_5 ;
struct V_112 * V_113 ;
F_6 ( V_7 , 4 , L_13 , V_111 ) ;
V_113 = F_39 ( V_7 , V_111 , V_114 ) ;
if ( ! V_113 )
return - V_58 ;
V_5 = (struct V_105 * ) ( V_113 -> V_81 + V_115 ) ;
V_5 -> V_81 . V_107 . V_101 = V_109 ;
return F_40 ( V_7 , V_113 ,
F_37 , NULL ) ;
}
static void F_41 ( struct V_6 * V_7 )
{
struct V_116 * V_90 ;
F_16 ( V_7 , 3 , L_14 ) ;
F_26 ( & V_7 -> V_117 ) ;
F_9 (id, &card->vid_list, list) {
F_38 ( V_7 , V_90 -> V_118 , V_119 ) ;
}
F_29 ( & V_7 -> V_117 ) ;
}
static int F_42 ( struct V_1 * V_2 ,
T_3 V_120 , T_4 V_118 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_116 * V_90 ;
int V_11 ;
F_6 ( V_7 , 4 , L_15 , V_118 ) ;
if ( ! V_118 )
return 0 ;
if ( V_7 -> V_16 . type == V_24 ) {
F_16 ( V_7 , 3 , L_16 ) ;
return 0 ;
}
if ( F_43 ( V_7 , V_121 ) ) {
F_16 ( V_7 , 3 , L_17 ) ;
return 0 ;
}
V_90 = F_22 ( sizeof( struct V_116 ) , V_66 ) ;
if ( V_90 ) {
V_90 -> V_118 = V_118 ;
V_11 = F_38 ( V_7 , V_118 , V_119 ) ;
if ( V_11 ) {
F_24 ( V_90 ) ;
return V_11 ;
}
F_26 ( & V_7 -> V_117 ) ;
F_23 ( & V_90 -> V_72 , & V_7 -> V_122 ) ;
F_29 ( & V_7 -> V_117 ) ;
} else {
return - V_58 ;
}
return 0 ;
}
static int F_44 ( struct V_1 * V_2 ,
T_3 V_120 , T_4 V_118 )
{
struct V_116 * V_90 , * V_123 = NULL ;
struct V_6 * V_7 = V_2 -> V_8 ;
int V_11 = 0 ;
F_6 ( V_7 , 4 , L_18 , V_118 ) ;
if ( V_7 -> V_16 . type == V_24 ) {
F_16 ( V_7 , 3 , L_19 ) ;
return 0 ;
}
if ( F_43 ( V_7 , V_121 ) ) {
F_16 ( V_7 , 3 , L_20 ) ;
return 0 ;
}
F_26 ( & V_7 -> V_117 ) ;
F_9 (id, &card->vid_list, list) {
if ( V_90 -> V_118 == V_118 ) {
F_28 ( & V_90 -> V_72 ) ;
V_123 = V_90 ;
break;
}
}
F_29 ( & V_7 -> V_117 ) ;
if ( V_123 ) {
V_11 = F_38 ( V_7 , V_118 , V_124 ) ;
F_24 ( V_123 ) ;
}
F_45 ( V_7 -> V_2 ) ;
return V_11 ;
}
static int F_46 ( struct V_6 * V_7 , int V_125 )
{
int V_11 = 0 ;
F_47 ( V_126 , 2 , L_21 ) ;
F_48 ( V_126 , 2 , & V_7 , sizeof( void * ) ) ;
F_49 ( V_7 , 0 , 1 ) ;
if ( V_7 -> V_127 . V_13 == V_128 &&
V_7 -> V_129 . V_13 == V_128 &&
( V_7 -> V_13 == V_14 ) ) {
if ( V_125 &&
V_7 -> V_16 . type != V_17 ) {
F_50 ( V_7 -> V_2 ) ;
} else {
F_51 () ;
F_52 ( V_7 -> V_2 ) ;
F_53 () ;
}
V_7 -> V_16 . V_130 &= ~ V_131 ;
V_7 -> V_13 = V_15 ;
}
if ( V_7 -> V_13 == V_15 ) {
F_25 ( V_7 , 0 ) ;
F_54 ( V_7 ) ;
V_7 -> V_13 = V_132 ;
}
if ( V_7 -> V_13 == V_132 ) {
F_55 ( V_7 , 0 ) ;
F_56 ( V_7 ) ;
F_57 ( V_7 ) ;
V_7 -> V_13 = V_133 ;
}
if ( V_7 -> V_13 == V_133 ) {
F_58 ( & V_7 -> V_127 ) ;
F_58 ( & V_7 -> V_129 ) ;
}
return V_11 ;
}
static int F_59 ( struct V_6 * V_7 ,
int V_134 , int * V_135 )
{
int V_136 = 0 ;
struct V_78 * V_79 ;
struct V_84 * V_85 ;
unsigned int V_96 ;
* V_135 = 0 ;
F_60 ( ! V_134 ) ;
while ( V_134 ) {
V_79 = F_61 ( V_7 ,
& V_7 -> V_137 . V_138 -> V_139 [ V_7 -> V_140 . V_141 ] ,
& V_7 -> V_140 . V_142 , & V_7 -> V_140 . V_143 , & V_85 ) ;
if ( ! V_79 ) {
* V_135 = 1 ;
break;
}
V_79 -> V_2 = V_7 -> V_2 ;
switch ( V_85 -> V_85 . V_89 . V_90 ) {
case V_91 :
V_79 -> V_144 = V_145 ;
V_79 -> V_146 = F_62 ( V_79 , V_79 -> V_2 ) ;
V_79 -> V_147 = V_148 ;
if ( V_79 -> V_146 == F_63 ( V_149 ) )
* ( ( V_150 * ) V_79 -> V_151 ) = ++ V_7 -> V_152 . V_153 ;
V_96 = V_79 -> V_96 ;
F_64 ( V_79 ) ;
break;
case V_154 :
if ( V_7 -> V_16 . type == V_17 ) {
F_65 ( V_79 , sizeof( struct V_84 ) ) ;
F_66 ( V_79 , V_85 ,
sizeof( struct V_84 ) ) ;
V_96 = V_79 -> V_96 ;
V_7 -> V_155 . V_156 ( V_79 ) ;
break;
}
default:
F_67 ( V_79 ) ;
F_16 ( V_7 , 3 , L_22 ) ;
F_48 ( V_157 , 3 , V_85 , V_158 ) ;
continue;
}
V_136 ++ ;
V_134 -- ;
V_7 -> V_159 . V_160 ++ ;
V_7 -> V_159 . V_161 += V_96 ;
}
return V_136 ;
}
static int F_68 ( struct V_162 * V_163 , int V_134 )
{
struct V_6 * V_7 = F_69 ( V_163 , struct V_6 , V_163 ) ;
int V_136 = 0 ;
struct V_164 * V_165 ;
int V_135 ;
int V_166 = V_134 ;
if ( V_7 -> V_167 . V_168 ) {
V_7 -> V_169 . V_170 ++ ;
V_7 -> V_169 . V_171 = F_70 () ;
}
while ( 1 ) {
if ( ! V_7 -> V_140 . V_172 ) {
V_7 -> V_140 . V_173 = 0 ;
V_7 -> V_140 . V_172 = F_71 (
V_7 -> V_81 . V_174 , 0 , & V_7 -> V_140 . V_141 ,
& V_7 -> V_140 . V_173 ) ;
if ( V_7 -> V_140 . V_172 <= 0 ) {
V_7 -> V_140 . V_172 = 0 ;
break;
}
V_7 -> V_140 . V_142 =
& V_7 -> V_137 . V_138 -> V_139 [ V_7 -> V_140 . V_141 ]
. V_165 -> V_175 [ 0 ] ;
V_7 -> V_140 . V_143 = 0 ;
}
while ( V_7 -> V_140 . V_172 ) {
V_165 = & V_7 -> V_137 . V_138 -> V_139 [ V_7 -> V_140 . V_141 ] ;
if ( ! ( V_7 -> V_140 . V_173 &&
F_72 ( V_7 , V_165 -> V_165 ,
V_7 -> V_140 . V_173 , L_23 ) ) )
V_136 += F_59 (
V_7 , V_166 , & V_135 ) ;
else
V_135 = 1 ;
if ( V_135 ) {
if ( V_7 -> V_167 . V_168 )
V_7 -> V_169 . V_176 ++ ;
F_73 ( V_7 ,
V_165 -> V_177 ) ;
F_74 ( V_7 , V_7 -> V_140 . V_141 ) ;
V_7 -> V_140 . V_172 -- ;
if ( V_7 -> V_140 . V_172 ) {
V_7 -> V_140 . V_141 =
( V_7 -> V_140 . V_141 + 1 ) %
V_178 ;
V_7 -> V_140 . V_142 =
& V_7 -> V_137 . V_138
-> V_139 [ V_7 -> V_140 . V_141 ]
. V_165 -> V_175 [ 0 ] ;
V_7 -> V_140 . V_143 = 0 ;
}
}
if ( V_136 >= V_134 )
goto V_179;
else
V_166 = V_134 - V_136 ;
}
}
F_75 ( V_163 ) ;
if ( F_76 ( V_7 -> V_81 . V_174 , 0 ) )
F_77 ( & V_7 -> V_163 ) ;
V_179:
if ( V_7 -> V_167 . V_168 )
V_7 -> V_169 . V_180 += F_70 () -
V_7 -> V_169 . V_171 ;
return V_136 ;
}
static int F_17 ( struct V_6 * V_7 , T_2 * V_60 ,
enum V_110 V_111 )
{
struct V_105 * V_5 ;
struct V_112 * V_113 ;
F_16 ( V_7 , 2 , L_24 ) ;
V_113 = F_39 ( V_7 , V_111 , V_114 ) ;
if ( ! V_113 )
return - V_58 ;
V_5 = (struct V_105 * ) ( V_113 -> V_81 + V_115 ) ;
V_5 -> V_81 . V_181 . V_182 = V_68 ;
memcpy ( & V_5 -> V_81 . V_181 . V_60 , V_60 , V_68 ) ;
return F_40 ( V_7 , V_113 , NULL , NULL ) ;
}
static int F_78 ( struct V_6 * V_7 , T_2 * V_60 )
{
int V_11 ;
F_16 ( V_7 , 2 , L_25 ) ;
V_11 = F_14 ( V_7 , F_17 ( V_7 , V_60 ,
V_71 ) ) ;
if ( V_11 == 0 ) {
V_7 -> V_16 . V_130 |= V_131 ;
memcpy ( V_7 -> V_2 -> V_183 , V_60 , V_68 ) ;
F_79 ( & V_7 -> V_184 -> V_2 ,
L_26 ,
V_7 -> V_2 -> V_183 , V_7 -> V_2 -> V_185 ) ;
} else {
V_7 -> V_16 . V_130 &= ~ V_131 ;
switch ( V_11 ) {
case - V_53 :
F_80 ( & V_7 -> V_184 -> V_2 ,
L_27 , V_60 ) ;
break;
case - V_18 :
F_80 ( & V_7 -> V_184 -> V_2 ,
L_28 , V_60 ) ;
break;
}
}
return V_11 ;
}
static int F_81 ( struct V_6 * V_7 , T_2 * V_60 )
{
int V_11 ;
F_16 ( V_7 , 2 , L_29 ) ;
if ( ! ( V_7 -> V_16 . V_130 & V_131 ) )
return 0 ;
V_11 = F_14 ( V_7 , F_17 ( V_7 , V_60 ,
V_77 ) ) ;
if ( V_11 == 0 )
V_7 -> V_16 . V_130 &= ~ V_131 ;
return V_11 ;
}
static int F_82 ( struct V_6 * V_7 )
{
int V_11 = 0 ;
char V_186 [] = { 0x02 , 0x00 , 0x00 } ;
F_47 ( V_126 , 2 , L_30 ) ;
F_83 ( V_126 , 2 , L_31 , F_84 ( V_7 ) ) ;
if ( F_85 ( V_7 , V_187 ) ) {
V_11 = F_86 ( V_7 ) ;
if ( V_11 ) {
F_18 ( 2 , L_32
L_33 ,
F_84 ( V_7 ) , V_11 ) ;
}
}
if ( V_7 -> V_16 . type == V_188 ||
V_7 -> V_16 . type == V_24 ||
V_7 -> V_16 . type == V_25 ||
V_7 -> V_16 . V_26 ) {
V_11 = F_87 ( V_7 ) ;
if ( V_11 ) {
F_18 ( 2 , L_34
L_35 , F_84 ( V_7 ) , V_11 ) ;
F_83 ( V_126 , 2 , L_36 , V_11 ) ;
return V_11 ;
}
F_48 ( V_126 , 2 , V_7 -> V_2 -> V_183 , V_68 ) ;
} else {
F_88 ( V_7 -> V_2 -> V_183 ) ;
memcpy ( V_7 -> V_2 -> V_183 , V_186 , 3 ) ;
}
return 0 ;
}
static int F_89 ( struct V_1 * V_2 , void * V_189 )
{
struct V_190 * V_191 = V_189 ;
struct V_6 * V_7 = V_2 -> V_8 ;
int V_11 = 0 ;
F_16 ( V_7 , 3 , L_37 ) ;
if ( F_7 ( V_2 ) != V_38 ) {
F_16 ( V_7 , 3 , L_38 ) ;
return - V_34 ;
}
if ( V_7 -> V_16 . type == V_17 ||
V_7 -> V_16 . type == V_24 ||
V_7 -> V_16 . type == V_25 ) {
F_16 ( V_7 , 3 , L_39 ) ;
return - V_34 ;
}
F_90 ( V_7 , 3 , V_191 -> V_192 , V_68 ) ;
if ( F_43 ( V_7 , V_121 ) ) {
F_16 ( V_7 , 3 , L_40 ) ;
return - V_193 ;
}
V_11 = F_81 ( V_7 , & V_7 -> V_2 -> V_183 [ 0 ] ) ;
if ( ! V_11 || ( V_11 == - V_57 ) )
V_11 = F_78 ( V_7 , V_191 -> V_192 ) ;
return V_11 ? - V_30 : 0 ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_194 * V_195 ;
if ( V_7 -> V_16 . type == V_17 )
return ;
F_16 ( V_7 , 3 , L_41 ) ;
if ( F_91 ( V_7 , V_121 ) &&
( V_7 -> V_13 != V_14 ) )
return;
F_25 ( V_7 , 1 ) ;
F_26 ( & V_7 -> V_76 ) ;
F_92 (ha, dev)
F_21 ( V_7 , V_195 -> V_191 , 0 ) ;
F_93 (ha, dev)
F_21 ( V_7 , V_195 -> V_191 , 1 ) ;
F_29 ( & V_7 -> V_76 ) ;
if ( ! F_94 ( V_7 , V_196 ) )
return;
F_95 ( V_7 ) ;
}
static int F_96 ( struct V_78 * V_79 , struct V_1 * V_2 )
{
int V_11 ;
struct V_84 * V_85 = NULL ;
int V_197 = 0 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_78 * V_198 = V_79 ;
int V_86 = F_30 ( V_7 , V_79 ) ;
struct V_199 * V_200 ;
int V_201 = V_79 -> V_96 ;
int V_202 = - 1 ;
int V_203 = 0 ;
int V_204 = 0 ;
if ( V_7 -> V_137 . V_205 || ( V_86 &&
V_7 -> V_16 . V_206 ) )
V_200 = V_7 -> V_137 . V_207 [ F_97 ( V_7 , V_79 ,
F_98 ( V_79 ) , V_86 ) ] ;
else
V_200 = V_7 -> V_137 . V_207 [ V_7 -> V_137 . V_208 ] ;
if ( ( V_7 -> V_13 != V_14 ) || ! V_7 -> V_209 ) {
V_7 -> V_159 . V_210 ++ ;
goto V_211;
}
if ( ( V_7 -> V_16 . type == V_17 ) &&
( V_79 -> V_146 == F_63 ( V_212 ) ) )
goto V_211;
if ( V_7 -> V_167 . V_168 ) {
V_7 -> V_169 . V_213 ++ ;
V_7 -> V_169 . V_214 = F_70 () ;
}
F_99 ( V_2 ) ;
if ( V_7 -> V_16 . type == V_17 )
V_85 = (struct V_84 * ) V_79 -> V_81 ;
else {
if ( V_7 -> V_16 . type == V_188 ) {
V_198 = V_79 ;
V_202 = V_215 ;
V_204 = V_215 ;
V_85 = F_100 ( V_216 ,
V_66 ) ;
if ( ! V_85 )
goto V_211;
V_203 ++ ;
F_101 ( V_198 ) ;
F_33 ( V_7 , V_85 , V_198 , V_86 ) ;
V_85 -> V_85 . V_89 . V_95 = V_198 -> V_96 ;
memcpy ( ( ( char * ) V_85 ) + sizeof( struct V_84 ) ,
F_34 ( V_198 ) , V_215 ) ;
} else {
V_198 = F_102 ( V_79 ,
sizeof( struct V_84 ) ) ;
if ( ! V_198 )
goto V_211;
V_85 = (struct V_84 * ) F_65 ( V_198 ,
sizeof( struct V_84 ) ) ;
F_103 ( V_198 , sizeof( struct V_84 ) ) ;
F_33 ( V_7 , V_85 , V_198 , V_86 ) ;
}
}
V_197 = F_104 ( V_7 , V_198 , V_203 ) ;
if ( ! V_197 ) {
if ( V_202 >= 0 )
F_105 ( V_216 , V_85 ) ;
goto V_211;
}
if ( V_7 -> V_16 . type != V_188 ) {
if ( F_106 ( V_198 , & V_85 ,
sizeof( struct V_217 ) ) )
goto V_211;
V_11 = F_107 ( V_7 , V_200 , V_198 , V_85 ,
V_197 ) ;
} else
V_11 = F_108 ( V_7 , V_200 , V_198 , V_85 ,
V_197 , V_202 , V_204 ) ;
if ( ! V_11 ) {
V_7 -> V_159 . V_218 ++ ;
V_7 -> V_159 . V_201 += V_201 ;
if ( V_198 != V_79 )
F_67 ( V_79 ) ;
V_11 = V_219 ;
} else {
if ( V_202 >= 0 )
F_105 ( V_216 , V_85 ) ;
if ( V_11 == - V_220 ) {
if ( V_198 != V_79 )
F_67 ( V_198 ) ;
return V_221 ;
} else
goto V_211;
}
F_109 ( V_2 ) ;
if ( V_7 -> V_167 . V_168 )
V_7 -> V_169 . V_222 += F_70 () -
V_7 -> V_169 . V_214 ;
return V_11 ;
V_211:
V_7 -> V_159 . V_223 ++ ;
V_7 -> V_159 . V_224 ++ ;
if ( ( V_198 != V_79 ) && V_198 )
F_67 ( V_198 ) ;
F_67 ( V_79 ) ;
F_109 ( V_2 ) ;
return V_219 ;
}
static int F_110 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_11 = 0 ;
F_16 ( V_7 , 4 , L_42 ) ;
if ( V_7 -> V_13 == V_14 )
return V_11 ;
if ( V_7 -> V_13 != V_15 )
return - V_12 ;
if ( ( V_7 -> V_16 . type != V_17 ) &&
( ! ( V_7 -> V_16 . V_130 & V_131 ) ) ) {
F_16 ( V_7 , 4 , L_43 ) ;
return - V_18 ;
}
V_7 -> V_81 . V_13 = V_128 ;
V_7 -> V_13 = V_14 ;
F_111 ( V_2 ) ;
if ( F_112 ( V_7 -> V_81 . V_174 , 0 ) >= 0 ) {
F_113 ( & V_7 -> V_163 ) ;
F_77 ( & V_7 -> V_163 ) ;
} else
V_11 = - V_59 ;
return V_11 ;
}
static int F_114 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_16 ( V_7 , 5 , L_44 ) ;
if ( F_43 ( V_7 , V_121 ) ) {
F_16 ( V_7 , 3 , L_45 ) ;
return - V_193 ;
}
return F_110 ( V_2 ) ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_16 ( V_7 , 4 , L_46 ) ;
F_115 ( V_2 ) ;
if ( V_7 -> V_13 == V_14 ) {
V_7 -> V_13 = V_15 ;
F_116 ( & V_7 -> V_163 ) ;
}
return 0 ;
}
static int F_117 ( struct V_225 * V_184 )
{
struct V_6 * V_7 = F_118 ( & V_184 -> V_2 ) ;
F_119 ( & V_184 -> V_2 ) ;
F_120 ( & V_7 -> V_122 ) ;
F_120 ( & V_7 -> V_73 ) ;
V_7 -> V_167 . V_226 = 1 ;
V_7 -> V_16 . V_227 = 0 ;
return 0 ;
}
static void F_121 ( struct V_225 * V_228 )
{
struct V_6 * V_7 = F_118 ( & V_228 -> V_2 ) ;
F_122 ( & V_228 -> V_2 ) ;
F_49 ( V_7 , 0 , 1 ) ;
F_123 ( V_7 -> V_229 , F_91 ( V_7 , 0xffffffff ) == 0 ) ;
if ( V_228 -> V_13 == V_230 )
F_124 ( V_228 ) ;
if ( V_7 -> V_2 ) {
F_125 ( V_7 -> V_2 ) ;
V_7 -> V_2 = NULL ;
}
return;
}
static int F_126 ( struct V_6 * V_7 )
{
switch ( V_7 -> V_16 . type ) {
case V_188 :
V_7 -> V_2 = F_127 ( 0 , L_47 , V_231 ,
V_232 ) ;
break;
case V_17 :
V_7 -> V_2 = F_127 ( 0 , L_48 , V_231 ,
V_232 ) ;
V_7 -> V_2 -> V_35 |= V_233 ;
break;
default:
V_7 -> V_2 = F_128 ( 0 ) ;
}
if ( ! V_7 -> V_2 )
return - V_12 ;
V_7 -> V_2 -> V_8 = V_7 ;
V_7 -> V_2 -> V_234 = V_235 ;
V_7 -> V_2 -> V_236 = V_7 -> V_16 . V_237 ;
V_7 -> V_2 -> V_238 = & V_239 ;
V_7 -> V_2 -> V_240 =
( V_7 -> V_16 . type != V_17 ) ?
& V_241 : & V_242 ;
V_7 -> V_2 -> V_243 |= V_244 ;
V_7 -> V_16 . V_245 = 1 ;
F_82 ( V_7 ) ;
F_129 ( V_7 -> V_2 , & V_7 -> V_184 -> V_2 ) ;
F_130 ( V_7 -> V_2 , & V_7 -> V_163 , F_68 , V_246 ) ;
return F_131 ( V_7 -> V_2 ) ;
}
static int F_132 ( struct V_225 * V_184 , int V_125 )
{
struct V_6 * V_7 = F_118 ( & V_184 -> V_2 ) ;
int V_11 = 0 ;
enum V_247 V_248 ;
F_133 ( & V_7 -> V_249 ) ;
F_133 ( & V_7 -> V_250 ) ;
F_47 ( V_126 , 2 , L_49 ) ;
F_48 ( V_126 , 2 , & V_7 , sizeof( void * ) ) ;
V_248 = V_7 -> V_13 ;
V_11 = F_134 ( V_7 ) ;
if ( V_11 ) {
F_83 ( V_126 , 2 , L_50 , V_11 ) ;
V_11 = - V_12 ;
goto V_251;
}
F_135 ( V_7 ) ;
if ( V_7 -> V_167 . V_252 . V_253 )
F_79 ( & V_7 -> V_184 -> V_2 ,
L_51 ) ;
F_136 ( V_7 ) ;
if ( ! V_7 -> V_2 && F_126 ( V_7 ) ) {
V_11 = - V_12 ;
goto V_251;
}
if ( V_7 -> V_16 . type != V_17 )
F_78 ( V_7 , & V_7 -> V_2 -> V_183 [ 0 ] ) ;
if ( F_137 ( V_7 , V_254 ) ) {
if ( V_7 -> V_16 . V_227 &&
F_138 ( V_7 , V_255 ) )
V_7 -> V_16 . V_227 = 0 ;
} else
V_7 -> V_16 . V_227 = 0 ;
F_139 ( V_7 ) ;
V_7 -> V_13 = V_132 ;
memset ( & V_7 -> V_140 , 0 , sizeof( struct V_256 ) ) ;
F_140 ( V_7 ) ;
F_47 ( V_126 , 2 , L_52 ) ;
V_11 = F_141 ( V_7 ) ;
if ( V_11 ) {
F_83 ( V_126 , 2 , L_53 , V_11 ) ;
if ( V_11 == 0xe080 ) {
F_80 ( & V_7 -> V_184 -> V_2 ,
L_54 ) ;
V_7 -> V_209 = 0 ;
goto V_257;
}
V_11 = - V_12 ;
goto V_251;
} else
V_7 -> V_209 = 1 ;
V_257:
if ( ( V_7 -> V_16 . type == V_23 ) ||
( V_7 -> V_16 . type == V_25 ) ) {
V_11 = F_142 ( V_7 , 0 ) ;
if ( V_11 ) {
V_11 = - V_12 ;
goto V_251;
}
}
if ( V_7 -> V_16 . type != V_17 &&
V_7 -> V_16 . type != V_24 )
F_41 ( V_7 ) ;
F_115 ( V_7 -> V_2 ) ;
V_11 = F_143 ( V_7 ) ;
if ( V_11 ) {
F_83 ( V_126 , 2 , L_55 , V_11 ) ;
V_11 = - V_12 ;
goto V_251;
}
V_7 -> V_13 = V_15 ;
if ( V_7 -> V_209 )
F_144 ( V_7 -> V_2 ) ;
else
F_145 ( V_7 -> V_2 ) ;
F_49 ( V_7 , 0xffffffff , 0 ) ;
if ( V_248 == V_258 ) {
if ( V_125 &&
V_7 -> V_16 . type != V_17 ) {
F_110 ( V_7 -> V_2 ) ;
} else {
F_51 () ;
F_146 ( V_7 -> V_2 ) ;
F_53 () ;
}
F_45 ( V_7 -> V_2 ) ;
}
F_147 ( & V_184 -> V_2 . V_259 , V_260 ) ;
F_148 ( & V_7 -> V_250 ) ;
F_148 ( & V_7 -> V_249 ) ;
return 0 ;
V_251:
F_46 ( V_7 , 0 ) ;
F_149 ( F_150 ( V_7 ) ) ;
F_149 ( F_151 ( V_7 ) ) ;
F_149 ( F_13 ( V_7 ) ) ;
F_152 ( F_150 ( V_7 ) ) ;
if ( V_248 == V_258 )
V_7 -> V_13 = V_258 ;
else
V_7 -> V_13 = V_133 ;
F_148 ( & V_7 -> V_250 ) ;
F_148 ( & V_7 -> V_249 ) ;
return V_11 ;
}
static int F_153 ( struct V_225 * V_184 )
{
return F_132 ( V_184 , 0 ) ;
}
static int F_154 ( struct V_225 * V_228 ,
int V_125 )
{
struct V_6 * V_7 = F_118 ( & V_228 -> V_2 ) ;
int V_11 = 0 , V_261 = 0 , V_262 = 0 ;
enum V_247 V_248 ;
F_133 ( & V_7 -> V_249 ) ;
F_133 ( & V_7 -> V_250 ) ;
F_47 ( V_126 , 3 , L_56 ) ;
F_48 ( V_126 , 3 , & V_7 , sizeof( void * ) ) ;
if ( V_7 -> V_2 && F_155 ( V_7 -> V_2 ) )
F_145 ( V_7 -> V_2 ) ;
V_248 = V_7 -> V_13 ;
if ( ( ! V_125 && V_7 -> V_16 . V_227 ) || V_7 -> V_16 . V_227 == 2 ) {
F_138 ( V_7 , V_263 ) ;
V_7 -> V_16 . V_227 = 1 ;
}
F_46 ( V_7 , V_125 ) ;
V_11 = F_149 ( F_150 ( V_7 ) ) ;
V_261 = F_149 ( F_151 ( V_7 ) ) ;
V_262 = F_149 ( F_13 ( V_7 ) ) ;
if ( ! V_11 )
V_11 = ( V_261 ) ? V_261 : V_262 ;
if ( V_11 )
F_83 ( V_126 , 2 , L_53 , V_11 ) ;
F_152 ( F_150 ( V_7 ) ) ;
if ( V_248 == V_14 )
V_7 -> V_13 = V_258 ;
F_147 ( & V_228 -> V_2 . V_259 , V_260 ) ;
F_148 ( & V_7 -> V_250 ) ;
F_148 ( & V_7 -> V_249 ) ;
return 0 ;
}
static int F_124 ( struct V_225 * V_228 )
{
return F_154 ( V_228 , 0 ) ;
}
static int F_156 ( void * V_264 )
{
struct V_6 * V_7 ;
int V_11 = 0 ;
V_7 = (struct V_6 * ) V_264 ;
F_16 ( V_7 , 2 , L_57 ) ;
if ( ! F_157 ( V_7 , V_121 ) )
return 0 ;
F_16 ( V_7 , 2 , L_58 ) ;
F_80 ( & V_7 -> V_184 -> V_2 ,
L_59 ) ;
F_158 ( V_7 ) ;
F_154 ( V_7 -> V_184 , 1 ) ;
V_11 = F_132 ( V_7 -> V_184 , 1 ) ;
if ( ! V_11 )
F_79 ( & V_7 -> V_184 -> V_2 ,
L_60 ) ;
else {
F_159 ( V_7 ) ;
F_80 ( & V_7 -> V_184 -> V_2 , L_61
L_62 ) ;
}
F_160 ( V_7 ) ;
F_161 ( V_7 , V_121 ) ;
F_162 ( V_7 , V_121 ) ;
return 0 ;
}
static int T_5 F_163 ( void )
{
F_164 ( L_63 ) ;
return 0 ;
}
static void T_6 F_165 ( void )
{
F_164 ( L_64 ) ;
}
static void F_166 ( struct V_225 * V_184 )
{
struct V_6 * V_7 = F_118 ( & V_184 -> V_2 ) ;
F_49 ( V_7 , 0 , 1 ) ;
if ( ( V_184 -> V_13 == V_230 ) && V_7 -> V_16 . V_227 )
F_138 ( V_7 , V_263 ) ;
F_55 ( V_7 , 0 ) ;
F_56 ( V_7 ) ;
F_152 ( F_150 ( V_7 ) ) ;
}
static int F_167 ( struct V_225 * V_184 )
{
struct V_6 * V_7 = F_118 ( & V_184 -> V_2 ) ;
if ( V_7 -> V_2 )
F_168 ( V_7 -> V_2 ) ;
F_49 ( V_7 , 0 , 1 ) ;
F_123 ( V_7 -> V_229 , F_91 ( V_7 , 0xffffffff ) == 0 ) ;
if ( V_184 -> V_13 == V_265 )
return 0 ;
if ( V_7 -> V_13 == V_14 ) {
if ( V_7 -> V_16 . V_227 )
F_138 ( V_7 , V_263 ) ;
F_154 ( V_7 -> V_184 , 1 ) ;
} else
F_154 ( V_7 -> V_184 , 0 ) ;
return 0 ;
}
static int F_169 ( struct V_225 * V_184 )
{
struct V_6 * V_7 = F_118 ( & V_184 -> V_2 ) ;
int V_11 = 0 ;
if ( V_184 -> V_13 == V_265 )
goto V_179;
if ( V_7 -> V_13 == V_258 ) {
V_11 = F_132 ( V_7 -> V_184 , 1 ) ;
if ( V_11 ) {
F_51 () ;
F_52 ( V_7 -> V_2 ) ;
F_53 () ;
}
} else
V_11 = F_132 ( V_7 -> V_184 , 0 ) ;
V_179:
F_49 ( V_7 , 0xffffffff , 0 ) ;
if ( V_7 -> V_2 )
F_170 ( V_7 -> V_2 ) ;
if ( V_11 )
F_80 ( & V_7 -> V_184 -> V_2 , L_61
L_62 ) ;
return V_11 ;
}
static int F_171 ( struct V_6 * V_7 ,
struct V_105 * V_5 )
{
switch ( V_5 -> V_85 . V_108 ) {
case V_266 :
if ( V_5 -> V_81 . V_252 . V_85 . V_267 ==
V_268 ) {
F_172 ( V_7 , V_5 ) ;
return 0 ;
} else
return 1 ;
case V_269 :
F_173 ( V_7 , V_5 ) ;
return 0 ;
default:
return 1 ;
}
}
static int F_174 ( struct V_6 * V_7 , int V_96 ,
struct V_112 * V_113 )
{
unsigned long V_35 ;
int V_11 = 0 ;
F_16 ( V_7 , 5 , L_65 ) ;
F_123 ( V_7 -> V_229 ,
F_175 ( & V_7 -> V_129 . V_270 , 0 , 1 ) == 0 ) ;
F_176 ( V_7 , V_96 , V_113 ) ;
F_16 ( V_7 , 6 , L_66 ) ;
F_177 ( F_178 ( V_7 -> V_129 . V_174 ) , V_35 ) ;
V_11 = F_179 ( V_7 -> V_129 . V_174 , & V_7 -> V_129 . V_271 ,
( V_272 ) V_113 , 0 , 0 ) ;
F_180 ( F_178 ( V_7 -> V_129 . V_174 ) , V_35 ) ;
if ( V_11 ) {
F_18 ( 2 , L_67
L_68 , V_11 ) ;
F_6 ( V_7 , 2 , L_69 , V_11 ) ;
F_181 ( V_113 -> V_273 , V_113 ) ;
F_182 ( & V_7 -> V_129 . V_270 , 0 ) ;
F_183 ( & V_7 -> V_229 ) ;
}
return V_11 ;
}
static int F_184 ( struct V_6 * V_7 ,
struct V_112 * V_113 , int V_274 )
{
T_4 V_275 , V_276 ;
F_16 ( V_7 , 4 , L_70 ) ;
F_185 ( V_7 , V_113 , V_277 ) ;
V_275 = ( T_4 ) ( V_115 + V_274 ) ;
V_276 = ( T_4 ) V_274 ;
memcpy ( F_186 ( V_113 -> V_81 ) , & V_275 , 2 ) ;
memcpy ( F_187 ( V_113 -> V_81 ) , & V_276 , 2 ) ;
memcpy ( F_188 ( V_113 -> V_81 ) , & V_276 , 2 ) ;
memcpy ( F_189 ( V_113 -> V_81 ) , & V_276 , 2 ) ;
return F_174 ( V_7 , V_275 , V_113 ) ;
}
int F_190 ( struct V_1 * V_2 , void * V_81 , int V_274 )
{
struct V_112 * V_113 ;
struct V_6 * V_7 ;
int V_11 ;
if ( ! V_2 )
return - V_12 ;
V_7 = V_2 -> V_8 ;
if ( ! V_7 )
return - V_12 ;
F_16 ( V_7 , 2 , L_71 ) ;
if ( ( V_7 -> V_13 != V_14 ) &&
( V_7 -> V_13 != V_15 ) )
return - V_12 ;
V_113 = F_191 ( & V_7 -> V_129 ) ;
memcpy ( V_113 -> V_81 + V_115 , V_81 , V_274 ) ;
V_11 = F_184 ( V_7 , V_113 , V_274 ) ;
return V_11 ;
}
int F_192 ( unsigned char * V_39 , struct V_1 * * V_2 ,
int (* F_193)( struct V_1 * , void * ) ,
int (* V_156)( struct V_78 * ) )
{
struct V_6 * V_7 ;
* V_2 = F_11 ( V_39 ) ;
if ( * V_2 == NULL )
return - V_12 ;
V_7 = ( * V_2 ) -> V_8 ;
if ( ! V_7 )
return - V_12 ;
F_16 ( V_7 , 2 , L_72 ) ;
if ( ( F_193 == NULL ) || ( V_156 == NULL ) )
return - V_30 ;
V_7 -> V_155 . F_193 = F_193 ;
V_7 -> V_155 . V_156 = V_156 ;
return 0 ;
}
void F_194 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
if ( ! V_2 )
return;
V_7 = V_2 -> V_8 ;
if ( ! V_7 )
return;
F_16 ( V_7 , 2 , L_73 ) ;
V_7 -> V_155 . F_193 = NULL ;
V_7 -> V_155 . V_156 = NULL ;
return;
}
static void F_195 ( struct V_6 * V_7 ,
enum V_278 V_279 ,
T_7 V_280 , struct V_281 * V_282 , struct V_283 * V_284 )
{
char V_285 [ 7 ] [ 32 ] ;
char * V_286 [ 8 ] ;
int V_109 = 0 ;
switch ( V_279 ) {
case V_287 :
snprintf ( V_285 [ V_109 ] , sizeof( V_285 [ V_109 ] ) , L_74 ,
( V_280 & V_288 )
? L_75 : L_76 ) ;
V_286 [ V_109 ] = V_285 [ V_109 ] ; V_109 ++ ;
if ( V_280 & V_289 ) {
snprintf ( V_285 [ V_109 ] , sizeof( V_285 [ V_109 ] ) , L_77 ,
V_284 -> V_290 ) ;
V_286 [ V_109 ] = V_285 [ V_109 ] ; V_109 ++ ;
}
if ( V_280 & V_291 ) {
snprintf ( V_285 [ V_109 ] , sizeof( V_285 [ V_109 ] ) , L_78 ,
& V_284 -> V_60 ) ;
V_286 [ V_109 ] = V_285 [ V_109 ] ; V_109 ++ ;
}
snprintf ( V_285 [ V_109 ] , sizeof( V_285 [ V_109 ] ) , L_79 ,
V_282 -> V_292 , V_282 -> V_293 , V_282 -> V_294 ) ;
V_286 [ V_109 ] = V_285 [ V_109 ] ; V_109 ++ ;
snprintf ( V_285 [ V_109 ] , sizeof( V_285 [ V_109 ] ) , L_80 , V_282 -> V_295 ) ;
V_286 [ V_109 ] = V_285 [ V_109 ] ; V_109 ++ ;
snprintf ( V_285 [ V_109 ] , sizeof( V_285 [ V_109 ] ) , L_81 ,
V_282 -> V_296 ) ;
V_286 [ V_109 ] = V_285 [ V_109 ] ; V_109 ++ ;
snprintf ( V_285 [ V_109 ] , sizeof( V_285 [ V_109 ] ) , L_82 , V_282 -> V_297 ) ;
V_286 [ V_109 ] = V_285 [ V_109 ] ; V_109 ++ ;
break;
case V_298 :
snprintf ( V_285 [ V_109 ] , sizeof( V_285 [ V_109 ] ) , L_83 ) ;
V_286 [ V_109 ] = V_285 [ V_109 ] ; V_109 ++ ;
break;
case V_299 :
snprintf ( V_285 [ V_109 ] , sizeof( V_285 [ V_109 ] ) , L_84 ) ;
V_286 [ V_109 ] = V_285 [ V_109 ] ; V_109 ++ ;
break;
}
V_286 [ V_109 ] = NULL ;
F_196 ( & V_7 -> V_184 -> V_2 . V_259 , V_260 , V_286 ) ;
}
static void F_197 ( struct V_300 * V_301 )
{
struct V_302 * V_81 =
F_69 ( V_301 , struct V_302 , V_303 ) ;
struct V_304 * V_305 = & V_81 -> V_306 . V_305 [ 0 ] ;
char V_307 [ 32 ] ;
char V_308 [ 32 ] ;
char V_309 [ 32 ] ;
char * V_286 [] = {
V_307 ,
V_308 ,
V_309 ,
NULL
} ;
F_133 ( & V_81 -> V_7 -> V_250 ) ;
V_81 -> V_7 -> V_167 . V_252 . V_310 = V_305 -> V_310 ;
F_148 ( & V_81 -> V_7 -> V_250 ) ;
snprintf ( V_307 , sizeof( V_307 ) , L_85 ) ;
snprintf ( V_308 , sizeof( V_308 ) , L_86 ,
( V_305 -> V_310 == V_311 ) ? L_87 :
( V_305 -> V_310 == V_312 ) ? L_88 :
( V_305 -> V_310 == V_313 ) ? L_89 :
L_90 ) ;
snprintf ( V_309 , sizeof( V_309 ) , L_91 ,
( V_305 -> V_13 == V_314 ) ? L_92 :
( V_305 -> V_13 == V_315 ) ? L_93 :
( V_305 -> V_13 == V_316 ) ? L_94 :
L_90 ) ;
F_196 ( & V_81 -> V_7 -> V_184 -> V_2 . V_259 ,
V_260 , V_286 ) ;
F_24 ( V_81 ) ;
}
static void F_172 ( struct V_6 * V_7 ,
struct V_105 * V_5 )
{
struct V_317 * V_306 =
& V_5 -> V_81 . V_252 . V_81 . V_318 ;
struct V_302 * V_81 ;
int V_319 ;
F_16 ( V_7 , 2 , L_95 ) ;
if ( V_306 -> V_320 != sizeof( struct V_304 ) ) {
F_6 ( V_7 , 2 , L_96 , V_306 -> V_320 ) ;
return;
}
V_319 = sizeof( struct V_304 ) * V_306 -> V_321 ;
V_81 = F_198 ( sizeof( struct V_302 ) + V_319 ,
V_66 ) ;
if ( ! V_81 ) {
F_16 ( V_7 , 2 , L_97 ) ;
return;
}
F_199 ( & V_81 -> V_303 , F_197 ) ;
V_81 -> V_7 = V_7 ;
memcpy ( & V_81 -> V_306 , V_306 ,
sizeof( struct V_317 ) + V_319 ) ;
F_200 ( V_322 , & V_81 -> V_303 ) ;
}
static void F_201 ( struct V_300 * V_301 )
{
struct V_323 * V_81 =
F_69 ( V_301 , struct V_323 , V_303 ) ;
int V_109 ;
if ( V_81 -> V_324 . V_325 ) {
F_79 ( & V_81 -> V_7 -> V_184 -> V_2 ,
L_98 ,
V_81 -> V_7 -> V_2 -> V_185 ,
( V_81 -> V_324 . V_325 == 0x01 )
? L_99
: ( V_81 -> V_324 . V_325 == 0x02 )
? L_100
: L_101 ) ;
F_133 ( & V_81 -> V_7 -> V_250 ) ;
V_81 -> V_7 -> V_167 . V_252 . V_326 = 0 ;
F_148 ( & V_81 -> V_7 -> V_250 ) ;
F_195 ( V_81 -> V_7 , V_298 ,
0 , NULL , NULL ) ;
} else
for ( V_109 = 0 ; V_109 < V_81 -> V_324 . V_321 ; V_109 ++ ) {
struct V_327 * V_305 =
& V_81 -> V_324 . V_305 [ V_109 ] ;
F_195 ( V_81 -> V_7 ,
V_287 ,
V_305 -> V_328 ,
& V_305 -> V_282 , & V_305 -> V_284 ) ;
}
F_24 ( V_81 ) ;
}
static void F_173 ( struct V_6 * V_7 ,
struct V_105 * V_5 )
{
struct V_329 * V_324 =
& V_5 -> V_81 . V_330 ;
struct V_323 * V_81 ;
int V_319 ;
F_16 ( V_7 , 2 , L_102 ) ;
if ( V_5 -> V_85 . V_106 != 0x0000 ) {
if ( V_5 -> V_85 . V_106 == 0x0010 ) {
if ( V_324 -> V_325 == 0x00 )
V_324 -> V_325 = 0xff ;
} else {
F_6 ( V_7 , 2 , L_103 ,
V_5 -> V_85 . V_106 ) ;
return;
}
}
V_319 = sizeof( struct V_327 ) *
V_324 -> V_321 ;
V_81 = F_198 ( sizeof( struct V_323 ) + V_319 ,
V_66 ) ;
if ( ! V_81 ) {
F_16 ( V_7 , 2 , L_104 ) ;
return;
}
F_199 ( & V_81 -> V_303 , F_201 ) ;
V_81 -> V_7 = V_7 ;
memcpy ( & V_81 -> V_324 , V_324 ,
sizeof( struct V_329 ) + V_319 ) ;
F_200 ( V_322 , & V_81 -> V_303 ) ;
}
static int F_202 ( struct V_6 * V_7 ,
struct V_331 * V_332 , enum V_333 V_334 )
{
int V_11 ;
switch ( V_332 -> V_335 ) {
case V_46 :
switch ( V_332 -> V_336 ) {
case 0x0000 :
V_11 = 0 ;
break;
case 0x0004 :
V_11 = - V_48 ;
break;
case 0x000C :
V_11 = - V_12 ;
F_203 ( & V_7 -> V_184 -> V_2 ,
L_105 ) ;
break;
case 0x0014 :
switch ( V_334 ) {
case V_337 :
V_11 = - V_53 ;
F_203 ( & V_7 -> V_184 -> V_2 ,
L_106 ) ;
break;
case V_338 :
V_11 = - V_220 ;
F_203 ( & V_7 -> V_184 -> V_2 ,
L_107 ) ;
break;
default:
V_11 = - V_59 ;
}
break;
case 0x0018 :
V_11 = - V_220 ;
F_203 ( & V_7 -> V_184 -> V_2 ,
L_108 ) ;
break;
case 0x001C :
V_11 = - V_53 ;
F_203 ( & V_7 -> V_184 -> V_2 ,
L_109 ) ;
break;
case 0x0024 :
V_11 = - V_220 ;
F_203 ( & V_7 -> V_184 -> V_2 ,
L_107 ) ;
break;
case 0x0020 :
V_11 = - V_339 ;
F_203 ( & V_7 -> V_184 -> V_2 ,
L_110 ) ;
break;
default:
V_11 = - V_59 ;
}
break;
case V_340 :
V_11 = - V_48 ;
break;
case V_341 :
V_11 = - V_48 ;
break;
default:
V_11 = - V_59 ;
}
if ( V_11 ) {
F_6 ( V_7 , 2 , L_111 , V_332 -> V_335 ) ;
F_6 ( V_7 , 2 , L_112 , V_332 -> V_336 ) ;
}
return V_11 ;
}
static int F_204 ( struct V_6 * V_7 ,
struct V_103 * V_104 , unsigned long V_81 )
{
struct V_105 * V_5 = (struct V_105 * ) V_81 ;
struct V_331 * V_332 = (struct V_331 * ) V_104 -> V_342 ;
F_16 ( V_7 , 2 , L_113 ) ;
V_332 -> V_335 = V_5 -> V_85 . V_106 ;
V_332 -> V_336 = V_5 -> V_81 . V_252 . V_85 . V_106 ;
if ( ( V_332 -> V_335 == 0 ) && ( V_332 -> V_336 == 0 ) ) {
V_332 -> V_81 . V_343 =
V_5 -> V_81 . V_252 . V_81 . V_344 . V_345 ;
} else {
V_332 -> V_81 . V_343 = 0 ;
}
return 0 ;
}
static void F_135 ( struct V_6 * V_7 )
{
struct V_112 * V_113 ;
struct V_105 * V_5 ;
struct V_331 V_332 ;
F_16 ( V_7 , 2 , L_114 ) ;
V_113 = F_39 ( V_7 , V_266 , 0 ) ;
if ( ! V_113 )
return;
V_5 = (struct V_105 * ) ( V_113 -> V_81 + V_115 ) ;
V_5 -> V_81 . V_252 . V_85 . V_346 =
sizeof( struct V_347 ) +
sizeof( struct V_348 ) ;
V_5 -> V_81 . V_252 . V_85 . V_267 =
V_349 ;
V_5 -> V_81 . V_252 . V_85 . V_350 = 1 ;
V_5 -> V_81 . V_252 . V_85 . V_351 = 1 ;
if ( F_40 ( V_7 , V_113 , F_204 ,
( void * ) & V_332 ) ||
F_202 ( V_7 , & V_332 ,
V_349 ) ) {
V_7 -> V_167 . V_252 . V_310 = V_311 ;
return;
}
V_7 -> V_167 . V_252 . V_253 = V_332 . V_81 . V_343 ;
}
static int F_205 ( struct V_6 * V_7 ,
struct V_103 * V_104 , unsigned long V_81 )
{
struct V_105 * V_5 = (struct V_105 * ) V_81 ;
struct V_352 * V_306 = & V_5 -> V_81 . V_252 . V_81 . V_353 ;
struct V_331 * V_332 = (struct V_331 * ) V_104 -> V_342 ;
F_16 ( V_7 , 2 , L_115 ) ;
V_332 -> V_335 = V_5 -> V_85 . V_106 ;
V_332 -> V_336 = V_5 -> V_81 . V_252 . V_85 . V_106 ;
if ( ( V_332 -> V_335 != 0 ) || ( V_332 -> V_336 != 0 ) )
return 0 ;
if ( V_306 -> V_320 != sizeof( struct V_304 ) ) {
V_332 -> V_336 = 0xffff ;
F_6 ( V_7 , 2 , L_116 , V_306 -> V_320 ) ;
return 0 ;
}
if ( V_306 -> V_321 > 0 ) {
if ( V_332 -> V_81 . V_306 . V_310 )
* V_332 -> V_81 . V_306 . V_310 = V_306 -> V_305 [ 0 ] . V_310 ;
if ( V_332 -> V_81 . V_306 . V_13 )
* V_332 -> V_81 . V_306 . V_13 = V_306 -> V_305 [ 0 ] . V_13 ;
}
return 0 ;
}
int F_206 ( struct V_6 * V_7 ,
enum V_354 * V_310 , enum V_355 * V_13 )
{
int V_11 = 0 ;
struct V_112 * V_113 ;
struct V_105 * V_5 ;
struct V_331 V_332 = {
. V_81 = {
. V_306 = {
. V_310 = V_310 ,
. V_13 = V_13 ,
} ,
} ,
} ;
F_16 ( V_7 , 2 , L_117 ) ;
if ( ! ( V_7 -> V_167 . V_252 . V_253 & V_356 ) )
return - V_34 ;
V_113 = F_39 ( V_7 , V_266 , 0 ) ;
if ( ! V_113 )
return - V_58 ;
V_5 = (struct V_105 * ) ( V_113 -> V_81 + V_115 ) ;
V_5 -> V_81 . V_252 . V_85 . V_346 =
sizeof( struct V_347 ) ;
V_5 -> V_81 . V_252 . V_85 . V_267 =
V_356 ;
V_5 -> V_81 . V_252 . V_85 . V_350 = 1 ;
V_5 -> V_81 . V_252 . V_85 . V_351 = 1 ;
V_11 = F_40 ( V_7 , V_113 , F_205 ,
( void * ) & V_332 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_202 ( V_7 , & V_332 , V_356 ) ;
return V_11 ;
}
static int F_207 ( struct V_6 * V_7 ,
struct V_103 * V_104 , unsigned long V_81 )
{
struct V_105 * V_5 = (struct V_105 * ) V_81 ;
struct V_331 * V_332 = (struct V_331 * ) V_104 -> V_342 ;
F_16 ( V_7 , 2 , L_118 ) ;
V_332 -> V_335 = V_5 -> V_85 . V_106 ;
V_332 -> V_336 = V_5 -> V_81 . V_252 . V_85 . V_106 ;
return 0 ;
}
int F_208 ( struct V_6 * V_7 , enum V_354 V_310 )
{
int V_11 = 0 ;
int V_346 ;
struct V_112 * V_113 ;
struct V_105 * V_5 ;
struct V_331 V_332 ;
enum V_333 V_334 ;
F_16 ( V_7 , 2 , L_119 ) ;
switch ( V_310 ) {
case V_311 :
V_334 = V_357 ;
V_346 = sizeof( struct V_347 ) +
sizeof( struct V_358 ) ;
break;
case V_312 :
V_334 = V_337 ;
V_346 = sizeof( struct V_347 ) +
sizeof( struct V_359 ) ;
break;
case V_313 :
V_334 = V_338 ;
V_346 = sizeof( struct V_347 ) +
sizeof( struct V_360 ) ;
break;
default:
return - V_30 ;
}
if ( ! ( V_7 -> V_167 . V_252 . V_253 & V_334 ) )
return - V_34 ;
V_113 = F_39 ( V_7 , V_266 , 0 ) ;
if ( ! V_113 )
return - V_58 ;
V_5 = (struct V_105 * ) ( V_113 -> V_81 + V_115 ) ;
V_5 -> V_81 . V_252 . V_85 . V_346 = V_346 ;
V_5 -> V_81 . V_252 . V_85 . V_267 = V_334 ;
V_5 -> V_81 . V_252 . V_85 . V_350 = 1 ;
V_5 -> V_81 . V_252 . V_85 . V_351 = 1 ;
V_11 = F_40 ( V_7 , V_113 , F_207 ,
( void * ) & V_332 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_202 ( V_7 , & V_332 , V_334 ) ;
return V_11 ;
}
static int F_209 ( struct V_6 * V_7 , int V_361 , T_4 V_362 )
{
int V_11 ;
if ( V_361 == 0 )
switch ( V_362 ) {
case 0x0001 :
V_11 = 0 ;
break;
case 0x0004 :
case 0x0100 :
case 0x0106 :
V_11 = - V_48 ;
F_203 ( & V_7 -> V_184 -> V_2 ,
L_120 ) ;
break;
case 0x0107 :
V_11 = - V_363 ;
break;
default:
V_11 = - V_59 ;
}
else
V_11 = - V_59 ;
if ( V_11 ) {
F_6 ( V_7 , 2 , L_121 , V_361 ) ;
F_6 ( V_7 , 2 , L_122 , V_362 ) ;
}
return V_11 ;
}
static void F_210 ( void * V_364 ,
enum V_365 type , void * V_305 )
{
struct V_6 * V_7 = (struct V_6 * ) V_364 ;
struct V_366 * V_367 ;
T_7 V_280 ;
if ( type != V_368 ) {
F_60 ( 1 ) ;
return;
}
V_367 = (struct V_366 * ) V_305 ;
V_280 = V_291 ;
if ( V_367 -> V_284 . V_290 )
V_280 |= V_289 ;
F_195 ( V_7 , V_287 , V_280 ,
(struct V_281 * ) & V_367 -> V_369 ,
(struct V_283 * ) & V_367 -> V_284 ) ;
}
int F_211 ( struct V_6 * V_7 , int V_370 )
{
int V_11 ;
T_4 V_362 ;
struct V_371 * V_372 ;
struct V_373 V_374 ;
if ( ! V_7 )
return - V_30 ;
if ( ! V_7 -> V_167 . V_252 . V_253 )
return - V_34 ;
V_372 = F_150 ( V_7 ) ;
F_212 ( V_372 , & V_374 ) ;
if ( V_370 ) {
F_195 ( V_7 , V_299 , 0 , NULL , NULL ) ;
V_11 = F_213 ( V_374 , 1 , & V_362 ,
F_210 , V_7 ) ;
} else
V_11 = F_213 ( V_374 , 0 , & V_362 , NULL , NULL ) ;
return F_209 ( V_7 , V_11 , V_362 ) ;
}
