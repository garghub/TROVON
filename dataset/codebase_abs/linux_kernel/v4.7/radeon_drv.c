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
V_16 = F_11 () ;
if ( V_16 == - V_17 )
return V_16 ;
if ( F_12 ( V_18 ) && F_12 ( V_19 ) &&
F_13 () && V_2 != F_14 () &&
! F_15 () )
return - V_17 ;
V_16 = F_3 ( V_2 ) ;
if ( V_16 )
return V_16 ;
return F_16 ( V_2 , V_15 , & V_20 ) ;
}
static void
F_17 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_18 ( V_2 ) ;
F_19 ( V_22 ) ;
}
static int F_20 ( struct V_23 * V_22 )
{
struct V_1 * V_2 = F_21 ( V_22 ) ;
struct V_21 * V_24 = F_18 ( V_2 ) ;
return F_22 ( V_24 , true , true , false ) ;
}
static int F_23 ( struct V_23 * V_22 )
{
struct V_1 * V_2 = F_21 ( V_22 ) ;
struct V_21 * V_24 = F_18 ( V_2 ) ;
return F_24 ( V_24 , true , true ) ;
}
static int F_25 ( struct V_23 * V_22 )
{
struct V_1 * V_2 = F_21 ( V_22 ) ;
struct V_21 * V_24 = F_18 ( V_2 ) ;
return F_22 ( V_24 , false , true , true ) ;
}
static int F_26 ( struct V_23 * V_22 )
{
struct V_1 * V_2 = F_21 ( V_22 ) ;
struct V_21 * V_24 = F_18 ( V_2 ) ;
return F_24 ( V_24 , false , true ) ;
}
static int F_27 ( struct V_23 * V_22 )
{
struct V_1 * V_2 = F_21 ( V_22 ) ;
struct V_21 * V_24 = F_18 ( V_2 ) ;
int V_16 ;
if ( ! F_28 ( V_24 ) ) {
F_29 ( V_22 ) ;
return - V_25 ;
}
V_24 -> V_26 = V_27 ;
F_30 ( V_24 ) ;
F_31 ( V_2 , V_28 ) ;
V_16 = F_22 ( V_24 , false , false , false ) ;
F_32 ( V_2 ) ;
F_33 ( V_2 ) ;
F_34 ( V_2 ) ;
F_35 ( V_2 , V_29 ) ;
V_24 -> V_26 = V_30 ;
return 0 ;
}
static int F_36 ( struct V_23 * V_22 )
{
struct V_1 * V_2 = F_21 ( V_22 ) ;
struct V_21 * V_24 = F_18 ( V_2 ) ;
int V_16 ;
if ( ! F_28 ( V_24 ) )
return - V_31 ;
V_24 -> V_26 = V_27 ;
F_35 ( V_2 , V_32 ) ;
F_37 ( V_2 ) ;
V_16 = F_38 ( V_2 ) ;
if ( V_16 )
return V_16 ;
F_39 ( V_2 ) ;
V_16 = F_24 ( V_24 , false , false ) ;
F_40 ( V_24 ) ;
F_31 ( V_2 , V_33 ) ;
V_24 -> V_26 = V_34 ;
return 0 ;
}
static int F_41 ( struct V_23 * V_22 )
{
struct V_1 * V_2 = F_21 ( V_22 ) ;
struct V_21 * V_24 = F_18 ( V_2 ) ;
struct V_35 * V_36 ;
if ( ! F_28 ( V_24 ) ) {
F_29 ( V_22 ) ;
return - V_25 ;
}
F_42 (crtc, &drm_dev->mode_config.crtc_list, head) {
if ( V_36 -> V_37 ) {
F_43 ( L_2 ) ;
return - V_25 ;
}
}
F_44 ( V_22 ) ;
F_45 ( V_22 ) ;
return 1 ;
}
long F_46 ( struct V_38 * V_39 ,
unsigned int V_40 , unsigned long V_41 )
{
struct V_42 * V_43 = V_39 -> V_44 ;
struct V_21 * V_22 ;
long V_16 ;
V_22 = V_43 -> V_45 -> V_22 ;
V_16 = F_47 ( V_22 -> V_22 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_48 ( V_39 , V_40 , V_41 ) ;
F_44 ( V_22 -> V_22 ) ;
F_49 ( V_22 -> V_22 ) ;
return V_16 ;
}
static int T_1 F_50 ( void )
{
if ( F_51 () && V_46 == - 1 ) {
F_52 ( L_3 ) ;
V_46 = 0 ;
}
if ( V_46 == - 1 )
V_46 = 1 ;
if ( V_46 == 1 ) {
F_52 ( L_4 ) ;
V_47 = & V_20 ;
V_48 = & V_49 ;
V_47 -> V_50 |= V_51 ;
V_47 -> V_52 = V_53 ;
F_1 () ;
} else {
F_53 ( L_5 ) ;
return - V_31 ;
}
return F_54 ( V_47 , V_48 ) ;
}
static void T_2 F_55 ( void )
{
F_56 () ;
F_57 ( V_47 , V_48 ) ;
F_2 () ;
}
