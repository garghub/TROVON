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
if ( ( V_39 -> V_14 -> V_44 & V_45 ) &&
( ( ! ( V_38 & V_46 ) ) ) ) {
unsigned short V_32 ;
V_32 = F_21 ( V_4 , V_41 ) ;
V_32 &= ~ V_47 ;
V_32 |= V_48 ;
F_23 ( V_4 , V_41 , V_32 ) ;
}
}
static int F_32 ( struct V_2 * V_4 )
{
struct V_7 * V_8 ;
V_8 = F_4 ( V_4 , V_49 ) ;
if ( V_8 -> V_9 )
return F_21 ( V_4 , V_49 ) & ( ( V_4 -> V_50 << 1 ) - 1 ) ;
V_8 = F_4 ( V_4 , V_51 ) ;
if ( V_8 -> V_9 )
return F_21 ( V_4 , V_51 ) >> 8 ;
return ! ( F_21 ( V_4 , V_34 ) & V_52 ) ;
}
static int F_33 ( struct V_2 * V_4 )
{
return V_4 -> V_50 - F_32 ( V_4 ) ;
}
static int F_34 ( struct V_2 * V_4 )
{
struct V_7 * V_8 ;
V_8 = F_4 ( V_4 , V_53 ) ;
if ( V_8 -> V_9 )
return F_21 ( V_4 , V_53 ) & ( ( V_4 -> V_50 << 1 ) - 1 ) ;
V_8 = F_4 ( V_4 , V_51 ) ;
if ( V_8 -> V_9 )
return F_21 ( V_4 , V_51 ) & ( ( V_4 -> V_50 << 1 ) - 1 ) ;
return ( F_21 ( V_4 , V_34 ) & F_25 ( V_4 ) ) != 0 ;
}
static inline int F_35 ( struct V_2 * V_4 )
{
struct V_1 * V_39 = F_1 ( V_4 ) ;
if ( V_39 -> V_14 -> V_54 <= 0 )
return 1 ;
return ! ! F_36 ( ( void V_55 * ) V_39 -> V_14 -> V_54 ) ;
}
static void F_37 ( struct V_2 * V_4 )
{
struct V_56 * V_57 = & V_4 -> V_58 -> V_57 ;
unsigned int V_59 = F_38 ( V_4 ) ;
unsigned short V_32 ;
unsigned short V_60 ;
int V_61 ;
V_32 = F_21 ( V_4 , V_34 ) ;
if ( ! ( V_32 & F_28 ( V_4 ) ) ) {
V_60 = F_21 ( V_4 , V_62 ) ;
if ( F_39 ( V_57 ) )
V_60 &= ~ V_63 ;
else
V_60 |= V_63 ;
F_23 ( V_4 , V_62 , V_60 ) ;
return;
}
V_61 = F_33 ( V_4 ) ;
do {
unsigned char V_33 ;
if ( V_4 -> V_64 ) {
V_33 = V_4 -> V_64 ;
V_4 -> V_64 = 0 ;
} else if ( ! F_39 ( V_57 ) && ! V_59 ) {
V_33 = V_57 -> V_65 [ V_57 -> V_66 ] ;
V_57 -> V_66 = ( V_57 -> V_66 + 1 ) & ( V_67 - 1 ) ;
} else {
break;
}
F_23 ( V_4 , V_37 , V_33 ) ;
V_4 -> V_68 . V_69 ++ ;
} while ( -- V_61 > 0 );
F_23 ( V_4 , V_34 , F_29 ( V_4 ) ) ;
if ( F_40 ( V_57 ) < V_70 )
F_41 ( V_4 ) ;
if ( F_39 ( V_57 ) ) {
F_42 ( V_4 ) ;
} else {
V_60 = F_21 ( V_4 , V_62 ) ;
if ( V_4 -> type != V_15 ) {
F_21 ( V_4 , V_34 ) ;
F_23 ( V_4 , V_34 , F_29 ( V_4 ) ) ;
}
V_60 |= V_63 ;
F_23 ( V_4 , V_62 , V_60 ) ;
}
}
static void F_43 ( struct V_2 * V_4 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_71 * V_72 = & V_4 -> V_58 -> V_4 ;
int V_73 , V_61 , V_74 = 0 ;
unsigned short V_32 ;
unsigned char V_75 ;
V_32 = F_21 ( V_4 , V_34 ) ;
if ( ! ( V_32 & F_25 ( V_4 ) ) )
return;
while ( 1 ) {
V_61 = F_44 ( V_72 , F_34 ( V_4 ) ) ;
if ( V_61 == 0 )
break;
if ( V_4 -> type == V_15 ) {
char V_33 = F_21 ( V_4 , V_36 ) ;
if ( F_45 ( V_4 , V_33 ) ||
V_1 -> V_76 )
V_61 = 0 ;
else
F_46 ( V_72 , V_33 , V_77 ) ;
} else {
for ( V_73 = 0 ; V_73 < V_61 ; V_73 ++ ) {
char V_33 = F_21 ( V_4 , V_36 ) ;
V_32 = F_21 ( V_4 , V_34 ) ;
#if F_47 ( V_78 )
if ( V_1 -> V_76 ) {
if ( ( V_33 == 0 ) &&
( V_32 & F_48 ( V_4 ) ) ) {
V_61 -- ; V_73 -- ;
continue;
}
F_49 ( V_4 -> V_28 , L_3 , V_33 ) ;
V_1 -> V_76 = 0 ;
if ( F_50 ( V_33 ) ) {
V_61 -- ; V_73 -- ;
continue;
}
}
#endif
if ( F_45 ( V_4 , V_33 ) ) {
V_61 -- ; V_73 -- ;
continue;
}
if ( V_32 & F_48 ( V_4 ) ) {
V_75 = V_79 ;
V_4 -> V_68 . V_80 ++ ;
F_51 ( V_4 -> V_28 , L_4 ) ;
} else if ( V_32 & F_52 ( V_4 ) ) {
V_75 = V_81 ;
V_4 -> V_68 . V_82 ++ ;
F_51 ( V_4 -> V_28 , L_5 ) ;
} else
V_75 = V_77 ;
F_46 ( V_72 , V_33 , V_75 ) ;
}
}
F_21 ( V_4 , V_34 ) ;
F_23 ( V_4 , V_34 , F_26 ( V_4 ) ) ;
V_74 += V_61 ;
V_4 -> V_68 . V_83 += V_61 ;
}
if ( V_74 ) {
F_53 ( V_72 ) ;
} else {
F_21 ( V_4 , V_34 ) ;
F_23 ( V_4 , V_34 , F_26 ( V_4 ) ) ;
}
}
static inline void F_54 ( struct V_1 * V_4 )
{
F_55 ( & V_4 -> V_84 , V_85 + V_86 ) ;
}
static void F_56 ( unsigned long V_87 )
{
struct V_1 * V_4 = (struct V_1 * ) V_87 ;
F_13 ( V_4 ) ;
if ( F_35 ( & V_4 -> V_4 ) == 0 ) {
V_4 -> V_76 = 1 ;
F_54 ( V_4 ) ;
} else if ( V_4 -> V_76 == 1 ) {
V_4 -> V_76 = 2 ;
F_54 ( V_4 ) ;
} else
V_4 -> V_76 = 0 ;
F_17 ( V_4 ) ;
}
static int F_57 ( struct V_2 * V_4 )
{
int V_74 = 0 ;
unsigned short V_32 = F_21 ( V_4 , V_34 ) ;
struct V_71 * V_72 = & V_4 -> V_58 -> V_4 ;
struct V_1 * V_39 = F_1 ( V_4 ) ;
if ( V_39 -> V_14 -> V_88 != V_89 ) {
if ( V_32 & ( 1 << V_39 -> V_14 -> V_88 ) ) {
V_4 -> V_68 . V_90 ++ ;
if ( F_46 ( V_72 , 0 , V_91 ) )
V_74 ++ ;
F_51 ( V_4 -> V_28 , L_6 ) ;
}
}
if ( V_32 & F_48 ( V_4 ) ) {
if ( F_35 ( V_4 ) == 0 ) {
struct V_1 * V_1 = F_1 ( V_4 ) ;
if ( ! V_1 -> V_76 ) {
V_4 -> V_68 . V_92 ++ ;
V_1 -> V_76 = 1 ;
F_54 ( V_1 ) ;
if ( F_58 ( V_4 ) )
return 0 ;
F_49 ( V_4 -> V_28 , L_7 ) ;
if ( F_46 ( V_72 , 0 , V_93 ) )
V_74 ++ ;
}
} else {
V_4 -> V_68 . V_80 ++ ;
if ( F_46 ( V_72 , 0 , V_79 ) )
V_74 ++ ;
F_51 ( V_4 -> V_28 , L_4 ) ;
}
}
if ( V_32 & F_52 ( V_4 ) ) {
V_4 -> V_68 . V_82 ++ ;
if ( F_46 ( V_72 , 0 , V_81 ) )
V_74 ++ ;
F_51 ( V_4 -> V_28 , L_8 ) ;
}
if ( V_74 )
F_53 ( V_72 ) ;
return V_74 ;
}
static int F_59 ( struct V_2 * V_4 )
{
struct V_71 * V_72 = & V_4 -> V_58 -> V_4 ;
struct V_1 * V_39 = F_1 ( V_4 ) ;
struct V_7 * V_8 ;
int V_74 = 0 ;
V_8 = F_4 ( V_4 , V_94 ) ;
if ( ! V_8 -> V_9 )
return 0 ;
if ( ( F_21 ( V_4 , V_94 ) & ( 1 << V_39 -> V_14 -> V_88 ) ) ) {
F_23 ( V_4 , V_94 , 0 ) ;
V_4 -> V_68 . V_90 ++ ;
F_46 ( V_72 , 0 , V_91 ) ;
F_53 ( V_72 ) ;
F_51 ( V_4 -> V_28 , L_9 ) ;
V_74 ++ ;
}
return V_74 ;
}
static int F_60 ( struct V_2 * V_4 )
{
int V_74 = 0 ;
unsigned short V_32 = F_21 ( V_4 , V_34 ) ;
struct V_71 * V_72 = & V_4 -> V_58 -> V_4 ;
struct V_1 * V_39 = F_1 ( V_4 ) ;
if ( F_58 ( V_4 ) )
return 0 ;
if ( ! V_39 -> V_76 && V_32 & F_61 ( V_4 ) ) {
#if F_47 ( V_78 )
V_39 -> V_76 = 1 ;
#endif
V_4 -> V_68 . V_92 ++ ;
if ( F_46 ( V_72 , 0 , V_93 ) )
V_74 ++ ;
F_49 ( V_4 -> V_28 , L_7 ) ;
}
if ( V_74 )
F_53 ( V_72 ) ;
V_74 += F_59 ( V_4 ) ;
return V_74 ;
}
static T_1 F_62 ( int V_95 , void * V_96 )
{
#ifdef F_63
struct V_2 * V_4 = V_96 ;
struct V_1 * V_39 = F_1 ( V_4 ) ;
if ( V_39 -> V_97 ) {
T_2 V_98 = F_21 ( V_4 , V_62 ) ;
T_2 V_99 = F_21 ( V_4 , V_34 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
F_64 ( V_95 ) ;
V_98 |= 0x4000 ;
} else {
V_98 &= ~ V_100 ;
}
F_23 ( V_4 , V_62 , V_98 ) ;
F_23 ( V_4 , V_34 , V_99 & ~ ( 1 | F_25 ( V_4 ) ) ) ;
F_49 ( V_4 -> V_28 , L_10 ,
V_85 , V_39 -> V_101 ) ;
F_55 ( & V_39 -> V_102 , V_85 + V_39 -> V_101 ) ;
return V_103 ;
}
#endif
F_43 ( V_96 ) ;
return V_103 ;
}
static T_1 F_65 ( int V_95 , void * V_96 )
{
struct V_2 * V_4 = V_96 ;
unsigned long V_104 ;
F_66 ( & V_4 -> V_105 , V_104 ) ;
F_37 ( V_4 ) ;
F_67 ( & V_4 -> V_105 , V_104 ) ;
return V_103 ;
}
static T_1 F_68 ( int V_95 , void * V_96 )
{
struct V_2 * V_4 = V_96 ;
if ( V_4 -> type == V_15 ) {
if ( F_57 ( V_4 ) ) {
F_21 ( V_4 , V_34 ) ;
F_23 ( V_4 , V_34 , F_26 ( V_4 ) ) ;
}
} else {
F_59 ( V_4 ) ;
F_62 ( V_95 , V_96 ) ;
}
F_23 ( V_4 , V_34 , F_24 ( V_4 ) ) ;
F_65 ( V_95 , V_96 ) ;
return V_103 ;
}
static T_1 F_69 ( int V_95 , void * V_96 )
{
struct V_2 * V_4 = V_96 ;
F_60 ( V_4 ) ;
F_23 ( V_4 , V_34 , F_70 ( V_4 ) ) ;
return V_103 ;
}
static inline unsigned long F_71 ( struct V_2 * V_4 )
{
return V_100 | ( F_1 ( V_4 ) -> V_14 -> V_106 & V_107 ) ;
}
static T_1 F_72 ( int V_95 , void * V_96 )
{
unsigned short V_108 , V_109 , V_110 ;
struct V_2 * V_4 = V_96 ;
struct V_1 * V_39 = F_1 ( V_4 ) ;
T_1 V_111 = V_112 ;
V_108 = F_21 ( V_4 , V_34 ) ;
V_109 = F_21 ( V_4 , V_62 ) ;
V_110 = V_109 & F_71 ( V_4 ) ;
if ( ( V_108 & F_28 ( V_4 ) ) && ( V_109 & V_63 ) &&
! V_39 -> V_113 )
V_111 = F_65 ( V_95 , V_96 ) ;
if ( ( ( V_108 & F_25 ( V_4 ) ) || V_39 -> V_97 ) &&
( V_109 & V_100 ) )
V_111 = F_62 ( V_95 , V_96 ) ;
if ( ( V_108 & F_22 ( V_4 ) ) && V_110 )
V_111 = F_68 ( V_95 , V_96 ) ;
if ( ( V_108 & F_61 ( V_4 ) ) && V_110 )
V_111 = F_69 ( V_95 , V_96 ) ;
return V_111 ;
}
static int F_73 ( struct V_114 * V_115 ,
unsigned long V_116 , void * V_5 )
{
struct V_1 * V_1 ;
unsigned long V_104 ;
V_1 = F_2 ( V_115 , struct V_1 , V_117 ) ;
if ( ( V_116 == V_118 ) ||
( V_116 == V_119 ) ) {
struct V_2 * V_4 = & V_1 -> V_4 ;
F_66 ( & V_4 -> V_105 , V_104 ) ;
V_4 -> V_30 = F_16 ( V_1 -> V_29 ) ;
F_67 ( & V_4 -> V_105 , V_104 ) ;
}
return V_120 ;
}
static int F_74 ( struct V_1 * V_4 )
{
struct V_2 * V_121 = & V_4 -> V_4 ;
int V_73 , V_122 , V_111 = 0 ;
for ( V_73 = V_122 = 0 ; V_73 < V_123 ; V_73 ++ , V_122 ++ ) {
struct V_124 * V_125 ;
unsigned int V_95 ;
if ( F_75 ( V_4 ) ) {
V_73 = V_126 ;
V_95 = V_121 -> V_95 ;
} else {
V_95 = V_4 -> V_14 -> V_127 [ V_73 ] ;
if ( F_76 ( ! V_95 ) )
continue;
}
V_125 = V_124 + V_73 ;
V_4 -> V_128 [ V_122 ] = F_77 ( V_129 , L_11 ,
F_78 ( V_121 -> V_28 ) , V_125 -> V_125 ) ;
if ( ! V_4 -> V_128 [ V_122 ] ) {
F_79 ( V_121 -> V_28 , L_12 ,
V_125 -> V_125 ) ;
goto V_130;
}
V_111 = F_80 ( V_95 , V_125 -> V_131 , V_121 -> V_132 ,
V_4 -> V_128 [ V_122 ] , V_4 ) ;
if ( F_76 ( V_111 ) ) {
F_79 ( V_121 -> V_28 , L_13 , V_125 -> V_125 ) ;
goto V_133;
}
}
return 0 ;
V_133:
while ( -- V_73 >= 0 )
F_81 ( V_4 -> V_14 -> V_127 [ V_73 ] , V_4 ) ;
V_130:
while ( -- V_122 >= 0 )
F_82 ( V_4 -> V_128 [ V_122 ] ) ;
return V_111 ;
}
static void F_83 ( struct V_1 * V_4 )
{
int V_73 ;
for ( V_73 = 0 ; V_73 < V_123 ; V_73 ++ ) {
unsigned int V_95 = V_4 -> V_14 -> V_127 [ V_73 ] ;
if ( F_76 ( ! V_95 ) )
continue;
F_81 ( V_4 -> V_14 -> V_127 [ V_73 ] , V_4 ) ;
F_82 ( V_4 -> V_128 [ V_73 ] ) ;
if ( F_75 ( V_4 ) ) {
return;
}
}
}
static const char * F_84 ( unsigned int V_134 )
{
return V_135 [ V_134 ] ;
}
static void F_85 ( struct V_1 * V_4 )
{
struct V_2 * V_121 = & V_4 -> V_4 ;
int V_73 ;
if ( ! V_4 -> V_14 )
return;
for ( V_73 = 0 ; V_73 < V_136 ; V_73 ++ ) {
const char * V_125 ;
int V_111 ;
if ( ! V_4 -> V_14 -> V_137 [ V_73 ] )
continue;
V_125 = F_84 ( V_73 ) ;
V_4 -> V_138 [ V_73 ] = F_77 ( V_129 , L_11 ,
F_78 ( V_121 -> V_28 ) , V_125 ) ;
if ( ! V_4 -> V_138 [ V_73 ] )
F_51 ( V_121 -> V_28 , L_14 ,
V_125 ) ;
V_111 = F_86 ( V_4 -> V_14 -> V_137 [ V_73 ] , V_4 -> V_138 [ V_73 ] ) ;
if ( F_76 ( V_111 != 0 ) ) {
F_51 ( V_121 -> V_28 , L_15 , V_125 ) ;
F_82 ( V_4 -> V_138 [ V_73 ] ) ;
}
}
}
static void F_87 ( struct V_1 * V_4 )
{
int V_73 ;
for ( V_73 = 0 ; V_73 < V_136 ; V_73 ++ )
if ( V_4 -> V_14 -> V_137 [ V_73 ] ) {
F_88 ( V_4 -> V_14 -> V_137 [ V_73 ] ) ;
F_82 ( V_4 -> V_138 [ V_73 ] ) ;
}
}
static unsigned int F_89 ( struct V_2 * V_4 )
{
unsigned short V_32 = F_21 ( V_4 , V_34 ) ;
unsigned short V_139 = F_32 ( V_4 ) ;
return ( V_32 & F_30 ( V_4 ) ) && ! V_139 ? V_140 : 0 ;
}
static void F_90 ( struct V_2 * V_4 , unsigned int V_141 )
{
if ( V_141 & V_142 ) {
struct V_7 * V_8 ;
V_8 = F_4 ( V_4 , V_143 ) ;
if ( V_8 -> V_9 )
F_23 ( V_4 , V_143 , F_21 ( V_4 , V_143 ) | 1 ) ;
}
}
static unsigned int F_91 ( struct V_2 * V_4 )
{
return V_144 | V_145 ;
}
static void F_92 ( void * V_146 )
{
struct V_1 * V_39 = V_146 ;
struct V_2 * V_4 = & V_39 -> V_4 ;
struct V_56 * V_57 = & V_4 -> V_58 -> V_57 ;
unsigned long V_104 ;
F_49 ( V_4 -> V_28 , L_16 , V_147 , V_4 -> line ) ;
F_66 ( & V_4 -> V_105 , V_104 ) ;
V_57 -> V_66 += F_93 ( & V_39 -> V_148 ) ;
V_57 -> V_66 &= V_67 - 1 ;
V_4 -> V_68 . V_69 += F_93 ( & V_39 -> V_148 ) ;
F_94 ( V_39 -> V_149 ) ;
V_39 -> V_149 = NULL ;
if ( F_40 ( V_57 ) < V_70 )
F_41 ( V_4 ) ;
if ( ! F_39 ( V_57 ) ) {
V_39 -> V_150 = 0 ;
F_95 ( & V_39 -> V_151 ) ;
} else {
V_39 -> V_150 = - V_27 ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
T_2 V_60 = F_21 ( V_4 , V_62 ) ;
F_23 ( V_4 , V_62 , V_60 & ~ V_63 ) ;
}
}
F_67 ( & V_4 -> V_105 , V_104 ) ;
}
static int F_96 ( struct V_1 * V_39 , T_3 V_61 )
{
struct V_2 * V_4 = & V_39 -> V_4 ;
struct V_71 * V_72 = & V_4 -> V_58 -> V_4 ;
int V_73 , V_152 , V_153 ;
V_153 = F_44 ( V_72 , V_61 ) ;
if ( V_39 -> V_154 == V_39 -> V_155 [ 0 ] ) {
V_152 = 0 ;
} else if ( V_39 -> V_154 == V_39 -> V_155 [ 1 ] ) {
V_152 = 1 ;
} else {
F_79 ( V_4 -> V_28 , L_17 , V_39 -> V_154 ) ;
return 0 ;
}
if ( V_153 < V_61 )
F_97 ( V_4 -> V_28 , L_18 ,
V_61 - V_153 ) ;
if ( ! V_153 )
return V_153 ;
for ( V_73 = 0 ; V_73 < V_153 ; V_73 ++ )
F_46 ( V_72 , ( ( V_156 * ) F_98 ( & V_39 -> V_157 [ V_152 ] ) ) [ V_73 ] ,
V_77 ) ;
V_4 -> V_68 . V_83 += V_153 ;
return V_153 ;
}
static void F_99 ( void * V_146 )
{
struct V_1 * V_39 = V_146 ;
struct V_2 * V_4 = & V_39 -> V_4 ;
unsigned long V_104 ;
int V_61 ;
F_49 ( V_4 -> V_28 , L_19 , V_147 , V_4 -> line , V_39 -> V_154 ) ;
F_66 ( & V_4 -> V_105 , V_104 ) ;
V_61 = F_96 ( V_39 , V_39 -> V_158 ) ;
F_55 ( & V_39 -> V_102 , V_85 + V_39 -> V_101 ) ;
F_67 ( & V_4 -> V_105 , V_104 ) ;
if ( V_61 )
F_53 ( & V_4 -> V_58 -> V_4 ) ;
F_95 ( & V_39 -> V_159 ) ;
}
static void F_100 ( struct V_1 * V_39 , bool V_160 )
{
struct V_161 * V_162 = V_39 -> V_97 ;
struct V_2 * V_4 = & V_39 -> V_4 ;
V_39 -> V_97 = NULL ;
V_39 -> V_155 [ 0 ] = V_39 -> V_155 [ 1 ] = - V_27 ;
F_101 ( V_162 ) ;
if ( F_102 ( & V_39 -> V_157 [ 0 ] ) )
F_103 ( V_4 -> V_28 , V_39 -> V_158 * 2 ,
F_98 ( & V_39 -> V_157 [ 0 ] ) , F_102 ( & V_39 -> V_157 [ 0 ] ) ) ;
if ( V_160 )
F_104 ( V_4 ) ;
}
static void F_105 ( struct V_1 * V_39 , bool V_160 )
{
struct V_161 * V_162 = V_39 -> V_113 ;
struct V_2 * V_4 = & V_39 -> V_4 ;
V_39 -> V_113 = NULL ;
V_39 -> V_150 = - V_27 ;
F_101 ( V_162 ) ;
if ( V_160 )
F_106 ( V_4 ) ;
}
static void F_107 ( struct V_1 * V_39 )
{
struct V_161 * V_162 = V_39 -> V_97 ;
int V_73 ;
for ( V_73 = 0 ; V_73 < 2 ; V_73 ++ ) {
struct V_163 * V_164 = & V_39 -> V_157 [ V_73 ] ;
struct V_165 * V_125 ;
V_125 = F_108 ( V_162 ,
V_164 , 1 , V_166 , V_167 ) ;
if ( V_125 ) {
V_39 -> V_168 [ V_73 ] = V_125 ;
V_125 -> V_169 = F_99 ;
V_125 -> V_170 = V_39 ;
V_39 -> V_155 [ V_73 ] = V_125 -> V_171 ( V_125 ) ;
}
if ( ! V_125 || V_39 -> V_155 [ V_73 ] < 0 ) {
if ( V_73 ) {
F_94 ( V_39 -> V_168 [ 0 ] ) ;
V_39 -> V_155 [ 0 ] = - V_27 ;
}
if ( V_125 ) {
F_94 ( V_125 ) ;
V_39 -> V_155 [ V_73 ] = - V_27 ;
}
F_97 ( V_39 -> V_4 . V_28 ,
L_20 ) ;
F_100 ( V_39 , true ) ;
return;
}
F_49 ( V_39 -> V_4 . V_28 , L_21 , V_147 ,
V_39 -> V_155 [ V_73 ] , V_73 ) ;
}
V_39 -> V_154 = V_39 -> V_155 [ 0 ] ;
F_109 ( V_162 ) ;
}
static void F_110 ( struct V_172 * V_173 )
{
struct V_1 * V_39 = F_2 ( V_173 , struct V_1 , V_159 ) ;
struct V_2 * V_4 = & V_39 -> V_4 ;
struct V_165 * V_125 ;
int V_174 ;
if ( V_39 -> V_154 == V_39 -> V_155 [ 0 ] ) {
V_174 = 0 ;
} else if ( V_39 -> V_154 == V_39 -> V_155 [ 1 ] ) {
V_174 = 1 ;
} else {
F_79 ( V_4 -> V_28 , L_17 , V_39 -> V_154 ) ;
return;
}
V_125 = V_39 -> V_168 [ V_174 ] ;
if ( F_111 ( V_39 -> V_97 , V_39 -> V_154 , NULL , NULL ) !=
V_175 ) {
struct V_161 * V_162 = V_39 -> V_97 ;
struct V_176 * V_177 = F_2 ( V_125 ,
struct V_176 , V_178 ) ;
unsigned long V_104 ;
int V_61 ;
V_162 -> V_179 -> V_180 ( V_162 , V_181 , 0 ) ;
F_49 ( V_4 -> V_28 , L_22 ,
V_177 -> V_182 , V_177 -> V_183 ) ;
F_66 ( & V_4 -> V_105 , V_104 ) ;
V_61 = F_96 ( V_39 , V_177 -> V_182 ) ;
F_67 ( & V_4 -> V_105 , V_104 ) ;
if ( V_61 )
F_53 ( & V_4 -> V_58 -> V_4 ) ;
F_107 ( V_39 ) ;
return;
}
V_39 -> V_155 [ V_174 ] = V_125 -> V_171 ( V_125 ) ;
if ( V_39 -> V_155 [ V_174 ] < 0 ) {
F_97 ( V_4 -> V_28 , L_23 ) ;
F_100 ( V_39 , true ) ;
return;
}
V_39 -> V_154 = V_39 -> V_155 [ ! V_174 ] ;
F_49 ( V_4 -> V_28 , L_24 , V_147 ,
V_39 -> V_155 [ V_174 ] , V_174 , V_39 -> V_154 ) ;
}
static void F_112 ( struct V_172 * V_173 )
{
struct V_1 * V_39 = F_2 ( V_173 , struct V_1 , V_151 ) ;
struct V_165 * V_125 ;
struct V_161 * V_162 = V_39 -> V_113 ;
struct V_2 * V_4 = & V_39 -> V_4 ;
struct V_56 * V_57 = & V_4 -> V_58 -> V_57 ;
struct V_163 * V_164 = & V_39 -> V_148 ;
F_113 ( & V_4 -> V_105 ) ;
V_164 -> V_6 = V_57 -> V_66 & ( V_67 - 1 ) ;
F_102 ( V_164 ) = ( F_102 ( V_164 ) & ~ ( V_67 - 1 ) ) +
V_164 -> V_6 ;
F_93 ( V_164 ) = F_114 ( ( int ) F_115 ( V_57 -> V_184 , V_57 -> V_66 , V_67 ) ,
F_116 ( V_57 -> V_184 , V_57 -> V_66 , V_67 ) ) ;
F_117 ( & V_4 -> V_105 ) ;
F_118 ( ! F_93 ( V_164 ) ) ;
V_125 = F_108 ( V_162 ,
V_164 , V_39 -> V_185 , V_186 ,
V_167 | V_187 ) ;
if ( ! V_125 ) {
F_105 ( V_39 , true ) ;
return;
}
F_119 ( V_4 -> V_28 , V_164 , 1 , V_188 ) ;
F_113 ( & V_4 -> V_105 ) ;
V_39 -> V_149 = V_125 ;
V_125 -> V_169 = F_92 ;
V_125 -> V_170 = V_39 ;
F_117 ( & V_4 -> V_105 ) ;
V_39 -> V_150 = V_125 -> V_171 ( V_125 ) ;
if ( V_39 -> V_150 < 0 ) {
F_97 ( V_4 -> V_28 , L_25 ) ;
F_105 ( V_39 , true ) ;
return;
}
F_49 ( V_4 -> V_28 , L_26 , V_147 ,
V_57 -> V_65 , V_57 -> V_66 , V_57 -> V_184 , V_39 -> V_150 ) ;
F_109 ( V_162 ) ;
}
static void F_106 ( struct V_2 * V_4 )
{
struct V_1 * V_39 = F_1 ( V_4 ) ;
unsigned short V_60 ;
#ifdef F_63
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
T_2 V_174 , V_98 = F_21 ( V_4 , V_62 ) ;
if ( V_39 -> V_113 )
V_174 = V_98 | 0x8000 ;
else
V_174 = V_98 & ~ 0x8000 ;
if ( V_174 != V_98 )
F_23 ( V_4 , V_62 , V_174 ) ;
}
if ( V_39 -> V_113 && ! F_39 ( & V_39 -> V_4 . V_58 -> V_57 ) &&
V_39 -> V_150 < 0 ) {
V_39 -> V_150 = 0 ;
F_95 ( & V_39 -> V_151 ) ;
}
#endif
if ( ! V_39 -> V_113 || V_4 -> type == V_20 || V_4 -> type == V_22 ) {
V_60 = F_21 ( V_4 , V_62 ) ;
F_23 ( V_4 , V_62 , V_60 | V_63 ) ;
}
}
static void F_42 ( struct V_2 * V_4 )
{
unsigned short V_60 ;
V_60 = F_21 ( V_4 , V_62 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 )
V_60 &= ~ 0x8000 ;
V_60 &= ~ V_63 ;
F_23 ( V_4 , V_62 , V_60 ) ;
}
static void F_104 ( struct V_2 * V_4 )
{
unsigned short V_60 ;
V_60 = F_21 ( V_4 , V_62 ) | F_71 ( V_4 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 )
V_60 &= ~ 0x4000 ;
F_23 ( V_4 , V_62 , V_60 ) ;
}
static void F_120 ( struct V_2 * V_4 )
{
unsigned short V_60 ;
V_60 = F_21 ( V_4 , V_62 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 )
V_60 &= ~ 0x4000 ;
V_60 &= ~ F_71 ( V_4 ) ;
F_23 ( V_4 , V_62 , V_60 ) ;
}
static void F_121 ( struct V_2 * V_4 )
{
}
static void F_122 ( struct V_2 * V_4 , int V_189 )
{
struct V_1 * V_39 = F_1 ( V_4 ) ;
struct V_7 * V_8 = V_40 [ V_39 -> V_14 -> V_16 ] + V_41 ;
unsigned short V_106 , V_190 ;
if ( ! V_8 -> V_9 ) {
return;
}
V_190 = F_21 ( V_4 , V_41 ) ;
V_106 = F_21 ( V_4 , V_62 ) ;
if ( V_189 == - 1 ) {
V_190 = ( V_190 | V_191 ) & ~ V_192 ;
V_106 &= ~ V_193 ;
} else {
V_190 = ( V_190 | V_192 ) & ~ V_191 ;
V_106 |= V_193 ;
}
F_23 ( V_4 , V_41 , V_190 ) ;
F_23 ( V_4 , V_62 , V_106 ) ;
}
static bool F_123 ( struct V_161 * V_162 , void * V_194 )
{
struct V_195 * V_196 = V_194 ;
F_49 ( V_162 -> V_179 -> V_28 , L_27 , V_147 ,
V_196 -> V_197 . V_198 ) ;
V_162 -> V_199 = & V_196 -> V_197 ;
return true ;
}
static void F_124 ( unsigned long V_146 )
{
struct V_1 * V_39 = (struct V_1 * ) V_146 ;
struct V_2 * V_4 = & V_39 -> V_4 ;
T_2 V_98 = F_21 ( V_4 , V_62 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
V_98 &= ~ 0x4000 ;
F_125 ( V_39 -> V_14 -> V_127 [ 1 ] ) ;
}
F_23 ( V_4 , V_62 , V_98 | V_100 ) ;
F_49 ( V_4 -> V_28 , L_28 ) ;
F_95 ( & V_39 -> V_159 ) ;
}
static void F_126 ( struct V_2 * V_4 )
{
struct V_1 * V_39 = F_1 ( V_4 ) ;
struct V_195 * V_196 ;
struct V_161 * V_162 ;
T_4 V_200 ;
int V_201 ;
F_49 ( V_4 -> V_28 , L_29 , V_147 ,
V_4 -> line ) ;
if ( V_39 -> V_14 -> V_202 <= 0 || V_39 -> V_14 -> V_203 <= 0 )
return;
F_127 ( V_200 ) ;
F_128 ( V_204 , V_200 ) ;
V_196 = & V_39 -> V_205 ;
V_196 -> V_197 . V_198 = V_39 -> V_14 -> V_202 ;
V_39 -> V_150 = - V_27 ;
V_162 = F_129 ( V_200 , F_123 , V_196 ) ;
F_49 ( V_4 -> V_28 , L_30 , V_147 , V_162 ) ;
if ( V_162 ) {
V_39 -> V_113 = V_162 ;
F_130 ( & V_39 -> V_148 , 1 ) ;
F_118 ( ( int ) V_4 -> V_58 -> V_57 . V_65 & ~ V_206 ) ;
F_131 ( & V_39 -> V_148 , F_132 ( V_4 -> V_58 -> V_57 . V_65 ) ,
V_67 , ( int ) V_4 -> V_58 -> V_57 . V_65 & ~ V_206 ) ;
V_201 = F_133 ( V_4 -> V_28 , & V_39 -> V_148 , 1 , V_188 ) ;
if ( ! V_201 )
F_105 ( V_39 , false ) ;
else
F_49 ( V_4 -> V_28 , L_31 , V_147 ,
F_93 ( & V_39 -> V_148 ) ,
V_4 -> V_58 -> V_57 . V_65 , F_102 ( & V_39 -> V_148 ) ) ;
V_39 -> V_185 = V_201 ;
F_134 ( & V_39 -> V_151 , F_112 ) ;
}
V_196 = & V_39 -> V_207 ;
V_196 -> V_197 . V_198 = V_39 -> V_14 -> V_203 ;
V_162 = F_129 ( V_200 , F_123 , V_196 ) ;
F_49 ( V_4 -> V_28 , L_32 , V_147 , V_162 ) ;
if ( V_162 ) {
T_5 V_208 [ 2 ] ;
void * V_65 [ 2 ] ;
int V_73 ;
V_39 -> V_97 = V_162 ;
V_39 -> V_158 = 2 * F_135 ( 16 , ( int ) V_4 -> V_50 ) ;
V_65 [ 0 ] = F_136 ( V_4 -> V_28 , V_39 -> V_158 * 2 ,
& V_208 [ 0 ] , V_129 ) ;
if ( ! V_65 [ 0 ] ) {
F_97 ( V_4 -> V_28 ,
L_33 ) ;
F_100 ( V_39 , true ) ;
return;
}
V_65 [ 1 ] = V_65 [ 0 ] + V_39 -> V_158 ;
V_208 [ 1 ] = V_208 [ 0 ] + V_39 -> V_158 ;
for ( V_73 = 0 ; V_73 < 2 ; V_73 ++ ) {
struct V_163 * V_164 = & V_39 -> V_157 [ V_73 ] ;
F_130 ( V_164 , 1 ) ;
F_131 ( V_164 , F_132 ( V_65 [ V_73 ] ) , V_39 -> V_158 ,
( int ) V_65 [ V_73 ] & ~ V_206 ) ;
F_102 ( V_164 ) = V_208 [ V_73 ] ;
}
F_134 ( & V_39 -> V_159 , F_110 ) ;
F_137 ( & V_39 -> V_102 , F_124 , ( unsigned long ) V_39 ) ;
F_107 ( V_39 ) ;
}
}
static void F_138 ( struct V_2 * V_4 )
{
struct V_1 * V_39 = F_1 ( V_4 ) ;
if ( V_39 -> V_113 )
F_105 ( V_39 , false ) ;
if ( V_39 -> V_97 )
F_100 ( V_39 , false ) ;
}
static inline void F_126 ( struct V_2 * V_4 )
{
}
static inline void F_138 ( struct V_2 * V_4 )
{
}
static int F_139 ( struct V_2 * V_4 )
{
struct V_1 * V_39 = F_1 ( V_4 ) ;
unsigned long V_104 ;
int V_111 ;
F_49 ( V_4 -> V_28 , L_16 , V_147 , V_4 -> line ) ;
V_111 = F_74 ( V_39 ) ;
if ( F_76 ( V_111 < 0 ) )
return V_111 ;
F_126 ( V_4 ) ;
F_66 ( & V_4 -> V_105 , V_104 ) ;
F_106 ( V_4 ) ;
F_104 ( V_4 ) ;
F_67 ( & V_4 -> V_105 , V_104 ) ;
return 0 ;
}
static void F_140 ( struct V_2 * V_4 )
{
struct V_1 * V_39 = F_1 ( V_4 ) ;
unsigned long V_104 ;
F_49 ( V_4 -> V_28 , L_16 , V_147 , V_4 -> line ) ;
F_66 ( & V_4 -> V_105 , V_104 ) ;
F_120 ( V_4 ) ;
F_42 ( V_4 ) ;
F_67 ( & V_4 -> V_105 , V_104 ) ;
F_138 ( V_4 ) ;
F_83 ( V_39 ) ;
}
static unsigned int F_141 ( unsigned int V_209 , unsigned int V_210 ,
unsigned long V_211 )
{
switch ( V_209 ) {
case V_212 :
return ( ( V_211 + 16 * V_210 ) / ( 16 * V_210 ) - 1 ) ;
case V_213 :
return ( ( V_211 + 16 * V_210 ) / ( 32 * V_210 ) - 1 ) ;
case V_214 :
return ( ( ( V_211 * 2 ) + 16 * V_210 ) / ( 16 * V_210 ) - 1 ) ;
case V_215 :
return ( ( ( V_211 * 2 ) + 16 * V_210 ) / ( 32 * V_210 ) - 1 ) ;
case V_216 :
return ( ( ( V_211 * 1000 / 32 ) / V_210 ) - 1 ) ;
}
F_142 ( 1 ) ;
return ( ( V_211 + 16 * V_210 ) / ( 32 * V_210 ) - 1 ) ;
}
static void F_143 ( struct V_2 * V_4 )
{
struct V_7 * V_8 ;
unsigned int V_32 ;
do {
V_32 = F_21 ( V_4 , V_34 ) ;
} while ( ! ( V_32 & F_30 ( V_4 ) ) );
F_23 ( V_4 , V_62 , 0x00 ) ;
V_8 = F_4 ( V_4 , V_143 ) ;
if ( V_8 -> V_9 )
F_23 ( V_4 , V_143 , V_217 | V_218 ) ;
}
static void F_144 ( struct V_2 * V_4 , struct V_219 * V_220 ,
struct V_219 * V_221 )
{
struct V_1 * V_39 = F_1 ( V_4 ) ;
struct V_7 * V_8 ;
unsigned int V_222 , V_223 , V_224 , V_225 ;
int V_226 = - 1 ;
V_224 = V_4 -> V_30 ? V_4 -> V_30 / 16 : 115200 ;
V_222 = F_145 ( V_4 , V_220 , V_221 , 0 , V_224 ) ;
if ( F_146 ( V_222 && V_4 -> V_30 ) )
V_226 = F_141 ( V_39 -> V_14 -> V_227 , V_222 , V_4 -> V_30 ) ;
F_13 ( V_39 ) ;
F_143 ( V_4 ) ;
V_223 = F_21 ( V_4 , V_228 ) & 3 ;
if ( ( V_220 -> V_229 & V_230 ) == V_231 )
V_223 |= 0x40 ;
if ( V_220 -> V_229 & V_232 )
V_223 |= 0x20 ;
if ( V_220 -> V_229 & V_233 )
V_223 |= 0x30 ;
if ( V_220 -> V_229 & V_234 )
V_223 |= 0x08 ;
F_147 ( V_4 , V_220 -> V_229 , V_222 ) ;
for ( V_225 = 0 ; V_226 >= 256 && V_225 <= 3 ; V_225 ++ )
V_226 >>= 2 ;
F_49 ( V_4 -> V_28 , L_34 ,
V_147 , V_223 , V_225 , V_226 , V_39 -> V_14 -> V_106 ) ;
if ( V_226 >= 0 ) {
F_23 ( V_4 , V_228 , ( V_223 & ~ 3 ) | V_225 ) ;
F_23 ( V_4 , V_235 , V_226 ) ;
F_148 ( ( 1000000 + ( V_222 - 1 ) ) / V_222 ) ;
} else
F_23 ( V_4 , V_228 , V_223 ) ;
F_31 ( V_4 , V_220 -> V_229 ) ;
V_8 = F_4 ( V_4 , V_143 ) ;
if ( V_8 -> V_9 ) {
unsigned short V_60 = F_21 ( V_4 , V_143 ) ;
if ( V_39 -> V_14 -> V_44 & V_45 ) {
if ( V_220 -> V_229 & V_46 )
V_60 |= V_236 ;
else
V_60 &= ~ V_236 ;
}
V_60 &= ~ ( V_217 | V_218 ) ;
F_23 ( V_4 , V_143 , V_60 ) ;
}
F_23 ( V_4 , V_62 , V_39 -> V_14 -> V_106 ) ;
#ifdef F_63
if ( V_39 -> V_97 ) {
V_39 -> V_101 = ( V_4 -> V_237 - V_238 / 50 ) * V_39 -> V_158 * 3 /
V_4 -> V_50 / 2 ;
F_49 ( V_4 -> V_28 ,
L_35 ,
V_39 -> V_101 * 1000 / V_238 , V_4 -> V_237 ) ;
if ( V_39 -> V_101 < F_149 ( 20 ) )
V_39 -> V_101 = F_149 ( 20 ) ;
}
#endif
if ( ( V_220 -> V_229 & V_239 ) != 0 )
F_104 ( V_4 ) ;
F_17 ( V_39 ) ;
}
static void F_150 ( struct V_2 * V_4 , unsigned int V_58 ,
unsigned int V_240 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
switch ( V_58 ) {
case 3 :
F_17 ( V_1 ) ;
break;
default:
F_13 ( V_1 ) ;
break;
}
}
static const char * F_151 ( struct V_2 * V_4 )
{
switch ( V_4 -> type ) {
case V_18 :
return L_36 ;
case V_15 :
return L_37 ;
case V_24 :
return L_38 ;
case V_20 :
return L_39 ;
case V_22 :
return L_40 ;
}
return NULL ;
}
static inline unsigned long F_152 ( struct V_2 * V_4 )
{
return 64 ;
}
static int F_153 ( struct V_2 * V_4 )
{
unsigned long V_9 = F_152 ( V_4 ) ;
if ( V_4 -> V_10 )
return 0 ;
if ( V_4 -> V_104 & V_241 ) {
V_4 -> V_10 = F_154 ( V_4 -> V_242 , V_9 ) ;
if ( F_76 ( ! V_4 -> V_10 ) ) {
F_79 ( V_4 -> V_28 , L_41 , V_4 -> line ) ;
return - V_243 ;
}
} else {
V_4 -> V_10 = ( void V_55 * ) V_4 -> V_242 ;
}
return 0 ;
}
static void F_155 ( struct V_2 * V_4 )
{
if ( V_4 -> V_104 & V_241 ) {
F_156 ( V_4 -> V_10 ) ;
V_4 -> V_10 = NULL ;
}
F_157 ( V_4 -> V_242 , F_152 ( V_4 ) ) ;
}
static int F_158 ( struct V_2 * V_4 )
{
unsigned long V_9 = F_152 ( V_4 ) ;
struct V_244 * V_245 ;
int V_111 ;
V_245 = F_159 ( V_4 -> V_242 , V_9 , F_78 ( V_4 -> V_28 ) ) ;
if ( F_76 ( V_245 == NULL ) )
return - V_246 ;
V_111 = F_153 ( V_4 ) ;
if ( F_76 ( V_111 != 0 ) ) {
F_160 ( V_245 ) ;
return V_111 ;
}
return 0 ;
}
static void F_161 ( struct V_2 * V_4 , int V_104 )
{
if ( V_104 & V_247 ) {
struct V_1 * V_248 = F_1 ( V_4 ) ;
V_4 -> type = V_248 -> V_14 -> type ;
F_158 ( V_4 ) ;
}
}
static int F_162 ( struct V_2 * V_4 , struct V_249 * V_250 )
{
struct V_1 * V_39 = F_1 ( V_4 ) ;
if ( V_250 -> V_95 != V_39 -> V_14 -> V_127 [ V_251 ] || V_250 -> V_95 > V_252 )
return - V_27 ;
if ( V_250 -> V_253 < 2400 )
return - V_27 ;
return 0 ;
}
static int F_163 ( struct V_254 * V_28 ,
struct V_1 * V_1 ,
unsigned int V_134 ,
struct V_13 * V_5 )
{
struct V_2 * V_4 = & V_1 -> V_4 ;
int V_111 ;
V_1 -> V_14 = V_5 ;
V_4 -> V_42 = & V_255 ;
V_4 -> V_256 = V_257 ;
V_4 -> line = V_134 ;
switch ( V_5 -> type ) {
case V_22 :
V_4 -> V_50 = 256 ;
break;
case V_20 :
V_4 -> V_50 = 64 ;
break;
case V_24 :
V_4 -> V_50 = 16 ;
break;
default:
V_4 -> V_50 = 1 ;
break;
}
if ( V_5 -> V_16 == V_258 ) {
V_111 = F_11 ( V_5 ) ;
if ( F_76 ( V_111 ) )
return V_111 ;
}
if ( V_28 ) {
V_1 -> V_29 = F_164 ( & V_28 -> V_28 , L_42 ) ;
if ( F_165 ( V_1 -> V_29 ) ) {
V_1 -> V_29 = F_164 ( & V_28 -> V_28 , L_43 ) ;
if ( F_165 ( V_1 -> V_29 ) ) {
F_79 ( & V_28 -> V_28 , L_44 ) ;
return F_166 ( V_1 -> V_29 ) ;
}
}
V_1 -> V_31 = F_164 ( & V_28 -> V_28 , L_45 ) ;
if ( F_165 ( V_1 -> V_31 ) )
V_1 -> V_31 = NULL ;
V_4 -> V_28 = & V_28 -> V_28 ;
F_85 ( V_1 ) ;
F_167 ( & V_28 -> V_28 ) ;
}
V_1 -> V_84 . V_87 = ( unsigned long ) V_1 ;
V_1 -> V_84 . V_259 = F_56 ;
F_168 ( & V_1 -> V_84 ) ;
if ( ! V_5 -> V_260 )
V_5 -> V_260 = ( V_5 -> type == V_15 ) ?
V_261 : V_262 ;
if ( V_5 -> V_88 != V_89 ) {
if ( V_5 -> type == V_15 )
V_5 -> V_88 = 5 ;
else if ( V_5 -> V_227 == V_215 )
V_5 -> V_88 = 9 ;
else
V_5 -> V_88 = 0 ;
V_5 -> V_260 |= ( 1 << V_5 -> V_88 ) ;
}
V_4 -> V_242 = V_5 -> V_242 ;
V_4 -> type = V_5 -> type ;
V_4 -> V_104 = V_5 -> V_104 ;
V_4 -> V_11 = V_5 -> V_11 ;
V_4 -> V_95 = V_5 -> V_127 [ V_263 ] ;
V_4 -> V_132 = 0 ;
V_4 -> V_264 = F_3 ;
V_4 -> V_265 = F_8 ;
if ( V_5 -> V_202 > 0 && V_5 -> V_203 > 0 )
F_49 ( V_4 -> V_28 , L_46 ,
V_5 -> V_202 , V_5 -> V_203 ) ;
return 0 ;
}
static void F_169 ( struct V_1 * V_4 )
{
F_87 ( V_4 ) ;
F_170 ( V_4 -> V_29 ) ;
F_170 ( V_4 -> V_31 ) ;
F_171 ( V_4 -> V_4 . V_28 ) ;
}
static void F_172 ( struct V_2 * V_4 , int V_266 )
{
F_27 ( V_4 , V_266 ) ;
}
static void F_173 ( struct V_267 * V_268 , const char * V_39 ,
unsigned V_61 )
{
struct V_1 * V_1 = & V_269 [ V_268 -> V_134 ] ;
struct V_2 * V_4 = & V_1 -> V_4 ;
unsigned short V_270 , V_60 ;
unsigned long V_104 ;
int V_271 = 1 ;
F_174 ( V_104 ) ;
if ( V_4 -> V_272 )
V_271 = 0 ;
else if ( V_273 )
V_271 = F_175 ( & V_4 -> V_105 ) ;
else
F_176 ( & V_4 -> V_105 ) ;
V_60 = F_21 ( V_4 , V_62 ) ;
F_23 ( V_4 , V_62 , V_1 -> V_14 -> V_106 ) ;
F_177 ( V_4 , V_39 , V_61 , F_172 ) ;
V_270 = F_28 ( V_4 ) | F_30 ( V_4 ) ;
while ( ( F_21 ( V_4 , V_34 ) & V_270 ) != V_270 )
F_178 () ;
F_23 ( V_4 , V_62 , V_60 ) ;
if ( V_271 )
F_179 ( & V_4 -> V_105 ) ;
F_180 ( V_104 ) ;
}
static int F_181 ( struct V_267 * V_268 , char * V_274 )
{
struct V_1 * V_1 ;
struct V_2 * V_4 ;
int V_222 = 115200 ;
int V_270 = 8 ;
int V_82 = 'n' ;
int V_275 = 'n' ;
int V_111 ;
if ( V_268 -> V_134 < 0 || V_268 -> V_134 >= V_276 )
return - V_277 ;
V_1 = & V_269 [ V_268 -> V_134 ] ;
V_4 = & V_1 -> V_4 ;
if ( ! V_4 -> V_42 )
return - V_277 ;
V_111 = F_153 ( V_4 ) ;
if ( F_76 ( V_111 != 0 ) )
return V_111 ;
if ( V_274 )
F_182 ( V_274 , & V_222 , & V_82 , & V_270 , & V_275 ) ;
return F_183 ( V_4 , V_268 , V_222 , V_82 , V_270 , V_275 ) ;
}
static int F_184 ( struct V_254 * V_278 )
{
struct V_13 * V_14 = V_278 -> V_28 . V_279 ;
if ( V_280 . V_87 )
return - V_281 ;
V_280 . V_134 = V_278 -> V_282 ;
F_163 ( NULL , & V_269 [ V_278 -> V_282 ] , V_278 -> V_282 , V_14 ) ;
F_181 ( & V_280 , V_283 ) ;
if ( ! strstr ( V_283 , L_47 ) )
V_280 . V_104 |= V_284 ;
F_185 ( & V_280 ) ;
return 0 ;
}
static inline int F_184 ( struct V_254 * V_278 )
{
return - V_27 ;
}
static int F_186 ( struct V_254 * V_28 )
{
struct V_1 * V_4 = F_187 ( V_28 ) ;
F_188 ( & V_4 -> V_117 ,
V_285 ) ;
F_189 ( & V_286 , & V_4 -> V_4 ) ;
F_169 ( V_4 ) ;
return 0 ;
}
static int F_190 ( struct V_254 * V_28 ,
unsigned int V_134 ,
struct V_13 * V_5 ,
struct V_1 * V_287 )
{
int V_111 ;
if ( F_76 ( V_134 >= V_276 ) ) {
F_51 ( & V_28 -> V_28 , L_48
L_49 ,
V_134 + 1 , V_276 ) ;
F_51 ( & V_28 -> V_28 , L_50
L_51 ) ;
return - V_27 ;
}
V_111 = F_163 ( V_28 , V_287 , V_134 , V_5 ) ;
if ( V_111 )
return V_111 ;
V_111 = F_191 ( & V_286 , & V_287 -> V_4 ) ;
if ( V_111 ) {
F_169 ( V_287 ) ;
return V_111 ;
}
return 0 ;
}
static int F_192 ( struct V_254 * V_28 )
{
struct V_13 * V_5 = V_28 -> V_28 . V_279 ;
struct V_1 * V_288 = & V_269 [ V_28 -> V_282 ] ;
int V_111 ;
if ( F_193 ( V_28 ) )
return F_184 ( V_28 ) ;
F_194 ( V_28 , V_288 ) ;
V_111 = F_190 ( V_28 , V_28 -> V_282 , V_5 , V_288 ) ;
if ( V_111 )
return V_111 ;
V_288 -> V_117 . V_289 = F_73 ;
V_111 = F_195 ( & V_288 -> V_117 ,
V_285 ) ;
if ( F_76 ( V_111 < 0 ) ) {
F_169 ( V_288 ) ;
return V_111 ;
}
#ifdef F_196
F_197 () ;
#endif
return 0 ;
}
static int F_198 ( struct V_179 * V_28 )
{
struct V_1 * V_248 = F_199 ( V_28 ) ;
if ( V_248 )
F_200 ( & V_286 , & V_248 -> V_4 ) ;
return 0 ;
}
static int F_201 ( struct V_179 * V_28 )
{
struct V_1 * V_248 = F_199 ( V_28 ) ;
if ( V_248 )
F_202 ( & V_286 , & V_248 -> V_4 ) ;
return 0 ;
}
static int T_6 F_203 ( void )
{
int V_111 ;
F_12 ( V_290 ) ;
V_111 = F_204 ( & V_286 ) ;
if ( F_146 ( V_111 == 0 ) ) {
V_111 = F_205 ( & V_291 ) ;
if ( F_76 ( V_111 ) )
F_206 ( & V_286 ) ;
}
return V_111 ;
}
static void T_7 F_207 ( void )
{
F_208 ( & V_291 ) ;
F_206 ( & V_286 ) ;
}
