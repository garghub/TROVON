static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return F_2 ( V_5 , V_2 -> V_6 , V_3 , V_4 ) ;
}
static int F_3 ( struct V_7 * V_8 , T_2 * V_9 , T_3 V_10 )
{
struct V_11 * V_12 = F_4 ( & V_8 -> V_13 ) ;
T_4 V_14 ;
int V_15 ;
if ( ! V_12 -> V_16 ) {
F_5 ( V_12 -> V_13 , L_1 ) ;
return 0 ;
}
V_15 = F_6 ( V_12 -> V_17 , ! V_12 -> V_18 ) ;
if ( V_15 )
return - V_19 ;
V_14 = V_12 -> V_20 ;
if ( V_10 < V_14 ) {
F_5 ( V_12 -> V_13 ,
L_2 ,
V_10 , V_14 ) ;
return - V_21 ;
}
F_7 ( & V_12 -> V_22 ) ;
memcpy ( ( void * ) V_9 , ( void * ) V_12 -> V_16 , V_14 ) ;
memset ( V_12 -> V_16 , 0 , V_14 ) ;
V_12 -> V_20 = 0 ;
F_8 ( & V_12 -> V_22 ) ;
return V_14 ;
}
static int F_9 ( struct V_7 * V_8 , T_2 * V_9 , T_3 V_10 )
{
struct V_11 * V_12 = F_4 ( & V_8 -> V_13 ) ;
struct V_23 V_24 ;
T_5 * V_25 = ( T_5 * ) & V_24 ;
int V_26 , V_15 ;
if ( ! V_12 -> V_16 ) {
F_5 ( V_12 -> V_13 , L_1 ) ;
return 0 ;
}
if ( V_10 > V_12 -> V_27 ) {
F_5 ( V_12 -> V_13 ,
L_3 ,
V_10 , V_12 -> V_27 ) ;
return - V_21 ;
}
if ( V_12 -> V_18 ) {
F_10 ( V_12 -> V_13 ,
L_4 ) ;
V_15 = F_6 ( V_12 -> V_17 , ! V_12 -> V_18 ) ;
if ( V_15 )
return - V_19 ;
}
F_7 ( & V_12 -> V_22 ) ;
V_12 -> V_20 = 0 ;
memcpy ( ( void * ) V_12 -> V_16 , ( void * ) V_9 , V_10 ) ;
V_24 . V_28 = ( T_2 ) V_29 ;
V_24 . V_30 = ( T_2 ) V_31 ;
V_24 . V_14 = F_11 ( V_10 ) ;
V_24 . V_32 = F_12 ( V_12 -> V_33 ) ;
V_12 -> V_18 = true ;
V_26 = F_1 ( V_12 -> V_2 , F_13 ( V_25 [ 0 ] ) ,
F_13 ( V_25 [ 1 ] ) ) ;
if ( V_26 != V_34 ) {
F_5 ( V_12 -> V_13 , L_5 , V_26 ) ;
V_26 = 0 ;
V_12 -> V_18 = false ;
} else
V_26 = V_10 ;
F_8 ( & V_12 -> V_22 ) ;
return V_26 ;
}
static void F_14 ( struct V_7 * V_8 )
{
return;
}
static T_2 F_15 ( struct V_7 * V_8 )
{
return 0 ;
}
static int F_16 ( struct V_11 * V_12 )
{
struct V_23 V_24 ;
T_1 * V_9 = ( T_1 * ) & V_24 ;
int V_26 ;
V_24 . V_28 = ( T_2 ) V_29 ;
V_24 . V_30 = ( T_2 ) V_35 ;
V_26 = F_1 ( V_12 -> V_2 , F_17 ( V_9 [ 0 ] ) ,
F_17 ( V_9 [ 1 ] ) ) ;
if ( V_26 != V_34 )
F_5 ( V_12 -> V_13 ,
L_6 , V_26 ) ;
return V_26 ;
}
static int F_18 ( struct V_11 * V_12 )
{
struct V_23 V_24 ;
T_1 * V_9 = ( T_1 * ) & V_24 ;
int V_26 ;
V_24 . V_28 = ( T_2 ) V_29 ;
V_24 . V_30 = ( T_2 ) V_36 ;
V_26 = F_1 ( V_12 -> V_2 , F_17 ( V_9 [ 0 ] ) ,
F_17 ( V_9 [ 1 ] ) ) ;
if ( V_26 != V_34 )
F_5 ( V_12 -> V_13 ,
L_7 , V_26 ) ;
return V_26 ;
}
static int F_19 ( struct V_11 * V_12 )
{
int V_26 ;
V_26 = F_1 ( V_12 -> V_2 , V_37 , 0 ) ;
if ( V_26 != V_34 )
F_5 ( V_12 -> V_13 ,
L_8 , V_26 ) ;
return V_26 ;
}
static int F_20 ( struct V_11 * V_12 )
{
int V_26 ;
V_26 = F_1 ( V_12 -> V_2 , V_38 , 0 ) ;
if ( V_26 != V_34 )
F_5 ( V_12 -> V_13 ,
L_9 , V_26 ) ;
return V_26 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_4 ( & V_2 -> V_13 ) ;
struct V_11 * V_12 = F_4 ( & V_8 -> V_13 ) ;
int V_26 = 0 ;
F_22 ( V_8 ) ;
F_23 ( V_2 -> V_39 , V_12 ) ;
do {
if ( V_26 )
F_24 ( 100 ) ;
V_26 = F_2 ( V_40 , V_2 -> V_6 ) ;
} while ( V_26 == V_41 || F_25 ( V_26 ) );
F_26 ( V_12 -> V_13 , V_12 -> V_42 ,
V_43 , V_44 ) ;
F_27 ( ( unsigned long ) V_12 -> V_45 . V_46 ) ;
if ( V_12 -> V_16 ) {
F_26 ( V_12 -> V_13 , V_12 -> V_33 ,
V_12 -> V_27 , V_44 ) ;
F_28 ( V_12 -> V_16 ) ;
}
F_28 ( V_12 ) ;
F_29 ( & V_2 -> V_13 , NULL ) ;
return 0 ;
}
static unsigned long F_30 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_4 ( & V_2 -> V_13 ) ;
struct V_11 * V_12 ;
if ( V_8 )
V_12 = F_4 ( & V_8 -> V_13 ) ;
else
return V_43 + V_47 ;
return V_43 + V_12 -> V_27 ;
}
static int F_31 ( struct V_48 * V_13 )
{
struct V_7 * V_8 = F_4 ( V_13 ) ;
struct V_11 * V_12 = F_4 ( & V_8 -> V_13 ) ;
struct V_23 V_24 ;
T_1 * V_9 = ( T_1 * ) & V_24 ;
int V_26 = 0 ;
V_24 . V_28 = ( T_2 ) V_29 ;
V_24 . V_30 = ( T_2 ) V_49 ;
V_26 = F_1 ( V_12 -> V_2 , F_17 ( V_9 [ 0 ] ) ,
F_17 ( V_9 [ 1 ] ) ) ;
if ( V_26 != V_34 )
F_5 ( V_12 -> V_13 ,
L_10 , V_26 ) ;
return V_26 ;
}
static int F_32 ( struct V_11 * V_12 )
{
int V_26 = 0 ;
do {
if ( V_26 )
F_24 ( 100 ) ;
V_26 = F_2 ( V_40 ,
V_12 -> V_2 -> V_6 ) ;
} while ( V_26 == V_41 || F_25 ( V_26 ) );
memset ( V_12 -> V_45 . V_46 , 0 , V_43 ) ;
V_12 -> V_45 . V_50 = 0 ;
return F_2 ( V_51 , V_12 -> V_2 -> V_6 ,
V_12 -> V_42 , V_43 ) ;
}
static int F_33 ( struct V_48 * V_13 )
{
struct V_7 * V_8 = F_4 ( V_13 ) ;
struct V_11 * V_12 = F_4 ( & V_8 -> V_13 ) ;
int V_26 = 0 ;
do {
if ( V_26 )
F_24 ( 100 ) ;
V_26 = F_2 ( V_52 ,
V_12 -> V_2 -> V_6 ) ;
} while ( V_26 == V_53 || V_26 == V_41 || F_25 ( V_26 ) );
if ( V_26 ) {
F_5 ( V_13 , L_11 , V_26 ) ;
return V_26 ;
}
V_26 = F_34 ( V_12 -> V_2 ) ;
if ( V_26 ) {
F_5 ( V_13 , L_12 , V_26 ) ;
return V_26 ;
}
V_26 = F_20 ( V_12 ) ;
if ( V_26 )
F_5 ( V_13 , L_13 , V_26 ) ;
return V_26 ;
}
static bool F_35 ( struct V_7 * V_8 , T_2 V_54 )
{
return ( V_54 == 0 ) ;
}
static struct V_23 * F_36 ( struct V_11 * V_12 )
{
struct V_55 * V_56 = & V_12 -> V_45 ;
struct V_23 * V_24 = & V_56 -> V_46 [ V_56 -> V_50 ] ;
if ( V_24 -> V_28 & V_57 ) {
if ( ++ V_56 -> V_50 == V_56 -> V_58 )
V_56 -> V_50 = 0 ;
F_37 () ;
} else
V_24 = NULL ;
return V_24 ;
}
static void F_38 ( struct V_23 * V_24 ,
struct V_11 * V_12 )
{
int V_26 = 0 ;
switch ( V_24 -> V_28 ) {
case V_59 :
switch ( V_24 -> V_30 ) {
case V_60 :
F_10 ( V_12 -> V_13 , L_14 ) ;
V_26 = F_19 ( V_12 ) ;
if ( V_26 )
F_5 ( V_12 -> V_13 , L_15 , V_26 ) ;
return;
case V_61 :
F_10 ( V_12 -> V_13 ,
L_16 ) ;
return;
default:
F_5 ( V_12 -> V_13 , L_17 , V_24 -> V_30 ) ;
return;
}
case V_29 :
switch ( V_24 -> V_30 ) {
case V_62 :
if ( F_39 ( V_24 -> V_14 ) <= 0 ) {
F_5 ( V_12 -> V_13 , L_18 ) ;
return;
}
V_12 -> V_27 = F_39 ( V_24 -> V_14 ) ;
V_12 -> V_16 = F_40 ( V_12 -> V_27 ,
V_63 ) ;
if ( ! V_12 -> V_16 ) {
F_5 ( V_12 -> V_13 , L_19 ) ;
return;
}
V_12 -> V_33 = F_41 ( V_12 -> V_13 ,
V_12 -> V_16 , V_12 -> V_27 ,
V_44 ) ;
if ( F_42 ( V_12 -> V_13 ,
V_12 -> V_33 ) ) {
F_28 ( V_12 -> V_16 ) ;
V_12 -> V_16 = NULL ;
F_5 ( V_12 -> V_13 , L_20 ) ;
}
return;
case V_64 :
V_12 -> V_65 = F_43 ( V_24 -> V_32 ) ;
return;
case V_66 :
V_12 -> V_20 = F_39 ( V_24 -> V_14 ) ;
V_12 -> V_18 = false ;
F_44 ( & V_12 -> V_17 ) ;
return;
default:
return;
}
}
return;
}
static T_6 F_45 ( int V_39 , void * V_67 )
{
struct V_11 * V_12 = (struct V_11 * ) V_67 ;
struct V_23 * V_24 ;
while ( ( V_24 = F_36 ( V_12 ) ) != NULL ) {
F_38 ( V_24 , V_12 ) ;
V_24 -> V_28 = 0 ;
F_46 () ;
}
return V_68 ;
}
static int F_47 ( struct V_1 * V_1 ,
const struct V_69 * V_70 )
{
struct V_11 * V_12 ;
struct V_48 * V_13 = & V_1 -> V_13 ;
struct V_55 * V_56 ;
struct V_7 * V_8 ;
int V_26 = - V_71 , V_72 ;
V_8 = F_48 ( V_13 , & V_73 ) ;
if ( F_49 ( V_8 ) )
return F_50 ( V_8 ) ;
V_12 = F_51 ( sizeof( struct V_11 ) , V_74 ) ;
if ( ! V_12 ) {
F_5 ( V_13 , L_21 ) ;
goto V_75;
}
V_12 -> V_13 = V_13 ;
V_12 -> V_2 = V_1 ;
V_56 = & V_12 -> V_45 ;
V_56 -> V_46 = (struct V_23 * ) F_52 ( V_74 ) ;
if ( ! V_56 -> V_46 ) {
F_5 ( V_13 , L_22 ) ;
goto V_75;
}
V_56 -> V_58 = V_43 / sizeof( * V_56 -> V_46 ) ;
V_12 -> V_42 = F_41 ( V_13 , V_56 -> V_46 ,
V_43 ,
V_44 ) ;
if ( F_42 ( V_13 , V_12 -> V_42 ) ) {
F_5 ( V_13 , L_23 ) ;
goto V_75;
}
V_26 = F_2 ( V_51 , V_1 -> V_6 ,
V_12 -> V_42 , V_43 ) ;
if ( V_26 == V_76 )
V_26 = F_32 ( V_12 ) ;
if ( V_26 ) {
F_5 ( V_13 , L_24 , V_26 ) ;
goto V_77;
}
V_26 = F_53 ( V_1 -> V_39 , F_45 , 0 ,
V_78 , V_12 ) ;
if ( V_26 ) {
F_5 ( V_13 , L_25 , V_26 , V_1 -> V_39 ) ;
goto V_79;
}
V_26 = F_34 ( V_1 ) ;
if ( V_26 ) {
F_5 ( V_13 , L_26 , V_26 ) ;
goto V_79;
}
F_54 ( & V_12 -> V_17 ) ;
V_56 -> V_50 = 0 ;
F_29 ( & V_8 -> V_13 , V_12 ) ;
F_55 ( & V_12 -> V_22 ) ;
V_26 = F_20 ( V_12 ) ;
if ( V_26 )
goto V_79;
V_26 = F_18 ( V_12 ) ;
if ( V_26 )
goto V_79;
V_26 = F_16 ( V_12 ) ;
if ( V_26 )
goto V_79;
return F_56 ( V_8 ) ;
V_79:
do {
V_72 = F_2 ( V_40 , V_1 -> V_6 ) ;
} while ( V_72 == V_41 || F_25 ( V_72 ) );
V_77:
F_26 ( V_13 , V_12 -> V_42 , V_43 ,
V_44 ) ;
V_75:
if ( V_12 ) {
if ( V_56 -> V_46 )
F_27 ( ( unsigned long ) V_56 -> V_46 ) ;
F_28 ( V_12 ) ;
}
return V_26 ;
}
static int T_7 F_57 ( void )
{
return F_58 ( & V_80 ) ;
}
static void T_8 F_59 ( void )
{
F_60 ( & V_80 ) ;
}
