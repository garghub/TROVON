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
case V_26 :
V_14 -> V_16 = V_27 ;
break;
default:
F_12 ( V_28 L_2 ) ;
return - V_29 ;
}
return 0 ;
}
static void F_13 ( struct V_1 * V_1 )
{
if ( ! V_1 -> V_4 . V_30 )
return;
F_14 ( V_1 -> V_4 . V_30 ) ;
F_15 ( V_1 -> V_31 ) ;
V_1 -> V_4 . V_32 = F_16 ( V_1 -> V_31 ) ;
F_15 ( V_1 -> V_33 ) ;
}
static void F_17 ( struct V_1 * V_1 )
{
if ( ! V_1 -> V_4 . V_30 )
return;
F_18 ( V_1 -> V_33 ) ;
F_18 ( V_1 -> V_31 ) ;
F_19 ( V_1 -> V_4 . V_30 ) ;
}
static int F_20 ( struct V_2 * V_4 )
{
unsigned short V_34 ;
int V_35 ;
do {
V_34 = F_21 ( V_4 , V_36 ) ;
if ( V_34 & F_22 ( V_4 ) ) {
F_23 ( V_4 , V_36 , F_24 ( V_4 ) ) ;
continue;
}
break;
} while ( 1 );
if ( ! ( V_34 & F_25 ( V_4 ) ) )
return V_37 ;
V_35 = F_21 ( V_4 , V_38 ) ;
F_21 ( V_4 , V_36 ) ;
F_23 ( V_4 , V_36 , F_26 ( V_4 ) ) ;
return V_35 ;
}
static void F_27 ( struct V_2 * V_4 , unsigned char V_35 )
{
unsigned short V_34 ;
do {
V_34 = F_21 ( V_4 , V_36 ) ;
} while ( ! ( V_34 & F_28 ( V_4 ) ) );
F_23 ( V_4 , V_39 , V_35 ) ;
F_23 ( V_4 , V_36 , F_29 ( V_4 ) & ~ F_30 ( V_4 ) ) ;
}
static void F_31 ( struct V_2 * V_4 , unsigned int V_40 )
{
struct V_1 * V_41 = F_1 ( V_4 ) ;
struct V_7 * V_8 = V_42 [ V_41 -> V_14 -> V_16 ] + V_43 ;
if ( V_41 -> V_14 -> V_44 && V_41 -> V_14 -> V_44 -> V_45 ) {
V_41 -> V_14 -> V_44 -> V_45 ( V_4 , V_40 ) ;
return;
}
if ( ! V_8 -> V_9 )
return;
if ( ( V_41 -> V_14 -> V_46 & V_47 ) &&
( ( ! ( V_40 & V_48 ) ) ) ) {
unsigned short V_34 ;
V_34 = F_21 ( V_4 , V_43 ) ;
V_34 &= ~ V_49 ;
V_34 |= V_50 ;
F_23 ( V_4 , V_43 , V_34 ) ;
}
}
static int F_32 ( struct V_2 * V_4 )
{
struct V_7 * V_8 ;
V_8 = F_4 ( V_4 , V_51 ) ;
if ( V_8 -> V_9 )
return F_21 ( V_4 , V_51 ) & ( ( V_4 -> V_52 << 1 ) - 1 ) ;
V_8 = F_4 ( V_4 , V_53 ) ;
if ( V_8 -> V_9 )
return F_21 ( V_4 , V_53 ) >> 8 ;
return ! ( F_21 ( V_4 , V_36 ) & V_54 ) ;
}
static int F_33 ( struct V_2 * V_4 )
{
return V_4 -> V_52 - F_32 ( V_4 ) ;
}
static int F_34 ( struct V_2 * V_4 )
{
struct V_7 * V_8 ;
V_8 = F_4 ( V_4 , V_55 ) ;
if ( V_8 -> V_9 )
return F_21 ( V_4 , V_55 ) & ( ( V_4 -> V_52 << 1 ) - 1 ) ;
V_8 = F_4 ( V_4 , V_53 ) ;
if ( V_8 -> V_9 )
return F_21 ( V_4 , V_53 ) & ( ( V_4 -> V_52 << 1 ) - 1 ) ;
return ( F_21 ( V_4 , V_36 ) & F_25 ( V_4 ) ) != 0 ;
}
static inline int F_35 ( struct V_2 * V_4 )
{
struct V_1 * V_41 = F_1 ( V_4 ) ;
if ( V_41 -> V_14 -> V_56 <= 0 )
return 1 ;
return ! ! F_36 ( ( void V_57 * ) V_41 -> V_14 -> V_56 ) ;
}
static void F_37 ( struct V_2 * V_4 )
{
struct V_58 * V_59 = & V_4 -> V_60 -> V_59 ;
unsigned int V_61 = F_38 ( V_4 ) ;
unsigned short V_34 ;
unsigned short V_62 ;
int V_63 ;
V_34 = F_21 ( V_4 , V_36 ) ;
if ( ! ( V_34 & F_28 ( V_4 ) ) ) {
V_62 = F_21 ( V_4 , V_64 ) ;
if ( F_39 ( V_59 ) )
V_62 &= ~ V_65 ;
else
V_62 |= V_65 ;
F_23 ( V_4 , V_64 , V_62 ) ;
return;
}
V_63 = F_33 ( V_4 ) ;
do {
unsigned char V_35 ;
if ( V_4 -> V_66 ) {
V_35 = V_4 -> V_66 ;
V_4 -> V_66 = 0 ;
} else if ( ! F_39 ( V_59 ) && ! V_61 ) {
V_35 = V_59 -> V_67 [ V_59 -> V_68 ] ;
V_59 -> V_68 = ( V_59 -> V_68 + 1 ) & ( V_69 - 1 ) ;
} else {
break;
}
F_23 ( V_4 , V_39 , V_35 ) ;
V_4 -> V_70 . V_71 ++ ;
} while ( -- V_63 > 0 );
F_23 ( V_4 , V_36 , F_29 ( V_4 ) ) ;
if ( F_40 ( V_59 ) < V_72 )
F_41 ( V_4 ) ;
if ( F_39 ( V_59 ) ) {
F_42 ( V_4 ) ;
} else {
V_62 = F_21 ( V_4 , V_64 ) ;
if ( V_4 -> type != V_15 ) {
F_21 ( V_4 , V_36 ) ;
F_23 ( V_4 , V_36 , F_29 ( V_4 ) ) ;
}
V_62 |= V_65 ;
F_23 ( V_4 , V_64 , V_62 ) ;
}
}
static void F_43 ( struct V_2 * V_4 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_73 * V_74 = & V_4 -> V_60 -> V_4 ;
int V_75 , V_63 , V_76 = 0 ;
unsigned short V_34 ;
unsigned char V_77 ;
V_34 = F_21 ( V_4 , V_36 ) ;
if ( ! ( V_34 & F_25 ( V_4 ) ) )
return;
while ( 1 ) {
V_63 = F_44 ( V_74 , F_34 ( V_4 ) ) ;
if ( V_63 == 0 )
break;
if ( V_4 -> type == V_15 ) {
char V_35 = F_21 ( V_4 , V_38 ) ;
if ( F_45 ( V_4 , V_35 ) ||
V_1 -> V_78 )
V_63 = 0 ;
else
F_46 ( V_74 , V_35 , V_79 ) ;
} else {
for ( V_75 = 0 ; V_75 < V_63 ; V_75 ++ ) {
char V_35 = F_21 ( V_4 , V_38 ) ;
V_34 = F_21 ( V_4 , V_36 ) ;
#if F_47 ( V_80 )
if ( V_1 -> V_78 ) {
if ( ( V_35 == 0 ) &&
( V_34 & F_48 ( V_4 ) ) ) {
V_63 -- ; V_75 -- ;
continue;
}
F_49 ( V_4 -> V_30 , L_3 , V_35 ) ;
V_1 -> V_78 = 0 ;
if ( F_50 ( V_35 ) ) {
V_63 -- ; V_75 -- ;
continue;
}
}
#endif
if ( F_45 ( V_4 , V_35 ) ) {
V_63 -- ; V_75 -- ;
continue;
}
if ( V_34 & F_48 ( V_4 ) ) {
V_77 = V_81 ;
V_4 -> V_70 . V_82 ++ ;
F_51 ( V_4 -> V_30 , L_4 ) ;
} else if ( V_34 & F_52 ( V_4 ) ) {
V_77 = V_83 ;
V_4 -> V_70 . V_84 ++ ;
F_51 ( V_4 -> V_30 , L_5 ) ;
} else
V_77 = V_79 ;
F_46 ( V_74 , V_35 , V_77 ) ;
}
}
F_21 ( V_4 , V_36 ) ;
F_23 ( V_4 , V_36 , F_26 ( V_4 ) ) ;
V_76 += V_63 ;
V_4 -> V_70 . V_85 += V_63 ;
}
if ( V_76 ) {
F_53 ( V_74 ) ;
} else {
F_21 ( V_4 , V_36 ) ;
F_23 ( V_4 , V_36 , F_26 ( V_4 ) ) ;
}
}
static inline void F_54 ( struct V_1 * V_4 )
{
F_55 ( & V_4 -> V_86 , V_87 + V_88 ) ;
}
static void F_56 ( unsigned long V_89 )
{
struct V_1 * V_4 = (struct V_1 * ) V_89 ;
F_13 ( V_4 ) ;
if ( F_35 ( & V_4 -> V_4 ) == 0 ) {
V_4 -> V_78 = 1 ;
F_54 ( V_4 ) ;
} else if ( V_4 -> V_78 == 1 ) {
V_4 -> V_78 = 2 ;
F_54 ( V_4 ) ;
} else
V_4 -> V_78 = 0 ;
F_17 ( V_4 ) ;
}
static int F_57 ( struct V_2 * V_4 )
{
int V_76 = 0 ;
unsigned short V_34 = F_21 ( V_4 , V_36 ) ;
struct V_73 * V_74 = & V_4 -> V_60 -> V_4 ;
struct V_1 * V_41 = F_1 ( V_4 ) ;
if ( V_41 -> V_14 -> V_90 != V_91 ) {
if ( V_34 & ( 1 << V_41 -> V_14 -> V_90 ) ) {
V_4 -> V_70 . V_92 ++ ;
if ( F_46 ( V_74 , 0 , V_93 ) )
V_76 ++ ;
F_51 ( V_4 -> V_30 , L_6 ) ;
}
}
if ( V_34 & F_48 ( V_4 ) ) {
if ( F_35 ( V_4 ) == 0 ) {
struct V_1 * V_1 = F_1 ( V_4 ) ;
if ( ! V_1 -> V_78 ) {
V_4 -> V_70 . V_94 ++ ;
V_1 -> V_78 = 1 ;
F_54 ( V_1 ) ;
if ( F_58 ( V_4 ) )
return 0 ;
F_49 ( V_4 -> V_30 , L_7 ) ;
if ( F_46 ( V_74 , 0 , V_95 ) )
V_76 ++ ;
}
} else {
V_4 -> V_70 . V_82 ++ ;
if ( F_46 ( V_74 , 0 , V_81 ) )
V_76 ++ ;
F_51 ( V_4 -> V_30 , L_4 ) ;
}
}
if ( V_34 & F_52 ( V_4 ) ) {
V_4 -> V_70 . V_84 ++ ;
if ( F_46 ( V_74 , 0 , V_83 ) )
V_76 ++ ;
F_51 ( V_4 -> V_30 , L_8 ) ;
}
if ( V_76 )
F_53 ( V_74 ) ;
return V_76 ;
}
static int F_59 ( struct V_2 * V_4 )
{
struct V_73 * V_74 = & V_4 -> V_60 -> V_4 ;
struct V_1 * V_41 = F_1 ( V_4 ) ;
struct V_7 * V_8 ;
int V_76 = 0 ;
V_8 = F_4 ( V_4 , V_96 ) ;
if ( ! V_8 -> V_9 )
return 0 ;
if ( ( F_21 ( V_4 , V_96 ) & ( 1 << V_41 -> V_14 -> V_90 ) ) ) {
F_23 ( V_4 , V_96 , 0 ) ;
V_4 -> V_70 . V_92 ++ ;
F_46 ( V_74 , 0 , V_93 ) ;
F_53 ( V_74 ) ;
F_51 ( V_4 -> V_30 , L_9 ) ;
V_76 ++ ;
}
return V_76 ;
}
static int F_60 ( struct V_2 * V_4 )
{
int V_76 = 0 ;
unsigned short V_34 = F_21 ( V_4 , V_36 ) ;
struct V_73 * V_74 = & V_4 -> V_60 -> V_4 ;
struct V_1 * V_41 = F_1 ( V_4 ) ;
if ( F_58 ( V_4 ) )
return 0 ;
if ( ! V_41 -> V_78 && V_34 & F_61 ( V_4 ) ) {
#if F_47 ( V_80 )
V_41 -> V_78 = 1 ;
#endif
V_4 -> V_70 . V_94 ++ ;
if ( F_46 ( V_74 , 0 , V_95 ) )
V_76 ++ ;
F_49 ( V_4 -> V_30 , L_7 ) ;
}
if ( V_76 )
F_53 ( V_74 ) ;
V_76 += F_59 ( V_4 ) ;
return V_76 ;
}
static T_1 F_62 ( int V_97 , void * V_98 )
{
#ifdef F_63
struct V_2 * V_4 = V_98 ;
struct V_1 * V_41 = F_1 ( V_4 ) ;
if ( V_41 -> V_99 ) {
T_2 V_100 = F_21 ( V_4 , V_64 ) ;
T_2 V_101 = F_21 ( V_4 , V_36 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
F_64 ( V_97 ) ;
V_100 |= 0x4000 ;
} else {
V_100 &= ~ V_102 ;
}
F_23 ( V_4 , V_64 , V_100 ) ;
F_23 ( V_4 , V_36 , V_101 & ~ ( 1 | F_25 ( V_4 ) ) ) ;
F_49 ( V_4 -> V_30 , L_10 ,
V_87 , V_41 -> V_103 ) ;
F_55 ( & V_41 -> V_104 , V_87 + V_41 -> V_103 ) ;
return V_105 ;
}
#endif
F_43 ( V_98 ) ;
return V_105 ;
}
static T_1 F_65 ( int V_97 , void * V_98 )
{
struct V_2 * V_4 = V_98 ;
unsigned long V_106 ;
F_66 ( & V_4 -> V_107 , V_106 ) ;
F_37 ( V_4 ) ;
F_67 ( & V_4 -> V_107 , V_106 ) ;
return V_105 ;
}
static T_1 F_68 ( int V_97 , void * V_98 )
{
struct V_2 * V_4 = V_98 ;
if ( V_4 -> type == V_15 ) {
if ( F_57 ( V_4 ) ) {
F_21 ( V_4 , V_36 ) ;
F_23 ( V_4 , V_36 , F_26 ( V_4 ) ) ;
}
} else {
F_59 ( V_4 ) ;
F_62 ( V_97 , V_98 ) ;
}
F_23 ( V_4 , V_36 , F_24 ( V_4 ) ) ;
F_65 ( V_97 , V_98 ) ;
return V_105 ;
}
static T_1 F_69 ( int V_97 , void * V_98 )
{
struct V_2 * V_4 = V_98 ;
F_60 ( V_4 ) ;
F_23 ( V_4 , V_36 , F_70 ( V_4 ) ) ;
return V_105 ;
}
static inline unsigned long F_71 ( struct V_2 * V_4 )
{
return V_102 | ( F_1 ( V_4 ) -> V_14 -> V_108 & V_109 ) ;
}
static T_1 F_72 ( int V_97 , void * V_98 )
{
unsigned short V_110 , V_111 , V_112 ;
struct V_2 * V_4 = V_98 ;
struct V_1 * V_41 = F_1 ( V_4 ) ;
T_1 V_113 = V_114 ;
V_110 = F_21 ( V_4 , V_36 ) ;
V_111 = F_21 ( V_4 , V_64 ) ;
V_112 = V_111 & F_71 ( V_4 ) ;
if ( ( V_110 & F_28 ( V_4 ) ) && ( V_111 & V_65 ) &&
! V_41 -> V_115 )
V_113 = F_65 ( V_97 , V_98 ) ;
if ( ( ( V_110 & F_25 ( V_4 ) ) || V_41 -> V_99 ) &&
( V_111 & V_102 ) )
V_113 = F_62 ( V_97 , V_98 ) ;
if ( ( V_110 & F_22 ( V_4 ) ) && V_112 )
V_113 = F_68 ( V_97 , V_98 ) ;
if ( ( V_110 & F_61 ( V_4 ) ) && V_112 )
V_113 = F_69 ( V_97 , V_98 ) ;
return V_113 ;
}
static int F_73 ( struct V_116 * V_117 ,
unsigned long V_118 , void * V_5 )
{
struct V_1 * V_1 ;
unsigned long V_106 ;
V_1 = F_2 ( V_117 , struct V_1 , V_119 ) ;
if ( ( V_118 == V_120 ) ||
( V_118 == V_121 ) ) {
struct V_2 * V_4 = & V_1 -> V_4 ;
F_66 ( & V_4 -> V_107 , V_106 ) ;
V_4 -> V_32 = F_16 ( V_1 -> V_31 ) ;
F_67 ( & V_4 -> V_107 , V_106 ) ;
}
return V_122 ;
}
static int F_74 ( struct V_1 * V_4 )
{
struct V_2 * V_123 = & V_4 -> V_4 ;
int V_75 , V_124 , V_113 = 0 ;
for ( V_75 = V_124 = 0 ; V_75 < V_125 ; V_75 ++ , V_124 ++ ) {
struct V_126 * V_127 ;
unsigned int V_97 ;
if ( F_75 ( V_4 ) ) {
V_75 = V_128 ;
V_97 = V_123 -> V_97 ;
} else {
V_97 = V_4 -> V_14 -> V_129 [ V_75 ] ;
if ( F_76 ( ! V_97 ) )
continue;
}
V_127 = V_126 + V_75 ;
V_4 -> V_130 [ V_124 ] = F_77 ( V_131 , L_11 ,
F_78 ( V_123 -> V_30 ) , V_127 -> V_127 ) ;
if ( ! V_4 -> V_130 [ V_124 ] ) {
F_79 ( V_123 -> V_30 , L_12 ,
V_127 -> V_127 ) ;
goto V_132;
}
V_113 = F_80 ( V_97 , V_127 -> V_133 , V_123 -> V_134 ,
V_4 -> V_130 [ V_124 ] , V_4 ) ;
if ( F_76 ( V_113 ) ) {
F_79 ( V_123 -> V_30 , L_13 , V_127 -> V_127 ) ;
goto V_135;
}
}
return 0 ;
V_135:
while ( -- V_75 >= 0 )
F_81 ( V_4 -> V_14 -> V_129 [ V_75 ] , V_4 ) ;
V_132:
while ( -- V_124 >= 0 )
F_82 ( V_4 -> V_130 [ V_124 ] ) ;
return V_113 ;
}
static void F_83 ( struct V_1 * V_4 )
{
int V_75 ;
for ( V_75 = 0 ; V_75 < V_125 ; V_75 ++ ) {
unsigned int V_97 = V_4 -> V_14 -> V_129 [ V_75 ] ;
if ( F_76 ( ! V_97 ) )
continue;
F_81 ( V_4 -> V_14 -> V_129 [ V_75 ] , V_4 ) ;
F_82 ( V_4 -> V_130 [ V_75 ] ) ;
if ( F_75 ( V_4 ) ) {
return;
}
}
}
static const char * F_84 ( unsigned int V_136 )
{
return V_137 [ V_136 ] ;
}
static void F_85 ( struct V_1 * V_4 )
{
struct V_2 * V_123 = & V_4 -> V_4 ;
int V_75 ;
if ( ! V_4 -> V_14 )
return;
for ( V_75 = 0 ; V_75 < V_138 ; V_75 ++ ) {
const char * V_127 ;
int V_113 ;
if ( ! V_4 -> V_14 -> V_139 [ V_75 ] )
continue;
V_127 = F_84 ( V_75 ) ;
V_4 -> V_140 [ V_75 ] = F_77 ( V_131 , L_11 ,
F_78 ( V_123 -> V_30 ) , V_127 ) ;
if ( ! V_4 -> V_140 [ V_75 ] )
F_51 ( V_123 -> V_30 , L_14 ,
V_127 ) ;
V_113 = F_86 ( V_4 -> V_14 -> V_139 [ V_75 ] , V_4 -> V_140 [ V_75 ] ) ;
if ( F_76 ( V_113 != 0 ) ) {
F_51 ( V_123 -> V_30 , L_15 , V_127 ) ;
F_82 ( V_4 -> V_140 [ V_75 ] ) ;
}
}
}
static void F_87 ( struct V_1 * V_4 )
{
int V_75 ;
for ( V_75 = 0 ; V_75 < V_138 ; V_75 ++ )
if ( V_4 -> V_14 -> V_139 [ V_75 ] ) {
F_88 ( V_4 -> V_14 -> V_139 [ V_75 ] ) ;
F_82 ( V_4 -> V_140 [ V_75 ] ) ;
}
}
static unsigned int F_89 ( struct V_2 * V_4 )
{
unsigned short V_34 = F_21 ( V_4 , V_36 ) ;
unsigned short V_141 = F_32 ( V_4 ) ;
return ( V_34 & F_30 ( V_4 ) ) && ! V_141 ? V_142 : 0 ;
}
static void F_90 ( struct V_2 * V_4 , unsigned int V_143 )
{
if ( V_143 & V_144 ) {
struct V_7 * V_8 ;
V_8 = F_4 ( V_4 , V_145 ) ;
if ( V_8 -> V_9 )
F_23 ( V_4 , V_145 , F_21 ( V_4 , V_145 ) | 1 ) ;
}
}
static unsigned int F_91 ( struct V_2 * V_4 )
{
return V_146 | V_147 ;
}
static void F_92 ( void * V_148 )
{
struct V_1 * V_41 = V_148 ;
struct V_2 * V_4 = & V_41 -> V_4 ;
struct V_58 * V_59 = & V_4 -> V_60 -> V_59 ;
unsigned long V_106 ;
F_49 ( V_4 -> V_30 , L_16 , V_149 , V_4 -> line ) ;
F_66 ( & V_4 -> V_107 , V_106 ) ;
V_59 -> V_68 += F_93 ( & V_41 -> V_150 ) ;
V_59 -> V_68 &= V_69 - 1 ;
V_4 -> V_70 . V_71 += F_93 ( & V_41 -> V_150 ) ;
F_94 ( V_41 -> V_151 ) ;
V_41 -> V_151 = NULL ;
if ( F_40 ( V_59 ) < V_72 )
F_41 ( V_4 ) ;
if ( ! F_39 ( V_59 ) ) {
V_41 -> V_152 = 0 ;
F_95 ( & V_41 -> V_153 ) ;
} else {
V_41 -> V_152 = - V_29 ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
T_2 V_62 = F_21 ( V_4 , V_64 ) ;
F_23 ( V_4 , V_64 , V_62 & ~ V_65 ) ;
}
}
F_67 ( & V_4 -> V_107 , V_106 ) ;
}
static int F_96 ( struct V_1 * V_41 , T_3 V_63 )
{
struct V_2 * V_4 = & V_41 -> V_4 ;
struct V_73 * V_74 = & V_4 -> V_60 -> V_4 ;
int V_75 , V_154 , V_155 ;
V_155 = F_44 ( V_74 , V_63 ) ;
if ( V_41 -> V_156 == V_41 -> V_157 [ 0 ] ) {
V_154 = 0 ;
} else if ( V_41 -> V_156 == V_41 -> V_157 [ 1 ] ) {
V_154 = 1 ;
} else {
F_79 ( V_4 -> V_30 , L_17 , V_41 -> V_156 ) ;
return 0 ;
}
if ( V_155 < V_63 )
F_97 ( V_4 -> V_30 , L_18 ,
V_63 - V_155 ) ;
if ( ! V_155 )
return V_155 ;
for ( V_75 = 0 ; V_75 < V_155 ; V_75 ++ )
F_46 ( V_74 , ( ( V_158 * ) F_98 ( & V_41 -> V_159 [ V_154 ] ) ) [ V_75 ] ,
V_79 ) ;
V_4 -> V_70 . V_85 += V_155 ;
return V_155 ;
}
static void F_99 ( void * V_148 )
{
struct V_1 * V_41 = V_148 ;
struct V_2 * V_4 = & V_41 -> V_4 ;
unsigned long V_106 ;
int V_63 ;
F_49 ( V_4 -> V_30 , L_19 , V_149 , V_4 -> line , V_41 -> V_156 ) ;
F_66 ( & V_4 -> V_107 , V_106 ) ;
V_63 = F_96 ( V_41 , V_41 -> V_160 ) ;
F_55 ( & V_41 -> V_104 , V_87 + V_41 -> V_103 ) ;
F_67 ( & V_4 -> V_107 , V_106 ) ;
if ( V_63 )
F_53 ( & V_4 -> V_60 -> V_4 ) ;
F_95 ( & V_41 -> V_161 ) ;
}
static void F_100 ( struct V_1 * V_41 , bool V_162 )
{
struct V_163 * V_164 = V_41 -> V_99 ;
struct V_2 * V_4 = & V_41 -> V_4 ;
V_41 -> V_99 = NULL ;
V_41 -> V_157 [ 0 ] = V_41 -> V_157 [ 1 ] = - V_29 ;
F_101 ( V_164 ) ;
if ( F_102 ( & V_41 -> V_159 [ 0 ] ) )
F_103 ( V_4 -> V_30 , V_41 -> V_160 * 2 ,
F_98 ( & V_41 -> V_159 [ 0 ] ) , F_102 ( & V_41 -> V_159 [ 0 ] ) ) ;
if ( V_162 )
F_104 ( V_4 ) ;
}
static void F_105 ( struct V_1 * V_41 , bool V_162 )
{
struct V_163 * V_164 = V_41 -> V_115 ;
struct V_2 * V_4 = & V_41 -> V_4 ;
V_41 -> V_115 = NULL ;
V_41 -> V_152 = - V_29 ;
F_101 ( V_164 ) ;
if ( V_162 )
F_106 ( V_4 ) ;
}
static void F_107 ( struct V_1 * V_41 )
{
struct V_163 * V_164 = V_41 -> V_99 ;
int V_75 ;
for ( V_75 = 0 ; V_75 < 2 ; V_75 ++ ) {
struct V_165 * V_166 = & V_41 -> V_159 [ V_75 ] ;
struct V_167 * V_127 ;
V_127 = F_108 ( V_164 ,
V_166 , 1 , V_168 , V_169 ) ;
if ( V_127 ) {
V_41 -> V_170 [ V_75 ] = V_127 ;
V_127 -> V_171 = F_99 ;
V_127 -> V_172 = V_41 ;
V_41 -> V_157 [ V_75 ] = V_127 -> V_173 ( V_127 ) ;
}
if ( ! V_127 || V_41 -> V_157 [ V_75 ] < 0 ) {
if ( V_75 ) {
F_94 ( V_41 -> V_170 [ 0 ] ) ;
V_41 -> V_157 [ 0 ] = - V_29 ;
}
if ( V_127 ) {
F_94 ( V_127 ) ;
V_41 -> V_157 [ V_75 ] = - V_29 ;
}
F_97 ( V_41 -> V_4 . V_30 ,
L_20 ) ;
F_100 ( V_41 , true ) ;
return;
}
F_49 ( V_41 -> V_4 . V_30 , L_21 , V_149 ,
V_41 -> V_157 [ V_75 ] , V_75 ) ;
}
V_41 -> V_156 = V_41 -> V_157 [ 0 ] ;
F_109 ( V_164 ) ;
}
static void F_110 ( struct V_174 * V_175 )
{
struct V_1 * V_41 = F_2 ( V_175 , struct V_1 , V_161 ) ;
struct V_2 * V_4 = & V_41 -> V_4 ;
struct V_167 * V_127 ;
int V_176 ;
if ( V_41 -> V_156 == V_41 -> V_157 [ 0 ] ) {
V_176 = 0 ;
} else if ( V_41 -> V_156 == V_41 -> V_157 [ 1 ] ) {
V_176 = 1 ;
} else {
F_79 ( V_4 -> V_30 , L_17 , V_41 -> V_156 ) ;
return;
}
V_127 = V_41 -> V_170 [ V_176 ] ;
if ( F_111 ( V_41 -> V_99 , V_41 -> V_156 , NULL , NULL ) !=
V_177 ) {
struct V_163 * V_164 = V_41 -> V_99 ;
struct V_178 * V_179 = F_2 ( V_127 ,
struct V_178 , V_180 ) ;
unsigned long V_106 ;
int V_63 ;
V_164 -> V_181 -> V_182 ( V_164 , V_183 , 0 ) ;
F_49 ( V_4 -> V_30 , L_22 ,
V_179 -> V_184 , V_179 -> V_185 ) ;
F_66 ( & V_4 -> V_107 , V_106 ) ;
V_63 = F_96 ( V_41 , V_179 -> V_184 ) ;
F_67 ( & V_4 -> V_107 , V_106 ) ;
if ( V_63 )
F_53 ( & V_4 -> V_60 -> V_4 ) ;
F_107 ( V_41 ) ;
return;
}
V_41 -> V_157 [ V_176 ] = V_127 -> V_173 ( V_127 ) ;
if ( V_41 -> V_157 [ V_176 ] < 0 ) {
F_97 ( V_4 -> V_30 , L_23 ) ;
F_100 ( V_41 , true ) ;
return;
}
V_41 -> V_156 = V_41 -> V_157 [ ! V_176 ] ;
F_49 ( V_4 -> V_30 , L_24 , V_149 ,
V_41 -> V_157 [ V_176 ] , V_176 , V_41 -> V_156 ) ;
}
static void F_112 ( struct V_174 * V_175 )
{
struct V_1 * V_41 = F_2 ( V_175 , struct V_1 , V_153 ) ;
struct V_167 * V_127 ;
struct V_163 * V_164 = V_41 -> V_115 ;
struct V_2 * V_4 = & V_41 -> V_4 ;
struct V_58 * V_59 = & V_4 -> V_60 -> V_59 ;
struct V_165 * V_166 = & V_41 -> V_150 ;
F_113 ( & V_4 -> V_107 ) ;
V_166 -> V_6 = V_59 -> V_68 & ( V_69 - 1 ) ;
F_102 ( V_166 ) = ( F_102 ( V_166 ) & ~ ( V_69 - 1 ) ) +
V_166 -> V_6 ;
F_93 ( V_166 ) = F_114 ( ( int ) F_115 ( V_59 -> V_186 , V_59 -> V_68 , V_69 ) ,
F_116 ( V_59 -> V_186 , V_59 -> V_68 , V_69 ) ) ;
F_117 ( & V_4 -> V_107 ) ;
F_118 ( ! F_93 ( V_166 ) ) ;
V_127 = F_108 ( V_164 ,
V_166 , V_41 -> V_187 , V_188 ,
V_169 | V_189 ) ;
if ( ! V_127 ) {
F_105 ( V_41 , true ) ;
return;
}
F_119 ( V_4 -> V_30 , V_166 , 1 , V_190 ) ;
F_113 ( & V_4 -> V_107 ) ;
V_41 -> V_151 = V_127 ;
V_127 -> V_171 = F_92 ;
V_127 -> V_172 = V_41 ;
F_117 ( & V_4 -> V_107 ) ;
V_41 -> V_152 = V_127 -> V_173 ( V_127 ) ;
if ( V_41 -> V_152 < 0 ) {
F_97 ( V_4 -> V_30 , L_25 ) ;
F_105 ( V_41 , true ) ;
return;
}
F_49 ( V_4 -> V_30 , L_26 , V_149 ,
V_59 -> V_67 , V_59 -> V_68 , V_59 -> V_186 , V_41 -> V_152 ) ;
F_109 ( V_164 ) ;
}
static void F_106 ( struct V_2 * V_4 )
{
struct V_1 * V_41 = F_1 ( V_4 ) ;
unsigned short V_62 ;
#ifdef F_63
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
T_2 V_176 , V_100 = F_21 ( V_4 , V_64 ) ;
if ( V_41 -> V_115 )
V_176 = V_100 | 0x8000 ;
else
V_176 = V_100 & ~ 0x8000 ;
if ( V_176 != V_100 )
F_23 ( V_4 , V_64 , V_176 ) ;
}
if ( V_41 -> V_115 && ! F_39 ( & V_41 -> V_4 . V_60 -> V_59 ) &&
V_41 -> V_152 < 0 ) {
V_41 -> V_152 = 0 ;
F_95 ( & V_41 -> V_153 ) ;
}
#endif
if ( ! V_41 -> V_115 || V_4 -> type == V_20 || V_4 -> type == V_22 ) {
V_62 = F_21 ( V_4 , V_64 ) ;
F_23 ( V_4 , V_64 , V_62 | V_65 ) ;
}
}
static void F_42 ( struct V_2 * V_4 )
{
unsigned short V_62 ;
V_62 = F_21 ( V_4 , V_64 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 )
V_62 &= ~ 0x8000 ;
V_62 &= ~ V_65 ;
F_23 ( V_4 , V_64 , V_62 ) ;
}
static void F_104 ( struct V_2 * V_4 )
{
unsigned short V_62 ;
V_62 = F_21 ( V_4 , V_64 ) | F_71 ( V_4 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 )
V_62 &= ~ 0x4000 ;
F_23 ( V_4 , V_64 , V_62 ) ;
}
static void F_120 ( struct V_2 * V_4 )
{
unsigned short V_62 ;
V_62 = F_21 ( V_4 , V_64 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 )
V_62 &= ~ 0x4000 ;
V_62 &= ~ F_71 ( V_4 ) ;
F_23 ( V_4 , V_64 , V_62 ) ;
}
static void F_121 ( struct V_2 * V_4 )
{
}
static void F_122 ( struct V_2 * V_4 , int V_191 )
{
struct V_1 * V_41 = F_1 ( V_4 ) ;
struct V_7 * V_8 = V_42 [ V_41 -> V_14 -> V_16 ] + V_43 ;
unsigned short V_108 , V_192 ;
if ( ! V_8 -> V_9 ) {
return;
}
V_192 = F_21 ( V_4 , V_43 ) ;
V_108 = F_21 ( V_4 , V_64 ) ;
if ( V_191 == - 1 ) {
V_192 = ( V_192 | V_193 ) & ~ V_194 ;
V_108 &= ~ V_195 ;
} else {
V_192 = ( V_192 | V_194 ) & ~ V_193 ;
V_108 |= V_195 ;
}
F_23 ( V_4 , V_43 , V_192 ) ;
F_23 ( V_4 , V_64 , V_108 ) ;
}
static bool F_123 ( struct V_163 * V_164 , void * V_196 )
{
struct V_197 * V_198 = V_196 ;
F_49 ( V_164 -> V_181 -> V_30 , L_27 , V_149 ,
V_198 -> V_199 . V_200 ) ;
V_164 -> V_201 = & V_198 -> V_199 ;
return true ;
}
static void F_124 ( unsigned long V_148 )
{
struct V_1 * V_41 = (struct V_1 * ) V_148 ;
struct V_2 * V_4 = & V_41 -> V_4 ;
T_2 V_100 = F_21 ( V_4 , V_64 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
V_100 &= ~ 0x4000 ;
F_125 ( V_41 -> V_14 -> V_129 [ 1 ] ) ;
}
F_23 ( V_4 , V_64 , V_100 | V_102 ) ;
F_49 ( V_4 -> V_30 , L_28 ) ;
F_95 ( & V_41 -> V_161 ) ;
}
static void F_126 ( struct V_2 * V_4 )
{
struct V_1 * V_41 = F_1 ( V_4 ) ;
struct V_197 * V_198 ;
struct V_163 * V_164 ;
T_4 V_202 ;
int V_203 ;
F_49 ( V_4 -> V_30 , L_29 , V_149 ,
V_4 -> line ) ;
if ( V_41 -> V_14 -> V_204 <= 0 || V_41 -> V_14 -> V_205 <= 0 )
return;
F_127 ( V_202 ) ;
F_128 ( V_206 , V_202 ) ;
V_198 = & V_41 -> V_207 ;
V_198 -> V_199 . V_200 = V_41 -> V_14 -> V_204 ;
V_41 -> V_152 = - V_29 ;
V_164 = F_129 ( V_202 , F_123 , V_198 ) ;
F_49 ( V_4 -> V_30 , L_30 , V_149 , V_164 ) ;
if ( V_164 ) {
V_41 -> V_115 = V_164 ;
F_130 ( & V_41 -> V_150 , 1 ) ;
F_118 ( ( int ) V_4 -> V_60 -> V_59 . V_67 & ~ V_208 ) ;
F_131 ( & V_41 -> V_150 , F_132 ( V_4 -> V_60 -> V_59 . V_67 ) ,
V_69 , ( int ) V_4 -> V_60 -> V_59 . V_67 & ~ V_208 ) ;
V_203 = F_133 ( V_4 -> V_30 , & V_41 -> V_150 , 1 , V_190 ) ;
if ( ! V_203 )
F_105 ( V_41 , false ) ;
else
F_49 ( V_4 -> V_30 , L_31 , V_149 ,
F_93 ( & V_41 -> V_150 ) ,
V_4 -> V_60 -> V_59 . V_67 , F_102 ( & V_41 -> V_150 ) ) ;
V_41 -> V_187 = V_203 ;
F_134 ( & V_41 -> V_153 , F_112 ) ;
}
V_198 = & V_41 -> V_209 ;
V_198 -> V_199 . V_200 = V_41 -> V_14 -> V_205 ;
V_164 = F_129 ( V_202 , F_123 , V_198 ) ;
F_49 ( V_4 -> V_30 , L_32 , V_149 , V_164 ) ;
if ( V_164 ) {
T_5 V_210 [ 2 ] ;
void * V_67 [ 2 ] ;
int V_75 ;
V_41 -> V_99 = V_164 ;
V_41 -> V_160 = 2 * F_135 ( 16 , ( int ) V_4 -> V_52 ) ;
V_67 [ 0 ] = F_136 ( V_4 -> V_30 , V_41 -> V_160 * 2 ,
& V_210 [ 0 ] , V_131 ) ;
if ( ! V_67 [ 0 ] ) {
F_97 ( V_4 -> V_30 ,
L_33 ) ;
F_100 ( V_41 , true ) ;
return;
}
V_67 [ 1 ] = V_67 [ 0 ] + V_41 -> V_160 ;
V_210 [ 1 ] = V_210 [ 0 ] + V_41 -> V_160 ;
for ( V_75 = 0 ; V_75 < 2 ; V_75 ++ ) {
struct V_165 * V_166 = & V_41 -> V_159 [ V_75 ] ;
F_130 ( V_166 , 1 ) ;
F_131 ( V_166 , F_132 ( V_67 [ V_75 ] ) , V_41 -> V_160 ,
( int ) V_67 [ V_75 ] & ~ V_208 ) ;
F_102 ( V_166 ) = V_210 [ V_75 ] ;
}
F_134 ( & V_41 -> V_161 , F_110 ) ;
F_137 ( & V_41 -> V_104 , F_124 , ( unsigned long ) V_41 ) ;
F_107 ( V_41 ) ;
}
}
static void F_138 ( struct V_2 * V_4 )
{
struct V_1 * V_41 = F_1 ( V_4 ) ;
if ( V_41 -> V_115 )
F_105 ( V_41 , false ) ;
if ( V_41 -> V_99 )
F_100 ( V_41 , false ) ;
}
static inline void F_126 ( struct V_2 * V_4 )
{
}
static inline void F_138 ( struct V_2 * V_4 )
{
}
static int F_139 ( struct V_2 * V_4 )
{
struct V_1 * V_41 = F_1 ( V_4 ) ;
unsigned long V_106 ;
int V_113 ;
F_49 ( V_4 -> V_30 , L_16 , V_149 , V_4 -> line ) ;
V_113 = F_74 ( V_41 ) ;
if ( F_76 ( V_113 < 0 ) )
return V_113 ;
F_126 ( V_4 ) ;
F_66 ( & V_4 -> V_107 , V_106 ) ;
F_106 ( V_4 ) ;
F_104 ( V_4 ) ;
F_67 ( & V_4 -> V_107 , V_106 ) ;
return 0 ;
}
static void F_140 ( struct V_2 * V_4 )
{
struct V_1 * V_41 = F_1 ( V_4 ) ;
unsigned long V_106 ;
F_49 ( V_4 -> V_30 , L_16 , V_149 , V_4 -> line ) ;
F_66 ( & V_4 -> V_107 , V_106 ) ;
F_120 ( V_4 ) ;
F_42 ( V_4 ) ;
F_67 ( & V_4 -> V_107 , V_106 ) ;
F_138 ( V_4 ) ;
F_83 ( V_41 ) ;
}
static unsigned int F_141 ( unsigned int V_211 , unsigned int V_212 ,
unsigned long V_213 )
{
switch ( V_211 ) {
case V_214 :
return ( ( V_213 + 16 * V_212 ) / ( 16 * V_212 ) - 1 ) ;
case V_215 :
return ( ( V_213 + 16 * V_212 ) / ( 32 * V_212 ) - 1 ) ;
case V_216 :
return ( ( ( V_213 * 2 ) + 16 * V_212 ) / ( 16 * V_212 ) - 1 ) ;
case V_217 :
return ( ( ( V_213 * 2 ) + 16 * V_212 ) / ( 32 * V_212 ) - 1 ) ;
case V_218 :
return ( ( ( V_213 * 1000 / 32 ) / V_212 ) - 1 ) ;
}
F_142 ( 1 ) ;
return ( ( V_213 + 16 * V_212 ) / ( 32 * V_212 ) - 1 ) ;
}
static void F_143 ( unsigned int V_212 , unsigned long V_213 ,
int * V_219 , unsigned int * V_220 ,
unsigned int * V_221 )
{
int V_222 , V_35 , V_223 , V_224 ;
int V_225 = 1000 ;
for ( V_222 = 8 ; V_222 <= 32 ; V_222 ++ ) {
for ( V_35 = 0 ; V_35 <= 3 ; V_35 ++ ) {
V_223 = V_213 / ( V_222 * ( 1 << ( 2 * V_35 + 1 ) ) * V_212 ) - 1 ;
if ( V_223 < 0 || V_223 > 255 )
continue;
V_224 = V_213 / ( ( V_223 + 1 ) * V_212 * V_222 *
( 1 << ( 2 * V_35 + 1 ) ) / 1000 ) - 1000 ;
if ( V_225 > V_224 ) {
V_225 = V_224 ;
* V_219 = V_223 ;
* V_220 = V_222 - 1 ;
* V_221 = V_35 ;
}
}
}
if ( V_225 == 1000 ) {
F_142 ( 1 ) ;
* V_219 = 255 ;
* V_220 = 15 ;
* V_221 = 0 ;
}
}
static void F_144 ( struct V_2 * V_4 )
{
struct V_7 * V_8 ;
unsigned int V_34 ;
do {
V_34 = F_21 ( V_4 , V_36 ) ;
} while ( ! ( V_34 & F_30 ( V_4 ) ) );
F_23 ( V_4 , V_64 , 0x00 ) ;
V_8 = F_4 ( V_4 , V_145 ) ;
if ( V_8 -> V_9 )
F_23 ( V_4 , V_145 , V_226 | V_227 ) ;
}
static void F_145 ( struct V_2 * V_4 , struct V_228 * V_229 ,
struct V_228 * V_230 )
{
struct V_1 * V_41 = F_1 ( V_4 ) ;
struct V_7 * V_8 ;
unsigned int V_231 , V_232 , V_233 , V_221 = 0 ;
int V_234 = - 1 ;
unsigned int V_220 = 15 ;
V_233 = V_4 -> V_32 ? V_4 -> V_32 / 16 : 115200 ;
V_231 = F_146 ( V_4 , V_229 , V_230 , 0 , V_233 ) ;
if ( F_147 ( V_231 && V_4 -> V_32 ) ) {
if ( V_41 -> V_14 -> V_235 == V_236 ) {
F_143 ( V_231 , V_4 -> V_32 , & V_234 , & V_220 ,
& V_221 ) ;
} else {
V_234 = F_141 ( V_41 -> V_14 -> V_235 , V_231 ,
V_4 -> V_32 ) ;
for ( V_221 = 0 ; V_234 >= 256 && V_221 <= 3 ; V_221 ++ )
V_234 >>= 2 ;
}
}
F_13 ( V_41 ) ;
F_144 ( V_4 ) ;
V_232 = F_21 ( V_4 , V_237 ) & 3 ;
if ( ( V_229 -> V_238 & V_239 ) == V_240 )
V_232 |= 0x40 ;
if ( V_229 -> V_238 & V_241 )
V_232 |= 0x20 ;
if ( V_229 -> V_238 & V_242 )
V_232 |= 0x30 ;
if ( V_229 -> V_238 & V_243 )
V_232 |= 0x08 ;
F_148 ( V_4 , V_229 -> V_238 , V_231 ) ;
F_49 ( V_4 -> V_30 , L_34 ,
V_149 , V_232 , V_221 , V_234 , V_41 -> V_14 -> V_108 ) ;
if ( V_234 >= 0 ) {
F_23 ( V_4 , V_237 , ( V_232 & ~ 3 ) | V_221 ) ;
F_23 ( V_4 , V_244 , V_234 ) ;
V_8 = F_4 ( V_4 , V_245 ) ;
if ( V_8 -> V_9 )
F_23 ( V_4 , V_245 , V_220 | V_246 ) ;
F_149 ( ( 1000000 + ( V_231 - 1 ) ) / V_231 ) ;
} else
F_23 ( V_4 , V_237 , V_232 ) ;
F_31 ( V_4 , V_229 -> V_238 ) ;
V_8 = F_4 ( V_4 , V_145 ) ;
if ( V_8 -> V_9 ) {
unsigned short V_62 = F_21 ( V_4 , V_145 ) ;
if ( V_41 -> V_14 -> V_46 & V_47 ) {
if ( V_229 -> V_238 & V_48 )
V_62 |= V_247 ;
else
V_62 &= ~ V_247 ;
}
V_62 &= ~ ( V_226 | V_227 ) ;
F_23 ( V_4 , V_145 , V_62 ) ;
}
F_23 ( V_4 , V_64 , V_41 -> V_14 -> V_108 ) ;
#ifdef F_63
if ( V_41 -> V_99 ) {
V_41 -> V_103 = ( V_4 -> V_248 - V_249 / 50 ) * V_41 -> V_160 * 3 /
V_4 -> V_52 / 2 ;
F_49 ( V_4 -> V_30 ,
L_35 ,
V_41 -> V_103 * 1000 / V_249 , V_4 -> V_248 ) ;
if ( V_41 -> V_103 < F_150 ( 20 ) )
V_41 -> V_103 = F_150 ( 20 ) ;
}
#endif
if ( ( V_229 -> V_238 & V_250 ) != 0 )
F_104 ( V_4 ) ;
F_17 ( V_41 ) ;
}
static void F_151 ( struct V_2 * V_4 , unsigned int V_60 ,
unsigned int V_251 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
switch ( V_60 ) {
case 3 :
F_17 ( V_1 ) ;
break;
default:
F_13 ( V_1 ) ;
break;
}
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
case V_26 :
return L_41 ;
}
return NULL ;
}
static inline unsigned long F_153 ( struct V_2 * V_4 )
{
if ( V_4 -> type == V_26 )
return 96 ;
else
return 64 ;
}
static int F_154 ( struct V_2 * V_4 )
{
unsigned long V_9 = F_153 ( V_4 ) ;
if ( V_4 -> V_10 )
return 0 ;
if ( V_4 -> V_106 & V_252 ) {
V_4 -> V_10 = F_155 ( V_4 -> V_253 , V_9 ) ;
if ( F_76 ( ! V_4 -> V_10 ) ) {
F_79 ( V_4 -> V_30 , L_42 , V_4 -> line ) ;
return - V_254 ;
}
} else {
V_4 -> V_10 = ( void V_57 * ) V_4 -> V_253 ;
}
return 0 ;
}
static void F_156 ( struct V_2 * V_4 )
{
if ( V_4 -> V_106 & V_252 ) {
F_157 ( V_4 -> V_10 ) ;
V_4 -> V_10 = NULL ;
}
F_158 ( V_4 -> V_253 , F_153 ( V_4 ) ) ;
}
static int F_159 ( struct V_2 * V_4 )
{
unsigned long V_9 = F_153 ( V_4 ) ;
struct V_255 * V_256 ;
int V_113 ;
V_256 = F_160 ( V_4 -> V_253 , V_9 , F_78 ( V_4 -> V_30 ) ) ;
if ( F_76 ( V_256 == NULL ) )
return - V_257 ;
V_113 = F_154 ( V_4 ) ;
if ( F_76 ( V_113 != 0 ) ) {
F_161 ( V_256 ) ;
return V_113 ;
}
return 0 ;
}
static void F_162 ( struct V_2 * V_4 , int V_106 )
{
if ( V_106 & V_258 ) {
struct V_1 * V_259 = F_1 ( V_4 ) ;
V_4 -> type = V_259 -> V_14 -> type ;
F_159 ( V_4 ) ;
}
}
static int F_163 ( struct V_2 * V_4 , struct V_260 * V_261 )
{
struct V_1 * V_41 = F_1 ( V_4 ) ;
if ( V_261 -> V_97 != V_41 -> V_14 -> V_129 [ V_262 ] || V_261 -> V_97 > V_263 )
return - V_29 ;
if ( V_261 -> V_264 < 2400 )
return - V_29 ;
return 0 ;
}
static int F_164 ( struct V_265 * V_30 ,
struct V_1 * V_1 ,
unsigned int V_136 ,
struct V_13 * V_5 )
{
struct V_2 * V_4 = & V_1 -> V_4 ;
int V_113 ;
V_1 -> V_14 = V_5 ;
V_4 -> V_44 = & V_266 ;
V_4 -> V_267 = V_268 ;
V_4 -> line = V_136 ;
switch ( V_5 -> type ) {
case V_22 :
V_4 -> V_52 = 256 ;
break;
case V_26 :
V_4 -> V_52 = 128 ;
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
if ( V_5 -> V_16 == V_269 ) {
V_113 = F_11 ( V_5 ) ;
if ( F_76 ( V_113 ) )
return V_113 ;
}
if ( V_30 ) {
V_1 -> V_31 = F_165 ( & V_30 -> V_30 , L_43 ) ;
if ( F_166 ( V_1 -> V_31 ) ) {
V_1 -> V_31 = F_165 ( & V_30 -> V_30 , L_44 ) ;
if ( F_166 ( V_1 -> V_31 ) ) {
F_79 ( & V_30 -> V_30 , L_45 ) ;
return F_167 ( V_1 -> V_31 ) ;
}
}
V_1 -> V_33 = F_165 ( & V_30 -> V_30 , L_46 ) ;
if ( F_166 ( V_1 -> V_33 ) )
V_1 -> V_33 = NULL ;
V_4 -> V_30 = & V_30 -> V_30 ;
F_85 ( V_1 ) ;
F_168 ( & V_30 -> V_30 ) ;
}
V_1 -> V_86 . V_89 = ( unsigned long ) V_1 ;
V_1 -> V_86 . V_270 = F_56 ;
F_169 ( & V_1 -> V_86 ) ;
if ( ! V_5 -> V_271 )
V_5 -> V_271 = ( V_5 -> type == V_15 ) ?
V_272 : V_273 ;
if ( V_5 -> V_90 != V_91 ) {
if ( V_5 -> type == V_15 )
V_5 -> V_90 = 5 ;
else if ( V_5 -> V_235 == V_217 )
V_5 -> V_90 = 9 ;
else
V_5 -> V_90 = 0 ;
V_5 -> V_271 |= ( 1 << V_5 -> V_90 ) ;
}
V_4 -> V_253 = V_5 -> V_253 ;
V_4 -> type = V_5 -> type ;
V_4 -> V_106 = V_5 -> V_106 ;
V_4 -> V_11 = V_5 -> V_11 ;
V_4 -> V_97 = V_5 -> V_129 [ V_274 ] ;
V_4 -> V_134 = 0 ;
V_4 -> V_275 = F_3 ;
V_4 -> V_276 = F_8 ;
if ( V_5 -> V_204 > 0 && V_5 -> V_205 > 0 )
F_49 ( V_4 -> V_30 , L_47 ,
V_5 -> V_204 , V_5 -> V_205 ) ;
return 0 ;
}
static void F_170 ( struct V_1 * V_4 )
{
F_87 ( V_4 ) ;
F_171 ( V_4 -> V_31 ) ;
F_171 ( V_4 -> V_33 ) ;
F_172 ( V_4 -> V_4 . V_30 ) ;
}
static void F_173 ( struct V_2 * V_4 , int V_277 )
{
F_27 ( V_4 , V_277 ) ;
}
static void F_174 ( struct V_278 * V_279 , const char * V_41 ,
unsigned V_63 )
{
struct V_1 * V_1 = & V_280 [ V_279 -> V_136 ] ;
struct V_2 * V_4 = & V_1 -> V_4 ;
unsigned short V_281 , V_62 ;
unsigned long V_106 ;
int V_282 = 1 ;
F_175 ( V_106 ) ;
if ( V_4 -> V_283 )
V_282 = 0 ;
else if ( V_284 )
V_282 = F_176 ( & V_4 -> V_107 ) ;
else
F_177 ( & V_4 -> V_107 ) ;
V_62 = F_21 ( V_4 , V_64 ) ;
F_23 ( V_4 , V_64 , V_1 -> V_14 -> V_108 ) ;
F_178 ( V_4 , V_41 , V_63 , F_173 ) ;
V_281 = F_28 ( V_4 ) | F_30 ( V_4 ) ;
while ( ( F_21 ( V_4 , V_36 ) & V_281 ) != V_281 )
F_179 () ;
F_23 ( V_4 , V_64 , V_62 ) ;
if ( V_282 )
F_180 ( & V_4 -> V_107 ) ;
F_181 ( V_106 ) ;
}
static int F_182 ( struct V_278 * V_279 , char * V_285 )
{
struct V_1 * V_1 ;
struct V_2 * V_4 ;
int V_231 = 115200 ;
int V_281 = 8 ;
int V_84 = 'n' ;
int V_286 = 'n' ;
int V_113 ;
if ( V_279 -> V_136 < 0 || V_279 -> V_136 >= V_287 )
return - V_288 ;
V_1 = & V_280 [ V_279 -> V_136 ] ;
V_4 = & V_1 -> V_4 ;
if ( ! V_4 -> V_44 )
return - V_288 ;
V_113 = F_154 ( V_4 ) ;
if ( F_76 ( V_113 != 0 ) )
return V_113 ;
if ( V_285 )
F_183 ( V_285 , & V_231 , & V_84 , & V_281 , & V_286 ) ;
return F_184 ( V_4 , V_279 , V_231 , V_84 , V_281 , V_286 ) ;
}
static int F_185 ( struct V_265 * V_289 )
{
struct V_13 * V_14 = F_186 ( & V_289 -> V_30 ) ;
if ( V_290 . V_89 )
return - V_291 ;
V_290 . V_136 = V_289 -> V_292 ;
F_164 ( NULL , & V_280 [ V_289 -> V_292 ] , V_289 -> V_292 , V_14 ) ;
F_182 ( & V_290 , V_293 ) ;
if ( ! strstr ( V_293 , L_48 ) )
V_290 . V_106 |= V_294 ;
F_187 ( & V_290 ) ;
return 0 ;
}
static inline int F_185 ( struct V_265 * V_289 )
{
return - V_29 ;
}
static int F_188 ( struct V_265 * V_30 )
{
struct V_1 * V_4 = F_189 ( V_30 ) ;
F_190 ( & V_4 -> V_119 ,
V_295 ) ;
F_191 ( & V_296 , & V_4 -> V_4 ) ;
F_170 ( V_4 ) ;
return 0 ;
}
static int F_192 ( struct V_265 * V_30 ,
unsigned int V_136 ,
struct V_13 * V_5 ,
struct V_1 * V_297 )
{
int V_113 ;
if ( F_76 ( V_136 >= V_287 ) ) {
F_51 ( & V_30 -> V_30 , L_49
L_50 ,
V_136 + 1 , V_287 ) ;
F_51 ( & V_30 -> V_30 , L_51
L_52 ) ;
return - V_29 ;
}
V_113 = F_164 ( V_30 , V_297 , V_136 , V_5 ) ;
if ( V_113 )
return V_113 ;
V_113 = F_193 ( & V_296 , & V_297 -> V_4 ) ;
if ( V_113 ) {
F_170 ( V_297 ) ;
return V_113 ;
}
return 0 ;
}
static int F_194 ( struct V_265 * V_30 )
{
struct V_13 * V_5 = F_186 ( & V_30 -> V_30 ) ;
struct V_1 * V_298 = & V_280 [ V_30 -> V_292 ] ;
int V_113 ;
if ( F_195 ( V_30 ) )
return F_185 ( V_30 ) ;
F_196 ( V_30 , V_298 ) ;
V_113 = F_192 ( V_30 , V_30 -> V_292 , V_5 , V_298 ) ;
if ( V_113 )
return V_113 ;
V_298 -> V_119 . V_299 = F_73 ;
V_113 = F_197 ( & V_298 -> V_119 ,
V_295 ) ;
if ( F_76 ( V_113 < 0 ) ) {
F_170 ( V_298 ) ;
return V_113 ;
}
#ifdef F_198
F_199 () ;
#endif
return 0 ;
}
static int F_200 ( struct V_181 * V_30 )
{
struct V_1 * V_259 = F_201 ( V_30 ) ;
if ( V_259 )
F_202 ( & V_296 , & V_259 -> V_4 ) ;
return 0 ;
}
static int F_203 ( struct V_181 * V_30 )
{
struct V_1 * V_259 = F_201 ( V_30 ) ;
if ( V_259 )
F_204 ( & V_296 , & V_259 -> V_4 ) ;
return 0 ;
}
static int T_6 F_205 ( void )
{
int V_113 ;
F_12 ( V_300 ) ;
V_113 = F_206 ( & V_296 ) ;
if ( F_147 ( V_113 == 0 ) ) {
V_113 = F_207 ( & V_301 ) ;
if ( F_76 ( V_113 ) )
F_208 ( & V_296 ) ;
}
return V_113 ;
}
static void T_7 F_209 ( void )
{
F_210 ( & V_301 ) ;
F_208 ( & V_296 ) ;
}
