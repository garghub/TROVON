static struct V_1 * F_1 ( int V_2 )
{
int V_3 ;
struct V_1 * V_4 = NULL ;
for ( V_3 = 0 ; V_3 < F_2 ( V_5 ) ; V_3 ++ ) {
if ( V_5 [ V_3 ] . V_2 == V_2 ) {
V_4 = & V_5 [ V_3 ] ;
break;
}
}
return V_4 ;
}
static int F_3 ( struct V_6 * V_7 )
{
char * V_8 = NULL ;
int V_9 ;
struct V_10 * V_11 ;
V_9 = - V_12 ;
V_11 = F_4 ( sizeof( * V_11 ) , V_13 ) ;
if ( ! V_11 )
goto V_14;
V_9 = - V_15 ;
V_11 -> V_16 = ++ V_7 -> V_17 . V_18 ;
if ( V_11 -> V_16 != V_19 )
goto V_14;
V_9 = - V_12 ;
V_8 = F_5 ( V_20 , V_13 ) ;
if ( ! V_8 )
goto V_14;
V_9 = F_6 ( V_7 -> V_17 . V_21 , V_8 , V_11 ) ;
if ( V_9 )
goto V_14;
return 0 ;
V_14:
F_7 ( V_8 ) ;
F_7 ( V_11 ) ;
return V_9 ;
}
static T_1 F_8 ( struct V_22 * V_23 , const void * V_24 )
{
const struct V_25 * V_26 = V_24 ;
unsigned long V_27 ;
unsigned int V_28 ;
unsigned char V_29 ;
V_27 = V_26 -> V_30 ^ V_26 -> V_31 ^ V_26 -> V_32 ;
V_28 = 0 ;
while ( ( V_29 = V_26 -> V_33 [ V_28 ++ ] ) )
V_27 = F_9 ( V_29 , V_27 ) ;
return V_27 & ( V_23 -> V_34 - 1 ) ;
}
static int F_10 ( struct V_22 * V_23 , const void * V_35 , const void * V_36 )
{
const struct V_25 * V_37 = V_35 ;
const struct V_25 * V_38 = V_36 ;
int V_39 ;
V_39 = V_37 -> V_30 - V_38 -> V_30 ;
if ( V_39 )
return V_39 ;
V_39 = V_37 -> V_31 - V_38 -> V_31 ;
if ( V_39 )
return V_39 ;
V_39 = V_37 -> V_32 - V_38 -> V_32 ;
if ( V_39 )
return V_39 ;
return strcmp ( V_37 -> V_33 , V_38 -> V_33 ) ;
}
static T_1 F_11 ( struct V_22 * V_23 , const void * V_24 )
{
const struct V_40 * V_8 = V_24 ;
return ( V_8 -> V_41 + ( V_8 -> V_42 << 3 ) +
( V_8 -> V_43 << 5 ) ) & ( V_23 -> V_34 - 1 ) ;
}
static int F_12 ( struct V_22 * V_23 , const void * V_35 , const void * V_36 )
{
const struct V_40 * V_44 = V_35 , * V_45 = V_36 ;
int V_39 ;
V_39 = V_44 -> V_41 - V_45 -> V_41 ;
if ( V_39 )
return V_39 ;
V_39 = V_44 -> V_42 - V_45 -> V_42 ;
if ( V_39 )
return V_39 ;
V_39 = V_44 -> V_43 - V_45 -> V_43 ;
return V_39 ;
}
static int F_13 ( struct V_6 * V_7 )
{
int V_3 , V_9 ;
memset ( V_7 , 0 , sizeof( * V_7 ) ) ;
for ( V_3 = 0 ; V_3 < V_46 ; V_3 ++ ) {
V_9 = F_14 ( & V_7 -> V_47 [ V_3 ] , V_48 [ V_3 ] ) ;
if ( V_9 )
goto V_14;
}
V_9 = F_15 ( & V_7 -> V_49 ) ;
if ( V_9 )
goto V_14;
V_9 = F_3 ( V_7 ) ;
if ( V_9 )
goto V_14;
V_9 = F_16 ( V_7 ) ;
if ( V_9 )
goto V_14;
V_7 -> V_25 = F_17 ( F_8 , F_10 , ( 1 << 10 ) ) ;
if ( ! V_7 -> V_25 )
goto V_14;
V_7 -> V_50 = F_17 ( F_11 , F_12 , 256 ) ;
if ( ! V_7 -> V_50 )
goto V_14;
F_18 ( & V_7 -> V_51 ) ;
F_18 ( & V_7 -> V_52 ) ;
F_18 ( & V_7 -> V_53 ) ;
return 0 ;
V_14:
F_19 ( V_7 -> V_25 ) ;
F_19 ( V_7 -> V_50 ) ;
for ( V_3 = 0 ; V_3 < V_46 ; V_3 ++ )
F_19 ( V_7 -> V_47 [ V_3 ] . V_21 ) ;
return V_9 ;
}
static int F_20 ( void * V_8 , void * V_54 , void * V_55 )
{
struct V_6 * V_7 ;
struct V_56 * V_57 ;
struct V_58 * V_59 ;
V_57 = V_54 ;
V_7 = V_55 ;
if ( ! V_57 -> V_16 || V_57 -> V_16 > V_7 -> V_60 . V_18 )
return - V_15 ;
V_59 = V_7 -> V_61 [ V_62 ] ;
if ( F_21 ( V_59 , V_57 -> V_16 - 1 , V_8 ,
V_13 | V_63 ) )
F_22 () ;
return 0 ;
}
static int F_23 ( void * V_8 , void * V_54 , void * V_55 )
{
struct V_6 * V_7 ;
struct V_64 * V_65 ;
struct V_58 * V_59 ;
V_65 = V_54 ;
V_7 = V_55 ;
if ( ! V_65 -> V_16 || V_65 -> V_16 > V_7 -> V_66 . V_18 )
return - V_15 ;
V_59 = V_7 -> V_61 [ V_67 ] ;
if ( F_21 ( V_59 , V_65 -> V_16 - 1 , V_8 ,
V_13 | V_63 ) )
F_22 () ;
V_7 -> V_68 [ V_65 -> V_16 - 1 ] = V_65 ;
return 0 ;
}
static int F_24 ( void * V_8 , void * V_54 , void * V_55 )
{
struct V_6 * V_7 ;
struct V_10 * V_11 ;
struct V_58 * V_59 ;
V_11 = V_54 ;
V_7 = V_55 ;
if ( ! V_11 -> V_16
|| V_11 -> V_16 > V_7 -> V_17 . V_18
|| V_11 -> V_69 > V_7 -> V_17 . V_18 )
return - V_15 ;
V_59 = V_7 -> V_61 [ V_70 ] ;
if ( F_21 ( V_59 , V_11 -> V_16 - 1 , V_8 ,
V_13 | V_63 ) )
F_22 () ;
V_7 -> V_71 [ V_11 -> V_16 - 1 ] = V_11 ;
return 0 ;
}
static int F_25 ( void * V_8 , void * V_54 , void * V_55 )
{
struct V_6 * V_7 ;
struct V_72 * V_73 ;
struct V_58 * V_59 ;
V_73 = V_54 ;
V_7 = V_55 ;
if ( V_73 -> V_74 ) {
if ( ! V_73 -> V_16
|| V_73 -> V_16 > V_7 -> V_75 . V_18
|| V_73 -> V_69 > V_7 -> V_75 . V_18 )
return - V_15 ;
V_59 = V_7 -> V_61 [ V_76 ] ;
if ( F_21 ( V_59 , V_73 -> V_16 - 1 , V_8 ,
V_13 | V_63 ) )
F_22 () ;
V_59 = V_7 -> V_77 ;
if ( F_21 ( V_59 , V_73 -> V_16 - 1 , V_73 ,
V_13 | V_63 ) )
F_22 () ;
}
return 0 ;
}
static int F_26 ( void * V_8 , void * V_54 , void * V_55 )
{
struct V_6 * V_7 ;
struct V_78 * V_79 ;
struct V_58 * V_59 ;
V_79 = V_54 ;
V_7 = V_55 ;
if ( ! V_79 -> V_16
|| V_79 -> V_16 > V_7 -> V_80 . V_18
|| V_79 -> V_69 > V_7 -> V_80 . V_18 )
return - V_15 ;
V_59 = V_7 -> V_61 [ V_81 ] ;
if ( F_21 ( V_59 , V_79 -> V_16 - 1 , V_8 ,
V_13 | V_63 ) )
F_22 () ;
V_7 -> V_82 [ V_79 -> V_16 - 1 ] = V_79 ;
return 0 ;
}
static int F_27 ( void * V_8 , void * V_54 , void * V_55 )
{
struct V_6 * V_7 ;
struct V_83 * V_84 ;
struct V_58 * V_59 ;
V_84 = V_54 ;
V_7 = V_55 ;
if ( ! V_84 -> V_85 ) {
if ( ! V_84 -> V_86 -> V_87 ||
V_84 -> V_86 -> V_87 > V_7 -> V_88 . V_18 )
return - V_15 ;
V_59 = V_7 -> V_61 [ V_89 ] ;
if ( F_21 ( V_59 , V_84 -> V_86 -> V_87 - 1 , V_8 ,
V_13 | V_63 ) )
F_22 () ;
}
return 0 ;
}
static int F_28 ( void * V_8 , void * V_54 , void * V_55 )
{
struct V_6 * V_7 ;
struct V_90 * V_91 ;
struct V_58 * V_59 ;
V_91 = V_54 ;
V_7 = V_55 ;
if ( ! V_91 -> V_85 ) {
if ( ! V_91 -> V_16 || V_91 -> V_16 > V_7 -> V_92 . V_18 )
return - V_15 ;
V_59 = V_7 -> V_61 [ V_93 ] ;
if ( F_21 ( V_59 , V_91 -> V_16 - 1 , V_8 ,
V_13 | V_63 ) )
F_22 () ;
}
return 0 ;
}
static void F_29 ( struct V_22 * V_23 , const char * V_94 )
{
struct V_95 V_4 ;
F_30 ( V_23 , & V_4 ) ;
F_31 ( V_96 L_1
L_2 , V_94 , V_23 -> V_97 ,
V_4 . V_98 , V_23 -> V_34 , V_4 . V_99 ) ;
}
static void F_32 ( struct V_47 * V_100 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_46 ; V_3 ++ )
F_29 ( V_100 [ V_3 ] . V_21 , V_101 [ V_3 ] ) ;
}
static inline void F_29 ( struct V_22 * V_23 , char * V_94 )
{
}
static int F_33 ( struct V_6 * V_7 )
{
int V_3 , V_9 ;
F_31 ( V_96 L_3 ,
V_7 -> V_80 . V_18 , V_7 -> V_17 . V_18 , V_7 -> V_75 . V_18 , V_7 -> V_102 . V_18 ) ;
if ( V_7 -> V_103 )
F_31 ( L_4 , V_7 -> V_88 . V_18 ,
V_7 -> V_92 . V_18 ) ;
F_31 ( L_5 ) ;
F_31 ( V_96 L_6 ,
V_7 -> V_66 . V_18 , V_7 -> V_49 . V_97 ) ;
#ifdef F_34
F_35 ( & V_7 -> V_49 , L_7 ) ;
F_32 ( V_7 -> V_47 ) ;
#endif
V_9 = - V_12 ;
V_7 -> V_68 =
F_36 ( V_7 -> V_66 . V_18 * sizeof( * ( V_7 -> V_68 ) ) ,
V_13 ) ;
if ( ! V_7 -> V_68 )
goto V_14;
V_9 = - V_12 ;
V_7 -> V_71 =
F_36 ( V_7 -> V_17 . V_18 * sizeof( * ( V_7 -> V_71 ) ) ,
V_13 ) ;
if ( ! V_7 -> V_71 )
goto V_14;
V_9 = - V_12 ;
V_7 -> V_82 =
F_36 ( V_7 -> V_80 . V_18 * sizeof( * ( V_7 -> V_82 ) ) ,
V_13 ) ;
if ( ! V_7 -> V_82 )
goto V_14;
V_9 = - V_12 ;
V_7 -> V_77 = F_37 ( sizeof( struct V_72 * ) ,
V_7 -> V_75 . V_18 ,
V_13 | V_63 ) ;
if ( ! V_7 -> V_77 )
goto V_14;
V_9 = F_38 ( V_7 -> V_77 , 0 ,
V_7 -> V_75 . V_18 , V_13 | V_63 ) ;
if ( V_9 )
goto V_14;
V_9 = F_39 ( V_7 ) ;
if ( V_9 )
goto V_14;
for ( V_3 = 0 ; V_3 < V_46 ; V_3 ++ ) {
V_9 = - V_12 ;
V_7 -> V_61 [ V_3 ] = F_37 ( sizeof( char * ) ,
V_7 -> V_47 [ V_3 ] . V_18 ,
V_13 | V_63 ) ;
if ( ! V_7 -> V_61 [ V_3 ] )
goto V_14;
V_9 = F_38 ( V_7 -> V_61 [ V_3 ] ,
0 , V_7 -> V_47 [ V_3 ] . V_18 ,
V_13 | V_63 ) ;
if ( V_9 )
goto V_14;
V_9 = F_40 ( V_7 -> V_47 [ V_3 ] . V_21 , V_104 [ V_3 ] , V_7 ) ;
if ( V_9 )
goto V_14;
}
V_9 = 0 ;
V_14:
return V_9 ;
}
static int F_41 ( void * V_8 , void * V_54 , void * V_7 )
{
F_7 ( V_8 ) ;
F_7 ( V_54 ) ;
return 0 ;
}
static int F_42 ( void * V_8 , void * V_54 , void * V_7 )
{
struct V_56 * V_57 ;
F_7 ( V_8 ) ;
if ( V_54 ) {
V_57 = V_54 ;
F_40 ( V_57 -> V_105 . V_21 , F_41 , NULL ) ;
F_19 ( V_57 -> V_105 . V_21 ) ;
}
F_7 ( V_54 ) ;
return 0 ;
}
static void F_43 ( struct V_106 * V_107 )
{
if ( V_107 ) {
F_44 ( & V_107 -> V_108 ) ;
if ( V_107 -> V_109 ) {
F_44 ( & V_107 -> V_109 -> V_110 ) ;
F_44 ( & V_107 -> V_109 -> V_111 ) ;
F_7 ( V_107 -> V_109 ) ;
}
F_7 ( V_107 ) ;
}
}
static int F_45 ( void * V_8 , void * V_54 , void * V_7 )
{
struct V_64 * V_65 ;
struct V_112 * V_113 , * V_114 ;
struct V_106 * V_115 , * V_116 ;
F_7 ( V_8 ) ;
if ( V_54 ) {
V_65 = V_54 ;
F_40 ( V_65 -> V_105 . V_21 , F_41 , NULL ) ;
F_19 ( V_65 -> V_105 . V_21 ) ;
V_113 = V_65 -> V_117 ;
while ( V_113 ) {
V_115 = V_113 -> V_107 ;
while ( V_115 ) {
V_116 = V_115 ;
V_115 = V_115 -> V_118 ;
F_43 ( V_116 ) ;
}
V_114 = V_113 ;
V_113 = V_113 -> V_118 ;
F_7 ( V_114 ) ;
}
V_113 = V_65 -> V_119 ;
while ( V_113 ) {
V_115 = V_113 -> V_107 ;
while ( V_115 ) {
V_116 = V_115 ;
V_115 = V_115 -> V_118 ;
F_43 ( V_116 ) ;
}
V_114 = V_113 ;
V_113 = V_113 -> V_118 ;
F_7 ( V_114 ) ;
}
F_7 ( V_65 -> V_120 ) ;
}
F_7 ( V_54 ) ;
return 0 ;
}
static int F_46 ( void * V_8 , void * V_54 , void * V_7 )
{
struct V_10 * V_11 ;
F_7 ( V_8 ) ;
if ( V_54 ) {
V_11 = V_54 ;
F_44 ( & V_11 -> V_121 ) ;
F_44 ( & V_11 -> V_110 ) ;
}
F_7 ( V_54 ) ;
return 0 ;
}
static int F_47 ( void * V_8 , void * V_54 , void * V_7 )
{
F_7 ( V_8 ) ;
F_7 ( V_54 ) ;
return 0 ;
}
static int F_48 ( void * V_8 , void * V_54 , void * V_7 )
{
struct V_78 * V_79 ;
F_7 ( V_8 ) ;
if ( V_54 ) {
V_79 = V_54 ;
F_44 ( & V_79 -> V_122 ) ;
F_44 ( & V_79 -> V_123 . V_86 [ 0 ] . V_124 ) ;
F_44 ( & V_79 -> V_123 . V_86 [ 1 ] . V_124 ) ;
F_44 ( & V_79 -> V_125 . V_124 ) ;
}
F_7 ( V_54 ) ;
return 0 ;
}
static int F_49 ( void * V_8 , void * V_54 , void * V_7 )
{
struct V_83 * V_84 ;
F_7 ( V_8 ) ;
if ( V_54 ) {
V_84 = V_54 ;
F_44 ( & V_84 -> V_86 -> V_124 ) ;
F_7 ( V_84 -> V_86 ) ;
}
F_7 ( V_54 ) ;
return 0 ;
}
static int F_50 ( void * V_8 , void * V_54 , void * V_7 )
{
F_7 ( V_8 ) ;
F_7 ( V_54 ) ;
return 0 ;
}
static int F_51 ( void * V_8 , void * V_54 , void * V_7 )
{
struct V_25 * V_26 = V_8 ;
F_7 ( V_26 -> V_33 ) ;
F_7 ( V_8 ) ;
F_7 ( V_54 ) ;
F_52 () ;
return 0 ;
}
static int F_53 ( void * V_8 , void * V_54 , void * V_7 )
{
struct V_126 * V_127 = V_54 ;
F_7 ( V_8 ) ;
F_44 ( & V_127 -> V_86 [ 0 ] . V_124 ) ;
F_44 ( & V_127 -> V_86 [ 1 ] . V_124 ) ;
F_7 ( V_54 ) ;
F_52 () ;
return 0 ;
}
static void F_54 ( struct V_128 * V_129 , int V_3 )
{
if ( ! V_129 )
return;
F_55 ( & V_129 -> V_130 [ 0 ] ) ;
F_55 ( & V_129 -> V_130 [ 1 ] ) ;
if ( V_3 == V_131 || V_3 == V_132 ||
V_3 == V_133 || V_3 == V_134 )
F_7 ( V_129 -> V_135 . V_33 ) ;
F_7 ( V_129 ) ;
}
void F_56 ( struct V_6 * V_7 )
{
struct V_128 * V_129 , * V_136 ;
struct V_137 * V_138 , * V_139 ;
int V_3 ;
struct V_140 * V_141 , * V_142 = NULL ;
struct V_143 * V_144 , * V_145 = NULL ;
for ( V_3 = 0 ; V_3 < V_46 ; V_3 ++ ) {
F_52 () ;
F_40 ( V_7 -> V_47 [ V_3 ] . V_21 , V_146 [ V_3 ] , NULL ) ;
F_19 ( V_7 -> V_47 [ V_3 ] . V_21 ) ;
}
for ( V_3 = 0 ; V_3 < V_46 ; V_3 ++ ) {
if ( V_7 -> V_61 [ V_3 ] )
F_57 ( V_7 -> V_61 [ V_3 ] ) ;
}
F_7 ( V_7 -> V_68 ) ;
F_7 ( V_7 -> V_71 ) ;
F_7 ( V_7 -> V_82 ) ;
if ( V_7 -> V_77 )
F_57 ( V_7 -> V_77 ) ;
F_58 ( & V_7 -> V_49 ) ;
for ( V_3 = 0 ; V_3 < V_147 ; V_3 ++ ) {
F_52 () ;
V_129 = V_7 -> V_148 [ V_3 ] ;
while ( V_129 ) {
V_136 = V_129 ;
V_129 = V_129 -> V_118 ;
F_54 ( V_136 , V_3 ) ;
}
V_7 -> V_148 [ V_3 ] = NULL ;
}
V_138 = V_7 -> V_137 ;
while ( V_138 ) {
F_52 () ;
F_7 ( V_138 -> V_149 ) ;
V_129 = V_138 -> V_150 ;
while ( V_129 ) {
V_136 = V_129 ;
V_129 = V_129 -> V_118 ;
F_54 ( V_136 , V_134 ) ;
}
V_139 = V_138 ;
V_138 = V_138 -> V_118 ;
F_7 ( V_139 ) ;
}
V_7 -> V_137 = NULL ;
F_59 ( V_7 ) ;
for ( V_144 = V_7 -> V_151 ; V_144 ; V_144 = V_144 -> V_118 ) {
F_52 () ;
F_7 ( V_145 ) ;
V_145 = V_144 ;
}
F_7 ( V_145 ) ;
for ( V_141 = V_7 -> V_140 ; V_141 ; V_141 = V_141 -> V_118 ) {
F_52 () ;
F_7 ( V_142 ) ;
V_142 = V_141 ;
}
F_7 ( V_142 ) ;
F_40 ( V_7 -> V_25 , F_51 , NULL ) ;
F_19 ( V_7 -> V_25 ) ;
F_40 ( V_7 -> V_50 , F_53 , NULL ) ;
F_19 ( V_7 -> V_50 ) ;
if ( V_7 -> V_152 ) {
for ( V_3 = 0 ; V_3 < V_7 -> V_75 . V_18 ; V_3 ++ ) {
struct V_153 * V_115 ;
V_115 = F_60 ( V_7 -> V_152 , V_3 ) ;
if ( ! V_115 )
continue;
F_44 ( V_115 ) ;
}
F_57 ( V_7 -> V_152 ) ;
}
F_44 ( & V_7 -> V_51 ) ;
F_44 ( & V_7 -> V_52 ) ;
F_44 ( & V_7 -> V_53 ) ;
return;
}
int F_61 ( struct V_6 * V_7 , struct V_154 * V_100 )
{
struct V_128 * V_150 , * V_129 ;
int V_9 ;
V_9 = F_62 ( V_100 ) ;
if ( V_9 ) {
F_31 ( V_155 L_8 ) ;
goto V_14;
}
V_150 = V_7 -> V_148 [ V_131 ] ;
for ( V_129 = V_150 ; V_129 ; V_129 = V_129 -> V_118 ) {
V_9 = - V_15 ;
if ( ! V_129 -> V_130 [ 0 ] . V_156 ) {
F_31 ( V_155 L_9 ,
V_129 -> V_135 . V_33 ) ;
goto V_14;
}
V_9 = F_63 ( V_100 , V_129 -> V_157 [ 0 ] , & V_129 -> V_130 [ 0 ] ) ;
if ( V_9 ) {
F_31 ( V_155 L_10 ,
V_129 -> V_135 . V_33 ) ;
goto V_14;
}
}
V_9 = 0 ;
V_14:
return V_9 ;
}
int F_64 ( struct V_6 * V_7 , unsigned int V_158 )
{
if ( ! V_158 || V_158 > V_7 -> V_66 . V_18 )
return 0 ;
return 1 ;
}
int F_65 ( struct V_6 * V_7 , unsigned int V_11 )
{
if ( ! V_11 || V_11 > V_7 -> V_17 . V_18 )
return 0 ;
return 1 ;
}
int F_66 ( struct V_6 * V_7 , unsigned int type )
{
if ( ! type || type > V_7 -> V_75 . V_18 )
return 0 ;
return 1 ;
}
int F_67 ( struct V_6 * V_7 , struct V_130 * V_129 )
{
struct V_10 * V_11 ;
struct V_78 * V_79 ;
if ( ! V_129 -> V_11 || V_129 -> V_11 > V_7 -> V_17 . V_18 )
return 0 ;
if ( ! V_129 -> V_156 || V_129 -> V_156 > V_7 -> V_80 . V_18 )
return 0 ;
if ( ! V_129 -> type || V_129 -> type > V_7 -> V_75 . V_18 )
return 0 ;
if ( V_129 -> V_11 != V_19 ) {
V_11 = V_7 -> V_71 [ V_129 -> V_11 - 1 ] ;
if ( ! F_68 ( & V_11 -> V_110 , V_129 -> type - 1 ) )
return 0 ;
V_79 = V_7 -> V_82 [ V_129 -> V_156 - 1 ] ;
if ( ! V_79 )
return 0 ;
if ( ! F_68 ( & V_79 -> V_122 , V_129 -> V_11 - 1 ) )
return 0 ;
}
if ( ! F_69 ( V_7 , V_129 ) )
return 0 ;
return 1 ;
}
static int F_70 ( struct V_126 * V_159 , void * V_160 )
{
T_2 V_161 [ 2 ] ;
T_1 V_162 ;
int V_9 ;
V_9 = F_71 ( V_161 , V_160 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_14;
V_9 = - V_15 ;
V_162 = F_72 ( V_161 [ 0 ] ) ;
if ( V_162 > F_2 ( V_161 ) ) {
F_31 ( V_155 L_11 ) ;
goto V_14;
}
V_9 = F_71 ( V_161 , V_160 , sizeof( T_1 ) * V_162 ) ;
if ( V_9 ) {
F_31 ( V_155 L_12 ) ;
goto V_14;
}
V_159 -> V_86 [ 0 ] . V_87 = F_72 ( V_161 [ 0 ] ) ;
if ( V_162 > 1 )
V_159 -> V_86 [ 1 ] . V_87 = F_72 ( V_161 [ 1 ] ) ;
else
V_159 -> V_86 [ 1 ] . V_87 = V_159 -> V_86 [ 0 ] . V_87 ;
V_9 = F_73 ( & V_159 -> V_86 [ 0 ] . V_124 , V_160 ) ;
if ( V_9 ) {
F_31 ( V_155 L_13 ) ;
goto V_14;
}
if ( V_162 > 1 ) {
V_9 = F_73 ( & V_159 -> V_86 [ 1 ] . V_124 , V_160 ) ;
if ( V_9 ) {
F_31 ( V_155 L_14 ) ;
goto V_163;
}
} else {
V_9 = F_74 ( & V_159 -> V_86 [ 1 ] . V_124 , & V_159 -> V_86 [ 0 ] . V_124 ) ;
if ( V_9 ) {
F_31 ( V_155 L_15 ) ;
goto V_163;
}
}
return 0 ;
V_163:
F_44 ( & V_159 -> V_86 [ 0 ] . V_124 ) ;
V_14:
return V_9 ;
}
static int F_75 ( struct V_130 * V_129 ,
struct V_6 * V_7 ,
void * V_160 )
{
T_2 V_161 [ 3 ] ;
int V_9 ;
V_9 = F_71 ( V_161 , V_160 , sizeof V_161 ) ;
if ( V_9 ) {
F_31 ( V_155 L_16 ) ;
goto V_14;
}
V_129 -> V_156 = F_72 ( V_161 [ 0 ] ) ;
V_129 -> V_11 = F_72 ( V_161 [ 1 ] ) ;
V_129 -> type = F_72 ( V_161 [ 2 ] ) ;
if ( V_7 -> V_164 >= V_165 ) {
V_9 = F_70 ( & V_129 -> V_123 , V_160 ) ;
if ( V_9 ) {
F_31 ( V_155 L_17 ) ;
goto V_14;
}
}
V_9 = - V_15 ;
if ( ! F_67 ( V_7 , V_129 ) ) {
F_31 ( V_155 L_18 ) ;
F_55 ( V_129 ) ;
goto V_14;
}
V_9 = 0 ;
V_14:
return V_9 ;
}
static int F_76 ( struct V_6 * V_7 , struct V_22 * V_23 , void * V_160 )
{
char * V_8 = NULL ;
struct V_166 * V_167 ;
int V_9 ;
T_2 V_161 [ 2 ] ;
T_1 V_168 ;
V_9 = - V_12 ;
V_167 = F_4 ( sizeof( * V_167 ) , V_13 ) ;
if ( ! V_167 )
goto V_169;
V_9 = F_71 ( V_161 , V_160 , sizeof V_161 ) ;
if ( V_9 )
goto V_169;
V_168 = F_72 ( V_161 [ 0 ] ) ;
V_167 -> V_16 = F_72 ( V_161 [ 1 ] ) ;
V_9 = - V_12 ;
V_8 = F_36 ( V_168 + 1 , V_13 ) ;
if ( ! V_8 )
goto V_169;
V_9 = F_71 ( V_8 , V_160 , V_168 ) ;
if ( V_9 )
goto V_169;
V_8 [ V_168 ] = '\0' ;
V_9 = F_6 ( V_23 , V_8 , V_167 ) ;
if ( V_9 )
goto V_169;
return 0 ;
V_169:
F_41 ( V_8 , V_167 , NULL ) ;
return V_9 ;
}
static int F_77 ( struct V_6 * V_7 , struct V_22 * V_23 , void * V_160 )
{
char * V_8 = NULL ;
struct V_56 * V_57 ;
T_2 V_161 [ 4 ] ;
T_1 V_168 , V_97 ;
int V_3 , V_9 ;
V_9 = - V_12 ;
V_57 = F_4 ( sizeof( * V_57 ) , V_13 ) ;
if ( ! V_57 )
goto V_169;
V_9 = F_71 ( V_161 , V_160 , sizeof V_161 ) ;
if ( V_9 )
goto V_169;
V_168 = F_72 ( V_161 [ 0 ] ) ;
V_57 -> V_16 = F_72 ( V_161 [ 1 ] ) ;
V_9 = F_14 ( & V_57 -> V_105 , V_170 ) ;
if ( V_9 )
goto V_169;
V_57 -> V_105 . V_18 = F_72 ( V_161 [ 2 ] ) ;
V_97 = F_72 ( V_161 [ 3 ] ) ;
V_9 = - V_12 ;
V_8 = F_36 ( V_168 + 1 , V_13 ) ;
if ( ! V_8 )
goto V_169;
V_9 = F_71 ( V_8 , V_160 , V_168 ) ;
if ( V_9 )
goto V_169;
V_8 [ V_168 ] = '\0' ;
for ( V_3 = 0 ; V_3 < V_97 ; V_3 ++ ) {
V_9 = F_76 ( V_7 , V_57 -> V_105 . V_21 , V_160 ) ;
if ( V_9 )
goto V_169;
}
V_9 = F_6 ( V_23 , V_8 , V_57 ) ;
if ( V_9 )
goto V_169;
return 0 ;
V_169:
F_42 ( V_8 , V_57 , NULL ) ;
return V_9 ;
}
static void F_78 ( struct V_171 * V_172 )
{
F_18 ( & V_172 -> V_110 ) ;
F_18 ( & V_172 -> V_111 ) ;
}
static int F_79 ( struct V_171 * V_172 , void * V_160 )
{
T_2 V_161 [ 1 ] ;
int V_9 ;
if ( F_73 ( & V_172 -> V_110 , V_160 ) )
return - V_15 ;
if ( F_73 ( & V_172 -> V_111 , V_160 ) )
return - V_15 ;
V_9 = F_71 ( V_161 , V_160 , sizeof( T_1 ) ) ;
if ( V_9 < 0 )
return - V_15 ;
V_172 -> V_173 = F_72 ( V_161 [ 0 ] ) ;
return 0 ;
}
static int F_80 ( struct V_6 * V_7 ,
struct V_112 * * V_174 ,
int V_175 , int V_176 , void * V_160 )
{
struct V_112 * V_129 , * V_177 ;
struct V_106 * V_115 , * V_178 ;
T_2 V_161 [ 3 ] ;
T_1 V_179 ;
int V_9 , V_3 , V_180 , V_181 ;
V_177 = NULL ;
for ( V_3 = 0 ; V_3 < V_175 ; V_3 ++ ) {
V_129 = F_4 ( sizeof( * V_129 ) , V_13 ) ;
if ( ! V_129 )
return - V_12 ;
if ( V_177 )
V_177 -> V_118 = V_129 ;
else
* V_174 = V_129 ;
V_9 = F_71 ( V_161 , V_160 , ( sizeof( T_1 ) * 2 ) ) ;
if ( V_9 )
return V_9 ;
V_129 -> V_105 = F_72 ( V_161 [ 0 ] ) ;
V_179 = F_72 ( V_161 [ 1 ] ) ;
V_178 = NULL ;
V_181 = - 1 ;
for ( V_180 = 0 ; V_180 < V_179 ; V_180 ++ ) {
V_115 = F_4 ( sizeof( * V_115 ) , V_13 ) ;
if ( ! V_115 )
return - V_12 ;
if ( V_178 )
V_178 -> V_118 = V_115 ;
else
V_129 -> V_107 = V_115 ;
V_9 = F_71 ( V_161 , V_160 , ( sizeof( T_1 ) * 3 ) ) ;
if ( V_9 )
return V_9 ;
V_115 -> V_182 = F_72 ( V_161 [ 0 ] ) ;
V_115 -> V_183 = F_72 ( V_161 [ 1 ] ) ;
V_115 -> V_184 = F_72 ( V_161 [ 2 ] ) ;
switch ( V_115 -> V_182 ) {
case V_185 :
if ( V_181 < 0 )
return - V_15 ;
break;
case V_186 :
case V_187 :
if ( V_181 < 1 )
return - V_15 ;
V_181 -- ;
break;
case V_188 :
if ( V_181 == ( V_189 - 1 ) )
return - V_15 ;
V_181 ++ ;
break;
case V_190 :
if ( ! V_176 && ( V_115 -> V_183 & V_191 ) )
return - V_15 ;
if ( V_181 == ( V_189 - 1 ) )
return - V_15 ;
V_181 ++ ;
V_9 = F_73 ( & V_115 -> V_108 , V_160 ) ;
if ( V_9 )
return V_9 ;
if ( V_7 -> V_164 >=
V_192 ) {
V_115 -> V_109 = F_4 ( sizeof
( * V_115 -> V_109 ) ,
V_13 ) ;
if ( ! V_115 -> V_109 )
return - V_12 ;
F_78 ( V_115 -> V_109 ) ;
V_9 = F_79 ( V_115 -> V_109 , V_160 ) ;
if ( V_9 )
return V_9 ;
}
break;
default:
return - V_15 ;
}
V_178 = V_115 ;
}
if ( V_181 != 0 )
return - V_15 ;
V_177 = V_129 ;
}
return 0 ;
}
static int F_81 ( struct V_6 * V_7 , struct V_22 * V_23 , void * V_160 )
{
char * V_8 = NULL ;
struct V_64 * V_65 ;
T_2 V_161 [ 6 ] ;
T_1 V_168 , V_193 , V_175 , V_97 ;
int V_3 , V_9 ;
V_9 = - V_12 ;
V_65 = F_4 ( sizeof( * V_65 ) , V_13 ) ;
if ( ! V_65 )
goto V_169;
V_9 = F_71 ( V_161 , V_160 , sizeof( T_1 ) * 6 ) ;
if ( V_9 )
goto V_169;
V_168 = F_72 ( V_161 [ 0 ] ) ;
V_193 = F_72 ( V_161 [ 1 ] ) ;
V_65 -> V_16 = F_72 ( V_161 [ 2 ] ) ;
V_9 = F_14 ( & V_65 -> V_105 , V_170 ) ;
if ( V_9 )
goto V_169;
V_65 -> V_105 . V_18 = F_72 ( V_161 [ 3 ] ) ;
V_97 = F_72 ( V_161 [ 4 ] ) ;
V_175 = F_72 ( V_161 [ 5 ] ) ;
V_9 = - V_12 ;
V_8 = F_36 ( V_168 + 1 , V_13 ) ;
if ( ! V_8 )
goto V_169;
V_9 = F_71 ( V_8 , V_160 , V_168 ) ;
if ( V_9 )
goto V_169;
V_8 [ V_168 ] = '\0' ;
if ( V_193 ) {
V_9 = - V_12 ;
V_65 -> V_120 = F_36 ( V_193 + 1 , V_13 ) ;
if ( ! V_65 -> V_120 )
goto V_169;
V_9 = F_71 ( V_65 -> V_120 , V_160 , V_193 ) ;
if ( V_9 )
goto V_169;
V_65 -> V_120 [ V_193 ] = '\0' ;
V_9 = - V_15 ;
V_65 -> V_57 = F_82 ( V_7 -> V_60 . V_21 , V_65 -> V_120 ) ;
if ( ! V_65 -> V_57 ) {
F_31 ( V_155 L_19 , V_65 -> V_120 ) ;
goto V_169;
}
}
for ( V_3 = 0 ; V_3 < V_97 ; V_3 ++ ) {
V_9 = F_76 ( V_7 , V_65 -> V_105 . V_21 , V_160 ) ;
if ( V_9 )
goto V_169;
}
V_9 = F_80 ( V_7 , & V_65 -> V_117 , V_175 , 0 , V_160 ) ;
if ( V_9 )
goto V_169;
if ( V_7 -> V_164 >= V_194 ) {
V_9 = F_71 ( V_161 , V_160 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_169;
V_175 = F_72 ( V_161 [ 0 ] ) ;
V_9 = F_80 ( V_7 , & V_65 -> V_119 ,
V_175 , 1 , V_160 ) ;
if ( V_9 )
goto V_169;
}
if ( V_7 -> V_164 >= V_195 ) {
V_9 = F_71 ( V_161 , V_160 , sizeof( T_1 ) * 3 ) ;
if ( V_9 )
goto V_169;
V_65 -> V_196 = F_72 ( V_161 [ 0 ] ) ;
V_65 -> V_197 = F_72 ( V_161 [ 1 ] ) ;
V_65 -> V_198 = F_72 ( V_161 [ 2 ] ) ;
}
if ( V_7 -> V_164 >= V_199 ) {
V_9 = F_71 ( V_161 , V_160 , sizeof( T_1 ) * 1 ) ;
if ( V_9 )
goto V_169;
V_65 -> V_200 = F_72 ( V_161 [ 0 ] ) ;
}
V_9 = F_6 ( V_23 , V_8 , V_65 ) ;
if ( V_9 )
goto V_169;
return 0 ;
V_169:
F_45 ( V_8 , V_65 , NULL ) ;
return V_9 ;
}
static int F_83 ( struct V_6 * V_7 , struct V_22 * V_23 , void * V_160 )
{
char * V_8 = NULL ;
struct V_10 * V_11 ;
int V_9 , V_201 = 2 ;
T_2 V_161 [ 3 ] ;
T_1 V_168 ;
V_9 = - V_12 ;
V_11 = F_4 ( sizeof( * V_11 ) , V_13 ) ;
if ( ! V_11 )
goto V_169;
if ( V_7 -> V_164 >= V_202 )
V_201 = 3 ;
V_9 = F_71 ( V_161 , V_160 , sizeof( V_161 [ 0 ] ) * V_201 ) ;
if ( V_9 )
goto V_169;
V_168 = F_72 ( V_161 [ 0 ] ) ;
V_11 -> V_16 = F_72 ( V_161 [ 1 ] ) ;
if ( V_7 -> V_164 >= V_202 )
V_11 -> V_69 = F_72 ( V_161 [ 2 ] ) ;
V_9 = - V_12 ;
V_8 = F_36 ( V_168 + 1 , V_13 ) ;
if ( ! V_8 )
goto V_169;
V_9 = F_71 ( V_8 , V_160 , V_168 ) ;
if ( V_9 )
goto V_169;
V_8 [ V_168 ] = '\0' ;
V_9 = F_73 ( & V_11 -> V_121 , V_160 ) ;
if ( V_9 )
goto V_169;
V_9 = F_73 ( & V_11 -> V_110 , V_160 ) ;
if ( V_9 )
goto V_169;
if ( strcmp ( V_8 , V_20 ) == 0 ) {
V_9 = - V_15 ;
if ( V_11 -> V_16 != V_19 ) {
F_31 ( V_155 L_20 ,
V_20 , V_11 -> V_16 ) ;
goto V_169;
}
V_9 = 0 ;
goto V_169;
}
V_9 = F_6 ( V_23 , V_8 , V_11 ) ;
if ( V_9 )
goto V_169;
return 0 ;
V_169:
F_46 ( V_8 , V_11 , NULL ) ;
return V_9 ;
}
static int F_84 ( struct V_6 * V_7 , struct V_22 * V_23 , void * V_160 )
{
char * V_8 = NULL ;
struct V_72 * V_73 ;
int V_9 , V_201 = 3 ;
T_2 V_161 [ 4 ] ;
T_1 V_168 ;
V_9 = - V_12 ;
V_73 = F_4 ( sizeof( * V_73 ) , V_13 ) ;
if ( ! V_73 )
goto V_169;
if ( V_7 -> V_164 >= V_202 )
V_201 = 4 ;
V_9 = F_71 ( V_161 , V_160 , sizeof( V_161 [ 0 ] ) * V_201 ) ;
if ( V_9 )
goto V_169;
V_168 = F_72 ( V_161 [ 0 ] ) ;
V_73 -> V_16 = F_72 ( V_161 [ 1 ] ) ;
if ( V_7 -> V_164 >= V_202 ) {
T_1 V_203 = F_72 ( V_161 [ 2 ] ) ;
if ( V_203 & V_204 )
V_73 -> V_74 = 1 ;
if ( V_203 & V_205 )
V_73 -> V_206 = 1 ;
V_73 -> V_69 = F_72 ( V_161 [ 3 ] ) ;
} else {
V_73 -> V_74 = F_72 ( V_161 [ 2 ] ) ;
}
V_9 = - V_12 ;
V_8 = F_36 ( V_168 + 1 , V_13 ) ;
if ( ! V_8 )
goto V_169;
V_9 = F_71 ( V_8 , V_160 , V_168 ) ;
if ( V_9 )
goto V_169;
V_8 [ V_168 ] = '\0' ;
V_9 = F_6 ( V_23 , V_8 , V_73 ) ;
if ( V_9 )
goto V_169;
return 0 ;
V_169:
F_47 ( V_8 , V_73 , NULL ) ;
return V_9 ;
}
static int F_85 ( struct V_207 * V_208 , void * V_160 )
{
T_2 V_161 [ 1 ] ;
int V_9 ;
memset ( V_208 , 0 , sizeof( * V_208 ) ) ;
V_9 = F_71 ( V_161 , V_160 , sizeof V_161 ) ;
if ( V_9 ) {
F_31 ( V_155 L_21 ) ;
return V_9 ;
}
V_208 -> V_87 = F_72 ( V_161 [ 0 ] ) ;
V_9 = F_73 ( & V_208 -> V_124 , V_160 ) ;
if ( V_9 ) {
F_31 ( V_155 L_22 ) ;
return V_9 ;
}
return 0 ;
}
static int F_86 ( struct V_6 * V_7 , struct V_22 * V_23 , void * V_160 )
{
char * V_8 = NULL ;
struct V_78 * V_79 ;
int V_9 , V_201 = 2 ;
T_2 V_161 [ 3 ] ;
T_1 V_168 ;
V_9 = - V_12 ;
V_79 = F_4 ( sizeof( * V_79 ) , V_13 ) ;
if ( ! V_79 )
goto V_169;
if ( V_7 -> V_164 >= V_202 )
V_201 = 3 ;
V_9 = F_71 ( V_161 , V_160 , sizeof( V_161 [ 0 ] ) * V_201 ) ;
if ( V_9 )
goto V_169;
V_168 = F_72 ( V_161 [ 0 ] ) ;
V_79 -> V_16 = F_72 ( V_161 [ 1 ] ) ;
if ( V_7 -> V_164 >= V_202 )
V_79 -> V_69 = F_72 ( V_161 [ 2 ] ) ;
V_9 = - V_12 ;
V_8 = F_36 ( V_168 + 1 , V_13 ) ;
if ( ! V_8 )
goto V_169;
V_9 = F_71 ( V_8 , V_160 , V_168 ) ;
if ( V_9 )
goto V_169;
V_8 [ V_168 ] = '\0' ;
V_9 = F_73 ( & V_79 -> V_122 , V_160 ) ;
if ( V_9 )
goto V_169;
if ( V_7 -> V_164 >= V_165 ) {
V_9 = F_70 ( & V_79 -> V_123 , V_160 ) ;
if ( V_9 )
goto V_169;
V_9 = F_85 ( & V_79 -> V_125 , V_160 ) ;
if ( V_9 )
goto V_169;
}
V_9 = F_6 ( V_23 , V_8 , V_79 ) ;
if ( V_9 )
goto V_169;
return 0 ;
V_169:
F_48 ( V_8 , V_79 , NULL ) ;
return V_9 ;
}
static int F_87 ( struct V_6 * V_7 , struct V_22 * V_23 , void * V_160 )
{
char * V_8 = NULL ;
struct V_83 * V_84 ;
int V_9 ;
T_2 V_161 [ 2 ] ;
T_1 V_168 ;
V_9 = - V_12 ;
V_84 = F_4 ( sizeof( * V_84 ) , V_209 ) ;
if ( ! V_84 )
goto V_169;
V_9 = F_71 ( V_161 , V_160 , sizeof V_161 ) ;
if ( V_9 )
goto V_169;
V_168 = F_72 ( V_161 [ 0 ] ) ;
V_84 -> V_85 = F_72 ( V_161 [ 1 ] ) ;
V_9 = - V_12 ;
V_8 = F_36 ( V_168 + 1 , V_209 ) ;
if ( ! V_8 )
goto V_169;
V_9 = F_71 ( V_8 , V_160 , V_168 ) ;
if ( V_9 )
goto V_169;
V_8 [ V_168 ] = '\0' ;
V_9 = - V_12 ;
V_84 -> V_86 = F_36 ( sizeof( struct V_207 ) , V_209 ) ;
if ( ! V_84 -> V_86 )
goto V_169;
V_9 = F_85 ( V_84 -> V_86 , V_160 ) ;
if ( V_9 )
goto V_169;
V_9 = F_6 ( V_23 , V_8 , V_84 ) ;
if ( V_9 )
goto V_169;
return 0 ;
V_169:
F_49 ( V_8 , V_84 , NULL ) ;
return V_9 ;
}
static int F_88 ( struct V_6 * V_7 , struct V_22 * V_23 , void * V_160 )
{
char * V_8 = NULL ;
struct V_90 * V_91 ;
int V_9 ;
T_2 V_161 [ 3 ] ;
T_1 V_168 ;
V_9 = - V_12 ;
V_91 = F_4 ( sizeof( * V_91 ) , V_209 ) ;
if ( ! V_91 )
goto V_169;
V_9 = F_71 ( V_161 , V_160 , sizeof V_161 ) ;
if ( V_9 )
goto V_169;
V_168 = F_72 ( V_161 [ 0 ] ) ;
V_91 -> V_16 = F_72 ( V_161 [ 1 ] ) ;
V_91 -> V_85 = F_72 ( V_161 [ 2 ] ) ;
V_9 = - V_12 ;
V_8 = F_36 ( V_168 + 1 , V_209 ) ;
if ( ! V_8 )
goto V_169;
V_9 = F_71 ( V_8 , V_160 , V_168 ) ;
if ( V_9 )
goto V_169;
V_8 [ V_168 ] = '\0' ;
V_9 = F_6 ( V_23 , V_8 , V_91 ) ;
if ( V_9 )
goto V_169;
return 0 ;
V_169:
F_50 ( V_8 , V_91 , NULL ) ;
return V_9 ;
}
static int F_89 ( void * V_8 , void * V_54 , void * V_55 )
{
struct V_78 * V_210 , * V_156 ;
struct V_6 * V_7 = V_55 ;
int V_181 = 0 ;
V_210 = V_156 = V_54 ;
while ( V_210 -> V_69 ) {
struct V_211 * V_212 ;
unsigned long V_213 ;
if ( ++ V_181 == V_214 ) {
F_31 ( V_155 L_23
L_24 ,
( char * ) V_8 ) ;
return - V_15 ;
}
V_210 = V_7 -> V_82 [ V_210 -> V_69 - 1 ] ;
F_90 (&user->roles, node, bit) {
if ( F_68 ( & V_210 -> V_122 , V_213 ) )
continue;
F_31 ( V_155
L_25
L_26 ,
F_91 ( V_7 , V_81 , V_156 -> V_16 - 1 ) ,
F_91 ( V_7 , V_70 , V_213 ) ,
F_91 ( V_7 , V_81 , V_210 -> V_16 - 1 ) ) ;
return - V_15 ;
}
}
return 0 ;
}
static int F_92 ( void * V_8 , void * V_54 , void * V_55 )
{
struct V_10 * V_210 , * V_11 ;
struct V_6 * V_7 = V_55 ;
int V_181 = 0 ;
V_210 = V_11 = V_54 ;
while ( V_210 -> V_69 ) {
struct V_211 * V_212 ;
unsigned long V_213 ;
if ( ++ V_181 == V_214 ) {
F_31 ( V_155 L_27
L_28 ,
( char * ) V_8 ) ;
return - V_15 ;
}
V_210 = V_7 -> V_71 [ V_210 -> V_69 - 1 ] ;
F_90 (&role->types, node, bit) {
if ( F_68 ( & V_210 -> V_110 , V_213 ) )
continue;
F_31 ( V_155
L_25
L_29 ,
F_91 ( V_7 , V_70 , V_11 -> V_16 - 1 ) ,
F_91 ( V_7 , V_76 , V_213 ) ,
F_91 ( V_7 , V_70 , V_210 -> V_16 - 1 ) ) ;
return - V_15 ;
}
}
return 0 ;
}
static int F_93 ( void * V_8 , void * V_54 , void * V_55 )
{
struct V_72 * V_210 ;
struct V_6 * V_7 = V_55 ;
int V_181 = 0 ;
V_210 = V_54 ;
while ( V_210 -> V_69 ) {
if ( ++ V_181 == V_214 ) {
F_31 ( V_155 L_30
L_31 ,
( char * ) V_8 ) ;
return - V_15 ;
}
V_210 = F_94 ( V_7 -> V_77 ,
V_210 -> V_69 - 1 ) ;
F_95 ( ! V_210 ) ;
if ( V_210 -> V_206 ) {
F_31 ( V_155 L_30
L_32 ,
( char * ) V_8 ,
F_91 ( V_7 , V_76 , V_210 -> V_16 - 1 ) ) ;
return - V_15 ;
}
}
return 0 ;
}
static int F_96 ( struct V_6 * V_7 )
{
int V_9 ;
if ( V_7 -> V_164 < V_202 )
return 0 ;
V_9 = F_40 ( V_7 -> V_80 . V_21 ,
F_89 , V_7 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_40 ( V_7 -> V_17 . V_21 ,
F_92 , V_7 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_40 ( V_7 -> V_75 . V_21 ,
F_93 , V_7 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
T_3 F_97 ( struct V_6 * V_7 , const char * V_33 )
{
struct V_64 * V_65 ;
V_65 = F_82 ( V_7 -> V_66 . V_21 , V_33 ) ;
if ( ! V_65 )
return 0 ;
return V_65 -> V_16 ;
}
T_1 F_98 ( struct V_6 * V_7 , T_3 V_32 , const char * V_33 )
{
struct V_64 * V_65 ;
struct V_166 * V_167 = NULL ;
struct V_56 * V_57 ;
if ( ! V_32 || V_32 > V_7 -> V_66 . V_18 )
return 0 ;
V_65 = V_7 -> V_68 [ V_32 - 1 ] ;
V_57 = V_65 -> V_57 ;
if ( V_57 )
V_167 = F_82 ( V_57 -> V_105 . V_21 ,
V_33 ) ;
if ( ! V_167 )
V_167 = F_82 ( V_65 -> V_105 . V_21 ,
V_33 ) ;
if ( ! V_167 )
return 0 ;
return 1U << ( V_167 -> V_16 - 1 ) ;
}
static int F_99 ( struct V_6 * V_7 , void * V_160 )
{
struct V_40 * V_127 = NULL ;
struct V_126 * V_159 = NULL ;
int V_3 , V_9 ;
T_2 V_161 [ 2 ] ;
T_1 V_97 ;
if ( V_7 -> V_164 < V_165 )
return 0 ;
V_9 = F_71 ( V_161 , V_160 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_14;
V_97 = F_72 ( V_161 [ 0 ] ) ;
for ( V_3 = 0 ; V_3 < V_97 ; V_3 ++ ) {
V_9 = - V_12 ;
V_127 = F_4 ( sizeof( * V_127 ) , V_13 ) ;
if ( ! V_127 )
goto V_14;
V_9 = F_71 ( V_161 , V_160 , ( sizeof( T_1 ) * 2 ) ) ;
if ( V_9 )
goto V_14;
V_127 -> V_41 = F_72 ( V_161 [ 0 ] ) ;
V_127 -> V_42 = F_72 ( V_161 [ 1 ] ) ;
if ( V_7 -> V_164 >= V_215 ) {
V_9 = F_71 ( V_161 , V_160 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_14;
V_127 -> V_43 = F_72 ( V_161 [ 0 ] ) ;
} else
V_127 -> V_43 = V_7 -> V_216 ;
V_9 = - V_15 ;
if ( ! F_66 ( V_7 , V_127 -> V_41 ) ||
! F_66 ( V_7 , V_127 -> V_42 ) ||
! F_64 ( V_7 , V_127 -> V_43 ) )
goto V_14;
V_9 = - V_12 ;
V_159 = F_4 ( sizeof( * V_159 ) , V_13 ) ;
if ( ! V_159 )
goto V_14;
V_9 = F_70 ( V_159 , V_160 ) ;
if ( V_9 )
goto V_14;
V_9 = - V_15 ;
if ( ! F_100 ( V_7 , V_159 ) ) {
F_31 ( V_217 L_33 ) ;
goto V_14;
}
V_9 = F_6 ( V_7 -> V_50 , V_127 , V_159 ) ;
if ( V_9 )
goto V_14;
V_127 = NULL ;
V_159 = NULL ;
}
F_29 ( V_7 -> V_50 , L_34 ) ;
V_9 = 0 ;
V_14:
F_7 ( V_127 ) ;
F_7 ( V_159 ) ;
return V_9 ;
}
static int F_101 ( struct V_6 * V_7 , void * V_160 )
{
struct V_25 * V_26 ;
struct V_218 * V_219 ;
char * V_33 ;
T_1 V_97 , V_168 ;
T_2 V_161 [ 4 ] ;
int V_9 , V_3 ;
if ( V_7 -> V_164 < V_220 )
return 0 ;
V_9 = F_71 ( V_161 , V_160 , sizeof( T_1 ) ) ;
if ( V_9 )
return V_9 ;
V_97 = F_72 ( V_161 [ 0 ] ) ;
for ( V_3 = 0 ; V_3 < V_97 ; V_3 ++ ) {
V_26 = NULL ;
V_219 = NULL ;
V_33 = NULL ;
V_9 = - V_12 ;
V_26 = F_4 ( sizeof( * V_26 ) , V_13 ) ;
if ( ! V_26 )
goto V_14;
V_9 = - V_12 ;
V_219 = F_36 ( sizeof( * V_219 ) , V_13 ) ;
if ( ! V_219 )
goto V_14;
V_9 = F_71 ( V_161 , V_160 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_14;
V_168 = F_72 ( V_161 [ 0 ] ) ;
V_9 = - V_12 ;
V_33 = F_36 ( V_168 + 1 , V_13 ) ;
if ( ! V_33 )
goto V_14;
V_26 -> V_33 = V_33 ;
V_9 = F_71 ( V_33 , V_160 , V_168 ) ;
if ( V_9 )
goto V_14;
V_33 [ V_168 ] = 0 ;
V_9 = F_71 ( V_161 , V_160 , sizeof( T_1 ) * 4 ) ;
if ( V_9 )
goto V_14;
V_26 -> V_30 = F_72 ( V_161 [ 0 ] ) ;
V_26 -> V_31 = F_72 ( V_161 [ 1 ] ) ;
V_26 -> V_32 = F_72 ( V_161 [ 2 ] ) ;
V_219 -> V_219 = F_72 ( V_161 [ 3 ] ) ;
V_9 = F_102 ( & V_7 -> V_51 , V_26 -> V_31 , 1 ) ;
if ( V_9 )
goto V_14;
V_9 = F_6 ( V_7 -> V_25 , V_26 , V_219 ) ;
if ( V_9 ) {
if ( V_9 != - V_221 )
goto V_14;
F_7 ( V_26 ) ;
F_7 ( V_33 ) ;
F_7 ( V_219 ) ;
}
}
F_29 ( V_7 -> V_25 , L_35 ) ;
return 0 ;
V_14:
F_7 ( V_26 ) ;
F_7 ( V_33 ) ;
F_7 ( V_219 ) ;
return V_9 ;
}
static int F_103 ( struct V_6 * V_7 , void * V_160 )
{
int V_3 , V_180 , V_9 ;
T_1 V_97 , V_222 , V_168 , V_193 ;
T_2 V_161 [ 1 ] ;
struct V_128 * V_223 , * V_129 ;
struct V_128 * V_224 = NULL ;
struct V_137 * V_225 , * V_137 ;
struct V_137 * V_226 = NULL ;
V_9 = F_71 ( V_161 , V_160 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_14;
V_97 = F_72 ( V_161 [ 0 ] ) ;
for ( V_3 = 0 ; V_3 < V_97 ; V_3 ++ ) {
V_9 = F_71 ( V_161 , V_160 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_14;
V_168 = F_72 ( V_161 [ 0 ] ) ;
V_9 = - V_12 ;
V_226 = F_4 ( sizeof( * V_226 ) , V_13 ) ;
if ( ! V_226 )
goto V_14;
V_9 = - V_12 ;
V_226 -> V_149 = F_36 ( V_168 + 1 , V_13 ) ;
if ( ! V_226 -> V_149 )
goto V_14;
V_9 = F_71 ( V_226 -> V_149 , V_160 , V_168 ) ;
if ( V_9 )
goto V_14;
V_226 -> V_149 [ V_168 ] = 0 ;
for ( V_225 = NULL , V_137 = V_7 -> V_137 ; V_137 ;
V_225 = V_137 , V_137 = V_137 -> V_118 ) {
V_9 = - V_15 ;
if ( strcmp ( V_226 -> V_149 , V_137 -> V_149 ) == 0 ) {
F_31 ( V_155 L_36 ,
V_226 -> V_149 ) ;
goto V_14;
}
if ( strcmp ( V_226 -> V_149 , V_137 -> V_149 ) < 0 )
break;
}
V_226 -> V_118 = V_137 ;
if ( V_225 )
V_225 -> V_118 = V_226 ;
else
V_7 -> V_137 = V_226 ;
V_137 = V_226 ;
V_226 = NULL ;
V_9 = F_71 ( V_161 , V_160 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_14;
V_222 = F_72 ( V_161 [ 0 ] ) ;
for ( V_180 = 0 ; V_180 < V_222 ; V_180 ++ ) {
V_9 = F_71 ( V_161 , V_160 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_14;
V_168 = F_72 ( V_161 [ 0 ] ) ;
V_9 = - V_12 ;
V_224 = F_4 ( sizeof( * V_224 ) , V_13 ) ;
if ( ! V_224 )
goto V_14;
V_9 = - V_12 ;
V_224 -> V_135 . V_33 = F_36 ( V_168 + 1 , V_13 ) ;
if ( ! V_224 -> V_135 . V_33 )
goto V_14;
V_9 = F_71 ( V_224 -> V_135 . V_33 , V_160 , V_168 ) ;
if ( V_9 )
goto V_14;
V_224 -> V_135 . V_33 [ V_168 ] = 0 ;
V_9 = F_71 ( V_161 , V_160 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_14;
V_224 -> V_39 . V_227 = F_72 ( V_161 [ 0 ] ) ;
V_9 = F_75 ( & V_224 -> V_130 [ 0 ] , V_7 , V_160 ) ;
if ( V_9 )
goto V_14;
for ( V_223 = NULL , V_129 = V_137 -> V_150 ; V_129 ;
V_223 = V_129 , V_129 = V_129 -> V_118 ) {
V_9 = - V_15 ;
if ( ! strcmp ( V_224 -> V_135 . V_33 , V_129 -> V_135 . V_33 ) &&
( ! V_129 -> V_39 . V_227 || ! V_224 -> V_39 . V_227 ||
V_224 -> V_39 . V_227 == V_129 -> V_39 . V_227 ) ) {
F_31 ( V_155 L_37 ,
V_137 -> V_149 , V_129 -> V_135 . V_33 ) ;
goto V_14;
}
V_168 = strlen ( V_224 -> V_135 . V_33 ) ;
V_193 = strlen ( V_129 -> V_135 . V_33 ) ;
if ( V_168 > V_193 )
break;
}
V_224 -> V_118 = V_129 ;
if ( V_223 )
V_223 -> V_118 = V_224 ;
else
V_137 -> V_150 = V_224 ;
V_224 = NULL ;
}
}
V_9 = 0 ;
V_14:
if ( V_226 )
F_7 ( V_226 -> V_149 ) ;
F_7 ( V_226 ) ;
F_54 ( V_224 , V_134 ) ;
return V_9 ;
}
static int F_104 ( struct V_6 * V_7 , struct V_1 * V_4 ,
void * V_160 )
{
int V_3 , V_180 , V_9 ;
T_1 V_97 , V_168 ;
T_2 V_161 [ 3 ] ;
struct V_128 * V_223 , * V_129 ;
T_1 V_228 [ 8 ] ;
for ( V_3 = 0 ; V_3 < V_4 -> V_229 ; V_3 ++ ) {
V_9 = F_71 ( V_161 , V_160 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_14;
V_97 = F_72 ( V_161 [ 0 ] ) ;
V_223 = NULL ;
for ( V_180 = 0 ; V_180 < V_97 ; V_180 ++ ) {
V_9 = - V_12 ;
V_129 = F_4 ( sizeof( * V_129 ) , V_13 ) ;
if ( ! V_129 )
goto V_14;
if ( V_223 )
V_223 -> V_118 = V_129 ;
else
V_7 -> V_148 [ V_3 ] = V_129 ;
V_223 = V_129 ;
switch ( V_3 ) {
case V_131 :
V_9 = F_71 ( V_161 , V_160 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_14;
V_129 -> V_157 [ 0 ] = F_72 ( V_161 [ 0 ] ) ;
V_9 = F_75 ( & V_129 -> V_130 [ 0 ] , V_7 , V_160 ) ;
if ( V_9 )
goto V_14;
break;
case V_132 :
case V_133 :
V_9 = F_71 ( V_161 , V_160 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_14;
V_168 = F_72 ( V_161 [ 0 ] ) ;
V_9 = - V_12 ;
V_129 -> V_135 . V_33 = F_36 ( V_168 + 1 , V_13 ) ;
if ( ! V_129 -> V_135 . V_33 )
goto V_14;
V_9 = F_71 ( V_129 -> V_135 . V_33 , V_160 , V_168 ) ;
if ( V_9 )
goto V_14;
V_129 -> V_135 . V_33 [ V_168 ] = 0 ;
V_9 = F_75 ( & V_129 -> V_130 [ 0 ] , V_7 , V_160 ) ;
if ( V_9 )
goto V_14;
V_9 = F_75 ( & V_129 -> V_130 [ 1 ] , V_7 , V_160 ) ;
if ( V_9 )
goto V_14;
break;
case V_230 :
V_9 = F_71 ( V_161 , V_160 , sizeof( T_1 ) * 3 ) ;
if ( V_9 )
goto V_14;
V_129 -> V_135 . V_231 . V_232 = F_72 ( V_161 [ 0 ] ) ;
V_129 -> V_135 . V_231 . V_233 = F_72 ( V_161 [ 1 ] ) ;
V_129 -> V_135 . V_231 . V_234 = F_72 ( V_161 [ 2 ] ) ;
V_9 = F_75 ( & V_129 -> V_130 [ 0 ] , V_7 , V_160 ) ;
if ( V_9 )
goto V_14;
break;
case V_235 :
V_9 = F_71 ( V_228 , V_160 , sizeof( T_1 ) * 2 ) ;
if ( V_9 )
goto V_14;
V_129 -> V_135 . V_212 . V_236 = V_228 [ 0 ] ;
V_129 -> V_135 . V_212 . V_237 = V_228 [ 1 ] ;
V_9 = F_75 ( & V_129 -> V_130 [ 0 ] , V_7 , V_160 ) ;
if ( V_9 )
goto V_14;
break;
case V_134 :
V_9 = F_71 ( V_161 , V_160 , sizeof( T_1 ) * 2 ) ;
if ( V_9 )
goto V_14;
V_9 = - V_15 ;
V_129 -> V_39 . V_238 = F_72 ( V_161 [ 0 ] ) ;
if ( V_129 -> V_39 . V_238 == V_239 )
goto V_14;
if ( V_129 -> V_39 . V_238 > V_240 )
goto V_14;
V_9 = - V_12 ;
V_168 = F_72 ( V_161 [ 1 ] ) ;
V_129 -> V_135 . V_33 = F_36 ( V_168 + 1 , V_13 ) ;
if ( ! V_129 -> V_135 . V_33 )
goto V_14;
V_9 = F_71 ( V_129 -> V_135 . V_33 , V_160 , V_168 ) ;
if ( V_9 )
goto V_14;
V_129 -> V_135 . V_33 [ V_168 ] = 0 ;
V_9 = F_75 ( & V_129 -> V_130 [ 0 ] , V_7 , V_160 ) ;
if ( V_9 )
goto V_14;
break;
case V_241 : {
int V_24 ;
V_9 = F_71 ( V_228 , V_160 , sizeof( T_1 ) * 8 ) ;
if ( V_9 )
goto V_14;
for ( V_24 = 0 ; V_24 < 4 ; V_24 ++ )
V_129 -> V_135 . V_242 . V_236 [ V_24 ] = V_228 [ V_24 ] ;
for ( V_24 = 0 ; V_24 < 4 ; V_24 ++ )
V_129 -> V_135 . V_242 . V_237 [ V_24 ] = V_228 [ V_24 + 4 ] ;
V_9 = F_75 ( & V_129 -> V_130 [ 0 ] , V_7 , V_160 ) ;
if ( V_9 )
goto V_14;
break;
}
}
}
}
V_9 = 0 ;
V_14:
return V_9 ;
}
int F_105 ( struct V_6 * V_7 , void * V_160 )
{
struct V_140 * V_141 , * V_142 ;
struct V_143 * V_144 , * V_145 ;
int V_3 , V_180 , V_9 ;
T_2 V_161 [ 4 ] ;
T_1 V_168 , V_18 , V_97 ;
char * V_243 ;
struct V_1 * V_4 ;
V_9 = F_13 ( V_7 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_71 ( V_161 , V_160 , sizeof( T_1 ) * 2 ) ;
if ( V_9 )
goto V_169;
V_9 = - V_15 ;
if ( F_72 ( V_161 [ 0 ] ) != V_244 ) {
F_31 ( V_155 L_38
L_39 ,
F_72 ( V_161 [ 0 ] ) , V_244 ) ;
goto V_169;
}
V_9 = - V_15 ;
V_168 = F_72 ( V_161 [ 1 ] ) ;
if ( V_168 != strlen ( V_245 ) ) {
F_31 ( V_155 L_40
L_41 ,
V_168 , strlen ( V_245 ) ) ;
goto V_169;
}
V_9 = - V_12 ;
V_243 = F_36 ( V_168 + 1 , V_13 ) ;
if ( ! V_243 ) {
F_31 ( V_155 L_42
L_43 , V_168 ) ;
goto V_169;
}
V_9 = F_71 ( V_243 , V_160 , V_168 ) ;
if ( V_9 ) {
F_31 ( V_155 L_44 ) ;
F_7 ( V_243 ) ;
goto V_169;
}
V_9 = - V_15 ;
V_243 [ V_168 ] = '\0' ;
if ( strcmp ( V_243 , V_245 ) ) {
F_31 ( V_155 L_45
L_46 , V_243 , V_245 ) ;
F_7 ( V_243 ) ;
goto V_169;
}
F_7 ( V_243 ) ;
V_243 = NULL ;
V_9 = F_71 ( V_161 , V_160 , sizeof( T_1 ) * 4 ) ;
if ( V_9 )
goto V_169;
V_9 = - V_15 ;
V_7 -> V_164 = F_72 ( V_161 [ 0 ] ) ;
if ( V_7 -> V_164 < V_246 ||
V_7 -> V_164 > V_247 ) {
F_31 ( V_155 L_47
L_48 ,
F_72 ( V_161 [ 0 ] ) , V_246 , V_247 ) ;
goto V_169;
}
if ( ( F_72 ( V_161 [ 1 ] ) & V_248 ) ) {
V_7 -> V_103 = 1 ;
V_9 = - V_15 ;
if ( V_7 -> V_164 < V_165 ) {
F_31 ( V_155 L_49
L_50 ,
V_7 -> V_164 ) ;
goto V_169;
}
}
V_7 -> V_249 = ! ! ( F_72 ( V_161 [ 1 ] ) & V_250 ) ;
V_7 -> V_251 = ! ! ( F_72 ( V_161 [ 1 ] ) & V_252 ) ;
if ( V_7 -> V_164 >= V_253 ) {
V_9 = F_73 ( & V_7 -> V_52 , V_160 ) ;
if ( V_9 )
goto V_169;
}
if ( V_7 -> V_164 >= V_254 ) {
V_9 = F_73 ( & V_7 -> V_53 , V_160 ) ;
if ( V_9 )
goto V_169;
}
V_9 = - V_15 ;
V_4 = F_1 ( V_7 -> V_164 ) ;
if ( ! V_4 ) {
F_31 ( V_155 L_51
L_52 , V_7 -> V_164 ) ;
goto V_169;
}
V_9 = - V_15 ;
if ( F_72 ( V_161 [ 2 ] ) != V_4 -> V_255 ||
F_72 ( V_161 [ 3 ] ) != V_4 -> V_229 ) {
F_31 ( V_155 L_53
L_54 , F_72 ( V_161 [ 2 ] ) ,
F_72 ( V_161 [ 3 ] ) ,
V_4 -> V_255 , V_4 -> V_229 ) ;
goto V_169;
}
for ( V_3 = 0 ; V_3 < V_4 -> V_255 ; V_3 ++ ) {
V_9 = F_71 ( V_161 , V_160 , sizeof( T_1 ) * 2 ) ;
if ( V_9 )
goto V_169;
V_18 = F_72 ( V_161 [ 0 ] ) ;
V_97 = F_72 ( V_161 [ 1 ] ) ;
for ( V_180 = 0 ; V_180 < V_97 ; V_180 ++ ) {
V_9 = V_256 [ V_3 ] ( V_7 , V_7 -> V_47 [ V_3 ] . V_21 , V_160 ) ;
if ( V_9 )
goto V_169;
}
V_7 -> V_47 [ V_3 ] . V_18 = V_18 ;
}
V_9 = - V_15 ;
V_7 -> V_216 = F_97 ( V_7 , L_55 ) ;
if ( ! V_7 -> V_216 )
goto V_169;
V_9 = F_106 ( & V_7 -> V_49 , V_160 , V_7 ) ;
if ( V_9 )
goto V_169;
if ( V_7 -> V_164 >= V_257 ) {
V_9 = F_107 ( V_7 , V_160 ) ;
if ( V_9 )
goto V_169;
}
V_9 = F_71 ( V_161 , V_160 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_169;
V_97 = F_72 ( V_161 [ 0 ] ) ;
V_145 = NULL ;
for ( V_3 = 0 ; V_3 < V_97 ; V_3 ++ ) {
V_9 = - V_12 ;
V_144 = F_4 ( sizeof( * V_144 ) , V_13 ) ;
if ( ! V_144 )
goto V_169;
if ( V_145 )
V_145 -> V_118 = V_144 ;
else
V_7 -> V_151 = V_144 ;
V_9 = F_71 ( V_161 , V_160 , sizeof( T_1 ) * 3 ) ;
if ( V_9 )
goto V_169;
V_9 = - V_15 ;
V_144 -> V_11 = F_72 ( V_161 [ 0 ] ) ;
V_144 -> type = F_72 ( V_161 [ 1 ] ) ;
V_144 -> V_258 = F_72 ( V_161 [ 2 ] ) ;
if ( V_7 -> V_164 >= V_259 ) {
V_9 = F_71 ( V_161 , V_160 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_169;
V_144 -> V_32 = F_72 ( V_161 [ 0 ] ) ;
} else
V_144 -> V_32 = V_7 -> V_216 ;
if ( ! F_65 ( V_7 , V_144 -> V_11 ) ||
! F_66 ( V_7 , V_144 -> type ) ||
! F_64 ( V_7 , V_144 -> V_32 ) ||
! F_65 ( V_7 , V_144 -> V_258 ) )
goto V_169;
V_145 = V_144 ;
}
V_9 = F_71 ( V_161 , V_160 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_169;
V_97 = F_72 ( V_161 [ 0 ] ) ;
V_142 = NULL ;
for ( V_3 = 0 ; V_3 < V_97 ; V_3 ++ ) {
V_9 = - V_12 ;
V_141 = F_4 ( sizeof( * V_141 ) , V_13 ) ;
if ( ! V_141 )
goto V_169;
if ( V_142 )
V_142 -> V_118 = V_141 ;
else
V_7 -> V_140 = V_141 ;
V_9 = F_71 ( V_161 , V_160 , sizeof( T_1 ) * 2 ) ;
if ( V_9 )
goto V_169;
V_9 = - V_15 ;
V_141 -> V_11 = F_72 ( V_161 [ 0 ] ) ;
V_141 -> V_258 = F_72 ( V_161 [ 1 ] ) ;
if ( ! F_65 ( V_7 , V_141 -> V_11 ) ||
! F_65 ( V_7 , V_141 -> V_258 ) )
goto V_169;
V_142 = V_141 ;
}
V_9 = F_101 ( V_7 , V_160 ) ;
if ( V_9 )
goto V_169;
V_9 = F_33 ( V_7 ) ;
if ( V_9 )
goto V_169;
V_9 = - V_15 ;
V_7 -> V_260 = F_98 ( V_7 , V_7 -> V_216 , L_56 ) ;
V_7 -> V_260 |= F_98 ( V_7 , V_7 -> V_216 , L_57 ) ;
if ( ! V_7 -> V_260 )
goto V_169;
V_9 = F_104 ( V_7 , V_4 , V_160 ) ;
if ( V_9 )
goto V_169;
V_9 = F_103 ( V_7 , V_160 ) ;
if ( V_9 )
goto V_169;
V_9 = F_99 ( V_7 , V_160 ) ;
if ( V_9 )
goto V_169;
V_9 = - V_12 ;
V_7 -> V_152 = F_37 ( sizeof( struct V_153 ) ,
V_7 -> V_75 . V_18 ,
V_13 | V_63 ) ;
if ( ! V_7 -> V_152 )
goto V_169;
V_9 = F_38 ( V_7 -> V_152 , 0 , V_7 -> V_75 . V_18 ,
V_13 | V_63 ) ;
if ( V_9 )
goto V_169;
for ( V_3 = 0 ; V_3 < V_7 -> V_75 . V_18 ; V_3 ++ ) {
struct V_153 * V_115 = F_60 ( V_7 -> V_152 , V_3 ) ;
F_95 ( ! V_115 ) ;
F_18 ( V_115 ) ;
if ( V_7 -> V_164 >= V_261 ) {
V_9 = F_73 ( V_115 , V_160 ) ;
if ( V_9 )
goto V_169;
}
V_9 = F_102 ( V_115 , V_3 , 1 ) ;
if ( V_9 )
goto V_169;
}
V_9 = F_96 ( V_7 ) ;
if ( V_9 )
goto V_169;
V_9 = 0 ;
V_14:
return V_9 ;
V_169:
F_56 ( V_7 ) ;
goto V_14;
}
static int F_108 ( struct V_207 * V_223 , void * V_160 )
{
T_2 V_161 [ 1 ] ;
int V_9 ;
V_161 [ 0 ] = F_109 ( V_223 -> V_87 ) ;
V_9 = F_110 ( V_161 , sizeof( T_1 ) , 1 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_111 ( & V_223 -> V_124 , V_160 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_112 ( struct V_126 * V_159 , void * V_160 )
{
T_2 V_161 [ 3 ] ;
T_4 V_162 ;
int V_9 , V_262 ;
V_262 = F_113 ( & V_159 -> V_86 [ 1 ] , & V_159 -> V_86 [ 0 ] ) ;
if ( V_262 )
V_162 = 2 ;
else
V_162 = 3 ;
V_161 [ 0 ] = F_109 ( V_162 - 1 ) ;
V_161 [ 1 ] = F_109 ( V_159 -> V_86 [ 0 ] . V_87 ) ;
if ( ! V_262 )
V_161 [ 2 ] = F_109 ( V_159 -> V_86 [ 1 ] . V_87 ) ;
F_95 ( V_162 > ( sizeof( V_161 ) / sizeof( V_161 [ 0 ] ) ) ) ;
V_9 = F_110 ( V_161 , sizeof( T_1 ) , V_162 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_111 ( & V_159 -> V_86 [ 0 ] . V_124 , V_160 ) ;
if ( V_9 )
return V_9 ;
if ( ! V_262 ) {
V_9 = F_111 ( & V_159 -> V_86 [ 1 ] . V_124 , V_160 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
static int F_114 ( void * V_263 , void * V_54 , void * V_264 )
{
char * V_8 = V_263 ;
struct V_83 * V_84 = V_54 ;
struct V_265 * V_266 = V_264 ;
void * V_160 = V_266 -> V_160 ;
T_2 V_161 [ 2 ] ;
T_4 V_168 ;
int V_9 ;
V_168 = strlen ( V_8 ) ;
V_161 [ 0 ] = F_109 ( V_168 ) ;
V_161 [ 1 ] = F_109 ( V_84 -> V_85 ) ;
V_9 = F_110 ( V_161 , sizeof( T_1 ) , 2 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_110 ( V_8 , 1 , V_168 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_108 ( V_84 -> V_86 , V_160 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_115 ( void * V_263 , void * V_54 , void * V_264 )
{
char * V_8 = V_263 ;
struct V_90 * V_91 = V_54 ;
struct V_265 * V_266 = V_264 ;
void * V_160 = V_266 -> V_160 ;
T_2 V_161 [ 3 ] ;
T_4 V_168 ;
int V_9 ;
V_168 = strlen ( V_8 ) ;
V_161 [ 0 ] = F_109 ( V_168 ) ;
V_161 [ 1 ] = F_109 ( V_91 -> V_16 ) ;
V_161 [ 2 ] = F_109 ( V_91 -> V_85 ) ;
V_9 = F_110 ( V_161 , sizeof( T_1 ) , 3 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_110 ( V_8 , 1 , V_168 , V_160 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_116 ( struct V_6 * V_7 , void * V_160 )
{
struct V_143 * V_159 = V_7 -> V_151 ;
struct V_143 * V_144 ;
T_1 V_161 [ 3 ] ;
T_4 V_97 ;
int V_9 ;
V_97 = 0 ;
for ( V_144 = V_159 ; V_144 ; V_144 = V_144 -> V_118 )
V_97 ++ ;
V_161 [ 0 ] = F_109 ( V_97 ) ;
V_9 = F_110 ( V_161 , sizeof( T_1 ) , 1 , V_160 ) ;
if ( V_9 )
return V_9 ;
for ( V_144 = V_159 ; V_144 ; V_144 = V_144 -> V_118 ) {
V_161 [ 0 ] = F_109 ( V_144 -> V_11 ) ;
V_161 [ 1 ] = F_109 ( V_144 -> type ) ;
V_161 [ 2 ] = F_109 ( V_144 -> V_258 ) ;
V_9 = F_110 ( V_161 , sizeof( T_1 ) , 3 , V_160 ) ;
if ( V_9 )
return V_9 ;
if ( V_7 -> V_164 >= V_259 ) {
V_161 [ 0 ] = F_109 ( V_144 -> V_32 ) ;
V_9 = F_110 ( V_161 , sizeof( T_1 ) , 1 , V_160 ) ;
if ( V_9 )
return V_9 ;
}
}
return 0 ;
}
static int F_117 ( struct V_140 * V_159 , void * V_160 )
{
struct V_140 * V_141 ;
T_1 V_161 [ 2 ] ;
T_4 V_97 ;
int V_9 ;
V_97 = 0 ;
for ( V_141 = V_159 ; V_141 ; V_141 = V_141 -> V_118 )
V_97 ++ ;
V_161 [ 0 ] = F_109 ( V_97 ) ;
V_9 = F_110 ( V_161 , sizeof( T_1 ) , 1 , V_160 ) ;
if ( V_9 )
return V_9 ;
for ( V_141 = V_159 ; V_141 ; V_141 = V_141 -> V_118 ) {
V_161 [ 0 ] = F_109 ( V_141 -> V_11 ) ;
V_161 [ 1 ] = F_109 ( V_141 -> V_258 ) ;
V_9 = F_110 ( V_161 , sizeof( T_1 ) , 2 , V_160 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
static int F_118 ( struct V_6 * V_7 , struct V_130 * V_129 ,
void * V_160 )
{
int V_9 ;
T_2 V_161 [ 3 ] ;
V_161 [ 0 ] = F_109 ( V_129 -> V_156 ) ;
V_161 [ 1 ] = F_109 ( V_129 -> V_11 ) ;
V_161 [ 2 ] = F_109 ( V_129 -> type ) ;
V_9 = F_110 ( V_161 , sizeof( T_1 ) , 3 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_112 ( & V_129 -> V_123 , V_160 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_119 ( void * V_263 , void * V_54 , void * V_160 )
{
char * V_8 = V_263 ;
struct V_166 * V_167 = V_54 ;
T_2 V_161 [ 2 ] ;
T_4 V_168 ;
int V_9 ;
V_168 = strlen ( V_8 ) ;
V_161 [ 0 ] = F_109 ( V_168 ) ;
V_161 [ 1 ] = F_109 ( V_167 -> V_16 ) ;
V_9 = F_110 ( V_161 , sizeof( T_1 ) , 2 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_110 ( V_8 , 1 , V_168 , V_160 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_120 ( void * V_263 , void * V_54 , void * V_264 )
{
char * V_8 = V_263 ;
struct V_56 * V_57 = V_54 ;
struct V_265 * V_266 = V_264 ;
void * V_160 = V_266 -> V_160 ;
T_2 V_161 [ 4 ] ;
T_4 V_168 ;
int V_9 ;
V_168 = strlen ( V_8 ) ;
V_161 [ 0 ] = F_109 ( V_168 ) ;
V_161 [ 1 ] = F_109 ( V_57 -> V_16 ) ;
V_161 [ 2 ] = F_109 ( V_57 -> V_105 . V_18 ) ;
V_161 [ 3 ] = F_109 ( V_57 -> V_105 . V_21 -> V_97 ) ;
V_9 = F_110 ( V_161 , sizeof( T_1 ) , 4 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_110 ( V_8 , 1 , V_168 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_40 ( V_57 -> V_105 . V_21 , F_119 , V_160 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_121 ( struct V_171 * V_172 , void * V_160 )
{
int V_9 ;
T_2 V_161 [ 1 ] ;
if ( F_111 ( & V_172 -> V_110 , V_160 ) )
return - V_15 ;
if ( F_111 ( & V_172 -> V_111 , V_160 ) )
return - V_15 ;
V_161 [ 0 ] = F_109 ( V_172 -> V_173 ) ;
V_9 = F_110 ( V_161 , sizeof( T_1 ) , 1 , V_160 ) ;
if ( V_9 )
return - V_15 ;
return 0 ;
}
static int F_122 ( struct V_6 * V_7 , struct V_112 * V_212 ,
void * V_160 )
{
struct V_112 * V_129 ;
struct V_106 * V_115 ;
T_2 V_161 [ 3 ] ;
T_1 V_97 ;
int V_9 ;
for ( V_129 = V_212 ; V_129 ; V_129 = V_129 -> V_118 ) {
V_97 = 0 ;
for ( V_115 = V_129 -> V_107 ; V_115 ; V_115 = V_115 -> V_118 )
V_97 ++ ;
V_161 [ 0 ] = F_109 ( V_129 -> V_105 ) ;
V_161 [ 1 ] = F_109 ( V_97 ) ;
V_9 = F_110 ( V_161 , sizeof( T_1 ) , 2 , V_160 ) ;
if ( V_9 )
return V_9 ;
for ( V_115 = V_129 -> V_107 ; V_115 ; V_115 = V_115 -> V_118 ) {
V_161 [ 0 ] = F_109 ( V_115 -> V_182 ) ;
V_161 [ 1 ] = F_109 ( V_115 -> V_183 ) ;
V_161 [ 2 ] = F_109 ( V_115 -> V_184 ) ;
V_9 = F_110 ( V_161 , sizeof( T_1 ) , 3 , V_160 ) ;
if ( V_9 )
return V_9 ;
switch ( V_115 -> V_182 ) {
case V_190 :
V_9 = F_111 ( & V_115 -> V_108 , V_160 ) ;
if ( V_9 )
return V_9 ;
if ( V_7 -> V_164 >=
V_192 ) {
V_9 = F_121 ( V_115 -> V_109 , V_160 ) ;
if ( V_9 )
return V_9 ;
}
break;
default:
break;
}
}
}
return 0 ;
}
static int F_123 ( void * V_263 , void * V_54 , void * V_264 )
{
char * V_8 = V_263 ;
struct V_64 * V_65 = V_54 ;
struct V_265 * V_266 = V_264 ;
void * V_160 = V_266 -> V_160 ;
struct V_6 * V_7 = V_266 -> V_7 ;
struct V_112 * V_129 ;
T_2 V_161 [ 6 ] ;
T_1 V_175 ;
T_4 V_168 , V_193 ;
int V_9 ;
V_168 = strlen ( V_8 ) ;
if ( V_65 -> V_120 )
V_193 = strlen ( V_65 -> V_120 ) ;
else
V_193 = 0 ;
V_175 = 0 ;
for ( V_129 = V_65 -> V_117 ; V_129 ; V_129 = V_129 -> V_118 )
V_175 ++ ;
V_161 [ 0 ] = F_109 ( V_168 ) ;
V_161 [ 1 ] = F_109 ( V_193 ) ;
V_161 [ 2 ] = F_109 ( V_65 -> V_16 ) ;
V_161 [ 3 ] = F_109 ( V_65 -> V_105 . V_18 ) ;
if ( V_65 -> V_105 . V_21 )
V_161 [ 4 ] = F_109 ( V_65 -> V_105 . V_21 -> V_97 ) ;
else
V_161 [ 4 ] = 0 ;
V_161 [ 5 ] = F_109 ( V_175 ) ;
V_9 = F_110 ( V_161 , sizeof( T_1 ) , 6 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_110 ( V_8 , 1 , V_168 , V_160 ) ;
if ( V_9 )
return V_9 ;
if ( V_65 -> V_120 ) {
V_9 = F_110 ( V_65 -> V_120 , 1 , V_193 , V_160 ) ;
if ( V_9 )
return V_9 ;
}
V_9 = F_40 ( V_65 -> V_105 . V_21 , F_119 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_122 ( V_7 , V_65 -> V_117 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_175 = 0 ;
for ( V_129 = V_65 -> V_119 ; V_129 ; V_129 = V_129 -> V_118 )
V_175 ++ ;
V_161 [ 0 ] = F_109 ( V_175 ) ;
V_9 = F_110 ( V_161 , sizeof( T_1 ) , 1 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_122 ( V_7 , V_65 -> V_119 , V_160 ) ;
if ( V_9 )
return V_9 ;
if ( V_7 -> V_164 >= V_195 ) {
V_161 [ 0 ] = F_109 ( V_65 -> V_196 ) ;
V_161 [ 1 ] = F_109 ( V_65 -> V_197 ) ;
V_161 [ 2 ] = F_109 ( V_65 -> V_198 ) ;
V_9 = F_110 ( V_161 , sizeof( V_267 ) , 3 , V_160 ) ;
if ( V_9 )
return V_9 ;
}
if ( V_7 -> V_164 >= V_199 ) {
V_161 [ 0 ] = F_109 ( V_65 -> V_200 ) ;
V_9 = F_110 ( V_161 , sizeof( V_267 ) , 1 , V_160 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
static int F_124 ( void * V_263 , void * V_54 , void * V_264 )
{
char * V_8 = V_263 ;
struct V_10 * V_11 = V_54 ;
struct V_265 * V_266 = V_264 ;
void * V_160 = V_266 -> V_160 ;
struct V_6 * V_7 = V_266 -> V_7 ;
T_2 V_161 [ 3 ] ;
T_4 V_162 , V_168 ;
int V_9 ;
V_168 = strlen ( V_8 ) ;
V_162 = 0 ;
V_161 [ V_162 ++ ] = F_109 ( V_168 ) ;
V_161 [ V_162 ++ ] = F_109 ( V_11 -> V_16 ) ;
if ( V_7 -> V_164 >= V_202 )
V_161 [ V_162 ++ ] = F_109 ( V_11 -> V_69 ) ;
F_95 ( V_162 > ( sizeof( V_161 ) / sizeof( V_161 [ 0 ] ) ) ) ;
V_9 = F_110 ( V_161 , sizeof( T_1 ) , V_162 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_110 ( V_8 , 1 , V_168 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_111 ( & V_11 -> V_121 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_111 ( & V_11 -> V_110 , V_160 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_125 ( void * V_263 , void * V_54 , void * V_264 )
{
char * V_8 = V_263 ;
struct V_72 * V_73 = V_54 ;
struct V_265 * V_266 = V_264 ;
struct V_6 * V_7 = V_266 -> V_7 ;
void * V_160 = V_266 -> V_160 ;
T_2 V_161 [ 4 ] ;
int V_9 ;
T_4 V_162 , V_168 ;
V_168 = strlen ( V_8 ) ;
V_162 = 0 ;
V_161 [ V_162 ++ ] = F_109 ( V_168 ) ;
V_161 [ V_162 ++ ] = F_109 ( V_73 -> V_16 ) ;
if ( V_7 -> V_164 >= V_202 ) {
T_1 V_268 = 0 ;
if ( V_73 -> V_74 )
V_268 |= V_204 ;
if ( V_73 -> V_206 )
V_268 |= V_205 ;
V_161 [ V_162 ++ ] = F_109 ( V_268 ) ;
V_161 [ V_162 ++ ] = F_109 ( V_73 -> V_69 ) ;
} else {
V_161 [ V_162 ++ ] = F_109 ( V_73 -> V_74 ) ;
}
F_95 ( V_162 > ( sizeof( V_161 ) / sizeof( V_161 [ 0 ] ) ) ) ;
V_9 = F_110 ( V_161 , sizeof( T_1 ) , V_162 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_110 ( V_8 , 1 , V_168 , V_160 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_126 ( void * V_263 , void * V_54 , void * V_264 )
{
char * V_8 = V_263 ;
struct V_78 * V_79 = V_54 ;
struct V_265 * V_266 = V_264 ;
struct V_6 * V_7 = V_266 -> V_7 ;
void * V_160 = V_266 -> V_160 ;
T_2 V_161 [ 3 ] ;
T_4 V_162 , V_168 ;
int V_9 ;
V_168 = strlen ( V_8 ) ;
V_162 = 0 ;
V_161 [ V_162 ++ ] = F_109 ( V_168 ) ;
V_161 [ V_162 ++ ] = F_109 ( V_79 -> V_16 ) ;
if ( V_7 -> V_164 >= V_202 )
V_161 [ V_162 ++ ] = F_109 ( V_79 -> V_69 ) ;
F_95 ( V_162 > ( sizeof( V_161 ) / sizeof( V_161 [ 0 ] ) ) ) ;
V_9 = F_110 ( V_161 , sizeof( T_1 ) , V_162 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_110 ( V_8 , 1 , V_168 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_111 ( & V_79 -> V_122 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_112 ( & V_79 -> V_123 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_108 ( & V_79 -> V_125 , V_160 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_127 ( struct V_6 * V_7 , struct V_1 * V_4 ,
void * V_160 )
{
unsigned int V_3 , V_180 , V_9 ;
T_4 V_97 , V_168 ;
T_2 V_161 [ 3 ] ;
T_1 V_228 [ 8 ] ;
struct V_128 * V_129 ;
for ( V_3 = 0 ; V_3 < V_4 -> V_229 ; V_3 ++ ) {
V_97 = 0 ;
for ( V_129 = V_7 -> V_148 [ V_3 ] ; V_129 ; V_129 = V_129 -> V_118 )
V_97 ++ ;
V_161 [ 0 ] = F_109 ( V_97 ) ;
V_9 = F_110 ( V_161 , sizeof( T_1 ) , 1 , V_160 ) ;
if ( V_9 )
return V_9 ;
for ( V_129 = V_7 -> V_148 [ V_3 ] ; V_129 ; V_129 = V_129 -> V_118 ) {
switch ( V_3 ) {
case V_131 :
V_161 [ 0 ] = F_109 ( V_129 -> V_157 [ 0 ] ) ;
V_9 = F_110 ( V_161 , sizeof( T_1 ) , 1 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_118 ( V_7 , & V_129 -> V_130 [ 0 ] , V_160 ) ;
if ( V_9 )
return V_9 ;
break;
case V_132 :
case V_133 :
V_168 = strlen ( V_129 -> V_135 . V_33 ) ;
V_161 [ 0 ] = F_109 ( V_168 ) ;
V_9 = F_110 ( V_161 , sizeof( T_1 ) , 1 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_110 ( V_129 -> V_135 . V_33 , 1 , V_168 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_118 ( V_7 , & V_129 -> V_130 [ 0 ] , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_118 ( V_7 , & V_129 -> V_130 [ 1 ] , V_160 ) ;
if ( V_9 )
return V_9 ;
break;
case V_230 :
V_161 [ 0 ] = F_109 ( V_129 -> V_135 . V_231 . V_232 ) ;
V_161 [ 1 ] = F_109 ( V_129 -> V_135 . V_231 . V_233 ) ;
V_161 [ 2 ] = F_109 ( V_129 -> V_135 . V_231 . V_234 ) ;
V_9 = F_110 ( V_161 , sizeof( T_1 ) , 3 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_118 ( V_7 , & V_129 -> V_130 [ 0 ] , V_160 ) ;
if ( V_9 )
return V_9 ;
break;
case V_235 :
V_228 [ 0 ] = V_129 -> V_135 . V_212 . V_236 ;
V_228 [ 1 ] = V_129 -> V_135 . V_212 . V_237 ;
V_9 = F_110 ( V_228 , sizeof( T_1 ) , 2 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_118 ( V_7 , & V_129 -> V_130 [ 0 ] , V_160 ) ;
if ( V_9 )
return V_9 ;
break;
case V_134 :
V_161 [ 0 ] = F_109 ( V_129 -> V_39 . V_238 ) ;
V_168 = strlen ( V_129 -> V_135 . V_33 ) ;
V_161 [ 1 ] = F_109 ( V_168 ) ;
V_9 = F_110 ( V_161 , sizeof( T_1 ) , 2 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_110 ( V_129 -> V_135 . V_33 , 1 , V_168 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_118 ( V_7 , & V_129 -> V_130 [ 0 ] , V_160 ) ;
if ( V_9 )
return V_9 ;
break;
case V_241 :
for ( V_180 = 0 ; V_180 < 4 ; V_180 ++ )
V_228 [ V_180 ] = V_129 -> V_135 . V_242 . V_236 [ V_180 ] ;
for ( V_180 = 0 ; V_180 < 4 ; V_180 ++ )
V_228 [ V_180 + 4 ] = V_129 -> V_135 . V_242 . V_237 [ V_180 ] ;
V_9 = F_110 ( V_228 , sizeof( T_1 ) , 8 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_118 ( V_7 , & V_129 -> V_130 [ 0 ] , V_160 ) ;
if ( V_9 )
return V_9 ;
break;
}
}
}
return 0 ;
}
static int F_128 ( struct V_6 * V_7 , void * V_160 )
{
struct V_137 * V_137 ;
struct V_128 * V_129 ;
T_4 V_168 ;
T_2 V_161 [ 1 ] ;
int V_9 ;
V_168 = 0 ;
for ( V_137 = V_7 -> V_137 ; V_137 ; V_137 = V_137 -> V_118 )
V_168 ++ ;
V_161 [ 0 ] = F_109 ( V_168 ) ;
V_9 = F_110 ( V_161 , sizeof( T_1 ) , 1 , V_160 ) ;
if ( V_9 )
return V_9 ;
for ( V_137 = V_7 -> V_137 ; V_137 ; V_137 = V_137 -> V_118 ) {
V_168 = strlen ( V_137 -> V_149 ) ;
V_161 [ 0 ] = F_109 ( V_168 ) ;
V_9 = F_110 ( V_161 , sizeof( T_1 ) , 1 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_110 ( V_137 -> V_149 , 1 , V_168 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_168 = 0 ;
for ( V_129 = V_137 -> V_150 ; V_129 ; V_129 = V_129 -> V_118 )
V_168 ++ ;
V_161 [ 0 ] = F_109 ( V_168 ) ;
V_9 = F_110 ( V_161 , sizeof( T_1 ) , 1 , V_160 ) ;
if ( V_9 )
return V_9 ;
for ( V_129 = V_137 -> V_150 ; V_129 ; V_129 = V_129 -> V_118 ) {
V_168 = strlen ( V_129 -> V_135 . V_33 ) ;
V_161 [ 0 ] = F_109 ( V_168 ) ;
V_9 = F_110 ( V_161 , sizeof( T_1 ) , 1 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_110 ( V_129 -> V_135 . V_33 , 1 , V_168 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_161 [ 0 ] = F_109 ( V_129 -> V_39 . V_227 ) ;
V_9 = F_110 ( V_161 , sizeof( T_1 ) , 1 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_118 ( V_7 , & V_129 -> V_130 [ 0 ] , V_160 ) ;
if ( V_9 )
return V_9 ;
}
}
return 0 ;
}
static int F_129 ( void * V_8 , void * V_269 , void * V_264 )
{
int * V_270 = V_264 ;
* V_270 = * V_270 + 1 ;
return 0 ;
}
static int F_130 ( void * V_8 , void * V_269 , void * V_264 )
{
T_2 V_161 [ 2 ] ;
struct V_40 * V_127 = V_8 ;
struct V_126 * V_159 = V_269 ;
struct V_265 * V_266 = V_264 ;
void * V_160 = V_266 -> V_160 ;
struct V_6 * V_7 = V_266 -> V_7 ;
int V_9 ;
V_161 [ 0 ] = F_109 ( V_127 -> V_41 ) ;
V_161 [ 1 ] = F_109 ( V_127 -> V_42 ) ;
V_9 = F_110 ( V_161 , sizeof( T_1 ) , 2 , V_160 ) ;
if ( V_9 )
return V_9 ;
if ( V_7 -> V_164 >= V_215 ) {
V_161 [ 0 ] = F_109 ( V_127 -> V_43 ) ;
V_9 = F_110 ( V_161 , sizeof( T_1 ) , 1 , V_160 ) ;
if ( V_9 )
return V_9 ;
}
V_9 = F_112 ( V_159 , V_160 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_131 ( struct V_6 * V_7 , void * V_160 )
{
T_2 V_161 [ 1 ] ;
int V_9 , V_97 ;
struct V_265 V_266 ;
V_266 . V_7 = V_7 ;
V_266 . V_160 = V_160 ;
V_97 = 0 ;
V_9 = F_40 ( V_7 -> V_50 , F_129 , & V_97 ) ;
if ( V_9 )
return V_9 ;
V_161 [ 0 ] = F_109 ( V_97 ) ;
V_9 = F_110 ( V_161 , sizeof( T_1 ) , 1 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_40 ( V_7 -> V_50 , F_130 , & V_266 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_132 ( void * V_8 , void * V_269 , void * V_264 )
{
T_2 V_161 [ 4 ] ;
struct V_25 * V_26 = V_8 ;
struct V_218 * V_219 = V_269 ;
void * V_160 = V_264 ;
int V_9 ;
T_1 V_168 ;
V_168 = strlen ( V_26 -> V_33 ) ;
V_161 [ 0 ] = F_109 ( V_168 ) ;
V_9 = F_110 ( V_161 , sizeof( T_1 ) , 1 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_110 ( V_26 -> V_33 , sizeof( char ) , V_168 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_161 [ 0 ] = F_109 ( V_26 -> V_30 ) ;
V_161 [ 1 ] = F_109 ( V_26 -> V_31 ) ;
V_161 [ 2 ] = F_109 ( V_26 -> V_32 ) ;
V_161 [ 3 ] = F_109 ( V_219 -> V_219 ) ;
V_9 = F_110 ( V_161 , sizeof( T_1 ) , 4 , V_160 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_133 ( struct V_6 * V_7 , void * V_160 )
{
T_1 V_97 ;
T_2 V_161 [ 1 ] ;
int V_9 ;
if ( V_7 -> V_164 < V_220 )
return 0 ;
V_97 = 0 ;
V_9 = F_40 ( V_7 -> V_25 , F_129 , & V_97 ) ;
if ( V_9 )
return V_9 ;
V_161 [ 0 ] = F_109 ( V_97 ) ;
V_9 = F_110 ( V_161 , sizeof( T_1 ) , 1 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_40 ( V_7 -> V_25 , F_132 , V_160 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
int F_134 ( struct V_6 * V_7 , void * V_160 )
{
unsigned int V_3 , V_271 ;
int V_9 ;
T_2 V_161 [ 4 ] ;
T_1 V_272 ;
T_4 V_168 ;
struct V_1 * V_4 ;
if ( V_7 -> V_164 < V_261 ) {
F_31 ( V_155 L_58
L_59 , V_7 -> V_164 ,
V_261 ) ;
return - V_15 ;
}
V_272 = 0 ;
if ( V_7 -> V_103 )
V_272 |= V_248 ;
if ( V_7 -> V_249 )
V_272 |= V_250 ;
if ( V_7 -> V_251 )
V_272 |= V_252 ;
V_161 [ 0 ] = F_109 ( V_244 ) ;
V_168 = strlen ( V_245 ) ;
V_161 [ 1 ] = F_109 ( V_168 ) ;
V_9 = F_110 ( V_161 , sizeof( T_1 ) , 2 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_110 ( V_245 , 1 , V_168 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_4 = F_1 ( V_7 -> V_164 ) ;
if ( ! V_4 ) {
F_31 ( V_155 L_60
L_61 , V_7 -> V_164 ) ;
return - V_15 ;
}
V_161 [ 0 ] = F_109 ( V_7 -> V_164 ) ;
V_161 [ 1 ] = F_109 ( V_272 ) ;
V_161 [ 2 ] = F_109 ( V_4 -> V_255 ) ;
V_161 [ 3 ] = F_109 ( V_4 -> V_229 ) ;
V_9 = F_110 ( V_161 , sizeof( T_1 ) , 4 , V_160 ) ;
if ( V_9 )
return V_9 ;
if ( V_7 -> V_164 >= V_253 ) {
V_9 = F_111 ( & V_7 -> V_52 , V_160 ) ;
if ( V_9 )
return V_9 ;
}
if ( V_7 -> V_164 >= V_254 ) {
V_9 = F_111 ( & V_7 -> V_53 , V_160 ) ;
if ( V_9 )
return V_9 ;
}
V_271 = V_4 -> V_255 ;
for ( V_3 = 0 ; V_3 < V_271 ; V_3 ++ ) {
struct V_265 V_266 ;
V_266 . V_160 = V_160 ;
V_266 . V_7 = V_7 ;
V_161 [ 0 ] = F_109 ( V_7 -> V_47 [ V_3 ] . V_18 ) ;
V_161 [ 1 ] = F_109 ( V_7 -> V_47 [ V_3 ] . V_21 -> V_97 ) ;
V_9 = F_110 ( V_161 , sizeof( T_1 ) , 2 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_40 ( V_7 -> V_47 [ V_3 ] . V_21 , V_273 [ V_3 ] , & V_266 ) ;
if ( V_9 )
return V_9 ;
}
V_9 = F_135 ( V_7 , & V_7 -> V_49 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_136 ( V_7 , V_7 -> V_274 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_116 ( V_7 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_117 ( V_7 -> V_140 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_133 ( V_7 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_127 ( V_7 , V_4 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_128 ( V_7 , V_160 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_131 ( V_7 , V_160 ) ;
if ( V_9 )
return V_9 ;
for ( V_3 = 0 ; V_3 < V_7 -> V_75 . V_18 ; V_3 ++ ) {
struct V_153 * V_115 = F_60 ( V_7 -> V_152 , V_3 ) ;
F_95 ( ! V_115 ) ;
V_9 = F_111 ( V_115 , V_160 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
