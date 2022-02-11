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
static int F_30 ( struct V_3 * V_4 , struct V_63 * V_64 )
{
if ( V_4 -> V_46 . type == V_65 )
return V_66 ;
if ( F_31 ( V_64 -> V_40 ) )
return V_67 ;
if ( F_32 ( V_64 -> V_40 ) )
return V_68 ;
return V_66 ;
}
static void F_33 ( struct V_3 * V_4 , struct V_69 * V_70 ,
struct V_63 * V_64 )
{
struct V_71 * V_72 = F_34 ( V_64 ) ;
if ( V_72 -> V_73 == V_74 )
V_70 -> V_70 . V_75 . V_5 [ 1 ] |= V_76 ;
V_70 -> V_70 . V_75 . V_5 [ 1 ] |= V_77 |
V_78 ;
V_72 -> V_79 = 0 ;
if ( V_4 -> V_80 . V_81 )
V_4 -> V_82 . V_83 ++ ;
}
static void F_35 ( struct V_69 * V_70 , struct V_63 * V_64 ,
int V_84 , unsigned int V_85 )
{
struct V_86 * V_87 = (struct V_86 * ) F_36 ( V_64 ) ;
memset ( V_70 , 0 , sizeof( struct V_69 ) ) ;
V_70 -> V_70 . V_75 . V_88 = V_89 ;
V_70 -> V_70 . V_75 . V_90 = V_85 ;
if ( V_84 == V_68 )
V_70 -> V_70 . V_75 . V_5 [ 2 ] |= V_91 ;
else if ( V_84 == V_67 )
V_70 -> V_70 . V_75 . V_5 [ 2 ] |= V_92 ;
else
V_70 -> V_70 . V_75 . V_5 [ 2 ] |= V_93 ;
if ( V_87 -> V_94 == F_37 ( V_95 ) ) {
V_70 -> V_70 . V_75 . V_5 [ 2 ] |= V_96 ;
V_70 -> V_70 . V_75 . V_97 = F_38 ( V_87 -> V_98 ) ;
}
}
static int F_39 ( struct V_3 * V_4 ,
struct V_99 * V_100 , unsigned long V_40 )
{
struct V_35 * V_36 ;
F_11 ( V_4 , 2 , L_13 ) ;
V_36 = (struct V_35 * ) V_40 ;
if ( V_36 -> V_70 . V_101 ) {
F_19 ( 2 , L_14
L_15 , V_36 -> V_40 . V_102 . V_97 ,
F_20 ( V_4 ) , V_36 -> V_70 . V_101 ) ;
F_9 ( V_4 , 2 , L_16 , V_36 -> V_70 . V_103 ) ;
F_9 ( V_4 , 2 , L_17 , V_36 -> V_70 . V_101 ) ;
}
return 0 ;
}
static int F_40 ( struct V_3 * V_4 , T_1 V_60 ,
enum V_33 V_34 )
{
struct V_35 * V_36 ;
struct V_37 * V_38 ;
F_9 ( V_4 , 4 , L_18 , V_34 ) ;
V_38 = F_12 ( V_4 , V_34 , V_39 ) ;
if ( ! V_38 )
return - V_30 ;
V_36 = (struct V_35 * ) ( V_38 -> V_40 + V_41 ) ;
V_36 -> V_40 . V_102 . V_97 = V_60 ;
return F_13 ( V_4 , V_38 ,
F_39 , NULL ) ;
}
static void F_41 ( struct V_3 * V_4 )
{
struct V_104 * V_88 ;
F_11 ( V_4 , 3 , L_19 ) ;
F_25 ( & V_4 -> V_105 ) ;
F_3 (id, &card->vid_list, list) {
F_40 ( V_4 , V_88 -> V_106 , V_107 ) ;
}
F_29 ( & V_4 -> V_105 ) ;
}
static int F_42 ( struct V_1 * V_2 ,
T_3 V_108 , T_4 V_106 )
{
struct V_3 * V_4 = V_2 -> V_109 ;
struct V_104 * V_88 ;
int V_6 ;
F_9 ( V_4 , 4 , L_20 , V_106 ) ;
if ( ! V_106 )
return 0 ;
if ( V_4 -> V_46 . type == V_110 ) {
F_11 ( V_4 , 3 , L_21 ) ;
return 0 ;
}
if ( F_43 ( V_4 , V_111 ) ) {
F_11 ( V_4 , 3 , L_22 ) ;
return 0 ;
}
V_88 = F_44 ( sizeof( struct V_104 ) , V_112 ) ;
if ( V_88 ) {
V_88 -> V_106 = V_106 ;
V_6 = F_40 ( V_4 , V_106 , V_107 ) ;
if ( V_6 ) {
F_28 ( V_88 ) ;
return V_6 ;
}
F_25 ( & V_4 -> V_105 ) ;
F_45 ( & V_88 -> V_113 , & V_4 -> V_114 ) ;
F_29 ( & V_4 -> V_105 ) ;
} else {
return - V_30 ;
}
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ,
T_3 V_108 , T_4 V_106 )
{
struct V_104 * V_88 , * V_115 = NULL ;
struct V_3 * V_4 = V_2 -> V_109 ;
int V_6 = 0 ;
F_9 ( V_4 , 4 , L_23 , V_106 ) ;
if ( V_4 -> V_46 . type == V_110 ) {
F_11 ( V_4 , 3 , L_24 ) ;
return 0 ;
}
if ( F_43 ( V_4 , V_111 ) ) {
F_11 ( V_4 , 3 , L_25 ) ;
return 0 ;
}
F_25 ( & V_4 -> V_105 ) ;
F_3 (id, &card->vid_list, list) {
if ( V_88 -> V_106 == V_106 ) {
F_47 ( & V_88 -> V_113 ) ;
V_115 = V_88 ;
break;
}
}
F_29 ( & V_4 -> V_105 ) ;
if ( V_115 ) {
V_6 = F_40 ( V_4 , V_106 , V_116 ) ;
F_28 ( V_115 ) ;
}
F_48 ( V_4 -> V_2 ) ;
return V_6 ;
}
static void F_49 ( struct V_3 * V_4 , int V_117 )
{
F_50 ( V_118 , 2 , L_26 ) ;
F_51 ( V_118 , 2 , & V_4 , sizeof( void * ) ) ;
F_52 ( V_4 , 0 , 1 ) ;
if ( V_4 -> V_119 . V_120 == V_121 &&
V_4 -> V_122 . V_120 == V_121 &&
( V_4 -> V_120 == V_123 ) ) {
if ( V_117 &&
V_4 -> V_46 . type != V_65 ) {
F_53 ( V_4 -> V_2 ) ;
} else {
F_54 () ;
F_55 ( V_4 -> V_2 ) ;
F_56 () ;
}
V_4 -> V_46 . V_47 &= ~ V_48 ;
V_4 -> V_120 = V_124 ;
}
if ( V_4 -> V_120 == V_124 ) {
F_24 ( V_4 ) ;
F_57 ( V_4 ) ;
V_4 -> V_120 = V_125 ;
}
if ( V_4 -> V_120 == V_125 ) {
F_58 ( V_4 , 0 ) ;
F_59 ( V_4 ) ;
F_60 ( V_4 ) ;
V_4 -> V_120 = V_126 ;
}
if ( V_4 -> V_120 == V_126 ) {
F_61 ( & V_4 -> V_119 ) ;
F_61 ( & V_4 -> V_122 ) ;
}
}
static int F_62 ( struct V_3 * V_4 ,
int V_127 , int * V_128 )
{
int V_129 = 0 ;
struct V_63 * V_64 ;
struct V_69 * V_70 ;
unsigned int V_130 ;
* V_128 = 0 ;
F_63 ( ! V_127 ) ;
while ( V_127 ) {
V_64 = F_64 ( V_4 ,
& V_4 -> V_131 . V_132 -> V_133 [ V_4 -> V_134 . V_135 ] ,
& V_4 -> V_134 . V_136 , & V_4 -> V_134 . V_137 , & V_70 ) ;
if ( ! V_64 ) {
* V_128 = 1 ;
break;
}
V_64 -> V_2 = V_4 -> V_2 ;
switch ( V_70 -> V_70 . V_75 . V_88 ) {
case V_89 :
V_64 -> V_138 = V_139 ;
V_64 -> V_73 = F_65 ( V_64 , V_64 -> V_2 ) ;
if ( ( V_4 -> V_2 -> V_140 & V_141 )
&& ( ( V_70 -> V_70 . V_75 . V_5 [ 1 ] &
( V_78 |
V_77 ) ) ==
( V_78 |
V_77 ) ) )
V_64 -> V_142 = V_143 ;
else
V_64 -> V_142 = V_144 ;
if ( V_64 -> V_73 == F_66 ( V_145 ) )
* ( ( V_146 * ) V_64 -> V_147 ) = ++ V_4 -> V_148 . V_149 ;
V_130 = V_64 -> V_130 ;
F_67 ( & V_4 -> V_150 , V_64 ) ;
break;
case V_151 :
if ( V_4 -> V_46 . type == V_65 ) {
F_68 ( V_64 , sizeof( struct V_69 ) ) ;
F_69 ( V_64 , V_70 ,
sizeof( struct V_69 ) ) ;
V_130 = V_64 -> V_130 ;
V_4 -> V_152 . V_153 ( V_64 ) ;
break;
}
default:
F_70 ( V_64 ) ;
F_11 ( V_4 , 3 , L_27 ) ;
F_51 ( V_154 , 3 , V_70 , V_155 ) ;
continue;
}
V_129 ++ ;
V_127 -- ;
V_4 -> V_156 . V_157 ++ ;
V_4 -> V_156 . V_158 += V_130 ;
}
return V_129 ;
}
static int F_71 ( struct V_3 * V_4 )
{
int V_6 = 0 ;
char V_159 [] = { 0x02 , 0x00 , 0x00 } ;
F_50 ( V_118 , 2 , L_28 ) ;
F_72 ( V_118 , 2 , L_29 , F_73 ( V_4 ) ) ;
if ( V_160 ) {
V_6 = F_74 ( V_4 ) ;
if ( ! V_6 )
goto V_161;
F_19 ( 2 , L_30 ,
F_73 ( V_4 ) , V_6 ) ;
F_72 ( V_118 , 2 , L_1 , V_6 ) ;
}
if ( V_4 -> V_46 . type == V_162 ||
V_4 -> V_46 . type == V_110 ||
V_4 -> V_46 . type == V_163 ||
V_4 -> V_46 . V_164 ) {
V_6 = F_75 ( V_4 ) ;
if ( V_6 ) {
F_19 ( 2 , L_31
L_32 , F_73 ( V_4 ) , V_6 ) ;
F_72 ( V_118 , 2 , L_33 , V_6 ) ;
return V_6 ;
}
} else {
F_76 ( V_4 -> V_2 -> V_49 ) ;
memcpy ( V_4 -> V_2 -> V_49 , V_159 , 3 ) ;
}
V_161:
F_51 ( V_118 , 2 , V_4 -> V_2 -> V_49 , V_4 -> V_2 -> V_165 ) ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 , void * V_166 )
{
struct V_167 * V_168 = V_166 ;
struct V_3 * V_4 = V_2 -> V_109 ;
int V_6 = 0 ;
F_11 ( V_4 , 3 , L_34 ) ;
if ( F_1 ( V_2 ) != V_9 ) {
F_11 ( V_4 , 3 , L_35 ) ;
return - V_19 ;
}
if ( V_4 -> V_46 . type == V_65 ||
V_4 -> V_46 . type == V_110 ||
V_4 -> V_46 . type == V_163 ) {
F_11 ( V_4 , 3 , L_36 ) ;
return - V_19 ;
}
F_78 ( V_4 , 3 , V_168 -> V_169 , V_44 ) ;
if ( F_43 ( V_4 , V_111 ) ) {
F_11 ( V_4 , 3 , L_37 ) ;
return - V_170 ;
}
V_6 = F_17 ( V_4 , & V_4 -> V_2 -> V_49 [ 0 ] ) ;
if ( ! V_6 || ( V_6 == - V_29 ) )
V_6 = F_14 ( V_4 , V_168 -> V_169 ) ;
return V_6 ? - V_171 : 0 ;
}
static void F_79 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
enum V_172 V_173 ;
int V_174 ;
int V_6 ;
F_11 ( V_4 , 3 , L_38 ) ;
if ( ! V_4 -> V_80 . V_175 . V_176 )
return;
V_173 = ( V_2 -> V_5 & V_177 ) ? V_178
: V_179 ;
if ( V_173 == V_4 -> V_46 . V_173 )
return;
if ( V_173 == V_178 ) {
if ( V_4 -> V_80 . V_175 . V_180 )
V_174 = V_181 ;
else
V_174 = V_182 ;
} else
V_174 = V_183 ;
V_6 = F_80 ( V_4 , V_174 ) ;
F_72 ( V_118 , 2 , L_39 ,
( V_173 == V_178 ) ? '+' : '-' , V_6 ) ;
if ( ! V_6 ) {
V_4 -> V_80 . V_175 . V_174 = V_174 ;
V_4 -> V_46 . V_173 = V_173 ;
}
}
static void F_81 ( struct V_3 * V_4 , struct V_184 * V_185 ,
T_5 V_56 )
{
T_6 V_186 = F_82 ( ( T_6 * ) ( & V_185 -> V_168 [ 2 ] ) ) ;
struct V_55 * V_32 ;
F_83 (card->mac_htable, mac, hnode, mac_hash) {
if ( V_56 == V_32 -> V_56 &&
! memcmp ( V_185 -> V_168 , V_32 -> V_57 , V_44 ) ) {
V_32 -> V_187 = V_188 ;
return;
}
}
V_32 = F_84 ( sizeof( struct V_55 ) , V_112 ) ;
if ( ! V_32 )
return;
memcpy ( V_32 -> V_57 , V_185 -> V_168 , V_44 ) ;
V_32 -> V_56 = V_56 ;
V_32 -> V_187 = V_189 ;
F_85 ( V_4 -> V_190 , & V_32 -> V_62 , V_186 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_109 ;
struct V_184 * V_185 ;
struct V_55 * V_32 ;
struct V_58 * V_59 ;
int V_60 ;
int V_6 ;
if ( V_4 -> V_46 . type == V_65 )
return;
F_11 ( V_4 , 3 , L_40 ) ;
if ( F_86 ( V_4 , V_111 ) &&
( V_4 -> V_120 != V_123 ) )
return;
F_25 ( & V_4 -> V_61 ) ;
F_87 (ha, dev)
F_81 ( V_4 , V_185 , 0 ) ;
F_88 (ha, dev)
F_81 ( V_4 , V_185 , 1 ) ;
F_26 (card->mac_htable, i, tmp, mac, hnode) {
if ( V_32 -> V_187 == V_191 ) {
F_23 ( V_4 , V_32 ) ;
F_27 ( & V_32 -> V_62 ) ;
F_28 ( V_32 ) ;
} else if ( V_32 -> V_187 == V_189 ) {
V_6 = F_22 ( V_4 , V_32 ) ;
if ( V_6 ) {
F_27 ( & V_32 -> V_62 ) ;
F_28 ( V_32 ) ;
} else
V_32 -> V_187 = V_191 ;
} else
V_32 -> V_187 = V_191 ;
}
F_29 ( & V_4 -> V_61 ) ;
if ( F_89 ( V_4 , V_192 ) )
F_90 ( V_4 ) ;
else
F_79 ( V_4 ) ;
}
static int F_91 ( struct V_3 * V_4 , struct V_63 * V_64 ,
struct V_193 * V_194 , int V_84 )
{
unsigned int V_195 = V_196 ;
struct V_69 * V_70 ;
int V_6 ;
V_70 = F_92 ( V_197 , V_112 ) ;
if ( ! V_70 )
return - V_30 ;
F_35 ( V_70 , V_64 , V_84 , V_64 -> V_130 ) ;
F_93 ( V_64 , ( ( char * ) V_70 ) + sizeof( * V_70 ) ,
V_195 ) ;
if ( ! F_94 ( V_4 , V_64 , 1 , V_195 ) ) {
V_6 = - V_198 ;
goto V_161;
}
V_6 = F_95 ( V_4 , V_194 , V_64 , V_70 , V_195 ,
sizeof( * V_70 ) + V_195 ) ;
V_161:
if ( V_6 )
F_96 ( V_197 , V_70 ) ;
return V_6 ;
}
static int F_97 ( struct V_3 * V_4 , struct V_63 * V_64 ,
struct V_193 * V_194 , int V_84 )
{
int V_199 = sizeof( struct V_69 ) ;
unsigned int V_200 , V_201 ;
unsigned int V_202 = 0 ;
struct V_69 * V_70 = NULL ;
unsigned int V_203 = 0 ;
int V_6 ;
if ( ! F_94 ( V_4 , V_64 , 0 , 0 ) ) {
V_6 = F_98 ( V_64 ) ;
if ( V_4 -> V_80 . V_81 ) {
if ( V_6 )
V_4 -> V_82 . V_204 ++ ;
else
V_4 -> V_82 . V_205 ++ ;
}
if ( V_6 )
return V_6 ;
}
V_201 = F_99 ( V_64 ) -> V_201 ;
V_6 = F_100 ( V_64 , V_199 ) ;
if ( V_6 )
return V_6 ;
V_199 = F_101 ( V_64 , & V_70 , V_199 ) ;
if ( V_199 < 0 )
return V_199 ;
if ( ! V_199 ) {
V_203 = sizeof( * V_70 ) ;
V_202 = 1 ;
}
F_35 ( V_70 , V_64 , V_84 , V_64 -> V_130 - V_199 ) ;
if ( V_64 -> V_142 == V_206 )
F_33 ( V_4 , V_70 , V_64 ) ;
V_200 = F_94 ( V_4 , V_64 , V_202 , 0 ) ;
if ( ! V_200 ) {
V_6 = - V_198 ;
goto V_161;
}
V_200 += V_202 ;
F_102 ( V_64 ) ;
V_6 = F_103 ( V_4 , V_194 , V_64 , V_70 , 0 , V_203 , V_200 ) ;
V_161:
if ( ! V_6 ) {
if ( V_4 -> V_80 . V_81 && V_201 ) {
V_4 -> V_82 . V_207 ++ ;
V_4 -> V_82 . V_208 += V_201 + 1 ;
}
} else {
if ( V_203 )
F_96 ( V_197 , V_70 ) ;
if ( V_6 == - V_209 )
F_104 ( V_64 , V_199 ) ;
}
return V_6 ;
}
static int F_105 ( struct V_3 * V_4 , struct V_63 * V_64 ,
struct V_193 * V_194 )
{
unsigned int V_200 ;
struct V_69 * V_70 ;
if ( V_64 -> V_73 == F_66 ( V_210 ) )
return - V_211 ;
V_70 = (struct V_69 * ) V_64 -> V_40 ;
V_200 = F_94 ( V_4 , V_64 , 0 , 0 ) ;
if ( ! V_200 )
return - V_198 ;
if ( F_106 ( V_64 , & V_70 , sizeof( * V_70 ) ) )
return - V_171 ;
return F_103 ( V_4 , V_194 , V_64 , V_70 , 0 , 0 , V_200 ) ;
}
static T_7 F_107 ( struct V_63 * V_64 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_109 ;
int V_84 = F_30 ( V_4 , V_64 ) ;
struct V_193 * V_194 ;
int V_212 = V_64 -> V_130 ;
int V_6 ;
if ( V_4 -> V_131 . V_213 || ( V_84 &&
V_4 -> V_46 . V_214 ) )
V_194 = V_4 -> V_131 . V_215 [ F_108 ( V_4 , V_64 ,
F_109 ( V_64 ) , V_84 ) ] ;
else
V_194 = V_4 -> V_131 . V_215 [ V_4 -> V_131 . V_216 ] ;
if ( ( V_4 -> V_120 != V_123 ) || ! V_4 -> V_217 ) {
V_4 -> V_156 . V_218 ++ ;
goto V_219;
}
if ( V_4 -> V_80 . V_81 ) {
V_4 -> V_82 . V_220 ++ ;
V_4 -> V_82 . V_221 = F_110 () ;
}
F_111 ( V_2 ) ;
switch ( V_4 -> V_46 . type ) {
case V_65 :
V_6 = F_105 ( V_4 , V_64 , V_194 ) ;
break;
case V_162 :
V_6 = F_91 ( V_4 , V_64 , V_194 , V_84 ) ;
break;
default:
V_6 = F_97 ( V_4 , V_64 , V_194 , V_84 ) ;
}
if ( ! V_6 ) {
V_4 -> V_156 . V_222 ++ ;
V_4 -> V_156 . V_212 += V_212 ;
if ( V_4 -> V_80 . V_81 )
V_4 -> V_82 . V_223 += F_110 () -
V_4 -> V_82 . V_221 ;
F_112 ( V_2 ) ;
return V_224 ;
} else if ( V_6 == - V_209 ) {
return V_225 ;
}
V_219:
V_4 -> V_156 . V_226 ++ ;
V_4 -> V_156 . V_227 ++ ;
F_70 ( V_64 ) ;
F_112 ( V_2 ) ;
return V_224 ;
}
static int F_113 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_109 ;
int V_6 = 0 ;
F_11 ( V_4 , 4 , L_41 ) ;
if ( V_4 -> V_120 == V_123 )
return V_6 ;
if ( V_4 -> V_120 != V_124 )
return - V_228 ;
if ( ( V_4 -> V_46 . type != V_65 ) &&
( ! ( V_4 -> V_46 . V_47 & V_48 ) ) ) {
F_11 ( V_4 , 4 , L_42 ) ;
return - V_27 ;
}
V_4 -> V_40 . V_120 = V_121 ;
V_4 -> V_120 = V_123 ;
F_114 ( V_2 ) ;
if ( F_115 ( V_4 -> V_40 . V_229 , 0 ) >= 0 ) {
F_116 ( & V_4 -> V_150 ) ;
F_117 ( & V_4 -> V_150 ) ;
} else
V_6 = - V_31 ;
return V_6 ;
}
static int F_118 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_109 ;
F_11 ( V_4 , 5 , L_43 ) ;
if ( F_43 ( V_4 , V_111 ) ) {
F_11 ( V_4 , 3 , L_44 ) ;
return - V_170 ;
}
return F_113 ( V_2 ) ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_109 ;
F_11 ( V_4 , 4 , L_45 ) ;
F_119 ( V_2 ) ;
if ( V_4 -> V_120 == V_123 ) {
V_4 -> V_120 = V_124 ;
F_120 ( & V_4 -> V_150 ) ;
}
return 0 ;
}
static int F_121 ( struct V_230 * V_50 )
{
struct V_3 * V_4 = F_122 ( & V_50 -> V_2 ) ;
int V_6 ;
if ( V_50 -> V_2 . type == & V_231 ) {
V_6 = F_123 ( & V_50 -> V_2 ) ;
if ( V_6 )
return V_6 ;
}
F_124 ( & V_4 -> V_114 ) ;
F_125 ( V_4 -> V_190 ) ;
V_4 -> V_80 . V_232 = 1 ;
V_4 -> V_46 . V_233 = 0 ;
return 0 ;
}
static void F_126 ( struct V_230 * V_234 )
{
struct V_3 * V_4 = F_122 ( & V_234 -> V_2 ) ;
if ( V_234 -> V_2 . type == & V_231 )
F_127 ( & V_234 -> V_2 ) ;
F_52 ( V_4 , 0 , 1 ) ;
F_128 ( V_4 -> V_235 , F_86 ( V_4 , 0xffffffff ) == 0 ) ;
if ( V_234 -> V_120 == V_236 )
F_129 ( V_234 ) ;
if ( V_4 -> V_2 ) {
F_130 ( & V_4 -> V_150 ) ;
F_131 ( V_4 -> V_2 ) ;
V_4 -> V_2 = NULL ;
}
return;
}
static int F_132 ( struct V_3 * V_4 )
{
switch ( V_4 -> V_46 . type ) {
case V_162 :
V_4 -> V_2 = F_133 ( 0 , L_46 , V_237 ,
V_238 ) ;
break;
case V_65 :
V_4 -> V_2 = F_133 ( 0 , L_47 , V_237 ,
V_238 ) ;
break;
default:
V_4 -> V_2 = F_134 ( 0 ) ;
}
if ( ! V_4 -> V_2 )
return - V_228 ;
V_4 -> V_2 -> V_109 = V_4 ;
V_4 -> V_2 -> V_239 = V_240 ;
V_4 -> V_2 -> V_241 = V_4 -> V_46 . V_242 ;
V_4 -> V_2 -> V_243 = 64 ;
V_4 -> V_2 -> V_244 = V_245 ;
V_4 -> V_2 -> V_246 = & V_247 ;
if ( V_4 -> V_46 . type == V_65 ) {
V_4 -> V_2 -> V_248 = & V_249 ;
V_4 -> V_2 -> V_5 |= V_250 ;
} else {
V_4 -> V_2 -> V_248 = & V_251 ;
}
V_4 -> V_2 -> V_140 |= V_252 ;
if ( V_4 -> V_46 . type == V_253 && ! V_4 -> V_46 . V_164 ) {
V_4 -> V_2 -> V_254 = V_255 ;
V_4 -> V_2 -> V_256 = V_255 ;
if ( F_135 ( V_4 , V_257 ) ) {
V_4 -> V_2 -> V_254 |= V_258 ;
V_4 -> V_2 -> V_256 |= V_258 ;
}
if ( F_135 ( V_4 , V_259 ) ) {
V_4 -> V_2 -> V_254 |= V_141 ;
V_4 -> V_2 -> V_256 |= V_141 ;
}
}
if ( V_4 -> V_46 . type != V_65 &&
V_4 -> V_46 . type != V_162 ) {
V_4 -> V_2 -> V_260 &= ~ V_261 ;
V_4 -> V_2 -> V_262 = sizeof( struct V_69 ) ;
}
V_4 -> V_46 . V_263 = 1 ;
F_71 ( V_4 ) ;
V_4 -> V_2 -> V_264 = ( F_136 ( V_4 ) - 1 ) *
V_265 ;
F_137 ( V_4 -> V_2 , & V_4 -> V_50 -> V_2 ) ;
F_138 ( V_4 -> V_2 , & V_4 -> V_150 , V_266 , V_267 ) ;
F_139 ( V_4 -> V_2 ) ;
return F_140 ( V_4 -> V_2 ) ;
}
static int F_141 ( struct V_3 * V_4 )
{
if ( F_142 ( V_4 , 0 ) )
return - V_228 ;
return 0 ;
}
static void F_143 ( struct V_3 * V_4 )
{
F_11 ( V_4 , 2 , L_48 ) ;
F_78 ( V_4 , 2 , & V_4 -> V_80 . V_175 . V_268 ,
sizeof( V_4 -> V_80 . V_175 . V_268 ) ) ;
}
static int F_144 ( struct V_230 * V_50 , int V_117 )
{
struct V_3 * V_4 = F_122 ( & V_50 -> V_2 ) ;
int V_6 = 0 ;
enum V_269 V_270 ;
F_145 ( & V_4 -> V_271 ) ;
F_145 ( & V_4 -> V_272 ) ;
F_50 ( V_118 , 2 , L_49 ) ;
F_51 ( V_118 , 2 , & V_4 , sizeof( void * ) ) ;
V_270 = V_4 -> V_120 ;
V_6 = F_146 ( V_4 ) ;
if ( V_6 ) {
F_72 ( V_118 , 2 , L_50 , V_6 ) ;
V_6 = - V_228 ;
goto V_273;
}
F_147 ( V_4 ) ;
if ( V_4 -> V_80 . V_175 . V_268 )
F_15 ( & V_4 -> V_50 -> V_2 ,
L_51 ) ;
F_148 ( V_4 ) ;
F_143 ( V_4 ) ;
if ( ! V_4 -> V_2 && F_132 ( V_4 ) ) {
V_6 = - V_228 ;
goto V_273;
}
if ( V_4 -> V_46 . type != V_65 )
F_14 ( V_4 , & V_4 -> V_2 -> V_49 [ 0 ] ) ;
if ( F_149 ( V_4 , V_274 ) ) {
if ( V_4 -> V_46 . V_233 &&
F_150 ( V_4 , V_275 ) )
V_4 -> V_46 . V_233 = 0 ;
} else
V_4 -> V_46 . V_233 = 0 ;
F_151 ( V_4 ) ;
V_4 -> V_120 = V_125 ;
memset ( & V_4 -> V_134 , 0 , sizeof( struct V_276 ) ) ;
F_152 ( V_4 ) ;
F_50 ( V_118 , 2 , L_52 ) ;
if ( ( V_4 -> V_46 . type == V_253 ) ||
( V_4 -> V_46 . type == V_163 ) ) {
V_6 = F_141 ( V_4 ) ;
if ( V_6 )
goto V_273;
}
if ( V_4 -> V_46 . type != V_65 &&
V_4 -> V_46 . type != V_110 )
F_41 ( V_4 ) ;
F_119 ( V_4 -> V_2 ) ;
V_6 = F_153 ( V_4 ) ;
if ( V_6 ) {
F_72 ( V_118 , 2 , L_53 , V_6 ) ;
V_6 = - V_228 ;
goto V_273;
}
V_4 -> V_120 = V_124 ;
if ( V_4 -> V_217 )
F_154 ( V_4 -> V_2 ) ;
else
F_139 ( V_4 -> V_2 ) ;
F_52 ( V_4 , 0xffffffff , 0 ) ;
if ( V_270 == V_277 ) {
if ( V_117 &&
V_4 -> V_46 . type != V_65 ) {
F_113 ( V_4 -> V_2 ) ;
} else {
F_54 () ;
F_155 ( V_4 -> V_2 ) ;
F_56 () ;
}
F_48 ( V_4 -> V_2 ) ;
F_54 () ;
F_156 ( V_4 -> V_2 ) ;
F_56 () ;
}
F_157 ( & V_50 -> V_2 . V_278 , V_279 ) ;
F_158 ( & V_4 -> V_272 ) ;
F_158 ( & V_4 -> V_271 ) ;
return 0 ;
V_273:
F_49 ( V_4 , 0 ) ;
F_159 ( F_160 ( V_4 ) ) ;
F_159 ( F_161 ( V_4 ) ) ;
F_159 ( F_7 ( V_4 ) ) ;
F_162 ( F_160 ( V_4 ) ) ;
if ( V_270 == V_277 )
V_4 -> V_120 = V_277 ;
else
V_4 -> V_120 = V_126 ;
F_158 ( & V_4 -> V_272 ) ;
F_158 ( & V_4 -> V_271 ) ;
return V_6 ;
}
static int F_163 ( struct V_230 * V_50 )
{
return F_144 ( V_50 , 0 ) ;
}
static int F_164 ( struct V_230 * V_234 ,
int V_117 )
{
struct V_3 * V_4 = F_122 ( & V_234 -> V_2 ) ;
int V_6 = 0 , V_280 = 0 , V_281 = 0 ;
enum V_269 V_270 ;
F_145 ( & V_4 -> V_271 ) ;
F_145 ( & V_4 -> V_272 ) ;
F_50 ( V_118 , 3 , L_54 ) ;
F_51 ( V_118 , 3 , & V_4 , sizeof( void * ) ) ;
if ( V_4 -> V_2 && F_165 ( V_4 -> V_2 ) )
F_139 ( V_4 -> V_2 ) ;
V_270 = V_4 -> V_120 ;
if ( ( ! V_117 && V_4 -> V_46 . V_233 ) || V_4 -> V_46 . V_233 == 2 ) {
F_150 ( V_4 , V_282 ) ;
V_4 -> V_46 . V_233 = 1 ;
}
F_49 ( V_4 , V_117 ) ;
V_6 = F_159 ( F_160 ( V_4 ) ) ;
V_280 = F_159 ( F_161 ( V_4 ) ) ;
V_281 = F_159 ( F_7 ( V_4 ) ) ;
if ( ! V_6 )
V_6 = ( V_280 ) ? V_280 : V_281 ;
if ( V_6 )
F_72 ( V_118 , 2 , L_55 , V_6 ) ;
F_162 ( F_160 ( V_4 ) ) ;
if ( V_270 == V_123 )
V_4 -> V_120 = V_277 ;
F_157 ( & V_234 -> V_2 . V_278 , V_279 ) ;
F_158 ( & V_4 -> V_272 ) ;
F_158 ( & V_4 -> V_271 ) ;
return 0 ;
}
static int F_129 ( struct V_230 * V_234 )
{
return F_164 ( V_234 , 0 ) ;
}
static int F_166 ( void * V_283 )
{
struct V_3 * V_4 ;
int V_6 = 0 ;
V_4 = (struct V_3 * ) V_283 ;
F_11 ( V_4 , 2 , L_56 ) ;
if ( ! F_167 ( V_4 , V_111 ) )
return 0 ;
F_11 ( V_4 , 2 , L_57 ) ;
F_16 ( & V_4 -> V_50 -> V_2 ,
L_58 ) ;
F_168 ( V_4 ) ;
F_164 ( V_4 -> V_50 , 1 ) ;
V_6 = F_144 ( V_4 -> V_50 , 1 ) ;
if ( ! V_6 )
F_15 ( & V_4 -> V_50 -> V_2 ,
L_59 ) ;
else {
F_169 ( V_4 ) ;
F_16 ( & V_4 -> V_50 -> V_2 , L_60
L_61 ) ;
}
F_170 ( V_4 ) ;
F_171 ( V_4 , V_111 ) ;
F_172 ( V_4 , V_111 ) ;
return 0 ;
}
static int T_8 F_173 ( void )
{
F_174 ( L_62 ) ;
return 0 ;
}
static void T_9 F_175 ( void )
{
F_174 ( L_63 ) ;
}
static int F_176 ( struct V_230 * V_50 )
{
struct V_3 * V_4 = F_122 ( & V_50 -> V_2 ) ;
if ( V_4 -> V_2 )
F_177 ( V_4 -> V_2 ) ;
F_52 ( V_4 , 0 , 1 ) ;
F_128 ( V_4 -> V_235 , F_86 ( V_4 , 0xffffffff ) == 0 ) ;
if ( V_50 -> V_120 == V_284 )
return 0 ;
if ( V_4 -> V_120 == V_123 ) {
if ( V_4 -> V_46 . V_233 )
F_150 ( V_4 , V_282 ) ;
F_164 ( V_4 -> V_50 , 1 ) ;
} else
F_164 ( V_4 -> V_50 , 0 ) ;
return 0 ;
}
static int F_178 ( struct V_230 * V_50 )
{
struct V_3 * V_4 = F_122 ( & V_50 -> V_2 ) ;
int V_6 = 0 ;
if ( V_50 -> V_120 == V_284 )
goto V_161;
if ( V_4 -> V_120 == V_277 ) {
V_6 = F_144 ( V_4 -> V_50 , 1 ) ;
if ( V_6 ) {
F_54 () ;
F_55 ( V_4 -> V_2 ) ;
F_56 () ;
}
} else
V_6 = F_144 ( V_4 -> V_50 , 0 ) ;
V_161:
F_52 ( V_4 , 0xffffffff , 0 ) ;
if ( V_4 -> V_2 )
F_179 ( V_4 -> V_2 ) ;
if ( V_6 )
F_16 ( & V_4 -> V_50 -> V_2 , L_60
L_61 ) ;
return V_6 ;
}
static int F_180 ( struct V_3 * V_4 ,
struct V_35 * V_36 )
{
switch ( V_36 -> V_70 . V_103 ) {
case V_285 :
case V_286 :
if ( V_36 -> V_40 . V_175 . V_70 . V_287 ==
V_288 ) {
F_181 ( V_4 , V_36 ) ;
return 0 ;
} else
return 1 ;
case V_289 :
F_182 ( V_4 , V_36 ) ;
return 0 ;
default:
return 1 ;
}
}
static int F_183 ( struct V_3 * V_4 , int V_130 ,
struct V_37 * V_38 )
{
unsigned long V_5 ;
int V_6 = 0 ;
F_11 ( V_4 , 5 , L_64 ) ;
F_128 ( V_4 -> V_235 ,
F_184 ( & V_4 -> V_122 . V_290 , 0 , 1 ) == 0 ) ;
F_185 ( V_4 , V_130 , V_38 ) ;
F_11 ( V_4 , 6 , L_65 ) ;
F_186 ( F_187 ( V_4 -> V_122 . V_229 ) , V_5 ) ;
V_6 = F_188 ( V_4 -> V_122 . V_229 , & V_4 -> V_122 . V_291 ,
( V_292 ) V_38 , 0 , 0 ) ;
F_189 ( F_187 ( V_4 -> V_122 . V_229 ) , V_5 ) ;
if ( V_6 ) {
F_19 ( 2 , L_66
L_67 , V_6 ) ;
F_9 ( V_4 , 2 , L_68 , V_6 ) ;
F_190 ( V_38 -> V_293 , V_38 ) ;
F_191 ( & V_4 -> V_122 . V_290 , 0 ) ;
F_192 ( & V_4 -> V_235 ) ;
}
return V_6 ;
}
static int F_193 ( struct V_3 * V_4 ,
struct V_37 * V_38 , int V_85 )
{
T_4 V_294 , V_295 ;
F_11 ( V_4 , 4 , L_69 ) ;
F_194 ( V_4 , V_38 , V_296 ) ;
V_294 = ( T_4 ) ( V_41 + V_85 ) ;
V_295 = ( T_4 ) V_85 ;
memcpy ( F_195 ( V_38 -> V_40 ) , & V_294 , 2 ) ;
memcpy ( F_196 ( V_38 -> V_40 ) , & V_295 , 2 ) ;
memcpy ( F_197 ( V_38 -> V_40 ) , & V_295 , 2 ) ;
memcpy ( F_198 ( V_38 -> V_40 ) , & V_295 , 2 ) ;
return F_183 ( V_4 , V_294 , V_38 ) ;
}
int F_199 ( struct V_1 * V_2 , void * V_40 , int V_85 )
{
struct V_37 * V_38 ;
struct V_3 * V_4 ;
int V_6 ;
if ( ! V_2 )
return - V_228 ;
V_4 = V_2 -> V_109 ;
if ( ! V_4 )
return - V_228 ;
F_11 ( V_4 , 2 , L_70 ) ;
if ( ! F_200 ( V_4 ) )
return - V_228 ;
V_38 = F_201 ( & V_4 -> V_122 ) ;
memcpy ( V_38 -> V_40 + V_41 , V_40 , V_85 ) ;
V_6 = F_193 ( V_4 , V_38 , V_85 ) ;
return V_6 ;
}
int F_202 ( unsigned char * V_10 , struct V_1 * * V_2 ,
int (* F_203)( struct V_1 * , void * ) ,
int (* V_153)( struct V_63 * ) )
{
struct V_3 * V_4 ;
* V_2 = F_5 ( V_10 ) ;
if ( * V_2 == NULL )
return - V_228 ;
V_4 = ( * V_2 ) -> V_109 ;
if ( ! V_4 )
return - V_228 ;
F_11 ( V_4 , 2 , L_71 ) ;
if ( ( F_203 == NULL ) || ( V_153 == NULL ) )
return - V_171 ;
V_4 -> V_152 . F_203 = F_203 ;
V_4 -> V_152 . V_153 = V_153 ;
return 0 ;
}
void F_204 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( ! V_2 )
return;
V_4 = V_2 -> V_109 ;
if ( ! V_4 )
return;
F_11 ( V_4 , 2 , L_72 ) ;
V_4 -> V_152 . F_203 = NULL ;
V_4 -> V_152 . V_153 = NULL ;
return;
}
static void F_205 ( struct V_3 * V_4 ,
enum V_297 V_298 ,
T_5 V_299 , struct V_300 * V_301 , struct V_302 * V_303 )
{
char V_304 [ 7 ] [ 32 ] ;
char * V_305 [ 8 ] ;
int V_60 = 0 ;
switch ( V_298 ) {
case V_306 :
snprintf ( V_304 [ V_60 ] , sizeof( V_304 [ V_60 ] ) , L_73 ,
( V_299 & V_307 )
? L_74 : L_75 ) ;
V_305 [ V_60 ] = V_304 [ V_60 ] ; V_60 ++ ;
if ( V_299 & V_308 ) {
snprintf ( V_304 [ V_60 ] , sizeof( V_304 [ V_60 ] ) , L_76 ,
V_303 -> V_309 ) ;
V_305 [ V_60 ] = V_304 [ V_60 ] ; V_60 ++ ;
}
if ( V_299 & V_310 ) {
snprintf ( V_304 [ V_60 ] , sizeof( V_304 [ V_60 ] ) , L_77 ,
V_303 -> V_32 ) ;
V_305 [ V_60 ] = V_304 [ V_60 ] ; V_60 ++ ;
}
snprintf ( V_304 [ V_60 ] , sizeof( V_304 [ V_60 ] ) , L_78 ,
V_301 -> V_311 , V_301 -> V_312 , V_301 -> V_313 ) ;
V_305 [ V_60 ] = V_304 [ V_60 ] ; V_60 ++ ;
snprintf ( V_304 [ V_60 ] , sizeof( V_304 [ V_60 ] ) , L_79 , V_301 -> V_314 ) ;
V_305 [ V_60 ] = V_304 [ V_60 ] ; V_60 ++ ;
snprintf ( V_304 [ V_60 ] , sizeof( V_304 [ V_60 ] ) , L_80 ,
V_301 -> V_315 ) ;
V_305 [ V_60 ] = V_304 [ V_60 ] ; V_60 ++ ;
snprintf ( V_304 [ V_60 ] , sizeof( V_304 [ V_60 ] ) , L_81 , V_301 -> V_316 ) ;
V_305 [ V_60 ] = V_304 [ V_60 ] ; V_60 ++ ;
break;
case V_317 :
snprintf ( V_304 [ V_60 ] , sizeof( V_304 [ V_60 ] ) , L_82 ) ;
V_305 [ V_60 ] = V_304 [ V_60 ] ; V_60 ++ ;
break;
case V_318 :
snprintf ( V_304 [ V_60 ] , sizeof( V_304 [ V_60 ] ) , L_83 ) ;
V_305 [ V_60 ] = V_304 [ V_60 ] ; V_60 ++ ;
break;
}
V_305 [ V_60 ] = NULL ;
F_206 ( & V_4 -> V_50 -> V_2 . V_278 , V_279 , V_305 ) ;
}
static void F_207 ( struct V_319 * V_320 )
{
struct V_321 * V_40 =
F_208 ( V_320 , struct V_321 , V_322 ) ;
struct V_323 * V_324 = & V_40 -> V_325 . V_324 [ 0 ] ;
char V_326 [ 32 ] ;
char V_327 [ 32 ] ;
char V_328 [ 32 ] ;
char * V_305 [] = {
V_326 ,
V_327 ,
V_328 ,
NULL
} ;
F_145 ( & V_40 -> V_4 -> V_272 ) ;
V_40 -> V_4 -> V_80 . V_175 . V_174 = V_324 -> V_174 ;
F_158 ( & V_40 -> V_4 -> V_272 ) ;
snprintf ( V_326 , sizeof( V_326 ) , L_84 ) ;
snprintf ( V_327 , sizeof( V_327 ) , L_85 ,
( V_324 -> V_174 == V_183 ) ? L_86 :
( V_324 -> V_174 == V_181 ) ? L_87 :
( V_324 -> V_174 == V_182 ) ? L_88 :
L_89 ) ;
snprintf ( V_328 , sizeof( V_328 ) , L_90 ,
( V_324 -> V_120 == V_329 ) ? L_91 :
( V_324 -> V_120 == V_330 ) ? L_92 :
( V_324 -> V_120 == V_331 ) ? L_93 :
L_89 ) ;
F_206 ( & V_40 -> V_4 -> V_50 -> V_2 . V_278 ,
V_279 , V_305 ) ;
F_28 ( V_40 ) ;
}
static void F_181 ( struct V_3 * V_4 ,
struct V_35 * V_36 )
{
struct V_332 * V_325 =
& V_36 -> V_40 . V_175 . V_40 . V_333 ;
struct V_321 * V_40 ;
int V_334 ;
F_11 ( V_4 , 2 , L_94 ) ;
if ( V_325 -> V_335 != sizeof( struct V_323 ) ) {
F_9 ( V_4 , 2 , L_95 , V_325 -> V_335 ) ;
return;
}
V_334 = sizeof( struct V_323 ) * V_325 -> V_336 ;
V_40 = F_84 ( sizeof( struct V_321 ) + V_334 ,
V_112 ) ;
if ( ! V_40 ) {
F_11 ( V_4 , 2 , L_96 ) ;
return;
}
F_209 ( & V_40 -> V_322 , F_207 ) ;
V_40 -> V_4 = V_4 ;
memcpy ( & V_40 -> V_325 , V_325 ,
sizeof( struct V_332 ) + V_334 ) ;
F_210 ( V_337 , & V_40 -> V_322 ) ;
}
static void F_211 ( struct V_319 * V_320 )
{
struct V_338 * V_40 =
F_208 ( V_320 , struct V_338 , V_322 ) ;
int V_60 ;
if ( V_40 -> V_339 . V_340 ) {
F_15 ( & V_40 -> V_4 -> V_50 -> V_2 ,
L_97 ,
V_40 -> V_4 -> V_2 -> V_51 ,
( V_40 -> V_339 . V_340 == 0x01 )
? L_98
: ( V_40 -> V_339 . V_340 == 0x02 )
? L_99
: L_100 ) ;
F_145 ( & V_40 -> V_4 -> V_272 ) ;
V_40 -> V_4 -> V_80 . V_175 . V_341 = 0 ;
F_158 ( & V_40 -> V_4 -> V_272 ) ;
F_205 ( V_40 -> V_4 , V_317 ,
0 , NULL , NULL ) ;
} else
for ( V_60 = 0 ; V_60 < V_40 -> V_339 . V_336 ; V_60 ++ ) {
struct V_342 * V_324 =
& V_40 -> V_339 . V_324 [ V_60 ] ;
F_205 ( V_40 -> V_4 ,
V_306 ,
V_324 -> V_343 ,
& V_324 -> V_301 , & V_324 -> V_303 ) ;
}
F_28 ( V_40 ) ;
}
static void F_182 ( struct V_3 * V_4 ,
struct V_35 * V_36 )
{
struct V_344 * V_339 =
& V_36 -> V_40 . V_345 ;
struct V_338 * V_40 ;
int V_334 ;
F_11 ( V_4 , 2 , L_101 ) ;
if ( V_36 -> V_70 . V_101 != 0x0000 ) {
if ( V_36 -> V_70 . V_101 == 0x0010 ) {
if ( V_339 -> V_340 == 0x00 )
V_339 -> V_340 = 0xff ;
} else {
F_9 ( V_4 , 2 , L_102 ,
V_36 -> V_70 . V_101 ) ;
return;
}
}
V_334 = sizeof( struct V_342 ) *
V_339 -> V_336 ;
V_40 = F_84 ( sizeof( struct V_338 ) + V_334 ,
V_112 ) ;
if ( ! V_40 ) {
F_11 ( V_4 , 2 , L_103 ) ;
return;
}
F_209 ( & V_40 -> V_322 , F_211 ) ;
V_40 -> V_4 = V_4 ;
memcpy ( & V_40 -> V_339 , V_339 ,
sizeof( struct V_344 ) + V_334 ) ;
F_210 ( V_337 , & V_40 -> V_322 ) ;
}
static int F_212 ( struct V_3 * V_4 ,
struct V_346 * V_347 , enum V_348 V_349 )
{
int V_6 ;
int V_350 = ( V_4 -> V_46 . type == V_162 ) ;
if ( ( V_350 && ( V_347 -> V_351 == V_17 ) ) ||
( ! V_350 && ( V_347 -> V_351 == V_347 -> V_352 ) ) )
switch ( V_347 -> V_352 ) {
case V_17 :
V_6 = 0 ;
break;
case V_18 :
case V_353 :
V_6 = - V_19 ;
break;
case V_354 :
case V_355 :
V_6 = - V_228 ;
F_213 ( & V_4 -> V_50 -> V_2 ,
L_104 ) ;
break;
case V_356 :
case V_357 :
V_6 = - V_27 ;
F_213 ( & V_4 -> V_50 -> V_2 ,
L_105 ) ;
break;
case V_358 :
case V_359 :
switch ( V_349 ) {
case V_360 :
V_6 = - V_24 ;
F_213 ( & V_4 -> V_50 -> V_2 ,
L_106 ) ;
break;
case V_361 :
V_6 = - V_209 ;
F_213 ( & V_4 -> V_50 -> V_2 ,
L_107 ) ;
break;
default:
V_6 = - V_31 ;
}
break;
case V_362 :
case V_363 :
V_6 = - V_209 ;
F_213 ( & V_4 -> V_50 -> V_2 ,
L_108 ) ;
break;
case V_364 :
case V_365 :
V_6 = - V_24 ;
F_213 ( & V_4 -> V_50 -> V_2 ,
L_109 ) ;
break;
case V_366 :
case V_367 :
V_6 = - V_209 ;
F_213 ( & V_4 -> V_50 -> V_2 ,
L_107 ) ;
break;
case V_368 :
case V_369 :
V_6 = - V_370 ;
F_213 ( & V_4 -> V_50 -> V_2 ,
L_110 ) ;
break;
default:
V_6 = - V_31 ;
}
else
switch ( V_347 -> V_351 ) {
case V_371 :
V_6 = - V_19 ;
break;
case V_353 :
V_6 = - V_19 ;
break;
default:
V_6 = - V_31 ;
}
if ( V_6 ) {
F_9 ( V_4 , 2 , L_111 , V_347 -> V_351 ) ;
F_9 ( V_4 , 2 , L_112 , V_347 -> V_352 ) ;
}
return V_6 ;
}
static struct V_37 * F_214 ( struct V_3 * V_4 ,
enum V_348 V_372 ,
unsigned int V_373 )
{
enum V_33 V_374 = ( V_4 -> V_46 . type == V_162 ) ?
V_286 :
V_285 ;
struct V_37 * V_38 ;
struct V_35 * V_36 ;
V_38 = F_12 ( V_4 , V_374 , 0 ) ;
if ( ! V_38 )
return V_38 ;
V_36 = (struct V_35 * ) ( V_38 -> V_40 + V_41 ) ;
V_36 -> V_40 . V_175 . V_70 . V_375 = sizeof( struct V_376 ) +
V_373 ;
V_36 -> V_40 . V_175 . V_70 . V_287 = V_372 ;
V_36 -> V_40 . V_175 . V_70 . V_377 = 1 ;
V_36 -> V_40 . V_175 . V_70 . V_378 = 1 ;
return V_38 ;
}
static int F_215 ( struct V_3 * V_4 ,
struct V_99 * V_100 , unsigned long V_40 )
{
struct V_35 * V_36 = (struct V_35 * ) V_40 ;
struct V_346 * V_347 = (struct V_346 * ) V_100 -> V_379 ;
F_11 ( V_4 , 2 , L_113 ) ;
V_347 -> V_351 = V_36 -> V_70 . V_101 ;
V_347 -> V_352 = V_36 -> V_40 . V_175 . V_70 . V_101 ;
if ( ( V_347 -> V_351 == 0 ) && ( V_347 -> V_352 == 0 ) ) {
V_347 -> V_40 . V_380 =
V_36 -> V_40 . V_175 . V_40 . V_381 . V_382 ;
} else {
V_347 -> V_40 . V_380 = 0 ;
}
return 0 ;
}
static void F_147 ( struct V_3 * V_4 )
{
struct V_37 * V_38 ;
struct V_346 V_347 ;
F_11 ( V_4 , 2 , L_114 ) ;
V_38 = F_214 ( V_4 , V_383 ,
sizeof( struct V_384 ) ) ;
if ( ! V_38 )
return;
if ( F_13 ( V_4 , V_38 , F_215 ,
( void * ) & V_347 ) ||
F_212 ( V_4 , & V_347 ,
V_383 ) ) {
V_4 -> V_80 . V_175 . V_174 = V_183 ;
return;
}
V_4 -> V_80 . V_175 . V_268 = V_347 . V_40 . V_380 ;
}
static int F_216 ( struct V_3 * V_4 ,
struct V_99 * V_100 , unsigned long V_40 )
{
struct V_35 * V_36 = (struct V_35 * ) V_40 ;
struct V_385 * V_325 = & V_36 -> V_40 . V_175 . V_40 . V_386 ;
struct V_346 * V_347 = (struct V_346 * ) V_100 -> V_379 ;
F_11 ( V_4 , 2 , L_115 ) ;
V_347 -> V_351 = V_36 -> V_70 . V_101 ;
V_347 -> V_352 = V_36 -> V_40 . V_175 . V_70 . V_101 ;
if ( ( V_347 -> V_351 != 0 ) || ( V_347 -> V_352 != 0 ) )
return 0 ;
if ( V_325 -> V_335 != sizeof( struct V_323 ) ) {
V_347 -> V_352 = 0xffff ;
F_9 ( V_4 , 2 , L_116 , V_325 -> V_335 ) ;
return 0 ;
}
if ( V_325 -> V_336 > 0 ) {
if ( V_347 -> V_40 . V_325 . V_174 )
* V_347 -> V_40 . V_325 . V_174 = V_325 -> V_324 [ 0 ] . V_174 ;
if ( V_347 -> V_40 . V_325 . V_120 )
* V_347 -> V_40 . V_325 . V_120 = V_325 -> V_324 [ 0 ] . V_120 ;
}
return 0 ;
}
int F_217 ( struct V_3 * V_4 ,
enum V_387 * V_174 , enum V_388 * V_120 )
{
int V_6 = 0 ;
struct V_37 * V_38 ;
struct V_346 V_347 = {
. V_40 = {
. V_325 = {
. V_174 = V_174 ,
. V_120 = V_120 ,
} ,
} ,
} ;
F_11 ( V_4 , 2 , L_117 ) ;
if ( ! ( V_4 -> V_80 . V_175 . V_268 & V_389 ) )
return - V_19 ;
V_38 = F_214 ( V_4 , V_389 , 0 ) ;
if ( ! V_38 )
return - V_30 ;
V_6 = F_13 ( V_4 , V_38 , F_216 ,
( void * ) & V_347 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_212 ( V_4 , & V_347 , V_389 ) ;
}
static int F_218 ( struct V_3 * V_4 ,
struct V_99 * V_100 , unsigned long V_40 )
{
struct V_35 * V_36 = (struct V_35 * ) V_40 ;
struct V_346 * V_347 = (struct V_346 * ) V_100 -> V_379 ;
F_11 ( V_4 , 2 , L_118 ) ;
V_347 -> V_351 = V_36 -> V_70 . V_101 ;
V_347 -> V_352 = V_36 -> V_40 . V_175 . V_70 . V_101 ;
return 0 ;
}
int F_80 ( struct V_3 * V_4 , enum V_387 V_174 )
{
int V_6 = 0 ;
int V_375 ;
struct V_37 * V_38 ;
struct V_346 V_347 ;
enum V_348 V_349 ;
F_11 ( V_4 , 2 , L_119 ) ;
switch ( V_174 ) {
case V_183 :
V_349 = V_390 ;
V_375 = sizeof( struct V_391 ) ;
break;
case V_181 :
V_349 = V_360 ;
V_375 = sizeof( struct V_392 ) ;
break;
case V_182 :
V_349 = V_361 ;
V_375 = sizeof( struct V_393 ) ;
break;
default:
return - V_171 ;
}
if ( ! ( V_4 -> V_80 . V_175 . V_268 & V_349 ) )
return - V_19 ;
V_38 = F_214 ( V_4 , V_349 , V_375 ) ;
if ( ! V_38 )
return - V_30 ;
V_6 = F_13 ( V_4 , V_38 , F_218 ,
( void * ) & V_347 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_212 ( V_4 , & V_347 , V_349 ) ;
}
static int F_219 ( struct V_3 * V_4 , int V_394 , T_4 V_395 )
{
int V_6 ;
if ( V_394 == 0 )
switch ( V_395 ) {
case 0x0001 :
V_6 = 0 ;
break;
case 0x0004 :
case 0x0100 :
case 0x0106 :
V_6 = - V_19 ;
F_213 ( & V_4 -> V_50 -> V_2 ,
L_120 ) ;
break;
case 0x0107 :
V_6 = - V_396 ;
break;
default:
V_6 = - V_31 ;
}
else
V_6 = - V_31 ;
if ( V_6 ) {
F_9 ( V_4 , 2 , L_121 , V_394 ) ;
F_9 ( V_4 , 2 , L_122 , V_395 ) ;
}
return V_6 ;
}
static void F_220 ( void * V_397 ,
enum V_398 type , void * V_324 )
{
struct V_3 * V_4 = (struct V_3 * ) V_397 ;
struct V_399 * V_400 ;
T_5 V_299 ;
if ( type != V_401 ) {
F_63 ( 1 ) ;
return;
}
V_400 = (struct V_399 * ) V_324 ;
V_299 = V_310 ;
if ( V_400 -> V_303 . V_309 )
V_299 |= V_308 ;
F_205 ( V_4 , V_306 , V_299 ,
(struct V_300 * ) & V_400 -> V_402 ,
(struct V_302 * ) & V_400 -> V_303 ) ;
}
int F_221 ( struct V_3 * V_4 , int V_403 )
{
int V_6 ;
T_4 V_395 ;
struct V_404 * V_405 ;
struct V_406 V_407 ;
if ( ! V_4 )
return - V_171 ;
if ( ! V_4 -> V_80 . V_175 . V_268 )
return - V_19 ;
V_405 = F_160 ( V_4 ) ;
F_222 ( V_405 , & V_407 ) ;
if ( V_403 ) {
F_205 ( V_4 , V_318 , 0 , NULL , NULL ) ;
V_6 = F_223 ( V_407 , 1 , & V_395 ,
F_220 , V_4 ) ;
} else
V_6 = F_223 ( V_407 , 0 , & V_395 , NULL , NULL ) ;
return F_219 ( V_4 , V_6 , V_395 ) ;
}
