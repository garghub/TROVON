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
F_28 ( & V_14 -> V_21 , V_35 -> V_7 -> V_31 ) ;
V_14 -> V_21 . V_27 |= V_39 ;
V_14 -> V_21 . V_40 = F_16 ;
V_14 -> V_21 . V_25 = V_14 ;
F_29 ( V_15 , & V_14 -> V_21 ) ;
F_30 ( V_15 , & V_14 -> V_21 ) ;
F_31 ( & V_14 -> V_21 ) ;
return true ;
}
static void F_32 ( struct V_41 * V_42 , struct V_15 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
int V_3 ;
F_33 ( V_42 , L_3 , V_2 -> V_5 ,
V_2 -> V_5 - V_15 -> V_43 ) ;
F_2 () ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
struct V_6 * V_7 = F_3 ( V_2 -> V_8 [ V_3 ] . V_7 ) ;
F_33 ( V_42 , L_4 , V_7 && F_4 ( V_9 , & V_7 -> V_10 ) ? L_5 : L_6 ) ;
}
F_6 () ;
F_33 ( V_42 , L_7 ) ;
}
static int F_34 ( struct V_15 * V_15 , int V_44 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
int V_3 , V_45 = 0 ;
F_2 () ;
for ( V_3 = 0 ; V_3 < V_15 -> V_5 ; V_3 ++ ) {
struct V_6 * V_7 = F_3 ( V_2 -> V_8 [ V_3 ] . V_7 ) ;
if ( V_7 && ! F_4 ( V_11 , & V_7 -> V_10 ) ) {
struct V_46 * V_47 = F_35 ( V_7 -> V_31 ) ;
V_45 |= F_36 ( V_47 -> V_48 , V_44 ) ;
break;
}
}
F_6 () ;
return V_45 ;
}
static void F_37 ( struct V_15 * V_15 , struct V_6 * V_7 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
char V_29 [ V_30 ] ;
if ( V_2 -> V_5 - V_15 -> V_43 <= 1 ) {
F_38 ( L_8 ) ;
return;
}
if ( F_39 ( V_9 , & V_7 -> V_10 ) ) {
unsigned long V_10 ;
F_9 ( & V_2 -> V_17 , V_10 ) ;
V_15 -> V_43 ++ ;
F_11 ( & V_2 -> V_17 , V_10 ) ;
}
F_40 ( V_11 , & V_7 -> V_10 ) ;
F_40 ( V_49 , & V_15 -> V_50 ) ;
F_41 ( L_9
L_10 ,
F_19 ( V_7 -> V_31 , V_29 ) ,
V_2 -> V_5 - V_15 -> V_43 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_34 * V_51 ;
F_43 ( L_11 ) ;
if ( ! V_2 ) {
F_43 ( L_12 ) ;
return;
}
F_43 ( L_13 , V_2 -> V_5 - V_2 -> V_15 -> V_43 ,
V_2 -> V_5 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
char V_29 [ V_30 ] ;
V_51 = V_2 -> V_8 + V_3 ;
if ( V_51 -> V_7 )
F_43 ( L_14 ,
V_3 , ! F_4 ( V_11 , & V_51 -> V_7 -> V_10 ) ,
F_19 ( V_51 -> V_7 -> V_31 , V_29 ) ) ;
}
}
static int F_44 ( struct V_15 * V_15 , struct V_6 * V_7 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_46 * V_47 ;
int V_52 = - V_53 ;
int V_26 ;
struct V_34 * V_54 ;
int V_55 = 0 ;
int V_56 = V_15 -> V_5 - 1 ;
if ( V_7 -> V_57 >= 0 )
V_55 = V_56 = V_7 -> V_57 ;
F_42 ( V_2 ) ;
for ( V_26 = V_55 ; V_26 <= V_56 ; V_26 ++ )
if ( ( V_54 = V_2 -> V_8 + V_26 ) -> V_7 == NULL ) {
V_47 = V_7 -> V_31 -> V_58 -> V_59 ;
F_45 ( V_15 -> V_60 , V_7 -> V_31 ,
V_7 -> V_38 << 9 ) ;
V_52 = F_46 ( V_7 , V_15 ) ;
if ( V_52 )
break;
F_47 ( & V_2 -> V_17 ) ;
V_15 -> V_43 -- ;
V_7 -> V_57 = V_26 ;
F_40 ( V_9 , & V_7 -> V_10 ) ;
F_48 ( & V_2 -> V_17 ) ;
F_49 ( V_54 -> V_7 , V_7 ) ;
V_52 = 0 ;
break;
}
F_42 ( V_2 ) ;
return V_52 ;
}
static int F_50 ( struct V_15 * V_15 , struct V_6 * V_7 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
int V_52 = 0 ;
int V_61 = V_7 -> V_57 ;
struct V_34 * V_54 = V_2 -> V_8 + V_61 ;
F_42 ( V_2 ) ;
if ( V_7 == V_54 -> V_7 ) {
if ( F_4 ( V_9 , & V_7 -> V_10 ) ||
F_51 ( & V_7 -> V_12 ) ) {
F_38 ( L_15 , V_61 ) ;
V_52 = - V_62 ;
goto abort;
}
V_54 -> V_7 = NULL ;
if ( ! F_4 ( V_63 , & V_7 -> V_10 ) ) {
F_52 () ;
if ( F_51 ( & V_7 -> V_12 ) ) {
V_52 = - V_62 ;
V_54 -> V_7 = V_7 ;
goto abort;
}
}
V_52 = F_53 ( V_15 ) ;
}
abort:
F_42 ( V_2 ) ;
return V_52 ;
}
static void F_54 ( struct V_64 * V_19 )
{
struct V_15 * V_15 = V_19 -> V_15 ;
struct V_13 * V_14 ;
struct V_21 * V_21 ;
unsigned long V_10 ;
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_65 * V_66 = & V_2 -> V_18 ;
F_55 ( V_15 ) ;
for (; ; ) {
char V_29 [ V_30 ] ;
F_9 ( & V_2 -> V_17 , V_10 ) ;
if ( F_56 ( V_66 ) )
break;
V_14 = F_57 ( V_66 -> V_67 , struct V_13 , V_18 ) ;
F_58 ( V_66 -> V_67 ) ;
F_11 ( & V_2 -> V_17 , V_10 ) ;
V_21 = & V_14 -> V_21 ;
V_21 -> V_32 . V_33 = V_14 -> V_22 -> V_32 . V_33 ;
if ( ( V_14 -> V_26 = F_1 ( V_2 ) ) < 0 ) {
F_41 ( L_16 ,
F_59 ( V_21 , V_29 ) ,
( unsigned long long ) V_21 -> V_32 . V_33 ) ;
F_13 ( V_14 , V_68 ) ;
} else {
F_41 ( L_17 ,
F_59 ( V_21 , V_29 ) ,
( unsigned long long ) V_21 -> V_32 . V_33 ) ;
* V_21 = * ( V_14 -> V_22 ) ;
V_21 -> V_32 . V_33 +=
V_2 -> V_8 [ V_14 -> V_26 ] . V_7 -> V_38 ;
F_28 ( V_21 , V_2 -> V_8 [ V_14 -> V_26 ] . V_7 -> V_31 ) ;
V_21 -> V_27 |= V_39 ;
V_21 -> V_40 = F_16 ;
V_21 -> V_25 = V_14 ;
F_31 ( V_21 ) ;
}
}
F_11 ( & V_2 -> V_17 , V_10 ) ;
}
static T_2 F_60 ( struct V_15 * V_15 , T_2 V_69 , int V_5 )
{
F_61 ( V_69 || V_5 ,
L_18 , V_70 ) ;
return V_15 -> V_71 ;
}
static int F_62 ( struct V_15 * V_15 )
{
struct V_1 * V_2 ;
int V_72 ;
struct V_34 * V_73 ;
struct V_6 * V_7 ;
int V_74 ;
if ( F_63 ( V_15 ) )
return - V_75 ;
if ( V_15 -> V_76 != V_77 ) {
F_38 ( L_19 ,
F_64 ( V_15 ) , V_15 -> V_76 ) ;
goto V_78;
}
V_2 = F_65 ( sizeof( struct V_1 ) , V_79 ) ;
V_15 -> V_16 = V_2 ;
if ( ! V_2 )
goto V_78;
V_2 -> V_8 = F_65 ( sizeof( struct V_34 ) * V_15 -> V_5 ,
V_79 ) ;
if ( ! V_2 -> V_8 )
goto V_80;
V_74 = 0 ;
F_66 (rdev, mddev) {
V_72 = V_7 -> V_57 ;
if ( V_72 < 0 ||
V_72 >= V_15 -> V_5 )
continue;
V_73 = V_2 -> V_8 + V_72 ;
V_73 -> V_7 = V_7 ;
F_45 ( V_15 -> V_60 , V_7 -> V_31 ,
V_7 -> V_38 << 9 ) ;
if ( ! F_4 ( V_11 , & V_7 -> V_10 ) )
V_74 ++ ;
}
V_2 -> V_5 = V_15 -> V_5 ;
V_2 -> V_15 = V_15 ;
F_67 ( & V_2 -> V_17 ) ;
F_68 ( & V_2 -> V_18 ) ;
if ( ! V_74 ) {
F_38 ( L_20 ,
F_64 ( V_15 ) ) ;
goto V_80;
}
V_15 -> V_43 = V_2 -> V_5 - V_74 ;
V_2 -> V_24 = F_69 ( V_81 ,
sizeof( struct V_13 ) ) ;
if ( V_2 -> V_24 == NULL )
goto V_80;
V_15 -> V_19 = F_70 ( F_54 , V_15 ,
L_21 ) ;
if ( ! V_15 -> V_19 )
goto V_80;
F_18 ( L_22 ,
F_64 ( V_15 ) , V_2 -> V_5 - V_15 -> V_43 ,
V_15 -> V_5 ) ;
F_71 ( V_15 , F_60 ( V_15 , 0 , 0 ) ) ;
if ( F_53 ( V_15 ) )
goto V_80;
return 0 ;
V_80:
F_72 ( V_2 -> V_24 ) ;
F_73 ( V_2 -> V_8 ) ;
F_73 ( V_2 ) ;
V_15 -> V_16 = NULL ;
V_78:
return - V_82 ;
}
static void F_74 ( struct V_15 * V_15 , void * V_83 )
{
struct V_1 * V_2 = V_83 ;
F_72 ( V_2 -> V_24 ) ;
F_73 ( V_2 -> V_8 ) ;
F_73 ( V_2 ) ;
}
static int T_3 F_75 ( void )
{
return F_76 ( & V_84 ) ;
}
static void T_4 F_77 ( void )
{
F_78 ( & V_84 ) ;
}
