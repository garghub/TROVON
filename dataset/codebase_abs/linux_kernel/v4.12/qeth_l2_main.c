static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned long V_5 ;
int V_6 = 0 ;
F_2 ( & V_7 . V_8 , V_5 ) ;
F_3 (card, &qeth_core_card_list.list, list) {
if ( V_4 -> V_2 == V_2 ) {
V_6 = V_9 ;
break;
}
}
F_4 ( & V_7 . V_8 , V_5 ) ;
return V_6 ;
}
static struct V_1 * F_5 ( unsigned char * V_10 )
{
struct V_3 * V_4 ;
struct V_1 * V_11 ;
T_1 V_12 ;
unsigned long V_5 ;
struct V_13 V_14 ;
V_11 = NULL ;
memcpy ( & V_12 , V_10 , 2 ) ;
F_2 ( & V_7 . V_8 , V_5 ) ;
F_3 (card, &qeth_core_card_list.list, list) {
F_6 ( F_7 ( V_4 ) , & V_14 ) ;
if ( V_14 . V_15 == V_12 ) {
V_11 = V_4 -> V_2 ;
break;
}
}
F_4 ( & V_7 . V_8 , V_5 ) ;
return V_11 ;
}
static int F_8 ( struct V_3 * V_4 , int V_16 )
{
int V_6 ;
if ( V_16 )
F_9 ( V_4 , 2 , L_1 , V_16 ) ;
switch ( V_16 ) {
case V_17 :
V_6 = 0 ;
break;
case V_18 :
V_6 = - V_19 ;
break;
case V_20 :
V_6 = - V_21 ;
break;
case V_22 :
case V_23 :
V_6 = - V_24 ;
break;
case V_25 :
case V_26 :
V_6 = - V_27 ;
break;
case V_28 :
V_6 = - V_29 ;
break;
case - V_30 :
V_6 = - V_30 ;
break;
default:
V_6 = - V_31 ;
break;
}
return V_6 ;
}
static int F_10 ( struct V_3 * V_4 , T_2 * V_32 ,
enum V_33 V_34 )
{
struct V_35 * V_36 ;
struct V_37 * V_38 ;
F_11 ( V_4 , 2 , L_2 ) ;
V_38 = F_12 ( V_4 , V_34 , V_39 ) ;
if ( ! V_38 )
return - V_30 ;
V_36 = (struct V_35 * ) ( V_38 -> V_40 + V_41 ) ;
V_36 -> V_40 . V_42 . V_43 = V_44 ;
memcpy ( & V_36 -> V_40 . V_42 . V_32 , V_32 , V_44 ) ;
return F_8 ( V_4 , F_13 ( V_4 , V_38 ,
NULL , NULL ) ) ;
}
static int F_14 ( struct V_3 * V_4 , T_2 * V_32 )
{
int V_6 ;
F_11 ( V_4 , 2 , L_3 ) ;
V_6 = F_10 ( V_4 , V_32 , V_45 ) ;
if ( V_6 == 0 ) {
V_4 -> V_46 . V_47 |= V_48 ;
memcpy ( V_4 -> V_2 -> V_49 , V_32 , V_44 ) ;
F_15 ( & V_4 -> V_50 -> V_2 ,
L_4 ,
V_4 -> V_2 -> V_49 , V_4 -> V_2 -> V_51 ) ;
} else {
V_4 -> V_46 . V_47 &= ~ V_48 ;
switch ( V_6 ) {
case - V_24 :
F_16 ( & V_4 -> V_50 -> V_2 ,
L_5 , V_32 ) ;
break;
case - V_27 :
F_16 ( & V_4 -> V_50 -> V_2 ,
L_6 , V_32 ) ;
break;
}
}
return V_6 ;
}
static int F_17 ( struct V_3 * V_4 , T_2 * V_32 )
{
int V_6 ;
F_11 ( V_4 , 2 , L_7 ) ;
if ( ! ( V_4 -> V_46 . V_47 & V_48 ) )
return 0 ;
V_6 = F_10 ( V_4 , V_32 , V_52 ) ;
if ( V_6 == 0 )
V_4 -> V_46 . V_47 &= ~ V_48 ;
return V_6 ;
}
static int F_18 ( struct V_3 * V_4 , T_2 * V_32 )
{
int V_6 ;
F_11 ( V_4 , 2 , L_8 ) ;
V_6 = F_10 ( V_4 , V_32 , V_53 ) ;
if ( V_6 == - V_24 )
F_19 ( 2 , L_9 ,
V_32 , F_20 ( V_4 ) ) ;
else if ( V_6 )
F_19 ( 2 , L_10 ,
V_32 , F_20 ( V_4 ) , V_6 ) ;
return V_6 ;
}
static int F_21 ( struct V_3 * V_4 , T_2 * V_32 )
{
int V_6 ;
F_11 ( V_4 , 2 , L_11 ) ;
V_6 = F_10 ( V_4 , V_32 , V_54 ) ;
if ( V_6 )
F_19 ( 2 ,
L_12 ,
V_32 , F_20 ( V_4 ) , V_6 ) ;
return V_6 ;
}
static int F_22 ( struct V_3 * V_4 , struct V_55 * V_32 )
{
if ( V_32 -> V_56 ) {
return F_10 ( V_4 , V_32 -> V_57 ,
V_45 ) ;
} else {
return F_18 ( V_4 , V_32 -> V_57 ) ;
}
}
static int F_23 ( struct V_3 * V_4 , struct V_55 * V_32 )
{
if ( V_32 -> V_56 ) {
return F_10 ( V_4 , V_32 -> V_57 ,
V_52 ) ;
} else {
return F_21 ( V_4 , V_32 -> V_57 ) ;
}
}
static void F_24 ( struct V_3 * V_4 )
{
struct V_55 * V_32 ;
struct V_58 * V_59 ;
int V_60 ;
F_25 ( & V_4 -> V_61 ) ;
F_26 (card->mac_htable, i, tmp, mac, hnode) {
F_27 ( & V_32 -> V_62 ) ;
F_28 ( V_32 ) ;
}
F_29 ( & V_4 -> V_61 ) ;
}
static inline T_3 F_30 ( const T_4 * V_63 )
{
return F_31 ( ( T_3 * ) ( & V_63 [ 2 ] ) ) ;
}
static inline int F_32 ( struct V_3 * V_4 ,
struct V_64 * V_65 )
{
if ( V_4 -> V_46 . type == V_66 )
return V_67 ;
if ( F_33 ( V_65 -> V_40 ) )
return V_68 ;
if ( F_34 ( V_65 -> V_40 ) )
return V_69 ;
return V_67 ;
}
static inline void F_35 ( struct V_3 * V_4 ,
struct V_70 * V_71 , struct V_64 * V_65 )
{
struct V_72 * V_73 = F_36 ( V_65 ) ;
if ( V_73 -> V_74 == V_75 )
V_71 -> V_71 . V_76 . V_5 [ 1 ] |= V_77 ;
V_71 -> V_71 . V_76 . V_5 [ 1 ] |= V_78 |
V_79 ;
V_73 -> V_80 = 0 ;
if ( V_4 -> V_81 . V_82 )
V_4 -> V_83 . V_84 ++ ;
}
static void F_37 ( struct V_3 * V_4 , struct V_70 * V_71 ,
struct V_64 * V_65 , int V_85 )
{
struct V_86 * V_87 = (struct V_86 * ) F_38 ( V_65 ) ;
memset ( V_71 , 0 , sizeof( struct V_70 ) ) ;
V_71 -> V_71 . V_76 . V_88 = V_89 ;
if ( V_85 == V_69 )
V_71 -> V_71 . V_76 . V_5 [ 2 ] |= V_90 ;
else if ( V_85 == V_68 )
V_71 -> V_71 . V_76 . V_5 [ 2 ] |= V_91 ;
else
V_71 -> V_71 . V_76 . V_5 [ 2 ] |= V_92 ;
V_71 -> V_71 . V_76 . V_93 = V_65 -> V_94 - sizeof( struct V_70 ) ;
if ( V_87 -> V_95 == F_39 ( V_96 ) ) {
V_71 -> V_71 . V_76 . V_5 [ 2 ] |= V_97 ;
V_71 -> V_71 . V_76 . V_98 = F_40 ( V_87 -> V_99 ) ;
}
}
static int F_41 ( struct V_3 * V_4 ,
struct V_100 * V_101 , unsigned long V_40 )
{
struct V_35 * V_36 ;
F_11 ( V_4 , 2 , L_13 ) ;
V_36 = (struct V_35 * ) V_40 ;
if ( V_36 -> V_71 . V_102 ) {
F_19 ( 2 , L_14
L_15 , V_36 -> V_40 . V_103 . V_98 ,
F_20 ( V_4 ) , V_36 -> V_71 . V_102 ) ;
F_9 ( V_4 , 2 , L_16 , V_36 -> V_71 . V_104 ) ;
F_9 ( V_4 , 2 , L_17 , V_36 -> V_71 . V_102 ) ;
}
return 0 ;
}
static int F_42 ( struct V_3 * V_4 , T_1 V_60 ,
enum V_33 V_34 )
{
struct V_35 * V_36 ;
struct V_37 * V_38 ;
F_9 ( V_4 , 4 , L_18 , V_34 ) ;
V_38 = F_12 ( V_4 , V_34 , V_39 ) ;
if ( ! V_38 )
return - V_30 ;
V_36 = (struct V_35 * ) ( V_38 -> V_40 + V_41 ) ;
V_36 -> V_40 . V_103 . V_98 = V_60 ;
return F_13 ( V_4 , V_38 ,
F_41 , NULL ) ;
}
static void F_43 ( struct V_3 * V_4 )
{
struct V_105 * V_88 ;
F_11 ( V_4 , 3 , L_19 ) ;
F_25 ( & V_4 -> V_106 ) ;
F_3 (id, &card->vid_list, list) {
F_42 ( V_4 , V_88 -> V_107 , V_108 ) ;
}
F_29 ( & V_4 -> V_106 ) ;
}
static int F_44 ( struct V_1 * V_2 ,
T_5 V_109 , T_6 V_107 )
{
struct V_3 * V_4 = V_2 -> V_110 ;
struct V_105 * V_88 ;
int V_6 ;
F_9 ( V_4 , 4 , L_20 , V_107 ) ;
if ( ! V_107 )
return 0 ;
if ( V_4 -> V_46 . type == V_111 ) {
F_11 ( V_4 , 3 , L_21 ) ;
return 0 ;
}
if ( F_45 ( V_4 , V_112 ) ) {
F_11 ( V_4 , 3 , L_22 ) ;
return 0 ;
}
V_88 = F_46 ( sizeof( struct V_105 ) , V_113 ) ;
if ( V_88 ) {
V_88 -> V_107 = V_107 ;
V_6 = F_42 ( V_4 , V_107 , V_108 ) ;
if ( V_6 ) {
F_28 ( V_88 ) ;
return V_6 ;
}
F_25 ( & V_4 -> V_106 ) ;
F_47 ( & V_88 -> V_114 , & V_4 -> V_115 ) ;
F_29 ( & V_4 -> V_106 ) ;
} else {
return - V_30 ;
}
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
T_5 V_109 , T_6 V_107 )
{
struct V_105 * V_88 , * V_116 = NULL ;
struct V_3 * V_4 = V_2 -> V_110 ;
int V_6 = 0 ;
F_9 ( V_4 , 4 , L_23 , V_107 ) ;
if ( V_4 -> V_46 . type == V_111 ) {
F_11 ( V_4 , 3 , L_24 ) ;
return 0 ;
}
if ( F_45 ( V_4 , V_112 ) ) {
F_11 ( V_4 , 3 , L_25 ) ;
return 0 ;
}
F_25 ( & V_4 -> V_106 ) ;
F_3 (id, &card->vid_list, list) {
if ( V_88 -> V_107 == V_107 ) {
F_49 ( & V_88 -> V_114 ) ;
V_116 = V_88 ;
break;
}
}
F_29 ( & V_4 -> V_106 ) ;
if ( V_116 ) {
V_6 = F_42 ( V_4 , V_107 , V_117 ) ;
F_28 ( V_116 ) ;
}
F_50 ( V_4 -> V_2 ) ;
return V_6 ;
}
static void F_51 ( struct V_3 * V_4 , int V_118 )
{
F_52 ( V_119 , 2 , L_26 ) ;
F_53 ( V_119 , 2 , & V_4 , sizeof( void * ) ) ;
F_54 ( V_4 , 0 , 1 ) ;
if ( V_4 -> V_120 . V_121 == V_122 &&
V_4 -> V_123 . V_121 == V_122 &&
( V_4 -> V_121 == V_124 ) ) {
if ( V_118 &&
V_4 -> V_46 . type != V_66 ) {
F_55 ( V_4 -> V_2 ) ;
} else {
F_56 () ;
F_57 ( V_4 -> V_2 ) ;
F_58 () ;
}
V_4 -> V_46 . V_47 &= ~ V_48 ;
V_4 -> V_121 = V_125 ;
}
if ( V_4 -> V_121 == V_125 ) {
F_24 ( V_4 ) ;
F_59 ( V_4 ) ;
V_4 -> V_121 = V_126 ;
}
if ( V_4 -> V_121 == V_126 ) {
F_60 ( V_4 , 0 ) ;
F_61 ( V_4 ) ;
F_62 ( V_4 ) ;
V_4 -> V_121 = V_127 ;
}
if ( V_4 -> V_121 == V_127 ) {
F_63 ( & V_4 -> V_120 ) ;
F_63 ( & V_4 -> V_123 ) ;
}
}
static int F_64 ( struct V_3 * V_4 ,
int V_128 , int * V_129 )
{
int V_130 = 0 ;
struct V_64 * V_65 ;
struct V_70 * V_71 ;
unsigned int V_94 ;
* V_129 = 0 ;
F_65 ( ! V_128 ) ;
while ( V_128 ) {
V_65 = F_66 ( V_4 ,
& V_4 -> V_131 . V_132 -> V_133 [ V_4 -> V_134 . V_135 ] ,
& V_4 -> V_134 . V_136 , & V_4 -> V_134 . V_137 , & V_71 ) ;
if ( ! V_65 ) {
* V_129 = 1 ;
break;
}
V_65 -> V_2 = V_4 -> V_2 ;
switch ( V_71 -> V_71 . V_76 . V_88 ) {
case V_89 :
V_65 -> V_138 = V_139 ;
V_65 -> V_74 = F_67 ( V_65 , V_65 -> V_2 ) ;
if ( ( V_4 -> V_2 -> V_140 & V_141 )
&& ( ( V_71 -> V_71 . V_76 . V_5 [ 1 ] &
( V_79 |
V_78 ) ) ==
( V_79 |
V_78 ) ) )
V_65 -> V_142 = V_143 ;
else
V_65 -> V_142 = V_144 ;
if ( V_65 -> V_74 == F_68 ( V_145 ) )
* ( ( V_146 * ) V_65 -> V_147 ) = ++ V_4 -> V_148 . V_149 ;
V_94 = V_65 -> V_94 ;
F_69 ( & V_4 -> V_150 , V_65 ) ;
break;
case V_151 :
if ( V_4 -> V_46 . type == V_66 ) {
F_70 ( V_65 , sizeof( struct V_70 ) ) ;
F_71 ( V_65 , V_71 ,
sizeof( struct V_70 ) ) ;
V_94 = V_65 -> V_94 ;
V_4 -> V_152 . V_153 ( V_65 ) ;
break;
}
default:
F_72 ( V_65 ) ;
F_11 ( V_4 , 3 , L_27 ) ;
F_53 ( V_154 , 3 , V_71 , V_155 ) ;
continue;
}
V_130 ++ ;
V_128 -- ;
V_4 -> V_156 . V_157 ++ ;
V_4 -> V_156 . V_158 += V_94 ;
}
return V_130 ;
}
static int F_73 ( struct V_3 * V_4 )
{
int V_6 = 0 ;
char V_159 [] = { 0x02 , 0x00 , 0x00 } ;
F_52 ( V_119 , 2 , L_28 ) ;
F_74 ( V_119 , 2 , L_29 , F_75 ( V_4 ) ) ;
if ( F_76 ( V_4 , V_160 ) ) {
V_6 = F_77 ( V_4 ) ;
if ( V_6 ) {
F_19 ( 2 , L_30
L_31 ,
F_75 ( V_4 ) , V_6 ) ;
}
}
if ( V_4 -> V_46 . type == V_161 ||
V_4 -> V_46 . type == V_111 ||
V_4 -> V_46 . type == V_162 ||
V_4 -> V_46 . V_163 ) {
V_6 = F_78 ( V_4 ) ;
if ( V_6 ) {
F_19 ( 2 , L_32
L_33 , F_75 ( V_4 ) , V_6 ) ;
F_74 ( V_119 , 2 , L_34 , V_6 ) ;
return V_6 ;
}
F_53 ( V_119 , 2 , V_4 -> V_2 -> V_49 , V_44 ) ;
} else {
F_79 ( V_4 -> V_2 -> V_49 ) ;
memcpy ( V_4 -> V_2 -> V_49 , V_159 , 3 ) ;
}
return 0 ;
}
static int F_80 ( struct V_1 * V_2 , void * V_164 )
{
struct V_165 * V_63 = V_164 ;
struct V_3 * V_4 = V_2 -> V_110 ;
int V_6 = 0 ;
F_11 ( V_4 , 3 , L_35 ) ;
if ( F_1 ( V_2 ) != V_9 ) {
F_11 ( V_4 , 3 , L_36 ) ;
return - V_19 ;
}
if ( V_4 -> V_46 . type == V_66 ||
V_4 -> V_46 . type == V_111 ||
V_4 -> V_46 . type == V_162 ) {
F_11 ( V_4 , 3 , L_37 ) ;
return - V_19 ;
}
F_81 ( V_4 , 3 , V_63 -> V_166 , V_44 ) ;
if ( F_45 ( V_4 , V_112 ) ) {
F_11 ( V_4 , 3 , L_38 ) ;
return - V_167 ;
}
V_6 = F_17 ( V_4 , & V_4 -> V_2 -> V_49 [ 0 ] ) ;
if ( ! V_6 || ( V_6 == - V_29 ) )
V_6 = F_14 ( V_4 , V_63 -> V_166 ) ;
return V_6 ? - V_168 : 0 ;
}
static void F_82 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
enum V_169 V_170 ;
int V_171 ;
int V_6 ;
F_11 ( V_4 , 3 , L_39 ) ;
if ( ! V_4 -> V_81 . V_172 . V_173 )
return;
V_170 = ( V_2 -> V_5 & V_174 ) ? V_175
: V_176 ;
if ( V_170 == V_4 -> V_46 . V_170 )
return;
if ( V_170 == V_175 ) {
if ( V_4 -> V_81 . V_172 . V_177 )
V_171 = V_178 ;
else
V_171 = V_179 ;
} else
V_171 = V_180 ;
V_6 = F_83 ( V_4 , V_171 ) ;
F_74 ( V_119 , 2 , L_40 ,
( V_170 == V_175 ) ? '+' : '-' , V_6 ) ;
if ( ! V_6 ) {
V_4 -> V_81 . V_172 . V_171 = V_171 ;
V_4 -> V_46 . V_170 = V_170 ;
}
}
static void
F_84 ( struct V_3 * V_4 , struct V_181 * V_182 , T_4 V_56 )
{
struct V_55 * V_32 ;
F_85 (card->mac_htable, mac, hnode,
qeth_l2_mac_hash(ha->addr)) {
if ( V_56 == V_32 -> V_56 &&
! memcmp ( V_182 -> V_63 , V_32 -> V_57 , V_44 ) ) {
V_32 -> V_183 = V_184 ;
return;
}
}
V_32 = F_86 ( sizeof( struct V_55 ) , V_113 ) ;
if ( ! V_32 )
return;
memcpy ( V_32 -> V_57 , V_182 -> V_63 , V_44 ) ;
V_32 -> V_56 = V_56 ;
V_32 -> V_183 = V_185 ;
F_87 ( V_4 -> V_186 , & V_32 -> V_62 ,
F_30 ( V_32 -> V_57 ) ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_110 ;
struct V_181 * V_182 ;
struct V_55 * V_32 ;
struct V_58 * V_59 ;
int V_60 ;
int V_6 ;
if ( V_4 -> V_46 . type == V_66 )
return;
F_11 ( V_4 , 3 , L_41 ) ;
if ( F_88 ( V_4 , V_112 ) &&
( V_4 -> V_121 != V_124 ) )
return;
F_25 ( & V_4 -> V_61 ) ;
F_89 (ha, dev)
F_84 ( V_4 , V_182 , 0 ) ;
F_90 (ha, dev)
F_84 ( V_4 , V_182 , 1 ) ;
F_26 (card->mac_htable, i, tmp, mac, hnode) {
if ( V_32 -> V_183 == V_187 ) {
F_23 ( V_4 , V_32 ) ;
F_27 ( & V_32 -> V_62 ) ;
F_28 ( V_32 ) ;
} else if ( V_32 -> V_183 == V_185 ) {
V_6 = F_22 ( V_4 , V_32 ) ;
if ( V_6 ) {
F_27 ( & V_32 -> V_62 ) ;
F_28 ( V_32 ) ;
} else
V_32 -> V_183 = V_187 ;
} else
V_32 -> V_183 = V_187 ;
}
F_29 ( & V_4 -> V_61 ) ;
if ( F_91 ( V_4 , V_188 ) )
F_92 ( V_4 ) ;
else
F_82 ( V_4 ) ;
}
static T_7 F_93 ( struct V_64 * V_65 ,
struct V_1 * V_2 )
{
int V_6 ;
struct V_70 * V_71 = NULL ;
int V_189 = 0 ;
struct V_3 * V_4 = V_2 -> V_110 ;
struct V_64 * V_190 = V_65 ;
int V_85 = F_32 ( V_4 , V_65 ) ;
struct V_191 * V_192 ;
int V_193 = V_65 -> V_94 ;
int V_194 = - 1 ;
int V_195 = 0 ;
int V_196 = 0 ;
int V_197 ;
if ( V_4 -> V_131 . V_198 || ( V_85 &&
V_4 -> V_46 . V_199 ) )
V_192 = V_4 -> V_131 . V_200 [ F_94 ( V_4 , V_65 ,
F_95 ( V_65 ) , V_85 ) ] ;
else
V_192 = V_4 -> V_131 . V_200 [ V_4 -> V_131 . V_201 ] ;
if ( ( V_4 -> V_121 != V_124 ) || ! V_4 -> V_202 ) {
V_4 -> V_156 . V_203 ++ ;
goto V_204;
}
if ( ( V_4 -> V_46 . type == V_66 ) &&
( V_65 -> V_74 == F_68 ( V_205 ) ) )
goto V_204;
if ( V_4 -> V_81 . V_82 ) {
V_4 -> V_83 . V_206 ++ ;
V_4 -> V_83 . V_207 = F_96 () ;
}
F_97 ( V_2 ) ;
if ( ( V_4 -> V_46 . type != V_161 ) &&
! F_98 ( V_4 , V_190 , 0 , 0 ) ) {
int V_208 = F_99 ( V_190 ) ;
if ( V_4 -> V_81 . V_82 ) {
if ( V_208 )
V_4 -> V_83 . V_209 ++ ;
else
V_4 -> V_83 . V_210 ++ ;
}
if ( V_208 )
goto V_204;
}
if ( V_4 -> V_46 . type == V_66 )
V_71 = (struct V_70 * ) V_65 -> V_40 ;
else {
if ( V_4 -> V_46 . type == V_161 ) {
V_190 = V_65 ;
V_194 = V_211 ;
V_196 = V_211 ;
V_71 = F_100 ( V_212 ,
V_113 ) ;
if ( ! V_71 )
goto V_204;
V_195 ++ ;
F_101 ( V_190 ) ;
F_37 ( V_4 , V_71 , V_190 , V_85 ) ;
V_71 -> V_71 . V_76 . V_93 = V_190 -> V_94 ;
memcpy ( ( ( char * ) V_71 ) + sizeof( struct V_70 ) ,
F_38 ( V_190 ) , V_211 ) ;
} else {
V_190 = F_102 ( V_65 ,
sizeof( struct V_70 ) ) ;
if ( ! V_190 )
goto V_204;
V_71 = (struct V_70 * ) F_70 ( V_190 ,
sizeof( struct V_70 ) ) ;
F_103 ( V_190 , sizeof( struct V_70 ) ) ;
F_37 ( V_4 , V_71 , V_190 , V_85 ) ;
if ( V_190 -> V_142 == V_213 )
F_35 ( V_4 , V_71 , V_190 ) ;
}
}
V_189 = F_98 ( V_4 , V_190 , V_195 ,
( V_194 > 0 ) ? V_194 : 0 ) ;
if ( ! V_189 ) {
if ( V_194 >= 0 )
F_104 ( V_212 , V_71 ) ;
goto V_204;
}
if ( V_4 -> V_46 . type != V_161 ) {
if ( F_105 ( V_190 , & V_71 ,
sizeof( struct V_214 ) ) )
goto V_204;
V_6 = F_106 ( V_4 , V_192 , V_190 , V_71 ,
V_189 ) ;
} else
V_6 = F_107 ( V_4 , V_192 , V_190 , V_71 ,
V_194 , V_196 ) ;
if ( ! V_6 ) {
V_4 -> V_156 . V_215 ++ ;
V_4 -> V_156 . V_193 += V_193 ;
if ( V_4 -> V_81 . V_82 ) {
V_197 = F_108 ( V_190 ) -> V_197 ;
if ( V_197 ) {
V_4 -> V_83 . V_216 ++ ;
V_4 -> V_83 . V_217 += V_197 + 1 ;
}
}
if ( V_190 != V_65 )
F_72 ( V_65 ) ;
V_6 = V_218 ;
} else {
if ( V_194 >= 0 )
F_104 ( V_212 , V_71 ) ;
if ( V_6 == - V_219 ) {
if ( V_190 != V_65 )
F_72 ( V_190 ) ;
return V_220 ;
} else
goto V_204;
}
F_109 ( V_2 ) ;
if ( V_4 -> V_81 . V_82 )
V_4 -> V_83 . V_221 += F_96 () -
V_4 -> V_83 . V_207 ;
return V_6 ;
V_204:
V_4 -> V_156 . V_222 ++ ;
V_4 -> V_156 . V_223 ++ ;
if ( ( V_190 != V_65 ) && V_190 )
F_72 ( V_190 ) ;
F_72 ( V_65 ) ;
F_109 ( V_2 ) ;
return V_218 ;
}
static int F_110 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_110 ;
int V_6 = 0 ;
F_11 ( V_4 , 4 , L_42 ) ;
if ( V_4 -> V_121 == V_124 )
return V_6 ;
if ( V_4 -> V_121 != V_125 )
return - V_224 ;
if ( ( V_4 -> V_46 . type != V_66 ) &&
( ! ( V_4 -> V_46 . V_47 & V_48 ) ) ) {
F_11 ( V_4 , 4 , L_43 ) ;
return - V_27 ;
}
V_4 -> V_40 . V_121 = V_122 ;
V_4 -> V_121 = V_124 ;
F_111 ( V_2 ) ;
if ( F_112 ( V_4 -> V_40 . V_225 , 0 ) >= 0 ) {
F_113 ( & V_4 -> V_150 ) ;
F_114 ( & V_4 -> V_150 ) ;
} else
V_6 = - V_31 ;
return V_6 ;
}
static int F_115 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_110 ;
F_11 ( V_4 , 5 , L_44 ) ;
if ( F_45 ( V_4 , V_112 ) ) {
F_11 ( V_4 , 3 , L_45 ) ;
return - V_167 ;
}
return F_110 ( V_2 ) ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_110 ;
F_11 ( V_4 , 4 , L_46 ) ;
F_116 ( V_2 ) ;
if ( V_4 -> V_121 == V_124 ) {
V_4 -> V_121 = V_125 ;
F_117 ( & V_4 -> V_150 ) ;
}
return 0 ;
}
static int F_118 ( struct V_226 * V_50 )
{
struct V_3 * V_4 = F_119 ( & V_50 -> V_2 ) ;
int V_6 ;
if ( V_50 -> V_2 . type == & V_227 ) {
V_6 = F_120 ( & V_50 -> V_2 ) ;
if ( V_6 )
return V_6 ;
}
F_121 ( & V_4 -> V_115 ) ;
F_122 ( V_4 -> V_186 ) ;
V_4 -> V_81 . V_228 = 1 ;
V_4 -> V_46 . V_229 = 0 ;
return 0 ;
}
static void F_123 ( struct V_226 * V_230 )
{
struct V_3 * V_4 = F_119 ( & V_230 -> V_2 ) ;
if ( V_230 -> V_2 . type == & V_227 )
F_124 ( & V_230 -> V_2 ) ;
F_54 ( V_4 , 0 , 1 ) ;
F_125 ( V_4 -> V_231 , F_88 ( V_4 , 0xffffffff ) == 0 ) ;
if ( V_230 -> V_121 == V_232 )
F_126 ( V_230 ) ;
if ( V_4 -> V_2 ) {
F_127 ( & V_4 -> V_150 ) ;
F_128 ( V_4 -> V_2 ) ;
V_4 -> V_2 = NULL ;
}
return;
}
static int F_129 ( struct V_3 * V_4 )
{
switch ( V_4 -> V_46 . type ) {
case V_161 :
V_4 -> V_2 = F_130 ( 0 , L_47 , V_233 ,
V_234 ) ;
break;
case V_66 :
V_4 -> V_2 = F_130 ( 0 , L_48 , V_233 ,
V_234 ) ;
break;
default:
V_4 -> V_2 = F_131 ( 0 ) ;
}
if ( ! V_4 -> V_2 )
return - V_224 ;
V_4 -> V_2 -> V_110 = V_4 ;
V_4 -> V_2 -> V_235 = V_236 ;
V_4 -> V_2 -> V_237 = V_4 -> V_46 . V_238 ;
V_4 -> V_2 -> V_239 = 64 ;
V_4 -> V_2 -> V_240 = V_241 ;
V_4 -> V_2 -> V_242 = & V_243 ;
if ( V_4 -> V_46 . type == V_66 ) {
V_4 -> V_2 -> V_244 = & V_245 ;
V_4 -> V_2 -> V_5 |= V_246 ;
} else {
V_4 -> V_2 -> V_244 = & V_247 ;
}
V_4 -> V_2 -> V_140 |= V_248 ;
if ( V_4 -> V_46 . type == V_249 && ! V_4 -> V_46 . V_163 ) {
V_4 -> V_2 -> V_250 = V_251 ;
V_4 -> V_2 -> V_252 = V_251 ;
if ( F_76 ( V_4 , V_253 ) ) {
V_4 -> V_2 -> V_250 |= V_254 ;
V_4 -> V_2 -> V_252 |= V_254 ;
}
if ( F_76 ( V_4 , V_255 ) ) {
V_4 -> V_2 -> V_250 |= V_141 ;
V_4 -> V_2 -> V_252 |= V_141 ;
}
}
V_4 -> V_46 . V_256 = 1 ;
F_73 ( V_4 ) ;
V_4 -> V_2 -> V_257 = ( F_132 ( V_4 ) - 1 ) *
V_258 ;
F_133 ( V_4 -> V_2 , & V_4 -> V_50 -> V_2 ) ;
F_134 ( V_4 -> V_2 , & V_4 -> V_150 , V_259 , V_260 ) ;
F_135 ( V_4 -> V_2 ) ;
return F_136 ( V_4 -> V_2 ) ;
}
static int F_137 ( struct V_3 * V_4 )
{
if ( F_138 ( V_4 , 0 ) )
return - V_224 ;
return 0 ;
}
static int F_139 ( struct V_226 * V_50 , int V_118 )
{
struct V_3 * V_4 = F_119 ( & V_50 -> V_2 ) ;
int V_6 = 0 ;
enum V_261 V_262 ;
F_140 ( & V_4 -> V_263 ) ;
F_140 ( & V_4 -> V_264 ) ;
F_52 ( V_119 , 2 , L_49 ) ;
F_53 ( V_119 , 2 , & V_4 , sizeof( void * ) ) ;
V_262 = V_4 -> V_121 ;
V_6 = F_141 ( V_4 ) ;
if ( V_6 ) {
F_74 ( V_119 , 2 , L_50 , V_6 ) ;
V_6 = - V_224 ;
goto V_265;
}
F_142 ( V_4 ) ;
if ( V_4 -> V_81 . V_172 . V_266 )
F_15 ( & V_4 -> V_50 -> V_2 ,
L_51 ) ;
F_143 ( V_4 ) ;
if ( ! V_4 -> V_2 && F_129 ( V_4 ) ) {
V_6 = - V_224 ;
goto V_265;
}
if ( V_4 -> V_46 . type != V_66 )
F_14 ( V_4 , & V_4 -> V_2 -> V_49 [ 0 ] ) ;
if ( F_144 ( V_4 , V_267 ) ) {
if ( V_4 -> V_46 . V_229 &&
F_145 ( V_4 , V_268 ) )
V_4 -> V_46 . V_229 = 0 ;
} else
V_4 -> V_46 . V_229 = 0 ;
F_146 ( V_4 ) ;
V_4 -> V_121 = V_126 ;
memset ( & V_4 -> V_134 , 0 , sizeof( struct V_269 ) ) ;
F_147 ( V_4 ) ;
F_52 ( V_119 , 2 , L_52 ) ;
if ( ( V_4 -> V_46 . type == V_249 ) ||
( V_4 -> V_46 . type == V_162 ) ) {
V_6 = F_137 ( V_4 ) ;
if ( V_6 )
goto V_265;
}
if ( V_4 -> V_46 . type != V_66 &&
V_4 -> V_46 . type != V_111 )
F_43 ( V_4 ) ;
F_116 ( V_4 -> V_2 ) ;
V_6 = F_148 ( V_4 ) ;
if ( V_6 ) {
F_74 ( V_119 , 2 , L_53 , V_6 ) ;
V_6 = - V_224 ;
goto V_265;
}
V_4 -> V_121 = V_125 ;
if ( V_4 -> V_202 )
F_149 ( V_4 -> V_2 ) ;
else
F_135 ( V_4 -> V_2 ) ;
F_54 ( V_4 , 0xffffffff , 0 ) ;
if ( V_262 == V_270 ) {
if ( V_118 &&
V_4 -> V_46 . type != V_66 ) {
F_110 ( V_4 -> V_2 ) ;
} else {
F_56 () ;
F_150 ( V_4 -> V_2 ) ;
F_58 () ;
}
F_50 ( V_4 -> V_2 ) ;
F_56 () ;
F_151 ( V_4 -> V_2 ) ;
F_58 () ;
}
F_152 ( & V_50 -> V_2 . V_271 , V_272 ) ;
F_153 ( & V_4 -> V_264 ) ;
F_153 ( & V_4 -> V_263 ) ;
return 0 ;
V_265:
F_51 ( V_4 , 0 ) ;
F_154 ( F_155 ( V_4 ) ) ;
F_154 ( F_156 ( V_4 ) ) ;
F_154 ( F_7 ( V_4 ) ) ;
F_157 ( F_155 ( V_4 ) ) ;
if ( V_262 == V_270 )
V_4 -> V_121 = V_270 ;
else
V_4 -> V_121 = V_127 ;
F_153 ( & V_4 -> V_264 ) ;
F_153 ( & V_4 -> V_263 ) ;
return V_6 ;
}
static int F_158 ( struct V_226 * V_50 )
{
return F_139 ( V_50 , 0 ) ;
}
static int F_159 ( struct V_226 * V_230 ,
int V_118 )
{
struct V_3 * V_4 = F_119 ( & V_230 -> V_2 ) ;
int V_6 = 0 , V_273 = 0 , V_274 = 0 ;
enum V_261 V_262 ;
F_140 ( & V_4 -> V_263 ) ;
F_140 ( & V_4 -> V_264 ) ;
F_52 ( V_119 , 3 , L_54 ) ;
F_53 ( V_119 , 3 , & V_4 , sizeof( void * ) ) ;
if ( V_4 -> V_2 && F_160 ( V_4 -> V_2 ) )
F_135 ( V_4 -> V_2 ) ;
V_262 = V_4 -> V_121 ;
if ( ( ! V_118 && V_4 -> V_46 . V_229 ) || V_4 -> V_46 . V_229 == 2 ) {
F_145 ( V_4 , V_275 ) ;
V_4 -> V_46 . V_229 = 1 ;
}
F_51 ( V_4 , V_118 ) ;
V_6 = F_154 ( F_155 ( V_4 ) ) ;
V_273 = F_154 ( F_156 ( V_4 ) ) ;
V_274 = F_154 ( F_7 ( V_4 ) ) ;
if ( ! V_6 )
V_6 = ( V_273 ) ? V_273 : V_274 ;
if ( V_6 )
F_74 ( V_119 , 2 , L_55 , V_6 ) ;
F_157 ( F_155 ( V_4 ) ) ;
if ( V_262 == V_124 )
V_4 -> V_121 = V_270 ;
F_152 ( & V_230 -> V_2 . V_271 , V_272 ) ;
F_153 ( & V_4 -> V_264 ) ;
F_153 ( & V_4 -> V_263 ) ;
return 0 ;
}
static int F_126 ( struct V_226 * V_230 )
{
return F_159 ( V_230 , 0 ) ;
}
static int F_161 ( void * V_276 )
{
struct V_3 * V_4 ;
int V_6 = 0 ;
V_4 = (struct V_3 * ) V_276 ;
F_11 ( V_4 , 2 , L_56 ) ;
if ( ! F_162 ( V_4 , V_112 ) )
return 0 ;
F_11 ( V_4 , 2 , L_57 ) ;
F_16 ( & V_4 -> V_50 -> V_2 ,
L_58 ) ;
F_163 ( V_4 ) ;
F_159 ( V_4 -> V_50 , 1 ) ;
V_6 = F_139 ( V_4 -> V_50 , 1 ) ;
if ( ! V_6 )
F_15 ( & V_4 -> V_50 -> V_2 ,
L_59 ) ;
else {
F_164 ( V_4 ) ;
F_16 ( & V_4 -> V_50 -> V_2 , L_60
L_61 ) ;
}
F_165 ( V_4 ) ;
F_166 ( V_4 , V_112 ) ;
F_167 ( V_4 , V_112 ) ;
return 0 ;
}
static int T_8 F_168 ( void )
{
F_169 ( L_62 ) ;
return 0 ;
}
static void T_9 F_170 ( void )
{
F_169 ( L_63 ) ;
}
static int F_171 ( struct V_226 * V_50 )
{
struct V_3 * V_4 = F_119 ( & V_50 -> V_2 ) ;
if ( V_4 -> V_2 )
F_172 ( V_4 -> V_2 ) ;
F_54 ( V_4 , 0 , 1 ) ;
F_125 ( V_4 -> V_231 , F_88 ( V_4 , 0xffffffff ) == 0 ) ;
if ( V_50 -> V_121 == V_277 )
return 0 ;
if ( V_4 -> V_121 == V_124 ) {
if ( V_4 -> V_46 . V_229 )
F_145 ( V_4 , V_275 ) ;
F_159 ( V_4 -> V_50 , 1 ) ;
} else
F_159 ( V_4 -> V_50 , 0 ) ;
return 0 ;
}
static int F_173 ( struct V_226 * V_50 )
{
struct V_3 * V_4 = F_119 ( & V_50 -> V_2 ) ;
int V_6 = 0 ;
if ( V_50 -> V_121 == V_277 )
goto V_278;
if ( V_4 -> V_121 == V_270 ) {
V_6 = F_139 ( V_4 -> V_50 , 1 ) ;
if ( V_6 ) {
F_56 () ;
F_57 ( V_4 -> V_2 ) ;
F_58 () ;
}
} else
V_6 = F_139 ( V_4 -> V_50 , 0 ) ;
V_278:
F_54 ( V_4 , 0xffffffff , 0 ) ;
if ( V_4 -> V_2 )
F_174 ( V_4 -> V_2 ) ;
if ( V_6 )
F_16 ( & V_4 -> V_50 -> V_2 , L_60
L_61 ) ;
return V_6 ;
}
static int F_175 ( struct V_3 * V_4 ,
struct V_35 * V_36 )
{
switch ( V_36 -> V_71 . V_104 ) {
case V_279 :
case V_280 :
if ( V_36 -> V_40 . V_172 . V_71 . V_281 ==
V_282 ) {
F_176 ( V_4 , V_36 ) ;
return 0 ;
} else
return 1 ;
case V_283 :
F_177 ( V_4 , V_36 ) ;
return 0 ;
default:
return 1 ;
}
}
static int F_178 ( struct V_3 * V_4 , int V_94 ,
struct V_37 * V_38 )
{
unsigned long V_5 ;
int V_6 = 0 ;
F_11 ( V_4 , 5 , L_64 ) ;
F_125 ( V_4 -> V_231 ,
F_179 ( & V_4 -> V_123 . V_284 , 0 , 1 ) == 0 ) ;
F_180 ( V_4 , V_94 , V_38 ) ;
F_11 ( V_4 , 6 , L_65 ) ;
F_181 ( F_182 ( V_4 -> V_123 . V_225 ) , V_5 ) ;
V_6 = F_183 ( V_4 -> V_123 . V_225 , & V_4 -> V_123 . V_285 ,
( V_286 ) V_38 , 0 , 0 ) ;
F_184 ( F_182 ( V_4 -> V_123 . V_225 ) , V_5 ) ;
if ( V_6 ) {
F_19 ( 2 , L_66
L_67 , V_6 ) ;
F_9 ( V_4 , 2 , L_68 , V_6 ) ;
F_185 ( V_38 -> V_287 , V_38 ) ;
F_186 ( & V_4 -> V_123 . V_284 , 0 ) ;
F_187 ( & V_4 -> V_231 ) ;
}
return V_6 ;
}
static int F_188 ( struct V_3 * V_4 ,
struct V_37 * V_38 , int V_288 )
{
T_6 V_289 , V_290 ;
F_11 ( V_4 , 4 , L_69 ) ;
F_189 ( V_4 , V_38 , V_291 ) ;
V_289 = ( T_6 ) ( V_41 + V_288 ) ;
V_290 = ( T_6 ) V_288 ;
memcpy ( F_190 ( V_38 -> V_40 ) , & V_289 , 2 ) ;
memcpy ( F_191 ( V_38 -> V_40 ) , & V_290 , 2 ) ;
memcpy ( F_192 ( V_38 -> V_40 ) , & V_290 , 2 ) ;
memcpy ( F_193 ( V_38 -> V_40 ) , & V_290 , 2 ) ;
return F_178 ( V_4 , V_289 , V_38 ) ;
}
int F_194 ( struct V_1 * V_2 , void * V_40 , int V_288 )
{
struct V_37 * V_38 ;
struct V_3 * V_4 ;
int V_6 ;
if ( ! V_2 )
return - V_224 ;
V_4 = V_2 -> V_110 ;
if ( ! V_4 )
return - V_224 ;
F_11 ( V_4 , 2 , L_70 ) ;
if ( ! F_195 ( V_4 ) )
return - V_224 ;
V_38 = F_196 ( & V_4 -> V_123 ) ;
memcpy ( V_38 -> V_40 + V_41 , V_40 , V_288 ) ;
V_6 = F_188 ( V_4 , V_38 , V_288 ) ;
return V_6 ;
}
int F_197 ( unsigned char * V_10 , struct V_1 * * V_2 ,
int (* F_198)( struct V_1 * , void * ) ,
int (* V_153)( struct V_64 * ) )
{
struct V_3 * V_4 ;
* V_2 = F_5 ( V_10 ) ;
if ( * V_2 == NULL )
return - V_224 ;
V_4 = ( * V_2 ) -> V_110 ;
if ( ! V_4 )
return - V_224 ;
F_11 ( V_4 , 2 , L_71 ) ;
if ( ( F_198 == NULL ) || ( V_153 == NULL ) )
return - V_168 ;
V_4 -> V_152 . F_198 = F_198 ;
V_4 -> V_152 . V_153 = V_153 ;
return 0 ;
}
void F_199 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( ! V_2 )
return;
V_4 = V_2 -> V_110 ;
if ( ! V_4 )
return;
F_11 ( V_4 , 2 , L_72 ) ;
V_4 -> V_152 . F_198 = NULL ;
V_4 -> V_152 . V_153 = NULL ;
return;
}
static void F_200 ( struct V_3 * V_4 ,
enum V_292 V_293 ,
T_4 V_294 , struct V_295 * V_296 , struct V_297 * V_298 )
{
char V_299 [ 7 ] [ 32 ] ;
char * V_300 [ 8 ] ;
int V_60 = 0 ;
switch ( V_293 ) {
case V_301 :
snprintf ( V_299 [ V_60 ] , sizeof( V_299 [ V_60 ] ) , L_73 ,
( V_294 & V_302 )
? L_74 : L_75 ) ;
V_300 [ V_60 ] = V_299 [ V_60 ] ; V_60 ++ ;
if ( V_294 & V_303 ) {
snprintf ( V_299 [ V_60 ] , sizeof( V_299 [ V_60 ] ) , L_76 ,
V_298 -> V_304 ) ;
V_300 [ V_60 ] = V_299 [ V_60 ] ; V_60 ++ ;
}
if ( V_294 & V_305 ) {
snprintf ( V_299 [ V_60 ] , sizeof( V_299 [ V_60 ] ) , L_77 ,
V_298 -> V_32 ) ;
V_300 [ V_60 ] = V_299 [ V_60 ] ; V_60 ++ ;
}
snprintf ( V_299 [ V_60 ] , sizeof( V_299 [ V_60 ] ) , L_78 ,
V_296 -> V_306 , V_296 -> V_307 , V_296 -> V_308 ) ;
V_300 [ V_60 ] = V_299 [ V_60 ] ; V_60 ++ ;
snprintf ( V_299 [ V_60 ] , sizeof( V_299 [ V_60 ] ) , L_79 , V_296 -> V_309 ) ;
V_300 [ V_60 ] = V_299 [ V_60 ] ; V_60 ++ ;
snprintf ( V_299 [ V_60 ] , sizeof( V_299 [ V_60 ] ) , L_80 ,
V_296 -> V_310 ) ;
V_300 [ V_60 ] = V_299 [ V_60 ] ; V_60 ++ ;
snprintf ( V_299 [ V_60 ] , sizeof( V_299 [ V_60 ] ) , L_81 , V_296 -> V_311 ) ;
V_300 [ V_60 ] = V_299 [ V_60 ] ; V_60 ++ ;
break;
case V_312 :
snprintf ( V_299 [ V_60 ] , sizeof( V_299 [ V_60 ] ) , L_82 ) ;
V_300 [ V_60 ] = V_299 [ V_60 ] ; V_60 ++ ;
break;
case V_313 :
snprintf ( V_299 [ V_60 ] , sizeof( V_299 [ V_60 ] ) , L_83 ) ;
V_300 [ V_60 ] = V_299 [ V_60 ] ; V_60 ++ ;
break;
}
V_300 [ V_60 ] = NULL ;
F_201 ( & V_4 -> V_50 -> V_2 . V_271 , V_272 , V_300 ) ;
}
static void F_202 ( struct V_314 * V_315 )
{
struct V_316 * V_40 =
F_203 ( V_315 , struct V_316 , V_317 ) ;
struct V_318 * V_319 = & V_40 -> V_320 . V_319 [ 0 ] ;
char V_321 [ 32 ] ;
char V_322 [ 32 ] ;
char V_323 [ 32 ] ;
char * V_300 [] = {
V_321 ,
V_322 ,
V_323 ,
NULL
} ;
F_140 ( & V_40 -> V_4 -> V_264 ) ;
V_40 -> V_4 -> V_81 . V_172 . V_171 = V_319 -> V_171 ;
F_153 ( & V_40 -> V_4 -> V_264 ) ;
snprintf ( V_321 , sizeof( V_321 ) , L_84 ) ;
snprintf ( V_322 , sizeof( V_322 ) , L_85 ,
( V_319 -> V_171 == V_180 ) ? L_86 :
( V_319 -> V_171 == V_178 ) ? L_87 :
( V_319 -> V_171 == V_179 ) ? L_88 :
L_89 ) ;
snprintf ( V_323 , sizeof( V_323 ) , L_90 ,
( V_319 -> V_121 == V_324 ) ? L_91 :
( V_319 -> V_121 == V_325 ) ? L_92 :
( V_319 -> V_121 == V_326 ) ? L_93 :
L_89 ) ;
F_201 ( & V_40 -> V_4 -> V_50 -> V_2 . V_271 ,
V_272 , V_300 ) ;
F_28 ( V_40 ) ;
}
static void F_176 ( struct V_3 * V_4 ,
struct V_35 * V_36 )
{
struct V_327 * V_320 =
& V_36 -> V_40 . V_172 . V_40 . V_328 ;
struct V_316 * V_40 ;
int V_329 ;
F_11 ( V_4 , 2 , L_94 ) ;
if ( V_320 -> V_330 != sizeof( struct V_318 ) ) {
F_9 ( V_4 , 2 , L_95 , V_320 -> V_330 ) ;
return;
}
V_329 = sizeof( struct V_318 ) * V_320 -> V_331 ;
V_40 = F_86 ( sizeof( struct V_316 ) + V_329 ,
V_113 ) ;
if ( ! V_40 ) {
F_11 ( V_4 , 2 , L_96 ) ;
return;
}
F_204 ( & V_40 -> V_317 , F_202 ) ;
V_40 -> V_4 = V_4 ;
memcpy ( & V_40 -> V_320 , V_320 ,
sizeof( struct V_327 ) + V_329 ) ;
F_205 ( V_332 , & V_40 -> V_317 ) ;
}
static void F_206 ( struct V_314 * V_315 )
{
struct V_333 * V_40 =
F_203 ( V_315 , struct V_333 , V_317 ) ;
int V_60 ;
if ( V_40 -> V_334 . V_335 ) {
F_15 ( & V_40 -> V_4 -> V_50 -> V_2 ,
L_97 ,
V_40 -> V_4 -> V_2 -> V_51 ,
( V_40 -> V_334 . V_335 == 0x01 )
? L_98
: ( V_40 -> V_334 . V_335 == 0x02 )
? L_99
: L_100 ) ;
F_140 ( & V_40 -> V_4 -> V_264 ) ;
V_40 -> V_4 -> V_81 . V_172 . V_336 = 0 ;
F_153 ( & V_40 -> V_4 -> V_264 ) ;
F_200 ( V_40 -> V_4 , V_312 ,
0 , NULL , NULL ) ;
} else
for ( V_60 = 0 ; V_60 < V_40 -> V_334 . V_331 ; V_60 ++ ) {
struct V_337 * V_319 =
& V_40 -> V_334 . V_319 [ V_60 ] ;
F_200 ( V_40 -> V_4 ,
V_301 ,
V_319 -> V_338 ,
& V_319 -> V_296 , & V_319 -> V_298 ) ;
}
F_28 ( V_40 ) ;
}
static void F_177 ( struct V_3 * V_4 ,
struct V_35 * V_36 )
{
struct V_339 * V_334 =
& V_36 -> V_40 . V_340 ;
struct V_333 * V_40 ;
int V_329 ;
F_11 ( V_4 , 2 , L_101 ) ;
if ( V_36 -> V_71 . V_102 != 0x0000 ) {
if ( V_36 -> V_71 . V_102 == 0x0010 ) {
if ( V_334 -> V_335 == 0x00 )
V_334 -> V_335 = 0xff ;
} else {
F_9 ( V_4 , 2 , L_102 ,
V_36 -> V_71 . V_102 ) ;
return;
}
}
V_329 = sizeof( struct V_337 ) *
V_334 -> V_331 ;
V_40 = F_86 ( sizeof( struct V_333 ) + V_329 ,
V_113 ) ;
if ( ! V_40 ) {
F_11 ( V_4 , 2 , L_103 ) ;
return;
}
F_204 ( & V_40 -> V_317 , F_206 ) ;
V_40 -> V_4 = V_4 ;
memcpy ( & V_40 -> V_334 , V_334 ,
sizeof( struct V_339 ) + V_329 ) ;
F_205 ( V_332 , & V_40 -> V_317 ) ;
}
static int F_207 ( struct V_3 * V_4 ,
struct V_341 * V_342 , enum V_343 V_344 )
{
int V_6 ;
int V_345 = ( V_4 -> V_46 . type == V_161 ) ;
if ( ( V_345 && ( V_342 -> V_346 == V_17 ) ) ||
( ! V_345 && ( V_342 -> V_346 == V_342 -> V_347 ) ) )
switch ( V_342 -> V_347 ) {
case 0x0000 :
V_6 = 0 ;
break;
case 0x2B04 :
case 0x0004 :
V_6 = - V_19 ;
break;
case 0x2B0C :
case 0x000C :
V_6 = - V_224 ;
F_208 ( & V_4 -> V_50 -> V_2 ,
L_104 ) ;
break;
case 0x2B10 :
case 0x0010 :
V_6 = - V_27 ;
F_208 ( & V_4 -> V_50 -> V_2 ,
L_105 ) ;
break;
case 0x2B14 :
case 0x0014 :
switch ( V_344 ) {
case V_348 :
V_6 = - V_24 ;
F_208 ( & V_4 -> V_50 -> V_2 ,
L_106 ) ;
break;
case V_349 :
V_6 = - V_219 ;
F_208 ( & V_4 -> V_50 -> V_2 ,
L_107 ) ;
break;
default:
V_6 = - V_31 ;
}
break;
case 0x2B18 :
case 0x0018 :
V_6 = - V_219 ;
F_208 ( & V_4 -> V_50 -> V_2 ,
L_108 ) ;
break;
case 0x2B1C :
case 0x001C :
V_6 = - V_24 ;
F_208 ( & V_4 -> V_50 -> V_2 ,
L_109 ) ;
break;
case 0x2B24 :
case 0x0024 :
V_6 = - V_219 ;
F_208 ( & V_4 -> V_50 -> V_2 ,
L_107 ) ;
break;
case 0x2B20 :
case 0x0020 :
V_6 = - V_350 ;
F_208 ( & V_4 -> V_50 -> V_2 ,
L_110 ) ;
break;
default:
V_6 = - V_31 ;
}
else
switch ( V_342 -> V_346 ) {
case V_351 :
V_6 = - V_19 ;
break;
case V_352 :
V_6 = - V_19 ;
break;
default:
V_6 = - V_31 ;
}
if ( V_6 ) {
F_9 ( V_4 , 2 , L_111 , V_342 -> V_346 ) ;
F_9 ( V_4 , 2 , L_112 , V_342 -> V_347 ) ;
}
return V_6 ;
}
static inline int F_209 ( struct V_3 * V_4 )
{
return ( V_4 -> V_46 . type == V_161 ) ?
V_280 :
V_279 ;
}
static int F_210 ( struct V_3 * V_4 ,
struct V_100 * V_101 , unsigned long V_40 )
{
struct V_35 * V_36 = (struct V_35 * ) V_40 ;
struct V_341 * V_342 = (struct V_341 * ) V_101 -> V_353 ;
F_11 ( V_4 , 2 , L_113 ) ;
V_342 -> V_346 = V_36 -> V_71 . V_102 ;
V_342 -> V_347 = V_36 -> V_40 . V_172 . V_71 . V_102 ;
if ( ( V_342 -> V_346 == 0 ) && ( V_342 -> V_347 == 0 ) ) {
V_342 -> V_40 . V_354 =
V_36 -> V_40 . V_172 . V_40 . V_355 . V_356 ;
} else {
V_342 -> V_40 . V_354 = 0 ;
}
return 0 ;
}
static void F_142 ( struct V_3 * V_4 )
{
struct V_37 * V_38 ;
struct V_35 * V_36 ;
struct V_341 V_342 ;
F_11 ( V_4 , 2 , L_114 ) ;
V_38 = F_12 ( V_4 , F_209 ( V_4 ) , 0 ) ;
if ( ! V_38 )
return;
V_36 = (struct V_35 * ) ( V_38 -> V_40 + V_41 ) ;
V_36 -> V_40 . V_172 . V_71 . V_357 =
sizeof( struct V_358 ) +
sizeof( struct V_359 ) ;
V_36 -> V_40 . V_172 . V_71 . V_281 =
V_360 ;
V_36 -> V_40 . V_172 . V_71 . V_361 = 1 ;
V_36 -> V_40 . V_172 . V_71 . V_362 = 1 ;
if ( F_13 ( V_4 , V_38 , F_210 ,
( void * ) & V_342 ) ||
F_207 ( V_4 , & V_342 ,
V_360 ) ) {
V_4 -> V_81 . V_172 . V_171 = V_180 ;
return;
}
V_4 -> V_81 . V_172 . V_266 = V_342 . V_40 . V_354 ;
}
static int F_211 ( struct V_3 * V_4 ,
struct V_100 * V_101 , unsigned long V_40 )
{
struct V_35 * V_36 = (struct V_35 * ) V_40 ;
struct V_363 * V_320 = & V_36 -> V_40 . V_172 . V_40 . V_364 ;
struct V_341 * V_342 = (struct V_341 * ) V_101 -> V_353 ;
F_11 ( V_4 , 2 , L_115 ) ;
V_342 -> V_346 = V_36 -> V_71 . V_102 ;
V_342 -> V_347 = V_36 -> V_40 . V_172 . V_71 . V_102 ;
if ( ( V_342 -> V_346 != 0 ) || ( V_342 -> V_347 != 0 ) )
return 0 ;
if ( V_320 -> V_330 != sizeof( struct V_318 ) ) {
V_342 -> V_347 = 0xffff ;
F_9 ( V_4 , 2 , L_116 , V_320 -> V_330 ) ;
return 0 ;
}
if ( V_320 -> V_331 > 0 ) {
if ( V_342 -> V_40 . V_320 . V_171 )
* V_342 -> V_40 . V_320 . V_171 = V_320 -> V_319 [ 0 ] . V_171 ;
if ( V_342 -> V_40 . V_320 . V_121 )
* V_342 -> V_40 . V_320 . V_121 = V_320 -> V_319 [ 0 ] . V_121 ;
}
return 0 ;
}
int F_212 ( struct V_3 * V_4 ,
enum V_365 * V_171 , enum V_366 * V_121 )
{
int V_6 = 0 ;
struct V_37 * V_38 ;
struct V_35 * V_36 ;
struct V_341 V_342 = {
. V_40 = {
. V_320 = {
. V_171 = V_171 ,
. V_121 = V_121 ,
} ,
} ,
} ;
F_11 ( V_4 , 2 , L_117 ) ;
if ( ! ( V_4 -> V_81 . V_172 . V_266 & V_367 ) )
return - V_19 ;
V_38 = F_12 ( V_4 , F_209 ( V_4 ) , 0 ) ;
if ( ! V_38 )
return - V_30 ;
V_36 = (struct V_35 * ) ( V_38 -> V_40 + V_41 ) ;
V_36 -> V_40 . V_172 . V_71 . V_357 =
sizeof( struct V_358 ) ;
V_36 -> V_40 . V_172 . V_71 . V_281 =
V_367 ;
V_36 -> V_40 . V_172 . V_71 . V_361 = 1 ;
V_36 -> V_40 . V_172 . V_71 . V_362 = 1 ;
V_6 = F_13 ( V_4 , V_38 , F_211 ,
( void * ) & V_342 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_207 ( V_4 , & V_342 , V_367 ) ;
}
static int F_213 ( struct V_3 * V_4 ,
struct V_100 * V_101 , unsigned long V_40 )
{
struct V_35 * V_36 = (struct V_35 * ) V_40 ;
struct V_341 * V_342 = (struct V_341 * ) V_101 -> V_353 ;
F_11 ( V_4 , 2 , L_118 ) ;
V_342 -> V_346 = V_36 -> V_71 . V_102 ;
V_342 -> V_347 = V_36 -> V_40 . V_172 . V_71 . V_102 ;
return 0 ;
}
int F_83 ( struct V_3 * V_4 , enum V_365 V_171 )
{
int V_6 = 0 ;
int V_357 ;
struct V_37 * V_38 ;
struct V_35 * V_36 ;
struct V_341 V_342 ;
enum V_343 V_344 ;
F_11 ( V_4 , 2 , L_119 ) ;
switch ( V_171 ) {
case V_180 :
V_344 = V_368 ;
V_357 = sizeof( struct V_358 ) +
sizeof( struct V_369 ) ;
break;
case V_178 :
V_344 = V_348 ;
V_357 = sizeof( struct V_358 ) +
sizeof( struct V_370 ) ;
break;
case V_179 :
V_344 = V_349 ;
V_357 = sizeof( struct V_358 ) +
sizeof( struct V_371 ) ;
break;
default:
return - V_168 ;
}
if ( ! ( V_4 -> V_81 . V_172 . V_266 & V_344 ) )
return - V_19 ;
V_38 = F_12 ( V_4 , F_209 ( V_4 ) , 0 ) ;
if ( ! V_38 )
return - V_30 ;
V_36 = (struct V_35 * ) ( V_38 -> V_40 + V_41 ) ;
V_36 -> V_40 . V_172 . V_71 . V_357 = V_357 ;
V_36 -> V_40 . V_172 . V_71 . V_281 = V_344 ;
V_36 -> V_40 . V_172 . V_71 . V_361 = 1 ;
V_36 -> V_40 . V_172 . V_71 . V_362 = 1 ;
V_6 = F_13 ( V_4 , V_38 , F_213 ,
( void * ) & V_342 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_207 ( V_4 , & V_342 , V_344 ) ;
}
static int F_214 ( struct V_3 * V_4 , int V_372 , T_6 V_373 )
{
int V_6 ;
if ( V_372 == 0 )
switch ( V_373 ) {
case 0x0001 :
V_6 = 0 ;
break;
case 0x0004 :
case 0x0100 :
case 0x0106 :
V_6 = - V_19 ;
F_208 ( & V_4 -> V_50 -> V_2 ,
L_120 ) ;
break;
case 0x0107 :
V_6 = - V_374 ;
break;
default:
V_6 = - V_31 ;
}
else
V_6 = - V_31 ;
if ( V_6 ) {
F_9 ( V_4 , 2 , L_121 , V_372 ) ;
F_9 ( V_4 , 2 , L_122 , V_373 ) ;
}
return V_6 ;
}
static void F_215 ( void * V_375 ,
enum V_376 type , void * V_319 )
{
struct V_3 * V_4 = (struct V_3 * ) V_375 ;
struct V_377 * V_378 ;
T_4 V_294 ;
if ( type != V_379 ) {
F_65 ( 1 ) ;
return;
}
V_378 = (struct V_377 * ) V_319 ;
V_294 = V_305 ;
if ( V_378 -> V_298 . V_304 )
V_294 |= V_303 ;
F_200 ( V_4 , V_301 , V_294 ,
(struct V_295 * ) & V_378 -> V_380 ,
(struct V_297 * ) & V_378 -> V_298 ) ;
}
int F_216 ( struct V_3 * V_4 , int V_381 )
{
int V_6 ;
T_6 V_373 ;
struct V_382 * V_383 ;
struct V_384 V_385 ;
if ( ! V_4 )
return - V_168 ;
if ( ! V_4 -> V_81 . V_172 . V_266 )
return - V_19 ;
V_383 = F_155 ( V_4 ) ;
F_217 ( V_383 , & V_385 ) ;
if ( V_381 ) {
F_200 ( V_4 , V_313 , 0 , NULL , NULL ) ;
V_6 = F_218 ( V_385 , 1 , & V_373 ,
F_215 , V_4 ) ;
} else
V_6 = F_218 ( V_385 , 0 , & V_373 , NULL , NULL ) ;
return F_214 ( V_4 , V_6 , V_373 ) ;
}
