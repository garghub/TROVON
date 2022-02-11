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
if ( V_160 ) {
V_6 = F_76 ( V_4 ) ;
if ( ! V_6 )
goto V_161;
F_19 ( 2 , L_30 ,
F_75 ( V_4 ) , V_6 ) ;
F_74 ( V_119 , 2 , L_1 , V_6 ) ;
}
if ( F_77 ( V_4 , V_162 ) ) {
V_6 = F_78 ( V_4 ) ;
if ( V_6 ) {
F_19 ( 2 , L_31
L_32 ,
F_75 ( V_4 ) , V_6 ) ;
}
}
if ( V_4 -> V_46 . type == V_163 ||
V_4 -> V_46 . type == V_111 ||
V_4 -> V_46 . type == V_164 ||
V_4 -> V_46 . V_165 ) {
V_6 = F_79 ( V_4 ) ;
if ( V_6 ) {
F_19 ( 2 , L_33
L_34 , F_75 ( V_4 ) , V_6 ) ;
F_74 ( V_119 , 2 , L_35 , V_6 ) ;
return V_6 ;
}
} else {
F_80 ( V_4 -> V_2 -> V_49 ) ;
memcpy ( V_4 -> V_2 -> V_49 , V_159 , 3 ) ;
}
V_161:
F_53 ( V_119 , 2 , V_4 -> V_2 -> V_49 , V_4 -> V_2 -> V_166 ) ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 , void * V_167 )
{
struct V_168 * V_63 = V_167 ;
struct V_3 * V_4 = V_2 -> V_110 ;
int V_6 = 0 ;
F_11 ( V_4 , 3 , L_36 ) ;
if ( F_1 ( V_2 ) != V_9 ) {
F_11 ( V_4 , 3 , L_37 ) ;
return - V_19 ;
}
if ( V_4 -> V_46 . type == V_66 ||
V_4 -> V_46 . type == V_111 ||
V_4 -> V_46 . type == V_164 ) {
F_11 ( V_4 , 3 , L_38 ) ;
return - V_19 ;
}
F_82 ( V_4 , 3 , V_63 -> V_169 , V_44 ) ;
if ( F_45 ( V_4 , V_112 ) ) {
F_11 ( V_4 , 3 , L_39 ) ;
return - V_170 ;
}
V_6 = F_17 ( V_4 , & V_4 -> V_2 -> V_49 [ 0 ] ) ;
if ( ! V_6 || ( V_6 == - V_29 ) )
V_6 = F_14 ( V_4 , V_63 -> V_169 ) ;
return V_6 ? - V_171 : 0 ;
}
static void F_83 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
enum V_172 V_173 ;
int V_174 ;
int V_6 ;
F_11 ( V_4 , 3 , L_40 ) ;
if ( ! V_4 -> V_81 . V_175 . V_176 )
return;
V_173 = ( V_2 -> V_5 & V_177 ) ? V_178
: V_179 ;
if ( V_173 == V_4 -> V_46 . V_173 )
return;
if ( V_173 == V_178 ) {
if ( V_4 -> V_81 . V_175 . V_180 )
V_174 = V_181 ;
else
V_174 = V_182 ;
} else
V_174 = V_183 ;
V_6 = F_84 ( V_4 , V_174 ) ;
F_74 ( V_119 , 2 , L_41 ,
( V_173 == V_178 ) ? '+' : '-' , V_6 ) ;
if ( ! V_6 ) {
V_4 -> V_81 . V_175 . V_174 = V_174 ;
V_4 -> V_46 . V_173 = V_173 ;
}
}
static void
F_85 ( struct V_3 * V_4 , struct V_184 * V_185 , T_4 V_56 )
{
struct V_55 * V_32 ;
F_86 (card->mac_htable, mac, hnode,
qeth_l2_mac_hash(ha->addr)) {
if ( V_56 == V_32 -> V_56 &&
! memcmp ( V_185 -> V_63 , V_32 -> V_57 , V_44 ) ) {
V_32 -> V_186 = V_187 ;
return;
}
}
V_32 = F_87 ( sizeof( struct V_55 ) , V_113 ) ;
if ( ! V_32 )
return;
memcpy ( V_32 -> V_57 , V_185 -> V_63 , V_44 ) ;
V_32 -> V_56 = V_56 ;
V_32 -> V_186 = V_188 ;
F_88 ( V_4 -> V_189 , & V_32 -> V_62 ,
F_30 ( V_32 -> V_57 ) ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_110 ;
struct V_184 * V_185 ;
struct V_55 * V_32 ;
struct V_58 * V_59 ;
int V_60 ;
int V_6 ;
if ( V_4 -> V_46 . type == V_66 )
return;
F_11 ( V_4 , 3 , L_42 ) ;
if ( F_89 ( V_4 , V_112 ) &&
( V_4 -> V_121 != V_124 ) )
return;
F_25 ( & V_4 -> V_61 ) ;
F_90 (ha, dev)
F_85 ( V_4 , V_185 , 0 ) ;
F_91 (ha, dev)
F_85 ( V_4 , V_185 , 1 ) ;
F_26 (card->mac_htable, i, tmp, mac, hnode) {
if ( V_32 -> V_186 == V_190 ) {
F_23 ( V_4 , V_32 ) ;
F_27 ( & V_32 -> V_62 ) ;
F_28 ( V_32 ) ;
} else if ( V_32 -> V_186 == V_188 ) {
V_6 = F_22 ( V_4 , V_32 ) ;
if ( V_6 ) {
F_27 ( & V_32 -> V_62 ) ;
F_28 ( V_32 ) ;
} else
V_32 -> V_186 = V_190 ;
} else
V_32 -> V_186 = V_190 ;
}
F_29 ( & V_4 -> V_61 ) ;
if ( F_92 ( V_4 , V_191 ) )
F_93 ( V_4 ) ;
else
F_83 ( V_4 ) ;
}
static T_7 F_94 ( struct V_64 * V_65 ,
struct V_1 * V_2 )
{
int V_6 ;
struct V_70 * V_71 = NULL ;
int V_192 = 0 ;
struct V_3 * V_4 = V_2 -> V_110 ;
struct V_64 * V_193 = V_65 ;
int V_85 = F_32 ( V_4 , V_65 ) ;
struct V_194 * V_195 ;
int V_196 = V_65 -> V_94 ;
int V_197 = - 1 ;
int V_198 = 0 ;
int V_199 = 0 ;
int V_200 ;
if ( V_4 -> V_131 . V_201 || ( V_85 &&
V_4 -> V_46 . V_202 ) )
V_195 = V_4 -> V_131 . V_203 [ F_95 ( V_4 , V_65 ,
F_96 ( V_65 ) , V_85 ) ] ;
else
V_195 = V_4 -> V_131 . V_203 [ V_4 -> V_131 . V_204 ] ;
if ( ( V_4 -> V_121 != V_124 ) || ! V_4 -> V_205 ) {
V_4 -> V_156 . V_206 ++ ;
goto V_207;
}
if ( ( V_4 -> V_46 . type == V_66 ) &&
( V_65 -> V_74 == F_68 ( V_208 ) ) )
goto V_207;
if ( V_4 -> V_81 . V_82 ) {
V_4 -> V_83 . V_209 ++ ;
V_4 -> V_83 . V_210 = F_97 () ;
}
F_98 ( V_2 ) ;
if ( ( V_4 -> V_46 . type != V_163 ) &&
! F_99 ( V_4 , V_193 , 0 , 0 ) ) {
int V_211 = F_100 ( V_193 ) ;
if ( V_4 -> V_81 . V_82 ) {
if ( V_211 )
V_4 -> V_83 . V_212 ++ ;
else
V_4 -> V_83 . V_213 ++ ;
}
if ( V_211 )
goto V_207;
}
if ( V_4 -> V_46 . type == V_66 )
V_71 = (struct V_70 * ) V_65 -> V_40 ;
else {
if ( V_4 -> V_46 . type == V_163 ) {
V_193 = V_65 ;
V_197 = V_214 ;
V_199 = V_214 ;
V_71 = F_101 ( V_215 ,
V_113 ) ;
if ( ! V_71 )
goto V_207;
V_198 ++ ;
F_102 ( V_193 ) ;
F_37 ( V_4 , V_71 , V_193 , V_85 ) ;
V_71 -> V_71 . V_76 . V_93 = V_193 -> V_94 ;
memcpy ( ( ( char * ) V_71 ) + sizeof( struct V_70 ) ,
F_38 ( V_193 ) , V_214 ) ;
} else {
V_193 = F_103 ( V_65 ,
sizeof( struct V_70 ) ) ;
if ( ! V_193 )
goto V_207;
V_71 = F_70 ( V_193 , sizeof( struct V_70 ) ) ;
F_104 ( V_193 , sizeof( struct V_70 ) ) ;
F_37 ( V_4 , V_71 , V_193 , V_85 ) ;
if ( V_193 -> V_142 == V_216 )
F_35 ( V_4 , V_71 , V_193 ) ;
}
}
V_192 = F_99 ( V_4 , V_193 , V_198 ,
( V_197 > 0 ) ? V_197 : 0 ) ;
if ( ! V_192 ) {
if ( V_197 >= 0 )
F_105 ( V_215 , V_71 ) ;
goto V_207;
}
if ( V_4 -> V_46 . type != V_163 ) {
if ( F_106 ( V_193 , & V_71 ,
sizeof( struct V_217 ) ) )
goto V_207;
V_6 = F_107 ( V_4 , V_195 , V_193 , V_71 ,
V_192 ) ;
} else
V_6 = F_108 ( V_4 , V_195 , V_193 , V_71 ,
V_197 , V_199 ) ;
if ( ! V_6 ) {
V_4 -> V_156 . V_218 ++ ;
V_4 -> V_156 . V_196 += V_196 ;
if ( V_4 -> V_81 . V_82 ) {
V_200 = F_109 ( V_193 ) -> V_200 ;
if ( V_200 ) {
V_4 -> V_83 . V_219 ++ ;
V_4 -> V_83 . V_220 += V_200 + 1 ;
}
}
if ( V_193 != V_65 )
F_72 ( V_65 ) ;
V_6 = V_221 ;
} else {
if ( V_197 >= 0 )
F_105 ( V_215 , V_71 ) ;
if ( V_6 == - V_222 ) {
if ( V_193 != V_65 )
F_72 ( V_193 ) ;
return V_223 ;
} else
goto V_207;
}
F_110 ( V_2 ) ;
if ( V_4 -> V_81 . V_82 )
V_4 -> V_83 . V_224 += F_97 () -
V_4 -> V_83 . V_210 ;
return V_6 ;
V_207:
V_4 -> V_156 . V_225 ++ ;
V_4 -> V_156 . V_226 ++ ;
if ( ( V_193 != V_65 ) && V_193 )
F_72 ( V_193 ) ;
F_72 ( V_65 ) ;
F_110 ( V_2 ) ;
return V_221 ;
}
static int F_111 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_110 ;
int V_6 = 0 ;
F_11 ( V_4 , 4 , L_43 ) ;
if ( V_4 -> V_121 == V_124 )
return V_6 ;
if ( V_4 -> V_121 != V_125 )
return - V_227 ;
if ( ( V_4 -> V_46 . type != V_66 ) &&
( ! ( V_4 -> V_46 . V_47 & V_48 ) ) ) {
F_11 ( V_4 , 4 , L_44 ) ;
return - V_27 ;
}
V_4 -> V_40 . V_121 = V_122 ;
V_4 -> V_121 = V_124 ;
F_112 ( V_2 ) ;
if ( F_113 ( V_4 -> V_40 . V_228 , 0 ) >= 0 ) {
F_114 ( & V_4 -> V_150 ) ;
F_115 ( & V_4 -> V_150 ) ;
} else
V_6 = - V_31 ;
return V_6 ;
}
static int F_116 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_110 ;
F_11 ( V_4 , 5 , L_45 ) ;
if ( F_45 ( V_4 , V_112 ) ) {
F_11 ( V_4 , 3 , L_46 ) ;
return - V_170 ;
}
return F_111 ( V_2 ) ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_110 ;
F_11 ( V_4 , 4 , L_47 ) ;
F_117 ( V_2 ) ;
if ( V_4 -> V_121 == V_124 ) {
V_4 -> V_121 = V_125 ;
F_118 ( & V_4 -> V_150 ) ;
}
return 0 ;
}
static int F_119 ( struct V_229 * V_50 )
{
struct V_3 * V_4 = F_120 ( & V_50 -> V_2 ) ;
int V_6 ;
if ( V_50 -> V_2 . type == & V_230 ) {
V_6 = F_121 ( & V_50 -> V_2 ) ;
if ( V_6 )
return V_6 ;
}
F_122 ( & V_4 -> V_115 ) ;
F_123 ( V_4 -> V_189 ) ;
V_4 -> V_81 . V_231 = 1 ;
V_4 -> V_46 . V_232 = 0 ;
return 0 ;
}
static void F_124 ( struct V_229 * V_233 )
{
struct V_3 * V_4 = F_120 ( & V_233 -> V_2 ) ;
if ( V_233 -> V_2 . type == & V_230 )
F_125 ( & V_233 -> V_2 ) ;
F_54 ( V_4 , 0 , 1 ) ;
F_126 ( V_4 -> V_234 , F_89 ( V_4 , 0xffffffff ) == 0 ) ;
if ( V_233 -> V_121 == V_235 )
F_127 ( V_233 ) ;
if ( V_4 -> V_2 ) {
F_128 ( & V_4 -> V_150 ) ;
F_129 ( V_4 -> V_2 ) ;
V_4 -> V_2 = NULL ;
}
return;
}
static int F_130 ( struct V_3 * V_4 )
{
switch ( V_4 -> V_46 . type ) {
case V_163 :
V_4 -> V_2 = F_131 ( 0 , L_48 , V_236 ,
V_237 ) ;
break;
case V_66 :
V_4 -> V_2 = F_131 ( 0 , L_49 , V_236 ,
V_237 ) ;
break;
default:
V_4 -> V_2 = F_132 ( 0 ) ;
}
if ( ! V_4 -> V_2 )
return - V_227 ;
V_4 -> V_2 -> V_110 = V_4 ;
V_4 -> V_2 -> V_238 = V_239 ;
V_4 -> V_2 -> V_240 = V_4 -> V_46 . V_241 ;
V_4 -> V_2 -> V_242 = 64 ;
V_4 -> V_2 -> V_243 = V_244 ;
V_4 -> V_2 -> V_245 = & V_246 ;
if ( V_4 -> V_46 . type == V_66 ) {
V_4 -> V_2 -> V_247 = & V_248 ;
V_4 -> V_2 -> V_5 |= V_249 ;
} else {
V_4 -> V_2 -> V_247 = & V_250 ;
}
V_4 -> V_2 -> V_140 |= V_251 ;
if ( V_4 -> V_46 . type == V_252 && ! V_4 -> V_46 . V_165 ) {
V_4 -> V_2 -> V_253 = V_254 ;
V_4 -> V_2 -> V_255 = V_254 ;
if ( F_77 ( V_4 , V_256 ) ) {
V_4 -> V_2 -> V_253 |= V_257 ;
V_4 -> V_2 -> V_255 |= V_257 ;
}
if ( F_77 ( V_4 , V_258 ) ) {
V_4 -> V_2 -> V_253 |= V_141 ;
V_4 -> V_2 -> V_255 |= V_141 ;
}
}
V_4 -> V_46 . V_259 = 1 ;
F_73 ( V_4 ) ;
V_4 -> V_2 -> V_260 = ( F_133 ( V_4 ) - 1 ) *
V_261 ;
F_134 ( V_4 -> V_2 , & V_4 -> V_50 -> V_2 ) ;
F_135 ( V_4 -> V_2 , & V_4 -> V_150 , V_262 , V_263 ) ;
F_136 ( V_4 -> V_2 ) ;
return F_137 ( V_4 -> V_2 ) ;
}
static int F_138 ( struct V_3 * V_4 )
{
if ( F_139 ( V_4 , 0 ) )
return - V_227 ;
return 0 ;
}
static void F_140 ( struct V_3 * V_4 )
{
F_11 ( V_4 , 2 , L_50 ) ;
F_82 ( V_4 , 2 , & V_4 -> V_81 . V_175 . V_264 ,
sizeof( V_4 -> V_81 . V_175 . V_264 ) ) ;
}
static int F_141 ( struct V_229 * V_50 , int V_118 )
{
struct V_3 * V_4 = F_120 ( & V_50 -> V_2 ) ;
int V_6 = 0 ;
enum V_265 V_266 ;
F_142 ( & V_4 -> V_267 ) ;
F_142 ( & V_4 -> V_268 ) ;
F_52 ( V_119 , 2 , L_51 ) ;
F_53 ( V_119 , 2 , & V_4 , sizeof( void * ) ) ;
V_266 = V_4 -> V_121 ;
V_6 = F_143 ( V_4 ) ;
if ( V_6 ) {
F_74 ( V_119 , 2 , L_52 , V_6 ) ;
V_6 = - V_227 ;
goto V_269;
}
F_144 ( V_4 ) ;
if ( V_4 -> V_81 . V_175 . V_264 )
F_15 ( & V_4 -> V_50 -> V_2 ,
L_53 ) ;
F_145 ( V_4 ) ;
F_140 ( V_4 ) ;
if ( ! V_4 -> V_2 && F_130 ( V_4 ) ) {
V_6 = - V_227 ;
goto V_269;
}
if ( V_4 -> V_46 . type != V_66 )
F_14 ( V_4 , & V_4 -> V_2 -> V_49 [ 0 ] ) ;
if ( F_146 ( V_4 , V_270 ) ) {
if ( V_4 -> V_46 . V_232 &&
F_147 ( V_4 , V_271 ) )
V_4 -> V_46 . V_232 = 0 ;
} else
V_4 -> V_46 . V_232 = 0 ;
F_148 ( V_4 ) ;
V_4 -> V_121 = V_126 ;
memset ( & V_4 -> V_134 , 0 , sizeof( struct V_272 ) ) ;
F_149 ( V_4 ) ;
F_52 ( V_119 , 2 , L_54 ) ;
if ( ( V_4 -> V_46 . type == V_252 ) ||
( V_4 -> V_46 . type == V_164 ) ) {
V_6 = F_138 ( V_4 ) ;
if ( V_6 )
goto V_269;
}
if ( V_4 -> V_46 . type != V_66 &&
V_4 -> V_46 . type != V_111 )
F_43 ( V_4 ) ;
F_117 ( V_4 -> V_2 ) ;
V_6 = F_150 ( V_4 ) ;
if ( V_6 ) {
F_74 ( V_119 , 2 , L_55 , V_6 ) ;
V_6 = - V_227 ;
goto V_269;
}
V_4 -> V_121 = V_125 ;
if ( V_4 -> V_205 )
F_151 ( V_4 -> V_2 ) ;
else
F_136 ( V_4 -> V_2 ) ;
F_54 ( V_4 , 0xffffffff , 0 ) ;
if ( V_266 == V_273 ) {
if ( V_118 &&
V_4 -> V_46 . type != V_66 ) {
F_111 ( V_4 -> V_2 ) ;
} else {
F_56 () ;
F_152 ( V_4 -> V_2 ) ;
F_58 () ;
}
F_50 ( V_4 -> V_2 ) ;
F_56 () ;
F_153 ( V_4 -> V_2 ) ;
F_58 () ;
}
F_154 ( & V_50 -> V_2 . V_274 , V_275 ) ;
F_155 ( & V_4 -> V_268 ) ;
F_155 ( & V_4 -> V_267 ) ;
return 0 ;
V_269:
F_51 ( V_4 , 0 ) ;
F_156 ( F_157 ( V_4 ) ) ;
F_156 ( F_158 ( V_4 ) ) ;
F_156 ( F_7 ( V_4 ) ) ;
F_159 ( F_157 ( V_4 ) ) ;
if ( V_266 == V_273 )
V_4 -> V_121 = V_273 ;
else
V_4 -> V_121 = V_127 ;
F_155 ( & V_4 -> V_268 ) ;
F_155 ( & V_4 -> V_267 ) ;
return V_6 ;
}
static int F_160 ( struct V_229 * V_50 )
{
return F_141 ( V_50 , 0 ) ;
}
static int F_161 ( struct V_229 * V_233 ,
int V_118 )
{
struct V_3 * V_4 = F_120 ( & V_233 -> V_2 ) ;
int V_6 = 0 , V_276 = 0 , V_277 = 0 ;
enum V_265 V_266 ;
F_142 ( & V_4 -> V_267 ) ;
F_142 ( & V_4 -> V_268 ) ;
F_52 ( V_119 , 3 , L_56 ) ;
F_53 ( V_119 , 3 , & V_4 , sizeof( void * ) ) ;
if ( V_4 -> V_2 && F_162 ( V_4 -> V_2 ) )
F_136 ( V_4 -> V_2 ) ;
V_266 = V_4 -> V_121 ;
if ( ( ! V_118 && V_4 -> V_46 . V_232 ) || V_4 -> V_46 . V_232 == 2 ) {
F_147 ( V_4 , V_278 ) ;
V_4 -> V_46 . V_232 = 1 ;
}
F_51 ( V_4 , V_118 ) ;
V_6 = F_156 ( F_157 ( V_4 ) ) ;
V_276 = F_156 ( F_158 ( V_4 ) ) ;
V_277 = F_156 ( F_7 ( V_4 ) ) ;
if ( ! V_6 )
V_6 = ( V_276 ) ? V_276 : V_277 ;
if ( V_6 )
F_74 ( V_119 , 2 , L_57 , V_6 ) ;
F_159 ( F_157 ( V_4 ) ) ;
if ( V_266 == V_124 )
V_4 -> V_121 = V_273 ;
F_154 ( & V_233 -> V_2 . V_274 , V_275 ) ;
F_155 ( & V_4 -> V_268 ) ;
F_155 ( & V_4 -> V_267 ) ;
return 0 ;
}
static int F_127 ( struct V_229 * V_233 )
{
return F_161 ( V_233 , 0 ) ;
}
static int F_163 ( void * V_279 )
{
struct V_3 * V_4 ;
int V_6 = 0 ;
V_4 = (struct V_3 * ) V_279 ;
F_11 ( V_4 , 2 , L_58 ) ;
if ( ! F_164 ( V_4 , V_112 ) )
return 0 ;
F_11 ( V_4 , 2 , L_59 ) ;
F_16 ( & V_4 -> V_50 -> V_2 ,
L_60 ) ;
F_165 ( V_4 ) ;
F_161 ( V_4 -> V_50 , 1 ) ;
V_6 = F_141 ( V_4 -> V_50 , 1 ) ;
if ( ! V_6 )
F_15 ( & V_4 -> V_50 -> V_2 ,
L_61 ) ;
else {
F_166 ( V_4 ) ;
F_16 ( & V_4 -> V_50 -> V_2 , L_62
L_63 ) ;
}
F_167 ( V_4 ) ;
F_168 ( V_4 , V_112 ) ;
F_169 ( V_4 , V_112 ) ;
return 0 ;
}
static int T_8 F_170 ( void )
{
F_171 ( L_64 ) ;
return 0 ;
}
static void T_9 F_172 ( void )
{
F_171 ( L_65 ) ;
}
static int F_173 ( struct V_229 * V_50 )
{
struct V_3 * V_4 = F_120 ( & V_50 -> V_2 ) ;
if ( V_4 -> V_2 )
F_174 ( V_4 -> V_2 ) ;
F_54 ( V_4 , 0 , 1 ) ;
F_126 ( V_4 -> V_234 , F_89 ( V_4 , 0xffffffff ) == 0 ) ;
if ( V_50 -> V_121 == V_280 )
return 0 ;
if ( V_4 -> V_121 == V_124 ) {
if ( V_4 -> V_46 . V_232 )
F_147 ( V_4 , V_278 ) ;
F_161 ( V_4 -> V_50 , 1 ) ;
} else
F_161 ( V_4 -> V_50 , 0 ) ;
return 0 ;
}
static int F_175 ( struct V_229 * V_50 )
{
struct V_3 * V_4 = F_120 ( & V_50 -> V_2 ) ;
int V_6 = 0 ;
if ( V_50 -> V_121 == V_280 )
goto V_161;
if ( V_4 -> V_121 == V_273 ) {
V_6 = F_141 ( V_4 -> V_50 , 1 ) ;
if ( V_6 ) {
F_56 () ;
F_57 ( V_4 -> V_2 ) ;
F_58 () ;
}
} else
V_6 = F_141 ( V_4 -> V_50 , 0 ) ;
V_161:
F_54 ( V_4 , 0xffffffff , 0 ) ;
if ( V_4 -> V_2 )
F_176 ( V_4 -> V_2 ) ;
if ( V_6 )
F_16 ( & V_4 -> V_50 -> V_2 , L_62
L_63 ) ;
return V_6 ;
}
static int F_177 ( struct V_3 * V_4 ,
struct V_35 * V_36 )
{
switch ( V_36 -> V_71 . V_104 ) {
case V_281 :
case V_282 :
if ( V_36 -> V_40 . V_175 . V_71 . V_283 ==
V_284 ) {
F_178 ( V_4 , V_36 ) ;
return 0 ;
} else
return 1 ;
case V_285 :
F_179 ( V_4 , V_36 ) ;
return 0 ;
default:
return 1 ;
}
}
static int F_180 ( struct V_3 * V_4 , int V_94 ,
struct V_37 * V_38 )
{
unsigned long V_5 ;
int V_6 = 0 ;
F_11 ( V_4 , 5 , L_66 ) ;
F_126 ( V_4 -> V_234 ,
F_181 ( & V_4 -> V_123 . V_286 , 0 , 1 ) == 0 ) ;
F_182 ( V_4 , V_94 , V_38 ) ;
F_11 ( V_4 , 6 , L_67 ) ;
F_183 ( F_184 ( V_4 -> V_123 . V_228 ) , V_5 ) ;
V_6 = F_185 ( V_4 -> V_123 . V_228 , & V_4 -> V_123 . V_287 ,
( V_288 ) V_38 , 0 , 0 ) ;
F_186 ( F_184 ( V_4 -> V_123 . V_228 ) , V_5 ) ;
if ( V_6 ) {
F_19 ( 2 , L_68
L_69 , V_6 ) ;
F_9 ( V_4 , 2 , L_70 , V_6 ) ;
F_187 ( V_38 -> V_289 , V_38 ) ;
F_188 ( & V_4 -> V_123 . V_286 , 0 ) ;
F_189 ( & V_4 -> V_234 ) ;
}
return V_6 ;
}
static int F_190 ( struct V_3 * V_4 ,
struct V_37 * V_38 , int V_290 )
{
T_6 V_291 , V_292 ;
F_11 ( V_4 , 4 , L_71 ) ;
F_191 ( V_4 , V_38 , V_293 ) ;
V_291 = ( T_6 ) ( V_41 + V_290 ) ;
V_292 = ( T_6 ) V_290 ;
memcpy ( F_192 ( V_38 -> V_40 ) , & V_291 , 2 ) ;
memcpy ( F_193 ( V_38 -> V_40 ) , & V_292 , 2 ) ;
memcpy ( F_194 ( V_38 -> V_40 ) , & V_292 , 2 ) ;
memcpy ( F_195 ( V_38 -> V_40 ) , & V_292 , 2 ) ;
return F_180 ( V_4 , V_291 , V_38 ) ;
}
int F_196 ( struct V_1 * V_2 , void * V_40 , int V_290 )
{
struct V_37 * V_38 ;
struct V_3 * V_4 ;
int V_6 ;
if ( ! V_2 )
return - V_227 ;
V_4 = V_2 -> V_110 ;
if ( ! V_4 )
return - V_227 ;
F_11 ( V_4 , 2 , L_72 ) ;
if ( ! F_197 ( V_4 ) )
return - V_227 ;
V_38 = F_198 ( & V_4 -> V_123 ) ;
memcpy ( V_38 -> V_40 + V_41 , V_40 , V_290 ) ;
V_6 = F_190 ( V_4 , V_38 , V_290 ) ;
return V_6 ;
}
int F_199 ( unsigned char * V_10 , struct V_1 * * V_2 ,
int (* F_200)( struct V_1 * , void * ) ,
int (* V_153)( struct V_64 * ) )
{
struct V_3 * V_4 ;
* V_2 = F_5 ( V_10 ) ;
if ( * V_2 == NULL )
return - V_227 ;
V_4 = ( * V_2 ) -> V_110 ;
if ( ! V_4 )
return - V_227 ;
F_11 ( V_4 , 2 , L_73 ) ;
if ( ( F_200 == NULL ) || ( V_153 == NULL ) )
return - V_171 ;
V_4 -> V_152 . F_200 = F_200 ;
V_4 -> V_152 . V_153 = V_153 ;
return 0 ;
}
void F_201 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( ! V_2 )
return;
V_4 = V_2 -> V_110 ;
if ( ! V_4 )
return;
F_11 ( V_4 , 2 , L_74 ) ;
V_4 -> V_152 . F_200 = NULL ;
V_4 -> V_152 . V_153 = NULL ;
return;
}
static void F_202 ( struct V_3 * V_4 ,
enum V_294 V_295 ,
T_4 V_296 , struct V_297 * V_298 , struct V_299 * V_300 )
{
char V_301 [ 7 ] [ 32 ] ;
char * V_302 [ 8 ] ;
int V_60 = 0 ;
switch ( V_295 ) {
case V_303 :
snprintf ( V_301 [ V_60 ] , sizeof( V_301 [ V_60 ] ) , L_75 ,
( V_296 & V_304 )
? L_76 : L_77 ) ;
V_302 [ V_60 ] = V_301 [ V_60 ] ; V_60 ++ ;
if ( V_296 & V_305 ) {
snprintf ( V_301 [ V_60 ] , sizeof( V_301 [ V_60 ] ) , L_78 ,
V_300 -> V_306 ) ;
V_302 [ V_60 ] = V_301 [ V_60 ] ; V_60 ++ ;
}
if ( V_296 & V_307 ) {
snprintf ( V_301 [ V_60 ] , sizeof( V_301 [ V_60 ] ) , L_79 ,
V_300 -> V_32 ) ;
V_302 [ V_60 ] = V_301 [ V_60 ] ; V_60 ++ ;
}
snprintf ( V_301 [ V_60 ] , sizeof( V_301 [ V_60 ] ) , L_80 ,
V_298 -> V_308 , V_298 -> V_309 , V_298 -> V_310 ) ;
V_302 [ V_60 ] = V_301 [ V_60 ] ; V_60 ++ ;
snprintf ( V_301 [ V_60 ] , sizeof( V_301 [ V_60 ] ) , L_81 , V_298 -> V_311 ) ;
V_302 [ V_60 ] = V_301 [ V_60 ] ; V_60 ++ ;
snprintf ( V_301 [ V_60 ] , sizeof( V_301 [ V_60 ] ) , L_82 ,
V_298 -> V_312 ) ;
V_302 [ V_60 ] = V_301 [ V_60 ] ; V_60 ++ ;
snprintf ( V_301 [ V_60 ] , sizeof( V_301 [ V_60 ] ) , L_83 , V_298 -> V_313 ) ;
V_302 [ V_60 ] = V_301 [ V_60 ] ; V_60 ++ ;
break;
case V_314 :
snprintf ( V_301 [ V_60 ] , sizeof( V_301 [ V_60 ] ) , L_84 ) ;
V_302 [ V_60 ] = V_301 [ V_60 ] ; V_60 ++ ;
break;
case V_315 :
snprintf ( V_301 [ V_60 ] , sizeof( V_301 [ V_60 ] ) , L_85 ) ;
V_302 [ V_60 ] = V_301 [ V_60 ] ; V_60 ++ ;
break;
}
V_302 [ V_60 ] = NULL ;
F_203 ( & V_4 -> V_50 -> V_2 . V_274 , V_275 , V_302 ) ;
}
static void F_204 ( struct V_316 * V_317 )
{
struct V_318 * V_40 =
F_205 ( V_317 , struct V_318 , V_319 ) ;
struct V_320 * V_321 = & V_40 -> V_322 . V_321 [ 0 ] ;
char V_323 [ 32 ] ;
char V_324 [ 32 ] ;
char V_325 [ 32 ] ;
char * V_302 [] = {
V_323 ,
V_324 ,
V_325 ,
NULL
} ;
F_142 ( & V_40 -> V_4 -> V_268 ) ;
V_40 -> V_4 -> V_81 . V_175 . V_174 = V_321 -> V_174 ;
F_155 ( & V_40 -> V_4 -> V_268 ) ;
snprintf ( V_323 , sizeof( V_323 ) , L_86 ) ;
snprintf ( V_324 , sizeof( V_324 ) , L_87 ,
( V_321 -> V_174 == V_183 ) ? L_88 :
( V_321 -> V_174 == V_181 ) ? L_89 :
( V_321 -> V_174 == V_182 ) ? L_90 :
L_91 ) ;
snprintf ( V_325 , sizeof( V_325 ) , L_92 ,
( V_321 -> V_121 == V_326 ) ? L_93 :
( V_321 -> V_121 == V_327 ) ? L_94 :
( V_321 -> V_121 == V_328 ) ? L_95 :
L_91 ) ;
F_203 ( & V_40 -> V_4 -> V_50 -> V_2 . V_274 ,
V_275 , V_302 ) ;
F_28 ( V_40 ) ;
}
static void F_178 ( struct V_3 * V_4 ,
struct V_35 * V_36 )
{
struct V_329 * V_322 =
& V_36 -> V_40 . V_175 . V_40 . V_330 ;
struct V_318 * V_40 ;
int V_331 ;
F_11 ( V_4 , 2 , L_96 ) ;
if ( V_322 -> V_332 != sizeof( struct V_320 ) ) {
F_9 ( V_4 , 2 , L_97 , V_322 -> V_332 ) ;
return;
}
V_331 = sizeof( struct V_320 ) * V_322 -> V_333 ;
V_40 = F_87 ( sizeof( struct V_318 ) + V_331 ,
V_113 ) ;
if ( ! V_40 ) {
F_11 ( V_4 , 2 , L_98 ) ;
return;
}
F_206 ( & V_40 -> V_319 , F_204 ) ;
V_40 -> V_4 = V_4 ;
memcpy ( & V_40 -> V_322 , V_322 ,
sizeof( struct V_329 ) + V_331 ) ;
F_207 ( V_334 , & V_40 -> V_319 ) ;
}
static void F_208 ( struct V_316 * V_317 )
{
struct V_335 * V_40 =
F_205 ( V_317 , struct V_335 , V_319 ) ;
int V_60 ;
if ( V_40 -> V_336 . V_337 ) {
F_15 ( & V_40 -> V_4 -> V_50 -> V_2 ,
L_99 ,
V_40 -> V_4 -> V_2 -> V_51 ,
( V_40 -> V_336 . V_337 == 0x01 )
? L_100
: ( V_40 -> V_336 . V_337 == 0x02 )
? L_101
: L_102 ) ;
F_142 ( & V_40 -> V_4 -> V_268 ) ;
V_40 -> V_4 -> V_81 . V_175 . V_338 = 0 ;
F_155 ( & V_40 -> V_4 -> V_268 ) ;
F_202 ( V_40 -> V_4 , V_314 ,
0 , NULL , NULL ) ;
} else
for ( V_60 = 0 ; V_60 < V_40 -> V_336 . V_333 ; V_60 ++ ) {
struct V_339 * V_321 =
& V_40 -> V_336 . V_321 [ V_60 ] ;
F_202 ( V_40 -> V_4 ,
V_303 ,
V_321 -> V_340 ,
& V_321 -> V_298 , & V_321 -> V_300 ) ;
}
F_28 ( V_40 ) ;
}
static void F_179 ( struct V_3 * V_4 ,
struct V_35 * V_36 )
{
struct V_341 * V_336 =
& V_36 -> V_40 . V_342 ;
struct V_335 * V_40 ;
int V_331 ;
F_11 ( V_4 , 2 , L_103 ) ;
if ( V_36 -> V_71 . V_102 != 0x0000 ) {
if ( V_36 -> V_71 . V_102 == 0x0010 ) {
if ( V_336 -> V_337 == 0x00 )
V_336 -> V_337 = 0xff ;
} else {
F_9 ( V_4 , 2 , L_104 ,
V_36 -> V_71 . V_102 ) ;
return;
}
}
V_331 = sizeof( struct V_339 ) *
V_336 -> V_333 ;
V_40 = F_87 ( sizeof( struct V_335 ) + V_331 ,
V_113 ) ;
if ( ! V_40 ) {
F_11 ( V_4 , 2 , L_105 ) ;
return;
}
F_206 ( & V_40 -> V_319 , F_208 ) ;
V_40 -> V_4 = V_4 ;
memcpy ( & V_40 -> V_336 , V_336 ,
sizeof( struct V_341 ) + V_331 ) ;
F_207 ( V_334 , & V_40 -> V_319 ) ;
}
static int F_209 ( struct V_3 * V_4 ,
struct V_343 * V_344 , enum V_345 V_346 )
{
int V_6 ;
int V_347 = ( V_4 -> V_46 . type == V_163 ) ;
if ( ( V_347 && ( V_344 -> V_348 == V_17 ) ) ||
( ! V_347 && ( V_344 -> V_348 == V_344 -> V_349 ) ) )
switch ( V_344 -> V_349 ) {
case V_17 :
V_6 = 0 ;
break;
case V_18 :
case V_350 :
V_6 = - V_19 ;
break;
case V_351 :
case V_352 :
V_6 = - V_227 ;
F_210 ( & V_4 -> V_50 -> V_2 ,
L_106 ) ;
break;
case V_353 :
case V_354 :
V_6 = - V_27 ;
F_210 ( & V_4 -> V_50 -> V_2 ,
L_107 ) ;
break;
case V_355 :
case V_356 :
switch ( V_346 ) {
case V_357 :
V_6 = - V_24 ;
F_210 ( & V_4 -> V_50 -> V_2 ,
L_108 ) ;
break;
case V_358 :
V_6 = - V_222 ;
F_210 ( & V_4 -> V_50 -> V_2 ,
L_109 ) ;
break;
default:
V_6 = - V_31 ;
}
break;
case V_359 :
case V_360 :
V_6 = - V_222 ;
F_210 ( & V_4 -> V_50 -> V_2 ,
L_110 ) ;
break;
case V_361 :
case V_362 :
V_6 = - V_24 ;
F_210 ( & V_4 -> V_50 -> V_2 ,
L_111 ) ;
break;
case V_363 :
case V_364 :
V_6 = - V_222 ;
F_210 ( & V_4 -> V_50 -> V_2 ,
L_109 ) ;
break;
case V_365 :
case V_366 :
V_6 = - V_367 ;
F_210 ( & V_4 -> V_50 -> V_2 ,
L_112 ) ;
break;
default:
V_6 = - V_31 ;
}
else
switch ( V_344 -> V_348 ) {
case V_368 :
V_6 = - V_19 ;
break;
case V_350 :
V_6 = - V_19 ;
break;
default:
V_6 = - V_31 ;
}
if ( V_6 ) {
F_9 ( V_4 , 2 , L_113 , V_344 -> V_348 ) ;
F_9 ( V_4 , 2 , L_114 , V_344 -> V_349 ) ;
}
return V_6 ;
}
static inline int F_211 ( struct V_3 * V_4 )
{
return ( V_4 -> V_46 . type == V_163 ) ?
V_282 :
V_281 ;
}
static int F_212 ( struct V_3 * V_4 ,
struct V_100 * V_101 , unsigned long V_40 )
{
struct V_35 * V_36 = (struct V_35 * ) V_40 ;
struct V_343 * V_344 = (struct V_343 * ) V_101 -> V_369 ;
F_11 ( V_4 , 2 , L_115 ) ;
V_344 -> V_348 = V_36 -> V_71 . V_102 ;
V_344 -> V_349 = V_36 -> V_40 . V_175 . V_71 . V_102 ;
if ( ( V_344 -> V_348 == 0 ) && ( V_344 -> V_349 == 0 ) ) {
V_344 -> V_40 . V_370 =
V_36 -> V_40 . V_175 . V_40 . V_371 . V_372 ;
} else {
V_344 -> V_40 . V_370 = 0 ;
}
return 0 ;
}
static void F_144 ( struct V_3 * V_4 )
{
struct V_37 * V_38 ;
struct V_35 * V_36 ;
struct V_343 V_344 ;
F_11 ( V_4 , 2 , L_116 ) ;
V_38 = F_12 ( V_4 , F_211 ( V_4 ) , 0 ) ;
if ( ! V_38 )
return;
V_36 = (struct V_35 * ) ( V_38 -> V_40 + V_41 ) ;
V_36 -> V_40 . V_175 . V_71 . V_373 =
sizeof( struct V_374 ) +
sizeof( struct V_375 ) ;
V_36 -> V_40 . V_175 . V_71 . V_283 =
V_376 ;
V_36 -> V_40 . V_175 . V_71 . V_377 = 1 ;
V_36 -> V_40 . V_175 . V_71 . V_378 = 1 ;
if ( F_13 ( V_4 , V_38 , F_212 ,
( void * ) & V_344 ) ||
F_209 ( V_4 , & V_344 ,
V_376 ) ) {
V_4 -> V_81 . V_175 . V_174 = V_183 ;
return;
}
V_4 -> V_81 . V_175 . V_264 = V_344 . V_40 . V_370 ;
}
static int F_213 ( struct V_3 * V_4 ,
struct V_100 * V_101 , unsigned long V_40 )
{
struct V_35 * V_36 = (struct V_35 * ) V_40 ;
struct V_379 * V_322 = & V_36 -> V_40 . V_175 . V_40 . V_380 ;
struct V_343 * V_344 = (struct V_343 * ) V_101 -> V_369 ;
F_11 ( V_4 , 2 , L_117 ) ;
V_344 -> V_348 = V_36 -> V_71 . V_102 ;
V_344 -> V_349 = V_36 -> V_40 . V_175 . V_71 . V_102 ;
if ( ( V_344 -> V_348 != 0 ) || ( V_344 -> V_349 != 0 ) )
return 0 ;
if ( V_322 -> V_332 != sizeof( struct V_320 ) ) {
V_344 -> V_349 = 0xffff ;
F_9 ( V_4 , 2 , L_118 , V_322 -> V_332 ) ;
return 0 ;
}
if ( V_322 -> V_333 > 0 ) {
if ( V_344 -> V_40 . V_322 . V_174 )
* V_344 -> V_40 . V_322 . V_174 = V_322 -> V_321 [ 0 ] . V_174 ;
if ( V_344 -> V_40 . V_322 . V_121 )
* V_344 -> V_40 . V_322 . V_121 = V_322 -> V_321 [ 0 ] . V_121 ;
}
return 0 ;
}
int F_214 ( struct V_3 * V_4 ,
enum V_381 * V_174 , enum V_382 * V_121 )
{
int V_6 = 0 ;
struct V_37 * V_38 ;
struct V_35 * V_36 ;
struct V_343 V_344 = {
. V_40 = {
. V_322 = {
. V_174 = V_174 ,
. V_121 = V_121 ,
} ,
} ,
} ;
F_11 ( V_4 , 2 , L_119 ) ;
if ( ! ( V_4 -> V_81 . V_175 . V_264 & V_383 ) )
return - V_19 ;
V_38 = F_12 ( V_4 , F_211 ( V_4 ) , 0 ) ;
if ( ! V_38 )
return - V_30 ;
V_36 = (struct V_35 * ) ( V_38 -> V_40 + V_41 ) ;
V_36 -> V_40 . V_175 . V_71 . V_373 =
sizeof( struct V_374 ) ;
V_36 -> V_40 . V_175 . V_71 . V_283 =
V_383 ;
V_36 -> V_40 . V_175 . V_71 . V_377 = 1 ;
V_36 -> V_40 . V_175 . V_71 . V_378 = 1 ;
V_6 = F_13 ( V_4 , V_38 , F_213 ,
( void * ) & V_344 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_209 ( V_4 , & V_344 , V_383 ) ;
}
static int F_215 ( struct V_3 * V_4 ,
struct V_100 * V_101 , unsigned long V_40 )
{
struct V_35 * V_36 = (struct V_35 * ) V_40 ;
struct V_343 * V_344 = (struct V_343 * ) V_101 -> V_369 ;
F_11 ( V_4 , 2 , L_120 ) ;
V_344 -> V_348 = V_36 -> V_71 . V_102 ;
V_344 -> V_349 = V_36 -> V_40 . V_175 . V_71 . V_102 ;
return 0 ;
}
int F_84 ( struct V_3 * V_4 , enum V_381 V_174 )
{
int V_6 = 0 ;
int V_373 ;
struct V_37 * V_38 ;
struct V_35 * V_36 ;
struct V_343 V_344 ;
enum V_345 V_346 ;
F_11 ( V_4 , 2 , L_121 ) ;
switch ( V_174 ) {
case V_183 :
V_346 = V_384 ;
V_373 = sizeof( struct V_374 ) +
sizeof( struct V_385 ) ;
break;
case V_181 :
V_346 = V_357 ;
V_373 = sizeof( struct V_374 ) +
sizeof( struct V_386 ) ;
break;
case V_182 :
V_346 = V_358 ;
V_373 = sizeof( struct V_374 ) +
sizeof( struct V_387 ) ;
break;
default:
return - V_171 ;
}
if ( ! ( V_4 -> V_81 . V_175 . V_264 & V_346 ) )
return - V_19 ;
V_38 = F_12 ( V_4 , F_211 ( V_4 ) , 0 ) ;
if ( ! V_38 )
return - V_30 ;
V_36 = (struct V_35 * ) ( V_38 -> V_40 + V_41 ) ;
V_36 -> V_40 . V_175 . V_71 . V_373 = V_373 ;
V_36 -> V_40 . V_175 . V_71 . V_283 = V_346 ;
V_36 -> V_40 . V_175 . V_71 . V_377 = 1 ;
V_36 -> V_40 . V_175 . V_71 . V_378 = 1 ;
V_6 = F_13 ( V_4 , V_38 , F_215 ,
( void * ) & V_344 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_209 ( V_4 , & V_344 , V_346 ) ;
}
static int F_216 ( struct V_3 * V_4 , int V_388 , T_6 V_389 )
{
int V_6 ;
if ( V_388 == 0 )
switch ( V_389 ) {
case 0x0001 :
V_6 = 0 ;
break;
case 0x0004 :
case 0x0100 :
case 0x0106 :
V_6 = - V_19 ;
F_210 ( & V_4 -> V_50 -> V_2 ,
L_122 ) ;
break;
case 0x0107 :
V_6 = - V_390 ;
break;
default:
V_6 = - V_31 ;
}
else
V_6 = - V_31 ;
if ( V_6 ) {
F_9 ( V_4 , 2 , L_123 , V_388 ) ;
F_9 ( V_4 , 2 , L_124 , V_389 ) ;
}
return V_6 ;
}
static void F_217 ( void * V_391 ,
enum V_392 type , void * V_321 )
{
struct V_3 * V_4 = (struct V_3 * ) V_391 ;
struct V_393 * V_394 ;
T_4 V_296 ;
if ( type != V_395 ) {
F_65 ( 1 ) ;
return;
}
V_394 = (struct V_393 * ) V_321 ;
V_296 = V_307 ;
if ( V_394 -> V_300 . V_306 )
V_296 |= V_305 ;
F_202 ( V_4 , V_303 , V_296 ,
(struct V_297 * ) & V_394 -> V_396 ,
(struct V_299 * ) & V_394 -> V_300 ) ;
}
int F_218 ( struct V_3 * V_4 , int V_397 )
{
int V_6 ;
T_6 V_389 ;
struct V_398 * V_399 ;
struct V_400 V_401 ;
if ( ! V_4 )
return - V_171 ;
if ( ! V_4 -> V_81 . V_175 . V_264 )
return - V_19 ;
V_399 = F_157 ( V_4 ) ;
F_219 ( V_399 , & V_401 ) ;
if ( V_397 ) {
F_202 ( V_4 , V_315 , 0 , NULL , NULL ) ;
V_6 = F_220 ( V_401 , 1 , & V_389 ,
F_217 , V_4 ) ;
} else
V_6 = F_220 ( V_401 , 0 , & V_389 , NULL , NULL ) ;
return F_216 ( V_4 , V_6 , V_389 ) ;
}
