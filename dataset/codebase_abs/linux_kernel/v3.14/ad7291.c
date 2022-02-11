static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 = 0 ;
V_7 = F_2 ( V_6 , V_3 ) ;
if ( V_7 < 0 ) {
F_3 ( & V_6 -> V_8 , L_1 ) ;
return V_7 ;
}
* V_4 = V_7 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
return F_5 ( V_2 -> V_6 , V_3 , V_4 ) ;
}
static T_3 F_6 ( int V_9 , void * V_10 )
{
struct V_11 * V_12 = V_10 ;
struct V_1 * V_2 = F_7 ( V_10 ) ;
T_2 V_13 , V_14 ;
T_2 V_15 ;
int V_16 ;
T_4 V_17 = F_8 () ;
if ( F_1 ( V_2 , V_18 , & V_13 ) )
return V_19 ;
if ( F_1 ( V_2 , V_20 , & V_14 ) )
return V_19 ;
if ( ! ( V_13 || V_14 ) )
return V_19 ;
V_15 = V_2 -> V_15 | V_21 ;
F_4 ( V_2 , V_22 , V_15 ) ;
V_15 = V_2 -> V_15 & ~ V_21 ;
F_4 ( V_2 , V_22 , V_15 ) ;
if ( ( V_13 & ( 1 << 0 ) ) || ( V_13 & ( 1 << 2 ) ) )
F_9 ( V_12 ,
F_10 ( V_23 ,
0 ,
V_24 ,
V_25 ) ,
V_17 ) ;
if ( ( V_13 & ( 1 << 1 ) ) || ( V_13 & ( 1 << 3 ) ) )
F_9 ( V_12 ,
F_10 ( V_23 ,
0 ,
V_24 ,
V_26 ) ,
V_17 ) ;
for ( V_16 = 0 ; V_16 < V_27 * 2 ; V_16 += 2 ) {
if ( V_14 & ( 1 << V_16 ) )
F_9 ( V_12 ,
F_10 ( V_28 ,
V_16 / 2 ,
V_24 ,
V_25 ) ,
V_17 ) ;
if ( V_14 & ( 1 << ( V_16 + 1 ) ) )
F_9 ( V_12 ,
F_10 ( V_28 ,
V_16 / 2 ,
V_24 ,
V_26 ) ,
V_17 ) ;
}
return V_19 ;
}
static unsigned int F_11 ( const struct V_29 * V_30 ,
enum V_31 V_32 , enum V_33 V_34 )
{
unsigned int V_35 ;
switch ( V_30 -> type ) {
case V_28 :
V_35 = V_30 -> V_36 ;
break;
case V_23 :
V_35 = 8 ;
break;
default:
return 0 ;
}
switch ( V_34 ) {
case V_37 :
if ( V_32 == V_25 )
return F_12 ( V_35 ) ;
else
return F_13 ( V_35 ) ;
case V_38 :
return F_14 ( V_35 ) ;
default:
break;
}
return 0 ;
}
static int F_15 ( struct V_11 * V_12 ,
const struct V_29 * V_30 ,
enum V_39 type ,
enum V_31 V_32 ,
enum V_33 V_34 ,
int * V_40 , int * V_41 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
int V_7 ;
T_2 V_42 ;
V_7 = F_1 ( V_2 , F_11 ( V_30 , V_32 , V_34 ) ,
& V_42 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_34 == V_38 || V_30 -> type == V_28 )
* V_40 = V_42 & V_43 ;
else
* V_40 = F_16 ( V_42 , 11 ) ;
return V_44 ;
}
static int F_17 ( struct V_11 * V_12 ,
const struct V_29 * V_30 ,
enum V_39 type ,
enum V_31 V_32 ,
enum V_33 V_34 ,
int V_40 , int V_41 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
if ( V_34 == V_38 || V_30 -> type == V_28 ) {
if ( V_40 > V_43 || V_40 < 0 )
return - V_45 ;
} else {
if ( V_40 > 2047 || V_40 < - 2048 )
return - V_45 ;
}
return F_4 ( V_2 , F_11 ( V_30 , V_32 , V_34 ) ,
V_40 ) ;
}
static int F_18 ( struct V_11 * V_12 ,
const struct V_29 * V_30 ,
enum V_39 type ,
enum V_31 V_32 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
switch ( V_30 -> type ) {
case V_28 :
if ( V_2 -> V_46 & ( 1 << ( 15 - V_30 -> V_36 ) ) )
return 1 ;
else
return 0 ;
case V_23 :
return 1 ;
default:
return - V_45 ;
}
}
static int F_19 ( struct V_11 * V_12 ,
const struct V_29 * V_30 ,
enum V_39 type ,
enum V_31 V_32 ,
int V_47 )
{
int V_7 = 0 ;
struct V_1 * V_2 = F_7 ( V_12 ) ;
unsigned int V_48 ;
T_2 V_49 ;
F_20 ( & V_2 -> V_50 ) ;
V_49 = V_2 -> V_15 ;
V_48 = F_21 ( 15 - V_30 -> V_36 ) ;
switch ( V_30 -> type ) {
case V_28 :
if ( ( ! V_47 ) && ( V_2 -> V_46 & V_48 ) )
V_2 -> V_46 &= ~ V_48 ;
else if ( V_47 && ( ! ( V_2 -> V_46 & V_48 ) ) )
V_2 -> V_46 |= V_48 ;
else
break;
V_49 &= ~ V_51 ;
V_49 |= V_2 -> V_46 ;
if ( V_2 -> V_46 )
V_49 |= V_51 ;
V_7 = F_4 ( V_2 , V_22 , V_49 ) ;
if ( V_7 < 0 )
goto V_52;
V_2 -> V_15 = V_49 ;
break;
default:
V_7 = - V_45 ;
}
V_52:
F_22 ( & V_2 -> V_50 ) ;
return V_7 ;
}
static int F_23 ( struct V_11 * V_12 ,
struct V_29 const * V_30 ,
int * V_40 ,
int * V_41 ,
long V_48 )
{
int V_7 ;
struct V_1 * V_2 = F_7 ( V_12 ) ;
T_2 V_49 ;
switch ( V_48 ) {
case V_53 :
switch ( V_30 -> type ) {
case V_28 :
F_20 ( & V_2 -> V_50 ) ;
if ( V_2 -> V_15 & V_51 ) {
F_22 ( & V_2 -> V_50 ) ;
return - V_54 ;
}
V_49 = V_2 -> V_15 & ( ~ V_55 ) ;
V_49 |= 1 << ( 15 - V_30 -> V_36 ) ;
V_7 = F_4 ( V_2 , V_22 , V_49 ) ;
if ( V_7 < 0 ) {
F_22 ( & V_2 -> V_50 ) ;
return V_7 ;
}
V_7 = F_2 ( V_2 -> V_6 ,
V_56 ) ;
if ( V_7 < 0 ) {
F_22 ( & V_2 -> V_50 ) ;
return V_7 ;
}
* V_40 = V_7 & V_43 ;
F_22 ( & V_2 -> V_50 ) ;
return V_44 ;
case V_23 :
V_7 = F_2 ( V_2 -> V_6 ,
V_57 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_40 = F_16 ( V_7 , 11 ) ;
return V_44 ;
default:
return - V_45 ;
}
case V_58 :
V_7 = F_2 ( V_2 -> V_6 ,
V_59 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_40 = F_16 ( V_7 , 11 ) ;
return V_44 ;
case V_60 :
switch ( V_30 -> type ) {
case V_28 :
if ( V_2 -> V_3 ) {
int V_61 ;
V_61 = F_24 ( V_2 -> V_3 ) ;
if ( V_61 < 0 )
return V_61 ;
* V_40 = V_61 / 1000 ;
} else {
* V_40 = 2500 ;
}
* V_41 = V_62 ;
return V_63 ;
case V_23 :
* V_40 = 250 ;
return V_44 ;
default:
return - V_45 ;
}
default:
return - V_45 ;
}
}
static int F_25 ( struct V_5 * V_6 ,
const struct V_64 * V_65 )
{
struct V_66 * V_67 = V_6 -> V_8 . V_68 ;
struct V_1 * V_2 ;
struct V_11 * V_12 ;
int V_7 = 0 ;
V_12 = F_26 ( & V_6 -> V_8 , sizeof( * V_2 ) ) ;
if ( ! V_12 )
return - V_69 ;
V_2 = F_7 ( V_12 ) ;
if ( V_67 && V_67 -> V_70 ) {
V_2 -> V_3 = F_27 ( & V_6 -> V_8 , L_2 ) ;
if ( F_28 ( V_2 -> V_3 ) )
return V_7 ;
V_7 = F_29 ( V_2 -> V_3 ) ;
if ( V_7 )
return V_7 ;
}
F_30 ( & V_2 -> V_50 ) ;
F_31 ( V_6 , V_12 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_15 = V_71 |
V_72 |
V_73 ;
if ( V_67 && V_67 -> V_70 )
V_2 -> V_15 |= V_74 ;
V_12 -> V_75 = V_65 -> V_75 ;
V_12 -> V_76 = V_77 ;
V_12 -> V_78 = F_32 ( V_77 ) ;
V_12 -> V_8 . V_79 = & V_6 -> V_8 ;
V_12 -> V_34 = & V_80 ;
V_12 -> V_81 = V_82 ;
V_7 = F_4 ( V_2 , V_22 , V_83 ) ;
if ( V_7 ) {
V_7 = - V_84 ;
goto V_85;
}
V_7 = F_4 ( V_2 , V_22 , V_2 -> V_15 ) ;
if ( V_7 ) {
V_7 = - V_84 ;
goto V_85;
}
if ( V_6 -> V_9 > 0 ) {
V_7 = F_33 ( V_6 -> V_9 ,
NULL ,
& F_6 ,
V_86 | V_87 ,
V_65 -> V_75 ,
V_12 ) ;
if ( V_7 )
goto V_85;
}
V_7 = F_34 ( V_12 ) ;
if ( V_7 )
goto V_88;
return 0 ;
V_88:
if ( V_6 -> V_9 )
F_35 ( V_6 -> V_9 , V_12 ) ;
V_85:
if ( V_2 -> V_3 )
F_36 ( V_2 -> V_3 ) ;
return V_7 ;
}
static int F_37 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = F_38 ( V_6 ) ;
struct V_1 * V_2 = F_7 ( V_12 ) ;
F_39 ( V_12 ) ;
if ( V_6 -> V_9 )
F_35 ( V_6 -> V_9 , V_12 ) ;
if ( V_2 -> V_3 )
F_36 ( V_2 -> V_3 ) ;
return 0 ;
}
