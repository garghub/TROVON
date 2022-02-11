static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned long V_11 = V_12 ;
if ( ( V_6 -> V_13 > 0 ) && V_6 -> V_14 &&
F_2 ( & V_9 -> V_15 ) )
F_3 ( & V_9 -> V_16 ,
& V_11 , & V_11 , 1 ) ;
else
F_4 ( & V_9 -> V_16 , V_17 ) ;
if ( V_6 -> V_13 > 0 ) {
F_5 ( & V_9 -> V_15 ,
V_18 + F_6 ( V_6 -> V_13 ) ) ;
} else if ( V_6 -> V_13 == 0 ) {
F_4 ( & V_9 -> V_16 , V_19 ) ;
}
return V_20 ;
}
static void F_7 ( unsigned long V_21 )
{
struct V_8 * V_9 = (struct V_8 * ) V_21 ;
F_4 ( & V_9 -> V_16 , V_19 ) ;
}
static struct V_8 * F_8 ( const char * V_22 )
{
struct V_8 * V_9 ;
F_9 (ledinternal, &xt_led_triggers, list) {
if ( ! strcmp ( V_22 , V_9 -> V_16 . V_22 ) ) {
return V_9 ;
}
}
return NULL ;
}
static int F_10 ( const struct V_23 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 ;
int V_24 ;
if ( V_6 -> V_25 [ 0 ] == '\0' ) {
F_11 ( L_1 ) ;
return - V_26 ;
}
F_12 ( & V_27 ) ;
V_9 = F_8 ( V_6 -> V_25 ) ;
if ( V_9 ) {
V_9 -> V_28 ++ ;
goto V_29;
}
V_24 = - V_30 ;
V_9 = F_13 ( sizeof( struct V_8 ) , V_31 ) ;
if ( ! V_9 )
goto V_32;
V_9 -> V_33 = F_14 ( V_6 -> V_25 , V_31 ) ;
if ( ! V_9 -> V_33 )
goto V_34;
V_9 -> V_28 = 1 ;
V_9 -> V_16 . V_22 = V_9 -> V_33 ;
V_24 = F_15 ( & V_9 -> V_16 ) ;
if ( V_24 ) {
F_16 ( L_2 ) ;
goto V_35;
}
if ( V_6 -> V_13 > 0 )
F_17 ( & V_9 -> V_15 , F_7 ,
( unsigned long ) V_9 ) ;
F_18 ( & V_9 -> V_36 , & V_37 ) ;
V_29:
F_19 ( & V_27 ) ;
V_6 -> V_10 = V_9 ;
return 0 ;
V_35:
F_20 ( V_9 -> V_33 ) ;
V_34:
F_20 ( V_9 ) ;
V_32:
F_19 ( & V_27 ) ;
return V_24 ;
}
static void F_21 ( const struct V_38 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 ;
F_12 ( & V_27 ) ;
if ( -- V_9 -> V_28 ) {
F_19 ( & V_27 ) ;
return;
}
F_22 ( & V_9 -> V_36 ) ;
if ( V_6 -> V_13 > 0 )
F_23 ( & V_9 -> V_15 ) ;
F_24 ( & V_9 -> V_16 ) ;
F_19 ( & V_27 ) ;
F_20 ( V_9 -> V_33 ) ;
F_20 ( V_9 ) ;
}
static int T_1 F_25 ( void )
{
return F_26 ( & V_39 ) ;
}
static void T_2 F_27 ( void )
{
F_28 ( & V_39 ) ;
}
