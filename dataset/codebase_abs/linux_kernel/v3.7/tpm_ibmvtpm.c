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
V_16 = (struct V_7 * ) V_11 -> V_12 . V_13 ;
if ( ! V_16 -> V_18 ) {
F_6 ( V_16 -> V_9 , L_1 ) ;
return 0 ;
}
F_7 ( V_19 , V_16 -> V_20 . V_17 != 0 ) ;
if ( V_15 < V_16 -> V_20 . V_17 ) {
F_6 ( V_16 -> V_9 ,
L_2 ,
V_15 , V_16 -> V_20 . V_17 ) ;
return - V_21 ;
}
F_8 ( & V_16 -> V_22 ) ;
memcpy ( ( void * ) V_14 , ( void * ) V_16 -> V_18 , V_16 -> V_20 . V_17 ) ;
memset ( V_16 -> V_18 , 0 , V_16 -> V_20 . V_17 ) ;
V_16 -> V_20 . V_23 = 0 ;
V_16 -> V_20 . V_24 = 0 ;
V_17 = V_16 -> V_20 . V_17 ;
V_16 -> V_20 . V_17 = 0 ;
F_9 ( & V_16 -> V_22 ) ;
return V_17 ;
}
static int F_10 ( struct V_10 * V_11 , T_2 * V_14 , T_3 V_15 )
{
struct V_7 * V_16 ;
struct V_25 V_26 ;
T_1 * V_27 = ( T_1 * ) & V_26 ;
int V_28 ;
V_16 = (struct V_7 * ) V_11 -> V_12 . V_13 ;
if ( ! V_16 -> V_18 ) {
F_6 ( V_16 -> V_9 , L_1 ) ;
return 0 ;
}
if ( V_15 > V_16 -> V_29 ) {
F_6 ( V_16 -> V_9 ,
L_3 ,
V_15 , V_16 -> V_29 ) ;
return - V_21 ;
}
F_8 ( & V_16 -> V_22 ) ;
memcpy ( ( void * ) V_16 -> V_18 , ( void * ) V_14 , V_15 ) ;
V_26 . V_23 = ( T_2 ) V_30 ;
V_26 . V_24 = ( T_2 ) V_31 ;
V_26 . V_17 = ( T_4 ) V_15 ;
V_26 . V_13 = V_16 -> V_32 ;
V_28 = F_1 ( V_16 -> V_2 , V_27 [ 0 ] , V_27 [ 1 ] ) ;
if ( V_28 != V_33 ) {
F_6 ( V_16 -> V_9 , L_4 , V_28 ) ;
V_28 = 0 ;
} else
V_28 = V_15 ;
F_9 ( & V_16 -> V_22 ) ;
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
V_26 . V_23 = ( T_2 ) V_30 ;
V_26 . V_24 = ( T_2 ) V_34 ;
V_28 = F_1 ( V_16 -> V_2 , V_14 [ 0 ] , V_14 [ 1 ] ) ;
if ( V_28 != V_33 )
F_6 ( V_16 -> V_9 ,
L_5 , V_28 ) ;
return V_28 ;
}
static int F_14 ( struct V_7 * V_16 )
{
struct V_25 V_26 ;
T_1 * V_14 = ( T_1 * ) & V_26 ;
int V_28 ;
V_26 . V_23 = ( T_2 ) V_30 ;
V_26 . V_24 = ( T_2 ) V_35 ;
V_28 = F_1 ( V_16 -> V_2 , V_14 [ 0 ] , V_14 [ 1 ] ) ;
if ( V_28 != V_33 )
F_6 ( V_16 -> V_9 ,
L_6 , V_28 ) ;
return V_28 ;
}
static int F_15 ( struct V_7 * V_16 )
{
int V_28 ;
V_28 = F_1 ( V_16 -> V_2 , V_36 , 0 ) ;
if ( V_28 != V_33 )
F_6 ( V_16 -> V_9 ,
L_7 , V_28 ) ;
return V_28 ;
}
static int F_16 ( struct V_7 * V_16 )
{
int V_28 ;
V_28 = F_1 ( V_16 -> V_2 , V_37 , 0 ) ;
if ( V_28 != V_33 )
F_6 ( V_16 -> V_9 ,
L_8 , V_28 ) ;
return V_28 ;
}
static int T_5 F_17 ( struct V_1 * V_2 )
{
struct V_7 * V_16 = F_3 ( & V_2 -> V_9 ) ;
int V_28 = 0 ;
F_18 ( V_2 -> V_38 , V_16 ) ;
F_19 ( & V_16 -> V_39 ) ;
do {
if ( V_28 )
F_20 ( 100 ) ;
V_28 = F_2 ( V_40 , V_2 -> V_6 ) ;
} while ( V_28 == V_41 || F_21 ( V_28 ) );
F_22 ( V_16 -> V_9 , V_16 -> V_42 ,
V_43 , V_44 ) ;
F_23 ( ( unsigned long ) V_16 -> V_45 . V_46 ) ;
if ( V_16 -> V_18 ) {
F_22 ( V_16 -> V_9 , V_16 -> V_32 ,
V_16 -> V_29 , V_44 ) ;
F_24 ( V_16 -> V_18 ) ;
}
F_25 ( V_16 -> V_9 ) ;
F_24 ( V_16 ) ;
return 0 ;
}
static unsigned long F_26 ( struct V_1 * V_2 )
{
struct V_7 * V_16 = F_3 ( & V_2 -> V_9 ) ;
return V_43 + V_16 -> V_29 ;
}
static int F_27 ( struct V_8 * V_9 )
{
struct V_7 * V_16 = F_3 ( V_9 ) ;
struct V_25 V_26 ;
T_1 * V_14 = ( T_1 * ) & V_26 ;
int V_28 = 0 ;
V_26 . V_23 = ( T_2 ) V_30 ;
V_26 . V_24 = ( T_2 ) V_47 ;
V_28 = F_1 ( V_16 -> V_2 , V_14 [ 0 ] , V_14 [ 1 ] ) ;
if ( V_28 != V_33 )
F_6 ( V_16 -> V_9 ,
L_9 , V_28 ) ;
return V_28 ;
}
static int F_28 ( struct V_7 * V_16 )
{
int V_28 = 0 ;
do {
if ( V_28 )
F_20 ( 100 ) ;
V_28 = F_2 ( V_40 ,
V_16 -> V_2 -> V_6 ) ;
} while ( V_28 == V_41 || F_21 ( V_28 ) );
memset ( V_16 -> V_45 . V_46 , 0 , V_43 ) ;
V_16 -> V_45 . V_48 = 0 ;
return F_2 ( V_49 , V_16 -> V_2 -> V_6 ,
V_16 -> V_42 , V_43 ) ;
}
static int F_29 ( struct V_8 * V_9 )
{
struct V_7 * V_16 = F_3 ( V_9 ) ;
unsigned long V_50 ;
int V_28 = 0 ;
do {
if ( V_28 )
F_20 ( 100 ) ;
V_28 = F_2 ( V_51 ,
V_16 -> V_2 -> V_6 ) ;
} while ( V_28 == V_52 || V_28 == V_41 || F_21 ( V_28 ) );
if ( V_28 ) {
F_6 ( V_9 , L_10 , V_28 ) ;
return V_28 ;
}
F_30 ( & V_16 -> V_53 , V_50 ) ;
F_31 ( V_16 -> V_2 ) ;
F_32 ( & V_16 -> V_39 ) ;
F_33 ( & V_16 -> V_53 , V_50 ) ;
V_28 = F_16 ( V_16 ) ;
if ( V_28 )
F_6 ( V_9 , L_11 , V_28 ) ;
return V_28 ;
}
static struct V_25 * F_34 ( struct V_7 * V_16 )
{
struct V_54 * V_55 = & V_16 -> V_45 ;
struct V_25 * V_26 = & V_55 -> V_46 [ V_55 -> V_48 ] ;
if ( V_26 -> V_23 & V_56 ) {
if ( ++ V_55 -> V_48 == V_55 -> V_57 )
V_55 -> V_48 = 0 ;
F_35 () ;
} else
V_26 = NULL ;
return V_26 ;
}
static void F_36 ( struct V_25 * V_26 ,
struct V_7 * V_16 )
{
int V_28 = 0 ;
switch ( V_26 -> V_23 ) {
case V_58 :
switch ( V_26 -> V_24 ) {
case V_59 :
F_37 ( V_16 -> V_9 , L_12 ) ;
V_28 = F_15 ( V_16 ) ;
if ( V_28 )
F_6 ( V_16 -> V_9 , L_13 , V_28 ) ;
return;
case V_60 :
F_37 ( V_16 -> V_9 ,
L_14 ) ;
return;
default:
F_6 ( V_16 -> V_9 , L_15 , V_26 -> V_24 ) ;
return;
}
return;
case V_30 :
switch ( V_26 -> V_24 ) {
case V_61 :
if ( V_26 -> V_17 <= 0 ) {
F_6 ( V_16 -> V_9 , L_16 ) ;
return;
}
V_16 -> V_29 = V_26 -> V_17 ;
V_16 -> V_18 = F_38 ( V_16 -> V_29 ,
V_62 ) ;
if ( ! V_16 -> V_18 ) {
F_6 ( V_16 -> V_9 , L_17 ) ;
return;
}
V_16 -> V_32 = F_39 ( V_16 -> V_9 ,
V_16 -> V_18 , V_16 -> V_29 ,
V_44 ) ;
if ( F_40 ( V_16 -> V_9 ,
V_16 -> V_32 ) ) {
F_24 ( V_16 -> V_18 ) ;
V_16 -> V_18 = NULL ;
F_6 ( V_16 -> V_9 , L_18 ) ;
}
return;
case V_63 :
V_16 -> V_64 = V_26 -> V_13 ;
return;
case V_65 :
V_16 -> V_20 . V_23 = V_26 -> V_23 ;
V_16 -> V_20 . V_24 = V_26 -> V_24 ;
V_16 -> V_20 . V_17 = V_26 -> V_17 ;
V_16 -> V_20 . V_13 = V_26 -> V_13 ;
F_41 ( & V_19 ) ;
return;
default:
return;
}
}
return;
}
static T_6 F_42 ( int V_38 , void * V_66 )
{
struct V_7 * V_16 = (struct V_7 * ) V_66 ;
unsigned long V_50 ;
F_30 ( & V_16 -> V_53 , V_50 ) ;
F_31 ( V_16 -> V_2 ) ;
F_32 ( & V_16 -> V_39 ) ;
F_33 ( & V_16 -> V_53 , V_50 ) ;
return V_67 ;
}
static void F_43 ( void * V_13 )
{
struct V_7 * V_16 = V_13 ;
struct V_25 * V_26 ;
unsigned long V_50 ;
F_30 ( & V_16 -> V_53 , V_50 ) ;
while ( ( V_26 = F_34 ( V_16 ) ) != NULL ) {
F_36 ( V_26 , V_16 ) ;
V_26 -> V_23 = 0 ;
F_44 () ;
}
F_45 ( V_16 -> V_2 ) ;
F_33 ( & V_16 -> V_53 , V_50 ) ;
}
static int T_7 F_46 ( struct V_1 * V_1 ,
const struct V_68 * V_69 )
{
struct V_7 * V_16 ;
struct V_8 * V_9 = & V_1 -> V_9 ;
struct V_54 * V_55 ;
struct V_10 * V_11 ;
int V_28 = - V_70 , V_71 ;
V_11 = F_47 ( V_9 , & V_72 ) ;
if ( ! V_11 ) {
F_6 ( V_9 , L_19 ) ;
return - V_73 ;
}
V_16 = F_48 ( sizeof( struct V_7 ) , V_62 ) ;
if ( ! V_16 ) {
F_6 ( V_9 , L_20 ) ;
goto V_74;
}
V_55 = & V_16 -> V_45 ;
V_55 -> V_46 = (struct V_25 * ) F_49 ( V_62 ) ;
if ( ! V_55 -> V_46 ) {
F_6 ( V_9 , L_21 ) ;
goto V_74;
}
V_55 -> V_57 = V_43 / sizeof( * V_55 -> V_46 ) ;
V_16 -> V_42 = F_39 ( V_9 , V_55 -> V_46 ,
V_43 ,
V_44 ) ;
if ( F_40 ( V_9 , V_16 -> V_42 ) ) {
F_6 ( V_9 , L_22 ) ;
goto V_74;
}
V_28 = F_2 ( V_49 , V_1 -> V_6 ,
V_16 -> V_42 , V_43 ) ;
if ( V_28 == V_75 )
V_28 = F_28 ( V_16 ) ;
if ( V_28 ) {
F_6 ( V_9 , L_23 , V_28 ) ;
goto V_76;
}
F_50 ( & V_16 -> V_39 , ( void * ) F_43 ,
( unsigned long ) V_16 ) ;
V_28 = F_51 ( V_1 -> V_38 , F_42 , 0 ,
V_77 , V_16 ) ;
if ( V_28 ) {
F_6 ( V_9 , L_24 , V_28 , V_1 -> V_38 ) ;
goto V_78;
}
V_28 = F_45 ( V_1 ) ;
if ( V_28 ) {
F_6 ( V_9 , L_25 , V_28 ) ;
goto V_78;
}
V_55 -> V_48 = 0 ;
V_16 -> V_9 = V_9 ;
V_16 -> V_2 = V_1 ;
V_11 -> V_12 . V_13 = ( void * ) V_16 ;
F_52 ( & V_16 -> V_53 ) ;
F_52 ( & V_16 -> V_22 ) ;
V_28 = F_16 ( V_16 ) ;
if ( V_28 )
goto V_78;
V_28 = F_14 ( V_16 ) ;
if ( V_28 )
goto V_78;
V_28 = F_13 ( V_16 ) ;
if ( V_28 )
goto V_78;
return V_28 ;
V_78:
F_19 ( & V_16 -> V_39 ) ;
do {
V_71 = F_2 ( V_40 , V_1 -> V_6 ) ;
} while ( V_71 == V_41 || F_21 ( V_71 ) );
V_76:
F_22 ( V_9 , V_16 -> V_42 , V_43 ,
V_44 ) ;
V_74:
if ( V_16 ) {
if ( V_55 -> V_46 )
F_23 ( ( unsigned long ) V_55 -> V_46 ) ;
F_24 ( V_16 ) ;
}
F_25 ( V_9 ) ;
return V_28 ;
}
static int T_8 F_53 ( void )
{
return F_54 ( & V_79 ) ;
}
static void T_9 F_55 ( void )
{
F_56 ( & V_79 ) ;
}
