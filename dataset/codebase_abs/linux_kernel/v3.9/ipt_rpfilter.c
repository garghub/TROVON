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
static bool F_11 ( const struct V_23 * V_24 )
{
const struct V_25 * V_26 = F_12 ( V_24 ) ;
return V_26 && ( V_26 -> V_27 & V_28 ) ;
}
static bool F_13 ( const struct V_23 * V_24 , struct V_29 * V_30 )
{
const struct V_31 * V_32 ;
const struct V_33 * V_34 ;
struct V_2 V_35 ;
bool V_36 ;
V_32 = V_30 -> V_37 ;
V_36 = V_32 -> V_6 & V_38 ;
if ( F_11 ( V_24 ) )
return true ^ V_36 ;
V_34 = F_14 ( V_24 ) ;
if ( F_2 ( V_34 -> V_39 ) ) {
if ( F_4 ( V_34 -> V_40 ) )
return F_15 ( V_34 -> V_39 ) ^ V_36 ;
V_35 . V_41 = 0 ;
} else {
V_35 . V_41 = V_42 ;
}
V_35 . V_39 = V_34 -> V_40 ;
V_35 . V_40 = F_1 ( V_34 -> V_39 ) ;
V_35 . V_43 = 0 ;
V_35 . V_44 = V_32 -> V_6 & V_45 ? V_24 -> V_46 : 0 ;
V_35 . V_47 = F_16 ( V_34 -> V_48 ) ;
V_35 . V_49 = V_50 ;
return F_5 ( & V_35 , V_30 -> V_51 , V_32 -> V_6 ) ^ V_36 ;
}
static int F_17 ( const struct V_52 * V_30 )
{
const struct V_31 * V_32 = V_30 -> V_37 ;
unsigned int V_53 = ~ V_54 ;
if ( V_32 -> V_6 & V_53 ) {
F_18 ( L_1 ) ;
return - V_55 ;
}
if ( strcmp ( V_30 -> V_56 , L_2 ) != 0 &&
strcmp ( V_30 -> V_56 , L_3 ) != 0 ) {
F_18 ( L_4
L_5 , V_30 -> V_56 ) ;
return - V_55 ;
}
return 0 ;
}
static int T_4 F_19 ( void )
{
return F_20 ( & V_57 ) ;
}
static void T_5 F_21 ( void )
{
F_22 ( & V_57 ) ;
}
