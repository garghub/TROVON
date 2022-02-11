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
static int F_37 ( unsigned long V_67 , T_8 * V_68 )
{
unsigned long * V_69 ;
unsigned long V_70 ;
int V_71 ;
struct V_72 * V_73 ;
V_70 = ~ ( ~ 0UL << ( V_67 & ( V_74 - 1 ) ) ) ;
V_67 /= V_74 ;
V_73 = F_38 ( V_6 -> V_75 ) ;
V_69 = V_73 -> V_69 + V_67 ;
V_71 = 0 ;
if ( V_70 ) {
V_70 &= F_39 ( V_68 , V_67 ) ;
if ( V_70 ) {
if ( ! ( V_70 & ~ * V_69 ) )
goto V_76;
return - V_77 ;
}
}
while ( V_67 ) {
V_69 -- ;
V_67 -- ;
V_70 = F_39 ( V_68 , V_67 ) ;
if ( ! V_70 )
continue;
if ( V_70 & ~ * V_69 )
return - V_77 ;
if ( V_71 )
continue;
V_76:
do {
V_71 ++ ;
V_70 >>= 1 ;
} while ( V_70 );
V_71 += V_67 * V_74 ;
}
return V_71 ;
}
static inline void F_40 ( T_4 * V_24 , unsigned long V_78 ,
unsigned long V_79 , unsigned long V_80 ,
unsigned int V_81 )
{
V_24 -> V_43 = V_82 | V_81 ;
if ( V_78 & V_80 )
V_24 -> V_43 |= V_83 ;
if ( V_79 & V_80 )
V_24 -> V_43 |= V_84 ;
}
int F_41 ( int V_67 , T_8 * V_68 , struct V_1 * V_55 )
{
T_5 V_85 , * V_50 = NULL ;
struct V_13 V_19 ;
T_4 * V_24 ;
int V_86 , V_28 , V_87 = 0 ;
T_1 V_3 = 0 ;
unsigned int V_88 = F_42 () ? V_89 : 0 ;
unsigned long V_90 = 0 ;
F_43 () ;
V_86 = F_37 ( V_67 , V_68 ) ;
F_44 () ;
if ( V_86 < 0 )
return V_86 ;
V_67 = V_86 ;
F_7 ( & V_19 ) ;
V_24 = & V_19 . V_15 ;
if ( V_55 && ! V_55 -> V_5 && ! V_55 -> V_9 ) {
V_24 -> V_91 = NULL ;
V_87 = 1 ;
}
if ( V_55 && ! V_87 )
V_3 = F_3 ( V_55 ) ;
V_86 = 0 ;
for (; ; ) {
unsigned long * V_92 , * V_93 , * V_94 , * V_95 , * V_96 , * exp ;
bool V_97 = false ;
V_95 = V_68 -> V_78 ; V_96 = V_68 -> V_79 ; exp = V_68 -> V_98 ;
V_92 = V_68 -> V_99 ; V_93 = V_68 -> V_100 ; V_94 = V_68 -> V_101 ;
for ( V_28 = 0 ; V_28 < V_67 ; ++ V_92 , ++ V_93 , ++ V_94 ) {
unsigned long V_78 , V_79 , V_98 , V_102 , V_80 = 1 , V_103 , V_104 ;
unsigned long V_99 = 0 , V_100 = 0 , V_101 = 0 ;
V_78 = * V_95 ++ ; V_79 = * V_96 ++ ; V_98 = * exp ++ ;
V_102 = V_78 | V_79 | V_98 ;
if ( V_102 == 0 ) {
V_28 += V_74 ;
continue;
}
for ( V_104 = 0 ; V_104 < V_74 ; ++ V_104 , ++ V_28 , V_80 <<= 1 ) {
struct V_105 V_106 ;
if ( V_28 >= V_67 )
break;
if ( ! ( V_80 & V_102 ) )
continue;
V_106 = F_45 ( V_28 ) ;
if ( V_106 . V_42 ) {
const struct V_107 * V_108 ;
V_108 = V_106 . V_42 -> V_108 ;
V_103 = V_109 ;
if ( V_108 -> V_110 ) {
F_40 ( V_24 , V_78 , V_79 ,
V_80 , V_88 ) ;
V_103 = (* V_108 -> V_110 )( V_106 . V_42 , V_24 ) ;
}
F_46 ( V_106 ) ;
if ( ( V_103 & V_83 ) && ( V_78 & V_80 ) ) {
V_99 |= V_80 ;
V_86 ++ ;
V_24 -> V_91 = NULL ;
}
if ( ( V_103 & V_84 ) && ( V_79 & V_80 ) ) {
V_100 |= V_80 ;
V_86 ++ ;
V_24 -> V_91 = NULL ;
}
if ( ( V_103 & V_82 ) && ( V_98 & V_80 ) ) {
V_101 |= V_80 ;
V_86 ++ ;
V_24 -> V_91 = NULL ;
}
if ( V_86 ) {
V_97 = false ;
V_88 = 0 ;
} else if ( V_88 & V_103 )
V_97 = true ;
}
}
if ( V_99 )
* V_92 = V_99 ;
if ( V_100 )
* V_93 = V_100 ;
if ( V_101 )
* V_94 = V_101 ;
F_47 () ;
}
V_24 -> V_91 = NULL ;
if ( V_86 || V_87 || F_48 ( V_6 ) )
break;
if ( V_19 . error ) {
V_86 = V_19 . error ;
break;
}
if ( V_97 && ! F_49 () ) {
if ( ! V_90 ) {
V_90 = F_50 () ;
continue;
}
if ( ! F_51 ( V_90 ) )
continue;
}
V_88 = 0 ;
if ( V_55 && ! V_50 ) {
V_85 = F_52 ( * V_55 ) ;
V_50 = & V_85 ;
}
if ( ! F_26 ( & V_19 , V_111 ,
V_50 , V_3 ) )
V_87 = 1 ;
}
F_12 ( & V_19 ) ;
return V_86 ;
}
int F_53 ( int V_67 , T_9 T_7 * V_95 , T_9 T_7 * V_96 ,
T_9 T_7 * exp , struct V_1 * V_55 )
{
T_8 V_68 ;
void * V_112 ;
int V_10 , V_113 ;
T_10 V_114 , V_115 ;
struct V_72 * V_73 ;
long V_116 [ V_117 / sizeof( long ) ] ;
V_10 = - V_54 ;
if ( V_67 < 0 )
goto V_118;
F_43 () ;
V_73 = F_38 ( V_6 -> V_75 ) ;
V_113 = V_73 -> V_113 ;
F_44 () ;
if ( V_67 > V_113 )
V_67 = V_113 ;
V_114 = F_54 ( V_67 ) ;
V_112 = V_116 ;
if ( V_114 > sizeof( V_116 ) / 6 ) {
V_10 = - V_36 ;
if ( V_114 > ( V_119 / 6 ) )
goto V_118;
V_115 = 6 * V_114 ;
V_112 = F_55 ( V_115 , V_35 | V_120 ) ;
if ( ! V_112 && V_115 > V_121 )
V_112 = F_56 ( V_115 ) ;
if ( ! V_112 )
goto V_118;
}
V_68 . V_78 = V_112 ;
V_68 . V_79 = V_112 + V_114 ;
V_68 . V_98 = V_112 + 2 * V_114 ;
V_68 . V_99 = V_112 + 3 * V_114 ;
V_68 . V_100 = V_112 + 4 * V_114 ;
V_68 . V_101 = V_112 + 5 * V_114 ;
if ( ( V_10 = F_57 ( V_67 , V_95 , V_68 . V_78 ) ) ||
( V_10 = F_57 ( V_67 , V_96 , V_68 . V_79 ) ) ||
( V_10 = F_57 ( V_67 , exp , V_68 . V_98 ) ) )
goto V_79;
F_58 ( V_67 , V_68 . V_99 ) ;
F_58 ( V_67 , V_68 . V_100 ) ;
F_58 ( V_67 , V_68 . V_101 ) ;
V_10 = F_41 ( V_67 , & V_68 , V_55 ) ;
if ( V_10 < 0 )
goto V_79;
if ( ! V_10 ) {
V_10 = - V_66 ;
if ( F_48 ( V_6 ) )
goto V_79;
V_10 = 0 ;
}
if ( F_59 ( V_67 , V_95 , V_68 . V_99 ) ||
F_59 ( V_67 , V_96 , V_68 . V_100 ) ||
F_59 ( V_67 , exp , V_68 . V_101 ) )
V_10 = - V_122 ;
V_79:
if ( V_112 != V_116 )
F_60 ( V_112 ) ;
V_118:
return V_10 ;
}
static long F_61 ( int V_67 , T_9 T_7 * V_95 , T_9 T_7 * V_96 ,
T_9 T_7 * exp , struct V_58 T_7 * V_123 ,
const T_11 T_7 * V_124 , T_10 V_125 )
{
T_11 V_126 , V_127 ;
struct V_58 V_53 ;
struct V_1 V_128 , V_55 , * V_50 = NULL ;
int V_10 ;
if ( V_123 ) {
if ( F_62 ( & V_53 , V_123 , sizeof( V_53 ) ) )
return - V_122 ;
V_128 = F_63 ( V_53 ) ;
V_50 = & V_55 ;
if ( F_31 ( V_50 , V_128 . V_5 , V_128 . V_9 ) )
return - V_54 ;
}
if ( V_124 ) {
if ( V_125 != sizeof( T_11 ) )
return - V_54 ;
if ( F_62 ( & V_126 , V_124 , sizeof( V_126 ) ) )
return - V_122 ;
F_64 ( & V_126 , V_124 ( V_129 ) | V_124 ( V_130 ) ) ;
F_65 ( V_131 , & V_126 , & V_127 ) ;
}
V_10 = F_53 ( V_67 , V_95 , V_96 , exp , V_50 ) ;
V_10 = F_34 ( & V_55 , V_123 , 0 , V_10 ) ;
if ( V_10 == - V_66 ) {
if ( V_124 ) {
memcpy ( & V_6 -> V_132 , & V_127 ,
sizeof( V_127 ) ) ;
F_66 () ;
}
} else if ( V_124 )
F_65 ( V_131 , & V_127 , NULL ) ;
return V_10 ;
}
static inline unsigned int F_67 ( struct V_133 * V_133 , T_4 * V_134 ,
bool * V_135 ,
unsigned int V_88 )
{
unsigned int V_103 ;
int V_105 ;
V_103 = 0 ;
V_105 = V_133 -> V_105 ;
if ( V_105 >= 0 ) {
struct V_105 V_106 = F_45 ( V_105 ) ;
V_103 = V_136 ;
if ( V_106 . V_42 ) {
V_103 = V_109 ;
if ( V_106 . V_42 -> V_108 -> V_110 ) {
V_134 -> V_43 = V_133 -> V_137 | V_138 | V_139 ;
V_134 -> V_43 |= V_88 ;
V_103 = V_106 . V_42 -> V_108 -> V_110 ( V_106 . V_42 , V_134 ) ;
if ( V_103 & V_88 )
* V_135 = true ;
}
V_103 &= V_133 -> V_137 | V_138 | V_139 ;
F_46 ( V_106 ) ;
}
}
V_133 -> V_140 = V_103 ;
return V_103 ;
}
static int F_68 ( struct V_141 * V_142 , struct V_13 * V_24 ,
struct V_1 * V_55 )
{
T_4 * V_15 = & V_24 -> V_15 ;
T_5 V_85 , * V_50 = NULL ;
int V_87 = 0 , V_143 = 0 ;
T_1 V_3 = 0 ;
unsigned int V_88 = F_42 () ? V_89 : 0 ;
unsigned long V_90 = 0 ;
if ( V_55 && ! V_55 -> V_5 && ! V_55 -> V_9 ) {
V_15 -> V_91 = NULL ;
V_87 = 1 ;
}
if ( V_55 && ! V_87 )
V_3 = F_3 ( V_55 ) ;
for (; ; ) {
struct V_141 * V_144 ;
bool V_97 = false ;
for ( V_144 = V_142 ; V_144 != NULL ; V_144 = V_144 -> V_32 ) {
struct V_133 * V_145 , * V_146 ;
V_145 = V_144 -> V_31 ;
V_146 = V_145 + V_144 -> V_147 ;
for (; V_145 != V_146 ; V_145 ++ ) {
if ( F_67 ( V_145 , V_15 , & V_97 ,
V_88 ) ) {
V_143 ++ ;
V_15 -> V_91 = NULL ;
V_88 = 0 ;
V_97 = false ;
}
}
}
V_15 -> V_91 = NULL ;
if ( ! V_143 ) {
V_143 = V_24 -> error ;
if ( F_48 ( V_6 ) )
V_143 = - V_47 ;
}
if ( V_143 || V_87 )
break;
if ( V_97 && ! F_49 () ) {
if ( ! V_90 ) {
V_90 = F_50 () ;
continue;
}
if ( ! F_51 ( V_90 ) )
continue;
}
V_88 = 0 ;
if ( V_55 && ! V_50 ) {
V_85 = F_52 ( * V_55 ) ;
V_50 = & V_85 ;
}
if ( ! F_26 ( V_24 , V_111 , V_50 , V_3 ) )
V_87 = 1 ;
}
return V_143 ;
}
int F_69 ( struct V_133 T_7 * V_148 , unsigned int V_149 ,
struct V_1 * V_55 )
{
struct V_13 V_19 ;
int V_150 = - V_122 , V_151 , V_147 , V_114 ;
long V_152 [ V_153 / sizeof( long ) ] ;
struct V_141 * const V_154 = (struct V_141 * ) V_152 ;
struct V_141 * V_144 = V_154 ;
unsigned long V_155 = V_149 ;
if ( V_149 > F_70 ( V_156 ) )
return - V_54 ;
V_147 = F_71 (unsigned int, nfds, N_STACK_PPS) ;
for (; ; ) {
V_144 -> V_32 = NULL ;
V_144 -> V_147 = V_147 ;
if ( ! V_147 )
break;
if ( F_62 ( V_144 -> V_31 , V_148 + V_149 - V_155 ,
sizeof( struct V_133 ) * V_144 -> V_147 ) )
goto V_157;
V_155 -= V_144 -> V_147 ;
if ( ! V_155 )
break;
V_147 = F_72 ( V_155 , V_158 ) ;
V_114 = sizeof( struct V_141 ) + sizeof( struct V_133 ) * V_147 ;
V_144 = V_144 -> V_32 = F_55 ( V_114 , V_35 ) ;
if ( ! V_144 ) {
V_150 = - V_36 ;
goto V_157;
}
}
F_7 ( & V_19 ) ;
V_151 = F_68 ( V_154 , & V_19 , V_55 ) ;
F_12 ( & V_19 ) ;
for ( V_144 = V_154 ; V_144 ; V_144 = V_144 -> V_32 ) {
struct V_133 * V_68 = V_144 -> V_31 ;
int V_104 ;
for ( V_104 = 0 ; V_104 < V_144 -> V_147 ; V_104 ++ , V_148 ++ )
if ( F_73 ( V_68 [ V_104 ] . V_140 , & V_148 -> V_140 ) )
goto V_157;
}
V_150 = V_151 ;
V_157:
V_144 = V_154 -> V_32 ;
while ( V_144 ) {
struct V_141 * V_159 = V_144 ;
V_144 = V_144 -> V_32 ;
F_74 ( V_159 ) ;
}
return V_150 ;
}
static long F_75 ( struct V_160 * V_160 )
{
struct V_133 T_7 * V_148 = V_160 -> V_110 . V_148 ;
int V_149 = V_160 -> V_110 . V_149 ;
struct V_1 * V_50 = NULL , V_55 ;
int V_10 ;
if ( V_160 -> V_110 . V_161 ) {
V_55 . V_5 = V_160 -> V_110 . V_5 ;
V_55 . V_9 = V_160 -> V_110 . V_9 ;
V_50 = & V_55 ;
}
V_10 = F_69 ( V_148 , V_149 , V_50 ) ;
if ( V_10 == - V_47 ) {
V_160 -> V_162 = F_75 ;
V_10 = - V_163 ;
}
return V_10 ;
}
