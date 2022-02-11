static inline struct V_1 * F_1 ( unsigned int V_2 )
{
unsigned int V_3 = F_2 ( V_2 ) ;
return V_3 < V_4 -> V_5 ? V_4 -> V_6 [ V_3 ] : NULL ;
}
static inline T_1 F_3 ( struct V_7 * V_8 )
{
T_1 V_9 ;
F_4 ( V_8 -> V_10 . V_11 , V_9 ) ;
return V_9 ;
}
static inline T_1 F_5 ( T_1 V_12 , int V_13 )
{
if ( V_13 > V_14 ) {
F_6 ( L_1 , V_13 ) ;
return V_12 ;
}
return V_12 << ( 32 - V_15 [ V_13 - 1 ] ) ;
}
static T_1 F_7 ( struct V_7 * V_8 )
{
struct V_16 * V_17 = & V_8 -> V_10 ;
T_1 V_18 , V_19 ;
T_2 V_20 , V_21 ;
int V_22 = V_23 ;
V_24:
V_18 = F_8 ( & V_17 -> V_25 ) ;
F_4 ( V_8 -> V_10 . V_11 , V_19 ) ;
if ( F_9 ( & V_17 -> V_25 , V_18 ,
V_19 ) != V_18 ) {
F_10 () ;
goto V_24;
}
V_20 = ( V_19 << V_22 ) - ( V_18 << V_22 ) ;
V_20 >>= V_22 ;
V_21 = F_5 ( V_20 , V_8 -> V_10 . V_26 ) ;
F_11 ( V_21 , & V_8 -> V_27 ) ;
return V_19 ;
}
static void F_12 ( struct V_1 * V_28 )
{
F_13 ( & V_28 -> V_29 , V_28 -> V_30 ,
V_31 ) ;
}
static enum V_32 F_14 ( struct V_29 * V_29 )
{
struct V_1 * V_28 = F_15 ( V_29 , struct V_1 , V_29 ) ;
struct V_7 * V_8 ;
unsigned long V_33 ;
if ( ! V_28 -> V_34 )
return V_35 ;
F_16 ( & V_28 -> V_36 , V_33 ) ;
F_17 (event, &pmu->active_list, active_entry)
F_7 ( V_8 ) ;
F_18 ( & V_28 -> V_36 , V_33 ) ;
F_19 ( V_29 , V_28 -> V_30 ) ;
return V_37 ;
}
static void F_20 ( struct V_1 * V_28 )
{
struct V_29 * V_38 = & V_28 -> V_29 ;
F_21 ( V_38 , V_39 , V_40 ) ;
V_38 -> V_41 = F_14 ;
}
static void F_22 ( struct V_1 * V_28 ,
struct V_7 * V_8 )
{
if ( F_23 ( ! ( V_8 -> V_10 . V_42 & V_43 ) ) )
return;
V_8 -> V_10 . V_42 = 0 ;
F_24 ( & V_8 -> V_44 , & V_28 -> V_45 ) ;
F_25 ( & V_8 -> V_10 . V_25 , F_3 ( V_8 ) ) ;
V_28 -> V_34 ++ ;
if ( V_28 -> V_34 == 1 )
F_12 ( V_28 ) ;
}
static void F_26 ( struct V_7 * V_8 , int V_46 )
{
struct V_1 * V_28 = V_8 -> V_47 ;
unsigned long V_33 ;
F_16 ( & V_28 -> V_36 , V_33 ) ;
F_22 ( V_28 , V_8 ) ;
F_18 ( & V_28 -> V_36 , V_33 ) ;
}
static void F_27 ( struct V_7 * V_8 , int V_46 )
{
struct V_1 * V_28 = V_8 -> V_47 ;
struct V_16 * V_17 = & V_8 -> V_10 ;
unsigned long V_33 ;
F_16 ( & V_28 -> V_36 , V_33 ) ;
if ( ! ( V_17 -> V_42 & V_43 ) ) {
F_23 ( V_28 -> V_34 <= 0 ) ;
V_28 -> V_34 -- ;
if ( V_28 -> V_34 == 0 )
F_28 ( & V_28 -> V_29 ) ;
F_29 ( & V_8 -> V_44 ) ;
F_23 ( V_17 -> V_42 & V_43 ) ;
V_17 -> V_42 |= V_43 ;
}
if ( ( V_46 & V_48 ) && ! ( V_17 -> V_42 & V_49 ) ) {
F_7 ( V_8 ) ;
V_17 -> V_42 |= V_49 ;
}
F_18 ( & V_28 -> V_36 , V_33 ) ;
}
static int F_30 ( struct V_7 * V_8 , int V_46 )
{
struct V_1 * V_28 = V_8 -> V_47 ;
struct V_16 * V_17 = & V_8 -> V_10 ;
unsigned long V_33 ;
F_16 ( & V_28 -> V_36 , V_33 ) ;
V_17 -> V_42 = V_49 | V_43 ;
if ( V_46 & V_50 )
F_22 ( V_28 , V_8 ) ;
F_18 ( & V_28 -> V_36 , V_33 ) ;
return 0 ;
}
static void F_31 ( struct V_7 * V_8 , int V_33 )
{
F_27 ( V_8 , V_48 ) ;
}
static int F_32 ( struct V_7 * V_8 )
{
T_1 V_13 = V_8 -> V_51 . V_26 & V_52 ;
int V_53 , V_54 , V_55 = 0 ;
struct V_1 * V_28 ;
if ( V_8 -> V_51 . type != V_4 -> V_28 . type )
return - V_56 ;
if ( V_8 -> V_51 . V_26 & ~ V_52 )
return - V_57 ;
if ( V_8 -> V_2 < 0 )
return - V_57 ;
V_8 -> V_58 |= V_59 ;
switch ( V_13 ) {
case V_60 :
V_53 = V_61 ;
V_54 = V_62 ;
break;
case V_63 :
V_53 = V_64 ;
V_54 = V_65 ;
break;
case V_66 :
V_53 = V_67 ;
V_54 = V_68 ;
break;
case V_69 :
V_53 = V_70 ;
V_54 = V_71 ;
break;
case V_72 :
V_53 = V_73 ;
V_54 = V_74 ;
break;
default:
return - V_57 ;
}
if ( ! ( V_75 & ( 1 << V_53 ) ) )
return - V_57 ;
if ( V_8 -> V_51 . V_76 ||
V_8 -> V_51 . V_77 ||
V_8 -> V_51 . V_78 ||
V_8 -> V_51 . V_79 ||
V_8 -> V_51 . V_80 ||
V_8 -> V_51 . V_81 ||
V_8 -> V_51 . V_82 )
return - V_57 ;
V_28 = F_1 ( V_8 -> V_2 ) ;
if ( ! V_28 )
return - V_57 ;
V_8 -> V_2 = V_28 -> V_2 ;
V_8 -> V_47 = V_28 ;
V_8 -> V_10 . V_11 = V_54 ;
V_8 -> V_10 . V_26 = V_13 ;
V_8 -> V_10 . V_83 = V_53 ;
return V_55 ;
}
static void F_33 ( struct V_7 * V_8 )
{
F_7 ( V_8 ) ;
}
static T_3 F_34 ( struct V_84 * V_85 ,
struct V_86 * V_51 , char * V_87 )
{
return F_35 ( true , V_87 , & V_88 ) ;
}
static int F_36 ( unsigned int V_2 )
{
struct V_1 * V_28 = F_1 ( V_2 ) ;
int V_89 ;
if ( ! F_37 ( V_2 , & V_88 ) )
return 0 ;
V_28 -> V_2 = - 1 ;
V_89 = F_38 ( F_39 ( V_2 ) , V_2 ) ;
if ( V_89 < V_90 ) {
F_40 ( V_89 , & V_88 ) ;
V_28 -> V_2 = V_89 ;
F_41 ( V_28 -> V_28 , V_2 , V_89 ) ;
}
return 0 ;
}
static int F_42 ( unsigned int V_2 )
{
struct V_1 * V_28 = F_1 ( V_2 ) ;
int V_89 ;
if ( ! V_28 ) {
V_28 = F_43 ( sizeof( * V_28 ) , V_91 , F_44 ( V_2 ) ) ;
if ( ! V_28 )
return - V_92 ;
F_45 ( & V_28 -> V_36 ) ;
F_46 ( & V_28 -> V_45 ) ;
V_28 -> V_28 = & V_4 -> V_28 ;
V_28 -> V_30 = F_47 ( V_93 ) ;
F_20 ( V_28 ) ;
V_4 -> V_6 [ F_2 ( V_2 ) ] = V_28 ;
}
V_89 = F_48 ( & V_88 , F_39 ( V_2 ) ) ;
if ( V_89 < V_90 )
return 0 ;
F_40 ( V_2 , & V_88 ) ;
V_28 -> V_2 = V_2 ;
return 0 ;
}
static int F_49 ( bool V_94 )
{
T_1 V_95 ;
int V_96 ;
if ( F_50 ( V_97 , & V_95 ) )
return - 1 ;
for ( V_96 = 0 ; V_96 < V_14 ; V_96 ++ )
V_15 [ V_96 ] = ( V_95 >> 8 ) & 0x1FULL ;
if ( V_94 )
V_15 [ V_67 ] = 16 ;
V_93 = 2 ;
if ( V_15 [ 0 ] < 32 ) {
V_93 = ( 1000 / ( 2 * 100 ) ) ;
V_93 *= ( 1ULL << ( 32 - V_15 [ 0 ] - 1 ) ) ;
}
return 0 ;
}
static void T_4 F_51 ( void )
{
int V_96 ;
F_52 ( L_2 ,
F_53 ( V_75 ) , V_93 ) ;
for ( V_96 = 0 ; V_96 < V_14 ; V_96 ++ ) {
if ( V_75 & ( 1 << V_96 ) ) {
F_52 ( L_3 ,
V_98 [ V_96 ] , V_15 [ V_96 ] ) ;
}
}
}
static void F_54 ( void )
{
int V_96 ;
for ( V_96 = 0 ; V_96 < V_4 -> V_5 ; V_96 ++ )
F_55 ( V_4 -> V_6 [ V_96 ] ) ;
F_55 ( V_4 ) ;
}
static int T_4 F_56 ( void )
{
int V_5 = F_57 () ;
T_5 V_99 ;
V_99 = sizeof( * V_4 ) + V_5 * sizeof( struct V_1 * ) ;
V_4 = F_58 ( V_99 , V_91 ) ;
if ( ! V_4 )
return - V_92 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_28 . V_100 = V_101 ;
V_4 -> V_28 . V_102 = V_103 ;
V_4 -> V_28 . V_104 = F_32 ;
V_4 -> V_28 . V_105 = F_30 ;
V_4 -> V_28 . V_106 = F_31 ;
V_4 -> V_28 . V_107 = F_26 ;
V_4 -> V_28 . V_108 = F_27 ;
V_4 -> V_28 . V_109 = F_33 ;
V_4 -> V_28 . V_110 = V_111 ;
return 0 ;
}
static int T_4 F_59 ( void )
{
const struct V_112 * V_113 ;
struct V_114 * V_115 ;
bool V_94 ;
int V_55 ;
V_113 = F_60 ( V_116 ) ;
if ( ! V_113 )
return - V_117 ;
V_115 = (struct V_114 * ) V_113 -> V_118 ;
V_94 = V_115 -> V_94 ;
V_75 = V_115 -> V_119 ;
V_120 . V_121 = V_115 -> V_121 ;
V_55 = F_49 ( V_94 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_56 () ;
if ( V_55 )
return V_55 ;
V_55 = F_61 ( V_122 ,
L_4 ,
F_42 , F_36 ) ;
if ( V_55 )
goto V_123;
V_55 = F_62 ( & V_4 -> V_28 , L_5 , - 1 ) ;
if ( V_55 )
goto V_124;
F_51 () ;
return 0 ;
V_124:
F_63 ( V_122 ) ;
V_123:
F_6 ( L_6 , V_55 ) ;
F_54 () ;
return V_55 ;
}
static void T_6 F_64 ( void )
{
F_65 ( V_122 ) ;
F_66 ( & V_4 -> V_28 ) ;
F_54 () ;
}
