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
F_10 ( V_1 ) ;
V_1 -> V_18 = 0 ;
F_11 () ;
for (; ; ) {
V_17 = F_12 ( V_19 . V_16 ) ;
for (; ; ) {
if ( F_13 ( V_1 ) )
return;
if ( V_17 >= V_20 ) {
F_14 ( V_21 ,
( unsigned long * ) & V_19 . V_22 ) ;
return;
}
if ( V_19 . V_17 [ V_17 ] . V_18 ) {
V_17 ++ ;
continue;
}
break;
}
F_15 () ;
V_16 = V_17 + 1 ;
if ( F_16 ( & V_19 . V_16 , V_17 , V_16 ) == V_17 )
break;
}
memcpy ( V_19 . V_17 + V_17 , V_1 , sizeof( struct V_1 ) ) ;
F_11 () ;
V_19 . V_17 [ V_17 ] . V_18 = 1 ;
F_11 () ;
V_1 -> V_18 = 1 ;
F_14 ( 0 , & V_23 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
int V_24 = 0 ;
F_18 ( V_25 L_1 ,
V_2 -> V_4 , V_2 -> V_26 , V_2 -> V_27 , V_2 -> V_28 ) ;
if ( V_2 -> V_29 ) {
F_18 ( V_25 L_2 ,
! ( V_2 -> V_26 & V_30 ) ? L_3 : L_4 ,
V_2 -> V_31 , V_2 -> V_29 ) ;
if ( V_2 -> V_31 == V_32 )
F_19 ( L_5 , V_2 -> V_29 ) ;
F_20 ( L_6 ) ;
}
F_18 ( V_25 L_7 , V_2 -> V_5 ) ;
if ( V_2 -> V_33 )
F_20 ( L_8 , V_2 -> V_33 ) ;
if ( V_2 -> V_34 )
F_20 ( L_9 , V_2 -> V_34 ) ;
F_20 ( L_6 ) ;
F_18 ( V_25 L_10 ,
V_2 -> V_6 , V_2 -> V_9 , V_2 -> time , V_2 -> V_10 , V_2 -> V_12 ) ;
V_24 = F_21 ( & V_35 , 0 , V_2 ) ;
if ( V_24 == V_36 )
return;
F_22 ( V_25 L_11 ) ;
}
static void F_23 ( void )
{
long V_37 = V_38 * V_39 ;
F_24 () ;
F_25 () ;
while ( V_37 -- > 0 )
F_26 ( 1 ) ;
if ( V_40 == 0 )
V_40 = V_41 ;
F_27 ( L_12 ) ;
}
static void F_28 ( char * V_42 , struct V_1 * V_43 , char * exp )
{
int V_44 , V_45 = 0 ;
if ( ! V_46 ) {
if ( F_29 ( & V_47 ) > 1 )
F_23 () ;
F_30 () ;
F_31 ( 1 ) ;
F_32 () ;
} else {
if ( F_29 ( & V_48 ) > 1 )
return;
}
for ( V_44 = 0 ; V_44 < V_20 ; V_44 ++ ) {
struct V_1 * V_2 = & V_19 . V_17 [ V_44 ] ;
if ( ! ( V_2 -> V_28 & V_49 ) )
continue;
if ( ! ( V_2 -> V_28 & V_50 ) ) {
F_17 ( V_2 ) ;
if ( ! V_45 )
V_45 = F_33 ( V_2 ) ;
}
}
for ( V_44 = 0 ; V_44 < V_20 ; V_44 ++ ) {
struct V_1 * V_2 = & V_19 . V_17 [ V_44 ] ;
if ( ! ( V_2 -> V_28 & V_49 ) )
continue;
if ( ! ( V_2 -> V_28 & V_50 ) )
continue;
if ( ! V_43 || memcmp ( V_2 , V_43 , sizeof( struct V_1 ) ) ) {
F_17 ( V_2 ) ;
if ( ! V_45 )
V_45 = F_33 ( V_2 ) ;
}
}
if ( V_43 ) {
F_17 ( V_43 ) ;
if ( ! V_45 )
V_45 = F_33 ( V_43 ) ;
}
if ( V_51 )
F_18 ( V_25 L_13 ) ;
if ( exp )
F_18 ( V_25 L_14 , exp ) ;
if ( ! V_46 ) {
if ( V_40 == 0 )
V_40 = V_41 ;
F_27 ( V_42 ) ;
} else
F_18 ( V_25 L_15 , V_42 ) ;
}
static int F_34 ( T_1 V_52 )
{
unsigned V_27 = F_35 ( V_53 . V_27 ) ;
if ( V_52 == V_54 )
return F_36 ( struct V_1 , V_29 ) ;
if ( V_52 == F_37 ( V_27 ) )
return F_36 ( struct V_1 , V_28 ) ;
if ( V_52 == F_38 ( V_27 ) )
return F_36 ( struct V_1 , V_33 ) ;
if ( V_52 == F_39 ( V_27 ) )
return F_36 ( struct V_1 , V_34 ) ;
if ( V_52 == V_55 )
return F_36 ( struct V_1 , V_26 ) ;
return - 1 ;
}
static T_2 F_40 ( T_1 V_52 )
{
T_2 V_56 ;
if ( F_35 ( V_53 . V_18 ) ) {
int V_57 = F_34 ( V_52 ) ;
if ( V_57 < 0 )
return 0 ;
return * ( T_2 * ) ( ( char * ) & F_41 ( V_53 ) + V_57 ) ;
}
if ( F_42 ( V_52 , & V_56 ) ) {
F_43 ( 1 , L_16 , V_52 ) ;
V_56 = 0 ;
}
return V_56 ;
}
static void F_44 ( T_1 V_52 , T_2 V_56 )
{
if ( F_35 ( V_53 . V_18 ) ) {
int V_57 = F_34 ( V_52 ) ;
if ( V_57 >= 0 )
* ( T_2 * ) ( ( char * ) & F_41 ( V_53 ) + V_57 ) = V_56 ;
return;
}
F_45 ( V_52 , V_56 ) ;
}
static int F_46 ( void )
{
struct V_58 * V_59 = & F_41 ( V_58 ) ;
return V_59 -> V_60 == V_59 -> V_61 ;
}
static int F_47 ( unsigned long * V_62 )
{
struct V_58 * V_59 ;
int V_24 = 0 ;
* V_62 = 0 ;
F_48 () ;
V_59 = & F_41 ( V_58 ) ;
if ( V_59 -> V_60 == V_59 -> V_61 )
goto V_63;
* V_62 = V_59 -> V_64 [ V_59 -> V_60 ] ;
V_59 -> V_60 = ( V_59 -> V_60 + 1 ) % V_65 ;
V_24 = 1 ;
V_63:
F_49 () ;
return V_24 ;
}
static int F_50 ( unsigned long V_62 )
{
struct V_58 * V_59 = & F_41 ( V_58 ) ;
unsigned V_16 ;
V_16 = ( V_59 -> V_61 + 1 ) % V_65 ;
if ( V_16 == V_59 -> V_60 )
return - 1 ;
V_59 -> V_64 [ V_59 -> V_61 ] = V_62 ;
F_11 () ;
V_59 -> V_61 = V_16 ;
return 0 ;
}
int F_51 ( struct V_66 * V_67 )
{
if ( V_68 )
return 0 ;
return F_52 ( V_67 , V_69 ) && F_52 ( V_67 , V_70 ) ;
}
static void F_53 ( void )
{
if ( ! F_46 () ) {
struct V_71 * V_72 = & F_41 ( V_73 ) ;
if ( ! F_54 ( V_72 ) )
F_55 ( V_72 ) ;
}
}
static inline void F_56 ( struct V_1 * V_2 , struct V_74 * V_75 )
{
if ( V_75 && ( V_2 -> V_26 & ( V_76 | V_30 ) ) ) {
V_2 -> V_29 = V_75 -> V_29 ;
V_2 -> V_31 = V_75 -> V_31 ;
} else {
V_2 -> V_29 = 0 ;
V_2 -> V_31 = 0 ;
}
if ( V_54 )
V_2 -> V_29 = F_40 ( V_54 ) ;
}
T_3 void F_57 ( struct V_74 * V_75 )
{
F_58 () ;
F_59 () ;
F_60 () ;
F_61 () ;
F_53 () ;
F_62 () ;
}
static void F_63 ( struct V_74 * V_75 )
{
if ( V_75 -> V_22 & ( V_77 | V_78 ) ) {
F_61 () ;
F_53 () ;
return;
}
#ifdef F_64
if ( ! V_79 )
return;
V_80 -> V_81 ( V_82 ) ;
F_65 () ;
#endif
}
void F_66 ( enum V_83 V_22 , T_4 * V_84 )
{
struct V_1 V_2 ;
int V_44 ;
F_67 ( V_85 ) ;
F_1 ( & V_2 ) ;
V_2 . V_26 = F_40 ( V_55 ) ;
for ( V_44 = 0 ; V_44 < V_86 ; V_44 ++ ) {
if ( ! V_87 [ V_44 ] . V_88 || ! F_68 ( V_44 , * V_84 ) )
continue;
V_2 . V_34 = 0 ;
V_2 . V_33 = 0 ;
V_2 . V_27 = V_44 ;
V_2 . V_5 = 0 ;
F_30 () ;
V_2 . V_28 = F_40 ( F_37 ( V_44 ) ) ;
if ( ! ( V_2 . V_28 & V_49 ) )
continue;
if ( ! ( V_22 & V_89 ) &&
( V_2 . V_28 & ( V_90 ? V_91 : V_50 ) ) )
continue;
if ( V_2 . V_28 & V_92 )
V_2 . V_34 = F_40 ( F_39 ( V_44 ) ) ;
if ( V_2 . V_28 & V_93 )
V_2 . V_33 = F_40 ( F_38 ( V_44 ) ) ;
if ( ! ( V_22 & V_94 ) )
V_2 . V_5 = 0 ;
if ( ! ( V_22 & V_95 ) && ! V_96 ) {
F_9 ( & V_2 ) ;
F_21 ( & V_35 , 0 , & V_2 ) ;
}
F_44 ( F_37 ( V_44 ) , 0 ) ;
}
F_69 () ;
}
static int F_70 ( struct V_1 * V_2 , char * * V_42 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_86 ; V_44 ++ ) {
V_2 -> V_28 = F_40 ( F_37 ( V_44 ) ) ;
if ( F_71 ( V_2 , V_97 , V_42 ) >= V_98 )
return 1 ;
}
return 0 ;
}
static int F_72 ( T_2 * V_99 )
{
F_73 () ;
if ( F_74 ( & V_47 ) )
F_23 () ;
if ( ! V_100 )
goto V_63;
if ( ( V_101 ) * V_99 < V_102 ) {
if ( V_97 < 1 )
F_28 ( L_17 ,
NULL , NULL ) ;
V_51 = 1 ;
return 1 ;
}
* V_99 -= V_102 ;
V_63:
F_75 () ;
return 0 ;
}
static void F_76 ( void )
{
int V_3 ;
struct V_1 * V_2 = NULL ;
int V_103 = 0 ;
char * V_42 = NULL ;
char * V_104 = NULL ;
F_77 (cpu) {
int V_105 = F_71 ( & F_78 ( V_106 , V_3 ) , V_97 ,
& V_104 ) ;
if ( V_105 > V_103 ) {
V_42 = V_104 ;
V_103 = V_105 ;
V_2 = & F_78 ( V_106 , V_3 ) ;
}
}
if ( V_2 && V_103 >= V_98 && V_97 < 3 )
F_28 ( L_18 , V_2 , V_42 ) ;
if ( V_103 <= V_107 && V_97 < 3 )
F_28 ( L_19 , NULL , NULL ) ;
F_77 (cpu)
memset ( & F_78 ( V_106 , V_3 ) , 0 , sizeof( struct V_1 ) ) ;
}
static int F_79 ( int * V_108 )
{
int V_109 ;
int V_110 = F_80 () ;
T_2 V_37 = ( T_2 ) V_100 * V_111 ;
if ( ! V_37 )
return - 1 ;
F_81 ( * V_108 , & V_112 ) ;
F_82 () ;
V_109 = F_29 ( & V_113 ) ;
while ( F_74 ( & V_113 ) != V_110 ) {
if ( F_72 ( & V_37 ) ) {
F_83 ( & V_112 , 0 ) ;
return - 1 ;
}
F_84 ( V_102 ) ;
}
F_15 () ;
if ( V_109 == 1 ) {
F_83 ( & V_114 , 1 ) ;
} else {
while ( F_74 ( & V_114 ) < V_109 ) {
if ( F_72 ( & V_37 ) ) {
F_83 ( & V_112 , 0 ) ;
return - 1 ;
}
F_84 ( V_102 ) ;
}
}
* V_108 = F_74 ( & V_112 ) ;
return V_109 ;
}
static int F_85 ( int V_109 )
{
int V_24 = - 1 ;
T_2 V_37 = ( T_2 ) V_100 * V_111 ;
if ( ! V_37 )
goto V_115;
if ( V_109 < 0 )
goto V_115;
F_86 ( & V_114 ) ;
if ( V_109 == 1 ) {
int V_110 = F_80 () ;
while ( F_74 ( & V_114 ) <= V_110 ) {
if ( F_72 ( & V_37 ) )
goto V_115;
F_84 ( V_102 ) ;
}
F_76 () ;
F_30 () ;
V_24 = 0 ;
} else {
while ( F_74 ( & V_114 ) != 0 ) {
if ( F_72 ( & V_37 ) )
goto V_115;
F_84 ( V_102 ) ;
}
return 0 ;
}
V_115:
F_83 ( & V_112 , 0 ) ;
F_83 ( & V_113 , 0 ) ;
F_30 () ;
F_83 ( & V_114 , 0 ) ;
return V_24 ;
}
static int F_87 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_28 & V_92 ) || ! ( V_2 -> V_28 & V_93 ) )
return 0 ;
if ( ( V_2 -> V_34 & 0x3f ) > V_116 )
return 0 ;
if ( ( ( V_2 -> V_34 >> 6 ) & 7 ) != V_117 )
return 0 ;
return 1 ;
}
static void F_88 ( unsigned long * V_118 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_86 ; V_44 ++ ) {
if ( F_68 ( V_44 , V_118 ) )
F_44 ( F_37 ( V_44 ) , 0 ) ;
}
}
void F_89 ( struct V_74 * V_75 , long V_119 )
{
struct V_1 V_2 , * V_43 ;
int V_44 ;
int V_120 = 0 ;
int V_105 ;
int V_109 ;
int V_108 = 0 ;
int V_121 = 0 ;
F_90 ( V_118 , V_122 ) ;
char * V_42 = L_20 ;
F_86 ( & V_123 ) ;
F_67 ( V_124 ) ;
if ( F_91 ( V_125 , L_21 , V_75 , V_119 ,
18 , V_126 ) == V_36 )
goto V_63;
if ( ! V_86 )
goto V_63;
F_1 ( & V_2 ) ;
V_2 . V_26 = F_40 ( V_55 ) ;
V_43 = & F_41 ( V_106 ) ;
* V_43 = V_2 ;
V_108 = F_70 ( & V_2 , & V_42 ) ;
F_30 () ;
if ( ! ( V_2 . V_26 & V_76 ) )
V_121 = 1 ;
V_109 = F_79 ( & V_108 ) ;
for ( V_44 = 0 ; V_44 < V_86 ; V_44 ++ ) {
F_92 ( V_44 , V_118 ) ;
if ( ! V_87 [ V_44 ] . V_88 )
continue;
V_2 . V_34 = 0 ;
V_2 . V_33 = 0 ;
V_2 . V_27 = V_44 ;
V_2 . V_28 = F_40 ( F_37 ( V_44 ) ) ;
if ( ( V_2 . V_28 & V_49 ) == 0 )
continue;
if ( ! ( V_2 . V_28 & ( V_90 ? V_91 : V_50 ) ) &&
! V_108 )
continue;
F_93 ( V_127 ) ;
V_105 = F_71 ( & V_2 , V_97 , NULL ) ;
if ( V_105 == V_107 && ! V_108 )
continue;
F_94 ( V_44 , V_118 ) ;
if ( V_105 == V_128 ) {
continue;
}
if ( V_105 == V_129 )
V_121 = 1 ;
if ( V_2 . V_28 & V_92 )
V_2 . V_34 = F_40 ( F_39 ( V_44 ) ) ;
if ( V_2 . V_28 & V_93 )
V_2 . V_33 = F_40 ( F_38 ( V_44 ) ) ;
if ( V_105 == V_130 && F_87 ( & V_2 ) )
F_50 ( V_2 . V_33 >> V_116 ) ;
F_56 ( & V_2 , V_75 ) ;
F_9 ( & V_2 ) ;
if ( V_105 > V_120 ) {
* V_43 = V_2 ;
V_120 = V_105 ;
}
}
if ( ! V_108 )
F_88 ( V_118 ) ;
if ( F_85 ( V_109 ) < 0 )
V_108 = V_120 >= V_98 ;
if ( V_108 && V_97 < 3 )
F_28 ( L_22 , V_43 , V_42 ) ;
if ( V_121 && V_97 < 3 )
F_95 ( V_131 , V_132 ) ;
F_96 ( V_133 ) ;
if ( V_120 > 0 )
F_63 ( V_75 ) ;
F_44 ( V_55 , 0 ) ;
V_63:
F_97 ( & V_123 ) ;
F_69 () ;
}
void F_98 ( void )
{
unsigned long V_62 ;
F_61 () ;
while ( F_47 ( & V_62 ) )
F_99 ( V_62 , V_134 ) ;
}
static void F_100 ( struct V_71 * V_135 )
{
F_98 () ;
}
void F_101 ( T_5 V_28 )
{
struct V_1 V_2 ;
F_1 ( & V_2 ) ;
V_2 . V_27 = V_136 ;
V_2 . V_28 = V_28 ;
F_9 ( & V_2 ) ;
}
static void F_102 ( unsigned long V_137 )
{
struct V_138 * V_99 = & F_78 ( V_139 , V_137 ) ;
int * V_140 ;
F_103 ( F_2 () != V_137 ) ;
if ( F_51 ( F_104 ( & V_141 ) ) ) {
F_66 ( V_94 ,
& F_41 ( V_142 ) ) ;
}
V_140 = & F_41 ( V_143 ) ;
if ( F_61 () )
* V_140 = F_105 ( * V_140 / 2 , V_144 / 100 ) ;
else
* V_140 = F_106 ( * V_140 * 2 , ( int ) F_107 ( V_145 * V_144 ) ) ;
V_99 -> V_146 = V_147 + * V_140 ;
F_108 ( V_99 , F_2 () ) ;
}
static void F_109 ( struct V_71 * V_72 )
{
F_110 ( V_148 , V_149 , NULL , V_150 ) ;
}
int F_61 ( void )
{
static F_111 ( V_151 , 60 * V_144 , 2 ) ;
F_112 ( V_133 ) ;
if ( F_113 ( 0 , & V_23 ) ) {
F_114 ( & V_152 ) ;
if ( V_148 [ 0 ] && ! F_54 ( & V_153 ) )
F_55 ( & V_153 ) ;
if ( F_115 ( & V_151 ) )
F_116 ( V_25 L_23 ) ;
return 1 ;
}
return 0 ;
}
static int T_6 F_117 ( void )
{
int V_44 ;
V_87 = F_118 ( V_86 * sizeof( struct V_154 ) , V_155 ) ;
if ( ! V_87 )
return - V_156 ;
for ( V_44 = 0 ; V_44 < V_86 ; V_44 ++ ) {
struct V_154 * V_84 = & V_87 [ V_44 ] ;
V_84 -> V_88 = - 1ULL ;
V_84 -> V_157 = 1 ;
}
return 0 ;
}
static int T_6 F_119 ( void )
{
unsigned V_84 ;
T_2 V_158 ;
F_8 ( V_14 , V_158 ) ;
V_84 = V_158 & V_159 ;
if ( ! V_86 )
F_120 ( V_160 L_24 , V_84 ) ;
if ( V_84 > V_122 ) {
F_120 ( V_161
L_25 ,
V_122 , V_84 ) ;
V_84 = V_122 ;
}
F_103 ( V_86 != 0 && V_84 != V_86 ) ;
V_86 = V_84 ;
if ( ! V_87 ) {
int V_162 = F_117 () ;
if ( V_162 )
return V_162 ;
}
if ( ( V_158 & V_163 ) && F_121 ( V_158 ) >= 9 )
V_54 = V_164 ;
if ( V_158 & V_165 )
V_90 = 1 ;
return 0 ;
}
static void F_122 ( void )
{
T_4 V_166 ;
T_2 V_158 ;
int V_44 ;
F_123 ( V_166 , V_122 ) ;
F_66 ( V_89 | ( ! V_167 ? V_95 : 0 ) , & V_166 ) ;
F_124 ( V_168 ) ;
F_8 ( V_14 , V_158 ) ;
if ( V_158 & V_169 )
F_125 ( V_170 , 0xffffffff , 0xffffffff ) ;
for ( V_44 = 0 ; V_44 < V_86 ; V_44 ++ ) {
struct V_154 * V_84 = & V_87 [ V_44 ] ;
if ( ! V_84 -> V_157 )
continue;
F_45 ( F_126 ( V_44 ) , V_84 -> V_88 ) ;
F_45 ( F_37 ( V_44 ) , 0 ) ;
}
}
static int T_6 F_127 ( struct V_66 * V_67 )
{
if ( V_67 -> V_8 == V_171 ) {
F_116 ( L_26 ) ;
return - V_172 ;
}
if ( V_67 -> V_8 == V_173 ) {
if ( V_67 -> V_174 == 15 && V_86 > 4 ) {
F_128 ( 10 , ( unsigned long * ) & V_87 [ 4 ] . V_88 ) ;
}
if ( V_67 -> V_174 <= 17 && V_167 < 0 ) {
V_167 = 0 ;
}
if ( V_67 -> V_174 == 6 && V_86 > 0 )
V_87 [ 0 ] . V_88 = 0 ;
}
if ( V_67 -> V_8 == V_175 ) {
if ( V_67 -> V_174 == 6 && V_67 -> V_176 < 0x1A && V_86 > 0 )
V_87 [ 0 ] . V_157 = 0 ;
if ( ( V_67 -> V_174 > 6 || ( V_67 -> V_174 == 6 && V_67 -> V_176 >= 0xe ) ) &&
V_100 < 0 )
V_100 = V_39 ;
if ( V_67 -> V_174 == 6 && V_67 -> V_176 <= 13 && V_167 < 0 )
V_167 = 0 ;
}
if ( V_100 < 0 )
V_100 = 0 ;
if ( V_167 != 0 )
V_41 = 30 ;
return 0 ;
}
static void T_6 F_129 ( struct V_66 * V_67 )
{
if ( V_67 -> V_174 != 5 )
return;
switch ( V_67 -> V_8 ) {
case V_175 :
F_130 ( V_67 ) ;
break;
case V_177 :
F_131 ( V_67 ) ;
break;
}
}
static void F_132 ( struct V_66 * V_67 )
{
switch ( V_67 -> V_8 ) {
case V_175 :
F_133 ( V_67 ) ;
break;
case V_173 :
F_134 ( V_67 ) ;
break;
default:
break;
}
}
static void F_135 ( void )
{
struct V_138 * V_99 = & F_41 ( V_139 ) ;
int * V_140 = & F_41 ( V_143 ) ;
F_136 ( V_99 , F_102 , F_2 () ) ;
if ( V_178 )
return;
* V_140 = V_145 * V_144 ;
if ( ! * V_140 )
return;
V_99 -> V_146 = F_137 ( V_147 + * V_140 ) ;
F_108 ( V_99 , F_2 () ) ;
}
static void F_138 ( struct V_74 * V_75 , long V_119 )
{
F_120 ( V_179 L_27 ,
F_2 () ) ;
}
void T_6 F_139 ( struct V_66 * V_67 )
{
if ( V_68 )
return;
F_129 ( V_67 ) ;
if ( ! F_51 ( V_67 ) )
return;
if ( F_119 () < 0 || F_127 ( V_67 ) < 0 ) {
V_68 = 1 ;
return;
}
V_180 = F_89 ;
F_122 () ;
F_132 ( V_67 ) ;
F_135 () ;
F_140 ( & F_41 ( V_73 ) , F_100 ) ;
}
static int F_141 ( struct V_181 * V_181 , struct V_182 * V_182 )
{
F_142 ( & V_183 ) ;
if ( V_184 || ( V_185 && ( V_182 -> V_186 & V_187 ) ) ) {
F_143 ( & V_183 ) ;
return - V_188 ;
}
if ( V_182 -> V_186 & V_187 )
V_184 = 1 ;
V_185 ++ ;
F_143 ( & V_183 ) ;
return F_144 ( V_181 , V_182 ) ;
}
static int F_145 ( struct V_181 * V_181 , struct V_182 * V_182 )
{
F_142 ( & V_183 ) ;
V_185 -- ;
V_184 = 0 ;
F_143 ( & V_183 ) ;
return 0 ;
}
static void F_146 ( void * V_137 )
{
unsigned long * V_189 = ( unsigned long * ) V_137 ;
F_3 ( V_189 [ F_2 () ] ) ;
}
static int F_147 ( char T_7 * * V_190 , T_8 V_191 )
{
int V_192 ;
T_2 V_193 ;
struct V_1 V_2 ;
if ( V_191 < sizeof( struct V_1 ) )
return - V_194 ;
V_192 = F_148 ( & V_2 , & V_193 ) ;
if ( V_192 <= 0 ) {
V_195 = 1 ;
return V_192 ;
}
V_192 = - V_196 ;
if ( F_149 ( * V_190 , & V_2 , sizeof( struct V_1 ) ) )
return V_192 ;
V_192 = F_150 ( V_193 ) ;
if ( V_192 ) {
V_195 = 1 ;
return V_192 ;
}
* V_190 += sizeof( struct V_1 ) ;
return 0 ;
}
static T_9 F_151 ( struct V_182 * V_197 , char T_7 * V_190 , T_8 V_191 ,
T_10 * V_198 )
{
char T_7 * V_199 = V_190 ;
unsigned long * V_189 ;
unsigned V_200 , V_16 ;
int V_44 , V_162 ;
V_189 = F_152 ( V_201 * sizeof( long ) , V_155 ) ;
if ( ! V_189 )
return - V_156 ;
F_153 ( & V_202 ) ;
if ( ! V_195 ) {
V_162 = F_147 ( & V_199 , V_191 ) ;
if ( V_162 || V_199 != V_190 )
goto V_63;
}
V_16 = F_12 ( V_19 . V_16 ) ;
V_162 = - V_194 ;
if ( * V_198 != 0 || V_191 < V_20 * sizeof( struct V_1 ) )
goto V_63;
V_162 = 0 ;
V_200 = 0 ;
do {
for ( V_44 = V_200 ; V_44 < V_16 ; V_44 ++ ) {
unsigned long V_60 = V_147 ;
while ( ! V_19 . V_17 [ V_44 ] . V_18 ) {
if ( F_154 ( V_147 , V_60 + 2 ) ) {
memset ( V_19 . V_17 + V_44 , 0 ,
sizeof( struct V_1 ) ) ;
goto V_37;
}
F_155 () ;
}
F_15 () ;
V_162 |= F_149 ( V_199 , V_19 . V_17 + V_44 ,
sizeof( struct V_1 ) ) ;
V_199 += sizeof( struct V_1 ) ;
V_37:
;
}
memset ( V_19 . V_17 + V_200 , 0 ,
( V_16 - V_200 ) * sizeof( struct V_1 ) ) ;
V_200 = V_16 ;
V_16 = F_16 ( & V_19 . V_16 , V_200 , 0 ) ;
} while ( V_16 != V_200 );
F_156 () ;
F_157 ( F_146 , V_189 , 1 ) ;
for ( V_44 = V_16 ; V_44 < V_20 ; V_44 ++ ) {
if ( V_19 . V_17 [ V_44 ] . V_18 &&
V_19 . V_17 [ V_44 ] . V_5 < V_189 [ V_19 . V_17 [ V_44 ] . V_3 ] ) {
V_162 |= F_149 ( V_199 , V_19 . V_17 + V_44 ,
sizeof( struct V_1 ) ) ;
F_15 () ;
V_199 += sizeof( struct V_1 ) ;
memset ( & V_19 . V_17 [ V_44 ] , 0 , sizeof( struct V_1 ) ) ;
}
}
if ( V_162 )
V_162 = - V_196 ;
V_63:
F_158 ( & V_202 ) ;
F_159 ( V_189 ) ;
return V_162 ? V_162 : V_199 - V_190 ;
}
static unsigned int F_160 ( struct V_182 * V_182 , T_11 * V_203 )
{
F_161 ( V_182 , & V_152 , V_203 ) ;
if ( F_162 ( V_19 . V_16 ) )
return V_204 | V_205 ;
if ( ! V_195 && F_163 () )
return V_204 | V_205 ;
return 0 ;
}
static long F_164 ( struct V_182 * V_206 , unsigned int V_207 , unsigned long V_208 )
{
int T_7 * V_209 = ( int T_7 * ) V_208 ;
if ( ! F_165 ( V_210 ) )
return - V_211 ;
switch ( V_207 ) {
case V_212 :
return F_166 ( sizeof( struct V_1 ) , V_209 ) ;
case V_213 :
return F_166 ( V_20 , V_209 ) ;
case V_214 : {
unsigned V_22 ;
do {
V_22 = V_19 . V_22 ;
} while ( F_16 ( & V_19 . V_22 , V_22 , 0 ) != V_22 );
return F_166 ( V_22 , V_209 ) ;
}
default:
return - V_215 ;
}
}
static int T_12 F_167 ( char * V_216 )
{
if ( * V_216 == 0 ) {
F_168 () ;
return 1 ;
}
if ( * V_216 == '=' )
V_216 ++ ;
if ( ! strcmp ( V_216 , L_28 ) )
V_68 = 1 ;
else if ( ! strcmp ( V_216 , L_29 ) )
V_217 = 1 ;
else if ( ! strcmp ( V_216 , L_30 ) )
V_96 = 1 ;
else if ( ! strcmp ( V_216 , L_31 ) )
V_178 = 1 ;
else if ( ! strcmp ( V_216 , L_32 ) || ! strcmp ( V_216 , L_33 ) )
V_167 = ( V_216 [ 0 ] == 'b' ) ;
else if ( isdigit ( V_216 [ 0 ] ) ) {
F_169 ( & V_216 , & V_97 ) ;
if ( * V_216 == ',' ) {
++ V_216 ;
F_169 ( & V_216 , & V_100 ) ;
}
} else {
F_120 ( V_160 L_34 ,
V_216 ) ;
return 0 ;
}
return 1 ;
}
int T_12 F_170 ( void )
{
F_171 () ;
return 0 ;
}
static int F_172 ( void )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_86 ; V_44 ++ ) {
struct V_154 * V_84 = & V_87 [ V_44 ] ;
if ( V_84 -> V_157 )
F_45 ( F_126 ( V_44 ) , 0 ) ;
}
return 0 ;
}
static int F_173 ( void )
{
return F_172 () ;
}
static void F_174 ( void )
{
F_172 () ;
}
static void F_175 ( void )
{
F_122 () ;
F_132 ( F_104 ( & V_141 ) ) ;
}
static void F_176 ( void * V_137 )
{
F_177 ( & F_41 ( V_139 ) ) ;
if ( ! F_51 ( F_104 ( & V_141 ) ) )
return;
F_122 () ;
F_135 () ;
}
static void F_178 ( void )
{
F_157 ( F_176 , NULL , 1 ) ;
}
static void F_179 ( void * V_218 )
{
if ( ! F_51 ( F_104 ( & V_141 ) ) )
return;
if ( V_218 )
F_177 ( & F_41 ( V_139 ) ) ;
F_180 () ;
}
static void F_181 ( void * V_218 )
{
if ( ! F_51 ( F_104 ( & V_141 ) ) )
return;
F_182 () ;
F_183 () ;
if ( V_218 )
F_135 () ;
}
static inline struct V_154 * F_184 ( struct V_219 * V_220 )
{
return F_185 ( V_220 , struct V_154 , V_220 ) ;
}
static T_9 F_186 ( struct V_221 * V_222 , struct V_219 * V_220 ,
char * V_199 )
{
return sprintf ( V_199 , L_35 , F_184 ( V_220 ) -> V_88 ) ;
}
static T_9 F_187 ( struct V_221 * V_222 , struct V_219 * V_220 ,
const char * V_199 , T_8 V_223 )
{
T_2 V_224 ;
if ( F_188 ( V_199 , 0 , & V_224 ) < 0 )
return - V_194 ;
F_184 ( V_220 ) -> V_88 = V_224 ;
F_178 () ;
return V_223 ;
}
static T_9
F_189 ( struct V_221 * V_222 , struct V_219 * V_220 , char * V_199 )
{
strcpy ( V_199 , V_148 ) ;
strcat ( V_199 , L_6 ) ;
return strlen ( V_148 ) + 1 ;
}
static T_9 F_190 ( struct V_221 * V_222 , struct V_219 * V_220 ,
const char * V_199 , T_8 V_225 )
{
char * V_209 ;
strncpy ( V_148 , V_199 , sizeof( V_148 ) ) ;
V_148 [ sizeof( V_148 ) - 1 ] = 0 ;
V_209 = strchr ( V_148 , '\n' ) ;
if ( V_209 )
* V_209 = 0 ;
return strlen ( V_148 ) + ! ! V_209 ;
}
static T_9 F_191 ( struct V_221 * V_222 ,
struct V_219 * V_220 ,
const char * V_199 , T_8 V_223 )
{
T_2 V_224 ;
if ( F_188 ( V_199 , 0 , & V_224 ) < 0 )
return - V_194 ;
if ( V_178 ^ ! ! V_224 ) {
if ( V_224 ) {
F_157 ( F_179 , ( void * ) 1 , 1 ) ;
V_178 = 1 ;
} else {
V_178 = 0 ;
F_157 ( F_181 , ( void * ) 1 , 1 ) ;
}
}
return V_223 ;
}
static T_9 F_192 ( struct V_221 * V_222 ,
struct V_219 * V_220 ,
const char * V_199 , T_8 V_223 )
{
T_2 V_224 ;
if ( F_188 ( V_199 , 0 , & V_224 ) < 0 )
return - V_194 ;
if ( V_217 ^ ! ! V_224 ) {
if ( V_224 ) {
F_157 ( F_179 , NULL , 1 ) ;
V_217 = 1 ;
} else {
V_217 = 0 ;
F_157 ( F_181 , NULL , 1 ) ;
}
}
return V_223 ;
}
static T_9 F_193 ( struct V_221 * V_222 ,
struct V_219 * V_220 ,
const char * V_199 , T_8 V_223 )
{
T_9 V_24 = F_194 ( V_222 , V_220 , V_199 , V_223 ) ;
F_178 () ;
return V_24 ;
}
static T_6 int F_195 ( unsigned int V_3 )
{
int V_162 ;
int V_44 , V_226 ;
if ( ! F_51 ( & V_7 ) )
return - V_227 ;
memset ( & F_78 ( V_228 , V_3 ) . V_229 , 0 , sizeof( struct V_230 ) ) ;
F_78 ( V_228 , V_3 ) . V_231 = V_3 ;
F_78 ( V_228 , V_3 ) . V_232 = & V_233 ;
V_162 = F_196 ( & F_78 ( V_228 , V_3 ) ) ;
if ( V_162 )
return V_162 ;
for ( V_44 = 0 ; V_234 [ V_44 ] ; V_44 ++ ) {
V_162 = F_197 ( & F_78 ( V_228 , V_3 ) , V_234 [ V_44 ] ) ;
if ( V_162 )
goto error;
}
for ( V_226 = 0 ; V_226 < V_86 ; V_226 ++ ) {
V_162 = F_197 ( & F_78 ( V_228 , V_3 ) ,
& V_87 [ V_226 ] . V_220 ) ;
if ( V_162 )
goto V_235;
}
F_198 ( V_3 , V_236 ) ;
return 0 ;
V_235:
while ( -- V_226 >= 0 )
F_199 ( & F_78 ( V_228 , V_3 ) , & V_87 [ V_226 ] . V_220 ) ;
error:
while ( -- V_44 >= 0 )
F_199 ( & F_78 ( V_228 , V_3 ) , V_234 [ V_44 ] ) ;
F_200 ( & F_78 ( V_228 , V_3 ) ) ;
return V_162 ;
}
static T_6 void F_201 ( unsigned int V_3 )
{
int V_44 ;
if ( ! F_202 ( V_3 , V_236 ) )
return;
for ( V_44 = 0 ; V_234 [ V_44 ] ; V_44 ++ )
F_199 ( & F_78 ( V_228 , V_3 ) , V_234 [ V_44 ] ) ;
for ( V_44 = 0 ; V_44 < V_86 ; V_44 ++ )
F_199 ( & F_78 ( V_228 , V_3 ) , & V_87 [ V_44 ] . V_220 ) ;
F_200 ( & F_78 ( V_228 , V_3 ) ) ;
F_203 ( V_3 , V_236 ) ;
}
static void T_6 F_204 ( void * V_237 )
{
unsigned long V_238 = * ( unsigned long * ) V_237 ;
int V_44 ;
if ( ! F_51 ( F_104 ( & V_141 ) ) )
return;
if ( ! ( V_238 & V_239 ) )
F_180 () ;
for ( V_44 = 0 ; V_44 < V_86 ; V_44 ++ ) {
struct V_154 * V_84 = & V_87 [ V_44 ] ;
if ( V_84 -> V_157 )
F_45 ( F_126 ( V_44 ) , 0 ) ;
}
}
static void T_6 F_205 ( void * V_237 )
{
unsigned long V_238 = * ( unsigned long * ) V_237 ;
int V_44 ;
if ( ! F_51 ( F_104 ( & V_141 ) ) )
return;
if ( ! ( V_238 & V_239 ) )
F_182 () ;
for ( V_44 = 0 ; V_44 < V_86 ; V_44 ++ ) {
struct V_154 * V_84 = & V_87 [ V_44 ] ;
if ( V_84 -> V_157 )
F_45 ( F_126 ( V_44 ) , V_84 -> V_88 ) ;
}
}
static int T_6
F_206 ( struct V_240 * V_241 , unsigned long V_238 , void * V_242 )
{
unsigned int V_3 = ( unsigned long ) V_242 ;
struct V_138 * V_99 = & F_78 ( V_139 , V_3 ) ;
switch ( V_238 ) {
case V_243 :
case V_244 :
F_195 ( V_3 ) ;
if ( V_245 )
V_245 ( V_238 , V_3 ) ;
break;
case V_246 :
case V_247 :
if ( V_245 )
V_245 ( V_238 , V_3 ) ;
F_201 ( V_3 ) ;
break;
case V_248 :
case V_249 :
F_177 ( V_99 ) ;
F_207 ( V_3 , F_204 , & V_238 , 1 ) ;
break;
case V_250 :
case V_251 :
if ( ! V_178 && V_145 ) {
V_99 -> V_146 = F_137 ( V_147 +
F_41 ( V_143 ) ) ;
F_108 ( V_99 , V_3 ) ;
}
F_207 ( V_3 , F_205 , & V_238 , 1 ) ;
break;
case V_252 :
F_208 ( V_3 ) ;
break;
}
return V_253 ;
}
static T_12 void F_209 ( void )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_86 ; V_44 ++ ) {
struct V_154 * V_84 = & V_87 [ V_44 ] ;
struct V_219 * V_254 = & V_84 -> V_220 ;
F_210 ( & V_254 -> V_220 ) ;
V_254 -> V_220 . V_255 = V_84 -> V_256 ;
snprintf ( V_84 -> V_256 , V_257 , L_36 , V_44 ) ;
V_254 -> V_220 . V_258 = 0644 ;
V_254 -> V_259 = F_186 ;
V_254 -> V_260 = F_187 ;
}
}
static T_12 int F_211 ( void )
{
int V_162 ;
int V_44 = 0 ;
if ( ! F_51 ( & V_7 ) )
return - V_227 ;
F_212 ( & V_236 , V_155 ) ;
F_209 () ;
V_162 = F_213 ( & V_233 ) ;
if ( V_162 )
return V_162 ;
F_214 (i) {
V_162 = F_195 ( V_44 ) ;
if ( V_162 )
return V_162 ;
}
F_215 ( & V_261 ) ;
F_216 ( & V_262 ) ;
F_217 ( & V_263 ) ;
return V_162 ;
}
static int T_12 F_218 ( char * V_216 )
{
V_68 = 1 ;
return 1 ;
}
struct V_264 * F_219 ( void )
{
static struct V_264 * V_265 ;
if ( ! V_265 )
V_265 = F_220 ( L_37 , NULL ) ;
return V_265 ;
}
static void F_221 ( void )
{
V_51 = 0 ;
F_83 ( & V_48 , 0 ) ;
F_83 ( & V_114 , 0 ) ;
F_83 ( & V_113 , 0 ) ;
F_83 ( & V_112 , 0 ) ;
}
static int F_222 ( void * V_137 , T_2 * V_266 )
{
* V_266 = V_46 ;
return 0 ;
}
static int F_223 ( void * V_137 , T_2 V_266 )
{
F_221 () ;
V_46 = V_266 ;
return 0 ;
}
static int T_12 F_224 ( void )
{
struct V_264 * V_265 , * V_267 ;
V_265 = F_219 () ;
if ( ! V_265 )
return - V_156 ;
V_267 = F_225 ( L_38 , 0444 , V_265 , NULL ,
& V_268 ) ;
if ( ! V_267 )
return - V_156 ;
return 0 ;
}
