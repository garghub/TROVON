static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
switch ( F_3 ( V_6 ) ) {
case V_9 :
switch ( V_8 -> type ) {
case V_10 :
F_4 ( V_6 -> V_11 , V_8 -> V_12 ,
F_5 ( V_6 ) ) ;
break;
case V_13 :
F_6 ( F_7 ( V_6 ) , V_6 -> V_11 , F_5 ( V_6 ) ) ;
break;
case V_14 :
F_4 ( V_6 -> V_11 ,
F_8 ( V_8 -> V_12 ) ,
F_5 ( V_6 ) ) ;
break;
}
break;
case V_15 :
switch ( V_8 -> type ) {
case V_10 :
F_9 ( F_7 ( V_6 ) , V_6 -> V_11 ,
V_8 -> V_12 , F_5 ( V_6 ) ) ;
break;
case V_13 :
F_10 ( F_7 ( V_6 ) , V_6 -> V_11 , F_5 ( V_6 ) ) ;
break;
case V_14 :
F_9 ( F_7 ( V_6 ) , V_6 -> V_11 ,
F_11 ( V_8 -> V_12 ) ,
F_5 ( V_6 ) ) ;
break;
}
break;
}
V_4 -> V_16 . V_17 = V_18 ;
}
static int F_12 ( const struct V_19 * V_20 ,
const struct V_1 * V_2 ,
const struct V_21 * const V_22 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_12 , V_23 ;
V_23 = F_13 ( V_20 , V_2 , NULL ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_22 [ V_24 ] == NULL )
return - V_25 ;
V_8 -> type = F_14 ( F_15 ( V_22 [ V_24 ] ) ) ;
switch ( V_8 -> type ) {
case V_10 :
case V_14 :
if ( V_22 [ V_26 ] == NULL )
return - V_25 ;
V_12 = F_16 ( V_22 [ V_26 ] ) ;
if ( V_8 -> type == V_14 &&
V_12 > V_27 )
return - V_25 ;
V_8 -> V_12 = V_12 ;
break;
case V_13 :
break;
default:
return - V_25 ;
}
return 0 ;
}
static int F_17 ( struct V_28 * V_11 ,
const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_18 ( V_11 , V_24 , F_19 ( V_8 -> type ) ) )
goto V_29;
switch ( V_8 -> type ) {
case V_10 :
case V_14 :
if ( F_20 ( V_11 , V_26 , V_8 -> V_12 ) )
goto V_29;
break;
default:
break;
}
return 0 ;
V_29:
return - 1 ;
}
static int T_1 F_21 ( void )
{
return F_22 ( & V_30 ) ;
}
static void T_2 F_23 ( void )
{
F_24 ( & V_30 ) ;
}
