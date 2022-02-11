static inline void F_1 ( void ) {}
static inline void F_2 ( void ) {}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 * V_4 = V_2 -> V_5 ;
if ( ( V_4 -> V_6 & V_7 ) >= V_8 )
return 0 ;
if ( ( V_4 -> V_6 & V_7 ) >= V_9 )
F_4 ( V_10 , 0 ) ;
F_4 ( V_11 , 0 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
T_2 * V_4 = V_2 -> V_5 ;
if ( ( V_4 -> V_6 & V_7 ) >= V_8 )
return 0 ;
if ( ( V_4 -> V_6 & V_7 ) >= V_9 )
F_4 ( V_10 , V_4 -> V_12 ) ;
F_4 ( V_11 , V_4 -> V_13 ) ;
return 0 ;
}
static int F_6 ( struct V_14 * V_15 )
{
struct V_16 * V_17 ;
bool V_18 = false ;
V_17 = F_7 ( 1 ) ;
if ( ! V_17 )
return - V_19 ;
V_17 -> V_20 [ 0 ] . V_21 = F_8 ( V_15 , 0 ) ;
V_17 -> V_20 [ 0 ] . V_22 = F_9 ( V_15 , 0 ) ;
#ifdef F_10
V_18 = V_15 -> V_23 [ V_24 ] . V_6 & V_25 ;
#endif
F_11 ( V_17 , L_1 , V_18 ) ;
F_12 ( V_17 ) ;
return 0 ;
}
static int F_13 ( struct V_14 * V_15 ,
const struct V_26 * V_27 )
{
int V_28 ;
V_28 = F_6 ( V_15 ) ;
if ( V_28 )
return V_28 ;
return F_14 ( V_15 , V_27 , & V_29 ) ;
}
static void
F_15 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_16 ( V_15 ) ;
F_17 ( V_2 ) ;
}
static int F_18 ( struct V_30 * V_2 )
{
struct V_14 * V_15 = F_19 ( V_2 ) ;
struct V_1 * V_31 = F_16 ( V_15 ) ;
return F_20 ( V_31 , true , true ) ;
}
static int F_21 ( struct V_30 * V_2 )
{
struct V_14 * V_15 = F_19 ( V_2 ) ;
struct V_1 * V_31 = F_16 ( V_15 ) ;
return F_22 ( V_31 , true , true ) ;
}
static int F_23 ( struct V_30 * V_2 )
{
struct V_14 * V_15 = F_19 ( V_2 ) ;
struct V_1 * V_31 = F_16 ( V_15 ) ;
return F_20 ( V_31 , false , true ) ;
}
static int F_24 ( struct V_30 * V_2 )
{
struct V_14 * V_15 = F_19 ( V_2 ) ;
struct V_1 * V_31 = F_16 ( V_15 ) ;
return F_22 ( V_31 , false , true ) ;
}
static int F_25 ( struct V_30 * V_2 )
{
struct V_14 * V_15 = F_19 ( V_2 ) ;
struct V_1 * V_31 = F_16 ( V_15 ) ;
int V_28 ;
if ( ! F_26 ( V_31 ) ) {
F_27 ( V_2 ) ;
return - V_32 ;
}
V_31 -> V_33 = V_34 ;
F_28 ( V_31 ) ;
F_29 ( V_15 , V_35 ) ;
V_28 = F_20 ( V_31 , false , false ) ;
F_30 ( V_15 ) ;
F_31 ( V_15 ) ;
F_32 ( V_15 , V_36 ) ;
V_31 -> V_33 = V_37 ;
return 0 ;
}
static int F_33 ( struct V_30 * V_2 )
{
struct V_14 * V_15 = F_19 ( V_2 ) ;
struct V_1 * V_31 = F_16 ( V_15 ) ;
int V_28 ;
if ( ! F_26 ( V_31 ) )
return - V_38 ;
V_31 -> V_33 = V_34 ;
F_32 ( V_15 , V_39 ) ;
F_34 ( V_15 ) ;
V_28 = F_35 ( V_15 ) ;
if ( V_28 )
return V_28 ;
F_36 ( V_15 ) ;
V_28 = F_22 ( V_31 , false , false ) ;
F_37 ( V_31 ) ;
F_29 ( V_15 , V_40 ) ;
V_31 -> V_33 = V_41 ;
return 0 ;
}
static int F_38 ( struct V_30 * V_2 )
{
struct V_14 * V_15 = F_19 ( V_2 ) ;
struct V_1 * V_31 = F_16 ( V_15 ) ;
struct V_42 * V_43 ;
if ( ! F_26 ( V_31 ) ) {
F_27 ( V_2 ) ;
return - V_32 ;
}
F_39 (crtc, &drm_dev->mode_config.crtc_list, head) {
if ( V_43 -> V_44 ) {
F_40 ( L_2 ) ;
return - V_32 ;
}
}
F_41 ( V_2 ) ;
F_42 ( V_2 ) ;
return 1 ;
}
long F_43 ( struct V_45 * V_46 ,
unsigned int V_47 , unsigned long V_48 )
{
struct V_49 * V_50 = V_46 -> V_51 ;
struct V_1 * V_2 ;
long V_28 ;
V_2 = V_50 -> V_52 -> V_2 ;
V_28 = F_44 ( V_2 -> V_2 ) ;
if ( V_28 < 0 )
return V_28 ;
V_28 = F_45 ( V_46 , V_47 , V_48 ) ;
F_41 ( V_2 -> V_2 ) ;
F_46 ( V_2 -> V_2 ) ;
return V_28 ;
}
static int T_3 F_47 ( void )
{
#ifdef F_48
if ( F_49 () && V_53 == - 1 ) {
F_50 ( L_3 ) ;
V_53 = 0 ;
}
#endif
if ( V_53 == - 1 )
V_53 = 1 ;
if ( V_53 == 1 ) {
F_50 ( L_4 ) ;
V_54 = & V_29 ;
V_55 = & V_56 ;
V_54 -> V_57 |= V_58 ;
V_54 -> V_59 = V_60 ;
F_1 () ;
} else {
#ifdef F_51
F_50 ( L_5 ) ;
V_54 = & V_61 ;
V_55 = & V_62 ;
V_54 -> V_57 &= ~ V_58 ;
V_54 -> V_59 = V_63 ;
#else
F_52 ( L_6 ) ;
return - V_38 ;
#endif
}
return F_53 ( V_54 , V_55 ) ;
}
static void T_4 F_54 ( void )
{
F_55 ( V_54 , V_55 ) ;
F_2 () ;
}
