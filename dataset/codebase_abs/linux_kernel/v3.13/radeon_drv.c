static inline void F_1 ( void ) {}
static inline void F_2 ( void ) {}
static inline bool F_3 ( void ) { return false ; }
static int F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 * V_4 = V_2 -> V_5 ;
if ( ( V_4 -> V_6 & V_7 ) >= V_8 )
return 0 ;
if ( ( V_4 -> V_6 & V_7 ) >= V_9 )
F_5 ( V_10 , 0 ) ;
F_5 ( V_11 , 0 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
T_2 * V_4 = V_2 -> V_5 ;
if ( ( V_4 -> V_6 & V_7 ) >= V_8 )
return 0 ;
if ( ( V_4 -> V_6 & V_7 ) >= V_9 )
F_5 ( V_10 , V_4 -> V_12 ) ;
F_5 ( V_11 , V_4 -> V_13 ) ;
return 0 ;
}
static int F_7 ( struct V_14 * V_15 )
{
struct V_16 * V_17 ;
bool V_18 = false ;
V_17 = F_8 ( 1 ) ;
if ( ! V_17 )
return - V_19 ;
V_17 -> V_20 [ 0 ] . V_21 = F_9 ( V_15 , 0 ) ;
V_17 -> V_20 [ 0 ] . V_22 = F_10 ( V_15 , 0 ) ;
#ifdef F_11
V_18 = V_15 -> V_23 [ V_24 ] . V_6 & V_25 ;
#endif
F_12 ( V_17 , L_1 , V_18 ) ;
F_13 ( V_17 ) ;
return 0 ;
}
static int F_14 ( struct V_14 * V_15 ,
const struct V_26 * V_27 )
{
int V_28 ;
V_28 = F_7 ( V_15 ) ;
if ( V_28 )
return V_28 ;
return F_15 ( V_15 , V_27 , & V_29 ) ;
}
static void
F_16 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_17 ( V_15 ) ;
F_18 ( V_2 ) ;
}
static int F_19 ( struct V_30 * V_2 )
{
struct V_14 * V_15 = F_20 ( V_2 ) ;
struct V_1 * V_31 = F_17 ( V_15 ) ;
return F_21 ( V_31 , true , true ) ;
}
static int F_22 ( struct V_30 * V_2 )
{
struct V_14 * V_15 = F_20 ( V_2 ) ;
struct V_1 * V_31 = F_17 ( V_15 ) ;
return F_23 ( V_31 , true , true ) ;
}
static int F_24 ( struct V_30 * V_2 )
{
struct V_14 * V_15 = F_20 ( V_2 ) ;
struct V_1 * V_31 = F_17 ( V_15 ) ;
return F_21 ( V_31 , false , true ) ;
}
static int F_25 ( struct V_30 * V_2 )
{
struct V_14 * V_15 = F_20 ( V_2 ) ;
struct V_1 * V_31 = F_17 ( V_15 ) ;
return F_23 ( V_31 , false , true ) ;
}
static int F_26 ( struct V_30 * V_2 )
{
struct V_14 * V_15 = F_20 ( V_2 ) ;
struct V_1 * V_31 = F_17 ( V_15 ) ;
int V_28 ;
if ( V_32 == 0 )
return - V_33 ;
V_31 -> V_34 = V_35 ;
F_27 ( V_31 ) ;
F_28 ( V_15 , V_36 ) ;
V_28 = F_21 ( V_31 , false , false ) ;
F_29 ( V_15 ) ;
F_30 ( V_15 ) ;
F_31 ( V_15 , V_37 ) ;
V_31 -> V_34 = V_38 ;
return 0 ;
}
static int F_32 ( struct V_30 * V_2 )
{
struct V_14 * V_15 = F_20 ( V_2 ) ;
struct V_1 * V_31 = F_17 ( V_15 ) ;
int V_28 ;
if ( V_32 == 0 )
return - V_33 ;
V_31 -> V_34 = V_35 ;
F_31 ( V_15 , V_39 ) ;
F_33 ( V_15 ) ;
V_28 = F_34 ( V_15 ) ;
if ( V_28 )
return V_28 ;
F_35 ( V_15 ) ;
V_28 = F_23 ( V_31 , false , false ) ;
F_36 ( V_31 ) ;
F_28 ( V_15 , V_40 ) ;
V_31 -> V_34 = V_41 ;
return 0 ;
}
static int F_37 ( struct V_30 * V_2 )
{
struct V_14 * V_15 = F_20 ( V_2 ) ;
struct V_1 * V_31 = F_17 ( V_15 ) ;
struct V_42 * V_43 ;
if ( V_32 == 0 )
return - V_44 ;
if ( V_32 == - 1 && ! F_3 () ) {
F_38 ( L_2 ) ;
return - V_44 ;
}
F_39 (crtc, &drm_dev->mode_config.crtc_list, head) {
if ( V_43 -> V_45 ) {
F_38 ( L_3 ) ;
return - V_44 ;
}
}
F_40 ( V_2 ) ;
F_41 ( V_2 ) ;
return 1 ;
}
long F_42 ( struct V_46 * V_47 ,
unsigned int V_48 , unsigned long V_49 )
{
struct V_50 * V_51 = V_47 -> V_52 ;
struct V_1 * V_2 ;
long V_28 ;
V_2 = V_51 -> V_53 -> V_2 ;
V_28 = F_43 ( V_2 -> V_2 ) ;
if ( V_28 < 0 )
return V_28 ;
V_28 = F_44 ( V_47 , V_48 , V_49 ) ;
F_40 ( V_2 -> V_2 ) ;
F_45 ( V_2 -> V_2 ) ;
return V_28 ;
}
static int T_3 F_46 ( void )
{
#ifdef F_47
if ( F_48 () && V_54 == - 1 ) {
F_49 ( L_4 ) ;
V_54 = 0 ;
}
#endif
if ( V_54 == - 1 )
V_54 = 1 ;
if ( V_54 == 1 ) {
F_49 ( L_5 ) ;
V_55 = & V_29 ;
V_56 = & V_57 ;
V_55 -> V_58 |= V_59 ;
V_55 -> V_60 = V_61 ;
F_1 () ;
} else {
#ifdef F_50
F_49 ( L_6 ) ;
V_55 = & V_62 ;
V_56 = & V_63 ;
V_55 -> V_58 &= ~ V_59 ;
V_55 -> V_60 = V_64 ;
#else
F_51 ( L_7 ) ;
return - V_33 ;
#endif
}
return F_52 ( V_55 , V_56 ) ;
}
static void T_4 F_53 ( void )
{
F_54 ( V_55 , V_56 ) ;
F_2 () ;
}
