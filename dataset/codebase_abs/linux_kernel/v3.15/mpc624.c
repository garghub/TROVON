static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned long V_7 )
{
unsigned char V_8 ;
V_8 = F_2 ( V_2 -> V_9 + V_10 ) ;
if ( ( V_8 & V_11 ) == 0 )
return 0 ;
return - V_12 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 ,
unsigned int * V_13 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
int V_17 , V_18 ;
unsigned long int V_19 , V_20 ;
int V_21 ;
F_4 ( V_6 -> V_22 , V_2 -> V_9 + V_23 ) ;
for ( V_17 = 0 ; V_17 < V_6 -> V_17 ; V_17 ++ ) {
F_4 ( V_24 , V_2 -> V_9 + V_10 ) ;
F_5 ( 1 ) ;
F_4 ( V_25 | V_24 , V_2 -> V_9 + V_10 ) ;
F_5 ( 1 ) ;
F_4 ( 0 , V_2 -> V_9 + V_10 ) ;
F_5 ( 1 ) ;
V_21 = F_6 ( V_2 , V_4 , V_6 , F_1 , 0 ) ;
if ( V_21 )
return V_21 ;
V_19 = 0 ;
V_20 = V_15 -> V_26 ;
F_5 ( 1 ) ;
for ( V_18 = 0 ; V_18 < 32 ; V_18 ++ ) {
F_4 ( 0 , V_2 -> V_9 + V_10 ) ;
F_5 ( 1 ) ;
if ( V_20 & ( 1 << 31 ) ) {
F_4 ( V_27 , V_2 -> V_9 + V_10 ) ;
F_5 ( 1 ) ;
F_4 ( V_24 | V_27 ,
V_2 -> V_9 + V_10 ) ;
} else {
F_4 ( 0 , V_2 -> V_9 + V_10 ) ;
F_5 ( 1 ) ;
F_4 ( V_24 , V_2 -> V_9 + V_10 ) ;
}
F_5 ( 1 ) ;
V_19 <<= 1 ;
V_19 |=
( F_2 ( V_2 -> V_9 + V_10 ) & V_28 ) >> 4 ;
F_5 ( 1 ) ;
V_20 <<= 1 ;
}
if ( V_19 & V_29 )
F_7 ( V_2 -> V_30 ,
L_1 , V_19 ) ;
if ( V_19 & V_31 )
F_7 ( V_2 -> V_30 ,
L_2 , V_19 ) ;
if ( V_19 & V_32 ) {
V_19 &= 0x3FFFFFFF ;
V_13 [ V_17 ] = V_19 ;
} else {
V_19 |= V_32 ;
V_19 = ~ V_19 ;
V_19 += 1 ;
V_19 &= ~ ( V_29 | V_31 ) ;
V_19 = 0x20000000 - V_19 ;
V_13 [ V_17 ] = V_19 ;
}
}
return V_17 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_33 * V_34 )
{
struct V_14 * V_15 ;
struct V_3 * V_4 ;
int V_21 ;
V_21 = F_9 ( V_2 , V_34 -> V_35 [ 0 ] , V_36 ) ;
if ( V_21 )
return V_21 ;
V_15 = F_10 ( V_2 , sizeof( * V_15 ) ) ;
if ( ! V_15 )
return - V_37 ;
switch ( V_34 -> V_35 [ 1 ] ) {
case 0 :
V_15 -> V_26 = V_38 ;
break;
case 1 :
V_15 -> V_26 = V_39 ;
break;
case 2 :
V_15 -> V_26 = V_40 ;
break;
case 3 :
V_15 -> V_26 = V_41 ;
break;
case 4 :
V_15 -> V_26 = V_42 ;
break;
case 5 :
V_15 -> V_26 = V_43 ;
break;
case 6 :
V_15 -> V_26 = V_44 ;
break;
case 7 :
V_15 -> V_26 = V_45 ;
break;
case 8 :
V_15 -> V_26 = V_46 ;
break;
case 9 :
V_15 -> V_26 = V_47 ;
break;
default:
V_15 -> V_26 = V_38 ;
}
V_21 = F_11 ( V_2 , 1 ) ;
if ( V_21 )
return V_21 ;
V_4 = & V_2 -> V_48 [ 0 ] ;
V_4 -> type = V_49 ;
V_4 -> V_50 = V_51 | V_52 ;
V_4 -> V_53 = 8 ;
switch ( V_34 -> V_35 [ 1 ] ) {
default:
V_4 -> V_54 = 0x3FFFFFFF ;
}
switch ( V_34 -> V_35 [ 1 ] ) {
case 0 :
V_4 -> V_55 = & V_56 ;
break;
default:
V_4 -> V_55 = & V_57 ;
}
V_4 -> V_58 = 1 ;
V_4 -> V_59 = F_3 ;
return 0 ;
}
