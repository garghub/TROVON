static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_4 , V_2 -> V_5 , V_3 , 0 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
T_2 V_6 , T_2 V_7 , T_3 V_8 , T_4 V_9 )
{
T_1 V_3 = ( ( T_1 ) V_6 << 56 ) | ( ( T_1 ) V_7 << 48 ) | ( ( T_1 ) V_8 << 32 ) |
( T_1 ) V_9 ;
return F_1 ( V_2 , V_3 ) ;
}
static int F_4 ( struct V_10 * V_11 , T_2 * V_12 , T_5 V_13 )
{
struct V_14 * V_15 = F_5 ( & V_11 -> V_16 ) ;
T_3 V_8 ;
int V_17 ;
if ( ! V_15 -> V_18 ) {
F_6 ( V_15 -> V_16 , L_1 ) ;
return 0 ;
}
V_17 = F_7 ( V_15 -> V_19 , ! V_15 -> V_20 ) ;
if ( V_17 )
return - V_21 ;
V_8 = V_15 -> V_22 ;
if ( V_13 < V_8 ) {
F_6 ( V_15 -> V_16 ,
L_2 ,
V_13 , V_8 ) ;
return - V_23 ;
}
F_8 ( & V_15 -> V_24 ) ;
memcpy ( ( void * ) V_12 , ( void * ) V_15 -> V_18 , V_8 ) ;
memset ( V_15 -> V_18 , 0 , V_8 ) ;
V_15 -> V_22 = 0 ;
F_9 ( & V_15 -> V_24 ) ;
return V_8 ;
}
static int F_10 ( struct V_10 * V_11 , T_2 * V_12 , T_5 V_13 )
{
struct V_14 * V_15 = F_5 ( & V_11 -> V_16 ) ;
int V_25 , V_17 ;
if ( ! V_15 -> V_18 ) {
F_6 ( V_15 -> V_16 , L_1 ) ;
return 0 ;
}
if ( V_13 > V_15 -> V_26 ) {
F_6 ( V_15 -> V_16 ,
L_3 ,
V_13 , V_15 -> V_26 ) ;
return - V_23 ;
}
if ( V_15 -> V_20 ) {
F_11 ( V_15 -> V_16 ,
L_4 ) ;
V_17 = F_7 ( V_15 -> V_19 , ! V_15 -> V_20 ) ;
if ( V_17 )
return - V_21 ;
}
F_8 ( & V_15 -> V_24 ) ;
V_15 -> V_22 = 0 ;
memcpy ( ( void * ) V_15 -> V_18 , ( void * ) V_12 , V_13 ) ;
V_15 -> V_20 = true ;
V_25 = F_3 ( V_15 -> V_2 ,
V_27 , V_28 ,
V_13 , V_15 -> V_29 ) ;
if ( V_25 != V_30 ) {
F_6 ( V_15 -> V_16 , L_5 , V_25 ) ;
V_25 = 0 ;
V_15 -> V_20 = false ;
} else
V_25 = V_13 ;
F_9 ( & V_15 -> V_24 ) ;
return V_25 ;
}
static void F_12 ( struct V_10 * V_11 )
{
return;
}
static T_2 F_13 ( struct V_10 * V_11 )
{
return 0 ;
}
static int F_14 ( struct V_14 * V_15 )
{
int V_25 ;
V_25 = F_3 ( V_15 -> V_2 ,
V_27 , V_31 , 0 , 0 ) ;
if ( V_25 != V_30 )
F_6 ( V_15 -> V_16 ,
L_6 , V_25 ) ;
return V_25 ;
}
static int F_15 ( struct V_14 * V_15 )
{
int V_25 ;
V_25 = F_3 ( V_15 -> V_2 ,
V_27 , V_32 , 0 , 0 ) ;
if ( V_25 != V_30 )
F_6 ( V_15 -> V_16 ,
L_7 , V_25 ) ;
return V_25 ;
}
static int F_16 ( struct V_14 * V_15 )
{
int V_25 ;
V_25 = F_1 ( V_15 -> V_2 , V_33 ) ;
if ( V_25 != V_30 )
F_6 ( V_15 -> V_16 ,
L_8 , V_25 ) ;
return V_25 ;
}
static int F_17 ( struct V_14 * V_15 )
{
int V_25 ;
V_25 = F_1 ( V_15 -> V_2 , V_34 ) ;
if ( V_25 != V_30 )
F_6 ( V_15 -> V_16 ,
L_9 , V_25 ) ;
return V_25 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_5 ( & V_2 -> V_16 ) ;
struct V_14 * V_15 = F_5 ( & V_11 -> V_16 ) ;
int V_25 = 0 ;
F_19 ( V_11 ) ;
F_20 ( V_2 -> V_35 , V_15 ) ;
do {
if ( V_25 )
F_21 ( 100 ) ;
V_25 = F_2 ( V_36 , V_2 -> V_5 ) ;
} while ( V_25 == V_37 || F_22 ( V_25 ) );
F_23 ( V_15 -> V_16 , V_15 -> V_38 ,
V_39 , V_40 ) ;
F_24 ( ( unsigned long ) V_15 -> V_41 . V_42 ) ;
if ( V_15 -> V_18 ) {
F_23 ( V_15 -> V_16 , V_15 -> V_29 ,
V_15 -> V_26 , V_40 ) ;
F_25 ( V_15 -> V_18 ) ;
}
F_25 ( V_15 ) ;
F_26 ( & V_2 -> V_16 , NULL ) ;
return 0 ;
}
static unsigned long F_27 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_5 ( & V_2 -> V_16 ) ;
struct V_14 * V_15 ;
if ( V_11 )
V_15 = F_5 ( & V_11 -> V_16 ) ;
else
return V_39 + V_43 ;
return V_39 + V_15 -> V_26 ;
}
static int F_28 ( struct V_44 * V_16 )
{
struct V_10 * V_11 = F_5 ( V_16 ) ;
struct V_14 * V_15 = F_5 ( & V_11 -> V_16 ) ;
int V_25 = 0 ;
V_25 = F_3 ( V_15 -> V_2 ,
V_27 , V_45 , 0 , 0 ) ;
if ( V_25 != V_30 )
F_6 ( V_15 -> V_16 ,
L_10 , V_25 ) ;
return V_25 ;
}
static int F_29 ( struct V_14 * V_15 )
{
int V_25 = 0 ;
do {
if ( V_25 )
F_21 ( 100 ) ;
V_25 = F_2 ( V_36 ,
V_15 -> V_2 -> V_5 ) ;
} while ( V_25 == V_37 || F_22 ( V_25 ) );
memset ( V_15 -> V_41 . V_42 , 0 , V_39 ) ;
V_15 -> V_41 . V_46 = 0 ;
return F_2 ( V_47 , V_15 -> V_2 -> V_5 ,
V_15 -> V_38 , V_39 ) ;
}
static int F_30 ( struct V_44 * V_16 )
{
struct V_10 * V_11 = F_5 ( V_16 ) ;
struct V_14 * V_15 = F_5 ( & V_11 -> V_16 ) ;
int V_25 = 0 ;
do {
if ( V_25 )
F_21 ( 100 ) ;
V_25 = F_2 ( V_48 ,
V_15 -> V_2 -> V_5 ) ;
} while ( V_25 == V_49 || V_25 == V_37 || F_22 ( V_25 ) );
if ( V_25 ) {
F_6 ( V_16 , L_11 , V_25 ) ;
return V_25 ;
}
V_25 = F_31 ( V_15 -> V_2 ) ;
if ( V_25 ) {
F_6 ( V_16 , L_12 , V_25 ) ;
return V_25 ;
}
V_25 = F_17 ( V_15 ) ;
if ( V_25 )
F_6 ( V_16 , L_13 , V_25 ) ;
return V_25 ;
}
static bool F_32 ( struct V_10 * V_11 , T_2 V_50 )
{
return ( V_50 == 0 ) ;
}
static struct V_51 * F_33 ( struct V_14 * V_15 )
{
struct V_52 * V_53 = & V_15 -> V_41 ;
struct V_51 * V_54 = & V_53 -> V_42 [ V_53 -> V_46 ] ;
if ( V_54 -> V_6 & V_55 ) {
if ( ++ V_53 -> V_46 == V_53 -> V_56 )
V_53 -> V_46 = 0 ;
F_34 () ;
} else
V_54 = NULL ;
return V_54 ;
}
static void F_35 ( struct V_51 * V_54 ,
struct V_14 * V_15 )
{
int V_25 = 0 ;
switch ( V_54 -> V_6 ) {
case V_57 :
switch ( V_54 -> V_7 ) {
case V_58 :
F_11 ( V_15 -> V_16 , L_14 ) ;
V_25 = F_16 ( V_15 ) ;
if ( V_25 )
F_6 ( V_15 -> V_16 , L_15 , V_25 ) ;
return;
case V_59 :
F_11 ( V_15 -> V_16 ,
L_16 ) ;
return;
default:
F_6 ( V_15 -> V_16 , L_17 , V_54 -> V_7 ) ;
return;
}
case V_27 :
switch ( V_54 -> V_7 ) {
case V_60 :
if ( F_36 ( V_54 -> V_8 ) <= 0 ) {
F_6 ( V_15 -> V_16 , L_18 ) ;
return;
}
V_15 -> V_26 = F_36 ( V_54 -> V_8 ) ;
V_15 -> V_18 = F_37 ( V_15 -> V_26 ,
V_61 ) ;
if ( ! V_15 -> V_18 ) {
F_6 ( V_15 -> V_16 , L_19 ) ;
return;
}
V_15 -> V_29 = F_38 ( V_15 -> V_16 ,
V_15 -> V_18 , V_15 -> V_26 ,
V_40 ) ;
if ( F_39 ( V_15 -> V_16 ,
V_15 -> V_29 ) ) {
F_25 ( V_15 -> V_18 ) ;
V_15 -> V_18 = NULL ;
F_6 ( V_15 -> V_16 , L_20 ) ;
}
return;
case V_62 :
V_15 -> V_63 = F_40 ( V_54 -> V_9 ) ;
return;
case V_64 :
V_15 -> V_22 = F_36 ( V_54 -> V_8 ) ;
V_15 -> V_20 = false ;
F_41 ( & V_15 -> V_19 ) ;
return;
default:
return;
}
}
return;
}
static T_6 F_42 ( int V_35 , void * V_65 )
{
struct V_14 * V_15 = (struct V_14 * ) V_65 ;
struct V_51 * V_54 ;
while ( ( V_54 = F_33 ( V_15 ) ) != NULL ) {
F_35 ( V_54 , V_15 ) ;
V_54 -> V_6 = 0 ;
F_43 () ;
}
return V_66 ;
}
static int F_44 ( struct V_1 * V_1 ,
const struct V_67 * V_68 )
{
struct V_14 * V_15 ;
struct V_44 * V_16 = & V_1 -> V_16 ;
struct V_52 * V_53 ;
struct V_10 * V_11 ;
int V_25 = - V_69 , V_70 ;
V_11 = F_45 ( V_16 , & V_71 ) ;
if ( F_46 ( V_11 ) )
return F_47 ( V_11 ) ;
V_15 = F_48 ( sizeof( struct V_14 ) , V_72 ) ;
if ( ! V_15 ) {
F_6 ( V_16 , L_21 ) ;
goto V_73;
}
V_15 -> V_16 = V_16 ;
V_15 -> V_2 = V_1 ;
V_53 = & V_15 -> V_41 ;
V_53 -> V_42 = (struct V_51 * ) F_49 ( V_72 ) ;
if ( ! V_53 -> V_42 ) {
F_6 ( V_16 , L_22 ) ;
goto V_73;
}
V_53 -> V_56 = V_39 / sizeof( * V_53 -> V_42 ) ;
V_15 -> V_38 = F_38 ( V_16 , V_53 -> V_42 ,
V_39 ,
V_40 ) ;
if ( F_39 ( V_16 , V_15 -> V_38 ) ) {
F_6 ( V_16 , L_23 ) ;
goto V_73;
}
V_25 = F_2 ( V_47 , V_1 -> V_5 ,
V_15 -> V_38 , V_39 ) ;
if ( V_25 == V_74 )
V_25 = F_29 ( V_15 ) ;
if ( V_25 ) {
F_6 ( V_16 , L_24 , V_25 ) ;
goto V_75;
}
V_25 = F_50 ( V_1 -> V_35 , F_42 , 0 ,
V_76 , V_15 ) ;
if ( V_25 ) {
F_6 ( V_16 , L_25 , V_25 , V_1 -> V_35 ) ;
goto V_77;
}
V_25 = F_31 ( V_1 ) ;
if ( V_25 ) {
F_6 ( V_16 , L_26 , V_25 ) ;
goto V_77;
}
F_51 ( & V_15 -> V_19 ) ;
V_53 -> V_46 = 0 ;
F_26 ( & V_11 -> V_16 , V_15 ) ;
F_52 ( & V_15 -> V_24 ) ;
V_25 = F_17 ( V_15 ) ;
if ( V_25 )
goto V_77;
V_25 = F_15 ( V_15 ) ;
if ( V_25 )
goto V_77;
V_25 = F_14 ( V_15 ) ;
if ( V_25 )
goto V_77;
return F_53 ( V_11 ) ;
V_77:
do {
V_70 = F_2 ( V_36 , V_1 -> V_5 ) ;
} while ( V_70 == V_37 || F_22 ( V_70 ) );
V_75:
F_23 ( V_16 , V_15 -> V_38 , V_39 ,
V_40 ) ;
V_73:
if ( V_15 ) {
if ( V_53 -> V_42 )
F_24 ( ( unsigned long ) V_53 -> V_42 ) ;
F_25 ( V_15 ) ;
}
return V_25 ;
}
static int T_7 F_54 ( void )
{
return F_55 ( & V_78 ) ;
}
static void T_8 F_56 ( void )
{
F_57 ( & V_78 ) ;
}
