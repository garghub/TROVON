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
if ( V_49 . V_89 && ( V_2 -> V_37 & V_87 ) ) {
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
for ( V_27 = 0 ; V_27 < V_49 . V_94 ; V_27 ++ ) {
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
( V_2 . V_37 & ( V_49 . V_89 ? V_98 : V_57 ) ) )
continue;
F_69 ( & V_2 , V_27 ) ;
if ( ! ( V_25 & V_99 ) )
V_2 . V_5 = 0 ;
if ( ! ( V_25 & V_100 ) && ! V_49 . V_101 )
F_8 ( & V_2 ) ;
F_51 ( F_44 ( V_27 ) , 0 ) ;
}
F_74 () ;
}
static int F_75 ( struct V_1 * V_2 , char * * V_50 , unsigned long * V_102 ,
struct V_65 * V_66 )
{
int V_27 , V_18 = 0 ;
for ( V_27 = 0 ; V_27 < V_49 . V_94 ; V_27 ++ ) {
V_2 -> V_37 = F_47 ( F_44 ( V_27 ) ) ;
if ( V_2 -> V_37 & V_56 ) {
F_76 ( V_27 , V_102 ) ;
if ( V_103 )
V_103 ( V_27 , V_2 , V_66 ) ;
}
if ( F_77 ( V_2 , V_49 . V_104 , V_50 ) >= V_105 )
V_18 = 1 ;
}
return V_18 ;
}
static int F_78 ( T_2 * V_106 )
{
F_79 () ;
if ( F_80 ( & V_54 ) )
F_30 () ;
if ( ! V_49 . V_107 )
goto V_72;
if ( ( V_108 ) * V_106 < V_109 ) {
if ( V_49 . V_104 < 1 )
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
int V_112 = F_77 ( & F_84 ( V_113 , V_3 ) ,
V_49 . V_104 ,
& V_111 ) ;
if ( V_112 > V_110 ) {
V_50 = V_111 ;
V_110 = V_112 ;
V_2 = & F_84 ( V_113 , V_3 ) ;
}
}
if ( V_2 && V_110 >= V_105 && V_49 . V_104 < 3 )
F_35 ( L_19 , V_2 , V_50 ) ;
if ( V_110 <= V_114 && V_49 . V_104 < 3 )
F_35 ( L_20 , NULL , NULL ) ;
F_83 (cpu)
memset ( & F_84 ( V_113 , V_3 ) , 0 , sizeof( struct V_1 ) ) ;
}
static int F_85 ( int * V_115 )
{
int V_116 ;
int V_117 = F_86 () ;
T_2 V_45 = ( T_2 ) V_49 . V_107 * V_118 ;
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
T_2 V_45 = ( T_2 ) V_49 . V_107 * V_118 ;
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
for ( V_27 = 0 ; V_27 < V_49 . V_94 ; V_27 ++ ) {
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
struct V_134 * V_135 = & V_49 ;
struct V_1 V_2 , * V_51 ;
int V_27 ;
int V_136 = 0 ;
int V_112 ;
int V_116 ;
int V_115 = 0 ;
int V_137 = 0 ;
F_101 ( V_125 , V_138 ) ;
F_101 ( V_139 , V_138 ) ;
char * V_50 = L_22 ;
F_92 ( & V_140 ) ;
F_72 ( V_141 ) ;
if ( ! V_135 -> V_94 )
goto V_72;
F_53 ( & V_2 , V_66 ) ;
V_51 = & F_48 ( V_113 ) ;
* V_51 = V_2 ;
memset ( V_139 , 0 , sizeof( V_139 ) ) ;
V_115 = F_75 ( & V_2 , & V_50 , V_139 , V_66 ) ;
F_37 () ;
if ( ! ( V_2 . V_35 & V_67 ) )
V_137 = 1 ;
V_116 = F_85 ( & V_115 ) ;
for ( V_27 = 0 ; V_27 < V_135 -> V_94 ; V_27 ++ ) {
F_102 ( V_27 , V_125 ) ;
if ( ! F_73 ( V_27 , V_139 ) )
continue;
if ( ! V_95 [ V_27 ] . V_96 )
continue;
V_2 . V_43 = 0 ;
V_2 . V_42 = 0 ;
V_2 . V_36 = V_27 ;
V_2 . V_37 = F_47 ( F_44 ( V_27 ) ) ;
if ( ( V_2 . V_37 & V_56 ) == 0 )
continue;
if ( ! ( V_2 . V_37 & ( V_135 -> V_89 ? V_98 : V_57 ) ) &&
! V_115 )
continue;
F_103 ( V_142 ) ;
V_112 = F_77 ( & V_2 , V_135 -> V_104 , NULL ) ;
if ( V_112 == V_114 && ! V_115 )
continue;
F_76 ( V_27 , V_125 ) ;
if ( V_112 == V_143 ) {
continue;
}
F_69 ( & V_2 , V_27 ) ;
if ( V_112 == V_144 && F_93 ( & V_2 ) )
F_59 ( V_2 . V_42 >> V_123 ) ;
F_8 ( & V_2 ) ;
if ( V_112 > V_136 ) {
* V_51 = V_2 ;
V_136 = V_112 ;
}
}
V_2 = * V_51 ;
if ( ! V_115 )
F_95 ( V_125 ) ;
if ( F_91 ( V_116 ) < 0 )
V_115 = V_136 >= V_105 ;
if ( V_135 -> V_104 < 3 ) {
if ( V_115 )
F_35 ( L_23 , & V_2 , V_50 ) ;
if ( V_136 == V_145 ) {
F_96 ( V_2 . V_42 , V_2 . V_35 & V_67 ) ;
F_104 ( V_146 ) ;
} else if ( V_137 ) {
F_105 ( V_147 , V_130 ) ;
}
}
if ( V_136 > 0 )
F_67 ( V_66 ) ;
F_51 ( V_62 , 0 ) ;
V_72:
F_106 ( & V_140 ) ;
F_74 () ;
}
int F_107 ( unsigned long V_71 , int V_148 , int V_25 )
{
F_108 ( V_25 & V_149 ) ;
F_20 ( L_24
L_25 ,
V_71 ) ;
return 0 ;
}
void F_109 ( void )
{
unsigned long V_71 ;
struct V_126 * V_127 = F_98 () ;
int V_25 = V_149 ;
if ( ! V_127 )
F_35 ( L_26 , NULL , NULL ) ;
V_71 = V_127 -> V_131 >> V_123 ;
F_110 ( V_146 ) ;
F_20 ( L_27 ,
V_127 -> V_131 ) ;
if ( ! V_127 -> V_132 )
V_25 |= V_150 ;
if ( F_107 ( V_71 , V_151 , V_25 ) < 0 ) {
F_20 ( L_28 ) ;
F_105 ( V_147 , V_130 ) ;
}
F_99 ( V_127 ) ;
}
static void F_111 ( struct V_80 * V_152 )
{
unsigned long V_71 ;
while ( F_56 ( & V_71 ) )
F_107 ( V_71 , V_151 , 0 ) ;
}
void F_112 ( T_5 V_37 )
{
struct V_1 V_2 ;
F_1 ( & V_2 ) ;
V_2 . V_36 = V_153 ;
V_2 . V_37 = V_37 ;
F_8 ( & V_2 ) ;
}
static unsigned long F_113 ( unsigned long V_154 )
{
return V_154 ;
}
static void F_114 ( unsigned long V_155 )
{
struct V_156 * V_106 = & F_48 ( V_157 ) ;
unsigned long V_158 ;
F_115 ( F_2 () != V_155 ) ;
if ( F_60 ( F_116 ( & V_159 ) ) ) {
F_71 ( V_99 ,
& F_48 ( V_160 ) ) ;
F_117 () ;
}
V_158 = F_42 ( V_161 ) ;
if ( F_66 () ) {
V_158 = F_118 ( V_158 / 2 , ( unsigned long ) V_162 / 100 ) ;
} else {
V_158 = F_119 ( V_158 * 2 , F_120 ( V_163 * V_162 ) ) ;
V_158 = F_121 ( V_158 ) ;
}
F_122 ( V_161 , V_158 ) ;
if ( V_158 ) {
V_106 -> V_164 = V_30 + V_158 ;
F_123 ( V_106 , F_2 () ) ;
}
}
void F_124 ( unsigned long V_154 )
{
struct V_156 * V_106 = & F_48 ( V_157 ) ;
unsigned long V_165 = V_30 + V_154 ;
unsigned long V_158 = F_42 ( V_161 ) ;
if ( F_125 ( V_106 ) ) {
if ( F_126 ( V_165 , V_106 -> V_164 ) )
F_127 ( V_106 , V_165 ) ;
} else {
V_106 -> V_164 = F_128 ( V_165 ) ;
F_123 ( V_106 , F_2 () ) ;
}
if ( V_154 < V_158 )
F_122 ( V_161 , V_154 ) ;
}
static void F_129 ( void )
{
int V_3 ;
F_130 (cpu)
F_131 ( & F_84 ( V_157 , V_3 ) ) ;
}
static void F_132 ( struct V_80 * V_81 )
{
F_133 ( V_166 , V_167 , NULL , V_168 ) ;
}
int F_66 ( void )
{
static F_134 ( V_169 , 60 * V_162 , 2 ) ;
if ( F_135 ( 0 , & V_26 ) ) {
F_136 ( & V_170 ) ;
if ( V_166 [ 0 ] && ! F_63 ( & V_171 ) )
F_64 ( & V_171 ) ;
if ( F_137 ( & V_169 ) )
F_138 ( V_34 L_29 ) ;
return 1 ;
}
return 0 ;
}
static int T_6 F_139 ( void )
{
int V_27 ;
T_3 V_172 = V_49 . V_94 ;
V_95 = F_140 ( V_172 * sizeof( struct V_173 ) , V_174 ) ;
if ( ! V_95 )
return - V_175 ;
for ( V_27 = 0 ; V_27 < V_172 ; V_27 ++ ) {
struct V_173 * V_92 = & V_95 [ V_27 ] ;
V_92 -> V_96 = - 1ULL ;
V_92 -> V_176 = 1 ;
}
return 0 ;
}
static int T_6 F_141 ( void )
{
unsigned V_92 ;
T_2 V_177 ;
F_7 ( V_14 , V_177 ) ;
V_92 = V_177 & V_178 ;
if ( ! V_49 . V_94 )
F_138 ( L_30 , V_92 ) ;
if ( V_92 > V_138 ) {
F_142 ( L_31 ,
V_138 , V_92 ) ;
V_92 = V_138 ;
}
F_115 ( V_49 . V_94 != 0 && V_92 != V_49 . V_94 ) ;
V_49 . V_94 = V_92 ;
if ( ! V_95 ) {
int V_179 = F_139 () ;
if ( V_179 )
return V_179 ;
}
if ( ( V_177 & V_180 ) && F_143 ( V_177 ) >= 9 )
V_49 . V_61 = V_181 ;
if ( V_177 & V_182 )
V_49 . V_89 = true ;
return 0 ;
}
static void F_144 ( void )
{
enum V_91 V_183 = 0 ;
T_4 V_184 ;
T_2 V_177 ;
int V_27 ;
if ( ! V_49 . V_185 )
V_183 = V_100 ;
F_145 ( V_184 , V_138 ) ;
F_71 ( V_97 | V_183 , & V_184 ) ;
F_146 ( V_186 ) ;
F_7 ( V_14 , V_177 ) ;
if ( V_177 & V_187 )
F_147 ( V_188 , 0xffffffff , 0xffffffff ) ;
for ( V_27 = 0 ; V_27 < V_49 . V_94 ; V_27 ++ ) {
struct V_173 * V_92 = & V_95 [ V_27 ] ;
if ( ! V_92 -> V_176 )
continue;
F_52 ( F_148 ( V_27 ) , V_92 -> V_96 ) ;
F_52 ( F_44 ( V_27 ) , 0 ) ;
}
}
static void F_149 ( int V_36 , struct V_1 * V_2 , struct V_65 * V_66 )
{
if ( V_36 != 0 )
return;
if ( ( V_2 -> V_35 & ( V_39 | V_67 ) ) != 0 )
return;
if ( ( V_2 -> V_37 & ( V_189 | V_57 |
V_190 | V_87 | V_88 |
V_191 | V_98 | V_192 |
V_193 ) ) !=
( V_57 | V_190 |
V_87 | V_88 | V_98 |
V_192 | V_194 ) )
return;
V_2 -> V_35 |= V_39 ;
V_2 -> V_38 = V_66 -> V_38 ;
V_2 -> V_40 = V_66 -> V_40 ;
}
static int T_6 F_150 ( struct V_75 * V_76 )
{
struct V_134 * V_135 = & V_49 ;
if ( V_76 -> V_8 == V_195 ) {
F_138 ( L_32 ) ;
return - V_196 ;
}
if ( V_76 -> V_8 == V_197 ) {
if ( V_76 -> V_198 == 15 && V_135 -> V_94 > 4 ) {
F_151 ( 10 , ( unsigned long * ) & V_95 [ 4 ] . V_96 ) ;
}
if ( V_76 -> V_198 <= 17 && V_135 -> V_185 < 0 ) {
V_135 -> V_185 = 0 ;
}
if ( V_76 -> V_198 == 6 && V_135 -> V_94 > 0 )
V_95 [ 0 ] . V_96 = 0 ;
if ( V_76 -> V_198 == 0x15 &&
( V_76 -> V_199 >= 0x10 && V_76 -> V_199 <= 0x1f ) ) {
int V_27 ;
T_2 V_200 , V_201 ;
bool V_202 ;
T_1 V_203 [] = {
0x00000413 ,
0xc0000408 ,
} ;
F_7 ( V_204 , V_201 ) ;
V_202 = ! ( V_201 & F_152 ( 18 ) ) ;
if ( V_202 )
F_52 ( V_204 , V_201 | F_152 ( 18 ) ) ;
for ( V_27 = 0 ; V_27 < F_153 ( V_203 ) ; V_27 ++ ) {
F_7 ( V_203 [ V_27 ] , V_200 ) ;
if ( V_200 & F_154 ( 62 ) ) {
V_200 &= ~ F_154 ( 62 ) ;
F_52 ( V_203 [ V_27 ] , V_200 ) ;
}
}
if ( V_202 )
F_52 ( V_204 , V_201 ) ;
}
}
if ( V_76 -> V_8 == V_205 ) {
if ( V_76 -> V_198 == 6 && V_76 -> V_199 < 0x1A && V_135 -> V_94 > 0 )
V_95 [ 0 ] . V_176 = 0 ;
if ( ( V_76 -> V_198 > 6 || ( V_76 -> V_198 == 6 && V_76 -> V_199 >= 0xe ) ) &&
V_135 -> V_107 < 0 )
V_135 -> V_107 = V_47 ;
if ( V_76 -> V_198 == 6 && V_76 -> V_199 <= 13 && V_135 -> V_185 < 0 )
V_135 -> V_185 = 0 ;
if ( V_76 -> V_198 == 6 && V_76 -> V_199 == 45 )
V_103 = F_149 ;
}
if ( V_135 -> V_107 < 0 )
V_135 -> V_107 = 0 ;
if ( V_135 -> V_185 != 0 )
V_135 -> V_48 = 30 ;
return 0 ;
}
static int T_6 F_155 ( struct V_75 * V_76 )
{
if ( V_76 -> V_198 != 5 )
return 0 ;
switch ( V_76 -> V_8 ) {
case V_205 :
F_156 ( V_76 ) ;
return 1 ;
break;
case V_206 :
F_157 ( V_76 ) ;
return 1 ;
break;
}
return 0 ;
}
static void F_158 ( struct V_75 * V_76 )
{
switch ( V_76 -> V_8 ) {
case V_205 :
F_159 ( V_76 ) ;
F_121 = V_207 ;
break;
case V_197 :
F_160 ( V_76 ) ;
break;
default:
break;
}
}
static void F_161 ( unsigned int V_3 , struct V_156 * V_106 )
{
unsigned long V_158 = F_121 ( V_163 * V_162 ) ;
F_122 ( V_161 , V_158 ) ;
if ( V_49 . V_208 || ! V_158 )
return;
V_106 -> V_164 = F_128 ( V_30 + V_158 ) ;
F_123 ( V_106 , F_2 () ) ;
}
static void F_162 ( void )
{
struct V_156 * V_106 = & F_48 ( V_157 ) ;
unsigned int V_3 = F_2 () ;
F_163 ( V_106 , F_114 , V_3 ) ;
F_161 ( V_3 , V_106 ) ;
}
static void F_164 ( struct V_65 * V_66 , long V_133 )
{
F_20 ( L_33 ,
F_2 () ) ;
}
void T_6 F_165 ( struct V_75 * V_76 )
{
if ( V_49 . V_77 )
return;
if ( F_155 ( V_76 ) )
return;
if ( ! F_60 ( V_76 ) )
return;
if ( F_141 () < 0 || F_150 ( V_76 ) < 0 ) {
V_49 . V_77 = true ;
return;
}
V_209 = F_100 ;
F_144 () ;
F_158 ( V_76 ) ;
F_162 () ;
F_166 ( & F_48 ( V_82 ) , F_111 ) ;
F_167 ( & F_48 ( V_86 ) , & F_65 ) ;
}
static int F_168 ( struct V_210 * V_210 , struct V_211 * V_211 )
{
F_169 ( & V_212 ) ;
if ( V_213 ||
( V_214 && ( V_211 -> V_215 & V_216 ) ) ) {
F_170 ( & V_212 ) ;
return - V_217 ;
}
if ( V_211 -> V_215 & V_216 )
V_213 = 1 ;
V_214 ++ ;
F_170 ( & V_212 ) ;
return F_171 ( V_210 , V_211 ) ;
}
static int F_172 ( struct V_210 * V_210 , struct V_211 * V_211 )
{
F_169 ( & V_212 ) ;
V_214 -- ;
V_213 = 0 ;
F_170 ( & V_212 ) ;
return 0 ;
}
static void F_173 ( void * V_155 )
{
unsigned long * V_218 = ( unsigned long * ) V_155 ;
F_3 ( V_218 [ F_2 () ] ) ;
}
static int F_174 ( char T_7 * * V_219 , T_8 V_220 )
{
int V_221 ;
T_2 V_222 ;
struct V_1 V_2 ;
if ( V_220 < sizeof( struct V_1 ) )
return - V_223 ;
V_221 = F_175 ( & V_2 , & V_222 ) ;
if ( V_221 <= 0 ) {
V_224 = 1 ;
if ( V_221 == - V_225 )
return 0 ;
return V_221 ;
}
V_221 = - V_226 ;
if ( F_176 ( * V_219 , & V_2 , sizeof( struct V_1 ) ) )
return V_221 ;
V_221 = F_177 ( V_222 ) ;
if ( V_221 ) {
V_224 = 1 ;
return V_221 ;
}
* V_219 += sizeof( struct V_1 ) ;
return 0 ;
}
static T_9 F_178 ( struct V_211 * V_227 , char T_7 * V_219 ,
T_8 V_220 , T_10 * V_228 )
{
char T_7 * V_229 = V_219 ;
unsigned long * V_218 ;
unsigned V_28 , V_16 ;
int V_27 , V_179 ;
V_218 = F_179 ( V_230 * sizeof( long ) , V_174 ) ;
if ( ! V_218 )
return - V_175 ;
F_180 ( & V_231 ) ;
if ( ! V_224 ) {
V_179 = F_174 ( & V_229 , V_220 ) ;
if ( V_179 || V_229 != V_219 )
goto V_72;
}
V_16 = F_12 ( V_22 . V_16 ) ;
V_179 = - V_223 ;
if ( * V_228 != 0 || V_220 < V_23 * sizeof( struct V_1 ) )
goto V_72;
V_179 = 0 ;
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
V_179 |= F_176 ( V_229 , V_2 , sizeof( * V_2 ) ) ;
V_229 += sizeof( * V_2 ) ;
V_45:
;
}
memset ( V_22 . V_17 + V_28 , 0 ,
( V_16 - V_28 ) * sizeof( struct V_1 ) ) ;
V_28 = V_16 ;
V_16 = F_15 ( & V_22 . V_16 , V_28 , 0 ) ;
} while ( V_16 != V_28 );
F_181 () ;
F_182 ( F_173 , V_218 , 1 ) ;
for ( V_27 = V_16 ; V_27 < V_23 ; V_27 ++ ) {
struct V_1 * V_2 = & V_22 . V_17 [ V_27 ] ;
if ( V_2 -> V_21 && V_2 -> V_5 < V_218 [ V_2 -> V_3 ] ) {
V_179 |= F_176 ( V_229 , V_2 , sizeof( * V_2 ) ) ;
F_14 () ;
V_229 += sizeof( * V_2 ) ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
}
}
if ( V_179 )
V_179 = - V_226 ;
V_72:
F_183 ( & V_231 ) ;
F_184 ( V_218 ) ;
return V_179 ? V_179 : V_229 - V_219 ;
}
static unsigned int F_185 ( struct V_211 * V_211 , T_11 * V_232 )
{
F_186 ( V_211 , & V_170 , V_232 ) ;
if ( F_187 ( V_22 . V_16 ) )
return V_233 | V_234 ;
if ( ! V_224 && F_188 () )
return V_233 | V_234 ;
return 0 ;
}
static long F_189 ( struct V_211 * V_235 , unsigned int V_236 ,
unsigned long V_237 )
{
int T_7 * V_238 = ( int T_7 * ) V_237 ;
if ( ! F_190 ( V_239 ) )
return - V_240 ;
switch ( V_236 ) {
case V_241 :
return F_191 ( sizeof( struct V_1 ) , V_238 ) ;
case V_242 :
return F_191 ( V_23 , V_238 ) ;
case V_243 : {
unsigned V_25 ;
do {
V_25 = V_22 . V_25 ;
} while ( F_15 ( & V_22 . V_25 , V_25 , 0 ) != V_25 );
return F_191 ( V_25 , V_238 ) ;
}
default:
return - V_244 ;
}
}
void F_192 ( T_9 (* F_193)( struct V_211 * V_227 ,
const char T_7 * V_219 ,
T_8 V_220 , T_10 * V_228 ) )
{
V_245 = F_193 ;
}
T_9 F_194 ( struct V_211 * V_227 , const char T_7 * V_219 ,
T_8 V_220 , T_10 * V_228 )
{
if ( V_245 )
return V_245 ( V_227 , V_219 , V_220 , V_228 ) ;
else
return - V_223 ;
}
static int T_12 F_195 ( char * V_246 )
{
struct V_134 * V_135 = & V_49 ;
if ( * V_246 == 0 ) {
F_196 () ;
return 1 ;
}
if ( * V_246 == '=' )
V_246 ++ ;
if ( ! strcmp ( V_246 , L_34 ) )
V_135 -> V_77 = true ;
else if ( ! strcmp ( V_246 , L_35 ) )
V_135 -> V_247 = true ;
else if ( ! strcmp ( V_246 , L_36 ) )
V_135 -> V_101 = true ;
else if ( ! strcmp ( V_246 , L_37 ) )
V_135 -> V_208 = true ;
else if ( ! strcmp ( V_246 , L_38 ) || ! strcmp ( V_246 , L_39 ) )
V_135 -> V_185 = ( V_246 [ 0 ] == 'b' ) ;
else if ( ! strcmp ( V_246 , L_40 ) )
V_135 -> V_248 = true ;
else if ( isdigit ( V_246 [ 0 ] ) ) {
F_197 ( & V_246 , & ( V_135 -> V_104 ) ) ;
if ( * V_246 == ',' ) {
++ V_246 ;
F_197 ( & V_246 , & ( V_135 -> V_107 ) ) ;
}
} else {
F_138 ( L_41 , V_246 ) ;
return 0 ;
}
return 1 ;
}
int T_12 F_198 ( void )
{
F_199 () ;
return 0 ;
}
static int F_200 ( void )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_49 . V_94 ; V_27 ++ ) {
struct V_173 * V_92 = & V_95 [ V_27 ] ;
if ( V_92 -> V_176 )
F_52 ( F_148 ( V_27 ) , 0 ) ;
}
return 0 ;
}
static int F_201 ( void )
{
return F_200 () ;
}
static void F_202 ( void )
{
F_200 () ;
}
static void F_203 ( void )
{
F_144 () ;
F_158 ( F_116 ( & V_159 ) ) ;
}
static void F_204 ( void * V_155 )
{
if ( ! F_60 ( F_116 ( & V_159 ) ) )
return;
F_144 () ;
F_162 () ;
}
static void F_205 ( void )
{
F_129 () ;
F_182 ( F_204 , NULL , 1 ) ;
}
static void F_206 ( void * V_155 )
{
if ( ! F_60 ( F_116 ( & V_159 ) ) )
return;
F_207 () ;
}
static void F_208 ( void * V_249 )
{
if ( ! F_60 ( F_116 ( & V_159 ) ) )
return;
F_209 () ;
F_210 () ;
if ( V_249 )
F_162 () ;
}
static inline struct V_173 * F_211 ( struct V_250 * V_251 )
{
return F_212 ( V_251 , struct V_173 , V_251 ) ;
}
static T_9 F_213 ( struct V_252 * V_253 , struct V_250 * V_251 ,
char * V_229 )
{
return sprintf ( V_229 , L_42 , F_211 ( V_251 ) -> V_96 ) ;
}
static T_9 F_214 ( struct V_252 * V_253 , struct V_250 * V_251 ,
const char * V_229 , T_8 V_254 )
{
T_2 V_255 ;
if ( F_215 ( V_229 , 0 , & V_255 ) < 0 )
return - V_223 ;
F_211 ( V_251 ) -> V_96 = V_255 ;
F_205 () ;
return V_254 ;
}
static T_9
F_216 ( struct V_252 * V_253 , struct V_250 * V_251 , char * V_229 )
{
strcpy ( V_229 , V_166 ) ;
strcat ( V_229 , L_7 ) ;
return strlen ( V_166 ) + 1 ;
}
static T_9 F_217 ( struct V_252 * V_253 , struct V_250 * V_251 ,
const char * V_229 , T_8 V_256 )
{
char * V_238 ;
strncpy ( V_166 , V_229 , sizeof( V_166 ) ) ;
V_166 [ sizeof( V_166 ) - 1 ] = 0 ;
V_238 = strchr ( V_166 , '\n' ) ;
if ( V_238 )
* V_238 = 0 ;
return strlen ( V_166 ) + ! ! V_238 ;
}
static T_9 F_218 ( struct V_252 * V_253 ,
struct V_250 * V_251 ,
const char * V_229 , T_8 V_254 )
{
T_2 V_255 ;
if ( F_215 ( V_229 , 0 , & V_255 ) < 0 )
return - V_223 ;
if ( V_49 . V_208 ^ ! ! V_255 ) {
if ( V_255 ) {
F_129 () ;
F_182 ( F_206 , NULL , 1 ) ;
V_49 . V_208 = true ;
} else {
V_49 . V_208 = false ;
F_182 ( F_208 , ( void * ) 1 , 1 ) ;
}
}
return V_254 ;
}
static T_9 F_219 ( struct V_252 * V_253 ,
struct V_250 * V_251 ,
const char * V_229 , T_8 V_254 )
{
T_2 V_255 ;
if ( F_215 ( V_229 , 0 , & V_255 ) < 0 )
return - V_223 ;
if ( V_49 . V_247 ^ ! ! V_255 ) {
if ( V_255 ) {
F_182 ( F_206 , NULL , 1 ) ;
V_49 . V_247 = true ;
} else {
V_49 . V_247 = false ;
F_182 ( F_208 , NULL , 1 ) ;
}
}
return V_254 ;
}
static T_9 F_220 ( struct V_252 * V_253 ,
struct V_250 * V_251 ,
const char * V_229 , T_8 V_254 )
{
T_9 V_18 = F_221 ( V_253 , V_251 , V_229 , V_254 ) ;
F_205 () ;
return V_18 ;
}
static void F_222 ( struct V_252 * V_257 )
{
F_184 ( V_257 ) ;
}
static T_6 int F_223 ( unsigned int V_3 )
{
struct V_252 * V_257 ;
int V_179 ;
int V_27 , V_258 ;
if ( ! F_60 ( & V_7 ) )
return - V_259 ;
V_257 = F_140 ( sizeof *V_257 , V_174 ) ;
if ( ! V_257 )
return - V_175 ;
V_257 -> V_260 = V_3 ;
V_257 -> V_261 = & V_262 ;
V_257 -> V_263 = & F_222 ;
V_179 = F_224 ( V_257 ) ;
if ( V_179 )
return V_179 ;
for ( V_27 = 0 ; V_264 [ V_27 ] ; V_27 ++ ) {
V_179 = F_225 ( V_257 , V_264 [ V_27 ] ) ;
if ( V_179 )
goto error;
}
for ( V_258 = 0 ; V_258 < V_49 . V_94 ; V_258 ++ ) {
V_179 = F_225 ( V_257 , & V_95 [ V_258 ] . V_251 ) ;
if ( V_179 )
goto V_265;
}
F_226 ( V_3 , V_266 ) ;
F_84 ( V_267 , V_3 ) = V_257 ;
return 0 ;
V_265:
while ( -- V_258 >= 0 )
F_227 ( V_257 , & V_95 [ V_258 ] . V_251 ) ;
error:
while ( -- V_27 >= 0 )
F_227 ( V_257 , V_264 [ V_27 ] ) ;
F_228 ( V_257 ) ;
return V_179 ;
}
static T_6 void F_229 ( unsigned int V_3 )
{
struct V_252 * V_257 = F_84 ( V_267 , V_3 ) ;
int V_27 ;
if ( ! F_230 ( V_3 , V_266 ) )
return;
for ( V_27 = 0 ; V_264 [ V_27 ] ; V_27 ++ )
F_227 ( V_257 , V_264 [ V_27 ] ) ;
for ( V_27 = 0 ; V_27 < V_49 . V_94 ; V_27 ++ )
F_227 ( V_257 , & V_95 [ V_27 ] . V_251 ) ;
F_228 ( V_257 ) ;
F_231 ( V_3 , V_266 ) ;
F_84 ( V_267 , V_3 ) = NULL ;
}
static void T_6 F_232 ( void * V_268 )
{
unsigned long V_269 = * ( unsigned long * ) V_268 ;
int V_27 ;
if ( ! F_60 ( F_116 ( & V_159 ) ) )
return;
if ( ! ( V_269 & V_270 ) )
F_207 () ;
for ( V_27 = 0 ; V_27 < V_49 . V_94 ; V_27 ++ ) {
struct V_173 * V_92 = & V_95 [ V_27 ] ;
if ( V_92 -> V_176 )
F_52 ( F_148 ( V_27 ) , 0 ) ;
}
}
static void T_6 F_233 ( void * V_268 )
{
unsigned long V_269 = * ( unsigned long * ) V_268 ;
int V_27 ;
if ( ! F_60 ( F_116 ( & V_159 ) ) )
return;
if ( ! ( V_269 & V_270 ) )
F_209 () ;
for ( V_27 = 0 ; V_27 < V_49 . V_94 ; V_27 ++ ) {
struct V_173 * V_92 = & V_95 [ V_27 ] ;
if ( V_92 -> V_176 )
F_52 ( F_148 ( V_27 ) , V_92 -> V_96 ) ;
}
}
static int T_6
F_234 ( struct V_32 * V_271 , unsigned long V_269 , void * V_272 )
{
unsigned int V_3 = ( unsigned long ) V_272 ;
struct V_156 * V_106 = & F_84 ( V_157 , V_3 ) ;
switch ( V_269 & ~ V_270 ) {
case V_273 :
F_223 ( V_3 ) ;
if ( V_274 )
V_274 ( V_269 , V_3 ) ;
break;
case V_275 :
if ( V_274 )
V_274 ( V_269 , V_3 ) ;
F_229 ( V_3 ) ;
F_235 ( V_3 ) ;
break;
case V_276 :
F_236 ( V_3 , F_232 , & V_269 , 1 ) ;
F_131 ( V_106 ) ;
break;
case V_277 :
F_236 ( V_3 , F_233 , & V_269 , 1 ) ;
F_161 ( V_3 , V_106 ) ;
break;
}
if ( V_269 == V_278 ) {
F_237 ( V_3 ) ;
}
return V_279 ;
}
static T_12 void F_238 ( void )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_49 . V_94 ; V_27 ++ ) {
struct V_173 * V_92 = & V_95 [ V_27 ] ;
struct V_250 * V_280 = & V_92 -> V_251 ;
F_239 ( & V_280 -> V_251 ) ;
V_280 -> V_251 . V_281 = V_92 -> V_282 ;
snprintf ( V_92 -> V_282 , V_283 , L_43 , V_27 ) ;
V_280 -> V_251 . V_284 = 0644 ;
V_280 -> V_285 = F_213 ;
V_280 -> V_286 = F_214 ;
}
}
static T_12 int F_240 ( void )
{
int V_179 ;
int V_27 = 0 ;
if ( ! F_60 ( & V_7 ) )
return - V_259 ;
F_241 ( & V_266 , V_174 ) ;
F_238 () ;
V_179 = F_242 ( & V_262 , NULL ) ;
if ( V_179 )
return V_179 ;
F_130 (i) {
V_179 = F_223 ( V_27 ) ;
if ( V_179 )
return V_179 ;
}
F_243 ( & V_287 ) ;
F_244 ( & V_288 ) ;
F_245 ( & V_289 ) ;
return V_179 ;
}
static int T_12 F_246 ( char * V_246 )
{
V_49 . V_77 = true ;
return 1 ;
}
struct V_290 * F_247 ( void )
{
static struct V_290 * V_291 ;
if ( ! V_291 )
V_291 = F_248 ( L_44 , NULL ) ;
return V_291 ;
}
static void F_249 ( void )
{
V_58 = 0 ;
F_89 ( & V_55 , 0 ) ;
F_89 ( & V_121 , 0 ) ;
F_89 ( & V_120 , 0 ) ;
F_89 ( & V_119 , 0 ) ;
}
static int F_250 ( void * V_155 , T_2 * V_200 )
{
* V_200 = V_53 ;
return 0 ;
}
static int F_251 ( void * V_155 , T_2 V_200 )
{
F_249 () ;
V_53 = V_200 ;
return 0 ;
}
static int T_12 F_252 ( void )
{
struct V_290 * V_291 , * V_292 ;
V_291 = F_247 () ;
if ( ! V_291 )
return - V_175 ;
V_292 = F_253 ( L_45 , 0444 , V_291 , NULL ,
& V_293 ) ;
if ( ! V_292 )
return - V_175 ;
return 0 ;
}
