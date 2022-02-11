static void F_1 ( void )
{
F_2 ( 0xfffffffe , V_1 . V_2 + V_3 ) ;
F_2 ( V_4 , V_1 . V_2 + V_5 ) ;
F_2 ( V_6 , V_1 . V_2 + V_5 ) ;
}
static void F_3 ( void )
{
F_2 ( V_7 , V_1 . V_2 + V_5 ) ;
F_2 ( V_8 , V_1 . V_2 + V_5 ) ;
}
static void F_4 ( void * V_9 )
{
struct V_10 * V_2 = F_5 () ;
F_6 ( V_11 L_1 , V_2 ) ;
}
static void F_7 ( unsigned long V_12 )
{
if ( ! F_8 ( & V_1 . V_13 ) ) {
F_1 () ;
F_9 ( & V_1 . V_14 , V_15 + V_16 ) ;
} else
F_10 (KERN_CRIT PFX L_2 ) ;
}
static void F_11 ( void )
{
F_12 ( & V_1 . V_13 , V_17 ) ;
}
static void F_13 ( void )
{
F_11 () ;
F_7 ( 0 ) ;
}
static void F_14 ( void )
{
F_15 ( & V_1 . V_14 ) ;
F_3 () ;
}
static int F_16 ( int V_18 )
{
if ( ( V_18 <= 0 ) || ( V_18 > V_19 ) )
return - V_20 ;
V_17 = V_18 ;
return 0 ;
}
static int F_17 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
if ( F_18 ( 0 , & V_1 . V_23 ) )
return - V_24 ;
F_13 () ;
return F_19 ( V_21 , V_22 ) ;
}
static int F_20 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
if ( V_25 == 42 )
F_14 () ;
else {
F_10 (KERN_CRIT PFX
L_3 ) ;
F_13 () ;
}
F_21 ( 0 , & V_1 . V_23 ) ;
V_25 = 0 ;
return 0 ;
}
static T_1 F_22 ( struct V_22 * V_22 , const char * V_9 ,
T_2 V_26 , T_3 * V_27 )
{
if ( V_26 ) {
if ( ! V_28 ) {
T_2 V_29 ;
V_25 = 0 ;
for ( V_29 = 0 ; V_29 != V_26 ; V_29 ++ ) {
char V_30 ;
if ( F_23 ( V_30 , V_9 + V_29 ) )
return - V_31 ;
if ( V_30 == 'V' )
V_25 = 42 ;
}
}
F_11 () ;
}
return V_26 ;
}
static long F_24 ( struct V_22 * V_22 , unsigned int V_32 ,
unsigned long V_33 )
{
void T_4 * V_34 = ( void T_4 * ) V_33 ;
int T_4 * V_35 = V_34 ;
int V_36 , V_37 = - V_20 ;
switch ( V_32 ) {
case V_38 :
return F_25 ( V_34 , & V_39 ,
sizeof( V_39 ) ) ? - V_31 : 0 ;
case V_40 :
case V_41 :
return F_26 ( 0 , V_35 ) ;
case V_42 :
if ( F_23 ( V_36 , V_35 ) )
return - V_31 ;
if ( V_36 & V_43 ) {
F_14 () ;
V_37 = 0 ;
}
if ( V_36 & V_44 ) {
F_13 () ;
V_37 = 0 ;
}
return V_37 ;
case V_45 :
F_11 () ;
return 0 ;
case V_46 :
if ( F_23 ( V_36 , V_35 ) )
return - V_31 ;
if ( F_16 ( V_36 ) )
return - V_20 ;
F_11 () ;
case V_47 :
return F_26 ( V_17 , V_35 ) ;
default:
return - V_48 ;
}
}
static int T_5 F_27 ( struct V_49 * V_50 )
{
int V_51 ;
struct V_52 * V_53 ;
F_28 ( & V_1 . V_14 , F_7 , 0L ) ;
V_53 = F_29 ( V_50 , V_54 , 0 ) ;
if ( ! V_53 ) {
F_30 ( & V_50 -> V_55 , L_4 ) ;
return - V_56 ;
}
V_1 . V_2 = F_31 ( V_53 -> V_57 , F_32 ( V_53 ) ) ;
if ( ! V_1 . V_2 ) {
F_30 ( & V_50 -> V_55 , L_5 ) ;
return - V_58 ;
}
V_51 = F_33 ( V_59 , F_4 , NULL ) ;
if ( V_51 < 0 ) {
F_30 ( & V_50 -> V_55 , L_6 ) ;
goto V_60;
}
if ( F_16 ( V_17 ) ) {
F_16 ( V_61 ) ;
F_34 ( & V_50 -> V_55 ,
L_7 ,
V_17 ) ;
}
V_51 = F_35 ( & V_62 ) ;
if ( V_51 < 0 ) {
F_30 ( & V_50 -> V_55 , L_8 ) ;
goto V_63;
}
F_34 ( & V_50 -> V_55 , L_9 ,
V_61 ) ;
return 0 ;
V_63:
F_36 ( V_59 ) ;
V_60:
F_37 ( V_1 . V_2 ) ;
return V_51 ;
}
static int T_6 F_38 ( struct V_49 * V_50 )
{
if ( ! V_28 )
F_14 () ;
F_39 ( & V_62 ) ;
F_36 ( V_59 ) ;
F_37 ( V_1 . V_2 ) ;
return 0 ;
}
static void F_40 ( struct V_49 * V_50 )
{
F_14 () ;
}
static int T_7 F_41 ( void )
{
return F_42 ( & V_64 ) ;
}
static void T_8 F_43 ( void )
{
F_44 ( & V_64 ) ;
}
