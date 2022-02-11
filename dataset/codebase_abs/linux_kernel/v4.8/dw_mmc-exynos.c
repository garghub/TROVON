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
static void F_4 ( struct V_1 * V_2 )
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
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_4 ( V_2 ) ;
if ( V_4 -> V_5 >= V_23 ) {
V_4 -> V_24 = F_3 ( V_2 , V_25 ) ;
V_4 -> V_26 = F_3 ( V_2 , V_27 ) ;
V_4 -> V_26 |= V_28 ;
F_5 ( V_2 , V_27 , V_4 -> V_26 ) ;
if ( ! V_4 -> V_29 )
V_4 -> V_29 =
F_7 ( V_4 -> V_24 ) ;
}
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
if ( ! F_9 ( V_33 ) && V_2 -> V_35 )
F_10 ( V_36 , & V_2 -> V_35 -> V_37 ) ;
}
static int F_11 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_12 ( V_39 ) ;
return F_13 ( V_2 ) ;
}
static int F_14 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_12 ( V_39 ) ;
F_4 ( V_2 ) ;
return F_15 ( V_2 ) ;
}
static int F_16 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_12 ( V_39 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
T_2 V_33 ;
if ( V_4 -> V_5 == V_10 ||
V_4 -> V_5 == V_11 )
V_33 = F_3 ( V_2 , V_12 ) ;
else
V_33 = F_3 ( V_2 , V_13 ) ;
if ( V_33 & V_40 ) {
if ( V_4 -> V_5 == V_10 ||
V_4 -> V_5 == V_11 )
F_5 ( V_2 , V_12 , V_33 ) ;
else
F_5 ( V_2 , V_13 , V_33 ) ;
}
return 0 ;
}
static void F_17 ( struct V_1 * V_2 , T_2 V_32 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_2 V_41 , V_42 ;
if ( V_4 -> V_5 < V_23 )
return;
V_41 = V_4 -> V_26 ;
V_42 = V_4 -> V_24 ;
if ( V_32 == V_43 ) {
V_41 |= V_44 ;
V_42 = F_18 ( V_42 , V_4 -> V_29 ) ;
} else {
V_41 &= ~ V_44 ;
}
F_5 ( V_2 , V_27 , V_41 ) ;
F_5 ( V_2 , V_25 , V_42 ) ;
}
static void F_19 ( struct V_1 * V_2 , unsigned int V_45 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned long V_46 ;
T_1 div ;
int V_47 ;
if ( ! V_45 || F_20 ( V_2 -> V_48 ) )
return;
if ( V_45 < V_49 )
V_45 = V_49 ;
if ( V_45 == V_4 -> V_50 )
return;
div = F_1 ( V_2 ) ;
V_47 = F_21 ( V_2 -> V_48 , V_45 * div ) ;
if ( V_47 )
F_22 ( V_2 -> V_39 ,
L_1 ,
V_45 * div , V_47 ) ;
V_46 = F_23 ( V_2 -> V_48 ) ;
V_2 -> V_30 = V_46 / div ;
V_4 -> V_50 = V_45 ;
V_2 -> V_51 = 0 ;
}
static void F_24 ( struct V_1 * V_2 , struct V_52 * V_53 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_45 = V_53 -> clock ;
T_2 V_32 = V_53 -> V_32 , V_33 ;
switch ( V_32 ) {
case V_43 :
V_33 = F_25 (
V_4 -> V_54 , V_4 -> V_55 ) ;
V_45 <<= 1 ;
break;
case V_56 :
V_33 = V_4 -> V_57 ;
if ( V_53 -> V_58 == V_59 )
V_45 <<= 1 ;
break;
default:
V_33 = V_4 -> V_60 ;
}
F_8 ( V_2 , V_33 ) ;
F_17 ( V_2 , V_32 ) ;
F_19 ( V_2 , V_45 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_61 * V_62 = V_2 -> V_39 -> V_63 ;
T_2 V_32 [ 2 ] ;
T_2 div = 0 ;
int V_64 ;
int V_47 ;
V_4 = F_27 ( V_2 -> V_39 , sizeof( * V_4 ) , V_65 ) ;
if ( ! V_4 )
return - V_66 ;
for ( V_64 = 0 ; V_64 < F_28 ( V_67 ) ; V_64 ++ ) {
if ( F_29 ( V_62 , V_67 [ V_64 ] . V_68 ) )
V_4 -> V_5 = V_67 [ V_64 ] . V_5 ;
}
if ( V_4 -> V_5 == V_6 )
V_4 -> V_31 = V_7 - 1 ;
else if ( V_4 -> V_5 == V_8 )
V_4 -> V_31 = V_9 - 1 ;
else {
F_30 ( V_62 , L_2 , & div ) ;
V_4 -> V_31 = div ;
}
V_47 = F_31 ( V_62 ,
L_3 , V_32 , 2 ) ;
if ( V_47 )
return V_47 ;
V_4 -> V_60 = F_32 ( V_32 [ 0 ] , V_32 [ 1 ] , div ) ;
V_47 = F_31 ( V_62 ,
L_4 , V_32 , 2 ) ;
if ( V_47 )
return V_47 ;
V_4 -> V_57 = F_32 ( V_32 [ 0 ] , V_32 [ 1 ] , div ) ;
V_47 = F_31 ( V_62 ,
L_5 , V_32 , 2 ) ;
if ( ! V_47 && F_30 ( V_62 ,
L_6 , & V_4 -> V_29 ) )
F_33 ( V_2 -> V_39 ,
L_7 ) ;
V_4 -> V_54 = F_32 ( V_32 [ 0 ] , V_32 [ 1 ] ,
V_69 ) ;
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
static inline void F_36 ( struct V_1 * V_2 , T_1 V_70 )
{
T_2 V_33 ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_5 == V_10 ||
V_4 -> V_5 == V_11 )
V_33 = F_3 ( V_2 , V_12 ) ;
else
V_33 = F_3 ( V_2 , V_13 ) ;
V_33 = F_25 ( V_33 , V_70 ) ;
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
T_1 V_70 ;
if ( V_4 -> V_5 == V_10 ||
V_4 -> V_5 == V_11 )
V_33 = F_3 ( V_2 , V_12 ) ;
else
V_33 = F_3 ( V_2 , V_13 ) ;
V_70 = ( V_33 + 1 ) & 0x7 ;
V_33 = F_25 ( V_33 , V_70 ) ;
if ( V_4 -> V_5 == V_10 ||
V_4 -> V_5 == V_11 )
F_5 ( V_2 , V_12 , V_33 ) ;
else
F_5 ( V_2 , V_13 , V_33 ) ;
return V_70 ;
}
static T_3 F_38 ( T_1 V_71 )
{
const T_1 V_72 = 8 ;
T_1 V_73 ;
T_3 V_74 , V_75 = - 1 ;
for ( V_74 = 0 ; V_74 < V_72 ; V_74 ++ ) {
V_73 = F_39 ( V_71 , V_74 ) ;
if ( ( V_73 & 0xc7 ) == 0xc7 ) {
V_75 = V_74 ;
goto V_76;
}
}
for ( V_74 = 0 ; V_74 < V_72 ; V_74 ++ ) {
V_73 = F_39 ( V_71 , V_74 ) ;
if ( ( V_73 & 0x83 ) == 0x83 ) {
V_75 = V_74 ;
goto V_76;
}
}
V_76:
return V_75 ;
}
static int F_40 ( struct V_77 * V_78 , T_2 V_79 )
{
struct V_1 * V_2 = V_78 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_80 * V_81 = V_78 -> V_81 ;
T_1 V_82 , V_83 , V_71 = 0 ;
T_3 V_84 = - 1 ;
int V_47 = 0 ;
V_82 = F_34 ( V_2 ) ;
do {
F_5 ( V_2 , V_85 , ~ 0 ) ;
V_83 = F_37 ( V_2 ) ;
if ( ! F_41 ( V_81 , V_79 , NULL ) )
V_71 |= ( 1 << V_83 ) ;
} while ( V_82 != V_83 );
V_84 = F_38 ( V_71 ) ;
if ( V_84 >= 0 ) {
F_36 ( V_2 , V_84 ) ;
V_4 -> V_55 = V_84 ;
} else {
V_47 = - V_86 ;
}
return V_47 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_8 ( V_2 , V_4 -> V_54 ) ;
F_19 ( V_2 , ( V_53 -> clock ) << 1 ) ;
return 0 ;
}
static int F_43 ( struct V_87 * V_88 )
{
const struct V_89 * V_90 ;
const struct V_91 * V_92 ;
V_92 = F_44 ( V_93 , V_88 -> V_39 . V_63 ) ;
V_90 = V_92 -> V_94 ;
return F_45 ( V_88 , V_90 ) ;
}
