static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
unsigned long V_7 ;
V_7 = V_4 -> V_8 [ 0 ] ;
F_2 ( V_9 L_1 , V_2 -> V_10 , V_7 ) ;
if ( F_3 ( V_7 , V_11 , L_2 ) == NULL ) {
F_2 ( V_12 L_3 ) ;
return - V_13 ;
}
V_2 -> V_7 = V_7 ;
V_2 -> V_14 = L_2 ;
if ( F_4 ( V_2 , sizeof( struct V_15 ) ) < 0 )
return - V_16 ;
switch ( V_4 -> V_8 [ 1 ] ) {
case 0 :
V_17 -> V_18 = V_19 ;
F_2 ( V_9 L_4 ) ;
break;
case 1 :
V_17 -> V_18 = V_20 ;
F_2 ( V_9 L_5 ) ;
break;
case 2 :
V_17 -> V_18 = V_21 ;
F_2 ( V_9 L_6 ) ;
break;
case 3 :
V_17 -> V_18 = V_22 ;
F_2 ( V_9 L_7 ) ;
break;
case 4 :
V_17 -> V_18 = V_23 ;
F_2 ( V_9 L_8 ) ;
break;
case 5 :
V_17 -> V_18 = V_24 ;
F_2 ( V_9 L_9 ) ;
break;
case 6 :
V_17 -> V_18 = V_25 ;
F_2 ( V_9 L_10 ) ;
break;
case 7 :
V_17 -> V_18 = V_26 ;
F_2 ( V_9 L_11 ) ;
break;
case 8 :
V_17 -> V_18 = V_27 ;
F_2 ( V_9 L_12 ) ;
break;
case 9 :
V_17 -> V_18 = V_28 ;
F_2 ( V_9 L_13 ) ;
break;
default:
F_2
( V_12 L_14
L_15 ) ;
V_17 -> V_18 = V_19 ;
}
if ( F_5 ( V_2 , 1 ) < 0 )
return - V_16 ;
V_6 = V_2 -> V_29 + 0 ;
V_6 -> type = V_30 ;
V_6 -> V_31 = V_32 | V_33 ;
V_6 -> V_34 = 8 ;
switch ( V_4 -> V_8 [ 1 ] ) {
default:
V_6 -> V_35 = 0x3FFFFFFF ;
F_2 ( V_9 L_16 ) ;
}
switch ( V_4 -> V_8 [ 1 ] ) {
case 0 :
V_6 -> V_36 = & V_37 ;
F_2 ( V_9 L_17 ) ;
break;
default:
V_6 -> V_36 = & V_38 ;
F_2 ( V_9 L_18 ) ;
}
V_6 -> V_39 = 1 ;
V_6 -> V_40 = V_41 ;
F_2 ( V_9 L_19 ) ;
return 1 ;
}
static int F_6 ( struct V_1 * V_2 )
{
F_2 ( V_9 L_20 , V_2 -> V_10 ) ;
if ( V_2 -> V_7 )
F_7 ( V_2 -> V_7 , V_11 ) ;
return 0 ;
}
static int V_41 ( struct V_1 * V_2 ,
struct V_5 * V_6 , struct V_42 * V_43 ,
unsigned int * V_44 )
{
int V_45 , V_46 ;
unsigned long int V_47 , V_48 ;
unsigned char V_49 ;
F_8 ( V_43 -> V_50 , V_2 -> V_7 + V_51 ) ;
if ( ! V_43 -> V_45 ) {
F_2 ( V_9 L_21 ) ;
return 0 ;
}
for ( V_45 = 0 ; V_45 < V_43 -> V_45 ; V_45 ++ ) {
F_8 ( V_52 , V_2 -> V_7 + V_53 ) ;
F_9 ( 1 ) ;
F_8 ( V_54 | V_52 , V_2 -> V_7 + V_53 ) ;
F_9 ( 1 ) ;
F_8 ( 0 , V_2 -> V_7 + V_53 ) ;
F_9 ( 1 ) ;
for ( V_46 = 0 ; V_46 < V_55 ; V_46 ++ ) {
V_49 = F_10 ( V_2 -> V_7 + V_53 ) ;
if ( V_49 & V_56 )
F_9 ( 1000 ) ;
else
break;
}
if ( V_46 == V_55 ) {
F_2 ( V_12 L_22 , V_55 ) ;
V_44 [ V_45 ] = 0 ;
return - V_57 ;
}
V_47 = 0 ;
V_48 = V_17 -> V_18 ;
F_9 ( 1 ) ;
for ( V_46 = 0 ; V_46 < 32 ; V_46 ++ ) {
F_8 ( 0 , V_2 -> V_7 + V_53 ) ;
F_9 ( 1 ) ;
if ( V_48 & ( 1 << 31 ) ) {
F_8 ( V_58 , V_2 -> V_7 + V_53 ) ;
F_9 ( 1 ) ;
F_8 ( V_52 | V_58 ,
V_2 -> V_7 + V_53 ) ;
} else {
F_8 ( 0 , V_2 -> V_7 + V_53 ) ;
F_9 ( 1 ) ;
F_8 ( V_52 , V_2 -> V_7 + V_53 ) ;
}
F_9 ( 1 ) ;
V_47 <<= 1 ;
V_47 |=
( F_10 ( V_2 -> V_7 + V_53 ) & V_59 ) >> 4 ;
F_9 ( 1 ) ;
V_48 <<= 1 ;
}
if ( V_47 & V_60 )
F_2 ( V_9 L_23 ,
V_47 ) ;
if ( V_47 & V_61 )
F_2 ( V_9 L_24 ,
V_47 ) ;
if ( V_47 & V_62 ) {
V_47 &= 0x3FFFFFFF ;
V_44 [ V_45 ] = V_47 ;
} else {
V_47 |= V_62 ;
V_47 = ~ V_47 ;
V_47 += 1 ;
V_47 &= ~ ( V_60 | V_61 ) ;
V_47 = 0x20000000 - V_47 ;
V_44 [ V_45 ] = V_47 ;
}
}
return V_45 ;
}
static int T_1 F_11 ( void )
{
return F_12 ( & V_63 ) ;
}
static void T_2 F_13 ( void )
{
F_14 ( & V_63 ) ;
}
