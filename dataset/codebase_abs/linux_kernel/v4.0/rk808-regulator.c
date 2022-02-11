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
static int F_4 ( struct V_1 * V_2 , int V_17 )
{
unsigned int V_6 ;
int V_18 = F_5 ( V_2 , V_17 , V_17 ) ;
if ( V_18 < 0 )
return - V_19 ;
V_6 = V_2 -> V_8 -> V_20 + V_21 ;
return F_3 ( V_2 -> V_15 , V_6 ,
V_2 -> V_8 -> V_22 ,
V_18 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
V_6 = V_2 -> V_8 -> V_23 + V_24 ;
return F_3 ( V_2 -> V_15 , V_6 ,
V_2 -> V_8 -> V_25 ,
0 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
V_6 = V_2 -> V_8 -> V_23 + V_24 ;
return F_3 ( V_2 -> V_15 , V_6 ,
V_2 -> V_8 -> V_25 ,
V_2 -> V_8 -> V_25 ) ;
}
static int F_8 ( struct V_26 * V_27 )
{
struct V_28 * V_28 = F_9 ( V_27 -> V_29 . V_30 ) ;
struct V_31 * V_32 = V_28 -> V_33 ;
struct V_34 * V_35 ;
struct V_36 V_37 = {} ;
struct V_1 * V_38 ;
int V_39 , V_40 ;
V_35 = F_10 ( V_32 -> V_29 . V_41 , L_2 ) ;
if ( ! V_35 )
return - V_42 ;
V_39 = F_11 ( & V_27 -> V_29 , V_35 , V_43 ,
V_44 ) ;
F_12 ( V_35 ) ;
if ( V_39 < 0 )
return V_39 ;
for ( V_40 = 0 ; V_40 < V_44 ; V_40 ++ ) {
if ( ! V_43 [ V_40 ] . V_45 ||
! V_43 [ V_40 ] . V_41 )
continue;
V_37 . V_29 = & V_32 -> V_29 ;
V_37 . V_46 = V_28 ;
V_37 . V_15 = V_28 -> V_15 ;
V_37 . V_41 = V_43 [ V_40 ] . V_41 ;
V_37 . V_45 = V_43 [ V_40 ] . V_45 ;
V_38 = F_13 ( & V_27 -> V_29 ,
& V_47 [ V_40 ] , & V_37 ) ;
if ( F_14 ( V_38 ) ) {
F_15 ( & V_32 -> V_29 ,
L_3 , V_40 ) ;
return F_16 ( V_38 ) ;
}
}
return 0 ;
}
