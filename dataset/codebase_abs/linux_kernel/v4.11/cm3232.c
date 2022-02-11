static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_5 ;
V_2 -> V_6 = & V_7 ;
V_5 = F_2 ( V_4 , V_8 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_4 -> V_9 , L_1 ) ;
return V_5 ;
}
if ( ( V_5 & 0xFF ) != V_2 -> V_6 -> V_10 )
return - V_11 ;
V_2 -> V_12 = V_13 | V_14 ;
V_5 = F_4 ( V_4 , V_15 ,
V_2 -> V_12 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_4 -> V_9 , L_2 ) ;
return V_5 ;
}
V_2 -> V_12 = V_2 -> V_6 -> V_16 ;
V_5 = F_4 ( V_4 , V_15 ,
V_2 -> V_12 ) ;
if ( V_5 < 0 )
F_3 ( & V_2 -> V_4 -> V_9 , L_2 ) ;
return V_5 ;
}
static int F_5 ( struct V_1 * V_2 , int * V_17 , int * V_18 )
{
T_2 V_19 ;
int V_20 ;
V_19 = V_2 -> V_12 ;
V_19 &= V_21 ;
V_19 >>= V_22 ;
for ( V_20 = 0 ; V_20 < F_6 ( V_23 ) ; V_20 ++ ) {
if ( V_19 == V_23 [ V_20 ] . V_24 ) {
* V_17 = V_23 [ V_20 ] . V_17 ;
* V_18 = V_23 [ V_20 ] . V_18 ;
return V_25 ;
}
}
return - V_26 ;
}
static int F_7 ( struct V_1 * V_2 , int V_17 , int V_18 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_2 V_19 , V_27 ;
int V_20 ;
T_1 V_5 ;
for ( V_20 = 0 ; V_20 < F_6 ( V_23 ) ; V_20 ++ ) {
if ( V_17 == V_23 [ V_20 ] . V_17 &&
V_18 == V_23 [ V_20 ] . V_18 ) {
V_19 = V_23 [ V_20 ] . V_24 ;
V_19 <<= V_22 ;
V_27 = V_2 -> V_12 & ~ V_21 ;
V_27 |= V_19 ;
V_5 = F_4 ( V_4 ,
V_15 ,
V_27 ) ;
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_12 = V_27 ;
return 0 ;
}
}
return - V_26 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_28 * V_6 = V_2 -> V_6 ;
int V_5 ;
int V_17 , V_18 ;
int V_19 ;
T_3 V_29 ;
V_5 = F_5 ( V_2 , & V_17 , & V_18 ) ;
if ( V_5 < 0 )
return - V_26 ;
V_19 = V_17 * 1000000 + V_18 ;
V_29 = ( V_30 T_3 ) V_6 -> V_31 ;
V_29 *= V_6 -> V_32 ;
V_29 = F_9 ( V_29 , V_19 ) ;
V_5 = F_2 ( V_4 , V_33 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_9 , L_3 ) ;
return V_5 ;
}
V_2 -> V_34 = ( T_2 ) V_5 ;
V_29 *= V_2 -> V_34 ;
V_29 *= V_6 -> V_35 ;
V_29 = F_9 ( V_29 , V_36 ) ;
V_29 = F_9 ( V_29 , V_37 ) ;
if ( V_29 > 0xFFFF )
V_29 = 0xFFFF ;
return ( int ) V_29 ;
}
static int F_10 ( struct V_38 * V_39 ,
struct V_40 const * V_41 ,
int * V_17 , int * V_18 , long V_42 )
{
struct V_1 * V_2 = F_11 ( V_39 ) ;
struct V_28 * V_6 = V_2 -> V_6 ;
int V_5 ;
switch ( V_42 ) {
case V_43 :
V_5 = F_8 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
* V_17 = V_5 ;
return V_44 ;
case V_45 :
* V_17 = V_6 -> V_35 ;
return V_44 ;
case V_46 :
return F_5 ( V_2 , V_17 , V_18 ) ;
}
return - V_26 ;
}
static int F_12 ( struct V_38 * V_39 ,
struct V_40 const * V_41 ,
int V_17 , int V_18 , long V_42 )
{
struct V_1 * V_2 = F_11 ( V_39 ) ;
struct V_28 * V_6 = V_2 -> V_6 ;
switch ( V_42 ) {
case V_45 :
V_6 -> V_35 = V_17 ;
return 0 ;
case V_46 :
return F_7 ( V_2 , V_17 , V_18 ) ;
}
return - V_26 ;
}
static T_4 F_13 ( struct V_47 * V_9 ,
struct V_48 * V_49 , char * V_50 )
{
int V_20 , V_51 ;
for ( V_20 = 0 , V_51 = 0 ; V_20 < F_6 ( V_23 ) ; V_20 ++ )
V_51 += F_14 ( V_50 + V_51 , V_52 - V_51 , L_4 ,
V_23 [ V_20 ] . V_17 ,
V_23 [ V_20 ] . V_18 ) ;
return V_51 + F_14 ( V_50 + V_51 , V_52 - V_51 , L_5 ) ;
}
static int F_15 ( struct V_3 * V_4 ,
const struct V_53 * V_54 )
{
struct V_1 * V_2 ;
struct V_38 * V_39 ;
int V_5 ;
V_39 = F_16 ( & V_4 -> V_9 , sizeof( * V_2 ) ) ;
if ( ! V_39 )
return - V_55 ;
V_2 = F_11 ( V_39 ) ;
F_17 ( V_4 , V_39 ) ;
V_2 -> V_4 = V_4 ;
V_39 -> V_9 . V_56 = & V_4 -> V_9 ;
V_39 -> V_57 = V_58 ;
V_39 -> V_59 = F_6 ( V_58 ) ;
V_39 -> V_60 = & V_61 ;
V_39 -> V_62 = V_54 -> V_62 ;
V_39 -> V_63 = V_64 ;
V_5 = F_1 ( V_2 ) ;
if ( V_5 ) {
F_3 ( & V_4 -> V_9 ,
L_6 ,
V_65 ) ;
return V_5 ;
}
return F_18 ( V_39 ) ;
}
static int F_19 ( struct V_3 * V_4 )
{
struct V_38 * V_39 = F_20 ( V_4 ) ;
F_4 ( V_4 , V_15 ,
V_13 ) ;
F_21 ( V_39 ) ;
return 0 ;
}
static int F_22 ( struct V_47 * V_9 )
{
struct V_38 * V_39 = F_20 ( F_23 ( V_9 ) ) ;
struct V_1 * V_2 = F_11 ( V_39 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 ;
V_2 -> V_12 |= V_13 ;
V_5 = F_4 ( V_4 , V_15 ,
V_2 -> V_12 ) ;
return V_5 ;
}
static int F_24 ( struct V_47 * V_9 )
{
struct V_38 * V_39 = F_20 ( F_23 ( V_9 ) ) ;
struct V_1 * V_2 = F_11 ( V_39 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 ;
V_2 -> V_12 &= ~ V_13 ;
V_5 = F_4 ( V_4 , V_15 ,
V_2 -> V_12 | V_14 ) ;
return V_5 ;
}
