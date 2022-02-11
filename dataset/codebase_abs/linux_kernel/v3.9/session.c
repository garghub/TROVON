static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 V_5 ;
if ( ! strcmp ( V_2 -> V_6 , L_1 ) ) {
V_2 -> V_7 = true ;
V_2 -> V_8 = V_9 ;
if ( F_2 ( V_2 , V_2 -> V_8 ) < 0 )
F_3 ( L_2 ) ;
return 0 ;
}
V_2 -> V_8 = F_4 ( V_2 -> V_6 , V_10 ) ;
if ( V_2 -> V_8 < 0 ) {
int V_11 = V_12 ;
F_3 ( L_3 , V_2 -> V_6 , strerror ( V_11 ) ) ;
if ( V_11 == V_13 && ! strcmp ( V_2 -> V_6 , L_4 ) )
F_3 ( L_5 ) ;
F_3 ( L_6 ) ;
return - V_12 ;
}
if ( F_5 ( V_2 -> V_8 , & V_5 ) < 0 )
goto V_14;
if ( ! V_3 && V_5 . V_15 && ( V_5 . V_15 != F_6 () ) ) {
F_3 ( L_7 ,
V_2 -> V_6 ) ;
goto V_14;
}
if ( ! V_5 . V_16 ) {
F_7 ( L_8 ,
V_2 -> V_6 ) ;
goto V_14;
}
if ( F_2 ( V_2 , V_2 -> V_8 ) < 0 ) {
F_3 ( L_2 ) ;
goto V_14;
}
if ( ! F_8 ( V_2 -> V_17 ) ) {
F_3 ( L_9 ) ;
goto V_14;
}
if ( ! F_9 ( V_2 -> V_17 ) ) {
F_3 ( L_10 ) ;
goto V_14;
}
V_2 -> V_18 = V_5 . V_16 ;
return 0 ;
V_14:
F_10 ( V_2 -> V_8 ) ;
V_2 -> V_8 = - 1 ;
return - 1 ;
}
void F_11 ( struct V_1 * V_19 )
{
T_1 V_20 = F_12 ( V_19 -> V_17 ) ;
F_13 ( & V_19 -> V_21 , V_20 ) ;
}
int F_14 ( struct V_1 * V_2 )
{
int V_22 = F_15 ( & V_2 -> V_21 . V_23 ) ;
if ( V_22 >= 0 )
V_22 = F_16 ( & V_2 -> V_21 ) ;
return V_22 ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_18 ( & V_2 -> V_21 ) ;
}
struct V_1 * F_19 ( const char * V_6 , int V_24 ,
bool V_3 , bool V_25 ,
struct V_26 * V_27 )
{
struct V_1 * V_2 ;
struct V_4 V_28 ;
T_2 V_29 ;
if ( ! V_6 || ! strlen ( V_6 ) ) {
if ( ! F_5 ( V_9 , & V_28 ) && F_20 ( V_28 . V_30 ) )
V_6 = L_1 ;
else
V_6 = L_4 ;
}
V_29 = strlen ( V_6 ) ;
V_2 = F_21 ( sizeof( * V_2 ) + V_29 ) ;
if ( V_2 == NULL )
goto V_31;
memcpy ( V_2 -> V_6 , V_6 , V_29 ) ;
V_2 -> V_25 = V_25 ;
F_22 ( & V_2 -> V_32 . V_33 ) ;
F_22 ( & V_2 -> V_32 . V_34 ) ;
F_22 ( & V_2 -> V_32 . V_35 ) ;
F_23 ( & V_2 -> V_21 ) ;
if ( V_24 == V_10 ) {
if ( F_1 ( V_2 , V_3 ) < 0 )
goto V_36;
F_11 ( V_2 ) ;
} else if ( V_24 == V_37 ) {
if ( F_14 ( V_2 ) < 0 )
goto V_36;
}
if ( V_27 && V_27 -> V_38 &&
V_27 -> V_32 && ! F_24 ( V_2 -> V_17 ) ) {
F_25 ( L_11 ) ;
V_27 -> V_32 = false ;
}
V_31:
return V_2 ;
V_36:
F_26 ( V_2 ) ;
return NULL ;
}
static void F_27 ( struct V_1 * V_19 )
{
F_28 ( & V_19 -> V_21 . V_23 ) ;
}
static void F_29 ( struct V_1 * V_19 )
{
F_30 ( & V_19 -> V_21 . V_23 ) ;
}
static void F_31 ( struct V_39 * V_40 )
{
free ( V_40 -> V_41 ) ;
free ( V_40 -> V_42 ) ;
free ( V_40 -> V_43 ) ;
free ( V_40 -> V_44 ) ;
free ( V_40 -> V_45 ) ;
free ( V_40 -> V_46 ) ;
free ( V_40 -> V_47 ) ;
free ( V_40 -> V_48 ) ;
free ( V_40 -> V_49 ) ;
free ( V_40 -> V_50 ) ;
free ( V_40 -> V_51 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
F_17 ( V_2 ) ;
F_27 ( V_2 ) ;
F_29 ( V_2 ) ;
F_31 ( & V_2 -> V_52 . V_40 ) ;
F_32 ( & V_2 -> V_21 ) ;
F_10 ( V_2 -> V_8 ) ;
free ( V_2 ) ;
F_33 () ;
}
static int F_34 ( union V_53 * T_3
V_54 ,
struct V_1 * V_19
V_54 )
{
F_25 ( L_12 ) ;
return 0 ;
}
static int F_35 ( union V_53 * T_3 V_54 ,
struct V_55 * * T_4
V_54 )
{
F_25 ( L_12 ) ;
return 0 ;
}
static int F_36 ( struct V_26 * V_27 V_54 ,
union V_53 * T_3 V_54 ,
struct V_56 * T_5 V_54 ,
struct V_57 * T_6 V_54 ,
struct V_58 * V_58 V_54 )
{
F_25 ( L_12 ) ;
return 0 ;
}
static int F_37 ( struct V_26 * V_27 V_54 ,
union V_53 * T_3 V_54 ,
struct V_56 * T_5 V_54 ,
struct V_58 * V_58 V_54 )
{
F_25 ( L_12 ) ;
return 0 ;
}
static int F_38 ( struct V_26 * V_27 V_54 ,
union V_53 * T_3 V_54 ,
struct V_1 * V_1
V_54 )
{
F_25 ( L_12 ) ;
return 0 ;
}
static int F_39 ( struct V_26 * V_27 V_54 ,
union V_53 * T_3 V_54 )
{
F_25 ( L_12 ) ;
return 0 ;
}
static void F_40 ( struct V_26 * V_27 )
{
if ( V_27 -> T_5 == NULL )
V_27 -> T_5 = F_36 ;
if ( V_27 -> V_59 == NULL )
V_27 -> V_59 = F_37 ;
if ( V_27 -> V_60 == NULL )
V_27 -> V_60 = F_37 ;
if ( V_27 -> V_61 == NULL )
V_27 -> V_61 = F_37 ;
if ( V_27 -> exit == NULL )
V_27 -> exit = F_37 ;
if ( V_27 -> V_62 == NULL )
V_27 -> V_62 = V_63 ;
if ( V_27 -> V_64 == NULL )
V_27 -> V_64 = F_36 ;
if ( V_27 -> V_65 == NULL )
V_27 -> V_65 = F_37 ;
if ( V_27 -> V_66 == NULL )
V_27 -> V_66 = F_37 ;
if ( V_27 -> V_67 == NULL )
V_27 -> V_67 = F_35 ;
if ( V_27 -> V_68 == NULL )
V_27 -> V_68 = F_39 ;
if ( V_27 -> V_69 == NULL )
V_27 -> V_69 = F_34 ;
if ( V_27 -> V_70 == NULL )
V_27 -> V_70 = F_38 ;
if ( V_27 -> V_71 == NULL ) {
if ( V_27 -> V_32 )
V_27 -> V_71 = V_72 ;
else
V_27 -> V_71 = F_38 ;
}
}
void F_41 ( void * V_73 , int V_74 )
{
T_7 * V_75 = V_73 ;
while ( V_74 > 0 ) {
* V_75 = F_42 ( * V_75 ) ;
V_74 -= sizeof( T_7 ) ;
++ V_75 ;
}
}
void F_43 ( void * V_73 , int V_74 )
{
T_8 * V_75 = V_73 ;
while ( V_74 > 0 ) {
* V_75 = F_44 ( * V_75 ) ;
V_74 -= sizeof( T_8 ) ;
++ V_75 ;
}
}
static void F_45 ( union V_53 * T_3 , void * V_76 )
{
void * V_77 = ( void * ) T_3 + T_3 -> V_52 . V_18 ;
int V_18 = V_77 - V_76 ;
F_46 ( V_18 % sizeof( T_8 ) ) ;
F_43 ( V_76 , V_18 ) ;
}
static void F_47 ( union V_53 * T_3 ,
bool T_9 V_54 )
{
struct V_78 * V_79 = & T_3 -> V_52 ;
F_43 ( V_79 + 1 , T_3 -> V_52 . V_18 - sizeof( * V_79 ) ) ;
}
static void F_48 ( union V_53 * T_3 , bool T_9 )
{
T_3 -> V_60 . V_80 = F_42 ( T_3 -> V_60 . V_80 ) ;
T_3 -> V_60 . V_81 = F_42 ( T_3 -> V_60 . V_81 ) ;
if ( T_9 ) {
void * V_76 = & T_3 -> V_60 . V_60 ;
V_76 += F_49 ( strlen ( V_76 ) + 1 , sizeof( T_8 ) ) ;
F_45 ( T_3 , V_76 ) ;
}
}
static void F_50 ( union V_53 * T_3 ,
bool T_9 )
{
T_3 -> V_59 . V_80 = F_42 ( T_3 -> V_59 . V_80 ) ;
T_3 -> V_59 . V_81 = F_42 ( T_3 -> V_59 . V_81 ) ;
T_3 -> V_59 . V_82 = F_44 ( T_3 -> V_59 . V_82 ) ;
T_3 -> V_59 . V_29 = F_44 ( T_3 -> V_59 . V_29 ) ;
T_3 -> V_59 . V_83 = F_44 ( T_3 -> V_59 . V_83 ) ;
if ( T_9 ) {
void * V_76 = & T_3 -> V_59 . V_6 ;
V_76 += F_49 ( strlen ( V_76 ) + 1 , sizeof( T_8 ) ) ;
F_45 ( T_3 , V_76 ) ;
}
}
static void F_51 ( union V_53 * T_3 , bool T_9 )
{
T_3 -> V_61 . V_80 = F_42 ( T_3 -> V_61 . V_80 ) ;
T_3 -> V_61 . V_81 = F_42 ( T_3 -> V_61 . V_81 ) ;
T_3 -> V_61 . V_84 = F_42 ( T_3 -> V_61 . V_84 ) ;
T_3 -> V_61 . V_85 = F_42 ( T_3 -> V_61 . V_85 ) ;
T_3 -> V_61 . time = F_44 ( T_3 -> V_61 . time ) ;
if ( T_9 )
F_45 ( T_3 , & T_3 -> V_61 + 1 ) ;
}
static void F_52 ( union V_53 * T_3 , bool T_9 )
{
T_3 -> V_64 . V_80 = F_42 ( T_3 -> V_64 . V_80 ) ;
T_3 -> V_64 . V_81 = F_42 ( T_3 -> V_64 . V_81 ) ;
T_3 -> V_64 . V_86 = F_44 ( T_3 -> V_64 . V_86 ) ;
T_3 -> V_64 . V_87 = F_44 ( T_3 -> V_64 . V_87 ) ;
T_3 -> V_64 . V_88 = F_44 ( T_3 -> V_64 . V_88 ) ;
T_3 -> V_64 . V_89 = F_44 ( T_3 -> V_64 . V_89 ) ;
if ( T_9 )
F_45 ( T_3 , & T_3 -> V_64 + 1 ) ;
}
static T_10 F_53 ( T_10 V_90 )
{
int V_91 = ( V_90 >> 4 ) | ( ( V_90 & 0xf ) << 4 ) ;
V_91 = ( ( V_91 & 0xcc ) >> 2 ) | ( ( V_91 & 0x33 ) << 2 ) ;
V_91 = ( ( V_91 & 0xaa ) >> 1 ) | ( ( V_91 & 0x55 ) << 1 ) ;
return ( T_10 ) V_91 ;
}
static void F_54 ( T_10 * V_92 , unsigned V_29 )
{
unsigned V_93 ;
for ( V_93 = 0 ; V_93 < V_29 ; V_93 ++ ) {
* V_92 = F_53 ( * V_92 ) ;
V_92 ++ ;
}
}
void F_55 ( struct V_94 * V_67 )
{
V_67 -> type = F_42 ( V_67 -> type ) ;
V_67 -> V_18 = F_42 ( V_67 -> V_18 ) ;
V_67 -> V_95 = F_44 ( V_67 -> V_95 ) ;
V_67 -> V_96 = F_44 ( V_67 -> V_96 ) ;
V_67 -> V_97 = F_44 ( V_67 -> V_97 ) ;
V_67 -> V_98 = F_44 ( V_67 -> V_98 ) ;
V_67 -> V_99 = F_42 ( V_67 -> V_99 ) ;
V_67 -> V_100 = F_42 ( V_67 -> V_100 ) ;
V_67 -> V_101 = F_44 ( V_67 -> V_101 ) ;
V_67 -> V_102 = F_44 ( V_67 -> V_102 ) ;
F_54 ( ( T_10 * ) ( & V_67 -> V_98 + 1 ) , sizeof( T_8 ) ) ;
}
static void F_56 ( union V_53 * T_3 ,
bool T_9 V_54 )
{
T_2 V_18 ;
F_55 ( & T_3 -> V_67 . V_67 ) ;
V_18 = T_3 -> V_52 . V_18 ;
V_18 -= ( void * ) & T_3 -> V_67 . V_89 - ( void * ) T_3 ;
F_43 ( T_3 -> V_67 . V_89 , V_18 ) ;
}
static void F_57 ( union V_53 * T_3 ,
bool T_9 V_54 )
{
T_3 -> V_68 . V_68 . V_103 =
F_44 ( T_3 -> V_68 . V_68 . V_103 ) ;
}
static void F_58 ( union V_53 * T_3 ,
bool T_9 V_54 )
{
T_3 -> V_69 . V_18 = F_42 ( T_3 -> V_69 . V_18 ) ;
}
static void F_59 ( struct V_1 * V_19 )
{
struct V_32 * V_104 = & V_19 -> V_32 ;
while ( ! F_60 ( & V_104 -> V_35 ) ) {
struct V_105 * V_106 ;
V_106 = F_61 ( V_104 -> V_35 . V_107 , struct V_105 , V_108 ) ;
F_62 ( & V_106 -> V_108 ) ;
free ( V_106 ) ;
}
}
static int F_63 ( struct V_1 * V_109 ,
struct V_26 * V_27 )
{
struct V_32 * V_104 = & V_109 -> V_32 ;
struct V_110 * V_111 = & V_104 -> V_33 ;
struct V_105 * V_112 , * V_113 ;
struct V_56 T_5 ;
T_8 V_114 = V_104 -> V_115 ;
T_8 V_116 = V_104 -> V_117 ? V_104 -> V_117 -> V_118 : 0ULL ;
unsigned V_119 = 0 , V_120 = V_104 -> V_121 / 16 ;
int V_22 ;
if ( ! V_27 -> V_32 || ! V_114 )
return 0 ;
F_64 (iter, tmp, head, list) {
if ( V_113 -> V_118 > V_114 )
break;
V_22 = F_65 ( V_109 -> V_17 , V_113 -> T_3 , & T_5 ) ;
if ( V_22 )
F_3 ( L_13 , V_22 ) ;
else {
V_22 = F_66 ( V_109 , V_113 -> T_3 , & T_5 , V_27 ,
V_113 -> V_122 ) ;
if ( V_22 )
return V_22 ;
}
V_104 -> V_123 = V_113 -> V_118 ;
F_62 ( & V_113 -> V_108 ) ;
F_67 ( & V_113 -> V_108 , & V_104 -> V_34 ) ;
if ( ++ V_119 >= V_120 ) {
V_120 += V_104 -> V_121 / 16 ;
F_68 ( V_119 , V_104 -> V_121 ,
L_14 ) ;
}
}
if ( F_60 ( V_111 ) ) {
V_104 -> V_117 = NULL ;
} else if ( V_116 <= V_114 ) {
V_104 -> V_117 =
F_61 ( V_111 -> V_124 , struct V_105 , V_108 ) ;
}
V_104 -> V_121 = 0 ;
return 0 ;
}
static int V_72 ( struct V_26 * V_27 ,
union V_53 * T_3 V_54 ,
struct V_1 * V_19 )
{
int V_22 = F_63 ( V_19 , V_27 ) ;
if ( ! V_22 )
V_19 -> V_32 . V_115 = V_19 -> V_32 . V_125 ;
return V_22 ;
}
static void F_69 ( struct V_105 * V_126 , struct V_1 * V_109 )
{
struct V_32 * V_104 = & V_109 -> V_32 ;
struct V_105 * T_5 = V_104 -> V_117 ;
T_8 V_118 = V_126 -> V_118 ;
struct V_110 * V_92 ;
++ V_104 -> V_121 ;
V_104 -> V_117 = V_126 ;
if ( ! T_5 ) {
F_67 ( & V_126 -> V_108 , & V_104 -> V_33 ) ;
V_104 -> V_125 = V_118 ;
return;
}
if ( T_5 -> V_118 <= V_118 ) {
while ( T_5 -> V_118 <= V_118 ) {
V_92 = T_5 -> V_108 . V_107 ;
if ( V_92 == & V_104 -> V_33 ) {
F_70 ( & V_126 -> V_108 , & V_104 -> V_33 ) ;
V_104 -> V_125 = V_118 ;
return;
}
T_5 = F_61 ( V_92 , struct V_105 , V_108 ) ;
}
F_70 ( & V_126 -> V_108 , & T_5 -> V_108 ) ;
} else {
while ( T_5 -> V_118 > V_118 ) {
V_92 = T_5 -> V_108 . V_124 ;
if ( V_92 == & V_104 -> V_33 ) {
F_67 ( & V_126 -> V_108 , & V_104 -> V_33 ) ;
return;
}
T_5 = F_61 ( V_92 , struct V_105 , V_108 ) ;
}
F_67 ( & V_126 -> V_108 , & T_5 -> V_108 ) ;
}
}
static int F_71 ( struct V_1 * V_109 , union V_53 * T_3 ,
struct V_56 * T_5 , T_8 V_122 )
{
struct V_32 * V_104 = & V_109 -> V_32 ;
struct V_110 * V_127 = & V_104 -> V_34 ;
T_8 V_118 = T_5 -> time ;
struct V_105 * V_126 ;
if ( ! V_118 || V_118 == ~ 0ULL )
return - V_128 ;
if ( V_118 < V_109 -> V_32 . V_123 ) {
printf ( L_15 ) ;
return - V_129 ;
}
if ( ! F_60 ( V_127 ) ) {
V_126 = F_61 ( V_127 -> V_107 , struct V_105 , V_108 ) ;
F_62 ( & V_126 -> V_108 ) ;
} else if ( V_104 -> V_130 ) {
V_126 = V_104 -> V_130 + V_104 -> V_131 ;
if ( ++ V_104 -> V_131 == V_132 )
V_104 -> V_130 = NULL ;
} else {
V_104 -> V_130 = malloc ( V_132 * sizeof( * V_126 ) ) ;
if ( ! V_104 -> V_130 )
return - V_133 ;
F_67 ( & V_104 -> V_130 -> V_108 , & V_104 -> V_35 ) ;
V_104 -> V_131 = 2 ;
V_126 = V_104 -> V_130 + 1 ;
}
V_126 -> V_118 = V_118 ;
V_126 -> V_122 = V_122 ;
V_126 -> T_3 = T_3 ;
F_69 ( V_126 , V_109 ) ;
return 0 ;
}
static void F_72 ( struct V_56 * T_5 )
{
unsigned int V_93 ;
printf ( L_16 V_134 L_6 , T_5 -> V_135 -> V_136 ) ;
for ( V_93 = 0 ; V_93 < T_5 -> V_135 -> V_136 ; V_93 ++ )
printf ( L_17 V_137 L_6 ,
V_93 , T_5 -> V_135 -> V_138 [ V_93 ] ) ;
}
static void F_73 ( struct V_56 * T_5 )
{
T_11 V_93 ;
printf ( L_18 V_134 L_6 , T_5 -> V_139 -> V_136 ) ;
for ( V_93 = 0 ; V_93 < T_5 -> V_139 -> V_136 ; V_93 ++ )
printf ( L_19 V_134 L_20 V_137 L_21 V_137 L_6 ,
V_93 , T_5 -> V_139 -> V_140 [ V_93 ] . V_141 ,
T_5 -> V_139 -> V_140 [ V_93 ] . V_142 ) ;
}
static void F_74 ( T_8 V_143 , T_8 * V_144 )
{
unsigned V_145 , V_93 = 0 ;
F_75 (rid, (unsigned long *) &mask, sizeof(mask) * 8 ) {
T_8 V_146 = V_144 [ V_93 ++ ] ;
printf ( L_22 V_137 L_6 ,
F_76 ( V_145 ) , V_146 ) ;
}
}
static void F_77 ( struct V_56 * T_5 , T_8 V_143 )
{
struct V_147 * V_148 = & T_5 -> V_148 ;
if ( V_148 -> V_144 ) {
printf ( L_23 V_137 L_6 , V_143 ) ;
F_74 ( V_143 , V_148 -> V_144 ) ;
}
}
static void F_78 ( struct V_149 * V_150 )
{
printf ( L_24 V_134 L_25 ,
V_150 -> V_18 , V_150 -> V_151 ) ;
}
static void F_79 ( struct V_1 * V_19 ,
union V_53 * T_3 ,
struct V_56 * T_5 )
{
T_8 V_97 = F_80 ( V_19 -> V_17 ) ;
if ( T_3 -> V_52 . type != V_152 &&
! F_24 ( V_19 -> V_17 ) ) {
fputs ( L_26 , stdout ) ;
return;
}
if ( ( V_97 & V_153 ) )
printf ( L_27 , T_5 -> V_154 ) ;
if ( V_97 & V_155 )
printf ( L_28 V_134 L_29 , T_5 -> time ) ;
}
static void F_81 ( struct V_1 * V_19 , union V_53 * T_3 ,
T_8 V_122 , struct V_56 * T_5 )
{
if ( ! V_156 )
return;
printf ( L_30 V_137 L_31 ,
V_122 , T_3 -> V_52 . V_18 , T_3 -> V_52 . type ) ;
F_82 ( T_3 ) ;
if ( T_5 )
F_79 ( V_19 , T_3 , T_5 ) ;
printf ( L_32 V_137 L_33 , V_122 ,
T_3 -> V_52 . V_18 , F_83 ( T_3 -> V_52 . type ) ) ;
}
static void F_84 ( struct V_57 * T_6 , union V_53 * T_3 ,
struct V_56 * T_5 )
{
T_8 V_97 ;
if ( ! V_156 )
return;
printf ( L_34 V_137 L_35 V_134 L_36 V_137 L_6 ,
T_3 -> V_52 . V_157 , T_5 -> V_80 , T_5 -> V_81 , T_5 -> V_158 ,
T_5 -> V_159 , T_5 -> V_160 ) ;
V_97 = T_6 -> V_67 . V_97 ;
if ( V_97 & V_161 )
F_72 ( T_5 ) ;
if ( V_97 & V_162 )
F_73 ( T_5 ) ;
if ( V_97 & V_163 )
F_77 ( T_5 , T_6 -> V_67 . V_164 ) ;
if ( V_97 & V_165 )
F_78 ( & T_5 -> V_166 ) ;
}
static struct V_58 *
F_85 ( struct V_1 * V_19 ,
union V_53 * T_3 )
{
const T_10 V_167 = T_3 -> V_52 . V_157 & V_168 ;
if ( V_169 &&
( ( V_167 == V_170 ) ||
( V_167 == V_171 ) ) ) {
T_7 V_80 ;
if ( T_3 -> V_52 . type == V_172 )
V_80 = T_3 -> V_59 . V_80 ;
else
V_80 = T_3 -> V_158 . V_80 ;
return F_86 ( V_19 , V_80 ) ;
}
return & V_19 -> V_21 . V_23 ;
}
static int F_66 ( struct V_1 * V_19 ,
union V_53 * T_3 ,
struct V_56 * T_5 ,
struct V_26 * V_27 ,
T_8 V_122 )
{
struct V_57 * T_6 ;
struct V_58 * V_58 ;
F_81 ( V_19 , T_3 , V_122 , T_5 ) ;
T_6 = F_87 ( V_19 -> V_17 , T_5 -> V_89 ) ;
if ( T_6 != NULL && T_3 -> V_52 . type != V_152 ) {
F_88 ( & T_6 -> V_173 , T_3 -> V_52 . type ) ;
}
V_58 = F_85 ( V_19 , T_3 ) ;
switch ( T_3 -> V_52 . type ) {
case V_152 :
F_84 ( T_6 , T_3 , T_5 ) ;
if ( T_6 == NULL ) {
++ V_19 -> V_174 . V_175 ;
return 0 ;
}
if ( V_58 == NULL ) {
++ V_19 -> V_174 . V_176 ;
return 0 ;
}
return V_27 -> T_5 ( V_27 , T_3 , T_5 , T_6 , V_58 ) ;
case V_172 :
return V_27 -> V_59 ( V_27 , T_3 , T_5 , V_58 ) ;
case V_177 :
return V_27 -> V_60 ( V_27 , T_3 , T_5 , V_58 ) ;
case V_178 :
return V_27 -> V_61 ( V_27 , T_3 , T_5 , V_58 ) ;
case V_179 :
return V_27 -> exit ( V_27 , T_3 , T_5 , V_58 ) ;
case V_180 :
if ( V_27 -> V_62 == V_63 )
V_19 -> V_174 . V_181 += T_3 -> V_62 . V_62 ;
return V_27 -> V_62 ( V_27 , T_3 , T_5 , V_58 ) ;
case V_182 :
return V_27 -> V_64 ( V_27 , T_3 , T_5 , T_6 , V_58 ) ;
case V_183 :
return V_27 -> V_65 ( V_27 , T_3 , T_5 , V_58 ) ;
case V_184 :
return V_27 -> V_66 ( V_27 , T_3 , T_5 , V_58 ) ;
default:
++ V_19 -> V_174 . V_185 ;
return - 1 ;
}
}
static int F_89 ( struct V_1 * V_19 ,
union V_53 * T_3 , struct V_56 * T_5 )
{
if ( T_3 -> V_52 . type != V_152 ||
! ( F_80 ( V_19 -> V_17 ) & V_161 ) )
return 0 ;
if ( ! F_90 ( T_5 -> V_135 , T_3 ) ) {
F_91 ( L_37 ) ;
++ V_19 -> V_174 . V_186 ;
V_19 -> V_174 . V_187 += T_5 -> V_159 ;
return - V_129 ;
}
return 0 ;
}
static int F_92 ( struct V_1 * V_19 , union V_53 * T_3 ,
struct V_26 * V_27 , T_8 V_122 )
{
int V_11 ;
F_81 ( V_19 , T_3 , V_122 , NULL ) ;
switch ( T_3 -> V_52 . type ) {
case V_188 :
V_11 = V_27 -> V_67 ( T_3 , & V_19 -> V_17 ) ;
if ( V_11 == 0 )
F_11 ( V_19 ) ;
return V_11 ;
case V_189 :
return V_27 -> V_68 ( V_27 , T_3 ) ;
case V_190 :
F_93 ( V_19 -> V_8 , V_122 , V_191 ) ;
return V_27 -> V_69 ( T_3 , V_19 ) ;
case V_192 :
return V_27 -> V_70 ( V_27 , T_3 , V_19 ) ;
case V_193 :
return V_27 -> V_71 ( V_27 , T_3 , V_19 ) ;
default:
return - V_129 ;
}
}
static void F_94 ( union V_53 * T_3 , bool T_9 )
{
T_12 V_194 ;
V_194 = V_195 [ T_3 -> V_52 . type ] ;
if ( V_194 )
V_194 ( T_3 , T_9 ) ;
}
static int F_95 ( struct V_1 * V_19 ,
union V_53 * T_3 ,
struct V_26 * V_27 ,
T_8 V_122 )
{
struct V_56 T_5 ;
int V_22 ;
if ( V_19 -> V_52 . V_196 )
F_94 ( T_3 , F_24 ( V_19 -> V_17 ) ) ;
if ( T_3 -> V_52 . type >= V_197 )
return - V_129 ;
F_96 ( & V_19 -> V_174 , T_3 -> V_52 . type ) ;
if ( T_3 -> V_52 . type >= V_198 )
return F_92 ( V_19 , T_3 , V_27 , V_122 ) ;
V_22 = F_65 ( V_19 -> V_17 , T_3 , & T_5 ) ;
if ( V_22 )
return V_22 ;
if ( F_89 ( V_19 , T_3 , & T_5 ) )
return 0 ;
if ( V_27 -> V_32 ) {
V_22 = F_71 ( V_19 , T_3 , & T_5 ,
V_122 ) ;
if ( V_22 != - V_128 )
return V_22 ;
}
return F_66 ( V_19 , T_3 , & T_5 , V_27 ,
V_122 ) ;
}
void F_97 ( struct V_78 * V_2 )
{
V_2 -> type = F_42 ( V_2 -> type ) ;
V_2 -> V_157 = F_98 ( V_2 -> V_157 ) ;
V_2 -> V_18 = F_98 ( V_2 -> V_18 ) ;
}
struct V_199 * F_99 ( struct V_1 * V_19 , T_13 V_80 )
{
return F_100 ( & V_19 -> V_21 . V_23 , V_80 ) ;
}
static struct V_199 * F_101 ( struct V_1 * V_2 )
{
struct V_199 * V_199 = F_99 ( V_2 , 0 ) ;
if ( V_199 == NULL || F_102 ( V_199 , L_38 ) ) {
F_3 ( L_39 ) ;
V_199 = NULL ;
}
return V_199 ;
}
static void F_103 ( const struct V_1 * V_19 ,
const struct V_26 * V_27 )
{
if ( V_27 -> V_62 == V_63 &&
V_19 -> V_174 . V_200 [ V_180 ] != 0 ) {
F_104 ( L_40
L_41 ,
V_19 -> V_174 . V_200 [ 0 ] ,
V_19 -> V_174 . V_200 [ V_180 ] ) ;
}
if ( V_19 -> V_174 . V_185 != 0 ) {
F_104 ( L_42
L_43
L_44
L_45
L_46 ,
V_19 -> V_174 . V_185 ) ;
}
if ( V_19 -> V_174 . V_175 != 0 ) {
F_104 ( L_47 ,
V_19 -> V_174 . V_175 ) ;
}
if ( V_19 -> V_174 . V_186 != 0 ) {
F_104 ( L_48
L_49
L_50 ,
V_19 -> V_174 . V_186 ,
V_19 -> V_174 . V_200 [ V_152 ] ) ;
}
if ( V_19 -> V_174 . V_176 != 0 ) {
F_104 ( L_51
L_52 ,
V_19 -> V_174 . V_176 ) ;
}
}
static int F_105 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
union V_53 * T_3 ;
T_14 V_18 , V_201 = 0 ;
void * V_202 = NULL ;
int V_203 = 0 ;
T_8 V_111 ;
int V_11 ;
void * V_92 ;
F_40 ( V_27 ) ;
V_111 = 0 ;
V_201 = sizeof( union V_53 ) ;
V_202 = malloc ( V_201 ) ;
if ( ! V_202 )
return - V_12 ;
V_204:
T_3 = V_202 ;
V_11 = F_106 ( V_2 -> V_8 , T_3 , sizeof( struct V_78 ) ) ;
if ( V_11 <= 0 ) {
if ( V_11 == 0 )
goto V_205;
F_3 ( L_53 ) ;
goto V_206;
}
if ( V_2 -> V_52 . V_196 )
F_97 ( & T_3 -> V_52 ) ;
V_18 = T_3 -> V_52 . V_18 ;
if ( V_18 == 0 )
V_18 = 8 ;
if ( V_18 > V_201 ) {
void * V_126 = realloc ( V_202 , V_18 ) ;
if ( ! V_126 ) {
F_3 ( L_54 ) ;
goto V_206;
}
V_202 = V_126 ;
V_201 = V_18 ;
T_3 = V_202 ;
}
V_92 = T_3 ;
V_92 += sizeof( struct V_78 ) ;
if ( V_18 - sizeof( struct V_78 ) ) {
V_11 = F_106 ( V_2 -> V_8 , V_92 , V_18 - sizeof( struct V_78 ) ) ;
if ( V_11 <= 0 ) {
if ( V_11 == 0 ) {
F_3 ( L_55 ) ;
goto V_205;
}
F_3 ( L_56 ) ;
goto V_206;
}
}
if ( ( V_203 = F_95 ( V_2 , T_3 , V_27 , V_111 ) ) < 0 ) {
F_3 ( L_32 V_137 L_57 ,
V_111 , T_3 -> V_52 . V_18 , T_3 -> V_52 . type ) ;
V_11 = - V_129 ;
goto V_206;
}
V_111 += V_18 ;
if ( V_203 > 0 )
V_111 += V_203 ;
if ( ! F_107 () )
goto V_204;
V_205:
V_11 = 0 ;
V_206:
free ( V_202 ) ;
F_103 ( V_2 , V_27 ) ;
F_59 ( V_2 ) ;
return V_11 ;
}
static union V_53 *
F_108 ( struct V_1 * V_19 ,
T_8 V_111 , T_2 V_207 , char * V_202 )
{
union V_53 * T_3 ;
if ( V_111 + sizeof( T_3 -> V_52 ) > V_207 )
return NULL ;
T_3 = (union V_53 * ) ( V_202 + V_111 ) ;
if ( V_19 -> V_52 . V_196 )
F_97 ( & T_3 -> V_52 ) ;
if ( V_111 + T_3 -> V_52 . V_18 > V_207 )
return NULL ;
return T_3 ;
}
int F_109 ( struct V_1 * V_19 ,
T_8 V_208 , T_8 V_209 ,
T_8 V_210 , struct V_26 * V_27 )
{
T_8 V_111 , V_211 , V_122 , V_212 , V_120 ;
int V_11 , V_213 , V_214 , V_215 = 0 ;
T_2 V_207 ;
char * V_202 , * V_216 [ V_217 ] ;
union V_53 * T_3 ;
T_14 V_18 ;
F_40 ( V_27 ) ;
V_211 = V_218 * ( V_208 / V_218 ) ;
V_122 = V_211 ;
V_111 = V_208 - V_211 ;
if ( V_208 + V_209 < V_210 )
V_210 = V_208 + V_209 ;
V_120 = V_210 / 16 ;
V_207 = V_219 ;
if ( V_207 > V_210 )
V_207 = V_210 ;
memset ( V_216 , 0 , sizeof( V_216 ) ) ;
V_213 = V_220 ;
V_214 = V_221 ;
if ( V_19 -> V_52 . V_196 ) {
V_213 |= V_222 ;
V_214 = V_223 ;
}
V_224:
V_202 = V_59 ( NULL , V_207 , V_213 , V_214 , V_19 -> V_8 ,
V_122 ) ;
if ( V_202 == V_225 ) {
F_3 ( L_58 ) ;
V_11 = - V_12 ;
goto V_206;
}
V_216 [ V_215 ] = V_202 ;
V_215 = ( V_215 + 1 ) & ( F_110 ( V_216 ) - 1 ) ;
V_212 = V_122 + V_111 ;
V_204:
T_3 = F_108 ( V_19 , V_111 , V_207 , V_202 ) ;
if ( ! T_3 ) {
if ( V_216 [ V_215 ] ) {
F_111 ( V_216 [ V_215 ] , V_207 ) ;
V_216 [ V_215 ] = NULL ;
}
V_211 = V_218 * ( V_111 / V_218 ) ;
V_122 += V_211 ;
V_111 -= V_211 ;
goto V_224;
}
V_18 = T_3 -> V_52 . V_18 ;
if ( V_18 == 0 ||
F_95 ( V_19 , T_3 , V_27 , V_212 ) < 0 ) {
F_3 ( L_32 V_137 L_57 ,
V_122 + V_111 , T_3 -> V_52 . V_18 ,
T_3 -> V_52 . type ) ;
V_11 = - V_129 ;
goto V_206;
}
V_111 += V_18 ;
V_212 += V_18 ;
if ( V_212 >= V_120 ) {
V_120 += V_210 / 16 ;
F_68 ( V_212 , V_210 ,
L_59 ) ;
}
if ( V_212 < V_210 )
goto V_204;
V_11 = 0 ;
V_19 -> V_32 . V_115 = V_226 ;
V_11 = F_63 ( V_19 , V_27 ) ;
V_206:
F_112 () ;
F_103 ( V_19 , V_27 ) ;
F_59 ( V_19 ) ;
return V_11 ;
}
int F_113 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
int V_11 ;
if ( F_101 ( V_2 ) == NULL )
return - V_133 ;
if ( ! V_2 -> V_7 )
V_11 = F_109 ( V_2 ,
V_2 -> V_52 . V_208 ,
V_2 -> V_52 . V_209 ,
V_2 -> V_18 , V_27 ) ;
else
V_11 = F_105 ( V_2 , V_27 ) ;
return V_11 ;
}
bool F_114 ( struct V_1 * V_19 , const char * V_227 )
{
if ( ! ( F_80 ( V_19 -> V_17 ) & V_228 ) ) {
F_3 ( L_60 , V_227 ) ;
return false ;
}
return true ;
}
int F_115 ( struct V_229 * * V_230 ,
const char * V_231 , T_8 V_160 )
{
char * V_232 ;
enum V_233 V_93 ;
struct V_234 * V_235 ;
V_235 = F_21 ( sizeof( struct V_234 ) ) ;
if ( V_235 == NULL )
return - V_133 ;
V_235 -> V_236 = F_116 ( V_231 ) ;
if ( V_235 -> V_236 == NULL ) {
free ( V_235 ) ;
return - V_133 ;
}
V_232 = strchr ( V_235 -> V_236 , ']' ) ;
if ( V_232 )
* V_232 = '\0' ;
V_235 -> V_160 = V_160 ;
for ( V_93 = 0 ; V_93 < V_237 ; ++ V_93 ) {
struct V_238 * V_238 = F_117 ( V_230 [ V_93 ] ) ;
V_238 -> V_234 = V_235 ;
}
return 0 ;
}
T_2 F_118 ( struct V_1 * V_2 , T_15 * V_239 )
{
return F_119 ( & V_2 -> V_21 , V_239 ) ;
}
T_2 F_120 ( struct V_1 * V_2 , T_15 * V_239 ,
bool (V_203)( struct V_240 * V_240 , int V_241 ) , int V_241 )
{
return F_121 ( & V_2 -> V_21 , V_239 , V_203 , V_241 ) ;
}
T_2 F_122 ( struct V_1 * V_19 , T_15 * V_239 )
{
struct V_57 * V_242 ;
T_2 V_22 = fprintf ( V_239 , L_61 ) ;
V_22 += F_123 ( & V_19 -> V_174 , V_239 ) ;
F_124 (pos, &session->evlist->entries, node) {
V_22 += fprintf ( V_239 , L_62 , F_125 ( V_242 ) ) ;
V_22 += F_123 ( & V_242 -> V_173 . V_174 , V_239 ) ;
}
return V_22 ;
}
T_2 F_126 ( struct V_1 * V_19 , T_15 * V_239 )
{
return F_127 ( & V_19 -> V_21 . V_23 , V_239 ) ;
}
void F_128 ( struct V_1 * V_19 ,
struct V_199 * V_243 )
{
F_129 ( & V_19 -> V_21 . V_23 , V_243 ) ;
}
struct V_57 * F_130 ( struct V_1 * V_19 ,
unsigned int type )
{
struct V_57 * V_242 ;
F_124 (pos, &session->evlist->entries, node) {
if ( V_242 -> V_67 . type == type )
return V_242 ;
}
return NULL ;
}
void F_131 ( struct V_57 * T_6 , union V_53 * T_3 ,
struct V_56 * T_5 , struct V_58 * V_58 ,
int V_244 , int V_245 , int V_246 )
{
struct V_247 V_248 ;
struct V_249 * V_250 ;
if ( F_132 ( T_3 , V_58 , & V_248 , T_5 ,
NULL ) < 0 ) {
error ( L_63 ,
T_3 -> V_52 . type ) ;
return;
}
if ( V_251 . V_252 && T_5 -> V_135 ) {
if ( F_133 ( V_58 , T_6 , V_248 . V_199 ,
T_5 , NULL ) != 0 ) {
if ( V_253 )
error ( L_64 ) ;
return;
}
F_134 ( & V_254 ) ;
while ( 1 ) {
V_250 = F_135 ( & V_254 ) ;
if ( ! V_250 )
break;
printf ( L_65 V_137 , V_250 -> V_158 ) ;
if ( V_244 ) {
printf ( L_29 ) ;
F_136 ( V_250 -> V_255 , stdout ) ;
}
if ( V_245 ) {
printf ( L_66 ) ;
F_137 ( V_250 -> V_229 , stdout ) ;
printf ( L_67 ) ;
}
printf ( L_6 ) ;
F_138 ( & V_254 ) ;
}
} else {
printf ( L_68 V_137 , T_5 -> V_158 ) ;
if ( V_244 ) {
printf ( L_29 ) ;
if ( V_246 )
F_139 ( V_248 . V_255 , & V_248 ,
stdout ) ;
else
F_136 ( V_248 . V_255 , stdout ) ;
}
if ( V_245 ) {
printf ( L_66 ) ;
F_137 ( V_248 . V_229 , stdout ) ;
printf ( L_67 ) ;
}
}
}
int F_140 ( struct V_1 * V_19 ,
const char * V_256 , unsigned long * V_257 )
{
int V_93 ;
struct V_258 * V_229 ;
for ( V_93 = 0 ; V_93 < V_259 ; ++ V_93 ) {
struct V_57 * T_6 ;
T_6 = F_130 ( V_19 , V_93 ) ;
if ( ! T_6 )
continue;
if ( ! ( T_6 -> V_67 . V_97 & V_153 ) ) {
F_3 ( L_69
L_70 ) ;
return - 1 ;
}
}
V_229 = F_141 ( V_256 ) ;
if ( V_229 == NULL ) {
F_3 ( L_71 ) ;
return - 1 ;
}
for ( V_93 = 0 ; V_93 < V_229 -> V_136 ; V_93 ++ ) {
int V_154 = V_229 -> V_229 [ V_93 ] ;
if ( V_154 >= V_260 ) {
F_3 ( L_72
L_73 , V_154 ) ;
return - 1 ;
}
F_142 ( V_154 , V_257 ) ;
}
return 0 ;
}
void F_143 ( struct V_1 * V_19 , T_15 * V_239 ,
bool V_261 )
{
struct V_4 V_28 ;
int V_22 ;
if ( V_19 == NULL || V_239 == NULL )
return;
V_22 = F_5 ( V_19 -> V_8 , & V_28 ) ;
if ( V_22 == - 1 )
return;
fprintf ( V_239 , L_74 ) ;
fprintf ( V_239 , L_75 , ctime ( & V_28 . V_262 ) ) ;
F_144 ( V_19 , V_239 , V_261 ) ;
fprintf ( V_239 , L_76 ) ;
}
int F_145 ( struct V_1 * V_19 ,
const struct V_263 * V_264 ,
T_2 V_265 )
{
struct V_55 * V_17 = V_19 -> V_17 ;
struct V_266 * V_267 ;
struct V_57 * T_6 ;
char * V_268 , * V_236 ;
T_2 V_93 ;
int V_11 ;
for ( V_93 = 0 ; V_93 < V_265 ; V_93 ++ ) {
V_11 = - V_133 ;
V_268 = F_116 ( V_264 [ V_93 ] . V_236 ) ;
if ( V_268 == NULL )
goto V_31;
V_11 = - V_13 ;
V_236 = strchr ( V_268 , ':' ) ;
if ( V_236 == NULL )
goto V_269;
* V_236 ++ = '\0' ;
V_267 = F_146 ( V_19 -> V_270 ,
V_268 , V_236 ) ;
if ( V_267 == NULL ) {
goto V_107;
}
T_6 = F_147 ( V_17 , V_267 -> V_89 ) ;
if ( T_6 == NULL )
goto V_107;
V_11 = - V_271 ;
if ( T_6 -> V_272 . V_273 != NULL )
goto V_269;
T_6 -> V_272 . V_273 = V_264 [ V_93 ] . V_272 ;
V_107:
free ( V_268 ) ;
}
V_11 = 0 ;
V_31:
return V_11 ;
V_269:
free ( V_268 ) ;
goto V_31;
}
