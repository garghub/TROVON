static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
return sprintf ( V_5 , L_1 , V_7 -> V_9 ) ;
}
static void F_2 ( unsigned long V_10 )
{
struct V_11 * V_12 = (struct V_11 * ) V_10 ;
F_3 ( & V_12 -> V_13 ) ;
}
static void F_4 ( struct V_14 * V_13 )
{
struct V_11 * V_12 = F_5 ( V_13 , struct V_11 , V_13 ) ;
struct V_15 * V_16 = V_12 -> V_16 ;
V_12 -> V_17 = 0 ;
F_6 ( & V_16 -> V_2 . V_18 , V_19 ) ;
}
static int F_7 ( struct V_15 * V_16 )
{
struct V_6 * V_7 ;
struct V_11 * V_12 ;
int V_20 , V_21 ;
V_12 = F_8 ( sizeof( struct V_11 ) , V_22 ) ;
if ( F_9 ( ! V_12 ) )
return - V_23 ;
V_21 = F_10 ( V_16 , 0 ) ;
if ( F_9 ( V_21 < 0 ) ) {
V_20 = - V_24 ;
goto V_25;
}
V_7 = V_16 -> V_2 . V_8 ;
F_11 ( ! V_7 ) ;
V_20 = F_12 ( V_21 , V_7 -> V_26 ,
V_27 | V_7 -> V_28 ,
V_7 -> V_9 ? V_7 -> V_9 : V_29 , V_16 ) ;
if ( F_9 ( V_20 < 0 ) )
goto V_25;
if ( V_7 -> V_9 ) {
V_20 = F_13 ( & V_16 -> V_2 , & V_30 ) ;
if ( F_9 ( V_20 ) ) {
F_14 ( & V_16 -> V_2 , L_2 ) ;
V_20 = - V_31 ;
goto V_32;
}
}
F_15 ( & V_12 -> V_13 , F_4 ) ;
F_16 ( & V_12 -> V_33 ) ;
V_12 -> V_33 . V_34 = F_2 ;
V_12 -> V_33 . V_10 = ( unsigned long ) V_12 ;
V_12 -> V_16 = V_16 ;
F_17 ( V_16 , V_12 ) ;
return 0 ;
V_32:
F_18 ( V_21 , V_16 ) ;
V_25:
F_19 ( V_12 ) ;
return V_20 ;
}
static int F_20 ( struct V_15 * V_16 )
{
struct V_11 * V_12 = F_21 ( V_16 ) ;
struct V_6 * V_7 = V_16 -> V_2 . V_8 ;
int V_21 = F_10 ( V_16 , 0 ) ;
if ( V_7 -> V_9 )
F_22 ( & V_16 -> V_2 , & V_30 ) ;
F_17 ( V_16 , NULL ) ;
F_23 ( & V_12 -> V_13 ) ;
F_24 ( & V_12 -> V_33 ) ;
F_18 ( V_21 , V_16 ) ;
F_19 ( V_12 ) ;
return 0 ;
}
static int T_2 F_25 ( void )
{
F_26 (KERN_NOTICE DRV_NAME L_3 , DRV_VERSION) ;
return F_27 ( & V_35 ) ;
}
static void T_3 F_28 ( void )
{
F_29 ( & V_35 ) ;
}
