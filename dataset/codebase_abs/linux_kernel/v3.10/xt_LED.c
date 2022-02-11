static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 ;
if ( ( V_6 -> V_11 > 0 ) && V_6 -> V_12 &&
F_2 ( & V_9 -> V_13 ) )
F_3 ( & V_9 -> V_14 , V_15 ) ;
F_3 ( & V_9 -> V_14 , V_16 ) ;
if ( V_6 -> V_11 > 0 ) {
F_4 ( & V_9 -> V_13 ,
V_17 + F_5 ( V_6 -> V_11 ) ) ;
} else if ( V_6 -> V_11 == 0 ) {
F_3 ( & V_9 -> V_14 , V_15 ) ;
}
return V_18 ;
}
static void F_6 ( unsigned long V_19 )
{
struct V_8 * V_9 = (struct V_8 * ) V_19 ;
F_3 ( & V_9 -> V_14 , V_15 ) ;
}
static struct V_8 * F_7 ( const char * V_20 )
{
struct V_8 * V_9 ;
F_8 (ledinternal, &xt_led_triggers, list) {
if ( ! strcmp ( V_20 , V_9 -> V_14 . V_20 ) ) {
return V_9 ;
}
}
return NULL ;
}
static int F_9 ( const struct V_21 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 ;
int V_22 ;
if ( V_6 -> V_23 [ 0 ] == '\0' ) {
F_10 ( L_1 ) ;
return - V_24 ;
}
F_11 ( & V_25 ) ;
V_9 = F_7 ( V_6 -> V_23 ) ;
if ( V_9 ) {
V_9 -> V_26 ++ ;
goto V_27;
}
V_22 = - V_28 ;
V_9 = F_12 ( sizeof( struct V_8 ) , V_29 ) ;
if ( ! V_9 )
goto V_30;
V_9 -> V_31 = F_13 ( V_6 -> V_23 , V_29 ) ;
if ( ! V_9 -> V_31 )
goto V_32;
V_9 -> V_26 = 1 ;
V_9 -> V_14 . V_20 = V_9 -> V_31 ;
V_22 = F_14 ( & V_9 -> V_14 ) ;
if ( V_22 ) {
F_15 ( L_2 ) ;
if ( V_22 == - V_33 )
F_15 ( L_3 ) ;
goto V_34;
}
if ( V_6 -> V_11 > 0 )
F_16 ( & V_9 -> V_13 , F_6 ,
( unsigned long ) V_9 ) ;
F_17 ( & V_9 -> V_35 , & V_36 ) ;
V_27:
F_18 ( & V_25 ) ;
V_6 -> V_10 = V_9 ;
return 0 ;
V_34:
F_19 ( V_9 -> V_31 ) ;
V_32:
F_19 ( V_9 ) ;
V_30:
F_18 ( & V_25 ) ;
return V_22 ;
}
static void F_20 ( const struct V_37 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 ;
F_11 ( & V_25 ) ;
if ( -- V_9 -> V_26 ) {
F_18 ( & V_25 ) ;
return;
}
F_21 ( & V_9 -> V_35 ) ;
if ( V_6 -> V_11 > 0 )
F_22 ( & V_9 -> V_13 ) ;
F_23 ( & V_9 -> V_14 ) ;
F_18 ( & V_25 ) ;
F_19 ( V_9 -> V_31 ) ;
F_19 ( V_9 ) ;
}
static int T_1 F_24 ( void )
{
return F_25 ( & V_38 ) ;
}
static void T_2 F_26 ( void )
{
F_27 ( & V_38 ) ;
}
