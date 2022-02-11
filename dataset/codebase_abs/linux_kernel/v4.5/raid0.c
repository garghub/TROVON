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
unsigned short V_42 = 512 ;
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
V_42 = F_13 ( V_42 , F_14 (
V_34 -> V_15 -> V_45 -> V_46 ) ) ;
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
if ( ( V_1 -> V_44 << 9 ) % V_42 ) {
F_5 ( V_47 L_20 ,
F_6 ( V_1 ) ,
V_1 -> V_44 << 9 , V_42 ) ;
V_30 = - V_48 ;
goto abort;
}
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
V_30 = - V_48 ;
F_10 (rdev1, mddev) {
int V_17 = V_34 -> V_49 ;
if ( V_1 -> V_50 == 10 ) {
V_17 /= 2 ;
V_34 -> V_51 = V_17 ;
}
if ( V_1 -> V_50 == 1 ) {
V_17 = 0 ;
V_34 -> V_51 = V_17 ;
}
if ( V_17 < 0 ) {
F_5 ( V_47
L_21 ,
F_6 ( V_1 ) ) ;
goto abort;
}
if ( V_17 >= V_1 -> V_8 ) {
F_5 ( V_47 L_22
L_23 , F_6 ( V_1 ) , V_17 ) ;
goto abort;
}
if ( V_37 [ V_17 ] ) {
F_5 ( V_47 L_24
L_23 , F_6 ( V_1 ) , V_17 ) ;
goto abort;
}
V_37 [ V_17 ] = V_34 ;
if ( ! V_33 || ( V_34 -> V_32 < V_33 -> V_32 ) )
V_33 = V_34 ;
V_39 ++ ;
}
if ( V_39 != V_1 -> V_8 ) {
F_5 ( V_47 L_25
L_23 , F_6 ( V_1 ) , V_39 , V_1 -> V_8 ) ;
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
F_11 ( L_26 , F_6 ( V_1 ) , V_11 ) ;
V_38 -> V_27 = V_33 -> V_32 ;
V_33 = NULL ;
V_29 = 0 ;
for ( V_17 = 0 ; V_17 < V_39 ; V_17 ++ ) {
V_36 = V_4 -> V_7 [ V_17 ] ;
if ( V_36 -> V_32 <= V_38 -> V_27 ) {
F_11 ( L_27 ,
F_6 ( V_1 ) ,
F_7 ( V_36 -> V_15 , V_21 ) ) ;
continue;
}
F_11 ( L_28
L_29 ,
F_6 ( V_1 ) ,
F_7 ( V_36 -> V_15 , V_21 ) , V_29 ) ;
V_37 [ V_29 ] = V_36 ;
V_29 ++ ;
if ( ! V_33 || V_36 -> V_32 < V_33 -> V_32 ) {
V_33 = V_36 ;
F_11 ( L_30 ,
F_6 ( V_1 ) ,
( unsigned long long ) V_36 -> V_32 ) ;
}
}
V_38 -> V_10 = V_29 ;
V_32 = ( V_33 -> V_32 - V_38 -> V_27 ) * V_29 ;
F_11 ( L_31 ,
F_6 ( V_1 ) ,
V_38 -> V_10 , ( unsigned long long ) V_32 ) ;
V_31 += V_32 ;
V_38 -> V_26 = V_31 ;
F_11 ( L_32 ,
F_6 ( V_1 ) ,
( unsigned long long ) V_33 -> V_32 ) ;
}
F_11 ( L_33 , F_6 ( V_1 ) ) ;
* V_28 = V_4 ;
return 0 ;
abort:
F_15 ( V_4 -> V_9 ) ;
F_15 ( V_4 -> V_7 ) ;
F_15 ( V_4 ) ;
* V_28 = F_16 ( V_30 ) ;
return V_30 ;
}
static struct V_9 * F_17 ( struct V_3 * V_4 ,
T_1 * V_52 )
{
int V_11 ;
struct V_9 * V_53 = V_4 -> V_9 ;
T_1 V_54 = * V_52 ;
for ( V_11 = 0 ; V_11 < V_4 -> V_24 ; V_11 ++ )
if ( V_54 < V_53 [ V_11 ] . V_26 ) {
if ( V_11 )
* V_52 = V_54 - V_53 [ V_11 - 1 ] . V_26 ;
return V_53 + V_11 ;
}
F_18 () ;
}
static struct V_6 * F_19 ( struct V_1 * V_1 , struct V_9 * V_38 ,
T_1 V_54 , T_1 * V_55 )
{
unsigned int V_56 ;
T_1 V_57 ;
struct V_3 * V_4 = V_1 -> V_5 ;
int V_8 = V_4 -> V_9 [ 0 ] . V_10 ;
unsigned int V_58 = V_1 -> V_44 ;
if ( F_20 ( V_58 ) ) {
int V_59 = F_21 ( ~ V_58 ) ;
V_56 = V_54 & ( V_58 - 1 ) ;
V_54 >>= V_59 ;
V_57 = * V_55 ;
F_12 ( V_57 , V_38 -> V_10 << V_59 ) ;
} else{
V_56 = F_12 ( V_54 , V_58 ) ;
V_57 = * V_55 ;
F_12 ( V_57 , V_58 * V_38 -> V_10 ) ;
}
* V_55 = ( V_57 * V_58 ) + V_56 ;
return V_4 -> V_7 [ ( V_38 - V_4 -> V_9 ) * V_8
+ F_12 ( V_54 , V_38 -> V_10 ) ] ;
}
static T_1 F_22 ( struct V_1 * V_1 , T_1 V_32 , int V_8 )
{
T_1 V_60 = 0 ;
struct V_6 * V_36 ;
F_23 ( V_32 || V_8 ,
L_34 , V_61 ) ;
F_10 (rdev, mddev)
V_60 += ( V_36 -> V_32 &
~ ( T_1 ) ( V_1 -> V_44 - 1 ) ) ;
return V_60 ;
}
static int F_24 ( struct V_1 * V_1 )
{
struct V_3 * V_4 ;
int V_12 ;
if ( V_1 -> V_44 == 0 ) {
F_5 ( V_47 L_35 ,
F_6 ( V_1 ) ) ;
return - V_48 ;
}
if ( F_25 ( V_1 ) )
return - V_48 ;
if ( V_1 -> V_5 == NULL ) {
V_12 = F_8 ( V_1 , & V_4 ) ;
if ( V_12 < 0 )
return V_12 ;
V_1 -> V_5 = V_4 ;
}
V_4 = V_1 -> V_5 ;
if ( V_1 -> V_46 ) {
struct V_6 * V_36 ;
bool V_62 = false ;
F_26 ( V_1 -> V_46 , V_1 -> V_44 ) ;
F_27 ( V_1 -> V_46 , V_1 -> V_44 ) ;
F_28 ( V_1 -> V_46 , V_1 -> V_44 ) ;
F_29 ( V_1 -> V_46 , V_1 -> V_44 << 9 ) ;
F_30 ( V_1 -> V_46 ,
( V_1 -> V_44 << 9 ) * V_1 -> V_8 ) ;
F_10 (rdev, mddev) {
F_31 ( V_1 -> V_63 , V_36 -> V_15 ,
V_36 -> V_64 << 9 ) ;
if ( F_32 ( F_2 ( V_36 -> V_15 ) ) )
V_62 = true ;
}
if ( ! V_62 )
F_33 ( V_65 , V_1 -> V_46 ) ;
else
F_34 ( V_65 , V_1 -> V_46 ) ;
}
F_35 ( V_1 , F_22 ( V_1 , 0 , 0 ) ) ;
F_5 ( V_23 L_36 ,
F_6 ( V_1 ) ,
( unsigned long long ) V_1 -> V_60 ) ;
if ( V_1 -> V_46 ) {
int V_66 = V_1 -> V_8 *
( V_1 -> V_44 << 9 ) / V_67 ;
if ( V_1 -> V_46 -> V_16 . V_68 < 2 * V_66 )
V_1 -> V_46 -> V_16 . V_68 = 2 * V_66 ;
}
F_4 ( V_1 ) ;
V_12 = F_36 ( V_1 ) ;
return V_12 ;
}
static void F_37 ( struct V_1 * V_1 , void * V_69 )
{
struct V_3 * V_4 = V_69 ;
F_15 ( V_4 -> V_9 ) ;
F_15 ( V_4 -> V_7 ) ;
F_15 ( V_4 ) ;
}
static inline int F_38 ( struct V_1 * V_1 ,
unsigned int V_58 , struct V_70 * V_70 )
{
if ( F_39 ( F_20 ( V_58 ) ) ) {
return V_58 >=
( ( V_70 -> V_71 . V_72 & ( V_58 - 1 ) )
+ F_40 ( V_70 ) ) ;
} else{
T_1 V_54 = V_70 -> V_71 . V_72 ;
return V_58 >= ( F_12 ( V_54 , V_58 )
+ F_40 ( V_70 ) ) ;
}
}
static void F_41 ( struct V_1 * V_1 , struct V_70 * V_70 )
{
struct V_9 * V_38 ;
struct V_6 * V_73 ;
struct V_70 * V_74 ;
if ( F_42 ( V_70 -> V_75 & V_76 ) ) {
F_43 ( V_1 , V_70 ) ;
return;
}
do {
T_1 V_54 = V_70 -> V_71 . V_72 ;
unsigned V_58 = V_1 -> V_44 ;
unsigned V_32 = V_58 -
( F_39 ( F_20 ( V_58 ) )
? ( V_54 & ( V_58 - 1 ) )
: F_12 ( V_54 , V_58 ) ) ;
V_54 = V_70 -> V_71 . V_72 ;
if ( V_32 < F_40 ( V_70 ) ) {
V_74 = F_44 ( V_70 , V_32 , V_77 , V_78 ) ;
F_45 ( V_74 , V_70 ) ;
} else {
V_74 = V_70 ;
}
V_38 = F_17 ( V_1 -> V_5 , & V_54 ) ;
V_73 = F_19 ( V_1 , V_38 , V_54 , & V_54 ) ;
V_74 -> V_79 = V_73 -> V_15 ;
V_74 -> V_71 . V_72 = V_54 + V_38 -> V_27 +
V_73 -> V_64 ;
if ( F_42 ( ( V_74 -> V_75 & V_80 ) &&
! F_32 ( F_2 ( V_74 -> V_79 ) ) ) ) {
F_46 ( V_74 ) ;
} else
F_47 ( V_74 ) ;
} while ( V_74 != V_70 );
}
static void F_48 ( struct V_81 * V_82 , struct V_1 * V_1 )
{
F_49 ( V_82 , L_37 , V_1 -> V_44 / 2 ) ;
return;
}
static void * F_50 ( struct V_1 * V_1 )
{
struct V_6 * V_36 ;
struct V_3 * V_83 ;
if ( V_1 -> V_84 != 1 ) {
F_5 ( V_47 L_38 ,
F_6 ( V_1 ) ,
V_1 -> V_84 ) ;
return F_16 ( - V_48 ) ;
}
F_10 (rdev, mddev) {
if ( V_36 -> V_49 == V_1 -> V_8 - 1 ) {
F_5 ( V_47 L_39 ,
F_6 ( V_1 ) ) ;
return F_16 ( - V_48 ) ;
}
V_36 -> V_32 = V_1 -> V_85 ;
}
V_1 -> V_86 = 0 ;
V_1 -> V_87 = 0 ;
V_1 -> V_88 = V_1 -> V_44 ;
V_1 -> V_8 -- ;
V_1 -> V_89 = - 1 ;
V_1 -> V_90 = V_91 ;
F_8 ( V_1 , & V_83 ) ;
return V_83 ;
}
static void * F_51 ( struct V_1 * V_1 )
{
struct V_3 * V_83 ;
if ( V_1 -> V_92 != ( ( 1 << 8 ) + 2 ) ) {
F_5 ( V_47 L_40 ,
F_6 ( V_1 ) ,
V_1 -> V_92 ) ;
return F_16 ( - V_48 ) ;
}
if ( V_1 -> V_8 & 1 ) {
F_5 ( V_47 L_41 ,
F_6 ( V_1 ) ) ;
return F_16 ( - V_48 ) ;
}
if ( V_1 -> V_84 != ( V_1 -> V_8 >> 1 ) ) {
F_5 ( V_47 L_42 ,
F_6 ( V_1 ) ) ;
return F_16 ( - V_48 ) ;
}
V_1 -> V_86 = 0 ;
V_1 -> V_87 = 0 ;
V_1 -> V_88 = V_1 -> V_44 ;
V_1 -> V_89 = - V_1 -> V_8 / 2 ;
V_1 -> V_8 += V_1 -> V_89 ;
V_1 -> V_84 = 0 ;
V_1 -> V_90 = V_91 ;
F_8 ( V_1 , & V_83 ) ;
return V_83 ;
}
static void * F_52 ( struct V_1 * V_1 )
{
struct V_3 * V_83 ;
int V_93 ;
if ( ( V_1 -> V_8 - 1 ) != V_1 -> V_84 ) {
F_5 ( V_47 L_43 ,
F_6 ( V_1 ) ) ;
return F_16 ( - V_48 ) ;
}
V_93 = 64 * 2 ;
while ( V_93 && ( V_1 -> V_60 & ( V_93 - 1 ) ) )
V_93 >>= 1 ;
if ( ( V_93 << 9 ) < V_67 )
return F_16 ( - V_48 ) ;
V_1 -> V_86 = 0 ;
V_1 -> V_87 = 0 ;
V_1 -> V_88 = V_93 ;
V_1 -> V_44 = V_93 ;
V_1 -> V_89 = 1 - V_1 -> V_8 ;
V_1 -> V_8 = 1 ;
V_1 -> V_90 = V_91 ;
F_8 ( V_1 , & V_83 ) ;
return V_83 ;
}
static void * F_53 ( struct V_1 * V_1 )
{
if ( V_1 -> V_94 ) {
F_5 ( V_47 L_44 ,
F_6 ( V_1 ) ) ;
return F_16 ( - V_95 ) ;
}
if ( V_1 -> V_50 == 4 )
return F_50 ( V_1 ) ;
if ( V_1 -> V_50 == 5 ) {
if ( V_1 -> V_92 == V_96 )
return F_50 ( V_1 ) ;
F_5 ( V_47 L_45 ,
F_6 ( V_1 ) , V_96 ) ;
}
if ( V_1 -> V_50 == 10 )
return F_51 ( V_1 ) ;
if ( V_1 -> V_50 == 1 )
return F_52 ( V_1 ) ;
F_5 ( V_47 L_46 ,
V_1 -> V_50 ) ;
return F_16 ( - V_48 ) ;
}
static void F_54 ( struct V_1 * V_1 , int V_97 )
{
}
static int T_2 F_55 ( void )
{
return F_56 ( & V_98 ) ;
}
static void F_57 ( void )
{
F_58 ( & V_98 ) ;
}
