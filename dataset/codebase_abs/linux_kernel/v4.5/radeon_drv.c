static inline void F_1 ( void ) {}
static inline void F_2 ( void ) {}
static int F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
bool V_5 = false ;
V_4 = F_4 ( 1 ) ;
if ( ! V_4 )
return - V_6 ;
V_4 -> V_7 [ 0 ] . V_8 = F_5 ( V_2 , 0 ) ;
V_4 -> V_7 [ 0 ] . V_9 = F_6 ( V_2 , 0 ) ;
#ifdef F_7
V_5 = V_2 -> V_10 [ V_11 ] . V_12 & V_13 ;
#endif
F_8 ( V_4 , L_1 , V_5 ) ;
F_9 ( V_4 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
const struct V_14 * V_15 )
{
int V_16 ;
V_16 = F_3 ( V_2 ) ;
if ( V_16 )
return V_16 ;
return F_11 ( V_2 , V_15 , & V_17 ) ;
}
static void
F_12 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_13 ( V_2 ) ;
F_14 ( V_19 ) ;
}
static int F_15 ( struct V_20 * V_19 )
{
struct V_1 * V_2 = F_16 ( V_19 ) ;
struct V_18 * V_21 = F_13 ( V_2 ) ;
return F_17 ( V_21 , true , true ) ;
}
static int F_18 ( struct V_20 * V_19 )
{
struct V_1 * V_2 = F_16 ( V_19 ) ;
struct V_18 * V_21 = F_13 ( V_2 ) ;
return F_19 ( V_21 , true , true ) ;
}
static int F_20 ( struct V_20 * V_19 )
{
struct V_1 * V_2 = F_16 ( V_19 ) ;
struct V_18 * V_21 = F_13 ( V_2 ) ;
return F_17 ( V_21 , false , true ) ;
}
static int F_21 ( struct V_20 * V_19 )
{
struct V_1 * V_2 = F_16 ( V_19 ) ;
struct V_18 * V_21 = F_13 ( V_2 ) ;
return F_19 ( V_21 , false , true ) ;
}
static int F_22 ( struct V_20 * V_19 )
{
struct V_1 * V_2 = F_16 ( V_19 ) ;
struct V_18 * V_21 = F_13 ( V_2 ) ;
int V_16 ;
if ( ! F_23 ( V_21 ) ) {
F_24 ( V_19 ) ;
return - V_22 ;
}
V_21 -> V_23 = V_24 ;
F_25 ( V_21 ) ;
F_26 ( V_2 , V_25 ) ;
V_16 = F_17 ( V_21 , false , false ) ;
F_27 ( V_2 ) ;
F_28 ( V_2 ) ;
F_29 ( V_2 ) ;
F_30 ( V_2 , V_26 ) ;
V_21 -> V_23 = V_27 ;
return 0 ;
}
static int F_31 ( struct V_20 * V_19 )
{
struct V_1 * V_2 = F_16 ( V_19 ) ;
struct V_18 * V_21 = F_13 ( V_2 ) ;
int V_16 ;
if ( ! F_23 ( V_21 ) )
return - V_28 ;
V_21 -> V_23 = V_24 ;
F_30 ( V_2 , V_29 ) ;
F_32 ( V_2 ) ;
V_16 = F_33 ( V_2 ) ;
if ( V_16 )
return V_16 ;
F_34 ( V_2 ) ;
V_16 = F_19 ( V_21 , false , false ) ;
F_35 ( V_21 ) ;
F_26 ( V_2 , V_30 ) ;
V_21 -> V_23 = V_31 ;
return 0 ;
}
static int F_36 ( struct V_20 * V_19 )
{
struct V_1 * V_2 = F_16 ( V_19 ) ;
struct V_18 * V_21 = F_13 ( V_2 ) ;
struct V_32 * V_33 ;
if ( ! F_23 ( V_21 ) ) {
F_24 ( V_19 ) ;
return - V_22 ;
}
F_37 (crtc, &drm_dev->mode_config.crtc_list, head) {
if ( V_33 -> V_34 ) {
F_38 ( L_2 ) ;
return - V_22 ;
}
}
F_39 ( V_19 ) ;
F_40 ( V_19 ) ;
return 1 ;
}
long F_41 ( struct V_35 * V_36 ,
unsigned int V_37 , unsigned long V_38 )
{
struct V_39 * V_40 = V_36 -> V_41 ;
struct V_18 * V_19 ;
long V_16 ;
V_19 = V_40 -> V_42 -> V_19 ;
V_16 = F_42 ( V_19 -> V_19 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_43 ( V_36 , V_37 , V_38 ) ;
F_39 ( V_19 -> V_19 ) ;
F_44 ( V_19 -> V_19 ) ;
return V_16 ;
}
static int T_1 F_45 ( void )
{
#ifdef F_46
if ( F_47 () && V_43 == - 1 ) {
F_48 ( L_3 ) ;
V_43 = 0 ;
}
#endif
if ( V_43 == - 1 )
V_43 = 1 ;
if ( V_43 == 1 ) {
F_48 ( L_4 ) ;
V_44 = & V_17 ;
V_45 = & V_46 ;
V_44 -> V_47 |= V_48 ;
V_44 -> V_49 = V_50 ;
F_1 () ;
} else {
F_49 ( L_5 ) ;
return - V_28 ;
}
F_50 () ;
return F_51 ( V_44 , V_45 ) ;
}
static void T_2 F_52 ( void )
{
F_53 () ;
F_54 ( V_44 , V_45 ) ;
F_2 () ;
}
