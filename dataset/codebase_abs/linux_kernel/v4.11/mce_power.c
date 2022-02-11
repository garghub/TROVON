static void F_1 ( unsigned int V_1 , unsigned int V_2 )
{
unsigned long V_3 ;
unsigned int V_4 ;
switch ( V_2 ) {
case V_5 :
V_3 = V_6 ;
break;
case V_7 :
V_3 = V_8 ;
break;
default:
F_2 () ;
break;
}
asm volatile("ptesync" : : : "memory");
for ( V_4 = 0 ; V_4 < V_1 ; V_4 ++ ) {
asm volatile("tlbiel %0" : : "r" (rb));
V_3 += 1 << V_9 ;
}
asm volatile("ptesync" : : : "memory");
}
void F_3 ( unsigned int V_2 )
{
F_1 ( V_10 , V_2 ) ;
}
void F_4 ( unsigned int V_2 )
{
F_1 ( V_11 , V_2 ) ;
}
void F_5 ( unsigned int V_2 )
{
if ( F_6 () )
F_1 ( V_12 , V_2 ) ;
F_1 ( V_13 , V_2 ) ;
}
static void F_7 ( void )
{
struct V_14 * V_15 ;
unsigned long V_4 , V_16 ;
asm volatile("slbmte %0,%0; slbia" : : "r" (0));
#ifdef F_8
if ( F_9 () -> V_17 . V_18 )
return;
#endif
V_15 = F_10 () ;
if ( ! V_15 )
return;
V_16 = F_11 ( V_19 , F_12 ( V_15 -> V_20 ) , V_21 ) ;
for ( V_4 = 0 ; V_4 < V_16 ; V_4 ++ ) {
unsigned long V_3 = F_13 ( V_15 -> V_22 [ V_4 ] . V_23 ) ;
unsigned long V_24 = F_13 ( V_15 -> V_22 [ V_4 ] . V_25 ) ;
V_3 = ( V_3 & ~ 0xFFFul ) | V_4 ;
asm volatile("slbmte %0,%1" : : "r" (rs), "r" (rb));
}
}
static void F_14 ( void )
{
asm volatile(PPC_INVALIDATE_ERAT : : :"memory");
}
static int F_15 ( int V_26 )
{
#ifdef F_16
if ( V_26 == V_27 ) {
F_7 () ;
return 1 ;
}
#endif
if ( V_26 == V_28 ) {
F_14 () ;
return 1 ;
}
if ( V_26 == V_29 ) {
if ( V_30 && V_30 -> V_31 ) {
V_30 -> V_31 ( V_5 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_17 ( T_1 V_32 , T_1 V_15 , T_1 V_33 , T_1 V_34 )
{
if ( ( V_32 & V_15 ) && F_15 ( V_27 ) )
V_32 &= ~ V_15 ;
if ( ( V_32 & V_34 ) && F_15 ( V_28 ) )
V_32 &= ~ V_34 ;
if ( ( V_32 & V_33 ) && F_15 ( V_29 ) )
V_32 &= ~ V_33 ;
if ( V_32 )
return 0 ;
return 1 ;
}
static long F_18 ( T_1 V_32 , T_1 V_35 )
{
long V_36 = 1 ;
#ifdef F_16
if ( V_32 & V_35 ) {
F_7 () ;
V_32 &= ~ ( V_35 ) ;
}
if ( V_32 & V_37 ) {
if ( V_30 && V_30 -> V_31 )
V_30 -> V_31 ( V_5 ) ;
V_32 &= ~ V_37 ;
}
#endif
if ( V_32 & 0xffffffffUL )
V_36 = 0 ;
return V_36 ;
}
static long F_19 ( T_1 V_32 )
{
return F_18 ( V_32 , V_38 ) ;
}
static long F_20 ( T_1 V_39 )
{
long V_36 = 0 ;
switch ( F_21 ( V_39 ) ) {
case 0 :
break;
#ifdef F_16
case V_40 :
case V_41 :
F_7 () ;
V_36 = 1 ;
break;
case V_42 :
if ( V_30 && V_30 -> V_31 ) {
V_30 -> V_31 ( V_5 ) ;
V_36 = 1 ;
}
break;
#endif
default:
break;
}
return V_36 ;
}
static long F_22 ( T_1 V_39 )
{
long V_36 = 0 ;
V_36 = F_20 ( V_39 ) ;
#ifdef F_16
if ( F_21 ( V_39 ) == V_43 ) {
F_7 () ;
V_36 = 1 ;
}
#endif
return V_36 ;
}
static void F_23 ( struct V_44 * V_45 , T_1 V_39 )
{
switch ( F_21 ( V_39 ) ) {
case V_40 :
V_45 -> V_46 = V_47 ;
V_45 -> V_48 . V_49 = V_50 ;
break;
case V_41 :
V_45 -> V_46 = V_47 ;
V_45 -> V_48 . V_49 = V_51 ;
break;
case V_42 :
V_45 -> V_46 = V_52 ;
V_45 -> V_48 . V_53 = V_54 ;
break;
case V_55 :
case V_56 :
V_45 -> V_46 = V_57 ;
V_45 -> V_48 . V_58 = V_59 ;
break;
case V_60 :
V_45 -> V_46 = V_57 ;
V_45 -> V_48 . V_58 =
V_61 ;
break;
}
}
static void F_24 ( struct V_44 * V_45 , T_1 V_39 )
{
F_23 ( V_45 , V_39 ) ;
if ( F_21 ( V_39 ) == V_43 ) {
V_45 -> V_46 = V_47 ;
V_45 -> V_48 . V_49 = V_62 ;
}
}
static void F_25 ( struct V_44 * V_45 , T_1 V_32 )
{
if ( V_32 & V_63 ) {
V_45 -> V_46 = V_57 ;
V_45 -> V_48 . V_58 = V_64 ;
} else if ( V_32 & V_65 ) {
V_45 -> V_46 = V_57 ;
V_45 -> V_48 . V_58 =
V_66 ;
} else if ( V_32 & V_67 ) {
V_45 -> V_46 = V_68 ;
V_45 -> V_48 . V_69 = V_70 ;
} else if ( V_32 & V_71 ) {
V_45 -> V_46 = V_47 ;
V_45 -> V_48 . V_49 = V_51 ;
} else if ( V_32 & V_72 ) {
V_45 -> V_46 = V_47 ;
V_45 -> V_48 . V_49 = V_50 ;
} else if ( V_32 & V_37 ) {
V_45 -> V_46 = V_52 ;
V_45 -> V_48 . V_53 = V_54 ;
} else if ( V_32 & V_73 ) {
V_45 -> V_46 = V_47 ;
V_45 -> V_48 . V_49 = V_62 ;
}
}
static long F_26 ( struct V_74 * V_75 )
{
long V_36 = 0 ;
if ( V_76 . V_77 ) {
if ( V_76 . V_77 ( V_75 ) )
V_36 = 1 ;
}
return V_36 ;
}
long F_27 ( struct V_74 * V_75 )
{
T_1 V_39 , V_78 , V_79 ;
long V_36 = 1 ;
struct V_44 V_44 = { 0 } ;
V_44 . V_80 = V_81 ;
V_44 . V_82 = V_83 ;
V_39 = V_75 -> V_84 ;
V_78 = V_75 -> V_78 ;
if ( F_28 ( V_39 ) ) {
V_36 = F_19 ( V_75 -> V_32 ) ;
F_25 ( & V_44 , V_75 -> V_32 ) ;
V_79 = V_75 -> V_85 ;
} else {
V_36 = F_22 ( V_39 ) ;
F_24 ( & V_44 , V_39 ) ;
V_79 = V_75 -> V_78 ;
}
if ( V_44 . V_46 == V_57 )
V_36 = F_26 ( V_75 ) ;
F_29 ( V_75 , V_36 , & V_44 , V_78 , V_79 ) ;
return V_36 ;
}
static void F_30 ( struct V_44 * V_45 , T_1 V_39 )
{
F_23 ( V_45 , V_39 ) ;
if ( F_21 ( V_39 ) == V_86 ) {
V_45 -> V_46 = V_68 ;
V_45 -> V_48 . V_69 = V_70 ;
}
}
static void F_31 ( struct V_44 * V_45 , T_1 V_32 )
{
F_25 ( V_45 , V_32 ) ;
if ( V_32 & V_87 ) {
V_45 -> V_46 = V_68 ;
V_45 -> V_48 . V_69 = V_70 ;
}
}
static long F_32 ( T_1 V_39 )
{
long V_36 = 0 ;
V_36 = F_20 ( V_39 ) ;
#ifdef F_16
if ( F_21 ( V_39 ) == V_86 ) {
F_7 () ;
V_36 = 1 ;
}
#endif
return V_36 ;
}
static long F_33 ( T_1 V_32 )
{
return F_18 ( V_32 , V_88 ) ;
}
long F_34 ( struct V_74 * V_75 )
{
T_1 V_39 , V_78 , V_79 ;
long V_36 = 1 ;
struct V_44 V_44 = { 0 } ;
V_44 . V_80 = V_81 ;
V_44 . V_82 = V_83 ;
V_39 = V_75 -> V_84 ;
V_78 = V_75 -> V_78 ;
if ( F_28 ( V_39 ) ) {
V_36 = F_33 ( V_75 -> V_32 ) ;
F_31 ( & V_44 , V_75 -> V_32 ) ;
V_79 = V_75 -> V_85 ;
} else {
V_36 = F_32 ( V_39 ) ;
F_30 ( & V_44 , V_39 ) ;
V_79 = V_75 -> V_78 ;
}
if ( V_44 . V_46 == V_57 )
V_36 = F_26 ( V_75 ) ;
F_29 ( V_75 , V_36 , & V_44 , V_78 , V_79 ) ;
return V_36 ;
}
static int F_35 ( struct V_74 * V_75 )
{
T_1 V_32 = V_75 -> V_32 ;
return F_17 ( V_32 ,
V_89 |
V_90 ,
V_91 ,
V_92 ) ;
}
static int F_36 ( struct V_74 * V_75 )
{
T_1 V_39 = V_75 -> V_84 ;
switch ( F_37 ( V_39 ) ) {
case V_93 :
case V_94 :
return F_15 ( V_27 ) ;
case V_95 :
return F_15 ( V_29 ) ;
case V_96 :
return F_15 ( V_28 ) ;
default:
return 0 ;
}
}
static void F_38 ( struct V_74 * V_75 ,
struct V_44 * V_45 , T_1 * V_79 )
{
T_1 V_32 = V_75 -> V_32 ;
V_45 -> V_80 = V_81 ;
V_45 -> V_82 = V_83 ;
if ( V_32 & V_97 )
* V_79 = V_75 -> V_78 ;
else
* V_79 = V_75 -> V_85 ;
if ( V_32 & V_98 ) {
V_45 -> V_46 = V_57 ;
V_45 -> V_48 . V_58 = V_64 ;
} else if ( V_32 & V_99 ) {
V_45 -> V_46 = V_57 ;
V_45 -> V_48 . V_58 = V_66 ;
} else if ( V_32 & V_100 ) {
V_45 -> V_46 = V_101 ;
V_45 -> V_48 . V_102 = V_103 ;
} else if ( V_32 & V_104 ) {
V_45 -> V_46 = V_101 ;
V_45 -> V_48 . V_102 = V_105 ;
} else if ( V_32 & V_92 ) {
V_45 -> V_46 = V_68 ;
V_45 -> V_48 . V_69 = V_70 ;
} else if ( V_32 & V_91 ) {
V_45 -> V_46 = V_52 ;
V_45 -> V_48 . V_53 = V_54 ;
} else if ( V_32 & V_97 ) {
V_45 -> V_46 = V_106 ;
V_45 -> V_48 . V_107 = V_108 ;
} else if ( V_32 & V_89 ) {
V_45 -> V_46 = V_47 ;
V_45 -> V_48 . V_49 = V_50 ;
} else if ( V_32 & V_90 ) {
V_45 -> V_46 = V_47 ;
V_45 -> V_48 . V_49 = V_51 ;
} else if ( V_32 & V_109 ) {
V_45 -> V_46 = V_110 ;
V_45 -> V_48 . V_111 = V_112 ;
} else if ( V_32 & V_113 ) {
V_45 -> V_46 = V_110 ;
V_45 -> V_48 . V_111 = V_114 ;
} else if ( V_32 & V_115 ) {
V_45 -> V_46 = V_110 ;
V_45 -> V_48 . V_111 = V_116 ;
} else if ( V_32 & V_117 ) {
V_45 -> V_46 = V_110 ;
V_45 -> V_48 . V_111 = V_118 ;
}
}
static void F_39 ( struct V_74 * V_75 ,
struct V_44 * V_45 , T_1 * V_79 )
{
T_1 V_39 = V_75 -> V_84 ;
switch ( F_37 ( V_39 ) ) {
case V_119 :
case V_120 :
V_45 -> V_80 = V_121 ;
break;
default:
V_45 -> V_80 = V_81 ;
break;
}
V_45 -> V_82 = V_83 ;
* V_79 = V_75 -> V_78 ;
switch ( F_37 ( V_39 ) ) {
case V_122 :
V_45 -> V_46 = V_57 ;
V_45 -> V_48 . V_58 = V_59 ;
break;
case V_93 :
V_45 -> V_46 = V_47 ;
V_45 -> V_48 . V_49 = V_50 ;
break;
case V_94 :
V_45 -> V_46 = V_47 ;
V_45 -> V_48 . V_49 = V_51 ;
break;
case V_96 :
V_45 -> V_46 = V_68 ;
V_45 -> V_48 . V_69 = V_70 ;
break;
case V_95 :
V_45 -> V_46 = V_52 ;
V_45 -> V_48 . V_53 = V_54 ;
break;
case V_123 :
V_45 -> V_46 = V_57 ;
V_45 -> V_48 . V_58 = V_61 ;
break;
case V_124 :
V_45 -> V_46 = V_101 ;
V_45 -> V_48 . V_102 = V_125 ;
break;
case V_126 :
V_45 -> V_46 = V_101 ;
V_45 -> V_48 . V_102 = V_127 ;
break;
case V_128 :
V_45 -> V_46 = V_110 ;
V_45 -> V_48 . V_111 = V_129 ;
break;
case V_130 :
V_45 -> V_46 = V_110 ;
V_45 -> V_48 . V_111 = V_131 ;
break;
case V_119 :
V_45 -> V_46 = V_110 ;
V_45 -> V_48 . V_111 = V_132 ;
break;
case V_120 :
V_45 -> V_46 = V_101 ;
V_45 -> V_48 . V_102 = V_133 ;
break;
case V_134 :
V_45 -> V_46 = V_110 ;
V_45 -> V_48 . V_111 = V_135 ;
break;
default:
break;
}
}
long F_40 ( struct V_74 * V_75 )
{
T_1 V_78 , V_79 ;
long V_36 ;
struct V_44 V_44 = { 0 } ;
V_78 = V_75 -> V_78 ;
if ( F_41 ( V_75 -> V_84 ) ) {
V_36 = F_35 ( V_75 ) ;
F_38 ( V_75 , & V_44 , & V_79 ) ;
} else {
V_36 = F_36 ( V_75 ) ;
F_39 ( V_75 , & V_44 , & V_79 ) ;
}
if ( V_44 . V_46 == V_57 )
V_36 = F_26 ( V_75 ) ;
F_29 ( V_75 , V_36 , & V_44 , V_78 , V_79 ) ;
return V_36 ;
}
