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
V_40 -> V_48 = 1 ;
}
return F_22 ( V_9 , V_13 -> V_49 ) ;
}
static inline int F_23 ( struct V_8 * V_9 )
{
if ( F_24 ( V_9 , V_50 , V_51 ) ||
F_24 ( V_9 , V_50 , V_52 ) )
return 1 ;
return 0 ;
}
static void F_25 ( struct V_8 * V_53 , T_2 * V_54 )
{
if ( F_24 ( V_53 , V_50 , V_52 ) )
F_26 ( & V_27 [ 0 ] , V_54 [ 0 ] ) ;
else if ( F_24 ( V_53 , V_55 , V_56 ) )
F_26 ( & V_28 [ 0 ] , V_54 [ 0 ] ) ;
else if ( F_24 ( V_53 , V_55 , V_57 ) )
F_26 ( & V_29 [ 0 ] , V_54 [ 0 ] ) ;
else if ( F_24 ( V_53 , V_55 , V_58 ) )
F_26 ( & V_30 [ 0 ] , V_54 [ 0 ] ) ;
else if ( F_24 ( V_53 , V_55 , V_59 ) )
F_26 ( & V_31 [ 0 ] , V_54 [ 0 ] ) ;
else if ( F_24 ( V_53 , V_55 , V_60 ) )
F_26 ( & V_32 [ 0 ] , V_54 [ 0 ] ) ;
else if ( F_24 ( V_53 , V_61 , V_62 ) )
F_26 ( & V_33 [ 0 ] , V_54 [ 0 ] ) ;
else if ( F_24 ( V_53 , V_61 , V_63 ) )
F_26 ( & V_34 [ 0 ] , V_54 [ 0 ] ) ;
else if ( F_24 ( V_53 , V_61 , V_64 ) )
F_26 ( & V_35 [ 0 ] , V_54 [ 0 ] ) ;
else if ( F_24 ( V_53 , V_61 , V_65 ) )
F_26 ( & V_37 [ 0 ] , V_54 [ 0 ] ) ;
else if ( F_24 ( V_53 , V_61 , V_66 ) )
F_26 ( & V_36 [ 0 ] , V_54 [ 0 ] ) ;
}
static int F_27 ( struct V_8 * V_53 )
{
struct V_16 * V_67 = V_53 -> V_15 ;
T_2 * V_54 = V_53 -> V_20 -> V_68 . V_69 ;
int V_70 ;
if ( F_28 ( V_53 , F_3 ( V_53 ) ,
F_29 ( V_13 -> V_49 ) , V_41 ) < 0 )
return - 1 ;
for ( V_70 = 0 ; V_70 < 3 ; V_70 ++ )
F_26 ( & V_67 -> V_71 [ V_70 ] , V_54 [ V_70 ] ) ;
if ( V_72 ) {
fprintf ( V_73 , L_1 V_74 L_2 V_74 L_2 V_74 L_3 ,
F_30 ( V_53 ) , V_54 [ 0 ] , V_54 [ 1 ] , V_54 [ 2 ] ) ;
}
F_25 ( V_53 , V_54 ) ;
return 0 ;
}
static int F_31 ( struct V_8 * V_53 )
{
T_2 * V_54 ;
int V_75 ;
for ( V_75 = 0 ; V_75 < F_3 ( V_53 ) ; V_75 ++ ) {
if ( F_32 ( V_53 , V_75 , 0 , V_41 ) < 0 )
return - 1 ;
V_54 = V_53 -> V_20 -> V_75 [ V_75 ] . V_69 ;
F_25 ( V_53 , V_54 ) ;
}
return 0 ;
}
static void F_33 ( void )
{
static int V_76 ;
struct V_8 * V_53 ;
struct V_16 * V_67 ;
struct V_1 V_77 , V_78 ;
char V_79 [ 64 ] ;
if ( V_80 == V_81 ) {
F_11 (counter, &evsel_list->entries, node) {
V_67 = V_53 -> V_15 ;
memset ( V_67 -> V_71 , 0 , sizeof( V_67 -> V_71 ) ) ;
F_27 ( V_53 ) ;
}
} else {
F_11 (counter, &evsel_list->entries, node) {
V_67 = V_53 -> V_15 ;
memset ( V_67 -> V_71 , 0 , sizeof( V_67 -> V_71 ) ) ;
F_31 ( V_53 ) ;
}
}
F_34 ( V_82 , & V_77 ) ;
F_1 ( & V_78 , & V_77 , & V_83 ) ;
sprintf ( V_79 , L_4 , V_78 . V_5 , V_78 . V_6 , V_84 ) ;
if ( V_76 == 0 && ! V_85 ) {
switch ( V_80 ) {
case V_86 :
fprintf ( V_73 , L_5 ) ;
break;
case V_87 :
fprintf ( V_73 , L_6 ) ;
break;
case V_88 :
fprintf ( V_73 , L_7 ) ;
break;
case V_81 :
default:
fprintf ( V_73 , L_8 ) ;
}
}
if ( ++ V_76 == 25 )
V_76 = 0 ;
switch ( V_80 ) {
case V_87 :
case V_86 :
F_35 ( V_79 ) ;
break;
case V_88 :
F_11 (counter, &evsel_list->entries, node)
F_36 ( V_53 , V_79 ) ;
break;
case V_81 :
default:
F_11 (counter, &evsel_list->entries, node)
F_37 ( V_53 , V_79 ) ;
}
}
static int F_38 ( int V_89 , const char * * V_90 )
{
char V_91 [ 512 ] ;
unsigned long long V_92 , V_93 ;
struct V_8 * V_53 ;
struct V_1 V_77 ;
int V_94 = 0 ;
const bool V_95 = ( V_89 > 0 ) ;
if ( V_96 ) {
V_77 . V_5 = V_96 / 1000 ;
V_77 . V_6 = ( V_96 % 1000 ) * 1000000 ;
} else {
V_77 . V_5 = 1 ;
V_77 . V_6 = 0 ;
}
if ( V_95 ) {
if ( F_39 ( V_13 , & V_11 , V_90 ,
false , false ) < 0 ) {
perror ( L_9 ) ;
return - 1 ;
}
}
if ( V_97 )
F_40 ( V_13 ) ;
F_11 (counter, &evsel_list->entries, node) {
if ( F_17 ( V_53 ) < 0 ) {
if ( V_98 == V_99 || V_98 == V_100 ||
V_98 == V_101 || V_98 == V_102 ||
V_98 == V_103 ) {
if ( V_72 )
F_41 ( L_10 ,
F_30 ( V_53 ) ) ;
V_53 -> V_104 = false ;
continue;
}
F_42 ( V_53 , & V_11 ,
V_98 , V_91 , sizeof( V_91 ) ) ;
F_43 ( L_11 , V_91 ) ;
if ( V_105 != - 1 )
F_44 ( V_105 , V_106 ) ;
return - 1 ;
}
V_53 -> V_104 = true ;
}
if ( F_45 ( V_13 ) ) {
error ( L_12 , V_98 ,
strerror ( V_98 ) ) ;
return - 1 ;
}
V_92 = F_46 () ;
F_34 ( V_82 , & V_83 ) ;
if ( V_95 ) {
F_47 ( V_13 ) ;
if ( V_96 ) {
while ( ! F_48 ( V_105 , & V_94 , V_107 ) ) {
F_49 ( & V_77 , NULL ) ;
F_33 () ;
}
}
F_50 ( & V_94 ) ;
if ( F_51 ( V_94 ) )
F_52 ( F_53 ( V_94 ) , V_90 [ 0 ] ) ;
} else {
while ( ! V_108 ) {
F_49 ( & V_77 , NULL ) ;
if ( V_96 )
F_33 () ;
}
}
V_93 = F_46 () ;
F_26 ( & V_38 , V_93 - V_92 ) ;
if ( V_80 == V_81 ) {
F_11 (counter, &evsel_list->entries, node) {
F_27 ( V_53 ) ;
F_54 ( V_53 , F_3 ( V_53 ) ,
F_29 ( V_13 -> V_49 ) ) ;
}
} else {
F_11 (counter, &evsel_list->entries, node) {
F_31 ( V_53 ) ;
F_54 ( V_53 , F_3 ( V_53 ) , 1 ) ;
}
}
return F_55 ( V_94 ) ;
}
static int F_56 ( int V_89 V_109 , const char * * V_90 )
{
int V_110 ;
if ( V_111 ) {
V_110 = system ( V_111 ) ;
if ( V_110 )
return V_110 ;
}
if ( V_112 )
F_57 () ;
V_110 = F_38 ( V_89 , V_90 ) ;
if ( V_110 )
return V_110 ;
if ( V_113 ) {
V_110 = system ( V_113 ) ;
if ( V_110 )
return V_110 ;
}
return V_110 ;
}
static void F_58 ( double V_114 , double V_115 )
{
double V_116 = F_59 ( V_114 , V_115 ) ;
if ( V_85 )
fprintf ( V_73 , L_13 , V_84 , V_116 ) ;
else if ( V_116 )
fprintf ( V_73 , L_14 , V_116 ) ;
}
static void F_60 ( struct V_8 * V_9 , double V_115 )
{
struct V_16 * V_67 ;
if ( V_117 == 1 )
return;
V_67 = V_9 -> V_15 ;
F_58 ( F_61 ( & V_67 -> V_71 [ 0 ] ) , V_115 ) ;
}
static void F_62 ( struct V_8 * V_9 , int V_118 , int V_14 )
{
switch ( V_80 ) {
case V_87 :
fprintf ( V_73 , L_15 ,
F_63 ( V_118 ) ,
V_85 ? 0 : - 8 ,
F_64 ( V_118 ) ,
V_84 ,
V_85 ? 0 : 4 ,
V_14 ,
V_84 ) ;
break;
case V_86 :
fprintf ( V_73 , L_16 ,
V_85 ? 0 : - 5 ,
V_118 ,
V_84 ,
V_85 ? 0 : 4 ,
V_14 ,
V_84 ) ;
break;
case V_88 :
fprintf ( V_73 , L_17 ,
V_85 ? 0 : - 4 ,
F_2 ( V_9 ) -> V_119 [ V_118 ] , V_84 ) ;
break;
case V_81 :
default:
break;
}
}
static void F_65 ( int V_75 , int V_14 , struct V_8 * V_9 , double V_115 )
{
double V_120 = V_115 / 1e6 ;
const char * V_121 = V_85 ? L_18 : L_19 ;
F_62 ( V_9 , V_75 , V_14 ) ;
fprintf ( V_73 , V_121 , V_120 , V_84 , F_30 ( V_9 ) ) ;
if ( V_9 -> V_122 )
fprintf ( V_73 , L_20 , V_84 , V_9 -> V_122 -> V_123 ) ;
if ( V_85 || V_96 )
return;
if ( F_24 ( V_9 , V_50 , V_52 ) )
fprintf ( V_73 , L_21 ,
V_115 / F_66 ( & V_38 ) ) ;
else
fprintf ( V_73 , L_22 ) ;
}
static const char * F_67 ( enum V_124 type , double V_125 )
{
static const double V_126 [ V_127 ] [ 3 ] = {
[ V_128 ] = { 50.0 , 30.0 , 10.0 } ,
[ V_129 ] = { 75.0 , 50.0 , 20.0 } ,
[ V_130 ] = { 20.0 , 10.0 , 5.0 } ,
} ;
const char * V_131 = V_132 ;
if ( V_125 > V_126 [ type ] [ 0 ] )
V_131 = V_133 ;
else if ( V_125 > V_126 [ type ] [ 1 ] )
V_131 = V_134 ;
else if ( V_125 > V_126 [ type ] [ 2 ] )
V_131 = V_135 ;
return V_131 ;
}
static void F_68 ( int V_75 ,
struct V_8 * V_9
V_109 , double V_115 )
{
double V_114 , V_125 = 0.0 ;
const char * V_131 ;
V_114 = F_66 ( & V_28 [ V_75 ] ) ;
if ( V_114 )
V_125 = V_115 / V_114 * 100.0 ;
V_131 = F_67 ( V_128 , V_125 ) ;
fprintf ( V_73 , L_23 ) ;
F_69 ( V_73 , V_131 , L_24 , V_125 ) ;
fprintf ( V_73 , L_25 ) ;
}
static void F_70 ( int V_75 ,
struct V_8 * V_9
V_109 , double V_115 )
{
double V_114 , V_125 = 0.0 ;
const char * V_131 ;
V_114 = F_66 ( & V_28 [ V_75 ] ) ;
if ( V_114 )
V_125 = V_115 / V_114 * 100.0 ;
V_131 = F_67 ( V_129 , V_125 ) ;
fprintf ( V_73 , L_23 ) ;
F_69 ( V_73 , V_131 , L_24 , V_125 ) ;
fprintf ( V_73 , L_26 ) ;
}
static void F_71 ( int V_75 ,
struct V_8 * V_9 V_109 ,
double V_115 )
{
double V_114 , V_125 = 0.0 ;
const char * V_131 ;
V_114 = F_66 ( & V_31 [ V_75 ] ) ;
if ( V_114 )
V_125 = V_115 / V_114 * 100.0 ;
V_131 = F_67 ( V_130 , V_125 ) ;
fprintf ( V_73 , L_23 ) ;
F_69 ( V_73 , V_131 , L_24 , V_125 ) ;
fprintf ( V_73 , L_27 ) ;
}
static void F_72 ( int V_75 ,
struct V_8 * V_9 V_109 ,
double V_115 )
{
double V_114 , V_125 = 0.0 ;
const char * V_131 ;
V_114 = F_66 ( & V_33 [ V_75 ] ) ;
if ( V_114 )
V_125 = V_115 / V_114 * 100.0 ;
V_131 = F_67 ( V_130 , V_125 ) ;
fprintf ( V_73 , L_23 ) ;
F_69 ( V_73 , V_131 , L_24 , V_125 ) ;
fprintf ( V_73 , L_28 ) ;
}
static void F_73 ( int V_75 ,
struct V_8 * V_9 V_109 ,
double V_115 )
{
double V_114 , V_125 = 0.0 ;
const char * V_131 ;
V_114 = F_66 ( & V_34 [ V_75 ] ) ;
if ( V_114 )
V_125 = V_115 / V_114 * 100.0 ;
V_131 = F_67 ( V_130 , V_125 ) ;
fprintf ( V_73 , L_23 ) ;
F_69 ( V_73 , V_131 , L_24 , V_125 ) ;
fprintf ( V_73 , L_29 ) ;
}
static void F_74 ( int V_75 ,
struct V_8 * V_9 V_109 ,
double V_115 )
{
double V_114 , V_125 = 0.0 ;
const char * V_131 ;
V_114 = F_66 ( & V_37 [ V_75 ] ) ;
if ( V_114 )
V_125 = V_115 / V_114 * 100.0 ;
V_131 = F_67 ( V_130 , V_125 ) ;
fprintf ( V_73 , L_23 ) ;
F_69 ( V_73 , V_131 , L_24 , V_125 ) ;
fprintf ( V_73 , L_30 ) ;
}
static void F_75 ( int V_75 ,
struct V_8 * V_9 V_109 ,
double V_115 )
{
double V_114 , V_125 = 0.0 ;
const char * V_131 ;
V_114 = F_66 ( & V_36 [ V_75 ] ) ;
if ( V_114 )
V_125 = V_115 / V_114 * 100.0 ;
V_131 = F_67 ( V_130 , V_125 ) ;
fprintf ( V_73 , L_23 ) ;
F_69 ( V_73 , V_131 , L_24 , V_125 ) ;
fprintf ( V_73 , L_31 ) ;
}
static void F_76 ( int V_75 ,
struct V_8 * V_9 V_109 ,
double V_115 )
{
double V_114 , V_125 = 0.0 ;
const char * V_131 ;
V_114 = F_66 ( & V_35 [ V_75 ] ) ;
if ( V_114 )
V_125 = V_115 / V_114 * 100.0 ;
V_131 = F_67 ( V_130 , V_125 ) ;
fprintf ( V_73 , L_23 ) ;
F_69 ( V_73 , V_131 , L_24 , V_125 ) ;
fprintf ( V_73 , L_32 ) ;
}
static void F_77 ( int V_75 , int V_14 , struct V_8 * V_9 , double V_115 )
{
double V_114 , V_125 = 0.0 ;
const char * V_121 ;
if ( V_85 )
V_121 = L_33 ;
else if ( V_136 )
V_121 = L_34 ;
else
V_121 = L_35 ;
F_62 ( V_9 , V_75 , V_14 ) ;
if ( V_80 == V_81 )
V_75 = 0 ;
fprintf ( V_73 , V_121 , V_115 , V_84 , F_30 ( V_9 ) ) ;
if ( V_9 -> V_122 )
fprintf ( V_73 , L_20 , V_84 , V_9 -> V_122 -> V_123 ) ;
if ( V_85 || V_96 )
return;
if ( F_24 ( V_9 , V_55 , V_137 ) ) {
V_114 = F_66 ( & V_28 [ V_75 ] ) ;
if ( V_114 )
V_125 = V_115 / V_114 ;
fprintf ( V_73 , L_36 , V_125 ) ;
V_114 = F_66 ( & V_29 [ V_75 ] ) ;
V_114 = F_78 ( V_114 , F_66 ( & V_30 [ V_75 ] ) ) ;
if ( V_114 && V_115 ) {
V_125 = V_114 / V_115 ;
fprintf ( V_73 , L_37 , V_125 ) ;
}
} else if ( F_24 ( V_9 , V_55 , V_138 ) &&
V_31 [ V_75 ] . V_139 != 0 ) {
F_71 ( V_75 , V_9 , V_115 ) ;
} else if (
V_9 -> V_40 . type == V_140 &&
V_9 -> V_40 . V_141 == ( V_142 |
( ( V_143 ) << 8 ) |
( ( V_144 ) << 16 ) ) &&
V_33 [ V_75 ] . V_139 != 0 ) {
F_72 ( V_75 , V_9 , V_115 ) ;
} else if (
V_9 -> V_40 . type == V_140 &&
V_9 -> V_40 . V_141 == ( V_145 |
( ( V_143 ) << 8 ) |
( ( V_144 ) << 16 ) ) &&
V_34 [ V_75 ] . V_139 != 0 ) {
F_73 ( V_75 , V_9 , V_115 ) ;
} else if (
V_9 -> V_40 . type == V_140 &&
V_9 -> V_40 . V_141 == ( V_146 |
( ( V_143 ) << 8 ) |
( ( V_144 ) << 16 ) ) &&
V_37 [ V_75 ] . V_139 != 0 ) {
F_74 ( V_75 , V_9 , V_115 ) ;
} else if (
V_9 -> V_40 . type == V_140 &&
V_9 -> V_40 . V_141 == ( V_147 |
( ( V_143 ) << 8 ) |
( ( V_144 ) << 16 ) ) &&
V_36 [ V_75 ] . V_139 != 0 ) {
F_75 ( V_75 , V_9 , V_115 ) ;
} else if (
V_9 -> V_40 . type == V_140 &&
V_9 -> V_40 . V_141 == ( V_148 |
( ( V_143 ) << 8 ) |
( ( V_144 ) << 16 ) ) &&
V_35 [ V_75 ] . V_139 != 0 ) {
F_76 ( V_75 , V_9 , V_115 ) ;
} else if ( F_24 ( V_9 , V_55 , V_149 ) &&
V_32 [ V_75 ] . V_139 != 0 ) {
V_114 = F_66 ( & V_32 [ V_75 ] ) ;
if ( V_114 )
V_125 = V_115 * 100 / V_114 ;
fprintf ( V_73 , L_38 , V_125 ) ;
} else if ( F_24 ( V_9 , V_55 , V_57 ) ) {
F_68 ( V_75 , V_9 , V_115 ) ;
} else if ( F_24 ( V_9 , V_55 , V_58 ) ) {
F_70 ( V_75 , V_9 , V_115 ) ;
} else if ( F_24 ( V_9 , V_55 , V_56 ) ) {
V_114 = F_66 ( & V_27 [ V_75 ] ) ;
if ( V_114 )
V_125 = 1.0 * V_115 / V_114 ;
fprintf ( V_73 , L_39 , V_125 ) ;
} else if ( V_27 [ V_75 ] . V_139 != 0 ) {
char V_150 = 'M' ;
V_114 = F_66 ( & V_27 [ V_75 ] ) ;
if ( V_114 )
V_125 = 1000.0 * V_115 / V_114 ;
if ( V_125 < 0.001 ) {
V_125 *= 1000 ;
V_150 = 'K' ;
}
fprintf ( V_73 , L_40 , V_125 , V_150 ) ;
} else {
fprintf ( V_73 , L_22 ) ;
}
}
static void F_35 ( char * V_79 )
{
struct V_8 * V_53 ;
int V_75 , V_151 , V_152 , V_153 , V_118 , V_14 ;
T_2 V_154 , V_155 , V_156 ;
if ( ! ( V_157 || V_158 ) )
return;
for ( V_152 = 0 ; V_152 < V_157 -> V_14 ; V_152 ++ ) {
V_118 = V_157 -> V_119 [ V_152 ] ;
F_11 (counter, &evsel_list->entries, node) {
V_156 = V_154 = V_155 = 0 ;
V_14 = 0 ;
for ( V_75 = 0 ; V_75 < F_3 ( V_53 ) ; V_75 ++ ) {
V_151 = F_2 ( V_53 ) -> V_119 [ V_75 ] ;
V_153 = V_158 ( V_13 -> V_10 , V_151 ) ;
if ( V_153 != V_118 )
continue;
V_156 += V_53 -> V_20 -> V_75 [ V_75 ] . V_156 ;
V_154 += V_53 -> V_20 -> V_75 [ V_75 ] . V_154 ;
V_155 += V_53 -> V_20 -> V_75 [ V_75 ] . V_155 ;
V_14 ++ ;
}
if ( V_79 )
fprintf ( V_73 , L_41 , V_79 ) ;
if ( V_155 == 0 || V_154 == 0 ) {
F_62 ( V_53 , V_118 , V_14 ) ;
fprintf ( V_73 , L_42 ,
V_85 ? 0 : 18 ,
V_53 -> V_104 ? V_159 : V_160 ,
V_84 ,
V_85 ? 0 : - 24 ,
F_30 ( V_53 ) ) ;
if ( V_53 -> V_122 )
fprintf ( V_73 , L_20 ,
V_84 , V_53 -> V_122 -> V_123 ) ;
fputc ( '\n' , V_73 ) ;
continue;
}
if ( F_23 ( V_53 ) )
F_65 ( V_118 , V_14 , V_53 , V_156 ) ;
else
F_77 ( V_118 , V_14 , V_53 , V_156 ) ;
if ( ! V_85 ) {
F_60 ( V_53 , 1.0 ) ;
if ( V_155 != V_154 )
fprintf ( V_73 , L_43 ,
100.0 * V_155 / V_154 ) ;
}
fputc ( '\n' , V_73 ) ;
}
}
}
static void F_37 ( struct V_8 * V_53 , char * V_79 )
{
struct V_16 * V_67 = V_53 -> V_15 ;
double V_115 = F_66 ( & V_67 -> V_71 [ 0 ] ) ;
int V_161 = V_53 -> V_20 -> V_161 ;
if ( V_79 )
fprintf ( V_73 , L_41 , V_79 ) ;
if ( V_161 == - 1 ) {
fprintf ( V_73 , L_42 ,
V_85 ? 0 : 18 ,
V_53 -> V_104 ? V_159 : V_160 ,
V_84 ,
V_85 ? 0 : - 24 ,
F_30 ( V_53 ) ) ;
if ( V_53 -> V_122 )
fprintf ( V_73 , L_20 , V_84 , V_53 -> V_122 -> V_123 ) ;
fputc ( '\n' , V_73 ) ;
return;
}
if ( F_23 ( V_53 ) )
F_65 ( - 1 , 0 , V_53 , V_115 ) ;
else
F_77 ( - 1 , 0 , V_53 , V_115 ) ;
F_60 ( V_53 , V_115 ) ;
if ( V_85 ) {
fputc ( '\n' , V_73 ) ;
return;
}
if ( V_161 ) {
double V_162 , V_163 ;
V_162 = F_66 ( & V_67 -> V_71 [ 1 ] ) ;
V_163 = F_66 ( & V_67 -> V_71 [ 2 ] ) ;
fprintf ( V_73 , L_44 , 100 * V_163 / V_162 ) ;
}
fprintf ( V_73 , L_3 ) ;
}
static void F_36 ( struct V_8 * V_53 , char * V_79 )
{
T_2 V_154 , V_155 , V_156 ;
int V_75 ;
for ( V_75 = 0 ; V_75 < F_3 ( V_53 ) ; V_75 ++ ) {
V_156 = V_53 -> V_20 -> V_75 [ V_75 ] . V_156 ;
V_154 = V_53 -> V_20 -> V_75 [ V_75 ] . V_154 ;
V_155 = V_53 -> V_20 -> V_75 [ V_75 ] . V_155 ;
if ( V_79 )
fprintf ( V_73 , L_41 , V_79 ) ;
if ( V_155 == 0 || V_154 == 0 ) {
fprintf ( V_73 , L_45 ,
V_85 ? 0 : - 4 ,
F_2 ( V_53 ) -> V_119 [ V_75 ] , V_84 ,
V_85 ? 0 : 18 ,
V_53 -> V_104 ? V_159 : V_160 ,
V_84 ,
V_85 ? 0 : - 24 ,
F_30 ( V_53 ) ) ;
if ( V_53 -> V_122 )
fprintf ( V_73 , L_20 ,
V_84 , V_53 -> V_122 -> V_123 ) ;
fputc ( '\n' , V_73 ) ;
continue;
}
if ( F_23 ( V_53 ) )
F_65 ( V_75 , 0 , V_53 , V_156 ) ;
else
F_77 ( V_75 , 0 , V_53 , V_156 ) ;
if ( ! V_85 ) {
F_60 ( V_53 , 1.0 ) ;
if ( V_155 != V_154 )
fprintf ( V_73 , L_43 ,
100.0 * V_155 / V_154 ) ;
}
fputc ( '\n' , V_73 ) ;
}
}
static void F_79 ( int V_89 , const char * * V_90 )
{
struct V_8 * V_53 ;
int V_70 ;
fflush ( stdout ) ;
if ( ! V_85 ) {
fprintf ( V_73 , L_3 ) ;
fprintf ( V_73 , L_46 ) ;
if ( ! F_20 ( & V_11 ) ) {
fprintf ( V_73 , L_47 , V_90 [ 0 ] ) ;
for ( V_70 = 1 ; V_70 < V_89 ; V_70 ++ )
fprintf ( V_73 , L_48 , V_90 [ V_70 ] ) ;
} else if ( V_11 . V_164 )
fprintf ( V_73 , L_49 , V_11 . V_164 ) ;
else
fprintf ( V_73 , L_50 , V_11 . V_165 ) ;
fprintf ( V_73 , L_51 ) ;
if ( V_117 > 1 )
fprintf ( V_73 , L_52 , V_117 ) ;
fprintf ( V_73 , L_53 ) ;
}
switch ( V_80 ) {
case V_87 :
case V_86 :
F_35 ( NULL ) ;
break;
case V_81 :
F_11 (counter, &evsel_list->entries, node)
F_37 ( V_53 , NULL ) ;
break;
case V_88 :
F_11 (counter, &evsel_list->entries, node)
F_36 ( V_53 , NULL ) ;
break;
default:
break;
}
if ( ! V_85 ) {
if ( ! V_166 )
fprintf ( V_73 , L_3 ) ;
fprintf ( V_73 , L_54 ,
F_66 ( & V_38 ) / 1e9 ) ;
if ( V_117 > 1 ) {
fprintf ( V_73 , L_55 ) ;
F_58 ( F_61 ( & V_38 ) ,
F_66 ( & V_38 ) ) ;
}
fprintf ( V_73 , L_56 ) ;
}
}
static void F_80 ( int V_167 )
{
if ( ( V_105 == - 1 ) || V_96 )
V_108 = 1 ;
V_168 = V_167 ;
V_105 = - 1 ;
}
static void F_81 ( void )
{
T_3 V_169 , V_170 ;
F_82 ( & V_169 ) ;
F_83 ( & V_169 , V_171 ) ;
F_84 ( V_172 , & V_169 , & V_170 ) ;
if ( V_105 != - 1 )
F_44 ( V_105 , V_106 ) ;
F_84 ( V_173 , & V_170 , NULL ) ;
if ( V_168 == - 1 )
return;
signal ( V_168 , V_174 ) ;
F_44 ( F_85 () , V_168 ) ;
}
static int F_86 ( const struct V_175 * T_4 V_109 ,
const char * V_152 V_109 , int V_176 )
{
V_177 = V_176 ? 0 : 1 ;
return 0 ;
}
static int F_87 ( void )
{
switch ( V_80 ) {
case V_86 :
if ( F_88 ( V_13 -> V_10 , & V_157 ) ) {
perror ( L_57 ) ;
return - 1 ;
}
V_158 = V_178 ;
break;
case V_87 :
if ( F_89 ( V_13 -> V_10 , & V_157 ) ) {
perror ( L_58 ) ;
return - 1 ;
}
V_158 = V_179 ;
break;
case V_88 :
case V_81 :
default:
break;
}
return 0 ;
}
static int F_90 ( void )
{
struct V_39 V_180 [] = {
{ . type = V_181 , . V_141 = V_182 } ,
{ . type = V_181 , . V_141 = V_183 } ,
{ . type = V_181 , . V_141 = V_184 } ,
{ . type = V_181 , . V_141 = V_185 } ,
{ . type = V_186 , . V_141 = V_187 } ,
{ . type = V_186 , . V_141 = V_188 } ,
{ . type = V_186 , . V_141 = V_189 } ,
{ . type = V_186 , . V_141 = V_190 } ,
{ . type = V_186 , . V_141 = V_191 } ,
{ . type = V_186 , . V_141 = V_192 } ,
} ;
struct V_39 V_193 [] = {
{ . type = V_140 ,
. V_141 =
V_142 << 0 |
( V_143 << 8 ) |
( V_194 << 16 ) } ,
{ . type = V_140 ,
. V_141 =
V_142 << 0 |
( V_143 << 8 ) |
( V_144 << 16 ) } ,
{ . type = V_140 ,
. V_141 =
V_148 << 0 |
( V_143 << 8 ) |
( V_194 << 16 ) } ,
{ . type = V_140 ,
. V_141 =
V_148 << 0 |
( V_143 << 8 ) |
( V_144 << 16 ) } ,
} ;
struct V_39 V_195 [] = {
{ . type = V_140 ,
. V_141 =
V_145 << 0 |
( V_143 << 8 ) |
( V_194 << 16 ) } ,
{ . type = V_140 ,
. V_141 =
V_145 << 0 |
( V_143 << 8 ) |
( V_144 << 16 ) } ,
{ . type = V_140 ,
. V_141 =
V_146 << 0 |
( V_143 << 8 ) |
( V_194 << 16 ) } ,
{ . type = V_140 ,
. V_141 =
V_146 << 0 |
( V_143 << 8 ) |
( V_144 << 16 ) } ,
{ . type = V_140 ,
. V_141 =
V_147 << 0 |
( V_143 << 8 ) |
( V_194 << 16 ) } ,
{ . type = V_140 ,
. V_141 =
V_147 << 0 |
( V_143 << 8 ) |
( V_144 << 16 ) } ,
} ;
struct V_39 V_196 [] = {
{ . type = V_140 ,
. V_141 =
V_142 << 0 |
( V_197 << 8 ) |
( V_194 << 16 ) } ,
{ . type = V_140 ,
. V_141 =
V_142 << 0 |
( V_197 << 8 ) |
( V_144 << 16 ) } ,
} ;
if ( V_166 )
return 0 ;
if ( ! V_13 -> V_198 ) {
if ( F_91 ( V_13 , V_180 ) < 0 )
return - 1 ;
}
if ( V_199 < 1 )
return 0 ;
if ( F_91 ( V_13 , V_193 ) < 0 )
return - 1 ;
if ( V_199 < 2 )
return 0 ;
if ( F_91 ( V_13 , V_195 ) < 0 )
return - 1 ;
if ( V_199 < 3 )
return 0 ;
return F_91 ( V_13 , V_196 ) ;
}
int F_92 ( int V_89 , const char * * V_90 , const char * V_79 V_109 )
{
bool V_200 = false ;
int V_201 = 0 ;
const char * V_202 = NULL ;
const struct V_175 V_203 [] = {
F_93 ( 'e' , L_59 , & V_13 , L_59 ,
L_60 ,
V_204 ) ,
F_93 ( 0 , L_61 , & V_13 , L_61 ,
L_62 , V_205 ) ,
F_94 ( 'i' , L_63 , & V_46 ,
L_64 ) ,
F_95 ( 'p' , L_65 , & V_11 . V_164 , L_65 ,
L_66 ) ,
F_95 ( 't' , L_67 , & V_11 . V_165 , L_67 ,
L_68 ) ,
F_94 ( 'a' , L_69 , & V_11 . V_206 ,
L_70 ) ,
F_94 ( 'g' , L_71 , & V_97 ,
L_72 ) ,
F_94 ( 'c' , L_73 , & V_41 , L_74 ) ,
F_96 ( 'v' , L_75 , & V_72 ,
L_76 ) ,
F_97 ( 'r' , L_77 , & V_117 ,
L_78 ) ,
F_94 ( 'n' , L_79 , & V_166 ,
L_80 ) ,
F_96 ( 'd' , L_81 , & V_199 ,
L_82 ) ,
F_94 ( 'S' , L_83 , & V_112 ,
L_84 ) ,
F_98 ( 'B' , L_85 , NULL , NULL ,
L_86 ,
F_86 ) ,
F_95 ( 'C' , L_87 , & V_11 . V_12 , L_87 ,
L_88 ) ,
F_99 ( 'A' , L_89 , & V_80 ,
L_90 , V_88 ) ,
F_95 ( 'x' , L_91 , & V_84 , L_92 ,
L_93 ) ,
F_93 ( 'G' , L_94 , & V_13 , L_95 ,
L_96 , V_207 ) ,
F_95 ( 'o' , L_97 , & V_202 , L_98 , L_99 ) ,
F_94 ( 0 , L_100 , & V_200 , L_101 ) ,
F_97 ( 0 , L_102 , & V_201 ,
L_103 ) ,
F_95 ( 0 , L_104 , & V_111 , L_105 ,
L_106 ) ,
F_95 ( 0 , L_107 , & V_113 , L_105 ,
L_108 ) ,
F_100 ( 'I' , L_109 , & V_96 ,
L_110 ) ,
F_99 ( 0 , L_111 , & V_80 ,
L_112 , V_86 ) ,
F_99 ( 0 , L_113 , & V_80 ,
L_114 , V_87 ) ,
F_101 ()
} ;
const char * const V_208 [] = {
L_115 ,
NULL
} ;
int V_94 = - V_17 , V_209 ;
const char * V_210 ;
setlocale ( V_211 , L_116 ) ;
V_13 = F_102 () ;
if ( V_13 == NULL )
return - V_17 ;
V_89 = F_103 ( V_89 , V_90 , V_203 , V_208 ,
V_212 ) ;
V_73 = V_213 ;
if ( V_202 && strcmp ( V_202 , L_117 ) )
V_73 = NULL ;
if ( V_202 && V_201 ) {
fprintf ( V_213 , L_118 ) ;
F_104 ( V_208 , V_203 ) ;
}
if ( V_201 < 0 ) {
fprintf ( V_213 , L_119 ) ;
F_104 ( V_208 , V_203 ) ;
}
if ( ! V_73 ) {
struct V_1 V_214 ;
V_210 = V_200 ? L_120 : L_121 ;
V_73 = fopen ( V_202 , V_210 ) ;
if ( ! V_73 ) {
perror ( L_122 ) ;
return - 1 ;
}
F_34 ( V_215 , & V_214 ) ;
fprintf ( V_73 , L_123 , ctime ( & V_214 . V_5 ) ) ;
} else if ( V_201 > 0 ) {
V_210 = V_200 ? L_120 : L_121 ;
V_73 = fdopen ( V_201 , V_210 ) ;
if ( ! V_73 ) {
perror ( L_124 ) ;
return - V_98 ;
}
}
if ( V_84 ) {
V_85 = true ;
if ( ! strcmp ( V_84 , L_125 ) )
V_84 = L_126 ;
} else
V_84 = V_216 ;
if ( V_85 ) {
if ( V_177 == 1 ) {
fprintf ( V_213 , L_127 ) ;
F_104 ( V_208 , V_203 ) ;
} else
V_136 = false ;
} else if ( V_177 == 0 )
V_136 = false ;
if ( ! V_89 && ! F_20 ( & V_11 ) )
F_104 ( V_208 , V_203 ) ;
if ( V_117 < 0 ) {
F_104 ( V_208 , V_203 ) ;
} else if ( V_117 == 0 ) {
V_217 = true ;
V_117 = 1 ;
}
if ( ( V_80 != V_81 || V_218 )
&& ! F_18 ( & V_11 ) ) {
fprintf ( V_213 , L_128
L_129 ) ;
F_104 ( V_208 , V_203 ) ;
return - 1 ;
}
if ( F_90 () )
goto V_219;
F_105 ( & V_11 ) ;
if ( F_106 ( V_13 , & V_11 ) < 0 ) {
if ( F_20 ( & V_11 ) )
F_107 ( L_130 ) ;
if ( F_18 ( & V_11 ) )
perror ( L_131 ) ;
F_104 ( V_208 , V_203 ) ;
return - 1 ;
}
if ( V_96 && V_96 < 100 ) {
F_107 ( L_132 ) ;
F_104 ( V_208 , V_203 ) ;
return - 1 ;
}
if ( F_13 ( V_13 , V_96 ) )
goto V_220;
if ( F_87 () )
goto V_219;
atexit ( F_81 ) ;
if ( ! V_217 )
signal ( V_221 , F_80 ) ;
signal ( V_171 , F_80 ) ;
signal ( V_222 , F_80 ) ;
signal ( V_223 , F_80 ) ;
V_94 = 0 ;
for ( V_209 = 0 ; V_217 || V_209 < V_117 ; V_209 ++ ) {
if ( V_117 != 1 && V_72 )
fprintf ( V_73 , L_133 ,
V_209 + 1 ) ;
V_94 = F_56 ( V_89 , V_90 ) ;
if ( V_217 && V_94 != - 1 ) {
F_79 ( V_89 , V_90 ) ;
F_15 ( V_13 ) ;
}
}
if ( ! V_217 && V_94 != - 1 && ! V_96 )
F_79 ( V_89 , V_90 ) ;
F_10 ( V_13 ) ;
V_220:
F_108 ( V_13 ) ;
V_219:
F_109 ( V_13 ) ;
return V_94 ;
}
