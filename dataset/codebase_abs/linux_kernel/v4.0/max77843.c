static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
int V_4 ;
unsigned int V_5 ;
V_4 = F_2 ( V_3 , V_2 -> V_6 -> V_7 , & V_5 ) ;
if ( V_4 ) {
F_3 ( & V_2 -> V_8 , L_1 ) ;
return V_4 ;
}
return ( V_5 & V_2 -> V_6 -> V_9 ) == V_2 -> V_6 -> V_9 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
unsigned int V_10 = V_2 -> V_11 -> V_12 ;
unsigned int V_13 = V_2 -> V_11 -> V_14 ;
unsigned int V_15 ;
int V_4 ;
unsigned int V_5 , V_16 ;
V_4 = F_2 ( V_3 , V_17 , & V_5 ) ;
if ( V_4 ) {
F_3 ( & V_2 -> V_8 , L_2 ) ;
return V_4 ;
}
V_16 = V_5 & V_18 ;
if ( V_16 < 0x03 )
V_16 = 0 ;
else
V_16 -= 2 ;
V_15 = V_10 + V_19 * V_16 ;
if ( V_15 > V_13 )
return - V_20 ;
return V_15 ;
}
static int F_5 ( struct V_1 * V_2 ,
int V_12 , int V_14 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
unsigned int V_10 = V_2 -> V_11 -> V_12 ;
int V_16 = 0 ;
while ( V_10 + V_19 * V_16 < V_12 )
V_16 ++ ;
if ( V_10 + V_19 * V_16 > V_14 )
return - V_20 ;
V_16 += 2 ;
return F_6 ( V_3 , V_17 , V_16 ) ;
}
static struct V_3 * F_7 ( struct V_21 * V_21 , int V_22 )
{
switch ( V_22 ) {
case V_23 :
case V_24 :
return V_21 -> V_3 ;
case V_25 :
return V_21 -> V_26 ;
default:
return V_21 -> V_3 ;
}
}
static int F_8 ( struct V_27 * V_28 )
{
struct V_21 * V_21 = F_9 ( V_28 -> V_8 . V_29 ) ;
struct V_30 V_31 = {} ;
int V_32 ;
V_31 . V_8 = V_21 -> V_8 ;
V_31 . V_33 = V_21 ;
for ( V_32 = 0 ; V_32 < F_10 ( V_34 ) ; V_32 ++ ) {
struct V_1 * V_35 ;
V_31 . V_3 = F_7 ( V_21 ,
V_34 [ V_32 ] . V_36 ) ;
V_35 = F_11 ( & V_28 -> V_8 ,
& V_34 [ V_32 ] , & V_31 ) ;
if ( F_12 ( V_35 ) ) {
F_3 ( & V_28 -> V_8 ,
L_3 , V_32 ) ;
return F_13 ( V_35 ) ;
}
}
return 0 ;
}
static int T_1 F_14 ( void )
{
return F_15 ( & V_37 ) ;
}
static void T_2 F_16 ( void )
{
F_17 ( & V_37 ) ;
}
