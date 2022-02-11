static void F_1 ( const struct V_1 * V_2 ,
struct V_3 V_4 [ V_5 + 1 ] ,
const struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
switch ( V_9 -> type ) {
case V_10 :
F_3 ( V_7 -> V_11 , V_12 , V_9 -> V_13 , 0 ) ;
break;
case V_14 :
break;
}
V_4 [ V_15 ] . V_16 = V_17 ;
}
static int F_4 ( const struct V_18 * V_19 ,
const struct V_1 * V_2 ,
const struct V_20 * const V_21 [] )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_21 [ V_22 ] == NULL )
return - V_23 ;
V_9 -> type = F_5 ( F_6 ( V_21 [ V_22 ] ) ) ;
switch ( V_9 -> type ) {
case V_10 :
if ( V_21 [ V_24 ] == NULL )
return - V_23 ;
V_9 -> V_13 = F_7 ( V_21 [ V_24 ] ) ;
case V_14 :
break;
default:
return - V_23 ;
}
return 0 ;
}
static int F_8 ( struct V_25 * V_11 , const struct V_1 * V_2 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( F_9 ( V_11 , V_22 , F_10 ( V_9 -> type ) ) )
goto V_26;
switch ( V_9 -> type ) {
case V_10 :
if ( F_11 ( V_11 , V_24 , V_9 -> V_13 ) )
goto V_26;
break;
}
return 0 ;
V_26:
return - 1 ;
}
static int T_1 F_12 ( void )
{
return F_13 ( & V_27 ) ;
}
static void T_2 F_14 ( void )
{
F_15 ( & V_27 ) ;
}
