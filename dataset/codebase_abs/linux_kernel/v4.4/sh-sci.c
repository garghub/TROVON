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
static inline unsigned long F_21 ( struct V_2 * V_4 )
{
return V_35 | ( F_1 ( V_4 ) -> V_14 -> V_36 & V_37 ) ;
}
static void F_22 ( struct V_2 * V_4 )
{
struct V_1 * V_38 = F_1 ( V_4 ) ;
unsigned short V_39 ;
#ifdef F_23
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
T_1 V_40 , V_41 = F_24 ( V_4 , V_42 ) ;
if ( V_38 -> V_43 )
V_40 = V_41 | V_44 ;
else
V_40 = V_41 & ~ V_44 ;
if ( V_40 != V_41 )
F_25 ( V_4 , V_42 , V_40 ) ;
}
if ( V_38 -> V_43 && ! F_26 ( & V_38 -> V_4 . V_45 -> V_46 ) &&
F_27 ( V_38 -> V_47 ) ) {
V_38 -> V_47 = 0 ;
F_28 ( & V_38 -> V_48 ) ;
}
#endif
if ( ! V_38 -> V_43 || V_4 -> type == V_20 || V_4 -> type == V_22 ) {
V_39 = F_24 ( V_4 , V_42 ) ;
F_25 ( V_4 , V_42 , V_39 | V_49 ) ;
}
}
static void F_29 ( struct V_2 * V_4 )
{
unsigned short V_39 ;
V_39 = F_24 ( V_4 , V_42 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 )
V_39 &= ~ V_44 ;
V_39 &= ~ V_49 ;
F_25 ( V_4 , V_42 , V_39 ) ;
}
static void F_30 ( struct V_2 * V_4 )
{
unsigned short V_39 ;
V_39 = F_24 ( V_4 , V_42 ) | F_21 ( V_4 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 )
V_39 &= ~ V_50 ;
F_25 ( V_4 , V_42 , V_39 ) ;
}
static void F_31 ( struct V_2 * V_4 )
{
unsigned short V_39 ;
V_39 = F_24 ( V_4 , V_42 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 )
V_39 &= ~ V_50 ;
V_39 &= ~ F_21 ( V_4 ) ;
F_25 ( V_4 , V_42 , V_39 ) ;
}
static void F_32 ( struct V_2 * V_4 , unsigned int V_51 )
{
if ( V_4 -> type == V_15 ) {
F_25 ( V_4 , V_52 , V_51 ) ;
} else if ( F_1 ( V_4 ) -> V_53 == V_54 ) {
F_25 ( V_4 , V_52 ,
F_24 ( V_4 , V_52 ) & V_51 ) ;
} else {
F_25 ( V_4 , V_52 , V_51 & ~ ( V_55 | V_56 ) ) ;
}
}
static int F_33 ( struct V_2 * V_4 )
{
unsigned short V_57 ;
int V_58 ;
do {
V_57 = F_24 ( V_4 , V_52 ) ;
if ( V_57 & F_34 ( V_4 ) ) {
F_32 ( V_4 , F_35 ( V_4 ) ) ;
continue;
}
break;
} while ( 1 );
if ( ! ( V_57 & F_36 ( V_4 ) ) )
return V_59 ;
V_58 = F_24 ( V_4 , V_60 ) ;
F_24 ( V_4 , V_52 ) ;
F_32 ( V_4 , F_37 ( V_4 ) ) ;
return V_58 ;
}
static void F_38 ( struct V_2 * V_4 , unsigned char V_58 )
{
unsigned short V_57 ;
do {
V_57 = F_24 ( V_4 , V_52 ) ;
} while ( ! ( V_57 & F_39 ( V_4 ) ) );
F_25 ( V_4 , V_61 , V_58 ) ;
F_32 ( V_4 , F_40 ( V_4 ) & ~ F_41 ( V_4 ) ) ;
}
static void F_42 ( struct V_2 * V_4 , unsigned int V_62 )
{
struct V_1 * V_38 = F_1 ( V_4 ) ;
const struct V_7 * V_8 = V_63 [ V_38 -> V_14 -> V_16 ] + V_64 ;
if ( V_38 -> V_14 -> V_65 && V_38 -> V_14 -> V_65 -> V_66 ) {
V_38 -> V_14 -> V_65 -> V_66 ( V_4 , V_62 ) ;
return;
}
if ( ! V_8 -> V_9 )
return;
if ( ( V_38 -> V_14 -> V_67 & V_68 ) &&
( ( ! ( V_62 & V_69 ) ) ) ) {
unsigned short V_57 ;
V_57 = F_24 ( V_4 , V_64 ) ;
V_57 &= ~ V_70 ;
V_57 |= V_71 ;
F_25 ( V_4 , V_64 , V_57 ) ;
}
}
static int F_43 ( struct V_2 * V_4 )
{
const struct V_7 * V_8 ;
V_8 = F_4 ( V_4 , V_72 ) ;
if ( V_8 -> V_9 )
return F_24 ( V_4 , V_72 ) & ( ( V_4 -> V_73 << 1 ) - 1 ) ;
V_8 = F_4 ( V_4 , V_74 ) ;
if ( V_8 -> V_9 )
return F_24 ( V_4 , V_74 ) >> 8 ;
return ! ( F_24 ( V_4 , V_52 ) & V_75 ) ;
}
static int F_44 ( struct V_2 * V_4 )
{
return V_4 -> V_73 - F_43 ( V_4 ) ;
}
static int F_45 ( struct V_2 * V_4 )
{
const struct V_7 * V_8 ;
V_8 = F_4 ( V_4 , V_76 ) ;
if ( V_8 -> V_9 )
return F_24 ( V_4 , V_76 ) & ( ( V_4 -> V_73 << 1 ) - 1 ) ;
V_8 = F_4 ( V_4 , V_74 ) ;
if ( V_8 -> V_9 )
return F_24 ( V_4 , V_74 ) & ( ( V_4 -> V_73 << 1 ) - 1 ) ;
return ( F_24 ( V_4 , V_52 ) & F_36 ( V_4 ) ) != 0 ;
}
static inline int F_46 ( struct V_2 * V_4 )
{
struct V_1 * V_38 = F_1 ( V_4 ) ;
if ( V_38 -> V_14 -> V_77 <= 0 )
return 1 ;
return ! ! F_47 ( ( void V_78 * ) ( V_79 ) V_38 -> V_14 -> V_77 ) ;
}
static void F_48 ( struct V_2 * V_4 )
{
struct V_80 * V_46 = & V_4 -> V_45 -> V_46 ;
unsigned int V_81 = F_49 ( V_4 ) ;
unsigned short V_57 ;
unsigned short V_39 ;
int V_82 ;
V_57 = F_24 ( V_4 , V_52 ) ;
if ( ! ( V_57 & F_39 ( V_4 ) ) ) {
V_39 = F_24 ( V_4 , V_42 ) ;
if ( F_26 ( V_46 ) )
V_39 &= ~ V_49 ;
else
V_39 |= V_49 ;
F_25 ( V_4 , V_42 , V_39 ) ;
return;
}
V_82 = F_44 ( V_4 ) ;
do {
unsigned char V_58 ;
if ( V_4 -> V_83 ) {
V_58 = V_4 -> V_83 ;
V_4 -> V_83 = 0 ;
} else if ( ! F_26 ( V_46 ) && ! V_81 ) {
V_58 = V_46 -> V_84 [ V_46 -> V_85 ] ;
V_46 -> V_85 = ( V_46 -> V_85 + 1 ) & ( V_86 - 1 ) ;
} else {
break;
}
F_25 ( V_4 , V_61 , V_58 ) ;
V_4 -> V_87 . V_88 ++ ;
} while ( -- V_82 > 0 );
F_32 ( V_4 , F_40 ( V_4 ) ) ;
if ( F_50 ( V_46 ) < V_89 )
F_51 ( V_4 ) ;
if ( F_26 ( V_46 ) ) {
F_29 ( V_4 ) ;
} else {
V_39 = F_24 ( V_4 , V_42 ) ;
if ( V_4 -> type != V_15 ) {
F_24 ( V_4 , V_52 ) ;
F_32 ( V_4 , F_40 ( V_4 ) ) ;
}
V_39 |= V_49 ;
F_25 ( V_4 , V_42 , V_39 ) ;
}
}
static void F_52 ( struct V_2 * V_4 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_90 * V_91 = & V_4 -> V_45 -> V_4 ;
int V_92 , V_82 , V_93 = 0 ;
unsigned short V_57 ;
unsigned char V_94 ;
V_57 = F_24 ( V_4 , V_52 ) ;
if ( ! ( V_57 & F_36 ( V_4 ) ) )
return;
while ( 1 ) {
V_82 = F_53 ( V_91 , F_45 ( V_4 ) ) ;
if ( V_82 == 0 )
break;
if ( V_4 -> type == V_15 ) {
char V_58 = F_24 ( V_4 , V_60 ) ;
if ( F_54 ( V_4 , V_58 ) ||
V_1 -> V_34 )
V_82 = 0 ;
else
F_55 ( V_91 , V_58 , V_95 ) ;
} else {
for ( V_92 = 0 ; V_92 < V_82 ; V_92 ++ ) {
char V_58 = F_24 ( V_4 , V_60 ) ;
V_57 = F_24 ( V_4 , V_52 ) ;
#if F_56 ( V_96 )
if ( V_1 -> V_34 ) {
if ( ( V_58 == 0 ) &&
( V_57 & F_57 ( V_4 ) ) ) {
V_82 -- ; V_92 -- ;
continue;
}
F_58 ( V_4 -> V_29 , L_3 , V_58 ) ;
V_1 -> V_34 = 0 ;
if ( F_59 ( V_58 ) ) {
V_82 -- ; V_92 -- ;
continue;
}
}
#endif
if ( F_54 ( V_4 , V_58 ) ) {
V_82 -- ; V_92 -- ;
continue;
}
if ( V_57 & F_57 ( V_4 ) ) {
V_94 = V_97 ;
V_4 -> V_87 . V_98 ++ ;
F_60 ( V_4 -> V_29 , L_4 ) ;
} else if ( V_57 & F_61 ( V_4 ) ) {
V_94 = V_99 ;
V_4 -> V_87 . V_100 ++ ;
F_60 ( V_4 -> V_29 , L_5 ) ;
} else
V_94 = V_95 ;
F_55 ( V_91 , V_58 , V_94 ) ;
}
}
F_24 ( V_4 , V_52 ) ;
F_32 ( V_4 , F_37 ( V_4 ) ) ;
V_93 += V_82 ;
V_4 -> V_87 . V_101 += V_82 ;
}
if ( V_93 ) {
F_62 ( V_91 ) ;
} else {
F_24 ( V_4 , V_52 ) ;
F_32 ( V_4 , F_37 ( V_4 ) ) ;
}
}
static inline void F_63 ( struct V_1 * V_4 )
{
F_64 ( & V_4 -> V_33 , V_102 + V_103 ) ;
}
static void F_65 ( unsigned long V_104 )
{
struct V_1 * V_4 = (struct V_1 * ) V_104 ;
if ( F_46 ( & V_4 -> V_4 ) == 0 ) {
V_4 -> V_34 = 1 ;
F_63 ( V_4 ) ;
} else if ( V_4 -> V_34 == 1 ) {
V_4 -> V_34 = 2 ;
F_63 ( V_4 ) ;
} else
V_4 -> V_34 = 0 ;
}
static int F_66 ( struct V_2 * V_4 )
{
int V_93 = 0 ;
unsigned short V_57 = F_24 ( V_4 , V_52 ) ;
struct V_90 * V_91 = & V_4 -> V_45 -> V_4 ;
struct V_1 * V_38 = F_1 ( V_4 ) ;
if ( V_57 & V_38 -> V_53 ) {
V_4 -> V_87 . V_105 ++ ;
if ( F_55 ( V_91 , 0 , V_106 ) )
V_93 ++ ;
F_60 ( V_4 -> V_29 , L_6 ) ;
}
if ( V_57 & F_57 ( V_4 ) ) {
if ( F_46 ( V_4 ) == 0 ) {
struct V_1 * V_1 = F_1 ( V_4 ) ;
if ( ! V_1 -> V_34 ) {
V_4 -> V_87 . V_107 ++ ;
V_1 -> V_34 = 1 ;
F_63 ( V_1 ) ;
if ( F_67 ( V_4 ) )
return 0 ;
F_58 ( V_4 -> V_29 , L_7 ) ;
if ( F_55 ( V_91 , 0 , V_108 ) )
V_93 ++ ;
}
} else {
V_4 -> V_87 . V_98 ++ ;
if ( F_55 ( V_91 , 0 , V_97 ) )
V_93 ++ ;
F_60 ( V_4 -> V_29 , L_4 ) ;
}
}
if ( V_57 & F_61 ( V_4 ) ) {
V_4 -> V_87 . V_100 ++ ;
if ( F_55 ( V_91 , 0 , V_99 ) )
V_93 ++ ;
F_60 ( V_4 -> V_29 , L_5 ) ;
}
if ( V_93 )
F_62 ( V_91 ) ;
return V_93 ;
}
static int F_68 ( struct V_2 * V_4 )
{
struct V_90 * V_91 = & V_4 -> V_45 -> V_4 ;
struct V_1 * V_38 = F_1 ( V_4 ) ;
const struct V_7 * V_8 ;
int V_93 = 0 ;
T_1 V_57 ;
V_8 = F_4 ( V_4 , V_38 -> V_109 ) ;
if ( ! V_8 -> V_9 )
return 0 ;
V_57 = F_24 ( V_4 , V_38 -> V_109 ) ;
if ( V_57 & V_38 -> V_53 ) {
V_57 &= ~ V_38 -> V_53 ;
F_25 ( V_4 , V_38 -> V_109 , V_57 ) ;
V_4 -> V_87 . V_105 ++ ;
F_55 ( V_91 , 0 , V_106 ) ;
F_62 ( V_91 ) ;
F_58 ( V_4 -> V_29 , L_6 ) ;
V_93 ++ ;
}
return V_93 ;
}
static int F_69 ( struct V_2 * V_4 )
{
int V_93 = 0 ;
unsigned short V_57 = F_24 ( V_4 , V_52 ) ;
struct V_90 * V_91 = & V_4 -> V_45 -> V_4 ;
struct V_1 * V_38 = F_1 ( V_4 ) ;
if ( F_67 ( V_4 ) )
return 0 ;
if ( ! V_38 -> V_34 && V_57 & F_70 ( V_4 ) ) {
#if F_56 ( V_96 )
V_38 -> V_34 = 1 ;
#endif
V_4 -> V_87 . V_107 ++ ;
if ( F_55 ( V_91 , 0 , V_108 ) )
V_93 ++ ;
F_58 ( V_4 -> V_29 , L_7 ) ;
}
if ( V_93 )
F_62 ( V_91 ) ;
V_93 += F_68 ( V_4 ) ;
return V_93 ;
}
static void F_71 ( void * V_110 )
{
struct V_1 * V_38 = V_110 ;
struct V_2 * V_4 = & V_38 -> V_4 ;
struct V_80 * V_46 = & V_4 -> V_45 -> V_46 ;
unsigned long V_111 ;
F_58 ( V_4 -> V_29 , L_8 , V_112 , V_4 -> line ) ;
F_72 ( & V_4 -> V_113 , V_111 ) ;
V_46 -> V_85 += V_38 -> V_114 ;
V_46 -> V_85 &= V_86 - 1 ;
V_4 -> V_87 . V_88 += V_38 -> V_114 ;
if ( F_50 ( V_46 ) < V_89 )
F_51 ( V_4 ) ;
if ( ! F_26 ( V_46 ) ) {
V_38 -> V_47 = 0 ;
F_28 ( & V_38 -> V_48 ) ;
} else {
V_38 -> V_47 = - V_28 ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
T_1 V_39 = F_24 ( V_4 , V_42 ) ;
F_25 ( V_4 , V_42 , V_39 & ~ V_49 ) ;
}
}
F_73 ( & V_4 -> V_113 , V_111 ) ;
}
static int F_74 ( struct V_1 * V_38 , void * V_84 , T_2 V_82 )
{
struct V_2 * V_4 = & V_38 -> V_4 ;
struct V_90 * V_91 = & V_4 -> V_45 -> V_4 ;
int V_93 ;
V_93 = F_75 ( V_91 , V_84 , V_82 ) ;
if ( V_93 < V_82 ) {
F_76 ( V_4 -> V_29 , L_9 ,
V_82 - V_93 ) ;
V_4 -> V_87 . V_115 ++ ;
}
V_4 -> V_87 . V_101 += V_93 ;
return V_93 ;
}
static int F_77 ( struct V_1 * V_38 )
{
unsigned int V_92 ;
for ( V_92 = 0 ; V_92 < F_78 ( V_38 -> V_116 ) ; V_92 ++ )
if ( V_38 -> V_117 == V_38 -> V_116 [ V_92 ] )
return V_92 ;
F_79 ( V_38 -> V_4 . V_29 , L_10 , V_112 ,
V_38 -> V_117 ) ;
return - 1 ;
}
static void F_80 ( struct V_1 * V_38 , bool V_118 )
{
struct V_119 * V_120 = V_38 -> V_121 ;
struct V_2 * V_4 = & V_38 -> V_4 ;
unsigned long V_111 ;
F_72 ( & V_4 -> V_113 , V_111 ) ;
V_38 -> V_121 = NULL ;
V_38 -> V_116 [ 0 ] = V_38 -> V_116 [ 1 ] = - V_28 ;
F_73 ( & V_4 -> V_113 , V_111 ) ;
F_81 ( V_120 ) ;
F_82 ( V_120 -> V_122 -> V_29 , V_38 -> V_123 * 2 , V_38 -> V_124 [ 0 ] ,
F_83 ( & V_38 -> V_125 [ 0 ] ) ) ;
F_84 ( V_120 ) ;
if ( V_118 )
F_30 ( V_4 ) ;
}
static void F_85 ( void * V_110 )
{
struct V_1 * V_38 = V_110 ;
struct V_119 * V_120 = V_38 -> V_121 ;
struct V_2 * V_4 = & V_38 -> V_4 ;
struct V_126 * V_127 ;
unsigned long V_111 ;
int V_128 , V_82 = 0 ;
F_58 ( V_4 -> V_29 , L_11 , V_112 , V_4 -> line ,
V_38 -> V_117 ) ;
F_72 ( & V_4 -> V_113 , V_111 ) ;
V_128 = F_77 ( V_38 ) ;
if ( V_128 >= 0 )
V_82 = F_74 ( V_38 , V_38 -> V_124 [ V_128 ] , V_38 -> V_123 ) ;
F_64 ( & V_38 -> V_129 , V_102 + V_38 -> V_130 ) ;
if ( V_82 )
F_62 ( & V_4 -> V_45 -> V_4 ) ;
V_127 = F_86 ( V_38 -> V_121 , & V_38 -> V_125 [ V_128 ] , 1 ,
V_131 ,
V_132 | V_133 ) ;
if ( ! V_127 )
goto V_134;
V_127 -> V_135 = F_85 ;
V_127 -> V_136 = V_38 ;
V_38 -> V_116 [ V_128 ] = F_87 ( V_127 ) ;
if ( F_27 ( V_38 -> V_116 [ V_128 ] ) )
goto V_134;
V_38 -> V_117 = V_38 -> V_116 [ ! V_128 ] ;
F_88 ( V_120 ) ;
F_58 ( V_4 -> V_29 , L_12 ,
V_112 , V_38 -> V_116 [ V_128 ] , V_128 , V_38 -> V_117 ) ;
F_73 ( & V_4 -> V_113 , V_111 ) ;
return;
V_134:
F_73 ( & V_4 -> V_113 , V_111 ) ;
F_76 ( V_4 -> V_29 , L_13 ) ;
F_80 ( V_38 , true ) ;
}
static void F_89 ( struct V_1 * V_38 , bool V_118 )
{
struct V_119 * V_120 = V_38 -> V_43 ;
struct V_2 * V_4 = & V_38 -> V_4 ;
unsigned long V_111 ;
F_72 ( & V_4 -> V_113 , V_111 ) ;
V_38 -> V_43 = NULL ;
V_38 -> V_47 = - V_28 ;
F_73 ( & V_4 -> V_113 , V_111 ) ;
F_81 ( V_120 ) ;
F_90 ( V_120 -> V_122 -> V_29 , V_38 -> V_137 , V_86 ,
V_138 ) ;
F_84 ( V_120 ) ;
if ( V_118 )
F_22 ( V_4 ) ;
}
static void F_91 ( struct V_1 * V_38 )
{
struct V_119 * V_120 = V_38 -> V_121 ;
int V_92 ;
for ( V_92 = 0 ; V_92 < 2 ; V_92 ++ ) {
struct V_139 * V_140 = & V_38 -> V_125 [ V_92 ] ;
struct V_126 * V_127 ;
V_127 = F_86 ( V_120 ,
V_140 , 1 , V_131 ,
V_132 | V_133 ) ;
if ( ! V_127 )
goto V_134;
V_127 -> V_135 = F_85 ;
V_127 -> V_136 = V_38 ;
V_38 -> V_116 [ V_92 ] = F_87 ( V_127 ) ;
if ( F_27 ( V_38 -> V_116 [ V_92 ] ) )
goto V_134;
F_58 ( V_38 -> V_4 . V_29 , L_14 , V_112 ,
V_38 -> V_116 [ V_92 ] , V_92 ) ;
}
V_38 -> V_117 = V_38 -> V_116 [ 0 ] ;
F_88 ( V_120 ) ;
return;
V_134:
if ( V_92 )
F_81 ( V_120 ) ;
for ( V_92 = 0 ; V_92 < 2 ; V_92 ++ )
V_38 -> V_116 [ V_92 ] = - V_28 ;
V_38 -> V_117 = - V_28 ;
F_76 ( V_38 -> V_4 . V_29 , L_15 ) ;
F_80 ( V_38 , true ) ;
}
static void F_92 ( struct V_141 * V_142 )
{
struct V_1 * V_38 = F_2 ( V_142 , struct V_1 , V_48 ) ;
struct V_126 * V_127 ;
struct V_119 * V_120 = V_38 -> V_43 ;
struct V_2 * V_4 = & V_38 -> V_4 ;
struct V_80 * V_46 = & V_4 -> V_45 -> V_46 ;
T_3 V_84 ;
F_93 ( & V_4 -> V_113 ) ;
V_84 = V_38 -> V_137 + ( V_46 -> V_85 & ( V_86 - 1 ) ) ;
V_38 -> V_114 = F_94 (unsigned int,
CIRC_CNT(xmit->head, xmit->tail, UART_XMIT_SIZE),
CIRC_CNT_TO_END(xmit->head, xmit->tail, UART_XMIT_SIZE)) ;
F_95 ( & V_4 -> V_113 ) ;
V_127 = F_96 ( V_120 , V_84 , V_38 -> V_114 ,
V_143 ,
V_132 | V_133 ) ;
if ( ! V_127 ) {
F_76 ( V_4 -> V_29 , L_16 ) ;
F_89 ( V_38 , true ) ;
return;
}
F_97 ( V_120 -> V_122 -> V_29 , V_84 , V_38 -> V_114 ,
V_138 ) ;
F_93 ( & V_4 -> V_113 ) ;
V_127 -> V_135 = F_71 ;
V_127 -> V_136 = V_38 ;
F_95 ( & V_4 -> V_113 ) ;
V_38 -> V_47 = F_87 ( V_127 ) ;
if ( F_27 ( V_38 -> V_47 ) ) {
F_76 ( V_4 -> V_29 , L_17 ) ;
F_89 ( V_38 , true ) ;
return;
}
F_58 ( V_4 -> V_29 , L_18 ,
V_112 , V_46 -> V_84 , V_46 -> V_85 , V_46 -> V_144 , V_38 -> V_47 ) ;
F_88 ( V_120 ) ;
}
static void F_98 ( unsigned long V_110 )
{
struct V_1 * V_38 = (struct V_1 * ) V_110 ;
struct V_119 * V_120 = V_38 -> V_121 ;
struct V_2 * V_4 = & V_38 -> V_4 ;
struct V_145 V_45 ;
enum V_146 V_57 ;
unsigned long V_111 ;
unsigned int V_147 ;
int V_128 , V_82 ;
T_1 V_41 ;
F_72 ( & V_4 -> V_113 , V_111 ) ;
F_58 ( V_4 -> V_29 , L_19 ) ;
V_128 = F_77 ( V_38 ) ;
if ( V_128 < 0 ) {
F_73 ( & V_4 -> V_113 , V_111 ) ;
return;
}
V_57 = F_99 ( V_38 -> V_121 , V_38 -> V_117 , & V_45 ) ;
if ( V_57 == V_148 ) {
F_58 ( V_4 -> V_29 , L_20 ,
V_38 -> V_117 , V_128 ) ;
F_73 ( & V_4 -> V_113 , V_111 ) ;
return;
}
F_100 ( V_120 ) ;
V_57 = F_99 ( V_38 -> V_121 , V_38 -> V_117 , & V_45 ) ;
if ( V_57 == V_148 ) {
F_73 ( & V_4 -> V_113 , V_111 ) ;
F_58 ( V_4 -> V_29 , L_21 ) ;
return;
}
F_81 ( V_38 -> V_121 ) ;
V_147 = F_101 ( & V_38 -> V_125 [ V_128 ] ) - V_45 . V_149 ;
F_58 ( V_4 -> V_29 , L_22 , V_147 ,
V_38 -> V_117 ) ;
if ( V_147 ) {
V_82 = F_74 ( V_38 , V_38 -> V_124 [ V_128 ] , V_147 ) ;
if ( V_82 )
F_62 ( & V_4 -> V_45 -> V_4 ) ;
}
if ( V_4 -> type == V_20 || V_4 -> type == V_22 )
F_91 ( V_38 ) ;
V_41 = F_24 ( V_4 , V_42 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
V_41 &= ~ V_50 ;
F_102 ( V_38 -> V_150 [ V_151 ] ) ;
}
F_25 ( V_4 , V_42 , V_41 | V_35 ) ;
F_73 ( & V_4 -> V_113 , V_111 ) ;
}
static struct V_119 * F_103 ( struct V_2 * V_4 ,
enum V_152 V_153 ,
unsigned int V_154 )
{
T_4 V_51 ;
struct V_119 * V_120 ;
struct V_155 V_14 ;
int V_156 ;
F_104 ( V_51 ) ;
F_105 ( V_157 , V_51 ) ;
V_120 = F_106 ( V_51 , V_158 ,
( void * ) ( unsigned long ) V_154 , V_4 -> V_29 ,
V_153 == V_143 ? L_23 : L_24 ) ;
if ( ! V_120 ) {
F_76 ( V_4 -> V_29 ,
L_25 ) ;
return NULL ;
}
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_159 = V_153 ;
if ( V_153 == V_143 ) {
V_14 . V_160 = V_4 -> V_161 +
( F_4 ( V_4 , V_61 ) -> V_6 << V_4 -> V_11 ) ;
V_14 . V_162 = V_163 ;
} else {
V_14 . V_164 = V_4 -> V_161 +
( F_4 ( V_4 , V_60 ) -> V_6 << V_4 -> V_11 ) ;
V_14 . V_165 = V_163 ;
}
V_156 = F_107 ( V_120 , & V_14 ) ;
if ( V_156 ) {
F_76 ( V_4 -> V_29 , L_26 , V_156 ) ;
F_84 ( V_120 ) ;
return NULL ;
}
return V_120 ;
}
static void F_108 ( struct V_2 * V_4 )
{
struct V_1 * V_38 = F_1 ( V_4 ) ;
struct V_119 * V_120 ;
F_58 ( V_4 -> V_29 , L_27 , V_112 , V_4 -> line ) ;
if ( ! V_4 -> V_29 -> V_166 &&
( V_38 -> V_14 -> V_167 <= 0 || V_38 -> V_14 -> V_168 <= 0 ) )
return;
V_38 -> V_47 = - V_28 ;
V_120 = F_103 ( V_4 , V_143 , V_38 -> V_14 -> V_167 ) ;
F_58 ( V_4 -> V_29 , L_28 , V_112 , V_120 ) ;
if ( V_120 ) {
V_38 -> V_43 = V_120 ;
V_38 -> V_137 = F_109 ( V_120 -> V_122 -> V_29 ,
V_4 -> V_45 -> V_46 . V_84 ,
V_86 ,
V_138 ) ;
if ( F_110 ( V_120 -> V_122 -> V_29 , V_38 -> V_137 ) ) {
F_76 ( V_4 -> V_29 , L_29 ) ;
F_84 ( V_120 ) ;
V_38 -> V_43 = NULL ;
} else {
F_58 ( V_4 -> V_29 , L_30 ,
V_112 , V_86 ,
V_4 -> V_45 -> V_46 . V_84 , & V_38 -> V_137 ) ;
}
F_111 ( & V_38 -> V_48 , F_92 ) ;
}
V_120 = F_103 ( V_4 , V_131 , V_38 -> V_14 -> V_168 ) ;
F_58 ( V_4 -> V_29 , L_31 , V_112 , V_120 ) ;
if ( V_120 ) {
unsigned int V_92 ;
T_3 V_169 ;
void * V_84 ;
V_38 -> V_121 = V_120 ;
V_38 -> V_123 = 2 * F_112 ( T_2 , 16 , V_4 -> V_73 ) ;
V_84 = F_113 ( V_120 -> V_122 -> V_29 , V_38 -> V_123 * 2 ,
& V_169 , V_170 ) ;
if ( ! V_84 ) {
F_76 ( V_4 -> V_29 ,
L_32 ) ;
F_84 ( V_120 ) ;
V_38 -> V_121 = NULL ;
return;
}
for ( V_92 = 0 ; V_92 < 2 ; V_92 ++ ) {
struct V_139 * V_140 = & V_38 -> V_125 [ V_92 ] ;
F_114 ( V_140 , 1 ) ;
V_38 -> V_124 [ V_92 ] = V_84 ;
F_83 ( V_140 ) = V_169 ;
F_101 ( V_140 ) = V_38 -> V_123 ;
V_84 += V_38 -> V_123 ;
V_169 += V_38 -> V_123 ;
}
F_115 ( & V_38 -> V_129 , F_98 , ( unsigned long ) V_38 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 )
F_91 ( V_38 ) ;
}
}
static void F_116 ( struct V_2 * V_4 )
{
struct V_1 * V_38 = F_1 ( V_4 ) ;
if ( V_38 -> V_43 )
F_89 ( V_38 , false ) ;
if ( V_38 -> V_121 )
F_80 ( V_38 , false ) ;
}
static inline void F_108 ( struct V_2 * V_4 )
{
}
static inline void F_116 ( struct V_2 * V_4 )
{
}
static T_5 F_117 ( int V_171 , void * V_172 )
{
#ifdef F_23
struct V_2 * V_4 = V_172 ;
struct V_1 * V_38 = F_1 ( V_4 ) ;
if ( V_38 -> V_121 ) {
T_1 V_41 = F_24 ( V_4 , V_42 ) ;
T_1 V_173 = F_24 ( V_4 , V_52 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
F_118 ( V_171 ) ;
V_41 |= V_50 ;
} else {
V_41 &= ~ V_35 ;
F_91 ( V_38 ) ;
}
F_25 ( V_4 , V_42 , V_41 ) ;
F_25 ( V_4 , V_52 ,
V_173 & ~ ( V_174 | F_36 ( V_4 ) ) ) ;
F_58 ( V_4 -> V_29 , L_33 ,
V_102 , V_38 -> V_130 ) ;
F_64 ( & V_38 -> V_129 , V_102 + V_38 -> V_130 ) ;
return V_175 ;
}
#endif
F_52 ( V_172 ) ;
return V_175 ;
}
static T_5 F_119 ( int V_171 , void * V_172 )
{
struct V_2 * V_4 = V_172 ;
unsigned long V_111 ;
F_72 ( & V_4 -> V_113 , V_111 ) ;
F_48 ( V_4 ) ;
F_73 ( & V_4 -> V_113 , V_111 ) ;
return V_175 ;
}
static T_5 F_120 ( int V_171 , void * V_172 )
{
struct V_2 * V_4 = V_172 ;
struct V_1 * V_38 = F_1 ( V_4 ) ;
if ( V_4 -> type == V_15 ) {
if ( F_66 ( V_4 ) ) {
F_24 ( V_4 , V_52 ) ;
F_32 ( V_4 , F_37 ( V_4 ) ) ;
}
} else {
F_68 ( V_4 ) ;
if ( ! V_38 -> V_121 )
F_52 ( V_172 ) ;
}
F_32 ( V_4 , F_35 ( V_4 ) ) ;
if ( ! V_38 -> V_43 )
F_119 ( V_171 , V_172 ) ;
return V_175 ;
}
static T_5 F_121 ( int V_171 , void * V_172 )
{
struct V_2 * V_4 = V_172 ;
F_69 ( V_4 ) ;
F_32 ( V_4 , F_122 ( V_4 ) ) ;
return V_175 ;
}
static T_5 F_123 ( int V_171 , void * V_172 )
{
unsigned short V_176 , V_177 , V_178 , V_179 = 0 ;
struct V_2 * V_4 = V_172 ;
struct V_1 * V_38 = F_1 ( V_4 ) ;
T_5 V_156 = V_180 ;
V_176 = F_24 ( V_4 , V_52 ) ;
V_177 = F_24 ( V_4 , V_42 ) ;
if ( V_38 -> V_109 == V_52 )
V_179 = V_176 ;
else {
if ( F_4 ( V_4 , V_38 -> V_109 ) -> V_9 )
V_179 = F_24 ( V_4 , V_38 -> V_109 ) ;
}
V_178 = V_177 & F_21 ( V_4 ) ;
if ( ( V_176 & F_39 ( V_4 ) ) && ( V_177 & V_49 ) &&
! V_38 -> V_43 )
V_156 = F_119 ( V_171 , V_172 ) ;
if ( ( ( V_176 & F_36 ( V_4 ) ) || V_38 -> V_121 ) &&
( V_177 & V_35 ) )
V_156 = F_117 ( V_171 , V_172 ) ;
if ( ( V_176 & F_34 ( V_4 ) ) && V_178 )
V_156 = F_120 ( V_171 , V_172 ) ;
if ( ( V_176 & F_70 ( V_4 ) ) && V_178 )
V_156 = F_121 ( V_171 , V_172 ) ;
if ( V_179 & V_38 -> V_53 ) {
F_68 ( V_4 ) ;
V_156 = V_175 ;
}
return V_156 ;
}
static int F_124 ( struct V_181 * V_182 ,
unsigned long V_183 , void * V_5 )
{
struct V_1 * V_1 ;
unsigned long V_111 ;
V_1 = F_2 ( V_182 , struct V_1 , V_184 ) ;
if ( V_183 == V_185 ) {
struct V_2 * V_4 = & V_1 -> V_4 ;
F_72 ( & V_4 -> V_113 , V_111 ) ;
V_4 -> V_31 = F_16 ( V_1 -> V_30 ) ;
F_73 ( & V_4 -> V_113 , V_111 ) ;
}
return V_186 ;
}
static int F_125 ( struct V_1 * V_4 )
{
struct V_2 * V_187 = & V_4 -> V_4 ;
int V_92 , V_188 , V_156 = 0 ;
for ( V_92 = V_188 = 0 ; V_92 < V_189 ; V_92 ++ , V_188 ++ ) {
const struct V_190 * V_127 ;
int V_171 ;
if ( F_126 ( V_4 ) ) {
V_92 = V_191 ;
V_171 = V_187 -> V_171 ;
} else {
V_171 = V_4 -> V_150 [ V_92 ] ;
if ( F_127 ( V_171 < 0 ) )
continue;
}
V_127 = V_190 + V_92 ;
V_4 -> V_192 [ V_188 ] = F_128 ( V_170 , L_34 ,
F_129 ( V_187 -> V_29 ) , V_127 -> V_127 ) ;
if ( ! V_4 -> V_192 [ V_188 ] )
goto V_193;
V_156 = F_130 ( V_171 , V_127 -> V_194 , V_187 -> V_195 ,
V_4 -> V_192 [ V_188 ] , V_4 ) ;
if ( F_127 ( V_156 ) ) {
F_79 ( V_187 -> V_29 , L_35 , V_127 -> V_127 ) ;
goto V_196;
}
}
return 0 ;
V_196:
while ( -- V_92 >= 0 )
F_131 ( V_4 -> V_150 [ V_92 ] , V_4 ) ;
V_193:
while ( -- V_188 >= 0 )
F_132 ( V_4 -> V_192 [ V_188 ] ) ;
return V_156 ;
}
static void F_133 ( struct V_1 * V_4 )
{
int V_92 ;
for ( V_92 = 0 ; V_92 < V_189 ; V_92 ++ ) {
int V_171 = V_4 -> V_150 [ V_92 ] ;
if ( F_127 ( V_171 < 0 ) )
continue;
F_131 ( V_4 -> V_150 [ V_92 ] , V_4 ) ;
F_132 ( V_4 -> V_192 [ V_92 ] ) ;
if ( F_126 ( V_4 ) ) {
return;
}
}
}
static unsigned int F_134 ( struct V_2 * V_4 )
{
unsigned short V_57 = F_24 ( V_4 , V_52 ) ;
unsigned short V_197 = F_43 ( V_4 ) ;
return ( V_57 & F_41 ( V_4 ) ) && ! V_197 ? V_198 : 0 ;
}
static void F_135 ( struct V_2 * V_4 , unsigned int V_199 )
{
if ( V_199 & V_200 ) {
const struct V_7 * V_8 ;
V_8 = F_4 ( V_4 , V_201 ) ;
if ( V_8 -> V_9 )
F_25 ( V_4 , V_201 ,
F_24 ( V_4 , V_201 ) |
V_202 ) ;
}
}
static unsigned int F_136 ( struct V_2 * V_4 )
{
return V_203 | V_204 ;
}
static void F_137 ( struct V_2 * V_4 , int V_205 )
{
struct V_1 * V_38 = F_1 ( V_4 ) ;
const struct V_7 * V_8 = V_63 [ V_38 -> V_14 -> V_16 ] + V_64 ;
unsigned short V_36 , V_206 ;
if ( ! V_8 -> V_9 ) {
return;
}
V_206 = F_24 ( V_4 , V_64 ) ;
V_36 = F_24 ( V_4 , V_42 ) ;
if ( V_205 == - 1 ) {
V_206 = ( V_206 | V_207 ) & ~ V_208 ;
V_36 &= ~ V_209 ;
} else {
V_206 = ( V_206 | V_208 ) & ~ V_207 ;
V_36 |= V_209 ;
}
F_25 ( V_4 , V_64 , V_206 ) ;
F_25 ( V_4 , V_42 , V_36 ) ;
}
static int F_138 ( struct V_2 * V_4 )
{
struct V_1 * V_38 = F_1 ( V_4 ) ;
unsigned long V_111 ;
int V_156 ;
F_58 ( V_4 -> V_29 , L_8 , V_112 , V_4 -> line ) ;
V_156 = F_125 ( V_38 ) ;
if ( F_127 ( V_156 < 0 ) )
return V_156 ;
F_108 ( V_4 ) ;
F_72 ( & V_4 -> V_113 , V_111 ) ;
F_22 ( V_4 ) ;
F_30 ( V_4 ) ;
F_73 ( & V_4 -> V_113 , V_111 ) ;
return 0 ;
}
static void F_139 ( struct V_2 * V_4 )
{
struct V_1 * V_38 = F_1 ( V_4 ) ;
unsigned long V_111 ;
F_58 ( V_4 -> V_29 , L_8 , V_112 , V_4 -> line ) ;
F_72 ( & V_4 -> V_113 , V_111 ) ;
F_31 ( V_4 ) ;
F_29 ( V_4 ) ;
F_73 ( & V_4 -> V_113 , V_111 ) ;
#ifdef F_23
if ( V_38 -> V_121 ) {
F_58 ( V_4 -> V_29 , L_36 , V_112 ,
V_4 -> line ) ;
F_18 ( & V_38 -> V_129 ) ;
}
#endif
F_116 ( V_4 ) ;
F_133 ( V_38 ) ;
}
static unsigned int F_140 ( struct V_1 * V_38 , unsigned int V_210 ,
unsigned long V_211 )
{
if ( V_38 -> V_212 )
return F_141 ( V_211 , V_38 -> V_212 * V_210 ) - 1 ;
F_142 ( 1 ) ;
return ( ( V_211 + 16 * V_210 ) / ( 32 * V_210 ) - 1 ) ;
}
static int F_143 ( unsigned int V_213 )
{
int V_214 = 10 ;
if ( V_213 & V_215 )
V_214 -- ;
if ( V_213 & V_216 )
V_214 ++ ;
if ( V_213 & V_217 )
V_214 ++ ;
return V_214 ;
}
static void F_144 ( unsigned int V_210 , unsigned long V_211 ,
int * V_218 , unsigned int * V_219 ,
unsigned int * V_220 , int V_221 )
{
int V_222 , V_58 , V_223 , V_224 , V_225 ;
int V_226 = 1000 ;
int V_227 = 0 ;
for ( V_222 = 8 ; V_222 <= 32 ; V_222 ++ ) {
for ( V_58 = 0 ; V_58 <= 3 ; V_58 ++ ) {
V_223 = F_141 ( V_211 , ( V_222 *
( 1 << ( 2 * V_58 + 1 ) ) * V_210 ) ) - 1 ;
V_223 = F_145 ( V_223 , 0 , 255 ) ;
V_224 = F_141 ( V_211 , ( ( V_223 + 1 ) * V_210 * V_222 *
( 1 << ( 2 * V_58 + 1 ) ) / 1000 ) ) -
1000 ;
V_225 = abs ( ( 500 -
F_141 ( 1000 , V_222 << 1 ) ) / 10 ) ;
if ( abs ( V_226 ) > abs ( V_224 ) ) {
V_226 = V_224 ;
V_227 = V_225 ;
} else if ( ( V_226 == V_224 ) &&
( V_225 > V_227 ) )
V_227 = V_225 ;
else
continue;
* V_218 = V_223 ;
* V_219 = V_222 - 1 ;
* V_220 = V_58 ;
}
}
if ( V_226 == 1000 ) {
F_142 ( 1 ) ;
* V_218 = 255 ;
* V_219 = 15 ;
* V_220 = 0 ;
}
}
static void F_146 ( struct V_2 * V_4 )
{
const struct V_7 * V_8 ;
unsigned int V_57 ;
do {
V_57 = F_24 ( V_4 , V_52 ) ;
} while ( ! ( V_57 & F_41 ( V_4 ) ) );
F_25 ( V_4 , V_42 , 0x00 ) ;
V_8 = F_4 ( V_4 , V_201 ) ;
if ( V_8 -> V_9 )
F_25 ( V_4 , V_201 , V_228 | V_229 ) ;
}
static void F_147 ( struct V_2 * V_4 , struct V_230 * V_231 ,
struct V_230 * V_232 )
{
struct V_1 * V_38 = F_1 ( V_4 ) ;
const struct V_7 * V_8 ;
unsigned int V_233 , V_213 = 0 , V_234 , V_220 = 0 ;
int V_235 = - 1 ;
unsigned int V_219 = 15 ;
if ( ( V_231 -> V_236 & V_237 ) == V_238 )
V_213 |= V_215 ;
if ( V_231 -> V_236 & V_239 )
V_213 |= V_216 ;
if ( V_231 -> V_236 & V_240 )
V_213 |= V_216 | V_241 ;
if ( V_231 -> V_236 & V_242 )
V_213 |= V_217 ;
V_234 = V_4 -> V_31 ? V_4 -> V_31 / 16 : 115200 ;
V_233 = F_148 ( V_4 , V_231 , V_232 , 0 , V_234 ) ;
if ( F_149 ( V_233 && V_4 -> V_31 ) ) {
if ( V_38 -> V_14 -> type == V_26 ) {
int V_221 = F_143 ( V_213 ) ;
F_144 ( V_233 , V_4 -> V_31 , & V_235 , & V_219 ,
& V_220 , V_221 ) ;
} else {
V_235 = F_140 ( V_38 , V_233 , V_4 -> V_31 ) ;
for ( V_220 = 0 ; V_235 >= 256 && V_220 <= 3 ; V_220 ++ )
V_235 >>= 2 ;
}
}
F_13 ( V_38 ) ;
F_146 ( V_4 ) ;
V_213 |= F_24 ( V_4 , V_243 ) & V_244 ;
F_150 ( V_4 , V_231 -> V_236 , V_233 ) ;
F_58 ( V_4 -> V_29 , L_37 ,
V_112 , V_213 , V_220 , V_235 , V_38 -> V_14 -> V_36 ) ;
if ( V_235 >= 0 ) {
F_25 ( V_4 , V_243 , ( V_213 & ~ V_244 ) | V_220 ) ;
F_25 ( V_4 , V_245 , V_235 ) ;
V_8 = F_4 ( V_4 , V_246 ) ;
if ( V_8 -> V_9 )
F_25 ( V_4 , V_246 , V_219 | V_247 ) ;
F_151 ( ( 1000000 + ( V_233 - 1 ) ) / V_233 ) ;
} else
F_25 ( V_4 , V_243 , V_213 ) ;
F_42 ( V_4 , V_231 -> V_236 ) ;
V_8 = F_4 ( V_4 , V_201 ) ;
if ( V_8 -> V_9 ) {
unsigned short V_39 = F_24 ( V_4 , V_201 ) ;
if ( V_38 -> V_14 -> V_67 & V_68 ) {
if ( V_231 -> V_236 & V_69 )
V_39 |= V_248 ;
else
V_39 &= ~ V_248 ;
}
V_39 &= ~ ( V_228 | V_229 ) ;
F_25 ( V_4 , V_201 , V_39 ) ;
}
F_25 ( V_4 , V_42 , V_38 -> V_14 -> V_36 ) ;
#ifdef F_23
if ( V_38 -> V_121 ) {
unsigned int V_249 ;
switch ( V_231 -> V_236 & V_237 ) {
case V_250 :
V_249 = 7 ;
break;
case V_251 :
V_249 = 8 ;
break;
case V_238 :
V_249 = 9 ;
break;
default:
V_249 = 10 ;
break;
}
if ( V_231 -> V_236 & V_242 )
V_249 ++ ;
if ( V_231 -> V_236 & V_239 )
V_249 ++ ;
V_38 -> V_130 = F_152 ( ( V_38 -> V_123 * 2 * V_249 * V_252 ) /
( V_233 / 10 ) , 10 ) ;
F_58 ( V_4 -> V_29 , L_38 ,
V_38 -> V_130 * 1000 / V_252 , V_4 -> V_253 ) ;
if ( V_38 -> V_130 < F_153 ( 20 ) )
V_38 -> V_130 = F_153 ( 20 ) ;
}
#endif
if ( ( V_231 -> V_236 & V_254 ) != 0 )
F_30 ( V_4 ) ;
F_17 ( V_38 ) ;
}
static void F_154 ( struct V_2 * V_4 , unsigned int V_45 ,
unsigned int V_255 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
switch ( V_45 ) {
case V_256 :
F_17 ( V_1 ) ;
break;
default:
F_13 ( V_1 ) ;
break;
}
}
static const char * F_155 ( struct V_2 * V_4 )
{
switch ( V_4 -> type ) {
case V_18 :
return L_39 ;
case V_15 :
return L_40 ;
case V_24 :
return L_41 ;
case V_20 :
return L_42 ;
case V_22 :
return L_43 ;
case V_26 :
return L_44 ;
}
return NULL ;
}
static int F_156 ( struct V_2 * V_4 )
{
struct V_1 * V_257 = F_1 ( V_4 ) ;
if ( V_4 -> V_10 )
return 0 ;
if ( V_4 -> V_111 & V_258 ) {
V_4 -> V_10 = F_157 ( V_4 -> V_161 , V_257 -> V_259 ) ;
if ( F_127 ( ! V_4 -> V_10 ) ) {
F_79 ( V_4 -> V_29 , L_45 , V_4 -> line ) ;
return - V_260 ;
}
} else {
V_4 -> V_10 = ( void V_78 * ) ( V_79 ) V_4 -> V_161 ;
}
return 0 ;
}
static void F_158 ( struct V_2 * V_4 )
{
struct V_1 * V_257 = F_1 ( V_4 ) ;
if ( V_4 -> V_111 & V_258 ) {
F_159 ( V_4 -> V_10 ) ;
V_4 -> V_10 = NULL ;
}
F_160 ( V_4 -> V_161 , V_257 -> V_259 ) ;
}
static int F_161 ( struct V_2 * V_4 )
{
struct V_261 * V_262 ;
struct V_1 * V_257 = F_1 ( V_4 ) ;
int V_156 ;
V_262 = F_162 ( V_4 -> V_161 , V_257 -> V_259 ,
F_129 ( V_4 -> V_29 ) ) ;
if ( F_127 ( V_262 == NULL ) ) {
F_79 ( V_4 -> V_29 , L_46 ) ;
return - V_263 ;
}
V_156 = F_156 ( V_4 ) ;
if ( F_127 ( V_156 != 0 ) ) {
F_163 ( V_262 ) ;
return V_156 ;
}
return 0 ;
}
static void F_164 ( struct V_2 * V_4 , int V_111 )
{
if ( V_111 & V_264 ) {
struct V_1 * V_257 = F_1 ( V_4 ) ;
V_4 -> type = V_257 -> V_14 -> type ;
F_161 ( V_4 ) ;
}
}
static int F_165 ( struct V_2 * V_4 , struct V_265 * V_266 )
{
if ( V_266 -> V_267 < 2400 )
return - V_28 ;
return 0 ;
}
static int F_166 ( struct V_268 * V_29 ,
struct V_1 * V_1 , unsigned int V_269 ,
struct V_13 * V_5 , bool V_270 )
{
struct V_2 * V_4 = & V_1 -> V_4 ;
const struct V_261 * V_262 ;
unsigned int V_92 ;
int V_156 ;
V_1 -> V_14 = V_5 ;
V_4 -> V_65 = & V_271 ;
V_4 -> V_272 = V_273 ;
V_4 -> line = V_269 ;
V_262 = F_167 ( V_29 , V_274 , 0 ) ;
if ( V_262 == NULL )
return - V_275 ;
V_4 -> V_161 = V_262 -> V_276 ;
V_1 -> V_259 = F_168 ( V_262 ) ;
for ( V_92 = 0 ; V_92 < F_78 ( V_1 -> V_150 ) ; ++ V_92 )
V_1 -> V_150 [ V_92 ] = F_169 ( V_29 , V_92 ) ;
if ( V_1 -> V_150 [ 0 ] < 0 )
return - V_260 ;
if ( V_1 -> V_150 [ 1 ] < 0 ) {
V_1 -> V_150 [ 1 ] = V_1 -> V_150 [ 0 ] ;
V_1 -> V_150 [ 2 ] = V_1 -> V_150 [ 0 ] ;
V_1 -> V_150 [ 3 ] = V_1 -> V_150 [ 0 ] ;
}
if ( V_5 -> V_16 == V_277 ) {
V_156 = F_11 ( V_5 ) ;
if ( F_127 ( V_156 ) )
return V_156 ;
}
switch ( V_5 -> type ) {
case V_22 :
V_4 -> V_73 = 256 ;
V_1 -> V_109 = V_52 ;
V_1 -> V_53 = V_54 ;
V_1 -> V_212 = 16 ;
break;
case V_26 :
V_4 -> V_73 = 128 ;
V_1 -> V_109 = V_278 ;
V_1 -> V_53 = V_279 ;
V_1 -> V_212 = 0 ;
break;
case V_20 :
V_4 -> V_73 = 64 ;
V_1 -> V_109 = V_52 ;
V_1 -> V_53 = V_54 ;
V_1 -> V_212 = 16 ;
break;
case V_24 :
V_4 -> V_73 = 16 ;
if ( V_5 -> V_16 == V_280 ) {
V_1 -> V_109 = V_52 ;
V_1 -> V_53 = V_54 ;
V_1 -> V_212 = 16 ;
} else {
V_1 -> V_109 = V_278 ;
V_1 -> V_53 = V_279 ;
V_1 -> V_212 = 32 ;
}
break;
default:
V_4 -> V_73 = 1 ;
V_1 -> V_109 = V_52 ;
V_1 -> V_53 = V_281 ;
V_1 -> V_212 = 32 ;
break;
}
if ( V_5 -> V_212 )
V_1 -> V_212 = V_5 -> V_212 ;
if ( ! V_270 ) {
V_1 -> V_30 = F_170 ( & V_29 -> V_29 , L_47 ) ;
if ( F_171 ( V_1 -> V_30 ) ) {
V_1 -> V_30 = F_170 ( & V_29 -> V_29 , L_48 ) ;
if ( F_171 ( V_1 -> V_30 ) ) {
F_79 ( & V_29 -> V_29 , L_49 ) ;
return F_172 ( V_1 -> V_30 ) ;
}
}
V_1 -> V_32 = F_170 ( & V_29 -> V_29 , L_50 ) ;
if ( F_171 ( V_1 -> V_32 ) )
V_1 -> V_32 = NULL ;
V_4 -> V_29 = & V_29 -> V_29 ;
F_173 ( & V_29 -> V_29 ) ;
}
V_1 -> V_33 . V_104 = ( unsigned long ) V_1 ;
V_1 -> V_33 . V_282 = F_65 ;
F_174 ( & V_1 -> V_33 ) ;
if ( V_5 -> type == V_15 ) {
V_1 -> V_283 = V_284 ;
V_1 -> V_285 = V_286 ;
} else {
V_1 -> V_283 = V_287 ;
V_1 -> V_285 = V_288 ;
}
if ( V_1 -> V_109 == V_52 ) {
V_1 -> V_283 |= V_1 -> V_53 ;
V_1 -> V_285 &= ~ V_1 -> V_53 ;
}
V_4 -> type = V_5 -> type ;
V_4 -> V_111 = V_289 | V_5 -> V_111 ;
V_4 -> V_11 = V_5 -> V_11 ;
V_4 -> V_171 = V_1 -> V_150 [ V_151 ] ;
V_4 -> V_195 = 0 ;
V_4 -> V_290 = F_3 ;
V_4 -> V_291 = F_8 ;
if ( V_5 -> V_167 > 0 && V_5 -> V_168 > 0 )
F_58 ( V_4 -> V_29 , L_51 ,
V_5 -> V_167 , V_5 -> V_168 ) ;
return 0 ;
}
static void F_175 ( struct V_1 * V_4 )
{
F_176 ( V_4 -> V_30 ) ;
F_176 ( V_4 -> V_32 ) ;
F_177 ( V_4 -> V_4 . V_29 ) ;
}
static void F_178 ( struct V_2 * V_4 , int V_292 )
{
F_38 ( V_4 , V_292 ) ;
}
static void F_179 ( struct V_293 * V_294 , const char * V_38 ,
unsigned V_82 )
{
struct V_1 * V_1 = & V_295 [ V_294 -> V_269 ] ;
struct V_2 * V_4 = & V_1 -> V_4 ;
unsigned short V_249 , V_39 ;
unsigned long V_111 ;
int V_296 = 1 ;
F_180 ( V_111 ) ;
if ( V_4 -> V_297 )
V_296 = 0 ;
else if ( V_298 )
V_296 = F_181 ( & V_4 -> V_113 ) ;
else
F_182 ( & V_4 -> V_113 ) ;
V_39 = F_24 ( V_4 , V_42 ) ;
F_25 ( V_4 , V_42 , V_1 -> V_14 -> V_36 ) ;
F_183 ( V_4 , V_38 , V_82 , F_178 ) ;
V_249 = F_39 ( V_4 ) | F_41 ( V_4 ) ;
while ( ( F_24 ( V_4 , V_52 ) & V_249 ) != V_249 )
F_184 () ;
F_25 ( V_4 , V_42 , V_39 ) ;
if ( V_296 )
F_185 ( & V_4 -> V_113 ) ;
F_186 ( V_111 ) ;
}
static int F_187 ( struct V_293 * V_294 , char * V_299 )
{
struct V_1 * V_1 ;
struct V_2 * V_4 ;
int V_233 = 115200 ;
int V_249 = 8 ;
int V_100 = 'n' ;
int V_300 = 'n' ;
int V_156 ;
if ( V_294 -> V_269 < 0 || V_294 -> V_269 >= V_301 )
return - V_302 ;
V_1 = & V_295 [ V_294 -> V_269 ] ;
V_4 = & V_1 -> V_4 ;
if ( ! V_4 -> V_65 )
return - V_302 ;
V_156 = F_156 ( V_4 ) ;
if ( F_127 ( V_156 != 0 ) )
return V_156 ;
if ( V_299 )
F_188 ( V_299 , & V_233 , & V_100 , & V_249 , & V_300 ) ;
return F_189 ( V_4 , V_294 , V_233 , V_100 , V_249 , V_300 ) ;
}
static int F_190 ( struct V_268 * V_303 )
{
struct V_13 * V_14 = F_191 ( & V_303 -> V_29 ) ;
if ( V_304 . V_104 )
return - V_305 ;
V_304 . V_269 = V_303 -> V_154 ;
F_166 ( V_303 , & V_295 [ V_303 -> V_154 ] , V_303 -> V_154 , V_14 , true ) ;
F_187 ( & V_304 , V_306 ) ;
if ( ! strstr ( V_306 , L_52 ) )
V_304 . V_111 |= V_307 ;
F_192 ( & V_304 ) ;
return 0 ;
}
static inline int F_190 ( struct V_268 * V_303 )
{
return - V_28 ;
}
static int F_193 ( struct V_268 * V_29 )
{
struct V_1 * V_4 = F_194 ( V_29 ) ;
F_195 ( & V_4 -> V_184 ,
V_308 ) ;
F_196 ( & V_309 , & V_4 -> V_4 ) ;
F_175 ( V_4 ) ;
return 0 ;
}
static struct V_13 *
F_197 ( struct V_268 * V_303 , unsigned int * V_310 )
{
struct V_311 * V_312 = V_303 -> V_29 . V_166 ;
const struct V_313 * V_314 ;
const struct V_315 * V_316 ;
struct V_13 * V_5 ;
int V_154 ;
if ( ! F_198 ( V_317 ) || ! V_312 )
return NULL ;
V_314 = F_199 ( V_318 , V_303 -> V_29 . V_166 ) ;
if ( ! V_314 )
return NULL ;
V_316 = V_314 -> V_104 ;
V_5 = F_200 ( & V_303 -> V_29 , sizeof( struct V_13 ) , V_170 ) ;
if ( ! V_5 )
return NULL ;
V_154 = F_201 ( V_312 , L_53 ) ;
if ( V_154 < 0 ) {
F_79 ( & V_303 -> V_29 , L_54 , V_154 ) ;
return NULL ;
}
* V_310 = V_154 ;
V_5 -> V_111 = V_258 | V_319 ;
V_5 -> type = V_316 -> type ;
V_5 -> V_16 = V_316 -> V_16 ;
V_5 -> V_36 = V_320 | V_209 ;
return V_5 ;
}
static int F_202 ( struct V_268 * V_29 ,
unsigned int V_269 ,
struct V_13 * V_5 ,
struct V_1 * V_321 )
{
int V_156 ;
if ( F_127 ( V_269 >= V_301 ) ) {
F_60 ( & V_29 -> V_29 , L_55 ,
V_269 + 1 , V_301 ) ;
F_60 ( & V_29 -> V_29 , L_56 ) ;
return - V_28 ;
}
V_156 = F_166 ( V_29 , V_321 , V_269 , V_5 , false ) ;
if ( V_156 )
return V_156 ;
V_156 = F_203 ( & V_309 , & V_321 -> V_4 ) ;
if ( V_156 ) {
F_175 ( V_321 ) ;
return V_156 ;
}
return 0 ;
}
static int F_204 ( struct V_268 * V_29 )
{
struct V_13 * V_5 ;
struct V_1 * V_322 ;
unsigned int V_310 ;
int V_156 ;
if ( F_205 ( V_29 ) )
return F_190 ( V_29 ) ;
if ( V_29 -> V_29 . V_166 ) {
V_5 = F_197 ( V_29 , & V_310 ) ;
if ( V_5 == NULL )
return - V_28 ;
} else {
V_5 = V_29 -> V_29 . V_323 ;
if ( V_5 == NULL ) {
F_79 ( & V_29 -> V_29 , L_57 ) ;
return - V_28 ;
}
V_310 = V_29 -> V_154 ;
}
V_322 = & V_295 [ V_310 ] ;
F_206 ( V_29 , V_322 ) ;
V_156 = F_202 ( V_29 , V_310 , V_5 , V_322 ) ;
if ( V_156 )
return V_156 ;
V_322 -> V_184 . V_324 = F_124 ;
V_156 = F_207 ( & V_322 -> V_184 ,
V_308 ) ;
if ( F_127 ( V_156 < 0 ) ) {
F_196 ( & V_309 , & V_322 -> V_4 ) ;
F_175 ( V_322 ) ;
return V_156 ;
}
#ifdef F_208
F_209 () ;
#endif
return 0 ;
}
static T_6 int F_210 ( struct V_122 * V_29 )
{
struct V_1 * V_257 = F_211 ( V_29 ) ;
if ( V_257 )
F_212 ( & V_309 , & V_257 -> V_4 ) ;
return 0 ;
}
static T_6 int F_213 ( struct V_122 * V_29 )
{
struct V_1 * V_257 = F_211 ( V_29 ) ;
if ( V_257 )
F_214 ( & V_309 , & V_257 -> V_4 ) ;
return 0 ;
}
static int T_7 F_215 ( void )
{
int V_156 ;
F_216 ( L_58 , V_325 ) ;
V_156 = F_217 ( & V_309 ) ;
if ( F_149 ( V_156 == 0 ) ) {
V_156 = F_218 ( & V_326 ) ;
if ( F_127 ( V_156 ) )
F_219 ( & V_309 ) ;
}
return V_156 ;
}
static void T_8 F_220 ( void )
{
F_221 ( & V_326 ) ;
F_219 ( & V_309 ) ;
}
