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
struct V_11 V_12 ;
struct V_13 V_14 [] = {
{
. V_15 = & V_7 [ 0 ] . V_6 [ 1 ] ,
. V_16 = 8 ,
. V_17 = 3 ,
. V_18 = 1 ,
} , {
. V_15 = & V_7 [ 1 ] . V_6 [ 1 ] ,
. V_19 = & V_7 [ 2 ] . V_6 [ 1 ] ,
. V_16 = 8 ,
. V_17 = 3 ,
} ,
} ;
V_7 [ 0 ] . V_5 = F_2 ( V_20 |
F_3 ( V_3 ) ) ;
V_7 [ 1 ] . V_5 = F_2 ( F_3 ( V_21 ) ) ;
F_6 ( & V_12 ) ;
F_7 ( & V_14 [ 0 ] , & V_12 ) ;
F_7 ( & V_14 [ 1 ] , & V_12 ) ;
V_10 = F_8 ( V_2 , & V_12 ) ;
* V_4 = F_9 ( V_7 [ 2 ] . V_5 ) ;
return V_10 ;
}
static T_3 F_10 ( struct V_22 * V_23 ,
struct V_24 * V_25 , char * V_26 )
{
struct V_27 * V_28 = F_11 ( V_23 ) ;
struct V_29 * V_30 = F_12 ( V_28 ) ;
const char V_31 [] [ 14 ] = { L_1 , L_2 } ;
return sprintf ( V_26 , L_3 , V_31 [ V_30 -> V_32 ] ) ;
}
static T_3 F_13 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
const char * V_26 , T_4 V_17 )
{
struct V_27 * V_28 = F_11 ( V_23 ) ;
struct V_29 * V_30 = F_12 ( V_28 ) ;
int V_10 ;
if ( F_14 ( V_26 , L_1 ) )
V_30 -> V_32 = V_33 ;
else if ( F_14 ( V_26 , L_2 ) )
V_30 -> V_32 = V_34 ;
else
V_10 = - V_35 ;
return V_10 ? V_10 : V_17 ;
}
static T_3 F_15 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
char * V_26 )
{
struct V_27 * V_28 = F_11 ( V_23 ) ;
struct V_29 * V_30 = F_12 ( V_28 ) ;
return sprintf ( V_26 , L_4 , V_30 -> V_36 ) ;
}
static T_3 F_16 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
const char * V_26 , T_4 V_17 )
{
long V_37 ;
int V_10 ;
struct V_27 * V_28 = F_11 ( V_23 ) ;
struct V_29 * V_30 = F_12 ( V_28 ) ;
V_10 = F_17 ( V_26 , 10 , & V_37 ) ;
if ( V_10 )
return V_10 ;
if ( V_37 == 0 ) {
V_30 -> V_36 = false ;
V_30 -> V_38 &= ~ ( V_39 | V_40 ) ;
} else if ( V_37 == 1 ) {
V_30 -> V_36 = true ;
if ( V_30 -> V_32 == V_33 )
V_30 -> V_38 |= V_39 ;
else if ( V_30 -> V_32 == V_34 )
V_30 -> V_38 |= V_40 ;
} else
V_10 = - V_35 ;
V_10 = F_1 ( V_30 -> V_2 , V_41 , V_30 -> V_38 ) ;
return V_10 ? V_10 : V_17 ;
}
static int F_18 ( unsigned int V_42 )
{
if ( V_42 <= 10000 )
return V_43 ;
else if ( V_42 <= 12000 )
return V_44 ;
else if ( V_42 <= 16000 )
return V_45 ;
else if ( V_42 <= 19000 )
return V_46 ;
else
return V_47 ;
}
static int F_19 ( unsigned int V_42 )
{
if ( V_42 <= 10000 )
return V_48 ;
else
return V_49 ;
}
static int F_20 ( struct V_27 * V_28 ,
struct V_50 const * V_51 ,
int * V_4 ,
int * V_52 ,
long V_53 )
{
struct V_29 * V_30 = F_12 ( V_28 ) ;
T_5 V_54 ;
int V_10 ;
switch ( V_53 ) {
case V_55 :
V_10 = F_5 ( V_30 -> V_2 , V_51 -> V_56 , V_4 ) ;
if ( V_10 )
return V_10 ;
* V_4 &= V_9 ;
* V_4 >>= V_51 -> V_57 . V_58 ;
return V_59 ;
case V_60 :
* V_4 = 0 ;
* V_52 = ( ( ( T_5 ) V_30 -> V_61 ) * 1000000ULL ) >> V_51 -> V_57 . V_62 ;
return V_63 ;
case V_64 :
V_54 = ( ( ( T_5 ) V_30 -> V_65 ) << V_51 -> V_57 . V_62 ) ;
F_21 ( V_54 , V_30 -> V_61 ) ;
* V_4 = - V_54 ;
return V_59 ;
default:
return - V_35 ;
}
}
static int F_22 ( struct V_27 * V_28 ,
struct V_50 const * V_51 ,
int V_4 ,
int V_52 ,
long V_66 )
{
struct V_29 * V_30 = F_12 ( V_28 ) ;
switch ( V_66 ) {
case V_55 :
V_4 &= F_23 ( V_51 -> V_57 . V_62 ) ;
V_4 <<= V_51 -> V_57 . V_58 ;
return F_1 ( V_30 -> V_2 , V_51 -> V_56 , V_4 ) ;
default:
return - V_35 ;
}
}
static int T_6 F_24 ( struct V_1 * V_2 )
{
struct V_67 * V_68 = V_2 -> V_23 . V_69 ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
int V_10 , V_70 = 0 , V_71 = 0 ;
V_28 = F_25 ( sizeof( * V_30 ) ) ;
if ( V_28 == NULL ) {
V_10 = - V_72 ;
goto V_73;
}
V_30 = F_12 ( V_28 ) ;
V_30 -> V_74 = F_26 ( & V_2 -> V_23 , L_5 ) ;
if ( ! F_27 ( V_30 -> V_74 ) ) {
V_10 = F_28 ( V_30 -> V_74 ) ;
if ( V_10 )
goto V_75;
V_70 = F_29 ( V_30 -> V_74 ) ;
}
V_30 -> V_76 = F_26 ( & V_2 -> V_23 , L_6 ) ;
if ( ! F_27 ( V_30 -> V_76 ) ) {
V_10 = F_28 ( V_30 -> V_76 ) ;
if ( V_10 )
goto V_77;
V_71 = F_29 ( V_30 -> V_76 ) ;
}
V_30 -> V_36 = true ;
V_30 -> V_2 = V_2 ;
if ( ! F_27 ( V_30 -> V_76 ) && ! F_27 ( V_30 -> V_74 ) ) {
V_30 -> V_61 = ( V_70 + V_71 ) / 1000 ;
V_30 -> V_65 = V_71 / 1000 ;
} else if ( V_68 ) {
V_30 -> V_61 = V_68 -> V_78 + V_68 -> V_65 ;
V_30 -> V_65 = V_68 -> V_65 ;
} else {
F_30 ( & V_2 -> V_23 , L_7 ) ;
}
V_10 = F_1 ( V_2 , V_79 , V_80 ) ;
if ( V_10 )
goto V_81;
V_30 -> V_82 = & V_83 [ F_31 ( V_2 )
-> V_84 ] ;
V_30 -> V_38 = F_32 ( V_30 -> V_82 -> V_85 ( V_30 -> V_61 ) )
| ( ( V_68 && V_68 -> V_86 ) ? 0 : V_87 ) |
V_88 ;
V_10 = F_1 ( V_2 , V_41 , V_30 -> V_38 |
V_39 | V_40 ) ;
if ( V_10 )
goto V_81;
F_33 ( V_2 , V_28 ) ;
V_28 -> V_23 . V_89 = & V_2 -> V_23 ;
V_28 -> V_90 = & V_91 ;
V_28 -> V_92 = V_93 ;
V_28 -> V_94
= & V_95 [ F_31 ( V_2 ) -> V_84 ] ;
V_28 -> V_96 = 1 ;
V_28 -> V_97 = F_31 ( V_30 -> V_2 ) -> V_97 ;
V_10 = F_34 ( V_28 ) ;
if ( V_10 )
goto V_81;
return 0 ;
V_81:
if ( ! F_27 ( V_30 -> V_76 ) )
F_35 ( V_30 -> V_76 ) ;
V_77:
if ( ! F_27 ( V_30 -> V_76 ) )
F_36 ( V_30 -> V_76 ) ;
if ( ! F_27 ( V_30 -> V_74 ) )
F_35 ( V_30 -> V_74 ) ;
V_75:
if ( ! F_27 ( V_30 -> V_74 ) )
F_36 ( V_30 -> V_74 ) ;
F_37 ( V_28 ) ;
V_73:
return V_10 ;
}
static int T_7 F_38 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = F_39 ( V_2 ) ;
struct V_29 * V_30 = F_12 ( V_28 ) ;
F_40 ( V_28 ) ;
if ( ! F_27 ( V_30 -> V_74 ) ) {
F_35 ( V_30 -> V_74 ) ;
F_36 ( V_30 -> V_74 ) ;
}
if ( ! F_27 ( V_30 -> V_76 ) ) {
F_35 ( V_30 -> V_76 ) ;
F_36 ( V_30 -> V_76 ) ;
}
F_37 ( V_28 ) ;
return 0 ;
}
