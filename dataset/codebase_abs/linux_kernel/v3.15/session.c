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
F_32 ( & V_22 -> V_23 ) ;
F_32 ( & V_22 -> V_24 ) ;
F_32 ( & V_22 -> V_25 ) ;
F_32 ( & V_22 -> V_26 ) ;
F_32 ( & V_22 -> V_27 ) ;
F_32 ( & V_22 -> V_28 ) ;
F_32 ( & V_22 -> V_29 ) ;
F_32 ( & V_22 -> V_30 ) ;
F_32 ( & V_22 -> V_31 ) ;
F_32 ( & V_22 -> V_32 ) ;
F_32 ( & V_22 -> V_33 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
F_14 ( V_2 ) ;
F_27 ( V_2 ) ;
F_29 ( V_2 ) ;
F_31 ( & V_2 -> V_34 . V_22 ) ;
F_33 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_4 )
F_25 ( V_2 -> V_4 ) ;
free ( V_2 ) ;
F_34 () ;
}
static int F_35 ( struct V_11 * V_12
V_35 ,
union V_36 * T_2
V_35 ,
struct V_1 * V_2
V_35 )
{
F_24 ( L_6 ) ;
return 0 ;
}
static int F_36 ( struct V_11 * V_12 V_35 ,
union V_36 * T_2 V_35 ,
struct V_37 * * T_3
V_35 )
{
F_24 ( L_6 ) ;
return 0 ;
}
static int F_37 ( struct V_11 * V_12 V_35 ,
union V_36 * T_2 V_35 ,
struct V_38 * T_4 V_35 ,
struct V_39 * T_5 V_35 ,
struct V_40 * V_40 V_35 )
{
F_24 ( L_6 ) ;
return 0 ;
}
static int F_38 ( struct V_11 * V_12 V_35 ,
union V_36 * T_2 V_35 ,
struct V_38 * T_4 V_35 ,
struct V_40 * V_40 V_35 )
{
F_24 ( L_6 ) ;
return 0 ;
}
static int F_39 ( struct V_11 * V_12 V_35 ,
union V_36 * T_2 V_35 ,
struct V_1 * V_1
V_35 )
{
F_24 ( L_6 ) ;
return 0 ;
}
void F_40 ( struct V_11 * V_12 )
{
if ( V_12 -> T_4 == NULL )
V_12 -> T_4 = F_37 ;
if ( V_12 -> V_41 == NULL )
V_12 -> V_41 = F_38 ;
if ( V_12 -> V_42 == NULL )
V_12 -> V_42 = F_38 ;
if ( V_12 -> V_43 == NULL )
V_12 -> V_43 = F_38 ;
if ( V_12 -> V_44 == NULL )
V_12 -> V_44 = F_38 ;
if ( V_12 -> exit == NULL )
V_12 -> exit = F_38 ;
if ( V_12 -> V_45 == NULL )
V_12 -> V_45 = V_46 ;
if ( V_12 -> V_47 == NULL )
V_12 -> V_47 = F_37 ;
if ( V_12 -> V_48 == NULL )
V_12 -> V_48 = F_38 ;
if ( V_12 -> V_49 == NULL )
V_12 -> V_49 = F_38 ;
if ( V_12 -> V_50 == NULL )
V_12 -> V_50 = F_36 ;
if ( V_12 -> V_51 == NULL )
V_12 -> V_51 = F_35 ;
if ( V_12 -> V_52 == NULL )
V_12 -> V_52 = F_39 ;
if ( V_12 -> V_53 == NULL ) {
if ( V_12 -> V_14 )
V_12 -> V_53 = V_54 ;
else
V_12 -> V_53 = F_39 ;
}
}
static void F_41 ( union V_36 * T_2 , void * V_55 )
{
void * V_56 = ( void * ) T_2 + T_2 -> V_34 . V_57 ;
int V_57 = V_56 - V_55 ;
F_42 ( V_57 % sizeof( V_58 ) ) ;
F_43 ( V_55 , V_57 ) ;
}
static void F_44 ( union V_36 * T_2 ,
bool T_6 V_35 )
{
struct V_59 * V_60 = & T_2 -> V_34 ;
F_43 ( V_60 + 1 , T_2 -> V_34 . V_57 - sizeof( * V_60 ) ) ;
}
static void F_45 ( union V_36 * T_2 , bool T_6 )
{
T_2 -> V_43 . V_61 = F_46 ( T_2 -> V_43 . V_61 ) ;
T_2 -> V_43 . V_62 = F_46 ( T_2 -> V_43 . V_62 ) ;
if ( T_6 ) {
void * V_55 = & T_2 -> V_43 . V_43 ;
V_55 += F_47 ( strlen ( V_55 ) + 1 , sizeof( V_58 ) ) ;
F_41 ( T_2 , V_55 ) ;
}
}
static void F_48 ( union V_36 * T_2 ,
bool T_6 )
{
T_2 -> V_41 . V_61 = F_46 ( T_2 -> V_41 . V_61 ) ;
T_2 -> V_41 . V_62 = F_46 ( T_2 -> V_41 . V_62 ) ;
T_2 -> V_41 . V_63 = F_49 ( T_2 -> V_41 . V_63 ) ;
T_2 -> V_41 . V_64 = F_49 ( T_2 -> V_41 . V_64 ) ;
T_2 -> V_41 . V_65 = F_49 ( T_2 -> V_41 . V_65 ) ;
if ( T_6 ) {
void * V_55 = & T_2 -> V_41 . V_66 ;
V_55 += F_47 ( strlen ( V_55 ) + 1 , sizeof( V_58 ) ) ;
F_41 ( T_2 , V_55 ) ;
}
}
static void F_50 ( union V_36 * T_2 ,
bool T_6 )
{
T_2 -> V_42 . V_61 = F_46 ( T_2 -> V_42 . V_61 ) ;
T_2 -> V_42 . V_62 = F_46 ( T_2 -> V_42 . V_62 ) ;
T_2 -> V_42 . V_63 = F_49 ( T_2 -> V_42 . V_63 ) ;
T_2 -> V_42 . V_64 = F_49 ( T_2 -> V_42 . V_64 ) ;
T_2 -> V_42 . V_65 = F_49 ( T_2 -> V_42 . V_65 ) ;
T_2 -> V_42 . V_67 = F_46 ( T_2 -> V_42 . V_67 ) ;
T_2 -> V_42 . V_68 = F_46 ( T_2 -> V_42 . V_68 ) ;
T_2 -> V_42 . V_69 = F_49 ( T_2 -> V_42 . V_69 ) ;
if ( T_6 ) {
void * V_55 = & T_2 -> V_42 . V_66 ;
V_55 += F_47 ( strlen ( V_55 ) + 1 , sizeof( V_58 ) ) ;
F_41 ( T_2 , V_55 ) ;
}
}
static void F_51 ( union V_36 * T_2 , bool T_6 )
{
T_2 -> V_44 . V_61 = F_46 ( T_2 -> V_44 . V_61 ) ;
T_2 -> V_44 . V_62 = F_46 ( T_2 -> V_44 . V_62 ) ;
T_2 -> V_44 . V_70 = F_46 ( T_2 -> V_44 . V_70 ) ;
T_2 -> V_44 . V_71 = F_46 ( T_2 -> V_44 . V_71 ) ;
T_2 -> V_44 . time = F_49 ( T_2 -> V_44 . time ) ;
if ( T_6 )
F_41 ( T_2 , & T_2 -> V_44 + 1 ) ;
}
static void F_52 ( union V_36 * T_2 , bool T_6 )
{
T_2 -> V_47 . V_61 = F_46 ( T_2 -> V_47 . V_61 ) ;
T_2 -> V_47 . V_62 = F_46 ( T_2 -> V_47 . V_62 ) ;
T_2 -> V_47 . V_72 = F_49 ( T_2 -> V_47 . V_72 ) ;
T_2 -> V_47 . V_73 = F_49 ( T_2 -> V_47 . V_73 ) ;
T_2 -> V_47 . V_74 = F_49 ( T_2 -> V_47 . V_74 ) ;
T_2 -> V_47 . V_75 = F_49 ( T_2 -> V_47 . V_75 ) ;
if ( T_6 )
F_41 ( T_2 , & T_2 -> V_47 + 1 ) ;
}
static void F_53 ( union V_36 * T_2 ,
bool T_6 )
{
T_2 -> V_48 . time = F_49 ( T_2 -> V_48 . time ) ;
T_2 -> V_48 . V_75 = F_49 ( T_2 -> V_48 . V_75 ) ;
T_2 -> V_48 . V_76 = F_49 ( T_2 -> V_48 . V_76 ) ;
if ( T_6 )
F_41 ( T_2 , & T_2 -> V_48 + 1 ) ;
}
static T_7 F_54 ( T_7 V_77 )
{
int V_78 = ( V_77 >> 4 ) | ( ( V_77 & 0xf ) << 4 ) ;
V_78 = ( ( V_78 & 0xcc ) >> 2 ) | ( ( V_78 & 0x33 ) << 2 ) ;
V_78 = ( ( V_78 & 0xaa ) >> 1 ) | ( ( V_78 & 0x55 ) << 1 ) ;
return ( T_7 ) V_78 ;
}
static void F_55 ( T_7 * V_79 , unsigned V_64 )
{
unsigned V_80 ;
for ( V_80 = 0 ; V_80 < V_64 ; V_80 ++ ) {
* V_79 = F_54 ( * V_79 ) ;
V_79 ++ ;
}
}
void F_56 ( struct V_81 * V_50 )
{
V_50 -> type = F_46 ( V_50 -> type ) ;
V_50 -> V_57 = F_46 ( V_50 -> V_57 ) ;
V_50 -> V_82 = F_49 ( V_50 -> V_82 ) ;
V_50 -> V_83 = F_49 ( V_50 -> V_83 ) ;
V_50 -> V_84 = F_49 ( V_50 -> V_84 ) ;
V_50 -> V_85 = F_49 ( V_50 -> V_85 ) ;
V_50 -> V_86 = F_46 ( V_50 -> V_86 ) ;
V_50 -> V_87 = F_46 ( V_50 -> V_87 ) ;
V_50 -> V_88 = F_49 ( V_50 -> V_88 ) ;
V_50 -> V_89 = F_49 ( V_50 -> V_89 ) ;
V_50 -> V_90 = F_49 ( V_50 -> V_90 ) ;
V_50 -> V_91 = F_49 ( V_50 -> V_91 ) ;
V_50 -> V_92 = F_46 ( V_50 -> V_92 ) ;
F_55 ( ( T_7 * ) ( & V_50 -> V_85 + 1 ) , sizeof( V_58 ) ) ;
}
static void F_57 ( union V_36 * T_2 ,
bool T_6 V_35 )
{
T_8 V_57 ;
F_56 ( & T_2 -> V_50 . V_50 ) ;
V_57 = T_2 -> V_34 . V_57 ;
V_57 -= ( void * ) & T_2 -> V_50 . V_75 - ( void * ) T_2 ;
F_43 ( T_2 -> V_50 . V_75 , V_57 ) ;
}
static void F_58 ( union V_36 * T_2 ,
bool T_6 V_35 )
{
T_2 -> V_93 . V_93 . V_94 =
F_49 ( T_2 -> V_93 . V_93 . V_94 ) ;
}
static void F_59 ( union V_36 * T_2 ,
bool T_6 V_35 )
{
T_2 -> V_51 . V_57 = F_46 ( T_2 -> V_51 . V_57 ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_14 * V_95 = & V_2 -> V_14 ;
while ( ! F_61 ( & V_95 -> V_17 ) ) {
struct V_96 * V_97 ;
V_97 = F_62 ( V_95 -> V_17 . V_98 , struct V_96 , V_99 ) ;
F_63 ( & V_97 -> V_99 ) ;
free ( V_97 ) ;
}
}
static int F_64 ( struct V_1 * V_100 ,
struct V_11 * V_12 )
{
struct V_14 * V_95 = & V_100 -> V_14 ;
struct V_101 * V_102 = & V_95 -> V_15 ;
struct V_96 * V_103 , * V_104 ;
struct V_38 T_4 ;
V_58 V_105 = V_95 -> V_106 ;
V_58 V_107 = V_95 -> V_108 ? V_95 -> V_108 -> V_109 : 0ULL ;
bool V_110 = V_105 == V_111 ;
struct V_112 V_113 ;
int V_8 ;
if ( ! V_12 -> V_14 || ! V_105 )
return 0 ;
if ( V_110 )
F_65 ( & V_113 , V_95 -> V_114 , L_7 ) ;
F_66 (iter, tmp, head, list) {
if ( F_67 () )
return 0 ;
if ( V_104 -> V_109 > V_105 )
break;
V_8 = F_68 ( V_100 -> V_5 , V_104 -> T_2 , & T_4 ) ;
if ( V_8 )
F_3 ( L_8 , V_8 ) ;
else {
V_8 = F_69 ( V_100 , V_104 -> T_2 , & T_4 , V_12 ,
V_104 -> V_115 ) ;
if ( V_8 )
return V_8 ;
}
V_95 -> V_116 = V_104 -> V_109 ;
F_63 ( & V_104 -> V_99 ) ;
F_70 ( & V_104 -> V_99 , & V_95 -> V_16 ) ;
if ( V_110 )
F_71 ( & V_113 , 1 ) ;
}
if ( F_61 ( V_102 ) ) {
V_95 -> V_108 = NULL ;
} else if ( V_107 <= V_105 ) {
V_95 -> V_108 =
F_62 ( V_102 -> V_117 , struct V_96 , V_99 ) ;
}
V_95 -> V_114 = 0 ;
return 0 ;
}
static int V_54 ( struct V_11 * V_12 ,
union V_36 * T_2 V_35 ,
struct V_1 * V_2 )
{
int V_8 = F_64 ( V_2 , V_12 ) ;
if ( ! V_8 )
V_2 -> V_14 . V_106 = V_2 -> V_14 . V_118 ;
return V_8 ;
}
static void F_72 ( struct V_96 * V_119 , struct V_1 * V_100 )
{
struct V_14 * V_95 = & V_100 -> V_14 ;
struct V_96 * T_4 = V_95 -> V_108 ;
V_58 V_109 = V_119 -> V_109 ;
struct V_101 * V_79 ;
++ V_95 -> V_114 ;
V_95 -> V_108 = V_119 ;
if ( ! T_4 ) {
F_70 ( & V_119 -> V_99 , & V_95 -> V_15 ) ;
V_95 -> V_118 = V_109 ;
return;
}
if ( T_4 -> V_109 <= V_109 ) {
while ( T_4 -> V_109 <= V_109 ) {
V_79 = T_4 -> V_99 . V_98 ;
if ( V_79 == & V_95 -> V_15 ) {
F_73 ( & V_119 -> V_99 , & V_95 -> V_15 ) ;
V_95 -> V_118 = V_109 ;
return;
}
T_4 = F_62 ( V_79 , struct V_96 , V_99 ) ;
}
F_73 ( & V_119 -> V_99 , & T_4 -> V_99 ) ;
} else {
while ( T_4 -> V_109 > V_109 ) {
V_79 = T_4 -> V_99 . V_117 ;
if ( V_79 == & V_95 -> V_15 ) {
F_70 ( & V_119 -> V_99 , & V_95 -> V_15 ) ;
return;
}
T_4 = F_62 ( V_79 , struct V_96 , V_99 ) ;
}
F_70 ( & V_119 -> V_99 , & T_4 -> V_99 ) ;
}
}
int F_74 ( struct V_1 * V_100 , union V_36 * T_2 ,
struct V_38 * T_4 , V_58 V_115 )
{
struct V_14 * V_95 = & V_100 -> V_14 ;
struct V_101 * V_120 = & V_95 -> V_16 ;
V_58 V_109 = T_4 -> time ;
struct V_96 * V_119 ;
if ( ! V_109 || V_109 == ~ 0ULL )
return - V_121 ;
if ( V_109 < V_100 -> V_14 . V_116 ) {
printf ( L_9 ) ;
return - V_122 ;
}
if ( ! F_61 ( V_120 ) ) {
V_119 = F_62 ( V_120 -> V_98 , struct V_96 , V_99 ) ;
F_63 ( & V_119 -> V_99 ) ;
} else if ( V_95 -> V_123 ) {
V_119 = V_95 -> V_123 + V_95 -> V_124 ;
if ( ++ V_95 -> V_124 == V_125 )
V_95 -> V_123 = NULL ;
} else {
V_95 -> V_123 = malloc ( V_125 * sizeof( * V_119 ) ) ;
if ( ! V_95 -> V_123 )
return - V_126 ;
F_70 ( & V_95 -> V_123 -> V_99 , & V_95 -> V_17 ) ;
V_95 -> V_124 = 2 ;
V_119 = V_95 -> V_123 + 1 ;
}
V_119 -> V_109 = V_109 ;
V_119 -> V_115 = V_115 ;
V_119 -> T_2 = T_2 ;
F_72 ( V_119 , V_100 ) ;
return 0 ;
}
static void F_75 ( struct V_38 * T_4 )
{
unsigned int V_80 ;
printf ( L_10 V_127 L_11 , T_4 -> V_128 -> V_129 ) ;
for ( V_80 = 0 ; V_80 < T_4 -> V_128 -> V_129 ; V_80 ++ )
printf ( L_12 V_130 L_11 ,
V_80 , T_4 -> V_128 -> V_131 [ V_80 ] ) ;
}
static void F_76 ( struct V_38 * T_4 )
{
T_9 V_80 ;
printf ( L_13 V_127 L_11 , T_4 -> V_132 -> V_129 ) ;
for ( V_80 = 0 ; V_80 < T_4 -> V_132 -> V_129 ; V_80 ++ )
printf ( L_14 V_127 L_15 V_130 L_16 V_130 L_11 ,
V_80 , T_4 -> V_132 -> V_133 [ V_80 ] . V_134 ,
T_4 -> V_132 -> V_133 [ V_80 ] . V_135 ) ;
}
static void F_77 ( V_58 V_136 , V_58 * V_137 )
{
unsigned V_138 , V_80 = 0 ;
F_78 (rid, (unsigned long *) &mask, sizeof(mask) * 8 ) {
V_58 V_139 = V_137 [ V_80 ++ ] ;
printf ( L_17 V_130 L_11 ,
F_79 ( V_138 ) , V_139 ) ;
}
}
static void F_80 ( struct V_38 * T_4 )
{
struct V_140 * V_141 = & T_4 -> V_141 ;
if ( V_141 -> V_137 ) {
V_58 V_136 = V_141 -> V_136 ;
printf ( L_18 V_130 L_11 , V_136 ) ;
F_77 ( V_136 , V_141 -> V_137 ) ;
}
}
static void F_81 ( struct V_142 * V_143 )
{
printf ( L_19 V_127 L_20 ,
V_143 -> V_57 , V_143 -> V_144 ) ;
}
static void F_82 ( struct V_1 * V_2 ,
union V_36 * T_2 ,
struct V_38 * T_4 )
{
V_58 V_84 = F_83 ( V_2 -> V_5 ) ;
if ( T_2 -> V_34 . type != V_145 &&
! F_23 ( V_2 -> V_5 ) ) {
fputs ( L_21 , stdout ) ;
return;
}
if ( ( V_84 & V_146 ) )
printf ( L_22 , T_4 -> V_147 ) ;
if ( V_84 & V_148 )
printf ( L_23 V_127 L_24 , T_4 -> time ) ;
}
static void F_84 ( struct V_38 * T_4 , V_58 V_85 )
{
printf ( L_25 ) ;
if ( V_85 & V_149 )
printf ( L_26 V_130 L_11 ,
T_4 -> V_47 . V_73 ) ;
if ( V_85 & V_150 )
printf ( L_27 V_130 L_11 ,
T_4 -> V_47 . V_74 ) ;
if ( V_85 & V_151 ) {
V_58 V_80 ;
printf ( L_28 V_127 L_11 , T_4 -> V_47 . V_152 . V_129 ) ;
for ( V_80 = 0 ; V_80 < T_4 -> V_47 . V_152 . V_129 ; V_80 ++ ) {
struct V_153 * V_72 ;
V_72 = & T_4 -> V_47 . V_152 . V_154 [ V_80 ] ;
printf ( L_29 V_130
L_30 V_130 L_11 ,
V_72 -> V_75 , V_72 -> V_72 ) ;
}
} else
printf ( L_29 V_130 L_30 V_130 L_11 ,
T_4 -> V_47 . V_155 . V_75 , T_4 -> V_47 . V_155 . V_72 ) ;
}
static void F_85 ( struct V_1 * V_2 , union V_36 * T_2 ,
V_58 V_115 , struct V_38 * T_4 )
{
if ( ! V_156 )
return;
printf ( L_31 V_130 L_32 ,
V_115 , T_2 -> V_34 . V_57 , T_2 -> V_34 . type ) ;
F_86 ( T_2 ) ;
if ( T_4 )
F_82 ( V_2 , T_2 , T_4 ) ;
printf ( L_33 V_130 L_34 , V_115 ,
T_2 -> V_34 . V_57 , F_87 ( T_2 -> V_34 . type ) ) ;
}
static void F_88 ( struct V_39 * T_5 , union V_36 * T_2 ,
struct V_38 * T_4 )
{
V_58 V_84 ;
if ( ! V_156 )
return;
printf ( L_35 V_130 L_36 V_127 L_37 V_130 L_11 ,
T_2 -> V_34 . V_157 , T_4 -> V_61 , T_4 -> V_62 , T_4 -> V_158 ,
T_4 -> V_159 , T_4 -> V_160 ) ;
V_84 = T_5 -> V_50 . V_84 ;
if ( V_84 & V_161 )
F_75 ( T_4 ) ;
if ( V_84 & V_162 )
F_76 ( T_4 ) ;
if ( V_84 & V_163 )
F_80 ( T_4 ) ;
if ( V_84 & V_164 )
F_81 ( & T_4 -> V_165 ) ;
if ( V_84 & V_166 )
printf ( L_38 V_127 L_11 , T_4 -> V_167 ) ;
if ( V_84 & V_168 )
printf ( L_39 V_130 L_11 , T_4 -> V_169 ) ;
if ( V_84 & V_170 )
printf ( L_40 V_130 L_11 , T_4 -> V_171 ) ;
if ( V_84 & V_172 )
F_84 ( T_4 , T_5 -> V_50 . V_85 ) ;
}
static struct V_40 *
F_89 ( struct V_1 * V_2 ,
union V_36 * T_2 ,
struct V_38 * T_4 )
{
const T_7 V_173 = T_2 -> V_34 . V_157 & V_174 ;
struct V_40 * V_40 ;
if ( V_175 &&
( ( V_173 == V_176 ) ||
( V_173 == V_177 ) ) ) {
T_10 V_61 ;
if ( T_2 -> V_34 . type == V_178
|| T_2 -> V_34 . type == V_179 )
V_61 = T_2 -> V_41 . V_61 ;
else
V_61 = T_4 -> V_61 ;
V_40 = F_90 ( V_2 , V_61 ) ;
if ( ! V_40 )
V_40 = F_91 ( V_2 ,
V_180 ) ;
return V_40 ;
}
return & V_2 -> V_7 . V_9 ;
}
static int F_92 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
union V_36 * T_2 ,
struct V_38 * T_4 ,
struct V_153 * V_181 ,
struct V_40 * V_40 )
{
struct V_182 * V_183 ;
V_183 = F_93 ( V_2 -> V_5 , V_181 -> V_75 ) ;
if ( V_183 ) {
T_4 -> V_75 = V_181 -> V_75 ;
T_4 -> V_159 = V_181 -> V_72 - V_183 -> V_159 ;
V_183 -> V_159 = V_181 -> V_72 ;
}
if ( ! V_183 || V_183 -> T_5 == NULL ) {
++ V_2 -> V_184 . V_185 ;
return 0 ;
}
return V_12 -> T_4 ( V_12 , T_2 , T_4 , V_183 -> T_5 , V_40 ) ;
}
static int F_94 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
union V_36 * T_2 ,
struct V_38 * T_4 ,
struct V_40 * V_40 )
{
int V_8 = - V_122 ;
V_58 V_80 ;
for ( V_80 = 0 ; V_80 < T_4 -> V_47 . V_152 . V_129 ; V_80 ++ ) {
V_8 = F_92 ( V_2 , V_12 , T_2 , T_4 ,
& T_4 -> V_47 . V_152 . V_154 [ V_80 ] ,
V_40 ) ;
if ( V_8 )
break;
}
return V_8 ;
}
static int
F_95 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
union V_36 * T_2 ,
struct V_38 * T_4 ,
struct V_39 * T_5 ,
struct V_40 * V_40 )
{
V_58 V_84 = T_5 -> V_50 . V_84 ;
V_58 V_85 = T_5 -> V_50 . V_85 ;
if ( ! ( V_84 & V_172 ) )
return V_12 -> T_4 ( V_12 , T_2 , T_4 , T_5 , V_40 ) ;
if ( V_85 & V_151 )
return F_94 ( V_2 , V_12 , T_2 , T_4 ,
V_40 ) ;
else
return F_92 ( V_2 , V_12 , T_2 , T_4 ,
& T_4 -> V_47 . V_155 , V_40 ) ;
}
static int F_69 ( struct V_1 * V_2 ,
union V_36 * T_2 ,
struct V_38 * T_4 ,
struct V_11 * V_12 ,
V_58 V_115 )
{
struct V_39 * T_5 ;
struct V_40 * V_40 ;
F_85 ( V_2 , T_2 , V_115 , T_4 ) ;
T_5 = F_96 ( V_2 -> V_5 , T_4 -> V_75 ) ;
if ( T_5 != NULL && T_2 -> V_34 . type != V_145 ) {
F_97 ( & T_5 -> V_186 , T_2 -> V_34 . type ) ;
}
V_40 = F_89 ( V_2 , T_2 ,
T_4 ) ;
switch ( T_2 -> V_34 . type ) {
case V_145 :
F_88 ( T_5 , T_2 , T_4 ) ;
if ( T_5 == NULL ) {
++ V_2 -> V_184 . V_185 ;
return 0 ;
}
if ( V_40 == NULL ) {
++ V_2 -> V_184 . V_187 ;
return 0 ;
}
return F_95 ( V_2 , V_12 , T_2 ,
T_4 , T_5 , V_40 ) ;
case V_178 :
return V_12 -> V_41 ( V_12 , T_2 , T_4 , V_40 ) ;
case V_179 :
return V_12 -> V_42 ( V_12 , T_2 , T_4 , V_40 ) ;
case V_188 :
return V_12 -> V_43 ( V_12 , T_2 , T_4 , V_40 ) ;
case V_189 :
return V_12 -> V_44 ( V_12 , T_2 , T_4 , V_40 ) ;
case V_190 :
return V_12 -> exit ( V_12 , T_2 , T_4 , V_40 ) ;
case V_191 :
if ( V_12 -> V_45 == V_46 )
V_2 -> V_184 . V_192 += T_2 -> V_45 . V_45 ;
return V_12 -> V_45 ( V_12 , T_2 , T_4 , V_40 ) ;
case V_193 :
return V_12 -> V_47 ( V_12 , T_2 , T_4 , T_5 , V_40 ) ;
case V_194 :
return V_12 -> V_48 ( V_12 , T_2 , T_4 , V_40 ) ;
case V_195 :
return V_12 -> V_49 ( V_12 , T_2 , T_4 , V_40 ) ;
default:
++ V_2 -> V_184 . V_196 ;
return - 1 ;
}
}
static int F_98 ( struct V_1 * V_2 , union V_36 * T_2 ,
struct V_11 * V_12 , V_58 V_115 )
{
int V_197 = F_99 ( V_2 -> V_4 ) ;
int V_198 ;
F_85 ( V_2 , T_2 , V_115 , NULL ) ;
switch ( T_2 -> V_34 . type ) {
case V_199 :
V_198 = V_12 -> V_50 ( V_12 , T_2 , & V_2 -> V_5 ) ;
if ( V_198 == 0 )
F_8 ( V_2 ) ;
return V_198 ;
case V_200 :
return 0 ;
case V_201 :
F_100 ( V_197 , V_115 , V_202 ) ;
return V_12 -> V_51 ( V_12 , T_2 , V_2 ) ;
case V_203 :
return V_12 -> V_52 ( V_12 , T_2 , V_2 ) ;
case V_204 :
return V_12 -> V_53 ( V_12 , T_2 , V_2 ) ;
default:
return - V_122 ;
}
}
static void F_101 ( union V_36 * T_2 , bool T_6 )
{
T_11 V_205 ;
V_205 = V_206 [ T_2 -> V_34 . type ] ;
if ( V_205 )
V_205 ( T_2 , T_6 ) ;
}
static int F_102 ( struct V_1 * V_2 ,
union V_36 * T_2 ,
struct V_11 * V_12 ,
V_58 V_115 )
{
struct V_38 T_4 ;
int V_8 ;
if ( V_2 -> V_34 . V_207 )
F_101 ( T_2 , F_23 ( V_2 -> V_5 ) ) ;
if ( T_2 -> V_34 . type >= V_208 )
return - V_122 ;
F_103 ( & V_2 -> V_184 , T_2 -> V_34 . type ) ;
if ( T_2 -> V_34 . type >= V_209 )
return F_98 ( V_2 , T_2 , V_12 , V_115 ) ;
V_8 = F_68 ( V_2 -> V_5 , T_2 , & T_4 ) ;
if ( V_8 )
return V_8 ;
if ( V_12 -> V_14 ) {
V_8 = F_74 ( V_2 , T_2 , & T_4 ,
V_115 ) ;
if ( V_8 != - V_121 )
return V_8 ;
}
return F_69 ( V_2 , T_2 , & T_4 , V_12 ,
V_115 ) ;
}
void F_104 ( struct V_59 * V_60 )
{
V_60 -> type = F_46 ( V_60 -> type ) ;
V_60 -> V_157 = F_105 ( V_60 -> V_157 ) ;
V_60 -> V_57 = F_105 ( V_60 -> V_57 ) ;
}
struct V_210 * F_106 ( struct V_1 * V_2 , T_12 V_61 )
{
return F_107 ( & V_2 -> V_7 . V_9 , 0 , V_61 ) ;
}
static struct V_210 * F_108 ( struct V_1 * V_2 )
{
struct V_210 * V_210 = F_106 ( V_2 , 0 ) ;
if ( V_210 == NULL || F_109 ( V_210 , L_41 , 0 ) ) {
F_3 ( L_42 ) ;
V_210 = NULL ;
}
return V_210 ;
}
static void F_110 ( const struct V_1 * V_2 ,
const struct V_11 * V_12 )
{
if ( V_12 -> V_45 == V_46 &&
V_2 -> V_184 . V_211 [ V_191 ] != 0 ) {
F_111 ( L_43
L_44 ,
V_2 -> V_184 . V_211 [ 0 ] ,
V_2 -> V_184 . V_211 [ V_191 ] ) ;
}
if ( V_2 -> V_184 . V_196 != 0 ) {
F_111 ( L_45
L_46
L_47
L_48
L_49 ,
V_2 -> V_184 . V_196 ) ;
}
if ( V_2 -> V_184 . V_185 != 0 ) {
F_111 ( L_50 ,
V_2 -> V_184 . V_185 ) ;
}
if ( V_2 -> V_184 . V_212 != 0 ) {
F_111 ( L_51
L_52
L_53 ,
V_2 -> V_184 . V_212 ,
V_2 -> V_184 . V_211 [ V_145 ] ) ;
}
if ( V_2 -> V_184 . V_187 != 0 ) {
F_111 ( L_54
L_55 ,
V_2 -> V_184 . V_187 ) ;
}
}
static int F_112 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
int V_197 = F_99 ( V_2 -> V_4 ) ;
union V_36 * T_2 ;
T_13 V_57 , V_213 = 0 ;
void * V_214 = NULL ;
int V_215 = 0 ;
V_58 V_102 ;
T_14 V_198 ;
void * V_79 ;
F_40 ( V_12 ) ;
V_102 = 0 ;
V_213 = sizeof( union V_36 ) ;
V_214 = malloc ( V_213 ) ;
if ( ! V_214 )
return - V_216 ;
V_217:
T_2 = V_214 ;
V_198 = F_113 ( V_197 , T_2 , sizeof( struct V_59 ) ) ;
if ( V_198 <= 0 ) {
if ( V_198 == 0 )
goto V_218;
F_3 ( L_56 ) ;
goto V_219;
}
if ( V_2 -> V_34 . V_207 )
F_104 ( & T_2 -> V_34 ) ;
V_57 = T_2 -> V_34 . V_57 ;
if ( V_57 < sizeof( struct V_59 ) ) {
F_3 ( L_57 ) ;
goto V_219;
}
if ( V_57 > V_213 ) {
void * V_119 = realloc ( V_214 , V_57 ) ;
if ( ! V_119 ) {
F_3 ( L_58 ) ;
goto V_219;
}
V_214 = V_119 ;
V_213 = V_57 ;
T_2 = V_214 ;
}
V_79 = T_2 ;
V_79 += sizeof( struct V_59 ) ;
if ( V_57 - sizeof( struct V_59 ) ) {
V_198 = F_113 ( V_197 , V_79 , V_57 - sizeof( struct V_59 ) ) ;
if ( V_198 <= 0 ) {
if ( V_198 == 0 ) {
F_3 ( L_59 ) ;
goto V_218;
}
F_3 ( L_60 ) ;
goto V_219;
}
}
if ( ( V_215 = F_102 ( V_2 , T_2 , V_12 , V_102 ) ) < 0 ) {
F_3 ( L_33 V_130 L_61 ,
V_102 , T_2 -> V_34 . V_57 , T_2 -> V_34 . type ) ;
V_198 = - V_122 ;
goto V_219;
}
V_102 += V_57 ;
if ( V_215 > 0 )
V_102 += V_215 ;
if ( ! F_67 () )
goto V_217;
V_218:
V_2 -> V_14 . V_106 = V_111 ;
V_198 = F_64 ( V_2 , V_12 ) ;
V_219:
free ( V_214 ) ;
F_110 ( V_2 , V_12 ) ;
F_60 ( V_2 ) ;
return V_198 ;
}
static union V_36 *
F_114 ( struct V_1 * V_2 ,
V_58 V_102 , T_8 V_220 , char * V_214 )
{
union V_36 * T_2 ;
if ( V_102 + sizeof( T_2 -> V_34 ) > V_220 )
return NULL ;
T_2 = (union V_36 * ) ( V_214 + V_102 ) ;
if ( V_2 -> V_34 . V_207 )
F_104 ( & T_2 -> V_34 ) ;
if ( V_102 + T_2 -> V_34 . V_57 > V_220 ) {
if ( V_2 -> V_34 . V_207 )
F_104 ( & T_2 -> V_34 ) ;
return NULL ;
}
return T_2 ;
}
int F_115 ( struct V_1 * V_2 ,
V_58 V_221 , V_58 V_222 ,
V_58 V_223 , struct V_11 * V_12 )
{
int V_197 = F_99 ( V_2 -> V_4 ) ;
V_58 V_102 , V_224 , V_115 , V_225 ;
int V_198 , V_226 , V_227 , V_228 = 0 ;
T_8 V_220 ;
char * V_214 , * V_229 [ V_230 ] ;
union V_36 * T_2 ;
T_13 V_57 ;
struct V_112 V_113 ;
F_40 ( V_12 ) ;
V_224 = V_231 * ( V_221 / V_231 ) ;
V_115 = V_224 ;
V_102 = V_221 - V_224 ;
if ( V_222 && ( V_221 + V_222 < V_223 ) )
V_223 = V_221 + V_222 ;
F_65 ( & V_113 , V_223 , L_62 ) ;
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
V_214 = V_41 ( NULL , V_220 , V_226 , V_227 , V_197 ,
V_115 ) ;
if ( V_214 == V_238 ) {
F_3 ( L_63 ) ;
V_198 = - V_216 ;
goto V_219;
}
V_229 [ V_228 ] = V_214 ;
V_228 = ( V_228 + 1 ) & ( F_116 ( V_229 ) - 1 ) ;
V_225 = V_115 + V_102 ;
V_217:
T_2 = F_114 ( V_2 , V_102 , V_220 , V_214 ) ;
if ( ! T_2 ) {
if ( V_229 [ V_228 ] ) {
F_117 ( V_229 [ V_228 ] , V_220 ) ;
V_229 [ V_228 ] = NULL ;
}
V_224 = V_231 * ( V_102 / V_231 ) ;
V_115 += V_224 ;
V_102 -= V_224 ;
goto V_237;
}
V_57 = T_2 -> V_34 . V_57 ;
if ( V_57 < sizeof( struct V_59 ) ||
F_102 ( V_2 , T_2 , V_12 , V_225 ) < 0 ) {
F_3 ( L_33 V_130 L_61 ,
V_115 + V_102 , T_2 -> V_34 . V_57 ,
T_2 -> V_34 . type ) ;
V_198 = - V_122 ;
goto V_219;
}
V_102 += V_57 ;
V_225 += V_57 ;
F_71 ( & V_113 , V_57 ) ;
if ( F_67 () )
goto V_13;
if ( V_225 < V_223 )
goto V_217;
V_13:
V_2 -> V_14 . V_106 = V_111 ;
V_198 = F_64 ( V_2 , V_12 ) ;
V_219:
F_118 () ;
F_110 ( V_2 , V_12 ) ;
F_60 ( V_2 ) ;
return V_198 ;
}
int F_119 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
V_58 V_57 = F_120 ( V_2 -> V_4 ) ;
int V_198 ;
if ( F_108 ( V_2 ) == NULL )
return - V_126 ;
if ( ! F_4 ( V_2 -> V_4 ) )
V_198 = F_115 ( V_2 ,
V_2 -> V_34 . V_221 ,
V_2 -> V_34 . V_222 ,
V_57 , V_12 ) ;
else
V_198 = F_112 ( V_2 , V_12 ) ;
return V_198 ;
}
bool F_121 ( struct V_1 * V_2 , const char * V_239 )
{
struct V_39 * T_5 ;
F_122 (session->evlist, evsel) {
if ( T_5 -> V_50 . type == V_240 )
return true ;
}
F_3 ( L_64 , V_239 ) ;
return false ;
}
int F_123 ( struct V_241 * * V_242 ,
const char * V_243 , V_58 V_160 )
{
char * V_244 ;
enum V_245 V_80 ;
struct V_246 * V_247 ;
V_247 = F_17 ( sizeof( struct V_246 ) ) ;
if ( V_247 == NULL )
return - V_126 ;
V_247 -> V_248 = F_124 ( V_243 ) ;
if ( V_247 -> V_248 == NULL ) {
free ( V_247 ) ;
return - V_126 ;
}
V_244 = strchr ( V_247 -> V_248 , ']' ) ;
if ( V_244 )
* V_244 = '\0' ;
V_247 -> V_160 = V_160 ;
for ( V_80 = 0 ; V_80 < V_249 ; ++ V_80 ) {
struct V_250 * V_250 = F_125 ( V_242 [ V_80 ] ) ;
V_250 -> V_246 = V_247 ;
}
return 0 ;
}
T_8 F_126 ( struct V_1 * V_2 , T_15 * V_251 )
{
return F_127 ( & V_2 -> V_7 , V_251 ) ;
}
T_8 F_128 ( struct V_1 * V_2 , T_15 * V_251 ,
bool (V_215)( struct V_252 * V_252 , int V_253 ) , int V_253 )
{
return F_129 ( & V_2 -> V_7 , V_251 , V_215 , V_253 ) ;
}
T_8 F_130 ( struct V_1 * V_2 , T_15 * V_251 )
{
struct V_39 * V_254 ;
T_8 V_8 = fprintf ( V_251 , L_65 ) ;
V_8 += F_131 ( & V_2 -> V_184 , V_251 ) ;
F_122 (session->evlist, pos) {
V_8 += fprintf ( V_251 , L_66 , F_132 ( V_254 ) ) ;
V_8 += F_131 ( & V_254 -> V_186 . V_184 , V_251 ) ;
}
return V_8 ;
}
T_8 F_133 ( struct V_1 * V_2 , T_15 * V_251 )
{
return F_134 ( & V_2 -> V_7 . V_9 , V_251 ) ;
}
struct V_39 * F_135 ( struct V_1 * V_2 ,
unsigned int type )
{
struct V_39 * V_254 ;
F_122 (session->evlist, pos) {
if ( V_254 -> V_50 . type == type )
return V_254 ;
}
return NULL ;
}
void F_136 ( struct V_39 * T_5 , struct V_38 * T_4 ,
struct V_255 * V_256 ,
unsigned int V_257 , unsigned int V_258 )
{
struct V_259 * V_260 ;
int V_261 = V_257 & V_262 ;
int V_263 = V_257 & V_264 ;
int V_265 = V_257 & V_266 ;
int V_267 = V_257 & V_268 ;
int V_269 = V_257 & V_270 ;
int V_271 = V_257 & V_272 ;
char V_100 = V_269 ? ' ' : '\t' ;
if ( V_273 . V_274 && T_4 -> V_128 ) {
struct V_255 V_275 ;
if ( F_137 ( V_256 -> V_40 , T_5 , V_256 -> V_210 ,
T_4 , NULL , NULL ,
V_276 ) != 0 ) {
if ( V_277 )
error ( L_67 ) ;
return;
}
F_138 ( & V_278 ) ;
if ( V_267 )
V_275 = * V_256 ;
while ( V_258 ) {
V_58 V_160 = 0 ;
V_260 = F_139 ( & V_278 ) ;
if ( ! V_260 )
break;
if ( V_260 -> V_279 && V_260 -> V_279 -> V_280 )
goto V_98;
if ( V_261 )
printf ( L_68 V_130 , V_100 , V_260 -> V_158 ) ;
if ( V_260 -> V_241 )
V_160 = V_260 -> V_241 -> V_281 ( V_260 -> V_241 , V_260 -> V_158 ) ;
if ( V_263 ) {
printf ( L_24 ) ;
if ( V_267 ) {
V_275 . V_160 = V_160 ;
V_275 . V_241 = V_260 -> V_241 ;
F_140 ( V_260 -> V_279 , & V_275 , stdout ) ;
} else
F_141 ( V_260 -> V_279 , stdout ) ;
}
if ( V_265 ) {
printf ( L_69 ) ;
F_142 ( V_260 -> V_241 , stdout ) ;
printf ( L_70 ) ;
}
if ( V_271 )
F_143 ( V_260 -> V_241 , V_160 , L_71 ,
stdout ) ;
if ( ! V_269 )
printf ( L_11 ) ;
V_258 -- ;
V_98:
F_144 ( & V_278 ) ;
}
} else {
if ( V_256 -> V_279 && V_256 -> V_279 -> V_280 )
return;
if ( V_261 )
printf ( L_72 V_130 , T_4 -> V_158 ) ;
if ( V_263 ) {
printf ( L_24 ) ;
if ( V_267 )
F_140 ( V_256 -> V_279 , V_256 ,
stdout ) ;
else
F_141 ( V_256 -> V_279 , stdout ) ;
}
if ( V_265 ) {
printf ( L_69 ) ;
F_142 ( V_256 -> V_241 , stdout ) ;
printf ( L_70 ) ;
}
if ( V_271 )
F_143 ( V_256 -> V_241 , V_256 -> V_160 , L_71 , stdout ) ;
}
}
int F_145 ( struct V_1 * V_2 ,
const char * V_282 , unsigned long * V_283 )
{
int V_80 , V_198 = - 1 ;
struct V_284 * V_241 ;
for ( V_80 = 0 ; V_80 < V_285 ; ++ V_80 ) {
struct V_39 * T_5 ;
T_5 = F_135 ( V_2 , V_80 ) ;
if ( ! T_5 )
continue;
if ( ! ( T_5 -> V_50 . V_84 & V_146 ) ) {
F_3 ( L_73
L_74 ) ;
return - 1 ;
}
}
V_241 = F_146 ( V_282 ) ;
if ( V_241 == NULL ) {
F_3 ( L_75 ) ;
return - 1 ;
}
for ( V_80 = 0 ; V_80 < V_241 -> V_129 ; V_80 ++ ) {
int V_147 = V_241 -> V_241 [ V_80 ] ;
if ( V_147 >= V_286 ) {
F_3 ( L_76
L_77 , V_147 ) ;
goto V_287;
}
F_147 ( V_147 , V_283 ) ;
}
V_198 = 0 ;
V_287:
F_148 ( V_241 ) ;
return V_198 ;
}
void F_149 ( struct V_1 * V_2 , T_15 * V_251 ,
bool V_288 )
{
int V_197 = F_99 ( V_2 -> V_4 ) ;
struct V_289 V_290 ;
int V_8 ;
if ( V_2 == NULL || V_251 == NULL )
return;
V_8 = F_150 ( V_197 , & V_290 ) ;
if ( V_8 == - 1 )
return;
fprintf ( V_251 , L_78 ) ;
fprintf ( V_251 , L_79 , ctime ( & V_290 . V_291 ) ) ;
F_151 ( V_2 , V_251 , V_288 ) ;
fprintf ( V_251 , L_80 ) ;
}
int F_152 ( struct V_1 * V_2 ,
const struct V_292 * V_293 ,
T_8 V_294 )
{
struct V_39 * T_5 ;
T_8 V_80 ;
int V_198 ;
for ( V_80 = 0 ; V_80 < V_294 ; V_80 ++ ) {
T_5 = F_153 ( V_2 -> V_5 , V_293 [ V_80 ] . V_248 ) ;
if ( T_5 == NULL )
continue;
V_198 = - V_295 ;
if ( T_5 -> V_296 != NULL )
goto V_13;
T_5 -> V_296 = V_293 [ V_80 ] . V_296 ;
}
V_198 = 0 ;
V_13:
return V_198 ;
}
