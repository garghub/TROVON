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
return F_21 ( V_4 , V_49 ) & 0xff ;
V_8 = F_4 ( V_4 , V_50 ) ;
if ( V_8 -> V_9 )
return F_21 ( V_4 , V_50 ) >> 8 ;
return ! ( F_21 ( V_4 , V_34 ) & V_51 ) ;
}
static int F_33 ( struct V_2 * V_4 )
{
return V_4 -> V_52 - F_32 ( V_4 ) ;
}
static int F_34 ( struct V_2 * V_4 )
{
struct V_7 * V_8 ;
V_8 = F_4 ( V_4 , V_53 ) ;
if ( V_8 -> V_9 )
return F_21 ( V_4 , V_53 ) & 0xff ;
V_8 = F_4 ( V_4 , V_50 ) ;
if ( V_8 -> V_9 )
return F_21 ( V_4 , V_50 ) & ( ( V_4 -> V_52 << 1 ) - 1 ) ;
return ( F_21 ( V_4 , V_34 ) & F_25 ( V_4 ) ) != 0 ;
}
static inline int F_35 ( struct V_2 * V_4 )
{
struct V_1 * V_39 = F_1 ( V_4 ) ;
if ( V_39 -> V_14 -> V_54 <= 0 )
return 1 ;
return ! ! F_36 ( V_39 -> V_14 -> V_54 ) ;
}
static void F_37 ( struct V_2 * V_4 )
{
struct V_55 * V_56 = & V_4 -> V_57 -> V_56 ;
unsigned int V_58 = F_38 ( V_4 ) ;
unsigned short V_32 ;
unsigned short V_59 ;
int V_60 ;
V_32 = F_21 ( V_4 , V_34 ) ;
if ( ! ( V_32 & F_28 ( V_4 ) ) ) {
V_59 = F_21 ( V_4 , V_61 ) ;
if ( F_39 ( V_56 ) )
V_59 &= ~ V_62 ;
else
V_59 |= V_62 ;
F_23 ( V_4 , V_61 , V_59 ) ;
return;
}
V_60 = F_33 ( V_4 ) ;
do {
unsigned char V_33 ;
if ( V_4 -> V_63 ) {
V_33 = V_4 -> V_63 ;
V_4 -> V_63 = 0 ;
} else if ( ! F_39 ( V_56 ) && ! V_58 ) {
V_33 = V_56 -> V_64 [ V_56 -> V_65 ] ;
V_56 -> V_65 = ( V_56 -> V_65 + 1 ) & ( V_66 - 1 ) ;
} else {
break;
}
F_23 ( V_4 , V_37 , V_33 ) ;
V_4 -> V_67 . V_68 ++ ;
} while ( -- V_60 > 0 );
F_23 ( V_4 , V_34 , F_29 ( V_4 ) ) ;
if ( F_40 ( V_56 ) < V_69 )
F_41 ( V_4 ) ;
if ( F_39 ( V_56 ) ) {
F_42 ( V_4 ) ;
} else {
V_59 = F_21 ( V_4 , V_61 ) ;
if ( V_4 -> type != V_15 ) {
F_21 ( V_4 , V_34 ) ;
F_23 ( V_4 , V_34 , F_29 ( V_4 ) ) ;
}
V_59 |= V_62 ;
F_23 ( V_4 , V_61 , V_59 ) ;
}
}
static void F_43 ( struct V_2 * V_4 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_70 * V_71 = V_4 -> V_57 -> V_4 . V_71 ;
int V_72 , V_60 , V_73 = 0 ;
unsigned short V_32 ;
unsigned char V_74 ;
V_32 = F_21 ( V_4 , V_34 ) ;
if ( ! ( V_32 & F_25 ( V_4 ) ) )
return;
while ( 1 ) {
V_60 = F_44 ( V_71 , F_34 ( V_4 ) ) ;
if ( V_60 == 0 )
break;
if ( V_4 -> type == V_15 ) {
char V_33 = F_21 ( V_4 , V_36 ) ;
if ( F_45 ( V_4 , V_33 ) ||
V_1 -> V_75 )
V_60 = 0 ;
else
F_46 ( V_71 , V_33 , V_76 ) ;
} else {
for ( V_72 = 0 ; V_72 < V_60 ; V_72 ++ ) {
char V_33 = F_21 ( V_4 , V_36 ) ;
V_32 = F_21 ( V_4 , V_34 ) ;
#if F_47 ( V_77 )
if ( V_1 -> V_75 ) {
if ( ( V_33 == 0 ) &&
( V_32 & F_48 ( V_4 ) ) ) {
V_60 -- ; V_72 -- ;
continue;
}
F_49 ( V_4 -> V_28 , L_3 , V_33 ) ;
V_1 -> V_75 = 0 ;
if ( F_50 ( V_33 ) ) {
V_60 -- ; V_72 -- ;
continue;
}
}
#endif
if ( F_45 ( V_4 , V_33 ) ) {
V_60 -- ; V_72 -- ;
continue;
}
if ( V_32 & F_48 ( V_4 ) ) {
V_74 = V_78 ;
V_4 -> V_67 . V_79 ++ ;
F_51 ( V_4 -> V_28 , L_4 ) ;
} else if ( V_32 & F_52 ( V_4 ) ) {
V_74 = V_80 ;
V_4 -> V_67 . V_81 ++ ;
F_51 ( V_4 -> V_28 , L_5 ) ;
} else
V_74 = V_76 ;
F_46 ( V_71 , V_33 , V_74 ) ;
}
}
F_21 ( V_4 , V_34 ) ;
F_23 ( V_4 , V_34 , F_26 ( V_4 ) ) ;
V_73 += V_60 ;
V_4 -> V_67 . V_82 += V_60 ;
}
if ( V_73 ) {
F_53 ( V_71 ) ;
} else {
F_21 ( V_4 , V_34 ) ;
F_23 ( V_4 , V_34 , F_26 ( V_4 ) ) ;
}
}
static inline void F_54 ( struct V_1 * V_4 )
{
F_55 ( & V_4 -> V_83 , V_84 + V_85 ) ;
}
static void F_56 ( unsigned long V_86 )
{
struct V_1 * V_4 = (struct V_1 * ) V_86 ;
F_13 ( V_4 ) ;
if ( F_35 ( & V_4 -> V_4 ) == 0 ) {
V_4 -> V_75 = 1 ;
F_54 ( V_4 ) ;
} else if ( V_4 -> V_75 == 1 ) {
V_4 -> V_75 = 2 ;
F_54 ( V_4 ) ;
} else
V_4 -> V_75 = 0 ;
F_17 ( V_4 ) ;
}
static int F_57 ( struct V_2 * V_4 )
{
int V_73 = 0 ;
unsigned short V_32 = F_21 ( V_4 , V_34 ) ;
struct V_70 * V_71 = V_4 -> V_57 -> V_4 . V_71 ;
struct V_1 * V_39 = F_1 ( V_4 ) ;
if ( V_39 -> V_14 -> V_87 != V_88 ) {
if ( V_32 & ( 1 << V_39 -> V_14 -> V_87 ) ) {
V_4 -> V_67 . V_89 ++ ;
if ( F_46 ( V_71 , 0 , V_90 ) )
V_73 ++ ;
F_51 ( V_4 -> V_28 , L_6 ) ;
}
}
if ( V_32 & F_48 ( V_4 ) ) {
if ( F_35 ( V_4 ) == 0 ) {
struct V_1 * V_1 = F_1 ( V_4 ) ;
if ( ! V_1 -> V_75 ) {
V_4 -> V_67 . V_91 ++ ;
V_1 -> V_75 = 1 ;
F_54 ( V_1 ) ;
if ( F_58 ( V_4 ) )
return 0 ;
F_49 ( V_4 -> V_28 , L_7 ) ;
if ( F_46 ( V_71 , 0 , V_92 ) )
V_73 ++ ;
}
} else {
V_4 -> V_67 . V_79 ++ ;
if ( F_46 ( V_71 , 0 , V_78 ) )
V_73 ++ ;
F_51 ( V_4 -> V_28 , L_4 ) ;
}
}
if ( V_32 & F_52 ( V_4 ) ) {
V_4 -> V_67 . V_81 ++ ;
if ( F_46 ( V_71 , 0 , V_80 ) )
V_73 ++ ;
F_51 ( V_4 -> V_28 , L_8 ) ;
}
if ( V_73 )
F_53 ( V_71 ) ;
return V_73 ;
}
static int F_59 ( struct V_2 * V_4 )
{
struct V_70 * V_71 = V_4 -> V_57 -> V_4 . V_71 ;
struct V_1 * V_39 = F_1 ( V_4 ) ;
struct V_7 * V_8 ;
int V_73 = 0 ;
V_8 = F_4 ( V_4 , V_93 ) ;
if ( ! V_8 -> V_9 )
return 0 ;
if ( ( F_21 ( V_4 , V_93 ) & ( 1 << V_39 -> V_14 -> V_87 ) ) ) {
F_23 ( V_4 , V_93 , 0 ) ;
V_4 -> V_67 . V_89 ++ ;
F_46 ( V_71 , 0 , V_90 ) ;
F_53 ( V_71 ) ;
F_51 ( V_4 -> V_28 , L_9 ) ;
V_73 ++ ;
}
return V_73 ;
}
static int F_60 ( struct V_2 * V_4 )
{
int V_73 = 0 ;
unsigned short V_32 = F_21 ( V_4 , V_34 ) ;
struct V_70 * V_71 = V_4 -> V_57 -> V_4 . V_71 ;
struct V_1 * V_39 = F_1 ( V_4 ) ;
if ( F_58 ( V_4 ) )
return 0 ;
if ( ! V_39 -> V_75 && V_32 & F_61 ( V_4 ) ) {
#if F_47 ( V_77 )
V_39 -> V_75 = 1 ;
#endif
V_4 -> V_67 . V_91 ++ ;
if ( F_46 ( V_71 , 0 , V_92 ) )
V_73 ++ ;
F_49 ( V_4 -> V_28 , L_7 ) ;
}
if ( V_73 )
F_53 ( V_71 ) ;
V_73 += F_59 ( V_4 ) ;
return V_73 ;
}
static T_1 F_62 ( int V_94 , void * V_95 )
{
#ifdef F_63
struct V_2 * V_4 = V_95 ;
struct V_1 * V_39 = F_1 ( V_4 ) ;
if ( V_39 -> V_96 ) {
T_2 V_97 = F_21 ( V_4 , V_61 ) ;
T_2 V_98 = F_21 ( V_4 , V_34 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
F_64 ( V_94 ) ;
V_97 |= 0x4000 ;
} else {
V_97 &= ~ V_99 ;
}
F_23 ( V_4 , V_61 , V_97 ) ;
F_23 ( V_4 , V_34 , V_98 & ~ ( 1 | F_25 ( V_4 ) ) ) ;
F_49 ( V_4 -> V_28 , L_10 ,
V_84 , V_39 -> V_100 ) ;
F_55 ( & V_39 -> V_101 , V_84 + V_39 -> V_100 ) ;
return V_102 ;
}
#endif
F_43 ( V_95 ) ;
return V_102 ;
}
static T_1 F_65 ( int V_94 , void * V_95 )
{
struct V_2 * V_4 = V_95 ;
unsigned long V_103 ;
F_66 ( & V_4 -> V_104 , V_103 ) ;
F_37 ( V_4 ) ;
F_67 ( & V_4 -> V_104 , V_103 ) ;
return V_102 ;
}
static T_1 F_68 ( int V_94 , void * V_95 )
{
struct V_2 * V_4 = V_95 ;
if ( V_4 -> type == V_15 ) {
if ( F_57 ( V_4 ) ) {
F_21 ( V_4 , V_34 ) ;
F_23 ( V_4 , V_34 , F_26 ( V_4 ) ) ;
}
} else {
F_59 ( V_4 ) ;
F_62 ( V_94 , V_95 ) ;
}
F_23 ( V_4 , V_34 , F_24 ( V_4 ) ) ;
F_65 ( V_94 , V_95 ) ;
return V_102 ;
}
static T_1 F_69 ( int V_94 , void * V_95 )
{
struct V_2 * V_4 = V_95 ;
F_60 ( V_4 ) ;
F_23 ( V_4 , V_34 , F_70 ( V_4 ) ) ;
return V_102 ;
}
static inline unsigned long F_71 ( struct V_2 * V_4 )
{
return V_99 | ( F_1 ( V_4 ) -> V_14 -> V_105 & V_106 ) ;
}
static T_1 F_72 ( int V_94 , void * V_95 )
{
unsigned short V_107 , V_108 , V_109 ;
struct V_2 * V_4 = V_95 ;
struct V_1 * V_39 = F_1 ( V_4 ) ;
T_1 V_110 = V_111 ;
V_107 = F_21 ( V_4 , V_34 ) ;
V_108 = F_21 ( V_4 , V_61 ) ;
V_109 = V_108 & F_71 ( V_4 ) ;
if ( ( V_107 & F_28 ( V_4 ) ) && ( V_108 & V_62 ) &&
! V_39 -> V_112 )
V_110 = F_65 ( V_94 , V_95 ) ;
if ( ( ( V_107 & F_25 ( V_4 ) ) || V_39 -> V_96 ) &&
( V_108 & V_99 ) )
V_110 = F_62 ( V_94 , V_95 ) ;
if ( ( V_107 & F_22 ( V_4 ) ) && V_109 )
V_110 = F_68 ( V_94 , V_95 ) ;
if ( ( V_107 & F_61 ( V_4 ) ) && V_109 )
V_110 = F_69 ( V_94 , V_95 ) ;
return V_110 ;
}
static int F_73 ( struct V_113 * V_114 ,
unsigned long V_115 , void * V_5 )
{
struct V_1 * V_1 ;
unsigned long V_103 ;
V_1 = F_2 ( V_114 , struct V_1 , V_116 ) ;
if ( ( V_115 == V_117 ) ||
( V_115 == V_118 ) ) {
struct V_2 * V_4 = & V_1 -> V_4 ;
F_66 ( & V_4 -> V_104 , V_103 ) ;
V_4 -> V_30 = F_16 ( V_1 -> V_29 ) ;
F_67 ( & V_4 -> V_104 , V_103 ) ;
}
return V_119 ;
}
static int F_74 ( struct V_1 * V_4 )
{
struct V_2 * V_120 = & V_4 -> V_4 ;
int V_72 , V_121 , V_110 = 0 ;
for ( V_72 = V_121 = 0 ; V_72 < V_122 ; V_72 ++ , V_121 ++ ) {
struct V_123 * V_124 ;
unsigned int V_94 ;
if ( F_75 ( V_4 ) ) {
V_72 = V_125 ;
V_94 = V_120 -> V_94 ;
} else {
V_94 = V_4 -> V_14 -> V_126 [ V_72 ] ;
if ( F_76 ( ! V_94 ) )
continue;
}
V_124 = V_123 + V_72 ;
V_4 -> V_127 [ V_121 ] = F_77 ( V_128 , L_11 ,
F_78 ( V_120 -> V_28 ) , V_124 -> V_124 ) ;
if ( ! V_4 -> V_127 [ V_121 ] ) {
F_79 ( V_120 -> V_28 , L_12 ,
V_124 -> V_124 ) ;
goto V_129;
}
V_110 = F_80 ( V_94 , V_124 -> V_130 , V_120 -> V_131 ,
V_4 -> V_127 [ V_121 ] , V_4 ) ;
if ( F_76 ( V_110 ) ) {
F_79 ( V_120 -> V_28 , L_13 , V_124 -> V_124 ) ;
goto V_132;
}
}
return 0 ;
V_132:
while ( -- V_72 >= 0 )
F_81 ( V_4 -> V_14 -> V_126 [ V_72 ] , V_4 ) ;
V_129:
while ( -- V_121 >= 0 )
F_82 ( V_4 -> V_127 [ V_121 ] ) ;
return V_110 ;
}
static void F_83 ( struct V_1 * V_4 )
{
int V_72 ;
for ( V_72 = 0 ; V_72 < V_122 ; V_72 ++ ) {
unsigned int V_94 = V_4 -> V_14 -> V_126 [ V_72 ] ;
if ( F_76 ( ! V_94 ) )
continue;
F_81 ( V_4 -> V_14 -> V_126 [ V_72 ] , V_4 ) ;
F_82 ( V_4 -> V_127 [ V_72 ] ) ;
if ( F_75 ( V_4 ) ) {
return;
}
}
}
static const char * F_84 ( unsigned int V_133 )
{
return V_134 [ V_133 ] ;
}
static void T_3 F_85 ( struct V_1 * V_4 )
{
struct V_2 * V_120 = & V_4 -> V_4 ;
int V_72 ;
if ( ! V_4 -> V_14 )
return;
for ( V_72 = 0 ; V_72 < V_135 ; V_72 ++ ) {
const char * V_124 ;
int V_110 ;
if ( ! V_4 -> V_14 -> V_136 [ V_72 ] )
continue;
V_124 = F_84 ( V_72 ) ;
V_4 -> V_137 [ V_72 ] = F_77 ( V_128 , L_11 ,
F_78 ( V_120 -> V_28 ) , V_124 ) ;
if ( ! V_4 -> V_137 [ V_72 ] )
F_51 ( V_120 -> V_28 , L_14 ,
V_124 ) ;
V_110 = F_86 ( V_4 -> V_14 -> V_136 [ V_72 ] , V_4 -> V_137 [ V_72 ] ) ;
if ( F_76 ( V_110 != 0 ) ) {
F_51 ( V_120 -> V_28 , L_15 , V_124 ) ;
F_82 ( V_4 -> V_137 [ V_72 ] ) ;
}
}
}
static void F_87 ( struct V_1 * V_4 )
{
int V_72 ;
for ( V_72 = 0 ; V_72 < V_135 ; V_72 ++ )
if ( V_4 -> V_14 -> V_136 [ V_72 ] ) {
F_88 ( V_4 -> V_14 -> V_136 [ V_72 ] ) ;
F_82 ( V_4 -> V_137 [ V_72 ] ) ;
}
}
static unsigned int F_89 ( struct V_2 * V_4 )
{
unsigned short V_32 = F_21 ( V_4 , V_34 ) ;
unsigned short V_138 = F_32 ( V_4 ) ;
return ( V_32 & F_30 ( V_4 ) ) && ! V_138 ? V_139 : 0 ;
}
static void F_90 ( struct V_2 * V_4 , unsigned int V_140 )
{
if ( V_140 & V_141 ) {
struct V_7 * V_8 ;
V_8 = F_4 ( V_4 , V_142 ) ;
if ( V_8 -> V_9 )
F_23 ( V_4 , V_142 , F_21 ( V_4 , V_142 ) | 1 ) ;
}
}
static unsigned int F_91 ( struct V_2 * V_4 )
{
return V_143 | V_144 ;
}
static void F_92 ( void * V_145 )
{
struct V_1 * V_39 = V_145 ;
struct V_2 * V_4 = & V_39 -> V_4 ;
struct V_55 * V_56 = & V_4 -> V_57 -> V_56 ;
unsigned long V_103 ;
F_49 ( V_4 -> V_28 , L_16 , V_146 , V_4 -> line ) ;
F_66 ( & V_4 -> V_104 , V_103 ) ;
V_56 -> V_65 += F_93 ( & V_39 -> V_147 ) ;
V_56 -> V_65 &= V_66 - 1 ;
V_4 -> V_67 . V_68 += F_93 ( & V_39 -> V_147 ) ;
F_94 ( V_39 -> V_148 ) ;
V_39 -> V_148 = NULL ;
if ( F_40 ( V_56 ) < V_69 )
F_41 ( V_4 ) ;
if ( ! F_39 ( V_56 ) ) {
V_39 -> V_149 = 0 ;
F_95 ( & V_39 -> V_150 ) ;
} else {
V_39 -> V_149 = - V_27 ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
T_2 V_59 = F_21 ( V_4 , V_61 ) ;
F_23 ( V_4 , V_61 , V_59 & ~ V_62 ) ;
}
}
F_67 ( & V_4 -> V_104 , V_103 ) ;
}
static int F_96 ( struct V_1 * V_39 , struct V_70 * V_71 ,
T_4 V_60 )
{
struct V_2 * V_4 = & V_39 -> V_4 ;
int V_72 , V_151 , V_152 ;
V_152 = F_44 ( V_71 , V_60 ) ;
if ( V_39 -> V_153 == V_39 -> V_154 [ 0 ] ) {
V_151 = 0 ;
} else if ( V_39 -> V_153 == V_39 -> V_154 [ 1 ] ) {
V_151 = 1 ;
} else {
F_79 ( V_4 -> V_28 , L_17 , V_39 -> V_153 ) ;
return 0 ;
}
if ( V_152 < V_60 )
F_97 ( V_4 -> V_28 , L_18 ,
V_60 - V_152 ) ;
if ( ! V_152 )
return V_152 ;
for ( V_72 = 0 ; V_72 < V_152 ; V_72 ++ )
F_46 ( V_71 , ( ( V_155 * ) F_98 ( & V_39 -> V_156 [ V_151 ] ) ) [ V_72 ] ,
V_76 ) ;
V_4 -> V_67 . V_82 += V_152 ;
return V_152 ;
}
static void F_99 ( void * V_145 )
{
struct V_1 * V_39 = V_145 ;
struct V_2 * V_4 = & V_39 -> V_4 ;
struct V_70 * V_71 = V_4 -> V_57 -> V_4 . V_71 ;
unsigned long V_103 ;
int V_60 ;
F_49 ( V_4 -> V_28 , L_19 , V_146 , V_4 -> line , V_39 -> V_153 ) ;
F_66 ( & V_4 -> V_104 , V_103 ) ;
V_60 = F_96 ( V_39 , V_71 , V_39 -> V_157 ) ;
F_55 ( & V_39 -> V_101 , V_84 + V_39 -> V_100 ) ;
F_67 ( & V_4 -> V_104 , V_103 ) ;
if ( V_60 )
F_53 ( V_71 ) ;
F_95 ( & V_39 -> V_158 ) ;
}
static void F_100 ( struct V_1 * V_39 , bool V_159 )
{
struct V_160 * V_161 = V_39 -> V_96 ;
struct V_2 * V_4 = & V_39 -> V_4 ;
V_39 -> V_96 = NULL ;
V_39 -> V_154 [ 0 ] = V_39 -> V_154 [ 1 ] = - V_27 ;
F_101 ( V_161 ) ;
if ( F_102 ( & V_39 -> V_156 [ 0 ] ) )
F_103 ( V_4 -> V_28 , V_39 -> V_157 * 2 ,
F_98 ( & V_39 -> V_156 [ 0 ] ) , F_102 ( & V_39 -> V_156 [ 0 ] ) ) ;
if ( V_159 )
F_104 ( V_4 ) ;
}
static void F_105 ( struct V_1 * V_39 , bool V_159 )
{
struct V_160 * V_161 = V_39 -> V_112 ;
struct V_2 * V_4 = & V_39 -> V_4 ;
V_39 -> V_112 = NULL ;
V_39 -> V_149 = - V_27 ;
F_101 ( V_161 ) ;
if ( V_159 )
F_106 ( V_4 ) ;
}
static void F_107 ( struct V_1 * V_39 )
{
struct V_160 * V_161 = V_39 -> V_96 ;
int V_72 ;
for ( V_72 = 0 ; V_72 < 2 ; V_72 ++ ) {
struct V_162 * V_163 = & V_39 -> V_156 [ V_72 ] ;
struct V_164 * V_124 ;
V_124 = F_108 ( V_161 ,
V_163 , 1 , V_165 , V_166 ) ;
if ( V_124 ) {
V_39 -> V_167 [ V_72 ] = V_124 ;
V_124 -> V_168 = F_99 ;
V_124 -> V_169 = V_39 ;
V_39 -> V_154 [ V_72 ] = V_124 -> V_170 ( V_124 ) ;
}
if ( ! V_124 || V_39 -> V_154 [ V_72 ] < 0 ) {
if ( V_72 ) {
F_94 ( V_39 -> V_167 [ 0 ] ) ;
V_39 -> V_154 [ 0 ] = - V_27 ;
}
if ( V_124 ) {
F_94 ( V_124 ) ;
V_39 -> V_154 [ V_72 ] = - V_27 ;
}
F_97 ( V_39 -> V_4 . V_28 ,
L_20 ) ;
F_100 ( V_39 , true ) ;
return;
}
F_49 ( V_39 -> V_4 . V_28 , L_21 , V_146 ,
V_39 -> V_154 [ V_72 ] , V_72 ) ;
}
V_39 -> V_153 = V_39 -> V_154 [ 0 ] ;
F_109 ( V_161 ) ;
}
static void F_110 ( struct V_171 * V_172 )
{
struct V_1 * V_39 = F_2 ( V_172 , struct V_1 , V_158 ) ;
struct V_2 * V_4 = & V_39 -> V_4 ;
struct V_164 * V_124 ;
int V_173 ;
if ( V_39 -> V_153 == V_39 -> V_154 [ 0 ] ) {
V_173 = 0 ;
} else if ( V_39 -> V_153 == V_39 -> V_154 [ 1 ] ) {
V_173 = 1 ;
} else {
F_79 ( V_4 -> V_28 , L_17 , V_39 -> V_153 ) ;
return;
}
V_124 = V_39 -> V_167 [ V_173 ] ;
if ( F_111 ( V_39 -> V_96 , V_39 -> V_153 , NULL , NULL ) !=
V_174 ) {
struct V_70 * V_71 = V_4 -> V_57 -> V_4 . V_71 ;
struct V_160 * V_161 = V_39 -> V_96 ;
struct V_175 * V_176 = F_2 ( V_124 ,
struct V_175 , V_177 ) ;
unsigned long V_103 ;
int V_60 ;
V_161 -> V_178 -> V_179 ( V_161 , V_180 , 0 ) ;
F_49 ( V_4 -> V_28 , L_22 ,
V_176 -> V_181 , V_176 -> V_182 ) ;
F_66 ( & V_4 -> V_104 , V_103 ) ;
V_60 = F_96 ( V_39 , V_71 , V_176 -> V_181 ) ;
F_67 ( & V_4 -> V_104 , V_103 ) ;
if ( V_60 )
F_53 ( V_71 ) ;
F_107 ( V_39 ) ;
return;
}
V_39 -> V_154 [ V_173 ] = V_124 -> V_170 ( V_124 ) ;
if ( V_39 -> V_154 [ V_173 ] < 0 ) {
F_97 ( V_4 -> V_28 , L_23 ) ;
F_100 ( V_39 , true ) ;
return;
}
V_39 -> V_153 = V_39 -> V_154 [ ! V_173 ] ;
F_49 ( V_4 -> V_28 , L_24 , V_146 ,
V_39 -> V_154 [ V_173 ] , V_173 , V_39 -> V_153 ) ;
}
static void F_112 ( struct V_171 * V_172 )
{
struct V_1 * V_39 = F_2 ( V_172 , struct V_1 , V_150 ) ;
struct V_164 * V_124 ;
struct V_160 * V_161 = V_39 -> V_112 ;
struct V_2 * V_4 = & V_39 -> V_4 ;
struct V_55 * V_56 = & V_4 -> V_57 -> V_56 ;
struct V_162 * V_163 = & V_39 -> V_147 ;
F_113 ( & V_4 -> V_104 ) ;
V_163 -> V_6 = V_56 -> V_65 & ( V_66 - 1 ) ;
F_102 ( V_163 ) = ( F_102 ( V_163 ) & ~ ( V_66 - 1 ) ) +
V_163 -> V_6 ;
F_93 ( V_163 ) = F_114 ( ( int ) F_115 ( V_56 -> V_183 , V_56 -> V_65 , V_66 ) ,
F_116 ( V_56 -> V_183 , V_56 -> V_65 , V_66 ) ) ;
F_117 ( & V_4 -> V_104 ) ;
F_118 ( ! F_93 ( V_163 ) ) ;
V_124 = F_108 ( V_161 ,
V_163 , V_39 -> V_184 , V_185 ,
V_166 | V_186 ) ;
if ( ! V_124 ) {
F_105 ( V_39 , true ) ;
return;
}
F_119 ( V_4 -> V_28 , V_163 , 1 , V_187 ) ;
F_113 ( & V_4 -> V_104 ) ;
V_39 -> V_148 = V_124 ;
V_124 -> V_168 = F_92 ;
V_124 -> V_169 = V_39 ;
F_117 ( & V_4 -> V_104 ) ;
V_39 -> V_149 = V_124 -> V_170 ( V_124 ) ;
if ( V_39 -> V_149 < 0 ) {
F_97 ( V_4 -> V_28 , L_25 ) ;
F_105 ( V_39 , true ) ;
return;
}
F_49 ( V_4 -> V_28 , L_26 , V_146 ,
V_56 -> V_64 , V_56 -> V_65 , V_56 -> V_183 , V_39 -> V_149 ) ;
F_109 ( V_161 ) ;
}
static void F_106 ( struct V_2 * V_4 )
{
struct V_1 * V_39 = F_1 ( V_4 ) ;
unsigned short V_59 ;
#ifdef F_63
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
T_2 V_173 , V_97 = F_21 ( V_4 , V_61 ) ;
if ( V_39 -> V_112 )
V_173 = V_97 | 0x8000 ;
else
V_173 = V_97 & ~ 0x8000 ;
if ( V_173 != V_97 )
F_23 ( V_4 , V_61 , V_173 ) ;
}
if ( V_39 -> V_112 && ! F_39 ( & V_39 -> V_4 . V_57 -> V_56 ) &&
V_39 -> V_149 < 0 ) {
V_39 -> V_149 = 0 ;
F_95 ( & V_39 -> V_150 ) ;
}
#endif
if ( ! V_39 -> V_112 || V_4 -> type == V_20 || V_4 -> type == V_22 ) {
V_59 = F_21 ( V_4 , V_61 ) ;
F_23 ( V_4 , V_61 , V_59 | V_62 ) ;
}
}
static void F_42 ( struct V_2 * V_4 )
{
unsigned short V_59 ;
V_59 = F_21 ( V_4 , V_61 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 )
V_59 &= ~ 0x8000 ;
V_59 &= ~ V_62 ;
F_23 ( V_4 , V_61 , V_59 ) ;
}
static void F_104 ( struct V_2 * V_4 )
{
unsigned short V_59 ;
V_59 = F_21 ( V_4 , V_61 ) | F_71 ( V_4 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 )
V_59 &= ~ 0x4000 ;
F_23 ( V_4 , V_61 , V_59 ) ;
}
static void F_120 ( struct V_2 * V_4 )
{
unsigned short V_59 ;
V_59 = F_21 ( V_4 , V_61 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 )
V_59 &= ~ 0x4000 ;
V_59 &= ~ F_71 ( V_4 ) ;
F_23 ( V_4 , V_61 , V_59 ) ;
}
static void F_121 ( struct V_2 * V_4 )
{
}
static void F_122 ( struct V_2 * V_4 , int V_188 )
{
struct V_1 * V_39 = F_1 ( V_4 ) ;
struct V_7 * V_8 = V_40 [ V_39 -> V_14 -> V_16 ] + V_41 ;
unsigned short V_105 , V_189 ;
if ( ! V_8 -> V_9 ) {
return;
}
V_189 = F_21 ( V_4 , V_41 ) ;
V_105 = F_21 ( V_4 , V_61 ) ;
if ( V_188 == - 1 ) {
V_189 = ( V_189 | V_190 ) & ~ V_191 ;
V_105 &= ~ V_192 ;
} else {
V_189 = ( V_189 | V_191 ) & ~ V_190 ;
V_105 |= V_192 ;
}
F_23 ( V_4 , V_41 , V_189 ) ;
F_23 ( V_4 , V_61 , V_105 ) ;
}
static bool F_123 ( struct V_160 * V_161 , void * V_193 )
{
struct V_194 * V_195 = V_193 ;
F_49 ( V_161 -> V_178 -> V_28 , L_27 , V_146 ,
V_195 -> V_196 . V_197 ) ;
V_161 -> V_198 = & V_195 -> V_196 ;
return true ;
}
static void F_124 ( unsigned long V_145 )
{
struct V_1 * V_39 = (struct V_1 * ) V_145 ;
struct V_2 * V_4 = & V_39 -> V_4 ;
T_2 V_97 = F_21 ( V_4 , V_61 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
V_97 &= ~ 0x4000 ;
F_125 ( V_39 -> V_14 -> V_126 [ 1 ] ) ;
}
F_23 ( V_4 , V_61 , V_97 | V_99 ) ;
F_49 ( V_4 -> V_28 , L_28 ) ;
F_95 ( & V_39 -> V_158 ) ;
}
static void F_126 ( struct V_2 * V_4 )
{
struct V_1 * V_39 = F_1 ( V_4 ) ;
struct V_194 * V_195 ;
struct V_160 * V_161 ;
T_5 V_199 ;
int V_200 ;
F_49 ( V_4 -> V_28 , L_29 , V_146 ,
V_4 -> line ) ;
if ( V_39 -> V_14 -> V_201 <= 0 || V_39 -> V_14 -> V_202 <= 0 )
return;
F_127 ( V_199 ) ;
F_128 ( V_203 , V_199 ) ;
V_195 = & V_39 -> V_204 ;
V_195 -> V_196 . V_197 = V_39 -> V_14 -> V_201 ;
V_39 -> V_149 = - V_27 ;
V_161 = F_129 ( V_199 , F_123 , V_195 ) ;
F_49 ( V_4 -> V_28 , L_30 , V_146 , V_161 ) ;
if ( V_161 ) {
V_39 -> V_112 = V_161 ;
F_130 ( & V_39 -> V_147 , 1 ) ;
F_118 ( ( int ) V_4 -> V_57 -> V_56 . V_64 & ~ V_205 ) ;
F_131 ( & V_39 -> V_147 , F_132 ( V_4 -> V_57 -> V_56 . V_64 ) ,
V_66 , ( int ) V_4 -> V_57 -> V_56 . V_64 & ~ V_205 ) ;
V_200 = F_133 ( V_4 -> V_28 , & V_39 -> V_147 , 1 , V_187 ) ;
if ( ! V_200 )
F_105 ( V_39 , false ) ;
else
F_49 ( V_4 -> V_28 , L_31 , V_146 ,
F_93 ( & V_39 -> V_147 ) ,
V_4 -> V_57 -> V_56 . V_64 , F_102 ( & V_39 -> V_147 ) ) ;
V_39 -> V_184 = V_200 ;
F_134 ( & V_39 -> V_150 , F_112 ) ;
}
V_195 = & V_39 -> V_206 ;
V_195 -> V_196 . V_197 = V_39 -> V_14 -> V_202 ;
V_161 = F_129 ( V_199 , F_123 , V_195 ) ;
F_49 ( V_4 -> V_28 , L_32 , V_146 , V_161 ) ;
if ( V_161 ) {
T_6 V_207 [ 2 ] ;
void * V_64 [ 2 ] ;
int V_72 ;
V_39 -> V_96 = V_161 ;
V_39 -> V_157 = 2 * F_135 ( 16 , ( int ) V_4 -> V_52 ) ;
V_64 [ 0 ] = F_136 ( V_4 -> V_28 , V_39 -> V_157 * 2 ,
& V_207 [ 0 ] , V_128 ) ;
if ( ! V_64 [ 0 ] ) {
F_97 ( V_4 -> V_28 ,
L_33 ) ;
F_100 ( V_39 , true ) ;
return;
}
V_64 [ 1 ] = V_64 [ 0 ] + V_39 -> V_157 ;
V_207 [ 1 ] = V_207 [ 0 ] + V_39 -> V_157 ;
for ( V_72 = 0 ; V_72 < 2 ; V_72 ++ ) {
struct V_162 * V_163 = & V_39 -> V_156 [ V_72 ] ;
F_130 ( V_163 , 1 ) ;
F_131 ( V_163 , F_132 ( V_64 [ V_72 ] ) , V_39 -> V_157 ,
( int ) V_64 [ V_72 ] & ~ V_205 ) ;
F_102 ( V_163 ) = V_207 [ V_72 ] ;
}
F_134 ( & V_39 -> V_158 , F_110 ) ;
F_137 ( & V_39 -> V_101 , F_124 , ( unsigned long ) V_39 ) ;
F_107 ( V_39 ) ;
}
}
static void F_138 ( struct V_2 * V_4 )
{
struct V_1 * V_39 = F_1 ( V_4 ) ;
if ( V_39 -> V_112 )
F_105 ( V_39 , false ) ;
if ( V_39 -> V_96 )
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
int V_110 ;
F_49 ( V_4 -> V_28 , L_16 , V_146 , V_4 -> line ) ;
F_140 ( V_4 -> V_28 ) ;
F_13 ( V_39 ) ;
V_110 = F_74 ( V_39 ) ;
if ( F_76 ( V_110 < 0 ) )
return V_110 ;
F_126 ( V_4 ) ;
F_106 ( V_4 ) ;
F_104 ( V_4 ) ;
return 0 ;
}
static void F_141 ( struct V_2 * V_4 )
{
struct V_1 * V_39 = F_1 ( V_4 ) ;
F_49 ( V_4 -> V_28 , L_16 , V_146 , V_4 -> line ) ;
F_120 ( V_4 ) ;
F_42 ( V_4 ) ;
F_138 ( V_4 ) ;
F_83 ( V_39 ) ;
F_17 ( V_39 ) ;
F_142 ( V_4 -> V_28 ) ;
}
static unsigned int F_143 ( unsigned int V_208 , unsigned int V_209 ,
unsigned long V_210 )
{
switch ( V_208 ) {
case V_211 :
return ( ( V_210 + 16 * V_209 ) / ( 16 * V_209 ) - 1 ) ;
case V_212 :
return ( ( V_210 + 16 * V_209 ) / ( 32 * V_209 ) - 1 ) ;
case V_213 :
return ( ( ( V_210 * 2 ) + 16 * V_209 ) / ( 16 * V_209 ) - 1 ) ;
case V_214 :
return ( ( ( V_210 * 2 ) + 16 * V_209 ) / ( 32 * V_209 ) - 1 ) ;
case V_215 :
return ( ( ( V_210 * 1000 / 32 ) / V_209 ) - 1 ) ;
}
F_144 ( 1 ) ;
return ( ( V_210 + 16 * V_209 ) / ( 32 * V_209 ) - 1 ) ;
}
static void F_145 ( struct V_2 * V_4 )
{
struct V_7 * V_8 ;
unsigned int V_32 ;
do {
V_32 = F_21 ( V_4 , V_34 ) ;
} while ( ! ( V_32 & F_30 ( V_4 ) ) );
F_23 ( V_4 , V_61 , 0x00 ) ;
V_8 = F_4 ( V_4 , V_142 ) ;
if ( V_8 -> V_9 )
F_23 ( V_4 , V_142 , V_216 | V_217 ) ;
}
static void F_146 ( struct V_2 * V_4 , struct V_218 * V_219 ,
struct V_218 * V_220 )
{
struct V_1 * V_39 = F_1 ( V_4 ) ;
struct V_7 * V_8 ;
unsigned int V_221 , V_222 , V_223 ;
int V_224 = - 1 ;
V_223 = V_4 -> V_30 ? V_4 -> V_30 / 16 : 115200 ;
V_221 = F_147 ( V_4 , V_219 , V_220 , 0 , V_223 ) ;
if ( F_148 ( V_221 && V_4 -> V_30 ) )
V_224 = F_143 ( V_39 -> V_14 -> V_225 , V_221 , V_4 -> V_30 ) ;
F_13 ( V_39 ) ;
F_145 ( V_4 ) ;
V_222 = F_21 ( V_4 , V_226 ) & 3 ;
if ( ( V_219 -> V_227 & V_228 ) == V_229 )
V_222 |= 0x40 ;
if ( V_219 -> V_227 & V_230 )
V_222 |= 0x20 ;
if ( V_219 -> V_227 & V_231 )
V_222 |= 0x30 ;
if ( V_219 -> V_227 & V_232 )
V_222 |= 0x08 ;
F_149 ( V_4 , V_219 -> V_227 , V_221 ) ;
F_23 ( V_4 , V_226 , V_222 ) ;
F_49 ( V_4 -> V_28 , L_34 , V_146 , V_222 , V_224 ,
V_39 -> V_14 -> V_105 ) ;
if ( V_224 > 0 ) {
if ( V_224 >= 256 ) {
F_23 ( V_4 , V_226 , ( F_21 ( V_4 , V_226 ) & ~ 3 ) | 1 ) ;
V_224 >>= 2 ;
} else
F_23 ( V_4 , V_226 , F_21 ( V_4 , V_226 ) & ~ 3 ) ;
F_23 ( V_4 , V_233 , V_224 ) ;
F_150 ( ( 1000000 + ( V_221 - 1 ) ) / V_221 ) ;
}
F_31 ( V_4 , V_219 -> V_227 ) ;
V_8 = F_4 ( V_4 , V_142 ) ;
if ( V_8 -> V_9 ) {
unsigned short V_59 = F_21 ( V_4 , V_142 ) ;
if ( V_39 -> V_14 -> V_44 & V_45 ) {
if ( V_219 -> V_227 & V_46 )
V_59 |= V_234 ;
else
V_59 &= ~ V_234 ;
}
V_59 &= ~ ( V_216 | V_217 ) ;
F_23 ( V_4 , V_142 , V_59 ) ;
}
F_23 ( V_4 , V_61 , V_39 -> V_14 -> V_105 ) ;
#ifdef F_63
if ( V_39 -> V_96 ) {
V_39 -> V_100 = ( V_4 -> V_235 - V_236 / 50 ) * V_39 -> V_157 * 3 /
V_4 -> V_52 / 2 ;
F_49 ( V_4 -> V_28 ,
L_35 ,
V_39 -> V_100 * 1000 / V_236 , V_4 -> V_235 ) ;
if ( V_39 -> V_100 < F_151 ( 20 ) )
V_39 -> V_100 = F_151 ( 20 ) ;
}
#endif
if ( ( V_219 -> V_227 & V_237 ) != 0 )
F_104 ( V_4 ) ;
F_17 ( V_39 ) ;
}
static const char * F_152 ( struct V_2 * V_4 )
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
static inline unsigned long F_153 ( struct V_2 * V_4 )
{
return 64 ;
}
static int F_154 ( struct V_2 * V_4 )
{
unsigned long V_9 = F_153 ( V_4 ) ;
if ( V_4 -> V_10 )
return 0 ;
if ( V_4 -> V_103 & V_238 ) {
V_4 -> V_10 = F_155 ( V_4 -> V_239 , V_9 ) ;
if ( F_76 ( ! V_4 -> V_10 ) ) {
F_79 ( V_4 -> V_28 , L_41 , V_4 -> line ) ;
return - V_240 ;
}
} else {
V_4 -> V_10 = ( void V_241 * ) V_4 -> V_239 ;
}
return 0 ;
}
static void F_156 ( struct V_2 * V_4 )
{
if ( V_4 -> V_103 & V_238 ) {
F_157 ( V_4 -> V_10 ) ;
V_4 -> V_10 = NULL ;
}
F_158 ( V_4 -> V_239 , F_153 ( V_4 ) ) ;
}
static int F_159 ( struct V_2 * V_4 )
{
unsigned long V_9 = F_153 ( V_4 ) ;
struct V_242 * V_243 ;
int V_110 ;
V_243 = F_160 ( V_4 -> V_239 , V_9 , F_78 ( V_4 -> V_28 ) ) ;
if ( F_76 ( V_243 == NULL ) )
return - V_244 ;
V_110 = F_154 ( V_4 ) ;
if ( F_76 ( V_110 != 0 ) ) {
F_161 ( V_243 ) ;
return V_110 ;
}
return 0 ;
}
static void F_162 ( struct V_2 * V_4 , int V_103 )
{
if ( V_103 & V_245 ) {
struct V_1 * V_246 = F_1 ( V_4 ) ;
V_4 -> type = V_246 -> V_14 -> type ;
F_159 ( V_4 ) ;
}
}
static int F_163 ( struct V_2 * V_4 , struct V_247 * V_248 )
{
struct V_1 * V_39 = F_1 ( V_4 ) ;
if ( V_248 -> V_94 != V_39 -> V_14 -> V_126 [ V_249 ] || V_248 -> V_94 > V_250 )
return - V_27 ;
if ( V_248 -> V_251 < 2400 )
return - V_27 ;
return 0 ;
}
static int T_3 F_164 ( struct V_252 * V_28 ,
struct V_1 * V_1 ,
unsigned int V_133 ,
struct V_13 * V_5 )
{
struct V_2 * V_4 = & V_1 -> V_4 ;
int V_110 ;
V_1 -> V_14 = V_5 ;
V_4 -> V_42 = & V_253 ;
V_4 -> V_254 = V_255 ;
V_4 -> line = V_133 ;
switch ( V_5 -> type ) {
case V_22 :
V_4 -> V_52 = 256 ;
break;
case V_20 :
V_4 -> V_52 = 64 ;
break;
case V_24 :
V_4 -> V_52 = 16 ;
break;
default:
V_4 -> V_52 = 1 ;
break;
}
if ( V_5 -> V_16 == V_256 ) {
V_110 = F_11 ( V_5 ) ;
if ( F_76 ( V_110 ) )
return V_110 ;
}
if ( V_28 ) {
V_1 -> V_29 = F_165 ( & V_28 -> V_28 , L_42 ) ;
if ( F_166 ( V_1 -> V_29 ) ) {
V_1 -> V_29 = F_165 ( & V_28 -> V_28 , L_43 ) ;
if ( F_166 ( V_1 -> V_29 ) ) {
F_79 ( & V_28 -> V_28 , L_44 ) ;
return F_167 ( V_1 -> V_29 ) ;
}
}
V_1 -> V_31 = F_165 ( & V_28 -> V_28 , L_45 ) ;
if ( F_166 ( V_1 -> V_31 ) )
V_1 -> V_31 = NULL ;
V_4 -> V_28 = & V_28 -> V_28 ;
F_85 ( V_1 ) ;
F_168 ( & V_28 -> V_28 ) ;
F_142 ( & V_28 -> V_28 ) ;
F_169 ( & V_28 -> V_28 ) ;
}
V_1 -> V_83 . V_86 = ( unsigned long ) V_1 ;
V_1 -> V_83 . V_257 = F_56 ;
F_170 ( & V_1 -> V_83 ) ;
if ( ! V_5 -> V_258 )
V_5 -> V_258 = ( V_5 -> type == V_15 ) ?
V_259 : V_260 ;
if ( V_5 -> V_87 != V_88 ) {
if ( V_5 -> type == V_15 )
V_5 -> V_87 = 5 ;
else if ( V_5 -> V_225 == V_214 )
V_5 -> V_87 = 9 ;
else
V_5 -> V_87 = 0 ;
V_5 -> V_258 |= ( 1 << V_5 -> V_87 ) ;
}
V_4 -> V_239 = V_5 -> V_239 ;
V_4 -> type = V_5 -> type ;
V_4 -> V_103 = V_5 -> V_103 ;
V_4 -> V_11 = V_5 -> V_11 ;
V_4 -> V_94 = V_5 -> V_126 [ V_261 ] ;
V_4 -> V_131 = 0 ;
V_4 -> V_262 = F_3 ;
V_4 -> V_263 = F_8 ;
if ( V_5 -> V_201 > 0 && V_5 -> V_202 > 0 )
F_49 ( V_4 -> V_28 , L_46 ,
V_5 -> V_201 , V_5 -> V_202 ) ;
return 0 ;
}
static void F_171 ( struct V_1 * V_4 )
{
F_87 ( V_4 ) ;
F_172 ( V_4 -> V_29 ) ;
F_172 ( V_4 -> V_31 ) ;
F_173 ( V_4 -> V_4 . V_28 ) ;
}
static void F_174 ( struct V_2 * V_4 , int V_264 )
{
F_27 ( V_4 , V_264 ) ;
}
static void F_175 ( struct V_265 * V_266 , const char * V_39 ,
unsigned V_60 )
{
struct V_1 * V_1 = & V_267 [ V_266 -> V_133 ] ;
struct V_2 * V_4 = & V_1 -> V_4 ;
unsigned short V_268 ;
F_13 ( V_1 ) ;
F_176 ( V_4 , V_39 , V_60 , F_174 ) ;
V_268 = F_28 ( V_4 ) | F_30 ( V_4 ) ;
while ( ( F_21 ( V_4 , V_34 ) & V_268 ) != V_268 )
F_177 () ;
F_17 ( V_1 ) ;
}
static int T_3 F_178 ( struct V_265 * V_266 , char * V_269 )
{
struct V_1 * V_1 ;
struct V_2 * V_4 ;
int V_221 = 115200 ;
int V_268 = 8 ;
int V_81 = 'n' ;
int V_270 = 'n' ;
int V_110 ;
if ( V_266 -> V_133 < 0 || V_266 -> V_133 >= V_271 )
return - V_272 ;
V_1 = & V_267 [ V_266 -> V_133 ] ;
V_4 = & V_1 -> V_4 ;
if ( ! V_4 -> V_42 )
return - V_272 ;
V_110 = F_154 ( V_4 ) ;
if ( F_76 ( V_110 != 0 ) )
return V_110 ;
F_13 ( V_1 ) ;
if ( V_269 )
F_179 ( V_269 , & V_221 , & V_81 , & V_268 , & V_270 ) ;
F_17 ( V_1 ) ;
return F_180 ( V_4 , V_266 , V_221 , V_81 , V_268 , V_270 ) ;
}
static int T_3 F_181 ( struct V_252 * V_273 )
{
struct V_13 * V_14 = V_273 -> V_28 . V_274 ;
if ( V_275 . V_86 )
return - V_276 ;
V_275 . V_133 = V_273 -> V_277 ;
F_164 ( NULL , & V_267 [ V_273 -> V_277 ] , V_273 -> V_277 , V_14 ) ;
F_178 ( & V_275 , V_278 ) ;
if ( ! strstr ( V_278 , L_47 ) )
V_275 . V_103 |= V_279 ;
F_182 ( & V_275 ) ;
return 0 ;
}
static int F_183 ( struct V_178 * V_28 )
{
struct V_1 * V_1 = F_184 ( V_28 ) ;
struct V_2 * V_4 = & V_1 -> V_4 ;
if ( F_185 ( V_4 ) ) {
struct V_7 * V_8 ;
V_1 -> V_280 = F_21 ( V_4 , V_226 ) ;
V_1 -> V_281 = F_21 ( V_4 , V_233 ) ;
V_8 = F_4 ( V_4 , V_142 ) ;
if ( V_8 -> V_9 )
V_1 -> V_282 = F_21 ( V_4 , V_142 ) ;
else
V_1 -> V_282 = 0 ;
}
return 0 ;
}
static int F_186 ( struct V_178 * V_28 )
{
struct V_1 * V_1 = F_184 ( V_28 ) ;
struct V_2 * V_4 = & V_1 -> V_4 ;
if ( F_185 ( V_4 ) ) {
F_145 ( V_4 ) ;
F_23 ( V_4 , V_226 , V_1 -> V_280 ) ;
F_23 ( V_4 , V_233 , V_1 -> V_281 ) ;
if ( V_1 -> V_282 )
F_23 ( V_4 , V_142 , V_1 -> V_282 ) ;
F_23 ( V_4 , V_61 , V_1 -> V_14 -> V_105 ) ;
}
return 0 ;
}
static inline int T_3 F_181 ( struct V_252 * V_273 )
{
return - V_27 ;
}
static int F_187 ( struct V_252 * V_28 )
{
struct V_1 * V_4 = F_188 ( V_28 ) ;
F_189 ( & V_4 -> V_116 ,
V_283 ) ;
F_190 ( & V_284 , & V_4 -> V_4 ) ;
F_171 ( V_4 ) ;
return 0 ;
}
static int T_3 F_191 ( struct V_252 * V_28 ,
unsigned int V_133 ,
struct V_13 * V_5 ,
struct V_1 * V_285 )
{
int V_110 ;
if ( F_76 ( V_133 >= V_271 ) ) {
F_51 ( & V_28 -> V_28 , L_48
L_49 ,
V_133 + 1 , V_271 ) ;
F_51 ( & V_28 -> V_28 , L_50
L_51 ) ;
return - V_27 ;
}
V_110 = F_164 ( V_28 , V_285 , V_133 , V_5 ) ;
if ( V_110 )
return V_110 ;
V_110 = F_192 ( & V_284 , & V_285 -> V_4 ) ;
if ( V_110 ) {
F_171 ( V_285 ) ;
return V_110 ;
}
return 0 ;
}
static int T_3 F_193 ( struct V_252 * V_28 )
{
struct V_13 * V_5 = V_28 -> V_28 . V_274 ;
struct V_1 * V_286 = & V_267 [ V_28 -> V_277 ] ;
int V_110 ;
if ( F_194 ( V_28 ) )
return F_181 ( V_28 ) ;
F_195 ( V_28 , V_286 ) ;
V_110 = F_191 ( V_28 , V_28 -> V_277 , V_5 , V_286 ) ;
if ( V_110 )
return V_110 ;
V_286 -> V_116 . V_287 = F_73 ;
V_110 = F_196 ( & V_286 -> V_116 ,
V_283 ) ;
if ( F_76 ( V_110 < 0 ) ) {
F_171 ( V_286 ) ;
return V_110 ;
}
#ifdef F_197
F_198 () ;
#endif
return 0 ;
}
static int F_199 ( struct V_178 * V_28 )
{
struct V_1 * V_246 = F_184 ( V_28 ) ;
if ( V_246 )
F_200 ( & V_284 , & V_246 -> V_4 ) ;
return 0 ;
}
static int F_201 ( struct V_178 * V_28 )
{
struct V_1 * V_246 = F_184 ( V_28 ) ;
if ( V_246 )
F_202 ( & V_284 , & V_246 -> V_4 ) ;
return 0 ;
}
static int T_7 F_203 ( void )
{
int V_110 ;
F_12 ( V_288 ) ;
V_110 = F_204 ( & V_284 ) ;
if ( F_148 ( V_110 == 0 ) ) {
V_110 = F_205 ( & V_289 ) ;
if ( F_76 ( V_110 ) )
F_206 ( & V_284 ) ;
}
return V_110 ;
}
static void T_8 F_207 ( void )
{
F_208 ( & V_289 ) ;
F_206 ( & V_284 ) ;
}
