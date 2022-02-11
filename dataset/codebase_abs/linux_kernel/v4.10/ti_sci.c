static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_2 ( V_5 -> V_7 , V_5 -> V_8 ,
V_5 -> V_9 ) ;
F_3 ( V_2 , V_5 -> V_7 ) ;
return 0 ;
}
static int F_4 ( struct V_10 * V_10 , struct V_11 * V_11 )
{
return F_5 ( V_11 , F_1 , V_10 -> V_12 ) ;
}
static int F_6 ( struct V_13 * V_14 ,
struct V_4 * V_5 )
{
struct V_15 * V_16 = & V_14 -> V_16 ;
struct V_17 * V_18 ;
char V_19 [ 50 ] = L_1 ;
V_18 = F_7 ( V_14 , V_20 ,
L_2 ) ;
V_5 -> V_8 = F_8 ( V_16 , V_18 ) ;
if ( F_9 ( V_5 -> V_8 ) )
return 0 ;
V_5 -> V_9 = F_10 ( V_18 ) ;
V_5 -> V_7 = F_11 ( V_16 , V_5 -> V_9 + 1 ,
sizeof( char ) , V_21 ) ;
if ( ! V_5 -> V_7 )
return - V_22 ;
V_5 -> V_7 [ V_5 -> V_9 ] = 0 ;
V_5 -> V_23 = F_12 ( strncat ( V_19 , F_13 ( V_16 ) ,
sizeof( V_19 ) ) ,
0444 , NULL , V_5 , & V_24 ) ;
if ( F_9 ( V_5 -> V_23 ) )
return F_14 ( V_5 -> V_23 ) ;
F_15 ( V_16 , L_3 ,
V_5 -> V_8 , V_5 -> V_9 , V_18 ) ;
return 0 ;
}
static void F_16 ( struct V_13 * V_14 ,
struct V_4 * V_5 )
{
if ( F_9 ( V_5 -> V_8 ) )
return;
F_17 ( V_5 -> V_23 ) ;
}
static inline int F_6 ( struct V_13 * V_16 ,
struct V_4 * V_5 )
{
return 0 ;
}
static inline void F_16 ( struct V_13 * V_16 ,
struct V_4 * V_5 )
{
}
static inline void F_18 ( struct V_15 * V_16 ,
struct V_25 * V_26 )
{
F_15 ( V_16 , L_4 ,
V_26 -> type , V_26 -> V_27 , V_26 -> V_28 , V_26 -> V_29 ) ;
}
static void F_19 ( struct V_30 * V_31 , void * V_32 )
{
struct V_4 * V_5 = F_20 ( V_31 ) ;
struct V_15 * V_16 = V_5 -> V_16 ;
struct V_33 * V_34 = & V_5 -> V_34 ;
struct V_35 * V_36 = V_32 ;
struct V_25 * V_26 = (struct V_25 * ) V_36 -> V_37 ;
struct V_38 * V_39 ;
T_1 V_40 ;
V_40 = V_26 -> V_28 ;
if ( ! F_21 ( V_40 , V_34 -> V_41 ) ) {
F_22 ( V_16 , L_5 , V_40 ) ;
return;
}
V_39 = & V_34 -> V_42 [ V_40 ] ;
if ( V_36 -> V_43 > V_5 -> V_44 -> V_45 ) {
F_22 ( V_16 , L_6 ,
V_36 -> V_43 , V_5 -> V_44 -> V_45 ) ;
F_18 ( V_16 , V_26 ) ;
return;
}
if ( V_36 -> V_43 < V_39 -> V_46 ) {
F_22 ( V_16 , L_7 ,
V_36 -> V_43 , V_39 -> V_46 ) ;
F_18 ( V_16 , V_26 ) ;
return;
}
F_18 ( V_16 , V_26 ) ;
memcpy ( V_39 -> V_47 , V_36 -> V_37 , V_39 -> V_46 ) ;
F_23 ( & V_39 -> V_48 ) ;
}
static struct V_38 * F_24 ( struct V_4 * V_5 ,
T_2 V_49 , T_3 V_50 ,
T_4 V_51 ,
T_4 V_52 )
{
struct V_33 * V_34 = & V_5 -> V_34 ;
struct V_38 * V_39 ;
struct V_25 * V_26 ;
unsigned long V_29 ;
unsigned long V_53 ;
T_1 V_40 ;
int V_54 ;
int V_55 ;
if ( V_52 > V_5 -> V_44 -> V_45 ||
V_51 > V_5 -> V_44 -> V_45 ||
V_52 < sizeof( * V_26 ) || V_51 < sizeof( * V_26 ) )
return F_25 ( - V_56 ) ;
V_55 = F_26 ( V_5 -> V_44 -> V_57 ) * 5 ;
V_54 = F_27 ( & V_34 -> V_58 , V_55 ) ;
if ( V_54 < 0 )
return F_25 ( V_54 ) ;
F_28 ( & V_34 -> V_59 , V_29 ) ;
V_53 = F_29 ( V_34 -> V_41 ,
V_5 -> V_44 -> V_60 ) ;
F_30 ( V_53 , V_34 -> V_41 ) ;
F_31 ( & V_34 -> V_59 , V_29 ) ;
V_40 = ( T_1 ) V_53 ;
V_39 = & V_34 -> V_42 [ V_40 ] ;
V_26 = (struct V_25 * ) V_39 -> V_61 . V_37 ;
V_39 -> V_61 . V_43 = V_51 ;
V_39 -> V_46 = ( T_1 ) V_52 ;
F_32 ( & V_39 -> V_48 ) ;
V_26 -> V_28 = V_40 ;
V_26 -> type = V_49 ;
V_26 -> V_27 = V_5 -> V_44 -> V_62 ;
V_26 -> V_29 = V_50 ;
return V_39 ;
}
static void F_33 ( struct V_33 * V_34 ,
struct V_38 * V_39 )
{
unsigned long V_29 ;
struct V_25 * V_26 ;
T_1 V_40 ;
V_26 = (struct V_25 * ) V_39 -> V_61 . V_37 ;
V_40 = V_26 -> V_28 ;
F_28 ( & V_34 -> V_59 , V_29 ) ;
F_34 ( V_40 , V_34 -> V_41 ) ;
F_31 ( & V_34 -> V_59 , V_29 ) ;
F_35 ( & V_34 -> V_58 ) ;
}
static inline int F_36 ( struct V_4 * V_5 ,
struct V_38 * V_39 )
{
int V_54 ;
int V_55 ;
struct V_15 * V_16 = V_5 -> V_16 ;
V_54 = F_37 ( V_5 -> V_63 , & V_39 -> V_61 ) ;
if ( V_54 < 0 )
return V_54 ;
V_54 = 0 ;
V_55 = F_26 ( V_5 -> V_44 -> V_57 ) ;
if ( ! F_38 ( & V_39 -> V_48 , V_55 ) ) {
F_22 ( V_16 , L_8 ,
( void * ) V_64 ) ;
V_54 = - V_65 ;
}
F_39 ( V_5 -> V_63 , V_54 ) ;
return V_54 ;
}
static int F_40 ( struct V_4 * V_5 )
{
struct V_15 * V_16 = V_5 -> V_16 ;
struct V_66 * V_67 = & V_5 -> V_67 ;
struct V_68 * V_69 = & V_67 -> V_70 ;
struct V_71 * V_72 ;
struct V_38 * V_39 ;
int V_54 ;
V_39 = F_24 ( V_5 , V_73 ,
0x0 , sizeof( struct V_25 ) ,
sizeof( * V_72 ) ) ;
if ( F_9 ( V_39 ) ) {
V_54 = F_14 ( V_39 ) ;
F_22 ( V_16 , L_9 , V_54 ) ;
return V_54 ;
}
V_72 = (struct V_71 * ) V_39 -> V_47 ;
V_54 = F_36 ( V_5 , V_39 ) ;
if ( V_54 ) {
F_22 ( V_16 , L_10 , V_54 ) ;
goto V_74;
}
V_69 -> V_75 = V_72 -> V_75 ;
V_69 -> V_76 = V_72 -> V_76 ;
V_69 -> V_77 = V_72 -> V_77 ;
strncpy ( V_69 -> V_78 , V_72 -> V_78 ,
sizeof( V_69 -> V_78 ) ) ;
V_74:
F_33 ( & V_5 -> V_34 , V_39 ) ;
return V_54 ;
}
static inline bool F_41 ( void * V_79 )
{
struct V_25 * V_26 = V_79 ;
return V_26 -> V_29 & V_80 ? true : false ;
}
static int F_42 ( const struct V_66 * V_67 ,
T_3 V_81 , T_3 V_29 , T_1 V_82 )
{
struct V_4 * V_5 ;
struct V_83 * V_84 ;
struct V_25 * V_85 ;
struct V_38 * V_39 ;
struct V_15 * V_16 ;
int V_54 = 0 ;
if ( F_9 ( V_67 ) )
return F_14 ( V_67 ) ;
if ( ! V_67 )
return - V_86 ;
V_5 = F_43 ( V_67 ) ;
V_16 = V_5 -> V_16 ;
V_39 = F_24 ( V_5 , V_87 ,
V_29 | V_88 ,
sizeof( * V_84 ) , sizeof( * V_85 ) ) ;
if ( F_9 ( V_39 ) ) {
V_54 = F_14 ( V_39 ) ;
F_22 ( V_16 , L_9 , V_54 ) ;
return V_54 ;
}
V_84 = (struct V_83 * ) V_39 -> V_47 ;
V_84 -> V_81 = V_81 ;
V_84 -> V_82 = V_82 ;
V_54 = F_36 ( V_5 , V_39 ) ;
if ( V_54 ) {
F_22 ( V_16 , L_10 , V_54 ) ;
goto V_74;
}
V_85 = (struct V_25 * ) V_39 -> V_47 ;
V_54 = F_41 ( V_85 ) ? 0 : - V_89 ;
V_74:
F_33 ( & V_5 -> V_34 , V_39 ) ;
return V_54 ;
}
static int F_44 ( const struct V_66 * V_67 ,
T_3 V_81 , T_3 * V_90 , T_3 * V_91 ,
T_1 * V_92 , T_1 * V_93 )
{
struct V_4 * V_5 ;
struct V_94 * V_84 ;
struct V_95 * V_85 ;
struct V_38 * V_39 ;
struct V_15 * V_16 ;
int V_54 = 0 ;
if ( F_9 ( V_67 ) )
return F_14 ( V_67 ) ;
if ( ! V_67 )
return - V_86 ;
if ( ! V_90 && ! V_91 && ! V_92 && ! V_93 )
return - V_86 ;
V_5 = F_43 ( V_67 ) ;
V_16 = V_5 -> V_16 ;
V_39 = F_24 ( V_5 , V_96 ,
0 , sizeof( * V_84 ) , sizeof( * V_85 ) ) ;
if ( F_9 ( V_39 ) ) {
V_54 = F_14 ( V_39 ) ;
F_22 ( V_16 , L_9 , V_54 ) ;
return V_54 ;
}
V_84 = (struct V_94 * ) V_39 -> V_47 ;
V_84 -> V_81 = V_81 ;
V_54 = F_36 ( V_5 , V_39 ) ;
if ( V_54 ) {
F_22 ( V_16 , L_10 , V_54 ) ;
goto V_74;
}
V_85 = (struct V_95 * ) V_39 -> V_47 ;
if ( ! F_41 ( V_85 ) ) {
V_54 = - V_89 ;
goto V_74;
}
if ( V_90 )
* V_90 = V_85 -> V_97 ;
if ( V_91 )
* V_91 = V_85 -> V_91 ;
if ( V_92 )
* V_92 = V_85 -> V_98 ;
if ( V_93 )
* V_93 = V_85 -> V_99 ;
V_74:
F_33 ( & V_5 -> V_34 , V_39 ) ;
return V_54 ;
}
static int F_45 ( const struct V_66 * V_67 , T_3 V_81 )
{
return F_42 ( V_67 , V_81 ,
V_100 ,
V_101 ) ;
}
static int F_46 ( const struct V_66 * V_67 , T_3 V_81 )
{
return F_42 ( V_67 , V_81 ,
V_100 ,
V_102 ) ;
}
static int F_47 ( const struct V_66 * V_67 , T_3 V_81 )
{
return F_42 ( V_67 , V_81 ,
0 , V_103 ) ;
}
static int F_48 ( const struct V_66 * V_67 , T_3 V_81 )
{
T_1 V_3 ;
return F_44 ( V_67 , V_81 , NULL , NULL , NULL , & V_3 ) ;
}
static int F_49 ( const struct V_66 * V_67 , T_3 V_81 ,
T_3 * V_104 )
{
return F_44 ( V_67 , V_81 , V_104 , NULL , NULL , NULL ) ;
}
static int F_50 ( const struct V_66 * V_67 , T_3 V_81 ,
bool * V_105 )
{
int V_54 ;
T_1 V_82 ;
if ( ! V_105 )
return - V_86 ;
V_54 = F_44 ( V_67 , V_81 , NULL , NULL , & V_82 , NULL ) ;
if ( V_54 )
return V_54 ;
* V_105 = ( V_82 == V_102 ) ;
return 0 ;
}
static int F_51 ( const struct V_66 * V_67 , T_3 V_81 ,
bool * V_105 , bool * V_106 )
{
int V_54 ;
T_1 V_92 , V_93 ;
if ( ! V_105 && ! V_106 )
return - V_86 ;
V_54 =
F_44 ( V_67 , V_81 , NULL , NULL , & V_92 , & V_93 ) ;
if ( V_54 )
return V_54 ;
if ( V_105 )
* V_105 = ( V_92 == V_103 ) ;
if ( V_106 )
* V_106 = ( V_93 == V_107 ) ;
return 0 ;
}
static int F_52 ( const struct V_66 * V_67 , T_3 V_81 ,
bool * V_105 , bool * V_106 )
{
int V_54 ;
T_1 V_92 , V_93 ;
if ( ! V_105 && ! V_106 )
return - V_86 ;
V_54 =
F_44 ( V_67 , V_81 , NULL , NULL , & V_92 , & V_93 ) ;
if ( V_54 )
return V_54 ;
if ( V_105 )
* V_105 = ( V_92 == V_101 ) ;
if ( V_106 )
* V_106 = ( V_93 == V_108 ) ;
return 0 ;
}
static int F_53 ( const struct V_66 * V_67 , T_3 V_81 ,
bool * V_106 )
{
int V_54 ;
T_1 V_82 ;
if ( ! V_106 )
return - V_86 ;
V_54 = F_44 ( V_67 , V_81 , NULL , NULL , NULL , & V_82 ) ;
if ( V_54 )
return V_54 ;
* V_106 = ( V_82 == V_109 ) ;
return 0 ;
}
static int F_54 ( const struct V_66 * V_67 ,
T_3 V_81 , T_3 V_110 )
{
struct V_4 * V_5 ;
struct V_111 * V_84 ;
struct V_25 * V_85 ;
struct V_38 * V_39 ;
struct V_15 * V_16 ;
int V_54 = 0 ;
if ( F_9 ( V_67 ) )
return F_14 ( V_67 ) ;
if ( ! V_67 )
return - V_86 ;
V_5 = F_43 ( V_67 ) ;
V_16 = V_5 -> V_16 ;
V_39 = F_24 ( V_5 , V_112 ,
V_88 ,
sizeof( * V_84 ) , sizeof( * V_85 ) ) ;
if ( F_9 ( V_39 ) ) {
V_54 = F_14 ( V_39 ) ;
F_22 ( V_16 , L_9 , V_54 ) ;
return V_54 ;
}
V_84 = (struct V_111 * ) V_39 -> V_47 ;
V_84 -> V_81 = V_81 ;
V_84 -> V_91 = V_110 ;
V_54 = F_36 ( V_5 , V_39 ) ;
if ( V_54 ) {
F_22 ( V_16 , L_10 , V_54 ) ;
goto V_74;
}
V_85 = (struct V_25 * ) V_39 -> V_47 ;
V_54 = F_41 ( V_85 ) ? 0 : - V_89 ;
V_74:
F_33 ( & V_5 -> V_34 , V_39 ) ;
return V_54 ;
}
static int F_55 ( const struct V_66 * V_67 ,
T_3 V_81 , T_3 * V_110 )
{
return F_44 ( V_67 , V_81 , NULL , V_110 , NULL ,
NULL ) ;
}
static int F_56 ( const struct V_66 * V_67 ,
T_3 V_113 , T_1 V_114 ,
T_3 V_29 , T_1 V_82 )
{
struct V_4 * V_5 ;
struct V_115 * V_84 ;
struct V_25 * V_85 ;
struct V_38 * V_39 ;
struct V_15 * V_16 ;
int V_54 = 0 ;
if ( F_9 ( V_67 ) )
return F_14 ( V_67 ) ;
if ( ! V_67 )
return - V_86 ;
V_5 = F_43 ( V_67 ) ;
V_16 = V_5 -> V_16 ;
V_39 = F_24 ( V_5 , V_116 ,
V_29 | V_88 ,
sizeof( * V_84 ) , sizeof( * V_85 ) ) ;
if ( F_9 ( V_39 ) ) {
V_54 = F_14 ( V_39 ) ;
F_22 ( V_16 , L_9 , V_54 ) ;
return V_54 ;
}
V_84 = (struct V_115 * ) V_39 -> V_47 ;
V_84 -> V_113 = V_113 ;
V_84 -> V_114 = V_114 ;
V_84 -> V_117 = V_82 ;
V_54 = F_36 ( V_5 , V_39 ) ;
if ( V_54 ) {
F_22 ( V_16 , L_10 , V_54 ) ;
goto V_74;
}
V_85 = (struct V_25 * ) V_39 -> V_47 ;
V_54 = F_41 ( V_85 ) ? 0 : - V_89 ;
V_74:
F_33 ( & V_5 -> V_34 , V_39 ) ;
return V_54 ;
}
static int F_57 ( const struct V_66 * V_67 ,
T_3 V_113 , T_1 V_114 ,
T_1 * V_98 , T_1 * V_99 )
{
struct V_4 * V_5 ;
struct V_118 * V_84 ;
struct V_119 * V_85 ;
struct V_38 * V_39 ;
struct V_15 * V_16 ;
int V_54 = 0 ;
if ( F_9 ( V_67 ) )
return F_14 ( V_67 ) ;
if ( ! V_67 )
return - V_86 ;
if ( ! V_98 && ! V_99 )
return - V_86 ;
V_5 = F_43 ( V_67 ) ;
V_16 = V_5 -> V_16 ;
V_39 = F_24 ( V_5 , V_120 ,
V_88 ,
sizeof( * V_84 ) , sizeof( * V_85 ) ) ;
if ( F_9 ( V_39 ) ) {
V_54 = F_14 ( V_39 ) ;
F_22 ( V_16 , L_9 , V_54 ) ;
return V_54 ;
}
V_84 = (struct V_118 * ) V_39 -> V_47 ;
V_84 -> V_113 = V_113 ;
V_84 -> V_114 = V_114 ;
V_54 = F_36 ( V_5 , V_39 ) ;
if ( V_54 ) {
F_22 ( V_16 , L_10 , V_54 ) ;
goto V_74;
}
V_85 = (struct V_119 * ) V_39 -> V_47 ;
if ( ! F_41 ( V_85 ) ) {
V_54 = - V_89 ;
goto V_74;
}
if ( V_98 )
* V_98 = V_85 -> V_98 ;
if ( V_99 )
* V_99 = V_85 -> V_99 ;
V_74:
F_33 ( & V_5 -> V_34 , V_39 ) ;
return V_54 ;
}
static int F_58 ( const struct V_66 * V_67 , T_3 V_113 ,
T_1 V_114 , bool V_121 , bool V_122 ,
bool V_123 )
{
T_3 V_29 = 0 ;
V_29 |= V_121 ? V_124 : 0 ;
V_29 |= V_122 ? V_125 : 0 ;
V_29 |= V_123 ? V_126 : 0 ;
return F_56 ( V_67 , V_113 , V_114 , V_29 ,
V_127 ) ;
}
static int F_59 ( const struct V_66 * V_67 ,
T_3 V_113 , T_1 V_114 )
{
return F_56 ( V_67 , V_113 , V_114 , 0 ,
V_128 ) ;
}
static int F_60 ( const struct V_66 * V_67 ,
T_3 V_113 , T_1 V_114 )
{
return F_56 ( V_67 , V_113 , V_114 , 0 ,
V_129 ) ;
}
static int F_61 ( const struct V_66 * V_67 ,
T_3 V_113 , T_1 V_114 , bool * V_130 )
{
T_1 V_82 = 0 ;
int V_54 ;
if ( ! V_130 )
return - V_86 ;
V_54 = F_57 ( V_67 , V_113 , V_114 , & V_82 , NULL ) ;
if ( V_54 )
return V_54 ;
* V_130 = ( V_82 == V_129 ) ;
return 0 ;
}
static int F_62 ( const struct V_66 * V_67 , T_3 V_113 ,
T_1 V_114 , bool * V_130 , bool * V_106 )
{
T_1 V_93 = 0 , V_105 = 0 ;
int V_54 ;
if ( ! V_130 && ! V_106 )
return - V_86 ;
V_54 = F_57 ( V_67 , V_113 , V_114 ,
& V_105 , & V_93 ) ;
if ( V_54 )
return V_54 ;
if ( V_130 )
* V_130 = ( V_105 == V_127 ) ;
if ( V_106 )
* V_106 = ( V_93 == V_131 ) ;
return 0 ;
}
static int F_63 ( const struct V_66 * V_67 , T_3 V_113 ,
T_1 V_114 , bool * V_130 , bool * V_106 )
{
T_1 V_93 = 0 , V_105 = 0 ;
int V_54 ;
if ( ! V_130 && ! V_106 )
return - V_86 ;
V_54 = F_57 ( V_67 , V_113 , V_114 ,
& V_105 , & V_93 ) ;
if ( V_54 )
return V_54 ;
if ( V_130 )
* V_130 = ( V_105 == V_128 ) ;
if ( V_106 )
* V_106 = ( V_93 == V_132 ) ;
return 0 ;
}
static int F_64 ( const struct V_66 * V_67 ,
T_3 V_113 , T_1 V_114 , T_1 V_133 )
{
struct V_4 * V_5 ;
struct V_134 * V_84 ;
struct V_25 * V_85 ;
struct V_38 * V_39 ;
struct V_15 * V_16 ;
int V_54 = 0 ;
if ( F_9 ( V_67 ) )
return F_14 ( V_67 ) ;
if ( ! V_67 )
return - V_86 ;
V_5 = F_43 ( V_67 ) ;
V_16 = V_5 -> V_16 ;
V_39 = F_24 ( V_5 , V_135 ,
V_88 ,
sizeof( * V_84 ) , sizeof( * V_85 ) ) ;
if ( F_9 ( V_39 ) ) {
V_54 = F_14 ( V_39 ) ;
F_22 ( V_16 , L_9 , V_54 ) ;
return V_54 ;
}
V_84 = (struct V_134 * ) V_39 -> V_47 ;
V_84 -> V_113 = V_113 ;
V_84 -> V_114 = V_114 ;
V_84 -> V_133 = V_133 ;
V_54 = F_36 ( V_5 , V_39 ) ;
if ( V_54 ) {
F_22 ( V_16 , L_10 , V_54 ) ;
goto V_74;
}
V_85 = (struct V_25 * ) V_39 -> V_47 ;
V_54 = F_41 ( V_85 ) ? 0 : - V_89 ;
V_74:
F_33 ( & V_5 -> V_34 , V_39 ) ;
return V_54 ;
}
static int F_65 ( const struct V_66 * V_67 ,
T_3 V_113 , T_1 V_114 , T_1 * V_133 )
{
struct V_4 * V_5 ;
struct V_136 * V_84 ;
struct V_137 * V_85 ;
struct V_38 * V_39 ;
struct V_15 * V_16 ;
int V_54 = 0 ;
if ( F_9 ( V_67 ) )
return F_14 ( V_67 ) ;
if ( ! V_67 || ! V_133 )
return - V_86 ;
V_5 = F_43 ( V_67 ) ;
V_16 = V_5 -> V_16 ;
V_39 = F_24 ( V_5 , V_138 ,
V_88 ,
sizeof( * V_84 ) , sizeof( * V_85 ) ) ;
if ( F_9 ( V_39 ) ) {
V_54 = F_14 ( V_39 ) ;
F_22 ( V_16 , L_9 , V_54 ) ;
return V_54 ;
}
V_84 = (struct V_136 * ) V_39 -> V_47 ;
V_84 -> V_113 = V_113 ;
V_84 -> V_114 = V_114 ;
V_54 = F_36 ( V_5 , V_39 ) ;
if ( V_54 ) {
F_22 ( V_16 , L_10 , V_54 ) ;
goto V_74;
}
V_85 = (struct V_137 * ) V_39 -> V_47 ;
if ( ! F_41 ( V_85 ) )
V_54 = - V_89 ;
else
* V_133 = V_85 -> V_133 ;
V_74:
F_33 ( & V_5 -> V_34 , V_39 ) ;
return V_54 ;
}
static int F_66 ( const struct V_66 * V_67 ,
T_3 V_113 , T_1 V_114 ,
T_1 * V_139 )
{
struct V_4 * V_5 ;
struct V_140 * V_84 ;
struct V_141 * V_85 ;
struct V_38 * V_39 ;
struct V_15 * V_16 ;
int V_54 = 0 ;
if ( F_9 ( V_67 ) )
return F_14 ( V_67 ) ;
if ( ! V_67 || ! V_139 )
return - V_86 ;
V_5 = F_43 ( V_67 ) ;
V_16 = V_5 -> V_16 ;
V_39 = F_24 ( V_5 , V_142 ,
V_88 ,
sizeof( * V_84 ) , sizeof( * V_85 ) ) ;
if ( F_9 ( V_39 ) ) {
V_54 = F_14 ( V_39 ) ;
F_22 ( V_16 , L_9 , V_54 ) ;
return V_54 ;
}
V_84 = (struct V_140 * ) V_39 -> V_47 ;
V_84 -> V_113 = V_113 ;
V_84 -> V_114 = V_114 ;
V_54 = F_36 ( V_5 , V_39 ) ;
if ( V_54 ) {
F_22 ( V_16 , L_10 , V_54 ) ;
goto V_74;
}
V_85 = (struct V_141 * ) V_39 -> V_47 ;
if ( ! F_41 ( V_85 ) )
V_54 = - V_89 ;
else
* V_139 = V_85 -> V_139 ;
V_74:
F_33 ( & V_5 -> V_34 , V_39 ) ;
return V_54 ;
}
static int F_67 ( const struct V_66 * V_67 ,
T_3 V_113 , T_1 V_114 , T_5 V_143 ,
T_5 V_144 , T_5 V_145 ,
T_5 * V_146 )
{
struct V_4 * V_5 ;
struct V_147 * V_84 ;
struct V_148 * V_85 ;
struct V_38 * V_39 ;
struct V_15 * V_16 ;
int V_54 = 0 ;
if ( F_9 ( V_67 ) )
return F_14 ( V_67 ) ;
if ( ! V_67 || ! V_146 )
return - V_86 ;
V_5 = F_43 ( V_67 ) ;
V_16 = V_5 -> V_16 ;
V_39 = F_24 ( V_5 , V_149 ,
V_88 ,
sizeof( * V_84 ) , sizeof( * V_85 ) ) ;
if ( F_9 ( V_39 ) ) {
V_54 = F_14 ( V_39 ) ;
F_22 ( V_16 , L_9 , V_54 ) ;
return V_54 ;
}
V_84 = (struct V_147 * ) V_39 -> V_47 ;
V_84 -> V_113 = V_113 ;
V_84 -> V_114 = V_114 ;
V_84 -> V_150 = V_143 ;
V_84 -> V_151 = V_144 ;
V_84 -> V_152 = V_145 ;
V_54 = F_36 ( V_5 , V_39 ) ;
if ( V_54 ) {
F_22 ( V_16 , L_10 , V_54 ) ;
goto V_74;
}
V_85 = (struct V_148 * ) V_39 -> V_47 ;
if ( ! F_41 ( V_85 ) )
V_54 = - V_89 ;
else
* V_146 = V_85 -> V_153 ;
V_74:
F_33 ( & V_5 -> V_34 , V_39 ) ;
return V_54 ;
}
static int F_68 ( const struct V_66 * V_67 ,
T_3 V_113 , T_1 V_114 , T_5 V_143 ,
T_5 V_144 , T_5 V_145 )
{
struct V_4 * V_5 ;
struct V_154 * V_84 ;
struct V_25 * V_85 ;
struct V_38 * V_39 ;
struct V_15 * V_16 ;
int V_54 = 0 ;
if ( F_9 ( V_67 ) )
return F_14 ( V_67 ) ;
if ( ! V_67 )
return - V_86 ;
V_5 = F_43 ( V_67 ) ;
V_16 = V_5 -> V_16 ;
V_39 = F_24 ( V_5 , V_155 ,
V_88 ,
sizeof( * V_84 ) , sizeof( * V_85 ) ) ;
if ( F_9 ( V_39 ) ) {
V_54 = F_14 ( V_39 ) ;
F_22 ( V_16 , L_9 , V_54 ) ;
return V_54 ;
}
V_84 = (struct V_154 * ) V_39 -> V_47 ;
V_84 -> V_113 = V_113 ;
V_84 -> V_114 = V_114 ;
V_84 -> V_150 = V_143 ;
V_84 -> V_151 = V_144 ;
V_84 -> V_152 = V_145 ;
V_54 = F_36 ( V_5 , V_39 ) ;
if ( V_54 ) {
F_22 ( V_16 , L_10 , V_54 ) ;
goto V_74;
}
V_85 = (struct V_25 * ) V_39 -> V_47 ;
V_54 = F_41 ( V_85 ) ? 0 : - V_89 ;
V_74:
F_33 ( & V_5 -> V_34 , V_39 ) ;
return V_54 ;
}
static int F_69 ( const struct V_66 * V_67 ,
T_3 V_113 , T_1 V_114 , T_5 * V_156 )
{
struct V_4 * V_5 ;
struct V_157 * V_84 ;
struct V_158 * V_85 ;
struct V_38 * V_39 ;
struct V_15 * V_16 ;
int V_54 = 0 ;
if ( F_9 ( V_67 ) )
return F_14 ( V_67 ) ;
if ( ! V_67 || ! V_156 )
return - V_86 ;
V_5 = F_43 ( V_67 ) ;
V_16 = V_5 -> V_16 ;
V_39 = F_24 ( V_5 , V_159 ,
V_88 ,
sizeof( * V_84 ) , sizeof( * V_85 ) ) ;
if ( F_9 ( V_39 ) ) {
V_54 = F_14 ( V_39 ) ;
F_22 ( V_16 , L_9 , V_54 ) ;
return V_54 ;
}
V_84 = (struct V_157 * ) V_39 -> V_47 ;
V_84 -> V_113 = V_113 ;
V_84 -> V_114 = V_114 ;
V_54 = F_36 ( V_5 , V_39 ) ;
if ( V_54 ) {
F_22 ( V_16 , L_10 , V_54 ) ;
goto V_74;
}
V_85 = (struct V_158 * ) V_39 -> V_47 ;
if ( ! F_41 ( V_85 ) )
V_54 = - V_89 ;
else
* V_156 = V_85 -> V_153 ;
V_74:
F_33 ( & V_5 -> V_34 , V_39 ) ;
return V_54 ;
}
static int F_70 ( const struct V_66 * V_67 )
{
struct V_4 * V_5 ;
struct V_160 * V_84 ;
struct V_25 * V_85 ;
struct V_38 * V_39 ;
struct V_15 * V_16 ;
int V_54 = 0 ;
if ( F_9 ( V_67 ) )
return F_14 ( V_67 ) ;
if ( ! V_67 )
return - V_86 ;
V_5 = F_43 ( V_67 ) ;
V_16 = V_5 -> V_16 ;
V_39 = F_24 ( V_5 , V_161 ,
V_88 ,
sizeof( * V_84 ) , sizeof( * V_85 ) ) ;
if ( F_9 ( V_39 ) ) {
V_54 = F_14 ( V_39 ) ;
F_22 ( V_16 , L_9 , V_54 ) ;
return V_54 ;
}
V_84 = (struct V_160 * ) V_39 -> V_47 ;
V_54 = F_36 ( V_5 , V_39 ) ;
if ( V_54 ) {
F_22 ( V_16 , L_10 , V_54 ) ;
goto V_74;
}
V_85 = (struct V_25 * ) V_39 -> V_47 ;
if ( ! F_41 ( V_85 ) )
V_54 = - V_89 ;
else
V_54 = 0 ;
V_74:
F_33 ( & V_5 -> V_34 , V_39 ) ;
return V_54 ;
}
static void F_71 ( struct V_4 * V_5 )
{
struct V_162 * V_163 = & V_5 -> V_67 . V_163 ;
struct V_164 * V_165 = & V_163 -> V_165 ;
struct V_166 * V_167 = & V_163 -> V_168 ;
struct V_169 * V_170 = & V_163 -> V_171 ;
V_165 -> V_172 = F_70 ;
V_167 -> V_173 = F_45 ;
V_167 -> V_174 = F_46 ;
V_167 -> V_175 = F_47 ;
V_167 -> V_176 = F_48 ;
V_167 -> V_177 = F_49 ;
V_167 -> V_178 = F_50 ;
V_167 -> V_179 = F_51 ;
V_167 -> V_180 = F_52 ;
V_167 -> V_181 = F_53 ;
V_167 -> V_182 = F_54 ;
V_167 -> V_183 = F_55 ;
V_170 -> V_184 = F_58 ;
V_170 -> V_185 = F_59 ;
V_170 -> V_186 = F_60 ;
V_170 -> V_187 = F_61 ;
V_170 -> V_180 = F_62 ;
V_170 -> V_188 = F_63 ;
V_170 -> V_189 = F_64 ;
V_170 -> V_190 = F_65 ;
V_170 -> V_191 = F_66 ;
V_170 -> V_192 = F_67 ;
V_170 -> V_193 = F_68 ;
V_170 -> V_194 = F_69 ;
}
const struct V_66 * F_72 ( struct V_15 * V_16 )
{
struct V_195 * V_196 ;
struct V_197 * V_198 ;
struct V_66 * V_67 = NULL ;
struct V_4 * V_5 ;
if ( ! V_16 ) {
F_73 ( L_11 ) ;
return F_25 ( - V_86 ) ;
}
V_196 = F_74 ( V_16 -> V_199 ) ;
if ( ! V_196 ) {
F_22 ( V_16 , L_12 ) ;
return F_25 ( - V_86 ) ;
}
F_75 ( & V_200 ) ;
F_76 (p, &ti_sci_list) {
V_5 = F_77 ( V_198 , struct V_4 , V_201 ) ;
if ( V_196 == V_5 -> V_16 -> V_199 ) {
V_67 = & V_5 -> V_67 ;
V_5 -> V_202 ++ ;
break;
}
}
F_78 ( & V_200 ) ;
F_79 ( V_196 ) ;
if ( ! V_67 )
return F_25 ( - V_203 ) ;
return V_67 ;
}
int F_80 ( const struct V_66 * V_67 )
{
struct V_4 * V_5 ;
if ( F_9 ( V_67 ) )
return F_14 ( V_67 ) ;
if ( ! V_67 )
return - V_86 ;
V_5 = F_43 ( V_67 ) ;
F_75 ( & V_200 ) ;
if ( ! F_81 ( ! V_5 -> V_202 ) )
V_5 -> V_202 -- ;
F_78 ( & V_200 ) ;
return 0 ;
}
static void F_82 ( struct V_15 * V_16 , void * V_18 )
{
const struct V_66 * * V_204 = V_18 ;
const struct V_66 * V_67 = * V_204 ;
int V_54 ;
V_54 = F_80 ( V_67 ) ;
if ( V_54 )
F_22 ( V_16 , L_13 , V_54 ) ;
}
const struct V_66 * F_83 ( struct V_15 * V_16 )
{
const struct V_66 * * V_204 ;
const struct V_66 * V_67 ;
V_204 = F_84 ( F_82 , sizeof( * V_204 ) , V_21 ) ;
if ( ! V_204 )
return F_25 ( - V_22 ) ;
V_67 = F_72 ( V_16 ) ;
if ( ! F_9 ( V_67 ) ) {
* V_204 = V_67 ;
F_85 ( V_16 , V_204 ) ;
} else {
F_86 ( V_204 ) ;
}
return V_67 ;
}
static int F_87 ( struct V_205 * V_206 , unsigned long V_207 ,
void * V_208 )
{
struct V_4 * V_5 = F_88 ( V_206 ) ;
const struct V_66 * V_67 = & V_5 -> V_67 ;
F_70 ( V_67 ) ;
return V_209 ;
}
static int F_89 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = & V_14 -> V_16 ;
const struct V_210 * V_211 ;
const struct V_212 * V_44 ;
struct V_38 * V_39 ;
struct V_4 * V_5 = NULL ;
struct V_33 * V_34 ;
struct V_30 * V_31 ;
int V_54 = - V_86 ;
int V_213 ;
int V_214 = 0 ;
V_211 = F_90 ( V_215 , V_16 ) ;
if ( ! V_211 ) {
F_22 ( V_16 , L_14 ) ;
return - V_86 ;
}
V_44 = V_211 -> V_216 ;
V_5 = F_91 ( V_16 , sizeof( * V_5 ) , V_21 ) ;
if ( ! V_5 )
return - V_22 ;
V_5 -> V_16 = V_16 ;
V_5 -> V_44 = V_44 ;
V_214 = F_92 ( V_16 -> V_199 ,
L_15 ) ;
F_93 ( & V_5 -> V_201 ) ;
V_34 = & V_5 -> V_34 ;
if ( F_81 ( V_44 -> V_60 >=
1 << 8 * sizeof( ( (struct V_25 * ) 0 ) -> V_28 ) ) )
return - V_86 ;
V_34 -> V_42 = F_11 ( V_16 ,
V_44 -> V_60 ,
sizeof( * V_34 -> V_42 ) ,
V_21 ) ;
if ( ! V_34 -> V_42 )
return - V_22 ;
V_34 -> V_41 = F_91 ( V_16 ,
F_94 ( V_44 -> V_60 )
* sizeof( unsigned long ) ,
V_21 ) ;
if ( ! V_34 -> V_41 )
return - V_22 ;
F_95 ( V_34 -> V_41 , V_44 -> V_60 ) ;
for ( V_213 = 0 , V_39 = V_34 -> V_42 ; V_213 < V_44 -> V_60 ; V_213 ++ , V_39 ++ ) {
V_39 -> V_47 = F_11 ( V_16 , 1 , V_44 -> V_45 ,
V_21 ) ;
if ( ! V_39 -> V_47 )
return - V_22 ;
V_39 -> V_61 . V_37 = V_39 -> V_47 ;
F_96 ( & V_39 -> V_48 ) ;
}
V_54 = F_6 ( V_14 , V_5 ) ;
if ( V_54 )
F_97 ( V_16 , L_16 ) ;
F_98 ( V_14 , V_5 ) ;
V_31 = & V_5 -> V_31 ;
V_31 -> V_16 = V_16 ;
V_31 -> V_217 = false ;
V_31 -> V_218 = F_19 ;
V_31 -> V_219 = true ;
F_99 ( & V_34 -> V_59 ) ;
F_100 ( & V_34 -> V_58 , V_44 -> V_60 ) ;
V_5 -> V_220 = F_101 ( V_31 , L_17 ) ;
if ( F_9 ( V_5 -> V_220 ) ) {
V_54 = F_14 ( V_5 -> V_220 ) ;
goto V_221;
}
V_5 -> V_63 = F_101 ( V_31 , L_18 ) ;
if ( F_9 ( V_5 -> V_63 ) ) {
V_54 = F_14 ( V_5 -> V_63 ) ;
goto V_221;
}
V_54 = F_40 ( V_5 ) ;
if ( V_54 ) {
F_22 ( V_16 , L_19 , V_54 ) ;
goto V_221;
}
F_71 ( V_5 ) ;
if ( V_214 ) {
V_5 -> V_206 . V_222 = F_87 ;
V_5 -> V_206 . V_223 = 128 ;
V_54 = F_102 ( & V_5 -> V_206 ) ;
if ( V_54 ) {
F_22 ( V_16 , L_20 , V_54 ) ;
return V_54 ;
}
}
F_103 ( V_16 , L_21 ,
V_5 -> V_67 . V_70 . V_75 , V_5 -> V_67 . V_70 . V_76 ,
V_5 -> V_67 . V_70 . V_77 ,
V_5 -> V_67 . V_70 . V_78 ) ;
F_75 ( & V_200 ) ;
F_104 ( & V_5 -> V_201 , & V_224 ) ;
F_78 ( & V_200 ) ;
return F_105 ( V_16 -> V_199 , NULL , NULL , V_16 ) ;
V_221:
if ( ! F_9 ( V_5 -> V_63 ) )
F_106 ( V_5 -> V_63 ) ;
if ( ! F_9 ( V_5 -> V_220 ) )
F_106 ( V_5 -> V_220 ) ;
F_17 ( V_5 -> V_23 ) ;
return V_54 ;
}
static int F_107 ( struct V_13 * V_14 )
{
struct V_4 * V_5 ;
struct V_15 * V_16 = & V_14 -> V_16 ;
int V_54 = 0 ;
F_108 ( V_16 ) ;
V_5 = F_109 ( V_14 ) ;
if ( V_5 -> V_206 . V_222 )
F_110 ( & V_5 -> V_206 ) ;
F_75 ( & V_200 ) ;
if ( V_5 -> V_202 )
V_54 = - V_225 ;
else
F_111 ( & V_5 -> V_201 ) ;
F_78 ( & V_200 ) ;
if ( ! V_54 ) {
F_16 ( V_14 , V_5 ) ;
F_106 ( V_5 -> V_63 ) ;
F_106 ( V_5 -> V_220 ) ;
}
return V_54 ;
}
