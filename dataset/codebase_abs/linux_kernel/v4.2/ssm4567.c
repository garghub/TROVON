static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 ... V_5 :
return true ;
default:
return false ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 ... V_6 :
case V_7 ... V_8 :
case V_9 ... V_5 :
case V_10 :
return true ;
default:
return false ;
}
}
static bool F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_11 :
case V_12 ... V_13 :
case V_10 :
return true ;
default:
return false ;
}
}
static int F_4 ( struct V_14 * V_15 ,
struct V_16 * V_17 , struct V_18 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_21 ;
struct V_22 * V_22 = F_5 ( V_21 ) ;
unsigned int V_23 = F_6 ( V_17 ) ;
unsigned int V_24 ;
if ( V_23 >= 8000 && V_23 <= 12000 )
V_24 = V_25 ;
else if ( V_23 >= 16000 && V_23 <= 24000 )
V_24 = V_26 ;
else if ( V_23 >= 32000 && V_23 <= 48000 )
V_24 = V_27 ;
else if ( V_23 >= 64000 && V_23 <= 96000 )
V_24 = V_28 ;
else if ( V_23 >= 128000 && V_23 <= 192000 )
V_24 = V_29 ;
else
return - V_30 ;
return F_7 ( V_22 -> V_31 , V_32 ,
V_33 , V_24 ) ;
}
static int F_8 ( struct V_18 * V_19 , int V_34 )
{
struct V_22 * V_22 = F_5 ( V_19 -> V_21 ) ;
unsigned int V_35 ;
V_35 = V_34 ? V_36 : 0 ;
return F_7 ( V_22 -> V_31 , V_32 ,
V_36 , V_35 ) ;
}
static int F_9 ( struct V_18 * V_19 , unsigned int V_37 ,
unsigned int V_38 , int V_39 , int V_40 )
{
struct V_22 * V_22 = F_10 ( V_19 ) ;
unsigned int V_41 ;
int V_42 ;
int V_43 ;
if ( V_37 == 0 )
return - V_30 ;
if ( V_38 && V_38 != V_37 )
return - V_30 ;
V_42 = F_11 ( V_37 ) ;
if ( V_37 != F_12 ( V_42 ) )
return - V_30 ;
switch ( V_40 ) {
case 32 :
V_41 = V_44 ;
break;
case 48 :
V_41 = V_45 ;
break;
case 64 :
V_41 = V_46 ;
break;
default:
return - V_30 ;
}
V_43 = F_7 ( V_22 -> V_31 , V_47 ,
V_48 | V_49 ,
F_13 ( V_42 ) ) ;
if ( V_43 )
return V_43 ;
return F_7 ( V_22 -> V_31 , V_50 ,
V_51 , V_41 ) ;
}
static int F_14 ( struct V_18 * V_19 , unsigned int V_52 )
{
struct V_22 * V_22 = F_10 ( V_19 ) ;
unsigned int V_53 = 0 ;
bool V_54 ;
switch ( V_52 & V_55 ) {
case V_56 :
break;
default:
return - V_30 ;
}
switch ( V_52 & V_57 ) {
case V_58 :
V_54 = false ;
break;
case V_59 :
V_53 |= V_60 ;
V_54 = false ;
break;
case V_61 :
V_53 |= V_62 ;
V_54 = true ;
break;
case V_63 :
V_53 |= V_60 ;
V_54 = true ;
break;
default:
return - V_30 ;
}
switch ( V_52 & V_64 ) {
case V_65 :
break;
case V_66 :
V_53 |= V_67 ;
V_54 = ! V_54 ;
break;
case V_68 :
V_53 |= V_69 ;
break;
case V_70 :
V_53 |= V_69 | V_67 ;
break;
case V_71 :
V_53 |= V_72 ;
break;
default:
return - V_30 ;
}
if ( V_54 )
V_53 |= V_62 ;
return F_7 ( V_22 -> V_31 , V_50 ,
V_60 |
V_62 |
V_67 |
V_69 |
V_72 ,
V_53 ) ;
}
static int F_15 ( struct V_22 * V_22 , bool V_73 )
{
int V_43 = 0 ;
if ( ! V_73 ) {
V_43 = F_7 ( V_22 -> V_31 ,
V_4 ,
V_74 , V_74 ) ;
F_16 ( V_22 -> V_31 ) ;
}
F_17 ( V_22 -> V_31 , ! V_73 ) ;
if ( V_73 ) {
V_43 = F_7 ( V_22 -> V_31 ,
V_4 ,
V_74 , 0x00 ) ;
F_18 ( V_22 -> V_31 ) ;
}
return V_43 ;
}
static int F_19 ( struct V_20 * V_21 ,
enum V_75 V_76 )
{
struct V_22 * V_22 = F_5 ( V_21 ) ;
int V_43 = 0 ;
switch ( V_76 ) {
case V_77 :
break;
case V_78 :
break;
case V_79 :
if ( F_20 ( V_21 ) == V_80 )
V_43 = F_15 ( V_22 , true ) ;
break;
case V_80 :
V_43 = F_15 ( V_22 , false ) ;
break;
}
return V_43 ;
}
static int F_21 ( struct V_81 * V_82 ,
const struct V_83 * V_84 )
{
struct V_22 * V_22 ;
int V_43 ;
V_22 = F_22 ( & V_82 -> V_2 , sizeof( * V_22 ) , V_85 ) ;
if ( V_22 == NULL )
return - V_86 ;
F_23 ( V_82 , V_22 ) ;
V_22 -> V_31 = F_24 ( V_82 , & V_87 ) ;
if ( F_25 ( V_22 -> V_31 ) )
return F_26 ( V_22 -> V_31 ) ;
V_43 = F_27 ( V_22 -> V_31 , V_10 , 0x00 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_15 ( V_22 , false ) ;
if ( V_43 )
return V_43 ;
return F_28 ( & V_82 -> V_2 , & V_88 ,
& V_89 , 1 ) ;
}
static int F_29 ( struct V_81 * V_90 )
{
F_30 ( & V_90 -> V_2 ) ;
return 0 ;
}
