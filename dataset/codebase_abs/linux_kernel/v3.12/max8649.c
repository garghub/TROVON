static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 , V_6 , V_7 ;
unsigned int V_8 ;
V_7 = F_3 ( V_4 -> V_9 , V_2 -> V_10 -> V_11 , & V_8 ) ;
if ( V_7 != 0 )
return V_7 ;
V_8 &= V_12 ;
V_5 = F_4 ( V_2 , ( unsigned char ) V_8 ) ;
V_7 = F_3 ( V_4 -> V_9 , V_13 , & V_8 ) ;
if ( V_7 != 0 )
return V_7 ;
V_7 = ( V_8 & V_14 ) >> 5 ;
V_6 = ( 32 * 1000 ) >> V_7 ;
return F_5 ( V_5 , V_6 ) ;
}
static int F_6 ( struct V_1 * V_2 , unsigned int V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_15 ) {
case V_16 :
F_7 ( V_4 -> V_9 , V_2 -> V_10 -> V_11 ,
V_17 , V_17 ) ;
break;
case V_18 :
F_7 ( V_4 -> V_9 , V_2 -> V_10 -> V_11 ,
V_17 , 0 ) ;
break;
default:
return - V_19 ;
}
return 0 ;
}
static unsigned int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_8 ;
int V_7 ;
V_7 = F_3 ( V_4 -> V_9 , V_2 -> V_10 -> V_11 , & V_8 ) ;
if ( V_7 != 0 )
return V_7 ;
if ( V_8 & V_17 )
return V_16 ;
return V_18 ;
}
static int F_9 ( struct V_20 * V_21 ,
const struct V_22 * V_23 )
{
struct V_24 * V_25 = F_10 ( & V_21 -> V_26 ) ;
struct V_3 * V_4 = NULL ;
struct V_27 V_28 = { } ;
unsigned int V_8 ;
unsigned char V_29 ;
int V_7 ;
V_4 = F_11 ( & V_21 -> V_26 , sizeof( struct V_3 ) ,
V_30 ) ;
if ( ! V_4 ) {
F_12 ( & V_21 -> V_26 , L_1 ) ;
return - V_31 ;
}
V_4 -> V_9 = F_13 ( V_21 , & V_32 ) ;
if ( F_14 ( V_4 -> V_9 ) ) {
V_7 = F_15 ( V_4 -> V_9 ) ;
F_12 ( & V_21 -> V_26 , L_2 , V_7 ) ;
return V_7 ;
}
V_4 -> V_26 = & V_21 -> V_26 ;
F_16 ( V_21 , V_4 ) ;
V_4 -> V_15 = V_25 -> V_15 ;
switch ( V_4 -> V_15 ) {
case 0 :
V_33 . V_11 = V_34 ;
break;
case 1 :
V_33 . V_11 = V_35 ;
break;
case 2 :
V_33 . V_11 = V_36 ;
break;
case 3 :
V_33 . V_11 = V_37 ;
break;
default:
break;
}
V_7 = F_3 ( V_4 -> V_9 , V_38 , & V_8 ) ;
if ( V_7 != 0 ) {
F_12 ( V_4 -> V_26 , L_3 ,
V_7 ) ;
return V_7 ;
}
F_17 ( V_4 -> V_26 , L_4 , V_8 ) ;
F_7 ( V_4 -> V_9 , V_39 , V_40 , 0 ) ;
V_4 -> V_41 = V_25 -> V_41 ;
V_29 = ( V_4 -> V_41 ) ? V_42 : 0 ;
F_7 ( V_4 -> V_9 , V_33 . V_11 ,
V_42 , V_29 ) ;
if ( V_4 -> V_41 ) {
V_4 -> V_43 = V_25 -> V_43 ;
F_7 ( V_4 -> V_9 , V_44 , V_45 ,
V_4 -> V_43 << 6 ) ;
}
if ( V_25 -> V_46 ) {
V_4 -> V_46 = V_25 -> V_46 ;
F_7 ( V_4 -> V_9 , V_13 , V_14 ,
V_4 -> V_46 << 5 ) ;
}
V_4 -> V_47 = V_25 -> V_47 ;
if ( V_4 -> V_47 ) {
F_7 ( V_4 -> V_9 , V_13 , V_48 ,
V_48 ) ;
}
V_28 . V_26 = & V_21 -> V_26 ;
V_28 . V_49 = V_25 -> V_50 ;
V_28 . V_51 = V_4 ;
V_28 . V_9 = V_4 -> V_9 ;
V_4 -> V_50 = F_18 ( & V_33 , & V_28 ) ;
if ( F_14 ( V_4 -> V_50 ) ) {
F_12 ( V_4 -> V_26 , L_5 ,
V_33 . V_52 ) ;
return F_15 ( V_4 -> V_50 ) ;
}
return 0 ;
}
static int F_19 ( struct V_20 * V_21 )
{
struct V_3 * V_4 = F_20 ( V_21 ) ;
if ( V_4 )
F_21 ( V_4 -> V_50 ) ;
return 0 ;
}
static int T_1 F_22 ( void )
{
return F_23 ( & V_53 ) ;
}
static void T_2 F_24 ( void )
{
F_25 ( & V_53 ) ;
}
