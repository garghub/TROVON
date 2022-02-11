void F_1 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
F_2 ( V_3 ) ;
}
static T_1 F_3 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
T_1 V_4 = 0 ;
T_2 V_5 ;
T_2 V_6 ;
T_2 * V_7 ;
if ( V_3 -> V_8 == V_9 ||
V_3 -> V_8 == V_10 ||
V_3 -> V_8 == V_11 ||
V_3 -> V_8 == V_12 ||
V_3 -> V_8 == V_13 ) {
V_5 = F_4 ( V_3 , V_14 ,
0xFFC00000 ) ;
V_7 = V_15 ;
V_6 = V_16 ;
} else {
{
V_5 = 0 ;
V_7 = V_17 ;
V_6 = V_16 ;
}
}
for ( V_4 = 0 ; V_4 < V_6 ; ++ V_4 ) {
T_2 V_18 = V_7 [ V_4 ] ;
if ( V_18 >= 0x100000 )
V_18 >>= 22 ;
if ( V_5 == V_18 )
break;
}
return V_4 ;
}
void F_2 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
T_1 V_19 = F_3 ( V_3 ) ;
T_1 V_20 = 0 ;
struct V_21 * V_22 = & V_3 -> V_23 ;
struct V_24 * V_25 = (struct V_24 * ) V_3 -> V_26 ;
struct V_27 * V_28 = V_27 ( V_25 ) ;
V_22 -> V_29 = true ;
V_22 -> V_30 = 0 ;
V_22 -> V_31 = false ;
if ( ! V_3 -> V_32 )
V_22 -> V_33 = true ;
else
V_22 -> V_33 = false ;
if ( ! V_3 -> V_32 )
V_22 -> V_33 = true ;
F_5 ( V_3 , V_34 , L_1 ,
V_22 -> V_33 ) ;
V_22 -> V_35 = V_28 -> V_36 ;
V_22 -> V_37 = V_28 -> V_36 ;
V_22 -> V_38 = V_28 -> V_36 ;
if ( ! V_22 -> V_39 ) {
if ( V_3 -> V_8 == V_9 ||
V_3 -> V_8 == V_10 ||
V_3 -> V_8 == V_11 ||
V_3 -> V_8 == V_13 ) {
V_22 -> V_40 =
( V_19 >= V_16 ) ?
30 :
V_19 ;
V_22 -> V_41 = 20 ;
} else if ( V_3 -> V_8 ==
V_12 ) {
V_22 -> V_40 = 28 ;
V_22 -> V_41 = 20 ;
} else if ( V_3 -> V_8 ==
V_42 ) {
V_22 -> V_40 = 28 ;
V_22 -> V_41 = 28 ;
} else if ( V_3 -> V_8 ==
V_43 ) {
V_22 -> V_40 = 28 ;
V_22 -> V_41 = 28 ;
} else {
V_22 -> V_40 =
( V_19 >= V_44 ) ?
24 :
V_19 ;
V_22 -> V_41 = 24 ;
}
V_22 -> V_39 = true ;
}
V_22 -> V_45 = V_22 -> V_41 ;
V_22 -> V_46 = V_22 -> V_41 ;
for ( V_20 = V_47 ; V_20 < V_48 ; ++ V_20 ) {
V_22 -> V_49 [ V_20 ] =
V_22 -> V_40 ;
V_22 -> V_50 [ V_20 ] = V_22 -> V_40 ;
V_22 -> V_51 [ V_20 ] = 0 ;
V_22 -> V_52 [ V_20 ] = 0 ;
V_22 -> V_53 [ V_20 ] = 0 ;
}
V_22 -> V_54 = 0 ;
V_22 -> V_55 = 0 ;
}
void F_6 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
switch ( V_3 -> V_56 ) {
case V_57 :
F_7 ( V_3 ) ;
break;
case V_58 :
F_8 ( V_3 ) ;
break;
case V_59 :
F_9 ( V_3 ) ;
break;
default:
break;
}
}
void F_8 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
void * V_26 = V_3 -> V_26 ;
if ( ! ( V_3 -> V_60 & V_61 ) )
return;
if ( ! V_3 -> V_23 . V_62 ) {
if ( F_10 ( V_26 ) ||
F_11 ( V_26 ) ||
F_12 ( V_26 ) ||
F_13 ( V_26 ) ||
F_14 ( V_26 ) ||
F_15 ( V_26 ) ||
F_16 ( V_26 ) ||
F_17 ( V_26 ) ||
F_18 ( V_26 ) ||
F_19 ( V_26 ) ||
( V_3 -> V_8 == V_43 ) )
F_20 ( V_3 , V_47 , V_63 ,
( F_21 ( 17 ) | F_21 ( 16 ) ) , 0x03 ) ;
else
F_20 ( V_3 , V_47 , V_64 ,
V_65 , 0x60 ) ;
V_3 -> V_23 . V_62 = 1 ;
return;
}
F_22 ( V_3 ) ;
V_3 -> V_23 . V_62 = 0 ;
}
void F_7 ( void * V_1 ) {}
void F_9 ( void * V_1 ) {}
