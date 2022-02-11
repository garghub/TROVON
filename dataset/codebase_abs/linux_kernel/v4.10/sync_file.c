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
struct V_1 * F_12 ( struct V_10 * V_13 )
{
struct V_1 * V_1 ;
V_1 = F_1 () ;
if ( ! V_1 )
return NULL ;
V_1 -> V_13 = F_13 ( V_13 ) ;
snprintf ( V_1 -> V_14 , sizeof( V_1 -> V_14 ) , L_2 ,
V_13 -> V_15 -> V_16 ( V_13 ) ,
V_13 -> V_15 -> V_17 ( V_13 ) , V_13 -> V_18 ,
V_13 -> V_19 ) ;
return V_1 ;
}
static struct V_1 * F_14 ( int V_20 )
{
struct V_3 * V_3 = F_15 ( V_20 ) ;
if ( ! V_3 )
return NULL ;
if ( V_3 -> V_21 != & V_4 )
goto V_5;
return V_3 -> V_22 ;
V_5:
F_16 ( V_3 ) ;
return NULL ;
}
struct V_10 * F_17 ( int V_20 )
{
struct V_1 * V_1 ;
struct V_10 * V_13 ;
V_1 = F_14 ( V_20 ) ;
if ( ! V_1 )
return NULL ;
V_13 = F_13 ( V_1 -> V_13 ) ;
F_16 ( V_1 -> V_3 ) ;
return V_13 ;
}
static int F_18 ( struct V_1 * V_1 ,
struct V_10 * * V_23 , int V_24 )
{
struct V_25 * V_26 ;
if ( V_24 == 1 ) {
V_1 -> V_13 = V_23 [ 0 ] ;
F_8 ( V_23 ) ;
} else {
V_26 = F_19 ( V_24 , V_23 ,
F_20 ( 1 ) ,
1 , false ) ;
if ( ! V_26 )
return - V_27 ;
V_1 -> V_13 = & V_26 -> V_28 ;
}
return 0 ;
}
static struct V_10 * * F_21 ( struct V_1 * V_1 ,
int * V_24 )
{
if ( F_22 ( V_1 -> V_13 ) ) {
struct V_25 * V_26 = F_23 ( V_1 -> V_13 ) ;
* V_24 = V_26 -> V_24 ;
return V_26 -> V_23 ;
}
* V_24 = 1 ;
return & V_1 -> V_13 ;
}
static void F_24 ( struct V_10 * * V_23 ,
int * V_29 , struct V_10 * V_13 )
{
V_23 [ * V_29 ] = V_13 ;
if ( ! F_25 ( V_13 ) ) {
F_13 ( V_13 ) ;
( * V_29 ) ++ ;
}
}
static struct V_1 * F_26 ( const char * V_14 , struct V_1 * V_30 ,
struct V_1 * V_31 )
{
struct V_1 * V_1 ;
struct V_10 * * V_23 , * * V_32 , * * V_33 , * * V_34 ;
int V_29 , V_35 , V_36 , V_24 , V_37 , V_38 ;
V_1 = F_1 () ;
if ( ! V_1 )
return NULL ;
V_33 = F_21 ( V_30 , & V_37 ) ;
V_34 = F_21 ( V_31 , & V_38 ) ;
if ( V_37 > V_39 - V_38 )
return NULL ;
V_24 = V_37 + V_38 ;
V_23 = F_27 ( V_24 , sizeof( * V_23 ) , V_2 ) ;
if ( ! V_23 )
goto V_5;
for ( V_29 = V_35 = V_36 = 0 ; V_35 < V_37 && V_36 < V_38 ; ) {
struct V_10 * V_40 = V_33 [ V_35 ] ;
struct V_10 * V_41 = V_34 [ V_36 ] ;
if ( V_40 -> V_18 < V_41 -> V_18 ) {
F_24 ( V_23 , & V_29 , V_40 ) ;
V_35 ++ ;
} else if ( V_40 -> V_18 > V_41 -> V_18 ) {
F_24 ( V_23 , & V_29 , V_41 ) ;
V_36 ++ ;
} else {
if ( V_40 -> V_19 - V_41 -> V_19 <= V_39 )
F_24 ( V_23 , & V_29 , V_40 ) ;
else
F_24 ( V_23 , & V_29 , V_41 ) ;
V_35 ++ ;
V_36 ++ ;
}
}
for (; V_35 < V_37 ; V_35 ++ )
F_24 ( V_23 , & V_29 , V_33 [ V_35 ] ) ;
for (; V_36 < V_38 ; V_36 ++ )
F_24 ( V_23 , & V_29 , V_34 [ V_36 ] ) ;
if ( V_29 == 0 )
V_23 [ V_29 ++ ] = F_13 ( V_33 [ 0 ] ) ;
if ( V_24 > V_29 ) {
V_32 = F_28 ( V_23 , V_29 * sizeof( * V_23 ) ,
V_2 ) ;
if ( ! V_32 )
goto V_5;
V_23 = V_32 ;
}
if ( F_18 ( V_1 , V_23 , V_29 ) < 0 ) {
F_8 ( V_23 ) ;
goto V_5;
}
F_29 ( V_1 -> V_14 , V_14 , sizeof( V_1 -> V_14 ) ) ;
return V_1 ;
V_5:
F_16 ( V_1 -> V_3 ) ;
return NULL ;
}
static void F_30 ( struct V_6 * V_6 )
{
struct V_1 * V_1 = F_10 ( V_6 , struct V_1 ,
V_6 ) ;
if ( F_31 ( V_42 , & V_1 -> V_13 -> V_43 ) )
F_32 ( V_1 -> V_13 , & V_1 -> V_8 ) ;
F_33 ( V_1 -> V_13 ) ;
F_8 ( V_1 ) ;
}
static int F_34 ( struct V_44 * V_44 , struct V_3 * V_3 )
{
struct V_1 * V_1 = V_3 -> V_22 ;
F_35 ( & V_1 -> V_6 , F_30 ) ;
return 0 ;
}
static unsigned int F_36 ( struct V_3 * V_3 , T_1 * V_45 )
{
struct V_1 * V_1 = V_3 -> V_22 ;
F_37 ( V_3 , & V_1 -> V_7 , V_45 ) ;
if ( ! F_38 ( V_42 , & V_1 -> V_13 -> V_43 ) ) {
if ( F_39 ( V_1 -> V_13 , & V_1 -> V_8 ,
F_9 ) < 0 )
F_11 ( & V_1 -> V_7 ) ;
}
return F_25 ( V_1 -> V_13 ) ? V_46 : 0 ;
}
static long F_40 ( struct V_1 * V_1 ,
unsigned long V_47 )
{
int V_20 = F_41 ( V_48 ) ;
int V_5 ;
struct V_1 * V_49 , * V_50 ;
struct V_51 V_52 ;
if ( V_20 < 0 )
return V_20 ;
if ( F_42 ( & V_52 , ( void V_53 * ) V_47 , sizeof( V_52 ) ) ) {
V_5 = - V_54 ;
goto V_55;
}
if ( V_52 . V_43 || V_52 . V_56 ) {
V_5 = - V_57 ;
goto V_55;
}
V_49 = F_14 ( V_52 . V_58 ) ;
if ( ! V_49 ) {
V_5 = - V_59 ;
goto V_55;
}
V_52 . V_14 [ sizeof( V_52 . V_14 ) - 1 ] = '\0' ;
V_50 = F_26 ( V_52 . V_14 , V_1 , V_49 ) ;
if ( ! V_50 ) {
V_5 = - V_27 ;
goto V_60;
}
V_52 . V_13 = V_20 ;
if ( F_43 ( ( void V_53 * ) V_47 , & V_52 , sizeof( V_52 ) ) ) {
V_5 = - V_54 ;
goto V_61;
}
F_44 ( V_20 , V_50 -> V_3 ) ;
F_16 ( V_49 -> V_3 ) ;
return 0 ;
V_61:
F_16 ( V_50 -> V_3 ) ;
V_60:
F_16 ( V_49 -> V_3 ) ;
V_55:
F_45 ( V_20 ) ;
return V_5 ;
}
static void F_46 ( struct V_10 * V_13 ,
struct V_62 * V_63 )
{
F_29 ( V_63 -> V_64 , V_13 -> V_15 -> V_17 ( V_13 ) ,
sizeof( V_63 -> V_64 ) ) ;
F_29 ( V_63 -> V_65 , V_13 -> V_15 -> V_16 ( V_13 ) ,
sizeof( V_63 -> V_65 ) ) ;
if ( F_25 ( V_13 ) )
V_63 -> V_66 = V_13 -> V_66 >= 0 ? 1 : V_13 -> V_66 ;
else
V_63 -> V_66 = 0 ;
V_63 -> V_67 = F_47 ( V_13 -> V_68 ) ;
}
static long F_48 ( struct V_1 * V_1 ,
unsigned long V_47 )
{
struct V_69 V_63 ;
struct V_62 * V_70 = NULL ;
struct V_10 * * V_23 ;
T_2 V_71 ;
int V_24 , V_72 , V_29 ;
if ( F_42 ( & V_63 , ( void V_53 * ) V_47 , sizeof( V_63 ) ) )
return - V_54 ;
if ( V_63 . V_43 || V_63 . V_56 )
return - V_57 ;
V_23 = F_21 ( V_1 , & V_24 ) ;
if ( ! V_63 . V_24 )
goto V_73;
if ( V_63 . V_24 < V_24 )
return - V_57 ;
V_71 = V_24 * sizeof( * V_70 ) ;
V_70 = F_2 ( V_71 , V_2 ) ;
if ( ! V_70 )
return - V_27 ;
for ( V_29 = 0 ; V_29 < V_24 ; V_29 ++ )
F_46 ( V_23 [ V_29 ] , & V_70 [ V_29 ] ) ;
if ( F_43 ( F_49 ( V_63 . V_62 ) , V_70 ,
V_71 ) ) {
V_72 = - V_54 ;
goto V_74;
}
V_73:
F_29 ( V_63 . V_14 , V_1 -> V_14 , sizeof( V_63 . V_14 ) ) ;
V_63 . V_66 = F_25 ( V_1 -> V_13 ) ;
V_63 . V_24 = V_24 ;
if ( F_43 ( ( void V_53 * ) V_47 , & V_63 , sizeof( V_63 ) ) )
V_72 = - V_54 ;
else
V_72 = 0 ;
V_74:
F_8 ( V_70 ) ;
return V_72 ;
}
static long F_50 ( struct V_3 * V_3 , unsigned int V_75 ,
unsigned long V_47 )
{
struct V_1 * V_1 = V_3 -> V_22 ;
switch ( V_75 ) {
case V_76 :
return F_40 ( V_1 , V_47 ) ;
case V_77 :
return F_48 ( V_1 , V_47 ) ;
default:
return - V_78 ;
}
}
