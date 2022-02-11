static inline void F_1 ( void ) {}
static inline void F_2 ( void ) {}
static inline bool F_3 ( void ) { return false ; }
static inline bool F_4 ( void ) { return false ; }
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
bool V_5 = false ;
V_4 = F_6 ( 1 ) ;
if ( ! V_4 )
return - V_6 ;
V_4 -> V_7 [ 0 ] . V_8 = F_7 ( V_2 , 0 ) ;
V_4 -> V_7 [ 0 ] . V_9 = F_8 ( V_2 , 0 ) ;
#ifdef F_9
V_5 = V_2 -> V_10 [ V_11 ] . V_12 & V_13 ;
#endif
F_10 ( V_4 , L_1 , V_5 ) ;
F_11 ( V_4 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
const struct V_14 * V_15 )
{
int V_16 ;
V_16 = F_13 () ;
if ( V_16 == - V_17 )
return V_16 ;
if ( F_14 ( V_2 ) )
return - V_17 ;
V_16 = F_5 ( V_2 ) ;
if ( V_16 )
return V_16 ;
return F_15 ( V_2 , V_15 , & V_18 ) ;
}
static void
F_16 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = F_17 ( V_2 ) ;
F_18 ( V_20 ) ;
}
static void
F_19 ( struct V_1 * V_2 )
{
if ( F_20 () )
F_16 ( V_2 ) ;
}
static int F_21 ( struct V_21 * V_20 )
{
struct V_1 * V_2 = F_22 ( V_20 ) ;
struct V_19 * V_22 = F_17 ( V_2 ) ;
return F_23 ( V_22 , true , true , false ) ;
}
static int F_24 ( struct V_21 * V_20 )
{
struct V_1 * V_2 = F_22 ( V_20 ) ;
struct V_19 * V_22 = F_17 ( V_2 ) ;
if ( F_25 ( V_22 ) ) {
F_26 ( V_20 ) ;
F_27 ( V_20 ) ;
F_28 ( V_20 ) ;
}
return F_29 ( V_22 , true , true ) ;
}
static int F_30 ( struct V_21 * V_20 )
{
struct V_1 * V_2 = F_22 ( V_20 ) ;
struct V_19 * V_22 = F_17 ( V_2 ) ;
return F_23 ( V_22 , false , true , true ) ;
}
static int F_31 ( struct V_21 * V_20 )
{
struct V_1 * V_2 = F_22 ( V_20 ) ;
struct V_19 * V_22 = F_17 ( V_2 ) ;
return F_29 ( V_22 , false , true ) ;
}
static int F_32 ( struct V_21 * V_20 )
{
struct V_1 * V_2 = F_22 ( V_20 ) ;
struct V_19 * V_22 = F_17 ( V_2 ) ;
int V_16 ;
if ( ! F_25 ( V_22 ) ) {
F_33 ( V_20 ) ;
return - V_23 ;
}
V_22 -> V_24 = V_25 ;
F_34 ( V_22 ) ;
F_35 ( V_2 , V_26 ) ;
V_16 = F_23 ( V_22 , false , false , false ) ;
F_36 ( V_2 ) ;
F_37 ( V_2 ) ;
F_38 ( V_2 ) ;
if ( F_4 () )
F_39 ( V_2 , V_27 ) ;
else if ( ! F_3 () )
F_39 ( V_2 , V_28 ) ;
V_22 -> V_24 = V_29 ;
return 0 ;
}
static int F_40 ( struct V_21 * V_20 )
{
struct V_1 * V_2 = F_22 ( V_20 ) ;
struct V_19 * V_22 = F_17 ( V_2 ) ;
int V_16 ;
if ( ! F_25 ( V_22 ) )
return - V_30 ;
V_22 -> V_24 = V_25 ;
if ( F_4 () ||
! F_3 () )
F_39 ( V_2 , V_31 ) ;
F_41 ( V_2 ) ;
V_16 = F_42 ( V_2 ) ;
if ( V_16 )
return V_16 ;
F_43 ( V_2 ) ;
V_16 = F_29 ( V_22 , false , false ) ;
F_44 ( V_22 ) ;
F_35 ( V_2 , V_32 ) ;
V_22 -> V_24 = V_33 ;
return 0 ;
}
static int F_45 ( struct V_21 * V_20 )
{
struct V_1 * V_2 = F_22 ( V_20 ) ;
struct V_19 * V_22 = F_17 ( V_2 ) ;
struct V_34 * V_35 ;
if ( ! F_25 ( V_22 ) ) {
F_33 ( V_20 ) ;
return - V_23 ;
}
F_46 (crtc, &drm_dev->mode_config.crtc_list, head) {
if ( V_35 -> V_36 ) {
F_47 ( L_2 ) ;
return - V_23 ;
}
}
F_48 ( V_20 ) ;
F_49 ( V_20 ) ;
return 1 ;
}
long F_50 ( struct V_37 * V_38 ,
unsigned int V_39 , unsigned long V_40 )
{
struct V_41 * V_42 = V_38 -> V_43 ;
struct V_19 * V_20 ;
long V_16 ;
V_20 = V_42 -> V_44 -> V_20 ;
V_16 = F_51 ( V_20 -> V_20 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_52 ( V_38 , V_39 , V_40 ) ;
F_48 ( V_20 -> V_20 ) ;
F_53 ( V_20 -> V_20 ) ;
return V_16 ;
}
static int T_1 F_54 ( void )
{
if ( F_55 () && V_45 == - 1 ) {
F_56 ( L_3 ) ;
V_45 = 0 ;
}
if ( V_45 == - 1 )
V_45 = 1 ;
if ( V_45 == 1 ) {
F_56 ( L_4 ) ;
V_46 = & V_18 ;
V_47 = & V_48 ;
V_46 -> V_49 |= V_50 ;
V_46 -> V_51 = V_52 ;
F_1 () ;
} else {
F_57 ( L_5 ) ;
return - V_30 ;
}
return F_58 ( V_46 , V_47 ) ;
}
static void T_2 F_59 ( void )
{
F_60 () ;
F_61 ( V_46 , V_47 ) ;
F_2 () ;
}
