static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
const struct V_9 * V_10 = F_3 ( V_6 ) , * V_11 = F_4 ( V_6 ) ;
T_1 * V_12 = & V_4 -> V_13 [ V_8 -> V_14 ] ;
const struct V_15 * V_16 ;
switch ( V_8 -> V_17 ) {
case V_18 :
if ( V_10 == NULL || ( V_16 = F_5 ( V_10 ) ) == NULL )
goto V_19;
break;
case V_20 :
if ( V_11 == NULL || ( V_16 = F_5 ( V_11 ) ) == NULL )
goto V_19;
break;
default:
goto V_11;
}
strncpy ( ( char * ) V_12 , V_16 -> V_21 -> V_22 -> V_23 , V_24 ) ;
return;
V_11:
return F_6 ( V_2 , V_4 , V_6 ) ;
V_19:
V_4 -> V_25 . V_26 = V_27 ;
}
static int F_7 ( const struct V_28 * V_29 ,
const struct V_1 * V_2 ,
const struct V_30 * const V_31 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned int V_32 ;
V_8 -> V_17 = F_8 ( F_9 ( V_31 [ V_33 ] ) ) ;
switch ( V_8 -> V_17 ) {
case V_18 :
case V_20 :
V_32 = V_24 ;
break;
default:
return F_10 ( V_29 , V_2 , V_31 ) ;
}
V_8 -> V_14 = F_11 ( V_31 [ V_34 ] ) ;
return F_12 ( V_29 , V_8 -> V_14 , NULL ,
V_35 , V_32 ) ;
}
static const struct V_36 *
F_13 ( const struct V_28 * V_29 ,
const struct V_30 * const V_31 [] )
{
if ( V_31 [ V_33 ] == NULL )
return F_14 ( - V_37 ) ;
if ( V_31 [ V_34 ] && V_31 [ V_38 ] )
return F_14 ( - V_37 ) ;
if ( V_31 [ V_34 ] )
return & V_39 ;
if ( V_31 [ V_38 ] )
return & V_40 ;
return F_14 ( - V_37 ) ;
}
static int T_2 F_15 ( void )
{
return F_16 ( & V_41 ) ;
}
static void T_3 F_17 ( void )
{
F_18 ( & V_41 ) ;
}
