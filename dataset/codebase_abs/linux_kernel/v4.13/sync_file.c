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
F_6 ( & V_1 -> V_7 . V_8 ) ;
return V_1 ;
V_5:
F_7 ( V_1 ) ;
return NULL ;
}
static void F_8 ( struct V_9 * V_10 , struct V_11 * V_7 )
{
struct V_1 * V_1 ;
V_1 = F_9 ( V_7 , struct V_1 , V_7 ) ;
F_10 ( & V_1 -> V_6 ) ;
}
struct V_1 * F_11 ( struct V_9 * V_12 )
{
struct V_1 * V_1 ;
V_1 = F_1 () ;
if ( ! V_1 )
return NULL ;
V_1 -> V_12 = F_12 ( V_12 ) ;
return V_1 ;
}
static struct V_1 * F_13 ( int V_13 )
{
struct V_3 * V_3 = F_14 ( V_13 ) ;
if ( ! V_3 )
return NULL ;
if ( V_3 -> V_14 != & V_4 )
goto V_5;
return V_3 -> V_15 ;
V_5:
F_15 ( V_3 ) ;
return NULL ;
}
struct V_9 * F_16 ( int V_13 )
{
struct V_1 * V_1 ;
struct V_9 * V_12 ;
V_1 = F_13 ( V_13 ) ;
if ( ! V_1 )
return NULL ;
V_12 = F_12 ( V_1 -> V_12 ) ;
F_15 ( V_1 -> V_3 ) ;
return V_12 ;
}
char * F_17 ( struct V_1 * V_1 , char * V_16 , int V_17 )
{
if ( V_1 -> V_18 [ 0 ] ) {
F_18 ( V_16 , V_1 -> V_18 , V_17 ) ;
} else {
struct V_9 * V_12 = V_1 -> V_12 ;
snprintf ( V_16 , V_17 , L_2 ,
V_12 -> V_19 -> V_20 ( V_12 ) ,
V_12 -> V_19 -> V_21 ( V_12 ) ,
V_12 -> V_22 ,
V_12 -> V_23 ) ;
}
return V_16 ;
}
static int F_19 ( struct V_1 * V_1 ,
struct V_9 * * V_24 , int V_25 )
{
struct V_26 * V_27 ;
if ( V_25 == 1 ) {
V_1 -> V_12 = V_24 [ 0 ] ;
F_7 ( V_24 ) ;
} else {
V_27 = F_20 ( V_25 , V_24 ,
F_21 ( 1 ) ,
1 , false ) ;
if ( ! V_27 )
return - V_28 ;
V_1 -> V_12 = & V_27 -> V_29 ;
}
return 0 ;
}
static struct V_9 * * F_22 ( struct V_1 * V_1 ,
int * V_25 )
{
if ( F_23 ( V_1 -> V_12 ) ) {
struct V_26 * V_27 = F_24 ( V_1 -> V_12 ) ;
* V_25 = V_27 -> V_25 ;
return V_27 -> V_24 ;
}
* V_25 = 1 ;
return & V_1 -> V_12 ;
}
static void F_25 ( struct V_9 * * V_24 ,
int * V_30 , struct V_9 * V_12 )
{
V_24 [ * V_30 ] = V_12 ;
if ( ! F_26 ( V_12 ) ) {
F_12 ( V_12 ) ;
( * V_30 ) ++ ;
}
}
static struct V_1 * F_27 ( const char * V_31 , struct V_1 * V_32 ,
struct V_1 * V_33 )
{
struct V_1 * V_1 ;
struct V_9 * * V_24 , * * V_34 , * * V_35 , * * V_36 ;
int V_30 , V_37 , V_38 , V_25 , V_39 , V_40 ;
V_1 = F_1 () ;
if ( ! V_1 )
return NULL ;
V_35 = F_22 ( V_32 , & V_39 ) ;
V_36 = F_22 ( V_33 , & V_40 ) ;
if ( V_39 > V_41 - V_40 )
return NULL ;
V_25 = V_39 + V_40 ;
V_24 = F_28 ( V_25 , sizeof( * V_24 ) , V_2 ) ;
if ( ! V_24 )
goto V_5;
for ( V_30 = V_37 = V_38 = 0 ; V_37 < V_39 && V_38 < V_40 ; ) {
struct V_9 * V_42 = V_35 [ V_37 ] ;
struct V_9 * V_43 = V_36 [ V_38 ] ;
if ( V_42 -> V_22 < V_43 -> V_22 ) {
F_25 ( V_24 , & V_30 , V_42 ) ;
V_37 ++ ;
} else if ( V_42 -> V_22 > V_43 -> V_22 ) {
F_25 ( V_24 , & V_30 , V_43 ) ;
V_38 ++ ;
} else {
if ( V_42 -> V_23 - V_43 -> V_23 <= V_41 )
F_25 ( V_24 , & V_30 , V_42 ) ;
else
F_25 ( V_24 , & V_30 , V_43 ) ;
V_37 ++ ;
V_38 ++ ;
}
}
for (; V_37 < V_39 ; V_37 ++ )
F_25 ( V_24 , & V_30 , V_35 [ V_37 ] ) ;
for (; V_38 < V_40 ; V_38 ++ )
F_25 ( V_24 , & V_30 , V_36 [ V_38 ] ) ;
if ( V_30 == 0 )
V_24 [ V_30 ++ ] = F_12 ( V_35 [ 0 ] ) ;
if ( V_25 > V_30 ) {
V_34 = F_29 ( V_24 , V_30 * sizeof( * V_24 ) ,
V_2 ) ;
if ( ! V_34 )
goto V_5;
V_24 = V_34 ;
}
if ( F_19 ( V_1 , V_24 , V_30 ) < 0 ) {
F_7 ( V_24 ) ;
goto V_5;
}
F_18 ( V_1 -> V_18 , V_31 , sizeof( V_1 -> V_18 ) ) ;
return V_1 ;
V_5:
F_15 ( V_1 -> V_3 ) ;
return NULL ;
}
static int F_30 ( struct V_44 * V_44 , struct V_3 * V_3 )
{
struct V_1 * V_1 = V_3 -> V_15 ;
if ( F_31 ( V_45 , & V_1 -> V_46 ) )
F_32 ( V_1 -> V_12 , & V_1 -> V_7 ) ;
F_33 ( V_1 -> V_12 ) ;
F_7 ( V_1 ) ;
return 0 ;
}
static unsigned int F_34 ( struct V_3 * V_3 , T_1 * V_47 )
{
struct V_1 * V_1 = V_3 -> V_15 ;
F_35 ( V_3 , & V_1 -> V_6 , V_47 ) ;
if ( F_36 ( & V_1 -> V_7 . V_8 ) &&
! F_37 ( V_45 , & V_1 -> V_46 ) ) {
if ( F_38 ( V_1 -> V_12 , & V_1 -> V_7 ,
F_8 ) < 0 )
F_10 ( & V_1 -> V_6 ) ;
}
return F_26 ( V_1 -> V_12 ) ? V_48 : 0 ;
}
static long F_39 ( struct V_1 * V_1 ,
unsigned long V_49 )
{
int V_13 = F_40 ( V_50 ) ;
int V_5 ;
struct V_1 * V_51 , * V_52 ;
struct V_53 V_54 ;
if ( V_13 < 0 )
return V_13 ;
if ( F_41 ( & V_54 , ( void V_55 * ) V_49 , sizeof( V_54 ) ) ) {
V_5 = - V_56 ;
goto V_57;
}
if ( V_54 . V_46 || V_54 . V_58 ) {
V_5 = - V_59 ;
goto V_57;
}
V_51 = F_13 ( V_54 . V_60 ) ;
if ( ! V_51 ) {
V_5 = - V_61 ;
goto V_57;
}
V_54 . V_31 [ sizeof( V_54 . V_31 ) - 1 ] = '\0' ;
V_52 = F_27 ( V_54 . V_31 , V_1 , V_51 ) ;
if ( ! V_52 ) {
V_5 = - V_28 ;
goto V_62;
}
V_54 . V_12 = V_13 ;
if ( F_42 ( ( void V_55 * ) V_49 , & V_54 , sizeof( V_54 ) ) ) {
V_5 = - V_56 ;
goto V_63;
}
F_43 ( V_13 , V_52 -> V_3 ) ;
F_15 ( V_51 -> V_3 ) ;
return 0 ;
V_63:
F_15 ( V_52 -> V_3 ) ;
V_62:
F_15 ( V_51 -> V_3 ) ;
V_57:
F_44 ( V_13 ) ;
return V_5 ;
}
static void F_45 ( struct V_9 * V_12 ,
struct V_64 * V_65 )
{
F_18 ( V_65 -> V_66 , V_12 -> V_19 -> V_21 ( V_12 ) ,
sizeof( V_65 -> V_66 ) ) ;
F_18 ( V_65 -> V_67 , V_12 -> V_19 -> V_20 ( V_12 ) ,
sizeof( V_65 -> V_67 ) ) ;
V_65 -> V_68 = F_46 ( V_12 ) ;
while ( F_31 ( V_69 , & V_12 -> V_46 ) &&
! F_31 ( V_70 , & V_12 -> V_46 ) )
F_47 () ;
V_65 -> V_71 =
F_31 ( V_70 , & V_12 -> V_46 ) ?
F_48 ( V_12 -> V_72 ) :
F_49 ( 0 , 0 ) ;
}
static long F_50 ( struct V_1 * V_1 ,
unsigned long V_49 )
{
struct V_73 V_65 ;
struct V_64 * V_74 = NULL ;
struct V_9 * * V_24 ;
T_2 V_75 ;
int V_25 , V_76 , V_30 ;
if ( F_41 ( & V_65 , ( void V_55 * ) V_49 , sizeof( V_65 ) ) )
return - V_56 ;
if ( V_65 . V_46 || V_65 . V_58 )
return - V_59 ;
V_24 = F_22 ( V_1 , & V_25 ) ;
if ( ! V_65 . V_25 )
goto V_77;
if ( V_65 . V_25 < V_25 )
return - V_59 ;
V_75 = V_25 * sizeof( * V_74 ) ;
V_74 = F_2 ( V_75 , V_2 ) ;
if ( ! V_74 )
return - V_28 ;
for ( V_30 = 0 ; V_30 < V_25 ; V_30 ++ )
F_45 ( V_24 [ V_30 ] , & V_74 [ V_30 ] ) ;
if ( F_42 ( F_51 ( V_65 . V_64 ) , V_74 ,
V_75 ) ) {
V_76 = - V_56 ;
goto V_78;
}
V_77:
F_17 ( V_1 , V_65 . V_31 , sizeof( V_65 . V_31 ) ) ;
V_65 . V_68 = F_26 ( V_1 -> V_12 ) ;
V_65 . V_25 = V_25 ;
if ( F_42 ( ( void V_55 * ) V_49 , & V_65 , sizeof( V_65 ) ) )
V_76 = - V_56 ;
else
V_76 = 0 ;
V_78:
F_7 ( V_74 ) ;
return V_76 ;
}
static long F_52 ( struct V_3 * V_3 , unsigned int V_79 ,
unsigned long V_49 )
{
struct V_1 * V_1 = V_3 -> V_15 ;
switch ( V_79 ) {
case V_80 :
return F_39 ( V_1 , V_49 ) ;
case V_81 :
return F_50 ( V_1 , V_49 ) ;
default:
return - V_82 ;
}
}
