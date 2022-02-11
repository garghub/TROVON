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
static bool F_16 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
F_17 (session->evlist, evsel) {
if ( V_11 -> V_12 . V_13 )
return true ;
}
return false ;
}
static void F_18 ( struct V_1 * V_2 )
{
bool V_13 = F_16 ( V_2 ) ;
F_19 ( & V_2 -> V_7 , V_13 ) ;
}
struct V_1 * F_20 ( struct V_3 * V_4 ,
bool V_14 , struct V_15 * V_16 )
{
struct V_1 * V_2 = F_21 ( sizeof( * V_2 ) ) ;
if ( ! V_2 )
goto V_17;
V_2 -> V_14 = V_14 ;
F_22 ( & V_2 -> V_18 ) ;
F_23 ( & V_2 -> V_7 ) ;
if ( V_4 ) {
if ( F_24 ( V_4 ) )
goto V_19;
V_2 -> V_4 = V_4 ;
if ( F_25 ( V_4 ) ) {
if ( F_1 ( V_2 ) < 0 )
goto V_20;
F_8 ( V_2 ) ;
F_18 ( V_2 ) ;
}
}
if ( ! V_4 || F_26 ( V_4 ) ) {
if ( F_11 ( V_2 ) < 0 )
F_27 ( L_5 ) ;
}
if ( V_16 && V_16 -> V_21 &&
V_16 -> V_18 && ! F_28 ( V_2 -> V_5 ) ) {
F_29 ( L_6 ) ;
V_16 -> V_18 = false ;
}
return V_2 ;
V_20:
F_30 ( V_4 ) ;
V_19:
F_31 ( V_2 ) ;
V_17:
return NULL ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_33 ( & V_2 -> V_7 . V_9 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_35 ( & V_2 -> V_7 . V_9 ) ;
}
static void F_36 ( struct V_22 * V_23 )
{
F_37 ( & V_23 -> V_24 ) ;
F_37 ( & V_23 -> V_25 ) ;
F_37 ( & V_23 -> V_26 ) ;
F_37 ( & V_23 -> V_27 ) ;
F_37 ( & V_23 -> V_28 ) ;
F_37 ( & V_23 -> V_29 ) ;
F_37 ( & V_23 -> V_30 ) ;
F_37 ( & V_23 -> V_31 ) ;
F_37 ( & V_23 -> V_32 ) ;
F_37 ( & V_23 -> V_33 ) ;
F_37 ( & V_23 -> V_34 ) ;
}
void F_31 ( struct V_1 * V_2 )
{
F_14 ( V_2 ) ;
F_32 ( V_2 ) ;
F_34 ( V_2 ) ;
F_36 ( & V_2 -> V_35 . V_23 ) ;
F_38 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_4 )
F_30 ( V_2 -> V_4 ) ;
free ( V_2 ) ;
}
static int F_39 ( struct V_15 * V_16
V_36 ,
union V_37 * T_2
V_36 ,
struct V_1 * V_2
V_36 )
{
F_29 ( L_7 ) ;
return 0 ;
}
static int F_40 ( struct V_15 * V_16 V_36 ,
union V_37 * T_2 V_36 ,
struct V_38 * * T_3
V_36 )
{
F_29 ( L_7 ) ;
return 0 ;
}
static int F_41 ( struct V_15 * V_16 V_36 ,
union V_37 * T_2 V_36 ,
struct V_39 * T_4 V_36 ,
struct V_10 * V_11 V_36 ,
struct V_40 * V_40 V_36 )
{
F_29 ( L_7 ) ;
return 0 ;
}
static int F_42 ( struct V_15 * V_16 V_36 ,
union V_37 * T_2 V_36 ,
struct V_39 * T_4 V_36 ,
struct V_40 * V_40 V_36 )
{
F_29 ( L_7 ) ;
return 0 ;
}
static int F_43 ( struct V_15 * V_16 V_36 ,
union V_37 * T_2 V_36 ,
struct V_1 * V_1
V_36 )
{
F_29 ( L_7 ) ;
return 0 ;
}
static int F_44 ( struct V_15 * V_16 V_36 ,
union V_37 * T_2 V_36 ,
struct V_1 * V_1
V_36 )
{
F_29 ( L_7 ) ;
return 0 ;
}
void F_45 ( struct V_15 * V_16 )
{
if ( V_16 -> T_4 == NULL )
V_16 -> T_4 = F_41 ;
if ( V_16 -> V_41 == NULL )
V_16 -> V_41 = F_42 ;
if ( V_16 -> V_42 == NULL )
V_16 -> V_42 = F_42 ;
if ( V_16 -> V_43 == NULL )
V_16 -> V_43 = F_42 ;
if ( V_16 -> V_44 == NULL )
V_16 -> V_44 = F_42 ;
if ( V_16 -> exit == NULL )
V_16 -> exit = F_42 ;
if ( V_16 -> V_45 == NULL )
V_16 -> V_45 = V_46 ;
if ( V_16 -> V_47 == NULL )
V_16 -> V_47 = F_41 ;
if ( V_16 -> V_48 == NULL )
V_16 -> V_48 = F_42 ;
if ( V_16 -> V_49 == NULL )
V_16 -> V_49 = F_42 ;
if ( V_16 -> V_12 == NULL )
V_16 -> V_12 = F_40 ;
if ( V_16 -> V_50 == NULL )
V_16 -> V_50 = F_39 ;
if ( V_16 -> V_51 == NULL )
V_16 -> V_51 = F_43 ;
if ( V_16 -> V_52 == NULL ) {
if ( V_16 -> V_18 )
V_16 -> V_52 = V_53 ;
else
V_16 -> V_52 = F_43 ;
}
if ( V_16 -> V_54 == NULL )
V_16 -> V_54 = F_44 ;
}
static void F_46 ( union V_37 * T_2 , void * V_55 )
{
void * V_56 = ( void * ) T_2 + T_2 -> V_35 . V_57 ;
int V_57 = V_56 - V_55 ;
F_47 ( V_57 % sizeof( V_58 ) ) ;
F_48 ( V_55 , V_57 ) ;
}
static void F_49 ( union V_37 * T_2 ,
bool T_5 V_36 )
{
struct V_59 * V_60 = & T_2 -> V_35 ;
F_48 ( V_60 + 1 , T_2 -> V_35 . V_57 - sizeof( * V_60 ) ) ;
}
static void F_50 ( union V_37 * T_2 , bool T_5 )
{
T_2 -> V_43 . V_61 = F_51 ( T_2 -> V_43 . V_61 ) ;
T_2 -> V_43 . V_62 = F_51 ( T_2 -> V_43 . V_62 ) ;
if ( T_5 ) {
void * V_55 = & T_2 -> V_43 . V_43 ;
V_55 += F_52 ( strlen ( V_55 ) + 1 , sizeof( V_58 ) ) ;
F_46 ( T_2 , V_55 ) ;
}
}
static void F_53 ( union V_37 * T_2 ,
bool T_5 )
{
T_2 -> V_41 . V_61 = F_51 ( T_2 -> V_41 . V_61 ) ;
T_2 -> V_41 . V_62 = F_51 ( T_2 -> V_41 . V_62 ) ;
T_2 -> V_41 . V_63 = F_54 ( T_2 -> V_41 . V_63 ) ;
T_2 -> V_41 . V_64 = F_54 ( T_2 -> V_41 . V_64 ) ;
T_2 -> V_41 . V_65 = F_54 ( T_2 -> V_41 . V_65 ) ;
if ( T_5 ) {
void * V_55 = & T_2 -> V_41 . V_66 ;
V_55 += F_52 ( strlen ( V_55 ) + 1 , sizeof( V_58 ) ) ;
F_46 ( T_2 , V_55 ) ;
}
}
static void F_55 ( union V_37 * T_2 ,
bool T_5 )
{
T_2 -> V_42 . V_61 = F_51 ( T_2 -> V_42 . V_61 ) ;
T_2 -> V_42 . V_62 = F_51 ( T_2 -> V_42 . V_62 ) ;
T_2 -> V_42 . V_63 = F_54 ( T_2 -> V_42 . V_63 ) ;
T_2 -> V_42 . V_64 = F_54 ( T_2 -> V_42 . V_64 ) ;
T_2 -> V_42 . V_65 = F_54 ( T_2 -> V_42 . V_65 ) ;
T_2 -> V_42 . V_67 = F_51 ( T_2 -> V_42 . V_67 ) ;
T_2 -> V_42 . V_68 = F_51 ( T_2 -> V_42 . V_68 ) ;
T_2 -> V_42 . V_69 = F_54 ( T_2 -> V_42 . V_69 ) ;
if ( T_5 ) {
void * V_55 = & T_2 -> V_42 . V_66 ;
V_55 += F_52 ( strlen ( V_55 ) + 1 , sizeof( V_58 ) ) ;
F_46 ( T_2 , V_55 ) ;
}
}
static void F_56 ( union V_37 * T_2 , bool T_5 )
{
T_2 -> V_44 . V_61 = F_51 ( T_2 -> V_44 . V_61 ) ;
T_2 -> V_44 . V_62 = F_51 ( T_2 -> V_44 . V_62 ) ;
T_2 -> V_44 . V_70 = F_51 ( T_2 -> V_44 . V_70 ) ;
T_2 -> V_44 . V_71 = F_51 ( T_2 -> V_44 . V_71 ) ;
T_2 -> V_44 . time = F_54 ( T_2 -> V_44 . time ) ;
if ( T_5 )
F_46 ( T_2 , & T_2 -> V_44 + 1 ) ;
}
static void F_57 ( union V_37 * T_2 , bool T_5 )
{
T_2 -> V_47 . V_61 = F_51 ( T_2 -> V_47 . V_61 ) ;
T_2 -> V_47 . V_62 = F_51 ( T_2 -> V_47 . V_62 ) ;
T_2 -> V_47 . V_72 = F_54 ( T_2 -> V_47 . V_72 ) ;
T_2 -> V_47 . V_73 = F_54 ( T_2 -> V_47 . V_73 ) ;
T_2 -> V_47 . V_74 = F_54 ( T_2 -> V_47 . V_74 ) ;
T_2 -> V_47 . V_75 = F_54 ( T_2 -> V_47 . V_75 ) ;
if ( T_5 )
F_46 ( T_2 , & T_2 -> V_47 + 1 ) ;
}
static void F_58 ( union V_37 * T_2 ,
bool T_5 )
{
T_2 -> V_48 . time = F_54 ( T_2 -> V_48 . time ) ;
T_2 -> V_48 . V_75 = F_54 ( T_2 -> V_48 . V_75 ) ;
T_2 -> V_48 . V_76 = F_54 ( T_2 -> V_48 . V_76 ) ;
if ( T_5 )
F_46 ( T_2 , & T_2 -> V_48 + 1 ) ;
}
static T_6 F_59 ( T_6 V_77 )
{
int V_78 = ( V_77 >> 4 ) | ( ( V_77 & 0xf ) << 4 ) ;
V_78 = ( ( V_78 & 0xcc ) >> 2 ) | ( ( V_78 & 0x33 ) << 2 ) ;
V_78 = ( ( V_78 & 0xaa ) >> 1 ) | ( ( V_78 & 0x55 ) << 1 ) ;
return ( T_6 ) V_78 ;
}
static void F_60 ( T_6 * V_79 , unsigned V_64 )
{
unsigned V_80 ;
for ( V_80 = 0 ; V_80 < V_64 ; V_80 ++ ) {
* V_79 = F_59 ( * V_79 ) ;
V_79 ++ ;
}
}
void F_61 ( struct V_81 * V_12 )
{
V_12 -> type = F_51 ( V_12 -> type ) ;
V_12 -> V_57 = F_51 ( V_12 -> V_57 ) ;
V_12 -> V_82 = F_54 ( V_12 -> V_82 ) ;
V_12 -> V_83 = F_54 ( V_12 -> V_83 ) ;
V_12 -> V_84 = F_54 ( V_12 -> V_84 ) ;
V_12 -> V_85 = F_54 ( V_12 -> V_85 ) ;
V_12 -> V_86 = F_51 ( V_12 -> V_86 ) ;
V_12 -> V_87 = F_51 ( V_12 -> V_87 ) ;
V_12 -> V_88 = F_54 ( V_12 -> V_88 ) ;
V_12 -> V_89 = F_54 ( V_12 -> V_89 ) ;
V_12 -> V_90 = F_54 ( V_12 -> V_90 ) ;
V_12 -> V_91 = F_54 ( V_12 -> V_91 ) ;
V_12 -> V_92 = F_51 ( V_12 -> V_92 ) ;
F_60 ( ( T_6 * ) ( & V_12 -> V_85 + 1 ) , sizeof( V_58 ) ) ;
}
static void F_62 ( union V_37 * T_2 ,
bool T_5 V_36 )
{
T_7 V_57 ;
F_61 ( & T_2 -> V_12 . V_12 ) ;
V_57 = T_2 -> V_35 . V_57 ;
V_57 -= ( void * ) & T_2 -> V_12 . V_75 - ( void * ) T_2 ;
F_48 ( T_2 -> V_12 . V_75 , V_57 ) ;
}
static void F_63 ( union V_37 * T_2 ,
bool T_5 V_36 )
{
T_2 -> V_93 . V_93 . V_94 =
F_54 ( T_2 -> V_93 . V_93 . V_94 ) ;
}
static void F_64 ( union V_37 * T_2 ,
bool T_5 V_36 )
{
T_2 -> V_50 . V_57 = F_51 ( T_2 -> V_50 . V_57 ) ;
}
static int V_53 ( struct V_15 * V_16 ,
union V_37 * T_2 V_36 ,
struct V_1 * V_2 )
{
return F_65 ( V_2 , V_16 , V_95 ) ;
}
int F_66 ( struct V_1 * V_96 , union V_37 * T_2 ,
struct V_15 * V_16 , struct V_39 * T_4 ,
V_58 V_97 )
{
struct V_18 * V_98 = & V_96 -> V_18 ;
V_58 V_99 = T_4 -> time ;
struct V_100 * V_101 ;
if ( ! V_99 || V_99 == ~ 0ULL )
return - V_102 ;
if ( V_99 < V_98 -> V_103 ) {
F_67 ( V_99 , L_8 ) ;
F_67 ( V_98 -> V_103 , L_9 ,
V_98 -> V_104 ) ;
V_96 -> V_105 . V_106 ++ ;
}
V_101 = F_68 ( V_98 , V_99 , T_2 ) ;
if ( ! V_101 ) {
F_65 ( V_96 , V_16 , V_107 ) ;
V_101 = F_68 ( V_98 , V_99 , T_2 ) ;
}
if ( ! V_101 )
return - V_108 ;
V_101 -> V_97 = V_97 ;
return 0 ;
}
static void F_69 ( struct V_39 * T_4 )
{
unsigned int V_80 ;
printf ( L_10 V_109 L_11 , T_4 -> V_110 -> V_111 ) ;
for ( V_80 = 0 ; V_80 < T_4 -> V_110 -> V_111 ; V_80 ++ )
printf ( L_12 V_112 L_11 ,
V_80 , T_4 -> V_110 -> V_113 [ V_80 ] ) ;
}
static void F_70 ( struct V_39 * T_4 )
{
T_8 V_80 ;
printf ( L_13 V_109 L_11 , T_4 -> V_114 -> V_111 ) ;
for ( V_80 = 0 ; V_80 < T_4 -> V_114 -> V_111 ; V_80 ++ )
printf ( L_14 V_109 L_15 V_112 L_16 V_112 L_11 ,
V_80 , T_4 -> V_114 -> V_115 [ V_80 ] . V_116 ,
T_4 -> V_114 -> V_115 [ V_80 ] . V_117 ) ;
}
static void F_71 ( V_58 V_118 , V_58 * V_119 )
{
unsigned V_120 , V_80 = 0 ;
F_72 (rid, (unsigned long *) &mask, sizeof(mask) * 8 ) {
V_58 V_121 = V_119 [ V_80 ++ ] ;
printf ( L_17 V_112 L_11 ,
F_73 ( V_120 ) , V_121 ) ;
}
}
static inline const char * F_74 ( struct V_122 * V_123 )
{
if ( V_123 -> V_124 > V_125 )
return L_18 ;
return V_126 [ V_123 -> V_124 ] ;
}
static void F_75 ( const char * type , struct V_122 * V_119 )
{
V_58 V_118 = V_119 -> V_118 ;
printf ( L_19 V_112 L_20 ,
type ,
V_118 ,
F_74 ( V_119 ) ) ;
F_71 ( V_118 , V_119 -> V_119 ) ;
}
static void F_76 ( struct V_39 * T_4 )
{
struct V_122 * V_127 = & T_4 -> V_127 ;
if ( V_127 -> V_119 )
F_75 ( L_21 , V_127 ) ;
}
static void F_77 ( struct V_39 * T_4 )
{
struct V_122 * V_128 = & T_4 -> V_128 ;
if ( V_128 -> V_119 )
F_75 ( L_22 , V_128 ) ;
}
static void F_78 ( struct V_129 * V_130 )
{
printf ( L_23 V_109 L_24 ,
V_130 -> V_57 , V_130 -> V_131 ) ;
}
static void F_79 ( struct V_1 * V_2 ,
union V_37 * T_2 ,
struct V_39 * T_4 )
{
V_58 V_84 = F_80 ( V_2 -> V_5 ) ;
if ( T_2 -> V_35 . type != V_132 &&
! F_28 ( V_2 -> V_5 ) ) {
fputs ( L_25 , stdout ) ;
return;
}
if ( ( V_84 & V_133 ) )
printf ( L_26 , T_4 -> V_134 ) ;
if ( V_84 & V_135 )
printf ( L_27 V_109 L_28 , T_4 -> time ) ;
}
static void F_81 ( struct V_39 * T_4 , V_58 V_85 )
{
printf ( L_29 ) ;
if ( V_85 & V_136 )
printf ( L_30 V_112 L_11 ,
T_4 -> V_47 . V_73 ) ;
if ( V_85 & V_137 )
printf ( L_31 V_112 L_11 ,
T_4 -> V_47 . V_74 ) ;
if ( V_85 & V_138 ) {
V_58 V_80 ;
printf ( L_32 V_109 L_11 , T_4 -> V_47 . V_139 . V_111 ) ;
for ( V_80 = 0 ; V_80 < T_4 -> V_47 . V_139 . V_111 ; V_80 ++ ) {
struct V_140 * V_72 ;
V_72 = & T_4 -> V_47 . V_139 . V_141 [ V_80 ] ;
printf ( L_33 V_112
L_34 V_112 L_11 ,
V_72 -> V_75 , V_72 -> V_72 ) ;
}
} else
printf ( L_33 V_112 L_34 V_112 L_11 ,
T_4 -> V_47 . V_142 . V_75 , T_4 -> V_47 . V_142 . V_72 ) ;
}
static void F_82 ( struct V_1 * V_2 , union V_37 * T_2 ,
V_58 V_97 , struct V_39 * T_4 )
{
if ( ! V_143 )
return;
printf ( L_35 V_112 L_36 ,
V_97 , T_2 -> V_35 . V_57 , T_2 -> V_35 . type ) ;
F_83 ( T_2 ) ;
if ( T_4 )
F_79 ( V_2 , T_2 , T_4 ) ;
printf ( L_37 V_112 L_38 , V_97 ,
T_2 -> V_35 . V_57 , F_84 ( T_2 -> V_35 . type ) ) ;
}
static void F_85 ( struct V_10 * V_11 , union V_37 * T_2 ,
struct V_39 * T_4 )
{
V_58 V_84 ;
if ( ! V_143 )
return;
printf ( L_39 V_112 L_40 V_109 L_41 V_112 L_11 ,
T_2 -> V_35 . V_144 , T_4 -> V_61 , T_4 -> V_62 , T_4 -> V_145 ,
T_4 -> V_146 , T_4 -> V_147 ) ;
V_84 = V_11 -> V_12 . V_84 ;
if ( V_84 & V_148 )
F_69 ( T_4 ) ;
if ( V_84 & V_149 )
F_70 ( T_4 ) ;
if ( V_84 & V_150 )
F_76 ( T_4 ) ;
if ( V_84 & V_151 )
F_77 ( T_4 ) ;
if ( V_84 & V_152 )
F_78 ( & T_4 -> V_153 ) ;
if ( V_84 & V_154 )
printf ( L_42 V_109 L_11 , T_4 -> V_155 ) ;
if ( V_84 & V_156 )
printf ( L_43 V_112 L_11 , T_4 -> V_157 ) ;
if ( V_84 & V_158 )
printf ( L_44 V_112 L_11 , T_4 -> V_159 ) ;
if ( V_84 & V_160 )
F_81 ( T_4 , V_11 -> V_12 . V_85 ) ;
}
static struct V_40 *
F_86 ( struct V_1 * V_2 ,
union V_37 * T_2 ,
struct V_39 * T_4 )
{
const T_6 V_161 = T_2 -> V_35 . V_144 & V_162 ;
struct V_40 * V_40 ;
if ( V_163 &&
( ( V_161 == V_164 ) ||
( V_161 == V_165 ) ) ) {
T_9 V_61 ;
if ( T_2 -> V_35 . type == V_166
|| T_2 -> V_35 . type == V_167 )
V_61 = T_2 -> V_41 . V_61 ;
else
V_61 = T_4 -> V_61 ;
V_40 = F_87 ( V_2 , V_61 ) ;
if ( ! V_40 )
V_40 = F_88 ( V_2 ,
V_168 ) ;
return V_40 ;
}
return & V_2 -> V_7 . V_9 ;
}
static int F_89 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
union V_37 * T_2 ,
struct V_39 * T_4 ,
struct V_140 * V_169 ,
struct V_40 * V_40 )
{
struct V_170 * V_171 ;
V_171 = F_90 ( V_2 -> V_5 , V_169 -> V_75 ) ;
if ( V_171 ) {
T_4 -> V_75 = V_169 -> V_75 ;
T_4 -> V_146 = V_169 -> V_72 - V_171 -> V_146 ;
V_171 -> V_146 = V_169 -> V_72 ;
}
if ( ! V_171 || V_171 -> V_11 == NULL ) {
++ V_2 -> V_105 . V_172 ;
return 0 ;
}
return V_16 -> T_4 ( V_16 , T_2 , T_4 , V_171 -> V_11 , V_40 ) ;
}
static int F_91 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
union V_37 * T_2 ,
struct V_39 * T_4 ,
struct V_40 * V_40 )
{
int V_8 = - V_173 ;
V_58 V_80 ;
for ( V_80 = 0 ; V_80 < T_4 -> V_47 . V_139 . V_111 ; V_80 ++ ) {
V_8 = F_89 ( V_2 , V_16 , T_2 , T_4 ,
& T_4 -> V_47 . V_139 . V_141 [ V_80 ] ,
V_40 ) ;
if ( V_8 )
break;
}
return V_8 ;
}
static int
F_92 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
union V_37 * T_2 ,
struct V_39 * T_4 ,
struct V_10 * V_11 ,
struct V_40 * V_40 )
{
V_58 V_84 = V_11 -> V_12 . V_84 ;
V_58 V_85 = V_11 -> V_12 . V_85 ;
if ( ! ( V_84 & V_160 ) )
return V_16 -> T_4 ( V_16 , T_2 , T_4 , V_11 , V_40 ) ;
if ( V_85 & V_138 )
return F_91 ( V_2 , V_16 , T_2 , T_4 ,
V_40 ) ;
else
return F_89 ( V_2 , V_16 , T_2 , T_4 ,
& T_4 -> V_47 . V_142 , V_40 ) ;
}
int F_93 ( struct V_1 * V_2 ,
union V_37 * T_2 ,
struct V_39 * T_4 ,
struct V_15 * V_16 , V_58 V_97 )
{
struct V_10 * V_11 ;
struct V_40 * V_40 ;
F_82 ( V_2 , T_2 , V_97 , T_4 ) ;
V_11 = F_94 ( V_2 -> V_5 , T_4 -> V_75 ) ;
V_40 = F_86 ( V_2 , T_2 ,
T_4 ) ;
switch ( T_2 -> V_35 . type ) {
case V_132 :
F_85 ( V_11 , T_2 , T_4 ) ;
if ( V_11 == NULL ) {
++ V_2 -> V_105 . V_172 ;
return 0 ;
}
if ( V_40 == NULL ) {
++ V_2 -> V_105 . V_174 ;
return 0 ;
}
return F_92 ( V_2 , V_16 , T_2 ,
T_4 , V_11 , V_40 ) ;
case V_166 :
return V_16 -> V_41 ( V_16 , T_2 , T_4 , V_40 ) ;
case V_167 :
return V_16 -> V_42 ( V_16 , T_2 , T_4 , V_40 ) ;
case V_175 :
return V_16 -> V_43 ( V_16 , T_2 , T_4 , V_40 ) ;
case V_176 :
return V_16 -> V_44 ( V_16 , T_2 , T_4 , V_40 ) ;
case V_177 :
return V_16 -> exit ( V_16 , T_2 , T_4 , V_40 ) ;
case V_178 :
if ( V_16 -> V_45 == V_46 )
V_2 -> V_105 . V_179 += T_2 -> V_45 . V_45 ;
return V_16 -> V_45 ( V_16 , T_2 , T_4 , V_40 ) ;
case V_180 :
return V_16 -> V_47 ( V_16 , T_2 , T_4 , V_11 , V_40 ) ;
case V_181 :
return V_16 -> V_48 ( V_16 , T_2 , T_4 , V_40 ) ;
case V_182 :
return V_16 -> V_49 ( V_16 , T_2 , T_4 , V_40 ) ;
default:
++ V_2 -> V_105 . V_183 ;
return - 1 ;
}
}
static T_10 F_95 ( struct V_1 * V_2 ,
union V_37 * T_2 ,
struct V_15 * V_16 ,
V_58 V_97 )
{
int V_184 = F_96 ( V_2 -> V_4 ) ;
int V_185 ;
F_82 ( V_2 , T_2 , V_97 , NULL ) ;
switch ( T_2 -> V_35 . type ) {
case V_186 :
V_185 = V_16 -> V_12 ( V_16 , T_2 , & V_2 -> V_5 ) ;
if ( V_185 == 0 ) {
F_8 ( V_2 ) ;
F_18 ( V_2 ) ;
}
return V_185 ;
case V_187 :
return 0 ;
case V_188 :
F_97 ( V_184 , V_97 , V_189 ) ;
return V_16 -> V_50 ( V_16 , T_2 , V_2 ) ;
case V_190 :
return V_16 -> V_51 ( V_16 , T_2 , V_2 ) ;
case V_191 :
return V_16 -> V_52 ( V_16 , T_2 , V_2 ) ;
case V_192 :
return V_16 -> V_54 ( V_16 , T_2 , V_2 ) ;
default:
return - V_173 ;
}
}
int F_98 ( struct V_1 * V_2 ,
union V_37 * T_2 ,
struct V_39 * T_4 ,
struct V_15 * V_16 )
{
F_99 ( & V_2 -> V_105 , T_2 -> V_35 . type ) ;
if ( T_2 -> V_35 . type >= V_193 )
return F_95 ( V_2 , T_2 , V_16 , 0 ) ;
return F_93 ( V_2 , T_2 , T_4 , V_16 , 0 ) ;
}
static void F_100 ( union V_37 * T_2 , bool T_5 )
{
T_11 V_194 ;
V_194 = V_195 [ T_2 -> V_35 . type ] ;
if ( V_194 )
V_194 ( T_2 , T_5 ) ;
}
int F_101 ( struct V_1 * V_2 , T_12 V_97 ,
void * V_196 , T_7 V_197 ,
union V_37 * * V_198 ,
struct V_39 * T_4 )
{
union V_37 * T_2 ;
T_7 V_199 , V_200 ;
int V_184 ;
if ( V_2 -> V_201 && ! V_2 -> V_35 . V_202 ) {
T_2 = V_97 - V_2 -> V_203 +
V_2 -> V_204 ;
goto V_205;
}
if ( F_4 ( V_2 -> V_4 ) )
return - 1 ;
V_184 = F_96 ( V_2 -> V_4 ) ;
V_199 = sizeof( struct V_59 ) ;
if ( V_197 < V_199 )
return - 1 ;
if ( F_97 ( V_184 , V_97 , V_189 ) == ( T_12 ) - 1 ||
F_102 ( V_184 , & V_196 , V_199 ) != ( V_206 ) V_199 )
return - 1 ;
T_2 = (union V_37 * ) V_196 ;
if ( V_2 -> V_35 . V_202 )
F_103 ( & T_2 -> V_35 ) ;
if ( T_2 -> V_35 . V_57 < V_199 )
return - 1 ;
V_200 = T_2 -> V_35 . V_57 - V_199 ;
if ( F_102 ( V_184 , & V_196 , V_200 ) != ( V_206 ) V_200 )
return - 1 ;
if ( V_2 -> V_35 . V_202 )
F_100 ( T_2 , F_28 ( V_2 -> V_5 ) ) ;
V_205:
if ( T_4 && T_2 -> V_35 . type < V_193 &&
F_104 ( V_2 -> V_5 , T_2 , T_4 ) )
return - 1 ;
* V_198 = T_2 ;
return 0 ;
}
static T_10 F_105 ( struct V_1 * V_2 ,
union V_37 * T_2 ,
struct V_15 * V_16 ,
V_58 V_97 )
{
struct V_39 T_4 ;
int V_8 ;
if ( V_2 -> V_35 . V_202 )
F_100 ( T_2 , F_28 ( V_2 -> V_5 ) ) ;
if ( T_2 -> V_35 . type >= V_207 )
return - V_173 ;
F_99 ( & V_2 -> V_105 , T_2 -> V_35 . type ) ;
if ( T_2 -> V_35 . type >= V_193 )
return F_95 ( V_2 , T_2 , V_16 , V_97 ) ;
V_8 = F_104 ( V_2 -> V_5 , T_2 , & T_4 ) ;
if ( V_8 )
return V_8 ;
if ( V_16 -> V_18 ) {
V_8 = F_66 ( V_2 , T_2 , V_16 , & T_4 ,
V_97 ) ;
if ( V_8 != - V_102 )
return V_8 ;
}
return F_93 ( V_2 , T_2 , & T_4 , V_16 ,
V_97 ) ;
}
void F_103 ( struct V_59 * V_60 )
{
V_60 -> type = F_51 ( V_60 -> type ) ;
V_60 -> V_144 = F_106 ( V_60 -> V_144 ) ;
V_60 -> V_57 = F_106 ( V_60 -> V_57 ) ;
}
struct V_208 * F_107 ( struct V_1 * V_2 , T_13 V_61 )
{
return F_108 ( & V_2 -> V_7 . V_9 , - 1 , V_61 ) ;
}
static struct V_208 * F_109 ( struct V_1 * V_2 )
{
struct V_208 * V_208 ;
V_208 = F_108 ( & V_2 -> V_7 . V_9 , 0 , 0 ) ;
if ( V_208 == NULL || F_110 ( V_208 , L_45 , 0 ) ) {
F_3 ( L_46 ) ;
V_208 = NULL ;
}
return V_208 ;
}
static void F_111 ( const struct V_1 * V_2 ,
const struct V_15 * V_16 )
{
if ( V_16 -> V_45 == V_46 &&
V_2 -> V_105 . V_209 [ V_178 ] != 0 ) {
F_112 ( L_47
L_48 ,
V_2 -> V_105 . V_209 [ 0 ] ,
V_2 -> V_105 . V_209 [ V_178 ] ) ;
}
if ( V_2 -> V_105 . V_183 != 0 ) {
F_112 ( L_49
L_50
L_51
L_52
L_53 ,
V_2 -> V_105 . V_183 ) ;
}
if ( V_2 -> V_105 . V_172 != 0 ) {
F_112 ( L_54 ,
V_2 -> V_105 . V_172 ) ;
}
if ( V_2 -> V_105 . V_210 != 0 ) {
F_112 ( L_55
L_56
L_57 ,
V_2 -> V_105 . V_210 ,
V_2 -> V_105 . V_209 [ V_132 ] ) ;
}
if ( V_2 -> V_105 . V_174 != 0 ) {
F_112 ( L_58
L_59 ,
V_2 -> V_105 . V_174 ) ;
}
if ( V_2 -> V_105 . V_106 != 0 )
F_112 ( L_60 , V_2 -> V_105 . V_106 ) ;
}
static int F_113 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
int V_184 = F_96 ( V_2 -> V_4 ) ;
union V_37 * T_2 ;
T_14 V_57 , V_211 = 0 ;
void * V_196 = NULL ;
T_10 V_212 = 0 ;
V_58 V_213 ;
V_206 V_185 ;
void * V_79 ;
F_45 ( V_16 ) ;
V_213 = 0 ;
V_211 = sizeof( union V_37 ) ;
V_196 = malloc ( V_211 ) ;
if ( ! V_196 )
return - V_214 ;
V_215:
T_2 = V_196 ;
V_185 = F_102 ( V_184 , T_2 , sizeof( struct V_59 ) ) ;
if ( V_185 <= 0 ) {
if ( V_185 == 0 )
goto V_216;
F_3 ( L_61 ) ;
goto V_217;
}
if ( V_2 -> V_35 . V_202 )
F_103 ( & T_2 -> V_35 ) ;
V_57 = T_2 -> V_35 . V_57 ;
if ( V_57 < sizeof( struct V_59 ) ) {
F_3 ( L_62 ) ;
goto V_217;
}
if ( V_57 > V_211 ) {
void * V_101 = realloc ( V_196 , V_57 ) ;
if ( ! V_101 ) {
F_3 ( L_63 ) ;
goto V_217;
}
V_196 = V_101 ;
V_211 = V_57 ;
T_2 = V_196 ;
}
V_79 = T_2 ;
V_79 += sizeof( struct V_59 ) ;
if ( V_57 - sizeof( struct V_59 ) ) {
V_185 = F_102 ( V_184 , V_79 , V_57 - sizeof( struct V_59 ) ) ;
if ( V_185 <= 0 ) {
if ( V_185 == 0 ) {
F_3 ( L_64 ) ;
goto V_216;
}
F_3 ( L_65 ) ;
goto V_217;
}
}
if ( ( V_212 = F_105 ( V_2 , T_2 , V_16 , V_213 ) ) < 0 ) {
F_3 ( L_37 V_112 L_66 ,
V_213 , T_2 -> V_35 . V_57 , T_2 -> V_35 . type ) ;
V_185 = - V_173 ;
goto V_217;
}
V_213 += V_57 ;
if ( V_212 > 0 )
V_213 += V_212 ;
if ( ! F_114 () )
goto V_215;
V_216:
V_185 = F_65 ( V_2 , V_16 , V_218 ) ;
V_217:
free ( V_196 ) ;
F_111 ( V_2 , V_16 ) ;
F_115 ( & V_2 -> V_18 ) ;
return V_185 ;
}
static union V_37 *
F_116 ( struct V_1 * V_2 ,
V_58 V_213 , T_7 V_219 , char * V_196 )
{
union V_37 * T_2 ;
if ( V_213 + sizeof( T_2 -> V_35 ) > V_219 )
return NULL ;
T_2 = (union V_37 * ) ( V_196 + V_213 ) ;
if ( V_2 -> V_35 . V_202 )
F_103 ( & T_2 -> V_35 ) ;
if ( V_213 + T_2 -> V_35 . V_57 > V_219 ) {
if ( V_2 -> V_35 . V_202 )
F_103 ( & T_2 -> V_35 ) ;
return NULL ;
}
return T_2 ;
}
static int F_117 ( struct V_1 * V_2 ,
V_58 V_220 , V_58 V_221 ,
V_58 V_222 , struct V_15 * V_16 )
{
int V_184 = F_96 ( V_2 -> V_4 ) ;
V_58 V_213 , V_223 , V_97 , V_224 , V_57 ;
int V_185 , V_225 , V_226 , V_227 = 0 ;
T_7 V_219 ;
char * V_196 , * V_228 [ V_229 ] ;
union V_37 * T_2 ;
struct V_230 V_231 ;
T_10 V_212 ;
F_45 ( V_16 ) ;
V_223 = V_232 * ( V_220 / V_232 ) ;
V_97 = V_223 ;
V_213 = V_220 - V_223 ;
if ( V_221 && ( V_220 + V_221 < V_222 ) )
V_222 = V_220 + V_221 ;
F_118 ( & V_231 , V_222 , L_67 ) ;
V_219 = V_233 ;
if ( V_219 > V_222 ) {
V_219 = V_222 ;
V_2 -> V_201 = true ;
}
memset ( V_228 , 0 , sizeof( V_228 ) ) ;
V_225 = V_234 ;
V_226 = V_235 ;
if ( V_2 -> V_35 . V_202 ) {
V_225 |= V_236 ;
V_226 = V_237 ;
}
V_238:
V_196 = V_41 ( NULL , V_219 , V_225 , V_226 , V_184 ,
V_97 ) ;
if ( V_196 == V_239 ) {
F_3 ( L_68 ) ;
V_185 = - V_214 ;
goto V_217;
}
V_228 [ V_227 ] = V_196 ;
V_227 = ( V_227 + 1 ) & ( F_119 ( V_228 ) - 1 ) ;
V_224 = V_97 + V_213 ;
if ( V_2 -> V_201 ) {
V_2 -> V_204 = V_196 ;
V_2 -> V_203 = V_97 ;
}
V_215:
T_2 = F_116 ( V_2 , V_213 , V_219 , V_196 ) ;
if ( ! T_2 ) {
if ( V_228 [ V_227 ] ) {
F_120 ( V_228 [ V_227 ] , V_219 ) ;
V_228 [ V_227 ] = NULL ;
}
V_223 = V_232 * ( V_213 / V_232 ) ;
V_97 += V_223 ;
V_213 -= V_223 ;
goto V_238;
}
V_57 = T_2 -> V_35 . V_57 ;
if ( V_57 < sizeof( struct V_59 ) ||
( V_212 = F_105 ( V_2 , T_2 , V_16 , V_224 ) )
< 0 ) {
F_3 ( L_37 V_112 L_66 ,
V_97 + V_213 , T_2 -> V_35 . V_57 ,
T_2 -> V_35 . type ) ;
V_185 = - V_173 ;
goto V_217;
}
if ( V_212 )
V_57 += V_212 ;
V_213 += V_57 ;
V_224 += V_57 ;
F_121 ( & V_231 , V_57 ) ;
if ( F_114 () )
goto V_17;
if ( V_224 < V_222 )
goto V_215;
V_17:
V_185 = F_65 ( V_2 , V_16 , V_218 ) ;
V_217:
F_122 () ;
F_111 ( V_2 , V_16 ) ;
F_115 ( & V_2 -> V_18 ) ;
V_2 -> V_201 = false ;
return V_185 ;
}
int F_123 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
V_58 V_57 = F_124 ( V_2 -> V_4 ) ;
int V_185 ;
if ( F_109 ( V_2 ) == NULL )
return - V_108 ;
if ( ! F_4 ( V_2 -> V_4 ) )
V_185 = F_117 ( V_2 ,
V_2 -> V_35 . V_220 ,
V_2 -> V_35 . V_221 ,
V_57 , V_16 ) ;
else
V_185 = F_113 ( V_2 , V_16 ) ;
return V_185 ;
}
bool F_125 ( struct V_1 * V_2 , const char * V_240 )
{
struct V_10 * V_11 ;
F_17 (session->evlist, evsel) {
if ( V_11 -> V_12 . type == V_241 )
return true ;
}
F_3 ( L_69 , V_240 ) ;
return false ;
}
int F_126 ( struct V_242 * * V_243 ,
const char * V_244 , V_58 V_147 )
{
char * V_245 ;
enum V_246 V_80 ;
struct V_247 * V_248 ;
V_248 = F_21 ( sizeof( struct V_247 ) ) ;
if ( V_248 == NULL )
return - V_108 ;
V_248 -> V_249 = F_127 ( V_244 ) ;
if ( V_248 -> V_249 == NULL ) {
free ( V_248 ) ;
return - V_108 ;
}
V_245 = strchr ( V_248 -> V_249 , ']' ) ;
if ( V_245 )
* V_245 = '\0' ;
V_248 -> V_147 = V_147 ;
for ( V_80 = 0 ; V_80 < V_250 ; ++ V_80 ) {
struct V_251 * V_251 = F_128 ( V_243 [ V_80 ] ) ;
V_251 -> V_247 = V_248 ;
}
return 0 ;
}
T_7 F_129 ( struct V_1 * V_2 , T_15 * V_252 )
{
return F_130 ( & V_2 -> V_7 , V_252 ) ;
}
T_7 F_131 ( struct V_1 * V_2 , T_15 * V_252 ,
bool (V_212)( struct V_253 * V_253 , int V_254 ) , int V_254 )
{
return F_132 ( & V_2 -> V_7 , V_252 , V_212 , V_254 ) ;
}
T_7 F_133 ( struct V_1 * V_2 , T_15 * V_252 )
{
T_7 V_8 = fprintf ( V_252 , L_70 ) ;
V_8 += F_134 ( & V_2 -> V_105 , V_252 ) ;
return V_8 ;
}
T_7 F_135 ( struct V_1 * V_2 , T_15 * V_252 )
{
return F_136 ( & V_2 -> V_7 . V_9 , V_252 ) ;
}
struct V_10 * F_137 ( struct V_1 * V_2 ,
unsigned int type )
{
struct V_10 * V_255 ;
F_17 (session->evlist, pos) {
if ( V_255 -> V_12 . type == type )
return V_255 ;
}
return NULL ;
}
void F_138 ( struct V_10 * V_11 , struct V_39 * T_4 ,
struct V_256 * V_257 ,
unsigned int V_258 , unsigned int V_259 )
{
struct V_260 * V_261 ;
int V_262 = V_258 & V_263 ;
int V_264 = V_258 & V_265 ;
int V_266 = V_258 & V_267 ;
int V_268 = V_258 & V_269 ;
int V_270 = V_258 & V_271 ;
int V_272 = V_258 & V_273 ;
char V_96 = V_270 ? ' ' : '\t' ;
if ( V_274 . V_275 && T_4 -> V_110 ) {
struct V_256 V_276 ;
if ( F_139 ( V_257 -> V_208 , V_11 ,
T_4 , NULL , NULL ,
V_277 ) != 0 ) {
if ( V_278 )
error ( L_71 ) ;
return;
}
F_140 ( & V_279 ) ;
if ( V_268 )
V_276 = * V_257 ;
while ( V_259 ) {
V_58 V_147 = 0 ;
V_261 = F_141 ( & V_279 ) ;
if ( ! V_261 )
break;
if ( V_261 -> V_280 && V_261 -> V_280 -> V_281 )
goto V_282;
if ( V_262 )
printf ( L_72 V_112 , V_96 , V_261 -> V_145 ) ;
if ( V_261 -> V_242 )
V_147 = V_261 -> V_242 -> V_283 ( V_261 -> V_242 , V_261 -> V_145 ) ;
if ( V_264 ) {
printf ( L_28 ) ;
if ( V_268 ) {
V_276 . V_147 = V_147 ;
V_276 . V_242 = V_261 -> V_242 ;
F_142 ( V_261 -> V_280 , & V_276 , stdout ) ;
} else
F_143 ( V_261 -> V_280 , stdout ) ;
}
if ( V_266 ) {
printf ( L_73 ) ;
F_144 ( V_261 -> V_242 , stdout ) ;
printf ( L_74 ) ;
}
if ( V_272 )
F_145 ( V_261 -> V_242 , V_147 , L_75 ,
stdout ) ;
if ( ! V_270 )
printf ( L_11 ) ;
V_259 -- ;
V_282:
F_146 ( & V_279 ) ;
}
} else {
if ( V_257 -> V_280 && V_257 -> V_280 -> V_281 )
return;
if ( V_262 )
printf ( L_76 V_112 , T_4 -> V_145 ) ;
if ( V_264 ) {
printf ( L_28 ) ;
if ( V_268 )
F_142 ( V_257 -> V_280 , V_257 ,
stdout ) ;
else
F_143 ( V_257 -> V_280 , stdout ) ;
}
if ( V_266 ) {
printf ( L_73 ) ;
F_144 ( V_257 -> V_242 , stdout ) ;
printf ( L_74 ) ;
}
if ( V_272 )
F_145 ( V_257 -> V_242 , V_257 -> V_147 , L_75 , stdout ) ;
}
}
int F_147 ( struct V_1 * V_2 ,
const char * V_284 , unsigned long * V_285 )
{
int V_80 , V_185 = - 1 ;
struct V_286 * V_242 ;
for ( V_80 = 0 ; V_80 < V_287 ; ++ V_80 ) {
struct V_10 * V_11 ;
V_11 = F_137 ( V_2 , V_80 ) ;
if ( ! V_11 )
continue;
if ( ! ( V_11 -> V_12 . V_84 & V_133 ) ) {
F_3 ( L_77
L_78 ) ;
return - 1 ;
}
}
V_242 = F_148 ( V_284 ) ;
if ( V_242 == NULL ) {
F_3 ( L_79 ) ;
return - 1 ;
}
for ( V_80 = 0 ; V_80 < V_242 -> V_111 ; V_80 ++ ) {
int V_134 = V_242 -> V_242 [ V_80 ] ;
if ( V_134 >= V_288 ) {
F_3 ( L_80
L_81 , V_134 ) ;
goto V_289;
}
F_149 ( V_134 , V_285 ) ;
}
V_185 = 0 ;
V_289:
F_150 ( V_242 ) ;
return V_185 ;
}
void F_151 ( struct V_1 * V_2 , T_15 * V_252 ,
bool V_290 )
{
struct V_291 V_292 ;
int V_184 , V_8 ;
if ( V_2 == NULL || V_252 == NULL )
return;
V_184 = F_96 ( V_2 -> V_4 ) ;
V_8 = F_152 ( V_184 , & V_292 ) ;
if ( V_8 == - 1 )
return;
fprintf ( V_252 , L_82 ) ;
fprintf ( V_252 , L_83 , ctime ( & V_292 . V_293 ) ) ;
F_153 ( V_2 , V_252 , V_290 ) ;
fprintf ( V_252 , L_84 ) ;
}
int F_154 ( struct V_1 * V_2 ,
const struct V_294 * V_295 ,
T_7 V_296 )
{
struct V_10 * V_11 ;
T_7 V_80 ;
int V_185 ;
for ( V_80 = 0 ; V_80 < V_296 ; V_80 ++ ) {
V_11 = F_155 ( V_2 -> V_5 , V_295 [ V_80 ] . V_249 ) ;
if ( V_11 == NULL )
continue;
V_185 = - V_297 ;
if ( V_11 -> V_298 != NULL )
goto V_17;
V_11 -> V_298 = V_295 [ V_80 ] . V_298 ;
}
V_185 = 0 ;
V_17:
return V_185 ;
}
int F_156 ( struct V_15 * V_16 V_36 ,
union V_37 * T_2 ,
struct V_1 * V_2 )
{
struct V_38 * V_5 = V_2 -> V_5 ;
struct V_299 * V_300 = & T_2 -> V_54 ;
T_7 V_80 , V_111 , V_301 ;
V_301 = ( V_300 -> V_35 . V_57 - sizeof( struct V_299 ) ) /
sizeof( struct V_302 ) ;
V_111 = V_300 -> V_111 ;
if ( V_111 > V_301 )
return - V_173 ;
if ( V_143 )
fprintf ( stdout , L_85 , V_111 ) ;
for ( V_80 = 0 ; V_80 < V_111 ; V_80 ++ ) {
struct V_302 * V_303 = & V_300 -> V_115 [ V_80 ] ;
struct V_170 * V_171 ;
if ( V_143 ) {
fprintf ( stdout , L_86 V_109 , V_303 -> V_75 ) ;
fprintf ( stdout , L_87 V_109 , V_303 -> V_304 ) ;
fprintf ( stdout , L_88 V_305 , V_303 -> V_134 ) ;
fprintf ( stdout , L_89 V_305 L_11 , V_303 -> V_62 ) ;
}
V_171 = F_90 ( V_5 , V_303 -> V_75 ) ;
if ( ! V_171 )
return - V_306 ;
V_171 -> V_304 = V_303 -> V_304 ;
V_171 -> V_134 = V_303 -> V_134 ;
V_171 -> V_62 = V_303 -> V_62 ;
}
return 0 ;
}
int F_157 ( struct V_15 * V_16 ,
T_16 V_307 ,
struct V_38 * V_5 ,
struct V_40 * V_40 )
{
union V_37 * V_308 ;
struct V_10 * V_11 ;
T_7 V_111 = 0 , V_80 = 0 , V_309 , V_301 , V_310 ;
int V_185 ;
F_158 ( L_90 ) ;
V_301 = ( V_311 - sizeof( struct V_299 ) ) /
sizeof( struct V_302 ) ;
F_17 (evlist, evsel)
V_111 += V_11 -> V_312 ;
V_310 = V_111 > V_301 ? V_301 : V_111 ;
V_309 = sizeof( struct V_299 ) + V_310 * sizeof( struct V_302 ) ;
V_308 = F_21 ( V_309 ) ;
if ( ! V_308 )
return - V_108 ;
V_308 -> V_54 . V_35 . type = V_192 ;
V_308 -> V_54 . V_35 . V_57 = V_309 ;
V_308 -> V_54 . V_111 = V_310 ;
F_17 (evlist, evsel) {
T_9 V_313 ;
for ( V_313 = 0 ; V_313 < V_11 -> V_312 ; V_313 ++ ) {
struct V_302 * V_303 ;
struct V_170 * V_171 ;
if ( V_80 >= V_310 ) {
V_185 = V_307 ( V_16 , V_308 , NULL , V_40 ) ;
if ( V_185 )
goto V_217;
V_111 -= V_310 ;
V_80 = 0 ;
}
V_303 = & V_308 -> V_54 . V_115 [ V_80 ++ ] ;
V_303 -> V_75 = V_11 -> V_75 [ V_313 ] ;
V_171 = F_90 ( V_5 , V_303 -> V_75 ) ;
if ( ! V_171 ) {
free ( V_308 ) ;
return - V_306 ;
}
V_303 -> V_304 = V_171 -> V_304 ;
V_303 -> V_134 = V_171 -> V_134 ;
V_303 -> V_62 = V_171 -> V_62 ;
}
}
V_309 = sizeof( struct V_299 ) + V_111 * sizeof( struct V_302 ) ;
V_308 -> V_54 . V_35 . V_57 = V_309 ;
V_308 -> V_54 . V_111 = V_111 ;
V_185 = V_307 ( V_16 , V_308 , NULL , V_40 ) ;
V_217:
free ( V_308 ) ;
return V_185 ;
}
