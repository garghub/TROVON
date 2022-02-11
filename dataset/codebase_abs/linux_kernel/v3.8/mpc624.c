static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 , V_12 ;
unsigned long int V_13 , V_14 ;
unsigned char V_15 ;
F_2 ( V_6 -> V_16 , V_2 -> V_17 + V_18 ) ;
if ( ! V_6 -> V_11 ) {
F_3 ( V_19 L_1 ) ;
return 0 ;
}
for ( V_11 = 0 ; V_11 < V_6 -> V_11 ; V_11 ++ ) {
F_2 ( V_20 , V_2 -> V_17 + V_21 ) ;
F_4 ( 1 ) ;
F_2 ( V_22 | V_20 , V_2 -> V_17 + V_21 ) ;
F_4 ( 1 ) ;
F_2 ( 0 , V_2 -> V_17 + V_21 ) ;
F_4 ( 1 ) ;
for ( V_12 = 0 ; V_12 < V_23 ; V_12 ++ ) {
V_15 = F_5 ( V_2 -> V_17 + V_21 ) ;
if ( V_15 & V_24 )
F_4 ( 1000 ) ;
else
break;
}
if ( V_12 == V_23 ) {
F_3 ( V_25 L_2 , V_23 ) ;
V_7 [ V_11 ] = 0 ;
return - V_26 ;
}
V_13 = 0 ;
V_14 = V_9 -> V_27 ;
F_4 ( 1 ) ;
for ( V_12 = 0 ; V_12 < 32 ; V_12 ++ ) {
F_2 ( 0 , V_2 -> V_17 + V_21 ) ;
F_4 ( 1 ) ;
if ( V_14 & ( 1 << 31 ) ) {
F_2 ( V_28 , V_2 -> V_17 + V_21 ) ;
F_4 ( 1 ) ;
F_2 ( V_20 | V_28 ,
V_2 -> V_17 + V_21 ) ;
} else {
F_2 ( 0 , V_2 -> V_17 + V_21 ) ;
F_4 ( 1 ) ;
F_2 ( V_20 , V_2 -> V_17 + V_21 ) ;
}
F_4 ( 1 ) ;
V_13 <<= 1 ;
V_13 |=
( F_5 ( V_2 -> V_17 + V_21 ) & V_29 ) >> 4 ;
F_4 ( 1 ) ;
V_14 <<= 1 ;
}
if ( V_13 & V_30 )
F_3 ( V_19 L_3 ,
V_13 ) ;
if ( V_13 & V_31 )
F_3 ( V_19 L_4 ,
V_13 ) ;
if ( V_13 & V_32 ) {
V_13 &= 0x3FFFFFFF ;
V_7 [ V_11 ] = V_13 ;
} else {
V_13 |= V_32 ;
V_13 = ~ V_13 ;
V_13 += 1 ;
V_13 &= ~ ( V_30 | V_31 ) ;
V_13 = 0x20000000 - V_13 ;
V_7 [ V_11 ] = V_13 ;
}
}
return V_11 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_33 * V_34 )
{
struct V_8 * V_9 ;
struct V_3 * V_4 ;
unsigned long V_17 ;
int V_35 ;
V_17 = V_34 -> V_36 [ 0 ] ;
F_3 ( V_19 L_5 , V_2 -> V_37 , V_17 ) ;
if ( F_7 ( V_17 , V_38 , L_6 ) == NULL ) {
F_3 ( V_25 L_7 ) ;
return - V_39 ;
}
V_2 -> V_17 = V_17 ;
V_2 -> V_40 = L_6 ;
V_9 = F_8 ( sizeof( * V_9 ) , V_41 ) ;
if ( ! V_9 )
return - V_42 ;
V_2 -> V_10 = V_9 ;
switch ( V_34 -> V_36 [ 1 ] ) {
case 0 :
V_9 -> V_27 = V_43 ;
F_3 ( V_19 L_8 ) ;
break;
case 1 :
V_9 -> V_27 = V_44 ;
F_3 ( V_19 L_9 ) ;
break;
case 2 :
V_9 -> V_27 = V_45 ;
F_3 ( V_19 L_10 ) ;
break;
case 3 :
V_9 -> V_27 = V_46 ;
F_3 ( V_19 L_11 ) ;
break;
case 4 :
V_9 -> V_27 = V_47 ;
F_3 ( V_19 L_12 ) ;
break;
case 5 :
V_9 -> V_27 = V_48 ;
F_3 ( V_19 L_13 ) ;
break;
case 6 :
V_9 -> V_27 = V_49 ;
F_3 ( V_19 L_14 ) ;
break;
case 7 :
V_9 -> V_27 = V_50 ;
F_3 ( V_19 L_15 ) ;
break;
case 8 :
V_9 -> V_27 = V_51 ;
F_3 ( V_19 L_16 ) ;
break;
case 9 :
V_9 -> V_27 = V_52 ;
F_3 ( V_19 L_17 ) ;
break;
default:
F_3
( V_25 L_18
L_19 ) ;
V_9 -> V_27 = V_43 ;
}
V_35 = F_9 ( V_2 , 1 ) ;
if ( V_35 )
return V_35 ;
V_4 = & V_2 -> V_53 [ 0 ] ;
V_4 -> type = V_54 ;
V_4 -> V_55 = V_56 | V_57 ;
V_4 -> V_58 = 8 ;
switch ( V_34 -> V_36 [ 1 ] ) {
default:
V_4 -> V_59 = 0x3FFFFFFF ;
F_3 ( V_19 L_20 ) ;
}
switch ( V_34 -> V_36 [ 1 ] ) {
case 0 :
V_4 -> V_60 = & V_61 ;
F_3 ( V_19 L_21 ) ;
break;
default:
V_4 -> V_60 = & V_62 ;
F_3 ( V_19 L_22 ) ;
}
V_4 -> V_63 = 1 ;
V_4 -> V_64 = F_1 ;
F_3 ( V_19 L_23 ) ;
return 1 ;
}
static void F_10 ( struct V_1 * V_2 )
{
if ( V_2 -> V_17 )
F_11 ( V_2 -> V_17 , V_38 ) ;
}
