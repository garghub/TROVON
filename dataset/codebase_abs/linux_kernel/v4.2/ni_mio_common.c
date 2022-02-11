static inline unsigned F_1 ( unsigned V_1 )
{
switch ( V_1 ) {
case 0 :
return V_2 ;
case 1 :
return V_3 ;
default:
break;
}
F_2 () ;
return V_2 ;
}
static void F_3 ( struct V_4 * V_5 , T_1 V_6 , int V_7 )
{
if ( V_5 -> V_8 )
F_4 ( V_6 , V_5 -> V_8 + V_7 ) ;
F_5 ( V_6 , V_5 -> V_9 + V_7 ) ;
}
static void F_6 ( struct V_4 * V_5 , T_2 V_6 , int V_7 )
{
if ( V_5 -> V_8 )
F_7 ( V_6 , V_5 -> V_8 + V_7 ) ;
F_8 ( V_6 , V_5 -> V_9 + V_7 ) ;
}
static void F_9 ( struct V_4 * V_5 , T_3 V_6 , int V_7 )
{
if ( V_5 -> V_8 )
F_10 ( V_6 , V_5 -> V_8 + V_7 ) ;
F_11 ( V_6 , V_5 -> V_9 + V_7 ) ;
}
static T_1 F_12 ( struct V_4 * V_5 , int V_7 )
{
if ( V_5 -> V_8 )
return F_13 ( V_5 -> V_8 + V_7 ) ;
return F_14 ( V_5 -> V_9 + V_7 ) ;
}
static T_2 F_15 ( struct V_4 * V_5 , int V_7 )
{
if ( V_5 -> V_8 )
return F_16 ( V_5 -> V_8 + V_7 ) ;
return F_17 ( V_5 -> V_9 + V_7 ) ;
}
static T_3 F_18 ( struct V_4 * V_5 , int V_7 )
{
if ( V_5 -> V_8 )
return F_19 ( V_5 -> V_8 + V_7 ) ;
return F_20 ( V_5 -> V_9 + V_7 ) ;
}
static void F_21 ( struct V_4 * V_5 ,
unsigned int V_6 , unsigned int V_7 )
{
const struct V_10 * V_11 ;
if ( V_7 < F_22 ( V_12 ) ) {
V_11 = & V_12 [ V_7 ] ;
} else {
F_23 ( V_5 -> V_13 , L_1 ,
V_14 , V_7 ) ;
return;
}
switch ( V_11 -> V_15 ) {
case 4 :
F_3 ( V_5 , V_6 , V_11 -> V_16 ) ;
break;
case 2 :
F_6 ( V_5 , V_6 , V_11 -> V_16 ) ;
break;
default:
F_23 ( V_5 -> V_13 , L_2 ,
V_14 , V_7 ) ;
break;
}
}
static unsigned int F_24 ( struct V_4 * V_5 ,
unsigned int V_7 )
{
const struct V_10 * V_11 ;
if ( V_7 < F_22 ( V_17 ) ) {
V_11 = & V_17 [ V_7 ] ;
} else {
F_23 ( V_5 -> V_13 , L_1 ,
V_14 , V_7 ) ;
return 0 ;
}
switch ( V_11 -> V_15 ) {
case 4 :
return F_12 ( V_5 , V_11 -> V_16 ) ;
case 2 :
return F_15 ( V_5 , V_11 -> V_16 ) ;
case 1 :
return F_18 ( V_5 , V_11 -> V_16 ) ;
default:
F_23 ( V_5 -> V_13 , L_2 ,
V_14 , V_7 ) ;
return 0 ;
}
}
static void F_25 ( struct V_4 * V_5 , T_2 V_6 , int V_7 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned long V_21 ;
if ( V_19 -> V_22 ) {
F_21 ( V_5 , V_6 , V_7 ) ;
} else {
F_26 ( & V_19 -> V_23 , V_21 ) ;
if ( ! V_19 -> V_24 && V_7 < 8 ) {
F_6 ( V_5 , V_6 , V_7 * 2 ) ;
} else {
F_6 ( V_5 , V_7 , V_25 ) ;
F_6 ( V_5 , V_6 , V_26 ) ;
}
F_27 ( & V_19 -> V_23 , V_21 ) ;
}
}
static void F_28 ( struct V_4 * V_5 , T_1 V_6 , int V_7 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
if ( V_19 -> V_22 ) {
F_21 ( V_5 , V_6 , V_7 ) ;
} else {
F_25 ( V_5 , V_6 >> 16 , V_7 ) ;
F_25 ( V_5 , V_6 & 0xffff , V_7 + 1 ) ;
}
}
static T_2 F_29 ( struct V_4 * V_5 , int V_7 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned long V_21 ;
T_2 V_27 ;
if ( V_19 -> V_22 ) {
V_27 = F_24 ( V_5 , V_7 ) ;
} else {
F_26 ( & V_19 -> V_23 , V_21 ) ;
if ( ! V_19 -> V_24 && V_7 < 8 ) {
V_27 = F_15 ( V_5 , V_7 * 2 ) ;
} else {
F_6 ( V_5 , V_7 , V_25 ) ;
V_27 = F_15 ( V_5 , V_26 ) ;
}
F_27 ( & V_19 -> V_23 , V_21 ) ;
}
return V_27 ;
}
static T_1 F_30 ( struct V_4 * V_5 , int V_7 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
T_1 V_27 ;
if ( V_19 -> V_22 ) {
V_27 = F_24 ( V_5 , V_7 ) ;
} else {
V_27 = F_29 ( V_5 , V_7 ) << 16 ;
V_27 |= F_29 ( V_5 , V_7 + 1 ) ;
}
return V_27 ;
}
static inline void F_31 ( struct V_4 * V_5 , int V_7 ,
unsigned V_28 , unsigned V_29 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned long V_21 ;
F_26 ( & V_19 -> V_30 , V_21 ) ;
switch ( V_7 ) {
case V_31 :
V_19 -> V_32 &= ~ V_28 ;
V_19 -> V_32 |= V_29 & V_28 ;
F_25 ( V_5 , V_19 -> V_32 , V_7 ) ;
break;
case V_33 :
V_19 -> V_34 &= ~ V_28 ;
V_19 -> V_34 |= V_29 & V_28 ;
F_25 ( V_5 , V_19 -> V_34 , V_7 ) ;
break;
case V_35 :
V_19 -> V_36 &= ~ V_28 ;
V_19 -> V_36 |= V_29 & V_28 ;
F_25 ( V_5 , V_19 -> V_36 , V_7 ) ;
break;
case V_37 :
V_19 -> V_38 &= ~ V_28 ;
V_19 -> V_38 |= V_29 & V_28 ;
F_9 ( V_5 , V_19 -> V_38 , V_7 ) ;
break;
case V_39 :
V_19 -> V_40 &= ~ V_28 ;
V_19 -> V_40 |= V_29 & V_28 ;
F_9 ( V_5 , V_19 -> V_40 , V_7 ) ;
break;
default:
F_32 ( V_5 -> V_13 , L_3 ,
V_7 ) ;
break;
}
F_33 () ;
F_27 ( & V_19 -> V_30 , V_21 ) ;
}
static inline unsigned F_34 ( unsigned V_41 )
{
if ( V_41 < 4 )
return 1 << V_41 ;
if ( V_41 == 4 )
return 0x3 ;
if ( V_41 == 5 )
return 0x5 ;
F_2 () ;
return 0 ;
}
static inline void F_35 ( struct V_4 * V_5 , int V_41 )
{
unsigned V_42 = 0 ;
if ( V_41 >= 0 )
V_42 = F_34 ( V_41 ) ;
F_31 ( V_5 , V_37 ,
V_43 , F_36 ( V_42 ) ) ;
}
static inline void F_37 ( struct V_4 * V_5 , int V_41 )
{
unsigned V_42 = 0 ;
if ( V_41 >= 0 )
V_42 = F_34 ( V_41 ) ;
F_31 ( V_5 , V_37 ,
V_44 , F_38 ( V_42 ) ) ;
}
static inline void F_39 ( struct V_4 * V_5 ,
unsigned V_45 ,
int V_41 )
{
unsigned V_42 = 0 ;
if ( V_41 >= 0 )
V_42 = F_34 ( V_41 ) ;
F_31 ( V_5 , V_39 ,
F_40 ( V_45 ) ,
F_41 ( V_45 , V_42 ) ) ;
}
static inline void F_42 ( struct V_4 * V_5 ,
int V_46 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned long V_21 ;
unsigned V_42 ;
F_26 ( & V_19 -> V_30 , V_21 ) ;
V_19 -> V_47 &= ~ V_48 ;
if ( V_46 >= 0 ) {
V_42 = F_34 ( V_46 ) ;
V_19 -> V_47 |= F_43 ( V_42 ) ;
}
F_9 ( V_5 , V_19 -> V_47 , V_49 ) ;
F_33 () ;
F_27 ( & V_19 -> V_30 , V_21 ) ;
}
static int F_44 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned long V_21 ;
F_26 ( & V_19 -> V_50 , V_21 ) ;
F_45 ( V_19 -> V_51 ) ;
V_19 -> V_51 =
F_46 ( V_19 -> V_24 , V_19 -> V_52 ) ;
if ( ! V_19 -> V_51 ) {
F_27 ( & V_19 -> V_50 , V_21 ) ;
F_32 ( V_5 -> V_13 ,
L_4 ) ;
return - V_53 ;
}
V_19 -> V_51 -> V_54 = V_55 ;
F_35 ( V_5 , V_19 -> V_51 -> V_41 ) ;
F_27 ( & V_19 -> V_50 , V_21 ) ;
return 0 ;
}
static int F_47 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned long V_21 ;
F_26 ( & V_19 -> V_50 , V_21 ) ;
F_45 ( V_19 -> V_56 ) ;
V_19 -> V_56 =
F_46 ( V_19 -> V_24 , V_19 -> V_57 ) ;
if ( ! V_19 -> V_56 ) {
F_27 ( & V_19 -> V_50 , V_21 ) ;
F_32 ( V_5 -> V_13 ,
L_5 ) ;
return - V_53 ;
}
V_19 -> V_56 -> V_54 = V_58 ;
F_37 ( V_5 , V_19 -> V_56 -> V_41 ) ;
F_27 ( & V_19 -> V_50 , V_21 ) ;
return 0 ;
}
static int F_48 ( struct V_4 * V_5 ,
unsigned V_45 ,
enum V_59 V_60 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned long V_21 ;
struct V_46 * V_61 ;
F_26 ( & V_19 -> V_50 , V_21 ) ;
F_45 ( V_19 -> V_62 -> V_63 [ V_45 ] . V_61 ) ;
V_61 =
F_46 ( V_19 -> V_24 ,
V_19 -> V_64 [ V_45 ] ) ;
if ( ! V_61 ) {
F_27 ( & V_19 -> V_50 , V_21 ) ;
F_32 ( V_5 -> V_13 ,
L_6 ) ;
return - V_53 ;
}
V_61 -> V_54 = V_60 ;
F_49 ( & V_19 -> V_62 -> V_63 [ V_45 ] ,
V_61 ) ;
F_39 ( V_5 , V_45 , V_61 -> V_41 ) ;
F_27 ( & V_19 -> V_50 , V_21 ) ;
return 0 ;
}
static int F_50 ( struct V_4 * V_5 )
{
#ifdef F_51
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned long V_21 ;
F_26 ( & V_19 -> V_50 , V_21 ) ;
F_45 ( V_19 -> V_65 ) ;
V_19 -> V_65 =
F_46 ( V_19 -> V_24 , V_19 -> V_66 ) ;
if ( ! V_19 -> V_65 ) {
F_27 ( & V_19 -> V_50 , V_21 ) ;
F_32 ( V_5 -> V_13 ,
L_7 ) ;
return - V_53 ;
}
V_19 -> V_65 -> V_54 = V_58 ;
F_42 ( V_5 , V_19 -> V_65 -> V_41 ) ;
F_27 ( & V_19 -> V_50 , V_21 ) ;
#endif
return 0 ;
}
static void F_52 ( struct V_4 * V_5 )
{
#ifdef F_51
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned long V_21 ;
F_26 ( & V_19 -> V_50 , V_21 ) ;
if ( V_19 -> V_51 ) {
F_35 ( V_5 , - 1 ) ;
F_53 ( V_19 -> V_51 ) ;
V_19 -> V_51 = NULL ;
}
F_27 ( & V_19 -> V_50 , V_21 ) ;
#endif
}
static void F_54 ( struct V_4 * V_5 )
{
#ifdef F_51
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned long V_21 ;
F_26 ( & V_19 -> V_50 , V_21 ) ;
if ( V_19 -> V_56 ) {
F_37 ( V_5 , - 1 ) ;
F_53 ( V_19 -> V_56 ) ;
V_19 -> V_56 = NULL ;
}
F_27 ( & V_19 -> V_50 , V_21 ) ;
#endif
}
static void F_55 ( struct V_4 * V_5 ,
unsigned V_45 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned long V_21 ;
F_26 ( & V_19 -> V_50 , V_21 ) ;
if ( V_19 -> V_62 -> V_63 [ V_45 ] . V_61 ) {
struct V_46 * V_61 =
V_19 -> V_62 -> V_63 [ V_45 ] . V_61 ;
F_39 ( V_5 , V_45 , - 1 ) ;
F_49 ( & V_19 ->
V_62 -> V_63 [ V_45 ] ,
NULL ) ;
F_53 ( V_61 ) ;
}
F_27 ( & V_19 -> V_50 , V_21 ) ;
}
static void F_56 ( struct V_4 * V_5 )
{
#ifdef F_51
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned long V_21 ;
F_26 ( & V_19 -> V_50 , V_21 ) ;
if ( V_19 -> V_65 ) {
F_42 ( V_5 , - 1 ) ;
F_53 ( V_19 -> V_65 ) ;
V_19 -> V_65 = NULL ;
}
F_27 ( & V_19 -> V_50 , V_21 ) ;
#endif
}
static void F_57 ( struct V_4 * V_5 ,
unsigned V_45 , short V_67 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
T_2 V_27 = 0 ;
int V_7 ;
if ( V_19 -> V_22 || V_45 > 1 )
return;
if ( V_45 == 0 ) {
V_7 = V_68 ;
if ( V_67 )
V_27 = V_69 ;
} else {
V_7 = V_70 ;
if ( V_67 )
V_27 = V_71 ;
}
F_25 ( V_5 , V_27 , V_7 ) ;
}
static void F_58 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
static const int V_72 = 10000 ;
int V_73 ;
if ( V_19 -> V_74 ) {
F_3 ( V_5 , 0x10 , V_75 ) ;
F_3 ( V_5 , 0x00 , V_75 ) ;
for ( V_73 = 0 ; V_73 < V_72 ; V_73 ++ ) {
if ( ! ( F_12 ( V_5 , V_76 ) & 0x10 ) )
break;
F_59 ( 1 ) ;
}
if ( V_73 == V_72 )
F_32 ( V_5 -> V_13 , L_8 ) ;
} else {
F_25 ( V_5 , 1 , V_77 ) ;
if ( V_19 -> V_78 ) {
F_9 ( V_5 , 0 , F_60 ( 0 ) ) ;
F_9 ( V_5 , 1 , F_60 ( 0 ) ) ;
#if 0
ni_stc_writew(dev, NISTC_AI_CMD1_CONVERT_PULSE,
NISTC_AI_CMD1_REG);
ni_stc_writew(dev, NISTC_AI_CMD1_CONVERT_PULSE,
NISTC_AI_CMD1_REG);
ni_stc_writew(dev, NISTC_AI_CMD1_CONVERT_PULSE,
NISTC_AI_CMD1_REG);
#endif
}
}
}
static inline void F_61 ( struct V_4 * V_5 , T_2 V_6 ,
int V_79 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned long V_21 ;
F_26 ( & V_19 -> V_23 , V_21 ) ;
F_6 ( V_5 , V_79 , V_80 ) ;
F_6 ( V_5 , V_6 , V_81 ) ;
F_27 ( & V_19 -> V_23 , V_21 ) ;
}
static inline void F_62 ( struct V_4 * V_5 , T_1 V_6 ,
int V_79 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned long V_21 ;
F_26 ( & V_19 -> V_23 , V_21 ) ;
F_6 ( V_5 , V_79 , V_80 ) ;
F_3 ( V_5 , V_6 , V_81 ) ;
F_27 ( & V_19 -> V_23 , V_21 ) ;
}
static inline unsigned short F_63 ( struct V_4 * V_5 , int V_79 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned long V_21 ;
unsigned short V_6 ;
F_26 ( & V_19 -> V_23 , V_21 ) ;
F_6 ( V_5 , V_79 , V_80 ) ;
V_6 = F_15 ( V_5 , V_81 ) ;
F_27 ( & V_19 -> V_23 , V_21 ) ;
return V_6 ;
}
static inline void F_64 ( struct V_4 * V_5 , int V_7 ,
unsigned V_42 , unsigned V_82 )
{
unsigned V_29 ;
if ( V_82 )
V_29 = V_42 ;
else
V_29 = 0 ;
F_31 ( V_5 , V_7 , V_42 , V_29 ) ;
}
static void F_65 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
struct V_83 * V_84 = V_5 -> V_85 ;
unsigned long V_21 ;
F_26 ( & V_19 -> V_50 , V_21 ) ;
if ( V_19 -> V_51 )
F_66 ( V_19 -> V_51 , V_84 ) ;
F_27 ( & V_19 -> V_50 , V_21 ) ;
}
static int F_67 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
int V_73 ;
static const int V_72 = 10000 ;
unsigned long V_21 ;
int V_86 = 0 ;
F_26 ( & V_19 -> V_50 , V_21 ) ;
if ( V_19 -> V_51 ) {
for ( V_73 = 0 ; V_73 < V_72 ; V_73 ++ ) {
if ( ( F_29 ( V_5 , V_87 ) &
V_88 )
&& F_68 ( V_19 -> V_51 ) ==
0 )
break;
F_59 ( 5 ) ;
}
if ( V_73 == V_72 ) {
F_32 ( V_5 -> V_13 , L_9 ) ;
F_32 ( V_5 -> V_13 ,
L_10 ,
F_68 ( V_19 -> V_51 ) ,
F_29 ( V_5 , V_87 ) ) ;
V_86 = - 1 ;
}
}
F_27 ( & V_19 -> V_50 , V_21 ) ;
F_65 ( V_5 ) ;
return V_86 ;
}
static void F_69 ( struct V_89 * V_24 ,
struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
struct V_83 * V_84 = V_5 -> V_90 ;
unsigned long V_21 ;
F_26 ( & V_19 -> V_50 , V_21 ) ;
if ( V_19 -> V_56 )
F_70 ( V_19 -> V_56 , V_84 ) ;
F_27 ( & V_19 -> V_50 , V_21 ) ;
}
static int F_71 ( struct V_4 * V_5 )
{
static const int V_72 = 10000 ;
int V_73 ;
for ( V_73 = 0 ; V_73 < V_72 ; V_73 ++ ) {
unsigned short V_91 ;
V_91 = F_29 ( V_5 , V_92 ) ;
if ( V_91 & V_93 )
break;
F_59 ( 10 ) ;
}
if ( V_73 == V_72 ) {
F_32 ( V_5 -> V_13 , L_11 ) ;
return - V_94 ;
}
return 0 ;
}
static void F_72 ( struct V_4 * V_5 ,
struct V_83 * V_84 , int V_95 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
int V_73 ;
unsigned short V_96 ;
T_4 V_97 ;
for ( V_73 = 0 ; V_73 < V_95 ; V_73 ++ ) {
F_73 ( V_84 , & V_96 , 1 ) ;
if ( V_19 -> V_98 ) {
V_97 = V_96 & 0xffff ;
if ( ! V_19 -> V_99 ) {
F_73 ( V_84 , & V_96 , 1 ) ;
V_73 ++ ;
V_97 |= ( V_96 << 16 ) & 0xffff0000 ;
}
F_3 ( V_5 , V_97 , V_100 ) ;
} else {
F_6 ( V_5 , V_96 , V_101 ) ;
}
}
}
static int F_74 ( struct V_4 * V_5 ,
struct V_83 * V_84 )
{
const struct V_102 * V_103 = V_5 -> V_104 ;
unsigned int V_105 ;
unsigned int V_106 ;
V_105 = F_75 ( V_84 ) ;
if ( V_105 == 0 ) {
V_84 -> V_107 -> V_108 |= V_109 ;
return 0 ;
}
V_106 = F_76 ( V_84 , V_105 ) ;
if ( V_106 > V_103 -> V_110 / 2 )
V_106 = V_103 -> V_110 / 2 ;
F_72 ( V_5 , V_84 , V_106 ) ;
return 1 ;
}
static int F_77 ( struct V_4 * V_5 ,
struct V_83 * V_84 )
{
const struct V_102 * V_103 = V_5 -> V_104 ;
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_105 ;
unsigned int V_106 ;
F_25 ( V_5 , 1 , V_111 ) ;
if ( V_19 -> V_98 )
F_62 ( V_5 , 0x6 , V_112 ) ;
V_105 = F_75 ( V_84 ) ;
if ( V_105 == 0 )
return 0 ;
V_106 = F_76 ( V_84 , V_105 ) ;
if ( V_106 > V_103 -> V_110 )
V_106 = V_103 -> V_110 ;
F_72 ( V_5 , V_84 , V_106 ) ;
return V_106 ;
}
static void F_78 ( struct V_4 * V_5 ,
struct V_83 * V_84 , int V_95 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
struct V_113 * V_107 = V_84 -> V_107 ;
T_4 V_114 ;
unsigned short V_6 ;
int V_73 ;
if ( V_19 -> V_115 ) {
for ( V_73 = 0 ; V_73 < V_95 / 2 ; V_73 ++ ) {
V_114 = F_12 ( V_5 , V_116 ) ;
V_6 = ( V_114 >> 16 ) & 0xffff ;
F_79 ( V_84 , & V_6 , 1 ) ;
V_6 = V_114 & 0xffff ;
F_79 ( V_84 , & V_6 , 1 ) ;
}
if ( V_95 % 2 ) {
V_114 = F_12 ( V_5 , V_116 ) ;
V_6 = V_114 & 0xffff ;
F_79 ( V_84 , & V_6 , 1 ) ;
}
} else if ( V_19 -> V_74 ) {
for ( V_73 = 0 ; V_73 < V_95 / 2 ; V_73 ++ ) {
V_114 = F_12 ( V_5 , V_117 ) ;
V_6 = ( V_114 >> 16 ) & 0xffff ;
F_79 ( V_84 , & V_6 , 1 ) ;
V_6 = V_114 & 0xffff ;
F_79 ( V_84 , & V_6 , 1 ) ;
}
if ( V_95 % 2 ) {
F_3 ( V_5 , 0x01 , V_75 ) ;
V_114 = F_12 ( V_5 , V_117 ) ;
V_6 = ( V_114 >> 16 ) & 0xffff ;
F_79 ( V_84 , & V_6 , 1 ) ;
}
} else {
if ( V_95 > sizeof( V_19 -> V_118 ) /
sizeof( V_19 -> V_118 [ 0 ] ) ) {
F_32 ( V_5 -> V_13 ,
L_12 ) ;
V_107 -> V_108 |= V_119 ;
return;
}
for ( V_73 = 0 ; V_73 < V_95 ; V_73 ++ ) {
V_19 -> V_118 [ V_73 ] =
F_15 ( V_5 , V_120 ) ;
}
F_79 ( V_84 , V_19 -> V_118 , V_95 ) ;
}
}
static void F_80 ( struct V_4 * V_5 )
{
const struct V_102 * V_103 = V_5 -> V_104 ;
struct V_83 * V_84 = V_5 -> V_85 ;
int V_95 ;
V_95 = V_103 -> V_121 / 2 ;
F_78 ( V_5 , V_84 , V_95 ) ;
}
static void F_81 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
struct V_83 * V_84 = V_5 -> V_85 ;
T_4 V_114 ;
unsigned short V_6 ;
unsigned short V_122 ;
int V_73 ;
if ( V_19 -> V_115 ) {
while ( ( F_29 ( V_5 , V_87 ) &
V_88 ) == 0 ) {
V_114 = F_12 ( V_5 , V_116 ) ;
V_6 = V_114 >> 16 ;
F_79 ( V_84 , & V_6 , 1 ) ;
V_6 = V_114 & 0xffff ;
F_79 ( V_84 , & V_6 , 1 ) ;
}
} else if ( V_19 -> V_74 ) {
V_73 = 0 ;
while ( F_12 ( V_5 , V_76 ) & 0x04 ) {
V_114 = F_12 ( V_5 , V_117 ) ;
V_6 = V_114 >> 16 ;
F_79 ( V_84 , & V_6 , 1 ) ;
V_6 = V_114 & 0xffff ;
F_79 ( V_84 , & V_6 , 1 ) ;
V_73 += 2 ;
}
if ( F_12 ( V_5 , V_76 ) & 0x01 ) {
F_3 ( V_5 , 0x01 , V_75 ) ;
V_114 = F_12 ( V_5 , V_117 ) ;
V_6 = ( V_114 >> 16 ) & 0xffff ;
F_79 ( V_84 , & V_6 , 1 ) ;
}
} else {
V_122 = F_29 ( V_5 , V_87 ) &
V_88 ;
while ( V_122 == 0 ) {
for ( V_73 = 0 ;
V_73 <
sizeof( V_19 -> V_118 ) /
sizeof( V_19 -> V_118 [ 0 ] ) ; V_73 ++ ) {
V_122 = F_29 ( V_5 ,
V_87 ) &
V_88 ;
if ( V_122 )
break;
V_19 -> V_118 [ V_73 ] =
F_15 ( V_5 , V_120 ) ;
}
F_79 ( V_84 , V_19 -> V_118 , V_73 ) ;
}
}
}
static void F_82 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
struct V_83 * V_84 = V_5 -> V_85 ;
unsigned short V_6 ;
T_4 V_114 ;
if ( ! V_19 -> V_115 )
return;
if ( F_18 ( V_5 , V_123 ) & 0x80 ) {
V_114 = F_12 ( V_5 , V_116 ) ;
V_6 = V_114 & 0xffff ;
F_79 ( V_84 , & V_6 , 1 ) ;
}
}
static void F_83 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
struct V_83 * V_84 = V_5 -> V_85 ;
unsigned short V_6 ;
T_4 V_114 ;
if ( ! V_19 -> V_74 )
return;
if ( F_12 ( V_5 , V_76 ) & 0x01 ) {
F_3 ( V_5 , 0x01 , V_75 ) ;
V_114 = F_12 ( V_5 , V_117 ) ;
V_6 = ( V_114 >> 16 ) & 0xffff ;
F_79 ( V_84 , & V_6 , 1 ) ;
}
}
static void F_84 ( struct V_4 * V_5 )
{
struct V_83 * V_84 = V_5 -> V_85 ;
#ifdef F_51
F_67 ( V_5 ) ;
#endif
F_81 ( V_5 ) ;
F_82 ( V_5 ) ;
F_83 ( V_5 ) ;
V_84 -> V_107 -> V_108 |= V_124 ;
}
static void F_85 ( struct V_4 * V_5 , struct V_83 * V_84 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
if ( V_19 -> V_125 == V_126 ) {
#ifdef F_51
static const int V_72 = 10 ;
int V_73 ;
for ( V_73 = 0 ; V_73 < V_72 ; V_73 ++ ) {
F_65 ( V_5 ) ;
if ( ( V_84 -> V_107 -> V_108 & V_127 ) )
break;
F_59 ( 1 ) ;
}
#else
F_81 ( V_5 ) ;
V_84 -> V_107 -> V_108 |= V_127 ;
#endif
}
if ( V_19 -> V_128 & V_129 )
F_84 ( V_5 ) ;
}
static void F_86 ( struct V_4 * V_5 ,
unsigned short V_1 )
{
#ifdef F_51
struct V_18 * V_19 = V_5 -> V_20 ;
struct V_83 * V_84 ;
V_84 = & V_5 -> V_130 [ F_1 ( V_1 ) ] ;
F_87 ( & V_19 -> V_62 -> V_63 [ V_1 ] ,
V_84 ) ;
F_88 ( V_5 , V_84 ) ;
#endif
}
static void F_89 ( struct V_4 * V_5 , unsigned short V_131 )
{
unsigned short V_132 = 0 ;
if ( V_131 & V_133 )
V_132 |= V_134 ;
if ( V_131 & V_135 )
V_132 |= V_136 ;
if ( V_131 & V_137 )
V_132 |= V_138 ;
if ( V_131 & V_139 )
V_132 |= V_140 ;
if ( V_132 )
F_25 ( V_5 , V_132 , V_141 ) ;
}
static void F_90 ( struct V_4 * V_5 , unsigned short V_142 ,
unsigned V_143 )
{
struct V_83 * V_84 = V_5 -> V_85 ;
struct V_144 * V_145 = & V_84 -> V_107 -> V_145 ;
if ( V_84 -> type == V_146 )
return;
#ifdef F_51
if ( V_143 & V_147 )
F_65 ( V_5 ) ;
if ( V_143 & ~ ( V_148 | V_147 | V_149 | V_150 |
V_151 | V_152 | V_153 | V_154 |
V_155 | V_156 | V_157 ) ) {
F_32 ( V_5 -> V_13 ,
L_13 ,
V_143 ) ;
V_84 -> V_107 -> V_108 |= V_119 ;
}
#endif
if ( V_142 & ( V_158 |
V_133 | V_135 ) ) {
if ( V_142 == 0xffff ) {
F_32 ( V_5 -> V_13 , L_14 ) ;
if ( F_91 ( V_84 ) ) {
V_84 -> V_107 -> V_108 |= V_119 ;
F_88 ( V_5 , V_84 ) ;
}
return;
}
if ( V_142 & V_158 ) {
F_32 ( V_5 -> V_13 , L_15 ,
V_142 ) ;
F_84 ( V_5 ) ;
V_84 -> V_107 -> V_108 |= V_119 ;
if ( V_142 & V_159 )
V_84 -> V_107 -> V_108 |= V_109 ;
F_88 ( V_5 , V_84 ) ;
return;
}
if ( V_142 & V_133 ) {
if ( V_145 -> V_160 == V_161 )
F_84 ( V_5 ) ;
}
}
#ifndef F_51
if ( V_142 & V_162 ) {
int V_73 ;
static const int V_72 = 10 ;
for ( V_73 = 0 ; V_73 < V_72 ; ++ V_73 ) {
F_80 ( V_5 ) ;
if ( ( F_29 ( V_5 , V_87 ) &
V_162 ) == 0 )
break;
}
}
#endif
if ( V_142 & V_139 )
F_85 ( V_5 , V_84 ) ;
F_88 ( V_5 , V_84 ) ;
}
static void F_92 ( struct V_4 * V_5 , unsigned short V_91 )
{
unsigned short V_132 = 0 ;
if ( V_91 & V_163 )
V_132 |= V_164 ;
if ( V_91 & V_165 )
V_132 |= V_166 ;
if ( V_91 & V_167 )
V_132 |= V_168 ;
if ( V_91 & V_169 )
V_132 |= V_170 ;
if ( V_91 & V_171 )
V_132 |= V_172 ;
if ( V_91 & V_173 )
V_132 |= V_174 ;
if ( V_91 & V_175 )
V_132 |= V_176 ;
if ( V_132 )
F_25 ( V_5 , V_132 , V_177 ) ;
}
static void F_93 ( struct V_4 * V_5 ,
unsigned short V_91 , unsigned V_178 )
{
struct V_83 * V_84 = V_5 -> V_90 ;
#ifdef F_51
if ( V_178 & V_147 ) {
struct V_18 * V_19 = V_5 -> V_20 ;
F_69 ( V_19 -> V_24 , V_5 ) ;
}
if ( V_178 & ~ ( V_148 | V_147 | V_149 | V_150 |
V_151 | V_152 | V_153 | V_154 |
V_155 | V_156 | V_157 ) ) {
F_32 ( V_5 -> V_13 ,
L_16 ,
V_178 ) ;
V_84 -> V_107 -> V_108 |= V_119 ;
}
#endif
if ( V_91 == 0xffff )
return;
if ( V_91 & V_165 ) {
F_32 ( V_5 -> V_13 ,
L_17 ,
V_91 , F_29 ( V_5 , V_179 ) ) ;
V_84 -> V_107 -> V_108 |= V_109 ;
}
if ( V_91 & V_163 )
V_84 -> V_107 -> V_108 |= V_124 ;
#ifndef F_51
if ( V_91 & V_180 ) {
int V_181 ;
V_181 = F_74 ( V_5 , V_84 ) ;
if ( ! V_181 ) {
F_32 ( V_5 -> V_13 , L_18 ) ;
F_64 ( V_5 , V_33 ,
V_182 |
V_183 , 0 ) ;
V_84 -> V_107 -> V_108 |= V_109 ;
}
}
#endif
F_88 ( V_5 , V_84 ) ;
}
static void F_94 ( struct V_4 * V_5 , struct V_83 * V_84 ,
void * V_6 , unsigned int V_184 ,
unsigned int V_185 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
struct V_113 * V_107 = V_84 -> V_107 ;
struct V_144 * V_145 = & V_107 -> V_145 ;
unsigned int V_106 = F_76 ( V_84 , V_184 ) ;
unsigned short * V_186 = V_6 ;
unsigned int * V_187 = V_6 ;
unsigned int V_73 ;
for ( V_73 = 0 ; V_73 < V_106 ; V_73 ++ ) {
#ifdef F_51
if ( V_84 -> V_188 & V_189 )
V_187 [ V_73 ] = F_95 ( V_187 [ V_73 ] ) ;
else
V_186 [ V_73 ] = F_96 ( V_186 [ V_73 ] ) ;
#endif
if ( V_84 -> V_188 & V_189 )
V_187 [ V_73 ] += V_19 -> V_190 [ V_185 ] ;
else
V_186 [ V_73 ] += V_19 -> V_190 [ V_185 ] ;
V_185 ++ ;
V_185 %= V_145 -> V_191 ;
}
}
static int F_97 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
struct V_83 * V_84 = V_5 -> V_85 ;
int V_86 ;
unsigned long V_21 ;
V_86 = F_44 ( V_5 ) ;
if ( V_86 )
return V_86 ;
F_98 ( V_84 , V_84 -> V_107 -> V_192 ) ;
F_26 ( & V_19 -> V_50 , V_21 ) ;
if ( ! V_19 -> V_51 ) {
F_27 ( & V_19 -> V_50 , V_21 ) ;
return - V_193 ;
}
if ( V_19 -> V_115 || V_19 -> V_74 )
F_99 ( V_19 -> V_51 , 32 , 16 ) ;
else if ( V_19 -> V_194 )
F_99 ( V_19 -> V_51 , 32 , 32 ) ;
else
F_99 ( V_19 -> V_51 , 16 , 16 ) ;
F_100 ( V_19 -> V_51 ) ;
F_27 ( & V_19 -> V_50 , V_21 ) ;
return 0 ;
}
static int F_101 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
struct V_83 * V_84 = V_5 -> V_90 ;
int V_86 ;
unsigned long V_21 ;
V_86 = F_47 ( V_5 ) ;
if ( V_86 )
return V_86 ;
F_102 ( V_84 , V_84 -> V_107 -> V_192 ) ;
F_26 ( & V_19 -> V_50 , V_21 ) ;
if ( V_19 -> V_56 ) {
if ( V_19 -> V_115 || V_19 -> V_195 ) {
F_99 ( V_19 -> V_56 , 32 , 32 ) ;
} else {
F_99 ( V_19 -> V_56 , 16 , 32 ) ;
}
F_100 ( V_19 -> V_56 ) ;
} else {
V_86 = - V_193 ;
}
F_27 ( & V_19 -> V_50 , V_21 ) ;
return V_86 ;
}
static int F_103 ( struct V_4 * V_5 , struct V_83 * V_84 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned V_196 ;
unsigned V_197 ;
F_52 ( V_5 ) ;
F_25 ( V_5 , V_198 | V_199 ,
V_200 ) ;
F_64 ( V_5 , V_31 , V_201 , 0 ) ;
F_58 ( V_5 ) ;
if ( ! V_19 -> V_74 )
F_9 ( V_5 , V_202 , V_203 ) ;
F_25 ( V_5 , V_204 , V_205 ) ;
F_25 ( V_5 , V_206 |
V_207
,
V_208 ) ;
F_25 ( V_5 , 0 , V_209 ) ;
F_25 ( V_5 , V_210 ,
V_211 ) ;
V_196 = V_212 |
V_213 |
V_214 ;
V_197 = F_104 ( 3 ) |
F_105 ( 0 ) |
F_106 ( 2 ) |
F_107 ( 3 ) ;
if ( V_19 -> V_115 ) {
V_197 |= V_215 ;
} else if ( V_19 -> V_74 ) {
V_197 |= V_216 ;
} else {
V_196 |= V_217 ;
if ( V_19 -> V_218 )
V_197 |= V_215 ;
else
V_197 |= V_216 ;
}
F_25 ( V_5 , V_196 , V_219 ) ;
F_25 ( V_5 , V_197 , V_220 ) ;
F_25 ( V_5 , V_221 , V_141 ) ;
F_25 ( V_5 , V_222 , V_200 ) ;
return 0 ;
}
static int F_108 ( struct V_4 * V_5 , struct V_83 * V_84 )
{
unsigned long V_21 ;
int V_223 ;
F_26 ( & V_5 -> V_224 , V_21 ) ;
#ifndef F_51
F_81 ( V_5 ) ;
#else
F_65 ( V_5 ) ;
#endif
V_223 = F_109 ( V_84 ) ;
F_27 ( & V_5 -> V_224 , V_21 ) ;
return V_223 ;
}
static void F_110 ( struct V_4 * V_5 )
{
int V_73 ;
F_25 ( V_5 , V_225 , V_205 ) ;
for ( V_73 = 0 ; V_73 < V_226 ; ++ V_73 ) {
if ( ! ( F_29 ( V_5 , V_87 ) &
V_88 ) ) {
F_25 ( V_5 , 1 , V_77 ) ;
return;
}
F_59 ( 1 ) ;
}
F_32 ( V_5 -> V_13 , L_19 ) ;
}
static void F_111 ( struct V_4 * V_5 ,
unsigned int V_227 ,
unsigned int * V_228 )
{
const struct V_102 * V_103 = V_5 -> V_104 ;
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_229 , V_230 , V_231 ;
unsigned int V_73 ;
unsigned int V_232 ;
unsigned V_233 ;
F_25 ( V_5 , 1 , V_234 ) ;
if ( ( V_228 [ 0 ] & V_235 ) ) {
unsigned V_236 ;
V_229 = F_112 ( V_228 [ 0 ] ) ;
V_230 = F_113 ( V_228 [ 0 ] ) ;
V_233 = V_237 [ V_103 -> V_238 ] [ V_230 ] ;
V_232 = ( V_228 [ 0 ] & V_239 ) != 0 ;
V_236 = V_240 |
F_114 ( V_229 ) |
F_115 ( V_233 ) |
V_19 -> V_241 ;
if ( V_232 )
V_236 |= V_242 ;
V_236 |= V_243 ;
F_3 ( V_5 , V_236 , V_244 ) ;
} else {
F_3 ( V_5 , 0 , V_244 ) ;
}
for ( V_73 = 0 ; V_73 < V_227 ; V_73 ++ ) {
unsigned V_245 = 0 ;
V_229 = F_112 ( V_228 [ V_73 ] ) ;
V_231 = F_116 ( V_228 [ V_73 ] ) ;
V_230 = F_113 ( V_228 [ V_73 ] ) ;
V_232 = ( V_228 [ V_73 ] & V_239 ) != 0 ;
V_233 = V_237 [ V_103 -> V_238 ] [ V_230 ] ;
V_19 -> V_190 [ V_73 ] = 0 ;
switch ( V_231 ) {
case V_246 :
V_245 |= V_247 ;
break;
case V_248 :
V_245 |= V_249 ;
break;
case V_250 :
V_245 |= V_251 ;
break;
case V_252 :
break;
}
V_245 |= F_117 ( V_229 ) ;
V_245 |= F_118 ( V_229 ) ;
V_245 |= F_119 ( V_233 ) ;
if ( V_73 == V_227 - 1 )
V_245 |= V_253 ;
if ( V_232 )
V_245 |= V_254 ;
V_245 |= V_255 ;
F_6 ( V_5 , V_245 , V_256 ) ;
}
F_110 ( V_5 ) ;
}
static void F_120 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
unsigned int V_227 , unsigned int * V_228 )
{
const struct V_102 * V_103 = V_5 -> V_104 ;
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_257 = ( V_84 -> V_258 + 1 ) >> 1 ;
unsigned int V_229 , V_230 , V_231 ;
unsigned int V_73 ;
unsigned int V_259 , V_260 ;
unsigned int V_232 ;
if ( V_19 -> V_22 ) {
F_111 ( V_5 , V_227 , V_228 ) ;
return;
}
if ( V_227 == 1 && ! V_19 -> V_115 && ! V_19 -> V_74 ) {
if ( V_19 -> V_261
&& V_19 -> V_262 == V_228 [ 0 ] ) {
return;
}
V_19 -> V_261 = 1 ;
V_19 -> V_262 = V_228 [ 0 ] ;
} else {
V_19 -> V_261 = 0 ;
}
F_25 ( V_5 , 1 , V_234 ) ;
if ( V_19 -> V_74 ) {
if ( ( V_228 [ 0 ] & V_235 )
&& ! V_19 -> V_263 ) {
F_6 ( V_5 , V_19 -> V_241 |
V_264 ,
V_265 ) ;
F_6 ( V_5 , V_19 -> V_241 ,
V_265 ) ;
V_19 -> V_263 = 1 ;
F_121 ( 100 ) ;
} else if ( ! ( V_228 [ 0 ] & V_235 )
&& V_19 -> V_263 ) {
F_6 ( V_5 , V_19 -> V_241 |
V_266 ,
V_265 ) ;
F_6 ( V_5 , V_19 -> V_241 ,
V_265 ) ;
V_19 -> V_263 = 0 ;
F_121 ( 100 ) ;
}
}
for ( V_73 = 0 ; V_73 < V_227 ; V_73 ++ ) {
if ( ! V_19 -> V_74 && ( V_228 [ V_73 ] & V_235 ) )
V_229 = V_19 -> V_241 ;
else
V_229 = F_112 ( V_228 [ V_73 ] ) ;
V_231 = F_116 ( V_228 [ V_73 ] ) ;
V_230 = F_113 ( V_228 [ V_73 ] ) ;
V_232 = ( V_228 [ V_73 ] & V_239 ) != 0 ;
V_230 = V_237 [ V_103 -> V_238 ] [ V_230 ] ;
if ( V_19 -> V_115 )
V_19 -> V_190 [ V_73 ] = V_257 ;
else
V_19 -> V_190 [ V_73 ] = ( V_230 & 0x100 ) ? 0 : V_257 ;
V_259 = 0 ;
if ( ( V_228 [ V_73 ] & V_235 ) ) {
if ( V_19 -> V_115 )
F_6 ( V_5 , F_112 ( V_228 [ V_73 ] ) & 0x0003 ,
V_267 ) ;
} else {
if ( V_19 -> V_115 )
V_231 = V_246 ;
else if ( V_19 -> V_74 )
V_231 = V_252 ;
switch ( V_231 ) {
case V_246 :
V_259 |= V_268 ;
break;
case V_248 :
V_259 |= V_269 ;
break;
case V_250 :
V_259 |= V_270 ;
break;
case V_252 :
break;
}
}
V_259 |= F_122 ( V_229 ) ;
F_6 ( V_5 , V_259 , V_271 ) ;
if ( ! V_19 -> V_74 ) {
V_260 = F_123 ( V_230 ) ;
if ( V_73 == V_227 - 1 )
V_260 |= V_272 ;
if ( V_232 )
V_260 |= V_273 ;
F_6 ( V_5 , V_260 , V_274 ) ;
}
}
if ( ! V_19 -> V_115 && ! V_19 -> V_74 )
F_110 ( V_5 ) ;
}
static int F_124 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_275 * V_276 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_277 = ( V_84 -> V_258 + 1 ) >> 1 ;
int V_73 , V_95 ;
unsigned V_278 ;
unsigned int V_96 ;
unsigned long V_114 ;
F_120 ( V_5 , V_84 , 1 , & V_276 -> V_279 ) ;
F_58 ( V_5 ) ;
V_278 = V_19 -> V_190 [ 0 ] ;
if ( V_19 -> V_115 ) {
for ( V_95 = 0 ; V_95 < V_280 ; V_95 ++ ) {
F_25 ( V_5 , V_225 ,
V_205 ) ;
F_59 ( 1 ) ;
}
for ( V_95 = 0 ; V_95 < V_276 -> V_95 ; V_95 ++ ) {
F_25 ( V_5 , V_225 ,
V_205 ) ;
V_96 = 0 ;
for ( V_73 = 0 ; V_73 < V_226 ; V_73 ++ ) {
if ( F_18 ( V_5 , V_123 ) & 0x80 ) {
V_96 = F_12 ( V_5 ,
V_116 ) ;
V_96 >>= 16 ;
V_96 &= 0xffff ;
break;
}
if ( ! ( F_29 ( V_5 , V_87 ) &
V_88 ) ) {
V_96 = F_12 ( V_5 ,
V_116 ) ;
V_96 &= 0xffff ;
break;
}
}
if ( V_73 == V_226 ) {
F_32 ( V_5 -> V_13 , L_20 ) ;
return - V_281 ;
}
V_96 += V_278 ;
V_6 [ V_95 ] = V_96 ;
}
} else if ( V_19 -> V_74 ) {
for ( V_95 = 0 ; V_95 < V_276 -> V_95 ; V_95 ++ ) {
F_25 ( V_5 , V_225 ,
V_205 ) ;
V_114 = 0 ;
for ( V_73 = 0 ; V_73 < V_226 ; V_73 ++ ) {
if ( F_12 ( V_5 , V_76 ) &
0x01 ) {
F_3 ( V_5 , 0x01 ,
V_75 ) ;
V_114 = F_12 ( V_5 ,
V_117 ) ;
break;
}
}
if ( V_73 == V_226 ) {
F_32 ( V_5 -> V_13 , L_20 ) ;
return - V_281 ;
}
V_6 [ V_95 ] = ( ( ( V_114 >> 16 ) & 0xFFFF ) + V_278 ) & 0xFFFF ;
}
} else {
for ( V_95 = 0 ; V_95 < V_276 -> V_95 ; V_95 ++ ) {
F_25 ( V_5 , V_225 ,
V_205 ) ;
for ( V_73 = 0 ; V_73 < V_226 ; V_73 ++ ) {
if ( ! ( F_29 ( V_5 , V_87 ) &
V_88 ) )
break;
}
if ( V_73 == V_226 ) {
F_32 ( V_5 -> V_13 , L_20 ) ;
return - V_281 ;
}
if ( V_19 -> V_22 ) {
V_114 = F_12 ( V_5 , V_282 ) ;
V_114 &= V_277 ;
V_6 [ V_95 ] = V_114 ;
} else {
V_96 = F_15 ( V_5 , V_120 ) ;
V_96 += V_278 ;
V_6 [ V_95 ] = V_96 ;
}
}
}
return V_276 -> V_95 ;
}
static int F_125 ( const struct V_4 * V_5 , unsigned V_283 ,
unsigned int V_21 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
int V_284 ;
switch ( V_21 & V_285 ) {
case V_286 :
default:
V_284 = ( V_283 + V_19 -> V_287 / 2 ) / V_19 -> V_287 ;
break;
case V_288 :
V_284 = ( V_283 ) / V_19 -> V_287 ;
break;
case V_289 :
V_284 = ( V_283 + V_19 -> V_287 - 1 ) / V_19 -> V_287 ;
break;
}
return V_284 - 1 ;
}
static unsigned F_126 ( const struct V_4 * V_5 , int V_290 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
return V_19 -> V_287 * ( V_290 + 1 ) ;
}
static unsigned F_127 ( struct V_4 * V_5 ,
unsigned V_291 )
{
const struct V_102 * V_103 = V_5 -> V_104 ;
struct V_18 * V_19 = V_5 -> V_20 ;
if ( V_19 -> V_115 || V_19 -> V_74 )
return V_103 -> V_292 ;
return V_103 -> V_292 * V_291 ;
}
static int F_128 ( struct V_4 * V_5 , struct V_83 * V_84 ,
struct V_144 * V_145 )
{
const struct V_102 * V_103 = V_5 -> V_104 ;
struct V_18 * V_19 = V_5 -> V_20 ;
int V_293 = 0 ;
unsigned int V_294 ;
unsigned int V_295 ;
V_293 |= F_129 ( & V_145 -> V_296 ,
V_297 | V_298 | V_299 ) ;
V_293 |= F_129 ( & V_145 -> V_300 ,
V_301 | V_299 ) ;
V_295 = V_301 | V_299 ;
if ( V_19 -> V_115 || V_19 -> V_74 )
V_295 |= V_297 ;
V_293 |= F_129 ( & V_145 -> V_302 , V_295 ) ;
V_293 |= F_129 ( & V_145 -> V_303 , V_161 ) ;
V_293 |= F_129 ( & V_145 -> V_160 , V_161 | V_304 ) ;
if ( V_293 )
return 1 ;
V_293 |= F_130 ( V_145 -> V_296 ) ;
V_293 |= F_130 ( V_145 -> V_300 ) ;
V_293 |= F_130 ( V_145 -> V_302 ) ;
V_293 |= F_130 ( V_145 -> V_160 ) ;
if ( V_293 )
return 2 ;
switch ( V_145 -> V_296 ) {
case V_297 :
case V_298 :
V_293 |= F_131 ( & V_145 -> V_305 , 0 ) ;
break;
case V_299 :
V_294 = F_112 ( V_145 -> V_305 ) ;
if ( V_294 > 16 )
V_294 = 16 ;
V_294 |= ( V_145 -> V_305 & ( V_306 | V_307 ) ) ;
V_293 |= F_131 ( & V_145 -> V_305 , V_294 ) ;
break;
}
if ( V_145 -> V_300 == V_301 ) {
V_293 |= F_132 ( & V_145 -> V_308 ,
F_127 ( V_5 , V_145 -> V_191 ) ) ;
V_293 |= F_133 ( & V_145 -> V_308 ,
V_19 -> V_287 *
0xffffff ) ;
} else if ( V_145 -> V_300 == V_299 ) {
unsigned int V_294 = F_112 ( V_145 -> V_308 ) ;
if ( V_294 > 16 )
V_294 = 16 ;
V_294 |= ( V_145 -> V_308 & ( V_306 | V_307 ) ) ;
V_293 |= F_131 ( & V_145 -> V_308 , V_294 ) ;
} else {
V_293 |= F_131 ( & V_145 -> V_308 , 0 ) ;
}
if ( V_145 -> V_302 == V_301 ) {
if ( V_19 -> V_115 || V_19 -> V_74 ) {
V_293 |= F_131 ( & V_145 -> V_309 ,
0 ) ;
} else {
V_293 |= F_132 ( & V_145 -> V_309 ,
V_103 -> V_292 ) ;
V_293 |= F_133 ( & V_145 -> V_309 ,
V_19 -> V_287 *
0xffff ) ;
}
} else if ( V_145 -> V_302 == V_299 ) {
unsigned int V_294 = F_112 ( V_145 -> V_309 ) ;
if ( V_294 > 16 )
V_294 = 16 ;
V_294 |= ( V_145 -> V_309 & ( V_239 | V_306 ) ) ;
V_293 |= F_131 ( & V_145 -> V_309 , V_294 ) ;
} else if ( V_145 -> V_302 == V_297 ) {
V_293 |= F_131 ( & V_145 -> V_309 , 0 ) ;
}
V_293 |= F_131 ( & V_145 -> V_310 ,
V_145 -> V_191 ) ;
if ( V_145 -> V_160 == V_161 ) {
unsigned int V_311 = 0x01000000 ;
if ( V_19 -> V_115 )
V_311 -= V_280 ;
V_293 |= F_133 ( & V_145 -> V_312 , V_311 ) ;
V_293 |= F_132 ( & V_145 -> V_312 , 1 ) ;
} else {
V_293 |= F_131 ( & V_145 -> V_312 , 0 ) ;
}
if ( V_293 )
return 3 ;
if ( V_145 -> V_300 == V_301 ) {
V_294 = V_145 -> V_308 ;
V_145 -> V_308 =
F_126 ( V_5 , F_125 ( V_5 ,
V_145 -> V_308 ,
V_145 -> V_21 ) ) ;
if ( V_294 != V_145 -> V_308 )
V_293 ++ ;
}
if ( V_145 -> V_302 == V_301 ) {
if ( ! V_19 -> V_115 && ! V_19 -> V_74 ) {
V_294 = V_145 -> V_309 ;
V_145 -> V_309 =
F_126 ( V_5 , F_125 ( V_5 ,
V_145 -> V_309 ,
V_145 -> V_21 ) ) ;
if ( V_294 != V_145 -> V_309 )
V_293 ++ ;
if ( V_145 -> V_300 == V_301 &&
V_145 -> V_308 <
V_145 -> V_309 * V_145 -> V_310 ) {
V_145 -> V_308 =
V_145 -> V_309 * V_145 -> V_310 ;
V_293 ++ ;
}
}
}
if ( V_293 )
return 4 ;
return 0 ;
}
static int F_134 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
unsigned int V_313 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
struct V_144 * V_145 = & V_84 -> V_107 -> V_145 ;
if ( V_313 != V_145 -> V_305 )
return - V_314 ;
F_25 ( V_5 , V_315 | V_19 -> V_128 ,
V_316 ) ;
V_84 -> V_107 -> V_317 = NULL ;
return 1 ;
}
static int F_135 ( struct V_4 * V_5 , struct V_83 * V_84 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
const struct V_144 * V_145 = & V_84 -> V_107 -> V_145 ;
int V_290 ;
int V_318 = 0 ;
int V_319 = 0 ;
int V_320 = 0 ;
unsigned int V_321 ;
int V_322 = 0 ;
unsigned V_323 ;
if ( V_5 -> V_324 == 0 ) {
F_32 ( V_5 -> V_13 , L_21 ) ;
return - V_193 ;
}
F_58 ( V_5 ) ;
F_120 ( V_5 , V_84 , V_145 -> V_191 , V_145 -> V_325 ) ;
F_25 ( V_5 , V_198 , V_200 ) ;
V_19 -> V_326 &= ~ V_327 ;
F_25 ( V_5 , V_19 -> V_326 , V_328 ) ;
V_323 = F_136 ( 0 ) | V_329 ;
switch ( V_145 -> V_296 ) {
case V_298 :
case V_297 :
V_323 |= V_330 |
F_137 ( 0 ) ;
break;
case V_299 :
V_323 |= F_137 ( F_112 ( V_145 -> V_305 ) +
1 ) ;
if ( V_145 -> V_305 & V_306 )
V_323 |= V_331 ;
if ( V_145 -> V_305 & V_307 )
V_323 |= V_330 ;
break;
}
F_25 ( V_5 , V_323 , V_332 ) ;
V_319 &= ~ V_333 ;
V_319 &= ~ V_334 ;
V_319 &= ~ V_335 ;
F_25 ( V_5 , V_319 , V_209 ) ;
if ( V_145 -> V_191 == 1 || V_19 -> V_115 || V_19 -> V_74 ) {
V_320 |= V_336 |
F_138 ( 31 ) |
V_337 ;
} else {
V_320 |= F_138 ( 19 ) ;
}
F_25 ( V_5 , V_320 , V_338 ) ;
V_19 -> V_128 = 0 ;
switch ( V_145 -> V_160 ) {
case V_161 :
V_321 = V_145 -> V_312 - 1 ;
if ( V_19 -> V_115 ) {
V_321 += V_280 ;
}
F_28 ( V_5 , V_321 , V_339 ) ;
V_318 |= V_206 |
V_207 |
V_340 ;
F_25 ( V_5 , V_318 , V_208 ) ;
F_25 ( V_5 , V_341 , V_205 ) ;
if ( V_321 == 0 ) {
V_19 -> V_128 |= V_129 ;
V_322 |= V_342 ;
if ( V_145 -> V_191 > 1 )
V_320 |= V_336 |
V_343 ;
}
break;
case V_304 :
F_28 ( V_5 , 0 , V_339 ) ;
V_318 |= V_206 |
V_207 |
V_344 ;
F_25 ( V_5 , V_318 , V_208 ) ;
F_25 ( V_5 , V_341 , V_205 ) ;
break;
}
switch ( V_145 -> V_300 ) {
case V_301 :
V_320 |= V_345 | V_346 ;
F_25 ( V_5 , V_320 , V_338 ) ;
V_319 &= ~ V_347 ;
V_319 |= F_139 ( 0 ) ;
F_25 ( V_5 , V_319 , V_209 ) ;
V_290 = F_125 ( V_5 , V_145 -> V_308 ,
V_286 ) ;
F_28 ( V_5 , V_290 , V_348 ) ;
F_25 ( V_5 , V_349 , V_205 ) ;
break;
case V_299 :
if ( V_145 -> V_308 & V_307 )
V_320 |= V_345 ;
if ( V_145 -> V_308 & V_306 )
V_320 |= V_350 ;
if ( V_145 -> V_300 != V_145 -> V_302 ||
( V_145 -> V_308 & ~ V_307 ) !=
( V_145 -> V_309 & ~ V_307 ) )
V_320 |= V_346 ;
V_320 |=
F_140 ( 1 + F_112 ( V_145 -> V_308 ) ) ;
F_25 ( V_5 , V_320 , V_338 ) ;
break;
}
switch ( V_145 -> V_302 ) {
case V_301 :
case V_297 :
if ( V_145 -> V_309 == 0 || V_145 -> V_302 == V_297 )
V_290 = 1 ;
else
V_290 = F_125 ( V_5 , V_145 -> V_309 ,
V_286 ) ;
F_25 ( V_5 , 1 , V_351 ) ;
F_25 ( V_5 , V_290 , V_352 ) ;
V_319 &= ~ V_353 ;
V_319 |= V_354 ;
F_25 ( V_5 , V_319 , V_209 ) ;
F_25 ( V_5 , V_355 , V_205 ) ;
V_319 |= V_353 ;
V_319 |= V_354 ;
F_25 ( V_5 , V_319 , V_209 ) ;
break;
case V_299 :
V_318 |= F_141 ( 1 + V_145 -> V_309 ) ;
if ( ( V_145 -> V_309 & V_306 ) == 0 )
V_318 |= V_356 ;
F_25 ( V_5 , V_318 , V_208 ) ;
V_319 |= V_357 |
V_358 ;
F_25 ( V_5 , V_319 , V_209 ) ;
break;
}
if ( V_5 -> V_324 ) {
V_322 |= V_359 |
V_360 ;
#ifndef F_51
V_322 |= V_361 ;
#endif
if ( ( V_145 -> V_21 & V_362 ) ||
( V_19 -> V_128 & V_129 ) ) {
V_19 -> V_125 = V_126 ;
} else {
V_19 -> V_125 = V_363 ;
}
switch ( V_19 -> V_125 ) {
case V_363 :
#ifdef F_51
F_25 ( V_5 , V_364 ,
V_211 ) ;
#else
F_25 ( V_5 , V_365 ,
V_211 ) ;
#endif
break;
case V_366 :
F_25 ( V_5 , V_210 ,
V_211 ) ;
break;
case V_126 :
#ifdef F_51
F_25 ( V_5 , V_210 ,
V_211 ) ;
#else
F_25 ( V_5 , V_365 ,
V_211 ) ;
#endif
V_322 |= V_342 ;
break;
default:
break;
}
F_25 ( V_5 , V_221 , V_141 ) ;
F_64 ( V_5 , V_31 , V_322 , 1 ) ;
} else {
F_64 ( V_5 , V_31 , ~ 0 , 0 ) ;
}
F_25 ( V_5 , V_222 , V_200 ) ;
switch ( V_145 -> V_300 ) {
case V_301 :
F_25 ( V_5 , V_367 |
V_368 |
V_369 |
V_370 ,
V_205 ) ;
break;
case V_299 :
F_25 ( V_5 , V_367 |
V_368 |
V_369 |
V_370 ,
V_205 ) ;
break;
}
#ifdef F_51
{
int V_86 = F_97 ( V_5 ) ;
if ( V_86 )
return V_86 ;
}
#endif
if ( V_145 -> V_296 == V_297 ) {
F_25 ( V_5 , V_315 |
V_19 -> V_128 ,
V_316 ) ;
V_84 -> V_107 -> V_317 = NULL ;
} else if ( V_145 -> V_296 == V_299 ) {
V_84 -> V_107 -> V_317 = NULL ;
} else {
V_84 -> V_107 -> V_317 = F_134 ;
}
return 0 ;
}
static int F_142 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_275 * V_276 , unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
if ( V_276 -> V_95 < 1 )
return - V_314 ;
switch ( V_6 [ 0 ] ) {
case V_371 :
if ( V_19 -> V_22 ) {
if ( V_6 [ 1 ] & ~ V_372 )
return - V_314 ;
V_19 -> V_241 = V_6 [ 1 ] ;
} else if ( V_19 -> V_74 ) {
unsigned int V_373 ;
V_373 = V_6 [ 1 ] & 0xf ;
V_19 -> V_241 = V_373 ;
F_6 ( V_5 , V_373 , V_265 ) ;
} else {
unsigned int V_373 ;
unsigned int V_374 ;
V_373 = V_6 [ 1 ] & 0xf ;
V_374 = ( V_6 [ 1 ] >> 4 ) & 0xff ;
if ( V_373 >= 8 )
return - V_314 ;
V_19 -> V_241 = V_373 ;
if ( V_19 -> V_115 ) {
F_9 ( V_5 , V_374 ,
V_375 ) ;
}
}
return 2 ;
default:
break;
}
return - V_314 ;
}
static void F_143 ( struct V_4 * V_5 , struct V_83 * V_84 ,
void * V_6 , unsigned int V_184 ,
unsigned int V_185 )
{
struct V_144 * V_145 = & V_84 -> V_107 -> V_145 ;
unsigned int V_106 = F_76 ( V_84 , V_184 ) ;
unsigned short * V_186 = V_6 ;
unsigned int V_73 ;
for ( V_73 = 0 ; V_73 < V_106 ; V_73 ++ ) {
unsigned int V_230 = F_113 ( V_145 -> V_325 [ V_185 ] ) ;
unsigned short V_27 = V_186 [ V_73 ] ;
if ( F_144 ( V_84 , V_230 ) )
V_27 = F_145 ( V_84 , V_27 ) ;
#ifdef F_51
V_27 = F_146 ( V_27 ) ;
#endif
V_186 [ V_73 ] = V_27 ;
V_185 ++ ;
V_185 %= V_145 -> V_191 ;
}
}
static int F_147 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
unsigned int V_279 [] ,
unsigned int V_376 , int V_377 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_230 ;
unsigned int V_229 ;
unsigned int V_378 ;
int V_73 ;
int V_379 = 0 ;
if ( V_377 ) {
for ( V_73 = 0 ; V_73 < V_84 -> V_227 ; ++ V_73 ) {
V_19 -> V_380 [ V_73 ] &= ~ V_381 ;
F_9 ( V_5 , V_19 -> V_380 [ V_73 ] ,
F_148 ( V_73 ) ) ;
F_9 ( V_5 , 0xf , F_149 ( V_73 ) ) ;
}
}
for ( V_73 = 0 ; V_73 < V_376 ; V_73 ++ ) {
const struct V_382 * V_383 ;
V_229 = F_112 ( V_279 [ V_73 ] ) ;
V_230 = F_113 ( V_279 [ V_73 ] ) ;
V_383 = V_84 -> V_384 -> V_230 + V_230 ;
V_379 = 0 ;
V_378 = 0 ;
switch ( V_383 -> V_385 - V_383 -> V_386 ) {
case 20000000 :
V_378 |= V_387 ;
F_9 ( V_5 , 0 , F_150 ( V_229 ) ) ;
break;
case 10000000 :
V_378 |= V_388 ;
F_9 ( V_5 , 0 , F_150 ( V_229 ) ) ;
break;
case 4000000 :
V_378 |= V_387 ;
F_9 ( V_5 , V_389 ,
F_150 ( V_229 ) ) ;
break;
case 2000000 :
V_378 |= V_388 ;
F_9 ( V_5 , V_389 ,
F_150 ( V_229 ) ) ;
break;
default:
F_32 ( V_5 -> V_13 ,
L_22 ) ;
break;
}
switch ( V_383 -> V_385 + V_383 -> V_386 ) {
case 0 :
V_378 |= V_390 ;
break;
case 10000000 :
V_378 |= V_391 ;
break;
default:
F_32 ( V_5 -> V_13 ,
L_23 ) ;
break;
}
if ( V_377 )
V_378 |= V_381 ;
F_9 ( V_5 , V_378 , F_148 ( V_229 ) ) ;
V_19 -> V_380 [ V_229 ] = V_378 ;
F_9 ( V_5 , V_73 , F_149 ( V_229 ) ) ;
}
return V_379 ;
}
static int F_151 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
unsigned int V_279 [] ,
unsigned int V_376 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_230 ;
unsigned int V_229 ;
unsigned int V_378 ;
int V_73 ;
int V_379 = 0 ;
for ( V_73 = 0 ; V_73 < V_376 ; V_73 ++ ) {
V_229 = F_112 ( V_279 [ V_73 ] ) ;
V_230 = F_113 ( V_279 [ V_73 ] ) ;
V_378 = F_152 ( V_229 ) ;
if ( F_144 ( V_84 , V_230 ) ) {
V_378 |= V_392 ;
V_379 = ( V_84 -> V_258 + 1 ) >> 1 ;
} else {
V_379 = 0 ;
}
if ( F_153 ( V_84 , V_230 ) )
V_378 |= V_393 ;
if ( V_279 [ V_73 ] & V_394 )
V_378 |= V_395 ;
if ( F_116 ( V_279 [ V_73 ] ) == V_252 )
V_378 |= V_396 ;
F_6 ( V_5 , V_378 , V_397 ) ;
V_19 -> V_380 [ V_229 ] = V_378 ;
}
return V_379 ;
}
static int F_154 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
unsigned int V_279 [] , unsigned int V_376 ,
int V_377 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
if ( V_19 -> V_22 )
return F_147 ( V_5 , V_84 , V_279 , V_376 ,
V_377 ) ;
else
return F_151 ( V_5 , V_84 , V_279 , V_376 ) ;
}
static int F_155 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_275 * V_276 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_229 = F_112 ( V_276 -> V_279 ) ;
unsigned int V_230 = F_113 ( V_276 -> V_279 ) ;
int V_7 ;
int V_73 ;
if ( V_19 -> V_98 ) {
F_61 ( V_5 , 1 << V_229 , V_398 ) ;
V_7 = F_156 ( V_229 ) ;
} else if ( V_19 -> V_22 ) {
V_7 = F_157 ( V_229 ) ;
} else {
V_7 = F_158 ( V_229 ) ;
}
F_154 ( V_5 , V_84 , & V_276 -> V_279 , 1 , 0 ) ;
for ( V_73 = 0 ; V_73 < V_276 -> V_95 ; V_73 ++ ) {
unsigned int V_27 = V_6 [ V_73 ] ;
V_84 -> V_399 [ V_229 ] = V_27 ;
if ( V_19 -> V_98 ) {
V_27 = F_145 ( V_84 , V_27 ) ;
F_61 ( V_5 , V_27 , V_7 ) ;
} else if ( V_19 -> V_22 ) {
F_6 ( V_5 , V_27 , V_7 ) ;
} else {
if ( F_144 ( V_84 , V_230 ) )
V_27 = F_145 ( V_84 , V_27 ) ;
F_6 ( V_5 , V_27 , V_7 ) ;
}
}
return V_276 -> V_95 ;
}
static int F_159 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_275 * V_276 , unsigned int * V_6 )
{
const struct V_102 * V_103 = V_5 -> V_104 ;
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_105 ;
switch ( V_6 [ 0 ] ) {
case V_400 :
switch ( V_6 [ 1 ] ) {
case V_58 :
V_105 = F_160 ( V_84 ,
V_103 -> V_110 ) ;
V_6 [ 2 ] = 1 + V_105 ;
if ( V_19 -> V_24 )
V_6 [ 2 ] += V_19 -> V_24 -> V_401 ;
break;
case V_55 :
V_6 [ 2 ] = 0 ;
break;
default:
return - V_314 ;
}
return 0 ;
default:
break;
}
return - V_314 ;
}
static int F_161 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
unsigned int V_313 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
struct V_144 * V_145 = & V_84 -> V_107 -> V_145 ;
int V_181 ;
int V_402 ;
int V_73 ;
static const int V_72 = 1000 ;
if ( V_313 != V_145 -> V_305 )
return - V_314 ;
V_84 -> V_107 -> V_317 = NULL ;
F_64 ( V_5 , V_33 ,
V_182 | V_183 , 0 ) ;
V_402 = V_183 ;
#ifdef F_51
F_25 ( V_5 , 1 , V_111 ) ;
if ( V_19 -> V_98 )
F_62 ( V_5 , 0x6 , V_112 ) ;
V_181 = F_101 ( V_5 ) ;
if ( V_181 )
return V_181 ;
V_181 = F_71 ( V_5 ) ;
if ( V_181 < 0 )
return V_181 ;
#else
V_181 = F_77 ( V_5 , V_84 ) ;
if ( V_181 == 0 )
return - V_94 ;
V_402 |= V_182 ;
#endif
F_25 ( V_5 , V_19 -> V_403 | V_404 ,
V_405 ) ;
F_25 ( V_5 , V_19 -> V_403 , V_405 ) ;
for ( V_73 = 0 ; V_73 < V_72 ; V_73 ++ ) {
F_59 ( 1 ) ;
if ( ( F_29 ( V_5 , V_406 ) &
V_407 ) == 0 )
break;
}
if ( V_73 == V_72 ) {
F_32 ( V_5 -> V_13 ,
L_24 ) ;
return - V_193 ;
}
F_25 ( V_5 , V_166 , V_177 ) ;
F_64 ( V_5 , V_33 , V_402 , 1 ) ;
F_25 ( V_5 , V_408 |
V_409 |
V_410 |
V_411 |
V_412 |
V_19 -> V_413 ,
V_414 ) ;
F_25 ( V_5 , V_415 | V_19 -> V_416 ,
V_417 ) ;
return 0 ;
}
static int F_162 ( struct V_4 * V_5 , struct V_83 * V_84 )
{
const struct V_102 * V_103 = V_5 -> V_104 ;
struct V_18 * V_19 = V_5 -> V_20 ;
const struct V_144 * V_145 = & V_84 -> V_107 -> V_145 ;
int V_42 ;
int V_73 ;
unsigned V_418 ;
unsigned V_27 ;
if ( V_5 -> V_324 == 0 ) {
F_32 ( V_5 -> V_13 , L_21 ) ;
return - V_193 ;
}
F_25 ( V_5 , V_419 , V_200 ) ;
F_25 ( V_5 , V_420 , V_414 ) ;
if ( V_19 -> V_98 ) {
F_61 ( V_5 , V_421 ,
V_422 ) ;
V_42 = 0 ;
for ( V_73 = 0 ; V_73 < V_145 -> V_191 ; V_73 ++ ) {
int V_229 ;
V_229 = F_112 ( V_145 -> V_325 [ V_73 ] ) ;
V_42 |= 1 << V_229 ;
F_61 ( V_5 , V_229 , V_423 ) ;
}
F_61 ( V_5 , V_42 , V_424 ) ;
}
F_154 ( V_5 , V_84 , V_145 -> V_325 , V_145 -> V_191 , 1 ) ;
if ( V_145 -> V_160 == V_304 ) {
V_19 -> V_425 |= V_426 ;
V_19 -> V_425 &= ~ V_427 ;
} else {
V_19 -> V_425 &= ~ V_426 ;
V_19 -> V_425 |= V_427 ;
}
F_25 ( V_5 , V_19 -> V_425 , V_428 ) ;
V_27 = V_19 -> V_429 ;
switch ( V_145 -> V_296 ) {
case V_298 :
case V_297 :
V_27 &= ~ ( V_430 |
V_431 ) ;
V_27 |= V_432 |
V_433 ;
break;
case V_299 :
V_27 = F_163 ( F_112 ( V_145 -> V_305 ) + 1 ) ;
if ( V_145 -> V_305 & V_306 ) {
V_27 |= V_430 ;
}
if ( V_145 -> V_305 & V_307 ) {
V_27 |= V_432 ;
}
F_25 ( V_5 , V_19 -> V_429 ,
V_434 ) ;
break;
default:
F_2 () ;
break;
}
V_19 -> V_429 = V_27 ;
F_25 ( V_5 , V_19 -> V_429 , V_434 ) ;
V_19 -> V_403 &= ~ V_435 ;
F_25 ( V_5 , V_19 -> V_403 , V_405 ) ;
F_25 ( V_5 , V_19 -> V_425 , V_428 ) ;
V_19 -> V_436 &= ~ V_437 ;
F_25 ( V_5 , V_19 -> V_436 , V_438 ) ;
if ( V_145 -> V_160 == V_304 )
F_28 ( V_5 , 0xffffff , V_439 ) ;
else
F_28 ( V_5 , 0 , V_439 ) ;
F_25 ( V_5 , V_440 , V_414 ) ;
V_19 -> V_436 &= ~ V_441 ;
F_25 ( V_5 , V_19 -> V_436 , V_438 ) ;
switch ( V_145 -> V_160 ) {
case V_161 :
if ( V_19 -> V_22 ) {
F_28 ( V_5 , V_145 -> V_312 - 1 ,
V_442 ) ;
F_25 ( V_5 , V_443 ,
V_414 ) ;
} else {
F_28 ( V_5 , V_145 -> V_312 ,
V_442 ) ;
F_25 ( V_5 , V_443 ,
V_414 ) ;
F_28 ( V_5 , V_145 -> V_312 - 1 ,
V_442 ) ;
}
break;
case V_304 :
F_28 ( V_5 , 0xffffff , V_442 ) ;
F_25 ( V_5 , V_443 , V_414 ) ;
F_28 ( V_5 , 0xffffff , V_442 ) ;
break;
default:
F_28 ( V_5 , 0 , V_442 ) ;
F_25 ( V_5 , V_443 , V_414 ) ;
F_28 ( V_5 , V_145 -> V_312 , V_442 ) ;
}
V_19 -> V_425 &= ~ ( V_444 |
V_445 |
V_446 |
V_447 ) ;
switch ( V_145 -> V_300 ) {
case V_301 :
V_19 -> V_416 &= ~ V_448 ;
V_418 =
F_125 ( V_5 , V_145 -> V_308 ,
V_286 ) ;
F_28 ( V_5 , 1 , V_449 ) ;
F_25 ( V_5 , V_450 , V_414 ) ;
F_28 ( V_5 , V_418 , V_449 ) ;
break;
case V_299 :
V_19 -> V_425 |=
F_164 ( V_145 -> V_308 ) ;
if ( V_145 -> V_308 & V_306 )
V_19 -> V_425 |= V_446 ;
V_19 -> V_416 |= V_448 ;
break;
default:
F_2 () ;
break;
}
F_25 ( V_5 , V_19 -> V_416 , V_417 ) ;
F_25 ( V_5 , V_19 -> V_425 , V_428 ) ;
V_19 -> V_436 &= ~ ( F_165 ( 3 ) |
V_451 ) ;
F_25 ( V_5 , V_19 -> V_436 , V_438 ) ;
if ( V_145 -> V_310 > 1 ) {
V_19 -> V_425 |= V_452 ;
F_25 ( V_5 ,
F_166 ( V_145 -> V_310 - 1 ) |
V_453 ,
V_454 ) ;
} else {
unsigned V_42 ;
V_19 -> V_425 &= ~ V_452 ;
V_42 = V_453 ;
if ( V_19 -> V_22 || V_19 -> V_98 ) {
V_42 |= F_166 ( 0 ) ;
} else {
V_42 |=
F_166 ( F_112 ( V_145 -> V_325 [ 0 ] ) ) ;
}
F_25 ( V_5 , V_42 , V_454 ) ;
}
F_25 ( V_5 , V_19 -> V_425 , V_428 ) ;
F_25 ( V_5 , V_411 |
V_412 ,
V_414 ) ;
V_19 -> V_403 |= V_455 ;
F_25 ( V_5 , V_19 -> V_403 , V_405 ) ;
V_19 -> V_436 &= ~ V_456 ;
#ifdef F_51
V_19 -> V_436 |= V_457 ;
#else
V_19 -> V_436 |= V_458 ;
#endif
V_19 -> V_436 &= ~ V_459 ;
F_25 ( V_5 , V_19 -> V_436 , V_438 ) ;
V_42 = V_460 |
V_461 |
V_462 ;
if ( V_103 -> V_110 )
V_42 |= V_463 ;
else
V_42 |= V_464 ;
#if 0
if (devpriv->is_m_series)
bits |= NISTC_AO_PERSONAL_NUM_DAC;
#endif
F_25 ( V_5 , V_42 , V_465 ) ;
F_25 ( V_5 , V_466 , V_467 ) ;
F_25 ( V_5 , V_468 , V_200 ) ;
if ( V_145 -> V_160 == V_161 ) {
F_25 ( V_5 , V_164 ,
V_177 ) ;
F_64 ( V_5 , V_33 ,
V_469 , 1 ) ;
}
V_84 -> V_107 -> V_317 = F_161 ;
return 0 ;
}
static int F_167 ( struct V_4 * V_5 , struct V_83 * V_84 ,
struct V_144 * V_145 )
{
const struct V_102 * V_103 = V_5 -> V_104 ;
struct V_18 * V_19 = V_5 -> V_20 ;
int V_293 = 0 ;
unsigned int V_294 ;
V_293 |= F_129 ( & V_145 -> V_296 , V_298 | V_299 ) ;
V_293 |= F_129 ( & V_145 -> V_300 ,
V_301 | V_299 ) ;
V_293 |= F_129 ( & V_145 -> V_302 , V_297 ) ;
V_293 |= F_129 ( & V_145 -> V_303 , V_161 ) ;
V_293 |= F_129 ( & V_145 -> V_160 , V_161 | V_304 ) ;
if ( V_293 )
return 1 ;
V_293 |= F_130 ( V_145 -> V_296 ) ;
V_293 |= F_130 ( V_145 -> V_300 ) ;
V_293 |= F_130 ( V_145 -> V_160 ) ;
if ( V_293 )
return 2 ;
switch ( V_145 -> V_296 ) {
case V_298 :
V_293 |= F_131 ( & V_145 -> V_305 , 0 ) ;
break;
case V_299 :
V_294 = F_112 ( V_145 -> V_305 ) ;
if ( V_294 > 18 )
V_294 = 18 ;
V_294 |= ( V_145 -> V_305 & ( V_306 | V_307 ) ) ;
V_293 |= F_131 ( & V_145 -> V_305 , V_294 ) ;
break;
}
if ( V_145 -> V_300 == V_301 ) {
V_293 |= F_132 ( & V_145 -> V_308 ,
V_103 -> V_470 ) ;
V_293 |= F_133 ( & V_145 -> V_308 ,
V_19 -> V_287 *
0xffffff ) ;
}
V_293 |= F_131 ( & V_145 -> V_309 , 0 ) ;
V_293 |= F_131 ( & V_145 -> V_310 ,
V_145 -> V_191 ) ;
if ( V_145 -> V_160 == V_161 )
V_293 |= F_133 ( & V_145 -> V_312 , 0x00ffffff ) ;
else
V_293 |= F_131 ( & V_145 -> V_312 , 0 ) ;
if ( V_293 )
return 3 ;
if ( V_145 -> V_300 == V_301 ) {
V_294 = V_145 -> V_308 ;
V_145 -> V_308 =
F_126 ( V_5 , F_125 ( V_5 ,
V_145 -> V_308 ,
V_145 -> V_21 ) ) ;
if ( V_294 != V_145 -> V_308 )
V_293 ++ ;
}
if ( V_293 )
return 4 ;
return 0 ;
}
static int F_168 ( struct V_4 * V_5 , struct V_83 * V_84 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
F_54 ( V_5 ) ;
F_25 ( V_5 , V_419 , V_200 ) ;
F_25 ( V_5 , V_420 , V_414 ) ;
F_64 ( V_5 , V_33 , ~ 0 , 0 ) ;
F_25 ( V_5 , V_460 , V_465 ) ;
F_25 ( V_5 , V_471 , V_177 ) ;
F_25 ( V_5 , V_460 |
V_461 |
V_462 ,
V_465 ) ;
F_25 ( V_5 , 0 , V_454 ) ;
F_25 ( V_5 , 0 , V_467 ) ;
V_19 -> V_413 = 0 ;
F_25 ( V_5 , V_19 -> V_413 , V_414 ) ;
V_19 -> V_416 = 0 ;
F_25 ( V_5 , V_19 -> V_416 , V_417 ) ;
V_19 -> V_425 = 0 ;
F_25 ( V_5 , V_19 -> V_425 , V_428 ) ;
V_19 -> V_436 = 0 ;
F_25 ( V_5 , V_19 -> V_436 , V_438 ) ;
if ( V_19 -> V_22 )
V_19 -> V_403 = V_472 ;
else
V_19 -> V_403 = 0 ;
F_25 ( V_5 , V_19 -> V_403 , V_405 ) ;
V_19 -> V_429 = 0 ;
F_25 ( V_5 , V_19 -> V_429 ,
V_434 ) ;
if ( V_19 -> V_98 ) {
unsigned V_473 = 0 ;
unsigned V_73 ;
for ( V_73 = 0 ; V_73 < V_84 -> V_227 ; ++ V_73 )
V_473 |= 1 << V_73 ;
F_61 ( V_5 , V_473 , V_398 ) ;
F_61 ( V_5 , V_421 ,
V_422 ) ;
}
F_25 ( V_5 , V_468 , V_200 ) ;
return 0 ;
}
static int F_169 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_275 * V_276 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
int V_181 ;
V_181 = F_170 ( V_5 , V_84 , V_276 , V_6 , 0 ) ;
if ( V_181 )
return V_181 ;
V_19 -> V_474 &= ~ V_475 ;
V_19 -> V_474 |= F_171 ( V_84 -> V_476 ) ;
F_25 ( V_5 , V_19 -> V_474 , V_477 ) ;
return V_276 -> V_95 ;
}
static int F_172 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_275 * V_276 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
if ( ( V_6 [ 0 ] & ( V_478 | V_479 ) ) &&
V_19 -> V_480 )
return - V_53 ;
if ( F_173 ( V_84 , V_6 ) ) {
V_19 -> V_481 &= ~ V_482 ;
V_19 -> V_481 |= F_174 ( V_84 -> V_483 ) ;
F_25 ( V_5 , V_19 -> V_481 , V_484 ) ;
}
V_6 [ 1 ] = F_29 ( V_5 , V_485 ) ;
return V_276 -> V_95 ;
}
static int F_175 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_275 * V_276 ,
unsigned int * V_6 )
{
int V_181 ;
V_181 = F_170 ( V_5 , V_84 , V_276 , V_6 , 0 ) ;
if ( V_181 )
return V_181 ;
F_3 ( V_5 , V_84 -> V_476 , V_486 ) ;
return V_276 -> V_95 ;
}
static int F_176 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_275 * V_276 ,
unsigned int * V_6 )
{
if ( F_173 ( V_84 , V_6 ) )
F_3 ( V_5 , V_84 -> V_483 , V_487 ) ;
V_6 [ 1 ] = F_12 ( V_5 , V_487 ) ;
return V_276 -> V_95 ;
}
static int F_177 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_144 * V_145 )
{
int V_73 ;
for ( V_73 = 0 ; V_73 < V_145 -> V_191 ; ++ V_73 ) {
unsigned int V_229 = F_112 ( V_145 -> V_325 [ V_73 ] ) ;
if ( V_229 != V_73 )
return - V_314 ;
}
return 0 ;
}
static int F_178 ( struct V_4 * V_5 ,
struct V_83 * V_84 , struct V_144 * V_145 )
{
int V_293 = 0 ;
int V_294 ;
V_293 |= F_129 ( & V_145 -> V_296 , V_298 ) ;
V_293 |= F_129 ( & V_145 -> V_300 , V_299 ) ;
V_293 |= F_129 ( & V_145 -> V_302 , V_297 ) ;
V_293 |= F_129 ( & V_145 -> V_303 , V_161 ) ;
V_293 |= F_129 ( & V_145 -> V_160 , V_304 ) ;
if ( V_293 )
return 1 ;
V_293 |= F_131 ( & V_145 -> V_305 , 0 ) ;
V_294 = V_145 -> V_308 ;
V_294 &= F_179 ( V_488 , 0 , 0 , V_306 ) ;
if ( V_294 != V_145 -> V_308 )
V_293 |= - V_314 ;
V_293 |= F_131 ( & V_145 -> V_309 , 0 ) ;
V_293 |= F_131 ( & V_145 -> V_310 ,
V_145 -> V_191 ) ;
V_293 |= F_131 ( & V_145 -> V_312 , 0 ) ;
if ( V_293 )
return 3 ;
if ( V_145 -> V_325 && V_145 -> V_191 > 0 )
V_293 |= F_177 ( V_5 , V_84 , V_145 ) ;
if ( V_293 )
return 5 ;
return 0 ;
}
static int F_180 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
unsigned int V_313 )
{
struct V_144 * V_145 = & V_84 -> V_107 -> V_145 ;
const unsigned V_72 = 1000 ;
int V_86 = 0 ;
unsigned V_73 ;
#ifdef F_51
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned long V_21 ;
#endif
if ( V_313 != V_145 -> V_305 )
return - V_314 ;
V_84 -> V_107 -> V_317 = NULL ;
F_102 ( V_84 , V_84 -> V_107 -> V_192 ) ;
#ifdef F_51
F_26 ( & V_19 -> V_50 , V_21 ) ;
if ( V_19 -> V_65 ) {
F_99 ( V_19 -> V_65 , 32 , 32 ) ;
F_100 ( V_19 -> V_65 ) ;
} else {
F_32 ( V_5 -> V_13 , L_25 ) ;
V_86 = - V_193 ;
}
F_27 ( & V_19 -> V_50 , V_21 ) ;
if ( V_86 < 0 )
return V_86 ;
#endif
for ( V_73 = 0 ; V_73 < V_72 ; ++ V_73 ) {
if ( F_12 ( V_5 , V_489 ) &
V_490 )
break;
F_59 ( 10 ) ;
}
if ( V_73 == V_72 ) {
F_32 ( V_5 -> V_13 , L_26 ) ;
V_84 -> V_491 ( V_5 , V_84 ) ;
return - V_193 ;
}
F_3 ( V_5 , V_492 |
V_493 |
V_494 ,
V_495 ) ;
return V_86 ;
}
static int F_181 ( struct V_4 * V_5 , struct V_83 * V_84 )
{
const struct V_144 * V_145 = & V_84 -> V_107 -> V_145 ;
unsigned V_496 ;
int V_86 ;
F_3 ( V_5 , V_497 , V_495 ) ;
V_496 = V_498 |
V_499 |
F_182 ( F_112 ( V_145 -> V_308 ) ) ;
if ( V_145 -> V_308 & V_306 )
V_496 |= V_500 ;
F_3 ( V_5 , V_496 , V_501 ) ;
if ( V_84 -> V_476 ) {
F_3 ( V_5 , V_84 -> V_483 , V_502 ) ;
F_3 ( V_5 , V_503 , V_495 ) ;
F_3 ( V_5 , V_84 -> V_476 , V_504 ) ;
} else {
F_32 ( V_5 -> V_13 ,
L_27 ) ;
return - V_193 ;
}
V_86 = F_50 ( V_5 ) ;
if ( V_86 < 0 )
return V_86 ;
V_84 -> V_107 -> V_317 = F_180 ;
return 0 ;
}
static int F_183 ( struct V_4 * V_5 , struct V_83 * V_84 )
{
F_3 ( V_5 , V_505 |
V_506 |
V_507 |
V_508 ,
V_495 ) ;
F_3 ( V_5 , 0 , V_504 ) ;
F_56 ( V_5 ) ;
return 0 ;
}
static void F_184 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned V_509 ;
struct V_83 * V_84 = & V_5 -> V_130 [ V_510 ] ;
#ifdef F_51
unsigned long V_21 ;
#endif
if ( ! V_19 -> V_22 )
return;
#ifdef F_51
F_26 ( & V_19 -> V_50 , V_21 ) ;
if ( V_19 -> V_65 ) {
unsigned V_511 =
F_185 ( V_19 -> V_65 ) ;
if ( V_511 & V_147 ) {
F_4 ( V_512 ,
V_19 -> V_24 -> V_513 +
F_186 ( V_19 -> V_65 -> V_41 ) ) ;
}
F_70 ( V_19 -> V_65 , V_84 ) ;
}
F_27 ( & V_19 -> V_50 , V_21 ) ;
#endif
V_509 = F_12 ( V_5 , V_489 ) ;
if ( V_509 & V_514 ) {
F_3 ( V_5 , V_515 ,
V_495 ) ;
V_84 -> V_107 -> V_108 |= V_109 ;
}
if ( V_509 & V_516 ) {
F_3 ( V_5 , V_507 ,
V_495 ) ;
}
F_88 ( V_5 , V_84 ) ;
}
static int F_187 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
unsigned char V_517 ,
unsigned char * V_518 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_519 ;
int V_293 = 0 , V_223 = 20 ;
V_19 -> V_481 &= ~ V_520 ;
V_19 -> V_481 |= F_188 ( V_517 ) ;
F_25 ( V_5 , V_19 -> V_481 , V_484 ) ;
V_519 = F_29 ( V_5 , V_521 ) ;
if ( V_519 & V_522 ) {
V_293 = - V_53 ;
goto Error;
}
V_19 -> V_474 |= V_523 ;
F_25 ( V_5 , V_19 -> V_474 , V_477 ) ;
V_19 -> V_474 &= ~ V_523 ;
while ( ( V_519 = F_29 ( V_5 , V_521 ) ) &
V_522 ) {
F_59 ( ( V_19 -> V_480 + 999 ) / 1000 ) ;
if ( -- V_223 < 0 ) {
F_32 ( V_5 -> V_13 ,
L_28 ) ;
V_293 = - V_281 ;
goto Error;
}
}
F_59 ( ( V_19 -> V_480 + 999 ) / 1000 ) ;
if ( V_518 )
* V_518 = F_29 ( V_5 , V_524 ) ;
Error:
F_25 ( V_5 , V_19 -> V_474 , V_477 ) ;
return V_293 ;
}
static int F_189 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
unsigned char V_517 ,
unsigned char * V_518 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned char V_277 , V_525 = 0 ;
F_59 ( ( V_19 -> V_480 + 999 ) / 1000 ) ;
for ( V_277 = 0x80 ; V_277 ; V_277 >>= 1 ) {
V_19 -> V_481 &= ~ V_479 ;
if ( V_517 & V_277 )
V_19 -> V_481 |= V_479 ;
F_25 ( V_5 , V_19 -> V_481 , V_484 ) ;
V_19 -> V_474 |= V_526 ;
F_25 ( V_5 , V_19 -> V_474 , V_477 ) ;
F_59 ( ( V_19 -> V_480 + 999 ) / 2000 ) ;
V_19 -> V_474 &= ~ V_526 ;
F_25 ( V_5 , V_19 -> V_474 , V_477 ) ;
F_59 ( ( V_19 -> V_480 + 999 ) / 2000 ) ;
if ( F_29 ( V_5 , V_485 ) & V_478 )
V_525 |= V_277 ;
}
if ( V_518 )
* V_518 = V_525 ;
return 0 ;
}
static int F_190 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_275 * V_276 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned V_527 = V_19 -> V_528 ;
int V_293 = V_276 -> V_95 ;
unsigned char V_529 , V_530 = 0 ;
if ( V_276 -> V_95 != 2 )
return - V_314 ;
switch ( V_6 [ 0 ] ) {
case V_531 :
V_19 -> V_532 = 1 ;
V_19 -> V_474 |= V_533 ;
if ( V_6 [ 1 ] == V_534 ) {
V_19 -> V_532 = 0 ;
V_19 -> V_474 &= ~ ( V_533 |
V_526 ) ;
V_6 [ 1 ] = V_534 ;
V_19 -> V_480 = V_6 [ 1 ] ;
} else if ( V_6 [ 1 ] <= V_535 ) {
V_19 -> V_474 &= ~ V_536 ;
V_527 |= V_537 ;
V_527 &= ~ V_538 ;
V_6 [ 1 ] = V_535 ;
V_19 -> V_480 = V_6 [ 1 ] ;
} else if ( V_6 [ 1 ] <= V_539 ) {
V_19 -> V_474 &= ~ V_536 ;
V_527 |= V_537 |
V_538 ;
V_6 [ 1 ] = V_539 ;
V_19 -> V_480 = V_6 [ 1 ] ;
} else if ( V_6 [ 1 ] <= V_540 ) {
V_19 -> V_474 |= V_536 ;
V_527 |= V_537 |
V_538 ;
V_6 [ 1 ] = V_540 ;
V_19 -> V_480 = V_6 [ 1 ] ;
} else {
V_19 -> V_474 &= ~ ( V_533 |
V_526 ) ;
V_19 -> V_532 = 0 ;
V_6 [ 1 ] = ( V_6 [ 1 ] / 1000 ) * 1000 ;
V_19 -> V_480 = V_6 [ 1 ] ;
}
V_19 -> V_528 = V_527 ;
F_25 ( V_5 , V_19 -> V_474 , V_477 ) ;
F_25 ( V_5 , V_19 -> V_528 , V_541 ) ;
return 1 ;
case V_542 :
if ( V_19 -> V_480 == 0 )
return - V_314 ;
V_529 = V_6 [ 1 ] & 0xFF ;
if ( V_19 -> V_532 ) {
V_293 = F_187 ( V_5 , V_84 , V_529 ,
& V_530 ) ;
} else if ( V_19 -> V_480 > 0 ) {
V_293 = F_189 ( V_5 , V_84 , V_529 ,
& V_530 ) ;
} else {
F_32 ( V_5 -> V_13 , L_29 ) ;
return - V_314 ;
}
if ( V_293 < 0 )
return V_293 ;
V_6 [ 1 ] = V_530 & 0xFF ;
return V_276 -> V_95 ;
break;
default:
return - V_314 ;
}
}
static void F_191 ( struct V_4 * V_5 , struct V_83 * V_84 )
{
int V_73 ;
for ( V_73 = 0 ; V_73 < V_84 -> V_227 ; V_73 ++ ) {
F_61 ( V_5 , F_152 ( V_73 ) | 0x0 ,
V_543 ) ;
}
F_61 ( V_5 , 0x0 , V_544 ) ;
}
static unsigned int F_192 ( struct V_4 * V_5 ,
enum V_545 V_7 )
{
const struct V_10 * V_11 ;
if ( V_7 < F_22 ( V_546 ) ) {
V_11 = & V_546 [ V_7 ] ;
} else {
F_23 ( V_5 -> V_13 , L_1 ,
V_14 , V_7 ) ;
return 0 ;
}
return V_11 -> V_16 ;
}
static void F_193 ( struct V_547 * V_548 , unsigned V_42 ,
enum V_545 V_7 )
{
struct V_4 * V_5 = V_548 -> V_62 -> V_5 ;
unsigned int V_549 = F_192 ( V_5 , V_7 ) ;
static const unsigned V_550 =
V_69 | V_551 ;
static const unsigned V_552 =
V_71 | V_553 ;
if ( V_549 == 0 )
return;
switch ( V_7 ) {
case V_554 :
case V_555 :
case V_556 :
case V_557 :
case V_558 :
case V_559 :
case V_560 :
case V_561 :
F_6 ( V_5 , V_42 , V_549 ) ;
break;
case V_562 :
case V_563 :
case V_564 :
case V_565 :
F_28 ( V_5 , V_42 , V_549 ) ;
break;
case V_566 :
F_45 ( V_42 & ~ V_550 ) ;
F_31 ( V_5 , V_549 ,
V_550 , V_42 ) ;
break;
case V_567 :
F_45 ( V_42 & ~ V_552 ) ;
F_31 ( V_5 , V_549 ,
V_552 , V_42 ) ;
break;
case V_568 :
F_45 ( V_42 & ~ ( V_569 | V_570 ) ) ;
default:
F_25 ( V_5 , V_42 , V_549 ) ;
}
}
static unsigned F_194 ( struct V_547 * V_548 ,
enum V_545 V_7 )
{
struct V_4 * V_5 = V_548 -> V_62 -> V_5 ;
unsigned int V_549 = F_192 ( V_5 , V_7 ) ;
if ( V_549 == 0 )
return 0 ;
switch ( V_7 ) {
case V_571 :
case V_572 :
return F_15 ( V_5 , V_549 ) ;
case V_573 :
case V_574 :
case V_575 :
case V_576 :
return F_30 ( V_5 , V_549 ) ;
default:
return F_29 ( V_5 , V_549 ) ;
}
}
static int F_195 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_275 * V_276 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_27 = F_196 ( V_19 -> V_528 ) ;
int V_73 ;
for ( V_73 = 0 ; V_73 < V_276 -> V_95 ; V_73 ++ )
V_6 [ V_73 ] = V_27 ;
return V_276 -> V_95 ;
}
static int F_197 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_275 * V_276 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
if ( V_276 -> V_95 ) {
unsigned int V_27 = V_6 [ V_276 -> V_95 - 1 ] ;
V_19 -> V_528 &= ~ V_577 ;
F_25 ( V_5 , V_19 -> V_528 , V_541 ) ;
V_19 -> V_528 &= ~ V_578 ;
V_19 -> V_528 |= F_198 ( V_27 ) ;
V_19 -> V_528 |= V_577 ;
F_25 ( V_5 , V_19 -> V_528 , V_541 ) ;
}
return V_276 -> V_95 ;
}
static int F_199 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_275 * V_276 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
switch ( V_6 [ 0 ] ) {
case V_579 :
switch ( V_6 [ 1 ] ) {
case V_580 :
V_19 -> V_528 &= ~ V_581 ;
break;
case V_582 :
V_19 -> V_528 |= V_581 ;
break;
default:
return - V_314 ;
}
F_25 ( V_5 , V_19 -> V_528 , V_541 ) ;
break;
case V_583 :
if ( V_19 -> V_528 & V_581 ) {
V_6 [ 1 ] = V_582 ;
V_6 [ 2 ] = V_584 ;
} else {
V_6 [ 1 ] = V_580 ;
V_6 [ 2 ] = V_585 * 2 ;
}
break;
default:
return - V_314 ;
}
return V_276 -> V_95 ;
}
static int F_200 ( struct V_4 * V_5 ,
int V_54 , int V_586 , int V_6 , unsigned long V_9 )
{
if ( V_54 ) {
F_9 ( V_5 , V_6 , V_9 + 2 * V_586 ) ;
return 0 ;
}
return F_18 ( V_5 , V_9 + 2 * V_586 ) ;
}
static int F_201 ( struct V_4 * V_5 , unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
V_6 [ 1 ] = V_19 -> V_587 * V_19 -> V_287 ;
V_6 [ 2 ] = V_19 -> V_588 * V_19 -> V_287 ;
return 3 ;
}
static int F_202 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_275 * V_276 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned V_589 , V_590 ;
switch ( V_6 [ 0 ] ) {
case V_591 :
switch ( V_6 [ 1 ] ) {
case V_286 :
V_589 =
( V_6 [ 2 ] +
V_19 -> V_287 / 2 ) / V_19 -> V_287 ;
break;
case V_288 :
V_589 = V_6 [ 2 ] / V_19 -> V_287 ;
break;
case V_289 :
V_589 =
( V_6 [ 2 ] + V_19 -> V_287 -
1 ) / V_19 -> V_287 ;
break;
default:
return - V_314 ;
}
switch ( V_6 [ 3 ] ) {
case V_286 :
V_590 =
( V_6 [ 4 ] +
V_19 -> V_287 / 2 ) / V_19 -> V_287 ;
break;
case V_288 :
V_590 = V_6 [ 4 ] / V_19 -> V_287 ;
break;
case V_289 :
V_590 =
( V_6 [ 4 ] + V_19 -> V_287 -
1 ) / V_19 -> V_287 ;
break;
default:
return - V_314 ;
}
if ( V_589 * V_19 -> V_287 != V_6 [ 2 ] ||
V_590 * V_19 -> V_287 != V_6 [ 4 ] ) {
V_6 [ 2 ] = V_589 * V_19 -> V_287 ;
V_6 [ 4 ] = V_590 * V_19 -> V_287 ;
return - V_592 ;
}
F_3 ( V_5 , F_203 ( V_589 ) |
F_204 ( V_590 ) ,
V_593 ) ;
V_19 -> V_587 = V_589 ;
V_19 -> V_588 = V_590 ;
return 5 ;
case V_594 :
return F_201 ( V_5 , V_6 ) ;
default:
return - V_314 ;
}
return 0 ;
}
static int F_205 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_275 * V_276 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned V_589 , V_590 ;
switch ( V_6 [ 0 ] ) {
case V_591 :
switch ( V_6 [ 1 ] ) {
case V_286 :
V_589 =
( V_6 [ 2 ] +
V_19 -> V_287 / 2 ) / V_19 -> V_287 ;
break;
case V_288 :
V_589 = V_6 [ 2 ] / V_19 -> V_287 ;
break;
case V_289 :
V_589 =
( V_6 [ 2 ] + V_19 -> V_287 -
1 ) / V_19 -> V_287 ;
break;
default:
return - V_314 ;
}
switch ( V_6 [ 3 ] ) {
case V_286 :
V_590 =
( V_6 [ 4 ] +
V_19 -> V_287 / 2 ) / V_19 -> V_287 ;
break;
case V_288 :
V_590 = V_6 [ 4 ] / V_19 -> V_287 ;
break;
case V_289 :
V_590 =
( V_6 [ 4 ] + V_19 -> V_287 -
1 ) / V_19 -> V_287 ;
break;
default:
return - V_314 ;
}
if ( V_589 * V_19 -> V_287 != V_6 [ 2 ] ||
V_590 * V_19 -> V_287 != V_6 [ 4 ] ) {
V_6 [ 2 ] = V_589 * V_19 -> V_287 ;
V_6 [ 4 ] = V_590 * V_19 -> V_287 ;
return - V_592 ;
}
F_3 ( V_5 , V_589 , V_595 ) ;
V_19 -> V_587 = V_589 ;
F_3 ( V_5 , V_590 , V_596 ) ;
V_19 -> V_588 = V_590 ;
return 5 ;
case V_594 :
return F_201 ( V_5 , V_6 ) ;
default:
return - V_314 ;
}
return 0 ;
}
static int F_206 ( int V_79 , int V_27 , int * V_597 )
{
V_79 ++ ;
* V_597 = ( ( V_79 & 0x1 ) << 11 ) |
( ( V_79 & 0x2 ) << 9 ) |
( ( V_79 & 0x4 ) << 7 ) | ( ( V_79 & 0x8 ) << 5 ) | ( V_27 & 0xff ) ;
return 12 ;
}
static int F_207 ( int V_79 , int V_27 , int * V_597 )
{
* V_597 = ( ( V_79 & 0x7 ) << 8 ) | ( V_27 & 0xff ) ;
return 11 ;
}
static int F_208 ( int V_79 , int V_27 , int * V_597 )
{
* V_597 = V_27 & 0xfff ;
return 12 ;
}
static int F_209 ( int V_79 , int V_27 , int * V_597 )
{
* V_597 = ( V_27 & 0xfff ) | ( V_79 ? 0xc000 : 0xa000 ) ;
return 16 ;
}
static int F_210 ( int V_79 , int V_27 , int * V_597 )
{
* V_597 = ( ( V_79 & 0xf ) << 8 ) | ( V_27 & 0xff ) ;
return 12 ;
}
static int F_211 ( int V_79 , int V_27 , int * V_597 )
{
* V_597 = ( ( V_79 + 1 ) << 8 ) | ( V_27 & 0xff ) ;
return 12 ;
}
static void F_212 ( struct V_4 * V_5 , int V_79 , int V_27 )
{
const struct V_102 * V_103 = V_5 -> V_104 ;
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_598 = 0 , V_42 = 0 , V_599 , V_597 = 0 ;
unsigned int V_145 ;
int V_73 ;
int type ;
if ( V_19 -> V_600 [ V_79 ] == V_27 )
return;
V_19 -> V_600 [ V_79 ] = V_27 ;
for ( V_73 = 0 ; V_73 < 3 ; V_73 ++ ) {
type = V_103 -> V_601 [ V_73 ] ;
if ( type == V_602 )
break;
if ( V_79 < V_600 [ type ] . V_376 ) {
V_42 = V_600 [ type ] . F_213 ( V_79 , V_27 , & V_597 ) ;
V_598 = F_214 ( V_73 ) ;
break;
}
V_79 -= V_600 [ type ] . V_376 ;
}
if ( V_42 == 0 )
return;
for ( V_599 = 1 << ( V_42 - 1 ) ; V_599 ; V_599 >>= 1 ) {
V_145 = ( V_599 & V_597 ) ? V_603 : 0 ;
F_9 ( V_5 , V_145 , V_604 ) ;
F_59 ( 1 ) ;
F_9 ( V_5 , V_605 | V_145 , V_604 ) ;
F_59 ( 1 ) ;
}
F_9 ( V_5 , V_598 , V_604 ) ;
F_59 ( 1 ) ;
F_9 ( V_5 , 0 , V_604 ) ;
}
static int F_215 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_275 * V_276 ,
unsigned int * V_6 )
{
F_212 ( V_5 , F_112 ( V_276 -> V_279 ) , V_6 [ 0 ] ) ;
return 1 ;
}
static int F_216 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_275 * V_276 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
V_6 [ 0 ] = V_19 -> V_600 [ F_112 ( V_276 -> V_279 ) ] ;
return 1 ;
}
static void F_217 ( struct V_4 * V_5 , struct V_83 * V_84 )
{
const struct V_102 * V_103 = V_5 -> V_104 ;
struct V_18 * V_19 = V_5 -> V_20 ;
int V_73 , V_606 ;
int V_607 ;
int V_376 = 0 ;
int V_608 ;
int V_609 = 0 ;
int type ;
int V_229 ;
type = V_103 -> V_601 [ 0 ] ;
if ( type == V_602 )
return;
V_608 = V_600 [ type ] . V_608 ;
for ( V_73 = 0 ; V_73 < 3 ; V_73 ++ ) {
type = V_103 -> V_601 [ V_73 ] ;
if ( type == V_602 )
break;
if ( V_600 [ type ] . V_608 != V_608 )
V_609 = 1 ;
V_376 += V_600 [ type ] . V_376 ;
}
V_607 = V_73 ;
V_84 -> V_227 = V_376 ;
if ( V_609 ) {
unsigned int * V_610 ;
if ( V_376 > V_611 )
F_32 ( V_5 -> V_13 ,
L_30 ) ;
V_84 -> V_610 = V_610 = V_19 -> V_612 ;
V_229 = 0 ;
for ( V_73 = 0 ; V_73 < V_607 ; V_73 ++ ) {
type = V_103 -> V_601 [ V_73 ] ;
for ( V_606 = 0 ; V_606 < V_600 [ type ] . V_376 ; V_606 ++ ) {
V_610 [ V_229 ] =
( 1 << V_600 [ type ] . V_608 ) - 1 ;
V_229 ++ ;
}
}
for ( V_229 = 0 ; V_229 < V_84 -> V_227 ; V_229 ++ )
F_212 ( V_5 , V_73 , V_84 -> V_610 [ V_73 ] / 2 ) ;
} else {
type = V_103 -> V_601 [ 0 ] ;
V_84 -> V_258 = ( 1 << V_600 [ type ] . V_608 ) - 1 ;
for ( V_229 = 0 ; V_229 < V_84 -> V_227 ; V_229 ++ )
F_212 ( V_5 , V_73 , V_84 -> V_258 / 2 ) ;
}
}
static int F_218 ( struct V_4 * V_5 , int V_79 )
{
unsigned int V_145 = V_613 ;
int V_599 ;
int V_597 ;
V_597 = 0x0300 | ( ( V_79 & 0x100 ) << 3 ) | ( V_79 & 0xff ) ;
F_9 ( V_5 , V_145 , V_604 ) ;
for ( V_599 = 0x8000 ; V_599 ; V_599 >>= 1 ) {
if ( V_599 & V_597 )
V_145 |= V_603 ;
else
V_145 &= ~ V_603 ;
F_9 ( V_5 , V_145 , V_604 ) ;
F_9 ( V_5 , V_605 | V_145 , V_604 ) ;
}
V_145 = V_613 ;
V_597 = 0 ;
for ( V_599 = 0x80 ; V_599 ; V_599 >>= 1 ) {
F_9 ( V_5 , V_145 , V_604 ) ;
F_9 ( V_5 , V_605 | V_145 , V_604 ) ;
if ( F_18 ( V_5 , V_123 ) & V_614 )
V_597 |= V_599 ;
}
F_9 ( V_5 , 0 , V_604 ) ;
return V_597 ;
}
static int F_219 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_275 * V_276 ,
unsigned int * V_6 )
{
V_6 [ 0 ] = F_218 ( V_5 , F_112 ( V_276 -> V_279 ) ) ;
return 1 ;
}
static int F_220 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_275 * V_276 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
V_6 [ 0 ] = V_19 -> V_615 [ F_112 ( V_276 -> V_279 ) ] ;
return 1 ;
}
static unsigned F_221 ( struct V_4 * V_5 ,
unsigned V_229 )
{
switch ( V_229 ) {
case 0 :
return V_616 ;
case 1 :
return V_617 ;
case 2 :
return V_618 ;
case 3 :
return V_619 ;
case 4 :
return V_620 ;
case 5 :
return V_621 ;
case 6 :
return V_622 ;
case 7 :
return V_623 ;
case 8 :
return V_624 ;
case 9 :
return V_625 ;
default:
F_32 ( V_5 -> V_13 , L_31 ) ;
break;
}
return 0 ;
}
static int F_222 ( struct V_4 * V_5 ,
unsigned V_229 , unsigned V_626 )
{
if ( V_626 != F_221 ( V_5 , V_229 ) )
return - V_314 ;
return 2 ;
}
static unsigned F_223 ( struct V_4 * V_5 ,
unsigned V_229 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
const unsigned V_627 = V_229 / 3 ;
return F_224 ( V_229 ,
V_19 -> V_628 [ V_627 ] ) ;
}
static int F_225 ( struct V_4 * V_5 ,
unsigned V_229 , unsigned V_626 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned V_629 = V_229 / 3 ;
unsigned short V_27 = V_19 -> V_628 [ V_629 ] ;
if ( ( V_626 & 0x1f ) != V_626 )
return - V_314 ;
V_27 &= ~ F_226 ( V_229 ) ;
V_27 |= F_227 ( V_229 , V_626 ) ;
F_6 ( V_5 , V_27 , F_228 ( V_629 ) ) ;
V_19 -> V_628 [ V_629 ] = V_27 ;
return 2 ;
}
static unsigned F_229 ( struct V_4 * V_5 , unsigned V_229 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
return ( V_19 -> V_22 )
? F_223 ( V_5 , V_229 )
: F_221 ( V_5 , V_229 ) ;
}
static int F_230 ( struct V_4 * V_5 , unsigned V_229 ,
unsigned V_626 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
return ( V_19 -> V_22 )
? F_225 ( V_5 , V_229 , V_626 )
: F_222 ( V_5 , V_229 , V_626 ) ;
}
static int F_231 ( struct V_4 * V_5 ,
unsigned V_630 ,
enum V_631 V_632 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned V_42 ;
if ( ! V_19 -> V_22 )
return - V_633 ;
V_42 = F_12 ( V_5 , V_634 ) ;
V_42 &= ~ F_232 ( V_630 ) ;
V_42 |= F_233 ( V_630 , V_632 ) ;
F_3 ( V_5 , V_42 , V_634 ) ;
return 0 ;
}
static int F_234 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_275 * V_276 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_229 ;
if ( V_276 -> V_95 < 1 )
return - V_314 ;
V_229 = F_112 ( V_276 -> V_279 ) ;
switch ( V_6 [ 0 ] ) {
case V_58 :
F_64 ( V_5 , V_35 , 1 << V_229 , 1 ) ;
break;
case V_55 :
F_64 ( V_5 , V_35 , 1 << V_229 , 0 ) ;
break;
case V_635 :
V_6 [ 1 ] =
( V_19 -> V_36 & ( 1 << V_229 ) ) ?
V_58 : V_55 ;
return 0 ;
case V_636 :
return F_230 ( V_5 , V_229 , V_6 [ 1 ] ) ;
case V_637 :
V_6 [ 1 ] = F_229 ( V_5 , V_229 ) ;
break;
case V_638 :
return F_231 ( V_5 , V_229 , V_6 [ 1 ] ) ;
default:
return - V_314 ;
}
return 0 ;
}
static int F_235 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_275 * V_276 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
if ( ! V_19 -> V_22 )
return - V_633 ;
if ( F_173 ( V_84 , V_6 ) )
F_6 ( V_5 , V_84 -> V_483 , V_639 ) ;
V_6 [ 1 ] = F_15 ( V_5 , V_640 ) ;
return V_276 -> V_95 ;
}
static int F_236 ( struct V_4 * V_5 )
{
unsigned short V_142 ;
const int V_72 = V_641 ;
int V_73 ;
for ( V_73 = 0 ; V_73 < V_72 ; V_73 ++ ) {
V_142 = F_63 ( V_5 , V_642 ) ;
if ( ( V_142 & V_643 ) == 0 )
break;
F_237 ( V_644 ) ;
if ( F_238 ( 1 ) )
return - V_193 ;
}
if ( V_73 == V_72 ) {
F_32 ( V_5 -> V_13 , L_20 ) ;
return - V_281 ;
}
return 0 ;
}
static void F_239 ( struct V_4 * V_5 , unsigned short V_82 )
{
static const int V_72 = 100 ;
int V_73 ;
F_61 ( V_5 , V_82 , V_645 ) ;
for ( V_73 = 0 ; V_73 < V_72 ; V_73 ++ ) {
if ( F_63 ( V_5 , V_642 ) &
V_643 )
break;
F_59 ( 1 ) ;
}
if ( V_73 == V_72 )
F_32 ( V_5 -> V_13 ,
L_32 ) ;
}
static int F_240 ( struct V_4 * V_5 ,
unsigned short * V_6 )
{
int V_86 ;
unsigned short V_142 ;
F_239 ( V_5 , V_646 | V_647 ) ;
V_86 = F_236 ( V_5 ) ;
if ( V_86 ) {
F_32 ( V_5 -> V_13 ,
L_33 ) ;
return - V_281 ;
}
V_142 = F_63 ( V_5 , V_642 ) ;
if ( V_142 & V_648 ) {
F_32 ( V_5 -> V_13 ,
L_34 ) ;
return - V_193 ;
}
if ( V_142 & V_649 ) {
F_32 ( V_5 -> V_13 ,
L_35 ) ;
}
if ( V_6 ) {
* V_6 = F_63 ( V_5 , V_650 ) ;
* V_6 ^= ( 1 << 15 ) ;
}
return 0 ;
}
static int F_241 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_275 * V_276 ,
unsigned int * V_6 )
{
int V_95 , V_86 ;
unsigned short V_651 ;
unsigned int V_652 ;
const unsigned int V_653 = 0x1000 ;
if ( V_276 -> V_279 & V_235 )
V_652 = V_653 ;
else
V_652 = F_112 ( V_276 -> V_279 ) ;
F_61 ( V_5 , V_652 , V_654 ) ;
for ( V_95 = 0 ; V_95 < V_276 -> V_95 ; V_95 ++ ) {
V_86 = F_240 ( V_5 , & V_651 ) ;
if ( V_86 < 0 )
return V_86 ;
V_6 [ V_95 ] = V_651 ;
}
return V_276 -> V_95 ;
}
static void F_242 ( struct V_4 * V_5 , unsigned int V_82 ,
unsigned int V_655 )
{
F_61 ( V_5 , ( V_82 >> 16 ) & 0xff , V_656 ) ;
F_61 ( V_5 , V_82 & 0xffff , V_657 ) ;
V_655 &= V_658 ;
F_239 ( V_5 , V_646 | V_655 ) ;
if ( F_236 ( V_5 ) )
F_32 ( V_5 -> V_13 ,
L_36 , V_14 ) ;
}
static int F_243 ( struct V_4 * V_5 )
{
unsigned int V_245 = V_659 |
V_660 ;
#if 1
F_242 ( V_5 , V_245 | V_661 ,
V_662 ) ;
F_240 ( V_5 , NULL ) ;
#else
F_242 ( V_5 , 0x400000 , V_663 ) ;
F_242 ( V_5 , V_245 | V_664 ,
V_662 ) ;
if ( F_236 ( V_5 ) )
F_32 ( V_5 -> V_13 ,
L_36 , V_14 ) ;
#endif
return 0 ;
}
static int F_244 ( unsigned V_665 ,
unsigned * V_666 ,
unsigned * V_667 ,
unsigned * V_668 )
{
unsigned div ;
unsigned V_669 = 1 ;
unsigned V_670 ;
unsigned V_671 = 1 ;
static const unsigned V_672 = 1000 ;
const unsigned V_673 = V_665 * V_672 ;
static const unsigned V_674 = 12500 ;
static const unsigned V_675 = 4 ;
int V_676 = 0 ;
for ( div = 1 ; div <= V_677 ; ++ div ) {
for ( V_670 = 1 ; V_670 <= V_678 ; ++ V_670 ) {
unsigned V_679 =
( V_673 * div ) / V_670 ;
if ( abs ( V_679 - V_674 ) <
abs ( V_676 - V_674 ) ) {
V_676 = V_679 ;
V_669 = div ;
V_671 = V_670 ;
}
}
}
if ( V_676 == 0 )
return - V_193 ;
* V_666 = V_669 ;
* V_667 = V_671 ;
* V_668 =
( V_676 * V_675 +
( V_672 / 2 ) ) / V_672 ;
return 0 ;
}
static int F_245 ( struct V_4 * V_5 ,
unsigned V_626 , unsigned V_680 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
static const unsigned V_681 = 50 ;
static const unsigned V_682 = 1000 ;
static const unsigned V_72 = 1000 ;
unsigned V_683 ;
unsigned V_666 ;
unsigned V_667 ;
unsigned V_684 ;
unsigned V_73 ;
int V_86 ;
if ( V_626 == V_685 )
V_680 = 100 ;
if ( V_680 < V_681 || V_680 > V_682 ) {
F_32 ( V_5 -> V_13 ,
L_37 ,
V_14 , V_681 , V_682 ) ;
return - V_314 ;
}
V_19 -> V_686 &= ~ V_687 ;
F_25 ( V_5 , V_19 -> V_686 ,
V_688 ) ;
V_683 = V_689 | V_690 ;
V_19 -> V_691 |= V_692 |
V_693 ;
V_19 -> V_691 &= ~ V_694 ;
switch ( V_626 ) {
case V_695 :
V_19 -> V_691 |= V_696 ;
break;
case V_685 :
V_19 -> V_691 |= V_697 ;
break;
default:
for ( V_684 = 0 ; V_684 <= V_698 ; ++ V_684 ) {
if ( V_626 == F_246 ( V_684 ) ) {
V_19 -> V_691 |=
F_247 ( V_684 ) ;
break;
}
}
if ( V_684 > V_698 )
return - V_314 ;
break;
}
V_86 = F_244 ( V_680 ,
& V_666 ,
& V_667 ,
& V_19 -> V_287 ) ;
if ( V_86 < 0 ) {
F_32 ( V_5 -> V_13 ,
L_38 ) ;
return V_86 ;
}
F_6 ( V_5 , V_19 -> V_691 , V_699 ) ;
V_683 |= F_248 ( V_666 ) |
F_249 ( V_667 ) ;
F_6 ( V_5 , V_683 , V_700 ) ;
V_19 -> V_701 = V_626 ;
for ( V_73 = 0 ; V_73 < V_72 ; ++ V_73 ) {
if ( F_15 ( V_5 , V_702 ) & V_703 )
break;
F_59 ( 1 ) ;
}
if ( V_73 == V_72 ) {
F_32 ( V_5 -> V_13 ,
L_39 ,
V_14 , V_626 , V_680 ) ;
return - V_704 ;
}
return 3 ;
}
static int F_250 ( struct V_4 * V_5 ,
unsigned V_626 , unsigned V_680 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
if ( V_626 == V_705 ) {
V_19 -> V_686 &= ~ V_687 ;
F_25 ( V_5 , V_19 -> V_686 ,
V_688 ) ;
V_19 -> V_287 = V_585 ;
if ( V_19 -> V_22 ) {
V_19 -> V_691 &=
~ ( V_692 |
V_693 ) ;
F_6 ( V_5 , V_19 -> V_691 ,
V_699 ) ;
F_6 ( V_5 , 0 , V_700 ) ;
}
V_19 -> V_701 = V_626 ;
} else {
if ( V_19 -> V_22 ) {
return F_245 ( V_5 , V_626 ,
V_680 ) ;
} else {
if ( V_626 == V_706 ) {
V_19 -> V_686 |=
V_687 ;
F_25 ( V_5 ,
V_19 -> V_686 ,
V_688 ) ;
if ( V_680 == 0 ) {
F_32 ( V_5 -> V_13 ,
L_40 ) ;
return - V_314 ;
}
V_19 -> V_287 = V_680 ;
V_19 -> V_701 = V_626 ;
} else {
return - V_314 ;
}
}
}
return 3 ;
}
static int F_251 ( struct V_4 * V_5 ,
unsigned V_229 , unsigned V_626 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
if ( V_229 >= F_252 ( V_19 -> V_22 ) ) {
if ( V_229 == V_707 ) {
if ( V_626 == V_708 )
return 1 ;
F_32 ( V_5 -> V_13 ,
L_41 ,
V_14 , V_229 , V_707 ) ;
return 0 ;
}
return 0 ;
}
switch ( V_626 ) {
case V_709 :
case V_710 :
case V_711 :
case V_712 :
case V_713 :
case V_714 :
case V_715 :
case V_716 :
case V_717 :
return 1 ;
case V_708 :
return ( V_19 -> V_22 ) ? 1 : 0 ;
default:
return 0 ;
}
}
static int F_253 ( struct V_4 * V_5 ,
unsigned V_229 , unsigned V_718 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
if ( F_251 ( V_5 , V_229 , V_718 ) == 0 )
return - V_314 ;
if ( V_229 < 4 ) {
V_19 -> V_719 &= ~ F_254 ( V_229 ) ;
V_19 -> V_719 |= F_255 ( V_229 , V_718 ) ;
F_25 ( V_5 , V_19 -> V_719 ,
V_720 ) ;
} else if ( V_229 < 8 ) {
V_19 -> V_721 &= ~ F_254 ( V_229 ) ;
V_19 -> V_721 |= F_255 ( V_229 , V_718 ) ;
F_25 ( V_5 , V_19 -> V_721 ,
V_722 ) ;
}
return 2 ;
}
static unsigned F_256 ( struct V_4 * V_5 , unsigned V_229 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
if ( V_229 < 4 ) {
return F_257 ( V_229 ,
V_19 -> V_719 ) ;
} else if ( V_229 < F_252 ( V_19 -> V_22 ) ) {
return F_257 ( V_229 ,
V_19 -> V_721 ) ;
} else {
if ( V_229 == V_707 )
return V_708 ;
F_32 ( V_5 -> V_13 , L_42 ) ;
return 0 ;
}
}
static int F_258 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_275 * V_276 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_229 = F_112 ( V_276 -> V_279 ) ;
unsigned int V_723 = F_252 ( V_19 -> V_22 ) ;
switch ( V_6 [ 0 ] ) {
case V_724 :
if ( V_229 < V_723 ) {
V_19 -> V_686 |=
F_259 ( V_229 , V_19 -> V_22 ) ;
} else if ( V_229 == V_707 ) {
V_19 -> V_686 |=
V_725 ;
}
F_25 ( V_5 , V_19 -> V_686 ,
V_688 ) ;
break;
case V_726 :
if ( V_229 < V_723 ) {
V_19 -> V_686 &=
~ F_259 ( V_229 , V_19 -> V_22 ) ;
} else if ( V_229 == V_707 ) {
V_19 -> V_686 &=
~ V_725 ;
}
F_25 ( V_5 , V_19 -> V_686 ,
V_688 ) ;
break;
case V_635 :
if ( V_229 < V_723 ) {
V_6 [ 1 ] =
( V_19 -> V_686 &
F_259 ( V_229 , V_19 -> V_22 ) )
? V_724
: V_726 ;
} else if ( V_229 == V_707 ) {
V_6 [ 1 ] = ( V_19 -> V_686 &
V_725 )
? V_724
: V_726 ;
}
return 2 ;
case V_579 :
return F_250 ( V_5 , V_6 [ 1 ] , V_6 [ 2 ] ) ;
case V_583 :
V_6 [ 1 ] = V_19 -> V_701 ;
V_6 [ 2 ] = V_19 -> V_287 ;
return 3 ;
case V_636 :
return F_253 ( V_5 , V_229 , V_6 [ 1 ] ) ;
case V_637 :
V_6 [ 1 ] = F_256 ( V_5 , V_229 ) ;
return 2 ;
default:
return - V_314 ;
}
return 1 ;
}
static int F_260 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_275 * V_276 ,
unsigned int * V_6 )
{
V_6 [ 1 ] = 0 ;
return V_276 -> V_95 ;
}
static void F_261 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
V_19 -> V_691 = V_727 ;
if ( F_250 ( V_5 , V_705 , 0 ) < 0 )
F_32 ( V_5 -> V_13 , L_43 ) ;
V_19 -> V_719 =
F_255 ( 0 , V_709 ) |
F_255 ( 1 , V_710 ) |
F_255 ( 2 , V_711 ) |
F_255 ( 3 , V_712 ) ;
F_25 ( V_5 , V_19 -> V_719 ,
V_720 ) ;
V_19 -> V_721 =
F_255 ( 4 , V_713 ) |
F_255 ( 5 , V_714 ) |
F_255 ( 6 , V_715 ) ;
if ( V_19 -> V_22 )
V_19 -> V_721 |=
F_255 ( 7 , V_708 ) ;
F_25 ( V_5 , V_19 -> V_721 ,
V_722 ) ;
}
static int F_262 ( struct V_4 * V_5 , struct V_83 * V_84 )
{
struct V_547 * V_548 = V_84 -> V_20 ;
int V_86 ;
V_86 = F_48 ( V_5 , V_548 -> V_1 ,
V_55 ) ;
if ( V_86 ) {
F_32 ( V_5 -> V_13 ,
L_44 ) ;
return V_86 ;
}
F_263 ( V_548 ) ;
F_57 ( V_5 , V_548 -> V_1 , 1 ) ;
return F_264 ( V_5 , V_84 ) ;
}
static int F_265 ( struct V_4 * V_5 , struct V_83 * V_84 )
{
struct V_547 * V_548 = V_84 -> V_20 ;
int V_86 ;
V_86 = F_266 ( V_548 ) ;
F_57 ( V_5 , V_548 -> V_1 , 0 ) ;
F_55 ( V_5 , V_548 -> V_1 ) ;
return V_86 ;
}
static T_5 F_267 ( int V_324 , void * V_96 )
{
struct V_4 * V_5 = V_96 ;
unsigned short V_131 ;
unsigned short V_91 ;
unsigned int V_143 = 0 ;
unsigned int V_178 = 0 ;
unsigned long V_21 ;
#ifdef F_51
struct V_18 * V_19 = V_5 -> V_20 ;
struct V_89 * V_24 = V_19 -> V_24 ;
#endif
if ( ! V_5 -> V_728 )
return V_729 ;
F_268 () ;
F_26 ( & V_5 -> V_224 , V_21 ) ;
V_131 = F_29 ( V_5 , V_87 ) ;
V_91 = F_29 ( V_5 , V_92 ) ;
#ifdef F_51
if ( V_24 ) {
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned long V_730 ;
F_26 ( & V_19 -> V_50 , V_730 ) ;
if ( V_19 -> V_51 ) {
V_143 = F_185 ( V_19 -> V_51 ) ;
if ( V_143 & V_147 )
F_4 ( V_512 ,
V_19 -> V_24 -> V_513 +
F_186 ( V_19 ->
V_51 -> V_41 ) ) ;
}
if ( V_19 -> V_56 ) {
V_178 = F_185 ( V_19 -> V_56 ) ;
if ( V_178 & V_147 )
F_4 ( V_512 ,
V_24 -> V_513 +
F_186 ( V_19 ->
V_56 -> V_41 ) ) ;
}
F_27 ( & V_19 -> V_50 , V_730 ) ;
}
#endif
F_89 ( V_5 , V_131 ) ;
F_92 ( V_5 , V_91 ) ;
if ( ( V_131 & V_731 ) || ( V_143 & V_148 ) )
F_90 ( V_5 , V_131 , V_143 ) ;
if ( ( V_91 & V_732 ) || ( V_178 & V_148 ) )
F_93 ( V_5 , V_91 , V_178 ) ;
F_86 ( V_5 , 0 ) ;
F_86 ( V_5 , 1 ) ;
F_184 ( V_5 ) ;
F_27 ( & V_5 -> V_224 , V_21 ) ;
return V_733 ;
}
static int F_269 ( struct V_4 * V_5 )
{
struct V_18 * V_19 ;
V_19 = F_270 ( V_5 , sizeof( * V_19 ) ) ;
if ( ! V_19 )
return - V_734 ;
F_271 ( & V_19 -> V_23 ) ;
F_271 ( & V_19 -> V_30 ) ;
F_271 ( & V_19 -> V_50 ) ;
return 0 ;
}
static int F_272 ( struct V_4 * V_5 ,
unsigned V_735 , unsigned V_736 )
{
const struct V_102 * V_103 = V_5 -> V_104 ;
struct V_18 * V_19 = V_5 -> V_20 ;
struct V_83 * V_84 ;
int V_181 ;
int V_73 ;
if ( V_103 -> V_737 > V_738 ) {
F_32 ( V_5 -> V_13 , L_45 ) ;
return - V_314 ;
}
V_19 -> V_528 = V_739 |
V_537 |
V_740 |
V_741 ;
if ( ! V_19 -> V_98 ) {
V_19 -> V_528 |= ( V_742 |
V_743 ) ;
}
F_25 ( V_5 , V_19 -> V_528 , V_541 ) ;
V_181 = F_273 ( V_5 , V_744 ) ;
if ( V_181 )
return V_181 ;
V_84 = & V_5 -> V_130 [ V_745 ] ;
if ( V_103 -> V_746 ) {
V_84 -> type = V_747 ;
V_84 -> V_188 = V_748 | V_749 | V_750 ;
if ( ! V_19 -> V_115 )
V_84 -> V_188 |= V_751 | V_752 | V_753 ;
if ( V_103 -> V_754 > 0xffff )
V_84 -> V_188 |= V_189 ;
if ( V_19 -> V_22 )
V_84 -> V_188 |= V_755 ;
V_84 -> V_227 = V_103 -> V_746 ;
V_84 -> V_258 = V_103 -> V_754 ;
V_84 -> V_384 = V_756 [ V_103 -> V_238 ] ;
V_84 -> V_757 = F_124 ;
V_84 -> V_758 = F_142 ;
if ( V_5 -> V_324 ) {
V_5 -> V_85 = V_84 ;
V_84 -> V_188 |= V_759 ;
V_84 -> V_760 = 512 ;
V_84 -> V_761 = F_128 ;
V_84 -> V_762 = F_135 ;
V_84 -> V_491 = F_103 ;
V_84 -> V_763 = F_108 ;
V_84 -> V_764 = F_94 ;
if ( V_19 -> V_24 )
V_84 -> V_765 = V_766 ;
}
F_103 ( V_5 , V_84 ) ;
} else {
V_84 -> type = V_146 ;
}
V_84 = & V_5 -> V_130 [ V_767 ] ;
if ( V_103 -> V_737 ) {
V_84 -> type = V_768 ;
V_84 -> V_188 = V_769 | V_770 | V_751 ;
if ( V_19 -> V_22 )
V_84 -> V_188 |= V_755 ;
V_84 -> V_227 = V_103 -> V_737 ;
V_84 -> V_258 = V_103 -> V_771 ;
V_84 -> V_384 = V_103 -> V_772 ;
V_84 -> V_758 = F_159 ;
V_84 -> V_773 = F_155 ;
V_181 = F_274 ( V_84 ) ;
if ( V_181 )
return V_181 ;
if ( V_5 -> V_324 && ( V_103 -> V_110 || V_19 -> V_24 ) ) {
V_5 -> V_90 = V_84 ;
V_84 -> V_188 |= V_774 ;
V_84 -> V_760 = V_84 -> V_227 ;
V_84 -> V_761 = F_167 ;
V_84 -> V_762 = F_162 ;
V_84 -> V_491 = F_168 ;
if ( ! V_19 -> V_22 )
V_84 -> V_764 = F_143 ;
if ( V_19 -> V_24 )
V_84 -> V_765 = V_775 ;
}
if ( V_19 -> V_776 )
F_191 ( V_5 , V_84 ) ;
F_168 ( V_5 , V_84 ) ;
} else {
V_84 -> type = V_146 ;
}
V_84 = & V_5 -> V_130 [ V_510 ] ;
V_84 -> type = V_777 ;
V_84 -> V_188 = V_769 | V_748 ;
V_84 -> V_227 = V_103 -> V_778 ? 32 : 8 ;
V_84 -> V_258 = 1 ;
V_84 -> V_384 = & V_779 ;
if ( V_19 -> V_22 ) {
V_84 -> V_188 |= V_189 ;
V_84 -> V_780 = F_176 ;
V_84 -> V_758 = F_175 ;
if ( V_5 -> V_324 ) {
V_84 -> V_188 |= V_774 ;
V_84 -> V_760 = V_84 -> V_227 ;
V_84 -> V_761 = F_178 ;
V_84 -> V_762 = F_181 ;
V_84 -> V_491 = F_183 ;
V_84 -> V_765 = V_781 ;
}
F_3 ( V_5 , V_497 |
V_782 ,
V_495 ) ;
F_3 ( V_5 , V_84 -> V_476 , V_486 ) ;
} else {
V_84 -> V_780 = F_172 ;
V_84 -> V_758 = F_169 ;
V_19 -> V_474 = F_171 ( V_84 -> V_476 ) ;
F_6 ( V_5 , V_19 -> V_474 , V_477 ) ;
}
V_84 = & V_5 -> V_130 [ V_783 ] ;
if ( V_103 -> V_784 ) {
V_181 = F_275 ( V_5 , V_84 , F_200 ,
V_785 ) ;
if ( V_181 )
return V_181 ;
} else {
V_84 -> type = V_146 ;
}
V_84 = & V_5 -> V_130 [ V_786 ] ;
V_84 -> type = V_146 ;
V_84 = & V_5 -> V_130 [ V_787 ] ;
V_84 -> type = V_788 ;
V_84 -> V_188 = V_789 ;
V_84 -> V_227 = 1 ;
V_84 -> V_258 = 0 ;
if ( V_19 -> V_22 ) {
V_84 -> V_758 = F_202 ;
F_3 ( V_5 , 0x0 , V_593 ) ;
} else if ( V_19 -> V_74 ) {
V_84 -> V_758 = F_205 ;
} else {
V_84 -> V_188 |= V_769 ;
V_84 -> V_757 = F_216 ;
V_84 -> V_773 = F_215 ;
F_217 ( V_5 , V_84 ) ;
}
V_84 = & V_5 -> V_130 [ V_790 ] ;
V_84 -> type = V_791 ;
V_84 -> V_188 = V_748 | V_789 ;
V_84 -> V_258 = 0xff ;
if ( V_19 -> V_22 ) {
V_84 -> V_227 = V_792 ;
V_84 -> V_757 = F_220 ;
} else {
V_84 -> V_227 = 512 ;
V_84 -> V_757 = F_219 ;
}
V_84 = & V_5 -> V_130 [ V_793 ] ;
V_84 -> type = V_777 ;
V_84 -> V_188 = V_748 | V_769 | V_789 ;
V_84 -> V_258 = 1 ;
if ( V_19 -> V_22 ) {
V_84 -> V_227 = 16 ;
V_84 -> V_780 = F_235 ;
F_6 ( V_5 , V_84 -> V_483 , V_639 ) ;
for ( V_73 = 0 ; V_73 < V_794 ; ++ V_73 ) {
F_6 ( V_5 , V_19 -> V_628 [ V_73 ] ,
F_228 ( V_73 ) ) ;
}
} else {
V_84 -> V_227 = 10 ;
}
V_84 -> V_758 = F_234 ;
F_64 ( V_5 , V_35 , ~ 0 , 0 ) ;
V_84 = & V_5 -> V_130 [ V_795 ] ;
if ( V_19 -> V_776 ) {
V_84 -> type = V_747 ;
V_84 -> V_188 = V_748 | V_749 | V_789 ;
V_84 -> V_227 = V_103 -> V_737 ;
V_84 -> V_258 = ( 1 << 16 ) - 1 ;
V_84 -> V_384 = & V_796 ;
V_84 -> V_757 = F_241 ;
V_84 -> V_758 = NULL ;
F_243 ( V_5 ) ;
} else {
V_84 -> type = V_146 ;
}
V_84 = & V_5 -> V_130 [ V_797 ] ;
V_84 -> type = V_798 ;
V_84 -> V_188 = V_748 | V_769 | V_789 ;
V_84 -> V_227 = 1 ;
V_84 -> V_258 = 0xff ;
V_84 -> V_758 = F_190 ;
V_19 -> V_480 = 0 ;
V_19 -> V_532 = 0 ;
V_84 = & V_5 -> V_130 [ V_799 ] ;
V_84 -> type = V_777 ;
V_84 -> V_188 = V_748 | V_769 | V_789 ;
V_84 -> V_227 = 8 ;
V_84 -> V_258 = 1 ;
V_84 -> V_780 = F_260 ;
V_84 -> V_758 = F_258 ;
F_261 ( V_5 ) ;
V_19 -> V_62 = F_276 ( V_5 ,
F_193 ,
F_194 ,
( V_19 -> V_22 )
? V_800
: V_801 ,
V_802 ) ;
if ( ! V_19 -> V_62 )
return - V_734 ;
for ( V_73 = 0 ; V_73 < V_802 ; ++ V_73 ) {
struct V_547 * V_803 = & V_19 -> V_62 -> V_63 [ V_73 ] ;
V_803 -> V_804 = 0 ;
V_803 -> V_1 = V_73 ;
F_277 ( V_803 ) ;
V_84 = & V_5 -> V_130 [ F_1 ( V_73 ) ] ;
V_84 -> type = V_805 ;
V_84 -> V_188 = V_748 | V_769 | V_189 ;
V_84 -> V_227 = 3 ;
V_84 -> V_258 = ( V_19 -> V_22 ) ? 0xffffffff
: 0x00ffffff ;
V_84 -> V_757 = V_806 ;
V_84 -> V_773 = V_806 ;
V_84 -> V_758 = V_807 ;
#ifdef F_51
if ( V_5 -> V_324 && V_19 -> V_24 ) {
V_84 -> V_188 |= V_759 ;
V_84 -> V_760 = 1 ;
V_84 -> V_761 = V_808 ;
V_84 -> V_762 = F_262 ;
V_84 -> V_491 = F_265 ;
V_84 -> V_765 = V_781 ;
}
#endif
V_84 -> V_20 = V_803 ;
}
V_84 = & V_5 -> V_130 [ V_809 ] ;
V_84 -> type = V_805 ;
V_84 -> V_188 = V_748 | V_769 ;
V_84 -> V_227 = 1 ;
V_84 -> V_258 = 0xf ;
V_84 -> V_757 = F_195 ;
V_84 -> V_773 = F_197 ;
V_84 -> V_758 = F_199 ;
if ( V_5 -> V_324 ) {
F_25 ( V_5 ,
( V_736 ? V_810 : 0 ) |
( V_811 & 0 ) |
V_812 |
V_813 |
F_278 ( V_735 ) |
F_279 ( V_735 ) ,
V_814 ) ;
}
F_9 ( V_5 , V_19 -> V_38 , V_37 ) ;
F_9 ( V_5 , V_19 -> V_40 , V_39 ) ;
if ( V_19 -> V_98 ) {
F_9 ( V_5 , 0 , V_815 ) ;
} else if ( V_19 -> V_22 ) {
int V_41 ;
for ( V_41 = 0 ; V_41 < V_103 -> V_737 ; ++ V_41 ) {
F_9 ( V_5 , 0xf ,
F_149 ( V_41 ) ) ;
F_9 ( V_5 , 0x0 ,
F_150 ( V_41 ) ) ;
}
F_9 ( V_5 , 0x0 , V_816 ) ;
}
return 0 ;
}
static void F_280 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
if ( V_19 ) {
if ( V_19 -> V_62 )
F_281 ( V_19 -> V_62 ) ;
}
}
