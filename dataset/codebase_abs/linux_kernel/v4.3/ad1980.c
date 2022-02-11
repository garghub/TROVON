static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 ... V_5 :
case V_6 ... V_7 :
case V_8 ... V_9 :
case V_10 ... V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
return true ;
default:
return false ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_18 :
case V_19 :
return false ;
default:
return F_1 ( V_2 , V_3 ) ;
}
}
static int F_3 ( struct V_20 * V_21 , int V_22 )
{
struct V_23 * V_24 = F_4 ( V_21 ) ;
unsigned int V_25 = 0 ;
int V_26 ;
do {
V_26 = F_5 ( V_24 , true , V_27 ,
V_28 ) ;
if ( V_26 >= 0 )
return 0 ;
F_6 ( V_21 , V_17 , 0x9900 ) ;
} while ( V_25 ++ < 10 );
F_7 ( V_21 -> V_2 , L_1 ) ;
return - V_29 ;
}
static int F_8 ( struct V_20 * V_21 )
{
struct V_23 * V_24 ;
struct V_30 * V_30 ;
int V_26 ;
T_1 V_31 ;
T_1 V_32 ;
V_24 = F_9 ( V_21 , 0 , 0 ) ;
if ( F_10 ( V_24 ) ) {
V_26 = F_11 ( V_24 ) ;
F_7 ( V_21 -> V_2 , L_2 , V_26 ) ;
return V_26 ;
}
V_30 = F_12 ( V_24 , & V_33 ) ;
if ( F_10 ( V_30 ) ) {
V_26 = F_11 ( V_30 ) ;
goto V_34;
}
F_13 ( V_21 , V_30 ) ;
F_14 ( V_21 , V_24 ) ;
V_26 = F_3 ( V_21 , 0 ) ;
if ( V_26 < 0 )
goto V_35;
V_31 = F_15 ( V_21 , V_19 ) ;
if ( V_31 == 0x5374 ) {
F_16 ( V_21 -> V_2 ,
L_3 ) ;
}
F_6 ( V_21 , V_36 , 0x0000 ) ;
F_6 ( V_21 , V_37 , 0x0000 ) ;
F_6 ( V_21 , V_38 , 0x0000 ) ;
F_6 ( V_21 , V_39 , 0x0000 ) ;
F_6 ( V_21 , V_40 , 0x0000 ) ;
V_32 = F_15 ( V_21 , V_41 ) ;
F_6 ( V_21 , V_41 , V_32 & ~ 0x3800 ) ;
return 0 ;
V_35:
F_17 ( V_21 ) ;
V_34:
F_18 ( V_24 ) ;
return V_26 ;
}
static int F_19 ( struct V_20 * V_21 )
{
struct V_23 * V_24 = F_4 ( V_21 ) ;
F_17 ( V_21 ) ;
F_18 ( V_24 ) ;
return 0 ;
}
static int F_20 ( struct V_42 * V_43 )
{
return F_21 ( & V_43 -> V_2 ,
& V_44 , & V_45 , 1 ) ;
}
static int F_22 ( struct V_42 * V_43 )
{
F_23 ( & V_43 -> V_2 ) ;
return 0 ;
}
