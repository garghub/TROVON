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
F_23 ( V_25 ) ;
V_22 -> V_25 = V_25 ;
V_22 -> V_23 = V_23 ;
V_22 -> V_39 = V_27 -> V_39 ;
F_24 ( & V_22 -> V_24 , F_21 ) ;
V_22 -> V_24 . V_40 = V_14 ;
F_25 ( V_23 , & V_22 -> V_24 ) ;
}
int F_26 ( struct V_13 * V_14 , int V_43 ,
T_4 * V_44 , unsigned long V_3 )
{
int V_45 = - V_46 ;
F_27 ( V_43 ) ;
if ( ! V_14 -> V_18 )
V_45 = F_28 ( V_44 , V_3 , V_47 ) ;
F_29 ( V_48 ) ;
F_30 ( V_14 -> V_18 , 0 ) ;
return V_45 ;
}
int F_31 ( struct V_1 * V_49 , long V_50 , long V_51 )
{
struct V_1 V_52 = { . V_5 = V_50 , . V_9 = V_51 } ;
if ( ! F_32 ( & V_52 ) )
return - V_53 ;
if ( ! V_50 && ! V_51 ) {
V_49 -> V_5 = V_49 -> V_9 = 0 ;
} else {
F_5 ( V_49 ) ;
* V_49 = F_33 ( * V_49 , V_52 ) ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_54 , void T_5 * V_27 ,
int V_55 , int V_10 )
{
struct V_1 V_56 ;
struct V_55 V_57 ;
if ( ! V_27 )
return V_10 ;
if ( V_6 -> V_58 & V_59 )
goto V_60;
if ( ! V_54 -> V_5 && ! V_54 -> V_9 )
return V_10 ;
F_5 ( & V_56 ) ;
V_56 = F_6 ( * V_54 , V_56 ) ;
if ( V_56 . V_5 < 0 )
V_56 . V_5 = V_56 . V_9 = 0 ;
if ( V_55 ) {
if ( sizeof( V_57 ) > sizeof( V_57 . V_5 ) + sizeof( V_57 . V_61 ) )
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
V_57 . V_5 = V_56 . V_5 ;
V_57 . V_61 = V_56 . V_9 / V_62 ;
if ( ! F_35 ( V_27 , & V_57 , sizeof( V_57 ) ) )
return V_10 ;
} else if ( ! F_35 ( V_27 , & V_56 , sizeof( V_56 ) ) )
return V_10 ;
V_60:
if ( V_10 == - V_63 )
V_10 = - V_46 ;
return V_10 ;
}
static int F_36 ( unsigned long V_64 , T_6 * V_65 )
{
unsigned long * V_66 ;
unsigned long V_67 ;
int V_68 ;
struct V_69 * V_70 ;
V_67 = ~ ( ~ 0UL << ( V_64 & ( V_71 - 1 ) ) ) ;
V_64 /= V_71 ;
V_70 = F_37 ( V_6 -> V_72 ) ;
V_66 = V_70 -> V_66 -> V_73 + V_64 ;
V_68 = 0 ;
if ( V_67 ) {
V_67 &= F_38 ( V_65 , V_64 ) ;
if ( V_67 ) {
if ( ! ( V_67 & ~ * V_66 ) )
goto V_74;
return - V_75 ;
}
}
while ( V_64 ) {
V_66 -- ;
V_64 -- ;
V_67 = F_38 ( V_65 , V_64 ) ;
if ( ! V_67 )
continue;
if ( V_67 & ~ * V_66 )
return - V_75 ;
if ( V_68 )
continue;
V_74:
do {
V_68 ++ ;
V_67 >>= 1 ;
} while ( V_67 );
V_68 += V_64 * V_71 ;
}
return V_68 ;
}
static inline void F_39 ( T_3 * V_24 , unsigned long V_76 ,
unsigned long V_77 , unsigned long V_78 )
{
if ( V_24 ) {
V_24 -> V_39 = V_79 ;
if ( V_76 & V_78 )
V_24 -> V_39 |= V_80 ;
if ( V_77 & V_78 )
V_24 -> V_39 |= V_81 ;
}
}
int F_40 ( int V_64 , T_6 * V_65 , struct V_1 * V_54 )
{
T_4 V_82 , * V_49 = NULL ;
struct V_13 V_19 ;
T_3 * V_24 ;
int V_83 , V_28 , V_84 = 0 ;
unsigned long V_3 = 0 ;
F_41 () ;
V_83 = F_36 ( V_64 , V_65 ) ;
F_42 () ;
if ( V_83 < 0 )
return V_83 ;
V_64 = V_83 ;
F_7 ( & V_19 ) ;
V_24 = & V_19 . V_15 ;
if ( V_54 && ! V_54 -> V_5 && ! V_54 -> V_9 ) {
V_24 = NULL ;
V_84 = 1 ;
}
if ( V_54 && ! V_84 )
V_3 = F_3 ( V_54 ) ;
V_83 = 0 ;
for (; ; ) {
unsigned long * V_85 , * V_86 , * V_87 , * V_88 , * V_89 , * exp ;
V_88 = V_65 -> V_76 ; V_89 = V_65 -> V_77 ; exp = V_65 -> V_90 ;
V_85 = V_65 -> V_91 ; V_86 = V_65 -> V_92 ; V_87 = V_65 -> V_93 ;
for ( V_28 = 0 ; V_28 < V_64 ; ++ V_85 , ++ V_86 , ++ V_87 ) {
unsigned long V_76 , V_77 , V_90 , V_94 , V_78 = 1 , V_95 , V_96 ;
unsigned long V_91 = 0 , V_92 = 0 , V_93 = 0 ;
const struct V_97 * V_98 = NULL ;
struct V_42 * V_42 = NULL ;
V_76 = * V_88 ++ ; V_77 = * V_89 ++ ; V_90 = * exp ++ ;
V_94 = V_76 | V_77 | V_90 ;
if ( V_94 == 0 ) {
V_28 += V_71 ;
continue;
}
for ( V_96 = 0 ; V_96 < V_71 ; ++ V_96 , ++ V_28 , V_78 <<= 1 ) {
int V_99 ;
if ( V_28 >= V_64 )
break;
if ( ! ( V_78 & V_94 ) )
continue;
V_42 = F_43 ( V_28 , & V_99 ) ;
if ( V_42 ) {
V_98 = V_42 -> V_98 ;
V_95 = V_100 ;
if ( V_98 && V_98 -> V_101 ) {
F_39 ( V_24 , V_76 , V_77 , V_78 ) ;
V_95 = (* V_98 -> V_101 )( V_42 , V_24 ) ;
}
F_44 ( V_42 , V_99 ) ;
if ( ( V_95 & V_80 ) && ( V_76 & V_78 ) ) {
V_91 |= V_78 ;
V_83 ++ ;
V_24 = NULL ;
}
if ( ( V_95 & V_81 ) && ( V_77 & V_78 ) ) {
V_92 |= V_78 ;
V_83 ++ ;
V_24 = NULL ;
}
if ( ( V_95 & V_79 ) && ( V_90 & V_78 ) ) {
V_93 |= V_78 ;
V_83 ++ ;
V_24 = NULL ;
}
}
}
if ( V_91 )
* V_85 = V_91 ;
if ( V_92 )
* V_86 = V_92 ;
if ( V_93 )
* V_87 = V_93 ;
F_45 () ;
}
V_24 = NULL ;
if ( V_83 || V_84 || F_46 ( V_6 ) )
break;
if ( V_19 . error ) {
V_83 = V_19 . error ;
break;
}
if ( V_54 && ! V_49 ) {
V_82 = F_47 ( * V_54 ) ;
V_49 = & V_82 ;
}
if ( ! F_26 ( & V_19 , V_102 ,
V_49 , V_3 ) )
V_84 = 1 ;
}
F_12 ( & V_19 ) ;
return V_83 ;
}
int F_48 ( int V_64 , T_7 T_5 * V_88 , T_7 T_5 * V_89 ,
T_7 T_5 * exp , struct V_1 * V_54 )
{
T_6 V_65 ;
void * V_103 ;
int V_10 , V_104 ;
unsigned int V_105 ;
struct V_69 * V_70 ;
long V_106 [ V_107 / sizeof( long ) ] ;
V_10 = - V_53 ;
if ( V_64 < 0 )
goto V_108;
F_41 () ;
V_70 = F_37 ( V_6 -> V_72 ) ;
V_104 = V_70 -> V_104 ;
F_42 () ;
if ( V_64 > V_104 )
V_64 = V_104 ;
V_105 = F_49 ( V_64 ) ;
V_103 = V_106 ;
if ( V_105 > sizeof( V_106 ) / 6 ) {
V_10 = - V_36 ;
V_103 = F_50 ( 6 * V_105 , V_35 ) ;
if ( ! V_103 )
goto V_108;
}
V_65 . V_76 = V_103 ;
V_65 . V_77 = V_103 + V_105 ;
V_65 . V_90 = V_103 + 2 * V_105 ;
V_65 . V_91 = V_103 + 3 * V_105 ;
V_65 . V_92 = V_103 + 4 * V_105 ;
V_65 . V_93 = V_103 + 5 * V_105 ;
if ( ( V_10 = F_51 ( V_64 , V_88 , V_65 . V_76 ) ) ||
( V_10 = F_51 ( V_64 , V_89 , V_65 . V_77 ) ) ||
( V_10 = F_51 ( V_64 , exp , V_65 . V_90 ) ) )
goto V_77;
F_52 ( V_64 , V_65 . V_91 ) ;
F_52 ( V_64 , V_65 . V_92 ) ;
F_52 ( V_64 , V_65 . V_93 ) ;
V_10 = F_40 ( V_64 , & V_65 , V_54 ) ;
if ( V_10 < 0 )
goto V_77;
if ( ! V_10 ) {
V_10 = - V_63 ;
if ( F_46 ( V_6 ) )
goto V_77;
V_10 = 0 ;
}
if ( F_53 ( V_64 , V_88 , V_65 . V_91 ) ||
F_53 ( V_64 , V_89 , V_65 . V_92 ) ||
F_53 ( V_64 , exp , V_65 . V_93 ) )
V_10 = - V_109 ;
V_77:
if ( V_103 != V_106 )
F_54 ( V_103 ) ;
V_108:
return V_10 ;
}
static long F_55 ( int V_64 , T_7 T_5 * V_88 , T_7 T_5 * V_89 ,
T_7 T_5 * exp , struct V_1 T_5 * V_110 ,
const T_8 T_5 * V_111 , T_9 V_112 )
{
T_8 V_113 , V_114 ;
struct V_1 V_52 , V_54 , * V_49 = NULL ;
int V_10 ;
if ( V_110 ) {
if ( F_56 ( & V_52 , V_110 , sizeof( V_52 ) ) )
return - V_109 ;
V_49 = & V_54 ;
if ( F_31 ( V_49 , V_52 . V_5 , V_52 . V_9 ) )
return - V_53 ;
}
if ( V_111 ) {
if ( V_112 != sizeof( T_8 ) )
return - V_53 ;
if ( F_56 ( & V_113 , V_111 , sizeof( V_113 ) ) )
return - V_109 ;
F_57 ( & V_113 , V_111 ( V_115 ) | V_111 ( V_116 ) ) ;
F_58 ( V_117 , & V_113 , & V_114 ) ;
}
V_10 = F_48 ( V_64 , V_88 , V_89 , exp , V_49 ) ;
V_10 = F_34 ( & V_54 , V_110 , 0 , V_10 ) ;
if ( V_10 == - V_63 ) {
if ( V_111 ) {
memcpy ( & V_6 -> V_118 , & V_114 ,
sizeof( V_114 ) ) ;
F_59 () ;
}
} else if ( V_111 )
F_58 ( V_117 , & V_114 , NULL ) ;
return V_10 ;
}
static inline unsigned int F_60 ( struct V_119 * V_119 , T_3 * V_120 )
{
unsigned int V_95 ;
int V_121 ;
V_95 = 0 ;
V_121 = V_119 -> V_121 ;
if ( V_121 >= 0 ) {
int V_99 ;
struct V_42 * V_42 ;
V_42 = F_43 ( V_121 , & V_99 ) ;
V_95 = V_122 ;
if ( V_42 != NULL ) {
V_95 = V_100 ;
if ( V_42 -> V_98 && V_42 -> V_98 -> V_101 ) {
if ( V_120 )
V_120 -> V_39 = V_119 -> V_123 |
V_124 | V_125 ;
V_95 = V_42 -> V_98 -> V_101 ( V_42 , V_120 ) ;
}
V_95 &= V_119 -> V_123 | V_124 | V_125 ;
F_44 ( V_42 , V_99 ) ;
}
}
V_119 -> V_126 = V_95 ;
return V_95 ;
}
static int F_61 ( unsigned int V_127 , struct V_128 * V_129 ,
struct V_13 * V_24 , struct V_1 * V_54 )
{
T_3 * V_15 = & V_24 -> V_15 ;
T_4 V_82 , * V_49 = NULL ;
int V_84 = 0 , V_130 = 0 ;
unsigned long V_3 = 0 ;
if ( V_54 && ! V_54 -> V_5 && ! V_54 -> V_9 ) {
V_15 = NULL ;
V_84 = 1 ;
}
if ( V_54 && ! V_84 )
V_3 = F_3 ( V_54 ) ;
for (; ; ) {
struct V_128 * V_131 ;
for ( V_131 = V_129 ; V_131 != NULL ; V_131 = V_131 -> V_32 ) {
struct V_119 * V_132 , * V_133 ;
V_132 = V_131 -> V_31 ;
V_133 = V_132 + V_131 -> V_134 ;
for (; V_132 != V_133 ; V_132 ++ ) {
if ( F_60 ( V_132 , V_15 ) ) {
V_130 ++ ;
V_15 = NULL ;
}
}
}
V_15 = NULL ;
if ( ! V_130 ) {
V_130 = V_24 -> error ;
if ( F_46 ( V_6 ) )
V_130 = - V_46 ;
}
if ( V_130 || V_84 )
break;
if ( V_54 && ! V_49 ) {
V_82 = F_47 ( * V_54 ) ;
V_49 = & V_82 ;
}
if ( ! F_26 ( V_24 , V_102 , V_49 , V_3 ) )
V_84 = 1 ;
}
return V_130 ;
}
int F_62 ( struct V_119 T_5 * V_135 , unsigned int V_127 ,
struct V_1 * V_54 )
{
struct V_13 V_19 ;
int V_136 = - V_109 , V_137 , V_134 , V_105 ;
long V_138 [ V_139 / sizeof( long ) ] ;
struct V_128 * const V_140 = (struct V_128 * ) V_138 ;
struct V_128 * V_131 = V_140 ;
unsigned long V_141 = V_127 ;
if ( V_127 > F_63 ( V_142 ) )
return - V_53 ;
V_134 = F_64 (unsigned int, nfds, N_STACK_PPS) ;
for (; ; ) {
V_131 -> V_32 = NULL ;
V_131 -> V_134 = V_134 ;
if ( ! V_134 )
break;
if ( F_56 ( V_131 -> V_31 , V_135 + V_127 - V_141 ,
sizeof( struct V_119 ) * V_131 -> V_134 ) )
goto V_143;
V_141 -= V_131 -> V_134 ;
if ( ! V_141 )
break;
V_134 = F_65 ( V_141 , V_144 ) ;
V_105 = sizeof( struct V_128 ) + sizeof( struct V_119 ) * V_134 ;
V_131 = V_131 -> V_32 = F_50 ( V_105 , V_35 ) ;
if ( ! V_131 ) {
V_136 = - V_36 ;
goto V_143;
}
}
F_7 ( & V_19 ) ;
V_137 = F_61 ( V_127 , V_140 , & V_19 , V_54 ) ;
F_12 ( & V_19 ) ;
for ( V_131 = V_140 ; V_131 ; V_131 = V_131 -> V_32 ) {
struct V_119 * V_65 = V_131 -> V_31 ;
int V_96 ;
for ( V_96 = 0 ; V_96 < V_131 -> V_134 ; V_96 ++ , V_135 ++ )
if ( F_66 ( V_65 [ V_96 ] . V_126 , & V_135 -> V_126 ) )
goto V_143;
}
V_136 = V_137 ;
V_143:
V_131 = V_140 -> V_32 ;
while ( V_131 ) {
struct V_128 * V_145 = V_131 ;
V_131 = V_131 -> V_32 ;
F_54 ( V_145 ) ;
}
return V_136 ;
}
static long F_67 ( struct V_146 * V_146 )
{
struct V_119 T_5 * V_135 = V_146 -> V_101 . V_135 ;
int V_127 = V_146 -> V_101 . V_127 ;
struct V_1 * V_49 = NULL , V_54 ;
int V_10 ;
if ( V_146 -> V_101 . V_147 ) {
V_54 . V_5 = V_146 -> V_101 . V_5 ;
V_54 . V_9 = V_146 -> V_101 . V_9 ;
V_49 = & V_54 ;
}
V_10 = F_62 ( V_135 , V_127 , V_49 ) ;
if ( V_10 == - V_46 ) {
V_146 -> V_148 = F_67 ;
V_10 = - V_149 ;
}
return V_10 ;
}
