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
static void
F_15 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = F_13 ( V_2 ) ;
struct V_25 * V_26 = V_24 -> V_27 ;
F_16 ( V_26 ) ;
}
static int F_17 ( struct V_28 * V_24 )
{
struct V_1 * V_2 = F_18 ( V_24 ) ;
struct V_23 * V_29 = F_13 ( V_2 ) ;
return F_19 ( V_29 , true , true ) ;
}
static int F_20 ( struct V_28 * V_24 )
{
struct V_1 * V_2 = F_18 ( V_24 ) ;
struct V_23 * V_29 = F_13 ( V_2 ) ;
if ( F_21 ( V_29 ) ) {
F_22 ( V_24 ) ;
F_23 ( V_24 ) ;
F_24 ( V_24 ) ;
}
return F_25 ( V_29 , true , true ) ;
}
static int F_26 ( struct V_28 * V_24 )
{
struct V_1 * V_2 = F_18 ( V_24 ) ;
struct V_23 * V_29 = F_13 ( V_2 ) ;
return F_19 ( V_29 , false , true ) ;
}
static int F_27 ( struct V_28 * V_24 )
{
struct V_1 * V_2 = F_18 ( V_24 ) ;
struct V_23 * V_29 = F_13 ( V_2 ) ;
return F_25 ( V_29 , false , true ) ;
}
static int F_28 ( struct V_28 * V_24 )
{
struct V_1 * V_2 = F_18 ( V_24 ) ;
struct V_23 * V_29 = F_13 ( V_2 ) ;
return F_19 ( V_29 , true , true ) ;
}
static int F_29 ( struct V_28 * V_24 )
{
struct V_1 * V_2 = F_18 ( V_24 ) ;
struct V_23 * V_29 = F_13 ( V_2 ) ;
return F_25 ( V_29 , false , true ) ;
}
static int F_30 ( struct V_28 * V_24 )
{
struct V_1 * V_2 = F_18 ( V_24 ) ;
struct V_23 * V_29 = F_13 ( V_2 ) ;
int V_17 ;
if ( ! F_21 ( V_29 ) ) {
F_31 ( V_24 ) ;
return - V_30 ;
}
V_29 -> V_31 = V_32 ;
F_32 ( V_29 ) ;
F_33 ( V_2 , V_33 ) ;
V_17 = F_19 ( V_29 , false , false ) ;
F_34 ( V_2 ) ;
F_35 ( V_2 ) ;
F_36 ( V_2 ) ;
if ( F_37 () )
F_38 ( V_2 , V_34 ) ;
else if ( ! F_39 () )
F_38 ( V_2 , V_35 ) ;
V_29 -> V_31 = V_36 ;
return 0 ;
}
static int F_40 ( struct V_28 * V_24 )
{
struct V_1 * V_2 = F_18 ( V_24 ) ;
struct V_23 * V_29 = F_13 ( V_2 ) ;
int V_17 ;
if ( ! F_21 ( V_29 ) )
return - V_37 ;
V_29 -> V_31 = V_32 ;
if ( F_37 () ||
! F_39 () )
F_38 ( V_2 , V_38 ) ;
F_41 ( V_2 ) ;
V_17 = F_42 ( V_2 ) ;
if ( V_17 )
return V_17 ;
F_43 ( V_2 ) ;
V_17 = F_25 ( V_29 , false , false ) ;
F_44 ( V_29 ) ;
F_33 ( V_2 , V_39 ) ;
V_29 -> V_31 = V_40 ;
return 0 ;
}
static int F_45 ( struct V_28 * V_24 )
{
struct V_1 * V_2 = F_18 ( V_24 ) ;
struct V_23 * V_29 = F_13 ( V_2 ) ;
struct V_41 * V_42 ;
if ( ! F_21 ( V_29 ) ) {
F_31 ( V_24 ) ;
return - V_30 ;
}
F_46 (crtc, &drm_dev->mode_config.crtc_list, head) {
if ( V_42 -> V_43 ) {
F_47 ( L_4 ) ;
return - V_30 ;
}
}
F_48 ( V_24 ) ;
F_49 ( V_24 ) ;
return 1 ;
}
long F_50 ( struct V_44 * V_45 ,
unsigned int V_46 , unsigned long V_47 )
{
struct V_48 * V_49 = V_45 -> V_50 ;
struct V_23 * V_24 ;
long V_17 ;
V_24 = V_49 -> V_51 -> V_24 ;
V_17 = F_51 ( V_24 -> V_24 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_52 ( V_45 , V_46 , V_47 ) ;
F_48 ( V_24 -> V_24 ) ;
F_53 ( V_24 -> V_24 ) ;
return V_17 ;
}
static int T_1 F_54 ( void )
{
int V_52 ;
V_52 = F_55 () ;
if ( V_52 )
goto V_53;
V_52 = F_56 () ;
if ( V_52 )
goto V_54;
V_52 = F_57 () ;
if ( V_52 )
goto V_55;
if ( F_58 () ) {
F_59 ( L_5 ) ;
return - V_37 ;
}
F_9 ( L_6 ) ;
V_56 = & V_22 ;
V_57 = & V_58 ;
V_56 -> V_59 = V_60 ;
F_60 () ;
return F_61 ( V_56 , V_57 ) ;
V_55:
F_62 () ;
V_54:
F_63 () ;
V_53:
return V_52 ;
}
static void T_2 F_64 ( void )
{
F_65 () ;
F_66 ( V_56 , V_57 ) ;
F_67 () ;
F_63 () ;
F_68 () ;
F_62 () ;
}
