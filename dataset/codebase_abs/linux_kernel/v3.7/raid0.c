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
bool V_43 = false ;
if ( ! V_5 )
return - V_44 ;
F_11 (rdev1, mddev) {
F_12 ( L_11 ,
F_7 ( V_3 ) ,
F_8 ( V_35 -> V_16 , V_22 ) ) ;
V_30 = 0 ;
V_33 = V_35 -> V_33 ;
F_13 ( V_33 , V_3 -> V_45 ) ;
V_35 -> V_33 = V_33 * V_3 -> V_45 ;
F_11 (rdev2, mddev) {
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
V_31 = - V_44 ;
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
V_31 = - V_46 ;
F_11 (rdev1, mddev) {
int V_18 = V_35 -> V_47 ;
if ( V_3 -> V_48 == 10 ) {
V_18 /= 2 ;
V_35 -> V_49 = V_18 ;
}
if ( V_3 -> V_48 == 1 ) {
V_18 = 0 ;
V_35 -> V_49 = V_18 ;
}
if ( V_18 < 0 || V_18 >= V_3 -> V_9 ) {
F_6 ( V_50 L_20
L_21 , F_7 ( V_3 ) , V_18 ) ;
goto abort;
}
if ( V_38 [ V_18 ] ) {
F_6 ( V_50 L_22
L_21 , F_7 ( V_3 ) , V_18 ) ;
goto abort;
}
V_38 [ V_18 ] = V_35 ;
F_14 ( V_3 -> V_51 , V_35 -> V_16 ,
V_35 -> V_52 << 9 ) ;
if ( V_35 -> V_16 -> V_53 -> V_54 -> V_55 )
V_5 -> V_56 = 1 ;
if ( ! V_34 || ( V_35 -> V_33 < V_34 -> V_33 ) )
V_34 = V_35 ;
V_40 ++ ;
if ( F_15 ( F_3 ( V_35 -> V_16 ) ) )
V_43 = true ;
}
if ( V_40 != V_3 -> V_9 ) {
F_6 ( V_50 L_23
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
V_3 -> V_54 -> V_17 . V_57 = F_1 ;
V_3 -> V_54 -> V_17 . V_58 = V_3 ;
if ( ( V_3 -> V_45 << 9 ) % F_16 ( V_3 -> V_54 ) ) {
F_6 ( V_50 L_31 ,
F_7 ( V_3 ) ,
V_3 -> V_45 << 9 ) ;
goto abort;
}
F_17 ( V_3 -> V_54 , V_3 -> V_45 << 9 ) ;
F_18 ( V_3 -> V_54 ,
( V_3 -> V_45 << 9 ) * V_3 -> V_9 ) ;
if ( ! V_43 )
F_19 ( V_59 , V_3 -> V_54 ) ;
else
F_20 ( V_59 , V_3 -> V_54 ) ;
F_12 ( L_32 , F_7 ( V_3 ) ) ;
* V_29 = V_5 ;
return 0 ;
abort:
F_21 ( V_5 -> V_10 ) ;
F_21 ( V_5 -> V_8 ) ;
F_21 ( V_5 ) ;
* V_29 = NULL ;
return V_31 ;
}
static struct V_10 * F_22 ( struct V_4 * V_5 ,
T_1 * V_60 )
{
int V_12 ;
struct V_10 * V_61 = V_5 -> V_10 ;
T_1 V_62 = * V_60 ;
for ( V_12 = 0 ; V_12 < V_5 -> V_25 ; V_12 ++ )
if ( V_62 < V_61 [ V_12 ] . V_27 ) {
if ( V_12 )
* V_60 = V_62 - V_61 [ V_12 - 1 ] . V_27 ;
return V_61 + V_12 ;
}
F_23 () ;
}
static struct V_7 * F_24 ( struct V_3 * V_3 , struct V_10 * V_39 ,
T_1 V_62 , T_1 * V_63 )
{
unsigned int V_64 ;
T_1 V_65 ;
struct V_4 * V_5 = V_3 -> V_6 ;
int V_9 = V_5 -> V_10 [ 0 ] . V_11 ;
unsigned int V_66 = V_3 -> V_45 ;
if ( F_25 ( V_66 ) ) {
int V_67 = F_26 ( ~ V_66 ) ;
V_64 = V_62 & ( V_66 - 1 ) ;
V_62 >>= V_67 ;
V_65 = * V_63 ;
F_13 ( V_65 , V_39 -> V_11 << V_67 ) ;
} else{
V_64 = F_13 ( V_62 , V_66 ) ;
V_65 = * V_63 ;
F_13 ( V_65 , V_66 * V_39 -> V_11 ) ;
}
* V_63 = ( V_65 * V_66 ) + V_64 ;
return V_5 -> V_8 [ ( V_39 - V_5 -> V_10 ) * V_9
+ F_13 ( V_62 , V_39 -> V_11 ) ] ;
}
static int F_27 ( struct V_14 * V_15 ,
struct V_68 * V_69 ,
struct V_70 * V_71 )
{
struct V_3 * V_3 = V_15 -> V_72 ;
struct V_4 * V_5 = V_3 -> V_6 ;
T_1 V_62 = V_69 -> V_73 + F_28 ( V_69 -> V_74 ) ;
T_1 V_63 = V_62 ;
int V_75 ;
unsigned int V_45 = V_3 -> V_45 ;
unsigned int V_76 = V_69 -> V_77 >> 9 ;
struct V_10 * V_39 ;
struct V_7 * V_37 ;
struct V_14 * V_78 ;
if ( F_25 ( V_45 ) )
V_75 = ( V_45 - ( ( V_62 & ( V_45 - 1 ) )
+ V_76 ) ) << 9 ;
else
V_75 = ( V_45 - ( F_13 ( V_62 , V_45 )
+ V_76 ) ) << 9 ;
if ( V_75 < 0 )
V_75 = 0 ;
if ( V_75 <= V_71 -> V_79 && V_76 == 0 )
return V_71 -> V_79 ;
if ( V_75 < V_71 -> V_79 )
return V_75 ;
if ( ! V_5 -> V_56 )
return V_75 ;
V_62 = V_63 ;
V_39 = F_22 ( V_3 -> V_6 , & V_63 ) ;
V_37 = F_24 ( V_3 , V_39 , V_62 , & V_63 ) ;
V_78 = F_3 ( V_37 -> V_16 ) ;
if ( V_78 -> V_55 ) {
V_69 -> V_74 = V_37 -> V_16 ;
V_69 -> V_73 = V_63 + V_39 -> V_28 +
V_37 -> V_52 ;
return F_29 ( V_75 , V_78 -> V_55 ( V_78 , V_69 , V_71 ) ) ;
} else
return V_75 ;
}
static T_1 F_30 ( struct V_3 * V_3 , T_1 V_33 , int V_9 )
{
T_1 V_80 = 0 ;
struct V_7 * V_37 ;
F_31 ( V_33 || V_9 ,
L_33 , V_81 ) ;
F_11 (rdev, mddev)
V_80 += V_37 -> V_33 ;
return V_80 ;
}
static int F_32 ( struct V_3 * V_3 )
{
struct V_4 * V_5 ;
int V_13 ;
if ( V_3 -> V_45 == 0 ) {
F_6 ( V_50 L_34 ,
F_7 ( V_3 ) ) ;
return - V_46 ;
}
if ( F_33 ( V_3 ) )
return - V_46 ;
F_34 ( V_3 -> V_54 , V_3 -> V_45 ) ;
F_35 ( V_3 -> V_54 , V_3 -> V_45 ) ;
F_36 ( V_3 -> V_54 , V_3 -> V_45 ) ;
if ( V_3 -> V_6 == NULL ) {
V_13 = F_9 ( V_3 , & V_5 ) ;
if ( V_13 < 0 )
return V_13 ;
V_3 -> V_6 = V_5 ;
}
V_5 = V_3 -> V_6 ;
F_37 ( V_3 , F_30 ( V_3 , 0 , 0 ) ) ;
F_6 ( V_24 L_35 ,
F_7 ( V_3 ) ,
( unsigned long long ) V_3 -> V_80 ) ;
{
int V_82 = V_3 -> V_9 *
( V_3 -> V_45 << 9 ) / V_83 ;
if ( V_3 -> V_54 -> V_17 . V_84 < 2 * V_82 )
V_3 -> V_54 -> V_17 . V_84 = 2 * V_82 ;
}
F_38 ( V_3 -> V_54 , F_27 ) ;
F_5 ( V_3 ) ;
V_13 = F_39 ( V_3 ) ;
if ( V_13 )
F_40 ( V_3 ) ;
return V_13 ;
}
static int F_40 ( struct V_3 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
F_41 ( V_3 -> V_54 ) ;
F_21 ( V_5 -> V_10 ) ;
F_21 ( V_5 -> V_8 ) ;
F_21 ( V_5 ) ;
V_3 -> V_6 = NULL ;
return 0 ;
}
static inline int F_42 ( struct V_3 * V_3 ,
unsigned int V_66 , struct V_85 * V_85 )
{
if ( F_43 ( F_25 ( V_66 ) ) ) {
return V_66 >= ( ( V_85 -> V_73 & ( V_66 - 1 ) )
+ ( V_85 -> V_77 >> 9 ) ) ;
} else{
T_1 V_62 = V_85 -> V_73 ;
return V_66 >= ( F_13 ( V_62 , V_66 )
+ ( V_85 -> V_77 >> 9 ) ) ;
}
}
static void F_44 ( struct V_3 * V_3 , struct V_85 * V_85 )
{
unsigned int V_66 ;
T_1 V_63 ;
struct V_10 * V_39 ;
struct V_7 * V_86 ;
if ( F_45 ( V_85 -> V_87 & V_88 ) ) {
F_46 ( V_3 , V_85 ) ;
return;
}
V_66 = V_3 -> V_45 ;
if ( F_45 ( ! F_42 ( V_3 , V_66 , V_85 ) ) ) {
T_1 V_62 = V_85 -> V_73 ;
struct V_89 * V_90 ;
if ( ( V_85 -> V_91 != 1 && V_85 -> V_91 != 0 ) ||
V_85 -> V_92 != 0 )
goto V_93;
if ( F_43 ( F_25 ( V_66 ) ) )
V_90 = F_47 ( V_85 , V_66 - ( V_62 &
( V_66 - 1 ) ) ) ;
else
V_90 = F_47 ( V_85 , V_66 -
F_13 ( V_62 , V_66 ) ) ;
F_44 ( V_3 , & V_90 -> V_94 ) ;
F_44 ( V_3 , & V_90 -> V_95 ) ;
F_48 ( V_90 ) ;
return;
}
V_63 = V_85 -> V_73 ;
V_39 = F_22 ( V_3 -> V_6 , & V_63 ) ;
V_86 = F_24 ( V_3 , V_39 , V_85 -> V_73 ,
& V_63 ) ;
V_85 -> V_74 = V_86 -> V_16 ;
V_85 -> V_73 = V_63 + V_39 -> V_28 +
V_86 -> V_52 ;
if ( F_45 ( ( V_85 -> V_87 & V_96 ) &&
! F_15 ( F_3 ( V_85 -> V_74 ) ) ) ) {
F_49 ( V_85 , 0 ) ;
return;
}
F_50 ( V_85 ) ;
return;
V_93:
F_6 ( L_36
L_37 ,
F_7 ( V_3 ) , V_66 / 2 ,
( unsigned long long ) V_85 -> V_73 , V_85 -> V_77 >> 10 ) ;
F_51 ( V_85 ) ;
return;
}
static void F_52 ( struct V_97 * V_98 , struct V_3 * V_3 )
{
F_53 ( V_98 , L_38 , V_3 -> V_45 / 2 ) ;
return;
}
static void * F_54 ( struct V_3 * V_3 )
{
struct V_7 * V_37 ;
struct V_4 * V_99 ;
if ( V_3 -> V_100 != 1 ) {
F_6 ( V_50 L_39 ,
F_7 ( V_3 ) ,
V_3 -> V_100 ) ;
return F_55 ( - V_46 ) ;
}
F_11 (rdev, mddev) {
if ( V_37 -> V_47 == V_3 -> V_9 - 1 ) {
F_6 ( V_50 L_40 ,
F_7 ( V_3 ) ) ;
return F_55 ( - V_46 ) ;
}
}
V_3 -> V_101 = 0 ;
V_3 -> V_102 = 0 ;
V_3 -> V_103 = V_3 -> V_45 ;
V_3 -> V_9 -- ;
V_3 -> V_104 = - 1 ;
V_3 -> V_105 = V_106 ;
F_9 ( V_3 , & V_99 ) ;
return V_99 ;
}
static void * F_56 ( struct V_3 * V_3 )
{
struct V_4 * V_99 ;
if ( V_3 -> V_107 != ( ( 1 << 8 ) + 2 ) ) {
F_6 ( V_50 L_41 ,
F_7 ( V_3 ) ,
V_3 -> V_107 ) ;
return F_55 ( - V_46 ) ;
}
if ( V_3 -> V_9 & 1 ) {
F_6 ( V_50 L_42 ,
F_7 ( V_3 ) ) ;
return F_55 ( - V_46 ) ;
}
if ( V_3 -> V_100 != ( V_3 -> V_9 >> 1 ) ) {
F_6 ( V_50 L_43 ,
F_7 ( V_3 ) ) ;
return F_55 ( - V_46 ) ;
}
V_3 -> V_101 = 0 ;
V_3 -> V_102 = 0 ;
V_3 -> V_103 = V_3 -> V_45 ;
V_3 -> V_104 = - V_3 -> V_9 / 2 ;
V_3 -> V_9 += V_3 -> V_104 ;
V_3 -> V_100 = 0 ;
V_3 -> V_105 = V_106 ;
F_9 ( V_3 , & V_99 ) ;
return V_99 ;
}
static void * F_57 ( struct V_3 * V_3 )
{
struct V_4 * V_99 ;
int V_108 ;
if ( ( V_3 -> V_9 - 1 ) != V_3 -> V_100 ) {
F_6 ( V_50 L_44 ,
F_7 ( V_3 ) ) ;
return F_55 ( - V_46 ) ;
}
V_108 = 64 * 2 ;
while ( V_108 && ( V_3 -> V_80 & ( V_108 - 1 ) ) )
V_108 >>= 1 ;
if ( ( V_108 << 9 ) < V_83 )
return F_55 ( - V_46 ) ;
V_3 -> V_101 = 0 ;
V_3 -> V_102 = 0 ;
V_3 -> V_103 = V_108 ;
V_3 -> V_45 = V_108 ;
V_3 -> V_104 = 1 - V_3 -> V_9 ;
V_3 -> V_9 = 1 ;
V_3 -> V_105 = V_106 ;
F_9 ( V_3 , & V_99 ) ;
return V_99 ;
}
static void * F_58 ( struct V_3 * V_3 )
{
if ( V_3 -> V_48 == 4 )
return F_54 ( V_3 ) ;
if ( V_3 -> V_48 == 5 ) {
if ( V_3 -> V_107 == V_109 )
return F_54 ( V_3 ) ;
F_6 ( V_50 L_45 ,
F_7 ( V_3 ) , V_109 ) ;
}
if ( V_3 -> V_48 == 10 )
return F_56 ( V_3 ) ;
if ( V_3 -> V_48 == 1 )
return F_57 ( V_3 ) ;
F_6 ( V_50 L_46 ,
V_3 -> V_48 ) ;
return F_55 ( - V_46 ) ;
}
static void F_59 ( struct V_3 * V_3 , int V_110 )
{
}
static int T_2 F_60 ( void )
{
return F_61 ( & V_111 ) ;
}
static void F_62 ( void )
{
F_63 ( & V_111 ) ;
}
