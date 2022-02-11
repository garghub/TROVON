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
if ( ( V_13 & V_23 ) || ( V_13 & V_24 ) )
F_9 ( V_12 ,
F_10 ( V_25 ,
0 ,
V_26 ,
V_27 ) ,
V_17 ) ;
if ( ( V_13 & V_28 ) || ( V_13 & V_29 ) )
F_9 ( V_12 ,
F_10 ( V_25 ,
0 ,
V_26 ,
V_30 ) ,
V_17 ) ;
for ( V_16 = 0 ; V_16 < V_31 ; V_16 ++ ) {
if ( V_14 & F_11 ( V_16 ) )
F_9 ( V_12 ,
F_10 ( V_32 ,
V_16 ,
V_26 ,
V_27 ) ,
V_17 ) ;
if ( V_14 & F_12 ( V_16 ) )
F_9 ( V_12 ,
F_10 ( V_32 ,
V_16 ,
V_26 ,
V_30 ) ,
V_17 ) ;
}
return V_19 ;
}
static unsigned int F_13 ( const struct V_33 * V_34 ,
enum V_35 V_36 ,
enum V_37 V_38 )
{
unsigned int V_39 ;
switch ( V_34 -> type ) {
case V_32 :
V_39 = V_34 -> V_40 ;
break;
case V_25 :
V_39 = V_41 ;
break;
default:
return 0 ;
}
switch ( V_38 ) {
case V_42 :
if ( V_36 == V_27 )
return F_14 ( V_39 ) ;
else
return F_15 ( V_39 ) ;
case V_43 :
return F_16 ( V_39 ) ;
default:
break;
}
return 0 ;
}
static int F_17 ( struct V_11 * V_12 ,
const struct V_33 * V_34 ,
enum V_44 type ,
enum V_35 V_36 ,
enum V_37 V_38 ,
int * V_45 , int * V_46 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
int V_7 ;
T_2 V_47 ;
V_7 = F_1 ( V_2 , F_13 ( V_34 , V_36 , V_38 ) ,
& V_47 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_38 == V_43 || V_34 -> type == V_32 )
* V_45 = V_47 & V_48 ;
else
* V_45 = F_18 ( V_47 , 11 ) ;
return V_49 ;
}
static int F_19 ( struct V_11 * V_12 ,
const struct V_33 * V_34 ,
enum V_44 type ,
enum V_35 V_36 ,
enum V_37 V_38 ,
int V_45 , int V_46 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
if ( V_38 == V_43 || V_34 -> type == V_32 ) {
if ( V_45 > V_48 || V_45 < 0 )
return - V_50 ;
} else {
if ( V_45 > 2047 || V_45 < - 2048 )
return - V_50 ;
}
return F_4 ( V_2 , F_13 ( V_34 , V_36 , V_38 ) ,
V_45 ) ;
}
static int F_20 ( struct V_11 * V_12 ,
const struct V_33 * V_34 ,
enum V_44 type ,
enum V_35 V_36 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
switch ( V_34 -> type ) {
case V_32 :
return ! ! ( V_2 -> V_51 & F_21 ( 15 - V_34 -> V_40 ) ) ;
case V_25 :
return 1 ;
default:
return - V_50 ;
}
}
static int F_22 ( struct V_11 * V_12 ,
const struct V_33 * V_34 ,
enum V_44 type ,
enum V_35 V_36 ,
int V_52 )
{
int V_7 = 0 ;
struct V_1 * V_2 = F_7 ( V_12 ) ;
unsigned int V_53 ;
T_2 V_54 ;
F_23 ( & V_2 -> V_55 ) ;
V_54 = V_2 -> V_15 ;
V_53 = F_21 ( 15 - V_34 -> V_40 ) ;
switch ( V_34 -> type ) {
case V_32 :
if ( ( ! V_52 ) && ( V_2 -> V_51 & V_53 ) )
V_2 -> V_51 &= ~ V_53 ;
else if ( V_52 && ( ! ( V_2 -> V_51 & V_53 ) ) )
V_2 -> V_51 |= V_53 ;
else
break;
V_54 &= ~ V_56 ;
V_54 |= V_2 -> V_51 ;
if ( V_2 -> V_51 )
V_54 |= V_56 ;
V_7 = F_4 ( V_2 , V_22 , V_54 ) ;
if ( V_7 < 0 )
goto V_57;
V_2 -> V_15 = V_54 ;
break;
default:
V_7 = - V_50 ;
}
V_57:
F_24 ( & V_2 -> V_55 ) ;
return V_7 ;
}
static int F_25 ( struct V_11 * V_12 ,
struct V_33 const * V_34 ,
int * V_45 ,
int * V_46 ,
long V_53 )
{
int V_7 ;
struct V_1 * V_2 = F_7 ( V_12 ) ;
T_2 V_54 ;
switch ( V_53 ) {
case V_58 :
switch ( V_34 -> type ) {
case V_32 :
F_23 ( & V_2 -> V_55 ) ;
if ( V_2 -> V_15 & V_56 ) {
F_24 ( & V_2 -> V_55 ) ;
return - V_59 ;
}
V_54 = V_2 -> V_15 & ( ~ V_60 ) ;
V_54 |= F_21 ( 15 - V_34 -> V_40 ) ;
V_7 = F_4 ( V_2 , V_22 , V_54 ) ;
if ( V_7 < 0 ) {
F_24 ( & V_2 -> V_55 ) ;
return V_7 ;
}
V_7 = F_2 ( V_2 -> V_6 ,
V_61 ) ;
if ( V_7 < 0 ) {
F_24 ( & V_2 -> V_55 ) ;
return V_7 ;
}
* V_45 = V_7 & V_48 ;
F_24 ( & V_2 -> V_55 ) ;
return V_49 ;
case V_25 :
V_7 = F_2 ( V_2 -> V_6 ,
V_62 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_45 = F_18 ( V_7 , 11 ) ;
return V_49 ;
default:
return - V_50 ;
}
case V_63 :
V_7 = F_2 ( V_2 -> V_6 ,
V_64 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_45 = F_18 ( V_7 , 11 ) ;
return V_49 ;
case V_65 :
switch ( V_34 -> type ) {
case V_32 :
if ( V_2 -> V_3 ) {
int V_66 ;
V_66 = F_26 ( V_2 -> V_3 ) ;
if ( V_66 < 0 )
return V_66 ;
* V_45 = V_66 / 1000 ;
} else {
* V_45 = 2500 ;
}
* V_46 = V_67 ;
return V_68 ;
case V_25 :
* V_45 = 250 ;
return V_49 ;
default:
return - V_50 ;
}
default:
return - V_50 ;
}
}
static int F_27 ( struct V_5 * V_6 ,
const struct V_69 * V_70 )
{
struct V_71 * V_72 = V_6 -> V_8 . V_73 ;
struct V_1 * V_2 ;
struct V_11 * V_12 ;
int V_7 ;
V_12 = F_28 ( & V_6 -> V_8 , sizeof( * V_2 ) ) ;
if ( ! V_12 )
return - V_74 ;
V_2 = F_7 ( V_12 ) ;
if ( V_72 && V_72 -> V_75 ) {
V_2 -> V_3 = F_29 ( & V_6 -> V_8 , L_2 ) ;
if ( F_30 ( V_2 -> V_3 ) )
return F_31 ( V_2 -> V_3 ) ;
V_7 = F_32 ( V_2 -> V_3 ) ;
if ( V_7 )
return V_7 ;
}
F_33 ( & V_2 -> V_55 ) ;
F_34 ( V_6 , V_12 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_15 = V_76 |
V_77 |
V_78 ;
if ( V_72 && V_72 -> V_75 )
V_2 -> V_15 |= V_79 ;
V_12 -> V_80 = V_70 -> V_80 ;
V_12 -> V_81 = V_82 ;
V_12 -> V_83 = F_35 ( V_82 ) ;
V_12 -> V_8 . V_84 = & V_6 -> V_8 ;
V_12 -> V_38 = & V_85 ;
V_12 -> V_86 = V_87 ;
V_7 = F_4 ( V_2 , V_22 , V_88 ) ;
if ( V_7 ) {
V_7 = - V_89 ;
goto V_90;
}
V_7 = F_4 ( V_2 , V_22 , V_2 -> V_15 ) ;
if ( V_7 ) {
V_7 = - V_89 ;
goto V_90;
}
if ( V_6 -> V_9 > 0 ) {
V_7 = F_36 ( V_6 -> V_9 ,
NULL ,
& F_6 ,
V_91 | V_92 ,
V_70 -> V_80 ,
V_12 ) ;
if ( V_7 )
goto V_90;
}
V_7 = F_37 ( V_12 ) ;
if ( V_7 )
goto V_93;
return 0 ;
V_93:
if ( V_6 -> V_9 )
F_38 ( V_6 -> V_9 , V_12 ) ;
V_90:
if ( V_2 -> V_3 )
F_39 ( V_2 -> V_3 ) ;
return V_7 ;
}
static int F_40 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = F_41 ( V_6 ) ;
struct V_1 * V_2 = F_7 ( V_12 ) ;
F_42 ( V_12 ) ;
if ( V_6 -> V_9 )
F_38 ( V_6 -> V_9 , V_12 ) ;
if ( V_2 -> V_3 )
F_39 ( V_2 -> V_3 ) ;
return 0 ;
}
