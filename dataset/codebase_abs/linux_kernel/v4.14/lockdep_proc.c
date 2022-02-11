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
char V_8 [ V_9 ] ;
const char * V_10 = V_7 -> V_10 ;
if ( ! V_10 ) {
V_10 = F_7 ( V_7 -> V_11 , V_8 ) ;
F_8 ( V_2 , L_1 , V_10 ) ;
} else{
F_8 ( V_2 , L_1 , V_10 ) ;
if ( V_7 -> V_12 > 1 )
F_8 ( V_2 , L_2 , V_7 -> V_12 ) ;
if ( V_7 -> V_13 )
F_8 ( V_2 , L_3 , V_7 -> V_13 ) ;
}
}
static int F_9 ( struct V_1 * V_2 , void * V_3 )
{
struct V_6 * V_7 = F_10 ( V_3 , struct V_6 , V_14 ) ;
struct V_15 * V_16 ;
char V_17 [ V_18 ] ;
if ( V_3 == & V_5 ) {
F_8 ( V_2 , L_4 ) ;
return 0 ;
}
F_8 ( V_2 , L_5 , V_7 -> V_11 ) ;
#ifdef F_11
F_8 ( V_2 , L_6 , V_7 -> V_19 ) ;
#endif
#ifdef F_12
F_8 ( V_2 , L_7 , F_13 ( V_7 ) ) ;
F_8 ( V_2 , L_8 , F_14 ( V_7 ) ) ;
#endif
F_15 ( V_7 , V_17 ) ;
F_8 ( V_2 , L_9 , V_17 ) ;
F_8 ( V_2 , L_10 ) ;
F_6 ( V_2 , V_7 ) ;
F_16 ( V_2 , L_11 ) ;
F_17 (entry, &class->locks_after, entry) {
if ( V_16 -> V_20 == 1 ) {
F_8 ( V_2 , L_12 , V_16 -> V_7 -> V_11 ) ;
F_6 ( V_2 , V_16 -> V_7 ) ;
F_16 ( V_2 , L_11 ) ;
}
}
F_16 ( V_2 , L_11 ) ;
return 0 ;
}
static int F_18 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
return F_19 ( V_22 , & V_23 ) ;
}
static void * F_20 ( struct V_1 * V_2 , T_1 * V_4 )
{
if ( * V_4 == 0 )
return V_24 ;
if ( * V_4 - 1 < V_25 )
return V_26 + ( * V_4 - 1 ) ;
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
struct V_27 * V_28 = V_3 ;
struct V_6 * V_7 ;
int V_29 ;
if ( V_3 == V_24 ) {
if ( V_30 > V_31 )
F_8 ( V_2 , L_13 ) ;
F_8 ( V_2 , L_14 ) ;
return 0 ;
}
F_8 ( V_2 , L_15 , V_28 -> V_32 ) ;
for ( V_29 = 0 ; V_29 < V_28 -> V_33 ; V_29 ++ ) {
V_7 = F_24 ( V_28 , V_29 ) ;
if ( ! V_7 -> V_11 )
continue;
F_8 ( V_2 , L_16 , V_7 -> V_11 ) ;
F_6 ( V_2 , V_7 ) ;
F_16 ( V_2 , L_11 ) ;
}
F_16 ( V_2 , L_11 ) ;
return 0 ;
}
static int F_25 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
return F_19 ( V_22 , & V_34 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
#ifdef F_11
unsigned long long V_35 = F_27 ( V_36 ) ,
V_37 = F_27 ( V_38 ) ,
V_39 = F_27 ( V_40 ) ,
V_41 = F_27 ( V_42 ) ,
V_43 = F_27 ( V_44 ) ,
V_45 = F_27 ( V_46 ) ,
V_47 = F_27 ( V_48 ) ,
V_49 = F_27 ( V_50 ) ;
F_8 ( V_2 , L_17 ,
F_27 ( V_51 ) ) ;
F_8 ( V_2 , L_18 ,
F_27 ( V_52 ) ) ;
F_8 ( V_2 , L_19 ,
F_27 ( V_53 ) ) ;
F_8 ( V_2 , L_20 ,
F_27 ( V_54 ) ) ;
F_8 ( V_2 , L_21 ,
F_27 ( V_55 ) ) ;
F_8 ( V_2 , L_22 ,
F_27 ( V_56 ) ) ;
F_8 ( V_2 , L_23 ,
F_27 ( V_57 ) ) ;
F_8 ( V_2 , L_24 , V_35 ) ;
F_8 ( V_2 , L_25 , V_37 ) ;
F_8 ( V_2 , L_26 , V_39 ) ;
F_8 ( V_2 , L_27 , V_41 ) ;
F_8 ( V_2 , L_28 , V_43 ) ;
F_8 ( V_2 , L_29 , V_45 ) ;
F_8 ( V_2 , L_30 , V_47 ) ;
F_8 ( V_2 , L_31 , V_49 ) ;
#endif
}
static int F_28 ( struct V_1 * V_2 , void * V_3 )
{
struct V_6 * V_7 ;
unsigned long V_58 = 0 , V_59 = 0 ,
V_60 = 0 , V_61 = 0 ,
V_62 = 0 , V_63 = 0 ,
V_64 = 0 , V_65 = 0 ,
V_66 = 0 , V_67 = 0 ,
V_68 = 0 , V_69 = 0 ,
V_70 = 0 , V_71 = 0 ,
V_72 = 0 ;
F_17 (class, &all_lock_classes, lock_entry) {
if ( V_7 -> V_73 == 0 )
V_58 ++ ;
if ( V_7 -> V_73 == V_74 )
V_59 ++ ;
if ( V_7 -> V_73 & V_75 )
V_60 ++ ;
if ( V_7 -> V_73 & V_76 )
V_61 ++ ;
if ( V_7 -> V_73 & V_77 )
V_62 ++ ;
if ( V_7 -> V_73 & V_78 )
V_63 ++ ;
if ( V_7 -> V_73 & V_79 )
V_64 ++ ;
if ( V_7 -> V_73 & V_80 )
V_65 ++ ;
if ( V_7 -> V_73 & V_81 )
V_66 ++ ;
if ( V_7 -> V_73 & V_82 )
V_67 ++ ;
if ( V_7 -> V_73 & V_83 )
V_68 ++ ;
if ( V_7 -> V_73 & V_84 )
V_69 ++ ;
if ( V_7 -> V_73 & V_85 )
V_70 ++ ;
if ( V_7 -> V_73 & V_86 )
V_71 ++ ;
#ifdef F_12
V_72 += F_13 ( V_7 ) ;
#endif
}
#ifdef F_11
F_29 ( F_27 ( V_87 ) != V_58 ) ;
#endif
F_8 ( V_2 , L_32 ,
V_88 , V_89 ) ;
F_8 ( V_2 , L_33 ,
V_90 , V_91 ) ;
F_8 ( V_2 , L_34 ,
V_72 ) ;
F_8 ( V_2 , L_35 ,
V_61 * V_60 +
V_65 * V_64 +
V_90 ) ;
#ifdef F_12
F_8 ( V_2 , L_36 ,
V_25 , V_92 ) ;
F_8 ( V_2 , L_37 ,
V_30 , V_31 ) ;
#endif
#ifdef F_30
F_8 ( V_2 , L_38 ,
V_93 ) ;
F_8 ( V_2 , L_39 ,
V_94 ) ;
#endif
F_8 ( V_2 , L_40 ,
V_95 ) ;
F_8 ( V_2 , L_41 ,
V_96 , V_97 ) ;
F_8 ( V_2 , L_42 ,
( V_93 + 1 ) *
( V_94 + 1 ) *
( V_95 + 1 )
) ;
F_8 ( V_2 , L_43 ,
V_64 ) ;
F_8 ( V_2 , L_44 ,
V_65 ) ;
F_8 ( V_2 , L_45 ,
V_62 ) ;
F_8 ( V_2 , L_46 ,
V_63 ) ;
F_8 ( V_2 , L_47 ,
V_60 ) ;
F_8 ( V_2 , L_48 ,
V_61 ) ;
F_8 ( V_2 , L_49 ,
V_70 ) ;
F_8 ( V_2 , L_50 ,
V_71 ) ;
F_8 ( V_2 , L_51 ,
V_68 ) ;
F_8 ( V_2 , L_52 ,
V_69 ) ;
F_8 ( V_2 , L_53 ,
V_66 ) ;
F_8 ( V_2 , L_54 ,
V_67 ) ;
F_8 ( V_2 , L_55 ,
V_59 ) ;
F_8 ( V_2 , L_56 ,
V_58 ) ;
F_8 ( V_2 , L_57 ,
V_98 ) ;
#ifdef F_12
F_8 ( V_2 , L_58 ,
V_99 ) ;
#endif
F_26 ( V_2 ) ;
F_8 ( V_2 , L_59 ,
V_100 ) ;
return 0 ;
}
static int F_31 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
return F_32 ( V_22 , F_28 , NULL ) ;
}
static int F_33 ( const void * V_101 , const void * V_102 )
{
const struct V_103 * V_104 = V_101 , * V_105 = V_102 ;
unsigned long V_106 , V_107 ;
V_106 = V_104 -> V_108 . V_109 . V_107 + V_104 -> V_108 . V_110 . V_107 ;
V_107 = V_105 -> V_108 . V_109 . V_107 + V_105 -> V_108 . V_110 . V_107 ;
return V_107 - V_106 ;
}
static void F_34 ( struct V_1 * V_2 , char V_111 , int V_112 , int V_113 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < V_112 ; V_29 ++ )
F_16 ( V_2 , L_60 ) ;
for ( V_29 = 0 ; V_29 < V_113 ; V_29 ++ )
F_8 ( V_2 , L_61 , V_111 ) ;
F_16 ( V_2 , L_11 ) ;
}
static void F_35 ( char * V_114 , T_2 V_115 , T_3 V_107 )
{
T_3 div ;
T_4 V_116 ;
V_107 += 5 ;
div = F_36 ( V_107 , 1000 , & V_116 ) ;
snprintf ( V_114 , V_115 , L_62 , ( long long ) div , ( int ) V_116 / 10 ) ;
}
static void F_37 ( struct V_1 * V_2 , T_3 time )
{
char V_117 [ 15 ] ;
F_35 ( V_117 , sizeof( V_117 ) , time ) ;
F_8 ( V_2 , L_63 , V_117 ) ;
}
static void F_38 ( struct V_1 * V_2 , struct V_118 * V_119 )
{
F_8 ( V_2 , L_64 , V_119 -> V_107 ) ;
F_37 ( V_2 , V_119 -> V_120 ) ;
F_37 ( V_2 , V_119 -> V_121 ) ;
F_37 ( V_2 , V_119 -> V_122 ) ;
F_37 ( V_2 , V_119 -> V_107 ? F_39 ( V_119 -> V_122 , V_119 -> V_107 ) : 0 ) ;
}
static void F_40 ( struct V_1 * V_2 , struct V_103 * V_123 )
{
struct V_124 * V_125 ;
struct V_126 * V_108 ;
struct V_6 * V_7 ;
const char * V_127 ;
int V_29 , V_128 ;
char V_10 [ 39 ] ;
V_7 = V_123 -> V_7 ;
V_108 = & V_123 -> V_108 ;
V_128 = 38 ;
if ( V_7 -> V_12 > 1 )
V_128 -= 2 ;
if ( V_7 -> V_13 )
V_128 -= 2 ;
F_41 () ;
V_127 = F_42 ( V_7 -> V_10 ) ;
V_125 = F_42 ( V_7 -> V_11 ) ;
if ( ! V_127 && ! V_125 ) {
F_43 () ;
return;
} else if ( ! V_127 ) {
char V_8 [ V_9 ] ;
const char * V_129 ;
V_129 = F_7 ( V_125 , V_8 ) ;
snprintf ( V_10 , V_128 , L_1 , V_129 ) ;
} else {
snprintf ( V_10 , V_128 , L_1 , V_127 ) ;
}
F_43 () ;
V_128 = strlen ( V_10 ) ;
if ( V_7 -> V_12 > 1 ) {
snprintf ( V_10 + V_128 , 3 , L_2 , V_7 -> V_12 ) ;
V_128 += 2 ;
}
if ( V_7 -> V_13 ) {
snprintf ( V_10 + V_128 , 3 , L_3 , V_7 -> V_13 ) ;
V_128 += 2 ;
}
if ( V_108 -> V_130 . V_107 ) {
if ( V_108 -> V_131 . V_107 )
F_8 ( V_2 , L_65 , V_10 ) ;
else
F_8 ( V_2 , L_66 , V_10 ) ;
F_8 ( V_2 , L_67 , V_108 -> V_132 [ V_133 ] ) ;
F_38 ( V_2 , & V_108 -> V_110 ) ;
F_8 ( V_2 , L_68 , V_108 -> V_132 [ V_134 ] ) ;
F_38 ( V_2 , & V_108 -> V_130 ) ;
F_16 ( V_2 , L_11 ) ;
}
if ( V_108 -> V_131 . V_107 ) {
F_8 ( V_2 , L_69 , V_10 ) ;
F_8 ( V_2 , L_67 , V_108 -> V_132 [ V_135 ] ) ;
F_38 ( V_2 , & V_108 -> V_109 ) ;
F_8 ( V_2 , L_68 , V_108 -> V_132 [ V_136 ] ) ;
F_38 ( V_2 , & V_108 -> V_131 ) ;
F_16 ( V_2 , L_11 ) ;
}
if ( V_108 -> V_109 . V_107 + V_108 -> V_110 . V_107 == 0 )
return;
if ( V_108 -> V_131 . V_107 )
V_128 += 2 ;
for ( V_29 = 0 ; V_29 < V_137 ; V_29 ++ ) {
char V_138 [ 32 ] ;
if ( V_7 -> V_139 [ V_29 ] == 0 )
break;
if ( ! V_29 )
F_34 ( V_2 , '-' , 40 - V_128 , V_128 ) ;
snprintf ( V_138 , sizeof( V_138 ) , L_70 ,
( void * ) V_7 -> V_139 [ V_29 ] ) ;
F_8 ( V_2 , L_71 ,
V_10 , V_108 -> V_139 [ V_29 ] ,
V_138 , ( void * ) V_7 -> V_139 [ V_29 ] ) ;
}
for ( V_29 = 0 ; V_29 < V_137 ; V_29 ++ ) {
char V_138 [ 32 ] ;
if ( V_7 -> V_140 [ V_29 ] == 0 )
break;
if ( ! V_29 )
F_34 ( V_2 , '-' , 40 - V_128 , V_128 ) ;
snprintf ( V_138 , sizeof( V_138 ) , L_70 ,
( void * ) V_7 -> V_140 [ V_29 ] ) ;
F_8 ( V_2 , L_71 ,
V_10 , V_108 -> V_140 [ V_29 ] ,
V_138 , ( void * ) V_7 -> V_140 [ V_29 ] ) ;
}
if ( V_29 ) {
F_16 ( V_2 , L_11 ) ;
F_34 ( V_2 , '.' , 0 , 40 + 1 + 12 * ( 14 + 1 ) ) ;
F_16 ( V_2 , L_11 ) ;
}
}
static void F_44 ( struct V_1 * V_2 )
{
F_16 ( V_2 , L_72 ) ;
if ( F_45 ( ! V_100 ) )
F_8 ( V_2 , L_73 ) ;
F_34 ( V_2 , '-' , 0 , 40 + 1 + 12 * ( 14 + 1 ) ) ;
F_8 ( V_2 , L_74
L_75 ,
L_76 ,
L_77 ,
L_78 ,
L_79 ,
L_80 ,
L_81 ,
L_82 ,
L_83 ,
L_84 ,
L_85 ,
L_86 ,
L_87 ,
L_88 ) ;
F_34 ( V_2 , '-' , 0 , 40 + 1 + 12 * ( 14 + 1 ) ) ;
F_8 ( V_2 , L_11 ) ;
}
static void * F_46 ( struct V_1 * V_2 , T_1 * V_4 )
{
struct V_141 * V_123 = V_2 -> V_142 ;
struct V_103 * V_143 ;
if ( * V_4 == 0 )
return V_24 ;
V_143 = V_123 -> V_108 + ( * V_4 - 1 ) ;
if ( V_143 >= V_123 -> V_144 )
V_143 = NULL ;
return V_143 ;
}
static void * F_47 ( struct V_1 * V_2 , void * V_3 , T_1 * V_4 )
{
( * V_4 ) ++ ;
return F_46 ( V_2 , V_4 ) ;
}
static void F_48 ( struct V_1 * V_2 , void * V_3 )
{
}
static int F_49 ( struct V_1 * V_2 , void * V_3 )
{
if ( V_3 == V_24 )
F_44 ( V_2 ) ;
else
F_40 ( V_2 , V_3 ) ;
return 0 ;
}
static int F_50 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
int V_145 ;
struct V_6 * V_7 ;
struct V_141 * V_123 = F_51 ( sizeof( struct V_141 ) ) ;
if ( ! V_123 )
return - V_146 ;
V_145 = F_19 ( V_22 , & V_147 ) ;
if ( ! V_145 ) {
struct V_103 * V_143 = V_123 -> V_108 ;
struct V_1 * V_2 = V_22 -> V_148 ;
F_17 (class, &all_lock_classes, lock_entry) {
V_143 -> V_7 = V_7 ;
V_143 -> V_108 = F_52 ( V_7 ) ;
V_143 ++ ;
}
V_123 -> V_144 = V_143 ;
F_53 ( V_123 -> V_108 , V_123 -> V_144 - V_123 -> V_108 ,
sizeof( struct V_103 ) ,
F_33 , NULL ) ;
V_2 -> V_142 = V_123 ;
} else
F_54 ( V_123 ) ;
return V_145 ;
}
static T_5 F_55 ( struct V_22 * V_22 , const char T_6 * V_114 ,
T_2 V_149 , T_1 * V_150 )
{
struct V_6 * V_7 ;
char V_111 ;
if ( V_149 ) {
if ( F_56 ( V_111 , V_114 ) )
return - V_151 ;
if ( V_111 != '0' )
return V_149 ;
F_17 (class, &all_lock_classes, lock_entry)
F_57 ( V_7 ) ;
}
return V_149 ;
}
static int F_58 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
struct V_1 * V_152 = V_22 -> V_148 ;
F_54 ( V_152 -> V_142 ) ;
return F_59 ( V_21 , V_22 ) ;
}
static int T_7 F_60 ( void )
{
F_61 ( L_89 , V_153 , NULL , & V_154 ) ;
#ifdef F_12
F_61 ( L_90 , V_153 , NULL ,
& V_155 ) ;
#endif
F_61 ( L_91 , V_153 , NULL ,
& V_156 ) ;
#ifdef F_62
F_61 ( L_92 , V_153 | V_157 , NULL ,
& V_158 ) ;
#endif
return 0 ;
}
