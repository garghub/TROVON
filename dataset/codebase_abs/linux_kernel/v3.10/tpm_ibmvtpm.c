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
V_16 = F_8 ( V_14 -> V_18 , V_14 -> V_19 != 0 ) ;
if ( V_16 )
return - V_20 ;
V_15 = V_14 -> V_19 ;
if ( V_13 < V_15 ) {
F_7 ( V_14 -> V_9 ,
L_2 ,
V_13 , V_15 ) ;
return - V_21 ;
}
F_9 ( & V_14 -> V_22 ) ;
memcpy ( ( void * ) V_12 , ( void * ) V_14 -> V_17 , V_15 ) ;
memset ( V_14 -> V_17 , 0 , V_15 ) ;
V_14 -> V_19 = 0 ;
F_10 ( & V_14 -> V_22 ) ;
return V_15 ;
}
static int F_11 ( struct V_10 * V_11 , T_2 * V_12 , T_3 V_13 )
{
struct V_7 * V_14 ;
struct V_23 V_24 ;
T_1 * V_25 = ( T_1 * ) & V_24 ;
int V_26 ;
V_14 = (struct V_7 * ) F_5 ( V_11 ) ;
if ( ! V_14 -> V_17 ) {
F_7 ( V_14 -> V_9 , L_1 ) ;
return 0 ;
}
if ( V_13 > V_14 -> V_27 ) {
F_7 ( V_14 -> V_9 ,
L_3 ,
V_13 , V_14 -> V_27 ) ;
return - V_21 ;
}
F_9 ( & V_14 -> V_22 ) ;
memcpy ( ( void * ) V_14 -> V_17 , ( void * ) V_12 , V_13 ) ;
V_24 . V_28 = ( T_2 ) V_29 ;
V_24 . V_30 = ( T_2 ) V_31 ;
V_24 . V_15 = ( T_4 ) V_13 ;
V_24 . V_32 = V_14 -> V_33 ;
V_26 = F_1 ( V_14 -> V_2 , V_25 [ 0 ] , V_25 [ 1 ] ) ;
if ( V_26 != V_34 ) {
F_7 ( V_14 -> V_9 , L_4 , V_26 ) ;
V_26 = 0 ;
} else
V_26 = V_13 ;
F_10 ( & V_14 -> V_22 ) ;
return V_26 ;
}
static void F_12 ( struct V_10 * V_11 )
{
return;
}
static T_2 F_13 ( struct V_10 * V_11 )
{
return 0 ;
}
static int F_14 ( struct V_7 * V_14 )
{
struct V_23 V_24 ;
T_1 * V_12 = ( T_1 * ) & V_24 ;
int V_26 ;
V_24 . V_28 = ( T_2 ) V_29 ;
V_24 . V_30 = ( T_2 ) V_35 ;
V_26 = F_1 ( V_14 -> V_2 , V_12 [ 0 ] , V_12 [ 1 ] ) ;
if ( V_26 != V_34 )
F_7 ( V_14 -> V_9 ,
L_5 , V_26 ) ;
return V_26 ;
}
static int F_15 ( struct V_7 * V_14 )
{
struct V_23 V_24 ;
T_1 * V_12 = ( T_1 * ) & V_24 ;
int V_26 ;
V_24 . V_28 = ( T_2 ) V_29 ;
V_24 . V_30 = ( T_2 ) V_36 ;
V_26 = F_1 ( V_14 -> V_2 , V_12 [ 0 ] , V_12 [ 1 ] ) ;
if ( V_26 != V_34 )
F_7 ( V_14 -> V_9 ,
L_6 , V_26 ) ;
return V_26 ;
}
static int F_16 ( struct V_7 * V_14 )
{
int V_26 ;
V_26 = F_1 ( V_14 -> V_2 , V_37 , 0 ) ;
if ( V_26 != V_34 )
F_7 ( V_14 -> V_9 ,
L_7 , V_26 ) ;
return V_26 ;
}
static int F_17 ( struct V_7 * V_14 )
{
int V_26 ;
V_26 = F_1 ( V_14 -> V_2 , V_38 , 0 ) ;
if ( V_26 != V_34 )
F_7 ( V_14 -> V_9 ,
L_8 , V_26 ) ;
return V_26 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_7 * V_14 = F_3 ( & V_2 -> V_9 ) ;
int V_26 = 0 ;
F_19 ( V_2 -> V_39 , V_14 ) ;
do {
if ( V_26 )
F_20 ( 100 ) ;
V_26 = F_2 ( V_40 , V_2 -> V_6 ) ;
} while ( V_26 == V_41 || F_21 ( V_26 ) );
F_22 ( V_14 -> V_9 , V_14 -> V_42 ,
V_43 , V_44 ) ;
F_23 ( ( unsigned long ) V_14 -> V_45 . V_46 ) ;
if ( V_14 -> V_17 ) {
F_22 ( V_14 -> V_9 , V_14 -> V_33 ,
V_14 -> V_27 , V_44 ) ;
F_24 ( V_14 -> V_17 ) ;
}
F_25 ( V_14 -> V_9 ) ;
F_24 ( V_14 ) ;
return 0 ;
}
static unsigned long F_26 ( struct V_1 * V_2 )
{
struct V_7 * V_14 = F_3 ( & V_2 -> V_9 ) ;
return V_43 + V_14 -> V_27 ;
}
static int F_27 ( struct V_8 * V_9 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_23 V_24 ;
T_1 * V_12 = ( T_1 * ) & V_24 ;
int V_26 = 0 ;
V_24 . V_28 = ( T_2 ) V_29 ;
V_24 . V_30 = ( T_2 ) V_47 ;
V_26 = F_1 ( V_14 -> V_2 , V_12 [ 0 ] , V_12 [ 1 ] ) ;
if ( V_26 != V_34 )
F_7 ( V_14 -> V_9 ,
L_9 , V_26 ) ;
return V_26 ;
}
static int F_28 ( struct V_7 * V_14 )
{
int V_26 = 0 ;
do {
if ( V_26 )
F_20 ( 100 ) ;
V_26 = F_2 ( V_40 ,
V_14 -> V_2 -> V_6 ) ;
} while ( V_26 == V_41 || F_21 ( V_26 ) );
memset ( V_14 -> V_45 . V_46 , 0 , V_43 ) ;
V_14 -> V_45 . V_48 = 0 ;
return F_2 ( V_49 , V_14 -> V_2 -> V_6 ,
V_14 -> V_42 , V_43 ) ;
}
static int F_29 ( struct V_8 * V_9 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
int V_26 = 0 ;
do {
if ( V_26 )
F_20 ( 100 ) ;
V_26 = F_2 ( V_50 ,
V_14 -> V_2 -> V_6 ) ;
} while ( V_26 == V_51 || V_26 == V_41 || F_21 ( V_26 ) );
if ( V_26 ) {
F_7 ( V_9 , L_10 , V_26 ) ;
return V_26 ;
}
V_26 = F_30 ( V_14 -> V_2 ) ;
if ( V_26 ) {
F_7 ( V_9 , L_11 , V_26 ) ;
return V_26 ;
}
V_26 = F_17 ( V_14 ) ;
if ( V_26 )
F_7 ( V_9 , L_12 , V_26 ) ;
return V_26 ;
}
static bool F_31 ( struct V_10 * V_11 , T_2 V_52 )
{
return ( V_52 == 0 ) ;
}
static struct V_23 * F_32 ( struct V_7 * V_14 )
{
struct V_53 * V_54 = & V_14 -> V_45 ;
struct V_23 * V_24 = & V_54 -> V_46 [ V_54 -> V_48 ] ;
if ( V_24 -> V_28 & V_55 ) {
if ( ++ V_54 -> V_48 == V_54 -> V_56 )
V_54 -> V_48 = 0 ;
F_33 () ;
} else
V_24 = NULL ;
return V_24 ;
}
static void F_34 ( struct V_23 * V_24 ,
struct V_7 * V_14 )
{
int V_26 = 0 ;
switch ( V_24 -> V_28 ) {
case V_57 :
switch ( V_24 -> V_30 ) {
case V_58 :
F_35 ( V_14 -> V_9 , L_13 ) ;
V_26 = F_16 ( V_14 ) ;
if ( V_26 )
F_7 ( V_14 -> V_9 , L_14 , V_26 ) ;
return;
case V_59 :
F_35 ( V_14 -> V_9 ,
L_15 ) ;
return;
default:
F_7 ( V_14 -> V_9 , L_16 , V_24 -> V_30 ) ;
return;
}
return;
case V_29 :
switch ( V_24 -> V_30 ) {
case V_60 :
if ( V_24 -> V_15 <= 0 ) {
F_7 ( V_14 -> V_9 , L_17 ) ;
return;
}
V_14 -> V_27 = V_24 -> V_15 ;
V_14 -> V_17 = F_36 ( V_14 -> V_27 ,
V_61 ) ;
if ( ! V_14 -> V_17 ) {
F_7 ( V_14 -> V_9 , L_18 ) ;
return;
}
V_14 -> V_33 = F_37 ( V_14 -> V_9 ,
V_14 -> V_17 , V_14 -> V_27 ,
V_44 ) ;
if ( F_38 ( V_14 -> V_9 ,
V_14 -> V_33 ) ) {
F_24 ( V_14 -> V_17 ) ;
V_14 -> V_17 = NULL ;
F_7 ( V_14 -> V_9 , L_19 ) ;
}
return;
case V_62 :
V_14 -> V_63 = V_24 -> V_32 ;
return;
case V_64 :
V_14 -> V_19 = V_24 -> V_15 ;
F_39 ( & V_14 -> V_18 ) ;
return;
default:
return;
}
}
return;
}
static T_5 F_40 ( int V_39 , void * V_65 )
{
struct V_7 * V_14 = (struct V_7 * ) V_65 ;
struct V_23 * V_24 ;
while ( ( V_24 = F_32 ( V_14 ) ) != NULL ) {
F_34 ( V_24 , V_14 ) ;
V_24 -> V_28 = 0 ;
F_41 () ;
}
return V_66 ;
}
static int F_42 ( struct V_1 * V_1 ,
const struct V_67 * V_68 )
{
struct V_7 * V_14 ;
struct V_8 * V_9 = & V_1 -> V_9 ;
struct V_53 * V_54 ;
struct V_10 * V_11 ;
int V_26 = - V_69 , V_70 ;
V_11 = F_43 ( V_9 , & V_71 ) ;
if ( ! V_11 ) {
F_7 ( V_9 , L_20 ) ;
return - V_72 ;
}
V_14 = F_44 ( sizeof( struct V_7 ) , V_61 ) ;
if ( ! V_14 ) {
F_7 ( V_9 , L_21 ) ;
goto V_73;
}
V_54 = & V_14 -> V_45 ;
V_54 -> V_46 = (struct V_23 * ) F_45 ( V_61 ) ;
if ( ! V_54 -> V_46 ) {
F_7 ( V_9 , L_22 ) ;
goto V_73;
}
V_54 -> V_56 = V_43 / sizeof( * V_54 -> V_46 ) ;
V_14 -> V_42 = F_37 ( V_9 , V_54 -> V_46 ,
V_43 ,
V_44 ) ;
if ( F_38 ( V_9 , V_14 -> V_42 ) ) {
F_7 ( V_9 , L_23 ) ;
goto V_73;
}
V_26 = F_2 ( V_49 , V_1 -> V_6 ,
V_14 -> V_42 , V_43 ) ;
if ( V_26 == V_74 )
V_26 = F_28 ( V_14 ) ;
if ( V_26 ) {
F_7 ( V_9 , L_24 , V_26 ) ;
goto V_75;
}
V_26 = F_46 ( V_1 -> V_39 , F_40 , 0 ,
V_76 , V_14 ) ;
if ( V_26 ) {
F_7 ( V_9 , L_25 , V_26 , V_1 -> V_39 ) ;
goto V_77;
}
V_26 = F_30 ( V_1 ) ;
if ( V_26 ) {
F_7 ( V_9 , L_26 , V_26 ) ;
goto V_77;
}
F_47 ( & V_14 -> V_18 ) ;
V_54 -> V_48 = 0 ;
V_14 -> V_9 = V_9 ;
V_14 -> V_2 = V_1 ;
F_5 ( V_11 ) = ( void * ) V_14 ;
F_48 ( & V_14 -> V_22 ) ;
V_26 = F_17 ( V_14 ) ;
if ( V_26 )
goto V_77;
V_26 = F_15 ( V_14 ) ;
if ( V_26 )
goto V_77;
V_26 = F_14 ( V_14 ) ;
if ( V_26 )
goto V_77;
return V_26 ;
V_77:
do {
V_70 = F_2 ( V_40 , V_1 -> V_6 ) ;
} while ( V_70 == V_41 || F_21 ( V_70 ) );
V_75:
F_22 ( V_9 , V_14 -> V_42 , V_43 ,
V_44 ) ;
V_73:
if ( V_14 ) {
if ( V_54 -> V_46 )
F_23 ( ( unsigned long ) V_54 -> V_46 ) ;
F_24 ( V_14 ) ;
}
F_25 ( V_9 ) ;
return V_26 ;
}
static int T_6 F_49 ( void )
{
return F_50 ( & V_78 ) ;
}
static void T_7 F_51 ( void )
{
F_52 ( & V_78 ) ;
}
