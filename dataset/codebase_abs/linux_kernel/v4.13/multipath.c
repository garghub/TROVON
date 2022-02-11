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
F_7 ( L_1 ) ;
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
static void F_13 ( struct V_13 * V_14 , T_1 V_20 )
{
struct V_21 * V_21 = V_14 -> V_22 ;
struct V_1 * V_2 = V_14 -> V_15 -> V_16 ;
V_21 -> V_23 = V_20 ;
F_14 ( V_21 ) ;
F_15 ( V_14 , V_2 -> V_24 ) ;
}
static void F_16 ( struct V_21 * V_21 )
{
struct V_13 * V_14 = V_21 -> V_25 ;
struct V_1 * V_2 = V_14 -> V_15 -> V_16 ;
struct V_6 * V_7 = V_2 -> V_8 [ V_14 -> V_26 ] . V_7 ;
if ( ! V_21 -> V_23 )
F_13 ( V_14 , 0 ) ;
else if ( ! ( V_21 -> V_27 & V_28 ) ) {
char V_29 [ V_30 ] ;
F_17 ( V_14 -> V_15 , V_7 ) ;
F_18 ( L_2 ,
F_19 ( V_7 -> V_31 , V_29 ) ,
( unsigned long long ) V_21 -> V_32 . V_33 ) ;
F_8 ( V_14 ) ;
} else
F_13 ( V_14 , V_21 -> V_23 ) ;
F_20 ( V_7 , V_2 -> V_15 ) ;
}
static bool F_21 ( struct V_15 * V_15 , struct V_21 * V_21 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_13 * V_14 ;
struct V_34 * V_35 ;
if ( F_22 ( V_21 -> V_27 & V_36 ) ) {
F_23 ( V_15 , V_21 ) ;
return true ;
}
V_14 = F_24 ( V_2 -> V_24 , V_37 ) ;
V_14 -> V_22 = V_21 ;
V_14 -> V_15 = V_15 ;
V_14 -> V_26 = F_1 ( V_2 ) ;
if ( V_14 -> V_26 < 0 ) {
F_25 ( V_21 ) ;
F_15 ( V_14 , V_2 -> V_24 ) ;
return true ;
}
V_35 = V_2 -> V_8 + V_14 -> V_26 ;
F_26 ( & V_14 -> V_21 , NULL , 0 ) ;
F_27 ( & V_14 -> V_21 , V_21 ) ;
V_14 -> V_21 . V_32 . V_33 += V_35 -> V_7 -> V_38 ;
V_14 -> V_21 . V_39 = V_35 -> V_7 -> V_31 ;
V_14 -> V_21 . V_27 |= V_40 ;
V_14 -> V_21 . V_41 = F_16 ;
V_14 -> V_21 . V_25 = V_14 ;
F_28 ( V_15 , & V_14 -> V_21 ) ;
F_29 ( V_15 , & V_14 -> V_21 ) ;
F_30 ( & V_14 -> V_21 ) ;
return true ;
}
static void F_31 ( struct V_42 * V_43 , struct V_15 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
int V_3 ;
F_32 ( V_43 , L_3 , V_2 -> V_5 ,
V_2 -> V_5 - V_15 -> V_44 ) ;
F_2 () ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
struct V_6 * V_7 = F_3 ( V_2 -> V_8 [ V_3 ] . V_7 ) ;
F_32 ( V_43 , L_4 , V_7 && F_4 ( V_9 , & V_7 -> V_10 ) ? L_5 : L_6 ) ;
}
F_6 () ;
F_32 ( V_43 , L_7 ) ;
}
static int F_33 ( struct V_15 * V_15 , int V_45 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
int V_3 , V_46 = 0 ;
F_2 () ;
for ( V_3 = 0 ; V_3 < V_15 -> V_5 ; V_3 ++ ) {
struct V_6 * V_7 = F_3 ( V_2 -> V_8 [ V_3 ] . V_7 ) ;
if ( V_7 && ! F_4 ( V_11 , & V_7 -> V_10 ) ) {
struct V_47 * V_48 = F_34 ( V_7 -> V_31 ) ;
V_46 |= F_35 ( V_48 -> V_49 , V_45 ) ;
break;
}
}
F_6 () ;
return V_46 ;
}
static void F_36 ( struct V_15 * V_15 , struct V_6 * V_7 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
char V_29 [ V_30 ] ;
if ( V_2 -> V_5 - V_15 -> V_44 <= 1 ) {
F_37 ( L_8 ) ;
return;
}
if ( F_38 ( V_9 , & V_7 -> V_10 ) ) {
unsigned long V_10 ;
F_9 ( & V_2 -> V_17 , V_10 ) ;
V_15 -> V_44 ++ ;
F_11 ( & V_2 -> V_17 , V_10 ) ;
}
F_39 ( V_11 , & V_7 -> V_10 ) ;
F_39 ( V_50 , & V_15 -> V_51 ) ;
F_40 ( L_9
L_10 ,
F_19 ( V_7 -> V_31 , V_29 ) ,
V_2 -> V_5 - V_15 -> V_44 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_34 * V_52 ;
F_42 ( L_11 ) ;
if ( ! V_2 ) {
F_42 ( L_12 ) ;
return;
}
F_42 ( L_13 , V_2 -> V_5 - V_2 -> V_15 -> V_44 ,
V_2 -> V_5 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
char V_29 [ V_30 ] ;
V_52 = V_2 -> V_8 + V_3 ;
if ( V_52 -> V_7 )
F_42 ( L_14 ,
V_3 , ! F_4 ( V_11 , & V_52 -> V_7 -> V_10 ) ,
F_19 ( V_52 -> V_7 -> V_31 , V_29 ) ) ;
}
}
static int F_43 ( struct V_15 * V_15 , struct V_6 * V_7 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_47 * V_48 ;
int V_53 = - V_54 ;
int V_26 ;
struct V_34 * V_55 ;
int V_56 = 0 ;
int V_57 = V_15 -> V_5 - 1 ;
if ( V_7 -> V_58 >= 0 )
V_56 = V_57 = V_7 -> V_58 ;
F_41 ( V_2 ) ;
for ( V_26 = V_56 ; V_26 <= V_57 ; V_26 ++ )
if ( ( V_55 = V_2 -> V_8 + V_26 ) -> V_7 == NULL ) {
V_48 = V_7 -> V_31 -> V_59 -> V_60 ;
F_44 ( V_15 -> V_61 , V_7 -> V_31 ,
V_7 -> V_38 << 9 ) ;
V_53 = F_45 ( V_7 , V_15 ) ;
if ( V_53 )
break;
F_46 ( & V_2 -> V_17 ) ;
V_15 -> V_44 -- ;
V_7 -> V_58 = V_26 ;
F_39 ( V_9 , & V_7 -> V_10 ) ;
F_47 ( & V_2 -> V_17 ) ;
F_48 ( V_55 -> V_7 , V_7 ) ;
V_53 = 0 ;
break;
}
F_41 ( V_2 ) ;
return V_53 ;
}
static int F_49 ( struct V_15 * V_15 , struct V_6 * V_7 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
int V_53 = 0 ;
int V_62 = V_7 -> V_58 ;
struct V_34 * V_55 = V_2 -> V_8 + V_62 ;
F_41 ( V_2 ) ;
if ( V_7 == V_55 -> V_7 ) {
if ( F_4 ( V_9 , & V_7 -> V_10 ) ||
F_50 ( & V_7 -> V_12 ) ) {
F_37 ( L_15 , V_62 ) ;
V_53 = - V_63 ;
goto abort;
}
V_55 -> V_7 = NULL ;
if ( ! F_4 ( V_64 , & V_7 -> V_10 ) ) {
F_51 () ;
if ( F_50 ( & V_7 -> V_12 ) ) {
V_53 = - V_63 ;
V_55 -> V_7 = V_7 ;
goto abort;
}
}
V_53 = F_52 ( V_15 ) ;
}
abort:
F_41 ( V_2 ) ;
return V_53 ;
}
static void F_53 ( struct V_65 * V_19 )
{
struct V_15 * V_15 = V_19 -> V_15 ;
struct V_13 * V_14 ;
struct V_21 * V_21 ;
unsigned long V_10 ;
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_66 * V_67 = & V_2 -> V_18 ;
F_54 ( V_15 ) ;
for (; ; ) {
char V_29 [ V_30 ] ;
F_9 ( & V_2 -> V_17 , V_10 ) ;
if ( F_55 ( V_67 ) )
break;
V_14 = F_56 ( V_67 -> V_68 , struct V_13 , V_18 ) ;
F_57 ( V_67 -> V_68 ) ;
F_11 ( & V_2 -> V_17 , V_10 ) ;
V_21 = & V_14 -> V_21 ;
V_21 -> V_32 . V_33 = V_14 -> V_22 -> V_32 . V_33 ;
if ( ( V_14 -> V_26 = F_1 ( V_2 ) ) < 0 ) {
F_40 ( L_16 ,
F_19 ( V_21 -> V_39 , V_29 ) ,
( unsigned long long ) V_21 -> V_32 . V_33 ) ;
F_13 ( V_14 , V_69 ) ;
} else {
F_40 ( L_17 ,
F_19 ( V_21 -> V_39 , V_29 ) ,
( unsigned long long ) V_21 -> V_32 . V_33 ) ;
* V_21 = * ( V_14 -> V_22 ) ;
V_21 -> V_32 . V_33 +=
V_2 -> V_8 [ V_14 -> V_26 ] . V_7 -> V_38 ;
V_21 -> V_39 = V_2 -> V_8 [ V_14 -> V_26 ] . V_7 -> V_31 ;
V_21 -> V_27 |= V_40 ;
V_21 -> V_41 = F_16 ;
V_21 -> V_25 = V_14 ;
F_30 ( V_21 ) ;
}
}
F_11 ( & V_2 -> V_17 , V_10 ) ;
}
static T_2 F_58 ( struct V_15 * V_15 , T_2 V_70 , int V_5 )
{
F_59 ( V_70 || V_5 ,
L_18 , V_71 ) ;
return V_15 -> V_72 ;
}
static int F_60 ( struct V_15 * V_15 )
{
struct V_1 * V_2 ;
int V_73 ;
struct V_34 * V_74 ;
struct V_6 * V_7 ;
int V_75 ;
if ( F_61 ( V_15 ) )
return - V_76 ;
if ( V_15 -> V_77 != V_78 ) {
F_37 ( L_19 ,
F_62 ( V_15 ) , V_15 -> V_77 ) ;
goto V_79;
}
V_2 = F_63 ( sizeof( struct V_1 ) , V_80 ) ;
V_15 -> V_16 = V_2 ;
if ( ! V_2 )
goto V_79;
V_2 -> V_8 = F_63 ( sizeof( struct V_34 ) * V_15 -> V_5 ,
V_80 ) ;
if ( ! V_2 -> V_8 )
goto V_81;
V_75 = 0 ;
F_64 (rdev, mddev) {
V_73 = V_7 -> V_58 ;
if ( V_73 < 0 ||
V_73 >= V_15 -> V_5 )
continue;
V_74 = V_2 -> V_8 + V_73 ;
V_74 -> V_7 = V_7 ;
F_44 ( V_15 -> V_61 , V_7 -> V_31 ,
V_7 -> V_38 << 9 ) ;
if ( ! F_4 ( V_11 , & V_7 -> V_10 ) )
V_75 ++ ;
}
V_2 -> V_5 = V_15 -> V_5 ;
V_2 -> V_15 = V_15 ;
F_65 ( & V_2 -> V_17 ) ;
F_66 ( & V_2 -> V_18 ) ;
if ( ! V_75 ) {
F_37 ( L_20 ,
F_62 ( V_15 ) ) ;
goto V_81;
}
V_15 -> V_44 = V_2 -> V_5 - V_75 ;
V_2 -> V_24 = F_67 ( V_82 ,
sizeof( struct V_13 ) ) ;
if ( V_2 -> V_24 == NULL )
goto V_81;
V_15 -> V_19 = F_68 ( F_53 , V_15 ,
L_21 ) ;
if ( ! V_15 -> V_19 )
goto V_81;
F_18 ( L_22 ,
F_62 ( V_15 ) , V_2 -> V_5 - V_15 -> V_44 ,
V_15 -> V_5 ) ;
F_69 ( V_15 , F_58 ( V_15 , 0 , 0 ) ) ;
if ( F_52 ( V_15 ) )
goto V_81;
return 0 ;
V_81:
F_70 ( V_2 -> V_24 ) ;
F_71 ( V_2 -> V_8 ) ;
F_71 ( V_2 ) ;
V_15 -> V_16 = NULL ;
V_79:
return - V_83 ;
}
static void F_72 ( struct V_15 * V_15 , void * V_84 )
{
struct V_1 * V_2 = V_84 ;
F_70 ( V_2 -> V_24 ) ;
F_71 ( V_2 -> V_8 ) ;
F_71 ( V_2 ) ;
}
static int T_3 F_73 ( void )
{
return F_74 ( & V_85 ) ;
}
static void T_4 F_75 ( void )
{
F_76 ( & V_85 ) ;
}
