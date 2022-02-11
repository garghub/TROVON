static inline T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_5 == V_6 )
return V_7 ;
else if ( V_4 -> V_5 == V_8 )
return V_9 ;
else if ( V_4 -> V_5 == V_10 ||
V_4 -> V_5 == V_11 )
return F_2 ( F_3 ( V_2 , V_12 ) ) + 1 ;
else
return F_2 ( F_3 ( V_2 , V_13 ) ) + 1 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_5 == V_14 ||
V_4 -> V_5 == V_11 ) {
F_5 ( V_2 , V_15 , 0 ) ;
F_5 ( V_2 , V_16 , V_17 ) ;
F_5 ( V_2 , V_18 , V_19 |
V_20 |
V_21 |
V_22 ) ;
}
if ( V_4 -> V_5 >= V_23 ) {
V_4 -> V_24 = F_3 ( V_2 , V_25 ) ;
V_4 -> V_26 = F_3 ( V_2 , V_27 ) ;
V_4 -> V_26 |= V_28 ;
F_5 ( V_2 , V_27 , V_4 -> V_26 ) ;
if ( ! V_4 -> V_29 )
V_4 -> V_29 =
F_6 ( V_4 -> V_24 ) ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
V_2 -> V_30 /= ( V_4 -> V_31 + 1 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 , T_2 V_32 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_2 V_33 ;
if ( V_4 -> V_5 == V_10 ||
V_4 -> V_5 == V_11 )
V_33 = F_3 ( V_2 , V_12 ) ;
else
V_33 = F_3 ( V_2 , V_13 ) ;
V_33 = ( V_33 & ~ V_34 ) | V_32 ;
if ( V_4 -> V_5 == V_10 ||
V_4 -> V_5 == V_11 )
F_5 ( V_2 , V_12 , V_33 ) ;
else
F_5 ( V_2 , V_13 , V_33 ) ;
}
static int F_9 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_10 ( V_36 ) ;
return F_11 ( V_2 ) ;
}
static int F_12 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_10 ( V_36 ) ;
F_4 ( V_2 ) ;
return F_13 ( V_2 ) ;
}
static int F_14 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_10 ( V_36 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
T_2 V_33 ;
if ( V_4 -> V_5 == V_10 ||
V_4 -> V_5 == V_11 )
V_33 = F_3 ( V_2 , V_12 ) ;
else
V_33 = F_3 ( V_2 , V_13 ) ;
if ( V_33 & V_37 ) {
if ( V_4 -> V_5 == V_10 ||
V_4 -> V_5 == V_11 )
F_5 ( V_2 , V_12 , V_33 ) ;
else
F_5 ( V_2 , V_13 , V_33 ) ;
}
return 0 ;
}
static void F_15 ( struct V_1 * V_2 , T_2 * V_38 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_5 == V_10 ||
V_4 -> V_5 == V_11 ) {
if ( F_16 ( F_3 ( V_2 , V_12 ) ) )
* V_38 |= V_39 ;
} else {
if ( F_16 ( F_3 ( V_2 , V_13 ) ) )
* V_38 |= V_39 ;
}
}
static void F_17 ( struct V_1 * V_2 , T_2 V_32 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_2 V_40 , V_41 ;
if ( V_4 -> V_5 < V_23 )
return;
V_40 = V_4 -> V_26 ;
V_41 = V_4 -> V_24 ;
if ( V_32 == V_42 ) {
V_40 |= V_43 ;
V_41 = F_18 ( V_41 , V_4 -> V_29 ) ;
} else {
V_40 &= ~ V_43 ;
}
F_5 ( V_2 , V_27 , V_40 ) ;
F_5 ( V_2 , V_25 , V_41 ) ;
}
static void F_19 ( struct V_1 * V_2 , unsigned int V_44 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned long V_45 ;
T_1 div ;
int V_46 ;
if ( ! V_44 || F_20 ( V_2 -> V_47 ) )
return;
if ( V_44 < V_48 )
V_44 = V_48 ;
if ( V_44 == V_4 -> V_49 )
return;
div = F_1 ( V_2 ) ;
V_46 = F_21 ( V_2 -> V_47 , V_44 * div ) ;
if ( V_46 )
F_22 ( V_2 -> V_36 ,
L_1 ,
V_44 * div , V_46 ) ;
V_45 = F_23 ( V_2 -> V_47 ) ;
V_2 -> V_30 = V_45 / div ;
V_4 -> V_49 = V_44 ;
V_2 -> V_50 = 0 ;
}
static void F_24 ( struct V_1 * V_2 , struct V_51 * V_52 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_44 = V_52 -> clock ;
T_2 V_32 = V_52 -> V_32 , V_33 ;
switch ( V_32 ) {
case V_42 :
V_33 = F_25 (
V_4 -> V_53 , V_4 -> V_54 ) ;
V_44 <<= 1 ;
break;
case V_55 :
V_33 = V_4 -> V_56 ;
if ( V_52 -> V_57 == V_58 )
V_44 <<= 1 ;
break;
default:
V_33 = V_4 -> V_59 ;
}
F_8 ( V_2 , V_33 ) ;
F_17 ( V_2 , V_32 ) ;
F_19 ( V_2 , V_44 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_60 * V_61 = V_2 -> V_36 -> V_62 ;
T_2 V_32 [ 2 ] ;
T_2 div = 0 ;
int V_63 ;
int V_46 ;
V_4 = F_27 ( V_2 -> V_36 , sizeof( * V_4 ) , V_64 ) ;
if ( ! V_4 )
return - V_65 ;
for ( V_63 = 0 ; V_63 < F_28 ( V_66 ) ; V_63 ++ ) {
if ( F_29 ( V_61 , V_66 [ V_63 ] . V_67 ) )
V_4 -> V_5 = V_66 [ V_63 ] . V_5 ;
}
if ( V_4 -> V_5 == V_6 )
V_4 -> V_31 = V_7 - 1 ;
else if ( V_4 -> V_5 == V_8 )
V_4 -> V_31 = V_9 - 1 ;
else {
F_30 ( V_61 , L_2 , & div ) ;
V_4 -> V_31 = div ;
}
V_46 = F_31 ( V_61 ,
L_3 , V_32 , 2 ) ;
if ( V_46 )
return V_46 ;
V_4 -> V_59 = F_32 ( V_32 [ 0 ] , V_32 [ 1 ] , div ) ;
V_46 = F_31 ( V_61 ,
L_4 , V_32 , 2 ) ;
if ( V_46 )
return V_46 ;
V_4 -> V_56 = F_32 ( V_32 [ 0 ] , V_32 [ 1 ] , div ) ;
V_46 = F_31 ( V_61 ,
L_5 , V_32 , 2 ) ;
if ( ! V_46 && F_30 ( V_61 ,
L_6 , & V_4 -> V_29 ) )
F_33 ( V_2 -> V_36 ,
L_7 ) ;
V_4 -> V_53 = F_32 ( V_32 [ 0 ] , V_32 [ 1 ] ,
V_68 ) ;
V_2 -> V_4 = V_4 ;
return 0 ;
}
static inline T_1 F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_5 == V_10 ||
V_4 -> V_5 == V_11 )
return F_35 ( F_3 ( V_2 , V_12 ) ) ;
else
return F_35 ( F_3 ( V_2 , V_13 ) ) ;
}
static inline void F_36 ( struct V_1 * V_2 , T_1 V_69 )
{
T_2 V_33 ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_5 == V_10 ||
V_4 -> V_5 == V_11 )
V_33 = F_3 ( V_2 , V_12 ) ;
else
V_33 = F_3 ( V_2 , V_13 ) ;
V_33 = F_25 ( V_33 , V_69 ) ;
if ( V_4 -> V_5 == V_10 ||
V_4 -> V_5 == V_11 )
F_5 ( V_2 , V_12 , V_33 ) ;
else
F_5 ( V_2 , V_13 , V_33 ) ;
}
static inline T_1 F_37 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_2 V_33 ;
T_1 V_69 ;
if ( V_4 -> V_5 == V_10 ||
V_4 -> V_5 == V_11 )
V_33 = F_3 ( V_2 , V_12 ) ;
else
V_33 = F_3 ( V_2 , V_13 ) ;
V_69 = ( V_33 + 1 ) & 0x7 ;
V_33 = F_25 ( V_33 , V_69 ) ;
if ( V_4 -> V_5 == V_10 ||
V_4 -> V_5 == V_11 )
F_5 ( V_2 , V_12 , V_33 ) ;
else
F_5 ( V_2 , V_13 , V_33 ) ;
return V_69 ;
}
static T_3 F_38 ( T_1 V_70 )
{
const T_1 V_71 = 8 ;
T_1 V_72 ;
T_3 V_73 , V_74 = - 1 ;
for ( V_73 = 0 ; V_73 < V_71 ; V_73 ++ ) {
V_72 = F_39 ( V_70 , V_73 ) ;
if ( ( V_72 & 0xc7 ) == 0xc7 ) {
V_74 = V_73 ;
goto V_75;
}
}
for ( V_73 = 0 ; V_73 < V_71 ; V_73 ++ ) {
V_72 = F_39 ( V_70 , V_73 ) ;
if ( ( V_72 & 0x83 ) == 0x83 ) {
V_74 = V_73 ;
goto V_75;
}
}
V_75:
return V_74 ;
}
static int F_40 ( struct V_76 * V_77 , T_2 V_78 )
{
struct V_1 * V_2 = V_77 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_79 * V_80 = V_77 -> V_80 ;
T_1 V_81 , V_82 , V_70 = 0 ;
T_3 V_83 = - 1 ;
int V_46 = 0 ;
V_81 = F_34 ( V_2 ) ;
do {
F_5 ( V_2 , V_84 , ~ 0 ) ;
V_82 = F_37 ( V_2 ) ;
if ( ! F_41 ( V_80 , V_78 , NULL ) )
V_70 |= ( 1 << V_82 ) ;
} while ( V_81 != V_82 );
V_83 = F_38 ( V_70 ) ;
if ( V_83 >= 0 ) {
F_36 ( V_2 , V_83 ) ;
V_4 -> V_54 = V_83 ;
} else {
V_46 = - V_85 ;
}
return V_46 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_51 * V_52 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_8 ( V_2 , V_4 -> V_53 ) ;
F_19 ( V_2 , ( V_52 -> clock ) << 1 ) ;
return 0 ;
}
static int F_43 ( struct V_86 * V_87 )
{
const struct V_88 * V_89 ;
const struct V_90 * V_91 ;
V_91 = F_44 ( V_92 , V_87 -> V_36 . V_62 ) ;
V_89 = V_91 -> V_93 ;
return F_45 ( V_87 , V_89 ) ;
}
