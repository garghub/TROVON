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
static int F_43 ( struct V_1 * V_2 , unsigned short V_106 )
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
if ( F_44 ( V_7 , V_108 ) ) {
F_15 ( V_7 , 3 , L_18 ) ;
return 0 ;
}
V_82 = F_23 ( sizeof( struct V_104 ) , V_59 ) ;
if ( V_82 ) {
V_82 -> V_106 = V_106 ;
F_39 ( V_7 , V_106 , V_107 ) ;
F_27 ( & V_7 -> V_105 ) ;
F_24 ( & V_82 -> V_65 , & V_7 -> V_109 ) ;
F_30 ( & V_7 -> V_105 ) ;
} else {
return - V_110 ;
}
return 0 ;
}
static int F_45 ( struct V_1 * V_2 , unsigned short V_106 )
{
struct V_104 * V_82 , * V_111 = NULL ;
struct V_6 * V_7 = V_2 -> V_8 ;
F_6 ( V_7 , 4 , L_19 , V_106 ) ;
if ( V_7 -> V_16 . type == V_24 ) {
F_15 ( V_7 , 3 , L_20 ) ;
return 0 ;
}
if ( F_44 ( V_7 , V_108 ) ) {
F_15 ( V_7 , 3 , L_21 ) ;
return 0 ;
}
F_27 ( & V_7 -> V_105 ) ;
F_9 (id, &card->vid_list, list) {
if ( V_82 -> V_106 == V_106 ) {
F_29 ( & V_82 -> V_65 ) ;
V_111 = V_82 ;
break;
}
}
F_30 ( & V_7 -> V_105 ) ;
if ( V_111 ) {
F_39 ( V_7 , V_106 , V_112 ) ;
F_25 ( V_111 ) ;
}
F_46 ( V_7 -> V_2 ) ;
return 0 ;
}
static int F_47 ( struct V_6 * V_7 , int V_113 )
{
int V_11 = 0 ;
F_48 ( V_114 , 2 , L_22 ) ;
F_49 ( V_114 , 2 , & V_7 , sizeof( void * ) ) ;
F_50 ( V_7 , 0 , 1 ) ;
if ( V_7 -> V_115 . V_13 == V_116 &&
V_7 -> V_117 . V_13 == V_116 &&
( V_7 -> V_13 == V_14 ) ) {
if ( V_113 &&
V_7 -> V_16 . type != V_17 ) {
F_51 ( V_7 -> V_2 ) ;
} else {
F_52 () ;
F_53 ( V_7 -> V_2 ) ;
F_54 () ;
}
V_7 -> V_16 . V_118 &= ~ V_119 ;
V_7 -> V_13 = V_15 ;
}
if ( V_7 -> V_13 == V_15 ) {
F_26 ( V_7 , 0 ) ;
F_55 ( V_7 ) ;
V_7 -> V_13 = V_120 ;
}
if ( V_7 -> V_13 == V_120 ) {
F_56 ( V_7 , 0 ) ;
F_57 ( V_7 ) ;
F_58 ( V_7 ) ;
V_7 -> V_13 = V_121 ;
}
if ( V_7 -> V_13 == V_121 ) {
F_59 ( & V_7 -> V_115 ) ;
F_59 ( & V_7 -> V_117 ) ;
}
return V_11 ;
}
static int F_60 ( struct V_6 * V_7 ,
int V_122 , int * V_123 )
{
int V_124 = 0 ;
struct V_71 * V_72 ;
struct V_76 * V_51 ;
unsigned int V_88 ;
* V_123 = 0 ;
F_61 ( ! V_122 ) ;
while ( V_122 ) {
V_72 = F_62 ( V_7 ,
& V_7 -> V_125 . V_126 -> V_127 [ V_7 -> V_128 . V_129 ] ,
& V_7 -> V_128 . V_130 , & V_7 -> V_128 . V_131 , & V_51 ) ;
if ( ! V_72 ) {
* V_123 = 1 ;
break;
}
V_72 -> V_2 = V_7 -> V_2 ;
switch ( V_51 -> V_51 . V_81 . V_82 ) {
case V_83 :
V_72 -> V_132 = V_133 ;
V_72 -> V_134 = F_63 ( V_72 , V_72 -> V_2 ) ;
V_72 -> V_135 = V_136 ;
if ( V_72 -> V_134 == F_64 ( V_137 ) )
* ( ( V_138 * ) V_72 -> V_139 ) = ++ V_7 -> V_140 . V_141 ;
V_88 = V_72 -> V_88 ;
F_65 ( V_72 ) ;
break;
case V_142 :
if ( V_7 -> V_16 . type == V_17 ) {
F_66 ( V_72 , sizeof( struct V_76 ) ) ;
F_67 ( V_72 , V_51 ,
sizeof( struct V_76 ) ) ;
V_88 = V_72 -> V_88 ;
V_7 -> V_143 . V_144 ( V_72 ) ;
break;
}
default:
F_68 ( V_72 ) ;
F_15 ( V_7 , 3 , L_23 ) ;
F_49 ( V_145 , 3 , V_51 , V_146 ) ;
continue;
}
V_124 ++ ;
V_122 -- ;
V_7 -> V_147 . V_148 ++ ;
V_7 -> V_147 . V_149 += V_88 ;
}
return V_124 ;
}
static int F_69 ( struct V_150 * V_151 , int V_122 )
{
struct V_6 * V_7 = F_70 ( V_151 , struct V_6 , V_151 ) ;
int V_124 = 0 ;
struct V_152 * V_153 ;
int V_123 ;
int V_154 = V_122 ;
if ( V_7 -> V_155 . V_156 ) {
V_7 -> V_157 . V_158 ++ ;
V_7 -> V_157 . V_159 = F_71 () ;
}
while ( 1 ) {
if ( ! V_7 -> V_128 . V_160 ) {
V_7 -> V_128 . V_161 = 0 ;
V_7 -> V_128 . V_160 = F_72 (
V_7 -> V_47 . V_162 , 0 , & V_7 -> V_128 . V_129 ,
& V_7 -> V_128 . V_161 ) ;
if ( V_7 -> V_128 . V_160 <= 0 ) {
V_7 -> V_128 . V_160 = 0 ;
break;
}
V_7 -> V_128 . V_130 =
& V_7 -> V_125 . V_126 -> V_127 [ V_7 -> V_128 . V_129 ]
. V_153 -> V_163 [ 0 ] ;
V_7 -> V_128 . V_131 = 0 ;
}
while ( V_7 -> V_128 . V_160 ) {
V_153 = & V_7 -> V_125 . V_126 -> V_127 [ V_7 -> V_128 . V_129 ] ;
if ( ! ( V_7 -> V_128 . V_161 &&
F_73 ( V_7 , V_153 -> V_153 ,
V_7 -> V_128 . V_161 , L_24 ) ) )
V_124 += F_60 (
V_7 , V_154 , & V_123 ) ;
else
V_123 = 1 ;
if ( V_123 ) {
if ( V_7 -> V_155 . V_156 )
V_7 -> V_157 . V_164 ++ ;
F_74 ( V_7 ,
V_153 -> V_165 ) ;
F_75 ( V_7 , V_7 -> V_128 . V_129 ) ;
V_7 -> V_128 . V_160 -- ;
if ( V_7 -> V_128 . V_160 ) {
V_7 -> V_128 . V_129 =
( V_7 -> V_128 . V_129 + 1 ) %
V_166 ;
V_7 -> V_128 . V_130 =
& V_7 -> V_125 . V_126
-> V_127 [ V_7 -> V_128 . V_129 ]
. V_153 -> V_163 [ 0 ] ;
V_7 -> V_128 . V_131 = 0 ;
}
}
if ( V_124 >= V_122 )
goto V_167;
else
V_154 = V_122 - V_124 ;
}
}
F_76 ( V_151 ) ;
if ( F_77 ( V_7 -> V_47 . V_162 , 0 ) )
F_78 ( & V_7 -> V_151 ) ;
V_167:
if ( V_7 -> V_155 . V_156 )
V_7 -> V_157 . V_168 += F_71 () -
V_7 -> V_157 . V_159 ;
return V_124 ;
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
V_5 -> V_47 . V_50 . V_169 = V_61 ;
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
V_7 -> V_16 . V_118 &= ~ V_119 ;
switch ( V_5 -> V_51 . V_52 ) {
case V_53 :
case V_170 :
F_81 ( & V_7 -> V_171 -> V_2 ,
L_28 ,
V_5 -> V_47 . V_50 . V_49 ) ;
break;
case V_172 :
case V_173 :
F_81 ( & V_7 -> V_171 -> V_2 ,
L_29 ,
V_5 -> V_47 . V_50 . V_49 ) ;
break;
default:
break;
}
} else {
V_7 -> V_16 . V_118 |= V_119 ;
memcpy ( V_7 -> V_2 -> V_174 , V_5 -> V_47 . V_50 . V_49 ,
V_61 ) ;
F_82 ( & V_7 -> V_171 -> V_2 ,
L_30 ,
V_7 -> V_2 -> V_174 , V_7 -> V_2 -> V_175 ) ;
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
V_7 -> V_16 . V_118 &= ~ V_119 ;
return 0 ;
}
static int F_85 ( struct V_6 * V_7 , T_2 * V_49 )
{
F_15 ( V_7 , 2 , L_33 ) ;
if ( ! ( V_7 -> V_16 . V_118 & V_119 ) )
return 0 ;
return F_19 ( V_7 , V_49 , V_70 ,
F_84 ) ;
}
static int F_86 ( struct V_6 * V_7 )
{
int V_11 = 0 ;
char V_176 [] = { 0x02 , 0x00 , 0x00 } ;
F_48 ( V_114 , 2 , L_34 ) ;
F_87 ( V_114 , 2 , L_35 , F_88 ( V_7 ) ) ;
V_11 = F_89 ( V_7 ) ;
if ( V_11 ) {
F_16 ( 2 , L_36
L_37 , F_88 ( V_7 ) , V_11 ) ;
}
if ( V_7 -> V_16 . type == V_177 ||
V_7 -> V_16 . type == V_24 ||
V_7 -> V_16 . type == V_25 ||
V_7 -> V_16 . V_26 ) {
V_11 = F_90 ( V_7 ) ;
if ( V_11 ) {
F_16 ( 2 , L_38
L_37 , F_88 ( V_7 ) , V_11 ) ;
F_87 ( V_114 , 2 , L_39 , V_11 ) ;
return V_11 ;
}
F_49 ( V_114 , 2 , V_7 -> V_2 -> V_174 , V_61 ) ;
} else {
F_91 ( V_7 -> V_2 -> V_174 ) ;
memcpy ( V_7 -> V_2 -> V_174 , V_176 , 3 ) ;
}
return 0 ;
}
static int F_92 ( struct V_1 * V_2 , void * V_178 )
{
struct V_179 * V_180 = V_178 ;
struct V_6 * V_7 = V_2 -> V_8 ;
int V_11 = 0 ;
F_15 ( V_7 , 3 , L_40 ) ;
if ( F_7 ( V_2 ) != V_38 ) {
F_15 ( V_7 , 3 , L_41 ) ;
return - V_34 ;
}
if ( V_7 -> V_16 . type == V_17 ||
V_7 -> V_16 . type == V_24 ||
V_7 -> V_16 . type == V_25 ) {
F_15 ( V_7 , 3 , L_42 ) ;
return - V_34 ;
}
F_93 ( V_7 , 3 , V_180 -> V_181 , V_61 ) ;
if ( F_44 ( V_7 , V_108 ) ) {
F_15 ( V_7 , 3 , L_43 ) ;
return - V_182 ;
}
V_11 = F_85 ( V_7 , & V_7 -> V_2 -> V_174 [ 0 ] ) ;
if ( ! V_11 )
V_11 = F_83 ( V_7 , V_180 -> V_181 ) ;
return V_11 ? - V_30 : 0 ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_183 * V_184 ;
if ( V_7 -> V_16 . type == V_17 )
return ;
F_15 ( V_7 , 3 , L_44 ) ;
if ( F_94 ( V_7 , V_108 ) &&
( V_7 -> V_13 != V_14 ) )
return;
F_26 ( V_7 , 1 ) ;
F_27 ( & V_7 -> V_69 ) ;
F_95 (ha, dev)
F_22 ( V_7 , V_184 -> V_180 , 0 ) ;
F_96 (ha, dev)
F_22 ( V_7 , V_184 -> V_180 , 1 ) ;
F_30 ( & V_7 -> V_69 ) ;
if ( ! F_97 ( V_7 , V_185 ) )
return;
F_98 ( V_7 ) ;
}
static int F_99 ( struct V_71 * V_72 , struct V_1 * V_2 )
{
int V_11 ;
struct V_76 * V_51 = NULL ;
int V_186 = 0 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_71 * V_187 = V_72 ;
int V_77 = F_100 ( V_72 ) ;
int V_78 = F_31 ( V_7 , V_72 ) ;
struct V_188 * V_189 = V_7 -> V_125 . V_190
[ F_101 ( V_7 , V_72 , V_77 , V_78 ) ] ;
int V_191 = V_72 -> V_88 ;
int V_192 = - 1 ;
int V_193 = 0 ;
int V_194 = 0 ;
if ( ( V_7 -> V_13 != V_14 ) || ! V_7 -> V_195 ) {
V_7 -> V_147 . V_196 ++ ;
goto V_197;
}
if ( ( V_7 -> V_16 . type == V_17 ) &&
( V_72 -> V_134 == F_64 ( V_198 ) ) )
goto V_197;
if ( V_7 -> V_155 . V_156 ) {
V_7 -> V_157 . V_199 ++ ;
V_7 -> V_157 . V_200 = F_71 () ;
}
F_102 ( V_2 ) ;
if ( V_7 -> V_16 . type == V_17 )
V_51 = (struct V_76 * ) V_72 -> V_47 ;
else {
if ( V_7 -> V_16 . type == V_177 ) {
V_187 = V_72 ;
V_192 = V_201 ;
V_194 = V_201 ;
V_51 = F_103 ( V_202 ,
V_59 ) ;
if ( ! V_51 )
goto V_197;
V_193 ++ ;
F_104 ( V_187 ) ;
F_34 ( V_7 , V_51 , V_187 , V_77 , V_78 ) ;
V_51 -> V_51 . V_81 . V_87 = V_187 -> V_88 ;
memcpy ( ( ( char * ) V_51 ) + sizeof( struct V_76 ) ,
F_35 ( V_187 ) , V_201 ) ;
} else {
V_187 = F_105 ( V_72 ,
sizeof( struct V_76 ) ) ;
if ( ! V_187 )
goto V_197;
V_51 = (struct V_76 * ) F_66 ( V_187 ,
sizeof( struct V_76 ) ) ;
F_106 ( V_187 , sizeof( struct V_76 ) ) ;
F_34 ( V_7 , V_51 , V_187 , V_77 , V_78 ) ;
}
}
V_186 = F_107 ( V_7 , ( void * ) V_51 , V_187 ,
V_193 ) ;
if ( ! V_186 ) {
if ( V_192 >= 0 )
F_108 ( V_202 , V_51 ) ;
goto V_197;
}
if ( V_7 -> V_16 . type != V_177 ) {
if ( F_109 ( V_187 ,
sizeof( struct V_203 ) ) )
goto V_197;
V_11 = F_110 ( V_7 , V_189 , V_187 , V_51 ,
V_186 ) ;
} else
V_11 = F_111 ( V_7 , V_189 , V_187 , V_51 ,
V_186 , V_192 , V_194 ) ;
if ( ! V_11 ) {
V_7 -> V_147 . V_204 ++ ;
V_7 -> V_147 . V_191 += V_191 ;
if ( V_187 != V_72 )
F_68 ( V_72 ) ;
V_11 = V_205 ;
} else {
if ( V_192 >= 0 )
F_108 ( V_202 , V_51 ) ;
if ( V_11 == - V_206 ) {
if ( V_187 != V_72 )
F_68 ( V_187 ) ;
return V_207 ;
} else
goto V_197;
}
F_112 ( V_2 ) ;
if ( V_7 -> V_155 . V_156 )
V_7 -> V_157 . V_208 += F_71 () -
V_7 -> V_157 . V_200 ;
return V_11 ;
V_197:
V_7 -> V_147 . V_209 ++ ;
V_7 -> V_147 . V_210 ++ ;
if ( ( V_187 != V_72 ) && V_187 )
F_68 ( V_187 ) ;
F_68 ( V_72 ) ;
F_112 ( V_2 ) ;
return V_205 ;
}
static int F_113 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_11 = 0 ;
F_15 ( V_7 , 4 , L_45 ) ;
if ( V_7 -> V_13 == V_14 )
return V_11 ;
if ( V_7 -> V_13 != V_15 )
return - V_12 ;
if ( ( V_7 -> V_16 . type != V_17 ) &&
( ! ( V_7 -> V_16 . V_118 & V_119 ) ) ) {
F_15 ( V_7 , 4 , L_46 ) ;
return - V_18 ;
}
V_7 -> V_47 . V_13 = V_116 ;
V_7 -> V_13 = V_14 ;
F_114 ( V_2 ) ;
if ( F_115 ( V_7 -> V_47 . V_162 , 0 ) >= 0 ) {
F_116 ( & V_7 -> V_151 ) ;
F_78 ( & V_7 -> V_151 ) ;
} else
V_11 = - V_211 ;
return V_11 ;
}
static int F_117 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_15 ( V_7 , 5 , L_47 ) ;
if ( F_44 ( V_7 , V_108 ) ) {
F_15 ( V_7 , 3 , L_48 ) ;
return - V_182 ;
}
return F_113 ( V_2 ) ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_15 ( V_7 , 4 , L_49 ) ;
F_118 ( V_2 ) ;
if ( V_7 -> V_13 == V_14 ) {
V_7 -> V_13 = V_15 ;
F_119 ( & V_7 -> V_151 ) ;
}
return 0 ;
}
static int F_120 ( struct V_212 * V_171 )
{
struct V_6 * V_7 = F_121 ( & V_171 -> V_2 ) ;
F_122 ( & V_7 -> V_109 ) ;
F_122 ( & V_7 -> V_66 ) ;
V_7 -> V_155 . V_213 = 1 ;
V_7 -> V_16 . V_214 = 0 ;
return 0 ;
}
static void F_123 ( struct V_212 * V_215 )
{
struct V_6 * V_7 = F_121 ( & V_215 -> V_2 ) ;
F_50 ( V_7 , 0 , 1 ) ;
F_124 ( V_7 -> V_216 , F_94 ( V_7 , 0xffffffff ) == 0 ) ;
if ( V_215 -> V_13 == V_217 )
F_125 ( V_215 ) ;
if ( V_7 -> V_2 ) {
F_126 ( V_7 -> V_2 ) ;
V_7 -> V_2 = NULL ;
}
return;
}
static int F_127 ( struct V_6 * V_7 )
{
switch ( V_7 -> V_16 . type ) {
case V_177 :
V_7 -> V_2 = F_128 ( 0 , L_50 , V_218 ) ;
break;
case V_17 :
V_7 -> V_2 = F_128 ( 0 , L_51 , V_218 ) ;
V_7 -> V_2 -> V_35 |= V_219 ;
break;
default:
V_7 -> V_2 = F_129 ( 0 ) ;
}
if ( ! V_7 -> V_2 )
return - V_12 ;
V_7 -> V_2 -> V_8 = V_7 ;
V_7 -> V_2 -> V_220 = V_221 ;
V_7 -> V_2 -> V_222 = V_7 -> V_16 . V_223 ;
V_7 -> V_2 -> V_224 = & V_225 ;
if ( V_7 -> V_16 . type != V_17 )
F_130 ( V_7 -> V_2 , & V_226 ) ;
else
F_130 ( V_7 -> V_2 , & V_227 ) ;
V_7 -> V_2 -> V_228 |= V_229 ;
V_7 -> V_16 . V_230 = 1 ;
F_86 ( V_7 ) ;
F_131 ( V_7 -> V_2 , & V_7 -> V_171 -> V_2 ) ;
F_132 ( V_7 -> V_2 , & V_7 -> V_151 , F_69 , V_231 ) ;
return F_133 ( V_7 -> V_2 ) ;
}
static int F_134 ( struct V_212 * V_171 , int V_113 )
{
struct V_6 * V_7 = F_121 ( & V_171 -> V_2 ) ;
int V_11 = 0 ;
enum V_232 V_233 ;
F_61 ( ! V_7 ) ;
F_135 ( & V_7 -> V_234 ) ;
F_135 ( & V_7 -> V_235 ) ;
F_48 ( V_114 , 2 , L_52 ) ;
F_49 ( V_114 , 2 , & V_7 , sizeof( void * ) ) ;
V_233 = V_7 -> V_13 ;
V_11 = F_136 ( V_7 ) ;
if ( V_11 ) {
F_87 ( V_114 , 2 , L_53 , V_11 ) ;
V_11 = - V_12 ;
goto V_236;
}
if ( ! V_7 -> V_2 && F_127 ( V_7 ) ) {
V_11 = - V_12 ;
goto V_236;
}
if ( V_7 -> V_16 . type != V_17 )
F_83 ( V_7 , & V_7 -> V_2 -> V_174 [ 0 ] ) ;
if ( F_137 ( V_7 , V_237 ) ) {
if ( V_7 -> V_16 . V_214 &&
F_138 ( V_7 , V_238 ) )
V_7 -> V_16 . V_214 = 0 ;
} else
V_7 -> V_16 . V_214 = 0 ;
V_7 -> V_13 = V_120 ;
memset ( & V_7 -> V_128 , 0 , sizeof( struct V_239 ) ) ;
F_139 ( V_7 ) ;
F_48 ( V_114 , 2 , L_54 ) ;
V_11 = F_140 ( V_7 ) ;
if ( V_11 ) {
F_87 ( V_114 , 2 , L_39 , V_11 ) ;
if ( V_11 == 0xe080 ) {
F_81 ( & V_7 -> V_171 -> V_2 ,
L_55 ) ;
V_7 -> V_195 = 0 ;
goto V_240;
}
V_11 = - V_12 ;
goto V_236;
} else
V_7 -> V_195 = 1 ;
V_240:
if ( ( V_7 -> V_16 . type == V_23 ) ||
( V_7 -> V_16 . type == V_25 ) )
F_141 ( V_7 ) ;
if ( V_7 -> V_16 . type != V_17 &&
V_7 -> V_16 . type != V_24 )
F_42 ( V_7 ) ;
F_118 ( V_7 -> V_2 ) ;
V_11 = F_142 ( V_7 ) ;
if ( V_11 ) {
F_87 ( V_114 , 2 , L_56 , V_11 ) ;
V_11 = - V_12 ;
goto V_236;
}
V_7 -> V_13 = V_15 ;
if ( V_7 -> V_195 )
F_143 ( V_7 -> V_2 ) ;
else
F_144 ( V_7 -> V_2 ) ;
F_50 ( V_7 , 0xffffffff , 0 ) ;
if ( V_233 == V_241 ) {
if ( V_113 &&
V_7 -> V_16 . type != V_17 ) {
F_113 ( V_7 -> V_2 ) ;
} else {
F_52 () ;
F_145 ( V_7 -> V_2 ) ;
F_54 () ;
}
F_46 ( V_7 -> V_2 ) ;
}
F_146 ( & V_171 -> V_2 . V_242 , V_243 ) ;
F_147 ( & V_7 -> V_235 ) ;
F_147 ( & V_7 -> V_234 ) ;
return 0 ;
V_236:
F_47 ( V_7 , 0 ) ;
F_148 ( F_149 ( V_7 ) ) ;
F_148 ( F_150 ( V_7 ) ) ;
F_148 ( F_13 ( V_7 ) ) ;
if ( V_233 == V_241 )
V_7 -> V_13 = V_241 ;
else
V_7 -> V_13 = V_121 ;
F_147 ( & V_7 -> V_235 ) ;
F_147 ( & V_7 -> V_234 ) ;
return V_11 ;
}
static int F_151 ( struct V_212 * V_171 )
{
return F_134 ( V_171 , 0 ) ;
}
static int F_152 ( struct V_212 * V_215 ,
int V_113 )
{
struct V_6 * V_7 = F_121 ( & V_215 -> V_2 ) ;
int V_11 = 0 , V_244 = 0 , V_245 = 0 ;
enum V_232 V_233 ;
F_135 ( & V_7 -> V_234 ) ;
F_135 ( & V_7 -> V_235 ) ;
F_48 ( V_114 , 3 , L_57 ) ;
F_49 ( V_114 , 3 , & V_7 , sizeof( void * ) ) ;
if ( V_7 -> V_2 && F_153 ( V_7 -> V_2 ) )
F_144 ( V_7 -> V_2 ) ;
V_233 = V_7 -> V_13 ;
if ( ( ! V_113 && V_7 -> V_16 . V_214 ) || V_7 -> V_16 . V_214 == 2 ) {
F_138 ( V_7 , V_246 ) ;
V_7 -> V_16 . V_214 = 1 ;
}
F_47 ( V_7 , V_113 ) ;
V_11 = F_148 ( F_149 ( V_7 ) ) ;
V_244 = F_148 ( F_150 ( V_7 ) ) ;
V_245 = F_148 ( F_13 ( V_7 ) ) ;
if ( ! V_11 )
V_11 = ( V_244 ) ? V_244 : V_245 ;
if ( V_11 )
F_87 ( V_114 , 2 , L_39 , V_11 ) ;
if ( V_233 == V_14 )
V_7 -> V_13 = V_241 ;
F_146 ( & V_215 -> V_2 . V_242 , V_243 ) ;
F_147 ( & V_7 -> V_235 ) ;
F_147 ( & V_7 -> V_234 ) ;
return 0 ;
}
static int F_125 ( struct V_212 * V_215 )
{
return F_152 ( V_215 , 0 ) ;
}
static int F_154 ( void * V_247 )
{
struct V_6 * V_7 ;
int V_11 = 0 ;
V_7 = (struct V_6 * ) V_247 ;
F_15 ( V_7 , 2 , L_58 ) ;
if ( ! F_155 ( V_7 , V_108 ) )
return 0 ;
F_15 ( V_7 , 2 , L_59 ) ;
F_81 ( & V_7 -> V_171 -> V_2 ,
L_60 ) ;
F_152 ( V_7 -> V_171 , 1 ) ;
V_11 = F_134 ( V_7 -> V_171 , 1 ) ;
if ( ! V_11 )
F_82 ( & V_7 -> V_171 -> V_2 ,
L_61 ) ;
else {
F_52 () ;
F_53 ( V_7 -> V_2 ) ;
F_54 () ;
F_81 ( & V_7 -> V_171 -> V_2 , L_62
L_63 ) ;
}
F_156 ( V_7 , V_108 ) ;
F_157 ( V_7 , V_108 ) ;
return 0 ;
}
static int T_3 F_158 ( void )
{
F_159 ( L_64 ) ;
return 0 ;
}
static void T_4 F_160 ( void )
{
F_159 ( L_65 ) ;
}
static void F_161 ( struct V_212 * V_171 )
{
struct V_6 * V_7 = F_121 ( & V_171 -> V_2 ) ;
F_50 ( V_7 , 0 , 1 ) ;
if ( ( V_171 -> V_13 == V_217 ) && V_7 -> V_16 . V_214 )
F_138 ( V_7 , V_246 ) ;
F_56 ( V_7 , 0 ) ;
F_57 ( V_7 ) ;
}
static int F_162 ( struct V_212 * V_171 )
{
struct V_6 * V_7 = F_121 ( & V_171 -> V_2 ) ;
if ( V_7 -> V_2 )
F_163 ( V_7 -> V_2 ) ;
F_50 ( V_7 , 0 , 1 ) ;
F_124 ( V_7 -> V_216 , F_94 ( V_7 , 0xffffffff ) == 0 ) ;
if ( V_171 -> V_13 == V_248 )
return 0 ;
if ( V_7 -> V_13 == V_14 ) {
if ( V_7 -> V_16 . V_214 )
F_138 ( V_7 , V_246 ) ;
F_152 ( V_7 -> V_171 , 1 ) ;
} else
F_152 ( V_7 -> V_171 , 0 ) ;
return 0 ;
}
static int F_164 ( struct V_212 * V_171 )
{
struct V_6 * V_7 = F_121 ( & V_171 -> V_2 ) ;
int V_11 = 0 ;
if ( V_171 -> V_13 == V_248 )
goto V_167;
if ( V_7 -> V_13 == V_241 ) {
V_11 = F_134 ( V_7 -> V_171 , 1 ) ;
if ( V_11 ) {
F_52 () ;
F_53 ( V_7 -> V_2 ) ;
F_54 () ;
}
} else
V_11 = F_134 ( V_7 -> V_171 , 0 ) ;
V_167:
F_50 ( V_7 , 0xffffffff , 0 ) ;
if ( V_7 -> V_2 )
F_165 ( V_7 -> V_2 ) ;
if ( V_11 )
F_81 ( & V_7 -> V_171 -> V_2 , L_62
L_63 ) ;
return V_11 ;
}
static int F_166 ( struct V_6 * V_7 , int V_88 ,
struct V_100 * V_101 )
{
unsigned long V_35 ;
int V_11 = 0 ;
F_15 ( V_7 , 5 , L_66 ) ;
F_124 ( V_7 -> V_216 ,
F_167 ( & V_7 -> V_117 . V_249 , 0 , 1 ) == 0 ) ;
F_168 ( V_7 , V_88 , V_101 ) ;
F_15 ( V_7 , 6 , L_67 ) ;
F_169 ( F_170 ( V_7 -> V_117 . V_162 ) , V_35 ) ;
V_11 = F_171 ( V_7 -> V_117 . V_162 , & V_7 -> V_117 . V_250 ,
( V_251 ) V_101 , 0 , 0 ) ;
F_172 ( F_170 ( V_7 -> V_117 . V_162 ) , V_35 ) ;
if ( V_11 ) {
F_16 ( 2 , L_68
L_69 , V_11 ) ;
F_6 ( V_7 , 2 , L_70 , V_11 ) ;
F_173 ( V_101 -> V_252 , V_101 ) ;
F_174 ( & V_7 -> V_117 . V_249 , 0 ) ;
F_175 ( & V_7 -> V_216 ) ;
}
return V_11 ;
}
static int F_176 ( struct V_6 * V_7 ,
struct V_100 * V_101 , int V_253 )
{
T_5 V_254 , V_255 ;
F_15 ( V_7 , 4 , L_71 ) ;
F_177 ( V_7 , V_101 , V_256 ) ;
V_254 = ( T_5 ) ( V_103 + V_253 ) ;
V_255 = ( T_5 ) V_253 ;
memcpy ( F_178 ( V_101 -> V_47 ) , & V_254 , 2 ) ;
memcpy ( F_179 ( V_101 -> V_47 ) , & V_255 , 2 ) ;
memcpy ( F_180 ( V_101 -> V_47 ) , & V_255 , 2 ) ;
memcpy ( F_181 ( V_101 -> V_47 ) , & V_255 , 2 ) ;
return F_166 ( V_7 , V_254 , V_101 ) ;
}
int F_182 ( struct V_1 * V_2 , void * V_47 , int V_253 )
{
struct V_100 * V_101 ;
struct V_6 * V_7 ;
int V_11 ;
if ( ! V_2 )
return - V_12 ;
V_7 = V_2 -> V_8 ;
if ( ! V_7 )
return - V_12 ;
F_15 ( V_7 , 2 , L_72 ) ;
if ( ( V_7 -> V_13 != V_14 ) &&
( V_7 -> V_13 != V_15 ) )
return - V_12 ;
V_101 = F_183 ( & V_7 -> V_117 ) ;
memcpy ( V_101 -> V_47 + V_103 , V_47 , V_253 ) ;
V_11 = F_176 ( V_7 , V_101 , V_253 ) ;
return V_11 ;
}
int F_184 ( unsigned char * V_39 , struct V_1 * * V_2 ,
int (* F_185)( struct V_1 * , void * ) ,
int (* V_144)( struct V_71 * ) )
{
struct V_6 * V_7 ;
* V_2 = F_11 ( V_39 ) ;
if ( * V_2 == NULL )
return - V_12 ;
V_7 = ( * V_2 ) -> V_8 ;
if ( ! V_7 )
return - V_12 ;
F_15 ( V_7 , 2 , L_73 ) ;
if ( ( F_185 == NULL ) || ( V_144 == NULL ) )
return - V_30 ;
V_7 -> V_143 . F_185 = F_185 ;
V_7 -> V_143 . V_144 = V_144 ;
return 0 ;
}
void F_186 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
if ( ! V_2 )
return;
V_7 = V_2 -> V_8 ;
if ( ! V_7 )
return;
F_15 ( V_7 , 2 , L_74 ) ;
V_7 -> V_143 . F_185 = NULL ;
V_7 -> V_143 . V_144 = NULL ;
return;
}
