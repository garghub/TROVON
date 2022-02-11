static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 , V_4 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_5 == V_6 )
V_3 = F_4 ( V_2 , V_7 , V_8 ) ;
else
V_3 = F_4 ( V_2 , V_7 , V_9 ) ;
return V_3 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_4 ( V_2 , V_10 , V_11 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , 0x1d , 0x1f ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , 0x1e , 0x200c ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , 0x1d , 0x5 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , 0x1e , 0 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , 0x1e , 0x100 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_12 ,
V_13 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_14 ,
V_15 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_6 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_2 -> V_16 != V_17 ) {
int V_18 ;
V_18 = F_2 ( V_2 , V_10 ) ;
if ( V_18 < 0 )
return V_18 ;
V_3 = F_4 ( V_2 , V_10 , V_18 | V_11 ) ;
if ( V_3 < 0 )
return V_3 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
const T_1 * V_19 ;
int V_20 , V_21 , V_22 , V_23 , V_24 , V_25 ;
if ( ! V_2 -> V_26 . V_27 )
return 0 ;
V_19 = F_8 ( V_2 -> V_26 . V_27 , L_1 , & V_20 ) ;
if ( ! V_19 || V_20 < ( 4 * sizeof( * V_19 ) ) )
return 0 ;
V_22 = F_2 ( V_2 , V_28 ) ;
if ( V_22 < 0 )
return V_22 ;
V_24 = 0 ;
V_23 = V_22 ;
V_25 = 0 ;
V_20 /= sizeof( * V_19 ) ;
for ( V_21 = 0 ; V_21 < V_20 - 3 ; V_21 += 4 ) {
T_2 V_29 = F_9 ( V_19 + V_21 ) ;
T_2 V_30 = F_9 ( V_19 + V_21 + 1 ) ;
T_2 V_31 = F_9 ( V_19 + V_21 + 2 ) ;
T_2 V_32 = F_9 ( V_19 + V_21 + 3 ) ;
int V_33 ;
if ( V_29 != V_23 ) {
V_23 = V_29 ;
V_24 = 1 ;
V_25 = F_4 ( V_2 , V_28 , V_29 ) ;
if ( V_25 < 0 )
goto V_3;
}
V_33 = 0 ;
if ( V_31 ) {
V_33 = F_2 ( V_2 , V_30 ) ;
if ( V_33 < 0 ) {
V_25 = V_33 ;
goto V_3;
}
V_33 &= V_31 ;
}
V_33 |= V_32 ;
V_25 = F_4 ( V_2 , V_30 , V_33 ) ;
if ( V_25 < 0 )
goto V_3;
}
V_3:
if ( V_24 ) {
V_21 = F_4 ( V_2 , V_28 , V_22 ) ;
if ( V_25 == 0 )
V_25 = V_21 ;
}
return V_25 ;
}
static int F_7 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_3 , V_34 , V_35 ;
V_34 = F_2 ( V_2 , V_28 ) ;
V_3 = F_4 ( V_2 , V_28 ,
V_36 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( ( V_2 -> V_37 == V_38 ) ||
( V_2 -> V_37 == V_39 ) ||
( V_2 -> V_37 == V_40 ) ||
( V_2 -> V_37 == V_41 ) ) {
V_35 = F_2 ( V_2 , V_42 ) &
V_43 ;
if ( V_2 -> V_37 == V_39 )
V_35 |= ( V_44 |
V_45 ) ;
else if ( V_2 -> V_37 == V_40 )
V_35 |= V_44 ;
else if ( V_2 -> V_37 == V_41 )
V_35 |= V_45 ;
V_3 = F_4 ( V_2 , V_42 , V_35 ) ;
if ( V_3 < 0 )
return V_3 ;
}
F_4 ( V_2 , V_28 , V_34 ) ;
V_3 = F_4 ( V_2 , V_10 , V_11 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_12 ,
V_13 ) ;
if ( V_3 < 0 )
return V_3 ;
V_34 = F_2 ( V_2 , V_28 ) ;
F_4 ( V_2 , V_28 , V_46 ) ;
F_4 ( V_2 , V_47 , V_48 ) ;
F_4 ( V_2 , V_28 , V_34 ) ;
V_3 = F_6 ( V_2 ) ;
return V_3 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_3 , V_34 , V_35 ;
V_34 = F_2 ( V_2 , V_28 ) ;
V_3 = F_4 ( V_2 , V_28 ,
V_36 ) ;
if ( V_3 < 0 )
return V_3 ;
V_35 = F_2 ( V_2 , V_49 ) ;
V_35 |= V_50 ;
V_3 = F_4 ( V_2 , V_49 , V_35 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_28 , V_34 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_10 ( V_2 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_3 ;
int V_51 ;
V_51 = F_2 ( V_2 , V_52 ) ;
V_51 &= ~ V_53 ;
F_4 ( V_2 , V_52 , V_51 ) ;
V_51 = F_2 ( V_2 , V_10 ) ;
V_51 |= V_11 ;
F_4 ( V_2 , V_10 , V_51 ) ;
if ( ( V_2 -> V_37 == V_38 ) ||
( V_2 -> V_37 == V_39 ) ||
( V_2 -> V_37 == V_40 ) ||
( V_2 -> V_37 == V_41 ) ) {
V_51 = F_2 ( V_2 , V_54 ) ;
if ( V_51 < 0 )
return V_51 ;
if ( V_2 -> V_37 == V_39 ) {
V_51 |= ( V_55 | V_56 ) ;
} else if ( V_2 -> V_37 == V_40 ) {
V_51 &= ~ V_56 ;
V_51 |= V_55 ;
} else if ( V_2 -> V_37 == V_41 ) {
V_51 &= ~ V_55 ;
V_51 |= V_56 ;
}
V_3 = F_4 ( V_2 , V_54 , V_51 ) ;
if ( V_3 < 0 )
return V_3 ;
V_51 = F_2 ( V_2 , V_52 ) ;
if ( V_51 < 0 )
return V_51 ;
V_51 &= ~ ( V_57 ) ;
if ( V_51 & V_58 )
V_51 |= V_59 ;
else
V_51 |= V_60 ;
V_3 = F_4 ( V_2 , V_52 , V_51 ) ;
if ( V_3 < 0 )
return V_3 ;
}
if ( V_2 -> V_37 == V_61 ) {
V_51 = F_2 ( V_2 , V_52 ) ;
if ( V_51 < 0 )
return V_51 ;
V_51 &= ~ ( V_57 ) ;
V_51 |= V_62 ;
V_51 |= V_53 ;
V_3 = F_4 ( V_2 , V_52 , V_51 ) ;
if ( V_3 < 0 )
return V_3 ;
}
if ( V_2 -> V_37 == V_63 ) {
V_51 = F_2 ( V_2 , V_54 ) ;
if ( V_51 < 0 )
return V_51 ;
V_51 |= ( V_55 | V_56 ) ;
V_3 = F_4 ( V_2 , V_54 , V_51 ) ;
if ( V_3 < 0 )
return V_3 ;
V_51 = F_2 ( V_2 , V_52 ) ;
if ( V_51 < 0 )
return V_51 ;
V_51 &= ~ ( V_57 | V_58 ) ;
V_51 |= 0x7 | V_53 ;
V_3 = F_4 ( V_2 , V_52 , V_51 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_10 , V_11 ) ;
if ( V_3 < 0 )
return V_3 ;
do
V_51 = F_2 ( V_2 , V_10 ) ;
while ( V_51 & V_11 );
V_51 = F_2 ( V_2 , V_52 ) ;
if ( V_51 < 0 )
return V_51 ;
V_51 &= ~ ( V_57 | V_58 ) ;
V_51 |= V_64 | V_53 ;
V_3 = F_4 ( V_2 , V_52 , V_51 ) ;
if ( V_3 < 0 )
return V_3 ;
}
V_3 = F_7 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_4 ( V_2 , V_10 , V_11 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_4 ( V_2 , V_10 , V_11 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_12 ,
V_13 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_6 ( V_2 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_4 ( V_2 , V_28 , 0x0002 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , 0x15 , 0x1070 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_28 , 0x0003 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_2 -> V_65 & V_66 )
V_3 = F_4 ( V_2 , 0x10 , 0x1100 ) ;
else
V_3 = F_4 ( V_2 , 0x10 , 0x021e ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_7 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_28 , 0x0 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_4 ( V_2 , V_10 , V_11 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_4 ( V_2 , V_28 , 0x0002 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , 0x15 , 0x1048 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_7 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_28 , 0x0 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_4 ( V_2 , V_10 , V_11 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_4 ( V_2 , 0x1d , 0x001b ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , 0x1e , 0x418f ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , 0x1d , 0x0016 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , 0x1e , 0xa2da ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_2 -> V_37 == V_39 ) {
int V_51 = F_2 ( V_2 , V_67 ) ;
if ( V_51 < 0 )
return V_51 ;
V_51 |= ( V_68 | V_69 ) ;
V_3 = F_4 ( V_2 , V_67 , V_51 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_2 -> V_65 & V_70 ) {
V_3 = F_4 ( V_2 , 0x1d , 0x0012 ) ;
if ( V_3 < 0 )
return V_3 ;
V_51 = F_2 ( V_2 , 0x1e ) ;
if ( V_51 < 0 )
return V_51 ;
V_51 &= 0xf03f ;
V_51 |= 2 << 9 ;
V_51 |= 2 << 6 ;
V_3 = F_4 ( V_2 , 0x1e , V_51 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , 0x1d , 0x3 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , 0x1e , 0x8000 ) ;
if ( V_3 < 0 )
return V_3 ;
}
}
V_3 = F_7 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_71 ;
int V_3 ;
int V_72 ;
int V_73 = 0 ;
V_3 = F_18 ( V_2 ) ;
if ( V_3 )
return V_3 ;
if ( V_17 == V_2 -> V_16 ) {
V_73 = F_2 ( V_2 , V_74 ) ;
if ( V_73 < 0 )
return V_73 ;
V_72 = F_2 ( V_2 , V_75 ) ;
if ( V_72 < 0 )
return V_72 ;
V_71 = F_2 ( V_2 , V_76 ) ;
if ( V_71 < 0 )
return V_71 ;
V_72 &= V_71 ;
if ( V_73 & V_77 )
V_2 -> V_78 = V_79 ;
else
V_2 -> V_78 = V_80 ;
V_73 = V_73 & V_81 ;
V_2 -> V_82 = V_2 -> V_83 = 0 ;
switch ( V_73 ) {
case V_84 :
V_2 -> V_85 = V_86 ;
break;
case V_87 :
V_2 -> V_85 = V_88 ;
break;
default:
V_2 -> V_85 = V_89 ;
break;
}
if ( V_2 -> V_78 == V_79 ) {
V_2 -> V_82 = V_72 & V_90 ? 1 : 0 ;
V_2 -> V_83 = V_72 & V_91 ? 1 : 0 ;
}
} else {
int V_18 = F_2 ( V_2 , V_10 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_18 & V_92 )
V_2 -> V_78 = V_79 ;
else
V_2 -> V_78 = V_80 ;
if ( V_18 & V_93 )
V_2 -> V_85 = V_86 ;
else if ( V_18 & V_94 )
V_2 -> V_85 = V_88 ;
else
V_2 -> V_85 = V_89 ;
V_2 -> V_82 = V_2 -> V_83 = 0 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_95 ;
V_95 = F_2 ( V_2 , V_4 ) ;
if ( V_95 & V_8 )
return 1 ;
return 0 ;
}
static int T_3 F_20 ( void )
{
int V_25 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < F_21 ( V_96 ) ; V_21 ++ ) {
V_25 = F_22 ( & V_96 [ V_21 ] ) ;
if ( V_25 ) {
while ( V_21 -- > 0 )
F_23 ( & V_96 [ V_21 ] ) ;
return V_25 ;
}
}
return 0 ;
}
static void T_4 F_24 ( void )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < F_21 ( V_96 ) ; V_21 ++ )
F_23 ( & V_96 [ V_21 ] ) ;
}
