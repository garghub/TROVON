static unsigned int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
F_3 ( V_4 -> V_6 , V_7 , & V_5 ) ;
return F_4 ( V_8 , V_5 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 , V_9 = 10000 ;
do {
F_6 ( 1 ) ;
F_3 ( V_4 -> V_6 , V_7 , & V_5 ) ;
} while ( F_4 ( V_10 , V_5 ) && V_9 -- );
if ( V_9 < 0 )
return - V_11 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
const struct V_12 * V_13 ,
int * V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_15 , V_5 , V_16 , V_17 , V_18 = 0 , V_19 = 0 ;
V_15 = F_5 ( V_2 ) ;
if ( V_15 )
return V_15 ;
while ( F_1 ( V_2 ) > 0 &&
V_19 < V_20 ) {
F_3 ( V_4 -> V_6 , V_21 , & V_5 ) ;
V_16 = F_4 ( V_22 ,
V_5 ) ;
if ( V_16 != V_13 -> V_23 )
continue;
V_17 = F_4 ( V_24 ,
V_5 ) ;
V_17 &= ( F_8 ( V_4 -> V_25 -> V_26 ) - 1 ) ;
V_18 += V_17 ;
V_19 ++ ;
}
if ( ! V_19 )
return - V_27 ;
* V_14 = V_18 / V_19 ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 ,
const struct V_12 * V_13 ,
enum V_28 V_29 ,
enum V_30 V_31 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_14 , V_23 = V_13 -> V_23 ;
V_14 = V_31 << F_10 ( V_23 ) ;
F_11 ( V_4 -> V_6 , V_32 ,
F_12 ( V_23 ) ,
V_14 ) ;
V_14 = V_29 << F_13 ( V_23 ) ;
F_11 ( V_4 -> V_6 , V_32 ,
F_14 ( V_23 ) , V_14 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
const struct V_12 * V_13 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
V_5 = F_16 ( V_33 , 0 ) ;
F_11 ( V_4 -> V_6 , V_34 ,
V_33 , V_5 ) ;
V_5 = F_16 ( F_17 ( 0 ) ,
V_13 -> V_23 ) ;
F_11 ( V_4 -> V_6 , V_34 ,
F_17 ( 0 ) , V_5 ) ;
V_5 = F_16 ( V_35 ,
V_13 -> V_23 ) ;
F_11 ( V_4 -> V_6 , V_36 ,
V_35 ,
V_5 ) ;
V_5 = F_16 ( V_37 ,
V_13 -> V_23 ) ;
F_11 ( V_4 -> V_6 , V_36 ,
V_37 ,
V_5 ) ;
if ( V_13 -> V_23 == 6 )
F_11 ( V_4 -> V_6 , V_38 ,
V_39 , 0 ) ;
}
static void F_18 ( struct V_1 * V_2 ,
enum V_40 V_41 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
V_5 = F_16 ( V_42 , V_41 ) ;
F_11 ( V_4 -> V_6 , V_43 ,
V_42 , V_5 ) ;
F_19 ( 10 , 20 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_11 ( V_4 -> V_6 , V_7 ,
V_44 ,
V_44 ) ;
F_11 ( V_4 -> V_6 , V_7 ,
V_45 ,
V_45 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_11 ( V_4 -> V_6 , V_7 ,
V_46 ,
V_46 ) ;
F_5 ( V_2 ) ;
F_11 ( V_4 -> V_6 , V_7 ,
V_44 , 0 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_14 , V_9 = 10000 ;
F_23 ( & V_2 -> V_47 ) ;
F_11 ( V_4 -> V_6 , V_48 ,
V_49 ,
V_49 ) ;
do {
F_6 ( 1 ) ;
F_3 ( V_4 -> V_6 , V_48 , & V_14 ) ;
} while ( V_14 & V_50 && V_9 -- );
if ( V_9 < 0 )
return - V_11 ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_11 ( V_4 -> V_6 , V_48 ,
V_49 , 0 ) ;
F_25 ( & V_2 -> V_47 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ ) {
if ( ! F_1 ( V_2 ) )
break;
F_3 ( V_4 -> V_6 , V_21 , 0 ) ;
}
}
static int F_27 ( struct V_1 * V_2 ,
const struct V_12 * V_13 ,
enum V_28 V_51 ,
enum V_30 V_52 ,
int * V_14 )
{
int V_15 ;
V_15 = F_22 ( V_2 ) ;
if ( V_15 )
return V_15 ;
F_26 ( V_2 ) ;
F_9 ( V_2 , V_13 , V_51 , V_52 ) ;
F_15 ( V_2 , V_13 ) ;
F_20 ( V_2 ) ;
V_15 = F_7 ( V_2 , V_13 , V_14 ) ;
F_21 ( V_2 ) ;
F_24 ( V_2 ) ;
if ( V_15 ) {
F_28 ( V_2 -> V_53 . V_54 ,
L_1 ,
V_13 -> V_23 , V_15 ) ;
return V_15 ;
}
return V_55 ;
}
static int F_29 ( struct V_1 * V_2 ,
const struct V_12 * V_13 ,
int * V_14 , int * V_56 , long V_57 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_15 ;
switch ( V_57 ) {
case V_58 :
return F_27 ( V_2 , V_13 , V_59 ,
V_60 , V_14 ) ;
break;
case V_61 :
return F_27 ( V_2 , V_13 ,
V_62 , V_63 ,
V_14 ) ;
break;
case V_64 :
V_15 = F_30 ( V_4 -> V_65 ) ;
if ( V_15 < 0 ) {
F_31 ( V_2 -> V_53 . V_54 ,
L_2 , V_15 ) ;
return V_15 ;
}
* V_14 = V_15 / 1000 ;
* V_56 = V_4 -> V_25 -> V_26 ;
return V_66 ;
default:
return - V_67 ;
}
}
static int F_32 ( struct V_1 * V_2 ,
void T_2 * V_68 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_69 V_70 ;
const char * V_71 [ 1 ] ;
V_70 . V_72 = F_33 ( & V_2 -> V_53 , V_73 , L_3 ,
F_34 ( V_2 -> V_53 . V_74 ) ) ;
V_70 . V_75 = 0 ;
V_70 . V_76 = & V_77 ;
V_71 [ 0 ] = F_35 ( V_4 -> V_78 ) ;
V_70 . V_79 = V_71 ;
V_70 . V_80 = 1 ;
V_4 -> V_81 . V_82 = V_68 + V_43 ;
V_4 -> V_81 . V_83 = V_84 ;
V_4 -> V_81 . V_85 = V_86 ;
V_4 -> V_81 . V_87 . V_70 = & V_70 ;
V_4 -> V_81 . V_75 = 0 ;
V_4 -> V_88 = F_36 ( & V_2 -> V_53 ,
& V_4 -> V_81 . V_87 ) ;
if ( F_37 ( F_38 ( V_4 -> V_88 ) ) )
return F_39 ( V_4 -> V_88 ) ;
V_70 . V_72 = F_33 ( & V_2 -> V_53 , V_73 , L_4 ,
F_34 ( V_2 -> V_53 . V_74 ) ) ;
V_70 . V_75 = V_89 ;
V_70 . V_76 = & V_90 ;
V_71 [ 0 ] = F_35 ( V_4 -> V_88 ) ;
V_70 . V_79 = V_71 ;
V_70 . V_80 = 1 ;
V_4 -> V_91 . V_82 = V_68 + V_43 ;
V_4 -> V_91 . V_92 = F_40 ( V_93 ) ;
V_4 -> V_91 . V_87 . V_70 = & V_70 ;
V_4 -> V_94 = F_36 ( & V_2 -> V_53 , & V_4 -> V_91 . V_87 ) ;
if ( F_37 ( F_38 ( V_4 -> V_94 ) ) )
return F_39 ( V_4 -> V_94 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 , V_15 ;
F_18 ( V_2 , V_95 ) ;
F_3 ( V_4 -> V_6 , V_43 , & V_5 ) ;
if ( V_5 & V_96 )
return 0 ;
F_21 ( V_2 ) ;
F_11 ( V_4 -> V_6 , V_7 ,
V_97 ,
V_97 ) ;
F_42 ( V_4 -> V_6 , V_34 , 0x0 ) ;
F_11 ( V_4 -> V_6 , V_43 ,
V_98 , 0 ) ;
F_11 ( V_4 -> V_6 , V_43 ,
V_99 ,
V_99 ) ;
F_11 ( V_4 -> V_6 , V_48 ,
V_100 ,
F_16 ( V_101 ,
10 ) ) ;
F_11 ( V_4 -> V_6 , V_48 ,
V_102 ,
F_16 ( V_102 ,
0 ) ) ;
F_11 ( V_4 -> V_6 , V_48 ,
V_100 ,
F_16 ( V_100 ,
10 ) ) ;
F_11 ( V_4 -> V_6 , V_48 ,
V_103 ,
F_16 ( V_103 ,
1 ) ) ;
V_15 = F_43 ( V_4 -> V_104 , V_4 -> V_78 ) ;
if ( V_15 ) {
F_31 ( V_2 -> V_53 . V_54 ,
L_5 ) ;
return V_15 ;
}
V_15 = F_44 ( V_4 -> V_94 , 1200000 ) ;
if ( V_15 ) {
F_31 ( V_2 -> V_53 . V_54 ,
L_6 ) ;
return V_15 ;
}
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_15 ;
V_15 = F_22 ( V_2 ) ;
if ( V_15 )
goto V_105;
V_15 = F_46 ( V_4 -> V_65 ) ;
if ( V_15 < 0 ) {
F_31 ( V_2 -> V_53 . V_54 ,
L_7 ) ;
goto V_106;
}
V_15 = F_47 ( V_4 -> V_107 ) ;
if ( V_15 ) {
F_31 ( V_2 -> V_53 . V_54 , L_8 ) ;
goto V_108;
}
V_15 = F_47 ( V_4 -> V_109 ) ;
if ( V_15 ) {
F_31 ( V_2 -> V_53 . V_54 , L_9 ) ;
goto V_110;
}
F_11 ( V_4 -> V_6 , V_111 ,
V_112 ,
V_112 ) ;
F_11 ( V_4 -> V_6 , V_43 ,
V_113 ,
V_113 ) ;
F_6 ( 5 ) ;
V_15 = F_47 ( V_4 -> V_94 ) ;
if ( V_15 ) {
F_31 ( V_2 -> V_53 . V_54 , L_10 ) ;
goto V_114;
}
F_24 ( V_2 ) ;
return 0 ;
V_114:
F_11 ( V_4 -> V_6 , V_43 ,
V_113 , 0 ) ;
F_11 ( V_4 -> V_6 , V_111 ,
V_112 , 0 ) ;
F_48 ( V_4 -> V_109 ) ;
V_110:
F_48 ( V_4 -> V_107 ) ;
V_108:
F_49 ( V_4 -> V_65 ) ;
V_106:
F_24 ( V_2 ) ;
V_105:
return V_15 ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_15 ;
V_15 = F_22 ( V_2 ) ;
if ( V_15 )
return V_15 ;
F_48 ( V_4 -> V_94 ) ;
F_11 ( V_4 -> V_6 , V_43 ,
V_113 , 0 ) ;
F_11 ( V_4 -> V_6 , V_111 ,
V_112 , 0 ) ;
F_48 ( V_4 -> V_109 ) ;
F_48 ( V_4 -> V_107 ) ;
F_49 ( V_4 -> V_65 ) ;
F_24 ( V_2 ) ;
return 0 ;
}
static int F_51 ( struct V_115 * V_116 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_117 * V_118 ;
void T_2 * V_68 ;
const struct V_119 * V_120 ;
int V_15 ;
V_2 = F_52 ( & V_116 -> V_53 , sizeof( * V_4 ) ) ;
if ( ! V_2 ) {
F_31 ( & V_116 -> V_53 , L_11 ) ;
return - V_121 ;
}
V_4 = F_2 ( V_2 ) ;
V_120 = F_53 ( V_122 , & V_116 -> V_53 ) ;
V_4 -> V_25 = V_120 -> V_25 ;
V_2 -> V_72 = V_4 -> V_25 -> V_72 ;
V_2 -> V_53 . V_54 = & V_116 -> V_53 ;
V_2 -> V_53 . V_74 = V_116 -> V_53 . V_74 ;
V_2 -> V_123 = V_124 ;
V_2 -> V_125 = & V_126 ;
V_2 -> V_127 = V_128 ;
V_2 -> V_129 = F_54 ( V_128 ) ;
V_118 = F_55 ( V_116 , V_130 , 0 ) ;
V_68 = F_56 ( & V_116 -> V_53 , V_118 ) ;
if ( F_38 ( V_68 ) )
return F_39 ( V_68 ) ;
V_4 -> V_6 = F_57 ( & V_116 -> V_53 , V_68 ,
& V_131 ) ;
if ( F_38 ( V_4 -> V_6 ) )
return F_39 ( V_4 -> V_6 ) ;
V_4 -> V_78 = F_58 ( & V_116 -> V_53 , L_12 ) ;
if ( F_38 ( V_4 -> V_78 ) ) {
F_31 ( & V_116 -> V_53 , L_13 ) ;
return F_39 ( V_4 -> V_78 ) ;
}
V_4 -> V_107 = F_58 ( & V_116 -> V_53 , L_14 ) ;
if ( F_38 ( V_4 -> V_107 ) ) {
F_31 ( & V_116 -> V_53 , L_15 ) ;
return F_39 ( V_4 -> V_107 ) ;
}
V_4 -> V_109 = F_58 ( & V_116 -> V_53 , L_16 ) ;
if ( F_38 ( V_4 -> V_109 ) ) {
if ( F_39 ( V_4 -> V_109 ) == - V_27 ) {
V_4 -> V_109 = NULL ;
} else {
F_31 ( & V_116 -> V_53 , L_17 ) ;
return F_39 ( V_4 -> V_109 ) ;
}
}
V_4 -> V_94 = F_58 ( & V_116 -> V_53 , L_18 ) ;
if ( F_38 ( V_4 -> V_94 ) ) {
if ( F_39 ( V_4 -> V_94 ) == - V_27 ) {
V_4 -> V_94 = NULL ;
} else {
F_31 ( & V_116 -> V_53 , L_19 ) ;
return F_39 ( V_4 -> V_94 ) ;
}
}
V_4 -> V_104 = F_58 ( & V_116 -> V_53 , L_20 ) ;
if ( F_38 ( V_4 -> V_104 ) ) {
if ( F_39 ( V_4 -> V_104 ) == - V_27 ) {
V_4 -> V_104 = NULL ;
} else {
F_31 ( & V_116 -> V_53 , L_21 ) ;
return F_39 ( V_4 -> V_104 ) ;
}
}
if ( ! V_4 -> V_94 ) {
V_15 = F_32 ( V_2 , V_68 ) ;
if ( V_15 )
return V_15 ;
}
V_4 -> V_65 = F_59 ( & V_116 -> V_53 , L_22 ) ;
if ( F_38 ( V_4 -> V_65 ) ) {
F_31 ( & V_116 -> V_53 , L_23 ) ;
return F_39 ( V_4 -> V_65 ) ;
}
V_15 = F_41 ( V_2 ) ;
if ( V_15 )
goto V_132;
V_15 = F_45 ( V_2 ) ;
if ( V_15 )
goto V_132;
F_60 ( V_116 , V_2 ) ;
V_15 = F_61 ( V_2 ) ;
if ( V_15 )
goto V_133;
return 0 ;
V_133:
F_50 ( V_2 ) ;
V_132:
return V_15 ;
}
static int F_62 ( struct V_115 * V_116 )
{
struct V_1 * V_2 = F_63 ( V_116 ) ;
F_64 ( V_2 ) ;
return F_50 ( V_2 ) ;
}
static int T_3 F_65 ( struct V_134 * V_53 )
{
struct V_1 * V_2 = F_66 ( V_53 ) ;
return F_50 ( V_2 ) ;
}
static int T_3 F_67 ( struct V_134 * V_53 )
{
struct V_1 * V_2 = F_66 ( V_53 ) ;
return F_45 ( V_2 ) ;
}
