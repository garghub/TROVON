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
static int F_75 ( struct V_1 * V_2 , char * * V_50 , unsigned long * V_102 ,
struct V_65 * V_66 )
{
int V_27 , V_18 = 0 ;
for ( V_27 = 0 ; V_27 < V_94 ; V_27 ++ ) {
V_2 -> V_37 = F_47 ( F_44 ( V_27 ) ) ;
if ( V_2 -> V_37 & V_56 ) {
F_76 ( V_27 , V_102 ) ;
if ( V_103 )
V_103 ( V_27 , V_2 , V_66 ) ;
}
if ( F_77 ( V_2 , V_104 , V_50 ) >= V_105 )
V_18 = 1 ;
}
return V_18 ;
}
static int F_78 ( T_2 * V_106 )
{
F_79 () ;
if ( F_80 ( & V_54 ) )
F_30 () ;
if ( ! V_107 )
goto V_72;
if ( ( V_108 ) * V_106 < V_109 ) {
if ( V_104 < 1 )
F_35 ( L_18 ,
NULL , NULL ) ;
V_58 = 1 ;
return 1 ;
}
* V_106 -= V_109 ;
V_72:
F_81 () ;
return 0 ;
}
static void F_82 ( void )
{
int V_3 ;
struct V_1 * V_2 = NULL ;
int V_110 = 0 ;
char * V_50 = NULL ;
char * V_111 = NULL ;
F_83 (cpu) {
int V_112 = F_77 ( & F_84 ( V_113 , V_3 ) , V_104 ,
& V_111 ) ;
if ( V_112 > V_110 ) {
V_50 = V_111 ;
V_110 = V_112 ;
V_2 = & F_84 ( V_113 , V_3 ) ;
}
}
if ( V_2 && V_110 >= V_105 && V_104 < 3 )
F_35 ( L_19 , V_2 , V_50 ) ;
if ( V_110 <= V_114 && V_104 < 3 )
F_35 ( L_20 , NULL , NULL ) ;
F_83 (cpu)
memset ( & F_84 ( V_113 , V_3 ) , 0 , sizeof( struct V_1 ) ) ;
}
static int F_85 ( int * V_115 )
{
int V_116 ;
int V_117 = F_86 () ;
T_2 V_45 = ( T_2 ) V_107 * V_118 ;
if ( ! V_45 )
return - 1 ;
F_87 ( * V_115 , & V_119 ) ;
F_88 () ;
V_116 = F_36 ( & V_120 ) ;
while ( F_80 ( & V_120 ) != V_117 ) {
if ( F_78 ( & V_45 ) ) {
F_89 ( & V_119 , 0 ) ;
return - 1 ;
}
F_90 ( V_109 ) ;
}
F_14 () ;
if ( V_116 == 1 ) {
F_89 ( & V_121 , 1 ) ;
} else {
while ( F_80 ( & V_121 ) < V_116 ) {
if ( F_78 ( & V_45 ) ) {
F_89 ( & V_119 , 0 ) ;
return - 1 ;
}
F_90 ( V_109 ) ;
}
}
* V_115 = F_80 ( & V_119 ) ;
return V_116 ;
}
static int F_91 ( int V_116 )
{
int V_18 = - 1 ;
T_2 V_45 = ( T_2 ) V_107 * V_118 ;
if ( ! V_45 )
goto V_122;
if ( V_116 < 0 )
goto V_122;
F_92 ( & V_121 ) ;
if ( V_116 == 1 ) {
int V_117 = F_86 () ;
while ( F_80 ( & V_121 ) <= V_117 ) {
if ( F_78 ( & V_45 ) )
goto V_122;
F_90 ( V_109 ) ;
}
F_82 () ;
F_37 () ;
V_18 = 0 ;
} else {
while ( F_80 ( & V_121 ) != 0 ) {
if ( F_78 ( & V_45 ) )
goto V_122;
F_90 ( V_109 ) ;
}
return 0 ;
}
V_122:
F_89 ( & V_119 , 0 ) ;
F_89 ( & V_120 , 0 ) ;
F_37 () ;
F_89 ( & V_121 , 0 ) ;
return V_18 ;
}
static int F_93 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_37 & V_87 ) || ! ( V_2 -> V_37 & V_88 ) )
return 0 ;
if ( F_70 ( V_2 -> V_43 ) > V_123 )
return 0 ;
if ( F_94 ( V_2 -> V_43 ) != V_124 )
return 0 ;
return 1 ;
}
static void F_95 ( unsigned long * V_125 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_94 ; V_27 ++ ) {
if ( F_73 ( V_27 , V_125 ) )
F_51 ( F_44 ( V_27 ) , 0 ) ;
}
}
static void F_96 ( T_5 V_42 , int V_76 )
{
struct V_126 * V_127 ;
for ( V_127 = V_126 ; V_127 < & V_126 [ V_128 ] ; V_127 ++ ) {
if ( F_97 ( & V_127 -> V_129 , 0 , 1 ) == 0 ) {
V_127 -> V_106 = V_130 ;
V_127 -> V_131 = V_42 ;
V_127 -> V_132 = V_76 ;
return;
}
}
F_35 ( L_21 , NULL , NULL ) ;
}
static struct V_126 * F_98 ( void )
{
struct V_126 * V_127 ;
for ( V_127 = V_126 ; V_127 < & V_126 [ V_128 ] ; V_127 ++ )
if ( F_80 ( & V_127 -> V_129 ) && V_127 -> V_106 == V_130 )
return V_127 ;
return NULL ;
}
static void F_99 ( struct V_126 * V_127 )
{
F_89 ( & V_127 -> V_129 , 0 ) ;
}
void F_100 ( struct V_65 * V_66 , long V_133 )
{
struct V_1 V_2 , * V_51 ;
int V_27 ;
int V_134 = 0 ;
int V_112 ;
int V_116 ;
int V_115 = 0 ;
int V_135 = 0 ;
F_101 ( V_125 , V_136 ) ;
F_101 ( V_137 , V_136 ) ;
char * V_50 = L_22 ;
F_92 ( & V_138 ) ;
F_72 ( V_139 ) ;
if ( ! V_94 )
goto V_72;
F_53 ( & V_2 , V_66 ) ;
V_51 = & F_48 ( V_113 ) ;
* V_51 = V_2 ;
memset ( V_137 , 0 , sizeof( V_137 ) ) ;
V_115 = F_75 ( & V_2 , & V_50 , V_137 , V_66 ) ;
F_37 () ;
if ( ! ( V_2 . V_35 & V_67 ) )
V_135 = 1 ;
V_116 = F_85 ( & V_115 ) ;
for ( V_27 = 0 ; V_27 < V_94 ; V_27 ++ ) {
F_102 ( V_27 , V_125 ) ;
if ( ! F_73 ( V_27 , V_137 ) )
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
! V_115 )
continue;
F_103 ( V_140 ) ;
V_112 = F_77 ( & V_2 , V_104 , NULL ) ;
if ( V_112 == V_114 && ! V_115 )
continue;
F_76 ( V_27 , V_125 ) ;
if ( V_112 == V_141 ) {
continue;
}
F_69 ( & V_2 , V_27 ) ;
if ( V_112 == V_142 && F_93 ( & V_2 ) )
F_59 ( V_2 . V_42 >> V_123 ) ;
F_8 ( & V_2 ) ;
if ( V_112 > V_134 ) {
* V_51 = V_2 ;
V_134 = V_112 ;
}
}
V_2 = * V_51 ;
if ( ! V_115 )
F_95 ( V_125 ) ;
if ( F_91 ( V_116 ) < 0 )
V_115 = V_134 >= V_105 ;
if ( V_104 < 3 ) {
if ( V_115 )
F_35 ( L_23 , & V_2 , V_50 ) ;
if ( V_134 == V_143 ) {
F_96 ( V_2 . V_42 , V_2 . V_35 & V_67 ) ;
F_104 ( V_144 ) ;
} else if ( V_135 ) {
F_105 ( V_145 , V_130 ) ;
}
}
if ( V_134 > 0 )
F_67 ( V_66 ) ;
F_51 ( V_62 , 0 ) ;
V_72:
F_106 ( & V_138 ) ;
F_74 () ;
}
int F_107 ( unsigned long V_71 , int V_146 , int V_25 )
{
F_108 ( V_25 & V_147 ) ;
F_20 ( L_24
L_25 ,
V_71 ) ;
return 0 ;
}
void F_109 ( void )
{
unsigned long V_71 ;
struct V_126 * V_127 = F_98 () ;
int V_25 = V_147 ;
if ( ! V_127 )
F_35 ( L_26 , NULL , NULL ) ;
V_71 = V_127 -> V_131 >> V_123 ;
F_110 ( V_144 ) ;
F_20 ( L_27 ,
V_127 -> V_131 ) ;
if ( ! V_127 -> V_132 )
V_25 |= V_148 ;
if ( F_107 ( V_71 , V_149 , V_25 ) < 0 ) {
F_20 ( L_28 ) ;
F_105 ( V_145 , V_130 ) ;
}
F_99 ( V_127 ) ;
}
static void F_111 ( struct V_80 * V_150 )
{
unsigned long V_71 ;
while ( F_56 ( & V_71 ) )
F_107 ( V_71 , V_149 , 0 ) ;
}
void F_112 ( T_5 V_37 )
{
struct V_1 V_2 ;
F_1 ( & V_2 ) ;
V_2 . V_36 = V_151 ;
V_2 . V_37 = V_37 ;
F_8 ( & V_2 ) ;
}
static void F_113 ( unsigned long V_152 )
{
struct V_153 * V_106 = & F_48 ( V_154 ) ;
unsigned long V_155 ;
F_114 ( F_2 () != V_152 ) ;
if ( F_60 ( F_115 ( & V_156 ) ) ) {
F_71 ( V_99 ,
& F_48 ( V_157 ) ) ;
}
V_155 = F_42 ( V_158 ) ;
if ( F_66 () )
V_155 = F_116 ( V_155 / 2 , ( unsigned long ) V_159 / 100 ) ;
else
V_155 = F_117 ( V_155 * 2 , F_118 ( V_160 * V_159 ) ) ;
F_119 ( V_158 , V_155 ) ;
V_106 -> V_161 = V_30 + V_155 ;
F_120 ( V_106 , F_2 () ) ;
}
static void F_121 ( void )
{
int V_3 ;
F_122 (cpu)
F_123 ( & F_84 ( V_154 , V_3 ) ) ;
}
static void F_124 ( struct V_80 * V_81 )
{
F_125 ( V_162 , V_163 , NULL , V_164 ) ;
}
int F_66 ( void )
{
static F_126 ( V_165 , 60 * V_159 , 2 ) ;
if ( F_127 ( 0 , & V_26 ) ) {
F_128 ( & V_166 ) ;
if ( V_162 [ 0 ] && ! F_63 ( & V_167 ) )
F_64 ( & V_167 ) ;
if ( F_129 ( & V_165 ) )
F_130 ( V_34 L_29 ) ;
return 1 ;
}
return 0 ;
}
static int T_6 F_131 ( void )
{
int V_27 ;
V_95 = F_132 ( V_94 * sizeof( struct V_168 ) , V_169 ) ;
if ( ! V_95 )
return - V_170 ;
for ( V_27 = 0 ; V_27 < V_94 ; V_27 ++ ) {
struct V_168 * V_92 = & V_95 [ V_27 ] ;
V_92 -> V_96 = - 1ULL ;
V_92 -> V_171 = 1 ;
}
return 0 ;
}
static int T_6 F_133 ( void )
{
unsigned V_92 ;
T_2 V_172 ;
F_7 ( V_14 , V_172 ) ;
V_92 = V_172 & V_173 ;
if ( ! V_94 )
F_130 ( L_30 , V_92 ) ;
if ( V_92 > V_136 ) {
F_134 ( L_31 ,
V_136 , V_92 ) ;
V_92 = V_136 ;
}
F_114 ( V_94 != 0 && V_92 != V_94 ) ;
V_94 = V_92 ;
if ( ! V_95 ) {
int V_174 = F_131 () ;
if ( V_174 )
return V_174 ;
}
if ( ( V_172 & V_175 ) && F_135 ( V_172 ) >= 9 )
V_61 = V_176 ;
if ( V_172 & V_177 )
V_89 = 1 ;
return 0 ;
}
static void F_136 ( void )
{
T_4 V_178 ;
T_2 V_172 ;
int V_27 ;
F_137 ( V_178 , V_136 ) ;
F_71 ( V_97 | ( ! V_179 ? V_100 : 0 ) , & V_178 ) ;
F_138 ( V_180 ) ;
F_7 ( V_14 , V_172 ) ;
if ( V_172 & V_181 )
F_139 ( V_182 , 0xffffffff , 0xffffffff ) ;
for ( V_27 = 0 ; V_27 < V_94 ; V_27 ++ ) {
struct V_168 * V_92 = & V_95 [ V_27 ] ;
if ( ! V_92 -> V_171 )
continue;
F_52 ( F_140 ( V_27 ) , V_92 -> V_96 ) ;
F_52 ( F_44 ( V_27 ) , 0 ) ;
}
}
static void F_141 ( int V_36 , struct V_1 * V_2 , struct V_65 * V_66 )
{
if ( V_36 != 0 )
return;
if ( ( V_2 -> V_35 & ( V_39 | V_67 ) ) != 0 )
return;
if ( ( V_2 -> V_37 & ( V_183 | V_57 |
V_184 | V_87 | V_88 |
V_185 | V_98 | V_186 |
V_187 ) ) !=
( V_57 | V_184 |
V_87 | V_88 | V_98 |
V_186 | V_188 ) )
return;
V_2 -> V_35 |= V_39 ;
V_2 -> V_38 = V_66 -> V_38 ;
V_2 -> V_40 = V_66 -> V_40 ;
}
static int T_6 F_142 ( struct V_75 * V_76 )
{
if ( V_76 -> V_8 == V_189 ) {
F_130 ( L_32 ) ;
return - V_190 ;
}
if ( V_76 -> V_8 == V_191 ) {
if ( V_76 -> V_192 == 15 && V_94 > 4 ) {
F_143 ( 10 , ( unsigned long * ) & V_95 [ 4 ] . V_96 ) ;
}
if ( V_76 -> V_192 <= 17 && V_179 < 0 ) {
V_179 = 0 ;
}
if ( V_76 -> V_192 == 6 && V_94 > 0 )
V_95 [ 0 ] . V_96 = 0 ;
if ( V_76 -> V_192 == 0x15 &&
( V_76 -> V_193 >= 0x10 && V_76 -> V_193 <= 0x1f ) ) {
int V_27 ;
T_2 V_194 , V_195 ;
bool V_196 ;
T_1 V_197 [] = {
0x00000413 ,
0xc0000408 ,
} ;
F_7 ( V_198 , V_195 ) ;
V_196 = ! ( V_195 & F_144 ( 18 ) ) ;
if ( V_196 )
F_52 ( V_198 , V_195 | F_144 ( 18 ) ) ;
for ( V_27 = 0 ; V_27 < F_145 ( V_197 ) ; V_27 ++ ) {
F_7 ( V_197 [ V_27 ] , V_194 ) ;
if ( V_194 & F_146 ( 62 ) ) {
V_194 &= ~ F_146 ( 62 ) ;
F_52 ( V_197 [ V_27 ] , V_194 ) ;
}
}
if ( V_196 )
F_52 ( V_198 , V_195 ) ;
}
}
if ( V_76 -> V_8 == V_199 ) {
if ( V_76 -> V_192 == 6 && V_76 -> V_193 < 0x1A && V_94 > 0 )
V_95 [ 0 ] . V_171 = 0 ;
if ( ( V_76 -> V_192 > 6 || ( V_76 -> V_192 == 6 && V_76 -> V_193 >= 0xe ) ) &&
V_107 < 0 )
V_107 = V_47 ;
if ( V_76 -> V_192 == 6 && V_76 -> V_193 <= 13 && V_179 < 0 )
V_179 = 0 ;
if ( V_76 -> V_192 == 6 && V_76 -> V_193 == 45 )
V_103 = F_141 ;
}
if ( V_107 < 0 )
V_107 = 0 ;
if ( V_179 != 0 )
V_49 = 30 ;
return 0 ;
}
static int T_6 F_147 ( struct V_75 * V_76 )
{
if ( V_76 -> V_192 != 5 )
return 0 ;
switch ( V_76 -> V_8 ) {
case V_199 :
F_148 ( V_76 ) ;
return 1 ;
break;
case V_200 :
F_149 ( V_76 ) ;
return 1 ;
break;
}
return 0 ;
}
static void F_150 ( struct V_75 * V_76 )
{
switch ( V_76 -> V_8 ) {
case V_199 :
F_151 ( V_76 ) ;
break;
case V_191 :
F_152 ( V_76 ) ;
break;
default:
break;
}
}
static void F_153 ( void )
{
struct V_153 * V_106 = & F_48 ( V_154 ) ;
unsigned long V_155 = V_160 * V_159 ;
F_154 ( V_106 , F_113 , F_2 () ) ;
if ( V_201 )
return;
F_119 ( V_158 , V_155 ) ;
if ( ! V_155 )
return;
V_106 -> V_161 = F_155 ( V_30 + V_155 ) ;
F_120 ( V_106 , F_2 () ) ;
}
static void F_156 ( struct V_65 * V_66 , long V_133 )
{
F_20 ( L_33 ,
F_2 () ) ;
}
void T_6 F_157 ( struct V_75 * V_76 )
{
if ( V_77 )
return;
if ( F_147 ( V_76 ) )
return;
if ( ! F_60 ( V_76 ) )
return;
if ( F_133 () < 0 || F_142 ( V_76 ) < 0 ) {
V_77 = 1 ;
return;
}
V_202 = F_100 ;
F_136 () ;
F_150 ( V_76 ) ;
F_153 () ;
F_158 ( & F_48 ( V_82 ) , F_111 ) ;
F_159 ( & F_48 ( V_86 ) , & F_65 ) ;
}
static int F_160 ( struct V_203 * V_203 , struct V_204 * V_204 )
{
F_161 ( & V_205 ) ;
if ( V_206 ||
( V_207 && ( V_204 -> V_208 & V_209 ) ) ) {
F_162 ( & V_205 ) ;
return - V_210 ;
}
if ( V_204 -> V_208 & V_209 )
V_206 = 1 ;
V_207 ++ ;
F_162 ( & V_205 ) ;
return F_163 ( V_203 , V_204 ) ;
}
static int F_164 ( struct V_203 * V_203 , struct V_204 * V_204 )
{
F_161 ( & V_205 ) ;
V_207 -- ;
V_206 = 0 ;
F_162 ( & V_205 ) ;
return 0 ;
}
static void F_165 ( void * V_152 )
{
unsigned long * V_211 = ( unsigned long * ) V_152 ;
F_3 ( V_211 [ F_2 () ] ) ;
}
static int F_166 ( char T_7 * * V_212 , T_8 V_213 )
{
int V_214 ;
T_2 V_215 ;
struct V_1 V_2 ;
if ( V_213 < sizeof( struct V_1 ) )
return - V_216 ;
V_214 = F_167 ( & V_2 , & V_215 ) ;
if ( V_214 <= 0 ) {
V_217 = 1 ;
if ( V_214 == - V_218 )
return 0 ;
return V_214 ;
}
V_214 = - V_219 ;
if ( F_168 ( * V_212 , & V_2 , sizeof( struct V_1 ) ) )
return V_214 ;
V_214 = F_169 ( V_215 ) ;
if ( V_214 ) {
V_217 = 1 ;
return V_214 ;
}
* V_212 += sizeof( struct V_1 ) ;
return 0 ;
}
static T_9 F_170 ( struct V_204 * V_220 , char T_7 * V_212 ,
T_8 V_213 , T_10 * V_221 )
{
char T_7 * V_222 = V_212 ;
unsigned long * V_211 ;
unsigned V_28 , V_16 ;
int V_27 , V_174 ;
V_211 = F_171 ( V_223 * sizeof( long ) , V_169 ) ;
if ( ! V_211 )
return - V_170 ;
F_172 ( & V_224 ) ;
if ( ! V_217 ) {
V_174 = F_166 ( & V_222 , V_213 ) ;
if ( V_174 || V_222 != V_212 )
goto V_72;
}
V_16 = F_12 ( V_22 . V_16 ) ;
V_174 = - V_216 ;
if ( * V_221 != 0 || V_213 < V_23 * sizeof( struct V_1 ) )
goto V_72;
V_174 = 0 ;
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
V_174 |= F_168 ( V_222 , V_2 , sizeof( * V_2 ) ) ;
V_222 += sizeof( * V_2 ) ;
V_45:
;
}
memset ( V_22 . V_17 + V_28 , 0 ,
( V_16 - V_28 ) * sizeof( struct V_1 ) ) ;
V_28 = V_16 ;
V_16 = F_15 ( & V_22 . V_16 , V_28 , 0 ) ;
} while ( V_16 != V_28 );
F_173 () ;
F_174 ( F_165 , V_211 , 1 ) ;
for ( V_27 = V_16 ; V_27 < V_23 ; V_27 ++ ) {
struct V_1 * V_2 = & V_22 . V_17 [ V_27 ] ;
if ( V_2 -> V_21 && V_2 -> V_5 < V_211 [ V_2 -> V_3 ] ) {
V_174 |= F_168 ( V_222 , V_2 , sizeof( * V_2 ) ) ;
F_14 () ;
V_222 += sizeof( * V_2 ) ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
}
}
if ( V_174 )
V_174 = - V_219 ;
V_72:
F_175 ( & V_224 ) ;
F_176 ( V_211 ) ;
return V_174 ? V_174 : V_222 - V_212 ;
}
static unsigned int F_177 ( struct V_204 * V_204 , T_11 * V_225 )
{
F_178 ( V_204 , & V_166 , V_225 ) ;
if ( F_179 ( V_22 . V_16 ) )
return V_226 | V_227 ;
if ( ! V_217 && F_180 () )
return V_226 | V_227 ;
return 0 ;
}
static long F_181 ( struct V_204 * V_228 , unsigned int V_229 ,
unsigned long V_230 )
{
int T_7 * V_231 = ( int T_7 * ) V_230 ;
if ( ! F_182 ( V_232 ) )
return - V_233 ;
switch ( V_229 ) {
case V_234 :
return F_183 ( sizeof( struct V_1 ) , V_231 ) ;
case V_235 :
return F_183 ( V_23 , V_231 ) ;
case V_236 : {
unsigned V_25 ;
do {
V_25 = V_22 . V_25 ;
} while ( F_15 ( & V_22 . V_25 , V_25 , 0 ) != V_25 );
return F_183 ( V_25 , V_231 ) ;
}
default:
return - V_237 ;
}
}
void F_184 ( T_9 (* F_185)( struct V_204 * V_220 ,
const char T_7 * V_212 ,
T_8 V_213 , T_10 * V_221 ) )
{
V_238 = F_185 ;
}
T_9 F_186 ( struct V_204 * V_220 , const char T_7 * V_212 ,
T_8 V_213 , T_10 * V_221 )
{
if ( V_238 )
return V_238 ( V_220 , V_212 , V_213 , V_221 ) ;
else
return - V_216 ;
}
static int T_12 F_187 ( char * V_239 )
{
if ( * V_239 == 0 ) {
F_188 () ;
return 1 ;
}
if ( * V_239 == '=' )
V_239 ++ ;
if ( ! strcmp ( V_239 , L_34 ) )
V_77 = 1 ;
else if ( ! strcmp ( V_239 , L_35 ) )
V_240 = 1 ;
else if ( ! strcmp ( V_239 , L_36 ) )
V_101 = 1 ;
else if ( ! strcmp ( V_239 , L_37 ) )
V_201 = 1 ;
else if ( ! strcmp ( V_239 , L_38 ) || ! strcmp ( V_239 , L_39 ) )
V_179 = ( V_239 [ 0 ] == 'b' ) ;
else if ( isdigit ( V_239 [ 0 ] ) ) {
F_189 ( & V_239 , & V_104 ) ;
if ( * V_239 == ',' ) {
++ V_239 ;
F_189 ( & V_239 , & V_107 ) ;
}
} else {
F_130 ( L_40 , V_239 ) ;
return 0 ;
}
return 1 ;
}
int T_12 F_190 ( void )
{
F_191 () ;
return 0 ;
}
static int F_192 ( void )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_94 ; V_27 ++ ) {
struct V_168 * V_92 = & V_95 [ V_27 ] ;
if ( V_92 -> V_171 )
F_52 ( F_140 ( V_27 ) , 0 ) ;
}
return 0 ;
}
static int F_193 ( void )
{
return F_192 () ;
}
static void F_194 ( void )
{
F_192 () ;
}
static void F_195 ( void )
{
F_136 () ;
F_150 ( F_115 ( & V_156 ) ) ;
}
static void F_196 ( void * V_152 )
{
if ( ! F_60 ( F_115 ( & V_156 ) ) )
return;
F_136 () ;
F_153 () ;
}
static void F_197 ( void )
{
F_121 () ;
F_174 ( F_196 , NULL , 1 ) ;
}
static void F_198 ( void * V_152 )
{
if ( ! F_60 ( F_115 ( & V_156 ) ) )
return;
F_199 () ;
}
static void F_200 ( void * V_241 )
{
if ( ! F_60 ( F_115 ( & V_156 ) ) )
return;
F_201 () ;
F_202 () ;
if ( V_241 )
F_153 () ;
}
static inline struct V_168 * F_203 ( struct V_242 * V_243 )
{
return F_204 ( V_243 , struct V_168 , V_243 ) ;
}
static T_9 F_205 ( struct V_244 * V_245 , struct V_242 * V_243 ,
char * V_222 )
{
return sprintf ( V_222 , L_41 , F_203 ( V_243 ) -> V_96 ) ;
}
static T_9 F_206 ( struct V_244 * V_245 , struct V_242 * V_243 ,
const char * V_222 , T_8 V_246 )
{
T_2 V_247 ;
if ( F_207 ( V_222 , 0 , & V_247 ) < 0 )
return - V_216 ;
F_203 ( V_243 ) -> V_96 = V_247 ;
F_197 () ;
return V_246 ;
}
static T_9
F_208 ( struct V_244 * V_245 , struct V_242 * V_243 , char * V_222 )
{
strcpy ( V_222 , V_162 ) ;
strcat ( V_222 , L_7 ) ;
return strlen ( V_162 ) + 1 ;
}
static T_9 F_209 ( struct V_244 * V_245 , struct V_242 * V_243 ,
const char * V_222 , T_8 V_248 )
{
char * V_231 ;
strncpy ( V_162 , V_222 , sizeof( V_162 ) ) ;
V_162 [ sizeof( V_162 ) - 1 ] = 0 ;
V_231 = strchr ( V_162 , '\n' ) ;
if ( V_231 )
* V_231 = 0 ;
return strlen ( V_162 ) + ! ! V_231 ;
}
static T_9 F_210 ( struct V_244 * V_245 ,
struct V_242 * V_243 ,
const char * V_222 , T_8 V_246 )
{
T_2 V_247 ;
if ( F_207 ( V_222 , 0 , & V_247 ) < 0 )
return - V_216 ;
if ( V_201 ^ ! ! V_247 ) {
if ( V_247 ) {
F_121 () ;
F_174 ( F_198 , NULL , 1 ) ;
V_201 = 1 ;
} else {
V_201 = 0 ;
F_174 ( F_200 , ( void * ) 1 , 1 ) ;
}
}
return V_246 ;
}
static T_9 F_211 ( struct V_244 * V_245 ,
struct V_242 * V_243 ,
const char * V_222 , T_8 V_246 )
{
T_2 V_247 ;
if ( F_207 ( V_222 , 0 , & V_247 ) < 0 )
return - V_216 ;
if ( V_240 ^ ! ! V_247 ) {
if ( V_247 ) {
F_174 ( F_198 , NULL , 1 ) ;
V_240 = 1 ;
} else {
V_240 = 0 ;
F_174 ( F_200 , NULL , 1 ) ;
}
}
return V_246 ;
}
static T_9 F_212 ( struct V_244 * V_245 ,
struct V_242 * V_243 ,
const char * V_222 , T_8 V_246 )
{
T_9 V_18 = F_213 ( V_245 , V_243 , V_222 , V_246 ) ;
F_197 () ;
return V_18 ;
}
static void F_214 ( struct V_244 * V_249 )
{
F_176 ( V_249 ) ;
}
static T_6 int F_215 ( unsigned int V_3 )
{
struct V_244 * V_249 ;
int V_174 ;
int V_27 , V_250 ;
if ( ! F_60 ( & V_7 ) )
return - V_251 ;
V_249 = F_132 ( sizeof *V_249 , V_169 ) ;
if ( ! V_249 )
return - V_170 ;
V_249 -> V_252 = V_3 ;
V_249 -> V_253 = & V_254 ;
V_249 -> V_255 = & F_214 ;
V_174 = F_216 ( V_249 ) ;
if ( V_174 )
return V_174 ;
for ( V_27 = 0 ; V_256 [ V_27 ] ; V_27 ++ ) {
V_174 = F_217 ( V_249 , V_256 [ V_27 ] ) ;
if ( V_174 )
goto error;
}
for ( V_250 = 0 ; V_250 < V_94 ; V_250 ++ ) {
V_174 = F_217 ( V_249 , & V_95 [ V_250 ] . V_243 ) ;
if ( V_174 )
goto V_257;
}
F_218 ( V_3 , V_258 ) ;
F_84 ( V_259 , V_3 ) = V_249 ;
return 0 ;
V_257:
while ( -- V_250 >= 0 )
F_219 ( V_249 , & V_95 [ V_250 ] . V_243 ) ;
error:
while ( -- V_27 >= 0 )
F_219 ( V_249 , V_256 [ V_27 ] ) ;
F_220 ( V_249 ) ;
return V_174 ;
}
static T_6 void F_221 ( unsigned int V_3 )
{
struct V_244 * V_249 = F_84 ( V_259 , V_3 ) ;
int V_27 ;
if ( ! F_222 ( V_3 , V_258 ) )
return;
for ( V_27 = 0 ; V_256 [ V_27 ] ; V_27 ++ )
F_219 ( V_249 , V_256 [ V_27 ] ) ;
for ( V_27 = 0 ; V_27 < V_94 ; V_27 ++ )
F_219 ( V_249 , & V_95 [ V_27 ] . V_243 ) ;
F_220 ( V_249 ) ;
F_223 ( V_3 , V_258 ) ;
F_84 ( V_259 , V_3 ) = NULL ;
}
static void T_6 F_224 ( void * V_260 )
{
unsigned long V_261 = * ( unsigned long * ) V_260 ;
int V_27 ;
if ( ! F_60 ( F_115 ( & V_156 ) ) )
return;
if ( ! ( V_261 & V_262 ) )
F_199 () ;
for ( V_27 = 0 ; V_27 < V_94 ; V_27 ++ ) {
struct V_168 * V_92 = & V_95 [ V_27 ] ;
if ( V_92 -> V_171 )
F_52 ( F_140 ( V_27 ) , 0 ) ;
}
}
static void T_6 F_225 ( void * V_260 )
{
unsigned long V_261 = * ( unsigned long * ) V_260 ;
int V_27 ;
if ( ! F_60 ( F_115 ( & V_156 ) ) )
return;
if ( ! ( V_261 & V_262 ) )
F_201 () ;
for ( V_27 = 0 ; V_27 < V_94 ; V_27 ++ ) {
struct V_168 * V_92 = & V_95 [ V_27 ] ;
if ( V_92 -> V_171 )
F_52 ( F_140 ( V_27 ) , V_92 -> V_96 ) ;
}
}
static int T_6
F_226 ( struct V_32 * V_263 , unsigned long V_261 , void * V_264 )
{
unsigned int V_3 = ( unsigned long ) V_264 ;
struct V_153 * V_106 = & F_84 ( V_154 , V_3 ) ;
switch ( V_261 ) {
case V_265 :
case V_266 :
F_215 ( V_3 ) ;
if ( V_267 )
V_267 ( V_261 , V_3 ) ;
break;
case V_268 :
case V_269 :
if ( V_267 )
V_267 ( V_261 , V_3 ) ;
F_221 ( V_3 ) ;
break;
case V_270 :
case V_271 :
F_123 ( V_106 ) ;
F_227 ( V_3 , F_224 , & V_261 , 1 ) ;
break;
case V_272 :
case V_273 :
if ( ! V_201 && V_160 ) {
V_106 -> V_161 = F_155 ( V_30 +
F_84 ( V_158 , V_3 ) ) ;
F_120 ( V_106 , V_3 ) ;
}
F_227 ( V_3 , F_225 , & V_261 , 1 ) ;
break;
case V_274 :
F_228 ( V_3 ) ;
break;
}
return V_275 ;
}
static T_12 void F_229 ( void )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_94 ; V_27 ++ ) {
struct V_168 * V_92 = & V_95 [ V_27 ] ;
struct V_242 * V_276 = & V_92 -> V_243 ;
F_230 ( & V_276 -> V_243 ) ;
V_276 -> V_243 . V_277 = V_92 -> V_278 ;
snprintf ( V_92 -> V_278 , V_279 , L_42 , V_27 ) ;
V_276 -> V_243 . V_280 = 0644 ;
V_276 -> V_281 = F_205 ;
V_276 -> V_282 = F_206 ;
}
}
static T_12 int F_231 ( void )
{
int V_174 ;
int V_27 = 0 ;
if ( ! F_60 ( & V_7 ) )
return - V_251 ;
F_232 ( & V_258 , V_169 ) ;
F_229 () ;
V_174 = F_233 ( & V_254 , NULL ) ;
if ( V_174 )
return V_174 ;
F_122 (i) {
V_174 = F_215 ( V_27 ) ;
if ( V_174 )
return V_174 ;
}
F_234 ( & V_283 ) ;
F_235 ( & V_284 ) ;
F_236 ( & V_285 ) ;
return V_174 ;
}
static int T_12 F_237 ( char * V_239 )
{
V_77 = 1 ;
return 1 ;
}
struct V_286 * F_238 ( void )
{
static struct V_286 * V_287 ;
if ( ! V_287 )
V_287 = F_239 ( L_43 , NULL ) ;
return V_287 ;
}
static void F_240 ( void )
{
V_58 = 0 ;
F_89 ( & V_55 , 0 ) ;
F_89 ( & V_121 , 0 ) ;
F_89 ( & V_120 , 0 ) ;
F_89 ( & V_119 , 0 ) ;
}
static int F_241 ( void * V_152 , T_2 * V_194 )
{
* V_194 = V_53 ;
return 0 ;
}
static int F_242 ( void * V_152 , T_2 V_194 )
{
F_240 () ;
V_53 = V_194 ;
return 0 ;
}
static int T_12 F_243 ( void )
{
struct V_286 * V_287 , * V_288 ;
V_287 = F_238 () ;
if ( ! V_287 )
return - V_170 ;
V_288 = F_244 ( L_44 , 0444 , V_287 , NULL ,
& V_289 ) ;
if ( ! V_288 )
return - V_170 ;
return 0 ;
}
