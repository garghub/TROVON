static T_1 F_1 ( T_1 V_1 )
{
if ( F_2 ( V_1 ) || F_3 ( V_1 ) ||
F_4 ( V_1 ) )
return 0 ;
return V_1 ;
}
static bool F_5 ( struct V_2 * V_3 ,
const struct V_4 * V_5 , T_2 V_6 )
{
struct V_7 V_8 ;
bool V_9 ;
struct V_10 * V_10 = F_6 ( V_5 ) ;
int T_3 V_11 ;
if ( F_7 ( V_10 , V_3 , & V_8 , V_12 ) )
return false ;
if ( V_8 . type != V_13 ) {
if ( V_8 . type != V_14 || ! ( V_6 & V_15 ) )
return false ;
}
V_9 = false ;
#ifdef F_8
for ( T_3 = 0 ; T_3 < V_8 . V_16 -> V_17 ; T_3 ++ ) {
struct V_18 * V_19 = & V_8 . V_16 -> V_18 [ T_3 ] ;
if ( V_19 -> V_20 == V_5 ) {
V_9 = true ;
break;
}
}
#else
if ( F_9 ( V_8 ) == V_5 )
V_9 = true ;
#endif
return V_9 || V_6 & V_21 ;
}
static bool F_10 ( const struct V_22 * V_23 )
{
const struct V_24 * V_25 = F_11 ( V_23 ) ;
return V_25 && ( V_25 -> V_26 & V_27 ) ;
}
static bool F_12 ( const struct V_22 * V_23 , struct V_28 * V_29 )
{
const struct V_30 * V_31 ;
const struct V_32 * V_33 ;
struct V_2 V_34 ;
bool V_35 ;
V_31 = V_29 -> V_36 ;
V_35 = V_31 -> V_6 & V_37 ;
if ( F_10 ( V_23 ) )
return true ^ V_35 ;
V_33 = F_13 ( V_23 ) ;
if ( F_2 ( V_33 -> V_38 ) ) {
if ( F_4 ( V_33 -> V_39 ) )
return F_14 ( V_33 -> V_38 ) ^ V_35 ;
}
V_34 . V_40 = V_41 ;
V_34 . V_38 = V_33 -> V_39 ;
V_34 . V_39 = F_1 ( V_33 -> V_38 ) ;
V_34 . V_42 = 0 ;
V_34 . V_43 = V_31 -> V_6 & V_44 ? V_23 -> V_45 : 0 ;
V_34 . V_46 = F_15 ( V_33 -> V_47 ) ;
V_34 . V_48 = V_49 ;
return F_5 ( & V_34 , V_29 -> V_50 , V_31 -> V_6 ) ^ V_35 ;
}
static int F_16 ( const struct V_51 * V_29 )
{
const struct V_30 * V_31 = V_29 -> V_36 ;
unsigned int V_52 = ~ V_53 ;
if ( V_31 -> V_6 & V_52 ) {
F_17 ( L_1 ) ;
return - V_54 ;
}
if ( strcmp ( V_29 -> V_55 , L_2 ) != 0 &&
strcmp ( V_29 -> V_55 , L_3 ) != 0 ) {
F_17 ( L_4
L_5 , V_29 -> V_55 ) ;
return - V_54 ;
}
return 0 ;
}
static int T_4 F_18 ( void )
{
return F_19 ( & V_56 ) ;
}
static void T_5 F_20 ( void )
{
F_21 ( & V_56 ) ;
}
