static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 * V_4 , T_2 V_5 , T_1 * V_6 , T_2 V_7 )
{
T_2 V_8 ;
T_2 V_9 = V_3 << ( 8 + 1 ) ;
int V_10 = ( V_6 == NULL || V_7 == 0 ) ;
T_1 V_11 , type ;
if ( V_10 ) {
V_11 = V_12 ;
type = V_13 ;
} else {
V_11 = V_14 ;
type = V_15 ;
}
switch ( V_5 ) {
case 1 :
V_8 = V_4 [ 0 ] ;
break;
case 2 :
V_8 = V_4 [ 0 ] ;
V_9 = V_9 + V_4 [ 1 ] ;
break;
default:
F_2 ( & V_2 -> V_16 -> V_17 , L_1 ,
V_18 , V_5 ) ;
return - V_19 ;
}
F_3 ( 1 ) ;
return F_4 ( V_2 -> V_16 , F_5 ( V_2 -> V_16 , 0 ) , V_11 , type ,
V_9 , V_8 , V_6 , V_7 , 2000 ) ;
}
static int F_6 ( struct V_20 * V_21 , struct V_22 V_23 [] ,
int V_24 )
{
struct V_1 * V_2 = F_7 ( V_21 ) ;
int V_25 ;
if ( V_24 > 2 )
return - V_19 ;
if ( F_8 ( & V_2 -> V_26 ) < 0 )
return - V_27 ;
for ( V_25 = 0 ; V_25 < V_24 ; V_25 ++ ) {
if ( V_25 + 1 < V_24 && ( V_23 [ V_25 + 1 ] . V_28 & V_29 ) ) {
if ( F_1 ( V_2 , V_23 [ V_25 ] . V_3 , V_23 [ V_25 ] . V_30 ,
V_23 [ V_25 ] . V_31 , V_23 [ V_25 + 1 ] . V_30 , V_23 [ V_25 + 1 ] . V_31 ) < 0 )
break;
V_25 ++ ;
} else
if ( F_1 ( V_2 , V_23 [ V_25 ] . V_3 , V_23 [ V_25 ] . V_30 ,
V_23 [ V_25 ] . V_31 , NULL , 0 ) < 0 )
break;
}
F_9 ( & V_2 -> V_26 ) ;
return V_25 ;
}
static T_3 F_10 ( struct V_20 * V_32 )
{
return V_33 ;
}
static int F_11 ( struct V_34 * V_21 )
{
V_21 -> V_35 [ 0 ] = F_12 ( V_36 , & V_37 ,
& F_13 ( V_21 ) -> V_38 ) ;
if ( V_21 -> V_35 [ 0 ] == NULL )
return - V_39 ;
return 0 ;
}
static int F_14 ( struct V_34 * V_21 )
{
return F_12 ( V_40 ,
V_21 -> V_35 [ 0 ] , & F_13 ( V_21 ) -> V_38 ,
& V_41 ) == NULL ? - V_42 : 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
return F_16 ( V_2 -> V_16 , 0 , 0 ) ;
}
