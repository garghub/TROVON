static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static unsigned int F_3 ( struct V_2 * V_5 , int V_6 )
{
const struct V_7 * V_8 = F_4 ( V_5 , V_6 ) ;
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
const struct V_7 * V_8 = F_4 ( V_5 , V_6 ) ;
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
unsigned int V_29 ;
if ( ! V_1 -> V_4 . V_30 )
return;
F_14 ( V_1 -> V_4 . V_30 ) ;
for ( V_29 = 0 ; V_29 < V_31 ; V_29 ++ ) {
F_15 ( V_1 -> V_32 [ V_29 ] ) ;
V_1 -> V_33 [ V_29 ] = F_16 ( V_1 -> V_32 [ V_29 ] ) ;
}
V_1 -> V_4 . V_34 = V_1 -> V_33 [ V_35 ] ;
}
static void F_17 ( struct V_1 * V_1 )
{
unsigned int V_29 ;
if ( ! V_1 -> V_4 . V_30 )
return;
F_18 ( & V_1 -> V_36 ) ;
V_1 -> V_37 = 0 ;
for ( V_29 = V_31 ; V_29 -- > 0 ; )
F_19 ( V_1 -> V_32 [ V_29 ] ) ;
F_20 ( V_1 -> V_4 . V_30 ) ;
}
static inline unsigned long F_21 ( struct V_2 * V_4 )
{
return V_38 | ( F_1 ( V_4 ) -> V_14 -> V_39 & V_40 ) ;
}
static void F_22 ( struct V_2 * V_4 )
{
struct V_1 * V_41 = F_1 ( V_4 ) ;
unsigned short V_42 ;
#ifdef F_23
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
T_1 V_43 , V_44 = F_24 ( V_4 , V_45 ) ;
if ( V_41 -> V_46 )
V_43 = V_44 | V_47 ;
else
V_43 = V_44 & ~ V_47 ;
if ( V_43 != V_44 )
F_25 ( V_4 , V_45 , V_43 ) ;
}
if ( V_41 -> V_46 && ! F_26 ( & V_41 -> V_4 . V_48 -> V_49 ) &&
F_27 ( V_41 -> V_50 ) ) {
V_41 -> V_50 = 0 ;
F_28 ( & V_41 -> V_51 ) ;
}
#endif
if ( ! V_41 -> V_46 || V_4 -> type == V_20 || V_4 -> type == V_22 ) {
V_42 = F_24 ( V_4 , V_45 ) ;
F_25 ( V_4 , V_45 , V_42 | V_52 ) ;
}
}
static void F_29 ( struct V_2 * V_4 )
{
unsigned short V_42 ;
V_42 = F_24 ( V_4 , V_45 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 )
V_42 &= ~ V_47 ;
V_42 &= ~ V_52 ;
F_25 ( V_4 , V_45 , V_42 ) ;
}
static void F_30 ( struct V_2 * V_4 )
{
unsigned short V_42 ;
V_42 = F_24 ( V_4 , V_45 ) | F_21 ( V_4 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 )
V_42 &= ~ V_53 ;
F_25 ( V_4 , V_45 , V_42 ) ;
}
static void F_31 ( struct V_2 * V_4 )
{
unsigned short V_42 ;
V_42 = F_24 ( V_4 , V_45 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 )
V_42 &= ~ V_53 ;
V_42 &= ~ F_21 ( V_4 ) ;
F_25 ( V_4 , V_45 , V_42 ) ;
}
static void F_32 ( struct V_2 * V_4 , unsigned int V_54 )
{
if ( V_4 -> type == V_15 ) {
F_25 ( V_4 , V_55 , V_54 ) ;
} else if ( F_1 ( V_4 ) -> V_56 == V_57 ) {
F_25 ( V_4 , V_55 ,
F_24 ( V_4 , V_55 ) & V_54 ) ;
} else {
F_25 ( V_4 , V_55 , V_54 & ~ ( V_58 | V_59 ) ) ;
}
}
static int F_33 ( struct V_2 * V_4 )
{
unsigned short V_60 ;
int V_61 ;
do {
V_60 = F_24 ( V_4 , V_55 ) ;
if ( V_60 & F_34 ( V_4 ) ) {
F_32 ( V_4 , F_35 ( V_4 ) ) ;
continue;
}
break;
} while ( 1 );
if ( ! ( V_60 & F_36 ( V_4 ) ) )
return V_62 ;
V_61 = F_24 ( V_4 , V_63 ) ;
F_24 ( V_4 , V_55 ) ;
F_32 ( V_4 , F_37 ( V_4 ) ) ;
return V_61 ;
}
static void F_38 ( struct V_2 * V_4 , unsigned char V_61 )
{
unsigned short V_60 ;
do {
V_60 = F_24 ( V_4 , V_55 ) ;
} while ( ! ( V_60 & F_39 ( V_4 ) ) );
F_25 ( V_4 , V_64 , V_61 ) ;
F_32 ( V_4 , F_40 ( V_4 ) & ~ F_41 ( V_4 ) ) ;
}
static void F_42 ( struct V_2 * V_4 , unsigned int V_65 )
{
struct V_1 * V_41 = F_1 ( V_4 ) ;
if ( V_41 -> V_14 -> V_66 && V_41 -> V_14 -> V_66 -> V_67 ) {
V_41 -> V_14 -> V_66 -> V_67 ( V_4 , V_65 ) ;
return;
}
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
T_1 V_42 = F_24 ( V_4 , V_68 ) ;
V_42 &= ~ ( V_69 | V_70 ) ;
if ( F_1 ( V_4 ) -> V_14 -> V_71 & V_72 ) {
V_42 |= V_73 ;
F_25 ( V_4 , V_74 ,
F_24 ( V_4 , V_74 ) | V_75 ) ;
V_42 &= ~ V_76 ;
}
F_25 ( V_4 , V_68 , V_42 ) ;
} else if ( F_4 ( V_4 , V_77 ) -> V_9 ) {
T_1 V_60 = F_24 ( V_4 , V_77 ) ;
V_60 |= V_78 | V_79 ;
V_60 &= ~ ( V_80 | V_81 ) ;
F_25 ( V_4 , V_77 , V_60 ) ;
}
}
static int F_43 ( struct V_2 * V_4 )
{
const struct V_7 * V_8 ;
V_8 = F_4 ( V_4 , V_82 ) ;
if ( V_8 -> V_9 )
return F_24 ( V_4 , V_82 ) & ( ( V_4 -> V_83 << 1 ) - 1 ) ;
V_8 = F_4 ( V_4 , V_84 ) ;
if ( V_8 -> V_9 )
return F_24 ( V_4 , V_84 ) >> 8 ;
return ! ( F_24 ( V_4 , V_55 ) & V_85 ) ;
}
static int F_44 ( struct V_2 * V_4 )
{
return V_4 -> V_83 - F_43 ( V_4 ) ;
}
static int F_45 ( struct V_2 * V_4 )
{
const struct V_7 * V_8 ;
V_8 = F_4 ( V_4 , V_86 ) ;
if ( V_8 -> V_9 )
return F_24 ( V_4 , V_86 ) & ( ( V_4 -> V_83 << 1 ) - 1 ) ;
V_8 = F_4 ( V_4 , V_84 ) ;
if ( V_8 -> V_9 )
return F_24 ( V_4 , V_84 ) & ( ( V_4 -> V_83 << 1 ) - 1 ) ;
return ( F_24 ( V_4 , V_55 ) & F_36 ( V_4 ) ) != 0 ;
}
static inline int F_46 ( struct V_2 * V_4 )
{
struct V_1 * V_41 = F_1 ( V_4 ) ;
if ( V_41 -> V_14 -> V_87 <= 0 )
return 1 ;
return ! ! F_47 ( ( void V_88 * ) ( V_89 ) V_41 -> V_14 -> V_87 ) ;
}
static void F_48 ( struct V_2 * V_4 )
{
struct V_90 * V_49 = & V_4 -> V_48 -> V_49 ;
unsigned int V_91 = F_49 ( V_4 ) ;
unsigned short V_60 ;
unsigned short V_42 ;
int V_92 ;
V_60 = F_24 ( V_4 , V_55 ) ;
if ( ! ( V_60 & F_39 ( V_4 ) ) ) {
V_42 = F_24 ( V_4 , V_45 ) ;
if ( F_26 ( V_49 ) )
V_42 &= ~ V_52 ;
else
V_42 |= V_52 ;
F_25 ( V_4 , V_45 , V_42 ) ;
return;
}
V_92 = F_44 ( V_4 ) ;
do {
unsigned char V_61 ;
if ( V_4 -> V_93 ) {
V_61 = V_4 -> V_93 ;
V_4 -> V_93 = 0 ;
} else if ( ! F_26 ( V_49 ) && ! V_91 ) {
V_61 = V_49 -> V_94 [ V_49 -> V_95 ] ;
V_49 -> V_95 = ( V_49 -> V_95 + 1 ) & ( V_96 - 1 ) ;
} else {
break;
}
F_25 ( V_4 , V_64 , V_61 ) ;
V_4 -> V_97 . V_98 ++ ;
} while ( -- V_92 > 0 );
F_32 ( V_4 , F_40 ( V_4 ) ) ;
if ( F_50 ( V_49 ) < V_99 )
F_51 ( V_4 ) ;
if ( F_26 ( V_49 ) ) {
F_29 ( V_4 ) ;
} else {
V_42 = F_24 ( V_4 , V_45 ) ;
if ( V_4 -> type != V_15 ) {
F_24 ( V_4 , V_55 ) ;
F_32 ( V_4 , F_40 ( V_4 ) ) ;
}
V_42 |= V_52 ;
F_25 ( V_4 , V_45 , V_42 ) ;
}
}
static void F_52 ( struct V_2 * V_4 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_100 * V_101 = & V_4 -> V_48 -> V_4 ;
int V_29 , V_92 , V_102 = 0 ;
unsigned short V_60 ;
unsigned char V_103 ;
V_60 = F_24 ( V_4 , V_55 ) ;
if ( ! ( V_60 & F_36 ( V_4 ) ) )
return;
while ( 1 ) {
V_92 = F_53 ( V_101 , F_45 ( V_4 ) ) ;
if ( V_92 == 0 )
break;
if ( V_4 -> type == V_15 ) {
char V_61 = F_24 ( V_4 , V_63 ) ;
if ( F_54 ( V_4 , V_61 ) ||
V_1 -> V_37 )
V_92 = 0 ;
else
F_55 ( V_101 , V_61 , V_104 ) ;
} else {
for ( V_29 = 0 ; V_29 < V_92 ; V_29 ++ ) {
char V_61 = F_24 ( V_4 , V_63 ) ;
V_60 = F_24 ( V_4 , V_55 ) ;
#if F_56 ( V_105 )
if ( V_1 -> V_37 ) {
if ( ( V_61 == 0 ) &&
( V_60 & F_57 ( V_4 ) ) ) {
V_92 -- ; V_29 -- ;
continue;
}
F_58 ( V_4 -> V_30 , L_3 , V_61 ) ;
V_1 -> V_37 = 0 ;
if ( F_59 ( V_61 ) ) {
V_92 -- ; V_29 -- ;
continue;
}
}
#endif
if ( F_54 ( V_4 , V_61 ) ) {
V_92 -- ; V_29 -- ;
continue;
}
if ( V_60 & F_57 ( V_4 ) ) {
V_103 = V_106 ;
V_4 -> V_97 . V_107 ++ ;
F_60 ( V_4 -> V_30 , L_4 ) ;
} else if ( V_60 & F_61 ( V_4 ) ) {
V_103 = V_108 ;
V_4 -> V_97 . V_109 ++ ;
F_60 ( V_4 -> V_30 , L_5 ) ;
} else
V_103 = V_104 ;
F_55 ( V_101 , V_61 , V_103 ) ;
}
}
F_24 ( V_4 , V_55 ) ;
F_32 ( V_4 , F_37 ( V_4 ) ) ;
V_102 += V_92 ;
V_4 -> V_97 . V_110 += V_92 ;
}
if ( V_102 ) {
F_62 ( V_101 ) ;
} else {
F_24 ( V_4 , V_55 ) ;
F_32 ( V_4 , F_37 ( V_4 ) ) ;
}
}
static inline void F_63 ( struct V_1 * V_4 )
{
F_64 ( & V_4 -> V_36 , V_111 + V_112 ) ;
}
static void F_65 ( unsigned long V_113 )
{
struct V_1 * V_4 = (struct V_1 * ) V_113 ;
if ( F_46 ( & V_4 -> V_4 ) == 0 ) {
V_4 -> V_37 = 1 ;
F_63 ( V_4 ) ;
} else if ( V_4 -> V_37 == 1 ) {
V_4 -> V_37 = 2 ;
F_63 ( V_4 ) ;
} else
V_4 -> V_37 = 0 ;
}
static int F_66 ( struct V_2 * V_4 )
{
int V_102 = 0 ;
unsigned short V_60 = F_24 ( V_4 , V_55 ) ;
struct V_100 * V_101 = & V_4 -> V_48 -> V_4 ;
struct V_1 * V_41 = F_1 ( V_4 ) ;
if ( V_60 & V_41 -> V_56 ) {
V_4 -> V_97 . V_114 ++ ;
if ( F_55 ( V_101 , 0 , V_115 ) )
V_102 ++ ;
F_60 ( V_4 -> V_30 , L_6 ) ;
}
if ( V_60 & F_57 ( V_4 ) ) {
if ( F_46 ( V_4 ) == 0 ) {
struct V_1 * V_1 = F_1 ( V_4 ) ;
if ( ! V_1 -> V_37 ) {
V_4 -> V_97 . V_116 ++ ;
V_1 -> V_37 = 1 ;
F_63 ( V_1 ) ;
if ( F_67 ( V_4 ) )
return 0 ;
F_58 ( V_4 -> V_30 , L_7 ) ;
if ( F_55 ( V_101 , 0 , V_117 ) )
V_102 ++ ;
}
} else {
V_4 -> V_97 . V_107 ++ ;
if ( F_55 ( V_101 , 0 , V_106 ) )
V_102 ++ ;
F_60 ( V_4 -> V_30 , L_4 ) ;
}
}
if ( V_60 & F_61 ( V_4 ) ) {
V_4 -> V_97 . V_109 ++ ;
if ( F_55 ( V_101 , 0 , V_108 ) )
V_102 ++ ;
F_60 ( V_4 -> V_30 , L_5 ) ;
}
if ( V_102 )
F_62 ( V_101 ) ;
return V_102 ;
}
static int F_68 ( struct V_2 * V_4 )
{
struct V_100 * V_101 = & V_4 -> V_48 -> V_4 ;
struct V_1 * V_41 = F_1 ( V_4 ) ;
const struct V_7 * V_8 ;
int V_102 = 0 ;
T_1 V_60 ;
V_8 = F_4 ( V_4 , V_41 -> V_118 ) ;
if ( ! V_8 -> V_9 )
return 0 ;
V_60 = F_24 ( V_4 , V_41 -> V_118 ) ;
if ( V_60 & V_41 -> V_56 ) {
V_60 &= ~ V_41 -> V_56 ;
F_25 ( V_4 , V_41 -> V_118 , V_60 ) ;
V_4 -> V_97 . V_114 ++ ;
F_55 ( V_101 , 0 , V_115 ) ;
F_62 ( V_101 ) ;
F_58 ( V_4 -> V_30 , L_6 ) ;
V_102 ++ ;
}
return V_102 ;
}
static int F_69 ( struct V_2 * V_4 )
{
int V_102 = 0 ;
unsigned short V_60 = F_24 ( V_4 , V_55 ) ;
struct V_100 * V_101 = & V_4 -> V_48 -> V_4 ;
struct V_1 * V_41 = F_1 ( V_4 ) ;
if ( F_67 ( V_4 ) )
return 0 ;
if ( ! V_41 -> V_37 && V_60 & F_70 ( V_4 ) ) {
#if F_56 ( V_105 )
V_41 -> V_37 = 1 ;
#endif
V_4 -> V_97 . V_116 ++ ;
if ( F_55 ( V_101 , 0 , V_117 ) )
V_102 ++ ;
F_58 ( V_4 -> V_30 , L_7 ) ;
}
if ( V_102 )
F_62 ( V_101 ) ;
V_102 += F_68 ( V_4 ) ;
return V_102 ;
}
static void F_71 ( void * V_119 )
{
struct V_1 * V_41 = V_119 ;
struct V_2 * V_4 = & V_41 -> V_4 ;
struct V_90 * V_49 = & V_4 -> V_48 -> V_49 ;
unsigned long V_120 ;
F_58 ( V_4 -> V_30 , L_8 , V_121 , V_4 -> line ) ;
F_72 ( & V_4 -> V_122 , V_120 ) ;
V_49 -> V_95 += V_41 -> V_123 ;
V_49 -> V_95 &= V_96 - 1 ;
V_4 -> V_97 . V_98 += V_41 -> V_123 ;
if ( F_50 ( V_49 ) < V_99 )
F_51 ( V_4 ) ;
if ( ! F_26 ( V_49 ) ) {
V_41 -> V_50 = 0 ;
F_28 ( & V_41 -> V_51 ) ;
} else {
V_41 -> V_50 = - V_28 ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
T_1 V_42 = F_24 ( V_4 , V_45 ) ;
F_25 ( V_4 , V_45 , V_42 & ~ V_52 ) ;
}
}
F_73 ( & V_4 -> V_122 , V_120 ) ;
}
static int F_74 ( struct V_1 * V_41 , void * V_94 , T_2 V_92 )
{
struct V_2 * V_4 = & V_41 -> V_4 ;
struct V_100 * V_101 = & V_4 -> V_48 -> V_4 ;
int V_102 ;
V_102 = F_75 ( V_101 , V_94 , V_92 ) ;
if ( V_102 < V_92 ) {
F_76 ( V_4 -> V_30 , L_9 ,
V_92 - V_102 ) ;
V_4 -> V_97 . V_124 ++ ;
}
V_4 -> V_97 . V_110 += V_102 ;
return V_102 ;
}
static int F_77 ( struct V_1 * V_41 )
{
unsigned int V_29 ;
for ( V_29 = 0 ; V_29 < F_78 ( V_41 -> V_125 ) ; V_29 ++ )
if ( V_41 -> V_126 == V_41 -> V_125 [ V_29 ] )
return V_29 ;
F_79 ( V_41 -> V_4 . V_30 , L_10 , V_121 ,
V_41 -> V_126 ) ;
return - 1 ;
}
static void F_80 ( struct V_1 * V_41 , bool V_127 )
{
struct V_128 * V_129 = V_41 -> V_130 ;
struct V_2 * V_4 = & V_41 -> V_4 ;
unsigned long V_120 ;
F_72 ( & V_4 -> V_122 , V_120 ) ;
V_41 -> V_130 = NULL ;
V_41 -> V_125 [ 0 ] = V_41 -> V_125 [ 1 ] = - V_28 ;
F_73 ( & V_4 -> V_122 , V_120 ) ;
F_81 ( V_129 ) ;
F_82 ( V_129 -> V_131 -> V_30 , V_41 -> V_132 * 2 , V_41 -> V_133 [ 0 ] ,
F_83 ( & V_41 -> V_134 [ 0 ] ) ) ;
F_84 ( V_129 ) ;
if ( V_127 )
F_30 ( V_4 ) ;
}
static void F_85 ( void * V_119 )
{
struct V_1 * V_41 = V_119 ;
struct V_128 * V_129 = V_41 -> V_130 ;
struct V_2 * V_4 = & V_41 -> V_4 ;
struct V_135 * V_136 ;
unsigned long V_120 ;
int V_137 , V_92 = 0 ;
F_58 ( V_4 -> V_30 , L_11 , V_121 , V_4 -> line ,
V_41 -> V_126 ) ;
F_72 ( & V_4 -> V_122 , V_120 ) ;
V_137 = F_77 ( V_41 ) ;
if ( V_137 >= 0 )
V_92 = F_74 ( V_41 , V_41 -> V_133 [ V_137 ] , V_41 -> V_132 ) ;
F_64 ( & V_41 -> V_138 , V_111 + V_41 -> V_139 ) ;
if ( V_92 )
F_62 ( & V_4 -> V_48 -> V_4 ) ;
V_136 = F_86 ( V_41 -> V_130 , & V_41 -> V_134 [ V_137 ] , 1 ,
V_140 ,
V_141 | V_142 ) ;
if ( ! V_136 )
goto V_143;
V_136 -> V_144 = F_85 ;
V_136 -> V_145 = V_41 ;
V_41 -> V_125 [ V_137 ] = F_87 ( V_136 ) ;
if ( F_27 ( V_41 -> V_125 [ V_137 ] ) )
goto V_143;
V_41 -> V_126 = V_41 -> V_125 [ ! V_137 ] ;
F_88 ( V_129 ) ;
F_58 ( V_4 -> V_30 , L_12 ,
V_121 , V_41 -> V_125 [ V_137 ] , V_137 , V_41 -> V_126 ) ;
F_73 ( & V_4 -> V_122 , V_120 ) ;
return;
V_143:
F_73 ( & V_4 -> V_122 , V_120 ) ;
F_76 ( V_4 -> V_30 , L_13 ) ;
F_80 ( V_41 , true ) ;
}
static void F_89 ( struct V_1 * V_41 , bool V_127 )
{
struct V_128 * V_129 = V_41 -> V_46 ;
struct V_2 * V_4 = & V_41 -> V_4 ;
unsigned long V_120 ;
F_72 ( & V_4 -> V_122 , V_120 ) ;
V_41 -> V_46 = NULL ;
V_41 -> V_50 = - V_28 ;
F_73 ( & V_4 -> V_122 , V_120 ) ;
F_81 ( V_129 ) ;
F_90 ( V_129 -> V_131 -> V_30 , V_41 -> V_146 , V_96 ,
V_147 ) ;
F_84 ( V_129 ) ;
if ( V_127 )
F_22 ( V_4 ) ;
}
static void F_91 ( struct V_1 * V_41 )
{
struct V_128 * V_129 = V_41 -> V_130 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < 2 ; V_29 ++ ) {
struct V_148 * V_149 = & V_41 -> V_134 [ V_29 ] ;
struct V_135 * V_136 ;
V_136 = F_86 ( V_129 ,
V_149 , 1 , V_140 ,
V_141 | V_142 ) ;
if ( ! V_136 )
goto V_143;
V_136 -> V_144 = F_85 ;
V_136 -> V_145 = V_41 ;
V_41 -> V_125 [ V_29 ] = F_87 ( V_136 ) ;
if ( F_27 ( V_41 -> V_125 [ V_29 ] ) )
goto V_143;
F_58 ( V_41 -> V_4 . V_30 , L_14 , V_121 ,
V_41 -> V_125 [ V_29 ] , V_29 ) ;
}
V_41 -> V_126 = V_41 -> V_125 [ 0 ] ;
F_88 ( V_129 ) ;
return;
V_143:
if ( V_29 )
F_81 ( V_129 ) ;
for ( V_29 = 0 ; V_29 < 2 ; V_29 ++ )
V_41 -> V_125 [ V_29 ] = - V_28 ;
V_41 -> V_126 = - V_28 ;
F_76 ( V_41 -> V_4 . V_30 , L_15 ) ;
F_80 ( V_41 , true ) ;
}
static void F_92 ( struct V_150 * V_151 )
{
struct V_1 * V_41 = F_2 ( V_151 , struct V_1 , V_51 ) ;
struct V_135 * V_136 ;
struct V_128 * V_129 = V_41 -> V_46 ;
struct V_2 * V_4 = & V_41 -> V_4 ;
struct V_90 * V_49 = & V_4 -> V_48 -> V_49 ;
T_3 V_94 ;
F_93 ( & V_4 -> V_122 ) ;
V_94 = V_41 -> V_146 + ( V_49 -> V_95 & ( V_96 - 1 ) ) ;
V_41 -> V_123 = F_94 (unsigned int,
CIRC_CNT(xmit->head, xmit->tail, UART_XMIT_SIZE),
CIRC_CNT_TO_END(xmit->head, xmit->tail, UART_XMIT_SIZE)) ;
F_95 ( & V_4 -> V_122 ) ;
V_136 = F_96 ( V_129 , V_94 , V_41 -> V_123 ,
V_152 ,
V_141 | V_142 ) ;
if ( ! V_136 ) {
F_76 ( V_4 -> V_30 , L_16 ) ;
F_89 ( V_41 , true ) ;
return;
}
F_97 ( V_129 -> V_131 -> V_30 , V_94 , V_41 -> V_123 ,
V_147 ) ;
F_93 ( & V_4 -> V_122 ) ;
V_136 -> V_144 = F_71 ;
V_136 -> V_145 = V_41 ;
F_95 ( & V_4 -> V_122 ) ;
V_41 -> V_50 = F_87 ( V_136 ) ;
if ( F_27 ( V_41 -> V_50 ) ) {
F_76 ( V_4 -> V_30 , L_17 ) ;
F_89 ( V_41 , true ) ;
return;
}
F_58 ( V_4 -> V_30 , L_18 ,
V_121 , V_49 -> V_94 , V_49 -> V_95 , V_49 -> V_153 , V_41 -> V_50 ) ;
F_88 ( V_129 ) ;
}
static void F_98 ( unsigned long V_119 )
{
struct V_1 * V_41 = (struct V_1 * ) V_119 ;
struct V_128 * V_129 = V_41 -> V_130 ;
struct V_2 * V_4 = & V_41 -> V_4 ;
struct V_154 V_48 ;
enum V_155 V_60 ;
unsigned long V_120 ;
unsigned int V_156 ;
int V_137 , V_92 ;
T_1 V_44 ;
F_72 ( & V_4 -> V_122 , V_120 ) ;
F_58 ( V_4 -> V_30 , L_19 ) ;
V_137 = F_77 ( V_41 ) ;
if ( V_137 < 0 ) {
F_73 ( & V_4 -> V_122 , V_120 ) ;
return;
}
V_60 = F_99 ( V_41 -> V_130 , V_41 -> V_126 , & V_48 ) ;
if ( V_60 == V_157 ) {
F_58 ( V_4 -> V_30 , L_20 ,
V_41 -> V_126 , V_137 ) ;
F_73 ( & V_4 -> V_122 , V_120 ) ;
return;
}
F_100 ( V_129 ) ;
V_60 = F_99 ( V_41 -> V_130 , V_41 -> V_126 , & V_48 ) ;
if ( V_60 == V_157 ) {
F_73 ( & V_4 -> V_122 , V_120 ) ;
F_58 ( V_4 -> V_30 , L_21 ) ;
return;
}
F_81 ( V_41 -> V_130 ) ;
V_156 = F_101 ( & V_41 -> V_134 [ V_137 ] ) - V_48 . V_158 ;
F_58 ( V_4 -> V_30 , L_22 , V_156 ,
V_41 -> V_126 ) ;
if ( V_156 ) {
V_92 = F_74 ( V_41 , V_41 -> V_133 [ V_137 ] , V_156 ) ;
if ( V_92 )
F_62 ( & V_4 -> V_48 -> V_4 ) ;
}
if ( V_4 -> type == V_20 || V_4 -> type == V_22 )
F_91 ( V_41 ) ;
V_44 = F_24 ( V_4 , V_45 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
V_44 &= ~ V_53 ;
F_102 ( V_41 -> V_159 [ V_160 ] ) ;
}
F_25 ( V_4 , V_45 , V_44 | V_38 ) ;
F_73 ( & V_4 -> V_122 , V_120 ) ;
}
static struct V_128 * F_103 ( struct V_2 * V_4 ,
enum V_161 V_162 ,
unsigned int V_163 )
{
T_4 V_54 ;
struct V_128 * V_129 ;
struct V_164 V_14 ;
int V_165 ;
F_104 ( V_54 ) ;
F_105 ( V_166 , V_54 ) ;
V_129 = F_106 ( V_54 , V_167 ,
( void * ) ( unsigned long ) V_163 , V_4 -> V_30 ,
V_162 == V_152 ? L_23 : L_24 ) ;
if ( ! V_129 ) {
F_76 ( V_4 -> V_30 ,
L_25 ) ;
return NULL ;
}
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_168 = V_162 ;
if ( V_162 == V_152 ) {
V_14 . V_169 = V_4 -> V_170 +
( F_4 ( V_4 , V_64 ) -> V_6 << V_4 -> V_11 ) ;
V_14 . V_171 = V_172 ;
} else {
V_14 . V_173 = V_4 -> V_170 +
( F_4 ( V_4 , V_63 ) -> V_6 << V_4 -> V_11 ) ;
V_14 . V_174 = V_172 ;
}
V_165 = F_107 ( V_129 , & V_14 ) ;
if ( V_165 ) {
F_76 ( V_4 -> V_30 , L_26 , V_165 ) ;
F_84 ( V_129 ) ;
return NULL ;
}
return V_129 ;
}
static void F_108 ( struct V_2 * V_4 )
{
struct V_1 * V_41 = F_1 ( V_4 ) ;
struct V_128 * V_129 ;
F_58 ( V_4 -> V_30 , L_27 , V_121 , V_4 -> line ) ;
if ( ! V_4 -> V_30 -> V_175 &&
( V_41 -> V_14 -> V_176 <= 0 || V_41 -> V_14 -> V_177 <= 0 ) )
return;
V_41 -> V_50 = - V_28 ;
V_129 = F_103 ( V_4 , V_152 , V_41 -> V_14 -> V_176 ) ;
F_58 ( V_4 -> V_30 , L_28 , V_121 , V_129 ) ;
if ( V_129 ) {
V_41 -> V_46 = V_129 ;
V_41 -> V_146 = F_109 ( V_129 -> V_131 -> V_30 ,
V_4 -> V_48 -> V_49 . V_94 ,
V_96 ,
V_147 ) ;
if ( F_110 ( V_129 -> V_131 -> V_30 , V_41 -> V_146 ) ) {
F_76 ( V_4 -> V_30 , L_29 ) ;
F_84 ( V_129 ) ;
V_41 -> V_46 = NULL ;
} else {
F_58 ( V_4 -> V_30 , L_30 ,
V_121 , V_96 ,
V_4 -> V_48 -> V_49 . V_94 , & V_41 -> V_146 ) ;
}
F_111 ( & V_41 -> V_51 , F_92 ) ;
}
V_129 = F_103 ( V_4 , V_140 , V_41 -> V_14 -> V_177 ) ;
F_58 ( V_4 -> V_30 , L_31 , V_121 , V_129 ) ;
if ( V_129 ) {
unsigned int V_29 ;
T_3 V_178 ;
void * V_94 ;
V_41 -> V_130 = V_129 ;
V_41 -> V_132 = 2 * F_112 ( T_2 , 16 , V_4 -> V_83 ) ;
V_94 = F_113 ( V_129 -> V_131 -> V_30 , V_41 -> V_132 * 2 ,
& V_178 , V_179 ) ;
if ( ! V_94 ) {
F_76 ( V_4 -> V_30 ,
L_32 ) ;
F_84 ( V_129 ) ;
V_41 -> V_130 = NULL ;
return;
}
for ( V_29 = 0 ; V_29 < 2 ; V_29 ++ ) {
struct V_148 * V_149 = & V_41 -> V_134 [ V_29 ] ;
F_114 ( V_149 , 1 ) ;
V_41 -> V_133 [ V_29 ] = V_94 ;
F_83 ( V_149 ) = V_178 ;
F_101 ( V_149 ) = V_41 -> V_132 ;
V_94 += V_41 -> V_132 ;
V_178 += V_41 -> V_132 ;
}
F_115 ( & V_41 -> V_138 , F_98 , ( unsigned long ) V_41 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 )
F_91 ( V_41 ) ;
}
}
static void F_116 ( struct V_2 * V_4 )
{
struct V_1 * V_41 = F_1 ( V_4 ) ;
if ( V_41 -> V_46 )
F_89 ( V_41 , false ) ;
if ( V_41 -> V_130 )
F_80 ( V_41 , false ) ;
}
static inline void F_108 ( struct V_2 * V_4 )
{
}
static inline void F_116 ( struct V_2 * V_4 )
{
}
static T_5 F_117 ( int V_180 , void * V_181 )
{
#ifdef F_23
struct V_2 * V_4 = V_181 ;
struct V_1 * V_41 = F_1 ( V_4 ) ;
if ( V_41 -> V_130 ) {
T_1 V_44 = F_24 ( V_4 , V_45 ) ;
T_1 V_182 = F_24 ( V_4 , V_55 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
F_118 ( V_180 ) ;
V_44 |= V_53 ;
} else {
V_44 &= ~ V_38 ;
F_91 ( V_41 ) ;
}
F_25 ( V_4 , V_45 , V_44 ) ;
F_25 ( V_4 , V_55 ,
V_182 & ~ ( V_183 | F_36 ( V_4 ) ) ) ;
F_58 ( V_4 -> V_30 , L_33 ,
V_111 , V_41 -> V_139 ) ;
F_64 ( & V_41 -> V_138 , V_111 + V_41 -> V_139 ) ;
return V_184 ;
}
#endif
F_52 ( V_181 ) ;
return V_184 ;
}
static T_5 F_119 ( int V_180 , void * V_181 )
{
struct V_2 * V_4 = V_181 ;
unsigned long V_120 ;
F_72 ( & V_4 -> V_122 , V_120 ) ;
F_48 ( V_4 ) ;
F_73 ( & V_4 -> V_122 , V_120 ) ;
return V_184 ;
}
static T_5 F_120 ( int V_180 , void * V_181 )
{
struct V_2 * V_4 = V_181 ;
struct V_1 * V_41 = F_1 ( V_4 ) ;
if ( V_4 -> type == V_15 ) {
if ( F_66 ( V_4 ) ) {
F_24 ( V_4 , V_55 ) ;
F_32 ( V_4 , F_37 ( V_4 ) ) ;
}
} else {
F_68 ( V_4 ) ;
if ( ! V_41 -> V_130 )
F_52 ( V_181 ) ;
}
F_32 ( V_4 , F_35 ( V_4 ) ) ;
if ( ! V_41 -> V_46 )
F_119 ( V_180 , V_181 ) ;
return V_184 ;
}
static T_5 F_121 ( int V_180 , void * V_181 )
{
struct V_2 * V_4 = V_181 ;
F_69 ( V_4 ) ;
F_32 ( V_4 , F_122 ( V_4 ) ) ;
return V_184 ;
}
static T_5 F_123 ( int V_180 , void * V_181 )
{
unsigned short V_185 , V_186 , V_187 , V_188 = 0 ;
struct V_2 * V_4 = V_181 ;
struct V_1 * V_41 = F_1 ( V_4 ) ;
T_5 V_165 = V_189 ;
V_185 = F_24 ( V_4 , V_55 ) ;
V_186 = F_24 ( V_4 , V_45 ) ;
if ( V_41 -> V_118 == V_55 )
V_188 = V_185 ;
else {
if ( F_4 ( V_4 , V_41 -> V_118 ) -> V_9 )
V_188 = F_24 ( V_4 , V_41 -> V_118 ) ;
}
V_187 = V_186 & F_21 ( V_4 ) ;
if ( ( V_185 & F_39 ( V_4 ) ) && ( V_186 & V_52 ) &&
! V_41 -> V_46 )
V_165 = F_119 ( V_180 , V_181 ) ;
if ( ( ( V_185 & F_36 ( V_4 ) ) || V_41 -> V_130 ) &&
( V_186 & V_38 ) )
V_165 = F_117 ( V_180 , V_181 ) ;
if ( ( V_185 & F_34 ( V_4 ) ) && V_187 )
V_165 = F_120 ( V_180 , V_181 ) ;
if ( ( V_185 & F_70 ( V_4 ) ) && V_187 )
V_165 = F_121 ( V_180 , V_181 ) ;
if ( V_188 & V_41 -> V_56 ) {
F_68 ( V_4 ) ;
V_165 = V_184 ;
}
return V_165 ;
}
static int F_124 ( struct V_1 * V_4 )
{
struct V_2 * V_190 = & V_4 -> V_4 ;
int V_29 , V_191 , V_165 = 0 ;
for ( V_29 = V_191 = 0 ; V_29 < V_192 ; V_29 ++ , V_191 ++ ) {
const struct V_193 * V_136 ;
int V_180 ;
if ( F_125 ( V_4 ) ) {
V_29 = V_194 ;
V_180 = V_190 -> V_180 ;
} else {
V_180 = V_4 -> V_159 [ V_29 ] ;
if ( F_126 ( V_180 < 0 ) )
continue;
}
V_136 = V_193 + V_29 ;
V_4 -> V_195 [ V_191 ] = F_127 ( V_179 , L_34 ,
F_128 ( V_190 -> V_30 ) , V_136 -> V_136 ) ;
if ( ! V_4 -> V_195 [ V_191 ] )
goto V_196;
V_165 = F_129 ( V_180 , V_136 -> V_197 , V_190 -> V_198 ,
V_4 -> V_195 [ V_191 ] , V_4 ) ;
if ( F_126 ( V_165 ) ) {
F_79 ( V_190 -> V_30 , L_35 , V_136 -> V_136 ) ;
goto V_199;
}
}
return 0 ;
V_199:
while ( -- V_29 >= 0 )
F_130 ( V_4 -> V_159 [ V_29 ] , V_4 ) ;
V_196:
while ( -- V_191 >= 0 )
F_131 ( V_4 -> V_195 [ V_191 ] ) ;
return V_165 ;
}
static void F_132 ( struct V_1 * V_4 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < V_192 ; V_29 ++ ) {
int V_180 = V_4 -> V_159 [ V_29 ] ;
if ( F_126 ( V_180 < 0 ) )
continue;
F_130 ( V_4 -> V_159 [ V_29 ] , V_4 ) ;
F_131 ( V_4 -> V_195 [ V_29 ] ) ;
if ( F_125 ( V_4 ) ) {
return;
}
}
}
static unsigned int F_133 ( struct V_2 * V_4 )
{
unsigned short V_60 = F_24 ( V_4 , V_55 ) ;
unsigned short V_200 = F_43 ( V_4 ) ;
return ( V_60 & F_41 ( V_4 ) ) && ! V_200 ? V_201 : 0 ;
}
static void F_134 ( struct V_2 * V_4 , bool V_48 )
{
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
T_1 V_113 = F_24 ( V_4 , V_74 ) ;
if ( V_48 )
V_113 &= ~ V_75 ;
else
V_113 |= V_75 ;
F_25 ( V_4 , V_74 , V_113 ) ;
F_25 ( V_4 , V_68 ,
F_24 ( V_4 , V_68 ) | V_73 ) ;
} else if ( F_4 ( V_4 , V_77 ) -> V_9 ) {
T_1 V_42 = F_24 ( V_4 , V_77 ) ;
if ( V_48 )
V_42 &= ~ V_79 ;
else
V_42 |= V_79 ;
F_25 ( V_4 , V_77 , V_42 ) ;
}
}
static bool F_135 ( struct V_2 * V_4 )
{
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
return ! ( F_24 ( V_4 , V_74 ) & V_202 ) ;
} else if ( F_4 ( V_4 , V_77 ) -> V_9 ) {
return ! ( F_24 ( V_4 , V_77 ) & V_203 ) ;
}
return true ;
}
static void F_136 ( struct V_2 * V_4 , unsigned int V_204 )
{
struct V_1 * V_41 = F_1 ( V_4 ) ;
if ( V_204 & V_205 ) {
const struct V_7 * V_8 ;
V_8 = F_4 ( V_4 , V_206 ) ;
if ( V_8 -> V_9 )
F_25 ( V_4 , V_206 ,
F_24 ( V_4 , V_206 ) |
V_207 ) ;
}
F_137 ( V_41 -> V_208 , V_204 ) ;
if ( ! ( V_41 -> V_14 -> V_71 & V_72 ) )
return;
if ( ! ( V_204 & V_209 ) ) {
F_25 ( V_4 , V_206 ,
F_24 ( V_4 , V_206 ) & ~ V_210 ) ;
F_134 ( V_4 , 0 ) ;
} else if ( V_41 -> V_211 ) {
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
F_25 ( V_4 , V_68 ,
F_24 ( V_4 , V_68 ) & ~ V_73 ) ;
}
F_25 ( V_4 , V_206 ,
F_24 ( V_4 , V_206 ) | V_210 ) ;
} else {
F_134 ( V_4 , 1 ) ;
}
}
static unsigned int F_138 ( struct V_2 * V_4 )
{
struct V_1 * V_41 = F_1 ( V_4 ) ;
struct V_212 * V_208 = V_41 -> V_208 ;
unsigned int V_204 = 0 ;
F_139 ( V_208 , & V_204 ) ;
if ( V_41 -> V_211 ) {
if ( F_135 ( V_4 ) )
V_204 |= V_213 ;
} else if ( F_140 ( F_141 ( V_208 , V_214 ) ) ) {
V_204 |= V_213 ;
}
if ( F_140 ( F_141 ( V_208 , V_215 ) ) )
V_204 |= V_216 ;
if ( F_140 ( F_141 ( V_208 , V_217 ) ) )
V_204 |= V_218 ;
return V_204 ;
}
static void F_142 ( struct V_2 * V_4 )
{
F_143 ( F_1 ( V_4 ) -> V_208 ) ;
}
static void F_144 ( struct V_2 * V_4 , int V_219 )
{
unsigned short V_39 , V_220 ;
if ( ! F_4 ( V_4 , V_77 ) -> V_9 ) {
return;
}
V_220 = F_24 ( V_4 , V_77 ) ;
V_39 = F_24 ( V_4 , V_45 ) ;
if ( V_219 == - 1 ) {
V_220 = ( V_220 | V_221 ) & ~ V_222 ;
V_39 &= ~ V_223 ;
} else {
V_220 = ( V_220 | V_222 ) & ~ V_221 ;
V_39 |= V_223 ;
}
F_25 ( V_4 , V_77 , V_220 ) ;
F_25 ( V_4 , V_45 , V_39 ) ;
}
static int F_145 ( struct V_2 * V_4 )
{
struct V_1 * V_41 = F_1 ( V_4 ) ;
int V_165 ;
F_58 ( V_4 -> V_30 , L_8 , V_121 , V_4 -> line ) ;
V_165 = F_124 ( V_41 ) ;
if ( F_126 ( V_165 < 0 ) )
return V_165 ;
F_108 ( V_4 ) ;
return 0 ;
}
static void F_146 ( struct V_2 * V_4 )
{
struct V_1 * V_41 = F_1 ( V_4 ) ;
unsigned long V_120 ;
T_1 V_44 ;
F_58 ( V_4 -> V_30 , L_8 , V_121 , V_4 -> line ) ;
V_41 -> V_211 = false ;
F_147 ( F_1 ( V_4 ) -> V_208 ) ;
F_72 ( & V_4 -> V_122 , V_120 ) ;
F_31 ( V_4 ) ;
F_29 ( V_4 ) ;
V_44 = F_24 ( V_4 , V_45 ) ;
F_25 ( V_4 , V_45 , V_44 & ( V_224 | V_225 ) ) ;
F_73 ( & V_4 -> V_122 , V_120 ) ;
#ifdef F_23
if ( V_41 -> V_130 ) {
F_58 ( V_4 -> V_30 , L_36 , V_121 ,
V_4 -> line ) ;
F_18 ( & V_41 -> V_138 ) ;
}
#endif
F_116 ( V_4 ) ;
F_132 ( V_41 ) ;
}
static int F_148 ( struct V_1 * V_41 , unsigned int V_226 ,
unsigned int * V_227 )
{
unsigned long V_228 = V_41 -> V_33 [ V_229 ] ;
int V_230 , V_231 = V_232 ;
unsigned int V_233 ;
if ( V_41 -> V_4 . type != V_26 )
V_228 *= 2 ;
F_149 (sr, s) {
V_230 = F_150 ( V_228 , V_233 ) - V_226 ;
if ( abs ( V_230 ) >= abs ( V_231 ) )
continue;
V_231 = V_230 ;
* V_227 = V_233 - 1 ;
if ( ! V_230 )
break;
}
F_58 ( V_41 -> V_4 . V_30 , L_37 , V_226 , V_231 ,
* V_227 + 1 ) ;
return V_231 ;
}
static int F_151 ( struct V_1 * V_41 , unsigned int V_226 ,
unsigned long V_228 , unsigned int * V_234 ,
unsigned int * V_227 )
{
int V_230 , V_231 = V_232 ;
unsigned int V_233 , V_235 ;
if ( V_41 -> V_4 . type != V_26 )
V_228 *= 2 ;
F_149 (sr, s) {
V_235 = F_150 ( V_228 , V_233 * V_226 ) ;
V_235 = F_152 ( V_235 , 1U , 65535U ) ;
V_230 = F_150 ( V_228 , V_233 * V_235 ) - V_226 ;
if ( abs ( V_230 ) >= abs ( V_231 ) )
continue;
V_231 = V_230 ;
* V_234 = V_235 ;
* V_227 = V_233 - 1 ;
if ( ! V_230 )
break;
}
F_58 ( V_41 -> V_4 . V_30 , L_38 , V_226 ,
V_231 , * V_234 , * V_227 + 1 ) ;
return V_231 ;
}
static int F_153 ( struct V_1 * V_41 , unsigned int V_226 ,
unsigned int * V_236 , unsigned int * V_227 ,
unsigned int * V_237 )
{
unsigned long V_228 = V_41 -> V_33 [ V_35 ] ;
unsigned int V_233 , V_238 , V_239 , V_240 , V_61 ;
int V_230 , V_231 = V_232 ;
if ( V_41 -> V_4 . type != V_26 )
V_228 *= 2 ;
F_149 (sr, s) {
for ( V_61 = 0 ; V_61 <= 3 ; V_61 ++ ) {
V_239 = V_233 * ( 1 << ( 2 * V_61 + 1 ) ) ;
if ( V_226 > V_241 / V_239 )
break;
V_240 = V_239 * V_226 ;
V_238 = F_150 ( V_228 , V_240 ) ;
V_238 = F_152 ( V_238 , 1U , 256U ) ;
V_230 = F_150 ( V_228 , V_238 * V_239 ) - V_226 ;
if ( abs ( V_230 ) >= abs ( V_231 ) )
continue;
V_231 = V_230 ;
* V_236 = V_238 - 1 ;
* V_227 = V_233 - 1 ;
* V_237 = V_61 ;
if ( ! V_230 )
goto V_242;
}
}
V_242:
F_58 ( V_41 -> V_4 . V_30 , L_39 , V_226 ,
V_231 , * V_236 , * V_227 + 1 , * V_237 ) ;
return V_231 ;
}
static void F_154 ( struct V_2 * V_4 )
{
const struct V_7 * V_8 ;
unsigned int V_60 ;
do {
V_60 = F_24 ( V_4 , V_55 ) ;
} while ( ! ( V_60 & F_41 ( V_4 ) ) );
F_25 ( V_4 , V_45 , 0x00 ) ;
V_8 = F_4 ( V_4 , V_206 ) ;
if ( V_8 -> V_9 )
F_25 ( V_4 , V_206 , V_243 | V_244 ) ;
F_32 ( V_4 ,
F_37 ( V_4 ) & F_35 ( V_4 ) &
F_122 ( V_4 ) ) ;
if ( F_4 ( V_4 , V_245 ) -> V_9 ) {
V_60 = F_24 ( V_4 , V_245 ) ;
V_60 &= ~ ( V_246 | V_247 ) ;
F_25 ( V_4 , V_245 , V_60 ) ;
}
}
static void F_155 ( struct V_2 * V_4 , struct V_248 * V_249 ,
struct V_248 * V_250 )
{
unsigned int V_251 , V_252 = V_253 , V_254 = 0 , V_29 ;
unsigned int V_236 = 255 , V_237 = 0 , V_227 = 15 , V_235 = 0 , V_255 = 0 ;
unsigned int V_256 = 255 , V_257 = 0 , V_258 = 15 , V_259 = 0 ;
struct V_1 * V_41 = F_1 ( V_4 ) ;
const struct V_7 * V_8 ;
int V_231 = V_232 , V_230 ;
unsigned long V_260 = 0 ;
int V_261 = - 1 ;
if ( ( V_249 -> V_262 & V_263 ) == V_264 )
V_252 |= V_265 ;
if ( V_249 -> V_262 & V_266 )
V_252 |= V_267 ;
if ( V_249 -> V_262 & V_268 )
V_252 |= V_267 | V_269 ;
if ( V_249 -> V_262 & V_270 )
V_252 |= V_271 ;
if ( ! V_4 -> V_34 ) {
V_251 = F_156 ( V_4 , V_249 , V_250 , 0 , 115200 ) ;
goto V_272;
}
for ( V_29 = 0 ; V_29 < V_31 ; V_29 ++ )
V_260 = F_157 ( V_260 , V_41 -> V_33 [ V_29 ] ) ;
V_251 = F_156 ( V_4 , V_249 , V_250 , 0 , V_260 / F_158 ( V_41 ) ) ;
if ( ! V_251 )
goto V_272;
if ( V_41 -> V_33 [ V_229 ] && V_4 -> type != V_20 &&
V_4 -> type != V_22 ) {
V_230 = F_148 ( V_41 , V_251 , & V_258 ) ;
if ( abs ( V_230 ) < abs ( V_231 ) ) {
V_261 = V_229 ;
V_254 = V_224 ;
V_255 = V_273 ;
V_231 = V_230 ;
V_227 = V_258 ;
if ( ! V_230 )
goto V_272;
}
}
if ( V_41 -> V_33 [ V_274 ] && F_4 ( V_4 , V_275 ) -> V_9 ) {
V_230 = F_151 ( V_41 , V_251 , V_41 -> V_33 [ V_274 ] , & V_259 ,
& V_258 ) ;
if ( abs ( V_230 ) < abs ( V_231 ) ) {
V_261 = V_274 ;
V_254 = V_224 ;
V_255 = 0 ;
V_231 = V_230 ;
V_235 = V_259 ;
V_227 = V_258 ;
if ( ! V_230 )
goto V_272;
}
}
if ( V_41 -> V_33 [ V_276 ] && F_4 ( V_4 , V_275 ) -> V_9 ) {
V_230 = F_151 ( V_41 , V_251 , V_41 -> V_33 [ V_276 ] , & V_259 ,
& V_258 ) ;
if ( abs ( V_230 ) < abs ( V_231 ) ) {
V_261 = V_276 ;
V_254 = V_224 ;
V_255 = V_277 ;
V_231 = V_230 ;
V_235 = V_259 ;
V_227 = V_258 ;
if ( ! V_231 )
goto V_272;
}
}
V_230 = F_153 ( V_41 , V_251 , & V_256 , & V_258 , & V_257 ) ;
if ( abs ( V_230 ) < abs ( V_231 ) ) {
V_261 = V_35 ;
V_254 = 0 ;
V_231 = V_230 ;
V_236 = V_256 ;
V_227 = V_258 ;
V_237 = V_257 ;
}
V_272:
if ( V_261 >= 0 )
F_58 ( V_4 -> V_30 , L_40 ,
V_41 -> V_32 [ V_261 ] , V_251 , V_231 ) ;
F_13 ( V_41 ) ;
if ( V_261 >= 0 && F_4 ( V_4 , V_278 ) -> V_9 ) {
F_25 ( V_4 , V_275 , V_235 ) ;
F_25 ( V_4 , V_278 , V_255 ) ;
}
F_154 ( V_4 ) ;
F_159 ( V_4 , V_249 -> V_262 , V_251 ) ;
if ( V_261 >= 0 ) {
if ( V_4 -> type == V_20 || V_4 -> type == V_22 )
switch ( V_227 + 1 ) {
case 5 : V_252 |= V_279 ; break;
case 7 : V_252 |= V_280 ; break;
case 11 : V_252 |= V_281 ; break;
case 13 : V_252 |= V_282 ; break;
case 16 : V_252 |= V_283 ; break;
case 17 : V_252 |= V_284 ; break;
case 19 : V_252 |= V_285 ; break;
case 27 : V_252 |= V_286 ; break;
}
V_252 |= V_237 ;
F_58 ( V_4 -> V_30 ,
L_41 ,
V_254 , V_252 , V_236 , V_255 , V_235 , V_227 ) ;
F_25 ( V_4 , V_45 , V_254 ) ;
F_25 ( V_4 , V_287 , V_252 ) ;
F_25 ( V_4 , V_288 , V_236 ) ;
if ( F_4 ( V_4 , V_289 ) -> V_9 )
F_25 ( V_4 , V_289 , V_227 | V_290 ) ;
F_160 ( ( 1000000 + ( V_251 - 1 ) ) / V_251 ) ;
} else {
V_254 = V_41 -> V_14 -> V_39 & ( V_224 | V_225 ) ;
V_252 |= F_24 ( V_4 , V_287 ) &
( V_291 | V_292 | V_293 ) ;
F_58 ( V_4 -> V_30 , L_42 , V_254 , V_252 ) ;
F_25 ( V_4 , V_45 , V_254 ) ;
F_25 ( V_4 , V_287 , V_252 ) ;
}
F_42 ( V_4 , V_249 -> V_262 ) ;
V_4 -> V_60 &= ~ V_294 ;
V_41 -> V_211 = false ;
V_8 = F_4 ( V_4 , V_206 ) ;
if ( V_8 -> V_9 ) {
unsigned short V_42 = F_24 ( V_4 , V_206 ) ;
if ( ( V_4 -> V_120 & V_295 ) &&
( V_249 -> V_262 & V_296 ) ) {
V_4 -> V_60 |= V_294 ;
V_41 -> V_211 = true ;
}
V_42 &= ~ ( V_243 | V_244 ) ;
F_25 ( V_4 , V_206 , V_42 ) ;
}
V_254 |= V_41 -> V_14 -> V_39 & ~ ( V_224 | V_225 ) ;
F_58 ( V_4 -> V_30 , L_43 , V_254 ) ;
F_25 ( V_4 , V_45 , V_254 ) ;
if ( ( V_227 + 1 == 5 ) &&
( V_4 -> type == V_20 || V_4 -> type == V_22 ) ) {
F_160 ( F_161 ( 10 * 1000000 , V_251 ) ) ;
}
#ifdef F_23
if ( V_41 -> V_130 ) {
unsigned int V_297 ;
switch ( V_249 -> V_262 & V_263 ) {
case V_298 :
V_297 = 7 ;
break;
case V_299 :
V_297 = 8 ;
break;
case V_264 :
V_297 = 9 ;
break;
default:
V_297 = 10 ;
break;
}
if ( V_249 -> V_262 & V_270 )
V_297 ++ ;
if ( V_249 -> V_262 & V_266 )
V_297 ++ ;
V_41 -> V_139 = F_161 ( ( V_41 -> V_132 * 2 * V_297 * V_300 ) /
( V_251 / 10 ) , 10 ) ;
F_58 ( V_4 -> V_30 , L_44 ,
V_41 -> V_139 * 1000 / V_300 , V_4 -> V_301 ) ;
if ( V_41 -> V_139 < F_162 ( 20 ) )
V_41 -> V_139 = F_162 ( 20 ) ;
}
#endif
if ( ( V_249 -> V_262 & V_302 ) != 0 )
F_30 ( V_4 ) ;
F_17 ( V_41 ) ;
if ( F_163 ( V_4 , V_249 -> V_262 ) )
F_142 ( V_4 ) ;
}
static void F_164 ( struct V_2 * V_4 , unsigned int V_48 ,
unsigned int V_303 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
switch ( V_48 ) {
case V_304 :
F_17 ( V_1 ) ;
break;
default:
F_13 ( V_1 ) ;
break;
}
}
static const char * F_165 ( struct V_2 * V_4 )
{
switch ( V_4 -> type ) {
case V_18 :
return L_45 ;
case V_15 :
return L_46 ;
case V_24 :
return L_47 ;
case V_20 :
return L_48 ;
case V_22 :
return L_49 ;
case V_26 :
return L_50 ;
}
return NULL ;
}
static int F_166 ( struct V_2 * V_4 )
{
struct V_1 * V_305 = F_1 ( V_4 ) ;
if ( V_4 -> V_10 )
return 0 ;
if ( V_4 -> V_120 & V_306 ) {
V_4 -> V_10 = F_167 ( V_4 -> V_170 , V_305 -> V_307 ) ;
if ( F_126 ( ! V_4 -> V_10 ) ) {
F_79 ( V_4 -> V_30 , L_51 , V_4 -> line ) ;
return - V_308 ;
}
} else {
V_4 -> V_10 = ( void V_88 * ) ( V_89 ) V_4 -> V_170 ;
}
return 0 ;
}
static void F_168 ( struct V_2 * V_4 )
{
struct V_1 * V_305 = F_1 ( V_4 ) ;
if ( V_4 -> V_120 & V_306 ) {
F_169 ( V_4 -> V_10 ) ;
V_4 -> V_10 = NULL ;
}
F_170 ( V_4 -> V_170 , V_305 -> V_307 ) ;
}
static int F_171 ( struct V_2 * V_4 )
{
struct V_309 * V_310 ;
struct V_1 * V_305 = F_1 ( V_4 ) ;
int V_165 ;
V_310 = F_172 ( V_4 -> V_170 , V_305 -> V_307 ,
F_128 ( V_4 -> V_30 ) ) ;
if ( F_126 ( V_310 == NULL ) ) {
F_79 ( V_4 -> V_30 , L_52 ) ;
return - V_311 ;
}
V_165 = F_166 ( V_4 ) ;
if ( F_126 ( V_165 != 0 ) ) {
F_173 ( V_310 ) ;
return V_165 ;
}
return 0 ;
}
static void F_174 ( struct V_2 * V_4 , int V_120 )
{
if ( V_120 & V_312 ) {
struct V_1 * V_305 = F_1 ( V_4 ) ;
V_4 -> type = V_305 -> V_14 -> type ;
F_171 ( V_4 ) ;
}
}
static int F_175 ( struct V_2 * V_4 , struct V_313 * V_314 )
{
if ( V_314 -> V_315 < 2400 )
return - V_28 ;
return 0 ;
}
static int F_176 ( struct V_1 * V_1 , struct V_131 * V_30 )
{
const char * V_316 [] = {
[ V_35 ] = L_53 ,
[ V_229 ] = L_54 ,
[ V_276 ] = L_55 ,
[ V_274 ] = L_56 ,
} ;
struct V_317 * V_317 ;
unsigned int V_29 ;
if ( V_1 -> V_14 -> type == V_26 )
V_316 [ V_229 ] = L_57 ;
for ( V_29 = 0 ; V_29 < V_31 ; V_29 ++ ) {
V_317 = F_177 ( V_30 , V_316 [ V_29 ] ) ;
if ( F_178 ( V_317 ) == - V_318 )
return - V_318 ;
if ( F_179 ( V_317 ) && V_29 == V_35 ) {
V_317 = F_177 ( V_30 , L_58 ) ;
if ( F_178 ( V_317 ) == - V_318 )
return - V_318 ;
if ( ! F_179 ( V_317 ) )
goto V_242;
V_317 = F_177 ( V_30 , L_59 ) ;
if ( ! F_179 ( V_317 ) )
goto V_242;
F_79 ( V_30 , L_60 , V_316 [ V_29 ] ,
F_178 ( V_317 ) ) ;
return F_178 ( V_317 ) ;
}
V_242:
if ( F_179 ( V_317 ) )
F_58 ( V_30 , L_60 , V_316 [ V_29 ] ,
F_178 ( V_317 ) ) ;
else
F_58 ( V_30 , L_61 , V_316 [ V_29 ] ,
V_317 , V_317 ) ;
V_1 -> V_32 [ V_29 ] = F_179 ( V_317 ) ? NULL : V_317 ;
}
return 0 ;
}
static int F_180 ( struct V_319 * V_30 ,
struct V_1 * V_1 , unsigned int V_320 ,
struct V_13 * V_5 , bool V_321 )
{
struct V_2 * V_4 = & V_1 -> V_4 ;
const struct V_309 * V_310 ;
unsigned int V_29 ;
int V_165 ;
V_1 -> V_14 = V_5 ;
V_4 -> V_66 = & V_322 ;
V_4 -> V_323 = V_324 ;
V_4 -> line = V_320 ;
V_310 = F_181 ( V_30 , V_325 , 0 ) ;
if ( V_310 == NULL )
return - V_326 ;
V_4 -> V_170 = V_310 -> V_327 ;
V_1 -> V_307 = F_182 ( V_310 ) ;
for ( V_29 = 0 ; V_29 < F_78 ( V_1 -> V_159 ) ; ++ V_29 )
V_1 -> V_159 [ V_29 ] = F_183 ( V_30 , V_29 ) ;
if ( V_1 -> V_159 [ 0 ] < 0 )
return - V_308 ;
if ( V_1 -> V_159 [ 1 ] < 0 ) {
V_1 -> V_159 [ 1 ] = V_1 -> V_159 [ 0 ] ;
V_1 -> V_159 [ 2 ] = V_1 -> V_159 [ 0 ] ;
V_1 -> V_159 [ 3 ] = V_1 -> V_159 [ 0 ] ;
}
if ( V_5 -> V_16 == V_328 ) {
V_165 = F_11 ( V_5 ) ;
if ( F_126 ( V_165 ) )
return V_165 ;
}
switch ( V_5 -> type ) {
case V_22 :
V_4 -> V_83 = 256 ;
V_1 -> V_118 = V_55 ;
V_1 -> V_56 = V_57 ;
V_1 -> V_329 = V_330 ;
break;
case V_26 :
V_4 -> V_83 = 128 ;
V_1 -> V_118 = V_245 ;
V_1 -> V_56 = V_247 ;
V_1 -> V_329 = F_184 ( 8 , 32 ) ;
break;
case V_20 :
V_4 -> V_83 = 64 ;
V_1 -> V_118 = V_55 ;
V_1 -> V_56 = V_57 ;
V_1 -> V_329 = V_330 ;
break;
case V_24 :
V_4 -> V_83 = 16 ;
if ( V_5 -> V_16 == V_331 ) {
V_1 -> V_118 = V_55 ;
V_1 -> V_56 = V_57 ;
V_1 -> V_329 = F_185 ( 16 ) ;
} else {
V_1 -> V_118 = V_245 ;
V_1 -> V_56 = V_247 ;
V_1 -> V_329 = F_185 ( 32 ) ;
}
break;
default:
V_4 -> V_83 = 1 ;
V_1 -> V_118 = V_55 ;
V_1 -> V_56 = V_332 ;
V_1 -> V_329 = F_185 ( 32 ) ;
break;
}
if ( V_5 -> V_333 )
V_1 -> V_329 = F_185 ( V_5 -> V_333 ) ;
if ( ! V_321 ) {
V_165 = F_176 ( V_1 , & V_30 -> V_30 ) ;
if ( V_165 < 0 )
return V_165 ;
V_4 -> V_30 = & V_30 -> V_30 ;
F_186 ( & V_30 -> V_30 ) ;
}
V_1 -> V_36 . V_113 = ( unsigned long ) V_1 ;
V_1 -> V_36 . V_334 = F_65 ;
F_187 ( & V_1 -> V_36 ) ;
if ( V_5 -> type == V_15 ) {
V_1 -> V_335 = V_336 ;
V_1 -> V_337 = V_338 ;
} else {
V_1 -> V_335 = V_339 ;
V_1 -> V_337 = V_340 ;
}
if ( V_1 -> V_118 == V_55 ) {
V_1 -> V_335 |= V_1 -> V_56 ;
V_1 -> V_337 &= ~ V_1 -> V_56 ;
}
V_4 -> type = V_5 -> type ;
V_4 -> V_120 = V_341 | V_5 -> V_120 ;
V_4 -> V_11 = V_5 -> V_11 ;
V_4 -> V_180 = V_1 -> V_159 [ V_160 ] ;
V_4 -> V_198 = 0 ;
V_4 -> V_342 = F_3 ;
V_4 -> V_343 = F_8 ;
if ( V_5 -> V_176 > 0 && V_5 -> V_177 > 0 )
F_58 ( V_4 -> V_30 , L_62 ,
V_5 -> V_176 , V_5 -> V_177 ) ;
return 0 ;
}
static void F_188 ( struct V_1 * V_4 )
{
F_189 ( V_4 -> V_4 . V_30 ) ;
}
static void F_190 ( struct V_2 * V_4 , int V_344 )
{
F_38 ( V_4 , V_344 ) ;
}
static void F_191 ( struct V_345 * V_346 , const char * V_41 ,
unsigned V_92 )
{
struct V_1 * V_1 = & V_347 [ V_346 -> V_320 ] ;
struct V_2 * V_4 = & V_1 -> V_4 ;
unsigned short V_297 , V_42 , V_348 ;
unsigned long V_120 ;
int V_349 = 1 ;
F_192 ( V_120 ) ;
#if F_56 ( V_350 )
if ( V_4 -> V_351 )
V_349 = 0 ;
else
#endif
if ( V_352 )
V_349 = F_193 ( & V_4 -> V_122 ) ;
else
F_194 ( & V_4 -> V_122 ) ;
V_42 = F_24 ( V_4 , V_45 ) ;
V_348 = ( V_1 -> V_14 -> V_39 & ~ ( V_224 | V_225 ) ) |
( V_42 & ( V_224 | V_225 ) ) ;
F_25 ( V_4 , V_45 , V_348 ) ;
F_195 ( V_4 , V_41 , V_92 , F_190 ) ;
V_297 = F_39 ( V_4 ) | F_41 ( V_4 ) ;
while ( ( F_24 ( V_4 , V_55 ) & V_297 ) != V_297 )
F_196 () ;
F_25 ( V_4 , V_45 , V_42 ) ;
if ( V_349 )
F_197 ( & V_4 -> V_122 ) ;
F_198 ( V_120 ) ;
}
static int F_199 ( struct V_345 * V_346 , char * V_353 )
{
struct V_1 * V_1 ;
struct V_2 * V_4 ;
int V_251 = 115200 ;
int V_297 = 8 ;
int V_109 = 'n' ;
int V_354 = 'n' ;
int V_165 ;
if ( V_346 -> V_320 < 0 || V_346 -> V_320 >= V_355 )
return - V_356 ;
V_1 = & V_347 [ V_346 -> V_320 ] ;
V_4 = & V_1 -> V_4 ;
if ( ! V_4 -> V_66 )
return - V_356 ;
V_165 = F_166 ( V_4 ) ;
if ( F_126 ( V_165 != 0 ) )
return V_165 ;
if ( V_353 )
F_200 ( V_353 , & V_251 , & V_109 , & V_297 , & V_354 ) ;
return F_201 ( V_4 , V_346 , V_251 , V_109 , V_297 , V_354 ) ;
}
static int F_202 ( struct V_319 * V_357 )
{
struct V_13 * V_14 = F_203 ( & V_357 -> V_30 ) ;
if ( V_358 . V_113 )
return - V_359 ;
V_358 . V_320 = V_357 -> V_163 ;
F_180 ( V_357 , & V_347 [ V_357 -> V_163 ] , V_357 -> V_163 , V_14 , true ) ;
F_199 ( & V_358 , V_360 ) ;
if ( ! strstr ( V_360 , L_63 ) )
V_358 . V_120 |= V_361 ;
F_204 ( & V_358 ) ;
return 0 ;
}
static inline int F_202 ( struct V_319 * V_357 )
{
return - V_28 ;
}
static int F_205 ( struct V_319 * V_30 )
{
struct V_1 * V_4 = F_206 ( V_30 ) ;
F_207 ( & V_362 , & V_4 -> V_4 ) ;
F_188 ( V_4 ) ;
return 0 ;
}
static struct V_13 *
F_208 ( struct V_319 * V_357 , unsigned int * V_363 )
{
struct V_364 * V_365 = V_357 -> V_30 . V_175 ;
const struct V_366 * V_367 ;
struct V_13 * V_5 ;
int V_163 ;
if ( ! F_209 ( V_368 ) || ! V_365 )
return NULL ;
V_367 = F_210 ( V_369 , V_365 ) ;
if ( ! V_367 )
return NULL ;
V_5 = F_211 ( & V_357 -> V_30 , sizeof( struct V_13 ) , V_179 ) ;
if ( ! V_5 )
return NULL ;
V_163 = F_212 ( V_365 , L_64 ) ;
if ( V_163 < 0 ) {
F_79 ( & V_357 -> V_30 , L_65 , V_163 ) ;
return NULL ;
}
* V_363 = V_163 ;
V_5 -> V_120 = V_306 | V_370 ;
V_5 -> type = F_213 ( V_367 -> V_113 ) ;
V_5 -> V_16 = F_214 ( V_367 -> V_113 ) ;
V_5 -> V_39 = V_371 | V_223 ;
if ( F_215 ( V_365 , L_66 , NULL ) )
V_5 -> V_71 |= V_72 ;
return V_5 ;
}
static int F_216 ( struct V_319 * V_30 ,
unsigned int V_320 ,
struct V_13 * V_5 ,
struct V_1 * V_372 )
{
int V_165 ;
if ( F_126 ( V_320 >= V_355 ) ) {
F_60 ( & V_30 -> V_30 , L_67 ,
V_320 + 1 , V_355 ) ;
F_60 ( & V_30 -> V_30 , L_68 ) ;
return - V_28 ;
}
V_165 = F_180 ( V_30 , V_372 , V_320 , V_5 , false ) ;
if ( V_165 )
return V_165 ;
V_372 -> V_208 = F_217 ( & V_372 -> V_4 , 0 ) ;
if ( F_179 ( V_372 -> V_208 ) && F_178 ( V_372 -> V_208 ) != - V_373 )
return F_178 ( V_372 -> V_208 ) ;
if ( V_5 -> V_71 & V_72 ) {
if ( ! F_140 ( F_141 ( V_372 -> V_208 ,
V_214 ) ) ||
! F_140 ( F_141 ( V_372 -> V_208 ,
V_374 ) ) ) {
F_79 ( & V_30 -> V_30 , L_69 ) ;
return - V_28 ;
}
V_372 -> V_4 . V_120 |= V_295 ;
}
V_165 = F_218 ( & V_362 , & V_372 -> V_4 ) ;
if ( V_165 ) {
F_188 ( V_372 ) ;
return V_165 ;
}
return 0 ;
}
static int F_219 ( struct V_319 * V_30 )
{
struct V_13 * V_5 ;
struct V_1 * V_375 ;
unsigned int V_363 ;
int V_165 ;
if ( F_220 ( V_30 ) )
return F_202 ( V_30 ) ;
if ( V_30 -> V_30 . V_175 ) {
V_5 = F_208 ( V_30 , & V_363 ) ;
if ( V_5 == NULL )
return - V_28 ;
} else {
V_5 = V_30 -> V_30 . V_376 ;
if ( V_5 == NULL ) {
F_79 ( & V_30 -> V_30 , L_70 ) ;
return - V_28 ;
}
V_363 = V_30 -> V_163 ;
}
V_375 = & V_347 [ V_363 ] ;
F_221 ( V_30 , V_375 ) ;
V_165 = F_216 ( V_30 , V_363 , V_5 , V_375 ) ;
if ( V_165 )
return V_165 ;
#ifdef F_222
F_223 () ;
#endif
return 0 ;
}
static T_6 int F_224 ( struct V_131 * V_30 )
{
struct V_1 * V_305 = F_225 ( V_30 ) ;
if ( V_305 )
F_226 ( & V_362 , & V_305 -> V_4 ) ;
return 0 ;
}
static T_6 int F_227 ( struct V_131 * V_30 )
{
struct V_1 * V_305 = F_225 ( V_30 ) ;
if ( V_305 )
F_228 ( & V_362 , & V_305 -> V_4 ) ;
return 0 ;
}
static int T_7 F_229 ( void )
{
int V_165 ;
F_230 ( L_71 , V_377 ) ;
V_165 = F_231 ( & V_362 ) ;
if ( F_232 ( V_165 == 0 ) ) {
V_165 = F_233 ( & V_378 ) ;
if ( F_126 ( V_165 ) )
F_234 ( & V_362 ) ;
}
return V_165 ;
}
static void T_8 F_235 ( void )
{
F_236 ( & V_378 ) ;
F_234 ( & V_362 ) ;
}
static int T_7 F_237 ( struct V_379 * V_131 ,
int type )
{
if ( ! V_131 -> V_4 . V_10 )
return - V_356 ;
V_131 -> V_4 . V_342 = F_3 ;
V_131 -> V_4 . V_343 = F_8 ;
V_131 -> V_4 . type = type ;
memcpy ( & V_347 [ 0 ] . V_4 , & V_131 -> V_4 , sizeof( struct V_2 ) ) ;
V_347 [ 0 ] . V_14 = & V_380 ;
V_347 [ 0 ] . V_14 -> type = type ;
F_11 ( V_347 [ 0 ] . V_14 ) ;
V_380 . V_39 = F_3 ( & V_347 [ 0 ] . V_4 , V_45 ) |
V_371 | V_223 ;
F_8 ( & V_347 [ 0 ] . V_4 , V_45 , V_380 . V_39 ) ;
V_131 -> V_381 -> V_382 = F_191 ;
return 0 ;
}
static int T_7 F_238 ( struct V_379 * V_131 ,
const char * V_383 )
{
return F_237 ( V_131 , V_15 ) ;
}
static int T_7 F_239 ( struct V_379 * V_131 ,
const char * V_383 )
{
return F_237 ( V_131 , V_24 ) ;
}
static int T_7 F_240 ( struct V_379 * V_131 ,
const char * V_383 )
{
return F_237 ( V_131 , V_20 ) ;
}
static int T_7 F_241 ( struct V_379 * V_131 ,
const char * V_383 )
{
return F_237 ( V_131 , V_22 ) ;
}
static int T_7 F_242 ( struct V_379 * V_131 ,
const char * V_383 )
{
return F_237 ( V_131 , V_26 ) ;
}
