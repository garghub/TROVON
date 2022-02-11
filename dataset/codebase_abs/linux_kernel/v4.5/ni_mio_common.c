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
if ( V_91 & V_163 )
V_84 -> V_107 -> V_108 |= V_124 ;
#ifndef F_55
if ( V_91 & V_180 ) {
int V_181 ;
V_181 = F_78 ( V_5 , V_84 ) ;
if ( ! V_181 ) {
F_32 ( V_5 -> V_13 , L_18 ) ;
F_68 ( V_5 , V_33 ,
V_182 |
V_183 , 0 ) ;
V_84 -> V_107 -> V_108 |= V_109 ;
}
}
#endif
F_92 ( V_5 , V_84 ) ;
}
static void F_98 ( struct V_4 * V_5 , struct V_83 * V_84 ,
void * V_6 , unsigned int V_184 ,
unsigned int V_185 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
struct V_113 * V_107 = V_84 -> V_107 ;
struct V_144 * V_145 = & V_107 -> V_145 ;
unsigned int V_106 = F_80 ( V_84 , V_184 ) ;
unsigned short * V_186 = V_6 ;
unsigned int * V_187 = V_6 ;
unsigned int V_73 ;
#ifdef F_55
T_5 * V_188 = V_6 ;
T_6 * V_189 = V_6 ;
#endif
for ( V_73 = 0 ; V_73 < V_106 ; V_73 ++ ) {
#ifdef F_55
if ( V_84 -> V_190 & V_191 )
V_187 [ V_73 ] = F_99 ( V_189 [ V_73 ] ) ;
else
V_186 [ V_73 ] = F_100 ( V_188 [ V_73 ] ) ;
#endif
if ( V_84 -> V_190 & V_191 )
V_187 [ V_73 ] += V_19 -> V_192 [ V_185 ] ;
else
V_186 [ V_73 ] += V_19 -> V_192 [ V_185 ] ;
V_185 ++ ;
V_185 %= V_145 -> V_193 ;
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
F_102 ( V_84 , V_84 -> V_107 -> V_194 ) ;
F_26 ( & V_19 -> V_50 , V_21 ) ;
if ( ! V_19 -> V_51 ) {
F_27 ( & V_19 -> V_50 , V_21 ) ;
return - V_195 ;
}
if ( V_19 -> V_115 || V_19 -> V_74 )
F_103 ( V_19 -> V_51 , 32 , 16 ) ;
else if ( V_19 -> V_196 )
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
F_106 ( V_84 , V_84 -> V_107 -> V_194 ) ;
F_26 ( & V_19 -> V_50 , V_21 ) ;
if ( V_19 -> V_56 ) {
if ( V_19 -> V_115 || V_19 -> V_197 ) {
F_103 ( V_19 -> V_56 , 32 , 32 ) ;
} else {
F_103 ( V_19 -> V_56 , 16 , 32 ) ;
}
F_104 ( V_19 -> V_56 ) ;
} else {
V_86 = - V_195 ;
}
F_27 ( & V_19 -> V_50 , V_21 ) ;
return V_86 ;
}
static int F_107 ( struct V_4 * V_5 , struct V_83 * V_84 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned V_198 ;
unsigned V_199 ;
F_56 ( V_5 ) ;
F_25 ( V_5 , V_200 | V_201 ,
V_202 ) ;
F_68 ( V_5 , V_31 , V_203 , 0 ) ;
F_62 ( V_5 ) ;
if ( ! V_19 -> V_74 )
F_9 ( V_5 , V_204 , V_205 ) ;
F_25 ( V_5 , V_206 , V_207 ) ;
F_25 ( V_5 , V_208 |
V_209
,
V_210 ) ;
F_25 ( V_5 , 0 , V_211 ) ;
F_25 ( V_5 , V_212 ,
V_213 ) ;
V_198 = V_214 |
V_215 |
V_216 ;
V_199 = F_108 ( 3 ) |
F_109 ( 0 ) |
F_110 ( 2 ) |
F_111 ( 3 ) ;
if ( V_19 -> V_115 ) {
V_199 |= V_217 ;
} else if ( V_19 -> V_74 ) {
V_199 |= V_218 ;
} else {
V_198 |= V_219 ;
if ( V_19 -> V_220 )
V_199 |= V_217 ;
else
V_199 |= V_218 ;
}
F_25 ( V_5 , V_198 , V_221 ) ;
F_25 ( V_5 , V_199 , V_222 ) ;
F_25 ( V_5 , V_223 , V_141 ) ;
F_25 ( V_5 , V_224 , V_202 ) ;
return 0 ;
}
static int F_112 ( struct V_4 * V_5 , struct V_83 * V_84 )
{
unsigned long V_21 ;
int V_225 ;
F_26 ( & V_5 -> V_226 , V_21 ) ;
#ifndef F_55
F_85 ( V_5 ) ;
#else
F_69 ( V_5 ) ;
#endif
V_225 = F_113 ( V_84 ) ;
F_27 ( & V_5 -> V_226 , V_21 ) ;
return V_225 ;
}
static void F_114 ( struct V_4 * V_5 )
{
int V_73 ;
F_25 ( V_5 , V_227 , V_207 ) ;
for ( V_73 = 0 ; V_73 < V_228 ; ++ V_73 ) {
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
unsigned int V_229 ,
unsigned int * V_230 )
{
const struct V_102 * V_103 = V_5 -> V_104 ;
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_231 , V_232 , V_233 ;
unsigned int V_73 ;
unsigned int V_234 ;
unsigned V_235 ;
F_25 ( V_5 , 1 , V_236 ) ;
if ( ( V_230 [ 0 ] & V_237 ) ) {
unsigned V_238 ;
V_231 = F_116 ( V_230 [ 0 ] ) ;
V_232 = F_117 ( V_230 [ 0 ] ) ;
V_235 = V_239 [ V_103 -> V_240 ] [ V_232 ] ;
V_234 = ( V_230 [ 0 ] & V_241 ) != 0 ;
V_238 = V_242 |
F_118 ( V_231 ) |
F_119 ( V_235 ) |
V_19 -> V_243 ;
if ( V_234 )
V_238 |= V_244 ;
V_238 |= V_245 ;
F_3 ( V_5 , V_238 , V_246 ) ;
} else {
F_3 ( V_5 , 0 , V_246 ) ;
}
for ( V_73 = 0 ; V_73 < V_229 ; V_73 ++ ) {
unsigned V_247 = 0 ;
V_231 = F_116 ( V_230 [ V_73 ] ) ;
V_233 = F_120 ( V_230 [ V_73 ] ) ;
V_232 = F_117 ( V_230 [ V_73 ] ) ;
V_234 = ( V_230 [ V_73 ] & V_241 ) != 0 ;
V_235 = V_239 [ V_103 -> V_240 ] [ V_232 ] ;
V_19 -> V_192 [ V_73 ] = 0 ;
switch ( V_233 ) {
case V_248 :
V_247 |= V_249 ;
break;
case V_250 :
V_247 |= V_251 ;
break;
case V_252 :
V_247 |= V_253 ;
break;
case V_254 :
break;
}
V_247 |= F_121 ( V_231 ) ;
V_247 |= F_122 ( V_231 ) ;
V_247 |= F_123 ( V_235 ) ;
if ( V_73 == V_229 - 1 )
V_247 |= V_255 ;
if ( V_234 )
V_247 |= V_256 ;
V_247 |= V_257 ;
F_6 ( V_5 , V_247 , V_258 ) ;
}
F_114 ( V_5 ) ;
}
static void F_124 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
unsigned int V_229 , unsigned int * V_230 )
{
const struct V_102 * V_103 = V_5 -> V_104 ;
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_259 = ( V_84 -> V_260 + 1 ) >> 1 ;
unsigned int V_231 , V_232 , V_233 ;
unsigned int V_73 ;
unsigned int V_261 , V_262 ;
unsigned int V_234 ;
if ( V_19 -> V_22 ) {
F_115 ( V_5 , V_229 , V_230 ) ;
return;
}
if ( V_229 == 1 && ! V_19 -> V_115 && ! V_19 -> V_74 ) {
if ( V_19 -> V_263
&& V_19 -> V_264 == V_230 [ 0 ] ) {
return;
}
V_19 -> V_263 = 1 ;
V_19 -> V_264 = V_230 [ 0 ] ;
} else {
V_19 -> V_263 = 0 ;
}
F_25 ( V_5 , 1 , V_236 ) ;
if ( V_19 -> V_74 ) {
if ( ( V_230 [ 0 ] & V_237 )
&& ! V_19 -> V_265 ) {
F_6 ( V_5 , V_19 -> V_243 |
V_266 ,
V_267 ) ;
F_6 ( V_5 , V_19 -> V_243 ,
V_267 ) ;
V_19 -> V_265 = 1 ;
F_125 ( 100 ) ;
} else if ( ! ( V_230 [ 0 ] & V_237 )
&& V_19 -> V_265 ) {
F_6 ( V_5 , V_19 -> V_243 |
V_268 ,
V_267 ) ;
F_6 ( V_5 , V_19 -> V_243 ,
V_267 ) ;
V_19 -> V_265 = 0 ;
F_125 ( 100 ) ;
}
}
for ( V_73 = 0 ; V_73 < V_229 ; V_73 ++ ) {
if ( ! V_19 -> V_74 && ( V_230 [ V_73 ] & V_237 ) )
V_231 = V_19 -> V_243 ;
else
V_231 = F_116 ( V_230 [ V_73 ] ) ;
V_233 = F_120 ( V_230 [ V_73 ] ) ;
V_232 = F_117 ( V_230 [ V_73 ] ) ;
V_234 = ( V_230 [ V_73 ] & V_241 ) != 0 ;
V_232 = V_239 [ V_103 -> V_240 ] [ V_232 ] ;
if ( V_19 -> V_115 )
V_19 -> V_192 [ V_73 ] = V_259 ;
else
V_19 -> V_192 [ V_73 ] = ( V_232 & 0x100 ) ? 0 : V_259 ;
V_261 = 0 ;
if ( ( V_230 [ V_73 ] & V_237 ) ) {
if ( V_19 -> V_115 )
F_6 ( V_5 , F_116 ( V_230 [ V_73 ] ) & 0x0003 ,
V_269 ) ;
} else {
if ( V_19 -> V_115 )
V_233 = V_248 ;
else if ( V_19 -> V_74 )
V_233 = V_254 ;
switch ( V_233 ) {
case V_248 :
V_261 |= V_270 ;
break;
case V_250 :
V_261 |= V_271 ;
break;
case V_252 :
V_261 |= V_272 ;
break;
case V_254 :
break;
}
}
V_261 |= F_126 ( V_231 ) ;
F_6 ( V_5 , V_261 , V_273 ) ;
if ( ! V_19 -> V_74 ) {
V_262 = F_127 ( V_232 ) ;
if ( V_73 == V_229 - 1 )
V_262 |= V_274 ;
if ( V_234 )
V_262 |= V_275 ;
F_6 ( V_5 , V_262 , V_276 ) ;
}
}
if ( ! V_19 -> V_115 && ! V_19 -> V_74 )
F_114 ( V_5 ) ;
}
static int F_128 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_277 * V_278 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_279 = ( V_84 -> V_260 + 1 ) >> 1 ;
int V_73 , V_95 ;
unsigned V_280 ;
unsigned int V_96 ;
unsigned long V_114 ;
F_124 ( V_5 , V_84 , 1 , & V_278 -> V_281 ) ;
F_62 ( V_5 ) ;
V_280 = V_19 -> V_192 [ 0 ] ;
if ( V_19 -> V_115 ) {
for ( V_95 = 0 ; V_95 < V_282 ; V_95 ++ ) {
F_25 ( V_5 , V_227 ,
V_207 ) ;
F_63 ( 1 ) ;
}
for ( V_95 = 0 ; V_95 < V_278 -> V_95 ; V_95 ++ ) {
F_25 ( V_5 , V_227 ,
V_207 ) ;
V_96 = 0 ;
for ( V_73 = 0 ; V_73 < V_228 ; V_73 ++ ) {
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
if ( V_73 == V_228 ) {
F_32 ( V_5 -> V_13 , L_20 ) ;
return - V_283 ;
}
V_96 += V_280 ;
V_6 [ V_95 ] = V_96 ;
}
} else if ( V_19 -> V_74 ) {
for ( V_95 = 0 ; V_95 < V_278 -> V_95 ; V_95 ++ ) {
F_25 ( V_5 , V_227 ,
V_207 ) ;
V_114 = 0 ;
for ( V_73 = 0 ; V_73 < V_228 ; V_73 ++ ) {
if ( F_12 ( V_5 , V_76 ) &
0x01 ) {
F_3 ( V_5 , 0x01 ,
V_75 ) ;
V_114 = F_12 ( V_5 ,
V_117 ) ;
break;
}
}
if ( V_73 == V_228 ) {
F_32 ( V_5 -> V_13 , L_20 ) ;
return - V_283 ;
}
V_6 [ V_95 ] = ( ( ( V_114 >> 16 ) & 0xFFFF ) + V_280 ) & 0xFFFF ;
}
} else {
for ( V_95 = 0 ; V_95 < V_278 -> V_95 ; V_95 ++ ) {
F_25 ( V_5 , V_227 ,
V_207 ) ;
for ( V_73 = 0 ; V_73 < V_228 ; V_73 ++ ) {
if ( ! ( F_29 ( V_5 , V_87 ) &
V_88 ) )
break;
}
if ( V_73 == V_228 ) {
F_32 ( V_5 -> V_13 , L_20 ) ;
return - V_283 ;
}
if ( V_19 -> V_22 ) {
V_114 = F_12 ( V_5 , V_284 ) ;
V_114 &= V_279 ;
V_6 [ V_95 ] = V_114 ;
} else {
V_96 = F_15 ( V_5 , V_120 ) ;
V_96 += V_280 ;
V_6 [ V_95 ] = V_96 ;
}
}
}
return V_278 -> V_95 ;
}
static int F_129 ( const struct V_4 * V_5 , unsigned V_285 ,
unsigned int V_21 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
int V_286 ;
switch ( V_21 & V_287 ) {
case V_288 :
default:
V_286 = ( V_285 + V_19 -> V_289 / 2 ) / V_19 -> V_289 ;
break;
case V_290 :
V_286 = ( V_285 ) / V_19 -> V_289 ;
break;
case V_291 :
V_286 = ( V_285 + V_19 -> V_289 - 1 ) / V_19 -> V_289 ;
break;
}
return V_286 - 1 ;
}
static unsigned F_130 ( const struct V_4 * V_5 , int V_292 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
return V_19 -> V_289 * ( V_292 + 1 ) ;
}
static unsigned F_131 ( struct V_4 * V_5 ,
unsigned V_293 )
{
const struct V_102 * V_103 = V_5 -> V_104 ;
struct V_18 * V_19 = V_5 -> V_20 ;
if ( V_19 -> V_115 || V_19 -> V_74 )
return V_103 -> V_294 ;
return V_103 -> V_294 * V_293 ;
}
static int F_132 ( struct V_4 * V_5 , struct V_83 * V_84 ,
struct V_144 * V_145 )
{
const struct V_102 * V_103 = V_5 -> V_104 ;
struct V_18 * V_19 = V_5 -> V_20 ;
int V_295 = 0 ;
unsigned int V_296 ;
unsigned int V_297 ;
V_295 |= F_133 ( & V_145 -> V_298 ,
V_299 | V_300 | V_301 ) ;
V_295 |= F_133 ( & V_145 -> V_302 ,
V_303 | V_301 ) ;
V_297 = V_303 | V_301 ;
if ( V_19 -> V_115 || V_19 -> V_74 )
V_297 |= V_299 ;
V_295 |= F_133 ( & V_145 -> V_304 , V_297 ) ;
V_295 |= F_133 ( & V_145 -> V_305 , V_161 ) ;
V_295 |= F_133 ( & V_145 -> V_160 , V_161 | V_306 ) ;
if ( V_295 )
return 1 ;
V_295 |= F_134 ( V_145 -> V_298 ) ;
V_295 |= F_134 ( V_145 -> V_302 ) ;
V_295 |= F_134 ( V_145 -> V_304 ) ;
V_295 |= F_134 ( V_145 -> V_160 ) ;
if ( V_295 )
return 2 ;
switch ( V_145 -> V_298 ) {
case V_299 :
case V_300 :
V_295 |= F_135 ( & V_145 -> V_307 , 0 ) ;
break;
case V_301 :
V_296 = F_116 ( V_145 -> V_307 ) ;
if ( V_296 > 16 )
V_296 = 16 ;
V_296 |= ( V_145 -> V_307 & ( V_308 | V_309 ) ) ;
V_295 |= F_135 ( & V_145 -> V_307 , V_296 ) ;
break;
}
if ( V_145 -> V_302 == V_303 ) {
V_295 |= F_136 ( & V_145 -> V_310 ,
F_131 ( V_5 , V_145 -> V_193 ) ) ;
V_295 |= F_137 ( & V_145 -> V_310 ,
V_19 -> V_289 *
0xffffff ) ;
} else if ( V_145 -> V_302 == V_301 ) {
unsigned int V_296 = F_116 ( V_145 -> V_310 ) ;
if ( V_296 > 16 )
V_296 = 16 ;
V_296 |= ( V_145 -> V_310 & ( V_308 | V_309 ) ) ;
V_295 |= F_135 ( & V_145 -> V_310 , V_296 ) ;
} else {
V_295 |= F_135 ( & V_145 -> V_310 , 0 ) ;
}
if ( V_145 -> V_304 == V_303 ) {
if ( V_19 -> V_115 || V_19 -> V_74 ) {
V_295 |= F_135 ( & V_145 -> V_311 ,
0 ) ;
} else {
V_295 |= F_136 ( & V_145 -> V_311 ,
V_103 -> V_294 ) ;
V_295 |= F_137 ( & V_145 -> V_311 ,
V_19 -> V_289 *
0xffff ) ;
}
} else if ( V_145 -> V_304 == V_301 ) {
unsigned int V_296 = F_116 ( V_145 -> V_311 ) ;
if ( V_296 > 16 )
V_296 = 16 ;
V_296 |= ( V_145 -> V_311 & ( V_241 | V_308 ) ) ;
V_295 |= F_135 ( & V_145 -> V_311 , V_296 ) ;
} else if ( V_145 -> V_304 == V_299 ) {
V_295 |= F_135 ( & V_145 -> V_311 , 0 ) ;
}
V_295 |= F_135 ( & V_145 -> V_312 ,
V_145 -> V_193 ) ;
if ( V_145 -> V_160 == V_161 ) {
unsigned int V_313 = 0x01000000 ;
if ( V_19 -> V_115 )
V_313 -= V_282 ;
V_295 |= F_137 ( & V_145 -> V_314 , V_313 ) ;
V_295 |= F_136 ( & V_145 -> V_314 , 1 ) ;
} else {
V_295 |= F_135 ( & V_145 -> V_314 , 0 ) ;
}
if ( V_295 )
return 3 ;
if ( V_145 -> V_302 == V_303 ) {
V_296 = V_145 -> V_310 ;
V_145 -> V_310 =
F_130 ( V_5 , F_129 ( V_5 ,
V_145 -> V_310 ,
V_145 -> V_21 ) ) ;
if ( V_296 != V_145 -> V_310 )
V_295 ++ ;
}
if ( V_145 -> V_304 == V_303 ) {
if ( ! V_19 -> V_115 && ! V_19 -> V_74 ) {
V_296 = V_145 -> V_311 ;
V_145 -> V_311 =
F_130 ( V_5 , F_129 ( V_5 ,
V_145 -> V_311 ,
V_145 -> V_21 ) ) ;
if ( V_296 != V_145 -> V_311 )
V_295 ++ ;
if ( V_145 -> V_302 == V_303 &&
V_145 -> V_310 <
V_145 -> V_311 * V_145 -> V_312 ) {
V_145 -> V_310 =
V_145 -> V_311 * V_145 -> V_312 ;
V_295 ++ ;
}
}
}
if ( V_295 )
return 4 ;
return 0 ;
}
static int F_138 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
unsigned int V_315 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
struct V_144 * V_145 = & V_84 -> V_107 -> V_145 ;
if ( V_315 != V_145 -> V_307 )
return - V_316 ;
F_25 ( V_5 , V_317 | V_19 -> V_128 ,
V_318 ) ;
V_84 -> V_107 -> V_319 = NULL ;
return 1 ;
}
static int F_139 ( struct V_4 * V_5 , struct V_83 * V_84 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
const struct V_144 * V_145 = & V_84 -> V_107 -> V_145 ;
int V_292 ;
int V_320 = 0 ;
int V_321 = 0 ;
int V_322 = 0 ;
unsigned int V_323 ;
int V_324 = 0 ;
unsigned V_325 ;
if ( V_5 -> V_326 == 0 ) {
F_32 ( V_5 -> V_13 , L_21 ) ;
return - V_195 ;
}
F_62 ( V_5 ) ;
F_124 ( V_5 , V_84 , V_145 -> V_193 , V_145 -> V_327 ) ;
F_25 ( V_5 , V_200 , V_202 ) ;
V_19 -> V_328 &= ~ V_329 ;
F_25 ( V_5 , V_19 -> V_328 , V_330 ) ;
V_325 = F_140 ( 0 ) | V_331 ;
switch ( V_145 -> V_298 ) {
case V_300 :
case V_299 :
V_325 |= V_332 |
F_141 ( 0 ) ;
break;
case V_301 :
V_325 |= F_141 ( F_116 ( V_145 -> V_307 ) +
1 ) ;
if ( V_145 -> V_307 & V_308 )
V_325 |= V_333 ;
if ( V_145 -> V_307 & V_309 )
V_325 |= V_332 ;
break;
}
F_25 ( V_5 , V_325 , V_334 ) ;
V_321 &= ~ V_335 ;
V_321 &= ~ V_336 ;
V_321 &= ~ V_337 ;
F_25 ( V_5 , V_321 , V_211 ) ;
if ( V_145 -> V_193 == 1 || V_19 -> V_115 || V_19 -> V_74 ) {
V_322 |= V_338 |
F_142 ( 31 ) |
V_339 ;
} else {
V_322 |= F_142 ( 19 ) ;
}
F_25 ( V_5 , V_322 , V_340 ) ;
V_19 -> V_128 = 0 ;
switch ( V_145 -> V_160 ) {
case V_161 :
V_323 = V_145 -> V_314 - 1 ;
if ( V_19 -> V_115 ) {
V_323 += V_282 ;
}
F_28 ( V_5 , V_323 , V_341 ) ;
V_320 |= V_208 |
V_209 |
V_342 ;
F_25 ( V_5 , V_320 , V_210 ) ;
F_25 ( V_5 , V_343 , V_207 ) ;
if ( V_323 == 0 ) {
V_19 -> V_128 |= V_129 ;
V_324 |= V_344 ;
if ( V_145 -> V_193 > 1 )
V_322 |= V_338 |
V_345 ;
}
break;
case V_306 :
F_28 ( V_5 , 0 , V_341 ) ;
V_320 |= V_208 |
V_209 |
V_346 ;
F_25 ( V_5 , V_320 , V_210 ) ;
F_25 ( V_5 , V_343 , V_207 ) ;
break;
}
switch ( V_145 -> V_302 ) {
case V_303 :
V_322 |= V_347 | V_348 ;
F_25 ( V_5 , V_322 , V_340 ) ;
V_321 &= ~ V_349 ;
V_321 |= F_143 ( 0 ) ;
F_25 ( V_5 , V_321 , V_211 ) ;
V_292 = F_129 ( V_5 , V_145 -> V_310 ,
V_288 ) ;
F_28 ( V_5 , V_292 , V_350 ) ;
F_25 ( V_5 , V_351 , V_207 ) ;
break;
case V_301 :
if ( V_145 -> V_310 & V_309 )
V_322 |= V_347 ;
if ( V_145 -> V_310 & V_308 )
V_322 |= V_352 ;
if ( V_145 -> V_302 != V_145 -> V_304 ||
( V_145 -> V_310 & ~ V_309 ) !=
( V_145 -> V_311 & ~ V_309 ) )
V_322 |= V_348 ;
V_322 |=
F_144 ( 1 + F_116 ( V_145 -> V_310 ) ) ;
F_25 ( V_5 , V_322 , V_340 ) ;
break;
}
switch ( V_145 -> V_304 ) {
case V_303 :
case V_299 :
if ( V_145 -> V_311 == 0 || V_145 -> V_304 == V_299 )
V_292 = 1 ;
else
V_292 = F_129 ( V_5 , V_145 -> V_311 ,
V_288 ) ;
F_25 ( V_5 , 1 , V_353 ) ;
F_25 ( V_5 , V_292 , V_354 ) ;
V_321 &= ~ V_355 ;
V_321 |= V_356 ;
F_25 ( V_5 , V_321 , V_211 ) ;
F_25 ( V_5 , V_357 , V_207 ) ;
V_321 |= V_355 ;
V_321 |= V_356 ;
F_25 ( V_5 , V_321 , V_211 ) ;
break;
case V_301 :
V_320 |= F_145 ( 1 + V_145 -> V_311 ) ;
if ( ( V_145 -> V_311 & V_308 ) == 0 )
V_320 |= V_358 ;
F_25 ( V_5 , V_320 , V_210 ) ;
V_321 |= V_359 |
V_360 ;
F_25 ( V_5 , V_321 , V_211 ) ;
break;
}
if ( V_5 -> V_326 ) {
V_324 |= V_361 |
V_362 ;
#ifndef F_55
V_324 |= V_363 ;
#endif
if ( ( V_145 -> V_21 & V_364 ) ||
( V_19 -> V_128 & V_129 ) ) {
V_19 -> V_125 = V_126 ;
} else {
V_19 -> V_125 = V_365 ;
}
switch ( V_19 -> V_125 ) {
case V_365 :
#ifdef F_55
F_25 ( V_5 , V_366 ,
V_213 ) ;
#else
F_25 ( V_5 , V_367 ,
V_213 ) ;
#endif
break;
case V_368 :
F_25 ( V_5 , V_212 ,
V_213 ) ;
break;
case V_126 :
#ifdef F_55
F_25 ( V_5 , V_212 ,
V_213 ) ;
#else
F_25 ( V_5 , V_367 ,
V_213 ) ;
#endif
V_324 |= V_344 ;
break;
default:
break;
}
F_25 ( V_5 , V_223 , V_141 ) ;
F_68 ( V_5 , V_31 , V_324 , 1 ) ;
} else {
F_68 ( V_5 , V_31 , ~ 0 , 0 ) ;
}
F_25 ( V_5 , V_224 , V_202 ) ;
switch ( V_145 -> V_302 ) {
case V_303 :
F_25 ( V_5 , V_369 |
V_370 |
V_371 |
V_372 ,
V_207 ) ;
break;
case V_301 :
F_25 ( V_5 , V_369 |
V_370 |
V_371 |
V_372 ,
V_207 ) ;
break;
}
#ifdef F_55
{
int V_86 = F_101 ( V_5 ) ;
if ( V_86 )
return V_86 ;
}
#endif
if ( V_145 -> V_298 == V_299 ) {
F_25 ( V_5 , V_317 |
V_19 -> V_128 ,
V_318 ) ;
V_84 -> V_107 -> V_319 = NULL ;
} else if ( V_145 -> V_298 == V_301 ) {
V_84 -> V_107 -> V_319 = NULL ;
} else {
V_84 -> V_107 -> V_319 = F_138 ;
}
return 0 ;
}
static int F_146 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_277 * V_278 , unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
if ( V_278 -> V_95 < 1 )
return - V_316 ;
switch ( V_6 [ 0 ] ) {
case V_373 :
if ( V_19 -> V_22 ) {
if ( V_6 [ 1 ] & ~ V_374 )
return - V_316 ;
V_19 -> V_243 = V_6 [ 1 ] ;
} else if ( V_19 -> V_74 ) {
unsigned int V_375 ;
V_375 = V_6 [ 1 ] & 0xf ;
V_19 -> V_243 = V_375 ;
F_6 ( V_5 , V_375 , V_267 ) ;
} else {
unsigned int V_375 ;
unsigned int V_376 ;
V_375 = V_6 [ 1 ] & 0xf ;
V_376 = ( V_6 [ 1 ] >> 4 ) & 0xff ;
if ( V_375 >= 8 )
return - V_316 ;
V_19 -> V_243 = V_375 ;
if ( V_19 -> V_115 ) {
F_9 ( V_5 , V_376 ,
V_377 ) ;
}
}
return 2 ;
default:
break;
}
return - V_316 ;
}
static void F_147 ( struct V_4 * V_5 , struct V_83 * V_84 ,
void * V_6 , unsigned int V_184 ,
unsigned int V_185 )
{
struct V_144 * V_145 = & V_84 -> V_107 -> V_145 ;
unsigned int V_106 = F_80 ( V_84 , V_184 ) ;
unsigned short * V_186 = V_6 ;
unsigned int V_73 ;
#ifdef F_55
T_5 V_378 , * V_188 = V_6 ;
#endif
for ( V_73 = 0 ; V_73 < V_106 ; V_73 ++ ) {
unsigned int V_232 = F_117 ( V_145 -> V_327 [ V_185 ] ) ;
unsigned short V_27 = V_186 [ V_73 ] ;
if ( F_148 ( V_84 , V_232 ) )
V_27 = F_149 ( V_84 , V_27 ) ;
#ifdef F_55
V_378 = F_150 ( V_27 ) ;
V_188 [ V_73 ] = V_378 ;
#else
V_186 [ V_73 ] = V_27 ;
#endif
V_185 ++ ;
V_185 %= V_145 -> V_193 ;
}
}
static int F_151 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
unsigned int V_281 [] ,
unsigned int V_379 , int V_380 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_232 ;
unsigned int V_231 ;
unsigned int V_381 ;
int V_73 ;
int V_382 = 0 ;
if ( V_380 ) {
for ( V_73 = 0 ; V_73 < V_84 -> V_229 ; ++ V_73 ) {
V_19 -> V_383 [ V_73 ] &= ~ V_384 ;
F_9 ( V_5 , V_19 -> V_383 [ V_73 ] ,
F_152 ( V_73 ) ) ;
F_9 ( V_5 , 0xf , F_153 ( V_73 ) ) ;
}
}
for ( V_73 = 0 ; V_73 < V_379 ; V_73 ++ ) {
const struct V_385 * V_386 ;
V_231 = F_116 ( V_281 [ V_73 ] ) ;
V_232 = F_117 ( V_281 [ V_73 ] ) ;
V_386 = V_84 -> V_387 -> V_232 + V_232 ;
V_382 = 0 ;
V_381 = 0 ;
switch ( V_386 -> V_388 - V_386 -> V_389 ) {
case 20000000 :
V_381 |= V_390 ;
F_9 ( V_5 , 0 , F_154 ( V_231 ) ) ;
break;
case 10000000 :
V_381 |= V_391 ;
F_9 ( V_5 , 0 , F_154 ( V_231 ) ) ;
break;
case 4000000 :
V_381 |= V_390 ;
F_9 ( V_5 , V_392 ,
F_154 ( V_231 ) ) ;
break;
case 2000000 :
V_381 |= V_391 ;
F_9 ( V_5 , V_392 ,
F_154 ( V_231 ) ) ;
break;
default:
F_32 ( V_5 -> V_13 ,
L_22 ) ;
break;
}
switch ( V_386 -> V_388 + V_386 -> V_389 ) {
case 0 :
V_381 |= V_393 ;
break;
case 10000000 :
V_381 |= V_394 ;
break;
default:
F_32 ( V_5 -> V_13 ,
L_23 ) ;
break;
}
if ( V_380 )
V_381 |= V_384 ;
F_9 ( V_5 , V_381 , F_152 ( V_231 ) ) ;
V_19 -> V_383 [ V_231 ] = V_381 ;
F_9 ( V_5 , V_73 , F_153 ( V_231 ) ) ;
}
return V_382 ;
}
static int F_155 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
unsigned int V_281 [] ,
unsigned int V_379 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_232 ;
unsigned int V_231 ;
unsigned int V_381 ;
int V_73 ;
int V_382 = 0 ;
for ( V_73 = 0 ; V_73 < V_379 ; V_73 ++ ) {
V_231 = F_116 ( V_281 [ V_73 ] ) ;
V_232 = F_117 ( V_281 [ V_73 ] ) ;
V_381 = F_156 ( V_231 ) ;
if ( F_148 ( V_84 , V_232 ) ) {
V_381 |= V_395 ;
V_382 = ( V_84 -> V_260 + 1 ) >> 1 ;
} else {
V_382 = 0 ;
}
if ( F_157 ( V_84 , V_232 ) )
V_381 |= V_396 ;
if ( V_281 [ V_73 ] & V_397 )
V_381 |= V_398 ;
if ( F_120 ( V_281 [ V_73 ] ) == V_254 )
V_381 |= V_399 ;
F_6 ( V_5 , V_381 , V_400 ) ;
V_19 -> V_383 [ V_231 ] = V_381 ;
}
return V_382 ;
}
static int F_158 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
unsigned int V_281 [] , unsigned int V_379 ,
int V_380 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
if ( V_19 -> V_22 )
return F_151 ( V_5 , V_84 , V_281 , V_379 ,
V_380 ) ;
else
return F_155 ( V_5 , V_84 , V_281 , V_379 ) ;
}
static int F_159 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_277 * V_278 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_231 = F_116 ( V_278 -> V_281 ) ;
unsigned int V_232 = F_117 ( V_278 -> V_281 ) ;
int V_7 ;
int V_73 ;
if ( V_19 -> V_98 ) {
F_65 ( V_5 , 1 << V_231 , V_401 ) ;
V_7 = F_160 ( V_231 ) ;
} else if ( V_19 -> V_22 ) {
V_7 = F_161 ( V_231 ) ;
} else {
V_7 = F_162 ( V_231 ) ;
}
F_158 ( V_5 , V_84 , & V_278 -> V_281 , 1 , 0 ) ;
for ( V_73 = 0 ; V_73 < V_278 -> V_95 ; V_73 ++ ) {
unsigned int V_27 = V_6 [ V_73 ] ;
V_84 -> V_402 [ V_231 ] = V_27 ;
if ( V_19 -> V_98 ) {
V_27 = F_149 ( V_84 , V_27 ) ;
F_65 ( V_5 , V_27 , V_7 ) ;
} else if ( V_19 -> V_22 ) {
F_6 ( V_5 , V_27 , V_7 ) ;
} else {
if ( F_148 ( V_84 , V_232 ) )
V_27 = F_149 ( V_84 , V_27 ) ;
F_6 ( V_5 , V_27 , V_7 ) ;
}
}
return V_278 -> V_95 ;
}
static int F_163 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_277 * V_278 , unsigned int * V_6 )
{
const struct V_102 * V_103 = V_5 -> V_104 ;
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_105 ;
switch ( V_6 [ 0 ] ) {
case V_403 :
switch ( V_6 [ 1 ] ) {
case V_58 :
V_105 = F_164 ( V_84 ,
V_103 -> V_110 ) ;
V_6 [ 2 ] = 1 + V_105 ;
if ( V_19 -> V_24 )
V_6 [ 2 ] += V_19 -> V_24 -> V_404 ;
break;
case V_55 :
V_6 [ 2 ] = 0 ;
break;
default:
return - V_316 ;
}
return 0 ;
default:
break;
}
return - V_316 ;
}
static int F_165 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
unsigned int V_315 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
struct V_144 * V_145 = & V_84 -> V_107 -> V_145 ;
int V_181 ;
int V_405 ;
int V_73 ;
static const int V_72 = 1000 ;
if ( V_315 != V_145 -> V_307 )
return - V_316 ;
V_84 -> V_107 -> V_319 = NULL ;
F_68 ( V_5 , V_33 ,
V_182 | V_183 , 0 ) ;
V_405 = V_183 ;
#ifdef F_55
F_25 ( V_5 , 1 , V_111 ) ;
if ( V_19 -> V_98 )
F_66 ( V_5 , 0x6 , V_112 ) ;
V_181 = F_105 ( V_5 ) ;
if ( V_181 )
return V_181 ;
V_181 = F_75 ( V_5 ) ;
if ( V_181 < 0 )
return V_181 ;
#else
V_181 = F_81 ( V_5 , V_84 ) ;
if ( V_181 == 0 )
return - V_94 ;
V_405 |= V_182 ;
#endif
F_25 ( V_5 , V_19 -> V_406 | V_407 ,
V_408 ) ;
F_25 ( V_5 , V_19 -> V_406 , V_408 ) ;
for ( V_73 = 0 ; V_73 < V_72 ; V_73 ++ ) {
F_63 ( 1 ) ;
if ( ( F_29 ( V_5 , V_409 ) &
V_410 ) == 0 )
break;
}
if ( V_73 == V_72 ) {
F_32 ( V_5 -> V_13 ,
L_24 ) ;
return - V_195 ;
}
F_25 ( V_5 , V_166 , V_177 ) ;
F_68 ( V_5 , V_33 , V_405 , 1 ) ;
F_25 ( V_5 , V_411 |
V_412 |
V_413 |
V_414 |
V_415 |
V_19 -> V_416 ,
V_417 ) ;
F_25 ( V_5 , V_418 | V_19 -> V_419 ,
V_420 ) ;
return 0 ;
}
static int F_166 ( struct V_4 * V_5 , struct V_83 * V_84 )
{
const struct V_102 * V_103 = V_5 -> V_104 ;
struct V_18 * V_19 = V_5 -> V_20 ;
const struct V_144 * V_145 = & V_84 -> V_107 -> V_145 ;
int V_42 ;
int V_73 ;
unsigned V_421 ;
unsigned V_27 ;
if ( V_5 -> V_326 == 0 ) {
F_32 ( V_5 -> V_13 , L_21 ) ;
return - V_195 ;
}
F_25 ( V_5 , V_422 , V_202 ) ;
F_25 ( V_5 , V_423 , V_417 ) ;
if ( V_19 -> V_98 ) {
F_65 ( V_5 , V_424 ,
V_425 ) ;
V_42 = 0 ;
for ( V_73 = 0 ; V_73 < V_145 -> V_193 ; V_73 ++ ) {
int V_231 ;
V_231 = F_116 ( V_145 -> V_327 [ V_73 ] ) ;
V_42 |= 1 << V_231 ;
F_65 ( V_5 , V_231 , V_426 ) ;
}
F_65 ( V_5 , V_42 , V_427 ) ;
}
F_158 ( V_5 , V_84 , V_145 -> V_327 , V_145 -> V_193 , 1 ) ;
if ( V_145 -> V_160 == V_306 ) {
V_19 -> V_428 |= V_429 ;
V_19 -> V_428 &= ~ V_430 ;
} else {
V_19 -> V_428 &= ~ V_429 ;
V_19 -> V_428 |= V_430 ;
}
F_25 ( V_5 , V_19 -> V_428 , V_431 ) ;
V_27 = V_19 -> V_432 ;
switch ( V_145 -> V_298 ) {
case V_300 :
case V_299 :
V_27 &= ~ ( V_433 |
V_434 ) ;
V_27 |= V_435 |
V_436 ;
break;
case V_301 :
V_27 = F_167 ( F_116 ( V_145 -> V_307 ) + 1 ) ;
if ( V_145 -> V_307 & V_308 ) {
V_27 |= V_433 ;
}
if ( V_145 -> V_307 & V_309 ) {
V_27 |= V_435 ;
}
F_25 ( V_5 , V_19 -> V_432 ,
V_437 ) ;
break;
default:
F_2 () ;
break;
}
V_19 -> V_432 = V_27 ;
F_25 ( V_5 , V_19 -> V_432 , V_437 ) ;
V_19 -> V_406 &= ~ V_438 ;
F_25 ( V_5 , V_19 -> V_406 , V_408 ) ;
F_25 ( V_5 , V_19 -> V_428 , V_431 ) ;
V_19 -> V_439 &= ~ V_440 ;
F_25 ( V_5 , V_19 -> V_439 , V_441 ) ;
if ( V_145 -> V_160 == V_306 )
F_28 ( V_5 , 0xffffff , V_442 ) ;
else
F_28 ( V_5 , 0 , V_442 ) ;
F_25 ( V_5 , V_443 , V_417 ) ;
V_19 -> V_439 &= ~ V_444 ;
F_25 ( V_5 , V_19 -> V_439 , V_441 ) ;
switch ( V_145 -> V_160 ) {
case V_161 :
if ( V_19 -> V_22 ) {
F_28 ( V_5 , V_145 -> V_314 - 1 ,
V_445 ) ;
F_25 ( V_5 , V_446 ,
V_417 ) ;
} else {
F_28 ( V_5 , V_145 -> V_314 ,
V_445 ) ;
F_25 ( V_5 , V_446 ,
V_417 ) ;
F_28 ( V_5 , V_145 -> V_314 - 1 ,
V_445 ) ;
}
break;
case V_306 :
F_28 ( V_5 , 0xffffff , V_445 ) ;
F_25 ( V_5 , V_446 , V_417 ) ;
F_28 ( V_5 , 0xffffff , V_445 ) ;
break;
default:
F_28 ( V_5 , 0 , V_445 ) ;
F_25 ( V_5 , V_446 , V_417 ) ;
F_28 ( V_5 , V_145 -> V_314 , V_445 ) ;
}
V_19 -> V_428 &= ~ ( V_447 |
V_448 |
V_449 |
V_450 ) ;
switch ( V_145 -> V_302 ) {
case V_303 :
V_19 -> V_419 &= ~ V_451 ;
V_421 =
F_129 ( V_5 , V_145 -> V_310 ,
V_288 ) ;
F_28 ( V_5 , 1 , V_452 ) ;
F_25 ( V_5 , V_453 , V_417 ) ;
F_28 ( V_5 , V_421 , V_452 ) ;
break;
case V_301 :
V_19 -> V_428 |=
F_168 ( V_145 -> V_310 ) ;
if ( V_145 -> V_310 & V_308 )
V_19 -> V_428 |= V_449 ;
V_19 -> V_419 |= V_451 ;
break;
default:
F_2 () ;
break;
}
F_25 ( V_5 , V_19 -> V_419 , V_420 ) ;
F_25 ( V_5 , V_19 -> V_428 , V_431 ) ;
V_19 -> V_439 &= ~ ( F_169 ( 3 ) |
V_454 ) ;
F_25 ( V_5 , V_19 -> V_439 , V_441 ) ;
if ( V_145 -> V_312 > 1 ) {
V_19 -> V_428 |= V_455 ;
F_25 ( V_5 ,
F_170 ( V_145 -> V_312 - 1 ) |
V_456 ,
V_457 ) ;
} else {
unsigned V_42 ;
V_19 -> V_428 &= ~ V_455 ;
V_42 = V_456 ;
if ( V_19 -> V_22 || V_19 -> V_98 ) {
V_42 |= F_170 ( 0 ) ;
} else {
V_42 |=
F_170 ( F_116 ( V_145 -> V_327 [ 0 ] ) ) ;
}
F_25 ( V_5 , V_42 , V_457 ) ;
}
F_25 ( V_5 , V_19 -> V_428 , V_431 ) ;
F_25 ( V_5 , V_414 |
V_415 ,
V_417 ) ;
V_19 -> V_406 |= V_458 ;
F_25 ( V_5 , V_19 -> V_406 , V_408 ) ;
V_19 -> V_439 &= ~ V_459 ;
#ifdef F_55
V_19 -> V_439 |= V_460 ;
#else
V_19 -> V_439 |= V_461 ;
#endif
V_19 -> V_439 &= ~ V_462 ;
F_25 ( V_5 , V_19 -> V_439 , V_441 ) ;
V_42 = V_463 |
V_464 |
V_465 ;
if ( V_103 -> V_110 )
V_42 |= V_466 ;
else
V_42 |= V_467 ;
#if 0
if (devpriv->is_m_series)
bits |= NISTC_AO_PERSONAL_NUM_DAC;
#endif
F_25 ( V_5 , V_42 , V_468 ) ;
F_25 ( V_5 , V_469 , V_470 ) ;
F_25 ( V_5 , V_471 , V_202 ) ;
if ( V_145 -> V_160 == V_161 ) {
F_25 ( V_5 , V_164 ,
V_177 ) ;
F_68 ( V_5 , V_33 ,
V_472 , 1 ) ;
}
V_84 -> V_107 -> V_319 = F_165 ;
return 0 ;
}
static int F_171 ( struct V_4 * V_5 , struct V_83 * V_84 ,
struct V_144 * V_145 )
{
const struct V_102 * V_103 = V_5 -> V_104 ;
struct V_18 * V_19 = V_5 -> V_20 ;
int V_295 = 0 ;
unsigned int V_296 ;
V_295 |= F_133 ( & V_145 -> V_298 , V_300 | V_301 ) ;
V_295 |= F_133 ( & V_145 -> V_302 ,
V_303 | V_301 ) ;
V_295 |= F_133 ( & V_145 -> V_304 , V_299 ) ;
V_295 |= F_133 ( & V_145 -> V_305 , V_161 ) ;
V_295 |= F_133 ( & V_145 -> V_160 , V_161 | V_306 ) ;
if ( V_295 )
return 1 ;
V_295 |= F_134 ( V_145 -> V_298 ) ;
V_295 |= F_134 ( V_145 -> V_302 ) ;
V_295 |= F_134 ( V_145 -> V_160 ) ;
if ( V_295 )
return 2 ;
switch ( V_145 -> V_298 ) {
case V_300 :
V_295 |= F_135 ( & V_145 -> V_307 , 0 ) ;
break;
case V_301 :
V_296 = F_116 ( V_145 -> V_307 ) ;
if ( V_296 > 18 )
V_296 = 18 ;
V_296 |= ( V_145 -> V_307 & ( V_308 | V_309 ) ) ;
V_295 |= F_135 ( & V_145 -> V_307 , V_296 ) ;
break;
}
if ( V_145 -> V_302 == V_303 ) {
V_295 |= F_136 ( & V_145 -> V_310 ,
V_103 -> V_473 ) ;
V_295 |= F_137 ( & V_145 -> V_310 ,
V_19 -> V_289 *
0xffffff ) ;
}
V_295 |= F_135 ( & V_145 -> V_311 , 0 ) ;
V_295 |= F_135 ( & V_145 -> V_312 ,
V_145 -> V_193 ) ;
if ( V_145 -> V_160 == V_161 )
V_295 |= F_137 ( & V_145 -> V_314 , 0x00ffffff ) ;
else
V_295 |= F_135 ( & V_145 -> V_314 , 0 ) ;
if ( V_295 )
return 3 ;
if ( V_145 -> V_302 == V_303 ) {
V_296 = V_145 -> V_310 ;
V_145 -> V_310 =
F_130 ( V_5 , F_129 ( V_5 ,
V_145 -> V_310 ,
V_145 -> V_21 ) ) ;
if ( V_296 != V_145 -> V_310 )
V_295 ++ ;
}
if ( V_295 )
return 4 ;
return 0 ;
}
static int F_172 ( struct V_4 * V_5 , struct V_83 * V_84 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
F_58 ( V_5 ) ;
F_25 ( V_5 , V_422 , V_202 ) ;
F_25 ( V_5 , V_423 , V_417 ) ;
F_68 ( V_5 , V_33 , ~ 0 , 0 ) ;
F_25 ( V_5 , V_463 , V_468 ) ;
F_25 ( V_5 , V_474 , V_177 ) ;
F_25 ( V_5 , V_463 |
V_464 |
V_465 ,
V_468 ) ;
F_25 ( V_5 , 0 , V_457 ) ;
F_25 ( V_5 , 0 , V_470 ) ;
V_19 -> V_416 = 0 ;
F_25 ( V_5 , V_19 -> V_416 , V_417 ) ;
V_19 -> V_419 = 0 ;
F_25 ( V_5 , V_19 -> V_419 , V_420 ) ;
V_19 -> V_428 = 0 ;
F_25 ( V_5 , V_19 -> V_428 , V_431 ) ;
V_19 -> V_439 = 0 ;
F_25 ( V_5 , V_19 -> V_439 , V_441 ) ;
if ( V_19 -> V_22 )
V_19 -> V_406 = V_475 ;
else
V_19 -> V_406 = 0 ;
F_25 ( V_5 , V_19 -> V_406 , V_408 ) ;
V_19 -> V_432 = 0 ;
F_25 ( V_5 , V_19 -> V_432 ,
V_437 ) ;
if ( V_19 -> V_98 ) {
unsigned V_476 = 0 ;
unsigned V_73 ;
for ( V_73 = 0 ; V_73 < V_84 -> V_229 ; ++ V_73 )
V_476 |= 1 << V_73 ;
F_65 ( V_5 , V_476 , V_401 ) ;
F_65 ( V_5 , V_424 ,
V_425 ) ;
}
F_25 ( V_5 , V_471 , V_202 ) ;
return 0 ;
}
static int F_173 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_277 * V_278 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
int V_181 ;
V_181 = F_174 ( V_5 , V_84 , V_278 , V_6 , 0 ) ;
if ( V_181 )
return V_181 ;
V_19 -> V_477 &= ~ V_478 ;
V_19 -> V_477 |= F_175 ( V_84 -> V_479 ) ;
F_25 ( V_5 , V_19 -> V_477 , V_480 ) ;
return V_278 -> V_95 ;
}
static int F_176 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_277 * V_278 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
if ( ( V_6 [ 0 ] & ( V_481 | V_482 ) ) &&
V_19 -> V_483 )
return - V_53 ;
if ( F_177 ( V_84 , V_6 ) ) {
V_19 -> V_484 &= ~ V_485 ;
V_19 -> V_484 |= F_178 ( V_84 -> V_486 ) ;
F_25 ( V_5 , V_19 -> V_484 , V_487 ) ;
}
V_6 [ 1 ] = F_29 ( V_5 , V_488 ) ;
return V_278 -> V_95 ;
}
static int F_179 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_277 * V_278 ,
unsigned int * V_6 )
{
int V_181 ;
V_181 = F_174 ( V_5 , V_84 , V_278 , V_6 , 0 ) ;
if ( V_181 )
return V_181 ;
F_3 ( V_5 , V_84 -> V_479 , V_489 ) ;
return V_278 -> V_95 ;
}
static int F_180 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_277 * V_278 ,
unsigned int * V_6 )
{
if ( F_177 ( V_84 , V_6 ) )
F_3 ( V_5 , V_84 -> V_486 , V_490 ) ;
V_6 [ 1 ] = F_12 ( V_5 , V_490 ) ;
return V_278 -> V_95 ;
}
static int F_181 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_144 * V_145 )
{
int V_73 ;
for ( V_73 = 0 ; V_73 < V_145 -> V_193 ; ++ V_73 ) {
unsigned int V_231 = F_116 ( V_145 -> V_327 [ V_73 ] ) ;
if ( V_231 != V_73 )
return - V_316 ;
}
return 0 ;
}
static int F_182 ( struct V_4 * V_5 ,
struct V_83 * V_84 , struct V_144 * V_145 )
{
int V_295 = 0 ;
int V_296 ;
V_295 |= F_133 ( & V_145 -> V_298 , V_300 ) ;
V_295 |= F_133 ( & V_145 -> V_302 , V_301 ) ;
V_295 |= F_133 ( & V_145 -> V_304 , V_299 ) ;
V_295 |= F_133 ( & V_145 -> V_305 , V_161 ) ;
V_295 |= F_133 ( & V_145 -> V_160 , V_306 ) ;
if ( V_295 )
return 1 ;
V_295 |= F_135 ( & V_145 -> V_307 , 0 ) ;
V_296 = V_145 -> V_310 ;
V_296 &= F_183 ( V_491 , 0 , 0 , V_308 ) ;
if ( V_296 != V_145 -> V_310 )
V_295 |= - V_316 ;
V_295 |= F_135 ( & V_145 -> V_311 , 0 ) ;
V_295 |= F_135 ( & V_145 -> V_312 ,
V_145 -> V_193 ) ;
V_295 |= F_135 ( & V_145 -> V_314 , 0 ) ;
if ( V_295 )
return 3 ;
if ( V_145 -> V_327 && V_145 -> V_193 > 0 )
V_295 |= F_181 ( V_5 , V_84 , V_145 ) ;
if ( V_295 )
return 5 ;
return 0 ;
}
static int F_184 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
unsigned int V_315 )
{
struct V_144 * V_145 = & V_84 -> V_107 -> V_145 ;
const unsigned V_72 = 1000 ;
int V_86 = 0 ;
unsigned V_73 ;
#ifdef F_55
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned long V_21 ;
#endif
if ( V_315 != V_145 -> V_307 )
return - V_316 ;
V_84 -> V_107 -> V_319 = NULL ;
F_106 ( V_84 , V_84 -> V_107 -> V_194 ) ;
#ifdef F_55
F_26 ( & V_19 -> V_50 , V_21 ) ;
if ( V_19 -> V_65 ) {
F_103 ( V_19 -> V_65 , 32 , 32 ) ;
F_104 ( V_19 -> V_65 ) ;
} else {
F_32 ( V_5 -> V_13 , L_25 ) ;
V_86 = - V_195 ;
}
F_27 ( & V_19 -> V_50 , V_21 ) ;
if ( V_86 < 0 )
return V_86 ;
#endif
for ( V_73 = 0 ; V_73 < V_72 ; ++ V_73 ) {
if ( F_12 ( V_5 , V_492 ) &
V_493 )
break;
F_63 ( 10 ) ;
}
if ( V_73 == V_72 ) {
F_32 ( V_5 -> V_13 , L_26 ) ;
V_84 -> V_494 ( V_5 , V_84 ) ;
return - V_195 ;
}
F_3 ( V_5 , V_495 |
V_496 |
V_497 ,
V_498 ) ;
return V_86 ;
}
static int F_185 ( struct V_4 * V_5 , struct V_83 * V_84 )
{
const struct V_144 * V_145 = & V_84 -> V_107 -> V_145 ;
unsigned V_499 ;
int V_86 ;
F_3 ( V_5 , V_500 , V_498 ) ;
V_499 = V_501 |
V_502 |
F_186 ( F_116 ( V_145 -> V_310 ) ) ;
if ( V_145 -> V_310 & V_308 )
V_499 |= V_503 ;
F_3 ( V_5 , V_499 , V_504 ) ;
if ( V_84 -> V_479 ) {
F_3 ( V_5 , V_84 -> V_486 , V_505 ) ;
F_3 ( V_5 , V_506 , V_498 ) ;
F_3 ( V_5 , V_84 -> V_479 , V_507 ) ;
} else {
F_32 ( V_5 -> V_13 ,
L_27 ) ;
return - V_195 ;
}
V_86 = F_54 ( V_5 ) ;
if ( V_86 < 0 )
return V_86 ;
V_84 -> V_107 -> V_319 = F_184 ;
return 0 ;
}
static int F_187 ( struct V_4 * V_5 , struct V_83 * V_84 )
{
F_3 ( V_5 , V_508 |
V_509 |
V_510 |
V_511 ,
V_498 ) ;
F_3 ( V_5 , 0 , V_507 ) ;
F_60 ( V_5 ) ;
return 0 ;
}
static void F_188 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned V_512 ;
struct V_83 * V_84 = & V_5 -> V_130 [ V_513 ] ;
#ifdef F_55
unsigned long V_21 ;
#endif
if ( ! V_19 -> V_22 )
return;
#ifdef F_55
F_26 ( & V_19 -> V_50 , V_21 ) ;
if ( V_19 -> V_65 ) {
unsigned V_514 =
F_189 ( V_19 -> V_65 ) ;
if ( V_514 & V_147 ) {
F_4 ( V_515 ,
V_19 -> V_24 -> V_516 +
F_190 ( V_19 -> V_65 -> V_41 ) ) ;
}
F_74 ( V_19 -> V_65 , V_84 ) ;
}
F_27 ( & V_19 -> V_50 , V_21 ) ;
#endif
V_512 = F_12 ( V_5 , V_492 ) ;
if ( V_512 & V_517 ) {
F_3 ( V_5 , V_518 ,
V_498 ) ;
V_84 -> V_107 -> V_108 |= V_109 ;
}
if ( V_512 & V_519 ) {
F_3 ( V_5 , V_510 ,
V_498 ) ;
}
F_92 ( V_5 , V_84 ) ;
}
static int F_191 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
unsigned char V_520 ,
unsigned char * V_521 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_522 ;
int V_295 = 0 , V_225 = 20 ;
V_19 -> V_484 &= ~ V_523 ;
V_19 -> V_484 |= F_192 ( V_520 ) ;
F_25 ( V_5 , V_19 -> V_484 , V_487 ) ;
V_522 = F_29 ( V_5 , V_524 ) ;
if ( V_522 & V_525 ) {
V_295 = - V_53 ;
goto Error;
}
V_19 -> V_477 |= V_526 ;
F_25 ( V_5 , V_19 -> V_477 , V_480 ) ;
V_19 -> V_477 &= ~ V_526 ;
while ( ( V_522 = F_29 ( V_5 , V_524 ) ) &
V_525 ) {
F_63 ( ( V_19 -> V_483 + 999 ) / 1000 ) ;
if ( -- V_225 < 0 ) {
F_32 ( V_5 -> V_13 ,
L_28 ) ;
V_295 = - V_283 ;
goto Error;
}
}
F_63 ( ( V_19 -> V_483 + 999 ) / 1000 ) ;
if ( V_521 )
* V_521 = F_29 ( V_5 , V_527 ) ;
Error:
F_25 ( V_5 , V_19 -> V_477 , V_480 ) ;
return V_295 ;
}
static int F_193 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
unsigned char V_520 ,
unsigned char * V_521 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned char V_279 , V_528 = 0 ;
F_63 ( ( V_19 -> V_483 + 999 ) / 1000 ) ;
for ( V_279 = 0x80 ; V_279 ; V_279 >>= 1 ) {
V_19 -> V_484 &= ~ V_482 ;
if ( V_520 & V_279 )
V_19 -> V_484 |= V_482 ;
F_25 ( V_5 , V_19 -> V_484 , V_487 ) ;
V_19 -> V_477 |= V_529 ;
F_25 ( V_5 , V_19 -> V_477 , V_480 ) ;
F_63 ( ( V_19 -> V_483 + 999 ) / 2000 ) ;
V_19 -> V_477 &= ~ V_529 ;
F_25 ( V_5 , V_19 -> V_477 , V_480 ) ;
F_63 ( ( V_19 -> V_483 + 999 ) / 2000 ) ;
if ( F_29 ( V_5 , V_488 ) & V_481 )
V_528 |= V_279 ;
}
if ( V_521 )
* V_521 = V_528 ;
return 0 ;
}
static int F_194 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_277 * V_278 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned V_530 = V_19 -> V_531 ;
int V_295 = V_278 -> V_95 ;
unsigned char V_532 , V_533 = 0 ;
if ( V_278 -> V_95 != 2 )
return - V_316 ;
switch ( V_6 [ 0 ] ) {
case V_534 :
V_19 -> V_535 = 1 ;
V_19 -> V_477 |= V_536 ;
if ( V_6 [ 1 ] == V_537 ) {
V_19 -> V_535 = 0 ;
V_19 -> V_477 &= ~ ( V_536 |
V_529 ) ;
V_6 [ 1 ] = V_537 ;
V_19 -> V_483 = V_6 [ 1 ] ;
} else if ( V_6 [ 1 ] <= V_538 ) {
V_19 -> V_477 &= ~ V_539 ;
V_530 |= V_540 ;
V_530 &= ~ V_541 ;
V_6 [ 1 ] = V_538 ;
V_19 -> V_483 = V_6 [ 1 ] ;
} else if ( V_6 [ 1 ] <= V_542 ) {
V_19 -> V_477 &= ~ V_539 ;
V_530 |= V_540 |
V_541 ;
V_6 [ 1 ] = V_542 ;
V_19 -> V_483 = V_6 [ 1 ] ;
} else if ( V_6 [ 1 ] <= V_543 ) {
V_19 -> V_477 |= V_539 ;
V_530 |= V_540 |
V_541 ;
V_6 [ 1 ] = V_543 ;
V_19 -> V_483 = V_6 [ 1 ] ;
} else {
V_19 -> V_477 &= ~ ( V_536 |
V_529 ) ;
V_19 -> V_535 = 0 ;
V_6 [ 1 ] = ( V_6 [ 1 ] / 1000 ) * 1000 ;
V_19 -> V_483 = V_6 [ 1 ] ;
}
V_19 -> V_531 = V_530 ;
F_25 ( V_5 , V_19 -> V_477 , V_480 ) ;
F_25 ( V_5 , V_19 -> V_531 , V_544 ) ;
return 1 ;
case V_545 :
if ( V_19 -> V_483 == 0 )
return - V_316 ;
V_532 = V_6 [ 1 ] & 0xFF ;
if ( V_19 -> V_535 ) {
V_295 = F_191 ( V_5 , V_84 , V_532 ,
& V_533 ) ;
} else if ( V_19 -> V_483 > 0 ) {
V_295 = F_193 ( V_5 , V_84 , V_532 ,
& V_533 ) ;
} else {
F_32 ( V_5 -> V_13 , L_29 ) ;
return - V_316 ;
}
if ( V_295 < 0 )
return V_295 ;
V_6 [ 1 ] = V_533 & 0xFF ;
return V_278 -> V_95 ;
break;
default:
return - V_316 ;
}
}
static void F_195 ( struct V_4 * V_5 , struct V_83 * V_84 )
{
int V_73 ;
for ( V_73 = 0 ; V_73 < V_84 -> V_229 ; V_73 ++ ) {
F_65 ( V_5 , F_156 ( V_73 ) | 0x0 ,
V_546 ) ;
}
F_65 ( V_5 , 0x0 , V_547 ) ;
}
static unsigned int F_196 ( struct V_4 * V_5 ,
enum V_548 V_7 )
{
const struct V_10 * V_11 ;
if ( V_7 < F_22 ( V_549 ) ) {
V_11 = & V_549 [ V_7 ] ;
} else {
F_23 ( V_5 -> V_13 , L_1 ,
V_14 , V_7 ) ;
return 0 ;
}
return V_11 -> V_16 ;
}
static void F_197 ( struct V_550 * V_551 , unsigned V_42 ,
enum V_548 V_7 )
{
struct V_4 * V_5 = V_551 -> V_62 -> V_5 ;
unsigned int V_552 = F_196 ( V_5 , V_7 ) ;
static const unsigned V_553 =
V_69 | V_554 ;
static const unsigned V_555 =
V_71 | V_556 ;
if ( V_552 == 0 )
return;
switch ( V_7 ) {
case V_557 :
case V_558 :
case V_559 :
case V_560 :
case V_561 :
case V_562 :
case V_563 :
case V_564 :
F_6 ( V_5 , V_42 , V_552 ) ;
break;
case V_565 :
case V_566 :
case V_567 :
case V_568 :
F_28 ( V_5 , V_42 , V_552 ) ;
break;
case V_569 :
F_49 ( V_42 & ~ V_553 ) ;
F_31 ( V_5 , V_552 ,
V_553 , V_42 ) ;
break;
case V_570 :
F_49 ( V_42 & ~ V_555 ) ;
F_31 ( V_5 , V_552 ,
V_555 , V_42 ) ;
break;
case V_571 :
F_49 ( V_42 & ~ ( V_572 | V_573 ) ) ;
default:
F_25 ( V_5 , V_42 , V_552 ) ;
}
}
static unsigned F_198 ( struct V_550 * V_551 ,
enum V_548 V_7 )
{
struct V_4 * V_5 = V_551 -> V_62 -> V_5 ;
unsigned int V_552 = F_196 ( V_5 , V_7 ) ;
if ( V_552 == 0 )
return 0 ;
switch ( V_7 ) {
case V_574 :
case V_575 :
return F_15 ( V_5 , V_552 ) ;
case V_576 :
case V_577 :
case V_578 :
case V_579 :
return F_30 ( V_5 , V_552 ) ;
default:
return F_29 ( V_5 , V_552 ) ;
}
}
static int F_199 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_277 * V_278 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_27 = F_200 ( V_19 -> V_531 ) ;
int V_73 ;
for ( V_73 = 0 ; V_73 < V_278 -> V_95 ; V_73 ++ )
V_6 [ V_73 ] = V_27 ;
return V_278 -> V_95 ;
}
static int F_201 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_277 * V_278 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
if ( V_278 -> V_95 ) {
unsigned int V_27 = V_6 [ V_278 -> V_95 - 1 ] ;
V_19 -> V_531 &= ~ V_580 ;
F_25 ( V_5 , V_19 -> V_531 , V_544 ) ;
V_19 -> V_531 &= ~ V_581 ;
V_19 -> V_531 |= F_202 ( V_27 ) ;
V_19 -> V_531 |= V_580 ;
F_25 ( V_5 , V_19 -> V_531 , V_544 ) ;
}
return V_278 -> V_95 ;
}
static int F_203 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_277 * V_278 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
switch ( V_6 [ 0 ] ) {
case V_582 :
switch ( V_6 [ 1 ] ) {
case V_583 :
V_19 -> V_531 &= ~ V_584 ;
break;
case V_585 :
V_19 -> V_531 |= V_584 ;
break;
default:
return - V_316 ;
}
F_25 ( V_5 , V_19 -> V_531 , V_544 ) ;
break;
case V_586 :
if ( V_19 -> V_531 & V_584 ) {
V_6 [ 1 ] = V_585 ;
V_6 [ 2 ] = V_587 ;
} else {
V_6 [ 1 ] = V_583 ;
V_6 [ 2 ] = V_588 * 2 ;
}
break;
default:
return - V_316 ;
}
return V_278 -> V_95 ;
}
static int F_204 ( struct V_4 * V_5 ,
int V_54 , int V_589 , int V_6 , unsigned long V_9 )
{
if ( V_54 ) {
F_9 ( V_5 , V_6 , V_9 + 2 * V_589 ) ;
return 0 ;
}
return F_18 ( V_5 , V_9 + 2 * V_589 ) ;
}
static int F_205 ( struct V_4 * V_5 , unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
V_6 [ 1 ] = V_19 -> V_590 * V_19 -> V_289 ;
V_6 [ 2 ] = V_19 -> V_591 * V_19 -> V_289 ;
return 3 ;
}
static int F_206 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_277 * V_278 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned V_592 , V_593 ;
switch ( V_6 [ 0 ] ) {
case V_594 :
switch ( V_6 [ 1 ] ) {
case V_288 :
V_592 =
( V_6 [ 2 ] +
V_19 -> V_289 / 2 ) / V_19 -> V_289 ;
break;
case V_290 :
V_592 = V_6 [ 2 ] / V_19 -> V_289 ;
break;
case V_291 :
V_592 =
( V_6 [ 2 ] + V_19 -> V_289 -
1 ) / V_19 -> V_289 ;
break;
default:
return - V_316 ;
}
switch ( V_6 [ 3 ] ) {
case V_288 :
V_593 =
( V_6 [ 4 ] +
V_19 -> V_289 / 2 ) / V_19 -> V_289 ;
break;
case V_290 :
V_593 = V_6 [ 4 ] / V_19 -> V_289 ;
break;
case V_291 :
V_593 =
( V_6 [ 4 ] + V_19 -> V_289 -
1 ) / V_19 -> V_289 ;
break;
default:
return - V_316 ;
}
if ( V_592 * V_19 -> V_289 != V_6 [ 2 ] ||
V_593 * V_19 -> V_289 != V_6 [ 4 ] ) {
V_6 [ 2 ] = V_592 * V_19 -> V_289 ;
V_6 [ 4 ] = V_593 * V_19 -> V_289 ;
return - V_595 ;
}
F_3 ( V_5 , F_207 ( V_592 ) |
F_208 ( V_593 ) ,
V_596 ) ;
V_19 -> V_590 = V_592 ;
V_19 -> V_591 = V_593 ;
return 5 ;
case V_597 :
return F_205 ( V_5 , V_6 ) ;
default:
return - V_316 ;
}
return 0 ;
}
static int F_209 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_277 * V_278 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned V_592 , V_593 ;
switch ( V_6 [ 0 ] ) {
case V_594 :
switch ( V_6 [ 1 ] ) {
case V_288 :
V_592 =
( V_6 [ 2 ] +
V_19 -> V_289 / 2 ) / V_19 -> V_289 ;
break;
case V_290 :
V_592 = V_6 [ 2 ] / V_19 -> V_289 ;
break;
case V_291 :
V_592 =
( V_6 [ 2 ] + V_19 -> V_289 -
1 ) / V_19 -> V_289 ;
break;
default:
return - V_316 ;
}
switch ( V_6 [ 3 ] ) {
case V_288 :
V_593 =
( V_6 [ 4 ] +
V_19 -> V_289 / 2 ) / V_19 -> V_289 ;
break;
case V_290 :
V_593 = V_6 [ 4 ] / V_19 -> V_289 ;
break;
case V_291 :
V_593 =
( V_6 [ 4 ] + V_19 -> V_289 -
1 ) / V_19 -> V_289 ;
break;
default:
return - V_316 ;
}
if ( V_592 * V_19 -> V_289 != V_6 [ 2 ] ||
V_593 * V_19 -> V_289 != V_6 [ 4 ] ) {
V_6 [ 2 ] = V_592 * V_19 -> V_289 ;
V_6 [ 4 ] = V_593 * V_19 -> V_289 ;
return - V_595 ;
}
F_3 ( V_5 , V_592 , V_598 ) ;
V_19 -> V_590 = V_592 ;
F_3 ( V_5 , V_593 , V_599 ) ;
V_19 -> V_591 = V_593 ;
return 5 ;
case V_597 :
return F_205 ( V_5 , V_6 ) ;
default:
return - V_316 ;
}
return 0 ;
}
static int F_210 ( int V_79 , int V_27 , int * V_600 )
{
V_79 ++ ;
* V_600 = ( ( V_79 & 0x1 ) << 11 ) |
( ( V_79 & 0x2 ) << 9 ) |
( ( V_79 & 0x4 ) << 7 ) | ( ( V_79 & 0x8 ) << 5 ) | ( V_27 & 0xff ) ;
return 12 ;
}
static int F_211 ( int V_79 , int V_27 , int * V_600 )
{
* V_600 = ( ( V_79 & 0x7 ) << 8 ) | ( V_27 & 0xff ) ;
return 11 ;
}
static int F_212 ( int V_79 , int V_27 , int * V_600 )
{
* V_600 = V_27 & 0xfff ;
return 12 ;
}
static int F_213 ( int V_79 , int V_27 , int * V_600 )
{
* V_600 = ( V_27 & 0xfff ) | ( V_79 ? 0xc000 : 0xa000 ) ;
return 16 ;
}
static int F_214 ( int V_79 , int V_27 , int * V_600 )
{
* V_600 = ( ( V_79 & 0xf ) << 8 ) | ( V_27 & 0xff ) ;
return 12 ;
}
static int F_215 ( int V_79 , int V_27 , int * V_600 )
{
* V_600 = ( ( V_79 + 1 ) << 8 ) | ( V_27 & 0xff ) ;
return 12 ;
}
static void F_216 ( struct V_4 * V_5 , int V_79 , int V_27 )
{
const struct V_102 * V_103 = V_5 -> V_104 ;
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_601 = 0 , V_42 = 0 , V_602 , V_600 = 0 ;
unsigned int V_145 ;
int V_73 ;
int type ;
if ( V_19 -> V_603 [ V_79 ] == V_27 )
return;
V_19 -> V_603 [ V_79 ] = V_27 ;
for ( V_73 = 0 ; V_73 < 3 ; V_73 ++ ) {
type = V_103 -> V_604 [ V_73 ] ;
if ( type == V_605 )
break;
if ( V_79 < V_603 [ type ] . V_379 ) {
V_42 = V_603 [ type ] . F_217 ( V_79 , V_27 , & V_600 ) ;
V_601 = F_218 ( V_73 ) ;
break;
}
V_79 -= V_603 [ type ] . V_379 ;
}
if ( V_42 == 0 )
return;
for ( V_602 = 1 << ( V_42 - 1 ) ; V_602 ; V_602 >>= 1 ) {
V_145 = ( V_602 & V_600 ) ? V_606 : 0 ;
F_9 ( V_5 , V_145 , V_607 ) ;
F_63 ( 1 ) ;
F_9 ( V_5 , V_608 | V_145 , V_607 ) ;
F_63 ( 1 ) ;
}
F_9 ( V_5 , V_601 , V_607 ) ;
F_63 ( 1 ) ;
F_9 ( V_5 , 0 , V_607 ) ;
}
static int F_219 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_277 * V_278 ,
unsigned int * V_6 )
{
F_216 ( V_5 , F_116 ( V_278 -> V_281 ) , V_6 [ 0 ] ) ;
return 1 ;
}
static int F_220 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_277 * V_278 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
V_6 [ 0 ] = V_19 -> V_603 [ F_116 ( V_278 -> V_281 ) ] ;
return 1 ;
}
static void F_221 ( struct V_4 * V_5 , struct V_83 * V_84 )
{
const struct V_102 * V_103 = V_5 -> V_104 ;
struct V_18 * V_19 = V_5 -> V_20 ;
int V_73 , V_609 ;
int V_610 ;
int V_379 = 0 ;
int V_611 ;
int V_612 = 0 ;
int type ;
int V_231 ;
type = V_103 -> V_604 [ 0 ] ;
if ( type == V_605 )
return;
V_611 = V_603 [ type ] . V_611 ;
for ( V_73 = 0 ; V_73 < 3 ; V_73 ++ ) {
type = V_103 -> V_604 [ V_73 ] ;
if ( type == V_605 )
break;
if ( V_603 [ type ] . V_611 != V_611 )
V_612 = 1 ;
V_379 += V_603 [ type ] . V_379 ;
}
V_610 = V_73 ;
V_84 -> V_229 = V_379 ;
if ( V_612 ) {
unsigned int * V_613 ;
if ( V_379 > V_614 )
F_32 ( V_5 -> V_13 ,
L_30 ) ;
V_84 -> V_613 = V_613 = V_19 -> V_615 ;
V_231 = 0 ;
for ( V_73 = 0 ; V_73 < V_610 ; V_73 ++ ) {
type = V_103 -> V_604 [ V_73 ] ;
for ( V_609 = 0 ; V_609 < V_603 [ type ] . V_379 ; V_609 ++ ) {
V_613 [ V_231 ] =
( 1 << V_603 [ type ] . V_611 ) - 1 ;
V_231 ++ ;
}
}
for ( V_231 = 0 ; V_231 < V_84 -> V_229 ; V_231 ++ )
F_216 ( V_5 , V_73 , V_84 -> V_613 [ V_73 ] / 2 ) ;
} else {
type = V_103 -> V_604 [ 0 ] ;
V_84 -> V_260 = ( 1 << V_603 [ type ] . V_611 ) - 1 ;
for ( V_231 = 0 ; V_231 < V_84 -> V_229 ; V_231 ++ )
F_216 ( V_5 , V_73 , V_84 -> V_260 / 2 ) ;
}
}
static int F_222 ( struct V_4 * V_5 , int V_79 )
{
unsigned int V_145 = V_616 ;
int V_602 ;
int V_600 ;
V_600 = 0x0300 | ( ( V_79 & 0x100 ) << 3 ) | ( V_79 & 0xff ) ;
F_9 ( V_5 , V_145 , V_607 ) ;
for ( V_602 = 0x8000 ; V_602 ; V_602 >>= 1 ) {
if ( V_602 & V_600 )
V_145 |= V_606 ;
else
V_145 &= ~ V_606 ;
F_9 ( V_5 , V_145 , V_607 ) ;
F_9 ( V_5 , V_608 | V_145 , V_607 ) ;
}
V_145 = V_616 ;
V_600 = 0 ;
for ( V_602 = 0x80 ; V_602 ; V_602 >>= 1 ) {
F_9 ( V_5 , V_145 , V_607 ) ;
F_9 ( V_5 , V_608 | V_145 , V_607 ) ;
if ( F_18 ( V_5 , V_123 ) & V_617 )
V_600 |= V_602 ;
}
F_9 ( V_5 , 0 , V_607 ) ;
return V_600 ;
}
static int F_223 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_277 * V_278 ,
unsigned int * V_6 )
{
V_6 [ 0 ] = F_222 ( V_5 , F_116 ( V_278 -> V_281 ) ) ;
return 1 ;
}
static int F_224 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_277 * V_278 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
V_6 [ 0 ] = V_19 -> V_618 [ F_116 ( V_278 -> V_281 ) ] ;
return 1 ;
}
static unsigned F_225 ( struct V_4 * V_5 ,
unsigned V_231 )
{
switch ( V_231 ) {
case 0 :
return V_619 ;
case 1 :
return V_620 ;
case 2 :
return V_621 ;
case 3 :
return V_622 ;
case 4 :
return V_623 ;
case 5 :
return V_624 ;
case 6 :
return V_625 ;
case 7 :
return V_626 ;
case 8 :
return V_627 ;
case 9 :
return V_628 ;
default:
F_32 ( V_5 -> V_13 , L_31 ) ;
break;
}
return 0 ;
}
static int F_226 ( struct V_4 * V_5 ,
unsigned V_231 , unsigned V_629 )
{
if ( V_629 != F_225 ( V_5 , V_231 ) )
return - V_316 ;
return 2 ;
}
static unsigned F_227 ( struct V_4 * V_5 ,
unsigned V_231 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
const unsigned V_630 = V_231 / 3 ;
return F_228 ( V_231 ,
V_19 -> V_631 [ V_630 ] ) ;
}
static int F_229 ( struct V_4 * V_5 ,
unsigned V_231 , unsigned V_629 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned V_632 = V_231 / 3 ;
unsigned short V_27 = V_19 -> V_631 [ V_632 ] ;
if ( ( V_629 & 0x1f ) != V_629 )
return - V_316 ;
V_27 &= ~ F_230 ( V_231 ) ;
V_27 |= F_231 ( V_231 , V_629 ) ;
F_6 ( V_5 , V_27 , F_232 ( V_632 ) ) ;
V_19 -> V_631 [ V_632 ] = V_27 ;
return 2 ;
}
static unsigned F_233 ( struct V_4 * V_5 , unsigned V_231 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
return ( V_19 -> V_22 )
? F_227 ( V_5 , V_231 )
: F_225 ( V_5 , V_231 ) ;
}
static int F_234 ( struct V_4 * V_5 , unsigned V_231 ,
unsigned V_629 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
return ( V_19 -> V_22 )
? F_229 ( V_5 , V_231 , V_629 )
: F_226 ( V_5 , V_231 , V_629 ) ;
}
static int F_235 ( struct V_4 * V_5 ,
unsigned V_633 ,
enum V_634 V_635 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned V_42 ;
if ( ! V_19 -> V_22 )
return - V_636 ;
V_42 = F_12 ( V_5 , V_637 ) ;
V_42 &= ~ F_236 ( V_633 ) ;
V_42 |= F_237 ( V_633 , V_635 ) ;
F_3 ( V_5 , V_42 , V_637 ) ;
return 0 ;
}
static int F_238 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_277 * V_278 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_231 ;
if ( V_278 -> V_95 < 1 )
return - V_316 ;
V_231 = F_116 ( V_278 -> V_281 ) ;
switch ( V_6 [ 0 ] ) {
case V_58 :
F_68 ( V_5 , V_35 , 1 << V_231 , 1 ) ;
break;
case V_55 :
F_68 ( V_5 , V_35 , 1 << V_231 , 0 ) ;
break;
case V_638 :
V_6 [ 1 ] =
( V_19 -> V_36 & ( 1 << V_231 ) ) ?
V_58 : V_55 ;
return 0 ;
case V_639 :
return F_234 ( V_5 , V_231 , V_6 [ 1 ] ) ;
case V_640 :
V_6 [ 1 ] = F_233 ( V_5 , V_231 ) ;
break;
case V_641 :
return F_235 ( V_5 , V_231 , V_6 [ 1 ] ) ;
default:
return - V_316 ;
}
return 0 ;
}
static int F_239 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_277 * V_278 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
if ( ! V_19 -> V_22 )
return - V_636 ;
if ( F_177 ( V_84 , V_6 ) )
F_6 ( V_5 , V_84 -> V_486 , V_642 ) ;
V_6 [ 1 ] = F_15 ( V_5 , V_643 ) ;
return V_278 -> V_95 ;
}
static int F_240 ( struct V_4 * V_5 )
{
unsigned short V_142 ;
const int V_72 = V_644 ;
int V_73 ;
for ( V_73 = 0 ; V_73 < V_72 ; V_73 ++ ) {
V_142 = F_67 ( V_5 , V_645 ) ;
if ( ( V_142 & V_646 ) == 0 )
break;
F_241 ( V_647 ) ;
if ( F_242 ( 1 ) )
return - V_195 ;
}
if ( V_73 == V_72 ) {
F_32 ( V_5 -> V_13 , L_20 ) ;
return - V_283 ;
}
return 0 ;
}
static void F_243 ( struct V_4 * V_5 , unsigned short V_82 )
{
static const int V_72 = 100 ;
int V_73 ;
F_65 ( V_5 , V_82 , V_648 ) ;
for ( V_73 = 0 ; V_73 < V_72 ; V_73 ++ ) {
if ( F_67 ( V_5 , V_645 ) &
V_646 )
break;
F_63 ( 1 ) ;
}
if ( V_73 == V_72 )
F_32 ( V_5 -> V_13 ,
L_32 ) ;
}
static int F_244 ( struct V_4 * V_5 ,
unsigned short * V_6 )
{
int V_86 ;
unsigned short V_142 ;
F_243 ( V_5 , V_649 | V_650 ) ;
V_86 = F_240 ( V_5 ) ;
if ( V_86 ) {
F_32 ( V_5 -> V_13 ,
L_33 ) ;
return - V_283 ;
}
V_142 = F_67 ( V_5 , V_645 ) ;
if ( V_142 & V_651 ) {
F_32 ( V_5 -> V_13 ,
L_34 ) ;
return - V_195 ;
}
if ( V_142 & V_652 ) {
F_32 ( V_5 -> V_13 ,
L_35 ) ;
}
if ( V_6 ) {
* V_6 = F_67 ( V_5 , V_653 ) ;
* V_6 ^= ( 1 << 15 ) ;
}
return 0 ;
}
static int F_245 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_277 * V_278 ,
unsigned int * V_6 )
{
int V_95 , V_86 ;
unsigned short V_654 ;
unsigned int V_655 ;
const unsigned int V_656 = 0x1000 ;
if ( V_278 -> V_281 & V_237 )
V_655 = V_656 ;
else
V_655 = F_116 ( V_278 -> V_281 ) ;
F_65 ( V_5 , V_655 , V_657 ) ;
for ( V_95 = 0 ; V_95 < V_278 -> V_95 ; V_95 ++ ) {
V_86 = F_244 ( V_5 , & V_654 ) ;
if ( V_86 < 0 )
return V_86 ;
V_6 [ V_95 ] = V_654 ;
}
return V_278 -> V_95 ;
}
static void F_246 ( struct V_4 * V_5 , unsigned int V_82 ,
unsigned int V_658 )
{
F_65 ( V_5 , ( V_82 >> 16 ) & 0xff , V_659 ) ;
F_65 ( V_5 , V_82 & 0xffff , V_660 ) ;
V_658 &= V_661 ;
F_243 ( V_5 , V_649 | V_658 ) ;
if ( F_240 ( V_5 ) )
F_32 ( V_5 -> V_13 ,
L_36 , V_14 ) ;
}
static int F_247 ( struct V_4 * V_5 )
{
unsigned int V_247 = V_662 |
V_663 ;
#if 1
F_246 ( V_5 , V_247 | V_664 ,
V_665 ) ;
F_244 ( V_5 , NULL ) ;
#else
F_246 ( V_5 , 0x400000 , V_666 ) ;
F_246 ( V_5 , V_247 | V_667 ,
V_665 ) ;
if ( F_240 ( V_5 ) )
F_32 ( V_5 -> V_13 ,
L_36 , V_14 ) ;
#endif
return 0 ;
}
static int F_248 ( unsigned V_668 ,
unsigned * V_669 ,
unsigned * V_670 ,
unsigned * V_671 )
{
unsigned div ;
unsigned V_672 = 1 ;
unsigned V_673 ;
unsigned V_674 = 1 ;
static const unsigned V_675 = 1000 ;
const unsigned V_676 = V_668 * V_675 ;
static const unsigned V_677 = 12500 ;
static const unsigned V_678 = 4 ;
int V_679 = 0 ;
for ( div = 1 ; div <= V_680 ; ++ div ) {
for ( V_673 = 1 ; V_673 <= V_681 ; ++ V_673 ) {
unsigned V_682 =
( V_676 * div ) / V_673 ;
if ( abs ( V_682 - V_677 ) <
abs ( V_679 - V_677 ) ) {
V_679 = V_682 ;
V_672 = div ;
V_674 = V_673 ;
}
}
}
if ( V_679 == 0 )
return - V_195 ;
* V_669 = V_672 ;
* V_670 = V_674 ;
* V_671 =
( V_679 * V_678 +
( V_675 / 2 ) ) / V_675 ;
return 0 ;
}
static int F_249 ( struct V_4 * V_5 ,
unsigned V_629 , unsigned V_683 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
static const unsigned V_684 = 50 ;
static const unsigned V_685 = 1000 ;
static const unsigned V_72 = 1000 ;
unsigned V_686 ;
unsigned V_669 ;
unsigned V_670 ;
unsigned V_687 ;
unsigned V_73 ;
int V_86 ;
if ( V_629 == V_688 )
V_683 = 100 ;
if ( V_683 < V_684 || V_683 > V_685 ) {
F_32 ( V_5 -> V_13 ,
L_37 ,
V_14 , V_684 , V_685 ) ;
return - V_316 ;
}
V_19 -> V_689 &= ~ V_690 ;
F_25 ( V_5 , V_19 -> V_689 ,
V_691 ) ;
V_686 = V_692 | V_693 ;
V_19 -> V_694 |= V_695 |
V_696 ;
V_19 -> V_694 &= ~ V_697 ;
switch ( V_629 ) {
case V_698 :
V_19 -> V_694 |= V_699 ;
break;
case V_688 :
V_19 -> V_694 |= V_700 ;
break;
default:
for ( V_687 = 0 ; V_687 <= V_701 ; ++ V_687 ) {
if ( V_629 == F_250 ( V_687 ) ) {
V_19 -> V_694 |=
F_251 ( V_687 ) ;
break;
}
}
if ( V_687 > V_701 )
return - V_316 ;
break;
}
V_86 = F_248 ( V_683 ,
& V_669 ,
& V_670 ,
& V_19 -> V_289 ) ;
if ( V_86 < 0 ) {
F_32 ( V_5 -> V_13 ,
L_38 ) ;
return V_86 ;
}
F_6 ( V_5 , V_19 -> V_694 , V_702 ) ;
V_686 |= F_252 ( V_669 ) |
F_253 ( V_670 ) ;
F_6 ( V_5 , V_686 , V_703 ) ;
V_19 -> V_704 = V_629 ;
for ( V_73 = 0 ; V_73 < V_72 ; ++ V_73 ) {
if ( F_15 ( V_5 , V_705 ) & V_706 )
break;
F_63 ( 1 ) ;
}
if ( V_73 == V_72 ) {
F_32 ( V_5 -> V_13 ,
L_39 ,
V_14 , V_629 , V_683 ) ;
return - V_707 ;
}
return 3 ;
}
static int F_254 ( struct V_4 * V_5 ,
unsigned V_629 , unsigned V_683 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
if ( V_629 == V_708 ) {
V_19 -> V_689 &= ~ V_690 ;
F_25 ( V_5 , V_19 -> V_689 ,
V_691 ) ;
V_19 -> V_289 = V_588 ;
if ( V_19 -> V_22 ) {
V_19 -> V_694 &=
~ ( V_695 |
V_696 ) ;
F_6 ( V_5 , V_19 -> V_694 ,
V_702 ) ;
F_6 ( V_5 , 0 , V_703 ) ;
}
V_19 -> V_704 = V_629 ;
} else {
if ( V_19 -> V_22 ) {
return F_249 ( V_5 , V_629 ,
V_683 ) ;
} else {
if ( V_629 == V_709 ) {
V_19 -> V_689 |=
V_690 ;
F_25 ( V_5 ,
V_19 -> V_689 ,
V_691 ) ;
if ( V_683 == 0 ) {
F_32 ( V_5 -> V_13 ,
L_40 ) ;
return - V_316 ;
}
V_19 -> V_289 = V_683 ;
V_19 -> V_704 = V_629 ;
} else {
return - V_316 ;
}
}
}
return 3 ;
}
static int F_255 ( struct V_4 * V_5 ,
unsigned V_231 , unsigned V_629 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
if ( V_231 >= F_256 ( V_19 -> V_22 ) ) {
if ( V_231 == V_710 ) {
if ( V_629 == V_711 )
return 1 ;
F_32 ( V_5 -> V_13 ,
L_41 ,
V_14 , V_231 , V_710 ) ;
return 0 ;
}
return 0 ;
}
switch ( V_629 ) {
case V_712 :
case V_713 :
case V_714 :
case V_715 :
case V_716 :
case V_717 :
case V_718 :
case V_719 :
case V_720 :
return 1 ;
case V_711 :
return ( V_19 -> V_22 ) ? 1 : 0 ;
default:
return 0 ;
}
}
static int F_257 ( struct V_4 * V_5 ,
unsigned V_231 , unsigned V_721 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
if ( F_255 ( V_5 , V_231 , V_721 ) == 0 )
return - V_316 ;
if ( V_231 < 4 ) {
V_19 -> V_722 &= ~ F_258 ( V_231 ) ;
V_19 -> V_722 |= F_259 ( V_231 , V_721 ) ;
F_25 ( V_5 , V_19 -> V_722 ,
V_723 ) ;
} else if ( V_231 < 8 ) {
V_19 -> V_724 &= ~ F_258 ( V_231 ) ;
V_19 -> V_724 |= F_259 ( V_231 , V_721 ) ;
F_25 ( V_5 , V_19 -> V_724 ,
V_725 ) ;
}
return 2 ;
}
static unsigned F_260 ( struct V_4 * V_5 , unsigned V_231 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
if ( V_231 < 4 ) {
return F_261 ( V_231 ,
V_19 -> V_722 ) ;
} else if ( V_231 < F_256 ( V_19 -> V_22 ) ) {
return F_261 ( V_231 ,
V_19 -> V_724 ) ;
} else {
if ( V_231 == V_710 )
return V_711 ;
F_32 ( V_5 -> V_13 , L_42 ) ;
return 0 ;
}
}
static int F_262 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_277 * V_278 ,
unsigned int * V_6 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_231 = F_116 ( V_278 -> V_281 ) ;
unsigned int V_726 = F_256 ( V_19 -> V_22 ) ;
switch ( V_6 [ 0 ] ) {
case V_727 :
if ( V_231 < V_726 ) {
V_19 -> V_689 |=
F_263 ( V_231 , V_19 -> V_22 ) ;
} else if ( V_231 == V_710 ) {
V_19 -> V_689 |=
V_728 ;
}
F_25 ( V_5 , V_19 -> V_689 ,
V_691 ) ;
break;
case V_729 :
if ( V_231 < V_726 ) {
V_19 -> V_689 &=
~ F_263 ( V_231 , V_19 -> V_22 ) ;
} else if ( V_231 == V_710 ) {
V_19 -> V_689 &=
~ V_728 ;
}
F_25 ( V_5 , V_19 -> V_689 ,
V_691 ) ;
break;
case V_638 :
if ( V_231 < V_726 ) {
V_6 [ 1 ] =
( V_19 -> V_689 &
F_263 ( V_231 , V_19 -> V_22 ) )
? V_727
: V_729 ;
} else if ( V_231 == V_710 ) {
V_6 [ 1 ] = ( V_19 -> V_689 &
V_728 )
? V_727
: V_729 ;
}
return 2 ;
case V_582 :
return F_254 ( V_5 , V_6 [ 1 ] , V_6 [ 2 ] ) ;
case V_586 :
V_6 [ 1 ] = V_19 -> V_704 ;
V_6 [ 2 ] = V_19 -> V_289 ;
return 3 ;
case V_639 :
return F_257 ( V_5 , V_231 , V_6 [ 1 ] ) ;
case V_640 :
V_6 [ 1 ] = F_260 ( V_5 , V_231 ) ;
return 2 ;
default:
return - V_316 ;
}
return 1 ;
}
static int F_264 ( struct V_4 * V_5 ,
struct V_83 * V_84 ,
struct V_277 * V_278 ,
unsigned int * V_6 )
{
V_6 [ 1 ] = 0 ;
return V_278 -> V_95 ;
}
static void F_265 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
V_19 -> V_694 = V_730 ;
if ( F_254 ( V_5 , V_708 , 0 ) < 0 )
F_32 ( V_5 -> V_13 , L_43 ) ;
V_19 -> V_722 =
F_259 ( 0 , V_712 ) |
F_259 ( 1 , V_713 ) |
F_259 ( 2 , V_714 ) |
F_259 ( 3 , V_715 ) ;
F_25 ( V_5 , V_19 -> V_722 ,
V_723 ) ;
V_19 -> V_724 =
F_259 ( 4 , V_716 ) |
F_259 ( 5 , V_717 ) |
F_259 ( 6 , V_718 ) ;
if ( V_19 -> V_22 )
V_19 -> V_724 |=
F_259 ( 7 , V_711 ) ;
F_25 ( V_5 , V_19 -> V_724 ,
V_725 ) ;
}
static int F_266 ( struct V_4 * V_5 , struct V_83 * V_84 )
{
struct V_550 * V_551 = V_84 -> V_20 ;
int V_86 ;
V_86 = F_52 ( V_5 , V_551 -> V_1 ,
V_55 ) ;
if ( V_86 ) {
F_32 ( V_5 -> V_13 ,
L_44 ) ;
return V_86 ;
}
F_267 ( V_551 ) ;
F_61 ( V_5 , V_551 -> V_1 , 1 ) ;
return F_268 ( V_5 , V_84 ) ;
}
static int F_269 ( struct V_4 * V_5 , struct V_83 * V_84 )
{
struct V_550 * V_551 = V_84 -> V_20 ;
int V_86 ;
V_86 = F_270 ( V_551 ) ;
F_61 ( V_5 , V_551 -> V_1 , 0 ) ;
F_59 ( V_5 , V_551 -> V_1 ) ;
return V_86 ;
}
static T_7 F_271 ( int V_326 , void * V_96 )
{
struct V_4 * V_5 = V_96 ;
unsigned short V_131 ;
unsigned short V_91 ;
unsigned int V_143 = 0 ;
unsigned int V_178 = 0 ;
unsigned long V_21 ;
#ifdef F_55
struct V_18 * V_19 = V_5 -> V_20 ;
struct V_89 * V_24 = V_19 -> V_24 ;
#endif
if ( ! V_5 -> V_731 )
return V_732 ;
F_272 () ;
F_26 ( & V_5 -> V_226 , V_21 ) ;
V_131 = F_29 ( V_5 , V_87 ) ;
V_91 = F_29 ( V_5 , V_92 ) ;
#ifdef F_55
if ( V_24 ) {
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned long V_733 ;
F_26 ( & V_19 -> V_50 , V_733 ) ;
if ( V_19 -> V_51 ) {
V_143 = F_189 ( V_19 -> V_51 ) ;
if ( V_143 & V_147 )
F_4 ( V_515 ,
V_19 -> V_24 -> V_516 +
F_190 ( V_19 ->
V_51 -> V_41 ) ) ;
}
if ( V_19 -> V_56 ) {
V_178 = F_189 ( V_19 -> V_56 ) ;
if ( V_178 & V_147 )
F_4 ( V_515 ,
V_24 -> V_516 +
F_190 ( V_19 ->
V_56 -> V_41 ) ) ;
}
F_27 ( & V_19 -> V_50 , V_733 ) ;
}
#endif
F_93 ( V_5 , V_131 ) ;
F_96 ( V_5 , V_91 ) ;
if ( ( V_131 & V_734 ) || ( V_143 & V_148 ) )
F_94 ( V_5 , V_131 , V_143 ) ;
if ( ( V_91 & V_735 ) || ( V_178 & V_148 ) )
F_97 ( V_5 , V_91 , V_178 ) ;
F_90 ( V_5 , 0 ) ;
F_90 ( V_5 , 1 ) ;
F_188 ( V_5 ) ;
F_27 ( & V_5 -> V_226 , V_21 ) ;
return V_736 ;
}
static int F_273 ( struct V_4 * V_5 )
{
struct V_18 * V_19 ;
V_19 = F_274 ( V_5 , sizeof( * V_19 ) ) ;
if ( ! V_19 )
return - V_737 ;
F_275 ( & V_19 -> V_23 ) ;
F_275 ( & V_19 -> V_30 ) ;
F_275 ( & V_19 -> V_50 ) ;
return 0 ;
}
static int F_276 ( struct V_4 * V_5 ,
unsigned V_738 , unsigned V_739 )
{
const struct V_102 * V_103 = V_5 -> V_104 ;
struct V_18 * V_19 = V_5 -> V_20 ;
struct V_83 * V_84 ;
int V_181 ;
int V_73 ;
if ( V_103 -> V_740 > V_741 ) {
F_32 ( V_5 -> V_13 , L_45 ) ;
return - V_316 ;
}
V_19 -> V_531 = V_742 |
V_540 |
V_743 |
V_744 ;
if ( ! V_19 -> V_98 ) {
V_19 -> V_531 |= ( V_745 |
V_746 ) ;
}
F_25 ( V_5 , V_19 -> V_531 , V_544 ) ;
V_181 = F_277 ( V_5 , V_747 ) ;
if ( V_181 )
return V_181 ;
V_84 = & V_5 -> V_130 [ V_748 ] ;
if ( V_103 -> V_749 ) {
V_84 -> type = V_750 ;
V_84 -> V_190 = V_751 | V_752 | V_753 ;
if ( ! V_19 -> V_115 )
V_84 -> V_190 |= V_754 | V_755 | V_756 ;
if ( V_103 -> V_757 > 0xffff )
V_84 -> V_190 |= V_191 ;
if ( V_19 -> V_22 )
V_84 -> V_190 |= V_758 ;
V_84 -> V_229 = V_103 -> V_749 ;
V_84 -> V_260 = V_103 -> V_757 ;
V_84 -> V_387 = V_759 [ V_103 -> V_240 ] ;
V_84 -> V_760 = F_128 ;
V_84 -> V_761 = F_146 ;
if ( V_5 -> V_326 ) {
V_5 -> V_85 = V_84 ;
V_84 -> V_190 |= V_762 ;
V_84 -> V_763 = 512 ;
V_84 -> V_764 = F_132 ;
V_84 -> V_765 = F_139 ;
V_84 -> V_494 = F_107 ;
V_84 -> V_766 = F_112 ;
V_84 -> V_767 = F_98 ;
if ( V_19 -> V_24 )
V_84 -> V_768 = V_769 ;
}
F_107 ( V_5 , V_84 ) ;
} else {
V_84 -> type = V_146 ;
}
V_84 = & V_5 -> V_130 [ V_770 ] ;
if ( V_103 -> V_740 ) {
V_84 -> type = V_771 ;
V_84 -> V_190 = V_772 | V_773 | V_754 ;
if ( V_19 -> V_22 )
V_84 -> V_190 |= V_758 ;
V_84 -> V_229 = V_103 -> V_740 ;
V_84 -> V_260 = V_103 -> V_774 ;
V_84 -> V_387 = V_103 -> V_775 ;
V_84 -> V_761 = F_163 ;
V_84 -> V_776 = F_159 ;
V_181 = F_278 ( V_84 ) ;
if ( V_181 )
return V_181 ;
if ( V_5 -> V_326 && ( V_103 -> V_110 || V_19 -> V_24 ) ) {
V_5 -> V_90 = V_84 ;
V_84 -> V_190 |= V_777 ;
V_84 -> V_763 = V_84 -> V_229 ;
V_84 -> V_764 = F_171 ;
V_84 -> V_765 = F_166 ;
V_84 -> V_494 = F_172 ;
if ( ! V_19 -> V_22 )
V_84 -> V_767 = F_147 ;
if ( V_19 -> V_24 )
V_84 -> V_768 = V_778 ;
}
if ( V_19 -> V_779 )
F_195 ( V_5 , V_84 ) ;
F_172 ( V_5 , V_84 ) ;
} else {
V_84 -> type = V_146 ;
}
V_84 = & V_5 -> V_130 [ V_513 ] ;
V_84 -> type = V_780 ;
V_84 -> V_190 = V_772 | V_751 ;
V_84 -> V_229 = V_103 -> V_781 ? 32 : 8 ;
V_84 -> V_260 = 1 ;
V_84 -> V_387 = & V_782 ;
if ( V_19 -> V_22 ) {
V_84 -> V_190 |= V_191 ;
V_84 -> V_783 = F_180 ;
V_84 -> V_761 = F_179 ;
if ( V_5 -> V_326 ) {
V_84 -> V_190 |= V_777 ;
V_84 -> V_763 = V_84 -> V_229 ;
V_84 -> V_764 = F_182 ;
V_84 -> V_765 = F_185 ;
V_84 -> V_494 = F_187 ;
V_84 -> V_768 = V_784 ;
}
F_3 ( V_5 , V_500 |
V_785 ,
V_498 ) ;
F_3 ( V_5 , V_84 -> V_479 , V_489 ) ;
} else {
V_84 -> V_783 = F_176 ;
V_84 -> V_761 = F_173 ;
V_19 -> V_477 = F_175 ( V_84 -> V_479 ) ;
F_6 ( V_5 , V_19 -> V_477 , V_480 ) ;
}
V_84 = & V_5 -> V_130 [ V_786 ] ;
if ( V_103 -> V_787 ) {
V_181 = F_279 ( V_5 , V_84 , F_204 ,
V_788 ) ;
if ( V_181 )
return V_181 ;
} else {
V_84 -> type = V_146 ;
}
V_84 = & V_5 -> V_130 [ V_789 ] ;
V_84 -> type = V_146 ;
V_84 = & V_5 -> V_130 [ V_790 ] ;
V_84 -> type = V_791 ;
V_84 -> V_190 = V_792 ;
V_84 -> V_229 = 1 ;
V_84 -> V_260 = 0 ;
if ( V_19 -> V_22 ) {
V_84 -> V_761 = F_206 ;
F_3 ( V_5 , 0x0 , V_596 ) ;
} else if ( V_19 -> V_74 ) {
V_84 -> V_761 = F_209 ;
} else {
V_84 -> V_190 |= V_772 ;
V_84 -> V_760 = F_220 ;
V_84 -> V_776 = F_219 ;
F_221 ( V_5 , V_84 ) ;
}
V_84 = & V_5 -> V_130 [ V_793 ] ;
V_84 -> type = V_794 ;
V_84 -> V_190 = V_751 | V_792 ;
V_84 -> V_260 = 0xff ;
if ( V_19 -> V_22 ) {
V_84 -> V_229 = V_795 ;
V_84 -> V_760 = F_224 ;
} else {
V_84 -> V_229 = 512 ;
V_84 -> V_760 = F_223 ;
}
V_84 = & V_5 -> V_130 [ V_796 ] ;
V_84 -> type = V_780 ;
V_84 -> V_190 = V_751 | V_772 | V_792 ;
V_84 -> V_260 = 1 ;
if ( V_19 -> V_22 ) {
V_84 -> V_229 = 16 ;
V_84 -> V_783 = F_239 ;
F_6 ( V_5 , V_84 -> V_486 , V_642 ) ;
for ( V_73 = 0 ; V_73 < V_797 ; ++ V_73 ) {
F_6 ( V_5 , V_19 -> V_631 [ V_73 ] ,
F_232 ( V_73 ) ) ;
}
} else {
V_84 -> V_229 = 10 ;
}
V_84 -> V_761 = F_238 ;
F_68 ( V_5 , V_35 , ~ 0 , 0 ) ;
V_84 = & V_5 -> V_130 [ V_798 ] ;
if ( V_19 -> V_779 ) {
V_84 -> type = V_750 ;
V_84 -> V_190 = V_751 | V_752 | V_792 ;
V_84 -> V_229 = V_103 -> V_740 ;
V_84 -> V_260 = ( 1 << 16 ) - 1 ;
V_84 -> V_387 = & V_799 ;
V_84 -> V_760 = F_245 ;
V_84 -> V_761 = NULL ;
F_247 ( V_5 ) ;
} else {
V_84 -> type = V_146 ;
}
V_84 = & V_5 -> V_130 [ V_800 ] ;
V_84 -> type = V_801 ;
V_84 -> V_190 = V_751 | V_772 | V_792 ;
V_84 -> V_229 = 1 ;
V_84 -> V_260 = 0xff ;
V_84 -> V_761 = F_194 ;
V_19 -> V_483 = 0 ;
V_19 -> V_535 = 0 ;
V_84 = & V_5 -> V_130 [ V_802 ] ;
V_84 -> type = V_780 ;
V_84 -> V_190 = V_751 | V_772 | V_792 ;
V_84 -> V_229 = 8 ;
V_84 -> V_260 = 1 ;
V_84 -> V_783 = F_264 ;
V_84 -> V_761 = F_262 ;
F_265 ( V_5 ) ;
V_19 -> V_62 = F_280 ( V_5 ,
F_197 ,
F_198 ,
( V_19 -> V_22 )
? V_803
: V_804 ,
V_805 ) ;
if ( ! V_19 -> V_62 )
return - V_737 ;
for ( V_73 = 0 ; V_73 < V_805 ; ++ V_73 ) {
struct V_550 * V_806 = & V_19 -> V_62 -> V_63 [ V_73 ] ;
V_806 -> V_807 = 0 ;
V_806 -> V_1 = V_73 ;
F_281 ( V_806 ) ;
V_84 = & V_5 -> V_130 [ F_1 ( V_73 ) ] ;
V_84 -> type = V_808 ;
V_84 -> V_190 = V_751 | V_772 | V_191 ;
V_84 -> V_229 = 3 ;
V_84 -> V_260 = ( V_19 -> V_22 ) ? 0xffffffff
: 0x00ffffff ;
V_84 -> V_760 = V_809 ;
V_84 -> V_776 = V_809 ;
V_84 -> V_761 = V_810 ;
#ifdef F_55
if ( V_5 -> V_326 && V_19 -> V_24 ) {
V_84 -> V_190 |= V_762 ;
V_84 -> V_763 = 1 ;
V_84 -> V_764 = V_811 ;
V_84 -> V_765 = F_266 ;
V_84 -> V_494 = F_269 ;
V_84 -> V_768 = V_784 ;
}
#endif
V_84 -> V_20 = V_806 ;
}
V_84 = & V_5 -> V_130 [ V_812 ] ;
V_84 -> type = V_808 ;
V_84 -> V_190 = V_751 | V_772 ;
V_84 -> V_229 = 1 ;
V_84 -> V_260 = 0xf ;
V_84 -> V_760 = F_199 ;
V_84 -> V_776 = F_201 ;
V_84 -> V_761 = F_203 ;
if ( V_5 -> V_326 ) {
F_25 ( V_5 ,
( V_739 ? V_813 : 0 ) |
( V_814 & 0 ) |
V_815 |
V_816 |
F_282 ( V_738 ) |
F_283 ( V_738 ) ,
V_817 ) ;
}
F_9 ( V_5 , V_19 -> V_38 , V_37 ) ;
F_9 ( V_5 , V_19 -> V_40 , V_39 ) ;
if ( V_19 -> V_98 ) {
F_9 ( V_5 , 0 , V_818 ) ;
} else if ( V_19 -> V_22 ) {
int V_41 ;
for ( V_41 = 0 ; V_41 < V_103 -> V_740 ; ++ V_41 ) {
F_9 ( V_5 , 0xf ,
F_153 ( V_41 ) ) ;
F_9 ( V_5 , 0x0 ,
F_154 ( V_41 ) ) ;
}
F_9 ( V_5 , 0x0 , V_819 ) ;
}
return 0 ;
}
static void F_284 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
if ( V_19 ) {
if ( V_19 -> V_62 )
F_285 ( V_19 -> V_62 ) ;
}
}
