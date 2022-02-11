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
V_48 = V_49 . V_48 ;
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
V_48 = V_49 . V_48 ;
F_34 ( V_50 ) ;
} else
F_26 ( V_34 L_16 , V_50 ) ;
}
static int F_41 ( T_1 V_59 )
{
unsigned V_36 = F_42 ( V_60 . V_36 ) ;
if ( V_59 == V_49 . V_61 )
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
if ( V_49 . V_61 )
V_2 -> V_38 = F_47 ( V_49 . V_61 ) ;
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
if ( V_49 . V_77 )
return 0 ;
return F_61 ( V_76 , V_78 ) && F_61 ( V_76 , V_79 ) ;
}
static void F_62 ( void )
{
if ( ! F_55 () )
F_63 ( & F_48 ( V_80 ) ) ;
}
static void F_64 ( struct V_81 * V_17 )
{
F_65 () ;
F_62 () ;
}
static void F_66 ( struct V_65 * V_66 )
{
if ( V_66 -> V_25 & ( V_82 | V_83 ) ) {
F_65 () ;
F_62 () ;
return;
}
F_67 ( & F_48 ( V_84 ) ) ;
}
static void F_68 ( struct V_1 * V_2 , int V_27 )
{
if ( V_2 -> V_37 & V_85 )
V_2 -> V_43 = F_47 ( F_46 ( V_27 ) ) ;
if ( V_2 -> V_37 & V_86 ) {
V_2 -> V_42 = F_47 ( F_45 ( V_27 ) ) ;
if ( V_49 . V_87 && ( V_2 -> V_37 & V_85 ) ) {
T_3 V_88 = F_69 ( V_2 -> V_43 ) ;
V_2 -> V_42 >>= V_88 ;
V_2 -> V_42 <<= V_88 ;
}
}
}
void F_70 ( enum V_89 V_25 , T_4 * V_90 )
{
struct V_1 V_2 ;
int V_27 ;
F_71 ( V_91 ) ;
F_53 ( & V_2 , NULL ) ;
for ( V_27 = 0 ; V_27 < V_49 . V_92 ; V_27 ++ ) {
if ( ! V_93 [ V_27 ] . V_94 || ! F_72 ( V_27 , * V_90 ) )
continue;
V_2 . V_43 = 0 ;
V_2 . V_42 = 0 ;
V_2 . V_36 = V_27 ;
V_2 . V_5 = 0 ;
F_37 () ;
V_2 . V_37 = F_47 ( F_44 ( V_27 ) ) ;
if ( ! ( V_2 . V_37 & V_56 ) )
continue;
if ( ! ( V_25 & V_95 ) &&
( V_2 . V_37 & ( V_49 . V_87 ? V_96 : V_57 ) ) )
continue;
F_68 ( & V_2 , V_27 ) ;
if ( ! ( V_25 & V_97 ) )
V_2 . V_5 = 0 ;
if ( ! ( V_25 & V_98 ) && ! V_49 . V_99 )
F_8 ( & V_2 ) ;
F_51 ( F_44 ( V_27 ) , 0 ) ;
}
F_73 () ;
}
static int F_74 ( struct V_1 * V_2 , char * * V_50 , unsigned long * V_100 ,
struct V_65 * V_66 )
{
int V_27 , V_18 = 0 ;
for ( V_27 = 0 ; V_27 < V_49 . V_92 ; V_27 ++ ) {
V_2 -> V_37 = F_47 ( F_44 ( V_27 ) ) ;
if ( V_2 -> V_37 & V_56 ) {
F_75 ( V_27 , V_100 ) ;
if ( V_101 )
V_101 ( V_27 , V_2 , V_66 ) ;
}
if ( F_76 ( V_2 , V_49 . V_102 , V_50 ) >= V_103 )
V_18 = 1 ;
}
return V_18 ;
}
static int F_77 ( T_2 * V_104 )
{
F_78 () ;
if ( F_79 ( & V_54 ) )
F_30 () ;
if ( ! V_49 . V_105 )
goto V_72;
if ( ( V_106 ) * V_104 < V_107 ) {
if ( V_49 . V_102 < 1 )
F_35 ( L_18 ,
NULL , NULL ) ;
V_58 = 1 ;
return 1 ;
}
* V_104 -= V_107 ;
V_72:
F_80 () ;
return 0 ;
}
static void F_81 ( void )
{
int V_3 ;
struct V_1 * V_2 = NULL ;
int V_108 = 0 ;
char * V_50 = NULL ;
char * V_109 = NULL ;
F_82 (cpu) {
int V_110 = F_76 ( & F_83 ( V_111 , V_3 ) ,
V_49 . V_102 ,
& V_109 ) ;
if ( V_110 > V_108 ) {
V_50 = V_109 ;
V_108 = V_110 ;
V_2 = & F_83 ( V_111 , V_3 ) ;
}
}
if ( V_2 && V_108 >= V_103 && V_49 . V_102 < 3 )
F_35 ( L_19 , V_2 , V_50 ) ;
if ( V_108 <= V_112 && V_49 . V_102 < 3 )
F_35 ( L_20 , NULL , NULL ) ;
F_82 (cpu)
memset ( & F_83 ( V_111 , V_3 ) , 0 , sizeof( struct V_1 ) ) ;
}
static int F_84 ( int * V_113 )
{
int V_114 ;
int V_115 = F_85 () ;
T_2 V_45 = ( T_2 ) V_49 . V_105 * V_116 ;
if ( ! V_45 )
return - 1 ;
F_86 ( * V_113 , & V_117 ) ;
F_87 () ;
V_114 = F_36 ( & V_118 ) ;
while ( F_79 ( & V_118 ) != V_115 ) {
if ( F_77 ( & V_45 ) ) {
F_88 ( & V_117 , 0 ) ;
return - 1 ;
}
F_89 ( V_107 ) ;
}
F_14 () ;
if ( V_114 == 1 ) {
F_88 ( & V_119 , 1 ) ;
} else {
while ( F_79 ( & V_119 ) < V_114 ) {
if ( F_77 ( & V_45 ) ) {
F_88 ( & V_117 , 0 ) ;
return - 1 ;
}
F_89 ( V_107 ) ;
}
}
* V_113 = F_79 ( & V_117 ) ;
return V_114 ;
}
static int F_90 ( int V_114 )
{
int V_18 = - 1 ;
T_2 V_45 = ( T_2 ) V_49 . V_105 * V_116 ;
if ( ! V_45 )
goto V_120;
if ( V_114 < 0 )
goto V_120;
F_91 ( & V_119 ) ;
if ( V_114 == 1 ) {
int V_115 = F_85 () ;
while ( F_79 ( & V_119 ) <= V_115 ) {
if ( F_77 ( & V_45 ) )
goto V_120;
F_89 ( V_107 ) ;
}
F_81 () ;
F_37 () ;
V_18 = 0 ;
} else {
while ( F_79 ( & V_119 ) != 0 ) {
if ( F_77 ( & V_45 ) )
goto V_120;
F_89 ( V_107 ) ;
}
return 0 ;
}
V_120:
F_88 ( & V_117 , 0 ) ;
F_88 ( & V_118 , 0 ) ;
F_37 () ;
F_88 ( & V_119 , 0 ) ;
return V_18 ;
}
static int F_92 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_37 & V_85 ) || ! ( V_2 -> V_37 & V_86 ) )
return 0 ;
if ( F_69 ( V_2 -> V_43 ) > V_121 )
return 0 ;
if ( F_93 ( V_2 -> V_43 ) != V_122 )
return 0 ;
return 1 ;
}
static void F_94 ( unsigned long * V_123 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_49 . V_92 ; V_27 ++ ) {
if ( F_72 ( V_27 , V_123 ) )
F_51 ( F_44 ( V_27 ) , 0 ) ;
}
}
static void F_95 ( T_5 V_42 , int V_76 )
{
struct V_124 * V_125 ;
for ( V_125 = V_124 ; V_125 < & V_124 [ V_126 ] ; V_125 ++ ) {
if ( F_96 ( & V_125 -> V_127 , 0 , 1 ) == 0 ) {
V_125 -> V_104 = V_128 ;
V_125 -> V_129 = V_42 ;
V_125 -> V_130 = V_76 ;
return;
}
}
F_35 ( L_21 , NULL , NULL ) ;
}
static struct V_124 * F_97 ( void )
{
struct V_124 * V_125 ;
for ( V_125 = V_124 ; V_125 < & V_124 [ V_126 ] ; V_125 ++ )
if ( F_79 ( & V_125 -> V_127 ) && V_125 -> V_104 == V_128 )
return V_125 ;
return NULL ;
}
static void F_98 ( struct V_124 * V_125 )
{
F_88 ( & V_125 -> V_127 , 0 ) ;
}
void F_99 ( struct V_65 * V_66 , long V_131 )
{
struct V_132 * V_133 = & V_49 ;
struct V_1 V_2 , * V_51 ;
int V_27 ;
int V_134 = 0 ;
int V_110 ;
int V_114 ;
int V_113 = 0 ;
int V_135 = 0 ;
F_100 ( V_123 , V_136 ) ;
F_100 ( V_137 , V_136 ) ;
char * V_50 = L_22 ;
F_91 ( & V_138 ) ;
F_71 ( V_139 ) ;
if ( ! V_133 -> V_92 )
goto V_72;
F_53 ( & V_2 , V_66 ) ;
V_51 = & F_48 ( V_111 ) ;
* V_51 = V_2 ;
memset ( V_137 , 0 , sizeof( V_137 ) ) ;
V_113 = F_74 ( & V_2 , & V_50 , V_137 , V_66 ) ;
F_37 () ;
if ( ! ( V_2 . V_35 & V_67 ) )
V_135 = 1 ;
V_114 = F_84 ( & V_113 ) ;
for ( V_27 = 0 ; V_27 < V_133 -> V_92 ; V_27 ++ ) {
F_101 ( V_27 , V_123 ) ;
if ( ! F_72 ( V_27 , V_137 ) )
continue;
if ( ! V_93 [ V_27 ] . V_94 )
continue;
V_2 . V_43 = 0 ;
V_2 . V_42 = 0 ;
V_2 . V_36 = V_27 ;
V_2 . V_37 = F_47 ( F_44 ( V_27 ) ) ;
if ( ( V_2 . V_37 & V_56 ) == 0 )
continue;
if ( ! ( V_2 . V_37 & ( V_133 -> V_87 ? V_96 : V_57 ) ) &&
! V_113 )
continue;
F_102 ( V_140 , V_141 ) ;
V_110 = F_76 ( & V_2 , V_133 -> V_102 , NULL ) ;
if ( V_110 == V_112 && ! V_113 )
continue;
F_75 ( V_27 , V_123 ) ;
if ( V_110 == V_142 ) {
continue;
}
F_68 ( & V_2 , V_27 ) ;
if ( V_110 == V_143 && F_92 ( & V_2 ) )
F_59 ( V_2 . V_42 >> V_121 ) ;
F_8 ( & V_2 ) ;
if ( V_110 > V_134 ) {
* V_51 = V_2 ;
V_134 = V_110 ;
}
}
V_2 = * V_51 ;
if ( ! V_113 )
F_94 ( V_123 ) ;
if ( F_90 ( V_114 ) < 0 )
V_113 = V_134 >= V_103 ;
if ( V_133 -> V_102 < 3 ) {
if ( V_113 )
F_35 ( L_23 , & V_2 , V_50 ) ;
if ( V_134 == V_144 ) {
F_95 ( V_2 . V_42 , V_2 . V_35 & V_67 ) ;
F_103 ( V_145 ) ;
} else if ( V_135 ) {
F_104 ( V_146 , V_128 ) ;
}
}
if ( V_134 > 0 )
F_66 ( V_66 ) ;
F_51 ( V_62 , 0 ) ;
V_72:
F_105 ( & V_138 ) ;
F_73 () ;
}
int F_106 ( unsigned long V_71 , int V_147 , int V_25 )
{
F_107 ( V_25 & V_148 ) ;
F_20 ( L_24
L_25 ,
V_71 ) ;
return 0 ;
}
void F_108 ( void )
{
unsigned long V_71 ;
struct V_124 * V_125 = F_97 () ;
int V_25 = V_148 ;
if ( ! V_125 )
F_35 ( L_26 , NULL , NULL ) ;
V_71 = V_125 -> V_129 >> V_121 ;
F_109 ( V_145 ) ;
F_20 ( L_27 ,
V_125 -> V_129 ) ;
if ( ! V_125 -> V_130 )
V_25 |= V_149 ;
if ( F_106 ( V_71 , V_150 , V_25 ) < 0 ) {
F_20 ( L_28 ) ;
F_104 ( V_146 , V_128 ) ;
}
F_98 ( V_125 ) ;
}
static void F_110 ( struct V_151 * V_152 )
{
unsigned long V_71 ;
while ( F_56 ( & V_71 ) )
F_106 ( V_71 , V_150 , 0 ) ;
}
void F_111 ( T_5 V_37 )
{
struct V_1 V_2 ;
F_1 ( & V_2 ) ;
V_2 . V_36 = V_153 ;
V_2 . V_37 = V_37 ;
F_8 ( & V_2 ) ;
}
static unsigned long F_112 ( unsigned long V_154 )
{
return V_154 ;
}
static void F_113 ( unsigned long V_155 )
{
struct V_156 * V_104 = & F_48 ( V_157 ) ;
unsigned long V_158 ;
F_114 ( F_2 () != V_155 ) ;
if ( F_60 ( F_115 ( & V_159 ) ) ) {
F_70 ( V_97 ,
& F_48 ( V_160 ) ) ;
F_116 () ;
}
V_158 = F_42 ( V_161 ) ;
if ( F_65 () ) {
V_158 = F_117 ( V_158 / 2 , ( unsigned long ) V_162 / 100 ) ;
} else {
V_158 = F_118 ( V_158 * 2 , F_119 ( V_163 * V_162 ) ) ;
V_158 = F_120 ( V_158 ) ;
}
F_121 ( V_161 , V_158 ) ;
if ( V_158 ) {
V_104 -> V_164 = V_30 + V_158 ;
F_122 ( V_104 , F_2 () ) ;
}
}
void F_123 ( unsigned long V_154 )
{
struct V_156 * V_104 = & F_48 ( V_157 ) ;
unsigned long V_165 = V_30 + V_154 ;
unsigned long V_158 = F_42 ( V_161 ) ;
if ( F_124 ( V_104 ) ) {
if ( F_125 ( V_165 , V_104 -> V_164 ) )
F_126 ( V_104 , V_165 ) ;
} else {
V_104 -> V_164 = F_127 ( V_165 ) ;
F_122 ( V_104 , F_2 () ) ;
}
if ( V_154 < V_158 )
F_121 ( V_161 , V_154 ) ;
}
static void F_128 ( void )
{
int V_3 ;
F_129 (cpu)
F_130 ( & F_83 ( V_157 , V_3 ) ) ;
}
static void F_131 ( struct V_151 * V_166 )
{
F_132 ( V_167 , V_168 , NULL , V_169 ) ;
}
int F_65 ( void )
{
static F_133 ( V_170 , 60 * V_162 , 2 ) ;
if ( F_134 ( 0 , & V_26 ) ) {
F_135 ( & V_171 ) ;
if ( V_167 [ 0 ] )
F_63 ( & V_172 ) ;
if ( F_136 ( & V_170 ) )
F_137 ( V_34 L_29 ) ;
return 1 ;
}
return 0 ;
}
static int F_138 ( void )
{
int V_27 ;
T_3 V_173 = V_49 . V_92 ;
V_93 = F_139 ( V_173 * sizeof( struct V_174 ) , V_175 ) ;
if ( ! V_93 )
return - V_176 ;
for ( V_27 = 0 ; V_27 < V_173 ; V_27 ++ ) {
struct V_174 * V_90 = & V_93 [ V_27 ] ;
V_90 -> V_94 = - 1ULL ;
V_90 -> V_177 = 1 ;
}
return 0 ;
}
static int F_140 ( void )
{
unsigned V_90 ;
T_2 V_178 ;
F_7 ( V_14 , V_178 ) ;
V_90 = V_178 & V_179 ;
if ( ! V_49 . V_92 )
F_137 ( L_30 , V_90 ) ;
if ( V_90 > V_136 ) {
F_141 ( L_31 ,
V_136 , V_90 ) ;
V_90 = V_136 ;
}
F_114 ( V_49 . V_92 != 0 && V_90 != V_49 . V_92 ) ;
V_49 . V_92 = V_90 ;
if ( ! V_93 ) {
int V_180 = F_138 () ;
if ( V_180 )
return V_180 ;
}
if ( ( V_178 & V_181 ) && F_142 ( V_178 ) >= 9 )
V_49 . V_61 = V_182 ;
if ( V_178 & V_183 )
V_49 . V_87 = true ;
return 0 ;
}
static void F_143 ( void )
{
enum V_89 V_184 = 0 ;
T_4 V_185 ;
T_2 V_178 ;
int V_27 ;
if ( ! V_49 . V_186 )
V_184 = V_98 ;
F_144 ( V_185 , V_136 ) ;
F_70 ( V_95 | V_184 , & V_185 ) ;
F_145 ( V_187 ) ;
F_7 ( V_14 , V_178 ) ;
if ( V_178 & V_188 )
F_146 ( V_189 , 0xffffffff , 0xffffffff ) ;
for ( V_27 = 0 ; V_27 < V_49 . V_92 ; V_27 ++ ) {
struct V_174 * V_90 = & V_93 [ V_27 ] ;
if ( ! V_90 -> V_177 )
continue;
F_52 ( F_147 ( V_27 ) , V_90 -> V_94 ) ;
F_52 ( F_44 ( V_27 ) , 0 ) ;
}
}
static void F_148 ( int V_36 , struct V_1 * V_2 , struct V_65 * V_66 )
{
if ( V_36 != 0 )
return;
if ( ( V_2 -> V_35 & ( V_39 | V_67 ) ) != 0 )
return;
if ( ( V_2 -> V_37 & ( V_190 | V_57 |
V_191 | V_85 | V_86 |
V_192 | V_96 | V_193 |
V_194 ) ) !=
( V_57 | V_191 |
V_85 | V_86 | V_96 |
V_193 | V_195 ) )
return;
V_2 -> V_35 |= V_39 ;
V_2 -> V_38 = V_66 -> V_38 ;
V_2 -> V_40 = V_66 -> V_40 ;
}
static int F_149 ( struct V_75 * V_76 )
{
struct V_132 * V_133 = & V_49 ;
if ( V_76 -> V_8 == V_196 ) {
F_137 ( L_32 ) ;
return - V_197 ;
}
if ( V_76 -> V_8 == V_198 ) {
if ( V_76 -> V_199 == 15 && V_133 -> V_92 > 4 ) {
F_150 ( 10 , ( unsigned long * ) & V_93 [ 4 ] . V_94 ) ;
}
if ( V_76 -> V_199 <= 17 && V_133 -> V_186 < 0 ) {
V_133 -> V_186 = 0 ;
}
if ( V_76 -> V_199 == 6 && V_133 -> V_92 > 0 )
V_93 [ 0 ] . V_94 = 0 ;
if ( V_76 -> V_199 == 0x15 &&
( V_76 -> V_200 >= 0x10 && V_76 -> V_200 <= 0x1f ) ) {
int V_27 ;
T_2 V_201 , V_202 ;
bool V_203 ;
T_1 V_204 [] = {
0x00000413 ,
0xc0000408 ,
} ;
F_7 ( V_205 , V_202 ) ;
V_203 = ! ( V_202 & F_151 ( 18 ) ) ;
if ( V_203 )
F_52 ( V_205 , V_202 | F_151 ( 18 ) ) ;
for ( V_27 = 0 ; V_27 < F_152 ( V_204 ) ; V_27 ++ ) {
F_7 ( V_204 [ V_27 ] , V_201 ) ;
if ( V_201 & F_153 ( 62 ) ) {
V_201 &= ~ F_153 ( 62 ) ;
F_52 ( V_204 [ V_27 ] , V_201 ) ;
}
}
if ( V_203 )
F_52 ( V_205 , V_202 ) ;
}
}
if ( V_76 -> V_8 == V_206 ) {
if ( V_76 -> V_199 == 6 && V_76 -> V_200 < 0x1A && V_133 -> V_92 > 0 )
V_93 [ 0 ] . V_177 = 0 ;
if ( ( V_76 -> V_199 > 6 || ( V_76 -> V_199 == 6 && V_76 -> V_200 >= 0xe ) ) &&
V_133 -> V_105 < 0 )
V_133 -> V_105 = V_47 ;
if ( V_76 -> V_199 == 6 && V_76 -> V_200 <= 13 && V_133 -> V_186 < 0 )
V_133 -> V_186 = 0 ;
if ( V_76 -> V_199 == 6 && V_76 -> V_200 == 45 )
V_101 = F_148 ;
}
if ( V_133 -> V_105 < 0 )
V_133 -> V_105 = 0 ;
if ( V_133 -> V_186 != 0 )
V_133 -> V_48 = 30 ;
return 0 ;
}
static int F_154 ( struct V_75 * V_76 )
{
if ( V_76 -> V_199 != 5 )
return 0 ;
switch ( V_76 -> V_8 ) {
case V_206 :
F_155 ( V_76 ) ;
return 1 ;
break;
case V_207 :
F_156 ( V_76 ) ;
return 1 ;
break;
}
return 0 ;
}
static void F_157 ( struct V_75 * V_76 )
{
switch ( V_76 -> V_8 ) {
case V_206 :
F_158 ( V_76 ) ;
F_120 = V_208 ;
break;
case V_198 :
F_159 ( V_76 ) ;
break;
default:
break;
}
}
static void F_160 ( unsigned int V_3 , struct V_156 * V_104 )
{
unsigned long V_158 = F_120 ( V_163 * V_162 ) ;
F_121 ( V_161 , V_158 ) ;
if ( V_49 . V_209 || ! V_158 )
return;
V_104 -> V_164 = F_127 ( V_30 + V_158 ) ;
F_122 ( V_104 , F_2 () ) ;
}
static void F_161 ( void )
{
struct V_156 * V_104 = & F_48 ( V_157 ) ;
unsigned int V_3 = F_2 () ;
F_162 ( V_104 , F_113 , V_3 ) ;
F_160 ( V_3 , V_104 ) ;
}
static void F_163 ( struct V_65 * V_66 , long V_131 )
{
F_20 ( L_33 ,
F_2 () ) ;
}
void F_164 ( struct V_75 * V_76 )
{
if ( V_49 . V_77 )
return;
if ( F_154 ( V_76 ) )
return;
if ( ! F_60 ( V_76 ) )
return;
if ( F_140 () < 0 || F_149 ( V_76 ) < 0 ) {
V_49 . V_77 = true ;
return;
}
V_210 = F_99 ;
F_143 () ;
F_157 ( V_76 ) ;
F_161 () ;
F_165 ( & F_48 ( V_80 ) , F_110 ) ;
F_166 ( & F_48 ( V_84 ) , & F_64 ) ;
}
static int F_167 ( struct V_211 * V_211 , struct V_212 * V_212 )
{
F_168 ( & V_213 ) ;
if ( V_214 ||
( V_215 && ( V_212 -> V_216 & V_217 ) ) ) {
F_169 ( & V_213 ) ;
return - V_218 ;
}
if ( V_212 -> V_216 & V_217 )
V_214 = 1 ;
V_215 ++ ;
F_169 ( & V_213 ) ;
return F_170 ( V_211 , V_212 ) ;
}
static int F_171 ( struct V_211 * V_211 , struct V_212 * V_212 )
{
F_168 ( & V_213 ) ;
V_215 -- ;
V_214 = 0 ;
F_169 ( & V_213 ) ;
return 0 ;
}
static void F_172 ( void * V_155 )
{
unsigned long * V_219 = ( unsigned long * ) V_155 ;
F_3 ( V_219 [ F_2 () ] ) ;
}
static int F_173 ( char T_6 * * V_220 , T_7 V_221 )
{
int V_222 ;
T_2 V_223 ;
struct V_1 V_2 ;
if ( V_221 < sizeof( struct V_1 ) )
return - V_224 ;
V_222 = F_174 ( & V_2 , & V_223 ) ;
if ( V_222 <= 0 ) {
V_225 = 1 ;
if ( V_222 == - V_226 )
return 0 ;
return V_222 ;
}
V_222 = - V_227 ;
if ( F_175 ( * V_220 , & V_2 , sizeof( struct V_1 ) ) )
return V_222 ;
V_222 = F_176 ( V_223 ) ;
if ( V_222 ) {
V_225 = 1 ;
return V_222 ;
}
* V_220 += sizeof( struct V_1 ) ;
return 0 ;
}
static T_8 F_177 ( struct V_212 * V_228 , char T_6 * V_220 ,
T_7 V_221 , T_9 * V_229 )
{
char T_6 * V_230 = V_220 ;
unsigned long * V_219 ;
unsigned V_28 , V_16 ;
int V_27 , V_180 ;
V_219 = F_178 ( V_231 * sizeof( long ) , V_175 ) ;
if ( ! V_219 )
return - V_176 ;
F_179 ( & V_232 ) ;
if ( ! V_225 ) {
V_180 = F_173 ( & V_230 , V_221 ) ;
if ( V_180 || V_230 != V_220 )
goto V_72;
}
V_16 = F_12 ( V_22 . V_16 ) ;
V_180 = - V_224 ;
if ( * V_229 != 0 || V_221 < V_23 * sizeof( struct V_1 ) )
goto V_72;
V_180 = 0 ;
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
V_180 |= F_175 ( V_230 , V_2 , sizeof( * V_2 ) ) ;
V_230 += sizeof( * V_2 ) ;
V_45:
;
}
memset ( V_22 . V_17 + V_28 , 0 ,
( V_16 - V_28 ) * sizeof( struct V_1 ) ) ;
V_28 = V_16 ;
V_16 = F_15 ( & V_22 . V_16 , V_28 , 0 ) ;
} while ( V_16 != V_28 );
F_180 () ;
F_181 ( F_172 , V_219 , 1 ) ;
for ( V_27 = V_16 ; V_27 < V_23 ; V_27 ++ ) {
struct V_1 * V_2 = & V_22 . V_17 [ V_27 ] ;
if ( V_2 -> V_21 && V_2 -> V_5 < V_219 [ V_2 -> V_3 ] ) {
V_180 |= F_175 ( V_230 , V_2 , sizeof( * V_2 ) ) ;
F_14 () ;
V_230 += sizeof( * V_2 ) ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
}
}
if ( V_180 )
V_180 = - V_227 ;
V_72:
F_182 ( & V_232 ) ;
F_183 ( V_219 ) ;
return V_180 ? V_180 : V_230 - V_220 ;
}
static unsigned int F_184 ( struct V_212 * V_212 , T_10 * V_233 )
{
F_185 ( V_212 , & V_171 , V_233 ) ;
if ( F_186 ( V_22 . V_16 ) )
return V_234 | V_235 ;
if ( ! V_225 && F_187 () )
return V_234 | V_235 ;
return 0 ;
}
static long F_188 ( struct V_212 * V_236 , unsigned int V_237 ,
unsigned long V_238 )
{
int T_6 * V_239 = ( int T_6 * ) V_238 ;
if ( ! F_189 ( V_240 ) )
return - V_241 ;
switch ( V_237 ) {
case V_242 :
return F_190 ( sizeof( struct V_1 ) , V_239 ) ;
case V_243 :
return F_190 ( V_23 , V_239 ) ;
case V_244 : {
unsigned V_25 ;
do {
V_25 = V_22 . V_25 ;
} while ( F_15 ( & V_22 . V_25 , V_25 , 0 ) != V_25 );
return F_190 ( V_25 , V_239 ) ;
}
default:
return - V_245 ;
}
}
void F_191 ( T_8 (* F_192)( struct V_212 * V_228 ,
const char T_6 * V_220 ,
T_7 V_221 , T_9 * V_229 ) )
{
V_246 = F_192 ;
}
T_8 F_193 ( struct V_212 * V_228 , const char T_6 * V_220 ,
T_7 V_221 , T_9 * V_229 )
{
if ( V_246 )
return V_246 ( V_228 , V_220 , V_221 , V_229 ) ;
else
return - V_224 ;
}
static int T_11 F_194 ( char * V_247 )
{
struct V_132 * V_133 = & V_49 ;
if ( * V_247 == 0 ) {
F_195 () ;
return 1 ;
}
if ( * V_247 == '=' )
V_247 ++ ;
if ( ! strcmp ( V_247 , L_34 ) )
V_133 -> V_77 = true ;
else if ( ! strcmp ( V_247 , L_35 ) )
V_133 -> V_248 = true ;
else if ( ! strcmp ( V_247 , L_36 ) )
V_133 -> V_99 = true ;
else if ( ! strcmp ( V_247 , L_37 ) )
V_133 -> V_209 = true ;
else if ( ! strcmp ( V_247 , L_38 ) || ! strcmp ( V_247 , L_39 ) )
V_133 -> V_186 = ( V_247 [ 0 ] == 'b' ) ;
else if ( ! strcmp ( V_247 , L_40 ) )
V_133 -> V_249 = true ;
else if ( isdigit ( V_247 [ 0 ] ) ) {
F_196 ( & V_247 , & ( V_133 -> V_102 ) ) ;
if ( * V_247 == ',' ) {
++ V_247 ;
F_196 ( & V_247 , & ( V_133 -> V_105 ) ) ;
}
} else {
F_137 ( L_41 , V_247 ) ;
return 0 ;
}
return 1 ;
}
int T_11 F_197 ( void )
{
F_198 () ;
return 0 ;
}
static int F_199 ( void )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_49 . V_92 ; V_27 ++ ) {
struct V_174 * V_90 = & V_93 [ V_27 ] ;
if ( V_90 -> V_177 )
F_52 ( F_147 ( V_27 ) , 0 ) ;
}
return 0 ;
}
static int F_200 ( void )
{
return F_199 () ;
}
static void F_201 ( void )
{
F_199 () ;
}
static void F_202 ( void )
{
F_143 () ;
F_157 ( F_115 ( & V_159 ) ) ;
}
static void F_203 ( void * V_155 )
{
if ( ! F_60 ( F_115 ( & V_159 ) ) )
return;
F_143 () ;
F_161 () ;
}
static void F_204 ( void )
{
F_128 () ;
F_181 ( F_203 , NULL , 1 ) ;
}
static void F_205 ( void * V_155 )
{
if ( ! F_60 ( F_115 ( & V_159 ) ) )
return;
F_206 () ;
}
static void F_207 ( void * V_250 )
{
if ( ! F_60 ( F_115 ( & V_159 ) ) )
return;
F_208 () ;
F_209 () ;
if ( V_250 )
F_161 () ;
}
static inline struct V_174 * F_210 ( struct V_251 * V_252 )
{
return F_211 ( V_252 , struct V_174 , V_252 ) ;
}
static T_8 F_212 ( struct V_253 * V_254 , struct V_251 * V_252 ,
char * V_230 )
{
return sprintf ( V_230 , L_42 , F_210 ( V_252 ) -> V_94 ) ;
}
static T_8 F_213 ( struct V_253 * V_254 , struct V_251 * V_252 ,
const char * V_230 , T_7 V_255 )
{
T_2 V_256 ;
if ( F_214 ( V_230 , 0 , & V_256 ) < 0 )
return - V_224 ;
F_210 ( V_252 ) -> V_94 = V_256 ;
F_204 () ;
return V_255 ;
}
static T_8
F_215 ( struct V_253 * V_254 , struct V_251 * V_252 , char * V_230 )
{
strcpy ( V_230 , V_167 ) ;
strcat ( V_230 , L_7 ) ;
return strlen ( V_167 ) + 1 ;
}
static T_8 F_216 ( struct V_253 * V_254 , struct V_251 * V_252 ,
const char * V_230 , T_7 V_257 )
{
char * V_239 ;
strncpy ( V_167 , V_230 , sizeof( V_167 ) ) ;
V_167 [ sizeof( V_167 ) - 1 ] = 0 ;
V_239 = strchr ( V_167 , '\n' ) ;
if ( V_239 )
* V_239 = 0 ;
return strlen ( V_167 ) + ! ! V_239 ;
}
static T_8 F_217 ( struct V_253 * V_254 ,
struct V_251 * V_252 ,
const char * V_230 , T_7 V_255 )
{
T_2 V_256 ;
if ( F_214 ( V_230 , 0 , & V_256 ) < 0 )
return - V_224 ;
if ( V_49 . V_209 ^ ! ! V_256 ) {
if ( V_256 ) {
F_128 () ;
F_181 ( F_205 , NULL , 1 ) ;
V_49 . V_209 = true ;
} else {
V_49 . V_209 = false ;
F_181 ( F_207 , ( void * ) 1 , 1 ) ;
}
}
return V_255 ;
}
static T_8 F_218 ( struct V_253 * V_254 ,
struct V_251 * V_252 ,
const char * V_230 , T_7 V_255 )
{
T_2 V_256 ;
if ( F_214 ( V_230 , 0 , & V_256 ) < 0 )
return - V_224 ;
if ( V_49 . V_248 ^ ! ! V_256 ) {
if ( V_256 ) {
F_181 ( F_205 , NULL , 1 ) ;
V_49 . V_248 = true ;
} else {
V_49 . V_248 = false ;
F_181 ( F_207 , NULL , 1 ) ;
}
}
return V_255 ;
}
static T_8 F_219 ( struct V_253 * V_254 ,
struct V_251 * V_252 ,
const char * V_230 , T_7 V_255 )
{
T_8 V_18 = F_220 ( V_254 , V_252 , V_230 , V_255 ) ;
F_204 () ;
return V_18 ;
}
static void F_221 ( struct V_253 * V_258 )
{
F_183 ( V_258 ) ;
}
static int F_222 ( unsigned int V_3 )
{
struct V_253 * V_258 ;
int V_180 ;
int V_27 , V_259 ;
if ( ! F_60 ( & V_7 ) )
return - V_260 ;
V_258 = F_139 ( sizeof *V_258 , V_175 ) ;
if ( ! V_258 )
return - V_176 ;
V_258 -> V_261 = V_3 ;
V_258 -> V_262 = & V_263 ;
V_258 -> V_264 = & F_221 ;
V_180 = F_223 ( V_258 ) ;
if ( V_180 )
return V_180 ;
for ( V_27 = 0 ; V_265 [ V_27 ] ; V_27 ++ ) {
V_180 = F_224 ( V_258 , V_265 [ V_27 ] ) ;
if ( V_180 )
goto error;
}
for ( V_259 = 0 ; V_259 < V_49 . V_92 ; V_259 ++ ) {
V_180 = F_224 ( V_258 , & V_93 [ V_259 ] . V_252 ) ;
if ( V_180 )
goto V_266;
}
F_225 ( V_3 , V_267 ) ;
F_83 ( V_268 , V_3 ) = V_258 ;
return 0 ;
V_266:
while ( -- V_259 >= 0 )
F_226 ( V_258 , & V_93 [ V_259 ] . V_252 ) ;
error:
while ( -- V_27 >= 0 )
F_226 ( V_258 , V_265 [ V_27 ] ) ;
F_227 ( V_258 ) ;
return V_180 ;
}
static void F_228 ( unsigned int V_3 )
{
struct V_253 * V_258 = F_83 ( V_268 , V_3 ) ;
int V_27 ;
if ( ! F_229 ( V_3 , V_267 ) )
return;
for ( V_27 = 0 ; V_265 [ V_27 ] ; V_27 ++ )
F_226 ( V_258 , V_265 [ V_27 ] ) ;
for ( V_27 = 0 ; V_27 < V_49 . V_92 ; V_27 ++ )
F_226 ( V_258 , & V_93 [ V_27 ] . V_252 ) ;
F_227 ( V_258 ) ;
F_230 ( V_3 , V_267 ) ;
F_83 ( V_268 , V_3 ) = NULL ;
}
static void F_231 ( void * V_269 )
{
unsigned long V_270 = * ( unsigned long * ) V_269 ;
int V_27 ;
if ( ! F_60 ( F_115 ( & V_159 ) ) )
return;
if ( ! ( V_270 & V_271 ) )
F_206 () ;
for ( V_27 = 0 ; V_27 < V_49 . V_92 ; V_27 ++ ) {
struct V_174 * V_90 = & V_93 [ V_27 ] ;
if ( V_90 -> V_177 )
F_52 ( F_147 ( V_27 ) , 0 ) ;
}
}
static void F_232 ( void * V_269 )
{
unsigned long V_270 = * ( unsigned long * ) V_269 ;
int V_27 ;
if ( ! F_60 ( F_115 ( & V_159 ) ) )
return;
if ( ! ( V_270 & V_271 ) )
F_208 () ;
for ( V_27 = 0 ; V_27 < V_49 . V_92 ; V_27 ++ ) {
struct V_174 * V_90 = & V_93 [ V_27 ] ;
if ( V_90 -> V_177 )
F_52 ( F_147 ( V_27 ) , V_90 -> V_94 ) ;
}
}
static int
F_233 ( struct V_32 * V_272 , unsigned long V_270 , void * V_273 )
{
unsigned int V_3 = ( unsigned long ) V_273 ;
struct V_156 * V_104 = & F_83 ( V_157 , V_3 ) ;
switch ( V_270 & ~ V_271 ) {
case V_274 :
F_222 ( V_3 ) ;
if ( V_275 )
V_275 ( V_270 , V_3 ) ;
break;
case V_276 :
if ( V_275 )
V_275 ( V_270 , V_3 ) ;
F_228 ( V_3 ) ;
F_234 ( V_3 ) ;
break;
case V_277 :
F_235 ( V_3 , F_231 , & V_270 , 1 ) ;
F_130 ( V_104 ) ;
break;
case V_278 :
F_235 ( V_3 , F_232 , & V_270 , 1 ) ;
F_160 ( V_3 , V_104 ) ;
break;
}
if ( V_270 == V_279 ) {
F_236 () ;
}
return V_280 ;
}
static T_11 void F_237 ( void )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_49 . V_92 ; V_27 ++ ) {
struct V_174 * V_90 = & V_93 [ V_27 ] ;
struct V_251 * V_281 = & V_90 -> V_252 ;
F_238 ( & V_281 -> V_252 ) ;
V_281 -> V_252 . V_282 = V_90 -> V_283 ;
snprintf ( V_90 -> V_283 , V_284 , L_43 , V_27 ) ;
V_281 -> V_252 . V_285 = 0644 ;
V_281 -> V_286 = F_212 ;
V_281 -> V_287 = F_213 ;
}
}
static T_11 int F_239 ( void )
{
int V_180 ;
int V_27 = 0 ;
if ( ! F_60 ( & V_7 ) )
return - V_260 ;
F_240 ( & V_267 , V_175 ) ;
F_237 () ;
V_180 = F_241 ( & V_263 , NULL ) ;
if ( V_180 )
return V_180 ;
F_129 (i) {
V_180 = F_222 ( V_27 ) ;
if ( V_180 )
return V_180 ;
}
F_242 ( & V_288 ) ;
F_243 ( & V_289 ) ;
F_244 ( & V_290 ) ;
return V_180 ;
}
static int T_11 F_245 ( char * V_247 )
{
V_49 . V_77 = true ;
return 1 ;
}
struct V_291 * F_246 ( void )
{
static struct V_291 * V_292 ;
if ( ! V_292 )
V_292 = F_247 ( L_44 , NULL ) ;
return V_292 ;
}
static void F_248 ( void )
{
V_58 = 0 ;
F_88 ( & V_55 , 0 ) ;
F_88 ( & V_119 , 0 ) ;
F_88 ( & V_118 , 0 ) ;
F_88 ( & V_117 , 0 ) ;
}
static int F_249 ( void * V_155 , T_2 * V_201 )
{
* V_201 = V_53 ;
return 0 ;
}
static int F_250 ( void * V_155 , T_2 V_201 )
{
F_248 () ;
V_53 = V_201 ;
return 0 ;
}
static int T_11 F_251 ( void )
{
struct V_291 * V_292 , * V_293 ;
V_292 = F_246 () ;
if ( ! V_292 )
return - V_176 ;
V_293 = F_252 ( L_45 , 0444 , V_292 , NULL ,
& V_294 ) ;
if ( ! V_293 )
return - V_176 ;
return 0 ;
}
