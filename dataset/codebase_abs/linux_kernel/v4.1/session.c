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
static int F_20 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
struct V_18 V_19 ;
struct V_1 * V_2 = F_21 ( V_15 , struct V_1 ,
V_14 ) ;
int V_8 = F_22 ( V_2 -> V_5 , V_17 -> V_17 , & V_19 ) ;
if ( V_8 ) {
F_3 ( L_5 , V_8 ) ;
return V_8 ;
}
return F_23 ( & V_2 -> V_7 , V_2 -> V_5 , V_17 -> V_17 ,
& V_19 , V_2 -> V_20 , V_17 -> V_21 ) ;
}
struct V_1 * F_24 ( struct V_3 * V_4 ,
bool V_22 , struct V_23 * V_20 )
{
struct V_1 * V_2 = F_25 ( sizeof( * V_2 ) ) ;
if ( ! V_2 )
goto V_24;
V_2 -> V_22 = V_22 ;
V_2 -> V_20 = V_20 ;
F_26 ( & V_2 -> V_7 ) ;
F_27 ( & V_2 -> V_14 , F_20 ) ;
if ( V_4 ) {
if ( F_28 ( V_4 ) )
goto V_25;
V_2 -> V_4 = V_4 ;
if ( F_29 ( V_4 ) ) {
if ( F_1 ( V_2 ) < 0 )
goto V_26;
F_8 ( V_2 ) ;
F_18 ( V_2 ) ;
}
}
if ( ! V_4 || F_30 ( V_4 ) ) {
if ( F_11 ( V_2 ) < 0 )
F_31 ( L_6 ) ;
}
if ( V_20 && V_20 -> V_27 &&
V_20 -> V_14 && ! F_32 ( V_2 -> V_5 ) ) {
F_33 ( L_7 ) ;
V_20 -> V_14 = false ;
}
return V_2 ;
V_26:
F_34 ( V_4 ) ;
V_25:
F_35 ( V_2 ) ;
V_24:
return NULL ;
}
static void F_36 ( struct V_1 * V_2 )
{
F_37 ( & V_2 -> V_7 . V_9 ) ;
}
static void F_38 ( struct V_28 * V_29 )
{
F_39 ( & V_29 -> V_30 ) ;
F_39 ( & V_29 -> V_31 ) ;
F_39 ( & V_29 -> V_32 ) ;
F_39 ( & V_29 -> V_33 ) ;
F_39 ( & V_29 -> V_34 ) ;
F_39 ( & V_29 -> V_35 ) ;
F_39 ( & V_29 -> V_36 ) ;
F_39 ( & V_29 -> V_37 ) ;
F_39 ( & V_29 -> V_38 ) ;
F_39 ( & V_29 -> V_39 ) ;
F_39 ( & V_29 -> V_40 ) ;
}
void F_35 ( struct V_1 * V_2 )
{
F_14 ( V_2 ) ;
F_36 ( V_2 ) ;
F_38 ( & V_2 -> V_41 . V_29 ) ;
F_40 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_4 )
F_34 ( V_2 -> V_4 ) ;
free ( V_2 ) ;
}
static int F_41 ( struct V_23 * V_20
V_42 ,
union V_43 * V_17
V_42 ,
struct V_1 * V_2
V_42 )
{
F_33 ( L_8 ) ;
return 0 ;
}
static int F_42 ( struct V_23 * V_20 V_42 ,
union V_43 * V_17 V_42 ,
struct V_44 * * T_2
V_42 )
{
F_33 ( L_8 ) ;
return 0 ;
}
static int F_43 ( struct V_23 * V_20 V_42 ,
union V_43 * V_17 V_42 ,
struct V_18 * V_19 V_42 ,
struct V_10 * V_11 V_42 ,
struct V_45 * V_45 V_42 )
{
F_33 ( L_8 ) ;
return 0 ;
}
static int F_44 ( struct V_23 * V_20 V_42 ,
union V_43 * V_17 V_42 ,
struct V_18 * V_19 V_42 ,
struct V_45 * V_45 V_42 )
{
F_33 ( L_8 ) ;
return 0 ;
}
static int F_45 ( struct V_23 * V_20 V_42 ,
union V_43 * V_17 V_42 ,
struct V_1 * V_2 V_42 )
{
F_33 ( L_8 ) ;
return 0 ;
}
static int F_46 ( struct V_23 * V_20 V_42 ,
union V_43 * V_17 V_42 ,
struct V_14 * V_15 V_42 )
{
F_33 ( L_8 ) ;
return 0 ;
}
static int F_47 ( struct V_23 * V_20 V_42 ,
union V_43 * V_17 V_42 ,
struct V_1 * V_1
V_42 )
{
F_33 ( L_8 ) ;
return 0 ;
}
void F_48 ( struct V_23 * V_20 )
{
if ( V_20 -> V_19 == NULL )
V_20 -> V_19 = F_43 ;
if ( V_20 -> V_46 == NULL )
V_20 -> V_46 = F_44 ;
if ( V_20 -> V_47 == NULL )
V_20 -> V_47 = F_44 ;
if ( V_20 -> V_48 == NULL )
V_20 -> V_48 = F_44 ;
if ( V_20 -> V_49 == NULL )
V_20 -> V_49 = F_44 ;
if ( V_20 -> exit == NULL )
V_20 -> exit = F_44 ;
if ( V_20 -> V_50 == NULL )
V_20 -> V_50 = V_51 ;
if ( V_20 -> V_52 == NULL )
V_20 -> V_52 = F_43 ;
if ( V_20 -> V_53 == NULL )
V_20 -> V_53 = F_44 ;
if ( V_20 -> V_54 == NULL )
V_20 -> V_54 = F_44 ;
if ( V_20 -> V_12 == NULL )
V_20 -> V_12 = F_42 ;
if ( V_20 -> V_55 == NULL )
V_20 -> V_55 = F_41 ;
if ( V_20 -> V_56 == NULL )
V_20 -> V_56 = F_45 ;
if ( V_20 -> V_57 == NULL ) {
if ( V_20 -> V_14 )
V_20 -> V_57 = V_58 ;
else
V_20 -> V_57 = F_46 ;
}
if ( V_20 -> V_59 == NULL )
V_20 -> V_59 = F_47 ;
}
static void F_49 ( union V_43 * V_17 , void * V_60 )
{
void * V_61 = ( void * ) V_17 + V_17 -> V_41 . V_62 ;
int V_62 = V_61 - V_60 ;
F_50 ( V_62 % sizeof( V_63 ) ) ;
F_51 ( V_60 , V_62 ) ;
}
static void F_52 ( union V_43 * V_17 ,
bool T_3 V_42 )
{
struct V_64 * V_65 = & V_17 -> V_41 ;
F_51 ( V_65 + 1 , V_17 -> V_41 . V_62 - sizeof( * V_65 ) ) ;
}
static void F_53 ( union V_43 * V_17 , bool T_3 )
{
V_17 -> V_48 . V_66 = F_54 ( V_17 -> V_48 . V_66 ) ;
V_17 -> V_48 . V_67 = F_54 ( V_17 -> V_48 . V_67 ) ;
if ( T_3 ) {
void * V_60 = & V_17 -> V_48 . V_48 ;
V_60 += F_55 ( strlen ( V_60 ) + 1 , sizeof( V_63 ) ) ;
F_49 ( V_17 , V_60 ) ;
}
}
static void F_56 ( union V_43 * V_17 ,
bool T_3 )
{
V_17 -> V_46 . V_66 = F_54 ( V_17 -> V_46 . V_66 ) ;
V_17 -> V_46 . V_67 = F_54 ( V_17 -> V_46 . V_67 ) ;
V_17 -> V_46 . V_68 = F_57 ( V_17 -> V_46 . V_68 ) ;
V_17 -> V_46 . V_69 = F_57 ( V_17 -> V_46 . V_69 ) ;
V_17 -> V_46 . V_70 = F_57 ( V_17 -> V_46 . V_70 ) ;
if ( T_3 ) {
void * V_60 = & V_17 -> V_46 . V_71 ;
V_60 += F_55 ( strlen ( V_60 ) + 1 , sizeof( V_63 ) ) ;
F_49 ( V_17 , V_60 ) ;
}
}
static void F_58 ( union V_43 * V_17 ,
bool T_3 )
{
V_17 -> V_47 . V_66 = F_54 ( V_17 -> V_47 . V_66 ) ;
V_17 -> V_47 . V_67 = F_54 ( V_17 -> V_47 . V_67 ) ;
V_17 -> V_47 . V_68 = F_57 ( V_17 -> V_47 . V_68 ) ;
V_17 -> V_47 . V_69 = F_57 ( V_17 -> V_47 . V_69 ) ;
V_17 -> V_47 . V_70 = F_57 ( V_17 -> V_47 . V_70 ) ;
V_17 -> V_47 . V_72 = F_54 ( V_17 -> V_47 . V_72 ) ;
V_17 -> V_47 . V_73 = F_54 ( V_17 -> V_47 . V_73 ) ;
V_17 -> V_47 . V_74 = F_57 ( V_17 -> V_47 . V_74 ) ;
if ( T_3 ) {
void * V_60 = & V_17 -> V_47 . V_71 ;
V_60 += F_55 ( strlen ( V_60 ) + 1 , sizeof( V_63 ) ) ;
F_49 ( V_17 , V_60 ) ;
}
}
static void F_59 ( union V_43 * V_17 , bool T_3 )
{
V_17 -> V_49 . V_66 = F_54 ( V_17 -> V_49 . V_66 ) ;
V_17 -> V_49 . V_67 = F_54 ( V_17 -> V_49 . V_67 ) ;
V_17 -> V_49 . V_75 = F_54 ( V_17 -> V_49 . V_75 ) ;
V_17 -> V_49 . V_76 = F_54 ( V_17 -> V_49 . V_76 ) ;
V_17 -> V_49 . time = F_57 ( V_17 -> V_49 . time ) ;
if ( T_3 )
F_49 ( V_17 , & V_17 -> V_49 + 1 ) ;
}
static void F_60 ( union V_43 * V_17 , bool T_3 )
{
V_17 -> V_52 . V_66 = F_54 ( V_17 -> V_52 . V_66 ) ;
V_17 -> V_52 . V_67 = F_54 ( V_17 -> V_52 . V_67 ) ;
V_17 -> V_52 . V_77 = F_57 ( V_17 -> V_52 . V_77 ) ;
V_17 -> V_52 . V_78 = F_57 ( V_17 -> V_52 . V_78 ) ;
V_17 -> V_52 . V_79 = F_57 ( V_17 -> V_52 . V_79 ) ;
V_17 -> V_52 . V_80 = F_57 ( V_17 -> V_52 . V_80 ) ;
if ( T_3 )
F_49 ( V_17 , & V_17 -> V_52 + 1 ) ;
}
static void F_61 ( union V_43 * V_17 ,
bool T_3 )
{
V_17 -> V_53 . time = F_57 ( V_17 -> V_53 . time ) ;
V_17 -> V_53 . V_80 = F_57 ( V_17 -> V_53 . V_80 ) ;
V_17 -> V_53 . V_81 = F_57 ( V_17 -> V_53 . V_81 ) ;
if ( T_3 )
F_49 ( V_17 , & V_17 -> V_53 + 1 ) ;
}
static T_4 F_62 ( T_4 V_82 )
{
int V_83 = ( V_82 >> 4 ) | ( ( V_82 & 0xf ) << 4 ) ;
V_83 = ( ( V_83 & 0xcc ) >> 2 ) | ( ( V_83 & 0x33 ) << 2 ) ;
V_83 = ( ( V_83 & 0xaa ) >> 1 ) | ( ( V_83 & 0x55 ) << 1 ) ;
return ( T_4 ) V_83 ;
}
static void F_63 ( T_4 * V_84 , unsigned V_69 )
{
unsigned V_85 ;
for ( V_85 = 0 ; V_85 < V_69 ; V_85 ++ ) {
* V_84 = F_62 ( * V_84 ) ;
V_84 ++ ;
}
}
void F_64 ( struct V_86 * V_12 )
{
V_12 -> type = F_54 ( V_12 -> type ) ;
V_12 -> V_62 = F_54 ( V_12 -> V_62 ) ;
V_12 -> V_87 = F_57 ( V_12 -> V_87 ) ;
V_12 -> V_88 = F_57 ( V_12 -> V_88 ) ;
V_12 -> V_89 = F_57 ( V_12 -> V_89 ) ;
V_12 -> V_90 = F_57 ( V_12 -> V_90 ) ;
V_12 -> V_91 = F_54 ( V_12 -> V_91 ) ;
V_12 -> V_92 = F_54 ( V_12 -> V_92 ) ;
V_12 -> V_93 = F_57 ( V_12 -> V_93 ) ;
V_12 -> V_94 = F_57 ( V_12 -> V_94 ) ;
V_12 -> V_95 = F_57 ( V_12 -> V_95 ) ;
V_12 -> V_96 = F_57 ( V_12 -> V_96 ) ;
V_12 -> V_97 = F_54 ( V_12 -> V_97 ) ;
F_63 ( ( T_4 * ) ( & V_12 -> V_90 + 1 ) , sizeof( V_63 ) ) ;
}
static void F_65 ( union V_43 * V_17 ,
bool T_3 V_42 )
{
T_5 V_62 ;
F_64 ( & V_17 -> V_12 . V_12 ) ;
V_62 = V_17 -> V_41 . V_62 ;
V_62 -= ( void * ) & V_17 -> V_12 . V_80 - ( void * ) V_17 ;
F_51 ( V_17 -> V_12 . V_80 , V_62 ) ;
}
static void F_66 ( union V_43 * V_17 ,
bool T_3 V_42 )
{
V_17 -> V_98 . V_98 . V_99 =
F_57 ( V_17 -> V_98 . V_98 . V_99 ) ;
}
static void F_67 ( union V_43 * V_17 ,
bool T_3 V_42 )
{
V_17 -> V_55 . V_62 = F_54 ( V_17 -> V_55 . V_62 ) ;
}
static int V_58 ( struct V_23 * V_20 V_42 ,
union V_43 * V_17 V_42 ,
struct V_14 * V_15 )
{
return F_68 ( V_15 , V_100 ) ;
}
int F_69 ( struct V_1 * V_101 , union V_43 * V_17 ,
struct V_18 * V_19 , V_63 V_21 )
{
return F_70 ( & V_101 -> V_14 , V_17 , V_19 , V_21 ) ;
}
static void F_71 ( struct V_18 * V_19 )
{
struct V_102 * V_103 = V_19 -> V_103 ;
struct V_104 * V_105 = V_19 -> V_104 ;
V_63 V_106 = V_103 -> V_107 ;
unsigned int V_85 ;
for ( V_85 = 0 ; V_85 < V_106 ; V_85 ++ ) {
if ( V_103 -> V_108 [ V_85 ] == V_109 )
break;
}
if ( ( V_85 != V_106 ) && V_105 -> V_107 ) {
V_63 V_110 ;
V_110 = V_85 + 1 + V_105 -> V_107 + 1 ;
V_106 = V_85 + 1 ;
printf ( L_9 V_111 L_10 , V_110 ) ;
for ( V_85 = 0 ; V_85 < V_106 ; V_85 ++ )
printf ( L_11 V_112 L_10 ,
V_85 , V_103 -> V_108 [ V_85 ] ) ;
printf ( L_11 V_112 L_10 ,
( int ) ( V_106 ) , V_105 -> V_113 [ 0 ] . V_114 ) ;
for ( V_85 = 0 ; V_85 < V_105 -> V_107 ; V_85 ++ )
printf ( L_11 V_112 L_10 ,
( int ) ( V_85 + V_106 + 1 ) , V_105 -> V_113 [ V_85 ] . V_115 ) ;
}
}
static void F_72 ( struct V_10 * V_11 ,
struct V_18 * V_19 )
{
unsigned int V_85 ;
struct V_102 * V_103 = V_19 -> V_103 ;
if ( F_73 ( V_11 ) )
F_71 ( V_19 ) ;
printf ( L_12 V_111 L_10 , V_103 -> V_107 ) ;
for ( V_85 = 0 ; V_85 < V_103 -> V_107 ; V_85 ++ )
printf ( L_11 V_112 L_10 ,
V_85 , V_103 -> V_108 [ V_85 ] ) ;
}
static void F_74 ( struct V_18 * V_19 )
{
T_6 V_85 ;
printf ( L_13 V_111 L_10 , V_19 -> V_104 -> V_107 ) ;
for ( V_85 = 0 ; V_85 < V_19 -> V_104 -> V_107 ; V_85 ++ )
printf ( L_14 V_111 L_15 V_112 L_16 V_112 L_10 ,
V_85 , V_19 -> V_104 -> V_113 [ V_85 ] . V_115 ,
V_19 -> V_104 -> V_113 [ V_85 ] . V_114 ) ;
}
static void F_75 ( V_63 V_116 , V_63 * V_117 )
{
unsigned V_118 , V_85 = 0 ;
F_76 (rid, (unsigned long *) &mask, sizeof(mask) * 8 ) {
V_63 V_119 = V_117 [ V_85 ++ ] ;
printf ( L_17 V_112 L_10 ,
F_77 ( V_118 ) , V_119 ) ;
}
}
static inline const char * F_78 ( struct V_120 * V_121 )
{
if ( V_121 -> V_122 > V_123 )
return L_18 ;
return V_124 [ V_121 -> V_122 ] ;
}
static void F_79 ( const char * type , struct V_120 * V_117 )
{
V_63 V_116 = V_117 -> V_116 ;
printf ( L_19 V_112 L_20 ,
type ,
V_116 ,
F_78 ( V_117 ) ) ;
F_75 ( V_116 , V_117 -> V_117 ) ;
}
static void F_80 ( struct V_18 * V_19 )
{
struct V_120 * V_125 = & V_19 -> V_125 ;
if ( V_125 -> V_117 )
F_79 ( L_21 , V_125 ) ;
}
static void F_81 ( struct V_18 * V_19 )
{
struct V_120 * V_126 = & V_19 -> V_126 ;
if ( V_126 -> V_117 )
F_79 ( L_22 , V_126 ) ;
}
static void F_82 ( struct V_127 * V_128 )
{
printf ( L_23 V_111 L_24 ,
V_128 -> V_62 , V_128 -> V_129 ) ;
}
static void F_83 ( struct V_44 * V_5 ,
union V_43 * V_17 ,
struct V_18 * V_19 )
{
V_63 V_89 = F_84 ( V_5 ) ;
if ( V_17 -> V_41 . type != V_130 &&
! F_32 ( V_5 ) ) {
fputs ( L_25 , stdout ) ;
return;
}
if ( ( V_89 & V_131 ) )
printf ( L_26 , V_19 -> V_132 ) ;
if ( V_89 & V_133 )
printf ( L_27 V_111 L_28 , V_19 -> time ) ;
}
static void F_85 ( struct V_18 * V_19 , V_63 V_90 )
{
printf ( L_29 ) ;
if ( V_90 & V_134 )
printf ( L_30 V_112 L_10 ,
V_19 -> V_52 . V_78 ) ;
if ( V_90 & V_135 )
printf ( L_31 V_112 L_10 ,
V_19 -> V_52 . V_79 ) ;
if ( V_90 & V_136 ) {
V_63 V_85 ;
printf ( L_32 V_111 L_10 , V_19 -> V_52 . V_137 . V_107 ) ;
for ( V_85 = 0 ; V_85 < V_19 -> V_52 . V_137 . V_107 ; V_85 ++ ) {
struct V_138 * V_77 ;
V_77 = & V_19 -> V_52 . V_137 . V_139 [ V_85 ] ;
printf ( L_33 V_112
L_34 V_112 L_10 ,
V_77 -> V_80 , V_77 -> V_77 ) ;
}
} else
printf ( L_33 V_112 L_34 V_112 L_10 ,
V_19 -> V_52 . V_140 . V_80 , V_19 -> V_52 . V_140 . V_77 ) ;
}
static void F_86 ( struct V_44 * V_5 , union V_43 * V_17 ,
V_63 V_21 , struct V_18 * V_19 )
{
if ( ! V_141 )
return;
printf ( L_35 V_112 L_36 ,
V_21 , V_17 -> V_41 . V_62 , V_17 -> V_41 . type ) ;
F_87 ( V_17 ) ;
if ( V_19 )
F_83 ( V_5 , V_17 , V_19 ) ;
printf ( L_37 V_112 L_38 , V_21 ,
V_17 -> V_41 . V_62 , F_88 ( V_17 -> V_41 . type ) ) ;
}
static void F_89 ( struct V_10 * V_11 , union V_43 * V_17 ,
struct V_18 * V_19 )
{
V_63 V_89 ;
if ( ! V_141 )
return;
printf ( L_39 V_112 L_40 V_111 L_41 V_112 L_10 ,
V_17 -> V_41 . V_142 , V_19 -> V_66 , V_19 -> V_67 , V_19 -> V_143 ,
V_19 -> V_144 , V_19 -> V_145 ) ;
V_89 = V_11 -> V_12 . V_89 ;
if ( V_89 & V_146 )
F_72 ( V_11 , V_19 ) ;
if ( ( V_89 & V_147 ) && ! F_73 ( V_11 ) )
F_74 ( V_19 ) ;
if ( V_89 & V_148 )
F_80 ( V_19 ) ;
if ( V_89 & V_149 )
F_81 ( V_19 ) ;
if ( V_89 & V_150 )
F_82 ( & V_19 -> V_151 ) ;
if ( V_89 & V_152 )
printf ( L_42 V_111 L_10 , V_19 -> V_153 ) ;
if ( V_89 & V_154 )
printf ( L_43 V_112 L_10 , V_19 -> V_155 ) ;
if ( V_89 & V_156 )
printf ( L_44 V_112 L_10 , V_19 -> V_157 ) ;
if ( V_89 & V_158 )
F_85 ( V_19 , V_11 -> V_12 . V_90 ) ;
}
static struct V_45 * F_90 ( struct V_7 * V_7 ,
union V_43 * V_17 ,
struct V_18 * V_19 )
{
const T_4 V_159 = V_17 -> V_41 . V_142 & V_160 ;
struct V_45 * V_45 ;
if ( V_161 &&
( ( V_159 == V_162 ) ||
( V_159 == V_163 ) ) ) {
T_7 V_66 ;
if ( V_17 -> V_41 . type == V_164
|| V_17 -> V_41 . type == V_165 )
V_66 = V_17 -> V_46 . V_66 ;
else
V_66 = V_19 -> V_66 ;
V_45 = F_91 ( V_7 , V_66 ) ;
if ( ! V_45 )
V_45 = F_91 ( V_7 , V_166 ) ;
return V_45 ;
}
return & V_7 -> V_9 ;
}
static int F_92 ( struct V_44 * V_5 ,
struct V_23 * V_20 ,
union V_43 * V_17 ,
struct V_18 * V_19 ,
struct V_138 * V_167 ,
struct V_45 * V_45 )
{
struct V_168 * V_169 = F_93 ( V_5 , V_167 -> V_80 ) ;
if ( V_169 ) {
V_19 -> V_80 = V_167 -> V_80 ;
V_19 -> V_144 = V_167 -> V_77 - V_169 -> V_144 ;
V_169 -> V_144 = V_167 -> V_77 ;
}
if ( ! V_169 || V_169 -> V_11 == NULL ) {
++ V_5 -> V_170 . V_171 ;
return 0 ;
}
return V_20 -> V_19 ( V_20 , V_17 , V_19 , V_169 -> V_11 , V_45 ) ;
}
static int F_94 ( struct V_44 * V_5 ,
struct V_23 * V_20 ,
union V_43 * V_17 ,
struct V_18 * V_19 ,
struct V_45 * V_45 )
{
int V_8 = - V_172 ;
V_63 V_85 ;
for ( V_85 = 0 ; V_85 < V_19 -> V_52 . V_137 . V_107 ; V_85 ++ ) {
V_8 = F_92 ( V_5 , V_20 , V_17 , V_19 ,
& V_19 -> V_52 . V_137 . V_139 [ V_85 ] ,
V_45 ) ;
if ( V_8 )
break;
}
return V_8 ;
}
static int
F_95 ( struct V_44 * V_5 ,
struct V_23 * V_20 ,
union V_43 * V_17 ,
struct V_18 * V_19 ,
struct V_10 * V_11 ,
struct V_45 * V_45 )
{
V_63 V_89 = V_11 -> V_12 . V_89 ;
V_63 V_90 = V_11 -> V_12 . V_90 ;
if ( ! ( V_89 & V_158 ) )
return V_20 -> V_19 ( V_20 , V_17 , V_19 , V_11 , V_45 ) ;
if ( V_90 & V_136 )
return F_94 ( V_5 , V_20 , V_17 , V_19 ,
V_45 ) ;
else
return F_92 ( V_5 , V_20 , V_17 , V_19 ,
& V_19 -> V_52 . V_140 , V_45 ) ;
}
static int F_23 ( struct V_7 * V_7 ,
struct V_44 * V_5 ,
union V_43 * V_17 ,
struct V_18 * V_19 ,
struct V_23 * V_20 , V_63 V_21 )
{
struct V_10 * V_11 ;
struct V_45 * V_45 ;
F_86 ( V_5 , V_17 , V_21 , V_19 ) ;
V_11 = F_96 ( V_5 , V_19 -> V_80 ) ;
V_45 = F_90 ( V_7 , V_17 , V_19 ) ;
switch ( V_17 -> V_41 . type ) {
case V_130 :
F_89 ( V_11 , V_17 , V_19 ) ;
if ( V_11 == NULL ) {
++ V_5 -> V_170 . V_171 ;
return 0 ;
}
if ( V_45 == NULL ) {
++ V_5 -> V_170 . V_173 ;
return 0 ;
}
return F_95 ( V_5 , V_20 , V_17 , V_19 , V_11 , V_45 ) ;
case V_164 :
return V_20 -> V_46 ( V_20 , V_17 , V_19 , V_45 ) ;
case V_165 :
return V_20 -> V_47 ( V_20 , V_17 , V_19 , V_45 ) ;
case V_174 :
return V_20 -> V_48 ( V_20 , V_17 , V_19 , V_45 ) ;
case V_175 :
return V_20 -> V_49 ( V_20 , V_17 , V_19 , V_45 ) ;
case V_176 :
return V_20 -> exit ( V_20 , V_17 , V_19 , V_45 ) ;
case V_177 :
if ( V_20 -> V_50 == V_51 )
V_5 -> V_170 . V_178 += V_17 -> V_50 . V_50 ;
return V_20 -> V_50 ( V_20 , V_17 , V_19 , V_45 ) ;
case V_179 :
return V_20 -> V_52 ( V_20 , V_17 , V_19 , V_11 , V_45 ) ;
case V_180 :
return V_20 -> V_53 ( V_20 , V_17 , V_19 , V_45 ) ;
case V_181 :
return V_20 -> V_54 ( V_20 , V_17 , V_19 , V_45 ) ;
default:
++ V_5 -> V_170 . V_182 ;
return - 1 ;
}
}
static T_8 F_97 ( struct V_1 * V_2 ,
union V_43 * V_17 ,
V_63 V_21 )
{
struct V_14 * V_15 = & V_2 -> V_14 ;
struct V_23 * V_20 = V_2 -> V_20 ;
int V_183 = F_98 ( V_2 -> V_4 ) ;
int V_184 ;
F_86 ( V_2 -> V_5 , V_17 , V_21 , NULL ) ;
switch ( V_17 -> V_41 . type ) {
case V_185 :
V_184 = V_20 -> V_12 ( V_20 , V_17 , & V_2 -> V_5 ) ;
if ( V_184 == 0 ) {
F_8 ( V_2 ) ;
F_18 ( V_2 ) ;
}
return V_184 ;
case V_186 :
return 0 ;
case V_187 :
F_99 ( V_183 , V_21 , V_188 ) ;
return V_20 -> V_55 ( V_20 , V_17 , V_2 ) ;
case V_189 :
return V_20 -> V_56 ( V_20 , V_17 , V_2 ) ;
case V_190 :
return V_20 -> V_57 ( V_20 , V_17 , V_15 ) ;
case V_191 :
return V_20 -> V_59 ( V_20 , V_17 , V_2 ) ;
default:
return - V_172 ;
}
}
int F_100 ( struct V_1 * V_2 ,
union V_43 * V_17 ,
struct V_18 * V_19 )
{
struct V_44 * V_5 = V_2 -> V_5 ;
struct V_23 * V_20 = V_2 -> V_20 ;
F_101 ( & V_5 -> V_170 , V_17 -> V_41 . type ) ;
if ( V_17 -> V_41 . type >= V_192 )
return F_97 ( V_2 , V_17 , 0 ) ;
return F_23 ( & V_2 -> V_7 , V_5 , V_17 , V_19 , V_20 , 0 ) ;
}
static void F_102 ( union V_43 * V_17 , bool T_3 )
{
T_9 V_193 ;
V_193 = V_194 [ V_17 -> V_41 . type ] ;
if ( V_193 )
V_193 ( V_17 , T_3 ) ;
}
int F_103 ( struct V_1 * V_2 , T_10 V_21 ,
void * V_195 , T_5 V_196 ,
union V_43 * * V_197 ,
struct V_18 * V_19 )
{
union V_43 * V_17 ;
T_5 V_198 , V_199 ;
int V_183 ;
if ( V_2 -> V_200 && ! V_2 -> V_41 . V_201 ) {
V_17 = V_21 - V_2 -> V_202 +
V_2 -> V_203 ;
goto V_204;
}
if ( F_4 ( V_2 -> V_4 ) )
return - 1 ;
V_183 = F_98 ( V_2 -> V_4 ) ;
V_198 = sizeof( struct V_64 ) ;
if ( V_196 < V_198 )
return - 1 ;
if ( F_99 ( V_183 , V_21 , V_188 ) == ( T_10 ) - 1 ||
F_104 ( V_183 , & V_195 , V_198 ) != ( V_205 ) V_198 )
return - 1 ;
V_17 = (union V_43 * ) V_195 ;
if ( V_2 -> V_41 . V_201 )
F_105 ( & V_17 -> V_41 ) ;
if ( V_17 -> V_41 . V_62 < V_198 )
return - 1 ;
V_199 = V_17 -> V_41 . V_62 - V_198 ;
if ( F_104 ( V_183 , & V_195 , V_199 ) != ( V_205 ) V_199 )
return - 1 ;
if ( V_2 -> V_41 . V_201 )
F_102 ( V_17 , F_32 ( V_2 -> V_5 ) ) ;
V_204:
if ( V_19 && V_17 -> V_41 . type < V_192 &&
F_22 ( V_2 -> V_5 , V_17 , V_19 ) )
return - 1 ;
* V_197 = V_17 ;
return 0 ;
}
static T_8 F_106 ( struct V_1 * V_2 ,
union V_43 * V_17 , V_63 V_21 )
{
struct V_44 * V_5 = V_2 -> V_5 ;
struct V_23 * V_20 = V_2 -> V_20 ;
struct V_18 V_19 ;
int V_8 ;
if ( V_2 -> V_41 . V_201 )
F_102 ( V_17 , F_32 ( V_5 ) ) ;
if ( V_17 -> V_41 . type >= V_206 )
return - V_172 ;
F_101 ( & V_5 -> V_170 , V_17 -> V_41 . type ) ;
if ( V_17 -> V_41 . type >= V_192 )
return F_97 ( V_2 , V_17 , V_21 ) ;
V_8 = F_22 ( V_5 , V_17 , & V_19 ) ;
if ( V_8 )
return V_8 ;
if ( V_20 -> V_14 ) {
V_8 = F_69 ( V_2 , V_17 , & V_19 , V_21 ) ;
if ( V_8 != - V_207 )
return V_8 ;
}
return F_23 ( & V_2 -> V_7 , V_5 , V_17 ,
& V_19 , V_20 , V_21 ) ;
}
void F_105 ( struct V_64 * V_65 )
{
V_65 -> type = F_54 ( V_65 -> type ) ;
V_65 -> V_142 = F_107 ( V_65 -> V_142 ) ;
V_65 -> V_62 = F_107 ( V_65 -> V_62 ) ;
}
struct V_208 * F_108 ( struct V_1 * V_2 , T_11 V_66 )
{
return F_109 ( & V_2 -> V_7 . V_9 , - 1 , V_66 ) ;
}
static struct V_208 * F_110 ( struct V_1 * V_2 )
{
struct V_208 * V_208 ;
V_208 = F_109 ( & V_2 -> V_7 . V_9 , 0 , 0 ) ;
if ( V_208 == NULL || F_111 ( V_208 , L_45 , 0 ) ) {
F_3 ( L_46 ) ;
V_208 = NULL ;
}
return V_208 ;
}
static void F_112 ( const struct V_1 * V_2 )
{
const struct V_209 * V_170 = & V_2 -> V_5 -> V_170 ;
const struct V_14 * V_15 = & V_2 -> V_14 ;
if ( V_2 -> V_20 -> V_50 == V_51 &&
V_170 -> V_210 [ V_177 ] != 0 ) {
F_113 ( L_47
L_48 ,
V_170 -> V_210 [ 0 ] ,
V_170 -> V_210 [ V_177 ] ) ;
}
if ( V_170 -> V_182 != 0 ) {
F_113 ( L_49
L_50
L_51
L_52
L_53 ,
V_170 -> V_182 ) ;
}
if ( V_170 -> V_171 != 0 ) {
F_113 ( L_54 ,
V_170 -> V_171 ) ;
}
if ( V_170 -> V_211 != 0 ) {
F_113 ( L_55
L_56
L_57 ,
V_170 -> V_211 ,
V_170 -> V_210 [ V_130 ] ) ;
}
if ( V_170 -> V_173 != 0 ) {
F_113 ( L_58
L_59 ,
V_170 -> V_173 ) ;
}
if ( V_15 -> V_212 != 0 )
F_113 ( L_60 , V_15 -> V_212 ) ;
}
static int F_114 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = & V_2 -> V_14 ;
struct V_23 * V_20 = V_2 -> V_20 ;
int V_183 = F_98 ( V_2 -> V_4 ) ;
union V_43 * V_17 ;
T_12 V_62 , V_213 = 0 ;
void * V_195 = NULL ;
T_8 V_214 = 0 ;
V_63 V_215 ;
V_205 V_184 ;
void * V_84 ;
F_48 ( V_20 ) ;
V_215 = 0 ;
V_213 = sizeof( union V_43 ) ;
V_195 = malloc ( V_213 ) ;
if ( ! V_195 )
return - V_216 ;
V_217:
V_17 = V_195 ;
V_184 = F_104 ( V_183 , V_17 , sizeof( struct V_64 ) ) ;
if ( V_184 <= 0 ) {
if ( V_184 == 0 )
goto V_218;
F_3 ( L_61 ) ;
goto V_219;
}
if ( V_2 -> V_41 . V_201 )
F_105 ( & V_17 -> V_41 ) ;
V_62 = V_17 -> V_41 . V_62 ;
if ( V_62 < sizeof( struct V_64 ) ) {
F_3 ( L_62 ) ;
goto V_219;
}
if ( V_62 > V_213 ) {
void * V_220 = realloc ( V_195 , V_62 ) ;
if ( ! V_220 ) {
F_3 ( L_63 ) ;
goto V_219;
}
V_195 = V_220 ;
V_213 = V_62 ;
V_17 = V_195 ;
}
V_84 = V_17 ;
V_84 += sizeof( struct V_64 ) ;
if ( V_62 - sizeof( struct V_64 ) ) {
V_184 = F_104 ( V_183 , V_84 , V_62 - sizeof( struct V_64 ) ) ;
if ( V_184 <= 0 ) {
if ( V_184 == 0 ) {
F_3 ( L_64 ) ;
goto V_218;
}
F_3 ( L_65 ) ;
goto V_219;
}
}
if ( ( V_214 = F_106 ( V_2 , V_17 , V_215 ) ) < 0 ) {
F_3 ( L_37 V_112 L_66 ,
V_215 , V_17 -> V_41 . V_62 , V_17 -> V_41 . type ) ;
V_184 = - V_172 ;
goto V_219;
}
V_215 += V_62 ;
if ( V_214 > 0 )
V_215 += V_214 ;
if ( ! F_115 () )
goto V_217;
V_218:
V_184 = F_68 ( V_15 , V_221 ) ;
V_219:
free ( V_195 ) ;
F_112 ( V_2 ) ;
F_116 ( & V_2 -> V_14 ) ;
return V_184 ;
}
static union V_43 *
F_117 ( struct V_1 * V_2 ,
V_63 V_215 , T_5 V_222 , char * V_195 )
{
union V_43 * V_17 ;
if ( V_215 + sizeof( V_17 -> V_41 ) > V_222 )
return NULL ;
V_17 = (union V_43 * ) ( V_195 + V_215 ) ;
if ( V_2 -> V_41 . V_201 )
F_105 ( & V_17 -> V_41 ) ;
if ( V_215 + V_17 -> V_41 . V_62 > V_222 ) {
if ( V_2 -> V_41 . V_201 )
F_105 ( & V_17 -> V_41 ) ;
return NULL ;
}
return V_17 ;
}
static int F_118 ( struct V_1 * V_2 ,
V_63 V_223 , V_63 V_224 ,
V_63 V_225 )
{
struct V_14 * V_15 = & V_2 -> V_14 ;
struct V_23 * V_20 = V_2 -> V_20 ;
int V_183 = F_98 ( V_2 -> V_4 ) ;
V_63 V_215 , V_226 , V_21 , V_227 , V_62 ;
int V_184 , V_228 , V_229 , V_230 = 0 ;
T_5 V_222 ;
char * V_195 , * V_231 [ V_232 ] ;
union V_43 * V_17 ;
struct V_233 V_234 ;
T_8 V_214 ;
F_48 ( V_20 ) ;
V_226 = V_235 * ( V_223 / V_235 ) ;
V_21 = V_226 ;
V_215 = V_223 - V_226 ;
if ( V_224 && ( V_223 + V_224 < V_225 ) )
V_225 = V_223 + V_224 ;
F_119 ( & V_234 , V_225 , L_67 ) ;
V_222 = V_236 ;
if ( V_222 > V_225 ) {
V_222 = V_225 ;
V_2 -> V_200 = true ;
}
memset ( V_231 , 0 , sizeof( V_231 ) ) ;
V_228 = V_237 ;
V_229 = V_238 ;
if ( V_2 -> V_41 . V_201 ) {
V_228 |= V_239 ;
V_229 = V_240 ;
}
V_241:
V_195 = V_46 ( NULL , V_222 , V_228 , V_229 , V_183 ,
V_21 ) ;
if ( V_195 == V_242 ) {
F_3 ( L_68 ) ;
V_184 = - V_216 ;
goto V_219;
}
V_231 [ V_230 ] = V_195 ;
V_230 = ( V_230 + 1 ) & ( F_120 ( V_231 ) - 1 ) ;
V_227 = V_21 + V_215 ;
if ( V_2 -> V_200 ) {
V_2 -> V_203 = V_195 ;
V_2 -> V_202 = V_21 ;
}
V_217:
V_17 = F_117 ( V_2 , V_215 , V_222 , V_195 ) ;
if ( ! V_17 ) {
if ( V_231 [ V_230 ] ) {
F_121 ( V_231 [ V_230 ] , V_222 ) ;
V_231 [ V_230 ] = NULL ;
}
V_226 = V_235 * ( V_215 / V_235 ) ;
V_21 += V_226 ;
V_215 -= V_226 ;
goto V_241;
}
V_62 = V_17 -> V_41 . V_62 ;
if ( V_62 < sizeof( struct V_64 ) ||
( V_214 = F_106 ( V_2 , V_17 , V_227 ) ) < 0 ) {
F_3 ( L_37 V_112 L_66 ,
V_21 + V_215 , V_17 -> V_41 . V_62 ,
V_17 -> V_41 . type ) ;
V_184 = - V_172 ;
goto V_219;
}
if ( V_214 )
V_62 += V_214 ;
V_215 += V_62 ;
V_227 += V_62 ;
F_122 ( & V_234 , V_62 ) ;
if ( F_115 () )
goto V_24;
if ( V_227 < V_225 )
goto V_217;
V_24:
V_184 = F_68 ( V_15 , V_221 ) ;
V_219:
F_123 () ;
F_112 ( V_2 ) ;
F_116 ( & V_2 -> V_14 ) ;
V_2 -> V_200 = false ;
return V_184 ;
}
int F_124 ( struct V_1 * V_2 )
{
V_63 V_62 = F_125 ( V_2 -> V_4 ) ;
int V_184 ;
if ( F_110 ( V_2 ) == NULL )
return - V_243 ;
if ( ! F_4 ( V_2 -> V_4 ) )
V_184 = F_118 ( V_2 ,
V_2 -> V_41 . V_223 ,
V_2 -> V_41 . V_224 , V_62 ) ;
else
V_184 = F_114 ( V_2 ) ;
return V_184 ;
}
bool F_126 ( struct V_1 * V_2 , const char * V_244 )
{
struct V_10 * V_11 ;
F_17 (session->evlist, evsel) {
if ( V_11 -> V_12 . type == V_245 )
return true ;
}
F_3 ( L_69 , V_244 ) ;
return false ;
}
int F_127 ( struct V_246 * * V_247 ,
const char * V_248 , V_63 V_145 )
{
char * V_249 ;
enum V_250 V_85 ;
struct V_251 * V_252 ;
V_252 = F_25 ( sizeof( struct V_251 ) ) ;
if ( V_252 == NULL )
return - V_243 ;
V_252 -> V_253 = F_128 ( V_248 ) ;
if ( V_252 -> V_253 == NULL ) {
free ( V_252 ) ;
return - V_243 ;
}
V_249 = strchr ( V_252 -> V_253 , ']' ) ;
if ( V_249 )
* V_249 = '\0' ;
V_252 -> V_145 = V_145 ;
for ( V_85 = 0 ; V_85 < V_254 ; ++ V_85 ) {
struct V_255 * V_255 = F_129 ( V_247 [ V_85 ] ) ;
if ( ! V_255 )
continue;
V_255 -> V_251 = V_252 ;
}
return 0 ;
}
T_5 F_130 ( struct V_1 * V_2 , T_13 * V_256 )
{
return F_131 ( & V_2 -> V_7 , V_256 ) ;
}
T_5 F_132 ( struct V_1 * V_2 , T_13 * V_256 ,
bool (V_214)( struct V_257 * V_257 , int V_258 ) , int V_258 )
{
return F_133 ( & V_2 -> V_7 , V_256 , V_214 , V_258 ) ;
}
T_5 F_134 ( struct V_1 * V_2 , T_13 * V_256 )
{
T_5 V_8 = fprintf ( V_256 , L_70 ) ;
V_8 += F_135 ( & V_2 -> V_5 -> V_170 , V_256 ) ;
return V_8 ;
}
T_5 F_136 ( struct V_1 * V_2 , T_13 * V_256 )
{
return F_137 ( & V_2 -> V_7 . V_9 , V_256 ) ;
}
struct V_10 * F_138 ( struct V_1 * V_2 ,
unsigned int type )
{
struct V_10 * V_259 ;
F_17 (session->evlist, pos) {
if ( V_259 -> V_12 . type == type )
return V_259 ;
}
return NULL ;
}
void F_139 ( struct V_10 * V_11 , struct V_18 * V_19 ,
struct V_260 * V_261 ,
unsigned int V_262 , unsigned int V_263 )
{
struct V_264 * V_265 ;
int V_266 = V_262 & V_267 ;
int V_268 = V_262 & V_269 ;
int V_270 = V_262 & V_271 ;
int V_272 = V_262 & V_273 ;
int V_274 = V_262 & V_275 ;
int V_276 = V_262 & V_277 ;
char V_101 = V_274 ? ' ' : '\t' ;
if ( V_278 . V_279 && V_19 -> V_103 ) {
struct V_260 V_280 ;
if ( F_140 ( V_261 -> V_208 , V_11 ,
V_19 , NULL , NULL ,
V_281 ) != 0 ) {
if ( V_282 )
error ( L_71 ) ;
return;
}
F_141 ( & V_283 ) ;
if ( V_272 )
V_280 = * V_261 ;
while ( V_263 ) {
V_63 V_145 = 0 ;
V_265 = F_142 ( & V_283 ) ;
if ( ! V_265 )
break;
if ( V_265 -> V_284 && V_265 -> V_284 -> V_285 )
goto V_286;
if ( V_266 )
printf ( L_72 V_112 , V_101 , V_265 -> V_143 ) ;
if ( V_265 -> V_246 )
V_145 = V_265 -> V_246 -> V_287 ( V_265 -> V_246 , V_265 -> V_143 ) ;
if ( V_268 ) {
printf ( L_28 ) ;
if ( V_272 ) {
V_280 . V_145 = V_145 ;
V_280 . V_246 = V_265 -> V_246 ;
F_143 ( V_265 -> V_284 , & V_280 , stdout ) ;
} else
F_144 ( V_265 -> V_284 , stdout ) ;
}
if ( V_270 ) {
printf ( L_73 ) ;
F_145 ( V_265 -> V_246 , stdout ) ;
printf ( L_74 ) ;
}
if ( V_276 )
F_146 ( V_265 -> V_246 , V_145 , L_75 ,
stdout ) ;
if ( ! V_274 )
printf ( L_10 ) ;
V_263 -- ;
V_286:
F_147 ( & V_283 ) ;
}
} else {
if ( V_261 -> V_284 && V_261 -> V_284 -> V_285 )
return;
if ( V_266 )
printf ( L_76 V_112 , V_19 -> V_143 ) ;
if ( V_268 ) {
printf ( L_28 ) ;
if ( V_272 )
F_143 ( V_261 -> V_284 , V_261 ,
stdout ) ;
else
F_144 ( V_261 -> V_284 , stdout ) ;
}
if ( V_270 ) {
printf ( L_73 ) ;
F_145 ( V_261 -> V_246 , stdout ) ;
printf ( L_74 ) ;
}
if ( V_276 )
F_146 ( V_261 -> V_246 , V_261 -> V_145 , L_75 , stdout ) ;
}
}
int F_148 ( struct V_1 * V_2 ,
const char * V_288 , unsigned long * V_289 )
{
int V_85 , V_184 = - 1 ;
struct V_290 * V_246 ;
for ( V_85 = 0 ; V_85 < V_291 ; ++ V_85 ) {
struct V_10 * V_11 ;
V_11 = F_138 ( V_2 , V_85 ) ;
if ( ! V_11 )
continue;
if ( ! ( V_11 -> V_12 . V_89 & V_131 ) ) {
F_3 ( L_77
L_78 ) ;
return - 1 ;
}
}
V_246 = F_149 ( V_288 ) ;
if ( V_246 == NULL ) {
F_3 ( L_79 ) ;
return - 1 ;
}
for ( V_85 = 0 ; V_85 < V_246 -> V_107 ; V_85 ++ ) {
int V_132 = V_246 -> V_246 [ V_85 ] ;
if ( V_132 >= V_292 ) {
F_3 ( L_80
L_81 , V_132 ) ;
goto V_293;
}
F_150 ( V_132 , V_289 ) ;
}
V_184 = 0 ;
V_293:
F_151 ( V_246 ) ;
return V_184 ;
}
void F_152 ( struct V_1 * V_2 , T_13 * V_256 ,
bool V_294 )
{
struct V_295 V_296 ;
int V_183 , V_8 ;
if ( V_2 == NULL || V_256 == NULL )
return;
V_183 = F_98 ( V_2 -> V_4 ) ;
V_8 = F_153 ( V_183 , & V_296 ) ;
if ( V_8 == - 1 )
return;
fprintf ( V_256 , L_82 ) ;
fprintf ( V_256 , L_83 , ctime ( & V_296 . V_297 ) ) ;
F_154 ( V_2 , V_256 , V_294 ) ;
fprintf ( V_256 , L_84 ) ;
}
int F_155 ( struct V_1 * V_2 ,
const struct V_298 * V_299 ,
T_5 V_300 )
{
struct V_10 * V_11 ;
T_5 V_85 ;
int V_184 ;
for ( V_85 = 0 ; V_85 < V_300 ; V_85 ++ ) {
V_11 = F_156 ( V_2 -> V_5 , V_299 [ V_85 ] . V_253 ) ;
if ( V_11 == NULL )
continue;
V_184 = - V_301 ;
if ( V_11 -> V_302 != NULL )
goto V_24;
V_11 -> V_302 = V_299 [ V_85 ] . V_302 ;
}
V_184 = 0 ;
V_24:
return V_184 ;
}
int F_157 ( struct V_23 * V_20 V_42 ,
union V_43 * V_17 ,
struct V_1 * V_2 )
{
struct V_44 * V_5 = V_2 -> V_5 ;
struct V_303 * V_304 = & V_17 -> V_59 ;
T_5 V_85 , V_107 , V_305 ;
V_305 = ( V_304 -> V_41 . V_62 - sizeof( struct V_303 ) ) /
sizeof( struct V_306 ) ;
V_107 = V_304 -> V_107 ;
if ( V_107 > V_305 )
return - V_172 ;
if ( V_141 )
fprintf ( stdout , L_85 , V_107 ) ;
for ( V_85 = 0 ; V_85 < V_107 ; V_85 ++ ) {
struct V_306 * V_307 = & V_304 -> V_113 [ V_85 ] ;
struct V_168 * V_169 ;
if ( V_141 ) {
fprintf ( stdout , L_86 V_111 , V_307 -> V_80 ) ;
fprintf ( stdout , L_87 V_111 , V_307 -> V_308 ) ;
fprintf ( stdout , L_88 V_309 , V_307 -> V_132 ) ;
fprintf ( stdout , L_89 V_309 L_10 , V_307 -> V_67 ) ;
}
V_169 = F_93 ( V_5 , V_307 -> V_80 ) ;
if ( ! V_169 )
return - V_310 ;
V_169 -> V_308 = V_307 -> V_308 ;
V_169 -> V_132 = V_307 -> V_132 ;
V_169 -> V_67 = V_307 -> V_67 ;
}
return 0 ;
}
int F_158 ( struct V_23 * V_20 ,
T_14 V_311 ,
struct V_44 * V_5 ,
struct V_45 * V_45 )
{
union V_43 * V_312 ;
struct V_10 * V_11 ;
T_5 V_107 = 0 , V_85 = 0 , V_313 , V_305 , V_314 ;
int V_184 ;
F_159 ( L_90 ) ;
V_305 = ( V_315 - sizeof( struct V_303 ) ) /
sizeof( struct V_306 ) ;
F_17 (evlist, evsel)
V_107 += V_11 -> V_316 ;
V_314 = V_107 > V_305 ? V_305 : V_107 ;
V_313 = sizeof( struct V_303 ) + V_314 * sizeof( struct V_306 ) ;
V_312 = F_25 ( V_313 ) ;
if ( ! V_312 )
return - V_243 ;
V_312 -> V_59 . V_41 . type = V_191 ;
V_312 -> V_59 . V_41 . V_62 = V_313 ;
V_312 -> V_59 . V_107 = V_314 ;
F_17 (evlist, evsel) {
T_7 V_317 ;
for ( V_317 = 0 ; V_317 < V_11 -> V_316 ; V_317 ++ ) {
struct V_306 * V_307 ;
struct V_168 * V_169 ;
if ( V_85 >= V_314 ) {
V_184 = V_311 ( V_20 , V_312 , NULL , V_45 ) ;
if ( V_184 )
goto V_219;
V_107 -= V_314 ;
V_85 = 0 ;
}
V_307 = & V_312 -> V_59 . V_113 [ V_85 ++ ] ;
V_307 -> V_80 = V_11 -> V_80 [ V_317 ] ;
V_169 = F_93 ( V_5 , V_307 -> V_80 ) ;
if ( ! V_169 ) {
free ( V_312 ) ;
return - V_310 ;
}
V_307 -> V_308 = V_169 -> V_308 ;
V_307 -> V_132 = V_169 -> V_132 ;
V_307 -> V_67 = V_169 -> V_67 ;
}
}
V_313 = sizeof( struct V_303 ) + V_107 * sizeof( struct V_306 ) ;
V_312 -> V_59 . V_41 . V_62 = V_313 ;
V_312 -> V_59 . V_107 = V_107 ;
V_184 = V_311 ( V_20 , V_312 , NULL , V_45 ) ;
V_219:
free ( V_312 ) ;
return V_184 ;
}
