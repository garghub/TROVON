static bool F_1 ( const union V_1 * V_2 ,
const union V_1 * V_3 ,
const union V_1 * V_4 ,
unsigned int V_5 )
{
if ( V_5 == V_6 )
return ( ( V_2 -> V_7 ^ V_3 -> V_7 ) & V_4 -> V_7 ) == 0 ;
#ifdef F_2
else if ( V_5 == V_8 )
return F_3 ( & V_2 -> V_9 , & V_4 -> V_9 ,
& V_3 -> V_9 ) == 0 ;
#endif
else
return false ;
}
static bool
F_4 ( const struct V_10 * V_11 , struct V_12 * V_13 )
{
const struct V_14 * V_15 = V_13 -> V_16 ;
struct V_17 * V_18 = F_5 ( F_6 ( V_13 ) ) ;
const T_1 V_19 = F_7 ( V_13 ) ;
struct V_20 V_21 ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
bool V_26 = true ;
if ( V_15 -> V_27 == V_28 ) {
V_26 = V_11 -> V_29 ^
! ! ( V_15 -> V_30 & V_28 ) ;
goto V_31;
}
if ( ! V_11 -> V_29 ) {
V_26 = false ;
goto V_31;
}
F_8 ( V_19 , V_11 , true , & V_21 ) ;
if ( V_15 -> V_27 & V_32 )
if ( ( V_21 . V_33 == V_15 -> V_34 ) ^
! ( V_15 -> V_30 & V_32 ) ) {
V_26 = false ;
goto V_31;
}
V_23 = F_9 ( V_21 . V_33 ) ;
if ( F_10 ( ! V_23 ) ) {
V_26 = false ;
goto V_31;
}
V_25 = V_23 -> V_35 ( V_18 , V_19 , V_11 , & V_21 ) ;
if ( F_10 ( V_25 == NULL ) ) {
V_26 = false ;
goto V_31;
}
if ( V_15 -> V_27 & V_36 )
if ( ( V_25 -> V_37 == V_15 -> V_37 ) ^
! ( V_15 -> V_30 & V_36 ) ) {
V_26 = false ;
goto V_38;
}
if ( V_15 -> V_27 & V_39 )
if ( ( V_25 -> V_40 != NULL &&
V_25 -> V_40 -> V_37 == V_15 -> V_41 ) ^
! ( V_15 -> V_30 & V_39 ) ) {
V_26 = false ;
goto V_38;
}
if ( V_15 -> V_27 & V_42 ) {
enum V_43 V_44 ;
struct V_45 * V_46 = F_11 ( V_11 , & V_44 ) ;
if ( V_46 == NULL ) {
V_26 = false ;
goto V_38;
}
if ( ( V_44 >= V_47 ) ^
! ! ( V_15 -> V_30 & V_42 ) ) {
V_26 = false ;
goto V_38;
}
}
if ( V_15 -> V_27 & V_48 )
if ( ( ( V_25 -> V_49 & V_50 ) == V_15 -> V_51 ) ^
! ( V_15 -> V_30 & V_48 ) ) {
V_26 = false ;
goto V_38;
}
if ( V_15 -> V_27 & V_52 ) {
if ( F_1 ( & V_25 -> V_53 , & V_15 -> V_53 ,
& V_15 -> V_54 , V_19 ) ^
! ( V_15 -> V_30 & V_52 ) ) {
V_26 = false ;
goto V_38;
}
}
V_38:
F_12 ( V_25 ) ;
V_31:
F_13 ( L_1 , V_26 ) ;
return V_26 ;
}
static int F_14 ( const struct V_55 * V_13 )
{
if ( V_13 -> V_19 != V_6
#ifdef F_2
&& V_13 -> V_19 != V_8
#endif
) {
F_15 ( L_2 , V_13 -> V_19 ) ;
return - V_56 ;
}
return 0 ;
}
static int T_2 F_16 ( void )
{
return F_17 ( & V_57 ) ;
}
static void T_3 F_18 ( void )
{
F_19 ( & V_57 ) ;
}
