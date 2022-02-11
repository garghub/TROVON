static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
T_1 * V_5 , T_2 V_6 , T_1 * V_7 , T_2 V_8 )
{
int V_9 ;
T_2 V_10 ;
T_1 * V_11 ;
V_11 = F_2 ( 6 , V_12 ) ;
if ( ! V_11 )
return - V_13 ;
switch ( V_6 ) {
case 1 :
V_10 = V_5 [ 0 ] << 8 ;
break;
case 2 :
V_10 = V_5 [ 0 ] << 8 ;
V_10 += V_5 [ 1 ] ;
break;
default:
F_3 ( & V_2 -> V_14 -> V_15 , L_1 ,
V_16 , V_6 ) ;
V_9 = - V_17 ;
goto error;
}
V_9 = F_4 ( V_2 -> V_14 , F_5 ( V_2 -> V_14 , 0 ) , V_3 ,
V_18 | V_19 , V_4 << 1 , V_10 ,
V_11 , 6 , V_20 ) ;
F_6 ( V_2 -> V_14 , V_3 ,
( V_18 | V_19 ) , V_4 << 1 , V_10 ,
V_11 , 6 ) ;
if ( V_9 < 0 )
goto error;
switch ( V_3 ) {
case V_21 :
case V_22 :
V_7 [ 0 ] = V_11 [ 4 ] ;
}
error:
F_7 ( V_11 ) ;
return V_9 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_4 ,
T_1 * V_5 , T_2 V_6 , T_1 * V_7 , T_2 V_8 )
{
T_1 V_23 ;
T_1 V_24 = ( V_7 == NULL || V_8 == 0 ) ;
if ( V_24 ) {
V_23 = V_25 ;
} else {
V_23 = V_21 ;
}
return F_1 ( V_2 , V_23 , V_4 , V_5 , V_6 , V_7 , V_8 ) ;
}
static int F_9 ( struct V_26 * V_27 , struct V_28 V_29 [] ,
int V_30 )
{
struct V_1 * V_2 = F_10 ( V_27 ) ;
int V_31 ;
if ( V_30 > 2 )
return - V_17 ;
if ( F_11 ( & V_2 -> V_32 ) < 0 )
return - V_33 ;
for ( V_31 = 0 ; V_31 < V_30 ; V_31 ++ ) {
if ( V_31 + 1 < V_30 && ( V_29 [ V_31 + 1 ] . V_34 & V_35 ) ) {
if ( F_8 ( V_2 , V_29 [ V_31 ] . V_4 , V_29 [ V_31 ] . V_36 ,
V_29 [ V_31 ] . V_37 , V_29 [ V_31 + 1 ] . V_36 ,
V_29 [ V_31 + 1 ] . V_37 ) < 0 )
break;
V_31 ++ ;
} else if ( F_8 ( V_2 , V_29 [ V_31 ] . V_4 , V_29 [ V_31 ] . V_36 ,
V_29 [ V_31 ] . V_37 , NULL , 0 ) < 0 )
break;
}
F_12 ( & V_2 -> V_32 ) ;
return V_31 ;
}
static T_3 F_13 ( struct V_26 * V_38 )
{
return V_39 ;
}
static int F_14 ( struct V_40 * V_27 )
{
V_27 -> V_41 [ 0 ] = F_15 ( V_42 , & V_43 ,
& F_16 ( V_27 ) -> V_44 ) ;
if ( V_27 -> V_41 [ 0 ] == NULL )
return - V_45 ;
return 0 ;
}
static int F_17 ( struct V_40 * V_27 )
{
return F_15 ( V_46 , V_27 -> V_41 [ 0 ] ,
& F_16 ( V_27 ) -> V_44 ,
& V_47 ) == NULL ? - V_45 : 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
return F_19 ( V_2 -> V_14 , 0 , 5 ) ;
}
