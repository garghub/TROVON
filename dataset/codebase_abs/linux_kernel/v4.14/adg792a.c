static int F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 )
{
T_1 V_5 = V_6 | V_7 ;
if ( V_4 )
V_5 &= ~ V_6 ;
return F_2 ( V_2 , V_3 , V_5 ) ;
}
static int F_3 ( struct V_8 * V_9 , int V_10 )
{
struct V_1 * V_2 = F_4 ( V_9 -> V_11 -> V_12 . V_13 ) ;
T_1 V_3 ;
if ( V_9 -> V_11 -> V_14 == 1 ) {
if ( V_10 == V_15 )
V_3 = V_16 ;
else
V_3 = F_5 ( V_10 ) ;
} else {
unsigned int V_17 = F_6 ( V_9 ) ;
if ( V_10 == V_15 )
V_3 = F_7 ( V_17 ) ;
else
V_3 = F_8 ( V_17 , V_10 ) ;
}
return F_1 ( V_2 , V_3 , 0 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
const struct V_18 * V_19 )
{
struct V_20 * V_12 = & V_2 -> V_12 ;
struct V_21 * V_21 ;
T_2 V_22 [ 3 ] ;
T_3 V_23 ;
int V_24 ;
int V_25 ;
if ( ! F_10 ( V_2 -> V_26 , V_27 ) )
return - V_28 ;
V_24 = F_11 ( V_12 , L_1 , & V_23 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_23 >= 2 )
return - V_29 ;
V_21 = F_12 ( V_12 , V_23 ? 3 : 1 , 0 ) ;
if ( F_13 ( V_21 ) )
return F_14 ( V_21 ) ;
V_21 -> V_30 = & V_31 ;
V_24 = F_1 ( V_2 , V_16 , 1 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_15 ( V_12 , L_2 ,
( T_3 * ) V_22 ,
V_21 -> V_14 ) ;
if ( V_24 < 0 ) {
V_22 [ 0 ] = V_32 ;
V_22 [ 1 ] = V_32 ;
V_22 [ 2 ] = V_32 ;
}
for ( V_25 = 0 ; V_25 < V_21 -> V_14 ; ++ V_25 ) {
struct V_8 * V_9 = & V_21 -> V_9 [ V_25 ] ;
V_9 -> V_33 = 4 ;
switch ( V_22 [ V_25 ] ) {
case V_15 :
case V_32 :
case 0 ... 4 :
V_9 -> V_22 = V_22 [ V_25 ] ;
break;
default:
F_16 ( V_12 , L_3 , V_22 [ V_25 ] ) ;
return - V_29 ;
}
}
V_24 = F_17 ( V_12 , V_21 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_23 )
F_18 ( V_12 , L_4 ) ;
else
F_18 ( V_12 , L_5 ) ;
return 0 ;
}
