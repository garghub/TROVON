static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return F_2 ( V_5 , V_2 -> V_6 , V_3 , V_4 ) ;
}
static struct V_7 * F_3 ( const struct V_8 * V_9 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
if ( V_11 )
return (struct V_7 * ) F_5 ( V_11 ) ;
return NULL ;
}
static int F_6 ( struct V_10 * V_11 , T_2 * V_12 , T_3 V_13 )
{
struct V_7 * V_14 ;
T_4 V_15 ;
int V_16 ;
V_14 = (struct V_7 * ) F_5 ( V_11 ) ;
if ( ! V_14 -> V_17 ) {
F_7 ( V_14 -> V_9 , L_1 ) ;
return 0 ;
}
V_16 = F_8 ( V_14 -> V_18 , ! V_14 -> V_19 ) ;
if ( V_16 )
return - V_20 ;
V_15 = V_14 -> V_21 ;
if ( V_13 < V_15 ) {
F_7 ( V_14 -> V_9 ,
L_2 ,
V_13 , V_15 ) ;
return - V_22 ;
}
F_9 ( & V_14 -> V_23 ) ;
memcpy ( ( void * ) V_12 , ( void * ) V_14 -> V_17 , V_15 ) ;
memset ( V_14 -> V_17 , 0 , V_15 ) ;
V_14 -> V_21 = 0 ;
F_10 ( & V_14 -> V_23 ) ;
return V_15 ;
}
static int F_11 ( struct V_10 * V_11 , T_2 * V_12 , T_3 V_13 )
{
struct V_7 * V_14 ;
struct V_24 V_25 ;
T_5 * V_26 = ( T_5 * ) & V_25 ;
int V_27 , V_16 ;
V_14 = (struct V_7 * ) F_5 ( V_11 ) ;
if ( ! V_14 -> V_17 ) {
F_7 ( V_14 -> V_9 , L_1 ) ;
return 0 ;
}
if ( V_13 > V_14 -> V_28 ) {
F_7 ( V_14 -> V_9 ,
L_3 ,
V_13 , V_14 -> V_28 ) ;
return - V_22 ;
}
if ( V_14 -> V_19 ) {
F_12 ( V_14 -> V_9 ,
L_4 ) ;
V_16 = F_8 ( V_14 -> V_18 , ! V_14 -> V_19 ) ;
if ( V_16 )
return - V_20 ;
}
F_9 ( & V_14 -> V_23 ) ;
V_14 -> V_21 = 0 ;
memcpy ( ( void * ) V_14 -> V_17 , ( void * ) V_12 , V_13 ) ;
V_25 . V_29 = ( T_2 ) V_30 ;
V_25 . V_31 = ( T_2 ) V_32 ;
V_25 . V_15 = F_13 ( V_13 ) ;
V_25 . V_33 = F_14 ( V_14 -> V_34 ) ;
V_14 -> V_19 = true ;
V_27 = F_1 ( V_14 -> V_2 , F_15 ( V_26 [ 0 ] ) ,
F_15 ( V_26 [ 1 ] ) ) ;
if ( V_27 != V_35 ) {
F_7 ( V_14 -> V_9 , L_5 , V_27 ) ;
V_27 = 0 ;
V_14 -> V_19 = false ;
} else
V_27 = V_13 ;
F_10 ( & V_14 -> V_23 ) ;
return V_27 ;
}
static void F_16 ( struct V_10 * V_11 )
{
return;
}
static T_2 F_17 ( struct V_10 * V_11 )
{
return 0 ;
}
static int F_18 ( struct V_7 * V_14 )
{
struct V_24 V_25 ;
T_1 * V_12 = ( T_1 * ) & V_25 ;
int V_27 ;
V_25 . V_29 = ( T_2 ) V_30 ;
V_25 . V_31 = ( T_2 ) V_36 ;
V_27 = F_1 ( V_14 -> V_2 , F_19 ( V_12 [ 0 ] ) ,
F_19 ( V_12 [ 1 ] ) ) ;
if ( V_27 != V_35 )
F_7 ( V_14 -> V_9 ,
L_6 , V_27 ) ;
return V_27 ;
}
static int F_20 ( struct V_7 * V_14 )
{
struct V_24 V_25 ;
T_1 * V_12 = ( T_1 * ) & V_25 ;
int V_27 ;
V_25 . V_29 = ( T_2 ) V_30 ;
V_25 . V_31 = ( T_2 ) V_37 ;
V_27 = F_1 ( V_14 -> V_2 , F_19 ( V_12 [ 0 ] ) ,
F_19 ( V_12 [ 1 ] ) ) ;
if ( V_27 != V_35 )
F_7 ( V_14 -> V_9 ,
L_7 , V_27 ) ;
return V_27 ;
}
static int F_21 ( struct V_7 * V_14 )
{
int V_27 ;
V_27 = F_1 ( V_14 -> V_2 , V_38 , 0 ) ;
if ( V_27 != V_35 )
F_7 ( V_14 -> V_9 ,
L_8 , V_27 ) ;
return V_27 ;
}
static int F_22 ( struct V_7 * V_14 )
{
int V_27 ;
V_27 = F_1 ( V_14 -> V_2 , V_39 , 0 ) ;
if ( V_27 != V_35 )
F_7 ( V_14 -> V_9 ,
L_9 , V_27 ) ;
return V_27 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_7 * V_14 = F_3 ( & V_2 -> V_9 ) ;
struct V_10 * V_11 = F_4 ( V_14 -> V_9 ) ;
int V_27 = 0 ;
F_24 ( V_11 ) ;
F_25 ( V_2 -> V_40 , V_14 ) ;
do {
if ( V_27 )
F_26 ( 100 ) ;
V_27 = F_2 ( V_41 , V_2 -> V_6 ) ;
} while ( V_27 == V_42 || F_27 ( V_27 ) );
F_28 ( V_14 -> V_9 , V_14 -> V_43 ,
V_44 , V_45 ) ;
F_29 ( ( unsigned long ) V_14 -> V_46 . V_47 ) ;
if ( V_14 -> V_17 ) {
F_28 ( V_14 -> V_9 , V_14 -> V_34 ,
V_14 -> V_28 , V_45 ) ;
F_30 ( V_14 -> V_17 ) ;
}
F_30 ( V_14 ) ;
return 0 ;
}
static unsigned long F_31 ( struct V_1 * V_2 )
{
struct V_7 * V_14 = F_3 ( & V_2 -> V_9 ) ;
if ( ! V_14 )
return V_44 + V_48 ;
return V_44 + V_14 -> V_28 ;
}
static int F_32 ( struct V_8 * V_9 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_24 V_25 ;
T_1 * V_12 = ( T_1 * ) & V_25 ;
int V_27 = 0 ;
V_25 . V_29 = ( T_2 ) V_30 ;
V_25 . V_31 = ( T_2 ) V_49 ;
V_27 = F_1 ( V_14 -> V_2 , F_19 ( V_12 [ 0 ] ) ,
F_19 ( V_12 [ 1 ] ) ) ;
if ( V_27 != V_35 )
F_7 ( V_14 -> V_9 ,
L_10 , V_27 ) ;
return V_27 ;
}
static int F_33 ( struct V_7 * V_14 )
{
int V_27 = 0 ;
do {
if ( V_27 )
F_26 ( 100 ) ;
V_27 = F_2 ( V_41 ,
V_14 -> V_2 -> V_6 ) ;
} while ( V_27 == V_42 || F_27 ( V_27 ) );
memset ( V_14 -> V_46 . V_47 , 0 , V_44 ) ;
V_14 -> V_46 . V_50 = 0 ;
return F_2 ( V_51 , V_14 -> V_2 -> V_6 ,
V_14 -> V_43 , V_44 ) ;
}
static int F_34 ( struct V_8 * V_9 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
int V_27 = 0 ;
do {
if ( V_27 )
F_26 ( 100 ) ;
V_27 = F_2 ( V_52 ,
V_14 -> V_2 -> V_6 ) ;
} while ( V_27 == V_53 || V_27 == V_42 || F_27 ( V_27 ) );
if ( V_27 ) {
F_7 ( V_9 , L_11 , V_27 ) ;
return V_27 ;
}
V_27 = F_35 ( V_14 -> V_2 ) ;
if ( V_27 ) {
F_7 ( V_9 , L_12 , V_27 ) ;
return V_27 ;
}
V_27 = F_22 ( V_14 ) ;
if ( V_27 )
F_7 ( V_9 , L_13 , V_27 ) ;
return V_27 ;
}
static bool F_36 ( struct V_10 * V_11 , T_2 V_54 )
{
return ( V_54 == 0 ) ;
}
static struct V_24 * F_37 ( struct V_7 * V_14 )
{
struct V_55 * V_56 = & V_14 -> V_46 ;
struct V_24 * V_25 = & V_56 -> V_47 [ V_56 -> V_50 ] ;
if ( V_25 -> V_29 & V_57 ) {
if ( ++ V_56 -> V_50 == V_56 -> V_58 )
V_56 -> V_50 = 0 ;
F_38 () ;
} else
V_25 = NULL ;
return V_25 ;
}
static void F_39 ( struct V_24 * V_25 ,
struct V_7 * V_14 )
{
int V_27 = 0 ;
switch ( V_25 -> V_29 ) {
case V_59 :
switch ( V_25 -> V_31 ) {
case V_60 :
F_12 ( V_14 -> V_9 , L_14 ) ;
V_27 = F_21 ( V_14 ) ;
if ( V_27 )
F_7 ( V_14 -> V_9 , L_15 , V_27 ) ;
return;
case V_61 :
F_12 ( V_14 -> V_9 ,
L_16 ) ;
return;
default:
F_7 ( V_14 -> V_9 , L_17 , V_25 -> V_31 ) ;
return;
}
case V_30 :
switch ( V_25 -> V_31 ) {
case V_62 :
if ( F_40 ( V_25 -> V_15 ) <= 0 ) {
F_7 ( V_14 -> V_9 , L_18 ) ;
return;
}
V_14 -> V_28 = F_40 ( V_25 -> V_15 ) ;
V_14 -> V_17 = F_41 ( V_14 -> V_28 ,
V_63 ) ;
if ( ! V_14 -> V_17 ) {
F_7 ( V_14 -> V_9 , L_19 ) ;
return;
}
V_14 -> V_34 = F_42 ( V_14 -> V_9 ,
V_14 -> V_17 , V_14 -> V_28 ,
V_45 ) ;
if ( F_43 ( V_14 -> V_9 ,
V_14 -> V_34 ) ) {
F_30 ( V_14 -> V_17 ) ;
V_14 -> V_17 = NULL ;
F_7 ( V_14 -> V_9 , L_20 ) ;
}
return;
case V_64 :
V_14 -> V_65 = F_44 ( V_25 -> V_33 ) ;
return;
case V_66 :
V_14 -> V_21 = F_40 ( V_25 -> V_15 ) ;
V_14 -> V_19 = false ;
F_45 ( & V_14 -> V_18 ) ;
return;
default:
return;
}
}
return;
}
static T_6 F_46 ( int V_40 , void * V_67 )
{
struct V_7 * V_14 = (struct V_7 * ) V_67 ;
struct V_24 * V_25 ;
while ( ( V_25 = F_37 ( V_14 ) ) != NULL ) {
F_39 ( V_25 , V_14 ) ;
V_25 -> V_29 = 0 ;
F_47 () ;
}
return V_68 ;
}
static int F_48 ( struct V_1 * V_1 ,
const struct V_69 * V_70 )
{
struct V_7 * V_14 ;
struct V_8 * V_9 = & V_1 -> V_9 ;
struct V_55 * V_56 ;
struct V_10 * V_11 ;
int V_27 = - V_71 , V_72 ;
V_11 = F_49 ( V_9 , & V_73 ) ;
if ( F_50 ( V_11 ) )
return F_51 ( V_11 ) ;
V_14 = F_52 ( sizeof( struct V_7 ) , V_74 ) ;
if ( ! V_14 ) {
F_7 ( V_9 , L_21 ) ;
goto V_75;
}
V_14 -> V_9 = V_9 ;
V_14 -> V_2 = V_1 ;
V_56 = & V_14 -> V_46 ;
V_56 -> V_47 = (struct V_24 * ) F_53 ( V_74 ) ;
if ( ! V_56 -> V_47 ) {
F_7 ( V_9 , L_22 ) ;
goto V_75;
}
V_56 -> V_58 = V_44 / sizeof( * V_56 -> V_47 ) ;
V_14 -> V_43 = F_42 ( V_9 , V_56 -> V_47 ,
V_44 ,
V_45 ) ;
if ( F_43 ( V_9 , V_14 -> V_43 ) ) {
F_7 ( V_9 , L_23 ) ;
goto V_75;
}
V_27 = F_2 ( V_51 , V_1 -> V_6 ,
V_14 -> V_43 , V_44 ) ;
if ( V_27 == V_76 )
V_27 = F_33 ( V_14 ) ;
if ( V_27 ) {
F_7 ( V_9 , L_24 , V_27 ) ;
goto V_77;
}
V_27 = F_54 ( V_1 -> V_40 , F_46 , 0 ,
V_78 , V_14 ) ;
if ( V_27 ) {
F_7 ( V_9 , L_25 , V_27 , V_1 -> V_40 ) ;
goto V_79;
}
V_27 = F_35 ( V_1 ) ;
if ( V_27 ) {
F_7 ( V_9 , L_26 , V_27 ) ;
goto V_79;
}
F_55 ( & V_14 -> V_18 ) ;
V_56 -> V_50 = 0 ;
F_5 ( V_11 ) = ( void * ) V_14 ;
F_56 ( & V_14 -> V_23 ) ;
V_27 = F_22 ( V_14 ) ;
if ( V_27 )
goto V_79;
V_27 = F_20 ( V_14 ) ;
if ( V_27 )
goto V_79;
V_27 = F_18 ( V_14 ) ;
if ( V_27 )
goto V_79;
return F_57 ( V_11 ) ;
V_79:
do {
V_72 = F_2 ( V_41 , V_1 -> V_6 ) ;
} while ( V_72 == V_42 || F_27 ( V_72 ) );
V_77:
F_28 ( V_9 , V_14 -> V_43 , V_44 ,
V_45 ) ;
V_75:
if ( V_14 ) {
if ( V_56 -> V_47 )
F_29 ( ( unsigned long ) V_56 -> V_47 ) ;
F_30 ( V_14 ) ;
}
return V_27 ;
}
static int T_7 F_58 ( void )
{
return F_59 ( & V_80 ) ;
}
static void T_8 F_60 ( void )
{
F_61 ( & V_80 ) ;
}
