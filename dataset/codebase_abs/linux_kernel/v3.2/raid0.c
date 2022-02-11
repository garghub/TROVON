static int F_1 ( void * V_1 , int V_2 )
{
struct V_3 * V_3 = V_1 ;
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_7 * * V_8 = V_5 -> V_8 ;
int V_9 = V_5 -> V_10 [ 0 ] . V_11 ;
int V_12 , V_13 = 0 ;
if ( F_2 ( V_3 , V_2 ) )
return 1 ;
for ( V_12 = 0 ; V_12 < V_9 && ! V_13 ; V_12 ++ ) {
struct V_14 * V_15 = F_3 ( V_8 [ V_12 ] -> V_16 ) ;
V_13 |= F_4 ( & V_15 -> V_17 , V_2 ) ;
}
return V_13 ;
}
static void F_5 ( struct V_3 * V_3 )
{
int V_18 , V_19 ;
T_1 V_20 = 0 ;
T_1 V_21 = 0 ;
char V_22 [ V_23 ] ;
struct V_4 * V_5 = V_3 -> V_6 ;
int V_9 = V_5 -> V_10 [ 0 ] . V_11 ;
F_6 ( V_24 L_1 ,
F_7 ( V_3 ) ,
V_5 -> V_25 , V_5 -> V_25 == 1 ? L_2 : L_3 ) ;
for ( V_18 = 0 ; V_18 < V_5 -> V_25 ; V_18 ++ ) {
F_6 ( V_24 L_4 , V_18 ) ;
for ( V_19 = 0 ; V_19 < V_5 -> V_10 [ V_18 ] . V_11 ; V_19 ++ )
F_6 ( V_26 L_5 , V_19 ? L_6 : L_2 ,
F_8 ( V_5 -> V_8 [ V_18 * V_9
+ V_19 ] -> V_16 , V_22 ) ) ;
F_6 ( V_26 L_7 ) ;
V_20 = V_5 -> V_10 [ V_18 ] . V_27 - V_21 ;
F_6 ( V_24 L_8
L_9 ,
( unsigned long long ) V_21 >> 1 ,
( unsigned long long ) V_5 -> V_10 [ V_18 ] . V_28 >> 1 ,
( unsigned long long ) V_20 >> 1 ) ;
V_21 = V_5 -> V_10 [ V_18 ] . V_27 ;
}
F_6 ( V_24 L_10 ) ;
}
static int F_9 ( struct V_3 * V_3 , struct V_4 * * V_29 )
{
int V_12 , V_30 , V_31 ;
T_1 V_32 , V_33 ;
struct V_7 * V_34 , * V_35 , * V_36 , * V_37 , * * V_38 ;
struct V_10 * V_39 ;
int V_40 ;
char V_22 [ V_23 ] ;
char V_41 [ V_23 ] ;
struct V_4 * V_5 = F_10 ( sizeof( * V_5 ) , V_42 ) ;
if ( ! V_5 )
return - V_43 ;
F_11 (rdev1, &mddev->disks, same_set) {
F_12 ( L_11 ,
F_7 ( V_3 ) ,
F_8 ( V_35 -> V_16 , V_22 ) ) ;
V_30 = 0 ;
V_33 = V_35 -> V_33 ;
F_13 ( V_33 , V_3 -> V_44 ) ;
V_35 -> V_33 = V_33 * V_3 -> V_44 ;
F_11 (rdev2, &mddev->disks, same_set) {
F_12 ( L_12
L_13 ,
F_7 ( V_3 ) ,
F_8 ( V_35 -> V_16 , V_22 ) ,
( unsigned long long ) V_35 -> V_33 ,
F_8 ( V_36 -> V_16 , V_41 ) ,
( unsigned long long ) V_36 -> V_33 ) ;
if ( V_36 == V_35 ) {
F_12 ( L_14 ,
F_7 ( V_3 ) ) ;
break;
}
if ( V_36 -> V_33 == V_35 -> V_33 ) {
F_12 ( L_15 ,
F_7 ( V_3 ) ) ;
V_30 = 1 ;
break;
}
F_12 ( L_16 ,
F_7 ( V_3 ) ) ;
}
if ( ! V_30 ) {
F_12 ( L_17 ,
F_7 ( V_3 ) ) ;
V_5 -> V_25 ++ ;
F_12 ( L_18 ,
F_7 ( V_3 ) , V_5 -> V_25 ) ;
}
}
F_12 ( L_19 ,
F_7 ( V_3 ) , V_5 -> V_25 ) ;
V_31 = - V_43 ;
V_5 -> V_10 = F_10 ( sizeof( struct V_10 ) *
V_5 -> V_25 , V_42 ) ;
if ( ! V_5 -> V_10 )
goto abort;
V_5 -> V_8 = F_10 ( sizeof( struct V_7 * ) *
V_5 -> V_25 * V_3 -> V_9 ,
V_42 ) ;
if ( ! V_5 -> V_8 )
goto abort;
V_39 = & V_5 -> V_10 [ 0 ] ;
V_40 = 0 ;
V_34 = NULL ;
V_38 = V_5 -> V_8 ;
V_31 = - V_45 ;
F_11 (rdev1, &mddev->disks, same_set) {
int V_18 = V_35 -> V_46 ;
if ( V_3 -> V_47 == 10 ) {
V_18 /= 2 ;
V_35 -> V_48 = V_18 ;
}
if ( V_3 -> V_47 == 1 ) {
V_18 = 0 ;
V_35 -> V_48 = V_18 ;
}
if ( V_18 < 0 || V_18 >= V_3 -> V_9 ) {
F_6 ( V_49 L_20
L_21 , F_7 ( V_3 ) , V_18 ) ;
goto abort;
}
if ( V_38 [ V_18 ] ) {
F_6 ( V_49 L_22
L_21 , F_7 ( V_3 ) , V_18 ) ;
goto abort;
}
V_38 [ V_18 ] = V_35 ;
F_14 ( V_3 -> V_50 , V_35 -> V_16 ,
V_35 -> V_51 << 9 ) ;
if ( V_35 -> V_16 -> V_52 -> V_53 -> V_54 ) {
F_15 ( V_3 -> V_53 , 1 ) ;
F_16 ( V_3 -> V_53 ,
V_55 - 1 ) ;
}
if ( ! V_34 || ( V_35 -> V_33 < V_34 -> V_33 ) )
V_34 = V_35 ;
V_40 ++ ;
}
if ( V_40 != V_3 -> V_9 ) {
F_6 ( V_49 L_23
L_21 , F_7 ( V_3 ) , V_40 , V_3 -> V_9 ) ;
goto abort;
}
V_39 -> V_11 = V_40 ;
V_39 -> V_27 = V_34 -> V_33 * V_40 ;
V_32 = V_39 -> V_27 ;
for ( V_12 = 1 ; V_12 < V_5 -> V_25 ; V_12 ++ )
{
int V_18 ;
V_39 = V_5 -> V_10 + V_12 ;
V_38 = V_5 -> V_8 + V_12 * V_3 -> V_9 ;
F_12 ( L_24 , F_7 ( V_3 ) , V_12 ) ;
V_39 -> V_28 = V_34 -> V_33 ;
V_34 = NULL ;
V_30 = 0 ;
for ( V_18 = 0 ; V_18 < V_40 ; V_18 ++ ) {
V_37 = V_5 -> V_8 [ V_18 ] ;
if ( V_37 -> V_33 <= V_39 -> V_28 ) {
F_12 ( L_25 ,
F_7 ( V_3 ) ,
F_8 ( V_37 -> V_16 , V_22 ) ) ;
continue;
}
F_12 ( L_26
L_27 ,
F_7 ( V_3 ) ,
F_8 ( V_37 -> V_16 , V_22 ) , V_30 ) ;
V_38 [ V_30 ] = V_37 ;
V_30 ++ ;
if ( ! V_34 || V_37 -> V_33 < V_34 -> V_33 ) {
V_34 = V_37 ;
F_12 ( L_28 ,
F_7 ( V_3 ) ,
( unsigned long long ) V_37 -> V_33 ) ;
}
}
V_39 -> V_11 = V_30 ;
V_33 = ( V_34 -> V_33 - V_39 -> V_28 ) * V_30 ;
F_12 ( L_29 ,
F_7 ( V_3 ) ,
V_39 -> V_11 , ( unsigned long long ) V_33 ) ;
V_32 += V_33 ;
V_39 -> V_27 = V_32 ;
F_12 ( L_30 ,
F_7 ( V_3 ) ,
( unsigned long long ) V_34 -> V_33 ) ;
}
V_3 -> V_53 -> V_17 . V_56 = F_1 ;
V_3 -> V_53 -> V_17 . V_57 = V_3 ;
if ( ( V_3 -> V_44 << 9 ) % F_17 ( V_3 -> V_53 ) ) {
F_6 ( V_49 L_31 ,
F_7 ( V_3 ) ,
V_3 -> V_44 << 9 ) ;
goto abort;
}
F_18 ( V_3 -> V_53 , V_3 -> V_44 << 9 ) ;
F_19 ( V_3 -> V_53 ,
( V_3 -> V_44 << 9 ) * V_3 -> V_9 ) ;
F_12 ( L_32 , F_7 ( V_3 ) ) ;
* V_29 = V_5 ;
return 0 ;
abort:
F_20 ( V_5 -> V_10 ) ;
F_20 ( V_5 -> V_8 ) ;
F_20 ( V_5 ) ;
* V_29 = NULL ;
return V_31 ;
}
static int F_21 ( struct V_14 * V_15 ,
struct V_58 * V_59 ,
struct V_60 * V_61 )
{
struct V_3 * V_3 = V_15 -> V_62 ;
T_1 V_63 = V_59 -> V_64 + F_22 ( V_59 -> V_65 ) ;
int V_66 ;
unsigned int V_44 = V_3 -> V_44 ;
unsigned int V_67 = V_59 -> V_68 >> 9 ;
if ( F_23 ( V_44 ) )
V_66 = ( V_44 - ( ( V_63 & ( V_44 - 1 ) )
+ V_67 ) ) << 9 ;
else
V_66 = ( V_44 - ( F_13 ( V_63 , V_44 )
+ V_67 ) ) << 9 ;
if ( V_66 < 0 ) V_66 = 0 ;
if ( V_66 <= V_61 -> V_69 && V_67 == 0 )
return V_61 -> V_69 ;
else
return V_66 ;
}
static T_1 F_24 ( struct V_3 * V_3 , T_1 V_33 , int V_9 )
{
T_1 V_70 = 0 ;
struct V_7 * V_37 ;
F_25 ( V_33 || V_9 ,
L_33 , V_71 ) ;
F_11 (rdev, &mddev->disks, same_set)
V_70 += V_37 -> V_33 ;
return V_70 ;
}
static int F_26 ( struct V_3 * V_3 )
{
struct V_4 * V_5 ;
int V_13 ;
if ( V_3 -> V_44 == 0 ) {
F_6 ( V_49 L_34 ,
F_7 ( V_3 ) ) ;
return - V_45 ;
}
if ( F_27 ( V_3 ) )
return - V_45 ;
F_28 ( V_3 -> V_53 , V_3 -> V_44 ) ;
if ( V_3 -> V_6 == NULL ) {
V_13 = F_9 ( V_3 , & V_5 ) ;
if ( V_13 < 0 )
return V_13 ;
V_3 -> V_6 = V_5 ;
}
V_5 = V_3 -> V_6 ;
F_29 ( V_3 , F_24 ( V_3 , 0 , 0 ) ) ;
F_6 ( V_24 L_35 ,
F_7 ( V_3 ) ,
( unsigned long long ) V_3 -> V_70 ) ;
{
int V_72 = V_3 -> V_9 *
( V_3 -> V_44 << 9 ) / V_73 ;
if ( V_3 -> V_53 -> V_17 . V_74 < 2 * V_72 )
V_3 -> V_53 -> V_17 . V_74 = 2 * V_72 ;
}
F_30 ( V_3 -> V_53 , F_21 ) ;
F_5 ( V_3 ) ;
return F_31 ( V_3 ) ;
}
static int F_32 ( struct V_3 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
F_33 ( V_3 -> V_53 ) ;
F_20 ( V_5 -> V_10 ) ;
F_20 ( V_5 -> V_8 ) ;
F_20 ( V_5 ) ;
V_3 -> V_6 = NULL ;
return 0 ;
}
static struct V_10 * F_34 ( struct V_4 * V_5 ,
T_1 * V_75 )
{
int V_12 ;
struct V_10 * V_76 = V_5 -> V_10 ;
T_1 V_63 = * V_75 ;
for ( V_12 = 0 ; V_12 < V_5 -> V_25 ; V_12 ++ )
if ( V_63 < V_76 [ V_12 ] . V_27 ) {
if ( V_12 )
* V_75 = V_63 - V_76 [ V_12 - 1 ] . V_27 ;
return V_76 + V_12 ;
}
F_35 () ;
}
static struct V_7 * F_36 ( struct V_3 * V_3 , struct V_10 * V_39 ,
T_1 V_63 , T_1 * V_77 )
{
unsigned int V_78 ;
T_1 V_79 ;
struct V_4 * V_5 = V_3 -> V_6 ;
int V_9 = V_5 -> V_10 [ 0 ] . V_11 ;
unsigned int V_80 = V_3 -> V_44 ;
if ( F_23 ( V_80 ) ) {
int V_81 = F_37 ( ~ V_80 ) ;
V_78 = V_63 & ( V_80 - 1 ) ;
V_63 >>= V_81 ;
V_79 = * V_77 ;
F_13 ( V_79 , V_39 -> V_11 << V_81 ) ;
} else{
V_78 = F_13 ( V_63 , V_80 ) ;
V_79 = * V_77 ;
F_13 ( V_79 , V_80 * V_39 -> V_11 ) ;
}
* V_77 = ( V_79 * V_80 ) + V_78 ;
return V_5 -> V_8 [ ( V_39 - V_5 -> V_10 ) * V_9
+ F_13 ( V_63 , V_39 -> V_11 ) ] ;
}
static inline int F_38 ( struct V_3 * V_3 ,
unsigned int V_80 , struct V_82 * V_82 )
{
if ( F_39 ( F_23 ( V_80 ) ) ) {
return V_80 >= ( ( V_82 -> V_64 & ( V_80 - 1 ) )
+ ( V_82 -> V_68 >> 9 ) ) ;
} else{
T_1 V_63 = V_82 -> V_64 ;
return V_80 >= ( F_13 ( V_63 , V_80 )
+ ( V_82 -> V_68 >> 9 ) ) ;
}
}
static void F_40 ( struct V_3 * V_3 , struct V_82 * V_82 )
{
unsigned int V_80 ;
T_1 V_77 ;
struct V_10 * V_39 ;
struct V_7 * V_83 ;
if ( F_41 ( V_82 -> V_84 & V_85 ) ) {
F_42 ( V_3 , V_82 ) ;
return;
}
V_80 = V_3 -> V_44 ;
if ( F_41 ( ! F_38 ( V_3 , V_80 , V_82 ) ) ) {
T_1 V_63 = V_82 -> V_64 ;
struct V_86 * V_87 ;
if ( V_82 -> V_88 != 1 ||
V_82 -> V_89 != 0 )
goto V_90;
if ( F_39 ( F_23 ( V_80 ) ) )
V_87 = F_43 ( V_82 , V_80 - ( V_63 &
( V_80 - 1 ) ) ) ;
else
V_87 = F_43 ( V_82 , V_80 -
F_13 ( V_63 , V_80 ) ) ;
F_40 ( V_3 , & V_87 -> V_91 ) ;
F_40 ( V_3 , & V_87 -> V_92 ) ;
F_44 ( V_87 ) ;
return;
}
V_77 = V_82 -> V_64 ;
V_39 = F_34 ( V_3 -> V_6 , & V_77 ) ;
V_83 = F_36 ( V_3 , V_39 , V_82 -> V_64 ,
& V_77 ) ;
V_82 -> V_65 = V_83 -> V_16 ;
V_82 -> V_64 = V_77 + V_39 -> V_28 +
V_83 -> V_51 ;
F_45 ( V_82 ) ;
return;
V_90:
F_6 ( L_36
L_37 ,
F_7 ( V_3 ) , V_80 / 2 ,
( unsigned long long ) V_82 -> V_64 , V_82 -> V_68 >> 10 ) ;
F_46 ( V_82 ) ;
return;
}
static void F_47 ( struct V_93 * V_94 , struct V_3 * V_3 )
{
F_48 ( V_94 , L_38 , V_3 -> V_44 / 2 ) ;
return;
}
static void * F_49 ( struct V_3 * V_3 )
{
struct V_7 * V_37 ;
struct V_4 * V_95 ;
if ( V_3 -> V_96 != 1 ) {
F_6 ( V_49 L_39 ,
F_7 ( V_3 ) ,
V_3 -> V_96 ) ;
return F_50 ( - V_45 ) ;
}
F_11 (rdev, &mddev->disks, same_set) {
if ( V_37 -> V_46 == V_3 -> V_9 - 1 ) {
F_6 ( V_49 L_40 ,
F_7 ( V_3 ) ) ;
return F_50 ( - V_45 ) ;
}
}
V_3 -> V_97 = 0 ;
V_3 -> V_98 = 0 ;
V_3 -> V_99 = V_3 -> V_44 ;
V_3 -> V_9 -- ;
V_3 -> V_100 = - 1 ;
V_3 -> V_101 = V_102 ;
F_9 ( V_3 , & V_95 ) ;
return V_95 ;
}
static void * F_51 ( struct V_3 * V_3 )
{
struct V_4 * V_95 ;
if ( V_3 -> V_103 != ( ( 1 << 8 ) + 2 ) ) {
F_6 ( V_49 L_41 ,
F_7 ( V_3 ) ,
V_3 -> V_103 ) ;
return F_50 ( - V_45 ) ;
}
if ( V_3 -> V_9 & 1 ) {
F_6 ( V_49 L_42 ,
F_7 ( V_3 ) ) ;
return F_50 ( - V_45 ) ;
}
if ( V_3 -> V_96 != ( V_3 -> V_9 >> 1 ) ) {
F_6 ( V_49 L_43 ,
F_7 ( V_3 ) ) ;
return F_50 ( - V_45 ) ;
}
V_3 -> V_97 = 0 ;
V_3 -> V_98 = 0 ;
V_3 -> V_99 = V_3 -> V_44 ;
V_3 -> V_100 = - V_3 -> V_9 / 2 ;
V_3 -> V_9 += V_3 -> V_100 ;
V_3 -> V_96 = 0 ;
V_3 -> V_101 = V_102 ;
F_9 ( V_3 , & V_95 ) ;
return V_95 ;
}
static void * F_52 ( struct V_3 * V_3 )
{
struct V_4 * V_95 ;
if ( ( V_3 -> V_9 - 1 ) != V_3 -> V_96 ) {
F_6 ( V_49 L_44 ,
F_7 ( V_3 ) ) ;
return F_50 ( - V_45 ) ;
}
V_3 -> V_97 = 0 ;
V_3 -> V_98 = 0 ;
V_3 -> V_99 = 128 ;
V_3 -> V_100 = 1 - V_3 -> V_9 ;
V_3 -> V_9 = 1 ;
V_3 -> V_101 = V_102 ;
F_9 ( V_3 , & V_95 ) ;
return V_95 ;
}
static void * F_53 ( struct V_3 * V_3 )
{
if ( V_3 -> V_47 == 4 )
return F_49 ( V_3 ) ;
if ( V_3 -> V_47 == 5 ) {
if ( V_3 -> V_103 == V_104 )
return F_49 ( V_3 ) ;
F_6 ( V_49 L_45 ,
F_7 ( V_3 ) , V_104 ) ;
}
if ( V_3 -> V_47 == 10 )
return F_51 ( V_3 ) ;
if ( V_3 -> V_47 == 1 )
return F_52 ( V_3 ) ;
F_6 ( V_49 L_46 ,
V_3 -> V_47 ) ;
return F_50 ( - V_45 ) ;
}
static void F_54 ( struct V_3 * V_3 , int V_105 )
{
}
static int T_2 F_55 ( void )
{
return F_56 ( & V_106 ) ;
}
static void F_57 ( void )
{
F_58 ( & V_106 ) ;
}
