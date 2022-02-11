static void F_1 ( const struct V_1 * V_2 ,
struct V_3 V_4 [ V_5 + 1 ] ,
const struct V_6 * V_7 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
const struct V_10 * V_11 = V_7 -> V_11 , * V_12 = V_7 -> V_12 ;
struct V_3 * V_13 = & V_4 [ V_9 -> V_14 ] ;
const struct V_15 * V_16 ;
switch ( V_9 -> V_17 ) {
case V_18 :
if ( V_11 == NULL || ( V_16 = F_3 ( V_11 ) ) == NULL )
goto V_19;
break;
case V_20 :
if ( V_12 == NULL || ( V_16 = F_3 ( V_12 ) ) == NULL )
goto V_19;
break;
default:
goto V_12;
}
strncpy ( ( char * ) V_13 -> V_4 , V_16 -> V_21 -> V_22 -> V_23 , sizeof( V_13 -> V_4 ) ) ;
return;
V_12:
return F_4 ( V_2 , V_4 , V_7 ) ;
V_19:
V_4 [ V_24 ] . V_25 = V_26 ;
}
static int F_5 ( const struct V_27 * V_28 ,
const struct V_1 * V_2 ,
const struct V_29 * const V_30 [] )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_19 ;
V_9 -> V_17 = F_6 ( F_7 ( V_30 [ V_31 ] ) ) ;
switch ( V_9 -> V_17 ) {
case V_18 :
case V_20 :
break;
default:
return F_8 ( V_28 , V_2 , V_30 ) ;
}
V_9 -> V_14 = F_6 ( F_7 ( V_30 [ V_32 ] ) ) ;
V_19 = F_9 ( V_9 -> V_14 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_10 ( V_28 , V_9 -> V_14 , NULL , V_33 ) ;
if ( V_19 < 0 )
return V_19 ;
return 0 ;
}
static const struct V_34 *
F_11 ( const struct V_27 * V_28 ,
const struct V_29 * const V_30 [] )
{
if ( V_30 [ V_31 ] == NULL )
return F_12 ( - V_35 ) ;
if ( V_30 [ V_32 ] && V_30 [ V_36 ] )
return F_12 ( - V_35 ) ;
if ( V_30 [ V_32 ] )
return & V_37 ;
if ( V_30 [ V_36 ] )
return & V_38 ;
return F_12 ( - V_35 ) ;
}
static int T_1 F_13 ( void )
{
return F_14 ( & V_39 ) ;
}
static void T_2 F_15 ( void )
{
F_16 ( & V_39 ) ;
}
