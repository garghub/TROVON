static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 -> V_5 -> V_6 ;
}
static struct V_1 * F_2 ( struct V_7 * V_4 )
{
return V_4 -> V_5 -> V_6 ;
}
static bool F_3 ( struct V_2 * V_3 )
{
return ! ! ( V_3 -> V_8 & ( V_9 | V_10
| V_11 ) ) ;
}
static struct V_2 * F_4 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_5 ( V_13 ) ;
return F_6 ( V_15 , struct V_2 , V_16 ) ;
}
static struct V_12 * F_7 ( struct V_2 * V_3 )
{
return & V_3 -> V_16 . V_17 ;
}
static struct V_2 * F_8 ( struct V_7 * V_4 ,
T_1 V_8 )
{
struct V_2 * V_3 = NULL ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_4 -> V_19 ; V_18 ++ ) {
V_3 = & V_4 -> V_20 [ V_18 ] ;
if ( V_3 && V_3 -> V_8 == V_8 )
break;
}
return V_3 ;
}
static int F_9 ( struct V_2 * V_3 ,
T_1 V_21 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_22 * V_23 = V_6 -> V_23 ;
struct V_24 V_25 ;
int V_26 ;
if ( V_3 -> V_27 )
return - V_28 ;
V_26 = F_10 ( V_23 ) ;
if ( V_26 < 0 )
return V_26 ;
V_25 . V_29 = V_3 -> V_4 -> V_30 ;
V_25 . V_31 = V_3 -> V_30 ;
V_25 . V_32 = F_11 ( V_21 ) ;
V_26 = F_12 ( V_6 , V_33 ,
& V_25 , sizeof( V_25 ) , NULL , 0 ) ;
F_13 ( V_23 ) ;
return V_26 ;
}
static int F_14 ( struct V_2 * V_3 )
{
T_1 V_21 ;
if ( V_3 -> V_8 & V_9 )
V_3 = F_8 ( V_3 -> V_4 ,
V_10 ) ;
V_21 = V_3 -> V_32 . V_34 +
( V_3 -> V_32 . V_35 * V_3 -> V_36 -> V_37 ) ;
return F_9 ( V_3 , V_21 ) ;
}
static struct V_2 * F_4 ( struct V_12 * V_13 )
{
return F_6 ( V_13 , struct V_2 , V_38 ) ;
}
static struct V_12 * F_7 ( struct V_2 * V_3 )
{
return & V_3 -> V_38 ;
}
static int F_14 ( struct V_2 * V_3 )
{
return 0 ;
}
static void F_15 ( struct V_12 * V_13 )
{
F_16 ( & V_13 -> V_39 ) ;
}
static void F_17 ( struct V_12 * V_13 )
{
F_18 ( & V_13 -> V_39 ) ;
}
static T_2 F_19 ( struct V_40 * V_41 , struct V_42 * V_43 ,
char * V_44 )
{
struct V_12 * V_13 = F_20 ( V_41 ) ;
struct V_2 * V_3 = F_4 ( V_13 ) ;
return sprintf ( V_44 , L_1 , V_3 -> V_45 ) ;
}
static T_2 F_21 ( struct V_40 * V_41 , struct V_42 * V_43 ,
const char * V_44 , T_3 V_46 )
{
struct V_12 * V_13 = F_20 ( V_41 ) ;
struct V_2 * V_3 = F_4 ( V_13 ) ;
T_1 V_45 ;
int V_26 ;
F_15 ( V_13 ) ;
if ( F_22 ( V_13 ) ) {
V_26 = - V_47 ;
goto V_48;
}
V_26 = F_23 ( V_44 , 0 , & V_45 ) ;
if ( V_26 < 0 ) {
F_24 ( V_41 , L_2 , V_26 ) ;
goto V_48;
}
V_26 = F_25 ( V_3 , V_45 ) ;
if ( V_26 < 0 )
goto V_48;
V_3 -> V_45 = V_45 ;
V_26 = V_46 ;
V_48:
F_17 ( V_13 ) ;
return V_26 ;
}
static int F_26 ( struct V_2 * V_3 ,
struct V_12 * V_13 )
{
int V_43 = 0 ;
int V_46 = 0 ;
if ( V_3 -> V_49 & V_50 )
V_46 ++ ;
if ( V_3 -> V_49 & V_51 )
V_46 += 2 ;
if ( ! V_46 )
return 0 ;
V_3 -> V_52 = F_27 ( V_46 + 1 , sizeof( * V_3 -> V_52 ) , V_53 ) ;
if ( ! V_3 -> V_52 )
return - V_54 ;
V_3 -> V_55 = F_27 ( 1 , sizeof( * V_3 -> V_55 ) ,
V_53 ) ;
if ( ! V_3 -> V_55 )
return - V_54 ;
V_3 -> V_56 = F_27 ( 2 , sizeof( * V_3 -> V_56 ) ,
V_53 ) ;
if ( ! V_3 -> V_56 )
return - V_54 ;
if ( V_3 -> V_49 & V_50 )
V_3 -> V_52 [ V_43 ++ ] = & V_57 . V_43 ;
if ( V_3 -> V_49 & V_51 ) {
V_3 -> V_52 [ V_43 ++ ] = & V_58 . V_43 ;
V_3 -> V_52 [ V_43 ++ ] = & V_59 . V_43 ;
}
V_3 -> V_55 -> V_52 = V_3 -> V_52 ;
V_3 -> V_56 [ 0 ] = V_3 -> V_55 ;
V_13 -> V_60 = V_3 -> V_56 ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_22 * V_23 = V_6 -> V_23 ;
struct V_61 V_25 ;
int V_26 ;
if ( V_3 -> V_27 )
return - V_28 ;
V_26 = F_10 ( V_23 ) ;
if ( V_26 < 0 )
return V_26 ;
V_25 . V_29 = V_3 -> V_4 -> V_30 ;
V_25 . V_31 = V_3 -> V_30 ;
V_25 . V_62 = V_3 -> V_62 ;
V_25 . V_63 = V_3 -> V_63 ;
V_26 = F_12 ( V_6 , V_64 ,
& V_25 , sizeof( V_25 ) , NULL , 0 ) ;
F_13 ( V_23 ) ;
return V_26 ;
}
static int F_25 ( struct V_2 * V_3 , T_1 V_45 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_22 * V_23 = V_6 -> V_23 ;
struct V_65 V_25 ;
int V_26 ;
if ( V_3 -> V_27 )
return - V_28 ;
V_26 = F_10 ( V_23 ) ;
if ( V_26 < 0 )
return V_26 ;
V_25 . V_29 = V_3 -> V_4 -> V_30 ;
V_25 . V_31 = V_3 -> V_30 ;
V_25 . V_45 = F_11 ( V_45 ) ;
V_26 = F_12 ( V_6 , V_66 ,
& V_25 , sizeof( V_25 ) , NULL , 0 ) ;
F_13 ( V_23 ) ;
return V_26 ;
}
static int F_29 ( struct V_2 * V_3 )
{
struct V_67 V_25 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_22 * V_23 = V_6 -> V_23 ;
bool V_68 ;
int V_26 ;
F_16 ( & V_3 -> V_69 ) ;
V_26 = F_10 ( V_23 ) ;
if ( V_26 < 0 )
goto V_70;
V_68 = V_3 -> V_71 ;
V_25 . V_29 = V_3 -> V_4 -> V_30 ;
V_25 . V_31 = V_3 -> V_30 ;
V_25 . V_37 = ( V_72 ) V_3 -> V_36 -> V_37 ;
V_26 = F_12 ( V_6 , V_73 ,
& V_25 , sizeof( V_25 ) , NULL , 0 ) ;
if ( V_26 < 0 )
goto V_74;
if ( V_3 -> V_36 -> V_37 )
V_3 -> V_71 = true ;
else
V_3 -> V_71 = false ;
if ( ! V_68 && V_3 -> V_71 )
goto V_70;
if ( V_68 && ! V_3 -> V_71 )
F_13 ( V_23 ) ;
V_74:
F_13 ( V_23 ) ;
V_70:
F_18 ( & V_3 -> V_69 ) ;
return V_26 ;
}
static int F_30 ( struct V_2 * V_3 )
{
int V_26 ;
if ( V_3 -> V_27 )
return 0 ;
if ( F_3 ( V_3 ) )
V_26 = F_14 ( V_3 ) ;
else
V_26 = F_29 ( V_3 ) ;
return V_26 ;
}
static int F_31 ( struct V_12 * V_13 ,
enum V_75 V_76 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
V_3 -> V_36 -> V_37 = V_76 ;
return F_30 ( V_3 ) ;
}
static enum V_75 F_32 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
return V_3 -> V_36 -> V_37 ;
}
static int F_33 ( struct V_12 * V_13 , unsigned long * V_77 ,
unsigned long * V_78 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_22 * V_23 = V_6 -> V_23 ;
struct V_79 V_25 ;
bool V_68 ;
int V_26 ;
if ( V_3 -> V_27 )
return - V_28 ;
if ( ! V_77 || ! V_78 )
return - V_80 ;
F_16 ( & V_3 -> V_69 ) ;
V_26 = F_10 ( V_23 ) ;
if ( V_26 < 0 )
goto V_70;
V_68 = V_3 -> V_71 ;
V_25 . V_29 = V_3 -> V_4 -> V_30 ;
V_25 . V_31 = V_3 -> V_30 ;
V_25 . V_81 = F_34 ( * V_77 ) ;
V_25 . V_82 = F_34 ( * V_78 ) ;
V_26 = F_12 ( V_6 , V_83 , & V_25 ,
sizeof( V_25 ) , NULL , 0 ) ;
if ( V_26 < 0 )
goto V_74;
if ( * V_77 )
V_3 -> V_71 = true ;
else
V_3 -> V_71 = false ;
if ( ! V_68 && V_3 -> V_71 )
goto V_70;
if ( V_68 && ! V_3 -> V_71 )
F_13 ( V_23 ) ;
V_74:
F_13 ( V_23 ) ;
V_70:
F_18 ( & V_3 -> V_69 ) ;
return V_26 ;
}
static void F_35 ( struct V_2 * V_3 ,
struct V_12 * V_13 )
{
V_13 -> V_84 = F_32 ;
V_13 -> V_85 = F_31 ;
if ( V_3 -> V_49 & V_86 )
V_13 -> V_87 = F_33 ;
}
static void F_36 ( struct V_88 * V_89 ,
struct V_88 * V_90 )
{
V_90 -> V_34 = V_89 -> V_34 ;
V_90 -> V_91 = V_89 -> V_91 ;
V_90 -> V_35 = V_89 -> V_35 ;
V_90 -> V_92 = V_89 -> V_91 ;
}
static int F_37 ( struct V_7 * V_4 )
{
struct V_1 * V_6 = F_2 ( V_4 ) ;
struct V_40 * V_41 = & V_6 -> V_23 -> V_41 ;
struct V_93 * V_94 ;
struct V_14 * V_16 ;
struct V_14 * V_95 = NULL ;
struct V_2 * V_96 , * V_97 , * V_98 ;
int V_26 = 0 ;
V_94 = F_27 ( 1 , sizeof( * V_94 ) , V_53 ) ;
if ( ! V_94 )
return - V_54 ;
V_96 = F_8 ( V_4 , V_10 ) ;
if ( V_96 )
F_36 ( & V_96 -> V_32 ,
& V_94 -> V_99 ) ;
V_97 = F_8 ( V_4 , V_11 ) ;
if ( V_97 ) {
F_36 ( & V_97 -> V_32 ,
& V_94 -> V_100 ) ;
V_95 = & V_97 -> V_16 ;
}
V_98 = F_8 ( V_4 , V_9 ) ;
F_38 ( ! V_98 ) ;
V_16 = & V_98 -> V_16 ;
snprintf ( V_94 -> V_101 , sizeof( V_94 -> V_101 ) , L_3 , V_4 -> V_102 ) ;
V_94 -> V_103 = V_104 | V_105 |
V_106 | V_107 |
V_108 | V_109 |
V_110 | V_111 |
V_112 ;
V_4 -> V_113 = F_39 ( V_41 , NULL , V_16 , V_95 ,
& V_114 , V_94 ) ;
if ( F_40 ( V_4 -> V_113 ) ) {
V_26 = F_41 ( V_4 -> V_113 ) ;
goto V_115;
}
return V_26 ;
V_115:
F_42 ( V_94 ) ;
return V_26 ;
}
static void F_43 ( struct V_7 * V_4 )
{
F_44 ( V_4 -> V_113 ) ;
}
static int F_37 ( struct V_7 * V_4 )
{
struct V_1 * V_6 = F_2 ( V_4 ) ;
F_24 ( & V_6 -> V_23 -> V_41 , L_4 ) ;
return 0 ;
}
static void F_43 ( struct V_7 * V_4 )
{
}
static int F_45 ( struct V_14 * V_116 ,
T_1 V_37 )
{
struct V_2 * V_3 = F_6 ( V_116 , struct V_2 ,
V_16 ) ;
int V_26 ;
V_26 = F_9 ( V_3 , V_37 ) ;
if ( V_26 < 0 )
return V_26 ;
V_116 -> V_37 . V_92 = V_37 ;
return 0 ;
}
static int F_46 ( struct V_14 * V_116 ,
T_1 * V_37 )
{
* V_37 = V_116 -> V_37 . V_92 ;
return 0 ;
}
static int F_47 ( struct V_14 * V_116 ,
bool V_117 )
{
struct V_2 * V_3 = F_6 ( V_116 , struct V_2 ,
V_16 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_22 * V_23 = V_6 -> V_23 ;
struct V_118 V_25 ;
int V_26 ;
if ( V_3 -> V_27 )
return - V_28 ;
V_26 = F_10 ( V_23 ) ;
if ( V_26 < 0 )
return V_26 ;
V_25 . V_29 = V_3 -> V_4 -> V_30 ;
V_25 . V_31 = V_3 -> V_30 ;
V_25 . V_117 = V_117 ? 1 : 0 ;
V_26 = F_12 ( V_6 , V_119 ,
& V_25 , sizeof( V_25 ) , NULL , 0 ) ;
if ( ! V_26 )
V_3 -> V_120 = V_117 ;
F_13 ( V_23 ) ;
return V_26 ;
}
static int F_48 ( struct V_14 * V_116 ,
bool * V_117 )
{
struct V_2 * V_3 = F_6 ( V_116 , struct V_2 ,
V_16 ) ;
* V_117 = V_3 -> V_120 ;
return 0 ;
}
static int F_49 ( struct V_14 * V_116 ,
T_1 V_121 )
{
struct V_2 * V_3 = F_6 ( V_116 , struct V_2 ,
V_16 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_22 * V_23 = V_6 -> V_23 ;
struct V_122 V_25 ;
int V_26 ;
if ( V_3 -> V_27 )
return - V_28 ;
V_26 = F_10 ( V_23 ) ;
if ( V_26 < 0 )
return V_26 ;
V_25 . V_29 = V_3 -> V_4 -> V_30 ;
V_25 . V_31 = V_3 -> V_30 ;
V_25 . V_123 = F_11 ( V_121 ) ;
V_26 = F_12 ( V_6 , V_124 ,
& V_25 , sizeof( V_25 ) , NULL , 0 ) ;
if ( ! V_26 )
V_116 -> V_121 . V_92 = V_121 ;
F_13 ( V_23 ) ;
return V_26 ;
}
static int F_50 ( struct V_14 * V_116 ,
T_1 * V_125 )
{
struct V_2 * V_3 = F_6 ( V_116 , struct V_2 ,
V_16 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_22 * V_23 = V_6 -> V_23 ;
struct V_126 V_25 ;
struct V_127 V_128 ;
int V_26 ;
if ( V_3 -> V_27 )
return - V_28 ;
V_26 = F_10 ( V_23 ) ;
if ( V_26 < 0 )
return V_26 ;
V_25 . V_29 = V_3 -> V_4 -> V_30 ;
V_25 . V_31 = V_3 -> V_30 ;
V_26 = F_12 ( V_6 , V_129 ,
& V_25 , sizeof( V_25 ) , & V_128 , sizeof( V_128 ) ) ;
if ( ! V_26 )
* V_125 = F_51 ( V_128 . V_125 ) ;
F_13 ( V_23 ) ;
return V_26 ;
}
static int F_52 ( struct V_2 * V_3 ,
struct V_2 * V_96 )
{
char * V_102 ;
if ( ! ( V_3 -> V_8 & V_9 ) )
return 0 ;
V_3 -> V_36 -> V_130 = V_96 -> V_36 -> V_130 ;
V_102 = F_53 ( V_53 , L_5 , V_3 -> V_36 -> V_102 ,
V_96 -> V_131 ) ;
if ( ! V_102 )
return - V_54 ;
F_42 ( V_3 -> V_36 -> V_102 ) ;
V_3 -> V_36 -> V_102 = V_102 ;
V_96 -> V_36 = V_3 -> V_36 ;
return 0 ;
}
static int F_54 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_14 * V_16 = & V_3 -> V_16 ;
struct V_88 * V_132 ;
struct V_2 * V_96 ;
int V_26 ;
V_16 -> V_133 = & V_134 ;
V_16 -> V_17 . V_49 |= V_135 ;
V_132 = & V_16 -> V_37 ;
V_132 -> V_34 = V_3 -> V_32 . V_34 ;
V_132 -> V_91 = V_3 -> V_32 . V_91 ;
V_132 -> V_35 = V_3 -> V_32 . V_35 ;
V_132 -> V_92 = V_3 -> V_32 . V_91 ;
if ( V_3 -> V_8 & V_9 ) {
V_132 = & V_16 -> V_121 ;
V_132 -> V_34 = V_3 -> V_123 . V_34 ;
V_132 -> V_91 = V_3 -> V_123 . V_91 ;
V_132 -> V_35 = V_3 -> V_123 . V_35 ;
V_132 -> V_92 = V_3 -> V_123 . V_91 ;
}
V_96 = F_8 ( V_3 -> V_4 ,
V_10 ) ;
if ( V_96 ) {
V_26 = F_52 ( V_3 , V_96 ) ;
if ( V_26 < 0 )
goto V_136;
}
V_26 = F_55 ( & V_6 -> V_23 -> V_41 , V_16 ) ;
if ( V_26 < 0 )
goto V_136;
V_3 -> V_137 = true ;
return 0 ;
V_136:
V_3 -> V_36 = NULL ;
return V_26 ;
}
static void F_56 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_137 )
return;
F_57 ( & V_3 -> V_16 ) ;
}
static int F_58 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_138 V_25 ;
struct V_139 V_140 ;
struct V_88 * V_132 ;
int V_26 ;
V_25 . V_29 = V_3 -> V_4 -> V_30 ;
V_25 . V_31 = V_3 -> V_30 ;
V_26 = F_12 ( V_6 ,
V_141 ,
& V_25 , sizeof( V_25 ) , & V_140 , sizeof( V_140 ) ) ;
if ( V_26 < 0 )
return V_26 ;
V_132 = & V_3 -> V_32 ;
V_132 -> V_34 = F_51 ( V_140 . V_142 ) ;
V_132 -> V_91 = F_51 ( V_140 . V_143 ) ;
V_132 -> V_35 = F_51 ( V_140 . V_144 ) ;
V_3 -> V_36 -> V_130 = ( V_132 -> V_91 - V_132 -> V_34 ) / V_132 -> V_35 ;
if ( V_3 -> V_8 & V_9 ) {
V_132 = & V_3 -> V_123 ;
V_132 -> V_34 = F_51 ( V_140 . V_145 ) ;
V_132 -> V_91 = F_51 ( V_140 . V_146 ) ;
V_132 -> V_35 = F_51 ( V_140 . V_147 ) ;
}
return 0 ;
}
static int F_58 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_24 ( & V_6 -> V_23 -> V_41 , L_6 ) ;
return 0 ;
}
static int F_54 ( struct V_2 * V_3 )
{
return 0 ;
}
static void F_56 ( struct V_2 * V_3 )
{
}
static int F_59 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_12 * V_13 = F_7 ( V_3 ) ;
int V_26 ;
V_26 = F_60 ( & V_6 -> V_23 -> V_41 , V_13 ) ;
if ( V_26 < 0 )
V_3 -> V_36 = NULL ;
else
V_3 -> V_137 = true ;
return V_26 ;
}
static int F_61 ( struct V_2 * V_3 )
{
if ( ! F_3 ( V_3 ) )
return F_59 ( V_3 ) ;
if ( ! ( V_3 -> V_8 & V_10 ) )
return F_54 ( V_3 ) ;
return 0 ;
}
static void F_62 ( struct V_2 * V_3 )
{
struct V_12 * V_13 = F_7 ( V_3 ) ;
if ( ! V_3 -> V_137 )
return;
F_63 ( V_13 ) ;
V_3 -> V_36 = NULL ;
}
static void F_64 ( struct V_2 * V_3 )
{
if ( ! F_3 ( V_3 ) ) {
F_62 ( V_3 ) ;
return;
}
if ( V_3 -> V_8 & V_10 )
F_62 ( V_3 ) ;
else
F_56 ( V_3 ) ;
}
static int F_65 ( struct V_7 * V_4 ,
struct V_2 * V_3 )
{
struct V_148 V_140 ;
struct V_149 V_25 ;
struct V_1 * V_6 = F_2 ( V_4 ) ;
struct V_12 * V_13 = F_7 ( V_3 ) ;
char * V_102 ;
int V_26 ;
V_25 . V_29 = V_4 -> V_30 ;
V_25 . V_31 = V_3 -> V_30 ;
V_26 = F_12 ( V_6 , V_150 ,
& V_25 , sizeof( V_25 ) , & V_140 , sizeof( V_140 ) ) ;
if ( V_26 < 0 )
return V_26 ;
V_3 -> V_4 = V_4 ;
V_3 -> V_8 = F_51 ( V_140 . V_8 ) ;
V_3 -> V_49 = F_51 ( V_140 . V_49 ) ;
V_3 -> V_45 = F_51 ( V_140 . V_45 ) ;
V_3 -> V_151 = F_66 ( V_140 . V_151 , V_152 , V_53 ) ;
if ( ! V_3 -> V_151 )
return - V_54 ;
V_3 -> V_131 = F_66 ( V_140 . V_131 , V_152 , V_53 ) ;
if ( ! V_3 -> V_131 )
return - V_54 ;
V_3 -> V_36 = V_13 ;
V_102 = F_53 ( V_53 , L_7 , V_4 -> V_102 ,
V_3 -> V_151 , V_3 -> V_131 ) ;
if ( ! V_102 )
return - V_54 ;
V_13 -> V_102 = V_102 ;
V_13 -> V_130 = V_140 . V_130 ;
V_26 = F_26 ( V_3 , V_13 ) ;
if ( V_26 < 0 )
return V_26 ;
F_35 ( V_3 , V_13 ) ;
if ( ! F_3 ( V_3 ) )
return V_26 ;
V_4 -> V_153 = true ;
V_26 = F_58 ( V_3 ) ;
if ( V_26 < 0 )
return V_26 ;
return V_26 ;
}
static int F_67 ( struct V_154 * V_5 , V_72 V_30 )
{
struct V_7 * V_4 = & V_5 -> V_155 [ V_30 ] ;
struct V_156 V_25 ;
struct V_157 V_140 ;
int V_26 ;
int V_18 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_30 = V_30 ;
V_25 . V_30 = V_30 ;
V_26 = F_12 ( V_5 -> V_6 ,
V_158 ,
& V_25 , sizeof( V_25 ) , & V_140 , sizeof( V_140 ) ) ;
if ( V_26 < 0 )
return V_26 ;
if ( ! V_140 . V_159 )
return - V_80 ;
if ( ! strlen ( V_140 . V_102 ) )
return - V_80 ;
V_4 -> V_19 = V_140 . V_159 ;
V_4 -> V_102 = F_66 ( V_140 . V_102 , V_152 , V_53 ) ;
V_4 -> V_20 = F_27 ( V_4 -> V_19 ,
sizeof( struct V_2 ) , V_53 ) ;
if ( ! V_4 -> V_20 )
return - V_54 ;
for ( V_18 = 0 ; V_18 < V_4 -> V_19 ; V_18 ++ ) {
V_4 -> V_20 [ V_18 ] . V_30 = V_18 ;
V_26 = F_65 ( V_4 , & V_4 -> V_20 [ V_18 ] ) ;
if ( V_26 < 0 )
return V_26 ;
}
return 0 ;
}
static int F_68 ( struct V_7 * V_4 )
{
int V_26 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_4 -> V_19 ; V_18 ++ ) {
V_26 = F_61 ( & V_4 -> V_20 [ V_18 ] ) ;
if ( V_26 < 0 )
return V_26 ;
F_69 ( & V_4 -> V_20 [ V_18 ] . V_69 ) ;
}
V_4 -> V_160 = true ;
if ( V_4 -> V_153 ) {
V_26 = F_37 ( V_4 ) ;
if ( V_26 < 0 ) {
V_4 -> V_153 = false ;
return V_26 ;
}
}
return 0 ;
}
static void F_70 ( struct V_2 * V_3 )
{
F_42 ( V_3 -> V_52 ) ;
F_42 ( V_3 -> V_55 ) ;
F_42 ( V_3 -> V_56 ) ;
F_42 ( V_3 -> V_151 ) ;
F_42 ( V_3 -> V_131 ) ;
F_71 ( & V_3 -> V_69 ) ;
}
static void F_72 ( struct V_2 * V_3 )
{
V_3 -> V_27 = true ;
F_64 ( V_3 ) ;
F_70 ( V_3 ) ;
}
static void F_73 ( struct V_7 * V_4 )
{
int V_18 ;
int V_161 ;
V_4 -> V_160 = false ;
V_161 = V_4 -> V_19 ;
if ( V_4 -> V_153 )
F_43 ( V_4 ) ;
for ( V_18 = 0 ; V_18 < V_161 ; V_18 ++ ) {
F_72 ( & V_4 -> V_20 [ V_18 ] ) ;
V_4 -> V_19 -- ;
}
F_42 ( V_4 -> V_20 ) ;
F_42 ( V_4 -> V_102 ) ;
}
static void F_74 ( struct V_154 * V_5 )
{
int V_18 ;
if ( ! V_5 )
return;
F_16 ( & V_5 -> V_162 ) ;
if ( ! V_5 -> V_155 )
goto V_163;
for ( V_18 = 0 ; V_18 < V_5 -> V_164 ; V_18 ++ )
F_73 ( & V_5 -> V_155 [ V_18 ] ) ;
F_42 ( V_5 -> V_155 ) ;
V_163:
F_18 ( & V_5 -> V_162 ) ;
F_71 ( & V_5 -> V_162 ) ;
F_42 ( V_5 ) ;
}
static int F_75 ( struct V_154 * V_5 )
{
struct V_165 V_128 ;
int V_26 ;
V_26 = F_12 ( V_5 -> V_6 , V_166 ,
NULL , 0 , & V_128 , sizeof( V_128 ) ) ;
if ( V_26 < 0 )
return V_26 ;
if ( ! V_128 . V_164 )
return - V_80 ;
V_5 -> V_164 = V_128 . V_164 ;
return 0 ;
}
static int F_76 ( struct V_154 * V_5 )
{
struct V_1 * V_6 = V_5 -> V_6 ;
int V_26 ;
int V_18 ;
F_16 ( & V_5 -> V_162 ) ;
V_26 = F_75 ( V_5 ) ;
if ( V_26 < 0 )
goto V_167;
V_5 -> V_155 = F_27 ( V_5 -> V_164 ,
sizeof( struct V_7 ) , V_53 ) ;
if ( ! V_5 -> V_155 ) {
V_26 = - V_54 ;
goto V_167;
}
for ( V_18 = 0 ; V_18 < V_5 -> V_164 ; V_18 ++ ) {
V_26 = F_67 ( V_5 , V_18 ) ;
if ( V_26 < 0 ) {
F_24 ( & V_6 -> V_23 -> V_41 ,
L_8 ) ;
goto V_167;
}
}
V_167:
F_18 ( & V_5 -> V_162 ) ;
return V_26 ;
}
static int F_77 ( struct V_154 * V_5 )
{
struct V_1 * V_6 = V_5 -> V_6 ;
int V_26 = 0 ;
int V_18 ;
F_16 ( & V_5 -> V_162 ) ;
for ( V_18 = 0 ; V_18 < V_5 -> V_164 ; V_18 ++ ) {
V_26 = F_68 ( & V_5 -> V_155 [ V_18 ] ) ;
if ( V_26 < 0 ) {
F_24 ( & V_6 -> V_23 -> V_41 ,
L_9 ) ;
break;
}
}
F_18 ( & V_5 -> V_162 ) ;
return V_26 ;
}
static int F_78 ( struct V_168 * V_169 )
{
struct V_1 * V_6 = V_169 -> V_6 ;
struct V_40 * V_41 = & V_6 -> V_23 -> V_41 ;
struct V_154 * V_5 = F_79 ( V_6 ) ;
struct V_7 * V_4 ;
struct V_170 * V_171 ;
struct V_172 * V_173 ;
int V_26 = 0 ;
V_72 V_29 ;
V_72 V_174 ;
if ( V_169 -> type != V_175 ) {
F_24 ( V_41 , L_10 , V_169 -> type ) ;
return - V_80 ;
}
V_171 = V_169 -> V_171 ;
if ( V_171 -> V_176 < sizeof( * V_173 ) ) {
F_24 ( V_41 , L_11 ,
V_171 -> V_176 , sizeof( * V_173 ) ) ;
return - V_80 ;
}
V_173 = V_171 -> V_173 ;
V_29 = V_173 -> V_29 ;
if ( V_29 >= V_5 -> V_164 ||
! V_5 -> V_155 [ V_29 ] . V_160 ) {
F_24 ( V_41 , L_12 ,
V_29 ) ;
return - V_80 ;
}
V_174 = V_173 -> V_174 ;
if ( V_174 & V_177 ) {
V_4 = & V_5 -> V_155 [ V_29 ] ;
F_16 ( & V_5 -> V_162 ) ;
F_73 ( V_4 ) ;
V_26 = F_67 ( V_5 , V_29 ) ;
if ( ! V_26 )
V_26 = F_68 ( V_4 ) ;
if ( V_26 < 0 )
F_73 ( V_4 ) ;
F_18 ( & V_5 -> V_162 ) ;
}
return V_26 ;
}
static int F_80 ( struct V_22 * V_23 ,
const struct V_178 * V_30 )
{
struct V_179 * V_180 ;
struct V_1 * V_6 ;
struct V_154 * V_5 ;
int V_26 ;
if ( V_23 -> V_181 != 1 )
return - V_182 ;
V_180 = & V_23 -> V_180 [ 0 ] ;
if ( V_180 -> V_183 != V_184 )
return - V_182 ;
V_5 = F_81 ( sizeof( * V_5 ) , V_53 ) ;
if ( ! V_5 )
return - V_54 ;
F_69 ( & V_5 -> V_162 ) ;
V_6 = F_82 ( V_23 , F_83 ( V_180 -> V_30 ) ,
F_78 ) ;
if ( F_84 ( V_6 ) ) {
V_26 = F_41 ( V_6 ) ;
goto V_167;
}
V_5 -> V_6 = V_6 ;
F_85 ( V_6 , V_5 ) ;
F_86 ( V_23 , V_5 ) ;
V_26 = F_87 ( V_6 ) ;
if ( V_26 )
goto V_185;
V_26 = F_76 ( V_5 ) ;
if ( V_26 < 0 )
goto V_186;
V_26 = F_88 ( V_6 ) ;
if ( V_26 )
goto V_186;
V_26 = F_77 ( V_5 ) ;
if ( V_26 < 0 )
goto V_186;
F_13 ( V_23 ) ;
return 0 ;
V_186:
F_89 ( V_6 ) ;
V_185:
F_90 ( V_6 ) ;
V_167:
F_74 ( V_5 ) ;
return V_26 ;
}
static void F_91 ( struct V_22 * V_23 )
{
struct V_154 * V_5 = F_92 ( V_23 ) ;
if ( F_10 ( V_23 ) )
F_93 ( V_23 ) ;
F_89 ( V_5 -> V_6 ) ;
F_90 ( V_5 -> V_6 ) ;
F_74 ( V_5 ) ;
}
