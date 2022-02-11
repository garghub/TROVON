static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return F_2 ( V_5 , V_2 -> V_6 , V_3 , V_4 ) ;
}
static struct V_7 * F_3 ( const struct V_8 * V_9 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
if ( V_11 )
return (struct V_7 * ) V_11 -> V_12 . V_13 ;
return NULL ;
}
static int F_5 ( struct V_10 * V_11 , T_2 * V_14 , T_3 V_15 )
{
struct V_7 * V_16 ;
T_4 V_17 ;
int V_18 ;
V_16 = (struct V_7 * ) V_11 -> V_12 . V_13 ;
if ( ! V_16 -> V_19 ) {
F_6 ( V_16 -> V_9 , L_1 ) ;
return 0 ;
}
V_18 = F_7 ( V_16 -> V_20 , V_16 -> V_21 != 0 ) ;
if ( V_18 )
return - V_22 ;
V_17 = V_16 -> V_21 ;
if ( V_15 < V_17 ) {
F_6 ( V_16 -> V_9 ,
L_2 ,
V_15 , V_17 ) ;
return - V_23 ;
}
F_8 ( & V_16 -> V_24 ) ;
memcpy ( ( void * ) V_14 , ( void * ) V_16 -> V_19 , V_17 ) ;
memset ( V_16 -> V_19 , 0 , V_17 ) ;
V_16 -> V_21 = 0 ;
F_9 ( & V_16 -> V_24 ) ;
return V_17 ;
}
static int F_10 ( struct V_10 * V_11 , T_2 * V_14 , T_3 V_15 )
{
struct V_7 * V_16 ;
struct V_25 V_26 ;
T_1 * V_27 = ( T_1 * ) & V_26 ;
int V_28 ;
V_16 = (struct V_7 * ) V_11 -> V_12 . V_13 ;
if ( ! V_16 -> V_19 ) {
F_6 ( V_16 -> V_9 , L_1 ) ;
return 0 ;
}
if ( V_15 > V_16 -> V_29 ) {
F_6 ( V_16 -> V_9 ,
L_3 ,
V_15 , V_16 -> V_29 ) ;
return - V_23 ;
}
F_8 ( & V_16 -> V_24 ) ;
memcpy ( ( void * ) V_16 -> V_19 , ( void * ) V_14 , V_15 ) ;
V_26 . V_30 = ( T_2 ) V_31 ;
V_26 . V_32 = ( T_2 ) V_33 ;
V_26 . V_17 = ( T_4 ) V_15 ;
V_26 . V_13 = V_16 -> V_34 ;
V_28 = F_1 ( V_16 -> V_2 , V_27 [ 0 ] , V_27 [ 1 ] ) ;
if ( V_28 != V_35 ) {
F_6 ( V_16 -> V_9 , L_4 , V_28 ) ;
V_28 = 0 ;
} else
V_28 = V_15 ;
F_9 ( & V_16 -> V_24 ) ;
return V_28 ;
}
static void F_11 ( struct V_10 * V_11 )
{
return;
}
static T_2 F_12 ( struct V_10 * V_11 )
{
return 0 ;
}
static int F_13 ( struct V_7 * V_16 )
{
struct V_25 V_26 ;
T_1 * V_14 = ( T_1 * ) & V_26 ;
int V_28 ;
V_26 . V_30 = ( T_2 ) V_31 ;
V_26 . V_32 = ( T_2 ) V_36 ;
V_28 = F_1 ( V_16 -> V_2 , V_14 [ 0 ] , V_14 [ 1 ] ) ;
if ( V_28 != V_35 )
F_6 ( V_16 -> V_9 ,
L_5 , V_28 ) ;
return V_28 ;
}
static int F_14 ( struct V_7 * V_16 )
{
struct V_25 V_26 ;
T_1 * V_14 = ( T_1 * ) & V_26 ;
int V_28 ;
V_26 . V_30 = ( T_2 ) V_31 ;
V_26 . V_32 = ( T_2 ) V_37 ;
V_28 = F_1 ( V_16 -> V_2 , V_14 [ 0 ] , V_14 [ 1 ] ) ;
if ( V_28 != V_35 )
F_6 ( V_16 -> V_9 ,
L_6 , V_28 ) ;
return V_28 ;
}
static int F_15 ( struct V_7 * V_16 )
{
int V_28 ;
V_28 = F_1 ( V_16 -> V_2 , V_38 , 0 ) ;
if ( V_28 != V_35 )
F_6 ( V_16 -> V_9 ,
L_7 , V_28 ) ;
return V_28 ;
}
static int F_16 ( struct V_7 * V_16 )
{
int V_28 ;
V_28 = F_1 ( V_16 -> V_2 , V_39 , 0 ) ;
if ( V_28 != V_35 )
F_6 ( V_16 -> V_9 ,
L_8 , V_28 ) ;
return V_28 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_7 * V_16 = F_3 ( & V_2 -> V_9 ) ;
int V_28 = 0 ;
F_18 ( V_2 -> V_40 , V_16 ) ;
do {
if ( V_28 )
F_19 ( 100 ) ;
V_28 = F_2 ( V_41 , V_2 -> V_6 ) ;
} while ( V_28 == V_42 || F_20 ( V_28 ) );
F_21 ( V_16 -> V_9 , V_16 -> V_43 ,
V_44 , V_45 ) ;
F_22 ( ( unsigned long ) V_16 -> V_46 . V_47 ) ;
if ( V_16 -> V_19 ) {
F_21 ( V_16 -> V_9 , V_16 -> V_34 ,
V_16 -> V_29 , V_45 ) ;
F_23 ( V_16 -> V_19 ) ;
}
F_24 ( V_16 -> V_9 ) ;
F_23 ( V_16 ) ;
return 0 ;
}
static unsigned long F_25 ( struct V_1 * V_2 )
{
struct V_7 * V_16 = F_3 ( & V_2 -> V_9 ) ;
return V_44 + V_16 -> V_29 ;
}
static int F_26 ( struct V_8 * V_9 )
{
struct V_7 * V_16 = F_3 ( V_9 ) ;
struct V_25 V_26 ;
T_1 * V_14 = ( T_1 * ) & V_26 ;
int V_28 = 0 ;
V_26 . V_30 = ( T_2 ) V_31 ;
V_26 . V_32 = ( T_2 ) V_48 ;
V_28 = F_1 ( V_16 -> V_2 , V_14 [ 0 ] , V_14 [ 1 ] ) ;
if ( V_28 != V_35 )
F_6 ( V_16 -> V_9 ,
L_9 , V_28 ) ;
return V_28 ;
}
static int F_27 ( struct V_7 * V_16 )
{
int V_28 = 0 ;
do {
if ( V_28 )
F_19 ( 100 ) ;
V_28 = F_2 ( V_41 ,
V_16 -> V_2 -> V_6 ) ;
} while ( V_28 == V_42 || F_20 ( V_28 ) );
memset ( V_16 -> V_46 . V_47 , 0 , V_44 ) ;
V_16 -> V_46 . V_49 = 0 ;
return F_2 ( V_50 , V_16 -> V_2 -> V_6 ,
V_16 -> V_43 , V_44 ) ;
}
static int F_28 ( struct V_8 * V_9 )
{
struct V_7 * V_16 = F_3 ( V_9 ) ;
int V_28 = 0 ;
do {
if ( V_28 )
F_19 ( 100 ) ;
V_28 = F_2 ( V_51 ,
V_16 -> V_2 -> V_6 ) ;
} while ( V_28 == V_52 || V_28 == V_42 || F_20 ( V_28 ) );
if ( V_28 ) {
F_6 ( V_9 , L_10 , V_28 ) ;
return V_28 ;
}
V_28 = F_29 ( V_16 -> V_2 ) ;
if ( V_28 ) {
F_6 ( V_9 , L_11 , V_28 ) ;
return V_28 ;
}
V_28 = F_16 ( V_16 ) ;
if ( V_28 )
F_6 ( V_9 , L_12 , V_28 ) ;
return V_28 ;
}
static struct V_25 * F_30 ( struct V_7 * V_16 )
{
struct V_53 * V_54 = & V_16 -> V_46 ;
struct V_25 * V_26 = & V_54 -> V_47 [ V_54 -> V_49 ] ;
if ( V_26 -> V_30 & V_55 ) {
if ( ++ V_54 -> V_49 == V_54 -> V_56 )
V_54 -> V_49 = 0 ;
F_31 () ;
} else
V_26 = NULL ;
return V_26 ;
}
static void F_32 ( struct V_25 * V_26 ,
struct V_7 * V_16 )
{
int V_28 = 0 ;
switch ( V_26 -> V_30 ) {
case V_57 :
switch ( V_26 -> V_32 ) {
case V_58 :
F_33 ( V_16 -> V_9 , L_13 ) ;
V_28 = F_15 ( V_16 ) ;
if ( V_28 )
F_6 ( V_16 -> V_9 , L_14 , V_28 ) ;
return;
case V_59 :
F_33 ( V_16 -> V_9 ,
L_15 ) ;
return;
default:
F_6 ( V_16 -> V_9 , L_16 , V_26 -> V_32 ) ;
return;
}
return;
case V_31 :
switch ( V_26 -> V_32 ) {
case V_60 :
if ( V_26 -> V_17 <= 0 ) {
F_6 ( V_16 -> V_9 , L_17 ) ;
return;
}
V_16 -> V_29 = V_26 -> V_17 ;
V_16 -> V_19 = F_34 ( V_16 -> V_29 ,
V_61 ) ;
if ( ! V_16 -> V_19 ) {
F_6 ( V_16 -> V_9 , L_18 ) ;
return;
}
V_16 -> V_34 = F_35 ( V_16 -> V_9 ,
V_16 -> V_19 , V_16 -> V_29 ,
V_45 ) ;
if ( F_36 ( V_16 -> V_9 ,
V_16 -> V_34 ) ) {
F_23 ( V_16 -> V_19 ) ;
V_16 -> V_19 = NULL ;
F_6 ( V_16 -> V_9 , L_19 ) ;
}
return;
case V_62 :
V_16 -> V_63 = V_26 -> V_13 ;
return;
case V_64 :
V_16 -> V_21 = V_26 -> V_17 ;
F_37 ( & V_16 -> V_20 ) ;
return;
default:
return;
}
}
return;
}
static T_5 F_38 ( int V_40 , void * V_65 )
{
struct V_7 * V_16 = (struct V_7 * ) V_65 ;
struct V_25 * V_26 ;
while ( ( V_26 = F_30 ( V_16 ) ) != NULL ) {
F_32 ( V_26 , V_16 ) ;
V_26 -> V_30 = 0 ;
F_39 () ;
}
return V_66 ;
}
static int F_40 ( struct V_1 * V_1 ,
const struct V_67 * V_68 )
{
struct V_7 * V_16 ;
struct V_8 * V_9 = & V_1 -> V_9 ;
struct V_53 * V_54 ;
struct V_10 * V_11 ;
int V_28 = - V_69 , V_70 ;
V_11 = F_41 ( V_9 , & V_71 ) ;
if ( ! V_11 ) {
F_6 ( V_9 , L_20 ) ;
return - V_72 ;
}
V_16 = F_42 ( sizeof( struct V_7 ) , V_61 ) ;
if ( ! V_16 ) {
F_6 ( V_9 , L_21 ) ;
goto V_73;
}
V_54 = & V_16 -> V_46 ;
V_54 -> V_47 = (struct V_25 * ) F_43 ( V_61 ) ;
if ( ! V_54 -> V_47 ) {
F_6 ( V_9 , L_22 ) ;
goto V_73;
}
V_54 -> V_56 = V_44 / sizeof( * V_54 -> V_47 ) ;
V_16 -> V_43 = F_35 ( V_9 , V_54 -> V_47 ,
V_44 ,
V_45 ) ;
if ( F_36 ( V_9 , V_16 -> V_43 ) ) {
F_6 ( V_9 , L_23 ) ;
goto V_73;
}
V_28 = F_2 ( V_50 , V_1 -> V_6 ,
V_16 -> V_43 , V_44 ) ;
if ( V_28 == V_74 )
V_28 = F_27 ( V_16 ) ;
if ( V_28 ) {
F_6 ( V_9 , L_24 , V_28 ) ;
goto V_75;
}
V_28 = F_44 ( V_1 -> V_40 , F_38 , 0 ,
V_76 , V_16 ) ;
if ( V_28 ) {
F_6 ( V_9 , L_25 , V_28 , V_1 -> V_40 ) ;
goto V_77;
}
V_28 = F_29 ( V_1 ) ;
if ( V_28 ) {
F_6 ( V_9 , L_26 , V_28 ) ;
goto V_77;
}
F_45 ( & V_16 -> V_20 ) ;
V_54 -> V_49 = 0 ;
V_16 -> V_9 = V_9 ;
V_16 -> V_2 = V_1 ;
V_11 -> V_12 . V_13 = ( void * ) V_16 ;
F_46 ( & V_16 -> V_24 ) ;
V_28 = F_16 ( V_16 ) ;
if ( V_28 )
goto V_77;
V_28 = F_14 ( V_16 ) ;
if ( V_28 )
goto V_77;
V_28 = F_13 ( V_16 ) ;
if ( V_28 )
goto V_77;
return V_28 ;
V_77:
do {
V_70 = F_2 ( V_41 , V_1 -> V_6 ) ;
} while ( V_70 == V_42 || F_20 ( V_70 ) );
V_75:
F_21 ( V_9 , V_16 -> V_43 , V_44 ,
V_45 ) ;
V_73:
if ( V_16 ) {
if ( V_54 -> V_47 )
F_22 ( ( unsigned long ) V_54 -> V_47 ) ;
F_23 ( V_16 ) ;
}
F_24 ( V_9 ) ;
return V_28 ;
}
static int T_6 F_47 ( void )
{
return F_48 ( & V_78 ) ;
}
static void T_7 F_49 ( void )
{
F_50 ( & V_78 ) ;
}
