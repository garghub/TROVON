static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 , V_12 ;
unsigned long int V_13 , V_14 ;
unsigned char V_15 ;
F_2 ( V_6 -> V_16 , V_2 -> V_17 + V_18 ) ;
for ( V_11 = 0 ; V_11 < V_6 -> V_11 ; V_11 ++ ) {
F_2 ( V_19 , V_2 -> V_17 + V_20 ) ;
F_3 ( 1 ) ;
F_2 ( V_21 | V_19 , V_2 -> V_17 + V_20 ) ;
F_3 ( 1 ) ;
F_2 ( 0 , V_2 -> V_17 + V_20 ) ;
F_3 ( 1 ) ;
for ( V_12 = 0 ; V_12 < V_22 ; V_12 ++ ) {
V_15 = F_4 ( V_2 -> V_17 + V_20 ) ;
if ( V_15 & V_23 )
F_3 ( 1000 ) ;
else
break;
}
if ( V_12 == V_22 )
return - V_24 ;
V_13 = 0 ;
V_14 = V_9 -> V_25 ;
F_3 ( 1 ) ;
for ( V_12 = 0 ; V_12 < 32 ; V_12 ++ ) {
F_2 ( 0 , V_2 -> V_17 + V_20 ) ;
F_3 ( 1 ) ;
if ( V_14 & ( 1 << 31 ) ) {
F_2 ( V_26 , V_2 -> V_17 + V_20 ) ;
F_3 ( 1 ) ;
F_2 ( V_19 | V_26 ,
V_2 -> V_17 + V_20 ) ;
} else {
F_2 ( 0 , V_2 -> V_17 + V_20 ) ;
F_3 ( 1 ) ;
F_2 ( V_19 , V_2 -> V_17 + V_20 ) ;
}
F_3 ( 1 ) ;
V_13 <<= 1 ;
V_13 |=
( F_4 ( V_2 -> V_17 + V_20 ) & V_27 ) >> 4 ;
F_3 ( 1 ) ;
V_14 <<= 1 ;
}
if ( V_13 & V_28 )
F_5 ( V_2 -> V_29 ,
L_1 , V_13 ) ;
if ( V_13 & V_30 )
F_5 ( V_2 -> V_29 ,
L_2 , V_13 ) ;
if ( V_13 & V_31 ) {
V_13 &= 0x3FFFFFFF ;
V_7 [ V_11 ] = V_13 ;
} else {
V_13 |= V_31 ;
V_13 = ~ V_13 ;
V_13 += 1 ;
V_13 &= ~ ( V_28 | V_30 ) ;
V_13 = 0x20000000 - V_13 ;
V_7 [ V_11 ] = V_13 ;
}
}
return V_11 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
struct V_8 * V_9 ;
struct V_3 * V_4 ;
int V_34 ;
V_34 = F_7 ( V_2 , V_33 -> V_35 [ 0 ] , V_36 ) ;
if ( V_34 )
return V_34 ;
V_9 = F_8 ( V_2 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_37 ;
switch ( V_33 -> V_35 [ 1 ] ) {
case 0 :
V_9 -> V_25 = V_38 ;
break;
case 1 :
V_9 -> V_25 = V_39 ;
break;
case 2 :
V_9 -> V_25 = V_40 ;
break;
case 3 :
V_9 -> V_25 = V_41 ;
break;
case 4 :
V_9 -> V_25 = V_42 ;
break;
case 5 :
V_9 -> V_25 = V_43 ;
break;
case 6 :
V_9 -> V_25 = V_44 ;
break;
case 7 :
V_9 -> V_25 = V_45 ;
break;
case 8 :
V_9 -> V_25 = V_46 ;
break;
case 9 :
V_9 -> V_25 = V_47 ;
break;
default:
V_9 -> V_25 = V_38 ;
}
V_34 = F_9 ( V_2 , 1 ) ;
if ( V_34 )
return V_34 ;
V_4 = & V_2 -> V_48 [ 0 ] ;
V_4 -> type = V_49 ;
V_4 -> V_50 = V_51 | V_52 ;
V_4 -> V_53 = 8 ;
switch ( V_33 -> V_35 [ 1 ] ) {
default:
V_4 -> V_54 = 0x3FFFFFFF ;
}
switch ( V_33 -> V_35 [ 1 ] ) {
case 0 :
V_4 -> V_55 = & V_56 ;
break;
default:
V_4 -> V_55 = & V_57 ;
}
V_4 -> V_58 = 1 ;
V_4 -> V_59 = F_1 ;
return 1 ;
}
