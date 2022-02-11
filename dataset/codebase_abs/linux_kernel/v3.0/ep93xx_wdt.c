static void F_1 ( void )
{
F_2 ( 0xaaaa , V_1 ) ;
}
static void F_3 ( void )
{
F_2 ( 0xaa55 , V_1 ) ;
}
static inline void F_4 ( void )
{
F_2 ( 0x5555 , V_1 ) ;
}
static void F_5 ( void )
{
V_2 = V_3 + ( V_4 * V_5 ) ;
F_1 () ;
F_6 ( & V_6 , V_3 + V_7 ) ;
}
static void F_7 ( void )
{
F_8 ( & V_6 ) ;
F_3 () ;
}
static void F_9 ( void )
{
V_2 = V_3 + ( V_4 * V_5 ) ;
}
static int F_10 ( struct V_8 * V_8 , struct V_9 * V_9 )
{
if ( F_11 ( V_10 , & V_11 ) )
return - V_12 ;
F_12 ( V_13 , & V_11 ) ;
F_5 () ;
return F_13 ( V_8 , V_9 ) ;
}
static T_1
F_14 ( struct V_9 * V_9 , const char T_2 * V_14 , T_3 V_15 ,
T_4 * V_16 )
{
if ( V_15 ) {
if ( ! V_17 ) {
T_3 V_18 ;
F_12 ( V_13 , & V_11 ) ;
for ( V_18 = 0 ; V_18 != V_15 ; V_18 ++ ) {
char V_19 ;
if ( F_15 ( V_19 , V_14 + V_18 ) )
return - V_20 ;
if ( V_19 == 'V' )
F_16 ( V_13 , & V_11 ) ;
else
F_12 ( V_13 , & V_11 ) ;
}
}
F_9 () ;
}
return V_15 ;
}
static long F_17 ( struct V_9 * V_9 ,
unsigned int V_21 , unsigned long V_22 )
{
int V_23 = - V_24 ;
switch ( V_21 ) {
case V_25 :
V_23 = F_18 ( (struct V_26 T_2 * ) V_22 , & V_27 ,
sizeof( V_27 ) ) ? - V_20 : 0 ;
break;
case V_28 :
V_23 = F_19 ( 0 , ( int T_2 * ) V_22 ) ;
break;
case V_29 :
V_23 = F_19 ( V_30 , ( int T_2 * ) V_22 ) ;
break;
case V_31 :
F_9 () ;
V_23 = 0 ;
break;
case V_32 :
V_23 = F_19 ( 1 , ( int T_2 * ) V_22 ) ;
break;
}
return V_23 ;
}
static int F_20 ( struct V_8 * V_8 , struct V_9 * V_9 )
{
if ( F_21 ( V_13 , & V_11 ) )
F_7 () ;
else
F_22 (KERN_CRIT PFX
L_1 ) ;
F_12 ( V_10 , & V_11 ) ;
F_12 ( V_13 , & V_11 ) ;
return 0 ;
}
static void F_23 ( unsigned long V_14 )
{
if ( F_24 ( V_3 , V_2 ) )
F_4 () ;
F_6 ( & V_6 , V_3 + V_7 ) ;
}
static int T_5 F_25 ( void )
{
int V_33 ;
V_33 = F_26 ( & V_34 ) ;
V_30 = F_27 ( V_1 ) & 0x01 ? 1 : 0 ;
F_22 (KERN_INFO PFX L_2
WDT_VERSION L_3 ,
(__raw_readl(EP93XX_WDT_WATCHDOG) & 0x08)
? L_4 : L_5 ) ;
if ( V_4 < 1 || V_4 > 3600 ) {
V_4 = V_35 ;
F_22 (KERN_INFO PFX
L_6 ,
timeout) ;
}
F_28 ( & V_6 , F_23 , 1 ) ;
return V_33 ;
}
static void T_6 F_29 ( void )
{
F_7 () ;
F_30 ( & V_34 ) ;
}
