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
static int F_43 ( void * V_8 , void * V_54 , void * V_7 )
{
struct V_64 * V_65 ;
struct V_106 * V_107 , * V_108 ;
struct V_109 * V_110 , * V_111 ;
F_7 ( V_8 ) ;
if ( V_54 ) {
V_65 = V_54 ;
F_40 ( V_65 -> V_105 . V_21 , F_41 , NULL ) ;
F_19 ( V_65 -> V_105 . V_21 ) ;
V_107 = V_65 -> V_112 ;
while ( V_107 ) {
V_110 = V_107 -> V_113 ;
while ( V_110 ) {
F_44 ( & V_110 -> V_114 ) ;
V_111 = V_110 ;
V_110 = V_110 -> V_115 ;
F_7 ( V_111 ) ;
}
V_108 = V_107 ;
V_107 = V_107 -> V_115 ;
F_7 ( V_108 ) ;
}
V_107 = V_65 -> V_116 ;
while ( V_107 ) {
V_110 = V_107 -> V_113 ;
while ( V_110 ) {
F_44 ( & V_110 -> V_114 ) ;
V_111 = V_110 ;
V_110 = V_110 -> V_115 ;
F_7 ( V_111 ) ;
}
V_108 = V_107 ;
V_107 = V_107 -> V_115 ;
F_7 ( V_108 ) ;
}
F_7 ( V_65 -> V_117 ) ;
}
F_7 ( V_54 ) ;
return 0 ;
}
static int F_45 ( void * V_8 , void * V_54 , void * V_7 )
{
struct V_10 * V_11 ;
F_7 ( V_8 ) ;
if ( V_54 ) {
V_11 = V_54 ;
F_44 ( & V_11 -> V_118 ) ;
F_44 ( & V_11 -> V_119 ) ;
}
F_7 ( V_54 ) ;
return 0 ;
}
static int F_46 ( void * V_8 , void * V_54 , void * V_7 )
{
F_7 ( V_8 ) ;
F_7 ( V_54 ) ;
return 0 ;
}
static int F_47 ( void * V_8 , void * V_54 , void * V_7 )
{
struct V_78 * V_79 ;
F_7 ( V_8 ) ;
if ( V_54 ) {
V_79 = V_54 ;
F_44 ( & V_79 -> V_120 ) ;
F_44 ( & V_79 -> V_121 . V_86 [ 0 ] . V_122 ) ;
F_44 ( & V_79 -> V_121 . V_86 [ 1 ] . V_122 ) ;
F_44 ( & V_79 -> V_123 . V_122 ) ;
}
F_7 ( V_54 ) ;
return 0 ;
}
static int F_48 ( void * V_8 , void * V_54 , void * V_7 )
{
struct V_83 * V_84 ;
F_7 ( V_8 ) ;
if ( V_54 ) {
V_84 = V_54 ;
F_44 ( & V_84 -> V_86 -> V_122 ) ;
F_7 ( V_84 -> V_86 ) ;
}
F_7 ( V_54 ) ;
return 0 ;
}
static int F_49 ( void * V_8 , void * V_54 , void * V_7 )
{
F_7 ( V_8 ) ;
F_7 ( V_54 ) ;
return 0 ;
}
static int F_50 ( void * V_8 , void * V_54 , void * V_7 )
{
struct V_25 * V_26 = V_8 ;
F_7 ( V_26 -> V_33 ) ;
F_7 ( V_8 ) ;
F_7 ( V_54 ) ;
F_51 () ;
return 0 ;
}
static int F_52 ( void * V_8 , void * V_54 , void * V_7 )
{
struct V_124 * V_125 = V_54 ;
F_7 ( V_8 ) ;
F_44 ( & V_125 -> V_86 [ 0 ] . V_122 ) ;
F_44 ( & V_125 -> V_86 [ 1 ] . V_122 ) ;
F_7 ( V_54 ) ;
F_51 () ;
return 0 ;
}
static void F_53 ( struct V_126 * V_127 , int V_3 )
{
if ( ! V_127 )
return;
F_54 ( & V_127 -> V_128 [ 0 ] ) ;
F_54 ( & V_127 -> V_128 [ 1 ] ) ;
if ( V_3 == V_129 || V_3 == V_130 ||
V_3 == V_131 || V_3 == V_132 )
F_7 ( V_127 -> V_133 . V_33 ) ;
F_7 ( V_127 ) ;
}
void F_55 ( struct V_6 * V_7 )
{
struct V_126 * V_127 , * V_134 ;
struct V_135 * V_136 , * V_137 ;
int V_3 ;
struct V_138 * V_139 , * V_140 = NULL ;
struct V_141 * V_142 , * V_143 = NULL ;
for ( V_3 = 0 ; V_3 < V_46 ; V_3 ++ ) {
F_51 () ;
F_40 ( V_7 -> V_47 [ V_3 ] . V_21 , V_144 [ V_3 ] , NULL ) ;
F_19 ( V_7 -> V_47 [ V_3 ] . V_21 ) ;
}
for ( V_3 = 0 ; V_3 < V_46 ; V_3 ++ ) {
if ( V_7 -> V_61 [ V_3 ] )
F_56 ( V_7 -> V_61 [ V_3 ] ) ;
}
F_7 ( V_7 -> V_68 ) ;
F_7 ( V_7 -> V_71 ) ;
F_7 ( V_7 -> V_82 ) ;
if ( V_7 -> V_77 )
F_56 ( V_7 -> V_77 ) ;
F_57 ( & V_7 -> V_49 ) ;
for ( V_3 = 0 ; V_3 < V_145 ; V_3 ++ ) {
F_51 () ;
V_127 = V_7 -> V_146 [ V_3 ] ;
while ( V_127 ) {
V_134 = V_127 ;
V_127 = V_127 -> V_115 ;
F_53 ( V_134 , V_3 ) ;
}
V_7 -> V_146 [ V_3 ] = NULL ;
}
V_136 = V_7 -> V_135 ;
while ( V_136 ) {
F_51 () ;
F_7 ( V_136 -> V_147 ) ;
V_127 = V_136 -> V_148 ;
while ( V_127 ) {
V_134 = V_127 ;
V_127 = V_127 -> V_115 ;
F_53 ( V_134 , V_132 ) ;
}
V_137 = V_136 ;
V_136 = V_136 -> V_115 ;
F_7 ( V_137 ) ;
}
V_7 -> V_135 = NULL ;
F_58 ( V_7 ) ;
for ( V_142 = V_7 -> V_149 ; V_142 ; V_142 = V_142 -> V_115 ) {
F_51 () ;
F_7 ( V_143 ) ;
V_143 = V_142 ;
}
F_7 ( V_143 ) ;
for ( V_139 = V_7 -> V_138 ; V_139 ; V_139 = V_139 -> V_115 ) {
F_51 () ;
F_7 ( V_140 ) ;
V_140 = V_139 ;
}
F_7 ( V_140 ) ;
F_40 ( V_7 -> V_25 , F_50 , NULL ) ;
F_19 ( V_7 -> V_25 ) ;
F_40 ( V_7 -> V_50 , F_52 , NULL ) ;
F_19 ( V_7 -> V_50 ) ;
if ( V_7 -> V_150 ) {
for ( V_3 = 0 ; V_3 < V_7 -> V_75 . V_18 ; V_3 ++ ) {
struct V_151 * V_110 ;
V_110 = F_59 ( V_7 -> V_150 , V_3 ) ;
if ( ! V_110 )
continue;
F_44 ( V_110 ) ;
}
F_56 ( V_7 -> V_150 ) ;
}
F_44 ( & V_7 -> V_51 ) ;
F_44 ( & V_7 -> V_52 ) ;
F_44 ( & V_7 -> V_53 ) ;
return;
}
int F_60 ( struct V_6 * V_7 , struct V_152 * V_100 )
{
struct V_126 * V_148 , * V_127 ;
int V_9 ;
V_9 = F_61 ( V_100 ) ;
if ( V_9 ) {
F_31 ( V_153 L_8 ) ;
goto V_14;
}
V_148 = V_7 -> V_146 [ V_129 ] ;
for ( V_127 = V_148 ; V_127 ; V_127 = V_127 -> V_115 ) {
V_9 = - V_15 ;
if ( ! V_127 -> V_128 [ 0 ] . V_154 ) {
F_31 ( V_153 L_9 ,
V_127 -> V_133 . V_33 ) ;
goto V_14;
}
V_9 = F_62 ( V_100 , V_127 -> V_155 [ 0 ] , & V_127 -> V_128 [ 0 ] ) ;
if ( V_9 ) {
F_31 ( V_153 L_10 ,
V_127 -> V_133 . V_33 ) ;
goto V_14;
}
}
V_9 = 0 ;
V_14:
return V_9 ;
}
int F_63 ( struct V_6 * V_7 , unsigned int V_156 )
{
if ( ! V_156 || V_156 > V_7 -> V_66 . V_18 )
return 0 ;
return 1 ;
}
int F_64 ( struct V_6 * V_7 , unsigned int V_11 )
{
if ( ! V_11 || V_11 > V_7 -> V_17 . V_18 )
return 0 ;
return 1 ;
}
int F_65 ( struct V_6 * V_7 , unsigned int type )
{
if ( ! type || type > V_7 -> V_75 . V_18 )
return 0 ;
return 1 ;
}
int F_66 ( struct V_6 * V_7 , struct V_128 * V_127 )
{
struct V_10 * V_11 ;
struct V_78 * V_79 ;
if ( ! V_127 -> V_11 || V_127 -> V_11 > V_7 -> V_17 . V_18 )
return 0 ;
if ( ! V_127 -> V_154 || V_127 -> V_154 > V_7 -> V_80 . V_18 )
return 0 ;
if ( ! V_127 -> type || V_127 -> type > V_7 -> V_75 . V_18 )
return 0 ;
if ( V_127 -> V_11 != V_19 ) {
V_11 = V_7 -> V_71 [ V_127 -> V_11 - 1 ] ;
if ( ! F_67 ( & V_11 -> V_119 , V_127 -> type - 1 ) )
return 0 ;
V_79 = V_7 -> V_82 [ V_127 -> V_154 - 1 ] ;
if ( ! V_79 )
return 0 ;
if ( ! F_67 ( & V_79 -> V_120 , V_127 -> V_11 - 1 ) )
return 0 ;
}
if ( ! F_68 ( V_7 , V_127 ) )
return 0 ;
return 1 ;
}
static int F_69 ( struct V_124 * V_157 , void * V_158 )
{
T_2 V_159 [ 2 ] ;
T_1 V_160 ;
int V_9 ;
V_9 = F_70 ( V_159 , V_158 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_14;
V_9 = - V_15 ;
V_160 = F_71 ( V_159 [ 0 ] ) ;
if ( V_160 > F_2 ( V_159 ) ) {
F_31 ( V_153 L_11 ) ;
goto V_14;
}
V_9 = F_70 ( V_159 , V_158 , sizeof( T_1 ) * V_160 ) ;
if ( V_9 ) {
F_31 ( V_153 L_12 ) ;
goto V_14;
}
V_157 -> V_86 [ 0 ] . V_87 = F_71 ( V_159 [ 0 ] ) ;
if ( V_160 > 1 )
V_157 -> V_86 [ 1 ] . V_87 = F_71 ( V_159 [ 1 ] ) ;
else
V_157 -> V_86 [ 1 ] . V_87 = V_157 -> V_86 [ 0 ] . V_87 ;
V_9 = F_72 ( & V_157 -> V_86 [ 0 ] . V_122 , V_158 ) ;
if ( V_9 ) {
F_31 ( V_153 L_13 ) ;
goto V_14;
}
if ( V_160 > 1 ) {
V_9 = F_72 ( & V_157 -> V_86 [ 1 ] . V_122 , V_158 ) ;
if ( V_9 ) {
F_31 ( V_153 L_14 ) ;
goto V_161;
}
} else {
V_9 = F_73 ( & V_157 -> V_86 [ 1 ] . V_122 , & V_157 -> V_86 [ 0 ] . V_122 ) ;
if ( V_9 ) {
F_31 ( V_153 L_15 ) ;
goto V_161;
}
}
return 0 ;
V_161:
F_44 ( & V_157 -> V_86 [ 0 ] . V_122 ) ;
V_14:
return V_9 ;
}
static int F_74 ( struct V_128 * V_127 ,
struct V_6 * V_7 ,
void * V_158 )
{
T_2 V_159 [ 3 ] ;
int V_9 ;
V_9 = F_70 ( V_159 , V_158 , sizeof V_159 ) ;
if ( V_9 ) {
F_31 ( V_153 L_16 ) ;
goto V_14;
}
V_127 -> V_154 = F_71 ( V_159 [ 0 ] ) ;
V_127 -> V_11 = F_71 ( V_159 [ 1 ] ) ;
V_127 -> type = F_71 ( V_159 [ 2 ] ) ;
if ( V_7 -> V_162 >= V_163 ) {
V_9 = F_69 ( & V_127 -> V_121 , V_158 ) ;
if ( V_9 ) {
F_31 ( V_153 L_17 ) ;
goto V_14;
}
}
V_9 = - V_15 ;
if ( ! F_66 ( V_7 , V_127 ) ) {
F_31 ( V_153 L_18 ) ;
F_54 ( V_127 ) ;
goto V_14;
}
V_9 = 0 ;
V_14:
return V_9 ;
}
static int F_75 ( struct V_6 * V_7 , struct V_22 * V_23 , void * V_158 )
{
char * V_8 = NULL ;
struct V_164 * V_165 ;
int V_9 ;
T_2 V_159 [ 2 ] ;
T_1 V_166 ;
V_9 = - V_12 ;
V_165 = F_4 ( sizeof( * V_165 ) , V_13 ) ;
if ( ! V_165 )
goto V_167;
V_9 = F_70 ( V_159 , V_158 , sizeof V_159 ) ;
if ( V_9 )
goto V_167;
V_166 = F_71 ( V_159 [ 0 ] ) ;
V_165 -> V_16 = F_71 ( V_159 [ 1 ] ) ;
V_9 = - V_12 ;
V_8 = F_36 ( V_166 + 1 , V_13 ) ;
if ( ! V_8 )
goto V_167;
V_9 = F_70 ( V_8 , V_158 , V_166 ) ;
if ( V_9 )
goto V_167;
V_8 [ V_166 ] = '\0' ;
V_9 = F_6 ( V_23 , V_8 , V_165 ) ;
if ( V_9 )
goto V_167;
return 0 ;
V_167:
F_41 ( V_8 , V_165 , NULL ) ;
return V_9 ;
}
static int F_76 ( struct V_6 * V_7 , struct V_22 * V_23 , void * V_158 )
{
char * V_8 = NULL ;
struct V_56 * V_57 ;
T_2 V_159 [ 4 ] ;
T_1 V_166 , V_97 ;
int V_3 , V_9 ;
V_9 = - V_12 ;
V_57 = F_4 ( sizeof( * V_57 ) , V_13 ) ;
if ( ! V_57 )
goto V_167;
V_9 = F_70 ( V_159 , V_158 , sizeof V_159 ) ;
if ( V_9 )
goto V_167;
V_166 = F_71 ( V_159 [ 0 ] ) ;
V_57 -> V_16 = F_71 ( V_159 [ 1 ] ) ;
V_9 = F_14 ( & V_57 -> V_105 , V_168 ) ;
if ( V_9 )
goto V_167;
V_57 -> V_105 . V_18 = F_71 ( V_159 [ 2 ] ) ;
V_97 = F_71 ( V_159 [ 3 ] ) ;
V_9 = - V_12 ;
V_8 = F_36 ( V_166 + 1 , V_13 ) ;
if ( ! V_8 )
goto V_167;
V_9 = F_70 ( V_8 , V_158 , V_166 ) ;
if ( V_9 )
goto V_167;
V_8 [ V_166 ] = '\0' ;
for ( V_3 = 0 ; V_3 < V_97 ; V_3 ++ ) {
V_9 = F_75 ( V_7 , V_57 -> V_105 . V_21 , V_158 ) ;
if ( V_9 )
goto V_167;
}
V_9 = F_6 ( V_23 , V_8 , V_57 ) ;
if ( V_9 )
goto V_167;
return 0 ;
V_167:
F_42 ( V_8 , V_57 , NULL ) ;
return V_9 ;
}
static int F_77 ( struct V_106 * * V_169 , int V_170 ,
int V_171 , void * V_158 )
{
struct V_106 * V_127 , * V_172 ;
struct V_109 * V_110 , * V_173 ;
T_2 V_159 [ 3 ] ;
T_1 V_174 ;
int V_9 , V_3 , V_175 , V_176 ;
V_172 = NULL ;
for ( V_3 = 0 ; V_3 < V_170 ; V_3 ++ ) {
V_127 = F_4 ( sizeof( * V_127 ) , V_13 ) ;
if ( ! V_127 )
return - V_12 ;
if ( V_172 )
V_172 -> V_115 = V_127 ;
else
* V_169 = V_127 ;
V_9 = F_70 ( V_159 , V_158 , ( sizeof( T_1 ) * 2 ) ) ;
if ( V_9 )
return V_9 ;
V_127 -> V_105 = F_71 ( V_159 [ 0 ] ) ;
V_174 = F_71 ( V_159 [ 1 ] ) ;
V_173 = NULL ;
V_176 = - 1 ;
for ( V_175 = 0 ; V_175 < V_174 ; V_175 ++ ) {
V_110 = F_4 ( sizeof( * V_110 ) , V_13 ) ;
if ( ! V_110 )
return - V_12 ;
if ( V_173 )
V_173 -> V_115 = V_110 ;
else
V_127 -> V_113 = V_110 ;
V_9 = F_70 ( V_159 , V_158 , ( sizeof( T_1 ) * 3 ) ) ;
if ( V_9 )
return V_9 ;
V_110 -> V_177 = F_71 ( V_159 [ 0 ] ) ;
V_110 -> V_178 = F_71 ( V_159 [ 1 ] ) ;
V_110 -> V_179 = F_71 ( V_159 [ 2 ] ) ;
switch ( V_110 -> V_177 ) {
case V_180 :
if ( V_176 < 0 )
return - V_15 ;
break;
case V_181 :
case V_182 :
if ( V_176 < 1 )
return - V_15 ;
V_176 -- ;
break;
case V_183 :
if ( V_176 == ( V_184 - 1 ) )
return - V_15 ;
V_176 ++ ;
break;
case V_185 :
if ( ! V_171 && ( V_110 -> V_178 & V_186 ) )
return - V_15 ;
if ( V_176 == ( V_184 - 1 ) )
return - V_15 ;
V_176 ++ ;
V_9 = F_72 ( & V_110 -> V_114 , V_158 ) ;
if ( V_9 )
return V_9 ;
break;
default:
return - V_15 ;
}
V_173 = V_110 ;
}
if ( V_176 != 0 )
return - V_15 ;
V_172 = V_127 ;
}
return 0 ;
}
static int F_78 ( struct V_6 * V_7 , struct V_22 * V_23 , void * V_158 )
{
char * V_8 = NULL ;
struct V_64 * V_65 ;
T_2 V_159 [ 6 ] ;
T_1 V_166 , V_187 , V_170 , V_97 ;
int V_3 , V_9 ;
V_9 = - V_12 ;
V_65 = F_4 ( sizeof( * V_65 ) , V_13 ) ;
if ( ! V_65 )
goto V_167;
V_9 = F_70 ( V_159 , V_158 , sizeof( T_1 ) * 6 ) ;
if ( V_9 )
goto V_167;
V_166 = F_71 ( V_159 [ 0 ] ) ;
V_187 = F_71 ( V_159 [ 1 ] ) ;
V_65 -> V_16 = F_71 ( V_159 [ 2 ] ) ;
V_9 = F_14 ( & V_65 -> V_105 , V_168 ) ;
if ( V_9 )
goto V_167;
V_65 -> V_105 . V_18 = F_71 ( V_159 [ 3 ] ) ;
V_97 = F_71 ( V_159 [ 4 ] ) ;
V_170 = F_71 ( V_159 [ 5 ] ) ;
V_9 = - V_12 ;
V_8 = F_36 ( V_166 + 1 , V_13 ) ;
if ( ! V_8 )
goto V_167;
V_9 = F_70 ( V_8 , V_158 , V_166 ) ;
if ( V_9 )
goto V_167;
V_8 [ V_166 ] = '\0' ;
if ( V_187 ) {
V_9 = - V_12 ;
V_65 -> V_117 = F_36 ( V_187 + 1 , V_13 ) ;
if ( ! V_65 -> V_117 )
goto V_167;
V_9 = F_70 ( V_65 -> V_117 , V_158 , V_187 ) ;
if ( V_9 )
goto V_167;
V_65 -> V_117 [ V_187 ] = '\0' ;
V_9 = - V_15 ;
V_65 -> V_57 = F_79 ( V_7 -> V_60 . V_21 , V_65 -> V_117 ) ;
if ( ! V_65 -> V_57 ) {
F_31 ( V_153 L_19 , V_65 -> V_117 ) ;
goto V_167;
}
}
for ( V_3 = 0 ; V_3 < V_97 ; V_3 ++ ) {
V_9 = F_75 ( V_7 , V_65 -> V_105 . V_21 , V_158 ) ;
if ( V_9 )
goto V_167;
}
V_9 = F_77 ( & V_65 -> V_112 , V_170 , 0 , V_158 ) ;
if ( V_9 )
goto V_167;
if ( V_7 -> V_162 >= V_188 ) {
V_9 = F_70 ( V_159 , V_158 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_167;
V_170 = F_71 ( V_159 [ 0 ] ) ;
V_9 = F_77 ( & V_65 -> V_116 , V_170 , 1 , V_158 ) ;
if ( V_9 )
goto V_167;
}
if ( V_7 -> V_162 >= V_189 ) {
V_9 = F_70 ( V_159 , V_158 , sizeof( T_1 ) * 3 ) ;
if ( V_9 )
goto V_167;
V_65 -> V_190 = F_71 ( V_159 [ 0 ] ) ;
V_65 -> V_191 = F_71 ( V_159 [ 1 ] ) ;
V_65 -> V_192 = F_71 ( V_159 [ 2 ] ) ;
}
if ( V_7 -> V_162 >= V_193 ) {
V_9 = F_70 ( V_159 , V_158 , sizeof( T_1 ) * 1 ) ;
if ( V_9 )
goto V_167;
V_65 -> V_194 = F_71 ( V_159 [ 0 ] ) ;
}
V_9 = F_6 ( V_23 , V_8 , V_65 ) ;
if ( V_9 )
goto V_167;
return 0 ;
V_167:
F_43 ( V_8 , V_65 , NULL ) ;
return V_9 ;
}
static int F_80 ( struct V_6 * V_7 , struct V_22 * V_23 , void * V_158 )
{
char * V_8 = NULL ;
struct V_10 * V_11 ;
int V_9 , V_195 = 2 ;
T_2 V_159 [ 3 ] ;
T_1 V_166 ;
V_9 = - V_12 ;
V_11 = F_4 ( sizeof( * V_11 ) , V_13 ) ;
if ( ! V_11 )
goto V_167;
if ( V_7 -> V_162 >= V_196 )
V_195 = 3 ;
V_9 = F_70 ( V_159 , V_158 , sizeof( V_159 [ 0 ] ) * V_195 ) ;
if ( V_9 )
goto V_167;
V_166 = F_71 ( V_159 [ 0 ] ) ;
V_11 -> V_16 = F_71 ( V_159 [ 1 ] ) ;
if ( V_7 -> V_162 >= V_196 )
V_11 -> V_69 = F_71 ( V_159 [ 2 ] ) ;
V_9 = - V_12 ;
V_8 = F_36 ( V_166 + 1 , V_13 ) ;
if ( ! V_8 )
goto V_167;
V_9 = F_70 ( V_8 , V_158 , V_166 ) ;
if ( V_9 )
goto V_167;
V_8 [ V_166 ] = '\0' ;
V_9 = F_72 ( & V_11 -> V_118 , V_158 ) ;
if ( V_9 )
goto V_167;
V_9 = F_72 ( & V_11 -> V_119 , V_158 ) ;
if ( V_9 )
goto V_167;
if ( strcmp ( V_8 , V_20 ) == 0 ) {
V_9 = - V_15 ;
if ( V_11 -> V_16 != V_19 ) {
F_31 ( V_153 L_20 ,
V_20 , V_11 -> V_16 ) ;
goto V_167;
}
V_9 = 0 ;
goto V_167;
}
V_9 = F_6 ( V_23 , V_8 , V_11 ) ;
if ( V_9 )
goto V_167;
return 0 ;
V_167:
F_45 ( V_8 , V_11 , NULL ) ;
return V_9 ;
}
static int F_81 ( struct V_6 * V_7 , struct V_22 * V_23 , void * V_158 )
{
char * V_8 = NULL ;
struct V_72 * V_73 ;
int V_9 , V_195 = 3 ;
T_2 V_159 [ 4 ] ;
T_1 V_166 ;
V_9 = - V_12 ;
V_73 = F_4 ( sizeof( * V_73 ) , V_13 ) ;
if ( ! V_73 )
goto V_167;
if ( V_7 -> V_162 >= V_196 )
V_195 = 4 ;
V_9 = F_70 ( V_159 , V_158 , sizeof( V_159 [ 0 ] ) * V_195 ) ;
if ( V_9 )
goto V_167;
V_166 = F_71 ( V_159 [ 0 ] ) ;
V_73 -> V_16 = F_71 ( V_159 [ 1 ] ) ;
if ( V_7 -> V_162 >= V_196 ) {
T_1 V_197 = F_71 ( V_159 [ 2 ] ) ;
if ( V_197 & V_198 )
V_73 -> V_74 = 1 ;
if ( V_197 & V_199 )
V_73 -> V_200 = 1 ;
V_73 -> V_69 = F_71 ( V_159 [ 3 ] ) ;
} else {
V_73 -> V_74 = F_71 ( V_159 [ 2 ] ) ;
}
V_9 = - V_12 ;
V_8 = F_36 ( V_166 + 1 , V_13 ) ;
if ( ! V_8 )
goto V_167;
V_9 = F_70 ( V_8 , V_158 , V_166 ) ;
if ( V_9 )
goto V_167;
V_8 [ V_166 ] = '\0' ;
V_9 = F_6 ( V_23 , V_8 , V_73 ) ;
if ( V_9 )
goto V_167;
return 0 ;
V_167:
F_46 ( V_8 , V_73 , NULL ) ;
return V_9 ;
}
static int F_82 ( struct V_201 * V_202 , void * V_158 )
{
T_2 V_159 [ 1 ] ;
int V_9 ;
memset ( V_202 , 0 , sizeof( * V_202 ) ) ;
V_9 = F_70 ( V_159 , V_158 , sizeof V_159 ) ;
if ( V_9 ) {
F_31 ( V_153 L_21 ) ;
return V_9 ;
}
V_202 -> V_87 = F_71 ( V_159 [ 0 ] ) ;
V_9 = F_72 ( & V_202 -> V_122 , V_158 ) ;
if ( V_9 ) {
F_31 ( V_153 L_22 ) ;
return V_9 ;
}
return 0 ;
}
static int F_83 ( struct V_6 * V_7 , struct V_22 * V_23 , void * V_158 )
{
char * V_8 = NULL ;
struct V_78 * V_79 ;
int V_9 , V_195 = 2 ;
T_2 V_159 [ 3 ] ;
T_1 V_166 ;
V_9 = - V_12 ;
V_79 = F_4 ( sizeof( * V_79 ) , V_13 ) ;
if ( ! V_79 )
goto V_167;
if ( V_7 -> V_162 >= V_196 )
V_195 = 3 ;
V_9 = F_70 ( V_159 , V_158 , sizeof( V_159 [ 0 ] ) * V_195 ) ;
if ( V_9 )
goto V_167;
V_166 = F_71 ( V_159 [ 0 ] ) ;
V_79 -> V_16 = F_71 ( V_159 [ 1 ] ) ;
if ( V_7 -> V_162 >= V_196 )
V_79 -> V_69 = F_71 ( V_159 [ 2 ] ) ;
V_9 = - V_12 ;
V_8 = F_36 ( V_166 + 1 , V_13 ) ;
if ( ! V_8 )
goto V_167;
V_9 = F_70 ( V_8 , V_158 , V_166 ) ;
if ( V_9 )
goto V_167;
V_8 [ V_166 ] = '\0' ;
V_9 = F_72 ( & V_79 -> V_120 , V_158 ) ;
if ( V_9 )
goto V_167;
if ( V_7 -> V_162 >= V_163 ) {
V_9 = F_69 ( & V_79 -> V_121 , V_158 ) ;
if ( V_9 )
goto V_167;
V_9 = F_82 ( & V_79 -> V_123 , V_158 ) ;
if ( V_9 )
goto V_167;
}
V_9 = F_6 ( V_23 , V_8 , V_79 ) ;
if ( V_9 )
goto V_167;
return 0 ;
V_167:
F_47 ( V_8 , V_79 , NULL ) ;
return V_9 ;
}
static int F_84 ( struct V_6 * V_7 , struct V_22 * V_23 , void * V_158 )
{
char * V_8 = NULL ;
struct V_83 * V_84 ;
int V_9 ;
T_2 V_159 [ 2 ] ;
T_1 V_166 ;
V_9 = - V_12 ;
V_84 = F_4 ( sizeof( * V_84 ) , V_203 ) ;
if ( ! V_84 )
goto V_167;
V_9 = F_70 ( V_159 , V_158 , sizeof V_159 ) ;
if ( V_9 )
goto V_167;
V_166 = F_71 ( V_159 [ 0 ] ) ;
V_84 -> V_85 = F_71 ( V_159 [ 1 ] ) ;
V_9 = - V_12 ;
V_8 = F_36 ( V_166 + 1 , V_203 ) ;
if ( ! V_8 )
goto V_167;
V_9 = F_70 ( V_8 , V_158 , V_166 ) ;
if ( V_9 )
goto V_167;
V_8 [ V_166 ] = '\0' ;
V_9 = - V_12 ;
V_84 -> V_86 = F_36 ( sizeof( struct V_201 ) , V_203 ) ;
if ( ! V_84 -> V_86 )
goto V_167;
V_9 = F_82 ( V_84 -> V_86 , V_158 ) ;
if ( V_9 )
goto V_167;
V_9 = F_6 ( V_23 , V_8 , V_84 ) ;
if ( V_9 )
goto V_167;
return 0 ;
V_167:
F_48 ( V_8 , V_84 , NULL ) ;
return V_9 ;
}
static int F_85 ( struct V_6 * V_7 , struct V_22 * V_23 , void * V_158 )
{
char * V_8 = NULL ;
struct V_90 * V_91 ;
int V_9 ;
T_2 V_159 [ 3 ] ;
T_1 V_166 ;
V_9 = - V_12 ;
V_91 = F_4 ( sizeof( * V_91 ) , V_203 ) ;
if ( ! V_91 )
goto V_167;
V_9 = F_70 ( V_159 , V_158 , sizeof V_159 ) ;
if ( V_9 )
goto V_167;
V_166 = F_71 ( V_159 [ 0 ] ) ;
V_91 -> V_16 = F_71 ( V_159 [ 1 ] ) ;
V_91 -> V_85 = F_71 ( V_159 [ 2 ] ) ;
V_9 = - V_12 ;
V_8 = F_36 ( V_166 + 1 , V_203 ) ;
if ( ! V_8 )
goto V_167;
V_9 = F_70 ( V_8 , V_158 , V_166 ) ;
if ( V_9 )
goto V_167;
V_8 [ V_166 ] = '\0' ;
V_9 = F_6 ( V_23 , V_8 , V_91 ) ;
if ( V_9 )
goto V_167;
return 0 ;
V_167:
F_49 ( V_8 , V_91 , NULL ) ;
return V_9 ;
}
static int F_86 ( void * V_8 , void * V_54 , void * V_55 )
{
struct V_78 * V_204 , * V_154 ;
struct V_6 * V_7 = V_55 ;
int V_176 = 0 ;
V_204 = V_154 = V_54 ;
while ( V_204 -> V_69 ) {
struct V_205 * V_206 ;
unsigned long V_207 ;
if ( ++ V_176 == V_208 ) {
F_31 ( V_153 L_23
L_24 ,
( char * ) V_8 ) ;
return - V_15 ;
}
V_204 = V_7 -> V_82 [ V_204 -> V_69 - 1 ] ;
F_87 (&user->roles, node, bit) {
if ( F_67 ( & V_204 -> V_120 , V_207 ) )
continue;
F_31 ( V_153
L_25
L_26 ,
F_88 ( V_7 , V_81 , V_154 -> V_16 - 1 ) ,
F_88 ( V_7 , V_70 , V_207 ) ,
F_88 ( V_7 , V_81 , V_204 -> V_16 - 1 ) ) ;
return - V_15 ;
}
}
return 0 ;
}
static int F_89 ( void * V_8 , void * V_54 , void * V_55 )
{
struct V_10 * V_204 , * V_11 ;
struct V_6 * V_7 = V_55 ;
int V_176 = 0 ;
V_204 = V_11 = V_54 ;
while ( V_204 -> V_69 ) {
struct V_205 * V_206 ;
unsigned long V_207 ;
if ( ++ V_176 == V_208 ) {
F_31 ( V_153 L_27
L_28 ,
( char * ) V_8 ) ;
return - V_15 ;
}
V_204 = V_7 -> V_71 [ V_204 -> V_69 - 1 ] ;
F_87 (&role->types, node, bit) {
if ( F_67 ( & V_204 -> V_119 , V_207 ) )
continue;
F_31 ( V_153
L_25
L_29 ,
F_88 ( V_7 , V_70 , V_11 -> V_16 - 1 ) ,
F_88 ( V_7 , V_76 , V_207 ) ,
F_88 ( V_7 , V_70 , V_204 -> V_16 - 1 ) ) ;
return - V_15 ;
}
}
return 0 ;
}
static int F_90 ( void * V_8 , void * V_54 , void * V_55 )
{
struct V_72 * V_204 ;
struct V_6 * V_7 = V_55 ;
int V_176 = 0 ;
V_204 = V_54 ;
while ( V_204 -> V_69 ) {
if ( ++ V_176 == V_208 ) {
F_31 ( V_153 L_30
L_31 ,
( char * ) V_8 ) ;
return - V_15 ;
}
V_204 = F_91 ( V_7 -> V_77 ,
V_204 -> V_69 - 1 ) ;
F_92 ( ! V_204 ) ;
if ( V_204 -> V_200 ) {
F_31 ( V_153 L_30
L_32 ,
( char * ) V_8 ,
F_88 ( V_7 , V_76 , V_204 -> V_16 - 1 ) ) ;
return - V_15 ;
}
}
return 0 ;
}
static int F_93 ( struct V_6 * V_7 )
{
int V_9 ;
if ( V_7 -> V_162 < V_196 )
return 0 ;
V_9 = F_40 ( V_7 -> V_80 . V_21 ,
F_86 , V_7 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_40 ( V_7 -> V_17 . V_21 ,
F_89 , V_7 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_40 ( V_7 -> V_75 . V_21 ,
F_90 , V_7 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
T_3 F_94 ( struct V_6 * V_7 , const char * V_33 )
{
struct V_64 * V_65 ;
V_65 = F_79 ( V_7 -> V_66 . V_21 , V_33 ) ;
if ( ! V_65 )
return 0 ;
return V_65 -> V_16 ;
}
T_1 F_95 ( struct V_6 * V_7 , T_3 V_32 , const char * V_33 )
{
struct V_64 * V_65 ;
struct V_164 * V_165 = NULL ;
struct V_56 * V_57 ;
if ( ! V_32 || V_32 > V_7 -> V_66 . V_18 )
return 0 ;
V_65 = V_7 -> V_68 [ V_32 - 1 ] ;
V_57 = V_65 -> V_57 ;
if ( V_57 )
V_165 = F_79 ( V_57 -> V_105 . V_21 ,
V_33 ) ;
if ( ! V_165 )
V_165 = F_79 ( V_65 -> V_105 . V_21 ,
V_33 ) ;
if ( ! V_165 )
return 0 ;
return 1U << ( V_165 -> V_16 - 1 ) ;
}
static int F_96 ( struct V_6 * V_7 , void * V_158 )
{
struct V_40 * V_125 = NULL ;
struct V_124 * V_157 = NULL ;
int V_3 , V_9 ;
T_2 V_159 [ 2 ] ;
T_1 V_97 ;
if ( V_7 -> V_162 < V_163 )
return 0 ;
V_9 = F_70 ( V_159 , V_158 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_14;
V_97 = F_71 ( V_159 [ 0 ] ) ;
for ( V_3 = 0 ; V_3 < V_97 ; V_3 ++ ) {
V_9 = - V_12 ;
V_125 = F_4 ( sizeof( * V_125 ) , V_13 ) ;
if ( ! V_125 )
goto V_14;
V_9 = F_70 ( V_159 , V_158 , ( sizeof( T_1 ) * 2 ) ) ;
if ( V_9 )
goto V_14;
V_125 -> V_41 = F_71 ( V_159 [ 0 ] ) ;
V_125 -> V_42 = F_71 ( V_159 [ 1 ] ) ;
if ( V_7 -> V_162 >= V_209 ) {
V_9 = F_70 ( V_159 , V_158 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_14;
V_125 -> V_43 = F_71 ( V_159 [ 0 ] ) ;
} else
V_125 -> V_43 = V_7 -> V_210 ;
V_9 = - V_15 ;
if ( ! F_65 ( V_7 , V_125 -> V_41 ) ||
! F_65 ( V_7 , V_125 -> V_42 ) ||
! F_63 ( V_7 , V_125 -> V_43 ) )
goto V_14;
V_9 = - V_12 ;
V_157 = F_4 ( sizeof( * V_157 ) , V_13 ) ;
if ( ! V_157 )
goto V_14;
V_9 = F_69 ( V_157 , V_158 ) ;
if ( V_9 )
goto V_14;
V_9 = - V_15 ;
if ( ! F_97 ( V_7 , V_157 ) ) {
F_31 ( V_211 L_33 ) ;
goto V_14;
}
V_9 = F_6 ( V_7 -> V_50 , V_125 , V_157 ) ;
if ( V_9 )
goto V_14;
V_125 = NULL ;
V_157 = NULL ;
}
F_29 ( V_7 -> V_50 , L_34 ) ;
V_9 = 0 ;
V_14:
F_7 ( V_125 ) ;
F_7 ( V_157 ) ;
return V_9 ;
}
static int F_98 ( struct V_6 * V_7 , void * V_158 )
{
struct V_25 * V_26 ;
struct V_212 * V_213 ;
char * V_33 ;
T_1 V_97 , V_166 ;
T_2 V_159 [ 4 ] ;
int V_9 , V_3 ;
if ( V_7 -> V_162 < V_214 )
return 0 ;
V_9 = F_70 ( V_159 , V_158 , sizeof( T_1 ) ) ;
if ( V_9 )
return V_9 ;
V_97 = F_71 ( V_159 [ 0 ] ) ;
for ( V_3 = 0 ; V_3 < V_97 ; V_3 ++ ) {
V_26 = NULL ;
V_213 = NULL ;
V_33 = NULL ;
V_9 = - V_12 ;
V_26 = F_4 ( sizeof( * V_26 ) , V_13 ) ;
if ( ! V_26 )
goto V_14;
V_9 = - V_12 ;
V_213 = F_36 ( sizeof( * V_213 ) , V_13 ) ;
if ( ! V_213 )
goto V_14;
V_9 = F_70 ( V_159 , V_158 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_14;
V_166 = F_71 ( V_159 [ 0 ] ) ;
V_9 = - V_12 ;
V_33 = F_36 ( V_166 + 1 , V_13 ) ;
if ( ! V_33 )
goto V_14;
V_26 -> V_33 = V_33 ;
V_9 = F_70 ( V_33 , V_158 , V_166 ) ;
if ( V_9 )
goto V_14;
V_33 [ V_166 ] = 0 ;
V_9 = F_70 ( V_159 , V_158 , sizeof( T_1 ) * 4 ) ;
if ( V_9 )
goto V_14;
V_26 -> V_30 = F_71 ( V_159 [ 0 ] ) ;
V_26 -> V_31 = F_71 ( V_159 [ 1 ] ) ;
V_26 -> V_32 = F_71 ( V_159 [ 2 ] ) ;
V_213 -> V_213 = F_71 ( V_159 [ 3 ] ) ;
V_9 = F_99 ( & V_7 -> V_51 , V_26 -> V_31 , 1 ) ;
if ( V_9 )
goto V_14;
F_6 ( V_7 -> V_25 , V_26 , V_213 ) ;
}
F_29 ( V_7 -> V_25 , L_35 ) ;
return 0 ;
V_14:
F_7 ( V_26 ) ;
F_7 ( V_33 ) ;
F_7 ( V_213 ) ;
return V_9 ;
}
static int F_100 ( struct V_6 * V_7 , void * V_158 )
{
int V_3 , V_175 , V_9 ;
T_1 V_97 , V_215 , V_166 , V_187 ;
T_2 V_159 [ 1 ] ;
struct V_126 * V_216 , * V_127 ;
struct V_126 * V_217 = NULL ;
struct V_135 * V_218 , * V_135 ;
struct V_135 * V_219 = NULL ;
V_9 = F_70 ( V_159 , V_158 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_14;
V_97 = F_71 ( V_159 [ 0 ] ) ;
for ( V_3 = 0 ; V_3 < V_97 ; V_3 ++ ) {
V_9 = F_70 ( V_159 , V_158 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_14;
V_166 = F_71 ( V_159 [ 0 ] ) ;
V_9 = - V_12 ;
V_219 = F_4 ( sizeof( * V_219 ) , V_13 ) ;
if ( ! V_219 )
goto V_14;
V_9 = - V_12 ;
V_219 -> V_147 = F_36 ( V_166 + 1 , V_13 ) ;
if ( ! V_219 -> V_147 )
goto V_14;
V_9 = F_70 ( V_219 -> V_147 , V_158 , V_166 ) ;
if ( V_9 )
goto V_14;
V_219 -> V_147 [ V_166 ] = 0 ;
for ( V_218 = NULL , V_135 = V_7 -> V_135 ; V_135 ;
V_218 = V_135 , V_135 = V_135 -> V_115 ) {
V_9 = - V_15 ;
if ( strcmp ( V_219 -> V_147 , V_135 -> V_147 ) == 0 ) {
F_31 ( V_153 L_36 ,
V_219 -> V_147 ) ;
goto V_14;
}
if ( strcmp ( V_219 -> V_147 , V_135 -> V_147 ) < 0 )
break;
}
V_219 -> V_115 = V_135 ;
if ( V_218 )
V_218 -> V_115 = V_219 ;
else
V_7 -> V_135 = V_219 ;
V_135 = V_219 ;
V_219 = NULL ;
V_9 = F_70 ( V_159 , V_158 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_14;
V_215 = F_71 ( V_159 [ 0 ] ) ;
for ( V_175 = 0 ; V_175 < V_215 ; V_175 ++ ) {
V_9 = F_70 ( V_159 , V_158 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_14;
V_166 = F_71 ( V_159 [ 0 ] ) ;
V_9 = - V_12 ;
V_217 = F_4 ( sizeof( * V_217 ) , V_13 ) ;
if ( ! V_217 )
goto V_14;
V_9 = - V_12 ;
V_217 -> V_133 . V_33 = F_36 ( V_166 + 1 , V_13 ) ;
if ( ! V_217 -> V_133 . V_33 )
goto V_14;
V_9 = F_70 ( V_217 -> V_133 . V_33 , V_158 , V_166 ) ;
if ( V_9 )
goto V_14;
V_217 -> V_133 . V_33 [ V_166 ] = 0 ;
V_9 = F_70 ( V_159 , V_158 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_14;
V_217 -> V_39 . V_220 = F_71 ( V_159 [ 0 ] ) ;
V_9 = F_74 ( & V_217 -> V_128 [ 0 ] , V_7 , V_158 ) ;
if ( V_9 )
goto V_14;
for ( V_216 = NULL , V_127 = V_135 -> V_148 ; V_127 ;
V_216 = V_127 , V_127 = V_127 -> V_115 ) {
V_9 = - V_15 ;
if ( ! strcmp ( V_217 -> V_133 . V_33 , V_127 -> V_133 . V_33 ) &&
( ! V_127 -> V_39 . V_220 || ! V_217 -> V_39 . V_220 ||
V_217 -> V_39 . V_220 == V_127 -> V_39 . V_220 ) ) {
F_31 ( V_153 L_37 ,
V_135 -> V_147 , V_127 -> V_133 . V_33 ) ;
goto V_14;
}
V_166 = strlen ( V_217 -> V_133 . V_33 ) ;
V_187 = strlen ( V_127 -> V_133 . V_33 ) ;
if ( V_166 > V_187 )
break;
}
V_217 -> V_115 = V_127 ;
if ( V_216 )
V_216 -> V_115 = V_217 ;
else
V_135 -> V_148 = V_217 ;
V_217 = NULL ;
}
}
V_9 = 0 ;
V_14:
if ( V_219 )
F_7 ( V_219 -> V_147 ) ;
F_7 ( V_219 ) ;
F_53 ( V_217 , V_132 ) ;
return V_9 ;
}
static int F_101 ( struct V_6 * V_7 , struct V_1 * V_4 ,
void * V_158 )
{
int V_3 , V_175 , V_9 ;
T_1 V_97 , V_166 ;
T_2 V_159 [ 3 ] ;
struct V_126 * V_216 , * V_127 ;
T_1 V_221 [ 8 ] ;
for ( V_3 = 0 ; V_3 < V_4 -> V_222 ; V_3 ++ ) {
V_9 = F_70 ( V_159 , V_158 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_14;
V_97 = F_71 ( V_159 [ 0 ] ) ;
V_216 = NULL ;
for ( V_175 = 0 ; V_175 < V_97 ; V_175 ++ ) {
V_9 = - V_12 ;
V_127 = F_4 ( sizeof( * V_127 ) , V_13 ) ;
if ( ! V_127 )
goto V_14;
if ( V_216 )
V_216 -> V_115 = V_127 ;
else
V_7 -> V_146 [ V_3 ] = V_127 ;
V_216 = V_127 ;
switch ( V_3 ) {
case V_129 :
V_9 = F_70 ( V_159 , V_158 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_14;
V_127 -> V_155 [ 0 ] = F_71 ( V_159 [ 0 ] ) ;
V_9 = F_74 ( & V_127 -> V_128 [ 0 ] , V_7 , V_158 ) ;
if ( V_9 )
goto V_14;
break;
case V_130 :
case V_131 :
V_9 = F_70 ( V_159 , V_158 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_14;
V_166 = F_71 ( V_159 [ 0 ] ) ;
V_9 = - V_12 ;
V_127 -> V_133 . V_33 = F_36 ( V_166 + 1 , V_13 ) ;
if ( ! V_127 -> V_133 . V_33 )
goto V_14;
V_9 = F_70 ( V_127 -> V_133 . V_33 , V_158 , V_166 ) ;
if ( V_9 )
goto V_14;
V_127 -> V_133 . V_33 [ V_166 ] = 0 ;
V_9 = F_74 ( & V_127 -> V_128 [ 0 ] , V_7 , V_158 ) ;
if ( V_9 )
goto V_14;
V_9 = F_74 ( & V_127 -> V_128 [ 1 ] , V_7 , V_158 ) ;
if ( V_9 )
goto V_14;
break;
case V_223 :
V_9 = F_70 ( V_159 , V_158 , sizeof( T_1 ) * 3 ) ;
if ( V_9 )
goto V_14;
V_127 -> V_133 . V_224 . V_225 = F_71 ( V_159 [ 0 ] ) ;
V_127 -> V_133 . V_224 . V_226 = F_71 ( V_159 [ 1 ] ) ;
V_127 -> V_133 . V_224 . V_227 = F_71 ( V_159 [ 2 ] ) ;
V_9 = F_74 ( & V_127 -> V_128 [ 0 ] , V_7 , V_158 ) ;
if ( V_9 )
goto V_14;
break;
case V_228 :
V_9 = F_70 ( V_221 , V_158 , sizeof( T_1 ) * 2 ) ;
if ( V_9 )
goto V_14;
V_127 -> V_133 . V_206 . V_229 = V_221 [ 0 ] ;
V_127 -> V_133 . V_206 . V_230 = V_221 [ 1 ] ;
V_9 = F_74 ( & V_127 -> V_128 [ 0 ] , V_7 , V_158 ) ;
if ( V_9 )
goto V_14;
break;
case V_132 :
V_9 = F_70 ( V_159 , V_158 , sizeof( T_1 ) * 2 ) ;
if ( V_9 )
goto V_14;
V_9 = - V_15 ;
V_127 -> V_39 . V_231 = F_71 ( V_159 [ 0 ] ) ;
if ( V_127 -> V_39 . V_231 > V_232 )
goto V_14;
V_9 = - V_12 ;
V_166 = F_71 ( V_159 [ 1 ] ) ;
V_127 -> V_133 . V_33 = F_36 ( V_166 + 1 , V_13 ) ;
if ( ! V_127 -> V_133 . V_33 )
goto V_14;
V_9 = F_70 ( V_127 -> V_133 . V_33 , V_158 , V_166 ) ;
if ( V_9 )
goto V_14;
V_127 -> V_133 . V_33 [ V_166 ] = 0 ;
V_9 = F_74 ( & V_127 -> V_128 [ 0 ] , V_7 , V_158 ) ;
if ( V_9 )
goto V_14;
break;
case V_233 : {
int V_24 ;
V_9 = F_70 ( V_221 , V_158 , sizeof( T_1 ) * 8 ) ;
if ( V_9 )
goto V_14;
for ( V_24 = 0 ; V_24 < 4 ; V_24 ++ )
V_127 -> V_133 . V_234 . V_229 [ V_24 ] = V_221 [ V_24 ] ;
for ( V_24 = 0 ; V_24 < 4 ; V_24 ++ )
V_127 -> V_133 . V_234 . V_230 [ V_24 ] = V_221 [ V_24 + 4 ] ;
V_9 = F_74 ( & V_127 -> V_128 [ 0 ] , V_7 , V_158 ) ;
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
int F_102 ( struct V_6 * V_7 , void * V_158 )
{
struct V_138 * V_139 , * V_140 ;
struct V_141 * V_142 , * V_143 ;
int V_3 , V_175 , V_9 ;
T_2 V_159 [ 4 ] ;
T_1 V_166 , V_18 , V_97 ;
char * V_235 ;
struct V_1 * V_4 ;
V_9 = F_13 ( V_7 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_70 ( V_159 , V_158 , sizeof( T_1 ) * 2 ) ;
if ( V_9 )
goto V_167;
V_9 = - V_15 ;
if ( F_71 ( V_159 [ 0 ] ) != V_236 ) {
F_31 ( V_153 L_38
L_39 ,
F_71 ( V_159 [ 0 ] ) , V_236 ) ;
goto V_167;
}
V_9 = - V_15 ;
V_166 = F_71 ( V_159 [ 1 ] ) ;
if ( V_166 != strlen ( V_237 ) ) {
F_31 ( V_153 L_40
L_41 ,
V_166 , strlen ( V_237 ) ) ;
goto V_167;
}
V_9 = - V_12 ;
V_235 = F_36 ( V_166 + 1 , V_13 ) ;
if ( ! V_235 ) {
F_31 ( V_153 L_42
L_43 , V_166 ) ;
goto V_167;
}
V_9 = F_70 ( V_235 , V_158 , V_166 ) ;
if ( V_9 ) {
F_31 ( V_153 L_44 ) ;
F_7 ( V_235 ) ;
goto V_167;
}
V_9 = - V_15 ;
V_235 [ V_166 ] = '\0' ;
if ( strcmp ( V_235 , V_237 ) ) {
F_31 ( V_153 L_45
L_46 , V_235 , V_237 ) ;
F_7 ( V_235 ) ;
goto V_167;
}
F_7 ( V_235 ) ;
V_235 = NULL ;
V_9 = F_70 ( V_159 , V_158 , sizeof( T_1 ) * 4 ) ;
if ( V_9 )
goto V_167;
V_9 = - V_15 ;
V_7 -> V_162 = F_71 ( V_159 [ 0 ] ) ;
if ( V_7 -> V_162 < V_238 ||
V_7 -> V_162 > V_239 ) {
F_31 ( V_153 L_47
L_48 ,
F_71 ( V_159 [ 0 ] ) , V_238 , V_239 ) ;
goto V_167;
}
if ( ( F_71 ( V_159 [ 1 ] ) & V_240 ) ) {
V_7 -> V_103 = 1 ;
V_9 = - V_15 ;
if ( V_7 -> V_162 < V_163 ) {
F_31 ( V_153 L_49
L_50 ,
V_7 -> V_162 ) ;
goto V_167;
}
}
V_7 -> V_241 = ! ! ( F_71 ( V_159 [ 1 ] ) & V_242 ) ;
V_7 -> V_243 = ! ! ( F_71 ( V_159 [ 1 ] ) & V_244 ) ;
if ( V_7 -> V_162 >= V_245 ) {
V_9 = F_72 ( & V_7 -> V_52 , V_158 ) ;
if ( V_9 )
goto V_167;
}
if ( V_7 -> V_162 >= V_246 ) {
V_9 = F_72 ( & V_7 -> V_53 , V_158 ) ;
if ( V_9 )
goto V_167;
}
V_9 = - V_15 ;
V_4 = F_1 ( V_7 -> V_162 ) ;
if ( ! V_4 ) {
F_31 ( V_153 L_51
L_52 , V_7 -> V_162 ) ;
goto V_167;
}
V_9 = - V_15 ;
if ( F_71 ( V_159 [ 2 ] ) != V_4 -> V_247 ||
F_71 ( V_159 [ 3 ] ) != V_4 -> V_222 ) {
F_31 ( V_153 L_53
L_54 , F_71 ( V_159 [ 2 ] ) ,
F_71 ( V_159 [ 3 ] ) ,
V_4 -> V_247 , V_4 -> V_222 ) ;
goto V_167;
}
for ( V_3 = 0 ; V_3 < V_4 -> V_247 ; V_3 ++ ) {
V_9 = F_70 ( V_159 , V_158 , sizeof( T_1 ) * 2 ) ;
if ( V_9 )
goto V_167;
V_18 = F_71 ( V_159 [ 0 ] ) ;
V_97 = F_71 ( V_159 [ 1 ] ) ;
for ( V_175 = 0 ; V_175 < V_97 ; V_175 ++ ) {
V_9 = V_248 [ V_3 ] ( V_7 , V_7 -> V_47 [ V_3 ] . V_21 , V_158 ) ;
if ( V_9 )
goto V_167;
}
V_7 -> V_47 [ V_3 ] . V_18 = V_18 ;
}
V_9 = - V_15 ;
V_7 -> V_210 = F_94 ( V_7 , L_55 ) ;
if ( ! V_7 -> V_210 )
goto V_167;
V_9 = F_103 ( & V_7 -> V_49 , V_158 , V_7 ) ;
if ( V_9 )
goto V_167;
if ( V_7 -> V_162 >= V_249 ) {
V_9 = F_104 ( V_7 , V_158 ) ;
if ( V_9 )
goto V_167;
}
V_9 = F_70 ( V_159 , V_158 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_167;
V_97 = F_71 ( V_159 [ 0 ] ) ;
V_143 = NULL ;
for ( V_3 = 0 ; V_3 < V_97 ; V_3 ++ ) {
V_9 = - V_12 ;
V_142 = F_4 ( sizeof( * V_142 ) , V_13 ) ;
if ( ! V_142 )
goto V_167;
if ( V_143 )
V_143 -> V_115 = V_142 ;
else
V_7 -> V_149 = V_142 ;
V_9 = F_70 ( V_159 , V_158 , sizeof( T_1 ) * 3 ) ;
if ( V_9 )
goto V_167;
V_9 = - V_15 ;
V_142 -> V_11 = F_71 ( V_159 [ 0 ] ) ;
V_142 -> type = F_71 ( V_159 [ 1 ] ) ;
V_142 -> V_250 = F_71 ( V_159 [ 2 ] ) ;
if ( V_7 -> V_162 >= V_251 ) {
V_9 = F_70 ( V_159 , V_158 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_167;
V_142 -> V_32 = F_71 ( V_159 [ 0 ] ) ;
} else
V_142 -> V_32 = V_7 -> V_210 ;
if ( ! F_64 ( V_7 , V_142 -> V_11 ) ||
! F_65 ( V_7 , V_142 -> type ) ||
! F_63 ( V_7 , V_142 -> V_32 ) ||
! F_64 ( V_7 , V_142 -> V_250 ) )
goto V_167;
V_143 = V_142 ;
}
V_9 = F_70 ( V_159 , V_158 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_167;
V_97 = F_71 ( V_159 [ 0 ] ) ;
V_140 = NULL ;
for ( V_3 = 0 ; V_3 < V_97 ; V_3 ++ ) {
V_9 = - V_12 ;
V_139 = F_4 ( sizeof( * V_139 ) , V_13 ) ;
if ( ! V_139 )
goto V_167;
if ( V_140 )
V_140 -> V_115 = V_139 ;
else
V_7 -> V_138 = V_139 ;
V_9 = F_70 ( V_159 , V_158 , sizeof( T_1 ) * 2 ) ;
if ( V_9 )
goto V_167;
V_9 = - V_15 ;
V_139 -> V_11 = F_71 ( V_159 [ 0 ] ) ;
V_139 -> V_250 = F_71 ( V_159 [ 1 ] ) ;
if ( ! F_64 ( V_7 , V_139 -> V_11 ) ||
! F_64 ( V_7 , V_139 -> V_250 ) )
goto V_167;
V_140 = V_139 ;
}
V_9 = F_98 ( V_7 , V_158 ) ;
if ( V_9 )
goto V_167;
V_9 = F_33 ( V_7 ) ;
if ( V_9 )
goto V_167;
V_9 = - V_15 ;
V_7 -> V_252 = F_95 ( V_7 , V_7 -> V_210 , L_56 ) ;
V_7 -> V_252 |= F_95 ( V_7 , V_7 -> V_210 , L_57 ) ;
if ( ! V_7 -> V_252 )
goto V_167;
V_9 = F_101 ( V_7 , V_4 , V_158 ) ;
if ( V_9 )
goto V_167;
V_9 = F_100 ( V_7 , V_158 ) ;
if ( V_9 )
goto V_167;
V_9 = F_96 ( V_7 , V_158 ) ;
if ( V_9 )
goto V_167;
V_9 = - V_12 ;
V_7 -> V_150 = F_37 ( sizeof( struct V_151 ) ,
V_7 -> V_75 . V_18 ,
V_13 | V_63 ) ;
if ( ! V_7 -> V_150 )
goto V_167;
V_9 = F_38 ( V_7 -> V_150 , 0 , V_7 -> V_75 . V_18 ,
V_13 | V_63 ) ;
if ( V_9 )
goto V_167;
for ( V_3 = 0 ; V_3 < V_7 -> V_75 . V_18 ; V_3 ++ ) {
struct V_151 * V_110 = F_59 ( V_7 -> V_150 , V_3 ) ;
F_92 ( ! V_110 ) ;
F_18 ( V_110 ) ;
if ( V_7 -> V_162 >= V_253 ) {
V_9 = F_72 ( V_110 , V_158 ) ;
if ( V_9 )
goto V_167;
}
V_9 = F_99 ( V_110 , V_3 , 1 ) ;
if ( V_9 )
goto V_167;
}
V_9 = F_93 ( V_7 ) ;
if ( V_9 )
goto V_167;
V_9 = 0 ;
V_14:
return V_9 ;
V_167:
F_55 ( V_7 ) ;
goto V_14;
}
static int F_105 ( struct V_201 * V_216 , void * V_158 )
{
T_2 V_159 [ 1 ] ;
int V_9 ;
V_159 [ 0 ] = F_106 ( V_216 -> V_87 ) ;
V_9 = F_107 ( V_159 , sizeof( T_1 ) , 1 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_108 ( & V_216 -> V_122 , V_158 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_109 ( struct V_124 * V_157 , void * V_158 )
{
T_2 V_159 [ 3 ] ;
T_4 V_160 ;
int V_9 , V_254 ;
V_254 = F_110 ( & V_157 -> V_86 [ 1 ] , & V_157 -> V_86 [ 0 ] ) ;
if ( V_254 )
V_160 = 2 ;
else
V_160 = 3 ;
V_159 [ 0 ] = F_106 ( V_160 - 1 ) ;
V_159 [ 1 ] = F_106 ( V_157 -> V_86 [ 0 ] . V_87 ) ;
if ( ! V_254 )
V_159 [ 2 ] = F_106 ( V_157 -> V_86 [ 1 ] . V_87 ) ;
F_92 ( V_160 > ( sizeof( V_159 ) / sizeof( V_159 [ 0 ] ) ) ) ;
V_9 = F_107 ( V_159 , sizeof( T_1 ) , V_160 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_108 ( & V_157 -> V_86 [ 0 ] . V_122 , V_158 ) ;
if ( V_9 )
return V_9 ;
if ( ! V_254 ) {
V_9 = F_108 ( & V_157 -> V_86 [ 1 ] . V_122 , V_158 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
static int F_111 ( void * V_255 , void * V_54 , void * V_256 )
{
char * V_8 = V_255 ;
struct V_83 * V_84 = V_54 ;
struct V_257 * V_258 = V_256 ;
void * V_158 = V_258 -> V_158 ;
T_2 V_159 [ 2 ] ;
T_4 V_166 ;
int V_9 ;
V_166 = strlen ( V_8 ) ;
V_159 [ 0 ] = F_106 ( V_166 ) ;
V_159 [ 1 ] = F_106 ( V_84 -> V_85 ) ;
V_9 = F_107 ( V_159 , sizeof( T_1 ) , 2 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_107 ( V_8 , 1 , V_166 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_105 ( V_84 -> V_86 , V_158 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_112 ( void * V_255 , void * V_54 , void * V_256 )
{
char * V_8 = V_255 ;
struct V_90 * V_91 = V_54 ;
struct V_257 * V_258 = V_256 ;
void * V_158 = V_258 -> V_158 ;
T_2 V_159 [ 3 ] ;
T_4 V_166 ;
int V_9 ;
V_166 = strlen ( V_8 ) ;
V_159 [ 0 ] = F_106 ( V_166 ) ;
V_159 [ 1 ] = F_106 ( V_91 -> V_16 ) ;
V_159 [ 2 ] = F_106 ( V_91 -> V_85 ) ;
V_9 = F_107 ( V_159 , sizeof( T_1 ) , 3 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_107 ( V_8 , 1 , V_166 , V_158 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_113 ( struct V_6 * V_7 , void * V_158 )
{
struct V_141 * V_157 = V_7 -> V_149 ;
struct V_141 * V_142 ;
T_1 V_159 [ 3 ] ;
T_4 V_97 ;
int V_9 ;
V_97 = 0 ;
for ( V_142 = V_157 ; V_142 ; V_142 = V_142 -> V_115 )
V_97 ++ ;
V_159 [ 0 ] = F_106 ( V_97 ) ;
V_9 = F_107 ( V_159 , sizeof( T_1 ) , 1 , V_158 ) ;
if ( V_9 )
return V_9 ;
for ( V_142 = V_157 ; V_142 ; V_142 = V_142 -> V_115 ) {
V_159 [ 0 ] = F_106 ( V_142 -> V_11 ) ;
V_159 [ 1 ] = F_106 ( V_142 -> type ) ;
V_159 [ 2 ] = F_106 ( V_142 -> V_250 ) ;
V_9 = F_107 ( V_159 , sizeof( T_1 ) , 3 , V_158 ) ;
if ( V_9 )
return V_9 ;
if ( V_7 -> V_162 >= V_251 ) {
V_159 [ 0 ] = F_106 ( V_142 -> V_32 ) ;
V_9 = F_107 ( V_159 , sizeof( T_1 ) , 1 , V_158 ) ;
if ( V_9 )
return V_9 ;
}
}
return 0 ;
}
static int F_114 ( struct V_138 * V_157 , void * V_158 )
{
struct V_138 * V_139 ;
T_1 V_159 [ 2 ] ;
T_4 V_97 ;
int V_9 ;
V_97 = 0 ;
for ( V_139 = V_157 ; V_139 ; V_139 = V_139 -> V_115 )
V_97 ++ ;
V_159 [ 0 ] = F_106 ( V_97 ) ;
V_9 = F_107 ( V_159 , sizeof( T_1 ) , 1 , V_158 ) ;
if ( V_9 )
return V_9 ;
for ( V_139 = V_157 ; V_139 ; V_139 = V_139 -> V_115 ) {
V_159 [ 0 ] = F_106 ( V_139 -> V_11 ) ;
V_159 [ 1 ] = F_106 ( V_139 -> V_250 ) ;
V_9 = F_107 ( V_159 , sizeof( T_1 ) , 2 , V_158 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
static int F_115 ( struct V_6 * V_7 , struct V_128 * V_127 ,
void * V_158 )
{
int V_9 ;
T_2 V_159 [ 3 ] ;
V_159 [ 0 ] = F_106 ( V_127 -> V_154 ) ;
V_159 [ 1 ] = F_106 ( V_127 -> V_11 ) ;
V_159 [ 2 ] = F_106 ( V_127 -> type ) ;
V_9 = F_107 ( V_159 , sizeof( T_1 ) , 3 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_109 ( & V_127 -> V_121 , V_158 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_116 ( void * V_255 , void * V_54 , void * V_158 )
{
char * V_8 = V_255 ;
struct V_164 * V_165 = V_54 ;
T_2 V_159 [ 2 ] ;
T_4 V_166 ;
int V_9 ;
V_166 = strlen ( V_8 ) ;
V_159 [ 0 ] = F_106 ( V_166 ) ;
V_159 [ 1 ] = F_106 ( V_165 -> V_16 ) ;
V_9 = F_107 ( V_159 , sizeof( T_1 ) , 2 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_107 ( V_8 , 1 , V_166 , V_158 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_117 ( void * V_255 , void * V_54 , void * V_256 )
{
char * V_8 = V_255 ;
struct V_56 * V_57 = V_54 ;
struct V_257 * V_258 = V_256 ;
void * V_158 = V_258 -> V_158 ;
T_2 V_159 [ 4 ] ;
T_4 V_166 ;
int V_9 ;
V_166 = strlen ( V_8 ) ;
V_159 [ 0 ] = F_106 ( V_166 ) ;
V_159 [ 1 ] = F_106 ( V_57 -> V_16 ) ;
V_159 [ 2 ] = F_106 ( V_57 -> V_105 . V_18 ) ;
V_159 [ 3 ] = F_106 ( V_57 -> V_105 . V_21 -> V_97 ) ;
V_9 = F_107 ( V_159 , sizeof( T_1 ) , 4 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_107 ( V_8 , 1 , V_166 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_40 ( V_57 -> V_105 . V_21 , F_116 , V_158 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_118 ( struct V_6 * V_7 , struct V_106 * V_206 ,
void * V_158 )
{
struct V_106 * V_127 ;
struct V_109 * V_110 ;
T_2 V_159 [ 3 ] ;
T_1 V_97 ;
int V_9 ;
for ( V_127 = V_206 ; V_127 ; V_127 = V_127 -> V_115 ) {
V_97 = 0 ;
for ( V_110 = V_127 -> V_113 ; V_110 ; V_110 = V_110 -> V_115 )
V_97 ++ ;
V_159 [ 0 ] = F_106 ( V_127 -> V_105 ) ;
V_159 [ 1 ] = F_106 ( V_97 ) ;
V_9 = F_107 ( V_159 , sizeof( T_1 ) , 2 , V_158 ) ;
if ( V_9 )
return V_9 ;
for ( V_110 = V_127 -> V_113 ; V_110 ; V_110 = V_110 -> V_115 ) {
V_159 [ 0 ] = F_106 ( V_110 -> V_177 ) ;
V_159 [ 1 ] = F_106 ( V_110 -> V_178 ) ;
V_159 [ 2 ] = F_106 ( V_110 -> V_179 ) ;
V_9 = F_107 ( V_159 , sizeof( T_1 ) , 3 , V_158 ) ;
if ( V_9 )
return V_9 ;
switch ( V_110 -> V_177 ) {
case V_185 :
V_9 = F_108 ( & V_110 -> V_114 , V_158 ) ;
if ( V_9 )
return V_9 ;
break;
default:
break;
}
}
}
return 0 ;
}
static int F_119 ( void * V_255 , void * V_54 , void * V_256 )
{
char * V_8 = V_255 ;
struct V_64 * V_65 = V_54 ;
struct V_257 * V_258 = V_256 ;
void * V_158 = V_258 -> V_158 ;
struct V_6 * V_7 = V_258 -> V_7 ;
struct V_106 * V_127 ;
T_2 V_159 [ 6 ] ;
T_1 V_170 ;
T_4 V_166 , V_187 ;
int V_9 ;
V_166 = strlen ( V_8 ) ;
if ( V_65 -> V_117 )
V_187 = strlen ( V_65 -> V_117 ) ;
else
V_187 = 0 ;
V_170 = 0 ;
for ( V_127 = V_65 -> V_112 ; V_127 ; V_127 = V_127 -> V_115 )
V_170 ++ ;
V_159 [ 0 ] = F_106 ( V_166 ) ;
V_159 [ 1 ] = F_106 ( V_187 ) ;
V_159 [ 2 ] = F_106 ( V_65 -> V_16 ) ;
V_159 [ 3 ] = F_106 ( V_65 -> V_105 . V_18 ) ;
if ( V_65 -> V_105 . V_21 )
V_159 [ 4 ] = F_106 ( V_65 -> V_105 . V_21 -> V_97 ) ;
else
V_159 [ 4 ] = 0 ;
V_159 [ 5 ] = F_106 ( V_170 ) ;
V_9 = F_107 ( V_159 , sizeof( T_1 ) , 6 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_107 ( V_8 , 1 , V_166 , V_158 ) ;
if ( V_9 )
return V_9 ;
if ( V_65 -> V_117 ) {
V_9 = F_107 ( V_65 -> V_117 , 1 , V_187 , V_158 ) ;
if ( V_9 )
return V_9 ;
}
V_9 = F_40 ( V_65 -> V_105 . V_21 , F_116 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_118 ( V_7 , V_65 -> V_112 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_170 = 0 ;
for ( V_127 = V_65 -> V_116 ; V_127 ; V_127 = V_127 -> V_115 )
V_170 ++ ;
V_159 [ 0 ] = F_106 ( V_170 ) ;
V_9 = F_107 ( V_159 , sizeof( T_1 ) , 1 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_118 ( V_7 , V_65 -> V_116 , V_158 ) ;
if ( V_9 )
return V_9 ;
if ( V_7 -> V_162 >= V_189 ) {
V_159 [ 0 ] = F_106 ( V_65 -> V_190 ) ;
V_159 [ 1 ] = F_106 ( V_65 -> V_191 ) ;
V_159 [ 2 ] = F_106 ( V_65 -> V_192 ) ;
V_9 = F_107 ( V_159 , sizeof( V_259 ) , 3 , V_158 ) ;
if ( V_9 )
return V_9 ;
}
if ( V_7 -> V_162 >= V_193 ) {
V_159 [ 0 ] = F_106 ( V_65 -> V_194 ) ;
V_9 = F_107 ( V_159 , sizeof( V_259 ) , 1 , V_158 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
static int F_120 ( void * V_255 , void * V_54 , void * V_256 )
{
char * V_8 = V_255 ;
struct V_10 * V_11 = V_54 ;
struct V_257 * V_258 = V_256 ;
void * V_158 = V_258 -> V_158 ;
struct V_6 * V_7 = V_258 -> V_7 ;
T_2 V_159 [ 3 ] ;
T_4 V_160 , V_166 ;
int V_9 ;
V_166 = strlen ( V_8 ) ;
V_160 = 0 ;
V_159 [ V_160 ++ ] = F_106 ( V_166 ) ;
V_159 [ V_160 ++ ] = F_106 ( V_11 -> V_16 ) ;
if ( V_7 -> V_162 >= V_196 )
V_159 [ V_160 ++ ] = F_106 ( V_11 -> V_69 ) ;
F_92 ( V_160 > ( sizeof( V_159 ) / sizeof( V_159 [ 0 ] ) ) ) ;
V_9 = F_107 ( V_159 , sizeof( T_1 ) , V_160 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_107 ( V_8 , 1 , V_166 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_108 ( & V_11 -> V_118 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_108 ( & V_11 -> V_119 , V_158 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_121 ( void * V_255 , void * V_54 , void * V_256 )
{
char * V_8 = V_255 ;
struct V_72 * V_73 = V_54 ;
struct V_257 * V_258 = V_256 ;
struct V_6 * V_7 = V_258 -> V_7 ;
void * V_158 = V_258 -> V_158 ;
T_2 V_159 [ 4 ] ;
int V_9 ;
T_4 V_160 , V_166 ;
V_166 = strlen ( V_8 ) ;
V_160 = 0 ;
V_159 [ V_160 ++ ] = F_106 ( V_166 ) ;
V_159 [ V_160 ++ ] = F_106 ( V_73 -> V_16 ) ;
if ( V_7 -> V_162 >= V_196 ) {
T_1 V_260 = 0 ;
if ( V_73 -> V_74 )
V_260 |= V_198 ;
if ( V_73 -> V_200 )
V_260 |= V_199 ;
V_159 [ V_160 ++ ] = F_106 ( V_260 ) ;
V_159 [ V_160 ++ ] = F_106 ( V_73 -> V_69 ) ;
} else {
V_159 [ V_160 ++ ] = F_106 ( V_73 -> V_74 ) ;
}
F_92 ( V_160 > ( sizeof( V_159 ) / sizeof( V_159 [ 0 ] ) ) ) ;
V_9 = F_107 ( V_159 , sizeof( T_1 ) , V_160 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_107 ( V_8 , 1 , V_166 , V_158 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_122 ( void * V_255 , void * V_54 , void * V_256 )
{
char * V_8 = V_255 ;
struct V_78 * V_79 = V_54 ;
struct V_257 * V_258 = V_256 ;
struct V_6 * V_7 = V_258 -> V_7 ;
void * V_158 = V_258 -> V_158 ;
T_2 V_159 [ 3 ] ;
T_4 V_160 , V_166 ;
int V_9 ;
V_166 = strlen ( V_8 ) ;
V_160 = 0 ;
V_159 [ V_160 ++ ] = F_106 ( V_166 ) ;
V_159 [ V_160 ++ ] = F_106 ( V_79 -> V_16 ) ;
if ( V_7 -> V_162 >= V_196 )
V_159 [ V_160 ++ ] = F_106 ( V_79 -> V_69 ) ;
F_92 ( V_160 > ( sizeof( V_159 ) / sizeof( V_159 [ 0 ] ) ) ) ;
V_9 = F_107 ( V_159 , sizeof( T_1 ) , V_160 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_107 ( V_8 , 1 , V_166 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_108 ( & V_79 -> V_120 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_109 ( & V_79 -> V_121 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_105 ( & V_79 -> V_123 , V_158 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_123 ( struct V_6 * V_7 , struct V_1 * V_4 ,
void * V_158 )
{
unsigned int V_3 , V_175 , V_9 ;
T_4 V_97 , V_166 ;
T_2 V_159 [ 3 ] ;
T_1 V_221 [ 8 ] ;
struct V_126 * V_127 ;
for ( V_3 = 0 ; V_3 < V_4 -> V_222 ; V_3 ++ ) {
V_97 = 0 ;
for ( V_127 = V_7 -> V_146 [ V_3 ] ; V_127 ; V_127 = V_127 -> V_115 )
V_97 ++ ;
V_159 [ 0 ] = F_106 ( V_97 ) ;
V_9 = F_107 ( V_159 , sizeof( T_1 ) , 1 , V_158 ) ;
if ( V_9 )
return V_9 ;
for ( V_127 = V_7 -> V_146 [ V_3 ] ; V_127 ; V_127 = V_127 -> V_115 ) {
switch ( V_3 ) {
case V_129 :
V_159 [ 0 ] = F_106 ( V_127 -> V_155 [ 0 ] ) ;
V_9 = F_107 ( V_159 , sizeof( T_1 ) , 1 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_115 ( V_7 , & V_127 -> V_128 [ 0 ] , V_158 ) ;
if ( V_9 )
return V_9 ;
break;
case V_130 :
case V_131 :
V_166 = strlen ( V_127 -> V_133 . V_33 ) ;
V_159 [ 0 ] = F_106 ( V_166 ) ;
V_9 = F_107 ( V_159 , sizeof( T_1 ) , 1 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_107 ( V_127 -> V_133 . V_33 , 1 , V_166 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_115 ( V_7 , & V_127 -> V_128 [ 0 ] , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_115 ( V_7 , & V_127 -> V_128 [ 1 ] , V_158 ) ;
if ( V_9 )
return V_9 ;
break;
case V_223 :
V_159 [ 0 ] = F_106 ( V_127 -> V_133 . V_224 . V_225 ) ;
V_159 [ 1 ] = F_106 ( V_127 -> V_133 . V_224 . V_226 ) ;
V_159 [ 2 ] = F_106 ( V_127 -> V_133 . V_224 . V_227 ) ;
V_9 = F_107 ( V_159 , sizeof( T_1 ) , 3 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_115 ( V_7 , & V_127 -> V_128 [ 0 ] , V_158 ) ;
if ( V_9 )
return V_9 ;
break;
case V_228 :
V_221 [ 0 ] = V_127 -> V_133 . V_206 . V_229 ;
V_221 [ 1 ] = V_127 -> V_133 . V_206 . V_230 ;
V_9 = F_107 ( V_221 , sizeof( T_1 ) , 2 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_115 ( V_7 , & V_127 -> V_128 [ 0 ] , V_158 ) ;
if ( V_9 )
return V_9 ;
break;
case V_132 :
V_159 [ 0 ] = F_106 ( V_127 -> V_39 . V_231 ) ;
V_166 = strlen ( V_127 -> V_133 . V_33 ) ;
V_159 [ 1 ] = F_106 ( V_166 ) ;
V_9 = F_107 ( V_159 , sizeof( T_1 ) , 2 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_107 ( V_127 -> V_133 . V_33 , 1 , V_166 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_115 ( V_7 , & V_127 -> V_128 [ 0 ] , V_158 ) ;
if ( V_9 )
return V_9 ;
break;
case V_233 :
for ( V_175 = 0 ; V_175 < 4 ; V_175 ++ )
V_221 [ V_175 ] = V_127 -> V_133 . V_234 . V_229 [ V_175 ] ;
for ( V_175 = 0 ; V_175 < 4 ; V_175 ++ )
V_221 [ V_175 + 4 ] = V_127 -> V_133 . V_234 . V_230 [ V_175 ] ;
V_9 = F_107 ( V_221 , sizeof( T_1 ) , 8 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_115 ( V_7 , & V_127 -> V_128 [ 0 ] , V_158 ) ;
if ( V_9 )
return V_9 ;
break;
}
}
}
return 0 ;
}
static int F_124 ( struct V_6 * V_7 , void * V_158 )
{
struct V_135 * V_135 ;
struct V_126 * V_127 ;
T_4 V_166 ;
T_2 V_159 [ 1 ] ;
int V_9 ;
V_166 = 0 ;
for ( V_135 = V_7 -> V_135 ; V_135 ; V_135 = V_135 -> V_115 )
V_166 ++ ;
V_159 [ 0 ] = F_106 ( V_166 ) ;
V_9 = F_107 ( V_159 , sizeof( T_1 ) , 1 , V_158 ) ;
if ( V_9 )
return V_9 ;
for ( V_135 = V_7 -> V_135 ; V_135 ; V_135 = V_135 -> V_115 ) {
V_166 = strlen ( V_135 -> V_147 ) ;
V_159 [ 0 ] = F_106 ( V_166 ) ;
V_9 = F_107 ( V_159 , sizeof( T_1 ) , 1 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_107 ( V_135 -> V_147 , 1 , V_166 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_166 = 0 ;
for ( V_127 = V_135 -> V_148 ; V_127 ; V_127 = V_127 -> V_115 )
V_166 ++ ;
V_159 [ 0 ] = F_106 ( V_166 ) ;
V_9 = F_107 ( V_159 , sizeof( T_1 ) , 1 , V_158 ) ;
if ( V_9 )
return V_9 ;
for ( V_127 = V_135 -> V_148 ; V_127 ; V_127 = V_127 -> V_115 ) {
V_166 = strlen ( V_127 -> V_133 . V_33 ) ;
V_159 [ 0 ] = F_106 ( V_166 ) ;
V_9 = F_107 ( V_159 , sizeof( T_1 ) , 1 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_107 ( V_127 -> V_133 . V_33 , 1 , V_166 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_159 [ 0 ] = F_106 ( V_127 -> V_39 . V_220 ) ;
V_9 = F_107 ( V_159 , sizeof( T_1 ) , 1 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_115 ( V_7 , & V_127 -> V_128 [ 0 ] , V_158 ) ;
if ( V_9 )
return V_9 ;
}
}
return 0 ;
}
static int F_125 ( void * V_8 , void * V_261 , void * V_256 )
{
int * V_262 = V_256 ;
* V_262 = * V_262 + 1 ;
return 0 ;
}
static int F_126 ( void * V_8 , void * V_261 , void * V_256 )
{
T_2 V_159 [ 2 ] ;
struct V_40 * V_125 = V_8 ;
struct V_124 * V_157 = V_261 ;
struct V_257 * V_258 = V_256 ;
void * V_158 = V_258 -> V_158 ;
struct V_6 * V_7 = V_258 -> V_7 ;
int V_9 ;
V_159 [ 0 ] = F_106 ( V_125 -> V_41 ) ;
V_159 [ 1 ] = F_106 ( V_125 -> V_42 ) ;
V_9 = F_107 ( V_159 , sizeof( T_1 ) , 2 , V_158 ) ;
if ( V_9 )
return V_9 ;
if ( V_7 -> V_162 >= V_209 ) {
V_159 [ 0 ] = F_106 ( V_125 -> V_43 ) ;
V_9 = F_107 ( V_159 , sizeof( T_1 ) , 1 , V_158 ) ;
if ( V_9 )
return V_9 ;
}
V_9 = F_109 ( V_157 , V_158 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_127 ( struct V_6 * V_7 , void * V_158 )
{
T_4 V_97 ;
T_2 V_159 [ 1 ] ;
int V_9 ;
struct V_257 V_258 ;
V_258 . V_7 = V_7 ;
V_258 . V_158 = V_158 ;
V_97 = 0 ;
V_9 = F_40 ( V_7 -> V_50 , F_125 , & V_97 ) ;
if ( V_9 )
return V_9 ;
V_159 [ 0 ] = F_106 ( V_97 ) ;
V_9 = F_107 ( V_159 , sizeof( T_1 ) , 1 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_40 ( V_7 -> V_50 , F_126 , & V_258 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_128 ( void * V_8 , void * V_261 , void * V_256 )
{
T_2 V_159 [ 4 ] ;
struct V_25 * V_26 = V_8 ;
struct V_212 * V_213 = V_261 ;
void * V_158 = V_256 ;
int V_9 ;
T_1 V_166 ;
V_166 = strlen ( V_26 -> V_33 ) ;
V_159 [ 0 ] = F_106 ( V_166 ) ;
V_9 = F_107 ( V_159 , sizeof( T_1 ) , 1 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_107 ( V_26 -> V_33 , sizeof( char ) , V_166 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_159 [ 0 ] = V_26 -> V_30 ;
V_159 [ 1 ] = V_26 -> V_31 ;
V_159 [ 2 ] = V_26 -> V_32 ;
V_159 [ 3 ] = V_213 -> V_213 ;
V_9 = F_107 ( V_159 , sizeof( T_1 ) , 4 , V_158 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_129 ( struct V_6 * V_7 , void * V_158 )
{
T_1 V_97 ;
T_2 V_159 [ 1 ] ;
int V_9 ;
if ( V_7 -> V_162 < V_214 )
return 0 ;
V_97 = 0 ;
V_9 = F_40 ( V_7 -> V_25 , F_125 , & V_97 ) ;
if ( V_9 )
return V_9 ;
V_159 [ 0 ] = F_106 ( V_97 ) ;
V_9 = F_107 ( V_159 , sizeof( T_1 ) , 1 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_40 ( V_7 -> V_25 , F_128 , V_158 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
int F_130 ( struct V_6 * V_7 , void * V_158 )
{
unsigned int V_3 , V_263 ;
int V_9 ;
T_2 V_159 [ 4 ] ;
T_1 V_264 ;
T_4 V_166 ;
struct V_1 * V_4 ;
if ( V_7 -> V_162 < V_253 ) {
F_31 ( V_153 L_58
L_59 , V_7 -> V_162 ,
V_253 ) ;
return - V_15 ;
}
V_264 = 0 ;
if ( V_7 -> V_103 )
V_264 |= V_240 ;
if ( V_7 -> V_241 )
V_264 |= V_242 ;
if ( V_7 -> V_243 )
V_264 |= V_244 ;
V_159 [ 0 ] = F_106 ( V_236 ) ;
V_166 = strlen ( V_237 ) ;
V_159 [ 1 ] = F_106 ( V_166 ) ;
V_9 = F_107 ( V_159 , sizeof( T_1 ) , 2 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_107 ( V_237 , 1 , V_166 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_4 = F_1 ( V_7 -> V_162 ) ;
if ( ! V_4 ) {
F_31 ( V_153 L_60
L_61 , V_7 -> V_162 ) ;
return - V_15 ;
}
V_159 [ 0 ] = F_106 ( V_7 -> V_162 ) ;
V_159 [ 1 ] = F_106 ( V_264 ) ;
V_159 [ 2 ] = F_106 ( V_4 -> V_247 ) ;
V_159 [ 3 ] = F_106 ( V_4 -> V_222 ) ;
V_9 = F_107 ( V_159 , sizeof( T_1 ) , 4 , V_158 ) ;
if ( V_9 )
return V_9 ;
if ( V_7 -> V_162 >= V_245 ) {
V_9 = F_108 ( & V_7 -> V_52 , V_158 ) ;
if ( V_9 )
return V_9 ;
}
if ( V_7 -> V_162 >= V_246 ) {
V_9 = F_108 ( & V_7 -> V_53 , V_158 ) ;
if ( V_9 )
return V_9 ;
}
V_263 = V_4 -> V_247 ;
for ( V_3 = 0 ; V_3 < V_263 ; V_3 ++ ) {
struct V_257 V_258 ;
V_258 . V_158 = V_158 ;
V_258 . V_7 = V_7 ;
V_159 [ 0 ] = F_106 ( V_7 -> V_47 [ V_3 ] . V_18 ) ;
V_159 [ 1 ] = F_106 ( V_7 -> V_47 [ V_3 ] . V_21 -> V_97 ) ;
V_9 = F_107 ( V_159 , sizeof( T_1 ) , 2 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_40 ( V_7 -> V_47 [ V_3 ] . V_21 , V_265 [ V_3 ] , & V_258 ) ;
if ( V_9 )
return V_9 ;
}
V_9 = F_131 ( V_7 , & V_7 -> V_49 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_132 ( V_7 , V_7 -> V_266 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_113 ( V_7 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_114 ( V_7 -> V_138 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_129 ( V_7 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_123 ( V_7 , V_4 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_124 ( V_7 , V_158 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_127 ( V_7 , V_158 ) ;
if ( V_9 )
return V_9 ;
for ( V_3 = 0 ; V_3 < V_7 -> V_75 . V_18 ; V_3 ++ ) {
struct V_151 * V_110 = F_59 ( V_7 -> V_150 , V_3 ) ;
F_92 ( ! V_110 ) ;
V_9 = F_108 ( V_110 , V_158 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
