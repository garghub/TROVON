static inline void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( & V_4 -> V_5 , & V_2 -> V_6 ) ;
}
static inline bool F_3 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
enum V_11 V_12 = F_4 ( V_8 -> V_13 ) ;
if ( V_10 -> V_12 == V_12 )
return 1 ;
return 0 ;
}
static inline bool F_5 ( struct V_7 * V_8 ,
struct V_3 * V_4 )
{
enum V_11 V_12 = F_4 ( V_8 -> V_13 ) ;
int V_14 = F_6 ( V_8 -> V_13 ) ;
return ( V_12 == V_4 -> V_12 && V_14 == V_4 -> V_14 ) ;
}
static inline void F_7 ( struct V_3 * V_4 )
{
F_8 ( & V_4 -> V_5 ) ;
}
static struct V_3 *
F_9 ( const struct V_1 * V_2 , T_1 V_15 ,
enum V_11 V_12 , int V_14 )
{
struct V_3 * V_4 ;
F_10 (pn, &blkcg->policy_list, node) {
if ( V_4 -> V_15 == V_15 && V_4 -> V_12 == V_12 && V_4 -> V_14 == V_14 )
return V_4 ;
}
return NULL ;
}
struct V_1 * F_11 ( struct V_16 * V_16 )
{
return F_12 ( F_13 ( V_16 , V_17 ) ,
struct V_1 , V_18 ) ;
}
struct V_1 * F_14 ( struct V_19 * V_20 )
{
return F_12 ( F_15 ( V_20 , V_17 ) ,
struct V_1 , V_18 ) ;
}
static inline void
F_16 ( struct V_9 * V_10 , unsigned int V_21 )
{
struct V_22 * V_23 ;
F_10 (blkiop, &blkio_list, list) {
if ( V_23 -> V_12 != V_10 -> V_12 )
continue;
if ( V_23 -> V_24 . V_25 )
V_23 -> V_24 . V_25 ( V_10 -> V_26 ,
V_10 , V_21 ) ;
}
}
static inline void F_17 ( struct V_9 * V_10 , T_2 V_27 ,
int V_14 )
{
struct V_22 * V_23 ;
F_10 (blkiop, &blkio_list, list) {
if ( V_23 -> V_12 != V_10 -> V_12 )
continue;
if ( V_14 == V_28
&& V_23 -> V_24 . V_29 )
V_23 -> V_24 . V_29 ( V_10 -> V_26 ,
V_10 , V_27 ) ;
if ( V_14 == V_30
&& V_23 -> V_24 . V_31 )
V_23 -> V_24 . V_31 ( V_10 -> V_26 ,
V_10 , V_27 ) ;
}
}
static inline void F_18 ( struct V_9 * V_10 ,
unsigned int V_32 , int V_14 )
{
struct V_22 * V_23 ;
F_10 (blkiop, &blkio_list, list) {
if ( V_23 -> V_12 != V_10 -> V_12 )
continue;
if ( V_14 == V_33
&& V_23 -> V_24 . V_34 )
V_23 -> V_24 . V_34 ( V_10 -> V_26 ,
V_10 , V_32 ) ;
if ( V_14 == V_35
&& V_23 -> V_24 . V_36 )
V_23 -> V_24 . V_36 ( V_10 -> V_26 ,
V_10 , V_32 ) ;
}
}
static void F_19 ( T_3 * V_37 , T_3 V_38 , bool V_39 ,
bool V_40 )
{
if ( V_39 )
V_37 [ V_41 ] += V_38 ;
else
V_37 [ V_42 ] += V_38 ;
if ( V_40 )
V_37 [ V_43 ] += V_38 ;
else
V_37 [ V_44 ] += V_38 ;
}
static void F_20 ( T_3 * V_37 , bool V_39 , bool V_40 )
{
if ( V_39 ) {
F_21 ( V_37 [ V_41 ] == 0 ) ;
V_37 [ V_41 ] -- ;
} else {
F_21 ( V_37 [ V_42 ] == 0 ) ;
V_37 [ V_42 ] -- ;
}
if ( V_40 ) {
F_21 ( V_37 [ V_43 ] == 0 ) ;
V_37 [ V_43 ] -- ;
} else {
F_21 ( V_37 [ V_44 ] == 0 ) ;
V_37 [ V_44 ] -- ;
}
}
static void F_22 ( struct V_9 * V_10 ,
struct V_9 * V_45 )
{
if ( F_23 ( & V_10 -> V_46 ) )
return;
if ( V_10 == V_45 )
return;
V_10 -> V_46 . V_47 = F_24 () ;
F_25 ( & V_10 -> V_46 ) ;
}
static void F_26 ( struct V_48 * V_46 )
{
unsigned long long V_49 ;
if ( ! F_23 ( V_46 ) )
return;
V_49 = F_24 () ;
if ( F_27 ( V_49 , V_46 -> V_47 ) )
V_46 -> V_50 += V_49 - V_46 -> V_47 ;
F_28 ( V_46 ) ;
}
static void F_29 ( struct V_48 * V_46 )
{
unsigned long long V_49 ;
if ( ! F_30 ( V_46 ) )
return;
V_49 = F_24 () ;
if ( F_27 ( V_49 , V_46 -> V_51 ) )
V_46 -> V_52 += V_49 - V_46 -> V_51 ;
F_31 ( V_46 ) ;
}
void F_32 ( struct V_9 * V_10 )
{
unsigned long V_53 ;
F_33 ( & V_10 -> V_54 , V_53 ) ;
F_21 ( F_34 ( & V_10 -> V_46 ) ) ;
V_10 -> V_46 . V_55 = F_24 () ;
F_35 ( & V_10 -> V_46 ) ;
F_36 ( & V_10 -> V_54 , V_53 ) ;
}
void F_37 ( struct V_9 * V_10 )
{
unsigned long V_53 ;
unsigned long long V_49 ;
struct V_48 * V_46 ;
F_33 ( & V_10 -> V_54 , V_53 ) ;
V_46 = & V_10 -> V_46 ;
if ( F_34 ( V_46 ) ) {
V_49 = F_24 () ;
if ( F_27 ( V_49 , V_46 -> V_55 ) )
V_46 -> V_56 += V_49 - V_46 -> V_55 ;
F_38 ( V_46 ) ;
}
F_36 ( & V_10 -> V_54 , V_53 ) ;
}
void F_39 ( struct V_9 * V_10 )
{
unsigned long V_53 ;
struct V_48 * V_46 ;
F_33 ( & V_10 -> V_54 , V_53 ) ;
V_46 = & V_10 -> V_46 ;
V_46 -> V_57 +=
V_46 -> V_58 [ V_59 ] [ V_42 ] +
V_46 -> V_58 [ V_59 ] [ V_41 ] ;
V_46 -> V_60 ++ ;
F_26 ( V_46 ) ;
F_36 ( & V_10 -> V_54 , V_53 ) ;
}
void F_40 ( struct V_9 * V_10 )
{
unsigned long V_53 ;
struct V_48 * V_46 ;
F_33 ( & V_10 -> V_54 , V_53 ) ;
V_46 = & V_10 -> V_46 ;
if ( V_46 -> V_58 [ V_59 ] [ V_42 ] ||
V_46 -> V_58 [ V_59 ] [ V_41 ] ) {
F_36 ( & V_10 -> V_54 , V_53 ) ;
return;
}
if( F_30 ( V_46 ) ) {
F_36 ( & V_10 -> V_54 , V_53 ) ;
return;
}
V_46 -> V_51 = F_24 () ;
F_41 ( V_46 ) ;
F_36 ( & V_10 -> V_54 , V_53 ) ;
}
void F_42 ( struct V_9 * V_10 ,
unsigned long V_61 )
{
V_10 -> V_46 . V_61 += V_61 ;
}
static inline void F_22 ( struct V_9 * V_10 ,
struct V_9 * V_45 ) {}
static inline void F_29 ( struct V_48 * V_46 ) {}
void F_43 ( struct V_9 * V_10 ,
struct V_9 * V_45 , bool V_39 ,
bool V_40 )
{
unsigned long V_53 ;
F_33 ( & V_10 -> V_54 , V_53 ) ;
F_19 ( V_10 -> V_46 . V_58 [ V_59 ] , 1 , V_39 ,
V_40 ) ;
F_29 ( & V_10 -> V_46 ) ;
F_22 ( V_10 , V_45 ) ;
F_36 ( & V_10 -> V_54 , V_53 ) ;
}
void F_44 ( struct V_9 * V_10 ,
bool V_39 , bool V_40 )
{
unsigned long V_53 ;
F_33 ( & V_10 -> V_54 , V_53 ) ;
F_20 ( V_10 -> V_46 . V_58 [ V_59 ] ,
V_39 , V_40 ) ;
F_36 ( & V_10 -> V_54 , V_53 ) ;
}
void F_45 ( struct V_9 * V_10 , unsigned long time ,
unsigned long V_62 )
{
unsigned long V_53 ;
F_33 ( & V_10 -> V_54 , V_53 ) ;
V_10 -> V_46 . time += time ;
#ifdef F_46
V_10 -> V_46 . V_62 += V_62 ;
#endif
F_36 ( & V_10 -> V_54 , V_53 ) ;
}
void F_47 ( struct V_9 * V_10 ,
T_3 V_63 , bool V_39 , bool V_40 )
{
struct V_64 * V_65 ;
unsigned long V_53 ;
F_48 ( V_53 ) ;
V_65 = F_49 ( V_10 -> V_65 ) ;
F_50 ( & V_65 -> V_66 ) ;
V_65 -> V_67 += V_63 >> 9 ;
F_19 ( V_65 -> V_68 [ V_69 ] ,
1 , V_39 , V_40 ) ;
F_19 ( V_65 -> V_68 [ V_70 ] ,
V_63 , V_39 , V_40 ) ;
F_51 ( & V_65 -> V_66 ) ;
F_52 ( V_53 ) ;
}
void F_53 ( struct V_9 * V_10 ,
T_3 V_71 , T_3 V_72 , bool V_39 , bool V_40 )
{
struct V_48 * V_46 ;
unsigned long V_53 ;
unsigned long long V_49 = F_24 () ;
F_33 ( & V_10 -> V_54 , V_53 ) ;
V_46 = & V_10 -> V_46 ;
if ( F_27 ( V_49 , V_72 ) )
F_19 ( V_46 -> V_58 [ V_73 ] ,
V_49 - V_72 , V_39 , V_40 ) ;
if ( F_27 ( V_72 , V_71 ) )
F_19 ( V_46 -> V_58 [ V_74 ] ,
V_72 - V_71 , V_39 , V_40 ) ;
F_36 ( & V_10 -> V_54 , V_53 ) ;
}
void F_54 ( struct V_9 * V_10 , bool V_39 ,
bool V_40 )
{
struct V_64 * V_65 ;
unsigned long V_53 ;
F_48 ( V_53 ) ;
V_65 = F_49 ( V_10 -> V_65 ) ;
F_50 ( & V_65 -> V_66 ) ;
F_19 ( V_65 -> V_68 [ V_75 ] , 1 ,
V_39 , V_40 ) ;
F_51 ( & V_65 -> V_66 ) ;
F_52 ( V_53 ) ;
}
int F_55 ( struct V_9 * V_10 )
{
V_10 -> V_65 = F_56 ( struct V_64 ) ;
if ( ! V_10 -> V_65 )
return - V_76 ;
return 0 ;
}
void F_57 ( struct V_1 * V_2 ,
struct V_9 * V_10 , void * V_26 , T_1 V_15 ,
enum V_11 V_12 )
{
unsigned long V_53 ;
F_33 ( & V_2 -> V_77 , V_53 ) ;
F_58 ( & V_10 -> V_54 ) ;
F_59 ( V_10 -> V_26 , V_26 ) ;
V_10 -> V_78 = F_60 ( & V_2 -> V_18 ) ;
F_61 ( & V_10 -> V_79 , & V_2 -> V_80 ) ;
V_10 -> V_12 = V_12 ;
F_36 ( & V_2 -> V_77 , V_53 ) ;
F_62 ( V_2 -> V_18 . V_16 , V_10 -> V_81 , sizeof( V_10 -> V_81 ) ) ;
V_10 -> V_15 = V_15 ;
}
static void F_63 ( struct V_9 * V_10 )
{
F_64 ( & V_10 -> V_79 ) ;
V_10 -> V_78 = 0 ;
}
int F_65 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
unsigned long V_53 ;
struct F_13 * V_18 ;
int V_82 = 1 ;
F_66 () ;
V_18 = F_67 ( & V_83 , V_10 -> V_78 ) ;
if ( V_18 ) {
V_2 = F_12 ( V_18 , struct V_1 , V_18 ) ;
F_33 ( & V_2 -> V_77 , V_53 ) ;
if ( ! F_68 ( & V_10 -> V_79 ) ) {
F_63 ( V_10 ) ;
V_82 = 0 ;
}
F_36 ( & V_2 -> V_77 , V_53 ) ;
}
F_69 () ;
return V_82 ;
}
struct V_9 * F_70 ( struct V_1 * V_2 , void * V_26 )
{
struct V_9 * V_10 ;
struct V_84 * V_85 ;
void * V_86 ;
F_71 (blkg, n, &blkcg->blkg_list, blkcg_node) {
V_86 = V_10 -> V_26 ;
if ( V_86 == V_26 )
return V_10 ;
}
return NULL ;
}
static void F_72 ( struct V_9 * V_10 )
{
struct V_64 * V_65 ;
int V_87 , V_88 , V_89 ;
F_73 (i) {
V_65 = F_74 ( V_10 -> V_65 , V_87 ) ;
V_65 -> V_67 = 0 ;
for( V_88 = 0 ; V_88 < V_90 ; V_88 ++ )
for ( V_89 = 0 ; V_89 < V_91 ; V_89 ++ )
V_65 -> V_68 [ V_88 ] [ V_89 ] = 0 ;
}
}
static int
F_75 ( struct V_16 * V_16 , struct V_7 * V_7 , T_2 V_92 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
struct V_48 * V_46 ;
struct V_84 * V_85 ;
T_3 V_93 [ V_91 ] ;
int V_87 ;
#ifdef F_46
bool V_94 , V_95 , V_96 ;
unsigned long long V_49 = F_24 () ;
#endif
V_2 = F_11 ( V_16 ) ;
F_76 ( & V_2 -> V_77 ) ;
F_77 (blkg, n, &blkcg->blkg_list, blkcg_node) {
F_78 ( & V_10 -> V_54 ) ;
V_46 = & V_10 -> V_46 ;
#ifdef F_46
V_94 = F_34 ( V_46 ) ;
V_95 = F_23 ( V_46 ) ;
V_96 = F_30 ( V_46 ) ;
#endif
for ( V_87 = 0 ; V_87 < V_91 ; V_87 ++ )
V_93 [ V_87 ] = V_46 -> V_58 [ V_59 ] [ V_87 ] ;
memset ( V_46 , 0 , sizeof( struct V_48 ) ) ;
for ( V_87 = 0 ; V_87 < V_91 ; V_87 ++ )
V_46 -> V_58 [ V_59 ] [ V_87 ] = V_93 [ V_87 ] ;
#ifdef F_46
if ( V_94 ) {
F_35 ( V_46 ) ;
V_46 -> V_55 = V_49 ;
}
if ( V_95 ) {
F_25 ( V_46 ) ;
V_46 -> V_47 = V_49 ;
}
if ( V_96 ) {
F_41 ( V_46 ) ;
V_46 -> V_51 = V_49 ;
}
#endif
F_79 ( & V_10 -> V_54 ) ;
F_72 ( V_10 ) ;
}
F_80 ( & V_2 -> V_77 ) ;
return 0 ;
}
static void F_81 ( enum V_97 type , T_1 V_15 , char * V_98 ,
int V_99 , bool V_100 )
{
snprintf ( V_98 , V_99 , L_1 , F_82 ( V_15 ) , F_83 ( V_15 ) ) ;
V_99 -= strlen ( V_98 ) ;
if ( V_99 <= 0 ) {
F_84 ( V_101
L_2 ) ;
return;
}
if ( V_100 )
return;
switch ( type ) {
case V_42 :
F_85 ( V_98 , L_3 , V_99 ) ;
break;
case V_41 :
F_85 ( V_98 , L_4 , V_99 ) ;
break;
case V_43 :
F_85 ( V_98 , L_5 , V_99 ) ;
break;
case V_44 :
F_85 ( V_98 , L_6 , V_99 ) ;
break;
case V_91 :
F_85 ( V_98 , L_7 , V_99 ) ;
break;
default:
F_85 ( V_98 , L_8 , V_99 ) ;
}
}
static T_3 F_86 ( char * V_98 , int V_99 , T_3 V_92 ,
struct V_102 * V_103 , T_1 V_15 )
{
F_81 ( 0 , V_15 , V_98 , V_99 , true ) ;
V_103 -> V_104 ( V_103 , V_98 , V_92 ) ;
return V_92 ;
}
static T_3 F_87 ( struct V_9 * V_10 ,
enum V_105 type , enum V_97 V_106 )
{
int V_107 ;
struct V_64 * V_65 ;
T_2 V_92 = 0 , V_108 ;
F_73 (cpu) {
unsigned int V_109 ;
V_65 = F_74 ( V_10 -> V_65 , V_107 ) ;
do {
V_109 = F_88 ( & V_65 -> V_66 ) ;
if ( type == V_110 )
V_108 = V_65 -> V_67 ;
else
V_108 = V_65 -> V_68 [ type ] [ V_106 ] ;
} while( F_89 ( & V_65 -> V_66 , V_109 ) );
V_92 += V_108 ;
}
return V_92 ;
}
static T_3 F_90 ( struct V_9 * V_10 ,
struct V_102 * V_103 , T_1 V_15 , enum V_105 type )
{
T_3 V_111 , V_92 ;
char V_112 [ V_113 ] ;
enum V_97 V_106 ;
if ( type == V_110 ) {
V_92 = F_87 ( V_10 , type , 0 ) ;
return F_86 ( V_112 , V_113 - 1 , V_92 , V_103 , V_15 ) ;
}
for ( V_106 = V_42 ; V_106 < V_91 ;
V_106 ++ ) {
F_81 ( V_106 , V_15 , V_112 , V_113 , false ) ;
V_92 = F_87 ( V_10 , type , V_106 ) ;
V_103 -> V_104 ( V_103 , V_112 , V_92 ) ;
}
V_111 = F_87 ( V_10 , type , V_42 ) +
F_87 ( V_10 , type , V_41 ) ;
F_81 ( V_91 , V_15 , V_112 , V_113 , false ) ;
V_103 -> V_104 ( V_103 , V_112 , V_111 ) ;
return V_111 ;
}
static T_3 F_91 ( struct V_9 * V_10 ,
struct V_102 * V_103 , T_1 V_15 , enum V_114 type )
{
T_3 V_111 ;
char V_112 [ V_113 ] ;
enum V_97 V_106 ;
if ( type == V_115 )
return F_86 ( V_112 , V_113 - 1 ,
V_10 -> V_46 . time , V_103 , V_15 ) ;
#ifdef F_46
if ( type == V_116 )
return F_86 ( V_112 , V_113 - 1 ,
V_10 -> V_46 . V_62 , V_103 , V_15 ) ;
if ( type == V_117 ) {
T_3 V_118 = V_10 -> V_46 . V_57 ;
T_3 V_119 = V_10 -> V_46 . V_60 ;
if ( V_119 )
F_92 ( V_118 , V_119 ) ;
else
V_118 = 0 ;
return F_86 ( V_112 , V_113 - 1 , V_118 , V_103 , V_15 ) ;
}
if ( type == V_120 )
return F_86 ( V_112 , V_113 - 1 ,
V_10 -> V_46 . V_50 , V_103 , V_15 ) ;
if ( type == V_121 )
return F_86 ( V_112 , V_113 - 1 ,
V_10 -> V_46 . V_56 , V_103 , V_15 ) ;
if ( type == V_122 )
return F_86 ( V_112 , V_113 - 1 ,
V_10 -> V_46 . V_52 , V_103 , V_15 ) ;
if ( type == V_123 )
return F_86 ( V_112 , V_113 - 1 ,
V_10 -> V_46 . V_61 , V_103 , V_15 ) ;
#endif
for ( V_106 = V_42 ; V_106 < V_91 ;
V_106 ++ ) {
F_81 ( V_106 , V_15 , V_112 , V_113 , false ) ;
V_103 -> V_104 ( V_103 , V_112 , V_10 -> V_46 . V_58 [ type ] [ V_106 ] ) ;
}
V_111 = V_10 -> V_46 . V_58 [ type ] [ V_42 ] +
V_10 -> V_46 . V_58 [ type ] [ V_41 ] ;
F_81 ( V_91 , V_15 , V_112 , V_113 , false ) ;
V_103 -> V_104 ( V_103 , V_112 , V_111 ) ;
return V_111 ;
}
static int F_93 ( char * V_124 ,
struct V_3 * V_125 , enum V_11 V_12 , int V_14 )
{
struct V_126 * V_127 = NULL ;
char * V_128 [ 4 ] , * V_129 , * V_130 = NULL , * V_131 = NULL ;
unsigned long V_132 , V_133 ;
int V_87 = 0 , V_82 = - V_134 ;
int V_135 ;
T_1 V_15 ;
T_2 V_136 ;
memset ( V_128 , 0 , sizeof( V_128 ) ) ;
while ( ( V_129 = F_94 ( & V_124 , L_9 ) ) != NULL ) {
if ( ! * V_129 )
continue;
V_128 [ V_87 ++ ] = V_129 ;
if ( V_87 == 3 )
break;
}
if ( V_87 != 2 )
goto V_137;
V_129 = F_94 ( & V_128 [ 0 ] , L_10 ) ;
if ( V_129 != NULL )
V_130 = V_129 ;
else
goto V_137;
V_131 = V_128 [ 0 ] ;
if ( ! V_131 )
goto V_137;
if ( F_95 ( V_130 , 10 , & V_132 ) )
goto V_137;
if ( F_95 ( V_131 , 10 , & V_133 ) )
goto V_137;
V_15 = F_96 ( V_132 , V_133 ) ;
if ( F_97 ( V_128 [ 1 ] , 10 , & V_136 ) )
goto V_137;
if ( V_136 ) {
V_127 = F_98 ( V_15 , & V_135 ) ;
if ( ! V_127 || V_135 ) {
V_82 = - V_138 ;
goto V_137;
}
}
V_125 -> V_15 = V_15 ;
switch ( V_12 ) {
case V_139 :
if ( ( V_136 < V_140 && V_136 > 0 ) ||
V_136 > V_141 )
goto V_137;
V_125 -> V_12 = V_12 ;
V_125 -> V_14 = V_14 ;
V_125 -> V_92 . V_21 = V_136 ;
break;
case V_142 :
switch( V_14 ) {
case V_28 :
case V_30 :
V_125 -> V_12 = V_12 ;
V_125 -> V_14 = V_14 ;
V_125 -> V_92 . V_27 = V_136 ;
break;
case V_33 :
case V_35 :
if ( V_136 > V_143 )
goto V_137;
V_125 -> V_12 = V_12 ;
V_125 -> V_14 = V_14 ;
V_125 -> V_92 . V_32 = ( unsigned int ) V_136 ;
break;
}
break;
default:
F_99 () ;
}
V_82 = 0 ;
V_137:
F_100 ( V_127 ) ;
return V_82 ;
}
unsigned int F_101 ( struct V_1 * V_2 ,
T_1 V_15 )
{
struct V_3 * V_4 ;
unsigned long V_53 ;
unsigned int V_21 ;
F_33 ( & V_2 -> V_77 , V_53 ) ;
V_4 = F_9 ( V_2 , V_15 , V_139 ,
V_144 ) ;
if ( V_4 )
V_21 = V_4 -> V_92 . V_21 ;
else
V_21 = V_2 -> V_21 ;
F_36 ( & V_2 -> V_77 , V_53 ) ;
return V_21 ;
}
T_3 F_102 ( struct V_1 * V_2 , T_1 V_15 )
{
struct V_3 * V_4 ;
unsigned long V_53 ;
T_3 V_27 = - 1 ;
F_33 ( & V_2 -> V_77 , V_53 ) ;
V_4 = F_9 ( V_2 , V_15 , V_142 ,
V_28 ) ;
if ( V_4 )
V_27 = V_4 -> V_92 . V_27 ;
F_36 ( & V_2 -> V_77 , V_53 ) ;
return V_27 ;
}
T_3 F_103 ( struct V_1 * V_2 , T_1 V_15 )
{
struct V_3 * V_4 ;
unsigned long V_53 ;
T_3 V_27 = - 1 ;
F_33 ( & V_2 -> V_77 , V_53 ) ;
V_4 = F_9 ( V_2 , V_15 , V_142 ,
V_30 ) ;
if ( V_4 )
V_27 = V_4 -> V_92 . V_27 ;
F_36 ( & V_2 -> V_77 , V_53 ) ;
return V_27 ;
}
unsigned int F_104 ( struct V_1 * V_2 , T_1 V_15 )
{
struct V_3 * V_4 ;
unsigned long V_53 ;
unsigned int V_32 = - 1 ;
F_33 ( & V_2 -> V_77 , V_53 ) ;
V_4 = F_9 ( V_2 , V_15 , V_142 ,
V_33 ) ;
if ( V_4 )
V_32 = V_4 -> V_92 . V_32 ;
F_36 ( & V_2 -> V_77 , V_53 ) ;
return V_32 ;
}
unsigned int F_105 ( struct V_1 * V_2 , T_1 V_15 )
{
struct V_3 * V_4 ;
unsigned long V_53 ;
unsigned int V_32 = - 1 ;
F_33 ( & V_2 -> V_77 , V_53 ) ;
V_4 = F_9 ( V_2 , V_15 , V_142 ,
V_35 ) ;
if ( V_4 )
V_32 = V_4 -> V_92 . V_32 ;
F_36 ( & V_2 -> V_77 , V_53 ) ;
return V_32 ;
}
static bool F_106 ( struct V_3 * V_4 )
{
switch( V_4 -> V_12 ) {
case V_139 :
if ( V_4 -> V_92 . V_21 == 0 )
return 1 ;
break;
case V_142 :
switch( V_4 -> V_14 ) {
case V_28 :
case V_30 :
if ( V_4 -> V_92 . V_27 == 0 )
return 1 ;
break;
case V_33 :
case V_35 :
if ( V_4 -> V_92 . V_32 == 0 )
return 1 ;
}
break;
default:
F_99 () ;
}
return 0 ;
}
static void F_107 ( struct V_3 * V_145 ,
struct V_3 * V_125 )
{
switch( V_145 -> V_12 ) {
case V_139 :
V_145 -> V_92 . V_21 = V_125 -> V_92 . V_21 ;
break;
case V_142 :
switch( V_125 -> V_14 ) {
case V_28 :
case V_30 :
V_145 -> V_92 . V_27 = V_125 -> V_92 . V_27 ;
break;
case V_33 :
case V_35 :
V_145 -> V_92 . V_32 = V_125 -> V_92 . V_32 ;
}
break;
default:
F_99 () ;
}
}
static void F_108 ( struct V_1 * V_2 ,
struct V_9 * V_10 , struct V_3 * V_4 )
{
unsigned int V_21 , V_32 ;
T_2 V_27 ;
switch( V_4 -> V_12 ) {
case V_139 :
V_21 = V_4 -> V_92 . V_21 ? V_4 -> V_92 . V_21 :
V_2 -> V_21 ;
F_16 ( V_10 , V_21 ) ;
break;
case V_142 :
switch( V_4 -> V_14 ) {
case V_28 :
case V_30 :
V_27 = V_4 -> V_92 . V_27 ? V_4 -> V_92 . V_27 : ( - 1 ) ;
F_17 ( V_10 , V_27 , V_4 -> V_14 ) ;
break;
case V_33 :
case V_35 :
V_32 = V_4 -> V_92 . V_32 ? V_4 -> V_92 . V_32 : ( - 1 ) ;
F_18 ( V_10 , V_32 , V_4 -> V_14 ) ;
break;
}
break;
default:
F_99 () ;
}
}
static void F_109 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_9 * V_10 ;
struct V_84 * V_85 ;
F_78 ( & V_146 ) ;
F_76 ( & V_2 -> V_77 ) ;
F_77 (blkg, n, &blkcg->blkg_list, blkcg_node) {
if ( V_4 -> V_15 != V_10 -> V_15 || V_4 -> V_12 != V_10 -> V_12 )
continue;
F_108 ( V_2 , V_10 , V_4 ) ;
}
F_80 ( & V_2 -> V_77 ) ;
F_79 ( & V_146 ) ;
}
static int F_110 ( struct V_16 * V_147 , struct V_7 * V_8 ,
const char * V_148 )
{
int V_82 = 0 ;
char * V_124 ;
struct V_3 * V_125 , * V_4 ;
struct V_1 * V_2 ;
int V_149 = 0 ;
enum V_11 V_12 = F_4 ( V_8 -> V_13 ) ;
int V_14 = F_6 ( V_8 -> V_13 ) ;
V_124 = F_111 ( V_148 , V_150 ) ;
if ( ! V_124 )
return - V_76 ;
V_125 = F_112 ( sizeof( * V_125 ) , V_150 ) ;
if ( ! V_125 ) {
V_82 = - V_76 ;
goto V_151;
}
V_82 = F_93 ( V_124 , V_125 , V_12 , V_14 ) ;
if ( V_82 )
goto V_152;
V_2 = F_11 ( V_147 ) ;
F_76 ( & V_2 -> V_77 ) ;
V_4 = F_9 ( V_2 , V_125 -> V_15 , V_12 , V_14 ) ;
if ( ! V_4 ) {
if ( ! F_106 ( V_125 ) ) {
F_1 ( V_2 , V_125 ) ;
V_149 = 1 ;
}
F_80 ( & V_2 -> V_77 ) ;
goto V_153;
}
if ( F_106 ( V_125 ) ) {
F_7 ( V_4 ) ;
F_113 ( V_4 ) ;
F_80 ( & V_2 -> V_77 ) ;
goto V_153;
}
F_80 ( & V_2 -> V_77 ) ;
F_107 ( V_4 , V_125 ) ;
V_153:
F_109 ( V_2 , V_125 ) ;
V_152:
if ( ! V_149 )
F_113 ( V_125 ) ;
V_151:
F_113 ( V_124 ) ;
return V_82 ;
}
static void
F_114 ( struct V_154 * V_155 , struct V_3 * V_4 )
{
switch( V_4 -> V_12 ) {
case V_139 :
if ( V_4 -> V_14 == V_144 )
F_115 ( V_155 , L_11 , F_82 ( V_4 -> V_15 ) ,
F_83 ( V_4 -> V_15 ) , V_4 -> V_92 . V_21 ) ;
break;
case V_142 :
switch( V_4 -> V_14 ) {
case V_28 :
case V_30 :
F_115 ( V_155 , L_12 , F_82 ( V_4 -> V_15 ) ,
F_83 ( V_4 -> V_15 ) , V_4 -> V_92 . V_27 ) ;
break;
case V_33 :
case V_35 :
F_115 ( V_155 , L_11 , F_82 ( V_4 -> V_15 ) ,
F_83 ( V_4 -> V_15 ) , V_4 -> V_92 . V_32 ) ;
break;
}
break;
default:
F_99 () ;
}
}
static void F_116 ( struct V_7 * V_8 ,
struct V_1 * V_2 , struct V_154 * V_155 )
{
struct V_3 * V_4 ;
if ( ! F_117 ( & V_2 -> V_6 ) ) {
F_76 ( & V_2 -> V_77 ) ;
F_10 (pn, &blkcg->policy_list, node) {
if ( ! F_5 ( V_8 , V_4 ) )
continue;
F_114 ( V_155 , V_4 ) ;
}
F_80 ( & V_2 -> V_77 ) ;
}
}
static int F_118 ( struct V_16 * V_147 , struct V_7 * V_8 ,
struct V_154 * V_155 )
{
struct V_1 * V_2 ;
enum V_11 V_12 = F_4 ( V_8 -> V_13 ) ;
int V_156 = F_6 ( V_8 -> V_13 ) ;
V_2 = F_11 ( V_147 ) ;
switch( V_12 ) {
case V_139 :
switch( V_156 ) {
case V_144 :
F_116 ( V_8 , V_2 , V_155 ) ;
return 0 ;
default:
F_99 () ;
}
break;
case V_142 :
switch( V_156 ) {
case V_28 :
case V_30 :
case V_33 :
case V_35 :
F_116 ( V_8 , V_2 , V_155 ) ;
return 0 ;
default:
F_99 () ;
}
break;
default:
F_99 () ;
}
return 0 ;
}
static int F_119 ( struct V_1 * V_2 ,
struct V_7 * V_8 , struct V_102 * V_103 ,
enum V_114 type , bool V_157 , bool V_158 )
{
struct V_9 * V_10 ;
struct V_84 * V_85 ;
T_3 V_159 = 0 ;
F_66 () ;
F_71 (blkg, n, &blkcg->blkg_list, blkcg_node) {
if ( V_10 -> V_15 ) {
if ( ! F_3 ( V_8 , V_10 ) )
continue;
if ( V_158 )
V_159 += F_90 ( V_10 , V_103 ,
V_10 -> V_15 , type ) ;
else {
F_76 ( & V_10 -> V_54 ) ;
V_159 += F_91 ( V_10 , V_103 ,
V_10 -> V_15 , type ) ;
F_80 ( & V_10 -> V_54 ) ;
}
}
}
if ( V_157 )
V_103 -> V_104 ( V_103 , L_13 , V_159 ) ;
F_69 () ;
return 0 ;
}
static int F_120 ( struct V_16 * V_147 , struct V_7 * V_8 ,
struct V_102 * V_103 )
{
struct V_1 * V_2 ;
enum V_11 V_12 = F_4 ( V_8 -> V_13 ) ;
int V_156 = F_6 ( V_8 -> V_13 ) ;
V_2 = F_11 ( V_147 ) ;
switch( V_12 ) {
case V_139 :
switch( V_156 ) {
case V_160 :
return F_119 ( V_2 , V_8 , V_103 ,
V_115 , 0 , 0 ) ;
case V_161 :
return F_119 ( V_2 , V_8 , V_103 ,
V_110 , 0 , 1 ) ;
case V_162 :
return F_119 ( V_2 , V_8 , V_103 ,
V_70 , 1 , 1 ) ;
case V_163 :
return F_119 ( V_2 , V_8 , V_103 ,
V_69 , 1 , 1 ) ;
case V_164 :
return F_119 ( V_2 , V_8 , V_103 ,
V_73 , 1 , 0 ) ;
case V_165 :
return F_119 ( V_2 , V_8 , V_103 ,
V_74 , 1 , 0 ) ;
case V_166 :
return F_119 ( V_2 , V_8 , V_103 ,
V_75 , 1 , 1 ) ;
case V_167 :
return F_119 ( V_2 , V_8 , V_103 ,
V_59 , 1 , 0 ) ;
#ifdef F_46
case V_168 :
return F_119 ( V_2 , V_8 , V_103 ,
V_116 , 0 , 0 ) ;
case V_169 :
return F_119 ( V_2 , V_8 , V_103 ,
V_123 , 0 , 0 ) ;
case V_170 :
return F_119 ( V_2 , V_8 , V_103 ,
V_117 , 0 , 0 ) ;
case V_171 :
return F_119 ( V_2 , V_8 , V_103 ,
V_120 , 0 , 0 ) ;
case V_172 :
return F_119 ( V_2 , V_8 , V_103 ,
V_121 , 0 , 0 ) ;
case V_173 :
return F_119 ( V_2 , V_8 , V_103 ,
V_122 , 0 , 0 ) ;
#endif
default:
F_99 () ;
}
break;
case V_142 :
switch( V_156 ) {
case V_174 :
return F_119 ( V_2 , V_8 , V_103 ,
V_70 , 1 , 1 ) ;
case V_175 :
return F_119 ( V_2 , V_8 , V_103 ,
V_69 , 1 , 1 ) ;
default:
F_99 () ;
}
break;
default:
F_99 () ;
}
return 0 ;
}
static int F_121 ( struct V_1 * V_2 , T_2 V_92 )
{
struct V_9 * V_10 ;
struct V_84 * V_85 ;
struct V_3 * V_4 ;
if ( V_92 < V_140 || V_92 > V_141 )
return - V_134 ;
F_78 ( & V_146 ) ;
F_76 ( & V_2 -> V_77 ) ;
V_2 -> V_21 = ( unsigned int ) V_92 ;
F_77 (blkg, n, &blkcg->blkg_list, blkcg_node) {
V_4 = F_9 ( V_2 , V_10 -> V_15 ,
V_139 , V_144 ) ;
if ( V_4 )
continue;
F_16 ( V_10 , V_2 -> V_21 ) ;
}
F_80 ( & V_2 -> V_77 ) ;
F_79 ( & V_146 ) ;
return 0 ;
}
static T_2 F_122 ( struct V_16 * V_147 , struct V_7 * V_8 ) {
struct V_1 * V_2 ;
enum V_11 V_12 = F_4 ( V_8 -> V_13 ) ;
int V_156 = F_6 ( V_8 -> V_13 ) ;
V_2 = F_11 ( V_147 ) ;
switch( V_12 ) {
case V_139 :
switch( V_156 ) {
case V_176 :
return ( T_2 ) V_2 -> V_21 ;
}
break;
default:
F_99 () ;
}
return 0 ;
}
static int
F_123 ( struct V_16 * V_147 , struct V_7 * V_8 , T_2 V_92 )
{
struct V_1 * V_2 ;
enum V_11 V_12 = F_4 ( V_8 -> V_13 ) ;
int V_156 = F_6 ( V_8 -> V_13 ) ;
V_2 = F_11 ( V_147 ) ;
switch( V_12 ) {
case V_139 :
switch( V_156 ) {
case V_176 :
return F_121 ( V_2 , V_92 ) ;
}
break;
default:
F_99 () ;
}
return 0 ;
}
static int F_124 ( struct V_177 * V_178 , struct V_16 * V_16 )
{
return F_125 ( V_16 , V_178 , V_179 ,
F_126 ( V_179 ) ) ;
}
static void F_127 ( struct V_16 * V_16 )
{
struct V_1 * V_2 = F_11 ( V_16 ) ;
unsigned long V_53 ;
struct V_9 * V_10 ;
void * V_26 ;
struct V_22 * V_23 ;
struct V_3 * V_4 , * V_180 ;
F_66 () ;
do {
F_33 ( & V_2 -> V_77 , V_53 ) ;
if ( F_128 ( & V_2 -> V_80 ) ) {
F_36 ( & V_2 -> V_77 , V_53 ) ;
break;
}
V_10 = F_129 ( V_2 -> V_80 . V_181 , struct V_9 ,
V_79 ) ;
V_26 = F_130 ( V_10 -> V_26 ) ;
F_63 ( V_10 ) ;
F_36 ( & V_2 -> V_77 , V_53 ) ;
F_78 ( & V_146 ) ;
F_10 (blkiop, &blkio_list, list) {
if ( V_23 -> V_12 != V_10 -> V_12 )
continue;
V_23 -> V_24 . V_182 ( V_26 , V_10 ) ;
}
F_79 ( & V_146 ) ;
} while ( 1 );
F_131 (pn, pntmp, &blkcg->policy_list, node) {
F_7 ( V_4 ) ;
F_113 ( V_4 ) ;
}
F_132 ( & V_83 , & V_2 -> V_18 ) ;
F_69 () ;
if ( V_2 != & V_183 )
F_113 ( V_2 ) ;
}
static struct F_13 * F_133 ( struct V_16 * V_16 )
{
struct V_1 * V_2 ;
struct V_16 * V_184 = V_16 -> V_184 ;
if ( ! V_184 ) {
V_2 = & V_183 ;
goto V_185;
}
V_2 = F_112 ( sizeof( * V_2 ) , V_150 ) ;
if ( ! V_2 )
return F_134 ( - V_76 ) ;
V_2 -> V_21 = V_186 ;
V_185:
F_58 ( & V_2 -> V_77 ) ;
F_135 ( & V_2 -> V_80 ) ;
F_136 ( & V_2 -> V_6 ) ;
return & V_2 -> V_18 ;
}
static int F_137 ( struct V_16 * V_147 , struct V_187 * V_188 )
{
struct V_19 * V_189 ;
struct V_190 * V_191 ;
int V_82 = 0 ;
F_138 (task, cgrp, tset) {
F_139 ( V_189 ) ;
V_191 = V_189 -> V_190 ;
if ( V_191 && F_140 ( & V_191 -> V_192 ) > 1 )
V_82 = - V_134 ;
F_141 ( V_189 ) ;
if ( V_82 )
break;
}
return V_82 ;
}
static void F_142 ( struct V_16 * V_147 , struct V_187 * V_188 )
{
struct V_19 * V_189 ;
struct V_190 * V_191 ;
F_138 (task, cgrp, tset) {
V_191 = F_143 ( V_189 , V_193 , V_194 ) ;
if ( V_191 ) {
F_144 ( V_191 ) ;
F_145 ( V_191 ) ;
}
}
}
void F_146 ( struct V_22 * V_23 )
{
F_78 ( & V_146 ) ;
F_147 ( & V_23 -> V_195 , & V_196 ) ;
F_79 ( & V_146 ) ;
}
void F_148 ( struct V_22 * V_23 )
{
F_78 ( & V_146 ) ;
F_149 ( & V_23 -> V_195 ) ;
F_79 ( & V_146 ) ;
}
static int T_4 F_150 ( void )
{
return F_151 ( & V_83 ) ;
}
static void T_5 F_152 ( void )
{
F_153 ( & V_83 ) ;
}
