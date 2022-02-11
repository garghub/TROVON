static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_9 = F_3 ( ( V_6 -> V_10 != NULL ) ? V_6 -> V_10 : V_6 -> V_11 ) ;
switch ( V_6 -> V_12 -> V_13 ) {
case V_14 :
switch ( V_8 -> type ) {
case V_15 :
F_4 ( V_6 -> V_16 , V_8 -> V_17 ,
V_6 -> V_12 -> V_18 ) ;
break;
case V_19 :
F_5 ( V_6 -> V_16 , V_6 -> V_12 -> V_18 ) ;
break;
case V_20 :
F_4 ( V_6 -> V_16 ,
F_6 ( V_8 -> V_17 ) ,
V_6 -> V_12 -> V_18 ) ;
break;
}
break;
case V_21 :
switch ( V_8 -> type ) {
case V_15 :
F_7 ( V_9 , V_6 -> V_16 , V_8 -> V_17 ,
V_6 -> V_12 -> V_18 ) ;
break;
case V_19 :
F_8 ( V_9 , V_6 -> V_16 , V_6 -> V_12 -> V_18 ) ;
break;
case V_20 :
F_7 ( V_9 , V_6 -> V_16 ,
F_9 ( V_8 -> V_17 ) ,
V_6 -> V_12 -> V_18 ) ;
break;
}
break;
}
V_4 -> V_22 . V_23 = V_24 ;
}
static int F_10 ( const struct V_25 * V_26 ,
const struct V_1 * V_2 ,
const struct V_27 * const V_28 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_17 ;
if ( V_28 [ V_29 ] == NULL )
return - V_30 ;
V_8 -> type = F_11 ( F_12 ( V_28 [ V_29 ] ) ) ;
switch ( V_8 -> type ) {
case V_15 :
case V_20 :
if ( V_28 [ V_31 ] == NULL )
return - V_30 ;
V_17 = F_13 ( V_28 [ V_31 ] ) ;
if ( V_8 -> type == V_20 &&
V_17 > V_32 )
return - V_30 ;
V_8 -> V_17 = V_17 ;
break;
case V_19 :
break;
default:
return - V_30 ;
}
return 0 ;
}
static int F_14 ( struct V_33 * V_16 ,
const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_15 ( V_16 , V_29 , F_16 ( V_8 -> type ) ) )
goto V_34;
switch ( V_8 -> type ) {
case V_15 :
case V_20 :
if ( F_17 ( V_16 , V_31 , V_8 -> V_17 ) )
goto V_34;
break;
default:
break;
}
return 0 ;
V_34:
return - 1 ;
}
static int T_1 F_18 ( void )
{
return F_19 ( & V_35 ) ;
}
static void T_2 F_20 ( void )
{
F_21 ( & V_35 ) ;
}
