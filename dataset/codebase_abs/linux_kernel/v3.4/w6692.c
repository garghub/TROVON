static void
F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 = V_4 ;
V_2 -> V_5 [ 0 ] . V_6 . V_4 = V_4 ;
V_2 -> V_5 [ 1 ] . V_6 . V_4 = V_4 ;
}
static int
F_2 ( const char * V_7 , struct V_8 * V_9 )
{
int V_10 ;
struct V_1 * V_2 ;
V_10 = F_3 ( V_7 , V_9 ) ;
if ( ! V_10 ) {
F_4 ( & V_11 ) ;
F_5 (card, &Cards, list)
F_1 ( V_2 ) ;
F_6 ( & V_11 ) ;
}
return V_10 ;
}
static inline T_1
F_7 ( struct V_1 * V_2 , T_1 V_12 )
{
return F_8 ( V_2 -> V_13 + V_12 ) ;
}
static inline void
F_9 ( struct V_1 * V_2 , T_1 V_12 , T_1 V_14 )
{
F_10 ( V_14 , V_2 -> V_13 + V_12 ) ;
}
static inline T_1
F_11 ( struct V_15 * V_5 , T_1 V_12 )
{
return F_8 ( V_5 -> V_13 + V_12 ) ;
}
static inline void
F_12 ( struct V_15 * V_5 , T_1 V_12 , T_1 V_14 )
{
F_10 ( V_14 , V_5 -> V_13 + V_12 ) ;
}
static void
F_13 ( struct V_1 * V_2 )
{
F_9 ( V_2 , V_16 , V_2 -> V_17 ) ;
}
static void
F_14 ( struct V_1 * V_2 )
{
F_9 ( V_2 , V_16 , 0xff ) ;
}
static void
F_15 ( struct V_1 * V_2 )
{
int V_7 ;
V_7 = F_7 ( V_2 , V_18 ) ;
F_16 ( L_1 , V_2 -> V_19 ,
V_20 [ ( V_7 >> 6 ) & 3 ] ) ;
}
static void
F_17 ( struct V_1 * V_2 , int V_21 )
{
if ( ( ! ( V_2 -> V_22 & V_23 ) ) || V_2 -> V_24 == V_25 )
return;
if ( V_21 ) {
V_2 -> V_26 &= 0xfb ;
F_9 ( V_2 , V_27 , V_2 -> V_26 ) ;
} else {
V_2 -> V_26 |= 0x04 ;
F_9 ( V_2 , V_27 , V_2 -> V_26 ) ;
}
}
static void
F_18 ( struct V_1 * V_2 , T_1 V_28 )
{
F_19 ( L_2 , V_2 -> V_19 , V_28 ) ;
F_9 ( V_2 , V_29 , V_28 ) ;
}
static void
F_20 ( struct V_1 * V_2 )
{
if ( V_2 -> V_30 == V_31 )
F_18 ( V_2 , V_32 ) ;
F_21 ( & V_2 -> V_3 , V_33 ) ;
}
static void
F_22 ( struct V_34 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_35 ;
switch ( V_2 -> V_30 ) {
case V_31 :
V_3 -> V_30 = 0 ;
F_23 ( V_3 -> V_36 , V_37 ) ;
break;
case V_38 :
V_3 -> V_30 = 3 ;
F_23 ( V_3 -> V_36 , V_39 ) ;
break;
case V_40 :
V_3 -> V_30 = 3 ;
F_23 ( V_3 -> V_36 , V_41 ) ;
break;
case V_42 :
V_3 -> V_30 = 4 ;
F_23 ( V_3 -> V_36 , V_43 ) ;
break;
case V_44 :
if ( V_3 -> V_30 <= 5 ) {
V_3 -> V_30 = 5 ;
F_23 ( V_3 -> V_36 , V_45 ) ;
} else {
V_3 -> V_30 = 8 ;
F_23 ( V_3 -> V_36 , V_46 ) ;
}
break;
case V_47 :
V_3 -> V_30 = 6 ;
F_23 ( V_3 -> V_36 , V_48 ) ;
break;
case V_49 :
V_3 -> V_30 = 7 ;
F_23 ( V_3 -> V_36 , V_50 ) ;
break;
case V_51 :
V_3 -> V_30 = 7 ;
F_23 ( V_3 -> V_36 , V_52 ) ;
break;
default:
F_19 ( L_3 ,
V_2 -> V_19 , V_2 -> V_30 , V_3 -> V_30 ) ;
break;
}
F_19 ( L_4 , V_2 -> V_19 , V_3 -> V_30 ) ;
}
static void
F_24 ( struct V_1 * V_2 , int V_53 )
{
struct V_34 * V_3 = & V_2 -> V_3 ;
T_1 * V_54 ;
F_19 ( L_5 , V_2 -> V_19 , V_53 ) ;
if ( ! V_3 -> V_55 ) {
V_3 -> V_55 = F_25 ( V_2 -> V_3 . V_56 , V_57 ) ;
if ( ! V_3 -> V_55 ) {
F_26 ( L_6 , V_2 -> V_19 ) ;
F_9 ( V_2 , V_58 , V_59 ) ;
return;
}
}
if ( ( V_3 -> V_55 -> V_60 + V_53 ) >= V_3 -> V_56 ) {
F_19 ( L_7 , V_2 -> V_19 ,
V_3 -> V_55 -> V_60 + V_53 ) ;
F_9 ( V_2 , V_58 , V_59 ) ;
return;
}
V_54 = F_27 ( V_3 -> V_55 , V_53 ) ;
F_28 ( V_2 -> V_13 + V_61 , V_54 , V_53 ) ;
F_9 ( V_2 , V_58 , V_59 ) ;
if ( V_4 & V_62 ) {
snprintf ( V_2 -> log , 63 , L_8 ,
V_2 -> V_19 , V_53 ) ;
F_29 ( V_2 -> log , V_63 , V_54 , V_53 ) ;
}
}
static void
F_30 ( struct V_1 * V_2 )
{
struct V_34 * V_3 = & V_2 -> V_3 ;
int V_53 ;
T_1 * V_54 ;
T_1 V_28 = V_64 ;
F_19 ( L_9 , V_2 -> V_19 ) ;
if ( ! V_3 -> V_65 )
return;
V_53 = V_3 -> V_65 -> V_60 - V_3 -> V_66 ;
if ( V_53 <= 0 )
return;
if ( V_53 > V_67 )
V_53 = V_67 ;
else
V_28 |= V_68 ;
V_54 = V_3 -> V_65 -> V_69 + V_3 -> V_66 ;
V_3 -> V_66 += V_53 ;
F_31 ( V_2 -> V_13 + V_70 , V_54 , V_53 ) ;
F_9 ( V_2 , V_58 , V_28 ) ;
if ( F_32 ( V_71 , & V_3 -> V_72 ) ) {
F_19 ( L_10 , V_2 -> V_19 ) ;
F_33 ( & V_3 -> V_73 ) ;
}
F_34 ( & V_3 -> V_73 ) ;
V_3 -> V_73 . V_74 = V_75 + ( ( V_76 * V_77 ) / 1000 ) ;
F_35 ( & V_3 -> V_73 ) ;
if ( V_4 & V_62 ) {
snprintf ( V_2 -> log , 63 , L_11 ,
V_2 -> V_19 , V_53 ) ;
F_29 ( V_2 -> log , V_63 , V_54 , V_53 ) ;
}
}
static void
F_36 ( struct V_1 * V_2 )
{
struct V_34 * V_3 = & V_2 -> V_3 ;
if ( F_37 ( V_71 , & V_3 -> V_72 ) )
F_33 ( & V_3 -> V_73 ) ;
#ifdef F_38
if ( F_37 ( V_78 , & V_3 -> V_72 ) )
F_39 ( V_3 , V_79 ) ;
#endif
if ( F_40 ( V_80 , & V_3 -> V_72 ) ) {
V_3 -> V_66 = 0 ;
F_30 ( V_2 ) ;
} else if ( V_3 -> V_65 ) {
F_26 ( L_12 , V_2 -> V_19 , V_81 ) ;
F_32 ( V_80 , & V_3 -> V_72 ) ;
V_3 -> V_66 = 0 ;
F_30 ( V_2 ) ;
} else {
F_26 ( L_13 , V_2 -> V_19 ) ;
if ( F_41 ( V_3 ) )
F_30 ( V_2 ) ;
}
}
static void
F_42 ( struct V_1 * V_2 ) {
T_1 V_82 ;
int V_53 ;
V_82 = F_7 ( V_2 , V_83 ) ;
if ( V_82 & ( V_84 | V_85 | V_86 ) ) {
if ( V_82 & V_84 ) {
F_19 ( L_14 , V_2 -> V_19 ) ;
#ifdef F_43
V_2 -> V_3 . V_87 ++ ;
#endif
}
if ( V_82 & V_85 ) {
F_19 ( L_15 , V_2 -> V_19 ) ;
#ifdef F_43
V_2 -> V_3 . V_88 ++ ;
#endif
}
if ( V_82 & V_86 ) {
F_19 ( L_16 , V_2 -> V_19 ) ;
#ifdef F_43
V_2 -> V_3 . V_87 ++ ;
#endif
}
if ( V_2 -> V_3 . V_55 )
F_44 ( V_2 -> V_3 . V_55 ) ;
V_2 -> V_3 . V_55 = NULL ;
F_9 ( V_2 , V_58 , V_59 | V_89 ) ;
} else {
V_53 = F_7 ( V_2 , V_90 ) & ( V_67 - 1 ) ;
if ( V_53 == 0 )
V_53 = V_67 ;
F_24 ( V_2 , V_53 ) ;
F_45 ( & V_2 -> V_3 ) ;
}
}
static void
F_46 ( struct V_1 * V_2 ) {
if ( F_37 ( V_71 , & V_2 -> V_3 . V_72 ) )
F_33 ( & V_2 -> V_3 . V_73 ) ;
if ( V_2 -> V_3 . V_65 && V_2 -> V_3 . V_66 < V_2 -> V_3 . V_65 -> V_60 ) {
F_30 ( V_2 ) ;
} else {
if ( V_2 -> V_3 . V_65 )
F_44 ( V_2 -> V_3 . V_65 ) ;
if ( F_41 ( & V_2 -> V_3 ) )
F_30 ( V_2 ) ;
}
}
static void
F_47 ( struct V_1 * V_2 )
{
struct V_34 * V_3 = & V_2 -> V_3 ;
T_1 V_91 , V_92 , V_93 ;
V_91 = F_7 ( V_2 , V_94 ) ;
F_19 ( L_17 , V_2 -> V_19 , V_91 ) ;
if ( V_91 & ( V_95 | V_96 ) ) {
F_19 ( L_18 , V_2 -> V_19 ) ;
#ifdef F_43
V_3 -> V_97 ++ ;
#endif
F_36 ( V_2 ) ;
}
if ( V_91 & V_98 ) {
F_19 ( L_14 , V_2 -> V_19 ) ;
F_9 ( V_2 , V_58 , V_89 ) ;
}
if ( V_91 & V_99 )
F_19 ( L_19 , V_2 -> V_19 ) ;
if ( V_91 & V_100 ) {
V_92 = F_7 ( V_2 , V_101 ) ;
F_19 ( L_20 ,
V_2 -> V_19 , V_92 ) ;
}
if ( V_91 & V_102 ) {
V_93 = F_7 ( V_2 , V_103 ) ;
F_19 ( L_21 , V_2 -> V_19 , V_93 ) ;
if ( V_93 & V_104 ) {
V_92 = V_93 & V_105 ;
F_19 ( L_22 , V_2 -> V_19 ,
V_3 -> V_30 , V_92 ) ;
V_2 -> V_30 = V_92 ;
if ( V_2 -> V_22 & V_23 ) {
switch ( V_92 ) {
case V_49 :
case V_51 :
F_17 ( V_2 , 1 ) ;
break;
default:
F_17 ( V_2 , 0 ) ;
break;
}
}
F_20 ( V_2 ) ;
}
if ( V_93 & V_106 ) {
V_92 = F_7 ( V_2 , V_107 ) ;
F_19 ( L_23 , V_2 -> V_19 , V_92 ) ;
}
}
if ( V_91 & V_108 )
F_19 ( L_24 , V_2 -> V_19 ) ;
if ( V_91 & V_109 )
F_19 ( L_25 , V_2 -> V_19 ) ;
}
static void
F_48 ( struct V_15 * V_110 , int V_53 )
{
struct V_1 * V_2 = V_110 -> V_6 . V_35 ;
T_1 * V_54 ;
F_19 ( L_26 , V_2 -> V_19 , V_53 ) ;
if ( F_49 ( V_110 -> V_6 . V_30 == V_111 ) ) {
F_19 ( L_27 , V_2 -> V_19 ) ;
F_12 ( V_110 , V_112 , V_113 | V_114 ) ;
if ( V_110 -> V_6 . V_55 )
F_50 ( V_110 -> V_6 . V_55 , 0 ) ;
return;
}
if ( ! V_110 -> V_6 . V_55 ) {
V_110 -> V_6 . V_55 = F_25 ( V_110 -> V_6 . V_56 , V_57 ) ;
if ( F_49 ( ! V_110 -> V_6 . V_55 ) ) {
F_26 ( L_28 , V_2 -> V_19 ) ;
F_12 ( V_110 , V_112 , V_113 |
V_114 ) ;
return;
}
}
if ( V_110 -> V_6 . V_55 -> V_60 + V_53 > V_110 -> V_6 . V_56 ) {
F_19 ( L_29 ,
V_2 -> V_19 ) ;
F_12 ( V_110 , V_112 , V_113 | V_114 ) ;
F_50 ( V_110 -> V_6 . V_55 , 0 ) ;
return;
}
V_54 = F_27 ( V_110 -> V_6 . V_55 , V_53 ) ;
F_28 ( V_110 -> V_13 + V_115 , V_54 , V_53 ) ;
F_12 ( V_110 , V_112 , V_113 | V_114 ) ;
if ( V_4 & V_62 ) {
snprintf ( V_2 -> log , 63 , L_30 ,
V_110 -> V_6 . V_116 , V_2 -> V_19 , V_53 ) ;
F_29 ( V_2 -> log , V_63 , V_54 , V_53 ) ;
}
}
static void
F_51 ( struct V_15 * V_110 )
{
struct V_1 * V_2 = V_110 -> V_6 . V_35 ;
int V_53 ;
T_1 * V_54 , V_28 = V_114 | V_117 ;
F_19 ( L_31 , V_2 -> V_19 ) ;
if ( ! V_110 -> V_6 . V_65 )
return;
V_53 = V_110 -> V_6 . V_65 -> V_60 - V_110 -> V_6 . V_66 ;
if ( V_53 <= 0 )
return;
V_54 = V_110 -> V_6 . V_65 -> V_69 + V_110 -> V_6 . V_66 ;
if ( V_53 > V_118 )
V_53 = V_118 ;
else if ( F_40 ( V_119 , & V_110 -> V_6 . V_72 ) )
V_28 |= V_120 ;
F_19 ( L_32 , V_2 -> V_19 ,
V_53 , V_110 -> V_6 . V_66 ) ;
V_110 -> V_6 . V_66 += V_53 ;
F_31 ( V_110 -> V_13 + V_121 , V_54 , V_53 ) ;
F_12 ( V_110 , V_112 , V_28 ) ;
if ( V_4 & V_62 ) {
snprintf ( V_2 -> log , 63 , L_33 ,
V_110 -> V_6 . V_116 , V_2 -> V_19 , V_53 ) ;
F_29 ( V_2 -> log , V_63 , V_54 , V_53 ) ;
}
}
static int
F_52 ( struct V_15 * V_110 )
{
struct V_1 * V_2 = V_110 -> V_6 . V_35 ;
if ( ! ( V_2 -> V_22 & V_122 ) )
return - V_123 ;
V_110 -> V_124 &= ~ ( V_125 | V_126 ) ;
F_12 ( V_110 , V_127 , V_110 -> V_124 ) ;
F_12 ( V_110 , V_112 , V_128 | V_114 |
V_129 ) ;
return 0 ;
}
static int
F_53 ( struct V_15 * V_110 , T_2 V_130 )
{
struct V_1 * V_2 ;
V_2 = V_110 -> V_6 . V_35 ;
F_19 ( L_34 , V_2 -> V_19 ,
V_110 -> V_6 . V_116 , V_110 -> V_6 . V_30 , V_130 ) ;
switch ( V_130 ) {
case V_111 :
if ( ( V_2 -> V_22 & V_122 ) && ( V_110 -> V_124 & V_125 ) )
F_52 ( V_110 ) ;
V_110 -> V_124 = 0 ;
F_54 ( & V_110 -> V_6 ) ;
F_12 ( V_110 , V_127 , V_110 -> V_124 ) ;
F_12 ( V_110 , V_112 , V_128 | V_129 ) ;
F_37 ( V_119 , & V_110 -> V_6 . V_72 ) ;
F_37 ( V_131 , & V_110 -> V_6 . V_72 ) ;
break;
case V_132 :
V_110 -> V_124 = V_133 ;
F_12 ( V_110 , V_127 , V_110 -> V_124 ) ;
F_12 ( V_110 , V_134 , 0 ) ;
F_12 ( V_110 , V_112 , V_128 | V_114 |
V_129 ) ;
F_32 ( V_131 , & V_110 -> V_6 . V_72 ) ;
break;
case V_135 :
V_110 -> V_124 = V_136 ;
F_12 ( V_110 , V_127 , V_110 -> V_124 ) ;
F_12 ( V_110 , V_137 , 0xff ) ;
F_12 ( V_110 , V_138 , 0xff ) ;
F_12 ( V_110 , V_134 , 0 ) ;
F_12 ( V_110 , V_112 , V_128 | V_114 |
V_129 ) ;
F_32 ( V_119 , & V_110 -> V_6 . V_72 ) ;
break;
default:
F_26 ( L_35 , V_2 -> V_19 , V_130 ) ;
return - V_139 ;
}
V_110 -> V_6 . V_30 = V_130 ;
return 0 ;
}
static void
F_55 ( struct V_15 * V_110 )
{
if ( V_110 -> V_6 . V_65 && V_110 -> V_6 . V_66 < V_110 -> V_6 . V_65 -> V_60 )
F_51 ( V_110 ) ;
else {
if ( V_110 -> V_6 . V_65 ) {
if ( F_40 ( V_131 , & V_110 -> V_6 . V_72 ) )
F_56 ( & V_110 -> V_6 ) ;
F_44 ( V_110 -> V_6 . V_65 ) ;
}
if ( F_57 ( & V_110 -> V_6 ) )
F_51 ( V_110 ) ;
}
}
static void
F_58 ( struct V_1 * V_2 , int V_140 )
{
struct V_15 * V_110 = & V_2 -> V_5 [ V_140 ] ;
int V_53 ;
T_1 V_82 , V_141 = 0 ;
V_82 = F_11 ( V_110 , V_142 ) ;
F_19 ( L_36 , V_2 -> V_19 , V_110 -> V_6 . V_116 , V_82 ) ;
if ( V_82 & V_143 ) {
V_141 = F_11 ( V_110 , V_144 ) ;
if ( V_141 & ( V_145 | V_146 | V_147 ) ) {
if ( ( V_141 & V_145 ) &&
F_40 ( V_148 , & V_110 -> V_6 . V_72 ) ) {
F_19 ( L_37 , V_2 -> V_19 ,
V_110 -> V_6 . V_116 , V_110 -> V_6 . V_30 ) ;
#ifdef F_43
V_110 -> V_6 . V_149 ++ ;
#endif
}
if ( F_40 ( V_119 , & V_110 -> V_6 . V_72 ) ) {
if ( V_141 & V_146 ) {
F_19 ( L_38 ,
V_2 -> V_19 , V_110 -> V_6 . V_116 ) ;
#ifdef F_43
V_110 -> V_6 . V_88 ++ ;
#endif
}
if ( V_141 & V_147 ) {
F_19 ( L_39 ,
V_2 -> V_19 , V_110 -> V_6 . V_116 ) ;
#ifdef F_43
V_110 -> V_6 . V_150 ++ ;
#endif
}
}
F_12 ( V_110 , V_112 , V_113 |
V_128 | V_114 ) ;
if ( V_110 -> V_6 . V_55 )
F_50 ( V_110 -> V_6 . V_55 , 0 ) ;
} else {
V_53 = F_11 ( V_110 , V_151 ) &
( V_118 - 1 ) ;
if ( V_53 == 0 )
V_53 = V_118 ;
F_48 ( V_110 , V_53 ) ;
F_59 ( & V_110 -> V_6 , 0 ) ;
}
}
if ( V_82 & V_152 ) {
if ( ! ( V_82 & V_143 ) )
V_141 = F_11 ( V_110 , V_144 ) ;
if ( V_141 & V_145 ) {
F_19 ( L_37 , V_2 -> V_19 ,
V_110 -> V_6 . V_116 , V_110 -> V_6 . V_30 ) ;
#ifdef F_43
V_110 -> V_6 . V_149 ++ ;
#endif
F_12 ( V_110 , V_112 , V_113 |
V_128 | V_114 ) ;
} else {
F_48 ( V_110 , V_118 ) ;
if ( F_40 ( V_131 , & V_110 -> V_6 . V_72 ) &&
V_110 -> V_6 . V_55 && ( V_110 -> V_6 . V_55 -> V_60 > 0 ) )
F_59 ( & V_110 -> V_6 , 0 ) ;
}
}
if ( V_82 & V_153 ) {
if ( ! ( V_141 & V_145 ) ) {
F_19 ( L_40 , V_2 -> V_19 ,
V_110 -> V_6 . V_116 , V_110 -> V_6 . V_30 ) ;
#ifdef F_43
V_110 -> V_6 . V_149 ++ ;
#endif
F_12 ( V_110 , V_112 , V_113 |
V_128 | V_114 ) ;
}
}
if ( V_82 & V_154 ) {
if ( ! ( V_82 & ( V_143 | V_152 ) ) ) {
V_141 = F_11 ( V_110 , V_144 ) ;
F_19 ( L_41 , V_2 -> V_19 ,
V_110 -> V_6 . V_116 , V_141 ) ;
}
if ( V_141 & V_155 ) {
F_19 ( L_42 , V_2 -> V_19 ,
V_110 -> V_6 . V_116 , V_110 -> V_6 . V_30 ) ;
#ifdef F_43
V_110 -> V_6 . V_156 ++ ;
#endif
F_12 ( V_110 , V_112 , V_129 |
V_114 ) ;
if ( V_110 -> V_6 . V_65 ) {
if ( ! F_40 ( V_131 , & V_110 -> V_6 . V_72 ) )
V_110 -> V_6 . V_66 = 0 ;
}
}
F_55 ( V_110 ) ;
if ( V_82 & V_157 )
return;
}
if ( V_82 & V_157 ) {
F_19 ( L_43 , V_2 -> V_19 ,
V_110 -> V_6 . V_116 , V_110 -> V_6 . V_30 ) ;
#ifdef F_43
V_110 -> V_6 . V_156 ++ ;
#endif
F_12 ( V_110 , V_112 , V_129 | V_114 ) ;
if ( V_110 -> V_6 . V_65 ) {
if ( ! F_40 ( V_131 , & V_110 -> V_6 . V_72 ) )
V_110 -> V_6 . V_66 = 0 ;
}
F_55 ( V_110 ) ;
}
}
static T_3
F_60 ( int V_158 , void * V_159 )
{
struct V_1 * V_2 = V_159 ;
T_1 V_160 ;
F_61 ( & V_2 -> V_161 ) ;
V_160 = F_7 ( V_2 , V_162 ) ;
if ( ( V_160 | V_2 -> V_17 ) == V_2 -> V_17 ) {
F_62 ( & V_2 -> V_161 ) ;
return V_163 ;
}
V_2 -> V_164 ++ ;
F_19 ( L_44 , V_2 -> V_19 , V_160 ) ;
V_160 &= ~ V_2 -> V_17 ;
if ( V_160 & V_165 )
F_58 ( V_2 , 0 ) ;
if ( V_160 & V_166 )
F_58 ( V_2 , 1 ) ;
if ( V_160 & V_167 )
F_42 ( V_2 ) ;
if ( V_160 & V_168 )
F_24 ( V_2 , V_67 ) ;
if ( V_160 & V_169 )
F_46 ( V_2 ) ;
if ( V_160 & V_170 )
F_47 ( V_2 ) ;
if ( V_160 & ( V_171 | V_172 ) )
F_19 ( L_45 , V_2 -> V_19 ) ;
F_62 ( & V_2 -> V_161 ) ;
return V_173 ;
}
static void
F_63 ( struct V_34 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_35 ;
int V_174 , V_141 ;
T_4 V_175 ;
if ( F_40 ( V_71 , & V_3 -> V_72 ) ) {
F_64 ( & V_2 -> V_161 , V_175 ) ;
V_174 = F_7 ( V_2 , V_18 ) ;
V_141 = F_7 ( V_2 , V_176 ) ;
F_19 ( L_46 ,
V_2 -> V_19 , V_174 , V_141 ) ;
if ( V_141 & V_177 )
F_32 ( V_78 , & V_3 -> V_72 ) ;
else {
F_37 ( V_71 , & V_3 -> V_72 ) ;
if ( V_3 -> V_66 )
V_3 -> V_66 = 0 ;
else
F_26 ( L_47 ,
V_2 -> V_19 ) ;
F_9 ( V_2 , V_58 , V_178 ) ;
}
F_65 ( & V_2 -> V_161 , V_175 ) ;
}
}
void F_66 ( struct V_1 * V_2 )
{
T_1 V_7 ;
V_2 -> V_3 . V_73 . V_179 = ( void * ) F_63 ;
V_2 -> V_3 . V_73 . V_69 = ( T_4 ) & V_2 -> V_3 ;
F_34 ( & V_2 -> V_3 . V_73 ) ;
F_53 ( & V_2 -> V_5 [ 0 ] , V_111 ) ;
F_53 ( & V_2 -> V_5 [ 1 ] , V_111 ) ;
F_9 ( V_2 , V_180 , 0x00 ) ;
F_14 ( V_2 ) ;
F_9 ( V_2 , V_181 , 0xff ) ;
F_9 ( V_2 , V_182 , 0xff ) ;
F_9 ( V_2 , V_183 , V_184 ) ;
V_2 -> V_30 = V_31 ;
F_18 ( V_2 , V_31 ) ;
F_18 ( V_2 , V_185 ) ;
V_2 -> V_17 = 0x18 ;
F_9 ( V_2 , V_186 , 0x00 ) ;
F_12 ( & V_2 -> V_5 [ 0 ] , V_134 , 0 ) ;
F_12 ( & V_2 -> V_5 [ 1 ] , V_134 , 0 ) ;
F_9 ( V_2 , V_58 , V_89 | V_178 ) ;
F_12 ( & V_2 -> V_5 [ 0 ] , V_112 , V_128 | V_129 ) ;
F_12 ( & V_2 -> V_5 [ 1 ] , V_112 , V_128 | V_129 ) ;
if ( V_2 -> V_24 == V_25 ) {
V_2 -> V_187 = 0x80 ;
V_2 -> V_26 = 0 ;
F_9 ( V_2 , V_188 , V_2 -> V_187 ) ;
F_9 ( V_2 , V_27 , V_2 -> V_26 ) ;
} else {
V_2 -> V_187 = V_189 | V_190 | V_191 |
V_192 | V_193 ;
V_2 -> V_194 = 0x00 ;
if ( V_2 -> V_22 & V_122 )
V_2 -> V_26 |= 0x06 ;
if ( V_2 -> V_22 & V_23 )
V_2 -> V_26 |= 0x04 ;
if ( ( V_2 -> V_22 & V_122 ) || ( V_2 -> V_22 & V_23 ) ) {
F_9 ( V_2 , V_188 , V_2 -> V_187 ) ;
F_9 ( V_2 , V_195 , V_2 -> V_194 ) ;
F_9 ( V_2 , V_27 , V_2 -> V_26 ) ;
V_7 = F_7 ( V_2 , V_195 ) ;
if ( V_4 & V_196 )
F_16 ( L_48 ,
V_2 -> V_19 , V_7 ) ;
}
}
}
static void
F_67 ( struct V_1 * V_2 )
{
F_9 ( V_2 , V_180 , V_197 ) ;
F_68 ( 10 ) ;
F_9 ( V_2 , V_180 , 0 ) ;
}
static int
F_69 ( struct V_1 * V_2 )
{
int V_198 = 3 ;
T_4 V_175 ;
F_64 ( & V_2 -> V_161 , V_175 ) ;
F_14 ( V_2 ) ;
F_65 ( & V_2 -> V_161 , V_175 ) ;
if ( F_70 ( V_2 -> V_199 , F_60 , V_200 , V_2 -> V_19 , V_2 ) ) {
F_26 ( L_49 , V_2 -> V_19 ,
V_2 -> V_199 ) ;
return - V_201 ;
}
while ( V_198 -- ) {
F_64 ( & V_2 -> V_161 , V_175 ) ;
F_66 ( V_2 ) ;
F_13 ( V_2 ) ;
F_65 ( & V_2 -> V_161 , V_175 ) ;
F_71 ( 10 ) ;
if ( V_4 & V_196 )
F_16 ( L_50 , V_2 -> V_19 ,
V_2 -> V_199 , V_2 -> V_164 ) ;
if ( ! V_2 -> V_164 ) {
F_26 ( L_51 ,
V_2 -> V_19 , V_2 -> V_199 , 3 - V_198 ) ;
F_67 ( V_2 ) ;
} else
return 0 ;
}
F_72 ( V_2 -> V_199 , V_2 ) ;
return - V_201 ;
}
static int
F_73 ( struct V_202 * V_140 , struct V_203 * V_204 )
{
struct V_205 * V_6 = F_74 ( V_140 , struct V_205 , V_140 ) ;
struct V_15 * V_5 = F_74 ( V_6 , struct V_15 , V_6 ) ;
struct V_1 * V_2 = V_6 -> V_35 ;
int V_10 = - V_206 ;
struct V_207 * V_208 = F_75 ( V_204 ) ;
T_2 V_209 ;
T_4 V_175 ;
switch ( V_208 -> V_210 ) {
case V_211 :
F_64 ( & V_2 -> V_161 , V_175 ) ;
V_10 = F_76 ( V_6 , V_204 ) ;
if ( V_10 > 0 ) {
V_209 = V_208 -> V_209 ;
V_10 = 0 ;
F_51 ( V_5 ) ;
F_65 ( & V_2 -> V_161 , V_175 ) ;
if ( ! F_40 ( V_131 , & V_6 -> V_72 ) )
F_77 ( V_140 , V_212 , V_209 , NULL ) ;
} else
F_65 ( & V_2 -> V_161 , V_175 ) ;
return V_10 ;
case V_213 :
F_64 ( & V_2 -> V_161 , V_175 ) ;
if ( ! F_32 ( V_148 , & V_6 -> V_72 ) )
V_10 = F_53 ( V_5 , V_140 -> V_214 ) ;
else
V_10 = 0 ;
F_65 ( & V_2 -> V_161 , V_175 ) ;
if ( ! V_10 )
F_78 ( V_140 , V_215 , V_216 , 0 ,
NULL , V_217 ) ;
break;
case V_218 :
F_64 ( & V_2 -> V_161 , V_175 ) ;
F_54 ( V_6 ) ;
F_53 ( V_5 , V_111 ) ;
F_65 ( & V_2 -> V_161 , V_175 ) ;
F_78 ( V_140 , V_219 , V_216 , 0 ,
NULL , V_217 ) ;
V_10 = 0 ;
break;
default:
F_26 ( L_52 ,
V_2 -> V_19 , V_81 , V_208 -> V_210 , V_208 -> V_209 ) ;
V_10 = - V_206 ;
}
if ( ! V_10 )
F_44 ( V_204 ) ;
return V_10 ;
}
static int
F_79 ( struct V_205 * V_6 , struct V_220 * V_221 )
{
int V_10 = 0 ;
switch ( V_221 -> V_222 ) {
case V_223 :
V_221 -> V_222 = 0 ;
break;
case V_224 :
default:
F_26 ( L_53 , V_81 , V_221 -> V_222 ) ;
V_10 = - V_206 ;
break;
}
return V_10 ;
}
static int
F_80 ( struct V_1 * V_2 , struct V_225 * V_226 )
{
struct V_205 * V_6 ;
if ( V_226 -> V_227 . V_228 == 0 || V_226 -> V_227 . V_228 > 2 )
return - V_206 ;
if ( V_226 -> V_214 == V_111 )
return - V_206 ;
V_6 = & V_2 -> V_5 [ V_226 -> V_227 . V_228 - 1 ] . V_6 ;
if ( F_32 ( V_229 , & V_6 -> V_72 ) )
return - V_230 ;
F_37 ( V_231 , & V_6 -> V_72 ) ;
V_6 -> V_140 . V_214 = V_226 -> V_214 ;
V_226 -> V_140 = & V_6 -> V_140 ;
return 0 ;
}
static int
F_81 ( struct V_1 * V_2 , struct V_220 * V_221 )
{
int V_10 = 0 ;
switch ( V_221 -> V_222 ) {
case V_223 :
V_221 -> V_222 = 0 ;
break;
default:
F_26 ( L_54 , V_2 -> V_19 , V_221 -> V_222 ) ;
V_10 = - V_206 ;
break;
}
return V_10 ;
}
static int
F_82 ( struct V_202 * V_140 , T_2 V_28 , void * V_232 )
{
struct V_205 * V_6 = F_74 ( V_140 , struct V_205 , V_140 ) ;
struct V_15 * V_5 = F_74 ( V_6 , struct V_15 , V_6 ) ;
struct V_1 * V_2 = V_6 -> V_35 ;
int V_10 = - V_206 ;
T_4 V_175 ;
F_19 ( L_55 , V_2 -> V_19 , V_81 , V_28 , V_232 ) ;
switch ( V_28 ) {
case V_233 :
F_37 ( V_229 , & V_6 -> V_72 ) ;
if ( F_40 ( V_148 , & V_6 -> V_72 ) ) {
F_64 ( & V_2 -> V_161 , V_175 ) ;
F_83 ( V_6 ) ;
F_53 ( V_5 , V_111 ) ;
F_65 ( & V_2 -> V_161 , V_175 ) ;
} else {
F_84 ( & V_6 -> V_234 ) ;
V_6 -> V_235 = 0 ;
}
V_140 -> V_214 = V_111 ;
V_140 -> V_236 = NULL ;
F_85 ( V_237 ) ;
V_10 = 0 ;
break;
case V_238 :
V_10 = F_79 ( V_6 , V_232 ) ;
break;
default:
F_26 ( L_56 ,
V_2 -> V_19 , V_81 , V_28 ) ;
}
return V_10 ;
}
static int
F_86 ( struct V_202 * V_140 , struct V_203 * V_204 )
{
struct V_239 * V_240 = F_74 ( V_140 , struct V_239 , V_241 ) ;
struct V_34 * V_3 = F_74 ( V_240 , struct V_34 , V_240 ) ;
struct V_1 * V_2 = F_74 ( V_3 , struct V_1 , V_3 ) ;
int V_10 = - V_206 ;
struct V_207 * V_208 = F_75 ( V_204 ) ;
T_2 V_209 ;
T_4 V_175 ;
switch ( V_208 -> V_210 ) {
case V_211 :
F_64 ( & V_2 -> V_161 , V_175 ) ;
V_10 = F_87 ( V_3 , V_204 ) ;
if ( V_10 > 0 ) {
V_209 = V_208 -> V_209 ;
F_30 ( V_2 ) ;
V_10 = 0 ;
F_65 ( & V_2 -> V_161 , V_175 ) ;
F_77 ( V_140 , V_212 , V_209 , NULL ) ;
} else
F_65 ( & V_2 -> V_161 , V_175 ) ;
return V_10 ;
case V_213 :
V_10 = F_23 ( V_3 -> V_36 , V_208 -> V_210 ) ;
break;
case V_218 :
F_37 ( V_242 , & V_3 -> V_72 ) ;
V_10 = F_23 ( V_3 -> V_36 , V_208 -> V_210 ) ;
break;
}
if ( ! V_10 )
F_44 ( V_204 ) ;
return V_10 ;
}
static int
F_88 ( struct V_34 * V_3 , T_2 V_28 )
{
struct V_1 * V_2 = F_74 ( V_3 , struct V_1 , V_3 ) ;
T_4 V_175 ;
F_19 ( L_57 , V_2 -> V_19 , V_28 , V_2 -> V_30 ) ;
switch ( V_28 ) {
case V_243 :
F_64 ( & V_2 -> V_161 , V_175 ) ;
F_18 ( V_2 , V_244 ) ;
F_65 ( & V_2 -> V_161 , V_175 ) ;
break;
case V_245 :
F_64 ( & V_2 -> V_161 , V_175 ) ;
F_18 ( V_2 , V_246 ) ;
F_65 ( & V_2 -> V_161 , V_175 ) ;
break;
case V_247 :
F_64 ( & V_2 -> V_161 , V_175 ) ;
if ( V_2 -> V_30 != V_40 )
F_18 ( V_2 , V_31 ) ;
F_18 ( V_2 , V_185 ) ;
F_65 ( & V_2 -> V_161 , V_175 ) ;
break;
case V_248 :
F_84 ( & V_3 -> V_249 ) ;
if ( V_3 -> V_65 ) {
F_44 ( V_3 -> V_65 ) ;
V_3 -> V_65 = NULL ;
}
V_3 -> V_66 = 0 ;
if ( V_3 -> V_55 ) {
F_44 ( V_3 -> V_55 ) ;
V_3 -> V_55 = NULL ;
}
F_37 ( V_80 , & V_3 -> V_72 ) ;
if ( F_37 ( V_71 , & V_3 -> V_72 ) )
F_33 ( & V_3 -> V_73 ) ;
break;
case V_250 :
F_64 ( & V_2 -> V_161 , V_175 ) ;
F_18 ( V_2 , V_185 ) ;
F_65 ( & V_2 -> V_161 , V_175 ) ;
break;
case V_215 :
F_32 ( V_148 , & V_3 -> V_72 ) ;
F_78 ( & V_3 -> V_240 . V_241 , V_28 , V_216 , 0 , NULL ,
V_57 ) ;
break;
case V_219 :
F_37 ( V_148 , & V_3 -> V_72 ) ;
F_78 ( & V_3 -> V_240 . V_241 , V_28 , V_216 , 0 , NULL ,
V_57 ) ;
break;
default:
F_19 ( L_58 , V_2 -> V_19 ,
V_81 , V_28 ) ;
return - 1 ;
}
return 0 ;
}
static int
F_89 ( struct V_1 * V_2 , struct V_225 * V_226 )
{
F_19 ( L_59 , V_2 -> V_19 , V_81 ,
V_2 -> V_3 . V_240 . V_209 , F_90 ( 1 ) ) ;
if ( V_226 -> V_214 != V_251 )
return - V_206 ;
if ( V_226 -> V_227 . V_228 == 1 )
return - V_206 ;
V_226 -> V_140 = & V_2 -> V_3 . V_240 . V_241 ;
V_226 -> V_140 -> V_214 = V_226 -> V_214 ;
if ( V_2 -> V_3 . V_30 == 7 )
F_78 ( V_226 -> V_140 , V_215 , V_216 ,
0 , NULL , V_217 ) ;
return 0 ;
}
static int
F_91 ( struct V_202 * V_140 , T_2 V_28 , void * V_232 )
{
struct V_239 * V_240 = F_74 ( V_140 , struct V_239 , V_241 ) ;
struct V_34 * V_3 = F_74 ( V_240 , struct V_34 , V_240 ) ;
struct V_1 * V_2 = F_74 ( V_3 , struct V_1 , V_3 ) ;
struct V_225 * V_226 ;
int V_252 = 0 ;
F_19 ( L_60 , V_2 -> V_19 , V_28 , V_232 ) ;
switch ( V_28 ) {
case V_253 :
V_226 = V_232 ;
if ( V_226 -> V_214 == V_251 )
V_252 = F_89 ( V_2 , V_226 ) ;
else
V_252 = F_80 ( V_2 , V_226 ) ;
if ( V_252 )
break;
if ( ! F_92 ( V_237 ) )
F_26 ( L_61 , V_2 -> V_19 ) ;
break;
case V_233 :
F_19 ( L_62 , V_2 -> V_19 ,
V_3 -> V_240 . V_209 , F_90 ( 0 ) ) ;
F_85 ( V_237 ) ;
break;
case V_238 :
V_252 = F_81 ( V_2 , V_232 ) ;
break;
default:
F_19 ( L_63 , V_2 -> V_19 , V_28 ) ;
return - V_206 ;
}
return V_252 ;
}
static int
F_93 ( struct V_1 * V_2 )
{
T_2 V_7 ;
if ( ! F_94 ( V_2 -> V_13 , 256 , V_2 -> V_19 ) ) {
F_26 ( L_64 , V_2 -> V_19 ,
V_2 -> V_13 , V_2 -> V_13 + 255 ) ;
return - V_201 ;
}
F_15 ( V_2 ) ;
V_2 -> V_5 [ 0 ] . V_13 = V_2 -> V_13 ;
V_2 -> V_5 [ 1 ] . V_13 = V_2 -> V_13 + 0x40 ;
V_7 = F_7 ( V_2 , V_162 ) ;
if ( V_4 & V_196 )
F_16 ( L_65 , V_2 -> V_19 , V_7 ) ;
V_7 = F_7 ( V_2 , V_16 ) ;
if ( V_4 & V_196 )
F_16 ( L_66 , V_2 -> V_19 , V_7 ) ;
V_7 = F_7 ( V_2 , V_94 ) ;
if ( V_4 & V_196 )
F_16 ( L_67 , V_2 -> V_19 , V_7 ) ;
V_7 = F_7 ( V_2 , V_186 ) ;
if ( V_4 & V_196 )
F_16 ( L_68 , V_2 -> V_19 , V_7 ) ;
V_7 = F_7 ( V_2 , V_83 ) ;
if ( V_4 & V_196 )
F_16 ( L_69 , V_2 -> V_19 , V_7 ) ;
return 0 ;
}
static void
F_95 ( struct V_1 * V_2 )
{
T_4 V_175 ;
F_64 ( & V_2 -> V_161 , V_175 ) ;
F_14 ( V_2 ) ;
F_53 ( & V_2 -> V_5 [ 0 ] , V_111 ) ;
F_53 ( & V_2 -> V_5 [ 1 ] , V_111 ) ;
if ( ( V_2 -> V_22 & V_23 ) || V_2 -> V_24 == V_25 ) {
V_2 -> V_26 |= 0x04 ;
F_9 ( V_2 , V_27 , V_2 -> V_26 ) ;
}
F_65 ( & V_2 -> V_161 , V_175 ) ;
F_72 ( V_2 -> V_199 , V_2 ) ;
F_23 ( V_2 -> V_3 . V_36 , V_233 ) ;
F_96 ( & V_2 -> V_3 . V_240 ) ;
F_97 ( V_2 -> V_13 , 256 ) ;
F_83 ( & V_2 -> V_5 [ 1 ] . V_6 ) ;
F_83 ( & V_2 -> V_5 [ 0 ] . V_6 ) ;
F_98 ( & V_2 -> V_3 ) ;
F_99 ( & V_11 , V_175 ) ;
F_100 ( & V_2 -> V_254 ) ;
F_101 ( & V_11 , V_175 ) ;
F_102 ( V_2 -> V_255 ) ;
F_103 ( V_2 -> V_255 , NULL ) ;
F_104 ( V_2 ) ;
}
static int
F_105 ( struct V_1 * V_2 )
{
int V_256 , V_252 ;
T_4 V_175 ;
snprintf ( V_2 -> V_19 , V_257 - 1 , L_70 , V_258 + 1 ) ;
F_99 ( & V_11 , V_175 ) ;
F_106 ( & V_2 -> V_254 , & V_259 ) ;
F_101 ( & V_11 , V_175 ) ;
V_2 -> V_22 = ( 1 << V_258 ) ;
F_1 ( V_2 ) ;
F_107 ( & V_2 -> V_161 ) ;
F_108 ( & V_2 -> V_3 , V_260 , F_22 ) ;
V_2 -> V_3 . V_240 . V_261 = ( 1 << V_251 ) ;
V_2 -> V_3 . V_240 . V_241 . V_262 = F_86 ;
V_2 -> V_3 . V_240 . V_241 . V_263 = F_91 ;
V_2 -> V_3 . V_240 . V_264 = ( 1 << ( V_132 & V_265 ) ) |
( 1 << ( V_135 & V_265 ) ) ;
V_2 -> V_3 . V_35 = V_2 ;
V_2 -> V_3 . V_240 . V_266 = 2 ;
for ( V_256 = 0 ; V_256 < 2 ; V_256 ++ ) {
F_109 ( & V_2 -> V_5 [ V_256 ] . V_6 , V_267 ) ;
V_2 -> V_5 [ V_256 ] . V_6 . V_35 = V_2 ;
V_2 -> V_5 [ V_256 ] . V_6 . V_116 = V_256 + 1 ;
V_2 -> V_5 [ V_256 ] . V_6 . V_140 . V_116 = V_256 + 1 ;
V_2 -> V_5 [ V_256 ] . V_6 . V_140 . V_262 = F_73 ;
V_2 -> V_5 [ V_256 ] . V_6 . V_140 . V_263 = F_82 ;
F_110 ( V_256 + 1 , V_2 -> V_3 . V_240 . V_268 ) ;
F_111 ( & V_2 -> V_5 [ V_256 ] . V_6 . V_140 . V_254 , & V_2 -> V_3 . V_240 . V_269 ) ;
}
V_252 = F_93 ( V_2 ) ;
if ( V_252 )
goto V_270;
V_252 = F_112 ( & V_2 -> V_3 . V_240 , & V_2 -> V_255 -> V_240 ,
V_2 -> V_19 ) ;
if ( V_252 )
goto V_271;
V_252 = F_69 ( V_2 ) ;
if ( V_252 )
goto V_272;
V_252 = F_113 ( & V_2 -> V_3 , F_88 ) ;
if ( ! V_252 ) {
V_258 ++ ;
F_16 ( L_71 , V_258 ) ;
return 0 ;
}
F_72 ( V_2 -> V_199 , V_2 ) ;
V_272:
F_96 ( & V_2 -> V_3 . V_240 ) ;
V_271:
F_97 ( V_2 -> V_13 , 256 ) ;
V_270:
F_83 ( & V_2 -> V_5 [ 1 ] . V_6 ) ;
F_83 ( & V_2 -> V_5 [ 0 ] . V_6 ) ;
F_98 ( & V_2 -> V_3 ) ;
F_99 ( & V_11 , V_175 ) ;
F_100 ( & V_2 -> V_254 ) ;
F_101 ( & V_11 , V_175 ) ;
F_104 ( V_2 ) ;
return V_252 ;
}
static int T_5
F_114 ( struct V_273 * V_255 , const struct V_274 * V_275 )
{
int V_252 = - V_276 ;
struct V_1 * V_2 ;
struct V_277 * V_278 = (struct V_277 * ) V_275 -> V_279 ;
V_2 = F_115 ( sizeof( struct V_1 ) , V_217 ) ;
if ( ! V_2 ) {
F_26 ( L_72 ) ;
return V_252 ;
}
V_2 -> V_255 = V_255 ;
V_2 -> V_24 = V_278 -> V_24 ;
V_252 = F_116 ( V_255 ) ;
if ( V_252 ) {
F_104 ( V_2 ) ;
return V_252 ;
}
F_117 ( V_280 L_73 ,
V_278 -> V_19 , F_118 ( V_255 ) ) ;
V_2 -> V_13 = F_119 ( V_255 , 1 ) ;
V_2 -> V_199 = V_255 -> V_199 ;
F_103 ( V_255 , V_2 ) ;
V_252 = F_105 ( V_2 ) ;
if ( V_252 )
F_103 ( V_255 , NULL ) ;
return V_252 ;
}
static void T_6
F_120 ( struct V_273 * V_255 )
{
struct V_1 * V_2 = F_121 ( V_255 ) ;
if ( V_2 )
F_95 ( V_2 ) ;
else
if ( V_4 )
F_16 ( L_74 , V_81 ) ;
}
static int T_7 F_122 ( void )
{
int V_252 ;
F_16 ( L_75 , V_281 ) ;
V_252 = F_123 ( & V_282 ) ;
return V_252 ;
}
static void T_8 F_124 ( void )
{
F_125 ( & V_282 ) ;
}
