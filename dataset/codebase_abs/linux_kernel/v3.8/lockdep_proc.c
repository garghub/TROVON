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
F_8 ( V_2 , L_13 ) ;
return 0 ;
}
F_8 ( V_2 , L_14 , V_28 -> V_30 ) ;
for ( V_29 = 0 ; V_29 < V_28 -> V_31 ; V_29 ++ ) {
V_7 = F_24 ( V_28 , V_29 ) ;
if ( ! V_7 -> V_11 )
continue;
F_8 ( V_2 , L_15 , V_7 -> V_11 ) ;
F_6 ( V_2 , V_7 ) ;
F_16 ( V_2 , L_11 ) ;
}
F_16 ( V_2 , L_11 ) ;
return 0 ;
}
static int F_25 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
return F_19 ( V_22 , & V_32 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
#ifdef F_11
unsigned long long V_33 = F_27 ( V_34 ) ,
V_35 = F_27 ( V_36 ) ,
V_37 = F_27 ( V_38 ) ,
V_39 = F_27 ( V_40 ) ,
V_41 = F_27 ( V_42 ) ,
V_43 = F_27 ( V_44 ) ,
V_45 = F_27 ( V_46 ) ,
V_47 = F_27 ( V_48 ) ;
F_8 ( V_2 , L_16 ,
F_27 ( V_49 ) ) ;
F_8 ( V_2 , L_17 ,
F_27 ( V_50 ) ) ;
F_8 ( V_2 , L_18 ,
F_27 ( V_51 ) ) ;
F_8 ( V_2 , L_19 ,
F_27 ( V_52 ) ) ;
F_8 ( V_2 , L_20 ,
F_27 ( V_53 ) ) ;
F_8 ( V_2 , L_21 , V_33 ) ;
F_8 ( V_2 , L_22 , V_35 ) ;
F_8 ( V_2 , L_23 , V_37 ) ;
F_8 ( V_2 , L_24 , V_39 ) ;
F_8 ( V_2 , L_25 , V_41 ) ;
F_8 ( V_2 , L_26 , V_43 ) ;
F_8 ( V_2 , L_27 , V_45 ) ;
F_8 ( V_2 , L_28 , V_47 ) ;
#endif
}
static int F_28 ( struct V_1 * V_2 , void * V_3 )
{
struct V_6 * V_7 ;
unsigned long V_54 = 0 , V_55 = 0 ,
V_56 = 0 , V_57 = 0 ,
V_58 = 0 , V_59 = 0 ,
V_60 = 0 , V_61 = 0 ,
V_62 = 0 , V_63 = 0 ,
V_64 = 0 , V_65 = 0 ,
V_66 = 0 , V_67 = 0 ,
V_68 = 0 ;
F_17 (class, &all_lock_classes, lock_entry) {
if ( V_7 -> V_69 == 0 )
V_54 ++ ;
if ( V_7 -> V_69 == V_70 )
V_55 ++ ;
if ( V_7 -> V_69 & V_71 )
V_56 ++ ;
if ( V_7 -> V_69 & V_72 )
V_57 ++ ;
if ( V_7 -> V_69 & V_73 )
V_58 ++ ;
if ( V_7 -> V_69 & V_74 )
V_59 ++ ;
if ( V_7 -> V_69 & V_75 )
V_60 ++ ;
if ( V_7 -> V_69 & V_76 )
V_61 ++ ;
if ( V_7 -> V_69 & V_77 )
V_62 ++ ;
if ( V_7 -> V_69 & V_78 )
V_63 ++ ;
if ( V_7 -> V_69 & V_79 )
V_64 ++ ;
if ( V_7 -> V_69 & V_80 )
V_65 ++ ;
if ( V_7 -> V_69 & V_81 )
V_66 ++ ;
if ( V_7 -> V_69 & V_82 )
V_67 ++ ;
#ifdef F_12
V_68 += F_13 ( V_7 ) ;
#endif
}
#ifdef F_11
F_29 ( F_27 ( V_83 ) != V_54 ) ;
#endif
F_8 ( V_2 , L_29 ,
V_84 , V_85 ) ;
F_8 ( V_2 , L_30 ,
V_86 , V_87 ) ;
F_8 ( V_2 , L_31 ,
V_68 ) ;
F_8 ( V_2 , L_32 ,
V_57 * V_56 +
V_61 * V_60 +
V_86 ) ;
#ifdef F_12
F_8 ( V_2 , L_33 ,
V_25 , V_88 ) ;
F_8 ( V_2 , L_34 ,
V_89 , V_90 ) ;
#endif
#ifdef F_30
F_8 ( V_2 , L_35 ,
V_91 ) ;
F_8 ( V_2 , L_36 ,
V_92 ) ;
#endif
F_8 ( V_2 , L_37 ,
V_93 ) ;
F_8 ( V_2 , L_38 ,
V_94 , V_95 ) ;
F_8 ( V_2 , L_39 ,
( V_91 + 1 ) *
( V_92 + 1 ) *
( V_93 + 1 )
) ;
F_8 ( V_2 , L_40 ,
V_60 ) ;
F_8 ( V_2 , L_41 ,
V_61 ) ;
F_8 ( V_2 , L_42 ,
V_58 ) ;
F_8 ( V_2 , L_43 ,
V_59 ) ;
F_8 ( V_2 , L_44 ,
V_56 ) ;
F_8 ( V_2 , L_45 ,
V_57 ) ;
F_8 ( V_2 , L_46 ,
V_66 ) ;
F_8 ( V_2 , L_47 ,
V_67 ) ;
F_8 ( V_2 , L_48 ,
V_64 ) ;
F_8 ( V_2 , L_49 ,
V_65 ) ;
F_8 ( V_2 , L_50 ,
V_62 ) ;
F_8 ( V_2 , L_51 ,
V_63 ) ;
F_8 ( V_2 , L_52 ,
V_55 ) ;
F_8 ( V_2 , L_53 ,
V_54 ) ;
F_8 ( V_2 , L_54 ,
V_96 ) ;
#ifdef F_12
F_8 ( V_2 , L_55 ,
V_97 ) ;
#endif
F_26 ( V_2 ) ;
F_8 ( V_2 , L_56 ,
V_98 ) ;
return 0 ;
}
static int F_31 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
return F_32 ( V_22 , F_28 , NULL ) ;
}
static int F_33 ( const void * V_99 , const void * V_100 )
{
const struct V_101 * V_102 = V_99 , * V_103 = V_100 ;
unsigned long V_104 , V_105 ;
V_104 = V_102 -> V_106 . V_107 . V_105 + V_102 -> V_106 . V_108 . V_105 ;
V_105 = V_103 -> V_106 . V_107 . V_105 + V_103 -> V_106 . V_108 . V_105 ;
return V_105 - V_104 ;
}
static void F_34 ( struct V_1 * V_2 , char V_109 , int V_110 , int V_111 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < V_110 ; V_29 ++ )
F_16 ( V_2 , L_57 ) ;
for ( V_29 = 0 ; V_29 < V_111 ; V_29 ++ )
F_8 ( V_2 , L_58 , V_109 ) ;
F_16 ( V_2 , L_11 ) ;
}
static void F_35 ( char * V_112 , T_2 V_113 , T_3 V_105 )
{
T_3 div ;
T_4 V_114 ;
V_105 += 5 ;
div = F_36 ( V_105 , 1000 , & V_114 ) ;
snprintf ( V_112 , V_113 , L_59 , ( long long ) div , ( int ) V_114 / 10 ) ;
}
static void F_37 ( struct V_1 * V_2 , T_3 time )
{
char V_115 [ 15 ] ;
F_35 ( V_115 , sizeof( V_115 ) , time ) ;
F_8 ( V_2 , L_60 , V_115 ) ;
}
static void F_38 ( struct V_1 * V_2 , struct V_116 * V_117 )
{
F_8 ( V_2 , L_61 , V_117 -> V_105 ) ;
F_37 ( V_2 , V_117 -> V_118 ) ;
F_37 ( V_2 , V_117 -> V_119 ) ;
F_37 ( V_2 , V_117 -> V_120 ) ;
}
static void F_39 ( struct V_1 * V_2 , struct V_101 * V_121 )
{
char V_10 [ 39 ] ;
struct V_6 * V_7 ;
struct V_122 * V_106 ;
int V_29 , V_123 ;
V_7 = V_121 -> V_7 ;
V_106 = & V_121 -> V_106 ;
V_123 = 38 ;
if ( V_7 -> V_12 > 1 )
V_123 -= 2 ;
if ( V_7 -> V_13 )
V_123 -= 2 ;
if ( ! V_7 -> V_10 ) {
char V_8 [ V_9 ] ;
const char * V_124 ;
V_124 = F_7 ( V_7 -> V_11 , V_8 ) ;
snprintf ( V_10 , V_123 , L_1 , V_124 ) ;
} else {
snprintf ( V_10 , V_123 , L_1 , V_7 -> V_10 ) ;
}
V_123 = strlen ( V_10 ) ;
if ( V_7 -> V_12 > 1 ) {
snprintf ( V_10 + V_123 , 3 , L_2 , V_7 -> V_12 ) ;
V_123 += 2 ;
}
if ( V_7 -> V_13 ) {
snprintf ( V_10 + V_123 , 3 , L_3 , V_7 -> V_13 ) ;
V_123 += 2 ;
}
if ( V_106 -> V_125 . V_105 ) {
if ( V_106 -> V_126 . V_105 )
F_8 ( V_2 , L_62 , V_10 ) ;
else
F_8 ( V_2 , L_63 , V_10 ) ;
F_8 ( V_2 , L_64 , V_106 -> V_127 [ V_128 ] ) ;
F_38 ( V_2 , & V_106 -> V_108 ) ;
F_8 ( V_2 , L_65 , V_106 -> V_127 [ V_129 ] ) ;
F_38 ( V_2 , & V_106 -> V_125 ) ;
F_16 ( V_2 , L_11 ) ;
}
if ( V_106 -> V_126 . V_105 ) {
F_8 ( V_2 , L_66 , V_10 ) ;
F_8 ( V_2 , L_64 , V_106 -> V_127 [ V_130 ] ) ;
F_38 ( V_2 , & V_106 -> V_107 ) ;
F_8 ( V_2 , L_65 , V_106 -> V_127 [ V_131 ] ) ;
F_38 ( V_2 , & V_106 -> V_126 ) ;
F_16 ( V_2 , L_11 ) ;
}
if ( V_106 -> V_107 . V_105 + V_106 -> V_108 . V_105 == 0 )
return;
if ( V_106 -> V_126 . V_105 )
V_123 += 2 ;
for ( V_29 = 0 ; V_29 < V_132 ; V_29 ++ ) {
char V_133 [ 32 ] ;
if ( V_7 -> V_134 [ V_29 ] == 0 )
break;
if ( ! V_29 )
F_34 ( V_2 , '-' , 40 - V_123 , V_123 ) ;
snprintf ( V_133 , sizeof( V_133 ) , L_67 ,
( void * ) V_7 -> V_134 [ V_29 ] ) ;
F_8 ( V_2 , L_68 ,
V_10 , V_106 -> V_134 [ V_29 ] ,
V_133 , ( void * ) V_7 -> V_134 [ V_29 ] ) ;
}
for ( V_29 = 0 ; V_29 < V_132 ; V_29 ++ ) {
char V_133 [ 32 ] ;
if ( V_7 -> V_135 [ V_29 ] == 0 )
break;
if ( ! V_29 )
F_34 ( V_2 , '-' , 40 - V_123 , V_123 ) ;
snprintf ( V_133 , sizeof( V_133 ) , L_67 ,
( void * ) V_7 -> V_135 [ V_29 ] ) ;
F_8 ( V_2 , L_68 ,
V_10 , V_106 -> V_135 [ V_29 ] ,
V_133 , ( void * ) V_7 -> V_135 [ V_29 ] ) ;
}
if ( V_29 ) {
F_16 ( V_2 , L_11 ) ;
F_34 ( V_2 , '.' , 0 , 40 + 1 + 10 * ( 14 + 1 ) ) ;
F_16 ( V_2 , L_11 ) ;
}
}
static void F_40 ( struct V_1 * V_2 )
{
F_8 ( V_2 , L_69 ) ;
if ( F_41 ( ! V_98 ) )
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
struct V_136 * V_121 = V_2 -> V_137 ;
struct V_101 * V_138 ;
if ( * V_4 == 0 )
return V_24 ;
V_138 = V_121 -> V_106 + ( * V_4 - 1 ) ;
if ( V_138 >= V_121 -> V_139 )
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
if ( V_3 == V_24 )
F_40 ( V_2 ) ;
else
F_39 ( V_2 , V_3 ) ;
return 0 ;
}
static int F_46 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
int V_140 ;
struct V_6 * V_7 ;
struct V_136 * V_121 = F_47 ( sizeof( struct V_136 ) ) ;
if ( ! V_121 )
return - V_141 ;
V_140 = F_19 ( V_22 , & V_142 ) ;
if ( ! V_140 ) {
struct V_101 * V_138 = V_121 -> V_106 ;
struct V_1 * V_2 = V_22 -> V_143 ;
F_17 (class, &all_lock_classes, lock_entry) {
V_138 -> V_7 = V_7 ;
V_138 -> V_106 = F_48 ( V_7 ) ;
V_138 ++ ;
}
V_121 -> V_139 = V_138 ;
F_49 ( V_121 -> V_106 , V_121 -> V_139 - V_121 -> V_106 ,
sizeof( struct V_101 ) ,
F_33 , NULL ) ;
V_2 -> V_137 = V_121 ;
} else
F_50 ( V_121 ) ;
return V_140 ;
}
static T_5 F_51 ( struct V_22 * V_22 , const char T_6 * V_112 ,
T_2 V_144 , T_1 * V_145 )
{
struct V_6 * V_7 ;
char V_109 ;
if ( V_144 ) {
if ( F_52 ( V_109 , V_112 ) )
return - V_146 ;
if ( V_109 != '0' )
return V_144 ;
F_17 (class, &all_lock_classes, lock_entry)
F_53 ( V_7 ) ;
}
return V_144 ;
}
static int F_54 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
struct V_1 * V_147 = V_22 -> V_143 ;
F_50 ( V_147 -> V_137 ) ;
return F_55 ( V_21 , V_22 ) ;
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
