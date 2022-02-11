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
static inline T_5 F_11 ( struct V_29 * V_8 ,
struct V_30 * V_31 ,
char * V_32 )
{
struct V_11 * V_12 = F_12 ( V_8 ) ;
struct V_1 * V_2 = F_7 ( V_12 ) ;
struct V_33 * V_34 = F_13 ( V_31 ) ;
T_2 V_4 ;
int V_7 ;
V_7 = F_1 ( V_2 , V_34 -> V_35 , & V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
return sprintf ( V_32 , L_2 , V_4 & V_36 ) ;
}
static inline T_5 F_14 ( struct V_29 * V_8 ,
struct V_30 * V_31 ,
const char * V_32 ,
T_6 V_37 )
{
struct V_11 * V_12 = F_12 ( V_8 ) ;
struct V_1 * V_2 = F_7 ( V_12 ) ;
struct V_33 * V_34 = F_13 ( V_31 ) ;
T_2 V_4 ;
int V_7 ;
V_7 = F_15 ( V_32 , 10 , & V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_4 > V_36 )
return - V_38 ;
V_7 = F_4 ( V_2 , V_34 -> V_35 , V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
return V_37 ;
}
static unsigned int F_16 ( T_7 V_39 )
{
unsigned int V_40 ;
switch ( F_17 ( V_39 ) ) {
case V_28 :
V_40 = F_18 ( V_39 ) ;
break;
case V_23 :
V_40 = 8 ;
break;
default:
return 0 ;
}
if ( F_19 ( V_39 ) == V_25 )
return F_20 ( V_40 ) ;
else
return F_21 ( V_40 ) ;
}
static int F_22 ( struct V_11 * V_12 ,
T_7 V_39 ,
int * V_41 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
int V_7 ;
T_2 V_42 ;
V_7 = F_1 ( V_2 , F_16 ( V_39 ) , & V_42 ) ;
if ( V_7 < 0 )
return V_7 ;
switch ( F_17 ( V_39 ) ) {
case V_28 :
* V_41 = V_42 & V_36 ;
return 0 ;
case V_23 :
* V_41 = F_23 ( V_42 , 11 ) ;
return 0 ;
default:
return - V_38 ;
} ;
}
static int F_24 ( struct V_11 * V_12 ,
T_7 V_39 ,
int V_41 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
switch ( F_17 ( V_39 ) ) {
case V_28 :
if ( V_41 > V_36 || V_41 < 0 )
return - V_38 ;
break;
case V_23 :
if ( V_41 > 2047 || V_41 < - 2048 )
return - V_38 ;
break;
default:
return - V_38 ;
}
return F_4 ( V_2 , F_16 ( V_39 ) , V_41 ) ;
}
static int F_25 ( struct V_11 * V_12 ,
T_7 V_39 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
switch ( F_17 ( V_39 ) ) {
case V_28 :
if ( V_2 -> V_43 &
( 1 << ( 15 - F_18 ( V_39 ) ) ) )
return 1 ;
else
return 0 ;
case V_23 :
return 1 ;
default:
return - V_38 ;
}
}
static int F_26 ( struct V_11 * V_12 ,
T_7 V_39 ,
int V_44 )
{
int V_7 = 0 ;
struct V_1 * V_2 = F_7 ( V_12 ) ;
T_2 V_45 ;
F_27 ( & V_2 -> V_46 ) ;
V_45 = V_2 -> V_15 ;
switch ( F_28 ( V_39 ) ) {
case V_28 :
if ( ( ! V_44 ) && ( V_2 -> V_43 & ( 1 << ( 15 -
F_18 ( V_39 ) ) ) ) )
V_2 -> V_43 &= ~ ( 1 << ( 15 - F_18
( V_39 ) ) ) ;
else if ( V_44 && ( ! ( V_2 -> V_43 & ( 1 << ( 15 -
F_18 ( V_39 ) ) ) ) ) )
V_2 -> V_43 |= ( 1 << ( 15 - F_18
( V_39 ) ) ) ;
else
break;
V_45 &= ~ V_47 ;
V_45 |= V_2 -> V_43 ;
if ( V_2 -> V_43 )
V_45 |= V_47 ;
V_7 = F_4 ( V_2 , V_22 , V_45 ) ;
if ( V_7 < 0 )
goto V_48;
V_2 -> V_15 = V_45 ;
break;
default:
V_7 = - V_38 ;
}
V_48:
F_29 ( & V_2 -> V_46 ) ;
return V_7 ;
}
static int F_30 ( struct V_11 * V_12 ,
struct V_49 const * V_50 ,
int * V_41 ,
int * V_51 ,
long V_52 )
{
int V_7 ;
struct V_1 * V_2 = F_7 ( V_12 ) ;
T_2 V_45 ;
switch ( V_52 ) {
case V_53 :
switch ( V_50 -> type ) {
case V_28 :
F_27 ( & V_2 -> V_46 ) ;
if ( V_2 -> V_15 & V_47 ) {
F_29 ( & V_2 -> V_46 ) ;
return - V_54 ;
}
V_45 = V_2 -> V_15 & ( ~ V_55 ) ;
V_45 |= 1 << ( 15 - V_50 -> V_56 ) ;
V_7 = F_4 ( V_2 , V_22 , V_45 ) ;
if ( V_7 < 0 ) {
F_29 ( & V_2 -> V_46 ) ;
return V_7 ;
}
V_7 = F_2 ( V_2 -> V_6 ,
V_57 ) ;
if ( V_7 < 0 ) {
F_29 ( & V_2 -> V_46 ) ;
return V_7 ;
}
* V_41 = V_7 & V_36 ;
F_29 ( & V_2 -> V_46 ) ;
return V_58 ;
case V_23 :
V_7 = F_2 ( V_2 -> V_6 ,
V_59 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_41 = F_23 ( V_7 , 11 ) ;
return V_58 ;
default:
return - V_38 ;
}
case V_60 :
V_7 = F_2 ( V_2 -> V_6 ,
V_61 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_41 = F_23 ( V_7 , 11 ) ;
return V_58 ;
case V_62 :
switch ( V_50 -> type ) {
case V_28 :
if ( V_2 -> V_3 ) {
int V_63 ;
V_63 = F_31 ( V_2 -> V_3 ) ;
if ( V_63 < 0 )
return V_63 ;
* V_41 = V_63 / 1000 ;
} else {
* V_41 = 2500 ;
}
* V_51 = V_64 ;
return V_65 ;
case V_23 :
* V_41 = 250 ;
return V_58 ;
default:
return - V_38 ;
}
default:
return - V_38 ;
}
}
static int F_32 ( struct V_5 * V_6 ,
const struct V_66 * V_67 )
{
struct V_68 * V_69 = V_6 -> V_8 . V_70 ;
struct V_1 * V_2 ;
struct V_11 * V_12 ;
int V_7 = 0 ;
V_12 = F_33 ( sizeof( * V_2 ) ) ;
if ( V_12 == NULL ) {
V_7 = - V_71 ;
goto V_48;
}
V_2 = F_7 ( V_12 ) ;
if ( V_69 && V_69 -> V_72 ) {
V_2 -> V_3 = F_34 ( & V_6 -> V_8 , L_3 ) ;
if ( F_35 ( V_2 -> V_3 ) )
goto V_73;
V_7 = F_36 ( V_2 -> V_3 ) ;
if ( V_7 )
goto V_74;
}
F_37 ( & V_2 -> V_46 ) ;
F_38 ( V_6 , V_12 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_15 = V_75 |
V_76 |
V_77 ;
if ( V_69 && V_69 -> V_72 )
V_2 -> V_15 |= V_78 ;
V_12 -> V_79 = V_67 -> V_79 ;
V_12 -> V_80 = V_81 ;
V_12 -> V_82 = F_39 ( V_81 ) ;
V_12 -> V_8 . V_83 = & V_6 -> V_8 ;
V_12 -> V_84 = & V_85 ;
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
V_7 = F_40 ( V_6 -> V_9 ,
NULL ,
& F_6 ,
V_91 | V_92 ,
V_67 -> V_79 ,
V_12 ) ;
if ( V_7 )
goto V_90;
}
V_7 = F_41 ( V_12 ) ;
if ( V_7 )
goto V_93;
return 0 ;
V_93:
if ( V_6 -> V_9 )
F_42 ( V_6 -> V_9 , V_12 ) ;
V_90:
if ( V_2 -> V_3 )
F_43 ( V_2 -> V_3 ) ;
V_74:
if ( V_2 -> V_3 )
F_44 ( V_2 -> V_3 ) ;
V_73:
F_45 ( V_12 ) ;
V_48:
return V_7 ;
}
static int F_46 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = F_47 ( V_6 ) ;
struct V_1 * V_2 = F_7 ( V_12 ) ;
F_48 ( V_12 ) ;
if ( V_6 -> V_9 )
F_42 ( V_6 -> V_9 , V_12 ) ;
if ( V_2 -> V_3 ) {
F_43 ( V_2 -> V_3 ) ;
F_44 ( V_2 -> V_3 ) ;
}
F_45 ( V_12 ) ;
return 0 ;
}
