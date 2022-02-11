static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_3 = F_3 ( V_2 -> V_7 , V_6 -> V_8 . V_9 , & V_4 ) ;
if ( V_3 != 0 ) {
F_4 ( & V_2 -> V_10 , L_1 , V_3 ) ;
return V_3 ;
}
return ( V_4 & V_6 -> V_11 ) ? V_12 : V_13 ;
}
static int F_5 ( struct V_1 * V_2 , unsigned int V_14 )
{
int V_3 , V_15 = 0 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_6 -> V_16 ) {
F_4 ( & V_2 -> V_10 , L_2 ,
V_6 -> V_8 . V_17 ) ;
return - V_18 ;
}
switch ( V_14 ) {
case V_19 :
V_15 = V_20 ;
break;
case V_21 :
V_15 = V_22 ;
break;
default:
return - V_18 ;
}
V_15 <<= F_6 ( V_6 -> V_16 ) - 1 ;
V_3 = F_7 ( V_2 -> V_7 , V_6 -> V_23 ,
V_6 -> V_16 , V_15 ) ;
return V_3 ;
}
static unsigned int F_8 ( struct V_1 * V_2 )
{
unsigned int V_15 ;
unsigned int V_14 ;
int V_3 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_6 -> V_16 ) {
F_4 ( & V_2 -> V_10 , L_3 ,
V_6 -> V_8 . V_17 ) ;
return - V_18 ;
}
V_3 = F_3 ( V_2 -> V_7 , V_6 -> V_23 , & V_15 ) ;
if ( V_3 < 0 )
return V_3 ;
V_15 &= V_6 -> V_16 ;
V_15 >>= F_6 ( V_6 -> V_16 ) - 1 ;
if ( V_15 & 0x1 )
V_14 = V_19 ;
else
V_14 = V_21 ;
return V_14 ;
}
static int F_9 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = F_10 ( V_25 -> V_10 . V_28 ) ;
int V_29 ;
T_1 V_4 ;
for ( V_29 = 0 ; V_29 < V_30 ; V_29 ++ ) {
if ( V_31 [ V_29 ] . V_32 ) {
if ( F_3 ( V_27 -> V_7 ,
V_31 [ V_29 ] . V_32 ,
& V_4 ) < 0 ) {
F_4 ( & V_25 -> V_10 ,
L_4 ) ;
return - V_33 ;
}
if ( V_4 & V_31 [ V_29 ] . V_34 ) {
V_31 [ V_29 ] . V_8 . V_35 =
V_31 [ V_29 ] . V_36 ;
}
}
}
return 0 ;
}
static int F_11 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = F_10 ( V_25 -> V_10 . V_28 ) ;
struct V_37 V_38 = {} ;
struct V_1 * V_2 ;
int V_29 ;
T_1 V_39 ;
if ( F_9 ( V_25 ) )
return - V_33 ;
if ( F_3 ( V_27 -> V_7 , V_40 , & V_39 ) < 0 ) {
F_4 ( & V_25 -> V_10 , L_5 ) ;
return - V_33 ;
}
F_12 ( & V_25 -> V_10 , L_6 , V_39 ) ;
for ( V_29 = 0 ; V_29 < V_30 ; V_29 ++ ) {
V_38 . V_10 = & V_25 -> V_10 ;
V_38 . V_41 = & V_31 [ V_29 ] ;
V_38 . V_7 = V_27 -> V_7 ;
V_2 = F_13 ( & V_25 -> V_10 ,
& V_31 [ V_29 ] . V_8 , & V_38 ) ;
if ( F_14 ( V_2 ) ) {
F_4 ( & V_25 -> V_10 , L_7 ,
V_31 [ V_29 ] . V_8 . V_17 ) ;
return F_15 ( V_2 ) ;
}
}
return 0 ;
}
