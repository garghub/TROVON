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
case 8 : {
T_3 V_18 ;
switch ( V_8 -> V_19 ) {
case V_20 :
for ( V_16 = 0 ; V_16 < V_8 -> V_21 / 8 ; V_16 ++ ) {
V_18 = F_3 ( ( T_3 * ) & V_9 [ V_16 ] ) ;
F_4 ( V_18 , & V_12 [ V_16 ] ) ;
}
break;
case V_22 :
for ( V_16 = 0 ; V_16 < V_8 -> V_21 / 8 ; V_16 ++ ) {
V_18 = F_5 ( & V_9 [ V_16 ] ) ;
F_6 ( V_18 , ( T_3 * ) & V_12 [ V_16 ] ) ;
}
break;
}
break;
}
case 4 :
switch ( V_8 -> V_19 ) {
case V_20 :
for ( V_16 = 0 ; V_16 < V_8 -> V_21 / 4 ; V_16 ++ )
V_15 [ V_16 ] . T_1 = F_7 ( ( V_23 V_24 ) V_14 [ V_16 ] . T_1 ) ;
break;
case V_22 :
for ( V_16 = 0 ; V_16 < V_8 -> V_21 / 4 ; V_16 ++ )
V_15 [ V_16 ] . T_1 = ( V_23 V_25 ) F_8 ( V_14 [ V_16 ] . T_1 ) ;
break;
}
break;
case 2 :
switch ( V_8 -> V_19 ) {
case V_20 :
for ( V_16 = 0 ; V_16 < V_8 -> V_21 / 2 ; V_16 ++ )
V_15 [ V_16 ] . T_2 = F_9 ( ( V_23 V_26 ) V_14 [ V_16 ] . T_2 ) ;
break;
case V_22 :
for ( V_16 = 0 ; V_16 < V_8 -> V_21 / 2 ; V_16 ++ )
V_15 [ V_16 ] . T_2 = ( V_23 V_27 ) F_10 ( V_14 [ V_16 ] . T_2 ) ;
break;
}
break;
}
}
static int F_11 ( const struct V_28 * V_29 ,
const struct V_1 * V_2 ,
const struct V_30 * const V_31 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_17 , V_21 ;
int V_32 ;
if ( V_31 [ V_33 ] == NULL ||
V_31 [ V_34 ] == NULL ||
V_31 [ V_35 ] == NULL ||
V_31 [ V_36 ] == NULL ||
V_31 [ V_37 ] == NULL )
return - V_38 ;
V_8 -> V_19 = F_7 ( F_12 ( V_31 [ V_37 ] ) ) ;
switch ( V_8 -> V_19 ) {
case V_20 :
case V_22 :
break;
default:
return - V_38 ;
}
V_32 = F_13 ( V_31 [ V_36 ] , V_39 , & V_17 ) ;
if ( V_32 < 0 )
return V_32 ;
V_8 -> V_17 = V_17 ;
switch ( V_8 -> V_17 ) {
case 2 :
case 4 :
case 8 :
break;
default:
return - V_38 ;
}
V_8 -> V_11 = F_14 ( V_31 [ V_33 ] ) ;
V_32 = F_13 ( V_31 [ V_35 ] , V_39 , & V_21 ) ;
if ( V_32 < 0 )
return V_32 ;
V_8 -> V_21 = V_21 ;
V_32 = F_15 ( V_8 -> V_11 , V_8 -> V_21 ) ;
if ( V_32 < 0 )
return V_32 ;
V_8 -> V_13 = F_14 ( V_31 [ V_34 ] ) ;
return F_16 ( V_29 , V_8 -> V_13 , NULL ,
V_40 , V_8 -> V_21 ) ;
}
static int F_17 ( struct V_41 * V_42 , const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_18 ( V_42 , V_33 , V_8 -> V_11 ) )
goto V_43;
if ( F_18 ( V_42 , V_34 , V_8 -> V_13 ) )
goto V_43;
if ( F_19 ( V_42 , V_37 , F_8 ( V_8 -> V_19 ) ) )
goto V_43;
if ( F_19 ( V_42 , V_35 , F_8 ( V_8 -> V_21 ) ) )
goto V_43;
if ( F_19 ( V_42 , V_36 , F_8 ( V_8 -> V_17 ) ) )
goto V_43;
return 0 ;
V_43:
return - 1 ;
}
