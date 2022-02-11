static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned int V_8 = 1 << F_2 ( V_6 -> V_9 ) ;
unsigned int V_10 ;
if ( V_8 & 0x000000ff )
V_10 = 0x000000ff ;
else if ( V_8 & 0x0000ff00 )
V_10 = 0x0000ff00 ;
else if ( V_8 & 0x00ff0000 )
V_10 = 0x00ff0000 ;
else
V_10 = 0xff000000 ;
switch ( V_7 [ 0 ] ) {
case V_11 :
V_4 -> V_12 &= ~ V_10 ;
break;
case V_13 :
V_4 -> V_12 |= V_10 ;
break;
case V_14 :
V_7 [ 1 ] = ( V_4 -> V_12 & V_10 ) ? V_15 : V_16 ;
return V_6 -> V_17 ;
default:
return - V_18 ;
}
F_3 ( V_4 -> V_12 , V_2 -> V_19 + F_4 ( V_4 -> V_20 ) ) ;
return V_6 -> V_17 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned int V_21 = V_7 [ 0 ] ;
unsigned int V_10 = V_7 [ 1 ] ;
V_21 &= V_4 -> V_12 ;
if ( V_21 ) {
V_4 -> V_22 &= ~ V_21 ;
V_4 -> V_22 |= ( V_10 & V_21 ) ;
F_3 ( V_4 -> V_22 , V_2 -> V_19 + F_6 ( V_4 -> V_20 ) ) ;
}
V_7 [ 1 ] = F_7 ( V_2 -> V_19 + F_8 ( V_4 -> V_20 ) ) ;
return V_6 -> V_17 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned long V_23 )
{
struct V_24 * V_25 = F_10 ( V_2 ) ;
const struct V_26 * V_27 = NULL ;
struct V_3 * V_4 ;
unsigned int V_28 ;
unsigned int V_29 ;
int V_30 ;
int V_31 ;
if ( V_23 < F_11 ( V_32 ) )
V_27 = & V_32 [ V_23 ] ;
if ( ! V_27 )
return - V_33 ;
V_2 -> V_34 = V_27 ;
V_2 -> V_35 = V_27 -> V_36 ;
V_31 = F_12 ( V_2 ) ;
if ( V_31 )
return V_31 ;
V_2 -> V_19 = F_13 ( V_25 , 0 ) ;
V_28 = V_27 -> V_37 / 32 ;
if ( ( V_28 * 32 ) < V_27 -> V_37 ) {
V_29 = V_27 -> V_37 - ( V_28 * 32 ) ;
V_28 ++ ;
} else {
V_29 = 0 ;
}
V_31 = F_14 ( V_2 , V_28 ) ;
if ( V_31 )
return V_31 ;
for ( V_30 = 0 ; V_30 < V_28 ; V_30 ++ ) {
V_4 = & V_2 -> V_38 [ V_30 ] ;
V_4 -> type = V_39 ;
V_4 -> V_40 = V_41 | V_42 ;
V_4 -> V_37 = ( ( V_30 * 32 ) < V_27 -> V_37 ) ? 32 : V_29 ;
V_4 -> V_43 = 1 ;
V_4 -> V_44 = & V_45 ;
V_4 -> V_46 = F_1 ;
V_4 -> V_47 = F_5 ;
V_4 -> V_12 = 0 ;
F_3 ( V_4 -> V_12 , V_2 -> V_19 + F_4 ( V_30 ) ) ;
}
return 0 ;
}
static int F_15 ( struct V_24 * V_2 ,
const struct V_48 * V_49 )
{
return F_16 ( V_2 , & V_50 , V_49 -> V_51 ) ;
}
