static void F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
const struct V_4 * V_5 , bool V_6 )
{
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < V_3 ; V_7 ++ ) {
if ( V_6 &&
V_5 [ V_7 ] . V_8 >= V_9 &&
V_5 [ V_7 ] . V_8 <= V_10 )
continue;
switch ( V_5 [ V_7 ] . V_11 ) {
case V_12 :
F_2 ( V_2 , V_5 [ V_7 ] . V_8 ) ;
break;
case V_13 :
default:
F_3 ( V_7 ) ;
F_4 ( V_2 , V_5 [ V_7 ] . V_14 ,
V_5 [ V_7 ] . V_8 ) ;
}
}
}
static void F_5 ( struct V_1 * V_2 ,
unsigned int V_3 , const struct V_15 * V_11 ,
T_1 V_16 )
{
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < V_3 ; V_7 ++ ) {
F_3 ( V_7 ) ;
F_4 ( V_2 , V_11 [ V_7 ] . V_17 [ V_16 ] ,
( V_18 ) V_11 [ V_7 ] . V_19 ) ;
}
}
int F_6 ( struct V_1 * V_2 , T_1 V_16 , bool V_6 )
{
if ( V_2 -> V_20 == V_21 ) {
F_5 ( V_2 ,
F_7 ( V_22 ) ,
V_22 , V_16 ) ;
F_1 ( V_2 , F_7 ( V_23 ) ,
V_23 , V_6 ) ;
switch ( V_2 -> V_24 ) {
case V_25 :
F_5 ( V_2 ,
F_7 ( V_26 ) ,
V_26 , V_16 ) ;
F_1 ( V_2 ,
F_7 ( V_27 ) ,
V_27 , V_6 ) ;
F_1 ( V_2 ,
F_7 ( V_28 ) ,
V_28 , V_6 ) ;
break;
case V_29 :
F_5 ( V_2 ,
F_7 ( V_30 ) ,
V_30 , V_16 ) ;
F_1 ( V_2 ,
F_7 ( V_31 ) ,
V_31 , V_6 ) ;
F_1 ( V_2 ,
F_7 ( V_32 ) ,
V_32 , V_6 ) ;
break;
case V_33 :
F_5 ( V_2 ,
F_7 ( V_34 ) ,
V_34 , V_16 ) ;
F_1 ( V_2 ,
F_7 ( V_35 ) ,
V_35 , V_6 ) ;
F_1 ( V_2 ,
F_7 ( V_32 ) ,
V_32 , V_6 ) ;
break;
case V_36 :
case V_37 :
F_5 ( V_2 ,
F_7 ( V_38 ) ,
V_38 , V_16 ) ;
F_1 ( V_2 ,
F_7 ( V_39 ) ,
V_39 , V_6 ) ;
if ( V_2 -> V_24 == V_36 ) {
F_4 ( V_2 , 0x00004000 ,
V_40 ) ;
F_4 ( V_2 , 0x081b7caa ,
0xa274 ) ;
}
F_1 ( V_2 ,
F_7 ( V_32 ) ,
V_32 , V_6 ) ;
break;
case V_41 :
F_5 ( V_2 ,
F_7 ( V_38 ) ,
V_38 , V_16 ) ;
F_1 ( V_2 ,
F_7 ( V_42 ) ,
V_42 , V_6 ) ;
F_4 ( V_2 , 0x00180a65 , V_43 ) ;
F_4 ( V_2 , 0x00004000 , V_40 ) ;
F_8 ( V_2 , V_44 ,
V_45 , 0xa ) ;
F_4 ( V_2 , 0x800000a8 , 0x8140 ) ;
F_4 ( V_2 , 0x000000ff , 0x9958 ) ;
F_1 ( V_2 ,
F_7 ( V_32 ) ,
V_32 , V_6 ) ;
break;
case V_46 :
F_5 ( V_2 ,
F_7 ( V_47 ) ,
V_47 , V_16 ) ;
F_1 ( V_2 ,
F_7 ( V_42 ) ,
V_42 , V_6 ) ;
F_1 ( V_2 ,
F_7 ( V_32 ) ,
V_32 , V_6 ) ;
break;
default:
return - V_48 ;
}
} else if ( V_2 -> V_20 == V_49 ) {
if ( V_16 > 2 ) {
F_9 ( V_2 -> V_50 ,
L_1 , V_16 ) ;
return - V_48 ;
}
F_5 ( V_2 , F_7 ( V_51 ) ,
V_51 , V_16 ) ;
F_1 ( V_2 , F_7 ( V_52 ) ,
V_52 , V_6 ) ;
F_1 ( V_2 , F_7 ( V_28 ) ,
V_28 , V_6 ) ;
} else if ( V_2 -> V_20 == V_53 ) {
F_1 ( V_2 , F_7 ( V_54 ) ,
V_54 , V_6 ) ;
}
return 0 ;
}
