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
unsigned long V_77 , unsigned long V_78 )
{
V_24 -> V_43 = V_79 ;
if ( V_76 & V_78 )
V_24 -> V_43 |= V_80 ;
if ( V_77 & V_78 )
V_24 -> V_43 |= V_81 ;
}
int F_40 ( int V_65 , T_6 * V_66 , struct V_1 * V_55 )
{
T_4 V_82 , * V_50 = NULL ;
struct V_13 V_19 ;
T_3 * V_24 ;
int V_83 , V_28 , V_84 = 0 ;
unsigned long V_3 = 0 ;
F_41 () ;
V_83 = F_36 ( V_65 , V_66 ) ;
F_42 () ;
if ( V_83 < 0 )
return V_83 ;
V_65 = V_83 ;
F_7 ( & V_19 ) ;
V_24 = & V_19 . V_15 ;
if ( V_55 && ! V_55 -> V_5 && ! V_55 -> V_9 ) {
V_24 -> V_85 = NULL ;
V_84 = 1 ;
}
if ( V_55 && ! V_84 )
V_3 = F_3 ( V_55 ) ;
V_83 = 0 ;
for (; ; ) {
unsigned long * V_86 , * V_87 , * V_88 , * V_89 , * V_90 , * exp ;
V_89 = V_66 -> V_76 ; V_90 = V_66 -> V_77 ; exp = V_66 -> V_91 ;
V_86 = V_66 -> V_92 ; V_87 = V_66 -> V_93 ; V_88 = V_66 -> V_94 ;
for ( V_28 = 0 ; V_28 < V_65 ; ++ V_86 , ++ V_87 , ++ V_88 ) {
unsigned long V_76 , V_77 , V_91 , V_95 , V_78 = 1 , V_96 , V_97 ;
unsigned long V_92 = 0 , V_93 = 0 , V_94 = 0 ;
V_76 = * V_89 ++ ; V_77 = * V_90 ++ ; V_91 = * exp ++ ;
V_95 = V_76 | V_77 | V_91 ;
if ( V_95 == 0 ) {
V_28 += V_72 ;
continue;
}
for ( V_97 = 0 ; V_97 < V_72 ; ++ V_97 , ++ V_28 , V_78 <<= 1 ) {
struct V_98 V_99 ;
if ( V_28 >= V_65 )
break;
if ( ! ( V_78 & V_95 ) )
continue;
V_99 = F_43 ( V_28 ) ;
if ( V_99 . V_42 ) {
const struct V_100 * V_101 ;
V_101 = V_99 . V_42 -> V_101 ;
V_96 = V_102 ;
if ( V_101 && V_101 -> V_103 ) {
F_39 ( V_24 , V_76 , V_77 , V_78 ) ;
V_96 = (* V_101 -> V_103 )( V_99 . V_42 , V_24 ) ;
}
F_44 ( V_99 ) ;
if ( ( V_96 & V_80 ) && ( V_76 & V_78 ) ) {
V_92 |= V_78 ;
V_83 ++ ;
V_24 -> V_85 = NULL ;
}
if ( ( V_96 & V_81 ) && ( V_77 & V_78 ) ) {
V_93 |= V_78 ;
V_83 ++ ;
V_24 -> V_85 = NULL ;
}
if ( ( V_96 & V_79 ) && ( V_91 & V_78 ) ) {
V_94 |= V_78 ;
V_83 ++ ;
V_24 -> V_85 = NULL ;
}
}
}
if ( V_92 )
* V_86 = V_92 ;
if ( V_93 )
* V_87 = V_93 ;
if ( V_94 )
* V_88 = V_94 ;
F_45 () ;
}
V_24 -> V_85 = NULL ;
if ( V_83 || V_84 || F_46 ( V_6 ) )
break;
if ( V_19 . error ) {
V_83 = V_19 . error ;
break;
}
if ( V_55 && ! V_50 ) {
V_82 = F_47 ( * V_55 ) ;
V_50 = & V_82 ;
}
if ( ! F_26 ( & V_19 , V_104 ,
V_50 , V_3 ) )
V_84 = 1 ;
}
F_12 ( & V_19 ) ;
return V_83 ;
}
int F_48 ( int V_65 , T_7 T_5 * V_89 , T_7 T_5 * V_90 ,
T_7 T_5 * exp , struct V_1 * V_55 )
{
T_6 V_66 ;
void * V_105 ;
int V_10 , V_106 ;
unsigned int V_107 ;
struct V_70 * V_71 ;
long V_108 [ V_109 / sizeof( long ) ] ;
V_10 = - V_54 ;
if ( V_65 < 0 )
goto V_110;
F_41 () ;
V_71 = F_37 ( V_6 -> V_73 ) ;
V_106 = V_71 -> V_106 ;
F_42 () ;
if ( V_65 > V_106 )
V_65 = V_106 ;
V_107 = F_49 ( V_65 ) ;
V_105 = V_108 ;
if ( V_107 > sizeof( V_108 ) / 6 ) {
V_10 = - V_36 ;
V_105 = F_50 ( 6 * V_107 , V_35 ) ;
if ( ! V_105 )
goto V_110;
}
V_66 . V_76 = V_105 ;
V_66 . V_77 = V_105 + V_107 ;
V_66 . V_91 = V_105 + 2 * V_107 ;
V_66 . V_92 = V_105 + 3 * V_107 ;
V_66 . V_93 = V_105 + 4 * V_107 ;
V_66 . V_94 = V_105 + 5 * V_107 ;
if ( ( V_10 = F_51 ( V_65 , V_89 , V_66 . V_76 ) ) ||
( V_10 = F_51 ( V_65 , V_90 , V_66 . V_77 ) ) ||
( V_10 = F_51 ( V_65 , exp , V_66 . V_91 ) ) )
goto V_77;
F_52 ( V_65 , V_66 . V_92 ) ;
F_52 ( V_65 , V_66 . V_93 ) ;
F_52 ( V_65 , V_66 . V_94 ) ;
V_10 = F_40 ( V_65 , & V_66 , V_55 ) ;
if ( V_10 < 0 )
goto V_77;
if ( ! V_10 ) {
V_10 = - V_64 ;
if ( F_46 ( V_6 ) )
goto V_77;
V_10 = 0 ;
}
if ( F_53 ( V_65 , V_89 , V_66 . V_92 ) ||
F_53 ( V_65 , V_90 , V_66 . V_93 ) ||
F_53 ( V_65 , exp , V_66 . V_94 ) )
V_10 = - V_111 ;
V_77:
if ( V_105 != V_108 )
F_54 ( V_105 ) ;
V_110:
return V_10 ;
}
static long F_55 ( int V_65 , T_7 T_5 * V_89 , T_7 T_5 * V_90 ,
T_7 T_5 * exp , struct V_1 T_5 * V_112 ,
const T_8 T_5 * V_113 , T_9 V_114 )
{
T_8 V_115 , V_116 ;
struct V_1 V_53 , V_55 , * V_50 = NULL ;
int V_10 ;
if ( V_112 ) {
if ( F_56 ( & V_53 , V_112 , sizeof( V_53 ) ) )
return - V_111 ;
V_50 = & V_55 ;
if ( F_31 ( V_50 , V_53 . V_5 , V_53 . V_9 ) )
return - V_54 ;
}
if ( V_113 ) {
if ( V_114 != sizeof( T_8 ) )
return - V_54 ;
if ( F_56 ( & V_115 , V_113 , sizeof( V_115 ) ) )
return - V_111 ;
F_57 ( & V_115 , V_113 ( V_117 ) | V_113 ( V_118 ) ) ;
F_58 ( V_119 , & V_115 , & V_116 ) ;
}
V_10 = F_48 ( V_65 , V_89 , V_90 , exp , V_50 ) ;
V_10 = F_34 ( & V_55 , V_112 , 0 , V_10 ) ;
if ( V_10 == - V_64 ) {
if ( V_113 ) {
memcpy ( & V_6 -> V_120 , & V_116 ,
sizeof( V_116 ) ) ;
F_59 () ;
}
} else if ( V_113 )
F_58 ( V_119 , & V_116 , NULL ) ;
return V_10 ;
}
static inline unsigned int F_60 ( struct V_121 * V_121 , T_3 * V_122 )
{
unsigned int V_96 ;
int V_98 ;
V_96 = 0 ;
V_98 = V_121 -> V_98 ;
if ( V_98 >= 0 ) {
struct V_98 V_99 = F_43 ( V_98 ) ;
V_96 = V_123 ;
if ( V_99 . V_42 ) {
V_96 = V_102 ;
if ( V_99 . V_42 -> V_101 && V_99 . V_42 -> V_101 -> V_103 ) {
V_122 -> V_43 = V_121 -> V_124 | V_125 | V_126 ;
V_96 = V_99 . V_42 -> V_101 -> V_103 ( V_99 . V_42 , V_122 ) ;
}
V_96 &= V_121 -> V_124 | V_125 | V_126 ;
F_44 ( V_99 ) ;
}
}
V_121 -> V_127 = V_96 ;
return V_96 ;
}
static int F_61 ( unsigned int V_128 , struct V_129 * V_130 ,
struct V_13 * V_24 , struct V_1 * V_55 )
{
T_3 * V_15 = & V_24 -> V_15 ;
T_4 V_82 , * V_50 = NULL ;
int V_84 = 0 , V_131 = 0 ;
unsigned long V_3 = 0 ;
if ( V_55 && ! V_55 -> V_5 && ! V_55 -> V_9 ) {
V_15 -> V_85 = NULL ;
V_84 = 1 ;
}
if ( V_55 && ! V_84 )
V_3 = F_3 ( V_55 ) ;
for (; ; ) {
struct V_129 * V_132 ;
for ( V_132 = V_130 ; V_132 != NULL ; V_132 = V_132 -> V_32 ) {
struct V_121 * V_133 , * V_134 ;
V_133 = V_132 -> V_31 ;
V_134 = V_133 + V_132 -> V_135 ;
for (; V_133 != V_134 ; V_133 ++ ) {
if ( F_60 ( V_133 , V_15 ) ) {
V_131 ++ ;
V_15 -> V_85 = NULL ;
}
}
}
V_15 -> V_85 = NULL ;
if ( ! V_131 ) {
V_131 = V_24 -> error ;
if ( F_46 ( V_6 ) )
V_131 = - V_47 ;
}
if ( V_131 || V_84 )
break;
if ( V_55 && ! V_50 ) {
V_82 = F_47 ( * V_55 ) ;
V_50 = & V_82 ;
}
if ( ! F_26 ( V_24 , V_104 , V_50 , V_3 ) )
V_84 = 1 ;
}
return V_131 ;
}
int F_62 ( struct V_121 T_5 * V_136 , unsigned int V_128 ,
struct V_1 * V_55 )
{
struct V_13 V_19 ;
int V_137 = - V_111 , V_138 , V_135 , V_107 ;
long V_139 [ V_140 / sizeof( long ) ] ;
struct V_129 * const V_141 = (struct V_129 * ) V_139 ;
struct V_129 * V_132 = V_141 ;
unsigned long V_142 = V_128 ;
if ( V_128 > F_63 ( V_143 ) )
return - V_54 ;
V_135 = F_64 (unsigned int, nfds, N_STACK_PPS) ;
for (; ; ) {
V_132 -> V_32 = NULL ;
V_132 -> V_135 = V_135 ;
if ( ! V_135 )
break;
if ( F_56 ( V_132 -> V_31 , V_136 + V_128 - V_142 ,
sizeof( struct V_121 ) * V_132 -> V_135 ) )
goto V_144;
V_142 -= V_132 -> V_135 ;
if ( ! V_142 )
break;
V_135 = F_65 ( V_142 , V_145 ) ;
V_107 = sizeof( struct V_129 ) + sizeof( struct V_121 ) * V_135 ;
V_132 = V_132 -> V_32 = F_50 ( V_107 , V_35 ) ;
if ( ! V_132 ) {
V_137 = - V_36 ;
goto V_144;
}
}
F_7 ( & V_19 ) ;
V_138 = F_61 ( V_128 , V_141 , & V_19 , V_55 ) ;
F_12 ( & V_19 ) ;
for ( V_132 = V_141 ; V_132 ; V_132 = V_132 -> V_32 ) {
struct V_121 * V_66 = V_132 -> V_31 ;
int V_97 ;
for ( V_97 = 0 ; V_97 < V_132 -> V_135 ; V_97 ++ , V_136 ++ )
if ( F_66 ( V_66 [ V_97 ] . V_127 , & V_136 -> V_127 ) )
goto V_144;
}
V_137 = V_138 ;
V_144:
V_132 = V_141 -> V_32 ;
while ( V_132 ) {
struct V_129 * V_146 = V_132 ;
V_132 = V_132 -> V_32 ;
F_54 ( V_146 ) ;
}
return V_137 ;
}
static long F_67 ( struct V_147 * V_147 )
{
struct V_121 T_5 * V_136 = V_147 -> V_103 . V_136 ;
int V_128 = V_147 -> V_103 . V_128 ;
struct V_1 * V_50 = NULL , V_55 ;
int V_10 ;
if ( V_147 -> V_103 . V_148 ) {
V_55 . V_5 = V_147 -> V_103 . V_5 ;
V_55 . V_9 = V_147 -> V_103 . V_9 ;
V_50 = & V_55 ;
}
V_10 = F_62 ( V_136 , V_128 , V_50 ) ;
if ( V_10 == - V_47 ) {
V_147 -> V_149 = F_67 ;
V_10 = - V_150 ;
}
return V_10 ;
}
