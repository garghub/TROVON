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
static int F_36 ( unsigned int V_2 )
{
struct V_1 * V_26 = F_1 ( V_2 ) ;
int V_85 ;
if ( ! F_37 ( V_2 , & V_84 ) )
return 0 ;
V_26 -> V_2 = - 1 ;
V_85 = F_38 ( F_39 ( V_2 ) , V_2 ) ;
if ( V_85 < V_86 ) {
F_40 ( V_85 , & V_84 ) ;
V_26 -> V_2 = V_85 ;
F_41 ( V_26 -> V_26 , V_2 , V_85 ) ;
}
return 0 ;
}
static int F_42 ( unsigned int V_2 )
{
struct V_1 * V_26 = F_1 ( V_2 ) ;
int V_85 ;
V_85 = F_43 ( & V_84 , F_39 ( V_2 ) ) ;
if ( V_85 < V_86 )
return 0 ;
F_40 ( V_2 , & V_84 ) ;
V_26 -> V_2 = V_2 ;
return 0 ;
}
static int F_44 ( unsigned int V_2 )
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
static int F_50 ( bool V_90 )
{
T_1 V_91 ;
int V_92 ;
if ( F_51 ( V_93 , & V_91 ) )
return - 1 ;
for ( V_92 = 0 ; V_92 < V_12 ; V_92 ++ )
V_13 [ V_92 ] = ( V_91 >> 8 ) & 0x1FULL ;
if ( V_90 )
V_13 [ V_63 ] = 16 ;
V_89 = 2 ;
if ( V_13 [ 0 ] < 32 ) {
V_89 = ( 1000 / ( 2 * 100 ) ) ;
V_89 *= ( 1ULL << ( 32 - V_13 [ 0 ] - 1 ) ) ;
}
return 0 ;
}
static void T_4 F_52 ( void )
{
int V_92 ;
F_53 ( L_2 ,
F_54 ( V_71 ) , V_89 ) ;
for ( V_92 = 0 ; V_92 < V_12 ; V_92 ++ ) {
if ( V_71 & ( 1 << V_92 ) ) {
F_53 ( L_3 ,
V_94 [ V_92 ] , V_13 [ V_92 ] ) ;
}
}
}
static void F_55 ( void )
{
int V_92 ;
for ( V_92 = 0 ; V_92 < V_3 -> V_95 ; V_92 ++ )
F_56 ( V_3 -> V_4 [ V_92 ] ) ;
F_56 ( V_3 ) ;
}
static int T_4 F_57 ( void )
{
int V_95 = F_58 () ;
T_5 V_96 ;
V_96 = sizeof( * V_3 ) + V_95 * sizeof( struct V_1 * ) ;
V_3 = F_59 ( V_96 , V_87 ) ;
if ( ! V_3 )
return - V_88 ;
V_3 -> V_95 = V_95 ;
V_3 -> V_26 . V_97 = V_98 ;
V_3 -> V_26 . V_99 = V_100 ;
V_3 -> V_26 . V_101 = F_32 ;
V_3 -> V_26 . V_102 = F_30 ;
V_3 -> V_26 . V_103 = F_31 ;
V_3 -> V_26 . V_104 = F_26 ;
V_3 -> V_26 . V_105 = F_27 ;
V_3 -> V_26 . V_106 = F_33 ;
return 0 ;
}
static int T_4 F_60 ( void )
{
const struct V_107 * V_108 ;
struct V_109 * V_110 ;
bool V_90 ;
int V_53 ;
V_108 = F_61 ( V_111 ) ;
if ( ! V_108 )
return - V_112 ;
V_110 = (struct V_109 * ) V_108 -> V_113 ;
V_90 = V_110 -> V_90 ;
V_71 = V_110 -> V_114 ;
V_115 . V_116 = V_110 -> V_116 ;
V_53 = F_50 ( V_90 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_57 () ;
if ( V_53 )
return V_53 ;
V_53 = F_62 ( V_117 , L_4 ,
F_44 , NULL ) ;
if ( V_53 )
goto V_118;
V_53 = F_62 ( V_119 ,
L_5 ,
F_42 , F_36 ) ;
if ( V_53 )
goto V_120;
V_53 = F_63 ( & V_3 -> V_26 , L_6 , - 1 ) ;
if ( V_53 )
goto V_121;
F_52 () ;
return 0 ;
V_121:
F_64 ( V_119 ) ;
V_120:
F_64 ( V_117 ) ;
V_118:
F_6 ( L_7 , V_53 ) ;
F_55 () ;
return V_53 ;
}
static void T_6 F_65 ( void )
{
F_66 ( V_119 ) ;
F_66 ( V_117 ) ;
F_67 ( & V_3 -> V_26 ) ;
F_55 () ;
}
