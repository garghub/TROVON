static inline void F_1 ( struct V_1 * V_2 , struct V_1 * V_3 ,
struct V_1 * V_4 )
{
V_2 -> V_5 = V_3 -> V_5 - V_4 -> V_5 ;
if ( V_3 -> V_6 < V_4 -> V_6 ) {
V_2 -> V_6 = V_3 -> V_6 + 1000000000L - V_4 -> V_6 ;
V_2 -> V_5 -- ;
} else {
V_2 -> V_6 = V_3 -> V_6 - V_4 -> V_6 ;
}
}
static inline struct V_7 * F_2 ( struct V_8 * V_9 )
{
return ( V_9 -> V_10 && ! V_11 . V_12 ) ? V_9 -> V_10 : V_13 -> V_10 ;
}
static inline int F_3 ( struct V_8 * V_9 )
{
return F_2 ( V_9 ) -> V_14 ;
}
static void F_4 ( struct V_8 * V_9 )
{
memset ( V_9 -> V_15 , 0 , sizeof( struct V_16 ) ) ;
}
static int F_5 ( struct V_8 * V_9 )
{
V_9 -> V_15 = F_6 ( sizeof( struct V_16 ) ) ;
return V_9 -> V_15 == NULL ? - V_17 : 0 ;
}
static void F_7 ( struct V_8 * V_9 )
{
free ( V_9 -> V_15 ) ;
V_9 -> V_15 = NULL ;
}
static int F_8 ( struct V_8 * V_9 )
{
void * V_18 ;
T_1 V_19 ;
V_19 = sizeof( * V_9 -> V_20 ) +
( F_3 ( V_9 ) * sizeof( struct V_21 ) ) ;
V_18 = F_6 ( V_19 ) ;
if ( ! V_18 )
return - V_17 ;
V_9 -> V_22 = V_18 ;
return 0 ;
}
static void F_9 ( struct V_8 * V_9 )
{
free ( V_9 -> V_22 ) ;
V_9 -> V_22 = NULL ;
}
static void F_10 ( struct V_23 * V_24 )
{
struct V_8 * V_9 ;
F_11 (evsel, &evlist->entries, node) {
F_7 ( V_9 ) ;
F_12 ( V_9 ) ;
F_9 ( V_9 ) ;
}
}
static int F_13 ( struct V_23 * V_24 , bool V_25 )
{
struct V_8 * V_9 ;
F_11 (evsel, &evlist->entries, node) {
if ( F_5 ( V_9 ) < 0 ||
F_14 ( V_9 , F_3 ( V_9 ) ) < 0 ||
( V_25 && F_8 ( V_9 ) < 0 ) )
goto V_26;
}
return 0 ;
V_26:
F_10 ( V_24 ) ;
return - 1 ;
}
static void F_15 ( struct V_23 * V_24 )
{
struct V_8 * V_9 ;
F_11 (evsel, &evlist->entries, node) {
F_4 ( V_9 ) ;
F_16 ( V_9 , F_3 ( V_9 ) ) ;
}
memset ( V_27 , 0 , sizeof( V_27 ) ) ;
memset ( V_28 , 0 , sizeof( V_28 ) ) ;
memset ( V_29 , 0 , sizeof( V_29 ) ) ;
memset ( V_30 , 0 , sizeof( V_30 ) ) ;
memset ( V_31 , 0 , sizeof( V_31 ) ) ;
memset ( V_32 , 0 , sizeof( V_32 ) ) ;
memset ( V_33 , 0 , sizeof( V_33 ) ) ;
memset ( V_34 , 0 , sizeof( V_34 ) ) ;
memset ( V_35 , 0 , sizeof( V_35 ) ) ;
memset ( V_36 , 0 , sizeof( V_36 ) ) ;
memset ( V_37 , 0 , sizeof( V_37 ) ) ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
}
static int F_17 ( struct V_8 * V_9 )
{
struct V_39 * V_40 = & V_9 -> V_40 ;
if ( V_41 )
V_40 -> V_42 = V_43 |
V_44 ;
V_40 -> V_45 = ! V_46 ;
if ( F_18 ( & V_11 ) )
return F_19 ( V_9 , F_2 ( V_9 ) ) ;
if ( ! F_20 ( & V_11 ) &&
F_21 ( V_9 ) ) {
V_40 -> V_47 = 1 ;
if ( ! V_48 )
V_40 -> V_49 = 1 ;
}
return F_22 ( V_9 , V_13 -> V_50 ) ;
}
static inline int F_23 ( struct V_8 * V_9 )
{
if ( F_24 ( V_9 , V_51 , V_52 ) ||
F_24 ( V_9 , V_51 , V_53 ) )
return 1 ;
return 0 ;
}
static void F_25 ( struct V_8 * V_54 , T_2 * V_55 )
{
if ( F_24 ( V_54 , V_51 , V_53 ) )
F_26 ( & V_27 [ 0 ] , V_55 [ 0 ] ) ;
else if ( F_24 ( V_54 , V_56 , V_57 ) )
F_26 ( & V_28 [ 0 ] , V_55 [ 0 ] ) ;
else if ( F_24 ( V_54 , V_56 , V_58 ) )
F_26 ( & V_29 [ 0 ] , V_55 [ 0 ] ) ;
else if ( F_24 ( V_54 , V_56 , V_59 ) )
F_26 ( & V_30 [ 0 ] , V_55 [ 0 ] ) ;
else if ( F_24 ( V_54 , V_56 , V_60 ) )
F_26 ( & V_31 [ 0 ] , V_55 [ 0 ] ) ;
else if ( F_24 ( V_54 , V_56 , V_61 ) )
F_26 ( & V_32 [ 0 ] , V_55 [ 0 ] ) ;
else if ( F_24 ( V_54 , V_62 , V_63 ) )
F_26 ( & V_33 [ 0 ] , V_55 [ 0 ] ) ;
else if ( F_24 ( V_54 , V_62 , V_64 ) )
F_26 ( & V_34 [ 0 ] , V_55 [ 0 ] ) ;
else if ( F_24 ( V_54 , V_62 , V_65 ) )
F_26 ( & V_35 [ 0 ] , V_55 [ 0 ] ) ;
else if ( F_24 ( V_54 , V_62 , V_66 ) )
F_26 ( & V_37 [ 0 ] , V_55 [ 0 ] ) ;
else if ( F_24 ( V_54 , V_62 , V_67 ) )
F_26 ( & V_36 [ 0 ] , V_55 [ 0 ] ) ;
}
static int F_27 ( struct V_8 * V_54 )
{
struct V_16 * V_68 = V_54 -> V_15 ;
T_2 * V_55 = V_54 -> V_20 -> V_69 . V_70 ;
int V_71 ;
if ( F_28 ( V_54 , F_3 ( V_54 ) ,
F_29 ( V_13 -> V_50 ) , V_41 ) < 0 )
return - 1 ;
for ( V_71 = 0 ; V_71 < 3 ; V_71 ++ )
F_26 ( & V_68 -> V_72 [ V_71 ] , V_55 [ V_71 ] ) ;
if ( V_73 ) {
fprintf ( V_74 , L_1 V_75 L_2 V_75 L_2 V_75 L_3 ,
F_30 ( V_54 ) , V_55 [ 0 ] , V_55 [ 1 ] , V_55 [ 2 ] ) ;
}
F_25 ( V_54 , V_55 ) ;
return 0 ;
}
static int F_31 ( struct V_8 * V_54 )
{
T_2 * V_55 ;
int V_76 ;
for ( V_76 = 0 ; V_76 < F_3 ( V_54 ) ; V_76 ++ ) {
if ( F_32 ( V_54 , V_76 , 0 , V_41 ) < 0 )
return - 1 ;
V_55 = V_54 -> V_20 -> V_76 [ V_76 ] . V_70 ;
F_25 ( V_54 , V_55 ) ;
}
return 0 ;
}
static void F_33 ( void )
{
static int V_77 ;
struct V_8 * V_54 ;
struct V_16 * V_68 ;
struct V_1 V_78 , V_79 ;
char V_80 [ 64 ] ;
if ( V_81 == V_82 ) {
F_11 (counter, &evsel_list->entries, node) {
V_68 = V_54 -> V_15 ;
memset ( V_68 -> V_72 , 0 , sizeof( V_68 -> V_72 ) ) ;
F_27 ( V_54 ) ;
}
} else {
F_11 (counter, &evsel_list->entries, node) {
V_68 = V_54 -> V_15 ;
memset ( V_68 -> V_72 , 0 , sizeof( V_68 -> V_72 ) ) ;
F_31 ( V_54 ) ;
}
}
F_34 ( V_83 , & V_78 ) ;
F_1 ( & V_79 , & V_78 , & V_84 ) ;
sprintf ( V_80 , L_4 , V_79 . V_5 , V_79 . V_6 , V_85 ) ;
if ( V_77 == 0 && ! V_86 ) {
switch ( V_81 ) {
case V_87 :
fprintf ( V_74 , L_5 ) ;
break;
case V_88 :
fprintf ( V_74 , L_6 ) ;
break;
case V_89 :
fprintf ( V_74 , L_7 ) ;
break;
case V_82 :
default:
fprintf ( V_74 , L_8 ) ;
}
}
if ( ++ V_77 == 25 )
V_77 = 0 ;
switch ( V_81 ) {
case V_88 :
case V_87 :
F_35 ( V_80 ) ;
break;
case V_89 :
F_11 (counter, &evsel_list->entries, node)
F_36 ( V_54 , V_80 ) ;
break;
case V_82 :
default:
F_11 (counter, &evsel_list->entries, node)
F_37 ( V_54 , V_80 ) ;
}
fflush ( V_74 ) ;
}
static void F_38 ( void )
{
struct V_8 * V_54 ;
if ( V_48 ) {
const int V_90 = F_39 ( V_13 -> V_10 ) ,
V_91 = F_29 ( V_13 -> V_50 ) ;
F_40 ( V_48 * 1000 ) ;
F_11 (counter, &evsel_list->entries, node)
F_41 ( V_54 , V_90 , V_91 ) ;
}
}
static int F_42 ( int V_92 , const char * * V_93 )
{
char V_94 [ 512 ] ;
unsigned long long V_95 , V_96 ;
struct V_8 * V_54 ;
struct V_1 V_78 ;
int V_97 = 0 ;
const bool V_98 = ( V_92 > 0 ) ;
if ( V_99 ) {
V_78 . V_5 = V_99 / 1000 ;
V_78 . V_6 = ( V_99 % 1000 ) * 1000000 ;
} else {
V_78 . V_5 = 1 ;
V_78 . V_6 = 0 ;
}
if ( V_98 ) {
if ( F_43 ( V_13 , & V_11 , V_93 ,
false , false ) < 0 ) {
perror ( L_9 ) ;
return - 1 ;
}
V_100 = V_13 -> V_101 . V_102 ;
}
if ( V_103 )
F_44 ( V_13 ) ;
F_11 (counter, &evsel_list->entries, node) {
if ( F_17 ( V_54 ) < 0 ) {
if ( V_104 == V_105 || V_104 == V_106 ||
V_104 == V_107 || V_104 == V_108 ||
V_104 == V_109 ) {
if ( V_73 )
F_45 ( L_10 ,
F_30 ( V_54 ) ) ;
V_54 -> V_110 = false ;
continue;
}
F_46 ( V_54 , & V_11 ,
V_104 , V_94 , sizeof( V_94 ) ) ;
F_47 ( L_11 , V_94 ) ;
if ( V_100 != - 1 )
F_48 ( V_100 , V_111 ) ;
return - 1 ;
}
V_54 -> V_110 = true ;
}
if ( F_49 ( V_13 ) ) {
error ( L_12 , V_104 ,
strerror ( V_104 ) ) ;
return - 1 ;
}
V_95 = F_50 () ;
F_34 ( V_83 , & V_84 ) ;
if ( V_98 ) {
F_51 ( V_13 ) ;
F_38 () ;
if ( V_99 ) {
while ( ! F_52 ( V_100 , & V_97 , V_112 ) ) {
F_53 ( & V_78 , NULL ) ;
F_33 () ;
}
}
F_54 ( & V_97 ) ;
if ( F_55 ( V_97 ) )
F_56 ( F_57 ( V_97 ) , V_93 [ 0 ] ) ;
} else {
F_38 () ;
while ( ! V_113 ) {
F_53 ( & V_78 , NULL ) ;
if ( V_99 )
F_33 () ;
}
}
V_96 = F_50 () ;
F_26 ( & V_38 , V_96 - V_95 ) ;
if ( V_81 == V_82 ) {
F_11 (counter, &evsel_list->entries, node) {
F_27 ( V_54 ) ;
F_58 ( V_54 , F_3 ( V_54 ) ,
F_29 ( V_13 -> V_50 ) ) ;
}
} else {
F_11 (counter, &evsel_list->entries, node) {
F_31 ( V_54 ) ;
F_58 ( V_54 , F_3 ( V_54 ) , 1 ) ;
}
}
return F_59 ( V_97 ) ;
}
static int F_60 ( int V_92 V_114 , const char * * V_93 )
{
int V_115 ;
if ( V_116 ) {
V_115 = system ( V_116 ) ;
if ( V_115 )
return V_115 ;
}
if ( V_117 )
F_61 () ;
V_115 = F_42 ( V_92 , V_93 ) ;
if ( V_115 )
return V_115 ;
if ( V_118 ) {
V_115 = system ( V_118 ) ;
if ( V_115 )
return V_115 ;
}
return V_115 ;
}
static void F_62 ( double V_119 , double V_120 )
{
double V_121 = F_63 ( V_119 , V_120 ) ;
if ( V_86 )
fprintf ( V_74 , L_13 , V_85 , V_121 ) ;
else if ( V_121 )
fprintf ( V_74 , L_14 , V_121 ) ;
}
static void F_64 ( struct V_8 * V_9 , double V_120 )
{
struct V_16 * V_68 ;
if ( V_122 == 1 )
return;
V_68 = V_9 -> V_15 ;
F_62 ( F_65 ( & V_68 -> V_72 [ 0 ] ) , V_120 ) ;
}
static void F_66 ( struct V_8 * V_9 , int V_123 , int V_14 )
{
switch ( V_81 ) {
case V_88 :
fprintf ( V_74 , L_15 ,
F_67 ( V_123 ) ,
V_86 ? 0 : - 8 ,
F_68 ( V_123 ) ,
V_85 ,
V_86 ? 0 : 4 ,
V_14 ,
V_85 ) ;
break;
case V_87 :
fprintf ( V_74 , L_16 ,
V_86 ? 0 : - 5 ,
V_123 ,
V_85 ,
V_86 ? 0 : 4 ,
V_14 ,
V_85 ) ;
break;
case V_89 :
fprintf ( V_74 , L_17 ,
V_86 ? 0 : - 4 ,
F_2 ( V_9 ) -> V_124 [ V_123 ] , V_85 ) ;
break;
case V_82 :
default:
break;
}
}
static void F_69 ( int V_76 , int V_14 , struct V_8 * V_9 , double V_120 )
{
double V_125 = V_120 / 1e6 ;
const char * V_126 = V_86 ? L_18 : L_19 ;
F_66 ( V_9 , V_76 , V_14 ) ;
fprintf ( V_74 , V_126 , V_125 , V_85 , F_30 ( V_9 ) ) ;
if ( V_9 -> V_127 )
fprintf ( V_74 , L_20 , V_85 , V_9 -> V_127 -> V_128 ) ;
if ( V_86 || V_99 )
return;
if ( F_24 ( V_9 , V_51 , V_53 ) )
fprintf ( V_74 , L_21 ,
V_120 / F_70 ( & V_38 ) ) ;
else
fprintf ( V_74 , L_22 ) ;
}
static const char * F_71 ( enum V_129 type , double V_130 )
{
static const double V_131 [ V_132 ] [ 3 ] = {
[ V_133 ] = { 50.0 , 30.0 , 10.0 } ,
[ V_134 ] = { 75.0 , 50.0 , 20.0 } ,
[ V_135 ] = { 20.0 , 10.0 , 5.0 } ,
} ;
const char * V_136 = V_137 ;
if ( V_130 > V_131 [ type ] [ 0 ] )
V_136 = V_138 ;
else if ( V_130 > V_131 [ type ] [ 1 ] )
V_136 = V_139 ;
else if ( V_130 > V_131 [ type ] [ 2 ] )
V_136 = V_140 ;
return V_136 ;
}
static void F_72 ( int V_76 ,
struct V_8 * V_9
V_114 , double V_120 )
{
double V_119 , V_130 = 0.0 ;
const char * V_136 ;
V_119 = F_70 ( & V_28 [ V_76 ] ) ;
if ( V_119 )
V_130 = V_120 / V_119 * 100.0 ;
V_136 = F_71 ( V_133 , V_130 ) ;
fprintf ( V_74 , L_23 ) ;
F_73 ( V_74 , V_136 , L_24 , V_130 ) ;
fprintf ( V_74 , L_25 ) ;
}
static void F_74 ( int V_76 ,
struct V_8 * V_9
V_114 , double V_120 )
{
double V_119 , V_130 = 0.0 ;
const char * V_136 ;
V_119 = F_70 ( & V_28 [ V_76 ] ) ;
if ( V_119 )
V_130 = V_120 / V_119 * 100.0 ;
V_136 = F_71 ( V_134 , V_130 ) ;
fprintf ( V_74 , L_23 ) ;
F_73 ( V_74 , V_136 , L_24 , V_130 ) ;
fprintf ( V_74 , L_26 ) ;
}
static void F_75 ( int V_76 ,
struct V_8 * V_9 V_114 ,
double V_120 )
{
double V_119 , V_130 = 0.0 ;
const char * V_136 ;
V_119 = F_70 ( & V_31 [ V_76 ] ) ;
if ( V_119 )
V_130 = V_120 / V_119 * 100.0 ;
V_136 = F_71 ( V_135 , V_130 ) ;
fprintf ( V_74 , L_23 ) ;
F_73 ( V_74 , V_136 , L_24 , V_130 ) ;
fprintf ( V_74 , L_27 ) ;
}
static void F_76 ( int V_76 ,
struct V_8 * V_9 V_114 ,
double V_120 )
{
double V_119 , V_130 = 0.0 ;
const char * V_136 ;
V_119 = F_70 ( & V_33 [ V_76 ] ) ;
if ( V_119 )
V_130 = V_120 / V_119 * 100.0 ;
V_136 = F_71 ( V_135 , V_130 ) ;
fprintf ( V_74 , L_23 ) ;
F_73 ( V_74 , V_136 , L_24 , V_130 ) ;
fprintf ( V_74 , L_28 ) ;
}
static void F_77 ( int V_76 ,
struct V_8 * V_9 V_114 ,
double V_120 )
{
double V_119 , V_130 = 0.0 ;
const char * V_136 ;
V_119 = F_70 ( & V_34 [ V_76 ] ) ;
if ( V_119 )
V_130 = V_120 / V_119 * 100.0 ;
V_136 = F_71 ( V_135 , V_130 ) ;
fprintf ( V_74 , L_23 ) ;
F_73 ( V_74 , V_136 , L_24 , V_130 ) ;
fprintf ( V_74 , L_29 ) ;
}
static void F_78 ( int V_76 ,
struct V_8 * V_9 V_114 ,
double V_120 )
{
double V_119 , V_130 = 0.0 ;
const char * V_136 ;
V_119 = F_70 ( & V_37 [ V_76 ] ) ;
if ( V_119 )
V_130 = V_120 / V_119 * 100.0 ;
V_136 = F_71 ( V_135 , V_130 ) ;
fprintf ( V_74 , L_23 ) ;
F_73 ( V_74 , V_136 , L_24 , V_130 ) ;
fprintf ( V_74 , L_30 ) ;
}
static void F_79 ( int V_76 ,
struct V_8 * V_9 V_114 ,
double V_120 )
{
double V_119 , V_130 = 0.0 ;
const char * V_136 ;
V_119 = F_70 ( & V_36 [ V_76 ] ) ;
if ( V_119 )
V_130 = V_120 / V_119 * 100.0 ;
V_136 = F_71 ( V_135 , V_130 ) ;
fprintf ( V_74 , L_23 ) ;
F_73 ( V_74 , V_136 , L_24 , V_130 ) ;
fprintf ( V_74 , L_31 ) ;
}
static void F_80 ( int V_76 ,
struct V_8 * V_9 V_114 ,
double V_120 )
{
double V_119 , V_130 = 0.0 ;
const char * V_136 ;
V_119 = F_70 ( & V_35 [ V_76 ] ) ;
if ( V_119 )
V_130 = V_120 / V_119 * 100.0 ;
V_136 = F_71 ( V_135 , V_130 ) ;
fprintf ( V_74 , L_23 ) ;
F_73 ( V_74 , V_136 , L_24 , V_130 ) ;
fprintf ( V_74 , L_32 ) ;
}
static void F_81 ( int V_76 , int V_14 , struct V_8 * V_9 , double V_120 )
{
double V_119 , V_130 = 0.0 ;
const char * V_126 ;
if ( V_86 )
V_126 = L_33 ;
else if ( V_141 )
V_126 = L_34 ;
else
V_126 = L_35 ;
F_66 ( V_9 , V_76 , V_14 ) ;
if ( V_81 == V_82 )
V_76 = 0 ;
fprintf ( V_74 , V_126 , V_120 , V_85 , F_30 ( V_9 ) ) ;
if ( V_9 -> V_127 )
fprintf ( V_74 , L_20 , V_85 , V_9 -> V_127 -> V_128 ) ;
if ( V_86 || V_99 )
return;
if ( F_24 ( V_9 , V_56 , V_142 ) ) {
V_119 = F_70 ( & V_28 [ V_76 ] ) ;
if ( V_119 )
V_130 = V_120 / V_119 ;
fprintf ( V_74 , L_36 , V_130 ) ;
V_119 = F_70 ( & V_29 [ V_76 ] ) ;
V_119 = F_82 ( V_119 , F_70 ( & V_30 [ V_76 ] ) ) ;
if ( V_119 && V_120 ) {
V_130 = V_119 / V_120 ;
fprintf ( V_74 , L_37 , V_130 ) ;
}
} else if ( F_24 ( V_9 , V_56 , V_143 ) &&
V_31 [ V_76 ] . V_144 != 0 ) {
F_75 ( V_76 , V_9 , V_120 ) ;
} else if (
V_9 -> V_40 . type == V_145 &&
V_9 -> V_40 . V_146 == ( V_147 |
( ( V_148 ) << 8 ) |
( ( V_149 ) << 16 ) ) &&
V_33 [ V_76 ] . V_144 != 0 ) {
F_76 ( V_76 , V_9 , V_120 ) ;
} else if (
V_9 -> V_40 . type == V_145 &&
V_9 -> V_40 . V_146 == ( V_150 |
( ( V_148 ) << 8 ) |
( ( V_149 ) << 16 ) ) &&
V_34 [ V_76 ] . V_144 != 0 ) {
F_77 ( V_76 , V_9 , V_120 ) ;
} else if (
V_9 -> V_40 . type == V_145 &&
V_9 -> V_40 . V_146 == ( V_151 |
( ( V_148 ) << 8 ) |
( ( V_149 ) << 16 ) ) &&
V_37 [ V_76 ] . V_144 != 0 ) {
F_78 ( V_76 , V_9 , V_120 ) ;
} else if (
V_9 -> V_40 . type == V_145 &&
V_9 -> V_40 . V_146 == ( V_152 |
( ( V_148 ) << 8 ) |
( ( V_149 ) << 16 ) ) &&
V_36 [ V_76 ] . V_144 != 0 ) {
F_79 ( V_76 , V_9 , V_120 ) ;
} else if (
V_9 -> V_40 . type == V_145 &&
V_9 -> V_40 . V_146 == ( V_153 |
( ( V_148 ) << 8 ) |
( ( V_149 ) << 16 ) ) &&
V_35 [ V_76 ] . V_144 != 0 ) {
F_80 ( V_76 , V_9 , V_120 ) ;
} else if ( F_24 ( V_9 , V_56 , V_154 ) &&
V_32 [ V_76 ] . V_144 != 0 ) {
V_119 = F_70 ( & V_32 [ V_76 ] ) ;
if ( V_119 )
V_130 = V_120 * 100 / V_119 ;
fprintf ( V_74 , L_38 , V_130 ) ;
} else if ( F_24 ( V_9 , V_56 , V_58 ) ) {
F_72 ( V_76 , V_9 , V_120 ) ;
} else if ( F_24 ( V_9 , V_56 , V_59 ) ) {
F_74 ( V_76 , V_9 , V_120 ) ;
} else if ( F_24 ( V_9 , V_56 , V_57 ) ) {
V_119 = F_70 ( & V_27 [ V_76 ] ) ;
if ( V_119 )
V_130 = 1.0 * V_120 / V_119 ;
fprintf ( V_74 , L_39 , V_130 ) ;
} else if ( V_27 [ V_76 ] . V_144 != 0 ) {
char V_155 = 'M' ;
V_119 = F_70 ( & V_27 [ V_76 ] ) ;
if ( V_119 )
V_130 = 1000.0 * V_120 / V_119 ;
if ( V_130 < 0.001 ) {
V_130 *= 1000 ;
V_155 = 'K' ;
}
fprintf ( V_74 , L_40 , V_130 , V_155 ) ;
} else {
fprintf ( V_74 , L_22 ) ;
}
}
static void F_35 ( char * V_80 )
{
struct V_8 * V_54 ;
int V_76 , V_156 , V_157 , V_158 , V_123 , V_14 ;
T_2 V_159 , V_160 , V_161 ;
if ( ! ( V_162 || V_163 ) )
return;
for ( V_157 = 0 ; V_157 < V_162 -> V_14 ; V_157 ++ ) {
V_123 = V_162 -> V_124 [ V_157 ] ;
F_11 (counter, &evsel_list->entries, node) {
V_161 = V_159 = V_160 = 0 ;
V_14 = 0 ;
for ( V_76 = 0 ; V_76 < F_3 ( V_54 ) ; V_76 ++ ) {
V_156 = F_2 ( V_54 ) -> V_124 [ V_76 ] ;
V_158 = V_163 ( V_13 -> V_10 , V_156 ) ;
if ( V_158 != V_123 )
continue;
V_161 += V_54 -> V_20 -> V_76 [ V_76 ] . V_161 ;
V_159 += V_54 -> V_20 -> V_76 [ V_76 ] . V_159 ;
V_160 += V_54 -> V_20 -> V_76 [ V_76 ] . V_160 ;
V_14 ++ ;
}
if ( V_80 )
fprintf ( V_74 , L_41 , V_80 ) ;
if ( V_160 == 0 || V_159 == 0 ) {
F_66 ( V_54 , V_123 , V_14 ) ;
fprintf ( V_74 , L_42 ,
V_86 ? 0 : 18 ,
V_54 -> V_110 ? V_164 : V_165 ,
V_85 ,
V_86 ? 0 : - 24 ,
F_30 ( V_54 ) ) ;
if ( V_54 -> V_127 )
fprintf ( V_74 , L_20 ,
V_85 , V_54 -> V_127 -> V_128 ) ;
fputc ( '\n' , V_74 ) ;
continue;
}
if ( F_23 ( V_54 ) )
F_69 ( V_123 , V_14 , V_54 , V_161 ) ;
else
F_81 ( V_123 , V_14 , V_54 , V_161 ) ;
if ( ! V_86 ) {
F_64 ( V_54 , 1.0 ) ;
if ( V_160 != V_159 )
fprintf ( V_74 , L_43 ,
100.0 * V_160 / V_159 ) ;
}
fputc ( '\n' , V_74 ) ;
}
}
}
static void F_37 ( struct V_8 * V_54 , char * V_80 )
{
struct V_16 * V_68 = V_54 -> V_15 ;
double V_120 = F_70 ( & V_68 -> V_72 [ 0 ] ) ;
int V_166 = V_54 -> V_20 -> V_166 ;
if ( V_80 )
fprintf ( V_74 , L_41 , V_80 ) ;
if ( V_166 == - 1 ) {
fprintf ( V_74 , L_42 ,
V_86 ? 0 : 18 ,
V_54 -> V_110 ? V_164 : V_165 ,
V_85 ,
V_86 ? 0 : - 24 ,
F_30 ( V_54 ) ) ;
if ( V_54 -> V_127 )
fprintf ( V_74 , L_20 , V_85 , V_54 -> V_127 -> V_128 ) ;
fputc ( '\n' , V_74 ) ;
return;
}
if ( F_23 ( V_54 ) )
F_69 ( - 1 , 0 , V_54 , V_120 ) ;
else
F_81 ( - 1 , 0 , V_54 , V_120 ) ;
F_64 ( V_54 , V_120 ) ;
if ( V_86 ) {
fputc ( '\n' , V_74 ) ;
return;
}
if ( V_166 ) {
double V_167 , V_168 ;
V_167 = F_70 ( & V_68 -> V_72 [ 1 ] ) ;
V_168 = F_70 ( & V_68 -> V_72 [ 2 ] ) ;
fprintf ( V_74 , L_44 , 100 * V_168 / V_167 ) ;
}
fprintf ( V_74 , L_3 ) ;
}
static void F_36 ( struct V_8 * V_54 , char * V_80 )
{
T_2 V_159 , V_160 , V_161 ;
int V_76 ;
for ( V_76 = 0 ; V_76 < F_3 ( V_54 ) ; V_76 ++ ) {
V_161 = V_54 -> V_20 -> V_76 [ V_76 ] . V_161 ;
V_159 = V_54 -> V_20 -> V_76 [ V_76 ] . V_159 ;
V_160 = V_54 -> V_20 -> V_76 [ V_76 ] . V_160 ;
if ( V_80 )
fprintf ( V_74 , L_41 , V_80 ) ;
if ( V_160 == 0 || V_159 == 0 ) {
fprintf ( V_74 , L_45 ,
V_86 ? 0 : - 4 ,
F_2 ( V_54 ) -> V_124 [ V_76 ] , V_85 ,
V_86 ? 0 : 18 ,
V_54 -> V_110 ? V_164 : V_165 ,
V_85 ,
V_86 ? 0 : - 24 ,
F_30 ( V_54 ) ) ;
if ( V_54 -> V_127 )
fprintf ( V_74 , L_20 ,
V_85 , V_54 -> V_127 -> V_128 ) ;
fputc ( '\n' , V_74 ) ;
continue;
}
if ( F_23 ( V_54 ) )
F_69 ( V_76 , 0 , V_54 , V_161 ) ;
else
F_81 ( V_76 , 0 , V_54 , V_161 ) ;
if ( ! V_86 ) {
F_64 ( V_54 , 1.0 ) ;
if ( V_160 != V_159 )
fprintf ( V_74 , L_43 ,
100.0 * V_160 / V_159 ) ;
}
fputc ( '\n' , V_74 ) ;
}
}
static void F_83 ( int V_92 , const char * * V_93 )
{
struct V_8 * V_54 ;
int V_71 ;
fflush ( stdout ) ;
if ( ! V_86 ) {
fprintf ( V_74 , L_3 ) ;
fprintf ( V_74 , L_46 ) ;
if ( ! F_20 ( & V_11 ) ) {
fprintf ( V_74 , L_47 , V_93 [ 0 ] ) ;
for ( V_71 = 1 ; V_71 < V_92 ; V_71 ++ )
fprintf ( V_74 , L_48 , V_93 [ V_71 ] ) ;
} else if ( V_11 . V_102 )
fprintf ( V_74 , L_49 , V_11 . V_102 ) ;
else
fprintf ( V_74 , L_50 , V_11 . V_169 ) ;
fprintf ( V_74 , L_51 ) ;
if ( V_122 > 1 )
fprintf ( V_74 , L_52 , V_122 ) ;
fprintf ( V_74 , L_53 ) ;
}
switch ( V_81 ) {
case V_88 :
case V_87 :
F_35 ( NULL ) ;
break;
case V_82 :
F_11 (counter, &evsel_list->entries, node)
F_37 ( V_54 , NULL ) ;
break;
case V_89 :
F_11 (counter, &evsel_list->entries, node)
F_36 ( V_54 , NULL ) ;
break;
default:
break;
}
if ( ! V_86 ) {
if ( ! V_170 )
fprintf ( V_74 , L_3 ) ;
fprintf ( V_74 , L_54 ,
F_70 ( & V_38 ) / 1e9 ) ;
if ( V_122 > 1 ) {
fprintf ( V_74 , L_55 ) ;
F_62 ( F_65 ( & V_38 ) ,
F_70 ( & V_38 ) ) ;
}
fprintf ( V_74 , L_56 ) ;
}
}
static void F_84 ( int V_171 )
{
if ( ( V_100 == - 1 ) || V_99 )
V_113 = 1 ;
V_172 = V_171 ;
V_100 = - 1 ;
}
static void F_85 ( void )
{
T_3 V_173 , V_174 ;
F_86 ( & V_173 ) ;
F_87 ( & V_173 , V_175 ) ;
F_88 ( V_176 , & V_173 , & V_174 ) ;
if ( V_100 != - 1 )
F_48 ( V_100 , V_111 ) ;
F_88 ( V_177 , & V_174 , NULL ) ;
if ( V_172 == - 1 )
return;
signal ( V_172 , V_178 ) ;
F_48 ( F_89 () , V_172 ) ;
}
static int F_90 ( const struct V_179 * T_4 V_114 ,
const char * V_157 V_114 , int V_180 )
{
V_181 = V_180 ? 0 : 1 ;
return 0 ;
}
static int F_91 ( void )
{
switch ( V_81 ) {
case V_87 :
if ( F_92 ( V_13 -> V_10 , & V_162 ) ) {
perror ( L_57 ) ;
return - 1 ;
}
V_163 = V_182 ;
break;
case V_88 :
if ( F_93 ( V_13 -> V_10 , & V_162 ) ) {
perror ( L_58 ) ;
return - 1 ;
}
V_163 = V_183 ;
break;
case V_89 :
case V_82 :
default:
break;
}
return 0 ;
}
static int F_94 ( void )
{
struct V_39 V_184 [] = {
{ . type = V_185 , . V_146 = V_186 } ,
{ . type = V_185 , . V_146 = V_187 } ,
{ . type = V_185 , . V_146 = V_188 } ,
{ . type = V_185 , . V_146 = V_189 } ,
{ . type = V_190 , . V_146 = V_191 } ,
{ . type = V_190 , . V_146 = V_192 } ,
{ . type = V_190 , . V_146 = V_193 } ,
{ . type = V_190 , . V_146 = V_194 } ,
{ . type = V_190 , . V_146 = V_195 } ,
{ . type = V_190 , . V_146 = V_196 } ,
} ;
struct V_39 V_197 [] = {
{ . type = V_145 ,
. V_146 =
V_147 << 0 |
( V_148 << 8 ) |
( V_198 << 16 ) } ,
{ . type = V_145 ,
. V_146 =
V_147 << 0 |
( V_148 << 8 ) |
( V_149 << 16 ) } ,
{ . type = V_145 ,
. V_146 =
V_153 << 0 |
( V_148 << 8 ) |
( V_198 << 16 ) } ,
{ . type = V_145 ,
. V_146 =
V_153 << 0 |
( V_148 << 8 ) |
( V_149 << 16 ) } ,
} ;
struct V_39 V_199 [] = {
{ . type = V_145 ,
. V_146 =
V_150 << 0 |
( V_148 << 8 ) |
( V_198 << 16 ) } ,
{ . type = V_145 ,
. V_146 =
V_150 << 0 |
( V_148 << 8 ) |
( V_149 << 16 ) } ,
{ . type = V_145 ,
. V_146 =
V_151 << 0 |
( V_148 << 8 ) |
( V_198 << 16 ) } ,
{ . type = V_145 ,
. V_146 =
V_151 << 0 |
( V_148 << 8 ) |
( V_149 << 16 ) } ,
{ . type = V_145 ,
. V_146 =
V_152 << 0 |
( V_148 << 8 ) |
( V_198 << 16 ) } ,
{ . type = V_145 ,
. V_146 =
V_152 << 0 |
( V_148 << 8 ) |
( V_149 << 16 ) } ,
} ;
struct V_39 V_200 [] = {
{ . type = V_145 ,
. V_146 =
V_147 << 0 |
( V_201 << 8 ) |
( V_198 << 16 ) } ,
{ . type = V_145 ,
. V_146 =
V_147 << 0 |
( V_201 << 8 ) |
( V_149 << 16 ) } ,
} ;
if ( V_170 )
return 0 ;
if ( ! V_13 -> V_202 ) {
if ( F_95 ( V_13 , V_184 ) < 0 )
return - 1 ;
}
if ( V_203 < 1 )
return 0 ;
if ( F_95 ( V_13 , V_197 ) < 0 )
return - 1 ;
if ( V_203 < 2 )
return 0 ;
if ( F_95 ( V_13 , V_199 ) < 0 )
return - 1 ;
if ( V_203 < 3 )
return 0 ;
return F_95 ( V_13 , V_200 ) ;
}
int F_96 ( int V_92 , const char * * V_93 , const char * V_80 V_114 )
{
bool V_204 = false ;
int V_205 = 0 ;
const char * V_206 = NULL ;
const struct V_179 V_207 [] = {
F_97 ( 'e' , L_59 , & V_13 , L_59 ,
L_60 ,
V_208 ) ,
F_97 ( 0 , L_61 , & V_13 , L_61 ,
L_62 , V_209 ) ,
F_98 ( 'i' , L_63 , & V_46 ,
L_64 ) ,
F_99 ( 'p' , L_65 , & V_11 . V_102 , L_65 ,
L_66 ) ,
F_99 ( 't' , L_67 , & V_11 . V_169 , L_67 ,
L_68 ) ,
F_98 ( 'a' , L_69 , & V_11 . V_210 ,
L_70 ) ,
F_98 ( 'g' , L_71 , & V_103 ,
L_72 ) ,
F_98 ( 'c' , L_73 , & V_41 , L_74 ) ,
F_100 ( 'v' , L_75 , & V_73 ,
L_76 ) ,
F_101 ( 'r' , L_77 , & V_122 ,
L_78 ) ,
F_98 ( 'n' , L_79 , & V_170 ,
L_80 ) ,
F_100 ( 'd' , L_81 , & V_203 ,
L_82 ) ,
F_98 ( 'S' , L_83 , & V_117 ,
L_84 ) ,
F_102 ( 'B' , L_85 , NULL , NULL ,
L_86 ,
F_90 ) ,
F_99 ( 'C' , L_87 , & V_11 . V_12 , L_87 ,
L_88 ) ,
F_103 ( 'A' , L_89 , & V_81 ,
L_90 , V_89 ) ,
F_99 ( 'x' , L_91 , & V_85 , L_92 ,
L_93 ) ,
F_97 ( 'G' , L_94 , & V_13 , L_95 ,
L_96 , V_211 ) ,
F_99 ( 'o' , L_97 , & V_206 , L_98 , L_99 ) ,
F_98 ( 0 , L_100 , & V_204 , L_101 ) ,
F_101 ( 0 , L_102 , & V_205 ,
L_103 ) ,
F_99 ( 0 , L_104 , & V_116 , L_105 ,
L_106 ) ,
F_99 ( 0 , L_107 , & V_118 , L_105 ,
L_108 ) ,
F_104 ( 'I' , L_109 , & V_99 ,
L_110 ) ,
F_103 ( 0 , L_111 , & V_81 ,
L_112 , V_87 ) ,
F_103 ( 0 , L_113 , & V_81 ,
L_114 , V_88 ) ,
F_104 ( 'D' , L_115 , & V_48 ,
L_116 ) ,
F_105 ()
} ;
const char * const V_212 [] = {
L_117 ,
NULL
} ;
int V_97 = - V_17 , V_213 ;
const char * V_214 ;
setlocale ( V_215 , L_118 ) ;
V_13 = F_106 () ;
if ( V_13 == NULL )
return - V_17 ;
V_92 = F_107 ( V_92 , V_93 , V_207 , V_212 ,
V_216 ) ;
V_74 = V_217 ;
if ( V_206 && strcmp ( V_206 , L_119 ) )
V_74 = NULL ;
if ( V_206 && V_205 ) {
fprintf ( V_217 , L_120 ) ;
F_108 ( V_212 , V_207 ) ;
}
if ( V_205 < 0 ) {
fprintf ( V_217 , L_121 ) ;
F_108 ( V_212 , V_207 ) ;
}
if ( ! V_74 ) {
struct V_1 V_218 ;
V_214 = V_204 ? L_122 : L_123 ;
V_74 = fopen ( V_206 , V_214 ) ;
if ( ! V_74 ) {
perror ( L_124 ) ;
return - 1 ;
}
F_34 ( V_219 , & V_218 ) ;
fprintf ( V_74 , L_125 , ctime ( & V_218 . V_5 ) ) ;
} else if ( V_205 > 0 ) {
V_214 = V_204 ? L_122 : L_123 ;
V_74 = fdopen ( V_205 , V_214 ) ;
if ( ! V_74 ) {
perror ( L_126 ) ;
return - V_104 ;
}
}
if ( V_85 ) {
V_86 = true ;
if ( ! strcmp ( V_85 , L_127 ) )
V_85 = L_128 ;
} else
V_85 = V_220 ;
if ( V_86 ) {
if ( V_181 == 1 ) {
fprintf ( V_217 , L_129 ) ;
F_108 ( V_212 , V_207 ) ;
} else
V_141 = false ;
} else if ( V_181 == 0 )
V_141 = false ;
if ( ! V_92 && ! F_20 ( & V_11 ) )
F_108 ( V_212 , V_207 ) ;
if ( V_122 < 0 ) {
F_108 ( V_212 , V_207 ) ;
} else if ( V_122 == 0 ) {
V_221 = true ;
V_122 = 1 ;
}
if ( ( V_81 != V_82 || V_222 )
&& ! F_18 ( & V_11 ) ) {
fprintf ( V_217 , L_130
L_131 ) ;
F_108 ( V_212 , V_207 ) ;
return - 1 ;
}
if ( F_94 () )
goto V_223;
F_109 ( & V_11 ) ;
if ( F_110 ( V_13 , & V_11 ) < 0 ) {
if ( F_20 ( & V_11 ) )
F_111 ( L_132 ) ;
if ( F_18 ( & V_11 ) )
perror ( L_133 ) ;
F_108 ( V_212 , V_207 ) ;
return - 1 ;
}
if ( V_99 && V_99 < 100 ) {
F_111 ( L_134 ) ;
F_108 ( V_212 , V_207 ) ;
return - 1 ;
}
if ( F_13 ( V_13 , V_99 ) )
goto V_224;
if ( F_91 () )
goto V_223;
atexit ( F_85 ) ;
if ( ! V_221 )
signal ( V_225 , F_84 ) ;
signal ( V_175 , F_84 ) ;
signal ( V_226 , F_84 ) ;
signal ( V_227 , F_84 ) ;
V_97 = 0 ;
for ( V_213 = 0 ; V_221 || V_213 < V_122 ; V_213 ++ ) {
if ( V_122 != 1 && V_73 )
fprintf ( V_74 , L_135 ,
V_213 + 1 ) ;
V_97 = F_60 ( V_92 , V_93 ) ;
if ( V_221 && V_97 != - 1 ) {
F_83 ( V_92 , V_93 ) ;
F_15 ( V_13 ) ;
}
}
if ( ! V_221 && V_97 != - 1 && ! V_99 )
F_83 ( V_92 , V_93 ) ;
F_10 ( V_13 ) ;
V_224:
F_112 ( V_13 ) ;
V_223:
F_113 ( V_13 ) ;
return V_97 ;
}
