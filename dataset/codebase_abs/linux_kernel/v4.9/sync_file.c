static struct V_1 * F_1 ( void )
{
struct V_1 * V_1 ;
V_1 = F_2 ( sizeof( * V_1 ) , V_2 ) ;
if ( ! V_1 )
return NULL ;
V_1 -> V_3 = F_3 ( L_1 , & V_4 ,
V_1 , 0 ) ;
if ( F_4 ( V_1 -> V_3 ) )
goto V_5;
F_5 ( & V_1 -> V_6 ) ;
F_6 ( & V_1 -> V_7 ) ;
F_7 ( & V_1 -> V_8 . V_9 ) ;
return V_1 ;
V_5:
F_8 ( V_1 ) ;
return NULL ;
}
static void F_9 ( struct V_10 * V_11 , struct V_12 * V_8 )
{
struct V_1 * V_1 ;
V_1 = F_10 ( V_8 , struct V_1 , V_8 ) ;
F_11 ( & V_1 -> V_7 ) ;
}
struct V_1 * F_12 ( struct V_10 * V_10 )
{
struct V_1 * V_1 ;
V_1 = F_1 () ;
if ( ! V_1 )
return NULL ;
V_1 -> V_10 = V_10 ;
snprintf ( V_1 -> V_13 , sizeof( V_1 -> V_13 ) , L_2 ,
V_10 -> V_14 -> V_15 ( V_10 ) ,
V_10 -> V_14 -> V_16 ( V_10 ) , V_10 -> V_17 ,
V_10 -> V_18 ) ;
return V_1 ;
}
static struct V_1 * F_13 ( int V_19 )
{
struct V_3 * V_3 = F_14 ( V_19 ) ;
if ( ! V_3 )
return NULL ;
if ( V_3 -> V_20 != & V_4 )
goto V_5;
return V_3 -> V_21 ;
V_5:
F_15 ( V_3 ) ;
return NULL ;
}
struct V_10 * F_16 ( int V_19 )
{
struct V_1 * V_1 ;
struct V_10 * V_10 ;
V_1 = F_13 ( V_19 ) ;
if ( ! V_1 )
return NULL ;
V_10 = F_17 ( V_1 -> V_10 ) ;
F_15 ( V_1 -> V_3 ) ;
return V_10 ;
}
static int F_18 ( struct V_1 * V_1 ,
struct V_10 * * V_22 , int V_23 )
{
struct V_24 * V_25 ;
if ( V_23 == 1 ) {
V_1 -> V_10 = V_22 [ 0 ] ;
F_8 ( V_22 ) ;
} else {
V_25 = F_19 ( V_23 , V_22 ,
F_20 ( 1 ) , 1 , false ) ;
if ( ! V_25 )
return - V_26 ;
V_1 -> V_10 = & V_25 -> V_27 ;
}
return 0 ;
}
static struct V_10 * * F_21 ( struct V_1 * V_1 , int * V_23 )
{
if ( F_22 ( V_1 -> V_10 ) ) {
struct V_24 * V_25 = F_23 ( V_1 -> V_10 ) ;
* V_23 = V_25 -> V_23 ;
return V_25 -> V_22 ;
}
* V_23 = 1 ;
return & V_1 -> V_10 ;
}
static void F_24 ( struct V_10 * * V_22 , int * V_28 , struct V_10 * V_10 )
{
V_22 [ * V_28 ] = V_10 ;
if ( ! F_25 ( V_10 ) ) {
F_17 ( V_10 ) ;
( * V_28 ) ++ ;
}
}
static struct V_1 * F_26 ( const char * V_13 , struct V_1 * V_29 ,
struct V_1 * V_30 )
{
struct V_1 * V_1 ;
struct V_10 * * V_22 , * * V_31 , * * V_32 , * * V_33 ;
int V_28 , V_34 , V_35 , V_23 , V_36 , V_37 ;
V_1 = F_1 () ;
if ( ! V_1 )
return NULL ;
V_32 = F_21 ( V_29 , & V_36 ) ;
V_33 = F_21 ( V_30 , & V_37 ) ;
if ( V_36 > V_38 - V_37 )
return NULL ;
V_23 = V_36 + V_37 ;
V_22 = F_27 ( V_23 , sizeof( * V_22 ) , V_2 ) ;
if ( ! V_22 )
goto V_5;
for ( V_28 = V_34 = V_35 = 0 ; V_34 < V_36 && V_35 < V_37 ; ) {
struct V_10 * V_39 = V_32 [ V_34 ] ;
struct V_10 * V_40 = V_33 [ V_35 ] ;
if ( V_39 -> V_17 < V_40 -> V_17 ) {
F_24 ( V_22 , & V_28 , V_39 ) ;
V_34 ++ ;
} else if ( V_39 -> V_17 > V_40 -> V_17 ) {
F_24 ( V_22 , & V_28 , V_40 ) ;
V_35 ++ ;
} else {
if ( V_39 -> V_18 - V_40 -> V_18 <= V_38 )
F_24 ( V_22 , & V_28 , V_39 ) ;
else
F_24 ( V_22 , & V_28 , V_40 ) ;
V_34 ++ ;
V_35 ++ ;
}
}
for (; V_34 < V_36 ; V_34 ++ )
F_24 ( V_22 , & V_28 , V_32 [ V_34 ] ) ;
for (; V_35 < V_37 ; V_35 ++ )
F_24 ( V_22 , & V_28 , V_33 [ V_35 ] ) ;
if ( V_28 == 0 )
V_22 [ V_28 ++ ] = F_17 ( V_32 [ 0 ] ) ;
if ( V_23 > V_28 ) {
V_31 = F_28 ( V_22 , V_28 * sizeof( * V_22 ) ,
V_2 ) ;
if ( ! V_31 )
goto V_5;
V_22 = V_31 ;
}
if ( F_18 ( V_1 , V_22 , V_28 ) < 0 ) {
F_8 ( V_22 ) ;
goto V_5;
}
F_29 ( V_1 -> V_13 , V_13 , sizeof( V_1 -> V_13 ) ) ;
return V_1 ;
V_5:
F_15 ( V_1 -> V_3 ) ;
return NULL ;
}
static void F_30 ( struct V_6 * V_6 )
{
struct V_1 * V_1 = F_10 ( V_6 , struct V_1 ,
V_6 ) ;
if ( F_31 ( V_41 , & V_1 -> V_10 -> V_42 ) )
F_32 ( V_1 -> V_10 , & V_1 -> V_8 ) ;
F_33 ( V_1 -> V_10 ) ;
F_8 ( V_1 ) ;
}
static int F_34 ( struct V_43 * V_43 , struct V_3 * V_3 )
{
struct V_1 * V_1 = V_3 -> V_21 ;
F_35 ( & V_1 -> V_6 , F_30 ) ;
return 0 ;
}
static unsigned int F_36 ( struct V_3 * V_3 , T_1 * V_44 )
{
struct V_1 * V_1 = V_3 -> V_21 ;
F_37 ( V_3 , & V_1 -> V_7 , V_44 ) ;
if ( ! F_38 ( V_44 ) &&
! F_39 ( V_41 , & V_1 -> V_10 -> V_42 ) ) {
if ( F_40 ( V_1 -> V_10 , & V_1 -> V_8 ,
F_9 ) < 0 )
F_11 ( & V_1 -> V_7 ) ;
}
return F_25 ( V_1 -> V_10 ) ? V_45 : 0 ;
}
static long F_41 ( struct V_1 * V_1 ,
unsigned long V_46 )
{
int V_19 = F_42 ( V_47 ) ;
int V_5 ;
struct V_1 * V_48 , * V_49 ;
struct V_50 V_51 ;
if ( V_19 < 0 )
return V_19 ;
if ( F_43 ( & V_51 , ( void V_52 * ) V_46 , sizeof( V_51 ) ) ) {
V_5 = - V_53 ;
goto V_54;
}
if ( V_51 . V_42 || V_51 . V_55 ) {
V_5 = - V_56 ;
goto V_54;
}
V_48 = F_13 ( V_51 . V_57 ) ;
if ( ! V_48 ) {
V_5 = - V_58 ;
goto V_54;
}
V_51 . V_13 [ sizeof( V_51 . V_13 ) - 1 ] = '\0' ;
V_49 = F_26 ( V_51 . V_13 , V_1 , V_48 ) ;
if ( ! V_49 ) {
V_5 = - V_26 ;
goto V_59;
}
V_51 . V_10 = V_19 ;
if ( F_44 ( ( void V_52 * ) V_46 , & V_51 , sizeof( V_51 ) ) ) {
V_5 = - V_53 ;
goto V_60;
}
F_45 ( V_19 , V_49 -> V_3 ) ;
F_15 ( V_48 -> V_3 ) ;
return 0 ;
V_60:
F_15 ( V_49 -> V_3 ) ;
V_59:
F_15 ( V_48 -> V_3 ) ;
V_54:
F_46 ( V_19 ) ;
return V_5 ;
}
static void F_47 ( struct V_10 * V_10 ,
struct V_61 * V_62 )
{
F_29 ( V_62 -> V_63 , V_10 -> V_14 -> V_16 ( V_10 ) ,
sizeof( V_62 -> V_63 ) ) ;
F_29 ( V_62 -> V_64 , V_10 -> V_14 -> V_15 ( V_10 ) ,
sizeof( V_62 -> V_64 ) ) ;
if ( F_25 ( V_10 ) )
V_62 -> V_65 = V_10 -> V_65 >= 0 ? 1 : V_10 -> V_65 ;
else
V_62 -> V_65 = 0 ;
V_62 -> V_66 = F_48 ( V_10 -> V_67 ) ;
}
static long F_49 ( struct V_1 * V_1 ,
unsigned long V_46 )
{
struct V_68 V_62 ;
struct V_61 * V_69 = NULL ;
struct V_10 * * V_22 ;
T_2 V_70 ;
int V_23 , V_71 , V_28 ;
if ( F_43 ( & V_62 , ( void V_52 * ) V_46 , sizeof( V_62 ) ) )
return - V_53 ;
if ( V_62 . V_42 || V_62 . V_55 )
return - V_56 ;
V_22 = F_21 ( V_1 , & V_23 ) ;
if ( ! V_62 . V_23 )
goto V_72;
if ( V_62 . V_23 < V_23 )
return - V_56 ;
V_70 = V_23 * sizeof( * V_69 ) ;
V_69 = F_2 ( V_70 , V_2 ) ;
if ( ! V_69 )
return - V_26 ;
for ( V_28 = 0 ; V_28 < V_23 ; V_28 ++ )
F_47 ( V_22 [ V_28 ] , & V_69 [ V_28 ] ) ;
if ( F_44 ( F_50 ( V_62 . V_61 ) , V_69 ,
V_70 ) ) {
V_71 = - V_53 ;
goto V_73;
}
V_72:
F_29 ( V_62 . V_13 , V_1 -> V_13 , sizeof( V_62 . V_13 ) ) ;
V_62 . V_65 = F_25 ( V_1 -> V_10 ) ;
V_62 . V_23 = V_23 ;
if ( F_44 ( ( void V_52 * ) V_46 , & V_62 , sizeof( V_62 ) ) )
V_71 = - V_53 ;
else
V_71 = 0 ;
V_73:
F_8 ( V_69 ) ;
return V_71 ;
}
static long F_51 ( struct V_3 * V_3 , unsigned int V_74 ,
unsigned long V_46 )
{
struct V_1 * V_1 = V_3 -> V_21 ;
switch ( V_74 ) {
case V_75 :
return F_41 ( V_1 , V_46 ) ;
case V_76 :
return F_49 ( V_1 , V_46 ) ;
default:
return - V_77 ;
}
}
