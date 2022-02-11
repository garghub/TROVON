static T_1 F_1 ( T_1 V_1 )
{
if ( F_2 ( V_1 ) || F_3 ( V_1 ) ||
F_4 ( V_1 ) )
return 0 ;
return V_1 ;
}
static bool F_5 ( struct V_2 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 , T_2 V_7 )
{
struct V_8 V_9 ;
bool V_10 ;
int T_3 V_11 ;
if ( F_6 ( V_2 , V_4 , & V_9 , V_12 ) )
return false ;
if ( V_9 . type != V_13 ) {
if ( V_9 . type != V_14 || ! ( V_7 & V_15 ) )
return false ;
}
V_10 = false ;
#ifdef F_7
for ( T_3 = 0 ; T_3 < V_9 . V_16 -> V_17 ; T_3 ++ ) {
struct V_18 * V_19 = & V_9 . V_16 -> V_18 [ T_3 ] ;
if ( V_19 -> V_20 == V_6 ) {
V_10 = true ;
break;
}
}
#else
if ( F_8 ( V_9 ) == V_6 )
V_10 = true ;
#endif
return V_10 || V_7 & V_21 ;
}
static bool F_9 ( const struct V_22 * V_23 )
{
const struct V_24 * V_25 = F_10 ( V_23 ) ;
return V_25 && ( V_25 -> V_26 & V_27 ) ;
}
static bool F_11 ( const struct V_22 * V_23 , struct V_28 * V_29 )
{
const struct V_30 * V_31 ;
const struct V_32 * V_33 ;
struct V_3 V_34 ;
bool V_35 ;
V_31 = V_29 -> V_36 ;
V_35 = V_31 -> V_7 & V_37 ;
if ( F_9 ( V_23 ) )
return true ^ V_35 ;
V_33 = F_12 ( V_23 ) ;
if ( F_2 ( V_33 -> V_38 ) ) {
if ( F_4 ( V_33 -> V_39 ) )
return F_13 ( V_33 -> V_38 ) ^ V_35 ;
}
V_34 . V_40 = V_41 ;
V_34 . V_38 = V_33 -> V_39 ;
V_34 . V_39 = F_1 ( V_33 -> V_38 ) ;
V_34 . V_42 = 0 ;
V_34 . V_43 = V_31 -> V_7 & V_44 ? V_23 -> V_45 : 0 ;
V_34 . V_46 = F_14 ( V_33 -> V_47 ) ;
V_34 . V_48 = V_49 ;
return F_5 ( V_29 -> V_2 , & V_34 , V_29 -> V_50 , V_31 -> V_7 ) ^ V_35 ;
}
static int F_15 ( const struct V_51 * V_29 )
{
const struct V_30 * V_31 = V_29 -> V_36 ;
unsigned int V_52 = ~ V_53 ;
if ( V_31 -> V_7 & V_52 ) {
F_16 ( L_1 ) ;
return - V_54 ;
}
if ( strcmp ( V_29 -> V_55 , L_2 ) != 0 &&
strcmp ( V_29 -> V_55 , L_3 ) != 0 ) {
F_16 ( L_4
L_5 , V_29 -> V_55 ) ;
return - V_54 ;
}
return 0 ;
}
static int T_4 F_17 ( void )
{
return F_18 ( & V_56 ) ;
}
static void T_5 F_19 ( void )
{
F_20 ( & V_56 ) ;
}
