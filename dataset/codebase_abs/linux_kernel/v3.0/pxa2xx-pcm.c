static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_10 * V_11 = V_2 -> V_9 ;
struct V_12 * V_13 ;
int V_14 ;
V_13 = F_2 ( V_11 -> V_15 , V_2 ) ;
if ( ! V_13 )
return 0 ;
if ( V_8 -> V_4 == NULL ) {
V_8 -> V_4 = V_13 ;
V_14 = F_3 ( V_8 -> V_4 -> V_16 , V_17 ,
V_18 , V_2 ) ;
if ( V_14 < 0 )
return V_14 ;
V_8 -> V_19 = V_14 ;
} else if ( V_8 -> V_4 != V_13 ) {
F_4 ( V_8 -> V_19 ) ;
V_8 -> V_4 = V_13 ;
V_14 = F_3 ( V_8 -> V_4 -> V_16 , V_17 ,
V_18 , V_2 ) ;
if ( V_14 < 0 )
return V_14 ;
V_8 -> V_19 = V_14 ;
}
return F_5 ( V_2 , V_4 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_6 -> V_9 ;
F_7 ( V_2 ) ;
if ( V_8 -> V_19 >= 0 ) {
F_4 ( V_8 -> V_19 ) ;
V_8 -> V_19 = - 1 ;
V_8 -> V_4 = NULL ;
}
return 0 ;
}
static int F_8 ( struct V_20 * V_21 , struct V_22 * V_23 ,
struct V_24 * V_25 )
{
int V_14 = 0 ;
if ( ! V_21 -> V_26 -> V_27 )
V_21 -> V_26 -> V_27 = & V_28 ;
if ( ! V_21 -> V_26 -> V_29 )
V_21 -> V_26 -> V_29 = F_9 ( 32 ) ;
if ( V_25 -> V_30 [ V_31 ] . V_2 ) {
V_14 = F_10 ( V_25 ,
V_31 ) ;
if ( V_14 )
goto V_32;
}
if ( V_25 -> V_30 [ V_33 ] . V_2 ) {
V_14 = F_10 ( V_25 ,
V_33 ) ;
if ( V_14 )
goto V_32;
}
V_32:
return V_14 ;
}
static int T_1 F_11 ( struct V_34 * V_35 )
{
return F_12 ( & V_35 -> V_26 , & V_36 ) ;
}
static int T_2 F_13 ( struct V_34 * V_35 )
{
F_14 ( & V_35 -> V_26 ) ;
return 0 ;
}
static int T_3 F_15 ( void )
{
return F_16 ( & V_37 ) ;
}
static void T_4 F_17 ( void )
{
F_18 ( & V_37 ) ;
}
