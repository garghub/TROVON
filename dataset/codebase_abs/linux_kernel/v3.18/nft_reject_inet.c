static void F_1 ( const struct V_1 * V_2 ,
struct V_3 V_4 [ V_5 + 1 ] ,
const struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_10 = F_3 ( ( V_7 -> V_11 != NULL ) ? V_7 -> V_11 : V_7 -> V_12 ) ;
switch ( V_7 -> V_13 -> V_14 ) {
case V_15 :
switch ( V_9 -> type ) {
case V_16 :
F_4 ( V_7 -> V_17 , V_9 -> V_18 ) ;
break;
case V_19 :
F_5 ( V_7 -> V_17 , V_7 -> V_13 -> V_20 ) ;
break;
case V_21 :
F_4 ( V_7 -> V_17 ,
F_6 ( V_9 -> V_18 ) ) ;
break;
}
break;
case V_22 :
switch ( V_9 -> type ) {
case V_16 :
F_7 ( V_10 , V_7 -> V_17 , V_9 -> V_18 ,
V_7 -> V_13 -> V_20 ) ;
break;
case V_19 :
F_8 ( V_10 , V_7 -> V_17 , V_7 -> V_13 -> V_20 ) ;
break;
case V_21 :
F_7 ( V_10 , V_7 -> V_17 ,
F_9 ( V_9 -> V_18 ) ,
V_7 -> V_13 -> V_20 ) ;
break;
}
break;
}
V_4 [ V_23 ] . V_24 = V_25 ;
}
static int F_10 ( const struct V_26 * V_27 ,
const struct V_1 * V_2 ,
const struct V_28 * const V_29 [] )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_18 ;
if ( V_29 [ V_30 ] == NULL )
return - V_31 ;
V_9 -> type = F_11 ( F_12 ( V_29 [ V_30 ] ) ) ;
switch ( V_9 -> type ) {
case V_16 :
case V_21 :
if ( V_29 [ V_32 ] == NULL )
return - V_31 ;
V_18 = F_13 ( V_29 [ V_32 ] ) ;
if ( V_9 -> type == V_21 &&
V_18 > V_33 )
return - V_31 ;
V_9 -> V_18 = V_18 ;
break;
case V_19 :
break;
default:
return - V_31 ;
}
return 0 ;
}
static int F_14 ( struct V_34 * V_17 ,
const struct V_1 * V_2 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( F_15 ( V_17 , V_30 , F_16 ( V_9 -> type ) ) )
goto V_35;
switch ( V_9 -> type ) {
case V_16 :
case V_21 :
if ( F_17 ( V_17 , V_32 , V_9 -> V_18 ) )
goto V_35;
break;
}
return 0 ;
V_35:
return - 1 ;
}
static int T_1 F_18 ( void )
{
return F_19 ( & V_36 ) ;
}
static void T_2 F_20 ( void )
{
F_21 ( & V_36 ) ;
}
