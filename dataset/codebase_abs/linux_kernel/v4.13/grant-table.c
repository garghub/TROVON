static inline T_1 * F_1 ( T_1 V_1 )
{
return & V_2 [ ( V_1 ) / V_3 ] [ ( V_1 ) % V_3 ] ;
}
static int F_2 ( unsigned V_4 )
{
unsigned long V_5 ;
int V_6 , V_7 = 0 ;
T_1 V_8 ;
F_3 ( & V_9 , V_5 ) ;
if ( ( V_10 < V_4 ) &&
( ( V_7 = F_4 ( V_4 - V_10 ) ) < 0 ) ) {
F_5 ( & V_9 , V_5 ) ;
return V_7 ;
}
V_6 = V_8 = V_11 ;
V_10 -= V_4 ;
while ( V_4 -- > 1 )
V_8 = F_6 ( V_8 ) ;
V_11 = F_6 ( V_8 ) ;
F_6 ( V_8 ) = V_12 ;
F_5 ( & V_9 , V_5 ) ;
return V_6 ;
}
static void F_7 ( void )
{
struct V_13 * V_14 , * V_15 ;
V_14 = V_16 ;
V_16 = NULL ;
while ( V_14 != NULL ) {
V_15 = V_14 -> V_15 ;
if ( V_10 >= V_14 -> V_4 ) {
V_14 -> V_15 = NULL ;
V_14 -> V_17 ( V_14 -> V_18 ) ;
} else {
V_14 -> V_15 = V_16 ;
V_16 = V_14 ;
}
V_14 = V_15 ;
}
}
static inline void F_8 ( void )
{
if ( F_9 ( V_16 ) )
F_7 () ;
}
static void F_10 ( T_1 V_6 )
{
unsigned long V_5 ;
F_3 ( & V_9 , V_5 ) ;
F_6 ( V_6 ) = V_11 ;
V_11 = V_6 ;
V_10 ++ ;
F_8 () ;
F_5 ( & V_9 , V_5 ) ;
}
static void F_11 ( T_1 V_6 , T_2 V_19 ,
unsigned long V_20 , unsigned V_5 )
{
V_21 . V_22 [ V_6 ] . V_19 = V_19 ;
V_21 . V_22 [ V_6 ] . V_20 = V_20 ;
F_12 () ;
V_21 . V_22 [ V_6 ] . V_5 = V_5 ;
}
void F_13 ( T_1 V_6 , T_2 V_19 ,
unsigned long V_20 , int V_23 )
{
V_24 -> V_25 ( V_6 , V_19 , V_20 ,
V_26 | ( V_23 ? V_27 : 0 ) ) ;
}
int F_14 ( T_2 V_19 , unsigned long V_20 ,
int V_23 )
{
int V_6 ;
V_6 = F_2 ( 1 ) ;
if ( F_9 ( V_6 < 0 ) )
return - V_28 ;
F_13 ( V_6 , V_19 , V_20 , V_23 ) ;
return V_6 ;
}
static int F_15 ( T_1 V_6 )
{
return V_21 . V_22 [ V_6 ] . V_5 & ( V_29 | V_30 ) ;
}
int F_16 ( T_1 V_6 )
{
return V_24 -> V_31 ( V_6 ) ;
}
static int F_17 ( T_1 V_6 , int V_23 )
{
T_3 V_5 , V_32 ;
T_3 * V_33 ;
V_33 = & V_21 . V_22 [ V_6 ] . V_5 ;
V_32 = * V_33 ;
do {
V_5 = V_32 ;
if ( V_5 & ( V_29 | V_30 ) )
return 0 ;
} while ( ( V_32 = F_18 ( V_33 , V_5 , 0 ) ) != V_5 );
return 1 ;
}
static inline int F_19 ( T_1 V_6 , int V_23 )
{
return V_24 -> V_34 ( V_6 , V_23 ) ;
}
int F_20 ( T_1 V_6 , int V_23 )
{
if ( F_19 ( V_6 , V_23 ) )
return 1 ;
F_21 ( L_1 , V_6 ) ;
return 0 ;
}
static void F_22 ( unsigned long V_35 )
{
unsigned int V_36 = 10 ;
struct V_37 * V_38 = NULL ;
unsigned long V_5 ;
F_3 ( & V_9 , V_5 ) ;
while ( V_36 -- ) {
struct V_37 * V_1
= F_23 ( & V_39 ,
struct V_37 , V_40 ) ;
if ( V_1 == V_38 )
break;
F_24 ( & V_1 -> V_40 ) ;
F_5 ( & V_9 , V_5 ) ;
if ( F_19 ( V_1 -> V_6 , V_1 -> V_41 ) ) {
F_10 ( V_1 -> V_6 ) ;
if ( V_1 -> V_42 ) {
F_25 ( L_2 ,
V_1 -> V_6 , F_26 ( V_1 -> V_42 ) ) ;
F_27 ( V_1 -> V_42 ) ;
} else
F_28 ( L_3 , V_1 -> V_6 ) ;
F_29 ( V_1 ) ;
V_1 = NULL ;
} else {
if ( ! -- V_1 -> V_43 )
F_28 ( L_4 , V_1 -> V_6 ) ;
if ( ! V_38 )
V_38 = V_1 ;
}
F_3 ( & V_9 , V_5 ) ;
if ( V_1 )
F_30 ( & V_1 -> V_40 , & V_39 ) ;
else if ( F_31 ( & V_39 ) )
break;
}
if ( ! F_31 ( & V_39 ) && ! F_32 ( & V_44 ) ) {
V_44 . V_45 = V_46 + V_47 ;
F_33 ( & V_44 ) ;
}
F_5 ( & V_9 , V_5 ) ;
}
static void F_34 ( T_1 V_6 , bool V_23 ,
struct V_42 * V_42 )
{
struct V_37 * V_1 = F_35 ( sizeof( * V_1 ) , V_48 ) ;
const char * V_49 = V_50 L_5 ;
if ( V_1 ) {
unsigned long V_5 ;
V_1 -> V_6 = V_6 ;
V_1 -> V_41 = V_23 ;
V_1 -> V_42 = V_42 ;
V_1 -> V_43 = 60 ;
F_3 ( & V_9 , V_5 ) ;
F_30 ( & V_1 -> V_40 , & V_39 ) ;
if ( ! F_32 ( & V_44 ) ) {
V_44 . V_45 = V_46 + V_47 ;
F_33 ( & V_44 ) ;
}
F_5 ( & V_9 , V_5 ) ;
V_49 = V_51 L_6 ;
}
F_36 ( L_7 ,
V_49 , V_6 , V_42 ? F_26 ( V_42 ) : - 1 ) ;
}
void F_37 ( T_1 V_6 , int V_23 ,
unsigned long V_42 )
{
if ( F_20 ( V_6 , V_23 ) ) {
F_10 ( V_6 ) ;
if ( V_42 != 0 )
F_38 ( V_42 ) ;
} else
F_34 ( V_6 , V_23 ,
V_42 ? F_39 ( V_42 ) : NULL ) ;
}
int F_40 ( T_2 V_19 , unsigned long V_52 )
{
int V_6 ;
V_6 = F_2 ( 1 ) ;
if ( F_9 ( V_6 < 0 ) )
return - V_28 ;
F_41 ( V_6 , V_19 , V_52 ) ;
return V_6 ;
}
void F_41 ( T_1 V_6 , T_2 V_19 ,
unsigned long V_52 )
{
V_24 -> V_25 ( V_6 , V_19 , V_52 , V_53 ) ;
}
static unsigned long F_42 ( T_1 V_6 )
{
unsigned long V_20 ;
T_3 V_5 ;
T_3 * V_33 ;
V_33 = & V_21 . V_22 [ V_6 ] . V_5 ;
while ( ! ( ( V_5 = * V_33 ) & V_54 ) ) {
if ( F_18 ( V_33 , V_5 , 0 ) == V_5 )
return 0 ;
F_43 () ;
}
while ( ! ( V_5 & V_55 ) ) {
V_5 = * V_33 ;
F_43 () ;
}
F_44 () ;
V_20 = V_21 . V_22 [ V_6 ] . V_20 ;
F_45 ( V_20 == 0 ) ;
return V_20 ;
}
unsigned long F_46 ( T_1 V_6 )
{
return V_24 -> V_56 ( V_6 ) ;
}
unsigned long F_47 ( T_1 V_6 )
{
unsigned long V_20 = F_46 ( V_6 ) ;
F_10 ( V_6 ) ;
return V_20 ;
}
void F_48 ( T_1 V_6 )
{
F_10 ( V_6 ) ;
}
void F_49 ( T_1 V_8 )
{
T_1 V_6 ;
unsigned long V_5 ;
int V_4 = 1 ;
if ( V_8 == V_12 )
return;
F_3 ( & V_9 , V_5 ) ;
V_6 = V_8 ;
while ( F_6 ( V_6 ) != V_12 ) {
V_6 = F_6 ( V_6 ) ;
V_4 ++ ;
}
F_6 ( V_6 ) = V_11 ;
V_11 = V_8 ;
V_10 += V_4 ;
F_8 () ;
F_5 ( & V_9 , V_5 ) ;
}
int F_50 ( T_3 V_4 , T_1 * V_8 )
{
int V_57 = F_2 ( V_4 ) ;
if ( V_57 < 0 )
return - V_28 ;
* V_8 = V_57 ;
return 0 ;
}
int F_51 ( const T_1 * V_58 )
{
return ( * V_58 == V_12 ) ;
}
int F_52 ( T_1 * V_58 )
{
T_1 V_59 = * V_58 ;
if ( F_9 ( V_59 == V_12 ) )
return - V_28 ;
* V_58 = F_6 ( V_59 ) ;
return V_59 ;
}
void F_53 ( T_1 * V_58 ,
T_1 V_60 )
{
F_6 ( V_60 ) = * V_58 ;
* V_58 = V_60 ;
}
void F_54 ( struct V_13 * V_14 ,
void (* V_17)( void * ) , void * V_18 , T_3 V_4 )
{
unsigned long V_5 ;
struct V_13 * V_61 ;
F_3 ( & V_9 , V_5 ) ;
V_61 = V_16 ;
while ( V_61 ) {
if ( V_61 == V_14 )
goto V_62;
V_61 = V_61 -> V_15 ;
}
V_14 -> V_17 = V_17 ;
V_14 -> V_18 = V_18 ;
V_14 -> V_4 = V_4 ;
V_14 -> V_15 = V_16 ;
V_16 = V_14 ;
F_8 () ;
V_62:
F_5 ( & V_9 , V_5 ) ;
}
void F_55 ( struct V_13 * V_14 )
{
struct V_13 * * V_63 ;
unsigned long V_5 ;
F_3 ( & V_9 , V_5 ) ;
for ( V_63 = & V_16 ; * V_63 ; V_63 = & ( * V_63 ) -> V_15 ) {
if ( * V_63 == V_14 ) {
* V_63 = V_14 -> V_15 ;
break;
}
}
F_5 ( & V_9 , V_5 ) ;
}
static int F_56 ( unsigned int V_64 )
{
unsigned int V_65 , V_66 , V_67 ;
unsigned int V_68 , V_69 ;
F_45 ( V_70 == 0 ) ;
V_65 = V_71 + V_64 ;
V_66 = V_64 * V_70 ;
V_68 = ( V_71 * V_70 + V_3 - 1 ) / V_3 ;
V_69 =
( V_65 * V_70 + V_3 - 1 ) / V_3 ;
for ( V_67 = V_68 ; V_67 < V_69 ; V_67 ++ ) {
V_2 [ V_67 ] = ( T_1 * ) F_57 ( V_48 ) ;
if ( ! V_2 [ V_67 ] )
goto V_72;
}
for ( V_67 = V_70 * V_71 ;
V_67 < V_70 * V_65 - 1 ; V_67 ++ )
F_6 ( V_67 ) = V_67 + 1 ;
F_6 ( V_67 ) = V_11 ;
V_11 = V_70 * V_71 ;
V_10 += V_66 ;
V_71 = V_65 ;
F_8 () ;
return 0 ;
V_72:
while ( V_67 -- > V_68 )
F_38 ( ( unsigned long ) V_2 [ V_67 ] ) ;
return - V_73 ;
}
static unsigned int F_58 ( void )
{
struct V_74 V_75 ;
int V_7 ;
V_75 . V_76 = V_77 ;
V_7 = F_59 ( V_78 , & V_75 , 1 ) ;
if ( ( V_7 < 0 ) || ( V_75 . V_79 != V_80 ) )
return 4 ;
return V_75 . V_81 ;
}
unsigned int F_60 ( void )
{
unsigned int V_82 = F_58 () ;
static unsigned int V_83 ;
if ( ! V_83 )
V_83 = F_58 () ;
if ( V_82 > V_83 )
return V_83 ;
return V_82 ;
}
int F_61 ( T_4 V_84 )
{
T_5 * V_52 ;
unsigned int V_85 = F_58 () ;
unsigned int V_67 ;
void * V_86 ;
if ( V_87 . V_4 )
return - V_88 ;
V_86 = F_62 ( V_84 , V_89 * V_85 ) ;
if ( V_86 == NULL ) {
F_21 ( L_8 ,
& V_84 ) ;
return - V_73 ;
}
V_52 = F_63 ( V_85 , sizeof( V_52 [ 0 ] ) , V_90 ) ;
if ( ! V_52 ) {
F_64 ( V_86 ) ;
return - V_73 ;
}
for ( V_67 = 0 ; V_67 < V_85 ; V_67 ++ )
V_52 [ V_67 ] = F_65 ( V_84 ) + V_67 ;
V_87 . V_86 = V_86 ;
V_87 . V_52 = V_52 ;
V_87 . V_4 = V_85 ;
return 0 ;
}
void F_66 ( void )
{
if ( ! V_87 . V_4 )
return;
F_29 ( V_87 . V_52 ) ;
F_64 ( V_87 . V_86 ) ;
V_87 . V_52 = NULL ;
V_87 . V_4 = 0 ;
V_87 . V_86 = NULL ;
}
int F_67 ( int V_91 , struct V_42 * * V_92 )
{
int V_67 ;
int V_93 ;
V_93 = F_68 ( V_91 , V_92 ) ;
if ( V_93 < 0 )
return V_93 ;
for ( V_67 = 0 ; V_67 < V_91 ; V_67 ++ ) {
#if V_94 < 64
struct V_95 * V_96 ;
V_96 = F_69 ( sizeof( * V_96 ) , V_90 ) ;
if ( ! V_96 ) {
F_70 ( V_91 , V_92 ) ;
return - V_73 ;
}
F_71 ( V_92 [ V_67 ] , ( unsigned long ) V_96 ) ;
#endif
F_72 ( V_92 [ V_67 ] ) ;
}
return 0 ;
}
void F_70 ( int V_91 , struct V_42 * * V_92 )
{
int V_67 ;
for ( V_67 = 0 ; V_67 < V_91 ; V_67 ++ ) {
if ( F_73 ( V_92 [ V_67 ] ) ) {
#if V_94 < 64
F_29 ( ( void * ) F_74 ( V_92 [ V_67 ] ) ) ;
#endif
F_75 ( V_92 [ V_67 ] ) ;
}
}
F_76 ( V_91 , V_92 ) ;
}
static inline void
F_77 ( unsigned int V_97 , void * V_98 , T_6 * V_79 ,
const char * V_99 )
{
unsigned V_100 = 1 ;
do {
F_45 ( F_59 ( V_97 , V_98 , 1 ) ) ;
if ( * V_79 == V_101 )
F_78 ( V_100 ++ ) ;
} while ( ( * V_79 == V_101 ) && ( V_100 < V_102 ) );
if ( V_100 >= V_102 ) {
F_79 ( L_9 , V_99 , V_103 -> V_104 ) ;
* V_79 = V_105 ;
}
}
void F_80 ( struct V_106 * V_107 , unsigned V_4 )
{
struct V_106 * V_108 ;
if ( F_59 ( V_109 , V_107 , V_4 ) )
F_81 () ;
for ( V_108 = V_107 ; V_108 < V_107 + V_4 ; V_108 ++ )
if ( V_108 -> V_79 == V_101 )
F_77 ( V_109 , V_108 ,
& V_108 -> V_79 , V_110 ) ;
}
void F_82 ( struct V_111 * V_107 , unsigned V_4 )
{
struct V_111 * V_108 ;
if ( F_59 ( V_112 , V_107 , V_4 ) )
F_81 () ;
for ( V_108 = V_107 ; V_108 < V_107 + V_4 ; V_108 ++ )
if ( V_108 -> V_79 == V_101 )
F_77 ( V_112 , V_108 ,
& V_108 -> V_79 , V_110 ) ;
}
void F_83 ( struct V_42 * V_42 ,
unsigned int V_113 ,
unsigned int V_114 ,
T_7 V_17 ,
void * V_115 )
{
unsigned int V_116 ;
unsigned int V_117 ;
unsigned long V_118 ;
V_114 = F_84 (unsigned int, PAGE_SIZE - offset, len) ;
V_116 = F_85 ( V_113 ) ;
V_118 = F_86 ( V_42 ) + F_65 ( V_113 ) ;
while ( V_114 ) {
V_117 = F_84 (unsigned int, XEN_PAGE_SIZE - goffset, len) ;
V_17 ( F_87 ( V_118 ) , V_116 , V_117 , V_115 ) ;
V_116 = 0 ;
V_118 ++ ;
V_114 -= V_117 ;
}
}
void F_88 ( struct V_42 * * V_92 ,
unsigned int V_119 ,
T_7 V_17 ,
void * V_115 )
{
unsigned int V_116 = 0 ;
unsigned long V_118 = 0 ;
unsigned int V_67 ;
for ( V_67 = 0 ; V_67 < V_119 ; V_67 ++ ) {
if ( ( V_67 % V_120 ) == 0 ) {
V_118 = F_86 ( V_92 [ V_67 / V_120 ] ) ;
V_116 = 0 ;
}
V_17 ( F_87 ( V_118 ) , V_116 , V_89 , V_115 ) ;
V_116 += V_89 ;
V_118 ++ ;
}
}
int F_89 ( struct V_106 * V_121 ,
struct V_106 * V_122 ,
struct V_42 * * V_92 , unsigned int V_4 )
{
int V_67 , V_93 ;
V_93 = F_59 ( V_109 , V_121 , V_4 ) ;
if ( V_93 )
return V_93 ;
for ( V_67 = 0 ; V_67 < V_4 ; V_67 ++ ) {
if ( V_121 [ V_67 ] . V_79 == V_101 )
F_77 ( V_109 , V_121 + V_67 ,
& V_121 [ V_67 ] . V_79 , V_110 ) ;
if ( V_121 [ V_67 ] . V_79 == V_80 ) {
struct V_95 * V_96 ;
F_90 ( V_92 [ V_67 ] ) ;
V_96 = V_95 ( V_92 [ V_67 ] ) ;
V_96 -> V_19 = V_121 [ V_67 ] . V_76 ;
V_96 -> V_123 = V_121 [ V_67 ] . V_6 ;
}
}
return F_91 ( V_121 , V_122 , V_92 , V_4 ) ;
}
int F_92 ( struct V_124 * V_125 ,
struct V_124 * V_126 ,
struct V_42 * * V_92 , unsigned int V_4 )
{
unsigned int V_67 ;
int V_93 ;
V_93 = F_59 ( V_127 , V_125 , V_4 ) ;
if ( V_93 )
return V_93 ;
for ( V_67 = 0 ; V_67 < V_4 ; V_67 ++ )
F_93 ( V_92 [ V_67 ] ) ;
return F_94 ( V_125 , V_126 , V_92 , V_4 ) ;
}
static void F_95 ( struct V_128 * V_129 )
{
struct V_130
* V_131 = F_96 ( V_129 ,
struct V_130 ,
V_132 . V_129 ) ;
if ( V_131 -> V_133 != V_134 )
V_131 -> V_133 ++ ;
F_97 ( V_131 ) ;
}
static void F_97 ( struct V_130 * V_135 )
{
int V_93 ;
int V_136 ;
for ( V_136 = 0 ; V_136 < V_135 -> V_4 ; V_136 ++ ) {
if ( F_98 ( V_135 -> V_92 [ V_136 ] ) > 1 ) {
unsigned long V_100 = V_137 * ( V_135 -> V_133 + 1 ) ;
F_99 ( & V_135 -> V_132 ,
F_100 ( V_100 ) ) ;
return;
}
}
V_93 = F_92 ( V_135 -> V_125 , V_135 -> V_126 ,
V_135 -> V_92 , V_135 -> V_4 ) ;
V_135 -> V_138 ( V_93 , V_135 ) ;
}
void F_101 ( struct V_130 * V_135 )
{
F_102 ( & V_135 -> V_132 , F_95 ) ;
V_135 -> V_133 = 0 ;
F_97 ( V_135 ) ;
}
static void F_103 ( int V_139 ,
struct V_130 * V_115 )
{
struct V_140 * V_141 = V_115 -> V_115 ;
V_141 -> V_139 = V_139 ;
F_104 ( & V_141 -> V_142 ) ;
}
int F_105 ( struct V_130 * V_135 )
{
struct V_140 V_115 ;
F_106 ( & V_115 . V_142 ) ;
V_135 -> V_115 = & V_115 ;
V_135 -> V_138 = & F_103 ;
F_101 ( V_135 ) ;
F_107 ( & V_115 . V_142 ) ;
return V_115 . V_139 ;
}
static int F_108 ( T_5 * V_143 , unsigned int V_144 )
{
int V_7 ;
V_7 = F_109 ( V_143 , V_144 ,
F_60 () ,
& V_21 . V_84 ) ;
F_45 ( V_7 ) ;
return 0 ;
}
static void F_110 ( void )
{
F_111 ( V_21 . V_84 , V_71 ) ;
}
static int F_112 ( unsigned int V_145 , unsigned int V_146 )
{
struct V_147 V_148 ;
T_5 * V_143 ;
unsigned int V_144 = V_146 + 1 ;
int V_7 ;
if ( F_113 ( V_149 ) ) {
struct V_150 V_151 ;
unsigned int V_67 = V_146 ;
V_7 = 0 ;
F_45 ( V_87 . V_4 < V_144 ) ;
do {
V_151 . V_19 = V_77 ;
V_151 . V_152 = V_67 ;
V_151 . V_153 = V_154 ;
V_151 . V_155 = V_87 . V_52 [ V_67 ] ;
V_7 = F_114 ( V_156 , & V_151 ) ;
if ( V_7 != 0 ) {
F_21 ( L_10 ,
V_7 ) ;
break;
}
} while ( V_67 -- > V_145 );
return V_7 ;
}
V_143 = F_35 ( V_144 * sizeof( unsigned long ) , V_48 ) ;
if ( ! V_143 )
return - V_73 ;
V_148 . V_76 = V_77 ;
V_148 . V_157 = V_144 ;
F_115 ( V_148 . V_158 , V_143 ) ;
V_7 = F_59 ( V_159 , & V_148 , 1 ) ;
if ( V_7 == - V_160 ) {
F_29 ( V_143 ) ;
return - V_160 ;
}
F_45 ( V_7 || V_148 . V_79 ) ;
V_7 = V_24 -> V_161 ( V_143 , V_144 ) ;
F_29 ( V_143 ) ;
return V_7 ;
}
static void F_116 ( void )
{
V_162 = 1 ;
V_70 = V_89 / sizeof( struct V_163 ) ;
V_24 = & V_164 ;
F_28 ( L_11 , V_162 ) ;
}
static int F_117 ( void )
{
unsigned int V_85 ;
V_85 = F_60 () ;
if ( V_85 < V_71 )
return - V_160 ;
if ( F_113 ( V_149 ) && V_21 . V_84 == NULL ) {
V_21 . V_84 = V_87 . V_86 ;
if ( V_21 . V_84 == NULL ) {
F_21 ( L_12 ,
( unsigned long ) V_87 . V_86 ) ;
return - V_73 ;
}
}
return F_112 ( 0 , V_71 - 1 ) ;
}
int F_118 ( void )
{
F_116 () ;
return F_117 () ;
}
int F_119 ( void )
{
if ( ! F_113 ( V_149 ) )
V_24 -> V_165 () ;
return 0 ;
}
static int F_4 ( unsigned int V_166 )
{
int V_7 ;
unsigned int V_167 , V_168 ;
F_45 ( V_70 == 0 ) ;
V_167 = V_71 ;
V_168 = ( ( V_166 + ( V_70 - 1 ) ) /
V_70 ) ;
if ( V_167 + V_168 > F_60 () ) {
F_120 ( L_13
L_14
L_15 ,
V_167 , V_168 , F_60 () ,
V_10 , V_166 ) ;
return - V_28 ;
}
V_7 = F_112 ( V_167 , V_167 + V_168 - 1 ) ;
if ( V_7 == 0 )
V_7 = F_56 ( V_168 ) ;
return V_7 ;
}
int F_121 ( void )
{
int V_67 ;
unsigned long V_169 ;
unsigned int V_170 , V_68 ;
unsigned int V_171 ;
int V_93 ;
F_116 () ;
V_169 = F_60 () ;
V_71 = 1 ;
F_45 ( V_70 == 0 ) ;
V_170 = ( V_169 *
V_70 / V_3 ) ;
V_2 = F_35 ( V_170 * sizeof( T_1 * ) ,
V_90 ) ;
if ( V_2 == NULL )
return - V_73 ;
V_68 = ( V_71 * V_70 + V_3 - 1 ) / V_3 ;
for ( V_67 = 0 ; V_67 < V_68 ; V_67 ++ ) {
V_2 [ V_67 ] = ( T_1 * ) F_57 ( V_90 ) ;
if ( V_2 [ V_67 ] == NULL ) {
V_93 = - V_73 ;
goto V_172;
}
}
V_93 = F_122 ( V_169 ) ;
if ( V_93 < 0 )
goto V_172;
if ( F_117 () < 0 ) {
V_93 = - V_173 ;
goto V_172;
}
V_171 = V_71 * V_70 ;
for ( V_67 = V_174 ; V_67 < V_171 - 1 ; V_67 ++ )
F_6 ( V_67 ) = V_67 + 1 ;
F_6 ( V_171 - 1 ) = V_12 ;
V_10 = V_171 - V_174 ;
V_11 = V_174 ;
F_36 ( L_16 ) ;
return 0 ;
V_172:
for ( V_67 -- ; V_67 >= 0 ; V_67 -- )
F_38 ( ( unsigned long ) V_2 [ V_67 ] ) ;
F_29 ( V_2 ) ;
return V_93 ;
}
static int F_123 ( void )
{
if ( ! F_124 () )
return - V_173 ;
if ( F_125 () && ! F_126 () )
return 0 ;
return F_121 () ;
}
