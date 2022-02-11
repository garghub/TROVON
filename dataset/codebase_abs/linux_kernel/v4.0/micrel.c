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
int V_31 ;
V_31 = F_4 ( V_2 , V_32 ) ;
if ( V_31 < 0 )
goto V_29;
if ( ! ( V_31 & V_34 ) )
return 0 ;
V_31 = F_2 ( V_2 , V_32 ,
V_31 & ~ V_34 ) ;
V_29:
if ( V_31 )
F_9 ( & V_2 -> V_30 , L_3 ) ;
return V_31 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = V_2 -> V_36 ;
const struct V_11 * type ;
int V_31 ;
if ( ! V_36 )
return 0 ;
type = V_36 -> type ;
if ( type -> V_37 )
F_10 ( V_2 ) ;
if ( type -> V_38 )
F_11 ( V_2 ) ;
if ( V_36 -> V_39 ) {
V_31 = F_7 ( V_2 , V_36 -> V_40 ) ;
if ( V_31 ) {
F_9 ( & V_2 -> V_30 , L_4 ) ;
return V_31 ;
}
}
if ( V_36 -> V_41 >= 0 )
F_8 ( V_2 , type -> V_42 , V_36 -> V_41 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_43 * V_44 , T_2 V_24 ,
char * V_45 , char * V_46 ,
char * V_47 , char * V_48 )
{
int V_49 = - 1 ;
int V_50 = - 2 ;
int V_51 = - 3 ;
int V_52 = - 4 ;
int V_53 ;
int V_54 = 0 ;
if ( ! F_14 ( V_44 , V_45 , & V_49 ) )
V_54 ++ ;
if ( ! F_14 ( V_44 , V_46 , & V_50 ) )
V_54 ++ ;
if ( ! F_14 ( V_44 , V_47 , & V_51 ) )
V_54 ++ ;
if ( ! F_14 ( V_44 , V_48 , & V_52 ) )
V_54 ++ ;
if ( ! V_54 )
return 0 ;
if ( V_54 < 4 )
V_53 = F_3 ( V_2 , V_24 ) ;
else
V_53 = 0 ;
if ( V_49 != - 1 )
V_53 = ( ( V_53 & 0xfff0 ) | ( ( V_49 / V_55 ) & 0xf ) << 0 ) ;
if ( V_50 != - 2 )
V_53 = ( ( V_53 & 0xff0f ) | ( ( V_50 / V_55 ) & 0xf ) << 4 ) ;
if ( V_51 != - 3 )
V_53 = ( ( V_53 & 0xf0ff ) | ( ( V_51 / V_55 ) & 0xf ) << 8 ) ;
if ( V_52 != - 4 )
V_53 = ( ( V_53 & 0x0fff ) | ( ( V_52 / V_55 ) & 0xf ) << 12 ) ;
return F_1 ( V_2 , V_24 , V_53 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_56 * V_30 = & V_2 -> V_30 ;
struct V_43 * V_44 = V_30 -> V_44 ;
if ( ! V_44 && V_30 -> V_57 -> V_44 )
V_44 = V_30 -> V_57 -> V_44 ;
if ( V_44 ) {
F_13 ( V_2 , V_44 ,
V_58 ,
L_5 , L_6 ,
L_7 , L_8 ) ;
F_13 ( V_2 , V_44 ,
V_59 ,
L_9 , L_10 ,
L_11 , L_12 ) ;
F_13 ( V_2 , V_44 ,
V_60 ,
L_13 , L_14 ,
L_15 , L_16 ) ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
T_3 V_61 , T_1 V_62 , T_1 V_3 , T_2 V_4 )
{
F_2 ( V_2 , V_63 , V_62 ) ;
F_2 ( V_2 , V_64 , V_3 ) ;
F_2 ( V_2 , V_63 , ( V_61 << 14 ) | V_62 ) ;
return F_2 ( V_2 , V_64 , V_4 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
T_3 V_61 , T_1 V_62 , T_1 V_3 )
{
F_2 ( V_2 , V_63 , V_62 ) ;
F_2 ( V_2 , V_64 , V_3 ) ;
F_2 ( V_2 , V_63 , ( V_61 << 14 ) | V_62 ) ;
return F_4 ( V_2 , V_64 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
T_2 V_24 , T_4 V_65 ,
char * V_66 [] , T_3 V_67 )
{
int V_4 [ 4 ] = { - 1 , - 2 , - 3 , - 4 } ;
int V_54 = 0 ;
T_2 V_15 ;
T_2 V_68 ;
T_2 V_53 ;
int V_69 ;
for ( V_69 = 0 ; V_69 < V_67 ; V_69 ++ )
if ( ! F_14 ( V_44 , V_66 [ V_69 ] , V_4 + V_69 ) )
V_54 ++ ;
if ( ! V_54 )
return 0 ;
if ( V_54 < V_67 )
V_53 = F_17 ( V_2 , V_70 , 2 , V_24 ) ;
else
V_53 = 0 ;
V_68 = ( V_65 == 4 ) ? 0xf : 0x1f ;
for ( V_69 = 0 ; V_69 < V_67 ; V_69 ++ )
if ( V_4 [ V_69 ] != - ( V_69 + 1 ) ) {
V_15 = 0xffff ;
V_15 ^= V_68 << ( V_65 * V_69 ) ;
V_53 = ( V_53 & V_15 ) |
( ( ( V_4 [ V_69 ] / V_71 ) & V_68 )
<< ( V_65 * V_69 ) ) ;
}
return F_16 ( V_2 , V_70 , 2 , V_24 , V_53 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_56 * V_30 = & V_2 -> V_30 ;
struct V_43 * V_44 = V_30 -> V_44 ;
char * V_72 [ 2 ] = { L_8 , L_6 } ;
char * V_73 [ 4 ] = {
L_9 , L_10 ,
L_11 , L_12
} ;
char * V_74 [ 4 ] = {
L_13 , L_14 ,
L_15 , L_16
} ;
char * V_75 [ 2 ] = { L_5 , L_7 } ;
if ( ! V_44 && V_30 -> V_57 -> V_44 )
V_44 = V_30 -> V_57 -> V_44 ;
if ( V_44 ) {
F_18 ( V_2 , V_44 ,
V_76 , 5 ,
V_72 , 2 ) ;
F_18 ( V_2 , V_44 ,
V_77 , 4 ,
V_75 , 2 ) ;
F_18 ( V_2 , V_44 ,
V_78 , 4 ,
V_73 , 4 ) ;
F_18 ( V_2 , V_44 ,
V_79 , 4 ,
V_74 , 4 ) ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_80 ;
V_80 = F_4 ( V_2 , V_81 ) ;
V_80 = F_4 ( V_2 , V_81 ) ;
if ( V_80 & V_82 )
V_2 -> V_83 = V_84 ;
else
V_2 -> V_83 = V_85 ;
if ( V_80 & V_86 )
V_2 -> V_87 = V_88 ;
else
V_2 -> V_87 = V_89 ;
V_2 -> V_90 = 1 ;
V_2 -> V_91 = V_2 -> V_92 = 0 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
return 0 ;
}
static int
F_22 ( struct V_1 * V_2 , int V_93 , int V_94 ,
int V_3 )
{
return - 1 ;
}
static void
F_23 ( struct V_1 * V_2 , int V_93 , int V_94 ,
int V_3 , T_1 V_4 )
{
}
static int F_24 ( struct V_1 * V_2 )
{
const struct V_11 * type = V_2 -> V_12 -> V_13 ;
struct V_43 * V_95 = V_2 -> V_30 . V_44 ;
struct V_35 * V_36 ;
struct V_96 * V_96 ;
int V_31 ;
V_36 = F_25 ( & V_2 -> V_30 , sizeof( * V_36 ) , V_97 ) ;
if ( ! V_36 )
return - V_98 ;
V_2 -> V_36 = V_36 ;
V_36 -> type = type ;
if ( type -> V_42 ) {
V_31 = F_14 ( V_95 , L_17 ,
& V_36 -> V_41 ) ;
if ( V_31 )
V_36 -> V_41 = - 1 ;
if ( V_36 -> V_41 > 3 ) {
F_9 ( & V_2 -> V_30 , L_18 ,
V_36 -> V_41 ) ;
V_36 -> V_41 = - 1 ;
}
} else {
V_36 -> V_41 = - 1 ;
}
V_96 = F_26 ( & V_2 -> V_30 , L_19 ) ;
if ( ! F_27 ( V_96 ) ) {
unsigned long V_99 = F_28 ( V_96 ) ;
bool V_100 ;
V_36 -> V_39 = type -> V_101 ;
V_100 = F_29 ( V_95 ,
L_20 ) ;
if ( V_99 > 24500000 && V_99 < 25500000 ) {
V_36 -> V_40 = V_100 ;
} else if ( V_99 > 49500000 && V_99 < 50500000 ) {
V_36 -> V_40 = ! V_100 ;
} else {
F_9 ( & V_2 -> V_30 , L_21 , V_99 ) ;
return - V_28 ;
}
}
if ( V_2 -> V_102 & V_103 ) {
V_36 -> V_39 = true ;
V_36 -> V_40 = true ;
}
return 0 ;
}
