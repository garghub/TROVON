static int T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( ( V_4 -> V_5 & V_6 ) ||
( V_4 -> V_5 & V_7 ) )
return 0 ;
F_2 ( V_8 , & V_4 -> V_9 -> V_10 ) ;
return 0 ;
}
static bool F_3 ( T_2 T_3 * V_11 , T_2 V_12 , T_2 V_13 ,
unsigned long V_14 )
{
T_4 V_15 ;
T_4 V_16 ;
V_15 = F_4 () ;
V_16 = F_5 ( V_15 , F_6 ( V_14 ) ) ;
do {
if ( ( F_7 ( V_11 ) & V_12 ) == V_13 )
return true ;
F_8 ( 50 , 100 ) ;
} while ( F_9 ( F_4 () , V_16 ) );
return false ;
}
static int T_1 F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( ( V_4 -> V_5 & V_6 ) ||
( V_4 -> V_5 & V_7 ) )
return 0 ;
F_2 ( V_17 , & V_4 -> V_9 -> V_10 ) ;
if ( ! F_3 ( & V_4 -> V_9 -> V_10 ,
V_17 ,
0 ,
V_18 ) ) {
F_11 ( V_2 , L_1 ) ;
return - V_19 ;
}
return 0 ;
}
static int F_12 ( struct V_20 * V_21 , int V_22 )
{
struct V_3 * V_4 = F_13 ( & V_21 -> V_2 ) ;
T_2 V_13 = V_23 |
V_24 ;
if ( ! V_4 -> V_25 )
return 0 ;
F_2 ( V_26 , & V_4 -> V_25 -> V_27 ) ;
if ( ! F_3 ( & V_4 -> V_25 -> V_28 , V_13 , V_13 ,
V_18 ) ) {
F_11 ( & V_21 -> V_2 , L_2 ) ;
return - V_19 ;
}
return 0 ;
}
static void F_14 ( struct V_20 * V_21 , int V_22 )
{
struct V_3 * V_4 = F_13 ( & V_21 -> V_2 ) ;
if ( ! V_4 -> V_25 )
return;
F_2 ( V_29 , & V_4 -> V_25 -> V_27 ) ;
}
static T_5 F_15 ( struct V_20 * V_21 )
{
struct V_3 * V_4 = F_13 ( & V_21 -> V_2 ) ;
T_5 V_30 = 0 ;
if ( ( F_7 ( & V_4 -> V_9 -> V_31 ) & V_32 ) !=
V_32 )
V_30 |= V_33 ;
return V_30 ;
}
static int F_16 ( struct V_20 * V_21 , T_5 * V_34 , T_6 V_35 )
{
struct V_3 * V_4 = F_13 ( & V_21 -> V_2 ) ;
unsigned int V_36 ;
if ( V_35 < 6 )
return - V_37 ;
if ( F_7 ( & V_4 -> V_9 -> V_38 ) & V_39 )
return - V_37 ;
F_17 ( V_34 , V_4 -> V_40 , 6 ) ;
V_36 = F_18 ( ( V_41 * ) & V_34 [ 2 ] ) ;
if ( V_36 > V_35 || V_36 < 6 )
return - V_37 ;
F_17 ( & V_34 [ 6 ] , & V_4 -> V_40 [ 6 ] , V_36 - 6 ) ;
return V_36 ;
}
static int F_19 ( struct V_20 * V_21 )
{
union V_42 * V_43 ;
int V_44 ;
V_43 = F_20 ( V_21 -> V_45 ,
& V_46 ,
V_47 ,
V_48 ,
NULL ) ;
if ( ! V_43 )
return - V_49 ;
V_44 = V_43 -> integer . V_13 == 0 ? 0 : - V_49 ;
F_21 ( V_43 ) ;
return V_44 ;
}
static int F_22 ( struct V_1 * V_2 , unsigned long V_50 )
{
struct V_51 V_52 ;
F_23 ( V_50 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , & V_52 ) ;
if ( V_52 . V_53 != 0 ) {
F_24 ( V_2 ,
V_54 L_3 ,
V_52 . V_53 ) ;
return - V_37 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , unsigned long V_50 )
{
F_24 ( V_2 , V_54 L_4 ) ;
return - V_55 ;
}
static int F_25 ( struct V_20 * V_21 , T_5 * V_34 , T_6 V_56 )
{
struct V_3 * V_4 = F_13 ( & V_21 -> V_2 ) ;
int V_44 = 0 ;
F_2 ( 0 , & V_4 -> V_9 -> V_57 ) ;
if ( V_56 > V_4 -> V_58 ) {
F_24 ( & V_21 -> V_2 , L_5 ,
V_56 , V_4 -> V_58 ) ;
return - V_59 ;
}
F_26 ( V_4 -> V_60 , V_34 , V_56 ) ;
F_27 () ;
if ( V_4 -> V_5 & V_61 )
F_2 ( V_32 , & V_4 -> V_9 -> V_31 ) ;
if ( V_4 -> V_5 & V_6 )
V_44 = F_19 ( V_21 ) ;
if ( V_4 -> V_5 & V_7 ) {
F_2 ( V_32 , & V_4 -> V_9 -> V_31 ) ;
V_44 = F_22 ( & V_21 -> V_2 , V_4 -> V_62 ) ;
}
return V_44 ;
}
static void F_28 ( struct V_20 * V_21 )
{
struct V_3 * V_4 = F_13 ( & V_21 -> V_2 ) ;
F_2 ( V_63 , & V_4 -> V_9 -> V_57 ) ;
if ( ( V_4 -> V_5 & V_6 ) && F_19 ( V_21 ) )
F_24 ( & V_21 -> V_2 , L_6 ) ;
}
static bool F_29 ( struct V_20 * V_21 , T_5 V_64 )
{
struct V_3 * V_4 = F_13 ( & V_21 -> V_2 ) ;
T_2 V_65 = F_7 ( & V_4 -> V_9 -> V_57 ) ;
return ( V_65 & V_63 ) == V_63 ;
}
static int F_30 ( struct V_66 * V_67 , void * V_68 )
{
struct V_69 * V_70 = V_68 ;
struct V_71 V_72 ;
struct V_69 * V_52 = & ( V_72 . V_52 ) ;
if ( F_31 ( V_67 , V_52 ) ||
F_32 ( V_67 , & V_72 ) ) {
* V_70 = * V_52 ;
V_70 -> V_73 = NULL ;
}
return 1 ;
}
static void T_3 * F_33 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_69 * V_70 , T_7 V_15 , T_2 V_74 )
{
struct V_69 V_75 = {
. V_15 = V_15 ,
. V_76 = V_15 + V_74 - 1 ,
. V_5 = V_77 ,
} ;
if ( V_15 != V_75 . V_15 )
return ( void T_3 * ) F_34 ( - V_55 ) ;
if ( ! F_35 ( V_70 , & V_75 ) )
return F_36 ( V_2 , & V_75 ) ;
return V_4 -> V_78 + ( V_75 . V_15 - V_70 -> V_15 ) ;
}
static T_7 F_37 ( struct V_1 * V_2 , struct V_69 * V_70 ,
T_7 V_15 , T_7 V_74 )
{
if ( V_70 -> V_15 > V_15 || V_70 -> V_76 < V_15 )
return V_74 ;
if ( V_15 + V_74 - 1 <= V_70 -> V_76 )
return V_74 ;
F_24 ( V_2 ,
V_54 L_7 ,
V_70 , V_15 , V_74 ) ;
return V_70 -> V_76 - V_15 + 1 ;
}
static int F_38 ( struct V_79 * V_1 , struct V_3 * V_4 ,
struct V_80 * V_34 )
{
struct V_81 V_82 ;
struct V_69 V_70 ;
struct V_1 * V_2 = & V_1 -> V_2 ;
T_2 V_83 , V_84 ;
T_7 V_85 ;
T_2 V_58 ;
T_7 V_86 ;
T_2 V_87 ;
int V_88 ;
F_39 ( & V_82 ) ;
V_88 = F_40 ( V_1 , & V_82 , F_30 ,
& V_70 ) ;
if ( V_88 < 0 )
return V_88 ;
F_41 ( & V_82 ) ;
if ( F_42 ( & V_70 ) != V_77 ) {
F_24 ( V_2 , V_54 L_8 ) ;
return - V_55 ;
}
V_4 -> V_78 = F_36 ( V_2 , & V_70 ) ;
if ( F_43 ( V_4 -> V_78 ) )
return F_44 ( V_4 -> V_78 ) ;
if ( ! ( V_4 -> V_5 & V_6 ) ) {
if ( V_34 -> V_89 == V_70 . V_15 +
sizeof( * V_4 -> V_25 ) )
V_4 -> V_25 = V_4 -> V_78 ;
else
F_11 ( V_2 , V_54 L_9 ) ;
}
V_4 -> V_9 = F_33 ( V_2 , V_4 , & V_70 , V_34 -> V_89 ,
sizeof( struct V_90 ) ) ;
if ( F_43 ( V_4 -> V_9 ) )
return F_44 ( V_4 -> V_9 ) ;
V_88 = F_10 ( V_2 , V_4 ) ;
if ( V_88 )
return V_88 ;
V_83 = F_7 ( & V_4 -> V_9 -> V_91 ) ;
V_84 = F_7 ( & V_4 -> V_9 -> V_92 ) ;
V_85 = ( ( T_7 ) V_83 << 32 ) | V_84 ;
V_58 = F_37 ( V_2 , & V_70 , V_85 ,
F_7 ( & V_4 -> V_9 -> V_93 ) ) ;
F_45 ( V_2 , L_10 ,
V_83 , V_84 , V_58 ) ;
V_4 -> V_60 = F_33 ( V_2 , V_4 , & V_70 , V_85 , V_58 ) ;
if ( F_43 ( V_4 -> V_60 ) ) {
V_88 = F_44 ( V_4 -> V_60 ) ;
goto V_94;
}
F_17 ( & V_86 , & V_4 -> V_9 -> V_95 , 8 ) ;
V_86 = F_46 ( V_86 ) ;
V_87 = F_37 ( V_2 , & V_70 , V_86 ,
F_7 ( & V_4 -> V_9 -> V_96 ) ) ;
if ( V_85 != V_86 ) {
V_4 -> V_40 = F_33 ( V_2 , V_4 , & V_70 , V_86 , V_87 ) ;
V_88 = F_47 ( V_4 -> V_40 ) ;
goto V_94;
}
if ( V_58 != V_87 ) {
F_24 ( V_2 , V_54 L_11 ) ;
V_88 = - V_55 ;
goto V_94;
}
V_4 -> V_40 = V_4 -> V_60 ;
V_94:
if ( ! V_88 )
V_4 -> V_58 = V_58 ;
F_1 ( V_2 , V_4 ) ;
return V_88 ;
}
static int F_48 ( struct V_79 * V_1 )
{
struct V_80 * V_34 ;
struct V_3 * V_4 ;
struct V_20 * V_21 ;
struct V_1 * V_2 = & V_1 -> V_2 ;
struct V_97 * V_98 ;
T_8 V_64 ;
T_2 V_99 ;
int V_44 ;
V_64 = F_49 ( V_100 , 1 ,
(struct V_101 * * ) & V_34 ) ;
if ( F_50 ( V_64 ) || V_34 -> V_102 . V_103 < sizeof( * V_34 ) ) {
F_24 ( V_2 , V_54 L_12 ) ;
return - V_55 ;
}
V_99 = V_34 -> V_104 ;
if ( V_99 == V_105 )
return - V_106 ;
V_4 = F_51 ( V_2 , sizeof( struct V_3 ) , V_107 ) ;
if ( ! V_4 )
return - V_108 ;
if ( V_99 == V_109 || V_99 == V_105 ||
! strcmp ( F_52 ( V_1 ) , L_13 ) )
V_4 -> V_5 |= V_61 ;
if ( V_99 == V_110 ||
V_99 == V_111 )
V_4 -> V_5 |= V_6 ;
if ( V_99 == V_112 ) {
if ( V_34 -> V_102 . V_103 < ( sizeof( * V_34 ) + sizeof( * V_98 ) ) ) {
F_24 ( V_2 ,
V_54 L_14 ,
V_34 -> V_102 . V_103 ,
V_112 ) ;
return - V_55 ;
}
V_98 = F_53 ( struct V_97 , V_34 , sizeof( * V_34 ) ) ;
V_4 -> V_62 = V_98 -> V_62 ;
V_4 -> V_5 |= V_7 ;
}
V_44 = F_38 ( V_1 , V_4 , V_34 ) ;
if ( V_44 )
return V_44 ;
V_21 = F_54 ( V_2 , & V_113 ) ;
if ( F_43 ( V_21 ) )
return F_44 ( V_21 ) ;
F_55 ( & V_21 -> V_2 , V_4 ) ;
V_21 -> V_45 = V_1 -> V_114 ;
V_21 -> V_5 = V_115 ;
V_44 = F_10 ( V_2 , V_4 ) ;
if ( V_44 )
return V_44 ;
F_56 ( V_2 ) ;
F_57 ( V_2 ) ;
F_58 ( V_2 ) ;
V_44 = F_59 ( V_21 ) ;
if ( V_44 ) {
F_1 ( V_2 , V_4 ) ;
F_60 ( V_2 ) ;
F_61 ( V_2 ) ;
return V_44 ;
}
F_62 ( V_2 ) ;
return 0 ;
}
static int F_63 ( struct V_79 * V_1 )
{
struct V_1 * V_2 = & V_1 -> V_2 ;
struct V_20 * V_21 = F_13 ( V_2 ) ;
F_64 ( V_21 ) ;
F_61 ( V_2 ) ;
return 0 ;
}
static int T_1 F_65 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_13 ( V_2 ) ;
struct V_3 * V_4 = F_13 ( & V_21 -> V_2 ) ;
return F_1 ( V_2 , V_4 ) ;
}
static int T_1 F_66 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_13 ( V_2 ) ;
struct V_3 * V_4 = F_13 ( & V_21 -> V_2 ) ;
return F_10 ( V_2 , V_4 ) ;
}
static int T_1 F_67 ( struct V_1 * V_2 )
{
int V_88 ;
V_88 = F_68 ( V_2 ) ;
if ( V_88 )
return V_88 ;
return F_65 ( V_2 ) ;
}
static int T_1 F_69 ( struct V_1 * V_2 )
{
int V_88 ;
V_88 = F_66 ( V_2 ) ;
if ( V_88 )
return V_88 ;
return F_70 ( V_2 ) ;
}
