static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return V_5 -> V_6 ;
}
static void F_3 ( struct V_1 * V_7 )
{
if ( ! F_4 ( V_7 -> V_8 ) )
F_5 ( V_7 -> V_8 ) ;
V_7 -> V_8 = NULL ;
if ( ! F_4 ( V_7 -> V_9 ) )
F_6 ( V_7 -> V_9 ) ;
V_7 -> V_9 = NULL ;
if ( ! F_4 ( V_7 -> V_10 ) )
F_6 ( V_7 -> V_10 ) ;
V_7 -> V_10 = NULL ;
if ( ! F_4 ( V_7 -> V_11 ) )
F_6 ( V_7 -> V_11 ) ;
V_7 -> V_11 = NULL ;
}
static int F_7 ( struct V_1 * V_7 )
{
struct V_4 * V_5 = V_7 -> V_5 ;
int V_12 , V_13 = V_5 -> V_14 ;
V_7 -> V_15 = V_7 -> V_16 -> V_15 [ V_5 -> V_17 ] ;
V_7 -> V_8 = F_8 ( V_7 -> V_15 , V_13 ) ;
if ( F_9 ( V_7 -> V_8 ) ) {
F_10 ( & V_5 -> V_3 , L_1 ) ;
V_12 = F_11 ( V_7 -> V_8 ) ;
goto V_18;
}
V_7 -> V_9 = F_12 ( V_7 -> V_15 ,
V_19 [ V_13 ] . V_9 ) ;
if ( F_9 ( V_7 -> V_9 ) ) {
F_10 ( & V_5 -> V_3 , L_2 ,
V_19 [ V_13 ] . V_9 ) ;
V_12 = F_11 ( V_7 -> V_9 ) ;
goto V_18;
}
V_7 -> V_10 = F_12 ( V_7 -> V_15 ,
V_19 [ V_13 ] . V_10 ) ;
if ( F_9 ( V_7 -> V_10 ) ) {
F_10 ( & V_5 -> V_3 , L_2 ,
V_19 [ V_13 ] . V_10 ) ;
V_12 = F_11 ( V_7 -> V_10 ) ;
goto V_18;
}
V_7 -> V_11 = F_12 ( V_7 -> V_15 ,
V_19 [ V_13 ] . V_11 ) ;
if ( F_9 ( V_7 -> V_11 ) ) {
F_10 ( & V_5 -> V_3 , L_2 ,
V_19 [ V_13 ] . V_11 ) ;
V_12 = F_11 ( V_7 -> V_11 ) ;
goto V_18;
}
return 0 ;
V_18:
F_3 ( V_7 ) ;
return V_12 ;
}
static void F_13 ( struct V_1 * V_7 , struct V_20 * V_21 )
{
struct V_22 * V_23 = V_7 -> V_23 ;
struct V_24 * V_25 , * V_26 ;
struct V_27 * V_28 ;
T_1 V_29 ;
V_25 = V_7 -> V_30 [ V_7 -> V_31 ] ;
if ( V_25 ) {
V_28 = & V_25 -> V_32 . V_33 ;
V_28 -> V_34 = F_14 () ;
F_15 ( V_28 , V_7 -> V_35 ?
V_36 : V_37 ) ;
}
V_7 -> V_35 = false ;
V_26 = F_16 ( V_23 ) ;
if ( V_26 ) {
V_29 = F_17 ( & V_26 -> V_32 . V_33 , 0 ) ;
V_7 -> V_30 [ V_7 -> V_31 ] = V_26 ;
} else {
V_29 = V_7 -> V_38 . V_29 ;
V_7 -> V_30 [ V_7 -> V_31 ] = NULL ;
}
if ( F_18 ( V_21 , V_7 -> V_31 ) )
F_19 ( V_21 , V_7 -> V_31 ) ;
F_20 ( V_21 , V_7 -> V_31 , V_29 ) ;
}
static T_2 F_21 ( int V_39 , void * V_40 )
{
struct V_1 * V_7 = V_40 ;
struct V_20 * V_41 ;
F_22 ( & V_7 -> V_42 ) ;
if ( V_7 -> V_43 ) {
F_23 ( & V_7 -> V_44 ) ;
V_7 -> V_43 = false ;
goto V_45;
}
V_41 = ( F_24 ( V_7 -> V_46 ) ) ?
V_7 -> V_11 : V_7 -> V_9 ;
F_13 ( V_7 , V_41 ) ;
F_25 ( V_41 , V_7 -> V_31 ) ;
V_7 -> V_31 ^= 1 ;
F_26 ( & V_7 -> V_47 ,
V_48 + F_27 ( V_49 ) ) ;
V_45:
F_28 ( & V_7 -> V_42 ) ;
return V_50 ;
}
static T_2 F_29 ( int V_39 , void * V_40 )
{
struct V_1 * V_7 = V_40 ;
struct V_4 * V_5 = V_7 -> V_5 ;
F_22 ( & V_7 -> V_42 ) ;
V_7 -> V_35 = true ;
F_10 ( & V_5 -> V_3 , L_3 ) ;
F_28 ( & V_7 -> V_42 ) ;
return V_50 ;
}
static void F_30 ( unsigned long V_51 )
{
struct V_1 * V_7 = (struct V_1 * ) V_51 ;
struct V_22 * V_23 = V_7 -> V_23 ;
struct V_4 * V_5 = V_7 -> V_5 ;
F_10 ( & V_5 -> V_3 , L_4 ) ;
F_31 ( V_23 ) ;
}
static void F_32 ( struct V_1 * V_7 , T_1 * V_29 )
{
struct V_22 * V_23 = V_7 -> V_23 ;
struct V_24 * V_52 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < 2 ; V_53 ++ ) {
V_52 = F_16 ( V_23 ) ;
if ( V_52 ) {
V_7 -> V_30 [ V_53 ] = V_52 ;
V_29 [ V_53 ] = F_17 (
& V_52 -> V_32 . V_33 , 0 ) ;
} else {
V_7 -> V_30 [ V_53 ] = NULL ;
V_29 [ V_53 ] = V_7 -> V_38 . V_29 ;
}
}
}
static void F_33 ( struct V_1 * V_7 ,
enum V_54 V_55 )
{
struct V_24 * V_52 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < 2 ; V_53 ++ ) {
V_52 = V_7 -> V_30 [ V_53 ] ;
if ( V_52 ) {
struct V_27 * V_28 = & V_52 -> V_32 . V_33 ;
V_28 -> V_34 = F_14 () ;
F_15 ( V_28 , V_55 ) ;
}
}
}
static int F_34 ( struct V_1 * V_7 ,
struct V_20 * V_41 ,
enum V_56 V_46 ,
T_1 V_57 , T_1 V_58 ,
bool V_59 )
{
struct V_22 * V_23 = V_7 -> V_23 ;
const struct V_60 * V_61 ;
struct V_62 * V_63 ;
unsigned int V_64 ;
struct V_65 V_66 ;
int V_12 ;
V_63 = & V_7 -> V_67 [ V_68 ] ;
V_61 = V_23 -> V_69 ;
F_35 ( V_41 ) ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
V_66 . V_70 = V_23 -> V_71 . V_71 . V_70 ;
V_66 . V_72 . V_73 = V_66 . V_70 . V_73 ;
V_66 . V_72 . V_74 = V_66 . V_70 . V_74 ;
if ( V_59 ) {
F_36 ( V_66 . V_70 . V_73 , V_66 . V_70 . V_74 ) ;
F_36 ( V_66 . V_72 . V_73 , V_66 . V_72 . V_74 ) ;
V_66 . V_70 . V_75 = V_61 -> V_76 ?
V_66 . V_70 . V_73 :
( V_66 . V_70 . V_73 * V_61 -> V_77 ) >> 3 ;
}
V_66 . V_78 = V_57 ;
V_66 . V_79 = V_58 ;
V_12 = F_37 ( V_41 , & V_66 ) ;
if ( V_12 )
return V_12 ;
if ( V_41 == V_7 -> V_10 ||
V_41 == V_7 -> V_11 ) {
V_64 = 8 ;
F_38 ( V_41 ) ;
} else {
V_64 = ( V_66 . V_70 . V_73 & 0xf ) ? 8 : 16 ;
}
F_39 ( V_41 , V_64 ) ;
if ( V_46 )
F_40 ( V_41 , V_46 ) ;
if ( V_66 . V_70 . V_80 == V_81 &&
F_41 ( V_63 -> V_80 ) &&
V_41 == V_7 -> V_9 )
F_42 ( V_41 , V_66 . V_70 . V_75 ) ;
V_12 = F_43 ( V_7 -> V_8 , V_41 ,
V_66 . V_70 . V_73 , V_66 . V_70 . V_74 ,
V_64 , V_46 ) ;
if ( V_12 )
return V_12 ;
F_44 ( V_41 , 1 ) ;
F_45 ( V_41 , true ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_7 )
{
struct V_22 * V_23 = V_7 -> V_23 ;
struct V_4 * V_5 = V_7 -> V_5 ;
const struct V_60 * V_61 , * V_82 ;
struct V_62 * V_63 ;
struct V_83 * V_84 ;
T_1 V_29 [ 2 ] ;
int V_12 ;
V_63 = & V_7 -> V_67 [ V_68 ] ;
V_84 = & V_23 -> V_71 . V_71 . V_70 ;
V_82 = V_7 -> V_69 [ V_68 ] ;
V_61 = V_23 -> V_69 ;
V_12 = F_47 ( V_7 -> V_16 , & V_7 -> V_85 [ 0 ] ,
V_84 -> V_86 ) ;
if ( V_12 ) {
F_10 ( & V_5 -> V_3 , L_5 , V_12 ) ;
return V_12 ;
}
V_12 = F_47 ( V_7 -> V_16 , & V_7 -> V_85 [ 1 ] ,
V_84 -> V_86 ) ;
if ( V_12 ) {
F_10 ( & V_5 -> V_3 , L_6 , V_12 ) ;
goto V_87;
}
V_12 = F_48 ( V_7 -> V_8 ,
V_63 -> V_73 , V_63 -> V_74 ,
V_84 -> V_74 , V_84 -> V_73 ,
V_82 -> V_88 , V_61 -> V_88 ) ;
if ( V_12 ) {
F_10 ( & V_5 -> V_3 , L_7 , V_12 ) ;
goto V_89;
}
V_12 = F_34 ( V_7 , V_7 -> V_9 , V_90 ,
V_7 -> V_85 [ 0 ] . V_29 , V_7 -> V_85 [ 1 ] . V_29 ,
true ) ;
if ( V_12 ) {
F_10 ( & V_5 -> V_3 ,
L_8 , V_12 ) ;
goto V_89;
}
V_12 = F_34 ( V_7 , V_7 -> V_10 , V_7 -> V_46 ,
V_7 -> V_85 [ 0 ] . V_29 , V_7 -> V_85 [ 1 ] . V_29 ,
true ) ;
if ( V_12 ) {
F_10 ( & V_5 -> V_3 ,
L_9 , V_12 ) ;
goto V_89;
}
F_32 ( V_7 , V_29 ) ;
V_12 = F_34 ( V_7 , V_7 -> V_11 , V_90 ,
V_29 [ 0 ] , V_29 [ 1 ] ,
false ) ;
if ( V_12 ) {
F_10 ( & V_5 -> V_3 ,
L_10 , V_12 ) ;
goto V_91;
}
F_49 ( V_7 -> V_9 , V_7 -> V_10 ) ;
F_50 ( V_7 -> V_8 ) ;
F_25 ( V_7 -> V_9 , 0 ) ;
F_25 ( V_7 -> V_9 , 1 ) ;
F_25 ( V_7 -> V_11 , 0 ) ;
F_25 ( V_7 -> V_11 , 1 ) ;
F_51 ( V_7 -> V_9 ) ;
F_51 ( V_7 -> V_10 ) ;
F_51 ( V_7 -> V_11 ) ;
F_52 ( V_7 -> V_8 ) ;
return 0 ;
V_91:
F_33 ( V_7 , V_92 ) ;
V_89:
F_53 ( V_7 -> V_16 , & V_7 -> V_85 [ 1 ] ) ;
V_87:
F_53 ( V_7 -> V_16 , & V_7 -> V_85 [ 0 ] ) ;
return V_12 ;
}
static void F_54 ( struct V_1 * V_7 )
{
F_55 ( V_7 -> V_8 ) ;
F_56 ( V_7 -> V_9 ) ;
F_56 ( V_7 -> V_10 ) ;
F_56 ( V_7 -> V_11 ) ;
F_57 ( V_7 -> V_9 , V_7 -> V_10 ) ;
F_58 ( V_7 -> V_8 ) ;
F_53 ( V_7 -> V_16 , & V_7 -> V_85 [ 0 ] ) ;
F_53 ( V_7 -> V_16 , & V_7 -> V_85 [ 1 ] ) ;
}
static int F_59 ( struct V_1 * V_7 )
{
struct V_22 * V_23 = V_7 -> V_23 ;
struct V_4 * V_5 = V_7 -> V_5 ;
const struct V_60 * V_61 , * V_82 ;
struct V_62 * V_63 ;
struct V_83 * V_84 ;
T_1 V_29 [ 2 ] ;
int V_12 ;
V_63 = & V_7 -> V_67 [ V_68 ] ;
V_84 = & V_23 -> V_71 . V_71 . V_70 ;
V_82 = V_7 -> V_69 [ V_68 ] ;
V_61 = V_23 -> V_69 ;
V_12 = F_48 ( V_7 -> V_8 ,
V_63 -> V_73 , V_63 -> V_74 ,
V_84 -> V_73 , V_84 -> V_74 ,
V_82 -> V_88 , V_61 -> V_88 ) ;
if ( V_12 ) {
F_10 ( & V_5 -> V_3 , L_7 , V_12 ) ;
return V_12 ;
}
F_32 ( V_7 , V_29 ) ;
V_12 = F_34 ( V_7 , V_7 -> V_9 , V_7 -> V_46 ,
V_29 [ 0 ] , V_29 [ 1 ] , false ) ;
if ( V_12 ) {
F_10 ( & V_5 -> V_3 ,
L_8 , V_12 ) ;
goto V_91;
}
F_60 ( V_7 -> V_9 ) ;
F_61 ( V_7 -> V_8 ) ;
F_62 ( V_7 -> V_15 ) ;
F_50 ( V_7 -> V_8 ) ;
F_25 ( V_7 -> V_9 , 0 ) ;
F_25 ( V_7 -> V_9 , 1 ) ;
F_51 ( V_7 -> V_9 ) ;
F_52 ( V_7 -> V_8 ) ;
return 0 ;
V_91:
F_33 ( V_7 , V_92 ) ;
return V_12 ;
}
static void F_63 ( struct V_1 * V_7 )
{
F_55 ( V_7 -> V_8 ) ;
F_56 ( V_7 -> V_9 ) ;
F_58 ( V_7 -> V_8 ) ;
}
static void F_64 ( struct V_1 * V_7 ,
enum V_54 V_93 )
{
if ( F_24 ( V_7 -> V_46 ) )
F_54 ( V_7 ) ;
else
F_63 ( V_7 ) ;
F_33 ( V_7 , V_93 ) ;
}
static int F_65 ( struct V_1 * V_7 )
{
struct V_4 * V_5 = V_7 -> V_5 ;
struct V_22 * V_23 = V_7 -> V_23 ;
struct V_83 * V_84 ;
int V_12 ;
V_12 = F_7 ( V_7 ) ;
if ( V_12 )
return V_12 ;
V_84 = & V_23 -> V_71 . V_71 . V_70 ;
V_12 = F_47 ( V_7 -> V_16 , & V_7 -> V_38 ,
V_84 -> V_86 ) ;
if ( V_12 )
goto V_94;
V_7 -> V_31 = 0 ;
F_66 ( & V_7 -> V_44 ) ;
V_7 -> V_43 = false ;
V_7 -> V_35 = false ;
if ( F_24 ( V_7 -> V_46 ) )
V_12 = F_46 ( V_7 ) ;
else
V_12 = F_59 ( V_7 ) ;
if ( V_12 )
goto V_95;
V_7 -> V_96 = F_67 ( V_7 -> V_15 ,
V_7 -> V_9 ,
V_97 ) ;
V_12 = F_68 ( V_5 -> V_98 , V_7 -> V_96 ,
F_29 , 0 ,
L_11 , V_7 ) ;
if ( V_12 ) {
F_10 ( & V_5 -> V_3 ,
L_12 , V_12 ) ;
goto V_99;
}
if ( F_24 ( V_7 -> V_46 ) )
V_7 -> V_100 = F_67 (
V_7 -> V_15 , V_7 -> V_11 , V_101 ) ;
else
V_7 -> V_100 = F_67 (
V_7 -> V_15 , V_7 -> V_9 , V_101 ) ;
V_12 = F_68 ( V_5 -> V_98 , V_7 -> V_100 ,
F_21 , 0 ,
L_13 , V_7 ) ;
if ( V_12 ) {
F_10 ( & V_5 -> V_3 ,
L_14 , V_12 ) ;
goto V_102;
}
F_26 ( & V_7 -> V_47 ,
V_48 + F_27 ( V_49 ) ) ;
return 0 ;
V_102:
F_69 ( V_5 -> V_98 , V_7 -> V_96 , V_7 ) ;
V_99:
F_64 ( V_7 , V_92 ) ;
V_95:
F_53 ( V_7 -> V_16 , & V_7 -> V_38 ) ;
V_94:
F_3 ( V_7 ) ;
return V_12 ;
}
static void F_70 ( struct V_1 * V_7 )
{
struct V_4 * V_5 = V_7 -> V_5 ;
unsigned long V_103 ;
int V_12 ;
F_71 ( & V_7 -> V_42 , V_103 ) ;
V_7 -> V_43 = true ;
F_72 ( & V_7 -> V_42 , V_103 ) ;
V_12 = F_73 (
& V_7 -> V_44 ,
F_27 ( V_49 ) ) ;
if ( V_12 == 0 )
F_74 ( & V_5 -> V_3 , L_15 ) ;
F_69 ( V_5 -> V_98 , V_7 -> V_100 , V_7 ) ;
F_69 ( V_5 -> V_98 , V_7 -> V_96 , V_7 ) ;
F_64 ( V_7 , V_36 ) ;
F_53 ( V_7 -> V_16 , & V_7 -> V_38 ) ;
F_75 ( & V_7 -> V_47 ) ;
F_3 ( V_7 ) ;
}
static struct V_62 *
F_76 ( struct V_1 * V_7 , struct V_104 * V_105 ,
unsigned int V_106 , enum V_107 V_108 )
{
struct V_4 * V_5 = V_7 -> V_5 ;
if ( V_108 == V_109 )
return F_77 ( & V_5 -> V_3 , V_105 , V_106 ) ;
else
return & V_7 -> V_67 [ V_106 ] ;
}
static bool F_78 ( struct V_62 * V_84 ,
struct V_62 * V_63 ,
enum V_56 V_46 )
{
T_3 V_110 = V_84 -> V_73 ;
T_3 V_111 = V_84 -> V_74 ;
if ( F_24 ( V_46 ) )
F_79 ( & V_84 -> V_73 ,
V_63 -> V_74 / 4 , V_112 ,
V_113 ,
& V_84 -> V_74 ,
V_63 -> V_73 / 4 , V_114 ,
V_113 , V_115 ) ;
else
F_79 ( & V_84 -> V_73 ,
V_63 -> V_73 / 4 , V_114 ,
V_113 ,
& V_84 -> V_74 ,
V_63 -> V_74 / 4 , V_112 ,
V_116 , V_115 ) ;
return V_84 -> V_73 != V_110 || V_84 -> V_74 != V_111 ;
}
static int F_80 ( struct V_2 * V_3 ,
struct V_104 * V_105 ,
struct V_117 * V_118 )
{
if ( V_118 -> V_106 >= V_119 )
return - V_120 ;
return F_81 ( & V_118 -> V_118 , V_118 -> V_121 , V_122 ) ;
}
static int F_82 ( struct V_2 * V_3 ,
struct V_104 * V_105 ,
struct V_123 * V_124 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_62 * V_71 ;
int V_12 = 0 ;
if ( V_124 -> V_106 >= V_119 )
return - V_120 ;
F_83 ( & V_7 -> V_125 ) ;
V_71 = F_76 ( V_7 , V_105 , V_124 -> V_106 , V_124 -> V_108 ) ;
if ( ! V_71 ) {
V_12 = - V_120 ;
goto V_18;
}
V_124 -> V_126 = * V_71 ;
V_18:
F_84 ( & V_7 -> V_125 ) ;
return V_12 ;
}
static void F_85 ( struct V_1 * V_7 ,
struct V_104 * V_105 ,
struct V_123 * V_124 ,
const struct V_60 * * V_69 )
{
struct V_62 * V_63 ;
* V_69 = F_86 ( V_124 -> V_126 . V_118 , V_122 ) ;
if ( ! * V_69 ) {
T_3 V_118 ;
F_81 ( & V_118 , 0 , V_122 ) ;
* V_69 = F_86 ( V_118 , V_122 ) ;
V_124 -> V_126 . V_118 = ( * V_69 ) -> V_127 [ 0 ] ;
}
V_63 = F_76 ( V_7 , V_105 , V_68 , V_124 -> V_108 ) ;
if ( V_124 -> V_106 == V_128 ) {
if ( V_124 -> V_126 . V_80 != V_81 )
V_124 -> V_126 . V_80 = V_63 -> V_80 ;
F_78 ( & V_124 -> V_126 , V_63 ,
V_7 -> V_46 ) ;
V_124 -> V_126 . V_129 = V_63 -> V_129 ;
V_124 -> V_126 . V_130 = V_63 -> V_130 ;
V_124 -> V_126 . V_131 = V_63 -> V_131 ;
V_124 -> V_126 . V_132 = V_63 -> V_132 ;
} else {
F_79 ( & V_124 -> V_126 . V_73 ,
V_133 , V_134 , V_135 ,
& V_124 -> V_126 . V_74 ,
V_136 , V_137 , V_138 ,
V_115 ) ;
F_87 ( & V_124 -> V_126 , V_63 ,
true ) ;
}
}
static int F_88 ( struct V_2 * V_3 ,
struct V_104 * V_105 ,
struct V_123 * V_124 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_22 * V_23 = V_7 -> V_23 ;
const struct V_60 * V_69 ;
struct V_83 V_139 ;
struct V_62 * V_71 ;
int V_12 = 0 ;
if ( V_124 -> V_106 >= V_119 )
return - V_120 ;
F_83 ( & V_7 -> V_125 ) ;
if ( V_7 -> V_140 > 0 ) {
V_12 = - V_141 ;
goto V_18;
}
F_85 ( V_7 , V_105 , V_124 , & V_69 ) ;
V_71 = F_76 ( V_7 , V_105 , V_124 -> V_106 , V_124 -> V_108 ) ;
* V_71 = V_124 -> V_126 ;
if ( V_124 -> V_106 == V_68 ) {
const struct V_60 * V_61 ;
struct V_62 * V_84 ;
struct V_123 V_126 ;
V_126 . V_106 = V_128 ;
V_126 . V_108 = V_124 -> V_108 ;
V_126 . V_126 = V_124 -> V_126 ;
F_85 ( V_7 , V_105 , & V_126 , & V_61 ) ;
V_84 = F_76 ( V_7 , V_105 , V_128 ,
V_124 -> V_108 ) ;
* V_84 = V_126 . V_126 ;
if ( V_124 -> V_108 == V_142 )
V_7 -> V_69 [ V_128 ] = V_61 ;
}
if ( V_124 -> V_108 == V_109 )
goto V_18;
V_7 -> V_69 [ V_124 -> V_106 ] = V_69 ;
F_89 ( & V_139 ,
& V_7 -> V_67 [ V_128 ] ,
V_7 -> V_69 [ V_128 ] ) ;
F_84 ( & V_7 -> V_125 ) ;
F_90 ( V_23 , & V_139 ) ;
return 0 ;
V_18:
F_84 ( & V_7 -> V_125 ) ;
return V_12 ;
}
static int F_91 ( struct V_2 * V_3 ,
struct V_104 * V_105 ,
struct V_143 * V_144 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_123 V_126 = { 0 } ;
const struct V_60 * V_69 ;
int V_12 = 0 ;
if ( V_144 -> V_106 >= V_119 || V_144 -> V_121 != 0 )
return - V_120 ;
F_83 ( & V_7 -> V_125 ) ;
V_126 . V_106 = V_144 -> V_106 ;
V_126 . V_108 = V_144 -> V_108 ;
V_126 . V_126 . V_118 = V_144 -> V_118 ;
V_126 . V_126 . V_73 = 1 ;
V_126 . V_126 . V_74 = 1 ;
F_85 ( V_7 , V_105 , & V_126 , & V_69 ) ;
V_144 -> V_145 = V_126 . V_126 . V_73 ;
V_144 -> V_146 = V_126 . V_126 . V_74 ;
if ( V_126 . V_126 . V_118 != V_144 -> V_118 ) {
V_12 = - V_120 ;
goto V_18;
}
V_126 . V_126 . V_118 = V_144 -> V_118 ;
V_126 . V_126 . V_73 = - 1 ;
V_126 . V_126 . V_74 = - 1 ;
F_85 ( V_7 , V_105 , & V_126 , & V_69 ) ;
V_144 -> V_147 = V_126 . V_126 . V_73 ;
V_144 -> V_148 = V_126 . V_126 . V_74 ;
V_18:
F_84 ( & V_7 -> V_125 ) ;
return V_12 ;
}
static int F_92 ( struct V_149 * V_150 ,
const struct V_151 * V_152 ,
const struct V_151 * V_153 , T_3 V_103 )
{
struct V_2 * V_3 = F_93 ( V_150 ) ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_7 = V_5 -> V_6 ;
struct V_2 * V_154 ;
int V_12 = 0 ;
F_94 ( V_5 -> V_98 , L_16 , V_153 -> V_150 -> V_155 ,
V_152 -> V_150 -> V_155 ) ;
F_83 ( & V_7 -> V_125 ) ;
if ( V_152 -> V_103 & V_156 ) {
if ( ! F_95 ( V_153 -> V_150 ) ) {
V_12 = - V_120 ;
goto V_18;
}
V_154 = F_93 ( V_153 -> V_150 ) ;
if ( V_103 & V_157 ) {
if ( V_7 -> V_158 ) {
V_12 = - V_141 ;
goto V_18;
}
V_7 -> V_158 = V_154 ;
} else {
V_7 -> V_158 = NULL ;
}
goto V_18;
}
if ( ! F_96 ( V_153 -> V_150 ) ) {
V_12 = - V_120 ;
goto V_18;
}
if ( V_103 & V_157 ) {
if ( V_7 -> V_159 ) {
V_12 = - V_141 ;
goto V_18;
}
} else {
V_7 -> V_159 = NULL ;
goto V_18;
}
V_7 -> V_159 = V_153 -> V_150 ;
V_18:
F_84 ( & V_7 -> V_125 ) ;
return V_12 ;
}
static int F_97 ( struct V_160 * V_161 )
{
struct V_1 * V_7 = F_98 ( V_161 -> V_162 ,
struct V_1 , V_163 ) ;
struct V_4 * V_5 = V_7 -> V_5 ;
enum V_56 V_46 ;
int V_164 , V_12 = 0 ;
bool V_165 , V_166 ;
F_83 ( & V_7 -> V_125 ) ;
V_164 = V_7 -> V_164 ;
V_165 = V_7 -> V_165 ;
V_166 = V_7 -> V_166 ;
switch ( V_161 -> V_167 ) {
case V_168 :
V_165 = ( V_161 -> V_169 == 1 ) ;
break;
case V_170 :
V_166 = ( V_161 -> V_169 == 1 ) ;
break;
case V_171 :
V_164 = V_161 -> V_169 ;
break;
default:
F_10 ( & V_5 -> V_3 , L_17 ) ;
V_12 = - V_120 ;
goto V_18;
}
V_12 = F_99 ( & V_46 , V_164 , V_165 , V_166 ) ;
if ( V_12 )
goto V_18;
if ( V_46 != V_7 -> V_46 ) {
struct V_62 V_84 , V_63 ;
if ( V_7 -> V_140 > 0 ) {
V_12 = - V_141 ;
goto V_18;
}
V_84 = V_7 -> V_67 [ V_128 ] ;
V_63 = V_7 -> V_67 [ V_68 ] ;
if ( F_78 ( & V_84 , & V_63 , V_46 ) ) {
V_12 = - V_120 ;
goto V_18;
}
V_7 -> V_46 = V_46 ;
V_7 -> V_164 = V_164 ;
V_7 -> V_165 = V_165 ;
V_7 -> V_166 = V_166 ;
}
V_18:
F_84 ( & V_7 -> V_125 ) ;
return V_12 ;
}
static int F_100 ( struct V_1 * V_7 )
{
struct V_4 * V_5 = V_7 -> V_5 ;
struct V_172 * V_173 = & V_7 -> V_163 ;
int V_12 ;
F_101 ( V_173 , 3 ) ;
F_102 ( V_173 , & V_174 , V_168 ,
0 , 1 , 1 , 0 ) ;
F_102 ( V_173 , & V_174 , V_170 ,
0 , 1 , 1 , 0 ) ;
F_102 ( V_173 , & V_174 , V_171 ,
0 , 270 , 90 , 0 ) ;
V_5 -> V_3 . V_175 = V_173 ;
if ( V_173 -> error ) {
V_12 = V_173 -> error ;
goto V_176;
}
F_103 ( V_173 ) ;
return 0 ;
V_176:
F_104 ( V_173 ) ;
return V_12 ;
}
static int F_105 ( struct V_2 * V_3 , int V_177 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_7 = V_5 -> V_6 ;
int V_12 = 0 ;
F_83 ( & V_7 -> V_125 ) ;
if ( ! V_7 -> V_158 || ! V_7 -> V_159 ) {
V_12 = - V_178 ;
goto V_18;
}
if ( V_7 -> V_140 != ! V_177 )
goto V_179;
F_94 ( V_5 -> V_98 , L_18 , V_177 ? L_19 : L_20 ) ;
if ( V_177 )
V_12 = F_65 ( V_7 ) ;
else
F_70 ( V_7 ) ;
if ( V_12 )
goto V_18;
V_12 = F_106 ( V_7 -> V_158 , V_180 , V_181 , V_177 ) ;
V_12 = ( V_12 && V_12 != - V_182 ) ? V_12 : 0 ;
if ( V_12 ) {
if ( V_177 )
F_70 ( V_7 ) ;
goto V_18;
}
V_179:
V_7 -> V_140 += V_177 ? 1 : - 1 ;
if ( V_7 -> V_140 < 0 )
V_7 -> V_140 = 0 ;
V_18:
F_84 ( & V_7 -> V_125 ) ;
return V_12 ;
}
static int F_107 ( struct V_2 * V_3 ,
struct V_183 * V_184 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
if ( V_184 -> V_106 >= V_119 )
return - V_120 ;
F_83 ( & V_7 -> V_125 ) ;
V_184 -> V_185 = V_7 -> V_186 ;
F_84 ( & V_7 -> V_125 ) ;
return 0 ;
}
static int F_108 ( struct V_2 * V_3 ,
struct V_183 * V_184 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
if ( V_184 -> V_106 >= V_119 )
return - V_120 ;
F_83 ( & V_7 -> V_125 ) ;
V_7 -> V_186 = V_184 -> V_185 ;
F_84 ( & V_7 -> V_125 ) ;
return 0 ;
}
static int F_109 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_53 , V_12 ;
T_3 V_118 ;
V_7 -> V_16 = F_110 ( V_3 -> V_187 -> V_98 ) ;
for ( V_53 = 0 ; V_53 < V_119 ; V_53 ++ ) {
V_7 -> V_106 [ V_53 ] . V_103 = ( V_53 == V_68 ) ?
V_156 : V_188 ;
F_81 ( & V_118 , 0 , V_189 ) ;
V_12 = F_111 ( & V_7 -> V_67 [ V_53 ] ,
640 , 480 , V_118 , V_81 ,
& V_7 -> V_69 [ V_53 ] ) ;
if ( V_12 )
return V_12 ;
}
V_7 -> V_186 . V_190 = 1 ;
V_7 -> V_186 . V_191 = 30 ;
V_12 = F_112 ( & V_3 -> V_150 , V_119 ,
V_7 -> V_106 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_113 ( V_7 -> V_23 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_114 ( V_7 -> V_16 , V_7 -> V_23 ) ;
if ( V_12 )
goto V_192;
V_12 = F_100 ( V_7 ) ;
if ( V_12 )
goto V_192;
return 0 ;
V_192:
F_115 ( V_7 -> V_23 ) ;
return V_12 ;
}
static void F_116 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_115 ( V_7 -> V_23 ) ;
F_104 ( & V_7 -> V_163 ) ;
}
static int F_117 ( struct V_4 * V_5 )
{
struct V_1 * V_7 ;
V_7 = F_118 ( V_5 -> V_98 , sizeof( * V_7 ) , V_193 ) ;
if ( ! V_7 )
return - V_194 ;
V_5 -> V_6 = V_7 ;
V_7 -> V_5 = V_5 ;
F_119 ( & V_7 -> V_42 ) ;
F_120 ( & V_7 -> V_47 ) ;
V_7 -> V_47 . V_51 = ( unsigned long ) V_7 ;
V_7 -> V_47 . V_195 = F_30 ;
V_7 -> V_23 = F_121 ( & V_5 -> V_3 ,
V_128 ) ;
if ( F_9 ( V_7 -> V_23 ) )
return F_11 ( V_7 -> V_23 ) ;
F_122 ( & V_7 -> V_125 ) ;
return 0 ;
}
static void F_123 ( struct V_4 * V_5 )
{
struct V_1 * V_7 = V_5 -> V_6 ;
F_124 ( & V_7 -> V_125 ) ;
F_125 ( V_7 -> V_23 ) ;
}
