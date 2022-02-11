static void F_1 ( struct V_1 * V_2 , unsigned int V_3 , int V_4 )
{
if ( V_2 -> V_5 )
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
else
F_3 ( V_3 , V_2 -> V_6 + V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 , unsigned int V_3 , int V_4 )
{
if ( V_2 -> V_5 )
F_5 ( V_3 , V_2 -> V_5 + V_4 ) ;
else
F_6 ( V_3 , V_2 -> V_6 + V_4 ) ;
}
static void F_7 ( struct V_1 * V_2 , unsigned int V_3 , int V_4 )
{
if ( V_2 -> V_5 )
F_8 ( V_3 , V_2 -> V_5 + V_4 ) ;
else
F_9 ( V_3 , V_2 -> V_6 + V_4 ) ;
}
static unsigned int F_10 ( struct V_1 * V_2 , int V_4 )
{
if ( V_2 -> V_5 )
return F_11 ( V_2 -> V_5 + V_4 ) ;
return F_12 ( V_2 -> V_6 + V_4 ) ;
}
static unsigned int F_13 ( struct V_1 * V_2 , int V_4 )
{
if ( V_2 -> V_5 )
return F_14 ( V_2 -> V_5 + V_4 ) ;
return F_15 ( V_2 -> V_6 + V_4 ) ;
}
static unsigned int F_16 ( struct V_1 * V_2 , int V_4 )
{
if ( V_2 -> V_5 )
return F_17 ( V_2 -> V_5 + V_4 ) ;
return F_18 ( V_2 -> V_6 + V_4 ) ;
}
static void F_19 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
const struct V_7 * V_8 ;
if ( V_4 < F_20 ( V_9 ) ) {
V_8 = & V_9 [ V_4 ] ;
} else {
F_21 ( V_2 -> V_10 , L_1 ,
V_11 , V_4 ) ;
return;
}
switch ( V_8 -> V_12 ) {
case 4 :
F_1 ( V_2 , V_3 , V_8 -> V_13 ) ;
break;
case 2 :
F_4 ( V_2 , V_3 , V_8 -> V_13 ) ;
break;
default:
F_21 ( V_2 -> V_10 , L_2 ,
V_11 , V_4 ) ;
break;
}
}
static unsigned int F_22 ( struct V_1 * V_2 ,
unsigned int V_4 )
{
const struct V_7 * V_8 ;
if ( V_4 < F_20 ( V_14 ) ) {
V_8 = & V_14 [ V_4 ] ;
} else {
F_21 ( V_2 -> V_10 , L_1 ,
V_11 , V_4 ) ;
return 0 ;
}
switch ( V_8 -> V_12 ) {
case 4 :
return F_10 ( V_2 , V_8 -> V_13 ) ;
case 2 :
return F_13 ( V_2 , V_8 -> V_13 ) ;
case 1 :
return F_16 ( V_2 , V_8 -> V_13 ) ;
default:
F_21 ( V_2 -> V_10 , L_2 ,
V_11 , V_4 ) ;
return 0 ;
}
}
static void F_23 ( struct V_1 * V_2 ,
unsigned int V_3 , int V_4 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned long V_18 ;
if ( V_16 -> V_19 ) {
F_19 ( V_2 , V_3 , V_4 ) ;
} else {
F_24 ( & V_16 -> V_20 , V_18 ) ;
if ( ! V_16 -> V_21 && V_4 < 8 ) {
F_4 ( V_2 , V_3 , V_4 * 2 ) ;
} else {
F_4 ( V_2 , V_4 , V_22 ) ;
F_4 ( V_2 , V_3 , V_23 ) ;
}
F_25 ( & V_16 -> V_20 , V_18 ) ;
}
}
static void F_26 ( struct V_1 * V_2 ,
unsigned int V_3 , int V_4 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
if ( V_16 -> V_19 ) {
F_19 ( V_2 , V_3 , V_4 ) ;
} else {
F_23 ( V_2 , V_3 >> 16 , V_4 ) ;
F_23 ( V_2 , V_3 & 0xffff , V_4 + 1 ) ;
}
}
static unsigned int F_27 ( struct V_1 * V_2 , int V_4 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned long V_18 ;
unsigned int V_24 ;
if ( V_16 -> V_19 ) {
V_24 = F_22 ( V_2 , V_4 ) ;
} else {
F_24 ( & V_16 -> V_20 , V_18 ) ;
if ( ! V_16 -> V_21 && V_4 < 8 ) {
V_24 = F_13 ( V_2 , V_4 * 2 ) ;
} else {
F_4 ( V_2 , V_4 , V_22 ) ;
V_24 = F_13 ( V_2 , V_23 ) ;
}
F_25 ( & V_16 -> V_20 , V_18 ) ;
}
return V_24 ;
}
static unsigned int F_28 ( struct V_1 * V_2 , int V_4 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned int V_24 ;
if ( V_16 -> V_19 ) {
V_24 = F_22 ( V_2 , V_4 ) ;
} else {
V_24 = F_27 ( V_2 , V_4 ) << 16 ;
V_24 |= F_27 ( V_2 , V_4 + 1 ) ;
}
return V_24 ;
}
static inline void F_29 ( struct V_1 * V_2 , int V_4 ,
unsigned int V_25 ,
unsigned int V_26 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned long V_18 ;
F_24 ( & V_16 -> V_27 , V_18 ) ;
switch ( V_4 ) {
case V_28 :
V_16 -> V_29 &= ~ V_25 ;
V_16 -> V_29 |= V_26 & V_25 ;
F_23 ( V_2 , V_16 -> V_29 , V_4 ) ;
break;
case V_30 :
V_16 -> V_31 &= ~ V_25 ;
V_16 -> V_31 |= V_26 & V_25 ;
F_23 ( V_2 , V_16 -> V_31 , V_4 ) ;
break;
case V_32 :
V_16 -> V_33 &= ~ V_25 ;
V_16 -> V_33 |= V_26 & V_25 ;
F_23 ( V_2 , V_16 -> V_33 , V_4 ) ;
break;
case V_34 :
V_16 -> V_35 &= ~ V_25 ;
V_16 -> V_35 |= V_26 & V_25 ;
F_7 ( V_2 , V_16 -> V_35 , V_4 ) ;
break;
case V_36 :
V_16 -> V_37 &= ~ V_25 ;
V_16 -> V_37 |= V_26 & V_25 ;
F_7 ( V_2 , V_16 -> V_37 , V_4 ) ;
break;
case V_38 :
V_16 -> V_39 &= ~ V_25 ;
V_16 -> V_39 |= V_26 & V_25 ;
F_7 ( V_2 , V_16 -> V_39 , V_4 ) ;
break;
default:
F_30 ( V_2 -> V_10 , L_3 ,
V_4 ) ;
break;
}
F_31 () ;
F_25 ( & V_16 -> V_27 , V_18 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_40 * V_41 ;
unsigned long V_18 ;
unsigned int V_42 ;
F_24 ( & V_16 -> V_43 , V_18 ) ;
V_41 = F_33 ( V_16 -> V_21 , V_16 -> V_44 ) ;
if ( ! V_41 ) {
F_25 ( & V_16 -> V_43 , V_18 ) ;
F_30 ( V_2 -> V_10 ,
L_4 ) ;
return - V_45 ;
}
V_41 -> V_46 = V_47 ;
V_16 -> V_48 = V_41 ;
V_42 = F_34 ( V_41 -> V_49 ) ;
F_29 ( V_2 , V_34 ,
V_50 , F_35 ( V_42 ) ) ;
F_25 ( & V_16 -> V_43 , V_18 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_40 * V_41 ;
unsigned long V_18 ;
unsigned int V_42 ;
F_24 ( & V_16 -> V_43 , V_18 ) ;
V_41 = F_33 ( V_16 -> V_21 , V_16 -> V_51 ) ;
if ( ! V_41 ) {
F_25 ( & V_16 -> V_43 , V_18 ) ;
F_30 ( V_2 -> V_10 ,
L_5 ) ;
return - V_45 ;
}
V_41 -> V_46 = V_52 ;
V_16 -> V_53 = V_41 ;
V_42 = F_34 ( V_41 -> V_49 ) ;
F_29 ( V_2 , V_34 ,
V_54 , F_37 ( V_42 ) ) ;
F_25 ( & V_16 -> V_43 , V_18 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
unsigned int V_55 ,
enum V_56 V_57 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_58 * V_59 = & V_16 -> V_60 -> V_61 [ V_55 ] ;
struct V_40 * V_41 ;
unsigned long V_18 ;
unsigned int V_42 ;
F_24 ( & V_16 -> V_43 , V_18 ) ;
V_41 = F_33 ( V_16 -> V_21 ,
V_16 -> V_62 [ V_55 ] ) ;
if ( ! V_41 ) {
F_25 ( & V_16 -> V_43 , V_18 ) ;
F_30 ( V_2 -> V_10 ,
L_6 ) ;
return - V_45 ;
}
V_41 -> V_46 = V_57 ;
F_39 ( V_59 , V_41 ) ;
V_42 = F_34 ( V_41 -> V_49 ) ;
F_29 ( V_2 , V_36 ,
F_40 ( V_55 ) ,
F_41 ( V_55 , V_42 ) ) ;
F_25 ( & V_16 -> V_43 , V_18 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_40 * V_41 ;
unsigned long V_18 ;
unsigned int V_42 ;
F_24 ( & V_16 -> V_43 , V_18 ) ;
V_41 = F_33 ( V_16 -> V_21 , V_16 -> V_63 ) ;
if ( ! V_41 ) {
F_25 ( & V_16 -> V_43 , V_18 ) ;
F_30 ( V_2 -> V_10 ,
L_7 ) ;
return - V_45 ;
}
V_41 -> V_46 = V_52 ;
V_16 -> V_64 = V_41 ;
V_42 = F_34 ( V_41 -> V_49 ) ;
F_29 ( V_2 , V_38 ,
V_65 ,
F_43 ( V_42 ) ) ;
F_25 ( & V_16 -> V_43 , V_18 ) ;
return 0 ;
}
static void F_44 ( struct V_1 * V_2 )
{
#ifdef F_45
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned long V_18 ;
F_24 ( & V_16 -> V_43 , V_18 ) ;
if ( V_16 -> V_48 ) {
F_29 ( V_2 , V_34 ,
V_50 , 0 ) ;
F_46 ( V_16 -> V_48 ) ;
V_16 -> V_48 = NULL ;
}
F_25 ( & V_16 -> V_43 , V_18 ) ;
#endif
}
static void F_47 ( struct V_1 * V_2 )
{
#ifdef F_45
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned long V_18 ;
F_24 ( & V_16 -> V_43 , V_18 ) ;
if ( V_16 -> V_53 ) {
F_29 ( V_2 , V_34 ,
V_54 , 0 ) ;
F_46 ( V_16 -> V_53 ) ;
V_16 -> V_53 = NULL ;
}
F_25 ( & V_16 -> V_43 , V_18 ) ;
#endif
}
static void F_48 ( struct V_1 * V_2 ,
unsigned int V_55 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned long V_18 ;
F_24 ( & V_16 -> V_43 , V_18 ) ;
if ( V_16 -> V_60 -> V_61 [ V_55 ] . V_41 ) {
struct V_40 * V_41 =
V_16 -> V_60 -> V_61 [ V_55 ] . V_41 ;
F_29 ( V_2 , V_36 ,
F_40 ( V_55 ) , 0 ) ;
F_39 ( & V_16 ->
V_60 -> V_61 [ V_55 ] ,
NULL ) ;
F_46 ( V_41 ) ;
}
F_25 ( & V_16 -> V_43 , V_18 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned long V_18 ;
F_24 ( & V_16 -> V_43 , V_18 ) ;
if ( V_16 -> V_64 ) {
F_29 ( V_2 , V_38 ,
V_65 , 0 ) ;
F_46 ( V_16 -> V_64 ) ;
V_16 -> V_64 = NULL ;
}
F_25 ( & V_16 -> V_43 , V_18 ) ;
}
static void F_50 ( struct V_1 * V_2 ,
unsigned int V_55 , short V_66 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned int V_24 = 0 ;
int V_4 ;
if ( V_16 -> V_19 || V_55 > 1 )
return;
if ( V_55 == 0 ) {
V_4 = V_67 ;
if ( V_66 )
V_24 = V_68 ;
} else {
V_4 = V_69 ;
if ( V_66 )
V_24 = V_70 ;
}
F_23 ( V_2 , V_24 , V_4 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
static const int V_71 = 10000 ;
int V_72 ;
if ( V_16 -> V_73 ) {
F_1 ( V_2 , 0x10 , V_74 ) ;
F_1 ( V_2 , 0x00 , V_74 ) ;
for ( V_72 = 0 ; V_72 < V_71 ; V_72 ++ ) {
if ( ! ( F_10 ( V_2 , V_75 ) & 0x10 ) )
break;
F_52 ( 1 ) ;
}
if ( V_72 == V_71 )
F_30 ( V_2 -> V_10 , L_8 ) ;
} else {
F_23 ( V_2 , 1 , V_76 ) ;
if ( V_16 -> V_77 ) {
F_7 ( V_2 , 0 , F_53 ( 0 ) ) ;
F_7 ( V_2 , 1 , F_53 ( 0 ) ) ;
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
static inline void F_54 ( struct V_1 * V_2 ,
unsigned int V_3 , int V_78 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned long V_18 ;
F_24 ( & V_16 -> V_20 , V_18 ) ;
F_4 ( V_2 , V_78 , V_79 ) ;
F_4 ( V_2 , V_3 , V_80 ) ;
F_25 ( & V_16 -> V_20 , V_18 ) ;
}
static inline void F_55 ( struct V_1 * V_2 ,
unsigned int V_3 , int V_78 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned long V_18 ;
F_24 ( & V_16 -> V_20 , V_18 ) ;
F_4 ( V_2 , V_78 , V_79 ) ;
F_1 ( V_2 , V_3 , V_80 ) ;
F_25 ( & V_16 -> V_20 , V_18 ) ;
}
static inline unsigned short F_56 ( struct V_1 * V_2 , int V_78 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned long V_18 ;
unsigned short V_3 ;
F_24 ( & V_16 -> V_20 , V_18 ) ;
F_4 ( V_2 , V_78 , V_79 ) ;
V_3 = F_13 ( V_2 , V_80 ) ;
F_25 ( & V_16 -> V_20 , V_18 ) ;
return V_3 ;
}
static inline void F_57 ( struct V_1 * V_2 , int V_4 ,
unsigned int V_42 , unsigned int V_81 )
{
unsigned int V_26 ;
if ( V_81 )
V_26 = V_42 ;
else
V_26 = 0 ;
F_29 ( V_2 , V_4 , V_42 , V_26 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_82 * V_83 = V_2 -> V_84 ;
unsigned long V_18 ;
F_24 ( & V_16 -> V_43 , V_18 ) ;
if ( V_16 -> V_48 )
F_59 ( V_16 -> V_48 , V_83 ) ;
F_25 ( & V_16 -> V_43 , V_18 ) ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
int V_72 ;
static const int V_71 = 10000 ;
unsigned long V_18 ;
int V_85 = 0 ;
F_24 ( & V_16 -> V_43 , V_18 ) ;
if ( V_16 -> V_48 ) {
for ( V_72 = 0 ; V_72 < V_71 ; V_72 ++ ) {
if ( ( F_27 ( V_2 , V_86 ) &
V_87 ) &&
F_61 ( V_16 -> V_48 ) == 0 )
break;
F_52 ( 5 ) ;
}
if ( V_72 == V_71 ) {
F_30 ( V_2 -> V_10 , L_9 ) ;
F_30 ( V_2 -> V_10 ,
L_10 ,
F_61 ( V_16 -> V_48 ) ,
F_27 ( V_2 , V_86 ) ) ;
V_85 = - 1 ;
}
}
F_25 ( & V_16 -> V_43 , V_18 ) ;
F_58 ( V_2 ) ;
return V_85 ;
}
static int F_62 ( struct V_1 * V_2 )
{
static const int V_71 = 10000 ;
int V_72 ;
for ( V_72 = 0 ; V_72 < V_71 ; V_72 ++ ) {
unsigned short V_88 ;
V_88 = F_27 ( V_2 , V_89 ) ;
if ( V_88 & V_90 )
break;
F_63 ( 10 , 100 ) ;
}
if ( V_72 == V_71 ) {
F_30 ( V_2 -> V_10 , L_11 ) ;
return - V_91 ;
}
return 0 ;
}
static void F_64 ( struct V_1 * V_2 ,
struct V_82 * V_83 , int V_92 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
int V_72 ;
unsigned short V_93 ;
unsigned int V_94 ;
for ( V_72 = 0 ; V_72 < V_92 ; V_72 ++ ) {
F_65 ( V_83 , & V_93 , 1 ) ;
if ( V_16 -> V_95 ) {
V_94 = V_93 & 0xffff ;
if ( ! V_16 -> V_96 ) {
F_65 ( V_83 , & V_93 , 1 ) ;
V_72 ++ ;
V_94 |= ( V_93 << 16 ) & 0xffff0000 ;
}
F_1 ( V_2 , V_94 , V_97 ) ;
} else {
F_4 ( V_2 , V_93 , V_98 ) ;
}
}
}
static int F_66 ( struct V_1 * V_2 ,
struct V_82 * V_83 )
{
const struct V_99 * V_100 = V_2 -> V_101 ;
unsigned int V_102 ;
unsigned int V_103 ;
V_102 = F_67 ( V_83 ) ;
if ( V_102 == 0 ) {
V_83 -> V_104 -> V_105 |= V_106 ;
return 0 ;
}
V_103 = F_68 ( V_83 , V_102 ) ;
if ( V_103 > V_100 -> V_107 / 2 )
V_103 = V_100 -> V_107 / 2 ;
F_64 ( V_2 , V_83 , V_103 ) ;
return 1 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_82 * V_83 )
{
const struct V_99 * V_100 = V_2 -> V_101 ;
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned int V_102 ;
unsigned int V_103 ;
F_23 ( V_2 , 1 , V_108 ) ;
if ( V_16 -> V_95 )
F_55 ( V_2 , 0x6 , V_109 ) ;
V_102 = F_67 ( V_83 ) ;
if ( V_102 == 0 )
return 0 ;
V_103 = F_68 ( V_83 , V_102 ) ;
if ( V_103 > V_100 -> V_107 )
V_103 = V_100 -> V_107 ;
F_64 ( V_2 , V_83 , V_103 ) ;
return V_103 ;
}
static void F_70 ( struct V_1 * V_2 ,
struct V_82 * V_83 , int V_92 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_110 * V_104 = V_83 -> V_104 ;
unsigned int V_111 ;
unsigned short V_3 ;
int V_72 ;
if ( V_16 -> V_112 ) {
for ( V_72 = 0 ; V_72 < V_92 / 2 ; V_72 ++ ) {
V_111 = F_10 ( V_2 , V_113 ) ;
V_3 = ( V_111 >> 16 ) & 0xffff ;
F_71 ( V_83 , & V_3 , 1 ) ;
V_3 = V_111 & 0xffff ;
F_71 ( V_83 , & V_3 , 1 ) ;
}
if ( V_92 % 2 ) {
V_111 = F_10 ( V_2 , V_113 ) ;
V_3 = V_111 & 0xffff ;
F_71 ( V_83 , & V_3 , 1 ) ;
}
} else if ( V_16 -> V_73 ) {
for ( V_72 = 0 ; V_72 < V_92 / 2 ; V_72 ++ ) {
V_111 = F_10 ( V_2 , V_114 ) ;
V_3 = ( V_111 >> 16 ) & 0xffff ;
F_71 ( V_83 , & V_3 , 1 ) ;
V_3 = V_111 & 0xffff ;
F_71 ( V_83 , & V_3 , 1 ) ;
}
if ( V_92 % 2 ) {
F_1 ( V_2 , 0x01 , V_74 ) ;
V_111 = F_10 ( V_2 , V_114 ) ;
V_3 = ( V_111 >> 16 ) & 0xffff ;
F_71 ( V_83 , & V_3 , 1 ) ;
}
} else {
if ( V_92 > F_20 ( V_16 -> V_115 ) ) {
F_30 ( V_2 -> V_10 ,
L_12 ) ;
V_104 -> V_105 |= V_116 ;
return;
}
for ( V_72 = 0 ; V_72 < V_92 ; V_72 ++ ) {
V_16 -> V_115 [ V_72 ] =
F_13 ( V_2 , V_117 ) ;
}
F_71 ( V_83 , V_16 -> V_115 , V_92 ) ;
}
}
static void F_72 ( struct V_1 * V_2 )
{
const struct V_99 * V_100 = V_2 -> V_101 ;
struct V_82 * V_83 = V_2 -> V_84 ;
int V_92 ;
V_92 = V_100 -> V_118 / 2 ;
F_70 ( V_2 , V_83 , V_92 ) ;
}
static void F_73 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_82 * V_83 = V_2 -> V_84 ;
unsigned int V_111 ;
unsigned short V_3 ;
int V_72 ;
if ( V_16 -> V_112 ) {
while ( ( F_27 ( V_2 , V_86 ) &
V_87 ) == 0 ) {
V_111 = F_10 ( V_2 , V_113 ) ;
V_3 = V_111 >> 16 ;
F_71 ( V_83 , & V_3 , 1 ) ;
V_3 = V_111 & 0xffff ;
F_71 ( V_83 , & V_3 , 1 ) ;
}
} else if ( V_16 -> V_73 ) {
V_72 = 0 ;
while ( F_10 ( V_2 , V_75 ) & 0x04 ) {
V_111 = F_10 ( V_2 , V_114 ) ;
V_3 = V_111 >> 16 ;
F_71 ( V_83 , & V_3 , 1 ) ;
V_3 = V_111 & 0xffff ;
F_71 ( V_83 , & V_3 , 1 ) ;
V_72 += 2 ;
}
if ( F_10 ( V_2 , V_75 ) & 0x01 ) {
F_1 ( V_2 , 0x01 , V_74 ) ;
V_111 = F_10 ( V_2 , V_114 ) ;
V_3 = ( V_111 >> 16 ) & 0xffff ;
F_71 ( V_83 , & V_3 , 1 ) ;
}
} else {
unsigned short V_119 ;
V_119 = F_27 ( V_2 , V_86 ) &
V_87 ;
while ( V_119 == 0 ) {
for ( V_72 = 0 ;
V_72 < F_20 ( V_16 -> V_115 ) ; V_72 ++ ) {
V_119 = F_27 ( V_2 , V_86 ) &
V_87 ;
if ( V_119 )
break;
V_16 -> V_115 [ V_72 ] =
F_13 ( V_2 , V_117 ) ;
}
F_71 ( V_83 , V_16 -> V_115 , V_72 ) ;
}
}
}
static void F_74 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_82 * V_83 = V_2 -> V_84 ;
unsigned short V_3 ;
unsigned int V_111 ;
if ( ! V_16 -> V_112 )
return;
if ( F_16 ( V_2 , V_120 ) & 0x80 ) {
V_111 = F_10 ( V_2 , V_113 ) ;
V_3 = V_111 & 0xffff ;
F_71 ( V_83 , & V_3 , 1 ) ;
}
}
static void F_75 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_82 * V_83 = V_2 -> V_84 ;
unsigned short V_3 ;
unsigned int V_111 ;
if ( ! V_16 -> V_73 )
return;
if ( F_10 ( V_2 , V_75 ) & 0x01 ) {
F_1 ( V_2 , 0x01 , V_74 ) ;
V_111 = F_10 ( V_2 , V_114 ) ;
V_3 = ( V_111 >> 16 ) & 0xffff ;
F_71 ( V_83 , & V_3 , 1 ) ;
}
}
static void F_76 ( struct V_1 * V_2 )
{
struct V_82 * V_83 = V_2 -> V_84 ;
#ifdef F_45
F_60 ( V_2 ) ;
#endif
F_73 ( V_2 ) ;
F_74 ( V_2 ) ;
F_75 ( V_2 ) ;
V_83 -> V_104 -> V_105 |= V_121 ;
}
static void F_77 ( struct V_1 * V_2 , struct V_82 * V_83 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
if ( V_16 -> V_122 == V_123 ) {
#ifdef F_45
static const int V_71 = 10 ;
int V_72 ;
for ( V_72 = 0 ; V_72 < V_71 ; V_72 ++ ) {
F_58 ( V_2 ) ;
if ( ( V_83 -> V_104 -> V_105 & V_124 ) )
break;
F_52 ( 1 ) ;
}
#else
F_73 ( V_2 ) ;
V_83 -> V_104 -> V_105 |= V_124 ;
#endif
}
if ( V_16 -> V_125 & V_126 )
F_76 ( V_2 ) ;
}
static void F_78 ( struct V_1 * V_2 ,
unsigned short V_127 )
{
#ifdef F_45
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_82 * V_83 ;
V_83 = & V_2 -> V_128 [ F_79 ( V_127 ) ] ;
F_80 ( & V_16 -> V_60 -> V_61 [ V_127 ] ,
V_83 ) ;
F_81 ( V_2 , V_83 ) ;
#endif
}
static void F_82 ( struct V_1 * V_2 , unsigned short V_129 )
{
unsigned short V_130 = 0 ;
if ( V_129 & V_131 )
V_130 |= V_132 ;
if ( V_129 & V_133 )
V_130 |= V_134 ;
if ( V_129 & V_135 )
V_130 |= V_136 ;
if ( V_129 & V_137 )
V_130 |= V_138 ;
if ( V_130 )
F_23 ( V_2 , V_130 , V_139 ) ;
}
static void F_83 ( struct V_1 * V_2 ,
struct V_82 * V_83 ,
unsigned short V_140 )
{
struct V_141 * V_142 = & V_83 -> V_104 -> V_142 ;
if ( V_140 & ( V_143 |
V_131 | V_133 ) ) {
if ( V_140 == 0xffff ) {
F_30 ( V_2 -> V_10 , L_13 ) ;
if ( F_84 ( V_83 ) )
V_83 -> V_104 -> V_105 |= V_116 ;
return;
}
if ( V_140 & V_143 ) {
F_30 ( V_2 -> V_10 , L_14 ,
V_140 ) ;
F_76 ( V_2 ) ;
V_83 -> V_104 -> V_105 |= V_116 ;
if ( V_140 & V_144 )
V_83 -> V_104 -> V_105 |= V_106 ;
return;
}
if ( V_140 & V_131 ) {
if ( V_142 -> V_145 == V_146 )
F_76 ( V_2 ) ;
}
}
#ifndef F_45
if ( V_140 & V_147 ) {
int V_72 ;
static const int V_71 = 10 ;
for ( V_72 = 0 ; V_72 < V_71 ; ++ V_72 ) {
F_72 ( V_2 ) ;
if ( ( F_27 ( V_2 , V_86 ) &
V_147 ) == 0 )
break;
}
}
#endif
if ( V_140 & V_137 )
F_77 ( V_2 , V_83 ) ;
}
static void F_85 ( struct V_1 * V_2 , unsigned short V_88 )
{
unsigned short V_130 = 0 ;
if ( V_88 & V_148 )
V_130 |= V_149 ;
if ( V_88 & V_150 )
V_130 |= V_151 ;
if ( V_88 & V_152 )
V_130 |= V_153 ;
if ( V_88 & V_154 )
V_130 |= V_155 ;
if ( V_88 & V_156 )
V_130 |= V_157 ;
if ( V_88 & V_158 )
V_130 |= V_159 ;
if ( V_88 & V_160 )
V_130 |= V_161 ;
if ( V_130 )
F_23 ( V_2 , V_130 , V_162 ) ;
}
static void F_86 ( struct V_1 * V_2 ,
struct V_82 * V_83 ,
unsigned short V_88 )
{
if ( V_88 == 0xffff )
return;
if ( V_88 & V_150 ) {
F_30 ( V_2 -> V_10 ,
L_15 ,
V_88 , F_27 ( V_2 , V_163 ) ) ;
V_83 -> V_104 -> V_105 |= V_106 ;
}
if ( V_83 -> V_104 -> V_142 . V_145 != V_164 &&
V_88 & V_148 )
V_83 -> V_104 -> V_105 |= V_121 ;
#ifndef F_45
if ( V_88 & V_165 ) {
int V_166 ;
V_166 = F_66 ( V_2 , V_83 ) ;
if ( ! V_166 ) {
F_30 ( V_2 -> V_10 , L_16 ) ;
F_57 ( V_2 , V_30 ,
V_167 |
V_168 , 0 ) ;
V_83 -> V_104 -> V_105 |= V_106 ;
}
}
#endif
}
static void F_87 ( struct V_1 * V_2 , struct V_82 * V_83 ,
void * V_3 , unsigned int V_169 ,
unsigned int V_170 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_110 * V_104 = V_83 -> V_104 ;
struct V_141 * V_142 = & V_104 -> V_142 ;
unsigned int V_103 = F_68 ( V_83 , V_169 ) ;
unsigned short * V_171 = V_3 ;
unsigned int * V_172 = V_3 ;
unsigned int V_72 ;
#ifdef F_45
T_1 * V_173 = V_3 ;
T_2 * V_174 = V_3 ;
#endif
for ( V_72 = 0 ; V_72 < V_103 ; V_72 ++ ) {
#ifdef F_45
if ( V_83 -> V_175 & V_176 )
V_172 [ V_72 ] = F_88 ( V_174 [ V_72 ] ) ;
else
V_171 [ V_72 ] = F_89 ( V_173 [ V_72 ] ) ;
#endif
if ( V_83 -> V_175 & V_176 )
V_172 [ V_72 ] += V_16 -> V_177 [ V_170 ] ;
else
V_171 [ V_72 ] += V_16 -> V_177 [ V_170 ] ;
V_170 ++ ;
V_170 %= V_142 -> V_178 ;
}
}
static int F_90 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_82 * V_83 = V_2 -> V_84 ;
int V_85 ;
unsigned long V_18 ;
V_85 = F_32 ( V_2 ) ;
if ( V_85 )
return V_85 ;
F_91 ( V_83 , V_83 -> V_104 -> V_179 ) ;
F_24 ( & V_16 -> V_43 , V_18 ) ;
if ( ! V_16 -> V_48 ) {
F_25 ( & V_16 -> V_43 , V_18 ) ;
return - V_180 ;
}
if ( V_16 -> V_112 || V_16 -> V_73 )
F_92 ( V_16 -> V_48 , 32 , 16 ) ;
else if ( V_16 -> V_181 )
F_92 ( V_16 -> V_48 , 32 , 32 ) ;
else
F_92 ( V_16 -> V_48 , 16 , 16 ) ;
F_93 ( V_16 -> V_48 ) ;
F_25 ( & V_16 -> V_43 , V_18 ) ;
return 0 ;
}
static int F_94 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_82 * V_83 = V_2 -> V_182 ;
int V_85 ;
unsigned long V_18 ;
V_85 = F_36 ( V_2 ) ;
if ( V_85 )
return V_85 ;
F_95 ( V_83 , V_83 -> V_104 -> V_179 ) ;
F_24 ( & V_16 -> V_43 , V_18 ) ;
if ( V_16 -> V_53 ) {
if ( V_16 -> V_112 || V_16 -> V_183 ) {
F_92 ( V_16 -> V_53 , 32 , 32 ) ;
} else {
F_92 ( V_16 -> V_53 , 16 , 32 ) ;
}
F_93 ( V_16 -> V_53 ) ;
} else {
V_85 = - V_180 ;
}
F_25 ( & V_16 -> V_43 , V_18 ) ;
return V_85 ;
}
static int F_96 ( struct V_1 * V_2 , struct V_82 * V_83 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned int V_184 ;
unsigned int V_185 ;
F_44 ( V_2 ) ;
F_23 ( V_2 , V_186 | V_187 ,
V_188 ) ;
F_57 ( V_2 , V_28 , V_189 , 0 ) ;
F_51 ( V_2 ) ;
if ( ! V_16 -> V_73 )
F_7 ( V_2 , V_190 , V_191 ) ;
F_23 ( V_2 , V_192 , V_193 ) ;
F_23 ( V_2 , V_194 |
V_195
,
V_196 ) ;
F_23 ( V_2 , 0 , V_197 ) ;
F_23 ( V_2 , V_198 ,
V_199 ) ;
V_184 = V_200 |
V_201 |
V_202 ;
V_185 = F_97 ( 3 ) |
F_98 ( 0 ) |
F_99 ( 2 ) |
F_100 ( 3 ) ;
if ( V_16 -> V_112 ) {
V_185 |= V_203 ;
} else if ( V_16 -> V_73 ) {
V_185 |= V_204 ;
} else {
V_184 |= V_205 ;
if ( V_16 -> V_206 )
V_185 |= V_203 ;
else
V_185 |= V_204 ;
}
F_23 ( V_2 , V_184 , V_207 ) ;
F_23 ( V_2 , V_185 , V_208 ) ;
F_23 ( V_2 , V_209 , V_139 ) ;
F_23 ( V_2 , V_210 , V_188 ) ;
return 0 ;
}
static int F_101 ( struct V_1 * V_2 , struct V_82 * V_83 )
{
unsigned long V_18 ;
int V_211 ;
F_24 ( & V_2 -> V_212 , V_18 ) ;
#ifndef F_45
F_73 ( V_2 ) ;
#else
F_58 ( V_2 ) ;
#endif
V_211 = F_102 ( V_83 ) ;
F_25 ( & V_2 -> V_212 , V_18 ) ;
return V_211 ;
}
static void F_103 ( struct V_1 * V_2 )
{
int V_72 ;
F_23 ( V_2 , V_213 , V_193 ) ;
for ( V_72 = 0 ; V_72 < V_214 ; ++ V_72 ) {
if ( ! ( F_27 ( V_2 , V_86 ) &
V_87 ) ) {
F_23 ( V_2 , 1 , V_76 ) ;
return;
}
F_52 ( 1 ) ;
}
F_30 ( V_2 -> V_10 , L_17 ) ;
}
static void F_104 ( struct V_1 * V_2 ,
unsigned int V_215 ,
unsigned int * V_216 )
{
const struct V_99 * V_100 = V_2 -> V_101 ;
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned int V_217 , V_218 , V_219 ;
unsigned int V_72 ;
unsigned int V_220 ;
unsigned int V_221 ;
F_23 ( V_2 , 1 , V_222 ) ;
if ( ( V_216 [ 0 ] & V_223 ) ) {
unsigned int V_224 ;
V_217 = F_105 ( V_216 [ 0 ] ) ;
V_218 = F_106 ( V_216 [ 0 ] ) ;
V_221 = V_225 [ V_100 -> V_226 ] [ V_218 ] ;
V_220 = ( V_216 [ 0 ] & V_227 ) != 0 ;
V_224 = V_228 |
F_107 ( V_217 ) |
F_108 ( V_221 ) |
V_16 -> V_229 ;
if ( V_220 )
V_224 |= V_230 ;
V_224 |= V_231 ;
F_1 ( V_2 , V_224 , V_232 ) ;
} else {
F_1 ( V_2 , 0 , V_232 ) ;
}
for ( V_72 = 0 ; V_72 < V_215 ; V_72 ++ ) {
unsigned int V_233 = 0 ;
V_217 = F_105 ( V_216 [ V_72 ] ) ;
V_219 = F_109 ( V_216 [ V_72 ] ) ;
V_218 = F_106 ( V_216 [ V_72 ] ) ;
V_220 = ( V_216 [ V_72 ] & V_227 ) != 0 ;
V_221 = V_225 [ V_100 -> V_226 ] [ V_218 ] ;
V_16 -> V_177 [ V_72 ] = 0 ;
switch ( V_219 ) {
case V_234 :
V_233 |= V_235 ;
break;
case V_236 :
V_233 |= V_237 ;
break;
case V_238 :
V_233 |= V_239 ;
break;
case V_240 :
break;
}
V_233 |= F_110 ( V_217 ) ;
V_233 |= F_111 ( V_217 ) ;
V_233 |= F_112 ( V_221 ) ;
if ( V_72 == V_215 - 1 )
V_233 |= V_241 ;
if ( V_220 )
V_233 |= V_242 ;
V_233 |= V_243 ;
F_4 ( V_2 , V_233 , V_244 ) ;
}
F_103 ( V_2 ) ;
}
static void F_113 ( struct V_1 * V_2 ,
struct V_82 * V_83 ,
unsigned int V_215 , unsigned int * V_216 )
{
const struct V_99 * V_100 = V_2 -> V_101 ;
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned int V_245 = ( V_83 -> V_246 + 1 ) >> 1 ;
unsigned int V_217 , V_218 , V_219 ;
unsigned int V_72 ;
unsigned int V_247 , V_248 ;
unsigned int V_220 ;
if ( V_16 -> V_19 ) {
F_104 ( V_2 , V_215 , V_216 ) ;
return;
}
if ( V_215 == 1 && ! V_16 -> V_112 && ! V_16 -> V_73 ) {
if ( V_16 -> V_249 &&
V_16 -> V_250 == V_216 [ 0 ] ) {
return;
}
V_16 -> V_249 = 1 ;
V_16 -> V_250 = V_216 [ 0 ] ;
} else {
V_16 -> V_249 = 0 ;
}
F_23 ( V_2 , 1 , V_222 ) ;
if ( V_16 -> V_73 ) {
if ( ( V_216 [ 0 ] & V_223 ) &&
! V_16 -> V_251 ) {
F_4 ( V_2 , V_16 -> V_229 |
V_252 ,
V_253 ) ;
F_4 ( V_2 , V_16 -> V_229 ,
V_253 ) ;
V_16 -> V_251 = 1 ;
F_114 ( 100 ) ;
} else if ( ! ( V_216 [ 0 ] & V_223 ) &&
V_16 -> V_251 ) {
F_4 ( V_2 , V_16 -> V_229 |
V_254 ,
V_253 ) ;
F_4 ( V_2 , V_16 -> V_229 ,
V_253 ) ;
V_16 -> V_251 = 0 ;
F_114 ( 100 ) ;
}
}
for ( V_72 = 0 ; V_72 < V_215 ; V_72 ++ ) {
if ( ! V_16 -> V_73 && ( V_216 [ V_72 ] & V_223 ) )
V_217 = V_16 -> V_229 ;
else
V_217 = F_105 ( V_216 [ V_72 ] ) ;
V_219 = F_109 ( V_216 [ V_72 ] ) ;
V_218 = F_106 ( V_216 [ V_72 ] ) ;
V_220 = ( V_216 [ V_72 ] & V_227 ) != 0 ;
V_218 = V_225 [ V_100 -> V_226 ] [ V_218 ] ;
if ( V_16 -> V_112 )
V_16 -> V_177 [ V_72 ] = V_245 ;
else
V_16 -> V_177 [ V_72 ] = ( V_218 & 0x100 ) ? 0 : V_245 ;
V_247 = 0 ;
if ( ( V_216 [ V_72 ] & V_223 ) ) {
if ( V_16 -> V_112 )
F_4 ( V_2 , F_105 ( V_216 [ V_72 ] ) & 0x0003 ,
V_255 ) ;
} else {
if ( V_16 -> V_112 )
V_219 = V_234 ;
else if ( V_16 -> V_73 )
V_219 = V_240 ;
switch ( V_219 ) {
case V_234 :
V_247 |= V_256 ;
break;
case V_236 :
V_247 |= V_257 ;
break;
case V_238 :
V_247 |= V_258 ;
break;
case V_240 :
break;
}
}
V_247 |= F_115 ( V_217 ) ;
F_4 ( V_2 , V_247 , V_259 ) ;
if ( ! V_16 -> V_73 ) {
V_248 = F_116 ( V_218 ) ;
if ( V_72 == V_215 - 1 )
V_248 |= V_260 ;
if ( V_220 )
V_248 |= V_261 ;
F_4 ( V_2 , V_248 , V_262 ) ;
}
}
if ( ! V_16 -> V_112 && ! V_16 -> V_73 )
F_103 ( V_2 ) ;
}
static int F_117 ( struct V_1 * V_2 ,
struct V_82 * V_83 ,
struct V_263 * V_264 ,
unsigned int * V_3 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned int V_265 = ( V_83 -> V_246 + 1 ) >> 1 ;
int V_72 , V_92 ;
unsigned int V_266 ;
unsigned int V_93 ;
unsigned long V_111 ;
F_113 ( V_2 , V_83 , 1 , & V_264 -> V_267 ) ;
F_51 ( V_2 ) ;
V_266 = V_16 -> V_177 [ 0 ] ;
if ( V_16 -> V_112 ) {
for ( V_92 = 0 ; V_92 < V_268 ; V_92 ++ ) {
F_23 ( V_2 , V_213 ,
V_193 ) ;
F_52 ( 1 ) ;
}
for ( V_92 = 0 ; V_92 < V_264 -> V_92 ; V_92 ++ ) {
F_23 ( V_2 , V_213 ,
V_193 ) ;
V_93 = 0 ;
for ( V_72 = 0 ; V_72 < V_214 ; V_72 ++ ) {
if ( F_16 ( V_2 , V_120 ) & 0x80 ) {
V_93 = F_10 ( V_2 ,
V_113 ) ;
V_93 >>= 16 ;
V_93 &= 0xffff ;
break;
}
if ( ! ( F_27 ( V_2 , V_86 ) &
V_87 ) ) {
V_93 = F_10 ( V_2 ,
V_113 ) ;
V_93 &= 0xffff ;
break;
}
}
if ( V_72 == V_214 ) {
F_30 ( V_2 -> V_10 , L_18 ) ;
return - V_269 ;
}
V_93 += V_266 ;
V_3 [ V_92 ] = V_93 ;
}
} else if ( V_16 -> V_73 ) {
for ( V_92 = 0 ; V_92 < V_264 -> V_92 ; V_92 ++ ) {
F_23 ( V_2 , V_213 ,
V_193 ) ;
V_111 = 0 ;
for ( V_72 = 0 ; V_72 < V_214 ; V_72 ++ ) {
if ( F_10 ( V_2 , V_75 ) &
0x01 ) {
F_1 ( V_2 , 0x01 ,
V_74 ) ;
V_111 = F_10 ( V_2 ,
V_114 ) ;
break;
}
}
if ( V_72 == V_214 ) {
F_30 ( V_2 -> V_10 , L_18 ) ;
return - V_269 ;
}
V_3 [ V_92 ] = ( ( ( V_111 >> 16 ) & 0xFFFF ) + V_266 ) & 0xFFFF ;
}
} else {
for ( V_92 = 0 ; V_92 < V_264 -> V_92 ; V_92 ++ ) {
F_23 ( V_2 , V_213 ,
V_193 ) ;
for ( V_72 = 0 ; V_72 < V_214 ; V_72 ++ ) {
if ( ! ( F_27 ( V_2 , V_86 ) &
V_87 ) )
break;
}
if ( V_72 == V_214 ) {
F_30 ( V_2 -> V_10 , L_18 ) ;
return - V_269 ;
}
if ( V_16 -> V_19 ) {
V_111 = F_10 ( V_2 , V_270 ) ;
V_111 &= V_265 ;
V_3 [ V_92 ] = V_111 ;
} else {
V_93 = F_13 ( V_2 , V_117 ) ;
V_93 += V_266 ;
V_3 [ V_92 ] = V_93 ;
}
}
}
return V_264 -> V_92 ;
}
static int F_118 ( const struct V_1 * V_2 ,
unsigned int V_271 , unsigned int V_18 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
int V_272 ;
switch ( V_18 & V_273 ) {
case V_274 :
default:
V_272 = F_119 ( V_271 , V_16 -> V_275 ) ;
break;
case V_276 :
V_272 = ( V_271 ) / V_16 -> V_275 ;
break;
case V_277 :
V_272 = F_120 ( V_271 , V_16 -> V_275 ) ;
break;
}
return V_272 - 1 ;
}
static unsigned int F_121 ( const struct V_1 * V_2 , int V_278 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
return V_16 -> V_275 * ( V_278 + 1 ) ;
}
static void F_122 ( struct V_279 * V_280 ,
struct V_82 * V_281 ,
const struct V_141 * V_142 ,
unsigned int V_282 ) {
#ifdef F_45
unsigned int V_102 = V_282 ;
if ( V_142 -> V_283 > 0 && V_142 -> V_283 < V_282 )
V_102 = V_142 -> V_283 ;
V_102 *= F_123 ( V_281 ) ;
if ( V_102 > V_281 -> V_104 -> V_179 ) {
if ( V_142 -> V_283 > 0 )
F_30 ( V_281 -> V_284 -> V_10 ,
L_19 ) ;
V_102 = V_281 -> V_104 -> V_179 ;
}
F_124 ( V_280 , V_281 , V_102 ) ;
#else
F_30 ( V_281 -> V_284 -> V_10 ,
L_20 ) ;
#endif
}
static unsigned int F_125 ( struct V_1 * V_2 ,
unsigned int V_285 )
{
const struct V_99 * V_100 = V_2 -> V_101 ;
struct V_15 * V_16 = V_2 -> V_17 ;
if ( V_16 -> V_112 || V_16 -> V_73 )
return V_100 -> V_286 ;
return V_100 -> V_286 * V_285 ;
}
static int F_126 ( struct V_1 * V_2 , struct V_82 * V_83 ,
struct V_141 * V_142 )
{
const struct V_99 * V_100 = V_2 -> V_101 ;
struct V_15 * V_16 = V_2 -> V_17 ;
int V_287 = 0 ;
unsigned int V_288 ;
unsigned int V_289 ;
V_287 |= F_127 ( & V_142 -> V_290 ,
V_291 | V_292 | V_293 ) ;
V_287 |= F_127 ( & V_142 -> V_294 ,
V_295 | V_293 ) ;
V_289 = V_295 | V_293 ;
if ( V_16 -> V_112 || V_16 -> V_73 )
V_289 |= V_291 ;
V_287 |= F_127 ( & V_142 -> V_296 , V_289 ) ;
V_287 |= F_127 ( & V_142 -> V_297 , V_146 ) ;
V_287 |= F_127 ( & V_142 -> V_145 , V_146 | V_164 ) ;
if ( V_287 )
return 1 ;
V_287 |= F_128 ( V_142 -> V_290 ) ;
V_287 |= F_128 ( V_142 -> V_294 ) ;
V_287 |= F_128 ( V_142 -> V_296 ) ;
V_287 |= F_128 ( V_142 -> V_145 ) ;
if ( V_287 )
return 2 ;
switch ( V_142 -> V_290 ) {
case V_291 :
case V_292 :
V_287 |= F_129 ( & V_142 -> V_298 , 0 ) ;
break;
case V_293 :
V_288 = F_105 ( V_142 -> V_298 ) ;
if ( V_288 > 16 )
V_288 = 16 ;
V_288 |= ( V_142 -> V_298 & ( V_299 | V_300 ) ) ;
V_287 |= F_129 ( & V_142 -> V_298 , V_288 ) ;
break;
}
if ( V_142 -> V_294 == V_295 ) {
V_287 |= F_130 ( & V_142 -> V_301 ,
F_125 ( V_2 , V_142 -> V_178 ) ) ;
V_287 |= F_131 ( & V_142 -> V_301 ,
V_16 -> V_275 *
0xffffff ) ;
} else if ( V_142 -> V_294 == V_293 ) {
unsigned int V_288 = F_105 ( V_142 -> V_301 ) ;
if ( V_288 > 16 )
V_288 = 16 ;
V_288 |= ( V_142 -> V_301 & ( V_299 | V_300 ) ) ;
V_287 |= F_129 ( & V_142 -> V_301 , V_288 ) ;
} else {
V_287 |= F_129 ( & V_142 -> V_301 , 0 ) ;
}
if ( V_142 -> V_296 == V_295 ) {
if ( V_16 -> V_112 || V_16 -> V_73 ) {
V_287 |= F_129 ( & V_142 -> V_302 ,
0 ) ;
} else {
V_287 |= F_130 ( & V_142 -> V_302 ,
V_100 -> V_286 ) ;
V_287 |= F_131 ( & V_142 -> V_302 ,
V_16 -> V_275 *
0xffff ) ;
}
} else if ( V_142 -> V_296 == V_293 ) {
unsigned int V_288 = F_105 ( V_142 -> V_302 ) ;
if ( V_288 > 16 )
V_288 = 16 ;
V_288 |= ( V_142 -> V_302 & ( V_227 | V_299 ) ) ;
V_287 |= F_129 ( & V_142 -> V_302 , V_288 ) ;
} else if ( V_142 -> V_296 == V_291 ) {
V_287 |= F_129 ( & V_142 -> V_302 , 0 ) ;
}
V_287 |= F_129 ( & V_142 -> V_303 ,
V_142 -> V_178 ) ;
if ( V_142 -> V_145 == V_146 ) {
unsigned int V_282 = 0x01000000 ;
if ( V_16 -> V_112 )
V_282 -= V_268 ;
V_287 |= F_131 ( & V_142 -> V_283 , V_282 ) ;
V_287 |= F_130 ( & V_142 -> V_283 , 1 ) ;
} else {
V_287 |= F_129 ( & V_142 -> V_283 , 0 ) ;
}
if ( V_287 )
return 3 ;
if ( V_142 -> V_294 == V_295 ) {
V_288 = V_142 -> V_301 ;
V_142 -> V_301 =
F_121 ( V_2 , F_118 ( V_2 ,
V_142 -> V_301 ,
V_142 -> V_18 ) ) ;
if ( V_288 != V_142 -> V_301 )
V_287 ++ ;
}
if ( V_142 -> V_296 == V_295 ) {
if ( ! V_16 -> V_112 && ! V_16 -> V_73 ) {
V_288 = V_142 -> V_302 ;
V_142 -> V_302 =
F_121 ( V_2 , F_118 ( V_2 ,
V_142 -> V_302 ,
V_142 -> V_18 ) ) ;
if ( V_288 != V_142 -> V_302 )
V_287 ++ ;
if ( V_142 -> V_294 == V_295 &&
V_142 -> V_301 <
V_142 -> V_302 * V_142 -> V_303 ) {
V_142 -> V_301 =
V_142 -> V_302 * V_142 -> V_303 ;
V_287 ++ ;
}
}
}
if ( V_287 )
return 4 ;
return 0 ;
}
static int F_132 ( struct V_1 * V_2 ,
struct V_82 * V_83 ,
unsigned int V_304 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_141 * V_142 = & V_83 -> V_104 -> V_142 ;
if ( V_304 != V_142 -> V_298 )
return - V_305 ;
F_23 ( V_2 , V_306 | V_16 -> V_125 ,
V_307 ) ;
V_83 -> V_104 -> V_308 = NULL ;
return 1 ;
}
static int F_133 ( struct V_1 * V_2 , struct V_82 * V_83 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
const struct V_141 * V_142 = & V_83 -> V_104 -> V_142 ;
int V_278 ;
int V_309 = 0 ;
int V_310 = 0 ;
int V_311 = 0 ;
unsigned int V_312 ;
int V_313 = 0 ;
unsigned int V_314 ;
if ( V_2 -> V_315 == 0 ) {
F_30 ( V_2 -> V_10 , L_21 ) ;
return - V_180 ;
}
F_51 ( V_2 ) ;
F_113 ( V_2 , V_83 , V_142 -> V_178 , V_142 -> V_316 ) ;
F_23 ( V_2 , V_186 , V_188 ) ;
V_16 -> V_317 &= ~ V_318 ;
F_23 ( V_2 , V_16 -> V_317 , V_319 ) ;
V_314 = F_134 ( 0 ) | V_320 ;
switch ( V_142 -> V_290 ) {
case V_292 :
case V_291 :
V_314 |= V_321 |
F_135 ( 0 ) ;
break;
case V_293 :
V_314 |= F_135 ( F_105 ( V_142 -> V_298 ) +
1 ) ;
if ( V_142 -> V_298 & V_299 )
V_314 |= V_322 ;
if ( V_142 -> V_298 & V_300 )
V_314 |= V_321 ;
break;
}
F_23 ( V_2 , V_314 , V_323 ) ;
V_310 &= ~ V_324 ;
V_310 &= ~ V_325 ;
V_310 &= ~ V_326 ;
F_23 ( V_2 , V_310 , V_197 ) ;
if ( V_142 -> V_178 == 1 || V_16 -> V_112 || V_16 -> V_73 ) {
V_311 |= V_327 |
F_136 ( 31 ) |
V_328 ;
} else {
V_311 |= F_136 ( 19 ) ;
}
F_23 ( V_2 , V_311 , V_329 ) ;
V_16 -> V_125 = 0 ;
switch ( V_142 -> V_145 ) {
case V_146 :
V_312 = V_142 -> V_283 - 1 ;
if ( V_16 -> V_112 ) {
V_312 += V_268 ;
}
F_26 ( V_2 , V_312 , V_330 ) ;
V_309 |= V_194 |
V_195 |
V_331 ;
F_23 ( V_2 , V_309 , V_196 ) ;
F_23 ( V_2 , V_332 , V_193 ) ;
if ( V_312 == 0 ) {
V_16 -> V_125 |= V_126 ;
V_313 |= V_333 ;
if ( V_142 -> V_178 > 1 )
V_311 |= V_327 |
V_334 ;
}
break;
case V_164 :
F_26 ( V_2 , 0 , V_330 ) ;
V_309 |= V_194 |
V_195 |
V_335 ;
F_23 ( V_2 , V_309 , V_196 ) ;
F_23 ( V_2 , V_332 , V_193 ) ;
break;
}
switch ( V_142 -> V_294 ) {
case V_295 :
V_311 |= V_336 | V_337 ;
F_23 ( V_2 , V_311 , V_329 ) ;
V_310 &= ~ V_338 ;
V_310 |= F_137 ( 0 ) ;
F_23 ( V_2 , V_310 , V_197 ) ;
V_278 = F_118 ( V_2 , V_142 -> V_301 ,
V_274 ) ;
F_26 ( V_2 , V_278 , V_339 ) ;
F_23 ( V_2 , V_340 , V_193 ) ;
break;
case V_293 :
if ( V_142 -> V_301 & V_300 )
V_311 |= V_336 ;
if ( V_142 -> V_301 & V_299 )
V_311 |= V_341 ;
if ( V_142 -> V_294 != V_142 -> V_296 ||
( V_142 -> V_301 & ~ V_300 ) !=
( V_142 -> V_302 & ~ V_300 ) )
V_311 |= V_337 ;
V_311 |=
F_138 ( 1 + F_105 ( V_142 -> V_301 ) ) ;
F_23 ( V_2 , V_311 , V_329 ) ;
break;
}
switch ( V_142 -> V_296 ) {
case V_295 :
case V_291 :
if ( V_142 -> V_302 == 0 || V_142 -> V_296 == V_291 )
V_278 = 1 ;
else
V_278 = F_118 ( V_2 , V_142 -> V_302 ,
V_274 ) ;
F_23 ( V_2 , 1 , V_342 ) ;
F_23 ( V_2 , V_278 , V_343 ) ;
V_310 &= ~ V_344 ;
V_310 |= V_345 ;
F_23 ( V_2 , V_310 , V_197 ) ;
F_23 ( V_2 , V_346 , V_193 ) ;
V_310 |= V_344 ;
V_310 |= V_345 ;
F_23 ( V_2 , V_310 , V_197 ) ;
break;
case V_293 :
V_309 |= F_139 ( 1 +
F_105 ( V_142 -> V_302 ) ) ;
if ( ( V_142 -> V_302 & V_299 ) == 0 )
V_309 |= V_347 ;
F_23 ( V_2 , V_309 , V_196 ) ;
V_310 |= V_348 |
V_349 ;
F_23 ( V_2 , V_310 , V_197 ) ;
break;
}
if ( V_2 -> V_315 ) {
V_313 |= V_350 |
V_351 ;
#ifndef F_45
V_313 |= V_352 ;
#endif
if ( ( V_142 -> V_18 & V_353 ) ||
( V_16 -> V_125 & V_126 ) ) {
V_16 -> V_122 = V_123 ;
} else {
V_16 -> V_122 = V_354 ;
}
switch ( V_16 -> V_122 ) {
case V_354 :
#ifdef F_45
F_23 ( V_2 , V_355 ,
V_199 ) ;
#else
F_23 ( V_2 , V_356 ,
V_199 ) ;
#endif
break;
case V_357 :
F_23 ( V_2 , V_198 ,
V_199 ) ;
break;
case V_123 :
#ifdef F_45
F_23 ( V_2 , V_198 ,
V_199 ) ;
#else
F_23 ( V_2 , V_356 ,
V_199 ) ;
#endif
V_313 |= V_333 ;
break;
default:
break;
}
F_23 ( V_2 , V_209 , V_139 ) ;
F_57 ( V_2 , V_28 , V_313 , 1 ) ;
} else {
F_57 ( V_2 , V_28 , ~ 0 , 0 ) ;
}
F_23 ( V_2 , V_210 , V_188 ) ;
switch ( V_142 -> V_294 ) {
case V_295 :
F_23 ( V_2 , V_358 |
V_359 |
V_360 |
V_361 ,
V_193 ) ;
break;
case V_293 :
F_23 ( V_2 , V_358 |
V_359 |
V_360 |
V_361 ,
V_193 ) ;
break;
}
#ifdef F_45
{
int V_85 = F_90 ( V_2 ) ;
if ( V_85 )
return V_85 ;
}
#endif
if ( V_142 -> V_290 == V_291 ) {
F_23 ( V_2 , V_306 |
V_16 -> V_125 ,
V_307 ) ;
V_83 -> V_104 -> V_308 = NULL ;
} else if ( V_142 -> V_290 == V_293 ) {
V_83 -> V_104 -> V_308 = NULL ;
} else {
V_83 -> V_104 -> V_308 = F_132 ;
}
return 0 ;
}
static int F_140 ( struct V_1 * V_2 ,
struct V_82 * V_83 ,
struct V_263 * V_264 , unsigned int * V_3 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
if ( V_264 -> V_92 < 1 )
return - V_305 ;
switch ( V_3 [ 0 ] ) {
case V_362 :
if ( V_16 -> V_19 ) {
if ( V_3 [ 1 ] & ~ V_363 )
return - V_305 ;
V_16 -> V_229 = V_3 [ 1 ] ;
} else if ( V_16 -> V_73 ) {
unsigned int V_364 ;
V_364 = V_3 [ 1 ] & 0xf ;
V_16 -> V_229 = V_364 ;
F_4 ( V_2 , V_364 , V_253 ) ;
} else {
unsigned int V_364 ;
unsigned int V_365 ;
V_364 = V_3 [ 1 ] & 0xf ;
V_365 = ( V_3 [ 1 ] >> 4 ) & 0xff ;
if ( V_364 >= 8 )
return - V_305 ;
V_16 -> V_229 = V_364 ;
if ( V_16 -> V_112 ) {
F_7 ( V_2 , V_365 ,
V_366 ) ;
}
}
return 2 ;
default:
break;
}
return - V_305 ;
}
static void F_141 ( struct V_1 * V_2 , struct V_82 * V_83 ,
void * V_3 , unsigned int V_169 ,
unsigned int V_170 )
{
struct V_141 * V_142 = & V_83 -> V_104 -> V_142 ;
unsigned int V_103 = F_68 ( V_83 , V_169 ) ;
unsigned short * V_171 = V_3 ;
unsigned int V_72 ;
#ifdef F_45
T_1 V_367 , * V_173 = V_3 ;
#endif
for ( V_72 = 0 ; V_72 < V_103 ; V_72 ++ ) {
unsigned int V_218 = F_106 ( V_142 -> V_316 [ V_170 ] ) ;
unsigned short V_24 = V_171 [ V_72 ] ;
if ( F_142 ( V_83 , V_218 ) )
V_24 = F_143 ( V_83 , V_24 ) ;
#ifdef F_45
V_367 = F_144 ( V_24 ) ;
V_173 [ V_72 ] = V_367 ;
#else
V_171 [ V_72 ] = V_24 ;
#endif
V_170 ++ ;
V_170 %= V_142 -> V_178 ;
}
}
static int F_145 ( struct V_1 * V_2 ,
struct V_82 * V_83 ,
unsigned int V_267 [] ,
unsigned int V_368 , int V_369 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned int V_218 ;
unsigned int V_217 ;
unsigned int V_370 ;
int V_72 ;
int V_371 = 0 ;
if ( V_369 ) {
for ( V_72 = 0 ; V_72 < V_83 -> V_215 ; ++ V_72 ) {
V_16 -> V_372 [ V_72 ] &= ~ V_373 ;
F_7 ( V_2 , V_16 -> V_372 [ V_72 ] ,
F_146 ( V_72 ) ) ;
F_7 ( V_2 , 0xf , F_147 ( V_72 ) ) ;
}
}
for ( V_72 = 0 ; V_72 < V_368 ; V_72 ++ ) {
const struct V_374 * V_375 ;
V_217 = F_105 ( V_267 [ V_72 ] ) ;
V_218 = F_106 ( V_267 [ V_72 ] ) ;
V_375 = V_83 -> V_376 -> V_218 + V_218 ;
V_371 = 0 ;
V_370 = 0 ;
switch ( V_375 -> V_377 - V_375 -> V_378 ) {
case 20000000 :
V_370 |= V_379 ;
F_7 ( V_2 , 0 , F_148 ( V_217 ) ) ;
break;
case 10000000 :
V_370 |= V_380 ;
F_7 ( V_2 , 0 , F_148 ( V_217 ) ) ;
break;
case 4000000 :
V_370 |= V_379 ;
F_7 ( V_2 , V_381 ,
F_148 ( V_217 ) ) ;
break;
case 2000000 :
V_370 |= V_380 ;
F_7 ( V_2 , V_381 ,
F_148 ( V_217 ) ) ;
break;
default:
F_30 ( V_2 -> V_10 ,
L_22 ) ;
break;
}
switch ( V_375 -> V_377 + V_375 -> V_378 ) {
case 0 :
V_370 |= V_382 ;
break;
case 10000000 :
V_370 |= V_383 ;
break;
default:
F_30 ( V_2 -> V_10 ,
L_23 ) ;
break;
}
if ( V_369 )
V_370 |= V_373 ;
F_7 ( V_2 , V_370 , F_146 ( V_217 ) ) ;
V_16 -> V_372 [ V_217 ] = V_370 ;
F_7 ( V_2 , V_72 , F_147 ( V_217 ) ) ;
}
return V_371 ;
}
static int F_149 ( struct V_1 * V_2 ,
struct V_82 * V_83 ,
unsigned int V_267 [] ,
unsigned int V_368 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned int V_218 ;
unsigned int V_217 ;
unsigned int V_370 ;
int V_72 ;
int V_371 = 0 ;
for ( V_72 = 0 ; V_72 < V_368 ; V_72 ++ ) {
V_217 = F_105 ( V_267 [ V_72 ] ) ;
V_218 = F_106 ( V_267 [ V_72 ] ) ;
V_370 = F_150 ( V_217 ) ;
if ( F_142 ( V_83 , V_218 ) ) {
V_370 |= V_384 ;
V_371 = ( V_83 -> V_246 + 1 ) >> 1 ;
} else {
V_371 = 0 ;
}
if ( F_151 ( V_83 , V_218 ) )
V_370 |= V_385 ;
if ( V_267 [ V_72 ] & V_386 )
V_370 |= V_387 ;
if ( F_109 ( V_267 [ V_72 ] ) == V_240 )
V_370 |= V_388 ;
F_4 ( V_2 , V_370 , V_389 ) ;
V_16 -> V_372 [ V_217 ] = V_370 ;
}
return V_371 ;
}
static int F_152 ( struct V_1 * V_2 ,
struct V_82 * V_83 ,
unsigned int V_267 [] , unsigned int V_368 ,
int V_369 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
if ( V_16 -> V_19 )
return F_145 ( V_2 , V_83 , V_267 , V_368 ,
V_369 ) ;
else
return F_149 ( V_2 , V_83 , V_267 , V_368 ) ;
}
static int F_153 ( struct V_1 * V_2 ,
struct V_82 * V_83 ,
struct V_263 * V_264 ,
unsigned int * V_3 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned int V_217 = F_105 ( V_264 -> V_267 ) ;
unsigned int V_218 = F_106 ( V_264 -> V_267 ) ;
int V_4 ;
int V_72 ;
if ( V_16 -> V_95 ) {
F_54 ( V_2 , 1 << V_217 , V_390 ) ;
V_4 = F_154 ( V_217 ) ;
} else if ( V_16 -> V_19 ) {
V_4 = F_155 ( V_217 ) ;
} else {
V_4 = F_156 ( V_217 ) ;
}
F_152 ( V_2 , V_83 , & V_264 -> V_267 , 1 , 0 ) ;
for ( V_72 = 0 ; V_72 < V_264 -> V_92 ; V_72 ++ ) {
unsigned int V_24 = V_3 [ V_72 ] ;
V_83 -> V_391 [ V_217 ] = V_24 ;
if ( V_16 -> V_95 ) {
V_24 = F_143 ( V_83 , V_24 ) ;
F_54 ( V_2 , V_24 , V_4 ) ;
} else if ( V_16 -> V_19 ) {
F_4 ( V_2 , V_24 , V_4 ) ;
} else {
if ( F_142 ( V_83 , V_218 ) )
V_24 = F_143 ( V_83 , V_24 ) ;
F_4 ( V_2 , V_24 , V_4 ) ;
}
}
return V_264 -> V_92 ;
}
static int F_157 ( struct V_1 * V_2 ,
struct V_82 * V_83 ,
struct V_263 * V_264 , unsigned int * V_3 )
{
const struct V_99 * V_100 = V_2 -> V_101 ;
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned int V_102 ;
switch ( V_3 [ 0 ] ) {
case V_392 :
switch ( V_3 [ 1 ] ) {
case V_52 :
V_102 = F_158 ( V_83 ,
V_100 -> V_107 ) ;
V_3 [ 2 ] = 1 + V_102 ;
if ( V_16 -> V_21 )
V_3 [ 2 ] += V_16 -> V_21 -> V_393 ;
break;
case V_47 :
V_3 [ 2 ] = 0 ;
break;
default:
return - V_305 ;
}
return 0 ;
default:
break;
}
return - V_305 ;
}
static int F_159 ( struct V_1 * V_2 ,
struct V_82 * V_83 ,
unsigned int V_304 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_141 * V_142 = & V_83 -> V_104 -> V_142 ;
int V_166 ;
int V_394 ;
int V_72 ;
static const int V_71 = 1000 ;
if ( ! ( V_304 == V_142 -> V_298 ||
( V_304 == 0 && V_142 -> V_290 != V_292 ) ) )
return - V_305 ;
V_83 -> V_104 -> V_308 = NULL ;
F_57 ( V_2 , V_30 ,
V_167 | V_168 , 0 ) ;
V_394 = V_168 ;
#ifdef F_45
F_23 ( V_2 , 1 , V_108 ) ;
if ( V_16 -> V_95 )
F_55 ( V_2 , 0x6 , V_109 ) ;
V_166 = F_94 ( V_2 ) ;
if ( V_166 )
return V_166 ;
V_166 = F_62 ( V_2 ) ;
if ( V_166 < 0 )
return V_166 ;
#else
V_166 = F_69 ( V_2 , V_83 ) ;
if ( V_166 == 0 )
return - V_91 ;
V_394 |= V_167 ;
#endif
F_23 ( V_2 , V_16 -> V_395 | V_396 ,
V_397 ) ;
F_23 ( V_2 , V_16 -> V_395 , V_397 ) ;
for ( V_72 = 0 ; V_72 < V_71 ; V_72 ++ ) {
F_52 ( 1 ) ;
if ( ( F_27 ( V_2 , V_398 ) &
V_399 ) == 0 )
break;
}
if ( V_72 == V_71 ) {
F_30 ( V_2 -> V_10 ,
L_24 ) ;
return - V_180 ;
}
F_23 ( V_2 , V_151 , V_162 ) ;
F_57 ( V_2 , V_30 , V_394 , 1 ) ;
F_23 ( V_2 , V_400 |
V_401 |
V_402 |
V_16 -> V_403 ,
V_404 ) ;
F_23 ( V_2 , V_405 | V_16 -> V_406 ,
V_407 ) ;
return 0 ;
}
static void F_160 ( struct V_1 * V_2 ,
const struct V_141 * V_142 )
{
const struct V_99 * V_100 = V_2 -> V_101 ;
unsigned int V_42 ;
F_23 ( V_2 , V_408 , V_188 ) ;
V_42 =
V_409 |
0 |
V_410 |
V_411 |
( V_100 -> V_107 ?
V_412 : V_413 )
;
#if 0
if (devpriv->is_m_series)
bits |= NISTC_AO_PERSONAL_NUM_DAC;
#endif
F_23 ( V_2 , V_42 , V_414 ) ;
F_23 ( V_2 , V_415 , V_188 ) ;
}
static void F_161 ( struct V_1 * V_2 ,
const struct V_141 * V_142 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned int V_416 ;
F_23 ( V_2 , V_408 , V_188 ) ;
if ( V_142 -> V_145 == V_164 ) {
V_16 -> V_417 |= V_418 ;
V_16 -> V_417 &= ~ V_419 ;
} else {
V_16 -> V_417 &= ~ V_418 ;
V_16 -> V_417 |= V_419 ;
}
F_23 ( V_2 , V_16 -> V_417 , V_420 ) ;
if ( V_142 -> V_290 == V_292 ) {
V_416 = V_421 |
V_422 ;
} else {
V_416 = F_162 ( F_105 ( V_142 -> V_298 ) + 1 ) ;
if ( V_142 -> V_298 & V_299 )
V_416 |= V_423 ;
if ( V_142 -> V_298 & V_300 )
V_416 |= V_421 ;
}
F_23 ( V_2 , V_416 , V_424 ) ;
V_16 -> V_395 &= ~ V_425 ;
F_23 ( V_2 , V_16 -> V_395 , V_397 ) ;
F_23 ( V_2 , V_415 , V_188 ) ;
}
static void F_163 ( struct V_1 * V_2 ,
const struct V_141 * V_142 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
F_23 ( V_2 , V_408 , V_188 ) ;
F_23 ( V_2 , V_16 -> V_417 , V_420 ) ;
V_16 -> V_426 &= ~ V_427 ;
F_23 ( V_2 , V_16 -> V_426 , V_428 ) ;
F_26 ( V_2 , 0 , V_429 ) ;
F_23 ( V_2 , V_430 , V_404 ) ;
V_16 -> V_426 &= ~ V_431 ;
F_23 ( V_2 , V_16 -> V_426 , V_428 ) ;
{
unsigned int V_283 = V_142 -> V_283 > 0 ?
( V_142 -> V_283 & 0xffffff ) : 0xffffff ;
if ( V_16 -> V_19 ) {
F_26 ( V_2 , V_283 - 1 , V_432 ) ;
F_23 ( V_2 , V_433 ,
V_404 ) ;
} else {
F_26 ( V_2 , V_283 , V_432 ) ;
F_23 ( V_2 , V_433 ,
V_404 ) ;
F_26 ( V_2 , V_283 - 1 , V_432 ) ;
}
}
F_23 ( V_2 , V_415 , V_188 ) ;
}
static void F_164 ( struct V_1 * V_2 ,
const struct V_141 * V_142 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
F_23 ( V_2 , V_408 , V_188 ) ;
V_16 -> V_417 &= ~ (
V_434 |
V_435 |
V_436 |
V_437
) ;
if ( V_142 -> V_294 == V_295 ) {
unsigned int V_438 ;
V_16 -> V_406 &= ~ V_439 ;
V_438 = F_118 ( V_2 , V_142 -> V_301 ,
V_274 ) ;
F_26 ( V_2 , 1 , V_440 ) ;
F_23 ( V_2 , V_441 , V_404 ) ;
F_26 ( V_2 , V_438 - 1 , V_440 ) ;
} else {
V_16 -> V_406 |= V_439 ;
V_16 -> V_417 |= F_165 (
F_105 ( V_142 -> V_301 ) ) ;
if ( V_142 -> V_301 & V_299 )
V_16 -> V_417 |= V_437 ;
}
F_23 ( V_2 , V_16 -> V_406 , V_407 ) ;
F_23 ( V_2 , V_16 -> V_417 , V_420 ) ;
V_16 -> V_426 &= ~ ( F_166 ( 3 ) |
V_442 ) ;
F_23 ( V_2 , V_16 -> V_426 , V_428 ) ;
V_16 -> V_403 |= V_443 |
V_444 ;
F_23 ( V_2 , V_16 -> V_403 , V_404 ) ;
F_23 ( V_2 , V_415 , V_188 ) ;
}
static void F_167 ( struct V_1 * V_2 ,
struct V_82 * V_83 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
const struct V_141 * V_142 = & V_83 -> V_104 -> V_142 ;
unsigned int V_42 = 0 ;
F_23 ( V_2 , V_408 , V_188 ) ;
if ( V_16 -> V_95 ) {
unsigned int V_72 ;
V_42 = 0 ;
for ( V_72 = 0 ; V_72 < V_142 -> V_178 ; ++ V_72 ) {
int V_217 = F_105 ( V_142 -> V_316 [ V_72 ] ) ;
V_42 |= 1 << V_217 ;
F_54 ( V_2 , V_217 , V_445 ) ;
}
F_54 ( V_2 , V_42 , V_446 ) ;
}
F_152 ( V_2 , V_83 , V_142 -> V_316 , V_142 -> V_178 , 1 ) ;
if ( V_142 -> V_303 > 1 ) {
V_16 -> V_417 |= V_447 ;
V_42 = F_168 ( V_142 -> V_303 - 1 )
| V_448 ;
} else {
V_16 -> V_417 &= ~ V_447 ;
V_42 = V_448 ;
if ( V_16 -> V_19 | V_16 -> V_95 )
V_42 |= F_168 ( 0 ) ;
else
V_42 |= F_168 (
F_105 ( V_142 -> V_316 [ 0 ] ) ) ;
}
F_23 ( V_2 , V_16 -> V_417 , V_420 ) ;
F_23 ( V_2 , V_42 , V_449 ) ;
F_23 ( V_2 , V_415 , V_188 ) ;
}
static void F_169 ( struct V_1 * V_2 ,
const struct V_141 * V_142 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
F_23 ( V_2 , V_408 , V_188 ) ;
V_16 -> V_395 |= V_450 ;
F_23 ( V_2 , V_16 -> V_395 , V_397 ) ;
F_23 ( V_2 , V_415 , V_188 ) ;
}
static void F_170 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
F_23 ( V_2 , V_408 , V_188 ) ;
V_16 -> V_426 &= ~ V_451 ;
#ifdef F_45
V_16 -> V_426 |= V_452 ;
#else
V_16 -> V_426 |= V_453 ;
#endif
V_16 -> V_426 &= ~ V_454 ;
F_23 ( V_2 , V_16 -> V_426 , V_428 ) ;
F_23 ( V_2 , V_455 , V_456 ) ;
F_23 ( V_2 , V_415 , V_188 ) ;
}
static void F_171 ( struct V_1 * V_2 ,
struct V_82 * V_83 )
{
if ( V_83 -> V_104 -> V_142 . V_145 == V_146 )
F_57 ( V_2 , V_30 ,
V_457 , 1 ) ;
V_83 -> V_104 -> V_308 = F_159 ;
}
static int F_172 ( struct V_1 * V_2 , struct V_82 * V_83 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
const struct V_141 * V_142 = & V_83 -> V_104 -> V_142 ;
if ( V_2 -> V_315 == 0 ) {
F_30 ( V_2 -> V_10 , L_25 ) ;
return - V_180 ;
}
F_160 ( V_2 , V_142 ) ;
F_161 ( V_2 , V_142 ) ;
F_163 ( V_2 , V_142 ) ;
F_164 ( V_2 , V_142 ) ;
F_167 ( V_2 , V_83 ) ;
F_169 ( V_2 , V_142 ) ;
F_170 ( V_2 ) ;
F_122 ( V_16 -> V_51 , V_83 , V_142 , 0x00ffffff ) ;
F_171 ( V_2 , V_83 ) ;
return 0 ;
}
static int F_173 ( struct V_1 * V_2 , struct V_82 * V_83 ,
struct V_141 * V_142 )
{
const struct V_99 * V_100 = V_2 -> V_101 ;
struct V_15 * V_16 = V_2 -> V_17 ;
int V_287 = 0 ;
unsigned int V_288 ;
V_287 |= F_127 ( & V_142 -> V_290 , V_292 | V_293 ) ;
V_287 |= F_127 ( & V_142 -> V_294 ,
V_295 | V_293 ) ;
V_287 |= F_127 ( & V_142 -> V_296 , V_291 ) ;
V_287 |= F_127 ( & V_142 -> V_297 , V_146 ) ;
V_287 |= F_127 ( & V_142 -> V_145 , V_146 | V_164 ) ;
if ( V_287 )
return 1 ;
V_287 |= F_128 ( V_142 -> V_290 ) ;
V_287 |= F_128 ( V_142 -> V_294 ) ;
V_287 |= F_128 ( V_142 -> V_145 ) ;
if ( V_287 )
return 2 ;
switch ( V_142 -> V_290 ) {
case V_292 :
V_287 |= F_129 ( & V_142 -> V_298 , 0 ) ;
break;
case V_293 :
V_288 = F_105 ( V_142 -> V_298 ) ;
if ( V_288 > 18 )
V_288 = 18 ;
V_288 |= ( V_142 -> V_298 & ( V_299 | V_300 ) ) ;
V_287 |= F_129 ( & V_142 -> V_298 , V_288 ) ;
break;
}
if ( V_142 -> V_294 == V_295 ) {
V_287 |= F_130 ( & V_142 -> V_301 ,
V_100 -> V_458 ) ;
V_287 |= F_131 ( & V_142 -> V_301 ,
V_16 -> V_275 *
0xffffff ) ;
}
V_287 |= F_129 ( & V_142 -> V_302 , 0 ) ;
V_287 |= F_129 ( & V_142 -> V_303 ,
V_142 -> V_178 ) ;
V_287 |= F_131 ( & V_142 -> V_283 , 0x00ffffff ) ;
if ( V_287 )
return 3 ;
if ( V_142 -> V_294 == V_295 ) {
V_288 = V_142 -> V_301 ;
V_142 -> V_301 =
F_121 ( V_2 , F_118 ( V_2 ,
V_142 -> V_301 ,
V_142 -> V_18 ) ) ;
if ( V_288 != V_142 -> V_301 )
V_287 ++ ;
}
if ( V_287 )
return 4 ;
return 0 ;
}
static int F_174 ( struct V_1 * V_2 , struct V_82 * V_83 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
F_47 ( V_2 ) ;
if ( V_16 -> V_19 )
F_23 ( V_2 , V_459 , V_188 ) ;
F_23 ( V_2 , V_408 , V_188 ) ;
F_23 ( V_2 , V_460 , V_404 ) ;
V_16 -> V_403 = 0 ;
V_16 -> V_406 = 0 ;
V_16 -> V_417 = 0 ;
V_16 -> V_426 = 0 ;
if ( V_16 -> V_19 )
V_16 -> V_395 = V_461 ;
else
V_16 -> V_395 = 0 ;
F_23 ( V_2 , 0 , V_414 ) ;
F_23 ( V_2 , 0 , V_404 ) ;
F_23 ( V_2 , 0 , V_407 ) ;
F_23 ( V_2 , 0 , V_420 ) ;
F_23 ( V_2 , 0 , V_428 ) ;
F_23 ( V_2 , 0 , V_449 ) ;
F_23 ( V_2 , V_16 -> V_395 , V_397 ) ;
F_23 ( V_2 , 0 , V_456 ) ;
F_23 ( V_2 , 0 , V_424 ) ;
F_57 ( V_2 , V_30 , ~ 0 , 0 ) ;
F_23 ( V_2 , V_409 , V_414 ) ;
F_23 ( V_2 , V_462 , V_162 ) ;
if ( V_16 -> V_95 ) {
F_54 ( V_2 , ( 1u << V_83 -> V_215 ) - 1u ,
V_390 ) ;
F_54 ( V_2 , V_463 ,
V_464 ) ;
}
F_23 ( V_2 , V_415 , V_188 ) ;
return 0 ;
}
static int F_175 ( struct V_1 * V_2 ,
struct V_82 * V_83 ,
struct V_263 * V_264 ,
unsigned int * V_3 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
int V_166 ;
V_166 = F_176 ( V_2 , V_83 , V_264 , V_3 , 0 ) ;
if ( V_166 )
return V_166 ;
V_16 -> V_465 &= ~ V_466 ;
V_16 -> V_465 |= F_177 ( V_83 -> V_467 ) ;
F_23 ( V_2 , V_16 -> V_465 , V_468 ) ;
return V_264 -> V_92 ;
}
static int F_178 ( struct V_1 * V_2 ,
struct V_82 * V_83 ,
struct V_263 * V_264 ,
unsigned int * V_3 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
if ( ( V_3 [ 0 ] & ( V_469 | V_470 ) ) &&
V_16 -> V_471 )
return - V_45 ;
if ( F_179 ( V_83 , V_3 ) ) {
V_16 -> V_472 &= ~ V_473 ;
V_16 -> V_472 |= F_180 ( V_83 -> V_474 ) ;
F_23 ( V_2 , V_16 -> V_472 , V_475 ) ;
}
V_3 [ 1 ] = F_27 ( V_2 , V_476 ) ;
return V_264 -> V_92 ;
}
static int F_181 ( struct V_1 * V_2 ,
struct V_82 * V_83 ,
struct V_263 * V_264 ,
unsigned int * V_3 )
{
int V_166 ;
V_166 = F_176 ( V_2 , V_83 , V_264 , V_3 , 0 ) ;
if ( V_166 )
return V_166 ;
F_1 ( V_2 , V_83 -> V_467 , V_477 ) ;
return V_264 -> V_92 ;
}
static int F_182 ( struct V_1 * V_2 ,
struct V_82 * V_83 ,
struct V_263 * V_264 ,
unsigned int * V_3 )
{
if ( F_179 ( V_83 , V_3 ) )
F_1 ( V_2 , V_83 -> V_474 , V_478 ) ;
V_3 [ 1 ] = F_10 ( V_2 , V_478 ) ;
return V_264 -> V_92 ;
}
static int F_183 ( struct V_1 * V_2 ,
struct V_82 * V_83 ,
struct V_141 * V_142 )
{
int V_72 ;
for ( V_72 = 0 ; V_72 < V_142 -> V_178 ; ++ V_72 ) {
unsigned int V_217 = F_105 ( V_142 -> V_316 [ V_72 ] ) ;
if ( V_217 != V_72 )
return - V_305 ;
}
return 0 ;
}
static int F_184 ( struct V_1 * V_2 ,
struct V_82 * V_83 , struct V_141 * V_142 )
{
int V_287 = 0 ;
int V_288 ;
V_287 |= F_127 ( & V_142 -> V_290 , V_292 ) ;
V_287 |= F_127 ( & V_142 -> V_294 , V_293 ) ;
V_287 |= F_127 ( & V_142 -> V_296 , V_291 ) ;
V_287 |= F_127 ( & V_142 -> V_297 , V_146 ) ;
V_287 |= F_127 ( & V_142 -> V_145 , V_164 ) ;
if ( V_287 )
return 1 ;
V_287 |= F_129 ( & V_142 -> V_298 , 0 ) ;
V_288 = V_142 -> V_301 ;
V_288 &= F_185 ( V_479 , 0 , 0 , V_299 ) ;
if ( V_288 != V_142 -> V_301 )
V_287 |= - V_305 ;
V_287 |= F_129 ( & V_142 -> V_302 , 0 ) ;
V_287 |= F_129 ( & V_142 -> V_303 ,
V_142 -> V_178 ) ;
V_287 |= F_131 ( & V_142 -> V_283 ,
V_83 -> V_104 -> V_179 /
F_123 ( V_83 ) ) ;
if ( V_287 )
return 3 ;
if ( V_142 -> V_316 && V_142 -> V_178 > 0 )
V_287 |= F_183 ( V_2 , V_83 , V_142 ) ;
if ( V_287 )
return 5 ;
return 0 ;
}
static int F_186 ( struct V_1 * V_2 ,
struct V_82 * V_83 ,
unsigned int V_304 )
{
struct V_141 * V_142 = & V_83 -> V_104 -> V_142 ;
const unsigned int V_71 = 1000 ;
int V_85 = 0 ;
unsigned int V_72 ;
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned long V_18 ;
if ( V_304 != V_142 -> V_298 )
return - V_305 ;
V_83 -> V_104 -> V_308 = NULL ;
F_95 ( V_83 , V_83 -> V_104 -> V_179 ) ;
F_24 ( & V_16 -> V_43 , V_18 ) ;
if ( V_16 -> V_64 ) {
F_92 ( V_16 -> V_64 , 32 , 32 ) ;
F_93 ( V_16 -> V_64 ) ;
} else {
F_30 ( V_2 -> V_10 , L_26 ) ;
V_85 = - V_180 ;
}
F_25 ( & V_16 -> V_43 , V_18 ) ;
if ( V_85 < 0 )
return V_85 ;
for ( V_72 = 0 ; V_72 < V_71 ; ++ V_72 ) {
if ( F_10 ( V_2 , V_480 ) &
V_481 )
break;
F_63 ( 10 , 100 ) ;
}
if ( V_72 == V_71 ) {
F_30 ( V_2 -> V_10 , L_27 ) ;
V_83 -> V_482 ( V_2 , V_83 ) ;
return - V_180 ;
}
F_1 ( V_2 , V_483 |
V_484 |
V_485 ,
V_486 ) ;
return V_85 ;
}
static int F_187 ( struct V_1 * V_2 , struct V_82 * V_83 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
const struct V_141 * V_142 = & V_83 -> V_104 -> V_142 ;
unsigned int V_487 ;
int V_85 ;
F_1 ( V_2 , V_488 , V_486 ) ;
V_487 = V_489 |
V_490 |
F_188 ( F_105 ( V_142 -> V_301 ) ) ;
if ( V_142 -> V_301 & V_299 )
V_487 |= V_491 ;
F_1 ( V_2 , V_487 , V_492 ) ;
if ( V_83 -> V_467 ) {
F_1 ( V_2 , V_83 -> V_474 , V_493 ) ;
F_1 ( V_2 , V_494 , V_486 ) ;
F_1 ( V_2 , V_83 -> V_467 , V_495 ) ;
} else {
F_30 ( V_2 -> V_10 ,
L_28 ) ;
return - V_180 ;
}
V_85 = F_42 ( V_2 ) ;
if ( V_85 < 0 )
return V_85 ;
F_122 ( V_16 -> V_63 , V_83 , V_142 ,
V_83 -> V_104 -> V_179 /
F_123 ( V_83 ) ) ;
V_83 -> V_104 -> V_308 = F_186 ;
return 0 ;
}
static int F_189 ( struct V_1 * V_2 , struct V_82 * V_83 )
{
F_1 ( V_2 , V_496 |
V_497 |
V_498 |
V_499 ,
V_486 ) ;
F_1 ( V_2 , 0 , V_495 ) ;
F_49 ( V_2 ) ;
return 0 ;
}
static void F_190 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned int V_500 ;
struct V_82 * V_83 = & V_2 -> V_128 [ V_501 ] ;
unsigned long V_18 ;
F_24 ( & V_16 -> V_43 , V_18 ) ;
if ( V_16 -> V_64 )
F_191 ( V_16 -> V_64 , V_83 , true ) ;
F_25 ( & V_16 -> V_43 , V_18 ) ;
V_500 = F_10 ( V_2 , V_480 ) ;
if ( V_500 & V_502 ) {
F_1 ( V_2 , V_503 ,
V_486 ) ;
V_83 -> V_104 -> V_105 |= V_106 ;
}
if ( V_500 & V_504 ) {
F_1 ( V_2 , V_498 ,
V_486 ) ;
}
F_81 ( V_2 , V_83 ) ;
}
static int F_192 ( struct V_1 * V_2 ,
struct V_82 * V_83 ,
unsigned char V_505 ,
unsigned char * V_506 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned int V_507 ;
int V_287 = 0 , V_211 = 20 ;
V_16 -> V_472 &= ~ V_508 ;
V_16 -> V_472 |= F_193 ( V_505 ) ;
F_23 ( V_2 , V_16 -> V_472 , V_475 ) ;
V_507 = F_27 ( V_2 , V_509 ) ;
if ( V_507 & V_510 ) {
V_287 = - V_45 ;
goto error;
}
V_16 -> V_465 |= V_511 ;
F_23 ( V_2 , V_16 -> V_465 , V_468 ) ;
V_16 -> V_465 &= ~ V_511 ;
while ( ( V_507 = F_27 ( V_2 , V_509 ) ) &
V_510 ) {
F_52 ( ( V_16 -> V_471 + 999 ) / 1000 ) ;
if ( -- V_211 < 0 ) {
F_30 ( V_2 -> V_10 ,
L_29 ) ;
V_287 = - V_269 ;
goto error;
}
}
F_52 ( ( V_16 -> V_471 + 999 ) / 1000 ) ;
if ( V_506 )
* V_506 = F_27 ( V_2 , V_512 ) ;
error:
F_23 ( V_2 , V_16 -> V_465 , V_468 ) ;
return V_287 ;
}
static int F_194 ( struct V_1 * V_2 ,
struct V_82 * V_83 ,
unsigned char V_505 ,
unsigned char * V_506 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned char V_265 , V_513 = 0 ;
F_52 ( ( V_16 -> V_471 + 999 ) / 1000 ) ;
for ( V_265 = 0x80 ; V_265 ; V_265 >>= 1 ) {
V_16 -> V_472 &= ~ V_470 ;
if ( V_505 & V_265 )
V_16 -> V_472 |= V_470 ;
F_23 ( V_2 , V_16 -> V_472 , V_475 ) ;
V_16 -> V_465 |= V_514 ;
F_23 ( V_2 , V_16 -> V_465 , V_468 ) ;
F_52 ( ( V_16 -> V_471 + 999 ) / 2000 ) ;
V_16 -> V_465 &= ~ V_514 ;
F_23 ( V_2 , V_16 -> V_465 , V_468 ) ;
F_52 ( ( V_16 -> V_471 + 999 ) / 2000 ) ;
if ( F_27 ( V_2 , V_476 ) & V_469 )
V_513 |= V_265 ;
}
if ( V_506 )
* V_506 = V_513 ;
return 0 ;
}
static int F_195 ( struct V_1 * V_2 ,
struct V_82 * V_83 ,
struct V_263 * V_264 ,
unsigned int * V_3 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned int V_515 = V_16 -> V_516 ;
int V_287 = V_264 -> V_92 ;
unsigned char V_517 , V_518 = 0 ;
if ( V_264 -> V_92 != 2 )
return - V_305 ;
switch ( V_3 [ 0 ] ) {
case V_519 :
V_16 -> V_520 = 1 ;
V_16 -> V_465 |= V_521 ;
if ( V_3 [ 1 ] == V_522 ) {
V_16 -> V_520 = 0 ;
V_16 -> V_465 &= ~ ( V_521 |
V_514 ) ;
V_3 [ 1 ] = V_522 ;
V_16 -> V_471 = V_3 [ 1 ] ;
} else if ( V_3 [ 1 ] <= V_523 ) {
V_16 -> V_465 &= ~ V_524 ;
V_515 |= V_525 ;
V_515 &= ~ V_526 ;
V_3 [ 1 ] = V_523 ;
V_16 -> V_471 = V_3 [ 1 ] ;
} else if ( V_3 [ 1 ] <= V_527 ) {
V_16 -> V_465 &= ~ V_524 ;
V_515 |= V_525 |
V_526 ;
V_3 [ 1 ] = V_527 ;
V_16 -> V_471 = V_3 [ 1 ] ;
} else if ( V_3 [ 1 ] <= V_528 ) {
V_16 -> V_465 |= V_524 ;
V_515 |= V_525 |
V_526 ;
V_3 [ 1 ] = V_528 ;
V_16 -> V_471 = V_3 [ 1 ] ;
} else {
V_16 -> V_465 &= ~ ( V_521 |
V_514 ) ;
V_16 -> V_520 = 0 ;
V_3 [ 1 ] = ( V_3 [ 1 ] / 1000 ) * 1000 ;
V_16 -> V_471 = V_3 [ 1 ] ;
}
V_16 -> V_516 = V_515 ;
F_23 ( V_2 , V_16 -> V_465 , V_468 ) ;
F_23 ( V_2 , V_16 -> V_516 , V_529 ) ;
return 1 ;
case V_530 :
if ( V_16 -> V_471 == 0 )
return - V_305 ;
V_517 = V_3 [ 1 ] & 0xFF ;
if ( V_16 -> V_520 ) {
V_287 = F_192 ( V_2 , V_83 , V_517 ,
& V_518 ) ;
} else if ( V_16 -> V_471 > 0 ) {
V_287 = F_194 ( V_2 , V_83 , V_517 ,
& V_518 ) ;
} else {
F_30 ( V_2 -> V_10 , L_30 ) ;
return - V_305 ;
}
if ( V_287 < 0 )
return V_287 ;
V_3 [ 1 ] = V_518 & 0xFF ;
return V_264 -> V_92 ;
break;
default:
return - V_305 ;
}
}
static void F_196 ( struct V_1 * V_2 , struct V_82 * V_83 )
{
int V_72 ;
for ( V_72 = 0 ; V_72 < V_83 -> V_215 ; V_72 ++ ) {
F_54 ( V_2 , F_150 ( V_72 ) | 0x0 ,
V_531 ) ;
}
F_54 ( V_2 , 0x0 , V_532 ) ;
}
static unsigned int F_197 ( struct V_1 * V_2 ,
enum V_533 V_4 )
{
const struct V_7 * V_8 ;
if ( V_4 < F_20 ( V_534 ) ) {
V_8 = & V_534 [ V_4 ] ;
} else {
F_21 ( V_2 -> V_10 , L_1 ,
V_11 , V_4 ) ;
return 0 ;
}
return V_8 -> V_13 ;
}
static void F_198 ( struct V_58 * V_59 , unsigned int V_42 ,
enum V_533 V_4 )
{
struct V_1 * V_2 = V_59 -> V_60 -> V_2 ;
unsigned int V_535 = F_197 ( V_2 , V_4 ) ;
if ( V_535 == 0 )
return;
switch ( V_4 ) {
case V_536 :
case V_537 :
case V_538 :
case V_539 :
case V_540 :
case V_541 :
case V_542 :
case V_543 :
F_4 ( V_2 , V_42 , V_535 ) ;
break;
case V_544 :
case V_545 :
case V_546 :
case V_547 :
F_26 ( V_2 , V_42 , V_535 ) ;
break;
case V_548 :
F_29 ( V_2 , V_535 ,
V_68 | V_549 ,
V_42 ) ;
break;
case V_550 :
F_29 ( V_2 , V_535 ,
V_70 | V_551 ,
V_42 ) ;
break;
default:
F_23 ( V_2 , V_42 , V_535 ) ;
}
}
static unsigned int F_199 ( struct V_58 * V_59 ,
enum V_533 V_4 )
{
struct V_1 * V_2 = V_59 -> V_60 -> V_2 ;
unsigned int V_535 = F_197 ( V_2 , V_4 ) ;
if ( V_535 == 0 )
return 0 ;
switch ( V_4 ) {
case V_552 :
case V_553 :
return F_13 ( V_2 , V_535 ) ;
case V_554 :
case V_555 :
case V_556 :
case V_557 :
return F_28 ( V_2 , V_535 ) ;
default:
return F_27 ( V_2 , V_535 ) ;
}
}
static int F_200 ( struct V_1 * V_2 ,
struct V_82 * V_83 ,
struct V_263 * V_264 ,
unsigned int * V_3 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned int V_24 = F_201 ( V_16 -> V_516 ) ;
int V_72 ;
for ( V_72 = 0 ; V_72 < V_264 -> V_92 ; V_72 ++ )
V_3 [ V_72 ] = V_24 ;
return V_264 -> V_92 ;
}
static int F_202 ( struct V_1 * V_2 ,
struct V_82 * V_83 ,
struct V_263 * V_264 ,
unsigned int * V_3 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
if ( V_264 -> V_92 ) {
unsigned int V_24 = V_3 [ V_264 -> V_92 - 1 ] ;
V_16 -> V_516 &= ~ V_558 ;
F_23 ( V_2 , V_16 -> V_516 , V_529 ) ;
V_16 -> V_516 &= ~ V_559 ;
V_16 -> V_516 |= F_203 ( V_24 ) ;
V_16 -> V_516 |= V_558 ;
F_23 ( V_2 , V_16 -> V_516 , V_529 ) ;
}
return V_264 -> V_92 ;
}
static int F_204 ( struct V_1 * V_2 ,
struct V_82 * V_83 ,
struct V_263 * V_264 ,
unsigned int * V_3 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
switch ( V_3 [ 0 ] ) {
case V_560 :
switch ( V_3 [ 1 ] ) {
case V_561 :
V_16 -> V_516 &= ~ V_562 ;
break;
case V_563 :
V_16 -> V_516 |= V_562 ;
break;
default:
return - V_305 ;
}
F_23 ( V_2 , V_16 -> V_516 , V_529 ) ;
break;
case V_564 :
if ( V_16 -> V_516 & V_562 ) {
V_3 [ 1 ] = V_563 ;
V_3 [ 2 ] = V_565 ;
} else {
V_3 [ 1 ] = V_561 ;
V_3 [ 2 ] = V_566 * 2 ;
}
break;
default:
return - V_305 ;
}
return V_264 -> V_92 ;
}
static int F_205 ( struct V_1 * V_2 ,
int V_46 , int V_567 , int V_3 , unsigned long V_6 )
{
if ( V_46 ) {
F_7 ( V_2 , V_3 , V_6 + 2 * V_567 ) ;
return 0 ;
}
return F_16 ( V_2 , V_6 + 2 * V_567 ) ;
}
static int F_206 ( struct V_1 * V_2 , unsigned int * V_3 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
V_3 [ 1 ] = V_16 -> V_568 * V_16 -> V_275 ;
V_3 [ 2 ] = V_16 -> V_569 * V_16 -> V_275 ;
return 3 ;
}
static int F_207 ( struct V_1 * V_2 ,
struct V_82 * V_83 ,
struct V_263 * V_264 ,
unsigned int * V_3 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned int V_570 , V_571 ;
switch ( V_3 [ 0 ] ) {
case V_572 :
switch ( V_3 [ 1 ] ) {
case V_274 :
V_570 = F_119 ( V_3 [ 2 ] ,
V_16 -> V_275 ) ;
break;
case V_276 :
V_570 = V_3 [ 2 ] / V_16 -> V_275 ;
break;
case V_277 :
V_570 =
F_120 ( V_3 [ 2 ] , V_16 -> V_275 ) ;
break;
default:
return - V_305 ;
}
switch ( V_3 [ 3 ] ) {
case V_274 :
V_571 = F_119 ( V_3 [ 4 ] ,
V_16 -> V_275 ) ;
break;
case V_276 :
V_571 = V_3 [ 4 ] / V_16 -> V_275 ;
break;
case V_277 :
V_571 =
F_120 ( V_3 [ 4 ] , V_16 -> V_275 ) ;
break;
default:
return - V_305 ;
}
if ( V_570 * V_16 -> V_275 != V_3 [ 2 ] ||
V_571 * V_16 -> V_275 != V_3 [ 4 ] ) {
V_3 [ 2 ] = V_570 * V_16 -> V_275 ;
V_3 [ 4 ] = V_571 * V_16 -> V_275 ;
return - V_573 ;
}
F_1 ( V_2 , F_208 ( V_570 ) |
F_209 ( V_571 ) ,
V_574 ) ;
V_16 -> V_568 = V_570 ;
V_16 -> V_569 = V_571 ;
return 5 ;
case V_575 :
return F_206 ( V_2 , V_3 ) ;
default:
return - V_305 ;
}
return 0 ;
}
static int F_210 ( struct V_1 * V_2 ,
struct V_82 * V_83 ,
struct V_263 * V_264 ,
unsigned int * V_3 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned int V_570 , V_571 ;
switch ( V_3 [ 0 ] ) {
case V_572 :
switch ( V_3 [ 1 ] ) {
case V_274 :
V_570 = F_119 ( V_3 [ 2 ] ,
V_16 -> V_275 ) ;
break;
case V_276 :
V_570 = V_3 [ 2 ] / V_16 -> V_275 ;
break;
case V_277 :
V_570 =
F_120 ( V_3 [ 2 ] , V_16 -> V_275 ) ;
break;
default:
return - V_305 ;
}
switch ( V_3 [ 3 ] ) {
case V_274 :
V_571 = F_119 ( V_3 [ 4 ] ,
V_16 -> V_275 ) ;
break;
case V_276 :
V_571 = V_3 [ 4 ] / V_16 -> V_275 ;
break;
case V_277 :
V_571 =
F_120 ( V_3 [ 4 ] , V_16 -> V_275 ) ;
break;
default:
return - V_305 ;
}
if ( V_570 * V_16 -> V_275 != V_3 [ 2 ] ||
V_571 * V_16 -> V_275 != V_3 [ 4 ] ) {
V_3 [ 2 ] = V_570 * V_16 -> V_275 ;
V_3 [ 4 ] = V_571 * V_16 -> V_275 ;
return - V_573 ;
}
F_1 ( V_2 , V_570 , V_576 ) ;
V_16 -> V_568 = V_570 ;
F_1 ( V_2 , V_571 , V_577 ) ;
V_16 -> V_569 = V_571 ;
return 5 ;
case V_575 :
return F_206 ( V_2 , V_3 ) ;
default:
return - V_305 ;
}
return 0 ;
}
static int F_211 ( int V_78 , int V_24 , int * V_578 )
{
V_78 ++ ;
* V_578 = ( ( V_78 & 0x1 ) << 11 ) |
( ( V_78 & 0x2 ) << 9 ) |
( ( V_78 & 0x4 ) << 7 ) | ( ( V_78 & 0x8 ) << 5 ) | ( V_24 & 0xff ) ;
return 12 ;
}
static int F_212 ( int V_78 , int V_24 , int * V_578 )
{
* V_578 = ( ( V_78 & 0x7 ) << 8 ) | ( V_24 & 0xff ) ;
return 11 ;
}
static int F_213 ( int V_78 , int V_24 , int * V_578 )
{
* V_578 = V_24 & 0xfff ;
return 12 ;
}
static int F_214 ( int V_78 , int V_24 , int * V_578 )
{
* V_578 = ( V_24 & 0xfff ) | ( V_78 ? 0xc000 : 0xa000 ) ;
return 16 ;
}
static int F_215 ( int V_78 , int V_24 , int * V_578 )
{
* V_578 = ( ( V_78 & 0xf ) << 8 ) | ( V_24 & 0xff ) ;
return 12 ;
}
static int F_216 ( int V_78 , int V_24 , int * V_578 )
{
* V_578 = ( ( V_78 + 1 ) << 8 ) | ( V_24 & 0xff ) ;
return 12 ;
}
static void F_217 ( struct V_1 * V_2 , int V_78 , int V_24 )
{
const struct V_99 * V_100 = V_2 -> V_101 ;
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned int V_579 = 0 , V_42 = 0 , V_580 , V_578 = 0 ;
unsigned int V_142 ;
int V_72 ;
int type ;
if ( V_16 -> V_581 [ V_78 ] == V_24 )
return;
V_16 -> V_581 [ V_78 ] = V_24 ;
for ( V_72 = 0 ; V_72 < 3 ; V_72 ++ ) {
type = V_100 -> V_582 [ V_72 ] ;
if ( type == V_583 )
break;
if ( V_78 < V_581 [ type ] . V_368 ) {
V_42 = V_581 [ type ] . F_218 ( V_78 , V_24 , & V_578 ) ;
V_579 = F_219 ( V_72 ) ;
break;
}
V_78 -= V_581 [ type ] . V_368 ;
}
if ( V_42 == 0 )
return;
for ( V_580 = 1 << ( V_42 - 1 ) ; V_580 ; V_580 >>= 1 ) {
V_142 = ( V_580 & V_578 ) ? V_584 : 0 ;
F_7 ( V_2 , V_142 , V_585 ) ;
F_52 ( 1 ) ;
F_7 ( V_2 , V_586 | V_142 , V_585 ) ;
F_52 ( 1 ) ;
}
F_7 ( V_2 , V_579 , V_585 ) ;
F_52 ( 1 ) ;
F_7 ( V_2 , 0 , V_585 ) ;
}
static int F_220 ( struct V_1 * V_2 ,
struct V_82 * V_83 ,
struct V_263 * V_264 ,
unsigned int * V_3 )
{
F_217 ( V_2 , F_105 ( V_264 -> V_267 ) , V_3 [ 0 ] ) ;
return 1 ;
}
static int F_221 ( struct V_1 * V_2 ,
struct V_82 * V_83 ,
struct V_263 * V_264 ,
unsigned int * V_3 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
V_3 [ 0 ] = V_16 -> V_581 [ F_105 ( V_264 -> V_267 ) ] ;
return 1 ;
}
static void F_222 ( struct V_1 * V_2 , struct V_82 * V_83 )
{
const struct V_99 * V_100 = V_2 -> V_101 ;
struct V_15 * V_16 = V_2 -> V_17 ;
int V_72 , V_587 ;
int V_588 ;
int V_368 = 0 ;
int V_589 ;
int V_590 = 0 ;
int type ;
int V_217 ;
type = V_100 -> V_582 [ 0 ] ;
if ( type == V_583 )
return;
V_589 = V_581 [ type ] . V_589 ;
for ( V_72 = 0 ; V_72 < 3 ; V_72 ++ ) {
type = V_100 -> V_582 [ V_72 ] ;
if ( type == V_583 )
break;
if ( V_581 [ type ] . V_589 != V_589 )
V_590 = 1 ;
V_368 += V_581 [ type ] . V_368 ;
}
V_588 = V_72 ;
V_83 -> V_215 = V_368 ;
if ( V_590 ) {
unsigned int * V_591 = V_16 -> V_592 ;
if ( V_368 > V_593 )
F_30 ( V_2 -> V_10 ,
L_31 ) ;
V_83 -> V_591 = V_591 ;
V_217 = 0 ;
for ( V_72 = 0 ; V_72 < V_588 ; V_72 ++ ) {
type = V_100 -> V_582 [ V_72 ] ;
for ( V_587 = 0 ; V_587 < V_581 [ type ] . V_368 ; V_587 ++ ) {
V_591 [ V_217 ] =
( 1 << V_581 [ type ] . V_589 ) - 1 ;
V_217 ++ ;
}
}
for ( V_217 = 0 ; V_217 < V_83 -> V_215 ; V_217 ++ )
F_217 ( V_2 , V_72 , V_83 -> V_591 [ V_72 ] / 2 ) ;
} else {
type = V_100 -> V_582 [ 0 ] ;
V_83 -> V_246 = ( 1 << V_581 [ type ] . V_589 ) - 1 ;
for ( V_217 = 0 ; V_217 < V_83 -> V_215 ; V_217 ++ )
F_217 ( V_2 , V_72 , V_83 -> V_246 / 2 ) ;
}
}
static int F_223 ( struct V_1 * V_2 , int V_78 )
{
unsigned int V_142 = V_594 ;
int V_580 ;
int V_578 ;
V_578 = 0x0300 | ( ( V_78 & 0x100 ) << 3 ) | ( V_78 & 0xff ) ;
F_7 ( V_2 , V_142 , V_585 ) ;
for ( V_580 = 0x8000 ; V_580 ; V_580 >>= 1 ) {
if ( V_580 & V_578 )
V_142 |= V_584 ;
else
V_142 &= ~ V_584 ;
F_7 ( V_2 , V_142 , V_585 ) ;
F_7 ( V_2 , V_586 | V_142 , V_585 ) ;
}
V_142 = V_594 ;
V_578 = 0 ;
for ( V_580 = 0x80 ; V_580 ; V_580 >>= 1 ) {
F_7 ( V_2 , V_142 , V_585 ) ;
F_7 ( V_2 , V_586 | V_142 , V_585 ) ;
if ( F_16 ( V_2 , V_120 ) & V_595 )
V_578 |= V_580 ;
}
F_7 ( V_2 , 0 , V_585 ) ;
return V_578 ;
}
static int F_224 ( struct V_1 * V_2 ,
struct V_82 * V_83 ,
struct V_263 * V_264 ,
unsigned int * V_3 )
{
V_3 [ 0 ] = F_223 ( V_2 , F_105 ( V_264 -> V_267 ) ) ;
return 1 ;
}
static int F_225 ( struct V_1 * V_2 ,
struct V_82 * V_83 ,
struct V_263 * V_264 ,
unsigned int * V_3 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
V_3 [ 0 ] = V_16 -> V_596 [ F_105 ( V_264 -> V_267 ) ] ;
return 1 ;
}
static unsigned int F_226 ( struct V_1 * V_2 ,
unsigned int V_217 )
{
switch ( V_217 ) {
case 0 :
return V_597 ;
case 1 :
return V_598 ;
case 2 :
return V_599 ;
case 3 :
return V_600 ;
case 4 :
return V_601 ;
case 5 :
return V_602 ;
case 6 :
return V_603 ;
case 7 :
return V_604 ;
case 8 :
return V_605 ;
case 9 :
return V_606 ;
default:
F_30 ( V_2 -> V_10 , L_32 ) ;
break;
}
return 0 ;
}
static int F_227 ( struct V_1 * V_2 ,
unsigned int V_217 , unsigned int V_607 )
{
if ( V_607 != F_226 ( V_2 , V_217 ) )
return - V_305 ;
return 2 ;
}
static unsigned int F_228 ( struct V_1 * V_2 ,
unsigned int V_217 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
const unsigned int V_608 = V_217 / 3 ;
return F_229 ( V_217 ,
V_16 -> V_609 [ V_608 ] ) ;
}
static int F_230 ( struct V_1 * V_2 ,
unsigned int V_217 , unsigned int V_607 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned int V_610 = V_217 / 3 ;
unsigned short V_24 = V_16 -> V_609 [ V_610 ] ;
if ( ( V_607 & 0x1f ) != V_607 )
return - V_305 ;
V_24 &= ~ F_231 ( V_217 ) ;
V_24 |= F_232 ( V_217 , V_607 ) ;
F_4 ( V_2 , V_24 , F_233 ( V_610 ) ) ;
V_16 -> V_609 [ V_610 ] = V_24 ;
return 2 ;
}
static unsigned int F_234 ( struct V_1 * V_2 ,
unsigned int V_217 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
return ( V_16 -> V_19 )
? F_228 ( V_2 , V_217 )
: F_226 ( V_2 , V_217 ) ;
}
static int F_235 ( struct V_1 * V_2 ,
unsigned int V_217 , unsigned int V_607 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
return ( V_16 -> V_19 )
? F_230 ( V_2 , V_217 , V_607 )
: F_227 ( V_2 , V_217 , V_607 ) ;
}
static int F_236 ( struct V_1 * V_2 ,
unsigned int V_611 ,
enum V_612 V_613 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned int V_42 ;
if ( ! V_16 -> V_19 )
return - V_614 ;
V_42 = F_10 ( V_2 , V_615 ) ;
V_42 &= ~ F_237 ( V_611 ) ;
V_42 |= F_238 ( V_611 , V_613 ) ;
F_1 ( V_2 , V_42 , V_615 ) ;
return 0 ;
}
static int F_239 ( struct V_1 * V_2 ,
struct V_82 * V_83 ,
struct V_263 * V_264 ,
unsigned int * V_3 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned int V_217 ;
if ( V_264 -> V_92 < 1 )
return - V_305 ;
V_217 = F_105 ( V_264 -> V_267 ) ;
switch ( V_3 [ 0 ] ) {
case V_52 :
F_57 ( V_2 , V_32 , 1 << V_217 , 1 ) ;
break;
case V_47 :
F_57 ( V_2 , V_32 , 1 << V_217 , 0 ) ;
break;
case V_616 :
V_3 [ 1 ] =
( V_16 -> V_33 & ( 1 << V_217 ) ) ?
V_52 : V_47 ;
return 0 ;
case V_617 :
return F_235 ( V_2 , V_217 , V_3 [ 1 ] ) ;
case V_618 :
V_3 [ 1 ] = F_234 ( V_2 , V_217 ) ;
break;
case V_619 :
return F_236 ( V_2 , V_217 , V_3 [ 1 ] ) ;
default:
return - V_305 ;
}
return 0 ;
}
static int F_240 ( struct V_1 * V_2 ,
struct V_82 * V_83 ,
struct V_263 * V_264 ,
unsigned int * V_3 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
if ( ! V_16 -> V_19 )
return - V_614 ;
if ( F_179 ( V_83 , V_3 ) )
F_4 ( V_2 , V_83 -> V_474 , V_620 ) ;
V_3 [ 1 ] = F_13 ( V_2 , V_621 ) ;
return V_264 -> V_92 ;
}
static int F_241 ( struct V_1 * V_2 )
{
unsigned short V_140 ;
const int V_71 = V_622 ;
int V_72 ;
for ( V_72 = 0 ; V_72 < V_71 ; V_72 ++ ) {
V_140 = F_56 ( V_2 , V_623 ) ;
if ( ( V_140 & V_624 ) == 0 )
break;
F_242 ( V_625 ) ;
if ( F_243 ( 1 ) )
return - V_180 ;
}
if ( V_72 == V_71 ) {
F_30 ( V_2 -> V_10 , L_18 ) ;
return - V_269 ;
}
return 0 ;
}
static void F_244 ( struct V_1 * V_2 , unsigned short V_81 )
{
static const int V_71 = 100 ;
int V_72 ;
F_54 ( V_2 , V_81 , V_626 ) ;
for ( V_72 = 0 ; V_72 < V_71 ; V_72 ++ ) {
if ( F_56 ( V_2 , V_623 ) &
V_624 )
break;
F_52 ( 1 ) ;
}
if ( V_72 == V_71 )
F_30 ( V_2 -> V_10 ,
L_33 ) ;
}
static int F_245 ( struct V_1 * V_2 ,
unsigned short * V_3 )
{
int V_85 ;
unsigned short V_140 ;
F_244 ( V_2 , V_627 | V_628 ) ;
V_85 = F_241 ( V_2 ) ;
if ( V_85 ) {
F_30 ( V_2 -> V_10 ,
L_34 ) ;
return - V_269 ;
}
V_140 = F_56 ( V_2 , V_623 ) ;
if ( V_140 & V_629 ) {
F_30 ( V_2 -> V_10 ,
L_35 ) ;
return - V_180 ;
}
if ( V_140 & V_630 ) {
F_30 ( V_2 -> V_10 ,
L_36 ) ;
}
if ( V_3 ) {
* V_3 = F_56 ( V_2 , V_631 ) ;
* V_3 ^= ( 1 << 15 ) ;
}
return 0 ;
}
static int F_246 ( struct V_1 * V_2 ,
struct V_82 * V_83 ,
struct V_263 * V_264 ,
unsigned int * V_3 )
{
int V_92 , V_85 ;
unsigned short V_632 ;
unsigned int V_633 ;
const unsigned int V_634 = 0x1000 ;
if ( V_264 -> V_267 & V_223 )
V_633 = V_634 ;
else
V_633 = F_105 ( V_264 -> V_267 ) ;
F_54 ( V_2 , V_633 , V_635 ) ;
for ( V_92 = 0 ; V_92 < V_264 -> V_92 ; V_92 ++ ) {
V_85 = F_245 ( V_2 , & V_632 ) ;
if ( V_85 < 0 )
return V_85 ;
V_3 [ V_92 ] = V_632 ;
}
return V_264 -> V_92 ;
}
static void F_247 ( struct V_1 * V_2 , unsigned int V_81 ,
unsigned int V_636 )
{
F_54 ( V_2 , ( V_81 >> 16 ) & 0xff , V_637 ) ;
F_54 ( V_2 , V_81 & 0xffff , V_638 ) ;
V_636 &= V_639 ;
F_244 ( V_2 , V_627 | V_636 ) ;
if ( F_241 ( V_2 ) )
F_30 ( V_2 -> V_10 ,
L_37 , V_11 ) ;
}
static int F_248 ( struct V_1 * V_2 )
{
unsigned int V_233 = V_640 |
V_641 ;
#if 1
F_247 ( V_2 , V_233 | V_642 ,
V_643 ) ;
F_245 ( V_2 , NULL ) ;
#else
F_247 ( V_2 , 0x400000 , V_644 ) ;
F_247 ( V_2 , V_233 | V_645 ,
V_643 ) ;
if ( F_241 ( V_2 ) )
F_30 ( V_2 -> V_10 ,
L_37 , V_11 ) ;
#endif
return 0 ;
}
static int F_249 ( unsigned int V_646 ,
unsigned int * V_647 ,
unsigned int * V_648 ,
unsigned int * V_649 )
{
unsigned int div ;
unsigned int V_650 = 1 ;
unsigned int V_651 ;
unsigned int V_652 = 1 ;
static const unsigned int V_653 = 1000 ;
const unsigned int V_654 = V_646 *
V_653 ;
static const unsigned int V_655 = 12500 ;
int V_656 = 0 ;
for ( div = 1 ; div <= V_657 ; ++ div ) {
for ( V_651 = 1 ; V_651 <= V_658 ; ++ V_651 ) {
unsigned int V_659 =
( V_654 * div ) / V_651 ;
if ( abs ( V_659 - V_655 ) <
abs ( V_656 - V_655 ) ) {
V_656 = V_659 ;
V_650 = div ;
V_652 = V_651 ;
}
}
}
if ( V_656 == 0 )
return - V_180 ;
* V_647 = V_650 ;
* V_648 = V_652 ;
* V_649 = F_119 ( V_656 * 4 ,
V_653 ) ;
return 0 ;
}
static int F_250 ( struct V_1 * V_2 ,
unsigned int V_607 ,
unsigned int V_660 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
static const unsigned int V_661 = 50 ;
static const unsigned int V_662 = 1000 ;
static const unsigned int V_71 = 1000 ;
unsigned int V_663 ;
unsigned int V_647 ;
unsigned int V_648 ;
unsigned int V_664 ;
unsigned int V_72 ;
int V_85 ;
if ( V_607 == V_665 )
V_660 = 100 ;
if ( V_660 < V_661 || V_660 > V_662 ) {
F_30 ( V_2 -> V_10 ,
L_38 ,
V_11 , V_661 , V_662 ) ;
return - V_305 ;
}
V_16 -> V_666 &= ~ V_667 ;
F_23 ( V_2 , V_16 -> V_666 ,
V_668 ) ;
V_663 = V_669 | V_670 ;
V_16 -> V_671 |= V_672 |
V_673 ;
V_16 -> V_671 &= ~ V_674 ;
switch ( V_607 ) {
case V_675 :
V_16 -> V_671 |= V_676 ;
break;
case V_665 :
V_16 -> V_671 |= V_677 ;
break;
default:
for ( V_664 = 0 ; V_664 <= V_678 ; ++ V_664 ) {
if ( V_607 == F_251 ( V_664 ) ) {
V_16 -> V_671 |=
F_252 ( V_664 ) ;
break;
}
}
if ( V_664 > V_678 )
return - V_305 ;
break;
}
V_85 = F_249 ( V_660 ,
& V_647 ,
& V_648 ,
& V_16 -> V_275 ) ;
if ( V_85 < 0 ) {
F_30 ( V_2 -> V_10 ,
L_39 ) ;
return V_85 ;
}
F_4 ( V_2 , V_16 -> V_671 , V_679 ) ;
V_663 |= F_253 ( V_647 ) |
F_254 ( V_648 ) ;
F_4 ( V_2 , V_663 , V_680 ) ;
V_16 -> V_681 = V_607 ;
for ( V_72 = 0 ; V_72 < V_71 ; ++ V_72 ) {
if ( F_13 ( V_2 , V_682 ) & V_683 )
break;
F_52 ( 1 ) ;
}
if ( V_72 == V_71 ) {
F_30 ( V_2 -> V_10 ,
L_40 ,
V_11 , V_607 , V_660 ) ;
return - V_684 ;
}
return 3 ;
}
static int F_255 ( struct V_1 * V_2 ,
unsigned int V_607 , unsigned int V_660 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
if ( V_607 == V_685 ) {
V_16 -> V_666 &= ~ V_667 ;
F_23 ( V_2 , V_16 -> V_666 ,
V_668 ) ;
V_16 -> V_275 = V_566 ;
if ( V_16 -> V_19 ) {
V_16 -> V_671 &=
~ ( V_672 |
V_673 ) ;
F_4 ( V_2 , V_16 -> V_671 ,
V_679 ) ;
F_4 ( V_2 , 0 , V_680 ) ;
}
V_16 -> V_681 = V_607 ;
} else {
if ( V_16 -> V_19 ) {
return F_250 ( V_2 , V_607 ,
V_660 ) ;
} else {
if ( V_607 == V_686 ) {
V_16 -> V_666 |=
V_667 ;
F_23 ( V_2 ,
V_16 -> V_666 ,
V_668 ) ;
if ( V_660 == 0 ) {
F_30 ( V_2 -> V_10 ,
L_41 ) ;
return - V_305 ;
}
V_16 -> V_275 = V_660 ;
V_16 -> V_681 = V_607 ;
} else {
return - V_305 ;
}
}
}
return 3 ;
}
static int F_256 ( struct V_1 * V_2 ,
unsigned int V_217 , unsigned int V_607 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
if ( V_217 >= F_257 ( V_16 -> V_19 ) ) {
if ( V_217 == V_687 ) {
if ( V_607 == V_688 )
return 1 ;
F_30 ( V_2 -> V_10 ,
L_42 ,
V_11 , V_217 , V_687 ) ;
return 0 ;
}
return 0 ;
}
switch ( V_607 ) {
case V_689 :
case V_690 :
case V_691 :
case V_692 :
case V_693 :
case V_694 :
case V_695 :
case V_696 :
case V_697 :
return 1 ;
case V_688 :
return ( V_16 -> V_19 ) ? 1 : 0 ;
default:
return 0 ;
}
}
static int F_258 ( struct V_1 * V_2 ,
unsigned int V_217 , unsigned int V_698 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
if ( F_256 ( V_2 , V_217 , V_698 ) == 0 )
return - V_305 ;
if ( V_217 < 4 ) {
V_16 -> V_699 &= ~ F_259 ( V_217 ) ;
V_16 -> V_699 |= F_260 ( V_217 , V_698 ) ;
F_23 ( V_2 , V_16 -> V_699 ,
V_700 ) ;
} else if ( V_217 < 8 ) {
V_16 -> V_701 &= ~ F_259 ( V_217 ) ;
V_16 -> V_701 |= F_260 ( V_217 , V_698 ) ;
F_23 ( V_2 , V_16 -> V_701 ,
V_702 ) ;
}
return 2 ;
}
static unsigned int F_261 ( struct V_1 * V_2 ,
unsigned int V_217 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
if ( V_217 < 4 ) {
return F_262 ( V_217 ,
V_16 -> V_699 ) ;
} else if ( V_217 < F_257 ( V_16 -> V_19 ) ) {
return F_262 ( V_217 ,
V_16 -> V_701 ) ;
} else {
if ( V_217 == V_687 )
return V_688 ;
F_30 ( V_2 -> V_10 , L_43 ) ;
return 0 ;
}
}
static int F_263 ( struct V_1 * V_2 ,
struct V_82 * V_83 ,
struct V_263 * V_264 ,
unsigned int * V_3 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned int V_217 = F_105 ( V_264 -> V_267 ) ;
unsigned int V_703 = F_257 ( V_16 -> V_19 ) ;
switch ( V_3 [ 0 ] ) {
case V_704 :
if ( V_217 < V_703 ) {
V_16 -> V_666 |=
F_264 ( V_217 , V_16 -> V_19 ) ;
} else if ( V_217 == V_687 ) {
V_16 -> V_666 |=
V_705 ;
}
F_23 ( V_2 , V_16 -> V_666 ,
V_668 ) ;
break;
case V_706 :
if ( V_217 < V_703 ) {
V_16 -> V_666 &=
~ F_264 ( V_217 , V_16 -> V_19 ) ;
} else if ( V_217 == V_687 ) {
V_16 -> V_666 &=
~ V_705 ;
}
F_23 ( V_2 , V_16 -> V_666 ,
V_668 ) ;
break;
case V_616 :
if ( V_217 < V_703 ) {
V_3 [ 1 ] =
( V_16 -> V_666 &
F_264 ( V_217 , V_16 -> V_19 ) )
? V_704
: V_706 ;
} else if ( V_217 == V_687 ) {
V_3 [ 1 ] = ( V_16 -> V_666 &
V_705 )
? V_704
: V_706 ;
}
return 2 ;
case V_560 :
return F_255 ( V_2 , V_3 [ 1 ] , V_3 [ 2 ] ) ;
case V_564 :
V_3 [ 1 ] = V_16 -> V_681 ;
V_3 [ 2 ] = V_16 -> V_275 ;
return 3 ;
case V_617 :
return F_258 ( V_2 , V_217 , V_3 [ 1 ] ) ;
case V_618 :
V_3 [ 1 ] = F_261 ( V_2 , V_217 ) ;
return 2 ;
default:
return - V_305 ;
}
return 1 ;
}
static int F_265 ( struct V_1 * V_2 ,
struct V_82 * V_83 ,
struct V_263 * V_264 ,
unsigned int * V_3 )
{
V_3 [ 1 ] = 0 ;
return V_264 -> V_92 ;
}
static void F_266 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
V_16 -> V_671 = V_707 ;
if ( F_255 ( V_2 , V_685 , 0 ) < 0 )
F_30 ( V_2 -> V_10 , L_44 ) ;
V_16 -> V_699 =
F_260 ( 0 , V_689 ) |
F_260 ( 1 , V_690 ) |
F_260 ( 2 , V_691 ) |
F_260 ( 3 , V_692 ) ;
F_23 ( V_2 , V_16 -> V_699 ,
V_700 ) ;
V_16 -> V_701 =
F_260 ( 4 , V_693 ) |
F_260 ( 5 , V_694 ) |
F_260 ( 6 , V_695 ) ;
if ( V_16 -> V_19 )
V_16 -> V_701 |=
F_260 ( 7 , V_688 ) ;
F_23 ( V_2 , V_16 -> V_701 ,
V_702 ) ;
}
static int F_267 ( struct V_1 * V_2 , struct V_82 * V_83 )
{
struct V_58 * V_59 = V_83 -> V_17 ;
int V_85 ;
V_85 = F_38 ( V_2 , V_59 -> V_127 ,
V_47 ) ;
if ( V_85 ) {
F_30 ( V_2 -> V_10 ,
L_45 ) ;
return V_85 ;
}
F_268 ( V_59 ) ;
F_50 ( V_2 , V_59 -> V_127 , 1 ) ;
return F_269 ( V_2 , V_83 ) ;
}
static int F_270 ( struct V_1 * V_2 , struct V_82 * V_83 )
{
struct V_58 * V_59 = V_83 -> V_17 ;
int V_85 ;
V_85 = F_271 ( V_59 ) ;
F_50 ( V_2 , V_59 -> V_127 , 0 ) ;
F_48 ( V_2 , V_59 -> V_127 ) ;
return V_85 ;
}
static T_3 F_272 ( int V_315 , void * V_93 )
{
struct V_1 * V_2 = V_93 ;
struct V_82 * V_708 = V_2 -> V_84 ;
struct V_82 * V_709 = V_2 -> V_182 ;
unsigned short V_129 ;
unsigned short V_88 ;
unsigned long V_18 ;
#ifdef F_45
struct V_15 * V_16 = V_2 -> V_17 ;
#endif
if ( ! V_2 -> V_710 )
return V_711 ;
F_273 () ;
F_24 ( & V_2 -> V_212 , V_18 ) ;
V_129 = F_27 ( V_2 , V_86 ) ;
V_88 = F_27 ( V_2 , V_89 ) ;
#ifdef F_45
if ( V_16 -> V_21 ) {
unsigned long V_712 ;
F_24 ( & V_16 -> V_43 , V_712 ) ;
if ( V_708 && V_16 -> V_48 )
F_191 ( V_16 -> V_48 , V_708 , false ) ;
if ( V_709 && V_16 -> V_53 )
F_191 ( V_16 -> V_53 , V_709 , false ) ;
F_25 ( & V_16 -> V_43 , V_712 ) ;
}
#endif
F_82 ( V_2 , V_129 ) ;
F_85 ( V_2 , V_88 ) ;
if ( V_708 ) {
if ( V_129 & V_713 )
F_83 ( V_2 , V_708 , V_129 ) ;
F_81 ( V_2 , V_708 ) ;
}
if ( V_709 ) {
if ( V_88 & V_714 )
F_86 ( V_2 , V_709 , V_88 ) ;
F_81 ( V_2 , V_709 ) ;
}
F_78 ( V_2 , 0 ) ;
F_78 ( V_2 , 1 ) ;
#ifdef F_45
if ( V_16 -> V_19 )
F_190 ( V_2 ) ;
#endif
F_25 ( & V_2 -> V_212 , V_18 ) ;
return V_715 ;
}
static int F_274 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
V_16 = F_275 ( V_2 , sizeof( * V_16 ) ) ;
if ( ! V_16 )
return - V_716 ;
F_276 ( & V_16 -> V_20 ) ;
F_276 ( & V_16 -> V_27 ) ;
F_276 ( & V_16 -> V_43 ) ;
return 0 ;
}
static int F_277 ( struct V_1 * V_2 ,
unsigned int V_717 , unsigned int V_718 )
{
const struct V_99 * V_100 = V_2 -> V_101 ;
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_82 * V_83 ;
int V_166 ;
int V_72 ;
if ( V_100 -> V_719 > V_720 ) {
F_30 ( V_2 -> V_10 , L_46 ) ;
return - V_305 ;
}
V_16 -> V_516 = V_721 |
V_525 |
V_722 |
V_723 ;
if ( ! V_16 -> V_95 ) {
V_16 -> V_516 |= ( V_724 |
V_725 ) ;
}
F_23 ( V_2 , V_16 -> V_516 , V_529 ) ;
V_166 = F_278 ( V_2 , V_726 ) ;
if ( V_166 )
return V_166 ;
V_83 = & V_2 -> V_128 [ V_727 ] ;
if ( V_100 -> V_728 ) {
V_83 -> type = V_729 ;
V_83 -> V_175 = V_730 | V_731 | V_732 ;
if ( ! V_16 -> V_112 )
V_83 -> V_175 |= V_733 | V_734 | V_735 ;
if ( V_100 -> V_736 > 0xffff )
V_83 -> V_175 |= V_176 ;
if ( V_16 -> V_19 )
V_83 -> V_175 |= V_737 ;
V_83 -> V_215 = V_100 -> V_728 ;
V_83 -> V_246 = V_100 -> V_736 ;
V_83 -> V_376 = V_738 [ V_100 -> V_226 ] ;
V_83 -> V_739 = F_117 ;
V_83 -> V_740 = F_140 ;
if ( V_2 -> V_315 ) {
V_2 -> V_84 = V_83 ;
V_83 -> V_175 |= V_741 ;
V_83 -> V_742 = 512 ;
V_83 -> V_743 = F_126 ;
V_83 -> V_744 = F_133 ;
V_83 -> V_482 = F_96 ;
V_83 -> V_745 = F_101 ;
V_83 -> V_746 = F_87 ;
if ( V_16 -> V_21 )
V_83 -> V_747 = V_748 ;
}
F_96 ( V_2 , V_83 ) ;
} else {
V_83 -> type = V_749 ;
}
V_83 = & V_2 -> V_128 [ V_750 ] ;
if ( V_100 -> V_719 ) {
V_83 -> type = V_751 ;
V_83 -> V_175 = V_752 | V_753 | V_733 ;
if ( V_16 -> V_19 )
V_83 -> V_175 |= V_737 ;
V_83 -> V_215 = V_100 -> V_719 ;
V_83 -> V_246 = V_100 -> V_754 ;
V_83 -> V_376 = V_100 -> V_755 ;
V_83 -> V_740 = F_157 ;
V_83 -> V_756 = F_153 ;
V_166 = F_279 ( V_83 ) ;
if ( V_166 )
return V_166 ;
if ( V_2 -> V_315 && ( V_100 -> V_107 || V_16 -> V_21 ) ) {
V_2 -> V_182 = V_83 ;
V_83 -> V_175 |= V_757 ;
V_83 -> V_742 = V_83 -> V_215 ;
V_83 -> V_743 = F_173 ;
V_83 -> V_744 = F_172 ;
V_83 -> V_482 = F_174 ;
if ( ! V_16 -> V_19 )
V_83 -> V_746 = F_141 ;
if ( V_16 -> V_21 )
V_83 -> V_747 = V_758 ;
}
if ( V_16 -> V_759 )
F_196 ( V_2 , V_83 ) ;
F_174 ( V_2 , V_83 ) ;
} else {
V_83 -> type = V_749 ;
}
V_83 = & V_2 -> V_128 [ V_501 ] ;
V_83 -> type = V_760 ;
V_83 -> V_175 = V_752 | V_730 ;
V_83 -> V_215 = V_100 -> V_761 ? 32 : 8 ;
V_83 -> V_246 = 1 ;
V_83 -> V_376 = & V_762 ;
if ( V_16 -> V_19 ) {
#ifdef F_45
V_83 -> V_175 |= V_176 ;
V_83 -> V_763 = F_182 ;
V_83 -> V_740 = F_181 ;
if ( V_2 -> V_315 ) {
V_83 -> V_175 |= V_757 ;
V_83 -> V_742 = V_83 -> V_215 ;
V_83 -> V_743 = F_184 ;
V_83 -> V_744 = F_187 ;
V_83 -> V_482 = F_189 ;
V_83 -> V_747 = V_764 ;
}
F_1 ( V_2 , V_488 |
V_765 ,
V_486 ) ;
F_1 ( V_2 , V_83 -> V_467 , V_477 ) ;
#endif
} else {
V_83 -> V_763 = F_178 ;
V_83 -> V_740 = F_175 ;
V_16 -> V_465 = F_177 ( V_83 -> V_467 ) ;
F_4 ( V_2 , V_16 -> V_465 , V_468 ) ;
}
V_83 = & V_2 -> V_128 [ V_766 ] ;
if ( V_100 -> V_767 ) {
V_166 = F_280 ( V_2 , V_83 , F_205 ,
V_768 ) ;
if ( V_166 )
return V_166 ;
} else {
V_83 -> type = V_749 ;
}
V_83 = & V_2 -> V_128 [ V_769 ] ;
V_83 -> type = V_749 ;
V_83 = & V_2 -> V_128 [ V_770 ] ;
V_83 -> type = V_771 ;
V_83 -> V_175 = V_772 ;
V_83 -> V_215 = 1 ;
V_83 -> V_246 = 0 ;
if ( V_16 -> V_19 ) {
V_83 -> V_740 = F_207 ;
F_1 ( V_2 , 0x0 , V_574 ) ;
} else if ( V_16 -> V_73 ) {
V_83 -> V_740 = F_210 ;
} else {
V_83 -> V_175 |= V_752 ;
V_83 -> V_739 = F_221 ;
V_83 -> V_756 = F_220 ;
F_222 ( V_2 , V_83 ) ;
}
V_83 = & V_2 -> V_128 [ V_773 ] ;
V_83 -> type = V_774 ;
V_83 -> V_175 = V_730 | V_772 ;
V_83 -> V_246 = 0xff ;
if ( V_16 -> V_19 ) {
V_83 -> V_215 = V_775 ;
V_83 -> V_739 = F_225 ;
} else {
V_83 -> V_215 = 512 ;
V_83 -> V_739 = F_224 ;
}
V_83 = & V_2 -> V_128 [ V_776 ] ;
V_83 -> type = V_760 ;
V_83 -> V_175 = V_730 | V_752 | V_772 ;
V_83 -> V_246 = 1 ;
if ( V_16 -> V_19 ) {
V_83 -> V_215 = 16 ;
V_83 -> V_763 = F_240 ;
F_4 ( V_2 , V_83 -> V_474 , V_620 ) ;
for ( V_72 = 0 ; V_72 < V_777 ; ++ V_72 ) {
F_4 ( V_2 , V_16 -> V_609 [ V_72 ] ,
F_233 ( V_72 ) ) ;
}
} else {
V_83 -> V_215 = 10 ;
}
V_83 -> V_740 = F_239 ;
F_57 ( V_2 , V_32 , ~ 0 , 0 ) ;
V_83 = & V_2 -> V_128 [ V_778 ] ;
if ( V_16 -> V_759 ) {
V_83 -> type = V_729 ;
V_83 -> V_175 = V_730 | V_731 | V_772 ;
V_83 -> V_215 = V_100 -> V_719 ;
V_83 -> V_246 = ( 1 << 16 ) - 1 ;
V_83 -> V_376 = & V_779 ;
V_83 -> V_739 = F_246 ;
V_83 -> V_740 = NULL ;
F_248 ( V_2 ) ;
} else {
V_83 -> type = V_749 ;
}
V_83 = & V_2 -> V_128 [ V_780 ] ;
V_83 -> type = V_781 ;
V_83 -> V_175 = V_730 | V_752 | V_772 ;
V_83 -> V_215 = 1 ;
V_83 -> V_246 = 0xff ;
V_83 -> V_740 = F_195 ;
V_16 -> V_471 = 0 ;
V_16 -> V_520 = 0 ;
V_83 = & V_2 -> V_128 [ V_782 ] ;
V_83 -> type = V_760 ;
V_83 -> V_175 = V_730 | V_752 | V_772 ;
V_83 -> V_215 = 8 ;
V_83 -> V_246 = 1 ;
V_83 -> V_763 = F_265 ;
V_83 -> V_740 = F_263 ;
F_266 ( V_2 ) ;
V_16 -> V_60 = F_281 ( V_2 ,
F_198 ,
F_199 ,
( V_16 -> V_19 )
? V_783
: V_784 ,
V_785 ) ;
if ( ! V_16 -> V_60 )
return - V_716 ;
for ( V_72 = 0 ; V_72 < V_785 ; ++ V_72 ) {
struct V_58 * V_786 = & V_16 -> V_60 -> V_61 [ V_72 ] ;
V_786 -> V_787 = 0 ;
V_786 -> V_127 = V_72 ;
F_282 ( V_786 ) ;
V_83 = & V_2 -> V_128 [ F_79 ( V_72 ) ] ;
V_83 -> type = V_788 ;
V_83 -> V_175 = V_730 | V_752 | V_176 ;
V_83 -> V_215 = 3 ;
V_83 -> V_246 = ( V_16 -> V_19 ) ? 0xffffffff
: 0x00ffffff ;
V_83 -> V_739 = V_789 ;
V_83 -> V_756 = V_790 ;
V_83 -> V_740 = V_791 ;
#ifdef F_45
if ( V_2 -> V_315 && V_16 -> V_21 ) {
V_83 -> V_175 |= V_741 ;
V_83 -> V_742 = 1 ;
V_83 -> V_743 = V_792 ;
V_83 -> V_744 = F_267 ;
V_83 -> V_482 = F_270 ;
V_83 -> V_747 = V_764 ;
}
#endif
V_83 -> V_17 = V_786 ;
}
V_83 = & V_2 -> V_128 [ V_793 ] ;
V_83 -> type = V_788 ;
V_83 -> V_175 = V_730 | V_752 ;
V_83 -> V_215 = 1 ;
V_83 -> V_246 = 0xf ;
V_83 -> V_739 = F_200 ;
V_83 -> V_756 = F_202 ;
V_83 -> V_740 = F_204 ;
if ( V_2 -> V_315 ) {
F_23 ( V_2 ,
( V_718 ? V_794 : 0 ) |
( V_795 & 0 ) |
V_796 |
V_797 |
F_283 ( V_717 ) |
F_284 ( V_717 ) ,
V_798 ) ;
}
F_7 ( V_2 , V_16 -> V_35 , V_34 ) ;
F_7 ( V_2 , V_16 -> V_37 , V_36 ) ;
if ( V_16 -> V_95 ) {
F_7 ( V_2 , 0 , V_799 ) ;
} else if ( V_16 -> V_19 ) {
int V_49 ;
for ( V_49 = 0 ; V_49 < V_100 -> V_719 ; ++ V_49 ) {
F_7 ( V_2 , 0xf ,
F_147 ( V_49 ) ) ;
F_7 ( V_2 , 0x0 ,
F_148 ( V_49 ) ) ;
}
F_7 ( V_2 , 0x0 , V_800 ) ;
}
return 0 ;
}
static void F_285 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
if ( V_16 )
F_286 ( V_16 -> V_60 ) ;
}
