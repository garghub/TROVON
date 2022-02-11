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
F_18 ( & V_1 -> V_34 ) ;
V_1 -> V_35 = 0 ;
F_19 ( V_1 -> V_33 ) ;
F_19 ( V_1 -> V_31 ) ;
F_20 ( V_1 -> V_4 . V_30 ) ;
}
static int F_21 ( struct V_2 * V_4 )
{
unsigned short V_36 ;
int V_37 ;
do {
V_36 = F_22 ( V_4 , V_38 ) ;
if ( V_36 & F_23 ( V_4 ) ) {
F_24 ( V_4 , V_38 , F_25 ( V_4 ) ) ;
continue;
}
break;
} while ( 1 );
if ( ! ( V_36 & F_26 ( V_4 ) ) )
return V_39 ;
V_37 = F_22 ( V_4 , V_40 ) ;
F_22 ( V_4 , V_38 ) ;
F_24 ( V_4 , V_38 , F_27 ( V_4 ) ) ;
return V_37 ;
}
static void F_28 ( struct V_2 * V_4 , unsigned char V_37 )
{
unsigned short V_36 ;
do {
V_36 = F_22 ( V_4 , V_38 ) ;
} while ( ! ( V_36 & F_29 ( V_4 ) ) );
F_24 ( V_4 , V_41 , V_37 ) ;
F_24 ( V_4 , V_38 , F_30 ( V_4 ) & ~ F_31 ( V_4 ) ) ;
}
static void F_32 ( struct V_2 * V_4 , unsigned int V_42 )
{
struct V_1 * V_43 = F_1 ( V_4 ) ;
struct V_7 * V_8 = V_44 [ V_43 -> V_14 -> V_16 ] + V_45 ;
if ( V_43 -> V_14 -> V_46 && V_43 -> V_14 -> V_46 -> V_47 ) {
V_43 -> V_14 -> V_46 -> V_47 ( V_4 , V_42 ) ;
return;
}
if ( ! V_8 -> V_9 )
return;
if ( ( V_43 -> V_14 -> V_48 & V_49 ) &&
( ( ! ( V_42 & V_50 ) ) ) ) {
unsigned short V_36 ;
V_36 = F_22 ( V_4 , V_45 ) ;
V_36 &= ~ V_51 ;
V_36 |= V_52 ;
F_24 ( V_4 , V_45 , V_36 ) ;
}
}
static int F_33 ( struct V_2 * V_4 )
{
struct V_7 * V_8 ;
V_8 = F_4 ( V_4 , V_53 ) ;
if ( V_8 -> V_9 )
return F_22 ( V_4 , V_53 ) & ( ( V_4 -> V_54 << 1 ) - 1 ) ;
V_8 = F_4 ( V_4 , V_55 ) ;
if ( V_8 -> V_9 )
return F_22 ( V_4 , V_55 ) >> 8 ;
return ! ( F_22 ( V_4 , V_38 ) & V_56 ) ;
}
static int F_34 ( struct V_2 * V_4 )
{
return V_4 -> V_54 - F_33 ( V_4 ) ;
}
static int F_35 ( struct V_2 * V_4 )
{
struct V_7 * V_8 ;
V_8 = F_4 ( V_4 , V_57 ) ;
if ( V_8 -> V_9 )
return F_22 ( V_4 , V_57 ) & ( ( V_4 -> V_54 << 1 ) - 1 ) ;
V_8 = F_4 ( V_4 , V_55 ) ;
if ( V_8 -> V_9 )
return F_22 ( V_4 , V_55 ) & ( ( V_4 -> V_54 << 1 ) - 1 ) ;
return ( F_22 ( V_4 , V_38 ) & F_26 ( V_4 ) ) != 0 ;
}
static inline int F_36 ( struct V_2 * V_4 )
{
struct V_1 * V_43 = F_1 ( V_4 ) ;
if ( V_43 -> V_14 -> V_58 <= 0 )
return 1 ;
return ! ! F_37 ( ( void V_59 * ) ( V_60 ) V_43 -> V_14 -> V_58 ) ;
}
static void F_38 ( struct V_2 * V_4 )
{
struct V_61 * V_62 = & V_4 -> V_63 -> V_62 ;
unsigned int V_64 = F_39 ( V_4 ) ;
unsigned short V_36 ;
unsigned short V_65 ;
int V_66 ;
V_36 = F_22 ( V_4 , V_38 ) ;
if ( ! ( V_36 & F_29 ( V_4 ) ) ) {
V_65 = F_22 ( V_4 , V_67 ) ;
if ( F_40 ( V_62 ) )
V_65 &= ~ V_68 ;
else
V_65 |= V_68 ;
F_24 ( V_4 , V_67 , V_65 ) ;
return;
}
V_66 = F_34 ( V_4 ) ;
do {
unsigned char V_37 ;
if ( V_4 -> V_69 ) {
V_37 = V_4 -> V_69 ;
V_4 -> V_69 = 0 ;
} else if ( ! F_40 ( V_62 ) && ! V_64 ) {
V_37 = V_62 -> V_70 [ V_62 -> V_71 ] ;
V_62 -> V_71 = ( V_62 -> V_71 + 1 ) & ( V_72 - 1 ) ;
} else {
break;
}
F_24 ( V_4 , V_41 , V_37 ) ;
V_4 -> V_73 . V_74 ++ ;
} while ( -- V_66 > 0 );
F_24 ( V_4 , V_38 , F_30 ( V_4 ) ) ;
if ( F_41 ( V_62 ) < V_75 )
F_42 ( V_4 ) ;
if ( F_40 ( V_62 ) ) {
F_43 ( V_4 ) ;
} else {
V_65 = F_22 ( V_4 , V_67 ) ;
if ( V_4 -> type != V_15 ) {
F_22 ( V_4 , V_38 ) ;
F_24 ( V_4 , V_38 , F_30 ( V_4 ) ) ;
}
V_65 |= V_68 ;
F_24 ( V_4 , V_67 , V_65 ) ;
}
}
static void F_44 ( struct V_2 * V_4 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_76 * V_77 = & V_4 -> V_63 -> V_4 ;
int V_78 , V_66 , V_79 = 0 ;
unsigned short V_36 ;
unsigned char V_80 ;
V_36 = F_22 ( V_4 , V_38 ) ;
if ( ! ( V_36 & F_26 ( V_4 ) ) )
return;
while ( 1 ) {
V_66 = F_45 ( V_77 , F_35 ( V_4 ) ) ;
if ( V_66 == 0 )
break;
if ( V_4 -> type == V_15 ) {
char V_37 = F_22 ( V_4 , V_40 ) ;
if ( F_46 ( V_4 , V_37 ) ||
V_1 -> V_35 )
V_66 = 0 ;
else
F_47 ( V_77 , V_37 , V_81 ) ;
} else {
for ( V_78 = 0 ; V_78 < V_66 ; V_78 ++ ) {
char V_37 = F_22 ( V_4 , V_40 ) ;
V_36 = F_22 ( V_4 , V_38 ) ;
#if F_48 ( V_82 )
if ( V_1 -> V_35 ) {
if ( ( V_37 == 0 ) &&
( V_36 & F_49 ( V_4 ) ) ) {
V_66 -- ; V_78 -- ;
continue;
}
F_50 ( V_4 -> V_30 , L_3 , V_37 ) ;
V_1 -> V_35 = 0 ;
if ( F_51 ( V_37 ) ) {
V_66 -- ; V_78 -- ;
continue;
}
}
#endif
if ( F_46 ( V_4 , V_37 ) ) {
V_66 -- ; V_78 -- ;
continue;
}
if ( V_36 & F_49 ( V_4 ) ) {
V_80 = V_83 ;
V_4 -> V_73 . V_84 ++ ;
F_52 ( V_4 -> V_30 , L_4 ) ;
} else if ( V_36 & F_53 ( V_4 ) ) {
V_80 = V_85 ;
V_4 -> V_73 . V_86 ++ ;
F_52 ( V_4 -> V_30 , L_5 ) ;
} else
V_80 = V_81 ;
F_47 ( V_77 , V_37 , V_80 ) ;
}
}
F_22 ( V_4 , V_38 ) ;
F_24 ( V_4 , V_38 , F_27 ( V_4 ) ) ;
V_79 += V_66 ;
V_4 -> V_73 . V_87 += V_66 ;
}
if ( V_79 ) {
F_54 ( V_77 ) ;
} else {
F_22 ( V_4 , V_38 ) ;
F_24 ( V_4 , V_38 , F_27 ( V_4 ) ) ;
}
}
static inline void F_55 ( struct V_1 * V_4 )
{
F_56 ( & V_4 -> V_34 , V_88 + V_89 ) ;
}
static void F_57 ( unsigned long V_90 )
{
struct V_1 * V_4 = (struct V_1 * ) V_90 ;
if ( F_36 ( & V_4 -> V_4 ) == 0 ) {
V_4 -> V_35 = 1 ;
F_55 ( V_4 ) ;
} else if ( V_4 -> V_35 == 1 ) {
V_4 -> V_35 = 2 ;
F_55 ( V_4 ) ;
} else
V_4 -> V_35 = 0 ;
}
static int F_58 ( struct V_2 * V_4 )
{
int V_79 = 0 ;
unsigned short V_36 = F_22 ( V_4 , V_38 ) ;
struct V_76 * V_77 = & V_4 -> V_63 -> V_4 ;
struct V_1 * V_43 = F_1 ( V_4 ) ;
if ( V_36 & ( 1 << V_43 -> V_91 ) ) {
V_4 -> V_73 . V_92 ++ ;
if ( F_47 ( V_77 , 0 , V_93 ) )
V_79 ++ ;
F_52 ( V_4 -> V_30 , L_6 ) ;
}
if ( V_36 & F_49 ( V_4 ) ) {
if ( F_36 ( V_4 ) == 0 ) {
struct V_1 * V_1 = F_1 ( V_4 ) ;
if ( ! V_1 -> V_35 ) {
V_4 -> V_73 . V_94 ++ ;
V_1 -> V_35 = 1 ;
F_55 ( V_1 ) ;
if ( F_59 ( V_4 ) )
return 0 ;
F_50 ( V_4 -> V_30 , L_7 ) ;
if ( F_47 ( V_77 , 0 , V_95 ) )
V_79 ++ ;
}
} else {
V_4 -> V_73 . V_84 ++ ;
if ( F_47 ( V_77 , 0 , V_83 ) )
V_79 ++ ;
F_52 ( V_4 -> V_30 , L_4 ) ;
}
}
if ( V_36 & F_53 ( V_4 ) ) {
V_4 -> V_73 . V_86 ++ ;
if ( F_47 ( V_77 , 0 , V_85 ) )
V_79 ++ ;
F_52 ( V_4 -> V_30 , L_8 ) ;
}
if ( V_79 )
F_54 ( V_77 ) ;
return V_79 ;
}
static int F_60 ( struct V_2 * V_4 )
{
struct V_76 * V_77 = & V_4 -> V_63 -> V_4 ;
struct V_1 * V_43 = F_1 ( V_4 ) ;
struct V_7 * V_8 ;
int V_79 = 0 ;
V_8 = F_4 ( V_4 , V_96 ) ;
if ( ! V_8 -> V_9 )
return 0 ;
if ( ( F_22 ( V_4 , V_96 ) & ( 1 << V_43 -> V_91 ) ) ) {
F_24 ( V_4 , V_96 , 0 ) ;
V_4 -> V_73 . V_92 ++ ;
F_47 ( V_77 , 0 , V_93 ) ;
F_54 ( V_77 ) ;
F_52 ( V_4 -> V_30 , L_9 ) ;
V_79 ++ ;
}
return V_79 ;
}
static int F_61 ( struct V_2 * V_4 )
{
int V_79 = 0 ;
unsigned short V_36 = F_22 ( V_4 , V_38 ) ;
struct V_76 * V_77 = & V_4 -> V_63 -> V_4 ;
struct V_1 * V_43 = F_1 ( V_4 ) ;
if ( F_59 ( V_4 ) )
return 0 ;
if ( ! V_43 -> V_35 && V_36 & F_62 ( V_4 ) ) {
#if F_48 ( V_82 )
V_43 -> V_35 = 1 ;
#endif
V_4 -> V_73 . V_94 ++ ;
if ( F_47 ( V_77 , 0 , V_95 ) )
V_79 ++ ;
F_50 ( V_4 -> V_30 , L_7 ) ;
}
if ( V_79 )
F_54 ( V_77 ) ;
V_79 += F_60 ( V_4 ) ;
return V_79 ;
}
static T_1 F_63 ( int V_97 , void * V_98 )
{
#ifdef F_64
struct V_2 * V_4 = V_98 ;
struct V_1 * V_43 = F_1 ( V_4 ) ;
if ( V_43 -> V_99 ) {
T_2 V_100 = F_22 ( V_4 , V_67 ) ;
T_2 V_101 = F_22 ( V_4 , V_38 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
F_65 ( V_97 ) ;
V_100 |= 0x4000 ;
} else {
V_100 &= ~ V_102 ;
}
F_24 ( V_4 , V_67 , V_100 ) ;
F_24 ( V_4 , V_38 , V_101 & ~ ( 1 | F_26 ( V_4 ) ) ) ;
F_50 ( V_4 -> V_30 , L_10 ,
V_88 , V_43 -> V_103 ) ;
F_56 ( & V_43 -> V_104 , V_88 + V_43 -> V_103 ) ;
return V_105 ;
}
#endif
F_44 ( V_98 ) ;
return V_105 ;
}
static T_1 F_66 ( int V_97 , void * V_98 )
{
struct V_2 * V_4 = V_98 ;
unsigned long V_106 ;
F_67 ( & V_4 -> V_107 , V_106 ) ;
F_38 ( V_4 ) ;
F_68 ( & V_4 -> V_107 , V_106 ) ;
return V_105 ;
}
static T_1 F_69 ( int V_97 , void * V_98 )
{
struct V_2 * V_4 = V_98 ;
if ( V_4 -> type == V_15 ) {
if ( F_58 ( V_4 ) ) {
F_22 ( V_4 , V_38 ) ;
F_24 ( V_4 , V_38 , F_27 ( V_4 ) ) ;
}
} else {
F_60 ( V_4 ) ;
F_63 ( V_97 , V_98 ) ;
}
F_24 ( V_4 , V_38 , F_25 ( V_4 ) ) ;
F_66 ( V_97 , V_98 ) ;
return V_105 ;
}
static T_1 F_70 ( int V_97 , void * V_98 )
{
struct V_2 * V_4 = V_98 ;
F_61 ( V_4 ) ;
F_24 ( V_4 , V_38 , F_71 ( V_4 ) ) ;
return V_105 ;
}
static inline unsigned long F_72 ( struct V_2 * V_4 )
{
return V_102 | ( F_1 ( V_4 ) -> V_14 -> V_108 & V_109 ) ;
}
static T_1 F_73 ( int V_97 , void * V_98 )
{
unsigned short V_110 , V_111 , V_112 ;
struct V_2 * V_4 = V_98 ;
struct V_1 * V_43 = F_1 ( V_4 ) ;
T_1 V_113 = V_114 ;
V_110 = F_22 ( V_4 , V_38 ) ;
V_111 = F_22 ( V_4 , V_67 ) ;
V_112 = V_111 & F_72 ( V_4 ) ;
if ( ( V_110 & F_29 ( V_4 ) ) && ( V_111 & V_68 ) &&
! V_43 -> V_115 )
V_113 = F_66 ( V_97 , V_98 ) ;
if ( ( ( V_110 & F_26 ( V_4 ) ) || V_43 -> V_99 ) &&
( V_111 & V_102 ) )
V_113 = F_63 ( V_97 , V_98 ) ;
if ( ( V_110 & F_23 ( V_4 ) ) && V_112 )
V_113 = F_69 ( V_97 , V_98 ) ;
if ( ( V_110 & F_62 ( V_4 ) ) && V_112 )
V_113 = F_70 ( V_97 , V_98 ) ;
return V_113 ;
}
static int F_74 ( struct V_116 * V_117 ,
unsigned long V_118 , void * V_5 )
{
struct V_1 * V_1 ;
unsigned long V_106 ;
V_1 = F_2 ( V_117 , struct V_1 , V_119 ) ;
if ( ( V_118 == V_120 ) ||
( V_118 == V_121 ) ) {
struct V_2 * V_4 = & V_1 -> V_4 ;
F_67 ( & V_4 -> V_107 , V_106 ) ;
V_4 -> V_32 = F_16 ( V_1 -> V_31 ) ;
F_68 ( & V_4 -> V_107 , V_106 ) ;
}
return V_122 ;
}
static int F_75 ( struct V_1 * V_4 )
{
struct V_2 * V_123 = & V_4 -> V_4 ;
int V_78 , V_124 , V_113 = 0 ;
for ( V_78 = V_124 = 0 ; V_78 < V_125 ; V_78 ++ , V_124 ++ ) {
struct V_126 * V_127 ;
int V_97 ;
if ( F_76 ( V_4 ) ) {
V_78 = V_128 ;
V_97 = V_123 -> V_97 ;
} else {
V_97 = V_4 -> V_129 [ V_78 ] ;
if ( F_77 ( V_97 < 0 ) )
continue;
}
V_127 = V_126 + V_78 ;
V_4 -> V_130 [ V_124 ] = F_78 ( V_131 , L_11 ,
F_79 ( V_123 -> V_30 ) , V_127 -> V_127 ) ;
if ( ! V_4 -> V_130 [ V_124 ] ) {
F_80 ( V_123 -> V_30 , L_12 ,
V_127 -> V_127 ) ;
goto V_132;
}
V_113 = F_81 ( V_97 , V_127 -> V_133 , V_123 -> V_134 ,
V_4 -> V_130 [ V_124 ] , V_4 ) ;
if ( F_77 ( V_113 ) ) {
F_80 ( V_123 -> V_30 , L_13 , V_127 -> V_127 ) ;
goto V_135;
}
}
return 0 ;
V_135:
while ( -- V_78 >= 0 )
F_82 ( V_4 -> V_129 [ V_78 ] , V_4 ) ;
V_132:
while ( -- V_124 >= 0 )
F_83 ( V_4 -> V_130 [ V_124 ] ) ;
return V_113 ;
}
static void F_84 ( struct V_1 * V_4 )
{
int V_78 ;
for ( V_78 = 0 ; V_78 < V_125 ; V_78 ++ ) {
int V_97 = V_4 -> V_129 [ V_78 ] ;
if ( F_77 ( V_97 < 0 ) )
continue;
F_82 ( V_4 -> V_129 [ V_78 ] , V_4 ) ;
F_83 ( V_4 -> V_130 [ V_78 ] ) ;
if ( F_76 ( V_4 ) ) {
return;
}
}
}
static unsigned int F_85 ( struct V_2 * V_4 )
{
unsigned short V_36 = F_22 ( V_4 , V_38 ) ;
unsigned short V_136 = F_33 ( V_4 ) ;
return ( V_36 & F_31 ( V_4 ) ) && ! V_136 ? V_137 : 0 ;
}
static void F_86 ( struct V_2 * V_4 , unsigned int V_138 )
{
if ( V_138 & V_139 ) {
struct V_7 * V_8 ;
V_8 = F_4 ( V_4 , V_140 ) ;
if ( V_8 -> V_9 )
F_24 ( V_4 , V_140 , F_22 ( V_4 , V_140 ) | 1 ) ;
}
}
static unsigned int F_87 ( struct V_2 * V_4 )
{
return V_141 | V_142 ;
}
static void F_88 ( void * V_143 )
{
struct V_1 * V_43 = V_143 ;
struct V_2 * V_4 = & V_43 -> V_4 ;
struct V_61 * V_62 = & V_4 -> V_63 -> V_62 ;
unsigned long V_106 ;
F_50 ( V_4 -> V_30 , L_14 , V_144 , V_4 -> line ) ;
F_67 ( & V_4 -> V_107 , V_106 ) ;
V_62 -> V_71 += F_89 ( & V_43 -> V_145 ) ;
V_62 -> V_71 &= V_72 - 1 ;
V_4 -> V_73 . V_74 += F_89 ( & V_43 -> V_145 ) ;
F_90 ( V_43 -> V_146 ) ;
V_43 -> V_146 = NULL ;
if ( F_41 ( V_62 ) < V_75 )
F_42 ( V_4 ) ;
if ( ! F_40 ( V_62 ) ) {
V_43 -> V_147 = 0 ;
F_91 ( & V_43 -> V_148 ) ;
} else {
V_43 -> V_147 = - V_29 ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
T_2 V_65 = F_22 ( V_4 , V_67 ) ;
F_24 ( V_4 , V_67 , V_65 & ~ V_68 ) ;
}
}
F_68 ( & V_4 -> V_107 , V_106 ) ;
}
static int F_92 ( struct V_1 * V_43 , T_3 V_66 )
{
struct V_2 * V_4 = & V_43 -> V_4 ;
struct V_76 * V_77 = & V_4 -> V_63 -> V_4 ;
int V_78 , V_149 , V_150 ;
V_150 = F_45 ( V_77 , V_66 ) ;
if ( V_43 -> V_151 == V_43 -> V_152 [ 0 ] ) {
V_149 = 0 ;
} else if ( V_43 -> V_151 == V_43 -> V_152 [ 1 ] ) {
V_149 = 1 ;
} else {
F_80 ( V_4 -> V_30 , L_15 , V_43 -> V_151 ) ;
return 0 ;
}
if ( V_150 < V_66 )
F_93 ( V_4 -> V_30 , L_16 ,
V_66 - V_150 ) ;
if ( ! V_150 )
return V_150 ;
for ( V_78 = 0 ; V_78 < V_150 ; V_78 ++ )
F_47 ( V_77 , ( ( V_153 * ) F_94 ( & V_43 -> V_154 [ V_149 ] ) ) [ V_78 ] ,
V_81 ) ;
V_4 -> V_73 . V_87 += V_150 ;
return V_150 ;
}
static void F_95 ( void * V_143 )
{
struct V_1 * V_43 = V_143 ;
struct V_2 * V_4 = & V_43 -> V_4 ;
unsigned long V_106 ;
int V_66 ;
F_50 ( V_4 -> V_30 , L_17 , V_144 , V_4 -> line , V_43 -> V_151 ) ;
F_67 ( & V_4 -> V_107 , V_106 ) ;
V_66 = F_92 ( V_43 , V_43 -> V_155 ) ;
F_56 ( & V_43 -> V_104 , V_88 + V_43 -> V_103 ) ;
F_68 ( & V_4 -> V_107 , V_106 ) ;
if ( V_66 )
F_54 ( & V_4 -> V_63 -> V_4 ) ;
F_91 ( & V_43 -> V_156 ) ;
}
static void F_96 ( struct V_1 * V_43 , bool V_157 )
{
struct V_158 * V_159 = V_43 -> V_99 ;
struct V_2 * V_4 = & V_43 -> V_4 ;
V_43 -> V_99 = NULL ;
V_43 -> V_152 [ 0 ] = V_43 -> V_152 [ 1 ] = - V_29 ;
F_97 ( V_159 ) ;
if ( F_98 ( & V_43 -> V_154 [ 0 ] ) )
F_99 ( V_4 -> V_30 , V_43 -> V_155 * 2 ,
F_94 ( & V_43 -> V_154 [ 0 ] ) , F_98 ( & V_43 -> V_154 [ 0 ] ) ) ;
if ( V_157 )
F_100 ( V_4 ) ;
}
static void F_101 ( struct V_1 * V_43 , bool V_157 )
{
struct V_158 * V_159 = V_43 -> V_115 ;
struct V_2 * V_4 = & V_43 -> V_4 ;
V_43 -> V_115 = NULL ;
V_43 -> V_147 = - V_29 ;
F_97 ( V_159 ) ;
if ( V_157 )
F_102 ( V_4 ) ;
}
static void F_103 ( struct V_1 * V_43 )
{
struct V_158 * V_159 = V_43 -> V_99 ;
int V_78 ;
for ( V_78 = 0 ; V_78 < 2 ; V_78 ++ ) {
struct V_160 * V_161 = & V_43 -> V_154 [ V_78 ] ;
struct V_162 * V_127 ;
V_127 = F_104 ( V_159 ,
V_161 , 1 , V_163 , V_164 ) ;
if ( V_127 ) {
V_43 -> V_165 [ V_78 ] = V_127 ;
V_127 -> V_166 = F_95 ;
V_127 -> V_167 = V_43 ;
V_43 -> V_152 [ V_78 ] = V_127 -> V_168 ( V_127 ) ;
}
if ( ! V_127 || V_43 -> V_152 [ V_78 ] < 0 ) {
if ( V_78 ) {
F_90 ( V_43 -> V_165 [ 0 ] ) ;
V_43 -> V_152 [ 0 ] = - V_29 ;
}
if ( V_127 ) {
F_90 ( V_127 ) ;
V_43 -> V_152 [ V_78 ] = - V_29 ;
}
F_93 ( V_43 -> V_4 . V_30 ,
L_18 ) ;
F_96 ( V_43 , true ) ;
return;
}
F_50 ( V_43 -> V_4 . V_30 , L_19 , V_144 ,
V_43 -> V_152 [ V_78 ] , V_78 ) ;
}
V_43 -> V_151 = V_43 -> V_152 [ 0 ] ;
F_105 ( V_159 ) ;
}
static void F_106 ( struct V_169 * V_170 )
{
struct V_1 * V_43 = F_2 ( V_170 , struct V_1 , V_156 ) ;
struct V_2 * V_4 = & V_43 -> V_4 ;
struct V_162 * V_127 ;
int V_171 ;
if ( V_43 -> V_151 == V_43 -> V_152 [ 0 ] ) {
V_171 = 0 ;
} else if ( V_43 -> V_151 == V_43 -> V_152 [ 1 ] ) {
V_171 = 1 ;
} else {
F_80 ( V_4 -> V_30 , L_15 , V_43 -> V_151 ) ;
return;
}
V_127 = V_43 -> V_165 [ V_171 ] ;
if ( F_107 ( V_43 -> V_99 , V_43 -> V_151 , NULL , NULL ) !=
V_172 ) {
struct V_158 * V_159 = V_43 -> V_99 ;
struct V_173 * V_174 = F_2 ( V_127 ,
struct V_173 , V_175 ) ;
unsigned long V_106 ;
int V_66 ;
V_159 -> V_176 -> V_177 ( V_159 , V_178 , 0 ) ;
F_50 ( V_4 -> V_30 , L_20 ,
V_174 -> V_179 , V_174 -> V_180 ) ;
F_67 ( & V_4 -> V_107 , V_106 ) ;
V_66 = F_92 ( V_43 , V_174 -> V_179 ) ;
F_68 ( & V_4 -> V_107 , V_106 ) ;
if ( V_66 )
F_54 ( & V_4 -> V_63 -> V_4 ) ;
F_103 ( V_43 ) ;
return;
}
V_43 -> V_152 [ V_171 ] = V_127 -> V_168 ( V_127 ) ;
if ( V_43 -> V_152 [ V_171 ] < 0 ) {
F_93 ( V_4 -> V_30 , L_21 ) ;
F_96 ( V_43 , true ) ;
return;
}
V_43 -> V_151 = V_43 -> V_152 [ ! V_171 ] ;
F_50 ( V_4 -> V_30 , L_22 , V_144 ,
V_43 -> V_152 [ V_171 ] , V_171 , V_43 -> V_151 ) ;
}
static void F_108 ( struct V_169 * V_170 )
{
struct V_1 * V_43 = F_2 ( V_170 , struct V_1 , V_148 ) ;
struct V_162 * V_127 ;
struct V_158 * V_159 = V_43 -> V_115 ;
struct V_2 * V_4 = & V_43 -> V_4 ;
struct V_61 * V_62 = & V_4 -> V_63 -> V_62 ;
struct V_160 * V_161 = & V_43 -> V_145 ;
F_109 ( & V_4 -> V_107 ) ;
V_161 -> V_6 = V_62 -> V_71 & ( V_72 - 1 ) ;
F_98 ( V_161 ) = ( F_98 ( V_161 ) & ~ ( V_72 - 1 ) ) +
V_161 -> V_6 ;
F_89 ( V_161 ) = F_110 ( ( int ) F_111 ( V_62 -> V_181 , V_62 -> V_71 , V_72 ) ,
F_112 ( V_62 -> V_181 , V_62 -> V_71 , V_72 ) ) ;
F_113 ( & V_4 -> V_107 ) ;
F_114 ( ! F_89 ( V_161 ) ) ;
V_127 = F_104 ( V_159 ,
V_161 , V_43 -> V_182 , V_183 ,
V_164 | V_184 ) ;
if ( ! V_127 ) {
F_101 ( V_43 , true ) ;
return;
}
F_115 ( V_4 -> V_30 , V_161 , 1 , V_185 ) ;
F_109 ( & V_4 -> V_107 ) ;
V_43 -> V_146 = V_127 ;
V_127 -> V_166 = F_88 ;
V_127 -> V_167 = V_43 ;
F_113 ( & V_4 -> V_107 ) ;
V_43 -> V_147 = V_127 -> V_168 ( V_127 ) ;
if ( V_43 -> V_147 < 0 ) {
F_93 ( V_4 -> V_30 , L_23 ) ;
F_101 ( V_43 , true ) ;
return;
}
F_50 ( V_4 -> V_30 , L_24 , V_144 ,
V_62 -> V_70 , V_62 -> V_71 , V_62 -> V_181 , V_43 -> V_147 ) ;
F_105 ( V_159 ) ;
}
static void F_102 ( struct V_2 * V_4 )
{
struct V_1 * V_43 = F_1 ( V_4 ) ;
unsigned short V_65 ;
#ifdef F_64
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
T_2 V_171 , V_100 = F_22 ( V_4 , V_67 ) ;
if ( V_43 -> V_115 )
V_171 = V_100 | 0x8000 ;
else
V_171 = V_100 & ~ 0x8000 ;
if ( V_171 != V_100 )
F_24 ( V_4 , V_67 , V_171 ) ;
}
if ( V_43 -> V_115 && ! F_40 ( & V_43 -> V_4 . V_63 -> V_62 ) &&
V_43 -> V_147 < 0 ) {
V_43 -> V_147 = 0 ;
F_91 ( & V_43 -> V_148 ) ;
}
#endif
if ( ! V_43 -> V_115 || V_4 -> type == V_20 || V_4 -> type == V_22 ) {
V_65 = F_22 ( V_4 , V_67 ) ;
F_24 ( V_4 , V_67 , V_65 | V_68 ) ;
}
}
static void F_43 ( struct V_2 * V_4 )
{
unsigned short V_65 ;
V_65 = F_22 ( V_4 , V_67 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 )
V_65 &= ~ 0x8000 ;
V_65 &= ~ V_68 ;
F_24 ( V_4 , V_67 , V_65 ) ;
}
static void F_100 ( struct V_2 * V_4 )
{
unsigned short V_65 ;
V_65 = F_22 ( V_4 , V_67 ) | F_72 ( V_4 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 )
V_65 &= ~ 0x4000 ;
F_24 ( V_4 , V_67 , V_65 ) ;
}
static void F_116 ( struct V_2 * V_4 )
{
unsigned short V_65 ;
V_65 = F_22 ( V_4 , V_67 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 )
V_65 &= ~ 0x4000 ;
V_65 &= ~ F_72 ( V_4 ) ;
F_24 ( V_4 , V_67 , V_65 ) ;
}
static void F_117 ( struct V_2 * V_4 )
{
}
static void F_118 ( struct V_2 * V_4 , int V_186 )
{
struct V_1 * V_43 = F_1 ( V_4 ) ;
struct V_7 * V_8 = V_44 [ V_43 -> V_14 -> V_16 ] + V_45 ;
unsigned short V_108 , V_187 ;
if ( ! V_8 -> V_9 ) {
return;
}
V_187 = F_22 ( V_4 , V_45 ) ;
V_108 = F_22 ( V_4 , V_67 ) ;
if ( V_186 == - 1 ) {
V_187 = ( V_187 | V_188 ) & ~ V_189 ;
V_108 &= ~ V_190 ;
} else {
V_187 = ( V_187 | V_189 ) & ~ V_188 ;
V_108 |= V_190 ;
}
F_24 ( V_4 , V_45 , V_187 ) ;
F_24 ( V_4 , V_67 , V_108 ) ;
}
static bool F_119 ( struct V_158 * V_159 , void * V_191 )
{
struct V_192 * V_193 = V_191 ;
F_50 ( V_159 -> V_176 -> V_30 , L_25 , V_144 ,
V_193 -> V_194 . V_195 ) ;
V_159 -> V_196 = & V_193 -> V_194 ;
return true ;
}
static void F_120 ( unsigned long V_143 )
{
struct V_1 * V_43 = (struct V_1 * ) V_143 ;
struct V_2 * V_4 = & V_43 -> V_4 ;
T_2 V_100 = F_22 ( V_4 , V_67 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
V_100 &= ~ 0x4000 ;
F_121 ( V_43 -> V_129 [ V_197 ] ) ;
}
F_24 ( V_4 , V_67 , V_100 | V_102 ) ;
F_50 ( V_4 -> V_30 , L_26 ) ;
F_91 ( & V_43 -> V_156 ) ;
}
static void F_122 ( struct V_2 * V_4 )
{
struct V_1 * V_43 = F_1 ( V_4 ) ;
struct V_192 * V_193 ;
struct V_158 * V_159 ;
T_4 V_198 ;
int V_199 ;
F_50 ( V_4 -> V_30 , L_27 , V_144 ,
V_4 -> line ) ;
if ( V_43 -> V_14 -> V_200 <= 0 || V_43 -> V_14 -> V_201 <= 0 )
return;
F_123 ( V_198 ) ;
F_124 ( V_202 , V_198 ) ;
V_193 = & V_43 -> V_203 ;
V_193 -> V_194 . V_195 = V_43 -> V_14 -> V_200 ;
V_43 -> V_147 = - V_29 ;
V_159 = F_125 ( V_198 , F_119 , V_193 ) ;
F_50 ( V_4 -> V_30 , L_28 , V_144 , V_159 ) ;
if ( V_159 ) {
V_43 -> V_115 = V_159 ;
F_126 ( & V_43 -> V_145 , 1 ) ;
F_114 ( ( V_60 ) V_4 -> V_63 -> V_62 . V_70 & ~ V_204 ) ;
F_127 ( & V_43 -> V_145 , F_128 ( V_4 -> V_63 -> V_62 . V_70 ) ,
V_72 ,
( V_60 ) V_4 -> V_63 -> V_62 . V_70 & ~ V_204 ) ;
V_199 = F_129 ( V_4 -> V_30 , & V_43 -> V_145 , 1 , V_185 ) ;
if ( ! V_199 )
F_101 ( V_43 , false ) ;
else
F_50 ( V_4 -> V_30 , L_29 , V_144 ,
F_89 ( & V_43 -> V_145 ) , V_4 -> V_63 -> V_62 . V_70 ,
& F_98 ( & V_43 -> V_145 ) ) ;
V_43 -> V_182 = V_199 ;
F_130 ( & V_43 -> V_148 , F_108 ) ;
}
V_193 = & V_43 -> V_205 ;
V_193 -> V_194 . V_195 = V_43 -> V_14 -> V_201 ;
V_159 = F_125 ( V_198 , F_119 , V_193 ) ;
F_50 ( V_4 -> V_30 , L_30 , V_144 , V_159 ) ;
if ( V_159 ) {
T_5 V_206 [ 2 ] ;
void * V_70 [ 2 ] ;
int V_78 ;
V_43 -> V_99 = V_159 ;
V_43 -> V_155 = 2 * F_131 ( 16 , ( int ) V_4 -> V_54 ) ;
V_70 [ 0 ] = F_132 ( V_4 -> V_30 , V_43 -> V_155 * 2 ,
& V_206 [ 0 ] , V_131 ) ;
if ( ! V_70 [ 0 ] ) {
F_93 ( V_4 -> V_30 ,
L_31 ) ;
F_96 ( V_43 , true ) ;
return;
}
V_70 [ 1 ] = V_70 [ 0 ] + V_43 -> V_155 ;
V_206 [ 1 ] = V_206 [ 0 ] + V_43 -> V_155 ;
for ( V_78 = 0 ; V_78 < 2 ; V_78 ++ ) {
struct V_160 * V_161 = & V_43 -> V_154 [ V_78 ] ;
F_126 ( V_161 , 1 ) ;
F_127 ( V_161 , F_128 ( V_70 [ V_78 ] ) , V_43 -> V_155 ,
( V_60 ) V_70 [ V_78 ] & ~ V_204 ) ;
F_98 ( V_161 ) = V_206 [ V_78 ] ;
}
F_130 ( & V_43 -> V_156 , F_106 ) ;
F_133 ( & V_43 -> V_104 , F_120 , ( unsigned long ) V_43 ) ;
F_103 ( V_43 ) ;
}
}
static void F_134 ( struct V_2 * V_4 )
{
struct V_1 * V_43 = F_1 ( V_4 ) ;
if ( V_43 -> V_115 )
F_101 ( V_43 , false ) ;
if ( V_43 -> V_99 )
F_96 ( V_43 , false ) ;
}
static inline void F_122 ( struct V_2 * V_4 )
{
}
static inline void F_134 ( struct V_2 * V_4 )
{
}
static int F_135 ( struct V_2 * V_4 )
{
struct V_1 * V_43 = F_1 ( V_4 ) ;
unsigned long V_106 ;
int V_113 ;
F_50 ( V_4 -> V_30 , L_14 , V_144 , V_4 -> line ) ;
V_113 = F_75 ( V_43 ) ;
if ( F_77 ( V_113 < 0 ) )
return V_113 ;
F_122 ( V_4 ) ;
F_67 ( & V_4 -> V_107 , V_106 ) ;
F_102 ( V_4 ) ;
F_100 ( V_4 ) ;
F_68 ( & V_4 -> V_107 , V_106 ) ;
return 0 ;
}
static void F_136 ( struct V_2 * V_4 )
{
struct V_1 * V_43 = F_1 ( V_4 ) ;
unsigned long V_106 ;
F_50 ( V_4 -> V_30 , L_14 , V_144 , V_4 -> line ) ;
F_67 ( & V_4 -> V_107 , V_106 ) ;
F_116 ( V_4 ) ;
F_43 ( V_4 ) ;
F_68 ( & V_4 -> V_107 , V_106 ) ;
F_134 ( V_4 ) ;
F_84 ( V_43 ) ;
}
static unsigned int F_137 ( struct V_1 * V_43 , unsigned int V_207 ,
unsigned long V_208 )
{
if ( V_43 -> V_209 )
return F_138 ( V_208 , V_43 -> V_209 * V_207 ) - 1 ;
F_139 ( 1 ) ;
return ( ( V_208 + 16 * V_207 ) / ( 32 * V_207 ) - 1 ) ;
}
static void F_140 ( unsigned int V_207 , unsigned long V_208 ,
int * V_210 , unsigned int * V_211 ,
unsigned int * V_212 )
{
int V_213 , V_37 , V_214 , V_215 ;
int V_216 = 1000 ;
for ( V_213 = 8 ; V_213 <= 32 ; V_213 ++ ) {
for ( V_37 = 0 ; V_37 <= 3 ; V_37 ++ ) {
V_214 = V_208 / ( V_213 * ( 1 << ( 2 * V_37 + 1 ) ) * V_207 ) - 1 ;
if ( V_214 < 0 || V_214 > 255 )
continue;
V_215 = V_208 / ( ( V_214 + 1 ) * V_207 * V_213 *
( 1 << ( 2 * V_37 + 1 ) ) / 1000 ) - 1000 ;
if ( V_216 > V_215 ) {
V_216 = V_215 ;
* V_210 = V_214 ;
* V_211 = V_213 - 1 ;
* V_212 = V_37 ;
}
}
}
if ( V_216 == 1000 ) {
F_139 ( 1 ) ;
* V_210 = 255 ;
* V_211 = 15 ;
* V_212 = 0 ;
}
}
static void F_141 ( struct V_2 * V_4 )
{
struct V_7 * V_8 ;
unsigned int V_36 ;
do {
V_36 = F_22 ( V_4 , V_38 ) ;
} while ( ! ( V_36 & F_31 ( V_4 ) ) );
F_24 ( V_4 , V_67 , 0x00 ) ;
V_8 = F_4 ( V_4 , V_140 ) ;
if ( V_8 -> V_9 )
F_24 ( V_4 , V_140 , V_217 | V_218 ) ;
}
static void F_142 ( struct V_2 * V_4 , struct V_219 * V_220 ,
struct V_219 * V_221 )
{
struct V_1 * V_43 = F_1 ( V_4 ) ;
struct V_7 * V_8 ;
unsigned int V_222 , V_223 , V_224 , V_212 = 0 ;
int V_225 = - 1 ;
unsigned int V_211 = 15 ;
V_224 = V_4 -> V_32 ? V_4 -> V_32 / 16 : 115200 ;
V_222 = F_143 ( V_4 , V_220 , V_221 , 0 , V_224 ) ;
if ( F_144 ( V_222 && V_4 -> V_32 ) ) {
if ( V_43 -> V_14 -> type == V_26 ) {
F_140 ( V_222 , V_4 -> V_32 , & V_225 , & V_211 ,
& V_212 ) ;
} else {
V_225 = F_137 ( V_43 , V_222 , V_4 -> V_32 ) ;
for ( V_212 = 0 ; V_225 >= 256 && V_212 <= 3 ; V_212 ++ )
V_225 >>= 2 ;
}
}
F_13 ( V_43 ) ;
F_141 ( V_4 ) ;
V_223 = F_22 ( V_4 , V_226 ) & 3 ;
if ( ( V_220 -> V_227 & V_228 ) == V_229 )
V_223 |= 0x40 ;
if ( V_220 -> V_227 & V_230 )
V_223 |= 0x20 ;
if ( V_220 -> V_227 & V_231 )
V_223 |= 0x30 ;
if ( V_220 -> V_227 & V_232 )
V_223 |= 0x08 ;
F_145 ( V_4 , V_220 -> V_227 , V_222 ) ;
F_50 ( V_4 -> V_30 , L_32 ,
V_144 , V_223 , V_212 , V_225 , V_43 -> V_14 -> V_108 ) ;
if ( V_225 >= 0 ) {
F_24 ( V_4 , V_226 , ( V_223 & ~ 3 ) | V_212 ) ;
F_24 ( V_4 , V_233 , V_225 ) ;
V_8 = F_4 ( V_4 , V_234 ) ;
if ( V_8 -> V_9 )
F_24 ( V_4 , V_234 , V_211 | V_235 ) ;
F_146 ( ( 1000000 + ( V_222 - 1 ) ) / V_222 ) ;
} else
F_24 ( V_4 , V_226 , V_223 ) ;
F_32 ( V_4 , V_220 -> V_227 ) ;
V_8 = F_4 ( V_4 , V_140 ) ;
if ( V_8 -> V_9 ) {
unsigned short V_65 = F_22 ( V_4 , V_140 ) ;
if ( V_43 -> V_14 -> V_48 & V_49 ) {
if ( V_220 -> V_227 & V_50 )
V_65 |= V_236 ;
else
V_65 &= ~ V_236 ;
}
V_65 &= ~ ( V_217 | V_218 ) ;
F_24 ( V_4 , V_140 , V_65 ) ;
}
F_24 ( V_4 , V_67 , V_43 -> V_14 -> V_108 ) ;
#ifdef F_64
if ( V_43 -> V_99 ) {
V_43 -> V_103 = ( V_4 -> V_237 - V_238 / 50 ) * V_43 -> V_155 * 3 /
V_4 -> V_54 / 2 ;
F_50 ( V_4 -> V_30 ,
L_33 ,
V_43 -> V_103 * 1000 / V_238 , V_4 -> V_237 ) ;
if ( V_43 -> V_103 < F_147 ( 20 ) )
V_43 -> V_103 = F_147 ( 20 ) ;
}
#endif
if ( ( V_220 -> V_227 & V_239 ) != 0 )
F_100 ( V_4 ) ;
F_17 ( V_43 ) ;
}
static void F_148 ( struct V_2 * V_4 , unsigned int V_63 ,
unsigned int V_240 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
switch ( V_63 ) {
case 3 :
F_17 ( V_1 ) ;
break;
default:
F_13 ( V_1 ) ;
break;
}
}
static const char * F_149 ( struct V_2 * V_4 )
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
case V_26 :
return L_39 ;
}
return NULL ;
}
static inline unsigned long F_150 ( struct V_2 * V_4 )
{
if ( V_4 -> type == V_26 )
return 96 ;
else
return 64 ;
}
static int F_151 ( struct V_2 * V_4 )
{
unsigned long V_9 = F_150 ( V_4 ) ;
if ( V_4 -> V_10 )
return 0 ;
if ( V_4 -> V_106 & V_241 ) {
V_4 -> V_10 = F_152 ( V_4 -> V_242 , V_9 ) ;
if ( F_77 ( ! V_4 -> V_10 ) ) {
F_80 ( V_4 -> V_30 , L_40 , V_4 -> line ) ;
return - V_243 ;
}
} else {
V_4 -> V_10 = ( void V_59 * ) V_4 -> V_242 ;
}
return 0 ;
}
static void F_153 ( struct V_2 * V_4 )
{
if ( V_4 -> V_106 & V_241 ) {
F_154 ( V_4 -> V_10 ) ;
V_4 -> V_10 = NULL ;
}
F_155 ( V_4 -> V_242 , F_150 ( V_4 ) ) ;
}
static int F_156 ( struct V_2 * V_4 )
{
unsigned long V_9 = F_150 ( V_4 ) ;
struct V_244 * V_245 ;
int V_113 ;
V_245 = F_157 ( V_4 -> V_242 , V_9 , F_79 ( V_4 -> V_30 ) ) ;
if ( F_77 ( V_245 == NULL ) )
return - V_246 ;
V_113 = F_151 ( V_4 ) ;
if ( F_77 ( V_113 != 0 ) ) {
F_158 ( V_245 ) ;
return V_113 ;
}
return 0 ;
}
static void F_159 ( struct V_2 * V_4 , int V_106 )
{
if ( V_106 & V_247 ) {
struct V_1 * V_248 = F_1 ( V_4 ) ;
V_4 -> type = V_248 -> V_14 -> type ;
F_156 ( V_4 ) ;
}
}
static int F_160 ( struct V_2 * V_4 , struct V_249 * V_250 )
{
if ( V_250 -> V_251 < 2400 )
return - V_29 ;
return 0 ;
}
static int F_161 ( struct V_252 * V_30 ,
struct V_1 * V_1 , unsigned int V_253 ,
struct V_13 * V_5 , bool V_254 )
{
struct V_2 * V_4 = & V_1 -> V_4 ;
const struct V_244 * V_245 ;
unsigned int V_209 ;
unsigned int V_78 ;
int V_113 ;
V_1 -> V_14 = V_5 ;
V_4 -> V_46 = & V_255 ;
V_4 -> V_256 = V_257 ;
V_4 -> line = V_253 ;
V_245 = F_162 ( V_30 , V_258 , 0 ) ;
if ( V_245 == NULL )
return - V_259 ;
V_4 -> V_242 = V_245 -> V_260 ;
for ( V_78 = 0 ; V_78 < F_163 ( V_1 -> V_129 ) ; ++ V_78 )
V_1 -> V_129 [ V_78 ] = F_164 ( V_30 , V_78 ) ;
if ( V_1 -> V_129 [ 0 ] < 0 )
return - V_243 ;
if ( V_1 -> V_129 [ 1 ] < 0 ) {
V_1 -> V_129 [ 1 ] = V_1 -> V_129 [ 0 ] ;
V_1 -> V_129 [ 2 ] = V_1 -> V_129 [ 0 ] ;
V_1 -> V_129 [ 3 ] = V_1 -> V_129 [ 0 ] ;
}
if ( V_5 -> V_16 == V_261 ) {
V_113 = F_11 ( V_5 ) ;
if ( F_77 ( V_113 ) )
return V_113 ;
}
switch ( V_5 -> type ) {
case V_22 :
V_4 -> V_54 = 256 ;
V_1 -> V_91 = 9 ;
V_209 = 16 ;
break;
case V_26 :
V_4 -> V_54 = 128 ;
V_209 = 0 ;
V_1 -> V_91 = 0 ;
break;
case V_20 :
V_4 -> V_54 = 64 ;
V_1 -> V_91 = 9 ;
V_209 = 16 ;
break;
case V_24 :
V_4 -> V_54 = 16 ;
if ( V_5 -> V_16 == V_262 ) {
V_1 -> V_91 = 9 ;
V_209 = 16 ;
} else {
V_1 -> V_91 = 0 ;
V_209 = 32 ;
}
break;
default:
V_4 -> V_54 = 1 ;
V_1 -> V_91 = 5 ;
V_209 = 32 ;
break;
}
V_1 -> V_209 = V_5 -> V_209 ? V_5 -> V_209
: V_209 ;
if ( ! V_254 ) {
V_1 -> V_31 = F_165 ( & V_30 -> V_30 , L_41 ) ;
if ( F_166 ( V_1 -> V_31 ) ) {
V_1 -> V_31 = F_165 ( & V_30 -> V_30 , L_42 ) ;
if ( F_166 ( V_1 -> V_31 ) ) {
F_80 ( & V_30 -> V_30 , L_43 ) ;
return F_167 ( V_1 -> V_31 ) ;
}
}
V_1 -> V_33 = F_165 ( & V_30 -> V_30 , L_44 ) ;
if ( F_166 ( V_1 -> V_33 ) )
V_1 -> V_33 = NULL ;
V_4 -> V_30 = & V_30 -> V_30 ;
F_168 ( & V_30 -> V_30 ) ;
}
V_1 -> V_34 . V_90 = ( unsigned long ) V_1 ;
V_1 -> V_34 . V_263 = F_57 ;
F_169 ( & V_1 -> V_34 ) ;
V_1 -> V_264 = ( V_5 -> type == V_15 ) ?
V_265 : V_266 ;
V_1 -> V_264 |= 1 << V_1 -> V_91 ;
V_4 -> type = V_5 -> type ;
V_4 -> V_106 = V_267 | V_5 -> V_106 ;
V_4 -> V_11 = V_5 -> V_11 ;
V_4 -> V_97 = V_1 -> V_129 [ V_197 ] ;
V_4 -> V_134 = 0 ;
V_4 -> V_268 = F_3 ;
V_4 -> V_269 = F_8 ;
if ( V_5 -> V_200 > 0 && V_5 -> V_201 > 0 )
F_50 ( V_4 -> V_30 , L_45 ,
V_5 -> V_200 , V_5 -> V_201 ) ;
return 0 ;
}
static void F_170 ( struct V_1 * V_4 )
{
F_171 ( V_4 -> V_31 ) ;
F_171 ( V_4 -> V_33 ) ;
F_172 ( V_4 -> V_4 . V_30 ) ;
}
static void F_173 ( struct V_2 * V_4 , int V_270 )
{
F_28 ( V_4 , V_270 ) ;
}
static void F_174 ( struct V_271 * V_272 , const char * V_43 ,
unsigned V_66 )
{
struct V_1 * V_1 = & V_273 [ V_272 -> V_253 ] ;
struct V_2 * V_4 = & V_1 -> V_4 ;
unsigned short V_274 , V_65 ;
unsigned long V_106 ;
int V_275 = 1 ;
F_175 ( V_106 ) ;
if ( V_4 -> V_276 )
V_275 = 0 ;
else if ( V_277 )
V_275 = F_176 ( & V_4 -> V_107 ) ;
else
F_177 ( & V_4 -> V_107 ) ;
V_65 = F_22 ( V_4 , V_67 ) ;
F_24 ( V_4 , V_67 , V_1 -> V_14 -> V_108 ) ;
F_178 ( V_4 , V_43 , V_66 , F_173 ) ;
V_274 = F_29 ( V_4 ) | F_31 ( V_4 ) ;
while ( ( F_22 ( V_4 , V_38 ) & V_274 ) != V_274 )
F_179 () ;
F_24 ( V_4 , V_67 , V_65 ) ;
if ( V_275 )
F_180 ( & V_4 -> V_107 ) ;
F_181 ( V_106 ) ;
}
static int F_182 ( struct V_271 * V_272 , char * V_278 )
{
struct V_1 * V_1 ;
struct V_2 * V_4 ;
int V_222 = 115200 ;
int V_274 = 8 ;
int V_86 = 'n' ;
int V_279 = 'n' ;
int V_113 ;
if ( V_272 -> V_253 < 0 || V_272 -> V_253 >= V_280 )
return - V_281 ;
V_1 = & V_273 [ V_272 -> V_253 ] ;
V_4 = & V_1 -> V_4 ;
if ( ! V_4 -> V_46 )
return - V_281 ;
V_113 = F_151 ( V_4 ) ;
if ( F_77 ( V_113 != 0 ) )
return V_113 ;
if ( V_278 )
F_183 ( V_278 , & V_222 , & V_86 , & V_274 , & V_279 ) ;
return F_184 ( V_4 , V_272 , V_222 , V_86 , V_274 , V_279 ) ;
}
static int F_185 ( struct V_252 * V_282 )
{
struct V_13 * V_14 = F_186 ( & V_282 -> V_30 ) ;
if ( V_283 . V_90 )
return - V_284 ;
V_283 . V_253 = V_282 -> V_285 ;
F_161 ( V_282 , & V_273 [ V_282 -> V_285 ] , V_282 -> V_285 , V_14 , true ) ;
F_182 ( & V_283 , V_286 ) ;
if ( ! strstr ( V_286 , L_46 ) )
V_283 . V_106 |= V_287 ;
F_187 ( & V_283 ) ;
return 0 ;
}
static inline int F_185 ( struct V_252 * V_282 )
{
return - V_29 ;
}
static int F_188 ( struct V_252 * V_30 )
{
struct V_1 * V_4 = F_189 ( V_30 ) ;
F_190 ( & V_4 -> V_119 ,
V_288 ) ;
F_191 ( & V_289 , & V_4 -> V_4 ) ;
F_170 ( V_4 ) ;
return 0 ;
}
static struct V_13 *
F_192 ( struct V_252 * V_282 , unsigned int * V_290 )
{
struct V_291 * V_292 = V_282 -> V_30 . V_293 ;
const struct V_294 * V_295 ;
const struct V_296 * V_297 ;
struct V_13 * V_5 ;
int V_285 ;
if ( ! F_193 ( V_298 ) || ! V_292 )
return NULL ;
V_295 = F_194 ( V_299 , V_282 -> V_30 . V_293 ) ;
if ( ! V_295 )
return NULL ;
V_297 = V_295 -> V_90 ;
V_5 = F_195 ( & V_282 -> V_30 , sizeof( struct V_13 ) , V_131 ) ;
if ( ! V_5 ) {
F_80 ( & V_282 -> V_30 , L_47 ) ;
return NULL ;
}
V_285 = F_196 ( V_292 , L_48 ) ;
if ( V_285 < 0 ) {
F_80 ( & V_282 -> V_30 , L_49 , V_285 ) ;
return NULL ;
}
* V_290 = V_285 ;
V_5 -> V_106 = V_241 | V_300 ;
V_5 -> type = V_297 -> type ;
V_5 -> V_16 = V_297 -> V_16 ;
V_5 -> V_108 = V_301 | V_190 ;
return V_5 ;
}
static int F_197 ( struct V_252 * V_30 ,
unsigned int V_253 ,
struct V_13 * V_5 ,
struct V_1 * V_302 )
{
int V_113 ;
if ( F_77 ( V_253 >= V_280 ) ) {
F_52 ( & V_30 -> V_30 , L_50
L_51 ,
V_253 + 1 , V_280 ) ;
F_52 ( & V_30 -> V_30 , L_52
L_53 ) ;
return - V_29 ;
}
V_113 = F_161 ( V_30 , V_302 , V_253 , V_5 , false ) ;
if ( V_113 )
return V_113 ;
V_113 = F_198 ( & V_289 , & V_302 -> V_4 ) ;
if ( V_113 ) {
F_170 ( V_302 ) ;
return V_113 ;
}
return 0 ;
}
static int F_199 ( struct V_252 * V_30 )
{
struct V_13 * V_5 ;
struct V_1 * V_303 ;
unsigned int V_290 ;
int V_113 ;
if ( F_200 ( V_30 ) )
return F_185 ( V_30 ) ;
if ( V_30 -> V_30 . V_293 ) {
V_5 = F_192 ( V_30 , & V_290 ) ;
if ( V_5 == NULL )
return - V_29 ;
} else {
V_5 = V_30 -> V_30 . V_304 ;
if ( V_5 == NULL ) {
F_80 ( & V_30 -> V_30 , L_54 ) ;
return - V_29 ;
}
V_290 = V_30 -> V_285 ;
}
V_303 = & V_273 [ V_290 ] ;
F_201 ( V_30 , V_303 ) ;
V_113 = F_197 ( V_30 , V_290 , V_5 , V_303 ) ;
if ( V_113 )
return V_113 ;
V_303 -> V_119 . V_305 = F_74 ;
V_113 = F_202 ( & V_303 -> V_119 ,
V_288 ) ;
if ( F_77 ( V_113 < 0 ) ) {
F_170 ( V_303 ) ;
return V_113 ;
}
#ifdef F_203
F_204 () ;
#endif
return 0 ;
}
static int F_205 ( struct V_176 * V_30 )
{
struct V_1 * V_248 = F_206 ( V_30 ) ;
if ( V_248 )
F_207 ( & V_289 , & V_248 -> V_4 ) ;
return 0 ;
}
static int F_208 ( struct V_176 * V_30 )
{
struct V_1 * V_248 = F_206 ( V_30 ) ;
if ( V_248 )
F_209 ( & V_289 , & V_248 -> V_4 ) ;
return 0 ;
}
static int T_6 F_210 ( void )
{
int V_113 ;
F_12 ( V_306 ) ;
V_113 = F_211 ( & V_289 ) ;
if ( F_144 ( V_113 == 0 ) ) {
V_113 = F_212 ( & V_307 ) ;
if ( F_77 ( V_113 ) )
F_213 ( & V_289 ) ;
}
return V_113 ;
}
static void T_7 F_214 ( void )
{
F_215 ( & V_307 ) ;
F_213 ( & V_289 ) ;
}
