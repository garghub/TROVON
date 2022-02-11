static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 V_5 ;
if ( ! strcmp ( V_2 -> V_6 , L_1 ) ) {
V_2 -> V_7 = true ;
V_2 -> V_8 = V_9 ;
if ( F_2 ( V_2 ) < 0 )
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
if ( F_2 ( V_2 ) < 0 ) {
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
if ( ! F_10 ( V_2 -> V_17 ) ) {
F_3 ( L_11 ) ;
goto V_14;
}
V_2 -> V_18 = V_5 . V_16 ;
return 0 ;
V_14:
F_11 ( V_2 -> V_8 ) ;
V_2 -> V_8 = - 1 ;
return - 1 ;
}
void F_12 ( struct V_1 * V_19 )
{
T_1 V_20 = F_13 ( V_19 -> V_17 ) ;
F_14 ( & V_19 -> V_21 , V_20 ) ;
}
int F_15 ( struct V_1 * V_2 )
{
int V_22 = F_16 ( & V_2 -> V_21 . V_23 ) ;
if ( V_22 >= 0 )
V_22 = F_17 ( & V_2 -> V_21 ) ;
return V_22 ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_19 ( & V_2 -> V_21 ) ;
}
struct V_1 * F_20 ( const char * V_6 , int V_24 ,
bool V_3 , bool V_25 ,
struct V_26 * V_27 )
{
struct V_1 * V_2 ;
struct V_4 V_28 ;
T_2 V_29 ;
if ( ! V_6 || ! strlen ( V_6 ) ) {
if ( ! F_5 ( V_9 , & V_28 ) && F_21 ( V_28 . V_30 ) )
V_6 = L_1 ;
else
V_6 = L_4 ;
}
V_29 = strlen ( V_6 ) ;
V_2 = F_22 ( sizeof( * V_2 ) + V_29 ) ;
if ( V_2 == NULL )
goto V_31;
memcpy ( V_2 -> V_6 , V_6 , V_29 ) ;
V_2 -> V_25 = V_25 ;
F_23 ( & V_2 -> V_32 . V_33 ) ;
F_23 ( & V_2 -> V_32 . V_34 ) ;
F_23 ( & V_2 -> V_32 . V_35 ) ;
F_24 ( & V_2 -> V_21 ) ;
if ( V_24 == V_10 ) {
if ( F_1 ( V_2 , V_3 ) < 0 )
goto V_36;
F_12 ( V_2 ) ;
} else if ( V_24 == V_37 ) {
if ( F_15 ( V_2 ) < 0 )
goto V_36;
}
if ( V_27 && V_27 -> V_38 &&
V_27 -> V_32 && ! F_25 ( V_2 -> V_17 ) ) {
F_26 ( L_12 ) ;
V_27 -> V_32 = false ;
}
V_31:
return V_2 ;
V_36:
F_27 ( V_2 ) ;
return NULL ;
}
static void F_28 ( struct V_1 * V_19 )
{
F_29 ( & V_19 -> V_21 . V_23 ) ;
}
static void F_30 ( struct V_1 * V_19 )
{
F_31 ( & V_19 -> V_21 . V_23 ) ;
}
static void F_32 ( struct V_39 * V_40 )
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
void F_27 ( struct V_1 * V_2 )
{
F_18 ( V_2 ) ;
F_28 ( V_2 ) ;
F_30 ( V_2 ) ;
F_32 ( & V_2 -> V_52 . V_40 ) ;
F_33 ( & V_2 -> V_21 ) ;
F_11 ( V_2 -> V_8 ) ;
free ( V_2 ) ;
F_34 () ;
}
static int F_35 ( struct V_26 * V_27
V_53 ,
union V_54 * T_3
V_53 ,
struct V_1 * V_19
V_53 )
{
F_26 ( L_13 ) ;
return 0 ;
}
static int F_36 ( struct V_26 * V_27 V_53 ,
union V_54 * T_3 V_53 ,
struct V_55 * * T_4
V_53 )
{
F_26 ( L_13 ) ;
return 0 ;
}
static int F_37 ( struct V_26 * V_27 V_53 ,
union V_54 * T_3 V_53 ,
struct V_56 * T_5 V_53 ,
struct V_57 * T_6 V_53 ,
struct V_58 * V_58 V_53 )
{
F_26 ( L_13 ) ;
return 0 ;
}
static int F_38 ( struct V_26 * V_27 V_53 ,
union V_54 * T_3 V_53 ,
struct V_56 * T_5 V_53 ,
struct V_58 * V_58 V_53 )
{
F_26 ( L_13 ) ;
return 0 ;
}
static int F_39 ( struct V_26 * V_27 V_53 ,
union V_54 * T_3 V_53 ,
struct V_1 * V_1
V_53 )
{
F_26 ( L_13 ) ;
return 0 ;
}
void F_40 ( struct V_26 * V_27 )
{
if ( V_27 -> T_5 == NULL )
V_27 -> T_5 = F_37 ;
if ( V_27 -> V_59 == NULL )
V_27 -> V_59 = F_38 ;
if ( V_27 -> V_60 == NULL )
V_27 -> V_60 = F_38 ;
if ( V_27 -> V_61 == NULL )
V_27 -> V_61 = F_38 ;
if ( V_27 -> V_62 == NULL )
V_27 -> V_62 = F_38 ;
if ( V_27 -> exit == NULL )
V_27 -> exit = F_38 ;
if ( V_27 -> V_63 == NULL )
V_27 -> V_63 = V_64 ;
if ( V_27 -> V_65 == NULL )
V_27 -> V_65 = F_37 ;
if ( V_27 -> V_66 == NULL )
V_27 -> V_66 = F_38 ;
if ( V_27 -> V_67 == NULL )
V_27 -> V_67 = F_38 ;
if ( V_27 -> V_68 == NULL )
V_27 -> V_68 = F_36 ;
if ( V_27 -> V_69 == NULL )
V_27 -> V_69 = F_35 ;
if ( V_27 -> V_70 == NULL )
V_27 -> V_70 = F_39 ;
if ( V_27 -> V_71 == NULL ) {
if ( V_27 -> V_32 )
V_27 -> V_71 = V_72 ;
else
V_27 -> V_71 = F_39 ;
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
static void F_45 ( union V_54 * T_3 , void * V_76 )
{
void * V_77 = ( void * ) T_3 + T_3 -> V_52 . V_18 ;
int V_18 = V_77 - V_76 ;
F_46 ( V_18 % sizeof( T_8 ) ) ;
F_43 ( V_76 , V_18 ) ;
}
static void F_47 ( union V_54 * T_3 ,
bool T_9 V_53 )
{
struct V_78 * V_79 = & T_3 -> V_52 ;
F_43 ( V_79 + 1 , T_3 -> V_52 . V_18 - sizeof( * V_79 ) ) ;
}
static void F_48 ( union V_54 * T_3 , bool T_9 )
{
T_3 -> V_61 . V_80 = F_42 ( T_3 -> V_61 . V_80 ) ;
T_3 -> V_61 . V_81 = F_42 ( T_3 -> V_61 . V_81 ) ;
if ( T_9 ) {
void * V_76 = & T_3 -> V_61 . V_61 ;
V_76 += F_49 ( strlen ( V_76 ) + 1 , sizeof( T_8 ) ) ;
F_45 ( T_3 , V_76 ) ;
}
}
static void F_50 ( union V_54 * T_3 ,
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
static void F_51 ( union V_54 * T_3 ,
bool T_9 )
{
T_3 -> V_60 . V_80 = F_42 ( T_3 -> V_60 . V_80 ) ;
T_3 -> V_60 . V_81 = F_42 ( T_3 -> V_60 . V_81 ) ;
T_3 -> V_60 . V_82 = F_44 ( T_3 -> V_60 . V_82 ) ;
T_3 -> V_60 . V_29 = F_44 ( T_3 -> V_60 . V_29 ) ;
T_3 -> V_60 . V_83 = F_44 ( T_3 -> V_60 . V_83 ) ;
T_3 -> V_60 . V_84 = F_42 ( T_3 -> V_60 . V_84 ) ;
T_3 -> V_60 . V_85 = F_42 ( T_3 -> V_60 . V_85 ) ;
T_3 -> V_60 . V_86 = F_44 ( T_3 -> V_60 . V_86 ) ;
if ( T_9 ) {
void * V_76 = & T_3 -> V_60 . V_6 ;
V_76 += F_49 ( strlen ( V_76 ) + 1 , sizeof( T_8 ) ) ;
F_45 ( T_3 , V_76 ) ;
}
}
static void F_52 ( union V_54 * T_3 , bool T_9 )
{
T_3 -> V_62 . V_80 = F_42 ( T_3 -> V_62 . V_80 ) ;
T_3 -> V_62 . V_81 = F_42 ( T_3 -> V_62 . V_81 ) ;
T_3 -> V_62 . V_87 = F_42 ( T_3 -> V_62 . V_87 ) ;
T_3 -> V_62 . V_88 = F_42 ( T_3 -> V_62 . V_88 ) ;
T_3 -> V_62 . time = F_44 ( T_3 -> V_62 . time ) ;
if ( T_9 )
F_45 ( T_3 , & T_3 -> V_62 + 1 ) ;
}
static void F_53 ( union V_54 * T_3 , bool T_9 )
{
T_3 -> V_65 . V_80 = F_42 ( T_3 -> V_65 . V_80 ) ;
T_3 -> V_65 . V_81 = F_42 ( T_3 -> V_65 . V_81 ) ;
T_3 -> V_65 . V_89 = F_44 ( T_3 -> V_65 . V_89 ) ;
T_3 -> V_65 . V_90 = F_44 ( T_3 -> V_65 . V_90 ) ;
T_3 -> V_65 . V_91 = F_44 ( T_3 -> V_65 . V_91 ) ;
T_3 -> V_65 . V_92 = F_44 ( T_3 -> V_65 . V_92 ) ;
if ( T_9 )
F_45 ( T_3 , & T_3 -> V_65 + 1 ) ;
}
static T_10 F_54 ( T_10 V_93 )
{
int V_94 = ( V_93 >> 4 ) | ( ( V_93 & 0xf ) << 4 ) ;
V_94 = ( ( V_94 & 0xcc ) >> 2 ) | ( ( V_94 & 0x33 ) << 2 ) ;
V_94 = ( ( V_94 & 0xaa ) >> 1 ) | ( ( V_94 & 0x55 ) << 1 ) ;
return ( T_10 ) V_94 ;
}
static void F_55 ( T_10 * V_95 , unsigned V_29 )
{
unsigned V_96 ;
for ( V_96 = 0 ; V_96 < V_29 ; V_96 ++ ) {
* V_95 = F_54 ( * V_95 ) ;
V_95 ++ ;
}
}
void F_56 ( struct V_97 * V_68 )
{
V_68 -> type = F_42 ( V_68 -> type ) ;
V_68 -> V_18 = F_42 ( V_68 -> V_18 ) ;
V_68 -> V_98 = F_44 ( V_68 -> V_98 ) ;
V_68 -> V_99 = F_44 ( V_68 -> V_99 ) ;
V_68 -> V_100 = F_44 ( V_68 -> V_100 ) ;
V_68 -> V_101 = F_44 ( V_68 -> V_101 ) ;
V_68 -> V_102 = F_42 ( V_68 -> V_102 ) ;
V_68 -> V_103 = F_42 ( V_68 -> V_103 ) ;
V_68 -> V_104 = F_44 ( V_68 -> V_104 ) ;
V_68 -> V_105 = F_44 ( V_68 -> V_105 ) ;
F_55 ( ( T_10 * ) ( & V_68 -> V_101 + 1 ) , sizeof( T_8 ) ) ;
}
static void F_57 ( union V_54 * T_3 ,
bool T_9 V_53 )
{
T_2 V_18 ;
F_56 ( & T_3 -> V_68 . V_68 ) ;
V_18 = T_3 -> V_52 . V_18 ;
V_18 -= ( void * ) & T_3 -> V_68 . V_92 - ( void * ) T_3 ;
F_43 ( T_3 -> V_68 . V_92 , V_18 ) ;
}
static void F_58 ( union V_54 * T_3 ,
bool T_9 V_53 )
{
T_3 -> V_106 . V_106 . V_107 =
F_44 ( T_3 -> V_106 . V_106 . V_107 ) ;
}
static void F_59 ( union V_54 * T_3 ,
bool T_9 V_53 )
{
T_3 -> V_69 . V_18 = F_42 ( T_3 -> V_69 . V_18 ) ;
}
static void F_60 ( struct V_1 * V_19 )
{
struct V_32 * V_108 = & V_19 -> V_32 ;
while ( ! F_61 ( & V_108 -> V_35 ) ) {
struct V_109 * V_110 ;
V_110 = F_62 ( V_108 -> V_35 . V_111 , struct V_109 , V_112 ) ;
F_63 ( & V_110 -> V_112 ) ;
free ( V_110 ) ;
}
}
static int F_64 ( struct V_1 * V_113 ,
struct V_26 * V_27 )
{
struct V_32 * V_108 = & V_113 -> V_32 ;
struct V_114 * V_115 = & V_108 -> V_33 ;
struct V_109 * V_116 , * V_117 ;
struct V_56 T_5 ;
T_8 V_118 = V_108 -> V_119 ;
T_8 V_120 = V_108 -> V_121 ? V_108 -> V_121 -> V_122 : 0ULL ;
unsigned V_123 = 0 , V_124 = V_108 -> V_125 / 16 ;
bool V_126 = V_118 == V_127 ;
int V_22 ;
if ( ! V_27 -> V_32 || ! V_118 )
return 0 ;
F_65 (iter, tmp, head, list) {
if ( F_66 () )
return 0 ;
if ( V_117 -> V_122 > V_118 )
break;
V_22 = F_67 ( V_113 -> V_17 , V_117 -> T_3 , & T_5 ) ;
if ( V_22 )
F_3 ( L_14 , V_22 ) ;
else {
V_22 = F_68 ( V_113 , V_117 -> T_3 , & T_5 , V_27 ,
V_117 -> V_128 ) ;
if ( V_22 )
return V_22 ;
}
V_108 -> V_129 = V_117 -> V_122 ;
F_63 ( & V_117 -> V_112 ) ;
F_69 ( & V_117 -> V_112 , & V_108 -> V_34 ) ;
if ( V_126 && ( ++ V_123 >= V_124 ) ) {
V_124 += V_108 -> V_125 / 16 ;
F_70 ( V_123 , V_108 -> V_125 ,
L_15 ) ;
}
}
if ( F_61 ( V_115 ) ) {
V_108 -> V_121 = NULL ;
} else if ( V_120 <= V_118 ) {
V_108 -> V_121 =
F_62 ( V_115 -> V_130 , struct V_109 , V_112 ) ;
}
V_108 -> V_125 = 0 ;
return 0 ;
}
static int V_72 ( struct V_26 * V_27 ,
union V_54 * T_3 V_53 ,
struct V_1 * V_19 )
{
int V_22 = F_64 ( V_19 , V_27 ) ;
if ( ! V_22 )
V_19 -> V_32 . V_119 = V_19 -> V_32 . V_131 ;
return V_22 ;
}
static void F_71 ( struct V_109 * V_132 , struct V_1 * V_113 )
{
struct V_32 * V_108 = & V_113 -> V_32 ;
struct V_109 * T_5 = V_108 -> V_121 ;
T_8 V_122 = V_132 -> V_122 ;
struct V_114 * V_95 ;
++ V_108 -> V_125 ;
V_108 -> V_121 = V_132 ;
if ( ! T_5 ) {
F_69 ( & V_132 -> V_112 , & V_108 -> V_33 ) ;
V_108 -> V_131 = V_122 ;
return;
}
if ( T_5 -> V_122 <= V_122 ) {
while ( T_5 -> V_122 <= V_122 ) {
V_95 = T_5 -> V_112 . V_111 ;
if ( V_95 == & V_108 -> V_33 ) {
F_72 ( & V_132 -> V_112 , & V_108 -> V_33 ) ;
V_108 -> V_131 = V_122 ;
return;
}
T_5 = F_62 ( V_95 , struct V_109 , V_112 ) ;
}
F_72 ( & V_132 -> V_112 , & T_5 -> V_112 ) ;
} else {
while ( T_5 -> V_122 > V_122 ) {
V_95 = T_5 -> V_112 . V_130 ;
if ( V_95 == & V_108 -> V_33 ) {
F_69 ( & V_132 -> V_112 , & V_108 -> V_33 ) ;
return;
}
T_5 = F_62 ( V_95 , struct V_109 , V_112 ) ;
}
F_69 ( & V_132 -> V_112 , & T_5 -> V_112 ) ;
}
}
int F_73 ( struct V_1 * V_113 , union V_54 * T_3 ,
struct V_56 * T_5 , T_8 V_128 )
{
struct V_32 * V_108 = & V_113 -> V_32 ;
struct V_114 * V_133 = & V_108 -> V_34 ;
T_8 V_122 = T_5 -> time ;
struct V_109 * V_132 ;
if ( ! V_122 || V_122 == ~ 0ULL )
return - V_134 ;
if ( V_122 < V_113 -> V_32 . V_129 ) {
printf ( L_16 ) ;
return - V_135 ;
}
if ( ! F_61 ( V_133 ) ) {
V_132 = F_62 ( V_133 -> V_111 , struct V_109 , V_112 ) ;
F_63 ( & V_132 -> V_112 ) ;
} else if ( V_108 -> V_136 ) {
V_132 = V_108 -> V_136 + V_108 -> V_137 ;
if ( ++ V_108 -> V_137 == V_138 )
V_108 -> V_136 = NULL ;
} else {
V_108 -> V_136 = malloc ( V_138 * sizeof( * V_132 ) ) ;
if ( ! V_108 -> V_136 )
return - V_139 ;
F_69 ( & V_108 -> V_136 -> V_112 , & V_108 -> V_35 ) ;
V_108 -> V_137 = 2 ;
V_132 = V_108 -> V_136 + 1 ;
}
V_132 -> V_122 = V_122 ;
V_132 -> V_128 = V_128 ;
V_132 -> T_3 = T_3 ;
F_71 ( V_132 , V_113 ) ;
return 0 ;
}
static void F_74 ( struct V_56 * T_5 )
{
unsigned int V_96 ;
printf ( L_17 V_140 L_6 , T_5 -> V_141 -> V_142 ) ;
for ( V_96 = 0 ; V_96 < T_5 -> V_141 -> V_142 ; V_96 ++ )
printf ( L_18 V_143 L_6 ,
V_96 , T_5 -> V_141 -> V_144 [ V_96 ] ) ;
}
static void F_75 ( struct V_56 * T_5 )
{
T_11 V_96 ;
printf ( L_19 V_140 L_6 , T_5 -> V_145 -> V_142 ) ;
for ( V_96 = 0 ; V_96 < T_5 -> V_145 -> V_142 ; V_96 ++ )
printf ( L_20 V_140 L_21 V_143 L_22 V_143 L_6 ,
V_96 , T_5 -> V_145 -> V_146 [ V_96 ] . V_147 ,
T_5 -> V_145 -> V_146 [ V_96 ] . V_148 ) ;
}
static void F_76 ( T_8 V_149 , T_8 * V_150 )
{
unsigned V_151 , V_96 = 0 ;
F_77 (rid, (unsigned long *) &mask, sizeof(mask) * 8 ) {
T_8 V_152 = V_150 [ V_96 ++ ] ;
printf ( L_23 V_143 L_6 ,
F_78 ( V_151 ) , V_152 ) ;
}
}
static void F_79 ( struct V_56 * T_5 , T_8 V_149 )
{
struct V_153 * V_154 = & T_5 -> V_154 ;
if ( V_154 -> V_150 ) {
printf ( L_24 V_143 L_6 , V_149 ) ;
F_76 ( V_149 , V_154 -> V_150 ) ;
}
}
static void F_80 ( struct V_155 * V_156 )
{
printf ( L_25 V_140 L_26 ,
V_156 -> V_18 , V_156 -> V_157 ) ;
}
static void F_81 ( struct V_1 * V_19 ,
union V_54 * T_3 ,
struct V_56 * T_5 )
{
T_8 V_100 = F_82 ( V_19 -> V_17 ) ;
if ( T_3 -> V_52 . type != V_158 &&
! F_25 ( V_19 -> V_17 ) ) {
fputs ( L_27 , stdout ) ;
return;
}
if ( ( V_100 & V_159 ) )
printf ( L_28 , T_5 -> V_160 ) ;
if ( V_100 & V_161 )
printf ( L_29 V_140 L_30 , T_5 -> time ) ;
}
static void F_83 ( struct V_56 * T_5 , T_8 V_101 )
{
printf ( L_31 ) ;
if ( V_101 & V_162 )
printf ( L_32 V_143 L_6 ,
T_5 -> V_65 . V_90 ) ;
if ( V_101 & V_163 )
printf ( L_33 V_143 L_6 ,
T_5 -> V_65 . V_91 ) ;
if ( V_101 & V_164 ) {
T_8 V_96 ;
printf ( L_34 V_140 L_6 , T_5 -> V_65 . V_165 . V_142 ) ;
for ( V_96 = 0 ; V_96 < T_5 -> V_65 . V_165 . V_142 ; V_96 ++ ) {
struct V_166 * V_89 ;
V_89 = & T_5 -> V_65 . V_165 . V_167 [ V_96 ] ;
printf ( L_35 V_143
L_36 V_143 L_6 ,
V_89 -> V_92 , V_89 -> V_89 ) ;
}
} else
printf ( L_35 V_143 L_36 V_143 L_6 ,
T_5 -> V_65 . V_168 . V_92 , T_5 -> V_65 . V_168 . V_89 ) ;
}
static void F_84 ( struct V_1 * V_19 , union V_54 * T_3 ,
T_8 V_128 , struct V_56 * T_5 )
{
if ( ! V_169 )
return;
printf ( L_37 V_143 L_38 ,
V_128 , T_3 -> V_52 . V_18 , T_3 -> V_52 . type ) ;
F_85 ( T_3 ) ;
if ( T_5 )
F_81 ( V_19 , T_3 , T_5 ) ;
printf ( L_39 V_143 L_40 , V_128 ,
T_3 -> V_52 . V_18 , F_86 ( T_3 -> V_52 . type ) ) ;
}
static void F_87 ( struct V_57 * T_6 , union V_54 * T_3 ,
struct V_56 * T_5 )
{
T_8 V_100 ;
if ( ! V_169 )
return;
printf ( L_41 V_143 L_42 V_140 L_43 V_143 L_6 ,
T_3 -> V_52 . V_170 , T_5 -> V_80 , T_5 -> V_81 , T_5 -> V_171 ,
T_5 -> V_172 , T_5 -> V_173 ) ;
V_100 = T_6 -> V_68 . V_100 ;
if ( V_100 & V_174 )
F_74 ( T_5 ) ;
if ( V_100 & V_175 )
F_75 ( T_5 ) ;
if ( V_100 & V_176 )
F_79 ( T_5 , T_6 -> V_68 . V_177 ) ;
if ( V_100 & V_178 )
F_80 ( & T_5 -> V_179 ) ;
if ( V_100 & V_180 )
printf ( L_44 V_140 L_6 , T_5 -> V_181 ) ;
if ( V_100 & V_182 )
printf ( L_45 V_143 L_6 , T_5 -> V_183 ) ;
if ( V_100 & V_184 )
F_83 ( T_5 , T_6 -> V_68 . V_101 ) ;
}
static struct V_58 *
F_88 ( struct V_1 * V_19 ,
union V_54 * T_3 ,
struct V_56 * T_5 )
{
const T_10 V_185 = T_3 -> V_52 . V_170 & V_186 ;
if ( V_187 &&
( ( V_185 == V_188 ) ||
( V_185 == V_189 ) ) ) {
T_7 V_80 ;
if ( T_3 -> V_52 . type == V_190
|| T_3 -> V_52 . type == V_191 )
V_80 = T_3 -> V_59 . V_80 ;
else
V_80 = T_5 -> V_80 ;
return F_89 ( V_19 , V_80 ) ;
}
return & V_19 -> V_21 . V_23 ;
}
static int F_90 ( struct V_1 * V_19 ,
struct V_26 * V_27 ,
union V_54 * T_3 ,
struct V_56 * T_5 ,
struct V_166 * V_192 ,
struct V_58 * V_58 )
{
struct V_193 * V_194 ;
V_194 = F_91 ( V_19 -> V_17 , V_192 -> V_92 ) ;
if ( V_194 ) {
T_5 -> V_92 = V_192 -> V_92 ;
T_5 -> V_172 = V_192 -> V_89 - V_194 -> V_172 ;
V_194 -> V_172 = V_192 -> V_89 ;
}
if ( ! V_194 || V_194 -> T_6 == NULL ) {
++ V_19 -> V_195 . V_196 ;
return 0 ;
}
return V_27 -> T_5 ( V_27 , T_3 , T_5 , V_194 -> T_6 , V_58 ) ;
}
static int F_92 ( struct V_1 * V_19 ,
struct V_26 * V_27 ,
union V_54 * T_3 ,
struct V_56 * T_5 ,
struct V_58 * V_58 )
{
int V_22 = - V_135 ;
T_8 V_96 ;
for ( V_96 = 0 ; V_96 < T_5 -> V_65 . V_165 . V_142 ; V_96 ++ ) {
V_22 = F_90 ( V_19 , V_27 , T_3 , T_5 ,
& T_5 -> V_65 . V_165 . V_167 [ V_96 ] ,
V_58 ) ;
if ( V_22 )
break;
}
return V_22 ;
}
static int
F_93 ( struct V_1 * V_19 ,
struct V_26 * V_27 ,
union V_54 * T_3 ,
struct V_56 * T_5 ,
struct V_57 * T_6 ,
struct V_58 * V_58 )
{
T_8 V_100 = T_6 -> V_68 . V_100 ;
T_8 V_101 = T_6 -> V_68 . V_101 ;
if ( ! ( V_100 & V_184 ) )
return V_27 -> T_5 ( V_27 , T_3 , T_5 , T_6 , V_58 ) ;
if ( V_101 & V_164 )
return F_92 ( V_19 , V_27 , T_3 , T_5 ,
V_58 ) ;
else
return F_90 ( V_19 , V_27 , T_3 , T_5 ,
& T_5 -> V_65 . V_168 , V_58 ) ;
}
static int F_68 ( struct V_1 * V_19 ,
union V_54 * T_3 ,
struct V_56 * T_5 ,
struct V_26 * V_27 ,
T_8 V_128 )
{
struct V_57 * T_6 ;
struct V_58 * V_58 ;
F_84 ( V_19 , T_3 , V_128 , T_5 ) ;
T_6 = F_94 ( V_19 -> V_17 , T_5 -> V_92 ) ;
if ( T_6 != NULL && T_3 -> V_52 . type != V_158 ) {
F_95 ( & T_6 -> V_197 , T_3 -> V_52 . type ) ;
}
V_58 = F_88 ( V_19 , T_3 ,
T_5 ) ;
switch ( T_3 -> V_52 . type ) {
case V_158 :
F_87 ( T_6 , T_3 , T_5 ) ;
if ( T_6 == NULL ) {
++ V_19 -> V_195 . V_196 ;
return 0 ;
}
if ( V_58 == NULL ) {
++ V_19 -> V_195 . V_198 ;
return 0 ;
}
return F_93 ( V_19 , V_27 , T_3 ,
T_5 , T_6 , V_58 ) ;
case V_190 :
return V_27 -> V_59 ( V_27 , T_3 , T_5 , V_58 ) ;
case V_191 :
return V_27 -> V_60 ( V_27 , T_3 , T_5 , V_58 ) ;
case V_199 :
return V_27 -> V_61 ( V_27 , T_3 , T_5 , V_58 ) ;
case V_200 :
return V_27 -> V_62 ( V_27 , T_3 , T_5 , V_58 ) ;
case V_201 :
return V_27 -> exit ( V_27 , T_3 , T_5 , V_58 ) ;
case V_202 :
if ( V_27 -> V_63 == V_64 )
V_19 -> V_195 . V_203 += T_3 -> V_63 . V_63 ;
return V_27 -> V_63 ( V_27 , T_3 , T_5 , V_58 ) ;
case V_204 :
return V_27 -> V_65 ( V_27 , T_3 , T_5 , T_6 , V_58 ) ;
case V_205 :
return V_27 -> V_66 ( V_27 , T_3 , T_5 , V_58 ) ;
case V_206 :
return V_27 -> V_67 ( V_27 , T_3 , T_5 , V_58 ) ;
default:
++ V_19 -> V_195 . V_207 ;
return - 1 ;
}
}
static int F_96 ( struct V_1 * V_19 , union V_54 * T_3 ,
struct V_26 * V_27 , T_8 V_128 )
{
int V_11 ;
F_84 ( V_19 , T_3 , V_128 , NULL ) ;
switch ( T_3 -> V_52 . type ) {
case V_208 :
V_11 = V_27 -> V_68 ( V_27 , T_3 , & V_19 -> V_17 ) ;
if ( V_11 == 0 )
F_12 ( V_19 ) ;
return V_11 ;
case V_209 :
F_97 ( V_19 -> V_8 , V_128 , V_210 ) ;
return V_27 -> V_69 ( V_27 , T_3 , V_19 ) ;
case V_211 :
return V_27 -> V_70 ( V_27 , T_3 , V_19 ) ;
case V_212 :
return V_27 -> V_71 ( V_27 , T_3 , V_19 ) ;
default:
return - V_135 ;
}
}
static void F_98 ( union V_54 * T_3 , bool T_9 )
{
T_12 V_213 ;
V_213 = V_214 [ T_3 -> V_52 . type ] ;
if ( V_213 )
V_213 ( T_3 , T_9 ) ;
}
static int F_99 ( struct V_1 * V_19 ,
union V_54 * T_3 ,
struct V_26 * V_27 ,
T_8 V_128 )
{
struct V_56 T_5 ;
int V_22 ;
if ( V_19 -> V_52 . V_215 )
F_98 ( T_3 , F_25 ( V_19 -> V_17 ) ) ;
if ( T_3 -> V_52 . type >= V_216 )
return - V_135 ;
F_100 ( & V_19 -> V_195 , T_3 -> V_52 . type ) ;
if ( T_3 -> V_52 . type >= V_217 )
return F_96 ( V_19 , T_3 , V_27 , V_128 ) ;
V_22 = F_67 ( V_19 -> V_17 , T_3 , & T_5 ) ;
if ( V_22 )
return V_22 ;
if ( V_27 -> V_32 ) {
V_22 = F_73 ( V_19 , T_3 , & T_5 ,
V_128 ) ;
if ( V_22 != - V_134 )
return V_22 ;
}
return F_68 ( V_19 , T_3 , & T_5 , V_27 ,
V_128 ) ;
}
void F_101 ( struct V_78 * V_2 )
{
V_2 -> type = F_42 ( V_2 -> type ) ;
V_2 -> V_170 = F_102 ( V_2 -> V_170 ) ;
V_2 -> V_18 = F_102 ( V_2 -> V_18 ) ;
}
struct V_218 * F_103 ( struct V_1 * V_19 , T_13 V_80 )
{
return F_104 ( & V_19 -> V_21 . V_23 , 0 , V_80 ) ;
}
static struct V_218 * F_105 ( struct V_1 * V_2 )
{
struct V_218 * V_218 = F_103 ( V_2 , 0 ) ;
if ( V_218 == NULL || F_106 ( V_218 , L_46 ) ) {
F_3 ( L_47 ) ;
V_218 = NULL ;
}
return V_218 ;
}
static void F_107 ( const struct V_1 * V_19 ,
const struct V_26 * V_27 )
{
if ( V_27 -> V_63 == V_64 &&
V_19 -> V_195 . V_219 [ V_202 ] != 0 ) {
F_108 ( L_48
L_49 ,
V_19 -> V_195 . V_219 [ 0 ] ,
V_19 -> V_195 . V_219 [ V_202 ] ) ;
}
if ( V_19 -> V_195 . V_207 != 0 ) {
F_108 ( L_50
L_51
L_52
L_53
L_54 ,
V_19 -> V_195 . V_207 ) ;
}
if ( V_19 -> V_195 . V_196 != 0 ) {
F_108 ( L_55 ,
V_19 -> V_195 . V_196 ) ;
}
if ( V_19 -> V_195 . V_220 != 0 ) {
F_108 ( L_56
L_57
L_58 ,
V_19 -> V_195 . V_220 ,
V_19 -> V_195 . V_219 [ V_158 ] ) ;
}
if ( V_19 -> V_195 . V_198 != 0 ) {
F_108 ( L_59
L_60 ,
V_19 -> V_195 . V_198 ) ;
}
}
static int F_109 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
union V_54 * T_3 ;
T_14 V_18 , V_221 = 0 ;
void * V_222 = NULL ;
int V_223 = 0 ;
T_8 V_115 ;
int V_11 ;
void * V_95 ;
F_40 ( V_27 ) ;
V_115 = 0 ;
V_221 = sizeof( union V_54 ) ;
V_222 = malloc ( V_221 ) ;
if ( ! V_222 )
return - V_12 ;
V_224:
T_3 = V_222 ;
V_11 = F_110 ( V_2 -> V_8 , T_3 , sizeof( struct V_78 ) ) ;
if ( V_11 <= 0 ) {
if ( V_11 == 0 )
goto V_225;
F_3 ( L_61 ) ;
goto V_226;
}
if ( V_2 -> V_52 . V_215 )
F_101 ( & T_3 -> V_52 ) ;
V_18 = T_3 -> V_52 . V_18 ;
if ( V_18 < sizeof( struct V_78 ) ) {
F_3 ( L_62 ) ;
goto V_226;
}
if ( V_18 > V_221 ) {
void * V_132 = realloc ( V_222 , V_18 ) ;
if ( ! V_132 ) {
F_3 ( L_63 ) ;
goto V_226;
}
V_222 = V_132 ;
V_221 = V_18 ;
T_3 = V_222 ;
}
V_95 = T_3 ;
V_95 += sizeof( struct V_78 ) ;
if ( V_18 - sizeof( struct V_78 ) ) {
V_11 = F_110 ( V_2 -> V_8 , V_95 , V_18 - sizeof( struct V_78 ) ) ;
if ( V_11 <= 0 ) {
if ( V_11 == 0 ) {
F_3 ( L_64 ) ;
goto V_225;
}
F_3 ( L_65 ) ;
goto V_226;
}
}
if ( ( V_223 = F_99 ( V_2 , T_3 , V_27 , V_115 ) ) < 0 ) {
F_3 ( L_39 V_143 L_66 ,
V_115 , T_3 -> V_52 . V_18 , T_3 -> V_52 . type ) ;
V_11 = - V_135 ;
goto V_226;
}
V_115 += V_18 ;
if ( V_223 > 0 )
V_115 += V_223 ;
if ( ! F_66 () )
goto V_224;
V_225:
V_11 = 0 ;
V_226:
free ( V_222 ) ;
F_107 ( V_2 , V_27 ) ;
F_60 ( V_2 ) ;
return V_11 ;
}
static union V_54 *
F_111 ( struct V_1 * V_19 ,
T_8 V_115 , T_2 V_227 , char * V_222 )
{
union V_54 * T_3 ;
if ( V_115 + sizeof( T_3 -> V_52 ) > V_227 )
return NULL ;
T_3 = (union V_54 * ) ( V_222 + V_115 ) ;
if ( V_19 -> V_52 . V_215 )
F_101 ( & T_3 -> V_52 ) ;
if ( V_115 + T_3 -> V_52 . V_18 > V_227 ) {
if ( V_19 -> V_52 . V_215 )
F_101 ( & T_3 -> V_52 ) ;
return NULL ;
}
return T_3 ;
}
int F_112 ( struct V_1 * V_19 ,
T_8 V_228 , T_8 V_229 ,
T_8 V_230 , struct V_26 * V_27 )
{
T_8 V_115 , V_231 , V_128 , V_232 , V_124 ;
int V_11 , V_233 , V_234 , V_235 = 0 ;
T_2 V_227 ;
char * V_222 , * V_236 [ V_237 ] ;
union V_54 * T_3 ;
T_14 V_18 ;
F_40 ( V_27 ) ;
V_231 = V_238 * ( V_228 / V_238 ) ;
V_128 = V_231 ;
V_115 = V_228 - V_231 ;
if ( V_229 && ( V_228 + V_229 < V_230 ) )
V_230 = V_228 + V_229 ;
V_124 = V_230 / 16 ;
V_227 = V_239 ;
if ( V_227 > V_230 )
V_227 = V_230 ;
memset ( V_236 , 0 , sizeof( V_236 ) ) ;
V_233 = V_240 ;
V_234 = V_241 ;
if ( V_19 -> V_52 . V_215 ) {
V_233 |= V_242 ;
V_234 = V_243 ;
}
V_244:
V_222 = V_59 ( NULL , V_227 , V_233 , V_234 , V_19 -> V_8 ,
V_128 ) ;
if ( V_222 == V_245 ) {
F_3 ( L_67 ) ;
V_11 = - V_12 ;
goto V_226;
}
V_236 [ V_235 ] = V_222 ;
V_235 = ( V_235 + 1 ) & ( F_113 ( V_236 ) - 1 ) ;
V_232 = V_128 + V_115 ;
V_224:
T_3 = F_111 ( V_19 , V_115 , V_227 , V_222 ) ;
if ( ! T_3 ) {
if ( V_236 [ V_235 ] ) {
F_114 ( V_236 [ V_235 ] , V_227 ) ;
V_236 [ V_235 ] = NULL ;
}
V_231 = V_238 * ( V_115 / V_238 ) ;
V_128 += V_231 ;
V_115 -= V_231 ;
goto V_244;
}
V_18 = T_3 -> V_52 . V_18 ;
if ( V_18 < sizeof( struct V_78 ) ||
F_99 ( V_19 , T_3 , V_27 , V_232 ) < 0 ) {
F_3 ( L_39 V_143 L_66 ,
V_128 + V_115 , T_3 -> V_52 . V_18 ,
T_3 -> V_52 . type ) ;
V_11 = - V_135 ;
goto V_226;
}
V_115 += V_18 ;
V_232 += V_18 ;
if ( V_232 >= V_124 ) {
V_124 += V_230 / 16 ;
F_70 ( V_232 , V_230 ,
L_68 ) ;
}
V_11 = 0 ;
if ( F_66 () )
goto V_226;
if ( V_232 < V_230 )
goto V_224;
V_19 -> V_32 . V_119 = V_127 ;
V_11 = F_64 ( V_19 , V_27 ) ;
V_226:
F_115 () ;
F_107 ( V_19 , V_27 ) ;
F_60 ( V_19 ) ;
return V_11 ;
}
int F_116 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
int V_11 ;
if ( F_105 ( V_2 ) == NULL )
return - V_139 ;
if ( ! V_2 -> V_7 )
V_11 = F_112 ( V_2 ,
V_2 -> V_52 . V_228 ,
V_2 -> V_52 . V_229 ,
V_2 -> V_18 , V_27 ) ;
else
V_11 = F_109 ( V_2 , V_27 ) ;
return V_11 ;
}
bool F_117 ( struct V_1 * V_19 , const char * V_246 )
{
struct V_57 * T_6 ;
F_118 (evsel, &session->evlist->entries, node) {
if ( T_6 -> V_68 . type == V_247 )
return true ;
}
F_3 ( L_69 , V_246 ) ;
return false ;
}
int F_119 ( struct V_248 * * V_249 ,
const char * V_250 , T_8 V_173 )
{
char * V_251 ;
enum V_252 V_96 ;
struct V_253 * V_254 ;
V_254 = F_22 ( sizeof( struct V_253 ) ) ;
if ( V_254 == NULL )
return - V_139 ;
V_254 -> V_255 = F_120 ( V_250 ) ;
if ( V_254 -> V_255 == NULL ) {
free ( V_254 ) ;
return - V_139 ;
}
V_251 = strchr ( V_254 -> V_255 , ']' ) ;
if ( V_251 )
* V_251 = '\0' ;
V_254 -> V_173 = V_173 ;
for ( V_96 = 0 ; V_96 < V_256 ; ++ V_96 ) {
struct V_257 * V_257 = F_121 ( V_249 [ V_96 ] ) ;
V_257 -> V_253 = V_254 ;
}
return 0 ;
}
T_2 F_122 ( struct V_1 * V_2 , T_15 * V_258 )
{
return F_123 ( & V_2 -> V_21 , V_258 ) ;
}
T_2 F_124 ( struct V_1 * V_2 , T_15 * V_258 ,
bool (V_223)( struct V_259 * V_259 , int V_260 ) , int V_260 )
{
return F_125 ( & V_2 -> V_21 , V_258 , V_223 , V_260 ) ;
}
T_2 F_126 ( struct V_1 * V_19 , T_15 * V_258 )
{
struct V_57 * V_261 ;
T_2 V_22 = fprintf ( V_258 , L_70 ) ;
V_22 += F_127 ( & V_19 -> V_195 , V_258 ) ;
F_118 (pos, &session->evlist->entries, node) {
V_22 += fprintf ( V_258 , L_71 , F_128 ( V_261 ) ) ;
V_22 += F_127 ( & V_261 -> V_197 . V_195 , V_258 ) ;
}
return V_22 ;
}
T_2 F_129 ( struct V_1 * V_19 , T_15 * V_258 )
{
return F_130 ( & V_19 -> V_21 . V_23 , V_258 ) ;
}
struct V_57 * F_131 ( struct V_1 * V_19 ,
unsigned int type )
{
struct V_57 * V_261 ;
F_118 (pos, &session->evlist->entries, node) {
if ( V_261 -> V_68 . type == type )
return V_261 ;
}
return NULL ;
}
void F_132 ( struct V_57 * T_6 , union V_54 * T_3 ,
struct V_56 * T_5 , struct V_58 * V_58 ,
unsigned int V_262 , unsigned int V_263 )
{
struct V_264 V_265 ;
struct V_266 * V_267 ;
int V_268 = V_262 & V_269 ;
int V_270 = V_262 & V_271 ;
int V_272 = V_262 & V_273 ;
int V_274 = V_262 & V_275 ;
int V_276 = V_262 & V_277 ;
char V_113 = V_276 ? ' ' : '\t' ;
if ( F_133 ( T_3 , V_58 , & V_265 , T_5 ) < 0 ) {
error ( L_72 ,
T_3 -> V_52 . type ) ;
return;
}
if ( V_278 . V_279 && T_5 -> V_141 ) {
if ( F_134 ( V_58 , T_6 , V_265 . V_218 ,
T_5 , NULL , NULL ) != 0 ) {
if ( V_280 )
error ( L_73 ) ;
return;
}
F_135 ( & V_281 ) ;
while ( V_263 ) {
V_267 = F_136 ( & V_281 ) ;
if ( ! V_267 )
break;
if ( V_268 )
printf ( L_74 V_143 , V_113 , V_267 -> V_171 ) ;
if ( V_270 ) {
printf ( L_30 ) ;
if ( V_274 ) {
V_265 . V_173 = V_267 -> V_171 ;
V_265 . V_248 = V_267 -> V_248 ;
F_137 ( V_267 -> V_282 , & V_265 , stdout ) ;
} else
F_138 ( V_267 -> V_282 , stdout ) ;
}
if ( V_272 ) {
printf ( L_75 ) ;
F_139 ( V_267 -> V_248 , stdout ) ;
printf ( L_76 ) ;
}
if ( ! V_276 )
printf ( L_6 ) ;
F_140 ( & V_281 ) ;
V_263 -- ;
}
} else {
if ( V_268 )
printf ( L_77 V_143 , T_5 -> V_171 ) ;
if ( V_270 ) {
printf ( L_30 ) ;
if ( V_274 )
F_137 ( V_265 . V_282 , & V_265 ,
stdout ) ;
else
F_138 ( V_265 . V_282 , stdout ) ;
}
if ( V_272 ) {
printf ( L_75 ) ;
F_139 ( V_265 . V_248 , stdout ) ;
printf ( L_76 ) ;
}
}
}
int F_141 ( struct V_1 * V_19 ,
const char * V_283 , unsigned long * V_284 )
{
int V_96 ;
struct V_285 * V_248 ;
for ( V_96 = 0 ; V_96 < V_286 ; ++ V_96 ) {
struct V_57 * T_6 ;
T_6 = F_131 ( V_19 , V_96 ) ;
if ( ! T_6 )
continue;
if ( ! ( T_6 -> V_68 . V_100 & V_159 ) ) {
F_3 ( L_78
L_79 ) ;
return - 1 ;
}
}
V_248 = F_142 ( V_283 ) ;
if ( V_248 == NULL ) {
F_3 ( L_80 ) ;
return - 1 ;
}
for ( V_96 = 0 ; V_96 < V_248 -> V_142 ; V_96 ++ ) {
int V_160 = V_248 -> V_248 [ V_96 ] ;
if ( V_160 >= V_287 ) {
F_3 ( L_81
L_82 , V_160 ) ;
return - 1 ;
}
F_143 ( V_160 , V_284 ) ;
}
return 0 ;
}
void F_144 ( struct V_1 * V_19 , T_15 * V_258 ,
bool V_288 )
{
struct V_4 V_28 ;
int V_22 ;
if ( V_19 == NULL || V_258 == NULL )
return;
V_22 = F_5 ( V_19 -> V_8 , & V_28 ) ;
if ( V_22 == - 1 )
return;
fprintf ( V_258 , L_83 ) ;
fprintf ( V_258 , L_84 , ctime ( & V_28 . V_289 ) ) ;
F_145 ( V_19 , V_258 , V_288 ) ;
fprintf ( V_258 , L_85 ) ;
}
int F_146 ( struct V_1 * V_19 ,
const struct V_290 * V_291 ,
T_2 V_292 )
{
struct V_57 * T_6 ;
T_2 V_96 ;
int V_11 ;
for ( V_96 = 0 ; V_96 < V_292 ; V_96 ++ ) {
T_6 = F_147 ( V_19 -> V_17 , V_291 [ V_96 ] . V_255 ) ;
if ( T_6 == NULL )
continue;
V_11 = - V_293 ;
if ( T_6 -> V_294 . V_295 != NULL )
goto V_31;
T_6 -> V_294 . V_295 = V_291 [ V_96 ] . V_294 ;
}
V_11 = 0 ;
V_31:
return V_11 ;
}
