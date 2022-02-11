static unsigned int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_8 = V_6 -> V_9 ;
unsigned int V_10 = 0 ;
unsigned int V_11 ;
int V_12 ;
F_2 ( 1 ) ;
for ( V_12 = 0 ; V_12 < 32 ; V_12 ++ ) {
F_3 ( 0 , V_2 -> V_13 + V_14 ) ;
F_2 ( 1 ) ;
V_11 = ( V_8 & F_4 ( 31 ) ) ? V_15 : 0 ;
F_3 ( V_11 , V_2 -> V_13 + V_14 ) ;
F_2 ( 1 ) ;
F_3 ( V_16 | V_11 , V_2 -> V_13 + V_14 ) ;
F_2 ( 1 ) ;
V_10 <<= 1 ;
V_10 |= ( F_5 ( V_2 -> V_13 + V_14 ) & V_17 ) >> 4 ;
F_2 ( 1 ) ;
V_8 <<= 1 ;
}
if ( V_10 & V_18 )
F_6 ( V_2 -> V_19 , L_1 ) ;
if ( V_10 & V_20 )
F_6 ( V_2 -> V_19 , L_2 ) ;
if ( V_10 & V_21 ) {
V_10 &= 0x3fffffff ;
} else {
V_10 |= V_21 ;
V_10 = ~ V_10 ;
V_10 += 1 ;
V_10 &= ~ ( V_18 | V_20 ) ;
V_10 = 0x20000000 - V_10 ;
}
return V_10 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_22 * V_23 ,
unsigned long V_24 )
{
unsigned char V_25 ;
V_25 = F_5 ( V_2 -> V_13 + V_14 ) ;
if ( ( V_25 & V_26 ) == 0 )
return 0 ;
return - V_27 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_22 * V_23 ,
unsigned int * V_28 )
{
int V_29 ;
int V_12 ;
F_3 ( V_23 -> V_30 , V_2 -> V_13 + V_31 ) ;
for ( V_12 = 0 ; V_12 < V_23 -> V_32 ; V_12 ++ ) {
F_3 ( V_16 , V_2 -> V_13 + V_14 ) ;
F_2 ( 1 ) ;
F_3 ( V_33 | V_16 , V_2 -> V_13 + V_14 ) ;
F_2 ( 1 ) ;
F_3 ( 0 , V_2 -> V_13 + V_14 ) ;
F_2 ( 1 ) ;
V_29 = F_9 ( V_2 , V_4 , V_23 , F_7 , 0 ) ;
if ( V_29 )
return V_29 ;
V_28 [ V_12 ] = F_1 ( V_2 , V_4 ) ;
}
return V_23 -> V_32 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_29 ;
V_29 = F_11 ( V_2 , V_35 -> V_36 [ 0 ] , 0x10 ) ;
if ( V_29 )
return V_29 ;
V_6 = F_12 ( V_2 , sizeof( * V_6 ) ) ;
if ( ! V_6 )
return - V_37 ;
switch ( V_35 -> V_36 [ 1 ] ) {
case 0 :
V_6 -> V_9 = V_38 ;
break;
case 1 :
V_6 -> V_9 = V_39 ;
break;
case 2 :
V_6 -> V_9 = V_40 ;
break;
case 3 :
V_6 -> V_9 = V_41 ;
break;
case 4 :
V_6 -> V_9 = V_42 ;
break;
case 5 :
V_6 -> V_9 = V_43 ;
break;
case 6 :
V_6 -> V_9 = V_44 ;
break;
case 7 :
V_6 -> V_9 = V_45 ;
break;
case 8 :
V_6 -> V_9 = V_46 ;
break;
case 9 :
V_6 -> V_9 = V_47 ;
break;
default:
V_6 -> V_9 = V_38 ;
}
V_29 = F_13 ( V_2 , 1 ) ;
if ( V_29 )
return V_29 ;
V_4 = & V_2 -> V_48 [ 0 ] ;
V_4 -> type = V_49 ;
V_4 -> V_50 = V_51 | V_52 ;
V_4 -> V_53 = 4 ;
V_4 -> V_54 = 0x3fffffff ;
V_4 -> V_55 = ( V_35 -> V_36 [ 1 ] == 0 ) ? & V_56
: & V_57 ;
V_4 -> V_58 = F_8 ;
return 0 ;
}
