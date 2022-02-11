void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
const struct V_9 * V_10 = V_6 -> V_10 ;
T_1 * V_11 = & V_4 -> V_12 [ V_8 -> V_13 ] ;
const struct V_14 * V_15 ;
V_15 = F_3 ( V_10 ) ;
if ( ! V_15 )
goto V_16;
switch ( V_8 -> V_17 ) {
#ifdef F_4
case V_18 :
* V_11 = V_15 -> V_19 ;
break;
#endif
case V_20 :
if ( F_5 ( V_6 ) != V_21 )
goto V_16;
* V_11 = F_6 ( ( const struct V_22 * ) V_15 ,
F_7 ( V_10 ) -> V_23 ) ;
break;
case V_24 :
if ( F_5 ( V_6 ) != V_25 )
goto V_16;
memcpy ( V_11 , F_8 ( (struct V_26 * ) V_15 ,
& F_9 ( V_10 ) -> V_23 ) ,
sizeof( struct V_27 ) ) ;
break;
default:
F_10 ( 1 ) ;
goto V_16;
}
return;
V_16:
V_4 -> V_28 . V_29 = V_30 ;
}
int F_11 ( const struct V_31 * V_32 ,
const struct V_1 * V_2 ,
const struct V_33 * const V_34 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned int V_35 ;
if ( V_34 [ V_36 ] == NULL ||
V_34 [ V_37 ] == NULL )
return - V_38 ;
V_8 -> V_17 = F_12 ( F_13 ( V_34 [ V_36 ] ) ) ;
switch ( V_8 -> V_17 ) {
#ifdef F_4
case V_18 :
#endif
case V_20 :
V_35 = sizeof( T_1 ) ;
break;
case V_24 :
V_35 = sizeof( struct V_27 ) ;
break;
default:
return - V_39 ;
}
V_8 -> V_13 = F_14 ( V_34 [ V_37 ] ) ;
return F_15 ( V_32 , V_8 -> V_13 , NULL ,
V_40 , V_35 ) ;
}
int F_16 ( struct V_9 * V_10 ,
const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_17 ( V_10 , V_36 , F_18 ( V_8 -> V_17 ) ) )
goto V_41;
if ( F_19 ( V_10 , V_37 , V_8 -> V_13 ) )
goto V_41;
return 0 ;
V_41:
return - 1 ;
}
static int T_2 F_20 ( void )
{
return F_21 ( & V_42 ) ;
}
static void T_3 F_22 ( void )
{
F_23 ( & V_42 ) ;
}
