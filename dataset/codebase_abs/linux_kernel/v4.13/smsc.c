static int F_1 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_2 , V_4 ,
( ( V_5 == V_2 -> V_6 )
? V_7
: 0 ) ) ;
return V_3 < 0 ? V_3 : 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_3 = F_4 ( V_2 , V_8 ) ;
return V_3 < 0 ? V_3 : 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
int V_3 = F_4 ( V_2 , V_11 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_10 -> V_12 ) {
V_3 = F_2 ( V_2 , V_11 ,
V_3 | V_13 ) ;
if ( V_3 < 0 )
return V_3 ;
}
return F_3 ( V_2 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_3 = F_4 ( V_2 , V_14 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( ( V_3 & V_15 ) == V_16 ) {
V_3 |= V_17 ;
F_2 ( V_2 , V_14 , V_3 ) ;
}
return F_7 ( V_2 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
return F_3 ( V_2 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
int V_18 = F_10 ( V_2 ) ;
if ( ! V_2 -> V_19 && V_10 -> V_12 ) {
int V_20 ;
int V_3 = F_4 ( V_2 , V_11 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_2 , V_11 ,
V_3 & ~ V_13 ) ;
if ( V_3 < 0 )
return V_3 ;
for ( V_20 = 0 ; V_20 < 64 ; V_20 ++ ) {
F_11 ( 10 ) ;
V_3 = F_4 ( V_2 , V_11 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_3 & V_21 )
break;
}
V_3 = F_4 ( V_2 , V_11 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_2 , V_11 ,
V_3 | V_13 ) ;
if ( V_3 < 0 )
return V_3 ;
}
return V_18 ;
}
static int F_12 ( struct V_1 * V_2 )
{
return F_13 ( V_22 ) ;
}
static void F_14 ( struct V_1 * V_2 , T_1 * V_23 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < F_13 ( V_22 ) ; V_20 ++ ) {
strncpy ( V_23 + V_20 * V_24 ,
V_22 [ V_20 ] . string , V_24 ) ;
}
}
static T_2 F_15 ( struct V_1 * V_2 , int V_20 )
{
struct V_25 V_26 = V_22 [ V_20 ] ;
int V_27 ;
T_2 V_28 ;
V_27 = F_4 ( V_2 , V_26 . V_29 ) ;
if ( V_27 < 0 )
V_28 = V_30 ;
else
V_28 = V_27 ;
return V_28 ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_31 * V_32 , T_2 * V_23 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < F_13 ( V_22 ) ; V_20 ++ )
V_23 [ V_20 ] = F_15 ( V_2 , V_20 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = & V_2 -> V_35 . V_34 ;
struct V_36 * V_37 = V_34 -> V_37 ;
struct V_9 * V_10 ;
V_10 = F_18 ( V_34 , sizeof( * V_10 ) , V_38 ) ;
if ( ! V_10 )
return - V_39 ;
V_10 -> V_12 = true ;
if ( F_19 ( V_37 , L_1 ) )
V_10 -> V_12 = false ;
V_2 -> V_10 = V_10 ;
return 0 ;
}
