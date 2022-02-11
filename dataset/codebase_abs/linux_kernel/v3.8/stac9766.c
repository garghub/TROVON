static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
T_1 * V_5 = V_2 -> V_6 ;
if ( V_3 > V_7 ) {
F_1 ( V_2 , V_8 , 0 ) ;
V_9 . V_10 ( V_2 -> V_11 , V_3 , V_4 ) ;
F_1 ( V_2 , V_8 , 1 ) ;
return 0 ;
}
if ( V_3 / 2 >= F_2 ( V_12 ) )
return - V_13 ;
V_9 . V_10 ( V_2 -> V_11 , V_3 , V_4 ) ;
V_5 [ V_3 / 2 ] = V_4 ;
return 0 ;
}
static unsigned int F_3 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
T_1 V_4 = 0 , * V_5 = V_2 -> V_6 ;
if ( V_3 > V_7 ) {
F_1 ( V_2 , V_8 , 0 ) ;
V_4 = V_9 . V_14 ( V_2 -> V_11 , V_3 - V_7 ) ;
F_1 ( V_2 , V_8 , 1 ) ;
return V_4 ;
}
if ( V_3 / 2 >= F_2 ( V_12 ) )
return - V_13 ;
if ( V_3 == V_15 || V_3 == V_16 ||
V_3 == V_8 || V_3 == V_17 ||
V_3 == V_18 ) {
V_4 = V_9 . V_14 ( V_2 -> V_11 , V_3 ) ;
return V_4 ;
}
return V_5 [ V_3 / 2 ] ;
}
static int F_4 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_23 * V_24 = V_20 -> V_24 ;
unsigned short V_3 , V_25 ;
V_25 = F_3 ( V_2 , V_26 ) ;
V_25 |= 0x1 ;
V_25 &= ~ 0x4 ;
F_1 ( V_2 , V_26 , V_25 ) ;
if ( V_20 -> V_27 == V_28 )
V_3 = V_29 ;
else
V_3 = V_30 ;
return F_1 ( V_2 , V_3 , V_24 -> V_31 ) ;
}
static int F_5 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_23 * V_24 = V_20 -> V_24 ;
unsigned short V_3 , V_25 ;
F_1 ( V_2 , V_32 , 0x2002 ) ;
V_25 = F_3 ( V_2 , V_26 ) ;
V_25 |= 0x5 ;
F_1 ( V_2 , V_26 , V_25 ) ;
V_3 = V_29 ;
return F_1 ( V_2 , V_3 , V_24 -> V_31 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
enum V_33 V_34 )
{
switch ( V_34 ) {
case V_35 :
case V_36 :
case V_37 :
F_1 ( V_2 , V_38 , 0x0000 ) ;
break;
case V_39 :
F_1 ( V_2 , V_38 , 0xffff ) ;
break;
}
V_2 -> V_40 . V_41 = V_34 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , int V_42 )
{
if ( V_42 && V_9 . V_43 ) {
V_9 . V_43 ( V_2 -> V_11 ) ;
if ( F_3 ( V_2 , 0 ) == V_12 [ 0 ] )
return 1 ;
}
V_9 . V_44 ( V_2 -> V_11 ) ;
if ( V_9 . V_43 )
V_9 . V_43 ( V_2 -> V_11 ) ;
if ( F_3 ( V_2 , 0 ) != V_12 [ 0 ] )
return - V_13 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_39 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
T_1 V_45 , V_44 ;
V_44 = 0 ;
V_44:
if ( V_44 > 5 ) {
F_10 ( V_46 L_1 ) ;
return - V_13 ;
}
V_2 -> V_11 -> V_47 -> V_48 -> V_43 ( V_2 -> V_11 ) ;
V_45 = V_9 . V_14 ( V_2 -> V_11 , V_18 ) ;
if ( V_45 != 0x4c13 ) {
F_7 ( V_2 , 0 ) ;
V_44 ++ ;
goto V_44;
}
F_6 ( V_2 , V_37 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_49 = 0 ;
F_10 ( V_50 L_2 , V_51 ) ;
V_49 = F_12 ( V_2 , & V_9 , 0 ) ;
if ( V_49 < 0 )
goto V_52;
F_7 ( V_2 , 0 ) ;
V_49 = F_7 ( V_2 , 1 ) ;
if ( V_49 < 0 ) {
F_10 ( V_46 L_3 ) ;
goto V_52;
}
F_6 ( V_2 , V_37 ) ;
F_13 ( V_2 , V_53 ,
F_2 ( V_53 ) ) ;
return 0 ;
V_52:
F_14 ( V_2 ) ;
return V_49 ;
}
static int F_15 ( struct V_1 * V_2 )
{
F_14 ( V_2 ) ;
return 0 ;
}
static int F_16 ( struct V_54 * V_55 )
{
return F_17 ( & V_55 -> V_56 ,
& V_57 , V_58 , F_2 ( V_58 ) ) ;
}
static int F_18 ( struct V_54 * V_55 )
{
F_19 ( & V_55 -> V_56 ) ;
return 0 ;
}
