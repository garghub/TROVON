static int F_1 ( const struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_1 -> V_6 ) ;
T_1 V_7 = V_5 -> V_8 . V_7 ;
if ( F_3 ( V_3 , V_9 , F_4 ( V_7 ) ) )
return - V_10 ;
if ( V_5 -> V_11 & V_12 ) {
struct V_13 * V_14 ;
V_14 = F_5 ( V_3 , V_15 ) ;
if ( ! V_14 )
return - V_10 ;
if ( V_5 -> V_11 & V_12 &&
F_6 ( V_3 , V_16 ) )
return - V_10 ;
F_7 ( V_3 , V_14 ) ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_1 , struct V_13 * V_17 ,
struct V_18 * V_19 )
{
struct V_13 * V_14 [ V_20 + 1 ] ;
int V_21 ;
if ( F_9 ( V_17 ) < sizeof( struct V_13 ) )
return - V_22 ;
V_21 = F_10 ( V_14 , V_20 , V_17 , V_23 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_14 [ V_16 ] )
V_19 -> V_11 |= V_12 ;
return 0 ;
}
static struct V_1 * F_11 ( const struct V_24 * V_25 )
{
struct V_26 * V_26 = F_12 ( V_25 -> V_27 ) ;
struct V_13 * V_28 = V_25 -> V_28 ;
struct V_29 * V_6 ;
struct V_1 * V_1 ;
struct V_13 * V_30 ;
int V_21 ;
struct V_18 V_19 = {
. V_31 = true ,
. V_11 = V_32 | V_33 ,
. V_34 = V_35 ,
} ;
if ( ! V_28 ) {
V_21 = - V_22 ;
goto error;
}
V_30 = F_13 ( V_28 , V_9 ) ;
if ( V_30 && F_9 ( V_30 ) == sizeof( V_36 ) ) {
V_19 . V_7 = F_14 ( F_15 ( V_30 ) ) ;
} else {
V_21 = - V_22 ;
goto error;
}
V_1 = F_16 ( 0 , & V_37 , V_25 ) ;
if ( F_17 ( V_1 ) )
return V_1 ;
V_30 = F_13 ( V_28 , V_15 ) ;
if ( V_30 ) {
V_21 = F_8 ( V_1 , V_30 , & V_19 ) ;
if ( V_21 ) {
F_18 ( V_1 ) ;
goto error;
}
}
F_19 () ;
V_6 = F_20 ( V_26 , V_25 -> V_38 , V_39 , & V_19 ) ;
if ( F_17 ( V_6 ) ) {
F_21 () ;
F_18 ( V_1 ) ;
return F_22 ( V_6 ) ;
}
F_23 ( V_6 , V_6 -> V_11 | V_40 ) ;
F_21 () ;
return V_1 ;
error:
return F_24 ( V_21 ) ;
}
static struct V_1 * F_25 ( const struct V_24 * V_25 )
{
struct V_1 * V_1 ;
V_1 = F_11 ( V_25 ) ;
if ( F_17 ( V_1 ) )
return V_1 ;
return F_26 ( V_1 , V_25 -> V_38 ) ;
}
static int T_2 F_27 ( void )
{
return F_28 ( & V_37 ) ;
}
static void T_3 F_29 ( void )
{
F_30 ( & V_37 ) ;
}
