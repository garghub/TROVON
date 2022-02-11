static int F_1 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_4 = V_5 ;
unsigned int V_6 = V_7 [ V_2 -> V_8 -> V_9 -
V_10 ] ;
switch ( V_3 ) {
case 1 ... 2000 :
V_4 = V_11 ;
break;
case 2001 ... 4000 :
V_4 = V_12 ;
break;
case 4001 ... 6000 :
V_4 = V_13 ;
break;
case 6001 ... 10000 :
break;
default:
F_2 ( L_1 ,
V_2 -> V_8 -> V_14 , V_3 ) ;
}
return F_3 ( V_2 -> V_15 , V_6 ,
V_16 , V_4 ) ;
}
static int F_4 ( struct V_17 * V_18 )
{
struct V_19 * V_19 = F_5 ( V_18 -> V_20 . V_21 ) ;
struct V_22 * V_23 = V_19 -> V_24 ;
struct V_25 * V_26 ;
struct V_27 V_28 = {} ;
struct V_1 * V_29 ;
int V_30 , V_31 ;
V_26 = F_6 ( V_23 -> V_20 . V_32 , L_2 ) ;
if ( ! V_26 )
return - V_33 ;
V_30 = F_7 ( & V_18 -> V_20 , V_26 , V_34 ,
V_35 ) ;
F_8 ( V_26 ) ;
if ( V_30 < 0 )
return V_30 ;
for ( V_31 = 0 ; V_31 < V_35 ; V_31 ++ ) {
if ( ! V_34 [ V_31 ] . V_36 ||
! V_34 [ V_31 ] . V_32 )
continue;
V_28 . V_20 = & V_23 -> V_20 ;
V_28 . V_37 = V_19 ;
V_28 . V_15 = V_19 -> V_15 ;
V_28 . V_32 = V_34 [ V_31 ] . V_32 ;
V_28 . V_36 = V_34 [ V_31 ] . V_36 ;
V_29 = F_9 ( & V_18 -> V_20 ,
& V_38 [ V_31 ] , & V_28 ) ;
if ( F_10 ( V_29 ) ) {
F_11 ( & V_23 -> V_20 ,
L_3 , V_31 ) ;
return F_12 ( V_29 ) ;
}
}
return 0 ;
}
