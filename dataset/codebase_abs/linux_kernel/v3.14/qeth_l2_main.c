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
static int F_14 ( struct V_6 * V_7 ,
struct V_45 * V_46 ,
unsigned long V_47 )
{
struct V_48 * V_5 ;
T_2 * V_49 ;
F_15 ( V_7 , 2 , L_2 ) ;
V_5 = (struct V_48 * ) V_47 ;
V_49 = & V_5 -> V_47 . V_50 . V_49 [ 0 ] ;
if ( V_5 -> V_51 . V_52 == V_53 ) {
F_16 ( 2 , L_3 ,
V_49 , F_17 ( V_7 ) ) ;
V_5 -> V_51 . V_52 = 0 ;
}
if ( V_5 -> V_51 . V_52 )
F_16 ( 2 , L_4 ,
V_49 , F_17 ( V_7 ) , V_5 -> V_51 . V_52 ) ;
return 0 ;
}
static int F_18 ( struct V_6 * V_7 , T_2 * V_49 )
{
F_15 ( V_7 , 2 , L_5 ) ;
return F_19 ( V_7 , V_49 , V_54 ,
F_14 ) ;
}
static int F_20 ( struct V_6 * V_7 ,
struct V_45 * V_46 ,
unsigned long V_47 )
{
struct V_48 * V_5 ;
T_2 * V_49 ;
F_15 ( V_7 , 2 , L_6 ) ;
V_5 = (struct V_48 * ) V_47 ;
V_49 = & V_5 -> V_47 . V_50 . V_49 [ 0 ] ;
if ( V_5 -> V_51 . V_52 )
F_16 ( 2 , L_7 ,
V_49 , F_17 ( V_7 ) , V_5 -> V_51 . V_52 ) ;
return 0 ;
}
static int F_21 ( struct V_6 * V_7 , T_2 * V_49 )
{
F_15 ( V_7 , 2 , L_8 ) ;
return F_19 ( V_7 , V_49 , V_55 ,
F_20 ) ;
}
static void F_22 ( struct V_6 * V_7 , T_2 * V_49 , int V_56 )
{
struct V_57 * V_58 ;
int V_11 ;
V_58 = F_23 ( sizeof( struct V_57 ) , V_59 ) ;
if ( ! V_58 )
return;
memcpy ( V_58 -> V_60 , V_49 , V_61 ) ;
V_58 -> V_62 = V_61 ;
V_58 -> V_63 = V_56 ;
if ( V_56 ) {
V_11 = F_19 ( V_7 , V_49 , V_64 ,
NULL ) ;
} else {
V_11 = F_18 ( V_7 , V_49 ) ;
}
if ( ! V_11 )
F_24 ( & V_58 -> V_65 , & V_7 -> V_66 ) ;
else
F_25 ( V_58 ) ;
}
static void F_26 ( struct V_6 * V_7 , int V_67 )
{
struct V_57 * V_58 , * V_68 ;
F_27 ( & V_7 -> V_69 ) ;
F_28 (mc, tmp, &card->mc_list, list) {
if ( V_67 ) {
if ( V_58 -> V_63 )
F_19 ( V_7 , V_58 -> V_60 ,
V_70 , NULL ) ;
else
F_21 ( V_7 , V_58 -> V_60 ) ;
}
F_29 ( & V_58 -> V_65 ) ;
F_25 ( V_58 ) ;
}
F_30 ( & V_7 -> V_69 ) ;
}
static inline int F_31 ( struct V_6 * V_7 ,
struct V_71 * V_72 )
{
if ( V_7 -> V_16 . type == V_17 )
return V_73 ;
if ( F_32 ( V_72 -> V_47 ) )
return V_74 ;
if ( F_33 ( V_72 -> V_47 ) )
return V_75 ;
return V_73 ;
}
static void F_34 ( struct V_6 * V_7 , struct V_76 * V_51 ,
struct V_71 * V_72 , int V_77 , int V_78 )
{
struct V_79 * V_80 = (struct V_79 * ) F_35 ( V_72 ) ;
memset ( V_51 , 0 , sizeof( struct V_76 ) ) ;
V_51 -> V_51 . V_81 . V_82 = V_83 ;
if ( V_78 == V_75 )
V_51 -> V_51 . V_81 . V_35 [ 2 ] |= V_84 ;
else if ( V_78 == V_74 )
V_51 -> V_51 . V_81 . V_35 [ 2 ] |= V_85 ;
else
V_51 -> V_51 . V_81 . V_35 [ 2 ] |= V_86 ;
V_51 -> V_51 . V_81 . V_87 = V_72 -> V_88 - V_89 ;
if ( V_80 -> V_90 == F_36 ( V_91 ) ) {
V_51 -> V_51 . V_81 . V_35 [ 2 ] |= V_92 ;
V_51 -> V_51 . V_81 . V_93 = F_37 ( V_80 -> V_94 ) ;
}
}
static int F_38 ( struct V_6 * V_7 ,
struct V_45 * V_46 , unsigned long V_47 )
{
struct V_48 * V_5 ;
F_15 ( V_7 , 2 , L_9 ) ;
V_5 = (struct V_48 * ) V_47 ;
if ( V_5 -> V_51 . V_52 ) {
F_16 ( 2 , L_10
L_11 , V_5 -> V_47 . V_95 . V_93 ,
F_17 ( V_7 ) , V_5 -> V_51 . V_52 ) ;
F_6 ( V_7 , 2 , L_12 , V_5 -> V_51 . V_96 ) ;
F_6 ( V_7 , 2 , L_13 , V_5 -> V_51 . V_52 ) ;
}
return 0 ;
}
static int F_39 ( struct V_6 * V_7 , T_1 V_97 ,
enum V_98 V_99 )
{
struct V_48 * V_5 ;
struct V_100 * V_101 ;
F_6 ( V_7 , 4 , L_14 , V_99 ) ;
V_101 = F_40 ( V_7 , V_99 , V_102 ) ;
V_5 = (struct V_48 * ) ( V_101 -> V_47 + V_103 ) ;
V_5 -> V_47 . V_95 . V_93 = V_97 ;
return F_41 ( V_7 , V_101 ,
F_38 , NULL ) ;
}
static void F_42 ( struct V_6 * V_7 )
{
struct V_104 * V_82 ;
F_15 ( V_7 , 3 , L_15 ) ;
F_27 ( & V_7 -> V_105 ) ;
F_9 (id, &card->vid_list, list) {
F_39 ( V_7 , V_82 -> V_106 , V_107 ) ;
}
F_30 ( & V_7 -> V_105 ) ;
}
static int F_43 ( struct V_1 * V_2 ,
T_3 V_108 , T_4 V_106 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_104 * V_82 ;
F_6 ( V_7 , 4 , L_16 , V_106 ) ;
if ( ! V_106 )
return 0 ;
if ( V_7 -> V_16 . type == V_24 ) {
F_15 ( V_7 , 3 , L_17 ) ;
return 0 ;
}
if ( F_44 ( V_7 , V_109 ) ) {
F_15 ( V_7 , 3 , L_18 ) ;
return 0 ;
}
V_82 = F_23 ( sizeof( struct V_104 ) , V_59 ) ;
if ( V_82 ) {
V_82 -> V_106 = V_106 ;
F_39 ( V_7 , V_106 , V_107 ) ;
F_27 ( & V_7 -> V_105 ) ;
F_24 ( & V_82 -> V_65 , & V_7 -> V_110 ) ;
F_30 ( & V_7 -> V_105 ) ;
} else {
return - V_111 ;
}
return 0 ;
}
static int F_45 ( struct V_1 * V_2 ,
T_3 V_108 , T_4 V_106 )
{
struct V_104 * V_82 , * V_112 = NULL ;
struct V_6 * V_7 = V_2 -> V_8 ;
F_6 ( V_7 , 4 , L_19 , V_106 ) ;
if ( V_7 -> V_16 . type == V_24 ) {
F_15 ( V_7 , 3 , L_20 ) ;
return 0 ;
}
if ( F_44 ( V_7 , V_109 ) ) {
F_15 ( V_7 , 3 , L_21 ) ;
return 0 ;
}
F_27 ( & V_7 -> V_105 ) ;
F_9 (id, &card->vid_list, list) {
if ( V_82 -> V_106 == V_106 ) {
F_29 ( & V_82 -> V_65 ) ;
V_112 = V_82 ;
break;
}
}
F_30 ( & V_7 -> V_105 ) ;
if ( V_112 ) {
F_39 ( V_7 , V_106 , V_113 ) ;
F_25 ( V_112 ) ;
}
F_46 ( V_7 -> V_2 ) ;
return 0 ;
}
static int F_47 ( struct V_6 * V_7 , int V_114 )
{
int V_11 = 0 ;
F_48 ( V_115 , 2 , L_22 ) ;
F_49 ( V_115 , 2 , & V_7 , sizeof( void * ) ) ;
F_50 ( V_7 , 0 , 1 ) ;
if ( V_7 -> V_116 . V_13 == V_117 &&
V_7 -> V_118 . V_13 == V_117 &&
( V_7 -> V_13 == V_14 ) ) {
if ( V_114 &&
V_7 -> V_16 . type != V_17 ) {
F_51 ( V_7 -> V_2 ) ;
} else {
F_52 () ;
F_53 ( V_7 -> V_2 ) ;
F_54 () ;
}
V_7 -> V_16 . V_119 &= ~ V_120 ;
V_7 -> V_13 = V_15 ;
}
if ( V_7 -> V_13 == V_15 ) {
F_26 ( V_7 , 0 ) ;
F_55 ( V_7 ) ;
V_7 -> V_13 = V_121 ;
}
if ( V_7 -> V_13 == V_121 ) {
F_56 ( V_7 , 0 ) ;
F_57 ( V_7 ) ;
F_58 ( V_7 ) ;
V_7 -> V_13 = V_122 ;
}
if ( V_7 -> V_13 == V_122 ) {
F_59 ( & V_7 -> V_116 ) ;
F_59 ( & V_7 -> V_118 ) ;
}
return V_11 ;
}
static int F_60 ( struct V_6 * V_7 ,
int V_123 , int * V_124 )
{
int V_125 = 0 ;
struct V_71 * V_72 ;
struct V_76 * V_51 ;
unsigned int V_88 ;
* V_124 = 0 ;
F_61 ( ! V_123 ) ;
while ( V_123 ) {
V_72 = F_62 ( V_7 ,
& V_7 -> V_126 . V_127 -> V_128 [ V_7 -> V_129 . V_130 ] ,
& V_7 -> V_129 . V_131 , & V_7 -> V_129 . V_132 , & V_51 ) ;
if ( ! V_72 ) {
* V_124 = 1 ;
break;
}
V_72 -> V_2 = V_7 -> V_2 ;
switch ( V_51 -> V_51 . V_81 . V_82 ) {
case V_83 :
V_72 -> V_133 = V_134 ;
V_72 -> V_135 = F_63 ( V_72 , V_72 -> V_2 ) ;
V_72 -> V_136 = V_137 ;
if ( V_72 -> V_135 == F_64 ( V_138 ) )
* ( ( V_139 * ) V_72 -> V_140 ) = ++ V_7 -> V_141 . V_142 ;
V_88 = V_72 -> V_88 ;
F_65 ( V_72 ) ;
break;
case V_143 :
if ( V_7 -> V_16 . type == V_17 ) {
F_66 ( V_72 , sizeof( struct V_76 ) ) ;
F_67 ( V_72 , V_51 ,
sizeof( struct V_76 ) ) ;
V_88 = V_72 -> V_88 ;
V_7 -> V_144 . V_145 ( V_72 ) ;
break;
}
default:
F_68 ( V_72 ) ;
F_15 ( V_7 , 3 , L_23 ) ;
F_49 ( V_146 , 3 , V_51 , V_147 ) ;
continue;
}
V_125 ++ ;
V_123 -- ;
V_7 -> V_148 . V_149 ++ ;
V_7 -> V_148 . V_150 += V_88 ;
}
return V_125 ;
}
static int F_69 ( struct V_151 * V_152 , int V_123 )
{
struct V_6 * V_7 = F_70 ( V_152 , struct V_6 , V_152 ) ;
int V_125 = 0 ;
struct V_153 * V_154 ;
int V_124 ;
int V_155 = V_123 ;
if ( V_7 -> V_156 . V_157 ) {
V_7 -> V_158 . V_159 ++ ;
V_7 -> V_158 . V_160 = F_71 () ;
}
while ( 1 ) {
if ( ! V_7 -> V_129 . V_161 ) {
V_7 -> V_129 . V_162 = 0 ;
V_7 -> V_129 . V_161 = F_72 (
V_7 -> V_47 . V_163 , 0 , & V_7 -> V_129 . V_130 ,
& V_7 -> V_129 . V_162 ) ;
if ( V_7 -> V_129 . V_161 <= 0 ) {
V_7 -> V_129 . V_161 = 0 ;
break;
}
V_7 -> V_129 . V_131 =
& V_7 -> V_126 . V_127 -> V_128 [ V_7 -> V_129 . V_130 ]
. V_154 -> V_164 [ 0 ] ;
V_7 -> V_129 . V_132 = 0 ;
}
while ( V_7 -> V_129 . V_161 ) {
V_154 = & V_7 -> V_126 . V_127 -> V_128 [ V_7 -> V_129 . V_130 ] ;
if ( ! ( V_7 -> V_129 . V_162 &&
F_73 ( V_7 , V_154 -> V_154 ,
V_7 -> V_129 . V_162 , L_24 ) ) )
V_125 += F_60 (
V_7 , V_155 , & V_124 ) ;
else
V_124 = 1 ;
if ( V_124 ) {
if ( V_7 -> V_156 . V_157 )
V_7 -> V_158 . V_165 ++ ;
F_74 ( V_7 ,
V_154 -> V_166 ) ;
F_75 ( V_7 , V_7 -> V_129 . V_130 ) ;
V_7 -> V_129 . V_161 -- ;
if ( V_7 -> V_129 . V_161 ) {
V_7 -> V_129 . V_130 =
( V_7 -> V_129 . V_130 + 1 ) %
V_167 ;
V_7 -> V_129 . V_131 =
& V_7 -> V_126 . V_127
-> V_128 [ V_7 -> V_129 . V_130 ]
. V_154 -> V_164 [ 0 ] ;
V_7 -> V_129 . V_132 = 0 ;
}
}
if ( V_125 >= V_123 )
goto V_168;
else
V_155 = V_123 - V_125 ;
}
}
F_76 ( V_152 ) ;
if ( F_77 ( V_7 -> V_47 . V_163 , 0 ) )
F_78 ( & V_7 -> V_152 ) ;
V_168:
if ( V_7 -> V_156 . V_157 )
V_7 -> V_158 . V_169 += F_71 () -
V_7 -> V_158 . V_160 ;
return V_125 ;
}
static int F_19 ( struct V_6 * V_7 , T_2 * V_49 ,
enum V_98 V_99 ,
int (* F_79) ( struct V_6 * ,
struct V_45 * ,
unsigned long ) )
{
struct V_48 * V_5 ;
struct V_100 * V_101 ;
F_15 ( V_7 , 2 , L_25 ) ;
V_101 = F_40 ( V_7 , V_99 , V_102 ) ;
V_5 = (struct V_48 * ) ( V_101 -> V_47 + V_103 ) ;
V_5 -> V_47 . V_50 . V_170 = V_61 ;
memcpy ( & V_5 -> V_47 . V_50 . V_49 , V_49 , V_61 ) ;
return F_41 ( V_7 , V_101 , F_79 , NULL ) ;
}
static int F_80 ( struct V_6 * V_7 ,
struct V_45 * V_46 ,
unsigned long V_47 )
{
struct V_48 * V_5 ;
F_15 ( V_7 , 2 , L_26 ) ;
V_5 = (struct V_48 * ) V_47 ;
if ( V_5 -> V_51 . V_52 ) {
F_6 ( V_7 , 2 , L_27 , V_5 -> V_51 . V_52 ) ;
V_7 -> V_16 . V_119 &= ~ V_120 ;
switch ( V_5 -> V_51 . V_52 ) {
case V_53 :
case V_171 :
F_81 ( & V_7 -> V_172 -> V_2 ,
L_28 ,
V_5 -> V_47 . V_50 . V_49 ) ;
break;
case V_173 :
case V_174 :
F_81 ( & V_7 -> V_172 -> V_2 ,
L_29 ,
V_5 -> V_47 . V_50 . V_49 ) ;
break;
default:
break;
}
} else {
V_7 -> V_16 . V_119 |= V_120 ;
memcpy ( V_7 -> V_2 -> V_175 , V_5 -> V_47 . V_50 . V_49 ,
V_61 ) ;
F_82 ( & V_7 -> V_172 -> V_2 ,
L_30 ,
V_7 -> V_2 -> V_175 , V_7 -> V_2 -> V_176 ) ;
}
return 0 ;
}
static int F_83 ( struct V_6 * V_7 , T_2 * V_49 )
{
F_15 ( V_7 , 2 , L_31 ) ;
return F_19 ( V_7 , V_49 , V_64 ,
F_80 ) ;
}
static int F_84 ( struct V_6 * V_7 ,
struct V_45 * V_46 ,
unsigned long V_47 )
{
struct V_48 * V_5 ;
F_15 ( V_7 , 2 , L_32 ) ;
V_5 = (struct V_48 * ) V_47 ;
if ( V_5 -> V_51 . V_52 ) {
F_6 ( V_7 , 2 , L_13 , V_5 -> V_51 . V_52 ) ;
return 0 ;
}
V_7 -> V_16 . V_119 &= ~ V_120 ;
return 0 ;
}
static int F_85 ( struct V_6 * V_7 , T_2 * V_49 )
{
F_15 ( V_7 , 2 , L_33 ) ;
if ( ! ( V_7 -> V_16 . V_119 & V_120 ) )
return 0 ;
return F_19 ( V_7 , V_49 , V_70 ,
F_84 ) ;
}
static int F_86 ( struct V_6 * V_7 )
{
int V_11 = 0 ;
char V_177 [] = { 0x02 , 0x00 , 0x00 } ;
F_48 ( V_115 , 2 , L_34 ) ;
F_87 ( V_115 , 2 , L_35 , F_88 ( V_7 ) ) ;
if ( F_89 ( V_7 , V_178 ) ) {
V_11 = F_90 ( V_7 ) ;
if ( V_11 ) {
F_16 ( 2 , L_36
L_37 ,
F_88 ( V_7 ) , V_11 ) ;
}
}
if ( V_7 -> V_16 . type == V_179 ||
V_7 -> V_16 . type == V_24 ||
V_7 -> V_16 . type == V_25 ||
V_7 -> V_16 . V_26 ) {
V_11 = F_91 ( V_7 ) ;
if ( V_11 ) {
F_16 ( 2 , L_38
L_39 , F_88 ( V_7 ) , V_11 ) ;
F_87 ( V_115 , 2 , L_40 , V_11 ) ;
return V_11 ;
}
F_49 ( V_115 , 2 , V_7 -> V_2 -> V_175 , V_61 ) ;
} else {
F_92 ( V_7 -> V_2 -> V_175 ) ;
memcpy ( V_7 -> V_2 -> V_175 , V_177 , 3 ) ;
}
return 0 ;
}
static int F_93 ( struct V_1 * V_2 , void * V_180 )
{
struct V_181 * V_182 = V_180 ;
struct V_6 * V_7 = V_2 -> V_8 ;
int V_11 = 0 ;
F_15 ( V_7 , 3 , L_41 ) ;
if ( F_7 ( V_2 ) != V_38 ) {
F_15 ( V_7 , 3 , L_42 ) ;
return - V_34 ;
}
if ( V_7 -> V_16 . type == V_17 ||
V_7 -> V_16 . type == V_24 ||
V_7 -> V_16 . type == V_25 ) {
F_15 ( V_7 , 3 , L_43 ) ;
return - V_34 ;
}
F_94 ( V_7 , 3 , V_182 -> V_183 , V_61 ) ;
if ( F_44 ( V_7 , V_109 ) ) {
F_15 ( V_7 , 3 , L_44 ) ;
return - V_184 ;
}
V_11 = F_85 ( V_7 , & V_7 -> V_2 -> V_175 [ 0 ] ) ;
if ( ! V_11 || ( V_11 == V_185 ) )
V_11 = F_83 ( V_7 , V_182 -> V_183 ) ;
return V_11 ? - V_30 : 0 ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_186 * V_187 ;
if ( V_7 -> V_16 . type == V_17 )
return ;
F_15 ( V_7 , 3 , L_45 ) ;
if ( F_95 ( V_7 , V_109 ) &&
( V_7 -> V_13 != V_14 ) )
return;
F_26 ( V_7 , 1 ) ;
F_27 ( & V_7 -> V_69 ) ;
F_96 (ha, dev)
F_22 ( V_7 , V_187 -> V_182 , 0 ) ;
F_97 (ha, dev)
F_22 ( V_7 , V_187 -> V_182 , 1 ) ;
F_30 ( & V_7 -> V_69 ) ;
if ( ! F_98 ( V_7 , V_188 ) )
return;
F_99 ( V_7 ) ;
}
static int F_100 ( struct V_71 * V_72 , struct V_1 * V_2 )
{
int V_11 ;
struct V_76 * V_51 = NULL ;
int V_189 = 0 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_71 * V_190 = V_72 ;
int V_77 = F_101 ( V_72 ) ;
int V_78 = F_31 ( V_7 , V_72 ) ;
struct V_191 * V_192 = V_7 -> V_126 . V_193
[ F_102 ( V_7 , V_72 , V_77 , V_78 ) ] ;
int V_194 = V_72 -> V_88 ;
int V_195 = - 1 ;
int V_196 = 0 ;
int V_197 = 0 ;
if ( ( V_7 -> V_13 != V_14 ) || ! V_7 -> V_198 ) {
V_7 -> V_148 . V_199 ++ ;
goto V_200;
}
if ( ( V_7 -> V_16 . type == V_17 ) &&
( V_72 -> V_135 == F_64 ( V_201 ) ) )
goto V_200;
if ( V_7 -> V_156 . V_157 ) {
V_7 -> V_158 . V_202 ++ ;
V_7 -> V_158 . V_203 = F_71 () ;
}
F_103 ( V_2 ) ;
if ( V_7 -> V_16 . type == V_17 )
V_51 = (struct V_76 * ) V_72 -> V_47 ;
else {
if ( V_7 -> V_16 . type == V_179 ) {
V_190 = V_72 ;
V_195 = V_204 ;
V_197 = V_204 ;
V_51 = F_104 ( V_205 ,
V_59 ) ;
if ( ! V_51 )
goto V_200;
V_196 ++ ;
F_105 ( V_190 ) ;
F_34 ( V_7 , V_51 , V_190 , V_77 , V_78 ) ;
V_51 -> V_51 . V_81 . V_87 = V_190 -> V_88 ;
memcpy ( ( ( char * ) V_51 ) + sizeof( struct V_76 ) ,
F_35 ( V_190 ) , V_204 ) ;
} else {
V_190 = F_106 ( V_72 ,
sizeof( struct V_76 ) ) ;
if ( ! V_190 )
goto V_200;
V_51 = (struct V_76 * ) F_66 ( V_190 ,
sizeof( struct V_76 ) ) ;
F_107 ( V_190 , sizeof( struct V_76 ) ) ;
F_34 ( V_7 , V_51 , V_190 , V_77 , V_78 ) ;
}
}
V_189 = F_108 ( V_7 , V_190 , V_196 ) ;
if ( ! V_189 ) {
if ( V_195 >= 0 )
F_109 ( V_205 , V_51 ) ;
goto V_200;
}
if ( V_7 -> V_16 . type != V_179 ) {
if ( F_110 ( V_190 , & V_51 ,
sizeof( struct V_206 ) ) )
goto V_200;
V_11 = F_111 ( V_7 , V_192 , V_190 , V_51 ,
V_189 ) ;
} else
V_11 = F_112 ( V_7 , V_192 , V_190 , V_51 ,
V_189 , V_195 , V_197 ) ;
if ( ! V_11 ) {
V_7 -> V_148 . V_207 ++ ;
V_7 -> V_148 . V_194 += V_194 ;
if ( V_190 != V_72 )
F_68 ( V_72 ) ;
V_11 = V_208 ;
} else {
if ( V_195 >= 0 )
F_109 ( V_205 , V_51 ) ;
if ( V_11 == - V_209 ) {
if ( V_190 != V_72 )
F_68 ( V_190 ) ;
return V_210 ;
} else
goto V_200;
}
F_113 ( V_2 ) ;
if ( V_7 -> V_156 . V_157 )
V_7 -> V_158 . V_211 += F_71 () -
V_7 -> V_158 . V_203 ;
return V_11 ;
V_200:
V_7 -> V_148 . V_212 ++ ;
V_7 -> V_148 . V_213 ++ ;
if ( ( V_190 != V_72 ) && V_190 )
F_68 ( V_190 ) ;
F_68 ( V_72 ) ;
F_113 ( V_2 ) ;
return V_208 ;
}
static int F_114 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_11 = 0 ;
F_15 ( V_7 , 4 , L_46 ) ;
if ( V_7 -> V_13 == V_14 )
return V_11 ;
if ( V_7 -> V_13 != V_15 )
return - V_12 ;
if ( ( V_7 -> V_16 . type != V_17 ) &&
( ! ( V_7 -> V_16 . V_119 & V_120 ) ) ) {
F_15 ( V_7 , 4 , L_47 ) ;
return - V_18 ;
}
V_7 -> V_47 . V_13 = V_117 ;
V_7 -> V_13 = V_14 ;
F_115 ( V_2 ) ;
if ( F_116 ( V_7 -> V_47 . V_163 , 0 ) >= 0 ) {
F_117 ( & V_7 -> V_152 ) ;
F_78 ( & V_7 -> V_152 ) ;
} else
V_11 = - V_214 ;
return V_11 ;
}
static int F_118 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_15 ( V_7 , 5 , L_48 ) ;
if ( F_44 ( V_7 , V_109 ) ) {
F_15 ( V_7 , 3 , L_49 ) ;
return - V_184 ;
}
return F_114 ( V_2 ) ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_15 ( V_7 , 4 , L_50 ) ;
F_119 ( V_2 ) ;
if ( V_7 -> V_13 == V_14 ) {
V_7 -> V_13 = V_15 ;
F_120 ( & V_7 -> V_152 ) ;
}
return 0 ;
}
static int F_121 ( struct V_215 * V_172 )
{
struct V_6 * V_7 = F_122 ( & V_172 -> V_2 ) ;
F_123 ( & V_172 -> V_2 ) ;
F_124 ( & V_7 -> V_110 ) ;
F_124 ( & V_7 -> V_66 ) ;
V_7 -> V_156 . V_216 = 1 ;
V_7 -> V_16 . V_217 = 0 ;
return 0 ;
}
static void F_125 ( struct V_215 * V_218 )
{
struct V_6 * V_7 = F_122 ( & V_218 -> V_2 ) ;
F_126 ( & V_218 -> V_2 ) ;
F_50 ( V_7 , 0 , 1 ) ;
F_127 ( V_7 -> V_219 , F_95 ( V_7 , 0xffffffff ) == 0 ) ;
if ( V_218 -> V_13 == V_220 )
F_128 ( V_218 ) ;
if ( V_7 -> V_2 ) {
F_129 ( V_7 -> V_2 ) ;
V_7 -> V_2 = NULL ;
}
return;
}
static int F_130 ( struct V_6 * V_7 )
{
switch ( V_7 -> V_16 . type ) {
case V_179 :
V_7 -> V_2 = F_131 ( 0 , L_51 , V_221 ) ;
break;
case V_17 :
V_7 -> V_2 = F_131 ( 0 , L_52 , V_221 ) ;
V_7 -> V_2 -> V_35 |= V_222 ;
break;
default:
V_7 -> V_2 = F_132 ( 0 ) ;
}
if ( ! V_7 -> V_2 )
return - V_12 ;
V_7 -> V_2 -> V_8 = V_7 ;
V_7 -> V_2 -> V_223 = V_224 ;
V_7 -> V_2 -> V_225 = V_7 -> V_16 . V_226 ;
V_7 -> V_2 -> V_227 = & V_228 ;
if ( V_7 -> V_16 . type != V_17 )
F_133 ( V_7 -> V_2 , & V_229 ) ;
else
F_133 ( V_7 -> V_2 , & V_230 ) ;
V_7 -> V_2 -> V_231 |= V_232 ;
V_7 -> V_16 . V_233 = 1 ;
F_86 ( V_7 ) ;
F_134 ( V_7 -> V_2 , & V_7 -> V_172 -> V_2 ) ;
F_135 ( V_7 -> V_2 , & V_7 -> V_152 , F_69 , V_234 ) ;
return F_136 ( V_7 -> V_2 ) ;
}
static int F_137 ( struct V_215 * V_172 , int V_114 )
{
struct V_6 * V_7 = F_122 ( & V_172 -> V_2 ) ;
int V_11 = 0 ;
enum V_235 V_236 ;
F_138 ( & V_7 -> V_237 ) ;
F_138 ( & V_7 -> V_238 ) ;
F_48 ( V_115 , 2 , L_53 ) ;
F_49 ( V_115 , 2 , & V_7 , sizeof( void * ) ) ;
V_236 = V_7 -> V_13 ;
V_11 = F_139 ( V_7 ) ;
if ( V_11 ) {
F_87 ( V_115 , 2 , L_54 , V_11 ) ;
V_11 = - V_12 ;
goto V_239;
}
F_140 ( V_7 ) ;
if ( V_7 -> V_156 . V_240 . V_241 )
F_82 ( & V_7 -> V_172 -> V_2 ,
L_55 ) ;
F_141 ( V_7 ) ;
if ( ! V_7 -> V_2 && F_130 ( V_7 ) ) {
V_11 = - V_12 ;
goto V_239;
}
if ( V_7 -> V_16 . type != V_17 )
F_83 ( V_7 , & V_7 -> V_2 -> V_175 [ 0 ] ) ;
if ( F_142 ( V_7 , V_242 ) ) {
if ( V_7 -> V_16 . V_217 &&
F_143 ( V_7 , V_243 ) )
V_7 -> V_16 . V_217 = 0 ;
} else
V_7 -> V_16 . V_217 = 0 ;
F_144 ( V_7 ) ;
V_7 -> V_13 = V_121 ;
memset ( & V_7 -> V_129 , 0 , sizeof( struct V_244 ) ) ;
F_145 ( V_7 ) ;
F_48 ( V_115 , 2 , L_56 ) ;
V_11 = F_146 ( V_7 ) ;
if ( V_11 ) {
F_87 ( V_115 , 2 , L_40 , V_11 ) ;
if ( V_11 == 0xe080 ) {
F_81 ( & V_7 -> V_172 -> V_2 ,
L_57 ) ;
V_7 -> V_198 = 0 ;
goto V_245;
}
V_11 = - V_12 ;
goto V_239;
} else
V_7 -> V_198 = 1 ;
V_245:
if ( ( V_7 -> V_16 . type == V_23 ) ||
( V_7 -> V_16 . type == V_25 ) ) {
V_11 = F_147 ( V_7 , 0 ) ;
if ( V_11 ) {
V_11 = - V_12 ;
goto V_239;
}
}
if ( V_7 -> V_16 . type != V_17 &&
V_7 -> V_16 . type != V_24 )
F_42 ( V_7 ) ;
F_119 ( V_7 -> V_2 ) ;
V_11 = F_148 ( V_7 ) ;
if ( V_11 ) {
F_87 ( V_115 , 2 , L_58 , V_11 ) ;
V_11 = - V_12 ;
goto V_239;
}
V_7 -> V_13 = V_15 ;
if ( V_7 -> V_198 )
F_149 ( V_7 -> V_2 ) ;
else
F_150 ( V_7 -> V_2 ) ;
F_50 ( V_7 , 0xffffffff , 0 ) ;
if ( V_236 == V_246 ) {
if ( V_114 &&
V_7 -> V_16 . type != V_17 ) {
F_114 ( V_7 -> V_2 ) ;
} else {
F_52 () ;
F_151 ( V_7 -> V_2 ) ;
F_54 () ;
}
F_46 ( V_7 -> V_2 ) ;
}
F_152 ( & V_172 -> V_2 . V_247 , V_248 ) ;
F_153 ( & V_7 -> V_238 ) ;
F_153 ( & V_7 -> V_237 ) ;
return 0 ;
V_239:
F_47 ( V_7 , 0 ) ;
F_154 ( F_155 ( V_7 ) ) ;
F_154 ( F_156 ( V_7 ) ) ;
F_154 ( F_13 ( V_7 ) ) ;
F_157 ( F_155 ( V_7 ) ) ;
if ( V_236 == V_246 )
V_7 -> V_13 = V_246 ;
else
V_7 -> V_13 = V_122 ;
F_153 ( & V_7 -> V_238 ) ;
F_153 ( & V_7 -> V_237 ) ;
return V_11 ;
}
static int F_158 ( struct V_215 * V_172 )
{
return F_137 ( V_172 , 0 ) ;
}
static int F_159 ( struct V_215 * V_218 ,
int V_114 )
{
struct V_6 * V_7 = F_122 ( & V_218 -> V_2 ) ;
int V_11 = 0 , V_249 = 0 , V_250 = 0 ;
enum V_235 V_236 ;
F_138 ( & V_7 -> V_237 ) ;
F_138 ( & V_7 -> V_238 ) ;
F_48 ( V_115 , 3 , L_59 ) ;
F_49 ( V_115 , 3 , & V_7 , sizeof( void * ) ) ;
if ( V_7 -> V_2 && F_160 ( V_7 -> V_2 ) )
F_150 ( V_7 -> V_2 ) ;
V_236 = V_7 -> V_13 ;
if ( ( ! V_114 && V_7 -> V_16 . V_217 ) || V_7 -> V_16 . V_217 == 2 ) {
F_143 ( V_7 , V_251 ) ;
V_7 -> V_16 . V_217 = 1 ;
}
F_47 ( V_7 , V_114 ) ;
V_11 = F_154 ( F_155 ( V_7 ) ) ;
V_249 = F_154 ( F_156 ( V_7 ) ) ;
V_250 = F_154 ( F_13 ( V_7 ) ) ;
if ( ! V_11 )
V_11 = ( V_249 ) ? V_249 : V_250 ;
if ( V_11 )
F_87 ( V_115 , 2 , L_40 , V_11 ) ;
F_157 ( F_155 ( V_7 ) ) ;
if ( V_236 == V_14 )
V_7 -> V_13 = V_246 ;
F_152 ( & V_218 -> V_2 . V_247 , V_248 ) ;
F_153 ( & V_7 -> V_238 ) ;
F_153 ( & V_7 -> V_237 ) ;
return 0 ;
}
static int F_128 ( struct V_215 * V_218 )
{
return F_159 ( V_218 , 0 ) ;
}
static int F_161 ( void * V_252 )
{
struct V_6 * V_7 ;
int V_11 = 0 ;
V_7 = (struct V_6 * ) V_252 ;
F_15 ( V_7 , 2 , L_60 ) ;
if ( ! F_162 ( V_7 , V_109 ) )
return 0 ;
F_15 ( V_7 , 2 , L_61 ) ;
F_81 ( & V_7 -> V_172 -> V_2 ,
L_62 ) ;
F_163 ( V_7 ) ;
F_159 ( V_7 -> V_172 , 1 ) ;
V_11 = F_137 ( V_7 -> V_172 , 1 ) ;
if ( ! V_11 )
F_82 ( & V_7 -> V_172 -> V_2 ,
L_63 ) ;
else {
F_164 ( V_7 ) ;
F_81 ( & V_7 -> V_172 -> V_2 , L_64
L_65 ) ;
}
F_165 ( V_7 ) ;
F_166 ( V_7 , V_109 ) ;
F_167 ( V_7 , V_109 ) ;
return 0 ;
}
static int T_5 F_168 ( void )
{
F_169 ( L_66 ) ;
return 0 ;
}
static void T_6 F_170 ( void )
{
F_169 ( L_67 ) ;
}
static void F_171 ( struct V_215 * V_172 )
{
struct V_6 * V_7 = F_122 ( & V_172 -> V_2 ) ;
F_50 ( V_7 , 0 , 1 ) ;
if ( ( V_172 -> V_13 == V_220 ) && V_7 -> V_16 . V_217 )
F_143 ( V_7 , V_251 ) ;
F_56 ( V_7 , 0 ) ;
F_57 ( V_7 ) ;
F_157 ( F_155 ( V_7 ) ) ;
}
static int F_172 ( struct V_215 * V_172 )
{
struct V_6 * V_7 = F_122 ( & V_172 -> V_2 ) ;
if ( V_7 -> V_2 )
F_173 ( V_7 -> V_2 ) ;
F_50 ( V_7 , 0 , 1 ) ;
F_127 ( V_7 -> V_219 , F_95 ( V_7 , 0xffffffff ) == 0 ) ;
if ( V_172 -> V_13 == V_253 )
return 0 ;
if ( V_7 -> V_13 == V_14 ) {
if ( V_7 -> V_16 . V_217 )
F_143 ( V_7 , V_251 ) ;
F_159 ( V_7 -> V_172 , 1 ) ;
} else
F_159 ( V_7 -> V_172 , 0 ) ;
return 0 ;
}
static int F_174 ( struct V_215 * V_172 )
{
struct V_6 * V_7 = F_122 ( & V_172 -> V_2 ) ;
int V_11 = 0 ;
if ( V_172 -> V_13 == V_253 )
goto V_168;
if ( V_7 -> V_13 == V_246 ) {
V_11 = F_137 ( V_7 -> V_172 , 1 ) ;
if ( V_11 ) {
F_52 () ;
F_53 ( V_7 -> V_2 ) ;
F_54 () ;
}
} else
V_11 = F_137 ( V_7 -> V_172 , 0 ) ;
V_168:
F_50 ( V_7 , 0xffffffff , 0 ) ;
if ( V_7 -> V_2 )
F_175 ( V_7 -> V_2 ) ;
if ( V_11 )
F_81 ( & V_7 -> V_172 -> V_2 , L_64
L_65 ) ;
return V_11 ;
}
static int F_176 ( struct V_6 * V_7 ,
struct V_48 * V_5 )
{
switch ( V_5 -> V_51 . V_96 ) {
case V_254 :
if ( V_5 -> V_47 . V_240 . V_51 . V_255 ==
V_256 ) {
F_177 ( V_7 , V_5 ) ;
return 0 ;
} else
return 1 ;
case V_257 :
F_178 ( V_7 , V_5 ) ;
return 0 ;
default:
return 1 ;
}
}
static int F_179 ( struct V_6 * V_7 , int V_88 ,
struct V_100 * V_101 )
{
unsigned long V_35 ;
int V_11 = 0 ;
F_15 ( V_7 , 5 , L_68 ) ;
F_127 ( V_7 -> V_219 ,
F_180 ( & V_7 -> V_118 . V_258 , 0 , 1 ) == 0 ) ;
F_181 ( V_7 , V_88 , V_101 ) ;
F_15 ( V_7 , 6 , L_69 ) ;
F_182 ( F_183 ( V_7 -> V_118 . V_163 ) , V_35 ) ;
V_11 = F_184 ( V_7 -> V_118 . V_163 , & V_7 -> V_118 . V_259 ,
( V_260 ) V_101 , 0 , 0 ) ;
F_185 ( F_183 ( V_7 -> V_118 . V_163 ) , V_35 ) ;
if ( V_11 ) {
F_16 ( 2 , L_70
L_71 , V_11 ) ;
F_6 ( V_7 , 2 , L_72 , V_11 ) ;
F_186 ( V_101 -> V_261 , V_101 ) ;
F_187 ( & V_7 -> V_118 . V_258 , 0 ) ;
F_188 ( & V_7 -> V_219 ) ;
}
return V_11 ;
}
static int F_189 ( struct V_6 * V_7 ,
struct V_100 * V_101 , int V_262 )
{
T_4 V_263 , V_264 ;
F_15 ( V_7 , 4 , L_73 ) ;
F_190 ( V_7 , V_101 , V_265 ) ;
V_263 = ( T_4 ) ( V_103 + V_262 ) ;
V_264 = ( T_4 ) V_262 ;
memcpy ( F_191 ( V_101 -> V_47 ) , & V_263 , 2 ) ;
memcpy ( F_192 ( V_101 -> V_47 ) , & V_264 , 2 ) ;
memcpy ( F_193 ( V_101 -> V_47 ) , & V_264 , 2 ) ;
memcpy ( F_194 ( V_101 -> V_47 ) , & V_264 , 2 ) ;
return F_179 ( V_7 , V_263 , V_101 ) ;
}
int F_195 ( struct V_1 * V_2 , void * V_47 , int V_262 )
{
struct V_100 * V_101 ;
struct V_6 * V_7 ;
int V_11 ;
if ( ! V_2 )
return - V_12 ;
V_7 = V_2 -> V_8 ;
if ( ! V_7 )
return - V_12 ;
F_15 ( V_7 , 2 , L_74 ) ;
if ( ( V_7 -> V_13 != V_14 ) &&
( V_7 -> V_13 != V_15 ) )
return - V_12 ;
V_101 = F_196 ( & V_7 -> V_118 ) ;
memcpy ( V_101 -> V_47 + V_103 , V_47 , V_262 ) ;
V_11 = F_189 ( V_7 , V_101 , V_262 ) ;
return V_11 ;
}
int F_197 ( unsigned char * V_39 , struct V_1 * * V_2 ,
int (* F_198)( struct V_1 * , void * ) ,
int (* V_145)( struct V_71 * ) )
{
struct V_6 * V_7 ;
* V_2 = F_11 ( V_39 ) ;
if ( * V_2 == NULL )
return - V_12 ;
V_7 = ( * V_2 ) -> V_8 ;
if ( ! V_7 )
return - V_12 ;
F_15 ( V_7 , 2 , L_75 ) ;
if ( ( F_198 == NULL ) || ( V_145 == NULL ) )
return - V_30 ;
V_7 -> V_144 . F_198 = F_198 ;
V_7 -> V_144 . V_145 = V_145 ;
return 0 ;
}
void F_199 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
if ( ! V_2 )
return;
V_7 = V_2 -> V_8 ;
if ( ! V_7 )
return;
F_15 ( V_7 , 2 , L_76 ) ;
V_7 -> V_144 . F_198 = NULL ;
V_7 -> V_144 . V_145 = NULL ;
return;
}
static void F_200 ( struct V_6 * V_7 ,
enum V_266 V_267 ,
T_7 V_268 , struct V_269 * V_270 , struct V_271 * V_272 )
{
char V_273 [ 7 ] [ 32 ] ;
char * V_274 [ 8 ] ;
int V_97 = 0 ;
switch ( V_267 ) {
case V_275 :
snprintf ( V_273 [ V_97 ] , sizeof( V_273 [ V_97 ] ) , L_77 ,
( V_268 & V_276 )
? L_78 : L_79 ) ;
V_274 [ V_97 ] = V_273 [ V_97 ] ; V_97 ++ ;
if ( V_268 & V_277 ) {
snprintf ( V_273 [ V_97 ] , sizeof( V_273 [ V_97 ] ) , L_80 ,
V_272 -> V_278 ) ;
V_274 [ V_97 ] = V_273 [ V_97 ] ; V_97 ++ ;
}
if ( V_268 & V_279 ) {
snprintf ( V_273 [ V_97 ] , sizeof( V_273 [ V_97 ] ) , L_81 ,
& V_272 -> V_49 ) ;
V_274 [ V_97 ] = V_273 [ V_97 ] ; V_97 ++ ;
}
snprintf ( V_273 [ V_97 ] , sizeof( V_273 [ V_97 ] ) , L_82 ,
V_270 -> V_280 , V_270 -> V_281 , V_270 -> V_282 ) ;
V_274 [ V_97 ] = V_273 [ V_97 ] ; V_97 ++ ;
snprintf ( V_273 [ V_97 ] , sizeof( V_273 [ V_97 ] ) , L_83 , V_270 -> V_283 ) ;
V_274 [ V_97 ] = V_273 [ V_97 ] ; V_97 ++ ;
snprintf ( V_273 [ V_97 ] , sizeof( V_273 [ V_97 ] ) , L_84 ,
V_270 -> V_284 ) ;
V_274 [ V_97 ] = V_273 [ V_97 ] ; V_97 ++ ;
snprintf ( V_273 [ V_97 ] , sizeof( V_273 [ V_97 ] ) , L_85 , V_270 -> V_285 ) ;
V_274 [ V_97 ] = V_273 [ V_97 ] ; V_97 ++ ;
break;
case V_286 :
snprintf ( V_273 [ V_97 ] , sizeof( V_273 [ V_97 ] ) , L_86 ) ;
V_274 [ V_97 ] = V_273 [ V_97 ] ; V_97 ++ ;
break;
case V_287 :
snprintf ( V_273 [ V_97 ] , sizeof( V_273 [ V_97 ] ) , L_87 ) ;
V_274 [ V_97 ] = V_273 [ V_97 ] ; V_97 ++ ;
break;
}
V_274 [ V_97 ] = NULL ;
F_201 ( & V_7 -> V_172 -> V_2 . V_247 , V_248 , V_274 ) ;
}
static void F_202 ( struct V_288 * V_289 )
{
struct V_290 * V_47 =
F_70 ( V_289 , struct V_290 , V_291 ) ;
struct V_292 * V_293 = & V_47 -> V_294 . V_293 [ 0 ] ;
char V_295 [ 32 ] ;
char V_296 [ 32 ] ;
char V_297 [ 32 ] ;
char * V_274 [] = {
V_295 ,
V_296 ,
V_297 ,
NULL
} ;
F_138 ( & V_47 -> V_7 -> V_238 ) ;
V_47 -> V_7 -> V_156 . V_240 . V_298 = V_293 -> V_298 ;
F_153 ( & V_47 -> V_7 -> V_238 ) ;
snprintf ( V_295 , sizeof( V_295 ) , L_88 ) ;
snprintf ( V_296 , sizeof( V_296 ) , L_89 ,
( V_293 -> V_298 == V_299 ) ? L_90 :
( V_293 -> V_298 == V_300 ) ? L_91 :
( V_293 -> V_298 == V_301 ) ? L_92 :
L_93 ) ;
snprintf ( V_297 , sizeof( V_297 ) , L_94 ,
( V_293 -> V_13 == V_302 ) ? L_95 :
( V_293 -> V_13 == V_303 ) ? L_96 :
( V_293 -> V_13 == V_304 ) ? L_97 :
L_93 ) ;
F_201 ( & V_47 -> V_7 -> V_172 -> V_2 . V_247 ,
V_248 , V_274 ) ;
F_25 ( V_47 ) ;
}
static void F_177 ( struct V_6 * V_7 ,
struct V_48 * V_5 )
{
struct V_305 * V_294 =
& V_5 -> V_47 . V_240 . V_47 . V_306 ;
struct V_290 * V_47 ;
int V_307 ;
F_15 ( V_7 , 2 , L_98 ) ;
if ( V_294 -> V_308 != sizeof( struct V_292 ) ) {
F_6 ( V_7 , 2 , L_99 , V_294 -> V_308 ) ;
return;
}
V_307 = sizeof( struct V_292 ) * V_294 -> V_309 ;
V_47 = F_203 ( sizeof( struct V_290 ) + V_307 ,
V_59 ) ;
if ( ! V_47 ) {
F_15 ( V_7 , 2 , L_100 ) ;
return;
}
F_204 ( & V_47 -> V_291 , F_202 ) ;
V_47 -> V_7 = V_7 ;
memcpy ( & V_47 -> V_294 , V_294 ,
sizeof( struct V_305 ) + V_307 ) ;
F_205 ( V_310 , & V_47 -> V_291 ) ;
}
static void F_206 ( struct V_288 * V_289 )
{
struct V_311 * V_47 =
F_70 ( V_289 , struct V_311 , V_291 ) ;
int V_97 ;
if ( V_47 -> V_312 . V_313 ) {
F_82 ( & V_47 -> V_7 -> V_172 -> V_2 ,
L_101 ,
V_47 -> V_7 -> V_2 -> V_176 ,
( V_47 -> V_312 . V_313 == 0x01 )
? L_102
: ( V_47 -> V_312 . V_313 == 0x02 )
? L_103
: L_104 ) ;
F_138 ( & V_47 -> V_7 -> V_238 ) ;
V_47 -> V_7 -> V_156 . V_240 . V_314 = 0 ;
F_153 ( & V_47 -> V_7 -> V_238 ) ;
F_200 ( V_47 -> V_7 , V_286 ,
0 , NULL , NULL ) ;
} else
for ( V_97 = 0 ; V_97 < V_47 -> V_312 . V_309 ; V_97 ++ ) {
struct V_315 * V_293 =
& V_47 -> V_312 . V_293 [ V_97 ] ;
F_200 ( V_47 -> V_7 ,
V_275 ,
V_293 -> V_316 ,
& V_293 -> V_270 , & V_293 -> V_272 ) ;
}
F_25 ( V_47 ) ;
}
static void F_178 ( struct V_6 * V_7 ,
struct V_48 * V_5 )
{
struct V_317 * V_312 =
& V_5 -> V_47 . V_318 ;
struct V_311 * V_47 ;
int V_307 ;
F_15 ( V_7 , 2 , L_105 ) ;
if ( V_5 -> V_51 . V_52 != 0x0000 ) {
if ( V_5 -> V_51 . V_52 == 0x0010 ) {
if ( V_312 -> V_313 == 0x00 )
V_312 -> V_313 = 0xff ;
} else {
F_6 ( V_7 , 2 , L_106 ,
V_5 -> V_51 . V_52 ) ;
return;
}
}
V_307 = sizeof( struct V_315 ) *
V_312 -> V_309 ;
V_47 = F_203 ( sizeof( struct V_311 ) + V_307 ,
V_59 ) ;
if ( ! V_47 ) {
F_15 ( V_7 , 2 , L_107 ) ;
return;
}
F_204 ( & V_47 -> V_291 , F_206 ) ;
V_47 -> V_7 = V_7 ;
memcpy ( & V_47 -> V_312 , V_312 ,
sizeof( struct V_317 ) + V_307 ) ;
F_205 ( V_310 , & V_47 -> V_291 ) ;
}
static int F_207 ( struct V_6 * V_7 ,
struct V_319 * V_320 , enum V_321 V_322 )
{
int V_11 ;
switch ( V_320 -> V_323 ) {
case V_324 :
switch ( V_320 -> V_325 ) {
case 0x0000 :
V_11 = 0 ;
break;
case 0x0004 :
V_11 = - V_326 ;
break;
case 0x000C :
V_11 = - V_12 ;
F_208 ( & V_7 -> V_172 -> V_2 ,
L_108 ) ;
break;
case 0x0014 :
switch ( V_322 ) {
case V_327 :
V_11 = - V_328 ;
F_208 ( & V_7 -> V_172 -> V_2 ,
L_109 ) ;
break;
case V_329 :
V_11 = - V_209 ;
F_208 ( & V_7 -> V_172 -> V_2 ,
L_110 ) ;
break;
default:
V_11 = - V_214 ;
}
break;
case 0x0018 :
V_11 = - V_209 ;
F_208 ( & V_7 -> V_172 -> V_2 ,
L_111 ) ;
break;
case 0x001C :
V_11 = - V_328 ;
F_208 ( & V_7 -> V_172 -> V_2 ,
L_112 ) ;
break;
case 0x0024 :
V_11 = - V_209 ;
F_208 ( & V_7 -> V_172 -> V_2 ,
L_110 ) ;
break;
case 0x0020 :
V_11 = - V_330 ;
F_208 ( & V_7 -> V_172 -> V_2 ,
L_113 ) ;
break;
default:
V_11 = - V_214 ;
}
break;
case V_331 :
V_11 = - V_326 ;
break;
case V_332 :
V_11 = - V_326 ;
break;
default:
V_11 = - V_214 ;
}
if ( V_11 ) {
F_6 ( V_7 , 2 , L_114 , V_320 -> V_323 ) ;
F_6 ( V_7 , 2 , L_115 , V_320 -> V_325 ) ;
}
return V_11 ;
}
static int F_209 ( struct V_6 * V_7 ,
struct V_45 * V_46 , unsigned long V_47 )
{
struct V_48 * V_5 = (struct V_48 * ) V_47 ;
struct V_319 * V_320 = (struct V_319 * ) V_46 -> V_333 ;
F_15 ( V_7 , 2 , L_116 ) ;
V_320 -> V_323 = V_5 -> V_51 . V_52 ;
V_320 -> V_325 = V_5 -> V_47 . V_240 . V_51 . V_52 ;
if ( ( V_320 -> V_323 == 0 ) && ( V_320 -> V_325 == 0 ) ) {
V_320 -> V_47 . V_334 =
V_5 -> V_47 . V_240 . V_47 . V_335 . V_336 ;
} else {
V_320 -> V_47 . V_334 = 0 ;
}
return 0 ;
}
static void F_140 ( struct V_6 * V_7 )
{
struct V_100 * V_101 ;
struct V_48 * V_5 ;
struct V_319 V_320 ;
F_15 ( V_7 , 2 , L_117 ) ;
V_101 = F_40 ( V_7 , V_254 , 0 ) ;
V_5 = (struct V_48 * ) ( V_101 -> V_47 + V_103 ) ;
V_5 -> V_47 . V_240 . V_51 . V_337 =
sizeof( struct V_338 ) +
sizeof( struct V_339 ) ;
V_5 -> V_47 . V_240 . V_51 . V_255 =
V_340 ;
V_5 -> V_47 . V_240 . V_51 . V_341 = 1 ;
V_5 -> V_47 . V_240 . V_51 . V_342 = 1 ;
if ( F_41 ( V_7 , V_101 , F_209 ,
( void * ) & V_320 ) ||
F_207 ( V_7 , & V_320 ,
V_340 ) ) {
V_7 -> V_156 . V_240 . V_298 = V_299 ;
return;
}
V_7 -> V_156 . V_240 . V_241 = V_320 . V_47 . V_334 ;
}
static int F_210 ( struct V_6 * V_7 ,
struct V_45 * V_46 , unsigned long V_47 )
{
struct V_48 * V_5 = (struct V_48 * ) V_47 ;
struct V_343 * V_294 = & V_5 -> V_47 . V_240 . V_47 . V_344 ;
struct V_319 * V_320 = (struct V_319 * ) V_46 -> V_333 ;
F_15 ( V_7 , 2 , L_118 ) ;
V_320 -> V_323 = V_5 -> V_51 . V_52 ;
V_320 -> V_325 = V_5 -> V_47 . V_240 . V_51 . V_52 ;
if ( ( V_320 -> V_323 != 0 ) || ( V_320 -> V_325 != 0 ) )
return 0 ;
if ( V_294 -> V_308 != sizeof( struct V_292 ) ) {
V_320 -> V_325 = 0xffff ;
F_6 ( V_7 , 2 , L_119 , V_294 -> V_308 ) ;
return 0 ;
}
if ( V_294 -> V_309 > 0 ) {
if ( V_320 -> V_47 . V_294 . V_298 )
* V_320 -> V_47 . V_294 . V_298 = V_294 -> V_293 [ 0 ] . V_298 ;
if ( V_320 -> V_47 . V_294 . V_13 )
* V_320 -> V_47 . V_294 . V_13 = V_294 -> V_293 [ 0 ] . V_13 ;
}
return 0 ;
}
int F_211 ( struct V_6 * V_7 ,
enum V_345 * V_298 , enum V_346 * V_13 )
{
int V_11 = 0 ;
struct V_100 * V_101 ;
struct V_48 * V_5 ;
struct V_319 V_320 = {
. V_47 = {
. V_294 = {
. V_298 = V_298 ,
. V_13 = V_13 ,
} ,
} ,
} ;
F_15 ( V_7 , 2 , L_120 ) ;
if ( ! ( V_7 -> V_156 . V_240 . V_241 & V_347 ) )
return - V_34 ;
V_101 = F_40 ( V_7 , V_254 , 0 ) ;
V_5 = (struct V_48 * ) ( V_101 -> V_47 + V_103 ) ;
V_5 -> V_47 . V_240 . V_51 . V_337 =
sizeof( struct V_338 ) ;
V_5 -> V_47 . V_240 . V_51 . V_255 =
V_347 ;
V_5 -> V_47 . V_240 . V_51 . V_341 = 1 ;
V_5 -> V_47 . V_240 . V_51 . V_342 = 1 ;
V_11 = F_41 ( V_7 , V_101 , F_210 ,
( void * ) & V_320 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_207 ( V_7 , & V_320 , V_347 ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}
static int F_212 ( struct V_6 * V_7 ,
struct V_45 * V_46 , unsigned long V_47 )
{
struct V_48 * V_5 = (struct V_48 * ) V_47 ;
struct V_319 * V_320 = (struct V_319 * ) V_46 -> V_333 ;
F_15 ( V_7 , 2 , L_121 ) ;
V_320 -> V_323 = V_5 -> V_51 . V_52 ;
V_320 -> V_325 = V_5 -> V_47 . V_240 . V_51 . V_52 ;
return 0 ;
}
int F_213 ( struct V_6 * V_7 , enum V_345 V_298 )
{
int V_11 = 0 ;
int V_337 ;
struct V_100 * V_101 ;
struct V_48 * V_5 ;
struct V_319 V_320 ;
enum V_321 V_322 ;
F_15 ( V_7 , 2 , L_122 ) ;
switch ( V_298 ) {
case V_299 :
V_322 = V_348 ;
V_337 = sizeof( struct V_338 ) +
sizeof( struct V_349 ) ;
break;
case V_300 :
V_322 = V_327 ;
V_337 = sizeof( struct V_338 ) +
sizeof( struct V_350 ) ;
break;
case V_301 :
V_322 = V_329 ;
V_337 = sizeof( struct V_338 ) +
sizeof( struct V_351 ) ;
break;
default:
return - V_30 ;
}
if ( ! ( V_7 -> V_156 . V_240 . V_241 & V_322 ) )
return - V_34 ;
V_101 = F_40 ( V_7 , V_254 , 0 ) ;
V_5 = (struct V_48 * ) ( V_101 -> V_47 + V_103 ) ;
V_5 -> V_47 . V_240 . V_51 . V_337 = V_337 ;
V_5 -> V_47 . V_240 . V_51 . V_255 = V_322 ;
V_5 -> V_47 . V_240 . V_51 . V_341 = 1 ;
V_5 -> V_47 . V_240 . V_51 . V_342 = 1 ;
V_11 = F_41 ( V_7 , V_101 , F_212 ,
( void * ) & V_320 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_207 ( V_7 , & V_320 , V_322 ) ;
return V_11 ;
}
static int F_214 ( struct V_6 * V_7 , int V_352 , T_4 V_353 )
{
int V_11 ;
if ( V_352 == 0 )
switch ( V_353 ) {
case 0x0001 :
V_11 = 0 ;
break;
case 0x0004 :
case 0x0100 :
case 0x0106 :
V_11 = - V_326 ;
F_208 ( & V_7 -> V_172 -> V_2 ,
L_123 ) ;
break;
case 0x0107 :
V_11 = - V_354 ;
break;
default:
V_11 = - V_214 ;
}
else
V_11 = - V_214 ;
if ( V_11 ) {
F_6 ( V_7 , 2 , L_124 , V_352 ) ;
F_6 ( V_7 , 2 , L_125 , V_353 ) ;
}
return V_11 ;
}
static void F_215 ( void * V_355 ,
enum V_356 type , void * V_293 )
{
struct V_6 * V_7 = (struct V_6 * ) V_355 ;
struct V_357 * V_358 ;
T_7 V_268 ;
if ( type != V_359 ) {
F_61 ( 1 ) ;
return;
}
V_358 = (struct V_357 * ) V_293 ;
V_268 = V_279 ;
if ( V_358 -> V_272 . V_278 )
V_268 |= V_277 ;
F_200 ( V_7 , V_275 , V_268 ,
(struct V_269 * ) & V_358 -> V_360 ,
(struct V_271 * ) & V_358 -> V_272 ) ;
}
int F_216 ( struct V_6 * V_7 , int V_361 )
{
int V_11 ;
T_4 V_353 ;
struct V_362 * V_363 ;
struct V_364 V_365 ;
if ( ! V_7 )
return - V_30 ;
if ( ! V_7 -> V_156 . V_240 . V_241 )
return - V_34 ;
V_363 = F_155 ( V_7 ) ;
F_217 ( V_363 , & V_365 ) ;
if ( V_361 ) {
F_200 ( V_7 , V_287 , 0 , NULL , NULL ) ;
V_11 = F_218 ( V_365 , 1 , & V_353 ,
F_215 , V_7 ) ;
} else
V_11 = F_218 ( V_365 , 0 , & V_353 , NULL , NULL ) ;
return F_214 ( V_7 , V_11 , V_353 ) ;
}
