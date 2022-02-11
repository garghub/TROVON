static void F_1 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
T_2 V_9 ;
if ( V_4 == V_6 -> V_10 )
return;
if ( ! V_8 -> V_11 )
return;
V_9 = V_8 -> V_11 -> V_9 ;
F_3 ( V_12 > V_13 ) ;
if ( F_4 ( V_9 >= V_13 ) )
return;
switch ( V_4 -> type ) {
case V_14 :
if ( V_4 -> V_15 . V_16 )
break;
return;
case V_17 :
case V_18 :
if ( V_8 -> V_19 )
break;
return;
case V_20 :
if ( V_8 -> V_21 )
break;
return;
case V_22 :
return;
default:
F_4 ( 1 ) ;
return;
}
if ( V_6 -> V_23 [ V_9 ] < 0 )
V_6 -> V_23 [ V_9 ] = V_8 -> V_11 -> V_24 ;
else
F_4 ( V_6 -> V_23 [ V_9 ] != V_8 -> V_11 -> V_24 ) ;
V_6 -> V_25 [ V_9 ] ++ ;
if ( F_5 ( V_8 ) && ! V_6 -> V_26 [ V_9 ] ) {
V_6 -> V_27 ++ ;
V_6 -> V_26 [ V_9 ] = true ;
}
}
static void F_6 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
#ifdef F_7
struct V_7 * V_8 ;
int V_32 , V_33 = - 1 , V_34 = 0 ;
if ( ! V_29 -> V_35 || ! V_29 -> V_36 )
return;
V_8 = F_2 ( V_29 -> V_36 ) ;
if ( ! V_8 -> V_19 )
return;
V_33 = V_8 -> V_11 -> V_9 ;
V_34 = V_29 -> V_36 -> V_15 . V_34 ;
for ( V_32 = 0 ; V_32 < V_13 ; V_32 ++ ) {
T_3 V_37 = F_8 ( V_31 -> V_38 [ V_32 ] . V_39 ) ;
T_3 V_9 = ( V_37 & V_40 ) >> V_41 ;
T_3 V_42 = F_8 ( V_31 -> V_38 [ V_32 ] . V_42 ) ;
if ( V_9 != V_33 )
continue;
V_42 *= ( V_34 - V_29 -> V_35 ) ;
V_42 /= V_34 ;
F_9 ( V_29 , L_1 ,
F_8 ( V_31 -> V_38 [ V_32 ] . V_42 ) , V_42 ) ;
V_31 -> V_38 [ V_32 ] . V_42 = F_10 ( V_42 ) ;
}
#endif
}
int F_11 ( struct V_28 * V_29 ,
bool V_43 ,
struct V_3 * V_10 )
{
struct V_30 V_31 = {} ;
int V_32 , V_44 , V_45 , V_46 , V_42 , V_47 , V_48 ;
struct V_5 V_6 = {
. V_25 = {} ,
. V_23 = { - 1 , - 1 , - 1 , - 1 } ,
. V_10 = V_10 ,
} ;
struct V_30 * V_49 = & V_29 -> V_50 ;
bool V_51 = false ;
F_12 ( & V_29 -> V_52 ) ;
if ( F_13 ( V_53 , & V_29 -> V_54 ) )
return 0 ;
F_3 ( V_13 != 4 ) ;
F_14 (
V_29 -> V_55 , V_56 ,
F_1 , & V_6 ) ;
V_46 = 0 ;
for ( V_32 = 0 ; V_32 < V_13 ; V_32 ++ ) {
V_31 . V_38 [ V_32 ] . V_39 = F_10 ( V_57 ) ;
V_46 += V_6 . V_25 [ V_32 ] ;
}
V_48 = V_46 ;
if ( V_6 . V_27 == 1 ) {
for ( V_32 = 0 ; V_32 < V_13 ; V_32 ++ ) {
if ( V_6 . V_26 [ V_32 ] ) {
V_48 -= V_6 . V_25 [ V_32 ] ;
break;
}
}
}
if ( V_6 . V_27 == 1 && V_48 ) {
V_42 = ( V_58 - V_59 ) / V_48 ;
V_47 = V_58 - V_48 * V_42 -
V_59 ;
F_9 ( V_29 ,
L_2 ,
V_42 ) ;
} else if ( V_46 ) {
V_42 = V_58 / V_46 ;
V_47 = V_58 % V_46 ;
F_9 ( V_29 ,
L_3 ,
V_42 ) ;
} else {
V_42 = 0 ;
V_47 = 0 ;
}
for ( V_44 = 0 , V_32 = 0 ; V_32 < V_13 ; V_32 ++ ) {
if ( V_6 . V_23 [ V_32 ] < 0 )
continue;
V_31 . V_38 [ V_44 ] . V_39 =
F_10 ( F_15 ( V_32 , V_6 . V_23 [ V_32 ] ) ) ;
if ( V_6 . V_25 [ V_32 ] <= 0 )
V_31 . V_38 [ V_44 ] . V_42 = F_10 ( 0 ) ;
else if ( V_6 . V_27 == 1 && V_48 &&
V_6 . V_26 [ V_32 ] )
V_31 . V_38 [ V_44 ] . V_42 = F_10 ( V_59 ) ;
else
V_31 . V_38 [ V_44 ] . V_42 =
F_10 ( V_42 * V_6 . V_25 [ V_32 ] ) ;
F_16 ( F_8 ( V_31 . V_38 [ V_44 ] . V_42 ) > V_58 ,
L_4 ,
V_44 , F_8 ( V_31 . V_38 [ V_44 ] . V_42 ) , V_58 ) ;
V_31 . V_38 [ V_44 ] . V_60 = F_10 ( 0 ) ;
V_44 ++ ;
}
for ( V_32 = 0 ; V_32 < V_13 ; V_32 ++ ) {
if ( F_8 ( V_31 . V_38 [ V_32 ] . V_42 ) != 0 ) {
F_17 ( & V_31 . V_38 [ V_32 ] . V_42 , V_47 ) ;
F_9 ( V_29 ,
L_5 ,
V_47 , V_32 ) ;
break;
}
}
F_6 ( V_29 , & V_31 ) ;
for ( V_32 = 0 ; V_32 < V_13 ; V_32 ++ ) {
if ( V_31 . V_38 [ V_32 ] . V_39 != V_49 -> V_38 [ V_32 ] . V_39 )
V_51 = true ;
if ( V_31 . V_38 [ V_32 ] . V_60 != V_49 -> V_38 [ V_32 ] . V_60 )
V_51 = true ;
if ( abs ( ( int ) F_8 ( V_31 . V_38 [ V_32 ] . V_42 ) -
( int ) F_8 ( V_49 -> V_38 [ V_32 ] . V_42 ) )
> V_61 )
V_51 = true ;
if ( V_31 . V_38 [ V_32 ] . V_39 == F_10 ( V_57 ) )
continue;
F_16 ( V_31 . V_38 [ V_32 ] . V_42 == 0 ,
L_6 , V_32 ) ;
}
if ( ! V_51 && ! V_43 ) {
return 0 ;
}
V_45 = F_18 ( V_29 , V_62 , 0 , sizeof( V_31 ) , & V_31 ) ;
if ( V_45 )
F_19 ( V_29 , L_7 , V_45 ) ;
else
V_29 -> V_50 = V_31 ;
return V_45 ;
}
