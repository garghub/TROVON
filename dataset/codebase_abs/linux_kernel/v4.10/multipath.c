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
static void F_13 ( struct V_13 * V_14 , int V_20 )
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
static void F_21 ( struct V_15 * V_15 , struct V_21 * V_21 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_13 * V_14 ;
struct V_34 * V_35 ;
if ( F_22 ( V_21 -> V_27 & V_36 ) ) {
F_23 ( V_15 , V_21 ) ;
return;
}
V_14 = F_24 ( V_2 -> V_24 , V_37 ) ;
V_14 -> V_22 = V_21 ;
V_14 -> V_15 = V_15 ;
V_14 -> V_26 = F_1 ( V_2 ) ;
if ( V_14 -> V_26 < 0 ) {
F_25 ( V_21 ) ;
F_15 ( V_14 , V_2 -> V_24 ) ;
return;
}
V_35 = V_2 -> V_8 + V_14 -> V_26 ;
F_26 ( & V_14 -> V_21 , NULL , 0 ) ;
F_27 ( & V_14 -> V_21 , V_21 ) ;
V_14 -> V_21 . V_32 . V_33 += V_35 -> V_7 -> V_38 ;
V_14 -> V_21 . V_39 = V_35 -> V_7 -> V_31 ;
V_14 -> V_21 . V_27 |= V_40 ;
V_14 -> V_21 . V_41 = F_16 ;
V_14 -> V_21 . V_25 = V_14 ;
F_28 ( & V_14 -> V_21 ) ;
return;
}
static void F_29 ( struct V_42 * V_43 , struct V_15 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
int V_3 ;
F_30 ( V_43 , L_3 , V_2 -> V_5 ,
V_2 -> V_5 - V_15 -> V_44 ) ;
F_2 () ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
struct V_6 * V_7 = F_3 ( V_2 -> V_8 [ V_3 ] . V_7 ) ;
F_30 ( V_43 , L_4 , V_7 && F_4 ( V_9 , & V_7 -> V_10 ) ? L_5 : L_6 ) ;
}
F_6 () ;
F_30 ( V_43 , L_7 ) ;
}
static int F_31 ( struct V_15 * V_15 , int V_45 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
int V_3 , V_46 = 0 ;
F_2 () ;
for ( V_3 = 0 ; V_3 < V_15 -> V_5 ; V_3 ++ ) {
struct V_6 * V_7 = F_3 ( V_2 -> V_8 [ V_3 ] . V_7 ) ;
if ( V_7 && ! F_4 ( V_11 , & V_7 -> V_10 ) ) {
struct V_47 * V_48 = F_32 ( V_7 -> V_31 ) ;
V_46 |= F_33 ( & V_48 -> V_49 , V_45 ) ;
break;
}
}
F_6 () ;
return V_46 ;
}
static void F_34 ( struct V_15 * V_15 , struct V_6 * V_7 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
char V_29 [ V_30 ] ;
if ( V_2 -> V_5 - V_15 -> V_44 <= 1 ) {
F_35 ( L_8 ) ;
return;
}
if ( F_36 ( V_9 , & V_7 -> V_10 ) ) {
unsigned long V_10 ;
F_9 ( & V_2 -> V_17 , V_10 ) ;
V_15 -> V_44 ++ ;
F_11 ( & V_2 -> V_17 , V_10 ) ;
}
F_37 ( V_11 , & V_7 -> V_10 ) ;
F_37 ( V_50 , & V_15 -> V_51 ) ;
F_38 ( L_9
L_10 ,
F_19 ( V_7 -> V_31 , V_29 ) ,
V_2 -> V_5 - V_15 -> V_44 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_34 * V_52 ;
F_40 ( L_11 ) ;
if ( ! V_2 ) {
F_40 ( L_12 ) ;
return;
}
F_40 ( L_13 , V_2 -> V_5 - V_2 -> V_15 -> V_44 ,
V_2 -> V_5 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
char V_29 [ V_30 ] ;
V_52 = V_2 -> V_8 + V_3 ;
if ( V_52 -> V_7 )
F_40 ( L_14 ,
V_3 , ! F_4 ( V_11 , & V_52 -> V_7 -> V_10 ) ,
F_19 ( V_52 -> V_7 -> V_31 , V_29 ) ) ;
}
}
static int F_41 ( struct V_15 * V_15 , struct V_6 * V_7 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_47 * V_48 ;
int V_20 = - V_53 ;
int V_26 ;
struct V_34 * V_54 ;
int V_55 = 0 ;
int V_56 = V_15 -> V_5 - 1 ;
if ( V_7 -> V_57 >= 0 )
V_55 = V_56 = V_7 -> V_57 ;
F_39 ( V_2 ) ;
for ( V_26 = V_55 ; V_26 <= V_56 ; V_26 ++ )
if ( ( V_54 = V_2 -> V_8 + V_26 ) -> V_7 == NULL ) {
V_48 = V_7 -> V_31 -> V_58 -> V_59 ;
F_42 ( V_15 -> V_60 , V_7 -> V_31 ,
V_7 -> V_38 << 9 ) ;
V_20 = F_43 ( V_7 , V_15 ) ;
if ( V_20 )
break;
F_44 ( & V_2 -> V_17 ) ;
V_15 -> V_44 -- ;
V_7 -> V_57 = V_26 ;
F_37 ( V_9 , & V_7 -> V_10 ) ;
F_45 ( & V_2 -> V_17 ) ;
F_46 ( V_54 -> V_7 , V_7 ) ;
V_20 = 0 ;
break;
}
F_39 ( V_2 ) ;
return V_20 ;
}
static int F_47 ( struct V_15 * V_15 , struct V_6 * V_7 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
int V_20 = 0 ;
int V_61 = V_7 -> V_57 ;
struct V_34 * V_54 = V_2 -> V_8 + V_61 ;
F_39 ( V_2 ) ;
if ( V_7 == V_54 -> V_7 ) {
if ( F_4 ( V_9 , & V_7 -> V_10 ) ||
F_48 ( & V_7 -> V_12 ) ) {
F_35 ( L_15 , V_61 ) ;
V_20 = - V_62 ;
goto abort;
}
V_54 -> V_7 = NULL ;
if ( ! F_4 ( V_63 , & V_7 -> V_10 ) ) {
F_49 () ;
if ( F_48 ( & V_7 -> V_12 ) ) {
V_20 = - V_62 ;
V_54 -> V_7 = V_7 ;
goto abort;
}
}
V_20 = F_50 ( V_15 ) ;
}
abort:
F_39 ( V_2 ) ;
return V_20 ;
}
static void F_51 ( struct V_64 * V_19 )
{
struct V_15 * V_15 = V_19 -> V_15 ;
struct V_13 * V_14 ;
struct V_21 * V_21 ;
unsigned long V_10 ;
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_65 * V_66 = & V_2 -> V_18 ;
F_52 ( V_15 ) ;
for (; ; ) {
char V_29 [ V_30 ] ;
F_9 ( & V_2 -> V_17 , V_10 ) ;
if ( F_53 ( V_66 ) )
break;
V_14 = F_54 ( V_66 -> V_67 , struct V_13 , V_18 ) ;
F_55 ( V_66 -> V_67 ) ;
F_11 ( & V_2 -> V_17 , V_10 ) ;
V_21 = & V_14 -> V_21 ;
V_21 -> V_32 . V_33 = V_14 -> V_22 -> V_32 . V_33 ;
if ( ( V_14 -> V_26 = F_1 ( V_2 ) ) < 0 ) {
F_38 ( L_16 ,
F_19 ( V_21 -> V_39 , V_29 ) ,
( unsigned long long ) V_21 -> V_32 . V_33 ) ;
F_13 ( V_14 , - V_68 ) ;
} else {
F_38 ( L_17 ,
F_19 ( V_21 -> V_39 , V_29 ) ,
( unsigned long long ) V_21 -> V_32 . V_33 ) ;
* V_21 = * ( V_14 -> V_22 ) ;
V_21 -> V_32 . V_33 +=
V_2 -> V_8 [ V_14 -> V_26 ] . V_7 -> V_38 ;
V_21 -> V_39 = V_2 -> V_8 [ V_14 -> V_26 ] . V_7 -> V_31 ;
V_21 -> V_27 |= V_40 ;
V_21 -> V_41 = F_16 ;
V_21 -> V_25 = V_14 ;
F_28 ( V_21 ) ;
}
}
F_11 ( & V_2 -> V_17 , V_10 ) ;
}
static T_1 F_56 ( struct V_15 * V_15 , T_1 V_69 , int V_5 )
{
F_57 ( V_69 || V_5 ,
L_18 , V_70 ) ;
return V_15 -> V_71 ;
}
static int F_58 ( struct V_15 * V_15 )
{
struct V_1 * V_2 ;
int V_72 ;
struct V_34 * V_73 ;
struct V_6 * V_7 ;
int V_74 ;
if ( F_59 ( V_15 ) )
return - V_75 ;
if ( V_15 -> V_76 != V_77 ) {
F_35 ( L_19 ,
F_60 ( V_15 ) , V_15 -> V_76 ) ;
goto V_78;
}
V_2 = F_61 ( sizeof( struct V_1 ) , V_79 ) ;
V_15 -> V_16 = V_2 ;
if ( ! V_2 )
goto V_78;
V_2 -> V_8 = F_61 ( sizeof( struct V_34 ) * V_15 -> V_5 ,
V_79 ) ;
if ( ! V_2 -> V_8 )
goto V_80;
V_74 = 0 ;
F_62 (rdev, mddev) {
V_72 = V_7 -> V_57 ;
if ( V_72 < 0 ||
V_72 >= V_15 -> V_5 )
continue;
V_73 = V_2 -> V_8 + V_72 ;
V_73 -> V_7 = V_7 ;
F_42 ( V_15 -> V_60 , V_7 -> V_31 ,
V_7 -> V_38 << 9 ) ;
if ( ! F_4 ( V_11 , & V_7 -> V_10 ) )
V_74 ++ ;
}
V_2 -> V_5 = V_15 -> V_5 ;
V_2 -> V_15 = V_15 ;
F_63 ( & V_2 -> V_17 ) ;
F_64 ( & V_2 -> V_18 ) ;
if ( ! V_74 ) {
F_35 ( L_20 ,
F_60 ( V_15 ) ) ;
goto V_80;
}
V_15 -> V_44 = V_2 -> V_5 - V_74 ;
V_2 -> V_24 = F_65 ( V_81 ,
sizeof( struct V_13 ) ) ;
if ( V_2 -> V_24 == NULL )
goto V_80;
V_15 -> V_19 = F_66 ( F_51 , V_15 ,
L_21 ) ;
if ( ! V_15 -> V_19 )
goto V_80;
F_18 ( L_22 ,
F_60 ( V_15 ) , V_2 -> V_5 - V_15 -> V_44 ,
V_15 -> V_5 ) ;
F_67 ( V_15 , F_56 ( V_15 , 0 , 0 ) ) ;
if ( F_50 ( V_15 ) )
goto V_80;
return 0 ;
V_80:
F_68 ( V_2 -> V_24 ) ;
F_69 ( V_2 -> V_8 ) ;
F_69 ( V_2 ) ;
V_15 -> V_16 = NULL ;
V_78:
return - V_68 ;
}
static void F_70 ( struct V_15 * V_15 , void * V_82 )
{
struct V_1 * V_2 = V_82 ;
F_68 ( V_2 -> V_24 ) ;
F_69 ( V_2 -> V_8 ) ;
F_69 ( V_2 ) ;
}
static int T_2 F_71 ( void )
{
return F_72 ( & V_83 ) ;
}
static void T_3 F_73 ( void )
{
F_74 ( & V_83 ) ;
}
