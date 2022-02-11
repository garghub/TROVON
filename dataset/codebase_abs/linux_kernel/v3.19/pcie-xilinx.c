static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 ;
}
static inline T_1 F_2 ( struct V_1 * V_5 , T_1 V_6 )
{
return F_3 ( V_5 -> V_7 + V_6 ) ;
}
static inline void F_4 ( struct V_1 * V_5 , T_1 V_8 , T_1 V_6 )
{
F_5 ( V_8 , V_5 -> V_7 + V_6 ) ;
}
static inline bool F_6 ( struct V_1 * V_5 )
{
return ( F_2 ( V_5 , V_9 ) &
V_10 ) ? 1 : 0 ;
}
static void F_7 ( struct V_1 * V_5 )
{
T_1 V_8 = F_2 ( V_5 , V_11 ) ;
if ( V_8 & V_12 ) {
F_8 ( V_5 -> V_13 , L_1 ,
V_8 & V_14 ) ;
F_4 ( V_5 , V_15 ,
V_11 ) ;
}
}
static bool F_9 ( struct V_16 * V_17 , unsigned int V_18 )
{
struct V_1 * V_5 = F_1 ( V_17 -> V_19 ) ;
if ( V_17 -> V_20 != V_5 -> V_21 )
if ( ! F_6 ( V_5 ) )
return false ;
if ( V_17 -> V_20 == V_5 -> V_21 && V_18 > 0 )
return false ;
if ( V_17 -> V_22 == V_5 -> V_21 && V_18 > 0 )
return false ;
return true ;
}
static void T_2 * F_10 ( struct V_16 * V_17 ,
unsigned int V_18 , int V_23 )
{
struct V_1 * V_5 = F_1 ( V_17 -> V_19 ) ;
int V_24 ;
V_24 = ( V_17 -> V_20 << V_25 ) |
( V_18 << V_26 ) ;
return V_5 -> V_7 + V_24 + V_23 ;
}
static int F_11 ( struct V_16 * V_17 , unsigned int V_18 ,
int V_23 , int V_27 , T_1 * V_8 )
{
void T_2 * V_28 ;
if ( ! F_9 ( V_17 , V_18 ) ) {
* V_8 = 0xFFFFFFFF ;
return V_29 ;
}
V_28 = F_10 ( V_17 , V_18 , V_23 ) ;
switch ( V_27 ) {
case 1 :
* V_8 = F_12 ( V_28 ) ;
break;
case 2 :
* V_8 = F_13 ( V_28 ) ;
break;
default:
* V_8 = F_3 ( V_28 ) ;
break;
}
return V_30 ;
}
static int F_14 ( struct V_16 * V_17 , unsigned int V_18 ,
int V_23 , int V_27 , T_1 V_8 )
{
void T_2 * V_28 ;
if ( ! F_9 ( V_17 , V_18 ) )
return V_29 ;
V_28 = F_10 ( V_17 , V_18 , V_23 ) ;
switch ( V_27 ) {
case 1 :
F_15 ( V_8 , V_28 ) ;
break;
case 2 :
F_16 ( V_8 , V_28 ) ;
break;
default:
F_5 ( V_8 , V_28 ) ;
break;
}
return V_30 ;
}
static void F_17 ( unsigned int V_31 )
{
struct V_32 * V_33 ;
struct V_34 * V_35 ;
struct V_1 * V_5 ;
V_33 = F_18 ( V_31 ) ;
V_35 = F_19 ( V_33 ) ;
V_5 = F_1 ( V_35 -> V_13 -> V_17 -> V_19 ) ;
if ( ! F_20 ( V_31 , V_36 ) )
F_21 ( V_5 -> V_13 , L_2 , V_31 ) ;
else
F_22 ( V_31 , V_36 ) ;
}
static int F_23 ( struct V_1 * V_5 )
{
int V_37 ;
V_37 = F_24 ( V_36 , V_38 ) ;
if ( V_37 < V_38 )
F_25 ( V_37 , V_36 ) ;
else
return - V_39 ;
return V_37 ;
}
static void F_26 ( struct V_40 * V_41 ,
unsigned int V_31 )
{
F_17 ( V_31 ) ;
}
static int F_27 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
struct V_34 * V_33 )
{
struct V_1 * V_5 = F_1 ( V_43 -> V_17 -> V_19 ) ;
unsigned int V_31 ;
int V_44 ;
struct V_45 V_46 ;
T_3 V_47 ;
V_44 = F_23 ( V_5 ) ;
if ( V_44 < 0 )
return V_44 ;
V_31 = F_28 ( V_5 -> V_48 , V_44 ) ;
if ( ! V_31 )
return - V_49 ;
F_29 ( V_31 , V_33 ) ;
V_47 = F_30 ( ( void * ) V_5 -> V_50 ) ;
V_46 . V_51 = 0 ;
V_46 . V_52 = V_47 ;
V_46 . V_53 = V_31 ;
F_31 ( V_31 , & V_46 ) ;
return 0 ;
}
static int F_32 ( struct V_48 * V_54 , unsigned int V_31 ,
T_4 V_44 )
{
F_33 ( V_31 , & V_55 , V_56 ) ;
F_34 ( V_31 , V_54 -> V_57 ) ;
F_35 ( V_31 , V_58 ) ;
return 0 ;
}
static void F_36 ( struct V_1 * V_5 )
{
T_3 V_47 ;
V_5 -> V_50 = F_37 ( V_59 , 0 ) ;
V_47 = F_30 ( ( void * ) V_5 -> V_50 ) ;
F_4 ( V_5 , 0x0 , V_60 ) ;
F_4 ( V_5 , V_47 , V_61 ) ;
}
static int F_38 ( struct V_48 * V_54 , unsigned int V_31 ,
T_4 V_44 )
{
F_33 ( V_31 , & V_62 , V_56 ) ;
F_34 ( V_31 , V_54 -> V_57 ) ;
F_35 ( V_31 , V_58 ) ;
return 0 ;
}
static T_5 F_39 ( int V_31 , void * V_53 )
{
struct V_1 * V_5 = (struct V_1 * ) V_53 ;
T_1 V_8 , V_63 , V_64 , V_65 ;
V_8 = F_2 ( V_5 , V_66 ) ;
V_63 = F_2 ( V_5 , V_67 ) ;
V_64 = V_8 & V_63 ;
if ( ! V_64 )
return V_68 ;
if ( V_64 & V_69 )
F_40 ( V_5 -> V_13 , L_3 ) ;
if ( V_64 & V_70 )
F_40 ( V_5 -> V_13 , L_4 ) ;
if ( V_64 & V_71 )
F_40 ( V_5 -> V_13 , L_5 ) ;
if ( V_64 & V_72 )
F_41 ( V_5 -> V_13 , L_6 ) ;
if ( V_64 & V_73 )
F_40 ( V_5 -> V_13 , L_7 ) ;
if ( V_64 & V_74 ) {
F_40 ( V_5 -> V_13 , L_8 ) ;
F_7 ( V_5 ) ;
}
if ( V_64 & V_75 ) {
F_40 ( V_5 -> V_13 , L_9 ) ;
F_7 ( V_5 ) ;
}
if ( V_64 & V_76 ) {
F_40 ( V_5 -> V_13 , L_10 ) ;
F_7 ( V_5 ) ;
}
if ( V_64 & V_77 ) {
V_8 = F_2 ( V_5 , V_78 ) ;
if ( ! ( V_8 & V_79 ) ) {
F_40 ( V_5 -> V_13 , L_11 ) ;
return V_80 ;
}
F_4 ( V_5 , V_81 ,
V_78 ) ;
V_8 = ( ( V_8 & V_82 ) >>
V_83 ) + 1 ;
F_42 ( F_43 ( V_5 -> V_48 , V_8 ) ) ;
}
if ( V_64 & V_84 ) {
V_8 = F_2 ( V_5 , V_78 ) ;
if ( ! ( V_8 & V_79 ) ) {
F_40 ( V_5 -> V_13 , L_11 ) ;
return V_80 ;
}
if ( V_8 & V_85 ) {
V_65 = F_2 ( V_5 , V_86 ) &
V_87 ;
F_4 ( V_5 , V_81 ,
V_78 ) ;
if ( F_44 ( V_88 ) ) {
F_42 ( V_65 ) ;
}
}
}
if ( V_64 & V_89 )
F_40 ( V_5 -> V_13 , L_12 ) ;
if ( V_64 & V_90 )
F_40 ( V_5 -> V_13 , L_13 ) ;
if ( V_64 & V_91 )
F_40 ( V_5 -> V_13 , L_14 ) ;
if ( V_64 & V_92 )
F_40 ( V_5 -> V_13 , L_15 ) ;
if ( V_64 & V_93 )
F_40 ( V_5 -> V_13 , L_16 ) ;
if ( V_64 & V_94 )
F_40 ( V_5 -> V_13 , L_17 ) ;
if ( V_64 & V_95 )
F_40 ( V_5 -> V_13 , L_18 ) ;
if ( V_64 & V_96 )
F_40 ( V_5 -> V_13 , L_19 ) ;
if ( V_64 & V_97 )
F_40 ( V_5 -> V_13 , L_20 ) ;
F_4 ( V_5 , V_64 , V_66 ) ;
return V_80 ;
}
static void F_45 ( struct V_1 * V_5 )
{
int V_98 ;
T_1 V_31 , V_99 ;
if ( F_44 ( V_88 ) ) {
F_46 ( V_5 -> V_50 , 0 ) ;
V_99 = V_38 ;
} else {
V_99 = 4 ;
}
for ( V_98 = 0 ; V_98 < V_99 ; V_98 ++ ) {
V_31 = F_43 ( V_5 -> V_48 , V_98 ) ;
if ( V_31 > 0 )
F_47 ( V_31 ) ;
}
F_48 ( V_5 -> V_48 ) ;
}
static int F_49 ( struct V_1 * V_5 )
{
struct V_100 * V_13 = V_5 -> V_13 ;
struct V_101 * V_102 = V_13 -> V_103 ;
struct V_101 * V_104 ;
V_104 = F_50 ( V_102 , NULL ) ;
if ( ! V_104 ) {
F_21 ( V_13 , L_21 ) ;
return F_51 ( V_104 ) ;
}
V_5 -> V_48 = F_52 ( V_104 , 4 ,
& V_105 ,
V_5 ) ;
if ( ! V_5 -> V_48 ) {
F_21 ( V_13 , L_22 ) ;
return F_51 ( V_5 -> V_48 ) ;
}
if ( F_44 ( V_88 ) ) {
V_5 -> V_48 = F_52 ( V_102 ,
V_38 ,
& V_106 ,
& V_107 ) ;
if ( ! V_5 -> V_48 ) {
F_21 ( V_13 , L_23 ) ;
return F_51 ( V_5 -> V_48 ) ;
}
F_36 ( V_5 ) ;
}
return 0 ;
}
static void F_53 ( struct V_1 * V_5 )
{
if ( F_6 ( V_5 ) )
F_41 ( V_5 -> V_13 , L_24 ) ;
else
F_41 ( V_5 -> V_13 , L_25 ) ;
F_4 ( V_5 , ~ V_108 ,
V_67 ) ;
F_4 ( V_5 , F_2 ( V_5 , V_66 ) &
V_109 ,
V_66 ) ;
F_4 ( V_5 , V_109 , V_67 ) ;
F_4 ( V_5 , F_2 ( V_5 , V_110 ) |
V_111 ,
V_110 ) ;
}
static int F_54 ( int V_112 , struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_55 ( & V_5 -> V_113 , & V_3 -> V_113 ) ;
return 1 ;
}
static struct V_16 * F_56 ( int V_112 , struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_16 * V_17 ;
V_5 -> V_21 = V_3 -> V_114 ;
V_17 = F_57 ( V_5 -> V_13 , V_3 -> V_114 , & V_115 ,
V_3 , & V_3 -> V_113 ) ;
return V_17 ;
}
static int F_58 ( struct V_1 * V_5 )
{
struct V_100 * V_13 = V_5 -> V_13 ;
struct V_101 * V_102 = V_13 -> V_103 ;
struct V_116 * V_117 ;
T_6 V_118 ;
struct V_119 V_120 ;
struct V_121 V_122 ;
struct V_123 * V_124 ;
int V_125 = 0 , V_126 = 0 ;
if ( F_59 ( & V_120 , V_102 ) ) {
F_21 ( V_13 , L_26 ) ;
return - V_49 ;
}
F_60 (&parser, &range) {
if ( V_126 >= V_127 ) {
F_21 ( V_13 , L_27 ) ;
return - V_49 ;
}
V_117 = F_61 ( V_13 , sizeof( * V_117 ) , V_59 ) ;
if ( ! V_117 ) {
V_125 = - V_128 ;
goto V_129;
}
F_62 ( & V_122 , V_102 , V_117 ) ;
switch ( V_117 -> V_130 & V_131 ) {
case V_132 :
V_118 = V_122 . V_133 - V_122 . V_134 ;
V_126 ++ ;
break;
default:
V_125 = - V_49 ;
break;
}
if ( V_125 < 0 ) {
F_40 ( V_13 , L_28 , V_117 ) ;
continue;
}
V_125 = F_63 ( & V_135 , V_117 ) ;
if ( V_125 )
goto V_129;
F_64 ( & V_5 -> V_113 , V_117 , V_118 ) ;
}
if ( F_65 ( V_102 , & V_5 -> V_136 ) ) {
T_1 V_8 = F_2 ( V_5 , V_137 ) ;
T_7 V_138 ;
V_138 = ( V_8 & V_139 ) >>
V_140 ;
V_5 -> V_136 = (struct V_116 ) {
. V_141 = V_102 -> V_141 ,
. V_142 = 0 ,
. V_143 = V_138 ,
. V_130 = V_144 ,
} ;
}
F_66 ( & V_5 -> V_113 , & V_5 -> V_136 ) ;
return 0 ;
V_129:
F_67 ( & V_135 ) ;
F_68 (win, &port->resources, list)
F_69 ( V_13 , V_124 -> V_145 ) ;
F_70 ( & V_5 -> V_113 ) ;
return V_125 ;
}
static int F_71 ( struct V_1 * V_5 )
{
struct V_100 * V_13 = V_5 -> V_13 ;
struct V_101 * V_102 = V_13 -> V_103 ;
struct V_116 V_146 ;
const char * type ;
int V_125 ;
type = F_72 ( V_102 , L_29 , NULL ) ;
if ( ! type || strcmp ( type , L_30 ) ) {
F_21 ( V_13 , L_31 , type ) ;
return - V_49 ;
}
V_125 = F_73 ( V_102 , 0 , & V_146 ) ;
if ( V_125 ) {
F_21 ( V_13 , L_32 ) ;
return V_125 ;
}
V_5 -> V_7 = F_74 ( V_13 , & V_146 ) ;
if ( F_75 ( V_5 -> V_7 ) )
return F_51 ( V_5 -> V_7 ) ;
V_5 -> V_31 = F_76 ( V_102 , 0 ) ;
V_125 = F_77 ( V_13 , V_5 -> V_31 , F_39 ,
V_147 , L_33 , V_5 ) ;
if ( V_125 ) {
F_21 ( V_13 , L_34 , V_5 -> V_31 ) ;
return V_125 ;
}
return 0 ;
}
static int F_78 ( struct V_148 * V_43 )
{
struct V_1 * V_5 ;
struct V_149 V_150 ;
struct V_100 * V_13 = & V_43 -> V_13 ;
int V_125 ;
if ( ! V_13 -> V_103 )
return - V_151 ;
V_5 = F_79 ( V_13 , sizeof( * V_5 ) , V_59 ) ;
if ( ! V_5 )
return - V_128 ;
V_5 -> V_13 = V_13 ;
V_125 = F_71 ( V_5 ) ;
if ( V_125 ) {
F_21 ( V_13 , L_35 ) ;
return V_125 ;
}
F_53 ( V_5 ) ;
V_125 = F_49 ( V_5 ) ;
if ( V_125 ) {
F_21 ( V_13 , L_36 ) ;
return V_125 ;
}
F_80 ( & V_5 -> V_113 ) ;
V_125 = F_58 ( V_5 ) ;
if ( V_125 ) {
F_21 ( V_13 , L_37 ) ;
return V_125 ;
}
F_81 ( V_43 , V_5 ) ;
memset ( & V_150 , 0 , sizeof( V_150 ) ) ;
V_150 = (struct V_149 ) {
. V_152 = 1 ,
. V_4 = ( void * * ) & V_5 ,
. V_153 = F_54 ,
. V_154 = V_155 ,
. V_156 = F_56 ,
. V_157 = & V_115 ,
} ;
#ifdef V_88
V_107 . V_13 = V_5 -> V_13 ;
V_150 . V_158 = & V_107 ;
#endif
F_82 ( V_13 , & V_150 ) ;
return 0 ;
}
static int F_83 ( struct V_148 * V_43 )
{
struct V_1 * V_5 = F_84 ( V_43 ) ;
F_45 ( V_5 ) ;
return 0 ;
}
