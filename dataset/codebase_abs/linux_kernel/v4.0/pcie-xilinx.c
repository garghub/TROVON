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
unsigned long V_8 = F_2 ( V_5 , V_11 ) ;
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
if ( ! F_9 ( V_17 , V_18 ) )
return NULL ;
V_24 = ( V_17 -> V_20 << V_25 ) |
( V_18 << V_26 ) ;
return V_5 -> V_7 + V_24 + V_23 ;
}
static void F_11 ( unsigned int V_27 )
{
struct V_28 * V_29 ;
struct V_30 * V_31 ;
struct V_1 * V_5 ;
V_29 = F_12 ( V_27 ) ;
V_31 = F_13 ( V_29 ) ;
V_5 = F_1 ( V_31 -> V_13 -> V_17 -> V_19 ) ;
if ( ! F_14 ( V_27 , V_32 ) )
F_15 ( V_5 -> V_13 , L_2 , V_27 ) ;
else
F_16 ( V_27 , V_32 ) ;
}
static int F_17 ( struct V_1 * V_5 )
{
int V_33 ;
V_33 = F_18 ( V_32 , V_34 ) ;
if ( V_33 < V_34 )
F_19 ( V_33 , V_32 ) ;
else
return - V_35 ;
return V_33 ;
}
static void F_20 ( struct V_36 * V_37 ,
unsigned int V_27 )
{
F_11 ( V_27 ) ;
}
static int F_21 ( struct V_36 * V_37 ,
struct V_38 * V_39 ,
struct V_30 * V_29 )
{
struct V_1 * V_5 = F_1 ( V_39 -> V_17 -> V_19 ) ;
unsigned int V_27 ;
int V_40 ;
struct V_41 V_42 ;
T_3 V_43 ;
V_40 = F_17 ( V_5 ) ;
if ( V_40 < 0 )
return V_40 ;
V_27 = F_22 ( V_5 -> V_44 , V_40 ) ;
if ( ! V_27 )
return - V_45 ;
F_23 ( V_27 , V_29 ) ;
V_43 = F_24 ( ( void * ) V_5 -> V_46 ) ;
V_42 . V_47 = 0 ;
V_42 . V_48 = V_43 ;
V_42 . V_49 = V_27 ;
F_25 ( V_27 , & V_42 ) ;
return 0 ;
}
static int F_26 ( struct V_44 * V_50 , unsigned int V_27 ,
T_4 V_40 )
{
F_27 ( V_27 , & V_51 , V_52 ) ;
F_28 ( V_27 , V_50 -> V_53 ) ;
F_29 ( V_27 , V_54 ) ;
return 0 ;
}
static void F_30 ( struct V_1 * V_5 )
{
T_3 V_43 ;
V_5 -> V_46 = F_31 ( V_55 , 0 ) ;
V_43 = F_24 ( ( void * ) V_5 -> V_46 ) ;
F_4 ( V_5 , 0x0 , V_56 ) ;
F_4 ( V_5 , V_43 , V_57 ) ;
}
static int F_32 ( struct V_44 * V_50 , unsigned int V_27 ,
T_4 V_40 )
{
F_27 ( V_27 , & V_58 , V_52 ) ;
F_28 ( V_27 , V_50 -> V_53 ) ;
F_29 ( V_27 , V_54 ) ;
return 0 ;
}
static T_5 F_33 ( int V_27 , void * V_49 )
{
struct V_1 * V_5 = (struct V_1 * ) V_49 ;
T_1 V_8 , V_59 , V_60 , V_61 ;
V_8 = F_2 ( V_5 , V_62 ) ;
V_59 = F_2 ( V_5 , V_63 ) ;
V_60 = V_8 & V_59 ;
if ( ! V_60 )
return V_64 ;
if ( V_60 & V_65 )
F_34 ( V_5 -> V_13 , L_3 ) ;
if ( V_60 & V_66 )
F_34 ( V_5 -> V_13 , L_4 ) ;
if ( V_60 & V_67 )
F_34 ( V_5 -> V_13 , L_5 ) ;
if ( V_60 & V_68 )
F_35 ( V_5 -> V_13 , L_6 ) ;
if ( V_60 & V_69 )
F_34 ( V_5 -> V_13 , L_7 ) ;
if ( V_60 & V_70 ) {
F_34 ( V_5 -> V_13 , L_8 ) ;
F_7 ( V_5 ) ;
}
if ( V_60 & V_71 ) {
F_34 ( V_5 -> V_13 , L_9 ) ;
F_7 ( V_5 ) ;
}
if ( V_60 & V_72 ) {
F_34 ( V_5 -> V_13 , L_10 ) ;
F_7 ( V_5 ) ;
}
if ( V_60 & V_73 ) {
V_8 = F_2 ( V_5 , V_74 ) ;
if ( ! ( V_8 & V_75 ) ) {
F_34 ( V_5 -> V_13 , L_11 ) ;
return V_76 ;
}
F_4 ( V_5 , V_77 ,
V_74 ) ;
V_8 = ( ( V_8 & V_78 ) >>
V_79 ) + 1 ;
F_36 ( F_37 ( V_5 -> V_44 , V_8 ) ) ;
}
if ( V_60 & V_80 ) {
V_8 = F_2 ( V_5 , V_74 ) ;
if ( ! ( V_8 & V_75 ) ) {
F_34 ( V_5 -> V_13 , L_11 ) ;
return V_76 ;
}
if ( V_8 & V_81 ) {
V_61 = F_2 ( V_5 , V_82 ) &
V_83 ;
F_4 ( V_5 , V_77 ,
V_74 ) ;
if ( F_38 ( V_84 ) ) {
F_36 ( V_61 ) ;
}
}
}
if ( V_60 & V_85 )
F_34 ( V_5 -> V_13 , L_12 ) ;
if ( V_60 & V_86 )
F_34 ( V_5 -> V_13 , L_13 ) ;
if ( V_60 & V_87 )
F_34 ( V_5 -> V_13 , L_14 ) ;
if ( V_60 & V_88 )
F_34 ( V_5 -> V_13 , L_15 ) ;
if ( V_60 & V_89 )
F_34 ( V_5 -> V_13 , L_16 ) ;
if ( V_60 & V_90 )
F_34 ( V_5 -> V_13 , L_17 ) ;
if ( V_60 & V_91 )
F_34 ( V_5 -> V_13 , L_18 ) ;
if ( V_60 & V_92 )
F_34 ( V_5 -> V_13 , L_19 ) ;
if ( V_60 & V_93 )
F_34 ( V_5 -> V_13 , L_20 ) ;
F_4 ( V_5 , V_60 , V_62 ) ;
return V_76 ;
}
static void F_39 ( struct V_1 * V_5 )
{
int V_94 ;
T_1 V_27 , V_95 ;
if ( F_38 ( V_84 ) ) {
F_40 ( V_5 -> V_46 , 0 ) ;
V_95 = V_34 ;
} else {
V_95 = 4 ;
}
for ( V_94 = 0 ; V_94 < V_95 ; V_94 ++ ) {
V_27 = F_37 ( V_5 -> V_44 , V_94 ) ;
if ( V_27 > 0 )
F_41 ( V_27 ) ;
}
F_42 ( V_5 -> V_44 ) ;
}
static int F_43 ( struct V_1 * V_5 )
{
struct V_96 * V_13 = V_5 -> V_13 ;
struct V_97 * V_98 = V_13 -> V_99 ;
struct V_97 * V_100 ;
V_100 = F_44 ( V_98 , NULL ) ;
if ( ! V_100 ) {
F_15 ( V_13 , L_21 ) ;
return F_45 ( V_100 ) ;
}
V_5 -> V_44 = F_46 ( V_100 , 4 ,
& V_101 ,
V_5 ) ;
if ( ! V_5 -> V_44 ) {
F_15 ( V_13 , L_22 ) ;
return F_45 ( V_5 -> V_44 ) ;
}
if ( F_38 ( V_84 ) ) {
V_5 -> V_44 = F_46 ( V_98 ,
V_34 ,
& V_102 ,
& V_103 ) ;
if ( ! V_5 -> V_44 ) {
F_15 ( V_13 , L_23 ) ;
return F_45 ( V_5 -> V_44 ) ;
}
F_30 ( V_5 ) ;
}
return 0 ;
}
static void F_47 ( struct V_1 * V_5 )
{
if ( F_6 ( V_5 ) )
F_35 ( V_5 -> V_13 , L_24 ) ;
else
F_35 ( V_5 -> V_13 , L_25 ) ;
F_4 ( V_5 , ~ V_104 ,
V_63 ) ;
F_4 ( V_5 , F_2 ( V_5 , V_62 ) &
V_105 ,
V_62 ) ;
F_4 ( V_5 , V_105 , V_63 ) ;
F_4 ( V_5 , F_2 ( V_5 , V_106 ) |
V_107 ,
V_106 ) ;
}
static int F_48 ( int V_108 , struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_49 ( & V_5 -> V_109 , & V_3 -> V_109 ) ;
return 1 ;
}
static struct V_16 * F_50 ( int V_108 , struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_16 * V_17 ;
V_5 -> V_21 = V_3 -> V_110 ;
V_17 = F_51 ( V_5 -> V_13 , V_3 -> V_110 , & V_111 ,
V_3 , & V_3 -> V_109 ) ;
return V_17 ;
}
static int F_52 ( struct V_1 * V_5 )
{
struct V_96 * V_13 = V_5 -> V_13 ;
struct V_97 * V_98 = V_13 -> V_99 ;
struct V_112 * V_113 ;
T_6 V_114 ;
struct V_115 V_116 ;
struct V_117 V_118 ;
struct V_119 * V_120 ;
int V_121 = 0 , V_122 = 0 ;
if ( F_53 ( & V_116 , V_98 ) ) {
F_15 ( V_13 , L_26 ) ;
return - V_45 ;
}
F_54 (&parser, &range) {
if ( V_122 >= V_123 ) {
F_15 ( V_13 , L_27 ) ;
return - V_45 ;
}
V_113 = F_55 ( V_13 , sizeof( * V_113 ) , V_55 ) ;
if ( ! V_113 ) {
V_121 = - V_124 ;
goto V_125;
}
F_56 ( & V_118 , V_98 , V_113 ) ;
switch ( V_113 -> V_126 & V_127 ) {
case V_128 :
V_114 = V_118 . V_129 - V_118 . V_130 ;
V_122 ++ ;
break;
default:
V_121 = - V_45 ;
break;
}
if ( V_121 < 0 ) {
F_34 ( V_13 , L_28 , V_113 ) ;
continue;
}
V_121 = F_57 ( & V_131 , V_113 ) ;
if ( V_121 )
goto V_125;
F_58 ( & V_5 -> V_109 , V_113 , V_114 ) ;
}
if ( F_59 ( V_98 , & V_5 -> V_132 ) ) {
T_1 V_8 = F_2 ( V_5 , V_133 ) ;
T_7 V_134 ;
V_134 = ( V_8 & V_135 ) >>
V_136 ;
V_5 -> V_132 = (struct V_112 ) {
. V_137 = V_98 -> V_137 ,
. V_138 = 0 ,
. V_139 = V_134 ,
. V_126 = V_140 ,
} ;
}
F_60 ( & V_5 -> V_109 , & V_5 -> V_132 ) ;
return 0 ;
V_125:
F_61 ( & V_131 ) ;
F_62 (win, &port->resources)
F_63 ( V_13 , V_120 -> V_141 ) ;
F_64 ( & V_5 -> V_109 ) ;
return V_121 ;
}
static int F_65 ( struct V_1 * V_5 )
{
struct V_96 * V_13 = V_5 -> V_13 ;
struct V_97 * V_98 = V_13 -> V_99 ;
struct V_112 V_142 ;
const char * type ;
int V_121 ;
type = F_66 ( V_98 , L_29 , NULL ) ;
if ( ! type || strcmp ( type , L_30 ) ) {
F_15 ( V_13 , L_31 , type ) ;
return - V_45 ;
}
V_121 = F_67 ( V_98 , 0 , & V_142 ) ;
if ( V_121 ) {
F_15 ( V_13 , L_32 ) ;
return V_121 ;
}
V_5 -> V_7 = F_68 ( V_13 , & V_142 ) ;
if ( F_69 ( V_5 -> V_7 ) )
return F_45 ( V_5 -> V_7 ) ;
V_5 -> V_27 = F_70 ( V_98 , 0 ) ;
V_121 = F_71 ( V_13 , V_5 -> V_27 , F_33 ,
V_143 , L_33 , V_5 ) ;
if ( V_121 ) {
F_15 ( V_13 , L_34 , V_5 -> V_27 ) ;
return V_121 ;
}
return 0 ;
}
static int F_72 ( struct V_144 * V_39 )
{
struct V_1 * V_5 ;
struct V_145 V_146 ;
struct V_96 * V_13 = & V_39 -> V_13 ;
int V_121 ;
if ( ! V_13 -> V_99 )
return - V_147 ;
V_5 = F_73 ( V_13 , sizeof( * V_5 ) , V_55 ) ;
if ( ! V_5 )
return - V_124 ;
V_5 -> V_13 = V_13 ;
V_121 = F_65 ( V_5 ) ;
if ( V_121 ) {
F_15 ( V_13 , L_35 ) ;
return V_121 ;
}
F_47 ( V_5 ) ;
V_121 = F_43 ( V_5 ) ;
if ( V_121 ) {
F_15 ( V_13 , L_36 ) ;
return V_121 ;
}
F_74 ( & V_5 -> V_109 ) ;
V_121 = F_52 ( V_5 ) ;
if ( V_121 ) {
F_15 ( V_13 , L_37 ) ;
return V_121 ;
}
F_75 ( V_39 , V_5 ) ;
memset ( & V_146 , 0 , sizeof( V_146 ) ) ;
V_146 = (struct V_145 ) {
. V_148 = 1 ,
. V_4 = ( void * * ) & V_5 ,
. V_149 = F_48 ,
. V_150 = V_151 ,
. V_152 = F_50 ,
. V_153 = & V_111 ,
} ;
#ifdef V_84
V_103 . V_13 = V_5 -> V_13 ;
V_146 . V_154 = & V_103 ;
#endif
F_76 ( V_13 , & V_146 ) ;
return 0 ;
}
static int F_77 ( struct V_144 * V_39 )
{
struct V_1 * V_5 = F_78 ( V_39 ) ;
F_39 ( V_5 ) ;
return 0 ;
}
