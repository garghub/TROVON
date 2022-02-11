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
F_11 (rdev1, mddev) {
F_12 ( L_11 ,
F_7 ( V_3 ) ,
F_8 ( V_35 -> V_16 , V_22 ) ) ;
V_30 = 0 ;
V_33 = V_35 -> V_33 ;
F_13 ( V_33 , V_3 -> V_44 ) ;
V_35 -> V_33 = V_33 * V_3 -> V_44 ;
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
F_11 (rdev1, mddev) {
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
if ( V_35 -> V_16 -> V_52 -> V_53 -> V_54 )
V_5 -> V_55 = 1 ;
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
if ( ( V_3 -> V_44 << 9 ) % F_15 ( V_3 -> V_53 ) ) {
F_6 ( V_49 L_31 ,
F_7 ( V_3 ) ,
V_3 -> V_44 << 9 ) ;
goto abort;
}
F_16 ( V_3 -> V_53 , V_3 -> V_44 << 9 ) ;
F_17 ( V_3 -> V_53 ,
( V_3 -> V_44 << 9 ) * V_3 -> V_9 ) ;
F_12 ( L_32 , F_7 ( V_3 ) ) ;
* V_29 = V_5 ;
return 0 ;
abort:
F_18 ( V_5 -> V_10 ) ;
F_18 ( V_5 -> V_8 ) ;
F_18 ( V_5 ) ;
* V_29 = NULL ;
return V_31 ;
}
static struct V_10 * F_19 ( struct V_4 * V_5 ,
T_1 * V_58 )
{
int V_12 ;
struct V_10 * V_59 = V_5 -> V_10 ;
T_1 V_60 = * V_58 ;
for ( V_12 = 0 ; V_12 < V_5 -> V_25 ; V_12 ++ )
if ( V_60 < V_59 [ V_12 ] . V_27 ) {
if ( V_12 )
* V_58 = V_60 - V_59 [ V_12 - 1 ] . V_27 ;
return V_59 + V_12 ;
}
F_20 () ;
}
static struct V_7 * F_21 ( struct V_3 * V_3 , struct V_10 * V_39 ,
T_1 V_60 , T_1 * V_61 )
{
unsigned int V_62 ;
T_1 V_63 ;
struct V_4 * V_5 = V_3 -> V_6 ;
int V_9 = V_5 -> V_10 [ 0 ] . V_11 ;
unsigned int V_64 = V_3 -> V_44 ;
if ( F_22 ( V_64 ) ) {
int V_65 = F_23 ( ~ V_64 ) ;
V_62 = V_60 & ( V_64 - 1 ) ;
V_60 >>= V_65 ;
V_63 = * V_61 ;
F_13 ( V_63 , V_39 -> V_11 << V_65 ) ;
} else{
V_62 = F_13 ( V_60 , V_64 ) ;
V_63 = * V_61 ;
F_13 ( V_63 , V_64 * V_39 -> V_11 ) ;
}
* V_61 = ( V_63 * V_64 ) + V_62 ;
return V_5 -> V_8 [ ( V_39 - V_5 -> V_10 ) * V_9
+ F_13 ( V_60 , V_39 -> V_11 ) ] ;
}
static int F_24 ( struct V_14 * V_15 ,
struct V_66 * V_67 ,
struct V_68 * V_69 )
{
struct V_3 * V_3 = V_15 -> V_70 ;
struct V_4 * V_5 = V_3 -> V_6 ;
T_1 V_60 = V_67 -> V_71 + F_25 ( V_67 -> V_72 ) ;
T_1 V_61 = V_60 ;
int V_73 ;
unsigned int V_44 = V_3 -> V_44 ;
unsigned int V_74 = V_67 -> V_75 >> 9 ;
struct V_10 * V_39 ;
struct V_7 * V_37 ;
struct V_14 * V_76 ;
if ( F_22 ( V_44 ) )
V_73 = ( V_44 - ( ( V_60 & ( V_44 - 1 ) )
+ V_74 ) ) << 9 ;
else
V_73 = ( V_44 - ( F_13 ( V_60 , V_44 )
+ V_74 ) ) << 9 ;
if ( V_73 < 0 )
V_73 = 0 ;
if ( V_73 <= V_69 -> V_77 && V_74 == 0 )
return V_69 -> V_77 ;
if ( V_73 < V_69 -> V_77 )
return V_73 ;
if ( ! V_5 -> V_55 )
return V_73 ;
V_60 = V_61 ;
V_39 = F_19 ( V_3 -> V_6 , & V_61 ) ;
V_37 = F_21 ( V_3 , V_39 , V_60 , & V_61 ) ;
V_76 = F_3 ( V_37 -> V_16 ) ;
if ( V_76 -> V_54 ) {
V_67 -> V_72 = V_37 -> V_16 ;
V_67 -> V_71 = V_61 + V_39 -> V_28 +
V_37 -> V_51 ;
return F_26 ( V_73 , V_76 -> V_54 ( V_76 , V_67 , V_69 ) ) ;
} else
return V_73 ;
}
static T_1 F_27 ( struct V_3 * V_3 , T_1 V_33 , int V_9 )
{
T_1 V_78 = 0 ;
struct V_7 * V_37 ;
F_28 ( V_33 || V_9 ,
L_33 , V_79 ) ;
F_11 (rdev, mddev)
V_78 += V_37 -> V_33 ;
return V_78 ;
}
static int F_29 ( struct V_3 * V_3 )
{
struct V_4 * V_5 ;
int V_13 ;
if ( V_3 -> V_44 == 0 ) {
F_6 ( V_49 L_34 ,
F_7 ( V_3 ) ) ;
return - V_45 ;
}
if ( F_30 ( V_3 ) )
return - V_45 ;
F_31 ( V_3 -> V_53 , V_3 -> V_44 ) ;
if ( V_3 -> V_6 == NULL ) {
V_13 = F_9 ( V_3 , & V_5 ) ;
if ( V_13 < 0 )
return V_13 ;
V_3 -> V_6 = V_5 ;
}
V_5 = V_3 -> V_6 ;
F_32 ( V_3 , F_27 ( V_3 , 0 , 0 ) ) ;
F_6 ( V_24 L_35 ,
F_7 ( V_3 ) ,
( unsigned long long ) V_3 -> V_78 ) ;
{
int V_80 = V_3 -> V_9 *
( V_3 -> V_44 << 9 ) / V_81 ;
if ( V_3 -> V_53 -> V_17 . V_82 < 2 * V_80 )
V_3 -> V_53 -> V_17 . V_82 = 2 * V_80 ;
}
F_33 ( V_3 -> V_53 , F_24 ) ;
F_5 ( V_3 ) ;
V_13 = F_34 ( V_3 ) ;
if ( V_13 )
F_35 ( V_3 ) ;
return V_13 ;
}
static int F_35 ( struct V_3 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
F_36 ( V_3 -> V_53 ) ;
F_18 ( V_5 -> V_10 ) ;
F_18 ( V_5 -> V_8 ) ;
F_18 ( V_5 ) ;
V_3 -> V_6 = NULL ;
return 0 ;
}
static inline int F_37 ( struct V_3 * V_3 ,
unsigned int V_64 , struct V_83 * V_83 )
{
if ( F_38 ( F_22 ( V_64 ) ) ) {
return V_64 >= ( ( V_83 -> V_71 & ( V_64 - 1 ) )
+ ( V_83 -> V_75 >> 9 ) ) ;
} else{
T_1 V_60 = V_83 -> V_71 ;
return V_64 >= ( F_13 ( V_60 , V_64 )
+ ( V_83 -> V_75 >> 9 ) ) ;
}
}
static void F_39 ( struct V_3 * V_3 , struct V_83 * V_83 )
{
unsigned int V_64 ;
T_1 V_61 ;
struct V_10 * V_39 ;
struct V_7 * V_84 ;
if ( F_40 ( V_83 -> V_85 & V_86 ) ) {
F_41 ( V_3 , V_83 ) ;
return;
}
V_64 = V_3 -> V_44 ;
if ( F_40 ( ! F_37 ( V_3 , V_64 , V_83 ) ) ) {
T_1 V_60 = V_83 -> V_71 ;
struct V_87 * V_88 ;
if ( V_83 -> V_89 != 1 ||
V_83 -> V_90 != 0 )
goto V_91;
if ( F_38 ( F_22 ( V_64 ) ) )
V_88 = F_42 ( V_83 , V_64 - ( V_60 &
( V_64 - 1 ) ) ) ;
else
V_88 = F_42 ( V_83 , V_64 -
F_13 ( V_60 , V_64 ) ) ;
F_39 ( V_3 , & V_88 -> V_92 ) ;
F_39 ( V_3 , & V_88 -> V_93 ) ;
F_43 ( V_88 ) ;
return;
}
V_61 = V_83 -> V_71 ;
V_39 = F_19 ( V_3 -> V_6 , & V_61 ) ;
V_84 = F_21 ( V_3 , V_39 , V_83 -> V_71 ,
& V_61 ) ;
V_83 -> V_72 = V_84 -> V_16 ;
V_83 -> V_71 = V_61 + V_39 -> V_28 +
V_84 -> V_51 ;
F_44 ( V_83 ) ;
return;
V_91:
F_6 ( L_36
L_37 ,
F_7 ( V_3 ) , V_64 / 2 ,
( unsigned long long ) V_83 -> V_71 , V_83 -> V_75 >> 10 ) ;
F_45 ( V_83 ) ;
return;
}
static void F_46 ( struct V_94 * V_95 , struct V_3 * V_3 )
{
F_47 ( V_95 , L_38 , V_3 -> V_44 / 2 ) ;
return;
}
static void * F_48 ( struct V_3 * V_3 )
{
struct V_7 * V_37 ;
struct V_4 * V_96 ;
if ( V_3 -> V_97 != 1 ) {
F_6 ( V_49 L_39 ,
F_7 ( V_3 ) ,
V_3 -> V_97 ) ;
return F_49 ( - V_45 ) ;
}
F_11 (rdev, mddev) {
if ( V_37 -> V_46 == V_3 -> V_9 - 1 ) {
F_6 ( V_49 L_40 ,
F_7 ( V_3 ) ) ;
return F_49 ( - V_45 ) ;
}
}
V_3 -> V_98 = 0 ;
V_3 -> V_99 = 0 ;
V_3 -> V_100 = V_3 -> V_44 ;
V_3 -> V_9 -- ;
V_3 -> V_101 = - 1 ;
V_3 -> V_102 = V_103 ;
F_9 ( V_3 , & V_96 ) ;
return V_96 ;
}
static void * F_50 ( struct V_3 * V_3 )
{
struct V_4 * V_96 ;
if ( V_3 -> V_104 != ( ( 1 << 8 ) + 2 ) ) {
F_6 ( V_49 L_41 ,
F_7 ( V_3 ) ,
V_3 -> V_104 ) ;
return F_49 ( - V_45 ) ;
}
if ( V_3 -> V_9 & 1 ) {
F_6 ( V_49 L_42 ,
F_7 ( V_3 ) ) ;
return F_49 ( - V_45 ) ;
}
if ( V_3 -> V_97 != ( V_3 -> V_9 >> 1 ) ) {
F_6 ( V_49 L_43 ,
F_7 ( V_3 ) ) ;
return F_49 ( - V_45 ) ;
}
V_3 -> V_98 = 0 ;
V_3 -> V_99 = 0 ;
V_3 -> V_100 = V_3 -> V_44 ;
V_3 -> V_101 = - V_3 -> V_9 / 2 ;
V_3 -> V_9 += V_3 -> V_101 ;
V_3 -> V_97 = 0 ;
V_3 -> V_102 = V_103 ;
F_9 ( V_3 , & V_96 ) ;
return V_96 ;
}
static void * F_51 ( struct V_3 * V_3 )
{
struct V_4 * V_96 ;
int V_105 ;
if ( ( V_3 -> V_9 - 1 ) != V_3 -> V_97 ) {
F_6 ( V_49 L_44 ,
F_7 ( V_3 ) ) ;
return F_49 ( - V_45 ) ;
}
V_105 = 64 * 2 ;
while ( V_105 && ( V_3 -> V_78 & ( V_105 - 1 ) ) )
V_105 >>= 1 ;
if ( ( V_105 << 9 ) < V_81 )
return F_49 ( - V_45 ) ;
V_3 -> V_98 = 0 ;
V_3 -> V_99 = 0 ;
V_3 -> V_100 = V_105 ;
V_3 -> V_44 = V_105 ;
V_3 -> V_101 = 1 - V_3 -> V_9 ;
V_3 -> V_9 = 1 ;
V_3 -> V_102 = V_103 ;
F_9 ( V_3 , & V_96 ) ;
return V_96 ;
}
static void * F_52 ( struct V_3 * V_3 )
{
if ( V_3 -> V_47 == 4 )
return F_48 ( V_3 ) ;
if ( V_3 -> V_47 == 5 ) {
if ( V_3 -> V_104 == V_106 )
return F_48 ( V_3 ) ;
F_6 ( V_49 L_45 ,
F_7 ( V_3 ) , V_106 ) ;
}
if ( V_3 -> V_47 == 10 )
return F_50 ( V_3 ) ;
if ( V_3 -> V_47 == 1 )
return F_51 ( V_3 ) ;
F_6 ( V_49 L_46 ,
V_3 -> V_47 ) ;
return F_49 ( - V_45 ) ;
}
static void F_53 ( struct V_3 * V_3 , int V_107 )
{
}
static int T_2 F_54 ( void )
{
return F_55 ( & V_108 ) ;
}
static void F_56 ( void )
{
F_57 ( & V_108 ) ;
}
