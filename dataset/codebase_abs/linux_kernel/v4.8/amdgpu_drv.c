static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
bool V_5 = false ;
V_4 = F_2 ( 1 ) ;
if ( ! V_4 )
return - V_6 ;
V_4 -> V_7 [ 0 ] . V_8 = F_3 ( V_2 , 0 ) ;
V_4 -> V_7 [ 0 ] . V_9 = F_4 ( V_2 , 0 ) ;
#ifdef F_5
V_5 = V_2 -> V_10 [ V_11 ] . V_12 & V_13 ;
#endif
F_6 ( V_4 , L_1 , V_5 ) ;
F_7 ( V_4 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
const struct V_14 * V_15 )
{
unsigned long V_12 = V_15 -> V_16 ;
int V_17 ;
if ( ( V_12 & V_18 ) && ! V_19 ) {
F_9 ( L_2
L_3 ) ;
return - V_20 ;
}
V_17 = F_10 () ;
if ( V_17 == - V_21 )
return V_17 ;
V_17 = F_1 ( V_2 ) ;
if ( V_17 )
return V_17 ;
return F_11 ( V_2 , V_15 , & V_22 ) ;
}
static void
F_12 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = F_13 ( V_2 ) ;
F_14 ( V_24 ) ;
}
static int F_15 ( struct V_25 * V_24 )
{
struct V_1 * V_2 = F_16 ( V_24 ) ;
struct V_23 * V_26 = F_13 ( V_2 ) ;
return F_17 ( V_26 , true , true ) ;
}
static int F_18 ( struct V_25 * V_24 )
{
struct V_1 * V_2 = F_16 ( V_24 ) ;
struct V_23 * V_26 = F_13 ( V_2 ) ;
return F_19 ( V_26 , true , true ) ;
}
static int F_20 ( struct V_25 * V_24 )
{
struct V_1 * V_2 = F_16 ( V_24 ) ;
struct V_23 * V_26 = F_13 ( V_2 ) ;
return F_17 ( V_26 , false , true ) ;
}
static int F_21 ( struct V_25 * V_24 )
{
struct V_1 * V_2 = F_16 ( V_24 ) ;
struct V_23 * V_26 = F_13 ( V_2 ) ;
return F_19 ( V_26 , false , true ) ;
}
static int F_22 ( struct V_25 * V_24 )
{
struct V_1 * V_2 = F_16 ( V_24 ) ;
struct V_23 * V_26 = F_13 ( V_2 ) ;
int V_17 ;
if ( ! F_23 ( V_26 ) ) {
F_24 ( V_24 ) ;
return - V_27 ;
}
V_26 -> V_28 = V_29 ;
F_25 ( V_26 ) ;
F_26 ( V_2 , V_30 ) ;
V_17 = F_17 ( V_26 , false , false ) ;
F_27 ( V_2 ) ;
F_28 ( V_2 ) ;
F_29 ( V_2 ) ;
if ( F_30 () )
F_31 ( V_2 , V_31 ) ;
else if ( ! F_32 () )
F_31 ( V_2 , V_32 ) ;
V_26 -> V_28 = V_33 ;
return 0 ;
}
static int F_33 ( struct V_25 * V_24 )
{
struct V_1 * V_2 = F_16 ( V_24 ) ;
struct V_23 * V_26 = F_13 ( V_2 ) ;
int V_17 ;
if ( ! F_23 ( V_26 ) )
return - V_34 ;
V_26 -> V_28 = V_29 ;
if ( F_30 () ||
! F_32 () )
F_31 ( V_2 , V_35 ) ;
F_34 ( V_2 ) ;
V_17 = F_35 ( V_2 ) ;
if ( V_17 )
return V_17 ;
F_36 ( V_2 ) ;
V_17 = F_19 ( V_26 , false , false ) ;
F_37 ( V_26 ) ;
F_26 ( V_2 , V_36 ) ;
V_26 -> V_28 = V_37 ;
return 0 ;
}
static int F_38 ( struct V_25 * V_24 )
{
struct V_1 * V_2 = F_16 ( V_24 ) ;
struct V_23 * V_26 = F_13 ( V_2 ) ;
struct V_38 * V_39 ;
if ( ! F_23 ( V_26 ) ) {
F_24 ( V_24 ) ;
return - V_27 ;
}
F_39 (crtc, &drm_dev->mode_config.crtc_list, head) {
if ( V_39 -> V_40 ) {
F_40 ( L_4 ) ;
return - V_27 ;
}
}
F_41 ( V_24 ) ;
F_42 ( V_24 ) ;
return 1 ;
}
long F_43 ( struct V_41 * V_42 ,
unsigned int V_43 , unsigned long V_44 )
{
struct V_45 * V_46 = V_42 -> V_47 ;
struct V_23 * V_24 ;
long V_17 ;
V_24 = V_46 -> V_48 -> V_24 ;
V_17 = F_44 ( V_24 -> V_24 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_45 ( V_42 , V_43 , V_44 ) ;
F_41 ( V_24 -> V_24 ) ;
F_46 ( V_24 -> V_24 ) ;
return V_17 ;
}
static int T_1 F_47 ( void )
{
F_48 () ;
F_49 () ;
if ( F_50 () ) {
F_51 ( L_5 ) ;
return - V_34 ;
}
F_9 ( L_6 ) ;
V_49 = & V_22 ;
V_50 = & V_51 ;
V_49 -> V_52 = V_53 ;
F_52 () ;
return F_53 ( V_49 , V_50 ) ;
}
static void T_2 F_54 ( void )
{
F_55 () ;
F_56 ( V_49 , V_50 ) ;
F_57 () ;
F_58 () ;
F_59 () ;
}
