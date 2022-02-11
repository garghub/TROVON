static int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
if ( V_2 -> V_5 < 4 ) {
F_2 ( L_1
L_2 ) ;
return - V_6 ;
}
return F_3 ( V_2 , V_4 , & V_7 ) ;
}
static void
F_4 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
F_6 ( V_9 ) ;
}
static int F_7 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_13 * V_14 ;
F_8 ( V_9 ) ;
F_9 () ;
F_10 ( V_11 , 1 ) ;
F_11 () ;
F_12 (crtc, &dev->mode_config.crtc_list, head) {
const struct V_15 * V_16 = V_14 -> V_17 ;
if ( V_14 -> V_18 )
(* V_16 -> V_19 )( V_14 ) ;
}
F_13 ( V_11 ) ;
F_14 ( V_11 ) ;
F_15 ( V_11 ) ;
while ( ! F_16 ( V_11 -> V_20 ) ) ;
while ( ! F_16 ( V_11 -> V_21 ) )
F_17 ( V_11 , 1 ) ;
F_18 ( V_2 ) ;
return 0 ;
}
static int F_19 ( struct V_8 * V_9 , bool V_22 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
V_11 -> V_23 -> V_24 = V_25 ;
if ( ! V_22 ) {
F_20 ( V_11 ) ;
F_21 ( V_11 -> V_21 ) ;
}
F_22 ( V_11 ) ;
F_23 ( V_9 ) ;
F_9 () ;
F_10 ( V_11 , 0 ) ;
F_11 () ;
F_24 ( V_9 ) ;
return 0 ;
}
static int F_25 ( struct V_26 * V_9 )
{
struct V_1 * V_2 = F_26 ( V_9 ) ;
struct V_8 * V_27 = F_5 ( V_2 ) ;
int error ;
error = F_7 ( V_27 ) ;
if ( error )
return error ;
F_27 ( V_2 ) ;
F_28 ( V_2 , V_28 ) ;
return 0 ;
}
static int F_29 ( struct V_26 * V_9 )
{
struct V_1 * V_2 = F_26 ( V_9 ) ;
struct V_8 * V_27 = F_5 ( V_2 ) ;
F_28 ( V_2 , V_29 ) ;
F_30 ( V_2 ) ;
if ( F_31 ( V_2 ) ) {
return - V_30 ;
}
return F_19 ( V_27 , false ) ;
}
static int F_32 ( struct V_26 * V_9 )
{
struct V_1 * V_2 = F_26 ( V_9 ) ;
struct V_8 * V_27 = F_5 ( V_2 ) ;
return F_19 ( V_27 , true ) ;
}
static int F_33 ( struct V_26 * V_9 )
{
struct V_1 * V_2 = F_26 ( V_9 ) ;
struct V_8 * V_27 = F_5 ( V_2 ) ;
return F_7 ( V_27 ) ;
}
static int F_34 ( struct V_26 * V_9 )
{
struct V_1 * V_2 = F_26 ( V_9 ) ;
struct V_8 * V_27 = F_5 ( V_2 ) ;
struct V_10 * V_11 = V_27 -> V_12 ;
F_35 ( V_11 ) ;
return F_19 ( V_27 , false ) ;
}
static T_1 F_36 ( struct V_8 * V_9 , int V_14 )
{
return V_9 -> V_31 [ V_14 ] . V_32 . V_33 ;
}
static int F_37 ( struct V_8 * V_9 , int V_14 )
{
return 0 ;
}
static void F_38 ( struct V_8 * V_9 , int V_14 )
{
}
static int T_2 F_39 ( void )
{
#ifdef F_40
if ( F_41 () && V_34 == - 1 )
return - V_6 ;
#endif
if ( V_34 == 0 )
return - V_6 ;
V_7 . V_35 = V_36 ;
return F_42 ( & V_7 , & V_37 ) ;
}
static void T_3 F_43 ( void )
{
F_44 ( & V_7 , & V_37 ) ;
}
