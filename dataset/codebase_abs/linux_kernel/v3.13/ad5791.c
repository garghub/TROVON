static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
union {
T_2 V_5 ;
T_1 V_6 [ 4 ] ;
} V_7 ;
V_7 . V_5 = F_2 ( V_8 |
F_3 ( V_3 ) |
( V_4 & V_9 ) ) ;
return F_4 ( V_2 , & V_7 . V_6 [ 1 ] , 3 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
union {
T_2 V_5 ;
T_1 V_6 [ 4 ] ;
} V_7 [ 3 ] ;
int V_10 ;
struct V_11 V_12 [] = {
{
. V_13 = & V_7 [ 0 ] . V_6 [ 1 ] ,
. V_14 = 8 ,
. V_15 = 3 ,
. V_16 = 1 ,
} , {
. V_13 = & V_7 [ 1 ] . V_6 [ 1 ] ,
. V_17 = & V_7 [ 2 ] . V_6 [ 1 ] ,
. V_14 = 8 ,
. V_15 = 3 ,
} ,
} ;
V_7 [ 0 ] . V_5 = F_2 ( V_18 |
F_3 ( V_3 ) ) ;
V_7 [ 1 ] . V_5 = F_2 ( F_3 ( V_19 ) ) ;
V_10 = F_6 ( V_2 , V_12 , F_7 ( V_12 ) ) ;
* V_4 = F_8 ( V_7 [ 2 ] . V_5 ) ;
return V_10 ;
}
static int F_9 ( struct V_20 * V_21 ,
const struct V_22 * V_23 )
{
struct V_24 * V_25 = F_10 ( V_21 ) ;
return V_25 -> V_26 ;
}
static int F_11 ( struct V_20 * V_21 ,
const struct V_22 * V_23 , unsigned int V_27 )
{
struct V_24 * V_25 = F_10 ( V_21 ) ;
V_25 -> V_26 = V_27 ;
return 0 ;
}
static T_3 F_12 ( struct V_20 * V_21 ,
T_4 V_28 , const struct V_22 * V_23 , char * V_29 )
{
struct V_24 * V_25 = F_10 ( V_21 ) ;
return sprintf ( V_29 , L_1 , V_25 -> V_30 ) ;
}
static T_3 F_13 ( struct V_20 * V_21 ,
T_4 V_28 , const struct V_22 * V_23 , const char * V_29 ,
T_5 V_15 )
{
bool V_30 ;
int V_10 ;
struct V_24 * V_25 = F_10 ( V_21 ) ;
V_10 = F_14 ( V_29 , & V_30 ) ;
if ( V_10 )
return V_10 ;
if ( ! V_30 ) {
V_25 -> V_31 &= ~ ( V_32 | V_33 ) ;
} else {
if ( V_25 -> V_26 == V_34 )
V_25 -> V_31 |= V_32 ;
else if ( V_25 -> V_26 == V_35 )
V_25 -> V_31 |= V_33 ;
}
V_25 -> V_30 = V_30 ;
V_10 = F_1 ( V_25 -> V_2 , V_36 , V_25 -> V_31 ) ;
return V_10 ? V_10 : V_15 ;
}
static int F_15 ( unsigned int V_37 )
{
if ( V_37 <= 10000 )
return V_38 ;
else if ( V_37 <= 12000 )
return V_39 ;
else if ( V_37 <= 16000 )
return V_40 ;
else if ( V_37 <= 19000 )
return V_41 ;
else
return V_42 ;
}
static int F_16 ( unsigned int V_37 )
{
if ( V_37 <= 10000 )
return V_43 ;
else
return V_44 ;
}
static int F_17 ( struct V_20 * V_21 ,
struct V_22 const * V_23 ,
int * V_4 ,
int * V_45 ,
long V_46 )
{
struct V_24 * V_25 = F_10 ( V_21 ) ;
T_6 V_47 ;
int V_10 ;
switch ( V_46 ) {
case V_48 :
V_10 = F_5 ( V_25 -> V_2 , V_23 -> V_49 , V_4 ) ;
if ( V_10 )
return V_10 ;
* V_4 &= V_9 ;
* V_4 >>= V_23 -> V_50 . V_51 ;
return V_52 ;
case V_53 :
* V_4 = V_25 -> V_54 ;
* V_45 = ( 1 << V_23 -> V_50 . V_55 ) - 1 ;
return V_56 ;
case V_57 :
V_47 = ( ( ( T_6 ) V_25 -> V_58 ) << V_23 -> V_50 . V_55 ) ;
F_18 ( V_47 , V_25 -> V_54 ) ;
* V_4 = - V_47 ;
return V_52 ;
default:
return - V_59 ;
}
}
static int F_19 ( struct V_20 * V_21 ,
struct V_22 const * V_23 ,
int V_4 ,
int V_45 ,
long V_60 )
{
struct V_24 * V_25 = F_10 ( V_21 ) ;
switch ( V_60 ) {
case V_48 :
V_4 &= F_20 ( V_23 -> V_50 . V_55 ) ;
V_4 <<= V_23 -> V_50 . V_51 ;
return F_1 ( V_25 -> V_2 , V_23 -> V_49 , V_4 ) ;
default:
return - V_59 ;
}
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_63 . V_64 ;
struct V_20 * V_21 ;
struct V_24 * V_25 ;
int V_10 , V_65 = 0 , V_66 = 0 ;
V_21 = F_22 ( & V_2 -> V_63 , sizeof( * V_25 ) ) ;
if ( ! V_21 )
return - V_67 ;
V_25 = F_10 ( V_21 ) ;
V_25 -> V_68 = F_23 ( & V_2 -> V_63 , L_2 ) ;
if ( ! F_24 ( V_25 -> V_68 ) ) {
V_10 = F_25 ( V_25 -> V_68 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_26 ( V_25 -> V_68 ) ;
if ( V_10 < 0 )
goto V_69;
V_65 = V_10 ;
}
V_25 -> V_70 = F_23 ( & V_2 -> V_63 , L_3 ) ;
if ( ! F_24 ( V_25 -> V_70 ) ) {
V_10 = F_25 ( V_25 -> V_70 ) ;
if ( V_10 )
goto V_69;
V_10 = F_26 ( V_25 -> V_70 ) ;
if ( V_10 < 0 )
goto V_71;
V_66 = V_10 ;
}
V_25 -> V_30 = true ;
V_25 -> V_2 = V_2 ;
if ( ! F_24 ( V_25 -> V_70 ) && ! F_24 ( V_25 -> V_68 ) ) {
V_25 -> V_54 = ( V_65 + V_66 ) / 1000 ;
V_25 -> V_58 = V_66 / 1000 ;
} else if ( V_62 ) {
V_25 -> V_54 = V_62 -> V_72 + V_62 -> V_58 ;
V_25 -> V_58 = V_62 -> V_58 ;
} else {
F_27 ( & V_2 -> V_63 , L_4 ) ;
}
V_10 = F_1 ( V_2 , V_73 , V_74 ) ;
if ( V_10 )
goto V_71;
V_25 -> V_75 = & V_76 [ F_28 ( V_2 )
-> V_77 ] ;
V_25 -> V_31 = F_29 ( V_25 -> V_75 -> V_78 ( V_25 -> V_54 ) )
| ( ( V_62 && V_62 -> V_79 ) ? 0 : V_80 ) |
V_81 ;
V_10 = F_1 ( V_2 , V_36 , V_25 -> V_31 |
V_32 | V_33 ) ;
if ( V_10 )
goto V_71;
F_30 ( V_2 , V_21 ) ;
V_21 -> V_63 . V_82 = & V_2 -> V_63 ;
V_21 -> V_83 = & V_84 ;
V_21 -> V_85 = V_86 ;
V_21 -> V_87
= & V_88 [ F_28 ( V_2 ) -> V_77 ] ;
V_21 -> V_89 = 1 ;
V_21 -> V_90 = F_28 ( V_25 -> V_2 ) -> V_90 ;
V_10 = F_31 ( V_21 ) ;
if ( V_10 )
goto V_71;
return 0 ;
V_71:
if ( ! F_24 ( V_25 -> V_70 ) )
F_32 ( V_25 -> V_70 ) ;
V_69:
if ( ! F_24 ( V_25 -> V_68 ) )
F_32 ( V_25 -> V_68 ) ;
return V_10 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_34 ( V_2 ) ;
struct V_24 * V_25 = F_10 ( V_21 ) ;
F_35 ( V_21 ) ;
if ( ! F_24 ( V_25 -> V_68 ) )
F_32 ( V_25 -> V_68 ) ;
if ( ! F_24 ( V_25 -> V_70 ) )
F_32 ( V_25 -> V_70 ) ;
return 0 ;
}
