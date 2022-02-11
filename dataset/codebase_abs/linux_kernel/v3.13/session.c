static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( F_2 ( V_2 ) < 0 ) {
F_3 ( L_1 ) ;
return - 1 ;
}
if ( F_4 ( V_4 ) )
return 0 ;
if ( ! F_5 ( V_2 -> V_5 ) ) {
F_3 ( L_2 ) ;
return - 1 ;
}
if ( ! F_6 ( V_2 -> V_5 ) ) {
F_3 ( L_3 ) ;
return - 1 ;
}
if ( ! F_7 ( V_2 -> V_5 ) ) {
F_3 ( L_4 ) ;
return - 1 ;
}
return 0 ;
}
void F_8 ( struct V_1 * V_2 )
{
T_1 V_6 = F_9 ( V_2 -> V_5 ) ;
F_10 ( & V_2 -> V_7 , V_6 ) ;
}
int F_11 ( struct V_1 * V_2 )
{
int V_8 = F_12 ( & V_2 -> V_7 . V_9 ) ;
if ( V_8 >= 0 )
V_8 = F_13 ( & V_2 -> V_7 ) ;
return V_8 ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_15 ( & V_2 -> V_7 ) ;
}
struct V_1 * F_16 ( struct V_3 * V_4 ,
bool V_10 , struct V_11 * V_12 )
{
struct V_1 * V_2 = F_17 ( sizeof( * V_2 ) ) ;
if ( ! V_2 )
goto V_13;
V_2 -> V_10 = V_10 ;
F_18 ( & V_2 -> V_14 . V_15 ) ;
F_18 ( & V_2 -> V_14 . V_16 ) ;
F_18 ( & V_2 -> V_14 . V_17 ) ;
F_19 ( & V_2 -> V_7 ) ;
if ( V_4 ) {
if ( F_20 ( V_4 ) )
goto V_18;
V_2 -> V_4 = V_4 ;
if ( F_21 ( V_4 ) ) {
if ( F_1 ( V_2 ) < 0 )
goto V_19;
F_8 ( V_2 ) ;
}
}
if ( ! V_4 || F_22 ( V_4 ) ) {
if ( F_11 ( V_2 ) < 0 )
goto V_18;
}
if ( V_12 && V_12 -> V_20 &&
V_12 -> V_14 && ! F_23 ( V_2 -> V_5 ) ) {
F_24 ( L_5 ) ;
V_12 -> V_14 = false ;
}
return V_2 ;
V_19:
F_25 ( V_4 ) ;
V_18:
F_26 ( V_2 ) ;
V_13:
return NULL ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_28 ( & V_2 -> V_7 . V_9 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_30 ( & V_2 -> V_7 . V_9 ) ;
}
static void F_31 ( struct V_21 * V_22 )
{
free ( V_22 -> V_23 ) ;
free ( V_22 -> V_24 ) ;
free ( V_22 -> V_25 ) ;
free ( V_22 -> V_26 ) ;
free ( V_22 -> V_27 ) ;
free ( V_22 -> V_28 ) ;
free ( V_22 -> V_29 ) ;
free ( V_22 -> V_30 ) ;
free ( V_22 -> V_31 ) ;
free ( V_22 -> V_32 ) ;
free ( V_22 -> V_33 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
F_14 ( V_2 ) ;
F_27 ( V_2 ) ;
F_29 ( V_2 ) ;
F_31 ( & V_2 -> V_34 . V_22 ) ;
F_32 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_4 )
F_25 ( V_2 -> V_4 ) ;
free ( V_2 ) ;
F_33 () ;
}
static int F_34 ( struct V_11 * V_12
V_35 ,
union V_36 * T_2
V_35 ,
struct V_1 * V_2
V_35 )
{
F_24 ( L_6 ) ;
return 0 ;
}
static int F_35 ( struct V_11 * V_12 V_35 ,
union V_36 * T_2 V_35 ,
struct V_37 * * T_3
V_35 )
{
F_24 ( L_6 ) ;
return 0 ;
}
static int F_36 ( struct V_11 * V_12 V_35 ,
union V_36 * T_2 V_35 ,
struct V_38 * T_4 V_35 ,
struct V_39 * T_5 V_35 ,
struct V_40 * V_40 V_35 )
{
F_24 ( L_6 ) ;
return 0 ;
}
static int F_37 ( struct V_11 * V_12 V_35 ,
union V_36 * T_2 V_35 ,
struct V_38 * T_4 V_35 ,
struct V_40 * V_40 V_35 )
{
F_24 ( L_6 ) ;
return 0 ;
}
static int F_38 ( struct V_11 * V_12 V_35 ,
union V_36 * T_2 V_35 ,
struct V_1 * V_1
V_35 )
{
F_24 ( L_6 ) ;
return 0 ;
}
void F_39 ( struct V_11 * V_12 )
{
if ( V_12 -> T_4 == NULL )
V_12 -> T_4 = F_36 ;
if ( V_12 -> V_41 == NULL )
V_12 -> V_41 = F_37 ;
if ( V_12 -> V_42 == NULL )
V_12 -> V_42 = F_37 ;
if ( V_12 -> V_43 == NULL )
V_12 -> V_43 = F_37 ;
if ( V_12 -> V_44 == NULL )
V_12 -> V_44 = F_37 ;
if ( V_12 -> exit == NULL )
V_12 -> exit = F_37 ;
if ( V_12 -> V_45 == NULL )
V_12 -> V_45 = V_46 ;
if ( V_12 -> V_47 == NULL )
V_12 -> V_47 = F_36 ;
if ( V_12 -> V_48 == NULL )
V_12 -> V_48 = F_37 ;
if ( V_12 -> V_49 == NULL )
V_12 -> V_49 = F_37 ;
if ( V_12 -> V_50 == NULL )
V_12 -> V_50 = F_35 ;
if ( V_12 -> V_51 == NULL )
V_12 -> V_51 = F_34 ;
if ( V_12 -> V_52 == NULL )
V_12 -> V_52 = F_38 ;
if ( V_12 -> V_53 == NULL ) {
if ( V_12 -> V_14 )
V_12 -> V_53 = V_54 ;
else
V_12 -> V_53 = F_38 ;
}
}
void F_40 ( void * V_55 , int V_56 )
{
T_6 * V_57 = V_55 ;
while ( V_56 > 0 ) {
* V_57 = F_41 ( * V_57 ) ;
V_56 -= sizeof( T_6 ) ;
++ V_57 ;
}
}
void F_42 ( void * V_55 , int V_56 )
{
T_7 * V_57 = V_55 ;
while ( V_56 > 0 ) {
* V_57 = F_43 ( * V_57 ) ;
V_56 -= sizeof( T_7 ) ;
++ V_57 ;
}
}
static void F_44 ( union V_36 * T_2 , void * V_58 )
{
void * V_59 = ( void * ) T_2 + T_2 -> V_34 . V_60 ;
int V_60 = V_59 - V_58 ;
F_45 ( V_60 % sizeof( T_7 ) ) ;
F_42 ( V_58 , V_60 ) ;
}
static void F_46 ( union V_36 * T_2 ,
bool T_8 V_35 )
{
struct V_61 * V_62 = & T_2 -> V_34 ;
F_42 ( V_62 + 1 , T_2 -> V_34 . V_60 - sizeof( * V_62 ) ) ;
}
static void F_47 ( union V_36 * T_2 , bool T_8 )
{
T_2 -> V_43 . V_63 = F_41 ( T_2 -> V_43 . V_63 ) ;
T_2 -> V_43 . V_64 = F_41 ( T_2 -> V_43 . V_64 ) ;
if ( T_8 ) {
void * V_58 = & T_2 -> V_43 . V_43 ;
V_58 += F_48 ( strlen ( V_58 ) + 1 , sizeof( T_7 ) ) ;
F_44 ( T_2 , V_58 ) ;
}
}
static void F_49 ( union V_36 * T_2 ,
bool T_8 )
{
T_2 -> V_41 . V_63 = F_41 ( T_2 -> V_41 . V_63 ) ;
T_2 -> V_41 . V_64 = F_41 ( T_2 -> V_41 . V_64 ) ;
T_2 -> V_41 . V_65 = F_43 ( T_2 -> V_41 . V_65 ) ;
T_2 -> V_41 . V_66 = F_43 ( T_2 -> V_41 . V_66 ) ;
T_2 -> V_41 . V_67 = F_43 ( T_2 -> V_41 . V_67 ) ;
if ( T_8 ) {
void * V_58 = & T_2 -> V_41 . V_68 ;
V_58 += F_48 ( strlen ( V_58 ) + 1 , sizeof( T_7 ) ) ;
F_44 ( T_2 , V_58 ) ;
}
}
static void F_50 ( union V_36 * T_2 ,
bool T_8 )
{
T_2 -> V_42 . V_63 = F_41 ( T_2 -> V_42 . V_63 ) ;
T_2 -> V_42 . V_64 = F_41 ( T_2 -> V_42 . V_64 ) ;
T_2 -> V_42 . V_65 = F_43 ( T_2 -> V_42 . V_65 ) ;
T_2 -> V_42 . V_66 = F_43 ( T_2 -> V_42 . V_66 ) ;
T_2 -> V_42 . V_67 = F_43 ( T_2 -> V_42 . V_67 ) ;
T_2 -> V_42 . V_69 = F_41 ( T_2 -> V_42 . V_69 ) ;
T_2 -> V_42 . V_70 = F_41 ( T_2 -> V_42 . V_70 ) ;
T_2 -> V_42 . V_71 = F_43 ( T_2 -> V_42 . V_71 ) ;
if ( T_8 ) {
void * V_58 = & T_2 -> V_42 . V_68 ;
V_58 += F_48 ( strlen ( V_58 ) + 1 , sizeof( T_7 ) ) ;
F_44 ( T_2 , V_58 ) ;
}
}
static void F_51 ( union V_36 * T_2 , bool T_8 )
{
T_2 -> V_44 . V_63 = F_41 ( T_2 -> V_44 . V_63 ) ;
T_2 -> V_44 . V_64 = F_41 ( T_2 -> V_44 . V_64 ) ;
T_2 -> V_44 . V_72 = F_41 ( T_2 -> V_44 . V_72 ) ;
T_2 -> V_44 . V_73 = F_41 ( T_2 -> V_44 . V_73 ) ;
T_2 -> V_44 . time = F_43 ( T_2 -> V_44 . time ) ;
if ( T_8 )
F_44 ( T_2 , & T_2 -> V_44 + 1 ) ;
}
static void F_52 ( union V_36 * T_2 , bool T_8 )
{
T_2 -> V_47 . V_63 = F_41 ( T_2 -> V_47 . V_63 ) ;
T_2 -> V_47 . V_64 = F_41 ( T_2 -> V_47 . V_64 ) ;
T_2 -> V_47 . V_74 = F_43 ( T_2 -> V_47 . V_74 ) ;
T_2 -> V_47 . V_75 = F_43 ( T_2 -> V_47 . V_75 ) ;
T_2 -> V_47 . V_76 = F_43 ( T_2 -> V_47 . V_76 ) ;
T_2 -> V_47 . V_77 = F_43 ( T_2 -> V_47 . V_77 ) ;
if ( T_8 )
F_44 ( T_2 , & T_2 -> V_47 + 1 ) ;
}
static void F_53 ( union V_36 * T_2 ,
bool T_8 )
{
T_2 -> V_48 . time = F_43 ( T_2 -> V_48 . time ) ;
T_2 -> V_48 . V_77 = F_43 ( T_2 -> V_48 . V_77 ) ;
T_2 -> V_48 . V_78 = F_43 ( T_2 -> V_48 . V_78 ) ;
if ( T_8 )
F_44 ( T_2 , & T_2 -> V_48 + 1 ) ;
}
static T_9 F_54 ( T_9 V_79 )
{
int V_80 = ( V_79 >> 4 ) | ( ( V_79 & 0xf ) << 4 ) ;
V_80 = ( ( V_80 & 0xcc ) >> 2 ) | ( ( V_80 & 0x33 ) << 2 ) ;
V_80 = ( ( V_80 & 0xaa ) >> 1 ) | ( ( V_80 & 0x55 ) << 1 ) ;
return ( T_9 ) V_80 ;
}
static void F_55 ( T_9 * V_81 , unsigned V_66 )
{
unsigned V_82 ;
for ( V_82 = 0 ; V_82 < V_66 ; V_82 ++ ) {
* V_81 = F_54 ( * V_81 ) ;
V_81 ++ ;
}
}
void F_56 ( struct V_83 * V_50 )
{
V_50 -> type = F_41 ( V_50 -> type ) ;
V_50 -> V_60 = F_41 ( V_50 -> V_60 ) ;
V_50 -> V_84 = F_43 ( V_50 -> V_84 ) ;
V_50 -> V_85 = F_43 ( V_50 -> V_85 ) ;
V_50 -> V_86 = F_43 ( V_50 -> V_86 ) ;
V_50 -> V_87 = F_43 ( V_50 -> V_87 ) ;
V_50 -> V_88 = F_41 ( V_50 -> V_88 ) ;
V_50 -> V_89 = F_41 ( V_50 -> V_89 ) ;
V_50 -> V_90 = F_43 ( V_50 -> V_90 ) ;
V_50 -> V_91 = F_43 ( V_50 -> V_91 ) ;
V_50 -> V_92 = F_43 ( V_50 -> V_92 ) ;
V_50 -> V_93 = F_43 ( V_50 -> V_93 ) ;
V_50 -> V_94 = F_41 ( V_50 -> V_94 ) ;
F_55 ( ( T_9 * ) ( & V_50 -> V_87 + 1 ) , sizeof( T_7 ) ) ;
}
static void F_57 ( union V_36 * T_2 ,
bool T_8 V_35 )
{
T_10 V_60 ;
F_56 ( & T_2 -> V_50 . V_50 ) ;
V_60 = T_2 -> V_34 . V_60 ;
V_60 -= ( void * ) & T_2 -> V_50 . V_77 - ( void * ) T_2 ;
F_42 ( T_2 -> V_50 . V_77 , V_60 ) ;
}
static void F_58 ( union V_36 * T_2 ,
bool T_8 V_35 )
{
T_2 -> V_95 . V_95 . V_96 =
F_43 ( T_2 -> V_95 . V_95 . V_96 ) ;
}
static void F_59 ( union V_36 * T_2 ,
bool T_8 V_35 )
{
T_2 -> V_51 . V_60 = F_41 ( T_2 -> V_51 . V_60 ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_14 * V_97 = & V_2 -> V_14 ;
while ( ! F_61 ( & V_97 -> V_17 ) ) {
struct V_98 * V_99 ;
V_99 = F_62 ( V_97 -> V_17 . V_100 , struct V_98 , V_101 ) ;
F_63 ( & V_99 -> V_101 ) ;
free ( V_99 ) ;
}
}
static int F_64 ( struct V_1 * V_102 ,
struct V_11 * V_12 )
{
struct V_14 * V_97 = & V_102 -> V_14 ;
struct V_103 * V_104 = & V_97 -> V_15 ;
struct V_98 * V_105 , * V_106 ;
struct V_38 T_4 ;
T_7 V_107 = V_97 -> V_108 ;
T_7 V_109 = V_97 -> V_110 ? V_97 -> V_110 -> V_111 : 0ULL ;
bool V_112 = V_107 == V_113 ;
struct V_114 V_115 ;
int V_8 ;
if ( ! V_12 -> V_14 || ! V_107 )
return 0 ;
if ( V_112 )
F_65 ( & V_115 , V_97 -> V_116 , L_7 ) ;
F_66 (iter, tmp, head, list) {
if ( F_67 () )
return 0 ;
if ( V_106 -> V_111 > V_107 )
break;
V_8 = F_68 ( V_102 -> V_5 , V_106 -> T_2 , & T_4 ) ;
if ( V_8 )
F_3 ( L_8 , V_8 ) ;
else {
V_8 = F_69 ( V_102 , V_106 -> T_2 , & T_4 , V_12 ,
V_106 -> V_117 ) ;
if ( V_8 )
return V_8 ;
}
V_97 -> V_118 = V_106 -> V_111 ;
F_63 ( & V_106 -> V_101 ) ;
F_70 ( & V_106 -> V_101 , & V_97 -> V_16 ) ;
if ( V_112 )
F_71 ( & V_115 , 1 ) ;
}
if ( F_61 ( V_104 ) ) {
V_97 -> V_110 = NULL ;
} else if ( V_109 <= V_107 ) {
V_97 -> V_110 =
F_62 ( V_104 -> V_119 , struct V_98 , V_101 ) ;
}
V_97 -> V_116 = 0 ;
return 0 ;
}
static int V_54 ( struct V_11 * V_12 ,
union V_36 * T_2 V_35 ,
struct V_1 * V_2 )
{
int V_8 = F_64 ( V_2 , V_12 ) ;
if ( ! V_8 )
V_2 -> V_14 . V_108 = V_2 -> V_14 . V_120 ;
return V_8 ;
}
static void F_72 ( struct V_98 * V_121 , struct V_1 * V_102 )
{
struct V_14 * V_97 = & V_102 -> V_14 ;
struct V_98 * T_4 = V_97 -> V_110 ;
T_7 V_111 = V_121 -> V_111 ;
struct V_103 * V_81 ;
++ V_97 -> V_116 ;
V_97 -> V_110 = V_121 ;
if ( ! T_4 ) {
F_70 ( & V_121 -> V_101 , & V_97 -> V_15 ) ;
V_97 -> V_120 = V_111 ;
return;
}
if ( T_4 -> V_111 <= V_111 ) {
while ( T_4 -> V_111 <= V_111 ) {
V_81 = T_4 -> V_101 . V_100 ;
if ( V_81 == & V_97 -> V_15 ) {
F_73 ( & V_121 -> V_101 , & V_97 -> V_15 ) ;
V_97 -> V_120 = V_111 ;
return;
}
T_4 = F_62 ( V_81 , struct V_98 , V_101 ) ;
}
F_73 ( & V_121 -> V_101 , & T_4 -> V_101 ) ;
} else {
while ( T_4 -> V_111 > V_111 ) {
V_81 = T_4 -> V_101 . V_119 ;
if ( V_81 == & V_97 -> V_15 ) {
F_70 ( & V_121 -> V_101 , & V_97 -> V_15 ) ;
return;
}
T_4 = F_62 ( V_81 , struct V_98 , V_101 ) ;
}
F_70 ( & V_121 -> V_101 , & T_4 -> V_101 ) ;
}
}
int F_74 ( struct V_1 * V_102 , union V_36 * T_2 ,
struct V_38 * T_4 , T_7 V_117 )
{
struct V_14 * V_97 = & V_102 -> V_14 ;
struct V_103 * V_122 = & V_97 -> V_16 ;
T_7 V_111 = T_4 -> time ;
struct V_98 * V_121 ;
if ( ! V_111 || V_111 == ~ 0ULL )
return - V_123 ;
if ( V_111 < V_102 -> V_14 . V_118 ) {
printf ( L_9 ) ;
return - V_124 ;
}
if ( ! F_61 ( V_122 ) ) {
V_121 = F_62 ( V_122 -> V_100 , struct V_98 , V_101 ) ;
F_63 ( & V_121 -> V_101 ) ;
} else if ( V_97 -> V_125 ) {
V_121 = V_97 -> V_125 + V_97 -> V_126 ;
if ( ++ V_97 -> V_126 == V_127 )
V_97 -> V_125 = NULL ;
} else {
V_97 -> V_125 = malloc ( V_127 * sizeof( * V_121 ) ) ;
if ( ! V_97 -> V_125 )
return - V_128 ;
F_70 ( & V_97 -> V_125 -> V_101 , & V_97 -> V_17 ) ;
V_97 -> V_126 = 2 ;
V_121 = V_97 -> V_125 + 1 ;
}
V_121 -> V_111 = V_111 ;
V_121 -> V_117 = V_117 ;
V_121 -> T_2 = T_2 ;
F_72 ( V_121 , V_102 ) ;
return 0 ;
}
static void F_75 ( struct V_38 * T_4 )
{
unsigned int V_82 ;
printf ( L_10 V_129 L_11 , T_4 -> V_130 -> V_131 ) ;
for ( V_82 = 0 ; V_82 < T_4 -> V_130 -> V_131 ; V_82 ++ )
printf ( L_12 V_132 L_11 ,
V_82 , T_4 -> V_130 -> V_133 [ V_82 ] ) ;
}
static void F_76 ( struct V_38 * T_4 )
{
T_11 V_82 ;
printf ( L_13 V_129 L_11 , T_4 -> V_134 -> V_131 ) ;
for ( V_82 = 0 ; V_82 < T_4 -> V_134 -> V_131 ; V_82 ++ )
printf ( L_14 V_129 L_15 V_132 L_16 V_132 L_11 ,
V_82 , T_4 -> V_134 -> V_135 [ V_82 ] . V_136 ,
T_4 -> V_134 -> V_135 [ V_82 ] . V_137 ) ;
}
static void F_77 ( T_7 V_138 , T_7 * V_139 )
{
unsigned V_140 , V_82 = 0 ;
F_78 (rid, (unsigned long *) &mask, sizeof(mask) * 8 ) {
T_7 V_141 = V_139 [ V_82 ++ ] ;
printf ( L_17 V_132 L_11 ,
F_79 ( V_140 ) , V_141 ) ;
}
}
static void F_80 ( struct V_38 * T_4 , T_7 V_138 )
{
struct V_142 * V_143 = & T_4 -> V_143 ;
if ( V_143 -> V_139 ) {
printf ( L_18 V_132 L_11 , V_138 ) ;
F_77 ( V_138 , V_143 -> V_139 ) ;
}
}
static void F_81 ( struct V_144 * V_145 )
{
printf ( L_19 V_129 L_20 ,
V_145 -> V_60 , V_145 -> V_146 ) ;
}
static void F_82 ( struct V_1 * V_2 ,
union V_36 * T_2 ,
struct V_38 * T_4 )
{
T_7 V_86 = F_83 ( V_2 -> V_5 ) ;
if ( T_2 -> V_34 . type != V_147 &&
! F_23 ( V_2 -> V_5 ) ) {
fputs ( L_21 , stdout ) ;
return;
}
if ( ( V_86 & V_148 ) )
printf ( L_22 , T_4 -> V_149 ) ;
if ( V_86 & V_150 )
printf ( L_23 V_129 L_24 , T_4 -> time ) ;
}
static void F_84 ( struct V_38 * T_4 , T_7 V_87 )
{
printf ( L_25 ) ;
if ( V_87 & V_151 )
printf ( L_26 V_132 L_11 ,
T_4 -> V_47 . V_75 ) ;
if ( V_87 & V_152 )
printf ( L_27 V_132 L_11 ,
T_4 -> V_47 . V_76 ) ;
if ( V_87 & V_153 ) {
T_7 V_82 ;
printf ( L_28 V_129 L_11 , T_4 -> V_47 . V_154 . V_131 ) ;
for ( V_82 = 0 ; V_82 < T_4 -> V_47 . V_154 . V_131 ; V_82 ++ ) {
struct V_155 * V_74 ;
V_74 = & T_4 -> V_47 . V_154 . V_156 [ V_82 ] ;
printf ( L_29 V_132
L_30 V_132 L_11 ,
V_74 -> V_77 , V_74 -> V_74 ) ;
}
} else
printf ( L_29 V_132 L_30 V_132 L_11 ,
T_4 -> V_47 . V_157 . V_77 , T_4 -> V_47 . V_157 . V_74 ) ;
}
static void F_85 ( struct V_1 * V_2 , union V_36 * T_2 ,
T_7 V_117 , struct V_38 * T_4 )
{
if ( ! V_158 )
return;
printf ( L_31 V_132 L_32 ,
V_117 , T_2 -> V_34 . V_60 , T_2 -> V_34 . type ) ;
F_86 ( T_2 ) ;
if ( T_4 )
F_82 ( V_2 , T_2 , T_4 ) ;
printf ( L_33 V_132 L_34 , V_117 ,
T_2 -> V_34 . V_60 , F_87 ( T_2 -> V_34 . type ) ) ;
}
static void F_88 ( struct V_39 * T_5 , union V_36 * T_2 ,
struct V_38 * T_4 )
{
T_7 V_86 ;
if ( ! V_158 )
return;
printf ( L_35 V_132 L_36 V_129 L_37 V_132 L_11 ,
T_2 -> V_34 . V_159 , T_4 -> V_63 , T_4 -> V_64 , T_4 -> V_160 ,
T_4 -> V_161 , T_4 -> V_162 ) ;
V_86 = T_5 -> V_50 . V_86 ;
if ( V_86 & V_163 )
F_75 ( T_4 ) ;
if ( V_86 & V_164 )
F_76 ( T_4 ) ;
if ( V_86 & V_165 )
F_80 ( T_4 , T_5 -> V_50 . V_93 ) ;
if ( V_86 & V_166 )
F_81 ( & T_4 -> V_167 ) ;
if ( V_86 & V_168 )
printf ( L_38 V_129 L_11 , T_4 -> V_169 ) ;
if ( V_86 & V_170 )
printf ( L_39 V_132 L_11 , T_4 -> V_171 ) ;
if ( V_86 & V_172 )
printf ( L_40 V_132 L_11 , T_4 -> V_173 ) ;
if ( V_86 & V_174 )
F_84 ( T_4 , T_5 -> V_50 . V_87 ) ;
}
static struct V_40 *
F_89 ( struct V_1 * V_2 ,
union V_36 * T_2 ,
struct V_38 * T_4 )
{
const T_9 V_175 = T_2 -> V_34 . V_159 & V_176 ;
if ( V_177 &&
( ( V_175 == V_178 ) ||
( V_175 == V_179 ) ) ) {
T_6 V_63 ;
if ( T_2 -> V_34 . type == V_180
|| T_2 -> V_34 . type == V_181 )
V_63 = T_2 -> V_41 . V_63 ;
else
V_63 = T_4 -> V_63 ;
return F_90 ( V_2 , V_63 ) ;
}
return & V_2 -> V_7 . V_9 ;
}
static int F_91 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
union V_36 * T_2 ,
struct V_38 * T_4 ,
struct V_155 * V_182 ,
struct V_40 * V_40 )
{
struct V_183 * V_184 ;
V_184 = F_92 ( V_2 -> V_5 , V_182 -> V_77 ) ;
if ( V_184 ) {
T_4 -> V_77 = V_182 -> V_77 ;
T_4 -> V_161 = V_182 -> V_74 - V_184 -> V_161 ;
V_184 -> V_161 = V_182 -> V_74 ;
}
if ( ! V_184 || V_184 -> T_5 == NULL ) {
++ V_2 -> V_185 . V_186 ;
return 0 ;
}
return V_12 -> T_4 ( V_12 , T_2 , T_4 , V_184 -> T_5 , V_40 ) ;
}
static int F_93 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
union V_36 * T_2 ,
struct V_38 * T_4 ,
struct V_40 * V_40 )
{
int V_8 = - V_124 ;
T_7 V_82 ;
for ( V_82 = 0 ; V_82 < T_4 -> V_47 . V_154 . V_131 ; V_82 ++ ) {
V_8 = F_91 ( V_2 , V_12 , T_2 , T_4 ,
& T_4 -> V_47 . V_154 . V_156 [ V_82 ] ,
V_40 ) ;
if ( V_8 )
break;
}
return V_8 ;
}
static int
F_94 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
union V_36 * T_2 ,
struct V_38 * T_4 ,
struct V_39 * T_5 ,
struct V_40 * V_40 )
{
T_7 V_86 = T_5 -> V_50 . V_86 ;
T_7 V_87 = T_5 -> V_50 . V_87 ;
if ( ! ( V_86 & V_174 ) )
return V_12 -> T_4 ( V_12 , T_2 , T_4 , T_5 , V_40 ) ;
if ( V_87 & V_153 )
return F_93 ( V_2 , V_12 , T_2 , T_4 ,
V_40 ) ;
else
return F_91 ( V_2 , V_12 , T_2 , T_4 ,
& T_4 -> V_47 . V_157 , V_40 ) ;
}
static int F_69 ( struct V_1 * V_2 ,
union V_36 * T_2 ,
struct V_38 * T_4 ,
struct V_11 * V_12 ,
T_7 V_117 )
{
struct V_39 * T_5 ;
struct V_40 * V_40 ;
F_85 ( V_2 , T_2 , V_117 , T_4 ) ;
T_5 = F_95 ( V_2 -> V_5 , T_4 -> V_77 ) ;
if ( T_5 != NULL && T_2 -> V_34 . type != V_147 ) {
F_96 ( & T_5 -> V_187 , T_2 -> V_34 . type ) ;
}
V_40 = F_89 ( V_2 , T_2 ,
T_4 ) ;
switch ( T_2 -> V_34 . type ) {
case V_147 :
F_88 ( T_5 , T_2 , T_4 ) ;
if ( T_5 == NULL ) {
++ V_2 -> V_185 . V_186 ;
return 0 ;
}
if ( V_40 == NULL ) {
++ V_2 -> V_185 . V_188 ;
return 0 ;
}
return F_94 ( V_2 , V_12 , T_2 ,
T_4 , T_5 , V_40 ) ;
case V_180 :
return V_12 -> V_41 ( V_12 , T_2 , T_4 , V_40 ) ;
case V_181 :
return V_12 -> V_42 ( V_12 , T_2 , T_4 , V_40 ) ;
case V_189 :
return V_12 -> V_43 ( V_12 , T_2 , T_4 , V_40 ) ;
case V_190 :
return V_12 -> V_44 ( V_12 , T_2 , T_4 , V_40 ) ;
case V_191 :
return V_12 -> exit ( V_12 , T_2 , T_4 , V_40 ) ;
case V_192 :
if ( V_12 -> V_45 == V_46 )
V_2 -> V_185 . V_193 += T_2 -> V_45 . V_45 ;
return V_12 -> V_45 ( V_12 , T_2 , T_4 , V_40 ) ;
case V_194 :
return V_12 -> V_47 ( V_12 , T_2 , T_4 , T_5 , V_40 ) ;
case V_195 :
return V_12 -> V_48 ( V_12 , T_2 , T_4 , V_40 ) ;
case V_196 :
return V_12 -> V_49 ( V_12 , T_2 , T_4 , V_40 ) ;
default:
++ V_2 -> V_185 . V_197 ;
return - 1 ;
}
}
static int F_97 ( struct V_1 * V_2 , union V_36 * T_2 ,
struct V_11 * V_12 , T_7 V_117 )
{
int V_198 = F_98 ( V_2 -> V_4 ) ;
int V_199 ;
F_85 ( V_2 , T_2 , V_117 , NULL ) ;
switch ( T_2 -> V_34 . type ) {
case V_200 :
V_199 = V_12 -> V_50 ( V_12 , T_2 , & V_2 -> V_5 ) ;
if ( V_199 == 0 )
F_8 ( V_2 ) ;
return V_199 ;
case V_201 :
F_99 ( V_198 , V_117 , V_202 ) ;
return V_12 -> V_51 ( V_12 , T_2 , V_2 ) ;
case V_203 :
return V_12 -> V_52 ( V_12 , T_2 , V_2 ) ;
case V_204 :
return V_12 -> V_53 ( V_12 , T_2 , V_2 ) ;
default:
return - V_124 ;
}
}
static void F_100 ( union V_36 * T_2 , bool T_8 )
{
T_12 V_205 ;
V_205 = V_206 [ T_2 -> V_34 . type ] ;
if ( V_205 )
V_205 ( T_2 , T_8 ) ;
}
static int F_101 ( struct V_1 * V_2 ,
union V_36 * T_2 ,
struct V_11 * V_12 ,
T_7 V_117 )
{
struct V_38 T_4 ;
int V_8 ;
if ( V_2 -> V_34 . V_207 )
F_100 ( T_2 , F_23 ( V_2 -> V_5 ) ) ;
if ( T_2 -> V_34 . type >= V_208 )
return - V_124 ;
F_102 ( & V_2 -> V_185 , T_2 -> V_34 . type ) ;
if ( T_2 -> V_34 . type >= V_209 )
return F_97 ( V_2 , T_2 , V_12 , V_117 ) ;
V_8 = F_68 ( V_2 -> V_5 , T_2 , & T_4 ) ;
if ( V_8 )
return V_8 ;
if ( V_12 -> V_14 ) {
V_8 = F_74 ( V_2 , T_2 , & T_4 ,
V_117 ) ;
if ( V_8 != - V_123 )
return V_8 ;
}
return F_69 ( V_2 , T_2 , & T_4 , V_12 ,
V_117 ) ;
}
void F_103 ( struct V_61 * V_62 )
{
V_62 -> type = F_41 ( V_62 -> type ) ;
V_62 -> V_159 = F_104 ( V_62 -> V_159 ) ;
V_62 -> V_60 = F_104 ( V_62 -> V_60 ) ;
}
struct V_210 * F_105 ( struct V_1 * V_2 , T_13 V_63 )
{
return F_106 ( & V_2 -> V_7 . V_9 , 0 , V_63 ) ;
}
static struct V_210 * F_107 ( struct V_1 * V_2 )
{
struct V_210 * V_210 = F_105 ( V_2 , 0 ) ;
if ( V_210 == NULL || F_108 ( V_210 , L_41 , 0 ) ) {
F_3 ( L_42 ) ;
V_210 = NULL ;
}
return V_210 ;
}
static void F_109 ( const struct V_1 * V_2 ,
const struct V_11 * V_12 )
{
if ( V_12 -> V_45 == V_46 &&
V_2 -> V_185 . V_211 [ V_192 ] != 0 ) {
F_110 ( L_43
L_44 ,
V_2 -> V_185 . V_211 [ 0 ] ,
V_2 -> V_185 . V_211 [ V_192 ] ) ;
}
if ( V_2 -> V_185 . V_197 != 0 ) {
F_110 ( L_45
L_46
L_47
L_48
L_49 ,
V_2 -> V_185 . V_197 ) ;
}
if ( V_2 -> V_185 . V_186 != 0 ) {
F_110 ( L_50 ,
V_2 -> V_185 . V_186 ) ;
}
if ( V_2 -> V_185 . V_212 != 0 ) {
F_110 ( L_51
L_52
L_53 ,
V_2 -> V_185 . V_212 ,
V_2 -> V_185 . V_211 [ V_147 ] ) ;
}
if ( V_2 -> V_185 . V_188 != 0 ) {
F_110 ( L_54
L_55 ,
V_2 -> V_185 . V_188 ) ;
}
}
static int F_111 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
int V_198 = F_98 ( V_2 -> V_4 ) ;
union V_36 * T_2 ;
T_14 V_60 , V_213 = 0 ;
void * V_214 = NULL ;
int V_215 = 0 ;
T_7 V_104 ;
int V_199 ;
void * V_81 ;
F_39 ( V_12 ) ;
V_104 = 0 ;
V_213 = sizeof( union V_36 ) ;
V_214 = malloc ( V_213 ) ;
if ( ! V_214 )
return - V_216 ;
V_217:
T_2 = V_214 ;
V_199 = F_112 ( V_198 , T_2 , sizeof( struct V_61 ) ) ;
if ( V_199 <= 0 ) {
if ( V_199 == 0 )
goto V_218;
F_3 ( L_56 ) ;
goto V_219;
}
if ( V_2 -> V_34 . V_207 )
F_103 ( & T_2 -> V_34 ) ;
V_60 = T_2 -> V_34 . V_60 ;
if ( V_60 < sizeof( struct V_61 ) ) {
F_3 ( L_57 ) ;
goto V_219;
}
if ( V_60 > V_213 ) {
void * V_121 = realloc ( V_214 , V_60 ) ;
if ( ! V_121 ) {
F_3 ( L_58 ) ;
goto V_219;
}
V_214 = V_121 ;
V_213 = V_60 ;
T_2 = V_214 ;
}
V_81 = T_2 ;
V_81 += sizeof( struct V_61 ) ;
if ( V_60 - sizeof( struct V_61 ) ) {
V_199 = F_112 ( V_198 , V_81 , V_60 - sizeof( struct V_61 ) ) ;
if ( V_199 <= 0 ) {
if ( V_199 == 0 ) {
F_3 ( L_59 ) ;
goto V_218;
}
F_3 ( L_60 ) ;
goto V_219;
}
}
if ( ( V_215 = F_101 ( V_2 , T_2 , V_12 , V_104 ) ) < 0 ) {
F_3 ( L_33 V_132 L_61 ,
V_104 , T_2 -> V_34 . V_60 , T_2 -> V_34 . type ) ;
V_199 = - V_124 ;
goto V_219;
}
V_104 += V_60 ;
if ( V_215 > 0 )
V_104 += V_215 ;
if ( ! F_67 () )
goto V_217;
V_218:
V_2 -> V_14 . V_108 = V_113 ;
V_199 = F_64 ( V_2 , V_12 ) ;
V_219:
free ( V_214 ) ;
F_109 ( V_2 , V_12 ) ;
F_60 ( V_2 ) ;
return V_199 ;
}
static union V_36 *
F_113 ( struct V_1 * V_2 ,
T_7 V_104 , T_10 V_220 , char * V_214 )
{
union V_36 * T_2 ;
if ( V_104 + sizeof( T_2 -> V_34 ) > V_220 )
return NULL ;
T_2 = (union V_36 * ) ( V_214 + V_104 ) ;
if ( V_2 -> V_34 . V_207 )
F_103 ( & T_2 -> V_34 ) ;
if ( V_104 + T_2 -> V_34 . V_60 > V_220 ) {
if ( V_2 -> V_34 . V_207 )
F_103 ( & T_2 -> V_34 ) ;
return NULL ;
}
return T_2 ;
}
int F_114 ( struct V_1 * V_2 ,
T_7 V_221 , T_7 V_222 ,
T_7 V_223 , struct V_11 * V_12 )
{
int V_198 = F_98 ( V_2 -> V_4 ) ;
T_7 V_104 , V_224 , V_117 , V_225 ;
int V_199 , V_226 , V_227 , V_228 = 0 ;
T_10 V_220 ;
char * V_214 , * V_229 [ V_230 ] ;
union V_36 * T_2 ;
T_14 V_60 ;
struct V_114 V_115 ;
F_39 ( V_12 ) ;
V_224 = V_231 * ( V_221 / V_231 ) ;
V_117 = V_224 ;
V_104 = V_221 - V_224 ;
if ( V_222 && ( V_221 + V_222 < V_223 ) )
V_223 = V_221 + V_222 ;
F_65 ( & V_115 , V_223 , L_62 ) ;
V_220 = V_232 ;
if ( V_220 > V_223 )
V_220 = V_223 ;
memset ( V_229 , 0 , sizeof( V_229 ) ) ;
V_226 = V_233 ;
V_227 = V_234 ;
if ( V_2 -> V_34 . V_207 ) {
V_226 |= V_235 ;
V_227 = V_236 ;
}
V_237:
V_214 = V_41 ( NULL , V_220 , V_226 , V_227 , V_198 ,
V_117 ) ;
if ( V_214 == V_238 ) {
F_3 ( L_63 ) ;
V_199 = - V_216 ;
goto V_219;
}
V_229 [ V_228 ] = V_214 ;
V_228 = ( V_228 + 1 ) & ( F_115 ( V_229 ) - 1 ) ;
V_225 = V_117 + V_104 ;
V_217:
T_2 = F_113 ( V_2 , V_104 , V_220 , V_214 ) ;
if ( ! T_2 ) {
if ( V_229 [ V_228 ] ) {
F_116 ( V_229 [ V_228 ] , V_220 ) ;
V_229 [ V_228 ] = NULL ;
}
V_224 = V_231 * ( V_104 / V_231 ) ;
V_117 += V_224 ;
V_104 -= V_224 ;
goto V_237;
}
V_60 = T_2 -> V_34 . V_60 ;
if ( V_60 < sizeof( struct V_61 ) ||
F_101 ( V_2 , T_2 , V_12 , V_225 ) < 0 ) {
F_3 ( L_33 V_132 L_61 ,
V_117 + V_104 , T_2 -> V_34 . V_60 ,
T_2 -> V_34 . type ) ;
V_199 = - V_124 ;
goto V_219;
}
V_104 += V_60 ;
V_225 += V_60 ;
F_71 ( & V_115 , V_60 ) ;
if ( F_67 () )
goto V_13;
if ( V_225 < V_223 )
goto V_217;
V_13:
V_2 -> V_14 . V_108 = V_113 ;
V_199 = F_64 ( V_2 , V_12 ) ;
V_219:
F_117 () ;
F_109 ( V_2 , V_12 ) ;
F_60 ( V_2 ) ;
return V_199 ;
}
int F_118 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
T_7 V_60 = F_119 ( V_2 -> V_4 ) ;
int V_199 ;
if ( F_107 ( V_2 ) == NULL )
return - V_128 ;
if ( ! F_4 ( V_2 -> V_4 ) )
V_199 = F_114 ( V_2 ,
V_2 -> V_34 . V_221 ,
V_2 -> V_34 . V_222 ,
V_60 , V_12 ) ;
else
V_199 = F_111 ( V_2 , V_12 ) ;
return V_199 ;
}
bool F_120 ( struct V_1 * V_2 , const char * V_239 )
{
struct V_39 * T_5 ;
F_121 (evsel, &session->evlist->entries, node) {
if ( T_5 -> V_50 . type == V_240 )
return true ;
}
F_3 ( L_64 , V_239 ) ;
return false ;
}
int F_122 ( struct V_241 * * V_242 ,
const char * V_243 , T_7 V_162 )
{
char * V_244 ;
enum V_245 V_82 ;
struct V_246 * V_247 ;
V_247 = F_17 ( sizeof( struct V_246 ) ) ;
if ( V_247 == NULL )
return - V_128 ;
V_247 -> V_248 = F_123 ( V_243 ) ;
if ( V_247 -> V_248 == NULL ) {
free ( V_247 ) ;
return - V_128 ;
}
V_244 = strchr ( V_247 -> V_248 , ']' ) ;
if ( V_244 )
* V_244 = '\0' ;
V_247 -> V_162 = V_162 ;
for ( V_82 = 0 ; V_82 < V_249 ; ++ V_82 ) {
struct V_250 * V_250 = F_124 ( V_242 [ V_82 ] ) ;
V_250 -> V_246 = V_247 ;
}
return 0 ;
}
T_10 F_125 ( struct V_1 * V_2 , T_15 * V_251 )
{
return F_126 ( & V_2 -> V_7 , V_251 ) ;
}
T_10 F_127 ( struct V_1 * V_2 , T_15 * V_251 ,
bool (V_215)( struct V_252 * V_252 , int V_253 ) , int V_253 )
{
return F_128 ( & V_2 -> V_7 , V_251 , V_215 , V_253 ) ;
}
T_10 F_129 ( struct V_1 * V_2 , T_15 * V_251 )
{
struct V_39 * V_254 ;
T_10 V_8 = fprintf ( V_251 , L_65 ) ;
V_8 += F_130 ( & V_2 -> V_185 , V_251 ) ;
F_121 (pos, &session->evlist->entries, node) {
V_8 += fprintf ( V_251 , L_66 , F_131 ( V_254 ) ) ;
V_8 += F_130 ( & V_254 -> V_187 . V_185 , V_251 ) ;
}
return V_8 ;
}
T_10 F_132 ( struct V_1 * V_2 , T_15 * V_251 )
{
return F_133 ( & V_2 -> V_7 . V_9 , V_251 ) ;
}
struct V_39 * F_134 ( struct V_1 * V_2 ,
unsigned int type )
{
struct V_39 * V_254 ;
F_121 (pos, &session->evlist->entries, node) {
if ( V_254 -> V_50 . type == type )
return V_254 ;
}
return NULL ;
}
void F_135 ( struct V_39 * T_5 , union V_36 * T_2 ,
struct V_38 * T_4 , struct V_40 * V_40 ,
unsigned int V_255 , unsigned int V_256 )
{
struct V_257 V_258 ;
struct V_259 * V_260 ;
int V_261 = V_255 & V_262 ;
int V_263 = V_255 & V_264 ;
int V_265 = V_255 & V_266 ;
int V_267 = V_255 & V_268 ;
int V_269 = V_255 & V_270 ;
char V_102 = V_269 ? ' ' : '\t' ;
if ( F_136 ( T_2 , V_40 , & V_258 , T_4 ) < 0 ) {
error ( L_67 ,
T_2 -> V_34 . type ) ;
return;
}
if ( V_271 . V_272 && T_4 -> V_130 ) {
if ( F_137 ( V_40 , T_5 , V_258 . V_210 ,
T_4 , NULL , NULL ,
V_273 ) != 0 ) {
if ( V_274 )
error ( L_68 ) ;
return;
}
F_138 ( & V_275 ) ;
while ( V_256 ) {
V_260 = F_139 ( & V_275 ) ;
if ( ! V_260 )
break;
if ( V_261 )
printf ( L_69 V_132 , V_102 , V_260 -> V_160 ) ;
if ( V_263 ) {
printf ( L_24 ) ;
if ( V_267 ) {
V_258 . V_162 = V_260 -> V_160 ;
V_258 . V_241 = V_260 -> V_241 ;
F_140 ( V_260 -> V_276 , & V_258 , stdout ) ;
} else
F_141 ( V_260 -> V_276 , stdout ) ;
}
if ( V_265 ) {
printf ( L_70 ) ;
F_142 ( V_260 -> V_241 , stdout ) ;
printf ( L_71 ) ;
}
if ( ! V_269 )
printf ( L_11 ) ;
F_143 ( & V_275 ) ;
V_256 -- ;
}
} else {
if ( V_261 )
printf ( L_72 V_132 , T_4 -> V_160 ) ;
if ( V_263 ) {
printf ( L_24 ) ;
if ( V_267 )
F_140 ( V_258 . V_276 , & V_258 ,
stdout ) ;
else
F_141 ( V_258 . V_276 , stdout ) ;
}
if ( V_265 ) {
printf ( L_70 ) ;
F_142 ( V_258 . V_241 , stdout ) ;
printf ( L_71 ) ;
}
}
}
int F_144 ( struct V_1 * V_2 ,
const char * V_277 , unsigned long * V_278 )
{
int V_82 ;
struct V_279 * V_241 ;
for ( V_82 = 0 ; V_82 < V_280 ; ++ V_82 ) {
struct V_39 * T_5 ;
T_5 = F_134 ( V_2 , V_82 ) ;
if ( ! T_5 )
continue;
if ( ! ( T_5 -> V_50 . V_86 & V_148 ) ) {
F_3 ( L_73
L_74 ) ;
return - 1 ;
}
}
V_241 = F_145 ( V_277 ) ;
if ( V_241 == NULL ) {
F_3 ( L_75 ) ;
return - 1 ;
}
for ( V_82 = 0 ; V_82 < V_241 -> V_131 ; V_82 ++ ) {
int V_149 = V_241 -> V_241 [ V_82 ] ;
if ( V_149 >= V_281 ) {
F_3 ( L_76
L_77 , V_149 ) ;
return - 1 ;
}
F_146 ( V_149 , V_278 ) ;
}
return 0 ;
}
void F_147 ( struct V_1 * V_2 , T_15 * V_251 ,
bool V_282 )
{
int V_198 = F_98 ( V_2 -> V_4 ) ;
struct V_283 V_284 ;
int V_8 ;
if ( V_2 == NULL || V_251 == NULL )
return;
V_8 = F_148 ( V_198 , & V_284 ) ;
if ( V_8 == - 1 )
return;
fprintf ( V_251 , L_78 ) ;
fprintf ( V_251 , L_79 , ctime ( & V_284 . V_285 ) ) ;
F_149 ( V_2 , V_251 , V_282 ) ;
fprintf ( V_251 , L_80 ) ;
}
int F_150 ( struct V_1 * V_2 ,
const struct V_286 * V_287 ,
T_10 V_288 )
{
struct V_39 * T_5 ;
T_10 V_82 ;
int V_199 ;
for ( V_82 = 0 ; V_82 < V_288 ; V_82 ++ ) {
T_5 = F_151 ( V_2 -> V_5 , V_287 [ V_82 ] . V_248 ) ;
if ( T_5 == NULL )
continue;
V_199 = - V_289 ;
if ( T_5 -> V_290 != NULL )
goto V_13;
T_5 -> V_290 = V_287 [ V_82 ] . V_290 ;
}
V_199 = 0 ;
V_13:
return V_199 ;
}
