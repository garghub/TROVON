static int F_1 ( struct V_1 * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
struct V_6 * * V_7 = V_4 -> V_7 ;
int V_8 = V_4 -> V_9 [ 0 ] . V_10 ;
int V_11 , V_12 = 0 ;
for ( V_11 = 0 ; V_11 < V_8 && ! V_12 ; V_11 ++ ) {
struct V_13 * V_14 = F_2 ( V_7 [ V_11 ] -> V_15 ) ;
V_12 |= F_3 ( V_14 -> V_16 , V_2 ) ;
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
F_5 ( L_1 ,
F_6 ( V_1 ) ,
V_4 -> V_23 , V_4 -> V_23 == 1 ? L_2 : L_3 ) ;
for ( V_17 = 0 ; V_17 < V_4 -> V_23 ; V_17 ++ ) {
char line [ 200 ] ;
int V_24 = 0 ;
for ( V_18 = 0 ; V_18 < V_4 -> V_9 [ V_17 ] . V_10 ; V_18 ++ )
V_24 += snprintf ( line + V_24 , 200 - V_24 , L_4 , V_18 ? L_5 : L_2 ,
F_7 ( V_4 -> V_7 [ V_17 * V_8
+ V_18 ] -> V_15 , V_21 ) ) ;
F_5 ( L_6 , V_17 , line ) ;
V_19 = V_4 -> V_9 [ V_17 ] . V_25 - V_20 ;
F_5 ( L_7 ,
( unsigned long long ) V_20 >> 1 ,
( unsigned long long ) V_4 -> V_9 [ V_17 ] . V_26 >> 1 ,
( unsigned long long ) V_19 >> 1 ) ;
V_20 = V_4 -> V_9 [ V_17 ] . V_25 ;
}
}
static int F_8 ( struct V_1 * V_1 , struct V_3 * * V_27 )
{
int V_11 , V_28 , V_29 ;
T_1 V_30 , V_31 ;
struct V_6 * V_32 , * V_33 , * V_34 , * V_35 , * * V_36 ;
struct V_9 * V_37 ;
int V_38 ;
char V_21 [ V_22 ] ;
char V_39 [ V_22 ] ;
struct V_3 * V_4 = F_9 ( sizeof( * V_4 ) , V_40 ) ;
unsigned short V_41 = 512 ;
* V_27 = F_10 ( - V_42 ) ;
if ( ! V_4 )
return - V_42 ;
F_11 (rdev1, mddev) {
F_5 ( L_8 ,
F_6 ( V_1 ) ,
F_7 ( V_33 -> V_15 , V_21 ) ) ;
V_28 = 0 ;
V_31 = V_33 -> V_31 ;
F_12 ( V_31 , V_1 -> V_43 ) ;
V_33 -> V_31 = V_31 * V_1 -> V_43 ;
V_41 = F_13 ( V_41 , F_14 (
V_33 -> V_15 -> V_44 -> V_45 ) ) ;
F_11 (rdev2, mddev) {
F_5 ( L_9
L_10 ,
F_6 ( V_1 ) ,
F_7 ( V_33 -> V_15 , V_21 ) ,
( unsigned long long ) V_33 -> V_31 ,
F_7 ( V_34 -> V_15 , V_39 ) ,
( unsigned long long ) V_34 -> V_31 ) ;
if ( V_34 == V_33 ) {
F_5 ( L_11 ,
F_6 ( V_1 ) ) ;
break;
}
if ( V_34 -> V_31 == V_33 -> V_31 ) {
F_5 ( L_12 ,
F_6 ( V_1 ) ) ;
V_28 = 1 ;
break;
}
F_5 ( L_13 ,
F_6 ( V_1 ) ) ;
}
if ( ! V_28 ) {
F_5 ( L_14 ,
F_6 ( V_1 ) ) ;
V_4 -> V_23 ++ ;
F_5 ( L_15 ,
F_6 ( V_1 ) , V_4 -> V_23 ) ;
}
}
F_5 ( L_16 ,
F_6 ( V_1 ) , V_4 -> V_23 ) ;
if ( ( V_1 -> V_43 << 9 ) % V_41 ) {
F_15 ( L_17 ,
F_6 ( V_1 ) ,
V_1 -> V_43 << 9 , V_41 ) ;
V_29 = - V_46 ;
goto abort;
}
V_29 = - V_42 ;
V_4 -> V_9 = F_9 ( sizeof( struct V_9 ) *
V_4 -> V_23 , V_40 ) ;
if ( ! V_4 -> V_9 )
goto abort;
V_4 -> V_7 = F_9 ( sizeof( struct V_6 * ) *
V_4 -> V_23 * V_1 -> V_8 ,
V_40 ) ;
if ( ! V_4 -> V_7 )
goto abort;
V_37 = & V_4 -> V_9 [ 0 ] ;
V_38 = 0 ;
V_32 = NULL ;
V_36 = V_4 -> V_7 ;
V_29 = - V_46 ;
F_11 (rdev1, mddev) {
int V_17 = V_33 -> V_47 ;
if ( V_1 -> V_48 == 10 ) {
V_17 /= 2 ;
V_33 -> V_49 = V_17 ;
}
if ( V_1 -> V_48 == 1 ) {
V_17 = 0 ;
V_33 -> V_49 = V_17 ;
}
if ( V_17 < 0 ) {
F_15 ( L_18 ,
F_6 ( V_1 ) ) ;
goto abort;
}
if ( V_17 >= V_1 -> V_8 ) {
F_15 ( L_19 ,
F_6 ( V_1 ) , V_17 ) ;
goto abort;
}
if ( V_36 [ V_17 ] ) {
F_15 ( L_20 ,
F_6 ( V_1 ) , V_17 ) ;
goto abort;
}
V_36 [ V_17 ] = V_33 ;
if ( ! V_32 || ( V_33 -> V_31 < V_32 -> V_31 ) )
V_32 = V_33 ;
V_38 ++ ;
}
if ( V_38 != V_1 -> V_8 ) {
F_15 ( L_21 ,
F_6 ( V_1 ) , V_38 , V_1 -> V_8 ) ;
goto abort;
}
V_37 -> V_10 = V_38 ;
V_37 -> V_25 = V_32 -> V_31 * V_38 ;
V_30 = V_37 -> V_25 ;
for ( V_11 = 1 ; V_11 < V_4 -> V_23 ; V_11 ++ )
{
int V_17 ;
V_37 = V_4 -> V_9 + V_11 ;
V_36 = V_4 -> V_7 + V_11 * V_1 -> V_8 ;
F_5 ( L_22 , F_6 ( V_1 ) , V_11 ) ;
V_37 -> V_26 = V_32 -> V_31 ;
V_32 = NULL ;
V_28 = 0 ;
for ( V_17 = 0 ; V_17 < V_38 ; V_17 ++ ) {
V_35 = V_4 -> V_7 [ V_17 ] ;
if ( V_35 -> V_31 <= V_37 -> V_26 ) {
F_5 ( L_23 ,
F_6 ( V_1 ) ,
F_7 ( V_35 -> V_15 , V_21 ) ) ;
continue;
}
F_5 ( L_24
L_25 ,
F_6 ( V_1 ) ,
F_7 ( V_35 -> V_15 , V_21 ) , V_28 ) ;
V_36 [ V_28 ] = V_35 ;
V_28 ++ ;
if ( ! V_32 || V_35 -> V_31 < V_32 -> V_31 ) {
V_32 = V_35 ;
F_5 ( L_26 ,
F_6 ( V_1 ) ,
( unsigned long long ) V_35 -> V_31 ) ;
}
}
V_37 -> V_10 = V_28 ;
V_31 = ( V_32 -> V_31 - V_37 -> V_26 ) * V_28 ;
F_5 ( L_27 ,
F_6 ( V_1 ) ,
V_37 -> V_10 , ( unsigned long long ) V_31 ) ;
V_30 += V_31 ;
V_37 -> V_25 = V_30 ;
F_5 ( L_28 ,
F_6 ( V_1 ) ,
( unsigned long long ) V_32 -> V_31 ) ;
}
F_5 ( L_29 , F_6 ( V_1 ) ) ;
* V_27 = V_4 ;
return 0 ;
abort:
F_16 ( V_4 -> V_9 ) ;
F_16 ( V_4 -> V_7 ) ;
F_16 ( V_4 ) ;
* V_27 = F_10 ( V_29 ) ;
return V_29 ;
}
static struct V_9 * F_17 ( struct V_3 * V_4 ,
T_1 * V_50 )
{
int V_11 ;
struct V_9 * V_51 = V_4 -> V_9 ;
T_1 V_52 = * V_50 ;
for ( V_11 = 0 ; V_11 < V_4 -> V_23 ; V_11 ++ )
if ( V_52 < V_51 [ V_11 ] . V_25 ) {
if ( V_11 )
* V_50 = V_52 - V_51 [ V_11 - 1 ] . V_25 ;
return V_51 + V_11 ;
}
F_18 () ;
}
static struct V_6 * F_19 ( struct V_1 * V_1 , struct V_9 * V_37 ,
T_1 V_52 , T_1 * V_53 )
{
unsigned int V_54 ;
T_1 V_55 ;
struct V_3 * V_4 = V_1 -> V_5 ;
int V_8 = V_4 -> V_9 [ 0 ] . V_10 ;
unsigned int V_56 = V_1 -> V_43 ;
if ( F_20 ( V_56 ) ) {
int V_57 = F_21 ( ~ V_56 ) ;
V_54 = V_52 & ( V_56 - 1 ) ;
V_52 >>= V_57 ;
V_55 = * V_53 ;
F_12 ( V_55 , V_37 -> V_10 << V_57 ) ;
} else{
V_54 = F_12 ( V_52 , V_56 ) ;
V_55 = * V_53 ;
F_12 ( V_55 , V_56 * V_37 -> V_10 ) ;
}
* V_53 = ( V_55 * V_56 ) + V_54 ;
return V_4 -> V_7 [ ( V_37 - V_4 -> V_9 ) * V_8
+ F_12 ( V_52 , V_37 -> V_10 ) ] ;
}
static T_1 F_22 ( struct V_1 * V_1 , T_1 V_31 , int V_8 )
{
T_1 V_58 = 0 ;
struct V_6 * V_35 ;
F_23 ( V_31 || V_8 ,
L_30 , V_59 ) ;
F_11 (rdev, mddev)
V_58 += ( V_35 -> V_31 &
~ ( T_1 ) ( V_1 -> V_43 - 1 ) ) ;
return V_58 ;
}
static int F_24 ( struct V_1 * V_1 )
{
struct V_3 * V_4 ;
int V_12 ;
if ( V_1 -> V_43 == 0 ) {
F_15 ( L_31 , F_6 ( V_1 ) ) ;
return - V_46 ;
}
if ( F_25 ( V_1 ) )
return - V_46 ;
if ( V_1 -> V_5 == NULL ) {
V_12 = F_8 ( V_1 , & V_4 ) ;
if ( V_12 < 0 )
return V_12 ;
V_1 -> V_5 = V_4 ;
}
V_4 = V_1 -> V_5 ;
if ( V_1 -> V_45 ) {
struct V_6 * V_35 ;
bool V_60 = false ;
F_26 ( V_1 -> V_45 , V_1 -> V_43 ) ;
F_27 ( V_1 -> V_45 , V_1 -> V_43 ) ;
F_28 ( V_1 -> V_45 , V_1 -> V_43 ) ;
F_29 ( V_1 -> V_45 , V_61 ) ;
F_30 ( V_1 -> V_45 , V_1 -> V_43 << 9 ) ;
F_31 ( V_1 -> V_45 ,
( V_1 -> V_43 << 9 ) * V_1 -> V_8 ) ;
F_11 (rdev, mddev) {
F_32 ( V_1 -> V_62 , V_35 -> V_15 ,
V_35 -> V_63 << 9 ) ;
if ( F_33 ( F_2 ( V_35 -> V_15 ) ) )
V_60 = true ;
}
if ( ! V_60 )
F_34 ( V_64 , V_1 -> V_45 ) ;
else
F_35 ( V_64 , V_1 -> V_45 ) ;
}
F_36 ( V_1 , F_22 ( V_1 , 0 , 0 ) ) ;
F_5 ( L_32 ,
F_6 ( V_1 ) ,
( unsigned long long ) V_1 -> V_58 ) ;
if ( V_1 -> V_45 ) {
int V_65 = V_1 -> V_8 *
( V_1 -> V_43 << 9 ) / V_66 ;
if ( V_1 -> V_45 -> V_16 -> V_67 < 2 * V_65 )
V_1 -> V_45 -> V_16 -> V_67 = 2 * V_65 ;
}
F_4 ( V_1 ) ;
V_12 = F_37 ( V_1 ) ;
return V_12 ;
}
static void F_38 ( struct V_1 * V_1 , void * V_68 )
{
struct V_3 * V_4 = V_68 ;
F_16 ( V_4 -> V_9 ) ;
F_16 ( V_4 -> V_7 ) ;
F_16 ( V_4 ) ;
}
static inline int F_39 ( struct V_1 * V_1 ,
unsigned int V_56 , struct V_69 * V_69 )
{
if ( F_40 ( F_20 ( V_56 ) ) ) {
return V_56 >=
( ( V_69 -> V_70 . V_71 & ( V_56 - 1 ) )
+ F_41 ( V_69 ) ) ;
} else{
T_1 V_52 = V_69 -> V_70 . V_71 ;
return V_56 >= ( F_12 ( V_52 , V_56 )
+ F_41 ( V_69 ) ) ;
}
}
static void F_42 ( struct V_1 * V_1 , struct V_69 * V_69 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
struct V_9 * V_37 ;
T_1 V_72 = V_69 -> V_70 . V_71 ;
T_1 V_73 ;
unsigned int V_74 ;
T_1 V_75 , V_76 ;
T_1 V_77 ;
unsigned int V_78 ;
T_1 V_79 ;
unsigned int V_80 ;
unsigned int V_81 ;
V_37 = F_17 ( V_4 , & V_72 ) ;
if ( F_43 ( V_69 ) > V_37 -> V_25 ) {
struct V_69 * V_82 = F_44 ( V_69 ,
V_37 -> V_25 - V_69 -> V_70 . V_71 , V_83 ,
V_1 -> V_84 ) ;
F_45 ( V_82 , V_69 ) ;
F_46 ( V_69 ) ;
V_69 = V_82 ;
V_73 = V_37 -> V_25 ;
} else
V_73 = F_43 ( V_69 ) ;
if ( V_37 != V_4 -> V_9 )
V_73 = V_73 - V_37 [ - 1 ] . V_25 ;
V_74 = V_37 -> V_10 * V_1 -> V_43 ;
V_75 = V_72 ;
F_12 ( V_75 , V_74 ) ;
V_76 = V_73 ;
F_12 ( V_76 , V_74 ) ;
V_78 = ( int ) ( V_72 - V_75 * V_74 ) /
V_1 -> V_43 ;
V_77 = ( ( int ) ( V_72 - V_75 * V_74 ) %
V_1 -> V_43 ) +
V_75 * V_1 -> V_43 ;
V_80 = ( int ) ( V_73 - V_76 * V_74 ) /
V_1 -> V_43 ;
V_79 = ( ( int ) ( V_73 - V_76 * V_74 ) %
V_1 -> V_43 ) +
V_76 * V_1 -> V_43 ;
for ( V_81 = 0 ; V_81 < V_37 -> V_10 ; V_81 ++ ) {
T_1 V_26 , V_85 ;
struct V_69 * V_86 = NULL ;
struct V_6 * V_35 ;
if ( V_81 < V_78 )
V_26 = ( V_75 + 1 ) *
V_1 -> V_43 ;
else if ( V_81 > V_78 )
V_26 = V_75 * V_1 -> V_43 ;
else
V_26 = V_77 ;
if ( V_81 < V_80 )
V_85 = ( V_76 + 1 ) * V_1 -> V_43 ;
else if ( V_81 > V_80 )
V_85 = V_76 * V_1 -> V_43 ;
else
V_85 = V_79 ;
if ( V_85 <= V_26 )
continue;
V_35 = V_4 -> V_7 [ ( V_37 - V_4 -> V_9 ) *
V_4 -> V_9 [ 0 ] . V_10 + V_81 ] ;
if ( F_47 ( V_35 -> V_15 ,
V_26 + V_37 -> V_26 + V_35 -> V_63 ,
V_85 - V_26 , V_83 , 0 , & V_86 ) ||
! V_86 )
continue;
F_45 ( V_86 , V_69 ) ;
if ( V_1 -> V_62 )
F_48 ( F_2 ( V_35 -> V_15 ) ,
V_86 , F_49 ( V_1 -> V_62 ) ,
V_69 -> V_70 . V_71 ) ;
F_46 ( V_86 ) ;
}
F_50 ( V_69 ) ;
}
static void F_51 ( struct V_1 * V_1 , struct V_69 * V_69 )
{
struct V_9 * V_37 ;
struct V_6 * V_87 ;
T_1 V_88 ;
T_1 V_52 ;
unsigned V_56 ;
unsigned V_31 ;
if ( F_52 ( V_69 -> V_89 & V_90 ) ) {
F_53 ( V_1 , V_69 ) ;
return;
}
if ( F_52 ( ( F_54 ( V_69 ) == V_91 ) ) ) {
F_42 ( V_1 , V_69 ) ;
return;
}
V_88 = V_69 -> V_70 . V_71 ;
V_52 = V_88 ;
V_56 = V_1 -> V_43 ;
V_31 = V_56 -
( F_40 ( F_20 ( V_56 ) )
? ( V_52 & ( V_56 - 1 ) )
: F_12 ( V_52 , V_56 ) ) ;
V_52 = V_88 ;
if ( V_31 < F_41 ( V_69 ) ) {
struct V_69 * V_82 = F_44 ( V_69 , V_31 , V_83 , V_1 -> V_84 ) ;
F_45 ( V_82 , V_69 ) ;
F_46 ( V_69 ) ;
V_69 = V_82 ;
}
V_37 = F_17 ( V_1 -> V_5 , & V_52 ) ;
V_87 = F_19 ( V_1 , V_37 , V_52 , & V_52 ) ;
V_69 -> V_92 = V_87 -> V_15 ;
V_69 -> V_70 . V_71 = V_52 + V_37 -> V_26 +
V_87 -> V_63 ;
if ( V_1 -> V_62 )
F_48 ( F_2 ( V_69 -> V_92 ) ,
V_69 , F_49 ( V_1 -> V_62 ) ,
V_88 ) ;
F_55 ( V_1 , V_69 ) ;
F_56 ( V_1 , V_69 ) ;
F_46 ( V_69 ) ;
}
static void F_57 ( struct V_93 * V_94 , struct V_1 * V_1 )
{
F_58 ( V_94 , L_33 , V_1 -> V_43 / 2 ) ;
return;
}
static void * F_59 ( struct V_1 * V_1 )
{
struct V_6 * V_35 ;
struct V_3 * V_95 ;
if ( V_1 -> V_96 != 1 ) {
F_15 ( L_34 ,
F_6 ( V_1 ) ,
V_1 -> V_96 ) ;
return F_10 ( - V_46 ) ;
}
F_11 (rdev, mddev) {
if ( V_35 -> V_47 == V_1 -> V_8 - 1 ) {
F_15 ( L_35 ,
F_6 ( V_1 ) ) ;
return F_10 ( - V_46 ) ;
}
V_35 -> V_31 = V_1 -> V_97 ;
}
V_1 -> V_98 = 0 ;
V_1 -> V_99 = 0 ;
V_1 -> V_100 = V_1 -> V_43 ;
V_1 -> V_8 -- ;
V_1 -> V_101 = - 1 ;
V_1 -> V_102 = V_103 ;
F_60 ( V_1 , V_104 ) ;
F_8 ( V_1 , & V_95 ) ;
return V_95 ;
}
static void * F_61 ( struct V_1 * V_1 )
{
struct V_3 * V_95 ;
if ( V_1 -> V_105 != ( ( 1 << 8 ) + 2 ) ) {
F_15 ( L_36 ,
F_6 ( V_1 ) ,
V_1 -> V_105 ) ;
return F_10 ( - V_46 ) ;
}
if ( V_1 -> V_8 & 1 ) {
F_15 ( L_37 ,
F_6 ( V_1 ) ) ;
return F_10 ( - V_46 ) ;
}
if ( V_1 -> V_96 != ( V_1 -> V_8 >> 1 ) ) {
F_15 ( L_38 ,
F_6 ( V_1 ) ) ;
return F_10 ( - V_46 ) ;
}
V_1 -> V_98 = 0 ;
V_1 -> V_99 = 0 ;
V_1 -> V_100 = V_1 -> V_43 ;
V_1 -> V_101 = - V_1 -> V_8 / 2 ;
V_1 -> V_8 += V_1 -> V_101 ;
V_1 -> V_96 = 0 ;
V_1 -> V_102 = V_103 ;
F_60 ( V_1 , V_104 ) ;
F_8 ( V_1 , & V_95 ) ;
return V_95 ;
}
static void * F_62 ( struct V_1 * V_1 )
{
struct V_3 * V_95 ;
int V_106 ;
if ( ( V_1 -> V_8 - 1 ) != V_1 -> V_96 ) {
F_63 ( L_39 ,
F_6 ( V_1 ) ) ;
return F_10 ( - V_46 ) ;
}
V_106 = 64 * 2 ;
while ( V_106 && ( V_1 -> V_58 & ( V_106 - 1 ) ) )
V_106 >>= 1 ;
if ( ( V_106 << 9 ) < V_66 )
return F_10 ( - V_46 ) ;
V_1 -> V_98 = 0 ;
V_1 -> V_99 = 0 ;
V_1 -> V_100 = V_106 ;
V_1 -> V_43 = V_106 ;
V_1 -> V_101 = 1 - V_1 -> V_8 ;
V_1 -> V_8 = 1 ;
V_1 -> V_102 = V_103 ;
F_60 ( V_1 , V_104 ) ;
F_8 ( V_1 , & V_95 ) ;
return V_95 ;
}
static void * F_64 ( struct V_1 * V_1 )
{
if ( V_1 -> V_107 ) {
F_15 ( L_40 ,
F_6 ( V_1 ) ) ;
return F_10 ( - V_108 ) ;
}
if ( V_1 -> V_48 == 4 )
return F_59 ( V_1 ) ;
if ( V_1 -> V_48 == 5 ) {
if ( V_1 -> V_105 == V_109 )
return F_59 ( V_1 ) ;
F_15 ( L_41 ,
F_6 ( V_1 ) , V_109 ) ;
}
if ( V_1 -> V_48 == 10 )
return F_61 ( V_1 ) ;
if ( V_1 -> V_48 == 1 )
return F_62 ( V_1 ) ;
F_15 ( L_42 ,
V_1 -> V_48 ) ;
return F_10 ( - V_46 ) ;
}
static void F_65 ( struct V_1 * V_1 , int V_110 )
{
}
static int T_2 F_66 ( void )
{
return F_67 ( & V_111 ) ;
}
static void F_68 ( void )
{
F_69 ( & V_111 ) ;
}
