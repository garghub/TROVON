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
struct V_71 * V_72 , int V_77 )
{
struct V_78 * V_79 = (struct V_78 * ) F_35 ( V_72 ) ;
memset ( V_51 , 0 , sizeof( struct V_76 ) ) ;
V_51 -> V_51 . V_80 . V_81 = V_82 ;
if ( V_77 == V_75 )
V_51 -> V_51 . V_80 . V_35 [ 2 ] |= V_83 ;
else if ( V_77 == V_74 )
V_51 -> V_51 . V_80 . V_35 [ 2 ] |= V_84 ;
else
V_51 -> V_51 . V_80 . V_35 [ 2 ] |= V_85 ;
V_51 -> V_51 . V_80 . V_86 = V_72 -> V_87 - V_88 ;
if ( V_79 -> V_89 == F_36 ( V_90 ) ) {
V_51 -> V_51 . V_80 . V_35 [ 2 ] |= V_91 ;
V_51 -> V_51 . V_80 . V_92 = F_37 ( V_79 -> V_93 ) ;
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
L_11 , V_5 -> V_47 . V_94 . V_92 ,
F_17 ( V_7 ) , V_5 -> V_51 . V_52 ) ;
F_6 ( V_7 , 2 , L_12 , V_5 -> V_51 . V_95 ) ;
F_6 ( V_7 , 2 , L_13 , V_5 -> V_51 . V_52 ) ;
}
return 0 ;
}
static int F_39 ( struct V_6 * V_7 , T_1 V_96 ,
enum V_97 V_98 )
{
struct V_48 * V_5 ;
struct V_99 * V_100 ;
F_6 ( V_7 , 4 , L_14 , V_98 ) ;
V_100 = F_40 ( V_7 , V_98 , V_101 ) ;
V_5 = (struct V_48 * ) ( V_100 -> V_47 + V_102 ) ;
V_5 -> V_47 . V_94 . V_92 = V_96 ;
return F_41 ( V_7 , V_100 ,
F_38 , NULL ) ;
}
static void F_42 ( struct V_6 * V_7 )
{
struct V_103 * V_81 ;
F_15 ( V_7 , 3 , L_15 ) ;
F_27 ( & V_7 -> V_104 ) ;
F_9 (id, &card->vid_list, list) {
F_39 ( V_7 , V_81 -> V_105 , V_106 ) ;
}
F_30 ( & V_7 -> V_104 ) ;
}
static int F_43 ( struct V_1 * V_2 ,
T_3 V_107 , T_4 V_105 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_103 * V_81 ;
F_6 ( V_7 , 4 , L_16 , V_105 ) ;
if ( ! V_105 )
return 0 ;
if ( V_7 -> V_16 . type == V_24 ) {
F_15 ( V_7 , 3 , L_17 ) ;
return 0 ;
}
if ( F_44 ( V_7 , V_108 ) ) {
F_15 ( V_7 , 3 , L_18 ) ;
return 0 ;
}
V_81 = F_23 ( sizeof( struct V_103 ) , V_59 ) ;
if ( V_81 ) {
V_81 -> V_105 = V_105 ;
F_39 ( V_7 , V_105 , V_106 ) ;
F_27 ( & V_7 -> V_104 ) ;
F_24 ( & V_81 -> V_65 , & V_7 -> V_109 ) ;
F_30 ( & V_7 -> V_104 ) ;
} else {
return - V_110 ;
}
return 0 ;
}
static int F_45 ( struct V_1 * V_2 ,
T_3 V_107 , T_4 V_105 )
{
struct V_103 * V_81 , * V_111 = NULL ;
struct V_6 * V_7 = V_2 -> V_8 ;
F_6 ( V_7 , 4 , L_19 , V_105 ) ;
if ( V_7 -> V_16 . type == V_24 ) {
F_15 ( V_7 , 3 , L_20 ) ;
return 0 ;
}
if ( F_44 ( V_7 , V_108 ) ) {
F_15 ( V_7 , 3 , L_21 ) ;
return 0 ;
}
F_27 ( & V_7 -> V_104 ) ;
F_9 (id, &card->vid_list, list) {
if ( V_81 -> V_105 == V_105 ) {
F_29 ( & V_81 -> V_65 ) ;
V_111 = V_81 ;
break;
}
}
F_30 ( & V_7 -> V_104 ) ;
if ( V_111 ) {
F_39 ( V_7 , V_105 , V_112 ) ;
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
unsigned int V_87 ;
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
switch ( V_51 -> V_51 . V_80 . V_81 ) {
case V_82 :
V_72 -> V_132 = V_133 ;
V_72 -> V_134 = F_63 ( V_72 , V_72 -> V_2 ) ;
V_72 -> V_135 = V_136 ;
if ( V_72 -> V_134 == F_64 ( V_137 ) )
* ( ( V_138 * ) V_72 -> V_139 ) = ++ V_7 -> V_140 . V_141 ;
V_87 = V_72 -> V_87 ;
F_65 ( V_72 ) ;
break;
case V_142 :
if ( V_7 -> V_16 . type == V_17 ) {
F_66 ( V_72 , sizeof( struct V_76 ) ) ;
F_67 ( V_72 , V_51 ,
sizeof( struct V_76 ) ) ;
V_87 = V_72 -> V_87 ;
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
V_7 -> V_147 . V_149 += V_87 ;
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
enum V_97 V_98 ,
int (* F_79) ( struct V_6 * ,
struct V_45 * ,
unsigned long ) )
{
struct V_48 * V_5 ;
struct V_99 * V_100 ;
F_15 ( V_7 , 2 , L_25 ) ;
V_100 = F_40 ( V_7 , V_98 , V_101 ) ;
V_5 = (struct V_48 * ) ( V_100 -> V_47 + V_102 ) ;
V_5 -> V_47 . V_50 . V_169 = V_61 ;
memcpy ( & V_5 -> V_47 . V_50 . V_49 , V_49 , V_61 ) ;
return F_41 ( V_7 , V_100 , F_79 , NULL ) ;
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
if ( F_89 ( V_7 , V_177 ) ) {
V_11 = F_90 ( V_7 ) ;
if ( V_11 ) {
F_16 ( 2 , L_36
L_37 ,
F_88 ( V_7 ) , V_11 ) ;
}
}
if ( V_7 -> V_16 . type == V_178 ||
V_7 -> V_16 . type == V_24 ||
V_7 -> V_16 . type == V_25 ||
V_7 -> V_16 . V_26 ) {
V_11 = F_91 ( V_7 ) ;
if ( V_11 ) {
F_16 ( 2 , L_38
L_39 , F_88 ( V_7 ) , V_11 ) ;
F_87 ( V_114 , 2 , L_40 , V_11 ) ;
return V_11 ;
}
F_49 ( V_114 , 2 , V_7 -> V_2 -> V_174 , V_61 ) ;
} else {
F_92 ( V_7 -> V_2 -> V_174 ) ;
memcpy ( V_7 -> V_2 -> V_174 , V_176 , 3 ) ;
}
return 0 ;
}
static int F_93 ( struct V_1 * V_2 , void * V_179 )
{
struct V_180 * V_181 = V_179 ;
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
F_94 ( V_7 , 3 , V_181 -> V_182 , V_61 ) ;
if ( F_44 ( V_7 , V_108 ) ) {
F_15 ( V_7 , 3 , L_44 ) ;
return - V_183 ;
}
V_11 = F_85 ( V_7 , & V_7 -> V_2 -> V_174 [ 0 ] ) ;
if ( ! V_11 || ( V_11 == V_184 ) )
V_11 = F_83 ( V_7 , V_181 -> V_182 ) ;
return V_11 ? - V_30 : 0 ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_185 * V_186 ;
if ( V_7 -> V_16 . type == V_17 )
return ;
F_15 ( V_7 , 3 , L_45 ) ;
if ( F_95 ( V_7 , V_108 ) &&
( V_7 -> V_13 != V_14 ) )
return;
F_26 ( V_7 , 1 ) ;
F_27 ( & V_7 -> V_69 ) ;
F_96 (ha, dev)
F_22 ( V_7 , V_186 -> V_181 , 0 ) ;
F_97 (ha, dev)
F_22 ( V_7 , V_186 -> V_181 , 1 ) ;
F_30 ( & V_7 -> V_69 ) ;
if ( ! F_98 ( V_7 , V_187 ) )
return;
F_99 ( V_7 ) ;
}
static int F_100 ( struct V_71 * V_72 , struct V_1 * V_2 )
{
int V_11 ;
struct V_76 * V_51 = NULL ;
int V_188 = 0 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_71 * V_189 = V_72 ;
int V_77 = F_31 ( V_7 , V_72 ) ;
struct V_190 * V_191 ;
int V_192 = V_72 -> V_87 ;
int V_193 = - 1 ;
int V_194 = 0 ;
int V_195 = 0 ;
if ( V_7 -> V_125 . V_196 || ( V_77 &&
V_7 -> V_16 . V_197 ) )
V_191 = V_7 -> V_125 . V_198 [ F_101 ( V_7 , V_72 ,
F_102 ( V_72 ) , V_77 ) ] ;
else
V_191 = V_7 -> V_125 . V_198 [ V_7 -> V_125 . V_199 ] ;
if ( ( V_7 -> V_13 != V_14 ) || ! V_7 -> V_200 ) {
V_7 -> V_147 . V_201 ++ ;
goto V_202;
}
if ( ( V_7 -> V_16 . type == V_17 ) &&
( V_72 -> V_134 == F_64 ( V_203 ) ) )
goto V_202;
if ( V_7 -> V_155 . V_156 ) {
V_7 -> V_157 . V_204 ++ ;
V_7 -> V_157 . V_205 = F_71 () ;
}
F_103 ( V_2 ) ;
if ( V_7 -> V_16 . type == V_17 )
V_51 = (struct V_76 * ) V_72 -> V_47 ;
else {
if ( V_7 -> V_16 . type == V_178 ) {
V_189 = V_72 ;
V_193 = V_206 ;
V_195 = V_206 ;
V_51 = F_104 ( V_207 ,
V_59 ) ;
if ( ! V_51 )
goto V_202;
V_194 ++ ;
F_105 ( V_189 ) ;
F_34 ( V_7 , V_51 , V_189 , V_77 ) ;
V_51 -> V_51 . V_80 . V_86 = V_189 -> V_87 ;
memcpy ( ( ( char * ) V_51 ) + sizeof( struct V_76 ) ,
F_35 ( V_189 ) , V_206 ) ;
} else {
V_189 = F_106 ( V_72 ,
sizeof( struct V_76 ) ) ;
if ( ! V_189 )
goto V_202;
V_51 = (struct V_76 * ) F_66 ( V_189 ,
sizeof( struct V_76 ) ) ;
F_107 ( V_189 , sizeof( struct V_76 ) ) ;
F_34 ( V_7 , V_51 , V_189 , V_77 ) ;
}
}
V_188 = F_108 ( V_7 , V_189 , V_194 ) ;
if ( ! V_188 ) {
if ( V_193 >= 0 )
F_109 ( V_207 , V_51 ) ;
goto V_202;
}
if ( V_7 -> V_16 . type != V_178 ) {
if ( F_110 ( V_189 , & V_51 ,
sizeof( struct V_208 ) ) )
goto V_202;
V_11 = F_111 ( V_7 , V_191 , V_189 , V_51 ,
V_188 ) ;
} else
V_11 = F_112 ( V_7 , V_191 , V_189 , V_51 ,
V_188 , V_193 , V_195 ) ;
if ( ! V_11 ) {
V_7 -> V_147 . V_209 ++ ;
V_7 -> V_147 . V_192 += V_192 ;
if ( V_189 != V_72 )
F_68 ( V_72 ) ;
V_11 = V_210 ;
} else {
if ( V_193 >= 0 )
F_109 ( V_207 , V_51 ) ;
if ( V_11 == - V_211 ) {
if ( V_189 != V_72 )
F_68 ( V_189 ) ;
return V_212 ;
} else
goto V_202;
}
F_113 ( V_2 ) ;
if ( V_7 -> V_155 . V_156 )
V_7 -> V_157 . V_213 += F_71 () -
V_7 -> V_157 . V_205 ;
return V_11 ;
V_202:
V_7 -> V_147 . V_214 ++ ;
V_7 -> V_147 . V_215 ++ ;
if ( ( V_189 != V_72 ) && V_189 )
F_68 ( V_189 ) ;
F_68 ( V_72 ) ;
F_113 ( V_2 ) ;
return V_210 ;
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
( ! ( V_7 -> V_16 . V_118 & V_119 ) ) ) {
F_15 ( V_7 , 4 , L_47 ) ;
return - V_18 ;
}
V_7 -> V_47 . V_13 = V_116 ;
V_7 -> V_13 = V_14 ;
F_115 ( V_2 ) ;
if ( F_116 ( V_7 -> V_47 . V_162 , 0 ) >= 0 ) {
F_117 ( & V_7 -> V_151 ) ;
F_78 ( & V_7 -> V_151 ) ;
} else
V_11 = - V_216 ;
return V_11 ;
}
static int F_118 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_15 ( V_7 , 5 , L_48 ) ;
if ( F_44 ( V_7 , V_108 ) ) {
F_15 ( V_7 , 3 , L_49 ) ;
return - V_183 ;
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
F_120 ( & V_7 -> V_151 ) ;
}
return 0 ;
}
static int F_121 ( struct V_217 * V_171 )
{
struct V_6 * V_7 = F_122 ( & V_171 -> V_2 ) ;
F_123 ( & V_171 -> V_2 ) ;
F_124 ( & V_7 -> V_109 ) ;
F_124 ( & V_7 -> V_66 ) ;
V_7 -> V_155 . V_218 = 1 ;
V_7 -> V_16 . V_219 = 0 ;
return 0 ;
}
static void F_125 ( struct V_217 * V_220 )
{
struct V_6 * V_7 = F_122 ( & V_220 -> V_2 ) ;
F_126 ( & V_220 -> V_2 ) ;
F_50 ( V_7 , 0 , 1 ) ;
F_127 ( V_7 -> V_221 , F_95 ( V_7 , 0xffffffff ) == 0 ) ;
if ( V_220 -> V_13 == V_222 )
F_128 ( V_220 ) ;
if ( V_7 -> V_2 ) {
F_129 ( V_7 -> V_2 ) ;
V_7 -> V_2 = NULL ;
}
return;
}
static int F_130 ( struct V_6 * V_7 )
{
switch ( V_7 -> V_16 . type ) {
case V_178 :
V_7 -> V_2 = F_131 ( 0 , L_51 , V_223 ) ;
break;
case V_17 :
V_7 -> V_2 = F_131 ( 0 , L_52 , V_223 ) ;
V_7 -> V_2 -> V_35 |= V_224 ;
break;
default:
V_7 -> V_2 = F_132 ( 0 ) ;
}
if ( ! V_7 -> V_2 )
return - V_12 ;
V_7 -> V_2 -> V_8 = V_7 ;
V_7 -> V_2 -> V_225 = V_226 ;
V_7 -> V_2 -> V_227 = V_7 -> V_16 . V_228 ;
V_7 -> V_2 -> V_229 = & V_230 ;
V_7 -> V_2 -> V_231 =
( V_7 -> V_16 . type != V_17 ) ?
& V_232 : & V_233 ;
V_7 -> V_2 -> V_234 |= V_235 ;
V_7 -> V_16 . V_236 = 1 ;
F_86 ( V_7 ) ;
F_133 ( V_7 -> V_2 , & V_7 -> V_171 -> V_2 ) ;
F_134 ( V_7 -> V_2 , & V_7 -> V_151 , F_69 , V_237 ) ;
return F_135 ( V_7 -> V_2 ) ;
}
static int F_136 ( struct V_217 * V_171 , int V_113 )
{
struct V_6 * V_7 = F_122 ( & V_171 -> V_2 ) ;
int V_11 = 0 ;
enum V_238 V_239 ;
F_137 ( & V_7 -> V_240 ) ;
F_137 ( & V_7 -> V_241 ) ;
F_48 ( V_114 , 2 , L_53 ) ;
F_49 ( V_114 , 2 , & V_7 , sizeof( void * ) ) ;
V_239 = V_7 -> V_13 ;
V_11 = F_138 ( V_7 ) ;
if ( V_11 ) {
F_87 ( V_114 , 2 , L_54 , V_11 ) ;
V_11 = - V_12 ;
goto V_242;
}
F_139 ( V_7 ) ;
if ( V_7 -> V_155 . V_243 . V_244 )
F_82 ( & V_7 -> V_171 -> V_2 ,
L_55 ) ;
F_140 ( V_7 ) ;
if ( ! V_7 -> V_2 && F_130 ( V_7 ) ) {
V_11 = - V_12 ;
goto V_242;
}
if ( V_7 -> V_16 . type != V_17 )
F_83 ( V_7 , & V_7 -> V_2 -> V_174 [ 0 ] ) ;
if ( F_141 ( V_7 , V_245 ) ) {
if ( V_7 -> V_16 . V_219 &&
F_142 ( V_7 , V_246 ) )
V_7 -> V_16 . V_219 = 0 ;
} else
V_7 -> V_16 . V_219 = 0 ;
F_143 ( V_7 ) ;
V_7 -> V_13 = V_120 ;
memset ( & V_7 -> V_128 , 0 , sizeof( struct V_247 ) ) ;
F_144 ( V_7 ) ;
F_48 ( V_114 , 2 , L_56 ) ;
V_11 = F_145 ( V_7 ) ;
if ( V_11 ) {
F_87 ( V_114 , 2 , L_40 , V_11 ) ;
if ( V_11 == 0xe080 ) {
F_81 ( & V_7 -> V_171 -> V_2 ,
L_57 ) ;
V_7 -> V_200 = 0 ;
goto V_248;
}
V_11 = - V_12 ;
goto V_242;
} else
V_7 -> V_200 = 1 ;
V_248:
if ( ( V_7 -> V_16 . type == V_23 ) ||
( V_7 -> V_16 . type == V_25 ) ) {
V_11 = F_146 ( V_7 , 0 ) ;
if ( V_11 ) {
V_11 = - V_12 ;
goto V_242;
}
}
if ( V_7 -> V_16 . type != V_17 &&
V_7 -> V_16 . type != V_24 )
F_42 ( V_7 ) ;
F_119 ( V_7 -> V_2 ) ;
V_11 = F_147 ( V_7 ) ;
if ( V_11 ) {
F_87 ( V_114 , 2 , L_58 , V_11 ) ;
V_11 = - V_12 ;
goto V_242;
}
V_7 -> V_13 = V_15 ;
if ( V_7 -> V_200 )
F_148 ( V_7 -> V_2 ) ;
else
F_149 ( V_7 -> V_2 ) ;
F_50 ( V_7 , 0xffffffff , 0 ) ;
if ( V_239 == V_249 ) {
if ( V_113 &&
V_7 -> V_16 . type != V_17 ) {
F_114 ( V_7 -> V_2 ) ;
} else {
F_52 () ;
F_150 ( V_7 -> V_2 ) ;
F_54 () ;
}
F_46 ( V_7 -> V_2 ) ;
}
F_151 ( & V_171 -> V_2 . V_250 , V_251 ) ;
F_152 ( & V_7 -> V_241 ) ;
F_152 ( & V_7 -> V_240 ) ;
return 0 ;
V_242:
F_47 ( V_7 , 0 ) ;
F_153 ( F_154 ( V_7 ) ) ;
F_153 ( F_155 ( V_7 ) ) ;
F_153 ( F_13 ( V_7 ) ) ;
F_156 ( F_154 ( V_7 ) ) ;
if ( V_239 == V_249 )
V_7 -> V_13 = V_249 ;
else
V_7 -> V_13 = V_121 ;
F_152 ( & V_7 -> V_241 ) ;
F_152 ( & V_7 -> V_240 ) ;
return V_11 ;
}
static int F_157 ( struct V_217 * V_171 )
{
return F_136 ( V_171 , 0 ) ;
}
static int F_158 ( struct V_217 * V_220 ,
int V_113 )
{
struct V_6 * V_7 = F_122 ( & V_220 -> V_2 ) ;
int V_11 = 0 , V_252 = 0 , V_253 = 0 ;
enum V_238 V_239 ;
F_137 ( & V_7 -> V_240 ) ;
F_137 ( & V_7 -> V_241 ) ;
F_48 ( V_114 , 3 , L_59 ) ;
F_49 ( V_114 , 3 , & V_7 , sizeof( void * ) ) ;
if ( V_7 -> V_2 && F_159 ( V_7 -> V_2 ) )
F_149 ( V_7 -> V_2 ) ;
V_239 = V_7 -> V_13 ;
if ( ( ! V_113 && V_7 -> V_16 . V_219 ) || V_7 -> V_16 . V_219 == 2 ) {
F_142 ( V_7 , V_254 ) ;
V_7 -> V_16 . V_219 = 1 ;
}
F_47 ( V_7 , V_113 ) ;
V_11 = F_153 ( F_154 ( V_7 ) ) ;
V_252 = F_153 ( F_155 ( V_7 ) ) ;
V_253 = F_153 ( F_13 ( V_7 ) ) ;
if ( ! V_11 )
V_11 = ( V_252 ) ? V_252 : V_253 ;
if ( V_11 )
F_87 ( V_114 , 2 , L_40 , V_11 ) ;
F_156 ( F_154 ( V_7 ) ) ;
if ( V_239 == V_14 )
V_7 -> V_13 = V_249 ;
F_151 ( & V_220 -> V_2 . V_250 , V_251 ) ;
F_152 ( & V_7 -> V_241 ) ;
F_152 ( & V_7 -> V_240 ) ;
return 0 ;
}
static int F_128 ( struct V_217 * V_220 )
{
return F_158 ( V_220 , 0 ) ;
}
static int F_160 ( void * V_255 )
{
struct V_6 * V_7 ;
int V_11 = 0 ;
V_7 = (struct V_6 * ) V_255 ;
F_15 ( V_7 , 2 , L_60 ) ;
if ( ! F_161 ( V_7 , V_108 ) )
return 0 ;
F_15 ( V_7 , 2 , L_61 ) ;
F_81 ( & V_7 -> V_171 -> V_2 ,
L_62 ) ;
F_162 ( V_7 ) ;
F_158 ( V_7 -> V_171 , 1 ) ;
V_11 = F_136 ( V_7 -> V_171 , 1 ) ;
if ( ! V_11 )
F_82 ( & V_7 -> V_171 -> V_2 ,
L_63 ) ;
else {
F_163 ( V_7 ) ;
F_81 ( & V_7 -> V_171 -> V_2 , L_64
L_65 ) ;
}
F_164 ( V_7 ) ;
F_165 ( V_7 , V_108 ) ;
F_166 ( V_7 , V_108 ) ;
return 0 ;
}
static int T_5 F_167 ( void )
{
F_168 ( L_66 ) ;
return 0 ;
}
static void T_6 F_169 ( void )
{
F_168 ( L_67 ) ;
}
static void F_170 ( struct V_217 * V_171 )
{
struct V_6 * V_7 = F_122 ( & V_171 -> V_2 ) ;
F_50 ( V_7 , 0 , 1 ) ;
if ( ( V_171 -> V_13 == V_222 ) && V_7 -> V_16 . V_219 )
F_142 ( V_7 , V_254 ) ;
F_56 ( V_7 , 0 ) ;
F_57 ( V_7 ) ;
F_156 ( F_154 ( V_7 ) ) ;
}
static int F_171 ( struct V_217 * V_171 )
{
struct V_6 * V_7 = F_122 ( & V_171 -> V_2 ) ;
if ( V_7 -> V_2 )
F_172 ( V_7 -> V_2 ) ;
F_50 ( V_7 , 0 , 1 ) ;
F_127 ( V_7 -> V_221 , F_95 ( V_7 , 0xffffffff ) == 0 ) ;
if ( V_171 -> V_13 == V_256 )
return 0 ;
if ( V_7 -> V_13 == V_14 ) {
if ( V_7 -> V_16 . V_219 )
F_142 ( V_7 , V_254 ) ;
F_158 ( V_7 -> V_171 , 1 ) ;
} else
F_158 ( V_7 -> V_171 , 0 ) ;
return 0 ;
}
static int F_173 ( struct V_217 * V_171 )
{
struct V_6 * V_7 = F_122 ( & V_171 -> V_2 ) ;
int V_11 = 0 ;
if ( V_171 -> V_13 == V_256 )
goto V_167;
if ( V_7 -> V_13 == V_249 ) {
V_11 = F_136 ( V_7 -> V_171 , 1 ) ;
if ( V_11 ) {
F_52 () ;
F_53 ( V_7 -> V_2 ) ;
F_54 () ;
}
} else
V_11 = F_136 ( V_7 -> V_171 , 0 ) ;
V_167:
F_50 ( V_7 , 0xffffffff , 0 ) ;
if ( V_7 -> V_2 )
F_174 ( V_7 -> V_2 ) ;
if ( V_11 )
F_81 ( & V_7 -> V_171 -> V_2 , L_64
L_65 ) ;
return V_11 ;
}
static int F_175 ( struct V_6 * V_7 ,
struct V_48 * V_5 )
{
switch ( V_5 -> V_51 . V_95 ) {
case V_257 :
if ( V_5 -> V_47 . V_243 . V_51 . V_258 ==
V_259 ) {
F_176 ( V_7 , V_5 ) ;
return 0 ;
} else
return 1 ;
case V_260 :
F_177 ( V_7 , V_5 ) ;
return 0 ;
default:
return 1 ;
}
}
static int F_178 ( struct V_6 * V_7 , int V_87 ,
struct V_99 * V_100 )
{
unsigned long V_35 ;
int V_11 = 0 ;
F_15 ( V_7 , 5 , L_68 ) ;
F_127 ( V_7 -> V_221 ,
F_179 ( & V_7 -> V_117 . V_261 , 0 , 1 ) == 0 ) ;
F_180 ( V_7 , V_87 , V_100 ) ;
F_15 ( V_7 , 6 , L_69 ) ;
F_181 ( F_182 ( V_7 -> V_117 . V_162 ) , V_35 ) ;
V_11 = F_183 ( V_7 -> V_117 . V_162 , & V_7 -> V_117 . V_262 ,
( V_263 ) V_100 , 0 , 0 ) ;
F_184 ( F_182 ( V_7 -> V_117 . V_162 ) , V_35 ) ;
if ( V_11 ) {
F_16 ( 2 , L_70
L_71 , V_11 ) ;
F_6 ( V_7 , 2 , L_72 , V_11 ) ;
F_185 ( V_100 -> V_264 , V_100 ) ;
F_186 ( & V_7 -> V_117 . V_261 , 0 ) ;
F_187 ( & V_7 -> V_221 ) ;
}
return V_11 ;
}
static int F_188 ( struct V_6 * V_7 ,
struct V_99 * V_100 , int V_265 )
{
T_4 V_266 , V_267 ;
F_15 ( V_7 , 4 , L_73 ) ;
F_189 ( V_7 , V_100 , V_268 ) ;
V_266 = ( T_4 ) ( V_102 + V_265 ) ;
V_267 = ( T_4 ) V_265 ;
memcpy ( F_190 ( V_100 -> V_47 ) , & V_266 , 2 ) ;
memcpy ( F_191 ( V_100 -> V_47 ) , & V_267 , 2 ) ;
memcpy ( F_192 ( V_100 -> V_47 ) , & V_267 , 2 ) ;
memcpy ( F_193 ( V_100 -> V_47 ) , & V_267 , 2 ) ;
return F_178 ( V_7 , V_266 , V_100 ) ;
}
int F_194 ( struct V_1 * V_2 , void * V_47 , int V_265 )
{
struct V_99 * V_100 ;
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
V_100 = F_195 ( & V_7 -> V_117 ) ;
memcpy ( V_100 -> V_47 + V_102 , V_47 , V_265 ) ;
V_11 = F_188 ( V_7 , V_100 , V_265 ) ;
return V_11 ;
}
int F_196 ( unsigned char * V_39 , struct V_1 * * V_2 ,
int (* F_197)( struct V_1 * , void * ) ,
int (* V_144)( struct V_71 * ) )
{
struct V_6 * V_7 ;
* V_2 = F_11 ( V_39 ) ;
if ( * V_2 == NULL )
return - V_12 ;
V_7 = ( * V_2 ) -> V_8 ;
if ( ! V_7 )
return - V_12 ;
F_15 ( V_7 , 2 , L_75 ) ;
if ( ( F_197 == NULL ) || ( V_144 == NULL ) )
return - V_30 ;
V_7 -> V_143 . F_197 = F_197 ;
V_7 -> V_143 . V_144 = V_144 ;
return 0 ;
}
void F_198 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
if ( ! V_2 )
return;
V_7 = V_2 -> V_8 ;
if ( ! V_7 )
return;
F_15 ( V_7 , 2 , L_76 ) ;
V_7 -> V_143 . F_197 = NULL ;
V_7 -> V_143 . V_144 = NULL ;
return;
}
static void F_199 ( struct V_6 * V_7 ,
enum V_269 V_270 ,
T_7 V_271 , struct V_272 * V_273 , struct V_274 * V_275 )
{
char V_276 [ 7 ] [ 32 ] ;
char * V_277 [ 8 ] ;
int V_96 = 0 ;
switch ( V_270 ) {
case V_278 :
snprintf ( V_276 [ V_96 ] , sizeof( V_276 [ V_96 ] ) , L_77 ,
( V_271 & V_279 )
? L_78 : L_79 ) ;
V_277 [ V_96 ] = V_276 [ V_96 ] ; V_96 ++ ;
if ( V_271 & V_280 ) {
snprintf ( V_276 [ V_96 ] , sizeof( V_276 [ V_96 ] ) , L_80 ,
V_275 -> V_281 ) ;
V_277 [ V_96 ] = V_276 [ V_96 ] ; V_96 ++ ;
}
if ( V_271 & V_282 ) {
snprintf ( V_276 [ V_96 ] , sizeof( V_276 [ V_96 ] ) , L_81 ,
& V_275 -> V_49 ) ;
V_277 [ V_96 ] = V_276 [ V_96 ] ; V_96 ++ ;
}
snprintf ( V_276 [ V_96 ] , sizeof( V_276 [ V_96 ] ) , L_82 ,
V_273 -> V_283 , V_273 -> V_284 , V_273 -> V_285 ) ;
V_277 [ V_96 ] = V_276 [ V_96 ] ; V_96 ++ ;
snprintf ( V_276 [ V_96 ] , sizeof( V_276 [ V_96 ] ) , L_83 , V_273 -> V_286 ) ;
V_277 [ V_96 ] = V_276 [ V_96 ] ; V_96 ++ ;
snprintf ( V_276 [ V_96 ] , sizeof( V_276 [ V_96 ] ) , L_84 ,
V_273 -> V_287 ) ;
V_277 [ V_96 ] = V_276 [ V_96 ] ; V_96 ++ ;
snprintf ( V_276 [ V_96 ] , sizeof( V_276 [ V_96 ] ) , L_85 , V_273 -> V_288 ) ;
V_277 [ V_96 ] = V_276 [ V_96 ] ; V_96 ++ ;
break;
case V_289 :
snprintf ( V_276 [ V_96 ] , sizeof( V_276 [ V_96 ] ) , L_86 ) ;
V_277 [ V_96 ] = V_276 [ V_96 ] ; V_96 ++ ;
break;
case V_290 :
snprintf ( V_276 [ V_96 ] , sizeof( V_276 [ V_96 ] ) , L_87 ) ;
V_277 [ V_96 ] = V_276 [ V_96 ] ; V_96 ++ ;
break;
}
V_277 [ V_96 ] = NULL ;
F_200 ( & V_7 -> V_171 -> V_2 . V_250 , V_251 , V_277 ) ;
}
static void F_201 ( struct V_291 * V_292 )
{
struct V_293 * V_47 =
F_70 ( V_292 , struct V_293 , V_294 ) ;
struct V_295 * V_296 = & V_47 -> V_297 . V_296 [ 0 ] ;
char V_298 [ 32 ] ;
char V_299 [ 32 ] ;
char V_300 [ 32 ] ;
char * V_277 [] = {
V_298 ,
V_299 ,
V_300 ,
NULL
} ;
F_137 ( & V_47 -> V_7 -> V_241 ) ;
V_47 -> V_7 -> V_155 . V_243 . V_301 = V_296 -> V_301 ;
F_152 ( & V_47 -> V_7 -> V_241 ) ;
snprintf ( V_298 , sizeof( V_298 ) , L_88 ) ;
snprintf ( V_299 , sizeof( V_299 ) , L_89 ,
( V_296 -> V_301 == V_302 ) ? L_90 :
( V_296 -> V_301 == V_303 ) ? L_91 :
( V_296 -> V_301 == V_304 ) ? L_92 :
L_93 ) ;
snprintf ( V_300 , sizeof( V_300 ) , L_94 ,
( V_296 -> V_13 == V_305 ) ? L_95 :
( V_296 -> V_13 == V_306 ) ? L_96 :
( V_296 -> V_13 == V_307 ) ? L_97 :
L_93 ) ;
F_200 ( & V_47 -> V_7 -> V_171 -> V_2 . V_250 ,
V_251 , V_277 ) ;
F_25 ( V_47 ) ;
}
static void F_176 ( struct V_6 * V_7 ,
struct V_48 * V_5 )
{
struct V_308 * V_297 =
& V_5 -> V_47 . V_243 . V_47 . V_309 ;
struct V_293 * V_47 ;
int V_310 ;
F_15 ( V_7 , 2 , L_98 ) ;
if ( V_297 -> V_311 != sizeof( struct V_295 ) ) {
F_6 ( V_7 , 2 , L_99 , V_297 -> V_311 ) ;
return;
}
V_310 = sizeof( struct V_295 ) * V_297 -> V_312 ;
V_47 = F_202 ( sizeof( struct V_293 ) + V_310 ,
V_59 ) ;
if ( ! V_47 ) {
F_15 ( V_7 , 2 , L_100 ) ;
return;
}
F_203 ( & V_47 -> V_294 , F_201 ) ;
V_47 -> V_7 = V_7 ;
memcpy ( & V_47 -> V_297 , V_297 ,
sizeof( struct V_308 ) + V_310 ) ;
F_204 ( V_313 , & V_47 -> V_294 ) ;
}
static void F_205 ( struct V_291 * V_292 )
{
struct V_314 * V_47 =
F_70 ( V_292 , struct V_314 , V_294 ) ;
int V_96 ;
if ( V_47 -> V_315 . V_316 ) {
F_82 ( & V_47 -> V_7 -> V_171 -> V_2 ,
L_101 ,
V_47 -> V_7 -> V_2 -> V_175 ,
( V_47 -> V_315 . V_316 == 0x01 )
? L_102
: ( V_47 -> V_315 . V_316 == 0x02 )
? L_103
: L_104 ) ;
F_137 ( & V_47 -> V_7 -> V_241 ) ;
V_47 -> V_7 -> V_155 . V_243 . V_317 = 0 ;
F_152 ( & V_47 -> V_7 -> V_241 ) ;
F_199 ( V_47 -> V_7 , V_289 ,
0 , NULL , NULL ) ;
} else
for ( V_96 = 0 ; V_96 < V_47 -> V_315 . V_312 ; V_96 ++ ) {
struct V_318 * V_296 =
& V_47 -> V_315 . V_296 [ V_96 ] ;
F_199 ( V_47 -> V_7 ,
V_278 ,
V_296 -> V_319 ,
& V_296 -> V_273 , & V_296 -> V_275 ) ;
}
F_25 ( V_47 ) ;
}
static void F_177 ( struct V_6 * V_7 ,
struct V_48 * V_5 )
{
struct V_320 * V_315 =
& V_5 -> V_47 . V_321 ;
struct V_314 * V_47 ;
int V_310 ;
F_15 ( V_7 , 2 , L_105 ) ;
if ( V_5 -> V_51 . V_52 != 0x0000 ) {
if ( V_5 -> V_51 . V_52 == 0x0010 ) {
if ( V_315 -> V_316 == 0x00 )
V_315 -> V_316 = 0xff ;
} else {
F_6 ( V_7 , 2 , L_106 ,
V_5 -> V_51 . V_52 ) ;
return;
}
}
V_310 = sizeof( struct V_318 ) *
V_315 -> V_312 ;
V_47 = F_202 ( sizeof( struct V_314 ) + V_310 ,
V_59 ) ;
if ( ! V_47 ) {
F_15 ( V_7 , 2 , L_107 ) ;
return;
}
F_203 ( & V_47 -> V_294 , F_205 ) ;
V_47 -> V_7 = V_7 ;
memcpy ( & V_47 -> V_315 , V_315 ,
sizeof( struct V_320 ) + V_310 ) ;
F_204 ( V_313 , & V_47 -> V_294 ) ;
}
static int F_206 ( struct V_6 * V_7 ,
struct V_322 * V_323 , enum V_324 V_325 )
{
int V_11 ;
switch ( V_323 -> V_326 ) {
case V_327 :
switch ( V_323 -> V_328 ) {
case 0x0000 :
V_11 = 0 ;
break;
case 0x0004 :
V_11 = - V_329 ;
break;
case 0x000C :
V_11 = - V_12 ;
F_207 ( & V_7 -> V_171 -> V_2 ,
L_108 ) ;
break;
case 0x0014 :
switch ( V_325 ) {
case V_330 :
V_11 = - V_331 ;
F_207 ( & V_7 -> V_171 -> V_2 ,
L_109 ) ;
break;
case V_332 :
V_11 = - V_211 ;
F_207 ( & V_7 -> V_171 -> V_2 ,
L_110 ) ;
break;
default:
V_11 = - V_216 ;
}
break;
case 0x0018 :
V_11 = - V_211 ;
F_207 ( & V_7 -> V_171 -> V_2 ,
L_111 ) ;
break;
case 0x001C :
V_11 = - V_331 ;
F_207 ( & V_7 -> V_171 -> V_2 ,
L_112 ) ;
break;
case 0x0024 :
V_11 = - V_211 ;
F_207 ( & V_7 -> V_171 -> V_2 ,
L_110 ) ;
break;
case 0x0020 :
V_11 = - V_333 ;
F_207 ( & V_7 -> V_171 -> V_2 ,
L_113 ) ;
break;
default:
V_11 = - V_216 ;
}
break;
case V_334 :
V_11 = - V_329 ;
break;
case V_335 :
V_11 = - V_329 ;
break;
default:
V_11 = - V_216 ;
}
if ( V_11 ) {
F_6 ( V_7 , 2 , L_114 , V_323 -> V_326 ) ;
F_6 ( V_7 , 2 , L_115 , V_323 -> V_328 ) ;
}
return V_11 ;
}
static int F_208 ( struct V_6 * V_7 ,
struct V_45 * V_46 , unsigned long V_47 )
{
struct V_48 * V_5 = (struct V_48 * ) V_47 ;
struct V_322 * V_323 = (struct V_322 * ) V_46 -> V_336 ;
F_15 ( V_7 , 2 , L_116 ) ;
V_323 -> V_326 = V_5 -> V_51 . V_52 ;
V_323 -> V_328 = V_5 -> V_47 . V_243 . V_51 . V_52 ;
if ( ( V_323 -> V_326 == 0 ) && ( V_323 -> V_328 == 0 ) ) {
V_323 -> V_47 . V_337 =
V_5 -> V_47 . V_243 . V_47 . V_338 . V_339 ;
} else {
V_323 -> V_47 . V_337 = 0 ;
}
return 0 ;
}
static void F_139 ( struct V_6 * V_7 )
{
struct V_99 * V_100 ;
struct V_48 * V_5 ;
struct V_322 V_323 ;
F_15 ( V_7 , 2 , L_117 ) ;
V_100 = F_40 ( V_7 , V_257 , 0 ) ;
V_5 = (struct V_48 * ) ( V_100 -> V_47 + V_102 ) ;
V_5 -> V_47 . V_243 . V_51 . V_340 =
sizeof( struct V_341 ) +
sizeof( struct V_342 ) ;
V_5 -> V_47 . V_243 . V_51 . V_258 =
V_343 ;
V_5 -> V_47 . V_243 . V_51 . V_344 = 1 ;
V_5 -> V_47 . V_243 . V_51 . V_345 = 1 ;
if ( F_41 ( V_7 , V_100 , F_208 ,
( void * ) & V_323 ) ||
F_206 ( V_7 , & V_323 ,
V_343 ) ) {
V_7 -> V_155 . V_243 . V_301 = V_302 ;
return;
}
V_7 -> V_155 . V_243 . V_244 = V_323 . V_47 . V_337 ;
}
static int F_209 ( struct V_6 * V_7 ,
struct V_45 * V_46 , unsigned long V_47 )
{
struct V_48 * V_5 = (struct V_48 * ) V_47 ;
struct V_346 * V_297 = & V_5 -> V_47 . V_243 . V_47 . V_347 ;
struct V_322 * V_323 = (struct V_322 * ) V_46 -> V_336 ;
F_15 ( V_7 , 2 , L_118 ) ;
V_323 -> V_326 = V_5 -> V_51 . V_52 ;
V_323 -> V_328 = V_5 -> V_47 . V_243 . V_51 . V_52 ;
if ( ( V_323 -> V_326 != 0 ) || ( V_323 -> V_328 != 0 ) )
return 0 ;
if ( V_297 -> V_311 != sizeof( struct V_295 ) ) {
V_323 -> V_328 = 0xffff ;
F_6 ( V_7 , 2 , L_119 , V_297 -> V_311 ) ;
return 0 ;
}
if ( V_297 -> V_312 > 0 ) {
if ( V_323 -> V_47 . V_297 . V_301 )
* V_323 -> V_47 . V_297 . V_301 = V_297 -> V_296 [ 0 ] . V_301 ;
if ( V_323 -> V_47 . V_297 . V_13 )
* V_323 -> V_47 . V_297 . V_13 = V_297 -> V_296 [ 0 ] . V_13 ;
}
return 0 ;
}
int F_210 ( struct V_6 * V_7 ,
enum V_348 * V_301 , enum V_349 * V_13 )
{
int V_11 = 0 ;
struct V_99 * V_100 ;
struct V_48 * V_5 ;
struct V_322 V_323 = {
. V_47 = {
. V_297 = {
. V_301 = V_301 ,
. V_13 = V_13 ,
} ,
} ,
} ;
F_15 ( V_7 , 2 , L_120 ) ;
if ( ! ( V_7 -> V_155 . V_243 . V_244 & V_350 ) )
return - V_34 ;
V_100 = F_40 ( V_7 , V_257 , 0 ) ;
V_5 = (struct V_48 * ) ( V_100 -> V_47 + V_102 ) ;
V_5 -> V_47 . V_243 . V_51 . V_340 =
sizeof( struct V_341 ) ;
V_5 -> V_47 . V_243 . V_51 . V_258 =
V_350 ;
V_5 -> V_47 . V_243 . V_51 . V_344 = 1 ;
V_5 -> V_47 . V_243 . V_51 . V_345 = 1 ;
V_11 = F_41 ( V_7 , V_100 , F_209 ,
( void * ) & V_323 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_206 ( V_7 , & V_323 , V_350 ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}
static int F_211 ( struct V_6 * V_7 ,
struct V_45 * V_46 , unsigned long V_47 )
{
struct V_48 * V_5 = (struct V_48 * ) V_47 ;
struct V_322 * V_323 = (struct V_322 * ) V_46 -> V_336 ;
F_15 ( V_7 , 2 , L_121 ) ;
V_323 -> V_326 = V_5 -> V_51 . V_52 ;
V_323 -> V_328 = V_5 -> V_47 . V_243 . V_51 . V_52 ;
return 0 ;
}
int F_212 ( struct V_6 * V_7 , enum V_348 V_301 )
{
int V_11 = 0 ;
int V_340 ;
struct V_99 * V_100 ;
struct V_48 * V_5 ;
struct V_322 V_323 ;
enum V_324 V_325 ;
F_15 ( V_7 , 2 , L_122 ) ;
switch ( V_301 ) {
case V_302 :
V_325 = V_351 ;
V_340 = sizeof( struct V_341 ) +
sizeof( struct V_352 ) ;
break;
case V_303 :
V_325 = V_330 ;
V_340 = sizeof( struct V_341 ) +
sizeof( struct V_353 ) ;
break;
case V_304 :
V_325 = V_332 ;
V_340 = sizeof( struct V_341 ) +
sizeof( struct V_354 ) ;
break;
default:
return - V_30 ;
}
if ( ! ( V_7 -> V_155 . V_243 . V_244 & V_325 ) )
return - V_34 ;
V_100 = F_40 ( V_7 , V_257 , 0 ) ;
V_5 = (struct V_48 * ) ( V_100 -> V_47 + V_102 ) ;
V_5 -> V_47 . V_243 . V_51 . V_340 = V_340 ;
V_5 -> V_47 . V_243 . V_51 . V_258 = V_325 ;
V_5 -> V_47 . V_243 . V_51 . V_344 = 1 ;
V_5 -> V_47 . V_243 . V_51 . V_345 = 1 ;
V_11 = F_41 ( V_7 , V_100 , F_211 ,
( void * ) & V_323 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_206 ( V_7 , & V_323 , V_325 ) ;
return V_11 ;
}
static int F_213 ( struct V_6 * V_7 , int V_355 , T_4 V_356 )
{
int V_11 ;
if ( V_355 == 0 )
switch ( V_356 ) {
case 0x0001 :
V_11 = 0 ;
break;
case 0x0004 :
case 0x0100 :
case 0x0106 :
V_11 = - V_329 ;
F_207 ( & V_7 -> V_171 -> V_2 ,
L_123 ) ;
break;
case 0x0107 :
V_11 = - V_357 ;
break;
default:
V_11 = - V_216 ;
}
else
V_11 = - V_216 ;
if ( V_11 ) {
F_6 ( V_7 , 2 , L_124 , V_355 ) ;
F_6 ( V_7 , 2 , L_125 , V_356 ) ;
}
return V_11 ;
}
static void F_214 ( void * V_358 ,
enum V_359 type , void * V_296 )
{
struct V_6 * V_7 = (struct V_6 * ) V_358 ;
struct V_360 * V_361 ;
T_7 V_271 ;
if ( type != V_362 ) {
F_61 ( 1 ) ;
return;
}
V_361 = (struct V_360 * ) V_296 ;
V_271 = V_282 ;
if ( V_361 -> V_275 . V_281 )
V_271 |= V_280 ;
F_199 ( V_7 , V_278 , V_271 ,
(struct V_272 * ) & V_361 -> V_363 ,
(struct V_274 * ) & V_361 -> V_275 ) ;
}
int F_215 ( struct V_6 * V_7 , int V_364 )
{
int V_11 ;
T_4 V_356 ;
struct V_365 * V_366 ;
struct V_367 V_368 ;
if ( ! V_7 )
return - V_30 ;
if ( ! V_7 -> V_155 . V_243 . V_244 )
return - V_34 ;
V_366 = F_154 ( V_7 ) ;
F_216 ( V_366 , & V_368 ) ;
if ( V_364 ) {
F_199 ( V_7 , V_290 , 0 , NULL , NULL ) ;
V_11 = F_217 ( V_368 , 1 , & V_356 ,
F_214 , V_7 ) ;
} else
V_11 = F_217 ( V_368 , 0 , & V_356 , NULL , NULL ) ;
return F_213 ( V_7 , V_11 , V_356 ) ;
}
