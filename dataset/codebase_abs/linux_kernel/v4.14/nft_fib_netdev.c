static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
switch ( F_3 ( V_6 -> V_9 -> V_10 ) ) {
case V_11 :
switch ( V_8 -> V_12 ) {
case V_13 :
case V_14 :
return F_4 ( V_2 , V_4 , V_6 ) ;
case V_15 :
return F_5 ( V_2 , V_4 , V_6 ) ;
}
break;
case V_16 :
switch ( V_8 -> V_12 ) {
case V_13 :
case V_14 :
return F_6 ( V_2 , V_4 , V_6 ) ;
case V_15 :
return F_7 ( V_2 , V_4 , V_6 ) ;
}
break;
}
V_4 -> V_17 . V_18 = V_19 ;
}
static int T_1 F_8 ( void )
{
return F_9 ( & V_20 ) ;
}
static void T_2 F_10 ( void )
{
F_11 ( & V_20 ) ;
}
