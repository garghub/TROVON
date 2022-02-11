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
V_16 = F_12 ( V_22 . V_16 ) ;
do {
struct V_1 * V_2 ;
for ( V_27 = V_28 ; V_27 < V_16 ; V_27 ++ ) {
unsigned long V_29 = V_30 ;
unsigned V_31 = 1 ;
V_2 = & V_22 . V_17 [ V_27 ] ;
while ( ! V_2 -> V_21 ) {
if ( F_17 ( V_30 , V_29 + 2 * V_31 ) )
V_31 ++ ;
F_18 () ;
if ( ! V_2 -> V_21 && V_31 >= 4 ) {
F_19 ( L_1 ) ;
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
void F_20 ( struct V_32 * V_33 )
{
F_21 ( & V_19 , V_33 ) ;
F_16 () ;
}
void F_22 ( struct V_32 * V_33 )
{
F_23 ( & V_19 , V_33 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
int V_18 = 0 ;
F_25 ( V_34 L_2 ,
V_2 -> V_4 , V_2 -> V_35 , V_2 -> V_36 , V_2 -> V_37 ) ;
if ( V_2 -> V_38 ) {
F_25 ( V_34 L_3 ,
! ( V_2 -> V_35 & V_39 ) ? L_4 : L_5 ,
V_2 -> V_40 , V_2 -> V_38 ) ;
if ( V_2 -> V_40 == V_41 )
F_26 ( L_6 , V_2 -> V_38 ) ;
F_27 ( L_7 ) ;
}
F_25 ( V_34 L_8 , V_2 -> V_5 ) ;
if ( V_2 -> V_42 )
F_27 ( L_9 , V_2 -> V_42 ) ;
if ( V_2 -> V_43 )
F_27 ( L_10 , V_2 -> V_43 ) ;
F_27 ( L_7 ) ;
F_25 ( V_34 L_11 ,
V_2 -> V_6 , V_2 -> V_9 , V_2 -> time , V_2 -> V_10 , V_2 -> V_12 ,
F_6 ( V_2 -> V_4 ) . V_44 ) ;
V_18 = F_10 ( & V_19 , 0 , V_2 ) ;
if ( V_18 == V_20 )
return;
F_28 ( V_34 L_12 ) ;
}
static void F_29 ( void )
{
long V_45 = V_46 * V_47 ;
F_30 () ;
F_31 () ;
while ( V_45 -- > 0 )
F_32 ( 1 ) ;
if ( V_48 == 0 )
V_48 = V_49 ;
F_33 ( L_13 ) ;
}
static void F_34 ( char * V_50 , struct V_1 * V_51 , char * exp )
{
int V_27 , V_52 = 0 ;
if ( ! V_53 ) {
if ( F_35 ( & V_54 ) > 1 )
F_29 () ;
F_36 () ;
F_37 ( 1 ) ;
F_38 () ;
} else {
if ( F_35 ( & V_55 ) > 1 )
return;
}
for ( V_27 = 0 ; V_27 < V_23 ; V_27 ++ ) {
struct V_1 * V_2 = & V_22 . V_17 [ V_27 ] ;
if ( ! ( V_2 -> V_37 & V_56 ) )
continue;
if ( ! ( V_2 -> V_37 & V_57 ) ) {
F_24 ( V_2 ) ;
if ( ! V_52 )
V_52 = F_39 ( V_2 ) ;
}
}
for ( V_27 = 0 ; V_27 < V_23 ; V_27 ++ ) {
struct V_1 * V_2 = & V_22 . V_17 [ V_27 ] ;
if ( ! ( V_2 -> V_37 & V_56 ) )
continue;
if ( ! ( V_2 -> V_37 & V_57 ) )
continue;
if ( ! V_51 || memcmp ( V_2 , V_51 , sizeof( struct V_1 ) ) ) {
F_24 ( V_2 ) ;
if ( ! V_52 )
V_52 = F_39 ( V_2 ) ;
}
}
if ( V_51 ) {
F_24 ( V_51 ) ;
if ( ! V_52 )
V_52 = F_39 ( V_51 ) ;
}
if ( V_58 )
F_25 ( V_34 L_14 ) ;
if ( exp )
F_25 ( V_34 L_15 , exp ) ;
if ( ! V_53 ) {
if ( V_48 == 0 )
V_48 = V_49 ;
F_33 ( V_50 ) ;
} else
F_25 ( V_34 L_16 , V_50 ) ;
}
static int F_40 ( T_1 V_59 )
{
unsigned V_36 = F_41 ( V_60 . V_36 ) ;
if ( V_59 == V_61 )
return F_42 ( struct V_1 , V_38 ) ;
if ( V_59 == F_43 ( V_36 ) )
return F_42 ( struct V_1 , V_37 ) ;
if ( V_59 == F_44 ( V_36 ) )
return F_42 ( struct V_1 , V_42 ) ;
if ( V_59 == F_45 ( V_36 ) )
return F_42 ( struct V_1 , V_43 ) ;
if ( V_59 == V_62 )
return F_42 ( struct V_1 , V_35 ) ;
return - 1 ;
}
static T_2 F_46 ( T_1 V_59 )
{
T_2 V_63 ;
if ( F_41 ( V_60 . V_21 ) ) {
int V_64 = F_40 ( V_59 ) ;
if ( V_64 < 0 )
return 0 ;
return * ( T_2 * ) ( ( char * ) & F_47 ( V_60 ) + V_64 ) ;
}
if ( F_48 ( V_59 , & V_63 ) ) {
F_49 ( 1 , L_17 , V_59 ) ;
V_63 = 0 ;
}
return V_63 ;
}
static void F_50 ( T_1 V_59 , T_2 V_63 )
{
if ( F_41 ( V_60 . V_21 ) ) {
int V_64 = F_40 ( V_59 ) ;
if ( V_64 >= 0 )
* ( T_2 * ) ( ( char * ) & F_47 ( V_60 ) + V_64 ) = V_63 ;
return;
}
F_51 ( V_59 , V_63 ) ;
}
static inline void F_52 ( struct V_1 * V_2 , struct V_65 * V_66 )
{
F_1 ( V_2 ) ;
V_2 -> V_35 = F_46 ( V_62 ) ;
if ( V_66 ) {
if ( V_2 -> V_35 & ( V_67 | V_39 ) ) {
V_2 -> V_38 = V_66 -> V_38 ;
V_2 -> V_40 = V_66 -> V_40 ;
}
if ( V_61 )
V_2 -> V_38 = F_46 ( V_61 ) ;
}
}
static int F_53 ( void )
{
struct V_68 * V_69 = & F_47 ( V_68 ) ;
return V_69 -> V_29 == V_69 -> V_70 ;
}
static int F_54 ( unsigned long * V_71 )
{
struct V_68 * V_69 ;
int V_18 = 0 ;
* V_71 = 0 ;
F_55 () ;
V_69 = & F_47 ( V_68 ) ;
if ( V_69 -> V_29 == V_69 -> V_70 )
goto V_72;
* V_71 = V_69 -> V_73 [ V_69 -> V_29 ] ;
V_69 -> V_29 = ( V_69 -> V_29 + 1 ) % V_74 ;
V_18 = 1 ;
V_72:
F_56 () ;
return V_18 ;
}
static int F_57 ( unsigned long V_71 )
{
struct V_68 * V_69 = & F_47 ( V_68 ) ;
unsigned V_16 ;
V_16 = ( V_69 -> V_70 + 1 ) % V_74 ;
if ( V_16 == V_69 -> V_29 )
return - 1 ;
V_69 -> V_73 [ V_69 -> V_70 ] = V_71 ;
F_11 () ;
V_69 -> V_70 = V_16 ;
return 0 ;
}
int F_58 ( struct V_75 * V_76 )
{
if ( V_77 )
return 0 ;
return F_59 ( V_76 , V_78 ) && F_59 ( V_76 , V_79 ) ;
}
static void F_60 ( void )
{
if ( ! F_53 () ) {
struct V_80 * V_81 = & F_47 ( V_82 ) ;
if ( ! F_61 ( V_81 ) )
F_62 ( V_81 ) ;
}
}
static void F_63 ( struct V_83 * V_17 )
{
F_64 () ;
F_60 () ;
}
static void F_65 ( struct V_65 * V_66 )
{
if ( V_66 -> V_25 & ( V_84 | V_85 ) ) {
F_64 () ;
F_60 () ;
return;
}
F_66 ( & F_47 ( V_86 ) ) ;
}
void F_67 ( enum V_87 V_25 , T_3 * V_88 )
{
struct V_1 V_2 ;
int V_27 ;
F_68 ( V_89 ) ;
F_52 ( & V_2 , NULL ) ;
for ( V_27 = 0 ; V_27 < V_90 ; V_27 ++ ) {
if ( ! V_91 [ V_27 ] . V_92 || ! F_69 ( V_27 , * V_88 ) )
continue;
V_2 . V_43 = 0 ;
V_2 . V_42 = 0 ;
V_2 . V_36 = V_27 ;
V_2 . V_5 = 0 ;
F_36 () ;
V_2 . V_37 = F_46 ( F_43 ( V_27 ) ) ;
if ( ! ( V_2 . V_37 & V_56 ) )
continue;
if ( ! ( V_25 & V_93 ) &&
( V_2 . V_37 & ( V_94 ? V_95 : V_57 ) ) )
continue;
if ( V_2 . V_37 & V_96 )
V_2 . V_43 = F_46 ( F_45 ( V_27 ) ) ;
if ( V_2 . V_37 & V_97 )
V_2 . V_42 = F_46 ( F_44 ( V_27 ) ) ;
if ( ! ( V_25 & V_98 ) )
V_2 . V_5 = 0 ;
if ( ! ( V_25 & V_99 ) && ! V_100 )
F_8 ( & V_2 ) ;
F_50 ( F_43 ( V_27 ) , 0 ) ;
}
F_70 () ;
}
static int F_71 ( struct V_1 * V_2 , char * * V_50 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_90 ; V_27 ++ ) {
V_2 -> V_37 = F_46 ( F_43 ( V_27 ) ) ;
if ( F_72 ( V_2 , V_101 , V_50 ) >= V_102 )
return 1 ;
}
return 0 ;
}
static int F_73 ( T_2 * V_103 )
{
F_74 () ;
if ( F_75 ( & V_54 ) )
F_29 () ;
if ( ! V_104 )
goto V_72;
if ( ( V_105 ) * V_103 < V_106 ) {
if ( V_101 < 1 )
F_34 ( L_18 ,
NULL , NULL ) ;
V_58 = 1 ;
return 1 ;
}
* V_103 -= V_106 ;
V_72:
F_76 () ;
return 0 ;
}
static void F_77 ( void )
{
int V_3 ;
struct V_1 * V_2 = NULL ;
int V_107 = 0 ;
char * V_50 = NULL ;
char * V_108 = NULL ;
F_78 (cpu) {
int V_109 = F_72 ( & F_79 ( V_110 , V_3 ) , V_101 ,
& V_108 ) ;
if ( V_109 > V_107 ) {
V_50 = V_108 ;
V_107 = V_109 ;
V_2 = & F_79 ( V_110 , V_3 ) ;
}
}
if ( V_2 && V_107 >= V_102 && V_101 < 3 )
F_34 ( L_19 , V_2 , V_50 ) ;
if ( V_107 <= V_111 && V_101 < 3 )
F_34 ( L_20 , NULL , NULL ) ;
F_78 (cpu)
memset ( & F_79 ( V_110 , V_3 ) , 0 , sizeof( struct V_1 ) ) ;
}
static int F_80 ( int * V_112 )
{
int V_113 ;
int V_114 = F_81 () ;
T_2 V_45 = ( T_2 ) V_104 * V_115 ;
if ( ! V_45 )
return - 1 ;
F_82 ( * V_112 , & V_116 ) ;
F_83 () ;
V_113 = F_35 ( & V_117 ) ;
while ( F_75 ( & V_117 ) != V_114 ) {
if ( F_73 ( & V_45 ) ) {
F_84 ( & V_116 , 0 ) ;
return - 1 ;
}
F_85 ( V_106 ) ;
}
F_14 () ;
if ( V_113 == 1 ) {
F_84 ( & V_118 , 1 ) ;
} else {
while ( F_75 ( & V_118 ) < V_113 ) {
if ( F_73 ( & V_45 ) ) {
F_84 ( & V_116 , 0 ) ;
return - 1 ;
}
F_85 ( V_106 ) ;
}
}
* V_112 = F_75 ( & V_116 ) ;
return V_113 ;
}
static int F_86 ( int V_113 )
{
int V_18 = - 1 ;
T_2 V_45 = ( T_2 ) V_104 * V_115 ;
if ( ! V_45 )
goto V_119;
if ( V_113 < 0 )
goto V_119;
F_87 ( & V_118 ) ;
if ( V_113 == 1 ) {
int V_114 = F_81 () ;
while ( F_75 ( & V_118 ) <= V_114 ) {
if ( F_73 ( & V_45 ) )
goto V_119;
F_85 ( V_106 ) ;
}
F_77 () ;
F_36 () ;
V_18 = 0 ;
} else {
while ( F_75 ( & V_118 ) != 0 ) {
if ( F_73 ( & V_45 ) )
goto V_119;
F_85 ( V_106 ) ;
}
return 0 ;
}
V_119:
F_84 ( & V_116 , 0 ) ;
F_84 ( & V_117 , 0 ) ;
F_36 () ;
F_84 ( & V_118 , 0 ) ;
return V_18 ;
}
static int F_88 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_37 & V_96 ) || ! ( V_2 -> V_37 & V_97 ) )
return 0 ;
if ( F_89 ( V_2 -> V_43 ) > V_120 )
return 0 ;
if ( F_90 ( V_2 -> V_43 ) != V_121 )
return 0 ;
return 1 ;
}
static void F_91 ( unsigned long * V_122 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_90 ; V_27 ++ ) {
if ( F_69 ( V_27 , V_122 ) )
F_50 ( F_43 ( V_27 ) , 0 ) ;
}
}
void F_92 ( struct V_65 * V_66 , long V_123 )
{
struct V_1 V_2 , * V_51 ;
int V_27 ;
int V_124 = 0 ;
int V_109 ;
int V_113 ;
int V_112 = 0 ;
int V_125 = 0 ;
F_93 ( V_122 , V_126 ) ;
char * V_50 = L_21 ;
F_87 ( & V_127 ) ;
F_68 ( V_128 ) ;
if ( ! V_90 )
goto V_72;
F_52 ( & V_2 , V_66 ) ;
V_51 = & F_47 ( V_110 ) ;
* V_51 = V_2 ;
V_112 = F_71 ( & V_2 , & V_50 ) ;
F_36 () ;
if ( ! ( V_2 . V_35 & V_67 ) )
V_125 = 1 ;
V_113 = F_80 ( & V_112 ) ;
for ( V_27 = 0 ; V_27 < V_90 ; V_27 ++ ) {
F_94 ( V_27 , V_122 ) ;
if ( ! V_91 [ V_27 ] . V_92 )
continue;
V_2 . V_43 = 0 ;
V_2 . V_42 = 0 ;
V_2 . V_36 = V_27 ;
V_2 . V_37 = F_46 ( F_43 ( V_27 ) ) ;
if ( ( V_2 . V_37 & V_56 ) == 0 )
continue;
if ( ! ( V_2 . V_37 & ( V_94 ? V_95 : V_57 ) ) &&
! V_112 )
continue;
F_95 ( V_129 ) ;
V_109 = F_72 ( & V_2 , V_101 , NULL ) ;
if ( V_109 == V_111 && ! V_112 )
continue;
F_96 ( V_27 , V_122 ) ;
if ( V_109 == V_130 ) {
continue;
}
if ( V_109 == V_131 )
V_125 = 1 ;
if ( V_2 . V_37 & V_96 )
V_2 . V_43 = F_46 ( F_45 ( V_27 ) ) ;
if ( V_2 . V_37 & V_97 )
V_2 . V_42 = F_46 ( F_44 ( V_27 ) ) ;
if ( V_109 == V_132 && F_88 ( & V_2 ) )
F_57 ( V_2 . V_42 >> V_120 ) ;
F_8 ( & V_2 ) ;
if ( V_109 > V_124 ) {
* V_51 = V_2 ;
V_124 = V_109 ;
}
}
if ( ! V_112 )
F_91 ( V_122 ) ;
if ( F_86 ( V_113 ) < 0 )
V_112 = V_124 >= V_102 ;
if ( V_112 && V_101 < 3 )
F_34 ( L_22 , V_51 , V_50 ) ;
if ( V_125 && V_101 < 3 )
F_97 ( V_133 , V_134 ) ;
F_98 ( V_135 ) ;
if ( V_124 > 0 )
F_65 ( V_66 ) ;
F_50 ( V_62 , 0 ) ;
V_72:
F_99 ( & V_127 ) ;
F_70 () ;
}
void F_100 ( void )
{
unsigned long V_71 ;
F_64 () ;
while ( F_54 ( & V_71 ) )
F_101 ( V_71 , V_136 ) ;
}
static void F_102 ( struct V_80 * V_137 )
{
F_100 () ;
}
void F_103 ( T_4 V_37 )
{
struct V_1 V_2 ;
F_1 ( & V_2 ) ;
V_2 . V_36 = V_138 ;
V_2 . V_37 = V_37 ;
F_8 ( & V_2 ) ;
}
static void F_104 ( unsigned long V_139 )
{
struct V_140 * V_103 = & F_79 ( V_141 , V_139 ) ;
int * V_142 ;
F_105 ( F_2 () != V_139 ) ;
if ( F_58 ( F_106 ( & V_143 ) ) ) {
F_67 ( V_98 ,
& F_47 ( V_144 ) ) ;
}
V_142 = & F_47 ( V_145 ) ;
if ( F_64 () )
* V_142 = F_107 ( * V_142 / 2 , V_146 / 100 ) ;
else
* V_142 = F_108 ( * V_142 * 2 , ( int ) F_109 ( V_147 * V_146 ) ) ;
V_103 -> V_148 = V_30 + * V_142 ;
F_110 ( V_103 , F_2 () ) ;
}
static void F_111 ( void )
{
int V_3 ;
F_112 (cpu)
F_113 ( & F_79 ( V_141 , V_3 ) ) ;
}
static void F_114 ( struct V_80 * V_81 )
{
F_115 ( V_149 , V_150 , NULL , V_151 ) ;
}
int F_64 ( void )
{
static F_116 ( V_152 , 60 * V_146 , 2 ) ;
F_117 ( V_135 ) ;
if ( F_118 ( 0 , & V_26 ) ) {
F_119 ( & V_153 ) ;
if ( V_149 [ 0 ] && ! F_61 ( & V_154 ) )
F_62 ( & V_154 ) ;
if ( F_120 ( & V_152 ) )
F_121 ( V_34 L_23 ) ;
return 1 ;
}
return 0 ;
}
static int T_5 F_122 ( void )
{
int V_27 ;
V_91 = F_123 ( V_90 * sizeof( struct V_155 ) , V_156 ) ;
if ( ! V_91 )
return - V_157 ;
for ( V_27 = 0 ; V_27 < V_90 ; V_27 ++ ) {
struct V_155 * V_88 = & V_91 [ V_27 ] ;
V_88 -> V_92 = - 1ULL ;
V_88 -> V_158 = 1 ;
}
return 0 ;
}
static int T_5 F_124 ( void )
{
unsigned V_88 ;
T_2 V_159 ;
F_7 ( V_14 , V_159 ) ;
V_88 = V_159 & V_160 ;
if ( ! V_90 )
F_125 ( V_161 L_24 , V_88 ) ;
if ( V_88 > V_126 ) {
F_125 ( V_162
L_25 ,
V_126 , V_88 ) ;
V_88 = V_126 ;
}
F_105 ( V_90 != 0 && V_88 != V_90 ) ;
V_90 = V_88 ;
if ( ! V_91 ) {
int V_163 = F_122 () ;
if ( V_163 )
return V_163 ;
}
if ( ( V_159 & V_164 ) && F_126 ( V_159 ) >= 9 )
V_61 = V_165 ;
if ( V_159 & V_166 )
V_94 = 1 ;
return 0 ;
}
static void F_127 ( void )
{
T_3 V_167 ;
T_2 V_159 ;
int V_27 ;
F_128 ( V_167 , V_126 ) ;
F_67 ( V_93 | ( ! V_168 ? V_99 : 0 ) , & V_167 ) ;
F_129 ( V_169 ) ;
F_7 ( V_14 , V_159 ) ;
if ( V_159 & V_170 )
F_130 ( V_171 , 0xffffffff , 0xffffffff ) ;
for ( V_27 = 0 ; V_27 < V_90 ; V_27 ++ ) {
struct V_155 * V_88 = & V_91 [ V_27 ] ;
if ( ! V_88 -> V_158 )
continue;
F_51 ( F_131 ( V_27 ) , V_88 -> V_92 ) ;
F_51 ( F_43 ( V_27 ) , 0 ) ;
}
}
static int T_5 F_132 ( struct V_75 * V_76 )
{
if ( V_76 -> V_8 == V_172 ) {
F_121 ( L_26 ) ;
return - V_173 ;
}
if ( V_76 -> V_8 == V_174 ) {
if ( V_76 -> V_175 == 15 && V_90 > 4 ) {
F_133 ( 10 , ( unsigned long * ) & V_91 [ 4 ] . V_92 ) ;
}
if ( V_76 -> V_175 <= 17 && V_168 < 0 ) {
V_168 = 0 ;
}
if ( V_76 -> V_175 == 6 && V_90 > 0 )
V_91 [ 0 ] . V_92 = 0 ;
}
if ( V_76 -> V_8 == V_176 ) {
if ( V_76 -> V_175 == 6 && V_76 -> V_177 < 0x1A && V_90 > 0 )
V_91 [ 0 ] . V_158 = 0 ;
if ( ( V_76 -> V_175 > 6 || ( V_76 -> V_175 == 6 && V_76 -> V_177 >= 0xe ) ) &&
V_104 < 0 )
V_104 = V_47 ;
if ( V_76 -> V_175 == 6 && V_76 -> V_177 <= 13 && V_168 < 0 )
V_168 = 0 ;
}
if ( V_104 < 0 )
V_104 = 0 ;
if ( V_168 != 0 )
V_49 = 30 ;
return 0 ;
}
static int T_5 F_134 ( struct V_75 * V_76 )
{
if ( V_76 -> V_175 != 5 )
return 0 ;
switch ( V_76 -> V_8 ) {
case V_176 :
F_135 ( V_76 ) ;
return 1 ;
break;
case V_178 :
F_136 ( V_76 ) ;
return 1 ;
break;
}
return 0 ;
}
static void F_137 ( struct V_75 * V_76 )
{
switch ( V_76 -> V_8 ) {
case V_176 :
F_138 ( V_76 ) ;
break;
case V_174 :
F_139 ( V_76 ) ;
break;
default:
break;
}
}
static void F_140 ( void )
{
struct V_140 * V_103 = & F_47 ( V_141 ) ;
int * V_142 = & F_47 ( V_145 ) ;
F_141 ( V_103 , F_104 , F_2 () ) ;
if ( V_179 )
return;
* V_142 = V_147 * V_146 ;
if ( ! * V_142 )
return;
V_103 -> V_148 = F_142 ( V_30 + * V_142 ) ;
F_110 ( V_103 , F_2 () ) ;
}
static void F_143 ( struct V_65 * V_66 , long V_123 )
{
F_125 ( V_180 L_27 ,
F_2 () ) ;
}
void T_5 F_144 ( struct V_75 * V_76 )
{
if ( V_77 )
return;
if ( F_134 ( V_76 ) )
return;
if ( ! F_58 ( V_76 ) )
return;
if ( F_124 () < 0 || F_132 ( V_76 ) < 0 ) {
V_77 = 1 ;
return;
}
V_181 = F_92 ;
F_127 () ;
F_137 ( V_76 ) ;
F_140 () ;
F_145 ( & F_47 ( V_82 ) , F_102 ) ;
F_146 ( & F_47 ( V_86 ) , & F_63 ) ;
}
static int F_147 ( struct V_182 * V_182 , struct V_183 * V_183 )
{
F_148 ( & V_184 ) ;
if ( V_185 ||
( V_186 && ( V_183 -> V_187 & V_188 ) ) ) {
F_149 ( & V_184 ) ;
return - V_189 ;
}
if ( V_183 -> V_187 & V_188 )
V_185 = 1 ;
V_186 ++ ;
F_149 ( & V_184 ) ;
return F_150 ( V_182 , V_183 ) ;
}
static int F_151 ( struct V_182 * V_182 , struct V_183 * V_183 )
{
F_148 ( & V_184 ) ;
V_186 -- ;
V_185 = 0 ;
F_149 ( & V_184 ) ;
return 0 ;
}
static void F_152 ( void * V_139 )
{
unsigned long * V_190 = ( unsigned long * ) V_139 ;
F_3 ( V_190 [ F_2 () ] ) ;
}
static int F_153 ( char T_6 * * V_191 , T_7 V_192 )
{
int V_193 ;
T_2 V_194 ;
struct V_1 V_2 ;
if ( V_192 < sizeof( struct V_1 ) )
return - V_195 ;
V_193 = F_154 ( & V_2 , & V_194 ) ;
if ( V_193 <= 0 ) {
V_196 = 1 ;
return V_193 ;
}
V_193 = - V_197 ;
if ( F_155 ( * V_191 , & V_2 , sizeof( struct V_1 ) ) )
return V_193 ;
V_193 = F_156 ( V_194 ) ;
if ( V_193 ) {
V_196 = 1 ;
return V_193 ;
}
* V_191 += sizeof( struct V_1 ) ;
return 0 ;
}
static T_8 F_157 ( struct V_183 * V_198 , char T_6 * V_191 ,
T_7 V_192 , T_9 * V_199 )
{
char T_6 * V_200 = V_191 ;
unsigned long * V_190 ;
unsigned V_28 , V_16 ;
int V_27 , V_163 ;
V_190 = F_158 ( V_201 * sizeof( long ) , V_156 ) ;
if ( ! V_190 )
return - V_157 ;
F_159 ( & V_202 ) ;
if ( ! V_196 ) {
V_163 = F_153 ( & V_200 , V_192 ) ;
if ( V_163 || V_200 != V_191 )
goto V_72;
}
V_16 = F_12 ( V_22 . V_16 ) ;
V_163 = - V_195 ;
if ( * V_199 != 0 || V_192 < V_23 * sizeof( struct V_1 ) )
goto V_72;
V_163 = 0 ;
V_28 = 0 ;
do {
for ( V_27 = V_28 ; V_27 < V_16 ; V_27 ++ ) {
unsigned long V_29 = V_30 ;
struct V_1 * V_2 = & V_22 . V_17 [ V_27 ] ;
while ( ! V_2 -> V_21 ) {
if ( F_17 ( V_30 , V_29 + 2 ) ) {
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
goto V_45;
}
F_18 () ;
}
F_14 () ;
V_163 |= F_155 ( V_200 , V_2 , sizeof( * V_2 ) ) ;
V_200 += sizeof( * V_2 ) ;
V_45:
;
}
memset ( V_22 . V_17 + V_28 , 0 ,
( V_16 - V_28 ) * sizeof( struct V_1 ) ) ;
V_28 = V_16 ;
V_16 = F_15 ( & V_22 . V_16 , V_28 , 0 ) ;
} while ( V_16 != V_28 );
F_160 () ;
F_161 ( F_152 , V_190 , 1 ) ;
for ( V_27 = V_16 ; V_27 < V_23 ; V_27 ++ ) {
struct V_1 * V_2 = & V_22 . V_17 [ V_27 ] ;
if ( V_2 -> V_21 && V_2 -> V_5 < V_190 [ V_2 -> V_3 ] ) {
V_163 |= F_155 ( V_200 , V_2 , sizeof( * V_2 ) ) ;
F_14 () ;
V_200 += sizeof( * V_2 ) ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
}
}
if ( V_163 )
V_163 = - V_197 ;
V_72:
F_162 ( & V_202 ) ;
F_163 ( V_190 ) ;
return V_163 ? V_163 : V_200 - V_191 ;
}
static unsigned int F_164 ( struct V_183 * V_183 , T_10 * V_203 )
{
F_165 ( V_183 , & V_153 , V_203 ) ;
if ( F_166 ( V_22 . V_16 ) )
return V_204 | V_205 ;
if ( ! V_196 && F_167 () )
return V_204 | V_205 ;
return 0 ;
}
static long F_168 ( struct V_183 * V_206 , unsigned int V_207 ,
unsigned long V_208 )
{
int T_6 * V_209 = ( int T_6 * ) V_208 ;
if ( ! F_169 ( V_210 ) )
return - V_211 ;
switch ( V_207 ) {
case V_212 :
return F_170 ( sizeof( struct V_1 ) , V_209 ) ;
case V_213 :
return F_170 ( V_23 , V_209 ) ;
case V_214 : {
unsigned V_25 ;
do {
V_25 = V_22 . V_25 ;
} while ( F_15 ( & V_22 . V_25 , V_25 , 0 ) != V_25 );
return F_170 ( V_25 , V_209 ) ;
}
default:
return - V_215 ;
}
}
void F_171 ( T_8 (* F_172)( struct V_183 * V_198 ,
const char T_6 * V_191 ,
T_7 V_192 , T_9 * V_199 ) )
{
V_216 = F_172 ;
}
T_8 F_173 ( struct V_183 * V_198 , const char T_6 * V_191 ,
T_7 V_192 , T_9 * V_199 )
{
if ( V_216 )
return V_216 ( V_198 , V_191 , V_192 , V_199 ) ;
else
return - V_195 ;
}
static int T_11 F_174 ( char * V_217 )
{
if ( * V_217 == 0 ) {
F_175 () ;
return 1 ;
}
if ( * V_217 == '=' )
V_217 ++ ;
if ( ! strcmp ( V_217 , L_28 ) )
V_77 = 1 ;
else if ( ! strcmp ( V_217 , L_29 ) )
V_218 = 1 ;
else if ( ! strcmp ( V_217 , L_30 ) )
V_100 = 1 ;
else if ( ! strcmp ( V_217 , L_31 ) )
V_179 = 1 ;
else if ( ! strcmp ( V_217 , L_32 ) || ! strcmp ( V_217 , L_33 ) )
V_168 = ( V_217 [ 0 ] == 'b' ) ;
else if ( isdigit ( V_217 [ 0 ] ) ) {
F_176 ( & V_217 , & V_101 ) ;
if ( * V_217 == ',' ) {
++ V_217 ;
F_176 ( & V_217 , & V_104 ) ;
}
} else {
F_125 ( V_161 L_34 ,
V_217 ) ;
return 0 ;
}
return 1 ;
}
int T_11 F_177 ( void )
{
F_178 () ;
return 0 ;
}
static int F_179 ( void )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_90 ; V_27 ++ ) {
struct V_155 * V_88 = & V_91 [ V_27 ] ;
if ( V_88 -> V_158 )
F_51 ( F_131 ( V_27 ) , 0 ) ;
}
return 0 ;
}
static int F_180 ( void )
{
return F_179 () ;
}
static void F_181 ( void )
{
F_179 () ;
}
static void F_182 ( void )
{
F_127 () ;
F_137 ( F_106 ( & V_143 ) ) ;
}
static void F_183 ( void * V_139 )
{
if ( ! F_58 ( F_106 ( & V_143 ) ) )
return;
F_127 () ;
F_140 () ;
}
static void F_184 ( void )
{
F_111 () ;
F_161 ( F_183 , NULL , 1 ) ;
}
static void F_185 ( void * V_139 )
{
if ( ! F_58 ( F_106 ( & V_143 ) ) )
return;
F_186 () ;
}
static void F_187 ( void * V_219 )
{
if ( ! F_58 ( F_106 ( & V_143 ) ) )
return;
F_188 () ;
F_189 () ;
if ( V_219 )
F_140 () ;
}
static inline struct V_155 * F_190 ( struct V_220 * V_221 )
{
return F_191 ( V_221 , struct V_155 , V_221 ) ;
}
static T_8 F_192 ( struct V_222 * V_223 , struct V_220 * V_221 ,
char * V_200 )
{
return sprintf ( V_200 , L_35 , F_190 ( V_221 ) -> V_92 ) ;
}
static T_8 F_193 ( struct V_222 * V_223 , struct V_220 * V_221 ,
const char * V_200 , T_7 V_224 )
{
T_2 V_225 ;
if ( F_194 ( V_200 , 0 , & V_225 ) < 0 )
return - V_195 ;
F_190 ( V_221 ) -> V_92 = V_225 ;
F_184 () ;
return V_224 ;
}
static T_8
F_195 ( struct V_222 * V_223 , struct V_220 * V_221 , char * V_200 )
{
strcpy ( V_200 , V_149 ) ;
strcat ( V_200 , L_7 ) ;
return strlen ( V_149 ) + 1 ;
}
static T_8 F_196 ( struct V_222 * V_223 , struct V_220 * V_221 ,
const char * V_200 , T_7 V_226 )
{
char * V_209 ;
strncpy ( V_149 , V_200 , sizeof( V_149 ) ) ;
V_149 [ sizeof( V_149 ) - 1 ] = 0 ;
V_209 = strchr ( V_149 , '\n' ) ;
if ( V_209 )
* V_209 = 0 ;
return strlen ( V_149 ) + ! ! V_209 ;
}
static T_8 F_197 ( struct V_222 * V_223 ,
struct V_220 * V_221 ,
const char * V_200 , T_7 V_224 )
{
T_2 V_225 ;
if ( F_194 ( V_200 , 0 , & V_225 ) < 0 )
return - V_195 ;
if ( V_179 ^ ! ! V_225 ) {
if ( V_225 ) {
F_111 () ;
F_161 ( F_185 , NULL , 1 ) ;
V_179 = 1 ;
} else {
V_179 = 0 ;
F_161 ( F_187 , ( void * ) 1 , 1 ) ;
}
}
return V_224 ;
}
static T_8 F_198 ( struct V_222 * V_223 ,
struct V_220 * V_221 ,
const char * V_200 , T_7 V_224 )
{
T_2 V_225 ;
if ( F_194 ( V_200 , 0 , & V_225 ) < 0 )
return - V_195 ;
if ( V_218 ^ ! ! V_225 ) {
if ( V_225 ) {
F_161 ( F_185 , NULL , 1 ) ;
V_218 = 1 ;
} else {
V_218 = 0 ;
F_161 ( F_187 , NULL , 1 ) ;
}
}
return V_224 ;
}
static T_8 F_199 ( struct V_222 * V_223 ,
struct V_220 * V_221 ,
const char * V_200 , T_7 V_224 )
{
T_8 V_18 = F_200 ( V_223 , V_221 , V_200 , V_224 ) ;
F_184 () ;
return V_18 ;
}
static void F_201 ( struct V_222 * V_227 )
{
F_163 ( V_227 ) ;
}
static T_5 int F_202 ( unsigned int V_3 )
{
struct V_222 * V_227 ;
int V_163 ;
int V_27 , V_228 ;
if ( ! F_58 ( & V_7 ) )
return - V_229 ;
V_227 = F_123 ( sizeof *V_227 , V_156 ) ;
if ( ! V_227 )
return - V_157 ;
V_227 -> V_230 = V_3 ;
V_227 -> V_231 = & V_232 ;
V_227 -> V_233 = & F_201 ;
V_163 = F_203 ( V_227 ) ;
if ( V_163 )
return V_163 ;
for ( V_27 = 0 ; V_234 [ V_27 ] ; V_27 ++ ) {
V_163 = F_204 ( V_227 , V_234 [ V_27 ] ) ;
if ( V_163 )
goto error;
}
for ( V_228 = 0 ; V_228 < V_90 ; V_228 ++ ) {
V_163 = F_204 ( V_227 , & V_91 [ V_228 ] . V_221 ) ;
if ( V_163 )
goto V_235;
}
F_205 ( V_3 , V_236 ) ;
V_237 [ V_3 ] = V_227 ;
return 0 ;
V_235:
while ( -- V_228 >= 0 )
F_206 ( V_227 , & V_91 [ V_228 ] . V_221 ) ;
error:
while ( -- V_27 >= 0 )
F_206 ( V_227 , V_234 [ V_27 ] ) ;
F_207 ( V_227 ) ;
return V_163 ;
}
static T_5 void F_208 ( unsigned int V_3 )
{
struct V_222 * V_227 = V_237 [ V_3 ] ;
int V_27 ;
if ( ! F_209 ( V_3 , V_236 ) )
return;
for ( V_27 = 0 ; V_234 [ V_27 ] ; V_27 ++ )
F_206 ( V_227 , V_234 [ V_27 ] ) ;
for ( V_27 = 0 ; V_27 < V_90 ; V_27 ++ )
F_206 ( V_227 , & V_91 [ V_27 ] . V_221 ) ;
F_207 ( V_227 ) ;
F_210 ( V_3 , V_236 ) ;
V_237 [ V_3 ] = NULL ;
}
static void T_5 F_211 ( void * V_238 )
{
unsigned long V_239 = * ( unsigned long * ) V_238 ;
int V_27 ;
if ( ! F_58 ( F_106 ( & V_143 ) ) )
return;
if ( ! ( V_239 & V_240 ) )
F_186 () ;
for ( V_27 = 0 ; V_27 < V_90 ; V_27 ++ ) {
struct V_155 * V_88 = & V_91 [ V_27 ] ;
if ( V_88 -> V_158 )
F_51 ( F_131 ( V_27 ) , 0 ) ;
}
}
static void T_5 F_212 ( void * V_238 )
{
unsigned long V_239 = * ( unsigned long * ) V_238 ;
int V_27 ;
if ( ! F_58 ( F_106 ( & V_143 ) ) )
return;
if ( ! ( V_239 & V_240 ) )
F_188 () ;
for ( V_27 = 0 ; V_27 < V_90 ; V_27 ++ ) {
struct V_155 * V_88 = & V_91 [ V_27 ] ;
if ( V_88 -> V_158 )
F_51 ( F_131 ( V_27 ) , V_88 -> V_92 ) ;
}
}
static int T_5
F_213 ( struct V_32 * V_241 , unsigned long V_239 , void * V_242 )
{
unsigned int V_3 = ( unsigned long ) V_242 ;
struct V_140 * V_103 = & F_79 ( V_141 , V_3 ) ;
switch ( V_239 ) {
case V_243 :
case V_244 :
F_202 ( V_3 ) ;
if ( V_245 )
V_245 ( V_239 , V_3 ) ;
break;
case V_246 :
case V_247 :
if ( V_245 )
V_245 ( V_239 , V_3 ) ;
F_208 ( V_3 ) ;
break;
case V_248 :
case V_249 :
F_113 ( V_103 ) ;
F_214 ( V_3 , F_211 , & V_239 , 1 ) ;
break;
case V_250 :
case V_251 :
if ( ! V_179 && V_147 ) {
V_103 -> V_148 = F_142 ( V_30 +
F_47 ( V_145 ) ) ;
F_110 ( V_103 , V_3 ) ;
}
F_214 ( V_3 , F_212 , & V_239 , 1 ) ;
break;
case V_252 :
F_215 ( V_3 ) ;
break;
}
return V_253 ;
}
static T_11 void F_216 ( void )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_90 ; V_27 ++ ) {
struct V_155 * V_88 = & V_91 [ V_27 ] ;
struct V_220 * V_254 = & V_88 -> V_221 ;
F_217 ( & V_254 -> V_221 ) ;
V_254 -> V_221 . V_255 = V_88 -> V_256 ;
snprintf ( V_88 -> V_256 , V_257 , L_36 , V_27 ) ;
V_254 -> V_221 . V_258 = 0644 ;
V_254 -> V_259 = F_192 ;
V_254 -> V_260 = F_193 ;
}
}
static T_11 int F_218 ( void )
{
int V_163 ;
int V_27 = 0 ;
if ( ! F_58 ( & V_7 ) )
return - V_229 ;
F_219 ( & V_236 , V_156 ) ;
F_216 () ;
V_163 = F_220 ( & V_232 , NULL ) ;
if ( V_163 )
return V_163 ;
F_112 (i) {
V_163 = F_202 ( V_27 ) ;
if ( V_163 )
return V_163 ;
}
F_221 ( & V_261 ) ;
F_222 ( & V_262 ) ;
F_223 ( & V_263 ) ;
return V_163 ;
}
static int T_11 F_224 ( char * V_217 )
{
V_77 = 1 ;
return 1 ;
}
struct V_264 * F_225 ( void )
{
static struct V_264 * V_265 ;
if ( ! V_265 )
V_265 = F_226 ( L_37 , NULL ) ;
return V_265 ;
}
static void F_227 ( void )
{
V_58 = 0 ;
F_84 ( & V_55 , 0 ) ;
F_84 ( & V_118 , 0 ) ;
F_84 ( & V_117 , 0 ) ;
F_84 ( & V_116 , 0 ) ;
}
static int F_228 ( void * V_139 , T_2 * V_266 )
{
* V_266 = V_53 ;
return 0 ;
}
static int F_229 ( void * V_139 , T_2 V_266 )
{
F_227 () ;
V_53 = V_266 ;
return 0 ;
}
static int T_11 F_230 ( void )
{
struct V_264 * V_265 , * V_267 ;
V_265 = F_225 () ;
if ( ! V_265 )
return - V_157 ;
V_267 = F_231 ( L_38 , 0444 , V_265 , NULL ,
& V_268 ) ;
if ( ! V_267 )
return - V_157 ;
return 0 ;
}
