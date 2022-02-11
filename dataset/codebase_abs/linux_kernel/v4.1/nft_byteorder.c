static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 * V_9 = & V_4 -> V_10 [ V_8 -> V_11 ] ;
T_1 * V_12 = & V_4 -> V_10 [ V_8 -> V_13 ] ;
union { T_1 T_1 ; T_2 T_2 ; } * V_14 , * V_15 ;
unsigned int V_16 ;
V_14 = ( void * ) V_9 ;
V_15 = ( void * ) V_12 ;
switch ( V_8 -> V_17 ) {
case 4 :
switch ( V_8 -> V_18 ) {
case V_19 :
for ( V_16 = 0 ; V_16 < V_8 -> V_20 / 4 ; V_16 ++ )
V_15 [ V_16 ] . T_1 = F_3 ( ( V_21 V_22 ) V_14 [ V_16 ] . T_1 ) ;
break;
case V_23 :
for ( V_16 = 0 ; V_16 < V_8 -> V_20 / 4 ; V_16 ++ )
V_15 [ V_16 ] . T_1 = ( V_21 V_24 ) F_4 ( V_14 [ V_16 ] . T_1 ) ;
break;
}
break;
case 2 :
switch ( V_8 -> V_18 ) {
case V_19 :
for ( V_16 = 0 ; V_16 < V_8 -> V_20 / 2 ; V_16 ++ )
V_15 [ V_16 ] . T_2 = F_5 ( ( V_21 V_25 ) V_14 [ V_16 ] . T_2 ) ;
break;
case V_23 :
for ( V_16 = 0 ; V_16 < V_8 -> V_20 / 2 ; V_16 ++ )
V_15 [ V_16 ] . T_2 = ( V_21 V_26 ) F_6 ( V_14 [ V_16 ] . T_2 ) ;
break;
}
break;
}
}
static int F_7 ( const struct V_27 * V_28 ,
const struct V_1 * V_2 ,
const struct V_29 * const V_30 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_31 ;
if ( V_30 [ V_32 ] == NULL ||
V_30 [ V_33 ] == NULL ||
V_30 [ V_34 ] == NULL ||
V_30 [ V_35 ] == NULL ||
V_30 [ V_36 ] == NULL )
return - V_37 ;
V_8 -> V_18 = F_3 ( F_8 ( V_30 [ V_36 ] ) ) ;
switch ( V_8 -> V_18 ) {
case V_19 :
case V_23 :
break;
default:
return - V_37 ;
}
V_8 -> V_17 = F_3 ( F_8 ( V_30 [ V_35 ] ) ) ;
switch ( V_8 -> V_17 ) {
case 2 :
case 4 :
break;
default:
return - V_37 ;
}
V_8 -> V_11 = F_9 ( V_30 [ V_32 ] ) ;
V_8 -> V_20 = F_3 ( F_8 ( V_30 [ V_34 ] ) ) ;
V_31 = F_10 ( V_8 -> V_11 , V_8 -> V_20 ) ;
if ( V_31 < 0 )
return V_31 ;
V_8 -> V_13 = F_9 ( V_30 [ V_33 ] ) ;
return F_11 ( V_28 , V_8 -> V_13 , NULL ,
V_38 , V_8 -> V_20 ) ;
}
static int F_12 ( struct V_39 * V_40 , const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_13 ( V_40 , V_32 , V_8 -> V_11 ) )
goto V_41;
if ( F_13 ( V_40 , V_33 , V_8 -> V_13 ) )
goto V_41;
if ( F_14 ( V_40 , V_36 , F_4 ( V_8 -> V_18 ) ) )
goto V_41;
if ( F_14 ( V_40 , V_34 , F_4 ( V_8 -> V_20 ) ) )
goto V_41;
if ( F_14 ( V_40 , V_35 , F_4 ( V_8 -> V_17 ) ) )
goto V_41;
return 0 ;
V_41:
return - 1 ;
}
int T_3 F_15 ( void )
{
return F_16 ( & V_42 ) ;
}
void F_17 ( void )
{
F_18 ( & V_42 ) ;
}
