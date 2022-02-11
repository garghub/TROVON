static void * F_1 ( struct V_1 * V_2 , void * V_3 , T_1 * V_4 )
{
return F_2 ( V_3 , & V_5 , V_4 ) ;
}
static void * F_3 ( struct V_1 * V_2 , T_1 * V_4 )
{
return F_4 ( & V_5 , * V_4 ) ;
}
static void F_5 ( struct V_1 * V_2 , void * V_3 )
{
}
static void F_6 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
char V_8 [ 128 ] ;
const char * V_9 = V_7 -> V_9 ;
if ( ! V_9 ) {
V_9 = F_7 ( V_7 -> V_10 , V_8 ) ;
F_8 ( V_2 , L_1 , V_9 ) ;
} else{
F_8 ( V_2 , L_1 , V_9 ) ;
if ( V_7 -> V_11 > 1 )
F_8 ( V_2 , L_2 , V_7 -> V_11 ) ;
if ( V_7 -> V_12 )
F_8 ( V_2 , L_3 , V_7 -> V_12 ) ;
}
}
static int F_9 ( struct V_1 * V_2 , void * V_3 )
{
struct V_6 * V_7 = F_10 ( V_3 , struct V_6 , V_13 ) ;
struct V_14 * V_15 ;
char V_16 [ V_17 ] ;
if ( V_3 == & V_5 ) {
F_8 ( V_2 , L_4 ) ;
return 0 ;
}
F_8 ( V_2 , L_5 , V_7 -> V_10 ) ;
#ifdef F_11
F_8 ( V_2 , L_6 , V_7 -> V_18 ) ;
#endif
#ifdef F_12
F_8 ( V_2 , L_7 , F_13 ( V_7 ) ) ;
F_8 ( V_2 , L_8 , F_14 ( V_7 ) ) ;
#endif
F_15 ( V_7 , V_16 ) ;
F_8 ( V_2 , L_9 , V_16 ) ;
F_8 ( V_2 , L_10 ) ;
F_6 ( V_2 , V_7 ) ;
F_16 ( V_2 , L_11 ) ;
F_17 (entry, &class->locks_after, entry) {
if ( V_15 -> V_19 == 1 ) {
F_8 ( V_2 , L_12 , V_15 -> V_7 -> V_10 ) ;
F_6 ( V_2 , V_15 -> V_7 ) ;
F_16 ( V_2 , L_11 ) ;
}
}
F_16 ( V_2 , L_11 ) ;
return 0 ;
}
static int F_18 ( struct V_20 * V_20 , struct V_21 * V_21 )
{
return F_19 ( V_21 , & V_22 ) ;
}
static void * F_20 ( struct V_1 * V_2 , T_1 * V_4 )
{
if ( * V_4 == 0 )
return V_23 ;
if ( * V_4 - 1 < V_24 )
return V_25 + ( * V_4 - 1 ) ;
return NULL ;
}
static void * F_21 ( struct V_1 * V_2 , void * V_3 , T_1 * V_4 )
{
( * V_4 ) ++ ;
return F_20 ( V_2 , V_4 ) ;
}
static void F_22 ( struct V_1 * V_2 , void * V_3 )
{
}
static int F_23 ( struct V_1 * V_2 , void * V_3 )
{
struct V_26 * V_27 = V_3 ;
struct V_6 * V_7 ;
int V_28 ;
if ( V_3 == V_23 ) {
F_8 ( V_2 , L_13 ) ;
return 0 ;
}
F_8 ( V_2 , L_14 , V_27 -> V_29 ) ;
for ( V_28 = 0 ; V_28 < V_27 -> V_30 ; V_28 ++ ) {
V_7 = F_24 ( V_27 , V_28 ) ;
if ( ! V_7 -> V_10 )
continue;
F_8 ( V_2 , L_15 , V_7 -> V_10 ) ;
F_6 ( V_2 , V_7 ) ;
F_16 ( V_2 , L_11 ) ;
}
F_16 ( V_2 , L_11 ) ;
return 0 ;
}
static int F_25 ( struct V_20 * V_20 , struct V_21 * V_21 )
{
return F_19 ( V_21 , & V_31 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
#ifdef F_11
unsigned long long V_32 = F_27 ( V_33 ) ,
V_34 = F_27 ( V_35 ) ,
V_36 = F_27 ( V_37 ) ,
V_38 = F_27 ( V_39 ) ,
V_40 = F_27 ( V_41 ) ,
V_42 = F_27 ( V_43 ) ,
V_44 = F_27 ( V_45 ) ,
V_46 = F_27 ( V_47 ) ;
F_8 ( V_2 , L_16 ,
F_27 ( V_48 ) ) ;
F_8 ( V_2 , L_17 ,
F_27 ( V_49 ) ) ;
F_8 ( V_2 , L_18 ,
F_27 ( V_50 ) ) ;
F_8 ( V_2 , L_19 ,
F_27 ( V_51 ) ) ;
F_8 ( V_2 , L_20 ,
F_27 ( V_52 ) ) ;
F_8 ( V_2 , L_21 , V_32 ) ;
F_8 ( V_2 , L_22 , V_34 ) ;
F_8 ( V_2 , L_23 , V_36 ) ;
F_8 ( V_2 , L_24 , V_38 ) ;
F_8 ( V_2 , L_25 , V_40 ) ;
F_8 ( V_2 , L_26 , V_42 ) ;
F_8 ( V_2 , L_27 , V_44 ) ;
F_8 ( V_2 , L_28 , V_46 ) ;
#endif
}
static int F_28 ( struct V_1 * V_2 , void * V_3 )
{
struct V_6 * V_7 ;
unsigned long V_53 = 0 , V_54 = 0 ,
V_55 = 0 , V_56 = 0 ,
V_57 = 0 , V_58 = 0 ,
V_59 = 0 , V_60 = 0 ,
V_61 = 0 , V_62 = 0 ,
V_63 = 0 , V_64 = 0 ,
V_65 = 0 , V_66 = 0 ,
V_67 = 0 ;
F_17 (class, &all_lock_classes, lock_entry) {
if ( V_7 -> V_68 == 0 )
V_53 ++ ;
if ( V_7 -> V_68 == V_69 )
V_54 ++ ;
if ( V_7 -> V_68 & V_70 )
V_55 ++ ;
if ( V_7 -> V_68 & V_71 )
V_56 ++ ;
if ( V_7 -> V_68 & V_72 )
V_57 ++ ;
if ( V_7 -> V_68 & V_73 )
V_58 ++ ;
if ( V_7 -> V_68 & V_74 )
V_59 ++ ;
if ( V_7 -> V_68 & V_75 )
V_60 ++ ;
if ( V_7 -> V_68 & V_76 )
V_61 ++ ;
if ( V_7 -> V_68 & V_77 )
V_62 ++ ;
if ( V_7 -> V_68 & V_78 )
V_63 ++ ;
if ( V_7 -> V_68 & V_79 )
V_64 ++ ;
if ( V_7 -> V_68 & V_80 )
V_65 ++ ;
if ( V_7 -> V_68 & V_81 )
V_66 ++ ;
#ifdef F_12
V_67 += F_13 ( V_7 ) ;
#endif
}
#ifdef F_11
F_29 ( F_27 ( V_82 ) != V_53 ) ;
#endif
F_8 ( V_2 , L_29 ,
V_83 , V_84 ) ;
F_8 ( V_2 , L_30 ,
V_85 , V_86 ) ;
F_8 ( V_2 , L_31 ,
V_67 ) ;
F_8 ( V_2 , L_32 ,
V_56 * V_55 +
V_60 * V_59 +
V_85 ) ;
#ifdef F_12
F_8 ( V_2 , L_33 ,
V_24 , V_87 ) ;
F_8 ( V_2 , L_34 ,
V_88 , V_89 ) ;
#endif
#ifdef F_30
F_8 ( V_2 , L_35 ,
V_90 ) ;
F_8 ( V_2 , L_36 ,
V_91 ) ;
#endif
F_8 ( V_2 , L_37 ,
V_92 ) ;
F_8 ( V_2 , L_38 ,
V_93 , V_94 ) ;
F_8 ( V_2 , L_39 ,
( V_90 + 1 ) *
( V_91 + 1 ) *
( V_92 + 1 )
) ;
F_8 ( V_2 , L_40 ,
V_59 ) ;
F_8 ( V_2 , L_41 ,
V_60 ) ;
F_8 ( V_2 , L_42 ,
V_57 ) ;
F_8 ( V_2 , L_43 ,
V_58 ) ;
F_8 ( V_2 , L_44 ,
V_55 ) ;
F_8 ( V_2 , L_45 ,
V_56 ) ;
F_8 ( V_2 , L_46 ,
V_65 ) ;
F_8 ( V_2 , L_47 ,
V_66 ) ;
F_8 ( V_2 , L_48 ,
V_63 ) ;
F_8 ( V_2 , L_49 ,
V_64 ) ;
F_8 ( V_2 , L_50 ,
V_61 ) ;
F_8 ( V_2 , L_51 ,
V_62 ) ;
F_8 ( V_2 , L_52 ,
V_54 ) ;
F_8 ( V_2 , L_53 ,
V_53 ) ;
F_8 ( V_2 , L_54 ,
V_95 ) ;
#ifdef F_12
F_8 ( V_2 , L_55 ,
V_96 ) ;
#endif
F_26 ( V_2 ) ;
F_8 ( V_2 , L_56 ,
V_97 ) ;
return 0 ;
}
static int F_31 ( struct V_20 * V_20 , struct V_21 * V_21 )
{
return F_32 ( V_21 , F_28 , NULL ) ;
}
static int F_33 ( const void * V_98 , const void * V_99 )
{
const struct V_100 * V_101 = V_98 , * V_102 = V_99 ;
unsigned long V_103 , V_104 ;
V_103 = V_101 -> V_105 . V_106 . V_104 + V_101 -> V_105 . V_107 . V_104 ;
V_104 = V_102 -> V_105 . V_106 . V_104 + V_102 -> V_105 . V_107 . V_104 ;
return V_104 - V_103 ;
}
static void F_34 ( struct V_1 * V_2 , char V_108 , int V_109 , int V_110 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_109 ; V_28 ++ )
F_16 ( V_2 , L_57 ) ;
for ( V_28 = 0 ; V_28 < V_110 ; V_28 ++ )
F_8 ( V_2 , L_58 , V_108 ) ;
F_16 ( V_2 , L_11 ) ;
}
static void F_35 ( char * V_111 , T_2 V_112 , T_3 V_104 )
{
T_3 div ;
T_4 V_113 ;
V_104 += 5 ;
div = F_36 ( V_104 , 1000 , & V_113 ) ;
snprintf ( V_111 , V_112 , L_59 , ( long long ) div , ( int ) V_113 / 10 ) ;
}
static void F_37 ( struct V_1 * V_2 , T_3 time )
{
char V_114 [ 15 ] ;
F_35 ( V_114 , sizeof( V_114 ) , time ) ;
F_8 ( V_2 , L_60 , V_114 ) ;
}
static void F_38 ( struct V_1 * V_2 , struct V_115 * V_116 )
{
F_8 ( V_2 , L_61 , V_116 -> V_104 ) ;
F_37 ( V_2 , V_116 -> V_117 ) ;
F_37 ( V_2 , V_116 -> V_118 ) ;
F_37 ( V_2 , V_116 -> V_119 ) ;
}
static void F_39 ( struct V_1 * V_2 , struct V_100 * V_120 )
{
char V_9 [ 39 ] ;
struct V_6 * V_7 ;
struct V_121 * V_105 ;
int V_28 , V_122 ;
V_7 = V_120 -> V_7 ;
V_105 = & V_120 -> V_105 ;
V_122 = 38 ;
if ( V_7 -> V_11 > 1 )
V_122 -= 2 ;
if ( V_7 -> V_12 )
V_122 -= 2 ;
if ( ! V_7 -> V_9 ) {
char V_8 [ V_123 ] ;
const char * V_124 ;
V_124 = F_7 ( V_7 -> V_10 , V_8 ) ;
snprintf ( V_9 , V_122 , L_1 , V_124 ) ;
} else {
snprintf ( V_9 , V_122 , L_1 , V_7 -> V_9 ) ;
}
V_122 = strlen ( V_9 ) ;
if ( V_7 -> V_11 > 1 ) {
snprintf ( V_9 + V_122 , 3 , L_2 , V_7 -> V_11 ) ;
V_122 += 2 ;
}
if ( V_7 -> V_12 ) {
snprintf ( V_9 + V_122 , 3 , L_3 , V_7 -> V_12 ) ;
V_122 += 2 ;
}
if ( V_105 -> V_125 . V_104 ) {
if ( V_105 -> V_126 . V_104 )
F_8 ( V_2 , L_62 , V_9 ) ;
else
F_8 ( V_2 , L_63 , V_9 ) ;
F_8 ( V_2 , L_64 , V_105 -> V_127 [ V_128 ] ) ;
F_38 ( V_2 , & V_105 -> V_107 ) ;
F_8 ( V_2 , L_65 , V_105 -> V_127 [ V_129 ] ) ;
F_38 ( V_2 , & V_105 -> V_125 ) ;
F_16 ( V_2 , L_11 ) ;
}
if ( V_105 -> V_126 . V_104 ) {
F_8 ( V_2 , L_66 , V_9 ) ;
F_8 ( V_2 , L_64 , V_105 -> V_127 [ V_130 ] ) ;
F_38 ( V_2 , & V_105 -> V_106 ) ;
F_8 ( V_2 , L_65 , V_105 -> V_127 [ V_131 ] ) ;
F_38 ( V_2 , & V_105 -> V_126 ) ;
F_16 ( V_2 , L_11 ) ;
}
if ( V_105 -> V_106 . V_104 + V_105 -> V_107 . V_104 == 0 )
return;
if ( V_105 -> V_126 . V_104 )
V_122 += 2 ;
for ( V_28 = 0 ; V_28 < V_132 ; V_28 ++ ) {
char V_133 [ 32 ] ;
if ( V_7 -> V_134 [ V_28 ] == 0 )
break;
if ( ! V_28 )
F_34 ( V_2 , '-' , 40 - V_122 , V_122 ) ;
snprintf ( V_133 , sizeof( V_133 ) , L_67 ,
( void * ) V_7 -> V_134 [ V_28 ] ) ;
F_8 ( V_2 , L_68 ,
V_9 , V_105 -> V_134 [ V_28 ] ,
V_133 , ( void * ) V_7 -> V_134 [ V_28 ] ) ;
}
for ( V_28 = 0 ; V_28 < V_132 ; V_28 ++ ) {
char V_133 [ 32 ] ;
if ( V_7 -> V_135 [ V_28 ] == 0 )
break;
if ( ! V_28 )
F_34 ( V_2 , '-' , 40 - V_122 , V_122 ) ;
snprintf ( V_133 , sizeof( V_133 ) , L_67 ,
( void * ) V_7 -> V_135 [ V_28 ] ) ;
F_8 ( V_2 , L_68 ,
V_9 , V_105 -> V_135 [ V_28 ] ,
V_133 , ( void * ) V_7 -> V_135 [ V_28 ] ) ;
}
if ( V_28 ) {
F_16 ( V_2 , L_11 ) ;
F_34 ( V_2 , '.' , 0 , 40 + 1 + 10 * ( 14 + 1 ) ) ;
F_16 ( V_2 , L_11 ) ;
}
}
static void F_40 ( struct V_1 * V_2 )
{
F_8 ( V_2 , L_69 ) ;
if ( F_41 ( ! V_97 ) )
F_8 ( V_2 , L_70 ) ;
F_34 ( V_2 , '-' , 0 , 40 + 1 + 10 * ( 14 + 1 ) ) ;
F_8 ( V_2 , L_71
L_72 ,
L_73 ,
L_74 ,
L_75 ,
L_76 ,
L_77 ,
L_78 ,
L_79 ,
L_80 ,
L_81 ,
L_82 ,
L_83 ) ;
F_34 ( V_2 , '-' , 0 , 40 + 1 + 10 * ( 14 + 1 ) ) ;
F_8 ( V_2 , L_11 ) ;
}
static void * F_42 ( struct V_1 * V_2 , T_1 * V_4 )
{
struct V_136 * V_120 = V_2 -> V_137 ;
struct V_100 * V_138 ;
if ( * V_4 == 0 )
return V_23 ;
V_138 = V_120 -> V_105 + ( * V_4 - 1 ) ;
if ( V_138 >= V_120 -> V_139 )
V_138 = NULL ;
return V_138 ;
}
static void * F_43 ( struct V_1 * V_2 , void * V_3 , T_1 * V_4 )
{
( * V_4 ) ++ ;
return F_42 ( V_2 , V_4 ) ;
}
static void F_44 ( struct V_1 * V_2 , void * V_3 )
{
}
static int F_45 ( struct V_1 * V_2 , void * V_3 )
{
if ( V_3 == V_23 )
F_40 ( V_2 ) ;
else
F_39 ( V_2 , V_3 ) ;
return 0 ;
}
static int F_46 ( struct V_20 * V_20 , struct V_21 * V_21 )
{
int V_140 ;
struct V_6 * V_7 ;
struct V_136 * V_120 = F_47 ( sizeof( struct V_136 ) ) ;
if ( ! V_120 )
return - V_141 ;
V_140 = F_19 ( V_21 , & V_142 ) ;
if ( ! V_140 ) {
struct V_100 * V_138 = V_120 -> V_105 ;
struct V_1 * V_2 = V_21 -> V_143 ;
F_17 (class, &all_lock_classes, lock_entry) {
V_138 -> V_7 = V_7 ;
V_138 -> V_105 = F_48 ( V_7 ) ;
V_138 ++ ;
}
V_120 -> V_139 = V_138 ;
F_49 ( V_120 -> V_105 , V_120 -> V_139 - V_120 -> V_105 ,
sizeof( struct V_100 ) ,
F_33 , NULL ) ;
V_2 -> V_137 = V_120 ;
} else
F_50 ( V_120 ) ;
return V_140 ;
}
static T_5 F_51 ( struct V_21 * V_21 , const char T_6 * V_111 ,
T_2 V_144 , T_1 * V_145 )
{
struct V_6 * V_7 ;
char V_108 ;
if ( V_144 ) {
if ( F_52 ( V_108 , V_111 ) )
return - V_146 ;
if ( V_108 != '0' )
return V_144 ;
F_17 (class, &all_lock_classes, lock_entry)
F_53 ( V_7 ) ;
}
return V_144 ;
}
static int F_54 ( struct V_20 * V_20 , struct V_21 * V_21 )
{
struct V_1 * V_147 = V_21 -> V_143 ;
F_50 ( V_147 -> V_137 ) ;
return F_55 ( V_20 , V_21 ) ;
}
static int T_7 F_56 ( void )
{
F_57 ( L_84 , V_148 , NULL , & V_149 ) ;
#ifdef F_12
F_57 ( L_85 , V_148 , NULL ,
& V_150 ) ;
#endif
F_57 ( L_86 , V_148 , NULL ,
& V_151 ) ;
#ifdef F_58
F_57 ( L_87 , V_148 | V_152 , NULL ,
& V_153 ) ;
#endif
return 0 ;
}
