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
void F_44 ( struct V_15 * V_16 )
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
}
static void F_45 ( union V_37 * T_2 , void * V_54 )
{
void * V_55 = ( void * ) T_2 + T_2 -> V_35 . V_56 ;
int V_56 = V_55 - V_54 ;
F_46 ( V_56 % sizeof( V_57 ) ) ;
F_47 ( V_54 , V_56 ) ;
}
static void F_48 ( union V_37 * T_2 ,
bool T_5 V_36 )
{
struct V_58 * V_59 = & T_2 -> V_35 ;
F_47 ( V_59 + 1 , T_2 -> V_35 . V_56 - sizeof( * V_59 ) ) ;
}
static void F_49 ( union V_37 * T_2 , bool T_5 )
{
T_2 -> V_43 . V_60 = F_50 ( T_2 -> V_43 . V_60 ) ;
T_2 -> V_43 . V_61 = F_50 ( T_2 -> V_43 . V_61 ) ;
if ( T_5 ) {
void * V_54 = & T_2 -> V_43 . V_43 ;
V_54 += F_51 ( strlen ( V_54 ) + 1 , sizeof( V_57 ) ) ;
F_45 ( T_2 , V_54 ) ;
}
}
static void F_52 ( union V_37 * T_2 ,
bool T_5 )
{
T_2 -> V_41 . V_60 = F_50 ( T_2 -> V_41 . V_60 ) ;
T_2 -> V_41 . V_61 = F_50 ( T_2 -> V_41 . V_61 ) ;
T_2 -> V_41 . V_62 = F_53 ( T_2 -> V_41 . V_62 ) ;
T_2 -> V_41 . V_63 = F_53 ( T_2 -> V_41 . V_63 ) ;
T_2 -> V_41 . V_64 = F_53 ( T_2 -> V_41 . V_64 ) ;
if ( T_5 ) {
void * V_54 = & T_2 -> V_41 . V_65 ;
V_54 += F_51 ( strlen ( V_54 ) + 1 , sizeof( V_57 ) ) ;
F_45 ( T_2 , V_54 ) ;
}
}
static void F_54 ( union V_37 * T_2 ,
bool T_5 )
{
T_2 -> V_42 . V_60 = F_50 ( T_2 -> V_42 . V_60 ) ;
T_2 -> V_42 . V_61 = F_50 ( T_2 -> V_42 . V_61 ) ;
T_2 -> V_42 . V_62 = F_53 ( T_2 -> V_42 . V_62 ) ;
T_2 -> V_42 . V_63 = F_53 ( T_2 -> V_42 . V_63 ) ;
T_2 -> V_42 . V_64 = F_53 ( T_2 -> V_42 . V_64 ) ;
T_2 -> V_42 . V_66 = F_50 ( T_2 -> V_42 . V_66 ) ;
T_2 -> V_42 . V_67 = F_50 ( T_2 -> V_42 . V_67 ) ;
T_2 -> V_42 . V_68 = F_53 ( T_2 -> V_42 . V_68 ) ;
if ( T_5 ) {
void * V_54 = & T_2 -> V_42 . V_65 ;
V_54 += F_51 ( strlen ( V_54 ) + 1 , sizeof( V_57 ) ) ;
F_45 ( T_2 , V_54 ) ;
}
}
static void F_55 ( union V_37 * T_2 , bool T_5 )
{
T_2 -> V_44 . V_60 = F_50 ( T_2 -> V_44 . V_60 ) ;
T_2 -> V_44 . V_61 = F_50 ( T_2 -> V_44 . V_61 ) ;
T_2 -> V_44 . V_69 = F_50 ( T_2 -> V_44 . V_69 ) ;
T_2 -> V_44 . V_70 = F_50 ( T_2 -> V_44 . V_70 ) ;
T_2 -> V_44 . time = F_53 ( T_2 -> V_44 . time ) ;
if ( T_5 )
F_45 ( T_2 , & T_2 -> V_44 + 1 ) ;
}
static void F_56 ( union V_37 * T_2 , bool T_5 )
{
T_2 -> V_47 . V_60 = F_50 ( T_2 -> V_47 . V_60 ) ;
T_2 -> V_47 . V_61 = F_50 ( T_2 -> V_47 . V_61 ) ;
T_2 -> V_47 . V_71 = F_53 ( T_2 -> V_47 . V_71 ) ;
T_2 -> V_47 . V_72 = F_53 ( T_2 -> V_47 . V_72 ) ;
T_2 -> V_47 . V_73 = F_53 ( T_2 -> V_47 . V_73 ) ;
T_2 -> V_47 . V_74 = F_53 ( T_2 -> V_47 . V_74 ) ;
if ( T_5 )
F_45 ( T_2 , & T_2 -> V_47 + 1 ) ;
}
static void F_57 ( union V_37 * T_2 ,
bool T_5 )
{
T_2 -> V_48 . time = F_53 ( T_2 -> V_48 . time ) ;
T_2 -> V_48 . V_74 = F_53 ( T_2 -> V_48 . V_74 ) ;
T_2 -> V_48 . V_75 = F_53 ( T_2 -> V_48 . V_75 ) ;
if ( T_5 )
F_45 ( T_2 , & T_2 -> V_48 + 1 ) ;
}
static T_6 F_58 ( T_6 V_76 )
{
int V_77 = ( V_76 >> 4 ) | ( ( V_76 & 0xf ) << 4 ) ;
V_77 = ( ( V_77 & 0xcc ) >> 2 ) | ( ( V_77 & 0x33 ) << 2 ) ;
V_77 = ( ( V_77 & 0xaa ) >> 1 ) | ( ( V_77 & 0x55 ) << 1 ) ;
return ( T_6 ) V_77 ;
}
static void F_59 ( T_6 * V_78 , unsigned V_63 )
{
unsigned V_79 ;
for ( V_79 = 0 ; V_79 < V_63 ; V_79 ++ ) {
* V_78 = F_58 ( * V_78 ) ;
V_78 ++ ;
}
}
void F_60 ( struct V_80 * V_12 )
{
V_12 -> type = F_50 ( V_12 -> type ) ;
V_12 -> V_56 = F_50 ( V_12 -> V_56 ) ;
V_12 -> V_81 = F_53 ( V_12 -> V_81 ) ;
V_12 -> V_82 = F_53 ( V_12 -> V_82 ) ;
V_12 -> V_83 = F_53 ( V_12 -> V_83 ) ;
V_12 -> V_84 = F_53 ( V_12 -> V_84 ) ;
V_12 -> V_85 = F_50 ( V_12 -> V_85 ) ;
V_12 -> V_86 = F_50 ( V_12 -> V_86 ) ;
V_12 -> V_87 = F_53 ( V_12 -> V_87 ) ;
V_12 -> V_88 = F_53 ( V_12 -> V_88 ) ;
V_12 -> V_89 = F_53 ( V_12 -> V_89 ) ;
V_12 -> V_90 = F_53 ( V_12 -> V_90 ) ;
V_12 -> V_91 = F_50 ( V_12 -> V_91 ) ;
F_59 ( ( T_6 * ) ( & V_12 -> V_84 + 1 ) , sizeof( V_57 ) ) ;
}
static void F_61 ( union V_37 * T_2 ,
bool T_5 V_36 )
{
T_7 V_56 ;
F_60 ( & T_2 -> V_12 . V_12 ) ;
V_56 = T_2 -> V_35 . V_56 ;
V_56 -= ( void * ) & T_2 -> V_12 . V_74 - ( void * ) T_2 ;
F_47 ( T_2 -> V_12 . V_74 , V_56 ) ;
}
static void F_62 ( union V_37 * T_2 ,
bool T_5 V_36 )
{
T_2 -> V_92 . V_92 . V_93 =
F_53 ( T_2 -> V_92 . V_92 . V_93 ) ;
}
static void F_63 ( union V_37 * T_2 ,
bool T_5 V_36 )
{
T_2 -> V_50 . V_56 = F_50 ( T_2 -> V_50 . V_56 ) ;
}
static int V_53 ( struct V_15 * V_16 ,
union V_37 * T_2 V_36 ,
struct V_1 * V_2 )
{
return F_64 ( V_2 , V_16 , V_94 ) ;
}
int F_65 ( struct V_1 * V_95 , union V_37 * T_2 ,
struct V_15 * V_16 , struct V_39 * T_4 ,
V_57 V_96 )
{
struct V_18 * V_97 = & V_95 -> V_18 ;
V_57 V_98 = T_4 -> time ;
struct V_99 * V_100 ;
if ( ! V_98 || V_98 == ~ 0ULL )
return - V_101 ;
if ( V_98 < V_97 -> V_102 ) {
F_66 ( 1 , L_8 ) ;
F_67 ( V_98 , L_9 ) ;
F_67 ( V_97 -> V_102 , L_10 ,
V_97 -> V_103 ) ;
if ( V_97 -> V_103 != V_104 )
return - V_105 ;
}
V_100 = F_68 ( V_97 , V_98 , T_2 ) ;
if ( ! V_100 ) {
F_64 ( V_95 , V_16 , V_104 ) ;
V_100 = F_68 ( V_97 , V_98 , T_2 ) ;
}
if ( ! V_100 )
return - V_106 ;
V_100 -> V_96 = V_96 ;
return 0 ;
}
static void F_69 ( struct V_39 * T_4 )
{
unsigned int V_79 ;
printf ( L_11 V_107 L_12 , T_4 -> V_108 -> V_109 ) ;
for ( V_79 = 0 ; V_79 < T_4 -> V_108 -> V_109 ; V_79 ++ )
printf ( L_13 V_110 L_12 ,
V_79 , T_4 -> V_108 -> V_111 [ V_79 ] ) ;
}
static void F_70 ( struct V_39 * T_4 )
{
T_8 V_79 ;
printf ( L_14 V_107 L_12 , T_4 -> V_112 -> V_109 ) ;
for ( V_79 = 0 ; V_79 < T_4 -> V_112 -> V_109 ; V_79 ++ )
printf ( L_15 V_107 L_16 V_110 L_17 V_110 L_12 ,
V_79 , T_4 -> V_112 -> V_113 [ V_79 ] . V_114 ,
T_4 -> V_112 -> V_113 [ V_79 ] . V_115 ) ;
}
static void F_71 ( V_57 V_116 , V_57 * V_117 )
{
unsigned V_118 , V_79 = 0 ;
F_72 (rid, (unsigned long *) &mask, sizeof(mask) * 8 ) {
V_57 V_119 = V_117 [ V_79 ++ ] ;
printf ( L_18 V_110 L_12 ,
F_73 ( V_118 ) , V_119 ) ;
}
}
static void F_74 ( struct V_39 * T_4 )
{
struct V_120 * V_121 = & T_4 -> V_121 ;
if ( V_121 -> V_117 ) {
V_57 V_116 = V_121 -> V_116 ;
printf ( L_19 V_110 L_12 , V_116 ) ;
F_71 ( V_116 , V_121 -> V_117 ) ;
}
}
static void F_75 ( struct V_122 * V_123 )
{
printf ( L_20 V_107 L_21 ,
V_123 -> V_56 , V_123 -> V_124 ) ;
}
static void F_76 ( struct V_1 * V_2 ,
union V_37 * T_2 ,
struct V_39 * T_4 )
{
V_57 V_83 = F_77 ( V_2 -> V_5 ) ;
if ( T_2 -> V_35 . type != V_125 &&
! F_28 ( V_2 -> V_5 ) ) {
fputs ( L_22 , stdout ) ;
return;
}
if ( ( V_83 & V_126 ) )
printf ( L_23 , T_4 -> V_127 ) ;
if ( V_83 & V_128 )
printf ( L_24 V_107 L_25 , T_4 -> time ) ;
}
static void F_78 ( struct V_39 * T_4 , V_57 V_84 )
{
printf ( L_26 ) ;
if ( V_84 & V_129 )
printf ( L_27 V_110 L_12 ,
T_4 -> V_47 . V_72 ) ;
if ( V_84 & V_130 )
printf ( L_28 V_110 L_12 ,
T_4 -> V_47 . V_73 ) ;
if ( V_84 & V_131 ) {
V_57 V_79 ;
printf ( L_29 V_107 L_12 , T_4 -> V_47 . V_132 . V_109 ) ;
for ( V_79 = 0 ; V_79 < T_4 -> V_47 . V_132 . V_109 ; V_79 ++ ) {
struct V_133 * V_71 ;
V_71 = & T_4 -> V_47 . V_132 . V_134 [ V_79 ] ;
printf ( L_30 V_110
L_31 V_110 L_12 ,
V_71 -> V_74 , V_71 -> V_71 ) ;
}
} else
printf ( L_30 V_110 L_31 V_110 L_12 ,
T_4 -> V_47 . V_135 . V_74 , T_4 -> V_47 . V_135 . V_71 ) ;
}
static void F_79 ( struct V_1 * V_2 , union V_37 * T_2 ,
V_57 V_96 , struct V_39 * T_4 )
{
if ( ! V_136 )
return;
printf ( L_32 V_110 L_33 ,
V_96 , T_2 -> V_35 . V_56 , T_2 -> V_35 . type ) ;
F_80 ( T_2 ) ;
if ( T_4 )
F_76 ( V_2 , T_2 , T_4 ) ;
printf ( L_34 V_110 L_35 , V_96 ,
T_2 -> V_35 . V_56 , F_81 ( T_2 -> V_35 . type ) ) ;
}
static void F_82 ( struct V_10 * V_11 , union V_37 * T_2 ,
struct V_39 * T_4 )
{
V_57 V_83 ;
if ( ! V_136 )
return;
printf ( L_36 V_110 L_37 V_107 L_38 V_110 L_12 ,
T_2 -> V_35 . V_137 , T_4 -> V_60 , T_4 -> V_61 , T_4 -> V_138 ,
T_4 -> V_139 , T_4 -> V_140 ) ;
V_83 = V_11 -> V_12 . V_83 ;
if ( V_83 & V_141 )
F_69 ( T_4 ) ;
if ( V_83 & V_142 )
F_70 ( T_4 ) ;
if ( V_83 & V_143 )
F_74 ( T_4 ) ;
if ( V_83 & V_144 )
F_75 ( & T_4 -> V_145 ) ;
if ( V_83 & V_146 )
printf ( L_39 V_107 L_12 , T_4 -> V_147 ) ;
if ( V_83 & V_148 )
printf ( L_40 V_110 L_12 , T_4 -> V_149 ) ;
if ( V_83 & V_150 )
printf ( L_41 V_110 L_12 , T_4 -> V_151 ) ;
if ( V_83 & V_152 )
F_78 ( T_4 , V_11 -> V_12 . V_84 ) ;
}
static struct V_40 *
F_83 ( struct V_1 * V_2 ,
union V_37 * T_2 ,
struct V_39 * T_4 )
{
const T_6 V_153 = T_2 -> V_35 . V_137 & V_154 ;
struct V_40 * V_40 ;
if ( V_155 &&
( ( V_153 == V_156 ) ||
( V_153 == V_157 ) ) ) {
T_9 V_60 ;
if ( T_2 -> V_35 . type == V_158
|| T_2 -> V_35 . type == V_159 )
V_60 = T_2 -> V_41 . V_60 ;
else
V_60 = T_4 -> V_60 ;
V_40 = F_84 ( V_2 , V_60 ) ;
if ( ! V_40 )
V_40 = F_85 ( V_2 ,
V_160 ) ;
return V_40 ;
}
return & V_2 -> V_7 . V_9 ;
}
static int F_86 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
union V_37 * T_2 ,
struct V_39 * T_4 ,
struct V_133 * V_161 ,
struct V_40 * V_40 )
{
struct V_162 * V_163 ;
V_163 = F_87 ( V_2 -> V_5 , V_161 -> V_74 ) ;
if ( V_163 ) {
T_4 -> V_74 = V_161 -> V_74 ;
T_4 -> V_139 = V_161 -> V_71 - V_163 -> V_139 ;
V_163 -> V_139 = V_161 -> V_71 ;
}
if ( ! V_163 || V_163 -> V_11 == NULL ) {
++ V_2 -> V_164 . V_165 ;
return 0 ;
}
return V_16 -> T_4 ( V_16 , T_2 , T_4 , V_163 -> V_11 , V_40 ) ;
}
static int F_88 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
union V_37 * T_2 ,
struct V_39 * T_4 ,
struct V_40 * V_40 )
{
int V_8 = - V_105 ;
V_57 V_79 ;
for ( V_79 = 0 ; V_79 < T_4 -> V_47 . V_132 . V_109 ; V_79 ++ ) {
V_8 = F_86 ( V_2 , V_16 , T_2 , T_4 ,
& T_4 -> V_47 . V_132 . V_134 [ V_79 ] ,
V_40 ) ;
if ( V_8 )
break;
}
return V_8 ;
}
static int
F_89 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
union V_37 * T_2 ,
struct V_39 * T_4 ,
struct V_10 * V_11 ,
struct V_40 * V_40 )
{
V_57 V_83 = V_11 -> V_12 . V_83 ;
V_57 V_84 = V_11 -> V_12 . V_84 ;
if ( ! ( V_83 & V_152 ) )
return V_16 -> T_4 ( V_16 , T_2 , T_4 , V_11 , V_40 ) ;
if ( V_84 & V_131 )
return F_88 ( V_2 , V_16 , T_2 , T_4 ,
V_40 ) ;
else
return F_86 ( V_2 , V_16 , T_2 , T_4 ,
& T_4 -> V_47 . V_135 , V_40 ) ;
}
int F_90 ( struct V_1 * V_2 ,
union V_37 * T_2 ,
struct V_39 * T_4 ,
struct V_15 * V_16 , V_57 V_96 )
{
struct V_10 * V_11 ;
struct V_40 * V_40 ;
F_79 ( V_2 , T_2 , V_96 , T_4 ) ;
V_11 = F_91 ( V_2 -> V_5 , T_4 -> V_74 ) ;
V_40 = F_83 ( V_2 , T_2 ,
T_4 ) ;
switch ( T_2 -> V_35 . type ) {
case V_125 :
F_82 ( V_11 , T_2 , T_4 ) ;
if ( V_11 == NULL ) {
++ V_2 -> V_164 . V_165 ;
return 0 ;
}
if ( V_40 == NULL ) {
++ V_2 -> V_164 . V_166 ;
return 0 ;
}
return F_89 ( V_2 , V_16 , T_2 ,
T_4 , V_11 , V_40 ) ;
case V_158 :
return V_16 -> V_41 ( V_16 , T_2 , T_4 , V_40 ) ;
case V_159 :
return V_16 -> V_42 ( V_16 , T_2 , T_4 , V_40 ) ;
case V_167 :
return V_16 -> V_43 ( V_16 , T_2 , T_4 , V_40 ) ;
case V_168 :
return V_16 -> V_44 ( V_16 , T_2 , T_4 , V_40 ) ;
case V_169 :
return V_16 -> exit ( V_16 , T_2 , T_4 , V_40 ) ;
case V_170 :
if ( V_16 -> V_45 == V_46 )
V_2 -> V_164 . V_171 += T_2 -> V_45 . V_45 ;
return V_16 -> V_45 ( V_16 , T_2 , T_4 , V_40 ) ;
case V_172 :
return V_16 -> V_47 ( V_16 , T_2 , T_4 , V_11 , V_40 ) ;
case V_173 :
return V_16 -> V_48 ( V_16 , T_2 , T_4 , V_40 ) ;
case V_174 :
return V_16 -> V_49 ( V_16 , T_2 , T_4 , V_40 ) ;
default:
++ V_2 -> V_164 . V_175 ;
return - 1 ;
}
}
static T_10 F_92 ( struct V_1 * V_2 ,
union V_37 * T_2 ,
struct V_15 * V_16 ,
V_57 V_96 )
{
int V_176 = F_93 ( V_2 -> V_4 ) ;
int V_177 ;
F_79 ( V_2 , T_2 , V_96 , NULL ) ;
switch ( T_2 -> V_35 . type ) {
case V_178 :
V_177 = V_16 -> V_12 ( V_16 , T_2 , & V_2 -> V_5 ) ;
if ( V_177 == 0 ) {
F_8 ( V_2 ) ;
F_18 ( V_2 ) ;
}
return V_177 ;
case V_179 :
return 0 ;
case V_180 :
F_94 ( V_176 , V_96 , V_181 ) ;
return V_16 -> V_50 ( V_16 , T_2 , V_2 ) ;
case V_182 :
return V_16 -> V_51 ( V_16 , T_2 , V_2 ) ;
case V_183 :
return V_16 -> V_52 ( V_16 , T_2 , V_2 ) ;
default:
return - V_105 ;
}
}
static void F_95 ( union V_37 * T_2 , bool T_5 )
{
T_11 V_184 ;
V_184 = V_185 [ T_2 -> V_35 . type ] ;
if ( V_184 )
V_184 ( T_2 , T_5 ) ;
}
int F_96 ( struct V_1 * V_2 , T_12 V_96 ,
void * V_186 , T_7 V_187 ,
union V_37 * * V_188 ,
struct V_39 * T_4 )
{
union V_37 * T_2 ;
T_7 V_189 , V_190 ;
int V_176 ;
if ( V_2 -> V_191 && ! V_2 -> V_35 . V_192 ) {
T_2 = V_96 - V_2 -> V_193 +
V_2 -> V_194 ;
goto V_195;
}
if ( F_4 ( V_2 -> V_4 ) )
return - 1 ;
V_176 = F_93 ( V_2 -> V_4 ) ;
V_189 = sizeof( struct V_58 ) ;
if ( V_187 < V_189 )
return - 1 ;
if ( F_94 ( V_176 , V_96 , V_181 ) == ( T_12 ) - 1 ||
F_97 ( V_176 , & V_186 , V_189 ) != ( V_196 ) V_189 )
return - 1 ;
T_2 = (union V_37 * ) V_186 ;
if ( V_2 -> V_35 . V_192 )
F_98 ( & T_2 -> V_35 ) ;
if ( T_2 -> V_35 . V_56 < V_189 )
return - 1 ;
V_190 = T_2 -> V_35 . V_56 - V_189 ;
if ( F_97 ( V_176 , & V_186 , V_190 ) != ( V_196 ) V_190 )
return - 1 ;
if ( V_2 -> V_35 . V_192 )
F_95 ( T_2 , F_28 ( V_2 -> V_5 ) ) ;
V_195:
if ( T_4 && T_2 -> V_35 . type < V_197 &&
F_99 ( V_2 -> V_5 , T_2 , T_4 ) )
return - 1 ;
* V_188 = T_2 ;
return 0 ;
}
static T_10 F_100 ( struct V_1 * V_2 ,
union V_37 * T_2 ,
struct V_15 * V_16 ,
V_57 V_96 )
{
struct V_39 T_4 ;
int V_8 ;
if ( V_2 -> V_35 . V_192 )
F_95 ( T_2 , F_28 ( V_2 -> V_5 ) ) ;
if ( T_2 -> V_35 . type >= V_198 )
return - V_105 ;
F_101 ( & V_2 -> V_164 , T_2 -> V_35 . type ) ;
if ( T_2 -> V_35 . type >= V_197 )
return F_92 ( V_2 , T_2 , V_16 , V_96 ) ;
V_8 = F_99 ( V_2 -> V_5 , T_2 , & T_4 ) ;
if ( V_8 )
return V_8 ;
if ( V_16 -> V_18 ) {
V_8 = F_65 ( V_2 , T_2 , V_16 , & T_4 ,
V_96 ) ;
if ( V_8 != - V_101 )
return V_8 ;
}
return F_90 ( V_2 , T_2 , & T_4 , V_16 ,
V_96 ) ;
}
void F_98 ( struct V_58 * V_59 )
{
V_59 -> type = F_50 ( V_59 -> type ) ;
V_59 -> V_137 = F_102 ( V_59 -> V_137 ) ;
V_59 -> V_56 = F_102 ( V_59 -> V_56 ) ;
}
struct V_199 * F_103 ( struct V_1 * V_2 , T_13 V_60 )
{
return F_104 ( & V_2 -> V_7 . V_9 , - 1 , V_60 ) ;
}
static struct V_199 * F_105 ( struct V_1 * V_2 )
{
struct V_199 * V_199 ;
V_199 = F_104 ( & V_2 -> V_7 . V_9 , 0 , 0 ) ;
if ( V_199 == NULL || F_106 ( V_199 , L_42 , 0 ) ) {
F_3 ( L_43 ) ;
V_199 = NULL ;
}
return V_199 ;
}
static void F_107 ( const struct V_1 * V_2 ,
const struct V_15 * V_16 )
{
if ( V_16 -> V_45 == V_46 &&
V_2 -> V_164 . V_200 [ V_170 ] != 0 ) {
F_108 ( L_44
L_45 ,
V_2 -> V_164 . V_200 [ 0 ] ,
V_2 -> V_164 . V_200 [ V_170 ] ) ;
}
if ( V_2 -> V_164 . V_175 != 0 ) {
F_108 ( L_46
L_47
L_48
L_49
L_50 ,
V_2 -> V_164 . V_175 ) ;
}
if ( V_2 -> V_164 . V_165 != 0 ) {
F_108 ( L_51 ,
V_2 -> V_164 . V_165 ) ;
}
if ( V_2 -> V_164 . V_201 != 0 ) {
F_108 ( L_52
L_53
L_54 ,
V_2 -> V_164 . V_201 ,
V_2 -> V_164 . V_200 [ V_125 ] ) ;
}
if ( V_2 -> V_164 . V_166 != 0 ) {
F_108 ( L_55
L_56 ,
V_2 -> V_164 . V_166 ) ;
}
}
static int F_109 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
int V_176 = F_93 ( V_2 -> V_4 ) ;
union V_37 * T_2 ;
T_14 V_56 , V_202 = 0 ;
void * V_186 = NULL ;
T_10 V_203 = 0 ;
V_57 V_204 ;
V_196 V_177 ;
void * V_78 ;
F_44 ( V_16 ) ;
V_204 = 0 ;
V_202 = sizeof( union V_37 ) ;
V_186 = malloc ( V_202 ) ;
if ( ! V_186 )
return - V_205 ;
V_206:
T_2 = V_186 ;
V_177 = F_97 ( V_176 , T_2 , sizeof( struct V_58 ) ) ;
if ( V_177 <= 0 ) {
if ( V_177 == 0 )
goto V_207;
F_3 ( L_57 ) ;
goto V_208;
}
if ( V_2 -> V_35 . V_192 )
F_98 ( & T_2 -> V_35 ) ;
V_56 = T_2 -> V_35 . V_56 ;
if ( V_56 < sizeof( struct V_58 ) ) {
F_3 ( L_58 ) ;
goto V_208;
}
if ( V_56 > V_202 ) {
void * V_100 = realloc ( V_186 , V_56 ) ;
if ( ! V_100 ) {
F_3 ( L_59 ) ;
goto V_208;
}
V_186 = V_100 ;
V_202 = V_56 ;
T_2 = V_186 ;
}
V_78 = T_2 ;
V_78 += sizeof( struct V_58 ) ;
if ( V_56 - sizeof( struct V_58 ) ) {
V_177 = F_97 ( V_176 , V_78 , V_56 - sizeof( struct V_58 ) ) ;
if ( V_177 <= 0 ) {
if ( V_177 == 0 ) {
F_3 ( L_60 ) ;
goto V_207;
}
F_3 ( L_61 ) ;
goto V_208;
}
}
if ( ( V_203 = F_100 ( V_2 , T_2 , V_16 , V_204 ) ) < 0 ) {
F_3 ( L_34 V_110 L_62 ,
V_204 , T_2 -> V_35 . V_56 , T_2 -> V_35 . type ) ;
V_177 = - V_105 ;
goto V_208;
}
V_204 += V_56 ;
if ( V_203 > 0 )
V_204 += V_203 ;
if ( ! F_110 () )
goto V_206;
V_207:
V_177 = F_64 ( V_2 , V_16 , V_209 ) ;
V_208:
free ( V_186 ) ;
F_107 ( V_2 , V_16 ) ;
F_111 ( & V_2 -> V_18 ) ;
return V_177 ;
}
static union V_37 *
F_112 ( struct V_1 * V_2 ,
V_57 V_204 , T_7 V_210 , char * V_186 )
{
union V_37 * T_2 ;
if ( V_204 + sizeof( T_2 -> V_35 ) > V_210 )
return NULL ;
T_2 = (union V_37 * ) ( V_186 + V_204 ) ;
if ( V_2 -> V_35 . V_192 )
F_98 ( & T_2 -> V_35 ) ;
if ( V_204 + T_2 -> V_35 . V_56 > V_210 ) {
if ( V_2 -> V_35 . V_192 )
F_98 ( & T_2 -> V_35 ) ;
return NULL ;
}
return T_2 ;
}
int F_113 ( struct V_1 * V_2 ,
V_57 V_211 , V_57 V_212 ,
V_57 V_213 , struct V_15 * V_16 )
{
int V_176 = F_93 ( V_2 -> V_4 ) ;
V_57 V_204 , V_214 , V_96 , V_215 , V_56 ;
int V_177 , V_216 , V_217 , V_218 = 0 ;
T_7 V_210 ;
char * V_186 , * V_219 [ V_220 ] ;
union V_37 * T_2 ;
struct V_221 V_222 ;
T_10 V_203 ;
F_44 ( V_16 ) ;
V_214 = V_223 * ( V_211 / V_223 ) ;
V_96 = V_214 ;
V_204 = V_211 - V_214 ;
if ( V_212 && ( V_211 + V_212 < V_213 ) )
V_213 = V_211 + V_212 ;
F_114 ( & V_222 , V_213 , L_63 ) ;
V_210 = V_224 ;
if ( V_210 > V_213 ) {
V_210 = V_213 ;
V_2 -> V_191 = true ;
}
memset ( V_219 , 0 , sizeof( V_219 ) ) ;
V_216 = V_225 ;
V_217 = V_226 ;
if ( V_2 -> V_35 . V_192 ) {
V_216 |= V_227 ;
V_217 = V_228 ;
}
V_229:
V_186 = V_41 ( NULL , V_210 , V_216 , V_217 , V_176 ,
V_96 ) ;
if ( V_186 == V_230 ) {
F_3 ( L_64 ) ;
V_177 = - V_205 ;
goto V_208;
}
V_219 [ V_218 ] = V_186 ;
V_218 = ( V_218 + 1 ) & ( F_115 ( V_219 ) - 1 ) ;
V_215 = V_96 + V_204 ;
if ( V_2 -> V_191 ) {
V_2 -> V_194 = V_186 ;
V_2 -> V_193 = V_96 ;
}
V_206:
T_2 = F_112 ( V_2 , V_204 , V_210 , V_186 ) ;
if ( ! T_2 ) {
if ( V_219 [ V_218 ] ) {
F_116 ( V_219 [ V_218 ] , V_210 ) ;
V_219 [ V_218 ] = NULL ;
}
V_214 = V_223 * ( V_204 / V_223 ) ;
V_96 += V_214 ;
V_204 -= V_214 ;
goto V_229;
}
V_56 = T_2 -> V_35 . V_56 ;
if ( V_56 < sizeof( struct V_58 ) ||
( V_203 = F_100 ( V_2 , T_2 , V_16 , V_215 ) )
< 0 ) {
F_3 ( L_34 V_110 L_62 ,
V_96 + V_204 , T_2 -> V_35 . V_56 ,
T_2 -> V_35 . type ) ;
V_177 = - V_105 ;
goto V_208;
}
if ( V_203 )
V_56 += V_203 ;
V_204 += V_56 ;
V_215 += V_56 ;
F_117 ( & V_222 , V_56 ) ;
if ( F_110 () )
goto V_17;
if ( V_215 < V_213 )
goto V_206;
V_17:
V_177 = F_64 ( V_2 , V_16 , V_209 ) ;
V_208:
F_118 () ;
F_107 ( V_2 , V_16 ) ;
F_111 ( & V_2 -> V_18 ) ;
V_2 -> V_191 = false ;
return V_177 ;
}
int F_119 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
V_57 V_56 = F_120 ( V_2 -> V_4 ) ;
int V_177 ;
if ( F_105 ( V_2 ) == NULL )
return - V_106 ;
if ( ! F_4 ( V_2 -> V_4 ) )
V_177 = F_113 ( V_2 ,
V_2 -> V_35 . V_211 ,
V_2 -> V_35 . V_212 ,
V_56 , V_16 ) ;
else
V_177 = F_109 ( V_2 , V_16 ) ;
return V_177 ;
}
bool F_121 ( struct V_1 * V_2 , const char * V_231 )
{
struct V_10 * V_11 ;
F_17 (session->evlist, evsel) {
if ( V_11 -> V_12 . type == V_232 )
return true ;
}
F_3 ( L_65 , V_231 ) ;
return false ;
}
int F_122 ( struct V_233 * * V_234 ,
const char * V_235 , V_57 V_140 )
{
char * V_236 ;
enum V_237 V_79 ;
struct V_238 * V_239 ;
V_239 = F_21 ( sizeof( struct V_238 ) ) ;
if ( V_239 == NULL )
return - V_106 ;
V_239 -> V_240 = F_123 ( V_235 ) ;
if ( V_239 -> V_240 == NULL ) {
free ( V_239 ) ;
return - V_106 ;
}
V_236 = strchr ( V_239 -> V_240 , ']' ) ;
if ( V_236 )
* V_236 = '\0' ;
V_239 -> V_140 = V_140 ;
for ( V_79 = 0 ; V_79 < V_241 ; ++ V_79 ) {
struct V_242 * V_242 = F_124 ( V_234 [ V_79 ] ) ;
V_242 -> V_238 = V_239 ;
}
return 0 ;
}
T_7 F_125 ( struct V_1 * V_2 , T_15 * V_243 )
{
return F_126 ( & V_2 -> V_7 , V_243 ) ;
}
T_7 F_127 ( struct V_1 * V_2 , T_15 * V_243 ,
bool (V_203)( struct V_244 * V_244 , int V_245 ) , int V_245 )
{
return F_128 ( & V_2 -> V_7 , V_243 , V_203 , V_245 ) ;
}
T_7 F_129 ( struct V_1 * V_2 , T_15 * V_243 )
{
T_7 V_8 = fprintf ( V_243 , L_66 ) ;
V_8 += F_130 ( & V_2 -> V_164 , V_243 ) ;
return V_8 ;
}
T_7 F_131 ( struct V_1 * V_2 , T_15 * V_243 )
{
return F_132 ( & V_2 -> V_7 . V_9 , V_243 ) ;
}
struct V_10 * F_133 ( struct V_1 * V_2 ,
unsigned int type )
{
struct V_10 * V_246 ;
F_17 (session->evlist, pos) {
if ( V_246 -> V_12 . type == type )
return V_246 ;
}
return NULL ;
}
void F_134 ( struct V_10 * V_11 , struct V_39 * T_4 ,
struct V_247 * V_248 ,
unsigned int V_249 , unsigned int V_250 )
{
struct V_251 * V_252 ;
int V_253 = V_249 & V_254 ;
int V_255 = V_249 & V_256 ;
int V_257 = V_249 & V_258 ;
int V_259 = V_249 & V_260 ;
int V_261 = V_249 & V_262 ;
int V_263 = V_249 & V_264 ;
char V_95 = V_261 ? ' ' : '\t' ;
if ( V_265 . V_266 && T_4 -> V_108 ) {
struct V_247 V_267 ;
if ( F_135 ( V_248 -> V_40 , V_11 , V_248 -> V_199 ,
T_4 , NULL , NULL ,
V_268 ) != 0 ) {
if ( V_269 )
error ( L_67 ) ;
return;
}
F_136 ( & V_270 ) ;
if ( V_259 )
V_267 = * V_248 ;
while ( V_250 ) {
V_57 V_140 = 0 ;
V_252 = F_137 ( & V_270 ) ;
if ( ! V_252 )
break;
if ( V_252 -> V_271 && V_252 -> V_271 -> V_272 )
goto V_273;
if ( V_253 )
printf ( L_68 V_110 , V_95 , V_252 -> V_138 ) ;
if ( V_252 -> V_233 )
V_140 = V_252 -> V_233 -> V_274 ( V_252 -> V_233 , V_252 -> V_138 ) ;
if ( V_255 ) {
printf ( L_25 ) ;
if ( V_259 ) {
V_267 . V_140 = V_140 ;
V_267 . V_233 = V_252 -> V_233 ;
F_138 ( V_252 -> V_271 , & V_267 , stdout ) ;
} else
F_139 ( V_252 -> V_271 , stdout ) ;
}
if ( V_257 ) {
printf ( L_69 ) ;
F_140 ( V_252 -> V_233 , stdout ) ;
printf ( L_70 ) ;
}
if ( V_263 )
F_141 ( V_252 -> V_233 , V_140 , L_71 ,
stdout ) ;
if ( ! V_261 )
printf ( L_12 ) ;
V_250 -- ;
V_273:
F_142 ( & V_270 ) ;
}
} else {
if ( V_248 -> V_271 && V_248 -> V_271 -> V_272 )
return;
if ( V_253 )
printf ( L_72 V_110 , T_4 -> V_138 ) ;
if ( V_255 ) {
printf ( L_25 ) ;
if ( V_259 )
F_138 ( V_248 -> V_271 , V_248 ,
stdout ) ;
else
F_139 ( V_248 -> V_271 , stdout ) ;
}
if ( V_257 ) {
printf ( L_69 ) ;
F_140 ( V_248 -> V_233 , stdout ) ;
printf ( L_70 ) ;
}
if ( V_263 )
F_141 ( V_248 -> V_233 , V_248 -> V_140 , L_71 , stdout ) ;
}
}
int F_143 ( struct V_1 * V_2 ,
const char * V_275 , unsigned long * V_276 )
{
int V_79 , V_177 = - 1 ;
struct V_277 * V_233 ;
for ( V_79 = 0 ; V_79 < V_278 ; ++ V_79 ) {
struct V_10 * V_11 ;
V_11 = F_133 ( V_2 , V_79 ) ;
if ( ! V_11 )
continue;
if ( ! ( V_11 -> V_12 . V_83 & V_126 ) ) {
F_3 ( L_73
L_74 ) ;
return - 1 ;
}
}
V_233 = F_144 ( V_275 ) ;
if ( V_233 == NULL ) {
F_3 ( L_75 ) ;
return - 1 ;
}
for ( V_79 = 0 ; V_79 < V_233 -> V_109 ; V_79 ++ ) {
int V_127 = V_233 -> V_233 [ V_79 ] ;
if ( V_127 >= V_279 ) {
F_3 ( L_76
L_77 , V_127 ) ;
goto V_280;
}
F_145 ( V_127 , V_276 ) ;
}
V_177 = 0 ;
V_280:
F_146 ( V_233 ) ;
return V_177 ;
}
void F_147 ( struct V_1 * V_2 , T_15 * V_243 ,
bool V_281 )
{
struct V_282 V_283 ;
int V_176 , V_8 ;
if ( V_2 == NULL || V_243 == NULL )
return;
V_176 = F_93 ( V_2 -> V_4 ) ;
V_8 = F_148 ( V_176 , & V_283 ) ;
if ( V_8 == - 1 )
return;
fprintf ( V_243 , L_78 ) ;
fprintf ( V_243 , L_79 , ctime ( & V_283 . V_284 ) ) ;
F_149 ( V_2 , V_243 , V_281 ) ;
fprintf ( V_243 , L_80 ) ;
}
int F_150 ( struct V_1 * V_2 ,
const struct V_285 * V_286 ,
T_7 V_287 )
{
struct V_10 * V_11 ;
T_7 V_79 ;
int V_177 ;
for ( V_79 = 0 ; V_79 < V_287 ; V_79 ++ ) {
V_11 = F_151 ( V_2 -> V_5 , V_286 [ V_79 ] . V_240 ) ;
if ( V_11 == NULL )
continue;
V_177 = - V_288 ;
if ( V_11 -> V_289 != NULL )
goto V_17;
V_11 -> V_289 = V_286 [ V_79 ] . V_289 ;
}
V_177 = 0 ;
V_17:
return V_177 ;
}
