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
struct V_1 * V_5 ;
if ( ! F_12 ( V_27 , V_30 ) ) {
V_29 = F_13 ( V_27 ) ;
V_5 = F_1 ( F_14 ( V_29 ) ) ;
F_15 ( V_5 -> V_13 , L_2 , V_27 ) ;
} else {
F_16 ( V_27 , V_30 ) ;
}
}
static int F_17 ( struct V_1 * V_5 )
{
int V_31 ;
V_31 = F_18 ( V_30 , V_32 ) ;
if ( V_31 < V_32 )
F_19 ( V_31 , V_30 ) ;
else
return - V_33 ;
return V_31 ;
}
static void F_20 ( struct V_34 * V_35 ,
unsigned int V_27 )
{
F_11 ( V_27 ) ;
}
static int F_21 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
struct V_28 * V_38 )
{
struct V_1 * V_5 = F_1 ( V_37 -> V_17 -> V_19 ) ;
unsigned int V_27 ;
int V_39 ;
struct V_40 V_41 ;
T_3 V_42 ;
V_39 = F_17 ( V_5 ) ;
if ( V_39 < 0 )
return V_39 ;
V_27 = F_22 ( V_5 -> V_43 , V_39 ) ;
if ( ! V_27 )
return - V_44 ;
F_23 ( V_27 , V_38 ) ;
V_42 = F_24 ( ( void * ) V_5 -> V_45 ) ;
V_41 . V_46 = 0 ;
V_41 . V_47 = V_42 ;
V_41 . V_48 = V_27 ;
F_25 ( V_27 , & V_41 ) ;
return 0 ;
}
static int F_26 ( struct V_43 * V_49 , unsigned int V_27 ,
T_4 V_39 )
{
F_27 ( V_27 , & V_50 , V_51 ) ;
F_28 ( V_27 , V_49 -> V_52 ) ;
return 0 ;
}
static void F_29 ( struct V_1 * V_5 )
{
T_3 V_42 ;
V_5 -> V_45 = F_30 ( V_53 , 0 ) ;
V_42 = F_24 ( ( void * ) V_5 -> V_45 ) ;
F_4 ( V_5 , 0x0 , V_54 ) ;
F_4 ( V_5 , V_42 , V_55 ) ;
}
static int F_31 ( struct V_43 * V_49 , unsigned int V_27 ,
T_4 V_39 )
{
F_27 ( V_27 , & V_56 , V_51 ) ;
F_28 ( V_27 , V_49 -> V_52 ) ;
return 0 ;
}
static T_5 F_32 ( int V_27 , void * V_48 )
{
struct V_1 * V_5 = (struct V_1 * ) V_48 ;
T_1 V_8 , V_57 , V_58 , V_59 ;
V_8 = F_2 ( V_5 , V_60 ) ;
V_57 = F_2 ( V_5 , V_61 ) ;
V_58 = V_8 & V_57 ;
if ( ! V_58 )
return V_62 ;
if ( V_58 & V_63 )
F_33 ( V_5 -> V_13 , L_3 ) ;
if ( V_58 & V_64 )
F_33 ( V_5 -> V_13 , L_4 ) ;
if ( V_58 & V_65 )
F_33 ( V_5 -> V_13 , L_5 ) ;
if ( V_58 & V_66 )
F_34 ( V_5 -> V_13 , L_6 ) ;
if ( V_58 & V_67 )
F_33 ( V_5 -> V_13 , L_7 ) ;
if ( V_58 & V_68 ) {
F_33 ( V_5 -> V_13 , L_8 ) ;
F_7 ( V_5 ) ;
}
if ( V_58 & V_69 ) {
F_33 ( V_5 -> V_13 , L_9 ) ;
F_7 ( V_5 ) ;
}
if ( V_58 & V_70 ) {
F_33 ( V_5 -> V_13 , L_10 ) ;
F_7 ( V_5 ) ;
}
if ( V_58 & V_71 ) {
V_8 = F_2 ( V_5 , V_72 ) ;
if ( ! ( V_8 & V_73 ) ) {
F_33 ( V_5 -> V_13 , L_11 ) ;
return V_74 ;
}
if ( ! ( V_8 & V_75 ) ) {
F_4 ( V_5 , V_76 ,
V_72 ) ;
V_8 = ( ( V_8 & V_77 ) >>
V_78 ) + 1 ;
F_35 ( F_36 ( V_5 -> V_43 ,
V_8 ) ) ;
}
}
if ( V_58 & V_79 ) {
V_8 = F_2 ( V_5 , V_72 ) ;
if ( ! ( V_8 & V_73 ) ) {
F_33 ( V_5 -> V_13 , L_11 ) ;
return V_74 ;
}
if ( V_8 & V_75 ) {
V_59 = F_2 ( V_5 , V_80 ) &
V_81 ;
F_4 ( V_5 , V_76 ,
V_72 ) ;
if ( F_37 ( V_82 ) ) {
F_35 ( V_59 ) ;
}
}
}
if ( V_58 & V_83 )
F_33 ( V_5 -> V_13 , L_12 ) ;
if ( V_58 & V_84 )
F_33 ( V_5 -> V_13 , L_13 ) ;
if ( V_58 & V_85 )
F_33 ( V_5 -> V_13 , L_14 ) ;
if ( V_58 & V_86 )
F_33 ( V_5 -> V_13 , L_15 ) ;
if ( V_58 & V_87 )
F_33 ( V_5 -> V_13 , L_16 ) ;
if ( V_58 & V_88 )
F_33 ( V_5 -> V_13 , L_17 ) ;
if ( V_58 & V_89 )
F_33 ( V_5 -> V_13 , L_18 ) ;
if ( V_58 & V_90 )
F_33 ( V_5 -> V_13 , L_19 ) ;
if ( V_58 & V_91 )
F_33 ( V_5 -> V_13 , L_20 ) ;
F_4 ( V_5 , V_58 , V_60 ) ;
return V_74 ;
}
static void F_38 ( struct V_1 * V_5 )
{
int V_92 ;
T_1 V_27 , V_93 ;
if ( F_37 ( V_82 ) ) {
F_39 ( V_5 -> V_45 , 0 ) ;
V_93 = V_32 ;
} else {
V_93 = 4 ;
}
for ( V_92 = 0 ; V_92 < V_93 ; V_92 ++ ) {
V_27 = F_36 ( V_5 -> V_43 , V_92 ) ;
if ( V_27 > 0 )
F_40 ( V_27 ) ;
}
F_41 ( V_5 -> V_43 ) ;
}
static int F_42 ( struct V_1 * V_5 )
{
struct V_94 * V_13 = V_5 -> V_13 ;
struct V_95 * V_96 = V_13 -> V_97 ;
struct V_95 * V_98 ;
V_98 = F_43 ( V_96 , NULL ) ;
if ( ! V_98 ) {
F_15 ( V_13 , L_21 ) ;
return F_44 ( V_98 ) ;
}
V_5 -> V_43 = F_45 ( V_98 , 4 ,
& V_99 ,
V_5 ) ;
if ( ! V_5 -> V_43 ) {
F_15 ( V_13 , L_22 ) ;
return F_44 ( V_5 -> V_43 ) ;
}
if ( F_37 ( V_82 ) ) {
V_5 -> V_43 = F_45 ( V_96 ,
V_32 ,
& V_100 ,
& V_101 ) ;
if ( ! V_5 -> V_43 ) {
F_15 ( V_13 , L_23 ) ;
return F_44 ( V_5 -> V_43 ) ;
}
F_29 ( V_5 ) ;
}
return 0 ;
}
static void F_46 ( struct V_1 * V_5 )
{
if ( F_6 ( V_5 ) )
F_34 ( V_5 -> V_13 , L_24 ) ;
else
F_34 ( V_5 -> V_13 , L_25 ) ;
F_4 ( V_5 , ~ V_102 ,
V_61 ) ;
F_4 ( V_5 , F_2 ( V_5 , V_60 ) &
V_103 ,
V_60 ) ;
F_4 ( V_5 , V_103 , V_61 ) ;
F_4 ( V_5 , F_2 ( V_5 , V_104 ) |
V_105 ,
V_104 ) ;
}
static int F_47 ( int V_106 , struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_48 ( & V_5 -> V_107 , & V_3 -> V_107 ) ;
return 1 ;
}
static struct V_16 * F_49 ( int V_106 , struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_16 * V_17 ;
V_5 -> V_21 = V_3 -> V_108 ;
if ( F_37 ( V_82 ) )
V_17 = F_50 ( V_5 -> V_13 , V_3 -> V_108 ,
& V_109 , V_3 ,
& V_3 -> V_107 ,
& V_101 ) ;
else
V_17 = F_51 ( V_5 -> V_13 , V_3 -> V_108 ,
& V_109 , V_3 , & V_3 -> V_107 ) ;
return V_17 ;
}
static int F_52 ( struct V_1 * V_5 )
{
struct V_94 * V_13 = V_5 -> V_13 ;
struct V_95 * V_96 = V_13 -> V_97 ;
struct V_110 * V_111 ;
T_6 V_112 ;
struct V_113 V_114 ;
struct V_115 V_116 ;
struct V_117 * V_118 ;
int V_119 = 0 , V_120 = 0 ;
if ( F_53 ( & V_114 , V_96 ) ) {
F_15 ( V_13 , L_26 ) ;
return - V_44 ;
}
F_54 (&parser, &range) {
if ( V_120 >= V_121 ) {
F_15 ( V_13 , L_27 ) ;
return - V_44 ;
}
V_111 = F_55 ( V_13 , sizeof( * V_111 ) , V_53 ) ;
if ( ! V_111 ) {
V_119 = - V_122 ;
goto V_123;
}
F_56 ( & V_116 , V_96 , V_111 ) ;
switch ( V_111 -> V_124 & V_125 ) {
case V_126 :
V_112 = V_116 . V_127 - V_116 . V_128 ;
V_120 ++ ;
break;
default:
V_119 = - V_44 ;
break;
}
if ( V_119 < 0 ) {
F_33 ( V_13 , L_28 , V_111 ) ;
continue;
}
V_119 = F_57 ( & V_129 , V_111 ) ;
if ( V_119 )
goto V_123;
F_58 ( & V_5 -> V_107 , V_111 , V_112 ) ;
}
if ( F_59 ( V_96 , & V_5 -> V_130 ) ) {
T_1 V_8 = F_2 ( V_5 , V_131 ) ;
T_7 V_132 ;
V_132 = ( V_8 & V_133 ) >>
V_134 ;
V_5 -> V_130 = (struct V_110 ) {
. V_135 = V_96 -> V_135 ,
. V_136 = 0 ,
. V_137 = V_132 ,
. V_124 = V_138 ,
} ;
}
F_60 ( & V_5 -> V_107 , & V_5 -> V_130 ) ;
return 0 ;
V_123:
F_61 ( & V_129 ) ;
F_62 (win, &port->resources)
F_63 ( V_13 , V_118 -> V_139 ) ;
F_64 ( & V_5 -> V_107 ) ;
return V_119 ;
}
static int F_65 ( struct V_1 * V_5 )
{
struct V_94 * V_13 = V_5 -> V_13 ;
struct V_95 * V_96 = V_13 -> V_97 ;
struct V_110 V_140 ;
const char * type ;
int V_119 ;
type = F_66 ( V_96 , L_29 , NULL ) ;
if ( ! type || strcmp ( type , L_30 ) ) {
F_15 ( V_13 , L_31 , type ) ;
return - V_44 ;
}
V_119 = F_67 ( V_96 , 0 , & V_140 ) ;
if ( V_119 ) {
F_15 ( V_13 , L_32 ) ;
return V_119 ;
}
V_5 -> V_7 = F_68 ( V_13 , & V_140 ) ;
if ( F_69 ( V_5 -> V_7 ) )
return F_44 ( V_5 -> V_7 ) ;
V_5 -> V_27 = F_70 ( V_96 , 0 ) ;
V_119 = F_71 ( V_13 , V_5 -> V_27 , F_32 ,
V_141 | V_142 ,
L_33 , V_5 ) ;
if ( V_119 ) {
F_15 ( V_13 , L_34 , V_5 -> V_27 ) ;
return V_119 ;
}
return 0 ;
}
static int F_72 ( struct V_143 * V_37 )
{
struct V_1 * V_5 ;
struct V_144 V_145 ;
struct V_94 * V_13 = & V_37 -> V_13 ;
int V_119 ;
if ( ! V_13 -> V_97 )
return - V_146 ;
V_5 = F_73 ( V_13 , sizeof( * V_5 ) , V_53 ) ;
if ( ! V_5 )
return - V_122 ;
V_5 -> V_13 = V_13 ;
V_119 = F_65 ( V_5 ) ;
if ( V_119 ) {
F_15 ( V_13 , L_35 ) ;
return V_119 ;
}
F_46 ( V_5 ) ;
V_119 = F_42 ( V_5 ) ;
if ( V_119 ) {
F_15 ( V_13 , L_36 ) ;
return V_119 ;
}
F_74 ( & V_5 -> V_107 ) ;
V_119 = F_52 ( V_5 ) ;
if ( V_119 ) {
F_15 ( V_13 , L_37 ) ;
return V_119 ;
}
F_75 ( V_37 , V_5 ) ;
memset ( & V_145 , 0 , sizeof( V_145 ) ) ;
V_145 = (struct V_144 ) {
. V_147 = 1 ,
. V_4 = ( void * * ) & V_5 ,
. V_148 = F_47 ,
. V_149 = V_150 ,
. V_151 = F_49 ,
. V_152 = & V_109 ,
} ;
#ifdef V_82
V_101 . V_13 = V_5 -> V_13 ;
#endif
F_76 ( V_13 , & V_145 ) ;
return 0 ;
}
static int F_77 ( struct V_143 * V_37 )
{
struct V_1 * V_5 = F_78 ( V_37 ) ;
F_38 ( V_5 ) ;
return 0 ;
}
