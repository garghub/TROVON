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
struct V_17 * V_18 = F_5 ( V_13 -> V_19 ) ;
const T_1 V_20 = V_13 -> V_20 ;
struct V_21 V_22 ;
struct V_23 * V_24 ;
struct V_25 * V_26 ;
bool V_27 = true ;
if ( V_15 -> V_28 == V_29 ) {
V_27 = V_11 -> V_30 ^
! ! ( V_15 -> V_31 & V_29 ) ;
goto V_32;
}
if ( ! V_11 -> V_30 ) {
V_27 = false ;
goto V_32;
}
F_6 ( V_20 , V_11 , true , & V_22 ) ;
if ( V_15 -> V_28 & V_33 )
if ( ( V_22 . V_34 == V_15 -> V_35 ) ^
! ( V_15 -> V_31 & V_33 ) ) {
V_27 = false ;
goto V_32;
}
V_24 = F_7 ( V_22 . V_34 ) ;
if ( F_8 ( ! V_24 ) ) {
V_27 = false ;
goto V_32;
}
V_26 = V_24 -> V_36 ( V_18 , V_20 , V_11 , & V_22 ) ;
if ( F_8 ( V_26 == NULL ) ) {
V_27 = false ;
goto V_32;
}
if ( V_15 -> V_28 & V_37 )
if ( ( V_26 -> V_38 == V_15 -> V_38 ) ^
! ( V_15 -> V_31 & V_37 ) ) {
V_27 = false ;
goto V_39;
}
if ( V_15 -> V_28 & V_40 )
if ( ( V_26 -> V_41 != NULL &&
V_26 -> V_41 -> V_38 == V_15 -> V_42 ) ^
! ( V_15 -> V_31 & V_40 ) ) {
V_27 = false ;
goto V_39;
}
if ( V_15 -> V_28 & V_43 ) {
enum V_44 V_45 ;
struct V_46 * V_47 = F_9 ( V_11 , & V_45 ) ;
if ( V_47 == NULL || F_10 ( V_47 ) ) {
V_27 = false ;
goto V_39;
}
if ( ( V_45 >= V_48 ) ^
! ! ( V_15 -> V_31 & V_43 ) ) {
V_27 = false ;
goto V_39;
}
}
if ( V_15 -> V_28 & V_49 )
if ( ( ( V_26 -> V_50 & V_51 ) == V_15 -> V_52 ) ^
! ( V_15 -> V_31 & V_49 ) ) {
V_27 = false ;
goto V_39;
}
if ( V_15 -> V_28 & V_53 ) {
if ( F_1 ( & V_26 -> V_54 , & V_15 -> V_54 ,
& V_15 -> V_55 , V_20 ) ^
! ( V_15 -> V_31 & V_53 ) ) {
V_27 = false ;
goto V_39;
}
}
V_39:
F_11 ( V_26 ) ;
V_32:
F_12 ( L_1 , V_27 ) ;
return V_27 ;
}
static int F_13 ( const struct V_56 * V_13 )
{
if ( V_13 -> V_20 != V_6
#ifdef F_2
&& V_13 -> V_20 != V_8
#endif
) {
F_14 ( L_2 , V_13 -> V_20 ) ;
return - V_57 ;
}
return 0 ;
}
static int T_2 F_15 ( void )
{
return F_16 ( & V_58 ) ;
}
static void T_3 F_17 ( void )
{
F_18 ( & V_58 ) ;
}
