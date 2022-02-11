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
static int F_8 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_26 * * V_27 ;
F_9 ( V_10 -> V_27 ) ;
V_27 = F_10 ( V_2 , V_28 ) ;
if ( F_11 ( V_27 ) ) {
F_12 ( V_2 -> V_7 -> V_7 , L_1 , F_13 ( V_27 ) ) ;
return F_13 ( V_27 ) ;
}
if ( V_10 -> V_22 & ( V_29 | V_30 ) ) {
int V_21 , V_31 = V_2 -> V_14 >> V_18 ;
T_3 * V_32 = F_14 ( V_31 * sizeof( V_32 ) , V_28 ) ;
for ( V_21 = 0 ; V_21 < V_31 ; V_21 ++ ) {
V_32 [ V_21 ] = F_15 ( V_2 -> V_7 -> V_7 , V_27 [ V_21 ] ,
0 , V_15 , V_33 ) ;
}
V_10 -> V_32 = V_32 ;
}
V_10 -> V_27 = V_27 ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( V_10 -> V_22 & ( V_29 | V_30 ) ) {
int V_21 , V_31 = V_2 -> V_14 >> V_18 ;
for ( V_21 = 0 ; V_21 < V_31 ; V_21 ++ ) {
F_17 ( V_2 -> V_7 -> V_7 , V_10 -> V_32 [ V_21 ] ,
V_15 , V_33 ) ;
}
F_18 ( V_10 -> V_32 ) ;
V_10 -> V_32 = NULL ;
}
F_19 ( V_2 , V_10 -> V_27 , true , false ) ;
V_10 -> V_27 = NULL ;
}
static T_4 F_3 ( struct V_1 * V_2 )
{
struct V_34 * V_7 = V_2 -> V_7 ;
F_9 ( ! F_20 ( & V_7 -> V_35 ) ) ;
if ( ! V_2 -> V_36 . V_37 ) {
T_1 V_14 = F_21 ( V_2 ) ;
int V_38 = F_22 ( V_2 , V_14 ) ;
if ( V_38 ) {
F_12 ( V_7 -> V_7 , L_2 ) ;
return 0 ;
}
}
return ( T_4 ) V_2 -> V_36 . V_39 . V_40 << V_18 ;
}
T_4 F_23 ( struct V_1 * V_2 )
{
T_4 V_41 ;
F_24 ( & V_2 -> V_7 -> V_35 ) ;
V_41 = F_3 ( V_2 ) ;
F_25 ( & V_2 -> V_7 -> V_35 ) ;
return V_41 ;
}
T_1 F_21 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
T_1 V_14 = V_2 -> V_14 ;
if ( V_10 -> V_22 & V_23 ) {
V_14 = F_26 ( F_6 ( V_10 -> V_22 ) ,
V_10 -> V_20 , V_10 -> V_13 ) ;
}
return V_14 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_42 * V_43 , struct V_44 * V_45 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
unsigned long V_46 ;
T_5 V_47 ;
V_47 = ( ( unsigned long ) V_45 -> V_48 -
V_43 -> V_49 ) >> V_18 ;
if ( V_10 -> V_27 ) {
V_46 = F_28 ( V_10 -> V_27 [ V_47 ] ) ;
} else {
F_29 ( ! ( V_10 -> V_22 & V_50 ) ) ;
V_46 = ( V_10 -> V_51 >> V_18 ) + V_47 ;
}
F_30 ( L_3 , V_45 -> V_48 ,
V_46 , V_46 << V_18 ) ;
return F_31 ( V_43 , ( unsigned long ) V_45 -> V_48 , V_46 ) ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_42 * V_43 , struct V_44 * V_45 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_5 * V_6 ;
enum V_3 V_4 = F_6 ( V_10 -> V_22 ) ;
struct V_26 * V_27 [ 64 ] ;
unsigned long V_46 ;
T_5 V_47 , V_52 ;
void T_6 * V_53 ;
int V_21 , V_38 , V_54 ;
const int V_11 = V_12 [ V_4 ] . V_13 ;
const int V_55 = V_12 [ V_4 ] . V_56 ;
const int V_19 = 1 + ( ( V_10 -> V_20 << V_4 ) / V_15 ) ;
V_47 = ( ( unsigned long ) V_45 -> V_48 -
V_43 -> V_49 ) >> V_18 ;
V_52 = F_33 ( V_47 , V_19 << V_55 ) ;
V_54 = V_10 -> V_20 >> V_12 [ V_4 ] . V_57 ;
V_53 = V_45 -> V_48 - ( ( V_47 - V_52 ) << V_18 ) ;
V_6 = & V_12 [ V_4 ] . V_6 [ V_12 [ V_4 ] . V_58 ] ;
if ( V_6 -> V_2 )
F_1 ( V_6 -> V_2 , V_4 , V_6 ) ;
V_6 -> V_2 = V_2 ;
V_6 -> V_17 = V_52 ;
V_52 = ( V_52 >> V_55 ) * V_54 ;
if ( V_19 > 1 ) {
int V_16 = V_47 % V_19 ;
V_6 -> V_17 += V_16 ;
V_52 /= V_19 ;
V_54 = F_34 ( V_54 - ( V_16 << V_55 ) , V_11 ) ;
V_52 += V_16 << V_55 ;
V_53 += V_16 << V_18 ;
}
memcpy ( V_27 , & V_10 -> V_27 [ V_52 ] ,
sizeof( struct V_26 * ) * V_54 ) ;
memset ( V_27 + V_54 , 0 ,
sizeof( struct V_26 * ) * ( V_11 - V_54 ) ) ;
V_38 = F_35 ( V_6 -> V_59 , V_27 , F_36 ( V_27 ) , 0 , true ) ;
if ( V_38 ) {
F_12 ( V_2 -> V_7 -> V_7 , L_4 , V_38 ) ;
return V_38 ;
}
V_46 = V_6 -> V_51 >> V_18 ;
F_30 ( L_3 , V_45 -> V_48 ,
V_46 , V_46 << V_18 ) ;
for ( V_21 = V_11 ; V_21 > 0 ; V_21 -- ) {
F_31 ( V_43 , ( unsigned long ) V_53 , V_46 ) ;
V_46 += V_12 [ V_4 ] . V_60 ;
V_53 += V_15 * V_19 ;
}
V_12 [ V_4 ] . V_58 = ( V_12 [ V_4 ] . V_58 + 1 ) % V_24 ;
return 0 ;
}
int F_37 ( struct V_42 * V_43 , struct V_44 * V_45 )
{
struct V_1 * V_2 = V_43 -> V_61 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_34 * V_7 = V_2 -> V_7 ;
struct V_26 * * V_27 ;
int V_38 ;
F_24 ( & V_7 -> V_35 ) ;
V_38 = F_38 ( V_2 , & V_27 ) ;
if ( V_38 ) {
goto V_62;
}
if ( V_10 -> V_22 & V_23 )
V_38 = F_32 ( V_2 , V_43 , V_45 ) ;
else
V_38 = F_27 ( V_2 , V_43 , V_45 ) ;
V_62:
F_25 ( & V_7 -> V_35 ) ;
switch ( V_38 ) {
case 0 :
case - V_63 :
case - V_64 :
return V_65 ;
case - V_66 :
return V_67 ;
default:
return V_68 ;
}
}
int F_39 ( struct V_69 * V_25 , struct V_42 * V_43 )
{
struct V_9 * V_10 ;
int V_38 ;
V_38 = F_40 ( V_25 , V_43 ) ;
if ( V_38 ) {
F_41 ( L_5 , V_38 ) ;
return V_38 ;
}
V_10 = F_2 ( V_43 -> V_61 ) ;
V_43 -> V_70 &= ~ V_71 ;
V_43 -> V_70 |= V_72 ;
if ( V_10 -> V_22 & V_29 ) {
V_43 -> V_73 = F_42 ( F_43 ( V_43 -> V_70 ) ) ;
} else if ( V_10 -> V_22 & V_30 ) {
V_43 -> V_73 = F_44 ( F_43 ( V_43 -> V_70 ) ) ;
} else {
V_43 -> V_73 = F_43 ( V_43 -> V_70 ) ;
}
return V_38 ;
}
int F_45 ( struct V_74 * V_69 , struct V_34 * V_7 ,
struct V_75 * args )
{
union V_76 V_77 ;
args -> V_78 = F_46 ( args -> V_78 , args -> V_20 , args -> V_79 ) ;
args -> V_14 = F_47 ( args -> V_78 * args -> V_13 ) ;
V_77 = (union V_76 ) {
. V_80 = args -> V_14 ,
} ;
return F_48 ( V_7 , V_69 , V_77 ,
V_81 | V_29 , & args -> V_82 ) ;
}
int F_49 ( struct V_74 * V_69 , struct V_34 * V_7 ,
T_7 V_82 )
{
return F_50 ( V_69 , V_82 ) ;
}
int F_51 ( struct V_74 * V_69 , struct V_34 * V_7 ,
T_7 V_82 , T_4 * V_41 )
{
struct V_1 * V_2 ;
int V_38 = 0 ;
V_2 = F_52 ( V_7 , V_69 , V_82 ) ;
if ( V_2 == NULL ) {
V_38 = - V_83 ;
goto V_62;
}
* V_41 = F_23 ( V_2 ) ;
F_53 ( V_2 ) ;
V_62:
return V_38 ;
}
int F_54 ( struct V_1 * V_2 , T_7 V_84 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
T_7 V_31 = V_2 -> V_14 >> V_18 ;
int V_38 = 0 ;
if ( V_84 > V_31 ) {
F_12 ( V_2 -> V_7 -> V_7 , L_6 , V_84 ) ;
return - V_85 ;
}
V_10 -> V_84 = V_84 ;
F_24 ( & V_2 -> V_7 -> V_35 ) ;
if ( V_10 -> V_59 ) {
struct V_26 * * V_27 ;
V_38 = F_38 ( V_2 , & V_27 ) ;
if ( V_38 )
goto V_62;
V_38 = F_35 ( V_10 -> V_59 , V_27 , V_31 , V_84 , true ) ;
if ( V_38 )
F_12 ( V_2 -> V_7 -> V_7 , L_7 , V_38 ) ;
}
V_62:
F_25 ( & V_2 -> V_7 -> V_35 ) ;
return V_38 ;
}
int F_55 ( struct V_1 * V_2 ,
T_3 * V_51 , bool V_86 )
{
struct V_87 * V_88 = V_2 -> V_7 -> V_89 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_38 = 0 ;
F_24 ( & V_2 -> V_7 -> V_35 ) ;
if ( V_86 && F_7 ( V_2 ) && V_88 -> V_90 ) {
if ( V_10 -> V_91 == 0 ) {
struct V_26 * * V_27 ;
T_7 V_31 = V_2 -> V_14 >> V_18 ;
enum V_3 V_4 = F_6 ( V_10 -> V_22 ) ;
struct V_92 * V_59 ;
F_29 ( V_10 -> V_59 ) ;
V_38 = F_38 ( V_2 , & V_27 ) ;
if ( V_38 )
goto V_62;
if ( V_10 -> V_22 & V_23 ) {
V_59 = F_56 ( V_4 ,
V_10 -> V_20 ,
V_10 -> V_13 , 0 ) ;
} else {
V_59 = F_57 ( V_2 -> V_14 ) ;
}
if ( F_11 ( V_59 ) ) {
V_38 = F_13 ( V_59 ) ;
F_12 ( V_2 -> V_7 -> V_7 ,
L_8 , V_38 , V_4 ) ;
goto V_62;
}
V_38 = F_35 ( V_59 , V_27 , V_31 ,
V_10 -> V_84 , true ) ;
if ( V_38 ) {
F_58 ( V_59 ) ;
F_12 ( V_2 -> V_7 -> V_7 ,
L_9 , V_38 ) ;
goto V_62;
}
V_10 -> V_51 = F_59 ( V_59 ) ;
V_10 -> V_59 = V_59 ;
F_41 ( L_10 , V_10 -> V_51 ) ;
}
V_10 -> V_91 ++ ;
* V_51 = V_10 -> V_51 ;
} else if ( V_10 -> V_22 & V_50 ) {
* V_51 = V_10 -> V_51 ;
} else {
V_38 = - V_85 ;
}
V_62:
F_25 ( & V_2 -> V_7 -> V_35 ) ;
return V_38 ;
}
int F_60 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_38 = 0 ;
F_24 ( & V_2 -> V_7 -> V_35 ) ;
if ( V_10 -> V_91 > 0 ) {
V_10 -> V_91 -- ;
if ( V_10 -> V_91 == 0 ) {
V_38 = F_61 ( V_10 -> V_59 ) ;
if ( V_38 ) {
F_12 ( V_2 -> V_7 -> V_7 ,
L_11 , V_38 ) ;
goto V_62;
}
V_38 = F_58 ( V_10 -> V_59 ) ;
if ( V_38 ) {
F_12 ( V_2 -> V_7 -> V_7 ,
L_12 , V_38 ) ;
}
V_10 -> V_59 = NULL ;
}
}
V_62:
F_25 ( & V_2 -> V_7 -> V_35 ) ;
return V_38 ;
}
static int F_38 ( struct V_1 * V_2 , struct V_26 * * * V_27 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_38 = 0 ;
if ( F_7 ( V_2 ) && ! V_10 -> V_27 ) {
V_38 = F_8 ( V_2 ) ;
if ( V_38 ) {
F_12 ( V_2 -> V_7 -> V_7 , L_13 ) ;
return V_38 ;
}
}
* V_27 = V_10 -> V_27 ;
return 0 ;
}
int F_62 ( struct V_1 * V_2 , struct V_26 * * * V_27 )
{
int V_38 ;
F_24 ( & V_2 -> V_7 -> V_35 ) ;
V_38 = F_38 ( V_2 , V_27 ) ;
F_25 ( & V_2 -> V_7 -> V_35 ) ;
return V_38 ;
}
int F_63 ( struct V_1 * V_2 )
{
return 0 ;
}
void * F_64 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
F_9 ( ! F_20 ( & V_2 -> V_7 -> V_35 ) ) ;
if ( ! V_10 -> V_53 ) {
struct V_26 * * V_27 ;
int V_38 = F_38 ( V_2 , & V_27 ) ;
if ( V_38 )
return F_65 ( V_38 ) ;
V_10 -> V_53 = F_66 ( V_27 , V_2 -> V_14 >> V_18 ,
V_93 , F_42 ( V_94 ) ) ;
}
return V_10 -> V_53 ;
}
void F_67 ( struct V_1 * V_2 , struct V_95 * V_19 )
{
struct V_34 * V_7 = V_2 -> V_7 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
T_4 V_16 = 0 ;
F_9 ( ! F_20 ( & V_7 -> V_35 ) ) ;
if ( V_2 -> V_36 . V_37 )
V_16 = ( T_4 ) V_2 -> V_36 . V_39 . V_40 ;
F_68 ( V_19 , L_14 ,
V_10 -> V_22 , V_2 -> V_96 , V_2 -> V_97 . V_97 . V_98 ,
V_16 , V_10 -> V_51 , V_10 -> V_91 ,
V_10 -> V_53 , V_10 -> V_84 ) ;
if ( V_10 -> V_22 & V_23 ) {
F_68 ( V_19 , L_15 , V_10 -> V_20 , V_10 -> V_13 ) ;
if ( V_10 -> V_59 ) {
struct V_99 * V_100 = & V_10 -> V_59 -> V_100 ;
F_68 ( V_19 , L_16 ,
V_100 -> V_101 . V_102 , V_100 -> V_101 . V_103 ,
V_100 -> V_104 . V_102 , V_100 -> V_104 . V_103 ) ;
}
} else {
F_68 ( V_19 , L_17 , V_2 -> V_14 ) ;
}
F_68 ( V_19 , L_18 ) ;
}
void F_69 ( struct V_105 * V_106 , struct V_95 * V_19 )
{
struct V_9 * V_10 ;
int V_107 = 0 ;
T_1 V_14 = 0 ;
F_70 (omap_obj, list, mm_list) {
struct V_1 * V_2 = & V_10 -> V_108 ;
F_68 ( V_19 , L_19 ) ;
F_67 ( V_2 , V_19 ) ;
V_107 ++ ;
V_14 += V_2 -> V_14 ;
}
F_68 ( V_19 , L_20 , V_107 , V_14 ) ;
}
static inline bool F_71 ( struct V_109 * V_110 )
{
struct V_9 * V_10 = V_110 -> V_10 ;
if ( ( V_110 -> V_111 & V_112 ) &&
( V_10 -> V_113 -> V_114 < V_110 -> V_115 ) )
return true ;
if ( ( V_110 -> V_111 & V_116 ) &&
( V_10 -> V_113 -> V_117 < V_110 -> V_118 ) )
return true ;
return false ;
}
static void F_72 ( void )
{
struct V_109 * V_110 , * V_11 ;
F_73 (waiter, n, &waiters, list) {
if ( ! F_71 ( V_110 ) ) {
F_74 ( & V_110 -> V_106 ) ;
F_75 ( L_21 , V_110 ) ;
V_110 -> V_119 ( V_110 -> V_120 ) ;
F_18 ( V_110 ) ;
}
}
}
static inline int F_76 ( struct V_1 * V_2 ,
enum V_121 V_111 , bool V_122 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_38 = 0 ;
F_77 ( & V_123 ) ;
if ( ! V_10 -> V_113 ) {
V_10 -> V_113 = F_78 ( sizeof( * V_10 -> V_113 ) , V_124 ) ;
if ( ! V_10 -> V_113 ) {
V_38 = - V_66 ;
goto V_125;
}
}
if ( V_122 ) {
if ( V_111 & V_112 )
V_10 -> V_113 -> V_126 ++ ;
if ( V_111 & V_116 )
V_10 -> V_113 -> V_127 ++ ;
} else {
if ( V_111 & V_112 )
V_10 -> V_113 -> V_114 ++ ;
if ( V_111 & V_116 )
V_10 -> V_113 -> V_117 ++ ;
F_72 () ;
}
V_125:
F_79 ( & V_123 ) ;
return V_38 ;
}
void F_80 ( void )
{
F_77 ( & V_123 ) ;
F_72 () ;
F_79 ( & V_123 ) ;
}
int F_81 ( struct V_1 * V_2 , enum V_121 V_111 )
{
return F_76 ( V_2 , V_111 , true ) ;
}
int F_82 ( struct V_1 * V_2 , enum V_121 V_111 )
{
return F_76 ( V_2 , V_111 , false ) ;
}
static void F_83 ( void * V_120 )
{
struct V_128 * * V_129 = V_120 ;
* V_129 = NULL ;
F_84 ( & V_130 ) ;
}
int F_85 ( struct V_1 * V_2 , enum V_121 V_111 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_38 = 0 ;
if ( V_10 -> V_113 ) {
struct V_128 * V_129 = V_131 ;
struct V_109 * V_110 =
F_78 ( sizeof( * V_110 ) , V_28 ) ;
if ( ! V_110 ) {
return - V_66 ;
}
V_110 -> V_10 = V_10 ;
V_110 -> V_111 = V_111 ;
V_110 -> V_115 = V_10 -> V_113 -> V_126 ;
V_110 -> V_118 = V_10 -> V_113 -> V_127 ;
V_110 -> V_119 = F_83 ;
V_110 -> V_120 = & V_129 ;
F_77 ( & V_123 ) ;
if ( F_71 ( V_110 ) ) {
F_75 ( L_22 , V_110 ) ;
F_86 ( & V_110 -> V_106 , & V_132 ) ;
F_79 ( & V_123 ) ;
V_38 = F_87 ( V_130 ,
( V_129 == NULL ) ) ;
F_77 ( & V_123 ) ;
if ( V_129 ) {
F_75 ( L_23 , V_110 ) ;
F_74 ( & V_110 -> V_106 ) ;
V_129 = NULL ;
} else {
V_110 = NULL ;
}
}
F_79 ( & V_123 ) ;
if ( V_110 ) {
F_18 ( V_110 ) ;
}
}
return V_38 ;
}
int F_88 ( struct V_1 * V_2 , enum V_121 V_111 ,
void (* F_89)( void * V_120 ) , void * V_120 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( V_10 -> V_113 ) {
struct V_109 * V_110 =
F_78 ( sizeof( * V_110 ) , V_124 ) ;
if ( ! V_110 ) {
return - V_66 ;
}
V_110 -> V_10 = V_10 ;
V_110 -> V_111 = V_111 ;
V_110 -> V_115 = V_10 -> V_113 -> V_126 ;
V_110 -> V_118 = V_10 -> V_113 -> V_127 ;
V_110 -> V_119 = F_89 ;
V_110 -> V_120 = V_120 ;
F_77 ( & V_123 ) ;
if ( F_71 ( V_110 ) ) {
F_75 ( L_22 , V_110 ) ;
F_86 ( & V_110 -> V_106 , & V_132 ) ;
F_79 ( & V_123 ) ;
return 0 ;
}
F_79 ( & V_123 ) ;
}
F_89 ( V_120 ) ;
return 0 ;
}
int F_90 ( struct V_1 * V_2 , void * V_133 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_38 = 0 ;
F_77 ( & V_123 ) ;
if ( ( V_10 -> V_22 & V_134 ) && ! V_133 ) {
V_133 = F_78 ( sizeof( * V_10 -> V_113 ) , V_124 ) ;
if ( ! V_133 ) {
V_38 = - V_66 ;
goto V_125;
}
memcpy ( V_133 , V_10 -> V_113 , sizeof( * V_10 -> V_113 ) ) ;
V_10 -> V_22 &= ~ V_134 ;
V_10 -> V_113 = V_133 ;
} else if ( V_133 && ! ( V_10 -> V_22 & V_134 ) ) {
if ( V_10 -> V_113 ) {
memcpy ( V_133 , V_10 -> V_113 , sizeof( * V_10 -> V_113 ) ) ;
F_18 ( V_10 -> V_113 ) ;
}
V_10 -> V_22 |= V_134 ;
V_10 -> V_113 = V_133 ;
}
V_125:
F_79 ( & V_123 ) ;
return V_38 ;
}
int F_91 ( struct V_1 * V_2 )
{
return - V_85 ;
}
void F_92 ( struct V_1 * V_2 )
{
struct V_34 * V_7 = V_2 -> V_7 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
F_5 ( V_2 ) ;
F_9 ( ! F_20 ( & V_7 -> V_35 ) ) ;
F_74 ( & V_10 -> V_135 ) ;
if ( V_2 -> V_36 . V_37 ) {
F_93 ( V_2 ) ;
}
F_9 ( V_10 -> V_91 > 0 ) ;
if ( ! ( V_10 -> V_22 & V_136 ) ) {
if ( V_10 -> V_27 ) {
F_16 ( V_2 ) ;
}
if ( ! F_7 ( V_2 ) ) {
F_94 ( V_7 -> V_7 , V_2 -> V_14 ,
V_10 -> V_53 , V_10 -> V_51 ) ;
} else if ( V_10 -> V_53 ) {
F_95 ( V_10 -> V_53 ) ;
}
}
if ( ! ( V_10 -> V_22 & V_134 ) ) {
F_18 ( V_10 -> V_113 ) ;
}
F_96 ( V_2 ) ;
F_18 ( V_2 ) ;
}
int F_48 ( struct V_34 * V_7 , struct V_74 * V_69 ,
union V_76 V_77 , T_7 V_22 , T_7 * V_82 )
{
struct V_1 * V_2 ;
int V_38 ;
V_2 = F_97 ( V_7 , V_77 , V_22 ) ;
if ( ! V_2 )
return - V_66 ;
V_38 = F_98 ( V_69 , V_2 , V_82 ) ;
if ( V_38 ) {
F_96 ( V_2 ) ;
F_18 ( V_2 ) ;
return V_38 ;
}
F_53 ( V_2 ) ;
return 0 ;
}
struct V_1 * F_97 ( struct V_34 * V_7 ,
union V_76 V_77 , T_7 V_22 )
{
struct V_87 * V_88 = V_7 -> V_89 ;
struct V_9 * V_10 ;
struct V_1 * V_2 = NULL ;
T_1 V_14 ;
int V_38 ;
if ( V_22 & V_23 ) {
if ( ! V_12 ) {
F_12 ( V_7 -> V_7 , L_24 ) ;
goto V_62;
}
V_22 &= ~ V_81 ;
V_22 &= ~ ( V_137 | V_30 ) ;
V_22 |= V_29 ;
F_99 ( F_6 ( V_22 ) ,
& V_77 . V_138 . V_20 , & V_77 . V_138 . V_13 ) ;
V_14 = F_100 ( F_6 ( V_22 ) ,
V_77 . V_138 . V_20 , V_77 . V_138 . V_13 ) ;
} else {
V_14 = F_47 ( V_77 . V_80 ) ;
}
V_10 = F_78 ( sizeof( * V_10 ) , V_28 ) ;
if ( ! V_10 ) {
F_12 ( V_7 -> V_7 , L_25 ) ;
goto V_62;
}
F_101 ( & V_10 -> V_135 , & V_88 -> V_139 ) ;
V_2 = & V_10 -> V_108 ;
if ( ( V_22 & V_81 ) && ! V_88 -> V_90 ) {
V_10 -> V_53 = F_102 ( V_7 -> V_7 , V_14 ,
& V_10 -> V_51 , V_28 ) ;
if ( V_10 -> V_53 ) {
V_22 |= V_50 ;
}
}
V_10 -> V_22 = V_22 ;
if ( V_22 & V_23 ) {
V_10 -> V_20 = V_77 . V_138 . V_20 ;
V_10 -> V_13 = V_77 . V_138 . V_13 ;
}
if ( V_22 & ( V_50 | V_136 ) ) {
V_38 = F_103 ( V_7 , V_2 , V_14 ) ;
} else {
V_38 = F_104 ( V_7 , V_2 , V_14 ) ;
}
if ( V_38 ) {
goto V_62;
}
return V_2 ;
V_62:
if ( V_2 ) {
F_92 ( V_2 ) ;
}
return NULL ;
}
void F_105 ( struct V_34 * V_7 )
{
struct V_87 * V_88 = V_7 -> V_89 ;
const enum V_3 V_140 [] = {
V_141 , V_142 , V_143
} ;
int V_21 , V_144 ;
if ( ! F_106 () ) {
F_107 ( V_7 -> V_7 , L_26 ) ;
return;
}
V_12 = F_78 ( 3 * sizeof( * V_12 ) , V_28 ) ;
if ( ! V_12 ) {
F_107 ( V_7 -> V_7 , L_27 ) ;
return;
}
for ( V_21 = 0 ; V_21 < F_36 ( V_140 ) ; V_21 ++ ) {
T_8 V_145 = 1 , V_146 = V_15 >> V_21 ;
F_99 ( V_140 [ V_21 ] , & V_146 , & V_145 ) ;
V_12 [ V_21 ] . V_13 = V_145 ;
V_12 [ V_21 ] . V_56 = F_108 ( V_145 ) ;
V_12 [ V_21 ] . V_60 = F_109 ( V_140 [ V_21 ] ) >> V_18 ;
V_12 [ V_21 ] . V_57 = F_108 ( ( V_15 / V_145 ) >> V_21 ) ;
for ( V_144 = 0 ; V_144 < V_24 ; V_144 ++ ) {
struct V_5 * V_6 = & V_12 [ V_21 ] . V_6 [ V_144 ] ;
struct V_92 * V_59 =
F_56 ( V_140 [ V_21 ] , V_146 , V_145 ,
V_15 ) ;
if ( F_11 ( V_59 ) ) {
F_12 ( V_7 -> V_7 ,
L_28 ,
V_21 , V_144 , F_13 ( V_59 ) ) ;
return;
}
V_6 -> V_51 = F_59 ( V_59 ) ;
V_6 -> V_59 = V_59 ;
F_41 ( L_29 , V_21 , V_144 , V_146 , V_145 ,
V_6 -> V_51 ,
V_12 [ V_21 ] . V_60 << V_18 ) ;
}
}
V_88 -> V_90 = true ;
}
void F_110 ( struct V_34 * V_7 )
{
F_18 ( V_12 ) ;
}
