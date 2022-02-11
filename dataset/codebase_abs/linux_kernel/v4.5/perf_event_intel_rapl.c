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
static void F_35 ( int V_79 )
{
struct V_22 * V_23 = F_36 ( V_22 , V_79 ) ;
int V_80 , V_81 = F_37 ( V_79 ) ;
int V_82 = - 1 ;
F_38 (i) {
if ( V_80 == V_79 )
continue;
if ( V_81 == F_37 ( V_80 ) ) {
V_82 = V_80 ;
break;
}
}
if ( F_39 ( V_79 , & V_78 ) && V_82 >= 0 )
F_40 ( V_82 , & V_78 ) ;
F_41 ( F_42 ( & V_78 ) ) ;
if ( V_82 >= 0 )
F_43 ( V_23 -> V_23 , V_79 , V_82 ) ;
F_12 ( V_23 ) ;
}
static void F_44 ( int V_79 )
{
int V_80 , V_81 = F_37 ( V_79 ) ;
F_45 (i, &rapl_cpu_mask) {
if ( V_81 == F_37 ( V_80 ) )
return;
}
F_40 ( V_79 , & V_78 ) ;
}
static T_4 void F_46 ( void )
{
V_9 [ V_60 ] = 16 ;
}
static int F_47 ( int V_79 )
{
struct V_22 * V_23 = F_36 ( V_22 , V_79 ) ;
int V_81 = F_37 ( V_79 ) ;
T_1 V_83 ;
if ( V_23 )
return 0 ;
if ( V_81 < 0 )
return - 1 ;
V_23 = F_48 ( sizeof( * V_23 ) , V_84 , F_49 ( V_79 ) ) ;
if ( ! V_23 )
return - 1 ;
F_50 ( & V_23 -> V_31 ) ;
F_51 ( & V_23 -> V_40 ) ;
V_23 -> V_23 = & V_50 ;
if ( V_9 [ 0 ] < 32 )
V_83 = ( 1000 / ( 2 * 100 ) ) * ( 1ULL << ( 32 - V_9 [ 0 ] - 1 ) ) ;
else
V_83 = 2 ;
V_23 -> V_25 = F_52 ( V_83 ) ;
F_20 ( V_23 ) ;
F_36 ( V_22 , V_79 ) = V_23 ;
F_36 ( V_85 , V_79 ) = NULL ;
return 0 ;
}
static void F_53 ( int V_79 )
{
struct V_22 * V_23 = F_36 ( V_85 , V_79 ) ;
F_54 ( V_23 ) ;
F_36 ( V_85 , V_79 ) = NULL ;
}
static int F_55 ( int V_79 )
{
struct V_22 * V_23 = F_36 ( V_22 , V_79 ) ;
if ( ! V_23 )
return 0 ;
F_36 ( V_22 , V_79 ) = NULL ;
F_36 ( V_85 , V_79 ) = V_23 ;
return 0 ;
}
static int F_56 ( struct V_86 * V_87 ,
unsigned long V_88 , void * V_89 )
{
unsigned int V_79 = ( long ) V_89 ;
switch ( V_88 & ~ V_90 ) {
case V_91 :
F_47 ( V_79 ) ;
break;
case V_92 :
F_44 ( V_79 ) ;
break;
case V_93 :
case V_94 :
F_55 ( V_79 ) ;
break;
case V_95 :
case V_96 :
F_53 ( V_79 ) ;
break;
case V_97 :
F_35 ( V_79 ) ;
break;
default:
break;
}
return V_98 ;
}
static int F_57 ( void )
{
T_1 V_99 ;
int V_80 ;
if ( F_58 ( V_100 , & V_99 ) )
return - 1 ;
for ( V_80 = 0 ; V_80 < V_8 ; V_80 ++ )
V_9 [ V_80 ] = ( V_99 >> 8 ) & 0x1FULL ;
return 0 ;
}
static int T_4 F_59 ( void )
{
struct V_22 * V_23 ;
int V_79 , V_49 ;
struct V_101 * V_102 ;
int V_80 ;
if ( ! F_60 ( V_103 ) )
return 0 ;
switch ( V_104 . V_105 ) {
case 42 :
case 58 :
V_65 = V_106 ;
V_107 . V_108 = V_109 ;
break;
case 63 :
F_61 ( F_46 ) ;
V_65 = V_110 ;
V_107 . V_108 = V_111 ;
break;
case 60 :
case 69 :
case 61 :
V_65 = V_112 ;
V_107 . V_108 = V_113 ;
break;
case 45 :
case 62 :
V_65 = V_110 ;
V_107 . V_108 = V_111 ;
break;
case 87 :
F_61 ( F_46 ) ;
V_65 = V_114 ;
V_107 . V_108 = V_115 ;
default:
return 0 ;
}
V_49 = F_57 () ;
if ( V_49 )
return V_49 ;
for ( V_102 = V_116 ; V_102 ; V_102 = V_102 -> V_117 )
V_102 -> V_118 () ;
F_62 () ;
F_38 (cpu) {
V_49 = F_47 ( V_79 ) ;
if ( V_49 )
goto V_119;
F_44 ( V_79 ) ;
}
F_63 ( F_56 ) ;
V_49 = F_64 ( & V_50 , L_2 , - 1 ) ;
if ( F_41 ( V_49 ) ) {
F_65 ( L_3 , V_49 ) ;
F_66 () ;
return - 1 ;
}
V_23 = F_15 ( V_22 ) ;
F_65 ( L_4
L_5
L_6
L_7 ,
F_67 ( V_65 ) ,
F_68 ( V_23 -> V_25 ) ) ;
for ( V_80 = 0 ; V_80 < V_8 ; V_80 ++ ) {
if ( V_65 & ( 1 << V_80 ) ) {
F_65 ( L_8 ,
V_120 [ V_80 ] , V_9 [ V_80 ] ) ;
}
}
V_119:
F_66 () ;
return 0 ;
}
