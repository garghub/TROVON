static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 = V_2 -> V_5 ;
F_2 () ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
struct V_6 * V_7 = F_3 ( V_2 -> V_8 [ V_3 ] . V_7 ) ;
if ( V_7 && F_4 ( V_9 , & V_7 -> V_10 ) ) {
F_5 ( & V_7 -> V_11 ) ;
F_6 () ;
return V_3 ;
}
}
F_6 () ;
F_7 ( V_12 L_1 ) ;
return ( - 1 ) ;
}
static void F_8 ( struct V_13 * V_14 )
{
unsigned long V_10 ;
struct V_15 * V_15 = V_14 -> V_15 ;
struct V_1 * V_2 = V_15 -> V_16 ;
F_9 ( & V_2 -> V_17 , V_10 ) ;
F_10 ( & V_14 -> V_18 , & V_2 -> V_18 ) ;
F_11 ( & V_2 -> V_17 , V_10 ) ;
F_12 ( V_15 -> V_19 ) ;
}
static void F_13 ( struct V_13 * V_14 , int V_20 )
{
struct V_21 * V_21 = V_14 -> V_22 ;
struct V_1 * V_2 = V_14 -> V_15 -> V_16 ;
F_14 ( V_21 , V_20 ) ;
F_15 ( V_14 , V_2 -> V_23 ) ;
}
static void F_16 ( struct V_21 * V_21 , int error )
{
int V_24 = F_4 ( V_25 , & V_21 -> V_26 ) ;
struct V_13 * V_14 = V_21 -> V_27 ;
struct V_1 * V_2 = V_14 -> V_15 -> V_16 ;
struct V_6 * V_7 = V_2 -> V_8 [ V_14 -> V_28 ] . V_7 ;
if ( V_24 )
F_13 ( V_14 , 0 ) ;
else if ( ! ( V_21 -> V_29 & V_30 ) ) {
char V_31 [ V_32 ] ;
F_17 ( V_14 -> V_15 , V_7 ) ;
F_7 ( V_12 L_2 ,
F_18 ( V_7 -> V_33 , V_31 ) ,
( unsigned long long ) V_21 -> V_34 . V_35 ) ;
F_8 ( V_14 ) ;
} else
F_13 ( V_14 , error ) ;
F_19 ( V_7 , V_2 -> V_15 ) ;
}
static void F_20 ( struct V_15 * V_15 , struct V_21 * V_21 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_13 * V_14 ;
struct V_36 * V_37 ;
if ( F_21 ( V_21 -> V_29 & V_38 ) ) {
F_22 ( V_15 , V_21 ) ;
return;
}
V_14 = F_23 ( V_2 -> V_23 , V_39 ) ;
V_14 -> V_22 = V_21 ;
V_14 -> V_15 = V_15 ;
V_14 -> V_28 = F_1 ( V_2 ) ;
if ( V_14 -> V_28 < 0 ) {
F_14 ( V_21 , - V_40 ) ;
F_15 ( V_14 , V_2 -> V_23 ) ;
return;
}
V_37 = V_2 -> V_8 + V_14 -> V_28 ;
V_14 -> V_21 = * V_21 ;
V_14 -> V_21 . V_34 . V_35 += V_37 -> V_7 -> V_41 ;
V_14 -> V_21 . V_42 = V_37 -> V_7 -> V_33 ;
V_14 -> V_21 . V_29 |= V_43 ;
V_14 -> V_21 . V_44 = F_16 ;
V_14 -> V_21 . V_27 = V_14 ;
F_24 ( & V_14 -> V_21 ) ;
return;
}
static void F_25 ( struct V_45 * V_46 , struct V_15 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
int V_3 ;
F_26 ( V_46 , L_3 , V_2 -> V_5 ,
V_2 -> V_5 - V_15 -> V_47 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ )
F_26 ( V_46 , L_4 ,
V_2 -> V_8 [ V_3 ] . V_7 &&
F_4 ( V_9 , & V_2 -> V_8 [ V_3 ] . V_7 -> V_10 ) ? L_5 : L_6 ) ;
F_26 ( V_46 , L_7 ) ;
}
static int F_27 ( struct V_15 * V_15 , int V_48 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
int V_3 , V_49 = 0 ;
F_2 () ;
for ( V_3 = 0 ; V_3 < V_15 -> V_5 ; V_3 ++ ) {
struct V_6 * V_7 = F_3 ( V_2 -> V_8 [ V_3 ] . V_7 ) ;
if ( V_7 && ! F_4 ( V_50 , & V_7 -> V_10 ) ) {
struct V_51 * V_52 = F_28 ( V_7 -> V_33 ) ;
V_49 |= F_29 ( & V_52 -> V_53 , V_48 ) ;
break;
}
}
F_6 () ;
return V_49 ;
}
static void F_30 ( struct V_15 * V_15 , struct V_6 * V_7 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
char V_31 [ V_32 ] ;
if ( V_2 -> V_5 - V_15 -> V_47 <= 1 ) {
F_7 ( V_54
L_8 ) ;
return;
}
if ( F_31 ( V_9 , & V_7 -> V_10 ) ) {
unsigned long V_10 ;
F_9 ( & V_2 -> V_17 , V_10 ) ;
V_15 -> V_47 ++ ;
F_11 ( & V_2 -> V_17 , V_10 ) ;
}
F_32 ( V_50 , & V_7 -> V_10 ) ;
F_32 ( V_55 , & V_15 -> V_10 ) ;
F_7 ( V_54 L_9
L_10
L_11
L_12 ,
F_18 ( V_7 -> V_33 , V_31 ) ,
V_2 -> V_5 - V_15 -> V_47 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_36 * V_56 ;
F_7 ( L_13 ) ;
if ( ! V_2 ) {
F_7 ( L_14 ) ;
return;
}
F_7 ( L_15 , V_2 -> V_5 - V_2 -> V_15 -> V_47 ,
V_2 -> V_5 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
char V_31 [ V_32 ] ;
V_56 = V_2 -> V_8 + V_3 ;
if ( V_56 -> V_7 )
F_7 ( L_16 ,
V_3 , ! F_4 ( V_50 , & V_56 -> V_7 -> V_10 ) ,
F_18 ( V_56 -> V_7 -> V_33 , V_31 ) ) ;
}
}
static int F_34 ( struct V_15 * V_15 , struct V_6 * V_7 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_51 * V_52 ;
int V_20 = - V_57 ;
int V_28 ;
struct V_36 * V_58 ;
int V_59 = 0 ;
int V_60 = V_15 -> V_5 - 1 ;
if ( V_7 -> V_61 >= 0 )
V_59 = V_60 = V_7 -> V_61 ;
F_33 ( V_2 ) ;
for ( V_28 = V_59 ; V_28 <= V_60 ; V_28 ++ )
if ( ( V_58 = V_2 -> V_8 + V_28 ) -> V_7 == NULL ) {
V_52 = V_7 -> V_33 -> V_62 -> V_63 ;
F_35 ( V_15 -> V_64 , V_7 -> V_33 ,
V_7 -> V_41 << 9 ) ;
if ( V_52 -> V_65 ) {
F_36 ( V_15 -> V_63 , 1 ) ;
F_37 ( V_15 -> V_63 ,
V_66 - 1 ) ;
}
F_38 ( & V_2 -> V_17 ) ;
V_15 -> V_47 -- ;
V_7 -> V_61 = V_28 ;
F_32 ( V_9 , & V_7 -> V_10 ) ;
F_39 ( & V_2 -> V_17 ) ;
F_40 ( V_58 -> V_7 , V_7 ) ;
V_20 = 0 ;
F_41 ( V_7 , V_15 ) ;
break;
}
F_33 ( V_2 ) ;
return V_20 ;
}
static int F_42 ( struct V_15 * V_15 , struct V_6 * V_7 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
int V_20 = 0 ;
int V_67 = V_7 -> V_61 ;
struct V_36 * V_58 = V_2 -> V_8 + V_67 ;
F_33 ( V_2 ) ;
if ( V_7 == V_58 -> V_7 ) {
if ( F_4 ( V_9 , & V_7 -> V_10 ) ||
F_43 ( & V_7 -> V_11 ) ) {
F_7 ( V_12 L_17
L_18 , V_67 ) ;
V_20 = - V_68 ;
goto abort;
}
V_58 -> V_7 = NULL ;
F_44 () ;
if ( F_43 ( & V_7 -> V_11 ) ) {
V_20 = - V_68 ;
V_58 -> V_7 = V_7 ;
goto abort;
}
V_20 = F_45 ( V_15 ) ;
}
abort:
F_33 ( V_2 ) ;
return V_20 ;
}
static void F_46 ( struct V_69 * V_19 )
{
struct V_15 * V_15 = V_19 -> V_15 ;
struct V_13 * V_14 ;
struct V_21 * V_21 ;
unsigned long V_10 ;
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_70 * V_71 = & V_2 -> V_18 ;
F_47 ( V_15 ) ;
for (; ; ) {
char V_31 [ V_32 ] ;
F_9 ( & V_2 -> V_17 , V_10 ) ;
if ( F_48 ( V_71 ) )
break;
V_14 = F_49 ( V_71 -> V_72 , struct V_13 , V_18 ) ;
F_50 ( V_71 -> V_72 ) ;
F_11 ( & V_2 -> V_17 , V_10 ) ;
V_21 = & V_14 -> V_21 ;
V_21 -> V_34 . V_35 = V_14 -> V_22 -> V_34 . V_35 ;
if ( ( V_14 -> V_28 = F_1 ( V_2 ) ) < 0 ) {
F_7 ( V_54 L_19
L_20 ,
F_18 ( V_21 -> V_42 , V_31 ) ,
( unsigned long long ) V_21 -> V_34 . V_35 ) ;
F_13 ( V_14 , - V_40 ) ;
} else {
F_7 ( V_12 L_21
L_22 ,
F_18 ( V_21 -> V_42 , V_31 ) ,
( unsigned long long ) V_21 -> V_34 . V_35 ) ;
* V_21 = * ( V_14 -> V_22 ) ;
V_21 -> V_34 . V_35 +=
V_2 -> V_8 [ V_14 -> V_28 ] . V_7 -> V_41 ;
V_21 -> V_42 = V_2 -> V_8 [ V_14 -> V_28 ] . V_7 -> V_33 ;
V_21 -> V_29 |= V_43 ;
V_21 -> V_44 = F_16 ;
V_21 -> V_27 = V_14 ;
F_24 ( V_21 ) ;
}
}
F_11 ( & V_2 -> V_17 , V_10 ) ;
}
static T_1 F_51 ( struct V_15 * V_15 , T_1 V_73 , int V_5 )
{
F_52 ( V_73 || V_5 ,
L_23 , V_74 ) ;
return V_15 -> V_75 ;
}
static int F_53 ( struct V_15 * V_15 )
{
struct V_1 * V_2 ;
int V_76 ;
struct V_36 * V_77 ;
struct V_6 * V_7 ;
int V_78 ;
if ( F_54 ( V_15 ) )
return - V_79 ;
if ( V_15 -> V_80 != V_81 ) {
F_7 ( L_24 ,
F_55 ( V_15 ) , V_15 -> V_80 ) ;
goto V_82;
}
V_2 = F_56 ( sizeof( struct V_1 ) , V_83 ) ;
V_15 -> V_16 = V_2 ;
if ( ! V_2 ) {
F_7 ( V_12
L_25 ,
F_55 ( V_15 ) ) ;
goto V_82;
}
V_2 -> V_8 = F_56 ( sizeof( struct V_36 ) * V_15 -> V_5 ,
V_83 ) ;
if ( ! V_2 -> V_8 ) {
F_7 ( V_12
L_25 ,
F_55 ( V_15 ) ) ;
goto V_84;
}
V_78 = 0 ;
F_57 (rdev, mddev) {
V_76 = V_7 -> V_61 ;
if ( V_76 < 0 ||
V_76 >= V_15 -> V_5 )
continue;
V_77 = V_2 -> V_8 + V_76 ;
V_77 -> V_7 = V_7 ;
F_35 ( V_15 -> V_64 , V_7 -> V_33 ,
V_7 -> V_41 << 9 ) ;
if ( V_7 -> V_33 -> V_62 -> V_63 -> V_65 ) {
F_36 ( V_15 -> V_63 , 1 ) ;
F_37 ( V_15 -> V_63 ,
V_66 - 1 ) ;
}
if ( ! F_4 ( V_50 , & V_7 -> V_10 ) )
V_78 ++ ;
}
V_2 -> V_5 = V_15 -> V_5 ;
V_2 -> V_15 = V_15 ;
F_58 ( & V_2 -> V_17 ) ;
F_59 ( & V_2 -> V_18 ) ;
if ( ! V_78 ) {
F_7 ( V_12 L_26 ,
F_55 ( V_15 ) ) ;
goto V_84;
}
V_15 -> V_47 = V_2 -> V_5 - V_78 ;
V_2 -> V_23 = F_60 ( V_85 ,
sizeof( struct V_13 ) ) ;
if ( V_2 -> V_23 == NULL ) {
F_7 ( V_12
L_25 ,
F_55 ( V_15 ) ) ;
goto V_84;
}
{
V_15 -> V_19 = F_61 ( F_46 , V_15 ,
L_27 ) ;
if ( ! V_15 -> V_19 ) {
F_7 ( V_12 L_28
L_29 , F_55 ( V_15 ) ) ;
goto V_84;
}
}
F_7 ( V_86
L_30 ,
F_55 ( V_15 ) , V_2 -> V_5 - V_15 -> V_47 ,
V_15 -> V_5 ) ;
F_62 ( V_15 , F_51 ( V_15 , 0 , 0 ) ) ;
if ( F_45 ( V_15 ) )
goto V_84;
return 0 ;
V_84:
if ( V_2 -> V_23 )
F_63 ( V_2 -> V_23 ) ;
F_64 ( V_2 -> V_8 ) ;
F_64 ( V_2 ) ;
V_15 -> V_16 = NULL ;
V_82:
return - V_40 ;
}
static void F_65 ( struct V_15 * V_15 , void * V_87 )
{
struct V_1 * V_2 = V_87 ;
F_63 ( V_2 -> V_23 ) ;
F_64 ( V_2 -> V_8 ) ;
F_64 ( V_2 ) ;
}
static int T_2 F_66 ( void )
{
return F_67 ( & V_88 ) ;
}
static void T_3 F_68 ( void )
{
F_69 ( & V_88 ) ;
}
