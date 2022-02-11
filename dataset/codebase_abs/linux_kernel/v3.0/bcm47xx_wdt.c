static inline void F_1 ( void )
{
F_2 ( & V_1 , 0xfffffff ) ;
}
static inline int F_3 ( void )
{
return F_2 ( & V_1 , 0 ) ;
}
static void F_4 ( unsigned long V_2 )
{
if ( ! F_5 ( & V_3 ) ) {
F_1 () ;
F_6 ( & V_4 , V_5 + V_6 ) ;
} else {
F_7 (KERN_CRIT DRV_NAME L_1 ) ;
}
}
static inline void F_8 ( void )
{
F_9 ( & V_3 , V_7 ) ;
}
static void F_10 ( void )
{
F_8 () ;
F_4 ( 0 ) ;
}
static void F_11 ( void )
{
F_12 ( & V_4 ) ;
F_3 () ;
}
static void F_13 ( void )
{
F_11 () ;
}
static int F_14 ( int V_8 )
{
if ( ( V_8 <= 0 ) || ( V_8 > V_9 ) )
return - V_10 ;
V_7 = V_8 ;
return 0 ;
}
static int F_15 ( struct V_11 * V_11 , struct V_12 * V_12 )
{
if ( F_16 ( 0 , & V_13 ) )
return - V_14 ;
F_10 () ;
return F_17 ( V_11 , V_12 ) ;
}
static int F_18 ( struct V_11 * V_11 , struct V_12 * V_12 )
{
if ( V_15 == 42 ) {
F_13 () ;
} else {
F_7 (KERN_CRIT DRV_NAME
L_2 ) ;
F_10 () ;
}
F_19 ( 0 , & V_13 ) ;
V_15 = 0 ;
return 0 ;
}
static T_1 F_20 ( struct V_12 * V_12 , const char T_2 * V_16 ,
T_3 V_17 , T_4 * V_18 )
{
if ( V_17 ) {
if ( ! V_19 ) {
T_3 V_20 ;
V_15 = 0 ;
for ( V_20 = 0 ; V_20 != V_17 ; V_20 ++ ) {
char V_21 ;
if ( F_21 ( V_21 , V_16 + V_20 ) )
return - V_22 ;
if ( V_21 == 'V' )
V_15 = 42 ;
}
}
F_8 () ;
}
return V_17 ;
}
static long F_22 ( struct V_12 * V_12 ,
unsigned int V_23 , unsigned long V_24 )
{
void T_2 * V_25 = ( void T_2 * ) V_24 ;
int T_2 * V_26 = V_25 ;
int V_27 , V_28 = - V_10 ;
switch ( V_23 ) {
case V_29 :
return F_23 ( V_25 , & V_30 ,
sizeof( V_30 ) ) ? - V_22 : 0 ;
case V_31 :
case V_32 :
return F_24 ( 0 , V_26 ) ;
case V_33 :
if ( F_21 ( V_27 , V_26 ) )
return - V_22 ;
if ( V_27 & V_34 ) {
F_13 () ;
V_28 = 0 ;
}
if ( V_27 & V_35 ) {
F_10 () ;
V_28 = 0 ;
}
return V_28 ;
case V_36 :
F_8 () ;
return 0 ;
case V_37 :
if ( F_21 ( V_27 , V_26 ) )
return - V_22 ;
if ( F_14 ( V_27 ) )
return - V_10 ;
F_8 () ;
case V_38 :
return F_24 ( V_7 , V_26 ) ;
default:
return - V_39 ;
}
}
static int F_25 ( struct V_40 * V_41 ,
unsigned long V_42 , void * V_2 )
{
if ( V_42 == V_43 || V_42 == V_44 )
F_13 () ;
return V_45 ;
}
static int T_5 F_26 ( void )
{
int V_46 ;
if ( F_3 () < 0 )
return - V_47 ;
F_27 ( & V_4 , F_4 , 0L ) ;
if ( F_14 ( V_7 ) ) {
F_14 ( V_48 ) ;
F_7 (KERN_INFO DRV_NAME L_3
L_4 ,
(WDT_MAX_TIME + 1), wdt_time) ;
}
V_46 = F_28 ( & V_49 ) ;
if ( V_46 )
return V_46 ;
V_46 = F_29 ( & V_50 ) ;
if ( V_46 ) {
F_30 ( & V_49 ) ;
return V_46 ;
}
F_7 ( V_51 L_5 ,
V_7 , V_19 ? L_6 : L_7 ) ;
return 0 ;
}
static void T_6 F_31 ( void )
{
if ( ! V_19 )
F_13 () ;
F_32 ( & V_50 ) ;
F_30 ( & V_49 ) ;
}
