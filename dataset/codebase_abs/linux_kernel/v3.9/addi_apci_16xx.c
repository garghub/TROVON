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
static const void * F_9 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
const struct V_25 * V_26 ;
int V_27 ;
for ( V_27 = 0 ; V_27 < F_10 ( V_28 ) ; V_27 ++ ) {
V_26 = & V_28 [ V_27 ] ;
if ( V_26 -> V_29 == V_24 -> V_29 &&
V_26 -> V_30 == V_24 -> V_30 )
return V_26 ;
}
return NULL ;
}
static int F_11 ( struct V_1 * V_2 ,
unsigned long V_31 )
{
struct V_23 * V_24 = F_12 ( V_2 ) ;
const struct V_25 * V_26 ;
struct V_3 * V_4 ;
unsigned int V_32 ;
unsigned int V_33 ;
int V_27 ;
int V_34 ;
V_26 = F_9 ( V_2 , V_24 ) ;
if ( ! V_26 )
return - V_35 ;
V_2 -> V_36 = V_26 ;
V_2 -> V_37 = V_26 -> V_38 ;
V_34 = F_13 ( V_24 , V_2 -> V_37 ) ;
if ( V_34 )
return V_34 ;
V_2 -> V_19 = F_14 ( V_24 , 0 ) ;
V_32 = V_26 -> V_39 / 32 ;
if ( ( V_32 * 32 ) < V_26 -> V_39 ) {
V_33 = V_26 -> V_39 - ( V_32 * 32 ) ;
V_32 ++ ;
} else {
V_33 = 0 ;
}
V_34 = F_15 ( V_2 , V_32 ) ;
if ( V_34 )
return V_34 ;
for ( V_27 = 0 ; V_27 < V_32 ; V_27 ++ ) {
V_4 = & V_2 -> V_40 [ V_27 ] ;
V_4 -> type = V_41 ;
V_4 -> V_42 = V_43 | V_44 ;
V_4 -> V_39 = ( ( V_27 * 32 ) < V_26 -> V_39 ) ? 32 : V_33 ;
V_4 -> V_45 = 1 ;
V_4 -> V_46 = & V_47 ;
V_4 -> V_48 = F_1 ;
V_4 -> V_49 = F_5 ;
V_4 -> V_12 = 0 ;
F_3 ( V_4 -> V_12 , V_2 -> V_19 + F_4 ( V_27 ) ) ;
}
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = F_12 ( V_2 ) ;
if ( V_24 ) {
if ( V_2 -> V_19 )
F_17 ( V_24 ) ;
}
}
static int F_18 ( struct V_23 * V_2 ,
const struct V_50 * V_51 )
{
return F_19 ( V_2 , & V_52 ) ;
}
