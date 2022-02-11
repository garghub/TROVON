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
int V_78 = 0 , V_6 ;
T_1 V_35 , V_95 ;
switch ( V_4 -> type ) {
case V_24 :
case V_26 :
V_6 = V_96 ;
break;
case V_20 :
case V_22 :
V_6 = V_37 ;
break;
default:
return 0 ;
}
V_8 = F_4 ( V_4 , V_6 ) ;
if ( ! V_8 -> V_9 )
return 0 ;
V_35 = F_22 ( V_4 , V_6 ) ;
V_95 = 1 << V_42 -> V_90 ;
if ( V_35 & V_95 ) {
V_35 &= ~ V_95 ;
F_24 ( V_4 , V_6 , V_35 ) ;
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
static T_2 F_63 ( int V_97 , void * V_98 )
{
#ifdef F_64
struct V_2 * V_4 = V_98 ;
struct V_1 * V_42 = F_1 ( V_4 ) ;
if ( V_42 -> V_99 ) {
T_1 V_100 = F_22 ( V_4 , V_66 ) ;
T_1 V_101 = F_22 ( V_4 , V_37 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
F_65 ( V_97 ) ;
V_100 |= V_102 ;
} else {
V_100 &= ~ V_103 ;
}
F_24 ( V_4 , V_66 , V_100 ) ;
F_24 ( V_4 , V_37 , V_101 & ~ ( 1 | F_26 ( V_4 ) ) ) ;
F_50 ( V_4 -> V_29 , L_8 ,
V_87 , V_42 -> V_104 ) ;
F_56 ( & V_42 -> V_105 , V_87 + V_42 -> V_104 ) ;
return V_106 ;
}
#endif
F_44 ( V_98 ) ;
return V_106 ;
}
static T_2 F_66 ( int V_97 , void * V_98 )
{
struct V_2 * V_4 = V_98 ;
unsigned long V_107 ;
F_67 ( & V_4 -> V_108 , V_107 ) ;
F_38 ( V_4 ) ;
F_68 ( & V_4 -> V_108 , V_107 ) ;
return V_106 ;
}
static T_2 F_69 ( int V_97 , void * V_98 )
{
struct V_2 * V_4 = V_98 ;
if ( V_4 -> type == V_15 ) {
if ( F_58 ( V_4 ) ) {
F_22 ( V_4 , V_37 ) ;
F_24 ( V_4 , V_37 , F_27 ( V_4 ) ) ;
}
} else {
F_60 ( V_4 ) ;
F_63 ( V_97 , V_98 ) ;
}
F_24 ( V_4 , V_37 , F_25 ( V_4 ) ) ;
F_66 ( V_97 , V_98 ) ;
return V_106 ;
}
static T_2 F_70 ( int V_97 , void * V_98 )
{
struct V_2 * V_4 = V_98 ;
F_61 ( V_4 ) ;
F_24 ( V_4 , V_37 , F_71 ( V_4 ) ) ;
return V_106 ;
}
static inline unsigned long F_72 ( struct V_2 * V_4 )
{
return V_103 | ( F_1 ( V_4 ) -> V_14 -> V_109 & V_110 ) ;
}
static T_2 F_73 ( int V_97 , void * V_98 )
{
unsigned short V_111 , V_112 , V_113 , V_114 = 0 ;
struct V_2 * V_4 = V_98 ;
struct V_1 * V_42 = F_1 ( V_4 ) ;
T_2 V_115 = V_116 ;
V_111 = F_22 ( V_4 , V_37 ) ;
V_112 = F_22 ( V_4 , V_66 ) ;
switch ( V_4 -> type ) {
case V_24 :
case V_26 :
V_114 = F_22 ( V_4 , V_96 ) ;
break;
case V_20 :
case V_22 :
V_114 = V_111 ;
break;
}
V_113 = V_112 & F_72 ( V_4 ) ;
if ( ( V_111 & F_29 ( V_4 ) ) && ( V_112 & V_67 ) &&
! V_42 -> V_117 )
V_115 = F_66 ( V_97 , V_98 ) ;
if ( ( ( V_111 & F_26 ( V_4 ) ) || V_42 -> V_99 ) &&
( V_112 & V_103 ) ) {
if ( V_4 -> type == V_24 || V_4 -> type == V_26 )
F_60 ( V_4 ) ;
V_115 = F_63 ( V_97 , V_98 ) ;
}
if ( ( V_111 & F_23 ( V_4 ) ) && V_113 )
V_115 = F_69 ( V_97 , V_98 ) ;
if ( ( V_111 & F_62 ( V_4 ) ) && V_113 )
V_115 = F_70 ( V_97 , V_98 ) ;
if ( V_114 & ( 1 << V_42 -> V_90 ) )
F_60 ( V_4 ) ;
return V_115 ;
}
static int F_74 ( struct V_118 * V_119 ,
unsigned long V_120 , void * V_5 )
{
struct V_1 * V_1 ;
unsigned long V_107 ;
V_1 = F_2 ( V_119 , struct V_1 , V_121 ) ;
if ( V_120 == V_122 ) {
struct V_2 * V_4 = & V_1 -> V_4 ;
F_67 ( & V_4 -> V_108 , V_107 ) ;
V_4 -> V_31 = F_16 ( V_1 -> V_30 ) ;
F_68 ( & V_4 -> V_108 , V_107 ) ;
}
return V_123 ;
}
static int F_75 ( struct V_1 * V_4 )
{
struct V_2 * V_124 = & V_4 -> V_4 ;
int V_77 , V_125 , V_115 = 0 ;
for ( V_77 = V_125 = 0 ; V_77 < V_126 ; V_77 ++ , V_125 ++ ) {
struct V_127 * V_128 ;
int V_97 ;
if ( F_76 ( V_4 ) ) {
V_77 = V_129 ;
V_97 = V_124 -> V_97 ;
} else {
V_97 = V_4 -> V_130 [ V_77 ] ;
if ( F_77 ( V_97 < 0 ) )
continue;
}
V_128 = V_127 + V_77 ;
V_4 -> V_131 [ V_125 ] = F_78 ( V_132 , L_9 ,
F_79 ( V_124 -> V_29 ) , V_128 -> V_128 ) ;
if ( ! V_4 -> V_131 [ V_125 ] ) {
F_80 ( V_124 -> V_29 , L_10 ,
V_128 -> V_128 ) ;
goto V_133;
}
V_115 = F_81 ( V_97 , V_128 -> V_134 , V_124 -> V_135 ,
V_4 -> V_131 [ V_125 ] , V_4 ) ;
if ( F_77 ( V_115 ) ) {
F_80 ( V_124 -> V_29 , L_11 , V_128 -> V_128 ) ;
goto V_136;
}
}
return 0 ;
V_136:
while ( -- V_77 >= 0 )
F_82 ( V_4 -> V_130 [ V_77 ] , V_4 ) ;
V_133:
while ( -- V_125 >= 0 )
F_83 ( V_4 -> V_131 [ V_125 ] ) ;
return V_115 ;
}
static void F_84 ( struct V_1 * V_4 )
{
int V_77 ;
for ( V_77 = 0 ; V_77 < V_126 ; V_77 ++ ) {
int V_97 = V_4 -> V_130 [ V_77 ] ;
if ( F_77 ( V_97 < 0 ) )
continue;
F_82 ( V_4 -> V_130 [ V_77 ] , V_4 ) ;
F_83 ( V_4 -> V_131 [ V_77 ] ) ;
if ( F_76 ( V_4 ) ) {
return;
}
}
}
static unsigned int F_85 ( struct V_2 * V_4 )
{
unsigned short V_35 = F_22 ( V_4 , V_37 ) ;
unsigned short V_137 = F_33 ( V_4 ) ;
return ( V_35 & F_31 ( V_4 ) ) && ! V_137 ? V_138 : 0 ;
}
static void F_86 ( struct V_2 * V_4 , unsigned int V_139 )
{
if ( V_139 & V_140 ) {
struct V_7 * V_8 ;
V_8 = F_4 ( V_4 , V_141 ) ;
if ( V_8 -> V_9 )
F_24 ( V_4 , V_141 ,
F_22 ( V_4 , V_141 ) |
V_142 ) ;
}
}
static unsigned int F_87 ( struct V_2 * V_4 )
{
return V_143 | V_144 ;
}
static void F_88 ( void * V_145 )
{
struct V_1 * V_42 = V_145 ;
struct V_2 * V_4 = & V_42 -> V_4 ;
struct V_60 * V_61 = & V_4 -> V_62 -> V_61 ;
unsigned long V_107 ;
F_50 ( V_4 -> V_29 , L_12 , V_146 , V_4 -> line ) ;
F_67 ( & V_4 -> V_108 , V_107 ) ;
V_61 -> V_70 += F_89 ( & V_42 -> V_147 ) ;
V_61 -> V_70 &= V_71 - 1 ;
V_4 -> V_72 . V_73 += F_89 ( & V_42 -> V_147 ) ;
F_90 ( V_42 -> V_148 ) ;
V_42 -> V_148 = NULL ;
if ( F_41 ( V_61 ) < V_74 )
F_42 ( V_4 ) ;
if ( ! F_40 ( V_61 ) ) {
V_42 -> V_149 = 0 ;
F_91 ( & V_42 -> V_150 ) ;
} else {
V_42 -> V_149 = - V_28 ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
T_1 V_64 = F_22 ( V_4 , V_66 ) ;
F_24 ( V_4 , V_66 , V_64 & ~ V_67 ) ;
}
}
F_68 ( & V_4 -> V_108 , V_107 ) ;
}
static int F_92 ( struct V_1 * V_42 , T_3 V_65 )
{
struct V_2 * V_4 = & V_42 -> V_4 ;
struct V_75 * V_76 = & V_4 -> V_62 -> V_4 ;
int V_77 , V_151 , V_152 ;
V_152 = F_45 ( V_76 , V_65 ) ;
if ( V_42 -> V_153 == V_42 -> V_154 [ 0 ] ) {
V_151 = 0 ;
} else if ( V_42 -> V_153 == V_42 -> V_154 [ 1 ] ) {
V_151 = 1 ;
} else {
F_80 ( V_4 -> V_29 , L_13 , V_42 -> V_153 ) ;
return 0 ;
}
if ( V_152 < V_65 )
F_93 ( V_4 -> V_29 , L_14 ,
V_65 - V_152 ) ;
if ( ! V_152 )
return V_152 ;
for ( V_77 = 0 ; V_77 < V_152 ; V_77 ++ )
F_47 ( V_76 , ( ( V_155 * ) F_94 ( & V_42 -> V_156 [ V_151 ] ) ) [ V_77 ] ,
V_80 ) ;
V_4 -> V_72 . V_86 += V_152 ;
return V_152 ;
}
static void F_95 ( void * V_145 )
{
struct V_1 * V_42 = V_145 ;
struct V_2 * V_4 = & V_42 -> V_4 ;
unsigned long V_107 ;
int V_65 ;
F_50 ( V_4 -> V_29 , L_15 ,
V_146 , V_4 -> line , V_42 -> V_153 ) ;
F_67 ( & V_4 -> V_108 , V_107 ) ;
V_65 = F_92 ( V_42 , V_42 -> V_157 ) ;
F_56 ( & V_42 -> V_105 , V_87 + V_42 -> V_104 ) ;
F_68 ( & V_4 -> V_108 , V_107 ) ;
if ( V_65 )
F_54 ( & V_4 -> V_62 -> V_4 ) ;
F_91 ( & V_42 -> V_158 ) ;
}
static void F_96 ( struct V_1 * V_42 , bool V_159 )
{
struct V_160 * V_161 = V_42 -> V_99 ;
struct V_2 * V_4 = & V_42 -> V_4 ;
V_42 -> V_99 = NULL ;
V_42 -> V_154 [ 0 ] = V_42 -> V_154 [ 1 ] = - V_28 ;
F_97 ( V_161 ) ;
if ( F_98 ( & V_42 -> V_156 [ 0 ] ) )
F_99 ( V_4 -> V_29 , V_42 -> V_157 * 2 ,
F_94 ( & V_42 -> V_156 [ 0 ] ) , F_98 ( & V_42 -> V_156 [ 0 ] ) ) ;
if ( V_159 )
F_100 ( V_4 ) ;
}
static void F_101 ( struct V_1 * V_42 , bool V_159 )
{
struct V_160 * V_161 = V_42 -> V_117 ;
struct V_2 * V_4 = & V_42 -> V_4 ;
V_42 -> V_117 = NULL ;
V_42 -> V_149 = - V_28 ;
F_97 ( V_161 ) ;
if ( V_159 )
F_102 ( V_4 ) ;
}
static void F_103 ( struct V_1 * V_42 )
{
struct V_160 * V_161 = V_42 -> V_99 ;
int V_77 ;
for ( V_77 = 0 ; V_77 < 2 ; V_77 ++ ) {
struct V_162 * V_163 = & V_42 -> V_156 [ V_77 ] ;
struct V_164 * V_128 ;
V_128 = F_104 ( V_161 ,
V_163 , 1 , V_165 , V_166 ) ;
if ( V_128 ) {
V_42 -> V_167 [ V_77 ] = V_128 ;
V_128 -> V_168 = F_95 ;
V_128 -> V_169 = V_42 ;
V_42 -> V_154 [ V_77 ] = V_128 -> V_170 ( V_128 ) ;
}
if ( ! V_128 || V_42 -> V_154 [ V_77 ] < 0 ) {
if ( V_77 ) {
F_90 ( V_42 -> V_167 [ 0 ] ) ;
V_42 -> V_154 [ 0 ] = - V_28 ;
}
if ( V_128 ) {
F_90 ( V_128 ) ;
V_42 -> V_154 [ V_77 ] = - V_28 ;
}
F_93 ( V_42 -> V_4 . V_29 ,
L_16 ) ;
F_96 ( V_42 , true ) ;
return;
}
F_50 ( V_42 -> V_4 . V_29 , L_17 ,
V_146 , V_42 -> V_154 [ V_77 ] , V_77 ) ;
}
V_42 -> V_153 = V_42 -> V_154 [ 0 ] ;
F_105 ( V_161 ) ;
}
static void F_106 ( struct V_171 * V_172 )
{
struct V_1 * V_42 = F_2 ( V_172 , struct V_1 , V_158 ) ;
struct V_2 * V_4 = & V_42 -> V_4 ;
struct V_164 * V_128 ;
int V_173 ;
if ( V_42 -> V_153 == V_42 -> V_154 [ 0 ] ) {
V_173 = 0 ;
} else if ( V_42 -> V_153 == V_42 -> V_154 [ 1 ] ) {
V_173 = 1 ;
} else {
F_80 ( V_4 -> V_29 , L_13 , V_42 -> V_153 ) ;
return;
}
V_128 = V_42 -> V_167 [ V_173 ] ;
if ( F_107 ( V_42 -> V_99 , V_42 -> V_153 , NULL , NULL ) !=
V_174 ) {
struct V_160 * V_161 = V_42 -> V_99 ;
struct V_175 * V_176 = F_2 ( V_128 ,
struct V_175 , V_177 ) ;
unsigned long V_107 ;
int V_65 ;
F_108 ( V_161 ) ;
F_50 ( V_4 -> V_29 , L_18 ,
V_176 -> V_178 , V_176 -> V_179 ) ;
F_67 ( & V_4 -> V_108 , V_107 ) ;
V_65 = F_92 ( V_42 , V_176 -> V_178 ) ;
F_68 ( & V_4 -> V_108 , V_107 ) ;
if ( V_65 )
F_54 ( & V_4 -> V_62 -> V_4 ) ;
F_103 ( V_42 ) ;
return;
}
V_42 -> V_154 [ V_173 ] = V_128 -> V_170 ( V_128 ) ;
if ( V_42 -> V_154 [ V_173 ] < 0 ) {
F_93 ( V_4 -> V_29 , L_19 ) ;
F_96 ( V_42 , true ) ;
return;
}
V_42 -> V_153 = V_42 -> V_154 [ ! V_173 ] ;
F_50 ( V_4 -> V_29 , L_20 ,
V_146 , V_42 -> V_154 [ V_173 ] , V_173 , V_42 -> V_153 ) ;
}
static void F_109 ( struct V_171 * V_172 )
{
struct V_1 * V_42 = F_2 ( V_172 , struct V_1 , V_150 ) ;
struct V_164 * V_128 ;
struct V_160 * V_161 = V_42 -> V_117 ;
struct V_2 * V_4 = & V_42 -> V_4 ;
struct V_60 * V_61 = & V_4 -> V_62 -> V_61 ;
struct V_162 * V_163 = & V_42 -> V_147 ;
F_110 ( & V_4 -> V_108 ) ;
V_163 -> V_6 = V_61 -> V_70 & ( V_71 - 1 ) ;
F_98 ( V_163 ) = ( F_98 ( V_163 ) & ~ ( V_71 - 1 ) ) +
V_163 -> V_6 ;
F_89 ( V_163 ) = F_111 ( ( int ) F_112 ( V_61 -> V_180 , V_61 -> V_70 , V_71 ) ,
F_113 ( V_61 -> V_180 , V_61 -> V_70 , V_71 ) ) ;
F_114 ( & V_4 -> V_108 ) ;
F_115 ( ! F_89 ( V_163 ) ) ;
V_128 = F_104 ( V_161 ,
V_163 , V_42 -> V_181 , V_182 ,
V_166 | V_183 ) ;
if ( ! V_128 ) {
F_101 ( V_42 , true ) ;
return;
}
F_116 ( V_4 -> V_29 , V_163 , 1 , V_184 ) ;
F_110 ( & V_4 -> V_108 ) ;
V_42 -> V_148 = V_128 ;
V_128 -> V_168 = F_88 ;
V_128 -> V_169 = V_42 ;
F_114 ( & V_4 -> V_108 ) ;
V_42 -> V_149 = V_128 -> V_170 ( V_128 ) ;
if ( V_42 -> V_149 < 0 ) {
F_93 ( V_4 -> V_29 , L_21 ) ;
F_101 ( V_42 , true ) ;
return;
}
F_50 ( V_4 -> V_29 , L_22 ,
V_146 , V_61 -> V_69 , V_61 -> V_70 , V_61 -> V_180 , V_42 -> V_149 ) ;
F_105 ( V_161 ) ;
}
static void F_102 ( struct V_2 * V_4 )
{
struct V_1 * V_42 = F_1 ( V_4 ) ;
unsigned short V_64 ;
#ifdef F_64
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
T_1 V_173 , V_100 = F_22 ( V_4 , V_66 ) ;
if ( V_42 -> V_117 )
V_173 = V_100 | V_185 ;
else
V_173 = V_100 & ~ V_185 ;
if ( V_173 != V_100 )
F_24 ( V_4 , V_66 , V_173 ) ;
}
if ( V_42 -> V_117 && ! F_40 ( & V_42 -> V_4 . V_62 -> V_61 ) &&
V_42 -> V_149 < 0 ) {
V_42 -> V_149 = 0 ;
F_91 ( & V_42 -> V_150 ) ;
}
#endif
if ( ! V_42 -> V_117 || V_4 -> type == V_20 || V_4 -> type == V_22 ) {
V_64 = F_22 ( V_4 , V_66 ) ;
F_24 ( V_4 , V_66 , V_64 | V_67 ) ;
}
}
static void F_43 ( struct V_2 * V_4 )
{
unsigned short V_64 ;
V_64 = F_22 ( V_4 , V_66 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 )
V_64 &= ~ V_185 ;
V_64 &= ~ V_67 ;
F_24 ( V_4 , V_66 , V_64 ) ;
}
static void F_100 ( struct V_2 * V_4 )
{
unsigned short V_64 ;
V_64 = F_22 ( V_4 , V_66 ) | F_72 ( V_4 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 )
V_64 &= ~ V_102 ;
F_24 ( V_4 , V_66 , V_64 ) ;
}
static void F_117 ( struct V_2 * V_4 )
{
unsigned short V_64 ;
V_64 = F_22 ( V_4 , V_66 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 )
V_64 &= ~ V_102 ;
V_64 &= ~ F_72 ( V_4 ) ;
F_24 ( V_4 , V_66 , V_64 ) ;
}
static void F_118 ( struct V_2 * V_4 , int V_186 )
{
struct V_1 * V_42 = F_1 ( V_4 ) ;
struct V_7 * V_8 = V_43 [ V_42 -> V_14 -> V_16 ] + V_44 ;
unsigned short V_109 , V_187 ;
if ( ! V_8 -> V_9 ) {
return;
}
V_187 = F_22 ( V_4 , V_44 ) ;
V_109 = F_22 ( V_4 , V_66 ) ;
if ( V_186 == - 1 ) {
V_187 = ( V_187 | V_188 ) & ~ V_189 ;
V_109 &= ~ V_190 ;
} else {
V_187 = ( V_187 | V_189 ) & ~ V_188 ;
V_109 |= V_190 ;
}
F_24 ( V_4 , V_44 , V_187 ) ;
F_24 ( V_4 , V_66 , V_109 ) ;
}
static bool F_119 ( struct V_160 * V_161 , void * V_191 )
{
struct V_192 * V_193 = V_191 ;
F_50 ( V_161 -> V_194 -> V_29 , L_23 ,
V_146 , V_193 -> V_195 . V_196 ) ;
V_161 -> V_197 = & V_193 -> V_195 ;
return true ;
}
static void F_120 ( unsigned long V_145 )
{
struct V_1 * V_42 = (struct V_1 * ) V_145 ;
struct V_2 * V_4 = & V_42 -> V_4 ;
T_1 V_100 = F_22 ( V_4 , V_66 ) ;
if ( V_4 -> type == V_20 || V_4 -> type == V_22 ) {
V_100 &= ~ V_102 ;
F_121 ( V_42 -> V_130 [ V_198 ] ) ;
}
F_24 ( V_4 , V_66 , V_100 | V_103 ) ;
F_50 ( V_4 -> V_29 , L_24 ) ;
F_91 ( & V_42 -> V_158 ) ;
}
static void F_122 ( struct V_2 * V_4 )
{
struct V_1 * V_42 = F_1 ( V_4 ) ;
struct V_192 * V_193 ;
struct V_160 * V_161 ;
T_4 V_199 ;
int V_200 ;
F_50 ( V_4 -> V_29 , L_25 , V_146 , V_4 -> line ) ;
if ( V_42 -> V_14 -> V_201 <= 0 || V_42 -> V_14 -> V_202 <= 0 )
return;
F_123 ( V_199 ) ;
F_124 ( V_203 , V_199 ) ;
V_193 = & V_42 -> V_204 ;
V_193 -> V_195 . V_196 = V_42 -> V_14 -> V_201 ;
V_42 -> V_149 = - V_28 ;
V_161 = F_125 ( V_199 , F_119 , V_193 ) ;
F_50 ( V_4 -> V_29 , L_26 , V_146 , V_161 ) ;
if ( V_161 ) {
V_42 -> V_117 = V_161 ;
F_126 ( & V_42 -> V_147 , 1 ) ;
F_115 ( ( V_59 ) V_4 -> V_62 -> V_61 . V_69 & ~ V_205 ) ;
F_127 ( & V_42 -> V_147 , F_128 ( V_4 -> V_62 -> V_61 . V_69 ) ,
V_71 ,
( V_59 ) V_4 -> V_62 -> V_61 . V_69 & ~ V_205 ) ;
V_200 = F_129 ( V_4 -> V_29 , & V_42 -> V_147 , 1 , V_184 ) ;
if ( ! V_200 )
F_101 ( V_42 , false ) ;
else
F_50 ( V_4 -> V_29 , L_27 ,
V_146 ,
F_89 ( & V_42 -> V_147 ) , V_4 -> V_62 -> V_61 . V_69 ,
& F_98 ( & V_42 -> V_147 ) ) ;
V_42 -> V_181 = V_200 ;
F_130 ( & V_42 -> V_150 , F_109 ) ;
}
V_193 = & V_42 -> V_206 ;
V_193 -> V_195 . V_196 = V_42 -> V_14 -> V_202 ;
V_161 = F_125 ( V_199 , F_119 , V_193 ) ;
F_50 ( V_4 -> V_29 , L_28 , V_146 , V_161 ) ;
if ( V_161 ) {
T_5 V_207 [ 2 ] ;
void * V_69 [ 2 ] ;
int V_77 ;
V_42 -> V_99 = V_161 ;
V_42 -> V_157 = 2 * F_131 ( 16 , ( int ) V_4 -> V_53 ) ;
V_69 [ 0 ] = F_132 ( V_4 -> V_29 , V_42 -> V_157 * 2 ,
& V_207 [ 0 ] , V_132 ) ;
if ( ! V_69 [ 0 ] ) {
F_93 ( V_4 -> V_29 ,
L_29 ) ;
F_96 ( V_42 , true ) ;
return;
}
V_69 [ 1 ] = V_69 [ 0 ] + V_42 -> V_157 ;
V_207 [ 1 ] = V_207 [ 0 ] + V_42 -> V_157 ;
for ( V_77 = 0 ; V_77 < 2 ; V_77 ++ ) {
struct V_162 * V_163 = & V_42 -> V_156 [ V_77 ] ;
F_126 ( V_163 , 1 ) ;
F_127 ( V_163 , F_128 ( V_69 [ V_77 ] ) , V_42 -> V_157 ,
( V_59 ) V_69 [ V_77 ] & ~ V_205 ) ;
F_98 ( V_163 ) = V_207 [ V_77 ] ;
}
F_130 ( & V_42 -> V_158 , F_106 ) ;
F_133 ( & V_42 -> V_105 , F_120 , ( unsigned long ) V_42 ) ;
F_103 ( V_42 ) ;
}
}
static void F_134 ( struct V_2 * V_4 )
{
struct V_1 * V_42 = F_1 ( V_4 ) ;
if ( V_42 -> V_117 )
F_101 ( V_42 , false ) ;
if ( V_42 -> V_99 )
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
unsigned long V_107 ;
int V_115 ;
F_50 ( V_4 -> V_29 , L_12 , V_146 , V_4 -> line ) ;
V_115 = F_75 ( V_42 ) ;
if ( F_77 ( V_115 < 0 ) )
return V_115 ;
F_122 ( V_4 ) ;
F_67 ( & V_4 -> V_108 , V_107 ) ;
F_102 ( V_4 ) ;
F_100 ( V_4 ) ;
F_68 ( & V_4 -> V_108 , V_107 ) ;
return 0 ;
}
static void F_136 ( struct V_2 * V_4 )
{
struct V_1 * V_42 = F_1 ( V_4 ) ;
unsigned long V_107 ;
F_50 ( V_4 -> V_29 , L_12 , V_146 , V_4 -> line ) ;
F_67 ( & V_4 -> V_108 , V_107 ) ;
F_117 ( V_4 ) ;
F_43 ( V_4 ) ;
F_68 ( & V_4 -> V_108 , V_107 ) ;
F_134 ( V_4 ) ;
F_84 ( V_42 ) ;
}
static unsigned int F_137 ( struct V_1 * V_42 , unsigned int V_208 ,
unsigned long V_209 )
{
if ( V_42 -> V_210 )
return F_138 ( V_209 , V_42 -> V_210 * V_208 ) - 1 ;
F_139 ( 1 ) ;
return ( ( V_209 + 16 * V_208 ) / ( 32 * V_208 ) - 1 ) ;
}
static int F_140 ( unsigned int V_211 )
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
static void F_141 ( unsigned int V_208 , unsigned long V_209 ,
int * V_216 , unsigned int * V_217 ,
unsigned int * V_218 , int V_219 )
{
int V_220 , V_36 , V_221 , V_222 , V_223 ;
int V_224 = 1000 ;
int V_225 = 0 ;
for ( V_220 = 8 ; V_220 <= 32 ; V_220 ++ ) {
for ( V_36 = 0 ; V_36 <= 3 ; V_36 ++ ) {
V_221 = F_138 ( V_209 , ( V_220 *
( 1 << ( 2 * V_36 + 1 ) ) * V_208 ) ) - 1 ;
V_221 = F_142 ( V_221 , 0 , 255 ) ;
V_222 = F_138 ( V_209 , ( ( V_221 + 1 ) * V_208 * V_220 *
( 1 << ( 2 * V_36 + 1 ) ) / 1000 ) ) -
1000 ;
V_223 = abs ( ( 500 -
F_138 ( 1000 , V_220 << 1 ) ) / 10 ) ;
if ( abs ( V_224 ) > abs ( V_222 ) ) {
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
F_139 ( 1 ) ;
* V_216 = 255 ;
* V_217 = 15 ;
* V_218 = 0 ;
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
V_8 = F_4 ( V_4 , V_141 ) ;
if ( V_8 -> V_9 )
F_24 ( V_4 , V_141 , V_226 | V_227 ) ;
}
static void F_144 ( struct V_2 * V_4 , struct V_228 * V_229 ,
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
V_231 = F_145 ( V_4 , V_229 , V_230 , 0 , V_232 ) ;
if ( F_146 ( V_231 && V_4 -> V_31 ) ) {
if ( V_42 -> V_14 -> type == V_26 ) {
int V_219 = F_140 ( V_211 ) ;
F_141 ( V_231 , V_4 -> V_31 , & V_233 , & V_217 ,
& V_218 , V_219 ) ;
} else {
V_233 = F_137 ( V_42 , V_231 , V_4 -> V_31 ) ;
for ( V_218 = 0 ; V_233 >= 256 && V_218 <= 3 ; V_218 ++ )
V_233 >>= 2 ;
}
}
F_13 ( V_42 ) ;
F_143 ( V_4 ) ;
V_211 |= F_22 ( V_4 , V_241 ) & 3 ;
F_147 ( V_4 , V_229 -> V_234 , V_231 ) ;
F_50 ( V_4 -> V_29 , L_30 ,
V_146 , V_211 , V_218 , V_233 , V_42 -> V_14 -> V_109 ) ;
if ( V_233 >= 0 ) {
F_24 ( V_4 , V_241 , ( V_211 & ~ V_242 ) | V_218 ) ;
F_24 ( V_4 , V_243 , V_233 ) ;
V_8 = F_4 ( V_4 , V_244 ) ;
if ( V_8 -> V_9 )
F_24 ( V_4 , V_244 , V_217 | V_245 ) ;
F_148 ( ( 1000000 + ( V_231 - 1 ) ) / V_231 ) ;
} else
F_24 ( V_4 , V_241 , V_211 ) ;
F_32 ( V_4 , V_229 -> V_234 ) ;
V_8 = F_4 ( V_4 , V_141 ) ;
if ( V_8 -> V_9 ) {
unsigned short V_64 = F_22 ( V_4 , V_141 ) ;
if ( V_42 -> V_14 -> V_47 & V_48 ) {
if ( V_229 -> V_234 & V_49 )
V_64 |= V_246 ;
else
V_64 &= ~ V_246 ;
}
V_64 &= ~ ( V_226 | V_227 ) ;
F_24 ( V_4 , V_141 , V_64 ) ;
}
F_24 ( V_4 , V_66 , V_42 -> V_14 -> V_109 ) ;
#ifdef F_64
if ( V_42 -> V_99 ) {
unsigned int V_247 ;
switch ( V_229 -> V_234 & V_235 ) {
case V_248 :
V_247 = 7 ;
break;
case V_249 :
V_247 = 8 ;
break;
case V_236 :
V_247 = 9 ;
break;
default:
V_247 = 10 ;
break;
}
if ( V_229 -> V_234 & V_240 )
V_247 ++ ;
if ( V_229 -> V_234 & V_237 )
V_247 ++ ;
V_42 -> V_104 = F_149 ( ( V_42 -> V_157 * 2 * V_247 * V_250 ) /
( V_231 / 10 ) , 10 ) ;
F_50 ( V_4 -> V_29 , L_31 ,
V_42 -> V_104 * 1000 / V_250 , V_4 -> V_251 ) ;
if ( V_42 -> V_104 < F_150 ( 20 ) )
V_42 -> V_104 = F_150 ( 20 ) ;
}
#endif
if ( ( V_229 -> V_234 & V_252 ) != 0 )
F_100 ( V_4 ) ;
F_17 ( V_42 ) ;
}
static void F_151 ( struct V_2 * V_4 , unsigned int V_62 ,
unsigned int V_253 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
switch ( V_62 ) {
case V_254 :
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
if ( V_4 -> V_107 & V_255 ) {
V_4 -> V_10 = F_155 ( V_4 -> V_256 , V_9 ) ;
if ( F_77 ( ! V_4 -> V_10 ) ) {
F_80 ( V_4 -> V_29 , L_38 , V_4 -> line ) ;
return - V_257 ;
}
} else {
V_4 -> V_10 = ( void V_58 * ) ( V_59 ) V_4 -> V_256 ;
}
return 0 ;
}
static void F_156 ( struct V_2 * V_4 )
{
if ( V_4 -> V_107 & V_255 ) {
F_157 ( V_4 -> V_10 ) ;
V_4 -> V_10 = NULL ;
}
F_158 ( V_4 -> V_256 , F_153 ( V_4 ) ) ;
}
static int F_159 ( struct V_2 * V_4 )
{
unsigned long V_9 = F_153 ( V_4 ) ;
struct V_258 * V_259 ;
int V_115 ;
V_259 = F_160 ( V_4 -> V_256 , V_9 , F_79 ( V_4 -> V_29 ) ) ;
if ( F_77 ( V_259 == NULL ) )
return - V_260 ;
V_115 = F_154 ( V_4 ) ;
if ( F_77 ( V_115 != 0 ) ) {
F_161 ( V_259 ) ;
return V_115 ;
}
return 0 ;
}
static void F_162 ( struct V_2 * V_4 , int V_107 )
{
if ( V_107 & V_261 ) {
struct V_1 * V_262 = F_1 ( V_4 ) ;
V_4 -> type = V_262 -> V_14 -> type ;
F_159 ( V_4 ) ;
}
}
static int F_163 ( struct V_2 * V_4 , struct V_263 * V_264 )
{
if ( V_264 -> V_265 < 2400 )
return - V_28 ;
return 0 ;
}
static int F_164 ( struct V_266 * V_29 ,
struct V_1 * V_1 , unsigned int V_267 ,
struct V_13 * V_5 , bool V_268 )
{
struct V_2 * V_4 = & V_1 -> V_4 ;
const struct V_258 * V_259 ;
unsigned int V_210 ;
unsigned int V_77 ;
int V_115 ;
V_1 -> V_14 = V_5 ;
V_4 -> V_45 = & V_269 ;
V_4 -> V_270 = V_271 ;
V_4 -> line = V_267 ;
V_259 = F_165 ( V_29 , V_272 , 0 ) ;
if ( V_259 == NULL )
return - V_273 ;
V_4 -> V_256 = V_259 -> V_274 ;
for ( V_77 = 0 ; V_77 < F_166 ( V_1 -> V_130 ) ; ++ V_77 )
V_1 -> V_130 [ V_77 ] = F_167 ( V_29 , V_77 ) ;
if ( V_1 -> V_130 [ 0 ] < 0 )
return - V_257 ;
if ( V_1 -> V_130 [ 1 ] < 0 ) {
V_1 -> V_130 [ 1 ] = V_1 -> V_130 [ 0 ] ;
V_1 -> V_130 [ 2 ] = V_1 -> V_130 [ 0 ] ;
V_1 -> V_130 [ 3 ] = V_1 -> V_130 [ 0 ] ;
}
if ( V_5 -> V_16 == V_275 ) {
V_115 = F_11 ( V_5 ) ;
if ( F_77 ( V_115 ) )
return V_115 ;
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
if ( V_5 -> V_16 == V_276 ) {
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
if ( ! V_268 ) {
V_1 -> V_30 = F_168 ( & V_29 -> V_29 , L_39 ) ;
if ( F_169 ( V_1 -> V_30 ) ) {
V_1 -> V_30 = F_168 ( & V_29 -> V_29 , L_40 ) ;
if ( F_169 ( V_1 -> V_30 ) ) {
F_80 ( & V_29 -> V_29 , L_41 ) ;
return F_170 ( V_1 -> V_30 ) ;
}
}
V_1 -> V_32 = F_168 ( & V_29 -> V_29 , L_42 ) ;
if ( F_169 ( V_1 -> V_32 ) )
V_1 -> V_32 = NULL ;
V_4 -> V_29 = & V_29 -> V_29 ;
F_171 ( & V_29 -> V_29 ) ;
}
V_1 -> V_33 . V_89 = ( unsigned long ) V_1 ;
V_1 -> V_33 . V_277 = F_57 ;
F_172 ( & V_1 -> V_33 ) ;
V_1 -> V_278 = ( V_5 -> type == V_15 ) ?
V_279 : V_280 ;
V_1 -> V_278 |= 1 << V_1 -> V_90 ;
V_4 -> type = V_5 -> type ;
V_4 -> V_107 = V_281 | V_5 -> V_107 ;
V_4 -> V_11 = V_5 -> V_11 ;
V_4 -> V_97 = V_1 -> V_130 [ V_198 ] ;
V_4 -> V_135 = 0 ;
V_4 -> V_282 = F_3 ;
V_4 -> V_283 = F_8 ;
if ( V_5 -> V_201 > 0 && V_5 -> V_202 > 0 )
F_50 ( V_4 -> V_29 , L_43 ,
V_5 -> V_201 , V_5 -> V_202 ) ;
return 0 ;
}
static void F_173 ( struct V_1 * V_4 )
{
F_174 ( V_4 -> V_30 ) ;
F_174 ( V_4 -> V_32 ) ;
F_175 ( V_4 -> V_4 . V_29 ) ;
}
static void F_176 ( struct V_2 * V_4 , int V_284 )
{
F_28 ( V_4 , V_284 ) ;
}
static void F_177 ( struct V_285 * V_286 , const char * V_42 ,
unsigned V_65 )
{
struct V_1 * V_1 = & V_287 [ V_286 -> V_267 ] ;
struct V_2 * V_4 = & V_1 -> V_4 ;
unsigned short V_247 , V_64 ;
unsigned long V_107 ;
int V_288 = 1 ;
F_178 ( V_107 ) ;
if ( V_4 -> V_289 )
V_288 = 0 ;
else if ( V_290 )
V_288 = F_179 ( & V_4 -> V_108 ) ;
else
F_180 ( & V_4 -> V_108 ) ;
V_64 = F_22 ( V_4 , V_66 ) ;
F_24 ( V_4 , V_66 , V_1 -> V_14 -> V_109 ) ;
F_181 ( V_4 , V_42 , V_65 , F_176 ) ;
V_247 = F_29 ( V_4 ) | F_31 ( V_4 ) ;
while ( ( F_22 ( V_4 , V_37 ) & V_247 ) != V_247 )
F_182 () ;
F_24 ( V_4 , V_66 , V_64 ) ;
if ( V_288 )
F_183 ( & V_4 -> V_108 ) ;
F_184 ( V_107 ) ;
}
static int F_185 ( struct V_285 * V_286 , char * V_291 )
{
struct V_1 * V_1 ;
struct V_2 * V_4 ;
int V_231 = 115200 ;
int V_247 = 8 ;
int V_85 = 'n' ;
int V_292 = 'n' ;
int V_115 ;
if ( V_286 -> V_267 < 0 || V_286 -> V_267 >= V_293 )
return - V_294 ;
V_1 = & V_287 [ V_286 -> V_267 ] ;
V_4 = & V_1 -> V_4 ;
if ( ! V_4 -> V_45 )
return - V_294 ;
V_115 = F_154 ( V_4 ) ;
if ( F_77 ( V_115 != 0 ) )
return V_115 ;
if ( V_291 )
F_186 ( V_291 , & V_231 , & V_85 , & V_247 , & V_292 ) ;
return F_187 ( V_4 , V_286 , V_231 , V_85 , V_247 , V_292 ) ;
}
static int F_188 ( struct V_266 * V_295 )
{
struct V_13 * V_14 = F_189 ( & V_295 -> V_29 ) ;
if ( V_296 . V_89 )
return - V_297 ;
V_296 . V_267 = V_295 -> V_298 ;
F_164 ( V_295 , & V_287 [ V_295 -> V_298 ] , V_295 -> V_298 , V_14 , true ) ;
F_185 ( & V_296 , V_299 ) ;
if ( ! strstr ( V_299 , L_44 ) )
V_296 . V_107 |= V_300 ;
F_190 ( & V_296 ) ;
return 0 ;
}
static inline int F_188 ( struct V_266 * V_295 )
{
return - V_28 ;
}
static int F_191 ( struct V_266 * V_29 )
{
struct V_1 * V_4 = F_192 ( V_29 ) ;
F_193 ( & V_4 -> V_121 ,
V_301 ) ;
F_194 ( & V_302 , & V_4 -> V_4 ) ;
F_173 ( V_4 ) ;
return 0 ;
}
static struct V_13 *
F_195 ( struct V_266 * V_295 , unsigned int * V_303 )
{
struct V_304 * V_305 = V_295 -> V_29 . V_306 ;
const struct V_307 * V_308 ;
const struct V_309 * V_310 ;
struct V_13 * V_5 ;
int V_298 ;
if ( ! F_196 ( V_311 ) || ! V_305 )
return NULL ;
V_308 = F_197 ( V_312 , V_295 -> V_29 . V_306 ) ;
if ( ! V_308 )
return NULL ;
V_310 = V_308 -> V_89 ;
V_5 = F_198 ( & V_295 -> V_29 , sizeof( struct V_13 ) , V_132 ) ;
if ( ! V_5 ) {
F_80 ( & V_295 -> V_29 , L_45 ) ;
return NULL ;
}
V_298 = F_199 ( V_305 , L_46 ) ;
if ( V_298 < 0 ) {
F_80 ( & V_295 -> V_29 , L_47 , V_298 ) ;
return NULL ;
}
* V_303 = V_298 ;
V_5 -> V_107 = V_255 | V_313 ;
V_5 -> type = V_310 -> type ;
V_5 -> V_16 = V_310 -> V_16 ;
V_5 -> V_109 = V_314 | V_190 ;
return V_5 ;
}
static int F_200 ( struct V_266 * V_29 ,
unsigned int V_267 ,
struct V_13 * V_5 ,
struct V_1 * V_315 )
{
int V_115 ;
if ( F_77 ( V_267 >= V_293 ) ) {
F_52 ( & V_29 -> V_29 , L_48 ,
V_267 + 1 , V_293 ) ;
F_52 ( & V_29 -> V_29 , L_49 ) ;
return - V_28 ;
}
V_115 = F_164 ( V_29 , V_315 , V_267 , V_5 , false ) ;
if ( V_115 )
return V_115 ;
V_115 = F_201 ( & V_302 , & V_315 -> V_4 ) ;
if ( V_115 ) {
F_173 ( V_315 ) ;
return V_115 ;
}
return 0 ;
}
static int F_202 ( struct V_266 * V_29 )
{
struct V_13 * V_5 ;
struct V_1 * V_316 ;
unsigned int V_303 ;
int V_115 ;
if ( F_203 ( V_29 ) )
return F_188 ( V_29 ) ;
if ( V_29 -> V_29 . V_306 ) {
V_5 = F_195 ( V_29 , & V_303 ) ;
if ( V_5 == NULL )
return - V_28 ;
} else {
V_5 = V_29 -> V_29 . V_317 ;
if ( V_5 == NULL ) {
F_80 ( & V_29 -> V_29 , L_50 ) ;
return - V_28 ;
}
V_303 = V_29 -> V_298 ;
}
V_316 = & V_287 [ V_303 ] ;
F_204 ( V_29 , V_316 ) ;
V_115 = F_200 ( V_29 , V_303 , V_5 , V_316 ) ;
if ( V_115 )
return V_115 ;
V_316 -> V_121 . V_318 = F_74 ;
V_115 = F_205 ( & V_316 -> V_121 ,
V_301 ) ;
if ( F_77 ( V_115 < 0 ) ) {
F_194 ( & V_302 , & V_316 -> V_4 ) ;
F_173 ( V_316 ) ;
return V_115 ;
}
#ifdef F_206
F_207 () ;
#endif
return 0 ;
}
static T_6 int F_208 ( struct V_194 * V_29 )
{
struct V_1 * V_262 = F_209 ( V_29 ) ;
if ( V_262 )
F_210 ( & V_302 , & V_262 -> V_4 ) ;
return 0 ;
}
static T_6 int F_211 ( struct V_194 * V_29 )
{
struct V_1 * V_262 = F_209 ( V_29 ) ;
if ( V_262 )
F_212 ( & V_302 , & V_262 -> V_4 ) ;
return 0 ;
}
static int T_7 F_213 ( void )
{
int V_115 ;
F_214 ( L_51 , V_319 ) ;
V_115 = F_215 ( & V_302 ) ;
if ( F_146 ( V_115 == 0 ) ) {
V_115 = F_216 ( & V_320 ) ;
if ( F_77 ( V_115 ) )
F_217 ( & V_302 ) ;
}
return V_115 ;
}
static void T_8 F_218 ( void )
{
F_219 ( & V_320 ) ;
F_217 ( & V_302 ) ;
}
