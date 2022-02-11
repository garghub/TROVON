static inline int F_1 ( unsigned V_1 )
{
F_2 ( L_1 , V_1 ) ;
return 0 ;
}
static void F_3 ( struct V_2 * V_3 , unsigned V_1 )
{
int V_4 = F_1 ( V_1 ) ;
if ( V_4 < 0 )
F_2 ( L_2 , V_1 , V_4 ) ;
}
static void F_3 ( struct V_2 * V_3 , unsigned V_1 )
{
}
static void F_4 ( struct V_2 * V_3 )
{
}
static inline void F_5 ( struct V_2 * V_3 )
{
F_6 ( V_5 L_3 ) ;
}
static inline T_1
F_7 ( struct V_2 * V_3 , T_1 V_6 )
{
return F_8 ( V_3 -> V_7 , V_6 + 0 ) ;
}
static inline int
F_9 ( struct V_2 * V_3 , T_1 V_6 )
{
return F_10 ( V_3 -> V_7 , V_6 ) ;
}
static inline int
F_11 ( struct V_2 * V_3 , T_1 V_6 , T_1 V_8 )
{
return F_12 ( V_3 -> V_7 , V_6 + 0 , V_8 ) ;
}
static inline int
F_13 ( struct V_2 * V_3 , T_1 V_6 , T_1 V_8 )
{
return F_12 ( V_3 -> V_7 , V_6 + 1 , V_8 ) ;
}
static inline const char * F_14 ( struct V_2 * V_3 )
{
return F_15 ( V_3 -> V_9 . V_10 ) ;
}
static void F_16 ( struct V_2 * V_3 )
{
V_3 -> V_9 . V_10 = V_11 ;
F_11 ( V_3 , V_12 , V_13 ) ;
F_13 ( V_3 , V_14 , V_15 ) ;
F_13 ( V_3 , V_12 , V_16 ) ;
}
static void F_17 ( struct V_2 * V_3 )
{
F_13 ( V_3 , V_12 , V_13 ) ;
F_11 ( V_3 , V_12 , V_16 ) ;
}
static int F_18 ( struct V_2 * V_3 )
{
#ifdef F_19
return 0 ;
#else
struct V_17 * V_18 ;
if ( ! V_3 -> V_9 . V_19 -> V_20 )
return - V_21 ;
V_18 = V_3 -> V_9 . V_19 -> V_20 -> V_22 ;
return V_18 -> V_23 -> V_24 ( V_18 , 3 , 0 ) ;
#endif
}
static int F_20 ( struct V_2 * V_3 )
{
#ifdef F_19
return 0 ;
#else
struct V_17 * V_18 ;
if ( ! V_3 -> V_9 . V_19 -> V_20 )
return - V_21 ;
V_18 = V_3 -> V_9 . V_19 -> V_20 -> V_22 ;
return V_18 -> V_23 -> V_25 ( V_18 , 0 ) ;
#endif
}
static int F_21 ( struct V_2 * V_3 )
{
V_3 -> V_9 . V_19 -> V_26 -> V_27 = 0 ;
V_3 -> V_9 . V_19 -> V_26 -> V_28 = 0 ;
V_3 -> V_9 . V_19 -> V_26 -> V_29 = 0 ;
return F_22 ( V_3 -> V_9 . V_19 -> V_26 ) ;
}
static void F_23 ( struct V_2 * V_3 , int V_30 )
{
int V_4 ;
if ( V_3 && ! F_24 ( V_30 , & V_3 -> V_31 ) ) {
( void ) F_25 ( & V_3 -> V_7 -> V_18 ) ;
V_4 = F_26 ( & V_3 -> V_30 ) ;
if ( ! V_4 && ! V_3 -> V_32 )
F_27 ( & V_3 -> V_7 -> V_18 ,
L_4 , V_30 ) ;
}
}
static void F_28 ( struct V_2 * V_3 , const char * V_33 )
{
T_2 V_34 ;
if ( V_3 -> V_9 . V_10 == V_35 )
return;
V_3 -> V_9 . V_19 -> V_36 = 1 ;
if ( V_3 -> V_9 . V_19 -> V_20 ) {
V_3 -> V_9 . V_19 -> V_20 -> V_37 = 0 ;
F_18 ( V_3 ) ;
}
if ( V_3 -> V_9 . V_19 -> V_26 ) {
V_3 -> V_9 . V_19 -> V_26 -> V_38 = 1 ;
F_21 ( V_3 ) ;
}
V_3 -> V_9 . V_10 = V_35 ;
V_34 = F_29 ( V_39 ) & V_40 ;
F_30 ( V_34 , V_39 ) ;
V_3 -> V_41 = V_34 ;
F_2 ( L_5 , F_14 ( V_3 ) , V_33 ) ;
}
static void F_31 ( struct V_2 * V_3 , const char * V_33 )
{
T_2 V_34 ;
if ( V_3 -> V_9 . V_10 == V_42 )
return;
V_3 -> V_9 . V_19 -> V_36 = 0 ;
if ( V_3 -> V_9 . V_19 -> V_20 ) {
V_3 -> V_9 . V_19 -> V_20 -> V_37 = 1 ;
F_18 ( V_3 ) ;
}
if ( V_3 -> V_9 . V_19 -> V_26 ) {
V_3 -> V_9 . V_19 -> V_26 -> V_38 = 0 ;
F_21 ( V_3 ) ;
}
V_3 -> V_9 . V_10 = V_42 ;
V_34 = F_29 ( V_39 ) & V_40 ;
F_30 ( V_34 , V_39 ) ;
V_3 -> V_41 = V_34 ;
F_2 ( L_5 , F_14 ( V_3 ) , V_33 ) ;
}
static void
F_32 ( struct V_2 * V_3 , const char * V_43 )
{
#ifdef F_33
T_1 V_44 = F_7 ( V_3 , V_14 ) ;
T_1 V_4 = F_7 ( V_3 , V_45 ) ;
T_1 V_46 = F_7 ( V_3 , V_47 ) ;
F_2 ( L_6 ,
F_29 ( V_39 ) , V_43 , F_14 ( V_3 ) ,
V_44 , V_4 , V_46 ) ;
#endif
}
static void F_34 ( struct V_2 * V_3 , const char * V_33 )
{
enum V_48 V_10 = V_11 ;
T_1 V_49 = F_35 ( V_50 ) & 0x0ff ;
unsigned V_51 = 0 ;
switch ( V_49 ) {
case 0x0 :
V_10 = V_42 ;
break;
case 0x3 :
case 0x7 :
V_51 = 1 ;
case 0x1 :
V_10 = V_52 ;
break;
case 0x11 :
V_10 = V_53 ;
break;
case 0x12 :
case 0x13 :
case 0x16 :
V_51 = 1 ;
case 0x17 :
V_10 = V_54 ;
break;
case 0x34 :
V_10 = V_55 ;
break;
case 0x36 :
V_10 = V_35 ;
break;
case 0x3c :
V_10 = V_56 ;
break;
case 0x7d :
V_10 = V_57 ;
break;
case 0x9e :
case 0x9f :
V_51 = 1 ;
case 0x89 :
V_10 = V_58 ;
break;
case 0xb7 :
V_10 = V_59 ;
break;
case 0xb8 :
V_10 = V_60 ;
break;
case 0xb9 :
V_10 = V_61 ;
break;
case 0xba :
V_10 = V_62 ;
break;
default:
break;
}
if ( V_3 -> V_9 . V_10 == V_10 && ! V_51 )
return;
F_2 ( L_7 , V_33 ,
F_15 ( V_10 ) , V_49 , F_14 ( V_3 ) ,
F_29 ( V_39 ) ) ;
}
static inline void F_34 ( struct V_2 * V_3 , const char * V_33 ) { }
static void F_36 ( struct V_2 * V_3 , T_1 V_63 )
{
T_2 V_64 ;
V_64 = F_29 ( V_39 ) & V_65 ;
V_64 &= ~ V_66 ;
V_64 &= ~ ( V_67 | V_68 | V_69 ) ;
if ( V_63 & V_70 )
V_64 |= V_68 ;
else if ( V_3 -> V_9 . V_10 == V_56 ) {
F_28 ( V_3 , L_8 ) ;
V_64 &= ~ V_71 ;
}
if ( V_63 & V_72 )
V_64 |= V_69 ;
if ( V_63 & V_73 ) {
if ( V_3 -> V_9 . V_10 == V_42
|| V_3 -> V_9 . V_10
== V_11 ) {
F_28 ( V_3 , L_9 ) ;
return;
}
} else {
V_64 |= V_67 ;
if ( V_3 -> V_9 . V_10 == V_35
|| V_3 -> V_9 . V_10 == V_11 ) {
F_31 ( V_3 , L_9 ) ;
return;
}
}
F_30 ( V_64 , V_39 ) ;
}
static void F_37 ( struct V_2 * V_3 , T_1 V_74 )
{
T_2 V_64 ;
V_64 = F_29 ( V_39 ) & V_65 ;
V_64 &= ~ V_66 ;
V_64 &= ~ ( V_75 | V_76 ) ;
if ( V_74 & V_77 )
V_64 |= V_75 ;
else if ( V_74 & V_78 )
V_64 |= V_76 ;
F_30 ( V_64 , V_39 ) ;
}
static void F_38 ( struct V_2 * V_3 )
{
T_2 V_64 , V_79 ;
T_1 V_80 = V_81 , V_82 = V_83 ;
V_64 = F_29 ( V_39 ) ;
V_79 = V_64 ^ V_3 -> V_41 ;
V_3 -> V_41 = V_64 ;
V_64 = V_64 & V_66 ;
switch ( V_3 -> V_9 . V_10 ) {
case V_42 :
case V_52 :
case V_53 :
if ( ! ( V_64 & V_84 ) ) {
if ( V_3 -> V_9 . V_19 -> V_26 -> V_27 ) {
V_3 -> V_9 . V_10 = V_54 ;
F_2 ( L_10 ) ;
}
goto V_85;
}
V_86:
V_80 |= V_87 ;
V_82 |= V_88 ;
break;
case V_62 :
case V_58 :
if ( V_64 & V_84 )
goto V_86;
default:
V_85:
V_80 |= V_88 ;
V_82 |= V_87 ;
break;
}
# define F_39 ( T_3 , T_4 ) do { \
if (otg_ctrl & OTG) set |= ISP; \
else clr |= ISP; \
} while (0)
if ( ! ( V_3 -> V_9 . V_19 -> V_20 ) )
V_64 &= ~ V_89 ;
switch ( V_3 -> V_9 . V_10 ) {
case V_62 :
if ( V_64 & V_89 ) {
V_80 |= V_90 ;
break;
}
F_5 ( V_3 ) ;
case V_57 :
V_3 -> V_9 . V_10 = V_56 ;
F_2 ( L_11 ) ;
case V_56 :
V_82 |= V_90 ;
break;
case V_35 :
if ( V_64 & V_89 ) {
V_3 -> V_9 . V_10 = V_59 ;
F_2 ( L_12 ) ;
}
default:
F_39 ( V_89 , V_90 ) ;
}
F_39 ( V_91 , V_92 ) ;
F_39 ( V_93 , V_94 ) ;
# undef F_39
F_11 ( V_3 , V_14 , V_80 ) ;
F_13 ( V_3 , V_14 , V_82 ) ;
if ( V_79 & V_84 ) {
T_2 V_34 ;
switch ( V_3 -> V_9 . V_10 ) {
case V_42 :
if ( V_82 & V_87 )
break;
V_3 -> V_9 . V_10 = V_52 ;
F_2 ( L_13 ) ;
break;
case V_62 :
if ( V_82 & V_87 )
break;
V_3 -> V_9 . V_10 = V_58 ;
F_2 ( L_14 ) ;
break;
default:
break;
}
V_34 = F_29 ( V_39 ) ;
V_34 |= V_84 ;
F_30 ( V_34 , V_39 ) ;
}
F_34 ( V_3 , V_95 ) ;
F_32 ( V_3 , L_15 ) ;
}
static T_5 F_40 ( int V_96 , void * V_97 )
{
T_6 V_98 = F_35 ( V_99 ) ;
T_2 V_64 ;
int V_100 = V_101 ;
struct V_2 * V_3 = V_97 ;
struct V_102 * V_19 = V_3 -> V_9 . V_19 ;
if ( V_98 & V_103 ) {
F_41 ( V_103 , V_99 ) ;
F_23 ( V_3 , V_104 ) ;
V_100 = V_105 ;
} else if ( V_98 & V_106 ) {
F_2 ( L_16 , F_29 ( V_39 ) ) ;
F_5 ( V_3 ) ;
if ( V_3 -> V_9 . V_10 == V_53 )
F_31 ( V_3 , L_17 ) ;
F_41 ( V_106 , V_99 ) ;
V_100 = V_105 ;
} else if ( V_98 & V_107 ) {
F_2 ( L_18 ,
F_14 ( V_3 ) , F_29 ( V_39 ) ) ;
F_5 ( V_3 ) ;
V_64 = F_29 ( V_39 ) ;
V_64 |= V_108 ;
V_64 &= V_65 & ~ V_66 ;
F_30 ( V_64 , V_39 ) ;
V_3 -> V_9 . V_10 = V_52 ;
F_2 ( L_13 ) ;
F_41 ( V_107 , V_99 ) ;
V_100 = V_105 ;
} else if ( V_98 & V_109 ) {
F_2 ( L_19 ,
F_14 ( V_3 ) , F_29 ( V_39 ) ) ;
F_23 ( V_3 , V_110 ) ;
switch ( V_3 -> V_9 . V_10 ) {
case V_35 :
if ( ! V_19 -> V_20 )
break;
F_23 ( V_3 , V_111 ) ;
V_64 = F_29 ( V_39 ) ;
V_64 |= V_112 ;
V_64 &= ~ ( V_108 | V_113 )
& ~ V_66
& V_65 ;
F_30 ( V_64 , V_39 ) ;
break;
default:
break;
}
F_41 ( V_109 , V_99 ) ;
V_100 = V_105 ;
} else if ( V_98 & V_114 ) {
V_64 = F_29 ( V_39 ) ;
F_42 ( L_20 ,
F_14 ( V_3 ) , V_64 ) ;
F_5 ( V_3 ) ;
V_64 |= V_108 ;
V_64 &= ~ V_112 & V_65 & ~ V_66 ;
F_30 ( V_64 , V_39 ) ;
V_3 -> V_9 . V_10 = V_56 ;
F_41 ( V_114 , V_99 ) ;
V_100 = V_105 ;
} else if ( V_98 & V_115 ) {
V_64 = F_29 ( V_39 ) ;
F_6 ( V_116 L_21 ,
F_14 ( V_3 ) , V_98 , V_64 ) ;
V_64 |= V_108 ;
V_64 &= ~ V_112 & V_65 & ~ V_66 ;
F_30 ( V_64 , V_39 ) ;
V_3 -> V_9 . V_10 = V_57 ;
F_41 ( V_115 , V_99 ) ;
V_100 = V_105 ;
} else if ( V_98 & V_117 ) {
int V_118 = 0 ;
V_64 = F_29 ( V_39 ) ;
F_6 ( V_5 L_22 ,
F_14 ( V_3 ) ,
( V_64 & V_119 )
? L_23 : L_24 ,
V_64 ) ;
F_23 ( V_3 , V_104 ) ;
if ( V_64 & V_119 ) {
switch ( V_3 -> V_9 . V_10 ) {
case V_35 :
F_31 ( V_3 , V_95 ) ;
break;
default:
break;
}
F_23 ( V_3 , V_104 ) ;
} else {
if ( ! ( V_64 & V_67 ) ) {
V_64 &= V_65 & ~ V_66 ;
F_30 ( V_64 | V_112 , V_39 ) ;
}
if ( V_19 -> V_20 ) {
switch ( V_3 -> V_9 . V_10 ) {
case V_54 :
V_3 -> V_9 . V_10 = V_55 ;
F_2 ( L_25 ) ;
V_118 = 1 ;
break;
case V_60 :
V_3 -> V_9 . V_10 = V_61 ;
F_2 ( L_26 ) ;
break;
case V_58 :
V_3 -> V_9 . V_10 = V_60 ;
F_2 ( L_27 ) ;
break;
default:
break;
}
F_23 ( V_3 , V_111 ) ;
}
}
F_41 ( V_117 , V_99 ) ;
V_100 = V_105 ;
if ( V_118 )
F_43 ( V_19 -> V_20 , V_19 -> V_20 -> V_120 ) ;
}
F_34 ( V_3 , V_95 ) ;
return V_100 ;
}
static int F_44 ( struct V_2 * V_3 )
{
T_2 V_34 ;
if ( ! V_121 )
return - V_21 ;
F_32 ( V_3 , V_95 ) ;
V_34 = F_29 ( V_122 ) ;
V_34 |= V_123
| V_124
| V_125
| ( 0 << 20 )
| V_126
| V_127 | V_128
;
F_30 ( V_34 , V_122 ) ;
F_36 ( V_3 , F_7 ( V_3 , V_47 ) ) ;
F_37 ( V_3 , F_7 ( V_3 , V_45 ) ) ;
F_34 ( V_3 , V_95 ) ;
F_2 ( L_28 ,
F_14 ( V_3 ) , V_95 , F_29 ( V_39 ) ) ;
F_41 ( V_117 | V_103
| V_106 | V_107
| V_115 | V_109 | V_114 , V_129 ) ;
V_34 = F_29 ( V_122 ) ;
V_34 |= V_123 ;
F_30 ( V_34 , V_122 ) ;
return 0 ;
}
static int F_45 ( struct V_130 * V_18 )
{
V_121 = V_18 ;
return 0 ;
}
static int F_46 ( struct V_130 * V_18 )
{
V_121 = NULL ;
return 0 ;
}
static int F_47 ( struct V_2 * V_3 )
{
int V_4 ;
if ( V_121 )
return - V_131 ;
V_4 = F_48 ( & V_132 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_121 )
V_4 = F_49 ( V_121 -> V_133 [ 1 ] . V_134 , F_40 ,
0 , V_135 , V_3 ) ;
else
V_4 = - V_21 ;
if ( V_4 < 0 )
F_50 ( & V_132 ) ;
return V_4 ;
}
static void F_51 ( struct V_2 * V_3 )
{
if ( ! V_121 )
return;
F_52 ( V_121 -> V_133 [ 1 ] . V_134 , V_3 ) ;
}
static void F_53 ( struct V_2 * V_3 )
{
T_2 V_34 ;
V_34 = F_29 ( V_39 ) & V_40 ;
F_30 ( V_34 , V_39 ) ;
F_54 ( V_3 -> V_9 . V_19 -> V_26 ) ;
#ifdef F_55
F_3 ( V_3 , 8 ) ;
F_38 ( V_3 ) ;
#else
F_3 ( V_3 , 100 ) ;
F_11 ( V_3 , V_14 , V_87 ) ;
F_13 ( V_3 , V_14 , V_88 ) ;
V_3 -> V_9 . V_10 = V_52 ;
F_2 ( L_13 ) ;
F_32 ( V_3 , L_29 ) ;
#endif
}
static void F_56 ( struct V_2 * V_3 , T_1 V_136 )
{
struct V_102 * V_19 = V_3 -> V_9 . V_19 ;
T_1 V_137 , V_138 ;
enum V_48 V_10 = V_3 -> V_9 . V_10 ;
if ( V_136 & V_139 )
F_2 ( L_30 , F_14 ( V_3 ) ) ;
V_137 = F_7 ( V_3 , V_47 ) ;
if ( V_137 & V_73 ) {
if ( V_19 -> V_36 ) {
switch ( V_10 ) {
case V_42 :
F_28 ( V_3 , L_31 ) ;
case V_35 :
F_4 ( V_3 ) ;
case V_59 :
if ( V_137 & V_72 )
V_3 -> V_9 . V_10 = V_61 ;
break;
case V_56 :
if ( ! ( V_137 & V_70 ) )
F_28 ( V_3 , L_32 ) ;
break;
default:
if ( ! ( V_137 & V_72 ) )
V_3 -> V_9 . V_10 = V_57 ;
break;
}
V_138 = F_7 ( V_3 , V_45 ) ;
} else {
switch ( V_10 ) {
case V_52 :
case V_55 :
case V_54 :
F_22 ( V_19 -> V_26 ) ;
break;
default:
break;
}
if ( V_10 != V_35 )
F_28 ( V_3 , L_33 ) ;
if ( V_19 -> V_20 && V_10 == V_35 )
F_23 ( V_3 , V_111 ) ;
V_138 = 0 ;
}
} else {
T_2 V_34 ;
if ( V_19 -> V_36 ) {
switch ( V_10 ) {
default:
V_3 -> V_9 . V_10 = V_56 ;
break;
case V_56 :
V_10 = V_35 ;
break;
case V_35 :
F_18 ( V_3 ) ;
F_13 ( V_3 , V_12 ,
V_140 ) ;
V_3 -> V_9 . V_10 = V_42 ;
V_34 = F_29 ( V_39 ) & V_65 ;
V_34 &= ~ V_71 ;
F_30 ( V_34 , V_39 ) ;
break;
case V_42 :
break;
}
}
V_138 = F_7 ( V_3 , V_45 ) ;
switch ( V_3 -> V_9 . V_10 ) {
case V_52 :
case V_54 :
case V_55 :
if ( F_57 ( V_138 & V_77 ) )
break;
F_3 ( V_3 , 0 ) ;
#ifndef F_55
F_11 ( V_3 , V_14 ,
V_88 ) ;
F_13 ( V_3 , V_14 ,
V_87 ) ;
F_32 ( V_3 , V_95 ) ;
#endif
case V_53 :
F_31 ( V_3 , V_95 ) ;
V_34 = F_29 ( V_39 ) & V_40 ;
F_30 ( V_34 , V_39 ) ;
case V_42 :
if ( V_19 -> V_26 && ( V_138 & V_77 ) ) {
#ifdef F_55
F_36 ( V_3 , V_137 ) ;
F_37 ( V_3 , V_138 ) ;
#endif
F_53 ( V_3 ) ;
} else if ( ! ( V_137 & ( V_72 | V_70 ) ) )
V_138 |= V_78 ;
break;
case V_56 :
break;
default:
F_2 ( L_34 ,
F_14 ( V_3 ) ) ;
break;
}
}
if ( V_10 != V_3 -> V_9 . V_10 )
F_2 ( L_35 ,
F_15 ( V_10 ) , F_14 ( V_3 ) ) ;
#ifdef F_55
F_36 ( V_3 , V_137 ) ;
F_37 ( V_3 , V_138 ) ;
F_34 ( V_3 , V_95 ) ;
#endif
F_32 ( V_3 , L_36 ) ;
}
static T_1 F_58 ( struct V_2 * V_3 )
{
T_1 V_141 = F_7 ( V_3 , V_142 ) ;
F_13 ( V_3 , V_142 , V_141 ) ;
return V_141 ;
}
static void
F_59 ( struct V_143 * V_30 )
{
struct V_2 * V_3 = F_60 ( V_30 , struct V_2 , V_30 ) ;
int V_144 ;
V_3 -> V_32 = 1 ;
do {
V_144 = F_61 ( V_145 , & V_3 -> V_31 ) ;
#ifdef F_55
if ( F_62 ( V_104 , & V_3 -> V_31 ) ) {
F_38 ( V_3 ) ;
F_63 ( & V_3 -> V_7 -> V_18 ) ;
}
#endif
if ( F_62 ( V_110 , & V_3 -> V_31 ) ) {
T_1 V_136 = F_58 ( V_3 ) ;
F_56 ( V_3 , V_136 ) ;
F_63 ( & V_3 -> V_7 -> V_18 ) ;
}
if ( F_62 ( V_111 , & V_3 -> V_31 ) ) {
T_2 V_64 ;
switch ( V_3 -> V_9 . V_10 ) {
case V_60 :
case V_59 :
V_3 -> V_9 . V_10 = V_61 ;
F_2 ( L_26 ) ;
V_64 = F_29 ( V_39 ) ;
V_64 |= V_112 ;
V_64 &= ~ ( V_108 | V_113 )
& V_65 ;
F_30 ( V_64 , V_39 ) ;
break;
case V_54 :
V_3 -> V_9 . V_10 = V_55 ;
F_2 ( L_37 ) ;
break;
case V_55 :
case V_42 :
case V_35 :
break;
default:
F_2 ( L_38 ,
F_14 ( V_3 ) ) ;
}
F_20 ( V_3 ) ;
F_63 ( & V_3 -> V_7 -> V_18 ) ;
}
if ( F_62 ( V_146 , & V_3 -> V_31 ) ) {
#ifdef F_64
F_32 ( V_3 , L_39 ) ;
if ( ! V_144 )
F_65 ( & V_3 -> V_147 , V_148 + V_149 ) ;
#endif
F_63 ( & V_3 -> V_7 -> V_18 ) ;
}
if ( V_3 -> V_31 )
F_27 ( & V_3 -> V_7 -> V_18 ,
L_40 ,
V_3 -> V_31 ) ;
if ( V_144 ) {
F_66 ( & V_3 -> V_7 -> V_18 , L_41 ) ;
break;
}
} while ( V_3 -> V_31 );
V_3 -> V_32 = 0 ;
}
static T_5 F_67 ( int V_96 , void * V_3 )
{
F_23 ( V_3 , V_110 ) ;
return V_105 ;
}
static void F_68 ( unsigned long V_97 )
{
F_23 ( ( void * ) V_97 , V_146 ) ;
}
static void F_69 ( struct V_17 * V_18 )
{
struct V_2 * V_3 ;
V_3 = F_70 ( V_18 ) ;
if ( V_3 -> V_150 )
V_3 -> V_150 ( V_18 ) ;
F_71 ( V_3 -> V_9 . V_19 ) ;
F_71 ( V_3 ) ;
}
static int T_7 F_72 ( struct V_151 * V_152 )
{
struct V_2 * V_3 ;
V_3 = F_73 ( V_152 ) ;
F_13 ( V_3 , V_153 , ~ 0 ) ;
F_13 ( V_3 , V_154 , ~ 0 ) ;
F_52 ( V_152 -> V_96 , V_3 ) ;
#ifdef F_55
F_51 ( V_3 ) ;
#endif
if ( F_74 () )
F_75 ( 2 ) ;
V_3 -> V_147 . V_155 = 0 ;
F_76 ( V_145 , & V_3 -> V_31 ) ;
F_77 ( & V_3 -> V_147 ) ;
F_78 ( & V_3 -> V_30 ) ;
F_63 ( & V_152 -> V_18 ) ;
V_156 = NULL ;
return 0 ;
}
static int F_79 ( struct V_2 * V_3 )
{
F_17 ( V_3 ) ;
F_44 ( V_3 ) ;
F_11 ( V_3 , V_154 ,
V_72 | V_70 | V_73 ) ;
F_11 ( V_3 , V_153 ,
V_72 | V_70 | V_73 ) ;
F_80 ( & V_3 -> V_7 -> V_18 , L_42 ) ;
return 0 ;
}
static int
F_81 ( struct V_102 * V_19 , struct V_157 * V_20 )
{
struct V_2 * V_3 = F_60 ( V_19 -> V_9 , struct V_2 , V_9 ) ;
if ( ! V_19 || V_3 != V_156 )
return - V_21 ;
if ( ! V_20 ) {
F_41 ( 0 , V_129 ) ;
F_16 ( V_3 ) ;
V_19 -> V_20 = NULL ;
return 0 ;
}
#ifdef F_55
V_19 -> V_20 = V_20 ;
F_66 ( & V_3 -> V_7 -> V_18 , L_43 ) ;
F_18 ( V_3 ) ;
if ( V_19 -> V_26 )
return F_79 ( V_3 ) ;
return 0 ;
#elif ! F_82 ( V_158 )
V_19 -> V_20 = V_20 ;
F_17 ( V_3 ) ;
if ( F_74 () )
F_11 ( V_3 , V_12 , V_16 ) ;
F_80 ( & V_3 -> V_7 -> V_18 , L_44 ) ;
F_11 ( V_3 , V_154 ,
V_73 ) ;
F_11 ( V_3 , V_153 ,
V_73 ) ;
F_11 ( V_3 , V_14 , V_90 ) ;
F_32 ( V_3 , V_95 ) ;
return 0 ;
#else
F_66 ( & V_3 -> V_7 -> V_18 , L_45 ) ;
return - V_159 ;
#endif
}
static int
F_83 ( struct V_102 * V_19 , struct V_160 * V_26 )
{
struct V_2 * V_3 = F_60 ( V_19 -> V_9 , struct V_2 , V_9 ) ;
if ( ! V_19 || V_3 != V_156 )
return - V_21 ;
if ( ! V_26 ) {
F_41 ( 0 , V_129 ) ;
if ( ! V_19 -> V_36 )
F_3 ( V_3 , 0 ) ;
F_22 ( V_19 -> V_26 ) ;
V_19 -> V_26 = NULL ;
F_16 ( V_3 ) ;
return 0 ;
}
#ifdef F_55
V_19 -> V_26 = V_26 ;
F_66 ( & V_3 -> V_7 -> V_18 , L_46 ) ;
if ( V_19 -> V_20 )
return F_79 ( V_3 ) ;
return 0 ;
#elif ! F_82 ( V_161 ) && ! F_82 ( V_162 )
V_19 -> V_26 = V_26 ;
{
T_2 V_34 ;
V_34 = F_29 ( V_39 ) & V_65 ;
V_34 &= ~ ( V_40 | V_71 ) ;
V_34 |= V_67 ;
F_30 ( V_34 , V_39 ) ;
}
F_17 ( V_3 ) ;
V_3 -> V_9 . V_10 = V_42 ;
if ( F_74 () || F_84 () )
F_11 ( V_3 , V_12 , V_16 ) ;
F_11 ( V_3 , V_154 ,
V_70 ) ;
F_11 ( V_3 , V_153 ,
V_72 ) ;
F_80 ( & V_3 -> V_7 -> V_18 , L_47 ) ;
F_32 ( V_3 , V_95 ) ;
if ( F_7 ( V_3 , V_47 ) & V_72 )
F_53 ( V_3 ) ;
return 0 ;
#else
F_66 ( & V_3 -> V_7 -> V_18 , L_48 ) ;
return - V_159 ;
#endif
}
static int
F_85 ( struct V_163 * V_18 , unsigned V_1 )
{
if ( ! V_156 )
return - V_21 ;
if ( V_18 -> V_10 == V_52 )
F_3 ( V_156 , V_1 ) ;
return 0 ;
}
static int
F_86 ( struct V_102 * V_19 )
{
struct V_2 * V_3 = F_60 ( V_19 -> V_9 , struct V_2 , V_9 ) ;
T_2 V_64 ;
if ( ! V_19 || V_3 != V_156
|| V_3 -> V_9 . V_10 != V_42 )
return - V_21 ;
V_64 = F_29 ( V_39 ) ;
if ( ! ( V_64 & V_76 ) )
return - V_159 ;
V_64 |= V_113 ;
V_64 &= ~ V_112 & V_65 ;
F_30 ( V_64 , V_39 ) ;
V_3 -> V_9 . V_10 = V_53 ;
F_2 ( L_49 , F_14 ( V_3 ) ,
F_29 ( V_39 ) ) ;
#ifdef F_55
F_34 ( V_3 , V_95 ) ;
#endif
return 0 ;
}
static int
F_87 ( struct V_102 * V_19 )
{
#ifdef F_55
struct V_2 * V_3 = F_60 ( V_19 -> V_9 , struct V_2 , V_9 ) ;
T_2 V_34 ;
if ( ! V_19 || V_3 != V_156 )
return - V_21 ;
if ( V_19 -> V_36 && ( V_19 -> V_20 == NULL || ! V_19 -> V_20 -> V_27 ) )
return - V_164 ;
if ( ! V_19 -> V_36 && ( V_19 -> V_26 == NULL
|| ! V_19 -> V_26 -> V_27 ) )
return - V_164 ;
switch ( V_3 -> V_9 . V_10 ) {
case V_55 :
V_3 -> V_9 . V_10 = V_52 ;
break;
case V_61 :
#if 0
isp1301_set_bits(isp, ISP1301_MODE_CONTROL_1,
MC1_BDIS_ACON_EN);
#endif
F_54 ( V_19 -> V_26 ) ;
V_34 = F_29 ( V_39 ) ;
V_34 |= V_165 ;
F_30 ( V_34 , V_39 ) ;
break;
case V_58 :
break;
default:
return - V_166 ;
}
F_2 ( L_50 ,
F_14 ( V_3 ) , F_29 ( V_39 ) ) ;
F_34 ( V_3 , V_95 ) ;
return 0 ;
#else
return - V_159 ;
#endif
}
static int
F_88 ( struct V_151 * V_152 , const struct V_167 * V_168 )
{
int V_4 ;
struct V_2 * V_3 ;
if ( V_156 )
return 0 ;
V_3 = F_89 ( sizeof *V_3 , V_169 ) ;
if ( ! V_3 )
return 0 ;
V_3 -> V_9 . V_19 = F_89 ( sizeof * V_3 -> V_9 . V_19 , V_169 ) ;
if ( ! V_3 -> V_9 . V_19 ) {
F_71 ( V_3 ) ;
return 0 ;
}
F_90 ( & V_3 -> V_30 , F_59 ) ;
F_91 ( & V_3 -> V_147 ) ;
V_3 -> V_147 . V_170 = F_68 ;
V_3 -> V_147 . V_155 = ( unsigned long ) V_3 ;
F_92 ( V_152 , V_3 ) ;
V_3 -> V_7 = V_152 ;
V_4 = F_9 ( V_3 , V_171 ) ;
if ( V_4 != V_172 ) {
F_66 ( & V_152 -> V_18 , L_51 , V_4 ) ;
goto V_173;
}
V_4 = F_9 ( V_3 , V_174 ) ;
if ( V_4 != V_175 ) {
F_66 ( & V_152 -> V_18 , L_52 , V_4 ) ;
goto V_173;
}
V_3 -> V_150 = V_152 -> V_18 . V_176 ;
V_152 -> V_18 . V_176 = F_69 ;
V_4 = F_10 ( V_152 , V_177 ) ;
F_80 ( & V_152 -> V_18 , L_53 V_178 L_54 ,
V_4 >> 8 , V_4 & 0xff ) ;
F_13 ( V_3 , V_12 , V_179 ) ;
F_11 ( V_3 , V_180 , V_181 ) ;
F_13 ( V_3 , V_180 , ~ V_181 ) ;
F_11 ( V_3 , V_14 ,
V_81 | V_88 ) ;
F_13 ( V_3 , V_14 ,
~ ( V_81 | V_88 ) ) ;
F_13 ( V_3 , V_142 , ~ 0 ) ;
F_13 ( V_3 , V_153 , ~ 0 ) ;
F_13 ( V_3 , V_154 , ~ 0 ) ;
#ifdef F_55
V_4 = F_47 ( V_3 ) ;
if ( V_4 < 0 ) {
F_66 ( & V_152 -> V_18 , L_55 ) ;
goto V_173;
}
#endif
if ( F_74 () ) {
F_11 ( V_3 , V_12 ,
V_182 ) ;
F_11 ( V_3 , V_180 ,
V_183 ) ;
F_93 ( V_184 ) ;
if ( F_94 ( 2 , L_56 ) == 0 )
F_95 ( 2 ) ;
V_3 -> V_185 = V_186 ;
}
V_4 = F_49 ( V_152 -> V_96 , F_67 ,
V_3 -> V_185 , V_135 , V_3 ) ;
if ( V_4 < 0 ) {
F_66 ( & V_152 -> V_18 , L_57 ,
V_152 -> V_96 , V_4 ) ;
goto V_173;
}
V_3 -> V_9 . V_18 = & V_152 -> V_18 ;
V_3 -> V_9 . V_43 = V_135 ;
V_3 -> V_9 . V_187 = F_85 ,
V_3 -> V_9 . V_19 -> V_9 = & V_3 -> V_9 ;
V_3 -> V_9 . V_19 -> V_188 = F_81 ,
V_3 -> V_9 . V_19 -> V_189 = F_83 ,
V_3 -> V_9 . V_19 -> V_190 = F_86 ,
V_3 -> V_9 . V_19 -> V_191 = F_87 ,
F_3 ( V_3 , 0 ) ;
F_16 ( V_3 ) ;
V_156 = V_3 ;
#ifdef F_55
F_36 ( V_3 , F_7 ( V_3 , V_47 ) ) ;
F_37 ( V_3 , F_7 ( V_3 , V_45 ) ) ;
#endif
F_32 ( V_3 , V_95 ) ;
#ifdef F_64
F_65 ( & V_3 -> V_147 , V_148 + V_149 ) ;
F_66 ( & V_152 -> V_18 , L_58 , V_192 ) ;
#endif
V_4 = F_96 ( & V_3 -> V_9 , V_193 ) ;
if ( V_4 < 0 )
F_97 ( & V_152 -> V_18 , L_59 ,
V_4 ) ;
return 0 ;
V_173:
F_71 ( V_3 -> V_9 . V_19 ) ;
F_71 ( V_3 ) ;
return - V_21 ;
}
static int T_8 F_98 ( void )
{
return F_99 ( & V_194 ) ;
}
static void T_7 F_100 ( void )
{
if ( V_156 )
F_101 ( & V_156 -> V_9 ) ;
F_102 ( & V_194 ) ;
}
