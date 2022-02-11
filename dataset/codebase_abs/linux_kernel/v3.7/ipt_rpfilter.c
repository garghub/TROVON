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
if ( F_7 ( V_10 , V_3 , & V_8 ) )
return false ;
if ( V_8 . type != V_12 ) {
if ( V_8 . type != V_13 || ! ( V_6 & V_14 ) )
return false ;
}
V_9 = false ;
#ifdef F_8
for ( T_3 = 0 ; T_3 < V_8 . V_15 -> V_16 ; T_3 ++ ) {
struct V_17 * V_18 = & V_8 . V_15 -> V_17 [ T_3 ] ;
if ( V_18 -> V_19 == V_5 ) {
V_9 = true ;
break;
}
}
#else
if ( F_9 ( V_8 ) == V_5 )
V_9 = true ;
#endif
if ( V_9 || V_6 & V_20 )
return F_10 ( V_8 ) . V_21 <= V_22 ;
return V_9 ;
}
static bool F_11 ( const struct V_23 * V_24 , struct V_25 * V_26 )
{
const struct V_27 * V_28 ;
const struct V_29 * V_30 ;
struct V_2 V_31 ;
bool V_32 ;
V_28 = V_26 -> V_33 ;
V_32 = V_28 -> V_6 & V_34 ;
if ( V_26 -> V_35 -> V_6 & V_36 )
return true ^ V_32 ;
V_30 = F_12 ( V_24 ) ;
if ( F_2 ( V_30 -> V_37 ) ) {
if ( F_4 ( V_30 -> V_38 ) )
return F_13 ( V_30 -> V_37 ) ^ V_32 ;
V_31 . V_39 = 0 ;
} else {
V_31 . V_39 = V_40 ;
}
V_31 . V_37 = V_30 -> V_38 ;
V_31 . V_38 = F_1 ( V_30 -> V_37 ) ;
V_31 . V_41 = 0 ;
V_31 . V_42 = V_28 -> V_6 & V_43 ? V_24 -> V_44 : 0 ;
V_31 . V_45 = F_14 ( V_30 -> V_46 ) ;
V_31 . V_47 = V_48 ;
return F_5 ( & V_31 , V_26 -> V_35 , V_28 -> V_6 ) ^ V_32 ;
}
static int F_15 ( const struct V_49 * V_26 )
{
const struct V_27 * V_28 = V_26 -> V_33 ;
unsigned int V_50 = ~ V_51 ;
if ( V_28 -> V_6 & V_50 ) {
F_16 ( L_1 ) ;
return - V_52 ;
}
if ( strcmp ( V_26 -> V_53 , L_2 ) != 0 &&
strcmp ( V_26 -> V_53 , L_3 ) != 0 ) {
F_16 ( L_4
L_5 , V_26 -> V_53 ) ;
return - V_52 ;
}
return 0 ;
}
static int T_4 F_17 ( void )
{
return F_18 ( & V_54 ) ;
}
static void T_5 F_19 ( void )
{
F_20 ( & V_54 ) ;
}
