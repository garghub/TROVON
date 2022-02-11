static enum V_1 F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 , struct V_4 , V_3 ) ;
struct V_6 * V_7 = V_5 -> V_8 -> V_9 ;
return F_3 ( V_5 -> V_10 , V_7 -> V_5 ) ? V_3 -> V_11 : 0 ;
}
static void F_4 ( struct V_2 * V_3 ,
enum V_1 V_12 )
{
struct V_4 * V_5 = F_2 ( V_3 , struct V_4 , V_3 ) ;
F_5 ( V_5 -> V_8 , V_13 , V_5 -> V_10 , ! ! V_12 ) ;
}
static void F_6 ( struct V_14 * V_8 , unsigned int type ,
unsigned int V_10 , int V_15 )
{
}
static int F_7 ( struct V_6 * V_9 )
{
unsigned int V_16 ;
int V_17 = 0 ;
F_8 (led_code, dev->ledbit, LED_CNT)
if ( V_18 [ V_16 ] . V_19 )
V_17 ++ ;
return V_17 ;
}
static int F_9 ( struct V_20 * V_21 ,
struct V_6 * V_9 ,
const struct V_22 * V_23 )
{
struct V_24 * V_25 ;
unsigned int V_26 ;
unsigned int V_16 ;
int V_27 ;
int error ;
V_26 = F_7 ( V_9 ) ;
if ( ! V_26 )
return - V_28 ;
V_25 = F_10 ( sizeof( * V_25 ) + V_26 * sizeof( * V_25 -> V_25 ) ,
V_29 ) ;
if ( ! V_25 )
return - V_30 ;
V_25 -> V_26 = V_26 ;
V_25 -> V_8 . V_9 = V_9 ;
V_25 -> V_8 . V_21 = V_21 ;
V_25 -> V_8 . V_19 = L_1 ;
V_25 -> V_8 . V_31 = V_25 ;
error = F_11 ( & V_25 -> V_8 ) ;
if ( error )
goto V_32;
error = F_12 ( & V_25 -> V_8 ) ;
if ( error )
goto V_33;
V_27 = 0 ;
F_8 (led_code, dev->ledbit, LED_CNT) {
struct V_4 * V_5 = & V_25 -> V_25 [ V_27 ] ;
V_5 -> V_8 = & V_25 -> V_8 ;
V_5 -> V_10 = V_16 ;
if ( ! V_18 [ V_16 ] . V_19 )
continue;
V_5 -> V_3 . V_19 = F_13 ( V_29 , L_2 ,
F_14 ( & V_9 -> V_9 ) ,
V_18 [ V_16 ] . V_19 ) ;
if ( ! V_5 -> V_3 . V_19 ) {
error = - V_30 ;
goto V_34;
}
V_5 -> V_3 . V_11 = 1 ;
V_5 -> V_3 . V_35 = F_1 ;
V_5 -> V_3 . V_36 = F_4 ;
V_5 -> V_3 . V_37 = V_18 [ V_16 ] . V_38 ;
error = F_15 ( & V_9 -> V_9 , & V_5 -> V_3 ) ;
if ( error ) {
F_16 ( & V_9 -> V_9 , L_3 ,
V_5 -> V_3 . V_19 , error ) ;
F_17 ( V_5 -> V_3 . V_19 ) ;
goto V_34;
}
V_27 ++ ;
}
return 0 ;
V_34:
while ( -- V_27 >= 0 ) {
struct V_4 * V_5 = & V_25 -> V_25 [ V_27 ] ;
F_18 ( & V_5 -> V_3 ) ;
F_17 ( V_5 -> V_3 . V_19 ) ;
}
F_19 ( & V_25 -> V_8 ) ;
V_33:
F_20 ( & V_25 -> V_8 ) ;
V_32:
F_17 ( V_25 ) ;
return error ;
}
static void F_21 ( struct V_14 * V_8 )
{
struct V_24 * V_25 = V_8 -> V_31 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_25 -> V_26 ; V_39 ++ ) {
struct V_4 * V_5 = & V_25 -> V_25 [ V_39 ] ;
F_18 ( & V_5 -> V_3 ) ;
F_17 ( V_5 -> V_3 . V_19 ) ;
}
F_19 ( V_8 ) ;
F_20 ( V_8 ) ;
F_17 ( V_25 ) ;
}
static int T_1 F_22 ( void )
{
return F_23 ( & V_40 ) ;
}
static void T_2 F_24 ( void )
{
F_25 ( & V_40 ) ;
}
