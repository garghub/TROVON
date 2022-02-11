void F_1 ( struct V_1 * V_2 )
{
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_3 = V_2 -> V_4 = F_2 () ;
F_3 ( V_2 -> V_5 ) ;
V_2 -> time = F_4 () ;
V_2 -> V_6 = V_7 . V_8 ;
V_2 -> V_9 = F_5 ( 1 ) ;
V_2 -> V_10 = F_6 ( V_2 -> V_4 ) . V_11 ;
V_2 -> V_12 = F_6 ( V_2 -> V_4 ) . V_13 ;
F_7 ( V_14 , V_2 -> V_15 ) ;
}
void F_8 ( struct V_1 * V_1 )
{
unsigned V_16 , V_17 ;
int V_18 = 0 ;
F_9 ( V_1 ) ;
V_18 = F_10 ( & V_19 , 0 , V_1 ) ;
if ( V_18 == V_20 )
return;
V_1 -> V_21 = 0 ;
F_11 () ;
for (; ; ) {
V_17 = F_12 ( V_22 . V_16 ) ;
for (; ; ) {
if ( V_17 >= V_23 ) {
F_13 ( V_24 ,
( unsigned long * ) & V_22 . V_25 ) ;
return;
}
if ( V_22 . V_17 [ V_17 ] . V_21 ) {
V_17 ++ ;
continue;
}
break;
}
F_14 () ;
V_16 = V_17 + 1 ;
if ( F_15 ( & V_22 . V_16 , V_17 , V_16 ) == V_17 )
break;
}
memcpy ( V_22 . V_17 + V_17 , V_1 , sizeof( struct V_1 ) ) ;
F_11 () ;
V_22 . V_17 [ V_17 ] . V_21 = 1 ;
F_11 () ;
V_1 -> V_21 = 1 ;
F_13 ( 0 , & V_26 ) ;
}
static void F_16 ( void )
{
unsigned int V_16 , V_27 , V_28 = 0 ;
V_16 = F_17 ( V_22 . V_16 ) ;
do {
struct V_1 * V_2 ;
for ( V_27 = V_28 ; V_27 < V_16 ; V_27 ++ ) {
unsigned long V_29 = V_30 ;
unsigned V_31 = 1 ;
V_2 = & V_22 . V_17 [ V_27 ] ;
while ( ! V_2 -> V_21 ) {
if ( F_18 ( V_30 , V_29 + 2 * V_31 ) )
V_31 ++ ;
F_19 () ;
if ( ! V_2 -> V_21 && V_31 >= 4 ) {
F_20 ( L_1 ) ;
break;
}
}
F_14 () ;
F_10 ( & V_19 , 0 , V_2 ) ;
}
memset ( V_22 . V_17 + V_28 , 0 , ( V_16 - V_28 ) * sizeof( * V_2 ) ) ;
V_28 = V_16 ;
V_16 = F_15 ( & V_22 . V_16 , V_28 , 0 ) ;
} while ( V_16 != V_28 );
}
void F_21 ( struct V_32 * V_33 )
{
F_22 ( & V_19 , V_33 ) ;
F_16 () ;
}
void F_23 ( struct V_32 * V_33 )
{
F_24 ( & V_19 , V_33 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
int V_18 = 0 ;
F_26 ( V_34 L_2 ,
V_2 -> V_4 , V_2 -> V_35 , V_2 -> V_36 , V_2 -> V_37 ) ;
if ( V_2 -> V_38 ) {
F_26 ( V_34 L_3 ,
! ( V_2 -> V_35 & V_39 ) ? L_4 : L_5 ,
V_2 -> V_40 , V_2 -> V_38 ) ;
if ( V_2 -> V_40 == V_41 )
F_27 ( L_6 , V_2 -> V_38 ) ;
F_28 ( L_7 ) ;
}
F_26 ( V_34 L_8 , V_2 -> V_5 ) ;
if ( V_2 -> V_42 )
F_28 ( L_9 , V_2 -> V_42 ) ;
if ( V_2 -> V_43 )
F_28 ( L_10 , V_2 -> V_43 ) ;
F_28 ( L_7 ) ;
F_26 ( V_34 L_11 ,
V_2 -> V_6 , V_2 -> V_9 , V_2 -> time , V_2 -> V_10 , V_2 -> V_12 ,
F_6 ( V_2 -> V_4 ) . V_44 ) ;
V_18 = F_10 ( & V_19 , 0 , V_2 ) ;
if ( V_18 == V_20 )
return;
F_29 ( V_34 L_12 ) ;
}
static void F_30 ( void )
{
long V_45 = V_46 * V_47 ;
F_31 () ;
F_32 () ;
while ( V_45 -- > 0 )
F_33 ( 1 ) ;
if ( V_48 == 0 )
V_48 = V_49 ;
F_34 ( L_13 ) ;
}
static void F_35 ( char * V_50 , struct V_1 * V_51 , char * exp )
{
int V_27 , V_52 = 0 ;
if ( ! V_53 ) {
if ( F_36 ( & V_54 ) > 1 )
F_30 () ;
F_37 () ;
F_38 ( 1 ) ;
F_39 () ;
} else {
if ( F_36 ( & V_55 ) > 1 )
return;
}
for ( V_27 = 0 ; V_27 < V_23 ; V_27 ++ ) {
struct V_1 * V_2 = & V_22 . V_17 [ V_27 ] ;
if ( ! ( V_2 -> V_37 & V_56 ) )
continue;
if ( ! ( V_2 -> V_37 & V_57 ) ) {
F_25 ( V_2 ) ;
if ( ! V_52 )
V_52 = F_40 ( V_2 ) ;
}
}
for ( V_27 = 0 ; V_27 < V_23 ; V_27 ++ ) {
struct V_1 * V_2 = & V_22 . V_17 [ V_27 ] ;
if ( ! ( V_2 -> V_37 & V_56 ) )
continue;
if ( ! ( V_2 -> V_37 & V_57 ) )
continue;
if ( ! V_51 || memcmp ( V_2 , V_51 , sizeof( struct V_1 ) ) ) {
F_25 ( V_2 ) ;
if ( ! V_52 )
V_52 = F_40 ( V_2 ) ;
}
}
if ( V_51 ) {
F_25 ( V_51 ) ;
if ( ! V_52 )
V_52 = F_40 ( V_51 ) ;
}
if ( V_58 )
F_26 ( V_34 L_14 ) ;
if ( exp )
F_26 ( V_34 L_15 , exp ) ;
if ( ! V_53 ) {
if ( V_48 == 0 )
V_48 = V_49 ;
F_34 ( V_50 ) ;
} else
F_26 ( V_34 L_16 , V_50 ) ;
}
static int F_41 ( T_1 V_59 )
{
unsigned V_36 = F_42 ( V_60 . V_36 ) ;
if ( V_59 == V_61 )
return F_43 ( struct V_1 , V_38 ) ;
if ( V_59 == F_44 ( V_36 ) )
return F_43 ( struct V_1 , V_37 ) ;
if ( V_59 == F_45 ( V_36 ) )
return F_43 ( struct V_1 , V_42 ) ;
if ( V_59 == F_46 ( V_36 ) )
return F_43 ( struct V_1 , V_43 ) ;
if ( V_59 == V_62 )
return F_43 ( struct V_1 , V_35 ) ;
return - 1 ;
}
static T_2 F_47 ( T_1 V_59 )
{
T_2 V_63 ;
if ( F_42 ( V_60 . V_21 ) ) {
int V_64 = F_41 ( V_59 ) ;
if ( V_64 < 0 )
return 0 ;
return * ( T_2 * ) ( ( char * ) & F_48 ( V_60 ) + V_64 ) ;
}
if ( F_49 ( V_59 , & V_63 ) ) {
F_50 ( 1 , L_17 , V_59 ) ;
V_63 = 0 ;
}
return V_63 ;
}
static void F_51 ( T_1 V_59 , T_2 V_63 )
{
if ( F_42 ( V_60 . V_21 ) ) {
int V_64 = F_41 ( V_59 ) ;
if ( V_64 >= 0 )
* ( T_2 * ) ( ( char * ) & F_48 ( V_60 ) + V_64 ) = V_63 ;
return;
}
F_52 ( V_59 , V_63 ) ;
}
static inline void F_53 ( struct V_1 * V_2 , struct V_65 * V_66 )
{
F_1 ( V_2 ) ;
V_2 -> V_35 = F_47 ( V_62 ) ;
if ( V_66 ) {
if ( V_2 -> V_35 & ( V_67 | V_39 ) ) {
V_2 -> V_38 = V_66 -> V_38 ;
V_2 -> V_40 = V_66 -> V_40 ;
if ( F_54 ( V_66 ) )
V_2 -> V_40 |= 3 ;
}
if ( V_61 )
V_2 -> V_38 = F_47 ( V_61 ) ;
}
}
static int F_55 ( void )
{
struct V_68 * V_69 = & F_48 ( V_68 ) ;
return V_69 -> V_29 == V_69 -> V_70 ;
}
static int F_56 ( unsigned long * V_71 )
{
struct V_68 * V_69 ;
int V_18 = 0 ;
* V_71 = 0 ;
F_57 () ;
V_69 = & F_48 ( V_68 ) ;
if ( V_69 -> V_29 == V_69 -> V_70 )
goto V_72;
* V_71 = V_69 -> V_73 [ V_69 -> V_29 ] ;
V_69 -> V_29 = ( V_69 -> V_29 + 1 ) % V_74 ;
V_18 = 1 ;
V_72:
F_58 () ;
return V_18 ;
}
static int F_59 ( unsigned long V_71 )
{
struct V_68 * V_69 = & F_48 ( V_68 ) ;
unsigned V_16 ;
V_16 = ( V_69 -> V_70 + 1 ) % V_74 ;
if ( V_16 == V_69 -> V_29 )
return - 1 ;
V_69 -> V_73 [ V_69 -> V_70 ] = V_71 ;
F_11 () ;
V_69 -> V_70 = V_16 ;
return 0 ;
}
int F_60 ( struct V_75 * V_76 )
{
if ( V_77 )
return 0 ;
return F_61 ( V_76 , V_78 ) && F_61 ( V_76 , V_79 ) ;
}
static void F_62 ( void )
{
if ( ! F_55 () ) {
struct V_80 * V_81 = & F_48 ( V_82 ) ;
if ( ! F_63 ( V_81 ) )
F_64 ( V_81 ) ;
}
}
static void F_65 ( struct V_83 * V_17 )
{
F_66 () ;
F_62 () ;
}
static void F_67 ( struct V_65 * V_66 )
{
if ( V_66 -> V_25 & ( V_84 | V_85 ) ) {
F_66 () ;
F_62 () ;
return;
}
F_68 ( & F_48 ( V_86 ) ) ;
}
static void F_69 ( struct V_1 * V_2 , int V_27 )
{
if ( V_2 -> V_37 & V_87 )
V_2 -> V_43 = F_47 ( F_46 ( V_27 ) ) ;
if ( V_2 -> V_37 & V_88 ) {
V_2 -> V_42 = F_47 ( F_45 ( V_27 ) ) ;
if ( V_89 && ( V_2 -> V_37 & V_87 ) ) {
T_3 V_90 = F_70 ( V_2 -> V_43 ) ;
V_2 -> V_42 >>= V_90 ;
V_2 -> V_42 <<= V_90 ;
}
}
}
void F_71 ( enum V_91 V_25 , T_4 * V_92 )
{
struct V_1 V_2 ;
int V_27 ;
F_72 ( V_93 ) ;
F_53 ( & V_2 , NULL ) ;
for ( V_27 = 0 ; V_27 < V_94 ; V_27 ++ ) {
if ( ! V_95 [ V_27 ] . V_96 || ! F_73 ( V_27 , * V_92 ) )
continue;
V_2 . V_43 = 0 ;
V_2 . V_42 = 0 ;
V_2 . V_36 = V_27 ;
V_2 . V_5 = 0 ;
F_37 () ;
V_2 . V_37 = F_47 ( F_44 ( V_27 ) ) ;
if ( ! ( V_2 . V_37 & V_56 ) )
continue;
if ( ! ( V_25 & V_97 ) &&
( V_2 . V_37 & ( V_89 ? V_98 : V_57 ) ) )
continue;
F_69 ( & V_2 , V_27 ) ;
if ( ! ( V_25 & V_99 ) )
V_2 . V_5 = 0 ;
if ( ! ( V_25 & V_100 ) && ! V_101 )
F_8 ( & V_2 ) ;
F_51 ( F_44 ( V_27 ) , 0 ) ;
}
F_74 () ;
}
static int F_75 ( struct V_1 * V_2 , char * * V_50 , unsigned long * V_102 )
{
int V_27 , V_18 = 0 ;
for ( V_27 = 0 ; V_27 < V_94 ; V_27 ++ ) {
V_2 -> V_37 = F_47 ( F_44 ( V_27 ) ) ;
if ( V_2 -> V_37 & V_56 )
F_76 ( V_27 , V_102 ) ;
if ( F_77 ( V_2 , V_103 , V_50 ) >= V_104 )
V_18 = 1 ;
}
return V_18 ;
}
static int F_78 ( T_2 * V_105 )
{
F_79 () ;
if ( F_80 ( & V_54 ) )
F_30 () ;
if ( ! V_106 )
goto V_72;
if ( ( V_107 ) * V_105 < V_108 ) {
if ( V_103 < 1 )
F_35 ( L_18 ,
NULL , NULL ) ;
V_58 = 1 ;
return 1 ;
}
* V_105 -= V_108 ;
V_72:
F_81 () ;
return 0 ;
}
static void F_82 ( void )
{
int V_3 ;
struct V_1 * V_2 = NULL ;
int V_109 = 0 ;
char * V_50 = NULL ;
char * V_110 = NULL ;
F_83 (cpu) {
int V_111 = F_77 ( & F_84 ( V_112 , V_3 ) , V_103 ,
& V_110 ) ;
if ( V_111 > V_109 ) {
V_50 = V_110 ;
V_109 = V_111 ;
V_2 = & F_84 ( V_112 , V_3 ) ;
}
}
if ( V_2 && V_109 >= V_104 && V_103 < 3 )
F_35 ( L_19 , V_2 , V_50 ) ;
if ( V_109 <= V_113 && V_103 < 3 )
F_35 ( L_20 , NULL , NULL ) ;
F_83 (cpu)
memset ( & F_84 ( V_112 , V_3 ) , 0 , sizeof( struct V_1 ) ) ;
}
static int F_85 ( int * V_114 )
{
int V_115 ;
int V_116 = F_86 () ;
T_2 V_45 = ( T_2 ) V_106 * V_117 ;
if ( ! V_45 )
return - 1 ;
F_87 ( * V_114 , & V_118 ) ;
F_88 () ;
V_115 = F_36 ( & V_119 ) ;
while ( F_80 ( & V_119 ) != V_116 ) {
if ( F_78 ( & V_45 ) ) {
F_89 ( & V_118 , 0 ) ;
return - 1 ;
}
F_90 ( V_108 ) ;
}
F_14 () ;
if ( V_115 == 1 ) {
F_89 ( & V_120 , 1 ) ;
} else {
while ( F_80 ( & V_120 ) < V_115 ) {
if ( F_78 ( & V_45 ) ) {
F_89 ( & V_118 , 0 ) ;
return - 1 ;
}
F_90 ( V_108 ) ;
}
}
* V_114 = F_80 ( & V_118 ) ;
return V_115 ;
}
static int F_91 ( int V_115 )
{
int V_18 = - 1 ;
T_2 V_45 = ( T_2 ) V_106 * V_117 ;
if ( ! V_45 )
goto V_121;
if ( V_115 < 0 )
goto V_121;
F_92 ( & V_120 ) ;
if ( V_115 == 1 ) {
int V_116 = F_86 () ;
while ( F_80 ( & V_120 ) <= V_116 ) {
if ( F_78 ( & V_45 ) )
goto V_121;
F_90 ( V_108 ) ;
}
F_82 () ;
F_37 () ;
V_18 = 0 ;
} else {
while ( F_80 ( & V_120 ) != 0 ) {
if ( F_78 ( & V_45 ) )
goto V_121;
F_90 ( V_108 ) ;
}
return 0 ;
}
V_121:
F_89 ( & V_118 , 0 ) ;
F_89 ( & V_119 , 0 ) ;
F_37 () ;
F_89 ( & V_120 , 0 ) ;
return V_18 ;
}
static int F_93 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_37 & V_87 ) || ! ( V_2 -> V_37 & V_88 ) )
return 0 ;
if ( F_70 ( V_2 -> V_43 ) > V_122 )
return 0 ;
if ( F_94 ( V_2 -> V_43 ) != V_123 )
return 0 ;
return 1 ;
}
static void F_95 ( unsigned long * V_124 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_94 ; V_27 ++ ) {
if ( F_73 ( V_27 , V_124 ) )
F_51 ( F_44 ( V_27 ) , 0 ) ;
}
}
static void F_96 ( T_5 V_42 , int V_76 )
{
struct V_125 * V_126 ;
for ( V_126 = V_125 ; V_126 < & V_125 [ V_127 ] ; V_126 ++ ) {
if ( F_97 ( & V_126 -> V_128 , 0 , 1 ) == 0 ) {
V_126 -> V_105 = V_129 ;
V_126 -> V_130 = V_42 ;
V_126 -> V_131 = V_76 ;
return;
}
}
F_35 ( L_21 , NULL , NULL ) ;
}
static struct V_125 * F_98 ( void )
{
struct V_125 * V_126 ;
for ( V_126 = V_125 ; V_126 < & V_125 [ V_127 ] ; V_126 ++ )
if ( F_80 ( & V_126 -> V_128 ) && V_126 -> V_105 == V_129 )
return V_126 ;
return NULL ;
}
static void F_99 ( struct V_125 * V_126 )
{
F_89 ( & V_126 -> V_128 , 0 ) ;
}
void F_100 ( struct V_65 * V_66 , long V_132 )
{
struct V_1 V_2 , * V_51 ;
int V_27 ;
int V_133 = 0 ;
int V_111 ;
int V_115 ;
int V_114 = 0 ;
int V_134 = 0 ;
F_101 ( V_124 , V_135 ) ;
F_101 ( V_136 , V_135 ) ;
char * V_50 = L_22 ;
F_92 ( & V_137 ) ;
F_72 ( V_138 ) ;
if ( ! V_94 )
goto V_72;
F_53 ( & V_2 , V_66 ) ;
V_51 = & F_48 ( V_112 ) ;
* V_51 = V_2 ;
memset ( V_136 , 0 , sizeof( V_136 ) ) ;
V_114 = F_75 ( & V_2 , & V_50 , V_136 ) ;
F_37 () ;
if ( ! ( V_2 . V_35 & V_67 ) )
V_134 = 1 ;
V_115 = F_85 ( & V_114 ) ;
for ( V_27 = 0 ; V_27 < V_94 ; V_27 ++ ) {
F_102 ( V_27 , V_124 ) ;
if ( ! F_73 ( V_27 , V_136 ) )
continue;
if ( ! V_95 [ V_27 ] . V_96 )
continue;
V_2 . V_43 = 0 ;
V_2 . V_42 = 0 ;
V_2 . V_36 = V_27 ;
V_2 . V_37 = F_47 ( F_44 ( V_27 ) ) ;
if ( ( V_2 . V_37 & V_56 ) == 0 )
continue;
if ( ! ( V_2 . V_37 & ( V_89 ? V_98 : V_57 ) ) &&
! V_114 )
continue;
F_103 ( V_139 ) ;
V_111 = F_77 ( & V_2 , V_103 , NULL ) ;
if ( V_111 == V_113 && ! V_114 )
continue;
F_76 ( V_27 , V_124 ) ;
if ( V_111 == V_140 ) {
continue;
}
F_69 ( & V_2 , V_27 ) ;
if ( V_111 == V_141 && F_93 ( & V_2 ) )
F_59 ( V_2 . V_42 >> V_122 ) ;
F_8 ( & V_2 ) ;
if ( V_111 > V_133 ) {
* V_51 = V_2 ;
V_133 = V_111 ;
}
}
V_2 = * V_51 ;
if ( ! V_114 )
F_95 ( V_124 ) ;
if ( F_91 ( V_115 ) < 0 )
V_114 = V_133 >= V_104 ;
if ( V_103 < 3 ) {
if ( V_114 )
F_35 ( L_23 , & V_2 , V_50 ) ;
if ( V_133 == V_142 ) {
F_96 ( V_2 . V_42 , V_2 . V_35 & V_67 ) ;
F_104 ( V_143 ) ;
} else if ( V_134 ) {
F_105 ( V_144 , V_129 ) ;
}
}
if ( V_133 > 0 )
F_67 ( V_66 ) ;
F_51 ( V_62 , 0 ) ;
V_72:
F_106 ( & V_137 ) ;
F_74 () ;
}
int F_107 ( unsigned long V_71 , int V_145 , int V_25 )
{
F_108 ( V_25 & V_146 ) ;
F_109 ( V_147 L_24
L_25 , V_71 ) ;
return 0 ;
}
void F_110 ( void )
{
unsigned long V_71 ;
struct V_125 * V_126 = F_98 () ;
if ( ! V_126 )
F_35 ( L_26 , NULL , NULL ) ;
V_71 = V_126 -> V_130 >> V_122 ;
F_111 ( V_143 ) ;
F_20 ( L_27 ,
V_126 -> V_130 ) ;
if ( F_107 ( V_71 , V_148 , V_146 ) < 0 ||
V_126 -> V_131 == 0 ) {
F_20 ( L_28 ) ;
F_105 ( V_144 , V_129 ) ;
}
F_99 ( V_126 ) ;
}
static void F_112 ( struct V_80 * V_149 )
{
unsigned long V_71 ;
while ( F_56 ( & V_71 ) )
F_107 ( V_71 , V_148 , 0 ) ;
}
void F_113 ( T_5 V_37 )
{
struct V_1 V_2 ;
F_1 ( & V_2 ) ;
V_2 . V_36 = V_150 ;
V_2 . V_37 = V_37 ;
F_8 ( & V_2 ) ;
}
static void F_114 ( unsigned long V_151 )
{
struct V_152 * V_105 = & F_48 ( V_153 ) ;
unsigned long V_154 ;
F_115 ( F_2 () != V_151 ) ;
if ( F_60 ( F_116 ( & V_155 ) ) ) {
F_71 ( V_99 ,
& F_48 ( V_156 ) ) ;
}
V_154 = F_42 ( V_157 ) ;
if ( F_66 () )
V_154 = F_117 ( V_154 / 2 , ( unsigned long ) V_158 / 100 ) ;
else
V_154 = F_118 ( V_154 * 2 , F_119 ( V_159 * V_158 ) ) ;
F_120 ( V_157 , V_154 ) ;
V_105 -> V_160 = V_30 + V_154 ;
F_121 ( V_105 , F_2 () ) ;
}
static void F_122 ( void )
{
int V_3 ;
F_123 (cpu)
F_124 ( & F_84 ( V_153 , V_3 ) ) ;
}
static void F_125 ( struct V_80 * V_81 )
{
F_126 ( V_161 , V_162 , NULL , V_163 ) ;
}
int F_66 ( void )
{
static F_127 ( V_164 , 60 * V_158 , 2 ) ;
if ( F_128 ( 0 , & V_26 ) ) {
F_129 ( & V_165 ) ;
if ( V_161 [ 0 ] && ! F_63 ( & V_166 ) )
F_64 ( & V_166 ) ;
if ( F_130 ( & V_164 ) )
F_131 ( V_34 L_29 ) ;
return 1 ;
}
return 0 ;
}
static int T_6 F_132 ( void )
{
int V_27 ;
V_95 = F_133 ( V_94 * sizeof( struct V_167 ) , V_168 ) ;
if ( ! V_95 )
return - V_169 ;
for ( V_27 = 0 ; V_27 < V_94 ; V_27 ++ ) {
struct V_167 * V_92 = & V_95 [ V_27 ] ;
V_92 -> V_96 = - 1ULL ;
V_92 -> V_170 = 1 ;
}
return 0 ;
}
static int T_6 F_134 ( void )
{
unsigned V_92 ;
T_2 V_171 ;
F_7 ( V_14 , V_171 ) ;
V_92 = V_171 & V_172 ;
if ( ! V_94 )
F_109 ( V_173 L_30 , V_92 ) ;
if ( V_92 > V_135 ) {
F_109 ( V_174
L_31 ,
V_135 , V_92 ) ;
V_92 = V_135 ;
}
F_115 ( V_94 != 0 && V_92 != V_94 ) ;
V_94 = V_92 ;
if ( ! V_95 ) {
int V_175 = F_132 () ;
if ( V_175 )
return V_175 ;
}
if ( ( V_171 & V_176 ) && F_135 ( V_171 ) >= 9 )
V_61 = V_177 ;
if ( V_171 & V_178 )
V_89 = 1 ;
return 0 ;
}
static void F_136 ( void )
{
T_4 V_179 ;
T_2 V_171 ;
int V_27 ;
F_137 ( V_179 , V_135 ) ;
F_71 ( V_97 | ( ! V_180 ? V_100 : 0 ) , & V_179 ) ;
F_138 ( V_181 ) ;
F_7 ( V_14 , V_171 ) ;
if ( V_171 & V_182 )
F_139 ( V_183 , 0xffffffff , 0xffffffff ) ;
for ( V_27 = 0 ; V_27 < V_94 ; V_27 ++ ) {
struct V_167 * V_92 = & V_95 [ V_27 ] ;
if ( ! V_92 -> V_170 )
continue;
F_52 ( F_140 ( V_27 ) , V_92 -> V_96 ) ;
F_52 ( F_44 ( V_27 ) , 0 ) ;
}
}
static int T_6 F_141 ( struct V_75 * V_76 )
{
if ( V_76 -> V_8 == V_184 ) {
F_131 ( L_32 ) ;
return - V_185 ;
}
if ( V_76 -> V_8 == V_186 ) {
if ( V_76 -> V_187 == 15 && V_94 > 4 ) {
F_142 ( 10 , ( unsigned long * ) & V_95 [ 4 ] . V_96 ) ;
}
if ( V_76 -> V_187 <= 17 && V_180 < 0 ) {
V_180 = 0 ;
}
if ( V_76 -> V_187 == 6 && V_94 > 0 )
V_95 [ 0 ] . V_96 = 0 ;
if ( V_76 -> V_187 == 0x15 &&
( V_76 -> V_188 >= 0x10 && V_76 -> V_188 <= 0x1f ) ) {
int V_27 ;
T_2 V_189 , V_190 ;
bool V_191 ;
T_1 V_192 [] = {
0x00000413 ,
0xc0000408 ,
} ;
F_7 ( V_193 , V_190 ) ;
V_191 = ! ( V_190 & F_143 ( 18 ) ) ;
if ( V_191 )
F_52 ( V_193 , V_190 | F_143 ( 18 ) ) ;
for ( V_27 = 0 ; V_27 < F_144 ( V_192 ) ; V_27 ++ ) {
F_7 ( V_192 [ V_27 ] , V_189 ) ;
if ( V_189 & F_145 ( 62 ) ) {
V_189 &= ~ F_145 ( 62 ) ;
F_52 ( V_192 [ V_27 ] , V_189 ) ;
}
}
if ( V_191 )
F_52 ( V_193 , V_190 ) ;
}
}
if ( V_76 -> V_8 == V_194 ) {
if ( V_76 -> V_187 == 6 && V_76 -> V_188 < 0x1A && V_94 > 0 )
V_95 [ 0 ] . V_170 = 0 ;
if ( ( V_76 -> V_187 > 6 || ( V_76 -> V_187 == 6 && V_76 -> V_188 >= 0xe ) ) &&
V_106 < 0 )
V_106 = V_47 ;
if ( V_76 -> V_187 == 6 && V_76 -> V_188 <= 13 && V_180 < 0 )
V_180 = 0 ;
}
if ( V_106 < 0 )
V_106 = 0 ;
if ( V_180 != 0 )
V_49 = 30 ;
return 0 ;
}
static int T_6 F_146 ( struct V_75 * V_76 )
{
if ( V_76 -> V_187 != 5 )
return 0 ;
switch ( V_76 -> V_8 ) {
case V_194 :
F_147 ( V_76 ) ;
return 1 ;
break;
case V_195 :
F_148 ( V_76 ) ;
return 1 ;
break;
}
return 0 ;
}
static void F_149 ( struct V_75 * V_76 )
{
switch ( V_76 -> V_8 ) {
case V_194 :
F_150 ( V_76 ) ;
break;
case V_186 :
F_151 ( V_76 ) ;
break;
default:
break;
}
}
static void F_152 ( void )
{
struct V_152 * V_105 = & F_48 ( V_153 ) ;
unsigned long V_154 = V_159 * V_158 ;
F_153 ( V_105 , F_114 , F_2 () ) ;
if ( V_196 )
return;
F_120 ( V_157 , V_154 ) ;
if ( ! V_154 )
return;
V_105 -> V_160 = F_154 ( V_30 + V_154 ) ;
F_121 ( V_105 , F_2 () ) ;
}
static void F_155 ( struct V_65 * V_66 , long V_132 )
{
F_109 ( V_147 L_33 ,
F_2 () ) ;
}
void T_6 F_156 ( struct V_75 * V_76 )
{
if ( V_77 )
return;
if ( F_146 ( V_76 ) )
return;
if ( ! F_60 ( V_76 ) )
return;
if ( F_134 () < 0 || F_141 ( V_76 ) < 0 ) {
V_77 = 1 ;
return;
}
V_197 = F_100 ;
F_136 () ;
F_149 ( V_76 ) ;
F_152 () ;
F_157 ( & F_48 ( V_82 ) , F_112 ) ;
F_158 ( & F_48 ( V_86 ) , & F_65 ) ;
}
static int F_159 ( struct V_198 * V_198 , struct V_199 * V_199 )
{
F_160 ( & V_200 ) ;
if ( V_201 ||
( V_202 && ( V_199 -> V_203 & V_204 ) ) ) {
F_161 ( & V_200 ) ;
return - V_205 ;
}
if ( V_199 -> V_203 & V_204 )
V_201 = 1 ;
V_202 ++ ;
F_161 ( & V_200 ) ;
return F_162 ( V_198 , V_199 ) ;
}
static int F_163 ( struct V_198 * V_198 , struct V_199 * V_199 )
{
F_160 ( & V_200 ) ;
V_202 -- ;
V_201 = 0 ;
F_161 ( & V_200 ) ;
return 0 ;
}
static void F_164 ( void * V_151 )
{
unsigned long * V_206 = ( unsigned long * ) V_151 ;
F_3 ( V_206 [ F_2 () ] ) ;
}
static int F_165 ( char T_7 * * V_207 , T_8 V_208 )
{
int V_209 ;
T_2 V_210 ;
struct V_1 V_2 ;
if ( V_208 < sizeof( struct V_1 ) )
return - V_211 ;
V_209 = F_166 ( & V_2 , & V_210 ) ;
if ( V_209 <= 0 ) {
V_212 = 1 ;
if ( V_209 == - V_213 )
return 0 ;
return V_209 ;
}
V_209 = - V_214 ;
if ( F_167 ( * V_207 , & V_2 , sizeof( struct V_1 ) ) )
return V_209 ;
V_209 = F_168 ( V_210 ) ;
if ( V_209 ) {
V_212 = 1 ;
return V_209 ;
}
* V_207 += sizeof( struct V_1 ) ;
return 0 ;
}
static T_9 F_169 ( struct V_199 * V_215 , char T_7 * V_207 ,
T_8 V_208 , T_10 * V_216 )
{
char T_7 * V_217 = V_207 ;
unsigned long * V_206 ;
unsigned V_28 , V_16 ;
int V_27 , V_175 ;
V_206 = F_170 ( V_218 * sizeof( long ) , V_168 ) ;
if ( ! V_206 )
return - V_169 ;
F_171 ( & V_219 ) ;
if ( ! V_212 ) {
V_175 = F_165 ( & V_217 , V_208 ) ;
if ( V_175 || V_217 != V_207 )
goto V_72;
}
V_16 = F_12 ( V_22 . V_16 ) ;
V_175 = - V_211 ;
if ( * V_216 != 0 || V_208 < V_23 * sizeof( struct V_1 ) )
goto V_72;
V_175 = 0 ;
V_28 = 0 ;
do {
for ( V_27 = V_28 ; V_27 < V_16 ; V_27 ++ ) {
unsigned long V_29 = V_30 ;
struct V_1 * V_2 = & V_22 . V_17 [ V_27 ] ;
while ( ! V_2 -> V_21 ) {
if ( F_18 ( V_30 , V_29 + 2 ) ) {
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
goto V_45;
}
F_19 () ;
}
F_14 () ;
V_175 |= F_167 ( V_217 , V_2 , sizeof( * V_2 ) ) ;
V_217 += sizeof( * V_2 ) ;
V_45:
;
}
memset ( V_22 . V_17 + V_28 , 0 ,
( V_16 - V_28 ) * sizeof( struct V_1 ) ) ;
V_28 = V_16 ;
V_16 = F_15 ( & V_22 . V_16 , V_28 , 0 ) ;
} while ( V_16 != V_28 );
F_172 () ;
F_173 ( F_164 , V_206 , 1 ) ;
for ( V_27 = V_16 ; V_27 < V_23 ; V_27 ++ ) {
struct V_1 * V_2 = & V_22 . V_17 [ V_27 ] ;
if ( V_2 -> V_21 && V_2 -> V_5 < V_206 [ V_2 -> V_3 ] ) {
V_175 |= F_167 ( V_217 , V_2 , sizeof( * V_2 ) ) ;
F_14 () ;
V_217 += sizeof( * V_2 ) ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
}
}
if ( V_175 )
V_175 = - V_214 ;
V_72:
F_174 ( & V_219 ) ;
F_175 ( V_206 ) ;
return V_175 ? V_175 : V_217 - V_207 ;
}
static unsigned int F_176 ( struct V_199 * V_199 , T_11 * V_220 )
{
F_177 ( V_199 , & V_165 , V_220 ) ;
if ( F_178 ( V_22 . V_16 ) )
return V_221 | V_222 ;
if ( ! V_212 && F_179 () )
return V_221 | V_222 ;
return 0 ;
}
static long F_180 ( struct V_199 * V_223 , unsigned int V_224 ,
unsigned long V_225 )
{
int T_7 * V_226 = ( int T_7 * ) V_225 ;
if ( ! F_181 ( V_227 ) )
return - V_228 ;
switch ( V_224 ) {
case V_229 :
return F_182 ( sizeof( struct V_1 ) , V_226 ) ;
case V_230 :
return F_182 ( V_23 , V_226 ) ;
case V_231 : {
unsigned V_25 ;
do {
V_25 = V_22 . V_25 ;
} while ( F_15 ( & V_22 . V_25 , V_25 , 0 ) != V_25 );
return F_182 ( V_25 , V_226 ) ;
}
default:
return - V_232 ;
}
}
void F_183 ( T_9 (* F_184)( struct V_199 * V_215 ,
const char T_7 * V_207 ,
T_8 V_208 , T_10 * V_216 ) )
{
V_233 = F_184 ;
}
T_9 F_185 ( struct V_199 * V_215 , const char T_7 * V_207 ,
T_8 V_208 , T_10 * V_216 )
{
if ( V_233 )
return V_233 ( V_215 , V_207 , V_208 , V_216 ) ;
else
return - V_211 ;
}
static int T_12 F_186 ( char * V_234 )
{
if ( * V_234 == 0 ) {
F_187 () ;
return 1 ;
}
if ( * V_234 == '=' )
V_234 ++ ;
if ( ! strcmp ( V_234 , L_34 ) )
V_77 = 1 ;
else if ( ! strcmp ( V_234 , L_35 ) )
V_235 = 1 ;
else if ( ! strcmp ( V_234 , L_36 ) )
V_101 = 1 ;
else if ( ! strcmp ( V_234 , L_37 ) )
V_196 = 1 ;
else if ( ! strcmp ( V_234 , L_38 ) || ! strcmp ( V_234 , L_39 ) )
V_180 = ( V_234 [ 0 ] == 'b' ) ;
else if ( isdigit ( V_234 [ 0 ] ) ) {
F_188 ( & V_234 , & V_103 ) ;
if ( * V_234 == ',' ) {
++ V_234 ;
F_188 ( & V_234 , & V_106 ) ;
}
} else {
F_109 ( V_173 L_40 ,
V_234 ) ;
return 0 ;
}
return 1 ;
}
int T_12 F_189 ( void )
{
F_190 () ;
return 0 ;
}
static int F_191 ( void )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_94 ; V_27 ++ ) {
struct V_167 * V_92 = & V_95 [ V_27 ] ;
if ( V_92 -> V_170 )
F_52 ( F_140 ( V_27 ) , 0 ) ;
}
return 0 ;
}
static int F_192 ( void )
{
return F_191 () ;
}
static void F_193 ( void )
{
F_191 () ;
}
static void F_194 ( void )
{
F_136 () ;
F_149 ( F_116 ( & V_155 ) ) ;
}
static void F_195 ( void * V_151 )
{
if ( ! F_60 ( F_116 ( & V_155 ) ) )
return;
F_136 () ;
F_152 () ;
}
static void F_196 ( void )
{
F_122 () ;
F_173 ( F_195 , NULL , 1 ) ;
}
static void F_197 ( void * V_151 )
{
if ( ! F_60 ( F_116 ( & V_155 ) ) )
return;
F_198 () ;
}
static void F_199 ( void * V_236 )
{
if ( ! F_60 ( F_116 ( & V_155 ) ) )
return;
F_200 () ;
F_201 () ;
if ( V_236 )
F_152 () ;
}
static inline struct V_167 * F_202 ( struct V_237 * V_238 )
{
return F_203 ( V_238 , struct V_167 , V_238 ) ;
}
static T_9 F_204 ( struct V_239 * V_240 , struct V_237 * V_238 ,
char * V_217 )
{
return sprintf ( V_217 , L_41 , F_202 ( V_238 ) -> V_96 ) ;
}
static T_9 F_205 ( struct V_239 * V_240 , struct V_237 * V_238 ,
const char * V_217 , T_8 V_241 )
{
T_2 V_242 ;
if ( F_206 ( V_217 , 0 , & V_242 ) < 0 )
return - V_211 ;
F_202 ( V_238 ) -> V_96 = V_242 ;
F_196 () ;
return V_241 ;
}
static T_9
F_207 ( struct V_239 * V_240 , struct V_237 * V_238 , char * V_217 )
{
strcpy ( V_217 , V_161 ) ;
strcat ( V_217 , L_7 ) ;
return strlen ( V_161 ) + 1 ;
}
static T_9 F_208 ( struct V_239 * V_240 , struct V_237 * V_238 ,
const char * V_217 , T_8 V_243 )
{
char * V_226 ;
strncpy ( V_161 , V_217 , sizeof( V_161 ) ) ;
V_161 [ sizeof( V_161 ) - 1 ] = 0 ;
V_226 = strchr ( V_161 , '\n' ) ;
if ( V_226 )
* V_226 = 0 ;
return strlen ( V_161 ) + ! ! V_226 ;
}
static T_9 F_209 ( struct V_239 * V_240 ,
struct V_237 * V_238 ,
const char * V_217 , T_8 V_241 )
{
T_2 V_242 ;
if ( F_206 ( V_217 , 0 , & V_242 ) < 0 )
return - V_211 ;
if ( V_196 ^ ! ! V_242 ) {
if ( V_242 ) {
F_122 () ;
F_173 ( F_197 , NULL , 1 ) ;
V_196 = 1 ;
} else {
V_196 = 0 ;
F_173 ( F_199 , ( void * ) 1 , 1 ) ;
}
}
return V_241 ;
}
static T_9 F_210 ( struct V_239 * V_240 ,
struct V_237 * V_238 ,
const char * V_217 , T_8 V_241 )
{
T_2 V_242 ;
if ( F_206 ( V_217 , 0 , & V_242 ) < 0 )
return - V_211 ;
if ( V_235 ^ ! ! V_242 ) {
if ( V_242 ) {
F_173 ( F_197 , NULL , 1 ) ;
V_235 = 1 ;
} else {
V_235 = 0 ;
F_173 ( F_199 , NULL , 1 ) ;
}
}
return V_241 ;
}
static T_9 F_211 ( struct V_239 * V_240 ,
struct V_237 * V_238 ,
const char * V_217 , T_8 V_241 )
{
T_9 V_18 = F_212 ( V_240 , V_238 , V_217 , V_241 ) ;
F_196 () ;
return V_18 ;
}
static void F_213 ( struct V_239 * V_244 )
{
F_175 ( V_244 ) ;
}
static T_6 int F_214 ( unsigned int V_3 )
{
struct V_239 * V_244 ;
int V_175 ;
int V_27 , V_245 ;
if ( ! F_60 ( & V_7 ) )
return - V_246 ;
V_244 = F_133 ( sizeof *V_244 , V_168 ) ;
if ( ! V_244 )
return - V_169 ;
V_244 -> V_247 = V_3 ;
V_244 -> V_248 = & V_249 ;
V_244 -> V_250 = & F_213 ;
V_175 = F_215 ( V_244 ) ;
if ( V_175 )
return V_175 ;
for ( V_27 = 0 ; V_251 [ V_27 ] ; V_27 ++ ) {
V_175 = F_216 ( V_244 , V_251 [ V_27 ] ) ;
if ( V_175 )
goto error;
}
for ( V_245 = 0 ; V_245 < V_94 ; V_245 ++ ) {
V_175 = F_216 ( V_244 , & V_95 [ V_245 ] . V_238 ) ;
if ( V_175 )
goto V_252;
}
F_217 ( V_3 , V_253 ) ;
F_84 ( V_254 , V_3 ) = V_244 ;
return 0 ;
V_252:
while ( -- V_245 >= 0 )
F_218 ( V_244 , & V_95 [ V_245 ] . V_238 ) ;
error:
while ( -- V_27 >= 0 )
F_218 ( V_244 , V_251 [ V_27 ] ) ;
F_219 ( V_244 ) ;
return V_175 ;
}
static T_6 void F_220 ( unsigned int V_3 )
{
struct V_239 * V_244 = F_84 ( V_254 , V_3 ) ;
int V_27 ;
if ( ! F_221 ( V_3 , V_253 ) )
return;
for ( V_27 = 0 ; V_251 [ V_27 ] ; V_27 ++ )
F_218 ( V_244 , V_251 [ V_27 ] ) ;
for ( V_27 = 0 ; V_27 < V_94 ; V_27 ++ )
F_218 ( V_244 , & V_95 [ V_27 ] . V_238 ) ;
F_219 ( V_244 ) ;
F_222 ( V_3 , V_253 ) ;
F_84 ( V_254 , V_3 ) = NULL ;
}
static void T_6 F_223 ( void * V_255 )
{
unsigned long V_256 = * ( unsigned long * ) V_255 ;
int V_27 ;
if ( ! F_60 ( F_116 ( & V_155 ) ) )
return;
if ( ! ( V_256 & V_257 ) )
F_198 () ;
for ( V_27 = 0 ; V_27 < V_94 ; V_27 ++ ) {
struct V_167 * V_92 = & V_95 [ V_27 ] ;
if ( V_92 -> V_170 )
F_52 ( F_140 ( V_27 ) , 0 ) ;
}
}
static void T_6 F_224 ( void * V_255 )
{
unsigned long V_256 = * ( unsigned long * ) V_255 ;
int V_27 ;
if ( ! F_60 ( F_116 ( & V_155 ) ) )
return;
if ( ! ( V_256 & V_257 ) )
F_200 () ;
for ( V_27 = 0 ; V_27 < V_94 ; V_27 ++ ) {
struct V_167 * V_92 = & V_95 [ V_27 ] ;
if ( V_92 -> V_170 )
F_52 ( F_140 ( V_27 ) , V_92 -> V_96 ) ;
}
}
static int T_6
F_225 ( struct V_32 * V_258 , unsigned long V_256 , void * V_259 )
{
unsigned int V_3 = ( unsigned long ) V_259 ;
struct V_152 * V_105 = & F_84 ( V_153 , V_3 ) ;
switch ( V_256 ) {
case V_260 :
case V_261 :
F_214 ( V_3 ) ;
if ( V_262 )
V_262 ( V_256 , V_3 ) ;
break;
case V_263 :
case V_264 :
if ( V_262 )
V_262 ( V_256 , V_3 ) ;
F_220 ( V_3 ) ;
break;
case V_265 :
case V_266 :
F_124 ( V_105 ) ;
F_226 ( V_3 , F_223 , & V_256 , 1 ) ;
break;
case V_267 :
case V_268 :
if ( ! V_196 && V_159 ) {
V_105 -> V_160 = F_154 ( V_30 +
F_84 ( V_157 , V_3 ) ) ;
F_121 ( V_105 , V_3 ) ;
}
F_226 ( V_3 , F_224 , & V_256 , 1 ) ;
break;
case V_269 :
F_227 ( V_3 ) ;
break;
}
return V_270 ;
}
static T_12 void F_228 ( void )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_94 ; V_27 ++ ) {
struct V_167 * V_92 = & V_95 [ V_27 ] ;
struct V_237 * V_271 = & V_92 -> V_238 ;
F_229 ( & V_271 -> V_238 ) ;
V_271 -> V_238 . V_272 = V_92 -> V_273 ;
snprintf ( V_92 -> V_273 , V_274 , L_42 , V_27 ) ;
V_271 -> V_238 . V_275 = 0644 ;
V_271 -> V_276 = F_204 ;
V_271 -> V_277 = F_205 ;
}
}
static T_12 int F_230 ( void )
{
int V_175 ;
int V_27 = 0 ;
if ( ! F_60 ( & V_7 ) )
return - V_246 ;
F_231 ( & V_253 , V_168 ) ;
F_228 () ;
V_175 = F_232 ( & V_249 , NULL ) ;
if ( V_175 )
return V_175 ;
F_123 (i) {
V_175 = F_214 ( V_27 ) ;
if ( V_175 )
return V_175 ;
}
F_233 ( & V_278 ) ;
F_234 ( & V_279 ) ;
F_235 ( & V_280 ) ;
return V_175 ;
}
static int T_12 F_236 ( char * V_234 )
{
V_77 = 1 ;
return 1 ;
}
struct V_281 * F_237 ( void )
{
static struct V_281 * V_282 ;
if ( ! V_282 )
V_282 = F_238 ( L_43 , NULL ) ;
return V_282 ;
}
static void F_239 ( void )
{
V_58 = 0 ;
F_89 ( & V_55 , 0 ) ;
F_89 ( & V_120 , 0 ) ;
F_89 ( & V_119 , 0 ) ;
F_89 ( & V_118 , 0 ) ;
}
static int F_240 ( void * V_151 , T_2 * V_189 )
{
* V_189 = V_53 ;
return 0 ;
}
static int F_241 ( void * V_151 , T_2 V_189 )
{
F_239 () ;
V_53 = V_189 ;
return 0 ;
}
static int T_12 F_242 ( void )
{
struct V_281 * V_282 , * V_283 ;
V_282 = F_237 () ;
if ( ! V_282 )
return - V_169 ;
V_283 = F_243 ( L_44 , 0444 , V_282 , NULL ,
& V_284 ) ;
if ( ! V_283 )
return - V_169 ;
return 0 ;
}
