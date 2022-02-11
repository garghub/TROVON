void F_1 ( struct V_1 * V_2 )
{
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_3 = V_2 -> V_4 = F_2 () ;
F_3 ( V_2 -> V_5 ) ;
V_2 -> time = F_4 () ;
V_2 -> V_6 = V_7 . V_8 ;
V_2 -> V_9 = F_5 ( 1 ) ;
#ifdef F_6
V_2 -> V_10 = F_7 ( V_2 -> V_4 ) . V_11 ;
#endif
V_2 -> V_12 = F_7 ( V_2 -> V_4 ) . V_13 ;
F_8 ( V_14 , V_2 -> V_15 ) ;
}
void F_9 ( struct V_1 * V_1 )
{
unsigned V_16 , V_17 ;
int V_18 = 0 ;
F_10 ( V_1 ) ;
V_18 = F_11 ( & V_19 , 0 , V_1 ) ;
if ( V_18 == V_20 )
return;
V_1 -> V_21 = 0 ;
F_12 () ;
for (; ; ) {
V_17 = F_13 ( V_22 . V_16 ) ;
for (; ; ) {
if ( V_17 >= V_23 ) {
F_14 ( V_24 ,
( unsigned long * ) & V_22 . V_25 ) ;
return;
}
if ( V_22 . V_17 [ V_17 ] . V_21 ) {
V_17 ++ ;
continue;
}
break;
}
F_15 () ;
V_16 = V_17 + 1 ;
if ( F_16 ( & V_22 . V_16 , V_17 , V_16 ) == V_17 )
break;
}
memcpy ( V_22 . V_17 + V_17 , V_1 , sizeof( struct V_1 ) ) ;
F_12 () ;
V_22 . V_17 [ V_17 ] . V_21 = 1 ;
F_12 () ;
V_1 -> V_21 = 1 ;
F_14 ( 0 , & V_26 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
int V_18 = 0 ;
F_18 ( V_27 L_1 ,
V_2 -> V_4 , V_2 -> V_28 , V_2 -> V_29 , V_2 -> V_30 ) ;
if ( V_2 -> V_31 ) {
F_18 ( V_27 L_2 ,
! ( V_2 -> V_28 & V_32 ) ? L_3 : L_4 ,
V_2 -> V_33 , V_2 -> V_31 ) ;
if ( V_2 -> V_33 == V_34 )
F_19 ( L_5 , V_2 -> V_31 ) ;
F_20 ( L_6 ) ;
}
F_18 ( V_27 L_7 , V_2 -> V_5 ) ;
if ( V_2 -> V_35 )
F_20 ( L_8 , V_2 -> V_35 ) ;
if ( V_2 -> V_36 )
F_20 ( L_9 , V_2 -> V_36 ) ;
F_20 ( L_6 ) ;
F_18 ( V_27 L_10 ,
V_2 -> V_6 , V_2 -> V_9 , V_2 -> time , V_2 -> V_10 , V_2 -> V_12 ,
F_7 ( V_2 -> V_4 ) . V_37 ) ;
V_18 = F_11 ( & V_19 , 0 , V_2 ) ;
if ( V_18 == V_20 )
return;
F_21 ( V_27 L_11 ) ;
}
static void F_22 ( void )
{
long V_38 = V_39 * V_40 ;
F_23 () ;
F_24 () ;
while ( V_38 -- > 0 )
F_25 ( 1 ) ;
if ( V_41 == 0 )
V_41 = V_42 ;
F_26 ( L_12 ) ;
}
static void F_27 ( char * V_43 , struct V_1 * V_44 , char * exp )
{
int V_45 , V_46 = 0 ;
if ( ! V_47 ) {
if ( F_28 ( & V_48 ) > 1 )
F_22 () ;
F_29 () ;
F_30 ( 1 ) ;
F_31 () ;
} else {
if ( F_28 ( & V_49 ) > 1 )
return;
}
for ( V_45 = 0 ; V_45 < V_23 ; V_45 ++ ) {
struct V_1 * V_2 = & V_22 . V_17 [ V_45 ] ;
if ( ! ( V_2 -> V_30 & V_50 ) )
continue;
if ( ! ( V_2 -> V_30 & V_51 ) ) {
F_17 ( V_2 ) ;
if ( ! V_46 )
V_46 = F_32 ( V_2 ) ;
}
}
for ( V_45 = 0 ; V_45 < V_23 ; V_45 ++ ) {
struct V_1 * V_2 = & V_22 . V_17 [ V_45 ] ;
if ( ! ( V_2 -> V_30 & V_50 ) )
continue;
if ( ! ( V_2 -> V_30 & V_51 ) )
continue;
if ( ! V_44 || memcmp ( V_2 , V_44 , sizeof( struct V_1 ) ) ) {
F_17 ( V_2 ) ;
if ( ! V_46 )
V_46 = F_32 ( V_2 ) ;
}
}
if ( V_44 ) {
F_17 ( V_44 ) ;
if ( ! V_46 )
V_46 = F_32 ( V_44 ) ;
}
if ( V_52 )
F_18 ( V_27 L_13 ) ;
if ( exp )
F_18 ( V_27 L_14 , exp ) ;
if ( ! V_47 ) {
if ( V_41 == 0 )
V_41 = V_42 ;
F_26 ( V_43 ) ;
} else
F_18 ( V_27 L_15 , V_43 ) ;
}
static int F_33 ( T_1 V_53 )
{
unsigned V_29 = F_34 ( V_54 . V_29 ) ;
if ( V_53 == V_55 )
return F_35 ( struct V_1 , V_31 ) ;
if ( V_53 == F_36 ( V_29 ) )
return F_35 ( struct V_1 , V_30 ) ;
if ( V_53 == F_37 ( V_29 ) )
return F_35 ( struct V_1 , V_35 ) ;
if ( V_53 == F_38 ( V_29 ) )
return F_35 ( struct V_1 , V_36 ) ;
if ( V_53 == V_56 )
return F_35 ( struct V_1 , V_28 ) ;
return - 1 ;
}
static T_2 F_39 ( T_1 V_53 )
{
T_2 V_57 ;
if ( F_34 ( V_54 . V_21 ) ) {
int V_58 = F_33 ( V_53 ) ;
if ( V_58 < 0 )
return 0 ;
return * ( T_2 * ) ( ( char * ) & F_40 ( V_54 ) + V_58 ) ;
}
if ( F_41 ( V_53 , & V_57 ) ) {
F_42 ( 1 , L_16 , V_53 ) ;
V_57 = 0 ;
}
return V_57 ;
}
static void F_43 ( T_1 V_53 , T_2 V_57 )
{
if ( F_34 ( V_54 . V_21 ) ) {
int V_58 = F_33 ( V_53 ) ;
if ( V_58 >= 0 )
* ( T_2 * ) ( ( char * ) & F_40 ( V_54 ) + V_58 ) = V_57 ;
return;
}
F_44 ( V_53 , V_57 ) ;
}
static inline void F_45 ( struct V_1 * V_2 , struct V_59 * V_60 )
{
F_1 ( V_2 ) ;
V_2 -> V_28 = F_39 ( V_56 ) ;
if ( V_60 ) {
if ( V_2 -> V_28 & ( V_61 | V_32 ) ) {
V_2 -> V_31 = V_60 -> V_31 ;
V_2 -> V_33 = V_60 -> V_33 ;
}
if ( V_55 )
V_2 -> V_31 = F_39 ( V_55 ) ;
}
}
static int F_46 ( void )
{
struct V_62 * V_63 = & F_40 ( V_62 ) ;
return V_63 -> V_64 == V_63 -> V_65 ;
}
static int F_47 ( unsigned long * V_66 )
{
struct V_62 * V_63 ;
int V_18 = 0 ;
* V_66 = 0 ;
F_48 () ;
V_63 = & F_40 ( V_62 ) ;
if ( V_63 -> V_64 == V_63 -> V_65 )
goto V_67;
* V_66 = V_63 -> V_68 [ V_63 -> V_64 ] ;
V_63 -> V_64 = ( V_63 -> V_64 + 1 ) % V_69 ;
V_18 = 1 ;
V_67:
F_49 () ;
return V_18 ;
}
static int F_50 ( unsigned long V_66 )
{
struct V_62 * V_63 = & F_40 ( V_62 ) ;
unsigned V_16 ;
V_16 = ( V_63 -> V_65 + 1 ) % V_69 ;
if ( V_16 == V_63 -> V_64 )
return - 1 ;
V_63 -> V_68 [ V_63 -> V_65 ] = V_66 ;
F_12 () ;
V_63 -> V_65 = V_16 ;
return 0 ;
}
int F_51 ( struct V_70 * V_71 )
{
if ( V_72 )
return 0 ;
return F_52 ( V_71 , V_73 ) && F_52 ( V_71 , V_74 ) ;
}
static void F_53 ( void )
{
if ( ! F_46 () ) {
struct V_75 * V_76 = & F_40 ( V_77 ) ;
if ( ! F_54 ( V_76 ) )
F_55 ( V_76 ) ;
}
}
static void F_56 ( struct V_78 * V_17 )
{
F_57 () ;
F_53 () ;
}
static void F_58 ( struct V_59 * V_60 )
{
if ( V_60 -> V_25 & ( V_79 | V_80 ) ) {
F_57 () ;
F_53 () ;
return;
}
F_59 ( & F_40 ( V_81 ) ) ;
}
void F_60 ( enum V_82 V_25 , T_3 * V_83 )
{
struct V_1 V_2 ;
int V_45 ;
F_61 ( V_84 ) ;
F_45 ( & V_2 , NULL ) ;
for ( V_45 = 0 ; V_45 < V_85 ; V_45 ++ ) {
if ( ! V_86 [ V_45 ] . V_87 || ! F_62 ( V_45 , * V_83 ) )
continue;
V_2 . V_36 = 0 ;
V_2 . V_35 = 0 ;
V_2 . V_29 = V_45 ;
V_2 . V_5 = 0 ;
F_29 () ;
V_2 . V_30 = F_39 ( F_36 ( V_45 ) ) ;
if ( ! ( V_2 . V_30 & V_50 ) )
continue;
if ( ! ( V_25 & V_88 ) &&
( V_2 . V_30 & ( V_89 ? V_90 : V_51 ) ) )
continue;
if ( V_2 . V_30 & V_91 )
V_2 . V_36 = F_39 ( F_38 ( V_45 ) ) ;
if ( V_2 . V_30 & V_92 )
V_2 . V_35 = F_39 ( F_37 ( V_45 ) ) ;
if ( ! ( V_25 & V_93 ) )
V_2 . V_5 = 0 ;
if ( ! ( V_25 & V_94 ) && ! V_95 )
F_9 ( & V_2 ) ;
F_43 ( F_36 ( V_45 ) , 0 ) ;
}
F_63 () ;
}
static int F_64 ( struct V_1 * V_2 , char * * V_43 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < V_85 ; V_45 ++ ) {
V_2 -> V_30 = F_39 ( F_36 ( V_45 ) ) ;
if ( F_65 ( V_2 , V_96 , V_43 ) >= V_97 )
return 1 ;
}
return 0 ;
}
static int F_66 ( T_2 * V_98 )
{
F_67 () ;
if ( F_68 ( & V_48 ) )
F_22 () ;
if ( ! V_99 )
goto V_67;
if ( ( V_100 ) * V_98 < V_101 ) {
if ( V_96 < 1 )
F_27 ( L_17 ,
NULL , NULL ) ;
V_52 = 1 ;
return 1 ;
}
* V_98 -= V_101 ;
V_67:
F_69 () ;
return 0 ;
}
static void F_70 ( void )
{
int V_3 ;
struct V_1 * V_2 = NULL ;
int V_102 = 0 ;
char * V_43 = NULL ;
char * V_103 = NULL ;
F_71 (cpu) {
int V_104 = F_65 ( & F_72 ( V_105 , V_3 ) , V_96 ,
& V_103 ) ;
if ( V_104 > V_102 ) {
V_43 = V_103 ;
V_102 = V_104 ;
V_2 = & F_72 ( V_105 , V_3 ) ;
}
}
if ( V_2 && V_102 >= V_97 && V_96 < 3 )
F_27 ( L_18 , V_2 , V_43 ) ;
if ( V_102 <= V_106 && V_96 < 3 )
F_27 ( L_19 , NULL , NULL ) ;
F_71 (cpu)
memset ( & F_72 ( V_105 , V_3 ) , 0 , sizeof( struct V_1 ) ) ;
}
static int F_73 ( int * V_107 )
{
int V_108 ;
int V_109 = F_74 () ;
T_2 V_38 = ( T_2 ) V_99 * V_110 ;
if ( ! V_38 )
return - 1 ;
F_75 ( * V_107 , & V_111 ) ;
F_76 () ;
V_108 = F_28 ( & V_112 ) ;
while ( F_68 ( & V_112 ) != V_109 ) {
if ( F_66 ( & V_38 ) ) {
F_77 ( & V_111 , 0 ) ;
return - 1 ;
}
F_78 ( V_101 ) ;
}
F_15 () ;
if ( V_108 == 1 ) {
F_77 ( & V_113 , 1 ) ;
} else {
while ( F_68 ( & V_113 ) < V_108 ) {
if ( F_66 ( & V_38 ) ) {
F_77 ( & V_111 , 0 ) ;
return - 1 ;
}
F_78 ( V_101 ) ;
}
}
* V_107 = F_68 ( & V_111 ) ;
return V_108 ;
}
static int F_79 ( int V_108 )
{
int V_18 = - 1 ;
T_2 V_38 = ( T_2 ) V_99 * V_110 ;
if ( ! V_38 )
goto V_114;
if ( V_108 < 0 )
goto V_114;
F_80 ( & V_113 ) ;
if ( V_108 == 1 ) {
int V_109 = F_74 () ;
while ( F_68 ( & V_113 ) <= V_109 ) {
if ( F_66 ( & V_38 ) )
goto V_114;
F_78 ( V_101 ) ;
}
F_70 () ;
F_29 () ;
V_18 = 0 ;
} else {
while ( F_68 ( & V_113 ) != 0 ) {
if ( F_66 ( & V_38 ) )
goto V_114;
F_78 ( V_101 ) ;
}
return 0 ;
}
V_114:
F_77 ( & V_111 , 0 ) ;
F_77 ( & V_112 , 0 ) ;
F_29 () ;
F_77 ( & V_113 , 0 ) ;
return V_18 ;
}
static int F_81 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_30 & V_91 ) || ! ( V_2 -> V_30 & V_92 ) )
return 0 ;
if ( F_82 ( V_2 -> V_36 ) > V_115 )
return 0 ;
if ( F_83 ( V_2 -> V_36 ) != V_116 )
return 0 ;
return 1 ;
}
static void F_84 ( unsigned long * V_117 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < V_85 ; V_45 ++ ) {
if ( F_62 ( V_45 , V_117 ) )
F_43 ( F_36 ( V_45 ) , 0 ) ;
}
}
void F_85 ( struct V_59 * V_60 , long V_118 )
{
struct V_1 V_2 , * V_44 ;
int V_45 ;
int V_119 = 0 ;
int V_104 ;
int V_108 ;
int V_107 = 0 ;
int V_120 = 0 ;
F_86 ( V_117 , V_121 ) ;
char * V_43 = L_20 ;
F_80 ( & V_122 ) ;
F_61 ( V_123 ) ;
if ( ! V_85 )
goto V_67;
F_45 ( & V_2 , V_60 ) ;
V_44 = & F_40 ( V_105 ) ;
* V_44 = V_2 ;
V_107 = F_64 ( & V_2 , & V_43 ) ;
F_29 () ;
if ( ! ( V_2 . V_28 & V_61 ) )
V_120 = 1 ;
V_108 = F_73 ( & V_107 ) ;
for ( V_45 = 0 ; V_45 < V_85 ; V_45 ++ ) {
F_87 ( V_45 , V_117 ) ;
if ( ! V_86 [ V_45 ] . V_87 )
continue;
V_2 . V_36 = 0 ;
V_2 . V_35 = 0 ;
V_2 . V_29 = V_45 ;
V_2 . V_30 = F_39 ( F_36 ( V_45 ) ) ;
if ( ( V_2 . V_30 & V_50 ) == 0 )
continue;
if ( ! ( V_2 . V_30 & ( V_89 ? V_90 : V_51 ) ) &&
! V_107 )
continue;
F_88 ( V_124 ) ;
V_104 = F_65 ( & V_2 , V_96 , NULL ) ;
if ( V_104 == V_106 && ! V_107 )
continue;
F_89 ( V_45 , V_117 ) ;
if ( V_104 == V_125 ) {
continue;
}
if ( V_104 == V_126 )
V_120 = 1 ;
if ( V_2 . V_30 & V_91 )
V_2 . V_36 = F_39 ( F_38 ( V_45 ) ) ;
if ( V_2 . V_30 & V_92 )
V_2 . V_35 = F_39 ( F_37 ( V_45 ) ) ;
if ( V_104 == V_127 && F_81 ( & V_2 ) )
F_50 ( V_2 . V_35 >> V_115 ) ;
F_9 ( & V_2 ) ;
if ( V_104 > V_119 ) {
* V_44 = V_2 ;
V_119 = V_104 ;
}
}
if ( ! V_107 )
F_84 ( V_117 ) ;
if ( F_79 ( V_108 ) < 0 )
V_107 = V_119 >= V_97 ;
if ( V_107 && V_96 < 3 )
F_27 ( L_21 , V_44 , V_43 ) ;
if ( V_120 && V_96 < 3 )
F_90 ( V_128 , V_129 ) ;
F_91 ( V_130 ) ;
if ( V_119 > 0 )
F_58 ( V_60 ) ;
F_43 ( V_56 , 0 ) ;
V_67:
F_92 ( & V_122 ) ;
F_63 () ;
}
void F_93 ( void )
{
unsigned long V_66 ;
F_57 () ;
while ( F_47 ( & V_66 ) )
F_94 ( V_66 , V_131 ) ;
}
static void F_95 ( struct V_75 * V_132 )
{
F_93 () ;
}
void F_96 ( T_4 V_30 )
{
struct V_1 V_2 ;
F_1 ( & V_2 ) ;
V_2 . V_29 = V_133 ;
V_2 . V_30 = V_30 ;
F_9 ( & V_2 ) ;
}
static void F_97 ( unsigned long V_134 )
{
struct V_135 * V_98 = & F_72 ( V_136 , V_134 ) ;
int * V_137 ;
F_98 ( F_2 () != V_134 ) ;
if ( F_51 ( F_99 ( & V_138 ) ) ) {
F_60 ( V_93 ,
& F_40 ( V_139 ) ) ;
}
V_137 = & F_40 ( V_140 ) ;
if ( F_57 () )
* V_137 = F_100 ( * V_137 / 2 , V_141 / 100 ) ;
else
* V_137 = F_101 ( * V_137 * 2 , ( int ) F_102 ( V_142 * V_141 ) ) ;
V_98 -> V_143 = V_144 + * V_137 ;
F_103 ( V_98 , F_2 () ) ;
}
static void F_104 ( void )
{
int V_3 ;
F_105 (cpu)
F_106 ( & F_72 ( V_136 , V_3 ) ) ;
}
static void F_107 ( struct V_75 * V_76 )
{
F_108 ( V_145 , V_146 , NULL , V_147 ) ;
}
int F_57 ( void )
{
static F_109 ( V_148 , 60 * V_141 , 2 ) ;
F_110 ( V_130 ) ;
if ( F_111 ( 0 , & V_26 ) ) {
F_112 ( & V_149 ) ;
if ( V_145 [ 0 ] && ! F_54 ( & V_150 ) )
F_55 ( & V_150 ) ;
if ( F_113 ( & V_148 ) )
F_114 ( V_27 L_22 ) ;
return 1 ;
}
return 0 ;
}
static int T_5 F_115 ( void )
{
int V_45 ;
V_86 = F_116 ( V_85 * sizeof( struct V_151 ) , V_152 ) ;
if ( ! V_86 )
return - V_153 ;
for ( V_45 = 0 ; V_45 < V_85 ; V_45 ++ ) {
struct V_151 * V_83 = & V_86 [ V_45 ] ;
V_83 -> V_87 = - 1ULL ;
V_83 -> V_154 = 1 ;
}
return 0 ;
}
static int T_5 F_117 ( void )
{
unsigned V_83 ;
T_2 V_155 ;
F_8 ( V_14 , V_155 ) ;
V_83 = V_155 & V_156 ;
if ( ! V_85 )
F_118 ( V_157 L_23 , V_83 ) ;
if ( V_83 > V_121 ) {
F_118 ( V_158
L_24 ,
V_121 , V_83 ) ;
V_83 = V_121 ;
}
F_98 ( V_85 != 0 && V_83 != V_85 ) ;
V_85 = V_83 ;
if ( ! V_86 ) {
int V_159 = F_115 () ;
if ( V_159 )
return V_159 ;
}
if ( ( V_155 & V_160 ) && F_119 ( V_155 ) >= 9 )
V_55 = V_161 ;
if ( V_155 & V_162 )
V_89 = 1 ;
return 0 ;
}
static void F_120 ( void )
{
T_3 V_163 ;
T_2 V_155 ;
int V_45 ;
F_121 ( V_163 , V_121 ) ;
F_60 ( V_88 | ( ! V_164 ? V_94 : 0 ) , & V_163 ) ;
F_122 ( V_165 ) ;
F_8 ( V_14 , V_155 ) ;
if ( V_155 & V_166 )
F_123 ( V_167 , 0xffffffff , 0xffffffff ) ;
for ( V_45 = 0 ; V_45 < V_85 ; V_45 ++ ) {
struct V_151 * V_83 = & V_86 [ V_45 ] ;
if ( ! V_83 -> V_154 )
continue;
F_44 ( F_124 ( V_45 ) , V_83 -> V_87 ) ;
F_44 ( F_36 ( V_45 ) , 0 ) ;
}
}
static int T_5 F_125 ( struct V_70 * V_71 )
{
if ( V_71 -> V_8 == V_168 ) {
F_114 ( L_25 ) ;
return - V_169 ;
}
if ( V_71 -> V_8 == V_170 ) {
if ( V_71 -> V_171 == 15 && V_85 > 4 ) {
F_126 ( 10 , ( unsigned long * ) & V_86 [ 4 ] . V_87 ) ;
}
if ( V_71 -> V_171 <= 17 && V_164 < 0 ) {
V_164 = 0 ;
}
if ( V_71 -> V_171 == 6 && V_85 > 0 )
V_86 [ 0 ] . V_87 = 0 ;
}
if ( V_71 -> V_8 == V_172 ) {
if ( V_71 -> V_171 == 6 && V_71 -> V_173 < 0x1A && V_85 > 0 )
V_86 [ 0 ] . V_154 = 0 ;
if ( ( V_71 -> V_171 > 6 || ( V_71 -> V_171 == 6 && V_71 -> V_173 >= 0xe ) ) &&
V_99 < 0 )
V_99 = V_40 ;
if ( V_71 -> V_171 == 6 && V_71 -> V_173 <= 13 && V_164 < 0 )
V_164 = 0 ;
}
if ( V_99 < 0 )
V_99 = 0 ;
if ( V_164 != 0 )
V_42 = 30 ;
return 0 ;
}
static int T_5 F_127 ( struct V_70 * V_71 )
{
if ( V_71 -> V_171 != 5 )
return 0 ;
switch ( V_71 -> V_8 ) {
case V_172 :
F_128 ( V_71 ) ;
return 1 ;
break;
case V_174 :
F_129 ( V_71 ) ;
return 1 ;
break;
}
return 0 ;
}
static void F_130 ( struct V_70 * V_71 )
{
switch ( V_71 -> V_8 ) {
case V_172 :
F_131 ( V_71 ) ;
break;
case V_170 :
F_132 ( V_71 ) ;
break;
default:
break;
}
}
static void F_133 ( void )
{
struct V_135 * V_98 = & F_40 ( V_136 ) ;
int * V_137 = & F_40 ( V_140 ) ;
F_134 ( V_98 , F_97 , F_2 () ) ;
if ( V_175 )
return;
* V_137 = V_142 * V_141 ;
if ( ! * V_137 )
return;
V_98 -> V_143 = F_135 ( V_144 + * V_137 ) ;
F_103 ( V_98 , F_2 () ) ;
}
static void F_136 ( struct V_59 * V_60 , long V_118 )
{
F_118 ( V_176 L_26 ,
F_2 () ) ;
}
void T_5 F_137 ( struct V_70 * V_71 )
{
if ( V_72 )
return;
if ( F_127 ( V_71 ) )
return;
if ( ! F_51 ( V_71 ) )
return;
if ( F_117 () < 0 || F_125 ( V_71 ) < 0 ) {
V_72 = 1 ;
return;
}
V_177 = F_85 ;
F_120 () ;
F_130 ( V_71 ) ;
F_133 () ;
F_138 ( & F_40 ( V_77 ) , F_95 ) ;
F_139 ( & F_40 ( V_81 ) , & F_56 ) ;
}
static int F_140 ( struct V_178 * V_178 , struct V_179 * V_179 )
{
F_141 ( & V_180 ) ;
if ( V_181 ||
( V_182 && ( V_179 -> V_183 & V_184 ) ) ) {
F_142 ( & V_180 ) ;
return - V_185 ;
}
if ( V_179 -> V_183 & V_184 )
V_181 = 1 ;
V_182 ++ ;
F_142 ( & V_180 ) ;
return F_143 ( V_178 , V_179 ) ;
}
static int F_144 ( struct V_178 * V_178 , struct V_179 * V_179 )
{
F_141 ( & V_180 ) ;
V_182 -- ;
V_181 = 0 ;
F_142 ( & V_180 ) ;
return 0 ;
}
static void F_145 ( void * V_134 )
{
unsigned long * V_186 = ( unsigned long * ) V_134 ;
F_3 ( V_186 [ F_2 () ] ) ;
}
static int F_146 ( char T_6 * * V_187 , T_7 V_188 )
{
int V_189 ;
T_2 V_190 ;
struct V_1 V_2 ;
if ( V_188 < sizeof( struct V_1 ) )
return - V_191 ;
V_189 = F_147 ( & V_2 , & V_190 ) ;
if ( V_189 <= 0 ) {
V_192 = 1 ;
return V_189 ;
}
V_189 = - V_193 ;
if ( F_148 ( * V_187 , & V_2 , sizeof( struct V_1 ) ) )
return V_189 ;
V_189 = F_149 ( V_190 ) ;
if ( V_189 ) {
V_192 = 1 ;
return V_189 ;
}
* V_187 += sizeof( struct V_1 ) ;
return 0 ;
}
static T_8 F_150 ( struct V_179 * V_194 , char T_6 * V_187 ,
T_7 V_188 , T_9 * V_195 )
{
char T_6 * V_196 = V_187 ;
unsigned long * V_186 ;
unsigned V_197 , V_16 ;
int V_45 , V_159 ;
V_186 = F_151 ( V_198 * sizeof( long ) , V_152 ) ;
if ( ! V_186 )
return - V_153 ;
F_152 ( & V_199 ) ;
if ( ! V_192 ) {
V_159 = F_146 ( & V_196 , V_188 ) ;
if ( V_159 || V_196 != V_187 )
goto V_67;
}
V_16 = F_13 ( V_22 . V_16 ) ;
V_159 = - V_191 ;
if ( * V_195 != 0 || V_188 < V_23 * sizeof( struct V_1 ) )
goto V_67;
V_159 = 0 ;
V_197 = 0 ;
do {
for ( V_45 = V_197 ; V_45 < V_16 ; V_45 ++ ) {
unsigned long V_64 = V_144 ;
struct V_1 * V_2 = & V_22 . V_17 [ V_45 ] ;
while ( ! V_2 -> V_21 ) {
if ( F_153 ( V_144 , V_64 + 2 ) ) {
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
goto V_38;
}
F_154 () ;
}
F_15 () ;
V_159 |= F_148 ( V_196 , V_2 , sizeof( * V_2 ) ) ;
V_196 += sizeof( * V_2 ) ;
V_38:
;
}
memset ( V_22 . V_17 + V_197 , 0 ,
( V_16 - V_197 ) * sizeof( struct V_1 ) ) ;
V_197 = V_16 ;
V_16 = F_16 ( & V_22 . V_16 , V_197 , 0 ) ;
} while ( V_16 != V_197 );
F_155 () ;
F_156 ( F_145 , V_186 , 1 ) ;
for ( V_45 = V_16 ; V_45 < V_23 ; V_45 ++ ) {
struct V_1 * V_2 = & V_22 . V_17 [ V_45 ] ;
if ( V_2 -> V_21 && V_2 -> V_5 < V_186 [ V_2 -> V_3 ] ) {
V_159 |= F_148 ( V_196 , V_2 , sizeof( * V_2 ) ) ;
F_15 () ;
V_196 += sizeof( * V_2 ) ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
}
}
if ( V_159 )
V_159 = - V_193 ;
V_67:
F_157 ( & V_199 ) ;
F_158 ( V_186 ) ;
return V_159 ? V_159 : V_196 - V_187 ;
}
static unsigned int F_159 ( struct V_179 * V_179 , T_10 * V_200 )
{
F_160 ( V_179 , & V_149 , V_200 ) ;
if ( F_161 ( V_22 . V_16 ) )
return V_201 | V_202 ;
if ( ! V_192 && F_162 () )
return V_201 | V_202 ;
return 0 ;
}
static long F_163 ( struct V_179 * V_203 , unsigned int V_204 ,
unsigned long V_205 )
{
int T_6 * V_206 = ( int T_6 * ) V_205 ;
if ( ! F_164 ( V_207 ) )
return - V_208 ;
switch ( V_204 ) {
case V_209 :
return F_165 ( sizeof( struct V_1 ) , V_206 ) ;
case V_210 :
return F_165 ( V_23 , V_206 ) ;
case V_211 : {
unsigned V_25 ;
do {
V_25 = V_22 . V_25 ;
} while ( F_16 ( & V_22 . V_25 , V_25 , 0 ) != V_25 );
return F_165 ( V_25 , V_206 ) ;
}
default:
return - V_212 ;
}
}
void F_166 ( T_8 (* F_167)( struct V_179 * V_194 ,
const char T_6 * V_187 ,
T_7 V_188 , T_9 * V_195 ) )
{
V_213 = F_167 ;
}
T_8 F_168 ( struct V_179 * V_194 , const char T_6 * V_187 ,
T_7 V_188 , T_9 * V_195 )
{
if ( V_213 )
return V_213 ( V_194 , V_187 , V_188 , V_195 ) ;
else
return - V_191 ;
}
static int T_11 F_169 ( char * V_214 )
{
if ( * V_214 == 0 ) {
F_170 () ;
return 1 ;
}
if ( * V_214 == '=' )
V_214 ++ ;
if ( ! strcmp ( V_214 , L_27 ) )
V_72 = 1 ;
else if ( ! strcmp ( V_214 , L_28 ) )
V_215 = 1 ;
else if ( ! strcmp ( V_214 , L_29 ) )
V_95 = 1 ;
else if ( ! strcmp ( V_214 , L_30 ) )
V_175 = 1 ;
else if ( ! strcmp ( V_214 , L_31 ) || ! strcmp ( V_214 , L_32 ) )
V_164 = ( V_214 [ 0 ] == 'b' ) ;
else if ( isdigit ( V_214 [ 0 ] ) ) {
F_171 ( & V_214 , & V_96 ) ;
if ( * V_214 == ',' ) {
++ V_214 ;
F_171 ( & V_214 , & V_99 ) ;
}
} else {
F_118 ( V_157 L_33 ,
V_214 ) ;
return 0 ;
}
return 1 ;
}
int T_11 F_172 ( void )
{
F_173 () ;
return 0 ;
}
static int F_174 ( void )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < V_85 ; V_45 ++ ) {
struct V_151 * V_83 = & V_86 [ V_45 ] ;
if ( V_83 -> V_154 )
F_44 ( F_124 ( V_45 ) , 0 ) ;
}
return 0 ;
}
static int F_175 ( void )
{
return F_174 () ;
}
static void F_176 ( void )
{
F_174 () ;
}
static void F_177 ( void )
{
F_120 () ;
F_130 ( F_99 ( & V_138 ) ) ;
}
static void F_178 ( void * V_134 )
{
if ( ! F_51 ( F_99 ( & V_138 ) ) )
return;
F_120 () ;
F_133 () ;
}
static void F_179 ( void )
{
F_104 () ;
F_156 ( F_178 , NULL , 1 ) ;
}
static void F_180 ( void * V_134 )
{
if ( ! F_51 ( F_99 ( & V_138 ) ) )
return;
F_181 () ;
}
static void F_182 ( void * V_216 )
{
if ( ! F_51 ( F_99 ( & V_138 ) ) )
return;
F_183 () ;
F_184 () ;
if ( V_216 )
F_133 () ;
}
static inline struct V_151 * F_185 ( struct V_217 * V_218 )
{
return F_186 ( V_218 , struct V_151 , V_218 ) ;
}
static T_8 F_187 ( struct V_219 * V_220 , struct V_217 * V_218 ,
char * V_196 )
{
return sprintf ( V_196 , L_34 , F_185 ( V_218 ) -> V_87 ) ;
}
static T_8 F_188 ( struct V_219 * V_220 , struct V_217 * V_218 ,
const char * V_196 , T_7 V_221 )
{
T_2 V_222 ;
if ( F_189 ( V_196 , 0 , & V_222 ) < 0 )
return - V_191 ;
F_185 ( V_218 ) -> V_87 = V_222 ;
F_179 () ;
return V_221 ;
}
static T_8
F_190 ( struct V_219 * V_220 , struct V_217 * V_218 , char * V_196 )
{
strcpy ( V_196 , V_145 ) ;
strcat ( V_196 , L_6 ) ;
return strlen ( V_145 ) + 1 ;
}
static T_8 F_191 ( struct V_219 * V_220 , struct V_217 * V_218 ,
const char * V_196 , T_7 V_223 )
{
char * V_206 ;
strncpy ( V_145 , V_196 , sizeof( V_145 ) ) ;
V_145 [ sizeof( V_145 ) - 1 ] = 0 ;
V_206 = strchr ( V_145 , '\n' ) ;
if ( V_206 )
* V_206 = 0 ;
return strlen ( V_145 ) + ! ! V_206 ;
}
static T_8 F_192 ( struct V_219 * V_220 ,
struct V_217 * V_218 ,
const char * V_196 , T_7 V_221 )
{
T_2 V_222 ;
if ( F_189 ( V_196 , 0 , & V_222 ) < 0 )
return - V_191 ;
if ( V_175 ^ ! ! V_222 ) {
if ( V_222 ) {
F_104 () ;
F_156 ( F_180 , NULL , 1 ) ;
V_175 = 1 ;
} else {
V_175 = 0 ;
F_156 ( F_182 , ( void * ) 1 , 1 ) ;
}
}
return V_221 ;
}
static T_8 F_193 ( struct V_219 * V_220 ,
struct V_217 * V_218 ,
const char * V_196 , T_7 V_221 )
{
T_2 V_222 ;
if ( F_189 ( V_196 , 0 , & V_222 ) < 0 )
return - V_191 ;
if ( V_215 ^ ! ! V_222 ) {
if ( V_222 ) {
F_156 ( F_180 , NULL , 1 ) ;
V_215 = 1 ;
} else {
V_215 = 0 ;
F_156 ( F_182 , NULL , 1 ) ;
}
}
return V_221 ;
}
static T_8 F_194 ( struct V_219 * V_220 ,
struct V_217 * V_218 ,
const char * V_196 , T_7 V_221 )
{
T_8 V_18 = F_195 ( V_220 , V_218 , V_196 , V_221 ) ;
F_179 () ;
return V_18 ;
}
static T_5 int F_196 ( unsigned int V_3 )
{
struct V_219 * V_224 = & F_72 ( V_225 , V_3 ) ;
int V_159 ;
int V_45 , V_226 ;
if ( ! F_51 ( & V_7 ) )
return - V_227 ;
memset ( & V_224 -> V_228 , 0 , sizeof( struct V_229 ) ) ;
V_224 -> V_230 = V_3 ;
V_224 -> V_231 = & V_232 ;
V_159 = F_197 ( V_224 ) ;
if ( V_159 )
return V_159 ;
for ( V_45 = 0 ; V_233 [ V_45 ] ; V_45 ++ ) {
V_159 = F_198 ( V_224 , V_233 [ V_45 ] ) ;
if ( V_159 )
goto error;
}
for ( V_226 = 0 ; V_226 < V_85 ; V_226 ++ ) {
V_159 = F_198 ( V_224 , & V_86 [ V_226 ] . V_218 ) ;
if ( V_159 )
goto V_234;
}
F_199 ( V_3 , V_235 ) ;
return 0 ;
V_234:
while ( -- V_226 >= 0 )
F_200 ( V_224 , & V_86 [ V_226 ] . V_218 ) ;
error:
while ( -- V_45 >= 0 )
F_200 ( V_224 , V_233 [ V_45 ] ) ;
F_201 ( V_224 ) ;
return V_159 ;
}
static T_5 void F_202 ( unsigned int V_3 )
{
struct V_219 * V_224 = & F_72 ( V_225 , V_3 ) ;
int V_45 ;
if ( ! F_203 ( V_3 , V_235 ) )
return;
for ( V_45 = 0 ; V_233 [ V_45 ] ; V_45 ++ )
F_200 ( V_224 , V_233 [ V_45 ] ) ;
for ( V_45 = 0 ; V_45 < V_85 ; V_45 ++ )
F_200 ( V_224 , & V_86 [ V_45 ] . V_218 ) ;
F_201 ( V_224 ) ;
F_204 ( V_3 , V_235 ) ;
}
static void T_5 F_205 ( void * V_236 )
{
unsigned long V_237 = * ( unsigned long * ) V_236 ;
int V_45 ;
if ( ! F_51 ( F_99 ( & V_138 ) ) )
return;
if ( ! ( V_237 & V_238 ) )
F_181 () ;
for ( V_45 = 0 ; V_45 < V_85 ; V_45 ++ ) {
struct V_151 * V_83 = & V_86 [ V_45 ] ;
if ( V_83 -> V_154 )
F_44 ( F_124 ( V_45 ) , 0 ) ;
}
}
static void T_5 F_206 ( void * V_236 )
{
unsigned long V_237 = * ( unsigned long * ) V_236 ;
int V_45 ;
if ( ! F_51 ( F_99 ( & V_138 ) ) )
return;
if ( ! ( V_237 & V_238 ) )
F_183 () ;
for ( V_45 = 0 ; V_45 < V_85 ; V_45 ++ ) {
struct V_151 * V_83 = & V_86 [ V_45 ] ;
if ( V_83 -> V_154 )
F_44 ( F_124 ( V_45 ) , V_83 -> V_87 ) ;
}
}
static int T_5
F_207 ( struct V_239 * V_240 , unsigned long V_237 , void * V_241 )
{
unsigned int V_3 = ( unsigned long ) V_241 ;
struct V_135 * V_98 = & F_72 ( V_136 , V_3 ) ;
switch ( V_237 ) {
case V_242 :
case V_243 :
F_196 ( V_3 ) ;
if ( V_244 )
V_244 ( V_237 , V_3 ) ;
break;
case V_245 :
case V_246 :
if ( V_244 )
V_244 ( V_237 , V_3 ) ;
F_202 ( V_3 ) ;
break;
case V_247 :
case V_248 :
F_106 ( V_98 ) ;
F_208 ( V_3 , F_205 , & V_237 , 1 ) ;
break;
case V_249 :
case V_250 :
if ( ! V_175 && V_142 ) {
V_98 -> V_143 = F_135 ( V_144 +
F_40 ( V_140 ) ) ;
F_103 ( V_98 , V_3 ) ;
}
F_208 ( V_3 , F_206 , & V_237 , 1 ) ;
break;
case V_251 :
F_209 ( V_3 ) ;
break;
}
return V_252 ;
}
static T_11 void F_210 ( void )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < V_85 ; V_45 ++ ) {
struct V_151 * V_83 = & V_86 [ V_45 ] ;
struct V_217 * V_253 = & V_83 -> V_218 ;
F_211 ( & V_253 -> V_218 ) ;
V_253 -> V_218 . V_254 = V_83 -> V_255 ;
snprintf ( V_83 -> V_255 , V_256 , L_35 , V_45 ) ;
V_253 -> V_218 . V_257 = 0644 ;
V_253 -> V_258 = F_187 ;
V_253 -> V_259 = F_188 ;
}
}
static T_11 int F_212 ( void )
{
int V_159 ;
int V_45 = 0 ;
if ( ! F_51 ( & V_7 ) )
return - V_227 ;
F_213 ( & V_235 , V_152 ) ;
F_210 () ;
V_159 = F_214 ( & V_232 ) ;
if ( V_159 )
return V_159 ;
F_105 (i) {
V_159 = F_196 ( V_45 ) ;
if ( V_159 )
return V_159 ;
}
F_215 ( & V_260 ) ;
F_216 ( & V_261 ) ;
F_217 ( & V_262 ) ;
return V_159 ;
}
static int T_11 F_218 ( char * V_214 )
{
V_72 = 1 ;
return 1 ;
}
struct V_263 * F_219 ( void )
{
static struct V_263 * V_264 ;
if ( ! V_264 )
V_264 = F_220 ( L_36 , NULL ) ;
return V_264 ;
}
static void F_221 ( void )
{
V_52 = 0 ;
F_77 ( & V_49 , 0 ) ;
F_77 ( & V_113 , 0 ) ;
F_77 ( & V_112 , 0 ) ;
F_77 ( & V_111 , 0 ) ;
}
static int F_222 ( void * V_134 , T_2 * V_265 )
{
* V_265 = V_47 ;
return 0 ;
}
static int F_223 ( void * V_134 , T_2 V_265 )
{
F_221 () ;
V_47 = V_265 ;
return 0 ;
}
static int T_11 F_224 ( void )
{
struct V_263 * V_264 , * V_266 ;
V_264 = F_219 () ;
if ( ! V_264 )
return - V_153 ;
V_266 = F_225 ( L_37 , 0444 , V_264 , NULL ,
& V_267 ) ;
if ( ! V_266 )
return - V_153 ;
return 0 ;
}
