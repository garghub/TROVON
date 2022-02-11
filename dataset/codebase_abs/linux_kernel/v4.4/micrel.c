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
const struct V_43 * V_44 ,
T_2 V_24 ,
const char * V_45 , const char * V_46 ,
const char * V_47 , const char * V_48 )
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
const struct V_56 * V_30 = & V_2 -> V_30 ;
const struct V_43 * V_44 = V_30 -> V_44 ;
const struct V_56 * V_57 ;
V_57 = & V_2 -> V_30 ;
do {
V_44 = V_57 -> V_44 ;
V_57 = V_57 -> V_58 ;
} while ( ! V_44 && V_57 );
if ( V_44 ) {
F_13 ( V_2 , V_44 ,
V_59 ,
L_5 , L_6 ,
L_7 , L_8 ) ;
F_13 ( V_2 , V_44 ,
V_60 ,
L_9 , L_10 ,
L_11 , L_12 ) ;
F_13 ( V_2 , V_44 ,
V_61 ,
L_13 , L_14 ,
L_15 , L_16 ) ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
T_3 V_62 , T_1 V_63 , T_1 V_3 , T_2 V_4 )
{
F_2 ( V_2 , V_64 , V_63 ) ;
F_2 ( V_2 , V_65 , V_3 ) ;
F_2 ( V_2 , V_64 , ( V_62 << 14 ) | V_63 ) ;
return F_2 ( V_2 , V_65 , V_4 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
T_3 V_62 , T_1 V_63 , T_1 V_3 )
{
F_2 ( V_2 , V_64 , V_63 ) ;
F_2 ( V_2 , V_65 , V_3 ) ;
F_2 ( V_2 , V_64 , ( V_62 << 14 ) | V_63 ) ;
return F_4 ( V_2 , V_65 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
const struct V_43 * V_44 ,
T_2 V_24 , T_4 V_66 ,
const char * V_67 [] , T_3 V_68 )
{
int V_4 [ 4 ] = { - 1 , - 2 , - 3 , - 4 } ;
int V_54 = 0 ;
T_2 V_15 ;
T_2 V_69 ;
T_2 V_53 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_68 ; V_70 ++ )
if ( ! F_14 ( V_44 , V_67 [ V_70 ] , V_4 + V_70 ) )
V_54 ++ ;
if ( ! V_54 )
return 0 ;
if ( V_54 < V_68 )
V_53 = F_17 ( V_2 , V_71 , 2 , V_24 ) ;
else
V_53 = 0 ;
V_69 = ( V_66 == 4 ) ? 0xf : 0x1f ;
for ( V_70 = 0 ; V_70 < V_68 ; V_70 ++ )
if ( V_4 [ V_70 ] != - ( V_70 + 1 ) ) {
V_15 = 0xffff ;
V_15 ^= V_69 << ( V_66 * V_70 ) ;
V_53 = ( V_53 & V_15 ) |
( ( ( V_4 [ V_70 ] / V_72 ) & V_69 )
<< ( V_66 * V_70 ) ) ;
}
return F_16 ( V_2 , V_71 , 2 , V_24 , V_53 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_73 ;
V_73 = F_16 ( V_2 , V_71 , 0 ,
V_74 , 0x0006 ) ;
V_73 = F_16 ( V_2 , V_71 , 0 ,
V_75 , 0x1A80 ) ;
if ( V_73 )
return V_73 ;
return F_20 ( V_2 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
const struct V_56 * V_30 = & V_2 -> V_30 ;
const struct V_43 * V_44 = V_30 -> V_44 ;
static const char * V_76 [ 2 ] = { L_8 , L_6 } ;
static const char * V_77 [ 4 ] = {
L_9 , L_10 ,
L_11 , L_12
} ;
static const char * V_78 [ 4 ] = {
L_13 , L_14 ,
L_15 , L_16
} ;
static const char * V_79 [ 2 ] = { L_5 , L_7 } ;
if ( ! V_44 && V_30 -> V_58 -> V_44 )
V_44 = V_30 -> V_58 -> V_44 ;
if ( V_44 ) {
F_18 ( V_2 , V_44 ,
V_80 , 5 ,
V_76 , 2 ) ;
F_18 ( V_2 , V_44 ,
V_81 , 4 ,
V_79 , 2 ) ;
F_18 ( V_2 , V_44 ,
V_82 , 4 ,
V_77 , 4 ) ;
F_18 ( V_2 , V_44 ,
V_83 , 4 ,
V_78 , 4 ) ;
}
return F_19 ( V_2 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_84 ;
V_84 = F_4 ( V_2 , V_85 ) ;
V_84 = F_4 ( V_2 , V_85 ) ;
if ( V_84 & V_86 )
V_2 -> V_87 = V_88 ;
else
V_2 -> V_87 = V_89 ;
if ( V_84 & V_90 )
V_2 -> V_91 = V_92 ;
else
V_2 -> V_91 = V_93 ;
V_2 -> V_94 = 1 ;
V_2 -> V_95 = V_2 -> V_96 = 0 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_97 ;
int V_84 ;
V_97 = F_24 ( V_2 ) ;
if ( V_97 )
return V_97 ;
V_84 = F_4 ( V_2 , V_98 ) ;
if ( ( V_84 & 0xFF ) == 0xFF ) {
F_25 ( V_2 ) ;
V_2 -> V_94 = 0 ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
return 0 ;
}
static int
F_27 ( struct V_1 * V_2 , int V_99 , int V_100 ,
int V_3 )
{
return - 1 ;
}
static void
F_28 ( struct V_1 * V_2 , int V_99 , int V_100 ,
int V_3 , T_1 V_4 )
{
}
static int F_29 ( struct V_1 * V_2 )
{
const struct V_11 * type = V_2 -> V_12 -> V_13 ;
const struct V_43 * V_101 = V_2 -> V_30 . V_44 ;
struct V_35 * V_36 ;
struct V_102 * V_102 ;
int V_31 ;
V_36 = F_30 ( & V_2 -> V_30 , sizeof( * V_36 ) , V_103 ) ;
if ( ! V_36 )
return - V_104 ;
V_2 -> V_36 = V_36 ;
V_36 -> type = type ;
if ( type -> V_42 ) {
V_31 = F_14 ( V_101 , L_17 ,
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
V_102 = F_31 ( & V_2 -> V_30 , L_19 ) ;
if ( ! F_32 ( V_102 ) ) {
unsigned long V_105 = F_33 ( V_102 ) ;
bool V_106 ;
V_36 -> V_39 = type -> V_107 ;
V_106 = F_34 ( V_101 ,
L_20 ) ;
if ( V_105 > 24500000 && V_105 < 25500000 ) {
V_36 -> V_40 = V_106 ;
} else if ( V_105 > 49500000 && V_105 < 50500000 ) {
V_36 -> V_40 = ! V_106 ;
} else {
F_9 ( & V_2 -> V_30 , L_21 , V_105 ) ;
return - V_28 ;
}
}
if ( V_2 -> V_108 & V_109 ) {
V_36 -> V_39 = true ;
V_36 -> V_40 = true ;
}
return 0 ;
}
