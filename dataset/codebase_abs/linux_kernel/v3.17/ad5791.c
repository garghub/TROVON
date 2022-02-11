static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
V_2 -> V_5 [ 0 ] . V_6 = F_2 ( V_7 |
F_3 ( V_3 ) |
( V_4 & V_8 ) ) ;
return F_4 ( V_2 -> V_9 , & V_2 -> V_5 [ 0 ] . V_10 [ 1 ] , 3 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
int V_11 ;
struct V_12 V_13 [] = {
{
. V_14 = & V_2 -> V_5 [ 0 ] . V_10 [ 1 ] ,
. V_15 = 8 ,
. V_16 = 3 ,
. V_17 = 1 ,
} , {
. V_14 = & V_2 -> V_5 [ 1 ] . V_10 [ 1 ] ,
. V_18 = & V_2 -> V_5 [ 2 ] . V_10 [ 1 ] ,
. V_15 = 8 ,
. V_16 = 3 ,
} ,
} ;
V_2 -> V_5 [ 0 ] . V_6 = F_2 ( V_19 |
F_3 ( V_3 ) ) ;
V_2 -> V_5 [ 1 ] . V_6 = F_2 ( F_3 ( V_20 ) ) ;
V_11 = F_6 ( V_2 -> V_9 , V_13 , F_7 ( V_13 ) ) ;
* V_4 = F_8 ( V_2 -> V_5 [ 2 ] . V_6 ) ;
return V_11 ;
}
static int F_9 ( struct V_21 * V_22 ,
const struct V_23 * V_24 )
{
struct V_1 * V_2 = F_10 ( V_22 ) ;
return V_2 -> V_25 ;
}
static int F_11 ( struct V_21 * V_22 ,
const struct V_23 * V_24 , unsigned int V_26 )
{
struct V_1 * V_2 = F_10 ( V_22 ) ;
V_2 -> V_25 = V_26 ;
return 0 ;
}
static T_3 F_12 ( struct V_21 * V_22 ,
T_4 V_27 , const struct V_23 * V_24 , char * V_28 )
{
struct V_1 * V_2 = F_10 ( V_22 ) ;
return sprintf ( V_28 , L_1 , V_2 -> V_29 ) ;
}
static T_3 F_13 ( struct V_21 * V_22 ,
T_4 V_27 , const struct V_23 * V_24 , const char * V_28 ,
T_5 V_16 )
{
bool V_29 ;
int V_11 ;
struct V_1 * V_2 = F_10 ( V_22 ) ;
V_11 = F_14 ( V_28 , & V_29 ) ;
if ( V_11 )
return V_11 ;
if ( ! V_29 ) {
V_2 -> V_30 &= ~ ( V_31 | V_32 ) ;
} else {
if ( V_2 -> V_25 == V_33 )
V_2 -> V_30 |= V_31 ;
else if ( V_2 -> V_25 == V_34 )
V_2 -> V_30 |= V_32 ;
}
V_2 -> V_29 = V_29 ;
V_11 = F_1 ( V_2 , V_35 , V_2 -> V_30 ) ;
return V_11 ? V_11 : V_16 ;
}
static int F_15 ( unsigned int V_36 )
{
if ( V_36 <= 10000 )
return V_37 ;
else if ( V_36 <= 12000 )
return V_38 ;
else if ( V_36 <= 16000 )
return V_39 ;
else if ( V_36 <= 19000 )
return V_40 ;
else
return V_41 ;
}
static int F_16 ( unsigned int V_36 )
{
if ( V_36 <= 10000 )
return V_42 ;
else
return V_43 ;
}
static int F_17 ( struct V_21 * V_22 ,
struct V_23 const * V_24 ,
int * V_4 ,
int * V_44 ,
long V_45 )
{
struct V_1 * V_2 = F_10 ( V_22 ) ;
T_6 V_46 ;
int V_11 ;
switch ( V_45 ) {
case V_47 :
V_11 = F_5 ( V_2 , V_24 -> V_48 , V_4 ) ;
if ( V_11 )
return V_11 ;
* V_4 &= V_8 ;
* V_4 >>= V_24 -> V_49 . V_50 ;
return V_51 ;
case V_52 :
* V_4 = V_2 -> V_53 ;
* V_44 = ( 1 << V_24 -> V_49 . V_54 ) - 1 ;
return V_55 ;
case V_56 :
V_46 = ( ( ( T_6 ) V_2 -> V_57 ) << V_24 -> V_49 . V_54 ) ;
F_18 ( V_46 , V_2 -> V_53 ) ;
* V_4 = - V_46 ;
return V_51 ;
default:
return - V_58 ;
}
}
static int F_19 ( struct V_21 * V_22 ,
struct V_23 const * V_24 ,
int V_4 ,
int V_44 ,
long V_59 )
{
struct V_1 * V_2 = F_10 ( V_22 ) ;
switch ( V_59 ) {
case V_47 :
V_4 &= F_20 ( V_24 -> V_49 . V_54 - 1 , 0 ) ;
V_4 <<= V_24 -> V_49 . V_50 ;
return F_1 ( V_2 , V_24 -> V_48 , V_4 ) ;
default:
return - V_58 ;
}
}
static int F_21 ( struct V_60 * V_9 )
{
struct V_61 * V_62 = V_9 -> V_63 . V_64 ;
struct V_21 * V_22 ;
struct V_1 * V_2 ;
int V_11 , V_65 = 0 , V_66 = 0 ;
V_22 = F_22 ( & V_9 -> V_63 , sizeof( * V_2 ) ) ;
if ( ! V_22 )
return - V_67 ;
V_2 = F_10 ( V_22 ) ;
V_2 -> V_68 = F_23 ( & V_9 -> V_63 , L_2 ) ;
if ( ! F_24 ( V_2 -> V_68 ) ) {
V_11 = F_25 ( V_2 -> V_68 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_26 ( V_2 -> V_68 ) ;
if ( V_11 < 0 )
goto V_69;
V_65 = V_11 ;
}
V_2 -> V_70 = F_23 ( & V_9 -> V_63 , L_3 ) ;
if ( ! F_24 ( V_2 -> V_70 ) ) {
V_11 = F_25 ( V_2 -> V_70 ) ;
if ( V_11 )
goto V_69;
V_11 = F_26 ( V_2 -> V_70 ) ;
if ( V_11 < 0 )
goto V_71;
V_66 = V_11 ;
}
V_2 -> V_29 = true ;
V_2 -> V_9 = V_9 ;
if ( ! F_24 ( V_2 -> V_70 ) && ! F_24 ( V_2 -> V_68 ) ) {
V_2 -> V_53 = ( V_65 + V_66 ) / 1000 ;
V_2 -> V_57 = V_66 / 1000 ;
} else if ( V_62 ) {
V_2 -> V_53 = V_62 -> V_72 + V_62 -> V_57 ;
V_2 -> V_57 = V_62 -> V_57 ;
} else {
F_27 ( & V_9 -> V_63 , L_4 ) ;
}
V_11 = F_1 ( V_2 , V_73 , V_74 ) ;
if ( V_11 )
goto V_71;
V_2 -> V_75 = & V_76 [ F_28 ( V_9 )
-> V_77 ] ;
V_2 -> V_30 = F_29 ( V_2 -> V_75 -> V_78 ( V_2 -> V_53 ) )
| ( ( V_62 && V_62 -> V_79 ) ? 0 : V_80 ) |
V_81 ;
V_11 = F_1 ( V_2 , V_35 , V_2 -> V_30 |
V_31 | V_32 ) ;
if ( V_11 )
goto V_71;
F_30 ( V_9 , V_22 ) ;
V_22 -> V_63 . V_82 = & V_9 -> V_63 ;
V_22 -> V_83 = & V_84 ;
V_22 -> V_85 = V_86 ;
V_22 -> V_87
= & V_88 [ F_28 ( V_9 ) -> V_77 ] ;
V_22 -> V_89 = 1 ;
V_22 -> V_90 = F_28 ( V_2 -> V_9 ) -> V_90 ;
V_11 = F_31 ( V_22 ) ;
if ( V_11 )
goto V_71;
return 0 ;
V_71:
if ( ! F_24 ( V_2 -> V_70 ) )
F_32 ( V_2 -> V_70 ) ;
V_69:
if ( ! F_24 ( V_2 -> V_68 ) )
F_32 ( V_2 -> V_68 ) ;
return V_11 ;
}
static int F_33 ( struct V_60 * V_9 )
{
struct V_21 * V_22 = F_34 ( V_9 ) ;
struct V_1 * V_2 = F_10 ( V_22 ) ;
F_35 ( V_22 ) ;
if ( ! F_24 ( V_2 -> V_68 ) )
F_32 ( V_2 -> V_68 ) ;
if ( ! F_24 ( V_2 -> V_70 ) )
F_32 ( V_2 -> V_70 ) ;
return 0 ;
}
