static long F_1 ( struct V_1 * V_2 )
{
long V_3 ;
int V_4 = 1000 ;
if ( V_2 -> V_5 < 0 )
return 0 ;
if ( F_2 ( V_6 ) > 0 )
V_4 = V_4 / 5 ;
if ( V_2 -> V_5 > V_7 / ( V_8 / V_4 ) )
return V_7 ;
V_3 = V_2 -> V_9 / V_4 ;
V_3 += V_2 -> V_5 * ( V_8 / V_4 ) ;
if ( V_3 > V_7 )
return V_7 ;
return V_3 ;
}
long F_3 ( struct V_1 * V_2 )
{
unsigned long V_10 ;
struct V_1 V_11 ;
if ( F_4 ( V_6 ) )
return 0 ;
F_5 ( & V_11 ) ;
V_11 = F_6 ( * V_2 , V_11 ) ;
V_10 = F_1 ( & V_11 ) ;
if ( V_10 < V_6 -> V_12 )
return V_6 -> V_12 ;
return V_10 ;
}
void F_7 ( struct V_13 * V_14 )
{
F_8 ( & V_14 -> V_15 , V_16 ) ;
V_14 -> V_17 = V_6 ;
V_14 -> V_18 = 0 ;
V_14 -> error = 0 ;
V_14 -> V_19 = NULL ;
V_14 -> V_20 = 0 ;
}
static void F_9 ( struct V_21 * V_22 )
{
F_10 ( V_22 -> V_23 , & V_22 -> V_24 ) ;
F_11 ( V_22 -> V_25 ) ;
}
void F_12 ( struct V_13 * V_14 )
{
struct V_26 * V_27 = V_14 -> V_19 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_14 -> V_20 ; V_28 ++ )
F_9 ( V_14 -> V_29 + V_28 ) ;
while ( V_27 ) {
struct V_21 * V_22 ;
struct V_26 * V_30 ;
V_22 = V_27 -> V_22 ;
do {
V_22 -- ;
F_9 ( V_22 ) ;
} while ( V_22 > V_27 -> V_31 );
V_30 = V_27 ;
V_27 = V_27 -> V_32 ;
F_13 ( ( unsigned long ) V_30 ) ;
}
}
static struct V_21 * F_14 ( struct V_13 * V_27 )
{
struct V_26 * V_19 = V_27 -> V_19 ;
if ( V_27 -> V_20 < V_33 )
return V_27 -> V_29 + V_27 -> V_20 ++ ;
if ( ! V_19 || F_15 ( V_19 ) ) {
struct V_26 * V_34 ;
V_34 = (struct V_26 * ) F_16 ( V_35 ) ;
if ( ! V_34 ) {
V_27 -> error = - V_36 ;
return NULL ;
}
V_34 -> V_22 = V_34 -> V_31 ;
V_34 -> V_32 = V_19 ;
V_27 -> V_19 = V_34 ;
V_19 = V_34 ;
}
return V_19 -> V_22 ++ ;
}
static int F_17 ( T_1 * V_24 , unsigned V_37 , int V_38 , void * V_39 )
{
struct V_13 * V_14 = V_24 -> V_40 ;
F_18 ( V_41 , V_14 -> V_17 ) ;
F_19 () ;
V_14 -> V_18 = 1 ;
return F_20 ( & V_41 , V_37 , V_38 , V_39 ) ;
}
static int F_21 ( T_1 * V_24 , unsigned V_37 , int V_38 , void * V_39 )
{
struct V_21 * V_22 ;
V_22 = F_22 ( V_24 , struct V_21 , V_24 ) ;
if ( V_39 && ! ( ( unsigned long ) V_39 & V_22 -> V_39 ) )
return 0 ;
return F_17 ( V_24 , V_37 , V_38 , V_39 ) ;
}
static void V_16 ( struct V_42 * V_25 , T_2 * V_23 ,
T_3 * V_27 )
{
struct V_13 * V_14 = F_22 ( V_27 , struct V_13 , V_15 ) ;
struct V_21 * V_22 = F_14 ( V_14 ) ;
if ( ! V_22 )
return;
V_22 -> V_25 = F_23 ( V_25 ) ;
V_22 -> V_23 = V_23 ;
V_22 -> V_39 = V_27 -> V_43 ;
F_24 ( & V_22 -> V_24 , F_21 ) ;
V_22 -> V_24 . V_40 = V_14 ;
F_25 ( V_23 , & V_22 -> V_24 ) ;
}
int F_26 ( struct V_13 * V_14 , int V_44 ,
T_4 * V_45 , unsigned long V_3 )
{
int V_46 = - V_47 ;
F_27 ( V_44 ) ;
if ( ! V_14 -> V_18 )
V_46 = F_28 ( V_45 , V_3 , V_48 ) ;
F_29 ( V_49 ) ;
F_30 ( V_14 -> V_18 , 0 ) ;
return V_46 ;
}
int F_31 ( struct V_1 * V_50 , long V_51 , long V_52 )
{
struct V_1 V_53 = { . V_5 = V_51 , . V_9 = V_52 } ;
if ( ! F_32 ( & V_53 ) )
return - V_54 ;
if ( ! V_51 && ! V_52 ) {
V_50 -> V_5 = V_50 -> V_9 = 0 ;
} else {
F_5 ( V_50 ) ;
* V_50 = F_33 ( * V_50 , V_53 ) ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_55 , void T_5 * V_27 ,
int V_56 , int V_10 )
{
struct V_1 V_57 ;
struct V_56 V_58 ;
if ( ! V_27 )
return V_10 ;
if ( V_6 -> V_59 & V_60 )
goto V_61;
if ( ! V_55 -> V_5 && ! V_55 -> V_9 )
return V_10 ;
F_5 ( & V_57 ) ;
V_57 = F_6 ( * V_55 , V_57 ) ;
if ( V_57 . V_5 < 0 )
V_57 . V_5 = V_57 . V_9 = 0 ;
if ( V_56 ) {
if ( sizeof( V_58 ) > sizeof( V_58 . V_5 ) + sizeof( V_58 . V_62 ) )
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_5 = V_57 . V_5 ;
V_58 . V_62 = V_57 . V_9 / V_63 ;
if ( ! F_35 ( V_27 , & V_58 , sizeof( V_58 ) ) )
return V_10 ;
} else if ( ! F_35 ( V_27 , & V_57 , sizeof( V_57 ) ) )
return V_10 ;
V_61:
if ( V_10 == - V_64 )
V_10 = - V_47 ;
return V_10 ;
}
static int F_36 ( unsigned long V_65 , T_6 * V_66 )
{
unsigned long * V_67 ;
unsigned long V_68 ;
int V_69 ;
struct V_70 * V_71 ;
V_68 = ~ ( ~ 0UL << ( V_65 & ( V_72 - 1 ) ) ) ;
V_65 /= V_72 ;
V_71 = F_37 ( V_6 -> V_73 ) ;
V_67 = V_71 -> V_67 + V_65 ;
V_69 = 0 ;
if ( V_68 ) {
V_68 &= F_38 ( V_66 , V_65 ) ;
if ( V_68 ) {
if ( ! ( V_68 & ~ * V_67 ) )
goto V_74;
return - V_75 ;
}
}
while ( V_65 ) {
V_67 -- ;
V_65 -- ;
V_68 = F_38 ( V_66 , V_65 ) ;
if ( ! V_68 )
continue;
if ( V_68 & ~ * V_67 )
return - V_75 ;
if ( V_69 )
continue;
V_74:
do {
V_69 ++ ;
V_68 >>= 1 ;
} while ( V_68 );
V_69 += V_65 * V_72 ;
}
return V_69 ;
}
static inline void F_39 ( T_3 * V_24 , unsigned long V_76 ,
unsigned long V_77 , unsigned long V_78 ,
unsigned int V_79 )
{
V_24 -> V_43 = V_80 | V_79 ;
if ( V_76 & V_78 )
V_24 -> V_43 |= V_81 ;
if ( V_77 & V_78 )
V_24 -> V_43 |= V_82 ;
}
int F_40 ( int V_65 , T_6 * V_66 , struct V_1 * V_55 )
{
T_4 V_83 , * V_50 = NULL ;
struct V_13 V_19 ;
T_3 * V_24 ;
int V_84 , V_28 , V_85 = 0 ;
unsigned long V_3 = 0 ;
unsigned int V_86 = F_41 () ? V_87 : 0 ;
unsigned long V_88 = 0 ;
F_42 () ;
V_84 = F_36 ( V_65 , V_66 ) ;
F_43 () ;
if ( V_84 < 0 )
return V_84 ;
V_65 = V_84 ;
F_7 ( & V_19 ) ;
V_24 = & V_19 . V_15 ;
if ( V_55 && ! V_55 -> V_5 && ! V_55 -> V_9 ) {
V_24 -> V_89 = NULL ;
V_85 = 1 ;
}
if ( V_55 && ! V_85 )
V_3 = F_3 ( V_55 ) ;
V_84 = 0 ;
for (; ; ) {
unsigned long * V_90 , * V_91 , * V_92 , * V_93 , * V_94 , * exp ;
bool V_95 = false ;
V_93 = V_66 -> V_76 ; V_94 = V_66 -> V_77 ; exp = V_66 -> V_96 ;
V_90 = V_66 -> V_97 ; V_91 = V_66 -> V_98 ; V_92 = V_66 -> V_99 ;
for ( V_28 = 0 ; V_28 < V_65 ; ++ V_90 , ++ V_91 , ++ V_92 ) {
unsigned long V_76 , V_77 , V_96 , V_100 , V_78 = 1 , V_101 , V_102 ;
unsigned long V_97 = 0 , V_98 = 0 , V_99 = 0 ;
V_76 = * V_93 ++ ; V_77 = * V_94 ++ ; V_96 = * exp ++ ;
V_100 = V_76 | V_77 | V_96 ;
if ( V_100 == 0 ) {
V_28 += V_72 ;
continue;
}
for ( V_102 = 0 ; V_102 < V_72 ; ++ V_102 , ++ V_28 , V_78 <<= 1 ) {
struct V_103 V_104 ;
if ( V_28 >= V_65 )
break;
if ( ! ( V_78 & V_100 ) )
continue;
V_104 = F_44 ( V_28 ) ;
if ( V_104 . V_42 ) {
const struct V_105 * V_106 ;
V_106 = V_104 . V_42 -> V_106 ;
V_101 = V_107 ;
if ( V_106 -> V_108 ) {
F_39 ( V_24 , V_76 , V_77 ,
V_78 , V_86 ) ;
V_101 = (* V_106 -> V_108 )( V_104 . V_42 , V_24 ) ;
}
F_45 ( V_104 ) ;
if ( ( V_101 & V_81 ) && ( V_76 & V_78 ) ) {
V_97 |= V_78 ;
V_84 ++ ;
V_24 -> V_89 = NULL ;
}
if ( ( V_101 & V_82 ) && ( V_77 & V_78 ) ) {
V_98 |= V_78 ;
V_84 ++ ;
V_24 -> V_89 = NULL ;
}
if ( ( V_101 & V_80 ) && ( V_96 & V_78 ) ) {
V_99 |= V_78 ;
V_84 ++ ;
V_24 -> V_89 = NULL ;
}
if ( V_84 ) {
V_95 = false ;
V_86 = 0 ;
} else if ( V_86 & V_101 )
V_95 = true ;
}
}
if ( V_97 )
* V_90 = V_97 ;
if ( V_98 )
* V_91 = V_98 ;
if ( V_99 )
* V_92 = V_99 ;
F_46 () ;
}
V_24 -> V_89 = NULL ;
if ( V_84 || V_85 || F_47 ( V_6 ) )
break;
if ( V_19 . error ) {
V_84 = V_19 . error ;
break;
}
if ( V_95 && ! F_48 () ) {
if ( ! V_88 ) {
V_88 = F_49 () ;
continue;
}
if ( ! F_50 ( V_88 ) )
continue;
}
V_86 = 0 ;
if ( V_55 && ! V_50 ) {
V_83 = F_51 ( * V_55 ) ;
V_50 = & V_83 ;
}
if ( ! F_26 ( & V_19 , V_109 ,
V_50 , V_3 ) )
V_85 = 1 ;
}
F_12 ( & V_19 ) ;
return V_84 ;
}
int F_52 ( int V_65 , T_7 T_5 * V_93 , T_7 T_5 * V_94 ,
T_7 T_5 * exp , struct V_1 * V_55 )
{
T_6 V_66 ;
void * V_110 ;
int V_10 , V_111 ;
unsigned int V_112 ;
struct V_70 * V_71 ;
long V_113 [ V_114 / sizeof( long ) ] ;
V_10 = - V_54 ;
if ( V_65 < 0 )
goto V_115;
F_42 () ;
V_71 = F_37 ( V_6 -> V_73 ) ;
V_111 = V_71 -> V_111 ;
F_43 () ;
if ( V_65 > V_111 )
V_65 = V_111 ;
V_112 = F_53 ( V_65 ) ;
V_110 = V_113 ;
if ( V_112 > sizeof( V_113 ) / 6 ) {
V_10 = - V_36 ;
V_110 = F_54 ( 6 * V_112 , V_35 ) ;
if ( ! V_110 )
goto V_115;
}
V_66 . V_76 = V_110 ;
V_66 . V_77 = V_110 + V_112 ;
V_66 . V_96 = V_110 + 2 * V_112 ;
V_66 . V_97 = V_110 + 3 * V_112 ;
V_66 . V_98 = V_110 + 4 * V_112 ;
V_66 . V_99 = V_110 + 5 * V_112 ;
if ( ( V_10 = F_55 ( V_65 , V_93 , V_66 . V_76 ) ) ||
( V_10 = F_55 ( V_65 , V_94 , V_66 . V_77 ) ) ||
( V_10 = F_55 ( V_65 , exp , V_66 . V_96 ) ) )
goto V_77;
F_56 ( V_65 , V_66 . V_97 ) ;
F_56 ( V_65 , V_66 . V_98 ) ;
F_56 ( V_65 , V_66 . V_99 ) ;
V_10 = F_40 ( V_65 , & V_66 , V_55 ) ;
if ( V_10 < 0 )
goto V_77;
if ( ! V_10 ) {
V_10 = - V_64 ;
if ( F_47 ( V_6 ) )
goto V_77;
V_10 = 0 ;
}
if ( F_57 ( V_65 , V_93 , V_66 . V_97 ) ||
F_57 ( V_65 , V_94 , V_66 . V_98 ) ||
F_57 ( V_65 , exp , V_66 . V_99 ) )
V_10 = - V_116 ;
V_77:
if ( V_110 != V_113 )
F_58 ( V_110 ) ;
V_115:
return V_10 ;
}
static long F_59 ( int V_65 , T_7 T_5 * V_93 , T_7 T_5 * V_94 ,
T_7 T_5 * exp , struct V_1 T_5 * V_117 ,
const T_8 T_5 * V_118 , T_9 V_119 )
{
T_8 V_120 , V_121 ;
struct V_1 V_53 , V_55 , * V_50 = NULL ;
int V_10 ;
if ( V_117 ) {
if ( F_60 ( & V_53 , V_117 , sizeof( V_53 ) ) )
return - V_116 ;
V_50 = & V_55 ;
if ( F_31 ( V_50 , V_53 . V_5 , V_53 . V_9 ) )
return - V_54 ;
}
if ( V_118 ) {
if ( V_119 != sizeof( T_8 ) )
return - V_54 ;
if ( F_60 ( & V_120 , V_118 , sizeof( V_120 ) ) )
return - V_116 ;
F_61 ( & V_120 , V_118 ( V_122 ) | V_118 ( V_123 ) ) ;
F_62 ( V_124 , & V_120 , & V_121 ) ;
}
V_10 = F_52 ( V_65 , V_93 , V_94 , exp , V_50 ) ;
V_10 = F_34 ( & V_55 , V_117 , 0 , V_10 ) ;
if ( V_10 == - V_64 ) {
if ( V_118 ) {
memcpy ( & V_6 -> V_125 , & V_121 ,
sizeof( V_121 ) ) ;
F_63 () ;
}
} else if ( V_118 )
F_62 ( V_124 , & V_121 , NULL ) ;
return V_10 ;
}
static inline unsigned int F_64 ( struct V_126 * V_126 , T_3 * V_127 ,
bool * V_128 ,
unsigned int V_86 )
{
unsigned int V_101 ;
int V_103 ;
V_101 = 0 ;
V_103 = V_126 -> V_103 ;
if ( V_103 >= 0 ) {
struct V_103 V_104 = F_44 ( V_103 ) ;
V_101 = V_129 ;
if ( V_104 . V_42 ) {
V_101 = V_107 ;
if ( V_104 . V_42 -> V_106 -> V_108 ) {
V_127 -> V_43 = V_126 -> V_130 | V_131 | V_132 ;
V_127 -> V_43 |= V_86 ;
V_101 = V_104 . V_42 -> V_106 -> V_108 ( V_104 . V_42 , V_127 ) ;
if ( V_101 & V_86 )
* V_128 = true ;
}
V_101 &= V_126 -> V_130 | V_131 | V_132 ;
F_45 ( V_104 ) ;
}
}
V_126 -> V_133 = V_101 ;
return V_101 ;
}
static int F_65 ( struct V_134 * V_135 , struct V_13 * V_24 ,
struct V_1 * V_55 )
{
T_3 * V_15 = & V_24 -> V_15 ;
T_4 V_83 , * V_50 = NULL ;
int V_85 = 0 , V_136 = 0 ;
unsigned long V_3 = 0 ;
unsigned int V_86 = F_41 () ? V_87 : 0 ;
unsigned long V_88 = 0 ;
if ( V_55 && ! V_55 -> V_5 && ! V_55 -> V_9 ) {
V_15 -> V_89 = NULL ;
V_85 = 1 ;
}
if ( V_55 && ! V_85 )
V_3 = F_3 ( V_55 ) ;
for (; ; ) {
struct V_134 * V_137 ;
bool V_95 = false ;
for ( V_137 = V_135 ; V_137 != NULL ; V_137 = V_137 -> V_32 ) {
struct V_126 * V_138 , * V_139 ;
V_138 = V_137 -> V_31 ;
V_139 = V_138 + V_137 -> V_140 ;
for (; V_138 != V_139 ; V_138 ++ ) {
if ( F_64 ( V_138 , V_15 , & V_95 ,
V_86 ) ) {
V_136 ++ ;
V_15 -> V_89 = NULL ;
V_86 = 0 ;
V_95 = false ;
}
}
}
V_15 -> V_89 = NULL ;
if ( ! V_136 ) {
V_136 = V_24 -> error ;
if ( F_47 ( V_6 ) )
V_136 = - V_47 ;
}
if ( V_136 || V_85 )
break;
if ( V_95 && ! F_48 () ) {
if ( ! V_88 ) {
V_88 = F_49 () ;
continue;
}
if ( ! F_50 ( V_88 ) )
continue;
}
V_86 = 0 ;
if ( V_55 && ! V_50 ) {
V_83 = F_51 ( * V_55 ) ;
V_50 = & V_83 ;
}
if ( ! F_26 ( V_24 , V_109 , V_50 , V_3 ) )
V_85 = 1 ;
}
return V_136 ;
}
int F_66 ( struct V_126 T_5 * V_141 , unsigned int V_142 ,
struct V_1 * V_55 )
{
struct V_13 V_19 ;
int V_143 = - V_116 , V_144 , V_140 , V_112 ;
long V_145 [ V_146 / sizeof( long ) ] ;
struct V_134 * const V_147 = (struct V_134 * ) V_145 ;
struct V_134 * V_137 = V_147 ;
unsigned long V_148 = V_142 ;
if ( V_142 > F_67 ( V_149 ) )
return - V_54 ;
V_140 = F_68 (unsigned int, nfds, N_STACK_PPS) ;
for (; ; ) {
V_137 -> V_32 = NULL ;
V_137 -> V_140 = V_140 ;
if ( ! V_140 )
break;
if ( F_60 ( V_137 -> V_31 , V_141 + V_142 - V_148 ,
sizeof( struct V_126 ) * V_137 -> V_140 ) )
goto V_150;
V_148 -= V_137 -> V_140 ;
if ( ! V_148 )
break;
V_140 = F_69 ( V_148 , V_151 ) ;
V_112 = sizeof( struct V_134 ) + sizeof( struct V_126 ) * V_140 ;
V_137 = V_137 -> V_32 = F_54 ( V_112 , V_35 ) ;
if ( ! V_137 ) {
V_143 = - V_36 ;
goto V_150;
}
}
F_7 ( & V_19 ) ;
V_144 = F_65 ( V_147 , & V_19 , V_55 ) ;
F_12 ( & V_19 ) ;
for ( V_137 = V_147 ; V_137 ; V_137 = V_137 -> V_32 ) {
struct V_126 * V_66 = V_137 -> V_31 ;
int V_102 ;
for ( V_102 = 0 ; V_102 < V_137 -> V_140 ; V_102 ++ , V_141 ++ )
if ( F_70 ( V_66 [ V_102 ] . V_133 , & V_141 -> V_133 ) )
goto V_150;
}
V_143 = V_144 ;
V_150:
V_137 = V_147 -> V_32 ;
while ( V_137 ) {
struct V_134 * V_152 = V_137 ;
V_137 = V_137 -> V_32 ;
F_58 ( V_152 ) ;
}
return V_143 ;
}
static long F_71 ( struct V_153 * V_153 )
{
struct V_126 T_5 * V_141 = V_153 -> V_108 . V_141 ;
int V_142 = V_153 -> V_108 . V_142 ;
struct V_1 * V_50 = NULL , V_55 ;
int V_10 ;
if ( V_153 -> V_108 . V_154 ) {
V_55 . V_5 = V_153 -> V_108 . V_5 ;
V_55 . V_9 = V_153 -> V_108 . V_9 ;
V_50 = & V_55 ;
}
V_10 = F_66 ( V_141 , V_142 , V_50 ) ;
if ( V_10 == - V_47 ) {
V_153 -> V_155 = F_71 ;
V_10 = - V_156 ;
}
return V_10 ;
}
