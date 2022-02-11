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
F_5 ( V_17 , F_6 ( V_11 ) , & V_19 ) ;
if ( V_15 -> V_25 & V_30 )
if ( ( V_19 . V_31 == V_15 -> V_32 ) ^
! ( V_15 -> V_28 & V_30 ) ) {
V_24 = false ;
goto V_29;
}
V_21 = F_7 ( V_19 . V_31 ) ;
if ( F_8 ( ! V_21 ) ) {
V_24 = false ;
goto V_29;
}
V_23 = V_21 -> V_33 ( V_17 , V_11 , & V_19 , V_19 . V_34 , 1 ) ;
if ( F_8 ( V_23 == NULL ) ) {
V_24 = false ;
goto V_29;
}
if ( V_15 -> V_25 & V_35 )
if ( ( V_23 -> V_36 == V_15 -> V_36 ) ^
! ( V_15 -> V_28 & V_35 ) ) {
V_24 = false ;
goto V_37;
}
if ( V_15 -> V_25 & V_38 )
if ( ( V_23 -> V_39 != NULL &&
V_23 -> V_39 -> V_36 == V_15 -> V_40 ) ^
! ( V_15 -> V_28 & V_38 ) ) {
V_24 = false ;
goto V_37;
}
if ( V_15 -> V_25 & V_41 ) {
enum V_42 V_43 ;
struct V_44 * V_45 = F_9 ( V_11 , & V_43 ) ;
if ( V_45 == NULL || F_10 ( V_45 ) ) {
V_24 = false ;
goto V_37;
}
if ( ( V_43 >= V_46 ) ^
! ! ( V_15 -> V_28 & V_41 ) ) {
V_24 = false ;
goto V_37;
}
}
if ( V_15 -> V_25 & V_47 )
if ( ( ( V_23 -> V_48 & V_49 ) == V_15 -> V_50 ) ^
! ( V_15 -> V_28 & V_47 ) ) {
V_24 = false ;
goto V_37;
}
if ( V_15 -> V_25 & V_51 ) {
if ( F_1 ( & V_23 -> V_52 , & V_15 -> V_52 ,
& V_15 -> V_53 , V_17 ) ^
! ( V_15 -> V_28 & V_51 ) ) {
V_24 = false ;
goto V_37;
}
}
V_37:
F_11 ( V_23 ) ;
V_29:
F_12 ( L_1 , V_24 ) ;
return V_24 ;
}
static int F_13 ( const struct V_54 * V_13 )
{
if ( V_13 -> V_17 != V_6
#ifdef F_2
&& V_13 -> V_17 != V_8
#endif
) {
F_14 ( L_2 , V_13 -> V_17 ) ;
return - V_55 ;
}
return 0 ;
}
static int T_2 F_15 ( void )
{
return F_16 ( & V_56 ) ;
}
static void T_3 F_17 ( void )
{
F_18 ( & V_56 ) ;
}
