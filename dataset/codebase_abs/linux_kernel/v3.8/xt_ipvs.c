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
const T_1 V_17 = V_13 -> V_17 ;
struct V_18 V_19 ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
bool V_24 = true ;
if ( V_15 -> V_25 == V_26 ) {
V_24 = V_11 -> V_27 ^
! ! ( V_15 -> V_28 & V_26 ) ;
goto V_29;
}
if ( ! V_11 -> V_27 ) {
V_24 = false ;
goto V_29;
}
F_5 ( V_17 , V_11 , & V_19 ) ;
if ( V_15 -> V_25 & V_30 )
if ( ( V_19 . V_31 == V_15 -> V_32 ) ^
! ( V_15 -> V_28 & V_30 ) ) {
V_24 = false ;
goto V_29;
}
V_21 = F_6 ( V_19 . V_31 ) ;
if ( F_7 ( ! V_21 ) ) {
V_24 = false ;
goto V_29;
}
V_23 = V_21 -> V_33 ( V_17 , V_11 , & V_19 , 1 ) ;
if ( F_7 ( V_23 == NULL ) ) {
V_24 = false ;
goto V_29;
}
if ( V_15 -> V_25 & V_34 )
if ( ( V_23 -> V_35 == V_15 -> V_35 ) ^
! ( V_15 -> V_28 & V_34 ) ) {
V_24 = false ;
goto V_36;
}
if ( V_15 -> V_25 & V_37 )
if ( ( V_23 -> V_38 != NULL &&
V_23 -> V_38 -> V_35 == V_15 -> V_39 ) ^
! ( V_15 -> V_28 & V_37 ) ) {
V_24 = false ;
goto V_36;
}
if ( V_15 -> V_25 & V_40 ) {
enum V_41 V_42 ;
struct V_43 * V_44 = F_8 ( V_11 , & V_42 ) ;
if ( V_44 == NULL || F_9 ( V_44 ) ) {
V_24 = false ;
goto V_36;
}
if ( ( V_42 >= V_45 ) ^
! ! ( V_15 -> V_28 & V_40 ) ) {
V_24 = false ;
goto V_36;
}
}
if ( V_15 -> V_25 & V_46 )
if ( ( ( V_23 -> V_47 & V_48 ) == V_15 -> V_49 ) ^
! ( V_15 -> V_28 & V_46 ) ) {
V_24 = false ;
goto V_36;
}
if ( V_15 -> V_25 & V_50 ) {
if ( F_1 ( & V_23 -> V_51 , & V_15 -> V_51 ,
& V_15 -> V_52 , V_17 ) ^
! ( V_15 -> V_28 & V_50 ) ) {
V_24 = false ;
goto V_36;
}
}
V_36:
F_10 ( V_23 ) ;
V_29:
F_11 ( L_1 , V_24 ) ;
return V_24 ;
}
static int F_12 ( const struct V_53 * V_13 )
{
if ( V_13 -> V_17 != V_6
#ifdef F_2
&& V_13 -> V_17 != V_8
#endif
) {
F_13 ( L_2 , V_13 -> V_17 ) ;
return - V_54 ;
}
return 0 ;
}
static int T_2 F_14 ( void )
{
return F_15 ( & V_55 ) ;
}
static void T_3 F_16 ( void )
{
F_17 ( & V_55 ) ;
}
