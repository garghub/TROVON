static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 = V_2 -> V_5 ;
F_2 () ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
struct V_6 * V_7 = F_3 ( V_2 -> V_8 [ V_3 ] . V_7 ) ;
if ( V_7 && F_4 ( V_9 , & V_7 -> V_10 ) &&
! F_4 ( V_11 , & V_7 -> V_10 ) ) {
F_5 ( & V_7 -> V_12 ) ;
F_6 () ;
return V_3 ;
}
}
F_6 () ;
F_7 ( V_13 L_1 ) ;
return ( - 1 ) ;
}
static void F_8 ( struct V_14 * V_15 )
{
unsigned long V_10 ;
struct V_16 * V_16 = V_15 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_17 ;
F_9 ( & V_2 -> V_18 , V_10 ) ;
F_10 ( & V_15 -> V_19 , & V_2 -> V_19 ) ;
F_11 ( & V_2 -> V_18 , V_10 ) ;
F_12 ( V_16 -> V_20 ) ;
}
static void F_13 ( struct V_14 * V_15 , int V_21 )
{
struct V_22 * V_22 = V_15 -> V_23 ;
struct V_1 * V_2 = V_15 -> V_16 -> V_17 ;
V_22 -> V_24 = V_21 ;
F_14 ( V_22 ) ;
F_15 ( V_15 , V_2 -> V_25 ) ;
}
static void F_16 ( struct V_22 * V_22 )
{
struct V_14 * V_15 = V_22 -> V_26 ;
struct V_1 * V_2 = V_15 -> V_16 -> V_17 ;
struct V_6 * V_7 = V_2 -> V_8 [ V_15 -> V_27 ] . V_7 ;
if ( ! V_22 -> V_24 )
F_13 ( V_15 , 0 ) ;
else if ( ! ( V_22 -> V_28 & V_29 ) ) {
char V_30 [ V_31 ] ;
F_17 ( V_15 -> V_16 , V_7 ) ;
F_7 ( V_13 L_2 ,
F_18 ( V_7 -> V_32 , V_30 ) ,
( unsigned long long ) V_22 -> V_33 . V_34 ) ;
F_8 ( V_15 ) ;
} else
F_13 ( V_15 , V_22 -> V_24 ) ;
F_19 ( V_7 , V_2 -> V_16 ) ;
}
static void F_20 ( struct V_16 * V_16 , struct V_22 * V_22 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_14 * V_15 ;
struct V_35 * V_36 ;
if ( F_21 ( V_22 -> V_28 & V_37 ) ) {
F_22 ( V_16 , V_22 ) ;
return;
}
V_15 = F_23 ( V_2 -> V_25 , V_38 ) ;
V_15 -> V_23 = V_22 ;
V_15 -> V_16 = V_16 ;
V_15 -> V_27 = F_1 ( V_2 ) ;
if ( V_15 -> V_27 < 0 ) {
F_24 ( V_22 ) ;
F_15 ( V_15 , V_2 -> V_25 ) ;
return;
}
V_36 = V_2 -> V_8 + V_15 -> V_27 ;
F_25 ( & V_15 -> V_22 ) ;
F_26 ( & V_15 -> V_22 , V_22 ) ;
V_15 -> V_22 . V_33 . V_34 += V_36 -> V_7 -> V_39 ;
V_15 -> V_22 . V_40 = V_36 -> V_7 -> V_32 ;
V_15 -> V_22 . V_28 |= V_41 ;
V_15 -> V_22 . V_42 = F_16 ;
V_15 -> V_22 . V_26 = V_15 ;
F_27 ( & V_15 -> V_22 ) ;
return;
}
static void F_28 ( struct V_43 * V_44 , struct V_16 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
int V_3 ;
F_29 ( V_44 , L_3 , V_2 -> V_5 ,
V_2 -> V_5 - V_16 -> V_45 ) ;
F_2 () ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
struct V_6 * V_7 = F_3 ( V_2 -> V_8 [ V_3 ] . V_7 ) ;
F_29 ( V_44 , L_4 , V_7 && F_4 ( V_9 , & V_7 -> V_10 ) ? L_5 : L_6 ) ;
}
F_6 () ;
F_29 ( V_44 , L_7 ) ;
}
static int F_30 ( struct V_16 * V_16 , int V_46 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
int V_3 , V_47 = 0 ;
F_2 () ;
for ( V_3 = 0 ; V_3 < V_16 -> V_5 ; V_3 ++ ) {
struct V_6 * V_7 = F_3 ( V_2 -> V_8 [ V_3 ] . V_7 ) ;
if ( V_7 && ! F_4 ( V_11 , & V_7 -> V_10 ) ) {
struct V_48 * V_49 = F_31 ( V_7 -> V_32 ) ;
V_47 |= F_32 ( & V_49 -> V_50 , V_46 ) ;
break;
}
}
F_6 () ;
return V_47 ;
}
static void F_33 ( struct V_16 * V_16 , struct V_6 * V_7 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
char V_30 [ V_31 ] ;
if ( V_2 -> V_5 - V_16 -> V_45 <= 1 ) {
F_7 ( V_51
L_8 ) ;
return;
}
if ( F_34 ( V_9 , & V_7 -> V_10 ) ) {
unsigned long V_10 ;
F_9 ( & V_2 -> V_18 , V_10 ) ;
V_16 -> V_45 ++ ;
F_11 ( & V_2 -> V_18 , V_10 ) ;
}
F_35 ( V_11 , & V_7 -> V_10 ) ;
F_35 ( V_52 , & V_16 -> V_10 ) ;
F_7 ( V_51 L_9
L_10
L_11
L_12 ,
F_18 ( V_7 -> V_32 , V_30 ) ,
V_2 -> V_5 - V_16 -> V_45 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_35 * V_53 ;
F_7 ( L_13 ) ;
if ( ! V_2 ) {
F_7 ( L_14 ) ;
return;
}
F_7 ( L_15 , V_2 -> V_5 - V_2 -> V_16 -> V_45 ,
V_2 -> V_5 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
char V_30 [ V_31 ] ;
V_53 = V_2 -> V_8 + V_3 ;
if ( V_53 -> V_7 )
F_7 ( L_16 ,
V_3 , ! F_4 ( V_11 , & V_53 -> V_7 -> V_10 ) ,
F_18 ( V_53 -> V_7 -> V_32 , V_30 ) ) ;
}
}
static int F_37 ( struct V_16 * V_16 , struct V_6 * V_7 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_48 * V_49 ;
int V_21 = - V_54 ;
int V_27 ;
struct V_35 * V_55 ;
int V_56 = 0 ;
int V_57 = V_16 -> V_5 - 1 ;
if ( V_7 -> V_58 >= 0 )
V_56 = V_57 = V_7 -> V_58 ;
F_36 ( V_2 ) ;
for ( V_27 = V_56 ; V_27 <= V_57 ; V_27 ++ )
if ( ( V_55 = V_2 -> V_8 + V_27 ) -> V_7 == NULL ) {
V_49 = V_7 -> V_32 -> V_59 -> V_60 ;
F_38 ( V_16 -> V_61 , V_7 -> V_32 ,
V_7 -> V_39 << 9 ) ;
V_21 = F_39 ( V_7 , V_16 ) ;
if ( V_21 )
break;
F_40 ( & V_2 -> V_18 ) ;
V_16 -> V_45 -- ;
V_7 -> V_58 = V_27 ;
F_35 ( V_9 , & V_7 -> V_10 ) ;
F_41 ( & V_2 -> V_18 ) ;
F_42 ( V_55 -> V_7 , V_7 ) ;
V_21 = 0 ;
break;
}
F_36 ( V_2 ) ;
return V_21 ;
}
static int F_43 ( struct V_16 * V_16 , struct V_6 * V_7 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
int V_21 = 0 ;
int V_62 = V_7 -> V_58 ;
struct V_35 * V_55 = V_2 -> V_8 + V_62 ;
F_36 ( V_2 ) ;
if ( V_7 == V_55 -> V_7 ) {
if ( F_4 ( V_9 , & V_7 -> V_10 ) ||
F_44 ( & V_7 -> V_12 ) ) {
F_7 ( V_13 L_17
L_18 , V_62 ) ;
V_21 = - V_63 ;
goto abort;
}
V_55 -> V_7 = NULL ;
if ( ! F_4 ( V_64 , & V_7 -> V_10 ) ) {
F_45 () ;
if ( F_44 ( & V_7 -> V_12 ) ) {
V_21 = - V_63 ;
V_55 -> V_7 = V_7 ;
goto abort;
}
}
V_21 = F_46 ( V_16 ) ;
}
abort:
F_36 ( V_2 ) ;
return V_21 ;
}
static void F_47 ( struct V_65 * V_20 )
{
struct V_16 * V_16 = V_20 -> V_16 ;
struct V_14 * V_15 ;
struct V_22 * V_22 ;
unsigned long V_10 ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_66 * V_67 = & V_2 -> V_19 ;
F_48 ( V_16 ) ;
for (; ; ) {
char V_30 [ V_31 ] ;
F_9 ( & V_2 -> V_18 , V_10 ) ;
if ( F_49 ( V_67 ) )
break;
V_15 = F_50 ( V_67 -> V_68 , struct V_14 , V_19 ) ;
F_51 ( V_67 -> V_68 ) ;
F_11 ( & V_2 -> V_18 , V_10 ) ;
V_22 = & V_15 -> V_22 ;
V_22 -> V_33 . V_34 = V_15 -> V_23 -> V_33 . V_34 ;
if ( ( V_15 -> V_27 = F_1 ( V_2 ) ) < 0 ) {
F_7 ( V_51 L_19
L_20 ,
F_18 ( V_22 -> V_40 , V_30 ) ,
( unsigned long long ) V_22 -> V_33 . V_34 ) ;
F_13 ( V_15 , - V_69 ) ;
} else {
F_7 ( V_13 L_21
L_22 ,
F_18 ( V_22 -> V_40 , V_30 ) ,
( unsigned long long ) V_22 -> V_33 . V_34 ) ;
* V_22 = * ( V_15 -> V_23 ) ;
V_22 -> V_33 . V_34 +=
V_2 -> V_8 [ V_15 -> V_27 ] . V_7 -> V_39 ;
V_22 -> V_40 = V_2 -> V_8 [ V_15 -> V_27 ] . V_7 -> V_32 ;
V_22 -> V_28 |= V_41 ;
V_22 -> V_42 = F_16 ;
V_22 -> V_26 = V_15 ;
F_27 ( V_22 ) ;
}
}
F_11 ( & V_2 -> V_18 , V_10 ) ;
}
static T_1 F_52 ( struct V_16 * V_16 , T_1 V_70 , int V_5 )
{
F_53 ( V_70 || V_5 ,
L_23 , V_71 ) ;
return V_16 -> V_72 ;
}
static int F_54 ( struct V_16 * V_16 )
{
struct V_1 * V_2 ;
int V_73 ;
struct V_35 * V_74 ;
struct V_6 * V_7 ;
int V_75 ;
if ( F_55 ( V_16 ) )
return - V_76 ;
if ( V_16 -> V_77 != V_78 ) {
F_7 ( L_24 ,
F_56 ( V_16 ) , V_16 -> V_77 ) ;
goto V_79;
}
V_2 = F_57 ( sizeof( struct V_1 ) , V_80 ) ;
V_16 -> V_17 = V_2 ;
if ( ! V_2 ) {
F_7 ( V_13
L_25 ,
F_56 ( V_16 ) ) ;
goto V_79;
}
V_2 -> V_8 = F_57 ( sizeof( struct V_35 ) * V_16 -> V_5 ,
V_80 ) ;
if ( ! V_2 -> V_8 ) {
F_7 ( V_13
L_25 ,
F_56 ( V_16 ) ) ;
goto V_81;
}
V_75 = 0 ;
F_58 (rdev, mddev) {
V_73 = V_7 -> V_58 ;
if ( V_73 < 0 ||
V_73 >= V_16 -> V_5 )
continue;
V_74 = V_2 -> V_8 + V_73 ;
V_74 -> V_7 = V_7 ;
F_38 ( V_16 -> V_61 , V_7 -> V_32 ,
V_7 -> V_39 << 9 ) ;
if ( ! F_4 ( V_11 , & V_7 -> V_10 ) )
V_75 ++ ;
}
V_2 -> V_5 = V_16 -> V_5 ;
V_2 -> V_16 = V_16 ;
F_59 ( & V_2 -> V_18 ) ;
F_60 ( & V_2 -> V_19 ) ;
if ( ! V_75 ) {
F_7 ( V_13 L_26 ,
F_56 ( V_16 ) ) ;
goto V_81;
}
V_16 -> V_45 = V_2 -> V_5 - V_75 ;
V_2 -> V_25 = F_61 ( V_82 ,
sizeof( struct V_14 ) ) ;
if ( V_2 -> V_25 == NULL ) {
F_7 ( V_13
L_25 ,
F_56 ( V_16 ) ) ;
goto V_81;
}
{
V_16 -> V_20 = F_62 ( F_47 , V_16 ,
L_27 ) ;
if ( ! V_16 -> V_20 ) {
F_7 ( V_13 L_28
L_29 , F_56 ( V_16 ) ) ;
goto V_81;
}
}
F_7 ( V_83
L_30 ,
F_56 ( V_16 ) , V_2 -> V_5 - V_16 -> V_45 ,
V_16 -> V_5 ) ;
F_63 ( V_16 , F_52 ( V_16 , 0 , 0 ) ) ;
if ( F_46 ( V_16 ) )
goto V_81;
return 0 ;
V_81:
F_64 ( V_2 -> V_25 ) ;
F_65 ( V_2 -> V_8 ) ;
F_65 ( V_2 ) ;
V_16 -> V_17 = NULL ;
V_79:
return - V_69 ;
}
static void F_66 ( struct V_16 * V_16 , void * V_84 )
{
struct V_1 * V_2 = V_84 ;
F_64 ( V_2 -> V_25 ) ;
F_65 ( V_2 -> V_8 ) ;
F_65 ( V_2 ) ;
}
static int T_2 F_67 ( void )
{
return F_68 ( & V_85 ) ;
}
static void T_3 F_69 ( void )
{
F_70 ( & V_85 ) ;
}
