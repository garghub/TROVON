static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 , struct V_5 * V_6 )
{
if ( V_2 -> V_7 -> V_8 ) {
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_11 = V_12 [ V_4 ] . V_13 ;
T_1 V_14 = V_15 * V_11 ;
T_2 V_16 = F_3 ( V_2 ) +
( V_6 -> V_17 << V_18 ) ;
const int V_19 = 1 + ( ( V_10 -> V_20 << V_4 ) / V_15 ) ;
if ( V_19 > 1 ) {
int V_21 ;
for ( V_21 = V_11 ; V_21 > 0 ; V_21 -- ) {
F_4 ( V_2 -> V_7 -> V_8 ,
V_16 , V_15 , 1 ) ;
V_16 += V_15 * V_19 ;
}
} else {
F_4 ( V_2 -> V_7 -> V_8 , V_16 , V_14 , 1 ) ;
}
}
V_6 -> V_2 = NULL ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( V_10 -> V_22 & V_23 ) {
enum V_3 V_4 = F_6 ( V_10 -> V_22 ) ;
int V_21 ;
if ( ! V_12 )
return;
for ( V_21 = 0 ; V_21 < V_24 ; V_21 ++ ) {
struct V_5 * V_6 = & V_12 [ V_4 ] . V_6 [ V_21 ] ;
if ( V_6 -> V_2 == V_2 )
F_1 ( V_2 , V_4 , V_6 ) ;
}
}
}
static inline bool F_7 ( struct V_1 * V_2 )
{
return V_2 -> V_25 != NULL ;
}
static inline bool F_8 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
return F_7 ( V_2 ) &&
( ( V_10 -> V_22 & V_26 ) == V_27 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_28 * V_7 = V_2 -> V_7 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_29 * * V_30 ;
int V_21 , V_31 = V_2 -> V_14 >> V_18 ;
T_3 * V_32 ;
F_10 ( V_10 -> V_30 ) ;
V_30 = F_11 ( V_2 , V_33 ) ;
if ( F_12 ( V_30 ) ) {
F_13 ( V_2 -> V_7 -> V_7 , L_1 , F_14 ( V_30 ) ) ;
return F_14 ( V_30 ) ;
}
if ( V_10 -> V_22 & ( V_34 | V_35 ) ) {
V_32 = F_15 ( V_31 * sizeof( V_32 ) , V_33 ) ;
for ( V_21 = 0 ; V_21 < V_31 ; V_21 ++ ) {
V_32 [ V_21 ] = F_16 ( V_7 -> V_7 , V_30 [ V_21 ] ,
0 , V_15 , V_36 ) ;
}
} else {
V_32 = F_17 ( V_31 * sizeof( V_32 ) , V_33 ) ;
}
V_10 -> V_32 = V_32 ;
V_10 -> V_30 = V_30 ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( V_10 -> V_22 & ( V_34 | V_35 ) ) {
int V_21 , V_31 = V_2 -> V_14 >> V_18 ;
for ( V_21 = 0 ; V_21 < V_31 ; V_21 ++ ) {
F_19 ( V_2 -> V_7 -> V_7 , V_10 -> V_32 [ V_21 ] ,
V_15 , V_36 ) ;
}
}
F_20 ( V_10 -> V_32 ) ;
V_10 -> V_32 = NULL ;
F_21 ( V_2 , V_10 -> V_30 , true , false ) ;
V_10 -> V_30 = NULL ;
}
T_4 F_22 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_22 ;
}
static T_5 F_3 ( struct V_1 * V_2 )
{
struct V_28 * V_7 = V_2 -> V_7 ;
F_10 ( ! F_23 ( & V_7 -> V_37 ) ) ;
if ( ! V_2 -> V_38 . V_39 ) {
T_1 V_14 = F_24 ( V_2 ) ;
int V_40 = F_25 ( V_2 , V_14 ) ;
if ( V_40 ) {
F_13 ( V_7 -> V_7 , L_2 ) ;
return 0 ;
}
}
return ( T_5 ) V_2 -> V_38 . V_41 . V_42 << V_18 ;
}
T_5 F_26 ( struct V_1 * V_2 )
{
T_5 V_43 ;
F_27 ( & V_2 -> V_7 -> V_37 ) ;
V_43 = F_3 ( V_2 ) ;
F_28 ( & V_2 -> V_7 -> V_37 ) ;
return V_43 ;
}
T_1 F_24 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
T_1 V_14 = V_2 -> V_14 ;
if ( V_10 -> V_22 & V_23 ) {
V_14 = F_29 ( F_6 ( V_10 -> V_22 ) ,
V_10 -> V_20 , V_10 -> V_13 ) ;
}
return V_14 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_44 * V_45 , struct V_46 * V_47 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
unsigned long V_48 ;
T_6 V_49 ;
V_49 = ( ( unsigned long ) V_47 -> V_50 -
V_45 -> V_51 ) >> V_18 ;
if ( V_10 -> V_30 ) {
F_31 ( V_2 , V_49 ) ;
V_48 = F_32 ( V_10 -> V_30 [ V_49 ] ) ;
} else {
F_33 ( ! ( V_10 -> V_22 & V_52 ) ) ;
V_48 = ( V_10 -> V_53 >> V_18 ) + V_49 ;
}
F_34 ( L_3 , V_47 -> V_50 ,
V_48 , V_48 << V_18 ) ;
return F_35 ( V_45 , ( unsigned long ) V_47 -> V_50 , V_48 ) ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_44 * V_45 , struct V_46 * V_47 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_5 * V_6 ;
enum V_3 V_4 = F_6 ( V_10 -> V_22 ) ;
struct V_29 * V_30 [ 64 ] ;
unsigned long V_48 ;
T_6 V_49 , V_54 ;
void T_7 * V_55 ;
int V_21 , V_40 , V_56 ;
const int V_11 = V_12 [ V_4 ] . V_13 ;
const int V_57 = V_12 [ V_4 ] . V_58 ;
const int V_19 = 1 + ( ( V_10 -> V_20 << V_4 ) / V_15 ) ;
V_49 = ( ( unsigned long ) V_47 -> V_50 -
V_45 -> V_51 ) >> V_18 ;
V_54 = F_37 ( V_49 , V_19 << V_57 ) ;
V_56 = V_10 -> V_20 >> V_12 [ V_4 ] . V_59 ;
V_55 = V_47 -> V_50 - ( ( V_49 - V_54 ) << V_18 ) ;
V_6 = & V_12 [ V_4 ] . V_6 [ V_12 [ V_4 ] . V_60 ] ;
if ( V_6 -> V_2 )
F_1 ( V_6 -> V_2 , V_4 , V_6 ) ;
V_6 -> V_2 = V_2 ;
V_6 -> V_17 = V_54 ;
V_54 = ( V_54 >> V_57 ) * V_56 ;
if ( V_19 > 1 ) {
int V_16 = V_49 % V_19 ;
V_6 -> V_17 += V_16 ;
V_54 /= V_19 ;
V_56 = F_38 ( V_56 - ( V_16 << V_57 ) , V_11 ) ;
V_54 += V_16 << V_57 ;
V_55 += V_16 << V_18 ;
}
memcpy ( V_30 , & V_10 -> V_30 [ V_54 ] ,
sizeof( struct V_29 * ) * V_56 ) ;
memset ( V_30 + V_56 , 0 ,
sizeof( struct V_29 * ) * ( V_11 - V_56 ) ) ;
V_40 = F_39 ( V_6 -> V_61 , V_30 , F_40 ( V_30 ) , 0 , true ) ;
if ( V_40 ) {
F_13 ( V_2 -> V_7 -> V_7 , L_4 , V_40 ) ;
return V_40 ;
}
V_48 = V_6 -> V_53 >> V_18 ;
F_34 ( L_3 , V_47 -> V_50 ,
V_48 , V_48 << V_18 ) ;
for ( V_21 = V_11 ; V_21 > 0 ; V_21 -- ) {
F_35 ( V_45 , ( unsigned long ) V_55 , V_48 ) ;
V_48 += V_12 [ V_4 ] . V_62 ;
V_55 += V_15 * V_19 ;
}
V_12 [ V_4 ] . V_60 = ( V_12 [ V_4 ] . V_60 + 1 ) % V_24 ;
return 0 ;
}
int F_41 ( struct V_44 * V_45 , struct V_46 * V_47 )
{
struct V_1 * V_2 = V_45 -> V_63 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_28 * V_7 = V_2 -> V_7 ;
struct V_29 * * V_30 ;
int V_40 ;
F_27 ( & V_7 -> V_37 ) ;
V_40 = F_42 ( V_2 , & V_30 ) ;
if ( V_40 ) {
goto V_64;
}
if ( V_10 -> V_22 & V_23 )
V_40 = F_36 ( V_2 , V_45 , V_47 ) ;
else
V_40 = F_30 ( V_2 , V_45 , V_47 ) ;
V_64:
F_28 ( & V_7 -> V_37 ) ;
switch ( V_40 ) {
case 0 :
case - V_65 :
case - V_66 :
return V_67 ;
case - V_68 :
return V_69 ;
default:
return V_70 ;
}
}
int F_43 ( struct V_71 * V_25 , struct V_44 * V_45 )
{
int V_40 ;
V_40 = F_44 ( V_25 , V_45 ) ;
if ( V_40 ) {
F_45 ( L_5 , V_40 ) ;
return V_40 ;
}
return F_46 ( V_45 -> V_63 , V_45 ) ;
}
int F_46 ( struct V_1 * V_2 ,
struct V_44 * V_45 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
V_45 -> V_72 &= ~ V_73 ;
V_45 -> V_72 |= V_74 ;
if ( V_10 -> V_22 & V_34 ) {
V_45 -> V_75 = F_47 ( F_48 ( V_45 -> V_72 ) ) ;
} else if ( V_10 -> V_22 & V_35 ) {
V_45 -> V_75 = F_49 ( F_48 ( V_45 -> V_72 ) ) ;
} else {
if ( F_10 ( ! V_2 -> V_25 ) )
return - V_76 ;
F_50 ( V_45 -> V_77 ) ;
F_51 ( V_2 -> V_25 ) ;
V_45 -> V_78 = 0 ;
V_45 -> V_77 = V_2 -> V_25 ;
V_45 -> V_75 = F_48 ( V_45 -> V_72 ) ;
}
return 0 ;
}
int F_52 ( struct V_79 * V_71 , struct V_28 * V_7 ,
struct V_80 * args )
{
union V_81 V_82 ;
args -> V_83 = F_53 ( args -> V_83 , args -> V_20 , args -> V_84 ) ;
args -> V_14 = F_54 ( args -> V_83 * args -> V_13 ) ;
V_82 = (union V_81 ) {
. V_85 = args -> V_14 ,
} ;
return F_55 ( V_7 , V_71 , V_82 ,
V_86 | V_34 , & args -> V_87 ) ;
}
int F_56 ( struct V_79 * V_71 , struct V_28 * V_7 ,
T_4 V_87 )
{
return F_57 ( V_71 , V_87 ) ;
}
int F_58 ( struct V_79 * V_71 , struct V_28 * V_7 ,
T_4 V_87 , T_5 * V_43 )
{
struct V_1 * V_2 ;
int V_40 = 0 ;
V_2 = F_59 ( V_7 , V_71 , V_87 ) ;
if ( V_2 == NULL ) {
V_40 = - V_88 ;
goto V_64;
}
* V_43 = F_26 ( V_2 ) ;
F_60 ( V_2 ) ;
V_64:
return V_40 ;
}
int F_61 ( struct V_1 * V_2 , T_4 V_89 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
T_4 V_31 = V_2 -> V_14 >> V_18 ;
int V_40 = 0 ;
if ( V_89 > V_31 ) {
F_13 ( V_2 -> V_7 -> V_7 , L_6 , V_89 ) ;
return - V_76 ;
}
V_10 -> V_89 = V_89 ;
F_27 ( & V_2 -> V_7 -> V_37 ) ;
if ( V_10 -> V_61 ) {
struct V_29 * * V_30 ;
V_40 = F_42 ( V_2 , & V_30 ) ;
if ( V_40 )
goto V_64;
V_40 = F_39 ( V_10 -> V_61 , V_30 , V_31 , V_89 , true ) ;
if ( V_40 )
F_13 ( V_2 -> V_7 -> V_7 , L_7 , V_40 ) ;
}
V_64:
F_28 ( & V_2 -> V_7 -> V_37 ) ;
return V_40 ;
}
void F_31 ( struct V_1 * V_2 , int V_49 )
{
struct V_28 * V_7 = V_2 -> V_7 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( F_8 ( V_2 ) && V_10 -> V_32 [ V_49 ] ) {
F_19 ( V_7 -> V_7 , V_10 -> V_32 [ V_49 ] ,
V_15 , V_36 ) ;
V_10 -> V_32 [ V_49 ] = 0 ;
}
}
void F_62 ( struct V_1 * V_2 ,
enum V_90 V_91 )
{
struct V_28 * V_7 = V_2 -> V_7 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( F_8 ( V_2 ) ) {
int V_21 , V_31 = V_2 -> V_14 >> V_18 ;
struct V_29 * * V_30 = V_10 -> V_30 ;
bool V_92 = false ;
for ( V_21 = 0 ; V_21 < V_31 ; V_21 ++ ) {
if ( ! V_10 -> V_32 [ V_21 ] ) {
V_10 -> V_32 [ V_21 ] = F_16 ( V_7 -> V_7 , V_30 [ V_21 ] , 0 ,
V_15 , V_36 ) ;
V_92 = true ;
}
}
if ( V_92 ) {
F_4 ( V_2 -> V_25 -> V_93 , 0 ,
F_24 ( V_2 ) , 1 ) ;
}
}
}
int F_63 ( struct V_1 * V_2 ,
T_3 * V_53 , bool V_94 )
{
struct V_95 * V_96 = V_2 -> V_7 -> V_97 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_40 = 0 ;
F_27 ( & V_2 -> V_7 -> V_37 ) ;
if ( V_94 && F_7 ( V_2 ) && V_96 -> V_98 ) {
if ( V_10 -> V_99 == 0 ) {
struct V_29 * * V_30 ;
T_4 V_31 = V_2 -> V_14 >> V_18 ;
enum V_3 V_4 = F_6 ( V_10 -> V_22 ) ;
struct V_100 * V_61 ;
F_33 ( V_10 -> V_61 ) ;
V_40 = F_42 ( V_2 , & V_30 ) ;
if ( V_40 )
goto V_64;
if ( V_10 -> V_22 & V_23 ) {
V_61 = F_64 ( V_4 ,
V_10 -> V_20 ,
V_10 -> V_13 , 0 ) ;
} else {
V_61 = F_65 ( V_2 -> V_14 ) ;
}
if ( F_12 ( V_61 ) ) {
V_40 = F_14 ( V_61 ) ;
F_13 ( V_2 -> V_7 -> V_7 ,
L_8 , V_40 , V_4 ) ;
goto V_64;
}
V_40 = F_39 ( V_61 , V_30 , V_31 ,
V_10 -> V_89 , true ) ;
if ( V_40 ) {
F_66 ( V_61 ) ;
F_13 ( V_2 -> V_7 -> V_7 ,
L_9 , V_40 ) ;
goto V_64;
}
V_10 -> V_53 = F_67 ( V_61 ) ;
V_10 -> V_61 = V_61 ;
F_45 ( L_10 , V_10 -> V_53 ) ;
}
V_10 -> V_99 ++ ;
* V_53 = V_10 -> V_53 ;
} else if ( V_10 -> V_22 & V_52 ) {
* V_53 = V_10 -> V_53 ;
} else {
V_40 = - V_76 ;
goto V_64;
}
V_64:
F_28 ( & V_2 -> V_7 -> V_37 ) ;
return V_40 ;
}
int F_68 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_40 = 0 ;
F_27 ( & V_2 -> V_7 -> V_37 ) ;
if ( V_10 -> V_99 > 0 ) {
V_10 -> V_99 -- ;
if ( V_10 -> V_99 == 0 ) {
V_40 = F_69 ( V_10 -> V_61 ) ;
if ( V_40 ) {
F_13 ( V_2 -> V_7 -> V_7 ,
L_11 , V_40 ) ;
goto V_64;
}
V_40 = F_66 ( V_10 -> V_61 ) ;
if ( V_40 ) {
F_13 ( V_2 -> V_7 -> V_7 ,
L_12 , V_40 ) ;
}
V_10 -> V_61 = NULL ;
}
}
V_64:
F_28 ( & V_2 -> V_7 -> V_37 ) ;
return V_40 ;
}
static int F_42 ( struct V_1 * V_2 , struct V_29 * * * V_30 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_40 = 0 ;
if ( F_7 ( V_2 ) && ! V_10 -> V_30 ) {
V_40 = F_9 ( V_2 ) ;
if ( V_40 ) {
F_13 ( V_2 -> V_7 -> V_7 , L_13 ) ;
return V_40 ;
}
}
* V_30 = V_10 -> V_30 ;
return 0 ;
}
int F_70 ( struct V_1 * V_2 , struct V_29 * * * V_30 ,
bool V_94 )
{
int V_40 ;
if ( ! V_94 ) {
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( ! V_10 -> V_30 )
return - V_68 ;
* V_30 = V_10 -> V_30 ;
return 0 ;
}
F_27 ( & V_2 -> V_7 -> V_37 ) ;
V_40 = F_42 ( V_2 , V_30 ) ;
F_28 ( & V_2 -> V_7 -> V_37 ) ;
return V_40 ;
}
int F_71 ( struct V_1 * V_2 )
{
return 0 ;
}
void * F_72 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
F_10 ( ! F_23 ( & V_2 -> V_7 -> V_37 ) ) ;
if ( ! V_10 -> V_55 ) {
struct V_29 * * V_30 ;
int V_40 = F_42 ( V_2 , & V_30 ) ;
if ( V_40 )
return F_73 ( V_40 ) ;
V_10 -> V_55 = F_74 ( V_30 , V_2 -> V_14 >> V_18 ,
V_101 , F_47 ( V_102 ) ) ;
}
return V_10 -> V_55 ;
}
void F_75 ( struct V_1 * V_2 , struct V_103 * V_19 )
{
struct V_28 * V_7 = V_2 -> V_7 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
T_5 V_16 = 0 ;
F_10 ( ! F_23 ( & V_7 -> V_37 ) ) ;
if ( V_2 -> V_38 . V_39 )
V_16 = ( T_5 ) V_2 -> V_38 . V_41 . V_42 ;
F_76 ( V_19 , L_14 ,
V_10 -> V_22 , V_2 -> V_104 , V_2 -> V_105 . V_105 . V_106 ,
V_16 , V_10 -> V_53 , V_10 -> V_99 ,
V_10 -> V_55 , V_10 -> V_89 ) ;
if ( V_10 -> V_22 & V_23 ) {
F_76 ( V_19 , L_15 , V_10 -> V_20 , V_10 -> V_13 ) ;
if ( V_10 -> V_61 ) {
struct V_107 * V_108 = & V_10 -> V_61 -> V_108 ;
F_76 ( V_19 , L_16 ,
V_108 -> V_109 . V_110 , V_108 -> V_109 . V_111 ,
V_108 -> V_112 . V_110 , V_108 -> V_112 . V_111 ) ;
}
} else {
F_76 ( V_19 , L_17 , V_2 -> V_14 ) ;
}
F_76 ( V_19 , L_18 ) ;
}
void F_77 ( struct V_113 * V_114 , struct V_103 * V_19 )
{
struct V_9 * V_10 ;
int V_115 = 0 ;
T_1 V_14 = 0 ;
F_78 (omap_obj, list, mm_list) {
struct V_1 * V_2 = & V_10 -> V_116 ;
F_76 ( V_19 , L_19 ) ;
F_75 ( V_2 , V_19 ) ;
V_115 ++ ;
V_14 += V_2 -> V_14 ;
}
F_76 ( V_19 , L_20 , V_115 , V_14 ) ;
}
static inline bool F_79 ( struct V_117 * V_118 )
{
struct V_9 * V_10 = V_118 -> V_10 ;
if ( ( V_118 -> V_119 & V_120 ) &&
( V_10 -> V_121 -> V_122 < V_118 -> V_123 ) )
return true ;
if ( ( V_118 -> V_119 & V_124 ) &&
( V_10 -> V_121 -> V_125 < V_118 -> V_126 ) )
return true ;
return false ;
}
static void F_80 ( void )
{
struct V_117 * V_118 , * V_11 ;
F_81 (waiter, n, &waiters, list) {
if ( ! F_79 ( V_118 ) ) {
F_82 ( & V_118 -> V_114 ) ;
F_83 ( L_21 , V_118 ) ;
V_118 -> V_127 ( V_118 -> V_128 ) ;
F_20 ( V_118 ) ;
}
}
}
static inline int F_84 ( struct V_1 * V_2 ,
enum V_129 V_119 , bool V_130 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_40 = 0 ;
F_85 ( & V_131 ) ;
if ( ! V_10 -> V_121 ) {
V_10 -> V_121 = F_17 ( sizeof( * V_10 -> V_121 ) , V_132 ) ;
if ( ! V_10 -> V_121 ) {
V_40 = - V_68 ;
goto V_133;
}
}
if ( V_130 ) {
if ( V_119 & V_120 )
V_10 -> V_121 -> V_134 ++ ;
if ( V_119 & V_124 )
V_10 -> V_121 -> V_135 ++ ;
} else {
if ( V_119 & V_120 )
V_10 -> V_121 -> V_122 ++ ;
if ( V_119 & V_124 )
V_10 -> V_121 -> V_125 ++ ;
F_80 () ;
}
V_133:
F_86 ( & V_131 ) ;
return V_40 ;
}
void F_87 ( void )
{
F_85 ( & V_131 ) ;
F_80 () ;
F_86 ( & V_131 ) ;
}
int F_88 ( struct V_1 * V_2 , enum V_129 V_119 )
{
return F_84 ( V_2 , V_119 , true ) ;
}
int F_89 ( struct V_1 * V_2 , enum V_129 V_119 )
{
return F_84 ( V_2 , V_119 , false ) ;
}
static void F_90 ( void * V_128 )
{
struct V_136 * * V_137 = V_128 ;
* V_137 = NULL ;
F_91 ( & V_138 ) ;
}
int F_92 ( struct V_1 * V_2 , enum V_129 V_119 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_40 = 0 ;
if ( V_10 -> V_121 ) {
struct V_136 * V_137 = V_139 ;
struct V_117 * V_118 =
F_17 ( sizeof( * V_118 ) , V_33 ) ;
if ( ! V_118 ) {
return - V_68 ;
}
V_118 -> V_10 = V_10 ;
V_118 -> V_119 = V_119 ;
V_118 -> V_123 = V_10 -> V_121 -> V_134 ;
V_118 -> V_126 = V_10 -> V_121 -> V_135 ;
V_118 -> V_127 = F_90 ;
V_118 -> V_128 = & V_137 ;
F_85 ( & V_131 ) ;
if ( F_79 ( V_118 ) ) {
F_83 ( L_22 , V_118 ) ;
F_93 ( & V_118 -> V_114 , & V_140 ) ;
F_86 ( & V_131 ) ;
V_40 = F_94 ( V_138 ,
( V_137 == NULL ) ) ;
F_85 ( & V_131 ) ;
if ( V_137 ) {
F_83 ( L_23 , V_118 ) ;
F_82 ( & V_118 -> V_114 ) ;
V_137 = NULL ;
} else {
V_118 = NULL ;
}
}
F_86 ( & V_131 ) ;
if ( V_118 ) {
F_20 ( V_118 ) ;
}
}
return V_40 ;
}
int F_95 ( struct V_1 * V_2 , enum V_129 V_119 ,
void (* F_96)( void * V_128 ) , void * V_128 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( V_10 -> V_121 ) {
struct V_117 * V_118 =
F_17 ( sizeof( * V_118 ) , V_132 ) ;
if ( ! V_118 ) {
return - V_68 ;
}
V_118 -> V_10 = V_10 ;
V_118 -> V_119 = V_119 ;
V_118 -> V_123 = V_10 -> V_121 -> V_134 ;
V_118 -> V_126 = V_10 -> V_121 -> V_135 ;
V_118 -> V_127 = F_96 ;
V_118 -> V_128 = V_128 ;
F_85 ( & V_131 ) ;
if ( F_79 ( V_118 ) ) {
F_83 ( L_22 , V_118 ) ;
F_93 ( & V_118 -> V_114 , & V_140 ) ;
F_86 ( & V_131 ) ;
return 0 ;
}
F_86 ( & V_131 ) ;
}
F_96 ( V_128 ) ;
return 0 ;
}
int F_97 ( struct V_1 * V_2 , void * V_141 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_40 = 0 ;
F_85 ( & V_131 ) ;
if ( ( V_10 -> V_22 & V_142 ) && ! V_141 ) {
V_141 = F_17 ( sizeof( * V_10 -> V_121 ) , V_132 ) ;
if ( ! V_141 ) {
V_40 = - V_68 ;
goto V_133;
}
memcpy ( V_141 , V_10 -> V_121 , sizeof( * V_10 -> V_121 ) ) ;
V_10 -> V_22 &= ~ V_142 ;
V_10 -> V_121 = V_141 ;
} else if ( V_141 && ! ( V_10 -> V_22 & V_142 ) ) {
if ( V_10 -> V_121 ) {
memcpy ( V_141 , V_10 -> V_121 , sizeof( * V_10 -> V_121 ) ) ;
F_20 ( V_10 -> V_121 ) ;
}
V_10 -> V_22 |= V_142 ;
V_10 -> V_121 = V_141 ;
}
V_133:
F_86 ( & V_131 ) ;
return V_40 ;
}
int F_98 ( struct V_1 * V_2 )
{
return - V_76 ;
}
void F_99 ( struct V_1 * V_2 )
{
struct V_28 * V_7 = V_2 -> V_7 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
F_5 ( V_2 ) ;
F_10 ( ! F_23 ( & V_7 -> V_37 ) ) ;
F_82 ( & V_10 -> V_143 ) ;
if ( V_2 -> V_38 . V_39 ) {
F_100 ( V_2 ) ;
}
F_10 ( V_10 -> V_99 > 0 ) ;
if ( ! ( V_10 -> V_22 & V_144 ) ) {
if ( V_10 -> V_30 ) {
F_18 ( V_2 ) ;
}
if ( ! F_7 ( V_2 ) ) {
F_101 ( V_7 -> V_7 , V_2 -> V_14 ,
V_10 -> V_55 , V_10 -> V_53 ) ;
} else if ( V_10 -> V_55 ) {
F_102 ( V_10 -> V_55 ) ;
}
}
if ( ! ( V_10 -> V_22 & V_142 ) ) {
F_20 ( V_10 -> V_121 ) ;
}
F_103 ( V_2 ) ;
F_20 ( V_2 ) ;
}
int F_55 ( struct V_28 * V_7 , struct V_79 * V_71 ,
union V_81 V_82 , T_4 V_22 , T_4 * V_87 )
{
struct V_1 * V_2 ;
int V_40 ;
V_2 = F_104 ( V_7 , V_82 , V_22 ) ;
if ( ! V_2 )
return - V_68 ;
V_40 = F_105 ( V_71 , V_2 , V_87 ) ;
if ( V_40 ) {
F_103 ( V_2 ) ;
F_20 ( V_2 ) ;
return V_40 ;
}
F_60 ( V_2 ) ;
return 0 ;
}
struct V_1 * F_104 ( struct V_28 * V_7 ,
union V_81 V_82 , T_4 V_22 )
{
struct V_95 * V_96 = V_7 -> V_97 ;
struct V_9 * V_10 ;
struct V_1 * V_2 = NULL ;
T_1 V_14 ;
int V_40 ;
if ( V_22 & V_23 ) {
if ( ! V_12 ) {
F_13 ( V_7 -> V_7 , L_24 ) ;
goto V_64;
}
V_22 &= ~ V_86 ;
V_22 &= ~ ( V_27 | V_35 ) ;
V_22 |= V_34 ;
F_106 ( F_6 ( V_22 ) ,
& V_82 . V_145 . V_20 , & V_82 . V_145 . V_13 ) ;
V_14 = F_107 ( F_6 ( V_22 ) ,
V_82 . V_145 . V_20 , V_82 . V_145 . V_13 ) ;
} else {
V_14 = F_54 ( V_82 . V_85 ) ;
}
V_10 = F_17 ( sizeof( * V_10 ) , V_33 ) ;
if ( ! V_10 ) {
F_13 ( V_7 -> V_7 , L_25 ) ;
goto V_64;
}
F_108 ( & V_10 -> V_143 , & V_96 -> V_146 ) ;
V_2 = & V_10 -> V_116 ;
if ( ( V_22 & V_86 ) && ! V_96 -> V_98 ) {
V_10 -> V_55 = F_109 ( V_7 -> V_7 , V_14 ,
& V_10 -> V_53 , V_33 ) ;
if ( V_10 -> V_55 ) {
V_22 |= V_52 ;
}
}
V_10 -> V_22 = V_22 ;
if ( V_22 & V_23 ) {
V_10 -> V_20 = V_82 . V_145 . V_20 ;
V_10 -> V_13 = V_82 . V_145 . V_13 ;
}
if ( V_22 & ( V_52 | V_144 ) ) {
V_40 = F_110 ( V_7 , V_2 , V_14 ) ;
} else {
V_40 = F_111 ( V_7 , V_2 , V_14 ) ;
}
if ( V_40 ) {
goto V_64;
}
return V_2 ;
V_64:
if ( V_2 ) {
F_99 ( V_2 ) ;
}
return NULL ;
}
void F_112 ( struct V_28 * V_7 )
{
struct V_95 * V_96 = V_7 -> V_97 ;
const enum V_3 V_147 [] = {
V_148 , V_149 , V_150
} ;
int V_21 , V_151 ;
if ( ! F_113 () ) {
F_114 ( V_7 -> V_7 , L_26 ) ;
return;
}
V_12 = F_17 ( 3 * sizeof( * V_12 ) , V_33 ) ;
if ( ! V_12 ) {
F_114 ( V_7 -> V_7 , L_27 ) ;
return;
}
for ( V_21 = 0 ; V_21 < F_40 ( V_147 ) ; V_21 ++ ) {
T_8 V_152 = 1 , V_153 = V_15 >> V_21 ;
F_106 ( V_147 [ V_21 ] , & V_153 , & V_152 ) ;
V_12 [ V_21 ] . V_13 = V_152 ;
V_12 [ V_21 ] . V_58 = F_115 ( V_152 ) ;
V_12 [ V_21 ] . V_62 = F_116 ( V_147 [ V_21 ] ) >> V_18 ;
V_12 [ V_21 ] . V_59 = F_115 ( ( V_15 / V_152 ) >> V_21 ) ;
for ( V_151 = 0 ; V_151 < V_24 ; V_151 ++ ) {
struct V_5 * V_6 = & V_12 [ V_21 ] . V_6 [ V_151 ] ;
struct V_100 * V_61 =
F_64 ( V_147 [ V_21 ] , V_153 , V_152 ,
V_15 ) ;
if ( F_12 ( V_61 ) ) {
F_13 ( V_7 -> V_7 ,
L_28 ,
V_21 , V_151 , F_14 ( V_61 ) ) ;
return;
}
V_6 -> V_53 = F_67 ( V_61 ) ;
V_6 -> V_61 = V_61 ;
F_45 ( L_29 , V_21 , V_151 , V_153 , V_152 ,
V_6 -> V_53 ,
V_12 [ V_21 ] . V_62 << V_18 ) ;
}
}
V_96 -> V_98 = true ;
}
void F_117 ( struct V_28 * V_7 )
{
F_20 ( V_12 ) ;
}
