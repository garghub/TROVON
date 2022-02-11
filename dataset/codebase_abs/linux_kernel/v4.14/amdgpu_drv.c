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
struct V_16 * V_17 ;
unsigned long V_12 = V_15 -> V_18 ;
int V_19 ;
if ( ( V_12 & V_20 ) && ! V_21 ) {
F_9 ( L_2
L_3 ) ;
return - V_22 ;
}
V_19 = F_10 () ;
if ( V_19 == - V_23 )
return V_19 ;
V_19 = F_1 ( V_2 ) ;
if ( V_19 )
return V_19 ;
V_17 = F_11 ( & V_24 , & V_2 -> V_17 ) ;
if ( F_12 ( V_17 ) )
return F_13 ( V_17 ) ;
V_19 = F_14 ( V_2 ) ;
if ( V_19 )
goto V_25;
V_17 -> V_2 = V_2 ;
F_15 ( V_2 , V_17 ) ;
V_19 = F_16 ( V_17 , V_15 -> V_18 ) ;
if ( V_19 )
goto V_26;
return 0 ;
V_26:
F_17 ( V_2 ) ;
V_25:
F_18 ( V_17 ) ;
return V_19 ;
}
static void
F_19 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_20 ( V_2 ) ;
F_21 ( V_17 ) ;
F_18 ( V_17 ) ;
}
static void
F_22 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_20 ( V_2 ) ;
struct V_27 * V_28 = V_17 -> V_29 ;
F_23 ( V_28 ) ;
}
static int F_24 ( struct V_30 * V_17 )
{
struct V_1 * V_2 = F_25 ( V_17 ) ;
struct V_16 * V_31 = F_20 ( V_2 ) ;
return F_26 ( V_31 , true , true ) ;
}
static int F_27 ( struct V_30 * V_17 )
{
struct V_1 * V_2 = F_25 ( V_17 ) ;
struct V_16 * V_31 = F_20 ( V_2 ) ;
if ( F_28 ( V_31 ) ) {
F_29 ( V_17 ) ;
F_30 ( V_17 ) ;
F_31 ( V_17 ) ;
}
return F_32 ( V_31 , true , true ) ;
}
static int F_33 ( struct V_30 * V_17 )
{
struct V_1 * V_2 = F_25 ( V_17 ) ;
struct V_16 * V_31 = F_20 ( V_2 ) ;
return F_26 ( V_31 , false , true ) ;
}
static int F_34 ( struct V_30 * V_17 )
{
struct V_1 * V_2 = F_25 ( V_17 ) ;
struct V_16 * V_31 = F_20 ( V_2 ) ;
return F_32 ( V_31 , false , true ) ;
}
static int F_35 ( struct V_30 * V_17 )
{
struct V_1 * V_2 = F_25 ( V_17 ) ;
struct V_16 * V_31 = F_20 ( V_2 ) ;
return F_26 ( V_31 , true , true ) ;
}
static int F_36 ( struct V_30 * V_17 )
{
struct V_1 * V_2 = F_25 ( V_17 ) ;
struct V_16 * V_31 = F_20 ( V_2 ) ;
return F_32 ( V_31 , false , true ) ;
}
static int F_37 ( struct V_30 * V_17 )
{
struct V_1 * V_2 = F_25 ( V_17 ) ;
struct V_16 * V_31 = F_20 ( V_2 ) ;
int V_19 ;
if ( ! F_28 ( V_31 ) ) {
F_38 ( V_17 ) ;
return - V_32 ;
}
V_31 -> V_33 = V_34 ;
F_39 ( V_31 ) ;
F_40 ( V_2 , V_35 ) ;
V_19 = F_26 ( V_31 , false , false ) ;
F_41 ( V_2 ) ;
F_17 ( V_2 ) ;
F_42 ( V_2 ) ;
if ( F_43 () )
F_44 ( V_2 , V_36 ) ;
else if ( ! F_45 () )
F_44 ( V_2 , V_37 ) ;
V_31 -> V_33 = V_38 ;
return 0 ;
}
static int F_46 ( struct V_30 * V_17 )
{
struct V_1 * V_2 = F_25 ( V_17 ) ;
struct V_16 * V_31 = F_20 ( V_2 ) ;
int V_19 ;
if ( ! F_28 ( V_31 ) )
return - V_39 ;
V_31 -> V_33 = V_34 ;
if ( F_43 () ||
! F_45 () )
F_44 ( V_2 , V_40 ) ;
F_47 ( V_2 ) ;
V_19 = F_14 ( V_2 ) ;
if ( V_19 )
return V_19 ;
F_48 ( V_2 ) ;
V_19 = F_32 ( V_31 , false , false ) ;
F_49 ( V_31 ) ;
F_40 ( V_2 , V_41 ) ;
V_31 -> V_33 = V_42 ;
return 0 ;
}
static int F_50 ( struct V_30 * V_17 )
{
struct V_1 * V_2 = F_25 ( V_17 ) ;
struct V_16 * V_31 = F_20 ( V_2 ) ;
struct V_43 * V_44 ;
if ( ! F_28 ( V_31 ) ) {
F_38 ( V_17 ) ;
return - V_32 ;
}
F_51 (crtc, &drm_dev->mode_config.crtc_list, head) {
if ( V_44 -> V_45 ) {
F_52 ( L_4 ) ;
return - V_32 ;
}
}
F_53 ( V_17 ) ;
F_54 ( V_17 ) ;
return 1 ;
}
long F_55 ( struct V_46 * V_47 ,
unsigned int V_48 , unsigned long V_49 )
{
struct V_50 * V_51 = V_47 -> V_52 ;
struct V_16 * V_17 ;
long V_19 ;
V_17 = V_51 -> V_53 -> V_17 ;
V_19 = F_56 ( V_17 -> V_17 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_57 ( V_47 , V_48 , V_49 ) ;
F_53 ( V_17 -> V_17 ) ;
F_58 ( V_17 -> V_17 ) ;
return V_19 ;
}
static bool
F_59 ( struct V_16 * V_17 , unsigned int V_54 ,
bool V_55 , int * V_56 , int * V_57 ,
T_1 * V_58 , T_1 * V_59 ,
const struct V_60 * V_61 )
{
return F_60 ( V_17 , V_54 , 0 , V_56 , V_57 ,
V_58 , V_59 , V_61 ) ;
}
static int T_2 F_61 ( void )
{
int V_62 ;
V_62 = F_62 () ;
if ( V_62 )
goto V_63;
V_62 = F_63 () ;
if ( V_62 )
goto V_64;
V_62 = F_64 () ;
if ( V_62 )
goto V_65;
if ( F_65 () ) {
F_66 ( L_5 ) ;
return - V_39 ;
}
F_9 ( L_6 ) ;
V_66 = & V_24 ;
V_67 = & V_68 ;
V_66 -> V_69 = V_70 ;
F_67 () ;
return F_68 ( V_67 ) ;
V_65:
F_69 () ;
V_64:
F_70 () ;
V_63:
return V_62 ;
}
static void T_3 F_71 ( void )
{
F_72 () ;
F_73 ( V_67 ) ;
F_74 () ;
F_70 () ;
F_75 () ;
F_69 () ;
}
