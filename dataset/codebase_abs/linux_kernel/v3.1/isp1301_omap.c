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
if ( ! V_3 -> V_9 . V_19 )
return - V_20 ;
V_18 = V_3 -> V_9 . V_19 -> V_21 ;
return V_18 -> V_22 -> V_23 ( V_18 , 3 , 0 ) ;
#endif
}
static int F_20 ( struct V_2 * V_3 )
{
#ifdef F_19
return 0 ;
#else
struct V_17 * V_18 ;
if ( ! V_3 -> V_9 . V_19 )
return - V_20 ;
V_18 = V_3 -> V_9 . V_19 -> V_21 ;
return V_18 -> V_22 -> V_24 ( V_18 , 0 ) ;
#endif
}
static int F_21 ( struct V_2 * V_3 )
{
V_3 -> V_9 . V_25 -> V_26 = 0 ;
V_3 -> V_9 . V_25 -> V_27 = 0 ;
V_3 -> V_9 . V_25 -> V_28 = 0 ;
return F_22 ( V_3 -> V_9 . V_25 ) ;
}
static void F_23 ( struct V_2 * V_3 , int V_29 )
{
int V_4 ;
if ( V_3 && ! F_24 ( V_29 , & V_3 -> V_30 ) ) {
( void ) F_25 ( & V_3 -> V_7 -> V_18 ) ;
V_4 = F_26 ( & V_3 -> V_29 ) ;
if ( ! V_4 && ! V_3 -> V_31 )
F_27 ( & V_3 -> V_7 -> V_18 ,
L_4 , V_29 ) ;
}
}
static void F_28 ( struct V_2 * V_3 , const char * V_32 )
{
T_2 V_33 ;
if ( V_3 -> V_9 . V_10 == V_34 )
return;
V_3 -> V_9 . V_35 = 1 ;
if ( V_3 -> V_9 . V_19 ) {
V_3 -> V_9 . V_19 -> V_36 = 0 ;
F_18 ( V_3 ) ;
}
if ( V_3 -> V_9 . V_25 ) {
V_3 -> V_9 . V_25 -> V_37 = 1 ;
F_21 ( V_3 ) ;
}
V_3 -> V_9 . V_10 = V_34 ;
V_33 = F_29 ( V_38 ) & V_39 ;
F_30 ( V_33 , V_38 ) ;
V_3 -> V_40 = V_33 ;
F_2 ( L_5 , F_14 ( V_3 ) , V_32 ) ;
}
static void F_31 ( struct V_2 * V_3 , const char * V_32 )
{
T_2 V_33 ;
if ( V_3 -> V_9 . V_10 == V_41 )
return;
V_3 -> V_9 . V_35 = 0 ;
if ( V_3 -> V_9 . V_19 ) {
V_3 -> V_9 . V_19 -> V_36 = 1 ;
F_18 ( V_3 ) ;
}
if ( V_3 -> V_9 . V_25 ) {
V_3 -> V_9 . V_25 -> V_37 = 0 ;
F_21 ( V_3 ) ;
}
V_3 -> V_9 . V_10 = V_41 ;
V_33 = F_29 ( V_38 ) & V_39 ;
F_30 ( V_33 , V_38 ) ;
V_3 -> V_40 = V_33 ;
F_2 ( L_5 , F_14 ( V_3 ) , V_32 ) ;
}
static void
F_32 ( struct V_2 * V_3 , const char * V_42 )
{
#ifdef F_33
T_1 V_43 = F_7 ( V_3 , V_14 ) ;
T_1 V_4 = F_7 ( V_3 , V_44 ) ;
T_1 V_45 = F_7 ( V_3 , V_46 ) ;
F_2 ( L_6 ,
F_29 ( V_38 ) , V_42 , F_14 ( V_3 ) ,
V_43 , V_4 , V_45 ) ;
#endif
}
static void F_34 ( struct V_2 * V_3 , const char * V_32 )
{
enum V_47 V_10 = V_11 ;
T_1 V_48 = F_35 ( V_49 ) & 0x0ff ;
unsigned V_50 = 0 ;
switch ( V_48 ) {
case 0x0 :
V_10 = V_41 ;
break;
case 0x3 :
case 0x7 :
V_50 = 1 ;
case 0x1 :
V_10 = V_51 ;
break;
case 0x11 :
V_10 = V_52 ;
break;
case 0x12 :
case 0x13 :
case 0x16 :
V_50 = 1 ;
case 0x17 :
V_10 = V_53 ;
break;
case 0x34 :
V_10 = V_54 ;
break;
case 0x36 :
V_10 = V_34 ;
break;
case 0x3c :
V_10 = V_55 ;
break;
case 0x7d :
V_10 = V_56 ;
break;
case 0x9e :
case 0x9f :
V_50 = 1 ;
case 0x89 :
V_10 = V_57 ;
break;
case 0xb7 :
V_10 = V_58 ;
break;
case 0xb8 :
V_10 = V_59 ;
break;
case 0xb9 :
V_10 = V_60 ;
break;
case 0xba :
V_10 = V_61 ;
break;
default:
break;
}
if ( V_3 -> V_9 . V_10 == V_10 && ! V_50 )
return;
F_2 ( L_7 , V_32 ,
F_15 ( V_10 ) , V_48 , F_14 ( V_3 ) ,
F_29 ( V_38 ) ) ;
}
static inline void F_34 ( struct V_2 * V_3 , const char * V_32 ) { }
static void F_36 ( struct V_2 * V_3 , T_1 V_62 )
{
T_2 V_63 ;
V_63 = F_29 ( V_38 ) & V_64 ;
V_63 &= ~ V_65 ;
V_63 &= ~ ( V_66 | V_67 | V_68 ) ;
if ( V_62 & V_69 )
V_63 |= V_67 ;
else if ( V_3 -> V_9 . V_10 == V_55 ) {
F_28 ( V_3 , L_8 ) ;
V_63 &= ~ V_70 ;
}
if ( V_62 & V_71 )
V_63 |= V_68 ;
if ( V_62 & V_72 ) {
if ( V_3 -> V_9 . V_10 == V_41
|| V_3 -> V_9 . V_10 == V_11 ) {
F_28 ( V_3 , L_9 ) ;
return;
}
} else {
V_63 |= V_66 ;
if ( V_3 -> V_9 . V_10 == V_34
|| V_3 -> V_9 . V_10 == V_11 ) {
F_31 ( V_3 , L_9 ) ;
return;
}
}
F_30 ( V_63 , V_38 ) ;
}
static void F_37 ( struct V_2 * V_3 , T_1 V_73 )
{
T_2 V_63 ;
V_63 = F_29 ( V_38 ) & V_64 ;
V_63 &= ~ V_65 ;
V_63 &= ~ ( V_74 | V_75 ) ;
if ( V_73 & V_76 )
V_63 |= V_74 ;
else if ( V_73 & V_77 )
V_63 |= V_75 ;
F_30 ( V_63 , V_38 ) ;
}
static void F_38 ( struct V_2 * V_3 )
{
T_2 V_63 , V_78 ;
T_1 V_79 = V_80 , V_81 = V_82 ;
V_63 = F_29 ( V_38 ) ;
V_78 = V_63 ^ V_3 -> V_40 ;
V_3 -> V_40 = V_63 ;
V_63 = V_63 & V_65 ;
switch ( V_3 -> V_9 . V_10 ) {
case V_41 :
case V_51 :
case V_52 :
if ( ! ( V_63 & V_83 ) ) {
if ( V_3 -> V_9 . V_25 -> V_26 ) {
V_3 -> V_9 . V_10 = V_53 ;
F_2 ( L_10 ) ;
}
goto V_84;
}
V_85:
V_79 |= V_86 ;
V_81 |= V_87 ;
break;
case V_61 :
case V_57 :
if ( V_63 & V_83 )
goto V_85;
default:
V_84:
V_79 |= V_87 ;
V_81 |= V_86 ;
break;
}
# define F_39 ( T_3 , T_4 ) do { \
if (otg_ctrl & OTG) set |= ISP; \
else clr |= ISP; \
} while (0)
if ( ! ( V_3 -> V_9 . V_19 ) )
V_63 &= ~ V_88 ;
switch ( V_3 -> V_9 . V_10 ) {
case V_61 :
if ( V_63 & V_88 ) {
V_79 |= V_89 ;
break;
}
F_5 ( V_3 ) ;
case V_56 :
V_3 -> V_9 . V_10 = V_55 ;
F_2 ( L_11 ) ;
case V_55 :
V_81 |= V_89 ;
break;
case V_34 :
if ( V_63 & V_88 ) {
V_3 -> V_9 . V_10 = V_58 ;
F_2 ( L_12 ) ;
}
default:
F_39 ( V_88 , V_89 ) ;
}
F_39 ( V_90 , V_91 ) ;
F_39 ( V_92 , V_93 ) ;
# undef F_39
F_11 ( V_3 , V_14 , V_79 ) ;
F_13 ( V_3 , V_14 , V_81 ) ;
if ( V_78 & V_83 ) {
T_2 V_33 ;
switch ( V_3 -> V_9 . V_10 ) {
case V_41 :
if ( V_81 & V_86 )
break;
V_3 -> V_9 . V_10 = V_51 ;
F_2 ( L_13 ) ;
break;
case V_61 :
if ( V_81 & V_86 )
break;
V_3 -> V_9 . V_10 = V_57 ;
F_2 ( L_14 ) ;
break;
default:
break;
}
V_33 = F_29 ( V_38 ) ;
V_33 |= V_83 ;
F_30 ( V_33 , V_38 ) ;
}
F_34 ( V_3 , V_94 ) ;
F_32 ( V_3 , L_15 ) ;
}
static T_5 F_40 ( int V_95 , void * V_96 )
{
T_6 V_97 = F_35 ( V_98 ) ;
T_2 V_63 ;
int V_99 = V_100 ;
struct V_2 * V_3 = V_96 ;
if ( V_97 & V_101 ) {
F_41 ( V_101 , V_98 ) ;
F_23 ( V_3 , V_102 ) ;
V_99 = V_103 ;
} else if ( V_97 & V_104 ) {
F_2 ( L_16 , F_29 ( V_38 ) ) ;
F_5 ( V_3 ) ;
if ( V_3 -> V_9 . V_10 == V_52 )
F_31 ( V_3 , L_17 ) ;
F_41 ( V_104 , V_98 ) ;
V_99 = V_103 ;
} else if ( V_97 & V_105 ) {
F_2 ( L_18 ,
F_14 ( V_3 ) , F_29 ( V_38 ) ) ;
F_5 ( V_3 ) ;
V_63 = F_29 ( V_38 ) ;
V_63 |= V_106 ;
V_63 &= V_64 & ~ V_65 ;
F_30 ( V_63 , V_38 ) ;
V_3 -> V_9 . V_10 = V_51 ;
F_2 ( L_13 ) ;
F_41 ( V_105 , V_98 ) ;
V_99 = V_103 ;
} else if ( V_97 & V_107 ) {
F_2 ( L_19 ,
F_14 ( V_3 ) , F_29 ( V_38 ) ) ;
F_23 ( V_3 , V_108 ) ;
switch ( V_3 -> V_9 . V_10 ) {
case V_34 :
if ( ! V_3 -> V_9 . V_19 )
break;
F_23 ( V_3 , V_109 ) ;
V_63 = F_29 ( V_38 ) ;
V_63 |= V_110 ;
V_63 &= ~ ( V_106 | V_111 )
& ~ V_65
& V_64 ;
F_30 ( V_63 , V_38 ) ;
break;
default:
break;
}
F_41 ( V_107 , V_98 ) ;
V_99 = V_103 ;
} else if ( V_97 & V_112 ) {
V_63 = F_29 ( V_38 ) ;
F_42 ( L_20 ,
F_14 ( V_3 ) , V_63 ) ;
F_5 ( V_3 ) ;
V_63 |= V_106 ;
V_63 &= ~ V_110 & V_64 & ~ V_65 ;
F_30 ( V_63 , V_38 ) ;
V_3 -> V_9 . V_10 = V_55 ;
F_41 ( V_112 , V_98 ) ;
V_99 = V_103 ;
} else if ( V_97 & V_113 ) {
V_63 = F_29 ( V_38 ) ;
F_6 ( V_114 L_21 ,
F_14 ( V_3 ) , V_97 , V_63 ) ;
V_63 |= V_106 ;
V_63 &= ~ V_110 & V_64 & ~ V_65 ;
F_30 ( V_63 , V_38 ) ;
V_3 -> V_9 . V_10 = V_56 ;
F_41 ( V_113 , V_98 ) ;
V_99 = V_103 ;
} else if ( V_97 & V_115 ) {
int V_116 = 0 ;
V_63 = F_29 ( V_38 ) ;
F_6 ( V_5 L_22 ,
F_14 ( V_3 ) ,
( V_63 & V_117 )
? L_23 : L_24 ,
V_63 ) ;
F_23 ( V_3 , V_102 ) ;
if ( V_63 & V_117 ) {
switch ( V_3 -> V_9 . V_10 ) {
case V_34 :
F_31 ( V_3 , V_94 ) ;
break;
default:
break;
}
F_23 ( V_3 , V_102 ) ;
} else {
if ( ! ( V_63 & V_66 ) ) {
V_63 &= V_64 & ~ V_65 ;
F_30 ( V_63 | V_110 , V_38 ) ;
}
if ( V_3 -> V_9 . V_19 ) {
switch ( V_3 -> V_9 . V_10 ) {
case V_53 :
V_3 -> V_9 . V_10 = V_54 ;
F_2 ( L_25 ) ;
V_116 = 1 ;
break;
case V_59 :
V_3 -> V_9 . V_10 = V_60 ;
F_2 ( L_26 ) ;
break;
case V_57 :
V_3 -> V_9 . V_10 = V_59 ;
F_2 ( L_27 ) ;
break;
default:
break;
}
F_23 ( V_3 , V_109 ) ;
}
}
F_41 ( V_115 , V_98 ) ;
V_99 = V_103 ;
if ( V_116 )
F_43 ( V_3 -> V_9 . V_19 ,
V_3 -> V_9 . V_19 -> V_118 ) ;
}
F_34 ( V_3 , V_94 ) ;
return V_99 ;
}
static int F_44 ( struct V_2 * V_3 )
{
T_2 V_33 ;
if ( ! V_119 )
return - V_20 ;
F_32 ( V_3 , V_94 ) ;
V_33 = F_29 ( V_120 ) ;
V_33 |= V_121
| V_122
| V_123
| ( 0 << 20 )
| V_124
| V_125 | V_126
;
F_30 ( V_33 , V_120 ) ;
F_36 ( V_3 , F_7 ( V_3 , V_46 ) ) ;
F_37 ( V_3 , F_7 ( V_3 , V_44 ) ) ;
F_34 ( V_3 , V_94 ) ;
F_2 ( L_28 ,
F_14 ( V_3 ) , V_94 , F_29 ( V_38 ) ) ;
F_41 ( V_115 | V_101
| V_104 | V_105
| V_113 | V_107 | V_112 , V_127 ) ;
V_33 = F_29 ( V_120 ) ;
V_33 |= V_121 ;
F_30 ( V_33 , V_120 ) ;
return 0 ;
}
static int F_45 ( struct V_128 * V_18 )
{
V_119 = V_18 ;
return 0 ;
}
static int F_46 ( struct V_128 * V_18 )
{
V_119 = NULL ;
return 0 ;
}
static int F_47 ( struct V_2 * V_3 )
{
int V_4 ;
if ( V_119 )
return - V_129 ;
V_4 = F_48 ( & V_130 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_119 )
V_4 = F_49 ( V_119 -> V_131 [ 1 ] . V_132 , F_40 ,
V_133 , V_134 , V_3 ) ;
else
V_4 = - V_20 ;
if ( V_4 < 0 )
F_50 ( & V_130 ) ;
return V_4 ;
}
static void F_51 ( struct V_2 * V_3 )
{
if ( ! V_119 )
return;
F_52 ( V_119 -> V_131 [ 1 ] . V_132 , V_3 ) ;
}
static void F_53 ( struct V_2 * V_3 )
{
T_2 V_33 ;
V_33 = F_29 ( V_38 ) & V_39 ;
F_30 ( V_33 , V_38 ) ;
F_54 ( V_3 -> V_9 . V_25 ) ;
#ifdef F_55
F_3 ( V_3 , 8 ) ;
F_38 ( V_3 ) ;
#else
F_3 ( V_3 , 100 ) ;
F_11 ( V_3 , V_14 , V_86 ) ;
F_13 ( V_3 , V_14 , V_87 ) ;
V_3 -> V_9 . V_10 = V_51 ;
F_2 ( L_13 ) ;
F_32 ( V_3 , L_29 ) ;
#endif
}
static void F_56 ( struct V_2 * V_3 , T_1 V_135 )
{
T_1 V_136 , V_137 ;
enum V_47 V_10 = V_3 -> V_9 . V_10 ;
if ( V_135 & V_138 )
F_2 ( L_30 , F_14 ( V_3 ) ) ;
V_136 = F_7 ( V_3 , V_46 ) ;
if ( V_136 & V_72 ) {
if ( V_3 -> V_9 . V_35 ) {
switch ( V_10 ) {
case V_41 :
F_28 ( V_3 , L_31 ) ;
case V_34 :
F_4 ( V_3 ) ;
case V_58 :
if ( V_136 & V_71 )
V_3 -> V_9 . V_10 = V_60 ;
break;
case V_55 :
if ( ! ( V_136 & V_69 ) )
F_28 ( V_3 , L_32 ) ;
break;
default:
if ( ! ( V_136 & V_71 ) )
V_3 -> V_9 . V_10 = V_56 ;
break;
}
V_137 = F_7 ( V_3 , V_44 ) ;
} else {
switch ( V_10 ) {
case V_51 :
case V_54 :
case V_53 :
F_22 ( V_3 -> V_9 . V_25 ) ;
break;
default:
break;
}
if ( V_10 != V_34 )
F_28 ( V_3 , L_33 ) ;
if ( V_3 -> V_9 . V_19 && V_10 == V_34 )
F_23 ( V_3 , V_109 ) ;
V_137 = 0 ;
}
} else {
T_2 V_33 ;
if ( V_3 -> V_9 . V_35 ) {
switch ( V_10 ) {
default:
V_3 -> V_9 . V_10 = V_55 ;
break;
case V_55 :
V_10 = V_34 ;
break;
case V_34 :
F_18 ( V_3 ) ;
F_13 ( V_3 , V_12 ,
V_139 ) ;
V_3 -> V_9 . V_10 = V_41 ;
V_33 = F_29 ( V_38 ) & V_64 ;
V_33 &= ~ V_70 ;
F_30 ( V_33 , V_38 ) ;
break;
case V_41 :
break;
}
}
V_137 = F_7 ( V_3 , V_44 ) ;
switch ( V_3 -> V_9 . V_10 ) {
case V_51 :
case V_53 :
case V_54 :
if ( F_57 ( V_137 & V_76 ) )
break;
F_3 ( V_3 , 0 ) ;
#ifndef F_55
F_11 ( V_3 , V_14 ,
V_87 ) ;
F_13 ( V_3 , V_14 ,
V_86 ) ;
F_32 ( V_3 , V_94 ) ;
#endif
case V_52 :
F_31 ( V_3 , V_94 ) ;
V_33 = F_29 ( V_38 ) & V_39 ;
F_30 ( V_33 , V_38 ) ;
case V_41 :
if ( V_3 -> V_9 . V_25 && ( V_137 & V_76 ) ) {
#ifdef F_55
F_36 ( V_3 , V_136 ) ;
F_37 ( V_3 , V_137 ) ;
#endif
F_53 ( V_3 ) ;
} else if ( ! ( V_136 & ( V_71 | V_69 ) ) )
V_137 |= V_77 ;
break;
case V_55 :
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
F_36 ( V_3 , V_136 ) ;
F_37 ( V_3 , V_137 ) ;
F_34 ( V_3 , V_94 ) ;
#endif
F_32 ( V_3 , L_36 ) ;
}
static T_1 F_58 ( struct V_2 * V_3 )
{
T_1 V_140 = F_7 ( V_3 , V_141 ) ;
F_13 ( V_3 , V_141 , V_140 ) ;
return V_140 ;
}
static void
F_59 ( struct V_142 * V_29 )
{
struct V_2 * V_3 = F_60 ( V_29 , struct V_2 , V_29 ) ;
int V_143 ;
V_3 -> V_31 = 1 ;
do {
V_143 = F_61 ( V_144 , & V_3 -> V_30 ) ;
#ifdef F_55
if ( F_62 ( V_102 , & V_3 -> V_30 ) ) {
F_38 ( V_3 ) ;
F_63 ( & V_3 -> V_7 -> V_18 ) ;
}
#endif
if ( F_62 ( V_108 , & V_3 -> V_30 ) ) {
T_1 V_135 = F_58 ( V_3 ) ;
F_56 ( V_3 , V_135 ) ;
F_63 ( & V_3 -> V_7 -> V_18 ) ;
}
if ( F_62 ( V_109 , & V_3 -> V_30 ) ) {
T_2 V_63 ;
switch ( V_3 -> V_9 . V_10 ) {
case V_59 :
case V_58 :
V_3 -> V_9 . V_10 = V_60 ;
F_2 ( L_26 ) ;
V_63 = F_29 ( V_38 ) ;
V_63 |= V_110 ;
V_63 &= ~ ( V_106 | V_111 )
& V_64 ;
F_30 ( V_63 , V_38 ) ;
break;
case V_53 :
V_3 -> V_9 . V_10 = V_54 ;
F_2 ( L_37 ) ;
break;
case V_54 :
case V_41 :
case V_34 :
break;
default:
F_2 ( L_38 ,
F_14 ( V_3 ) ) ;
}
F_20 ( V_3 ) ;
F_63 ( & V_3 -> V_7 -> V_18 ) ;
}
if ( F_62 ( V_145 , & V_3 -> V_30 ) ) {
#ifdef F_64
F_32 ( V_3 , L_39 ) ;
if ( ! V_143 )
F_65 ( & V_3 -> V_146 , V_147 + V_148 ) ;
#endif
F_63 ( & V_3 -> V_7 -> V_18 ) ;
}
if ( V_3 -> V_30 )
F_27 ( & V_3 -> V_7 -> V_18 ,
L_40 ,
V_3 -> V_30 ) ;
if ( V_143 ) {
F_66 ( & V_3 -> V_7 -> V_18 , L_41 ) ;
break;
}
} while ( V_3 -> V_30 );
V_3 -> V_31 = 0 ;
}
static T_5 F_67 ( int V_95 , void * V_3 )
{
F_23 ( V_3 , V_108 ) ;
return V_103 ;
}
static void F_68 ( unsigned long V_96 )
{
F_23 ( ( void * ) V_96 , V_145 ) ;
}
static void F_69 ( struct V_17 * V_18 )
{
struct V_2 * V_3 ;
V_3 = F_70 ( V_18 ) ;
if ( V_3 -> V_149 )
V_3 -> V_149 ( V_18 ) ;
F_71 ( V_3 ) ;
}
static int T_7 F_72 ( struct V_150 * V_151 )
{
struct V_2 * V_3 ;
V_3 = F_73 ( V_151 ) ;
F_13 ( V_3 , V_152 , ~ 0 ) ;
F_13 ( V_3 , V_153 , ~ 0 ) ;
F_52 ( V_151 -> V_95 , V_3 ) ;
#ifdef F_55
F_51 ( V_3 ) ;
#endif
if ( F_74 () )
F_75 ( 2 ) ;
V_3 -> V_146 . V_154 = 0 ;
F_76 ( V_144 , & V_3 -> V_30 ) ;
F_77 ( & V_3 -> V_146 ) ;
F_78 ( & V_3 -> V_29 ) ;
F_63 ( & V_151 -> V_18 ) ;
V_155 = NULL ;
return 0 ;
}
static int F_79 ( struct V_2 * V_3 )
{
F_17 ( V_3 ) ;
F_44 ( V_3 ) ;
F_11 ( V_3 , V_153 ,
V_71 | V_69 | V_72 ) ;
F_11 ( V_3 , V_152 ,
V_71 | V_69 | V_72 ) ;
F_80 ( & V_3 -> V_7 -> V_18 , L_42 ) ;
return 0 ;
}
static int
F_81 ( struct V_156 * V_9 , struct V_157 * V_19 )
{
struct V_2 * V_3 = F_60 ( V_9 , struct V_2 , V_9 ) ;
if ( ! V_9 || V_3 != V_155 )
return - V_20 ;
if ( ! V_19 ) {
F_41 ( 0 , V_127 ) ;
F_16 ( V_3 ) ;
V_3 -> V_9 . V_19 = NULL ;
return 0 ;
}
#ifdef F_55
V_3 -> V_9 . V_19 = V_19 ;
F_66 ( & V_3 -> V_7 -> V_18 , L_43 ) ;
F_18 ( V_3 ) ;
if ( V_3 -> V_9 . V_25 )
return F_79 ( V_3 ) ;
return 0 ;
#elif ! F_82 ( V_158 )
V_3 -> V_9 . V_19 = V_19 ;
F_17 ( V_3 ) ;
if ( F_74 () )
F_11 ( V_3 , V_12 , V_16 ) ;
F_80 ( & V_3 -> V_7 -> V_18 , L_44 ) ;
F_11 ( V_3 , V_153 ,
V_72 ) ;
F_11 ( V_3 , V_152 ,
V_72 ) ;
F_11 ( V_3 , V_14 , V_89 ) ;
F_32 ( V_3 , V_94 ) ;
return 0 ;
#else
F_66 ( & V_3 -> V_7 -> V_18 , L_45 ) ;
return - V_159 ;
#endif
}
static int
F_83 ( struct V_156 * V_9 , struct V_160 * V_25 )
{
struct V_2 * V_3 = F_60 ( V_9 , struct V_2 , V_9 ) ;
#ifndef F_55
T_2 V_33 ;
#endif
if ( ! V_9 || V_3 != V_155 )
return - V_20 ;
if ( ! V_25 ) {
F_41 ( 0 , V_127 ) ;
if ( ! V_3 -> V_9 . V_35 )
F_3 ( V_3 , 0 ) ;
F_22 ( V_3 -> V_9 . V_25 ) ;
V_3 -> V_9 . V_25 = NULL ;
F_16 ( V_3 ) ;
return 0 ;
}
#ifdef F_55
V_3 -> V_9 . V_25 = V_25 ;
F_66 ( & V_3 -> V_7 -> V_18 , L_46 ) ;
if ( V_3 -> V_9 . V_19 )
return F_79 ( V_3 ) ;
return 0 ;
#elif ! F_82 ( V_161 ) && ! F_82 ( V_162 )
V_3 -> V_9 . V_25 = V_25 ;
V_33 = F_29 ( V_38 ) & V_64 ;
V_33 &= ~ ( V_39 | V_70 ) ;
V_33 |= V_66 ;
F_30 ( V_33 , V_38 ) ;
F_17 ( V_3 ) ;
V_3 -> V_9 . V_10 = V_41 ;
if ( F_74 () || F_84 () )
F_11 ( V_3 , V_12 , V_16 ) ;
F_11 ( V_3 , V_153 ,
V_69 ) ;
F_11 ( V_3 , V_152 ,
V_71 ) ;
F_80 ( & V_3 -> V_7 -> V_18 , L_47 ) ;
F_32 ( V_3 , V_94 ) ;
if ( F_7 ( V_3 , V_46 ) & V_71 )
F_53 ( V_3 ) ;
return 0 ;
#else
F_66 ( & V_3 -> V_7 -> V_18 , L_48 ) ;
return - V_159 ;
#endif
}
static int
F_85 ( struct V_156 * V_18 , unsigned V_1 )
{
if ( ! V_155 )
return - V_20 ;
if ( V_18 -> V_10 == V_51 )
F_3 ( V_155 , V_1 ) ;
return 0 ;
}
static int
F_86 ( struct V_156 * V_18 )
{
struct V_2 * V_3 = F_60 ( V_18 , struct V_2 , V_9 ) ;
T_2 V_63 ;
if ( ! V_18 || V_3 != V_155
|| V_3 -> V_9 . V_10 != V_41 )
return - V_20 ;
V_63 = F_29 ( V_38 ) ;
if ( ! ( V_63 & V_75 ) )
return - V_159 ;
V_63 |= V_111 ;
V_63 &= ~ V_110 & V_64 ;
F_30 ( V_63 , V_38 ) ;
V_3 -> V_9 . V_10 = V_52 ;
F_2 ( L_49 , F_14 ( V_3 ) ,
F_29 ( V_38 ) ) ;
#ifdef F_55
F_34 ( V_3 , V_94 ) ;
#endif
return 0 ;
}
static int
F_87 ( struct V_156 * V_18 )
{
#ifdef F_55
struct V_2 * V_3 = F_60 ( V_18 , struct V_2 , V_9 ) ;
T_2 V_33 ;
if ( ! V_18 || V_3 != V_155 )
return - V_20 ;
if ( V_3 -> V_9 . V_35 && ( V_3 -> V_9 . V_19 == NULL
|| ! V_3 -> V_9 . V_19 -> V_26 ) )
return - V_163 ;
if ( ! V_3 -> V_9 . V_35 && ( V_3 -> V_9 . V_25 == NULL
|| ! V_3 -> V_9 . V_25 -> V_26 ) )
return - V_163 ;
switch ( V_3 -> V_9 . V_10 ) {
case V_54 :
V_3 -> V_9 . V_10 = V_51 ;
break;
case V_60 :
#if 0
isp1301_set_bits(isp, ISP1301_MODE_CONTROL_1,
MC1_BDIS_ACON_EN);
#endif
F_54 ( V_3 -> V_9 . V_25 ) ;
V_33 = F_29 ( V_38 ) ;
V_33 |= V_164 ;
F_30 ( V_33 , V_38 ) ;
break;
case V_57 :
break;
default:
return - V_165 ;
}
F_2 ( L_50 ,
F_14 ( V_3 ) , F_29 ( V_38 ) ) ;
F_34 ( V_3 , V_94 ) ;
return 0 ;
#else
return - V_159 ;
#endif
}
static int T_8
F_88 ( struct V_150 * V_151 , const struct V_166 * V_167 )
{
int V_4 ;
struct V_2 * V_3 ;
if ( V_155 )
return 0 ;
V_3 = F_89 ( sizeof *V_3 , V_168 ) ;
if ( ! V_3 )
return 0 ;
F_90 ( & V_3 -> V_29 , F_59 ) ;
F_91 ( & V_3 -> V_146 ) ;
V_3 -> V_146 . V_169 = F_68 ;
V_3 -> V_146 . V_154 = ( unsigned long ) V_3 ;
F_92 ( V_151 , V_3 ) ;
V_3 -> V_7 = V_151 ;
V_4 = F_9 ( V_3 , V_170 ) ;
if ( V_4 != V_171 ) {
F_66 ( & V_151 -> V_18 , L_51 , V_4 ) ;
goto V_172;
}
V_4 = F_9 ( V_3 , V_173 ) ;
if ( V_4 != V_174 ) {
F_66 ( & V_151 -> V_18 , L_52 , V_4 ) ;
goto V_172;
}
V_3 -> V_149 = V_151 -> V_18 . V_175 ;
V_151 -> V_18 . V_175 = F_69 ;
V_4 = F_10 ( V_151 , V_176 ) ;
F_80 ( & V_151 -> V_18 , L_53 V_177 L_54 ,
V_4 >> 8 , V_4 & 0xff ) ;
F_13 ( V_3 , V_12 , V_178 ) ;
F_11 ( V_3 , V_179 , V_180 ) ;
F_13 ( V_3 , V_179 , ~ V_180 ) ;
F_11 ( V_3 , V_14 ,
V_80 | V_87 ) ;
F_13 ( V_3 , V_14 ,
~ ( V_80 | V_87 ) ) ;
F_13 ( V_3 , V_141 , ~ 0 ) ;
F_13 ( V_3 , V_152 , ~ 0 ) ;
F_13 ( V_3 , V_153 , ~ 0 ) ;
#ifdef F_55
V_4 = F_47 ( V_3 ) ;
if ( V_4 < 0 ) {
F_66 ( & V_151 -> V_18 , L_55 ) ;
goto V_172;
}
#endif
if ( F_74 () ) {
F_11 ( V_3 , V_12 ,
V_181 ) ;
F_11 ( V_3 , V_179 ,
V_182 ) ;
F_93 ( V_183 ) ;
if ( F_94 ( 2 , L_56 ) == 0 )
F_95 ( 2 ) ;
V_3 -> V_184 = V_185 ;
}
V_3 -> V_184 |= V_186 ;
V_4 = F_49 ( V_151 -> V_95 , F_67 ,
V_3 -> V_184 , V_134 , V_3 ) ;
if ( V_4 < 0 ) {
F_66 ( & V_151 -> V_18 , L_57 ,
V_151 -> V_95 , V_4 ) ;
goto V_172;
}
V_3 -> V_9 . V_18 = & V_151 -> V_18 ;
V_3 -> V_9 . V_42 = V_134 ;
V_3 -> V_9 . V_187 = F_81 ,
V_3 -> V_9 . V_188 = F_83 ,
V_3 -> V_9 . V_189 = F_85 ,
V_3 -> V_9 . V_190 = F_86 ,
V_3 -> V_9 . V_191 = F_87 ,
F_3 ( V_3 , 0 ) ;
F_16 ( V_3 ) ;
V_155 = V_3 ;
#ifdef F_55
F_36 ( V_3 , F_7 ( V_3 , V_46 ) ) ;
F_37 ( V_3 , F_7 ( V_3 , V_44 ) ) ;
#endif
F_32 ( V_3 , V_94 ) ;
#ifdef F_64
F_65 ( & V_3 -> V_146 , V_147 + V_148 ) ;
F_66 ( & V_151 -> V_18 , L_58 , V_192 ) ;
#endif
V_4 = F_96 ( & V_3 -> V_9 ) ;
if ( V_4 < 0 )
F_97 ( & V_151 -> V_18 , L_59 ,
V_4 ) ;
return 0 ;
V_172:
F_71 ( V_3 ) ;
return - V_20 ;
}
static int T_9 F_98 ( void )
{
return F_99 ( & V_193 ) ;
}
static void T_7 F_100 ( void )
{
if ( V_155 )
F_96 ( NULL ) ;
F_101 ( & V_193 ) ;
}
