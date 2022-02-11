static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 )
{
F_2 ( V_2 , V_5 , V_6 | V_3 ) ;
return F_2 ( V_2 , V_7 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
T_1 V_3 )
{
F_2 ( V_2 , V_5 , V_3 ) ;
return F_4 ( V_2 , V_8 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_9 ;
V_9 = F_4 ( V_2 , V_10 ) ;
return ( V_9 < 0 ) ? V_9 : 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
const struct V_11 * type = V_2 -> V_12 -> V_13 ;
int V_14 ;
T_2 V_15 ;
if ( type && type -> V_16 )
V_15 = type -> V_16 ;
else
V_15 = V_17 ;
V_14 = F_4 ( V_2 , V_18 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 &= ~ V_15 ;
F_2 ( V_2 , V_18 , V_14 ) ;
if ( V_2 -> V_19 == V_20 )
V_14 = V_21 ;
else
V_14 = 0 ;
return F_2 ( V_2 , V_10 , V_14 ) ;
}
static int F_7 ( struct V_1 * V_2 , bool V_4 )
{
int V_22 ;
V_22 = F_4 ( V_2 , V_18 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( V_4 )
V_22 |= V_23 ;
else
V_22 &= ~ V_23 ;
return F_2 ( V_2 , V_18 , V_22 ) ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_24 , int V_4 )
{
int V_9 , V_14 , V_25 ;
switch ( V_24 ) {
case V_26 :
V_25 = 14 ;
break;
case V_27 :
V_25 = 4 ;
break;
default:
return - V_28 ;
}
V_14 = F_4 ( V_2 , V_24 ) ;
if ( V_14 < 0 ) {
V_9 = V_14 ;
goto V_29;
}
V_14 &= ~ ( 3 << V_25 ) ;
V_14 |= V_4 << V_25 ;
V_9 = F_2 ( V_2 , V_24 , V_14 ) ;
V_29:
if ( V_9 < 0 )
F_9 ( & V_2 -> V_30 , L_1 ) ;
return V_9 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_31 ;
V_31 = F_4 ( V_2 , V_32 ) ;
if ( V_31 < 0 )
goto V_29;
V_31 = F_2 ( V_2 , V_32 , V_31 | V_33 ) ;
V_29:
if ( V_31 )
F_9 ( & V_2 -> V_30 , L_2 ) ;
return V_31 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_35 ;
const struct V_11 * type ;
int V_31 ;
if ( ! V_35 )
return 0 ;
type = V_35 -> type ;
if ( type -> V_36 )
F_10 ( V_2 ) ;
if ( V_35 -> V_37 ) {
V_31 = F_7 ( V_2 , V_35 -> V_38 ) ;
if ( V_31 ) {
F_9 ( & V_2 -> V_30 , L_3 ) ;
return V_31 ;
}
}
if ( V_35 -> V_39 >= 0 )
F_8 ( V_2 , type -> V_40 , V_35 -> V_39 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_41 * V_42 , T_2 V_24 ,
char * V_43 , char * V_44 ,
char * V_45 , char * V_46 )
{
int V_47 = - 1 ;
int V_48 = - 2 ;
int V_49 = - 3 ;
int V_50 = - 4 ;
int V_51 ;
int V_52 = 0 ;
if ( ! F_13 ( V_42 , V_43 , & V_47 ) )
V_52 ++ ;
if ( ! F_13 ( V_42 , V_44 , & V_48 ) )
V_52 ++ ;
if ( ! F_13 ( V_42 , V_45 , & V_49 ) )
V_52 ++ ;
if ( ! F_13 ( V_42 , V_46 , & V_50 ) )
V_52 ++ ;
if ( ! V_52 )
return 0 ;
if ( V_52 < 4 )
V_51 = F_3 ( V_2 , V_24 ) ;
else
V_51 = 0 ;
if ( V_47 != - 1 )
V_51 = ( ( V_51 & 0xfff0 ) | ( ( V_47 / V_53 ) & 0xf ) << 0 ) ;
if ( V_48 != - 2 )
V_51 = ( ( V_51 & 0xff0f ) | ( ( V_48 / V_53 ) & 0xf ) << 4 ) ;
if ( V_49 != - 3 )
V_51 = ( ( V_51 & 0xf0ff ) | ( ( V_49 / V_53 ) & 0xf ) << 8 ) ;
if ( V_50 != - 4 )
V_51 = ( ( V_51 & 0x0fff ) | ( ( V_50 / V_53 ) & 0xf ) << 12 ) ;
return F_1 ( V_2 , V_24 , V_51 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_54 * V_30 = & V_2 -> V_30 ;
struct V_41 * V_42 = V_30 -> V_42 ;
if ( ! V_42 && V_30 -> V_55 -> V_42 )
V_42 = V_30 -> V_55 -> V_42 ;
if ( V_42 ) {
F_12 ( V_2 , V_42 ,
V_56 ,
L_4 , L_5 ,
L_6 , L_7 ) ;
F_12 ( V_2 , V_42 ,
V_57 ,
L_8 , L_9 ,
L_10 , L_11 ) ;
F_12 ( V_2 , V_42 ,
V_58 ,
L_12 , L_13 ,
L_14 , L_15 ) ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
T_3 V_59 , T_1 V_60 , T_1 V_3 , T_2 V_4 )
{
F_2 ( V_2 , V_61 , V_60 ) ;
F_2 ( V_2 , V_62 , V_3 ) ;
F_2 ( V_2 , V_61 , ( V_59 << 14 ) | V_60 ) ;
return F_2 ( V_2 , V_62 , V_4 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
T_3 V_59 , T_1 V_60 , T_1 V_3 )
{
F_2 ( V_2 , V_61 , V_60 ) ;
F_2 ( V_2 , V_62 , V_3 ) ;
F_2 ( V_2 , V_61 , ( V_59 << 14 ) | V_60 ) ;
return F_4 ( V_2 , V_62 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_41 * V_42 ,
T_2 V_24 , T_4 V_63 ,
char * V_64 [] , T_3 V_65 )
{
int V_4 [ 4 ] = { - 1 , - 2 , - 3 , - 4 } ;
int V_52 = 0 ;
T_2 V_15 ;
T_2 V_66 ;
T_2 V_51 ;
int V_67 ;
for ( V_67 = 0 ; V_67 < V_65 ; V_67 ++ )
if ( ! F_13 ( V_42 , V_64 [ V_67 ] , V_4 + V_67 ) )
V_52 ++ ;
if ( ! V_52 )
return 0 ;
if ( V_52 < V_65 )
V_51 = F_16 ( V_2 , V_68 , 2 , V_24 ) ;
else
V_51 = 0 ;
V_66 = ( V_63 == 4 ) ? 0xf : 0x1f ;
for ( V_67 = 0 ; V_67 < V_65 ; V_67 ++ )
if ( V_4 [ V_67 ] != - ( V_67 + 1 ) ) {
V_15 = 0xffff ;
V_15 ^= V_66 << ( V_63 * V_67 ) ;
V_51 = ( V_51 & V_15 ) |
( ( ( V_4 [ V_67 ] / V_69 ) & V_66 )
<< ( V_63 * V_67 ) ) ;
}
return F_15 ( V_2 , V_68 , 2 , V_24 , V_51 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_54 * V_30 = & V_2 -> V_30 ;
struct V_41 * V_42 = V_30 -> V_42 ;
char * V_70 [ 2 ] = { L_7 , L_5 } ;
char * V_71 [ 4 ] = {
L_8 , L_9 ,
L_10 , L_11
} ;
char * V_72 [ 4 ] = {
L_12 , L_13 ,
L_14 , L_15
} ;
char * V_73 [ 2 ] = { L_4 , L_6 } ;
if ( ! V_42 && V_30 -> V_55 -> V_42 )
V_42 = V_30 -> V_55 -> V_42 ;
if ( V_42 ) {
F_17 ( V_2 , V_42 ,
V_74 , 5 ,
V_70 , 2 ) ;
F_17 ( V_2 , V_42 ,
V_75 , 4 ,
V_73 , 2 ) ;
F_17 ( V_2 , V_42 ,
V_76 , 4 ,
V_71 , 4 ) ;
F_17 ( V_2 , V_42 ,
V_77 , 4 ,
V_72 , 4 ) ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_78 ;
V_78 = F_4 ( V_2 , V_79 ) ;
V_78 = F_4 ( V_2 , V_79 ) ;
if ( V_78 & V_80 )
V_2 -> V_81 = V_82 ;
else
V_2 -> V_81 = V_83 ;
if ( V_78 & V_84 )
V_2 -> V_85 = V_86 ;
else
V_2 -> V_85 = V_87 ;
V_2 -> V_88 = 1 ;
V_2 -> V_89 = V_2 -> V_90 = 0 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
return 0 ;
}
static int
F_21 ( struct V_1 * V_2 , int V_91 , int V_92 ,
int V_3 )
{
return - 1 ;
}
static void
F_22 ( struct V_1 * V_2 , int V_91 , int V_92 ,
int V_3 , T_1 V_4 )
{
}
static int F_23 ( struct V_1 * V_2 )
{
const struct V_11 * type = V_2 -> V_12 -> V_13 ;
struct V_41 * V_93 = V_2 -> V_30 . V_42 ;
struct V_34 * V_35 ;
struct V_94 * V_94 ;
int V_31 ;
V_35 = F_24 ( & V_2 -> V_30 , sizeof( * V_35 ) , V_95 ) ;
if ( ! V_35 )
return - V_96 ;
V_2 -> V_35 = V_35 ;
V_35 -> type = type ;
if ( type -> V_40 ) {
V_31 = F_13 ( V_93 , L_16 ,
& V_35 -> V_39 ) ;
if ( V_31 )
V_35 -> V_39 = - 1 ;
if ( V_35 -> V_39 > 3 ) {
F_9 ( & V_2 -> V_30 , L_17 ,
V_35 -> V_39 ) ;
V_35 -> V_39 = - 1 ;
}
} else {
V_35 -> V_39 = - 1 ;
}
V_94 = F_25 ( & V_2 -> V_30 , L_18 ) ;
if ( ! F_26 ( V_94 ) ) {
unsigned long V_97 = F_27 ( V_94 ) ;
bool V_98 ;
V_35 -> V_37 = type -> V_99 ;
V_98 = F_28 ( V_93 ,
L_19 ) ;
if ( V_97 > 24500000 && V_97 < 25500000 ) {
V_35 -> V_38 = V_98 ;
} else if ( V_97 > 49500000 && V_97 < 50500000 ) {
V_35 -> V_38 = ! V_98 ;
} else {
F_9 ( & V_2 -> V_30 , L_20 , V_97 ) ;
return - V_28 ;
}
}
if ( V_2 -> V_100 & V_101 ) {
V_35 -> V_37 = true ;
V_35 -> V_38 = true ;
}
return 0 ;
}
