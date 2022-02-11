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
#ifdef F_5
if ( V_8 -> V_26 )
V_6 -> V_27 [ V_9 ] = F_6 ( V_6 -> V_27 [ V_9 ] ,
V_8 -> V_26 ) ;
#endif
if ( F_7 ( V_8 ) && ! V_6 -> V_28 [ V_9 ] ) {
V_6 -> V_29 ++ ;
V_6 -> V_28 [ V_9 ] = true ;
}
}
static void F_8 ( struct V_30 * V_31 ,
struct V_32 * V_33 )
{
#ifdef F_9
struct V_7 * V_8 ;
int V_34 , V_35 = - 1 , V_36 = 0 ;
if ( ! V_31 -> V_37 || ! V_31 -> V_38 )
return;
V_8 = F_2 ( V_31 -> V_38 ) ;
if ( ! V_8 -> V_19 )
return;
V_35 = V_8 -> V_11 -> V_9 ;
V_36 = V_31 -> V_38 -> V_15 . V_36 ;
for ( V_34 = 0 ; V_34 < V_13 ; V_34 ++ ) {
T_3 V_39 = F_10 ( V_33 -> V_40 [ V_34 ] . V_41 ) ;
T_3 V_9 = ( V_39 & V_42 ) >> V_43 ;
T_3 V_44 = F_10 ( V_33 -> V_40 [ V_34 ] . V_44 ) ;
if ( V_9 != V_35 )
continue;
V_44 *= ( V_36 - V_31 -> V_37 ) ;
V_44 /= V_36 ;
F_11 ( V_31 , L_1 ,
F_10 ( V_33 -> V_40 [ V_34 ] . V_44 ) , V_44 ) ;
V_33 -> V_40 [ V_34 ] . V_44 = F_12 ( V_44 ) ;
}
#endif
}
int F_13 ( struct V_30 * V_31 ,
bool V_45 ,
struct V_3 * V_10 )
{
struct V_32 V_33 = {} ;
int V_34 , V_46 , V_47 , V_48 , V_44 , V_49 , V_50 ;
struct V_5 V_6 = {
. V_25 = {} ,
. V_23 = { - 1 , - 1 , - 1 , - 1 } ,
. V_10 = V_10 ,
} ;
struct V_32 * V_51 = & V_31 -> V_52 ;
bool V_53 = false ;
F_14 ( & V_31 -> V_54 ) ;
if ( F_15 ( V_55 , & V_31 -> V_56 ) )
return 0 ;
F_3 ( V_13 != 4 ) ;
F_16 (
V_31 -> V_57 , V_58 ,
F_1 , & V_6 ) ;
V_48 = 0 ;
for ( V_34 = 0 ; V_34 < V_13 ; V_34 ++ ) {
V_33 . V_40 [ V_34 ] . V_41 = F_12 ( V_59 ) ;
V_48 += V_6 . V_25 [ V_34 ] ;
}
V_50 = V_48 ;
if ( V_6 . V_29 == 1 ) {
for ( V_34 = 0 ; V_34 < V_13 ; V_34 ++ ) {
if ( V_6 . V_28 [ V_34 ] ) {
V_50 -= V_6 . V_25 [ V_34 ] ;
break;
}
}
}
if ( V_6 . V_29 == 1 && V_50 ) {
V_44 = ( V_60 - V_61 ) / V_50 ;
V_49 = V_60 - V_50 * V_44 -
V_61 ;
F_11 ( V_31 ,
L_2 ,
V_44 ) ;
} else if ( V_48 ) {
V_44 = V_60 / V_48 ;
V_49 = V_60 % V_48 ;
F_11 ( V_31 ,
L_3 ,
V_44 ) ;
} else {
V_44 = 0 ;
V_49 = 0 ;
}
for ( V_46 = 0 , V_34 = 0 ; V_34 < V_13 ; V_34 ++ ) {
if ( V_6 . V_23 [ V_34 ] < 0 )
continue;
V_33 . V_40 [ V_46 ] . V_41 =
F_12 ( F_17 ( V_34 , V_6 . V_23 [ V_34 ] ) ) ;
if ( V_6 . V_25 [ V_34 ] <= 0 )
V_33 . V_40 [ V_46 ] . V_44 = F_12 ( 0 ) ;
#ifdef F_5
else if ( V_6 . V_27 [ V_34 ] )
V_33 . V_40 [ V_46 ] . V_44 =
F_12 ( V_6 . V_27 [ V_34 ] * V_60 / 100 ) ;
#endif
else if ( V_6 . V_29 == 1 && V_50 &&
V_6 . V_28 [ V_34 ] )
V_33 . V_40 [ V_46 ] . V_44 = F_12 ( V_61 ) ;
else
V_33 . V_40 [ V_46 ] . V_44 =
F_12 ( V_44 * V_6 . V_25 [ V_34 ] ) ;
F_18 ( F_10 ( V_33 . V_40 [ V_46 ] . V_44 ) > V_60 ,
L_4 ,
V_46 , F_10 ( V_33 . V_40 [ V_46 ] . V_44 ) , V_60 ) ;
V_33 . V_40 [ V_46 ] . V_62 = F_12 ( 0 ) ;
V_46 ++ ;
}
for ( V_34 = 0 ; V_34 < V_13 ; V_34 ++ ) {
if ( F_10 ( V_33 . V_40 [ V_34 ] . V_44 ) != 0 ) {
F_19 ( & V_33 . V_40 [ V_34 ] . V_44 , V_49 ) ;
F_11 ( V_31 ,
L_5 ,
V_49 , V_34 ) ;
break;
}
}
F_8 ( V_31 , & V_33 ) ;
for ( V_34 = 0 ; V_34 < V_13 ; V_34 ++ ) {
if ( V_33 . V_40 [ V_34 ] . V_41 != V_51 -> V_40 [ V_34 ] . V_41 )
V_53 = true ;
if ( V_33 . V_40 [ V_34 ] . V_62 != V_51 -> V_40 [ V_34 ] . V_62 )
V_53 = true ;
if ( abs ( ( int ) F_10 ( V_33 . V_40 [ V_34 ] . V_44 ) -
( int ) F_10 ( V_51 -> V_40 [ V_34 ] . V_44 ) )
> V_63 )
V_53 = true ;
if ( V_33 . V_40 [ V_34 ] . V_41 == F_12 ( V_59 ) )
continue;
F_18 ( V_33 . V_40 [ V_34 ] . V_44 == 0 ,
L_6 , V_34 ) ;
}
if ( ! V_53 && ! V_45 ) {
return 0 ;
}
V_47 = F_20 ( V_31 , V_64 , 0 , sizeof( V_33 ) , & V_33 ) ;
if ( V_47 )
F_21 ( V_31 , L_7 , V_47 ) ;
else
V_31 -> V_52 = V_33 ;
return V_47 ;
}
