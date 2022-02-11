static inline T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_2 ( V_2 -> V_4 . V_5 , V_3 ) ;
return V_3 ;
}
static inline T_1 F_3 ( T_1 V_6 , int V_7 )
{
if ( V_7 > V_8 ) {
F_4 ( L_1 , V_7 ) ;
return V_6 ;
}
return V_6 << ( 32 - V_9 [ V_7 - 1 ] ) ;
}
static T_1 F_5 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = & V_2 -> V_4 ;
T_1 V_12 , V_13 ;
T_2 V_14 , V_15 ;
int V_16 = V_17 ;
V_18:
V_12 = F_6 ( & V_11 -> V_19 ) ;
F_2 ( V_2 -> V_4 . V_5 , V_13 ) ;
if ( F_7 ( & V_11 -> V_19 , V_12 ,
V_13 ) != V_12 ) {
F_8 () ;
goto V_18;
}
V_14 = ( V_13 << V_16 ) - ( V_12 << V_16 ) ;
V_14 >>= V_16 ;
V_15 = F_3 ( V_14 , V_2 -> V_4 . V_20 ) ;
F_9 ( V_15 , & V_2 -> V_21 ) ;
return V_13 ;
}
static void F_10 ( struct V_22 * V_23 )
{
F_11 ( & V_23 -> V_24 , V_23 -> V_25 ,
V_26 ) ;
}
static void F_12 ( struct V_22 * V_23 )
{
F_13 ( & V_23 -> V_24 ) ;
}
static enum V_27 F_14 ( struct V_24 * V_24 )
{
struct V_22 * V_23 = F_15 ( V_22 ) ;
struct V_1 * V_2 ;
unsigned long V_28 ;
if ( ! V_23 -> V_29 )
return V_30 ;
F_16 ( & V_23 -> V_31 , V_28 ) ;
F_17 (event, &pmu->active_list, active_entry) {
F_5 ( V_2 ) ;
}
F_18 ( & V_23 -> V_31 , V_28 ) ;
F_19 ( V_24 , V_23 -> V_25 ) ;
return V_32 ;
}
static void F_20 ( struct V_22 * V_23 )
{
struct V_24 * V_33 = & V_23 -> V_24 ;
F_21 ( V_33 , V_34 , V_35 ) ;
V_33 -> V_36 = F_14 ;
}
static void F_22 ( struct V_22 * V_23 ,
struct V_1 * V_2 )
{
if ( F_23 ( ! ( V_2 -> V_4 . V_37 & V_38 ) ) )
return;
V_2 -> V_4 . V_37 = 0 ;
F_24 ( & V_2 -> V_39 , & V_23 -> V_40 ) ;
F_25 ( & V_2 -> V_4 . V_19 , F_1 ( V_2 ) ) ;
V_23 -> V_29 ++ ;
if ( V_23 -> V_29 == 1 )
F_10 ( V_23 ) ;
}
static void F_26 ( struct V_1 * V_2 , int V_41 )
{
struct V_22 * V_23 = F_15 ( V_22 ) ;
unsigned long V_28 ;
F_16 ( & V_23 -> V_31 , V_28 ) ;
F_22 ( V_23 , V_2 ) ;
F_18 ( & V_23 -> V_31 , V_28 ) ;
}
static void F_27 ( struct V_1 * V_2 , int V_41 )
{
struct V_22 * V_23 = F_15 ( V_22 ) ;
struct V_10 * V_11 = & V_2 -> V_4 ;
unsigned long V_28 ;
F_16 ( & V_23 -> V_31 , V_28 ) ;
if ( ! ( V_11 -> V_37 & V_38 ) ) {
F_23 ( V_23 -> V_29 <= 0 ) ;
V_23 -> V_29 -- ;
if ( V_23 -> V_29 == 0 )
F_12 ( V_23 ) ;
F_28 ( & V_2 -> V_39 ) ;
F_23 ( V_11 -> V_37 & V_38 ) ;
V_11 -> V_37 |= V_38 ;
}
if ( ( V_41 & V_42 ) && ! ( V_11 -> V_37 & V_43 ) ) {
F_5 ( V_2 ) ;
V_11 -> V_37 |= V_43 ;
}
F_18 ( & V_23 -> V_31 , V_28 ) ;
}
static int F_29 ( struct V_1 * V_2 , int V_41 )
{
struct V_22 * V_23 = F_15 ( V_22 ) ;
struct V_10 * V_11 = & V_2 -> V_4 ;
unsigned long V_28 ;
F_16 ( & V_23 -> V_31 , V_28 ) ;
V_11 -> V_37 = V_43 | V_38 ;
if ( V_41 & V_44 )
F_22 ( V_23 , V_2 ) ;
F_18 ( & V_23 -> V_31 , V_28 ) ;
return 0 ;
}
static void F_30 ( struct V_1 * V_2 , int V_28 )
{
F_27 ( V_2 , V_42 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
T_1 V_7 = V_2 -> V_45 . V_20 & V_46 ;
int V_47 , V_48 , V_49 = 0 ;
if ( V_2 -> V_45 . type != V_50 . type )
return - V_51 ;
if ( V_2 -> V_45 . V_20 & ~ V_46 )
return - V_52 ;
switch ( V_7 ) {
case V_53 :
V_47 = V_54 ;
V_48 = V_55 ;
break;
case V_56 :
V_47 = V_57 ;
V_48 = V_58 ;
break;
case V_59 :
V_47 = V_60 ;
V_48 = V_61 ;
break;
case V_62 :
V_47 = V_63 ;
V_48 = V_64 ;
break;
default:
return - V_52 ;
}
if ( ! ( V_65 & ( 1 << V_47 ) ) )
return - V_52 ;
if ( V_2 -> V_45 . V_66 ||
V_2 -> V_45 . V_67 ||
V_2 -> V_45 . V_68 ||
V_2 -> V_45 . V_69 ||
V_2 -> V_45 . V_70 ||
V_2 -> V_45 . V_71 ||
V_2 -> V_45 . V_72 )
return - V_52 ;
V_2 -> V_4 . V_5 = V_48 ;
V_2 -> V_4 . V_20 = V_7 ;
V_2 -> V_4 . V_73 = V_47 ;
return V_49 ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_5 ( V_2 ) ;
}
static T_3 F_33 ( struct V_74 * V_75 ,
struct V_76 * V_45 , char * V_77 )
{
return F_34 ( true , V_77 , & V_78 ) ;
}
static T_3 F_35 ( struct V_74 * V_75 ,
struct V_76 * V_45 ,
char * V_79 )
{
struct V_80 * V_81 = \
F_36 ( V_45 , struct V_80 , V_45 ) ;
if ( V_81 -> V_82 )
return sprintf ( V_79 , L_2 , V_81 -> V_82 ) ;
return 0 ;
}
static void F_37 ( int V_83 )
{
struct V_22 * V_23 = F_38 ( V_22 , V_83 ) ;
int V_84 , V_85 = F_39 ( V_83 ) ;
int V_86 = - 1 ;
F_40 (i) {
if ( V_84 == V_83 )
continue;
if ( V_85 == F_39 ( V_84 ) ) {
V_86 = V_84 ;
break;
}
}
if ( F_41 ( V_83 , & V_78 ) && V_86 >= 0 )
F_42 ( V_86 , & V_78 ) ;
F_43 ( F_44 ( & V_78 ) ) ;
if ( V_86 >= 0 )
F_45 ( V_23 -> V_23 , V_83 , V_86 ) ;
F_12 ( V_23 ) ;
}
static void F_46 ( int V_83 )
{
int V_84 , V_85 = F_39 ( V_83 ) ;
F_47 (i, &rapl_cpu_mask) {
if ( V_85 == F_39 ( V_84 ) )
return;
}
F_42 ( V_83 , & V_78 ) ;
}
static T_4 void F_48 ( void )
{
V_9 [ V_60 ] = 16 ;
}
static int F_49 ( int V_83 )
{
struct V_22 * V_23 = F_38 ( V_22 , V_83 ) ;
int V_85 = F_39 ( V_83 ) ;
T_1 V_87 ;
if ( V_23 )
return 0 ;
if ( V_85 < 0 )
return - 1 ;
V_23 = F_50 ( sizeof( * V_23 ) , V_88 , F_51 ( V_83 ) ) ;
if ( ! V_23 )
return - 1 ;
F_52 ( & V_23 -> V_31 ) ;
F_53 ( & V_23 -> V_40 ) ;
V_23 -> V_23 = & V_50 ;
if ( V_9 [ 0 ] < 32 )
V_87 = ( 1000 / ( 2 * 100 ) ) * ( 1ULL << ( 32 - V_9 [ 0 ] - 1 ) ) ;
else
V_87 = 2 ;
V_23 -> V_25 = F_54 ( V_87 ) ;
F_20 ( V_23 ) ;
F_38 ( V_22 , V_83 ) = V_23 ;
F_38 ( V_89 , V_83 ) = NULL ;
return 0 ;
}
static void F_55 ( int V_83 )
{
struct V_22 * V_23 = F_38 ( V_89 , V_83 ) ;
F_56 ( V_23 ) ;
F_38 ( V_89 , V_83 ) = NULL ;
}
static int F_57 ( int V_83 )
{
struct V_22 * V_23 = F_38 ( V_22 , V_83 ) ;
if ( ! V_23 )
return 0 ;
F_38 ( V_22 , V_83 ) = NULL ;
F_38 ( V_89 , V_83 ) = V_23 ;
return 0 ;
}
static int F_58 ( struct V_90 * V_91 ,
unsigned long V_92 , void * V_93 )
{
unsigned int V_83 = ( long ) V_93 ;
switch ( V_92 & ~ V_94 ) {
case V_95 :
F_49 ( V_83 ) ;
break;
case V_96 :
F_46 ( V_83 ) ;
break;
case V_97 :
case V_98 :
F_57 ( V_83 ) ;
break;
case V_99 :
case V_100 :
F_55 ( V_83 ) ;
break;
case V_101 :
F_37 ( V_83 ) ;
break;
default:
break;
}
return V_102 ;
}
static int F_59 ( void )
{
T_1 V_103 ;
int V_84 ;
if ( F_60 ( V_104 , & V_103 ) )
return - 1 ;
for ( V_84 = 0 ; V_84 < V_8 ; V_84 ++ )
V_9 [ V_84 ] = ( V_103 >> 8 ) & 0x1FULL ;
return 0 ;
}
static int T_4 F_61 ( void )
{
struct V_22 * V_23 ;
int V_83 , V_49 ;
struct V_105 * V_106 ;
int V_84 ;
if ( ! F_62 ( V_107 ) )
return 0 ;
switch ( V_108 . V_109 ) {
case 42 :
case 58 :
V_65 = V_110 ;
V_111 . V_112 = V_113 ;
break;
case 63 :
F_63 ( F_48 ) ;
V_65 = V_114 ;
V_111 . V_112 = V_115 ;
break;
case 60 :
case 69 :
case 61 :
V_65 = V_116 ;
V_111 . V_112 = V_117 ;
break;
case 45 :
case 62 :
V_65 = V_114 ;
V_111 . V_112 = V_115 ;
break;
default:
return 0 ;
}
V_49 = F_59 () ;
if ( V_49 )
return V_49 ;
for ( V_106 = V_118 ; V_106 ; V_106 = V_106 -> V_119 )
V_106 -> V_120 () ;
F_64 () ;
F_40 (cpu) {
V_49 = F_49 ( V_83 ) ;
if ( V_49 )
goto V_121;
F_46 ( V_83 ) ;
}
F_65 ( F_58 ) ;
V_49 = F_66 ( & V_50 , L_3 , - 1 ) ;
if ( F_43 ( V_49 ) ) {
F_67 ( L_4 , V_49 ) ;
F_68 () ;
return - 1 ;
}
V_23 = F_15 ( V_22 ) ;
F_67 ( L_5
L_6
L_7
L_8 ,
F_69 ( V_65 ) ,
F_70 ( V_23 -> V_25 ) ) ;
for ( V_84 = 0 ; V_84 < V_8 ; V_84 ++ ) {
if ( V_65 & ( 1 << V_84 ) ) {
F_67 ( L_9 ,
V_122 [ V_84 ] , V_9 [ V_84 ] ) ;
}
}
V_121:
F_68 () ;
return 0 ;
}
