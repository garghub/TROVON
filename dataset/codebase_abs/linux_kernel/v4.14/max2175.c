static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_1 * F_3 ( struct V_4 * V_5 )
{
return F_2 ( V_5 , struct V_1 , V_6 ) ;
}
static inline T_1 F_4 ( T_1 V_7 , T_1 V_8 , T_1 V_9 )
{
return ( V_7 & F_5 ( V_8 , V_9 ) ) >> V_9 ;
}
static int F_6 ( struct V_1 * V_10 , T_1 V_11 , T_1 * V_7 )
{
T_2 V_12 ;
int V_13 ;
V_13 = F_7 ( V_10 -> V_14 , V_11 , & V_12 ) ;
if ( V_13 )
F_8 ( V_10 , L_1 , V_13 , V_11 ) ;
else
* V_7 = V_12 ;
return V_13 ;
}
static int F_9 ( struct V_1 * V_10 , T_1 V_11 , T_1 V_7 )
{
int V_13 ;
V_13 = F_10 ( V_10 -> V_14 , V_11 , V_7 ) ;
if ( V_13 )
F_8 ( V_10 , L_2 ,
V_13 , V_11 , V_7 ) ;
return V_13 ;
}
static T_1 F_11 ( struct V_1 * V_10 , T_1 V_11 , T_1 V_8 , T_1 V_9 )
{
T_1 V_7 ;
if ( F_6 ( V_10 , V_11 , & V_7 ) )
return 0 ;
return F_4 ( V_7 , V_8 , V_9 ) ;
}
static int F_12 ( struct V_1 * V_10 , T_1 V_11 ,
T_1 V_8 , T_1 V_9 , T_1 V_15 )
{
int V_13 = F_13 ( V_10 -> V_14 , V_11 , F_5 ( V_8 , V_9 ) ,
V_15 << V_9 ) ;
if ( V_13 )
F_8 ( V_10 , L_3 , V_13 , V_11 ) ;
return V_13 ;
}
static int F_14 ( struct V_1 * V_10 , T_1 V_11 , T_1 V_16 , T_1 V_15 )
{
return F_12 ( V_10 , V_11 , V_16 , V_16 , V_15 ) ;
}
static int F_15 ( struct V_1 * V_10 , T_1 V_11 , T_1 V_8 , T_1 V_9 ,
T_1 V_17 , T_2 V_18 )
{
unsigned int V_7 ;
return F_16 ( V_10 -> V_14 , V_11 , V_7 ,
( F_4 ( V_7 , V_8 , V_9 ) == V_17 ) ,
1000 , V_18 ) ;
}
static int F_17 ( struct V_1 * V_10 )
{
int V_13 ;
V_13 = F_15 ( V_10 , 69 , 1 , 1 , 0 , 50000 ) ;
if ( V_13 )
F_8 ( V_10 , L_4 ) ;
return V_13 ;
}
static int F_18 ( T_2 V_19 )
{
if ( V_19 >= 144000 && V_19 <= 26100000 )
return V_20 ;
else if ( V_19 >= 65000000 && V_19 <= 108000000 )
return V_21 ;
return V_22 ;
}
static void F_19 ( struct V_1 * V_10 , bool V_23 )
{
if ( V_23 )
F_12 ( V_10 , 104 , 3 , 0 , 2 ) ;
else
F_12 ( V_10 , 104 , 3 , 0 , 9 ) ;
F_20 ( V_10 , L_5 , V_23 ? L_6 : L_7 ) ;
}
static void F_21 ( struct V_1 * V_10 , T_1 V_24 ,
T_1 V_25 , const T_3 * V_26 )
{
unsigned int V_27 ;
T_1 V_28 , V_29 = 24 ;
F_20 ( V_10 , L_8 , V_24 , V_25 ) ;
F_12 ( V_10 , 114 , 5 , 4 , V_24 ) ;
if ( V_24 == 2 )
V_29 = 12 ;
for ( V_27 = 0 ; V_27 < V_29 ; V_27 ++ ) {
V_28 = V_27 + V_25 * 24 ;
F_9 ( V_10 , 115 , V_26 [ V_27 ] >> 8 ) ;
F_9 ( V_10 , 116 , V_26 [ V_27 ] ) ;
F_9 ( V_10 , 117 , V_28 | 1 << 7 ) ;
}
F_14 ( V_10 , 117 , 7 , 0 ) ;
}
static void F_22 ( struct V_1 * V_10 )
{
unsigned int V_27 ;
for ( V_27 = 0 ; V_27 < F_23 ( V_30 ) ; V_27 ++ )
F_9 ( V_10 , V_30 [ V_27 ] . V_11 , V_30 [ V_27 ] . V_7 ) ;
V_10 -> V_31 = 36 ;
F_21 ( V_10 , V_32 , 0 , V_33 ) ;
F_21 ( V_10 , V_34 , 0 ,
V_35 ) ;
}
static void F_24 ( struct V_1 * V_10 )
{
unsigned int V_27 ;
for ( V_27 = 0 ; V_27 < F_23 ( V_36 ) ; V_27 ++ )
F_9 ( V_10 , V_36 [ V_27 ] . V_11 , V_36 [ V_27 ] . V_7 ) ;
V_10 -> V_31 = 1 ;
F_21 ( V_10 , V_32 , 2 , V_37 ) ;
}
static void F_25 ( struct V_1 * V_10 )
{
unsigned int V_27 ;
for ( V_27 = 0 ; V_27 < F_23 ( V_38 ) ; V_27 ++ )
F_9 ( V_10 , V_38 [ V_27 ] . V_11 , V_38 [ V_27 ] . V_7 ) ;
}
static void F_26 ( struct V_1 * V_10 )
{
unsigned int V_27 ;
for ( V_27 = 0 ; V_27 < F_23 ( V_39 ) ; V_27 ++ )
F_9 ( V_10 , V_39 [ V_27 ] . V_11 , V_39 [ V_27 ] . V_7 ) ;
}
static void F_27 ( struct V_1 * V_10 )
{
if ( F_28 ( V_10 ) ) {
F_12 ( V_10 , 12 , 3 , 0 , V_10 -> V_40 ) ;
F_20 ( V_10 , L_9 , V_10 -> V_40 ) ;
} else if ( F_29 ( V_10 ) ) {
F_12 ( V_10 , 12 , 3 , 0 , V_10 -> V_41 ) ;
F_20 ( V_10 , L_10 , V_10 -> V_41 ) ;
} else {
F_12 ( V_10 , 12 , 3 , 0 , V_10 -> V_42 ) ;
F_20 ( V_10 , L_11 , V_10 -> V_42 ) ;
}
}
static bool F_30 ( struct V_1 * V_10 ,
enum V_43 V_44 )
{
int V_13 = F_17 ( V_10 ) ;
if ( V_13 )
return V_13 ;
F_12 ( V_10 , 0 , 2 , 0 , V_44 ) ;
F_20 ( V_10 , L_12 , V_44 ) ;
switch ( V_44 ) {
case V_45 :
F_31 ( 51100 , 51500 ) ;
break;
default:
break;
}
return F_17 ( V_10 ) ;
}
static int F_32 ( struct V_1 * V_10 ,
enum V_43 V_46 )
{
int V_13 ;
F_20 ( V_10 , L_13 , V_46 ) ;
V_13 = F_30 ( V_10 , V_47 ) ;
if ( V_13 )
return V_13 ;
return F_30 ( V_10 , V_45 ) ;
}
static int F_33 ( struct V_1 * V_10 , T_2 V_48 )
{
T_1 V_49 , V_50 = 0 , V_51 = 0 ;
T_2 V_52 , V_53 ;
enum V_54 V_55 ;
int V_13 ;
V_55 = F_11 ( V_10 , 5 , 1 , 0 ) ;
switch ( V_55 ) {
case V_20 :
V_49 = 16 ;
break;
case V_21 :
if ( V_48 <= 74700000 ) {
V_49 = 16 ;
} else if ( V_48 > 74700000 && V_48 <= 110000000 ) {
V_50 = 1 ;
V_49 = 8 ;
} else {
V_50 = 1 ;
V_51 = 3 ;
V_49 = 8 ;
}
break;
case V_22 :
if ( V_48 <= 210000000 )
V_51 = 2 ;
else
V_51 = 1 ;
V_50 = 2 ;
V_49 = 4 ;
break;
default:
V_50 = 3 ;
V_51 = 2 ;
V_49 = 2 ;
break;
}
if ( V_55 == V_56 )
V_48 /= V_49 ;
else
V_48 *= V_49 ;
V_52 = V_48 / V_10 -> V_57 ;
V_53 = F_34 ( ( V_58 ) ( V_48 % V_10 -> V_57 ) << 20 ,
V_10 -> V_57 ) ;
V_13 = F_17 ( V_10 ) ;
if ( V_13 )
return V_13 ;
F_20 ( V_10 , L_14 ,
V_49 , V_52 , V_53 ) ;
F_9 ( V_10 , 1 , V_52 ) ;
F_12 ( V_10 , 2 , 3 , 0 , ( V_53 >> 16 ) & 0xf ) ;
F_9 ( V_10 , 3 , V_53 >> 8 ) ;
F_9 ( V_10 , 4 , V_53 ) ;
F_12 ( V_10 , 5 , 3 , 2 , V_50 ) ;
F_12 ( V_10 , 6 , 7 , 6 , V_51 ) ;
return V_13 ;
}
static inline T_4 F_35 ( T_4 V_59 , T_5 V_60 )
{
if ( ( V_59 > 0 && V_60 > 0 ) || ( V_59 < 0 && V_60 < 0 ) )
return F_36 ( V_59 + V_60 / 2 , V_60 ) ;
return F_36 ( V_59 - V_60 / 2 , V_60 ) ;
}
static int F_37 ( struct V_1 * V_10 , T_5 V_61 )
{
T_5 V_62 = V_10 -> V_57 / V_10 -> V_31 ;
T_2 V_63 , V_64 = abs ( V_61 ) ;
T_4 V_65 ;
int V_13 ;
if ( V_64 < V_62 / 2 ) {
V_65 = 2 * V_61 ;
} else {
V_65 = 2 * ( V_62 - V_64 ) ;
if ( V_61 < 0 )
V_65 = - V_65 ;
}
V_63 = F_35 ( V_65 << 20 , V_62 ) ;
if ( V_61 < 0 )
V_63 += 0x200000 ;
V_13 = F_17 ( V_10 ) ;
if ( V_13 )
return V_13 ;
F_20 ( V_10 , L_15 ,
V_61 , V_65 , V_63 ) ;
F_12 ( V_10 , 7 , 4 , 0 , ( V_63 >> 16 ) & 0x1f ) ;
F_9 ( V_10 , 8 , V_63 >> 8 ) ;
F_9 ( V_10 , 9 , V_63 ) ;
return V_13 ;
}
static int F_38 ( struct V_1 * V_10 , V_58 V_19 ,
T_2 V_66 )
{
T_4 V_67 , V_68 ;
int V_13 ;
F_20 ( V_10 , L_16 ) ;
if ( F_39 ( V_10 ) )
V_68 = 128000 ;
else if ( F_40 ( V_10 ) )
V_68 = 228000 ;
else
return F_33 ( V_10 , V_19 ) ;
if ( F_41 ( V_10 ) == ( V_66 == V_69 ) )
V_67 = V_19 + V_68 ;
else
V_67 = V_19 - V_68 ;
V_13 = F_33 ( V_10 , V_67 ) ;
if ( V_13 )
return V_13 ;
return F_37 ( V_10 , - V_68 ) ;
}
static int F_42 ( struct V_1 * V_10 , V_58 V_19 , T_2 V_66 )
{
int V_13 ;
if ( F_28 ( V_10 ) )
V_13 = F_37 ( V_10 , V_19 ) ;
else
V_13 = F_38 ( V_10 , V_19 , V_66 ) ;
F_20 ( V_10 , L_17 , V_13 , V_19 ) ;
return V_13 ;
}
static int F_43 ( struct V_1 * V_10 , V_58 V_19 , T_2 V_70 )
{
int V_13 ;
V_13 = F_42 ( V_10 , V_19 , V_70 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_32 ( V_10 , V_71 ) ;
if ( V_13 )
return V_13 ;
F_20 ( V_10 , L_18 , V_10 -> V_19 , V_19 ) ;
V_10 -> V_19 = V_19 ;
return V_13 ;
}
static void F_44 ( struct V_1 * V_10 , T_2 V_66 )
{
F_20 ( V_10 , L_19 , V_66 ) ;
if ( ( V_66 == V_72 ) == F_41 ( V_10 ) )
F_14 ( V_10 , 5 , 4 , 1 ) ;
else
F_14 ( V_10 , 5 , 4 , 0 ) ;
}
static void F_45 ( struct V_1 * V_10 , T_2 V_73 )
{
switch ( V_73 ) {
case V_74 :
F_22 ( V_10 ) ;
break;
case V_75 :
F_24 ( V_10 ) ;
break;
}
if ( ! V_10 -> V_76 )
F_14 ( V_10 , 30 , 7 , 1 ) ;
}
static void F_46 ( struct V_1 * V_10 , T_2 V_73 )
{
switch ( V_73 ) {
case V_77 :
F_25 ( V_10 ) ;
break;
case V_78 :
F_26 ( V_10 ) ;
break;
}
if ( ! V_10 -> V_76 )
F_14 ( V_10 , 30 , 7 , 1 ) ;
V_10 -> V_31 = 27 ;
F_21 ( V_10 , V_32 , 0 , V_79 ) ;
F_21 ( V_10 , V_34 , 0 ,
V_80 ) ;
}
static int F_47 ( struct V_1 * V_10 , T_2 V_73 )
{
F_20 ( V_10 , L_20 , V_73 , V_10 -> V_81 ) ;
if ( V_10 -> V_57 == V_82 )
F_45 ( V_10 , V_73 ) ;
else
F_46 ( V_10 , V_73 ) ;
if ( V_10 -> V_81 ) {
F_20 ( V_10 , L_21 ) ;
F_14 ( V_10 , 50 , 5 , 1 ) ;
F_14 ( V_10 , 90 , 7 , 1 ) ;
F_12 ( V_10 , 73 , 1 , 0 , 2 ) ;
F_12 ( V_10 , 80 , 5 , 0 , 33 ) ;
}
F_27 ( V_10 ) ;
F_44 ( V_10 , V_10 -> V_70 -> V_83 . V_7 ) ;
F_19 ( V_10 , V_10 -> V_84 -> V_83 . V_7 ) ;
V_10 -> V_85 = true ;
return 0 ;
}
static int F_48 ( struct V_1 * V_10 , T_2 V_19 , T_2 * V_86 )
{
unsigned int V_27 ;
int V_55 = F_18 ( V_19 ) ;
for ( V_27 = 0 ; V_27 <= V_10 -> V_73 -> V_87 ; V_27 ++ ) {
if ( V_10 -> V_88 [ V_27 ] . V_55 == V_55 ) {
* V_86 = V_27 ;
F_20 ( V_10 , L_22 ,
V_19 , * V_86 ) ;
return 0 ;
}
}
return - V_89 ;
}
static bool F_49 ( struct V_1 * V_10 ,
T_2 V_86 , T_2 V_19 )
{
int V_55 = F_18 ( V_19 ) ;
return ( V_10 -> V_88 [ V_86 ] . V_55 == V_55 ) ;
}
static void F_50 ( struct V_1 * V_10 )
{
unsigned int V_27 , V_90 ;
for ( V_27 = 0 ; V_27 < F_23 ( V_91 ) ; V_27 ++ )
for ( V_90 = 0 ; V_90 < F_23 ( V_91 [ 0 ] ) ; V_90 ++ )
F_9 ( V_10 , 146 + V_90 + V_27 * 55 , V_91 [ V_27 ] [ V_90 ] ) ;
}
static int F_51 ( struct V_1 * V_10 )
{
int V_13 ;
F_14 ( V_10 , 99 , 2 , 0 ) ;
F_31 ( 1000 , 1500 ) ;
F_14 ( V_10 , 99 , 2 , 1 ) ;
V_13 = F_15 ( V_10 , 69 , 7 , 7 , 1 , 50000 ) ;
if ( V_13 )
F_8 ( V_10 , L_23 ) ;
return V_13 ;
}
static int F_52 ( struct V_1 * V_10 )
{
int V_13 ;
F_9 ( V_10 , 150 , 0xff ) ;
F_9 ( V_10 , 205 , 0xff ) ;
F_9 ( V_10 , 147 , 0x20 ) ;
F_9 ( V_10 , 147 , 0x00 ) ;
F_9 ( V_10 , 202 , 0x20 ) ;
F_9 ( V_10 , 202 , 0x00 ) ;
V_13 = F_15 ( V_10 , 69 , 4 , 3 , 3 , 50000 ) ;
if ( V_13 )
F_8 ( V_10 , L_24 ) ;
return V_13 ;
}
static T_1 F_53 ( struct V_1 * V_10 , T_1 V_92 )
{
T_1 V_93 = 0 ;
F_14 ( V_10 , 56 , 4 , 0 ) ;
F_12 ( V_10 , 56 , 3 , 0 , V_92 ) ;
F_31 ( 2000 , 2500 ) ;
F_6 ( V_10 , 58 , & V_93 ) ;
F_12 ( V_10 , 56 , 3 , 0 , 0 ) ;
F_20 ( V_10 , L_25 , V_92 , V_93 ) ;
return V_93 ;
}
static void F_54 ( struct V_1 * V_10 )
{
T_1 V_93 = 0 ;
V_93 = F_53 ( V_10 , 0 ) ;
V_10 -> V_40 = V_93 & 0x0f ;
F_12 ( V_10 , 81 , 3 , 0 , V_93 >> 4 ) ;
V_93 = F_53 ( V_10 , 1 ) ;
V_10 -> V_42 = V_93 & 0x0f ;
V_10 -> V_41 = V_93 >> 4 ;
V_93 = F_53 ( V_10 , 2 ) ;
F_12 ( V_10 , 82 , 4 , 0 , V_93 & 0x1f ) ;
F_12 ( V_10 , 82 , 7 , 5 , V_93 >> 5 ) ;
V_93 = F_53 ( V_10 , 3 ) ;
if ( V_10 -> V_81 ) {
V_93 &= 0x0f ;
V_93 |= ( F_53 ( V_10 , 7 ) & 0x40 ) >> 2 ;
if ( ! V_93 )
V_93 |= 2 ;
} else {
V_93 = ( V_93 & 0xf0 ) >> 4 ;
V_93 |= ( F_53 ( V_10 , 7 ) & 0x80 ) >> 3 ;
if ( ! V_93 )
V_93 |= 30 ;
}
F_12 ( V_10 , 80 , 5 , 0 , V_93 + 31 ) ;
V_93 = F_53 ( V_10 , 6 ) ;
F_12 ( V_10 , 81 , 7 , 6 , V_93 >> 6 ) ;
}
static void F_55 ( struct V_1 * V_10 )
{
unsigned int V_27 ;
for ( V_27 = 0 ; V_27 < F_23 ( V_94 ) ; V_27 ++ )
F_9 ( V_10 , V_27 + 1 , V_94 [ V_27 ] ) ;
F_31 ( 5000 , 5500 ) ;
V_10 -> V_31 = 36 ;
}
static void F_56 ( struct V_1 * V_10 )
{
unsigned int V_27 ;
for ( V_27 = 0 ; V_27 < F_23 ( V_95 ) ; V_27 ++ )
F_9 ( V_10 , V_27 + 1 , V_95 [ V_27 ] ) ;
F_31 ( 5000 , 5500 ) ;
V_10 -> V_31 = 27 ;
}
static int F_57 ( struct V_1 * V_10 , T_2 V_96 )
{
int V_13 ;
if ( V_10 -> V_57 == V_82 )
F_55 ( V_10 ) ;
else
F_56 ( V_10 ) ;
if ( ! V_10 -> V_76 )
F_14 ( V_10 , 30 , 7 , 1 ) ;
F_20 ( V_10 , L_26 , V_96 ) ;
F_12 ( V_10 , 56 , 7 , 5 , V_96 ) ;
F_14 ( V_10 , 99 , 1 , 0 ) ;
F_31 ( 1000 , 1500 ) ;
F_14 ( V_10 , 99 , 1 , 1 ) ;
F_50 ( V_10 ) ;
V_13 = F_51 ( V_10 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_52 ( V_10 ) ;
if ( V_13 )
return V_13 ;
F_54 ( V_10 ) ;
if ( V_10 -> V_57 == V_82 ) {
F_21 ( V_10 , V_32 , 0 ,
V_33 ) ;
F_21 ( V_10 , V_34 , 0 ,
V_35 ) ;
} else {
F_21 ( V_10 , V_32 , 0 ,
V_79 ) ;
F_21 ( V_10 , V_34 , 0 ,
V_80 ) ;
}
F_20 ( V_10 , L_27 ) ;
return 0 ;
}
static void F_58 ( struct V_1 * V_10 , T_2 V_73 )
{
F_47 ( V_10 , V_73 ) ;
F_20 ( V_10 , L_28 , V_73 , V_10 -> V_19 ) ;
if ( F_49 ( V_10 , V_73 , V_10 -> V_19 ) )
F_43 ( V_10 , V_10 -> V_19 , V_10 -> V_70 -> V_83 . V_7 ) ;
else
F_43 ( V_10 , V_10 -> V_88 [ V_73 ] . V_19 ,
V_10 -> V_70 -> V_83 . V_7 ) ;
}
static int F_59 ( struct V_97 * V_98 )
{
struct V_1 * V_10 = F_3 ( V_98 -> V_99 ) ;
F_20 ( V_10 , L_29 , V_98 -> V_100 , V_98 -> V_7 ) ;
switch ( V_98 -> V_100 ) {
case V_101 :
F_19 ( V_10 , V_98 -> V_7 ) ;
break;
case V_102 :
F_44 ( V_10 , V_98 -> V_7 ) ;
break;
case V_103 :
F_58 ( V_10 , V_98 -> V_7 ) ;
break;
}
return 0 ;
}
static T_2 F_60 ( struct V_1 * V_10 )
{
enum V_54 V_55 = F_11 ( V_10 , 5 , 1 , 0 ) ;
switch ( V_55 ) {
case V_20 :
return F_11 ( V_10 , 51 , 3 , 0 ) ;
case V_21 :
return F_11 ( V_10 , 50 , 3 , 0 ) ;
case V_22 :
return F_11 ( V_10 , 52 , 5 , 0 ) ;
default:
return 0 ;
}
}
static int F_61 ( struct V_97 * V_98 )
{
struct V_1 * V_10 = F_3 ( V_98 -> V_99 ) ;
switch ( V_98 -> V_100 ) {
case V_104 :
V_98 -> V_7 = F_60 ( V_10 ) ;
break;
case V_105 :
V_98 -> V_7 = F_11 ( V_10 , 49 , 4 , 0 ) ;
break;
case V_106 :
V_98 -> V_7 = ( F_11 ( V_10 , 60 , 7 , 6 ) == 3 ) ;
break;
}
return 0 ;
}
static int F_62 ( struct V_1 * V_10 , T_2 V_19 )
{
T_2 V_73 ;
int V_13 ;
V_13 = F_48 ( V_10 , V_19 , & V_73 ) ;
if ( V_13 )
return V_13 ;
F_20 ( V_10 , L_30 , V_19 , V_73 ) ;
F_47 ( V_10 , V_73 ) ;
V_10 -> V_73 -> V_83 . V_7 = V_73 ;
return F_43 ( V_10 , V_19 , V_10 -> V_70 -> V_83 . V_7 ) ;
}
static int F_63 ( struct V_2 * V_3 ,
const struct V_107 * V_108 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
T_2 V_19 ;
int V_13 = 0 ;
F_20 ( V_10 , L_31 ,
V_108 -> V_109 , V_10 -> V_19 , V_10 -> V_85 ) ;
if ( V_108 -> V_110 != 0 )
return - V_89 ;
V_19 = F_64 ( V_108 -> V_109 , V_10 -> V_111 -> V_112 ,
V_10 -> V_111 -> V_113 ) ;
if ( V_10 -> V_85 &&
F_49 ( V_10 , V_10 -> V_73 -> V_83 . V_7 , V_19 ) )
V_13 = F_43 ( V_10 , V_19 , V_10 -> V_70 -> V_83 . V_7 ) ;
else
V_13 = F_62 ( V_10 , V_19 ) ;
F_20 ( V_10 , L_32 ,
V_13 , V_10 -> V_19 , V_10 -> V_85 , V_10 -> V_73 -> V_83 . V_7 ) ;
return V_13 ;
}
static int F_65 ( struct V_2 * V_3 ,
struct V_107 * V_108 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
int V_13 = 0 ;
if ( V_108 -> V_110 != 0 )
return - V_89 ;
V_108 -> type = V_114 ;
V_108 -> V_109 = V_10 -> V_19 ;
return V_13 ;
}
static int F_66 ( struct V_2 * V_3 ,
struct V_115 * V_55 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
if ( V_55 -> V_110 != 0 || V_55 -> V_116 != 0 )
return - V_89 ;
* V_55 = * V_10 -> V_111 ;
return 0 ;
}
static int F_67 ( struct V_2 * V_3 , struct V_117 * V_118 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
if ( V_118 -> V_116 > 0 )
return - V_89 ;
F_68 ( V_118 -> V_119 , L_33 , sizeof( V_118 -> V_119 ) ) ;
V_118 -> type = V_114 ;
V_118 -> V_120 = V_121 | V_122 ;
V_118 -> V_112 = V_10 -> V_111 -> V_112 ;
V_118 -> V_113 = V_10 -> V_111 -> V_113 ;
return 0 ;
}
static int F_69 ( struct V_2 * V_3 , const struct V_117 * V_118 )
{
if ( V_118 -> V_116 > 0 )
return - V_89 ;
return 0 ;
}
static int F_70 ( struct V_123 * V_124 , T_2 V_125 ,
T_2 * V_126 )
{
if ( V_125 <= 40 )
* V_126 = V_125 / 10 ;
else if ( V_125 >= 60 && V_125 <= 70 )
* V_126 = V_125 / 10 - 1 ;
else
return - V_89 ;
return 0 ;
}
static int F_71 ( struct V_123 * V_124 ,
const struct V_127 * V_100 )
{
bool V_76 = true , V_81 = false ;
T_2 V_128 , V_96 = 0 ;
struct V_4 * V_129 ;
struct V_130 * V_131 ;
struct V_132 * V_133 ;
struct V_2 * V_3 ;
struct V_14 * V_14 ;
struct V_1 * V_10 ;
struct V_134 * V_134 ;
int V_13 ;
V_133 = F_72 ( V_124 -> V_135 . V_136 , L_34 , 0 ) ;
if ( V_133 ) {
V_76 = false ;
F_73 ( V_133 ) ;
}
V_131 = F_74 ( V_124 -> V_135 . V_136 ) ;
if ( F_75 ( V_131 , L_35 ) )
V_81 = true ;
if ( ! F_76 ( V_131 , L_36 ,
& V_128 ) ) {
V_13 = F_70 ( V_124 , V_128 ,
& V_96 ) ;
if ( V_13 ) {
F_77 ( & V_124 -> V_135 , L_37 ,
V_128 ) ;
return - V_89 ;
}
}
V_134 = F_78 ( & V_124 -> V_135 , NULL ) ;
if ( F_79 ( V_134 ) ) {
V_13 = F_80 ( V_134 ) ;
F_77 ( & V_124 -> V_135 , L_38 , V_13 ) ;
return V_13 ;
}
V_14 = F_81 ( V_124 , & V_137 ) ;
if ( F_79 ( V_14 ) ) {
V_13 = F_80 ( V_14 ) ;
F_77 ( & V_124 -> V_135 , L_39 , V_13 ) ;
return - V_138 ;
}
V_10 = F_82 ( & V_124 -> V_135 , sizeof( * V_10 ) , V_139 ) ;
if ( V_10 == NULL )
return - V_140 ;
V_3 = & V_10 -> V_3 ;
V_10 -> V_76 = V_76 ;
V_10 -> V_81 = V_81 ;
V_10 -> V_85 = false ;
V_10 -> V_14 = V_14 ;
V_10 -> V_57 = F_83 ( V_134 ) ;
F_84 ( & V_124 -> V_135 , L_40 , V_10 -> V_57 ) ;
F_85 ( V_3 , V_124 , & V_141 ) ;
V_10 -> V_124 = V_124 ;
V_3 -> V_142 = V_143 ;
V_129 = & V_10 -> V_6 ;
V_13 = F_86 ( V_129 , 7 ) ;
if ( V_13 )
return V_13 ;
V_10 -> V_144 = F_87 ( V_129 , & V_145 ,
V_104 ,
0 , 63 , 1 , 0 ) ;
V_10 -> V_144 -> V_142 |= ( V_146 |
V_147 ) ;
V_10 -> V_148 = F_87 ( V_129 , & V_145 ,
V_105 ,
0 , 31 , 1 , 0 ) ;
V_10 -> V_148 -> V_142 |= ( V_146 |
V_147 ) ;
V_10 -> V_149 = F_87 ( V_129 , & V_145 ,
V_106 ,
0 , 1 , 1 , 0 ) ;
V_10 -> V_149 -> V_142 |= ( V_146 |
V_147 ) ;
V_10 -> V_84 = F_88 ( V_129 , & V_150 , NULL ) ;
V_10 -> V_70 = F_88 ( V_129 , & V_151 , NULL ) ;
if ( V_10 -> V_57 == V_82 ) {
V_10 -> V_73 = F_88 ( V_129 ,
& V_152 , NULL ) ;
V_10 -> V_88 = V_153 ;
V_10 -> V_111 = & V_154 ;
} else {
V_10 -> V_73 = F_88 ( V_129 ,
& V_155 , NULL ) ;
V_10 -> V_88 = V_156 ;
V_10 -> V_111 = & V_157 ;
}
V_10 -> V_3 . V_158 = & V_10 -> V_6 ;
V_10 -> V_19 = V_10 -> V_111 -> V_112 ;
V_13 = F_89 ( V_3 ) ;
if ( V_13 ) {
F_77 ( & V_124 -> V_135 , L_41 ) ;
goto V_159;
}
V_13 = F_57 ( V_10 , V_96 ) ;
if ( V_13 )
goto V_160;
V_13 = F_90 ( V_129 ) ;
if ( V_13 )
goto V_160;
return 0 ;
V_160:
F_91 ( V_3 ) ;
V_159:
F_92 ( & V_10 -> V_6 ) ;
return V_13 ;
}
static int F_93 ( struct V_123 * V_124 )
{
struct V_2 * V_3 = F_94 ( V_124 ) ;
struct V_1 * V_10 = F_1 ( V_3 ) ;
F_92 ( & V_10 -> V_6 ) ;
F_91 ( V_3 ) ;
return 0 ;
}
