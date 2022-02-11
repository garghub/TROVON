static void F_1 ( struct V_1 * V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 ,
const struct V_6 * V_7 )
{
V_1 -> V_3 = V_3 ;
if ( V_5 ) {
V_1 -> V_8 = V_5 -> V_9 . V_8 ;
if ( V_1 -> V_8 == V_10 ||
V_1 -> V_8 == V_11 )
memcpy ( & V_1 -> V_12 ,
V_5 -> V_12 ,
sizeof( V_1 -> V_12 ) ) ;
} else {
if ( V_7 -> V_13 == 1 )
V_1 -> V_8 = V_14 ;
else
V_1 -> V_8 = V_11 ;
}
if ( V_7 ) {
memcpy ( & V_1 -> V_6 , V_7 ,
sizeof( V_1 -> V_6 ) ) ;
}
}
static void F_2 ( struct V_4 * V_5 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
struct V_2 * V_3 = V_16 -> V_3 ;
struct V_1 V_1 ;
struct V_6 * V_7 = & V_1 . V_6 ;
T_1 V_18 , V_19 , y1 , V_20 ;
int V_21 = V_16 -> V_22 . V_23 . V_24 [ 0 ] * 4 ;
V_18 = V_16 -> V_25 . V_18 ;
V_19 = V_16 -> V_25 . V_19 ;
y1 = V_16 -> V_25 . y1 ;
V_20 = V_16 -> V_25 . V_20 ;
F_3 ( V_3 , L_1 , V_18 , V_19 , y1 , V_20 ) ;
V_7 -> V_26 = V_18 ;
V_7 -> V_27 = y1 ;
V_7 -> V_28 = V_19 - V_18 ;
V_7 -> V_29 = V_20 - y1 ;
V_7 -> V_30 = 0xffffffff ;
V_7 -> V_31 = 0 ;
V_7 -> V_13 = 32 ;
V_7 -> V_32 . V_33 = 0 ;
V_7 -> V_32 . V_34 = 0 ;
V_7 -> V_32 . V_35 = NULL ;
V_7 -> V_32 . V_36 = NULL ;
V_7 -> V_32 . V_37 = NULL ;
V_7 -> V_32 . V_38 = NULL ;
V_7 -> V_39 = V_16 -> V_40 + ( V_18 * 4 ) + ( V_21 * y1 ) ;
F_1 ( & V_1 , V_3 , V_5 , NULL ) ;
F_4 ( & V_1 , V_21 ) ;
V_16 -> V_25 . V_18 = 0 ;
V_16 -> V_25 . V_19 = 0 ;
V_16 -> V_25 . y1 = 0 ;
V_16 -> V_25 . V_20 = 0 ;
}
static void F_5 ( struct V_4 * V_5 ,
struct V_41 * V_42 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
unsigned long V_33 , V_43 , V_44 , V_45 ;
struct V_46 * V_46 ;
int y1 , V_20 ;
V_44 = V_47 ;
V_45 = 0 ;
F_6 (page, pagelist, lru) {
V_33 = V_46 -> V_48 << V_49 ;
V_43 = V_33 + V_50 - 1 ;
V_44 = V_44 ( V_44 , V_33 ) ;
V_45 = V_45 ( V_45 , V_43 ) ;
}
if ( V_44 < V_45 ) {
y1 = V_44 / V_5 -> V_9 . V_51 ;
V_20 = ( V_45 / V_5 -> V_9 . V_51 ) + 1 ;
V_16 -> V_25 . V_18 = 0 ;
V_16 -> V_25 . y1 = y1 ;
V_16 -> V_25 . V_19 = V_5 -> V_52 . V_53 ;
V_16 -> V_25 . V_20 = V_20 ;
}
F_2 ( V_5 ) ;
}
static void F_7 ( struct V_4 * V_5 ,
const struct V_54 * V_55 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
struct V_2 * V_3 = V_16 -> V_3 ;
struct V_56 V_57 ;
T_2 V_58 ;
int V_59 = V_55 -> V_26 ;
int V_60 = V_55 -> V_27 ;
int V_28 = V_55 -> V_28 ;
int V_29 = V_55 -> V_29 ;
T_3 V_61 ;
struct V_62 V_63 ;
if ( V_5 -> V_9 . V_8 == V_10 ||
V_5 -> V_9 . V_8 == V_11 )
V_58 = ( ( T_1 * ) ( V_5 -> V_12 ) ) [ V_55 -> V_58 ] ;
else
V_58 = V_55 -> V_58 ;
V_57 . V_64 = V_59 ;
V_57 . V_65 = V_59 + V_28 ;
V_57 . V_66 = V_60 ;
V_57 . V_67 = V_60 + V_29 ;
switch ( V_55 -> V_61 ) {
case V_68 :
V_61 = V_69 ;
break;
case V_70 :
V_61 = V_71 ;
break;
default:
F_8 ( L_2
L_3 ) ;
V_61 = V_71 ;
}
V_63 . V_3 = V_3 ;
V_63 . V_57 = V_57 ;
V_63 . V_58 = V_58 ;
V_63 . V_61 = V_61 ;
if ( ! F_9 () ) {
F_3 ( V_3 ,
L_4 ,
V_72 ) ;
return;
}
V_62 ( & V_63 ) ;
}
static void F_10 ( struct V_4 * V_5 ,
const struct V_73 * V_74 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
F_11 ( V_16 -> V_3 ,
V_74 -> V_28 , V_74 -> V_29 ,
V_74 -> V_75 , V_74 -> V_76 ,
V_74 -> V_26 , V_74 -> V_27 ) ;
}
static void F_12 ( struct V_1 * V_1 )
{
F_4 ( V_1 , 0 ) ;
}
static void F_13 ( struct V_4 * V_5 ,
const struct V_6 * V_7 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
struct V_2 * V_3 = V_16 -> V_3 ;
struct V_1 V_1 ;
if ( ! F_9 () ) {
F_3 ( V_3 ,
L_4 ,
V_72 ) ;
return;
}
F_1 ( & V_1 , V_16 -> V_3 , V_5 , V_7 ) ;
F_12 ( & V_1 ) ;
}
int F_14 ( struct V_2 * V_3 )
{
return 0 ;
}
static void F_15 ( struct V_77 * V_78 )
{
struct V_79 * V_80 = F_16 ( V_78 ) ;
int V_81 ;
V_81 = F_17 ( V_80 , false ) ;
if ( F_18 ( V_81 == 0 ) ) {
F_19 ( V_80 ) ;
F_20 ( V_80 ) ;
F_21 ( V_80 ) ;
}
F_22 ( V_78 ) ;
}
int F_23 ( struct V_2 * V_3 ,
struct V_82 * V_83 ,
T_2 * V_84 )
{
int V_85 ;
struct V_77 * V_78 = V_3 -> V_86 -> V_87 ;
F_24 ( ! V_78 ) ;
V_85 = F_25 ( V_83 , V_78 , V_84 ) ;
if ( V_85 )
return V_85 ;
return 0 ;
}
static int F_26 ( struct V_15 * V_16 ,
struct V_88 * V_89 ,
struct V_77 * * V_90 )
{
struct V_2 * V_3 = V_16 -> V_3 ;
struct V_77 * V_78 = NULL ;
struct V_79 * V_80 = NULL ;
int V_81 ;
int V_91 , V_92 ;
int V_29 = V_89 -> V_29 ;
int V_93 ;
int V_13 ;
F_27 ( V_89 -> V_94 , & V_93 , & V_13 ) ;
V_92 = V_89 -> V_24 [ 0 ] * V_29 ;
V_91 = F_28 ( V_92 , V_50 ) ;
V_81 = F_29 ( V_3 , V_91 , 0 ,
V_95 ,
false ,
false ,
NULL ,
& V_78 ) ;
if ( V_81 ) {
F_8 ( L_5 ,
V_91 ) ;
return - V_96 ;
}
V_80 = F_16 ( V_78 ) ;
V_80 -> V_97 . V_28 = V_89 -> V_28 ;
V_80 -> V_97 . V_29 = V_89 -> V_29 ;
V_80 -> V_97 . V_21 = V_89 -> V_24 [ 0 ] ;
V_80 -> V_97 . V_98 = V_99 ;
V_81 = F_17 ( V_80 , false ) ;
if ( F_30 ( V_81 != 0 ) )
goto V_100;
V_81 = F_31 ( V_80 , V_95 , NULL ) ;
if ( V_81 ) {
F_21 ( V_80 ) ;
goto V_100;
}
V_81 = F_32 ( V_80 , NULL ) ;
F_21 ( V_80 ) ;
if ( V_81 )
goto V_100;
* V_90 = V_78 ;
return 0 ;
V_100:
F_15 ( V_78 ) ;
* V_90 = NULL ;
return V_81 ;
}
static int F_33 ( struct V_15 * V_16 ,
struct V_101 * V_102 )
{
struct V_2 * V_3 = V_16 -> V_3 ;
struct V_4 * V_5 ;
struct V_103 * V_104 = NULL ;
struct V_88 V_89 ;
struct V_77 * V_78 = NULL ;
struct V_79 * V_80 = NULL ;
struct V_105 * V_105 = & V_3 -> V_106 -> V_107 ;
int V_81 ;
int V_92 ;
int V_93 = V_102 -> V_108 ;
int V_13 = V_102 -> V_109 ;
void * V_40 ;
V_89 . V_28 = V_102 -> V_110 ;
V_89 . V_29 = V_102 -> V_111 ;
V_89 . V_24 [ 0 ] = F_28 ( V_89 . V_28 * ( ( V_93 + 1 ) / 8 ) , 64 ) ;
V_89 . V_94 = F_34 ( V_93 , V_13 ) ;
V_81 = F_26 ( V_16 , & V_89 , & V_78 ) ;
V_80 = F_16 ( V_78 ) ;
F_35 ( V_3 , L_6 , V_72 , V_89 . V_28 ,
V_89 . V_29 , V_89 . V_24 [ 0 ] ) ;
V_40 = F_36 ( V_89 . V_24 [ 0 ] * V_89 . V_29 ) ;
F_24 ( ! V_40 ) ;
F_35 ( V_3 ,
L_7 ,
F_37 ( V_80 ) ,
F_38 ( V_80 ) ,
V_80 -> V_112 ,
V_40 ) ;
V_92 = V_89 . V_24 [ 0 ] * V_89 . V_29 ;
V_5 = F_39 ( 0 , V_105 ) ;
if ( V_5 == NULL ) {
V_81 = - V_96 ;
goto V_100;
}
V_5 -> V_17 = V_16 ;
F_40 ( V_3 -> V_113 , & V_16 -> V_22 , & V_89 , V_78 ) ;
V_104 = & V_16 -> V_22 . V_23 ;
V_16 -> V_114 . V_104 = V_104 ;
V_16 -> V_114 . V_115 = V_5 ;
V_16 -> V_40 = V_40 ;
strcpy ( V_5 -> V_9 . V_116 , L_8 ) ;
F_41 ( V_5 , V_104 -> V_24 [ 0 ] , V_104 -> V_13 ) ;
V_5 -> V_117 = V_118 | V_119 | V_120 ;
V_5 -> V_121 = & V_122 ;
V_5 -> V_9 . V_123 = V_3 -> V_124 ;
V_5 -> V_9 . V_125 = V_78 -> V_92 ;
V_5 -> V_126 = V_16 -> V_40 ;
V_5 -> V_127 = V_78 -> V_92 ;
F_42 ( V_5 , & V_16 -> V_114 , V_102 -> V_128 ,
V_102 -> V_129 ) ;
V_5 -> V_130 = F_43 ( 1 ) ;
if ( ! V_5 -> V_130 ) {
V_81 = - V_96 ;
goto V_100;
}
V_5 -> V_130 -> V_131 [ 0 ] . V_23 = V_3 -> V_113 -> V_132 . V_133 ;
V_5 -> V_130 -> V_131 [ 0 ] . V_92 = V_3 -> V_134 ;
V_5 -> V_9 . V_135 = 0 ;
V_5 -> V_9 . V_136 = 0 ;
if ( V_5 -> V_126 == NULL ) {
V_81 = - V_137 ;
goto V_100;
}
V_81 = F_44 ( & V_5 -> V_32 , 256 , 0 ) ;
if ( V_81 ) {
V_81 = - V_96 ;
goto V_100;
}
V_5 -> V_138 = & V_139 ;
F_45 ( V_5 ) ;
V_3 -> V_140 = V_5 ;
V_3 -> V_86 = & V_16 -> V_22 ;
F_46 ( L_9 , V_5 -> V_9 . V_123 , ( unsigned long ) V_5 -> V_127 ) ;
F_46 ( L_10 , V_104 -> V_13 , V_104 -> V_24 [ 0 ] , V_104 -> V_28 , V_104 -> V_29 ) ;
return 0 ;
V_100:
if ( V_80 ) {
V_81 = F_17 ( V_80 , false ) ;
if ( F_18 ( V_81 == 0 ) ) {
F_19 ( V_80 ) ;
F_20 ( V_80 ) ;
F_21 ( V_80 ) ;
}
}
if ( V_104 && V_81 ) {
F_47 ( V_78 ) ;
F_48 ( V_104 ) ;
F_49 ( V_104 ) ;
}
F_47 ( V_78 ) ;
return V_81 ;
}
static int F_50 (
struct V_141 * V_114 ,
struct V_101 * V_102 )
{
struct V_15 * V_16 = (struct V_15 * ) V_114 ;
int V_142 = 0 ;
int V_81 ;
if ( ! V_114 -> V_104 ) {
V_81 = F_33 ( V_16 , V_102 ) ;
if ( V_81 )
return V_81 ;
V_142 = 1 ;
}
return V_142 ;
}
static int F_51 ( struct V_143 * V_107 , struct V_15 * V_16 )
{
struct V_4 * V_5 ;
struct V_144 * V_22 = & V_16 -> V_22 ;
if ( V_16 -> V_114 . V_115 ) {
V_5 = V_16 -> V_114 . V_115 ;
F_52 ( V_5 ) ;
F_53 ( V_5 ) ;
}
if ( V_22 -> V_87 ) {
F_15 ( V_22 -> V_87 ) ;
V_22 -> V_87 = NULL ;
}
F_54 ( & V_16 -> V_114 ) ;
F_55 ( V_16 -> V_40 ) ;
F_48 ( & V_22 -> V_23 ) ;
return 0 ;
}
int F_56 ( struct V_2 * V_3 )
{
struct V_15 * V_16 ;
int V_145 = 32 ;
int V_81 ;
V_16 = F_57 ( sizeof( struct V_15 ) , V_146 ) ;
if ( ! V_16 )
return - V_96 ;
V_16 -> V_3 = V_3 ;
V_3 -> V_147 . V_16 = V_16 ;
V_16 -> V_114 . V_148 = & V_149 ;
V_81 = F_58 ( V_3 -> V_113 , & V_16 -> V_114 ,
1 ,
V_150 ) ;
if ( V_81 ) {
F_49 ( V_16 ) ;
return V_81 ;
}
F_59 ( & V_16 -> V_114 ) ;
F_60 ( & V_16 -> V_114 , V_145 ) ;
return 0 ;
}
void F_61 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_147 . V_16 )
return;
F_51 ( V_3 -> V_113 , V_3 -> V_147 . V_16 ) ;
F_49 ( V_3 -> V_147 . V_16 ) ;
V_3 -> V_147 . V_16 = NULL ;
}
