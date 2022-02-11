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
static int F_13 ( struct V_16 * V_17 , int V_31 , long * V_8 )
{
struct V_6 * V_7 = F_10 ( V_17 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_15 ;
V_15 = F_4 ( V_2 , V_32 [ V_31 ] ) ;
if ( V_15 < 0 )
return V_15 ;
* V_8 = ! ! ( V_15 & V_33 [ V_31 ] ) ;
return 0 ;
}
static int F_14 ( struct V_16 * V_17 , T_4 V_19 , long * V_8 )
{
struct V_6 * V_7 = F_10 ( V_17 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_15 ;
switch ( V_19 ) {
case V_34 :
V_15 = F_1 ( V_2 , V_35 ,
V_36 , 2 ) ;
if ( V_15 < 0 )
return V_15 ;
* V_8 = V_15 * 7000 / 1024 ;
return 0 ;
case V_37 :
V_15 = F_4 ( V_2 , V_38 ) ;
if ( V_15 < 0 )
return V_15 ;
* V_8 = V_15 * 7000 / 256 ;
return 0 ;
case V_39 :
V_15 = F_4 ( V_2 , V_40 ) ;
if ( V_15 < 0 )
return V_15 ;
* V_8 = V_15 * 7000 / 256 ;
return 0 ;
case V_41 :
return F_13 ( V_17 , 0 , V_8 ) ;
default:
return - V_42 ;
}
}
static int F_15 ( struct V_16 * V_17 )
{
struct V_6 * V_7 = F_10 ( V_17 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_8 ;
if ( F_16 ( V_30 , V_7 -> V_29 ) ) {
V_8 = F_4 ( V_2 , V_43 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 & V_44 ) {
V_8 = F_14 ( V_17 , V_34 ,
& V_7 -> V_45 ) ;
if ( V_8 < 0 )
return V_8 ;
} else {
V_7 -> V_45 = 2250 ;
}
V_7 -> V_29 = V_30 + V_46 ;
}
return 0 ;
}
static int F_17 ( struct V_16 * V_17 , T_4 V_19 , int V_31 ,
long * V_8 )
{
struct V_6 * V_7 = F_10 ( V_17 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_15 ;
int V_12 , V_3 , V_5 ;
int V_24 = V_31 - 1 ;
F_3 ( & V_7 -> V_28 ) ;
V_15 = F_15 ( V_17 ) ;
if ( V_15 < 0 )
goto V_11;
switch ( V_19 ) {
case V_34 :
V_3 = V_47 + ( V_24 >> 2 ) ;
V_5 = 2 * ( V_24 & 0x03 ) ;
V_15 = F_1 ( V_2 , V_3 ,
V_48 + V_24 ,
V_5 ) ;
if ( V_15 < 0 )
goto V_11;
* V_8 = V_15 * V_7 -> V_45 / 1024 ;
V_15 = 0 ;
break;
case V_37 :
case V_39 :
V_12 = ( V_19 == V_37 )
? F_18 ( V_31 )
: F_19 ( V_31 ) ;
V_15 = F_4 ( V_2 , V_12 ) ;
if ( V_15 < 0 )
goto V_11;
* V_8 = V_15 * V_7 -> V_45 / 256 ;
V_15 = 0 ;
break;
case V_41 :
V_15 = F_13 ( V_17 , V_31 , V_8 ) ;
break;
default:
V_15 = - V_42 ;
break;
}
V_11:
F_5 ( & V_7 -> V_28 ) ;
return V_15 ;
}
static int F_20 ( struct V_16 * V_17 , T_4 V_19 , int V_31 ,
long * V_8 )
{
if ( V_31 == 0 )
return F_14 ( V_17 , V_19 , V_8 ) ;
else
return F_17 ( V_17 , V_19 , V_31 , V_8 ) ;
}
static int F_21 ( struct V_16 * V_17 , T_4 V_19 , int V_31 ,
long * V_8 )
{
struct V_6 * V_7 = F_10 ( V_17 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_15 , V_13 ;
V_15 = F_4 ( V_2 , V_49 ) ;
if ( V_15 < 0 )
return V_15 ;
switch ( V_19 ) {
case V_50 :
V_13 = V_31 ? V_51
: V_52 ;
break;
case V_53 :
V_13 = V_31 ? V_54
: V_55 ;
break;
case V_56 :
V_13 = V_57 ;
break;
default:
return - V_42 ;
}
* V_8 = ! ! ( V_15 & V_13 ) ;
return 0 ;
}
static int F_22 ( struct V_16 * V_17 , T_4 V_19 , int V_31 ,
long * V_8 )
{
struct V_6 * V_7 = F_10 ( V_17 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_15 , V_12 , V_58 , V_59 ;
switch ( V_19 ) {
case V_60 :
V_58 = V_31 ? V_47 :
V_35 ;
V_59 = V_31 ? V_48 :
V_61 ;
V_15 = F_1 ( V_2 , V_58 , V_59 , 0 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = V_15 & 0x200 ? V_15 - 0x400 : V_15 ;
* V_8 = V_15 * 250 ;
return 0 ;
case V_62 :
case V_63 :
V_12 = ( V_19 == V_62 )
? F_23 ( V_31 )
: F_24 ( V_31 ) ;
V_15 = F_4 ( V_2 , V_12 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = V_15 & 0x80 ? V_15 - 0x100 : V_15 ;
* V_8 = V_15 * 1000 ;
return 0 ;
case V_50 :
case V_53 :
case V_56 :
return F_21 ( V_17 , V_19 , V_31 , V_8 ) ;
default:
return - V_42 ;
}
}
static int F_25 ( struct V_16 * V_17 , enum V_64 type ,
T_4 V_19 , int V_31 , long * V_8 )
{
switch ( type ) {
case V_65 :
return F_20 ( V_17 , V_19 , V_31 , V_8 ) ;
case V_66 :
return F_22 ( V_17 , V_19 , V_31 , V_8 ) ;
default:
return - V_42 ;
}
}
static int F_26 ( struct V_16 * V_17 , T_4 V_19 , long V_8 )
{
struct V_6 * V_7 = F_10 ( V_17 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_12 ;
V_8 = F_27 ( V_8 , 0 , 255 * 7000 / 256 ) ;
V_8 = F_28 ( V_8 * 256 , 7000 ) ;
switch ( V_19 ) {
case V_37 :
V_12 = V_38 ;
break;
case V_39 :
V_12 = V_40 ;
break;
default:
return - V_42 ;
}
return F_7 ( V_2 , V_12 , V_8 ) ;
}
static int F_29 ( struct V_16 * V_17 , T_4 V_19 , int V_31 ,
long V_8 )
{
struct V_6 * V_7 = F_10 ( V_17 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_15 , V_12 ;
F_3 ( & V_7 -> V_28 ) ;
V_15 = F_15 ( V_17 ) ;
if ( V_15 < 0 )
goto V_11;
V_8 = F_27 ( V_8 , 0 , 255 * V_7 -> V_45 / 256 ) ;
V_8 = F_28 ( V_8 * 256 , V_7 -> V_45 ) ;
switch ( V_19 ) {
case V_37 :
V_12 = F_18 ( V_31 ) ;
break;
case V_39 :
V_12 = F_19 ( V_31 ) ;
break;
default:
V_15 = - V_42 ;
goto V_11;
}
V_15 = F_7 ( V_2 , V_12 , V_8 ) ;
V_11:
F_5 ( & V_7 -> V_28 ) ;
return V_15 ;
}
static int F_30 ( struct V_16 * V_17 , T_4 V_19 , int V_31 ,
long V_8 )
{
if ( V_31 == 0 )
return F_26 ( V_17 , V_19 , V_8 ) ;
else
return F_29 ( V_17 , V_19 , V_31 , V_8 ) ;
}
static int F_31 ( struct V_16 * V_17 , T_4 V_19 , int V_31 ,
long V_8 )
{
struct V_6 * V_7 = F_10 ( V_17 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_12 ;
V_8 = F_27 ( V_8 , - 128000 , 127000 ) ;
V_8 = F_28 ( V_8 , 1000 ) ;
switch ( V_19 ) {
case V_62 :
V_12 = F_23 ( V_31 ) ;
break;
case V_63 :
V_12 = F_24 ( V_31 ) ;
break;
default:
return - V_42 ;
}
return F_7 ( V_2 , V_12 , V_8 ) ;
}
static int F_32 ( struct V_16 * V_17 , enum V_64 type ,
T_4 V_19 , int V_31 , long V_8 )
{
switch ( type ) {
case V_65 :
return F_30 ( V_17 , V_19 , V_31 , V_8 ) ;
case V_66 :
return F_31 ( V_17 , V_19 , V_31 , V_8 ) ;
default:
return - V_42 ;
}
}
static T_5 F_33 ( const void * V_67 ,
enum V_64 type ,
T_4 V_19 , int V_31 )
{
const struct V_6 * V_7 = V_67 ;
bool V_68 ;
switch ( type ) {
case V_65 :
V_68 = V_31 == 0 || V_31 >= 3 || ! V_7 -> V_69 ;
switch ( V_19 ) {
case V_34 :
case V_41 :
return V_68 ? V_70 : 0 ;
case V_37 :
case V_39 :
return V_68 ? V_70 | V_71 : 0 ;
}
break;
case V_66 :
V_68 = V_31 == 0 || V_7 -> V_69 ;
switch ( V_19 ) {
case V_60 :
case V_50 :
case V_53 :
case V_56 :
return V_68 ? V_70 : 0 ;
case V_62 :
case V_63 :
return V_68 ? V_70 | V_71 : 0 ;
}
break;
default:
break;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_72 * V_73 )
{
int V_8 ;
if ( ! F_35 ( V_2 -> V_74 , V_75 ) )
return - V_76 ;
V_8 = F_4 ( V_2 , V_77 ) ;
if ( V_8 < 0 || V_8 != V_78 ) {
F_36 ( & V_2 -> V_17 ,
L_2 ,
V_8 , V_78 ) ;
return - V_76 ;
}
V_8 = F_4 ( V_2 , V_79 ) ;
if ( V_8 < 0 || V_8 != V_80 ) {
F_36 ( & V_2 -> V_17 ,
L_3 ,
V_8 , V_80 ) ;
return - V_76 ;
}
F_37 ( V_73 -> type , L_4 , V_81 ) ;
return 0 ;
}
static int F_38 ( struct V_6 * V_7 )
{
int V_15 ;
T_1 V_8 ;
V_15 = F_4 ( V_7 -> V_2 , V_43 ) ;
if ( V_15 < 0 )
return V_15 ;
V_8 = V_15 ;
V_8 &= ~ ( V_82 | V_83 ) ;
V_8 |= V_84 ;
V_15 = F_7 ( V_7 -> V_2 , V_43 , V_8 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_4 ( V_7 -> V_2 , V_85 ) ;
if ( V_15 < 0 )
return V_15 ;
V_7 -> V_69 = V_15 & V_86 ;
V_8 = V_15 ;
V_8 &= ~ V_87 ;
V_8 |= V_88 ;
V_8 |= V_89 ;
return F_7 ( V_7 -> V_2 , V_85 , V_8 ) ;
}
static int F_39 ( struct V_1 * V_2 ,
const struct V_90 * V_91 )
{
struct V_16 * V_17 = & V_2 -> V_17 ;
struct V_6 * V_7 ;
struct V_16 * V_92 ;
int V_15 ;
V_7 = F_40 ( V_17 , sizeof( * V_7 ) , V_93 ) ;
if ( ! V_7 )
return - V_94 ;
F_41 ( V_2 , V_7 ) ;
V_7 -> V_2 = V_2 ;
F_42 ( & V_7 -> V_10 ) ;
F_42 ( & V_7 -> V_28 ) ;
V_15 = F_38 ( V_7 ) ;
if ( V_15 < 0 )
return V_15 ;
V_7 -> V_29 = V_30 ;
V_92 = F_43 ( V_17 , V_2 -> V_95 ,
V_7 ,
& V_96 ,
V_97 ) ;
return F_44 ( V_92 ) ;
}
