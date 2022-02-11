static inline void F_1 ( void )
{
unsigned V_1 = F_2 ( V_2 . V_3 + 0x14 ) ;
V_1 |= ( 1 << 7 ) + ( V_4 << 8 ) ;
F_3 ( V_2 . V_3 + 0x14 , V_1 ) ;
}
static void F_4 ( unsigned long V_5 )
{
if ( F_5 ( V_6 , V_2 . V_7 ) ||
( ! V_8 && ! V_2 . V_9 ) ) {
F_1 () ;
F_6 ( & V_2 . V_10 , V_6 + V_11 ) ;
} else
F_7 (KERN_CRIT PFX L_1 ) ;
}
static void F_8 ( void )
{
V_2 . V_7 = V_6 + V_12 * V_13 ;
}
static void F_9 ( void )
{
F_8 () ;
F_6 ( & V_2 . V_10 , V_6 + V_11 ) ;
}
static int F_10 ( struct V_14 * V_14 , struct V_15 * V_15 )
{
if ( F_11 ( 0 , & V_2 . V_9 ) )
return - V_16 ;
F_9 () ;
return F_12 ( V_14 , V_15 ) ;
}
static int F_13 ( struct V_14 * V_14 , struct V_15 * V_15 )
{
if ( ! V_2 . V_17 )
F_14 ( & V_2 . V_10 ) ;
F_15 ( 0 , & V_2 . V_9 ) ;
V_2 . V_17 = 0 ;
return 0 ;
}
static T_1 F_16 ( struct V_15 * V_15 , const char T_2 * V_5 ,
T_3 V_18 , T_4 * V_19 )
{
if ( ! V_18 )
return 0 ;
if ( ! V_8 ) {
T_3 V_20 ;
V_2 . V_17 = 0 ;
for ( V_20 = 0 ; V_20 < V_18 ; V_20 ++ ) {
char V_21 ;
if ( F_17 ( V_21 , V_5 + V_20 ) )
return - V_22 ;
if ( V_21 == 'V' ) {
V_2 . V_17 = 42 ;
break;
}
}
}
F_8 () ;
return V_18 ;
}
static long F_18 ( struct V_15 * V_15 ,
unsigned int V_23 , unsigned long V_24 )
{
void T_2 * V_25 = ( void T_2 * ) V_24 ;
int T_2 * V_26 = V_25 ;
int V_27 ;
switch ( V_23 ) {
case V_28 :
return F_19 ( V_25 , & V_29 , sizeof( V_29 ) ) ? - V_22 : 0 ;
case V_30 :
return F_20 ( 0 , V_26 ) ;
case V_31 :
return F_20 ( V_2 . V_32 , V_26 ) ;
case V_33 :
F_8 () ;
return 0 ;
case V_34 :
if ( F_17 ( V_27 , V_26 ) )
return - V_22 ;
V_12 = V_27 ;
F_8 () ;
return F_20 ( V_27 , V_26 ) ;
case V_35 :
return F_20 ( V_12 , V_26 ) ;
}
return - V_36 ;
}
static int T_5 F_21 ( void )
{
struct V_37 * V_38 ;
void T_6 * V_3 ;
static T_7 V_39 ;
int V_40 ;
V_38 = F_22 ( NULL , NULL , L_2 ) ;
if ( V_38 == NULL ) {
F_7 (KERN_ERR PFX L_3 ) ;
return - V_41 ;
}
V_2 . V_3 = F_23 ( V_38 , 0 ) ;
F_24 ( V_38 ) ;
if ( V_2 . V_3 == NULL ) {
F_7 (KERN_ERR PFX L_4 ) ;
return - V_42 ;
}
V_29 . V_43 = F_2 ( V_2 . V_3 + 0x1c ) & 0xffff ;
V_38 = F_22 ( NULL , NULL , L_5 ) ;
if ( V_38 == NULL ) {
F_7 (KERN_ERR PFX L_6 ) ;
V_40 = - V_41 ;
goto V_44;
}
V_3 = F_23 ( V_38 , 0 ) ;
F_24 ( V_38 ) ;
if ( V_3 == NULL ) {
F_7 (KERN_ERR PFX L_7 ) ;
V_40 = - V_42 ;
goto V_44;
}
V_39 = F_2 ( V_3 + 0x40 ) ;
if ( V_39 & 0x80000000 )
V_2 . V_32 = V_45 ;
F_25 ( V_3 ) ;
F_26 ( & V_2 . V_10 , F_4 , 0 ) ;
V_40 = F_27 ( & V_46 ) ;
if ( V_40 ) {
F_7 (KERN_ERR PFX L_8 ) ;
goto V_44;
}
F_7 (KERN_INFO PFX L_9 ,
heartbeat, nowayout) ;
return 0 ;
V_44:
F_25 ( V_2 . V_3 ) ;
return V_40 ;
}
static void T_8 F_28 ( void )
{
F_29 ( & V_46 ) ;
F_25 ( V_2 . V_3 ) ;
}
