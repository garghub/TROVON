static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return V_5 -> V_6 ;
}
static void F_3 ( struct V_1 * V_7 )
{
if ( V_7 -> V_8 )
F_4 ( V_7 -> V_8 ) ;
V_7 -> V_8 = NULL ;
if ( V_7 -> V_9 )
F_5 ( V_7 -> V_9 ) ;
V_7 -> V_9 = NULL ;
if ( V_7 -> V_10 )
F_5 ( V_7 -> V_10 ) ;
V_7 -> V_10 = NULL ;
if ( V_7 -> V_11 )
F_5 ( V_7 -> V_11 ) ;
V_7 -> V_11 = NULL ;
}
static int F_6 ( struct V_1 * V_7 )
{
struct V_4 * V_5 = V_7 -> V_5 ;
struct V_12 * V_8 ;
struct V_13 * V_9 , * V_10 , * V_11 ;
int V_14 , V_15 = V_5 -> V_16 ;
V_7 -> V_17 = V_7 -> V_18 -> V_17 [ V_5 -> V_19 ] ;
V_8 = F_7 ( V_7 -> V_17 , V_15 ) ;
if ( F_8 ( V_8 ) ) {
F_9 ( & V_5 -> V_3 , L_1 ) ;
V_14 = F_10 ( V_8 ) ;
goto V_20;
}
V_7 -> V_8 = V_8 ;
V_9 = F_11 ( V_7 -> V_17 , V_21 [ V_15 ] . V_9 ) ;
if ( F_8 ( V_9 ) ) {
F_9 ( & V_5 -> V_3 , L_2 ,
V_21 [ V_15 ] . V_9 ) ;
V_14 = F_10 ( V_9 ) ;
goto V_20;
}
V_7 -> V_9 = V_9 ;
V_10 = F_11 ( V_7 -> V_17 , V_21 [ V_15 ] . V_10 ) ;
if ( F_8 ( V_10 ) ) {
F_9 ( & V_5 -> V_3 , L_2 ,
V_21 [ V_15 ] . V_10 ) ;
V_14 = F_10 ( V_10 ) ;
goto V_20;
}
V_7 -> V_10 = V_10 ;
V_11 = F_11 ( V_7 -> V_17 , V_21 [ V_15 ] . V_11 ) ;
if ( F_8 ( V_11 ) ) {
F_9 ( & V_5 -> V_3 , L_2 ,
V_21 [ V_15 ] . V_11 ) ;
V_14 = F_10 ( V_11 ) ;
goto V_20;
}
V_7 -> V_11 = V_11 ;
return 0 ;
V_20:
F_3 ( V_7 ) ;
return V_14 ;
}
static void F_12 ( struct V_1 * V_7 , struct V_13 * V_22 )
{
struct V_23 * V_24 = V_7 -> V_24 ;
struct V_25 * V_26 , * V_27 ;
struct V_28 * V_29 ;
T_1 V_30 ;
V_26 = V_7 -> V_31 [ V_7 -> V_32 ] ;
if ( V_26 ) {
V_29 = & V_26 -> V_33 . V_34 ;
V_29 -> V_35 = F_13 () ;
F_14 ( V_29 , V_7 -> V_36 ?
V_37 : V_38 ) ;
}
V_7 -> V_36 = false ;
V_27 = F_15 ( V_24 ) ;
if ( V_27 ) {
V_30 = F_16 ( & V_27 -> V_33 . V_34 , 0 ) ;
V_7 -> V_31 [ V_7 -> V_32 ] = V_27 ;
} else {
V_30 = V_7 -> V_39 . V_30 ;
V_7 -> V_31 [ V_7 -> V_32 ] = NULL ;
}
if ( F_17 ( V_22 , V_7 -> V_32 ) )
F_18 ( V_22 , V_7 -> V_32 ) ;
F_19 ( V_22 , V_7 -> V_32 , V_30 ) ;
}
static T_2 F_20 ( int V_40 , void * V_41 )
{
struct V_1 * V_7 = V_41 ;
struct V_13 * V_42 ;
F_21 ( & V_7 -> V_43 ) ;
if ( V_7 -> V_44 ) {
F_22 ( & V_7 -> V_45 ) ;
V_7 -> V_44 = false ;
goto V_46;
}
V_42 = ( F_23 ( V_7 -> V_47 ) ) ?
V_7 -> V_11 : V_7 -> V_9 ;
F_12 ( V_7 , V_42 ) ;
F_24 ( V_42 , V_7 -> V_32 ) ;
V_7 -> V_32 ^= 1 ;
F_25 ( & V_7 -> V_48 ,
V_49 + F_26 ( V_50 ) ) ;
V_46:
F_27 ( & V_7 -> V_43 ) ;
return V_51 ;
}
static T_2 F_28 ( int V_40 , void * V_41 )
{
struct V_1 * V_7 = V_41 ;
struct V_4 * V_5 = V_7 -> V_5 ;
F_21 ( & V_7 -> V_43 ) ;
V_7 -> V_36 = true ;
F_9 ( & V_5 -> V_3 , L_3 ) ;
F_27 ( & V_7 -> V_43 ) ;
return V_51 ;
}
static void F_29 ( unsigned long V_52 )
{
struct V_1 * V_7 = (struct V_1 * ) V_52 ;
struct V_23 * V_24 = V_7 -> V_24 ;
struct V_4 * V_5 = V_7 -> V_5 ;
F_9 ( & V_5 -> V_3 , L_4 ) ;
F_30 ( V_24 ) ;
}
static void F_31 ( struct V_1 * V_7 , T_1 * V_30 )
{
struct V_23 * V_24 = V_7 -> V_24 ;
struct V_25 * V_53 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < 2 ; V_54 ++ ) {
V_53 = F_15 ( V_24 ) ;
if ( V_53 ) {
V_7 -> V_31 [ V_54 ] = V_53 ;
V_30 [ V_54 ] = F_16 (
& V_53 -> V_33 . V_34 , 0 ) ;
} else {
V_7 -> V_31 [ V_54 ] = NULL ;
V_30 [ V_54 ] = V_7 -> V_39 . V_30 ;
}
}
}
static void F_32 ( struct V_1 * V_7 ,
enum V_55 V_56 )
{
struct V_25 * V_53 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < 2 ; V_54 ++ ) {
V_53 = V_7 -> V_31 [ V_54 ] ;
if ( V_53 ) {
struct V_28 * V_29 = & V_53 -> V_33 . V_34 ;
V_29 -> V_35 = F_13 () ;
F_14 ( V_29 , V_56 ) ;
}
}
}
static int F_33 ( struct V_1 * V_7 ,
struct V_13 * V_42 ,
enum V_57 V_47 ,
T_1 V_58 , T_1 V_59 ,
bool V_60 )
{
struct V_23 * V_24 = V_7 -> V_24 ;
const struct V_61 * V_62 ;
struct V_63 * V_64 ;
unsigned int V_65 ;
struct V_66 V_67 ;
int V_14 ;
V_64 = & V_7 -> V_68 [ V_69 ] ;
V_62 = V_24 -> V_70 ;
F_34 ( V_42 ) ;
memset ( & V_67 , 0 , sizeof( V_67 ) ) ;
V_67 . V_71 = V_24 -> V_72 . V_72 . V_71 ;
V_67 . V_73 . V_74 = V_67 . V_71 . V_74 ;
V_67 . V_73 . V_75 = V_67 . V_71 . V_75 ;
if ( V_60 ) {
F_35 ( V_67 . V_71 . V_74 , V_67 . V_71 . V_75 ) ;
F_35 ( V_67 . V_73 . V_74 , V_67 . V_73 . V_75 ) ;
V_67 . V_71 . V_76 = V_62 -> V_77 ?
V_67 . V_71 . V_74 :
( V_67 . V_71 . V_74 * V_62 -> V_78 ) >> 3 ;
}
V_67 . V_79 = V_58 ;
V_67 . V_80 = V_59 ;
if ( V_42 == V_7 -> V_9 || V_42 == V_7 -> V_11 ) {
switch ( V_67 . V_71 . V_81 ) {
case V_82 :
case V_83 :
case V_84 :
F_36 ( V_42 ) ;
break;
}
}
V_14 = F_37 ( V_42 , & V_67 ) ;
if ( V_14 )
return V_14 ;
if ( V_42 == V_7 -> V_10 ||
V_42 == V_7 -> V_11 ) {
V_65 = 8 ;
F_38 ( V_42 ) ;
} else {
V_65 = ( V_67 . V_71 . V_74 & 0xf ) ? 8 : 16 ;
}
F_39 ( V_42 , V_65 ) ;
if ( V_47 )
F_40 ( V_42 , V_47 ) ;
if ( V_67 . V_71 . V_85 == V_86 &&
F_41 ( V_64 -> V_85 ) &&
V_42 == V_7 -> V_9 )
F_42 ( V_42 , V_67 . V_71 . V_76 ) ;
V_14 = F_43 ( V_7 -> V_8 , V_42 ,
V_67 . V_71 . V_74 , V_67 . V_71 . V_75 ,
V_65 , V_47 ) ;
if ( V_14 )
return V_14 ;
F_44 ( V_42 , 1 ) ;
F_45 ( V_42 , true ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_7 )
{
struct V_23 * V_24 = V_7 -> V_24 ;
struct V_4 * V_5 = V_7 -> V_5 ;
const struct V_61 * V_62 , * V_87 ;
struct V_63 * V_64 ;
struct V_88 * V_89 ;
T_1 V_30 [ 2 ] ;
int V_14 ;
V_64 = & V_7 -> V_68 [ V_69 ] ;
V_89 = & V_24 -> V_72 . V_72 . V_71 ;
V_87 = V_7 -> V_70 [ V_69 ] ;
V_62 = V_24 -> V_70 ;
V_14 = F_47 ( V_7 -> V_18 , & V_7 -> V_90 [ 0 ] ,
V_89 -> V_91 ) ;
if ( V_14 ) {
F_9 ( & V_5 -> V_3 , L_5 , V_14 ) ;
return V_14 ;
}
V_14 = F_47 ( V_7 -> V_18 , & V_7 -> V_90 [ 1 ] ,
V_89 -> V_91 ) ;
if ( V_14 ) {
F_9 ( & V_5 -> V_3 , L_6 , V_14 ) ;
goto V_92;
}
V_14 = F_48 ( V_7 -> V_8 ,
V_64 -> V_74 , V_64 -> V_75 ,
V_89 -> V_75 , V_89 -> V_74 ,
V_87 -> V_93 , V_62 -> V_93 ) ;
if ( V_14 ) {
F_9 ( & V_5 -> V_3 , L_7 , V_14 ) ;
goto V_94;
}
V_14 = F_33 ( V_7 , V_7 -> V_9 , V_95 ,
V_7 -> V_90 [ 0 ] . V_30 , V_7 -> V_90 [ 1 ] . V_30 ,
true ) ;
if ( V_14 ) {
F_9 ( & V_5 -> V_3 ,
L_8 , V_14 ) ;
goto V_94;
}
V_14 = F_33 ( V_7 , V_7 -> V_10 , V_7 -> V_47 ,
V_7 -> V_90 [ 0 ] . V_30 , V_7 -> V_90 [ 1 ] . V_30 ,
true ) ;
if ( V_14 ) {
F_9 ( & V_5 -> V_3 ,
L_9 , V_14 ) ;
goto V_94;
}
F_31 ( V_7 , V_30 ) ;
V_14 = F_33 ( V_7 , V_7 -> V_11 , V_95 ,
V_30 [ 0 ] , V_30 [ 1 ] ,
false ) ;
if ( V_14 ) {
F_9 ( & V_5 -> V_3 ,
L_10 , V_14 ) ;
goto V_96;
}
F_49 ( V_7 -> V_9 , V_7 -> V_10 ) ;
F_50 ( V_7 -> V_8 ) ;
F_24 ( V_7 -> V_9 , 0 ) ;
F_24 ( V_7 -> V_9 , 1 ) ;
F_24 ( V_7 -> V_11 , 0 ) ;
F_24 ( V_7 -> V_11 , 1 ) ;
F_51 ( V_7 -> V_9 ) ;
F_51 ( V_7 -> V_10 ) ;
F_51 ( V_7 -> V_11 ) ;
F_52 ( V_7 -> V_8 ) ;
return 0 ;
V_96:
F_32 ( V_7 , V_97 ) ;
V_94:
F_53 ( V_7 -> V_18 , & V_7 -> V_90 [ 1 ] ) ;
V_92:
F_53 ( V_7 -> V_18 , & V_7 -> V_90 [ 0 ] ) ;
return V_14 ;
}
static void F_54 ( struct V_1 * V_7 )
{
F_55 ( V_7 -> V_8 ) ;
F_56 ( V_7 -> V_9 ) ;
F_56 ( V_7 -> V_10 ) ;
F_56 ( V_7 -> V_11 ) ;
F_57 ( V_7 -> V_9 , V_7 -> V_10 ) ;
F_58 ( V_7 -> V_8 ) ;
F_53 ( V_7 -> V_18 , & V_7 -> V_90 [ 0 ] ) ;
F_53 ( V_7 -> V_18 , & V_7 -> V_90 [ 1 ] ) ;
}
static int F_59 ( struct V_1 * V_7 )
{
struct V_23 * V_24 = V_7 -> V_24 ;
struct V_4 * V_5 = V_7 -> V_5 ;
const struct V_61 * V_62 , * V_87 ;
struct V_63 * V_64 ;
struct V_88 * V_89 ;
T_1 V_30 [ 2 ] ;
int V_14 ;
V_64 = & V_7 -> V_68 [ V_69 ] ;
V_89 = & V_24 -> V_72 . V_72 . V_71 ;
V_87 = V_7 -> V_70 [ V_69 ] ;
V_62 = V_24 -> V_70 ;
V_14 = F_48 ( V_7 -> V_8 ,
V_64 -> V_74 , V_64 -> V_75 ,
V_89 -> V_74 , V_89 -> V_75 ,
V_87 -> V_93 , V_62 -> V_93 ) ;
if ( V_14 ) {
F_9 ( & V_5 -> V_3 , L_7 , V_14 ) ;
return V_14 ;
}
F_31 ( V_7 , V_30 ) ;
V_14 = F_33 ( V_7 , V_7 -> V_9 , V_7 -> V_47 ,
V_30 [ 0 ] , V_30 [ 1 ] , false ) ;
if ( V_14 ) {
F_9 ( & V_5 -> V_3 ,
L_8 , V_14 ) ;
goto V_96;
}
F_60 ( V_7 -> V_9 ) ;
F_61 ( V_7 -> V_8 ) ;
F_62 ( V_7 -> V_17 ) ;
F_50 ( V_7 -> V_8 ) ;
F_24 ( V_7 -> V_9 , 0 ) ;
F_24 ( V_7 -> V_9 , 1 ) ;
F_51 ( V_7 -> V_9 ) ;
F_52 ( V_7 -> V_8 ) ;
return 0 ;
V_96:
F_32 ( V_7 , V_97 ) ;
return V_14 ;
}
static void F_63 ( struct V_1 * V_7 )
{
F_55 ( V_7 -> V_8 ) ;
F_56 ( V_7 -> V_9 ) ;
F_58 ( V_7 -> V_8 ) ;
}
static void F_64 ( struct V_1 * V_7 ,
enum V_55 V_98 )
{
if ( F_23 ( V_7 -> V_47 ) )
F_54 ( V_7 ) ;
else
F_63 ( V_7 ) ;
F_32 ( V_7 , V_98 ) ;
}
static int F_65 ( struct V_1 * V_7 )
{
struct V_4 * V_5 = V_7 -> V_5 ;
struct V_23 * V_24 = V_7 -> V_24 ;
struct V_88 * V_89 ;
int V_14 ;
V_14 = F_6 ( V_7 ) ;
if ( V_14 )
return V_14 ;
V_89 = & V_24 -> V_72 . V_72 . V_71 ;
V_14 = F_47 ( V_7 -> V_18 , & V_7 -> V_39 ,
V_89 -> V_91 ) ;
if ( V_14 )
goto V_99;
V_7 -> V_32 = 0 ;
F_66 ( & V_7 -> V_45 ) ;
V_7 -> V_44 = false ;
V_7 -> V_36 = false ;
if ( F_23 ( V_7 -> V_47 ) )
V_14 = F_46 ( V_7 ) ;
else
V_14 = F_59 ( V_7 ) ;
if ( V_14 )
goto V_100;
V_7 -> V_101 = F_67 ( V_7 -> V_17 ,
V_7 -> V_9 ,
V_102 ) ;
V_14 = F_68 ( V_5 -> V_103 , V_7 -> V_101 ,
F_28 , 0 ,
L_11 , V_7 ) ;
if ( V_14 ) {
F_9 ( & V_5 -> V_3 ,
L_12 , V_14 ) ;
goto V_104;
}
if ( F_23 ( V_7 -> V_47 ) )
V_7 -> V_105 = F_67 (
V_7 -> V_17 , V_7 -> V_11 , V_106 ) ;
else
V_7 -> V_105 = F_67 (
V_7 -> V_17 , V_7 -> V_9 , V_106 ) ;
V_14 = F_68 ( V_5 -> V_103 , V_7 -> V_105 ,
F_20 , 0 ,
L_13 , V_7 ) ;
if ( V_14 ) {
F_9 ( & V_5 -> V_3 ,
L_14 , V_14 ) ;
goto V_107;
}
F_25 ( & V_7 -> V_48 ,
V_49 + F_26 ( V_50 ) ) ;
return 0 ;
V_107:
F_69 ( V_5 -> V_103 , V_7 -> V_101 , V_7 ) ;
V_104:
F_64 ( V_7 , V_97 ) ;
V_100:
F_53 ( V_7 -> V_18 , & V_7 -> V_39 ) ;
V_99:
F_3 ( V_7 ) ;
return V_14 ;
}
static void F_70 ( struct V_1 * V_7 )
{
struct V_4 * V_5 = V_7 -> V_5 ;
unsigned long V_108 ;
int V_14 ;
F_71 ( & V_7 -> V_43 , V_108 ) ;
V_7 -> V_44 = true ;
F_72 ( & V_7 -> V_43 , V_108 ) ;
V_14 = F_73 (
& V_7 -> V_45 ,
F_26 ( V_50 ) ) ;
if ( V_14 == 0 )
F_74 ( & V_5 -> V_3 , L_15 ) ;
F_69 ( V_5 -> V_103 , V_7 -> V_105 , V_7 ) ;
F_69 ( V_5 -> V_103 , V_7 -> V_101 , V_7 ) ;
F_64 ( V_7 , V_37 ) ;
F_53 ( V_7 -> V_18 , & V_7 -> V_39 ) ;
F_75 ( & V_7 -> V_48 ) ;
F_3 ( V_7 ) ;
}
static struct V_63 *
F_76 ( struct V_1 * V_7 , struct V_109 * V_110 ,
unsigned int V_111 , enum V_112 V_113 )
{
struct V_4 * V_5 = V_7 -> V_5 ;
if ( V_113 == V_114 )
return F_77 ( & V_5 -> V_3 , V_110 , V_111 ) ;
else
return & V_7 -> V_68 [ V_111 ] ;
}
static bool F_78 ( struct V_63 * V_89 ,
struct V_63 * V_64 ,
enum V_57 V_47 )
{
T_3 V_115 = V_89 -> V_74 ;
T_3 V_116 = V_89 -> V_75 ;
if ( F_23 ( V_47 ) )
F_79 ( & V_89 -> V_74 ,
V_64 -> V_75 / 4 , V_117 ,
V_118 ,
& V_89 -> V_75 ,
V_64 -> V_74 / 4 , V_119 ,
V_118 , V_120 ) ;
else
F_79 ( & V_89 -> V_74 ,
V_64 -> V_74 / 4 , V_119 ,
V_118 ,
& V_89 -> V_75 ,
V_64 -> V_75 / 4 , V_117 ,
V_121 , V_120 ) ;
return V_89 -> V_74 != V_115 || V_89 -> V_75 != V_116 ;
}
static int F_80 ( struct V_2 * V_3 ,
struct V_109 * V_110 ,
struct V_122 * V_123 )
{
if ( V_123 -> V_111 >= V_124 )
return - V_125 ;
return F_81 ( & V_123 -> V_123 , V_123 -> V_126 , V_127 ) ;
}
static int F_82 ( struct V_2 * V_3 ,
struct V_109 * V_110 ,
struct V_128 * V_129 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_63 * V_72 ;
int V_14 = 0 ;
if ( V_129 -> V_111 >= V_124 )
return - V_125 ;
F_83 ( & V_7 -> V_130 ) ;
V_72 = F_76 ( V_7 , V_110 , V_129 -> V_111 , V_129 -> V_113 ) ;
if ( ! V_72 ) {
V_14 = - V_125 ;
goto V_20;
}
V_129 -> V_131 = * V_72 ;
V_20:
F_84 ( & V_7 -> V_130 ) ;
return V_14 ;
}
static void F_85 ( struct V_1 * V_7 ,
struct V_109 * V_110 ,
struct V_128 * V_129 ,
const struct V_61 * * V_70 )
{
struct V_63 * V_64 ;
* V_70 = F_86 ( V_129 -> V_131 . V_123 , V_127 ) ;
if ( ! * V_70 ) {
T_3 V_123 ;
F_81 ( & V_123 , 0 , V_127 ) ;
* V_70 = F_86 ( V_123 , V_127 ) ;
V_129 -> V_131 . V_123 = ( * V_70 ) -> V_132 [ 0 ] ;
}
V_64 = F_76 ( V_7 , V_110 , V_69 , V_129 -> V_113 ) ;
if ( V_129 -> V_111 == V_133 ) {
if ( V_129 -> V_131 . V_85 != V_86 )
V_129 -> V_131 . V_85 = V_64 -> V_85 ;
F_78 ( & V_129 -> V_131 , V_64 ,
V_7 -> V_47 ) ;
V_129 -> V_131 . V_134 = V_64 -> V_134 ;
V_129 -> V_131 . V_135 = V_64 -> V_135 ;
V_129 -> V_131 . V_136 = V_64 -> V_136 ;
V_129 -> V_131 . V_137 = V_64 -> V_137 ;
} else {
F_79 ( & V_129 -> V_131 . V_74 ,
V_138 , V_139 , V_140 ,
& V_129 -> V_131 . V_75 ,
V_141 , V_142 , V_143 ,
V_120 ) ;
F_87 ( & V_129 -> V_131 , V_64 ,
true ) ;
}
}
static int F_88 ( struct V_2 * V_3 ,
struct V_109 * V_110 ,
struct V_128 * V_129 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_23 * V_24 = V_7 -> V_24 ;
const struct V_61 * V_70 ;
struct V_88 V_144 ;
struct V_63 * V_72 ;
int V_14 = 0 ;
if ( V_129 -> V_111 >= V_124 )
return - V_125 ;
F_83 ( & V_7 -> V_130 ) ;
if ( V_7 -> V_145 > 0 ) {
V_14 = - V_146 ;
goto V_20;
}
F_85 ( V_7 , V_110 , V_129 , & V_70 ) ;
V_72 = F_76 ( V_7 , V_110 , V_129 -> V_111 , V_129 -> V_113 ) ;
* V_72 = V_129 -> V_131 ;
if ( V_129 -> V_111 == V_69 ) {
const struct V_61 * V_62 ;
struct V_63 * V_89 ;
struct V_128 V_131 ;
V_131 . V_111 = V_133 ;
V_131 . V_113 = V_129 -> V_113 ;
V_131 . V_131 = V_129 -> V_131 ;
F_85 ( V_7 , V_110 , & V_131 , & V_62 ) ;
V_89 = F_76 ( V_7 , V_110 , V_133 ,
V_129 -> V_113 ) ;
* V_89 = V_131 . V_131 ;
if ( V_129 -> V_113 == V_147 )
V_7 -> V_70 [ V_133 ] = V_62 ;
}
if ( V_129 -> V_113 == V_114 )
goto V_20;
V_7 -> V_70 [ V_129 -> V_111 ] = V_70 ;
F_89 ( & V_144 ,
& V_7 -> V_68 [ V_133 ] ,
V_7 -> V_70 [ V_133 ] ) ;
F_84 ( & V_7 -> V_130 ) ;
F_90 ( V_24 , & V_144 ) ;
return 0 ;
V_20:
F_84 ( & V_7 -> V_130 ) ;
return V_14 ;
}
static int F_91 ( struct V_2 * V_3 ,
struct V_109 * V_110 ,
struct V_148 * V_149 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_128 V_131 = { 0 } ;
const struct V_61 * V_70 ;
int V_14 = 0 ;
if ( V_149 -> V_111 >= V_124 || V_149 -> V_126 != 0 )
return - V_125 ;
F_83 ( & V_7 -> V_130 ) ;
V_131 . V_111 = V_149 -> V_111 ;
V_131 . V_113 = V_149 -> V_113 ;
V_131 . V_131 . V_123 = V_149 -> V_123 ;
V_131 . V_131 . V_74 = 1 ;
V_131 . V_131 . V_75 = 1 ;
F_85 ( V_7 , V_110 , & V_131 , & V_70 ) ;
V_149 -> V_150 = V_131 . V_131 . V_74 ;
V_149 -> V_151 = V_131 . V_131 . V_75 ;
if ( V_131 . V_131 . V_123 != V_149 -> V_123 ) {
V_14 = - V_125 ;
goto V_20;
}
V_131 . V_131 . V_123 = V_149 -> V_123 ;
V_131 . V_131 . V_74 = - 1 ;
V_131 . V_131 . V_75 = - 1 ;
F_85 ( V_7 , V_110 , & V_131 , & V_70 ) ;
V_149 -> V_152 = V_131 . V_131 . V_74 ;
V_149 -> V_153 = V_131 . V_131 . V_75 ;
V_20:
F_84 ( & V_7 -> V_130 ) ;
return V_14 ;
}
static int F_92 ( struct V_154 * V_155 ,
const struct V_156 * V_157 ,
const struct V_156 * V_158 , T_3 V_108 )
{
struct V_2 * V_3 = F_93 ( V_155 ) ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_7 = V_5 -> V_6 ;
struct V_2 * V_159 ;
int V_14 = 0 ;
F_94 ( V_5 -> V_103 , L_16 , V_158 -> V_155 -> V_160 ,
V_157 -> V_155 -> V_160 ) ;
F_83 ( & V_7 -> V_130 ) ;
if ( V_157 -> V_108 & V_161 ) {
if ( ! F_95 ( V_158 -> V_155 ) ) {
V_14 = - V_125 ;
goto V_20;
}
V_159 = F_93 ( V_158 -> V_155 ) ;
if ( V_108 & V_162 ) {
if ( V_7 -> V_163 ) {
V_14 = - V_146 ;
goto V_20;
}
V_7 -> V_163 = V_159 ;
} else {
V_7 -> V_163 = NULL ;
}
goto V_20;
}
if ( ! F_96 ( V_158 -> V_155 ) ) {
V_14 = - V_125 ;
goto V_20;
}
if ( V_108 & V_162 ) {
if ( V_7 -> V_164 ) {
V_14 = - V_146 ;
goto V_20;
}
} else {
V_7 -> V_164 = NULL ;
goto V_20;
}
V_7 -> V_164 = V_158 -> V_155 ;
V_20:
F_84 ( & V_7 -> V_130 ) ;
return V_14 ;
}
static int F_97 ( struct V_165 * V_166 )
{
struct V_1 * V_7 = F_98 ( V_166 -> V_167 ,
struct V_1 , V_168 ) ;
struct V_4 * V_5 = V_7 -> V_5 ;
enum V_57 V_47 ;
int V_169 , V_14 = 0 ;
bool V_170 , V_171 ;
F_83 ( & V_7 -> V_130 ) ;
V_169 = V_7 -> V_169 ;
V_170 = V_7 -> V_170 ;
V_171 = V_7 -> V_171 ;
switch ( V_166 -> V_172 ) {
case V_173 :
V_170 = ( V_166 -> V_174 == 1 ) ;
break;
case V_175 :
V_171 = ( V_166 -> V_174 == 1 ) ;
break;
case V_176 :
V_169 = V_166 -> V_174 ;
break;
default:
F_9 ( & V_5 -> V_3 , L_17 ) ;
V_14 = - V_125 ;
goto V_20;
}
V_14 = F_99 ( & V_47 , V_169 , V_170 , V_171 ) ;
if ( V_14 )
goto V_20;
if ( V_47 != V_7 -> V_47 ) {
struct V_63 V_89 , V_64 ;
if ( V_7 -> V_145 > 0 ) {
V_14 = - V_146 ;
goto V_20;
}
V_89 = V_7 -> V_68 [ V_133 ] ;
V_64 = V_7 -> V_68 [ V_69 ] ;
if ( F_78 ( & V_89 , & V_64 , V_47 ) ) {
V_14 = - V_125 ;
goto V_20;
}
V_7 -> V_47 = V_47 ;
V_7 -> V_169 = V_169 ;
V_7 -> V_170 = V_170 ;
V_7 -> V_171 = V_171 ;
}
V_20:
F_84 ( & V_7 -> V_130 ) ;
return V_14 ;
}
static int F_100 ( struct V_1 * V_7 )
{
struct V_4 * V_5 = V_7 -> V_5 ;
struct V_177 * V_178 = & V_7 -> V_168 ;
int V_14 ;
F_101 ( V_178 , 3 ) ;
F_102 ( V_178 , & V_179 , V_173 ,
0 , 1 , 1 , 0 ) ;
F_102 ( V_178 , & V_179 , V_175 ,
0 , 1 , 1 , 0 ) ;
F_102 ( V_178 , & V_179 , V_176 ,
0 , 270 , 90 , 0 ) ;
V_5 -> V_3 . V_180 = V_178 ;
if ( V_178 -> error ) {
V_14 = V_178 -> error ;
goto V_181;
}
F_103 ( V_178 ) ;
return 0 ;
V_181:
F_104 ( V_178 ) ;
return V_14 ;
}
static int F_105 ( struct V_2 * V_3 , int V_182 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_7 = V_5 -> V_6 ;
int V_14 = 0 ;
F_83 ( & V_7 -> V_130 ) ;
if ( ! V_7 -> V_163 || ! V_7 -> V_164 ) {
V_14 = - V_183 ;
goto V_20;
}
if ( V_7 -> V_145 != ! V_182 )
goto V_184;
F_94 ( V_5 -> V_103 , L_18 , V_182 ? L_19 : L_20 ) ;
if ( V_182 )
V_14 = F_65 ( V_7 ) ;
else
F_70 ( V_7 ) ;
if ( V_14 )
goto V_20;
V_14 = F_106 ( V_7 -> V_163 , V_185 , V_186 , V_182 ) ;
V_14 = ( V_14 && V_14 != - V_187 ) ? V_14 : 0 ;
if ( V_14 ) {
if ( V_182 )
F_70 ( V_7 ) ;
goto V_20;
}
V_184:
V_7 -> V_145 += V_182 ? 1 : - 1 ;
if ( V_7 -> V_145 < 0 )
V_7 -> V_145 = 0 ;
V_20:
F_84 ( & V_7 -> V_130 ) ;
return V_14 ;
}
static int F_107 ( struct V_2 * V_3 ,
struct V_188 * V_189 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
if ( V_189 -> V_111 >= V_124 )
return - V_125 ;
F_83 ( & V_7 -> V_130 ) ;
V_189 -> V_190 = V_7 -> V_191 ;
F_84 ( & V_7 -> V_130 ) ;
return 0 ;
}
static int F_108 ( struct V_2 * V_3 ,
struct V_188 * V_189 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
if ( V_189 -> V_111 >= V_124 )
return - V_125 ;
F_83 ( & V_7 -> V_130 ) ;
V_7 -> V_191 = V_189 -> V_190 ;
F_84 ( & V_7 -> V_130 ) ;
return 0 ;
}
static int F_109 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_54 , V_14 ;
T_3 V_123 ;
V_7 -> V_18 = F_110 ( V_3 -> V_192 -> V_103 ) ;
for ( V_54 = 0 ; V_54 < V_124 ; V_54 ++ ) {
V_7 -> V_111 [ V_54 ] . V_108 = ( V_54 == V_69 ) ?
V_161 : V_193 ;
F_81 ( & V_123 , 0 , V_194 ) ;
V_14 = F_111 ( & V_7 -> V_68 [ V_54 ] ,
640 , 480 , V_123 , V_86 ,
& V_7 -> V_70 [ V_54 ] ) ;
if ( V_14 )
return V_14 ;
}
V_7 -> V_191 . V_195 = 1 ;
V_7 -> V_191 . V_196 = 30 ;
V_14 = F_112 ( & V_3 -> V_155 , V_124 ,
V_7 -> V_111 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_113 ( V_7 -> V_24 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_114 ( V_7 -> V_18 , V_7 -> V_24 ) ;
if ( V_14 )
goto V_197;
V_14 = F_100 ( V_7 ) ;
if ( V_14 )
goto V_197;
return 0 ;
V_197:
F_115 ( V_7 -> V_24 ) ;
return V_14 ;
}
static void F_116 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_115 ( V_7 -> V_24 ) ;
F_104 ( & V_7 -> V_168 ) ;
}
static int F_117 ( struct V_4 * V_5 )
{
struct V_1 * V_7 ;
V_7 = F_118 ( V_5 -> V_103 , sizeof( * V_7 ) , V_198 ) ;
if ( ! V_7 )
return - V_199 ;
V_5 -> V_6 = V_7 ;
V_7 -> V_5 = V_5 ;
F_119 ( & V_7 -> V_43 ) ;
F_120 ( & V_7 -> V_48 , F_29 ,
( unsigned long ) V_7 ) ;
V_7 -> V_24 = F_121 ( & V_5 -> V_3 ,
V_133 ) ;
if ( F_8 ( V_7 -> V_24 ) )
return F_10 ( V_7 -> V_24 ) ;
F_122 ( & V_7 -> V_130 ) ;
return 0 ;
}
static void F_123 ( struct V_4 * V_5 )
{
struct V_1 * V_7 = V_5 -> V_6 ;
F_124 ( & V_7 -> V_130 ) ;
F_125 ( V_7 -> V_24 ) ;
}
