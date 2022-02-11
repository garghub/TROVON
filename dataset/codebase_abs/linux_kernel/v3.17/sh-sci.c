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
if ( V_35 & ( 1 << V_42 -> V_90 ) ) {
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
V_8 = F_4 ( V_4 , V_95 ) ;
if ( ! V_8 -> V_9 )
return 0 ;
if ( ( F_22 ( V_4 , V_95 ) & ( 1 << V_42 -> V_90 ) ) ) {
F_24 ( V_4 , V_95 , 0 ) ;
V_4 -> V_72 . V_91 ++ ;
F_47 ( V_76 , 0 , V_92 ) ;
F_54 ( V_76 ) ;
F_52 ( V_4 -> V_29 , L_6 ) ;
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
static T_1 F_63 ( int V_96 , void * V_97 )
{
#ifdef F_64
struct V_2 * V_4 = V_97 ;
struct V_1 * V_42 = F_1 ( V_4 ) ;
if ( V_42 -> V_98 ) {
T_2 V_99 = F_22 ( V_4 , V_66 ) ;
T_2 V_100 = F_22 ( V_4 , V_37 ) ;
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
static T_1 F_66 ( int V_96 , void * V_97 )
{
struct V_2 * V_4 = V_97 ;
unsigned long V_106 ;
F_67 ( & V_4 -> V_107 , V_106 ) ;
F_38 ( V_4 ) ;
F_68 ( & V_4 -> V_107 , V_106 ) ;
return V_105 ;
}
static T_1 F_69 ( int V_96 , void * V_97 )
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
static T_1 F_70 ( int V_96 , void * V_97 )
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
static T_1 F_73 ( int V_96 , void * V_97 )
{
unsigned short V_110 , V_111 , V_112 ;
struct V_2 * V_4 = V_97 ;
struct V_1 * V_42 = F_1 ( V_4 ) ;
T_1 V_113 = V_114 ;
V_110 = F_22 ( V_4 , V_37 ) ;
V_111 = F_22 ( V_4 , V_66 ) ;
V_112 = V_111 & F_72 ( V_4 ) ;
if ( ( V_110 & F_29 ( V_4 ) ) && ( V_111 & V_67 ) &&
! V_42 -> V_115 )
V_113 = F_66 ( V_96 , V_97 ) ;
if ( ( ( V_110 & F_26 ( V_4 ) ) || V_42 -> V_98 ) &&
( V_111 & V_102 ) )
V_113 = F_63 ( V_96 , V_97 ) ;
if ( ( V_110 & F_23 ( V_4 ) ) && V_112 )
V_113 = F_69 ( V_96 , V_97 ) ;
if ( ( V_110 & F_62 ( V_4 ) ) && V_112 )
V_113 = F_70 ( V_96 , V_97 ) ;
return V_113 ;
}
static int F_74 ( struct V_116 * V_117 ,
unsigned long V_118 , void * V_5 )
{
struct V_1 * V_1 ;
unsigned long V_106 ;
V_1 = F_2 ( V_117 , struct V_1 , V_119 ) ;
if ( V_118 == V_120 ) {
struct V_2 * V_4 = & V_1 -> V_4 ;
F_67 ( & V_4 -> V_107 , V_106 ) ;
V_4 -> V_31 = F_16 ( V_1 -> V_30 ) ;
F_68 ( & V_4 -> V_107 , V_106 ) ;
}
return V_121 ;
}
static int F_75 ( struct V_1 * V_4 )
{
struct V_2 * V_122 = & V_4 -> V_4 ;
int V_77 , V_123 , V_113 = 0 ;
for ( V_77 = V_123 = 0 ; V_77 < V_124 ; V_77 ++ , V_123 ++ ) {
struct V_125 * V_126 ;
int V_96 ;
if ( F_76 ( V_4 ) ) {
V_77 = V_127 ;
V_96 = V_122 -> V_96 ;
} else {
V_96 = V_4 -> V_128 [ V_77 ] ;
if ( F_77 ( V_96 < 0 ) )
continue;
}
V_126 = V_125 + V_77 ;
V_4 -> V_129 [ V_123 ] = F_78 ( V_130 , L_9 ,
F_79 ( V_122 -> V_29 ) , V_126 -> V_126 ) ;
if ( ! V_4 -> V_129 [ V_123 ] ) {
F_80 ( V_122 -> V_29 , L_10 ,
V_126 -> V_126 ) ;
goto V_131;
}
V_113 = F_81 ( V_96 , V_126 -> V_132 , V_122 -> V_133 ,
V_4 -> V_129 [ V_123 ] , V_4 ) ;
if ( F_77 ( V_113 ) ) {
F_80 ( V_122 -> V_29 , L_11 , V_126 -> V_126 ) ;
goto V_134;
}
}
return 0 ;
V_134:
while ( -- V_77 >= 0 )
F_82 ( V_4 -> V_128 [ V_77 ] , V_4 ) ;
V_131:
while ( -- V_123 >= 0 )
F_83 ( V_4 -> V_129 [ V_123 ] ) ;
return V_113 ;
}
static void F_84 ( struct V_1 * V_4 )
{
int V_77 ;
for ( V_77 = 0 ; V_77 < V_124 ; V_77 ++ ) {
int V_96 = V_4 -> V_128 [ V_77 ] ;
if ( F_77 ( V_96 < 0 ) )
continue;
F_82 ( V_4 -> V_128 [ V_77 ] , V_4 ) ;
F_83 ( V_4 -> V_129 [ V_77 ] ) ;
if ( F_76 ( V_4 ) ) {
return;
}
}
}
static unsigned int F_85 ( struct V_2 * V_4 )
{
unsigned short V_35 = F_22 ( V_4 , V_37 ) ;
unsigned short V_135 = F_33 ( V_4 ) ;
return ( V_35 & F_31 ( V_4 ) ) && ! V_135 ? V_136 : 0 ;
}
static void F_86 ( struct V_2 * V_4 , unsigned int V_137 )
{
if ( V_137 & V_138 ) {
struct V_7 * V_8 ;
V_8 = F_4 ( V_4 , V_139 ) ;
if ( V_8 -> V_9 )
F_24 ( V_4 , V_139 ,
F_22 ( V_4 , V_139 ) |
V_140 ) ;
}
}
static unsigned int F_87 ( struct V_2 * V_4 )
{
return V_141 | V_142 ;
}
static void F_88 ( void * V_143 )
{
struct V_1 * V_42 = V_143 ;
struct V_2 * V_4 = & V_42 -> V_4 ;
struct V_60 * V_61 = & V_4 -> V_62 -> V_61 ;
unsigned long V_106 ;
F_50 ( V_4 -> V_29 , L_12 , V_144 , V_4 -> line ) ;
F_67 ( & V_4 -> V_107 , V_106 ) ;
V_61 -> V_70 += F_89 ( & V_42 -> V_145 ) ;
V_61 -> V_70 &= V_71 - 1 ;
V_4 -> V_72 . V_73 += F_89 ( & V_42 -> V_145 ) ;
F_90 ( V_42 -> V_146 ) ;
V_42 -> V_146 = NULL ;
if ( F_41 ( V_61 ) < V_74 )
F_42 ( V_4 ) ;
if ( ! F_40 ( V_61 ) ) {
V_42 -> V_147 = 0 ;
F_91 ( & V_42 -> V_148 ) ;
} else {
V_42 -> V_147 = - V_28 ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
T_2 V_64 = F_22 ( V_4 , V_66 ) ;
F_24 ( V_4 , V_66 , V_64 & ~ V_67 ) ;
}
}
F_68 ( & V_4 -> V_107 , V_106 ) ;
}
static int F_92 ( struct V_1 * V_42 , T_3 V_65 )
{
struct V_2 * V_4 = & V_42 -> V_4 ;
struct V_75 * V_76 = & V_4 -> V_62 -> V_4 ;
int V_77 , V_149 , V_150 ;
V_150 = F_45 ( V_76 , V_65 ) ;
if ( V_42 -> V_151 == V_42 -> V_152 [ 0 ] ) {
V_149 = 0 ;
} else if ( V_42 -> V_151 == V_42 -> V_152 [ 1 ] ) {
V_149 = 1 ;
} else {
F_80 ( V_4 -> V_29 , L_13 , V_42 -> V_151 ) ;
return 0 ;
}
if ( V_150 < V_65 )
F_93 ( V_4 -> V_29 , L_14 ,
V_65 - V_150 ) ;
if ( ! V_150 )
return V_150 ;
for ( V_77 = 0 ; V_77 < V_150 ; V_77 ++ )
F_47 ( V_76 , ( ( V_153 * ) F_94 ( & V_42 -> V_154 [ V_149 ] ) ) [ V_77 ] ,
V_80 ) ;
V_4 -> V_72 . V_86 += V_150 ;
return V_150 ;
}
static void F_95 ( void * V_143 )
{
struct V_1 * V_42 = V_143 ;
struct V_2 * V_4 = & V_42 -> V_4 ;
unsigned long V_106 ;
int V_65 ;
F_50 ( V_4 -> V_29 , L_15 ,
V_144 , V_4 -> line , V_42 -> V_151 ) ;
F_67 ( & V_4 -> V_107 , V_106 ) ;
V_65 = F_92 ( V_42 , V_42 -> V_155 ) ;
F_56 ( & V_42 -> V_104 , V_87 + V_42 -> V_103 ) ;
F_68 ( & V_4 -> V_107 , V_106 ) ;
if ( V_65 )
F_54 ( & V_4 -> V_62 -> V_4 ) ;
F_91 ( & V_42 -> V_156 ) ;
}
static void F_96 ( struct V_1 * V_42 , bool V_157 )
{
struct V_158 * V_159 = V_42 -> V_98 ;
struct V_2 * V_4 = & V_42 -> V_4 ;
V_42 -> V_98 = NULL ;
V_42 -> V_152 [ 0 ] = V_42 -> V_152 [ 1 ] = - V_28 ;
F_97 ( V_159 ) ;
if ( F_98 ( & V_42 -> V_154 [ 0 ] ) )
F_99 ( V_4 -> V_29 , V_42 -> V_155 * 2 ,
F_94 ( & V_42 -> V_154 [ 0 ] ) , F_98 ( & V_42 -> V_154 [ 0 ] ) ) ;
if ( V_157 )
F_100 ( V_4 ) ;
}
static void F_101 ( struct V_1 * V_42 , bool V_157 )
{
struct V_158 * V_159 = V_42 -> V_115 ;
struct V_2 * V_4 = & V_42 -> V_4 ;
V_42 -> V_115 = NULL ;
V_42 -> V_147 = - V_28 ;
F_97 ( V_159 ) ;
if ( V_157 )
F_102 ( V_4 ) ;
}
static void F_103 ( struct V_1 * V_42 )
{
struct V_158 * V_159 = V_42 -> V_98 ;
int V_77 ;
for ( V_77 = 0 ; V_77 < 2 ; V_77 ++ ) {
struct V_160 * V_161 = & V_42 -> V_154 [ V_77 ] ;
struct V_162 * V_126 ;
V_126 = F_104 ( V_159 ,
V_161 , 1 , V_163 , V_164 ) ;
if ( V_126 ) {
V_42 -> V_165 [ V_77 ] = V_126 ;
V_126 -> V_166 = F_95 ;
V_126 -> V_167 = V_42 ;
V_42 -> V_152 [ V_77 ] = V_126 -> V_168 ( V_126 ) ;
}
if ( ! V_126 || V_42 -> V_152 [ V_77 ] < 0 ) {
if ( V_77 ) {
F_90 ( V_42 -> V_165 [ 0 ] ) ;
V_42 -> V_152 [ 0 ] = - V_28 ;
}
if ( V_126 ) {
F_90 ( V_126 ) ;
V_42 -> V_152 [ V_77 ] = - V_28 ;
}
F_93 ( V_42 -> V_4 . V_29 ,
L_16 ) ;
F_96 ( V_42 , true ) ;
return;
}
F_50 ( V_42 -> V_4 . V_29 , L_17 ,
V_144 , V_42 -> V_152 [ V_77 ] , V_77 ) ;
}
V_42 -> V_151 = V_42 -> V_152 [ 0 ] ;
F_105 ( V_159 ) ;
}
static void F_106 ( struct V_169 * V_170 )
{
struct V_1 * V_42 = F_2 ( V_170 , struct V_1 , V_156 ) ;
struct V_2 * V_4 = & V_42 -> V_4 ;
struct V_162 * V_126 ;
int V_171 ;
if ( V_42 -> V_151 == V_42 -> V_152 [ 0 ] ) {
V_171 = 0 ;
} else if ( V_42 -> V_151 == V_42 -> V_152 [ 1 ] ) {
V_171 = 1 ;
} else {
F_80 ( V_4 -> V_29 , L_13 , V_42 -> V_151 ) ;
return;
}
V_126 = V_42 -> V_165 [ V_171 ] ;
if ( F_107 ( V_42 -> V_98 , V_42 -> V_151 , NULL , NULL ) !=
V_172 ) {
struct V_158 * V_159 = V_42 -> V_98 ;
struct V_173 * V_174 = F_2 ( V_126 ,
struct V_173 , V_175 ) ;
unsigned long V_106 ;
int V_65 ;
V_159 -> V_176 -> V_177 ( V_159 , V_178 , 0 ) ;
F_50 ( V_4 -> V_29 , L_18 ,
V_174 -> V_179 , V_174 -> V_180 ) ;
F_67 ( & V_4 -> V_107 , V_106 ) ;
V_65 = F_92 ( V_42 , V_174 -> V_179 ) ;
F_68 ( & V_4 -> V_107 , V_106 ) ;
if ( V_65 )
F_54 ( & V_4 -> V_62 -> V_4 ) ;
F_103 ( V_42 ) ;
return;
}
V_42 -> V_152 [ V_171 ] = V_126 -> V_168 ( V_126 ) ;
if ( V_42 -> V_152 [ V_171 ] < 0 ) {
F_93 ( V_4 -> V_29 , L_19 ) ;
F_96 ( V_42 , true ) ;
return;
}
V_42 -> V_151 = V_42 -> V_152 [ ! V_171 ] ;
F_50 ( V_4 -> V_29 , L_20 ,
V_144 , V_42 -> V_152 [ V_171 ] , V_171 , V_42 -> V_151 ) ;
}
static void F_108 ( struct V_169 * V_170 )
{
struct V_1 * V_42 = F_2 ( V_170 , struct V_1 , V_148 ) ;
struct V_162 * V_126 ;
struct V_158 * V_159 = V_42 -> V_115 ;
struct V_2 * V_4 = & V_42 -> V_4 ;
struct V_60 * V_61 = & V_4 -> V_62 -> V_61 ;
struct V_160 * V_161 = & V_42 -> V_145 ;
F_109 ( & V_4 -> V_107 ) ;
V_161 -> V_6 = V_61 -> V_70 & ( V_71 - 1 ) ;
F_98 ( V_161 ) = ( F_98 ( V_161 ) & ~ ( V_71 - 1 ) ) +
V_161 -> V_6 ;
F_89 ( V_161 ) = F_110 ( ( int ) F_111 ( V_61 -> V_181 , V_61 -> V_70 , V_71 ) ,
F_112 ( V_61 -> V_181 , V_61 -> V_70 , V_71 ) ) ;
F_113 ( & V_4 -> V_107 ) ;
F_114 ( ! F_89 ( V_161 ) ) ;
V_126 = F_104 ( V_159 ,
V_161 , V_42 -> V_182 , V_183 ,
V_164 | V_184 ) ;
if ( ! V_126 ) {
F_101 ( V_42 , true ) ;
return;
}
F_115 ( V_4 -> V_29 , V_161 , 1 , V_185 ) ;
F_109 ( & V_4 -> V_107 ) ;
V_42 -> V_146 = V_126 ;
V_126 -> V_166 = F_88 ;
V_126 -> V_167 = V_42 ;
F_113 ( & V_4 -> V_107 ) ;
V_42 -> V_147 = V_126 -> V_168 ( V_126 ) ;
if ( V_42 -> V_147 < 0 ) {
F_93 ( V_4 -> V_29 , L_21 ) ;
F_101 ( V_42 , true ) ;
return;
}
F_50 ( V_4 -> V_29 , L_22 ,
V_144 , V_61 -> V_69 , V_61 -> V_70 , V_61 -> V_181 , V_42 -> V_147 ) ;
F_105 ( V_159 ) ;
}
static void F_102 ( struct V_2 * V_4 )
{
struct V_1 * V_42 = F_1 ( V_4 ) ;
unsigned short V_64 ;
#ifdef F_64
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
T_2 V_171 , V_99 = F_22 ( V_4 , V_66 ) ;
if ( V_42 -> V_115 )
V_171 = V_99 | V_186 ;
else
V_171 = V_99 & ~ V_186 ;
if ( V_171 != V_99 )
F_24 ( V_4 , V_66 , V_171 ) ;
}
if ( V_42 -> V_115 && ! F_40 ( & V_42 -> V_4 . V_62 -> V_61 ) &&
V_42 -> V_147 < 0 ) {
V_42 -> V_147 = 0 ;
F_91 ( & V_42 -> V_148 ) ;
}
#endif
if ( ! V_42 -> V_115 || V_4 -> type == V_20 || V_4 -> type == V_22 ) {
V_64 = F_22 ( V_4 , V_66 ) ;
F_24 ( V_4 , V_66 , V_64 | V_67 ) ;
}
}
static void F_43 ( struct V_2 * V_4 )
{
unsigned short V_64 ;
V_64 = F_22 ( V_4 , V_66 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 )
V_64 &= ~ V_186 ;
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
static void F_116 ( struct V_2 * V_4 )
{
unsigned short V_64 ;
V_64 = F_22 ( V_4 , V_66 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 )
V_64 &= ~ V_101 ;
V_64 &= ~ F_72 ( V_4 ) ;
F_24 ( V_4 , V_66 , V_64 ) ;
}
static void F_117 ( struct V_2 * V_4 , int V_187 )
{
struct V_1 * V_42 = F_1 ( V_4 ) ;
struct V_7 * V_8 = V_43 [ V_42 -> V_14 -> V_16 ] + V_44 ;
unsigned short V_108 , V_188 ;
if ( ! V_8 -> V_9 ) {
return;
}
V_188 = F_22 ( V_4 , V_44 ) ;
V_108 = F_22 ( V_4 , V_66 ) ;
if ( V_187 == - 1 ) {
V_188 = ( V_188 | V_189 ) & ~ V_190 ;
V_108 &= ~ V_191 ;
} else {
V_188 = ( V_188 | V_190 ) & ~ V_189 ;
V_108 |= V_191 ;
}
F_24 ( V_4 , V_44 , V_188 ) ;
F_24 ( V_4 , V_66 , V_108 ) ;
}
static bool F_118 ( struct V_158 * V_159 , void * V_192 )
{
struct V_193 * V_194 = V_192 ;
F_50 ( V_159 -> V_176 -> V_29 , L_23 ,
V_144 , V_194 -> V_195 . V_196 ) ;
V_159 -> V_197 = & V_194 -> V_195 ;
return true ;
}
static void F_119 ( unsigned long V_143 )
{
struct V_1 * V_42 = (struct V_1 * ) V_143 ;
struct V_2 * V_4 = & V_42 -> V_4 ;
T_2 V_99 = F_22 ( V_4 , V_66 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
V_99 &= ~ V_101 ;
F_120 ( V_42 -> V_128 [ V_198 ] ) ;
}
F_24 ( V_4 , V_66 , V_99 | V_102 ) ;
F_50 ( V_4 -> V_29 , L_24 ) ;
F_91 ( & V_42 -> V_156 ) ;
}
static void F_121 ( struct V_2 * V_4 )
{
struct V_1 * V_42 = F_1 ( V_4 ) ;
struct V_193 * V_194 ;
struct V_158 * V_159 ;
T_4 V_199 ;
int V_200 ;
F_50 ( V_4 -> V_29 , L_25 , V_144 , V_4 -> line ) ;
if ( V_42 -> V_14 -> V_201 <= 0 || V_42 -> V_14 -> V_202 <= 0 )
return;
F_122 ( V_199 ) ;
F_123 ( V_203 , V_199 ) ;
V_194 = & V_42 -> V_204 ;
V_194 -> V_195 . V_196 = V_42 -> V_14 -> V_201 ;
V_42 -> V_147 = - V_28 ;
V_159 = F_124 ( V_199 , F_118 , V_194 ) ;
F_50 ( V_4 -> V_29 , L_26 , V_144 , V_159 ) ;
if ( V_159 ) {
V_42 -> V_115 = V_159 ;
F_125 ( & V_42 -> V_145 , 1 ) ;
F_114 ( ( V_59 ) V_4 -> V_62 -> V_61 . V_69 & ~ V_205 ) ;
F_126 ( & V_42 -> V_145 , F_127 ( V_4 -> V_62 -> V_61 . V_69 ) ,
V_71 ,
( V_59 ) V_4 -> V_62 -> V_61 . V_69 & ~ V_205 ) ;
V_200 = F_128 ( V_4 -> V_29 , & V_42 -> V_145 , 1 , V_185 ) ;
if ( ! V_200 )
F_101 ( V_42 , false ) ;
else
F_50 ( V_4 -> V_29 , L_27 ,
V_144 ,
F_89 ( & V_42 -> V_145 ) , V_4 -> V_62 -> V_61 . V_69 ,
& F_98 ( & V_42 -> V_145 ) ) ;
V_42 -> V_182 = V_200 ;
F_129 ( & V_42 -> V_148 , F_108 ) ;
}
V_194 = & V_42 -> V_206 ;
V_194 -> V_195 . V_196 = V_42 -> V_14 -> V_202 ;
V_159 = F_124 ( V_199 , F_118 , V_194 ) ;
F_50 ( V_4 -> V_29 , L_28 , V_144 , V_159 ) ;
if ( V_159 ) {
T_5 V_207 [ 2 ] ;
void * V_69 [ 2 ] ;
int V_77 ;
V_42 -> V_98 = V_159 ;
V_42 -> V_155 = 2 * F_130 ( 16 , ( int ) V_4 -> V_53 ) ;
V_69 [ 0 ] = F_131 ( V_4 -> V_29 , V_42 -> V_155 * 2 ,
& V_207 [ 0 ] , V_130 ) ;
if ( ! V_69 [ 0 ] ) {
F_93 ( V_4 -> V_29 ,
L_29 ) ;
F_96 ( V_42 , true ) ;
return;
}
V_69 [ 1 ] = V_69 [ 0 ] + V_42 -> V_155 ;
V_207 [ 1 ] = V_207 [ 0 ] + V_42 -> V_155 ;
for ( V_77 = 0 ; V_77 < 2 ; V_77 ++ ) {
struct V_160 * V_161 = & V_42 -> V_154 [ V_77 ] ;
F_125 ( V_161 , 1 ) ;
F_126 ( V_161 , F_127 ( V_69 [ V_77 ] ) , V_42 -> V_155 ,
( V_59 ) V_69 [ V_77 ] & ~ V_205 ) ;
F_98 ( V_161 ) = V_207 [ V_77 ] ;
}
F_129 ( & V_42 -> V_156 , F_106 ) ;
F_132 ( & V_42 -> V_104 , F_119 , ( unsigned long ) V_42 ) ;
F_103 ( V_42 ) ;
}
}
static void F_133 ( struct V_2 * V_4 )
{
struct V_1 * V_42 = F_1 ( V_4 ) ;
if ( V_42 -> V_115 )
F_101 ( V_42 , false ) ;
if ( V_42 -> V_98 )
F_96 ( V_42 , false ) ;
}
static inline void F_121 ( struct V_2 * V_4 )
{
}
static inline void F_133 ( struct V_2 * V_4 )
{
}
static int F_134 ( struct V_2 * V_4 )
{
struct V_1 * V_42 = F_1 ( V_4 ) ;
unsigned long V_106 ;
int V_113 ;
F_50 ( V_4 -> V_29 , L_12 , V_144 , V_4 -> line ) ;
V_113 = F_75 ( V_42 ) ;
if ( F_77 ( V_113 < 0 ) )
return V_113 ;
F_121 ( V_4 ) ;
F_67 ( & V_4 -> V_107 , V_106 ) ;
F_102 ( V_4 ) ;
F_100 ( V_4 ) ;
F_68 ( & V_4 -> V_107 , V_106 ) ;
return 0 ;
}
static void F_135 ( struct V_2 * V_4 )
{
struct V_1 * V_42 = F_1 ( V_4 ) ;
unsigned long V_106 ;
F_50 ( V_4 -> V_29 , L_12 , V_144 , V_4 -> line ) ;
F_67 ( & V_4 -> V_107 , V_106 ) ;
F_116 ( V_4 ) ;
F_43 ( V_4 ) ;
F_68 ( & V_4 -> V_107 , V_106 ) ;
F_133 ( V_4 ) ;
F_84 ( V_42 ) ;
}
static unsigned int F_136 ( struct V_1 * V_42 , unsigned int V_208 ,
unsigned long V_209 )
{
if ( V_42 -> V_210 )
return F_137 ( V_209 , V_42 -> V_210 * V_208 ) - 1 ;
F_138 ( 1 ) ;
return ( ( V_209 + 16 * V_208 ) / ( 32 * V_208 ) - 1 ) ;
}
static int F_139 ( unsigned int V_211 )
{
int V_212 = 10 ;
if ( V_211 & V_213 )
V_212 -- ;
if ( V_211 & V_214 )
V_212 ++ ;
if ( V_211 & V_215 )
V_212 ++ ;
return V_212 ;
}
static void F_140 ( unsigned int V_208 , unsigned long V_209 ,
int * V_216 , unsigned int * V_217 ,
unsigned int * V_218 , int V_219 )
{
int V_220 , V_36 , V_221 , V_222 , V_223 ;
int V_224 = 1000 ;
int V_225 = 0 ;
for ( V_220 = 8 ; V_220 <= 32 ; V_220 ++ ) {
for ( V_36 = 0 ; V_36 <= 3 ; V_36 ++ ) {
V_221 = F_137 ( V_209 , ( V_220 *
( 1 << ( 2 * V_36 + 1 ) ) * V_208 ) ) - 1 ;
V_221 = F_141 ( V_221 , 0 , 255 ) ;
V_222 = F_137 ( V_209 , ( ( V_221 + 1 ) * V_208 * V_220 *
( 1 << ( 2 * V_36 + 1 ) ) / 1000 ) ) -
1000 ;
if ( V_222 < 0 )
continue;
V_223 = abs ( ( 500 -
F_137 ( 1000 , V_220 << 1 ) ) / 10 ) ;
if ( V_224 > V_222 ) {
V_224 = V_222 ;
V_225 = V_223 ;
} else if ( ( V_224 == V_222 ) &&
( V_223 > V_225 ) )
V_225 = V_223 ;
else
continue;
* V_216 = V_221 ;
* V_217 = V_220 - 1 ;
* V_218 = V_36 ;
}
}
if ( V_224 == 1000 ) {
F_138 ( 1 ) ;
* V_216 = 255 ;
* V_217 = 15 ;
* V_218 = 0 ;
}
}
static void F_142 ( struct V_2 * V_4 )
{
struct V_7 * V_8 ;
unsigned int V_35 ;
do {
V_35 = F_22 ( V_4 , V_37 ) ;
} while ( ! ( V_35 & F_31 ( V_4 ) ) );
F_24 ( V_4 , V_66 , 0x00 ) ;
V_8 = F_4 ( V_4 , V_139 ) ;
if ( V_8 -> V_9 )
F_24 ( V_4 , V_139 , V_226 | V_227 ) ;
}
static void F_143 ( struct V_2 * V_4 , struct V_228 * V_229 ,
struct V_228 * V_230 )
{
struct V_1 * V_42 = F_1 ( V_4 ) ;
struct V_7 * V_8 ;
unsigned int V_231 , V_211 = 0 , V_232 , V_218 = 0 ;
int V_233 = - 1 ;
unsigned int V_217 = 15 ;
if ( ( V_229 -> V_234 & V_235 ) == V_236 )
V_211 |= V_213 ;
if ( V_229 -> V_234 & V_237 )
V_211 |= V_214 ;
if ( V_229 -> V_234 & V_238 )
V_211 |= V_214 | V_239 ;
if ( V_229 -> V_234 & V_240 )
V_211 |= V_215 ;
V_232 = V_4 -> V_31 ? V_4 -> V_31 / 16 : 115200 ;
V_231 = F_144 ( V_4 , V_229 , V_230 , 0 , V_232 ) ;
if ( F_145 ( V_231 && V_4 -> V_31 ) ) {
if ( V_42 -> V_14 -> type == V_26 ) {
int V_219 = F_139 ( V_211 ) ;
F_140 ( V_231 , V_4 -> V_31 , & V_233 , & V_217 ,
& V_218 , V_219 ) ;
} else {
V_233 = F_136 ( V_42 , V_231 , V_4 -> V_31 ) ;
for ( V_218 = 0 ; V_233 >= 256 && V_218 <= 3 ; V_218 ++ )
V_233 >>= 2 ;
}
}
F_13 ( V_42 ) ;
F_142 ( V_4 ) ;
V_211 |= F_22 ( V_4 , V_241 ) & 3 ;
F_146 ( V_4 , V_229 -> V_234 , V_231 ) ;
F_50 ( V_4 -> V_29 , L_30 ,
V_144 , V_211 , V_218 , V_233 , V_42 -> V_14 -> V_108 ) ;
if ( V_233 >= 0 ) {
F_24 ( V_4 , V_241 , ( V_211 & ~ V_242 ) | V_218 ) ;
F_24 ( V_4 , V_243 , V_233 ) ;
V_8 = F_4 ( V_4 , V_244 ) ;
if ( V_8 -> V_9 )
F_24 ( V_4 , V_244 , V_217 | V_245 ) ;
F_147 ( ( 1000000 + ( V_231 - 1 ) ) / V_231 ) ;
} else
F_24 ( V_4 , V_241 , V_211 ) ;
F_32 ( V_4 , V_229 -> V_234 ) ;
V_8 = F_4 ( V_4 , V_139 ) ;
if ( V_8 -> V_9 ) {
unsigned short V_64 = F_22 ( V_4 , V_139 ) ;
if ( V_42 -> V_14 -> V_47 & V_48 ) {
if ( V_229 -> V_234 & V_49 )
V_64 |= V_246 ;
else
V_64 &= ~ V_246 ;
}
V_64 &= ~ ( V_226 | V_227 ) ;
F_24 ( V_4 , V_139 , V_64 ) ;
}
F_24 ( V_4 , V_66 , V_42 -> V_14 -> V_108 ) ;
#ifdef F_64
if ( V_42 -> V_98 ) {
V_42 -> V_103 = ( V_4 -> V_247 - V_248 / 50 ) * V_42 -> V_155 * 3 /
V_4 -> V_53 / 2 ;
F_50 ( V_4 -> V_29 , L_31 ,
V_42 -> V_103 * 1000 / V_248 , V_4 -> V_247 ) ;
if ( V_42 -> V_103 < F_148 ( 20 ) )
V_42 -> V_103 = F_148 ( 20 ) ;
}
#endif
if ( ( V_229 -> V_234 & V_249 ) != 0 )
F_100 ( V_4 ) ;
F_17 ( V_42 ) ;
}
static void F_149 ( struct V_2 * V_4 , unsigned int V_62 ,
unsigned int V_250 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
switch ( V_62 ) {
case V_251 :
F_17 ( V_1 ) ;
break;
default:
F_13 ( V_1 ) ;
break;
}
}
static const char * F_150 ( struct V_2 * V_4 )
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
static inline unsigned long F_151 ( struct V_2 * V_4 )
{
if ( V_4 -> type == V_26 )
return 96 ;
else
return 64 ;
}
static int F_152 ( struct V_2 * V_4 )
{
unsigned long V_9 = F_151 ( V_4 ) ;
if ( V_4 -> V_10 )
return 0 ;
if ( V_4 -> V_106 & V_252 ) {
V_4 -> V_10 = F_153 ( V_4 -> V_253 , V_9 ) ;
if ( F_77 ( ! V_4 -> V_10 ) ) {
F_80 ( V_4 -> V_29 , L_38 , V_4 -> line ) ;
return - V_254 ;
}
} else {
V_4 -> V_10 = ( void V_58 * ) ( V_59 ) V_4 -> V_253 ;
}
return 0 ;
}
static void F_154 ( struct V_2 * V_4 )
{
if ( V_4 -> V_106 & V_252 ) {
F_155 ( V_4 -> V_10 ) ;
V_4 -> V_10 = NULL ;
}
F_156 ( V_4 -> V_253 , F_151 ( V_4 ) ) ;
}
static int F_157 ( struct V_2 * V_4 )
{
unsigned long V_9 = F_151 ( V_4 ) ;
struct V_255 * V_256 ;
int V_113 ;
V_256 = F_158 ( V_4 -> V_253 , V_9 , F_79 ( V_4 -> V_29 ) ) ;
if ( F_77 ( V_256 == NULL ) )
return - V_257 ;
V_113 = F_152 ( V_4 ) ;
if ( F_77 ( V_113 != 0 ) ) {
F_159 ( V_256 ) ;
return V_113 ;
}
return 0 ;
}
static void F_160 ( struct V_2 * V_4 , int V_106 )
{
if ( V_106 & V_258 ) {
struct V_1 * V_259 = F_1 ( V_4 ) ;
V_4 -> type = V_259 -> V_14 -> type ;
F_157 ( V_4 ) ;
}
}
static int F_161 ( struct V_2 * V_4 , struct V_260 * V_261 )
{
if ( V_261 -> V_262 < 2400 )
return - V_28 ;
return 0 ;
}
static int F_162 ( struct V_263 * V_29 ,
struct V_1 * V_1 , unsigned int V_264 ,
struct V_13 * V_5 , bool V_265 )
{
struct V_2 * V_4 = & V_1 -> V_4 ;
const struct V_255 * V_256 ;
unsigned int V_210 ;
unsigned int V_77 ;
int V_113 ;
V_1 -> V_14 = V_5 ;
V_4 -> V_45 = & V_266 ;
V_4 -> V_267 = V_268 ;
V_4 -> line = V_264 ;
V_256 = F_163 ( V_29 , V_269 , 0 ) ;
if ( V_256 == NULL )
return - V_270 ;
V_4 -> V_253 = V_256 -> V_271 ;
for ( V_77 = 0 ; V_77 < F_164 ( V_1 -> V_128 ) ; ++ V_77 )
V_1 -> V_128 [ V_77 ] = F_165 ( V_29 , V_77 ) ;
if ( V_1 -> V_128 [ 0 ] < 0 )
return - V_254 ;
if ( V_1 -> V_128 [ 1 ] < 0 ) {
V_1 -> V_128 [ 1 ] = V_1 -> V_128 [ 0 ] ;
V_1 -> V_128 [ 2 ] = V_1 -> V_128 [ 0 ] ;
V_1 -> V_128 [ 3 ] = V_1 -> V_128 [ 0 ] ;
}
if ( V_5 -> V_16 == V_272 ) {
V_113 = F_11 ( V_5 ) ;
if ( F_77 ( V_113 ) )
return V_113 ;
}
switch ( V_5 -> type ) {
case V_22 :
V_4 -> V_53 = 256 ;
V_1 -> V_90 = 9 ;
V_210 = 16 ;
break;
case V_26 :
V_4 -> V_53 = 128 ;
V_210 = 0 ;
V_1 -> V_90 = 0 ;
break;
case V_20 :
V_4 -> V_53 = 64 ;
V_1 -> V_90 = 9 ;
V_210 = 16 ;
break;
case V_24 :
V_4 -> V_53 = 16 ;
if ( V_5 -> V_16 == V_273 ) {
V_1 -> V_90 = 9 ;
V_210 = 16 ;
} else {
V_1 -> V_90 = 0 ;
V_210 = 32 ;
}
break;
default:
V_4 -> V_53 = 1 ;
V_1 -> V_90 = 5 ;
V_210 = 32 ;
break;
}
V_1 -> V_210 = V_5 -> V_210 ? V_5 -> V_210
: V_210 ;
if ( ! V_265 ) {
V_1 -> V_30 = F_166 ( & V_29 -> V_29 , L_39 ) ;
if ( F_167 ( V_1 -> V_30 ) ) {
V_1 -> V_30 = F_166 ( & V_29 -> V_29 , L_40 ) ;
if ( F_167 ( V_1 -> V_30 ) ) {
F_80 ( & V_29 -> V_29 , L_41 ) ;
return F_168 ( V_1 -> V_30 ) ;
}
}
V_1 -> V_32 = F_166 ( & V_29 -> V_29 , L_42 ) ;
if ( F_167 ( V_1 -> V_32 ) )
V_1 -> V_32 = NULL ;
V_4 -> V_29 = & V_29 -> V_29 ;
F_169 ( & V_29 -> V_29 ) ;
}
V_1 -> V_33 . V_89 = ( unsigned long ) V_1 ;
V_1 -> V_33 . V_274 = F_57 ;
F_170 ( & V_1 -> V_33 ) ;
V_1 -> V_275 = ( V_5 -> type == V_15 ) ?
V_276 : V_277 ;
V_1 -> V_275 |= 1 << V_1 -> V_90 ;
V_4 -> type = V_5 -> type ;
V_4 -> V_106 = V_278 | V_5 -> V_106 ;
V_4 -> V_11 = V_5 -> V_11 ;
V_4 -> V_96 = V_1 -> V_128 [ V_198 ] ;
V_4 -> V_133 = 0 ;
V_4 -> V_279 = F_3 ;
V_4 -> V_280 = F_8 ;
if ( V_5 -> V_201 > 0 && V_5 -> V_202 > 0 )
F_50 ( V_4 -> V_29 , L_43 ,
V_5 -> V_201 , V_5 -> V_202 ) ;
return 0 ;
}
static void F_171 ( struct V_1 * V_4 )
{
F_172 ( V_4 -> V_30 ) ;
F_172 ( V_4 -> V_32 ) ;
F_173 ( V_4 -> V_4 . V_29 ) ;
}
static void F_174 ( struct V_2 * V_4 , int V_281 )
{
F_28 ( V_4 , V_281 ) ;
}
static void F_175 ( struct V_282 * V_283 , const char * V_42 ,
unsigned V_65 )
{
struct V_1 * V_1 = & V_284 [ V_283 -> V_264 ] ;
struct V_2 * V_4 = & V_1 -> V_4 ;
unsigned short V_285 , V_64 ;
unsigned long V_106 ;
int V_286 = 1 ;
F_176 ( V_106 ) ;
if ( V_4 -> V_287 )
V_286 = 0 ;
else if ( V_288 )
V_286 = F_177 ( & V_4 -> V_107 ) ;
else
F_178 ( & V_4 -> V_107 ) ;
V_64 = F_22 ( V_4 , V_66 ) ;
F_24 ( V_4 , V_66 , V_1 -> V_14 -> V_108 ) ;
F_179 ( V_4 , V_42 , V_65 , F_174 ) ;
V_285 = F_29 ( V_4 ) | F_31 ( V_4 ) ;
while ( ( F_22 ( V_4 , V_37 ) & V_285 ) != V_285 )
F_180 () ;
F_24 ( V_4 , V_66 , V_64 ) ;
if ( V_286 )
F_181 ( & V_4 -> V_107 ) ;
F_182 ( V_106 ) ;
}
static int F_183 ( struct V_282 * V_283 , char * V_289 )
{
struct V_1 * V_1 ;
struct V_2 * V_4 ;
int V_231 = 115200 ;
int V_285 = 8 ;
int V_85 = 'n' ;
int V_290 = 'n' ;
int V_113 ;
if ( V_283 -> V_264 < 0 || V_283 -> V_264 >= V_291 )
return - V_292 ;
V_1 = & V_284 [ V_283 -> V_264 ] ;
V_4 = & V_1 -> V_4 ;
if ( ! V_4 -> V_45 )
return - V_292 ;
V_113 = F_152 ( V_4 ) ;
if ( F_77 ( V_113 != 0 ) )
return V_113 ;
if ( V_289 )
F_184 ( V_289 , & V_231 , & V_85 , & V_285 , & V_290 ) ;
return F_185 ( V_4 , V_283 , V_231 , V_85 , V_285 , V_290 ) ;
}
static int F_186 ( struct V_263 * V_293 )
{
struct V_13 * V_14 = F_187 ( & V_293 -> V_29 ) ;
if ( V_294 . V_89 )
return - V_295 ;
V_294 . V_264 = V_293 -> V_296 ;
F_162 ( V_293 , & V_284 [ V_293 -> V_296 ] , V_293 -> V_296 , V_14 , true ) ;
F_183 ( & V_294 , V_297 ) ;
if ( ! strstr ( V_297 , L_44 ) )
V_294 . V_106 |= V_298 ;
F_188 ( & V_294 ) ;
return 0 ;
}
static inline int F_186 ( struct V_263 * V_293 )
{
return - V_28 ;
}
static int F_189 ( struct V_263 * V_29 )
{
struct V_1 * V_4 = F_190 ( V_29 ) ;
F_191 ( & V_4 -> V_119 ,
V_299 ) ;
F_192 ( & V_300 , & V_4 -> V_4 ) ;
F_171 ( V_4 ) ;
return 0 ;
}
static struct V_13 *
F_193 ( struct V_263 * V_293 , unsigned int * V_301 )
{
struct V_302 * V_303 = V_293 -> V_29 . V_304 ;
const struct V_305 * V_306 ;
const struct V_307 * V_308 ;
struct V_13 * V_5 ;
int V_296 ;
if ( ! F_194 ( V_309 ) || ! V_303 )
return NULL ;
V_306 = F_195 ( V_310 , V_293 -> V_29 . V_304 ) ;
if ( ! V_306 )
return NULL ;
V_308 = V_306 -> V_89 ;
V_5 = F_196 ( & V_293 -> V_29 , sizeof( struct V_13 ) , V_130 ) ;
if ( ! V_5 ) {
F_80 ( & V_293 -> V_29 , L_45 ) ;
return NULL ;
}
V_296 = F_197 ( V_303 , L_46 ) ;
if ( V_296 < 0 ) {
F_80 ( & V_293 -> V_29 , L_47 , V_296 ) ;
return NULL ;
}
* V_301 = V_296 ;
V_5 -> V_106 = V_252 | V_311 ;
V_5 -> type = V_308 -> type ;
V_5 -> V_16 = V_308 -> V_16 ;
V_5 -> V_108 = V_312 | V_191 ;
return V_5 ;
}
static int F_198 ( struct V_263 * V_29 ,
unsigned int V_264 ,
struct V_13 * V_5 ,
struct V_1 * V_313 )
{
int V_113 ;
if ( F_77 ( V_264 >= V_291 ) ) {
F_52 ( & V_29 -> V_29 , L_48 ,
V_264 + 1 , V_291 ) ;
F_52 ( & V_29 -> V_29 , L_49 ) ;
return - V_28 ;
}
V_113 = F_162 ( V_29 , V_313 , V_264 , V_5 , false ) ;
if ( V_113 )
return V_113 ;
V_113 = F_199 ( & V_300 , & V_313 -> V_4 ) ;
if ( V_113 ) {
F_171 ( V_313 ) ;
return V_113 ;
}
return 0 ;
}
static int F_200 ( struct V_263 * V_29 )
{
struct V_13 * V_5 ;
struct V_1 * V_314 ;
unsigned int V_301 ;
int V_113 ;
if ( F_201 ( V_29 ) )
return F_186 ( V_29 ) ;
if ( V_29 -> V_29 . V_304 ) {
V_5 = F_193 ( V_29 , & V_301 ) ;
if ( V_5 == NULL )
return - V_28 ;
} else {
V_5 = V_29 -> V_29 . V_315 ;
if ( V_5 == NULL ) {
F_80 ( & V_29 -> V_29 , L_50 ) ;
return - V_28 ;
}
V_301 = V_29 -> V_296 ;
}
V_314 = & V_284 [ V_301 ] ;
F_202 ( V_29 , V_314 ) ;
V_113 = F_198 ( V_29 , V_301 , V_5 , V_314 ) ;
if ( V_113 )
return V_113 ;
V_314 -> V_119 . V_316 = F_74 ;
V_113 = F_203 ( & V_314 -> V_119 ,
V_299 ) ;
if ( F_77 ( V_113 < 0 ) ) {
F_192 ( & V_300 , & V_314 -> V_4 ) ;
F_171 ( V_314 ) ;
return V_113 ;
}
#ifdef F_204
F_205 () ;
#endif
return 0 ;
}
static int F_206 ( struct V_176 * V_29 )
{
struct V_1 * V_259 = F_207 ( V_29 ) ;
if ( V_259 )
F_208 ( & V_300 , & V_259 -> V_4 ) ;
return 0 ;
}
static int F_209 ( struct V_176 * V_29 )
{
struct V_1 * V_259 = F_207 ( V_29 ) ;
if ( V_259 )
F_210 ( & V_300 , & V_259 -> V_4 ) ;
return 0 ;
}
static int T_6 F_211 ( void )
{
int V_113 ;
F_212 ( L_51 , V_317 ) ;
V_113 = F_213 ( & V_300 ) ;
if ( F_145 ( V_113 == 0 ) ) {
V_113 = F_214 ( & V_318 ) ;
if ( F_77 ( V_113 ) )
F_215 ( & V_300 ) ;
}
return V_113 ;
}
static void T_7 F_216 ( void )
{
F_217 ( & V_318 ) ;
F_215 ( & V_300 ) ;
}
