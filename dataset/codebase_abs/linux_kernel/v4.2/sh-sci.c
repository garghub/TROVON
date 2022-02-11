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
F_12 ( L_2 ) ;
return - V_28 ;
}
return 0 ;
}
static void F_13 ( struct V_1 * V_1 )
{
if ( ! V_1 -> V_4 . V_29 )
return;
F_14 ( V_1 -> V_4 . V_29 ) ;
F_15 ( V_1 -> V_30 ) ;
V_1 -> V_4 . V_31 = F_16 ( V_1 -> V_30 ) ;
F_15 ( V_1 -> V_32 ) ;
}
static void F_17 ( struct V_1 * V_1 )
{
if ( ! V_1 -> V_4 . V_29 )
return;
F_18 ( & V_1 -> V_33 ) ;
V_1 -> V_34 = 0 ;
F_19 ( V_1 -> V_32 ) ;
F_19 ( V_1 -> V_30 ) ;
F_20 ( V_1 -> V_4 . V_29 ) ;
}
static int F_21 ( struct V_2 * V_4 )
{
unsigned short V_35 ;
int V_36 ;
do {
V_35 = F_22 ( V_4 , V_37 ) ;
if ( V_35 & F_23 ( V_4 ) ) {
F_24 ( V_4 , V_37 , F_25 ( V_4 ) ) ;
continue;
}
break;
} while ( 1 );
if ( ! ( V_35 & F_26 ( V_4 ) ) )
return V_38 ;
V_36 = F_22 ( V_4 , V_39 ) ;
F_22 ( V_4 , V_37 ) ;
F_24 ( V_4 , V_37 , F_27 ( V_4 ) ) ;
return V_36 ;
}
static void F_28 ( struct V_2 * V_4 , unsigned char V_36 )
{
unsigned short V_35 ;
do {
V_35 = F_22 ( V_4 , V_37 ) ;
} while ( ! ( V_35 & F_29 ( V_4 ) ) );
F_24 ( V_4 , V_40 , V_36 ) ;
F_24 ( V_4 , V_37 , F_30 ( V_4 ) & ~ F_31 ( V_4 ) ) ;
}
static void F_32 ( struct V_2 * V_4 , unsigned int V_41 )
{
struct V_1 * V_42 = F_1 ( V_4 ) ;
struct V_7 * V_8 = V_43 [ V_42 -> V_14 -> V_16 ] + V_44 ;
if ( V_42 -> V_14 -> V_45 && V_42 -> V_14 -> V_45 -> V_46 ) {
V_42 -> V_14 -> V_45 -> V_46 ( V_4 , V_41 ) ;
return;
}
if ( ! V_8 -> V_9 )
return;
if ( ( V_42 -> V_14 -> V_47 & V_48 ) &&
( ( ! ( V_41 & V_49 ) ) ) ) {
unsigned short V_35 ;
V_35 = F_22 ( V_4 , V_44 ) ;
V_35 &= ~ V_50 ;
V_35 |= V_51 ;
F_24 ( V_4 , V_44 , V_35 ) ;
}
}
static int F_33 ( struct V_2 * V_4 )
{
struct V_7 * V_8 ;
V_8 = F_4 ( V_4 , V_52 ) ;
if ( V_8 -> V_9 )
return F_22 ( V_4 , V_52 ) & ( ( V_4 -> V_53 << 1 ) - 1 ) ;
V_8 = F_4 ( V_4 , V_54 ) ;
if ( V_8 -> V_9 )
return F_22 ( V_4 , V_54 ) >> 8 ;
return ! ( F_22 ( V_4 , V_37 ) & V_55 ) ;
}
static int F_34 ( struct V_2 * V_4 )
{
return V_4 -> V_53 - F_33 ( V_4 ) ;
}
static int F_35 ( struct V_2 * V_4 )
{
struct V_7 * V_8 ;
V_8 = F_4 ( V_4 , V_56 ) ;
if ( V_8 -> V_9 )
return F_22 ( V_4 , V_56 ) & ( ( V_4 -> V_53 << 1 ) - 1 ) ;
V_8 = F_4 ( V_4 , V_54 ) ;
if ( V_8 -> V_9 )
return F_22 ( V_4 , V_54 ) & ( ( V_4 -> V_53 << 1 ) - 1 ) ;
return ( F_22 ( V_4 , V_37 ) & F_26 ( V_4 ) ) != 0 ;
}
static inline int F_36 ( struct V_2 * V_4 )
{
struct V_1 * V_42 = F_1 ( V_4 ) ;
if ( V_42 -> V_14 -> V_57 <= 0 )
return 1 ;
return ! ! F_37 ( ( void V_58 * ) ( V_59 ) V_42 -> V_14 -> V_57 ) ;
}
static void F_38 ( struct V_2 * V_4 )
{
struct V_60 * V_61 = & V_4 -> V_62 -> V_61 ;
unsigned int V_63 = F_39 ( V_4 ) ;
unsigned short V_35 ;
unsigned short V_64 ;
int V_65 ;
V_35 = F_22 ( V_4 , V_37 ) ;
if ( ! ( V_35 & F_29 ( V_4 ) ) ) {
V_64 = F_22 ( V_4 , V_66 ) ;
if ( F_40 ( V_61 ) )
V_64 &= ~ V_67 ;
else
V_64 |= V_67 ;
F_24 ( V_4 , V_66 , V_64 ) ;
return;
}
V_65 = F_34 ( V_4 ) ;
do {
unsigned char V_36 ;
if ( V_4 -> V_68 ) {
V_36 = V_4 -> V_68 ;
V_4 -> V_68 = 0 ;
} else if ( ! F_40 ( V_61 ) && ! V_63 ) {
V_36 = V_61 -> V_69 [ V_61 -> V_70 ] ;
V_61 -> V_70 = ( V_61 -> V_70 + 1 ) & ( V_71 - 1 ) ;
} else {
break;
}
F_24 ( V_4 , V_40 , V_36 ) ;
V_4 -> V_72 . V_73 ++ ;
} while ( -- V_65 > 0 );
F_24 ( V_4 , V_37 , F_30 ( V_4 ) ) ;
if ( F_41 ( V_61 ) < V_74 )
F_42 ( V_4 ) ;
if ( F_40 ( V_61 ) ) {
F_43 ( V_4 ) ;
} else {
V_64 = F_22 ( V_4 , V_66 ) ;
if ( V_4 -> type != V_15 ) {
F_22 ( V_4 , V_37 ) ;
F_24 ( V_4 , V_37 , F_30 ( V_4 ) ) ;
}
V_64 |= V_67 ;
F_24 ( V_4 , V_66 , V_64 ) ;
}
}
static void F_44 ( struct V_2 * V_4 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_75 * V_76 = & V_4 -> V_62 -> V_4 ;
int V_77 , V_65 , V_78 = 0 ;
unsigned short V_35 ;
unsigned char V_79 ;
V_35 = F_22 ( V_4 , V_37 ) ;
if ( ! ( V_35 & F_26 ( V_4 ) ) )
return;
while ( 1 ) {
V_65 = F_45 ( V_76 , F_35 ( V_4 ) ) ;
if ( V_65 == 0 )
break;
if ( V_4 -> type == V_15 ) {
char V_36 = F_22 ( V_4 , V_39 ) ;
if ( F_46 ( V_4 , V_36 ) ||
V_1 -> V_34 )
V_65 = 0 ;
else
F_47 ( V_76 , V_36 , V_80 ) ;
} else {
for ( V_77 = 0 ; V_77 < V_65 ; V_77 ++ ) {
char V_36 = F_22 ( V_4 , V_39 ) ;
V_35 = F_22 ( V_4 , V_37 ) ;
#if F_48 ( V_81 )
if ( V_1 -> V_34 ) {
if ( ( V_36 == 0 ) &&
( V_35 & F_49 ( V_4 ) ) ) {
V_65 -- ; V_77 -- ;
continue;
}
F_50 ( V_4 -> V_29 , L_3 , V_36 ) ;
V_1 -> V_34 = 0 ;
if ( F_51 ( V_36 ) ) {
V_65 -- ; V_77 -- ;
continue;
}
}
#endif
if ( F_46 ( V_4 , V_36 ) ) {
V_65 -- ; V_77 -- ;
continue;
}
if ( V_35 & F_49 ( V_4 ) ) {
V_79 = V_82 ;
V_4 -> V_72 . V_83 ++ ;
F_52 ( V_4 -> V_29 , L_4 ) ;
} else if ( V_35 & F_53 ( V_4 ) ) {
V_79 = V_84 ;
V_4 -> V_72 . V_85 ++ ;
F_52 ( V_4 -> V_29 , L_5 ) ;
} else
V_79 = V_80 ;
F_47 ( V_76 , V_36 , V_79 ) ;
}
}
F_22 ( V_4 , V_37 ) ;
F_24 ( V_4 , V_37 , F_27 ( V_4 ) ) ;
V_78 += V_65 ;
V_4 -> V_72 . V_86 += V_65 ;
}
if ( V_78 ) {
F_54 ( V_76 ) ;
} else {
F_22 ( V_4 , V_37 ) ;
F_24 ( V_4 , V_37 , F_27 ( V_4 ) ) ;
}
}
static inline void F_55 ( struct V_1 * V_4 )
{
F_56 ( & V_4 -> V_33 , V_87 + V_88 ) ;
}
static void F_57 ( unsigned long V_89 )
{
struct V_1 * V_4 = (struct V_1 * ) V_89 ;
if ( F_36 ( & V_4 -> V_4 ) == 0 ) {
V_4 -> V_34 = 1 ;
F_55 ( V_4 ) ;
} else if ( V_4 -> V_34 == 1 ) {
V_4 -> V_34 = 2 ;
F_55 ( V_4 ) ;
} else
V_4 -> V_34 = 0 ;
}
static int F_58 ( struct V_2 * V_4 )
{
int V_78 = 0 ;
unsigned short V_35 = F_22 ( V_4 , V_37 ) ;
struct V_75 * V_76 = & V_4 -> V_62 -> V_4 ;
struct V_1 * V_42 = F_1 ( V_4 ) ;
if ( V_35 & V_42 -> V_90 ) {
V_4 -> V_72 . V_91 ++ ;
if ( F_47 ( V_76 , 0 , V_92 ) )
V_78 ++ ;
F_52 ( V_4 -> V_29 , L_6 ) ;
}
if ( V_35 & F_49 ( V_4 ) ) {
if ( F_36 ( V_4 ) == 0 ) {
struct V_1 * V_1 = F_1 ( V_4 ) ;
if ( ! V_1 -> V_34 ) {
V_4 -> V_72 . V_93 ++ ;
V_1 -> V_34 = 1 ;
F_55 ( V_1 ) ;
if ( F_59 ( V_4 ) )
return 0 ;
F_50 ( V_4 -> V_29 , L_7 ) ;
if ( F_47 ( V_76 , 0 , V_94 ) )
V_78 ++ ;
}
} else {
V_4 -> V_72 . V_83 ++ ;
if ( F_47 ( V_76 , 0 , V_82 ) )
V_78 ++ ;
F_52 ( V_4 -> V_29 , L_4 ) ;
}
}
if ( V_35 & F_53 ( V_4 ) ) {
V_4 -> V_72 . V_85 ++ ;
if ( F_47 ( V_76 , 0 , V_84 ) )
V_78 ++ ;
F_52 ( V_4 -> V_29 , L_5 ) ;
}
if ( V_78 )
F_54 ( V_76 ) ;
return V_78 ;
}
static int F_60 ( struct V_2 * V_4 )
{
struct V_75 * V_76 = & V_4 -> V_62 -> V_4 ;
struct V_1 * V_42 = F_1 ( V_4 ) ;
struct V_7 * V_8 ;
int V_78 = 0 ;
T_1 V_35 ;
V_8 = F_4 ( V_4 , V_42 -> V_95 ) ;
if ( ! V_8 -> V_9 )
return 0 ;
V_35 = F_22 ( V_4 , V_42 -> V_95 ) ;
if ( V_35 & V_42 -> V_90 ) {
V_35 &= ~ V_42 -> V_90 ;
F_24 ( V_4 , V_42 -> V_95 , V_35 ) ;
V_4 -> V_72 . V_91 ++ ;
F_47 ( V_76 , 0 , V_92 ) ;
F_54 ( V_76 ) ;
F_50 ( V_4 -> V_29 , L_6 ) ;
V_78 ++ ;
}
return V_78 ;
}
static int F_61 ( struct V_2 * V_4 )
{
int V_78 = 0 ;
unsigned short V_35 = F_22 ( V_4 , V_37 ) ;
struct V_75 * V_76 = & V_4 -> V_62 -> V_4 ;
struct V_1 * V_42 = F_1 ( V_4 ) ;
if ( F_59 ( V_4 ) )
return 0 ;
if ( ! V_42 -> V_34 && V_35 & F_62 ( V_4 ) ) {
#if F_48 ( V_81 )
V_42 -> V_34 = 1 ;
#endif
V_4 -> V_72 . V_93 ++ ;
if ( F_47 ( V_76 , 0 , V_94 ) )
V_78 ++ ;
F_50 ( V_4 -> V_29 , L_7 ) ;
}
if ( V_78 )
F_54 ( V_76 ) ;
V_78 += F_60 ( V_4 ) ;
return V_78 ;
}
static T_2 F_63 ( int V_96 , void * V_97 )
{
#ifdef F_64
struct V_2 * V_4 = V_97 ;
struct V_1 * V_42 = F_1 ( V_4 ) ;
if ( V_42 -> V_98 ) {
T_1 V_99 = F_22 ( V_4 , V_66 ) ;
T_1 V_100 = F_22 ( V_4 , V_37 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
F_65 ( V_96 ) ;
V_99 |= V_101 ;
} else {
V_99 &= ~ V_102 ;
}
F_24 ( V_4 , V_66 , V_99 ) ;
F_24 ( V_4 , V_37 , V_100 & ~ ( 1 | F_26 ( V_4 ) ) ) ;
F_50 ( V_4 -> V_29 , L_8 ,
V_87 , V_42 -> V_103 ) ;
F_56 ( & V_42 -> V_104 , V_87 + V_42 -> V_103 ) ;
return V_105 ;
}
#endif
F_44 ( V_97 ) ;
return V_105 ;
}
static T_2 F_66 ( int V_96 , void * V_97 )
{
struct V_2 * V_4 = V_97 ;
unsigned long V_106 ;
F_67 ( & V_4 -> V_107 , V_106 ) ;
F_38 ( V_4 ) ;
F_68 ( & V_4 -> V_107 , V_106 ) ;
return V_105 ;
}
static T_2 F_69 ( int V_96 , void * V_97 )
{
struct V_2 * V_4 = V_97 ;
if ( V_4 -> type == V_15 ) {
if ( F_58 ( V_4 ) ) {
F_22 ( V_4 , V_37 ) ;
F_24 ( V_4 , V_37 , F_27 ( V_4 ) ) ;
}
} else {
F_60 ( V_4 ) ;
F_63 ( V_96 , V_97 ) ;
}
F_24 ( V_4 , V_37 , F_25 ( V_4 ) ) ;
F_66 ( V_96 , V_97 ) ;
return V_105 ;
}
static T_2 F_70 ( int V_96 , void * V_97 )
{
struct V_2 * V_4 = V_97 ;
F_61 ( V_4 ) ;
F_24 ( V_4 , V_37 , F_71 ( V_4 ) ) ;
return V_105 ;
}
static inline unsigned long F_72 ( struct V_2 * V_4 )
{
return V_102 | ( F_1 ( V_4 ) -> V_14 -> V_108 & V_109 ) ;
}
static T_2 F_73 ( int V_96 , void * V_97 )
{
unsigned short V_110 , V_111 , V_112 , V_113 = 0 ;
struct V_2 * V_4 = V_97 ;
struct V_1 * V_42 = F_1 ( V_4 ) ;
T_2 V_114 = V_115 ;
V_110 = F_22 ( V_4 , V_37 ) ;
V_111 = F_22 ( V_4 , V_66 ) ;
if ( V_42 -> V_95 == V_37 )
V_113 = V_110 ;
else {
if ( F_4 ( V_4 , V_42 -> V_95 ) -> V_9 )
V_113 = F_22 ( V_4 , V_42 -> V_95 ) ;
}
V_112 = V_111 & F_72 ( V_4 ) ;
if ( ( V_110 & F_29 ( V_4 ) ) && ( V_111 & V_67 ) &&
! V_42 -> V_116 )
V_114 = F_66 ( V_96 , V_97 ) ;
if ( ( ( V_110 & F_26 ( V_4 ) ) || V_42 -> V_98 ) &&
( V_111 & V_102 ) ) {
if ( V_4 -> type == V_24 || V_4 -> type == V_26 )
F_60 ( V_4 ) ;
V_114 = F_63 ( V_96 , V_97 ) ;
}
if ( ( V_110 & F_23 ( V_4 ) ) && V_112 )
V_114 = F_69 ( V_96 , V_97 ) ;
if ( ( V_110 & F_62 ( V_4 ) ) && V_112 )
V_114 = F_70 ( V_96 , V_97 ) ;
if ( V_113 & V_42 -> V_90 )
F_60 ( V_4 ) ;
return V_114 ;
}
static int F_74 ( struct V_117 * V_118 ,
unsigned long V_119 , void * V_5 )
{
struct V_1 * V_1 ;
unsigned long V_106 ;
V_1 = F_2 ( V_118 , struct V_1 , V_120 ) ;
if ( V_119 == V_121 ) {
struct V_2 * V_4 = & V_1 -> V_4 ;
F_67 ( & V_4 -> V_107 , V_106 ) ;
V_4 -> V_31 = F_16 ( V_1 -> V_30 ) ;
F_68 ( & V_4 -> V_107 , V_106 ) ;
}
return V_122 ;
}
static int F_75 ( struct V_1 * V_4 )
{
struct V_2 * V_123 = & V_4 -> V_4 ;
int V_77 , V_124 , V_114 = 0 ;
for ( V_77 = V_124 = 0 ; V_77 < V_125 ; V_77 ++ , V_124 ++ ) {
struct V_126 * V_127 ;
int V_96 ;
if ( F_76 ( V_4 ) ) {
V_77 = V_128 ;
V_96 = V_123 -> V_96 ;
} else {
V_96 = V_4 -> V_129 [ V_77 ] ;
if ( F_77 ( V_96 < 0 ) )
continue;
}
V_127 = V_126 + V_77 ;
V_4 -> V_130 [ V_124 ] = F_78 ( V_131 , L_9 ,
F_79 ( V_123 -> V_29 ) , V_127 -> V_127 ) ;
if ( ! V_4 -> V_130 [ V_124 ] ) {
F_80 ( V_123 -> V_29 , L_10 ,
V_127 -> V_127 ) ;
goto V_132;
}
V_114 = F_81 ( V_96 , V_127 -> V_133 , V_123 -> V_134 ,
V_4 -> V_130 [ V_124 ] , V_4 ) ;
if ( F_77 ( V_114 ) ) {
F_80 ( V_123 -> V_29 , L_11 , V_127 -> V_127 ) ;
goto V_135;
}
}
return 0 ;
V_135:
while ( -- V_77 >= 0 )
F_82 ( V_4 -> V_129 [ V_77 ] , V_4 ) ;
V_132:
while ( -- V_124 >= 0 )
F_83 ( V_4 -> V_130 [ V_124 ] ) ;
return V_114 ;
}
static void F_84 ( struct V_1 * V_4 )
{
int V_77 ;
for ( V_77 = 0 ; V_77 < V_125 ; V_77 ++ ) {
int V_96 = V_4 -> V_129 [ V_77 ] ;
if ( F_77 ( V_96 < 0 ) )
continue;
F_82 ( V_4 -> V_129 [ V_77 ] , V_4 ) ;
F_83 ( V_4 -> V_130 [ V_77 ] ) ;
if ( F_76 ( V_4 ) ) {
return;
}
}
}
static unsigned int F_85 ( struct V_2 * V_4 )
{
unsigned short V_35 = F_22 ( V_4 , V_37 ) ;
unsigned short V_136 = F_33 ( V_4 ) ;
return ( V_35 & F_31 ( V_4 ) ) && ! V_136 ? V_137 : 0 ;
}
static void F_86 ( struct V_2 * V_4 , unsigned int V_138 )
{
if ( V_138 & V_139 ) {
struct V_7 * V_8 ;
V_8 = F_4 ( V_4 , V_140 ) ;
if ( V_8 -> V_9 )
F_24 ( V_4 , V_140 ,
F_22 ( V_4 , V_140 ) |
V_141 ) ;
}
}
static unsigned int F_87 ( struct V_2 * V_4 )
{
return V_142 | V_143 ;
}
static void F_88 ( void * V_144 )
{
struct V_1 * V_42 = V_144 ;
struct V_2 * V_4 = & V_42 -> V_4 ;
struct V_60 * V_61 = & V_4 -> V_62 -> V_61 ;
unsigned long V_106 ;
F_50 ( V_4 -> V_29 , L_12 , V_145 , V_4 -> line ) ;
F_67 ( & V_4 -> V_107 , V_106 ) ;
V_61 -> V_70 += F_89 ( & V_42 -> V_146 ) ;
V_61 -> V_70 &= V_71 - 1 ;
V_4 -> V_72 . V_73 += F_89 ( & V_42 -> V_146 ) ;
F_90 ( V_42 -> V_147 ) ;
V_42 -> V_147 = NULL ;
if ( F_41 ( V_61 ) < V_74 )
F_42 ( V_4 ) ;
if ( ! F_40 ( V_61 ) ) {
V_42 -> V_148 = 0 ;
F_91 ( & V_42 -> V_149 ) ;
} else {
V_42 -> V_148 = - V_28 ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
T_1 V_64 = F_22 ( V_4 , V_66 ) ;
F_24 ( V_4 , V_66 , V_64 & ~ V_67 ) ;
}
}
F_68 ( & V_4 -> V_107 , V_106 ) ;
}
static int F_92 ( struct V_1 * V_42 , T_3 V_65 )
{
struct V_2 * V_4 = & V_42 -> V_4 ;
struct V_75 * V_76 = & V_4 -> V_62 -> V_4 ;
int V_77 , V_150 , V_151 ;
V_151 = F_45 ( V_76 , V_65 ) ;
if ( V_42 -> V_152 == V_42 -> V_153 [ 0 ] ) {
V_150 = 0 ;
} else if ( V_42 -> V_152 == V_42 -> V_153 [ 1 ] ) {
V_150 = 1 ;
} else {
F_80 ( V_4 -> V_29 , L_13 , V_42 -> V_152 ) ;
return 0 ;
}
if ( V_151 < V_65 )
F_93 ( V_4 -> V_29 , L_14 ,
V_65 - V_151 ) ;
if ( ! V_151 )
return V_151 ;
for ( V_77 = 0 ; V_77 < V_151 ; V_77 ++ )
F_47 ( V_76 , ( ( V_154 * ) F_94 ( & V_42 -> V_155 [ V_150 ] ) ) [ V_77 ] ,
V_80 ) ;
V_4 -> V_72 . V_86 += V_151 ;
return V_151 ;
}
static void F_95 ( void * V_144 )
{
struct V_1 * V_42 = V_144 ;
struct V_2 * V_4 = & V_42 -> V_4 ;
unsigned long V_106 ;
int V_65 ;
F_50 ( V_4 -> V_29 , L_15 ,
V_145 , V_4 -> line , V_42 -> V_152 ) ;
F_67 ( & V_4 -> V_107 , V_106 ) ;
V_65 = F_92 ( V_42 , V_42 -> V_156 ) ;
F_56 ( & V_42 -> V_104 , V_87 + V_42 -> V_103 ) ;
F_68 ( & V_4 -> V_107 , V_106 ) ;
if ( V_65 )
F_54 ( & V_4 -> V_62 -> V_4 ) ;
F_91 ( & V_42 -> V_157 ) ;
}
static void F_96 ( struct V_1 * V_42 , bool V_158 )
{
struct V_159 * V_160 = V_42 -> V_98 ;
struct V_2 * V_4 = & V_42 -> V_4 ;
V_42 -> V_98 = NULL ;
V_42 -> V_153 [ 0 ] = V_42 -> V_153 [ 1 ] = - V_28 ;
F_97 ( V_160 ) ;
if ( F_98 ( & V_42 -> V_155 [ 0 ] ) )
F_99 ( V_4 -> V_29 , V_42 -> V_156 * 2 ,
F_94 ( & V_42 -> V_155 [ 0 ] ) , F_98 ( & V_42 -> V_155 [ 0 ] ) ) ;
if ( V_158 )
F_100 ( V_4 ) ;
}
static void F_101 ( struct V_1 * V_42 , bool V_158 )
{
struct V_159 * V_160 = V_42 -> V_116 ;
struct V_2 * V_4 = & V_42 -> V_4 ;
V_42 -> V_116 = NULL ;
V_42 -> V_148 = - V_28 ;
F_97 ( V_160 ) ;
if ( V_158 )
F_102 ( V_4 ) ;
}
static void F_103 ( struct V_1 * V_42 )
{
struct V_159 * V_160 = V_42 -> V_98 ;
int V_77 ;
for ( V_77 = 0 ; V_77 < 2 ; V_77 ++ ) {
struct V_161 * V_162 = & V_42 -> V_155 [ V_77 ] ;
struct V_163 * V_127 ;
V_127 = F_104 ( V_160 ,
V_162 , 1 , V_164 , V_165 ) ;
if ( V_127 ) {
V_42 -> V_166 [ V_77 ] = V_127 ;
V_127 -> V_167 = F_95 ;
V_127 -> V_168 = V_42 ;
V_42 -> V_153 [ V_77 ] = V_127 -> V_169 ( V_127 ) ;
}
if ( ! V_127 || V_42 -> V_153 [ V_77 ] < 0 ) {
if ( V_77 ) {
F_90 ( V_42 -> V_166 [ 0 ] ) ;
V_42 -> V_153 [ 0 ] = - V_28 ;
}
if ( V_127 ) {
F_90 ( V_127 ) ;
V_42 -> V_153 [ V_77 ] = - V_28 ;
}
F_93 ( V_42 -> V_4 . V_29 ,
L_16 ) ;
F_96 ( V_42 , true ) ;
return;
}
F_50 ( V_42 -> V_4 . V_29 , L_17 ,
V_145 , V_42 -> V_153 [ V_77 ] , V_77 ) ;
}
V_42 -> V_152 = V_42 -> V_153 [ 0 ] ;
F_105 ( V_160 ) ;
}
static void F_106 ( struct V_170 * V_171 )
{
struct V_1 * V_42 = F_2 ( V_171 , struct V_1 , V_157 ) ;
struct V_2 * V_4 = & V_42 -> V_4 ;
struct V_163 * V_127 ;
int V_172 ;
if ( V_42 -> V_152 == V_42 -> V_153 [ 0 ] ) {
V_172 = 0 ;
} else if ( V_42 -> V_152 == V_42 -> V_153 [ 1 ] ) {
V_172 = 1 ;
} else {
F_80 ( V_4 -> V_29 , L_13 , V_42 -> V_152 ) ;
return;
}
V_127 = V_42 -> V_166 [ V_172 ] ;
if ( F_107 ( V_42 -> V_98 , V_42 -> V_152 , NULL , NULL ) !=
V_173 ) {
struct V_159 * V_160 = V_42 -> V_98 ;
struct V_174 * V_175 = F_2 ( V_127 ,
struct V_174 , V_176 ) ;
unsigned long V_106 ;
int V_65 ;
F_108 ( V_160 ) ;
F_50 ( V_4 -> V_29 , L_18 ,
V_175 -> V_177 , V_175 -> V_178 ) ;
F_67 ( & V_4 -> V_107 , V_106 ) ;
V_65 = F_92 ( V_42 , V_175 -> V_177 ) ;
F_68 ( & V_4 -> V_107 , V_106 ) ;
if ( V_65 )
F_54 ( & V_4 -> V_62 -> V_4 ) ;
F_103 ( V_42 ) ;
return;
}
V_42 -> V_153 [ V_172 ] = V_127 -> V_169 ( V_127 ) ;
if ( V_42 -> V_153 [ V_172 ] < 0 ) {
F_93 ( V_4 -> V_29 , L_19 ) ;
F_96 ( V_42 , true ) ;
return;
}
V_42 -> V_152 = V_42 -> V_153 [ ! V_172 ] ;
F_50 ( V_4 -> V_29 , L_20 ,
V_145 , V_42 -> V_153 [ V_172 ] , V_172 , V_42 -> V_152 ) ;
}
static void F_109 ( struct V_170 * V_171 )
{
struct V_1 * V_42 = F_2 ( V_171 , struct V_1 , V_149 ) ;
struct V_163 * V_127 ;
struct V_159 * V_160 = V_42 -> V_116 ;
struct V_2 * V_4 = & V_42 -> V_4 ;
struct V_60 * V_61 = & V_4 -> V_62 -> V_61 ;
struct V_161 * V_162 = & V_42 -> V_146 ;
F_110 ( & V_4 -> V_107 ) ;
V_162 -> V_6 = V_61 -> V_70 & ( V_71 - 1 ) ;
F_98 ( V_162 ) = ( F_98 ( V_162 ) & ~ ( V_71 - 1 ) ) +
V_162 -> V_6 ;
F_89 ( V_162 ) = F_111 ( ( int ) F_112 ( V_61 -> V_179 , V_61 -> V_70 , V_71 ) ,
F_113 ( V_61 -> V_179 , V_61 -> V_70 , V_71 ) ) ;
F_114 ( & V_4 -> V_107 ) ;
F_115 ( ! F_89 ( V_162 ) ) ;
V_127 = F_104 ( V_160 ,
V_162 , V_42 -> V_180 , V_181 ,
V_165 | V_182 ) ;
if ( ! V_127 ) {
F_101 ( V_42 , true ) ;
return;
}
F_116 ( V_4 -> V_29 , V_162 , 1 , V_183 ) ;
F_110 ( & V_4 -> V_107 ) ;
V_42 -> V_147 = V_127 ;
V_127 -> V_167 = F_88 ;
V_127 -> V_168 = V_42 ;
F_114 ( & V_4 -> V_107 ) ;
V_42 -> V_148 = V_127 -> V_169 ( V_127 ) ;
if ( V_42 -> V_148 < 0 ) {
F_93 ( V_4 -> V_29 , L_21 ) ;
F_101 ( V_42 , true ) ;
return;
}
F_50 ( V_4 -> V_29 , L_22 ,
V_145 , V_61 -> V_69 , V_61 -> V_70 , V_61 -> V_179 , V_42 -> V_148 ) ;
F_105 ( V_160 ) ;
}
static void F_102 ( struct V_2 * V_4 )
{
struct V_1 * V_42 = F_1 ( V_4 ) ;
unsigned short V_64 ;
#ifdef F_64
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
T_1 V_172 , V_99 = F_22 ( V_4 , V_66 ) ;
if ( V_42 -> V_116 )
V_172 = V_99 | V_184 ;
else
V_172 = V_99 & ~ V_184 ;
if ( V_172 != V_99 )
F_24 ( V_4 , V_66 , V_172 ) ;
}
if ( V_42 -> V_116 && ! F_40 ( & V_42 -> V_4 . V_62 -> V_61 ) &&
V_42 -> V_148 < 0 ) {
V_42 -> V_148 = 0 ;
F_91 ( & V_42 -> V_149 ) ;
}
#endif
if ( ! V_42 -> V_116 || V_4 -> type == V_20 || V_4 -> type == V_22 ) {
V_64 = F_22 ( V_4 , V_66 ) ;
F_24 ( V_4 , V_66 , V_64 | V_67 ) ;
}
}
static void F_43 ( struct V_2 * V_4 )
{
unsigned short V_64 ;
V_64 = F_22 ( V_4 , V_66 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 )
V_64 &= ~ V_184 ;
V_64 &= ~ V_67 ;
F_24 ( V_4 , V_66 , V_64 ) ;
}
static void F_100 ( struct V_2 * V_4 )
{
unsigned short V_64 ;
V_64 = F_22 ( V_4 , V_66 ) | F_72 ( V_4 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 )
V_64 &= ~ V_101 ;
F_24 ( V_4 , V_66 , V_64 ) ;
}
static void F_117 ( struct V_2 * V_4 )
{
unsigned short V_64 ;
V_64 = F_22 ( V_4 , V_66 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 )
V_64 &= ~ V_101 ;
V_64 &= ~ F_72 ( V_4 ) ;
F_24 ( V_4 , V_66 , V_64 ) ;
}
static void F_118 ( struct V_2 * V_4 , int V_185 )
{
struct V_1 * V_42 = F_1 ( V_4 ) ;
struct V_7 * V_8 = V_43 [ V_42 -> V_14 -> V_16 ] + V_44 ;
unsigned short V_108 , V_186 ;
if ( ! V_8 -> V_9 ) {
return;
}
V_186 = F_22 ( V_4 , V_44 ) ;
V_108 = F_22 ( V_4 , V_66 ) ;
if ( V_185 == - 1 ) {
V_186 = ( V_186 | V_187 ) & ~ V_188 ;
V_108 &= ~ V_189 ;
} else {
V_186 = ( V_186 | V_188 ) & ~ V_187 ;
V_108 |= V_189 ;
}
F_24 ( V_4 , V_44 , V_186 ) ;
F_24 ( V_4 , V_66 , V_108 ) ;
}
static bool F_119 ( struct V_159 * V_160 , void * V_190 )
{
struct V_191 * V_192 = V_190 ;
F_50 ( V_160 -> V_193 -> V_29 , L_23 ,
V_145 , V_192 -> V_194 . V_195 ) ;
V_160 -> V_196 = & V_192 -> V_194 ;
return true ;
}
static void F_120 ( unsigned long V_144 )
{
struct V_1 * V_42 = (struct V_1 * ) V_144 ;
struct V_2 * V_4 = & V_42 -> V_4 ;
T_1 V_99 = F_22 ( V_4 , V_66 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
V_99 &= ~ V_101 ;
F_121 ( V_42 -> V_129 [ V_197 ] ) ;
}
F_24 ( V_4 , V_66 , V_99 | V_102 ) ;
F_50 ( V_4 -> V_29 , L_24 ) ;
F_91 ( & V_42 -> V_157 ) ;
}
static void F_122 ( struct V_2 * V_4 )
{
struct V_1 * V_42 = F_1 ( V_4 ) ;
struct V_191 * V_192 ;
struct V_159 * V_160 ;
T_4 V_198 ;
int V_199 ;
F_50 ( V_4 -> V_29 , L_25 , V_145 , V_4 -> line ) ;
if ( V_42 -> V_14 -> V_200 <= 0 || V_42 -> V_14 -> V_201 <= 0 )
return;
F_123 ( V_198 ) ;
F_124 ( V_202 , V_198 ) ;
V_192 = & V_42 -> V_203 ;
V_192 -> V_194 . V_195 = V_42 -> V_14 -> V_200 ;
V_42 -> V_148 = - V_28 ;
V_160 = F_125 ( V_198 , F_119 , V_192 ) ;
F_50 ( V_4 -> V_29 , L_26 , V_145 , V_160 ) ;
if ( V_160 ) {
V_42 -> V_116 = V_160 ;
F_126 ( & V_42 -> V_146 , 1 ) ;
F_115 ( ( V_59 ) V_4 -> V_62 -> V_61 . V_69 & ~ V_204 ) ;
F_127 ( & V_42 -> V_146 , F_128 ( V_4 -> V_62 -> V_61 . V_69 ) ,
V_71 ,
( V_59 ) V_4 -> V_62 -> V_61 . V_69 & ~ V_204 ) ;
V_199 = F_129 ( V_4 -> V_29 , & V_42 -> V_146 , 1 , V_183 ) ;
if ( ! V_199 )
F_101 ( V_42 , false ) ;
else
F_50 ( V_4 -> V_29 , L_27 ,
V_145 ,
F_89 ( & V_42 -> V_146 ) , V_4 -> V_62 -> V_61 . V_69 ,
& F_98 ( & V_42 -> V_146 ) ) ;
V_42 -> V_180 = V_199 ;
F_130 ( & V_42 -> V_149 , F_109 ) ;
}
V_192 = & V_42 -> V_205 ;
V_192 -> V_194 . V_195 = V_42 -> V_14 -> V_201 ;
V_160 = F_125 ( V_198 , F_119 , V_192 ) ;
F_50 ( V_4 -> V_29 , L_28 , V_145 , V_160 ) ;
if ( V_160 ) {
T_5 V_206 [ 2 ] ;
void * V_69 [ 2 ] ;
int V_77 ;
V_42 -> V_98 = V_160 ;
V_42 -> V_156 = 2 * F_131 ( 16 , ( int ) V_4 -> V_53 ) ;
V_69 [ 0 ] = F_132 ( V_4 -> V_29 , V_42 -> V_156 * 2 ,
& V_206 [ 0 ] , V_131 ) ;
if ( ! V_69 [ 0 ] ) {
F_93 ( V_4 -> V_29 ,
L_29 ) ;
F_96 ( V_42 , true ) ;
return;
}
V_69 [ 1 ] = V_69 [ 0 ] + V_42 -> V_156 ;
V_206 [ 1 ] = V_206 [ 0 ] + V_42 -> V_156 ;
for ( V_77 = 0 ; V_77 < 2 ; V_77 ++ ) {
struct V_161 * V_162 = & V_42 -> V_155 [ V_77 ] ;
F_126 ( V_162 , 1 ) ;
F_127 ( V_162 , F_128 ( V_69 [ V_77 ] ) , V_42 -> V_156 ,
( V_59 ) V_69 [ V_77 ] & ~ V_204 ) ;
F_98 ( V_162 ) = V_206 [ V_77 ] ;
}
F_130 ( & V_42 -> V_157 , F_106 ) ;
F_133 ( & V_42 -> V_104 , F_120 , ( unsigned long ) V_42 ) ;
F_103 ( V_42 ) ;
}
}
static void F_134 ( struct V_2 * V_4 )
{
struct V_1 * V_42 = F_1 ( V_4 ) ;
if ( V_42 -> V_116 )
F_101 ( V_42 , false ) ;
if ( V_42 -> V_98 )
F_96 ( V_42 , false ) ;
}
static inline void F_122 ( struct V_2 * V_4 )
{
}
static inline void F_134 ( struct V_2 * V_4 )
{
}
static int F_135 ( struct V_2 * V_4 )
{
struct V_1 * V_42 = F_1 ( V_4 ) ;
unsigned long V_106 ;
int V_114 ;
F_50 ( V_4 -> V_29 , L_12 , V_145 , V_4 -> line ) ;
V_114 = F_75 ( V_42 ) ;
if ( F_77 ( V_114 < 0 ) )
return V_114 ;
F_122 ( V_4 ) ;
F_67 ( & V_4 -> V_107 , V_106 ) ;
F_102 ( V_4 ) ;
F_100 ( V_4 ) ;
F_68 ( & V_4 -> V_107 , V_106 ) ;
return 0 ;
}
static void F_136 ( struct V_2 * V_4 )
{
struct V_1 * V_42 = F_1 ( V_4 ) ;
unsigned long V_106 ;
F_50 ( V_4 -> V_29 , L_12 , V_145 , V_4 -> line ) ;
F_67 ( & V_4 -> V_107 , V_106 ) ;
F_117 ( V_4 ) ;
F_43 ( V_4 ) ;
F_68 ( & V_4 -> V_107 , V_106 ) ;
F_134 ( V_4 ) ;
F_84 ( V_42 ) ;
}
static unsigned int F_137 ( struct V_1 * V_42 , unsigned int V_207 ,
unsigned long V_208 )
{
if ( V_42 -> V_209 )
return F_138 ( V_208 , V_42 -> V_209 * V_207 ) - 1 ;
F_139 ( 1 ) ;
return ( ( V_208 + 16 * V_207 ) / ( 32 * V_207 ) - 1 ) ;
}
static int F_140 ( unsigned int V_210 )
{
int V_211 = 10 ;
if ( V_210 & V_212 )
V_211 -- ;
if ( V_210 & V_213 )
V_211 ++ ;
if ( V_210 & V_214 )
V_211 ++ ;
return V_211 ;
}
static void F_141 ( unsigned int V_207 , unsigned long V_208 ,
int * V_215 , unsigned int * V_216 ,
unsigned int * V_217 , int V_218 )
{
int V_219 , V_36 , V_220 , V_221 , V_222 ;
int V_223 = 1000 ;
int V_224 = 0 ;
for ( V_219 = 8 ; V_219 <= 32 ; V_219 ++ ) {
for ( V_36 = 0 ; V_36 <= 3 ; V_36 ++ ) {
V_220 = F_138 ( V_208 , ( V_219 *
( 1 << ( 2 * V_36 + 1 ) ) * V_207 ) ) - 1 ;
V_220 = F_142 ( V_220 , 0 , 255 ) ;
V_221 = F_138 ( V_208 , ( ( V_220 + 1 ) * V_207 * V_219 *
( 1 << ( 2 * V_36 + 1 ) ) / 1000 ) ) -
1000 ;
V_222 = abs ( ( 500 -
F_138 ( 1000 , V_219 << 1 ) ) / 10 ) ;
if ( abs ( V_223 ) > abs ( V_221 ) ) {
V_223 = V_221 ;
V_224 = V_222 ;
} else if ( ( V_223 == V_221 ) &&
( V_222 > V_224 ) )
V_224 = V_222 ;
else
continue;
* V_215 = V_220 ;
* V_216 = V_219 - 1 ;
* V_217 = V_36 ;
}
}
if ( V_223 == 1000 ) {
F_139 ( 1 ) ;
* V_215 = 255 ;
* V_216 = 15 ;
* V_217 = 0 ;
}
}
static void F_143 ( struct V_2 * V_4 )
{
struct V_7 * V_8 ;
unsigned int V_35 ;
do {
V_35 = F_22 ( V_4 , V_37 ) ;
} while ( ! ( V_35 & F_31 ( V_4 ) ) );
F_24 ( V_4 , V_66 , 0x00 ) ;
V_8 = F_4 ( V_4 , V_140 ) ;
if ( V_8 -> V_9 )
F_24 ( V_4 , V_140 , V_225 | V_226 ) ;
}
static void F_144 ( struct V_2 * V_4 , struct V_227 * V_228 ,
struct V_227 * V_229 )
{
struct V_1 * V_42 = F_1 ( V_4 ) ;
struct V_7 * V_8 ;
unsigned int V_230 , V_210 = 0 , V_231 , V_217 = 0 ;
int V_232 = - 1 ;
unsigned int V_216 = 15 ;
if ( ( V_228 -> V_233 & V_234 ) == V_235 )
V_210 |= V_212 ;
if ( V_228 -> V_233 & V_236 )
V_210 |= V_213 ;
if ( V_228 -> V_233 & V_237 )
V_210 |= V_213 | V_238 ;
if ( V_228 -> V_233 & V_239 )
V_210 |= V_214 ;
V_231 = V_4 -> V_31 ? V_4 -> V_31 / 16 : 115200 ;
V_230 = F_145 ( V_4 , V_228 , V_229 , 0 , V_231 ) ;
if ( F_146 ( V_230 && V_4 -> V_31 ) ) {
if ( V_42 -> V_14 -> type == V_26 ) {
int V_218 = F_140 ( V_210 ) ;
F_141 ( V_230 , V_4 -> V_31 , & V_232 , & V_216 ,
& V_217 , V_218 ) ;
} else {
V_232 = F_137 ( V_42 , V_230 , V_4 -> V_31 ) ;
for ( V_217 = 0 ; V_232 >= 256 && V_217 <= 3 ; V_217 ++ )
V_232 >>= 2 ;
}
}
F_13 ( V_42 ) ;
F_143 ( V_4 ) ;
V_210 |= F_22 ( V_4 , V_240 ) & 3 ;
F_147 ( V_4 , V_228 -> V_233 , V_230 ) ;
F_50 ( V_4 -> V_29 , L_30 ,
V_145 , V_210 , V_217 , V_232 , V_42 -> V_14 -> V_108 ) ;
if ( V_232 >= 0 ) {
F_24 ( V_4 , V_240 , ( V_210 & ~ V_241 ) | V_217 ) ;
F_24 ( V_4 , V_242 , V_232 ) ;
V_8 = F_4 ( V_4 , V_243 ) ;
if ( V_8 -> V_9 )
F_24 ( V_4 , V_243 , V_216 | V_244 ) ;
F_148 ( ( 1000000 + ( V_230 - 1 ) ) / V_230 ) ;
} else
F_24 ( V_4 , V_240 , V_210 ) ;
F_32 ( V_4 , V_228 -> V_233 ) ;
V_8 = F_4 ( V_4 , V_140 ) ;
if ( V_8 -> V_9 ) {
unsigned short V_64 = F_22 ( V_4 , V_140 ) ;
if ( V_42 -> V_14 -> V_47 & V_48 ) {
if ( V_228 -> V_233 & V_49 )
V_64 |= V_245 ;
else
V_64 &= ~ V_245 ;
}
V_64 &= ~ ( V_225 | V_226 ) ;
F_24 ( V_4 , V_140 , V_64 ) ;
}
F_24 ( V_4 , V_66 , V_42 -> V_14 -> V_108 ) ;
#ifdef F_64
if ( V_42 -> V_98 ) {
unsigned int V_246 ;
switch ( V_228 -> V_233 & V_234 ) {
case V_247 :
V_246 = 7 ;
break;
case V_248 :
V_246 = 8 ;
break;
case V_235 :
V_246 = 9 ;
break;
default:
V_246 = 10 ;
break;
}
if ( V_228 -> V_233 & V_239 )
V_246 ++ ;
if ( V_228 -> V_233 & V_236 )
V_246 ++ ;
V_42 -> V_103 = F_149 ( ( V_42 -> V_156 * 2 * V_246 * V_249 ) /
( V_230 / 10 ) , 10 ) ;
F_50 ( V_4 -> V_29 , L_31 ,
V_42 -> V_103 * 1000 / V_249 , V_4 -> V_250 ) ;
if ( V_42 -> V_103 < F_150 ( 20 ) )
V_42 -> V_103 = F_150 ( 20 ) ;
}
#endif
if ( ( V_228 -> V_233 & V_251 ) != 0 )
F_100 ( V_4 ) ;
F_17 ( V_42 ) ;
}
static void F_151 ( struct V_2 * V_4 , unsigned int V_62 ,
unsigned int V_252 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
switch ( V_62 ) {
case V_253 :
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
return L_32 ;
case V_15 :
return L_33 ;
case V_24 :
return L_34 ;
case V_20 :
return L_35 ;
case V_22 :
return L_36 ;
case V_26 :
return L_37 ;
}
return NULL ;
}
static int F_153 ( struct V_2 * V_4 )
{
struct V_1 * V_254 = F_1 ( V_4 ) ;
if ( V_4 -> V_10 )
return 0 ;
if ( V_4 -> V_106 & V_255 ) {
V_4 -> V_10 = F_154 ( V_4 -> V_256 , V_254 -> V_257 ) ;
if ( F_77 ( ! V_4 -> V_10 ) ) {
F_80 ( V_4 -> V_29 , L_38 , V_4 -> line ) ;
return - V_258 ;
}
} else {
V_4 -> V_10 = ( void V_58 * ) ( V_59 ) V_4 -> V_256 ;
}
return 0 ;
}
static void F_155 ( struct V_2 * V_4 )
{
struct V_1 * V_254 = F_1 ( V_4 ) ;
if ( V_4 -> V_106 & V_255 ) {
F_156 ( V_4 -> V_10 ) ;
V_4 -> V_10 = NULL ;
}
F_157 ( V_4 -> V_256 , V_254 -> V_257 ) ;
}
static int F_158 ( struct V_2 * V_4 )
{
struct V_259 * V_260 ;
struct V_1 * V_254 = F_1 ( V_4 ) ;
int V_114 ;
V_260 = F_159 ( V_4 -> V_256 , V_254 -> V_257 ,
F_79 ( V_4 -> V_29 ) ) ;
if ( F_77 ( V_260 == NULL ) ) {
F_80 ( V_4 -> V_29 , L_39 ) ;
return - V_261 ;
}
V_114 = F_153 ( V_4 ) ;
if ( F_77 ( V_114 != 0 ) ) {
F_160 ( V_260 ) ;
return V_114 ;
}
return 0 ;
}
static void F_161 ( struct V_2 * V_4 , int V_106 )
{
if ( V_106 & V_262 ) {
struct V_1 * V_254 = F_1 ( V_4 ) ;
V_4 -> type = V_254 -> V_14 -> type ;
F_158 ( V_4 ) ;
}
}
static int F_162 ( struct V_2 * V_4 , struct V_263 * V_264 )
{
if ( V_264 -> V_265 < 2400 )
return - V_28 ;
return 0 ;
}
static int F_163 ( struct V_266 * V_29 ,
struct V_1 * V_1 , unsigned int V_267 ,
struct V_13 * V_5 , bool V_268 )
{
struct V_2 * V_4 = & V_1 -> V_4 ;
const struct V_259 * V_260 ;
unsigned int V_209 ;
unsigned int V_77 ;
int V_114 ;
V_1 -> V_14 = V_5 ;
V_4 -> V_45 = & V_269 ;
V_4 -> V_270 = V_271 ;
V_4 -> line = V_267 ;
V_260 = F_164 ( V_29 , V_272 , 0 ) ;
if ( V_260 == NULL )
return - V_273 ;
V_4 -> V_256 = V_260 -> V_274 ;
V_1 -> V_257 = F_165 ( V_260 ) ;
for ( V_77 = 0 ; V_77 < F_166 ( V_1 -> V_129 ) ; ++ V_77 )
V_1 -> V_129 [ V_77 ] = F_167 ( V_29 , V_77 ) ;
if ( V_1 -> V_129 [ 0 ] < 0 )
return - V_258 ;
if ( V_1 -> V_129 [ 1 ] < 0 ) {
V_1 -> V_129 [ 1 ] = V_1 -> V_129 [ 0 ] ;
V_1 -> V_129 [ 2 ] = V_1 -> V_129 [ 0 ] ;
V_1 -> V_129 [ 3 ] = V_1 -> V_129 [ 0 ] ;
}
if ( V_5 -> V_16 == V_275 ) {
V_114 = F_11 ( V_5 ) ;
if ( F_77 ( V_114 ) )
return V_114 ;
}
switch ( V_5 -> type ) {
case V_22 :
V_4 -> V_53 = 256 ;
V_1 -> V_95 = V_37 ;
V_1 -> V_90 = V_276 ;
V_209 = 16 ;
break;
case V_26 :
V_4 -> V_53 = 128 ;
V_209 = 0 ;
V_1 -> V_95 = V_277 ;
V_1 -> V_90 = V_278 ;
break;
case V_20 :
V_4 -> V_53 = 64 ;
V_1 -> V_95 = V_37 ;
V_1 -> V_90 = V_276 ;
V_209 = 16 ;
break;
case V_24 :
V_4 -> V_53 = 16 ;
if ( V_5 -> V_16 == V_279 ) {
V_1 -> V_95 = V_37 ;
V_1 -> V_90 = V_276 ;
V_209 = 16 ;
} else {
V_1 -> V_95 = V_277 ;
V_1 -> V_90 = V_278 ;
V_209 = 32 ;
}
break;
default:
V_4 -> V_53 = 1 ;
V_1 -> V_95 = V_37 ;
V_1 -> V_90 = V_280 ;
V_209 = 32 ;
break;
}
V_1 -> V_209 = V_5 -> V_209 ? V_5 -> V_209
: V_209 ;
if ( ! V_268 ) {
V_1 -> V_30 = F_168 ( & V_29 -> V_29 , L_40 ) ;
if ( F_169 ( V_1 -> V_30 ) ) {
V_1 -> V_30 = F_168 ( & V_29 -> V_29 , L_41 ) ;
if ( F_169 ( V_1 -> V_30 ) ) {
F_80 ( & V_29 -> V_29 , L_42 ) ;
return F_170 ( V_1 -> V_30 ) ;
}
}
V_1 -> V_32 = F_168 ( & V_29 -> V_29 , L_43 ) ;
if ( F_169 ( V_1 -> V_32 ) )
V_1 -> V_32 = NULL ;
V_4 -> V_29 = & V_29 -> V_29 ;
F_171 ( & V_29 -> V_29 ) ;
}
V_1 -> V_33 . V_89 = ( unsigned long ) V_1 ;
V_1 -> V_33 . V_281 = F_57 ;
F_172 ( & V_1 -> V_33 ) ;
V_1 -> V_282 = ( V_5 -> type == V_15 ) ?
V_283 : V_284 ;
if ( V_1 -> V_95 == V_37 )
V_1 -> V_282 |= V_1 -> V_90 ;
V_4 -> type = V_5 -> type ;
V_4 -> V_106 = V_285 | V_5 -> V_106 ;
V_4 -> V_11 = V_5 -> V_11 ;
V_4 -> V_96 = V_1 -> V_129 [ V_197 ] ;
V_4 -> V_134 = 0 ;
V_4 -> V_286 = F_3 ;
V_4 -> V_287 = F_8 ;
if ( V_5 -> V_200 > 0 && V_5 -> V_201 > 0 )
F_50 ( V_4 -> V_29 , L_44 ,
V_5 -> V_200 , V_5 -> V_201 ) ;
return 0 ;
}
static void F_173 ( struct V_1 * V_4 )
{
F_174 ( V_4 -> V_30 ) ;
F_174 ( V_4 -> V_32 ) ;
F_175 ( V_4 -> V_4 . V_29 ) ;
}
static void F_176 ( struct V_2 * V_4 , int V_288 )
{
F_28 ( V_4 , V_288 ) ;
}
static void F_177 ( struct V_289 * V_290 , const char * V_42 ,
unsigned V_65 )
{
struct V_1 * V_1 = & V_291 [ V_290 -> V_267 ] ;
struct V_2 * V_4 = & V_1 -> V_4 ;
unsigned short V_246 , V_64 ;
unsigned long V_106 ;
int V_292 = 1 ;
F_178 ( V_106 ) ;
if ( V_4 -> V_293 )
V_292 = 0 ;
else if ( V_294 )
V_292 = F_179 ( & V_4 -> V_107 ) ;
else
F_180 ( & V_4 -> V_107 ) ;
V_64 = F_22 ( V_4 , V_66 ) ;
F_24 ( V_4 , V_66 , V_1 -> V_14 -> V_108 ) ;
F_181 ( V_4 , V_42 , V_65 , F_176 ) ;
V_246 = F_29 ( V_4 ) | F_31 ( V_4 ) ;
while ( ( F_22 ( V_4 , V_37 ) & V_246 ) != V_246 )
F_182 () ;
F_24 ( V_4 , V_66 , V_64 ) ;
if ( V_292 )
F_183 ( & V_4 -> V_107 ) ;
F_184 ( V_106 ) ;
}
static int F_185 ( struct V_289 * V_290 , char * V_295 )
{
struct V_1 * V_1 ;
struct V_2 * V_4 ;
int V_230 = 115200 ;
int V_246 = 8 ;
int V_85 = 'n' ;
int V_296 = 'n' ;
int V_114 ;
if ( V_290 -> V_267 < 0 || V_290 -> V_267 >= V_297 )
return - V_298 ;
V_1 = & V_291 [ V_290 -> V_267 ] ;
V_4 = & V_1 -> V_4 ;
if ( ! V_4 -> V_45 )
return - V_298 ;
V_114 = F_153 ( V_4 ) ;
if ( F_77 ( V_114 != 0 ) )
return V_114 ;
if ( V_295 )
F_186 ( V_295 , & V_230 , & V_85 , & V_246 , & V_296 ) ;
return F_187 ( V_4 , V_290 , V_230 , V_85 , V_246 , V_296 ) ;
}
static int F_188 ( struct V_266 * V_299 )
{
struct V_13 * V_14 = F_189 ( & V_299 -> V_29 ) ;
if ( V_300 . V_89 )
return - V_301 ;
V_300 . V_267 = V_299 -> V_302 ;
F_163 ( V_299 , & V_291 [ V_299 -> V_302 ] , V_299 -> V_302 , V_14 , true ) ;
F_185 ( & V_300 , V_303 ) ;
if ( ! strstr ( V_303 , L_45 ) )
V_300 . V_106 |= V_304 ;
F_190 ( & V_300 ) ;
return 0 ;
}
static inline int F_188 ( struct V_266 * V_299 )
{
return - V_28 ;
}
static int F_191 ( struct V_266 * V_29 )
{
struct V_1 * V_4 = F_192 ( V_29 ) ;
F_193 ( & V_4 -> V_120 ,
V_305 ) ;
F_194 ( & V_306 , & V_4 -> V_4 ) ;
F_173 ( V_4 ) ;
return 0 ;
}
static struct V_13 *
F_195 ( struct V_266 * V_299 , unsigned int * V_307 )
{
struct V_308 * V_309 = V_299 -> V_29 . V_310 ;
const struct V_311 * V_312 ;
const struct V_313 * V_314 ;
struct V_13 * V_5 ;
int V_302 ;
if ( ! F_196 ( V_315 ) || ! V_309 )
return NULL ;
V_312 = F_197 ( V_316 , V_299 -> V_29 . V_310 ) ;
if ( ! V_312 )
return NULL ;
V_314 = V_312 -> V_89 ;
V_5 = F_198 ( & V_299 -> V_29 , sizeof( struct V_13 ) , V_131 ) ;
if ( ! V_5 ) {
F_80 ( & V_299 -> V_29 , L_46 ) ;
return NULL ;
}
V_302 = F_199 ( V_309 , L_47 ) ;
if ( V_302 < 0 ) {
F_80 ( & V_299 -> V_29 , L_48 , V_302 ) ;
return NULL ;
}
* V_307 = V_302 ;
V_5 -> V_106 = V_255 | V_317 ;
V_5 -> type = V_314 -> type ;
V_5 -> V_16 = V_314 -> V_16 ;
V_5 -> V_108 = V_318 | V_189 ;
return V_5 ;
}
static int F_200 ( struct V_266 * V_29 ,
unsigned int V_267 ,
struct V_13 * V_5 ,
struct V_1 * V_319 )
{
int V_114 ;
if ( F_77 ( V_267 >= V_297 ) ) {
F_52 ( & V_29 -> V_29 , L_49 ,
V_267 + 1 , V_297 ) ;
F_52 ( & V_29 -> V_29 , L_50 ) ;
return - V_28 ;
}
V_114 = F_163 ( V_29 , V_319 , V_267 , V_5 , false ) ;
if ( V_114 )
return V_114 ;
V_114 = F_201 ( & V_306 , & V_319 -> V_4 ) ;
if ( V_114 ) {
F_173 ( V_319 ) ;
return V_114 ;
}
return 0 ;
}
static int F_202 ( struct V_266 * V_29 )
{
struct V_13 * V_5 ;
struct V_1 * V_320 ;
unsigned int V_307 ;
int V_114 ;
if ( F_203 ( V_29 ) )
return F_188 ( V_29 ) ;
if ( V_29 -> V_29 . V_310 ) {
V_5 = F_195 ( V_29 , & V_307 ) ;
if ( V_5 == NULL )
return - V_28 ;
} else {
V_5 = V_29 -> V_29 . V_321 ;
if ( V_5 == NULL ) {
F_80 ( & V_29 -> V_29 , L_51 ) ;
return - V_28 ;
}
V_307 = V_29 -> V_302 ;
}
V_320 = & V_291 [ V_307 ] ;
F_204 ( V_29 , V_320 ) ;
V_114 = F_200 ( V_29 , V_307 , V_5 , V_320 ) ;
if ( V_114 )
return V_114 ;
V_320 -> V_120 . V_322 = F_74 ;
V_114 = F_205 ( & V_320 -> V_120 ,
V_305 ) ;
if ( F_77 ( V_114 < 0 ) ) {
F_194 ( & V_306 , & V_320 -> V_4 ) ;
F_173 ( V_320 ) ;
return V_114 ;
}
#ifdef F_206
F_207 () ;
#endif
return 0 ;
}
static T_6 int F_208 ( struct V_193 * V_29 )
{
struct V_1 * V_254 = F_209 ( V_29 ) ;
if ( V_254 )
F_210 ( & V_306 , & V_254 -> V_4 ) ;
return 0 ;
}
static T_6 int F_211 ( struct V_193 * V_29 )
{
struct V_1 * V_254 = F_209 ( V_29 ) ;
if ( V_254 )
F_212 ( & V_306 , & V_254 -> V_4 ) ;
return 0 ;
}
static int T_7 F_213 ( void )
{
int V_114 ;
F_214 ( L_52 , V_323 ) ;
V_114 = F_215 ( & V_306 ) ;
if ( F_146 ( V_114 == 0 ) ) {
V_114 = F_216 ( & V_324 ) ;
if ( F_77 ( V_114 ) )
F_217 ( & V_306 ) ;
}
return V_114 ;
}
static void T_8 F_218 ( void )
{
F_219 ( & V_324 ) ;
F_217 ( & V_306 ) ;
}
