static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 * V_7 = V_2 -> V_8 ;
if ( V_3 > V_9 ) {
F_1 ( V_2 , V_10 , 0 ) ;
V_11 -> V_12 ( V_6 , V_3 , V_4 ) ;
F_1 ( V_2 , V_10 , 1 ) ;
return 0 ;
}
if ( V_3 / 2 >= F_3 ( V_13 ) )
return - V_14 ;
V_11 -> V_12 ( V_6 , V_3 , V_4 ) ;
V_7 [ V_3 / 2 ] = V_4 ;
return 0 ;
}
static unsigned int F_4 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_4 = 0 , * V_7 = V_2 -> V_8 ;
if ( V_3 > V_9 ) {
F_1 ( V_2 , V_10 , 0 ) ;
V_4 = V_11 -> V_15 ( V_6 , V_3 - V_9 ) ;
F_1 ( V_2 , V_10 , 1 ) ;
return V_4 ;
}
if ( V_3 / 2 >= F_3 ( V_13 ) )
return - V_14 ;
if ( V_3 == V_16 || V_3 == V_17 ||
V_3 == V_10 || V_3 == V_18 ||
V_3 == V_19 ) {
V_4 = V_11 -> V_15 ( V_6 , V_3 ) ;
return V_4 ;
}
return V_7 [ V_3 / 2 ] ;
}
static int F_5 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_24 * V_25 = V_21 -> V_25 ;
unsigned short V_3 , V_26 ;
V_26 = F_4 ( V_2 , V_27 ) ;
V_26 |= 0x1 ;
V_26 &= ~ 0x4 ;
F_1 ( V_2 , V_27 , V_26 ) ;
if ( V_21 -> V_28 == V_29 )
V_3 = V_30 ;
else
V_3 = V_31 ;
return F_1 ( V_2 , V_3 , V_25 -> V_32 ) ;
}
static int F_6 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_24 * V_25 = V_21 -> V_25 ;
unsigned short V_3 , V_26 ;
F_1 ( V_2 , V_33 , 0x2002 ) ;
V_26 = F_4 ( V_2 , V_27 ) ;
V_26 |= 0x5 ;
F_1 ( V_2 , V_27 , V_26 ) ;
V_3 = V_30 ;
return F_1 ( V_2 , V_3 , V_25 -> V_32 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
enum V_34 V_35 )
{
switch ( V_35 ) {
case V_36 :
case V_37 :
case V_38 :
F_1 ( V_2 , V_39 , 0x0000 ) ;
break;
case V_40 :
F_1 ( V_2 , V_39 , 0xffff ) ;
break;
}
V_2 -> V_41 . V_42 = V_35 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , int V_43 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_43 && V_11 -> V_44 ) {
V_11 -> V_44 ( V_6 ) ;
if ( F_4 ( V_2 , 0 ) == V_13 [ 0 ] )
return 1 ;
}
V_11 -> V_45 ( V_6 ) ;
if ( V_11 -> V_44 )
V_11 -> V_44 ( V_6 ) ;
if ( F_4 ( V_2 , 0 ) != V_13 [ 0 ] )
return - V_14 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_46 , V_45 ;
V_45 = 0 ;
V_45:
if ( V_45 > 5 ) {
F_10 ( V_2 -> V_47 , L_1 ) ;
return - V_14 ;
}
V_6 -> V_48 -> V_49 -> V_44 ( V_6 ) ;
V_46 = V_11 -> V_15 ( V_6 , V_19 ) ;
if ( V_46 != 0x4c13 ) {
F_8 ( V_2 , 0 ) ;
V_45 ++ ;
goto V_45;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
int V_50 = 0 ;
V_6 = F_12 ( V_2 ) ;
if ( F_13 ( V_6 ) )
return F_14 ( V_6 ) ;
F_15 ( V_2 , V_6 ) ;
F_8 ( V_2 , 0 ) ;
V_50 = F_8 ( V_2 , 1 ) ;
if ( V_50 < 0 ) {
F_10 ( V_2 -> V_47 , L_2 ) ;
goto V_51;
}
return 0 ;
V_51:
F_16 ( V_6 ) ;
return V_50 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_16 ( V_6 ) ;
return 0 ;
}
static int F_18 ( struct V_52 * V_53 )
{
return F_19 ( & V_53 -> V_47 ,
& V_54 , V_55 , F_3 ( V_55 ) ) ;
}
static int F_20 ( struct V_52 * V_53 )
{
F_21 ( & V_53 -> V_47 ) ;
return 0 ;
}
