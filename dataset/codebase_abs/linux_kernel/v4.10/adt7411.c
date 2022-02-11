static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 , V_9 ;
F_3 ( & V_7 -> V_10 ) ;
V_8 = F_4 ( V_2 , V_3 ) ;
if ( V_8 < 0 )
goto V_11;
V_9 = ( V_8 >> V_5 ) & 3 ;
V_8 = F_4 ( V_2 , V_4 ) ;
if ( V_8 >= 0 )
V_8 = ( V_8 << 2 ) | V_9 ;
V_11:
F_5 ( & V_7 -> V_10 ) ;
return V_8 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_12 , T_1 V_13 ,
bool V_14 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_15 , V_8 ;
F_3 ( & V_7 -> V_10 ) ;
V_15 = F_4 ( V_2 , V_12 ) ;
if ( V_15 < 0 )
goto V_11;
if ( V_14 )
V_8 = V_15 | V_13 ;
else
V_8 = V_15 & ~ V_13 ;
V_15 = F_7 ( V_2 , V_12 , V_8 ) ;
V_11:
F_5 ( & V_7 -> V_10 ) ;
return V_15 ;
}
static T_2 F_8 ( struct V_16 * V_17 ,
struct V_18 * V_19 , char * V_20 )
{
struct V_21 * V_22 = F_9 ( V_19 ) ;
struct V_6 * V_7 = F_10 ( V_17 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_15 = F_4 ( V_2 , V_22 -> V_23 ) ;
return V_15 < 0 ? V_15 : sprintf ( V_20 , L_1 , ! ! ( V_15 & V_22 -> V_24 ) ) ;
}
static T_2 F_11 ( struct V_16 * V_17 ,
struct V_18 * V_19 , const char * V_20 ,
T_3 V_25 )
{
struct V_21 * V_26 = F_9 ( V_19 ) ;
struct V_6 * V_7 = F_10 ( V_17 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_15 ;
unsigned long V_14 ;
V_15 = F_12 ( V_20 , 0 , & V_14 ) ;
if ( V_15 || V_14 > 1 )
return - V_27 ;
V_15 = F_6 ( V_2 , V_26 -> V_23 , V_26 -> V_24 , V_14 ) ;
F_3 ( & V_7 -> V_28 ) ;
V_7 -> V_29 = V_30 ;
F_5 ( & V_7 -> V_28 ) ;
return V_15 < 0 ? V_15 : V_25 ;
}
static int F_13 ( struct V_16 * V_17 , T_4 V_19 , long * V_8 )
{
struct V_6 * V_7 = F_10 ( V_17 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_15 ;
switch ( V_19 ) {
case V_31 :
V_15 = F_1 ( V_2 , V_32 ,
V_33 , 2 ) ;
if ( V_15 < 0 )
return V_15 ;
* V_8 = V_15 * 7000 / 1024 ;
return 0 ;
default:
return - V_34 ;
}
}
static int F_14 ( struct V_16 * V_17 , T_4 V_19 , int V_35 ,
long * V_8 )
{
struct V_6 * V_7 = F_10 ( V_17 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_15 ;
int V_3 , V_5 ;
int V_24 = V_35 - 1 ;
F_3 ( & V_7 -> V_28 ) ;
if ( F_15 ( V_30 , V_7 -> V_29 ) ) {
V_15 = F_4 ( V_2 , V_36 ) ;
if ( V_15 < 0 )
goto V_11;
if ( V_15 & V_37 ) {
V_15 = F_13 ( V_17 , V_31 ,
& V_7 -> V_38 ) ;
if ( V_15 < 0 )
goto V_11;
} else {
V_7 -> V_38 = 2250 ;
}
V_7 -> V_29 = V_30 + V_39 ;
}
switch ( V_19 ) {
case V_31 :
V_3 = V_40 + ( V_24 >> 2 ) ;
V_5 = 2 * ( V_24 & 0x03 ) ;
V_15 = F_1 ( V_2 , V_3 ,
V_41 + V_24 ,
V_5 ) ;
if ( V_15 < 0 )
goto V_11;
* V_8 = V_15 * V_7 -> V_38 / 1024 ;
V_15 = 0 ;
break;
default:
V_15 = - V_34 ;
break;
}
V_11:
F_5 ( & V_7 -> V_28 ) ;
return V_15 ;
}
static int F_16 ( struct V_16 * V_17 , T_4 V_19 , int V_35 ,
long * V_8 )
{
if ( V_35 == 0 )
return F_13 ( V_17 , V_19 , V_8 ) ;
else
return F_14 ( V_17 , V_19 , V_35 , V_8 ) ;
}
static int F_17 ( struct V_16 * V_17 , T_4 V_19 , int V_35 ,
long * V_8 )
{
struct V_6 * V_7 = F_10 ( V_17 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_15 , V_42 , V_43 ;
switch ( V_19 ) {
case V_44 :
V_42 = V_35 ? V_40 :
V_32 ;
V_43 = V_35 ? V_41 :
V_45 ;
V_15 = F_1 ( V_2 , V_42 , V_43 , 0 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = V_15 & 0x200 ? V_15 - 0x400 : V_15 ;
* V_8 = V_15 * 250 ;
return 0 ;
default:
return - V_34 ;
}
}
static int F_18 ( struct V_16 * V_17 , enum V_46 type ,
T_4 V_19 , int V_35 , long * V_8 )
{
switch ( type ) {
case V_47 :
return F_16 ( V_17 , V_19 , V_35 , V_8 ) ;
case V_48 :
return F_17 ( V_17 , V_19 , V_35 , V_8 ) ;
default:
return - V_34 ;
}
}
static T_5 F_19 ( const void * V_49 ,
enum V_46 type ,
T_4 V_19 , int V_35 )
{
const struct V_6 * V_7 = V_49 ;
switch ( type ) {
case V_47 :
if ( V_35 > 0 && V_35 < 3 )
return V_7 -> V_50 ? 0 : V_51 ;
else
return V_51 ;
case V_48 :
if ( V_35 == 1 )
return V_7 -> V_50 ? V_51 : 0 ;
else
return V_51 ;
default:
return 0 ;
}
}
static int F_20 ( struct V_1 * V_2 ,
struct V_52 * V_53 )
{
int V_8 ;
if ( ! F_21 ( V_2 -> V_54 , V_55 ) )
return - V_56 ;
V_8 = F_4 ( V_2 , V_57 ) ;
if ( V_8 < 0 || V_8 != V_58 ) {
F_22 ( & V_2 -> V_17 ,
L_2 ,
V_8 , V_58 ) ;
return - V_56 ;
}
V_8 = F_4 ( V_2 , V_59 ) ;
if ( V_8 < 0 || V_8 != V_60 ) {
F_22 ( & V_2 -> V_17 ,
L_3 ,
V_8 , V_60 ) ;
return - V_56 ;
}
F_23 ( V_53 -> type , L_4 , V_61 ) ;
return 0 ;
}
static int F_24 ( struct V_6 * V_7 )
{
int V_15 ;
T_1 V_8 ;
V_15 = F_4 ( V_7 -> V_2 , V_36 ) ;
if ( V_15 < 0 )
return V_15 ;
V_8 = V_15 ;
V_8 &= ~ ( V_62 | V_63 ) ;
V_8 |= V_64 ;
V_15 = F_7 ( V_7 -> V_2 , V_36 , V_8 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_4 ( V_7 -> V_2 , V_65 ) ;
if ( V_15 < 0 )
return V_15 ;
V_7 -> V_50 = V_15 & V_66 ;
V_8 = V_15 ;
V_8 &= ~ V_67 ;
V_8 |= V_68 ;
V_8 |= V_69 ;
return F_7 ( V_7 -> V_2 , V_65 , V_8 ) ;
}
static int F_25 ( struct V_1 * V_2 ,
const struct V_70 * V_71 )
{
struct V_16 * V_17 = & V_2 -> V_17 ;
struct V_6 * V_7 ;
struct V_16 * V_72 ;
int V_15 ;
V_7 = F_26 ( V_17 , sizeof( * V_7 ) , V_73 ) ;
if ( ! V_7 )
return - V_74 ;
F_27 ( V_2 , V_7 ) ;
V_7 -> V_2 = V_2 ;
F_28 ( & V_7 -> V_10 ) ;
F_28 ( & V_7 -> V_28 ) ;
V_15 = F_24 ( V_7 ) ;
if ( V_15 < 0 )
return V_15 ;
V_7 -> V_29 = V_30 ;
V_72 = F_29 ( V_17 , V_2 -> V_75 ,
V_7 ,
& V_76 ,
V_77 ) ;
return F_30 ( V_72 ) ;
}
