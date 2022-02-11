static void F_1 ( unsigned long V_1 )
{
if ( F_2 ( 0 , & V_2 ) )
F_3 ( V_3 ) ;
if ( V_4 )
F_4 (KERN_CRIT PFX L_1 ) ;
else if ( V_5 ) {
F_4 (KERN_CRIT PFX L_2 ) ;
F_5 ( L_3 ) ;
} else {
F_4 (KERN_CRIT PFX L_4 ) ;
F_6 () ;
F_4 (KERN_CRIT PFX L_5 ) ;
}
}
static int F_7 ( void )
{
F_8 ( & V_6 , V_7 + ( V_8 * V_9 ) ) ;
return 0 ;
}
static int F_9 ( void )
{
F_10 ( & V_6 ) ;
return 0 ;
}
static int F_11 ( int V_10 )
{
if ( ( V_10 < 0x0001 ) || ( V_10 > 0xFFFF ) )
return - V_11 ;
V_8 = V_10 ;
return 0 ;
}
static int F_12 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
if ( F_13 ( 0 , & V_14 ) )
return - V_15 ;
if ( ! F_2 ( 0 , & V_2 ) )
F_14 ( V_3 ) ;
F_7 () ;
return F_15 ( V_12 , V_13 ) ;
}
static int F_16 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
if ( V_16 == 42 ) {
F_9 () ;
F_3 ( V_3 ) ;
} else {
F_4 (KERN_CRIT PFX
L_6 ) ;
F_17 ( 0 , & V_2 ) ;
F_7 () ;
}
F_18 ( 0 , & V_14 ) ;
V_16 = 0 ;
return 0 ;
}
static T_1 F_19 ( struct V_13 * V_13 , const char T_2 * V_1 ,
T_3 V_17 , T_4 * V_18 )
{
if ( V_17 ) {
if ( ! V_19 ) {
T_3 V_20 ;
V_16 = 0 ;
for ( V_20 = 0 ; V_20 != V_17 ; V_20 ++ ) {
char V_21 ;
if ( F_20 ( V_21 , V_1 + V_20 ) )
return - V_22 ;
if ( V_21 == 'V' )
V_16 = 42 ;
}
}
F_7 () ;
}
return V_17 ;
}
static long F_21 ( struct V_13 * V_13 , unsigned int V_23 ,
unsigned long V_24 )
{
void T_2 * V_25 = ( void T_2 * ) V_24 ;
int T_2 * V_26 = V_25 ;
int V_27 ;
static const struct V_28 V_29 = {
. V_30 = V_31 |
V_32 |
V_33 ,
. V_34 = 0 ,
. V_35 = L_7 ,
} ;
switch ( V_23 ) {
case V_36 :
return F_22 ( V_25 , & V_29 , sizeof( V_29 ) ) ? - V_22 : 0 ;
case V_37 :
case V_38 :
return F_23 ( 0 , V_26 ) ;
case V_39 :
F_7 () ;
return 0 ;
case V_40 :
if ( F_20 ( V_27 , V_26 ) )
return - V_22 ;
if ( F_11 ( V_27 ) )
return - V_11 ;
F_7 () ;
case V_41 :
return F_23 ( V_8 , V_26 ) ;
default:
return - V_42 ;
}
}
static int F_24 ( struct V_43 * V_44 , unsigned long V_45 ,
void * V_46 )
{
if ( V_45 == V_47 || V_45 == V_48 )
F_9 () ;
return V_49 ;
}
static int T_5 F_25 ( void )
{
int V_50 ;
if ( F_11 ( V_8 ) ) {
F_11 ( V_51 ) ;
F_4 (KERN_INFO PFX
L_8 ,
TIMER_MARGIN) ;
}
V_50 = F_26 ( & V_52 ) ;
if ( V_50 ) {
F_4 (KERN_ERR PFX
L_9 , ret) ;
return V_50 ;
}
V_50 = F_27 ( & V_53 ) ;
if ( V_50 ) {
F_4 (KERN_ERR PFX
L_10 ,
WATCHDOG_MINOR, ret) ;
F_28 ( & V_52 ) ;
return V_50 ;
}
F_4 ( V_54 , V_4 , V_8 , V_5 , V_19 ) ;
return 0 ;
}
static void T_6 F_29 ( void )
{
F_30 ( & V_53 ) ;
F_28 ( & V_52 ) ;
}
