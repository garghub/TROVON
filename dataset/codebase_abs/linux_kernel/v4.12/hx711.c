static int F_1 ( int V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
if ( V_4 [ V_2 ] . V_1 == V_1 )
return V_4 [ V_2 ] . V_5 ;
return 1 ;
}
static int F_2 ( int V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
if ( V_4 [ V_2 ] . V_1 == V_1 )
return V_4 [ V_2 ] . V_6 ;
return 0 ;
}
static int F_3 ( int V_6 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
if ( V_4 [ V_2 ] . V_6 == V_6 )
return V_4 [ V_2 ] . V_1 ;
return - V_7 ;
}
static int F_4 ( struct V_8 * V_8 )
{
int V_9 ;
F_5 () ;
F_6 ( V_8 -> V_10 , 1 ) ;
V_9 = F_7 ( V_8 -> V_11 ) ;
F_6 ( V_8 -> V_10 , 0 ) ;
F_8 () ;
return V_9 ;
}
static int F_9 ( struct V_8 * V_8 )
{
int V_2 , V_12 ;
int V_13 = 0 ;
int V_9 = F_7 ( V_8 -> V_11 ) ;
if ( V_9 )
return - V_14 ;
for ( V_2 = 0 ; V_2 < 24 ; V_2 ++ ) {
V_13 <<= 1 ;
V_12 = F_4 ( V_8 ) ;
if ( V_12 )
V_13 ++ ;
}
V_13 ^= 0x800000 ;
for ( V_2 = 0 ; V_2 < F_1 ( V_8 -> V_15 ) ; V_2 ++ )
F_4 ( V_8 ) ;
return V_13 ;
}
static int F_10 ( struct V_8 * V_8 )
{
int V_2 , V_9 ;
for ( V_2 = 0 ; V_2 < 100 ; V_2 ++ ) {
V_9 = F_7 ( V_8 -> V_11 ) ;
if ( ! V_9 )
break;
F_11 ( 1 ) ;
}
if ( V_9 )
return - V_14 ;
return 0 ;
}
static int F_12 ( struct V_8 * V_8 )
{
int V_12 ;
int V_9 = F_7 ( V_8 -> V_11 ) ;
if ( V_9 ) {
F_6 ( V_8 -> V_10 , 1 ) ;
F_11 ( 10 ) ;
F_6 ( V_8 -> V_10 , 0 ) ;
V_12 = F_10 ( V_8 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_9 ( V_8 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_10 ( V_8 ) ;
if ( V_12 )
return V_12 ;
}
return V_9 ;
}
static int F_13 ( struct V_8 * V_8 , int V_16 )
{
int V_12 ;
if ( V_16 == 0 ) {
if ( V_8 -> V_15 == 32 ) {
V_8 -> V_15 = V_8 -> V_17 ;
V_12 = F_9 ( V_8 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_10 ( V_8 ) ;
if ( V_12 )
return V_12 ;
}
} else {
if ( V_8 -> V_15 != 32 ) {
V_8 -> V_15 = 32 ;
V_12 = F_9 ( V_8 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_10 ( V_8 ) ;
if ( V_12 )
return V_12 ;
}
}
return 0 ;
}
static int F_14 ( struct V_18 * V_19 ,
const struct V_20 * V_16 ,
int * V_9 , int * V_21 , long V_22 )
{
struct V_8 * V_8 = F_15 ( V_19 ) ;
int V_12 ;
switch ( V_22 ) {
case V_23 :
F_16 ( & V_8 -> V_24 ) ;
if ( F_12 ( V_8 ) ) {
F_17 ( & V_8 -> V_24 ) ;
F_18 ( V_8 -> V_25 , L_1 ) ;
return - V_14 ;
}
V_12 = F_13 ( V_8 , V_16 -> V_26 ) ;
if ( V_12 < 0 ) {
F_17 ( & V_8 -> V_24 ) ;
return V_12 ;
}
* V_9 = F_9 ( V_8 ) ;
F_17 ( & V_8 -> V_24 ) ;
if ( * V_9 < 0 )
return * V_9 ;
return V_27 ;
case V_28 :
* V_9 = 0 ;
F_16 ( & V_8 -> V_24 ) ;
* V_21 = F_2 ( V_8 -> V_15 ) ;
F_17 ( & V_8 -> V_24 ) ;
return V_29 ;
default:
return - V_7 ;
}
}
static int F_19 ( struct V_18 * V_19 ,
struct V_20 const * V_16 ,
int V_9 ,
int V_21 ,
long V_22 )
{
struct V_8 * V_8 = F_15 ( V_19 ) ;
int V_12 ;
int V_1 ;
switch ( V_22 ) {
case V_28 :
if ( V_9 != 0 )
return - V_7 ;
F_16 ( & V_8 -> V_24 ) ;
V_1 = F_3 ( V_21 ) ;
if ( V_1 < 0 ) {
F_17 ( & V_8 -> V_24 ) ;
return V_1 ;
}
if ( V_1 != V_8 -> V_15 ) {
V_8 -> V_15 = V_1 ;
if ( V_1 != 32 )
V_8 -> V_17 = V_1 ;
V_12 = F_9 ( V_8 ) ;
if ( V_12 < 0 ) {
F_17 ( & V_8 -> V_24 ) ;
return V_12 ;
}
}
F_17 ( & V_8 -> V_24 ) ;
return 0 ;
default:
return - V_7 ;
}
return 0 ;
}
static int F_20 ( struct V_18 * V_19 ,
struct V_20 const * V_16 ,
long V_22 )
{
return V_29 ;
}
static T_1 F_21 ( struct V_30 * V_25 ,
struct V_31 * V_32 ,
char * V_33 )
{
struct V_34 * V_35 = F_22 ( V_32 ) ;
int V_26 = V_35 -> V_36 ;
int V_2 , V_37 = 0 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
if ( V_4 [ V_2 ] . V_26 == V_26 )
V_37 += sprintf ( V_33 + V_37 , L_2 ,
V_4 [ V_2 ] . V_6 ) ;
V_37 += sprintf ( V_33 + V_37 , L_3 ) ;
return V_37 ;
}
static int F_23 ( struct V_38 * V_39 )
{
struct V_30 * V_25 = & V_39 -> V_25 ;
struct V_8 * V_8 ;
struct V_18 * V_19 ;
int V_12 ;
int V_2 ;
V_19 = F_24 ( V_25 , sizeof( struct V_8 ) ) ;
if ( ! V_19 ) {
F_18 ( V_25 , L_4 ) ;
return - V_40 ;
}
V_8 = F_15 ( V_19 ) ;
V_8 -> V_25 = V_25 ;
F_25 ( & V_8 -> V_24 ) ;
V_8 -> V_10 = F_26 ( V_25 , L_5 , V_41 ) ;
if ( F_27 ( V_8 -> V_10 ) ) {
F_18 ( V_25 , L_6 ,
F_28 ( V_8 -> V_10 ) ) ;
return F_28 ( V_8 -> V_10 ) ;
}
V_8 -> V_11 = F_26 ( V_25 , L_7 , V_42 ) ;
if ( F_27 ( V_8 -> V_11 ) ) {
F_18 ( V_25 , L_8 ,
F_28 ( V_8 -> V_11 ) ) ;
return F_28 ( V_8 -> V_11 ) ;
}
V_8 -> V_43 = F_29 ( V_25 , L_9 ) ;
if ( F_27 ( V_8 -> V_43 ) )
return F_28 ( V_8 -> V_43 ) ;
V_12 = F_30 ( V_8 -> V_43 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_31 ( V_8 -> V_43 ) ;
if ( V_12 < 0 ) {
F_32 ( V_8 -> V_43 ) ;
return V_12 ;
}
V_12 *= 100 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
V_4 [ V_2 ] . V_6 =
V_12 / V_4 [ V_2 ] . V_1 / 1678 ;
V_8 -> V_15 = 128 ;
V_8 -> V_17 = 128 ;
F_33 ( V_39 , V_19 ) ;
V_19 -> V_44 = L_10 ;
V_19 -> V_25 . V_45 = & V_39 -> V_25 ;
V_19 -> V_46 = & V_47 ;
V_19 -> V_48 = V_49 ;
V_19 -> V_50 = V_51 ;
V_19 -> V_52 = F_34 ( V_51 ) ;
V_12 = F_35 ( V_19 ) ;
if ( V_12 < 0 ) {
F_18 ( V_25 , L_11 ) ;
F_32 ( V_8 -> V_43 ) ;
}
return V_12 ;
}
static int F_36 ( struct V_38 * V_39 )
{
struct V_8 * V_8 ;
struct V_18 * V_19 ;
V_19 = F_37 ( V_39 ) ;
V_8 = F_15 ( V_19 ) ;
F_38 ( V_19 ) ;
F_32 ( V_8 -> V_43 ) ;
return 0 ;
}
