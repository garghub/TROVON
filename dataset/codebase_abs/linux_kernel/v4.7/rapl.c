static inline struct V_1 * F_1 ( unsigned int V_2 )
{
return V_3 -> V_4 [ F_2 ( V_2 ) ] ;
}
static inline T_1 F_3 ( struct V_5 * V_6 )
{
T_1 V_7 ;
F_4 ( V_6 -> V_8 . V_9 , V_7 ) ;
return V_7 ;
}
static inline T_1 F_5 ( T_1 V_10 , int V_11 )
{
if ( V_11 > V_12 ) {
F_6 ( L_1 , V_11 ) ;
return V_10 ;
}
return V_10 << ( 32 - V_13 [ V_11 - 1 ] ) ;
}
static T_1 F_7 ( struct V_5 * V_6 )
{
struct V_14 * V_15 = & V_6 -> V_8 ;
T_1 V_16 , V_17 ;
T_2 V_18 , V_19 ;
int V_20 = V_21 ;
V_22:
V_16 = F_8 ( & V_15 -> V_23 ) ;
F_4 ( V_6 -> V_8 . V_9 , V_17 ) ;
if ( F_9 ( & V_15 -> V_23 , V_16 ,
V_17 ) != V_16 ) {
F_10 () ;
goto V_22;
}
V_18 = ( V_17 << V_20 ) - ( V_16 << V_20 ) ;
V_18 >>= V_20 ;
V_19 = F_5 ( V_18 , V_6 -> V_8 . V_24 ) ;
F_11 ( V_19 , & V_6 -> V_25 ) ;
return V_17 ;
}
static void F_12 ( struct V_1 * V_26 )
{
F_13 ( & V_26 -> V_27 , V_26 -> V_28 ,
V_29 ) ;
}
static enum V_30 F_14 ( struct V_27 * V_27 )
{
struct V_1 * V_26 = F_15 ( V_27 , struct V_1 , V_27 ) ;
struct V_5 * V_6 ;
unsigned long V_31 ;
if ( ! V_26 -> V_32 )
return V_33 ;
F_16 ( & V_26 -> V_34 , V_31 ) ;
F_17 (event, &pmu->active_list, active_entry)
F_7 ( V_6 ) ;
F_18 ( & V_26 -> V_34 , V_31 ) ;
F_19 ( V_27 , V_26 -> V_28 ) ;
return V_35 ;
}
static void F_20 ( struct V_1 * V_26 )
{
struct V_27 * V_36 = & V_26 -> V_27 ;
F_21 ( V_36 , V_37 , V_38 ) ;
V_36 -> V_39 = F_14 ;
}
static void F_22 ( struct V_1 * V_26 ,
struct V_5 * V_6 )
{
if ( F_23 ( ! ( V_6 -> V_8 . V_40 & V_41 ) ) )
return;
V_6 -> V_8 . V_40 = 0 ;
F_24 ( & V_6 -> V_42 , & V_26 -> V_43 ) ;
F_25 ( & V_6 -> V_8 . V_23 , F_3 ( V_6 ) ) ;
V_26 -> V_32 ++ ;
if ( V_26 -> V_32 == 1 )
F_12 ( V_26 ) ;
}
static void F_26 ( struct V_5 * V_6 , int V_44 )
{
struct V_1 * V_26 = V_6 -> V_45 ;
unsigned long V_31 ;
F_16 ( & V_26 -> V_34 , V_31 ) ;
F_22 ( V_26 , V_6 ) ;
F_18 ( & V_26 -> V_34 , V_31 ) ;
}
static void F_27 ( struct V_5 * V_6 , int V_44 )
{
struct V_1 * V_26 = V_6 -> V_45 ;
struct V_14 * V_15 = & V_6 -> V_8 ;
unsigned long V_31 ;
F_16 ( & V_26 -> V_34 , V_31 ) ;
if ( ! ( V_15 -> V_40 & V_41 ) ) {
F_23 ( V_26 -> V_32 <= 0 ) ;
V_26 -> V_32 -- ;
if ( V_26 -> V_32 == 0 )
F_28 ( & V_26 -> V_27 ) ;
F_29 ( & V_6 -> V_42 ) ;
F_23 ( V_15 -> V_40 & V_41 ) ;
V_15 -> V_40 |= V_41 ;
}
if ( ( V_44 & V_46 ) && ! ( V_15 -> V_40 & V_47 ) ) {
F_7 ( V_6 ) ;
V_15 -> V_40 |= V_47 ;
}
F_18 ( & V_26 -> V_34 , V_31 ) ;
}
static int F_30 ( struct V_5 * V_6 , int V_44 )
{
struct V_1 * V_26 = V_6 -> V_45 ;
struct V_14 * V_15 = & V_6 -> V_8 ;
unsigned long V_31 ;
F_16 ( & V_26 -> V_34 , V_31 ) ;
V_15 -> V_40 = V_47 | V_41 ;
if ( V_44 & V_48 )
F_22 ( V_26 , V_6 ) ;
F_18 ( & V_26 -> V_34 , V_31 ) ;
return 0 ;
}
static void F_31 ( struct V_5 * V_6 , int V_31 )
{
F_27 ( V_6 , V_46 ) ;
}
static int F_32 ( struct V_5 * V_6 )
{
T_1 V_11 = V_6 -> V_49 . V_24 & V_50 ;
int V_51 , V_52 , V_53 = 0 ;
struct V_1 * V_26 ;
if ( V_6 -> V_49 . type != V_3 -> V_26 . type )
return - V_54 ;
if ( V_6 -> V_49 . V_24 & ~ V_50 )
return - V_55 ;
if ( V_6 -> V_2 < 0 )
return - V_55 ;
switch ( V_11 ) {
case V_56 :
V_51 = V_57 ;
V_52 = V_58 ;
break;
case V_59 :
V_51 = V_60 ;
V_52 = V_61 ;
break;
case V_62 :
V_51 = V_63 ;
V_52 = V_64 ;
break;
case V_65 :
V_51 = V_66 ;
V_52 = V_67 ;
break;
case V_68 :
V_51 = V_69 ;
V_52 = V_70 ;
break;
default:
return - V_55 ;
}
if ( ! ( V_71 & ( 1 << V_51 ) ) )
return - V_55 ;
if ( V_6 -> V_49 . V_72 ||
V_6 -> V_49 . V_73 ||
V_6 -> V_49 . V_74 ||
V_6 -> V_49 . V_75 ||
V_6 -> V_49 . V_76 ||
V_6 -> V_49 . V_77 ||
V_6 -> V_49 . V_78 )
return - V_55 ;
V_26 = F_1 ( V_6 -> V_2 ) ;
V_6 -> V_2 = V_26 -> V_2 ;
V_6 -> V_45 = V_26 ;
V_6 -> V_8 . V_9 = V_52 ;
V_6 -> V_8 . V_24 = V_11 ;
V_6 -> V_8 . V_79 = V_51 ;
return V_53 ;
}
static void F_33 ( struct V_5 * V_6 )
{
F_7 ( V_6 ) ;
}
static T_3 F_34 ( struct V_80 * V_81 ,
struct V_82 * V_49 , char * V_83 )
{
return F_35 ( true , V_83 , & V_84 ) ;
}
static void F_36 ( int V_2 )
{
struct V_1 * V_26 = F_1 ( V_2 ) ;
int V_85 ;
if ( ! F_37 ( V_2 , & V_84 ) )
return;
V_26 -> V_2 = - 1 ;
V_85 = F_38 ( F_39 ( V_2 ) , V_2 ) ;
if ( V_85 < V_86 ) {
F_40 ( V_85 , & V_84 ) ;
V_26 -> V_2 = V_85 ;
F_41 ( V_26 -> V_26 , V_2 , V_85 ) ;
}
}
static void F_42 ( int V_2 )
{
struct V_1 * V_26 = F_1 ( V_2 ) ;
int V_85 ;
V_85 = F_43 ( & V_84 , F_39 ( V_2 ) ) ;
if ( V_85 < V_86 )
return;
F_40 ( V_2 , & V_84 ) ;
V_26 -> V_2 = V_2 ;
}
static int F_44 ( int V_2 )
{
struct V_1 * V_26 = F_1 ( V_2 ) ;
if ( V_26 )
return 0 ;
V_26 = F_45 ( sizeof( * V_26 ) , V_87 , F_46 ( V_2 ) ) ;
if ( ! V_26 )
return - V_88 ;
F_47 ( & V_26 -> V_34 ) ;
F_48 ( & V_26 -> V_43 ) ;
V_26 -> V_26 = & V_3 -> V_26 ;
V_26 -> V_28 = F_49 ( V_89 ) ;
V_26 -> V_2 = - 1 ;
F_20 ( V_26 ) ;
V_3 -> V_4 [ F_2 ( V_2 ) ] = V_26 ;
return 0 ;
}
static int F_50 ( struct V_90 * V_91 ,
unsigned long V_92 , void * V_93 )
{
unsigned int V_2 = ( long ) V_93 ;
switch ( V_92 & ~ V_94 ) {
case V_95 :
F_44 ( V_2 ) ;
break;
case V_96 :
case V_97 :
F_42 ( V_2 ) ;
break;
case V_98 :
F_36 ( V_2 ) ;
break;
}
return V_99 ;
}
static int F_51 ( bool V_100 )
{
T_1 V_101 ;
int V_102 ;
if ( F_52 ( V_103 , & V_101 ) )
return - 1 ;
for ( V_102 = 0 ; V_102 < V_12 ; V_102 ++ )
V_13 [ V_102 ] = ( V_101 >> 8 ) & 0x1FULL ;
if ( V_100 )
V_13 [ V_63 ] = 16 ;
V_89 = 2 ;
if ( V_13 [ 0 ] < 32 ) {
V_89 = ( 1000 / ( 2 * 100 ) ) ;
V_89 *= ( 1ULL << ( 32 - V_13 [ 0 ] - 1 ) ) ;
}
return 0 ;
}
static void T_4 F_53 ( void )
{
int V_102 ;
F_54 ( L_2 ,
F_55 ( V_71 ) , V_89 ) ;
for ( V_102 = 0 ; V_102 < V_12 ; V_102 ++ ) {
if ( V_71 & ( 1 << V_102 ) ) {
F_54 ( L_3 ,
V_104 [ V_102 ] , V_13 [ V_102 ] ) ;
}
}
}
static int T_4 F_56 ( void )
{
unsigned int V_2 , V_105 ;
int V_53 ;
F_57 (cpu) {
V_105 = F_2 ( V_2 ) ;
if ( V_3 -> V_4 [ V_105 ] )
continue;
V_53 = F_44 ( V_2 ) ;
if ( V_53 )
return V_53 ;
F_42 ( V_2 ) ;
}
return 0 ;
}
static void F_58 ( void )
{
int V_102 ;
for ( V_102 = 0 ; V_102 < V_3 -> V_106 ; V_102 ++ )
F_59 ( V_3 -> V_4 [ V_102 ] ) ;
F_59 ( V_3 ) ;
}
static int T_4 F_60 ( void )
{
int V_106 = F_61 () ;
T_5 V_107 ;
V_107 = sizeof( * V_3 ) + V_106 * sizeof( struct V_1 * ) ;
V_3 = F_62 ( V_107 , V_87 ) ;
if ( ! V_3 )
return - V_88 ;
V_3 -> V_106 = V_106 ;
V_3 -> V_26 . V_108 = V_109 ;
V_3 -> V_26 . V_110 = V_111 ;
V_3 -> V_26 . V_112 = F_32 ;
V_3 -> V_26 . V_113 = F_30 ;
V_3 -> V_26 . V_114 = F_31 ;
V_3 -> V_26 . V_115 = F_26 ;
V_3 -> V_26 . V_116 = F_27 ;
V_3 -> V_26 . V_117 = F_33 ;
return 0 ;
}
static int T_4 F_63 ( void )
{
const struct V_118 * V_119 ;
struct V_120 * V_121 ;
bool V_100 ;
int V_53 ;
V_119 = F_64 ( V_122 ) ;
if ( ! V_119 )
return - V_123 ;
V_121 = (struct V_120 * ) V_119 -> V_124 ;
V_100 = V_121 -> V_100 ;
V_71 = V_121 -> V_125 ;
V_126 . V_127 = V_121 -> V_127 ;
V_53 = F_51 ( V_100 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_60 () ;
if ( V_53 )
return V_53 ;
F_65 () ;
V_53 = F_56 () ;
if ( V_53 )
goto V_128;
V_53 = F_66 ( & V_3 -> V_26 , L_4 , - 1 ) ;
if ( V_53 )
goto V_128;
F_67 ( & V_129 ) ;
F_68 () ;
F_53 () ;
return 0 ;
V_128:
F_6 ( L_5 , V_53 ) ;
F_58 () ;
F_68 () ;
return V_53 ;
}
static void T_6 F_69 ( void )
{
F_65 () ;
F_70 ( & V_129 ) ;
F_71 ( & V_3 -> V_26 ) ;
F_58 () ;
F_68 () ;
}
