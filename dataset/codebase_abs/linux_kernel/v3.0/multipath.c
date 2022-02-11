static int F_1 ( T_1 * V_1 )
{
int V_2 , V_3 = V_1 -> V_4 ;
F_2 () ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
T_2 * V_5 = F_3 ( V_1 -> V_6 [ V_2 ] . V_5 ) ;
if ( V_5 && F_4 ( V_7 , & V_5 -> V_8 ) ) {
F_5 ( & V_5 -> V_9 ) ;
F_6 () ;
return V_2 ;
}
}
F_6 () ;
F_7 ( V_10 L_1 ) ;
return ( - 1 ) ;
}
static void F_8 ( struct V_11 * V_12 )
{
unsigned long V_8 ;
T_3 * V_13 = V_12 -> V_13 ;
T_1 * V_1 = V_13 -> V_14 ;
F_9 ( & V_1 -> V_15 , V_8 ) ;
F_10 ( & V_12 -> V_16 , & V_1 -> V_16 ) ;
F_11 ( & V_1 -> V_15 , V_8 ) ;
F_12 ( V_13 -> V_17 ) ;
}
static void F_13 ( struct V_11 * V_12 , int V_18 )
{
struct V_19 * V_19 = V_12 -> V_20 ;
T_1 * V_1 = V_12 -> V_13 -> V_14 ;
F_14 ( V_19 , V_18 ) ;
F_15 ( V_12 , V_1 -> V_21 ) ;
}
static void F_16 ( struct V_19 * V_19 , int error )
{
int V_22 = F_4 ( V_23 , & V_19 -> V_24 ) ;
struct V_11 * V_12 = V_19 -> V_25 ;
T_1 * V_1 = V_12 -> V_13 -> V_14 ;
T_2 * V_5 = V_1 -> V_6 [ V_12 -> V_26 ] . V_5 ;
if ( V_22 )
F_13 ( V_12 , 0 ) ;
else if ( ! ( V_19 -> V_27 & V_28 ) ) {
char V_29 [ V_30 ] ;
F_17 ( V_12 -> V_13 , V_5 ) ;
F_7 ( V_10 L_2 ,
F_18 ( V_5 -> V_31 , V_29 ) ,
( unsigned long long ) V_19 -> V_32 ) ;
F_8 ( V_12 ) ;
} else
F_13 ( V_12 , error ) ;
F_19 ( V_5 , V_1 -> V_13 ) ;
}
static int F_20 ( T_3 * V_13 , struct V_19 * V_19 )
{
T_1 * V_1 = V_13 -> V_14 ;
struct V_11 * V_12 ;
struct V_33 * V_34 ;
if ( F_21 ( V_19 -> V_27 & V_35 ) ) {
F_22 ( V_13 , V_19 ) ;
return 0 ;
}
V_12 = F_23 ( V_1 -> V_21 , V_36 ) ;
V_12 -> V_20 = V_19 ;
V_12 -> V_13 = V_13 ;
V_12 -> V_26 = F_1 ( V_1 ) ;
if ( V_12 -> V_26 < 0 ) {
F_14 ( V_19 , - V_37 ) ;
F_15 ( V_12 , V_1 -> V_21 ) ;
return 0 ;
}
V_34 = V_1 -> V_6 + V_12 -> V_26 ;
V_12 -> V_19 = * V_19 ;
V_12 -> V_19 . V_32 += V_34 -> V_5 -> V_38 ;
V_12 -> V_19 . V_39 = V_34 -> V_5 -> V_31 ;
V_12 -> V_19 . V_27 |= V_40 ;
V_12 -> V_19 . V_41 = F_16 ;
V_12 -> V_19 . V_25 = V_12 ;
F_24 ( & V_12 -> V_19 ) ;
return 0 ;
}
static void F_25 ( struct V_42 * V_43 , T_3 * V_13 )
{
T_1 * V_1 = V_13 -> V_14 ;
int V_2 ;
F_26 ( V_43 , L_3 , V_1 -> V_4 ,
V_1 -> V_4 - V_13 -> V_44 ) ;
for ( V_2 = 0 ; V_2 < V_1 -> V_4 ; V_2 ++ )
F_26 ( V_43 , L_4 ,
V_1 -> V_6 [ V_2 ] . V_5 &&
F_4 ( V_7 , & V_1 -> V_6 [ V_2 ] . V_5 -> V_8 ) ? L_5 : L_6 ) ;
F_26 ( V_43 , L_7 ) ;
}
static int F_27 ( void * V_45 , int V_46 )
{
T_3 * V_13 = V_45 ;
T_1 * V_1 = V_13 -> V_14 ;
int V_2 , V_47 = 0 ;
if ( F_28 ( V_13 , V_46 ) )
return 1 ;
F_2 () ;
for ( V_2 = 0 ; V_2 < V_13 -> V_4 ; V_2 ++ ) {
T_2 * V_5 = F_3 ( V_1 -> V_6 [ V_2 ] . V_5 ) ;
if ( V_5 && ! F_4 ( V_48 , & V_5 -> V_8 ) ) {
struct V_49 * V_50 = F_29 ( V_5 -> V_31 ) ;
V_47 |= F_30 ( & V_50 -> V_51 , V_46 ) ;
break;
}
}
F_6 () ;
return V_47 ;
}
static void F_31 ( T_3 * V_13 , T_2 * V_5 )
{
T_1 * V_1 = V_13 -> V_14 ;
char V_29 [ V_30 ] ;
if ( V_1 -> V_4 - V_13 -> V_44 <= 1 ) {
F_7 ( V_52
L_8 ) ;
return;
}
if ( F_32 ( V_7 , & V_5 -> V_8 ) ) {
unsigned long V_8 ;
F_9 ( & V_1 -> V_15 , V_8 ) ;
V_13 -> V_44 ++ ;
F_11 ( & V_1 -> V_15 , V_8 ) ;
}
F_33 ( V_48 , & V_5 -> V_8 ) ;
F_33 ( V_53 , & V_13 -> V_8 ) ;
F_7 ( V_52 L_9
L_10
L_11
L_12 ,
F_18 ( V_5 -> V_31 , V_29 ) ,
V_1 -> V_4 - V_13 -> V_44 ) ;
}
static void F_34 ( T_1 * V_1 )
{
int V_2 ;
struct V_33 * V_54 ;
F_7 ( L_13 ) ;
if ( ! V_1 ) {
F_7 ( L_14 ) ;
return;
}
F_7 ( L_15 , V_1 -> V_4 - V_1 -> V_13 -> V_44 ,
V_1 -> V_4 ) ;
for ( V_2 = 0 ; V_2 < V_1 -> V_4 ; V_2 ++ ) {
char V_29 [ V_30 ] ;
V_54 = V_1 -> V_6 + V_2 ;
if ( V_54 -> V_5 )
F_7 ( L_16 ,
V_2 , ! F_4 ( V_48 , & V_54 -> V_5 -> V_8 ) ,
F_18 ( V_54 -> V_5 -> V_31 , V_29 ) ) ;
}
}
static int F_35 ( T_3 * V_13 , T_2 * V_5 )
{
T_1 * V_1 = V_13 -> V_14 ;
struct V_49 * V_50 ;
int V_18 = - V_55 ;
int V_26 ;
struct V_33 * V_56 ;
int V_57 = 0 ;
int V_58 = V_13 -> V_4 - 1 ;
if ( V_5 -> V_59 >= 0 )
V_57 = V_58 = V_5 -> V_59 ;
F_34 ( V_1 ) ;
for ( V_26 = V_57 ; V_26 <= V_58 ; V_26 ++ )
if ( ( V_56 = V_1 -> V_6 + V_26 ) -> V_5 == NULL ) {
V_50 = V_5 -> V_31 -> V_60 -> V_61 ;
F_36 ( V_13 -> V_62 , V_5 -> V_31 ,
V_5 -> V_38 << 9 ) ;
if ( V_50 -> V_63 ) {
F_37 ( V_13 -> V_61 , 1 ) ;
F_38 ( V_13 -> V_61 ,
V_64 - 1 ) ;
}
F_39 ( & V_1 -> V_15 ) ;
V_13 -> V_44 -- ;
V_5 -> V_59 = V_26 ;
F_33 ( V_7 , & V_5 -> V_8 ) ;
F_40 ( & V_1 -> V_15 ) ;
F_41 ( V_56 -> V_5 , V_5 ) ;
V_18 = 0 ;
F_42 ( V_5 , V_13 ) ;
break;
}
F_34 ( V_1 ) ;
return V_18 ;
}
static int F_43 ( T_3 * V_13 , int V_65 )
{
T_1 * V_1 = V_13 -> V_14 ;
int V_18 = 0 ;
T_2 * V_5 ;
struct V_33 * V_56 = V_1 -> V_6 + V_65 ;
F_34 ( V_1 ) ;
V_5 = V_56 -> V_5 ;
if ( V_5 ) {
if ( F_4 ( V_7 , & V_5 -> V_8 ) ||
F_44 ( & V_5 -> V_9 ) ) {
F_7 ( V_10 L_17
L_18 , V_65 ) ;
V_18 = - V_66 ;
goto abort;
}
V_56 -> V_5 = NULL ;
F_45 () ;
if ( F_44 ( & V_5 -> V_9 ) ) {
V_18 = - V_66 ;
V_56 -> V_5 = V_5 ;
goto abort;
}
V_18 = F_46 ( V_13 ) ;
}
abort:
F_34 ( V_1 ) ;
return V_18 ;
}
static void F_47 ( T_3 * V_13 )
{
struct V_11 * V_12 ;
struct V_19 * V_19 ;
unsigned long V_8 ;
T_1 * V_1 = V_13 -> V_14 ;
struct V_67 * V_68 = & V_1 -> V_16 ;
F_48 ( V_13 ) ;
for (; ; ) {
char V_29 [ V_30 ] ;
F_9 ( & V_1 -> V_15 , V_8 ) ;
if ( F_49 ( V_68 ) )
break;
V_12 = F_50 ( V_68 -> V_69 , struct V_11 , V_16 ) ;
F_51 ( V_68 -> V_69 ) ;
F_11 ( & V_1 -> V_15 , V_8 ) ;
V_19 = & V_12 -> V_19 ;
V_19 -> V_32 = V_12 -> V_20 -> V_32 ;
if ( ( V_12 -> V_26 = F_1 ( V_1 ) ) < 0 ) {
F_7 ( V_52 L_19
L_20 ,
F_18 ( V_19 -> V_39 , V_29 ) ,
( unsigned long long ) V_19 -> V_32 ) ;
F_13 ( V_12 , - V_37 ) ;
} else {
F_7 ( V_10 L_21
L_22 ,
F_18 ( V_19 -> V_39 , V_29 ) ,
( unsigned long long ) V_19 -> V_32 ) ;
* V_19 = * ( V_12 -> V_20 ) ;
V_19 -> V_32 += V_1 -> V_6 [ V_12 -> V_26 ] . V_5 -> V_38 ;
V_19 -> V_39 = V_1 -> V_6 [ V_12 -> V_26 ] . V_5 -> V_31 ;
V_19 -> V_27 |= V_40 ;
V_19 -> V_41 = F_16 ;
V_19 -> V_25 = V_12 ;
F_24 ( V_19 ) ;
}
}
F_11 ( & V_1 -> V_15 , V_8 ) ;
}
static T_4 F_52 ( T_3 * V_13 , T_4 V_70 , int V_4 )
{
F_53 ( V_70 || V_4 ,
L_23 , V_71 ) ;
return V_13 -> V_72 ;
}
static int F_54 ( T_3 * V_13 )
{
T_1 * V_1 ;
int V_73 ;
struct V_33 * V_74 ;
T_2 * V_5 ;
int V_75 ;
if ( F_55 ( V_13 ) )
return - V_76 ;
if ( V_13 -> V_77 != V_78 ) {
F_7 ( L_24 ,
F_56 ( V_13 ) , V_13 -> V_77 ) ;
goto V_79;
}
V_1 = F_57 ( sizeof( T_1 ) , V_80 ) ;
V_13 -> V_14 = V_1 ;
if ( ! V_1 ) {
F_7 ( V_10
L_25 ,
F_56 ( V_13 ) ) ;
goto V_79;
}
V_1 -> V_6 = F_57 ( sizeof( struct V_33 ) * V_13 -> V_4 ,
V_80 ) ;
if ( ! V_1 -> V_6 ) {
F_7 ( V_10
L_25 ,
F_56 ( V_13 ) ) ;
goto V_81;
}
V_75 = 0 ;
F_58 (rdev, &mddev->disks, same_set) {
V_73 = V_5 -> V_59 ;
if ( V_73 < 0 ||
V_73 >= V_13 -> V_4 )
continue;
V_74 = V_1 -> V_6 + V_73 ;
V_74 -> V_5 = V_5 ;
F_36 ( V_13 -> V_62 , V_5 -> V_31 ,
V_5 -> V_38 << 9 ) ;
if ( V_5 -> V_31 -> V_60 -> V_61 -> V_63 ) {
F_37 ( V_13 -> V_61 , 1 ) ;
F_38 ( V_13 -> V_61 ,
V_64 - 1 ) ;
}
if ( ! F_4 ( V_48 , & V_5 -> V_8 ) )
V_75 ++ ;
}
V_1 -> V_4 = V_13 -> V_4 ;
V_1 -> V_13 = V_13 ;
F_59 ( & V_1 -> V_15 ) ;
F_60 ( & V_1 -> V_16 ) ;
if ( ! V_75 ) {
F_7 ( V_10 L_26 ,
F_56 ( V_13 ) ) ;
goto V_81;
}
V_13 -> V_44 = V_1 -> V_4 - V_75 ;
V_1 -> V_21 = F_61 ( V_82 ,
sizeof( struct V_11 ) ) ;
if ( V_1 -> V_21 == NULL ) {
F_7 ( V_10
L_25 ,
F_56 ( V_13 ) ) ;
goto V_81;
}
{
V_13 -> V_17 = F_62 ( F_47 , V_13 , NULL ) ;
if ( ! V_13 -> V_17 ) {
F_7 ( V_10 L_27
L_28 , F_56 ( V_13 ) ) ;
goto V_81;
}
}
F_7 ( V_83
L_29 ,
F_56 ( V_13 ) , V_1 -> V_4 - V_13 -> V_44 ,
V_13 -> V_4 ) ;
F_63 ( V_13 , F_52 ( V_13 , 0 , 0 ) ) ;
V_13 -> V_61 -> V_51 . V_84 = F_27 ;
V_13 -> V_61 -> V_51 . V_85 = V_13 ;
if ( F_46 ( V_13 ) )
goto V_81;
return 0 ;
V_81:
if ( V_1 -> V_21 )
F_64 ( V_1 -> V_21 ) ;
F_65 ( V_1 -> V_6 ) ;
F_65 ( V_1 ) ;
V_13 -> V_14 = NULL ;
V_79:
return - V_37 ;
}
static int F_66 ( T_3 * V_13 )
{
T_1 * V_1 = V_13 -> V_14 ;
F_67 ( V_13 -> V_17 ) ;
V_13 -> V_17 = NULL ;
F_68 ( V_13 -> V_61 ) ;
F_64 ( V_1 -> V_21 ) ;
F_65 ( V_1 -> V_6 ) ;
F_65 ( V_1 ) ;
V_13 -> V_14 = NULL ;
return 0 ;
}
static int T_5 F_69 ( void )
{
return F_70 ( & V_86 ) ;
}
static void T_6 F_71 ( void )
{
F_72 ( & V_86 ) ;
}
