static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_3 ( V_4 -> V_5 , V_6 , V_7 , 0 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_3 ( V_4 -> V_5 , V_6 , V_7 ,
V_7 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_8 ;
int V_9 ;
V_9 = F_6 ( V_4 -> V_5 , V_6 , & V_8 ) ;
if ( V_9 != 0 )
return V_9 ;
return ! ( ( unsigned char ) V_8 & V_7 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_10 , V_11 , V_9 ;
unsigned int V_8 ;
V_9 = F_6 ( V_4 -> V_5 , V_2 -> V_12 -> V_13 , & V_8 ) ;
if ( V_9 != 0 )
return V_9 ;
V_8 &= V_14 ;
V_10 = F_8 ( V_2 , ( unsigned char ) V_8 ) ;
V_9 = F_6 ( V_4 -> V_5 , V_15 , & V_8 ) ;
if ( V_9 != 0 )
return V_9 ;
V_9 = ( V_8 & V_16 ) >> 5 ;
V_11 = ( 32 * 1000 ) >> V_9 ;
return F_9 ( V_10 , V_11 ) ;
}
static int F_10 ( struct V_1 * V_2 , unsigned int V_17 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_17 ) {
case V_18 :
F_3 ( V_4 -> V_5 , V_2 -> V_12 -> V_13 ,
V_19 , V_19 ) ;
break;
case V_20 :
F_3 ( V_4 -> V_5 , V_2 -> V_12 -> V_13 ,
V_19 , 0 ) ;
break;
default:
return - V_21 ;
}
return 0 ;
}
static unsigned int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_8 ;
int V_9 ;
V_9 = F_6 ( V_4 -> V_5 , V_2 -> V_12 -> V_13 , & V_8 ) ;
if ( V_9 != 0 )
return V_9 ;
if ( V_8 & V_19 )
return V_18 ;
return V_20 ;
}
static int T_1 F_12 ( struct V_22 * V_23 ,
const struct V_24 * V_25 )
{
struct V_26 * V_27 = V_23 -> V_28 . V_29 ;
struct V_3 * V_4 = NULL ;
struct V_30 V_31 = { } ;
unsigned int V_8 ;
unsigned char V_32 ;
int V_9 ;
V_4 = F_13 ( & V_23 -> V_28 , sizeof( struct V_3 ) ,
V_33 ) ;
if ( ! V_4 ) {
F_14 ( & V_23 -> V_28 , L_1 ) ;
return - V_34 ;
}
V_4 -> V_5 = F_15 ( V_23 , & V_35 ) ;
if ( F_16 ( V_4 -> V_5 ) ) {
V_9 = F_17 ( V_4 -> V_5 ) ;
F_14 ( & V_23 -> V_28 , L_2 , V_9 ) ;
return V_9 ;
}
V_4 -> V_28 = & V_23 -> V_28 ;
F_18 ( V_23 , V_4 ) ;
V_4 -> V_17 = V_27 -> V_17 ;
switch ( V_4 -> V_17 ) {
case 0 :
V_36 . V_13 = V_37 ;
break;
case 1 :
V_36 . V_13 = V_38 ;
break;
case 2 :
V_36 . V_13 = V_39 ;
break;
case 3 :
V_36 . V_13 = V_40 ;
break;
default:
break;
}
V_9 = F_6 ( V_4 -> V_5 , V_41 , & V_8 ) ;
if ( V_9 != 0 ) {
F_14 ( V_4 -> V_28 , L_3 ,
V_9 ) ;
return V_9 ;
}
F_19 ( V_4 -> V_28 , L_4 , V_8 ) ;
F_3 ( V_4 -> V_5 , V_6 , V_42 , 0 ) ;
V_4 -> V_43 = V_27 -> V_43 ;
V_32 = ( V_4 -> V_43 ) ? V_44 : 0 ;
F_3 ( V_4 -> V_5 , V_36 . V_13 ,
V_44 , V_32 ) ;
if ( V_4 -> V_43 ) {
V_4 -> V_45 = V_27 -> V_45 ;
F_3 ( V_4 -> V_5 , V_46 , V_47 ,
V_4 -> V_45 << 6 ) ;
}
if ( V_27 -> V_48 ) {
V_4 -> V_48 = V_27 -> V_48 ;
F_3 ( V_4 -> V_5 , V_15 , V_16 ,
V_4 -> V_48 << 5 ) ;
}
V_4 -> V_49 = V_27 -> V_49 ;
if ( V_4 -> V_49 ) {
F_3 ( V_4 -> V_5 , V_15 , V_50 ,
V_50 ) ;
}
V_31 . V_28 = & V_23 -> V_28 ;
V_31 . V_51 = V_27 -> V_52 ;
V_31 . V_53 = V_4 ;
V_31 . V_5 = V_4 -> V_5 ;
V_4 -> V_52 = F_20 ( & V_36 , & V_31 ) ;
if ( F_16 ( V_4 -> V_52 ) ) {
F_14 ( V_4 -> V_28 , L_5 ,
V_36 . V_54 ) ;
return F_17 ( V_4 -> V_52 ) ;
}
return 0 ;
}
static int T_2 F_21 ( struct V_22 * V_23 )
{
struct V_3 * V_4 = F_22 ( V_23 ) ;
if ( V_4 ) {
if ( V_4 -> V_52 )
F_23 ( V_4 -> V_52 ) ;
}
return 0 ;
}
static int T_3 F_24 ( void )
{
return F_25 ( & V_55 ) ;
}
static void T_4 F_26 ( void )
{
F_27 ( & V_55 ) ;
}
