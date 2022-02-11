static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
switch ( F_3 ( V_6 ) ) {
case V_9 :
switch ( V_8 -> V_10 ) {
case V_11 :
case V_12 :
return F_4 ( V_2 , V_4 , V_6 ) ;
case V_13 :
return F_5 ( V_2 , V_4 , V_6 ) ;
}
break;
case V_14 :
switch ( V_8 -> V_10 ) {
case V_11 :
case V_12 :
return F_6 ( V_2 , V_4 , V_6 ) ;
case V_13 :
return F_7 ( V_2 , V_4 , V_6 ) ;
}
break;
}
V_4 -> V_15 . V_16 = V_17 ;
}
static int T_1 F_8 ( void )
{
return F_9 ( & V_18 ) ;
}
static void T_2 F_10 ( void )
{
F_11 ( & V_18 ) ;
}
