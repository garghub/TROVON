static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
switch ( V_6 -> V_9 ) {
case V_10 :
switch ( V_8 -> type ) {
case V_11 :
F_3 ( V_6 -> V_12 , V_8 -> V_13 ,
V_6 -> V_14 ) ;
break;
case V_15 :
F_4 ( V_6 -> V_16 , V_6 -> V_12 , V_6 -> V_14 ) ;
break;
case V_17 :
F_3 ( V_6 -> V_12 ,
F_5 ( V_8 -> V_13 ) ,
V_6 -> V_14 ) ;
break;
}
break;
case V_18 :
switch ( V_8 -> type ) {
case V_11 :
F_6 ( V_6 -> V_16 , V_6 -> V_12 , V_8 -> V_13 ,
V_6 -> V_14 ) ;
break;
case V_15 :
F_7 ( V_6 -> V_16 , V_6 -> V_12 , V_6 -> V_14 ) ;
break;
case V_17 :
F_6 ( V_6 -> V_16 , V_6 -> V_12 ,
F_8 ( V_8 -> V_13 ) ,
V_6 -> V_14 ) ;
break;
}
break;
}
V_4 -> V_19 . V_20 = V_21 ;
}
static int F_9 ( const struct V_22 * V_23 ,
const struct V_1 * V_2 ,
const struct V_24 * const V_25 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_13 ;
if ( V_25 [ V_26 ] == NULL )
return - V_27 ;
V_8 -> type = F_10 ( F_11 ( V_25 [ V_26 ] ) ) ;
switch ( V_8 -> type ) {
case V_11 :
case V_17 :
if ( V_25 [ V_28 ] == NULL )
return - V_27 ;
V_13 = F_12 ( V_25 [ V_28 ] ) ;
if ( V_8 -> type == V_17 &&
V_13 > V_29 )
return - V_27 ;
V_8 -> V_13 = V_13 ;
break;
case V_15 :
break;
default:
return - V_27 ;
}
return 0 ;
}
static int F_13 ( struct V_30 * V_12 ,
const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_14 ( V_12 , V_26 , F_15 ( V_8 -> type ) ) )
goto V_31;
switch ( V_8 -> type ) {
case V_11 :
case V_17 :
if ( F_16 ( V_12 , V_28 , V_8 -> V_13 ) )
goto V_31;
break;
default:
break;
}
return 0 ;
V_31:
return - 1 ;
}
static int T_1 F_17 ( void )
{
return F_18 ( & V_32 ) ;
}
static void T_2 F_19 ( void )
{
F_20 ( & V_32 ) ;
}
