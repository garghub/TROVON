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
const struct V_7 * V_8 = V_66 [ V_41 -> V_14 -> V_16 ] + V_67 ;
if ( V_41 -> V_14 -> V_68 && V_41 -> V_14 -> V_68 -> V_69 ) {
V_41 -> V_14 -> V_68 -> V_69 ( V_4 , V_65 ) ;
return;
}
if ( ! V_8 -> V_9 )
return;
if ( ( V_41 -> V_14 -> V_70 & V_71 ) &&
( ( ! ( V_65 & V_72 ) ) ) ) {
unsigned short V_60 ;
V_60 = F_24 ( V_4 , V_67 ) ;
V_60 &= ~ V_73 ;
V_60 |= V_74 ;
F_25 ( V_4 , V_67 , V_60 ) ;
}
}
static int F_43 ( struct V_2 * V_4 )
{
const struct V_7 * V_8 ;
V_8 = F_4 ( V_4 , V_75 ) ;
if ( V_8 -> V_9 )
return F_24 ( V_4 , V_75 ) & ( ( V_4 -> V_76 << 1 ) - 1 ) ;
V_8 = F_4 ( V_4 , V_77 ) ;
if ( V_8 -> V_9 )
return F_24 ( V_4 , V_77 ) >> 8 ;
return ! ( F_24 ( V_4 , V_55 ) & V_78 ) ;
}
static int F_44 ( struct V_2 * V_4 )
{
return V_4 -> V_76 - F_43 ( V_4 ) ;
}
static int F_45 ( struct V_2 * V_4 )
{
const struct V_7 * V_8 ;
V_8 = F_4 ( V_4 , V_79 ) ;
if ( V_8 -> V_9 )
return F_24 ( V_4 , V_79 ) & ( ( V_4 -> V_76 << 1 ) - 1 ) ;
V_8 = F_4 ( V_4 , V_77 ) ;
if ( V_8 -> V_9 )
return F_24 ( V_4 , V_77 ) & ( ( V_4 -> V_76 << 1 ) - 1 ) ;
return ( F_24 ( V_4 , V_55 ) & F_36 ( V_4 ) ) != 0 ;
}
static inline int F_46 ( struct V_2 * V_4 )
{
struct V_1 * V_41 = F_1 ( V_4 ) ;
if ( V_41 -> V_14 -> V_80 <= 0 )
return 1 ;
return ! ! F_47 ( ( void V_81 * ) ( V_82 ) V_41 -> V_14 -> V_80 ) ;
}
static void F_48 ( struct V_2 * V_4 )
{
struct V_83 * V_49 = & V_4 -> V_48 -> V_49 ;
unsigned int V_84 = F_49 ( V_4 ) ;
unsigned short V_60 ;
unsigned short V_42 ;
int V_85 ;
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
V_85 = F_44 ( V_4 ) ;
do {
unsigned char V_61 ;
if ( V_4 -> V_86 ) {
V_61 = V_4 -> V_86 ;
V_4 -> V_86 = 0 ;
} else if ( ! F_26 ( V_49 ) && ! V_84 ) {
V_61 = V_49 -> V_87 [ V_49 -> V_88 ] ;
V_49 -> V_88 = ( V_49 -> V_88 + 1 ) & ( V_89 - 1 ) ;
} else {
break;
}
F_25 ( V_4 , V_64 , V_61 ) ;
V_4 -> V_90 . V_91 ++ ;
} while ( -- V_85 > 0 );
F_32 ( V_4 , F_40 ( V_4 ) ) ;
if ( F_50 ( V_49 ) < V_92 )
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
struct V_93 * V_94 = & V_4 -> V_48 -> V_4 ;
int V_29 , V_85 , V_95 = 0 ;
unsigned short V_60 ;
unsigned char V_96 ;
V_60 = F_24 ( V_4 , V_55 ) ;
if ( ! ( V_60 & F_36 ( V_4 ) ) )
return;
while ( 1 ) {
V_85 = F_53 ( V_94 , F_45 ( V_4 ) ) ;
if ( V_85 == 0 )
break;
if ( V_4 -> type == V_15 ) {
char V_61 = F_24 ( V_4 , V_63 ) ;
if ( F_54 ( V_4 , V_61 ) ||
V_1 -> V_37 )
V_85 = 0 ;
else
F_55 ( V_94 , V_61 , V_97 ) ;
} else {
for ( V_29 = 0 ; V_29 < V_85 ; V_29 ++ ) {
char V_61 = F_24 ( V_4 , V_63 ) ;
V_60 = F_24 ( V_4 , V_55 ) ;
#if F_56 ( V_98 )
if ( V_1 -> V_37 ) {
if ( ( V_61 == 0 ) &&
( V_60 & F_57 ( V_4 ) ) ) {
V_85 -- ; V_29 -- ;
continue;
}
F_58 ( V_4 -> V_30 , L_3 , V_61 ) ;
V_1 -> V_37 = 0 ;
if ( F_59 ( V_61 ) ) {
V_85 -- ; V_29 -- ;
continue;
}
}
#endif
if ( F_54 ( V_4 , V_61 ) ) {
V_85 -- ; V_29 -- ;
continue;
}
if ( V_60 & F_57 ( V_4 ) ) {
V_96 = V_99 ;
V_4 -> V_90 . V_100 ++ ;
F_60 ( V_4 -> V_30 , L_4 ) ;
} else if ( V_60 & F_61 ( V_4 ) ) {
V_96 = V_101 ;
V_4 -> V_90 . V_102 ++ ;
F_60 ( V_4 -> V_30 , L_5 ) ;
} else
V_96 = V_97 ;
F_55 ( V_94 , V_61 , V_96 ) ;
}
}
F_24 ( V_4 , V_55 ) ;
F_32 ( V_4 , F_37 ( V_4 ) ) ;
V_95 += V_85 ;
V_4 -> V_90 . V_103 += V_85 ;
}
if ( V_95 ) {
F_62 ( V_94 ) ;
} else {
F_24 ( V_4 , V_55 ) ;
F_32 ( V_4 , F_37 ( V_4 ) ) ;
}
}
static inline void F_63 ( struct V_1 * V_4 )
{
F_64 ( & V_4 -> V_36 , V_104 + V_105 ) ;
}
static void F_65 ( unsigned long V_106 )
{
struct V_1 * V_4 = (struct V_1 * ) V_106 ;
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
int V_95 = 0 ;
unsigned short V_60 = F_24 ( V_4 , V_55 ) ;
struct V_93 * V_94 = & V_4 -> V_48 -> V_4 ;
struct V_1 * V_41 = F_1 ( V_4 ) ;
if ( V_60 & V_41 -> V_56 ) {
V_4 -> V_90 . V_107 ++ ;
if ( F_55 ( V_94 , 0 , V_108 ) )
V_95 ++ ;
F_60 ( V_4 -> V_30 , L_6 ) ;
}
if ( V_60 & F_57 ( V_4 ) ) {
if ( F_46 ( V_4 ) == 0 ) {
struct V_1 * V_1 = F_1 ( V_4 ) ;
if ( ! V_1 -> V_37 ) {
V_4 -> V_90 . V_109 ++ ;
V_1 -> V_37 = 1 ;
F_63 ( V_1 ) ;
if ( F_67 ( V_4 ) )
return 0 ;
F_58 ( V_4 -> V_30 , L_7 ) ;
if ( F_55 ( V_94 , 0 , V_110 ) )
V_95 ++ ;
}
} else {
V_4 -> V_90 . V_100 ++ ;
if ( F_55 ( V_94 , 0 , V_99 ) )
V_95 ++ ;
F_60 ( V_4 -> V_30 , L_4 ) ;
}
}
if ( V_60 & F_61 ( V_4 ) ) {
V_4 -> V_90 . V_102 ++ ;
if ( F_55 ( V_94 , 0 , V_101 ) )
V_95 ++ ;
F_60 ( V_4 -> V_30 , L_5 ) ;
}
if ( V_95 )
F_62 ( V_94 ) ;
return V_95 ;
}
static int F_68 ( struct V_2 * V_4 )
{
struct V_93 * V_94 = & V_4 -> V_48 -> V_4 ;
struct V_1 * V_41 = F_1 ( V_4 ) ;
const struct V_7 * V_8 ;
int V_95 = 0 ;
T_1 V_60 ;
V_8 = F_4 ( V_4 , V_41 -> V_111 ) ;
if ( ! V_8 -> V_9 )
return 0 ;
V_60 = F_24 ( V_4 , V_41 -> V_111 ) ;
if ( V_60 & V_41 -> V_56 ) {
V_60 &= ~ V_41 -> V_56 ;
F_25 ( V_4 , V_41 -> V_111 , V_60 ) ;
V_4 -> V_90 . V_107 ++ ;
F_55 ( V_94 , 0 , V_108 ) ;
F_62 ( V_94 ) ;
F_58 ( V_4 -> V_30 , L_6 ) ;
V_95 ++ ;
}
return V_95 ;
}
static int F_69 ( struct V_2 * V_4 )
{
int V_95 = 0 ;
unsigned short V_60 = F_24 ( V_4 , V_55 ) ;
struct V_93 * V_94 = & V_4 -> V_48 -> V_4 ;
struct V_1 * V_41 = F_1 ( V_4 ) ;
if ( F_67 ( V_4 ) )
return 0 ;
if ( ! V_41 -> V_37 && V_60 & F_70 ( V_4 ) ) {
#if F_56 ( V_98 )
V_41 -> V_37 = 1 ;
#endif
V_4 -> V_90 . V_109 ++ ;
if ( F_55 ( V_94 , 0 , V_110 ) )
V_95 ++ ;
F_58 ( V_4 -> V_30 , L_7 ) ;
}
if ( V_95 )
F_62 ( V_94 ) ;
V_95 += F_68 ( V_4 ) ;
return V_95 ;
}
static void F_71 ( void * V_112 )
{
struct V_1 * V_41 = V_112 ;
struct V_2 * V_4 = & V_41 -> V_4 ;
struct V_83 * V_49 = & V_4 -> V_48 -> V_49 ;
unsigned long V_113 ;
F_58 ( V_4 -> V_30 , L_8 , V_114 , V_4 -> line ) ;
F_72 ( & V_4 -> V_115 , V_113 ) ;
V_49 -> V_88 += V_41 -> V_116 ;
V_49 -> V_88 &= V_89 - 1 ;
V_4 -> V_90 . V_91 += V_41 -> V_116 ;
if ( F_50 ( V_49 ) < V_92 )
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
F_73 ( & V_4 -> V_115 , V_113 ) ;
}
static int F_74 ( struct V_1 * V_41 , void * V_87 , T_2 V_85 )
{
struct V_2 * V_4 = & V_41 -> V_4 ;
struct V_93 * V_94 = & V_4 -> V_48 -> V_4 ;
int V_95 ;
V_95 = F_75 ( V_94 , V_87 , V_85 ) ;
if ( V_95 < V_85 ) {
F_76 ( V_4 -> V_30 , L_9 ,
V_85 - V_95 ) ;
V_4 -> V_90 . V_117 ++ ;
}
V_4 -> V_90 . V_103 += V_95 ;
return V_95 ;
}
static int F_77 ( struct V_1 * V_41 )
{
unsigned int V_29 ;
for ( V_29 = 0 ; V_29 < F_78 ( V_41 -> V_118 ) ; V_29 ++ )
if ( V_41 -> V_119 == V_41 -> V_118 [ V_29 ] )
return V_29 ;
F_79 ( V_41 -> V_4 . V_30 , L_10 , V_114 ,
V_41 -> V_119 ) ;
return - 1 ;
}
static void F_80 ( struct V_1 * V_41 , bool V_120 )
{
struct V_121 * V_122 = V_41 -> V_123 ;
struct V_2 * V_4 = & V_41 -> V_4 ;
unsigned long V_113 ;
F_72 ( & V_4 -> V_115 , V_113 ) ;
V_41 -> V_123 = NULL ;
V_41 -> V_118 [ 0 ] = V_41 -> V_118 [ 1 ] = - V_28 ;
F_73 ( & V_4 -> V_115 , V_113 ) ;
F_81 ( V_122 ) ;
F_82 ( V_122 -> V_124 -> V_30 , V_41 -> V_125 * 2 , V_41 -> V_126 [ 0 ] ,
F_83 ( & V_41 -> V_127 [ 0 ] ) ) ;
F_84 ( V_122 ) ;
if ( V_120 )
F_30 ( V_4 ) ;
}
static void F_85 ( void * V_112 )
{
struct V_1 * V_41 = V_112 ;
struct V_121 * V_122 = V_41 -> V_123 ;
struct V_2 * V_4 = & V_41 -> V_4 ;
struct V_128 * V_129 ;
unsigned long V_113 ;
int V_130 , V_85 = 0 ;
F_58 ( V_4 -> V_30 , L_11 , V_114 , V_4 -> line ,
V_41 -> V_119 ) ;
F_72 ( & V_4 -> V_115 , V_113 ) ;
V_130 = F_77 ( V_41 ) ;
if ( V_130 >= 0 )
V_85 = F_74 ( V_41 , V_41 -> V_126 [ V_130 ] , V_41 -> V_125 ) ;
F_64 ( & V_41 -> V_131 , V_104 + V_41 -> V_132 ) ;
if ( V_85 )
F_62 ( & V_4 -> V_48 -> V_4 ) ;
V_129 = F_86 ( V_41 -> V_123 , & V_41 -> V_127 [ V_130 ] , 1 ,
V_133 ,
V_134 | V_135 ) ;
if ( ! V_129 )
goto V_136;
V_129 -> V_137 = F_85 ;
V_129 -> V_138 = V_41 ;
V_41 -> V_118 [ V_130 ] = F_87 ( V_129 ) ;
if ( F_27 ( V_41 -> V_118 [ V_130 ] ) )
goto V_136;
V_41 -> V_119 = V_41 -> V_118 [ ! V_130 ] ;
F_88 ( V_122 ) ;
F_58 ( V_4 -> V_30 , L_12 ,
V_114 , V_41 -> V_118 [ V_130 ] , V_130 , V_41 -> V_119 ) ;
F_73 ( & V_4 -> V_115 , V_113 ) ;
return;
V_136:
F_73 ( & V_4 -> V_115 , V_113 ) ;
F_76 ( V_4 -> V_30 , L_13 ) ;
F_80 ( V_41 , true ) ;
}
static void F_89 ( struct V_1 * V_41 , bool V_120 )
{
struct V_121 * V_122 = V_41 -> V_46 ;
struct V_2 * V_4 = & V_41 -> V_4 ;
unsigned long V_113 ;
F_72 ( & V_4 -> V_115 , V_113 ) ;
V_41 -> V_46 = NULL ;
V_41 -> V_50 = - V_28 ;
F_73 ( & V_4 -> V_115 , V_113 ) ;
F_81 ( V_122 ) ;
F_90 ( V_122 -> V_124 -> V_30 , V_41 -> V_139 , V_89 ,
V_140 ) ;
F_84 ( V_122 ) ;
if ( V_120 )
F_22 ( V_4 ) ;
}
static void F_91 ( struct V_1 * V_41 )
{
struct V_121 * V_122 = V_41 -> V_123 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < 2 ; V_29 ++ ) {
struct V_141 * V_142 = & V_41 -> V_127 [ V_29 ] ;
struct V_128 * V_129 ;
V_129 = F_86 ( V_122 ,
V_142 , 1 , V_133 ,
V_134 | V_135 ) ;
if ( ! V_129 )
goto V_136;
V_129 -> V_137 = F_85 ;
V_129 -> V_138 = V_41 ;
V_41 -> V_118 [ V_29 ] = F_87 ( V_129 ) ;
if ( F_27 ( V_41 -> V_118 [ V_29 ] ) )
goto V_136;
F_58 ( V_41 -> V_4 . V_30 , L_14 , V_114 ,
V_41 -> V_118 [ V_29 ] , V_29 ) ;
}
V_41 -> V_119 = V_41 -> V_118 [ 0 ] ;
F_88 ( V_122 ) ;
return;
V_136:
if ( V_29 )
F_81 ( V_122 ) ;
for ( V_29 = 0 ; V_29 < 2 ; V_29 ++ )
V_41 -> V_118 [ V_29 ] = - V_28 ;
V_41 -> V_119 = - V_28 ;
F_76 ( V_41 -> V_4 . V_30 , L_15 ) ;
F_80 ( V_41 , true ) ;
}
static void F_92 ( struct V_143 * V_144 )
{
struct V_1 * V_41 = F_2 ( V_144 , struct V_1 , V_51 ) ;
struct V_128 * V_129 ;
struct V_121 * V_122 = V_41 -> V_46 ;
struct V_2 * V_4 = & V_41 -> V_4 ;
struct V_83 * V_49 = & V_4 -> V_48 -> V_49 ;
T_3 V_87 ;
F_93 ( & V_4 -> V_115 ) ;
V_87 = V_41 -> V_139 + ( V_49 -> V_88 & ( V_89 - 1 ) ) ;
V_41 -> V_116 = F_94 (unsigned int,
CIRC_CNT(xmit->head, xmit->tail, UART_XMIT_SIZE),
CIRC_CNT_TO_END(xmit->head, xmit->tail, UART_XMIT_SIZE)) ;
F_95 ( & V_4 -> V_115 ) ;
V_129 = F_96 ( V_122 , V_87 , V_41 -> V_116 ,
V_145 ,
V_134 | V_135 ) ;
if ( ! V_129 ) {
F_76 ( V_4 -> V_30 , L_16 ) ;
F_89 ( V_41 , true ) ;
return;
}
F_97 ( V_122 -> V_124 -> V_30 , V_87 , V_41 -> V_116 ,
V_140 ) ;
F_93 ( & V_4 -> V_115 ) ;
V_129 -> V_137 = F_71 ;
V_129 -> V_138 = V_41 ;
F_95 ( & V_4 -> V_115 ) ;
V_41 -> V_50 = F_87 ( V_129 ) ;
if ( F_27 ( V_41 -> V_50 ) ) {
F_76 ( V_4 -> V_30 , L_17 ) ;
F_89 ( V_41 , true ) ;
return;
}
F_58 ( V_4 -> V_30 , L_18 ,
V_114 , V_49 -> V_87 , V_49 -> V_88 , V_49 -> V_146 , V_41 -> V_50 ) ;
F_88 ( V_122 ) ;
}
static void F_98 ( unsigned long V_112 )
{
struct V_1 * V_41 = (struct V_1 * ) V_112 ;
struct V_121 * V_122 = V_41 -> V_123 ;
struct V_2 * V_4 = & V_41 -> V_4 ;
struct V_147 V_48 ;
enum V_148 V_60 ;
unsigned long V_113 ;
unsigned int V_149 ;
int V_130 , V_85 ;
T_1 V_44 ;
F_72 ( & V_4 -> V_115 , V_113 ) ;
F_58 ( V_4 -> V_30 , L_19 ) ;
V_130 = F_77 ( V_41 ) ;
if ( V_130 < 0 ) {
F_73 ( & V_4 -> V_115 , V_113 ) ;
return;
}
V_60 = F_99 ( V_41 -> V_123 , V_41 -> V_119 , & V_48 ) ;
if ( V_60 == V_150 ) {
F_58 ( V_4 -> V_30 , L_20 ,
V_41 -> V_119 , V_130 ) ;
F_73 ( & V_4 -> V_115 , V_113 ) ;
return;
}
F_100 ( V_122 ) ;
V_60 = F_99 ( V_41 -> V_123 , V_41 -> V_119 , & V_48 ) ;
if ( V_60 == V_150 ) {
F_73 ( & V_4 -> V_115 , V_113 ) ;
F_58 ( V_4 -> V_30 , L_21 ) ;
return;
}
F_81 ( V_41 -> V_123 ) ;
V_149 = F_101 ( & V_41 -> V_127 [ V_130 ] ) - V_48 . V_151 ;
F_58 ( V_4 -> V_30 , L_22 , V_149 ,
V_41 -> V_119 ) ;
if ( V_149 ) {
V_85 = F_74 ( V_41 , V_41 -> V_126 [ V_130 ] , V_149 ) ;
if ( V_85 )
F_62 ( & V_4 -> V_48 -> V_4 ) ;
}
if ( V_4 -> type == V_20 || V_4 -> type == V_22 )
F_91 ( V_41 ) ;
V_44 = F_24 ( V_4 , V_45 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
V_44 &= ~ V_53 ;
F_102 ( V_41 -> V_152 [ V_153 ] ) ;
}
F_25 ( V_4 , V_45 , V_44 | V_38 ) ;
F_73 ( & V_4 -> V_115 , V_113 ) ;
}
static struct V_121 * F_103 ( struct V_2 * V_4 ,
enum V_154 V_155 ,
unsigned int V_156 )
{
T_4 V_54 ;
struct V_121 * V_122 ;
struct V_157 V_14 ;
int V_158 ;
F_104 ( V_54 ) ;
F_105 ( V_159 , V_54 ) ;
V_122 = F_106 ( V_54 , V_160 ,
( void * ) ( unsigned long ) V_156 , V_4 -> V_30 ,
V_155 == V_145 ? L_23 : L_24 ) ;
if ( ! V_122 ) {
F_76 ( V_4 -> V_30 ,
L_25 ) ;
return NULL ;
}
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_161 = V_155 ;
if ( V_155 == V_145 ) {
V_14 . V_162 = V_4 -> V_163 +
( F_4 ( V_4 , V_64 ) -> V_6 << V_4 -> V_11 ) ;
V_14 . V_164 = V_165 ;
} else {
V_14 . V_166 = V_4 -> V_163 +
( F_4 ( V_4 , V_63 ) -> V_6 << V_4 -> V_11 ) ;
V_14 . V_167 = V_165 ;
}
V_158 = F_107 ( V_122 , & V_14 ) ;
if ( V_158 ) {
F_76 ( V_4 -> V_30 , L_26 , V_158 ) ;
F_84 ( V_122 ) ;
return NULL ;
}
return V_122 ;
}
static void F_108 ( struct V_2 * V_4 )
{
struct V_1 * V_41 = F_1 ( V_4 ) ;
struct V_121 * V_122 ;
F_58 ( V_4 -> V_30 , L_27 , V_114 , V_4 -> line ) ;
if ( ! V_4 -> V_30 -> V_168 &&
( V_41 -> V_14 -> V_169 <= 0 || V_41 -> V_14 -> V_170 <= 0 ) )
return;
V_41 -> V_50 = - V_28 ;
V_122 = F_103 ( V_4 , V_145 , V_41 -> V_14 -> V_169 ) ;
F_58 ( V_4 -> V_30 , L_28 , V_114 , V_122 ) ;
if ( V_122 ) {
V_41 -> V_46 = V_122 ;
V_41 -> V_139 = F_109 ( V_122 -> V_124 -> V_30 ,
V_4 -> V_48 -> V_49 . V_87 ,
V_89 ,
V_140 ) ;
if ( F_110 ( V_122 -> V_124 -> V_30 , V_41 -> V_139 ) ) {
F_76 ( V_4 -> V_30 , L_29 ) ;
F_84 ( V_122 ) ;
V_41 -> V_46 = NULL ;
} else {
F_58 ( V_4 -> V_30 , L_30 ,
V_114 , V_89 ,
V_4 -> V_48 -> V_49 . V_87 , & V_41 -> V_139 ) ;
}
F_111 ( & V_41 -> V_51 , F_92 ) ;
}
V_122 = F_103 ( V_4 , V_133 , V_41 -> V_14 -> V_170 ) ;
F_58 ( V_4 -> V_30 , L_31 , V_114 , V_122 ) ;
if ( V_122 ) {
unsigned int V_29 ;
T_3 V_171 ;
void * V_87 ;
V_41 -> V_123 = V_122 ;
V_41 -> V_125 = 2 * F_112 ( T_2 , 16 , V_4 -> V_76 ) ;
V_87 = F_113 ( V_122 -> V_124 -> V_30 , V_41 -> V_125 * 2 ,
& V_171 , V_172 ) ;
if ( ! V_87 ) {
F_76 ( V_4 -> V_30 ,
L_32 ) ;
F_84 ( V_122 ) ;
V_41 -> V_123 = NULL ;
return;
}
for ( V_29 = 0 ; V_29 < 2 ; V_29 ++ ) {
struct V_141 * V_142 = & V_41 -> V_127 [ V_29 ] ;
F_114 ( V_142 , 1 ) ;
V_41 -> V_126 [ V_29 ] = V_87 ;
F_83 ( V_142 ) = V_171 ;
F_101 ( V_142 ) = V_41 -> V_125 ;
V_87 += V_41 -> V_125 ;
V_171 += V_41 -> V_125 ;
}
F_115 ( & V_41 -> V_131 , F_98 , ( unsigned long ) V_41 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 )
F_91 ( V_41 ) ;
}
}
static void F_116 ( struct V_2 * V_4 )
{
struct V_1 * V_41 = F_1 ( V_4 ) ;
if ( V_41 -> V_46 )
F_89 ( V_41 , false ) ;
if ( V_41 -> V_123 )
F_80 ( V_41 , false ) ;
}
static inline void F_108 ( struct V_2 * V_4 )
{
}
static inline void F_116 ( struct V_2 * V_4 )
{
}
static T_5 F_117 ( int V_173 , void * V_174 )
{
#ifdef F_23
struct V_2 * V_4 = V_174 ;
struct V_1 * V_41 = F_1 ( V_4 ) ;
if ( V_41 -> V_123 ) {
T_1 V_44 = F_24 ( V_4 , V_45 ) ;
T_1 V_175 = F_24 ( V_4 , V_55 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
F_118 ( V_173 ) ;
V_44 |= V_53 ;
} else {
V_44 &= ~ V_38 ;
F_91 ( V_41 ) ;
}
F_25 ( V_4 , V_45 , V_44 ) ;
F_25 ( V_4 , V_55 ,
V_175 & ~ ( V_176 | F_36 ( V_4 ) ) ) ;
F_58 ( V_4 -> V_30 , L_33 ,
V_104 , V_41 -> V_132 ) ;
F_64 ( & V_41 -> V_131 , V_104 + V_41 -> V_132 ) ;
return V_177 ;
}
#endif
F_52 ( V_174 ) ;
return V_177 ;
}
static T_5 F_119 ( int V_173 , void * V_174 )
{
struct V_2 * V_4 = V_174 ;
unsigned long V_113 ;
F_72 ( & V_4 -> V_115 , V_113 ) ;
F_48 ( V_4 ) ;
F_73 ( & V_4 -> V_115 , V_113 ) ;
return V_177 ;
}
static T_5 F_120 ( int V_173 , void * V_174 )
{
struct V_2 * V_4 = V_174 ;
struct V_1 * V_41 = F_1 ( V_4 ) ;
if ( V_4 -> type == V_15 ) {
if ( F_66 ( V_4 ) ) {
F_24 ( V_4 , V_55 ) ;
F_32 ( V_4 , F_37 ( V_4 ) ) ;
}
} else {
F_68 ( V_4 ) ;
if ( ! V_41 -> V_123 )
F_52 ( V_174 ) ;
}
F_32 ( V_4 , F_35 ( V_4 ) ) ;
if ( ! V_41 -> V_46 )
F_119 ( V_173 , V_174 ) ;
return V_177 ;
}
static T_5 F_121 ( int V_173 , void * V_174 )
{
struct V_2 * V_4 = V_174 ;
F_69 ( V_4 ) ;
F_32 ( V_4 , F_122 ( V_4 ) ) ;
return V_177 ;
}
static T_5 F_123 ( int V_173 , void * V_174 )
{
unsigned short V_178 , V_179 , V_180 , V_181 = 0 ;
struct V_2 * V_4 = V_174 ;
struct V_1 * V_41 = F_1 ( V_4 ) ;
T_5 V_158 = V_182 ;
V_178 = F_24 ( V_4 , V_55 ) ;
V_179 = F_24 ( V_4 , V_45 ) ;
if ( V_41 -> V_111 == V_55 )
V_181 = V_178 ;
else {
if ( F_4 ( V_4 , V_41 -> V_111 ) -> V_9 )
V_181 = F_24 ( V_4 , V_41 -> V_111 ) ;
}
V_180 = V_179 & F_21 ( V_4 ) ;
if ( ( V_178 & F_39 ( V_4 ) ) && ( V_179 & V_52 ) &&
! V_41 -> V_46 )
V_158 = F_119 ( V_173 , V_174 ) ;
if ( ( ( V_178 & F_36 ( V_4 ) ) || V_41 -> V_123 ) &&
( V_179 & V_38 ) )
V_158 = F_117 ( V_173 , V_174 ) ;
if ( ( V_178 & F_34 ( V_4 ) ) && V_180 )
V_158 = F_120 ( V_173 , V_174 ) ;
if ( ( V_178 & F_70 ( V_4 ) ) && V_180 )
V_158 = F_121 ( V_173 , V_174 ) ;
if ( V_181 & V_41 -> V_56 ) {
F_68 ( V_4 ) ;
V_158 = V_177 ;
}
return V_158 ;
}
static int F_124 ( struct V_1 * V_4 )
{
struct V_2 * V_183 = & V_4 -> V_4 ;
int V_29 , V_184 , V_158 = 0 ;
for ( V_29 = V_184 = 0 ; V_29 < V_185 ; V_29 ++ , V_184 ++ ) {
const struct V_186 * V_129 ;
int V_173 ;
if ( F_125 ( V_4 ) ) {
V_29 = V_187 ;
V_173 = V_183 -> V_173 ;
} else {
V_173 = V_4 -> V_152 [ V_29 ] ;
if ( F_126 ( V_173 < 0 ) )
continue;
}
V_129 = V_186 + V_29 ;
V_4 -> V_188 [ V_184 ] = F_127 ( V_172 , L_34 ,
F_128 ( V_183 -> V_30 ) , V_129 -> V_129 ) ;
if ( ! V_4 -> V_188 [ V_184 ] )
goto V_189;
V_158 = F_129 ( V_173 , V_129 -> V_190 , V_183 -> V_191 ,
V_4 -> V_188 [ V_184 ] , V_4 ) ;
if ( F_126 ( V_158 ) ) {
F_79 ( V_183 -> V_30 , L_35 , V_129 -> V_129 ) ;
goto V_192;
}
}
return 0 ;
V_192:
while ( -- V_29 >= 0 )
F_130 ( V_4 -> V_152 [ V_29 ] , V_4 ) ;
V_189:
while ( -- V_184 >= 0 )
F_131 ( V_4 -> V_188 [ V_184 ] ) ;
return V_158 ;
}
static void F_132 ( struct V_1 * V_4 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < V_185 ; V_29 ++ ) {
int V_173 = V_4 -> V_152 [ V_29 ] ;
if ( F_126 ( V_173 < 0 ) )
continue;
F_130 ( V_4 -> V_152 [ V_29 ] , V_4 ) ;
F_131 ( V_4 -> V_188 [ V_29 ] ) ;
if ( F_125 ( V_4 ) ) {
return;
}
}
}
static unsigned int F_133 ( struct V_2 * V_4 )
{
unsigned short V_60 = F_24 ( V_4 , V_55 ) ;
unsigned short V_193 = F_43 ( V_4 ) ;
return ( V_60 & F_41 ( V_4 ) ) && ! V_193 ? V_194 : 0 ;
}
static void F_134 ( struct V_2 * V_4 , unsigned int V_195 )
{
if ( V_195 & V_196 ) {
const struct V_7 * V_8 ;
V_8 = F_4 ( V_4 , V_197 ) ;
if ( V_8 -> V_9 )
F_25 ( V_4 , V_197 ,
F_24 ( V_4 , V_197 ) |
V_198 ) ;
}
}
static unsigned int F_135 ( struct V_2 * V_4 )
{
return V_199 | V_200 ;
}
static void F_136 ( struct V_2 * V_4 , int V_201 )
{
struct V_1 * V_41 = F_1 ( V_4 ) ;
const struct V_7 * V_8 = V_66 [ V_41 -> V_14 -> V_16 ] + V_67 ;
unsigned short V_39 , V_202 ;
if ( ! V_8 -> V_9 ) {
return;
}
V_202 = F_24 ( V_4 , V_67 ) ;
V_39 = F_24 ( V_4 , V_45 ) ;
if ( V_201 == - 1 ) {
V_202 = ( V_202 | V_203 ) & ~ V_204 ;
V_39 &= ~ V_205 ;
} else {
V_202 = ( V_202 | V_204 ) & ~ V_203 ;
V_39 |= V_205 ;
}
F_25 ( V_4 , V_67 , V_202 ) ;
F_25 ( V_4 , V_45 , V_39 ) ;
}
static int F_137 ( struct V_2 * V_4 )
{
struct V_1 * V_41 = F_1 ( V_4 ) ;
unsigned long V_113 ;
int V_158 ;
F_58 ( V_4 -> V_30 , L_8 , V_114 , V_4 -> line ) ;
V_158 = F_124 ( V_41 ) ;
if ( F_126 ( V_158 < 0 ) )
return V_158 ;
F_108 ( V_4 ) ;
F_72 ( & V_4 -> V_115 , V_113 ) ;
F_22 ( V_4 ) ;
F_30 ( V_4 ) ;
F_73 ( & V_4 -> V_115 , V_113 ) ;
return 0 ;
}
static void F_138 ( struct V_2 * V_4 )
{
struct V_1 * V_41 = F_1 ( V_4 ) ;
unsigned long V_113 ;
F_58 ( V_4 -> V_30 , L_8 , V_114 , V_4 -> line ) ;
F_72 ( & V_4 -> V_115 , V_113 ) ;
F_31 ( V_4 ) ;
F_29 ( V_4 ) ;
F_73 ( & V_4 -> V_115 , V_113 ) ;
#ifdef F_23
if ( V_41 -> V_123 ) {
F_58 ( V_4 -> V_30 , L_36 , V_114 ,
V_4 -> line ) ;
F_18 ( & V_41 -> V_131 ) ;
}
#endif
F_116 ( V_4 ) ;
F_132 ( V_41 ) ;
}
static int F_139 ( struct V_1 * V_41 , unsigned int V_206 ,
unsigned int * V_207 )
{
unsigned long V_208 = V_41 -> V_33 [ V_209 ] ;
unsigned int V_210 , V_211 , V_212 ;
int V_213 , V_214 = V_215 ;
if ( V_41 -> V_216 ) {
V_210 = V_211 = V_41 -> V_216 / 2 ;
} else {
V_210 = 8 ;
V_211 = 32 ;
}
for ( V_212 = V_211 ; V_212 >= V_210 ; V_212 -- ) {
V_213 = F_140 ( V_208 , V_212 ) - V_206 ;
if ( abs ( V_213 ) >= abs ( V_214 ) )
continue;
V_214 = V_213 ;
* V_207 = V_212 - 1 ;
if ( ! V_213 )
break;
}
F_58 ( V_41 -> V_4 . V_30 , L_37 , V_206 , V_214 ,
* V_207 + 1 ) ;
return V_214 ;
}
static int F_141 ( struct V_1 * V_41 , unsigned int V_206 ,
unsigned long V_208 , unsigned int * V_217 ,
unsigned int * V_207 )
{
unsigned int V_210 , V_211 , V_212 , V_218 ;
int V_213 , V_214 = V_215 ;
if ( V_41 -> V_216 ) {
V_210 = V_211 = V_41 -> V_216 / 2 ;
} else {
V_210 = 8 ;
V_211 = 32 ;
}
for ( V_212 = V_211 ; V_212 >= V_210 ; V_212 -- ) {
V_218 = F_140 ( V_208 , V_212 * V_206 ) ;
V_218 = F_142 ( V_218 , 1U , 65535U ) ;
V_213 = F_140 ( V_208 , V_212 * V_218 ) - V_206 ;
if ( abs ( V_213 ) >= abs ( V_214 ) )
continue;
V_214 = V_213 ;
* V_217 = V_218 ;
* V_207 = V_212 - 1 ;
if ( ! V_213 )
break;
}
F_58 ( V_41 -> V_4 . V_30 , L_38 , V_206 ,
V_214 , * V_217 , * V_207 + 1 ) ;
return V_214 ;
}
static int F_143 ( struct V_1 * V_41 , unsigned int V_206 ,
unsigned int * V_219 , unsigned int * V_207 ,
unsigned int * V_220 )
{
unsigned int V_210 , V_211 , V_221 , V_212 , V_222 , V_223 , V_224 , V_61 ;
unsigned long V_208 = V_41 -> V_33 [ V_35 ] ;
int V_213 , V_214 = V_215 ;
if ( V_41 -> V_216 ) {
V_210 = V_211 = V_41 -> V_216 ;
V_221 = 0 ;
} else {
V_210 = 8 ;
V_211 = 32 ;
V_221 = 1 ;
}
for ( V_212 = V_211 ; V_212 >= V_210 ; V_212 -- ) {
for ( V_61 = 0 ; V_61 <= 3 ; V_61 ++ ) {
V_223 = V_212 * ( 1 << ( 2 * V_61 + V_221 ) ) ;
if ( V_206 > V_225 / V_223 )
break;
V_224 = V_223 * V_206 ;
V_222 = F_140 ( V_208 , V_224 ) ;
V_222 = F_142 ( V_222 , 1U , 256U ) ;
V_213 = F_140 ( V_208 , V_222 * V_223 ) - V_206 ;
if ( abs ( V_213 ) >= abs ( V_214 ) )
continue;
V_214 = V_213 ;
* V_219 = V_222 - 1 ;
* V_207 = V_212 - 1 ;
* V_220 = V_61 ;
if ( ! V_213 )
goto V_226;
}
}
V_226:
F_58 ( V_41 -> V_4 . V_30 , L_39 , V_206 ,
V_214 , * V_219 , * V_207 + 1 , * V_220 ) ;
return V_214 ;
}
static void F_144 ( struct V_2 * V_4 )
{
const struct V_7 * V_8 ;
unsigned int V_60 ;
do {
V_60 = F_24 ( V_4 , V_55 ) ;
} while ( ! ( V_60 & F_41 ( V_4 ) ) );
F_25 ( V_4 , V_45 , 0x00 ) ;
V_8 = F_4 ( V_4 , V_197 ) ;
if ( V_8 -> V_9 )
F_25 ( V_4 , V_197 , V_227 | V_228 ) ;
}
static void F_145 ( struct V_2 * V_4 , struct V_229 * V_230 ,
struct V_229 * V_231 )
{
unsigned int V_232 , V_233 = 0 , V_234 = 0 , V_29 ;
unsigned int V_219 = 255 , V_220 = 0 , V_207 = 15 , V_218 = 0 , V_235 = 0 ;
unsigned int V_236 = 255 , V_237 = 0 , V_238 = 15 , V_239 = 0 ;
struct V_1 * V_41 = F_1 ( V_4 ) ;
const struct V_7 * V_8 ;
int V_214 = V_215 , V_213 ;
unsigned long V_240 = 0 ;
int V_241 = - 1 ;
if ( ( V_230 -> V_242 & V_243 ) == V_244 )
V_233 |= V_245 ;
if ( V_230 -> V_242 & V_246 )
V_233 |= V_247 ;
if ( V_230 -> V_242 & V_248 )
V_233 |= V_247 | V_249 ;
if ( V_230 -> V_242 & V_250 )
V_233 |= V_251 ;
if ( ! V_4 -> V_34 ) {
V_232 = F_146 ( V_4 , V_230 , V_231 , 0 , 115200 ) ;
goto V_252;
}
for ( V_29 = 0 ; V_29 < V_31 ; V_29 ++ )
V_240 = F_147 ( V_240 , V_41 -> V_33 [ V_29 ] ) ;
V_232 = F_146 ( V_4 , V_230 , V_231 , 0 ,
V_240 / F_147 ( V_41 -> V_216 , 8U ) ) ;
if ( ! V_232 )
goto V_252;
if ( V_41 -> V_33 [ V_209 ] && V_4 -> type != V_20 &&
V_4 -> type != V_22 ) {
V_213 = F_139 ( V_41 , V_232 , & V_238 ) ;
if ( abs ( V_213 ) < abs ( V_214 ) ) {
V_241 = V_209 ;
V_234 = V_253 ;
V_235 = V_254 ;
V_214 = V_213 ;
V_207 = V_238 ;
if ( ! V_213 )
goto V_252;
}
}
if ( V_41 -> V_33 [ V_255 ] && F_4 ( V_4 , V_256 ) -> V_9 ) {
V_213 = F_141 ( V_41 , V_232 , V_41 -> V_33 [ V_255 ] , & V_239 ,
& V_238 ) ;
if ( abs ( V_213 ) < abs ( V_214 ) ) {
V_241 = V_255 ;
V_234 = V_253 ;
V_235 = 0 ;
V_214 = V_213 ;
V_218 = V_239 ;
V_207 = V_238 ;
if ( ! V_213 )
goto V_252;
}
}
if ( V_41 -> V_33 [ V_257 ] && F_4 ( V_4 , V_256 ) -> V_9 ) {
V_213 = F_141 ( V_41 , V_232 , V_41 -> V_33 [ V_257 ] , & V_239 ,
& V_238 ) ;
if ( abs ( V_213 ) < abs ( V_214 ) ) {
V_241 = V_257 ;
V_234 = V_253 ;
V_235 = V_258 ;
V_214 = V_213 ;
V_218 = V_239 ;
V_207 = V_238 ;
if ( ! V_214 )
goto V_252;
}
}
V_213 = F_143 ( V_41 , V_232 , & V_236 , & V_238 , & V_237 ) ;
if ( abs ( V_213 ) < abs ( V_214 ) ) {
V_241 = V_35 ;
V_234 = 0 ;
V_214 = V_213 ;
V_219 = V_236 ;
V_207 = V_238 ;
V_220 = V_237 ;
}
V_252:
if ( V_241 >= 0 )
F_58 ( V_4 -> V_30 , L_40 ,
V_41 -> V_32 [ V_241 ] , V_232 , V_214 ) ;
F_13 ( V_41 ) ;
if ( V_241 >= 0 && F_4 ( V_4 , V_259 ) -> V_9 ) {
F_25 ( V_4 , V_256 , V_218 ) ;
F_25 ( V_4 , V_259 , V_235 ) ;
}
F_144 ( V_4 ) ;
F_148 ( V_4 , V_230 -> V_242 , V_232 ) ;
if ( V_241 >= 0 ) {
V_233 |= V_220 ;
F_58 ( V_4 -> V_30 ,
L_41 ,
V_234 , V_233 , V_219 , V_235 , V_218 , V_207 ) ;
F_25 ( V_4 , V_45 , V_234 ) ;
F_25 ( V_4 , V_260 , V_233 ) ;
F_25 ( V_4 , V_261 , V_219 ) ;
if ( F_4 ( V_4 , V_262 ) -> V_9 )
F_25 ( V_4 , V_262 , V_207 | V_263 ) ;
F_149 ( ( 1000000 + ( V_232 - 1 ) ) / V_232 ) ;
} else {
V_234 = V_41 -> V_14 -> V_39 & ( V_253 | V_264 ) ;
V_233 |= F_24 ( V_4 , V_260 ) & V_265 ;
F_58 ( V_4 -> V_30 , L_42 , V_234 , V_233 ) ;
F_25 ( V_4 , V_45 , V_234 ) ;
F_25 ( V_4 , V_260 , V_233 ) ;
}
F_42 ( V_4 , V_230 -> V_242 ) ;
V_8 = F_4 ( V_4 , V_197 ) ;
if ( V_8 -> V_9 ) {
unsigned short V_42 = F_24 ( V_4 , V_197 ) ;
if ( V_41 -> V_14 -> V_70 & V_71 ) {
if ( V_230 -> V_242 & V_72 )
V_42 |= V_266 ;
else
V_42 &= ~ V_266 ;
}
V_42 &= ~ ( V_227 | V_228 ) ;
F_25 ( V_4 , V_197 , V_42 ) ;
}
V_234 |= V_41 -> V_14 -> V_39 & ~ ( V_253 | V_264 ) ;
F_58 ( V_4 -> V_30 , L_43 , V_234 ) ;
F_25 ( V_4 , V_45 , V_234 ) ;
#ifdef F_23
if ( V_41 -> V_123 ) {
unsigned int V_267 ;
switch ( V_230 -> V_242 & V_243 ) {
case V_268 :
V_267 = 7 ;
break;
case V_269 :
V_267 = 8 ;
break;
case V_244 :
V_267 = 9 ;
break;
default:
V_267 = 10 ;
break;
}
if ( V_230 -> V_242 & V_250 )
V_267 ++ ;
if ( V_230 -> V_242 & V_246 )
V_267 ++ ;
V_41 -> V_132 = F_150 ( ( V_41 -> V_125 * 2 * V_267 * V_270 ) /
( V_232 / 10 ) , 10 ) ;
F_58 ( V_4 -> V_30 , L_44 ,
V_41 -> V_132 * 1000 / V_270 , V_4 -> V_271 ) ;
if ( V_41 -> V_132 < F_151 ( 20 ) )
V_41 -> V_132 = F_151 ( 20 ) ;
}
#endif
if ( ( V_230 -> V_242 & V_272 ) != 0 )
F_30 ( V_4 ) ;
F_17 ( V_41 ) ;
}
static void F_152 ( struct V_2 * V_4 , unsigned int V_48 ,
unsigned int V_273 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
switch ( V_48 ) {
case V_274 :
F_17 ( V_1 ) ;
break;
default:
F_13 ( V_1 ) ;
break;
}
}
static const char * F_153 ( struct V_2 * V_4 )
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
static int F_154 ( struct V_2 * V_4 )
{
struct V_1 * V_275 = F_1 ( V_4 ) ;
if ( V_4 -> V_10 )
return 0 ;
if ( V_4 -> V_113 & V_276 ) {
V_4 -> V_10 = F_155 ( V_4 -> V_163 , V_275 -> V_277 ) ;
if ( F_126 ( ! V_4 -> V_10 ) ) {
F_79 ( V_4 -> V_30 , L_51 , V_4 -> line ) ;
return - V_278 ;
}
} else {
V_4 -> V_10 = ( void V_81 * ) ( V_82 ) V_4 -> V_163 ;
}
return 0 ;
}
static void F_156 ( struct V_2 * V_4 )
{
struct V_1 * V_275 = F_1 ( V_4 ) ;
if ( V_4 -> V_113 & V_276 ) {
F_157 ( V_4 -> V_10 ) ;
V_4 -> V_10 = NULL ;
}
F_158 ( V_4 -> V_163 , V_275 -> V_277 ) ;
}
static int F_159 ( struct V_2 * V_4 )
{
struct V_279 * V_280 ;
struct V_1 * V_275 = F_1 ( V_4 ) ;
int V_158 ;
V_280 = F_160 ( V_4 -> V_163 , V_275 -> V_277 ,
F_128 ( V_4 -> V_30 ) ) ;
if ( F_126 ( V_280 == NULL ) ) {
F_79 ( V_4 -> V_30 , L_52 ) ;
return - V_281 ;
}
V_158 = F_154 ( V_4 ) ;
if ( F_126 ( V_158 != 0 ) ) {
F_161 ( V_280 ) ;
return V_158 ;
}
return 0 ;
}
static void F_162 ( struct V_2 * V_4 , int V_113 )
{
if ( V_113 & V_282 ) {
struct V_1 * V_275 = F_1 ( V_4 ) ;
V_4 -> type = V_275 -> V_14 -> type ;
F_159 ( V_4 ) ;
}
}
static int F_163 ( struct V_2 * V_4 , struct V_283 * V_284 )
{
if ( V_284 -> V_285 < 2400 )
return - V_28 ;
return 0 ;
}
static int F_164 ( struct V_1 * V_1 , struct V_124 * V_30 )
{
const char * V_286 [] = {
[ V_35 ] = L_53 ,
[ V_209 ] = L_54 ,
[ V_257 ] = L_55 ,
[ V_255 ] = L_56 ,
} ;
struct V_287 * V_287 ;
unsigned int V_29 ;
if ( V_1 -> V_14 -> type == V_26 )
V_286 [ V_209 ] = L_57 ;
for ( V_29 = 0 ; V_29 < V_31 ; V_29 ++ ) {
V_287 = F_165 ( V_30 , V_286 [ V_29 ] ) ;
if ( F_166 ( V_287 ) == - V_288 )
return - V_288 ;
if ( F_167 ( V_287 ) && V_29 == V_35 ) {
V_287 = F_165 ( V_30 , L_58 ) ;
if ( F_166 ( V_287 ) == - V_288 )
return - V_288 ;
if ( ! F_167 ( V_287 ) )
goto V_226;
V_287 = F_165 ( V_30 , L_59 ) ;
if ( ! F_167 ( V_287 ) )
goto V_226;
F_79 ( V_30 , L_60 , V_286 [ V_29 ] ,
F_166 ( V_287 ) ) ;
return F_166 ( V_287 ) ;
}
V_226:
if ( F_167 ( V_287 ) )
F_58 ( V_30 , L_60 , V_286 [ V_29 ] ,
F_166 ( V_287 ) ) ;
else
F_58 ( V_30 , L_61 , V_286 [ V_29 ] ,
V_287 , V_287 ) ;
V_1 -> V_32 [ V_29 ] = F_167 ( V_287 ) ? NULL : V_287 ;
}
return 0 ;
}
static int F_168 ( struct V_289 * V_30 ,
struct V_1 * V_1 , unsigned int V_290 ,
struct V_13 * V_5 , bool V_291 )
{
struct V_2 * V_4 = & V_1 -> V_4 ;
const struct V_279 * V_280 ;
unsigned int V_29 ;
int V_158 ;
V_1 -> V_14 = V_5 ;
V_4 -> V_68 = & V_292 ;
V_4 -> V_293 = V_294 ;
V_4 -> line = V_290 ;
V_280 = F_169 ( V_30 , V_295 , 0 ) ;
if ( V_280 == NULL )
return - V_296 ;
V_4 -> V_163 = V_280 -> V_297 ;
V_1 -> V_277 = F_170 ( V_280 ) ;
for ( V_29 = 0 ; V_29 < F_78 ( V_1 -> V_152 ) ; ++ V_29 )
V_1 -> V_152 [ V_29 ] = F_171 ( V_30 , V_29 ) ;
if ( V_1 -> V_152 [ 0 ] < 0 )
return - V_278 ;
if ( V_1 -> V_152 [ 1 ] < 0 ) {
V_1 -> V_152 [ 1 ] = V_1 -> V_152 [ 0 ] ;
V_1 -> V_152 [ 2 ] = V_1 -> V_152 [ 0 ] ;
V_1 -> V_152 [ 3 ] = V_1 -> V_152 [ 0 ] ;
}
if ( V_5 -> V_16 == V_298 ) {
V_158 = F_11 ( V_5 ) ;
if ( F_126 ( V_158 ) )
return V_158 ;
}
switch ( V_5 -> type ) {
case V_22 :
V_4 -> V_76 = 256 ;
V_1 -> V_111 = V_55 ;
V_1 -> V_56 = V_57 ;
V_1 -> V_216 = 16 ;
break;
case V_26 :
V_4 -> V_76 = 128 ;
V_1 -> V_111 = V_299 ;
V_1 -> V_56 = V_300 ;
V_1 -> V_216 = 0 ;
break;
case V_20 :
V_4 -> V_76 = 64 ;
V_1 -> V_111 = V_55 ;
V_1 -> V_56 = V_57 ;
V_1 -> V_216 = 16 ;
break;
case V_24 :
V_4 -> V_76 = 16 ;
if ( V_5 -> V_16 == V_301 ) {
V_1 -> V_111 = V_55 ;
V_1 -> V_56 = V_57 ;
V_1 -> V_216 = 16 ;
} else {
V_1 -> V_111 = V_299 ;
V_1 -> V_56 = V_300 ;
V_1 -> V_216 = 32 ;
}
break;
default:
V_4 -> V_76 = 1 ;
V_1 -> V_111 = V_55 ;
V_1 -> V_56 = V_302 ;
V_1 -> V_216 = 32 ;
break;
}
if ( V_5 -> V_216 )
V_1 -> V_216 = V_5 -> V_216 ;
if ( ! V_291 ) {
V_158 = F_164 ( V_1 , & V_30 -> V_30 ) ;
if ( V_158 < 0 )
return V_158 ;
V_4 -> V_30 = & V_30 -> V_30 ;
F_172 ( & V_30 -> V_30 ) ;
}
V_1 -> V_36 . V_106 = ( unsigned long ) V_1 ;
V_1 -> V_36 . V_303 = F_65 ;
F_173 ( & V_1 -> V_36 ) ;
if ( V_5 -> type == V_15 ) {
V_1 -> V_304 = V_305 ;
V_1 -> V_306 = V_307 ;
} else {
V_1 -> V_304 = V_308 ;
V_1 -> V_306 = V_309 ;
}
if ( V_1 -> V_111 == V_55 ) {
V_1 -> V_304 |= V_1 -> V_56 ;
V_1 -> V_306 &= ~ V_1 -> V_56 ;
}
V_4 -> type = V_5 -> type ;
V_4 -> V_113 = V_310 | V_5 -> V_113 ;
V_4 -> V_11 = V_5 -> V_11 ;
V_4 -> V_173 = V_1 -> V_152 [ V_153 ] ;
V_4 -> V_191 = 0 ;
V_4 -> V_311 = F_3 ;
V_4 -> V_312 = F_8 ;
if ( V_5 -> V_169 > 0 && V_5 -> V_170 > 0 )
F_58 ( V_4 -> V_30 , L_62 ,
V_5 -> V_169 , V_5 -> V_170 ) ;
return 0 ;
}
static void F_174 ( struct V_1 * V_4 )
{
F_175 ( V_4 -> V_4 . V_30 ) ;
}
static void F_176 ( struct V_2 * V_4 , int V_313 )
{
F_38 ( V_4 , V_313 ) ;
}
static void F_177 ( struct V_314 * V_315 , const char * V_41 ,
unsigned V_85 )
{
struct V_1 * V_1 = & V_316 [ V_315 -> V_290 ] ;
struct V_2 * V_4 = & V_1 -> V_4 ;
unsigned short V_267 , V_42 , V_317 ;
unsigned long V_113 ;
int V_318 = 1 ;
F_178 ( V_113 ) ;
if ( V_4 -> V_319 )
V_318 = 0 ;
else if ( V_320 )
V_318 = F_179 ( & V_4 -> V_115 ) ;
else
F_180 ( & V_4 -> V_115 ) ;
V_42 = F_24 ( V_4 , V_45 ) ;
V_317 = ( V_1 -> V_14 -> V_39 & ~ ( V_253 | V_264 ) ) |
( V_42 & ( V_253 | V_264 ) ) ;
F_25 ( V_4 , V_45 , V_317 ) ;
F_181 ( V_4 , V_41 , V_85 , F_176 ) ;
V_267 = F_39 ( V_4 ) | F_41 ( V_4 ) ;
while ( ( F_24 ( V_4 , V_55 ) & V_267 ) != V_267 )
F_182 () ;
F_25 ( V_4 , V_45 , V_42 ) ;
if ( V_318 )
F_183 ( & V_4 -> V_115 ) ;
F_184 ( V_113 ) ;
}
static int F_185 ( struct V_314 * V_315 , char * V_321 )
{
struct V_1 * V_1 ;
struct V_2 * V_4 ;
int V_232 = 115200 ;
int V_267 = 8 ;
int V_102 = 'n' ;
int V_322 = 'n' ;
int V_158 ;
if ( V_315 -> V_290 < 0 || V_315 -> V_290 >= V_323 )
return - V_324 ;
V_1 = & V_316 [ V_315 -> V_290 ] ;
V_4 = & V_1 -> V_4 ;
if ( ! V_4 -> V_68 )
return - V_324 ;
V_158 = F_154 ( V_4 ) ;
if ( F_126 ( V_158 != 0 ) )
return V_158 ;
if ( V_321 )
F_186 ( V_321 , & V_232 , & V_102 , & V_267 , & V_322 ) ;
return F_187 ( V_4 , V_315 , V_232 , V_102 , V_267 , V_322 ) ;
}
static int F_188 ( struct V_289 * V_325 )
{
struct V_13 * V_14 = F_189 ( & V_325 -> V_30 ) ;
if ( V_326 . V_106 )
return - V_327 ;
V_326 . V_290 = V_325 -> V_156 ;
F_168 ( V_325 , & V_316 [ V_325 -> V_156 ] , V_325 -> V_156 , V_14 , true ) ;
F_185 ( & V_326 , V_328 ) ;
if ( ! strstr ( V_328 , L_63 ) )
V_326 . V_113 |= V_329 ;
F_190 ( & V_326 ) ;
return 0 ;
}
static inline int F_188 ( struct V_289 * V_325 )
{
return - V_28 ;
}
static int F_191 ( struct V_289 * V_30 )
{
struct V_1 * V_4 = F_192 ( V_30 ) ;
F_193 ( & V_330 , & V_4 -> V_4 ) ;
F_174 ( V_4 ) ;
return 0 ;
}
static struct V_13 *
F_194 ( struct V_289 * V_325 , unsigned int * V_331 )
{
struct V_332 * V_333 = V_325 -> V_30 . V_168 ;
const struct V_334 * V_335 ;
struct V_13 * V_5 ;
int V_156 ;
if ( ! F_195 ( V_336 ) || ! V_333 )
return NULL ;
V_335 = F_196 ( V_337 , V_333 ) ;
if ( ! V_335 )
return NULL ;
V_5 = F_197 ( & V_325 -> V_30 , sizeof( struct V_13 ) , V_172 ) ;
if ( ! V_5 )
return NULL ;
V_156 = F_198 ( V_333 , L_64 ) ;
if ( V_156 < 0 ) {
F_79 ( & V_325 -> V_30 , L_65 , V_156 ) ;
return NULL ;
}
* V_331 = V_156 ;
V_5 -> V_113 = V_276 | V_338 ;
V_5 -> type = F_199 ( V_335 -> V_106 ) ;
V_5 -> V_16 = F_200 ( V_335 -> V_106 ) ;
V_5 -> V_39 = V_339 | V_205 ;
return V_5 ;
}
static int F_201 ( struct V_289 * V_30 ,
unsigned int V_290 ,
struct V_13 * V_5 ,
struct V_1 * V_340 )
{
int V_158 ;
if ( F_126 ( V_290 >= V_323 ) ) {
F_60 ( & V_30 -> V_30 , L_66 ,
V_290 + 1 , V_323 ) ;
F_60 ( & V_30 -> V_30 , L_67 ) ;
return - V_28 ;
}
V_158 = F_168 ( V_30 , V_340 , V_290 , V_5 , false ) ;
if ( V_158 )
return V_158 ;
V_158 = F_202 ( & V_330 , & V_340 -> V_4 ) ;
if ( V_158 ) {
F_174 ( V_340 ) ;
return V_158 ;
}
return 0 ;
}
static int F_203 ( struct V_289 * V_30 )
{
struct V_13 * V_5 ;
struct V_1 * V_341 ;
unsigned int V_331 ;
int V_158 ;
if ( F_204 ( V_30 ) )
return F_188 ( V_30 ) ;
if ( V_30 -> V_30 . V_168 ) {
V_5 = F_194 ( V_30 , & V_331 ) ;
if ( V_5 == NULL )
return - V_28 ;
} else {
V_5 = V_30 -> V_30 . V_342 ;
if ( V_5 == NULL ) {
F_79 ( & V_30 -> V_30 , L_68 ) ;
return - V_28 ;
}
V_331 = V_30 -> V_156 ;
}
V_341 = & V_316 [ V_331 ] ;
F_205 ( V_30 , V_341 ) ;
V_158 = F_201 ( V_30 , V_331 , V_5 , V_341 ) ;
if ( V_158 )
return V_158 ;
#ifdef F_206
F_207 () ;
#endif
return 0 ;
}
static T_6 int F_208 ( struct V_124 * V_30 )
{
struct V_1 * V_275 = F_209 ( V_30 ) ;
if ( V_275 )
F_210 ( & V_330 , & V_275 -> V_4 ) ;
return 0 ;
}
static T_6 int F_211 ( struct V_124 * V_30 )
{
struct V_1 * V_275 = F_209 ( V_30 ) ;
if ( V_275 )
F_212 ( & V_330 , & V_275 -> V_4 ) ;
return 0 ;
}
static int T_7 F_213 ( void )
{
int V_158 ;
F_214 ( L_69 , V_343 ) ;
V_158 = F_215 ( & V_330 ) ;
if ( F_216 ( V_158 == 0 ) ) {
V_158 = F_217 ( & V_344 ) ;
if ( F_126 ( V_158 ) )
F_218 ( & V_330 ) ;
}
return V_158 ;
}
static void T_8 F_219 ( void )
{
F_220 ( & V_344 ) ;
F_218 ( & V_330 ) ;
}
