static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 , V_4 , V_3 & 0xfff ) ;
}
int F_3 ( struct V_1 * V_2 , bool V_5 )
{
T_1 V_6 ;
int V_7 ;
V_7 = F_4 ( V_2 , V_8 , & V_6 ) ;
if ( V_7 )
return V_7 ;
if ( V_5 )
V_6 |= V_9 ;
else
V_6 &= ~ V_9 ;
return F_2 ( V_2 , V_8 , V_6 ) ;
}
int F_5 ( struct V_1 * V_2 ,
unsigned int V_10 )
{
const unsigned int V_11 = V_2 -> V_12 -> V_13 ;
const unsigned int V_14 = 0x01 * V_11 ;
const unsigned int V_15 = 0xff * V_11 ;
T_2 V_16 ;
T_1 V_6 ;
int V_7 ;
if ( V_10 < V_14 || V_10 > V_15 )
return - V_17 ;
V_16 = ( V_10 + V_11 / 2 ) / V_11 ;
V_7 = F_4 ( V_2 , V_8 , & V_6 ) ;
if ( V_7 )
return V_7 ;
V_6 &= ~ 0xff0 ;
V_6 |= V_16 << 4 ;
V_7 = F_2 ( V_2 , V_8 , V_6 ) ;
if ( V_7 )
return V_7 ;
F_6 ( V_2 -> V_18 , L_1 , V_16 ,
V_16 * V_11 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
return F_8 ( V_2 , V_19 , V_20 ) ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_21 )
{
T_1 V_6 ;
int V_7 ;
if ( F_10 ( V_2 ) > 256 ) {
V_7 = F_1 ( V_2 , V_3 ) ;
if ( V_7 )
return V_7 ;
} else {
if ( F_10 ( V_2 ) > 16 ) {
V_7 = F_4 ( V_2 , V_8 , & V_6 ) ;
if ( V_7 )
return V_7 ;
V_6 = ( V_6 & 0x0fff ) | ( ( V_3 << 8 ) & 0xf000 ) ;
V_7 = F_2 ( V_2 , V_8 , V_6 ) ;
if ( V_7 )
return V_7 ;
}
V_21 |= V_3 & 0xf ;
}
V_7 = F_2 ( V_2 , V_19 , V_21 ) ;
if ( V_7 )
return V_7 ;
return F_7 ( V_2 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
T_1 V_6 ;
int V_7 ;
V_7 = F_4 ( V_2 , V_24 , & V_6 ) ;
if ( V_7 )
return V_7 ;
V_23 -> V_25 = V_6 & 0xf ;
if ( V_23 -> V_25 != V_26 ) {
V_23 -> V_27 = ! ! ( V_6 & V_28 ) ;
V_23 -> V_29 = ( V_6 >> 4 ) & F_12 ( V_2 ) ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
T_1 V_30 = V_23 -> V_25 & 0xf ;
if ( V_23 -> V_25 != V_26 ) {
if ( V_23 -> V_27 )
V_30 |= V_28 ;
V_30 |= ( V_23 -> V_29 & F_12 ( V_2 ) ) << 4 ;
}
return F_2 ( V_2 , V_24 , V_30 ) ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
T_1 V_6 ;
int V_31 , V_7 ;
for ( V_31 = 0 ; V_31 < 3 ; V_31 ++ ) {
V_7 = F_4 ( V_2 , V_32 + V_31 , & V_6 ) ;
if ( V_7 )
return V_7 ;
V_23 -> V_33 [ V_31 * 2 ] = V_6 >> 8 ;
V_23 -> V_33 [ V_31 * 2 + 1 ] = V_6 & 0xff ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
T_1 V_6 ;
int V_31 , V_7 ;
for ( V_31 = 0 ; V_31 < 3 ; V_31 ++ ) {
V_6 = ( V_23 -> V_33 [ V_31 * 2 ] << 8 ) | V_23 -> V_33 [ V_31 * 2 + 1 ] ;
V_7 = F_2 ( V_2 , V_32 + V_31 , V_6 ) ;
if ( V_7 )
return V_7 ;
}
return 0 ;
}
int F_16 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_22 * V_23 )
{
int V_7 ;
V_7 = F_7 ( V_2 ) ;
if ( V_7 )
return V_7 ;
if ( V_23 -> V_25 == V_26 ) {
V_7 = F_15 ( V_2 , V_23 ) ;
if ( V_7 )
return V_7 ;
}
V_7 = F_9 ( V_2 , V_3 , V_34 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_11 ( V_2 , V_23 ) ;
if ( V_7 )
return V_7 ;
return F_14 ( V_2 , V_23 ) ;
}
int F_17 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_22 * V_23 )
{
int V_7 ;
V_7 = F_7 ( V_2 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_15 ( V_2 , V_23 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_13 ( V_2 , V_23 ) ;
if ( V_7 )
return V_7 ;
return F_9 ( V_2 , V_3 , V_35 ) ;
}
static int F_18 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_22 * V_23 ,
bool V_36 )
{
T_1 V_21 ;
int V_7 ;
V_7 = F_7 ( V_2 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_13 ( V_2 , V_23 ) ;
if ( V_7 )
return V_7 ;
if ( V_36 && V_3 )
V_21 = V_37 ;
else if ( V_3 )
V_21 = V_38 ;
else if ( V_36 )
V_21 = V_39 ;
else
V_21 = V_40 ;
return F_9 ( V_2 , V_3 , V_21 ) ;
}
int F_19 ( struct V_1 * V_2 , T_1 V_3 , bool V_36 )
{
struct V_22 V_23 = {
. V_25 = 0 ,
} ;
return F_18 ( V_2 , V_3 , & V_23 , V_36 ) ;
}
static int F_20 ( struct V_1 * V_2 , T_1 V_3 ,
int V_41 , int V_42 , bool V_36 )
{
struct V_22 V_23 = { 0 } ;
unsigned long V_43 ;
int V_44 ;
if ( ! V_2 -> V_12 -> V_45 )
return - V_46 ;
V_43 = V_2 -> V_12 -> V_45 ;
V_44 = F_21 ( & V_43 , 16 ) ;
V_23 . V_25 = 0xf ,
V_23 . V_29 = V_41 & V_43 ;
V_23 . V_29 |= ( V_42 & V_43 ) << V_44 ;
return F_18 ( V_2 , V_3 , & V_23 , V_36 ) ;
}
int F_22 ( struct V_1 * V_2 , T_1 V_3 , int V_47 ,
bool V_36 )
{
int V_41 = V_47 ;
int V_42 = V_2 -> V_12 -> V_45 ;
return F_20 ( V_2 , V_3 , V_41 , V_42 , V_36 ) ;
}
