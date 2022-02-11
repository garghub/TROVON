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
static inline void F_46 ( struct V_1 * V_2 , struct V_58 * V_59 )
{
F_1 ( V_2 ) ;
V_2 -> V_26 = F_40 ( V_55 ) ;
if ( V_59 ) {
if ( V_2 -> V_26 & ( V_60 | V_30 ) ) {
V_2 -> V_29 = V_59 -> V_29 ;
V_2 -> V_31 = V_59 -> V_31 ;
}
if ( V_54 )
V_2 -> V_29 = F_40 ( V_54 ) ;
}
}
static int F_47 ( void )
{
struct V_61 * V_62 = & F_41 ( V_61 ) ;
return V_62 -> V_63 == V_62 -> V_64 ;
}
static int F_48 ( unsigned long * V_65 )
{
struct V_61 * V_62 ;
int V_24 = 0 ;
* V_65 = 0 ;
F_49 () ;
V_62 = & F_41 ( V_61 ) ;
if ( V_62 -> V_63 == V_62 -> V_64 )
goto V_66;
* V_65 = V_62 -> V_67 [ V_62 -> V_63 ] ;
V_62 -> V_63 = ( V_62 -> V_63 + 1 ) % V_68 ;
V_24 = 1 ;
V_66:
F_50 () ;
return V_24 ;
}
static int F_51 ( unsigned long V_65 )
{
struct V_61 * V_62 = & F_41 ( V_61 ) ;
unsigned V_16 ;
V_16 = ( V_62 -> V_64 + 1 ) % V_68 ;
if ( V_16 == V_62 -> V_63 )
return - 1 ;
V_62 -> V_67 [ V_62 -> V_64 ] = V_65 ;
F_11 () ;
V_62 -> V_64 = V_16 ;
return 0 ;
}
int F_52 ( struct V_69 * V_70 )
{
if ( V_71 )
return 0 ;
return F_53 ( V_70 , V_72 ) && F_53 ( V_70 , V_73 ) ;
}
static void F_54 ( void )
{
if ( ! F_47 () ) {
struct V_74 * V_75 = & F_41 ( V_76 ) ;
if ( ! F_55 ( V_75 ) )
F_56 ( V_75 ) ;
}
}
static void F_57 ( struct V_77 * V_17 )
{
F_58 () ;
F_54 () ;
}
static void F_59 ( struct V_58 * V_59 )
{
if ( V_59 -> V_22 & ( V_78 | V_79 ) ) {
F_58 () ;
F_54 () ;
return;
}
F_60 ( & F_41 ( V_80 ) ) ;
}
void F_61 ( enum V_81 V_22 , T_3 * V_82 )
{
struct V_1 V_2 ;
int V_44 ;
F_62 ( V_83 ) ;
F_46 ( & V_2 , NULL ) ;
for ( V_44 = 0 ; V_44 < V_84 ; V_44 ++ ) {
if ( ! V_85 [ V_44 ] . V_86 || ! F_63 ( V_44 , * V_82 ) )
continue;
V_2 . V_34 = 0 ;
V_2 . V_33 = 0 ;
V_2 . V_27 = V_44 ;
V_2 . V_5 = 0 ;
F_30 () ;
V_2 . V_28 = F_40 ( F_37 ( V_44 ) ) ;
if ( ! ( V_2 . V_28 & V_49 ) )
continue;
if ( ! ( V_22 & V_87 ) &&
( V_2 . V_28 & ( V_88 ? V_89 : V_50 ) ) )
continue;
if ( V_2 . V_28 & V_90 )
V_2 . V_34 = F_40 ( F_39 ( V_44 ) ) ;
if ( V_2 . V_28 & V_91 )
V_2 . V_33 = F_40 ( F_38 ( V_44 ) ) ;
if ( ! ( V_22 & V_92 ) )
V_2 . V_5 = 0 ;
if ( ! ( V_22 & V_93 ) && ! V_94 ) {
F_9 ( & V_2 ) ;
F_21 ( & V_35 , 0 , & V_2 ) ;
}
F_44 ( F_37 ( V_44 ) , 0 ) ;
}
F_64 () ;
}
static int F_65 ( struct V_1 * V_2 , char * * V_42 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_84 ; V_44 ++ ) {
V_2 -> V_28 = F_40 ( F_37 ( V_44 ) ) ;
if ( F_66 ( V_2 , V_95 , V_42 ) >= V_96 )
return 1 ;
}
return 0 ;
}
static int F_67 ( T_2 * V_97 )
{
F_68 () ;
if ( F_69 ( & V_47 ) )
F_23 () ;
if ( ! V_98 )
goto V_66;
if ( ( V_99 ) * V_97 < V_100 ) {
if ( V_95 < 1 )
F_28 ( L_17 ,
NULL , NULL ) ;
V_51 = 1 ;
return 1 ;
}
* V_97 -= V_100 ;
V_66:
F_70 () ;
return 0 ;
}
static void F_71 ( void )
{
int V_3 ;
struct V_1 * V_2 = NULL ;
int V_101 = 0 ;
char * V_42 = NULL ;
char * V_102 = NULL ;
F_72 (cpu) {
int V_103 = F_66 ( & F_73 ( V_104 , V_3 ) , V_95 ,
& V_102 ) ;
if ( V_103 > V_101 ) {
V_42 = V_102 ;
V_101 = V_103 ;
V_2 = & F_73 ( V_104 , V_3 ) ;
}
}
if ( V_2 && V_101 >= V_96 && V_95 < 3 )
F_28 ( L_18 , V_2 , V_42 ) ;
if ( V_101 <= V_105 && V_95 < 3 )
F_28 ( L_19 , NULL , NULL ) ;
F_72 (cpu)
memset ( & F_73 ( V_104 , V_3 ) , 0 , sizeof( struct V_1 ) ) ;
}
static int F_74 ( int * V_106 )
{
int V_107 ;
int V_108 = F_75 () ;
T_2 V_37 = ( T_2 ) V_98 * V_109 ;
if ( ! V_37 )
return - 1 ;
F_76 ( * V_106 , & V_110 ) ;
F_77 () ;
V_107 = F_29 ( & V_111 ) ;
while ( F_69 ( & V_111 ) != V_108 ) {
if ( F_67 ( & V_37 ) ) {
F_78 ( & V_110 , 0 ) ;
return - 1 ;
}
F_79 ( V_100 ) ;
}
F_15 () ;
if ( V_107 == 1 ) {
F_78 ( & V_112 , 1 ) ;
} else {
while ( F_69 ( & V_112 ) < V_107 ) {
if ( F_67 ( & V_37 ) ) {
F_78 ( & V_110 , 0 ) ;
return - 1 ;
}
F_79 ( V_100 ) ;
}
}
* V_106 = F_69 ( & V_110 ) ;
return V_107 ;
}
static int F_80 ( int V_107 )
{
int V_24 = - 1 ;
T_2 V_37 = ( T_2 ) V_98 * V_109 ;
if ( ! V_37 )
goto V_113;
if ( V_107 < 0 )
goto V_113;
F_81 ( & V_112 ) ;
if ( V_107 == 1 ) {
int V_108 = F_75 () ;
while ( F_69 ( & V_112 ) <= V_108 ) {
if ( F_67 ( & V_37 ) )
goto V_113;
F_79 ( V_100 ) ;
}
F_71 () ;
F_30 () ;
V_24 = 0 ;
} else {
while ( F_69 ( & V_112 ) != 0 ) {
if ( F_67 ( & V_37 ) )
goto V_113;
F_79 ( V_100 ) ;
}
return 0 ;
}
V_113:
F_78 ( & V_110 , 0 ) ;
F_78 ( & V_111 , 0 ) ;
F_30 () ;
F_78 ( & V_112 , 0 ) ;
return V_24 ;
}
static int F_82 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_28 & V_90 ) || ! ( V_2 -> V_28 & V_91 ) )
return 0 ;
if ( F_83 ( V_2 -> V_34 ) > V_114 )
return 0 ;
if ( F_84 ( V_2 -> V_34 ) != V_115 )
return 0 ;
return 1 ;
}
static void F_85 ( unsigned long * V_116 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_84 ; V_44 ++ ) {
if ( F_63 ( V_44 , V_116 ) )
F_44 ( F_37 ( V_44 ) , 0 ) ;
}
}
void F_86 ( struct V_58 * V_59 , long V_117 )
{
struct V_1 V_2 , * V_43 ;
int V_44 ;
int V_118 = 0 ;
int V_103 ;
int V_107 ;
int V_106 = 0 ;
int V_119 = 0 ;
F_87 ( V_116 , V_120 ) ;
char * V_42 = L_20 ;
F_81 ( & V_121 ) ;
F_62 ( V_122 ) ;
if ( F_88 ( V_123 , L_21 , V_59 , V_117 ,
18 , V_124 ) == V_36 )
goto V_66;
if ( ! V_84 )
goto V_66;
F_46 ( & V_2 , V_59 ) ;
V_43 = & F_41 ( V_104 ) ;
* V_43 = V_2 ;
V_106 = F_65 ( & V_2 , & V_42 ) ;
F_30 () ;
if ( ! ( V_2 . V_26 & V_60 ) )
V_119 = 1 ;
V_107 = F_74 ( & V_106 ) ;
for ( V_44 = 0 ; V_44 < V_84 ; V_44 ++ ) {
F_89 ( V_44 , V_116 ) ;
if ( ! V_85 [ V_44 ] . V_86 )
continue;
V_2 . V_34 = 0 ;
V_2 . V_33 = 0 ;
V_2 . V_27 = V_44 ;
V_2 . V_28 = F_40 ( F_37 ( V_44 ) ) ;
if ( ( V_2 . V_28 & V_49 ) == 0 )
continue;
if ( ! ( V_2 . V_28 & ( V_88 ? V_89 : V_50 ) ) &&
! V_106 )
continue;
F_90 ( V_125 ) ;
V_103 = F_66 ( & V_2 , V_95 , NULL ) ;
if ( V_103 == V_105 && ! V_106 )
continue;
F_91 ( V_44 , V_116 ) ;
if ( V_103 == V_126 ) {
continue;
}
if ( V_103 == V_127 )
V_119 = 1 ;
if ( V_2 . V_28 & V_90 )
V_2 . V_34 = F_40 ( F_39 ( V_44 ) ) ;
if ( V_2 . V_28 & V_91 )
V_2 . V_33 = F_40 ( F_38 ( V_44 ) ) ;
if ( V_103 == V_128 && F_82 ( & V_2 ) )
F_51 ( V_2 . V_33 >> V_114 ) ;
F_9 ( & V_2 ) ;
if ( V_103 > V_118 ) {
* V_43 = V_2 ;
V_118 = V_103 ;
}
}
if ( ! V_106 )
F_85 ( V_116 ) ;
if ( F_80 ( V_107 ) < 0 )
V_106 = V_118 >= V_96 ;
if ( V_106 && V_95 < 3 )
F_28 ( L_22 , V_43 , V_42 ) ;
if ( V_119 && V_95 < 3 )
F_92 ( V_129 , V_130 ) ;
F_93 ( V_131 ) ;
if ( V_118 > 0 )
F_59 ( V_59 ) ;
F_44 ( V_55 , 0 ) ;
V_66:
F_94 ( & V_121 ) ;
F_64 () ;
}
void F_95 ( void )
{
unsigned long V_65 ;
F_58 () ;
while ( F_48 ( & V_65 ) )
F_96 ( V_65 , V_132 ) ;
}
static void F_97 ( struct V_74 * V_133 )
{
F_95 () ;
}
void F_98 ( T_4 V_28 )
{
struct V_1 V_2 ;
F_1 ( & V_2 ) ;
V_2 . V_27 = V_134 ;
V_2 . V_28 = V_28 ;
F_9 ( & V_2 ) ;
}
static void F_99 ( unsigned long V_135 )
{
struct V_136 * V_97 = & F_73 ( V_137 , V_135 ) ;
int * V_138 ;
F_100 ( F_2 () != V_135 ) ;
if ( F_52 ( F_101 ( & V_139 ) ) ) {
F_61 ( V_92 ,
& F_41 ( V_140 ) ) ;
}
V_138 = & F_41 ( V_141 ) ;
if ( F_58 () )
* V_138 = F_102 ( * V_138 / 2 , V_142 / 100 ) ;
else
* V_138 = F_103 ( * V_138 * 2 , ( int ) F_104 ( V_143 * V_142 ) ) ;
V_97 -> V_144 = V_145 + * V_138 ;
F_105 ( V_97 , F_2 () ) ;
}
static void F_106 ( struct V_74 * V_75 )
{
F_107 ( V_146 , V_147 , NULL , V_148 ) ;
}
int F_58 ( void )
{
static F_108 ( V_149 , 60 * V_142 , 2 ) ;
F_109 ( V_131 ) ;
if ( F_110 ( 0 , & V_23 ) ) {
F_111 ( & V_150 ) ;
if ( V_146 [ 0 ] && ! F_55 ( & V_151 ) )
F_56 ( & V_151 ) ;
if ( F_112 ( & V_149 ) )
F_113 ( V_25 L_23 ) ;
return 1 ;
}
return 0 ;
}
static int T_5 F_114 ( void )
{
int V_44 ;
V_85 = F_115 ( V_84 * sizeof( struct V_152 ) , V_153 ) ;
if ( ! V_85 )
return - V_154 ;
for ( V_44 = 0 ; V_44 < V_84 ; V_44 ++ ) {
struct V_152 * V_82 = & V_85 [ V_44 ] ;
V_82 -> V_86 = - 1ULL ;
V_82 -> V_155 = 1 ;
}
return 0 ;
}
static int T_5 F_116 ( void )
{
unsigned V_82 ;
T_2 V_156 ;
F_8 ( V_14 , V_156 ) ;
V_82 = V_156 & V_157 ;
if ( ! V_84 )
F_117 ( V_158 L_24 , V_82 ) ;
if ( V_82 > V_120 ) {
F_117 ( V_159
L_25 ,
V_120 , V_82 ) ;
V_82 = V_120 ;
}
F_100 ( V_84 != 0 && V_82 != V_84 ) ;
V_84 = V_82 ;
if ( ! V_85 ) {
int V_160 = F_114 () ;
if ( V_160 )
return V_160 ;
}
if ( ( V_156 & V_161 ) && F_118 ( V_156 ) >= 9 )
V_54 = V_162 ;
if ( V_156 & V_163 )
V_88 = 1 ;
return 0 ;
}
static void F_119 ( void )
{
T_3 V_164 ;
T_2 V_156 ;
int V_44 ;
F_120 ( V_164 , V_120 ) ;
F_61 ( V_87 | ( ! V_165 ? V_93 : 0 ) , & V_164 ) ;
F_121 ( V_166 ) ;
F_8 ( V_14 , V_156 ) ;
if ( V_156 & V_167 )
F_122 ( V_168 , 0xffffffff , 0xffffffff ) ;
for ( V_44 = 0 ; V_44 < V_84 ; V_44 ++ ) {
struct V_152 * V_82 = & V_85 [ V_44 ] ;
if ( ! V_82 -> V_155 )
continue;
F_45 ( F_123 ( V_44 ) , V_82 -> V_86 ) ;
F_45 ( F_37 ( V_44 ) , 0 ) ;
}
}
static int T_5 F_124 ( struct V_69 * V_70 )
{
if ( V_70 -> V_8 == V_169 ) {
F_113 ( L_26 ) ;
return - V_170 ;
}
if ( V_70 -> V_8 == V_171 ) {
if ( V_70 -> V_172 == 15 && V_84 > 4 ) {
F_125 ( 10 , ( unsigned long * ) & V_85 [ 4 ] . V_86 ) ;
}
if ( V_70 -> V_172 <= 17 && V_165 < 0 ) {
V_165 = 0 ;
}
if ( V_70 -> V_172 == 6 && V_84 > 0 )
V_85 [ 0 ] . V_86 = 0 ;
}
if ( V_70 -> V_8 == V_173 ) {
if ( V_70 -> V_172 == 6 && V_70 -> V_174 < 0x1A && V_84 > 0 )
V_85 [ 0 ] . V_155 = 0 ;
if ( ( V_70 -> V_172 > 6 || ( V_70 -> V_172 == 6 && V_70 -> V_174 >= 0xe ) ) &&
V_98 < 0 )
V_98 = V_39 ;
if ( V_70 -> V_172 == 6 && V_70 -> V_174 <= 13 && V_165 < 0 )
V_165 = 0 ;
}
if ( V_98 < 0 )
V_98 = 0 ;
if ( V_165 != 0 )
V_41 = 30 ;
return 0 ;
}
static int T_5 F_126 ( struct V_69 * V_70 )
{
if ( V_70 -> V_172 != 5 )
return 0 ;
switch ( V_70 -> V_8 ) {
case V_173 :
F_127 ( V_70 ) ;
return 1 ;
break;
case V_175 :
F_128 ( V_70 ) ;
return 1 ;
break;
}
return 0 ;
}
static void F_129 ( struct V_69 * V_70 )
{
switch ( V_70 -> V_8 ) {
case V_173 :
F_130 ( V_70 ) ;
break;
case V_171 :
F_131 ( V_70 ) ;
break;
default:
break;
}
}
static void F_132 ( void )
{
struct V_136 * V_97 = & F_41 ( V_137 ) ;
int * V_138 = & F_41 ( V_141 ) ;
F_133 ( V_97 , F_99 , F_2 () ) ;
if ( V_176 )
return;
* V_138 = V_143 * V_142 ;
if ( ! * V_138 )
return;
V_97 -> V_144 = F_134 ( V_145 + * V_138 ) ;
F_105 ( V_97 , F_2 () ) ;
}
static void F_135 ( struct V_58 * V_59 , long V_117 )
{
F_117 ( V_177 L_27 ,
F_2 () ) ;
}
void T_5 F_136 ( struct V_69 * V_70 )
{
if ( V_71 )
return;
if ( F_126 ( V_70 ) )
return;
if ( ! F_52 ( V_70 ) )
return;
if ( F_116 () < 0 || F_124 ( V_70 ) < 0 ) {
V_71 = 1 ;
return;
}
V_178 = F_86 ;
F_119 () ;
F_129 ( V_70 ) ;
F_132 () ;
F_137 ( & F_41 ( V_76 ) , F_97 ) ;
F_138 ( & F_41 ( V_80 ) , & F_57 ) ;
}
static int F_139 ( struct V_179 * V_179 , struct V_180 * V_180 )
{
F_140 ( & V_181 ) ;
if ( V_182 ||
( V_183 && ( V_180 -> V_184 & V_185 ) ) ) {
F_141 ( & V_181 ) ;
return - V_186 ;
}
if ( V_180 -> V_184 & V_185 )
V_182 = 1 ;
V_183 ++ ;
F_141 ( & V_181 ) ;
return F_142 ( V_179 , V_180 ) ;
}
static int F_143 ( struct V_179 * V_179 , struct V_180 * V_180 )
{
F_140 ( & V_181 ) ;
V_183 -- ;
V_182 = 0 ;
F_141 ( & V_181 ) ;
return 0 ;
}
static void F_144 ( void * V_135 )
{
unsigned long * V_187 = ( unsigned long * ) V_135 ;
F_3 ( V_187 [ F_2 () ] ) ;
}
static int F_145 ( char T_6 * * V_188 , T_7 V_189 )
{
int V_190 ;
T_2 V_191 ;
struct V_1 V_2 ;
if ( V_189 < sizeof( struct V_1 ) )
return - V_192 ;
V_190 = F_146 ( & V_2 , & V_191 ) ;
if ( V_190 <= 0 ) {
V_193 = 1 ;
return V_190 ;
}
V_190 = - V_194 ;
if ( F_147 ( * V_188 , & V_2 , sizeof( struct V_1 ) ) )
return V_190 ;
V_190 = F_148 ( V_191 ) ;
if ( V_190 ) {
V_193 = 1 ;
return V_190 ;
}
* V_188 += sizeof( struct V_1 ) ;
return 0 ;
}
static T_8 F_149 ( struct V_180 * V_195 , char T_6 * V_188 ,
T_7 V_189 , T_9 * V_196 )
{
char T_6 * V_197 = V_188 ;
unsigned long * V_187 ;
unsigned V_198 , V_16 ;
int V_44 , V_160 ;
V_187 = F_150 ( V_199 * sizeof( long ) , V_153 ) ;
if ( ! V_187 )
return - V_154 ;
F_151 ( & V_200 ) ;
if ( ! V_193 ) {
V_160 = F_145 ( & V_197 , V_189 ) ;
if ( V_160 || V_197 != V_188 )
goto V_66;
}
V_16 = F_12 ( V_19 . V_16 ) ;
V_160 = - V_192 ;
if ( * V_196 != 0 || V_189 < V_20 * sizeof( struct V_1 ) )
goto V_66;
V_160 = 0 ;
V_198 = 0 ;
do {
for ( V_44 = V_198 ; V_44 < V_16 ; V_44 ++ ) {
unsigned long V_63 = V_145 ;
struct V_1 * V_2 = & V_19 . V_17 [ V_44 ] ;
while ( ! V_2 -> V_18 ) {
if ( F_152 ( V_145 , V_63 + 2 ) ) {
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
goto V_37;
}
F_153 () ;
}
F_15 () ;
V_160 |= F_147 ( V_197 , V_2 , sizeof( * V_2 ) ) ;
V_197 += sizeof( * V_2 ) ;
V_37:
;
}
memset ( V_19 . V_17 + V_198 , 0 ,
( V_16 - V_198 ) * sizeof( struct V_1 ) ) ;
V_198 = V_16 ;
V_16 = F_16 ( & V_19 . V_16 , V_198 , 0 ) ;
} while ( V_16 != V_198 );
F_154 () ;
F_155 ( F_144 , V_187 , 1 ) ;
for ( V_44 = V_16 ; V_44 < V_20 ; V_44 ++ ) {
struct V_1 * V_2 = & V_19 . V_17 [ V_44 ] ;
if ( V_2 -> V_18 && V_2 -> V_5 < V_187 [ V_2 -> V_3 ] ) {
V_160 |= F_147 ( V_197 , V_2 , sizeof( * V_2 ) ) ;
F_15 () ;
V_197 += sizeof( * V_2 ) ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
}
}
if ( V_160 )
V_160 = - V_194 ;
V_66:
F_156 ( & V_200 ) ;
F_157 ( V_187 ) ;
return V_160 ? V_160 : V_197 - V_188 ;
}
static unsigned int F_158 ( struct V_180 * V_180 , T_10 * V_201 )
{
F_159 ( V_180 , & V_150 , V_201 ) ;
if ( F_160 ( V_19 . V_16 ) )
return V_202 | V_203 ;
if ( ! V_193 && F_161 () )
return V_202 | V_203 ;
return 0 ;
}
static long F_162 ( struct V_180 * V_204 , unsigned int V_205 ,
unsigned long V_206 )
{
int T_6 * V_207 = ( int T_6 * ) V_206 ;
if ( ! F_163 ( V_208 ) )
return - V_209 ;
switch ( V_205 ) {
case V_210 :
return F_164 ( sizeof( struct V_1 ) , V_207 ) ;
case V_211 :
return F_164 ( V_20 , V_207 ) ;
case V_212 : {
unsigned V_22 ;
do {
V_22 = V_19 . V_22 ;
} while ( F_16 ( & V_19 . V_22 , V_22 , 0 ) != V_22 );
return F_164 ( V_22 , V_207 ) ;
}
default:
return - V_213 ;
}
}
static int T_11 F_165 ( char * V_214 )
{
if ( * V_214 == 0 ) {
F_166 () ;
return 1 ;
}
if ( * V_214 == '=' )
V_214 ++ ;
if ( ! strcmp ( V_214 , L_28 ) )
V_71 = 1 ;
else if ( ! strcmp ( V_214 , L_29 ) )
V_215 = 1 ;
else if ( ! strcmp ( V_214 , L_30 ) )
V_94 = 1 ;
else if ( ! strcmp ( V_214 , L_31 ) )
V_176 = 1 ;
else if ( ! strcmp ( V_214 , L_32 ) || ! strcmp ( V_214 , L_33 ) )
V_165 = ( V_214 [ 0 ] == 'b' ) ;
else if ( isdigit ( V_214 [ 0 ] ) ) {
F_167 ( & V_214 , & V_95 ) ;
if ( * V_214 == ',' ) {
++ V_214 ;
F_167 ( & V_214 , & V_98 ) ;
}
} else {
F_117 ( V_158 L_34 ,
V_214 ) ;
return 0 ;
}
return 1 ;
}
int T_11 F_168 ( void )
{
F_169 () ;
return 0 ;
}
static int F_170 ( void )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_84 ; V_44 ++ ) {
struct V_152 * V_82 = & V_85 [ V_44 ] ;
if ( V_82 -> V_155 )
F_45 ( F_123 ( V_44 ) , 0 ) ;
}
return 0 ;
}
static int F_171 ( void )
{
return F_170 () ;
}
static void F_172 ( void )
{
F_170 () ;
}
static void F_173 ( void )
{
F_119 () ;
F_129 ( F_101 ( & V_139 ) ) ;
}
static void F_174 ( void * V_135 )
{
F_175 ( & F_41 ( V_137 ) ) ;
if ( ! F_52 ( F_101 ( & V_139 ) ) )
return;
F_119 () ;
F_132 () ;
}
static void F_176 ( void )
{
F_155 ( F_174 , NULL , 1 ) ;
}
static void F_177 ( void * V_216 )
{
if ( ! F_52 ( F_101 ( & V_139 ) ) )
return;
if ( V_216 )
F_175 ( & F_41 ( V_137 ) ) ;
F_178 () ;
}
static void F_179 ( void * V_216 )
{
if ( ! F_52 ( F_101 ( & V_139 ) ) )
return;
F_180 () ;
F_181 () ;
if ( V_216 )
F_132 () ;
}
static inline struct V_152 * F_182 ( struct V_217 * V_218 )
{
return F_183 ( V_218 , struct V_152 , V_218 ) ;
}
static T_8 F_184 ( struct V_219 * V_220 , struct V_217 * V_218 ,
char * V_197 )
{
return sprintf ( V_197 , L_35 , F_182 ( V_218 ) -> V_86 ) ;
}
static T_8 F_185 ( struct V_219 * V_220 , struct V_217 * V_218 ,
const char * V_197 , T_7 V_221 )
{
T_2 V_222 ;
if ( F_186 ( V_197 , 0 , & V_222 ) < 0 )
return - V_192 ;
F_182 ( V_218 ) -> V_86 = V_222 ;
F_176 () ;
return V_221 ;
}
static T_8
F_187 ( struct V_219 * V_220 , struct V_217 * V_218 , char * V_197 )
{
strcpy ( V_197 , V_146 ) ;
strcat ( V_197 , L_6 ) ;
return strlen ( V_146 ) + 1 ;
}
static T_8 F_188 ( struct V_219 * V_220 , struct V_217 * V_218 ,
const char * V_197 , T_7 V_223 )
{
char * V_207 ;
strncpy ( V_146 , V_197 , sizeof( V_146 ) ) ;
V_146 [ sizeof( V_146 ) - 1 ] = 0 ;
V_207 = strchr ( V_146 , '\n' ) ;
if ( V_207 )
* V_207 = 0 ;
return strlen ( V_146 ) + ! ! V_207 ;
}
static T_8 F_189 ( struct V_219 * V_220 ,
struct V_217 * V_218 ,
const char * V_197 , T_7 V_221 )
{
T_2 V_222 ;
if ( F_186 ( V_197 , 0 , & V_222 ) < 0 )
return - V_192 ;
if ( V_176 ^ ! ! V_222 ) {
if ( V_222 ) {
F_155 ( F_177 , ( void * ) 1 , 1 ) ;
V_176 = 1 ;
} else {
V_176 = 0 ;
F_155 ( F_179 , ( void * ) 1 , 1 ) ;
}
}
return V_221 ;
}
static T_8 F_190 ( struct V_219 * V_220 ,
struct V_217 * V_218 ,
const char * V_197 , T_7 V_221 )
{
T_2 V_222 ;
if ( F_186 ( V_197 , 0 , & V_222 ) < 0 )
return - V_192 ;
if ( V_215 ^ ! ! V_222 ) {
if ( V_222 ) {
F_155 ( F_177 , NULL , 1 ) ;
V_215 = 1 ;
} else {
V_215 = 0 ;
F_155 ( F_179 , NULL , 1 ) ;
}
}
return V_221 ;
}
static T_8 F_191 ( struct V_219 * V_220 ,
struct V_217 * V_218 ,
const char * V_197 , T_7 V_221 )
{
T_8 V_24 = F_192 ( V_220 , V_218 , V_197 , V_221 ) ;
F_176 () ;
return V_24 ;
}
static T_5 int F_193 ( unsigned int V_3 )
{
struct V_219 * V_224 = & F_73 ( V_225 , V_3 ) ;
int V_160 ;
int V_44 , V_226 ;
if ( ! F_52 ( & V_7 ) )
return - V_227 ;
memset ( & V_224 -> V_228 , 0 , sizeof( struct V_229 ) ) ;
V_224 -> V_230 = V_3 ;
V_224 -> V_231 = & V_232 ;
V_160 = F_194 ( V_224 ) ;
if ( V_160 )
return V_160 ;
for ( V_44 = 0 ; V_233 [ V_44 ] ; V_44 ++ ) {
V_160 = F_195 ( V_224 , V_233 [ V_44 ] ) ;
if ( V_160 )
goto error;
}
for ( V_226 = 0 ; V_226 < V_84 ; V_226 ++ ) {
V_160 = F_195 ( V_224 , & V_85 [ V_226 ] . V_218 ) ;
if ( V_160 )
goto V_234;
}
F_196 ( V_3 , V_235 ) ;
return 0 ;
V_234:
while ( -- V_226 >= 0 )
F_197 ( V_224 , & V_85 [ V_226 ] . V_218 ) ;
error:
while ( -- V_44 >= 0 )
F_197 ( V_224 , V_233 [ V_44 ] ) ;
F_198 ( V_224 ) ;
return V_160 ;
}
static T_5 void F_199 ( unsigned int V_3 )
{
struct V_219 * V_224 = & F_73 ( V_225 , V_3 ) ;
int V_44 ;
if ( ! F_200 ( V_3 , V_235 ) )
return;
for ( V_44 = 0 ; V_233 [ V_44 ] ; V_44 ++ )
F_197 ( V_224 , V_233 [ V_44 ] ) ;
for ( V_44 = 0 ; V_44 < V_84 ; V_44 ++ )
F_197 ( V_224 , & V_85 [ V_44 ] . V_218 ) ;
F_198 ( V_224 ) ;
F_201 ( V_3 , V_235 ) ;
}
static void T_5 F_202 ( void * V_236 )
{
unsigned long V_237 = * ( unsigned long * ) V_236 ;
int V_44 ;
if ( ! F_52 ( F_101 ( & V_139 ) ) )
return;
if ( ! ( V_237 & V_238 ) )
F_178 () ;
for ( V_44 = 0 ; V_44 < V_84 ; V_44 ++ ) {
struct V_152 * V_82 = & V_85 [ V_44 ] ;
if ( V_82 -> V_155 )
F_45 ( F_123 ( V_44 ) , 0 ) ;
}
}
static void T_5 F_203 ( void * V_236 )
{
unsigned long V_237 = * ( unsigned long * ) V_236 ;
int V_44 ;
if ( ! F_52 ( F_101 ( & V_139 ) ) )
return;
if ( ! ( V_237 & V_238 ) )
F_180 () ;
for ( V_44 = 0 ; V_44 < V_84 ; V_44 ++ ) {
struct V_152 * V_82 = & V_85 [ V_44 ] ;
if ( V_82 -> V_155 )
F_45 ( F_123 ( V_44 ) , V_82 -> V_86 ) ;
}
}
static int T_5
F_204 ( struct V_239 * V_240 , unsigned long V_237 , void * V_241 )
{
unsigned int V_3 = ( unsigned long ) V_241 ;
struct V_136 * V_97 = & F_73 ( V_137 , V_3 ) ;
switch ( V_237 ) {
case V_242 :
case V_243 :
F_193 ( V_3 ) ;
if ( V_244 )
V_244 ( V_237 , V_3 ) ;
break;
case V_245 :
case V_246 :
if ( V_244 )
V_244 ( V_237 , V_3 ) ;
F_199 ( V_3 ) ;
break;
case V_247 :
case V_248 :
F_175 ( V_97 ) ;
F_205 ( V_3 , F_202 , & V_237 , 1 ) ;
break;
case V_249 :
case V_250 :
if ( ! V_176 && V_143 ) {
V_97 -> V_144 = F_134 ( V_145 +
F_41 ( V_141 ) ) ;
F_105 ( V_97 , V_3 ) ;
}
F_205 ( V_3 , F_203 , & V_237 , 1 ) ;
break;
case V_251 :
F_206 ( V_3 ) ;
break;
}
return V_252 ;
}
static T_11 void F_207 ( void )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_84 ; V_44 ++ ) {
struct V_152 * V_82 = & V_85 [ V_44 ] ;
struct V_217 * V_253 = & V_82 -> V_218 ;
F_208 ( & V_253 -> V_218 ) ;
V_253 -> V_218 . V_254 = V_82 -> V_255 ;
snprintf ( V_82 -> V_255 , V_256 , L_36 , V_44 ) ;
V_253 -> V_218 . V_257 = 0644 ;
V_253 -> V_258 = F_184 ;
V_253 -> V_259 = F_185 ;
}
}
static T_11 int F_209 ( void )
{
int V_160 ;
int V_44 = 0 ;
if ( ! F_52 ( & V_7 ) )
return - V_227 ;
F_210 ( & V_235 , V_153 ) ;
F_207 () ;
V_160 = F_211 ( & V_232 ) ;
if ( V_160 )
return V_160 ;
F_212 (i) {
V_160 = F_193 ( V_44 ) ;
if ( V_160 )
return V_160 ;
}
F_213 ( & V_260 ) ;
F_214 ( & V_261 ) ;
F_215 ( & V_262 ) ;
return V_160 ;
}
static int T_11 F_216 ( char * V_214 )
{
V_71 = 1 ;
return 1 ;
}
struct V_263 * F_217 ( void )
{
static struct V_263 * V_264 ;
if ( ! V_264 )
V_264 = F_218 ( L_37 , NULL ) ;
return V_264 ;
}
static void F_219 ( void )
{
V_51 = 0 ;
F_78 ( & V_48 , 0 ) ;
F_78 ( & V_112 , 0 ) ;
F_78 ( & V_111 , 0 ) ;
F_78 ( & V_110 , 0 ) ;
}
static int F_220 ( void * V_135 , T_2 * V_265 )
{
* V_265 = V_46 ;
return 0 ;
}
static int F_221 ( void * V_135 , T_2 V_265 )
{
F_219 () ;
V_46 = V_265 ;
return 0 ;
}
static int T_11 F_222 ( void )
{
struct V_263 * V_264 , * V_266 ;
V_264 = F_217 () ;
if ( ! V_264 )
return - V_154 ;
V_266 = F_223 ( L_38 , 0444 , V_264 , NULL ,
& V_267 ) ;
if ( ! V_266 )
return - V_154 ;
return 0 ;
}
