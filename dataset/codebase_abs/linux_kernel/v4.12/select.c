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
T_1 F_3 ( struct V_1 * V_2 )
{
T_1 V_10 ;
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
static int F_17 ( T_2 * V_24 , unsigned V_37 , int V_38 , void * V_39 )
{
struct V_13 * V_14 = V_24 -> V_40 ;
F_18 ( V_41 , V_14 -> V_17 ) ;
F_19 () ;
V_14 -> V_18 = 1 ;
return F_20 ( & V_41 , V_37 , V_38 , V_39 ) ;
}
static int F_21 ( T_2 * V_24 , unsigned V_37 , int V_38 , void * V_39 )
{
struct V_21 * V_22 ;
V_22 = F_22 ( V_24 , struct V_21 , V_24 ) ;
if ( V_39 && ! ( ( unsigned long ) V_39 & V_22 -> V_39 ) )
return 0 ;
return F_17 ( V_24 , V_37 , V_38 , V_39 ) ;
}
static void V_16 ( struct V_42 * V_25 , T_3 * V_23 ,
T_4 * V_27 )
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
T_5 * V_45 , unsigned long V_3 )
{
int V_46 = - V_47 ;
F_27 ( V_44 ) ;
if ( ! V_14 -> V_18 )
V_46 = F_28 ( V_45 , V_3 , V_48 ) ;
F_29 ( V_49 ) ;
F_30 ( V_14 -> V_18 , 0 ) ;
return V_46 ;
}
int F_31 ( struct V_1 * V_50 , T_6 V_51 , long V_52 )
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
static int F_34 ( struct V_1 * V_55 ,
void T_7 * V_27 ,
int V_56 , int V_10 )
{
struct V_1 V_57 ;
struct V_58 V_59 ;
struct V_56 V_60 ;
if ( ! V_27 )
return V_10 ;
if ( V_6 -> V_61 & V_62 )
goto V_63;
if ( ! V_55 -> V_5 && ! V_55 -> V_9 )
return V_10 ;
F_5 ( & V_57 ) ;
V_57 = F_6 ( * V_55 , V_57 ) ;
if ( V_57 . V_5 < 0 )
V_57 . V_5 = V_57 . V_9 = 0 ;
V_59 = F_35 ( V_57 ) ;
if ( V_56 ) {
if ( sizeof( V_60 ) > sizeof( V_60 . V_5 ) + sizeof( V_60 . V_64 ) )
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
V_60 . V_5 = V_57 . V_5 ;
V_60 . V_64 = V_57 . V_9 / V_65 ;
if ( ! F_36 ( V_27 , & V_60 , sizeof( V_60 ) ) )
return V_10 ;
} else if ( ! F_36 ( V_27 , & V_59 , sizeof( V_59 ) ) )
return V_10 ;
V_63:
if ( V_10 == - V_66 )
V_10 = - V_47 ;
return V_10 ;
}
static inline
int F_37 ( unsigned long V_67 , void T_7 * V_68 , unsigned long * V_69 )
{
V_67 = F_38 ( V_67 ) ;
if ( V_68 )
return F_39 ( V_69 , V_68 , V_67 ) ? - V_70 : 0 ;
memset ( V_69 , 0 , V_67 ) ;
return 0 ;
}
static inline unsigned long T_8
F_40 ( unsigned long V_67 , void T_7 * V_68 , unsigned long * V_69 )
{
if ( V_68 )
return F_41 ( V_68 , V_69 , F_38 ( V_67 ) ) ;
return 0 ;
}
static inline
void F_42 ( unsigned long V_67 , unsigned long * V_69 )
{
memset ( V_69 , 0 , F_38 ( V_67 ) ) ;
}
static int F_43 ( unsigned long V_71 , T_9 * V_72 )
{
unsigned long * V_73 ;
unsigned long V_74 ;
int V_75 ;
struct V_76 * V_77 ;
V_74 = ~ ( ~ 0UL << ( V_71 & ( V_78 - 1 ) ) ) ;
V_71 /= V_78 ;
V_77 = F_44 ( V_6 -> V_79 ) ;
V_73 = V_77 -> V_73 + V_71 ;
V_75 = 0 ;
if ( V_74 ) {
V_74 &= F_45 ( V_72 , V_71 ) ;
if ( V_74 ) {
if ( ! ( V_74 & ~ * V_73 ) )
goto V_80;
return - V_81 ;
}
}
while ( V_71 ) {
V_73 -- ;
V_71 -- ;
V_74 = F_45 ( V_72 , V_71 ) ;
if ( ! V_74 )
continue;
if ( V_74 & ~ * V_73 )
return - V_81 ;
if ( V_75 )
continue;
V_80:
do {
V_75 ++ ;
V_74 >>= 1 ;
} while ( V_74 );
V_75 += V_71 * V_78 ;
}
return V_75 ;
}
static inline void F_46 ( T_4 * V_24 , unsigned long V_82 ,
unsigned long V_83 , unsigned long V_84 ,
unsigned int V_85 )
{
V_24 -> V_43 = V_86 | V_85 ;
if ( V_82 & V_84 )
V_24 -> V_43 |= V_87 ;
if ( V_83 & V_84 )
V_24 -> V_43 |= V_88 ;
}
static int F_47 ( int V_71 , T_9 * V_72 , struct V_1 * V_55 )
{
T_5 V_89 , * V_50 = NULL ;
struct V_13 V_19 ;
T_4 * V_24 ;
int V_90 , V_28 , V_91 = 0 ;
T_1 V_3 = 0 ;
unsigned int V_92 = F_48 () ? V_93 : 0 ;
unsigned long V_94 = 0 ;
F_49 () ;
V_90 = F_43 ( V_71 , V_72 ) ;
F_50 () ;
if ( V_90 < 0 )
return V_90 ;
V_71 = V_90 ;
F_7 ( & V_19 ) ;
V_24 = & V_19 . V_15 ;
if ( V_55 && ! V_55 -> V_5 && ! V_55 -> V_9 ) {
V_24 -> V_95 = NULL ;
V_91 = 1 ;
}
if ( V_55 && ! V_91 )
V_3 = F_3 ( V_55 ) ;
V_90 = 0 ;
for (; ; ) {
unsigned long * V_96 , * V_97 , * V_98 , * V_99 , * V_100 , * exp ;
bool V_101 = false ;
V_99 = V_72 -> V_82 ; V_100 = V_72 -> V_83 ; exp = V_72 -> V_102 ;
V_96 = V_72 -> V_103 ; V_97 = V_72 -> V_104 ; V_98 = V_72 -> V_105 ;
for ( V_28 = 0 ; V_28 < V_71 ; ++ V_96 , ++ V_97 , ++ V_98 ) {
unsigned long V_82 , V_83 , V_102 , V_106 , V_84 = 1 , V_107 , V_108 ;
unsigned long V_103 = 0 , V_104 = 0 , V_105 = 0 ;
V_82 = * V_99 ++ ; V_83 = * V_100 ++ ; V_102 = * exp ++ ;
V_106 = V_82 | V_83 | V_102 ;
if ( V_106 == 0 ) {
V_28 += V_78 ;
continue;
}
for ( V_108 = 0 ; V_108 < V_78 ; ++ V_108 , ++ V_28 , V_84 <<= 1 ) {
struct V_109 V_110 ;
if ( V_28 >= V_71 )
break;
if ( ! ( V_84 & V_106 ) )
continue;
V_110 = F_51 ( V_28 ) ;
if ( V_110 . V_42 ) {
const struct V_111 * V_112 ;
V_112 = V_110 . V_42 -> V_112 ;
V_107 = V_113 ;
if ( V_112 -> V_114 ) {
F_46 ( V_24 , V_82 , V_83 ,
V_84 , V_92 ) ;
V_107 = (* V_112 -> V_114 )( V_110 . V_42 , V_24 ) ;
}
F_52 ( V_110 ) ;
if ( ( V_107 & V_87 ) && ( V_82 & V_84 ) ) {
V_103 |= V_84 ;
V_90 ++ ;
V_24 -> V_95 = NULL ;
}
if ( ( V_107 & V_88 ) && ( V_83 & V_84 ) ) {
V_104 |= V_84 ;
V_90 ++ ;
V_24 -> V_95 = NULL ;
}
if ( ( V_107 & V_86 ) && ( V_102 & V_84 ) ) {
V_105 |= V_84 ;
V_90 ++ ;
V_24 -> V_95 = NULL ;
}
if ( V_90 ) {
V_101 = false ;
V_92 = 0 ;
} else if ( V_92 & V_107 )
V_101 = true ;
}
}
if ( V_103 )
* V_96 = V_103 ;
if ( V_104 )
* V_97 = V_104 ;
if ( V_105 )
* V_98 = V_105 ;
F_53 () ;
}
V_24 -> V_95 = NULL ;
if ( V_90 || V_91 || F_54 ( V_6 ) )
break;
if ( V_19 . error ) {
V_90 = V_19 . error ;
break;
}
if ( V_101 && ! F_55 () ) {
if ( ! V_94 ) {
V_94 = F_56 () ;
continue;
}
if ( ! F_57 ( V_94 ) )
continue;
}
V_92 = 0 ;
if ( V_55 && ! V_50 ) {
V_89 = F_58 ( * V_55 ) ;
V_50 = & V_89 ;
}
if ( ! F_26 ( & V_19 , V_115 ,
V_50 , V_3 ) )
V_91 = 1 ;
}
F_12 ( & V_19 ) ;
return V_90 ;
}
int F_59 ( int V_71 , T_10 T_7 * V_99 , T_10 T_7 * V_100 ,
T_10 T_7 * exp , struct V_1 * V_55 )
{
T_9 V_72 ;
void * V_116 ;
int V_10 , V_117 ;
T_11 V_118 , V_119 ;
struct V_76 * V_77 ;
long V_120 [ V_121 / sizeof( long ) ] ;
V_10 = - V_54 ;
if ( V_71 < 0 )
goto V_122;
F_49 () ;
V_77 = F_44 ( V_6 -> V_79 ) ;
V_117 = V_77 -> V_117 ;
F_50 () ;
if ( V_71 > V_117 )
V_71 = V_117 ;
V_118 = F_38 ( V_71 ) ;
V_116 = V_120 ;
if ( V_118 > sizeof( V_120 ) / 6 ) {
V_10 = - V_36 ;
if ( V_118 > ( V_123 / 6 ) )
goto V_122;
V_119 = 6 * V_118 ;
V_116 = F_60 ( V_119 , V_35 ) ;
if ( ! V_116 )
goto V_122;
}
V_72 . V_82 = V_116 ;
V_72 . V_83 = V_116 + V_118 ;
V_72 . V_102 = V_116 + 2 * V_118 ;
V_72 . V_103 = V_116 + 3 * V_118 ;
V_72 . V_104 = V_116 + 4 * V_118 ;
V_72 . V_105 = V_116 + 5 * V_118 ;
if ( ( V_10 = F_37 ( V_71 , V_99 , V_72 . V_82 ) ) ||
( V_10 = F_37 ( V_71 , V_100 , V_72 . V_83 ) ) ||
( V_10 = F_37 ( V_71 , exp , V_72 . V_102 ) ) )
goto V_83;
F_42 ( V_71 , V_72 . V_103 ) ;
F_42 ( V_71 , V_72 . V_104 ) ;
F_42 ( V_71 , V_72 . V_105 ) ;
V_10 = F_47 ( V_71 , & V_72 , V_55 ) ;
if ( V_10 < 0 )
goto V_83;
if ( ! V_10 ) {
V_10 = - V_66 ;
if ( F_54 ( V_6 ) )
goto V_83;
V_10 = 0 ;
}
if ( F_40 ( V_71 , V_99 , V_72 . V_103 ) ||
F_40 ( V_71 , V_100 , V_72 . V_104 ) ||
F_40 ( V_71 , exp , V_72 . V_105 ) )
V_10 = - V_70 ;
V_83:
if ( V_116 != V_120 )
F_61 ( V_116 ) ;
V_122:
return V_10 ;
}
static long F_62 ( int V_71 , T_10 T_7 * V_99 , T_10 T_7 * V_100 ,
T_10 T_7 * exp , struct V_58 T_7 * V_124 ,
const T_12 T_7 * V_125 , T_11 V_126 )
{
T_12 V_127 , V_128 ;
struct V_58 V_53 ;
struct V_1 V_129 , V_55 , * V_50 = NULL ;
int V_10 ;
if ( V_124 ) {
if ( F_39 ( & V_53 , V_124 , sizeof( V_53 ) ) )
return - V_70 ;
V_129 = F_63 ( V_53 ) ;
V_50 = & V_55 ;
if ( F_31 ( V_50 , V_129 . V_5 , V_129 . V_9 ) )
return - V_54 ;
}
if ( V_125 ) {
if ( V_126 != sizeof( T_12 ) )
return - V_54 ;
if ( F_39 ( & V_127 , V_125 , sizeof( V_127 ) ) )
return - V_70 ;
F_64 ( & V_127 , V_125 ( V_130 ) | V_125 ( V_131 ) ) ;
F_65 ( V_132 , & V_127 , & V_128 ) ;
}
V_10 = F_59 ( V_71 , V_99 , V_100 , exp , V_50 ) ;
V_10 = F_34 ( & V_55 , V_124 , 0 , V_10 ) ;
if ( V_10 == - V_66 ) {
if ( V_125 ) {
memcpy ( & V_6 -> V_133 , & V_128 ,
sizeof( V_128 ) ) ;
F_66 () ;
}
} else if ( V_125 )
F_65 ( V_132 , & V_128 , NULL ) ;
return V_10 ;
}
static inline unsigned int F_67 ( struct V_134 * V_134 , T_4 * V_135 ,
bool * V_136 ,
unsigned int V_92 )
{
unsigned int V_107 ;
int V_109 ;
V_107 = 0 ;
V_109 = V_134 -> V_109 ;
if ( V_109 >= 0 ) {
struct V_109 V_110 = F_51 ( V_109 ) ;
V_107 = V_137 ;
if ( V_110 . V_42 ) {
V_107 = V_113 ;
if ( V_110 . V_42 -> V_112 -> V_114 ) {
V_135 -> V_43 = V_134 -> V_138 | V_139 | V_140 ;
V_135 -> V_43 |= V_92 ;
V_107 = V_110 . V_42 -> V_112 -> V_114 ( V_110 . V_42 , V_135 ) ;
if ( V_107 & V_92 )
* V_136 = true ;
}
V_107 &= V_134 -> V_138 | V_139 | V_140 ;
F_52 ( V_110 ) ;
}
}
V_134 -> V_141 = V_107 ;
return V_107 ;
}
static int F_68 ( struct V_142 * V_143 , struct V_13 * V_24 ,
struct V_1 * V_55 )
{
T_4 * V_15 = & V_24 -> V_15 ;
T_5 V_89 , * V_50 = NULL ;
int V_91 = 0 , V_144 = 0 ;
T_1 V_3 = 0 ;
unsigned int V_92 = F_48 () ? V_93 : 0 ;
unsigned long V_94 = 0 ;
if ( V_55 && ! V_55 -> V_5 && ! V_55 -> V_9 ) {
V_15 -> V_95 = NULL ;
V_91 = 1 ;
}
if ( V_55 && ! V_91 )
V_3 = F_3 ( V_55 ) ;
for (; ; ) {
struct V_142 * V_145 ;
bool V_101 = false ;
for ( V_145 = V_143 ; V_145 != NULL ; V_145 = V_145 -> V_32 ) {
struct V_134 * V_146 , * V_147 ;
V_146 = V_145 -> V_31 ;
V_147 = V_146 + V_145 -> V_148 ;
for (; V_146 != V_147 ; V_146 ++ ) {
if ( F_67 ( V_146 , V_15 , & V_101 ,
V_92 ) ) {
V_144 ++ ;
V_15 -> V_95 = NULL ;
V_92 = 0 ;
V_101 = false ;
}
}
}
V_15 -> V_95 = NULL ;
if ( ! V_144 ) {
V_144 = V_24 -> error ;
if ( F_54 ( V_6 ) )
V_144 = - V_47 ;
}
if ( V_144 || V_91 )
break;
if ( V_101 && ! F_55 () ) {
if ( ! V_94 ) {
V_94 = F_56 () ;
continue;
}
if ( ! F_57 ( V_94 ) )
continue;
}
V_92 = 0 ;
if ( V_55 && ! V_50 ) {
V_89 = F_58 ( * V_55 ) ;
V_50 = & V_89 ;
}
if ( ! F_26 ( V_24 , V_115 , V_50 , V_3 ) )
V_91 = 1 ;
}
return V_144 ;
}
static int F_69 ( struct V_134 T_7 * V_149 , unsigned int V_150 ,
struct V_1 * V_55 )
{
struct V_13 V_19 ;
int V_151 = - V_70 , V_152 , V_148 , V_118 ;
long V_153 [ V_154 / sizeof( long ) ] ;
struct V_142 * const V_155 = (struct V_142 * ) V_153 ;
struct V_142 * V_145 = V_155 ;
unsigned long V_156 = V_150 ;
if ( V_150 > F_70 ( V_157 ) )
return - V_54 ;
V_148 = F_71 (unsigned int, nfds, N_STACK_PPS) ;
for (; ; ) {
V_145 -> V_32 = NULL ;
V_145 -> V_148 = V_148 ;
if ( ! V_148 )
break;
if ( F_39 ( V_145 -> V_31 , V_149 + V_150 - V_156 ,
sizeof( struct V_134 ) * V_145 -> V_148 ) )
goto V_158;
V_156 -= V_145 -> V_148 ;
if ( ! V_156 )
break;
V_148 = F_72 ( V_156 , V_159 ) ;
V_118 = sizeof( struct V_142 ) + sizeof( struct V_134 ) * V_148 ;
V_145 = V_145 -> V_32 = F_73 ( V_118 , V_35 ) ;
if ( ! V_145 ) {
V_151 = - V_36 ;
goto V_158;
}
}
F_7 ( & V_19 ) ;
V_152 = F_68 ( V_155 , & V_19 , V_55 ) ;
F_12 ( & V_19 ) ;
for ( V_145 = V_155 ; V_145 ; V_145 = V_145 -> V_32 ) {
struct V_134 * V_72 = V_145 -> V_31 ;
int V_108 ;
for ( V_108 = 0 ; V_108 < V_145 -> V_148 ; V_108 ++ , V_149 ++ )
if ( F_74 ( V_72 [ V_108 ] . V_141 , & V_149 -> V_141 ) )
goto V_158;
}
V_151 = V_152 ;
V_158:
V_145 = V_155 -> V_32 ;
while ( V_145 ) {
struct V_142 * V_160 = V_145 ;
V_145 = V_145 -> V_32 ;
F_75 ( V_160 ) ;
}
return V_151 ;
}
static long F_76 ( struct V_161 * V_161 )
{
struct V_134 T_7 * V_149 = V_161 -> V_114 . V_149 ;
int V_150 = V_161 -> V_114 . V_150 ;
struct V_1 * V_50 = NULL , V_55 ;
int V_10 ;
if ( V_161 -> V_114 . V_162 ) {
V_55 . V_5 = V_161 -> V_114 . V_5 ;
V_55 . V_9 = V_161 -> V_114 . V_9 ;
V_50 = & V_55 ;
}
V_10 = F_69 ( V_149 , V_150 , V_50 ) ;
if ( V_10 == - V_47 ) {
V_161 -> V_163 = F_76 ;
V_10 = - V_164 ;
}
return V_10 ;
}
static
int F_77 ( struct V_58 * V_55 , void T_7 * V_27 ,
int V_56 , int V_10 )
{
struct V_58 V_53 ;
if ( ! V_27 )
return V_10 ;
if ( V_6 -> V_61 & V_62 )
goto V_63;
if ( ! V_55 -> V_5 && ! V_55 -> V_9 )
return V_10 ;
F_78 ( & V_53 ) ;
V_53 = F_79 ( * V_55 , V_53 ) ;
if ( V_53 . V_5 < 0 )
V_53 . V_5 = V_53 . V_9 = 0 ;
if ( V_56 ) {
struct V_165 V_60 ;
V_60 . V_5 = V_53 . V_5 ;
V_60 . V_64 = V_53 . V_9 / V_65 ;
if ( ! F_36 ( V_27 , & V_60 , sizeof( V_60 ) ) )
return V_10 ;
} else {
struct V_166 V_59 ;
V_59 . V_5 = V_53 . V_5 ;
V_59 . V_9 = V_53 . V_9 ;
if ( ! F_36 ( V_27 , & V_59 , sizeof( V_59 ) ) )
return V_10 ;
}
V_63:
if ( V_10 == - V_66 )
V_10 = - V_47 ;
return V_10 ;
}
static
int F_80 ( unsigned long V_67 , T_13 T_7 * V_68 ,
unsigned long * V_69 )
{
V_67 = F_81 ( V_67 , V_167 ) ;
if ( V_68 ) {
unsigned long V_168 ;
if ( ! F_82 ( V_169 , V_68 , V_67 * sizeof( T_13 ) ) )
return - V_70 ;
V_168 = V_67 & 1UL ;
V_67 &= ~ 1UL ;
while ( V_67 ) {
unsigned long V_170 , V_171 ;
if ( F_83 ( V_171 , V_68 ) || F_83 ( V_170 , V_68 + 1 ) )
return - V_70 ;
V_68 += 2 ;
* V_69 ++ = V_170 << 32 | V_171 ;
V_67 -= 2 ;
}
if ( V_168 && F_83 ( * V_69 , V_68 ) )
return - V_70 ;
} else {
memset ( V_69 , 0 , ( ( V_67 + 1 ) & ~ 1 ) * sizeof( T_13 ) ) ;
}
return 0 ;
}
static
int F_84 ( unsigned long V_67 , T_13 T_7 * V_68 ,
unsigned long * V_69 )
{
unsigned long V_168 ;
V_67 = F_81 ( V_67 , V_167 ) ;
if ( ! V_68 )
return 0 ;
V_168 = V_67 & 1UL ;
V_67 &= ~ 1UL ;
while ( V_67 ) {
unsigned long V_170 , V_171 ;
V_171 = * V_69 ++ ;
V_170 = V_171 >> 32 ;
if ( F_74 ( V_171 , V_68 ) || F_74 ( V_170 , V_68 + 1 ) )
return - V_70 ;
V_68 += 2 ;
V_67 -= 2 ;
}
if ( V_168 && F_74 ( * V_69 , V_68 ) )
return - V_70 ;
return 0 ;
}
static int F_85 ( int V_71 , T_13 T_7 * V_99 ,
T_13 T_7 * V_100 , T_13 T_7 * exp ,
struct V_58 * V_55 )
{
T_9 V_72 ;
void * V_116 ;
int V_118 , V_117 , V_10 = - V_54 ;
struct V_76 * V_77 ;
long V_120 [ V_121 / sizeof( long ) ] ;
if ( V_71 < 0 )
goto V_122;
F_49 () ;
V_77 = F_44 ( V_6 -> V_79 ) ;
V_117 = V_77 -> V_117 ;
F_50 () ;
if ( V_71 > V_117 )
V_71 = V_117 ;
V_118 = F_38 ( V_71 ) ;
V_116 = V_120 ;
if ( V_118 > sizeof( V_120 ) / 6 ) {
V_116 = F_73 ( 6 * V_118 , V_35 ) ;
V_10 = - V_36 ;
if ( ! V_116 )
goto V_122;
}
V_72 . V_82 = ( unsigned long * ) V_116 ;
V_72 . V_83 = ( unsigned long * ) ( V_116 + V_118 ) ;
V_72 . V_102 = ( unsigned long * ) ( V_116 + 2 * V_118 ) ;
V_72 . V_103 = ( unsigned long * ) ( V_116 + 3 * V_118 ) ;
V_72 . V_104 = ( unsigned long * ) ( V_116 + 4 * V_118 ) ;
V_72 . V_105 = ( unsigned long * ) ( V_116 + 5 * V_118 ) ;
if ( ( V_10 = F_80 ( V_71 , V_99 , V_72 . V_82 ) ) ||
( V_10 = F_80 ( V_71 , V_100 , V_72 . V_83 ) ) ||
( V_10 = F_80 ( V_71 , exp , V_72 . V_102 ) ) )
goto V_83;
F_42 ( V_71 , V_72 . V_103 ) ;
F_42 ( V_71 , V_72 . V_104 ) ;
F_42 ( V_71 , V_72 . V_105 ) ;
V_10 = F_47 ( V_71 , & V_72 , V_55 ) ;
if ( V_10 < 0 )
goto V_83;
if ( ! V_10 ) {
V_10 = - V_66 ;
if ( F_54 ( V_6 ) )
goto V_83;
V_10 = 0 ;
}
if ( F_84 ( V_71 , V_99 , V_72 . V_103 ) ||
F_84 ( V_71 , V_100 , V_72 . V_104 ) ||
F_84 ( V_71 , exp , V_72 . V_105 ) )
V_10 = - V_70 ;
V_83:
if ( V_116 != V_120 )
F_75 ( V_116 ) ;
V_122:
return V_10 ;
}
static long F_86 ( int V_71 , T_13 T_7 * V_99 ,
T_13 T_7 * V_100 , T_13 T_7 * exp ,
struct V_166 T_7 * V_124 , T_14 T_7 * V_125 ,
T_15 V_126 )
{
T_14 V_172 ;
T_12 V_127 , V_128 ;
struct V_166 V_53 ;
struct V_58 V_55 , * V_50 = NULL ;
int V_10 ;
if ( V_124 ) {
if ( F_39 ( & V_53 , V_124 , sizeof( V_53 ) ) )
return - V_70 ;
V_50 = & V_55 ;
if ( F_31 ( V_50 , V_53 . V_5 , V_53 . V_9 ) )
return - V_54 ;
}
if ( V_125 ) {
if ( V_126 != sizeof( T_14 ) )
return - V_54 ;
if ( F_39 ( & V_172 , V_125 , sizeof( V_172 ) ) )
return - V_70 ;
F_87 ( & V_127 , & V_172 ) ;
F_64 ( & V_127 , V_125 ( V_130 ) | V_125 ( V_131 ) ) ;
F_65 ( V_132 , & V_127 , & V_128 ) ;
}
V_10 = F_85 ( V_71 , V_99 , V_100 , exp , V_50 ) ;
V_10 = F_77 ( & V_55 , V_124 , 0 , V_10 ) ;
if ( V_10 == - V_66 ) {
if ( V_125 ) {
memcpy ( & V_6 -> V_133 , & V_128 ,
sizeof( V_128 ) ) ;
F_66 () ;
}
} else if ( V_125 )
F_65 ( V_132 , & V_128 , NULL ) ;
return V_10 ;
}
