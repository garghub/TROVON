static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static unsigned int F_3 ( struct V_2 * V_5 , int V_6 )
{
struct V_7 * V_8 = F_4 ( V_5 , V_6 ) ;
if ( V_8 -> V_9 == 8 )
return F_5 ( V_5 -> V_10 + ( V_8 -> V_6 << V_5 -> V_11 ) ) ;
else if ( V_8 -> V_9 == 16 )
return F_6 ( V_5 -> V_10 + ( V_8 -> V_6 << V_5 -> V_11 ) ) ;
else
F_7 ( 1 , L_1 ) ;
return 0 ;
}
static void F_8 ( struct V_2 * V_5 , int V_6 , int V_12 )
{
struct V_7 * V_8 = F_4 ( V_5 , V_6 ) ;
if ( V_8 -> V_9 == 8 )
F_9 ( V_12 , V_5 -> V_10 + ( V_8 -> V_6 << V_5 -> V_11 ) ) ;
else if ( V_8 -> V_9 == 16 )
F_10 ( V_12 , V_5 -> V_10 + ( V_8 -> V_6 << V_5 -> V_11 ) ) ;
else
F_7 ( 1 , L_1 ) ;
}
static int F_11 ( struct V_13 * V_14 )
{
switch ( V_14 -> type ) {
case V_15 :
V_14 -> V_16 = V_17 ;
break;
case V_18 :
V_14 -> V_16 = V_19 ;
break;
case V_20 :
V_14 -> V_16 = V_21 ;
break;
case V_22 :
V_14 -> V_16 = V_23 ;
break;
case V_24 :
V_14 -> V_16 = V_25 ;
break;
default:
F_12 ( V_26 L_2 ) ;
return - V_27 ;
}
return 0 ;
}
static void F_13 ( struct V_1 * V_1 )
{
if ( ! V_1 -> V_4 . V_28 )
return;
F_14 ( V_1 -> V_4 . V_28 ) ;
F_15 ( V_1 -> V_29 ) ;
V_1 -> V_4 . V_30 = F_16 ( V_1 -> V_29 ) ;
F_15 ( V_1 -> V_31 ) ;
}
static void F_17 ( struct V_1 * V_1 )
{
if ( ! V_1 -> V_4 . V_28 )
return;
F_18 ( V_1 -> V_31 ) ;
F_18 ( V_1 -> V_29 ) ;
F_19 ( V_1 -> V_4 . V_28 ) ;
}
static int F_20 ( struct V_2 * V_4 )
{
unsigned short V_32 ;
int V_33 ;
do {
V_32 = F_21 ( V_4 , V_34 ) ;
if ( V_32 & F_22 ( V_4 ) ) {
F_23 ( V_4 , V_34 , F_24 ( V_4 ) ) ;
continue;
}
break;
} while ( 1 );
if ( ! ( V_32 & F_25 ( V_4 ) ) )
return V_35 ;
V_33 = F_21 ( V_4 , V_36 ) ;
F_21 ( V_4 , V_34 ) ;
F_23 ( V_4 , V_34 , F_26 ( V_4 ) ) ;
return V_33 ;
}
static void F_27 ( struct V_2 * V_4 , unsigned char V_33 )
{
unsigned short V_32 ;
do {
V_32 = F_21 ( V_4 , V_34 ) ;
} while ( ! ( V_32 & F_28 ( V_4 ) ) );
F_23 ( V_4 , V_37 , V_33 ) ;
F_23 ( V_4 , V_34 , F_29 ( V_4 ) & ~ F_30 ( V_4 ) ) ;
}
static void F_31 ( struct V_2 * V_4 , unsigned int V_38 )
{
struct V_1 * V_39 = F_1 ( V_4 ) ;
struct V_7 * V_8 = V_40 [ V_39 -> V_14 -> V_16 ] + V_41 ;
if ( V_39 -> V_14 -> V_42 && V_39 -> V_14 -> V_42 -> V_43 ) {
V_39 -> V_14 -> V_42 -> V_43 ( V_4 , V_38 ) ;
return;
}
if ( ! V_8 -> V_9 )
return;
if ( ! ( V_38 & V_44 ) )
F_23 ( V_4 , V_41 , 0x0080 ) ;
}
static int F_32 ( struct V_2 * V_4 )
{
struct V_7 * V_8 ;
V_8 = F_4 ( V_4 , V_45 ) ;
if ( V_8 -> V_9 )
return F_21 ( V_4 , V_45 ) & 0xff ;
V_8 = F_4 ( V_4 , V_46 ) ;
if ( V_8 -> V_9 )
return F_21 ( V_4 , V_46 ) >> 8 ;
return ! ( F_21 ( V_4 , V_34 ) & V_47 ) ;
}
static int F_33 ( struct V_2 * V_4 )
{
return V_4 -> V_48 - F_32 ( V_4 ) ;
}
static int F_34 ( struct V_2 * V_4 )
{
struct V_7 * V_8 ;
V_8 = F_4 ( V_4 , V_49 ) ;
if ( V_8 -> V_9 )
return F_21 ( V_4 , V_49 ) & 0xff ;
V_8 = F_4 ( V_4 , V_46 ) ;
if ( V_8 -> V_9 )
return F_21 ( V_4 , V_46 ) & ( ( V_4 -> V_48 << 1 ) - 1 ) ;
return ( F_21 ( V_4 , V_34 ) & F_25 ( V_4 ) ) != 0 ;
}
static inline int F_35 ( struct V_2 * V_4 )
{
struct V_1 * V_39 = F_1 ( V_4 ) ;
if ( V_39 -> V_14 -> V_50 <= 0 )
return 1 ;
return ! ! F_36 ( V_39 -> V_14 -> V_50 ) ;
}
static void F_37 ( struct V_2 * V_4 )
{
struct V_51 * V_52 = & V_4 -> V_53 -> V_52 ;
unsigned int V_54 = F_38 ( V_4 ) ;
unsigned short V_32 ;
unsigned short V_55 ;
int V_56 ;
V_32 = F_21 ( V_4 , V_34 ) ;
if ( ! ( V_32 & F_28 ( V_4 ) ) ) {
V_55 = F_21 ( V_4 , V_57 ) ;
if ( F_39 ( V_52 ) )
V_55 &= ~ V_58 ;
else
V_55 |= V_58 ;
F_23 ( V_4 , V_57 , V_55 ) ;
return;
}
V_56 = F_33 ( V_4 ) ;
do {
unsigned char V_33 ;
if ( V_4 -> V_59 ) {
V_33 = V_4 -> V_59 ;
V_4 -> V_59 = 0 ;
} else if ( ! F_39 ( V_52 ) && ! V_54 ) {
V_33 = V_52 -> V_60 [ V_52 -> V_61 ] ;
V_52 -> V_61 = ( V_52 -> V_61 + 1 ) & ( V_62 - 1 ) ;
} else {
break;
}
F_23 ( V_4 , V_37 , V_33 ) ;
V_4 -> V_63 . V_64 ++ ;
} while ( -- V_56 > 0 );
F_23 ( V_4 , V_34 , F_29 ( V_4 ) ) ;
if ( F_40 ( V_52 ) < V_65 )
F_41 ( V_4 ) ;
if ( F_39 ( V_52 ) ) {
F_42 ( V_4 ) ;
} else {
V_55 = F_21 ( V_4 , V_57 ) ;
if ( V_4 -> type != V_15 ) {
F_21 ( V_4 , V_34 ) ;
F_23 ( V_4 , V_34 , F_29 ( V_4 ) ) ;
}
V_55 |= V_58 ;
F_23 ( V_4 , V_57 , V_55 ) ;
}
}
static void F_43 ( struct V_2 * V_4 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_66 * V_67 = V_4 -> V_53 -> V_4 . V_67 ;
int V_68 , V_56 , V_69 = 0 ;
unsigned short V_32 ;
unsigned char V_70 ;
V_32 = F_21 ( V_4 , V_34 ) ;
if ( ! ( V_32 & F_25 ( V_4 ) ) )
return;
while ( 1 ) {
V_56 = F_44 ( V_67 , F_34 ( V_4 ) ) ;
if ( V_56 == 0 )
break;
if ( V_4 -> type == V_15 ) {
char V_33 = F_21 ( V_4 , V_36 ) ;
if ( F_45 ( V_4 , V_33 ) ||
V_1 -> V_71 )
V_56 = 0 ;
else
F_46 ( V_67 , V_33 , V_72 ) ;
} else {
for ( V_68 = 0 ; V_68 < V_56 ; V_68 ++ ) {
char V_33 = F_21 ( V_4 , V_36 ) ;
V_32 = F_21 ( V_4 , V_34 ) ;
#if F_47 ( V_73 )
if ( V_1 -> V_71 ) {
if ( ( V_33 == 0 ) &&
( V_32 & F_48 ( V_4 ) ) ) {
V_56 -- ; V_68 -- ;
continue;
}
F_49 ( V_4 -> V_28 , L_3 , V_33 ) ;
V_1 -> V_71 = 0 ;
if ( F_50 ( V_33 ) ) {
V_56 -- ; V_68 -- ;
continue;
}
}
#endif
if ( F_45 ( V_4 , V_33 ) ) {
V_56 -- ; V_68 -- ;
continue;
}
if ( V_32 & F_48 ( V_4 ) ) {
V_70 = V_74 ;
F_51 ( V_4 -> V_28 , L_4 ) ;
} else if ( V_32 & F_52 ( V_4 ) ) {
V_70 = V_75 ;
F_51 ( V_4 -> V_28 , L_5 ) ;
} else
V_70 = V_72 ;
F_46 ( V_67 , V_33 , V_70 ) ;
}
}
F_21 ( V_4 , V_34 ) ;
F_23 ( V_4 , V_34 , F_26 ( V_4 ) ) ;
V_69 += V_56 ;
V_4 -> V_63 . V_76 += V_56 ;
}
if ( V_69 ) {
F_53 ( V_67 ) ;
} else {
F_21 ( V_4 , V_34 ) ;
F_23 ( V_4 , V_34 , F_26 ( V_4 ) ) ;
}
}
static inline void F_54 ( struct V_1 * V_4 )
{
F_55 ( & V_4 -> V_77 , V_78 + V_79 ) ;
}
static void F_56 ( unsigned long V_80 )
{
struct V_1 * V_4 = (struct V_1 * ) V_80 ;
F_13 ( V_4 ) ;
if ( F_35 ( & V_4 -> V_4 ) == 0 ) {
V_4 -> V_71 = 1 ;
F_54 ( V_4 ) ;
} else if ( V_4 -> V_71 == 1 ) {
V_4 -> V_71 = 2 ;
F_54 ( V_4 ) ;
} else
V_4 -> V_71 = 0 ;
F_17 ( V_4 ) ;
}
static int F_57 ( struct V_2 * V_4 )
{
int V_69 = 0 ;
unsigned short V_32 = F_21 ( V_4 , V_34 ) ;
struct V_66 * V_67 = V_4 -> V_53 -> V_4 . V_67 ;
struct V_1 * V_39 = F_1 ( V_4 ) ;
if ( V_39 -> V_14 -> V_81 != V_82 ) {
if ( V_32 & ( 1 << V_39 -> V_14 -> V_81 ) ) {
if ( F_46 ( V_67 , 0 , V_83 ) )
V_69 ++ ;
F_51 ( V_4 -> V_28 , L_6 ) ;
}
}
if ( V_32 & F_48 ( V_4 ) ) {
if ( F_35 ( V_4 ) == 0 ) {
struct V_1 * V_1 = F_1 ( V_4 ) ;
if ( ! V_1 -> V_71 ) {
V_1 -> V_71 = 1 ;
F_54 ( V_1 ) ;
if ( F_58 ( V_4 ) )
return 0 ;
F_49 ( V_4 -> V_28 , L_7 ) ;
if ( F_46 ( V_67 , 0 , V_84 ) )
V_69 ++ ;
}
} else {
if ( F_46 ( V_67 , 0 , V_74 ) )
V_69 ++ ;
F_51 ( V_4 -> V_28 , L_4 ) ;
}
}
if ( V_32 & F_52 ( V_4 ) ) {
if ( F_46 ( V_67 , 0 , V_75 ) )
V_69 ++ ;
F_51 ( V_4 -> V_28 , L_8 ) ;
}
if ( V_69 )
F_53 ( V_67 ) ;
return V_69 ;
}
static int F_59 ( struct V_2 * V_4 )
{
struct V_66 * V_67 = V_4 -> V_53 -> V_4 . V_67 ;
struct V_1 * V_39 = F_1 ( V_4 ) ;
struct V_7 * V_8 ;
int V_69 = 0 ;
V_8 = F_4 ( V_4 , V_85 ) ;
if ( ! V_8 -> V_9 )
return 0 ;
if ( ( F_21 ( V_4 , V_85 ) & ( 1 << V_39 -> V_14 -> V_81 ) ) ) {
F_23 ( V_4 , V_85 , 0 ) ;
F_46 ( V_67 , 0 , V_83 ) ;
F_53 ( V_67 ) ;
F_51 ( V_4 -> V_28 , L_9 ) ;
V_69 ++ ;
}
return V_69 ;
}
static int F_60 ( struct V_2 * V_4 )
{
int V_69 = 0 ;
unsigned short V_32 = F_21 ( V_4 , V_34 ) ;
struct V_66 * V_67 = V_4 -> V_53 -> V_4 . V_67 ;
struct V_1 * V_39 = F_1 ( V_4 ) ;
if ( F_58 ( V_4 ) )
return 0 ;
if ( ! V_39 -> V_71 && V_32 & F_61 ( V_4 ) ) {
#if F_47 ( V_73 )
V_39 -> V_71 = 1 ;
#endif
if ( F_46 ( V_67 , 0 , V_84 ) )
V_69 ++ ;
F_49 ( V_4 -> V_28 , L_7 ) ;
}
if ( V_69 )
F_53 ( V_67 ) ;
V_69 += F_59 ( V_4 ) ;
return V_69 ;
}
static T_1 F_62 ( int V_86 , void * V_87 )
{
#ifdef F_63
struct V_2 * V_4 = V_87 ;
struct V_1 * V_39 = F_1 ( V_4 ) ;
if ( V_39 -> V_88 ) {
T_2 V_89 = F_21 ( V_4 , V_57 ) ;
T_2 V_90 = F_21 ( V_4 , V_34 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
F_64 ( V_86 ) ;
V_89 |= 0x4000 ;
} else {
V_89 &= ~ V_91 ;
}
F_23 ( V_4 , V_57 , V_89 ) ;
F_23 ( V_4 , V_34 , V_90 & ~ ( 1 | F_25 ( V_4 ) ) ) ;
F_49 ( V_4 -> V_28 , L_10 ,
V_78 , V_39 -> V_92 ) ;
F_55 ( & V_39 -> V_93 , V_78 + V_39 -> V_92 ) ;
return V_94 ;
}
#endif
F_43 ( V_87 ) ;
return V_94 ;
}
static T_1 F_65 ( int V_86 , void * V_87 )
{
struct V_2 * V_4 = V_87 ;
unsigned long V_95 ;
F_66 ( & V_4 -> V_96 , V_95 ) ;
F_37 ( V_4 ) ;
F_67 ( & V_4 -> V_96 , V_95 ) ;
return V_94 ;
}
static T_1 F_68 ( int V_86 , void * V_87 )
{
struct V_2 * V_4 = V_87 ;
if ( V_4 -> type == V_15 ) {
if ( F_57 ( V_4 ) ) {
F_21 ( V_4 , V_34 ) ;
F_23 ( V_4 , V_34 , F_26 ( V_4 ) ) ;
}
} else {
F_59 ( V_4 ) ;
F_62 ( V_86 , V_87 ) ;
}
F_23 ( V_4 , V_34 , F_24 ( V_4 ) ) ;
F_65 ( V_86 , V_87 ) ;
return V_94 ;
}
static T_1 F_69 ( int V_86 , void * V_87 )
{
struct V_2 * V_4 = V_87 ;
F_60 ( V_4 ) ;
F_23 ( V_4 , V_34 , F_70 ( V_4 ) ) ;
return V_94 ;
}
static inline unsigned long F_71 ( struct V_2 * V_4 )
{
return V_91 | ( F_1 ( V_4 ) -> V_14 -> V_97 & V_98 ) ;
}
static T_1 F_72 ( int V_86 , void * V_87 )
{
unsigned short V_99 , V_100 , V_101 ;
struct V_2 * V_4 = V_87 ;
struct V_1 * V_39 = F_1 ( V_4 ) ;
T_1 V_102 = V_103 ;
V_99 = F_21 ( V_4 , V_34 ) ;
V_100 = F_21 ( V_4 , V_57 ) ;
V_101 = V_100 & F_71 ( V_4 ) ;
if ( ( V_99 & F_28 ( V_4 ) ) && ( V_100 & V_58 ) &&
! V_39 -> V_104 )
V_102 = F_65 ( V_86 , V_87 ) ;
if ( ( ( V_99 & F_25 ( V_4 ) ) || V_39 -> V_88 ) &&
( V_100 & V_91 ) )
V_102 = F_62 ( V_86 , V_87 ) ;
if ( ( V_99 & F_22 ( V_4 ) ) && V_101 )
V_102 = F_68 ( V_86 , V_87 ) ;
if ( ( V_99 & F_61 ( V_4 ) ) && V_101 )
V_102 = F_69 ( V_86 , V_87 ) ;
return V_102 ;
}
static int F_73 ( struct V_105 * V_106 ,
unsigned long V_107 , void * V_5 )
{
struct V_1 * V_1 ;
unsigned long V_95 ;
V_1 = F_2 ( V_106 , struct V_1 , V_108 ) ;
if ( ( V_107 == V_109 ) ||
( V_107 == V_110 ) ) {
struct V_2 * V_4 = & V_1 -> V_4 ;
F_66 ( & V_4 -> V_96 , V_95 ) ;
V_4 -> V_30 = F_16 ( V_1 -> V_29 ) ;
F_67 ( & V_4 -> V_96 , V_95 ) ;
}
return V_111 ;
}
static int F_74 ( struct V_1 * V_4 )
{
struct V_2 * V_112 = & V_4 -> V_4 ;
int V_68 , V_113 , V_102 = 0 ;
for ( V_68 = V_113 = 0 ; V_68 < V_114 ; V_68 ++ , V_113 ++ ) {
struct V_115 * V_116 ;
unsigned int V_86 ;
if ( F_75 ( V_4 ) ) {
V_68 = V_117 ;
V_86 = V_112 -> V_86 ;
} else
V_86 = V_4 -> V_14 -> V_118 [ V_68 ] ;
V_116 = V_115 + V_68 ;
V_4 -> V_119 [ V_113 ] = F_76 ( V_120 , L_11 ,
F_77 ( V_112 -> V_28 ) , V_116 -> V_116 ) ;
if ( ! V_4 -> V_119 [ V_113 ] ) {
F_78 ( V_112 -> V_28 , L_12 ,
V_116 -> V_116 ) ;
goto V_121;
}
V_102 = F_79 ( V_86 , V_116 -> V_122 , V_112 -> V_123 ,
V_4 -> V_119 [ V_113 ] , V_4 ) ;
if ( F_80 ( V_102 ) ) {
F_78 ( V_112 -> V_28 , L_13 , V_116 -> V_116 ) ;
goto V_124;
}
}
return 0 ;
V_124:
while ( -- V_68 >= 0 )
F_81 ( V_4 -> V_14 -> V_118 [ V_68 ] , V_4 ) ;
V_121:
while ( -- V_113 >= 0 )
F_82 ( V_4 -> V_119 [ V_113 ] ) ;
return V_102 ;
}
static void F_83 ( struct V_1 * V_4 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_114 ; V_68 ++ ) {
F_81 ( V_4 -> V_14 -> V_118 [ V_68 ] , V_4 ) ;
F_82 ( V_4 -> V_119 [ V_68 ] ) ;
if ( F_75 ( V_4 ) ) {
return;
}
}
}
static unsigned int F_84 ( struct V_2 * V_4 )
{
unsigned short V_32 = F_21 ( V_4 , V_34 ) ;
unsigned short V_125 = F_32 ( V_4 ) ;
return ( V_32 & F_30 ( V_4 ) ) && ! V_125 ? V_126 : 0 ;
}
static void F_85 ( struct V_2 * V_4 , unsigned int V_127 )
{
}
static unsigned int F_86 ( struct V_2 * V_4 )
{
return V_128 | V_129 | V_130 | V_131 ;
}
static void F_87 ( void * V_132 )
{
struct V_1 * V_39 = V_132 ;
struct V_2 * V_4 = & V_39 -> V_4 ;
struct V_51 * V_52 = & V_4 -> V_53 -> V_52 ;
unsigned long V_95 ;
F_49 ( V_4 -> V_28 , L_14 , V_133 , V_4 -> line ) ;
F_66 ( & V_4 -> V_96 , V_95 ) ;
V_52 -> V_61 += F_88 ( & V_39 -> V_134 ) ;
V_52 -> V_61 &= V_62 - 1 ;
V_4 -> V_63 . V_64 += F_88 ( & V_39 -> V_134 ) ;
F_89 ( V_39 -> V_135 ) ;
V_39 -> V_136 = - V_27 ;
V_39 -> V_135 = NULL ;
if ( F_40 ( V_52 ) < V_65 )
F_41 ( V_4 ) ;
if ( ! F_39 ( V_52 ) ) {
F_90 ( & V_39 -> V_137 ) ;
} else if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
T_2 V_55 = F_21 ( V_4 , V_57 ) ;
F_23 ( V_4 , V_57 , V_55 & ~ V_58 ) ;
}
F_67 ( & V_4 -> V_96 , V_95 ) ;
}
static int F_91 ( struct V_1 * V_39 , struct V_66 * V_67 ,
T_3 V_56 )
{
struct V_2 * V_4 = & V_39 -> V_4 ;
int V_68 , V_138 , V_139 ;
V_139 = F_44 ( V_67 , V_56 ) ;
if ( V_39 -> V_140 == V_39 -> V_141 [ 0 ] ) {
V_138 = 0 ;
} else if ( V_39 -> V_140 == V_39 -> V_141 [ 1 ] ) {
V_138 = 1 ;
} else {
F_78 ( V_4 -> V_28 , L_15 , V_39 -> V_140 ) ;
return 0 ;
}
if ( V_139 < V_56 )
F_92 ( V_4 -> V_28 , L_16 ,
V_56 - V_139 ) ;
if ( ! V_139 )
return V_139 ;
for ( V_68 = 0 ; V_68 < V_139 ; V_68 ++ )
F_46 ( V_67 , ( ( V_142 * ) F_93 ( & V_39 -> V_143 [ V_138 ] ) ) [ V_68 ] ,
V_72 ) ;
V_4 -> V_63 . V_76 += V_139 ;
return V_139 ;
}
static void F_94 ( void * V_132 )
{
struct V_1 * V_39 = V_132 ;
struct V_2 * V_4 = & V_39 -> V_4 ;
struct V_66 * V_67 = V_4 -> V_53 -> V_4 . V_67 ;
unsigned long V_95 ;
int V_56 ;
F_49 ( V_4 -> V_28 , L_17 , V_133 , V_4 -> line , V_39 -> V_140 ) ;
F_66 ( & V_4 -> V_96 , V_95 ) ;
V_56 = F_91 ( V_39 , V_67 , V_39 -> V_144 ) ;
F_55 ( & V_39 -> V_93 , V_78 + V_39 -> V_92 ) ;
F_67 ( & V_4 -> V_96 , V_95 ) ;
if ( V_56 )
F_53 ( V_67 ) ;
F_90 ( & V_39 -> V_145 ) ;
}
static void F_95 ( struct V_1 * V_39 , bool V_146 )
{
struct V_147 * V_148 = V_39 -> V_88 ;
struct V_2 * V_4 = & V_39 -> V_4 ;
V_39 -> V_88 = NULL ;
V_39 -> V_141 [ 0 ] = V_39 -> V_141 [ 1 ] = - V_27 ;
F_96 ( V_148 ) ;
if ( F_97 ( & V_39 -> V_143 [ 0 ] ) )
F_98 ( V_4 -> V_28 , V_39 -> V_144 * 2 ,
F_93 ( & V_39 -> V_143 [ 0 ] ) , F_97 ( & V_39 -> V_143 [ 0 ] ) ) ;
if ( V_146 )
F_99 ( V_4 ) ;
}
static void F_100 ( struct V_1 * V_39 , bool V_146 )
{
struct V_147 * V_148 = V_39 -> V_104 ;
struct V_2 * V_4 = & V_39 -> V_4 ;
V_39 -> V_104 = NULL ;
V_39 -> V_136 = - V_27 ;
F_96 ( V_148 ) ;
if ( V_146 )
F_101 ( V_4 ) ;
}
static void F_102 ( struct V_1 * V_39 )
{
struct V_147 * V_148 = V_39 -> V_88 ;
int V_68 ;
for ( V_68 = 0 ; V_68 < 2 ; V_68 ++ ) {
struct V_149 * V_150 = & V_39 -> V_143 [ V_68 ] ;
struct V_151 * V_116 ;
V_116 = V_148 -> V_152 -> V_153 ( V_148 ,
V_150 , 1 , V_154 , V_155 ) ;
if ( V_116 ) {
V_39 -> V_156 [ V_68 ] = V_116 ;
V_116 -> V_157 = F_94 ;
V_116 -> V_158 = V_39 ;
V_39 -> V_141 [ V_68 ] = V_116 -> V_159 ( V_116 ) ;
}
if ( ! V_116 || V_39 -> V_141 [ V_68 ] < 0 ) {
if ( V_68 ) {
F_89 ( V_39 -> V_156 [ 0 ] ) ;
V_39 -> V_141 [ 0 ] = - V_27 ;
}
if ( V_116 ) {
F_89 ( V_116 ) ;
V_39 -> V_141 [ V_68 ] = - V_27 ;
}
F_92 ( V_39 -> V_4 . V_28 ,
L_18 ) ;
F_95 ( V_39 , true ) ;
return;
}
F_49 ( V_39 -> V_4 . V_28 , L_19 , V_133 ,
V_39 -> V_141 [ V_68 ] , V_68 ) ;
}
V_39 -> V_140 = V_39 -> V_141 [ 0 ] ;
F_103 ( V_148 ) ;
}
static void F_104 ( struct V_160 * V_161 )
{
struct V_1 * V_39 = F_2 ( V_161 , struct V_1 , V_145 ) ;
struct V_2 * V_4 = & V_39 -> V_4 ;
struct V_151 * V_116 ;
int V_162 ;
if ( V_39 -> V_140 == V_39 -> V_141 [ 0 ] ) {
V_162 = 0 ;
} else if ( V_39 -> V_140 == V_39 -> V_141 [ 1 ] ) {
V_162 = 1 ;
} else {
F_78 ( V_4 -> V_28 , L_15 , V_39 -> V_140 ) ;
return;
}
V_116 = V_39 -> V_156 [ V_162 ] ;
if ( F_105 ( V_39 -> V_88 , V_39 -> V_140 , NULL , NULL ) !=
V_163 ) {
struct V_66 * V_67 = V_4 -> V_53 -> V_4 . V_67 ;
struct V_147 * V_148 = V_39 -> V_88 ;
struct V_164 * V_164 = F_2 ( V_116 , struct V_164 ,
V_165 ) ;
unsigned long V_95 ;
int V_56 ;
V_148 -> V_152 -> V_166 ( V_148 , V_167 , 0 ) ;
F_49 ( V_4 -> V_28 , L_20 ,
V_164 -> V_168 , V_164 -> V_169 ) ;
F_66 ( & V_4 -> V_96 , V_95 ) ;
V_56 = F_91 ( V_39 , V_67 , V_164 -> V_168 ) ;
F_67 ( & V_4 -> V_96 , V_95 ) ;
if ( V_56 )
F_53 ( V_67 ) ;
F_102 ( V_39 ) ;
return;
}
V_39 -> V_141 [ V_162 ] = V_116 -> V_159 ( V_116 ) ;
if ( V_39 -> V_141 [ V_162 ] < 0 ) {
F_92 ( V_4 -> V_28 , L_21 ) ;
F_95 ( V_39 , true ) ;
return;
}
V_39 -> V_140 = V_39 -> V_141 [ ! V_162 ] ;
F_49 ( V_4 -> V_28 , L_22 , V_133 ,
V_39 -> V_141 [ V_162 ] , V_162 , V_39 -> V_140 ) ;
}
static void F_106 ( struct V_160 * V_161 )
{
struct V_1 * V_39 = F_2 ( V_161 , struct V_1 , V_137 ) ;
struct V_151 * V_116 ;
struct V_147 * V_148 = V_39 -> V_104 ;
struct V_2 * V_4 = & V_39 -> V_4 ;
struct V_51 * V_52 = & V_4 -> V_53 -> V_52 ;
struct V_149 * V_150 = & V_39 -> V_134 ;
F_107 ( & V_4 -> V_96 ) ;
V_150 -> V_6 = V_52 -> V_61 & ( V_62 - 1 ) ;
F_97 ( V_150 ) = ( F_97 ( V_150 ) & ~ ( V_62 - 1 ) ) +
V_150 -> V_6 ;
F_88 ( V_150 ) = F_108 ( ( int ) F_109 ( V_52 -> V_170 , V_52 -> V_61 , V_62 ) ,
F_110 ( V_52 -> V_170 , V_52 -> V_61 , V_62 ) ) ;
F_111 ( & V_4 -> V_96 ) ;
F_112 ( ! F_88 ( V_150 ) ) ;
V_116 = V_148 -> V_152 -> V_153 ( V_148 ,
V_150 , V_39 -> V_171 , V_172 ,
V_155 | V_173 ) ;
if ( ! V_116 ) {
F_100 ( V_39 , true ) ;
return;
}
F_113 ( V_4 -> V_28 , V_150 , 1 , V_172 ) ;
F_107 ( & V_4 -> V_96 ) ;
V_39 -> V_135 = V_116 ;
V_116 -> V_157 = F_87 ;
V_116 -> V_158 = V_39 ;
F_111 ( & V_4 -> V_96 ) ;
V_39 -> V_136 = V_116 -> V_159 ( V_116 ) ;
if ( V_39 -> V_136 < 0 ) {
F_92 ( V_4 -> V_28 , L_23 ) ;
F_100 ( V_39 , true ) ;
return;
}
F_49 ( V_4 -> V_28 , L_24 , V_133 ,
V_52 -> V_60 , V_52 -> V_61 , V_52 -> V_170 , V_39 -> V_136 ) ;
F_103 ( V_148 ) ;
}
static void F_101 ( struct V_2 * V_4 )
{
struct V_1 * V_39 = F_1 ( V_4 ) ;
unsigned short V_55 ;
#ifdef F_63
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
T_2 V_162 , V_89 = F_21 ( V_4 , V_57 ) ;
if ( V_39 -> V_104 )
V_162 = V_89 | 0x8000 ;
else
V_162 = V_89 & ~ 0x8000 ;
if ( V_162 != V_89 )
F_23 ( V_4 , V_57 , V_162 ) ;
}
if ( V_39 -> V_104 && ! F_39 ( & V_39 -> V_4 . V_53 -> V_52 ) &&
V_39 -> V_136 < 0 )
F_90 ( & V_39 -> V_137 ) ;
#endif
if ( ! V_39 -> V_104 || V_4 -> type == V_20 || V_4 -> type == V_22 ) {
V_55 = F_21 ( V_4 , V_57 ) ;
F_23 ( V_4 , V_57 , V_55 | V_58 ) ;
}
}
static void F_42 ( struct V_2 * V_4 )
{
unsigned short V_55 ;
V_55 = F_21 ( V_4 , V_57 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 )
V_55 &= ~ 0x8000 ;
V_55 &= ~ V_58 ;
F_23 ( V_4 , V_57 , V_55 ) ;
}
static void F_99 ( struct V_2 * V_4 )
{
unsigned short V_55 ;
V_55 = F_21 ( V_4 , V_57 ) | F_71 ( V_4 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 )
V_55 &= ~ 0x4000 ;
F_23 ( V_4 , V_57 , V_55 ) ;
}
static void F_114 ( struct V_2 * V_4 )
{
unsigned short V_55 ;
V_55 = F_21 ( V_4 , V_57 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 )
V_55 &= ~ 0x4000 ;
V_55 &= ~ F_71 ( V_4 ) ;
F_23 ( V_4 , V_57 , V_55 ) ;
}
static void F_115 ( struct V_2 * V_4 )
{
}
static void F_116 ( struct V_2 * V_4 , int V_174 )
{
}
static bool F_117 ( struct V_147 * V_148 , void * V_175 )
{
struct V_176 * V_177 = V_175 ;
F_49 ( V_148 -> V_152 -> V_28 , L_25 , V_133 ,
V_177 -> V_178 ) ;
V_148 -> V_179 = V_177 ;
return true ;
}
static void F_118 ( unsigned long V_132 )
{
struct V_1 * V_39 = (struct V_1 * ) V_132 ;
struct V_2 * V_4 = & V_39 -> V_4 ;
T_2 V_89 = F_21 ( V_4 , V_57 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
V_89 &= ~ 0x4000 ;
F_119 ( V_39 -> V_14 -> V_118 [ 1 ] ) ;
}
F_23 ( V_4 , V_57 , V_89 | V_91 ) ;
F_49 ( V_4 -> V_28 , L_26 ) ;
F_90 ( & V_39 -> V_145 ) ;
}
static void F_120 ( struct V_2 * V_4 )
{
struct V_1 * V_39 = F_1 ( V_4 ) ;
struct V_176 * V_177 ;
struct V_147 * V_148 ;
T_4 V_180 ;
int V_181 ;
F_49 ( V_4 -> V_28 , L_27 , V_133 ,
V_4 -> line ) ;
if ( V_39 -> V_14 -> V_182 <= 0 || V_39 -> V_14 -> V_183 <= 0 )
return;
F_121 ( V_180 ) ;
F_122 ( V_184 , V_180 ) ;
V_177 = & V_39 -> V_185 ;
V_177 -> V_178 = V_39 -> V_14 -> V_182 ;
V_39 -> V_136 = - V_27 ;
V_148 = F_123 ( V_180 , F_117 , V_177 ) ;
F_49 ( V_4 -> V_28 , L_28 , V_133 , V_148 ) ;
if ( V_148 ) {
V_39 -> V_104 = V_148 ;
F_124 ( & V_39 -> V_134 , 1 ) ;
F_112 ( ( int ) V_4 -> V_53 -> V_52 . V_60 & ~ V_186 ) ;
F_125 ( & V_39 -> V_134 , F_126 ( V_4 -> V_53 -> V_52 . V_60 ) ,
V_62 , ( int ) V_4 -> V_53 -> V_52 . V_60 & ~ V_186 ) ;
V_181 = F_127 ( V_4 -> V_28 , & V_39 -> V_134 , 1 , V_172 ) ;
if ( ! V_181 )
F_100 ( V_39 , false ) ;
else
F_49 ( V_4 -> V_28 , L_29 , V_133 ,
F_88 ( & V_39 -> V_134 ) ,
V_4 -> V_53 -> V_52 . V_60 , F_97 ( & V_39 -> V_134 ) ) ;
V_39 -> V_171 = V_181 ;
F_128 ( & V_39 -> V_137 , F_106 ) ;
}
V_177 = & V_39 -> V_187 ;
V_177 -> V_178 = V_39 -> V_14 -> V_183 ;
V_148 = F_123 ( V_180 , F_117 , V_177 ) ;
F_49 ( V_4 -> V_28 , L_30 , V_133 , V_148 ) ;
if ( V_148 ) {
T_5 V_188 [ 2 ] ;
void * V_60 [ 2 ] ;
int V_68 ;
V_39 -> V_88 = V_148 ;
V_39 -> V_144 = 2 * F_129 ( 16 , ( int ) V_4 -> V_48 ) ;
V_60 [ 0 ] = F_130 ( V_4 -> V_28 , V_39 -> V_144 * 2 ,
& V_188 [ 0 ] , V_120 ) ;
if ( ! V_60 [ 0 ] ) {
F_92 ( V_4 -> V_28 ,
L_31 ) ;
F_95 ( V_39 , true ) ;
return;
}
V_60 [ 1 ] = V_60 [ 0 ] + V_39 -> V_144 ;
V_188 [ 1 ] = V_188 [ 0 ] + V_39 -> V_144 ;
for ( V_68 = 0 ; V_68 < 2 ; V_68 ++ ) {
struct V_149 * V_150 = & V_39 -> V_143 [ V_68 ] ;
F_124 ( V_150 , 1 ) ;
F_125 ( V_150 , F_126 ( V_60 [ V_68 ] ) , V_39 -> V_144 ,
( int ) V_60 [ V_68 ] & ~ V_186 ) ;
F_97 ( V_150 ) = V_188 [ V_68 ] ;
}
F_128 ( & V_39 -> V_145 , F_104 ) ;
F_131 ( & V_39 -> V_93 , F_118 , ( unsigned long ) V_39 ) ;
F_102 ( V_39 ) ;
}
}
static void F_132 ( struct V_2 * V_4 )
{
struct V_1 * V_39 = F_1 ( V_4 ) ;
if ( V_39 -> V_104 )
F_100 ( V_39 , false ) ;
if ( V_39 -> V_88 )
F_95 ( V_39 , false ) ;
}
static inline void F_120 ( struct V_2 * V_4 )
{
}
static inline void F_132 ( struct V_2 * V_4 )
{
}
static int F_133 ( struct V_2 * V_4 )
{
struct V_1 * V_39 = F_1 ( V_4 ) ;
int V_102 ;
F_49 ( V_4 -> V_28 , L_14 , V_133 , V_4 -> line ) ;
F_13 ( V_39 ) ;
V_102 = F_74 ( V_39 ) ;
if ( F_80 ( V_102 < 0 ) )
return V_102 ;
F_120 ( V_4 ) ;
F_101 ( V_4 ) ;
F_99 ( V_4 ) ;
return 0 ;
}
static void F_134 ( struct V_2 * V_4 )
{
struct V_1 * V_39 = F_1 ( V_4 ) ;
F_49 ( V_4 -> V_28 , L_14 , V_133 , V_4 -> line ) ;
F_114 ( V_4 ) ;
F_42 ( V_4 ) ;
F_132 ( V_4 ) ;
F_83 ( V_39 ) ;
F_17 ( V_39 ) ;
}
static unsigned int F_135 ( unsigned int V_189 , unsigned int V_190 ,
unsigned long V_191 )
{
switch ( V_189 ) {
case V_192 :
return ( ( V_191 + 16 * V_190 ) / ( 16 * V_190 ) - 1 ) ;
case V_193 :
return ( ( V_191 + 16 * V_190 ) / ( 32 * V_190 ) - 1 ) ;
case V_194 :
return ( ( ( V_191 * 2 ) + 16 * V_190 ) / ( 16 * V_190 ) - 1 ) ;
case V_195 :
return ( ( ( V_191 * 2 ) + 16 * V_190 ) / ( 32 * V_190 ) - 1 ) ;
case V_196 :
return ( ( ( V_191 * 1000 / 32 ) / V_190 ) - 1 ) ;
}
F_136 ( 1 ) ;
return ( ( V_191 + 16 * V_190 ) / ( 32 * V_190 ) - 1 ) ;
}
static void F_137 ( struct V_2 * V_4 )
{
unsigned int V_32 ;
do {
V_32 = F_21 ( V_4 , V_34 ) ;
} while ( ! ( V_32 & F_30 ( V_4 ) ) );
F_23 ( V_4 , V_57 , 0x00 ) ;
if ( V_4 -> type != V_15 )
F_23 ( V_4 , V_197 , V_198 | V_199 ) ;
}
static void F_138 ( struct V_2 * V_4 , struct V_200 * V_201 ,
struct V_200 * V_202 )
{
struct V_1 * V_39 = F_1 ( V_4 ) ;
unsigned int V_203 , V_204 , V_205 ;
int V_206 = - 1 ;
T_2 V_207 = 0 ;
V_205 = V_4 -> V_30 ? V_4 -> V_30 / 16 : 115200 ;
V_203 = F_139 ( V_4 , V_201 , V_202 , 0 , V_205 ) ;
if ( F_140 ( V_203 && V_4 -> V_30 ) )
V_206 = F_135 ( V_39 -> V_14 -> V_208 , V_203 , V_4 -> V_30 ) ;
F_13 ( V_39 ) ;
F_137 ( V_4 ) ;
V_204 = F_21 ( V_4 , V_209 ) & 3 ;
if ( ( V_201 -> V_210 & V_211 ) == V_212 )
V_204 |= 0x40 ;
if ( V_201 -> V_210 & V_213 )
V_204 |= 0x20 ;
if ( V_201 -> V_210 & V_214 )
V_204 |= 0x30 ;
if ( V_201 -> V_210 & V_215 )
V_204 |= 0x08 ;
F_141 ( V_4 , V_201 -> V_210 , V_203 ) ;
F_23 ( V_4 , V_209 , V_204 ) ;
F_49 ( V_4 -> V_28 , L_32 , V_133 , V_204 , V_206 ,
V_39 -> V_14 -> V_97 ) ;
if ( V_206 > 0 ) {
if ( V_206 >= 256 ) {
F_23 ( V_4 , V_209 , ( F_21 ( V_4 , V_209 ) & ~ 3 ) | 1 ) ;
V_206 >>= 2 ;
} else
F_23 ( V_4 , V_209 , F_21 ( V_4 , V_209 ) & ~ 3 ) ;
F_23 ( V_4 , V_216 , V_206 ) ;
F_142 ( ( 1000000 + ( V_203 - 1 ) ) / V_203 ) ;
}
F_31 ( V_4 , V_201 -> V_210 ) ;
F_23 ( V_4 , V_197 , V_207 | ( ( V_201 -> V_210 & V_44 ) ? V_217 : 0 ) ) ;
F_23 ( V_4 , V_57 , V_39 -> V_14 -> V_97 ) ;
#ifdef F_63
if ( V_39 -> V_88 ) {
V_39 -> V_92 = ( V_4 -> V_218 - V_219 / 50 ) * V_39 -> V_144 * 3 /
V_4 -> V_48 / 2 ;
F_49 ( V_4 -> V_28 ,
L_33 ,
V_39 -> V_92 * 1000 / V_219 , V_4 -> V_218 ) ;
if ( V_39 -> V_92 < F_143 ( 20 ) )
V_39 -> V_92 = F_143 ( 20 ) ;
}
#endif
if ( ( V_201 -> V_210 & V_220 ) != 0 )
F_99 ( V_4 ) ;
F_17 ( V_39 ) ;
}
static const char * F_144 ( struct V_2 * V_4 )
{
switch ( V_4 -> type ) {
case V_18 :
return L_34 ;
case V_15 :
return L_35 ;
case V_24 :
return L_36 ;
case V_20 :
return L_37 ;
case V_22 :
return L_38 ;
}
return NULL ;
}
static inline unsigned long F_145 ( struct V_2 * V_4 )
{
return 64 ;
}
static int F_146 ( struct V_2 * V_4 )
{
unsigned long V_9 = F_145 ( V_4 ) ;
if ( V_4 -> V_10 )
return 0 ;
if ( V_4 -> V_95 & V_221 ) {
V_4 -> V_10 = F_147 ( V_4 -> V_222 , V_9 ) ;
if ( F_80 ( ! V_4 -> V_10 ) ) {
F_78 ( V_4 -> V_28 , L_39 , V_4 -> line ) ;
return - V_223 ;
}
} else {
V_4 -> V_10 = ( void V_224 * ) V_4 -> V_222 ;
}
return 0 ;
}
static void F_148 ( struct V_2 * V_4 )
{
if ( V_4 -> V_95 & V_221 ) {
F_149 ( V_4 -> V_10 ) ;
V_4 -> V_10 = NULL ;
}
F_150 ( V_4 -> V_222 , F_145 ( V_4 ) ) ;
}
static int F_151 ( struct V_2 * V_4 )
{
unsigned long V_9 = F_145 ( V_4 ) ;
struct V_225 * V_226 ;
int V_102 ;
V_226 = F_152 ( V_4 -> V_222 , V_9 , F_77 ( V_4 -> V_28 ) ) ;
if ( F_80 ( V_226 == NULL ) )
return - V_227 ;
V_102 = F_146 ( V_4 ) ;
if ( F_80 ( V_102 != 0 ) ) {
F_153 ( V_226 ) ;
return V_102 ;
}
return 0 ;
}
static void F_154 ( struct V_2 * V_4 , int V_95 )
{
if ( V_95 & V_228 ) {
struct V_1 * V_229 = F_1 ( V_4 ) ;
V_4 -> type = V_229 -> V_14 -> type ;
F_151 ( V_4 ) ;
}
}
static int F_155 ( struct V_2 * V_4 , struct V_230 * V_231 )
{
struct V_1 * V_39 = F_1 ( V_4 ) ;
if ( V_231 -> V_86 != V_39 -> V_14 -> V_118 [ V_232 ] || V_231 -> V_86 > V_233 )
return - V_27 ;
if ( V_231 -> V_234 < 2400 )
return - V_27 ;
return 0 ;
}
static int T_6 F_156 ( struct V_235 * V_28 ,
struct V_1 * V_1 ,
unsigned int V_236 ,
struct V_13 * V_5 )
{
struct V_2 * V_4 = & V_1 -> V_4 ;
int V_102 ;
V_4 -> V_42 = & V_237 ;
V_4 -> V_238 = V_239 ;
V_4 -> line = V_236 ;
switch ( V_5 -> type ) {
case V_22 :
V_4 -> V_48 = 256 ;
break;
case V_20 :
V_4 -> V_48 = 64 ;
break;
case V_24 :
V_4 -> V_48 = 16 ;
break;
default:
V_4 -> V_48 = 1 ;
break;
}
if ( V_5 -> V_16 == V_240 ) {
V_102 = F_11 ( V_5 ) ;
if ( F_80 ( V_102 ) )
return V_102 ;
}
if ( V_28 ) {
V_1 -> V_29 = F_157 ( & V_28 -> V_28 , L_40 ) ;
if ( F_158 ( V_1 -> V_29 ) ) {
V_1 -> V_29 = F_157 ( & V_28 -> V_28 , L_41 ) ;
if ( F_158 ( V_1 -> V_29 ) ) {
F_78 ( & V_28 -> V_28 , L_42 ) ;
return F_159 ( V_1 -> V_29 ) ;
}
}
V_1 -> V_31 = F_157 ( & V_28 -> V_28 , L_43 ) ;
if ( F_158 ( V_1 -> V_31 ) )
V_1 -> V_31 = NULL ;
V_4 -> V_28 = & V_28 -> V_28 ;
F_160 ( & V_28 -> V_28 ) ;
F_161 ( & V_28 -> V_28 ) ;
}
V_1 -> V_77 . V_80 = ( unsigned long ) V_1 ;
V_1 -> V_77 . V_241 = F_56 ;
F_162 ( & V_1 -> V_77 ) ;
if ( ! V_5 -> V_242 )
V_5 -> V_242 = ( V_5 -> type == V_15 ) ?
V_243 : V_244 ;
if ( V_5 -> V_81 != V_82 ) {
if ( V_5 -> type == V_15 )
V_5 -> V_81 = 5 ;
else if ( V_5 -> V_208 == V_195 )
V_5 -> V_81 = 9 ;
else
V_5 -> V_81 = 0 ;
V_5 -> V_242 |= ( 1 << V_5 -> V_81 ) ;
}
V_1 -> V_14 = V_5 ;
V_4 -> V_222 = V_5 -> V_222 ;
V_4 -> type = V_5 -> type ;
V_4 -> V_95 = V_5 -> V_95 ;
V_4 -> V_11 = V_5 -> V_11 ;
V_4 -> V_86 = V_5 -> V_118 [ V_245 ] ;
V_4 -> V_123 = 0 ;
V_4 -> V_246 = F_3 ;
V_4 -> V_247 = F_8 ;
if ( V_5 -> V_182 > 0 && V_5 -> V_183 > 0 )
F_49 ( V_4 -> V_28 , L_44 ,
V_5 -> V_182 , V_5 -> V_183 ) ;
return 0 ;
}
static void F_163 ( struct V_2 * V_4 , int V_248 )
{
F_27 ( V_4 , V_248 ) ;
}
static void F_164 ( struct V_249 * V_250 , const char * V_39 ,
unsigned V_56 )
{
struct V_1 * V_1 = & V_251 [ V_250 -> V_236 ] ;
struct V_2 * V_4 = & V_1 -> V_4 ;
unsigned short V_252 ;
F_13 ( V_1 ) ;
F_165 ( V_4 , V_39 , V_56 , F_163 ) ;
V_252 = F_28 ( V_4 ) | F_30 ( V_4 ) ;
while ( ( F_21 ( V_4 , V_34 ) & V_252 ) != V_252 )
F_166 () ;
F_17 ( V_1 ) ;
}
static int T_6 F_167 ( struct V_249 * V_250 , char * V_253 )
{
struct V_1 * V_1 ;
struct V_2 * V_4 ;
int V_203 = 115200 ;
int V_252 = 8 ;
int V_254 = 'n' ;
int V_255 = 'n' ;
int V_102 ;
if ( V_250 -> V_236 < 0 || V_250 -> V_236 >= V_256 )
return - V_257 ;
V_1 = & V_251 [ V_250 -> V_236 ] ;
V_4 = & V_1 -> V_4 ;
if ( ! V_4 -> V_42 )
return - V_257 ;
V_102 = F_146 ( V_4 ) ;
if ( F_80 ( V_102 != 0 ) )
return V_102 ;
F_13 ( V_1 ) ;
if ( V_253 )
F_168 ( V_253 , & V_203 , & V_254 , & V_252 , & V_255 ) ;
F_17 ( V_1 ) ;
return F_169 ( V_4 , V_250 , V_203 , V_254 , V_252 , V_255 ) ;
}
static int T_6 F_170 ( struct V_235 * V_258 )
{
struct V_13 * V_14 = V_258 -> V_28 . V_259 ;
if ( V_260 . V_80 )
return - V_261 ;
V_260 . V_236 = V_258 -> V_262 ;
F_156 ( NULL , & V_251 [ V_258 -> V_262 ] , V_258 -> V_262 , V_14 ) ;
F_167 ( & V_260 , V_263 ) ;
if ( ! strstr ( V_263 , L_45 ) )
V_260 . V_95 |= V_264 ;
F_171 ( & V_260 ) ;
return 0 ;
}
static int F_172 ( struct V_152 * V_28 )
{
struct V_1 * V_1 = F_173 ( V_28 ) ;
struct V_2 * V_4 = & V_1 -> V_4 ;
if ( F_174 ( V_4 ) ) {
V_1 -> V_265 = F_21 ( V_4 , V_209 ) ;
V_1 -> V_266 = F_21 ( V_4 , V_216 ) ;
V_1 -> V_267 = F_21 ( V_4 , V_197 ) ;
}
return 0 ;
}
static int F_175 ( struct V_152 * V_28 )
{
struct V_1 * V_1 = F_173 ( V_28 ) ;
struct V_2 * V_4 = & V_1 -> V_4 ;
if ( F_174 ( V_4 ) ) {
F_137 ( V_4 ) ;
F_23 ( V_4 , V_209 , V_1 -> V_265 ) ;
F_23 ( V_4 , V_216 , V_1 -> V_266 ) ;
F_23 ( V_4 , V_197 , V_1 -> V_267 ) ;
F_23 ( V_4 , V_57 , V_1 -> V_14 -> V_97 ) ;
}
return 0 ;
}
static inline int T_6 F_170 ( struct V_235 * V_258 )
{
return - V_27 ;
}
static int F_176 ( struct V_235 * V_28 )
{
struct V_1 * V_4 = F_177 ( V_28 ) ;
F_178 ( & V_4 -> V_108 ,
V_268 ) ;
F_179 ( & V_269 , & V_4 -> V_4 ) ;
F_180 ( V_4 -> V_29 ) ;
F_180 ( V_4 -> V_31 ) ;
F_181 ( & V_28 -> V_28 ) ;
return 0 ;
}
static int T_6 F_182 ( struct V_235 * V_28 ,
unsigned int V_236 ,
struct V_13 * V_5 ,
struct V_1 * V_270 )
{
int V_102 ;
if ( F_80 ( V_236 >= V_256 ) ) {
F_51 ( & V_28 -> V_28 , L_46
L_47 ,
V_236 + 1 , V_256 ) ;
F_51 ( & V_28 -> V_28 , L_48
L_49 ) ;
return 0 ;
}
V_102 = F_156 ( V_28 , V_270 , V_236 , V_5 ) ;
if ( V_102 )
return V_102 ;
return F_183 ( & V_269 , & V_270 -> V_4 ) ;
}
static int T_6 F_184 ( struct V_235 * V_28 )
{
struct V_13 * V_5 = V_28 -> V_28 . V_259 ;
struct V_1 * V_271 = & V_251 [ V_28 -> V_262 ] ;
int V_102 ;
if ( F_185 ( V_28 ) )
return F_170 ( V_28 ) ;
F_186 ( V_28 , V_271 ) ;
V_102 = F_182 ( V_28 , V_28 -> V_262 , V_5 , V_271 ) ;
if ( V_102 )
goto V_272;
V_271 -> V_108 . V_273 = F_73 ;
V_102 = F_187 ( & V_271 -> V_108 ,
V_268 ) ;
if ( F_80 ( V_102 < 0 ) )
goto V_272;
#ifdef F_188
F_189 () ;
#endif
return 0 ;
V_272:
F_176 ( V_28 ) ;
return V_102 ;
}
static int F_190 ( struct V_152 * V_28 )
{
struct V_1 * V_229 = F_173 ( V_28 ) ;
if ( V_229 )
F_191 ( & V_269 , & V_229 -> V_4 ) ;
return 0 ;
}
static int F_192 ( struct V_152 * V_28 )
{
struct V_1 * V_229 = F_173 ( V_28 ) ;
if ( V_229 )
F_193 ( & V_269 , & V_229 -> V_4 ) ;
return 0 ;
}
static int T_7 F_194 ( void )
{
int V_102 ;
F_12 ( V_274 ) ;
V_102 = F_195 ( & V_269 ) ;
if ( F_140 ( V_102 == 0 ) ) {
V_102 = F_196 ( & V_275 ) ;
if ( F_80 ( V_102 ) )
F_197 ( & V_269 ) ;
}
return V_102 ;
}
static void T_8 F_198 ( void )
{
F_199 ( & V_275 ) ;
F_197 ( & V_269 ) ;
}
