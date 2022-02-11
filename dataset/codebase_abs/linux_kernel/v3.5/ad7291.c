static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 = 0 ;
V_7 = F_2 ( V_6 , V_3 ) ;
if ( V_7 < 0 ) {
F_3 ( & V_6 -> V_8 , L_1 ) ;
return V_7 ;
}
* V_4 = F_4 ( ( T_2 ) V_7 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
return F_6 ( V_2 -> V_6 , V_3 , F_4 ( V_4 ) ) ;
}
static T_3 F_7 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
const char * V_12 ,
T_4 V_13 )
{
struct V_14 * V_15 = F_8 ( V_8 ) ;
struct V_1 * V_2 = F_9 ( V_15 ) ;
return F_5 ( V_2 , V_16 ,
V_2 -> V_17 | V_18 ) ;
}
static T_5 F_10 ( int V_19 , void * V_20 )
{
struct V_14 * V_15 = V_20 ;
struct V_1 * V_2 = F_9 ( V_20 ) ;
T_2 V_21 , V_22 ;
T_2 V_17 ;
int V_23 ;
T_6 V_24 = F_11 () ;
if ( F_1 ( V_2 , V_25 , & V_21 ) )
return V_26 ;
if ( F_1 ( V_2 , V_27 , & V_22 ) )
return V_26 ;
if ( ! ( V_21 || V_22 ) )
return V_26 ;
V_17 = V_2 -> V_17 | V_28 ;
F_5 ( V_2 , V_16 , V_17 ) ;
V_17 = V_2 -> V_17 & ~ V_28 ;
F_5 ( V_2 , V_16 , V_17 ) ;
if ( ( V_21 & ( 1 << 0 ) ) || ( V_21 & ( 1 << 2 ) ) )
F_12 ( V_15 ,
F_13 ( V_29 ,
0 ,
V_30 ,
V_31 ) ,
V_24 ) ;
if ( ( V_21 & ( 1 << 1 ) ) || ( V_21 & ( 1 << 3 ) ) )
F_12 ( V_15 ,
F_13 ( V_29 ,
0 ,
V_30 ,
V_32 ) ,
V_24 ) ;
for ( V_23 = 0 ; V_23 < V_33 * 2 ; V_23 += 2 ) {
if ( V_22 & ( 1 << V_23 ) )
F_12 ( V_15 ,
F_13 ( V_34 ,
V_23 / 2 ,
V_30 ,
V_31 ) ,
V_24 ) ;
if ( V_22 & ( 1 << ( V_23 + 1 ) ) )
F_12 ( V_15 ,
F_13 ( V_34 ,
V_23 / 2 ,
V_30 ,
V_32 ) ,
V_24 ) ;
}
return V_26 ;
}
static inline T_3 F_14 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
char * V_12 )
{
struct V_14 * V_15 = F_8 ( V_8 ) ;
struct V_1 * V_2 = F_9 ( V_15 ) ;
struct V_35 * V_36 = F_15 ( V_11 ) ;
T_2 V_4 ;
int V_7 ;
V_7 = F_1 ( V_2 , V_36 -> V_37 , & V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
return sprintf ( V_12 , L_2 , V_4 & V_38 ) ;
}
static inline T_3 F_16 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
const char * V_12 ,
T_4 V_13 )
{
struct V_14 * V_15 = F_8 ( V_8 ) ;
struct V_1 * V_2 = F_9 ( V_15 ) ;
struct V_35 * V_36 = F_15 ( V_11 ) ;
T_2 V_4 ;
int V_7 ;
V_7 = F_17 ( V_12 , 10 , & V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_4 > V_38 )
return - V_39 ;
V_7 = F_5 ( V_2 , V_36 -> V_37 , V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
return V_13 ;
}
static int F_18 ( struct V_14 * V_15 ,
T_7 V_40 ,
int * V_41 )
{
struct V_1 * V_2 = F_9 ( V_15 ) ;
int V_7 ;
T_1 V_3 ;
T_2 V_42 ;
T_8 V_43 ;
switch ( F_19 ( V_40 ) ) {
case V_34 :
V_3 = V_44 [ F_20 ( V_40 ) ]
[ ! ( F_21 ( V_40 ) ==
V_32 ) ] ;
V_7 = F_1 ( V_2 , V_3 , & V_42 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_41 = V_42 & V_38 ;
return 0 ;
case V_29 :
V_3 = V_44 [ 8 ]
[ ! ( F_21 ( V_40 ) ==
V_32 ) ] ;
V_7 = F_1 ( V_2 , V_3 , & V_43 ) ;
if ( V_7 < 0 )
return V_7 ;
V_43 = ( T_8 ) ( ( V_43 & V_38 ) << 4 ) >> 4 ;
* V_41 = V_43 ;
return 0 ;
default:
return - V_39 ;
} ;
}
static int F_22 ( struct V_14 * V_15 ,
T_7 V_40 ,
int V_41 )
{
struct V_1 * V_2 = F_9 ( V_15 ) ;
T_1 V_3 ;
T_8 V_43 ;
switch ( F_19 ( V_40 ) ) {
case V_34 :
if ( V_41 > V_38 || V_41 < 0 )
return - V_39 ;
V_3 = V_44 [ F_20 ( V_40 ) ]
[ ! ( F_21 ( V_40 ) ==
V_32 ) ] ;
return F_5 ( V_2 , V_3 , V_41 ) ;
case V_29 :
if ( V_41 > 2047 || V_41 < - 2048 )
return - V_39 ;
V_3 = V_44 [ 8 ]
[ ! ( F_21 ( V_40 ) ==
V_32 ) ] ;
V_43 = V_41 ;
return F_5 ( V_2 , V_3 , * ( T_2 * ) & V_43 ) ;
default:
return - V_39 ;
} ;
}
static int F_23 ( struct V_14 * V_15 ,
T_7 V_40 )
{
struct V_1 * V_2 = F_9 ( V_15 ) ;
switch ( F_19 ( V_40 ) ) {
case V_34 :
if ( V_2 -> V_45 &
( 1 << ( 15 - F_20 ( V_40 ) ) ) )
return 1 ;
else
return 0 ;
case V_29 :
return 1 ;
default:
return - V_39 ;
}
}
static int F_24 ( struct V_14 * V_15 ,
T_7 V_40 ,
int V_46 )
{
int V_7 = 0 ;
struct V_1 * V_2 = F_9 ( V_15 ) ;
T_2 V_47 ;
F_25 ( & V_2 -> V_48 ) ;
V_47 = V_2 -> V_17 ;
switch ( F_26 ( V_40 ) ) {
case V_34 :
if ( ( ! V_46 ) && ( V_2 -> V_45 & ( 1 << ( 15 -
F_20 ( V_40 ) ) ) ) )
V_2 -> V_45 &= ~ ( 1 << ( 15 - F_20
( V_40 ) ) ) ;
else if ( V_46 && ( ! ( V_2 -> V_45 & ( 1 << ( 15 -
F_20 ( V_40 ) ) ) ) ) )
V_2 -> V_45 |= ( 1 << ( 15 - F_20
( V_40 ) ) ) ;
else
break;
V_47 &= ~ V_49 ;
V_47 |= V_2 -> V_45 ;
if ( V_2 -> V_45 )
V_47 |= V_49 ;
V_7 = F_5 ( V_2 , V_16 , V_47 ) ;
if ( V_7 < 0 )
goto V_50;
V_2 -> V_17 = V_47 ;
break;
default:
V_7 = - V_39 ;
}
V_50:
F_27 ( & V_2 -> V_48 ) ;
return V_7 ;
}
static int F_28 ( struct V_14 * V_15 ,
struct V_51 const * V_52 ,
int * V_41 ,
int * V_53 ,
long V_54 )
{
int V_7 ;
struct V_1 * V_2 = F_9 ( V_15 ) ;
unsigned int V_55 ;
T_2 V_47 ;
T_8 V_43 ;
switch ( V_54 ) {
case V_56 :
switch ( V_52 -> type ) {
case V_34 :
F_25 ( & V_2 -> V_48 ) ;
if ( V_2 -> V_17 & V_49 ) {
F_27 ( & V_2 -> V_48 ) ;
return - V_57 ;
}
V_47 = V_2 -> V_17 & ( ~ V_58 ) ;
V_47 |= 1 << ( 15 - V_52 -> V_59 ) ;
V_7 = F_5 ( V_2 , V_16 , V_47 ) ;
if ( V_7 < 0 ) {
F_27 ( & V_2 -> V_48 ) ;
return V_7 ;
}
V_7 = F_2 ( V_2 -> V_6 ,
V_60 ) ;
if ( V_7 < 0 ) {
F_27 ( & V_2 -> V_48 ) ;
return V_7 ;
}
* V_41 = F_4 ( ( T_2 ) V_7 ) & V_38 ;
F_27 ( & V_2 -> V_48 ) ;
return V_61 ;
case V_29 :
V_7 = F_2 ( V_2 -> V_6 ,
V_62 ) ;
if ( V_7 < 0 )
return V_7 ;
V_43 = ( T_8 ) ( ( F_4 ( ( T_2 ) V_7 ) &
V_38 ) << 4 ) >> 4 ;
* V_41 = V_43 ;
return V_61 ;
default:
return - V_39 ;
}
case V_63 :
V_7 = F_2 ( V_2 -> V_6 ,
V_64 ) ;
if ( V_7 < 0 )
return V_7 ;
V_43 = ( T_8 ) ( ( F_4 ( ( T_2 ) V_7 ) &
V_38 ) << 4 ) >> 4 ;
* V_41 = V_43 ;
return V_61 ;
case V_65 :
switch ( V_52 -> type ) {
case V_34 :
V_55 = ( V_2 -> V_66 * 1000 ) >> V_67 ;
* V_41 = V_55 / 1000 ;
* V_53 = ( V_55 % 1000 ) * 1000 ;
return V_68 ;
case V_29 :
* V_41 = 250 ;
return V_61 ;
default:
return - V_39 ;
}
default:
return - V_39 ;
}
}
static int T_9 F_29 ( struct V_5 * V_6 ,
const struct V_69 * V_70 )
{
struct V_1 * V_2 ;
struct V_14 * V_15 ;
int V_7 = 0 , V_71 = 0 ;
V_15 = F_30 ( sizeof( * V_2 ) ) ;
if ( V_15 == NULL ) {
V_7 = - V_72 ;
goto V_50;
}
V_2 = F_9 ( V_15 ) ;
V_2 -> V_3 = F_31 ( & V_6 -> V_8 , L_3 ) ;
if ( ! F_32 ( V_2 -> V_3 ) ) {
V_7 = F_33 ( V_2 -> V_3 ) ;
if ( V_7 )
goto V_73;
V_71 = F_34 ( V_2 -> V_3 ) ;
}
F_35 ( & V_2 -> V_48 ) ;
F_36 ( V_6 , V_15 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_17 = V_74 |
V_75 |
V_76 ;
if ( V_71 ) {
V_2 -> V_66 = V_71 / 1000 ;
V_2 -> V_17 |= V_77 ;
} else {
V_2 -> V_66 = 2500 ;
}
V_15 -> V_78 = V_70 -> V_78 ;
V_15 -> V_79 = V_80 ;
V_15 -> V_81 = F_37 ( V_80 ) ;
V_15 -> V_8 . V_82 = & V_6 -> V_8 ;
V_15 -> V_83 = & V_84 ;
V_15 -> V_85 = V_86 ;
V_7 = F_5 ( V_2 , V_16 , V_18 ) ;
if ( V_7 ) {
V_7 = - V_87 ;
goto V_88;
}
V_7 = F_5 ( V_2 , V_16 , V_2 -> V_17 ) ;
if ( V_7 ) {
V_7 = - V_87 ;
goto V_88;
}
if ( V_6 -> V_19 > 0 ) {
V_7 = F_38 ( V_6 -> V_19 ,
NULL ,
& F_10 ,
V_89 | V_90 ,
V_70 -> V_78 ,
V_15 ) ;
if ( V_7 )
goto V_88;
}
V_7 = F_39 ( V_15 ) ;
if ( V_7 )
goto V_91;
F_40 ( & V_6 -> V_8 , L_4 ,
V_70 -> V_78 ) ;
return 0 ;
V_91:
if ( V_6 -> V_19 )
F_41 ( V_6 -> V_19 , V_15 ) ;
V_88:
if ( ! F_32 ( V_2 -> V_3 ) )
F_42 ( V_2 -> V_3 ) ;
V_73:
if ( ! F_32 ( V_2 -> V_3 ) )
F_43 ( V_2 -> V_3 ) ;
F_44 ( V_15 ) ;
V_50:
return V_7 ;
}
static int T_10 F_45 ( struct V_5 * V_6 )
{
struct V_14 * V_15 = F_46 ( V_6 ) ;
struct V_1 * V_2 = F_9 ( V_15 ) ;
F_47 ( V_15 ) ;
if ( V_6 -> V_19 )
F_41 ( V_6 -> V_19 , V_15 ) ;
if ( ! F_32 ( V_2 -> V_3 ) ) {
F_42 ( V_2 -> V_3 ) ;
F_43 ( V_2 -> V_3 ) ;
}
F_44 ( V_15 ) ;
return 0 ;
}
