static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 ,
unsigned int * V_7 )
{
int V_8 , V_9 ;
unsigned long int V_10 , V_11 ;
unsigned char V_12 ;
F_2 ( V_6 -> V_13 , V_2 -> V_14 + V_15 ) ;
if ( ! V_6 -> V_8 ) {
F_3 ( V_16 L_1 ) ;
return 0 ;
}
for ( V_8 = 0 ; V_8 < V_6 -> V_8 ; V_8 ++ ) {
F_2 ( V_17 , V_2 -> V_14 + V_18 ) ;
F_4 ( 1 ) ;
F_2 ( V_19 | V_17 , V_2 -> V_14 + V_18 ) ;
F_4 ( 1 ) ;
F_2 ( 0 , V_2 -> V_14 + V_18 ) ;
F_4 ( 1 ) ;
for ( V_9 = 0 ; V_9 < V_20 ; V_9 ++ ) {
V_12 = F_5 ( V_2 -> V_14 + V_18 ) ;
if ( V_12 & V_21 )
F_4 ( 1000 ) ;
else
break;
}
if ( V_9 == V_20 ) {
F_3 ( V_22 L_2 , V_20 ) ;
V_7 [ V_8 ] = 0 ;
return - V_23 ;
}
V_10 = 0 ;
V_11 = V_24 -> V_25 ;
F_4 ( 1 ) ;
for ( V_9 = 0 ; V_9 < 32 ; V_9 ++ ) {
F_2 ( 0 , V_2 -> V_14 + V_18 ) ;
F_4 ( 1 ) ;
if ( V_11 & ( 1 << 31 ) ) {
F_2 ( V_26 , V_2 -> V_14 + V_18 ) ;
F_4 ( 1 ) ;
F_2 ( V_17 | V_26 ,
V_2 -> V_14 + V_18 ) ;
} else {
F_2 ( 0 , V_2 -> V_14 + V_18 ) ;
F_4 ( 1 ) ;
F_2 ( V_17 , V_2 -> V_14 + V_18 ) ;
}
F_4 ( 1 ) ;
V_10 <<= 1 ;
V_10 |=
( F_5 ( V_2 -> V_14 + V_18 ) & V_27 ) >> 4 ;
F_4 ( 1 ) ;
V_11 <<= 1 ;
}
if ( V_10 & V_28 )
F_3 ( V_16 L_3 ,
V_10 ) ;
if ( V_10 & V_29 )
F_3 ( V_16 L_4 ,
V_10 ) ;
if ( V_10 & V_30 ) {
V_10 &= 0x3FFFFFFF ;
V_7 [ V_8 ] = V_10 ;
} else {
V_10 |= V_30 ;
V_10 = ~ V_10 ;
V_10 += 1 ;
V_10 &= ~ ( V_28 | V_29 ) ;
V_10 = 0x20000000 - V_10 ;
V_7 [ V_8 ] = V_10 ;
}
}
return V_8 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
struct V_3 * V_4 ;
unsigned long V_14 ;
V_14 = V_32 -> V_33 [ 0 ] ;
F_3 ( V_16 L_5 , V_2 -> V_34 , V_14 ) ;
if ( F_7 ( V_14 , V_35 , L_6 ) == NULL ) {
F_3 ( V_22 L_7 ) ;
return - V_36 ;
}
V_2 -> V_14 = V_14 ;
V_2 -> V_37 = L_6 ;
if ( F_8 ( V_2 , sizeof( struct V_38 ) ) < 0 )
return - V_39 ;
switch ( V_32 -> V_33 [ 1 ] ) {
case 0 :
V_24 -> V_25 = V_40 ;
F_3 ( V_16 L_8 ) ;
break;
case 1 :
V_24 -> V_25 = V_41 ;
F_3 ( V_16 L_9 ) ;
break;
case 2 :
V_24 -> V_25 = V_42 ;
F_3 ( V_16 L_10 ) ;
break;
case 3 :
V_24 -> V_25 = V_43 ;
F_3 ( V_16 L_11 ) ;
break;
case 4 :
V_24 -> V_25 = V_44 ;
F_3 ( V_16 L_12 ) ;
break;
case 5 :
V_24 -> V_25 = V_45 ;
F_3 ( V_16 L_13 ) ;
break;
case 6 :
V_24 -> V_25 = V_46 ;
F_3 ( V_16 L_14 ) ;
break;
case 7 :
V_24 -> V_25 = V_47 ;
F_3 ( V_16 L_15 ) ;
break;
case 8 :
V_24 -> V_25 = V_48 ;
F_3 ( V_16 L_16 ) ;
break;
case 9 :
V_24 -> V_25 = V_49 ;
F_3 ( V_16 L_17 ) ;
break;
default:
F_3
( V_22 L_18
L_19 ) ;
V_24 -> V_25 = V_40 ;
}
if ( F_9 ( V_2 , 1 ) < 0 )
return - V_39 ;
V_4 = V_2 -> V_50 + 0 ;
V_4 -> type = V_51 ;
V_4 -> V_52 = V_53 | V_54 ;
V_4 -> V_55 = 8 ;
switch ( V_32 -> V_33 [ 1 ] ) {
default:
V_4 -> V_56 = 0x3FFFFFFF ;
F_3 ( V_16 L_20 ) ;
}
switch ( V_32 -> V_33 [ 1 ] ) {
case 0 :
V_4 -> V_57 = & V_58 ;
F_3 ( V_16 L_21 ) ;
break;
default:
V_4 -> V_57 = & V_59 ;
F_3 ( V_16 L_22 ) ;
}
V_4 -> V_60 = 1 ;
V_4 -> V_61 = F_1 ;
F_3 ( V_16 L_23 ) ;
return 1 ;
}
static void F_10 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 )
F_11 ( V_2 -> V_14 , V_35 ) ;
}
