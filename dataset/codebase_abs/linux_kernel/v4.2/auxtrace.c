int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_5 , int V_6 )
{
struct V_7 * V_8 = V_5 ;
F_2 ( V_2 -> V_9 , L_1 ) ;
V_2 -> V_5 = V_5 ;
V_2 -> V_10 = V_4 -> V_10 ;
V_2 -> V_11 = V_4 -> V_11 ;
V_2 -> V_12 = 0 ;
V_2 -> V_13 = V_4 -> V_13 ;
V_2 -> V_14 = V_4 -> V_14 ;
V_2 -> V_15 = V_4 -> V_15 ;
if ( ! V_4 -> V_11 ) {
V_2 -> V_9 = NULL ;
return 0 ;
}
#if V_16 != 64 && ! F_3 ( V_17 )
F_4 ( L_2 ) ;
return - 1 ;
#endif
V_8 -> V_18 = V_4 -> V_19 ;
V_8 -> V_20 = V_4 -> V_11 ;
V_2 -> V_9 = F_5 ( NULL , V_4 -> V_11 , V_4 -> V_21 , V_22 , V_6 , V_4 -> V_19 ) ;
if ( V_2 -> V_9 == V_23 ) {
F_6 ( L_3 ) ;
V_2 -> V_9 = NULL ;
return - 1 ;
}
return 0 ;
}
void F_7 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 ) {
F_8 ( V_2 -> V_9 , V_2 -> V_11 ) ;
V_2 -> V_9 = NULL ;
}
}
void F_9 ( struct V_3 * V_4 ,
T_1 V_24 ,
unsigned int V_25 ,
bool V_26 )
{
if ( V_25 ) {
V_4 -> V_19 = V_24 ;
V_4 -> V_11 = V_25 * ( V_27 ) V_28 ;
V_4 -> V_10 = F_10 ( V_4 -> V_11 ) ? V_4 -> V_11 - 1 : 0 ;
V_4 -> V_21 = V_29 | ( V_26 ? 0 : V_30 ) ;
F_6 ( L_4 , V_4 -> V_11 ) ;
} else {
V_4 -> V_11 = 0 ;
}
}
void F_11 ( struct V_3 * V_4 ,
struct V_31 * V_32 , int V_13 ,
bool V_33 )
{
V_4 -> V_13 = V_13 ;
if ( V_33 ) {
V_4 -> V_15 = V_32 -> V_34 -> V_35 [ V_13 ] ;
if ( V_32 -> V_36 )
V_4 -> V_14 = F_12 ( V_32 -> V_36 , 0 ) ;
else
V_4 -> V_14 = - 1 ;
} else {
V_4 -> V_15 = - 1 ;
V_4 -> V_14 = F_12 ( V_32 -> V_36 , V_13 ) ;
}
}
static struct V_37 * F_13 ( unsigned int V_38 )
{
struct V_37 * V_39 ;
unsigned int V_40 , V_41 ;
V_40 = V_42 / sizeof( struct V_37 ) ;
if ( V_38 > V_40 )
return NULL ;
V_39 = calloc ( V_38 , sizeof( struct V_37 ) ) ;
if ( ! V_39 )
return NULL ;
for ( V_41 = 0 ; V_41 < V_38 ; V_41 ++ ) {
F_14 ( & V_39 [ V_41 ] . V_43 ) ;
V_39 [ V_41 ] . V_44 = NULL ;
}
return V_39 ;
}
int F_15 ( struct V_45 * V_46 )
{
V_46 -> V_38 = V_47 ;
V_46 -> V_39 = F_13 ( V_46 -> V_38 ) ;
if ( ! V_46 -> V_39 )
return - V_48 ;
return 0 ;
}
static int F_16 ( struct V_45 * V_46 ,
unsigned int V_49 )
{
unsigned int V_38 = V_46 -> V_38 ;
struct V_37 * V_39 ;
unsigned int V_41 ;
if ( ! V_38 )
V_38 = V_47 ;
while ( V_38 && V_38 < V_49 )
V_38 <<= 1 ;
if ( V_38 < V_46 -> V_38 || V_38 < V_49 )
return - V_50 ;
V_39 = F_13 ( V_38 ) ;
if ( ! V_39 )
return - V_48 ;
for ( V_41 = 0 ; V_41 < V_46 -> V_38 ; V_41 ++ ) {
F_17 ( & V_46 -> V_39 [ V_41 ] . V_43 ,
& V_39 [ V_41 ] . V_43 ) ;
V_39 [ V_41 ] . V_44 = V_46 -> V_39 [ V_41 ] . V_44 ;
}
V_46 -> V_38 = V_38 ;
V_46 -> V_39 = V_39 ;
return 0 ;
}
static void * F_18 ( T_2 V_51 , struct V_52 * V_53 )
{
int V_6 = F_19 ( V_53 -> V_54 ) ;
void * V_55 ;
T_3 V_56 ;
if ( V_51 > V_57 )
return NULL ;
V_55 = malloc ( V_51 ) ;
if ( ! V_55 )
return NULL ;
V_56 = F_20 ( V_6 , V_55 , V_51 ) ;
if ( V_56 != ( T_3 ) V_51 ) {
free ( V_55 ) ;
return NULL ;
}
return V_55 ;
}
static int F_21 ( struct V_45 * V_46 ,
unsigned int V_13 ,
struct V_58 * V_59 )
{
struct V_37 * V_60 ;
int V_61 ;
if ( V_13 >= V_46 -> V_38 ) {
V_61 = F_16 ( V_46 , V_13 + 1 ) ;
if ( V_61 )
return V_61 ;
}
V_60 = & V_46 -> V_39 [ V_13 ] ;
if ( ! V_60 -> V_62 ) {
V_60 -> V_62 = true ;
V_60 -> V_14 = V_59 -> V_14 ;
V_60 -> V_15 = V_59 -> V_15 ;
} else if ( V_59 -> V_15 != V_60 -> V_15 || V_59 -> V_14 != V_60 -> V_14 ) {
F_4 ( L_5 ,
V_60 -> V_15 , V_60 -> V_14 , V_59 -> V_15 , V_59 -> V_14 ) ;
return - V_50 ;
}
V_59 -> V_63 = V_46 -> V_64 ++ ;
F_22 ( & V_59 -> V_65 , & V_60 -> V_43 ) ;
V_46 -> V_66 = true ;
V_46 -> V_67 = true ;
return 0 ;
}
static int F_23 ( struct V_45 * V_46 ,
unsigned int V_13 ,
struct V_58 * V_59 )
{
T_2 V_68 = V_59 -> V_51 ;
bool V_69 = false ;
struct V_58 * V_70 ;
int V_61 ;
while ( V_68 > V_71 ) {
V_70 = F_24 ( V_59 , sizeof( struct V_58 ) ) ;
if ( ! V_70 )
return - V_48 ;
V_70 -> V_51 = V_71 ;
V_70 -> V_69 = V_69 ;
V_61 = F_21 ( V_46 , V_13 , V_70 ) ;
if ( V_61 ) {
F_25 ( V_70 ) ;
return V_61 ;
}
V_59 -> V_72 += V_71 ;
V_68 -= V_71 ;
V_69 = true ;
}
V_59 -> V_51 = V_68 ;
V_59 -> V_69 = V_69 ;
return 0 ;
}
static int F_26 ( struct V_45 * V_46 ,
struct V_52 * V_53 ,
unsigned int V_13 ,
struct V_58 * V_59 )
{
if ( V_53 -> V_73 ) {
V_59 -> V_74 = V_59 -> V_72 - V_53 -> V_75 +
V_53 -> V_76 ;
} else if ( F_27 ( V_53 -> V_54 ) ) {
V_59 -> V_74 = F_18 ( V_59 -> V_51 , V_53 ) ;
if ( ! V_59 -> V_74 )
return - V_48 ;
V_59 -> V_77 = true ;
} else if ( V_16 == 32 &&
V_59 -> V_51 > V_71 ) {
int V_61 ;
V_61 = F_23 ( V_46 , V_13 , V_59 ) ;
if ( V_61 )
return V_61 ;
}
return F_21 ( V_46 , V_13 , V_59 ) ;
}
int F_28 ( struct V_45 * V_46 ,
struct V_52 * V_53 ,
union V_78 * V_79 , T_1 V_72 ,
struct V_58 * * V_80 )
{
struct V_58 * V_59 ;
unsigned int V_13 ;
int V_61 ;
V_59 = F_29 ( sizeof( struct V_58 ) ) ;
if ( ! V_59 )
return - V_48 ;
V_59 -> V_81 = - 1 ;
V_59 -> V_14 = V_79 -> V_82 . V_14 ;
V_59 -> V_15 = V_79 -> V_82 . V_15 ;
V_59 -> V_72 = V_72 ;
V_59 -> V_19 = V_79 -> V_82 . V_19 ;
V_59 -> V_83 = V_79 -> V_82 . V_83 ;
V_59 -> V_51 = V_79 -> V_82 . V_51 ;
V_13 = V_79 -> V_82 . V_13 ;
V_61 = F_26 ( V_46 , V_53 , V_13 , V_59 ) ;
if ( V_61 )
goto V_84;
if ( V_80 )
* V_80 = V_59 ;
return 0 ;
V_84:
F_25 ( V_59 ) ;
return V_61 ;
}
static int F_30 ( struct V_45 * V_46 ,
struct V_52 * V_53 ,
T_1 V_85 , V_27 V_68 )
{
union V_78 * V_79 ;
int V_61 ;
char V_86 [ V_87 ] ;
V_61 = F_31 ( V_53 , V_85 , V_86 ,
V_87 , & V_79 , NULL ) ;
if ( V_61 )
return V_61 ;
if ( V_79 -> V_88 . type == V_89 ) {
if ( V_79 -> V_88 . V_51 < sizeof( struct V_90 ) ||
V_79 -> V_88 . V_51 != V_68 ) {
V_61 = - V_50 ;
goto V_91;
}
V_85 += V_79 -> V_88 . V_51 ;
V_61 = F_28 ( V_46 , V_53 , V_79 ,
V_85 , NULL ) ;
}
V_91:
return V_61 ;
}
void F_32 ( struct V_45 * V_46 )
{
unsigned int V_41 ;
for ( V_41 = 0 ; V_41 < V_46 -> V_38 ; V_41 ++ ) {
while ( ! F_33 ( & V_46 -> V_39 [ V_41 ] . V_43 ) ) {
struct V_58 * V_59 ;
V_59 = F_34 ( V_46 -> V_39 [ V_41 ] . V_43 . V_92 ,
struct V_58 , V_65 ) ;
F_35 ( & V_59 -> V_65 ) ;
F_25 ( V_59 ) ;
}
}
F_36 ( & V_46 -> V_39 ) ;
V_46 -> V_38 = 0 ;
}
static void F_37 ( struct V_93 * V_94 ,
unsigned int V_95 , unsigned int V_96 ,
T_2 V_97 )
{
unsigned int V_98 ;
while ( V_95 ) {
V_98 = ( V_95 - 1 ) >> 1 ;
if ( V_94 [ V_98 ] . V_97 <= V_97 )
break;
V_94 [ V_95 ] = V_94 [ V_98 ] ;
V_95 = V_98 ;
}
V_94 [ V_95 ] . V_96 = V_96 ;
V_94 [ V_95 ] . V_97 = V_97 ;
}
int F_38 ( struct V_99 * V_100 , unsigned int V_96 ,
T_2 V_97 )
{
struct V_93 * V_94 ;
if ( V_96 >= V_100 -> V_101 ) {
unsigned int V_101 = V_47 ;
while ( V_101 <= V_96 )
V_101 <<= 1 ;
V_94 = realloc ( V_100 -> V_94 ,
V_101 * sizeof( struct V_93 ) ) ;
if ( ! V_94 )
return - V_48 ;
V_100 -> V_94 = V_94 ;
V_100 -> V_101 = V_101 ;
}
F_37 ( V_100 -> V_94 , V_100 -> V_102 ++ , V_96 , V_97 ) ;
return 0 ;
}
void F_39 ( struct V_99 * V_100 )
{
F_36 ( & V_100 -> V_94 ) ;
V_100 -> V_102 = 0 ;
V_100 -> V_101 = 0 ;
}
void F_40 ( struct V_99 * V_100 )
{
unsigned int V_95 , V_103 , V_102 = V_100 -> V_102 ;
struct V_93 * V_94 ;
if ( ! V_102 )
return;
V_100 -> V_102 -= 1 ;
V_94 = V_100 -> V_94 ;
V_95 = 0 ;
while ( 1 ) {
unsigned int V_104 , V_105 ;
V_104 = ( V_95 << 1 ) + 1 ;
if ( V_104 >= V_102 )
break;
V_105 = V_104 + 1 ;
if ( V_105 >= V_102 ) {
V_94 [ V_95 ] = V_94 [ V_104 ] ;
return;
}
if ( V_94 [ V_104 ] . V_97 < V_94 [ V_105 ] . V_97 ) {
V_94 [ V_95 ] = V_94 [ V_104 ] ;
V_95 = V_104 ;
} else {
V_94 [ V_95 ] = V_94 [ V_105 ] ;
V_95 = V_105 ;
}
}
V_103 = V_102 - 1 ;
F_37 ( V_94 , V_95 , V_94 [ V_103 ] . V_96 ,
V_94 [ V_103 ] . V_97 ) ;
}
V_27 F_41 ( struct V_106 * V_107 )
{
if ( V_107 )
return V_107 -> V_108 ( V_107 ) ;
return 0 ;
}
static int F_42 ( void )
{
F_4 ( L_6 ) ;
return - V_50 ;
}
int F_43 ( struct V_106 * V_107 ,
struct V_52 * V_53 ,
struct V_109 * V_110 ,
V_27 V_111 )
{
if ( V_107 )
return V_107 -> V_112 ( V_107 , V_53 , V_110 , V_111 ) ;
return F_42 () ;
}
void F_44 ( struct V_106 * V_107 )
{
if ( V_107 )
V_107 -> free ( V_107 ) ;
}
int F_45 ( struct V_106 * V_107 )
{
if ( V_107 && V_107 -> V_113 )
return V_107 -> V_113 ( V_107 ) ;
return 0 ;
}
int F_46 ( struct V_106 * V_107 )
{
if ( V_107 && V_107 -> V_114 )
return V_107 -> V_114 ( V_107 ) ;
return 0 ;
}
int F_47 ( struct V_106 * V_107 , int V_13 ,
struct V_1 * V_2 ,
unsigned char * V_74 , T_2 * V_43 , T_2 * V_115 )
{
if ( V_107 && V_107 -> V_116 )
return V_107 -> V_116 ( V_107 , V_13 , V_2 , V_74 , V_43 , V_115 ) ;
return 0 ;
}
int F_48 ( struct V_106 * V_107 ,
struct V_31 * V_32 ,
struct V_117 * V_118 )
{
if ( V_107 )
return V_107 -> V_119 ( V_107 , V_32 , V_118 ) ;
return 0 ;
}
T_2 F_49 ( struct V_106 * V_107 )
{
if ( V_107 )
return V_107 -> V_83 ( V_107 ) ;
return 0 ;
}
int F_50 ( struct V_106 * V_107 ,
struct V_117 * V_118 , const char * V_120 )
{
if ( ! V_120 )
return 0 ;
if ( V_107 )
return V_107 -> V_121 ( V_107 , V_118 , V_120 ) ;
F_4 ( L_7 ) ;
return - V_50 ;
}
struct V_106 * __weak
F_51 ( struct V_31 * V_32 V_122 , int * V_61 )
{
* V_61 = 0 ;
return NULL ;
}
static int F_52 ( struct V_123 * V_43 )
{
struct V_124 * V_124 ;
V_124 = malloc ( sizeof( struct V_124 ) ) ;
if ( ! V_124 )
return - V_48 ;
V_124 -> V_125 = 0 ;
F_14 ( & V_124 -> V_65 ) ;
F_22 ( & V_124 -> V_65 , V_43 ) ;
return 0 ;
}
void F_53 ( struct V_123 * V_43 )
{
struct V_124 * V_124 , * V_126 ;
F_54 (auxtrace_index, n, head, list) {
F_35 ( & V_124 -> V_65 ) ;
free ( V_124 ) ;
}
}
static struct V_124 * F_55 ( struct V_123 * V_43 )
{
struct V_124 * V_124 ;
int V_61 ;
if ( F_33 ( V_43 ) ) {
V_61 = F_52 ( V_43 ) ;
if ( V_61 )
return NULL ;
}
V_124 = F_34 ( V_43 -> V_12 , struct V_124 , V_65 ) ;
if ( V_124 -> V_125 >= V_127 ) {
V_61 = F_52 ( V_43 ) ;
if ( V_61 )
return NULL ;
V_124 = F_34 ( V_43 -> V_12 , struct V_124 ,
V_65 ) ;
}
return V_124 ;
}
int F_56 ( struct V_123 * V_43 ,
union V_78 * V_79 , T_1 V_85 )
{
struct V_124 * V_124 ;
V_27 V_125 ;
V_124 = F_55 ( V_43 ) ;
if ( ! V_124 )
return - V_48 ;
V_125 = V_124 -> V_125 ;
V_124 -> V_128 [ V_125 ] . V_85 = V_85 ;
V_124 -> V_128 [ V_125 ] . V_68 = V_79 -> V_88 . V_51 ;
V_124 -> V_125 += 1 ;
return 0 ;
}
static int F_57 ( int V_6 ,
struct V_124 * V_124 )
{
struct V_129 V_130 ;
V_27 V_41 ;
for ( V_41 = 0 ; V_41 < V_124 -> V_125 ; V_41 ++ ) {
V_130 . V_85 = V_124 -> V_128 [ V_41 ] . V_85 ;
V_130 . V_68 = V_124 -> V_128 [ V_41 ] . V_68 ;
if ( F_58 ( V_6 , & V_130 , sizeof( V_130 ) ) != sizeof( V_130 ) )
return - V_131 ;
}
return 0 ;
}
int F_59 ( int V_6 , struct V_123 * V_43 )
{
struct V_124 * V_124 ;
T_2 V_132 = 0 ;
int V_61 ;
F_60 (auxtrace_index, head, list)
V_132 += V_124 -> V_125 ;
if ( F_58 ( V_6 , & V_132 , sizeof( V_132 ) ) != sizeof( V_132 ) )
return - V_131 ;
F_60 (auxtrace_index, head, list) {
V_61 = F_57 ( V_6 , V_124 ) ;
if ( V_61 )
return V_61 ;
}
return 0 ;
}
static int F_61 ( int V_6 , struct V_123 * V_43 ,
bool V_133 )
{
struct V_124 * V_124 ;
struct V_129 V_130 ;
V_27 V_125 ;
if ( F_20 ( V_6 , & V_130 , sizeof( V_130 ) ) != sizeof( V_130 ) )
return - 1 ;
V_124 = F_55 ( V_43 ) ;
if ( ! V_124 )
return - 1 ;
V_125 = V_124 -> V_125 ;
if ( V_133 ) {
V_124 -> V_128 [ V_125 ] . V_85 =
F_62 ( V_130 . V_85 ) ;
V_124 -> V_128 [ V_125 ] . V_68 = F_62 ( V_130 . V_68 ) ;
} else {
V_124 -> V_128 [ V_125 ] . V_85 = V_130 . V_85 ;
V_124 -> V_128 [ V_125 ] . V_68 = V_130 . V_68 ;
}
V_124 -> V_125 = V_125 + 1 ;
return 0 ;
}
int F_63 ( int V_6 , T_2 V_51 , struct V_52 * V_53 ,
bool V_133 )
{
struct V_123 * V_43 = & V_53 -> V_124 ;
T_2 V_125 ;
if ( F_20 ( V_6 , & V_125 , sizeof( T_2 ) ) != sizeof( T_2 ) )
return - 1 ;
if ( V_133 )
V_125 = F_62 ( V_125 ) ;
if ( sizeof( T_2 ) + V_125 * sizeof( struct V_129 ) > V_51 )
return - 1 ;
while ( V_125 -- ) {
int V_61 ;
V_61 = F_61 ( V_6 , V_43 , V_133 ) ;
if ( V_61 )
return - 1 ;
}
return 0 ;
}
static int F_64 ( struct V_45 * V_46 ,
struct V_52 * V_53 ,
struct V_129 * V_130 )
{
return F_30 ( V_46 , V_53 ,
V_130 -> V_85 , V_130 -> V_68 ) ;
}
int F_65 ( struct V_45 * V_46 ,
struct V_52 * V_53 )
{
struct V_124 * V_124 ;
struct V_129 * V_130 ;
V_27 V_41 ;
int V_61 ;
F_60 (auxtrace_index, &session->auxtrace_index, list) {
for ( V_41 = 0 ; V_41 < V_124 -> V_125 ; V_41 ++ ) {
V_130 = & V_124 -> V_128 [ V_41 ] ;
V_61 = F_64 ( V_46 ,
V_53 ,
V_130 ) ;
if ( V_61 )
return V_61 ;
}
}
return 0 ;
}
struct V_58 * F_66 ( struct V_37 * V_60 ,
struct V_58 * V_59 )
{
if ( V_59 ) {
if ( F_67 ( & V_59 -> V_65 , & V_60 -> V_43 ) )
return NULL ;
return F_34 ( V_59 -> V_65 . V_92 , struct V_58 ,
V_65 ) ;
} else {
if ( F_33 ( & V_60 -> V_43 ) )
return NULL ;
return F_34 ( V_60 -> V_43 . V_92 , struct V_58 ,
V_65 ) ;
}
}
void * F_68 ( struct V_58 * V_59 , int V_6 )
{
V_27 V_134 = V_59 -> V_72 & ( V_28 - 1 ) ;
V_27 V_51 = V_59 -> V_51 + V_134 ;
T_1 V_85 = V_59 -> V_72 - V_134 ;
void * V_135 ;
if ( V_59 -> V_74 )
return V_59 -> V_74 ;
V_135 = F_5 ( NULL , V_51 , V_29 , V_22 , V_6 , V_85 ) ;
if ( V_135 == V_23 )
return NULL ;
V_59 -> V_136 = V_135 ;
V_59 -> V_137 = V_51 ;
V_59 -> V_74 = V_135 + V_134 ;
return V_59 -> V_74 ;
}
void F_69 ( struct V_58 * V_59 )
{
if ( ! V_59 -> V_74 || ! V_59 -> V_136 )
return;
F_8 ( V_59 -> V_136 , V_59 -> V_137 ) ;
V_59 -> V_136 = NULL ;
V_59 -> V_137 = 0 ;
V_59 -> V_74 = NULL ;
V_59 -> V_138 = NULL ;
}
void F_70 ( struct V_58 * V_59 )
{
F_69 ( V_59 ) ;
if ( V_59 -> V_77 ) {
V_59 -> V_77 = false ;
F_36 ( & V_59 -> V_74 ) ;
V_59 -> V_138 = NULL ;
V_59 -> V_51 = 0 ;
}
}
void F_25 ( struct V_58 * V_59 )
{
F_70 ( V_59 ) ;
free ( V_59 ) ;
}
void F_71 ( struct V_139 * V_140 , int type ,
int V_141 , int V_15 , T_4 V_81 , T_4 V_14 , T_2 V_142 ,
const char * V_143 )
{
V_27 V_51 ;
memset ( V_140 , 0 , sizeof( struct V_139 ) ) ;
V_140 -> V_88 . type = V_144 ;
V_140 -> type = type ;
V_140 -> V_141 = V_141 ;
V_140 -> V_15 = V_15 ;
V_140 -> V_81 = V_81 ;
V_140 -> V_14 = V_14 ;
V_140 -> V_142 = V_142 ;
F_72 ( V_140 -> V_143 , V_143 , V_145 ) ;
V_51 = ( void * ) V_140 -> V_143 - ( void * ) V_140 +
strlen ( V_140 -> V_143 ) + 1 ;
V_140 -> V_88 . V_51 = F_73 ( V_51 , sizeof( T_2 ) ) ;
}
int F_74 ( struct V_106 * V_107 ,
struct V_146 * V_147 ,
struct V_52 * V_53 ,
T_5 V_148 )
{
union V_78 * V_149 ;
V_27 V_111 ;
int V_61 ;
F_6 ( L_8 ) ;
V_111 = F_41 ( V_107 ) ;
V_149 = F_29 ( sizeof( struct V_109 ) + V_111 ) ;
if ( ! V_149 )
return - V_48 ;
V_149 -> V_110 . V_88 . type = V_150 ;
V_149 -> V_110 . V_88 . V_51 = sizeof( struct V_109 ) +
V_111 ;
V_61 = F_43 ( V_107 , V_53 , & V_149 -> V_110 ,
V_111 ) ;
if ( V_61 )
goto V_151;
V_61 = V_148 ( V_147 , V_149 , NULL , NULL ) ;
V_151:
free ( V_149 ) ;
return V_61 ;
}
static bool F_75 ( struct V_52 * V_53 )
{
return ! V_53 -> V_152 ||
V_53 -> V_152 -> V_153 ;
}
int F_76 ( struct V_146 * V_147 V_122 ,
union V_78 * V_79 ,
struct V_52 * V_53 V_122 )
{
enum V_154 type = V_79 -> V_110 . type ;
if ( V_155 )
fprintf ( stdout , L_9 , type ) ;
switch ( type ) {
case V_156 :
default:
return - V_50 ;
}
}
T_6 F_77 ( struct V_146 * V_147 ,
union V_78 * V_79 ,
struct V_52 * V_53 )
{
T_6 V_61 ;
if ( V_155 )
fprintf ( stdout , L_10 V_157 L_11 V_157 L_12 V_157 L_13 ,
V_79 -> V_82 . V_51 , V_79 -> V_82 . V_19 ,
V_79 -> V_82 . V_83 , V_79 -> V_82 . V_13 ,
V_79 -> V_82 . V_14 , V_79 -> V_82 . V_15 ) ;
if ( F_75 ( V_53 ) )
return V_79 -> V_82 . V_51 ;
if ( ! V_53 -> V_82 || V_79 -> V_88 . type != V_89 )
return - V_50 ;
V_61 = V_53 -> V_82 -> V_158 ( V_53 , V_79 , V_147 ) ;
if ( V_61 < 0 )
return V_61 ;
return V_79 -> V_82 . V_51 ;
}
void F_78 ( struct V_152 * V_159 )
{
V_159 -> V_160 = true ;
V_159 -> V_161 = true ;
V_159 -> V_162 = true ;
V_159 -> V_163 = true ;
V_159 -> V_164 = V_165 ;
V_159 -> V_166 = V_167 ;
V_159 -> V_168 = V_169 ;
}
int F_79 ( const struct V_170 * V_171 , const char * V_120 ,
int V_172 )
{
struct V_152 * V_159 = V_171 -> V_173 ;
const char * V_55 ;
char * V_174 ;
V_159 -> V_62 = true ;
if ( V_172 ) {
V_159 -> V_153 = true ;
return 0 ;
}
if ( ! V_120 ) {
F_78 ( V_159 ) ;
return 0 ;
}
for ( V_55 = V_120 ; * V_55 ; ) {
switch ( * V_55 ++ ) {
case 'i' :
V_159 -> V_160 = true ;
while ( * V_55 == ' ' || * V_55 == ',' )
V_55 += 1 ;
if ( isdigit ( * V_55 ) ) {
V_159 -> V_166 = F_80 ( V_55 , & V_174 , 10 ) ;
V_55 = V_174 ;
while ( * V_55 == ' ' || * V_55 == ',' )
V_55 += 1 ;
switch ( * V_55 ++ ) {
case 'i' :
V_159 -> V_164 =
V_175 ;
break;
case 't' :
V_159 -> V_164 =
V_176 ;
break;
case 'm' :
V_159 -> V_166 *= 1000 ;
case 'u' :
V_159 -> V_166 *= 1000 ;
case 'n' :
if ( * V_55 ++ != 's' )
goto V_84;
V_159 -> V_164 =
V_177 ;
break;
case '\0' :
goto V_91;
default:
goto V_84;
}
}
break;
case 'b' :
V_159 -> V_161 = true ;
break;
case 'x' :
V_159 -> V_162 = true ;
break;
case 'e' :
V_159 -> V_163 = true ;
break;
case 'd' :
V_159 -> log = true ;
break;
case 'c' :
V_159 -> V_161 = true ;
V_159 -> V_178 = true ;
break;
case 'r' :
V_159 -> V_161 = true ;
V_159 -> V_179 = true ;
break;
case 'g' :
V_159 -> V_180 = true ;
V_159 -> V_168 =
V_169 ;
while ( * V_55 == ' ' || * V_55 == ',' )
V_55 += 1 ;
if ( isdigit ( * V_55 ) ) {
unsigned int V_181 ;
V_181 = strtoul ( V_55 , & V_174 , 10 ) ;
V_55 = V_174 ;
if ( ! V_181 || V_181 > V_182 )
goto V_84;
V_159 -> V_168 = V_181 ;
}
break;
case ' ' :
case ',' :
break;
default:
goto V_84;
}
}
V_91:
if ( V_159 -> V_160 ) {
if ( ! V_159 -> V_164 )
V_159 -> V_164 =
V_165 ;
if ( ! V_159 -> V_166 )
V_159 -> V_166 = V_167 ;
}
return 0 ;
V_84:
F_4 ( L_14 , V_120 ) ;
return - V_50 ;
}
static const char * F_81 ( int type )
{
const char * V_183 = NULL ;
if ( type < V_184 )
V_183 = V_185 [ type ] ;
if ( ! V_183 )
V_183 = L_15 ;
return V_183 ;
}
V_27 F_82 ( union V_78 * V_79 , T_7 * V_186 )
{
struct V_139 * V_187 = & V_79 -> V_140 ;
int V_56 ;
V_56 = fprintf ( V_186 , L_16 ,
F_81 ( V_187 -> type ) , V_187 -> type ) ;
V_56 += fprintf ( V_186 , L_17 V_157 L_18 ,
V_187 -> V_15 , V_187 -> V_81 , V_187 -> V_14 , V_187 -> V_142 , V_187 -> V_141 , V_187 -> V_143 ) ;
return V_56 ;
}
void F_83 ( struct V_52 * V_53 ,
union V_78 * V_79 )
{
struct V_139 * V_187 = & V_79 -> V_140 ;
if ( V_187 -> type < V_184 )
V_53 -> V_32 -> V_188 . V_189 [ V_187 -> type ] += 1 ;
}
void F_84 ( const struct V_190 * V_188 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_184 ; V_41 ++ ) {
if ( ! V_188 -> V_189 [ V_41 ] )
continue;
F_85 ( L_19 ,
V_188 -> V_189 [ V_41 ] ,
F_81 ( V_41 ) ) ;
}
}
int F_86 ( struct V_146 * V_147 V_122 ,
union V_78 * V_79 ,
struct V_52 * V_53 )
{
if ( F_75 ( V_53 ) )
return 0 ;
F_82 ( V_79 , stdout ) ;
return 0 ;
}
static int F_87 ( struct V_1 * V_2 ,
struct V_106 * V_107 ,
struct V_146 * V_147 , T_8 V_191 ,
bool V_192 , V_27 V_193 )
{
T_2 V_43 , V_115 = V_2 -> V_12 , V_19 , V_194 ;
unsigned char * V_74 = V_2 -> V_9 ;
V_27 V_51 , V_195 , V_196 , V_197 , V_198 , V_199 ;
union V_78 V_149 ;
void * V_200 , * V_201 ;
if ( V_192 ) {
V_43 = F_88 ( V_2 ) ;
if ( F_47 ( V_107 , V_2 -> V_13 , V_2 , V_74 ,
& V_43 , & V_115 ) )
return - 1 ;
} else {
V_43 = F_89 ( V_2 ) ;
}
if ( V_115 == V_43 )
return 0 ;
F_90 ( L_20 V_157 L_21 V_157 L_22 V_157 L_23 ,
V_2 -> V_13 , V_115 , V_43 , V_43 - V_115 ) ;
if ( V_2 -> V_10 ) {
V_195 = V_43 & V_2 -> V_10 ;
V_196 = V_115 & V_2 -> V_10 ;
} else {
V_195 = V_43 % V_2 -> V_11 ;
V_196 = V_115 % V_2 -> V_11 ;
}
if ( V_195 > V_196 )
V_51 = V_195 - V_196 ;
else
V_51 = V_2 -> V_11 - ( V_196 - V_195 ) ;
if ( V_192 && V_51 > V_193 )
V_51 = V_193 ;
V_194 = F_49 ( V_107 ) ;
if ( V_43 > V_115 || V_51 <= V_43 || V_2 -> V_10 ) {
V_19 = V_43 - V_51 ;
} else {
T_2 V_202 = ( 0ULL - V_2 -> V_11 ) % V_2 -> V_11 ;
V_19 = V_43 - V_51 - V_202 ;
}
if ( V_51 > V_195 ) {
V_197 = V_51 - V_195 ;
V_200 = & V_74 [ V_2 -> V_11 - V_197 ] ;
V_198 = V_195 ;
V_201 = & V_74 [ 0 ] ;
} else {
V_197 = V_51 ;
V_200 = & V_74 [ V_195 - V_197 ] ;
V_198 = 0 ;
V_201 = NULL ;
}
if ( V_107 -> V_203 ) {
unsigned int V_204 = V_197 % V_107 -> V_203 ;
V_197 -= V_204 ;
V_51 -= V_204 ;
}
V_199 = V_51 & 7 ;
if ( V_199 )
V_199 = 8 - V_199 ;
memset ( & V_149 , 0 , sizeof( V_149 ) ) ;
V_149 . V_82 . V_88 . type = V_89 ;
V_149 . V_82 . V_88 . V_51 = sizeof( V_149 . V_82 ) ;
V_149 . V_82 . V_51 = V_51 + V_199 ;
V_149 . V_82 . V_19 = V_19 ;
V_149 . V_82 . V_83 = V_194 ;
V_149 . V_82 . V_13 = V_2 -> V_13 ;
V_149 . V_82 . V_14 = V_2 -> V_14 ;
V_149 . V_82 . V_15 = V_2 -> V_15 ;
if ( V_191 ( V_147 , & V_149 , V_200 , V_197 , V_201 , V_198 ) )
return - 1 ;
V_2 -> V_12 = V_43 ;
if ( ! V_192 ) {
F_91 ( V_2 , V_43 ) ;
if ( V_107 -> V_205 ) {
int V_61 ;
V_61 = V_107 -> V_205 ( V_107 , V_2 -> V_13 ) ;
if ( V_61 < 0 )
return V_61 ;
}
}
return 1 ;
}
int F_92 ( struct V_1 * V_2 , struct V_106 * V_107 ,
struct V_146 * V_147 , T_8 V_191 )
{
return F_87 ( V_2 , V_107 , V_147 , V_191 , false , 0 ) ;
}
int F_93 ( struct V_1 * V_2 ,
struct V_106 * V_107 ,
struct V_146 * V_147 , T_8 V_191 ,
V_27 V_193 )
{
return F_87 ( V_2 , V_107 , V_147 , V_191 , true , V_193 ) ;
}
struct V_206 * F_94 ( unsigned int V_207 , V_27 V_208 ,
unsigned int V_209 )
{
struct V_206 * V_210 ;
struct V_211 * V_212 ;
V_27 V_68 , V_41 ;
V_210 = F_29 ( sizeof( struct V_206 ) ) ;
if ( ! V_210 )
return NULL ;
V_68 = 1UL << V_207 ;
V_212 = calloc ( V_68 , sizeof( struct V_211 ) ) ;
if ( ! V_212 )
goto V_151;
for ( V_41 = 0 ; V_41 < V_68 ; V_41 ++ )
F_95 ( & V_212 [ V_41 ] ) ;
V_210 -> V_213 = V_212 ;
V_210 -> V_68 = V_68 ;
V_210 -> V_208 = V_208 ;
V_210 -> V_214 = ( V_210 -> V_68 * V_209 ) / 100 ;
V_210 -> V_207 = V_207 ;
return V_210 ;
V_151:
free ( V_210 ) ;
return NULL ;
}
static void F_96 ( struct V_206 * V_210 )
{
struct V_215 * V_216 ;
struct V_217 * V_218 ;
V_27 V_41 ;
if ( ! V_210 )
return;
for ( V_41 = 0 ; V_41 < V_210 -> V_68 ; V_41 ++ ) {
F_97 (entry, tmp, &c->hashtable[i], hash) {
F_98 ( & V_216 -> V_219 ) ;
F_99 ( V_210 , V_216 ) ;
}
}
V_210 -> V_220 = 0 ;
}
void F_100 ( struct V_206 * V_210 )
{
if ( ! V_210 )
return;
F_96 ( V_210 ) ;
free ( V_210 -> V_213 ) ;
free ( V_210 ) ;
}
void * F_101 ( struct V_206 * V_210 )
{
return malloc ( V_210 -> V_208 ) ;
}
void F_99 ( struct V_206 * V_210 V_122 ,
void * V_216 )
{
free ( V_216 ) ;
}
int F_102 ( struct V_206 * V_210 , T_9 V_221 ,
struct V_215 * V_216 )
{
if ( V_210 -> V_214 && ++ V_210 -> V_220 > V_210 -> V_214 )
F_96 ( V_210 ) ;
V_216 -> V_221 = V_221 ;
F_103 ( & V_216 -> V_219 , & V_210 -> V_213 [ F_104 ( V_221 , V_210 -> V_207 ) ] ) ;
return 0 ;
}
void * F_105 ( struct V_206 * V_210 , T_9 V_221 )
{
struct V_215 * V_216 ;
struct V_211 * V_222 ;
if ( ! V_210 )
return NULL ;
V_222 = & V_210 -> V_213 [ F_104 ( V_221 , V_210 -> V_207 ) ] ;
F_106 (entry, hlist, hash) {
if ( V_216 -> V_221 == V_221 )
return V_216 ;
}
return NULL ;
}
