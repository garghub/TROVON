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
V_17 = F_1 ( V_2 ) ;
if ( V_17 )
return V_17 ;
return F_10 ( V_2 , V_15 , & V_21 ) ;
}
static void
F_11 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_12 ( V_2 ) ;
F_13 ( V_23 ) ;
}
static int F_14 ( struct V_24 * V_23 )
{
struct V_1 * V_2 = F_15 ( V_23 ) ;
struct V_22 * V_25 = F_12 ( V_2 ) ;
return F_16 ( V_25 , true , true ) ;
}
static int F_17 ( struct V_24 * V_23 )
{
struct V_1 * V_2 = F_15 ( V_23 ) ;
struct V_22 * V_25 = F_12 ( V_2 ) ;
return F_18 ( V_25 , true , true ) ;
}
static int F_19 ( struct V_24 * V_23 )
{
struct V_1 * V_2 = F_15 ( V_23 ) ;
struct V_22 * V_25 = F_12 ( V_2 ) ;
return F_16 ( V_25 , false , true ) ;
}
static int F_20 ( struct V_24 * V_23 )
{
struct V_1 * V_2 = F_15 ( V_23 ) ;
struct V_22 * V_25 = F_12 ( V_2 ) ;
return F_18 ( V_25 , false , true ) ;
}
static int F_21 ( struct V_24 * V_23 )
{
struct V_1 * V_2 = F_15 ( V_23 ) ;
struct V_22 * V_25 = F_12 ( V_2 ) ;
int V_17 ;
if ( ! F_22 ( V_25 ) ) {
F_23 ( V_23 ) ;
return - V_26 ;
}
V_25 -> V_27 = V_28 ;
F_24 ( V_25 ) ;
F_25 ( V_2 , V_29 ) ;
V_17 = F_16 ( V_25 , false , false ) ;
F_26 ( V_2 ) ;
F_27 ( V_2 ) ;
F_28 ( V_2 ) ;
F_29 ( V_2 , V_30 ) ;
V_25 -> V_27 = V_31 ;
return 0 ;
}
static int F_30 ( struct V_24 * V_23 )
{
struct V_1 * V_2 = F_15 ( V_23 ) ;
struct V_22 * V_25 = F_12 ( V_2 ) ;
int V_17 ;
if ( ! F_22 ( V_25 ) )
return - V_32 ;
V_25 -> V_27 = V_28 ;
F_29 ( V_2 , V_33 ) ;
F_31 ( V_2 ) ;
V_17 = F_32 ( V_2 ) ;
if ( V_17 )
return V_17 ;
F_33 ( V_2 ) ;
V_17 = F_18 ( V_25 , false , false ) ;
F_34 ( V_25 ) ;
F_25 ( V_2 , V_34 ) ;
V_25 -> V_27 = V_35 ;
return 0 ;
}
static int F_35 ( struct V_24 * V_23 )
{
struct V_1 * V_2 = F_15 ( V_23 ) ;
struct V_22 * V_25 = F_12 ( V_2 ) ;
struct V_36 * V_37 ;
if ( ! F_22 ( V_25 ) ) {
F_23 ( V_23 ) ;
return - V_26 ;
}
F_36 (crtc, &drm_dev->mode_config.crtc_list, head) {
if ( V_37 -> V_38 ) {
F_37 ( L_4 ) ;
return - V_26 ;
}
}
F_38 ( V_23 ) ;
F_39 ( V_23 ) ;
return 1 ;
}
long F_40 ( struct V_39 * V_40 ,
unsigned int V_41 , unsigned long V_42 )
{
struct V_43 * V_44 = V_40 -> V_45 ;
struct V_22 * V_23 ;
long V_17 ;
V_23 = V_44 -> V_46 -> V_23 ;
V_17 = F_41 ( V_23 -> V_23 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_42 ( V_40 , V_41 , V_42 ) ;
F_38 ( V_23 -> V_23 ) ;
F_43 ( V_23 -> V_23 ) ;
return V_17 ;
}
static int T_1 F_44 ( void )
{
#ifdef F_45
if ( F_46 () ) {
F_47 ( L_5 ) ;
return - V_32 ;
}
#endif
F_9 ( L_6 ) ;
V_47 = & V_21 ;
V_48 = & V_49 ;
V_47 -> V_50 |= V_51 ;
V_47 -> V_52 = V_53 ;
F_48 () ;
return F_49 ( V_47 , V_48 ) ;
}
static void T_2 F_50 ( void )
{
F_51 ( V_47 , V_48 ) ;
F_52 () ;
}
