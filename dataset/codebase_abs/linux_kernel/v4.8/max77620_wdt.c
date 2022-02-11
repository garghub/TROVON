static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_3 ( V_4 -> V_5 , V_6 ,
V_7 , V_7 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_3 ( V_4 -> V_5 , V_6 ,
V_7 , 0 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_3 ( V_4 -> V_5 , V_8 ,
V_9 , 0x1 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned int V_10 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_11 ;
T_1 V_12 ;
int V_13 ;
switch ( V_10 ) {
case 0 ... 2 :
V_12 = V_14 ;
V_11 = 2 ;
break;
case 3 ... 16 :
V_12 = V_15 ;
V_11 = 16 ;
break;
case 17 ... 64 :
V_12 = V_16 ;
V_11 = 64 ;
break;
default:
V_12 = V_17 ;
V_11 = 128 ;
break;
}
V_13 = F_3 ( V_4 -> V_5 , V_8 ,
V_9 , 0x1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_3 ( V_4 -> V_5 , V_6 ,
V_18 , V_12 ) ;
if ( V_13 < 0 )
return V_13 ;
V_2 -> V_10 = V_11 ;
return 0 ;
}
static int F_7 ( struct V_19 * V_20 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
unsigned int V_12 ;
int V_13 ;
V_4 = F_8 ( & V_20 -> V_21 , sizeof( * V_4 ) , V_22 ) ;
if ( ! V_4 )
return - V_23 ;
V_4 -> V_21 = & V_20 -> V_21 ;
V_4 -> V_5 = F_9 ( V_20 -> V_21 . V_24 , NULL ) ;
if ( ! V_4 -> V_5 ) {
F_10 ( V_4 -> V_21 , L_1 ) ;
return - V_25 ;
}
V_2 = & V_4 -> V_2 ;
V_2 -> V_26 = & V_27 ;
V_2 -> V_28 = & V_29 ;
V_2 -> V_30 = 2 ;
V_2 -> V_31 = 128 ;
V_2 -> V_32 = 128 * 1000 ;
F_11 ( V_20 , V_4 ) ;
V_13 = F_3 ( V_4 -> V_5 , V_33 ,
V_34 ,
V_34 ) ;
if ( V_13 < 0 ) {
F_10 ( V_4 -> V_21 , L_2 , V_13 ) ;
return V_13 ;
}
V_13 = F_3 ( V_4 -> V_5 , V_6 ,
V_35 | V_36 ,
V_35 | V_36 ) ;
if ( V_13 < 0 ) {
F_10 ( V_4 -> V_21 , L_3 , V_13 ) ;
return V_13 ;
}
V_13 = F_12 ( V_4 -> V_5 , V_6 , & V_12 ) ;
if ( V_13 < 0 ) {
F_10 ( V_4 -> V_21 , L_4 , V_13 ) ;
return V_13 ;
}
switch ( V_12 & V_18 ) {
case V_14 :
V_2 -> V_10 = 2 ;
break;
case V_15 :
V_2 -> V_10 = 16 ;
break;
case V_16 :
V_2 -> V_10 = 64 ;
break;
default:
V_2 -> V_10 = 128 ;
break;
}
if ( V_12 & V_7 )
F_13 ( V_37 , & V_2 -> V_38 ) ;
F_14 ( V_2 , V_39 ) ;
F_15 ( V_2 , V_4 ) ;
V_13 = F_16 ( V_2 ) ;
if ( V_13 < 0 ) {
F_10 ( & V_20 -> V_21 , L_5 , V_13 ) ;
return V_13 ;
}
return 0 ;
}
static int F_17 ( struct V_19 * V_20 )
{
struct V_3 * V_4 = F_18 ( V_20 ) ;
F_4 ( & V_4 -> V_2 ) ;
F_19 ( & V_4 -> V_2 ) ;
return 0 ;
}
