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
}
if ( V_61 )
V_2 -> V_38 = F_47 ( V_61 ) ;
}
}
static int F_54 ( void )
{
struct V_68 * V_69 = & F_48 ( V_68 ) ;
return V_69 -> V_29 == V_69 -> V_70 ;
}
static int F_55 ( unsigned long * V_71 )
{
struct V_68 * V_69 ;
int V_18 = 0 ;
* V_71 = 0 ;
F_56 () ;
V_69 = & F_48 ( V_68 ) ;
if ( V_69 -> V_29 == V_69 -> V_70 )
goto V_72;
* V_71 = V_69 -> V_73 [ V_69 -> V_29 ] ;
V_69 -> V_29 = ( V_69 -> V_29 + 1 ) % V_74 ;
V_18 = 1 ;
V_72:
F_57 () ;
return V_18 ;
}
static int F_58 ( unsigned long V_71 )
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
int F_59 ( struct V_75 * V_76 )
{
if ( V_77 )
return 0 ;
return F_60 ( V_76 , V_78 ) && F_60 ( V_76 , V_79 ) ;
}
static void F_61 ( void )
{
if ( ! F_54 () ) {
struct V_80 * V_81 = & F_48 ( V_82 ) ;
if ( ! F_62 ( V_81 ) )
F_63 ( V_81 ) ;
}
}
static void F_64 ( struct V_83 * V_17 )
{
F_65 () ;
F_61 () ;
}
static void F_66 ( struct V_65 * V_66 )
{
if ( V_66 -> V_25 & ( V_84 | V_85 ) ) {
F_65 () ;
F_61 () ;
return;
}
F_67 ( & F_48 ( V_86 ) ) ;
}
static void F_68 ( struct V_1 * V_2 , int V_27 )
{
if ( V_2 -> V_37 & V_87 )
V_2 -> V_43 = F_47 ( F_46 ( V_27 ) ) ;
if ( V_2 -> V_37 & V_88 ) {
V_2 -> V_42 = F_47 ( F_45 ( V_27 ) ) ;
if ( V_89 && ( V_2 -> V_37 & V_87 ) ) {
T_3 V_90 = F_69 ( V_2 -> V_43 ) ;
V_2 -> V_42 >>= V_90 ;
V_2 -> V_42 <<= V_90 ;
}
}
}
void F_70 ( enum V_91 V_25 , T_4 * V_92 )
{
struct V_1 V_2 ;
int V_27 ;
F_71 ( V_93 ) ;
F_53 ( & V_2 , NULL ) ;
for ( V_27 = 0 ; V_27 < V_94 ; V_27 ++ ) {
if ( ! V_95 [ V_27 ] . V_96 || ! F_72 ( V_27 , * V_92 ) )
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
F_68 ( & V_2 , V_27 ) ;
if ( ! ( V_25 & V_99 ) )
V_2 . V_5 = 0 ;
if ( ! ( V_25 & V_100 ) && ! V_101 )
F_8 ( & V_2 ) ;
F_51 ( F_44 ( V_27 ) , 0 ) ;
}
F_73 () ;
}
static int F_74 ( struct V_1 * V_2 , char * * V_50 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_94 ; V_27 ++ ) {
V_2 -> V_37 = F_47 ( F_44 ( V_27 ) ) ;
if ( F_75 ( V_2 , V_102 , V_50 ) >= V_103 )
return 1 ;
}
return 0 ;
}
static int F_76 ( T_2 * V_104 )
{
F_77 () ;
if ( F_78 ( & V_54 ) )
F_30 () ;
if ( ! V_105 )
goto V_72;
if ( ( V_106 ) * V_104 < V_107 ) {
if ( V_102 < 1 )
F_35 ( L_18 ,
NULL , NULL ) ;
V_58 = 1 ;
return 1 ;
}
* V_104 -= V_107 ;
V_72:
F_79 () ;
return 0 ;
}
static void F_80 ( void )
{
int V_3 ;
struct V_1 * V_2 = NULL ;
int V_108 = 0 ;
char * V_50 = NULL ;
char * V_109 = NULL ;
F_81 (cpu) {
int V_110 = F_75 ( & F_82 ( V_111 , V_3 ) , V_102 ,
& V_109 ) ;
if ( V_110 > V_108 ) {
V_50 = V_109 ;
V_108 = V_110 ;
V_2 = & F_82 ( V_111 , V_3 ) ;
}
}
if ( V_2 && V_108 >= V_103 && V_102 < 3 )
F_35 ( L_19 , V_2 , V_50 ) ;
if ( V_108 <= V_112 && V_102 < 3 )
F_35 ( L_20 , NULL , NULL ) ;
F_81 (cpu)
memset ( & F_82 ( V_111 , V_3 ) , 0 , sizeof( struct V_1 ) ) ;
}
static int F_83 ( int * V_113 )
{
int V_114 ;
int V_115 = F_84 () ;
T_2 V_45 = ( T_2 ) V_105 * V_116 ;
if ( ! V_45 )
return - 1 ;
F_85 ( * V_113 , & V_117 ) ;
F_86 () ;
V_114 = F_36 ( & V_118 ) ;
while ( F_78 ( & V_118 ) != V_115 ) {
if ( F_76 ( & V_45 ) ) {
F_87 ( & V_117 , 0 ) ;
return - 1 ;
}
F_88 ( V_107 ) ;
}
F_14 () ;
if ( V_114 == 1 ) {
F_87 ( & V_119 , 1 ) ;
} else {
while ( F_78 ( & V_119 ) < V_114 ) {
if ( F_76 ( & V_45 ) ) {
F_87 ( & V_117 , 0 ) ;
return - 1 ;
}
F_88 ( V_107 ) ;
}
}
* V_113 = F_78 ( & V_117 ) ;
return V_114 ;
}
static int F_89 ( int V_114 )
{
int V_18 = - 1 ;
T_2 V_45 = ( T_2 ) V_105 * V_116 ;
if ( ! V_45 )
goto V_120;
if ( V_114 < 0 )
goto V_120;
F_90 ( & V_119 ) ;
if ( V_114 == 1 ) {
int V_115 = F_84 () ;
while ( F_78 ( & V_119 ) <= V_115 ) {
if ( F_76 ( & V_45 ) )
goto V_120;
F_88 ( V_107 ) ;
}
F_80 () ;
F_37 () ;
V_18 = 0 ;
} else {
while ( F_78 ( & V_119 ) != 0 ) {
if ( F_76 ( & V_45 ) )
goto V_120;
F_88 ( V_107 ) ;
}
return 0 ;
}
V_120:
F_87 ( & V_117 , 0 ) ;
F_87 ( & V_118 , 0 ) ;
F_37 () ;
F_87 ( & V_119 , 0 ) ;
return V_18 ;
}
static int F_91 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_37 & V_87 ) || ! ( V_2 -> V_37 & V_88 ) )
return 0 ;
if ( F_69 ( V_2 -> V_43 ) > V_121 )
return 0 ;
if ( F_92 ( V_2 -> V_43 ) != V_122 )
return 0 ;
return 1 ;
}
static void F_93 ( unsigned long * V_123 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_94 ; V_27 ++ ) {
if ( F_72 ( V_27 , V_123 ) )
F_51 ( F_44 ( V_27 ) , 0 ) ;
}
}
static void F_94 ( T_5 V_42 , int V_76 )
{
struct V_124 * V_125 ;
for ( V_125 = V_124 ; V_125 < & V_124 [ V_126 ] ; V_125 ++ ) {
if ( F_95 ( & V_125 -> V_127 , 0 , 1 ) == 0 ) {
V_125 -> V_104 = V_128 ;
V_125 -> V_129 = V_42 ;
V_125 -> V_130 = V_76 ;
return;
}
}
F_35 ( L_21 , NULL , NULL ) ;
}
static struct V_124 * F_96 ( void )
{
struct V_124 * V_125 ;
for ( V_125 = V_124 ; V_125 < & V_124 [ V_126 ] ; V_125 ++ )
if ( F_78 ( & V_125 -> V_127 ) && V_125 -> V_104 == V_128 )
return V_125 ;
return NULL ;
}
static void F_97 ( struct V_124 * V_125 )
{
F_87 ( & V_125 -> V_127 , 0 ) ;
}
void F_98 ( struct V_65 * V_66 , long V_131 )
{
struct V_1 V_2 , * V_51 ;
int V_27 ;
int V_132 = 0 ;
int V_110 ;
int V_114 ;
int V_113 = 0 ;
int V_133 = 0 ;
F_99 ( V_123 , V_134 ) ;
char * V_50 = L_22 ;
F_90 ( & V_135 ) ;
F_71 ( V_136 ) ;
if ( ! V_94 )
goto V_72;
F_53 ( & V_2 , V_66 ) ;
V_51 = & F_48 ( V_111 ) ;
* V_51 = V_2 ;
V_113 = F_74 ( & V_2 , & V_50 ) ;
F_37 () ;
if ( ! ( V_2 . V_35 & V_67 ) )
V_133 = 1 ;
V_114 = F_83 ( & V_113 ) ;
for ( V_27 = 0 ; V_27 < V_94 ; V_27 ++ ) {
F_100 ( V_27 , V_123 ) ;
if ( ! V_95 [ V_27 ] . V_96 )
continue;
V_2 . V_43 = 0 ;
V_2 . V_42 = 0 ;
V_2 . V_36 = V_27 ;
V_2 . V_37 = F_47 ( F_44 ( V_27 ) ) ;
if ( ( V_2 . V_37 & V_56 ) == 0 )
continue;
if ( ! ( V_2 . V_37 & ( V_89 ? V_98 : V_57 ) ) &&
! V_113 )
continue;
F_101 ( V_137 ) ;
V_110 = F_75 ( & V_2 , V_102 , NULL ) ;
if ( V_110 == V_112 && ! V_113 )
continue;
F_102 ( V_27 , V_123 ) ;
if ( V_110 == V_138 ) {
continue;
}
F_68 ( & V_2 , V_27 ) ;
if ( V_110 == V_139 && F_91 ( & V_2 ) )
F_58 ( V_2 . V_42 >> V_121 ) ;
F_8 ( & V_2 ) ;
if ( V_110 > V_132 ) {
* V_51 = V_2 ;
V_132 = V_110 ;
}
}
V_2 = * V_51 ;
if ( ! V_113 )
F_93 ( V_123 ) ;
if ( F_89 ( V_114 ) < 0 )
V_113 = V_132 >= V_103 ;
if ( V_102 < 3 ) {
if ( V_113 )
F_35 ( L_23 , & V_2 , V_50 ) ;
if ( V_132 == V_140 ) {
F_94 ( V_2 . V_42 , V_2 . V_35 & V_67 ) ;
F_103 ( V_141 ) ;
} else if ( V_133 ) {
F_104 ( V_142 , V_128 ) ;
}
}
if ( V_132 > 0 )
F_66 ( V_66 ) ;
F_51 ( V_62 , 0 ) ;
V_72:
F_105 ( & V_135 ) ;
F_73 () ;
}
int F_106 ( unsigned long V_71 , int V_143 , int V_25 )
{
F_107 ( V_25 & V_144 ) ;
F_108 ( V_145 L_24
L_25 , V_71 ) ;
return 0 ;
}
void F_109 ( void )
{
unsigned long V_71 ;
struct V_124 * V_125 = F_96 () ;
if ( ! V_125 )
F_35 ( L_26 , NULL , NULL ) ;
V_71 = V_125 -> V_129 >> V_121 ;
F_110 ( V_141 ) ;
F_20 ( L_27 ,
V_125 -> V_129 ) ;
if ( F_106 ( V_71 , V_146 , V_144 ) < 0 ||
V_125 -> V_130 == 0 ) {
F_20 ( L_28 ) ;
F_104 ( V_142 , V_128 ) ;
}
F_97 ( V_125 ) ;
}
static void F_111 ( struct V_80 * V_147 )
{
unsigned long V_71 ;
while ( F_55 ( & V_71 ) )
F_106 ( V_71 , V_146 , 0 ) ;
}
void F_112 ( T_5 V_37 )
{
struct V_1 V_2 ;
F_1 ( & V_2 ) ;
V_2 . V_36 = V_148 ;
V_2 . V_37 = V_37 ;
F_8 ( & V_2 ) ;
}
static void F_113 ( unsigned long V_149 )
{
struct V_150 * V_104 = & F_82 ( V_151 , V_149 ) ;
int * V_152 ;
F_114 ( F_2 () != V_149 ) ;
if ( F_59 ( F_115 ( & V_153 ) ) ) {
F_70 ( V_99 ,
& F_48 ( V_154 ) ) ;
}
V_152 = & F_48 ( V_155 ) ;
if ( F_65 () )
* V_152 = F_116 ( * V_152 / 2 , V_156 / 100 ) ;
else
* V_152 = F_117 ( * V_152 * 2 , ( int ) F_118 ( V_157 * V_156 ) ) ;
V_104 -> V_158 = V_30 + * V_152 ;
F_119 ( V_104 , F_2 () ) ;
}
static void F_120 ( void )
{
int V_3 ;
F_121 (cpu)
F_122 ( & F_82 ( V_151 , V_3 ) ) ;
}
static void F_123 ( struct V_80 * V_81 )
{
F_124 ( V_159 , V_160 , NULL , V_161 ) ;
}
int F_65 ( void )
{
static F_125 ( V_162 , 60 * V_156 , 2 ) ;
if ( F_126 ( 0 , & V_26 ) ) {
F_127 ( & V_163 ) ;
if ( V_159 [ 0 ] && ! F_62 ( & V_164 ) )
F_63 ( & V_164 ) ;
if ( F_128 ( & V_162 ) )
F_129 ( V_34 L_29 ) ;
return 1 ;
}
return 0 ;
}
static int T_6 F_130 ( void )
{
int V_27 ;
V_95 = F_131 ( V_94 * sizeof( struct V_165 ) , V_166 ) ;
if ( ! V_95 )
return - V_167 ;
for ( V_27 = 0 ; V_27 < V_94 ; V_27 ++ ) {
struct V_165 * V_92 = & V_95 [ V_27 ] ;
V_92 -> V_96 = - 1ULL ;
V_92 -> V_168 = 1 ;
}
return 0 ;
}
static int T_6 F_132 ( void )
{
unsigned V_92 ;
T_2 V_169 ;
F_7 ( V_14 , V_169 ) ;
V_92 = V_169 & V_170 ;
if ( ! V_94 )
F_108 ( V_171 L_30 , V_92 ) ;
if ( V_92 > V_134 ) {
F_108 ( V_172
L_31 ,
V_134 , V_92 ) ;
V_92 = V_134 ;
}
F_114 ( V_94 != 0 && V_92 != V_94 ) ;
V_94 = V_92 ;
if ( ! V_95 ) {
int V_173 = F_130 () ;
if ( V_173 )
return V_173 ;
}
if ( ( V_169 & V_174 ) && F_133 ( V_169 ) >= 9 )
V_61 = V_175 ;
if ( V_169 & V_176 )
V_89 = 1 ;
return 0 ;
}
static void F_134 ( void )
{
T_4 V_177 ;
T_2 V_169 ;
int V_27 ;
F_135 ( V_177 , V_134 ) ;
F_70 ( V_97 | ( ! V_178 ? V_100 : 0 ) , & V_177 ) ;
F_136 ( V_179 ) ;
F_7 ( V_14 , V_169 ) ;
if ( V_169 & V_180 )
F_137 ( V_181 , 0xffffffff , 0xffffffff ) ;
for ( V_27 = 0 ; V_27 < V_94 ; V_27 ++ ) {
struct V_165 * V_92 = & V_95 [ V_27 ] ;
if ( ! V_92 -> V_168 )
continue;
F_52 ( F_138 ( V_27 ) , V_92 -> V_96 ) ;
F_52 ( F_44 ( V_27 ) , 0 ) ;
}
}
static int T_6 F_139 ( struct V_75 * V_76 )
{
if ( V_76 -> V_8 == V_182 ) {
F_129 ( L_32 ) ;
return - V_183 ;
}
if ( V_76 -> V_8 == V_184 ) {
if ( V_76 -> V_185 == 15 && V_94 > 4 ) {
F_140 ( 10 , ( unsigned long * ) & V_95 [ 4 ] . V_96 ) ;
}
if ( V_76 -> V_185 <= 17 && V_178 < 0 ) {
V_178 = 0 ;
}
if ( V_76 -> V_185 == 6 && V_94 > 0 )
V_95 [ 0 ] . V_96 = 0 ;
}
if ( V_76 -> V_8 == V_186 ) {
if ( V_76 -> V_185 == 6 && V_76 -> V_187 < 0x1A && V_94 > 0 )
V_95 [ 0 ] . V_168 = 0 ;
if ( ( V_76 -> V_185 > 6 || ( V_76 -> V_185 == 6 && V_76 -> V_187 >= 0xe ) ) &&
V_105 < 0 )
V_105 = V_47 ;
if ( V_76 -> V_185 == 6 && V_76 -> V_187 <= 13 && V_178 < 0 )
V_178 = 0 ;
}
if ( V_105 < 0 )
V_105 = 0 ;
if ( V_178 != 0 )
V_49 = 30 ;
return 0 ;
}
static int T_6 F_141 ( struct V_75 * V_76 )
{
if ( V_76 -> V_185 != 5 )
return 0 ;
switch ( V_76 -> V_8 ) {
case V_186 :
F_142 ( V_76 ) ;
return 1 ;
break;
case V_188 :
F_143 ( V_76 ) ;
return 1 ;
break;
}
return 0 ;
}
static void F_144 ( struct V_75 * V_76 )
{
switch ( V_76 -> V_8 ) {
case V_186 :
F_145 ( V_76 ) ;
break;
case V_184 :
F_146 ( V_76 ) ;
break;
default:
break;
}
}
static void F_147 ( void )
{
struct V_150 * V_104 = & F_48 ( V_151 ) ;
int * V_152 = & F_48 ( V_155 ) ;
F_148 ( V_104 , F_113 , F_2 () ) ;
if ( V_189 )
return;
* V_152 = V_157 * V_156 ;
if ( ! * V_152 )
return;
V_104 -> V_158 = F_149 ( V_30 + * V_152 ) ;
F_119 ( V_104 , F_2 () ) ;
}
static void F_150 ( struct V_65 * V_66 , long V_131 )
{
F_108 ( V_145 L_33 ,
F_2 () ) ;
}
void T_6 F_151 ( struct V_75 * V_76 )
{
if ( V_77 )
return;
if ( F_141 ( V_76 ) )
return;
if ( ! F_59 ( V_76 ) )
return;
if ( F_132 () < 0 || F_139 ( V_76 ) < 0 ) {
V_77 = 1 ;
return;
}
V_190 = F_98 ;
F_134 () ;
F_144 ( V_76 ) ;
F_147 () ;
F_152 ( & F_48 ( V_82 ) , F_111 ) ;
F_153 ( & F_48 ( V_86 ) , & F_64 ) ;
}
static int F_154 ( struct V_191 * V_191 , struct V_192 * V_192 )
{
F_155 ( & V_193 ) ;
if ( V_194 ||
( V_195 && ( V_192 -> V_196 & V_197 ) ) ) {
F_156 ( & V_193 ) ;
return - V_198 ;
}
if ( V_192 -> V_196 & V_197 )
V_194 = 1 ;
V_195 ++ ;
F_156 ( & V_193 ) ;
return F_157 ( V_191 , V_192 ) ;
}
static int F_158 ( struct V_191 * V_191 , struct V_192 * V_192 )
{
F_155 ( & V_193 ) ;
V_195 -- ;
V_194 = 0 ;
F_156 ( & V_193 ) ;
return 0 ;
}
static void F_159 ( void * V_149 )
{
unsigned long * V_199 = ( unsigned long * ) V_149 ;
F_3 ( V_199 [ F_2 () ] ) ;
}
static int F_160 ( char T_7 * * V_200 , T_8 V_201 )
{
int V_202 ;
T_2 V_203 ;
struct V_1 V_2 ;
if ( V_201 < sizeof( struct V_1 ) )
return - V_204 ;
V_202 = F_161 ( & V_2 , & V_203 ) ;
if ( V_202 <= 0 ) {
V_205 = 1 ;
if ( V_202 == - V_206 )
return 0 ;
return V_202 ;
}
V_202 = - V_207 ;
if ( F_162 ( * V_200 , & V_2 , sizeof( struct V_1 ) ) )
return V_202 ;
V_202 = F_163 ( V_203 ) ;
if ( V_202 ) {
V_205 = 1 ;
return V_202 ;
}
* V_200 += sizeof( struct V_1 ) ;
return 0 ;
}
static T_9 F_164 ( struct V_192 * V_208 , char T_7 * V_200 ,
T_8 V_201 , T_10 * V_209 )
{
char T_7 * V_210 = V_200 ;
unsigned long * V_199 ;
unsigned V_28 , V_16 ;
int V_27 , V_173 ;
V_199 = F_165 ( V_211 * sizeof( long ) , V_166 ) ;
if ( ! V_199 )
return - V_167 ;
F_166 ( & V_212 ) ;
if ( ! V_205 ) {
V_173 = F_160 ( & V_210 , V_201 ) ;
if ( V_173 || V_210 != V_200 )
goto V_72;
}
V_16 = F_12 ( V_22 . V_16 ) ;
V_173 = - V_204 ;
if ( * V_209 != 0 || V_201 < V_23 * sizeof( struct V_1 ) )
goto V_72;
V_173 = 0 ;
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
V_173 |= F_162 ( V_210 , V_2 , sizeof( * V_2 ) ) ;
V_210 += sizeof( * V_2 ) ;
V_45:
;
}
memset ( V_22 . V_17 + V_28 , 0 ,
( V_16 - V_28 ) * sizeof( struct V_1 ) ) ;
V_28 = V_16 ;
V_16 = F_15 ( & V_22 . V_16 , V_28 , 0 ) ;
} while ( V_16 != V_28 );
F_167 () ;
F_168 ( F_159 , V_199 , 1 ) ;
for ( V_27 = V_16 ; V_27 < V_23 ; V_27 ++ ) {
struct V_1 * V_2 = & V_22 . V_17 [ V_27 ] ;
if ( V_2 -> V_21 && V_2 -> V_5 < V_199 [ V_2 -> V_3 ] ) {
V_173 |= F_162 ( V_210 , V_2 , sizeof( * V_2 ) ) ;
F_14 () ;
V_210 += sizeof( * V_2 ) ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
}
}
if ( V_173 )
V_173 = - V_207 ;
V_72:
F_169 ( & V_212 ) ;
F_170 ( V_199 ) ;
return V_173 ? V_173 : V_210 - V_200 ;
}
static unsigned int F_171 ( struct V_192 * V_192 , T_11 * V_213 )
{
F_172 ( V_192 , & V_163 , V_213 ) ;
if ( F_173 ( V_22 . V_16 ) )
return V_214 | V_215 ;
if ( ! V_205 && F_174 () )
return V_214 | V_215 ;
return 0 ;
}
static long F_175 ( struct V_192 * V_216 , unsigned int V_217 ,
unsigned long V_218 )
{
int T_7 * V_219 = ( int T_7 * ) V_218 ;
if ( ! F_176 ( V_220 ) )
return - V_221 ;
switch ( V_217 ) {
case V_222 :
return F_177 ( sizeof( struct V_1 ) , V_219 ) ;
case V_223 :
return F_177 ( V_23 , V_219 ) ;
case V_224 : {
unsigned V_25 ;
do {
V_25 = V_22 . V_25 ;
} while ( F_15 ( & V_22 . V_25 , V_25 , 0 ) != V_25 );
return F_177 ( V_25 , V_219 ) ;
}
default:
return - V_225 ;
}
}
void F_178 ( T_9 (* F_179)( struct V_192 * V_208 ,
const char T_7 * V_200 ,
T_8 V_201 , T_10 * V_209 ) )
{
V_226 = F_179 ;
}
T_9 F_180 ( struct V_192 * V_208 , const char T_7 * V_200 ,
T_8 V_201 , T_10 * V_209 )
{
if ( V_226 )
return V_226 ( V_208 , V_200 , V_201 , V_209 ) ;
else
return - V_204 ;
}
static int T_12 F_181 ( char * V_227 )
{
if ( * V_227 == 0 ) {
F_182 () ;
return 1 ;
}
if ( * V_227 == '=' )
V_227 ++ ;
if ( ! strcmp ( V_227 , L_34 ) )
V_77 = 1 ;
else if ( ! strcmp ( V_227 , L_35 ) )
V_228 = 1 ;
else if ( ! strcmp ( V_227 , L_36 ) )
V_101 = 1 ;
else if ( ! strcmp ( V_227 , L_37 ) )
V_189 = 1 ;
else if ( ! strcmp ( V_227 , L_38 ) || ! strcmp ( V_227 , L_39 ) )
V_178 = ( V_227 [ 0 ] == 'b' ) ;
else if ( isdigit ( V_227 [ 0 ] ) ) {
F_183 ( & V_227 , & V_102 ) ;
if ( * V_227 == ',' ) {
++ V_227 ;
F_183 ( & V_227 , & V_105 ) ;
}
} else {
F_108 ( V_171 L_40 ,
V_227 ) ;
return 0 ;
}
return 1 ;
}
int T_12 F_184 ( void )
{
F_185 () ;
return 0 ;
}
static int F_186 ( void )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_94 ; V_27 ++ ) {
struct V_165 * V_92 = & V_95 [ V_27 ] ;
if ( V_92 -> V_168 )
F_52 ( F_138 ( V_27 ) , 0 ) ;
}
return 0 ;
}
static int F_187 ( void )
{
return F_186 () ;
}
static void F_188 ( void )
{
F_186 () ;
}
static void F_189 ( void )
{
F_134 () ;
F_144 ( F_115 ( & V_153 ) ) ;
}
static void F_190 ( void * V_149 )
{
if ( ! F_59 ( F_115 ( & V_153 ) ) )
return;
F_134 () ;
F_147 () ;
}
static void F_191 ( void )
{
F_120 () ;
F_168 ( F_190 , NULL , 1 ) ;
}
static void F_192 ( void * V_149 )
{
if ( ! F_59 ( F_115 ( & V_153 ) ) )
return;
F_193 () ;
}
static void F_194 ( void * V_229 )
{
if ( ! F_59 ( F_115 ( & V_153 ) ) )
return;
F_195 () ;
F_196 () ;
if ( V_229 )
F_147 () ;
}
static inline struct V_165 * F_197 ( struct V_230 * V_231 )
{
return F_198 ( V_231 , struct V_165 , V_231 ) ;
}
static T_9 F_199 ( struct V_232 * V_233 , struct V_230 * V_231 ,
char * V_210 )
{
return sprintf ( V_210 , L_41 , F_197 ( V_231 ) -> V_96 ) ;
}
static T_9 F_200 ( struct V_232 * V_233 , struct V_230 * V_231 ,
const char * V_210 , T_8 V_234 )
{
T_2 V_235 ;
if ( F_201 ( V_210 , 0 , & V_235 ) < 0 )
return - V_204 ;
F_197 ( V_231 ) -> V_96 = V_235 ;
F_191 () ;
return V_234 ;
}
static T_9
F_202 ( struct V_232 * V_233 , struct V_230 * V_231 , char * V_210 )
{
strcpy ( V_210 , V_159 ) ;
strcat ( V_210 , L_7 ) ;
return strlen ( V_159 ) + 1 ;
}
static T_9 F_203 ( struct V_232 * V_233 , struct V_230 * V_231 ,
const char * V_210 , T_8 V_236 )
{
char * V_219 ;
strncpy ( V_159 , V_210 , sizeof( V_159 ) ) ;
V_159 [ sizeof( V_159 ) - 1 ] = 0 ;
V_219 = strchr ( V_159 , '\n' ) ;
if ( V_219 )
* V_219 = 0 ;
return strlen ( V_159 ) + ! ! V_219 ;
}
static T_9 F_204 ( struct V_232 * V_233 ,
struct V_230 * V_231 ,
const char * V_210 , T_8 V_234 )
{
T_2 V_235 ;
if ( F_201 ( V_210 , 0 , & V_235 ) < 0 )
return - V_204 ;
if ( V_189 ^ ! ! V_235 ) {
if ( V_235 ) {
F_120 () ;
F_168 ( F_192 , NULL , 1 ) ;
V_189 = 1 ;
} else {
V_189 = 0 ;
F_168 ( F_194 , ( void * ) 1 , 1 ) ;
}
}
return V_234 ;
}
static T_9 F_205 ( struct V_232 * V_233 ,
struct V_230 * V_231 ,
const char * V_210 , T_8 V_234 )
{
T_2 V_235 ;
if ( F_201 ( V_210 , 0 , & V_235 ) < 0 )
return - V_204 ;
if ( V_228 ^ ! ! V_235 ) {
if ( V_235 ) {
F_168 ( F_192 , NULL , 1 ) ;
V_228 = 1 ;
} else {
V_228 = 0 ;
F_168 ( F_194 , NULL , 1 ) ;
}
}
return V_234 ;
}
static T_9 F_206 ( struct V_232 * V_233 ,
struct V_230 * V_231 ,
const char * V_210 , T_8 V_234 )
{
T_9 V_18 = F_207 ( V_233 , V_231 , V_210 , V_234 ) ;
F_191 () ;
return V_18 ;
}
static void F_208 ( struct V_232 * V_237 )
{
F_170 ( V_237 ) ;
}
static T_6 int F_209 ( unsigned int V_3 )
{
struct V_232 * V_237 ;
int V_173 ;
int V_27 , V_238 ;
if ( ! F_59 ( & V_7 ) )
return - V_239 ;
V_237 = F_131 ( sizeof *V_237 , V_166 ) ;
if ( ! V_237 )
return - V_167 ;
V_237 -> V_240 = V_3 ;
V_237 -> V_241 = & V_242 ;
V_237 -> V_243 = & F_208 ;
V_173 = F_210 ( V_237 ) ;
if ( V_173 )
return V_173 ;
for ( V_27 = 0 ; V_244 [ V_27 ] ; V_27 ++ ) {
V_173 = F_211 ( V_237 , V_244 [ V_27 ] ) ;
if ( V_173 )
goto error;
}
for ( V_238 = 0 ; V_238 < V_94 ; V_238 ++ ) {
V_173 = F_211 ( V_237 , & V_95 [ V_238 ] . V_231 ) ;
if ( V_173 )
goto V_245;
}
F_212 ( V_3 , V_246 ) ;
F_82 ( V_247 , V_3 ) = V_237 ;
return 0 ;
V_245:
while ( -- V_238 >= 0 )
F_213 ( V_237 , & V_95 [ V_238 ] . V_231 ) ;
error:
while ( -- V_27 >= 0 )
F_213 ( V_237 , V_244 [ V_27 ] ) ;
F_214 ( V_237 ) ;
return V_173 ;
}
static T_6 void F_215 ( unsigned int V_3 )
{
struct V_232 * V_237 = F_82 ( V_247 , V_3 ) ;
int V_27 ;
if ( ! F_216 ( V_3 , V_246 ) )
return;
for ( V_27 = 0 ; V_244 [ V_27 ] ; V_27 ++ )
F_213 ( V_237 , V_244 [ V_27 ] ) ;
for ( V_27 = 0 ; V_27 < V_94 ; V_27 ++ )
F_213 ( V_237 , & V_95 [ V_27 ] . V_231 ) ;
F_214 ( V_237 ) ;
F_217 ( V_3 , V_246 ) ;
F_82 ( V_247 , V_3 ) = NULL ;
}
static void T_6 F_218 ( void * V_248 )
{
unsigned long V_249 = * ( unsigned long * ) V_248 ;
int V_27 ;
if ( ! F_59 ( F_115 ( & V_153 ) ) )
return;
if ( ! ( V_249 & V_250 ) )
F_193 () ;
for ( V_27 = 0 ; V_27 < V_94 ; V_27 ++ ) {
struct V_165 * V_92 = & V_95 [ V_27 ] ;
if ( V_92 -> V_168 )
F_52 ( F_138 ( V_27 ) , 0 ) ;
}
}
static void T_6 F_219 ( void * V_248 )
{
unsigned long V_249 = * ( unsigned long * ) V_248 ;
int V_27 ;
if ( ! F_59 ( F_115 ( & V_153 ) ) )
return;
if ( ! ( V_249 & V_250 ) )
F_195 () ;
for ( V_27 = 0 ; V_27 < V_94 ; V_27 ++ ) {
struct V_165 * V_92 = & V_95 [ V_27 ] ;
if ( V_92 -> V_168 )
F_52 ( F_138 ( V_27 ) , V_92 -> V_96 ) ;
}
}
static int T_6
F_220 ( struct V_32 * V_251 , unsigned long V_249 , void * V_252 )
{
unsigned int V_3 = ( unsigned long ) V_252 ;
struct V_150 * V_104 = & F_82 ( V_151 , V_3 ) ;
switch ( V_249 ) {
case V_253 :
case V_254 :
F_209 ( V_3 ) ;
if ( V_255 )
V_255 ( V_249 , V_3 ) ;
break;
case V_256 :
case V_257 :
if ( V_255 )
V_255 ( V_249 , V_3 ) ;
F_215 ( V_3 ) ;
break;
case V_258 :
case V_259 :
F_122 ( V_104 ) ;
F_221 ( V_3 , F_218 , & V_249 , 1 ) ;
break;
case V_260 :
case V_261 :
if ( ! V_189 && V_157 ) {
V_104 -> V_158 = F_149 ( V_30 +
F_48 ( V_155 ) ) ;
F_119 ( V_104 , V_3 ) ;
}
F_221 ( V_3 , F_219 , & V_249 , 1 ) ;
break;
case V_262 :
F_222 ( V_3 ) ;
break;
}
return V_263 ;
}
static T_12 void F_223 ( void )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_94 ; V_27 ++ ) {
struct V_165 * V_92 = & V_95 [ V_27 ] ;
struct V_230 * V_264 = & V_92 -> V_231 ;
F_224 ( & V_264 -> V_231 ) ;
V_264 -> V_231 . V_265 = V_92 -> V_266 ;
snprintf ( V_92 -> V_266 , V_267 , L_42 , V_27 ) ;
V_264 -> V_231 . V_268 = 0644 ;
V_264 -> V_269 = F_199 ;
V_264 -> V_270 = F_200 ;
}
}
static T_12 int F_225 ( void )
{
int V_173 ;
int V_27 = 0 ;
if ( ! F_59 ( & V_7 ) )
return - V_239 ;
F_226 ( & V_246 , V_166 ) ;
F_223 () ;
V_173 = F_227 ( & V_242 , NULL ) ;
if ( V_173 )
return V_173 ;
F_121 (i) {
V_173 = F_209 ( V_27 ) ;
if ( V_173 )
return V_173 ;
}
F_228 ( & V_271 ) ;
F_229 ( & V_272 ) ;
F_230 ( & V_273 ) ;
return V_173 ;
}
static int T_12 F_231 ( char * V_227 )
{
V_77 = 1 ;
return 1 ;
}
struct V_274 * F_232 ( void )
{
static struct V_274 * V_275 ;
if ( ! V_275 )
V_275 = F_233 ( L_43 , NULL ) ;
return V_275 ;
}
static void F_234 ( void )
{
V_58 = 0 ;
F_87 ( & V_55 , 0 ) ;
F_87 ( & V_119 , 0 ) ;
F_87 ( & V_118 , 0 ) ;
F_87 ( & V_117 , 0 ) ;
}
static int F_235 ( void * V_149 , T_2 * V_276 )
{
* V_276 = V_53 ;
return 0 ;
}
static int F_236 ( void * V_149 , T_2 V_276 )
{
F_234 () ;
V_53 = V_276 ;
return 0 ;
}
static int T_12 F_237 ( void )
{
struct V_274 * V_275 , * V_277 ;
V_275 = F_232 () ;
if ( ! V_275 )
return - V_167 ;
V_277 = F_238 ( L_44 , 0444 , V_275 , NULL ,
& V_278 ) ;
if ( ! V_277 )
return - V_167 ;
return 0 ;
}
