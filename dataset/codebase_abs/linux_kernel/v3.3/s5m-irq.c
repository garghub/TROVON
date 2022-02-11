static inline struct V_1 *
F_1 ( struct V_2 * V_3 , int V_4 )
{
return & V_5 [ V_4 - V_3 -> V_6 ] ;
}
static void F_2 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
F_4 ( & V_3 -> V_9 ) ;
}
static void F_5 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
int V_10 ;
for ( V_10 = 0 ; V_10 < F_6 ( V_3 -> V_11 ) ; V_10 ++ ) {
if ( V_3 -> V_11 [ V_10 ] != V_3 -> V_12 [ V_10 ] ) {
V_3 -> V_12 [ V_10 ] = V_3 -> V_11 [ V_10 ] ;
F_7 ( V_3 , V_13 + V_10 ,
V_3 -> V_11 [ V_10 ] ) ;
}
}
F_8 ( & V_3 -> V_9 ) ;
}
static void F_9 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
struct V_1 * V_7 = F_1 ( V_3 ,
V_8 -> V_4 ) ;
V_3 -> V_11 [ V_7 -> V_14 - 1 ] &= ~ V_7 -> V_15 ;
}
static void F_10 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
struct V_1 * V_7 = F_1 ( V_3 ,
V_8 -> V_4 ) ;
V_3 -> V_11 [ V_7 -> V_14 - 1 ] |= V_7 -> V_15 ;
}
static inline struct V_1 *
F_11 ( struct V_2 * V_3 , int V_4 )
{
return & V_16 [ V_4 - V_3 -> V_6 ] ;
}
static void F_12 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
F_4 ( & V_3 -> V_9 ) ;
}
static void F_13 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
int V_10 ;
for ( V_10 = 0 ; V_10 < F_6 ( V_3 -> V_11 ) ; V_10 ++ ) {
if ( V_3 -> V_11 [ V_10 ] != V_3 -> V_12 [ V_10 ] ) {
V_3 -> V_12 [ V_10 ] = V_3 -> V_11 [ V_10 ] ;
F_7 ( V_3 , V_17 + V_10 ,
V_3 -> V_11 [ V_10 ] ) ;
}
}
F_8 ( & V_3 -> V_9 ) ;
}
static void F_14 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
struct V_1 * V_7 = F_11 ( V_3 ,
V_8 -> V_4 ) ;
V_3 -> V_11 [ V_7 -> V_14 - 1 ] &= ~ V_7 -> V_15 ;
}
static void F_15 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
struct V_1 * V_7 = F_11 ( V_3 ,
V_8 -> V_4 ) ;
V_3 -> V_11 [ V_7 -> V_14 - 1 ] |= V_7 -> V_15 ;
}
static T_1 F_16 ( int V_4 , void * V_8 )
{
struct V_2 * V_3 = V_8 ;
T_2 V_18 [ V_19 - 1 ] ;
int V_20 ;
int V_10 ;
V_20 = F_17 ( V_3 , V_21 ,
V_19 - 1 , V_18 ) ;
if ( V_20 < 0 ) {
F_18 ( V_3 -> V_22 , L_1 ,
V_20 ) ;
return V_23 ;
}
for ( V_10 = 0 ; V_10 < V_19 - 1 ; V_10 ++ )
V_18 [ V_10 ] &= ~ V_3 -> V_11 [ V_10 ] ;
for ( V_10 = 0 ; V_10 < V_24 ; V_10 ++ ) {
if ( V_18 [ V_5 [ V_10 ] . V_14 - 1 ] & V_5 [ V_10 ] . V_15 )
F_19 ( V_3 -> V_6 + V_10 ) ;
}
return V_25 ;
}
static T_1 F_20 ( int V_4 , void * V_8 )
{
struct V_2 * V_3 = V_8 ;
T_2 V_18 [ V_19 ] ;
int V_20 ;
int V_10 ;
V_20 = F_17 ( V_3 , V_26 ,
V_19 , V_18 ) ;
if ( V_20 < 0 ) {
F_18 ( V_3 -> V_22 , L_1 ,
V_20 ) ;
return V_23 ;
}
for ( V_10 = 0 ; V_10 < V_19 ; V_10 ++ )
V_18 [ V_10 ] &= ~ V_3 -> V_11 [ V_10 ] ;
for ( V_10 = 0 ; V_10 < V_27 ; V_10 ++ ) {
if ( V_18 [ V_16 [ V_10 ] . V_14 - 1 ] & V_16 [ V_10 ] . V_15 )
F_19 ( V_3 -> V_6 + V_10 ) ;
}
return V_25 ;
}
int F_21 ( struct V_2 * V_3 )
{
if ( V_3 -> V_4 && V_3 -> V_6 ) {
switch ( V_3 -> V_28 ) {
case V_29 :
F_20 ( V_3 -> V_6 , V_3 ) ;
break;
case V_30 :
F_16 ( V_3 -> V_6 , V_3 ) ;
break;
default:
break;
}
}
return 0 ;
}
int F_22 ( struct V_2 * V_3 )
{
int V_10 ;
int V_31 ;
int V_20 = 0 ;
int type = V_3 -> V_28 ;
if ( ! V_3 -> V_4 ) {
F_23 ( V_3 -> V_22 ,
L_2 ) ;
V_3 -> V_6 = 0 ;
return 0 ;
}
if ( ! V_3 -> V_6 ) {
F_18 ( V_3 -> V_22 ,
L_3 ) ;
return 0 ;
}
F_24 ( & V_3 -> V_9 ) ;
switch ( type ) {
case V_29 :
for ( V_10 = 0 ; V_10 < V_19 ; V_10 ++ ) {
V_3 -> V_11 [ V_10 ] = 0xff ;
V_3 -> V_12 [ V_10 ] = 0xff ;
F_7 ( V_3 , V_17 + V_10 ,
0xff ) ;
}
F_7 ( V_3 , V_32 , 0xff ) ;
F_7 ( V_3 , V_33 , 0xff ) ;
for ( V_10 = 0 ; V_10 < V_27 ; V_10 ++ ) {
V_31 = V_10 + V_3 -> V_6 ;
F_25 ( V_31 , V_3 ) ;
F_26 ( V_31 , & V_34 ,
V_35 ) ;
F_27 ( V_31 , 1 ) ;
#ifdef F_28
F_29 ( V_31 , V_36 ) ;
#else
F_30 ( V_31 ) ;
#endif
}
V_20 = F_31 ( V_3 -> V_4 , NULL ,
F_20 ,
V_37 | V_38 ,
L_4 , V_3 ) ;
if ( V_20 ) {
F_18 ( V_3 -> V_22 , L_5 ,
V_3 -> V_4 , V_20 ) ;
return V_20 ;
}
break;
case V_30 :
for ( V_10 = 0 ; V_10 < V_19 - 1 ; V_10 ++ ) {
V_3 -> V_11 [ V_10 ] = 0xff ;
V_3 -> V_12 [ V_10 ] = 0xff ;
F_7 ( V_3 , V_13 + V_10 ,
0xff ) ;
}
for ( V_10 = 0 ; V_10 < V_24 ; V_10 ++ ) {
V_31 = V_10 + V_3 -> V_6 ;
F_25 ( V_31 , V_3 ) ;
if ( V_20 ) {
F_18 ( V_3 -> V_22 ,
L_6 ,
V_3 -> V_4 , V_20 ) ;
return V_20 ;
}
F_26 ( V_31 , & V_39 ,
V_35 ) ;
F_27 ( V_31 , 1 ) ;
#ifdef F_28
F_29 ( V_31 , V_36 ) ;
#else
F_30 ( V_31 ) ;
#endif
}
V_20 = F_31 ( V_3 -> V_4 , NULL ,
F_16 ,
V_37 | V_38 ,
L_4 , V_3 ) ;
if ( V_20 ) {
F_18 ( V_3 -> V_22 , L_5 ,
V_3 -> V_4 , V_20 ) ;
return V_20 ;
}
break;
default:
break;
}
if ( ! V_3 -> V_40 )
return 0 ;
switch ( type ) {
case V_29 :
V_20 = F_31 ( V_3 -> V_40 , NULL ,
F_20 ,
V_37 |
V_41 |
V_38 , L_7 ,
V_3 ) ;
break;
case V_30 :
V_20 = F_31 ( V_3 -> V_40 , NULL ,
F_16 ,
V_37 |
V_41 |
V_38 , L_7 , V_3 ) ;
break;
default:
break;
}
if ( V_20 )
F_18 ( V_3 -> V_22 , L_5 ,
V_3 -> V_40 , V_20 ) ;
return 0 ;
}
void F_32 ( struct V_2 * V_3 )
{
if ( V_3 -> V_40 )
F_33 ( V_3 -> V_40 , V_3 ) ;
if ( V_3 -> V_4 )
F_33 ( V_3 -> V_4 , V_3 ) ;
}
