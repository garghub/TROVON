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
V_7 = F_5 ( V_6 , & V_13 , V_2 , V_4 -> V_14 ) ;
if ( V_7 )
goto V_15;
V_7 = F_6 ( & V_6 -> V_16 , 1 ) ;
if ( V_7 )
goto V_17;
V_7 = F_7 ( V_6 ) ;
if ( V_7 )
goto V_18;
F_8 ( & V_6 -> V_16 ) ;
V_7 = F_9 ( & V_6 -> V_16 , V_4 -> V_14 ) ;
if ( V_7 )
goto V_19;
return 0 ;
V_19:
F_10 ( V_6 ) ;
V_18:
F_11 ( & V_6 -> V_16 ) ;
V_17:
F_12 ( V_6 ) ;
V_15:
F_13 ( V_2 ) ;
V_12:
F_14 ( V_6 ) ;
return V_7 ;
}
static void
F_15 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_16 ( V_2 ) ;
struct V_5 * V_6 = V_21 -> V_22 ;
F_17 ( V_21 ) ;
F_10 ( V_6 ) ;
F_12 ( V_6 ) ;
V_21 -> V_22 = NULL ;
F_14 ( V_6 ) ;
F_18 ( V_21 ) ;
}
static int F_19 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_5 * V_6 = V_21 -> V_22 ;
struct V_23 * V_24 ;
F_20 ( V_21 ) ;
F_21 () ;
F_22 ( V_6 , 1 ) ;
F_23 () ;
F_24 (crtc, &dev->mode_config.crtc_list, head) {
const struct V_25 * V_26 = V_24 -> V_27 ;
if ( V_24 -> V_28 )
(* V_26 -> V_29 )( V_24 ) ;
}
F_25 ( V_6 ) ;
F_26 ( V_6 ) ;
F_27 ( V_6 ) ;
while ( ! F_28 ( V_6 -> V_30 ) ) ;
while ( ! F_28 ( V_6 -> V_31 ) )
F_29 ( V_6 , 1 ) ;
F_30 ( V_2 ) ;
return 0 ;
}
static int F_31 ( struct V_20 * V_21 , bool V_32 )
{
struct V_5 * V_6 = V_21 -> V_22 ;
V_6 -> V_33 -> V_34 = V_35 ;
if ( ! V_32 ) {
F_32 ( V_6 ) ;
F_33 ( V_6 -> V_31 ) ;
}
F_34 ( V_6 ) ;
F_35 ( V_21 ) ;
F_21 () ;
F_22 ( V_6 , 0 ) ;
F_23 () ;
F_36 ( V_21 ) ;
return 0 ;
}
static int F_37 ( struct V_36 * V_21 )
{
struct V_1 * V_2 = F_38 ( V_21 ) ;
struct V_20 * V_37 = F_16 ( V_2 ) ;
int error ;
error = F_19 ( V_37 ) ;
if ( error )
return error ;
F_13 ( V_2 ) ;
F_39 ( V_2 , V_38 ) ;
return 0 ;
}
static int F_40 ( struct V_36 * V_21 )
{
struct V_1 * V_2 = F_38 ( V_21 ) ;
struct V_20 * V_37 = F_16 ( V_2 ) ;
F_39 ( V_2 , V_39 ) ;
F_41 ( V_2 ) ;
if ( F_4 ( V_2 ) ) {
return - V_40 ;
}
return F_31 ( V_37 , false ) ;
}
static int F_42 ( struct V_36 * V_21 )
{
struct V_1 * V_2 = F_38 ( V_21 ) ;
struct V_20 * V_37 = F_16 ( V_2 ) ;
return F_31 ( V_37 , true ) ;
}
static int F_43 ( struct V_36 * V_21 )
{
struct V_1 * V_2 = F_38 ( V_21 ) ;
struct V_20 * V_37 = F_16 ( V_2 ) ;
return F_19 ( V_37 ) ;
}
static int F_44 ( struct V_36 * V_21 )
{
struct V_1 * V_2 = F_38 ( V_21 ) ;
struct V_20 * V_37 = F_16 ( V_2 ) ;
struct V_5 * V_6 = V_37 -> V_22 ;
F_45 ( V_6 ) ;
return F_31 ( V_37 , false ) ;
}
static T_1 F_46 ( struct V_20 * V_21 ,
unsigned int V_41 )
{
return 0 ;
}
static int F_47 ( struct V_20 * V_21 , unsigned int V_41 )
{
return 0 ;
}
static void F_48 ( struct V_20 * V_21 , unsigned int V_41 )
{
}
static int T_2 F_49 ( void )
{
if ( F_50 () && V_42 == - 1 )
return - V_9 ;
if ( V_42 == 0 )
return - V_9 ;
V_13 . V_43 = V_44 ;
return F_51 ( & V_13 , & V_45 ) ;
}
static void T_3 F_52 ( void )
{
F_53 ( & V_13 , & V_45 ) ;
}
