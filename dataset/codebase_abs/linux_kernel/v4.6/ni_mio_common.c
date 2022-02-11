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
else
F_5 ( V_6 , V_5 -> V_9 + V_7 ) ;
}
static void F_6 ( struct V_4 * V_5 , T_2 V_6 , int V_7 )
{
if ( V_5 -> V_8 )
F_7 ( V_6 , V_5 -> V_8 + V_7 ) ;
else
F_8 ( V_6 , V_5 -> V_9 + V_7 ) ;
}
static void F_9 ( struct V_4 * V_5 , T_3 V_6 , int V_7 )
{
if ( V_5 -> V_8 )
F_10 ( V_6 , V_5 -> V_8 + V_7 ) ;
else
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
static inline void F_35 ( struct V_4 * V_5 ,
unsigned V_41 )
{
unsigned V_42 = F_34 ( V_41 ) ;
F_31 ( V_5 , V_37 ,
V_43 , F_36 ( V_42 ) ) ;
}
static inline void F_37 ( struct V_4 * V_5 )
{
F_31 ( V_5 , V_37 , V_43 , 0 ) ;
}
static inline void F_38 ( struct V_4 * V_5 ,
unsigned V_41 )
{
unsigned V_42 = F_34 ( V_41 ) ;
F_31 ( V_5 , V_37 ,
V_44 , F_39 ( V_42 ) ) ;
}
static inline void F_40 ( struct V_4 * V_5 )
{
F_31 ( V_5 , V_37 , V_44 , 0 ) ;
}
static inline void F_41 ( struct V_4 * V_5 ,
unsigned V_45 ,
unsigned V_41 )
{
unsigned V_42 = F_34 ( V_41 ) ;
F_31 ( V_5 , V_39 ,
F_42 ( V_45 ) ,
F_43 ( V_45 , V_42 ) ) ;
}
static inline void F_44 ( struct V_4 * V_5 ,
unsigned V_45 )
{
F_31 ( V_5 , V_39 ,
F_42 ( V_45 ) , 0 ) ;
}
static inline void F_45 ( struct V_4 * V_5 ,
unsigned V_46 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned long V_21 ;
unsigned V_42 ;
F_26 ( & V_19 -> V_30 , V_21 ) ;
V_19 -> V_47 &= ~ V_48 ;
V_42 = F_34 ( V_46 ) ;
V_19 -> V_47 |= F_46 ( V_42 ) ;
F_9 ( V_5 , V_19 -> V_47 , V_49 ) ;
F_33 () ;
F_27 ( & V_19 -> V_30 , V_21 ) ;
}
static inline void F_47 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned long V_21 ;
F_26 ( & V_19 -> V_30 , V_21 ) ;
V_19 -> V_47 &= ~ V_48 ;
F_9 ( V_5 , V_19 -> V_47 , V_49 ) ;
F_33 () ;
F_27 ( & V_19 -> V_30 , V_21 ) ;
}
static int F_48 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned long V_21 ;
F_26 ( & V_19 -> V_50 , V_21 ) ;
F_49 ( V_19 -> V_51 ) ;
V_19 -> V_51 =
F_50 ( V_19 -> V_24 , V_19 -> V_52 ) ;
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
static int F_51 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned long V_21 ;
F_26 ( & V_19 -> V_50 , V_21 ) ;
F_49 ( V_19 -> V_56 ) ;
V_19 -> V_56 =
F_50 ( V_19 -> V_24 , V_19 -> V_57 ) ;
if ( ! V_19 -> V_56 ) {
F_27 ( & V_19 -> V_50 , V_21 ) ;
F_32 ( V_5 -> V_13 ,
L_5 ) ;
return - V_53 ;
}
V_19 -> V_56 -> V_54 = V_58 ;
F_38 ( V_5 , V_19 -> V_56 -> V_41 ) ;
F_27 ( & V_19 -> V_50 , V_21 ) ;
return 0 ;
}
static int F_52 ( struct V_4 * V_5 ,
unsigned V_45 ,
enum V_59 V_60 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned long V_21 ;
struct V_46 * V_61 ;
F_26 ( & V_19 -> V_50 , V_21 ) ;
F_49 ( V_19 -> V_62 -> V_63 [ V_45 ] . V_61 ) ;
V_61 =
F_50 ( V_19 -> V_24 ,
V_19 -> V_64 [ V_45 ] ) ;
if ( ! V_61 ) {
F_27 ( & V_19 -> V_50 , V_21 ) ;
F_32 ( V_5 -> V_13 ,
L_6 ) ;
return - V_53 ;
}
V_61 -> V_54 = V_60 ;
F_53 ( & V_19 -> V_62 -> V_63 [ V_45 ] ,
V_61 ) ;
F_41 ( V_5 , V_45 , V_61 -> V_41 ) ;
F_27 ( & V_19 -> V_50 , V_21 ) ;
return 0 ;
}
static int F_54 ( struct V_4 * V_5 )
{
#ifdef F_55
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned long V_21 ;
F_26 ( & V_19 -> V_50 , V_21 ) ;
F_49 ( V_19 -> V_65 ) ;
V_19 -> V_65 =
F_50 ( V_19 -> V_24 , V_19 -> V_66 ) ;
if ( ! V_19 -> V_65 ) {
F_27 ( & V_19 -> V_50 , V_21 ) ;
F_32 ( V_5 -> V_13 ,
L_7 ) ;
return - V_53 ;
}
V_19 -> V_65 -> V_54 = V_58 ;
F_45 ( V_5 , V_19 -> V_65 -> V_41 ) ;
F_27 ( & V_19 -> V_50 , V_21 ) ;
#endif
return 0 ;
}
static void F_56 ( struct V_4 * V_5 )
{
#ifdef F_55
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned long V_21 ;
F_26 ( & V_19 -> V_50 , V_21 ) ;
if ( V_19 -> V_51 ) {
F_37 ( V_5 ) ;
F_57 ( V_19 -> V_51 ) ;
V_19 -> V_51 = NULL ;
}
F_27 ( & V_19 -> V_50 , V_21 ) ;
#endif
}
static void F_58 ( struct V_4 * V_5 )
{
#ifdef F_55
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned long V_21 ;
F_26 ( & V_19 -> V_50 , V_21 ) ;
if ( V_19 -> V_56 ) {
F_40 ( V_5 ) ;
F_57 ( V_19 -> V_56 ) ;
V_19 -> V_56 = NULL ;
}
F_27 ( & V_19 -> V_50 , V_21 ) ;
#endif
}
static void F_59 ( struct V_4 * V_5 ,
unsigned V_45 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned long V_21 ;
F_26 ( & V_19 -> V_50 , V_21 ) ;
if ( V_19 -> V_62 -> V_63 [ V_45 ] . V_61 ) {
struct V_46 * V_61 =
V_19 -> V_62 -> V_63 [ V_45 ] . V_61 ;
F_44 ( V_5 , V_45 ) ;
F_53 ( & V_19 ->
V_62 -> V_63 [ V_45 ] ,
NULL ) ;
F_57 ( V_61 ) ;
}
F_27 ( & V_19 -> V_50 , V_21 ) ;
}
static void F_60 ( struct V_4 * V_5 )
{
#ifdef F_55
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned long V_21 ;
F_26 ( & V_19 -> V_50 , V_21 ) ;
if ( V_19 -> V_65 ) {
F_47 ( V_5 ) ;
F_57 ( V_19 -> V_65 ) ;
V_19 -> V_65 = NULL ;
}
F_27 ( & V_19 -> V_50 , V_21 ) ;
#endif
}
static void F_61 ( struct V_4 * V_5 ,
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
static void F_62 ( struct V_4 * V_5 )
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
F_63 ( 1 ) ;
}
if ( V_73 == V_72 )
F_32 ( V_5 -> V_13 , L_8 ) ;
} else {
F_25 ( V_5 , 1 , V_77 ) ;
if ( V_19 -> V_78 ) {
F_9 ( V_5 , 0 , F_64 ( 0 ) ) ;
F_9 ( V_5 , 1 , F_64 ( 0 ) ) ;
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
static inline void F_65 ( struct V_4 * V_5 , T_2 V_6 ,
int V_79 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned long V_21 ;
F_26 ( & V_19 -> V_23 , V_21 ) ;
F_6 ( V_5 , V_79 , V_80 ) ;
F_6 ( V_5 , V_6 , V_81 ) ;
F_27 ( & V_19 -> V_23 , V_21 ) ;
}
static inline void F_66 ( struct V_4 * V_5 , T_1 V_6 ,
int V_79 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned long V_21 ;
F_26 ( & V_19 -> V_23 , V_21 ) ;
F_6 ( V_5 , V_79 , V_80 ) ;
F_3 ( V_5 , V_6 , V_81 ) ;
F_27 ( & V_19 -> V_23 , V_21 ) ;
}
static inline unsigned short F_67 ( struct V_4 * V_5 , int V_79 )
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
static inline void F_68 ( struct V_4 * V_5 , int V_7 ,
unsigned V_42 , unsigned V_82 )
{
unsigned V_29 ;
if ( V_82 )
V_29 = V_42 ;
else
V_29 = 0 ;
F_31 ( V_5 , V_7 , V_42 , V_29 ) ;
}
static void F_69 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
struct V_83 * V_84 = V_5 -> V_85 ;
unsigned long V_21 ;
F_26 ( & V_19 -> V_50 , V_21 ) ;
if ( V_19 -> V_51 )
F_70 ( V_19 -> V_51 , V_84 ) ;
F_27 ( & V_19 -> V_50 , V_21 ) ;
}
static int F_71 ( struct V_4 * V_5 )
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
&& F_72 ( V_19 -> V_51 ) ==
0 )
break;
F_63 ( 5 ) ;
}
if ( V_73 == V_72 ) {
F_32 ( V_5 -> V_13 , L_9 ) ;
F_32 ( V_5 -> V_13 ,
L_10 ,
F_72 ( V_19 -> V_51 ) ,
F_29 ( V_5 , V_87 ) ) ;
V_86 = - 1 ;
}
}
F_27 ( & V_19 -> V_50 , V_21 ) ;
F_69 ( V_5 ) ;
return V_86 ;
}
static void F_73 ( struct V_89 * V_24 ,
struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
struct V_83 * V_84 = V_5 -> V_90 ;
unsigned long V_21 ;
F_26 ( & V_19 -> V_50 , V_21 ) ;
if ( V_19 -> V_56 )
F_74 ( V_19 -> V_56 , V_84 ) ;
F_27 ( & V_19 -> V_50 , V_21 ) ;
}
static int F_75 ( struct V_4 * V_5 )
{
static const int V_72 = 10000 ;
int V_73 ;
for ( V_73 = 0 ; V_73 < V_72 ; V_73 ++ ) {
unsigned short V_91 ;
V_91 = F_29 ( V_5 , V_92 ) ;
if ( V_91 & V_93 )
break;
F_63 ( 10 ) ;
}
if ( V_73 == V_72 ) {
F_32 ( V_5 -> V_13 , L_11 ) ;
return - V_94 ;
}
return 0 ;
}
static void F_76 ( struct V_4 * V_5 ,
struct V_83 * V_84 , int V_95 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
int V_73 ;
unsigned short V_96 ;
T_4 V_97 ;
for ( V_73 = 0 ; V_73 < V_95 ; V_73 ++ ) {
F_77 ( V_84 , & V_96 , 1 ) ;
if ( V_19 -> V_98 ) {
V_97 = V_96 & 0xffff ;
if ( ! V_19 -> V_99 ) {
F_77 ( V_84 , & V_96 , 1 ) ;
V_73 ++ ;
V_97 |= ( V_96 << 16 ) & 0xffff0000 ;
}
F_3 ( V_5 , V_97 , V_100 ) ;
} else {
F_6 ( V_5 , V_96 , V_101 ) ;
}
}
}
static int F_78 ( struct V_4 * V_5 ,
struct V_83 * V_84 )
{
const struct V_102 * V_103 = V_5 -> V_104 ;
unsigned int V_105 ;
unsigned int V_106 ;
V_105 = F_79 ( V_84 ) ;
if ( V_105 == 0 ) {
V_84 -> V_107 -> V_108 |= V_109 ;
return 0 ;
}
V_106 = F_80 ( V_84 , V_105 ) ;
if ( V_106 > V_103 -> V_110 / 2 )
V_106 = V_103 -> V_110 / 2 ;
F_76 ( V_5 , V_84 , V_106 ) ;
return 1 ;
}
static int F_81 ( struct V_4 * V_5 ,
struct V_83 * V_84 )
{
const struct V_102 * V_103 = V_5 -> V_104 ;
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_105 ;
unsigned int V_106 ;
F_25 ( V_5 , 1 , V_111 ) ;
if ( V_19 -> V_98 )
F_66 ( V_5 , 0x6 , V_112 ) ;
V_105 = F_79 ( V_84 ) ;
if ( V_105 == 0 )
return 0 ;
V_106 = F_80 ( V_84 , V_105 ) ;
if ( V_106 > V_103 -> V_110 )
V_106 = V_103 -> V_110 ;
F_76 ( V_5 , V_84 , V_106 ) ;
return V_106 ;
}
static void F_82 ( struct V_4 * V_5 ,
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
F_83 ( V_84 , & V_6 , 1 ) ;
V_6 = V_114 & 0xffff ;
F_83 ( V_84 , & V_6 , 1 ) ;
}
if ( V_95 % 2 ) {
V_114 = F_12 ( V_5 , V_116 ) ;
V_6 = V_114 & 0xffff ;
F_83 ( V_84 , & V_6 , 1 ) ;
}
} else if ( V_19 -> V_74 ) {
for ( V_73 = 0 ; V_73 < V_95 / 2 ; V_73 ++ ) {
V_114 = F_12 ( V_5 , V_117 ) ;
V_6 = ( V_114 >> 16 ) & 0xffff ;
F_83 ( V_84 , & V_6 , 1 ) ;
V_6 = V_114 & 0xffff ;
F_83 ( V_84 , & V_6 , 1 ) ;
}
if ( V_95 % 2 ) {
F_3 ( V_5 , 0x01 , V_75 ) ;
V_114 = F_12 ( V_5 , V_117 ) ;
V_6 = ( V_114 >> 16 ) & 0xffff ;
F_83 ( V_84 , & V_6 , 1 ) ;
}
} else {
if ( V_95 > F_22 ( V_19 -> V_118 ) ) {
F_32 ( V_5 -> V_13 ,
L_12 ) ;
V_107 -> V_108 |= V_119 ;
return;
}
for ( V_73 = 0 ; V_73 < V_95 ; V_73 ++ ) {
V_19 -> V_118 [ V_73 ] =
F_15 ( V_5 , V_120 ) ;
}
F_83 ( V_84 , V_19 -> V_118 , V_95 ) ;
}
}
static void F_84 ( struct V_4 * V_5 )
{
const struct V_102 * V_103 = V_5 -> V_104 ;
struct V_83 * V_84 = V_5 -> V_85 ;
int V_95 ;
V_95 = V_103 -> V_121 / 2 ;
F_82 ( V_5 , V_84 , V_95 ) ;
}
static void F_85 ( struct V_4 * V_5 )
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
F_83 ( V_84 , & V_6 , 1 ) ;
V_6 = V_114 & 0xffff ;
F_83 ( V_84 , & V_6 , 1 ) ;
}
} else if ( V_19 -> V_74 ) {
V_73 = 0 ;
while ( F_12 ( V_5 , V_76 ) & 0x04 ) {
V_114 = F_12 ( V_5 , V_117 ) ;
V_6 = V_114 >> 16 ;
F_83 ( V_84 , & V_6 , 1 ) ;
V_6 = V_114 & 0xffff ;
F_83 ( V_84 , & V_6 , 1 ) ;
V_73 += 2 ;
}
if ( F_12 ( V_5 , V_76 ) & 0x01 ) {
F_3 ( V_5 , 0x01 , V_75 ) ;
V_114 = F_12 ( V_5 , V_117 ) ;
V_6 = ( V_114 >> 16 ) & 0xffff ;
F_83 ( V_84 , & V_6 , 1 ) ;
}
} else {
V_122 = F_29 ( V_5 , V_87 ) &
V_88 ;
while ( V_122 == 0 ) {
for ( V_73 = 0 ;
V_73 < F_22 ( V_19 -> V_118 ) ; V_73 ++ ) {
V_122 = F_29 ( V_5 ,
V_87 ) &
V_88 ;
if ( V_122 )
break;
V_19 -> V_118 [ V_73 ] =
F_15 ( V_5 , V_120 ) ;
}
F_83 ( V_84 , V_19 -> V_118 , V_73 ) ;
}
}
}
static void F_86 ( struct V_4 * V_5 )
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
F_83 ( V_84 , & V_6 , 1 ) ;
}
}
static void F_87 ( struct V_4 * V_5 )
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
F_83 ( V_84 , & V_6 , 1 ) ;
}
}
static void F_88 ( struct V_4 * V_5 )
{
struct V_83 * V_84 = V_5 -> V_85 ;
#ifdef F_55
F_71 ( V_5 ) ;
#endif
F_85 ( V_5 ) ;
F_86 ( V_5 ) ;
F_87 ( V_5 ) ;
V_84 -> V_107 -> V_108 |= V_124 ;
}
static void F_89 ( struct V_4 * V_5 , struct V_83 * V_84 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
if ( V_19 -> V_125 == V_126 ) {
#ifdef F_55
static const int V_72 = 10 ;
int V_73 ;
for ( V_73 = 0 ; V_73 < V_72 ; V_73 ++ ) {
F_69 ( V_5 ) ;
if ( ( V_84 -> V_107 -> V_108 & V_127 ) )
break;
F_63 ( 1 ) ;
}
#else
F_85 ( V_5 ) ;
V_84 -> V_107 -> V_108 |= V_127 ;
#endif
}
if ( V_19 -> V_128 & V_129 )
F_88 ( V_5 ) ;
}
static void F_90 ( struct V_4 * V_5 ,
unsigned short V_1 )
{
#ifdef F_55
struct V_18 * V_19 = V_5 -> V_20 ;
struct V_83 * V_84 ;
V_84 = & V_5 -> V_130 [ F_1 ( V_1 ) ] ;
F_91 ( & V_19 -> V_62 -> V_63 [ V_1 ] ,
V_84 ) ;
F_92 ( V_5 , V_84 ) ;
#endif
}
static void F_93 ( struct V_4 * V_5 , unsigned short V_131 )
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
static void F_94 ( struct V_4 * V_5 , unsigned short V_142 ,
unsigned V_143 )
{
struct V_83 * V_84 = V_5 -> V_85 ;
struct V_144 * V_145 = & V_84 -> V_107 -> V_145 ;
if ( V_84 -> type == V_146 )
return;
#ifdef F_55
if ( V_143 & V_147 )
F_69 ( V_5 ) ;
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
if ( F_95 ( V_84 ) ) {
V_84 -> V_107 -> V_108 |= V_119 ;
F_92 ( V_5 , V_84 ) ;
}
return;
}
if ( V_142 & V_158 ) {
F_32 ( V_5 -> V_13 , L_15 ,
V_142 ) ;
F_88 ( V_5 ) ;
V_84 -> V_107 -> V_108 |= V_119 ;
if ( V_142 & V_159 )
V_84 -> V_107 -> V_108 |= V_109 ;
F_92 ( V_5 , V_84 ) ;
return;
}
if ( V_142 & V_133 ) {
if ( V_145 -> V_160 == V_161 )
F_88 ( V_5 ) ;
}
}
#ifndef F_55
if ( V_142 & V_162 ) {
int V_73 ;
static const int V_72 = 10 ;
for ( V_73 = 0 ; V_73 < V_72 ; ++ V_73 ) {
F_84 ( V_5 ) ;
if ( ( F_29 ( V_5 , V_87 ) &
V_162 ) == 0 )
break;
}
}
#endif
if ( V_142 & V_139 )
F_89 ( V_5 , V_84 ) ;
F_92 ( V_5 , V_84 ) ;
}
static void F_96 ( struct V_4 * V_5 , unsigned short V_91 )
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
static void F_97 ( struct V_4 * V_5 ,
unsigned short V_91 , unsigned V_178 )
{
struct V_83 * V_84 = V_5 -> V_90 ;
#ifdef F_55
if ( V_178 & V_147 ) {
struct V_18 * V_19 = V_5 -> V_20 ;
F_73 ( V_19 -> V_24 , V_5 ) ;
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
if ( V_84 -> V_107 -> V_145 . V_160 != V_180 &&
V_91 & V_163 )
V_84 -> V_107 -> V_108 |= V_124 ;
#ifndef F_55
if ( V_91 & V_181 ) {
int V_182 ;
V_182 = F_78 ( V_5 , V_84 ) ;
if ( ! V_182 ) {
F_32 ( V_5 -> V_13 , L_18 ) ;
F_68 ( V_5 , V_33 ,
V_183 |
V_184 , 0 ) ;
V_84 -> V_107 -> V_108 |= V_109 ;
}
}
#endif
F_92 ( V_5 , V_84 ) ;
}
static void F_98 ( struct V_4 * V_5 , struct V_83 * V_84 ,
void * V_6 , unsigned int V_185 ,
unsigned int V_186 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
struct V_113 * V_107 = V_84 -> V_107 ;
struct V_144 * V_145 = & V_107 -> V_145 ;
unsigned int V_106 = F_80 ( V_84 , V_185 ) ;
unsigned short * V_187 = V_6 ;
unsigned int * V_188 = V_6 ;
unsigned int V_73 ;
#ifdef F_55
T_5 * V_189 = V_6 ;
T_6 * V_190 = V_6 ;
#endif
for ( V_73 = 0 ; V_73 < V_106 ; V_73 ++ ) {
#ifdef F_55
if ( V_84 -> V_191 & V_192 )
V_188 [ V_73 ] = F_99 ( V_190 [ V_73 ] ) ;
else
V_187 [ V_73 ] = F_100 ( V_189 [ V_73 ] ) ;
#endif
if ( V_84 -> V_191 & V_192 )
V_188 [ V_73 ] += V_19 -> V_193 [ V_186 ] ;
else
V_187 [ V_73 ] += V_19 -> V_193 [ V_186 ] ;
V_186 ++ ;
V_186 %= V_145 -> V_194 ;
}
}
static int F_101 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
struct V_83 * V_84 = V_5 -> V_85 ;
int V_86 ;
unsigned long V_21 ;
V_86 = F_48 ( V_5 ) ;
if ( V_86 )
return V_86 ;
F_102 ( V_84 , V_84 -> V_107 -> V_195 ) ;
F_26 ( & V_19 -> V_50 , V_21 ) ;
if ( ! V_19 -> V_51 ) {
F_27 ( & V_19 -> V_50 , V_21 ) ;
return - V_196 ;
}
if ( V_19 -> V_115 || V_19 -> V_74 )
F_103 ( V_19 -> V_51 , 32 , 16 ) ;
else if ( V_19 -> V_197 )
F_103 ( V_19 -> V_51 , 32 , 32 ) ;
else
F_103 ( V_19 -> V_51 , 16 , 16 ) ;
F_104 ( V_19 -> V_51 ) ;
F_27 ( & V_19 -> V_50 , V_21 ) ;
return 0 ;
}
static int F_105 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
struct V_83 * V_84 = V_5 -> V_90 ;
int V_86 ;
unsigned long V_21 ;
V_86 = F_51 ( V_5 ) ;
if ( V_86 )
return V_86 ;
F_106 ( V_84 , V_84 -> V_107 -> V_195 ) ;
F_26 ( & V_19 -> V_50 , V_21 ) ;
if ( V_19 -> V_56 ) {
if ( V_19 -> V_115 || V_19 -> V_198 ) {
F_103 ( V_19 -> V_56 , 32 , 32 ) ;
} else {
F_103 ( V_19 -> V_56 , 16 , 32 ) ;
}
F_104 ( V_19 -> V_56 ) ;
} else {
V_86 = - V_196 ;
}
F_27 ( & V_19 -> V_50 , V_21 ) ;
return V_86 ;
}
static int F_107 ( struct V_4 * V_5 , struct V_83 * V_84 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned V_199 ;
unsigned V_200 ;
F_56 ( V_5 ) ;
F_25 ( V_5 , V_201 | V_202 ,
V_203 ) ;
F_68 ( V_5 , V_31 , V_204 , 0 ) ;
F_62 ( V_5 ) ;
if ( ! V_19 -> V_74 )
F_9 ( V_5 , V_205 , V_206 ) ;
F_25 ( V_5 , V_207 , V_208 ) ;
F_25 ( V_5 , V_209 |
V_210
,
V_211 ) ;
F_25 ( V_5 , 0 , V_212 ) ;
F_25 ( V_5 , V_213 ,
V_214 ) ;
V_199 = V_215 |
V_216 |
V_217 ;
V_200 = F_108 ( 3 ) |
F_109 ( 0 ) |
F_110 ( 2 ) |
F_111 ( 3 ) ;
if ( V_19 -> V_115 ) {
V_200 |= V_218 ;
} else if ( V_19 -> V_74 ) {
V_200 |= V_219 ;
} else {
V_199 |= V_220 ;
if ( V_19 -> V_221 )
V_200 |= V_218 ;
else
V_200 |= V_219 ;
}
F_25 ( V_5 , V_199 , V_222 ) ;
F_25 ( V_5 , V_200 , V_223 ) ;
F_25 ( V_5 , V_224 , V_141 ) ;
F_25 ( V_5 , V_225 , V_203 ) ;
return 0 ;
}
static int F_112 ( struct V_4 * V_5 , struct V_83 * V_84 )
{
unsigned long V_21 ;
int V_226 ;
F_26 ( & V_5 -> V_227 , V_21 ) ;
#ifndef F_55
F_85 ( V_5 ) ;
#else
F_69 ( V_5 ) ;
#endif
V_226 = F_113 ( V_84 ) ;
F_27 ( & V_5 -> V_227 , V_21 ) ;
return V_226 ;
}
static void F_114 ( struct V_4 * V_5 )
{
int V_73 ;
F_25 ( V_5 , V_228 , V_208 ) ;
for ( V_73 = 0 ; V_73 < V_229 ; ++ V_73 ) {
if ( ! ( F_29 ( V_5 , V_87 ) &
V_88 ) ) {
F_25 ( V_5 , 1 , V_77 ) ;
return;
}
F_63 ( 1 ) ;
}
F_32 ( V_5 -> V_13 , L_19 ) ;
}
static void F_115 ( struct V_4 * V_5 ,
unsigned int V_230 ,
unsigned int * V_231 )
{
const struct V_102 * V_103 = V_5 -> V_104 ;
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_232 , V_233 , V_234 ;
unsigned int V_73 ;
unsigned int V_235 ;
unsigned V_236 ;
F_25 ( V_5 , 1 , V_237 ) ;
if ( ( V_231 [ 0 ] & V_238 ) ) {
unsigned V_239 ;
V_232 = F_116 ( V_231 [ 0 ] ) ;
V_233 = F_117 ( V_231 [ 0 ] ) ;
V_236 = V_240 [ V_103 -> V_241 ] [ V_233 ] ;
V_235 = ( V_231 [ 0 ] & V_242 ) != 0 ;
V_239 = V_243 |
F_118 ( V_232 ) |
F_119 ( V_236 ) |
V_19 -> V_244 ;
if ( V_235 )
V_239 |= V_245 ;
V_239 |= V_246 ;
F_3 ( V_5 , V_239 , V_247 ) ;
} else {
F_3 ( V_5 , 0 , V_247 ) ;
}
for ( V_73 = 0 ; V_73 < V_230 ; V_73 ++ ) {
unsigned V_248 = 0 ;
V_232 = F_116 ( V_231 [ V_73 ] ) ;
V_234 = F_120 ( V_231 [ V_73 ] ) ;
V_233 = F_117 ( V_231 [ V_73 ] ) ;
V_235 = ( V_231 [ V_73 ] & V_242 ) != 0 ;
V_236 = V_240 [ V_103 -> V_241 ] [ V_233 ] ;
V_19 -> V_193 [ V_73 ] = 0 ;
switch ( V_234 ) {
case V_249 :
V_248 |= V_250 ;
break;
case V_251 :
V_248 |= V_252 ;
break;
case V_253 :
V_248 |= V_254 ;
break;
case V_255 :
break;
}
V_248 |= F_121 ( V_232 ) ;
V_248 |= F_122 ( V_232 ) ;
V_248 |= F_123 ( V_236 ) ;
if ( V_73 == V_230 - 1 )
V_248 |= V_256 ;
if ( V_235 )
V_248 |= V_257 ;
V_248 |= V_258 ;
F_6 ( V_5 , V_248 , V_259 ) ;
}
F_114 ( V_5 ) ;
}
static void F_124 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
unsigned int V_230 , unsigned int * V_231 )
{
const struct V_102 * V_103 = V_5 -> V_104 ;
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_260 = ( V_84 -> V_261 + 1 ) >> 1 ;
unsigned int V_232 , V_233 , V_234 ;
unsigned int V_73 ;
unsigned int V_262 , V_263 ;
unsigned int V_235 ;
if ( V_19 -> V_22 ) {
F_115 ( V_5 , V_230 , V_231 ) ;
return;
}
if ( V_230 == 1 && ! V_19 -> V_115 && ! V_19 -> V_74 ) {
if ( V_19 -> V_264
&& V_19 -> V_265 == V_231 [ 0 ] ) {
return;
}
V_19 -> V_264 = 1 ;
V_19 -> V_265 = V_231 [ 0 ] ;
} else {
V_19 -> V_264 = 0 ;
}
F_25 ( V_5 , 1 , V_237 ) ;
if ( V_19 -> V_74 ) {
if ( ( V_231 [ 0 ] & V_238 )
&& ! V_19 -> V_266 ) {
F_6 ( V_5 , V_19 -> V_244 |
V_267 ,
V_268 ) ;
F_6 ( V_5 , V_19 -> V_244 ,
V_268 ) ;
V_19 -> V_266 = 1 ;
F_125 ( 100 ) ;
} else if ( ! ( V_231 [ 0 ] & V_238 )
&& V_19 -> V_266 ) {
F_6 ( V_5 , V_19 -> V_244 |
V_269 ,
V_268 ) ;
F_6 ( V_5 , V_19 -> V_244 ,
V_268 ) ;
V_19 -> V_266 = 0 ;
F_125 ( 100 ) ;
}
}
for ( V_73 = 0 ; V_73 < V_230 ; V_73 ++ ) {
if ( ! V_19 -> V_74 && ( V_231 [ V_73 ] & V_238 ) )
V_232 = V_19 -> V_244 ;
else
V_232 = F_116 ( V_231 [ V_73 ] ) ;
V_234 = F_120 ( V_231 [ V_73 ] ) ;
V_233 = F_117 ( V_231 [ V_73 ] ) ;
V_235 = ( V_231 [ V_73 ] & V_242 ) != 0 ;
V_233 = V_240 [ V_103 -> V_241 ] [ V_233 ] ;
if ( V_19 -> V_115 )
V_19 -> V_193 [ V_73 ] = V_260 ;
else
V_19 -> V_193 [ V_73 ] = ( V_233 & 0x100 ) ? 0 : V_260 ;
V_262 = 0 ;
if ( ( V_231 [ V_73 ] & V_238 ) ) {
if ( V_19 -> V_115 )
F_6 ( V_5 , F_116 ( V_231 [ V_73 ] ) & 0x0003 ,
V_270 ) ;
} else {
if ( V_19 -> V_115 )
V_234 = V_249 ;
else if ( V_19 -> V_74 )
V_234 = V_255 ;
switch ( V_234 ) {
case V_249 :
V_262 |= V_271 ;
break;
case V_251 :
V_262 |= V_272 ;
break;
case V_253 :
V_262 |= V_273 ;
break;
case V_255 :
break;
}
}
V_262 |= F_126 ( V_232 ) ;
F_6 ( V_5 , V_262 , V_274 ) ;
if ( ! V_19 -> V_74 ) {
V_263 = F_127 ( V_233 ) ;
if ( V_73 == V_230 - 1 )
V_263 |= V_275 ;
if ( V_235 )
V_263 |= V_276 ;
F_6 ( V_5 , V_263 , V_277 ) ;
}
}
if ( ! V_19 -> V_115 && ! V_19 -> V_74 )
F_114 ( V_5 ) ;
}
static int F_128 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_278 * V_279 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_280 = ( V_84 -> V_261 + 1 ) >> 1 ;
int V_73 , V_95 ;
unsigned V_281 ;
unsigned int V_96 ;
unsigned long V_114 ;
F_124 ( V_5 , V_84 , 1 , & V_279 -> V_282 ) ;
F_62 ( V_5 ) ;
V_281 = V_19 -> V_193 [ 0 ] ;
if ( V_19 -> V_115 ) {
for ( V_95 = 0 ; V_95 < V_283 ; V_95 ++ ) {
F_25 ( V_5 , V_228 ,
V_208 ) ;
F_63 ( 1 ) ;
}
for ( V_95 = 0 ; V_95 < V_279 -> V_95 ; V_95 ++ ) {
F_25 ( V_5 , V_228 ,
V_208 ) ;
V_96 = 0 ;
for ( V_73 = 0 ; V_73 < V_229 ; V_73 ++ ) {
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
if ( V_73 == V_229 ) {
F_32 ( V_5 -> V_13 , L_20 ) ;
return - V_284 ;
}
V_96 += V_281 ;
V_6 [ V_95 ] = V_96 ;
}
} else if ( V_19 -> V_74 ) {
for ( V_95 = 0 ; V_95 < V_279 -> V_95 ; V_95 ++ ) {
F_25 ( V_5 , V_228 ,
V_208 ) ;
V_114 = 0 ;
for ( V_73 = 0 ; V_73 < V_229 ; V_73 ++ ) {
if ( F_12 ( V_5 , V_76 ) &
0x01 ) {
F_3 ( V_5 , 0x01 ,
V_75 ) ;
V_114 = F_12 ( V_5 ,
V_117 ) ;
break;
}
}
if ( V_73 == V_229 ) {
F_32 ( V_5 -> V_13 , L_20 ) ;
return - V_284 ;
}
V_6 [ V_95 ] = ( ( ( V_114 >> 16 ) & 0xFFFF ) + V_281 ) & 0xFFFF ;
}
} else {
for ( V_95 = 0 ; V_95 < V_279 -> V_95 ; V_95 ++ ) {
F_25 ( V_5 , V_228 ,
V_208 ) ;
for ( V_73 = 0 ; V_73 < V_229 ; V_73 ++ ) {
if ( ! ( F_29 ( V_5 , V_87 ) &
V_88 ) )
break;
}
if ( V_73 == V_229 ) {
F_32 ( V_5 -> V_13 , L_20 ) ;
return - V_284 ;
}
if ( V_19 -> V_22 ) {
V_114 = F_12 ( V_5 , V_285 ) ;
V_114 &= V_280 ;
V_6 [ V_95 ] = V_114 ;
} else {
V_96 = F_15 ( V_5 , V_120 ) ;
V_96 += V_281 ;
V_6 [ V_95 ] = V_96 ;
}
}
}
return V_279 -> V_95 ;
}
static int F_129 ( const struct V_4 * V_5 , unsigned V_286 ,
unsigned int V_21 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
int V_287 ;
switch ( V_21 & V_288 ) {
case V_289 :
default:
V_287 = F_130 ( V_286 , V_19 -> V_290 ) ;
break;
case V_291 :
V_287 = ( V_286 ) / V_19 -> V_290 ;
break;
case V_292 :
V_287 = F_131 ( V_286 , V_19 -> V_290 ) ;
break;
}
return V_287 - 1 ;
}
static unsigned F_132 ( const struct V_4 * V_5 , int V_293 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
return V_19 -> V_290 * ( V_293 + 1 ) ;
}
static void F_133 ( struct V_294 * V_295 ,
struct V_83 * V_296 ,
const struct V_144 * V_145 ,
unsigned int V_297 ) {
#ifdef F_55
unsigned int V_105 = V_297 ;
if ( V_145 -> V_298 > 0 && V_145 -> V_298 < V_297 )
V_105 = V_145 -> V_298 ;
V_105 *= F_134 ( V_296 ) ;
if ( V_105 > V_296 -> V_107 -> V_195 ) {
if ( V_145 -> V_298 > 0 )
F_32 ( V_296 -> V_299 -> V_13 ,
L_21 ) ;
V_105 = V_296 -> V_107 -> V_195 ;
}
F_135 ( V_295 , V_296 , V_105 ) ;
#else
F_32 ( V_296 -> V_299 -> V_13 ,
L_22 ) ;
#endif
}
static unsigned F_136 ( struct V_4 * V_5 ,
unsigned V_300 )
{
const struct V_102 * V_103 = V_5 -> V_104 ;
struct V_18 * V_19 = V_5 -> V_20 ;
if ( V_19 -> V_115 || V_19 -> V_74 )
return V_103 -> V_301 ;
return V_103 -> V_301 * V_300 ;
}
static int F_137 ( struct V_4 * V_5 , struct V_83 * V_84 ,
struct V_144 * V_145 )
{
const struct V_102 * V_103 = V_5 -> V_104 ;
struct V_18 * V_19 = V_5 -> V_20 ;
int V_302 = 0 ;
unsigned int V_303 ;
unsigned int V_304 ;
V_302 |= F_138 ( & V_145 -> V_305 ,
V_306 | V_307 | V_308 ) ;
V_302 |= F_138 ( & V_145 -> V_309 ,
V_310 | V_308 ) ;
V_304 = V_310 | V_308 ;
if ( V_19 -> V_115 || V_19 -> V_74 )
V_304 |= V_306 ;
V_302 |= F_138 ( & V_145 -> V_311 , V_304 ) ;
V_302 |= F_138 ( & V_145 -> V_312 , V_161 ) ;
V_302 |= F_138 ( & V_145 -> V_160 , V_161 | V_180 ) ;
if ( V_302 )
return 1 ;
V_302 |= F_139 ( V_145 -> V_305 ) ;
V_302 |= F_139 ( V_145 -> V_309 ) ;
V_302 |= F_139 ( V_145 -> V_311 ) ;
V_302 |= F_139 ( V_145 -> V_160 ) ;
if ( V_302 )
return 2 ;
switch ( V_145 -> V_305 ) {
case V_306 :
case V_307 :
V_302 |= F_140 ( & V_145 -> V_313 , 0 ) ;
break;
case V_308 :
V_303 = F_116 ( V_145 -> V_313 ) ;
if ( V_303 > 16 )
V_303 = 16 ;
V_303 |= ( V_145 -> V_313 & ( V_314 | V_315 ) ) ;
V_302 |= F_140 ( & V_145 -> V_313 , V_303 ) ;
break;
}
if ( V_145 -> V_309 == V_310 ) {
V_302 |= F_141 ( & V_145 -> V_316 ,
F_136 ( V_5 , V_145 -> V_194 ) ) ;
V_302 |= F_142 ( & V_145 -> V_316 ,
V_19 -> V_290 *
0xffffff ) ;
} else if ( V_145 -> V_309 == V_308 ) {
unsigned int V_303 = F_116 ( V_145 -> V_316 ) ;
if ( V_303 > 16 )
V_303 = 16 ;
V_303 |= ( V_145 -> V_316 & ( V_314 | V_315 ) ) ;
V_302 |= F_140 ( & V_145 -> V_316 , V_303 ) ;
} else {
V_302 |= F_140 ( & V_145 -> V_316 , 0 ) ;
}
if ( V_145 -> V_311 == V_310 ) {
if ( V_19 -> V_115 || V_19 -> V_74 ) {
V_302 |= F_140 ( & V_145 -> V_317 ,
0 ) ;
} else {
V_302 |= F_141 ( & V_145 -> V_317 ,
V_103 -> V_301 ) ;
V_302 |= F_142 ( & V_145 -> V_317 ,
V_19 -> V_290 *
0xffff ) ;
}
} else if ( V_145 -> V_311 == V_308 ) {
unsigned int V_303 = F_116 ( V_145 -> V_317 ) ;
if ( V_303 > 16 )
V_303 = 16 ;
V_303 |= ( V_145 -> V_317 & ( V_242 | V_314 ) ) ;
V_302 |= F_140 ( & V_145 -> V_317 , V_303 ) ;
} else if ( V_145 -> V_311 == V_306 ) {
V_302 |= F_140 ( & V_145 -> V_317 , 0 ) ;
}
V_302 |= F_140 ( & V_145 -> V_318 ,
V_145 -> V_194 ) ;
if ( V_145 -> V_160 == V_161 ) {
unsigned int V_297 = 0x01000000 ;
if ( V_19 -> V_115 )
V_297 -= V_283 ;
V_302 |= F_142 ( & V_145 -> V_298 , V_297 ) ;
V_302 |= F_141 ( & V_145 -> V_298 , 1 ) ;
} else {
V_302 |= F_140 ( & V_145 -> V_298 , 0 ) ;
}
if ( V_302 )
return 3 ;
if ( V_145 -> V_309 == V_310 ) {
V_303 = V_145 -> V_316 ;
V_145 -> V_316 =
F_132 ( V_5 , F_129 ( V_5 ,
V_145 -> V_316 ,
V_145 -> V_21 ) ) ;
if ( V_303 != V_145 -> V_316 )
V_302 ++ ;
}
if ( V_145 -> V_311 == V_310 ) {
if ( ! V_19 -> V_115 && ! V_19 -> V_74 ) {
V_303 = V_145 -> V_317 ;
V_145 -> V_317 =
F_132 ( V_5 , F_129 ( V_5 ,
V_145 -> V_317 ,
V_145 -> V_21 ) ) ;
if ( V_303 != V_145 -> V_317 )
V_302 ++ ;
if ( V_145 -> V_309 == V_310 &&
V_145 -> V_316 <
V_145 -> V_317 * V_145 -> V_318 ) {
V_145 -> V_316 =
V_145 -> V_317 * V_145 -> V_318 ;
V_302 ++ ;
}
}
}
if ( V_302 )
return 4 ;
return 0 ;
}
static int F_143 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
unsigned int V_319 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
struct V_144 * V_145 = & V_84 -> V_107 -> V_145 ;
if ( V_319 != V_145 -> V_313 )
return - V_320 ;
F_25 ( V_5 , V_321 | V_19 -> V_128 ,
V_322 ) ;
V_84 -> V_107 -> V_323 = NULL ;
return 1 ;
}
static int F_144 ( struct V_4 * V_5 , struct V_83 * V_84 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
const struct V_144 * V_145 = & V_84 -> V_107 -> V_145 ;
int V_293 ;
int V_324 = 0 ;
int V_325 = 0 ;
int V_326 = 0 ;
unsigned int V_327 ;
int V_328 = 0 ;
unsigned V_329 ;
if ( V_5 -> V_330 == 0 ) {
F_32 ( V_5 -> V_13 , L_23 ) ;
return - V_196 ;
}
F_62 ( V_5 ) ;
F_124 ( V_5 , V_84 , V_145 -> V_194 , V_145 -> V_331 ) ;
F_25 ( V_5 , V_201 , V_203 ) ;
V_19 -> V_332 &= ~ V_333 ;
F_25 ( V_5 , V_19 -> V_332 , V_334 ) ;
V_329 = F_145 ( 0 ) | V_335 ;
switch ( V_145 -> V_305 ) {
case V_307 :
case V_306 :
V_329 |= V_336 |
F_146 ( 0 ) ;
break;
case V_308 :
V_329 |= F_146 ( F_116 ( V_145 -> V_313 ) +
1 ) ;
if ( V_145 -> V_313 & V_314 )
V_329 |= V_337 ;
if ( V_145 -> V_313 & V_315 )
V_329 |= V_336 ;
break;
}
F_25 ( V_5 , V_329 , V_338 ) ;
V_325 &= ~ V_339 ;
V_325 &= ~ V_340 ;
V_325 &= ~ V_341 ;
F_25 ( V_5 , V_325 , V_212 ) ;
if ( V_145 -> V_194 == 1 || V_19 -> V_115 || V_19 -> V_74 ) {
V_326 |= V_342 |
F_147 ( 31 ) |
V_343 ;
} else {
V_326 |= F_147 ( 19 ) ;
}
F_25 ( V_5 , V_326 , V_344 ) ;
V_19 -> V_128 = 0 ;
switch ( V_145 -> V_160 ) {
case V_161 :
V_327 = V_145 -> V_298 - 1 ;
if ( V_19 -> V_115 ) {
V_327 += V_283 ;
}
F_28 ( V_5 , V_327 , V_345 ) ;
V_324 |= V_209 |
V_210 |
V_346 ;
F_25 ( V_5 , V_324 , V_211 ) ;
F_25 ( V_5 , V_347 , V_208 ) ;
if ( V_327 == 0 ) {
V_19 -> V_128 |= V_129 ;
V_328 |= V_348 ;
if ( V_145 -> V_194 > 1 )
V_326 |= V_342 |
V_349 ;
}
break;
case V_180 :
F_28 ( V_5 , 0 , V_345 ) ;
V_324 |= V_209 |
V_210 |
V_350 ;
F_25 ( V_5 , V_324 , V_211 ) ;
F_25 ( V_5 , V_347 , V_208 ) ;
break;
}
switch ( V_145 -> V_309 ) {
case V_310 :
V_326 |= V_351 | V_352 ;
F_25 ( V_5 , V_326 , V_344 ) ;
V_325 &= ~ V_353 ;
V_325 |= F_148 ( 0 ) ;
F_25 ( V_5 , V_325 , V_212 ) ;
V_293 = F_129 ( V_5 , V_145 -> V_316 ,
V_289 ) ;
F_28 ( V_5 , V_293 , V_354 ) ;
F_25 ( V_5 , V_355 , V_208 ) ;
break;
case V_308 :
if ( V_145 -> V_316 & V_315 )
V_326 |= V_351 ;
if ( V_145 -> V_316 & V_314 )
V_326 |= V_356 ;
if ( V_145 -> V_309 != V_145 -> V_311 ||
( V_145 -> V_316 & ~ V_315 ) !=
( V_145 -> V_317 & ~ V_315 ) )
V_326 |= V_352 ;
V_326 |=
F_149 ( 1 + F_116 ( V_145 -> V_316 ) ) ;
F_25 ( V_5 , V_326 , V_344 ) ;
break;
}
switch ( V_145 -> V_311 ) {
case V_310 :
case V_306 :
if ( V_145 -> V_317 == 0 || V_145 -> V_311 == V_306 )
V_293 = 1 ;
else
V_293 = F_129 ( V_5 , V_145 -> V_317 ,
V_289 ) ;
F_25 ( V_5 , 1 , V_357 ) ;
F_25 ( V_5 , V_293 , V_358 ) ;
V_325 &= ~ V_359 ;
V_325 |= V_360 ;
F_25 ( V_5 , V_325 , V_212 ) ;
F_25 ( V_5 , V_361 , V_208 ) ;
V_325 |= V_359 ;
V_325 |= V_360 ;
F_25 ( V_5 , V_325 , V_212 ) ;
break;
case V_308 :
V_324 |= F_150 ( 1 +
F_116 ( V_145 -> V_317 ) ) ;
if ( ( V_145 -> V_317 & V_314 ) == 0 )
V_324 |= V_362 ;
F_25 ( V_5 , V_324 , V_211 ) ;
V_325 |= V_363 |
V_364 ;
F_25 ( V_5 , V_325 , V_212 ) ;
break;
}
if ( V_5 -> V_330 ) {
V_328 |= V_365 |
V_366 ;
#ifndef F_55
V_328 |= V_367 ;
#endif
if ( ( V_145 -> V_21 & V_368 ) ||
( V_19 -> V_128 & V_129 ) ) {
V_19 -> V_125 = V_126 ;
} else {
V_19 -> V_125 = V_369 ;
}
switch ( V_19 -> V_125 ) {
case V_369 :
#ifdef F_55
F_25 ( V_5 , V_370 ,
V_214 ) ;
#else
F_25 ( V_5 , V_371 ,
V_214 ) ;
#endif
break;
case V_372 :
F_25 ( V_5 , V_213 ,
V_214 ) ;
break;
case V_126 :
#ifdef F_55
F_25 ( V_5 , V_213 ,
V_214 ) ;
#else
F_25 ( V_5 , V_371 ,
V_214 ) ;
#endif
V_328 |= V_348 ;
break;
default:
break;
}
F_25 ( V_5 , V_224 , V_141 ) ;
F_68 ( V_5 , V_31 , V_328 , 1 ) ;
} else {
F_68 ( V_5 , V_31 , ~ 0 , 0 ) ;
}
F_25 ( V_5 , V_225 , V_203 ) ;
switch ( V_145 -> V_309 ) {
case V_310 :
F_25 ( V_5 , V_373 |
V_374 |
V_375 |
V_376 ,
V_208 ) ;
break;
case V_308 :
F_25 ( V_5 , V_373 |
V_374 |
V_375 |
V_376 ,
V_208 ) ;
break;
}
#ifdef F_55
{
int V_86 = F_101 ( V_5 ) ;
if ( V_86 )
return V_86 ;
}
#endif
if ( V_145 -> V_305 == V_306 ) {
F_25 ( V_5 , V_321 |
V_19 -> V_128 ,
V_322 ) ;
V_84 -> V_107 -> V_323 = NULL ;
} else if ( V_145 -> V_305 == V_308 ) {
V_84 -> V_107 -> V_323 = NULL ;
} else {
V_84 -> V_107 -> V_323 = F_143 ;
}
return 0 ;
}
static int F_151 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_278 * V_279 , unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
if ( V_279 -> V_95 < 1 )
return - V_320 ;
switch ( V_6 [ 0 ] ) {
case V_377 :
if ( V_19 -> V_22 ) {
if ( V_6 [ 1 ] & ~ V_378 )
return - V_320 ;
V_19 -> V_244 = V_6 [ 1 ] ;
} else if ( V_19 -> V_74 ) {
unsigned int V_379 ;
V_379 = V_6 [ 1 ] & 0xf ;
V_19 -> V_244 = V_379 ;
F_6 ( V_5 , V_379 , V_268 ) ;
} else {
unsigned int V_379 ;
unsigned int V_380 ;
V_379 = V_6 [ 1 ] & 0xf ;
V_380 = ( V_6 [ 1 ] >> 4 ) & 0xff ;
if ( V_379 >= 8 )
return - V_320 ;
V_19 -> V_244 = V_379 ;
if ( V_19 -> V_115 ) {
F_9 ( V_5 , V_380 ,
V_381 ) ;
}
}
return 2 ;
default:
break;
}
return - V_320 ;
}
static void F_152 ( struct V_4 * V_5 , struct V_83 * V_84 ,
void * V_6 , unsigned int V_185 ,
unsigned int V_186 )
{
struct V_144 * V_145 = & V_84 -> V_107 -> V_145 ;
unsigned int V_106 = F_80 ( V_84 , V_185 ) ;
unsigned short * V_187 = V_6 ;
unsigned int V_73 ;
#ifdef F_55
T_5 V_382 , * V_189 = V_6 ;
#endif
for ( V_73 = 0 ; V_73 < V_106 ; V_73 ++ ) {
unsigned int V_233 = F_117 ( V_145 -> V_331 [ V_186 ] ) ;
unsigned short V_27 = V_187 [ V_73 ] ;
if ( F_153 ( V_84 , V_233 ) )
V_27 = F_154 ( V_84 , V_27 ) ;
#ifdef F_55
V_382 = F_155 ( V_27 ) ;
V_189 [ V_73 ] = V_382 ;
#else
V_187 [ V_73 ] = V_27 ;
#endif
V_186 ++ ;
V_186 %= V_145 -> V_194 ;
}
}
static int F_156 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
unsigned int V_282 [] ,
unsigned int V_383 , int V_384 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_233 ;
unsigned int V_232 ;
unsigned int V_385 ;
int V_73 ;
int V_386 = 0 ;
if ( V_384 ) {
for ( V_73 = 0 ; V_73 < V_84 -> V_230 ; ++ V_73 ) {
V_19 -> V_387 [ V_73 ] &= ~ V_388 ;
F_9 ( V_5 , V_19 -> V_387 [ V_73 ] ,
F_157 ( V_73 ) ) ;
F_9 ( V_5 , 0xf , F_158 ( V_73 ) ) ;
}
}
for ( V_73 = 0 ; V_73 < V_383 ; V_73 ++ ) {
const struct V_389 * V_390 ;
V_232 = F_116 ( V_282 [ V_73 ] ) ;
V_233 = F_117 ( V_282 [ V_73 ] ) ;
V_390 = V_84 -> V_391 -> V_233 + V_233 ;
V_386 = 0 ;
V_385 = 0 ;
switch ( V_390 -> V_392 - V_390 -> V_393 ) {
case 20000000 :
V_385 |= V_394 ;
F_9 ( V_5 , 0 , F_159 ( V_232 ) ) ;
break;
case 10000000 :
V_385 |= V_395 ;
F_9 ( V_5 , 0 , F_159 ( V_232 ) ) ;
break;
case 4000000 :
V_385 |= V_394 ;
F_9 ( V_5 , V_396 ,
F_159 ( V_232 ) ) ;
break;
case 2000000 :
V_385 |= V_395 ;
F_9 ( V_5 , V_396 ,
F_159 ( V_232 ) ) ;
break;
default:
F_32 ( V_5 -> V_13 ,
L_24 ) ;
break;
}
switch ( V_390 -> V_392 + V_390 -> V_393 ) {
case 0 :
V_385 |= V_397 ;
break;
case 10000000 :
V_385 |= V_398 ;
break;
default:
F_32 ( V_5 -> V_13 ,
L_25 ) ;
break;
}
if ( V_384 )
V_385 |= V_388 ;
F_9 ( V_5 , V_385 , F_157 ( V_232 ) ) ;
V_19 -> V_387 [ V_232 ] = V_385 ;
F_9 ( V_5 , V_73 , F_158 ( V_232 ) ) ;
}
return V_386 ;
}
static int F_160 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
unsigned int V_282 [] ,
unsigned int V_383 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_233 ;
unsigned int V_232 ;
unsigned int V_385 ;
int V_73 ;
int V_386 = 0 ;
for ( V_73 = 0 ; V_73 < V_383 ; V_73 ++ ) {
V_232 = F_116 ( V_282 [ V_73 ] ) ;
V_233 = F_117 ( V_282 [ V_73 ] ) ;
V_385 = F_161 ( V_232 ) ;
if ( F_153 ( V_84 , V_233 ) ) {
V_385 |= V_399 ;
V_386 = ( V_84 -> V_261 + 1 ) >> 1 ;
} else {
V_386 = 0 ;
}
if ( F_162 ( V_84 , V_233 ) )
V_385 |= V_400 ;
if ( V_282 [ V_73 ] & V_401 )
V_385 |= V_402 ;
if ( F_120 ( V_282 [ V_73 ] ) == V_255 )
V_385 |= V_403 ;
F_6 ( V_5 , V_385 , V_404 ) ;
V_19 -> V_387 [ V_232 ] = V_385 ;
}
return V_386 ;
}
static int F_163 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
unsigned int V_282 [] , unsigned int V_383 ,
int V_384 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
if ( V_19 -> V_22 )
return F_156 ( V_5 , V_84 , V_282 , V_383 ,
V_384 ) ;
else
return F_160 ( V_5 , V_84 , V_282 , V_383 ) ;
}
static int F_164 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_278 * V_279 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_232 = F_116 ( V_279 -> V_282 ) ;
unsigned int V_233 = F_117 ( V_279 -> V_282 ) ;
int V_7 ;
int V_73 ;
if ( V_19 -> V_98 ) {
F_65 ( V_5 , 1 << V_232 , V_405 ) ;
V_7 = F_165 ( V_232 ) ;
} else if ( V_19 -> V_22 ) {
V_7 = F_166 ( V_232 ) ;
} else {
V_7 = F_167 ( V_232 ) ;
}
F_163 ( V_5 , V_84 , & V_279 -> V_282 , 1 , 0 ) ;
for ( V_73 = 0 ; V_73 < V_279 -> V_95 ; V_73 ++ ) {
unsigned int V_27 = V_6 [ V_73 ] ;
V_84 -> V_406 [ V_232 ] = V_27 ;
if ( V_19 -> V_98 ) {
V_27 = F_154 ( V_84 , V_27 ) ;
F_65 ( V_5 , V_27 , V_7 ) ;
} else if ( V_19 -> V_22 ) {
F_6 ( V_5 , V_27 , V_7 ) ;
} else {
if ( F_153 ( V_84 , V_233 ) )
V_27 = F_154 ( V_84 , V_27 ) ;
F_6 ( V_5 , V_27 , V_7 ) ;
}
}
return V_279 -> V_95 ;
}
static int F_168 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_278 * V_279 , unsigned int * V_6 )
{
const struct V_102 * V_103 = V_5 -> V_104 ;
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_105 ;
switch ( V_6 [ 0 ] ) {
case V_407 :
switch ( V_6 [ 1 ] ) {
case V_58 :
V_105 = F_169 ( V_84 ,
V_103 -> V_110 ) ;
V_6 [ 2 ] = 1 + V_105 ;
if ( V_19 -> V_24 )
V_6 [ 2 ] += V_19 -> V_24 -> V_408 ;
break;
case V_55 :
V_6 [ 2 ] = 0 ;
break;
default:
return - V_320 ;
}
return 0 ;
default:
break;
}
return - V_320 ;
}
static int F_170 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
unsigned int V_319 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
struct V_144 * V_145 = & V_84 -> V_107 -> V_145 ;
int V_182 ;
int V_409 ;
int V_73 ;
static const int V_72 = 1000 ;
if ( V_319 != V_145 -> V_313 )
return - V_320 ;
V_84 -> V_107 -> V_323 = NULL ;
F_68 ( V_5 , V_33 ,
V_183 | V_184 , 0 ) ;
V_409 = V_184 ;
#ifdef F_55
F_25 ( V_5 , 1 , V_111 ) ;
if ( V_19 -> V_98 )
F_66 ( V_5 , 0x6 , V_112 ) ;
V_182 = F_105 ( V_5 ) ;
if ( V_182 )
return V_182 ;
V_182 = F_75 ( V_5 ) ;
if ( V_182 < 0 )
return V_182 ;
#else
V_182 = F_81 ( V_5 , V_84 ) ;
if ( V_182 == 0 )
return - V_94 ;
V_409 |= V_183 ;
#endif
F_25 ( V_5 , V_19 -> V_410 | V_411 ,
V_412 ) ;
F_25 ( V_5 , V_19 -> V_410 , V_412 ) ;
for ( V_73 = 0 ; V_73 < V_72 ; V_73 ++ ) {
F_63 ( 1 ) ;
if ( ( F_29 ( V_5 , V_413 ) &
V_414 ) == 0 )
break;
}
if ( V_73 == V_72 ) {
F_32 ( V_5 -> V_13 ,
L_26 ) ;
return - V_196 ;
}
F_25 ( V_5 , V_166 , V_177 ) ;
F_68 ( V_5 , V_33 , V_409 , 1 ) ;
F_25 ( V_5 , V_415 |
V_416 |
V_417 |
V_19 -> V_418 ,
V_419 ) ;
F_25 ( V_5 , V_420 | V_19 -> V_421 ,
V_422 ) ;
return 0 ;
}
static void F_171 ( struct V_4 * V_5 ,
const struct V_144 * V_145 )
{
const struct V_102 * V_103 = V_5 -> V_104 ;
unsigned V_42 ;
F_25 ( V_5 , V_423 , V_203 ) ;
V_42 =
V_424 |
0 |
V_425 |
V_426 |
( V_103 -> V_110 ?
V_427 : V_428 )
;
#if 0
if (devpriv->is_m_series)
bits |= NISTC_AO_PERSONAL_NUM_DAC;
#endif
F_25 ( V_5 , V_42 , V_429 ) ;
F_25 ( V_5 , V_430 , V_203 ) ;
}
static void F_172 ( struct V_4 * V_5 ,
const struct V_144 * V_145 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
F_25 ( V_5 , V_423 , V_203 ) ;
if ( V_145 -> V_160 == V_180 ) {
V_19 -> V_431 |= V_432 ;
V_19 -> V_431 &= ~ V_433 ;
} else {
V_19 -> V_431 &= ~ V_432 ;
V_19 -> V_431 |= V_433 ;
}
F_25 ( V_5 , V_19 -> V_431 , V_434 ) ;
{
unsigned int V_435 = V_19 -> V_436 ;
switch ( V_145 -> V_305 ) {
case V_307 :
case V_306 :
V_435 &= ~ ( V_437 |
V_438 ) ;
V_435 |= V_439 |
V_440 ;
break;
case V_308 :
V_435 = F_173 (
F_116 ( V_145 -> V_313 ) + 1 ) ;
if ( V_145 -> V_313 & V_314 )
V_435 |= V_437 ;
if ( V_145 -> V_313 & V_315 )
V_435 |= V_439 ;
break;
default:
F_2 () ;
break;
}
V_19 -> V_436 = V_435 ;
F_25 ( V_5 , V_19 -> V_436 ,
V_441 ) ;
}
V_19 -> V_410 &= ~ V_442 ;
F_25 ( V_5 , V_19 -> V_410 , V_412 ) ;
F_25 ( V_5 , V_430 , V_203 ) ;
}
static void F_174 ( struct V_4 * V_5 ,
const struct V_144 * V_145 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
F_25 ( V_5 , V_423 , V_203 ) ;
F_25 ( V_5 , V_19 -> V_431 , V_434 ) ;
V_19 -> V_443 &= ~ V_444 ;
F_25 ( V_5 , V_19 -> V_443 , V_445 ) ;
F_28 ( V_5 , 0 , V_446 ) ;
F_25 ( V_5 , V_447 , V_419 ) ;
V_19 -> V_443 &= ~ V_448 ;
F_25 ( V_5 , V_19 -> V_443 , V_445 ) ;
{
unsigned int V_298 = V_145 -> V_298 > 0 ?
( V_145 -> V_298 & 0xffffff ) : 0xffffff ;
if ( V_19 -> V_22 ) {
F_28 ( V_5 , V_298 - 1 , V_449 ) ;
F_25 ( V_5 , V_450 ,
V_419 ) ;
} else {
F_28 ( V_5 , V_298 , V_449 ) ;
F_25 ( V_5 , V_450 ,
V_419 ) ;
F_28 ( V_5 , V_298 - 1 , V_449 ) ;
}
}
F_25 ( V_5 , V_430 , V_203 ) ;
}
static void F_175 ( struct V_4 * V_5 ,
const struct V_144 * V_145 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
F_25 ( V_5 , V_423 , V_203 ) ;
V_19 -> V_431 &= ~ (
V_451 |
V_452 |
V_453 |
V_454
) ;
switch ( V_145 -> V_309 ) {
case V_310 :
V_19 -> V_421 &= ~ V_455 ;
{
unsigned V_456 = F_129 ( V_5 ,
V_145 -> V_316 ,
V_289 ) ;
F_28 ( V_5 , 1 , V_457 ) ;
F_25 ( V_5 , V_458 ,
V_419 ) ;
F_28 ( V_5 , V_456 - 1 , V_457 ) ;
}
break;
case V_308 :
V_19 -> V_421 |= V_455 ;
V_19 -> V_431 |= F_176 (
F_116 ( V_145 -> V_316 ) ) ;
if ( V_145 -> V_316 & V_314 )
V_19 -> V_431 |= V_454 ;
break;
default:
F_2 () ;
break;
}
F_25 ( V_5 , V_19 -> V_421 , V_422 ) ;
F_25 ( V_5 , V_19 -> V_431 , V_434 ) ;
V_19 -> V_443 &= ~ ( F_177 ( 3 ) |
V_459 ) ;
F_25 ( V_5 , V_19 -> V_443 , V_445 ) ;
V_19 -> V_418 |= V_460 |
V_461 ;
F_25 ( V_5 , V_19 -> V_418 , V_419 ) ;
F_25 ( V_5 , V_430 , V_203 ) ;
}
static void F_178 ( struct V_4 * V_5 ,
struct V_83 * V_84 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
const struct V_144 * V_145 = & V_84 -> V_107 -> V_145 ;
unsigned V_42 = 0 ;
F_25 ( V_5 , V_423 , V_203 ) ;
if ( V_19 -> V_98 ) {
unsigned int V_73 ;
V_42 = 0 ;
for ( V_73 = 0 ; V_73 < V_145 -> V_194 ; ++ V_73 ) {
int V_232 = F_116 ( V_145 -> V_331 [ V_73 ] ) ;
V_42 |= 1 << V_232 ;
F_65 ( V_5 , V_232 , V_462 ) ;
}
F_65 ( V_5 , V_42 , V_463 ) ;
}
F_163 ( V_5 , V_84 , V_145 -> V_331 , V_145 -> V_194 , 1 ) ;
if ( V_145 -> V_318 > 1 ) {
V_19 -> V_431 |= V_464 ;
V_42 = F_179 ( V_145 -> V_318 - 1 )
| V_465 ;
} else {
V_19 -> V_431 &= ~ V_464 ;
V_42 = V_465 ;
if ( V_19 -> V_22 | V_19 -> V_98 )
V_42 |= F_179 ( 0 ) ;
else
V_42 |= F_179 (
F_116 ( V_145 -> V_331 [ 0 ] ) ) ;
}
F_25 ( V_5 , V_19 -> V_431 , V_434 ) ;
F_25 ( V_5 , V_42 , V_466 ) ;
F_25 ( V_5 , V_430 , V_203 ) ;
}
static void F_180 ( struct V_4 * V_5 ,
const struct V_144 * V_145 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
F_25 ( V_5 , V_423 , V_203 ) ;
V_19 -> V_410 |= V_467 ;
F_25 ( V_5 , V_19 -> V_410 , V_412 ) ;
F_25 ( V_5 , V_430 , V_203 ) ;
}
static void F_181 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
F_25 ( V_5 , V_423 , V_203 ) ;
V_19 -> V_443 &= ~ V_468 ;
#ifdef F_55
V_19 -> V_443 |= V_469 ;
#else
V_19 -> V_443 |= V_470 ;
#endif
V_19 -> V_443 &= ~ V_471 ;
F_25 ( V_5 , V_19 -> V_443 , V_445 ) ;
F_25 ( V_5 , V_472 , V_473 ) ;
F_25 ( V_5 , V_430 , V_203 ) ;
}
static void F_182 ( struct V_4 * V_5 ,
struct V_83 * V_84 )
{
if ( V_84 -> V_107 -> V_145 . V_160 == V_161 )
F_68 ( V_5 , V_33 ,
V_474 , 1 ) ;
V_84 -> V_107 -> V_323 = F_170 ;
}
static int F_183 ( struct V_4 * V_5 , struct V_83 * V_84 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
const struct V_144 * V_145 = & V_84 -> V_107 -> V_145 ;
if ( V_5 -> V_330 == 0 ) {
F_32 ( V_5 -> V_13 , L_27 ) ;
return - V_196 ;
}
F_171 ( V_5 , V_145 ) ;
F_172 ( V_5 , V_145 ) ;
F_174 ( V_5 , V_145 ) ;
F_175 ( V_5 , V_145 ) ;
F_178 ( V_5 , V_84 ) ;
F_180 ( V_5 , V_145 ) ;
F_181 ( V_5 ) ;
F_133 ( V_19 -> V_57 , V_84 , V_145 , 0x00ffffff ) ;
F_182 ( V_5 , V_84 ) ;
return 0 ;
}
static int F_184 ( struct V_4 * V_5 , struct V_83 * V_84 ,
struct V_144 * V_145 )
{
const struct V_102 * V_103 = V_5 -> V_104 ;
struct V_18 * V_19 = V_5 -> V_20 ;
int V_302 = 0 ;
unsigned int V_303 ;
V_302 |= F_138 ( & V_145 -> V_305 , V_307 | V_308 ) ;
V_302 |= F_138 ( & V_145 -> V_309 ,
V_310 | V_308 ) ;
V_302 |= F_138 ( & V_145 -> V_311 , V_306 ) ;
V_302 |= F_138 ( & V_145 -> V_312 , V_161 ) ;
V_302 |= F_138 ( & V_145 -> V_160 , V_161 | V_180 ) ;
if ( V_302 )
return 1 ;
V_302 |= F_139 ( V_145 -> V_305 ) ;
V_302 |= F_139 ( V_145 -> V_309 ) ;
V_302 |= F_139 ( V_145 -> V_160 ) ;
if ( V_302 )
return 2 ;
switch ( V_145 -> V_305 ) {
case V_307 :
V_302 |= F_140 ( & V_145 -> V_313 , 0 ) ;
break;
case V_308 :
V_303 = F_116 ( V_145 -> V_313 ) ;
if ( V_303 > 18 )
V_303 = 18 ;
V_303 |= ( V_145 -> V_313 & ( V_314 | V_315 ) ) ;
V_302 |= F_140 ( & V_145 -> V_313 , V_303 ) ;
break;
}
if ( V_145 -> V_309 == V_310 ) {
V_302 |= F_141 ( & V_145 -> V_316 ,
V_103 -> V_475 ) ;
V_302 |= F_142 ( & V_145 -> V_316 ,
V_19 -> V_290 *
0xffffff ) ;
}
V_302 |= F_140 ( & V_145 -> V_317 , 0 ) ;
V_302 |= F_140 ( & V_145 -> V_318 ,
V_145 -> V_194 ) ;
V_302 |= F_142 ( & V_145 -> V_298 , 0x00ffffff ) ;
if ( V_302 )
return 3 ;
if ( V_145 -> V_309 == V_310 ) {
V_303 = V_145 -> V_316 ;
V_145 -> V_316 =
F_132 ( V_5 , F_129 ( V_5 ,
V_145 -> V_316 ,
V_145 -> V_21 ) ) ;
if ( V_303 != V_145 -> V_316 )
V_302 ++ ;
}
if ( V_302 )
return 4 ;
return 0 ;
}
static int F_185 ( struct V_4 * V_5 , struct V_83 * V_84 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
F_58 ( V_5 ) ;
if ( V_19 -> V_22 )
F_25 ( V_5 , V_476 , V_203 ) ;
F_25 ( V_5 , V_423 , V_203 ) ;
F_25 ( V_5 , V_477 , V_419 ) ;
V_19 -> V_418 = 0 ;
V_19 -> V_421 = 0 ;
V_19 -> V_431 = 0 ;
V_19 -> V_443 = 0 ;
if ( V_19 -> V_22 )
V_19 -> V_410 = V_478 ;
else
V_19 -> V_410 = 0 ;
V_19 -> V_436 = 0 ;
F_25 ( V_5 , 0 , V_429 ) ;
F_25 ( V_5 , 0 , V_419 ) ;
F_25 ( V_5 , 0 , V_422 ) ;
F_25 ( V_5 , 0 , V_434 ) ;
F_25 ( V_5 , 0 , V_445 ) ;
F_25 ( V_5 , 0 , V_466 ) ;
F_25 ( V_5 , V_19 -> V_410 , V_412 ) ;
F_25 ( V_5 , 0 , V_473 ) ;
F_25 ( V_5 , 0 , V_441 ) ;
F_68 ( V_5 , V_33 , ~ 0 , 0 ) ;
F_25 ( V_5 , V_424 , V_429 ) ;
F_25 ( V_5 , V_479 , V_177 ) ;
if ( V_19 -> V_98 ) {
F_65 ( V_5 , ( 1u << V_84 -> V_230 ) - 1u ,
V_405 ) ;
F_65 ( V_5 , V_480 ,
V_481 ) ;
}
F_25 ( V_5 , V_430 , V_203 ) ;
return 0 ;
}
static int F_186 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_278 * V_279 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
int V_182 ;
V_182 = F_187 ( V_5 , V_84 , V_279 , V_6 , 0 ) ;
if ( V_182 )
return V_182 ;
V_19 -> V_482 &= ~ V_483 ;
V_19 -> V_482 |= F_188 ( V_84 -> V_484 ) ;
F_25 ( V_5 , V_19 -> V_482 , V_485 ) ;
return V_279 -> V_95 ;
}
static int F_189 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_278 * V_279 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
if ( ( V_6 [ 0 ] & ( V_486 | V_487 ) ) &&
V_19 -> V_488 )
return - V_53 ;
if ( F_190 ( V_84 , V_6 ) ) {
V_19 -> V_489 &= ~ V_490 ;
V_19 -> V_489 |= F_191 ( V_84 -> V_491 ) ;
F_25 ( V_5 , V_19 -> V_489 , V_492 ) ;
}
V_6 [ 1 ] = F_29 ( V_5 , V_493 ) ;
return V_279 -> V_95 ;
}
static int F_192 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_278 * V_279 ,
unsigned int * V_6 )
{
int V_182 ;
V_182 = F_187 ( V_5 , V_84 , V_279 , V_6 , 0 ) ;
if ( V_182 )
return V_182 ;
F_3 ( V_5 , V_84 -> V_484 , V_494 ) ;
return V_279 -> V_95 ;
}
static int F_193 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_278 * V_279 ,
unsigned int * V_6 )
{
if ( F_190 ( V_84 , V_6 ) )
F_3 ( V_5 , V_84 -> V_491 , V_495 ) ;
V_6 [ 1 ] = F_12 ( V_5 , V_495 ) ;
return V_279 -> V_95 ;
}
static int F_194 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_144 * V_145 )
{
int V_73 ;
for ( V_73 = 0 ; V_73 < V_145 -> V_194 ; ++ V_73 ) {
unsigned int V_232 = F_116 ( V_145 -> V_331 [ V_73 ] ) ;
if ( V_232 != V_73 )
return - V_320 ;
}
return 0 ;
}
static int F_195 ( struct V_4 * V_5 ,
struct V_83 * V_84 , struct V_144 * V_145 )
{
int V_302 = 0 ;
int V_303 ;
V_302 |= F_138 ( & V_145 -> V_305 , V_307 ) ;
V_302 |= F_138 ( & V_145 -> V_309 , V_308 ) ;
V_302 |= F_138 ( & V_145 -> V_311 , V_306 ) ;
V_302 |= F_138 ( & V_145 -> V_312 , V_161 ) ;
V_302 |= F_138 ( & V_145 -> V_160 , V_180 ) ;
if ( V_302 )
return 1 ;
V_302 |= F_140 ( & V_145 -> V_313 , 0 ) ;
V_303 = V_145 -> V_316 ;
V_303 &= F_196 ( V_496 , 0 , 0 , V_314 ) ;
if ( V_303 != V_145 -> V_316 )
V_302 |= - V_320 ;
V_302 |= F_140 ( & V_145 -> V_317 , 0 ) ;
V_302 |= F_140 ( & V_145 -> V_318 ,
V_145 -> V_194 ) ;
V_302 |= F_142 ( & V_145 -> V_298 ,
V_84 -> V_107 -> V_195 /
F_134 ( V_84 ) ) ;
if ( V_302 )
return 3 ;
if ( V_145 -> V_331 && V_145 -> V_194 > 0 )
V_302 |= F_194 ( V_5 , V_84 , V_145 ) ;
if ( V_302 )
return 5 ;
return 0 ;
}
static int F_197 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
unsigned int V_319 )
{
struct V_144 * V_145 = & V_84 -> V_107 -> V_145 ;
const unsigned V_72 = 1000 ;
int V_86 = 0 ;
unsigned V_73 ;
#ifdef F_55
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned long V_21 ;
#endif
if ( V_319 != V_145 -> V_313 )
return - V_320 ;
V_84 -> V_107 -> V_323 = NULL ;
F_106 ( V_84 , V_84 -> V_107 -> V_195 ) ;
#ifdef F_55
F_26 ( & V_19 -> V_50 , V_21 ) ;
if ( V_19 -> V_65 ) {
F_103 ( V_19 -> V_65 , 32 , 32 ) ;
F_104 ( V_19 -> V_65 ) ;
} else {
F_32 ( V_5 -> V_13 , L_28 ) ;
V_86 = - V_196 ;
}
F_27 ( & V_19 -> V_50 , V_21 ) ;
if ( V_86 < 0 )
return V_86 ;
#endif
for ( V_73 = 0 ; V_73 < V_72 ; ++ V_73 ) {
if ( F_12 ( V_5 , V_497 ) &
V_498 )
break;
F_63 ( 10 ) ;
}
if ( V_73 == V_72 ) {
F_32 ( V_5 -> V_13 , L_29 ) ;
V_84 -> V_499 ( V_5 , V_84 ) ;
return - V_196 ;
}
F_3 ( V_5 , V_500 |
V_501 |
V_502 ,
V_503 ) ;
return V_86 ;
}
static int F_198 ( struct V_4 * V_5 , struct V_83 * V_84 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
const struct V_144 * V_145 = & V_84 -> V_107 -> V_145 ;
unsigned V_504 ;
int V_86 ;
F_3 ( V_5 , V_505 , V_503 ) ;
V_504 = V_506 |
V_507 |
F_199 ( F_116 ( V_145 -> V_316 ) ) ;
if ( V_145 -> V_316 & V_314 )
V_504 |= V_508 ;
F_3 ( V_5 , V_504 , V_509 ) ;
if ( V_84 -> V_484 ) {
F_3 ( V_5 , V_84 -> V_491 , V_510 ) ;
F_3 ( V_5 , V_511 , V_503 ) ;
F_3 ( V_5 , V_84 -> V_484 , V_512 ) ;
} else {
F_32 ( V_5 -> V_13 ,
L_30 ) ;
return - V_196 ;
}
V_86 = F_54 ( V_5 ) ;
if ( V_86 < 0 )
return V_86 ;
F_133 ( V_19 -> V_66 , V_84 , V_145 ,
V_84 -> V_107 -> V_195 /
F_134 ( V_84 ) ) ;
V_84 -> V_107 -> V_323 = F_197 ;
return 0 ;
}
static int F_200 ( struct V_4 * V_5 , struct V_83 * V_84 )
{
F_3 ( V_5 , V_513 |
V_514 |
V_515 |
V_516 ,
V_503 ) ;
F_3 ( V_5 , 0 , V_512 ) ;
F_60 ( V_5 ) ;
return 0 ;
}
static void F_201 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned V_517 ;
struct V_83 * V_84 = & V_5 -> V_130 [ V_518 ] ;
#ifdef F_55
unsigned long V_21 ;
#endif
if ( ! V_19 -> V_22 )
return;
#ifdef F_55
F_26 ( & V_19 -> V_50 , V_21 ) ;
if ( V_19 -> V_65 ) {
unsigned V_519 =
F_202 ( V_19 -> V_65 ) ;
if ( V_519 & V_147 ) {
F_4 ( V_520 ,
V_19 -> V_24 -> V_521 +
F_203 ( V_19 -> V_65 -> V_41 ) ) ;
}
F_74 ( V_19 -> V_65 , V_84 ) ;
}
F_27 ( & V_19 -> V_50 , V_21 ) ;
#endif
V_517 = F_12 ( V_5 , V_497 ) ;
if ( V_517 & V_522 ) {
F_3 ( V_5 , V_523 ,
V_503 ) ;
V_84 -> V_107 -> V_108 |= V_109 ;
}
if ( V_517 & V_524 ) {
F_3 ( V_5 , V_515 ,
V_503 ) ;
}
F_92 ( V_5 , V_84 ) ;
}
static int F_204 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
unsigned char V_525 ,
unsigned char * V_526 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_527 ;
int V_302 = 0 , V_226 = 20 ;
V_19 -> V_489 &= ~ V_528 ;
V_19 -> V_489 |= F_205 ( V_525 ) ;
F_25 ( V_5 , V_19 -> V_489 , V_492 ) ;
V_527 = F_29 ( V_5 , V_529 ) ;
if ( V_527 & V_530 ) {
V_302 = - V_53 ;
goto Error;
}
V_19 -> V_482 |= V_531 ;
F_25 ( V_5 , V_19 -> V_482 , V_485 ) ;
V_19 -> V_482 &= ~ V_531 ;
while ( ( V_527 = F_29 ( V_5 , V_529 ) ) &
V_530 ) {
F_63 ( ( V_19 -> V_488 + 999 ) / 1000 ) ;
if ( -- V_226 < 0 ) {
F_32 ( V_5 -> V_13 ,
L_31 ) ;
V_302 = - V_284 ;
goto Error;
}
}
F_63 ( ( V_19 -> V_488 + 999 ) / 1000 ) ;
if ( V_526 )
* V_526 = F_29 ( V_5 , V_532 ) ;
Error:
F_25 ( V_5 , V_19 -> V_482 , V_485 ) ;
return V_302 ;
}
static int F_206 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
unsigned char V_525 ,
unsigned char * V_526 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned char V_280 , V_533 = 0 ;
F_63 ( ( V_19 -> V_488 + 999 ) / 1000 ) ;
for ( V_280 = 0x80 ; V_280 ; V_280 >>= 1 ) {
V_19 -> V_489 &= ~ V_487 ;
if ( V_525 & V_280 )
V_19 -> V_489 |= V_487 ;
F_25 ( V_5 , V_19 -> V_489 , V_492 ) ;
V_19 -> V_482 |= V_534 ;
F_25 ( V_5 , V_19 -> V_482 , V_485 ) ;
F_63 ( ( V_19 -> V_488 + 999 ) / 2000 ) ;
V_19 -> V_482 &= ~ V_534 ;
F_25 ( V_5 , V_19 -> V_482 , V_485 ) ;
F_63 ( ( V_19 -> V_488 + 999 ) / 2000 ) ;
if ( F_29 ( V_5 , V_493 ) & V_486 )
V_533 |= V_280 ;
}
if ( V_526 )
* V_526 = V_533 ;
return 0 ;
}
static int F_207 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_278 * V_279 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned V_535 = V_19 -> V_536 ;
int V_302 = V_279 -> V_95 ;
unsigned char V_537 , V_538 = 0 ;
if ( V_279 -> V_95 != 2 )
return - V_320 ;
switch ( V_6 [ 0 ] ) {
case V_539 :
V_19 -> V_540 = 1 ;
V_19 -> V_482 |= V_541 ;
if ( V_6 [ 1 ] == V_542 ) {
V_19 -> V_540 = 0 ;
V_19 -> V_482 &= ~ ( V_541 |
V_534 ) ;
V_6 [ 1 ] = V_542 ;
V_19 -> V_488 = V_6 [ 1 ] ;
} else if ( V_6 [ 1 ] <= V_543 ) {
V_19 -> V_482 &= ~ V_544 ;
V_535 |= V_545 ;
V_535 &= ~ V_546 ;
V_6 [ 1 ] = V_543 ;
V_19 -> V_488 = V_6 [ 1 ] ;
} else if ( V_6 [ 1 ] <= V_547 ) {
V_19 -> V_482 &= ~ V_544 ;
V_535 |= V_545 |
V_546 ;
V_6 [ 1 ] = V_547 ;
V_19 -> V_488 = V_6 [ 1 ] ;
} else if ( V_6 [ 1 ] <= V_548 ) {
V_19 -> V_482 |= V_544 ;
V_535 |= V_545 |
V_546 ;
V_6 [ 1 ] = V_548 ;
V_19 -> V_488 = V_6 [ 1 ] ;
} else {
V_19 -> V_482 &= ~ ( V_541 |
V_534 ) ;
V_19 -> V_540 = 0 ;
V_6 [ 1 ] = ( V_6 [ 1 ] / 1000 ) * 1000 ;
V_19 -> V_488 = V_6 [ 1 ] ;
}
V_19 -> V_536 = V_535 ;
F_25 ( V_5 , V_19 -> V_482 , V_485 ) ;
F_25 ( V_5 , V_19 -> V_536 , V_549 ) ;
return 1 ;
case V_550 :
if ( V_19 -> V_488 == 0 )
return - V_320 ;
V_537 = V_6 [ 1 ] & 0xFF ;
if ( V_19 -> V_540 ) {
V_302 = F_204 ( V_5 , V_84 , V_537 ,
& V_538 ) ;
} else if ( V_19 -> V_488 > 0 ) {
V_302 = F_206 ( V_5 , V_84 , V_537 ,
& V_538 ) ;
} else {
F_32 ( V_5 -> V_13 , L_32 ) ;
return - V_320 ;
}
if ( V_302 < 0 )
return V_302 ;
V_6 [ 1 ] = V_538 & 0xFF ;
return V_279 -> V_95 ;
break;
default:
return - V_320 ;
}
}
static void F_208 ( struct V_4 * V_5 , struct V_83 * V_84 )
{
int V_73 ;
for ( V_73 = 0 ; V_73 < V_84 -> V_230 ; V_73 ++ ) {
F_65 ( V_5 , F_161 ( V_73 ) | 0x0 ,
V_551 ) ;
}
F_65 ( V_5 , 0x0 , V_552 ) ;
}
static unsigned int F_209 ( struct V_4 * V_5 ,
enum V_553 V_7 )
{
const struct V_10 * V_11 ;
if ( V_7 < F_22 ( V_554 ) ) {
V_11 = & V_554 [ V_7 ] ;
} else {
F_23 ( V_5 -> V_13 , L_1 ,
V_14 , V_7 ) ;
return 0 ;
}
return V_11 -> V_16 ;
}
static void F_210 ( struct V_555 * V_556 , unsigned V_42 ,
enum V_553 V_7 )
{
struct V_4 * V_5 = V_556 -> V_62 -> V_5 ;
unsigned int V_557 = F_209 ( V_5 , V_7 ) ;
static const unsigned V_558 =
V_69 | V_559 ;
static const unsigned V_560 =
V_71 | V_561 ;
if ( V_557 == 0 )
return;
switch ( V_7 ) {
case V_562 :
case V_563 :
case V_564 :
case V_565 :
case V_566 :
case V_567 :
case V_568 :
case V_569 :
F_6 ( V_5 , V_42 , V_557 ) ;
break;
case V_570 :
case V_571 :
case V_572 :
case V_573 :
F_28 ( V_5 , V_42 , V_557 ) ;
break;
case V_574 :
F_49 ( V_42 & ~ V_558 ) ;
F_31 ( V_5 , V_557 ,
V_558 , V_42 ) ;
break;
case V_575 :
F_49 ( V_42 & ~ V_560 ) ;
F_31 ( V_5 , V_557 ,
V_560 , V_42 ) ;
break;
case V_576 :
F_49 ( V_42 & ~ ( V_577 | V_578 ) ) ;
default:
F_25 ( V_5 , V_42 , V_557 ) ;
}
}
static unsigned F_211 ( struct V_555 * V_556 ,
enum V_553 V_7 )
{
struct V_4 * V_5 = V_556 -> V_62 -> V_5 ;
unsigned int V_557 = F_209 ( V_5 , V_7 ) ;
if ( V_557 == 0 )
return 0 ;
switch ( V_7 ) {
case V_579 :
case V_580 :
return F_15 ( V_5 , V_557 ) ;
case V_581 :
case V_582 :
case V_583 :
case V_584 :
return F_30 ( V_5 , V_557 ) ;
default:
return F_29 ( V_5 , V_557 ) ;
}
}
static int F_212 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_278 * V_279 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_27 = F_213 ( V_19 -> V_536 ) ;
int V_73 ;
for ( V_73 = 0 ; V_73 < V_279 -> V_95 ; V_73 ++ )
V_6 [ V_73 ] = V_27 ;
return V_279 -> V_95 ;
}
static int F_214 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_278 * V_279 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
if ( V_279 -> V_95 ) {
unsigned int V_27 = V_6 [ V_279 -> V_95 - 1 ] ;
V_19 -> V_536 &= ~ V_585 ;
F_25 ( V_5 , V_19 -> V_536 , V_549 ) ;
V_19 -> V_536 &= ~ V_586 ;
V_19 -> V_536 |= F_215 ( V_27 ) ;
V_19 -> V_536 |= V_585 ;
F_25 ( V_5 , V_19 -> V_536 , V_549 ) ;
}
return V_279 -> V_95 ;
}
static int F_216 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_278 * V_279 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
switch ( V_6 [ 0 ] ) {
case V_587 :
switch ( V_6 [ 1 ] ) {
case V_588 :
V_19 -> V_536 &= ~ V_589 ;
break;
case V_590 :
V_19 -> V_536 |= V_589 ;
break;
default:
return - V_320 ;
}
F_25 ( V_5 , V_19 -> V_536 , V_549 ) ;
break;
case V_591 :
if ( V_19 -> V_536 & V_589 ) {
V_6 [ 1 ] = V_590 ;
V_6 [ 2 ] = V_592 ;
} else {
V_6 [ 1 ] = V_588 ;
V_6 [ 2 ] = V_593 * 2 ;
}
break;
default:
return - V_320 ;
}
return V_279 -> V_95 ;
}
static int F_217 ( struct V_4 * V_5 ,
int V_54 , int V_594 , int V_6 , unsigned long V_9 )
{
if ( V_54 ) {
F_9 ( V_5 , V_6 , V_9 + 2 * V_594 ) ;
return 0 ;
}
return F_18 ( V_5 , V_9 + 2 * V_594 ) ;
}
static int F_218 ( struct V_4 * V_5 , unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
V_6 [ 1 ] = V_19 -> V_595 * V_19 -> V_290 ;
V_6 [ 2 ] = V_19 -> V_596 * V_19 -> V_290 ;
return 3 ;
}
static int F_219 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_278 * V_279 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned V_597 , V_598 ;
switch ( V_6 [ 0 ] ) {
case V_599 :
switch ( V_6 [ 1 ] ) {
case V_289 :
V_597 = F_130 ( V_6 [ 2 ] ,
V_19 -> V_290 ) ;
break;
case V_291 :
V_597 = V_6 [ 2 ] / V_19 -> V_290 ;
break;
case V_292 :
V_597 =
F_131 ( V_6 [ 2 ] , V_19 -> V_290 ) ;
break;
default:
return - V_320 ;
}
switch ( V_6 [ 3 ] ) {
case V_289 :
V_598 = F_130 ( V_6 [ 4 ] ,
V_19 -> V_290 ) ;
break;
case V_291 :
V_598 = V_6 [ 4 ] / V_19 -> V_290 ;
break;
case V_292 :
V_598 =
F_131 ( V_6 [ 4 ] , V_19 -> V_290 ) ;
break;
default:
return - V_320 ;
}
if ( V_597 * V_19 -> V_290 != V_6 [ 2 ] ||
V_598 * V_19 -> V_290 != V_6 [ 4 ] ) {
V_6 [ 2 ] = V_597 * V_19 -> V_290 ;
V_6 [ 4 ] = V_598 * V_19 -> V_290 ;
return - V_600 ;
}
F_3 ( V_5 , F_220 ( V_597 ) |
F_221 ( V_598 ) ,
V_601 ) ;
V_19 -> V_595 = V_597 ;
V_19 -> V_596 = V_598 ;
return 5 ;
case V_602 :
return F_218 ( V_5 , V_6 ) ;
default:
return - V_320 ;
}
return 0 ;
}
static int F_222 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_278 * V_279 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned V_597 , V_598 ;
switch ( V_6 [ 0 ] ) {
case V_599 :
switch ( V_6 [ 1 ] ) {
case V_289 :
V_597 = F_130 ( V_6 [ 2 ] ,
V_19 -> V_290 ) ;
break;
case V_291 :
V_597 = V_6 [ 2 ] / V_19 -> V_290 ;
break;
case V_292 :
V_597 =
F_131 ( V_6 [ 2 ] , V_19 -> V_290 ) ;
break;
default:
return - V_320 ;
}
switch ( V_6 [ 3 ] ) {
case V_289 :
V_598 = F_130 ( V_6 [ 4 ] ,
V_19 -> V_290 ) ;
break;
case V_291 :
V_598 = V_6 [ 4 ] / V_19 -> V_290 ;
break;
case V_292 :
V_598 =
F_131 ( V_6 [ 4 ] , V_19 -> V_290 ) ;
break;
default:
return - V_320 ;
}
if ( V_597 * V_19 -> V_290 != V_6 [ 2 ] ||
V_598 * V_19 -> V_290 != V_6 [ 4 ] ) {
V_6 [ 2 ] = V_597 * V_19 -> V_290 ;
V_6 [ 4 ] = V_598 * V_19 -> V_290 ;
return - V_600 ;
}
F_3 ( V_5 , V_597 , V_603 ) ;
V_19 -> V_595 = V_597 ;
F_3 ( V_5 , V_598 , V_604 ) ;
V_19 -> V_596 = V_598 ;
return 5 ;
case V_602 :
return F_218 ( V_5 , V_6 ) ;
default:
return - V_320 ;
}
return 0 ;
}
static int F_223 ( int V_79 , int V_27 , int * V_605 )
{
V_79 ++ ;
* V_605 = ( ( V_79 & 0x1 ) << 11 ) |
( ( V_79 & 0x2 ) << 9 ) |
( ( V_79 & 0x4 ) << 7 ) | ( ( V_79 & 0x8 ) << 5 ) | ( V_27 & 0xff ) ;
return 12 ;
}
static int F_224 ( int V_79 , int V_27 , int * V_605 )
{
* V_605 = ( ( V_79 & 0x7 ) << 8 ) | ( V_27 & 0xff ) ;
return 11 ;
}
static int F_225 ( int V_79 , int V_27 , int * V_605 )
{
* V_605 = V_27 & 0xfff ;
return 12 ;
}
static int F_226 ( int V_79 , int V_27 , int * V_605 )
{
* V_605 = ( V_27 & 0xfff ) | ( V_79 ? 0xc000 : 0xa000 ) ;
return 16 ;
}
static int F_227 ( int V_79 , int V_27 , int * V_605 )
{
* V_605 = ( ( V_79 & 0xf ) << 8 ) | ( V_27 & 0xff ) ;
return 12 ;
}
static int F_228 ( int V_79 , int V_27 , int * V_605 )
{
* V_605 = ( ( V_79 + 1 ) << 8 ) | ( V_27 & 0xff ) ;
return 12 ;
}
static void F_229 ( struct V_4 * V_5 , int V_79 , int V_27 )
{
const struct V_102 * V_103 = V_5 -> V_104 ;
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_606 = 0 , V_42 = 0 , V_607 , V_605 = 0 ;
unsigned int V_145 ;
int V_73 ;
int type ;
if ( V_19 -> V_608 [ V_79 ] == V_27 )
return;
V_19 -> V_608 [ V_79 ] = V_27 ;
for ( V_73 = 0 ; V_73 < 3 ; V_73 ++ ) {
type = V_103 -> V_609 [ V_73 ] ;
if ( type == V_610 )
break;
if ( V_79 < V_608 [ type ] . V_383 ) {
V_42 = V_608 [ type ] . F_230 ( V_79 , V_27 , & V_605 ) ;
V_606 = F_231 ( V_73 ) ;
break;
}
V_79 -= V_608 [ type ] . V_383 ;
}
if ( V_42 == 0 )
return;
for ( V_607 = 1 << ( V_42 - 1 ) ; V_607 ; V_607 >>= 1 ) {
V_145 = ( V_607 & V_605 ) ? V_611 : 0 ;
F_9 ( V_5 , V_145 , V_612 ) ;
F_63 ( 1 ) ;
F_9 ( V_5 , V_613 | V_145 , V_612 ) ;
F_63 ( 1 ) ;
}
F_9 ( V_5 , V_606 , V_612 ) ;
F_63 ( 1 ) ;
F_9 ( V_5 , 0 , V_612 ) ;
}
static int F_232 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_278 * V_279 ,
unsigned int * V_6 )
{
F_229 ( V_5 , F_116 ( V_279 -> V_282 ) , V_6 [ 0 ] ) ;
return 1 ;
}
static int F_233 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_278 * V_279 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
V_6 [ 0 ] = V_19 -> V_608 [ F_116 ( V_279 -> V_282 ) ] ;
return 1 ;
}
static void F_234 ( struct V_4 * V_5 , struct V_83 * V_84 )
{
const struct V_102 * V_103 = V_5 -> V_104 ;
struct V_18 * V_19 = V_5 -> V_20 ;
int V_73 , V_614 ;
int V_615 ;
int V_383 = 0 ;
int V_616 ;
int V_617 = 0 ;
int type ;
int V_232 ;
type = V_103 -> V_609 [ 0 ] ;
if ( type == V_610 )
return;
V_616 = V_608 [ type ] . V_616 ;
for ( V_73 = 0 ; V_73 < 3 ; V_73 ++ ) {
type = V_103 -> V_609 [ V_73 ] ;
if ( type == V_610 )
break;
if ( V_608 [ type ] . V_616 != V_616 )
V_617 = 1 ;
V_383 += V_608 [ type ] . V_383 ;
}
V_615 = V_73 ;
V_84 -> V_230 = V_383 ;
if ( V_617 ) {
unsigned int * V_618 ;
if ( V_383 > V_619 )
F_32 ( V_5 -> V_13 ,
L_33 ) ;
V_84 -> V_618 = V_618 = V_19 -> V_620 ;
V_232 = 0 ;
for ( V_73 = 0 ; V_73 < V_615 ; V_73 ++ ) {
type = V_103 -> V_609 [ V_73 ] ;
for ( V_614 = 0 ; V_614 < V_608 [ type ] . V_383 ; V_614 ++ ) {
V_618 [ V_232 ] =
( 1 << V_608 [ type ] . V_616 ) - 1 ;
V_232 ++ ;
}
}
for ( V_232 = 0 ; V_232 < V_84 -> V_230 ; V_232 ++ )
F_229 ( V_5 , V_73 , V_84 -> V_618 [ V_73 ] / 2 ) ;
} else {
type = V_103 -> V_609 [ 0 ] ;
V_84 -> V_261 = ( 1 << V_608 [ type ] . V_616 ) - 1 ;
for ( V_232 = 0 ; V_232 < V_84 -> V_230 ; V_232 ++ )
F_229 ( V_5 , V_73 , V_84 -> V_261 / 2 ) ;
}
}
static int F_235 ( struct V_4 * V_5 , int V_79 )
{
unsigned int V_145 = V_621 ;
int V_607 ;
int V_605 ;
V_605 = 0x0300 | ( ( V_79 & 0x100 ) << 3 ) | ( V_79 & 0xff ) ;
F_9 ( V_5 , V_145 , V_612 ) ;
for ( V_607 = 0x8000 ; V_607 ; V_607 >>= 1 ) {
if ( V_607 & V_605 )
V_145 |= V_611 ;
else
V_145 &= ~ V_611 ;
F_9 ( V_5 , V_145 , V_612 ) ;
F_9 ( V_5 , V_613 | V_145 , V_612 ) ;
}
V_145 = V_621 ;
V_605 = 0 ;
for ( V_607 = 0x80 ; V_607 ; V_607 >>= 1 ) {
F_9 ( V_5 , V_145 , V_612 ) ;
F_9 ( V_5 , V_613 | V_145 , V_612 ) ;
if ( F_18 ( V_5 , V_123 ) & V_622 )
V_605 |= V_607 ;
}
F_9 ( V_5 , 0 , V_612 ) ;
return V_605 ;
}
static int F_236 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_278 * V_279 ,
unsigned int * V_6 )
{
V_6 [ 0 ] = F_235 ( V_5 , F_116 ( V_279 -> V_282 ) ) ;
return 1 ;
}
static int F_237 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_278 * V_279 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
V_6 [ 0 ] = V_19 -> V_623 [ F_116 ( V_279 -> V_282 ) ] ;
return 1 ;
}
static unsigned F_238 ( struct V_4 * V_5 ,
unsigned V_232 )
{
switch ( V_232 ) {
case 0 :
return V_624 ;
case 1 :
return V_625 ;
case 2 :
return V_626 ;
case 3 :
return V_627 ;
case 4 :
return V_628 ;
case 5 :
return V_629 ;
case 6 :
return V_630 ;
case 7 :
return V_631 ;
case 8 :
return V_632 ;
case 9 :
return V_633 ;
default:
F_32 ( V_5 -> V_13 , L_34 ) ;
break;
}
return 0 ;
}
static int F_239 ( struct V_4 * V_5 ,
unsigned V_232 , unsigned V_634 )
{
if ( V_634 != F_238 ( V_5 , V_232 ) )
return - V_320 ;
return 2 ;
}
static unsigned F_240 ( struct V_4 * V_5 ,
unsigned V_232 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
const unsigned V_635 = V_232 / 3 ;
return F_241 ( V_232 ,
V_19 -> V_636 [ V_635 ] ) ;
}
static int F_242 ( struct V_4 * V_5 ,
unsigned V_232 , unsigned V_634 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned V_637 = V_232 / 3 ;
unsigned short V_27 = V_19 -> V_636 [ V_637 ] ;
if ( ( V_634 & 0x1f ) != V_634 )
return - V_320 ;
V_27 &= ~ F_243 ( V_232 ) ;
V_27 |= F_244 ( V_232 , V_634 ) ;
F_6 ( V_5 , V_27 , F_245 ( V_637 ) ) ;
V_19 -> V_636 [ V_637 ] = V_27 ;
return 2 ;
}
static unsigned F_246 ( struct V_4 * V_5 , unsigned V_232 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
return ( V_19 -> V_22 )
? F_240 ( V_5 , V_232 )
: F_238 ( V_5 , V_232 ) ;
}
static int F_247 ( struct V_4 * V_5 , unsigned V_232 ,
unsigned V_634 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
return ( V_19 -> V_22 )
? F_242 ( V_5 , V_232 , V_634 )
: F_239 ( V_5 , V_232 , V_634 ) ;
}
static int F_248 ( struct V_4 * V_5 ,
unsigned V_638 ,
enum V_639 V_640 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned V_42 ;
if ( ! V_19 -> V_22 )
return - V_641 ;
V_42 = F_12 ( V_5 , V_642 ) ;
V_42 &= ~ F_249 ( V_638 ) ;
V_42 |= F_250 ( V_638 , V_640 ) ;
F_3 ( V_5 , V_42 , V_642 ) ;
return 0 ;
}
static int F_251 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_278 * V_279 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_232 ;
if ( V_279 -> V_95 < 1 )
return - V_320 ;
V_232 = F_116 ( V_279 -> V_282 ) ;
switch ( V_6 [ 0 ] ) {
case V_58 :
F_68 ( V_5 , V_35 , 1 << V_232 , 1 ) ;
break;
case V_55 :
F_68 ( V_5 , V_35 , 1 << V_232 , 0 ) ;
break;
case V_643 :
V_6 [ 1 ] =
( V_19 -> V_36 & ( 1 << V_232 ) ) ?
V_58 : V_55 ;
return 0 ;
case V_644 :
return F_247 ( V_5 , V_232 , V_6 [ 1 ] ) ;
case V_645 :
V_6 [ 1 ] = F_246 ( V_5 , V_232 ) ;
break;
case V_646 :
return F_248 ( V_5 , V_232 , V_6 [ 1 ] ) ;
default:
return - V_320 ;
}
return 0 ;
}
static int F_252 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_278 * V_279 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
if ( ! V_19 -> V_22 )
return - V_641 ;
if ( F_190 ( V_84 , V_6 ) )
F_6 ( V_5 , V_84 -> V_491 , V_647 ) ;
V_6 [ 1 ] = F_15 ( V_5 , V_648 ) ;
return V_279 -> V_95 ;
}
static int F_253 ( struct V_4 * V_5 )
{
unsigned short V_142 ;
const int V_72 = V_649 ;
int V_73 ;
for ( V_73 = 0 ; V_73 < V_72 ; V_73 ++ ) {
V_142 = F_67 ( V_5 , V_650 ) ;
if ( ( V_142 & V_651 ) == 0 )
break;
F_254 ( V_652 ) ;
if ( F_255 ( 1 ) )
return - V_196 ;
}
if ( V_73 == V_72 ) {
F_32 ( V_5 -> V_13 , L_20 ) ;
return - V_284 ;
}
return 0 ;
}
static void F_256 ( struct V_4 * V_5 , unsigned short V_82 )
{
static const int V_72 = 100 ;
int V_73 ;
F_65 ( V_5 , V_82 , V_653 ) ;
for ( V_73 = 0 ; V_73 < V_72 ; V_73 ++ ) {
if ( F_67 ( V_5 , V_650 ) &
V_651 )
break;
F_63 ( 1 ) ;
}
if ( V_73 == V_72 )
F_32 ( V_5 -> V_13 ,
L_35 ) ;
}
static int F_257 ( struct V_4 * V_5 ,
unsigned short * V_6 )
{
int V_86 ;
unsigned short V_142 ;
F_256 ( V_5 , V_654 | V_655 ) ;
V_86 = F_253 ( V_5 ) ;
if ( V_86 ) {
F_32 ( V_5 -> V_13 ,
L_36 ) ;
return - V_284 ;
}
V_142 = F_67 ( V_5 , V_650 ) ;
if ( V_142 & V_656 ) {
F_32 ( V_5 -> V_13 ,
L_37 ) ;
return - V_196 ;
}
if ( V_142 & V_657 ) {
F_32 ( V_5 -> V_13 ,
L_38 ) ;
}
if ( V_6 ) {
* V_6 = F_67 ( V_5 , V_658 ) ;
* V_6 ^= ( 1 << 15 ) ;
}
return 0 ;
}
static int F_258 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_278 * V_279 ,
unsigned int * V_6 )
{
int V_95 , V_86 ;
unsigned short V_659 ;
unsigned int V_660 ;
const unsigned int V_661 = 0x1000 ;
if ( V_279 -> V_282 & V_238 )
V_660 = V_661 ;
else
V_660 = F_116 ( V_279 -> V_282 ) ;
F_65 ( V_5 , V_660 , V_662 ) ;
for ( V_95 = 0 ; V_95 < V_279 -> V_95 ; V_95 ++ ) {
V_86 = F_257 ( V_5 , & V_659 ) ;
if ( V_86 < 0 )
return V_86 ;
V_6 [ V_95 ] = V_659 ;
}
return V_279 -> V_95 ;
}
static void F_259 ( struct V_4 * V_5 , unsigned int V_82 ,
unsigned int V_663 )
{
F_65 ( V_5 , ( V_82 >> 16 ) & 0xff , V_664 ) ;
F_65 ( V_5 , V_82 & 0xffff , V_665 ) ;
V_663 &= V_666 ;
F_256 ( V_5 , V_654 | V_663 ) ;
if ( F_253 ( V_5 ) )
F_32 ( V_5 -> V_13 ,
L_39 , V_14 ) ;
}
static int F_260 ( struct V_4 * V_5 )
{
unsigned int V_248 = V_667 |
V_668 ;
#if 1
F_259 ( V_5 , V_248 | V_669 ,
V_670 ) ;
F_257 ( V_5 , NULL ) ;
#else
F_259 ( V_5 , 0x400000 , V_671 ) ;
F_259 ( V_5 , V_248 | V_672 ,
V_670 ) ;
if ( F_253 ( V_5 ) )
F_32 ( V_5 -> V_13 ,
L_39 , V_14 ) ;
#endif
return 0 ;
}
static int F_261 ( unsigned V_673 ,
unsigned * V_674 ,
unsigned * V_675 ,
unsigned * V_676 )
{
unsigned div ;
unsigned V_677 = 1 ;
unsigned V_678 ;
unsigned V_679 = 1 ;
static const unsigned V_680 = 1000 ;
const unsigned V_681 = V_673 * V_680 ;
static const unsigned V_682 = 12500 ;
static const unsigned V_683 = 4 ;
int V_684 = 0 ;
for ( div = 1 ; div <= V_685 ; ++ div ) {
for ( V_678 = 1 ; V_678 <= V_686 ; ++ V_678 ) {
unsigned V_687 =
( V_681 * div ) / V_678 ;
if ( abs ( V_687 - V_682 ) <
abs ( V_684 - V_682 ) ) {
V_684 = V_687 ;
V_677 = div ;
V_679 = V_678 ;
}
}
}
if ( V_684 == 0 )
return - V_196 ;
* V_674 = V_677 ;
* V_675 = V_679 ;
* V_676 = F_130 ( V_684 *
V_683 ,
V_680 ) ;
return 0 ;
}
static int F_262 ( struct V_4 * V_5 ,
unsigned V_634 , unsigned V_688 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
static const unsigned V_689 = 50 ;
static const unsigned V_690 = 1000 ;
static const unsigned V_72 = 1000 ;
unsigned V_691 ;
unsigned V_674 ;
unsigned V_675 ;
unsigned V_692 ;
unsigned V_73 ;
int V_86 ;
if ( V_634 == V_693 )
V_688 = 100 ;
if ( V_688 < V_689 || V_688 > V_690 ) {
F_32 ( V_5 -> V_13 ,
L_40 ,
V_14 , V_689 , V_690 ) ;
return - V_320 ;
}
V_19 -> V_694 &= ~ V_695 ;
F_25 ( V_5 , V_19 -> V_694 ,
V_696 ) ;
V_691 = V_697 | V_698 ;
V_19 -> V_699 |= V_700 |
V_701 ;
V_19 -> V_699 &= ~ V_702 ;
switch ( V_634 ) {
case V_703 :
V_19 -> V_699 |= V_704 ;
break;
case V_693 :
V_19 -> V_699 |= V_705 ;
break;
default:
for ( V_692 = 0 ; V_692 <= V_706 ; ++ V_692 ) {
if ( V_634 == F_263 ( V_692 ) ) {
V_19 -> V_699 |=
F_264 ( V_692 ) ;
break;
}
}
if ( V_692 > V_706 )
return - V_320 ;
break;
}
V_86 = F_261 ( V_688 ,
& V_674 ,
& V_675 ,
& V_19 -> V_290 ) ;
if ( V_86 < 0 ) {
F_32 ( V_5 -> V_13 ,
L_41 ) ;
return V_86 ;
}
F_6 ( V_5 , V_19 -> V_699 , V_707 ) ;
V_691 |= F_265 ( V_674 ) |
F_266 ( V_675 ) ;
F_6 ( V_5 , V_691 , V_708 ) ;
V_19 -> V_709 = V_634 ;
for ( V_73 = 0 ; V_73 < V_72 ; ++ V_73 ) {
if ( F_15 ( V_5 , V_710 ) & V_711 )
break;
F_63 ( 1 ) ;
}
if ( V_73 == V_72 ) {
F_32 ( V_5 -> V_13 ,
L_42 ,
V_14 , V_634 , V_688 ) ;
return - V_712 ;
}
return 3 ;
}
static int F_267 ( struct V_4 * V_5 ,
unsigned V_634 , unsigned V_688 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
if ( V_634 == V_713 ) {
V_19 -> V_694 &= ~ V_695 ;
F_25 ( V_5 , V_19 -> V_694 ,
V_696 ) ;
V_19 -> V_290 = V_593 ;
if ( V_19 -> V_22 ) {
V_19 -> V_699 &=
~ ( V_700 |
V_701 ) ;
F_6 ( V_5 , V_19 -> V_699 ,
V_707 ) ;
F_6 ( V_5 , 0 , V_708 ) ;
}
V_19 -> V_709 = V_634 ;
} else {
if ( V_19 -> V_22 ) {
return F_262 ( V_5 , V_634 ,
V_688 ) ;
} else {
if ( V_634 == V_714 ) {
V_19 -> V_694 |=
V_695 ;
F_25 ( V_5 ,
V_19 -> V_694 ,
V_696 ) ;
if ( V_688 == 0 ) {
F_32 ( V_5 -> V_13 ,
L_43 ) ;
return - V_320 ;
}
V_19 -> V_290 = V_688 ;
V_19 -> V_709 = V_634 ;
} else {
return - V_320 ;
}
}
}
return 3 ;
}
static int F_268 ( struct V_4 * V_5 ,
unsigned V_232 , unsigned V_634 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
if ( V_232 >= F_269 ( V_19 -> V_22 ) ) {
if ( V_232 == V_715 ) {
if ( V_634 == V_716 )
return 1 ;
F_32 ( V_5 -> V_13 ,
L_44 ,
V_14 , V_232 , V_715 ) ;
return 0 ;
}
return 0 ;
}
switch ( V_634 ) {
case V_717 :
case V_718 :
case V_719 :
case V_720 :
case V_721 :
case V_722 :
case V_723 :
case V_724 :
case V_725 :
return 1 ;
case V_716 :
return ( V_19 -> V_22 ) ? 1 : 0 ;
default:
return 0 ;
}
}
static int F_270 ( struct V_4 * V_5 ,
unsigned V_232 , unsigned V_726 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
if ( F_268 ( V_5 , V_232 , V_726 ) == 0 )
return - V_320 ;
if ( V_232 < 4 ) {
V_19 -> V_727 &= ~ F_271 ( V_232 ) ;
V_19 -> V_727 |= F_272 ( V_232 , V_726 ) ;
F_25 ( V_5 , V_19 -> V_727 ,
V_728 ) ;
} else if ( V_232 < 8 ) {
V_19 -> V_729 &= ~ F_271 ( V_232 ) ;
V_19 -> V_729 |= F_272 ( V_232 , V_726 ) ;
F_25 ( V_5 , V_19 -> V_729 ,
V_730 ) ;
}
return 2 ;
}
static unsigned F_273 ( struct V_4 * V_5 , unsigned V_232 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
if ( V_232 < 4 ) {
return F_274 ( V_232 ,
V_19 -> V_727 ) ;
} else if ( V_232 < F_269 ( V_19 -> V_22 ) ) {
return F_274 ( V_232 ,
V_19 -> V_729 ) ;
} else {
if ( V_232 == V_715 )
return V_716 ;
F_32 ( V_5 -> V_13 , L_45 ) ;
return 0 ;
}
}
static int F_275 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_278 * V_279 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_232 = F_116 ( V_279 -> V_282 ) ;
unsigned int V_731 = F_269 ( V_19 -> V_22 ) ;
switch ( V_6 [ 0 ] ) {
case V_732 :
if ( V_232 < V_731 ) {
V_19 -> V_694 |=
F_276 ( V_232 , V_19 -> V_22 ) ;
} else if ( V_232 == V_715 ) {
V_19 -> V_694 |=
V_733 ;
}
F_25 ( V_5 , V_19 -> V_694 ,
V_696 ) ;
break;
case V_734 :
if ( V_232 < V_731 ) {
V_19 -> V_694 &=
~ F_276 ( V_232 , V_19 -> V_22 ) ;
} else if ( V_232 == V_715 ) {
V_19 -> V_694 &=
~ V_733 ;
}
F_25 ( V_5 , V_19 -> V_694 ,
V_696 ) ;
break;
case V_643 :
if ( V_232 < V_731 ) {
V_6 [ 1 ] =
( V_19 -> V_694 &
F_276 ( V_232 , V_19 -> V_22 ) )
? V_732
: V_734 ;
} else if ( V_232 == V_715 ) {
V_6 [ 1 ] = ( V_19 -> V_694 &
V_733 )
? V_732
: V_734 ;
}
return 2 ;
case V_587 :
return F_267 ( V_5 , V_6 [ 1 ] , V_6 [ 2 ] ) ;
case V_591 :
V_6 [ 1 ] = V_19 -> V_709 ;
V_6 [ 2 ] = V_19 -> V_290 ;
return 3 ;
case V_644 :
return F_270 ( V_5 , V_232 , V_6 [ 1 ] ) ;
case V_645 :
V_6 [ 1 ] = F_273 ( V_5 , V_232 ) ;
return 2 ;
default:
return - V_320 ;
}
return 1 ;
}
static int F_277 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_278 * V_279 ,
unsigned int * V_6 )
{
V_6 [ 1 ] = 0 ;
return V_279 -> V_95 ;
}
static void F_278 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
V_19 -> V_699 = V_735 ;
if ( F_267 ( V_5 , V_713 , 0 ) < 0 )
F_32 ( V_5 -> V_13 , L_46 ) ;
V_19 -> V_727 =
F_272 ( 0 , V_717 ) |
F_272 ( 1 , V_718 ) |
F_272 ( 2 , V_719 ) |
F_272 ( 3 , V_720 ) ;
F_25 ( V_5 , V_19 -> V_727 ,
V_728 ) ;
V_19 -> V_729 =
F_272 ( 4 , V_721 ) |
F_272 ( 5 , V_722 ) |
F_272 ( 6 , V_723 ) ;
if ( V_19 -> V_22 )
V_19 -> V_729 |=
F_272 ( 7 , V_716 ) ;
F_25 ( V_5 , V_19 -> V_729 ,
V_730 ) ;
}
static int F_279 ( struct V_4 * V_5 , struct V_83 * V_84 )
{
struct V_555 * V_556 = V_84 -> V_20 ;
int V_86 ;
V_86 = F_52 ( V_5 , V_556 -> V_1 ,
V_55 ) ;
if ( V_86 ) {
F_32 ( V_5 -> V_13 ,
L_47 ) ;
return V_86 ;
}
F_280 ( V_556 ) ;
F_61 ( V_5 , V_556 -> V_1 , 1 ) ;
return F_281 ( V_5 , V_84 ) ;
}
static int F_282 ( struct V_4 * V_5 , struct V_83 * V_84 )
{
struct V_555 * V_556 = V_84 -> V_20 ;
int V_86 ;
V_86 = F_283 ( V_556 ) ;
F_61 ( V_5 , V_556 -> V_1 , 0 ) ;
F_59 ( V_5 , V_556 -> V_1 ) ;
return V_86 ;
}
static T_7 F_284 ( int V_330 , void * V_96 )
{
struct V_4 * V_5 = V_96 ;
unsigned short V_131 ;
unsigned short V_91 ;
unsigned int V_143 = 0 ;
unsigned int V_178 = 0 ;
unsigned long V_21 ;
#ifdef F_55
struct V_18 * V_19 = V_5 -> V_20 ;
#endif
if ( ! V_5 -> V_736 )
return V_737 ;
F_285 () ;
F_26 ( & V_5 -> V_227 , V_21 ) ;
V_131 = F_29 ( V_5 , V_87 ) ;
V_91 = F_29 ( V_5 , V_92 ) ;
#ifdef F_55
if ( V_19 -> V_24 ) {
unsigned long V_738 ;
F_26 ( & V_19 -> V_50 , V_738 ) ;
if ( V_19 -> V_51 ) {
V_143 = F_202 ( V_19 -> V_51 ) ;
if ( V_143 & V_147 )
F_4 ( V_520 ,
V_19 -> V_24 -> V_521 +
F_203 ( V_19 ->
V_51 -> V_41 ) ) ;
}
if ( V_19 -> V_56 ) {
V_178 = F_202 ( V_19 -> V_56 ) ;
if ( V_178 & V_147 )
F_4 ( V_520 ,
V_19 -> V_24 -> V_521 +
F_203 ( V_19 ->
V_56 -> V_41 ) ) ;
}
F_27 ( & V_19 -> V_50 , V_738 ) ;
}
#endif
F_93 ( V_5 , V_131 ) ;
F_96 ( V_5 , V_91 ) ;
if ( ( V_131 & V_739 ) || ( V_143 & V_148 ) )
F_94 ( V_5 , V_131 , V_143 ) ;
if ( ( V_91 & V_740 ) || ( V_178 & V_148 ) )
F_97 ( V_5 , V_91 , V_178 ) ;
F_90 ( V_5 , 0 ) ;
F_90 ( V_5 , 1 ) ;
F_201 ( V_5 ) ;
F_27 ( & V_5 -> V_227 , V_21 ) ;
return V_741 ;
}
static int F_286 ( struct V_4 * V_5 )
{
struct V_18 * V_19 ;
V_19 = F_287 ( V_5 , sizeof( * V_19 ) ) ;
if ( ! V_19 )
return - V_742 ;
F_288 ( & V_19 -> V_23 ) ;
F_288 ( & V_19 -> V_30 ) ;
F_288 ( & V_19 -> V_50 ) ;
return 0 ;
}
static int F_289 ( struct V_4 * V_5 ,
unsigned V_743 , unsigned V_744 )
{
const struct V_102 * V_103 = V_5 -> V_104 ;
struct V_18 * V_19 = V_5 -> V_20 ;
struct V_83 * V_84 ;
int V_182 ;
int V_73 ;
if ( V_103 -> V_745 > V_746 ) {
F_32 ( V_5 -> V_13 , L_48 ) ;
return - V_320 ;
}
V_19 -> V_536 = V_747 |
V_545 |
V_748 |
V_749 ;
if ( ! V_19 -> V_98 ) {
V_19 -> V_536 |= ( V_750 |
V_751 ) ;
}
F_25 ( V_5 , V_19 -> V_536 , V_549 ) ;
V_182 = F_290 ( V_5 , V_752 ) ;
if ( V_182 )
return V_182 ;
V_84 = & V_5 -> V_130 [ V_753 ] ;
if ( V_103 -> V_754 ) {
V_84 -> type = V_755 ;
V_84 -> V_191 = V_756 | V_757 | V_758 ;
if ( ! V_19 -> V_115 )
V_84 -> V_191 |= V_759 | V_760 | V_761 ;
if ( V_103 -> V_762 > 0xffff )
V_84 -> V_191 |= V_192 ;
if ( V_19 -> V_22 )
V_84 -> V_191 |= V_763 ;
V_84 -> V_230 = V_103 -> V_754 ;
V_84 -> V_261 = V_103 -> V_762 ;
V_84 -> V_391 = V_764 [ V_103 -> V_241 ] ;
V_84 -> V_765 = F_128 ;
V_84 -> V_766 = F_151 ;
if ( V_5 -> V_330 ) {
V_5 -> V_85 = V_84 ;
V_84 -> V_191 |= V_767 ;
V_84 -> V_768 = 512 ;
V_84 -> V_769 = F_137 ;
V_84 -> V_770 = F_144 ;
V_84 -> V_499 = F_107 ;
V_84 -> V_771 = F_112 ;
V_84 -> V_772 = F_98 ;
if ( V_19 -> V_24 )
V_84 -> V_773 = V_774 ;
}
F_107 ( V_5 , V_84 ) ;
} else {
V_84 -> type = V_146 ;
}
V_84 = & V_5 -> V_130 [ V_775 ] ;
if ( V_103 -> V_745 ) {
V_84 -> type = V_776 ;
V_84 -> V_191 = V_777 | V_778 | V_759 ;
if ( V_19 -> V_22 )
V_84 -> V_191 |= V_763 ;
V_84 -> V_230 = V_103 -> V_745 ;
V_84 -> V_261 = V_103 -> V_779 ;
V_84 -> V_391 = V_103 -> V_780 ;
V_84 -> V_766 = F_168 ;
V_84 -> V_781 = F_164 ;
V_182 = F_291 ( V_84 ) ;
if ( V_182 )
return V_182 ;
if ( V_5 -> V_330 && ( V_103 -> V_110 || V_19 -> V_24 ) ) {
V_5 -> V_90 = V_84 ;
V_84 -> V_191 |= V_782 ;
V_84 -> V_768 = V_84 -> V_230 ;
V_84 -> V_769 = F_184 ;
V_84 -> V_770 = F_183 ;
V_84 -> V_499 = F_185 ;
if ( ! V_19 -> V_22 )
V_84 -> V_772 = F_152 ;
if ( V_19 -> V_24 )
V_84 -> V_773 = V_783 ;
}
if ( V_19 -> V_784 )
F_208 ( V_5 , V_84 ) ;
F_185 ( V_5 , V_84 ) ;
} else {
V_84 -> type = V_146 ;
}
V_84 = & V_5 -> V_130 [ V_518 ] ;
V_84 -> type = V_785 ;
V_84 -> V_191 = V_777 | V_756 ;
V_84 -> V_230 = V_103 -> V_786 ? 32 : 8 ;
V_84 -> V_261 = 1 ;
V_84 -> V_391 = & V_787 ;
if ( V_19 -> V_22 ) {
V_84 -> V_191 |= V_192 ;
V_84 -> V_788 = F_193 ;
V_84 -> V_766 = F_192 ;
if ( V_5 -> V_330 ) {
V_84 -> V_191 |= V_782 ;
V_84 -> V_768 = V_84 -> V_230 ;
V_84 -> V_769 = F_195 ;
V_84 -> V_770 = F_198 ;
V_84 -> V_499 = F_200 ;
V_84 -> V_773 = V_789 ;
}
F_3 ( V_5 , V_505 |
V_790 ,
V_503 ) ;
F_3 ( V_5 , V_84 -> V_484 , V_494 ) ;
} else {
V_84 -> V_788 = F_189 ;
V_84 -> V_766 = F_186 ;
V_19 -> V_482 = F_188 ( V_84 -> V_484 ) ;
F_6 ( V_5 , V_19 -> V_482 , V_485 ) ;
}
V_84 = & V_5 -> V_130 [ V_791 ] ;
if ( V_103 -> V_792 ) {
V_182 = F_292 ( V_5 , V_84 , F_217 ,
V_793 ) ;
if ( V_182 )
return V_182 ;
} else {
V_84 -> type = V_146 ;
}
V_84 = & V_5 -> V_130 [ V_794 ] ;
V_84 -> type = V_146 ;
V_84 = & V_5 -> V_130 [ V_795 ] ;
V_84 -> type = V_796 ;
V_84 -> V_191 = V_797 ;
V_84 -> V_230 = 1 ;
V_84 -> V_261 = 0 ;
if ( V_19 -> V_22 ) {
V_84 -> V_766 = F_219 ;
F_3 ( V_5 , 0x0 , V_601 ) ;
} else if ( V_19 -> V_74 ) {
V_84 -> V_766 = F_222 ;
} else {
V_84 -> V_191 |= V_777 ;
V_84 -> V_765 = F_233 ;
V_84 -> V_781 = F_232 ;
F_234 ( V_5 , V_84 ) ;
}
V_84 = & V_5 -> V_130 [ V_798 ] ;
V_84 -> type = V_799 ;
V_84 -> V_191 = V_756 | V_797 ;
V_84 -> V_261 = 0xff ;
if ( V_19 -> V_22 ) {
V_84 -> V_230 = V_800 ;
V_84 -> V_765 = F_237 ;
} else {
V_84 -> V_230 = 512 ;
V_84 -> V_765 = F_236 ;
}
V_84 = & V_5 -> V_130 [ V_801 ] ;
V_84 -> type = V_785 ;
V_84 -> V_191 = V_756 | V_777 | V_797 ;
V_84 -> V_261 = 1 ;
if ( V_19 -> V_22 ) {
V_84 -> V_230 = 16 ;
V_84 -> V_788 = F_252 ;
F_6 ( V_5 , V_84 -> V_491 , V_647 ) ;
for ( V_73 = 0 ; V_73 < V_802 ; ++ V_73 ) {
F_6 ( V_5 , V_19 -> V_636 [ V_73 ] ,
F_245 ( V_73 ) ) ;
}
} else {
V_84 -> V_230 = 10 ;
}
V_84 -> V_766 = F_251 ;
F_68 ( V_5 , V_35 , ~ 0 , 0 ) ;
V_84 = & V_5 -> V_130 [ V_803 ] ;
if ( V_19 -> V_784 ) {
V_84 -> type = V_755 ;
V_84 -> V_191 = V_756 | V_757 | V_797 ;
V_84 -> V_230 = V_103 -> V_745 ;
V_84 -> V_261 = ( 1 << 16 ) - 1 ;
V_84 -> V_391 = & V_804 ;
V_84 -> V_765 = F_258 ;
V_84 -> V_766 = NULL ;
F_260 ( V_5 ) ;
} else {
V_84 -> type = V_146 ;
}
V_84 = & V_5 -> V_130 [ V_805 ] ;
V_84 -> type = V_806 ;
V_84 -> V_191 = V_756 | V_777 | V_797 ;
V_84 -> V_230 = 1 ;
V_84 -> V_261 = 0xff ;
V_84 -> V_766 = F_207 ;
V_19 -> V_488 = 0 ;
V_19 -> V_540 = 0 ;
V_84 = & V_5 -> V_130 [ V_807 ] ;
V_84 -> type = V_785 ;
V_84 -> V_191 = V_756 | V_777 | V_797 ;
V_84 -> V_230 = 8 ;
V_84 -> V_261 = 1 ;
V_84 -> V_788 = F_277 ;
V_84 -> V_766 = F_275 ;
F_278 ( V_5 ) ;
V_19 -> V_62 = F_293 ( V_5 ,
F_210 ,
F_211 ,
( V_19 -> V_22 )
? V_808
: V_809 ,
V_810 ) ;
if ( ! V_19 -> V_62 )
return - V_742 ;
for ( V_73 = 0 ; V_73 < V_810 ; ++ V_73 ) {
struct V_555 * V_811 = & V_19 -> V_62 -> V_63 [ V_73 ] ;
V_811 -> V_812 = 0 ;
V_811 -> V_1 = V_73 ;
F_294 ( V_811 ) ;
V_84 = & V_5 -> V_130 [ F_1 ( V_73 ) ] ;
V_84 -> type = V_813 ;
V_84 -> V_191 = V_756 | V_777 | V_192 ;
V_84 -> V_230 = 3 ;
V_84 -> V_261 = ( V_19 -> V_22 ) ? 0xffffffff
: 0x00ffffff ;
V_84 -> V_765 = V_814 ;
V_84 -> V_781 = V_814 ;
V_84 -> V_766 = V_815 ;
#ifdef F_55
if ( V_5 -> V_330 && V_19 -> V_24 ) {
V_84 -> V_191 |= V_767 ;
V_84 -> V_768 = 1 ;
V_84 -> V_769 = V_816 ;
V_84 -> V_770 = F_279 ;
V_84 -> V_499 = F_282 ;
V_84 -> V_773 = V_789 ;
}
#endif
V_84 -> V_20 = V_811 ;
}
V_84 = & V_5 -> V_130 [ V_817 ] ;
V_84 -> type = V_813 ;
V_84 -> V_191 = V_756 | V_777 ;
V_84 -> V_230 = 1 ;
V_84 -> V_261 = 0xf ;
V_84 -> V_765 = F_212 ;
V_84 -> V_781 = F_214 ;
V_84 -> V_766 = F_216 ;
if ( V_5 -> V_330 ) {
F_25 ( V_5 ,
( V_744 ? V_818 : 0 ) |
( V_819 & 0 ) |
V_820 |
V_821 |
F_295 ( V_743 ) |
F_296 ( V_743 ) ,
V_822 ) ;
}
F_9 ( V_5 , V_19 -> V_38 , V_37 ) ;
F_9 ( V_5 , V_19 -> V_40 , V_39 ) ;
if ( V_19 -> V_98 ) {
F_9 ( V_5 , 0 , V_823 ) ;
} else if ( V_19 -> V_22 ) {
int V_41 ;
for ( V_41 = 0 ; V_41 < V_103 -> V_745 ; ++ V_41 ) {
F_9 ( V_5 , 0xf ,
F_158 ( V_41 ) ) ;
F_9 ( V_5 , 0x0 ,
F_159 ( V_41 ) ) ;
}
F_9 ( V_5 , 0x0 , V_824 ) ;
}
return 0 ;
}
static void F_297 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
if ( V_19 ) {
if ( V_19 -> V_62 )
F_298 ( V_19 -> V_62 ) ;
}
}
