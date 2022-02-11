static int F_1 ( struct V_1 * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
struct V_6 * * V_7 = V_4 -> V_7 ;
int V_8 = V_4 -> V_9 [ 0 ] . V_10 ;
int V_11 , V_12 = 0 ;
for ( V_11 = 0 ; V_11 < V_8 && ! V_12 ; V_11 ++ ) {
struct V_13 * V_14 = F_2 ( V_7 [ V_11 ] -> V_15 ) ;
V_12 |= F_3 ( & V_14 -> V_16 , V_2 ) ;
}
return V_12 ;
}
static void F_4 ( struct V_1 * V_1 )
{
int V_17 , V_18 ;
T_1 V_19 = 0 ;
T_1 V_20 = 0 ;
char V_21 [ V_22 ] ;
struct V_3 * V_4 = V_1 -> V_5 ;
int V_8 = V_4 -> V_9 [ 0 ] . V_10 ;
F_5 ( V_23 L_1 ,
F_6 ( V_1 ) ,
V_4 -> V_24 , V_4 -> V_24 == 1 ? L_2 : L_3 ) ;
for ( V_17 = 0 ; V_17 < V_4 -> V_24 ; V_17 ++ ) {
F_5 ( V_23 L_4 , V_17 ) ;
for ( V_18 = 0 ; V_18 < V_4 -> V_9 [ V_17 ] . V_10 ; V_18 ++ )
F_5 ( V_25 L_5 , V_18 ? L_6 : L_2 ,
F_7 ( V_4 -> V_7 [ V_17 * V_8
+ V_18 ] -> V_15 , V_21 ) ) ;
F_5 ( V_25 L_7 ) ;
V_19 = V_4 -> V_9 [ V_17 ] . V_26 - V_20 ;
F_5 ( V_23 L_8
L_9 ,
( unsigned long long ) V_20 >> 1 ,
( unsigned long long ) V_4 -> V_9 [ V_17 ] . V_27 >> 1 ,
( unsigned long long ) V_19 >> 1 ) ;
V_20 = V_4 -> V_9 [ V_17 ] . V_26 ;
}
F_5 ( V_23 L_10 ) ;
}
static int F_8 ( struct V_1 * V_1 , struct V_3 * * V_28 )
{
int V_11 , V_29 , V_30 ;
T_1 V_31 , V_32 ;
struct V_6 * V_33 , * V_34 , * V_35 , * V_36 , * * V_37 ;
struct V_9 * V_38 ;
int V_39 ;
char V_21 [ V_22 ] ;
char V_40 [ V_22 ] ;
struct V_3 * V_4 = F_9 ( sizeof( * V_4 ) , V_41 ) ;
bool V_42 = false ;
if ( ! V_4 )
return - V_43 ;
F_10 (rdev1, mddev) {
F_11 ( L_11 ,
F_6 ( V_1 ) ,
F_7 ( V_34 -> V_15 , V_21 ) ) ;
V_29 = 0 ;
V_32 = V_34 -> V_32 ;
F_12 ( V_32 , V_1 -> V_44 ) ;
V_34 -> V_32 = V_32 * V_1 -> V_44 ;
F_10 (rdev2, mddev) {
F_11 ( L_12
L_13 ,
F_6 ( V_1 ) ,
F_7 ( V_34 -> V_15 , V_21 ) ,
( unsigned long long ) V_34 -> V_32 ,
F_7 ( V_35 -> V_15 , V_40 ) ,
( unsigned long long ) V_35 -> V_32 ) ;
if ( V_35 == V_34 ) {
F_11 ( L_14 ,
F_6 ( V_1 ) ) ;
break;
}
if ( V_35 -> V_32 == V_34 -> V_32 ) {
F_11 ( L_15 ,
F_6 ( V_1 ) ) ;
V_29 = 1 ;
break;
}
F_11 ( L_16 ,
F_6 ( V_1 ) ) ;
}
if ( ! V_29 ) {
F_11 ( L_17 ,
F_6 ( V_1 ) ) ;
V_4 -> V_24 ++ ;
F_11 ( L_18 ,
F_6 ( V_1 ) , V_4 -> V_24 ) ;
}
}
F_11 ( L_19 ,
F_6 ( V_1 ) , V_4 -> V_24 ) ;
V_30 = - V_43 ;
V_4 -> V_9 = F_9 ( sizeof( struct V_9 ) *
V_4 -> V_24 , V_41 ) ;
if ( ! V_4 -> V_9 )
goto abort;
V_4 -> V_7 = F_9 ( sizeof( struct V_6 * ) *
V_4 -> V_24 * V_1 -> V_8 ,
V_41 ) ;
if ( ! V_4 -> V_7 )
goto abort;
V_38 = & V_4 -> V_9 [ 0 ] ;
V_39 = 0 ;
V_33 = NULL ;
V_37 = V_4 -> V_7 ;
V_30 = - V_45 ;
F_10 (rdev1, mddev) {
int V_17 = V_34 -> V_46 ;
if ( V_1 -> V_47 == 10 ) {
V_17 /= 2 ;
V_34 -> V_48 = V_17 ;
}
if ( V_1 -> V_47 == 1 ) {
V_17 = 0 ;
V_34 -> V_48 = V_17 ;
}
if ( V_17 < 0 ) {
F_5 ( V_49
L_20 ,
F_6 ( V_1 ) ) ;
goto abort;
}
if ( V_17 >= V_1 -> V_8 ) {
F_5 ( V_49 L_21
L_22 , F_6 ( V_1 ) , V_17 ) ;
goto abort;
}
if ( V_37 [ V_17 ] ) {
F_5 ( V_49 L_23
L_22 , F_6 ( V_1 ) , V_17 ) ;
goto abort;
}
V_37 [ V_17 ] = V_34 ;
F_13 ( V_1 -> V_50 , V_34 -> V_15 ,
V_34 -> V_51 << 9 ) ;
if ( V_34 -> V_15 -> V_52 -> V_53 -> V_54 )
V_4 -> V_55 = 1 ;
if ( ! V_33 || ( V_34 -> V_32 < V_33 -> V_32 ) )
V_33 = V_34 ;
V_39 ++ ;
if ( F_14 ( F_2 ( V_34 -> V_15 ) ) )
V_42 = true ;
}
if ( V_39 != V_1 -> V_8 ) {
F_5 ( V_49 L_24
L_22 , F_6 ( V_1 ) , V_39 , V_1 -> V_8 ) ;
goto abort;
}
V_38 -> V_10 = V_39 ;
V_38 -> V_26 = V_33 -> V_32 * V_39 ;
V_31 = V_38 -> V_26 ;
for ( V_11 = 1 ; V_11 < V_4 -> V_24 ; V_11 ++ )
{
int V_17 ;
V_38 = V_4 -> V_9 + V_11 ;
V_37 = V_4 -> V_7 + V_11 * V_1 -> V_8 ;
F_11 ( L_25 , F_6 ( V_1 ) , V_11 ) ;
V_38 -> V_27 = V_33 -> V_32 ;
V_33 = NULL ;
V_29 = 0 ;
for ( V_17 = 0 ; V_17 < V_39 ; V_17 ++ ) {
V_36 = V_4 -> V_7 [ V_17 ] ;
if ( V_36 -> V_32 <= V_38 -> V_27 ) {
F_11 ( L_26 ,
F_6 ( V_1 ) ,
F_7 ( V_36 -> V_15 , V_21 ) ) ;
continue;
}
F_11 ( L_27
L_28 ,
F_6 ( V_1 ) ,
F_7 ( V_36 -> V_15 , V_21 ) , V_29 ) ;
V_37 [ V_29 ] = V_36 ;
V_29 ++ ;
if ( ! V_33 || V_36 -> V_32 < V_33 -> V_32 ) {
V_33 = V_36 ;
F_11 ( L_29 ,
F_6 ( V_1 ) ,
( unsigned long long ) V_36 -> V_32 ) ;
}
}
V_38 -> V_10 = V_29 ;
V_32 = ( V_33 -> V_32 - V_38 -> V_27 ) * V_29 ;
F_11 ( L_30 ,
F_6 ( V_1 ) ,
V_38 -> V_10 , ( unsigned long long ) V_32 ) ;
V_31 += V_32 ;
V_38 -> V_26 = V_31 ;
F_11 ( L_31 ,
F_6 ( V_1 ) ,
( unsigned long long ) V_33 -> V_32 ) ;
}
if ( ( V_1 -> V_44 << 9 ) % F_15 ( V_1 -> V_53 ) ) {
F_5 ( V_49 L_32 ,
F_6 ( V_1 ) ,
V_1 -> V_44 << 9 ) ;
goto abort;
}
F_16 ( V_1 -> V_53 , V_1 -> V_44 << 9 ) ;
F_17 ( V_1 -> V_53 ,
( V_1 -> V_44 << 9 ) * V_1 -> V_8 ) ;
if ( ! V_42 )
F_18 ( V_56 , V_1 -> V_53 ) ;
else
F_19 ( V_56 , V_1 -> V_53 ) ;
F_11 ( L_33 , F_6 ( V_1 ) ) ;
* V_28 = V_4 ;
return 0 ;
abort:
F_20 ( V_4 -> V_9 ) ;
F_20 ( V_4 -> V_7 ) ;
F_20 ( V_4 ) ;
* V_28 = F_21 ( V_30 ) ;
return V_30 ;
}
static struct V_9 * F_22 ( struct V_3 * V_4 ,
T_1 * V_57 )
{
int V_11 ;
struct V_9 * V_58 = V_4 -> V_9 ;
T_1 V_59 = * V_57 ;
for ( V_11 = 0 ; V_11 < V_4 -> V_24 ; V_11 ++ )
if ( V_59 < V_58 [ V_11 ] . V_26 ) {
if ( V_11 )
* V_57 = V_59 - V_58 [ V_11 - 1 ] . V_26 ;
return V_58 + V_11 ;
}
F_23 () ;
}
static struct V_6 * F_24 ( struct V_1 * V_1 , struct V_9 * V_38 ,
T_1 V_59 , T_1 * V_60 )
{
unsigned int V_61 ;
T_1 V_62 ;
struct V_3 * V_4 = V_1 -> V_5 ;
int V_8 = V_4 -> V_9 [ 0 ] . V_10 ;
unsigned int V_63 = V_1 -> V_44 ;
if ( F_25 ( V_63 ) ) {
int V_64 = F_26 ( ~ V_63 ) ;
V_61 = V_59 & ( V_63 - 1 ) ;
V_59 >>= V_64 ;
V_62 = * V_60 ;
F_12 ( V_62 , V_38 -> V_10 << V_64 ) ;
} else{
V_61 = F_12 ( V_59 , V_63 ) ;
V_62 = * V_60 ;
F_12 ( V_62 , V_63 * V_38 -> V_10 ) ;
}
* V_60 = ( V_62 * V_63 ) + V_61 ;
return V_4 -> V_7 [ ( V_38 - V_4 -> V_9 ) * V_8
+ F_12 ( V_59 , V_38 -> V_10 ) ] ;
}
static int F_27 ( struct V_1 * V_1 ,
struct V_65 * V_66 ,
struct V_67 * V_68 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
T_1 V_59 = V_66 -> V_69 + F_28 ( V_66 -> V_70 ) ;
T_1 V_60 = V_59 ;
int V_71 ;
unsigned int V_44 = V_1 -> V_44 ;
unsigned int V_72 = V_66 -> V_73 >> 9 ;
struct V_9 * V_38 ;
struct V_6 * V_36 ;
struct V_13 * V_74 ;
if ( F_25 ( V_44 ) )
V_71 = ( V_44 - ( ( V_59 & ( V_44 - 1 ) )
+ V_72 ) ) << 9 ;
else
V_71 = ( V_44 - ( F_12 ( V_59 , V_44 )
+ V_72 ) ) << 9 ;
if ( V_71 < 0 )
V_71 = 0 ;
if ( V_71 <= V_68 -> V_75 && V_72 == 0 )
return V_68 -> V_75 ;
if ( V_71 < V_68 -> V_75 )
return V_71 ;
if ( ! V_4 -> V_55 )
return V_71 ;
V_59 = V_60 ;
V_38 = F_22 ( V_1 -> V_5 , & V_60 ) ;
V_36 = F_24 ( V_1 , V_38 , V_59 , & V_60 ) ;
V_74 = F_2 ( V_36 -> V_15 ) ;
if ( V_74 -> V_54 ) {
V_66 -> V_70 = V_36 -> V_15 ;
V_66 -> V_69 = V_60 + V_38 -> V_27 +
V_36 -> V_51 ;
return F_29 ( V_71 , V_74 -> V_54 ( V_74 , V_66 , V_68 ) ) ;
} else
return V_71 ;
}
static T_1 F_30 ( struct V_1 * V_1 , T_1 V_32 , int V_8 )
{
T_1 V_76 = 0 ;
struct V_6 * V_36 ;
F_31 ( V_32 || V_8 ,
L_34 , V_77 ) ;
F_10 (rdev, mddev)
V_76 += ( V_36 -> V_32 &
~ ( T_1 ) ( V_1 -> V_44 - 1 ) ) ;
return V_76 ;
}
static int F_32 ( struct V_1 * V_1 )
{
struct V_3 * V_4 ;
int V_12 ;
if ( V_1 -> V_44 == 0 ) {
F_5 ( V_49 L_35 ,
F_6 ( V_1 ) ) ;
return - V_45 ;
}
if ( F_33 ( V_1 ) )
return - V_45 ;
F_34 ( V_1 -> V_53 , V_1 -> V_44 ) ;
F_35 ( V_1 -> V_53 , V_1 -> V_44 ) ;
F_36 ( V_1 -> V_53 , V_1 -> V_44 ) ;
if ( V_1 -> V_5 == NULL ) {
V_12 = F_8 ( V_1 , & V_4 ) ;
if ( V_12 < 0 )
return V_12 ;
V_1 -> V_5 = V_4 ;
}
V_4 = V_1 -> V_5 ;
F_37 ( V_1 , F_30 ( V_1 , 0 , 0 ) ) ;
F_5 ( V_23 L_36 ,
F_6 ( V_1 ) ,
( unsigned long long ) V_1 -> V_76 ) ;
{
int V_78 = V_1 -> V_8 *
( V_1 -> V_44 << 9 ) / V_79 ;
if ( V_1 -> V_53 -> V_16 . V_80 < 2 * V_78 )
V_1 -> V_53 -> V_16 . V_80 = 2 * V_78 ;
}
F_4 ( V_1 ) ;
V_12 = F_38 ( V_1 ) ;
return V_12 ;
}
static void F_39 ( struct V_1 * V_1 , void * V_81 )
{
struct V_3 * V_4 = V_81 ;
F_20 ( V_4 -> V_9 ) ;
F_20 ( V_4 -> V_7 ) ;
F_20 ( V_4 ) ;
}
static inline int F_40 ( struct V_1 * V_1 ,
unsigned int V_63 , struct V_82 * V_82 )
{
if ( F_41 ( F_25 ( V_63 ) ) ) {
return V_63 >=
( ( V_82 -> V_83 . V_69 & ( V_63 - 1 ) )
+ V_72 ( V_82 ) ) ;
} else{
T_1 V_59 = V_82 -> V_83 . V_69 ;
return V_63 >= ( F_12 ( V_59 , V_63 )
+ V_72 ( V_82 ) ) ;
}
}
static void F_42 ( struct V_1 * V_1 , struct V_82 * V_82 )
{
struct V_9 * V_38 ;
struct V_6 * V_84 ;
struct V_82 * V_85 ;
if ( F_43 ( V_82 -> V_86 & V_87 ) ) {
F_44 ( V_1 , V_82 ) ;
return;
}
do {
T_1 V_59 = V_82 -> V_83 . V_69 ;
unsigned V_63 = V_1 -> V_44 ;
unsigned V_32 = V_63 -
( F_41 ( F_25 ( V_63 ) )
? ( V_59 & ( V_63 - 1 ) )
: F_12 ( V_59 , V_63 ) ) ;
if ( V_32 < V_72 ( V_82 ) ) {
V_85 = F_45 ( V_82 , V_32 , V_88 , V_89 ) ;
F_46 ( V_85 , V_82 ) ;
} else {
V_85 = V_82 ;
}
V_38 = F_22 ( V_1 -> V_5 , & V_59 ) ;
V_84 = F_24 ( V_1 , V_38 , V_59 , & V_59 ) ;
V_85 -> V_70 = V_84 -> V_15 ;
V_85 -> V_83 . V_69 = V_59 + V_38 -> V_27 +
V_84 -> V_51 ;
if ( F_43 ( ( V_85 -> V_86 & V_90 ) &&
! F_14 ( F_2 ( V_85 -> V_70 ) ) ) ) {
F_47 ( V_85 , 0 ) ;
} else
F_48 ( V_85 ) ;
} while ( V_85 != V_82 );
}
static void F_49 ( struct V_91 * V_92 , struct V_1 * V_1 )
{
F_50 ( V_92 , L_37 , V_1 -> V_44 / 2 ) ;
return;
}
static void * F_51 ( struct V_1 * V_1 )
{
struct V_6 * V_36 ;
struct V_3 * V_93 ;
if ( V_1 -> V_94 != 1 ) {
F_5 ( V_49 L_38 ,
F_6 ( V_1 ) ,
V_1 -> V_94 ) ;
return F_21 ( - V_45 ) ;
}
F_10 (rdev, mddev) {
if ( V_36 -> V_46 == V_1 -> V_8 - 1 ) {
F_5 ( V_49 L_39 ,
F_6 ( V_1 ) ) ;
return F_21 ( - V_45 ) ;
}
V_36 -> V_32 = V_1 -> V_95 ;
}
V_1 -> V_96 = 0 ;
V_1 -> V_97 = 0 ;
V_1 -> V_98 = V_1 -> V_44 ;
V_1 -> V_8 -- ;
V_1 -> V_99 = - 1 ;
V_1 -> V_100 = V_101 ;
F_8 ( V_1 , & V_93 ) ;
return V_93 ;
}
static void * F_52 ( struct V_1 * V_1 )
{
struct V_3 * V_93 ;
if ( V_1 -> V_102 != ( ( 1 << 8 ) + 2 ) ) {
F_5 ( V_49 L_40 ,
F_6 ( V_1 ) ,
V_1 -> V_102 ) ;
return F_21 ( - V_45 ) ;
}
if ( V_1 -> V_8 & 1 ) {
F_5 ( V_49 L_41 ,
F_6 ( V_1 ) ) ;
return F_21 ( - V_45 ) ;
}
if ( V_1 -> V_94 != ( V_1 -> V_8 >> 1 ) ) {
F_5 ( V_49 L_42 ,
F_6 ( V_1 ) ) ;
return F_21 ( - V_45 ) ;
}
V_1 -> V_96 = 0 ;
V_1 -> V_97 = 0 ;
V_1 -> V_98 = V_1 -> V_44 ;
V_1 -> V_99 = - V_1 -> V_8 / 2 ;
V_1 -> V_8 += V_1 -> V_99 ;
V_1 -> V_94 = 0 ;
V_1 -> V_100 = V_101 ;
F_8 ( V_1 , & V_93 ) ;
return V_93 ;
}
static void * F_53 ( struct V_1 * V_1 )
{
struct V_3 * V_93 ;
int V_103 ;
if ( ( V_1 -> V_8 - 1 ) != V_1 -> V_94 ) {
F_5 ( V_49 L_43 ,
F_6 ( V_1 ) ) ;
return F_21 ( - V_45 ) ;
}
V_103 = 64 * 2 ;
while ( V_103 && ( V_1 -> V_76 & ( V_103 - 1 ) ) )
V_103 >>= 1 ;
if ( ( V_103 << 9 ) < V_79 )
return F_21 ( - V_45 ) ;
V_1 -> V_96 = 0 ;
V_1 -> V_97 = 0 ;
V_1 -> V_98 = V_103 ;
V_1 -> V_44 = V_103 ;
V_1 -> V_99 = 1 - V_1 -> V_8 ;
V_1 -> V_8 = 1 ;
V_1 -> V_100 = V_101 ;
F_8 ( V_1 , & V_93 ) ;
return V_93 ;
}
static void * F_54 ( struct V_1 * V_1 )
{
if ( V_1 -> V_104 ) {
F_5 ( V_49 L_44 ,
F_6 ( V_1 ) ) ;
return F_21 ( - V_105 ) ;
}
if ( V_1 -> V_47 == 4 )
return F_51 ( V_1 ) ;
if ( V_1 -> V_47 == 5 ) {
if ( V_1 -> V_102 == V_106 )
return F_51 ( V_1 ) ;
F_5 ( V_49 L_45 ,
F_6 ( V_1 ) , V_106 ) ;
}
if ( V_1 -> V_47 == 10 )
return F_52 ( V_1 ) ;
if ( V_1 -> V_47 == 1 )
return F_53 ( V_1 ) ;
F_5 ( V_49 L_46 ,
V_1 -> V_47 ) ;
return F_21 ( - V_45 ) ;
}
static void F_55 ( struct V_1 * V_1 , int V_107 )
{
}
static int T_2 F_56 ( void )
{
return F_57 ( & V_108 ) ;
}
static void F_58 ( void )
{
F_59 ( & V_108 ) ;
}
