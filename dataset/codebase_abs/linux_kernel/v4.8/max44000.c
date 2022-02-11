static int F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
int V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_6 , & V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
return ( V_3 & V_7 ) >> V_8 ;
}
static int F_3 ( struct V_1 * V_2 , int V_3 )
{
return F_4 ( V_2 -> V_5 , V_6 ,
V_7 ,
V_3 << V_8 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
int V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_6 , & V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
return ( V_3 & V_9 ) >> V_10 ;
}
static int F_6 ( struct V_1 * V_2 , int V_3 )
{
return F_4 ( V_2 -> V_5 , V_6 ,
V_9 ,
V_3 << V_10 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
T_1 V_11 ;
int V_12 , V_4 ;
V_4 = F_8 ( V_2 -> V_5 , V_13 ,
& V_11 , sizeof( V_11 ) ) ;
if ( V_4 < 0 )
return V_4 ;
V_12 = V_4 = F_1 ( V_2 ) ;
if ( V_4 < 0 )
return V_4 ;
V_11 = F_9 ( V_11 ) ;
if ( V_11 & V_14 )
return 0x3FFF ;
return V_11 << F_10 ( V_12 ) ;
}
static int F_11 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 < 0 || V_3 > V_15 )
return - V_16 ;
if ( V_3 >= 8 )
V_3 += 4 ;
return F_4 ( V_2 -> V_5 , V_17 ,
V_18 , V_3 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
unsigned int V_11 ;
int V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_17 , & V_11 ) ;
if ( V_4 < 0 )
return V_4 ;
V_11 &= V_18 ;
if ( V_11 >= 8 )
V_11 -= 4 ;
return V_11 ;
}
static int F_13 ( struct V_19 * V_20 ,
struct V_21 const * V_22 ,
int * V_3 , int * V_23 , long V_24 )
{
struct V_1 * V_2 = F_14 ( V_20 ) ;
int V_12 , V_25 ;
unsigned int V_11 ;
int V_4 ;
switch ( V_24 ) {
case V_26 :
switch ( V_22 -> type ) {
case V_27 :
F_15 ( & V_2 -> V_28 ) ;
V_4 = F_7 ( V_2 ) ;
F_16 ( & V_2 -> V_28 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_3 = V_4 ;
return V_29 ;
case V_30 :
F_15 ( & V_2 -> V_28 ) ;
V_4 = F_2 ( V_2 -> V_5 , V_31 , & V_11 ) ;
F_16 ( & V_2 -> V_28 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_3 = V_11 ;
return V_29 ;
case V_32 :
F_15 ( & V_2 -> V_28 ) ;
V_4 = F_12 ( V_2 ) ;
F_16 ( & V_2 -> V_28 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_3 = V_4 ;
return V_29 ;
default:
return - V_33 ;
}
case V_34 :
switch ( V_22 -> type ) {
case V_32 :
* V_3 = 10 ;
return V_29 ;
case V_27 :
F_15 ( & V_2 -> V_28 ) ;
V_25 = V_4 = F_5 ( V_2 ) ;
F_16 ( & V_2 -> V_28 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_3 = ( 1 << V_35 ) ;
* V_23 = V_36
+ V_35
- V_37 [ V_25 ] ;
return V_38 ;
default:
return - V_33 ;
}
case V_39 :
F_15 ( & V_2 -> V_28 ) ;
V_12 = V_4 = F_1 ( V_2 ) ;
F_16 ( & V_2 -> V_28 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_3 = 0 ;
* V_23 = V_40 [ V_12 ] ;
return V_41 ;
default:
return - V_33 ;
}
}
static int F_17 ( struct V_19 * V_20 ,
struct V_21 const * V_22 ,
int V_3 , int V_23 , long V_24 )
{
struct V_1 * V_2 = F_14 ( V_20 ) ;
int V_4 ;
if ( V_24 == V_26 && V_22 -> type == V_32 ) {
F_15 ( & V_2 -> V_28 ) ;
V_4 = F_11 ( V_2 , V_3 ) ;
F_16 ( & V_2 -> V_28 ) ;
return V_4 ;
} else if ( V_24 == V_39 && V_22 -> type == V_27 ) {
T_2 V_42 = V_3 * V_43 + V_23 ;
int V_12 = F_18 ( V_42 ,
V_40 ,
F_19 ( V_40 ) ) ;
F_15 ( & V_2 -> V_28 ) ;
V_4 = F_3 ( V_2 , V_12 ) ;
F_16 ( & V_2 -> V_28 ) ;
return V_4 ;
} else if ( V_24 == V_34 && V_22 -> type == V_27 ) {
T_2 V_44 = V_3 * V_45 + V_23 ;
int V_25 = F_20 ( V_44 ,
V_46 ,
F_19 ( V_46 ) ) ;
F_15 ( & V_2 -> V_28 ) ;
V_4 = F_6 ( V_2 , V_25 ) ;
F_16 ( & V_2 -> V_28 ) ;
return V_4 ;
}
return - V_33 ;
}
static int F_21 ( struct V_19 * V_20 ,
struct V_21 const * V_22 ,
long V_24 )
{
if ( V_24 == V_39 && V_22 -> type == V_27 )
return V_41 ;
else if ( V_24 == V_34 && V_22 -> type == V_27 )
return V_47 ;
else
return V_29 ;
}
static bool F_22 ( struct V_48 * V_49 , unsigned int V_50 )
{
switch ( V_50 ) {
case V_51 :
case V_52 :
case V_6 :
case V_17 :
case V_13 :
case V_53 :
case V_31 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
return true ;
default:
return false ;
}
}
static bool F_23 ( struct V_48 * V_49 , unsigned int V_50 )
{
switch ( V_50 ) {
case V_52 :
case V_6 :
case V_17 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
return true ;
default:
return false ;
}
}
static bool F_24 ( struct V_48 * V_49 , unsigned int V_50 )
{
switch ( V_50 ) {
case V_51 :
case V_13 :
case V_53 :
case V_31 :
return true ;
default:
return false ;
}
}
static bool F_25 ( struct V_48 * V_49 , unsigned int V_50 )
{
return V_50 == V_51 ;
}
static T_3 F_26 ( int V_63 , void * V_64 )
{
struct V_65 * V_66 = V_64 ;
struct V_19 * V_20 = V_66 -> V_20 ;
struct V_1 * V_2 = F_14 ( V_20 ) ;
T_1 V_67 [ 8 ] ;
int V_68 = 0 ;
unsigned int V_11 ;
int V_4 ;
F_15 ( & V_2 -> V_28 ) ;
if ( F_27 ( V_69 , V_20 -> V_70 ) ) {
V_4 = F_7 ( V_2 ) ;
if ( V_4 < 0 )
goto V_71;
V_67 [ V_68 ++ ] = V_4 ;
}
if ( F_27 ( V_72 , V_20 -> V_70 ) ) {
V_4 = F_2 ( V_2 -> V_5 , V_31 , & V_11 ) ;
if ( V_4 < 0 )
goto V_71;
V_67 [ V_68 ] = V_11 ;
}
F_16 ( & V_2 -> V_28 ) ;
F_28 ( V_20 , V_67 ,
F_29 ( V_20 ) ) ;
F_30 ( V_20 -> V_73 ) ;
return V_74 ;
V_71:
F_16 ( & V_2 -> V_28 ) ;
F_30 ( V_20 -> V_73 ) ;
return V_74 ;
}
static int F_31 ( struct V_75 * V_76 ,
const struct V_77 * V_78 )
{
struct V_1 * V_2 ;
struct V_19 * V_20 ;
int V_4 , V_50 ;
V_20 = F_32 ( & V_76 -> V_49 , sizeof( * V_2 ) ) ;
if ( ! V_20 )
return - V_79 ;
V_2 = F_14 ( V_20 ) ;
V_2 -> V_5 = F_33 ( V_76 , & V_80 ) ;
if ( F_34 ( V_2 -> V_5 ) ) {
F_35 ( & V_76 -> V_49 , L_1 ) ;
return F_36 ( V_2 -> V_5 ) ;
}
F_37 ( V_76 , V_20 ) ;
F_38 ( & V_2 -> V_28 ) ;
V_20 -> V_49 . V_81 = & V_76 -> V_49 ;
V_20 -> V_82 = & V_83 ;
V_20 -> V_84 = V_85 ;
V_20 -> V_86 = V_87 ;
V_20 -> V_88 = F_19 ( V_87 ) ;
V_4 = F_39 ( V_2 -> V_5 , V_6 ,
V_89 ) ;
if ( V_4 < 0 ) {
F_35 ( & V_76 -> V_49 , L_2 ,
V_4 ) ;
return V_4 ;
}
V_4 = F_11 ( V_2 , V_90 ) ;
if ( V_4 < 0 ) {
F_35 ( & V_76 -> V_49 , L_3 , V_4 ) ;
return V_4 ;
}
V_50 = V_91 | V_92 ;
V_4 = F_39 ( V_2 -> V_5 , V_52 , V_50 ) ;
if ( V_4 < 0 ) {
F_35 ( & V_76 -> V_49 , L_3 , V_4 ) ;
return V_4 ;
}
V_4 = F_2 ( V_2 -> V_5 , V_51 , & V_50 ) ;
if ( V_4 < 0 ) {
F_35 ( & V_76 -> V_49 , L_4 , V_4 ) ;
return V_4 ;
}
V_4 = F_40 ( V_20 , NULL , F_26 , NULL ) ;
if ( V_4 < 0 ) {
F_35 ( & V_76 -> V_49 , L_5 ) ;
return V_4 ;
}
return F_41 ( V_20 ) ;
}
static int F_42 ( struct V_75 * V_76 )
{
struct V_19 * V_20 = F_43 ( V_76 ) ;
F_44 ( V_20 ) ;
F_45 ( V_20 ) ;
return 0 ;
}
