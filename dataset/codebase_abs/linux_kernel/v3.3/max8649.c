static inline int F_1 ( int V_1 , int V_2 )
{
if ( ( V_1 < V_3 ) || ( V_2 > V_4 )
|| ( V_1 > V_2 ) )
return - V_5 ;
return 0 ;
}
static int F_2 ( struct V_6 * V_7 , unsigned V_8 )
{
return ( V_3 + V_8 * V_9 ) ;
}
static int F_3 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_4 ( V_7 ) ;
unsigned int V_12 ;
unsigned char V_13 ;
int V_14 ;
V_14 = F_5 ( V_11 -> V_15 , V_11 -> V_16 , & V_12 ) ;
if ( V_14 != 0 )
return V_14 ;
V_13 = ( unsigned char ) V_12 & V_17 ;
return F_2 ( V_7 , V_13 ) ;
}
static int F_6 ( struct V_6 * V_7 ,
int V_1 , int V_2 , unsigned * V_18 )
{
struct V_10 * V_11 = F_4 ( V_7 ) ;
unsigned char V_13 , V_19 ;
if ( F_1 ( V_1 , V_2 ) ) {
F_7 ( V_11 -> V_20 , L_1 ,
V_1 , V_2 ) ;
return - V_5 ;
}
V_13 = ( V_1 - V_3 + V_9 - 1 )
/ V_9 ;
V_19 = V_17 ;
* V_18 = V_13 & V_19 ;
return F_8 ( V_11 -> V_15 , V_11 -> V_16 , V_19 , V_13 ) ;
}
static int F_9 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_4 ( V_7 ) ;
return F_8 ( V_11 -> V_15 , V_21 , V_22 , 0 ) ;
}
static int F_10 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_4 ( V_7 ) ;
return F_8 ( V_11 -> V_15 , V_21 , V_22 ,
V_22 ) ;
}
static int F_11 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_4 ( V_7 ) ;
unsigned int V_12 ;
int V_14 ;
V_14 = F_5 ( V_11 -> V_15 , V_21 , & V_12 ) ;
if ( V_14 != 0 )
return V_14 ;
return ! ( ( unsigned char ) V_12 & V_22 ) ;
}
static int F_12 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_4 ( V_7 ) ;
int V_23 , V_24 , V_14 ;
unsigned int V_12 ;
V_14 = F_5 ( V_11 -> V_15 , V_11 -> V_16 , & V_12 ) ;
if ( V_14 != 0 )
return V_14 ;
V_12 &= V_17 ;
V_23 = F_2 ( V_7 , ( unsigned char ) V_12 ) ;
V_14 = F_5 ( V_11 -> V_15 , V_25 , & V_12 ) ;
if ( V_14 != 0 )
return V_14 ;
V_14 = ( V_12 & V_26 ) >> 5 ;
V_24 = ( 32 * 1000 ) >> V_14 ;
return F_13 ( V_23 , V_24 ) ;
}
static int F_14 ( struct V_6 * V_7 , unsigned int V_27 )
{
struct V_10 * V_11 = F_4 ( V_7 ) ;
switch ( V_27 ) {
case V_28 :
F_8 ( V_11 -> V_15 , V_11 -> V_16 , V_29 ,
V_29 ) ;
break;
case V_30 :
F_8 ( V_11 -> V_15 , V_11 -> V_16 ,
V_29 , 0 ) ;
break;
default:
return - V_5 ;
}
return 0 ;
}
static unsigned int F_15 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_4 ( V_7 ) ;
unsigned int V_12 ;
int V_14 ;
V_14 = F_5 ( V_11 -> V_15 , V_11 -> V_16 , & V_12 ) ;
if ( V_14 != 0 )
return V_14 ;
if ( V_12 & V_29 )
return V_28 ;
return V_30 ;
}
static int T_1 F_16 ( struct V_31 * V_32 ,
const struct V_33 * V_34 )
{
struct V_35 * V_36 = V_32 -> V_20 . V_37 ;
struct V_10 * V_11 = NULL ;
unsigned int V_12 ;
unsigned char V_13 ;
int V_14 ;
V_11 = F_17 ( sizeof( struct V_10 ) , V_38 ) ;
if ( ! V_11 ) {
F_7 ( & V_32 -> V_20 , L_2 ) ;
return - V_39 ;
}
V_11 -> V_15 = F_18 ( V_32 , & V_40 ) ;
if ( F_19 ( V_11 -> V_15 ) ) {
V_14 = F_20 ( V_11 -> V_15 ) ;
F_7 ( & V_32 -> V_20 , L_3 , V_14 ) ;
goto V_41;
}
V_11 -> V_20 = & V_32 -> V_20 ;
F_21 ( V_32 , V_11 ) ;
V_11 -> V_27 = V_36 -> V_27 ;
switch ( V_11 -> V_27 ) {
case 0 :
V_11 -> V_16 = V_42 ;
break;
case 1 :
V_11 -> V_16 = V_43 ;
break;
case 2 :
V_11 -> V_16 = V_44 ;
break;
case 3 :
V_11 -> V_16 = V_45 ;
break;
default:
break;
}
V_14 = F_5 ( V_11 -> V_15 , V_46 , & V_12 ) ;
if ( V_14 != 0 ) {
F_7 ( V_11 -> V_20 , L_4 ,
V_14 ) ;
goto V_47;
}
F_22 ( V_11 -> V_20 , L_5 , V_14 ) ;
F_8 ( V_11 -> V_15 , V_21 , V_48 , 0 ) ;
V_11 -> V_49 = V_36 -> V_49 ;
V_13 = ( V_11 -> V_49 ) ? V_50 : 0 ;
F_8 ( V_11 -> V_15 , V_11 -> V_16 , V_50 , V_13 ) ;
if ( V_11 -> V_49 ) {
V_11 -> V_51 = V_36 -> V_51 ;
F_8 ( V_11 -> V_15 , V_52 , V_53 ,
V_11 -> V_51 << 6 ) ;
}
if ( V_36 -> V_54 ) {
V_11 -> V_54 = V_36 -> V_54 ;
F_8 ( V_11 -> V_15 , V_25 , V_26 ,
V_11 -> V_54 << 5 ) ;
}
V_11 -> V_55 = V_36 -> V_55 ;
if ( V_11 -> V_55 ) {
F_8 ( V_11 -> V_15 , V_25 , V_56 ,
V_56 ) ;
}
V_11 -> V_57 = F_23 ( & V_58 , & V_32 -> V_20 ,
V_36 -> V_57 , V_11 , NULL ) ;
if ( F_19 ( V_11 -> V_57 ) ) {
F_7 ( V_11 -> V_20 , L_6 ,
V_58 . V_59 ) ;
V_14 = F_20 ( V_11 -> V_57 ) ;
goto V_47;
}
F_22 ( V_11 -> V_20 , L_7 ) ;
return 0 ;
V_47:
F_24 ( V_11 -> V_15 ) ;
V_41:
F_25 ( V_11 ) ;
return V_14 ;
}
static int T_2 F_26 ( struct V_31 * V_32 )
{
struct V_10 * V_11 = F_27 ( V_32 ) ;
if ( V_11 ) {
if ( V_11 -> V_57 )
F_28 ( V_11 -> V_57 ) ;
F_24 ( V_11 -> V_15 ) ;
F_25 ( V_11 ) ;
}
return 0 ;
}
static int T_3 F_29 ( void )
{
return F_30 ( & V_60 ) ;
}
static void T_4 F_31 ( void )
{
F_32 ( & V_60 ) ;
}
