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
if ( V_9 || V_6 & V_21 )
return F_10 ( V_8 ) . V_22 <= V_23 ;
return V_9 ;
}
static bool F_11 ( const struct V_24 * V_25 )
{
const struct V_26 * V_27 = F_12 ( V_25 ) ;
return V_27 && ( V_27 -> V_28 & V_29 ) ;
}
static bool F_13 ( const struct V_24 * V_25 , struct V_30 * V_31 )
{
const struct V_32 * V_33 ;
const struct V_34 * V_35 ;
struct V_2 V_36 ;
bool V_37 ;
V_33 = V_31 -> V_38 ;
V_37 = V_33 -> V_6 & V_39 ;
if ( F_11 ( V_25 ) )
return true ^ V_37 ;
V_35 = F_14 ( V_25 ) ;
if ( F_2 ( V_35 -> V_40 ) ) {
if ( F_4 ( V_35 -> V_41 ) )
return F_15 ( V_35 -> V_40 ) ^ V_37 ;
}
V_36 . V_42 = V_43 ;
V_36 . V_40 = V_35 -> V_41 ;
V_36 . V_41 = F_1 ( V_35 -> V_40 ) ;
V_36 . V_44 = 0 ;
V_36 . V_45 = V_33 -> V_6 & V_46 ? V_25 -> V_47 : 0 ;
V_36 . V_48 = F_16 ( V_35 -> V_49 ) ;
V_36 . V_50 = V_51 ;
return F_5 ( & V_36 , V_31 -> V_52 , V_33 -> V_6 ) ^ V_37 ;
}
static int F_17 ( const struct V_53 * V_31 )
{
const struct V_32 * V_33 = V_31 -> V_38 ;
unsigned int V_54 = ~ V_55 ;
if ( V_33 -> V_6 & V_54 ) {
F_18 ( L_1 ) ;
return - V_56 ;
}
if ( strcmp ( V_31 -> V_57 , L_2 ) != 0 &&
strcmp ( V_31 -> V_57 , L_3 ) != 0 ) {
F_18 ( L_4
L_5 , V_31 -> V_57 ) ;
return - V_56 ;
}
return 0 ;
}
static int T_4 F_19 ( void )
{
return F_20 ( & V_58 ) ;
}
static void T_5 F_21 ( void )
{
F_22 ( & V_58 ) ;
}
