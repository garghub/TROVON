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
static int F_10 ( struct V_22 * V_23 ,
const struct V_24 * V_25 )
{
struct V_26 * V_27 = F_11 ( V_23 ) ;
return V_27 -> V_28 ;
}
static int F_12 ( struct V_22 * V_23 ,
const struct V_24 * V_25 , unsigned int V_29 )
{
struct V_26 * V_27 = F_11 ( V_23 ) ;
V_27 -> V_28 = V_29 ;
return 0 ;
}
static T_3 F_13 ( struct V_22 * V_23 ,
T_4 V_30 , const struct V_24 * V_25 , char * V_31 )
{
struct V_26 * V_27 = F_11 ( V_23 ) ;
return sprintf ( V_31 , L_1 , V_27 -> V_32 ) ;
}
static T_3 F_14 ( struct V_22 * V_23 ,
T_4 V_30 , const struct V_24 * V_25 , const char * V_31 ,
T_5 V_17 )
{
bool V_32 ;
int V_10 ;
struct V_26 * V_27 = F_11 ( V_23 ) ;
V_10 = F_15 ( V_31 , & V_32 ) ;
if ( V_10 )
return V_10 ;
if ( ! V_32 ) {
V_27 -> V_33 &= ~ ( V_34 | V_35 ) ;
} else {
if ( V_27 -> V_28 == V_36 )
V_27 -> V_33 |= V_34 ;
else if ( V_27 -> V_28 == V_37 )
V_27 -> V_33 |= V_35 ;
}
V_27 -> V_32 = V_32 ;
V_10 = F_1 ( V_27 -> V_2 , V_38 , V_27 -> V_33 ) ;
return V_10 ? V_10 : V_17 ;
}
static int F_16 ( unsigned int V_39 )
{
if ( V_39 <= 10000 )
return V_40 ;
else if ( V_39 <= 12000 )
return V_41 ;
else if ( V_39 <= 16000 )
return V_42 ;
else if ( V_39 <= 19000 )
return V_43 ;
else
return V_44 ;
}
static int F_17 ( unsigned int V_39 )
{
if ( V_39 <= 10000 )
return V_45 ;
else
return V_46 ;
}
static int F_18 ( struct V_22 * V_23 ,
struct V_24 const * V_25 ,
int * V_4 ,
int * V_47 ,
long V_48 )
{
struct V_26 * V_27 = F_11 ( V_23 ) ;
T_6 V_49 ;
int V_10 ;
switch ( V_48 ) {
case V_50 :
V_10 = F_5 ( V_27 -> V_2 , V_25 -> V_51 , V_4 ) ;
if ( V_10 )
return V_10 ;
* V_4 &= V_9 ;
* V_4 >>= V_25 -> V_52 . V_53 ;
return V_54 ;
case V_55 :
* V_4 = 0 ;
* V_47 = ( ( ( T_6 ) V_27 -> V_56 ) * 1000000ULL ) >> V_25 -> V_52 . V_57 ;
return V_58 ;
case V_59 :
V_49 = ( ( ( T_6 ) V_27 -> V_60 ) << V_25 -> V_52 . V_57 ) ;
F_19 ( V_49 , V_27 -> V_56 ) ;
* V_4 = - V_49 ;
return V_54 ;
default:
return - V_61 ;
}
}
static int F_20 ( struct V_22 * V_23 ,
struct V_24 const * V_25 ,
int V_4 ,
int V_47 ,
long V_62 )
{
struct V_26 * V_27 = F_11 ( V_23 ) ;
switch ( V_62 ) {
case V_50 :
V_4 &= F_21 ( V_25 -> V_52 . V_57 ) ;
V_4 <<= V_25 -> V_52 . V_53 ;
return F_1 ( V_27 -> V_2 , V_25 -> V_51 , V_4 ) ;
default:
return - V_61 ;
}
}
static int T_7 F_22 ( struct V_1 * V_2 )
{
struct V_63 * V_64 = V_2 -> V_65 . V_66 ;
struct V_22 * V_23 ;
struct V_26 * V_27 ;
int V_10 , V_67 = 0 , V_68 = 0 ;
V_23 = F_23 ( sizeof( * V_27 ) ) ;
if ( V_23 == NULL ) {
V_10 = - V_69 ;
goto V_70;
}
V_27 = F_11 ( V_23 ) ;
V_27 -> V_71 = F_24 ( & V_2 -> V_65 , L_2 ) ;
if ( ! F_25 ( V_27 -> V_71 ) ) {
V_10 = F_26 ( V_27 -> V_71 ) ;
if ( V_10 )
goto V_72;
V_67 = F_27 ( V_27 -> V_71 ) ;
}
V_27 -> V_73 = F_24 ( & V_2 -> V_65 , L_3 ) ;
if ( ! F_25 ( V_27 -> V_73 ) ) {
V_10 = F_26 ( V_27 -> V_73 ) ;
if ( V_10 )
goto V_74;
V_68 = F_27 ( V_27 -> V_73 ) ;
}
V_27 -> V_32 = true ;
V_27 -> V_2 = V_2 ;
if ( ! F_25 ( V_27 -> V_73 ) && ! F_25 ( V_27 -> V_71 ) ) {
V_27 -> V_56 = ( V_67 + V_68 ) / 1000 ;
V_27 -> V_60 = V_68 / 1000 ;
} else if ( V_64 ) {
V_27 -> V_56 = V_64 -> V_75 + V_64 -> V_60 ;
V_27 -> V_60 = V_64 -> V_60 ;
} else {
F_28 ( & V_2 -> V_65 , L_4 ) ;
}
V_10 = F_1 ( V_2 , V_76 , V_77 ) ;
if ( V_10 )
goto V_78;
V_27 -> V_79 = & V_80 [ F_29 ( V_2 )
-> V_81 ] ;
V_27 -> V_33 = F_30 ( V_27 -> V_79 -> V_82 ( V_27 -> V_56 ) )
| ( ( V_64 && V_64 -> V_83 ) ? 0 : V_84 ) |
V_85 ;
V_10 = F_1 ( V_2 , V_38 , V_27 -> V_33 |
V_34 | V_35 ) ;
if ( V_10 )
goto V_78;
F_31 ( V_2 , V_23 ) ;
V_23 -> V_65 . V_86 = & V_2 -> V_65 ;
V_23 -> V_87 = & V_88 ;
V_23 -> V_89 = V_90 ;
V_23 -> V_91
= & V_92 [ F_29 ( V_2 ) -> V_81 ] ;
V_23 -> V_93 = 1 ;
V_23 -> V_94 = F_29 ( V_27 -> V_2 ) -> V_94 ;
V_10 = F_32 ( V_23 ) ;
if ( V_10 )
goto V_78;
return 0 ;
V_78:
if ( ! F_25 ( V_27 -> V_73 ) )
F_33 ( V_27 -> V_73 ) ;
V_74:
if ( ! F_25 ( V_27 -> V_73 ) )
F_34 ( V_27 -> V_73 ) ;
if ( ! F_25 ( V_27 -> V_71 ) )
F_33 ( V_27 -> V_71 ) ;
V_72:
if ( ! F_25 ( V_27 -> V_71 ) )
F_34 ( V_27 -> V_71 ) ;
F_35 ( V_23 ) ;
V_70:
return V_10 ;
}
static int T_8 F_36 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_37 ( V_2 ) ;
struct V_26 * V_27 = F_11 ( V_23 ) ;
F_38 ( V_23 ) ;
if ( ! F_25 ( V_27 -> V_71 ) ) {
F_33 ( V_27 -> V_71 ) ;
F_34 ( V_27 -> V_71 ) ;
}
if ( ! F_25 ( V_27 -> V_73 ) ) {
F_33 ( V_27 -> V_73 ) ;
F_34 ( V_27 -> V_73 ) ;
}
F_35 ( V_23 ) ;
return 0 ;
}
