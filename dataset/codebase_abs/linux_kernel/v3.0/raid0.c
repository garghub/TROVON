static int F_1 ( void * V_1 , int V_2 )
{
T_1 * V_3 = V_1 ;
T_2 * V_4 = V_3 -> V_5 ;
T_3 * * V_6 = V_4 -> V_6 ;
int V_7 = V_4 -> V_8 [ 0 ] . V_9 ;
int V_10 , V_11 = 0 ;
if ( F_2 ( V_3 , V_2 ) )
return 1 ;
for ( V_10 = 0 ; V_10 < V_7 && ! V_11 ; V_10 ++ ) {
struct V_12 * V_13 = F_3 ( V_6 [ V_10 ] -> V_14 ) ;
V_11 |= F_4 ( & V_13 -> V_15 , V_2 ) ;
}
return V_11 ;
}
static void F_5 ( T_1 * V_3 )
{
int V_16 , V_17 , V_18 ;
T_4 V_19 = 0 ;
T_4 V_20 = 0 ;
char V_21 [ V_22 ] ;
T_2 * V_4 = V_3 -> V_5 ;
int V_7 = V_4 -> V_8 [ 0 ] . V_9 ;
F_6 ( V_23 L_1 ,
F_7 ( V_3 ) ) ;
V_18 = 0 ;
for ( V_16 = 0 ; V_16 < V_4 -> V_24 ; V_16 ++ ) {
F_6 ( V_23 L_2 , V_16 ) ;
for ( V_17 = 0 ; V_17 < V_4 -> V_8 [ V_16 ] . V_9 ; V_17 ++ )
F_6 ( V_25 L_3 ,
F_8 ( V_4 -> V_6 [ V_16 * V_7
+ V_17 ] -> V_14 , V_21 ) ) ;
F_6 ( V_25 L_4 ) ;
V_19 = V_4 -> V_8 [ V_16 ] . V_26 - V_20 ;
F_6 ( V_23 L_5
L_6 ,
( unsigned long long ) V_20 >> 1 ,
( unsigned long long ) V_4 -> V_8 [ V_16 ] . V_27 >> 1 ,
( unsigned long long ) V_19 >> 1 ) ;
V_20 = V_4 -> V_8 [ V_16 ] . V_26 ;
}
F_6 ( V_23 L_7 ) ;
}
static int F_9 ( T_1 * V_3 , T_2 * * V_28 )
{
int V_10 , V_29 , V_30 ;
T_4 V_31 , V_32 ;
T_3 * V_33 , * V_34 , * V_35 , * V_36 , * * V_37 ;
struct V_8 * V_38 ;
int V_39 ;
char V_21 [ V_22 ] ;
T_2 * V_4 = F_10 ( sizeof( * V_4 ) , V_40 ) ;
if ( ! V_4 )
return - V_41 ;
F_11 (rdev1, &mddev->disks, same_set) {
F_6 ( V_23 L_8 ,
F_7 ( V_3 ) ,
F_8 ( V_34 -> V_14 , V_21 ) ) ;
V_29 = 0 ;
V_32 = V_34 -> V_32 ;
F_12 ( V_32 , V_3 -> V_42 ) ;
V_34 -> V_32 = V_32 * V_3 -> V_42 ;
F_11 (rdev2, &mddev->disks, same_set) {
F_6 ( V_23 L_9 ,
F_7 ( V_3 ) ,
F_8 ( V_34 -> V_14 , V_21 ) ,
( unsigned long long ) V_34 -> V_32 ) ;
F_6 ( V_25 L_10 ,
F_8 ( V_35 -> V_14 , V_21 ) ,
( unsigned long long ) V_35 -> V_32 ) ;
if ( V_35 == V_34 ) {
F_6 ( V_23 L_11 ,
F_7 ( V_3 ) ) ;
break;
}
if ( V_35 -> V_32 == V_34 -> V_32 ) {
F_6 ( V_23 L_12 ,
F_7 ( V_3 ) ) ;
V_29 = 1 ;
break;
}
F_6 ( V_23 L_13 ,
F_7 ( V_3 ) ) ;
}
if ( ! V_29 ) {
F_6 ( V_23 L_14 ,
F_7 ( V_3 ) ) ;
V_4 -> V_24 ++ ;
F_6 ( V_23 L_15 ,
F_7 ( V_3 ) , V_4 -> V_24 ) ;
}
}
F_6 ( V_23 L_16 ,
F_7 ( V_3 ) , V_4 -> V_24 ) ;
V_30 = - V_41 ;
V_4 -> V_8 = F_10 ( sizeof( struct V_8 ) *
V_4 -> V_24 , V_40 ) ;
if ( ! V_4 -> V_8 )
goto abort;
V_4 -> V_6 = F_10 ( sizeof( T_3 * ) *
V_4 -> V_24 * V_3 -> V_7 ,
V_40 ) ;
if ( ! V_4 -> V_6 )
goto abort;
V_38 = & V_4 -> V_8 [ 0 ] ;
V_39 = 0 ;
V_33 = NULL ;
V_37 = V_4 -> V_6 ;
V_30 = - V_43 ;
F_11 (rdev1, &mddev->disks, same_set) {
int V_16 = V_34 -> V_44 ;
if ( V_3 -> V_45 == 10 ) {
V_16 /= 2 ;
V_34 -> V_46 = V_16 ;
}
if ( V_3 -> V_45 == 1 ) {
V_16 = 0 ;
V_34 -> V_46 = V_16 ;
}
if ( V_16 < 0 || V_16 >= V_3 -> V_7 ) {
F_6 ( V_47 L_17
L_18 , F_7 ( V_3 ) , V_16 ) ;
goto abort;
}
if ( V_37 [ V_16 ] ) {
F_6 ( V_47 L_19
L_18 , F_7 ( V_3 ) , V_16 ) ;
goto abort;
}
V_37 [ V_16 ] = V_34 ;
F_13 ( V_3 -> V_48 , V_34 -> V_14 ,
V_34 -> V_49 << 9 ) ;
if ( V_34 -> V_14 -> V_50 -> V_51 -> V_52 ) {
F_14 ( V_3 -> V_51 , 1 ) ;
F_15 ( V_3 -> V_51 ,
V_53 - 1 ) ;
}
if ( ! V_33 || ( V_34 -> V_32 < V_33 -> V_32 ) )
V_33 = V_34 ;
V_39 ++ ;
}
if ( V_39 != V_3 -> V_7 ) {
F_6 ( V_47 L_20
L_18 , F_7 ( V_3 ) , V_39 , V_3 -> V_7 ) ;
goto abort;
}
V_38 -> V_9 = V_39 ;
V_38 -> V_26 = V_33 -> V_32 * V_39 ;
V_31 = V_38 -> V_26 ;
for ( V_10 = 1 ; V_10 < V_4 -> V_24 ; V_10 ++ )
{
int V_16 ;
V_38 = V_4 -> V_8 + V_10 ;
V_37 = V_4 -> V_6 + V_10 * V_3 -> V_7 ;
F_6 ( V_23 L_21 ,
F_7 ( V_3 ) , V_10 ) ;
V_38 -> V_27 = V_33 -> V_32 ;
V_33 = NULL ;
V_29 = 0 ;
for ( V_16 = 0 ; V_16 < V_39 ; V_16 ++ ) {
V_36 = V_4 -> V_6 [ V_16 ] ;
F_6 ( V_23 L_22 ,
F_7 ( V_3 ) ,
F_8 ( V_36 -> V_14 , V_21 ) ) ;
if ( V_36 -> V_32 <= V_38 -> V_27 ) {
F_6 ( V_25 L_23 ) ;
continue;
}
F_6 ( V_25 L_24 , V_29 ) ;
V_37 [ V_29 ] = V_36 ;
V_29 ++ ;
if ( ! V_33 || V_36 -> V_32 < V_33 -> V_32 ) {
V_33 = V_36 ;
F_6 ( V_23 L_25 ,
F_7 ( V_3 ) ,
( unsigned long long ) V_36 -> V_32 ) ;
}
}
V_38 -> V_9 = V_29 ;
V_32 = ( V_33 -> V_32 - V_38 -> V_27 ) * V_29 ;
F_6 ( V_23 L_26 ,
F_7 ( V_3 ) ,
V_38 -> V_9 , ( unsigned long long ) V_32 ) ;
V_31 += V_32 ;
V_38 -> V_26 = V_31 ;
F_6 ( V_23 L_27 ,
F_7 ( V_3 ) ,
( unsigned long long ) V_33 -> V_32 ) ;
}
V_3 -> V_51 -> V_15 . V_54 = F_1 ;
V_3 -> V_51 -> V_15 . V_55 = V_3 ;
if ( ( V_3 -> V_42 << 9 ) % F_16 ( V_3 -> V_51 ) ) {
F_6 ( V_47 L_28 ,
F_7 ( V_3 ) ,
V_3 -> V_42 << 9 ) ;
goto abort;
}
F_17 ( V_3 -> V_51 , V_3 -> V_42 << 9 ) ;
F_18 ( V_3 -> V_51 ,
( V_3 -> V_42 << 9 ) * V_3 -> V_7 ) ;
F_6 ( V_23 L_29 , F_7 ( V_3 ) ) ;
* V_28 = V_4 ;
return 0 ;
abort:
F_19 ( V_4 -> V_8 ) ;
F_19 ( V_4 -> V_6 ) ;
F_19 ( V_4 ) ;
* V_28 = NULL ;
return V_30 ;
}
static int F_20 ( struct V_12 * V_13 ,
struct V_56 * V_57 ,
struct V_58 * V_59 )
{
T_1 * V_3 = V_13 -> V_60 ;
T_4 V_61 = V_57 -> V_62 + F_21 ( V_57 -> V_63 ) ;
int V_64 ;
unsigned int V_42 = V_3 -> V_42 ;
unsigned int V_65 = V_57 -> V_66 >> 9 ;
if ( F_22 ( V_42 ) )
V_64 = ( V_42 - ( ( V_61 & ( V_42 - 1 ) )
+ V_65 ) ) << 9 ;
else
V_64 = ( V_42 - ( F_12 ( V_61 , V_42 )
+ V_65 ) ) << 9 ;
if ( V_64 < 0 ) V_64 = 0 ;
if ( V_64 <= V_59 -> V_67 && V_65 == 0 )
return V_59 -> V_67 ;
else
return V_64 ;
}
static T_4 F_23 ( T_1 * V_3 , T_4 V_32 , int V_7 )
{
T_4 V_68 = 0 ;
T_3 * V_36 ;
F_24 ( V_32 || V_7 ,
L_30 , V_69 ) ;
F_11 (rdev, &mddev->disks, same_set)
V_68 += V_36 -> V_32 ;
return V_68 ;
}
static int F_25 ( T_1 * V_3 )
{
T_2 * V_4 ;
int V_11 ;
if ( V_3 -> V_42 == 0 ) {
F_6 ( V_47 L_31 ,
F_7 ( V_3 ) ) ;
return - V_43 ;
}
if ( F_26 ( V_3 ) )
return - V_43 ;
F_27 ( V_3 -> V_51 , V_3 -> V_42 ) ;
if ( V_3 -> V_5 == NULL ) {
V_11 = F_9 ( V_3 , & V_4 ) ;
if ( V_11 < 0 )
return V_11 ;
V_3 -> V_5 = V_4 ;
}
V_4 = V_3 -> V_5 ;
F_28 ( V_3 , F_23 ( V_3 , 0 , 0 ) ) ;
F_6 ( V_23 L_32 ,
F_7 ( V_3 ) ,
( unsigned long long ) V_3 -> V_68 ) ;
{
int V_70 = V_3 -> V_7 *
( V_3 -> V_42 << 9 ) / V_71 ;
if ( V_3 -> V_51 -> V_15 . V_72 < 2 * V_70 )
V_3 -> V_51 -> V_15 . V_72 = 2 * V_70 ;
}
F_29 ( V_3 -> V_51 , F_20 ) ;
F_5 ( V_3 ) ;
return F_30 ( V_3 ) ;
}
static int F_31 ( T_1 * V_3 )
{
T_2 * V_4 = V_3 -> V_5 ;
F_32 ( V_3 -> V_51 ) ;
F_19 ( V_4 -> V_8 ) ;
F_19 ( V_4 -> V_6 ) ;
F_19 ( V_4 ) ;
V_3 -> V_5 = NULL ;
return 0 ;
}
static struct V_8 * F_33 ( struct V_73 * V_4 ,
T_4 * V_74 )
{
int V_10 ;
struct V_8 * V_75 = V_4 -> V_8 ;
T_4 V_61 = * V_74 ;
for ( V_10 = 0 ; V_10 < V_4 -> V_24 ; V_10 ++ )
if ( V_61 < V_75 [ V_10 ] . V_26 ) {
if ( V_10 )
* V_74 = V_61 - V_75 [ V_10 - 1 ] . V_26 ;
return V_75 + V_10 ;
}
F_34 () ;
}
static T_3 * F_35 ( T_1 * V_3 , struct V_8 * V_38 ,
T_4 V_61 , T_4 * V_76 )
{
unsigned int V_77 ;
T_4 V_78 ;
T_2 * V_4 = V_3 -> V_5 ;
int V_7 = V_4 -> V_8 [ 0 ] . V_9 ;
unsigned int V_79 = V_3 -> V_42 ;
if ( F_22 ( V_79 ) ) {
int V_80 = F_36 ( ~ V_79 ) ;
V_77 = V_61 & ( V_79 - 1 ) ;
V_61 >>= V_80 ;
V_78 = * V_76 ;
F_12 ( V_78 , V_38 -> V_9 << V_80 ) ;
} else{
V_77 = F_12 ( V_61 , V_79 ) ;
V_78 = * V_76 ;
F_12 ( V_78 , V_79 * V_38 -> V_9 ) ;
}
* V_76 = ( V_78 * V_79 ) + V_77 ;
return V_4 -> V_6 [ ( V_38 - V_4 -> V_8 ) * V_7
+ F_12 ( V_61 , V_38 -> V_9 ) ] ;
}
static inline int F_37 ( T_1 * V_3 ,
unsigned int V_79 , struct V_81 * V_81 )
{
if ( F_38 ( F_22 ( V_79 ) ) ) {
return V_79 >= ( ( V_81 -> V_62 & ( V_79 - 1 ) )
+ ( V_81 -> V_66 >> 9 ) ) ;
} else{
T_4 V_61 = V_81 -> V_62 ;
return V_79 >= ( F_12 ( V_61 , V_79 )
+ ( V_81 -> V_66 >> 9 ) ) ;
}
}
static int F_39 ( T_1 * V_3 , struct V_81 * V_81 )
{
unsigned int V_79 ;
T_4 V_76 ;
struct V_8 * V_38 ;
T_3 * V_82 ;
if ( F_40 ( V_81 -> V_83 & V_84 ) ) {
F_41 ( V_3 , V_81 ) ;
return 0 ;
}
V_79 = V_3 -> V_42 ;
if ( F_40 ( ! F_37 ( V_3 , V_79 , V_81 ) ) ) {
T_4 V_61 = V_81 -> V_62 ;
struct V_85 * V_86 ;
if ( V_81 -> V_87 != 1 ||
V_81 -> V_88 != 0 )
goto V_89;
if ( F_38 ( F_22 ( V_79 ) ) )
V_86 = F_42 ( V_81 , V_79 - ( V_61 &
( V_79 - 1 ) ) ) ;
else
V_86 = F_42 ( V_81 , V_79 -
F_12 ( V_61 , V_79 ) ) ;
if ( F_39 ( V_3 , & V_86 -> V_90 ) )
F_43 ( & V_86 -> V_90 ) ;
if ( F_39 ( V_3 , & V_86 -> V_91 ) )
F_43 ( & V_86 -> V_91 ) ;
F_44 ( V_86 ) ;
return 0 ;
}
V_76 = V_81 -> V_62 ;
V_38 = F_33 ( V_3 -> V_5 , & V_76 ) ;
V_82 = F_35 ( V_3 , V_38 , V_81 -> V_62 ,
& V_76 ) ;
V_81 -> V_63 = V_82 -> V_14 ;
V_81 -> V_62 = V_76 + V_38 -> V_27 +
V_82 -> V_49 ;
return 1 ;
V_89:
F_6 ( L_33
L_34 ,
F_7 ( V_3 ) , V_79 / 2 ,
( unsigned long long ) V_81 -> V_62 , V_81 -> V_66 >> 10 ) ;
F_45 ( V_81 ) ;
return 0 ;
}
static void F_46 ( struct V_92 * V_93 , T_1 * V_3 )
{
#undef V_94
#ifdef V_94
int V_16 , V_17 , V_18 ;
char V_21 [ V_22 ] ;
T_2 * V_4 = V_3 -> V_5 ;
int V_7 = V_4 -> V_8 [ 0 ] . V_9 ;
T_4 V_19 ;
T_4 V_20 = 0 ;
V_18 = 0 ;
for ( V_16 = 0 ; V_16 < V_4 -> V_24 ; V_16 ++ ) {
F_47 ( V_93 , L_35 , V_16 ) ;
F_47 ( V_93 , L_36 ) ;
for ( V_17 = 0 ; V_17 < V_4 -> V_8 [ V_16 ] . V_9 ; V_17 ++ )
F_47 ( V_93 , L_3 , F_8 (
V_4 -> V_6 [ V_16 * V_7 + V_17 ]
-> V_14 , V_21 ) ) ;
V_19 = V_4 -> V_8 [ V_16 ] . V_26 - V_20 ;
F_47 ( V_93 , L_37 ,
( unsigned long long ) V_20 >> 1 ,
( unsigned long long ) V_4 -> V_8 [ V_16 ] . V_27 >> 1 ,
( unsigned long long ) V_19 >> 1 ) ;
V_20 = V_4 -> V_8 [ V_16 ] . V_26 ;
}
#endif
F_47 ( V_93 , L_38 , V_3 -> V_42 / 2 ) ;
return;
}
static void * F_48 ( T_1 * V_3 )
{
T_3 * V_36 ;
T_2 * V_95 ;
if ( V_3 -> V_96 != 1 ) {
F_6 ( V_47 L_39 ,
F_7 ( V_3 ) ,
V_3 -> V_96 ) ;
return F_49 ( - V_43 ) ;
}
F_11 (rdev, &mddev->disks, same_set) {
if ( V_36 -> V_44 == V_3 -> V_7 - 1 ) {
F_6 ( V_47 L_40 ,
F_7 ( V_3 ) ) ;
return F_49 ( - V_43 ) ;
}
}
V_3 -> V_97 = 0 ;
V_3 -> V_98 = 0 ;
V_3 -> V_99 = V_3 -> V_42 ;
V_3 -> V_7 -- ;
V_3 -> V_100 = - 1 ;
V_3 -> V_101 = V_102 ;
F_9 ( V_3 , & V_95 ) ;
return V_95 ;
}
static void * F_50 ( T_1 * V_3 )
{
T_2 * V_95 ;
if ( V_3 -> V_103 != ( ( 1 << 8 ) + 2 ) ) {
F_6 ( V_47 L_41 ,
F_7 ( V_3 ) ,
V_3 -> V_103 ) ;
return F_49 ( - V_43 ) ;
}
if ( V_3 -> V_7 & 1 ) {
F_6 ( V_47 L_42 ,
F_7 ( V_3 ) ) ;
return F_49 ( - V_43 ) ;
}
if ( V_3 -> V_96 != ( V_3 -> V_7 >> 1 ) ) {
F_6 ( V_47 L_43 ,
F_7 ( V_3 ) ) ;
return F_49 ( - V_43 ) ;
}
V_3 -> V_97 = 0 ;
V_3 -> V_98 = 0 ;
V_3 -> V_99 = V_3 -> V_42 ;
V_3 -> V_100 = - V_3 -> V_7 / 2 ;
V_3 -> V_7 += V_3 -> V_100 ;
V_3 -> V_96 = 0 ;
V_3 -> V_101 = V_102 ;
F_9 ( V_3 , & V_95 ) ;
return V_95 ;
}
static void * F_51 ( T_1 * V_3 )
{
T_2 * V_95 ;
if ( ( V_3 -> V_7 - 1 ) != V_3 -> V_96 ) {
F_6 ( V_47 L_44 ,
F_7 ( V_3 ) ) ;
return F_49 ( - V_43 ) ;
}
V_3 -> V_97 = 0 ;
V_3 -> V_98 = 0 ;
V_3 -> V_99 = 128 ;
V_3 -> V_100 = 1 - V_3 -> V_7 ;
V_3 -> V_7 = 1 ;
V_3 -> V_101 = V_102 ;
F_9 ( V_3 , & V_95 ) ;
return V_95 ;
}
static void * F_52 ( T_1 * V_3 )
{
if ( V_3 -> V_45 == 4 )
return F_48 ( V_3 ) ;
if ( V_3 -> V_45 == 5 ) {
if ( V_3 -> V_103 == V_104 )
return F_48 ( V_3 ) ;
F_6 ( V_47 L_45 ,
F_7 ( V_3 ) , V_104 ) ;
}
if ( V_3 -> V_45 == 10 )
return F_50 ( V_3 ) ;
if ( V_3 -> V_45 == 1 )
return F_51 ( V_3 ) ;
F_6 ( V_47 L_46 ,
V_3 -> V_45 ) ;
return F_49 ( - V_43 ) ;
}
static void F_53 ( T_1 * V_3 , int V_105 )
{
}
static int T_5 F_54 ( void )
{
return F_55 ( & V_106 ) ;
}
static void F_56 ( void )
{
F_57 ( & V_106 ) ;
}
