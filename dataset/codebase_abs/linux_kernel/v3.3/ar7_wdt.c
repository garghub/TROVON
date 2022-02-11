static void F_1 ( T_1 V_1 )
{
F_2 ( V_2 -> V_3 , 0x5555 ) ;
if ( ( F_3 ( V_2 -> V_3 ) & 3 ) == 1 ) {
F_2 ( V_2 -> V_3 , 0xaaaa ) ;
if ( ( F_3 ( V_2 -> V_3 ) & 3 ) == 3 ) {
F_2 ( V_2 -> V_4 , V_1 ) ;
return;
}
}
F_4 (KERN_ERR DRVNAME L_1 ) ;
}
static void F_5 ( T_1 V_1 )
{
F_2 ( V_2 -> V_5 , 0x5a5a ) ;
if ( ( F_3 ( V_2 -> V_5 ) & 3 ) == 1 ) {
F_2 ( V_2 -> V_5 , 0xa5a5 ) ;
if ( ( F_3 ( V_2 -> V_5 ) & 3 ) == 3 ) {
F_2 ( V_2 -> V_6 , V_1 ) ;
return;
}
}
F_4 (KERN_ERR DRVNAME L_2 ) ;
}
static void F_6 ( T_1 V_1 )
{
F_2 ( V_2 -> V_7 , 0x6666 ) ;
if ( ( F_3 ( V_2 -> V_7 ) & 3 ) == 1 ) {
F_2 ( V_2 -> V_7 , 0xbbbb ) ;
if ( ( F_3 ( V_2 -> V_7 ) & 3 ) == 3 ) {
F_2 ( V_2 -> V_8 , V_1 ) ;
return;
}
}
F_4 (KERN_ERR DRVNAME L_3 ) ;
}
static void F_7 ( T_1 V_1 )
{
F_2 ( V_2 -> V_9 , 0x7777 ) ;
if ( ( F_3 ( V_2 -> V_9 ) & 3 ) == 1 ) {
F_2 ( V_2 -> V_9 , 0xcccc ) ;
if ( ( F_3 ( V_2 -> V_9 ) & 3 ) == 2 ) {
F_2 ( V_2 -> V_9 , 0xdddd ) ;
if ( ( F_3 ( V_2 -> V_9 ) & 3 ) == 3 ) {
F_2 ( V_2 -> V_10 , V_1 ) ;
return;
}
}
}
F_4 (KERN_ERR DRVNAME L_4 ) ;
}
static void F_8 ( int V_11 )
{
T_1 V_8 ;
T_1 V_12 ;
V_12 = F_9 ( V_13 ) ;
V_8 = V_11 * ( V_12 / V_14 ) ;
if ( V_8 < 1 )
V_8 = 1 ;
if ( V_8 > 0xffff )
V_8 = 0xffff ;
F_6 ( V_8 ) ;
V_15 = V_8 * V_14 / V_12 ;
F_4 (KERN_INFO DRVNAME
L_5 ,
margin, prescale_value, change, vbus_rate) ;
}
static void F_10 ( void )
{
F_4 (KERN_DEBUG DRVNAME L_6 ) ;
F_7 ( 1 ) ;
F_1 ( 1 ) ;
}
static void F_11 ( void )
{
F_4 (KERN_DEBUG DRVNAME L_7 ) ;
F_7 ( 0 ) ;
}
static int F_12 ( struct V_16 * V_16 , struct V_17 * V_17 )
{
if ( F_13 ( 0 , & V_18 ) )
return - V_19 ;
F_10 () ;
V_20 = 0 ;
return F_14 ( V_16 , V_17 ) ;
}
static int F_15 ( struct V_16 * V_16 , struct V_17 * V_17 )
{
if ( ! V_20 )
F_4 (KERN_WARNING DRVNAME
L_8
L_9 ) ;
else if ( ! V_21 )
F_11 () ;
F_16 ( 0 , & V_18 ) ;
return 0 ;
}
static T_2 F_17 ( struct V_17 * V_17 , const char * V_22 ,
T_3 V_23 , T_4 * V_24 )
{
if ( V_23 ) {
T_3 V_25 ;
F_18 ( & V_26 ) ;
F_1 ( 1 ) ;
F_19 ( & V_26 ) ;
V_20 = 0 ;
for ( V_25 = 0 ; V_25 < V_23 ; ++ V_25 ) {
char V_27 ;
if ( F_20 ( V_27 , V_22 + V_25 ) )
return - V_28 ;
if ( V_27 == 'V' )
V_20 = 1 ;
}
}
return V_23 ;
}
static long F_21 ( struct V_17 * V_17 ,
unsigned int V_29 , unsigned long V_30 )
{
static const struct V_31 V_32 = {
. V_33 = V_34 ,
. V_35 = 1 ,
. V_36 = ( V_37 | V_38 |
V_39 ) ,
} ;
int V_11 ;
switch ( V_29 ) {
case V_40 :
if ( F_22 ( (struct V_31 * ) V_30 , & V_32 ,
sizeof( V_32 ) ) )
return - V_28 ;
return 0 ;
case V_41 :
case V_42 :
if ( F_23 ( 0 , ( int * ) V_30 ) )
return - V_28 ;
return 0 ;
case V_43 :
F_1 ( 1 ) ;
return 0 ;
case V_44 :
if ( F_20 ( V_11 , ( int * ) V_30 ) )
return - V_28 ;
if ( V_11 < 1 )
return - V_45 ;
F_18 ( & V_26 ) ;
F_8 ( V_11 ) ;
F_1 ( 1 ) ;
F_19 ( & V_26 ) ;
case V_46 :
if ( F_23 ( V_15 , ( int * ) V_30 ) )
return - V_28 ;
return 0 ;
default:
return - V_47 ;
}
}
static int T_5 F_24 ( struct V_48 * V_49 )
{
int V_50 ;
V_51 =
F_25 ( V_49 , V_52 , L_10 ) ;
if ( ! V_51 ) {
F_4 (KERN_ERR DRVNAME L_11 ) ;
V_50 = - V_53 ;
goto V_54;
}
if ( ! F_26 ( V_51 -> V_55 ,
F_27 ( V_51 ) , V_34 ) ) {
F_4 (KERN_WARNING DRVNAME L_12 ) ;
V_50 = - V_19 ;
goto V_54;
}
V_2 = F_28 ( V_51 -> V_55 , F_27 ( V_51 ) ) ;
if ( ! V_2 ) {
F_4 (KERN_ERR DRVNAME L_13 ) ;
V_50 = - V_56 ;
goto V_57;
}
V_13 = F_29 ( NULL , L_14 ) ;
if ( F_30 ( V_13 ) ) {
F_4 (KERN_ERR DRVNAME L_15 ) ;
V_50 = F_31 ( V_13 ) ;
goto V_57;
}
F_11 () ;
F_5 ( V_14 ) ;
F_8 ( V_15 ) ;
V_50 = F_32 ( & V_58 ) ;
if ( V_50 ) {
F_4 (KERN_ERR DRVNAME L_16 ) ;
goto V_59;
}
goto V_54;
V_59:
F_33 ( V_2 ) ;
V_57:
F_34 ( V_51 -> V_55 , F_27 ( V_51 ) ) ;
V_54:
return V_50 ;
}
static int T_6 F_35 ( struct V_48 * V_49 )
{
F_36 ( & V_58 ) ;
F_33 ( V_2 ) ;
F_34 ( V_51 -> V_55 , F_27 ( V_51 ) ) ;
return 0 ;
}
static void F_37 ( struct V_48 * V_49 )
{
if ( ! V_21 )
F_11 () ;
}
