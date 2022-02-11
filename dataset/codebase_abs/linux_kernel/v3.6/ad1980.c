static unsigned int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
T_1 * V_4 = V_2 -> V_5 ;
switch ( V_3 ) {
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
return V_12 . V_13 ( V_2 -> V_14 , V_3 ) ;
default:
V_3 = V_3 >> 1 ;
if ( V_3 >= F_2 ( V_15 ) )
return - V_16 ;
return V_4 [ V_3 ] ;
}
}
static int F_3 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_17 )
{
T_1 * V_4 = V_2 -> V_5 ;
V_12 . V_18 ( V_2 -> V_14 , V_3 , V_17 ) ;
V_3 = V_3 >> 1 ;
if ( V_3 < F_2 ( V_15 ) )
V_4 [ V_3 ] = V_17 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , int V_19 )
{
T_1 V_20 = 0 ;
V_21:
if ( V_19 && V_12 . V_22 ) {
V_12 . V_22 ( V_2 -> V_14 ) ;
if ( F_1 ( V_2 , V_6 ) == 0x0090 )
return 1 ;
}
V_12 . V_23 ( V_2 -> V_14 ) ;
F_3 ( V_2 , V_24 , 0x9900 ) ;
if ( F_1 ( V_2 , V_6 ) != 0x0090 )
goto V_25;
return 0 ;
V_25:
while ( V_20 ++ < 10 )
goto V_21;
F_5 ( V_26 L_1 ) ;
return - V_27 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_28 ;
T_1 V_29 ;
T_1 V_30 ;
F_5 ( V_31 L_2 ) ;
V_2 -> V_32 = V_2 ;
V_28 = F_7 ( V_2 , & V_12 , 0 ) ;
if ( V_28 < 0 ) {
F_5 ( V_26 L_3 ) ;
return V_28 ;
}
V_28 = F_4 ( V_2 , 0 ) ;
if ( V_28 < 0 ) {
F_5 ( V_26 L_4 ) ;
goto V_33;
}
if ( F_1 ( V_2 , V_10 ) != 0x4144 ) {
V_28 = - V_34 ;
goto V_33;
}
V_29 = F_1 ( V_2 , V_11 ) ;
if ( V_29 != 0x5370 ) {
if ( V_29 != 0x5374 ) {
V_28 = - V_34 ;
goto V_33;
} else {
F_5 ( V_35 L_5
L_6
L_7 ) ;
}
}
F_3 ( V_2 , V_36 , 0x0000 ) ;
F_3 ( V_2 , V_37 , 0x0000 ) ;
F_3 ( V_2 , V_38 , 0x0000 ) ;
F_3 ( V_2 , V_39 , 0x0000 ) ;
F_3 ( V_2 , V_40 , 0x0000 ) ;
V_30 = F_1 ( V_2 , V_9 ) ;
F_3 ( V_2 , V_9 , V_30 & ~ 0x3800 ) ;
F_8 ( V_2 , V_41 ,
F_2 ( V_41 ) ) ;
return 0 ;
V_33:
F_9 ( V_2 ) ;
return V_28 ;
}
static int F_10 ( struct V_1 * V_2 )
{
F_9 ( V_2 ) ;
return 0 ;
}
static T_2 int F_11 ( struct V_42 * V_43 )
{
return F_12 ( & V_43 -> V_44 ,
& V_45 , & V_46 , 1 ) ;
}
static int T_3 F_13 ( struct V_42 * V_43 )
{
F_14 ( & V_43 -> V_44 ) ;
return 0 ;
}
