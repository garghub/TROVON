static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 , V_4 , V_5 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_2 ( V_2 , V_4 , V_6 ) ;
if ( V_3 )
return V_3 ;
return F_2 ( V_2 , V_4 , V_5 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_4 , V_6 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_2 ( V_2 , V_7 , 0xB ) ;
if ( V_3 )
return V_3 ;
V_3 = F_2 ( V_2 , V_4 , V_8 | V_9 ) ;
if ( V_3 )
return V_3 ;
return F_3 ( V_2 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_10 , V_3 ;
V_10 = F_6 ( V_2 , V_11 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 &= ~ V_12 ;
V_3 = F_2 ( V_2 , V_11 , V_10 ) ;
if ( V_3 )
return V_3 ;
return F_4 ( V_2 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
int V_13 = V_14 ;
if ( V_2 -> V_15 == V_16 ) {
int V_17 = F_6 ( V_2 , V_18 ) ;
if ( V_17 < 0 ) {
F_8 ( V_2 , L_1 , V_17 ) ;
return;
}
if ( V_17 & V_19 )
V_13 = V_20 ;
else if ( V_17 & V_21 )
V_13 = V_14 ;
} else {
int V_22 = F_6 ( V_2 , V_23 ) ;
if ( V_22 < 0 ) {
F_8 ( V_2 , L_1 , V_22 ) ;
return;
}
if ( V_22 & V_24 )
V_13 = V_20 ;
else
V_13 = V_14 ;
}
if ( ( V_2 -> V_13 == V_14 ) && ( V_13 == V_20 ) ) {
int V_3 = F_4 ( V_2 ) ;
if ( V_3 )
F_8 ( V_2 , L_2 ,
V_3 ) ;
}
}
static int F_9 ( struct V_1 * V_2 , int V_25 )
{
int V_17 , V_26 , V_10 ;
V_17 = F_6 ( V_2 , V_11 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 &= ~ V_12 ;
V_10 = V_17 ;
switch ( V_25 ) {
case V_27 :
V_10 &= ~ V_28 ;
break;
case V_29 :
V_10 |= V_28 ;
break;
case V_30 :
case V_31 :
default:
return 0 ;
}
if ( V_10 != V_17 ) {
V_26 = F_2 ( V_2 , V_11 , V_10 ) ;
if ( V_26 )
return V_26 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_26 ;
V_26 = F_9 ( V_2 , V_2 -> V_32 ) ;
if ( V_26 < 0 )
return V_26 ;
return F_11 ( V_2 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
F_13 ( V_2 ) ;
return F_5 ( V_2 ) ;
}
