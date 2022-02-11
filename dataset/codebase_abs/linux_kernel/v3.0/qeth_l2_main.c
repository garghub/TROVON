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
default:
V_11 = - V_33 ;
}
if ( V_11 )
F_5 ( V_7 , 2 , L_1 , V_11 ) ;
return V_11 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
unsigned long V_34 ;
int V_11 = 0 ;
F_7 ( & V_35 . V_36 , V_34 ) ;
F_8 (card, &qeth_core_card_list.list, list) {
if ( V_7 -> V_2 == V_2 ) {
V_11 = V_37 ;
break;
}
}
F_9 ( & V_35 . V_36 , V_34 ) ;
return V_11 ;
}
static struct V_1 * F_10 ( unsigned char * V_38 )
{
struct V_6 * V_7 ;
struct V_1 * V_39 ;
T_1 V_40 ;
unsigned long V_34 ;
struct V_41 V_42 ;
V_39 = NULL ;
memcpy ( & V_40 , V_38 , 2 ) ;
F_7 ( & V_35 . V_36 , V_34 ) ;
F_8 (card, &qeth_core_card_list.list, list) {
F_11 ( F_12 ( V_7 ) , & V_42 ) ;
if ( V_42 . V_43 == V_40 ) {
V_39 = V_7 -> V_2 ;
break;
}
}
F_9 ( & V_35 . V_36 , V_34 ) ;
return V_39 ;
}
static int F_13 ( struct V_6 * V_7 ,
struct V_44 * V_45 ,
unsigned long V_46 )
{
struct V_47 * V_5 ;
T_2 * V_48 ;
F_14 ( V_7 , 2 , L_2 ) ;
V_5 = (struct V_47 * ) V_46 ;
V_48 = & V_5 -> V_46 . V_49 . V_48 [ 0 ] ;
if ( V_5 -> V_50 . V_51 == V_52 ) {
F_15 ( 2 , L_3 ,
V_48 , F_16 ( V_7 ) ) ;
V_5 -> V_50 . V_51 = 0 ;
}
if ( V_5 -> V_50 . V_51 )
F_15 ( 2 , L_4 ,
V_48 , F_16 ( V_7 ) , V_5 -> V_50 . V_51 ) ;
return 0 ;
}
static int F_17 ( struct V_6 * V_7 , T_2 * V_48 )
{
F_14 ( V_7 , 2 , L_5 ) ;
return F_18 ( V_7 , V_48 , V_53 ,
F_13 ) ;
}
static int F_19 ( struct V_6 * V_7 ,
struct V_44 * V_45 ,
unsigned long V_46 )
{
struct V_47 * V_5 ;
T_2 * V_48 ;
F_14 ( V_7 , 2 , L_6 ) ;
V_5 = (struct V_47 * ) V_46 ;
V_48 = & V_5 -> V_46 . V_49 . V_48 [ 0 ] ;
if ( V_5 -> V_50 . V_51 )
F_15 ( 2 , L_7 ,
V_48 , F_16 ( V_7 ) , V_5 -> V_50 . V_51 ) ;
return 0 ;
}
static int F_20 ( struct V_6 * V_7 , T_2 * V_48 )
{
F_14 ( V_7 , 2 , L_8 ) ;
return F_18 ( V_7 , V_48 , V_54 ,
F_19 ) ;
}
static void F_21 ( struct V_6 * V_7 , T_2 * V_48 , int V_55 )
{
struct V_56 * V_57 ;
int V_11 ;
V_57 = F_22 ( sizeof( struct V_56 ) , V_58 ) ;
if ( ! V_57 )
return;
memcpy ( V_57 -> V_59 , V_48 , V_60 ) ;
V_57 -> V_61 = V_60 ;
V_57 -> V_62 = V_55 ;
if ( V_55 ) {
V_11 = F_18 ( V_7 , V_48 , V_63 ,
NULL ) ;
} else {
V_11 = F_17 ( V_7 , V_48 ) ;
}
if ( ! V_11 )
F_23 ( & V_57 -> V_64 , & V_7 -> V_65 ) ;
else
F_24 ( V_57 ) ;
}
static void F_25 ( struct V_6 * V_7 , int V_66 )
{
struct V_56 * V_57 , * V_67 ;
F_26 ( & V_7 -> V_68 ) ;
F_27 (mc, tmp, &card->mc_list, list) {
if ( V_66 ) {
if ( V_57 -> V_62 )
F_18 ( V_7 , V_57 -> V_59 ,
V_69 , NULL ) ;
else
F_20 ( V_7 , V_57 -> V_59 ) ;
}
F_28 ( & V_57 -> V_64 ) ;
F_24 ( V_57 ) ;
}
F_29 ( & V_7 -> V_68 ) ;
}
static inline int F_30 ( struct V_6 * V_7 ,
struct V_70 * V_71 )
{
if ( V_7 -> V_16 . type == V_17 )
return V_72 ;
if ( F_31 ( V_71 -> V_46 ) )
return V_73 ;
if ( F_32 ( V_71 -> V_46 ) )
return V_74 ;
return V_72 ;
}
static void F_33 ( struct V_6 * V_7 , struct V_75 * V_50 ,
struct V_70 * V_71 , int V_76 , int V_77 )
{
struct V_78 * V_79 = (struct V_78 * ) F_34 ( V_71 ) ;
memset ( V_50 , 0 , sizeof( struct V_75 ) ) ;
V_50 -> V_50 . V_80 . V_81 = V_82 ;
if ( V_77 == V_74 )
V_50 -> V_50 . V_80 . V_34 [ 2 ] |= V_83 ;
else if ( V_77 == V_73 )
V_50 -> V_50 . V_80 . V_34 [ 2 ] |= V_84 ;
else
V_50 -> V_50 . V_80 . V_34 [ 2 ] |= V_85 ;
V_50 -> V_50 . V_80 . V_86 = V_71 -> V_87 - V_88 ;
if ( V_79 -> V_89 == F_35 ( V_90 ) ) {
V_50 -> V_50 . V_80 . V_34 [ 2 ] |= V_91 ;
V_50 -> V_50 . V_80 . V_92 = F_36 ( V_79 -> V_93 ) ;
}
}
static int F_37 ( struct V_6 * V_7 ,
struct V_44 * V_45 , unsigned long V_46 )
{
struct V_47 * V_5 ;
F_14 ( V_7 , 2 , L_9 ) ;
V_5 = (struct V_47 * ) V_46 ;
if ( V_5 -> V_50 . V_51 ) {
F_15 ( 2 , L_10
L_11 , V_5 -> V_46 . V_94 . V_92 ,
F_16 ( V_7 ) , V_5 -> V_50 . V_51 ) ;
F_5 ( V_7 , 2 , L_12 , V_5 -> V_50 . V_95 ) ;
F_5 ( V_7 , 2 , L_13 , V_5 -> V_50 . V_51 ) ;
}
return 0 ;
}
static int F_38 ( struct V_6 * V_7 , T_1 V_96 ,
enum V_97 V_98 )
{
struct V_47 * V_5 ;
struct V_99 * V_100 ;
F_5 ( V_7 , 4 , L_14 , V_98 ) ;
V_100 = F_39 ( V_7 , V_98 , V_101 ) ;
V_5 = (struct V_47 * ) ( V_100 -> V_46 + V_102 ) ;
V_5 -> V_46 . V_94 . V_92 = V_96 ;
return F_40 ( V_7 , V_100 ,
F_37 , NULL ) ;
}
static void F_41 ( struct V_6 * V_7 )
{
struct V_103 * V_81 ;
F_14 ( V_7 , 3 , L_15 ) ;
F_26 ( & V_7 -> V_104 ) ;
F_8 (id, &card->vid_list, list) {
F_38 ( V_7 , V_81 -> V_105 , V_106 ) ;
}
F_29 ( & V_7 -> V_104 ) ;
}
static void F_42 ( struct V_1 * V_2 , unsigned short V_105 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_103 * V_81 ;
F_5 ( V_7 , 4 , L_16 , V_105 ) ;
if ( ! V_105 )
return;
if ( V_7 -> V_16 . type == V_24 ) {
F_14 ( V_7 , 3 , L_17 ) ;
return;
}
if ( F_43 ( V_7 , V_107 ) ) {
F_14 ( V_7 , 3 , L_18 ) ;
return;
}
V_81 = F_22 ( sizeof( struct V_103 ) , V_58 ) ;
if ( V_81 ) {
V_81 -> V_105 = V_105 ;
F_38 ( V_7 , V_105 , V_106 ) ;
F_26 ( & V_7 -> V_104 ) ;
F_23 ( & V_81 -> V_64 , & V_7 -> V_108 ) ;
F_29 ( & V_7 -> V_104 ) ;
}
}
static void F_44 ( struct V_1 * V_2 , unsigned short V_105 )
{
struct V_103 * V_81 , * V_109 = NULL ;
struct V_6 * V_7 = V_2 -> V_8 ;
F_5 ( V_7 , 4 , L_19 , V_105 ) ;
if ( V_7 -> V_16 . type == V_24 ) {
F_14 ( V_7 , 3 , L_20 ) ;
return;
}
if ( F_43 ( V_7 , V_107 ) ) {
F_14 ( V_7 , 3 , L_21 ) ;
return;
}
F_26 ( & V_7 -> V_104 ) ;
F_8 (id, &card->vid_list, list) {
if ( V_81 -> V_105 == V_105 ) {
F_28 ( & V_81 -> V_64 ) ;
V_109 = V_81 ;
break;
}
}
F_29 ( & V_7 -> V_104 ) ;
if ( V_109 ) {
F_38 ( V_7 , V_105 , V_110 ) ;
F_24 ( V_109 ) ;
}
F_45 ( V_7 -> V_2 ) ;
}
static int F_46 ( struct V_6 * V_7 , int V_111 )
{
int V_11 = 0 ;
F_47 ( V_112 , 2 , L_22 ) ;
F_48 ( V_112 , 2 , & V_7 , sizeof( void * ) ) ;
F_49 ( V_7 , 0 , 1 ) ;
if ( V_7 -> V_113 . V_13 == V_114 &&
V_7 -> V_115 . V_13 == V_114 &&
( V_7 -> V_13 == V_14 ) ) {
if ( V_111 &&
V_7 -> V_16 . type != V_17 ) {
F_50 ( V_7 -> V_2 ) ;
} else {
F_51 () ;
F_52 ( V_7 -> V_2 ) ;
F_53 () ;
}
V_7 -> V_16 . V_116 &= ~ V_117 ;
V_7 -> V_13 = V_15 ;
}
if ( V_7 -> V_13 == V_15 ) {
F_25 ( V_7 , 0 ) ;
F_54 ( V_7 ) ;
V_7 -> V_13 = V_118 ;
}
if ( V_7 -> V_13 == V_118 ) {
F_55 ( V_7 , 0 ) ;
F_56 ( V_7 ) ;
F_57 ( V_7 ) ;
V_7 -> V_13 = V_119 ;
}
if ( V_7 -> V_13 == V_119 ) {
F_58 ( & V_7 -> V_113 ) ;
F_58 ( & V_7 -> V_115 ) ;
}
return V_11 ;
}
static int F_59 ( struct V_6 * V_7 ,
int V_120 , int * V_121 )
{
int V_122 = 0 ;
struct V_70 * V_71 ;
struct V_75 * V_50 ;
unsigned int V_87 ;
* V_121 = 0 ;
F_60 ( ! V_120 ) ;
while ( V_120 ) {
V_71 = F_61 ( V_7 ,
V_7 -> V_123 . V_124 -> V_125 [ V_7 -> V_126 . V_127 ] . V_128 ,
& V_7 -> V_126 . V_129 , & V_7 -> V_126 . V_130 , & V_50 ) ;
if ( ! V_71 ) {
* V_121 = 1 ;
break;
}
V_71 -> V_2 = V_7 -> V_2 ;
switch ( V_50 -> V_50 . V_80 . V_81 ) {
case V_82 :
V_71 -> V_131 = V_132 ;
V_71 -> V_133 = F_62 ( V_71 , V_71 -> V_2 ) ;
V_71 -> V_134 = V_135 ;
if ( V_71 -> V_133 == F_63 ( V_136 ) )
* ( ( V_137 * ) V_71 -> V_138 ) = ++ V_7 -> V_139 . V_140 ;
V_87 = V_71 -> V_87 ;
F_64 ( V_71 ) ;
break;
case V_141 :
if ( V_7 -> V_16 . type == V_17 ) {
F_65 ( V_71 , sizeof( struct V_75 ) ) ;
F_66 ( V_71 , V_50 ,
sizeof( struct V_75 ) ) ;
V_87 = V_71 -> V_87 ;
V_7 -> V_142 . V_143 ( V_71 ) ;
break;
}
default:
F_67 ( V_71 ) ;
F_14 ( V_7 , 3 , L_23 ) ;
F_48 ( V_144 , 3 , V_50 , V_145 ) ;
continue;
}
V_122 ++ ;
V_120 -- ;
V_7 -> V_146 . V_147 ++ ;
V_7 -> V_146 . V_148 += V_87 ;
}
return V_122 ;
}
static int F_68 ( struct V_149 * V_150 , int V_120 )
{
struct V_6 * V_7 = F_69 ( V_150 , struct V_6 , V_150 ) ;
int V_122 = 0 ;
struct V_151 * V_128 ;
int V_121 ;
int V_152 = V_120 ;
if ( V_7 -> V_153 . V_154 ) {
V_7 -> V_155 . V_156 ++ ;
V_7 -> V_155 . V_157 = F_70 () ;
}
while ( 1 ) {
if ( ! V_7 -> V_126 . V_158 ) {
V_7 -> V_126 . V_159 = 0 ;
V_7 -> V_126 . V_158 = F_71 (
V_7 -> V_46 . V_160 , 0 , & V_7 -> V_126 . V_127 ,
& V_7 -> V_126 . V_159 ) ;
if ( V_7 -> V_126 . V_158 <= 0 ) {
V_7 -> V_126 . V_158 = 0 ;
break;
}
V_7 -> V_126 . V_129 =
& V_7 -> V_123 . V_124 -> V_125 [ V_7 -> V_126 . V_127 ]
. V_128 -> V_161 [ 0 ] ;
V_7 -> V_126 . V_130 = 0 ;
}
while ( V_7 -> V_126 . V_158 ) {
V_128 = & V_7 -> V_123 . V_124 -> V_125 [ V_7 -> V_126 . V_127 ] ;
if ( ! ( V_7 -> V_126 . V_159 &&
F_72 ( V_7 , V_128 -> V_128 ,
V_7 -> V_126 . V_159 , L_24 ) ) )
V_122 += F_59 (
V_7 , V_152 , & V_121 ) ;
else
V_121 = 1 ;
if ( V_121 ) {
if ( V_7 -> V_153 . V_154 )
V_7 -> V_155 . V_162 ++ ;
F_73 ( V_7 ,
V_128 -> V_163 ) ;
F_74 ( V_7 , V_7 -> V_126 . V_127 ) ;
V_7 -> V_126 . V_158 -- ;
if ( V_7 -> V_126 . V_158 ) {
V_7 -> V_126 . V_127 =
( V_7 -> V_126 . V_127 + 1 ) %
V_164 ;
V_7 -> V_126 . V_129 =
& V_7 -> V_123 . V_124
-> V_125 [ V_7 -> V_126 . V_127 ]
. V_128 -> V_161 [ 0 ] ;
V_7 -> V_126 . V_130 = 0 ;
}
}
if ( V_122 >= V_120 )
goto V_165;
else
V_152 = V_120 - V_122 ;
}
}
F_75 ( V_150 ) ;
if ( F_76 ( V_7 -> V_46 . V_160 , 0 ) )
F_77 ( & V_7 -> V_150 ) ;
V_165:
if ( V_7 -> V_153 . V_154 )
V_7 -> V_155 . V_166 += F_70 () -
V_7 -> V_155 . V_157 ;
return V_122 ;
}
static int F_18 ( struct V_6 * V_7 , T_2 * V_48 ,
enum V_97 V_98 ,
int (* F_78) ( struct V_6 * ,
struct V_44 * ,
unsigned long ) )
{
struct V_47 * V_5 ;
struct V_99 * V_100 ;
F_14 ( V_7 , 2 , L_25 ) ;
V_100 = F_39 ( V_7 , V_98 , V_101 ) ;
V_5 = (struct V_47 * ) ( V_100 -> V_46 + V_102 ) ;
V_5 -> V_46 . V_49 . V_167 = V_60 ;
memcpy ( & V_5 -> V_46 . V_49 . V_48 , V_48 , V_60 ) ;
return F_40 ( V_7 , V_100 , F_78 , NULL ) ;
}
static int F_79 ( struct V_6 * V_7 ,
struct V_44 * V_45 ,
unsigned long V_46 )
{
struct V_47 * V_5 ;
F_14 ( V_7 , 2 , L_26 ) ;
V_5 = (struct V_47 * ) V_46 ;
if ( V_5 -> V_50 . V_51 ) {
F_5 ( V_7 , 2 , L_27 , V_5 -> V_50 . V_51 ) ;
V_7 -> V_16 . V_116 &= ~ V_117 ;
switch ( V_5 -> V_50 . V_51 ) {
case V_52 :
case V_168 :
F_80 ( & V_7 -> V_169 -> V_2 ,
L_28 ,
V_5 -> V_46 . V_49 . V_48 ) ;
break;
case V_170 :
case V_171 :
F_80 ( & V_7 -> V_169 -> V_2 ,
L_29 ,
V_5 -> V_46 . V_49 . V_48 ) ;
break;
default:
break;
}
V_5 -> V_50 . V_51 = - V_172 ;
} else {
V_7 -> V_16 . V_116 |= V_117 ;
memcpy ( V_7 -> V_2 -> V_173 , V_5 -> V_46 . V_49 . V_48 ,
V_60 ) ;
F_81 ( & V_7 -> V_169 -> V_2 ,
L_30 ,
V_7 -> V_2 -> V_173 , V_7 -> V_2 -> V_174 ) ;
}
return 0 ;
}
static int F_82 ( struct V_6 * V_7 , T_2 * V_48 )
{
F_14 ( V_7 , 2 , L_31 ) ;
return F_18 ( V_7 , V_48 , V_63 ,
F_79 ) ;
}
static int F_83 ( struct V_6 * V_7 ,
struct V_44 * V_45 ,
unsigned long V_46 )
{
struct V_47 * V_5 ;
F_14 ( V_7 , 2 , L_32 ) ;
V_5 = (struct V_47 * ) V_46 ;
if ( V_5 -> V_50 . V_51 ) {
F_5 ( V_7 , 2 , L_13 , V_5 -> V_50 . V_51 ) ;
V_5 -> V_50 . V_51 = - V_172 ;
return 0 ;
}
V_7 -> V_16 . V_116 &= ~ V_117 ;
return 0 ;
}
static int F_84 ( struct V_6 * V_7 , T_2 * V_48 )
{
F_14 ( V_7 , 2 , L_33 ) ;
if ( ! ( V_7 -> V_16 . V_116 & V_117 ) )
return 0 ;
return F_18 ( V_7 , V_48 , V_69 ,
F_83 ) ;
}
static int F_85 ( struct V_6 * V_7 )
{
int V_11 = 0 ;
char V_175 [] = { 0x02 , 0x00 , 0x00 } ;
F_47 ( V_112 , 2 , L_34 ) ;
F_86 ( V_112 , 2 , L_35 , F_87 ( V_7 ) ) ;
V_11 = F_88 ( V_7 ) ;
if ( V_11 ) {
F_15 ( 2 , L_36
L_37 , F_87 ( V_7 ) , V_11 ) ;
}
if ( V_7 -> V_16 . type == V_176 ||
V_7 -> V_16 . type == V_24 ||
V_7 -> V_16 . type == V_25 ||
V_7 -> V_16 . V_26 ) {
V_11 = F_89 ( V_7 ) ;
if ( V_11 ) {
F_15 ( 2 , L_38
L_37 , F_87 ( V_7 ) , V_11 ) ;
F_86 ( V_112 , 2 , L_39 , V_11 ) ;
return V_11 ;
}
F_48 ( V_112 , 2 , V_7 -> V_2 -> V_173 , V_60 ) ;
} else {
F_90 ( V_7 -> V_2 -> V_173 ) ;
memcpy ( V_7 -> V_2 -> V_173 , V_175 , 3 ) ;
}
return 0 ;
}
static int F_91 ( struct V_1 * V_2 , void * V_177 )
{
struct V_178 * V_179 = V_177 ;
struct V_6 * V_7 = V_2 -> V_8 ;
int V_11 = 0 ;
F_14 ( V_7 , 3 , L_40 ) ;
if ( F_6 ( V_2 ) != V_37 ) {
F_14 ( V_7 , 3 , L_41 ) ;
return - V_33 ;
}
if ( V_7 -> V_16 . type == V_17 ||
V_7 -> V_16 . type == V_24 ||
V_7 -> V_16 . type == V_25 ) {
F_14 ( V_7 , 3 , L_42 ) ;
return - V_33 ;
}
F_92 ( V_7 , 3 , V_179 -> V_180 , V_60 ) ;
if ( F_43 ( V_7 , V_107 ) ) {
F_14 ( V_7 , 3 , L_43 ) ;
return - V_181 ;
}
V_11 = F_84 ( V_7 , & V_7 -> V_2 -> V_173 [ 0 ] ) ;
if ( ! V_11 )
V_11 = F_82 ( V_7 , V_179 -> V_180 ) ;
return V_11 ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_182 * V_183 ;
if ( V_7 -> V_16 . type == V_17 )
return ;
F_14 ( V_7 , 3 , L_44 ) ;
if ( F_93 ( V_7 , V_107 ) &&
( V_7 -> V_13 != V_14 ) )
return;
F_25 ( V_7 , 1 ) ;
F_26 ( & V_7 -> V_68 ) ;
F_94 (ha, dev)
F_21 ( V_7 , V_183 -> V_179 , 0 ) ;
F_95 (ha, dev)
F_21 ( V_7 , V_183 -> V_179 , 1 ) ;
F_29 ( & V_7 -> V_68 ) ;
if ( ! F_96 ( V_7 , V_184 ) )
return;
F_97 ( V_7 ) ;
}
static int F_98 ( struct V_70 * V_71 , struct V_1 * V_2 )
{
int V_11 ;
struct V_75 * V_50 = NULL ;
int V_185 = 0 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_70 * V_186 = V_71 ;
int V_76 = F_99 ( V_71 ) ;
int V_77 = F_30 ( V_7 , V_71 ) ;
struct V_187 * V_188 = V_7 -> V_123 . V_189
[ F_100 ( V_7 , V_71 , V_76 , V_77 ) ] ;
int V_190 = V_71 -> V_87 ;
int V_191 = - 1 ;
int V_192 = 0 ;
int V_193 = 0 ;
if ( ( V_7 -> V_13 != V_14 ) || ! V_7 -> V_194 ) {
V_7 -> V_146 . V_195 ++ ;
goto V_196;
}
if ( ( V_7 -> V_16 . type == V_17 ) &&
( V_71 -> V_133 == F_63 ( V_197 ) ) )
goto V_196;
if ( V_7 -> V_153 . V_154 ) {
V_7 -> V_155 . V_198 ++ ;
V_7 -> V_155 . V_199 = F_70 () ;
}
F_101 ( V_2 ) ;
if ( V_7 -> V_16 . type == V_17 )
V_50 = (struct V_75 * ) V_71 -> V_46 ;
else {
if ( V_7 -> V_16 . type == V_176 ) {
V_186 = V_71 ;
V_191 = V_200 ;
V_193 = V_200 ;
V_50 = F_102 ( V_201 ,
V_58 ) ;
if ( ! V_50 )
goto V_196;
V_192 ++ ;
F_103 ( V_186 ) ;
F_33 ( V_7 , V_50 , V_186 , V_76 , V_77 ) ;
V_50 -> V_50 . V_80 . V_86 = V_186 -> V_87 ;
memcpy ( ( ( char * ) V_50 ) + sizeof( struct V_75 ) ,
F_34 ( V_186 ) , V_200 ) ;
} else {
V_186 = F_104 ( V_71 ,
sizeof( struct V_75 ) ) ;
if ( ! V_186 )
goto V_196;
V_50 = (struct V_75 * ) F_65 ( V_186 ,
sizeof( struct V_75 ) ) ;
F_105 ( V_186 , sizeof( struct V_75 ) ) ;
F_33 ( V_7 , V_50 , V_186 , V_76 , V_77 ) ;
}
}
V_185 = F_106 ( V_7 , ( void * ) V_50 , V_186 ,
V_192 ) ;
if ( ! V_185 ) {
if ( V_191 >= 0 )
F_107 ( V_201 , V_50 ) ;
goto V_196;
}
if ( V_7 -> V_16 . type != V_176 ) {
if ( F_108 ( V_186 ,
sizeof( struct V_202 ) ) )
goto V_196;
V_11 = F_109 ( V_7 , V_188 , V_186 , V_50 ,
V_185 ) ;
} else
V_11 = F_110 ( V_7 , V_188 , V_186 , V_50 ,
V_185 , V_191 , V_193 ) ;
if ( ! V_11 ) {
V_7 -> V_146 . V_203 ++ ;
V_7 -> V_146 . V_190 += V_190 ;
if ( V_186 != V_71 )
F_67 ( V_71 ) ;
V_11 = V_204 ;
} else {
if ( V_191 >= 0 )
F_107 ( V_201 , V_50 ) ;
if ( V_11 == - V_205 ) {
if ( V_186 != V_71 )
F_67 ( V_186 ) ;
return V_206 ;
} else
goto V_196;
}
F_111 ( V_2 ) ;
if ( V_7 -> V_153 . V_154 )
V_7 -> V_155 . V_207 += F_70 () -
V_7 -> V_155 . V_199 ;
return V_11 ;
V_196:
V_7 -> V_146 . V_208 ++ ;
V_7 -> V_146 . V_209 ++ ;
if ( ( V_186 != V_71 ) && V_186 )
F_67 ( V_186 ) ;
F_67 ( V_71 ) ;
F_111 ( V_2 ) ;
return V_204 ;
}
static int F_112 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_11 = 0 ;
F_14 ( V_7 , 4 , L_45 ) ;
if ( V_7 -> V_13 == V_14 )
return V_11 ;
if ( V_7 -> V_13 != V_15 )
return - V_12 ;
if ( ( V_7 -> V_16 . type != V_17 ) &&
( ! ( V_7 -> V_16 . V_116 & V_117 ) ) ) {
F_14 ( V_7 , 4 , L_46 ) ;
return - V_18 ;
}
V_7 -> V_46 . V_13 = V_114 ;
V_7 -> V_13 = V_14 ;
F_113 ( V_2 ) ;
if ( F_114 ( V_7 -> V_46 . V_160 , 0 ) >= 0 ) {
F_115 ( & V_7 -> V_150 ) ;
F_77 ( & V_7 -> V_150 ) ;
} else
V_11 = - V_172 ;
return V_11 ;
}
static int F_116 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_14 ( V_7 , 5 , L_47 ) ;
if ( F_43 ( V_7 , V_107 ) ) {
F_14 ( V_7 , 3 , L_48 ) ;
return - V_181 ;
}
return F_112 ( V_2 ) ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_14 ( V_7 , 4 , L_49 ) ;
F_117 ( V_2 ) ;
if ( V_7 -> V_13 == V_14 ) {
V_7 -> V_13 = V_15 ;
F_118 ( & V_7 -> V_150 ) ;
}
return 0 ;
}
static int F_119 ( struct V_210 * V_169 )
{
struct V_6 * V_7 = F_120 ( & V_169 -> V_2 ) ;
F_121 ( & V_7 -> V_108 ) ;
F_121 ( & V_7 -> V_65 ) ;
V_7 -> V_153 . V_211 = 1 ;
V_7 -> V_16 . V_212 = 0 ;
V_7 -> V_213 . V_214 = V_215 ;
V_7 -> V_213 . V_216 = ( V_217 * )
V_218 ;
V_7 -> V_213 . V_219 = ( V_217 * )
V_220 ;
V_7 -> V_213 . V_221 = V_222 ;
return 0 ;
}
static void F_122 ( struct V_210 * V_223 )
{
struct V_6 * V_7 = F_120 ( & V_223 -> V_2 ) ;
F_49 ( V_7 , 0 , 1 ) ;
F_123 ( V_7 -> V_224 , F_93 ( V_7 , 0xffffffff ) == 0 ) ;
if ( V_223 -> V_13 == V_225 )
F_124 ( V_223 ) ;
if ( V_7 -> V_2 ) {
F_125 ( V_7 -> V_2 ) ;
V_7 -> V_2 = NULL ;
}
return;
}
static int F_126 ( struct V_6 * V_7 )
{
switch ( V_7 -> V_16 . type ) {
case V_176 :
V_7 -> V_2 = F_127 ( 0 , L_50 , V_226 ) ;
break;
case V_17 :
V_7 -> V_2 = F_127 ( 0 , L_51 , V_226 ) ;
V_7 -> V_2 -> V_34 |= V_227 ;
break;
default:
V_7 -> V_2 = F_128 ( 0 ) ;
}
if ( ! V_7 -> V_2 )
return - V_12 ;
V_7 -> V_2 -> V_8 = V_7 ;
V_7 -> V_2 -> V_228 = V_229 ;
V_7 -> V_2 -> V_230 = V_7 -> V_16 . V_231 ;
V_7 -> V_2 -> V_232 = & V_233 ;
if ( V_7 -> V_16 . type != V_17 )
F_129 ( V_7 -> V_2 , & V_234 ) ;
else
F_129 ( V_7 -> V_2 , & V_235 ) ;
V_7 -> V_2 -> V_236 |= V_237 ;
V_7 -> V_16 . V_238 = 1 ;
F_85 ( V_7 ) ;
F_130 ( V_7 -> V_2 , & V_7 -> V_169 -> V_2 ) ;
F_131 ( V_7 -> V_2 , & V_7 -> V_150 , F_68 , V_239 ) ;
return F_132 ( V_7 -> V_2 ) ;
}
static int F_133 ( struct V_210 * V_169 , int V_111 )
{
struct V_6 * V_7 = F_120 ( & V_169 -> V_2 ) ;
int V_11 = 0 ;
enum V_240 V_241 ;
F_60 ( ! V_7 ) ;
F_134 ( & V_7 -> V_242 ) ;
F_134 ( & V_7 -> V_243 ) ;
F_47 ( V_112 , 2 , L_52 ) ;
F_48 ( V_112 , 2 , & V_7 , sizeof( void * ) ) ;
V_241 = V_7 -> V_13 ;
V_11 = F_135 ( V_7 ) ;
if ( V_11 ) {
F_86 ( V_112 , 2 , L_53 , V_11 ) ;
V_11 = - V_12 ;
goto V_244;
}
if ( ! V_7 -> V_2 && F_126 ( V_7 ) ) {
V_11 = - V_12 ;
goto V_244;
}
if ( V_7 -> V_16 . type != V_17 )
F_82 ( V_7 , & V_7 -> V_2 -> V_173 [ 0 ] ) ;
if ( F_136 ( V_7 , V_245 ) ) {
if ( V_7 -> V_16 . V_212 &&
F_137 ( V_7 , V_246 ) )
V_7 -> V_16 . V_212 = 0 ;
} else
V_7 -> V_16 . V_212 = 0 ;
V_7 -> V_13 = V_118 ;
memset ( & V_7 -> V_126 , 0 , sizeof( struct V_247 ) ) ;
F_138 ( V_7 ) ;
F_47 ( V_112 , 2 , L_54 ) ;
V_11 = F_139 ( V_7 ) ;
if ( V_11 ) {
F_86 ( V_112 , 2 , L_39 , V_11 ) ;
if ( V_11 == 0xe080 ) {
F_80 ( & V_7 -> V_169 -> V_2 ,
L_55 ) ;
V_7 -> V_194 = 0 ;
goto V_248;
}
V_11 = - V_12 ;
goto V_244;
} else
V_7 -> V_194 = 1 ;
V_248:
if ( ( V_7 -> V_16 . type == V_23 ) ||
( V_7 -> V_16 . type == V_25 ) )
F_140 ( V_7 ) ;
if ( V_7 -> V_16 . type != V_17 &&
V_7 -> V_16 . type != V_24 )
F_41 ( V_7 ) ;
F_117 ( V_7 -> V_2 ) ;
V_11 = F_141 ( V_7 ) ;
if ( V_11 ) {
F_86 ( V_112 , 2 , L_56 , V_11 ) ;
V_11 = - V_12 ;
goto V_244;
}
V_7 -> V_13 = V_15 ;
if ( V_7 -> V_194 )
F_142 ( V_7 -> V_2 ) ;
else
F_143 ( V_7 -> V_2 ) ;
F_49 ( V_7 , 0xffffffff , 0 ) ;
if ( V_241 == V_249 ) {
if ( V_111 &&
V_7 -> V_16 . type != V_17 ) {
F_112 ( V_7 -> V_2 ) ;
} else {
F_51 () ;
F_144 ( V_7 -> V_2 ) ;
F_53 () ;
}
F_45 ( V_7 -> V_2 ) ;
}
F_145 ( & V_169 -> V_2 . V_250 , V_251 ) ;
F_146 ( & V_7 -> V_243 ) ;
F_146 ( & V_7 -> V_242 ) ;
return 0 ;
V_244:
F_46 ( V_7 , 0 ) ;
F_147 ( F_148 ( V_7 ) ) ;
F_147 ( F_149 ( V_7 ) ) ;
F_147 ( F_12 ( V_7 ) ) ;
if ( V_241 == V_249 )
V_7 -> V_13 = V_249 ;
else
V_7 -> V_13 = V_119 ;
F_146 ( & V_7 -> V_243 ) ;
F_146 ( & V_7 -> V_242 ) ;
return V_11 ;
}
static int F_150 ( struct V_210 * V_169 )
{
return F_133 ( V_169 , 0 ) ;
}
static int F_151 ( struct V_210 * V_223 ,
int V_111 )
{
struct V_6 * V_7 = F_120 ( & V_223 -> V_2 ) ;
int V_11 = 0 , V_252 = 0 , V_253 = 0 ;
enum V_240 V_241 ;
F_134 ( & V_7 -> V_242 ) ;
F_134 ( & V_7 -> V_243 ) ;
F_47 ( V_112 , 3 , L_57 ) ;
F_48 ( V_112 , 3 , & V_7 , sizeof( void * ) ) ;
if ( V_7 -> V_2 && F_152 ( V_7 -> V_2 ) )
F_143 ( V_7 -> V_2 ) ;
V_241 = V_7 -> V_13 ;
if ( ( ! V_111 && V_7 -> V_16 . V_212 ) || V_7 -> V_16 . V_212 == 2 ) {
F_137 ( V_7 , V_254 ) ;
V_7 -> V_16 . V_212 = 1 ;
}
F_46 ( V_7 , V_111 ) ;
V_11 = F_147 ( F_148 ( V_7 ) ) ;
V_252 = F_147 ( F_149 ( V_7 ) ) ;
V_253 = F_147 ( F_12 ( V_7 ) ) ;
if ( ! V_11 )
V_11 = ( V_252 ) ? V_252 : V_253 ;
if ( V_11 )
F_86 ( V_112 , 2 , L_39 , V_11 ) ;
if ( V_241 == V_14 )
V_7 -> V_13 = V_249 ;
F_145 ( & V_223 -> V_2 . V_250 , V_251 ) ;
F_146 ( & V_7 -> V_243 ) ;
F_146 ( & V_7 -> V_242 ) ;
return 0 ;
}
static int F_124 ( struct V_210 * V_223 )
{
return F_151 ( V_223 , 0 ) ;
}
static int V_222 ( void * V_255 )
{
struct V_6 * V_7 ;
int V_11 = 0 ;
V_7 = (struct V_6 * ) V_255 ;
F_14 ( V_7 , 2 , L_58 ) ;
if ( ! F_153 ( V_7 , V_107 ) )
return 0 ;
F_14 ( V_7 , 2 , L_59 ) ;
F_80 ( & V_7 -> V_169 -> V_2 ,
L_60 ) ;
F_151 ( V_7 -> V_169 , 1 ) ;
V_11 = F_133 ( V_7 -> V_169 , 1 ) ;
if ( ! V_11 )
F_81 ( & V_7 -> V_169 -> V_2 ,
L_61 ) ;
else {
F_51 () ;
F_52 ( V_7 -> V_2 ) ;
F_53 () ;
F_80 ( & V_7 -> V_169 -> V_2 , L_62
L_63 ) ;
}
F_154 ( V_7 , V_107 ) ;
F_155 ( V_7 , V_107 ) ;
return 0 ;
}
static int T_3 F_156 ( void )
{
F_157 ( L_64 ) ;
return 0 ;
}
static void T_4 F_158 ( void )
{
F_157 ( L_65 ) ;
}
static void F_159 ( struct V_210 * V_169 )
{
struct V_6 * V_7 = F_120 ( & V_169 -> V_2 ) ;
if ( ( V_169 -> V_13 == V_225 ) && V_7 -> V_16 . V_212 )
F_137 ( V_7 , V_254 ) ;
F_55 ( V_7 , 0 ) ;
F_56 ( V_7 ) ;
}
static int F_160 ( struct V_210 * V_169 )
{
struct V_6 * V_7 = F_120 ( & V_169 -> V_2 ) ;
if ( V_7 -> V_2 )
F_161 ( V_7 -> V_2 ) ;
F_49 ( V_7 , 0 , 1 ) ;
F_123 ( V_7 -> V_224 , F_93 ( V_7 , 0xffffffff ) == 0 ) ;
if ( V_169 -> V_13 == V_256 )
return 0 ;
if ( V_7 -> V_13 == V_14 ) {
if ( V_7 -> V_16 . V_212 )
F_137 ( V_7 , V_254 ) ;
F_151 ( V_7 -> V_169 , 1 ) ;
} else
F_151 ( V_7 -> V_169 , 0 ) ;
return 0 ;
}
static int F_162 ( struct V_210 * V_169 )
{
struct V_6 * V_7 = F_120 ( & V_169 -> V_2 ) ;
int V_11 = 0 ;
if ( V_169 -> V_13 == V_256 )
goto V_165;
if ( V_7 -> V_13 == V_249 ) {
V_11 = F_133 ( V_7 -> V_169 , 1 ) ;
if ( V_11 ) {
F_51 () ;
F_52 ( V_7 -> V_2 ) ;
F_53 () ;
}
} else
V_11 = F_133 ( V_7 -> V_169 , 0 ) ;
V_165:
F_49 ( V_7 , 0xffffffff , 0 ) ;
if ( V_7 -> V_2 )
F_163 ( V_7 -> V_2 ) ;
if ( V_11 )
F_80 ( & V_7 -> V_169 -> V_2 , L_62
L_63 ) ;
return V_11 ;
}
static int F_164 ( struct V_6 * V_7 , int V_87 ,
struct V_99 * V_100 )
{
unsigned long V_34 ;
int V_11 = 0 ;
F_14 ( V_7 , 5 , L_66 ) ;
F_123 ( V_7 -> V_224 ,
F_165 ( & V_7 -> V_115 . V_257 , 0 , 1 ) == 0 ) ;
F_166 ( V_7 , V_87 , V_100 ) ;
F_14 ( V_7 , 6 , L_67 ) ;
F_167 ( F_168 ( V_7 -> V_115 . V_160 ) , V_34 ) ;
V_11 = F_169 ( V_7 -> V_115 . V_160 , & V_7 -> V_115 . V_258 ,
( V_259 ) V_100 , 0 , 0 ) ;
F_170 ( F_168 ( V_7 -> V_115 . V_160 ) , V_34 ) ;
if ( V_11 ) {
F_15 ( 2 , L_68
L_69 , V_11 ) ;
F_5 ( V_7 , 2 , L_70 , V_11 ) ;
F_171 ( V_100 -> V_260 , V_100 ) ;
F_172 ( & V_7 -> V_115 . V_257 , 0 ) ;
F_173 ( & V_7 -> V_224 ) ;
}
return V_11 ;
}
static int F_174 ( struct V_6 * V_7 ,
struct V_99 * V_100 , int V_261 )
{
T_5 V_262 , V_263 ;
F_14 ( V_7 , 4 , L_71 ) ;
F_175 ( V_7 , V_100 , V_264 ) ;
V_262 = ( T_5 ) ( V_102 + V_261 ) ;
V_263 = ( T_5 ) V_261 ;
memcpy ( F_176 ( V_100 -> V_46 ) , & V_262 , 2 ) ;
memcpy ( F_177 ( V_100 -> V_46 ) , & V_263 , 2 ) ;
memcpy ( F_178 ( V_100 -> V_46 ) , & V_263 , 2 ) ;
memcpy ( F_179 ( V_100 -> V_46 ) , & V_263 , 2 ) ;
return F_164 ( V_7 , V_262 , V_100 ) ;
}
int F_180 ( struct V_1 * V_2 , void * V_46 , int V_261 )
{
struct V_99 * V_100 ;
struct V_6 * V_7 ;
int V_11 ;
if ( ! V_2 )
return - V_12 ;
V_7 = V_2 -> V_8 ;
if ( ! V_7 )
return - V_12 ;
F_14 ( V_7 , 2 , L_72 ) ;
if ( ( V_7 -> V_13 != V_14 ) &&
( V_7 -> V_13 != V_15 ) )
return - V_12 ;
V_100 = F_181 ( & V_7 -> V_115 ) ;
memcpy ( V_100 -> V_46 + V_102 , V_46 , V_261 ) ;
V_11 = F_174 ( V_7 , V_100 , V_261 ) ;
return V_11 ;
}
int F_182 ( unsigned char * V_38 , struct V_1 * * V_2 ,
int (* F_183)( struct V_1 * , void * ) ,
int (* V_143)( struct V_70 * ) )
{
struct V_6 * V_7 ;
* V_2 = F_10 ( V_38 ) ;
if ( * V_2 == NULL )
return - V_12 ;
V_7 = ( * V_2 ) -> V_8 ;
if ( ! V_7 )
return - V_12 ;
F_14 ( V_7 , 2 , L_73 ) ;
if ( ( F_183 == NULL ) || ( V_143 == NULL ) )
return - V_30 ;
V_7 -> V_142 . F_183 = F_183 ;
V_7 -> V_142 . V_143 = V_143 ;
return 0 ;
}
void F_184 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
if ( ! V_2 )
return;
V_7 = V_2 -> V_8 ;
if ( ! V_7 )
return;
F_14 ( V_7 , 2 , L_74 ) ;
V_7 -> V_142 . F_183 = NULL ;
V_7 -> V_142 . V_143 = NULL ;
return;
}
