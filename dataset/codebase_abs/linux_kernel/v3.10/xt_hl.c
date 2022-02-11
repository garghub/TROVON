static bool F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
const T_1 V_8 = F_2 ( V_2 ) -> V_8 ;
switch ( V_6 -> V_9 ) {
case V_10 :
return V_8 == V_6 -> V_8 ;
case V_11 :
return V_8 != V_6 -> V_8 ;
case V_12 :
return V_8 < V_6 -> V_8 ;
case V_13 :
return V_8 > V_6 -> V_8 ;
}
return false ;
}
static bool F_3 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_14 * V_6 = V_4 -> V_7 ;
const struct V_15 * V_16 = F_4 ( V_2 ) ;
switch ( V_6 -> V_9 ) {
case V_17 :
return V_16 -> V_18 == V_6 -> V_18 ;
case V_19 :
return V_16 -> V_18 != V_6 -> V_18 ;
case V_20 :
return V_16 -> V_18 < V_6 -> V_18 ;
case V_21 :
return V_16 -> V_18 > V_6 -> V_18 ;
}
return false ;
}
static int T_2 F_5 ( void )
{
return F_6 ( V_22 , F_7 ( V_22 ) ) ;
}
static void T_3 F_8 ( void )
{
F_9 ( V_22 , F_7 ( V_22 ) ) ;
}
