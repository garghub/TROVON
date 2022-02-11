static int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
if ( V_2 -> V_8 < 4 ) {
F_2 ( L_1
L_2 ) ;
return - V_9 ;
}
V_6 = F_3 ( sizeof( struct V_5 ) , V_10 ) ;
if ( ! V_6 )
return - V_11 ;
V_7 = F_4 ( V_2 ) ;
if ( V_7 )
goto V_12;
V_7 = F_5 ( V_6 , & V_13 , V_2 ) ;
if ( V_7 )
goto V_14;
V_7 = F_6 ( V_6 ) ;
if ( V_7 )
goto V_15;
F_7 ( & V_6 -> V_16 ) ;
V_7 = F_8 ( & V_6 -> V_16 , V_4 -> V_17 ) ;
if ( V_7 )
goto V_18;
return 0 ;
V_18:
F_9 ( V_6 ) ;
V_15:
F_10 ( V_6 ) ;
V_14:
F_11 ( V_2 ) ;
V_12:
F_12 ( V_6 ) ;
return V_7 ;
}
static void
F_13 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = F_14 ( V_2 ) ;
struct V_5 * V_6 = V_20 -> V_21 ;
F_15 ( V_20 ) ;
F_9 ( V_6 ) ;
F_10 ( V_6 ) ;
V_20 -> V_21 = NULL ;
F_12 ( V_6 ) ;
F_16 ( V_20 ) ;
}
static int F_17 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_5 * V_6 = V_20 -> V_21 ;
struct V_22 * V_23 ;
F_18 ( V_20 ) ;
F_19 () ;
F_20 ( V_6 , 1 ) ;
F_21 () ;
F_22 (crtc, &dev->mode_config.crtc_list, head) {
const struct V_24 * V_25 = V_23 -> V_26 ;
if ( V_23 -> V_27 )
(* V_25 -> V_28 )( V_23 ) ;
}
F_23 ( V_6 ) ;
F_24 ( V_6 ) ;
F_25 ( V_6 ) ;
while ( ! F_26 ( V_6 -> V_29 ) ) ;
while ( ! F_26 ( V_6 -> V_30 ) )
F_27 ( V_6 , 1 ) ;
F_28 ( V_2 ) ;
return 0 ;
}
static int F_29 ( struct V_19 * V_20 , bool V_31 )
{
struct V_5 * V_6 = V_20 -> V_21 ;
V_6 -> V_32 -> V_33 = V_34 ;
if ( ! V_31 ) {
F_30 ( V_6 ) ;
F_31 ( V_6 -> V_30 ) ;
}
F_32 ( V_6 ) ;
F_33 ( V_20 ) ;
F_19 () ;
F_20 ( V_6 , 0 ) ;
F_21 () ;
F_34 ( V_20 ) ;
return 0 ;
}
static int F_35 ( struct V_35 * V_20 )
{
struct V_1 * V_2 = F_36 ( V_20 ) ;
struct V_19 * V_36 = F_14 ( V_2 ) ;
int error ;
error = F_17 ( V_36 ) ;
if ( error )
return error ;
F_11 ( V_2 ) ;
F_37 ( V_2 , V_37 ) ;
return 0 ;
}
static int F_38 ( struct V_35 * V_20 )
{
struct V_1 * V_2 = F_36 ( V_20 ) ;
struct V_19 * V_36 = F_14 ( V_2 ) ;
F_37 ( V_2 , V_38 ) ;
F_39 ( V_2 ) ;
if ( F_4 ( V_2 ) ) {
return - V_39 ;
}
return F_29 ( V_36 , false ) ;
}
static int F_40 ( struct V_35 * V_20 )
{
struct V_1 * V_2 = F_36 ( V_20 ) ;
struct V_19 * V_36 = F_14 ( V_2 ) ;
return F_29 ( V_36 , true ) ;
}
static int F_41 ( struct V_35 * V_20 )
{
struct V_1 * V_2 = F_36 ( V_20 ) ;
struct V_19 * V_36 = F_14 ( V_2 ) ;
return F_17 ( V_36 ) ;
}
static int F_42 ( struct V_35 * V_20 )
{
struct V_1 * V_2 = F_36 ( V_20 ) ;
struct V_19 * V_36 = F_14 ( V_2 ) ;
struct V_5 * V_6 = V_36 -> V_21 ;
F_43 ( V_6 ) ;
return F_29 ( V_36 , false ) ;
}
static int T_1 F_44 ( void )
{
if ( F_45 () && V_40 == - 1 )
return - V_9 ;
if ( V_40 == 0 )
return - V_9 ;
V_13 . V_41 = V_42 ;
return F_46 ( & V_13 , & V_43 ) ;
}
static void T_2 F_47 ( void )
{
F_48 ( & V_13 , & V_43 ) ;
}
