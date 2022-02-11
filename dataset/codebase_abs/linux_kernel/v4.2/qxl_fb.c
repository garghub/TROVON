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
unsigned long V_18 ;
T_1 V_19 , V_20 , y1 , V_21 ;
int V_22 = V_16 -> V_23 . V_24 . V_25 [ 0 ] ;
F_3 ( & V_16 -> V_26 . V_27 , V_18 ) ;
V_19 = V_16 -> V_26 . V_19 ;
V_20 = V_16 -> V_26 . V_20 ;
y1 = V_16 -> V_26 . y1 ;
V_21 = V_16 -> V_26 . V_21 ;
V_16 -> V_26 . V_19 = 0 ;
V_16 -> V_26 . V_20 = 0 ;
V_16 -> V_26 . y1 = 0 ;
V_16 -> V_26 . V_21 = 0 ;
F_4 ( & V_16 -> V_26 . V_27 , V_18 ) ;
F_5 ( V_3 , L_1 , V_19 , V_20 , y1 , V_21 ) ;
V_7 -> V_28 = V_19 ;
V_7 -> V_29 = y1 ;
V_7 -> V_30 = V_20 - V_19 + 1 ;
V_7 -> V_31 = V_21 - y1 + 1 ;
V_7 -> V_32 = 0xffffffff ;
V_7 -> V_33 = 0 ;
V_7 -> V_13 = 32 ;
V_7 -> V_34 . V_35 = 0 ;
V_7 -> V_34 . V_36 = 0 ;
V_7 -> V_34 . V_37 = NULL ;
V_7 -> V_34 . V_38 = NULL ;
V_7 -> V_34 . V_39 = NULL ;
V_7 -> V_34 . V_40 = NULL ;
V_7 -> V_41 = V_16 -> V_42 + ( V_19 * 4 ) + ( V_22 * y1 ) ;
F_1 ( & V_1 , V_3 , V_5 , NULL ) ;
F_6 ( & V_1 , V_22 ) ;
}
static void F_7 ( struct V_15 * V_16 ,
int V_43 , int V_44 , int V_30 , int V_31 )
{
struct V_2 * V_3 = V_16 -> V_3 ;
unsigned long V_18 ;
int V_20 , V_21 ;
V_20 = V_43 + V_30 - 1 ;
V_21 = V_44 + V_31 - 1 ;
F_3 ( & V_16 -> V_26 . V_27 , V_18 ) ;
if ( V_16 -> V_26 . y1 < V_44 )
V_44 = V_16 -> V_26 . y1 ;
if ( V_16 -> V_26 . V_21 > V_21 )
V_21 = V_16 -> V_26 . V_21 ;
if ( V_16 -> V_26 . V_19 < V_43 )
V_43 = V_16 -> V_26 . V_19 ;
if ( V_16 -> V_26 . V_20 > V_20 )
V_20 = V_16 -> V_26 . V_20 ;
V_16 -> V_26 . V_19 = V_43 ;
V_16 -> V_26 . V_20 = V_20 ;
V_16 -> V_26 . y1 = V_44 ;
V_16 -> V_26 . V_21 = V_21 ;
F_4 ( & V_16 -> V_26 . V_27 , V_18 ) ;
F_8 ( & V_3 -> V_45 ) ;
}
static void F_9 ( struct V_4 * V_5 ,
struct V_46 * V_47 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
unsigned long V_35 , V_48 , V_49 , V_50 ;
struct V_51 * V_51 ;
int y1 , V_21 ;
V_49 = V_52 ;
V_50 = 0 ;
F_10 (page, pagelist, lru) {
V_35 = V_51 -> V_53 << V_54 ;
V_48 = V_35 + V_55 - 1 ;
V_49 = V_49 ( V_49 , V_35 ) ;
V_50 = V_50 ( V_50 , V_48 ) ;
}
if ( V_49 < V_50 ) {
y1 = V_49 / V_5 -> V_9 . V_56 ;
V_21 = ( V_50 / V_5 -> V_9 . V_56 ) + 1 ;
F_7 ( V_16 , 0 , y1 , V_5 -> V_57 . V_58 , V_21 - y1 ) ;
}
}
static void F_11 ( struct V_4 * V_5 ,
const struct V_59 * V_60 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
F_12 ( V_5 , V_60 ) ;
F_7 ( V_16 , V_60 -> V_28 , V_60 -> V_29 , V_60 -> V_30 ,
V_60 -> V_31 ) ;
}
static void F_13 ( struct V_4 * V_5 ,
const struct V_61 * V_62 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
F_14 ( V_5 , V_62 ) ;
F_7 ( V_16 , V_62 -> V_28 , V_62 -> V_29 , V_62 -> V_30 ,
V_62 -> V_31 ) ;
}
static void F_15 ( struct V_4 * V_5 ,
const struct V_6 * V_7 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
F_16 ( V_5 , V_7 ) ;
F_7 ( V_16 , V_7 -> V_28 , V_7 -> V_29 , V_7 -> V_30 ,
V_7 -> V_31 ) ;
}
static void F_17 ( struct V_63 * V_64 )
{
struct V_2 * V_3 = F_18 ( V_64 , struct V_2 , V_45 ) ;
struct V_15 * V_16 = V_3 -> V_65 . V_16 ;
F_2 ( V_16 -> V_66 . V_67 ) ;
}
int F_19 ( struct V_2 * V_3 )
{
F_20 ( & V_3 -> V_45 , F_17 ) ;
return 0 ;
}
static void F_21 ( struct V_68 * V_69 )
{
struct V_70 * V_71 = F_22 ( V_69 ) ;
int V_72 ;
V_72 = F_23 ( V_71 , false ) ;
if ( F_24 ( V_72 == 0 ) ) {
F_25 ( V_71 ) ;
F_26 ( V_71 ) ;
F_27 ( V_71 ) ;
}
F_28 ( V_69 ) ;
}
int F_29 ( struct V_2 * V_3 ,
struct V_73 * V_74 ,
T_2 * V_75 )
{
int V_76 ;
struct V_68 * V_69 = V_3 -> V_77 -> V_78 ;
F_30 ( ! V_69 ) ;
V_76 = F_31 ( V_74 , V_69 , V_75 ) ;
if ( V_76 )
return V_76 ;
return 0 ;
}
static int F_32 ( struct V_15 * V_16 ,
struct V_79 * V_80 ,
struct V_68 * * V_81 )
{
struct V_2 * V_3 = V_16 -> V_3 ;
struct V_68 * V_69 = NULL ;
struct V_70 * V_71 = NULL ;
int V_72 ;
int V_82 , V_83 ;
int V_31 = V_80 -> V_31 ;
int V_84 ;
int V_13 ;
F_33 ( V_80 -> V_85 , & V_84 , & V_13 ) ;
V_83 = V_80 -> V_25 [ 0 ] * V_31 ;
V_82 = F_34 ( V_83 , V_55 ) ;
V_72 = F_35 ( V_3 , V_82 , 0 ,
V_86 ,
false ,
false ,
NULL ,
& V_69 ) ;
if ( V_72 ) {
F_36 ( L_2 ,
V_82 ) ;
return - V_87 ;
}
V_71 = F_22 ( V_69 ) ;
V_71 -> V_88 . V_30 = V_80 -> V_30 ;
V_71 -> V_88 . V_31 = V_80 -> V_31 ;
V_71 -> V_88 . V_22 = V_80 -> V_25 [ 0 ] ;
V_71 -> V_88 . V_89 = V_90 ;
V_72 = F_23 ( V_71 , false ) ;
if ( F_37 ( V_72 != 0 ) )
goto V_91;
V_72 = F_38 ( V_71 , V_86 , NULL ) ;
if ( V_72 ) {
F_27 ( V_71 ) ;
goto V_91;
}
V_72 = F_39 ( V_71 , NULL ) ;
F_27 ( V_71 ) ;
if ( V_72 )
goto V_91;
* V_81 = V_69 ;
return 0 ;
V_91:
F_21 ( V_69 ) ;
* V_81 = NULL ;
return V_72 ;
}
static int F_40 ( struct V_15 * V_16 ,
struct V_92 * V_93 )
{
struct V_2 * V_3 = V_16 -> V_3 ;
struct V_4 * V_5 ;
struct V_94 * V_95 = NULL ;
struct V_79 V_80 ;
struct V_68 * V_69 = NULL ;
struct V_70 * V_71 = NULL ;
struct V_96 * V_96 = & V_3 -> V_97 -> V_98 ;
int V_72 ;
int V_83 ;
int V_84 = V_93 -> V_99 ;
int V_13 = V_93 -> V_100 ;
void * V_42 ;
V_80 . V_30 = V_93 -> V_101 ;
V_80 . V_31 = V_93 -> V_102 ;
V_80 . V_25 [ 0 ] = F_34 ( V_80 . V_30 * ( ( V_84 + 1 ) / 8 ) , 64 ) ;
V_80 . V_85 = F_41 ( V_84 , V_13 ) ;
V_72 = F_32 ( V_16 , & V_80 , & V_69 ) ;
V_71 = F_22 ( V_69 ) ;
F_42 ( V_3 , L_3 , V_103 , V_80 . V_30 ,
V_80 . V_31 , V_80 . V_25 [ 0 ] ) ;
V_42 = F_43 ( V_80 . V_25 [ 0 ] * V_80 . V_31 ) ;
F_30 ( ! V_42 ) ;
F_42 ( V_3 ,
L_4 ,
F_44 ( V_71 ) ,
F_45 ( V_71 ) ,
V_71 -> V_104 ,
V_42 ) ;
V_83 = V_80 . V_25 [ 0 ] * V_80 . V_31 ;
V_5 = F_46 ( 0 , V_96 ) ;
if ( V_5 == NULL ) {
V_72 = - V_87 ;
goto V_91;
}
V_5 -> V_17 = V_16 ;
F_47 ( V_3 -> V_105 , & V_16 -> V_23 , & V_80 , V_69 ) ;
V_95 = & V_16 -> V_23 . V_24 ;
V_16 -> V_66 . V_95 = V_95 ;
V_16 -> V_66 . V_67 = V_5 ;
V_16 -> V_42 = V_42 ;
strcpy ( V_5 -> V_9 . V_106 , L_5 ) ;
F_48 ( V_5 , V_95 -> V_25 [ 0 ] , V_95 -> V_13 ) ;
V_5 -> V_18 = V_107 | V_108 | V_109 ;
V_5 -> V_110 = & V_111 ;
V_5 -> V_9 . V_112 = V_3 -> V_113 ;
V_5 -> V_9 . V_114 = V_69 -> V_83 ;
V_5 -> V_115 = V_16 -> V_42 ;
V_5 -> V_116 = V_69 -> V_83 ;
F_49 ( V_5 , & V_16 -> V_66 , V_93 -> V_117 ,
V_93 -> V_118 ) ;
V_5 -> V_119 = F_50 ( 1 ) ;
if ( ! V_5 -> V_119 ) {
V_72 = - V_87 ;
goto V_91;
}
V_5 -> V_119 -> V_120 [ 0 ] . V_24 = V_3 -> V_105 -> V_121 . V_122 ;
V_5 -> V_119 -> V_120 [ 0 ] . V_83 = V_3 -> V_123 ;
V_5 -> V_9 . V_124 = 0 ;
V_5 -> V_9 . V_125 = 0 ;
if ( V_5 -> V_115 == NULL ) {
V_72 = - V_126 ;
goto V_91;
}
V_72 = F_51 ( & V_5 -> V_34 , 256 , 0 ) ;
if ( V_72 ) {
V_72 = - V_87 ;
goto V_91;
}
V_5 -> V_127 = & V_128 ;
F_52 ( V_5 ) ;
V_3 -> V_129 = V_5 ;
V_3 -> V_77 = & V_16 -> V_23 ;
F_53 ( L_6 , V_5 -> V_9 . V_112 , ( unsigned long ) V_5 -> V_116 ) ;
F_53 ( L_7 , V_95 -> V_13 , V_95 -> V_25 [ 0 ] , V_95 -> V_30 , V_95 -> V_31 ) ;
return 0 ;
V_91:
if ( V_71 ) {
V_72 = F_23 ( V_71 , false ) ;
if ( F_24 ( V_72 == 0 ) ) {
F_25 ( V_71 ) ;
F_26 ( V_71 ) ;
F_27 ( V_71 ) ;
}
}
if ( V_95 && V_72 ) {
F_54 ( V_69 ) ;
F_55 ( V_95 ) ;
F_56 ( V_95 ) ;
}
F_54 ( V_69 ) ;
return V_72 ;
}
static int F_57 (
struct V_130 * V_66 ,
struct V_92 * V_93 )
{
struct V_15 * V_16 =
F_18 ( V_66 , struct V_15 , V_66 ) ;
int V_131 = 0 ;
int V_72 ;
if ( ! V_66 -> V_95 ) {
V_72 = F_40 ( V_16 , V_93 ) ;
if ( V_72 )
return V_72 ;
V_131 = 1 ;
}
return V_131 ;
}
static int F_58 ( struct V_132 * V_98 , struct V_15 * V_16 )
{
struct V_4 * V_5 ;
struct V_133 * V_23 = & V_16 -> V_23 ;
if ( V_16 -> V_66 . V_67 ) {
V_5 = V_16 -> V_66 . V_67 ;
F_59 ( V_5 ) ;
F_60 ( V_5 ) ;
}
if ( V_23 -> V_78 ) {
F_21 ( V_23 -> V_78 ) ;
V_23 -> V_78 = NULL ;
}
F_61 ( & V_16 -> V_66 ) ;
F_62 ( V_16 -> V_42 ) ;
F_55 ( & V_23 -> V_24 ) ;
return 0 ;
}
int F_63 ( struct V_2 * V_3 )
{
struct V_15 * V_16 ;
int V_134 = 32 ;
int V_72 ;
V_16 = F_64 ( sizeof( struct V_15 ) , V_135 ) ;
if ( ! V_16 )
return - V_87 ;
V_16 -> V_3 = V_3 ;
V_3 -> V_65 . V_16 = V_16 ;
F_65 ( & V_16 -> V_136 ) ;
F_65 ( & V_16 -> V_26 . V_27 ) ;
F_66 ( & V_16 -> V_137 ) ;
F_67 ( V_3 -> V_105 , & V_16 -> V_66 ,
& V_138 ) ;
V_72 = F_68 ( V_3 -> V_105 , & V_16 -> V_66 ,
V_139 ,
V_140 ) ;
if ( V_72 )
goto free;
V_72 = F_69 ( & V_16 -> V_66 ) ;
if ( V_72 )
goto V_141;
V_72 = F_70 ( & V_16 -> V_66 , V_134 ) ;
if ( V_72 )
goto V_141;
return 0 ;
V_141:
F_61 ( & V_16 -> V_66 ) ;
free:
F_56 ( V_16 ) ;
return V_72 ;
}
void F_71 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_65 . V_16 )
return;
F_58 ( V_3 -> V_105 , V_3 -> V_65 . V_16 ) ;
F_56 ( V_3 -> V_65 . V_16 ) ;
V_3 -> V_65 . V_16 = NULL ;
}
void F_72 ( struct V_2 * V_3 , int V_142 )
{
F_73 ( V_3 -> V_65 . V_16 -> V_66 . V_67 , V_142 ) ;
}
bool F_74 ( struct V_2 * V_3 , struct V_70 * V_143 )
{
if ( V_143 == F_22 ( V_3 -> V_65 . V_16 -> V_23 . V_78 ) )
return true ;
return false ;
}
