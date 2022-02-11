static inline int F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 , void * V_5 )
{
unsigned char V_6 ;
int V_7 ;
V_6 = ( unsigned char ) V_3 ;
V_7 = F_2 ( V_2 , & V_6 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_3 ( V_2 , V_5 , V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static inline int F_4 ( struct V_1 * V_2 ,
int V_3 , int V_4 , void * V_8 )
{
unsigned char V_9 [ V_4 + 1 ] ;
int V_7 ;
V_9 [ 0 ] = ( unsigned char ) V_3 ;
memcpy ( & V_9 [ 1 ] , V_8 , V_4 ) ;
V_7 = F_2 ( V_2 , V_9 , V_4 + 1 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 )
{
struct V_10 * V_11 = F_6 ( V_2 ) ;
unsigned char V_6 ;
int V_7 ;
F_7 ( & V_11 -> V_12 ) ;
V_7 = F_1 ( V_2 , V_3 , 1 , & V_6 ) ;
F_8 ( & V_11 -> V_12 ) ;
if ( V_7 < 0 )
return V_7 ;
return ( int ) V_6 ;
}
static int F_9 ( struct V_1 * V_2 , int V_3 ,
unsigned char V_13 , unsigned char V_6 )
{
struct V_10 * V_11 = F_6 ( V_2 ) ;
unsigned char V_14 ;
int V_7 ;
F_7 ( & V_11 -> V_12 ) ;
V_7 = F_1 ( V_2 , V_3 , 1 , & V_14 ) ;
if ( V_7 < 0 )
goto V_15;
V_14 &= ~ V_13 ;
V_14 |= V_6 ;
V_7 = F_4 ( V_2 , V_3 , 1 , & V_14 ) ;
V_15:
F_8 ( & V_11 -> V_12 ) ;
return V_7 ;
}
static inline int F_10 ( int V_16 , int V_17 )
{
if ( ( V_16 < V_18 ) || ( V_17 > V_19 )
|| ( V_16 > V_17 ) )
return - V_20 ;
return 0 ;
}
static int F_11 ( struct V_21 * V_22 , unsigned V_23 )
{
return ( V_18 + V_23 * V_24 ) ;
}
static int F_12 ( struct V_21 * V_22 )
{
struct V_10 * V_11 = F_13 ( V_22 ) ;
unsigned char V_6 ;
int V_7 ;
V_7 = F_5 ( V_11 -> V_2 , V_11 -> V_25 ) ;
if ( V_7 < 0 )
return V_7 ;
V_6 = ( unsigned char ) V_7 & V_26 ;
return F_11 ( V_22 , V_6 ) ;
}
static int F_14 ( struct V_21 * V_22 ,
int V_16 , int V_17 , unsigned * V_27 )
{
struct V_10 * V_11 = F_13 ( V_22 ) ;
unsigned char V_6 , V_13 ;
if ( F_10 ( V_16 , V_17 ) ) {
F_15 ( V_11 -> V_28 , L_1 ,
V_16 , V_17 ) ;
return - V_20 ;
}
V_6 = ( V_16 - V_18 + V_24 - 1 )
/ V_24 ;
V_13 = V_26 ;
* V_27 = V_6 & V_13 ;
return F_9 ( V_11 -> V_2 , V_11 -> V_25 , V_13 , V_6 ) ;
}
static int F_16 ( struct V_21 * V_22 )
{
struct V_10 * V_11 = F_13 ( V_22 ) ;
return F_9 ( V_11 -> V_2 , V_29 , V_30 , 0 ) ;
}
static int F_17 ( struct V_21 * V_22 )
{
struct V_10 * V_11 = F_13 ( V_22 ) ;
return F_9 ( V_11 -> V_2 , V_29 , V_30 ,
V_30 ) ;
}
static int F_18 ( struct V_21 * V_22 )
{
struct V_10 * V_11 = F_13 ( V_22 ) ;
int V_7 ;
V_7 = F_5 ( V_11 -> V_2 , V_29 ) ;
if ( V_7 < 0 )
return V_7 ;
return ! ( ( unsigned char ) V_7 & V_30 ) ;
}
static int F_19 ( struct V_21 * V_22 )
{
struct V_10 * V_11 = F_13 ( V_22 ) ;
int V_31 , V_32 , V_7 ;
V_7 = F_5 ( V_11 -> V_2 , V_11 -> V_25 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 &= V_26 ;
V_31 = F_11 ( V_22 , ( unsigned char ) V_7 ) ;
V_7 = F_5 ( V_11 -> V_2 , V_33 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = ( V_7 & V_34 ) >> 5 ;
V_32 = ( 32 * 1000 ) >> V_7 ;
return ( V_31 / V_32 ) ;
}
static int F_20 ( struct V_21 * V_22 , unsigned int V_35 )
{
struct V_10 * V_11 = F_13 ( V_22 ) ;
switch ( V_35 ) {
case V_36 :
F_9 ( V_11 -> V_2 , V_11 -> V_25 , V_37 ,
V_37 ) ;
break;
case V_38 :
F_9 ( V_11 -> V_2 , V_11 -> V_25 ,
V_37 , 0 ) ;
break;
default:
return - V_20 ;
}
return 0 ;
}
static unsigned int F_21 ( struct V_21 * V_22 )
{
struct V_10 * V_11 = F_13 ( V_22 ) ;
int V_7 ;
V_7 = F_5 ( V_11 -> V_2 , V_11 -> V_25 ) ;
if ( V_7 & V_37 )
return V_36 ;
return V_38 ;
}
static int T_1 F_22 ( struct V_1 * V_39 ,
const struct V_40 * V_41 )
{
struct V_42 * V_43 = V_39 -> V_28 . V_44 ;
struct V_10 * V_11 = NULL ;
unsigned char V_6 ;
int V_7 ;
V_11 = F_23 ( sizeof( struct V_10 ) , V_45 ) ;
if ( ! V_11 ) {
F_15 ( & V_39 -> V_28 , L_2 ) ;
return - V_46 ;
}
V_11 -> V_2 = V_39 ;
V_11 -> V_28 = & V_39 -> V_28 ;
F_24 ( & V_11 -> V_12 ) ;
F_25 ( V_39 , V_11 ) ;
V_11 -> V_35 = V_43 -> V_35 ;
switch ( V_11 -> V_35 ) {
case 0 :
V_11 -> V_25 = V_47 ;
break;
case 1 :
V_11 -> V_25 = V_48 ;
break;
case 2 :
V_11 -> V_25 = V_49 ;
break;
case 3 :
V_11 -> V_25 = V_50 ;
break;
default:
break;
}
V_7 = F_5 ( V_11 -> V_2 , V_51 ) ;
if ( V_7 < 0 ) {
F_15 ( V_11 -> V_28 , L_3 ,
V_7 ) ;
goto V_15;
}
F_26 ( V_11 -> V_28 , L_4 , V_7 ) ;
F_9 ( V_11 -> V_2 , V_29 , V_52 , 0 ) ;
V_11 -> V_53 = V_43 -> V_53 ;
V_6 = ( V_11 -> V_53 ) ? V_54 : 0 ;
F_9 ( V_11 -> V_2 , V_11 -> V_25 , V_54 , V_6 ) ;
if ( V_11 -> V_53 ) {
V_11 -> V_55 = V_43 -> V_55 ;
F_9 ( V_11 -> V_2 , V_56 , V_57 ,
V_11 -> V_55 << 6 ) ;
}
if ( V_43 -> V_58 ) {
V_11 -> V_58 = V_43 -> V_58 ;
F_9 ( V_11 -> V_2 , V_33 , V_34 ,
V_11 -> V_58 << 5 ) ;
}
V_11 -> V_59 = V_43 -> V_59 ;
if ( V_11 -> V_59 ) {
F_9 ( V_11 -> V_2 , V_33 , V_60 ,
V_60 ) ;
}
V_11 -> V_61 = F_27 ( & V_62 , & V_39 -> V_28 ,
V_43 -> V_61 , V_11 ) ;
if ( F_28 ( V_11 -> V_61 ) ) {
F_15 ( V_11 -> V_28 , L_5 ,
V_62 . V_63 ) ;
V_7 = F_29 ( V_11 -> V_61 ) ;
goto V_15;
}
F_26 ( V_11 -> V_28 , L_6 ) ;
return 0 ;
V_15:
F_30 ( V_11 ) ;
return V_7 ;
}
static int T_2 F_31 ( struct V_1 * V_39 )
{
struct V_10 * V_11 = F_6 ( V_39 ) ;
if ( V_11 ) {
if ( V_11 -> V_61 )
F_32 ( V_11 -> V_61 ) ;
F_30 ( V_11 ) ;
}
return 0 ;
}
static int T_3 F_33 ( void )
{
return F_34 ( & V_64 ) ;
}
static void T_4 F_35 ( void )
{
F_36 ( & V_64 ) ;
}
