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
V_11 = F_4 ( sizeof( * V_11 ) , V_12 ) ;
if ( ! V_11 )
return - V_13 ;
V_9 = - V_14 ;
V_11 -> V_15 = ++ V_7 -> V_16 . V_17 ;
if ( V_11 -> V_15 != V_18 )
goto V_19;
V_9 = - V_13 ;
V_8 = F_5 ( V_20 , V_12 ) ;
if ( ! V_8 )
goto V_19;
V_9 = F_6 ( V_7 -> V_16 . V_21 , V_8 , V_11 ) ;
if ( V_9 )
goto V_19;
return 0 ;
V_19:
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
goto V_19;
}
V_9 = F_15 ( & V_7 -> V_49 ) ;
if ( V_9 )
goto V_19;
V_9 = F_3 ( V_7 ) ;
if ( V_9 )
goto V_19;
V_9 = F_16 ( V_7 ) ;
if ( V_9 )
goto V_19;
V_7 -> V_25 = F_17 ( F_8 , F_10 , ( 1 << 10 ) ) ;
if ( ! V_7 -> V_25 ) {
V_9 = - V_13 ;
goto V_19;
}
V_7 -> V_50 = F_17 ( F_11 , F_12 , 256 ) ;
if ( ! V_7 -> V_50 ) {
V_9 = - V_13 ;
goto V_19;
}
F_18 ( & V_7 -> V_51 ) ;
F_18 ( & V_7 -> V_52 ) ;
F_18 ( & V_7 -> V_53 ) ;
return 0 ;
V_19:
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
if ( ! V_57 -> V_15 || V_57 -> V_15 > V_7 -> V_60 . V_17 )
return - V_14 ;
V_59 = V_7 -> V_61 [ V_62 ] ;
if ( F_21 ( V_59 , V_57 -> V_15 - 1 , V_8 ,
V_12 | V_63 ) )
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
if ( ! V_65 -> V_15 || V_65 -> V_15 > V_7 -> V_66 . V_17 )
return - V_14 ;
V_59 = V_7 -> V_61 [ V_67 ] ;
if ( F_21 ( V_59 , V_65 -> V_15 - 1 , V_8 ,
V_12 | V_63 ) )
F_22 () ;
V_7 -> V_68 [ V_65 -> V_15 - 1 ] = V_65 ;
return 0 ;
}
static int F_24 ( void * V_8 , void * V_54 , void * V_55 )
{
struct V_6 * V_7 ;
struct V_10 * V_11 ;
struct V_58 * V_59 ;
V_11 = V_54 ;
V_7 = V_55 ;
if ( ! V_11 -> V_15
|| V_11 -> V_15 > V_7 -> V_16 . V_17
|| V_11 -> V_69 > V_7 -> V_16 . V_17 )
return - V_14 ;
V_59 = V_7 -> V_61 [ V_70 ] ;
if ( F_21 ( V_59 , V_11 -> V_15 - 1 , V_8 ,
V_12 | V_63 ) )
F_22 () ;
V_7 -> V_71 [ V_11 -> V_15 - 1 ] = V_11 ;
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
if ( ! V_73 -> V_15
|| V_73 -> V_15 > V_7 -> V_75 . V_17
|| V_73 -> V_69 > V_7 -> V_75 . V_17 )
return - V_14 ;
V_59 = V_7 -> V_61 [ V_76 ] ;
if ( F_21 ( V_59 , V_73 -> V_15 - 1 , V_8 ,
V_12 | V_63 ) )
F_22 () ;
V_59 = V_7 -> V_77 ;
if ( F_21 ( V_59 , V_73 -> V_15 - 1 , V_73 ,
V_12 | V_63 ) )
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
if ( ! V_79 -> V_15
|| V_79 -> V_15 > V_7 -> V_80 . V_17
|| V_79 -> V_69 > V_7 -> V_80 . V_17 )
return - V_14 ;
V_59 = V_7 -> V_61 [ V_81 ] ;
if ( F_21 ( V_59 , V_79 -> V_15 - 1 , V_8 ,
V_12 | V_63 ) )
F_22 () ;
V_7 -> V_82 [ V_79 -> V_15 - 1 ] = V_79 ;
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
V_84 -> V_86 -> V_87 > V_7 -> V_88 . V_17 )
return - V_14 ;
V_59 = V_7 -> V_61 [ V_89 ] ;
if ( F_21 ( V_59 , V_84 -> V_86 -> V_87 - 1 , V_8 ,
V_12 | V_63 ) )
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
if ( ! V_91 -> V_15 || V_91 -> V_15 > V_7 -> V_92 . V_17 )
return - V_14 ;
V_59 = V_7 -> V_61 [ V_93 ] ;
if ( F_21 ( V_59 , V_91 -> V_15 - 1 , V_8 ,
V_12 | V_63 ) )
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
V_7 -> V_80 . V_17 , V_7 -> V_16 . V_17 , V_7 -> V_75 . V_17 , V_7 -> V_102 . V_17 ) ;
if ( V_7 -> V_103 )
F_31 ( V_104 L_4 , V_7 -> V_88 . V_17 ,
V_7 -> V_92 . V_17 ) ;
F_31 ( V_104 L_5 ) ;
F_31 ( V_96 L_6 ,
V_7 -> V_66 . V_17 , V_7 -> V_49 . V_97 ) ;
#ifdef F_34
F_35 ( & V_7 -> V_49 , L_7 ) ;
F_32 ( V_7 -> V_47 ) ;
#endif
V_7 -> V_68 = F_36 ( V_7 -> V_66 . V_17 ,
sizeof( * V_7 -> V_68 ) ,
V_12 ) ;
if ( ! V_7 -> V_68 )
return - V_13 ;
V_7 -> V_71 = F_36 ( V_7 -> V_16 . V_17 ,
sizeof( * V_7 -> V_71 ) ,
V_12 ) ;
if ( ! V_7 -> V_71 )
return - V_13 ;
V_7 -> V_82 = F_36 ( V_7 -> V_80 . V_17 ,
sizeof( * V_7 -> V_82 ) ,
V_12 ) ;
if ( ! V_7 -> V_82 )
return - V_13 ;
V_7 -> V_77 = F_37 ( sizeof( struct V_72 * ) ,
V_7 -> V_75 . V_17 ,
V_12 | V_63 ) ;
if ( ! V_7 -> V_77 )
return - V_13 ;
V_9 = F_38 ( V_7 -> V_77 , 0 ,
V_7 -> V_75 . V_17 , V_12 | V_63 ) ;
if ( V_9 )
goto V_19;
V_9 = F_39 ( V_7 ) ;
if ( V_9 )
goto V_19;
for ( V_3 = 0 ; V_3 < V_46 ; V_3 ++ ) {
V_7 -> V_61 [ V_3 ] = F_37 ( sizeof( char * ) ,
V_7 -> V_47 [ V_3 ] . V_17 ,
V_12 | V_63 ) ;
if ( ! V_7 -> V_61 [ V_3 ] )
return - V_13 ;
V_9 = F_38 ( V_7 -> V_61 [ V_3 ] ,
0 , V_7 -> V_47 [ V_3 ] . V_17 ,
V_12 | V_63 ) ;
if ( V_9 )
goto V_19;
V_9 = F_40 ( V_7 -> V_47 [ V_3 ] . V_21 , V_105 [ V_3 ] , V_7 ) ;
if ( V_9 )
goto V_19;
}
V_9 = 0 ;
V_19:
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
F_40 ( V_57 -> V_106 . V_21 , F_41 , NULL ) ;
F_19 ( V_57 -> V_106 . V_21 ) ;
}
F_7 ( V_54 ) ;
return 0 ;
}
static void F_43 ( struct V_107 * V_108 )
{
if ( V_108 ) {
F_44 ( & V_108 -> V_109 ) ;
if ( V_108 -> V_110 ) {
F_44 ( & V_108 -> V_110 -> V_111 ) ;
F_44 ( & V_108 -> V_110 -> V_112 ) ;
F_7 ( V_108 -> V_110 ) ;
}
F_7 ( V_108 ) ;
}
}
static int F_45 ( void * V_8 , void * V_54 , void * V_7 )
{
struct V_64 * V_65 ;
struct V_113 * V_114 , * V_115 ;
struct V_107 * V_116 , * V_117 ;
F_7 ( V_8 ) ;
if ( V_54 ) {
V_65 = V_54 ;
F_40 ( V_65 -> V_106 . V_21 , F_41 , NULL ) ;
F_19 ( V_65 -> V_106 . V_21 ) ;
V_114 = V_65 -> V_118 ;
while ( V_114 ) {
V_116 = V_114 -> V_108 ;
while ( V_116 ) {
V_117 = V_116 ;
V_116 = V_116 -> V_119 ;
F_43 ( V_117 ) ;
}
V_115 = V_114 ;
V_114 = V_114 -> V_119 ;
F_7 ( V_115 ) ;
}
V_114 = V_65 -> V_120 ;
while ( V_114 ) {
V_116 = V_114 -> V_108 ;
while ( V_116 ) {
V_117 = V_116 ;
V_116 = V_116 -> V_119 ;
F_43 ( V_117 ) ;
}
V_115 = V_114 ;
V_114 = V_114 -> V_119 ;
F_7 ( V_115 ) ;
}
F_7 ( V_65 -> V_121 ) ;
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
F_44 ( & V_11 -> V_122 ) ;
F_44 ( & V_11 -> V_111 ) ;
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
F_44 ( & V_79 -> V_123 ) ;
F_44 ( & V_79 -> V_124 . V_86 [ 0 ] . V_125 ) ;
F_44 ( & V_79 -> V_124 . V_86 [ 1 ] . V_125 ) ;
F_44 ( & V_79 -> V_126 . V_125 ) ;
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
F_44 ( & V_84 -> V_86 -> V_125 ) ;
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
struct V_127 * V_128 = V_54 ;
F_7 ( V_8 ) ;
F_44 ( & V_128 -> V_86 [ 0 ] . V_125 ) ;
F_44 ( & V_128 -> V_86 [ 1 ] . V_125 ) ;
F_7 ( V_54 ) ;
F_52 () ;
return 0 ;
}
static void F_54 ( struct V_129 * V_130 , int V_3 )
{
if ( ! V_130 )
return;
F_55 ( & V_130 -> V_131 [ 0 ] ) ;
F_55 ( & V_130 -> V_131 [ 1 ] ) ;
if ( V_3 == V_132 || V_3 == V_133 ||
V_3 == V_134 || V_3 == V_135 )
F_7 ( V_130 -> V_136 . V_33 ) ;
F_7 ( V_130 ) ;
}
void F_56 ( struct V_6 * V_7 )
{
struct V_129 * V_130 , * V_137 ;
struct V_138 * V_139 , * V_140 ;
int V_3 ;
struct V_141 * V_142 , * V_143 = NULL ;
struct V_144 * V_145 , * V_146 = NULL ;
for ( V_3 = 0 ; V_3 < V_46 ; V_3 ++ ) {
F_52 () ;
F_40 ( V_7 -> V_47 [ V_3 ] . V_21 , V_147 [ V_3 ] , NULL ) ;
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
for ( V_3 = 0 ; V_3 < V_148 ; V_3 ++ ) {
F_52 () ;
V_130 = V_7 -> V_149 [ V_3 ] ;
while ( V_130 ) {
V_137 = V_130 ;
V_130 = V_130 -> V_119 ;
F_54 ( V_137 , V_3 ) ;
}
V_7 -> V_149 [ V_3 ] = NULL ;
}
V_139 = V_7 -> V_138 ;
while ( V_139 ) {
F_52 () ;
F_7 ( V_139 -> V_150 ) ;
V_130 = V_139 -> V_151 ;
while ( V_130 ) {
V_137 = V_130 ;
V_130 = V_130 -> V_119 ;
F_54 ( V_137 , V_135 ) ;
}
V_140 = V_139 ;
V_139 = V_139 -> V_119 ;
F_7 ( V_140 ) ;
}
V_7 -> V_138 = NULL ;
F_59 ( V_7 ) ;
for ( V_145 = V_7 -> V_152 ; V_145 ; V_145 = V_145 -> V_119 ) {
F_52 () ;
F_7 ( V_146 ) ;
V_146 = V_145 ;
}
F_7 ( V_146 ) ;
for ( V_142 = V_7 -> V_141 ; V_142 ; V_142 = V_142 -> V_119 ) {
F_52 () ;
F_7 ( V_143 ) ;
V_143 = V_142 ;
}
F_7 ( V_143 ) ;
F_40 ( V_7 -> V_25 , F_51 , NULL ) ;
F_19 ( V_7 -> V_25 ) ;
F_40 ( V_7 -> V_50 , F_53 , NULL ) ;
F_19 ( V_7 -> V_50 ) ;
if ( V_7 -> V_153 ) {
for ( V_3 = 0 ; V_3 < V_7 -> V_75 . V_17 ; V_3 ++ ) {
struct V_154 * V_116 ;
V_116 = F_60 ( V_7 -> V_153 , V_3 ) ;
if ( ! V_116 )
continue;
F_44 ( V_116 ) ;
}
F_57 ( V_7 -> V_153 ) ;
}
F_44 ( & V_7 -> V_51 ) ;
F_44 ( & V_7 -> V_52 ) ;
F_44 ( & V_7 -> V_53 ) ;
}
int F_61 ( struct V_6 * V_7 , struct V_155 * V_100 )
{
struct V_129 * V_151 , * V_130 ;
int V_9 ;
V_9 = F_62 ( V_100 ) ;
if ( V_9 ) {
F_31 ( V_156 L_8 ) ;
goto V_19;
}
V_151 = V_7 -> V_149 [ V_132 ] ;
for ( V_130 = V_151 ; V_130 ; V_130 = V_130 -> V_119 ) {
V_9 = - V_14 ;
if ( ! V_130 -> V_131 [ 0 ] . V_157 ) {
F_31 ( V_156 L_9 ,
V_130 -> V_136 . V_33 ) ;
goto V_19;
}
V_9 = F_63 ( V_100 , V_130 -> V_158 [ 0 ] , & V_130 -> V_131 [ 0 ] ) ;
if ( V_9 ) {
F_31 ( V_156 L_10 ,
V_130 -> V_136 . V_33 ) ;
goto V_19;
}
}
V_9 = 0 ;
V_19:
return V_9 ;
}
int F_64 ( struct V_6 * V_7 , unsigned int V_159 )
{
if ( ! V_159 || V_159 > V_7 -> V_66 . V_17 )
return 0 ;
return 1 ;
}
int F_65 ( struct V_6 * V_7 , unsigned int V_11 )
{
if ( ! V_11 || V_11 > V_7 -> V_16 . V_17 )
return 0 ;
return 1 ;
}
int F_66 ( struct V_6 * V_7 , unsigned int type )
{
if ( ! type || type > V_7 -> V_75 . V_17 )
return 0 ;
return 1 ;
}
int F_67 ( struct V_6 * V_7 , struct V_131 * V_130 )
{
struct V_10 * V_11 ;
struct V_78 * V_79 ;
if ( ! V_130 -> V_11 || V_130 -> V_11 > V_7 -> V_16 . V_17 )
return 0 ;
if ( ! V_130 -> V_157 || V_130 -> V_157 > V_7 -> V_80 . V_17 )
return 0 ;
if ( ! V_130 -> type || V_130 -> type > V_7 -> V_75 . V_17 )
return 0 ;
if ( V_130 -> V_11 != V_18 ) {
V_11 = V_7 -> V_71 [ V_130 -> V_11 - 1 ] ;
if ( ! V_11 || ! F_68 ( & V_11 -> V_111 , V_130 -> type - 1 ) )
return 0 ;
V_79 = V_7 -> V_82 [ V_130 -> V_157 - 1 ] ;
if ( ! V_79 )
return 0 ;
if ( ! F_68 ( & V_79 -> V_123 , V_130 -> V_11 - 1 ) )
return 0 ;
}
if ( ! F_69 ( V_7 , V_130 ) )
return 0 ;
return 1 ;
}
static int F_70 ( struct V_127 * V_160 , void * V_161 )
{
T_2 V_162 [ 2 ] ;
T_1 V_163 ;
int V_9 ;
V_9 = F_71 ( V_162 , V_161 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_19;
V_9 = - V_14 ;
V_163 = F_72 ( V_162 [ 0 ] ) ;
if ( V_163 > F_2 ( V_162 ) ) {
F_31 ( V_156 L_11 ) ;
goto V_19;
}
V_9 = F_71 ( V_162 , V_161 , sizeof( T_1 ) * V_163 ) ;
if ( V_9 ) {
F_31 ( V_156 L_12 ) ;
goto V_19;
}
V_160 -> V_86 [ 0 ] . V_87 = F_72 ( V_162 [ 0 ] ) ;
if ( V_163 > 1 )
V_160 -> V_86 [ 1 ] . V_87 = F_72 ( V_162 [ 1 ] ) ;
else
V_160 -> V_86 [ 1 ] . V_87 = V_160 -> V_86 [ 0 ] . V_87 ;
V_9 = F_73 ( & V_160 -> V_86 [ 0 ] . V_125 , V_161 ) ;
if ( V_9 ) {
F_31 ( V_156 L_13 ) ;
goto V_19;
}
if ( V_163 > 1 ) {
V_9 = F_73 ( & V_160 -> V_86 [ 1 ] . V_125 , V_161 ) ;
if ( V_9 ) {
F_31 ( V_156 L_14 ) ;
goto V_164;
}
} else {
V_9 = F_74 ( & V_160 -> V_86 [ 1 ] . V_125 , & V_160 -> V_86 [ 0 ] . V_125 ) ;
if ( V_9 ) {
F_31 ( V_156 L_15 ) ;
goto V_164;
}
}
return 0 ;
V_164:
F_44 ( & V_160 -> V_86 [ 0 ] . V_125 ) ;
V_19:
return V_9 ;
}
static int F_75 ( struct V_131 * V_130 ,
struct V_6 * V_7 ,
void * V_161 )
{
T_2 V_162 [ 3 ] ;
int V_9 ;
V_9 = F_71 ( V_162 , V_161 , sizeof V_162 ) ;
if ( V_9 ) {
F_31 ( V_156 L_16 ) ;
goto V_19;
}
V_130 -> V_157 = F_72 ( V_162 [ 0 ] ) ;
V_130 -> V_11 = F_72 ( V_162 [ 1 ] ) ;
V_130 -> type = F_72 ( V_162 [ 2 ] ) ;
if ( V_7 -> V_165 >= V_166 ) {
V_9 = F_70 ( & V_130 -> V_124 , V_161 ) ;
if ( V_9 ) {
F_31 ( V_156 L_17 ) ;
goto V_19;
}
}
V_9 = - V_14 ;
if ( ! F_67 ( V_7 , V_130 ) ) {
F_31 ( V_156 L_18 ) ;
F_55 ( V_130 ) ;
goto V_19;
}
V_9 = 0 ;
V_19:
return V_9 ;
}
static int F_76 ( char * * V_167 , T_3 V_168 , void * V_161 , T_1 V_169 )
{
int V_9 ;
char * V_170 ;
if ( ( V_169 == 0 ) || ( V_169 == ( T_1 ) - 1 ) )
return - V_14 ;
V_170 = F_77 ( V_169 + 1 , V_168 ) ;
if ( ! V_170 )
return - V_13 ;
* V_167 = V_170 ;
V_9 = F_71 ( V_170 , V_161 , V_169 ) ;
if ( V_9 )
return V_9 ;
V_170 [ V_169 ] = '\0' ;
return 0 ;
}
static int F_78 ( struct V_6 * V_7 , struct V_22 * V_23 , void * V_161 )
{
char * V_8 = NULL ;
struct V_171 * V_172 ;
int V_9 ;
T_2 V_162 [ 2 ] ;
T_1 V_169 ;
V_172 = F_4 ( sizeof( * V_172 ) , V_12 ) ;
if ( ! V_172 )
return - V_13 ;
V_9 = F_71 ( V_162 , V_161 , sizeof V_162 ) ;
if ( V_9 )
goto V_173;
V_169 = F_72 ( V_162 [ 0 ] ) ;
V_172 -> V_15 = F_72 ( V_162 [ 1 ] ) ;
V_9 = F_76 ( & V_8 , V_12 , V_161 , V_169 ) ;
if ( V_9 )
goto V_173;
V_9 = F_6 ( V_23 , V_8 , V_172 ) ;
if ( V_9 )
goto V_173;
return 0 ;
V_173:
F_41 ( V_8 , V_172 , NULL ) ;
return V_9 ;
}
static int F_79 ( struct V_6 * V_7 , struct V_22 * V_23 , void * V_161 )
{
char * V_8 = NULL ;
struct V_56 * V_57 ;
T_2 V_162 [ 4 ] ;
T_1 V_169 , V_97 ;
int V_3 , V_9 ;
V_57 = F_4 ( sizeof( * V_57 ) , V_12 ) ;
if ( ! V_57 )
return - V_13 ;
V_9 = F_71 ( V_162 , V_161 , sizeof V_162 ) ;
if ( V_9 )
goto V_173;
V_169 = F_72 ( V_162 [ 0 ] ) ;
V_57 -> V_15 = F_72 ( V_162 [ 1 ] ) ;
V_9 = F_14 ( & V_57 -> V_106 , V_174 ) ;
if ( V_9 )
goto V_173;
V_57 -> V_106 . V_17 = F_72 ( V_162 [ 2 ] ) ;
V_97 = F_72 ( V_162 [ 3 ] ) ;
V_9 = F_76 ( & V_8 , V_12 , V_161 , V_169 ) ;
if ( V_9 )
goto V_173;
for ( V_3 = 0 ; V_3 < V_97 ; V_3 ++ ) {
V_9 = F_78 ( V_7 , V_57 -> V_106 . V_21 , V_161 ) ;
if ( V_9 )
goto V_173;
}
V_9 = F_6 ( V_23 , V_8 , V_57 ) ;
if ( V_9 )
goto V_173;
return 0 ;
V_173:
F_42 ( V_8 , V_57 , NULL ) ;
return V_9 ;
}
static void F_80 ( struct V_175 * V_176 )
{
F_18 ( & V_176 -> V_111 ) ;
F_18 ( & V_176 -> V_112 ) ;
}
static int F_81 ( struct V_175 * V_176 , void * V_161 )
{
T_2 V_162 [ 1 ] ;
int V_9 ;
if ( F_73 ( & V_176 -> V_111 , V_161 ) )
return - V_14 ;
if ( F_73 ( & V_176 -> V_112 , V_161 ) )
return - V_14 ;
V_9 = F_71 ( V_162 , V_161 , sizeof( T_1 ) ) ;
if ( V_9 < 0 )
return - V_14 ;
V_176 -> V_168 = F_72 ( V_162 [ 0 ] ) ;
return 0 ;
}
static int F_82 ( struct V_6 * V_7 ,
struct V_113 * * V_177 ,
int V_178 , int V_179 , void * V_161 )
{
struct V_113 * V_130 , * V_180 ;
struct V_107 * V_116 , * V_181 ;
T_2 V_162 [ 3 ] ;
T_1 V_182 ;
int V_9 , V_3 , V_183 , V_184 ;
V_180 = NULL ;
for ( V_3 = 0 ; V_3 < V_178 ; V_3 ++ ) {
V_130 = F_4 ( sizeof( * V_130 ) , V_12 ) ;
if ( ! V_130 )
return - V_13 ;
if ( V_180 )
V_180 -> V_119 = V_130 ;
else
* V_177 = V_130 ;
V_9 = F_71 ( V_162 , V_161 , ( sizeof( T_1 ) * 2 ) ) ;
if ( V_9 )
return V_9 ;
V_130 -> V_106 = F_72 ( V_162 [ 0 ] ) ;
V_182 = F_72 ( V_162 [ 1 ] ) ;
V_181 = NULL ;
V_184 = - 1 ;
for ( V_183 = 0 ; V_183 < V_182 ; V_183 ++ ) {
V_116 = F_4 ( sizeof( * V_116 ) , V_12 ) ;
if ( ! V_116 )
return - V_13 ;
if ( V_181 )
V_181 -> V_119 = V_116 ;
else
V_130 -> V_108 = V_116 ;
V_9 = F_71 ( V_162 , V_161 , ( sizeof( T_1 ) * 3 ) ) ;
if ( V_9 )
return V_9 ;
V_116 -> V_185 = F_72 ( V_162 [ 0 ] ) ;
V_116 -> V_186 = F_72 ( V_162 [ 1 ] ) ;
V_116 -> V_187 = F_72 ( V_162 [ 2 ] ) ;
switch ( V_116 -> V_185 ) {
case V_188 :
if ( V_184 < 0 )
return - V_14 ;
break;
case V_189 :
case V_190 :
if ( V_184 < 1 )
return - V_14 ;
V_184 -- ;
break;
case V_191 :
if ( V_184 == ( V_192 - 1 ) )
return - V_14 ;
V_184 ++ ;
break;
case V_193 :
if ( ! V_179 && ( V_116 -> V_186 & V_194 ) )
return - V_14 ;
if ( V_184 == ( V_192 - 1 ) )
return - V_14 ;
V_184 ++ ;
V_9 = F_73 ( & V_116 -> V_109 , V_161 ) ;
if ( V_9 )
return V_9 ;
if ( V_7 -> V_165 >=
V_195 ) {
V_116 -> V_110 = F_4 ( sizeof
( * V_116 -> V_110 ) ,
V_12 ) ;
if ( ! V_116 -> V_110 )
return - V_13 ;
F_80 ( V_116 -> V_110 ) ;
V_9 = F_81 ( V_116 -> V_110 , V_161 ) ;
if ( V_9 )
return V_9 ;
}
break;
default:
return - V_14 ;
}
V_181 = V_116 ;
}
if ( V_184 != 0 )
return - V_14 ;
V_180 = V_130 ;
}
return 0 ;
}
static int F_83 ( struct V_6 * V_7 , struct V_22 * V_23 , void * V_161 )
{
char * V_8 = NULL ;
struct V_64 * V_65 ;
T_2 V_162 [ 6 ] ;
T_1 V_169 , V_196 , V_178 , V_97 ;
int V_3 , V_9 ;
V_65 = F_4 ( sizeof( * V_65 ) , V_12 ) ;
if ( ! V_65 )
return - V_13 ;
V_9 = F_71 ( V_162 , V_161 , sizeof( T_1 ) * 6 ) ;
if ( V_9 )
goto V_173;
V_169 = F_72 ( V_162 [ 0 ] ) ;
V_196 = F_72 ( V_162 [ 1 ] ) ;
V_65 -> V_15 = F_72 ( V_162 [ 2 ] ) ;
V_9 = F_14 ( & V_65 -> V_106 , V_174 ) ;
if ( V_9 )
goto V_173;
V_65 -> V_106 . V_17 = F_72 ( V_162 [ 3 ] ) ;
V_97 = F_72 ( V_162 [ 4 ] ) ;
V_178 = F_72 ( V_162 [ 5 ] ) ;
V_9 = F_76 ( & V_8 , V_12 , V_161 , V_169 ) ;
if ( V_9 )
goto V_173;
if ( V_196 ) {
V_9 = F_76 ( & V_65 -> V_121 , V_12 , V_161 , V_196 ) ;
if ( V_9 )
goto V_173;
V_9 = - V_14 ;
V_65 -> V_57 = F_84 ( V_7 -> V_60 . V_21 , V_65 -> V_121 ) ;
if ( ! V_65 -> V_57 ) {
F_31 ( V_156 L_19 , V_65 -> V_121 ) ;
goto V_173;
}
}
for ( V_3 = 0 ; V_3 < V_97 ; V_3 ++ ) {
V_9 = F_78 ( V_7 , V_65 -> V_106 . V_21 , V_161 ) ;
if ( V_9 )
goto V_173;
}
V_9 = F_82 ( V_7 , & V_65 -> V_118 , V_178 , 0 , V_161 ) ;
if ( V_9 )
goto V_173;
if ( V_7 -> V_165 >= V_197 ) {
V_9 = F_71 ( V_162 , V_161 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_173;
V_178 = F_72 ( V_162 [ 0 ] ) ;
V_9 = F_82 ( V_7 , & V_65 -> V_120 ,
V_178 , 1 , V_161 ) ;
if ( V_9 )
goto V_173;
}
if ( V_7 -> V_165 >= V_198 ) {
V_9 = F_71 ( V_162 , V_161 , sizeof( T_1 ) * 3 ) ;
if ( V_9 )
goto V_173;
V_65 -> V_199 = F_72 ( V_162 [ 0 ] ) ;
V_65 -> V_200 = F_72 ( V_162 [ 1 ] ) ;
V_65 -> V_201 = F_72 ( V_162 [ 2 ] ) ;
}
if ( V_7 -> V_165 >= V_202 ) {
V_9 = F_71 ( V_162 , V_161 , sizeof( T_1 ) * 1 ) ;
if ( V_9 )
goto V_173;
V_65 -> V_203 = F_72 ( V_162 [ 0 ] ) ;
}
V_9 = F_6 ( V_23 , V_8 , V_65 ) ;
if ( V_9 )
goto V_173;
return 0 ;
V_173:
F_45 ( V_8 , V_65 , NULL ) ;
return V_9 ;
}
static int F_85 ( struct V_6 * V_7 , struct V_22 * V_23 , void * V_161 )
{
char * V_8 = NULL ;
struct V_10 * V_11 ;
int V_9 , V_204 = 2 ;
T_2 V_162 [ 3 ] ;
T_1 V_169 ;
V_11 = F_4 ( sizeof( * V_11 ) , V_12 ) ;
if ( ! V_11 )
return - V_13 ;
if ( V_7 -> V_165 >= V_205 )
V_204 = 3 ;
V_9 = F_71 ( V_162 , V_161 , sizeof( V_162 [ 0 ] ) * V_204 ) ;
if ( V_9 )
goto V_173;
V_169 = F_72 ( V_162 [ 0 ] ) ;
V_11 -> V_15 = F_72 ( V_162 [ 1 ] ) ;
if ( V_7 -> V_165 >= V_205 )
V_11 -> V_69 = F_72 ( V_162 [ 2 ] ) ;
V_9 = F_76 ( & V_8 , V_12 , V_161 , V_169 ) ;
if ( V_9 )
goto V_173;
V_9 = F_73 ( & V_11 -> V_122 , V_161 ) ;
if ( V_9 )
goto V_173;
V_9 = F_73 ( & V_11 -> V_111 , V_161 ) ;
if ( V_9 )
goto V_173;
if ( strcmp ( V_8 , V_20 ) == 0 ) {
V_9 = - V_14 ;
if ( V_11 -> V_15 != V_18 ) {
F_31 ( V_156 L_20 ,
V_20 , V_11 -> V_15 ) ;
goto V_173;
}
V_9 = 0 ;
goto V_173;
}
V_9 = F_6 ( V_23 , V_8 , V_11 ) ;
if ( V_9 )
goto V_173;
return 0 ;
V_173:
F_46 ( V_8 , V_11 , NULL ) ;
return V_9 ;
}
static int F_86 ( struct V_6 * V_7 , struct V_22 * V_23 , void * V_161 )
{
char * V_8 = NULL ;
struct V_72 * V_73 ;
int V_9 , V_204 = 3 ;
T_2 V_162 [ 4 ] ;
T_1 V_169 ;
V_73 = F_4 ( sizeof( * V_73 ) , V_12 ) ;
if ( ! V_73 )
return - V_13 ;
if ( V_7 -> V_165 >= V_205 )
V_204 = 4 ;
V_9 = F_71 ( V_162 , V_161 , sizeof( V_162 [ 0 ] ) * V_204 ) ;
if ( V_9 )
goto V_173;
V_169 = F_72 ( V_162 [ 0 ] ) ;
V_73 -> V_15 = F_72 ( V_162 [ 1 ] ) ;
if ( V_7 -> V_165 >= V_205 ) {
T_1 V_206 = F_72 ( V_162 [ 2 ] ) ;
if ( V_206 & V_207 )
V_73 -> V_74 = 1 ;
if ( V_206 & V_208 )
V_73 -> V_209 = 1 ;
V_73 -> V_69 = F_72 ( V_162 [ 3 ] ) ;
} else {
V_73 -> V_74 = F_72 ( V_162 [ 2 ] ) ;
}
V_9 = F_76 ( & V_8 , V_12 , V_161 , V_169 ) ;
if ( V_9 )
goto V_173;
V_9 = F_6 ( V_23 , V_8 , V_73 ) ;
if ( V_9 )
goto V_173;
return 0 ;
V_173:
F_47 ( V_8 , V_73 , NULL ) ;
return V_9 ;
}
static int F_87 ( struct V_210 * V_211 , void * V_161 )
{
T_2 V_162 [ 1 ] ;
int V_9 ;
memset ( V_211 , 0 , sizeof( * V_211 ) ) ;
V_9 = F_71 ( V_162 , V_161 , sizeof V_162 ) ;
if ( V_9 ) {
F_31 ( V_156 L_21 ) ;
return V_9 ;
}
V_211 -> V_87 = F_72 ( V_162 [ 0 ] ) ;
V_9 = F_73 ( & V_211 -> V_125 , V_161 ) ;
if ( V_9 ) {
F_31 ( V_156 L_22 ) ;
return V_9 ;
}
return 0 ;
}
static int F_88 ( struct V_6 * V_7 , struct V_22 * V_23 , void * V_161 )
{
char * V_8 = NULL ;
struct V_78 * V_79 ;
int V_9 , V_204 = 2 ;
T_2 V_162 [ 3 ] ;
T_1 V_169 ;
V_79 = F_4 ( sizeof( * V_79 ) , V_12 ) ;
if ( ! V_79 )
return - V_13 ;
if ( V_7 -> V_165 >= V_205 )
V_204 = 3 ;
V_9 = F_71 ( V_162 , V_161 , sizeof( V_162 [ 0 ] ) * V_204 ) ;
if ( V_9 )
goto V_173;
V_169 = F_72 ( V_162 [ 0 ] ) ;
V_79 -> V_15 = F_72 ( V_162 [ 1 ] ) ;
if ( V_7 -> V_165 >= V_205 )
V_79 -> V_69 = F_72 ( V_162 [ 2 ] ) ;
V_9 = F_76 ( & V_8 , V_12 , V_161 , V_169 ) ;
if ( V_9 )
goto V_173;
V_9 = F_73 ( & V_79 -> V_123 , V_161 ) ;
if ( V_9 )
goto V_173;
if ( V_7 -> V_165 >= V_166 ) {
V_9 = F_70 ( & V_79 -> V_124 , V_161 ) ;
if ( V_9 )
goto V_173;
V_9 = F_87 ( & V_79 -> V_126 , V_161 ) ;
if ( V_9 )
goto V_173;
}
V_9 = F_6 ( V_23 , V_8 , V_79 ) ;
if ( V_9 )
goto V_173;
return 0 ;
V_173:
F_48 ( V_8 , V_79 , NULL ) ;
return V_9 ;
}
static int F_89 ( struct V_6 * V_7 , struct V_22 * V_23 , void * V_161 )
{
char * V_8 = NULL ;
struct V_83 * V_84 ;
int V_9 ;
T_2 V_162 [ 2 ] ;
T_1 V_169 ;
V_84 = F_4 ( sizeof( * V_84 ) , V_212 ) ;
if ( ! V_84 )
return - V_13 ;
V_9 = F_71 ( V_162 , V_161 , sizeof V_162 ) ;
if ( V_9 )
goto V_173;
V_169 = F_72 ( V_162 [ 0 ] ) ;
V_84 -> V_85 = F_72 ( V_162 [ 1 ] ) ;
V_9 = F_76 ( & V_8 , V_212 , V_161 , V_169 ) ;
if ( V_9 )
goto V_173;
V_9 = - V_13 ;
V_84 -> V_86 = F_77 ( sizeof( * V_84 -> V_86 ) , V_212 ) ;
if ( ! V_84 -> V_86 )
goto V_173;
V_9 = F_87 ( V_84 -> V_86 , V_161 ) ;
if ( V_9 )
goto V_173;
V_9 = F_6 ( V_23 , V_8 , V_84 ) ;
if ( V_9 )
goto V_173;
return 0 ;
V_173:
F_49 ( V_8 , V_84 , NULL ) ;
return V_9 ;
}
static int F_90 ( struct V_6 * V_7 , struct V_22 * V_23 , void * V_161 )
{
char * V_8 = NULL ;
struct V_90 * V_91 ;
int V_9 ;
T_2 V_162 [ 3 ] ;
T_1 V_169 ;
V_91 = F_4 ( sizeof( * V_91 ) , V_212 ) ;
if ( ! V_91 )
return - V_13 ;
V_9 = F_71 ( V_162 , V_161 , sizeof V_162 ) ;
if ( V_9 )
goto V_173;
V_169 = F_72 ( V_162 [ 0 ] ) ;
V_91 -> V_15 = F_72 ( V_162 [ 1 ] ) ;
V_91 -> V_85 = F_72 ( V_162 [ 2 ] ) ;
V_9 = F_76 ( & V_8 , V_212 , V_161 , V_169 ) ;
if ( V_9 )
goto V_173;
V_9 = F_6 ( V_23 , V_8 , V_91 ) ;
if ( V_9 )
goto V_173;
return 0 ;
V_173:
F_50 ( V_8 , V_91 , NULL ) ;
return V_9 ;
}
static int F_91 ( void * V_8 , void * V_54 , void * V_55 )
{
struct V_78 * V_213 , * V_157 ;
struct V_6 * V_7 = V_55 ;
int V_184 = 0 ;
V_213 = V_157 = V_54 ;
while ( V_213 -> V_69 ) {
struct V_214 * V_215 ;
unsigned long V_216 ;
if ( ++ V_184 == V_217 ) {
F_31 ( V_156 L_23
L_24 ,
( char * ) V_8 ) ;
return - V_14 ;
}
V_213 = V_7 -> V_82 [ V_213 -> V_69 - 1 ] ;
F_92 (&user->roles, node, bit) {
if ( F_68 ( & V_213 -> V_123 , V_216 ) )
continue;
F_31 ( V_156
L_25
L_26 ,
F_93 ( V_7 , V_81 , V_157 -> V_15 - 1 ) ,
F_93 ( V_7 , V_70 , V_216 ) ,
F_93 ( V_7 , V_81 , V_213 -> V_15 - 1 ) ) ;
return - V_14 ;
}
}
return 0 ;
}
static int F_94 ( void * V_8 , void * V_54 , void * V_55 )
{
struct V_10 * V_213 , * V_11 ;
struct V_6 * V_7 = V_55 ;
int V_184 = 0 ;
V_213 = V_11 = V_54 ;
while ( V_213 -> V_69 ) {
struct V_214 * V_215 ;
unsigned long V_216 ;
if ( ++ V_184 == V_217 ) {
F_31 ( V_156 L_27
L_28 ,
( char * ) V_8 ) ;
return - V_14 ;
}
V_213 = V_7 -> V_71 [ V_213 -> V_69 - 1 ] ;
F_92 (&role->types, node, bit) {
if ( F_68 ( & V_213 -> V_111 , V_216 ) )
continue;
F_31 ( V_156
L_25
L_29 ,
F_93 ( V_7 , V_70 , V_11 -> V_15 - 1 ) ,
F_93 ( V_7 , V_76 , V_216 ) ,
F_93 ( V_7 , V_70 , V_213 -> V_15 - 1 ) ) ;
return - V_14 ;
}
}
return 0 ;
}
static int F_95 ( void * V_8 , void * V_54 , void * V_55 )
{
struct V_72 * V_213 ;
struct V_6 * V_7 = V_55 ;
int V_184 = 0 ;
V_213 = V_54 ;
while ( V_213 -> V_69 ) {
if ( ++ V_184 == V_217 ) {
F_31 ( V_156 L_30
L_31 ,
( char * ) V_8 ) ;
return - V_14 ;
}
V_213 = F_96 ( V_7 -> V_77 ,
V_213 -> V_69 - 1 ) ;
F_97 ( ! V_213 ) ;
if ( V_213 -> V_209 ) {
F_31 ( V_156 L_30
L_32 ,
( char * ) V_8 ,
F_93 ( V_7 , V_76 , V_213 -> V_15 - 1 ) ) ;
return - V_14 ;
}
}
return 0 ;
}
static int F_98 ( struct V_6 * V_7 )
{
int V_9 ;
if ( V_7 -> V_165 < V_205 )
return 0 ;
V_9 = F_40 ( V_7 -> V_80 . V_21 ,
F_91 , V_7 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_40 ( V_7 -> V_16 . V_21 ,
F_94 , V_7 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_40 ( V_7 -> V_75 . V_21 ,
F_95 , V_7 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
T_4 F_99 ( struct V_6 * V_7 , const char * V_33 )
{
struct V_64 * V_65 ;
V_65 = F_84 ( V_7 -> V_66 . V_21 , V_33 ) ;
if ( ! V_65 )
return 0 ;
return V_65 -> V_15 ;
}
T_1 F_100 ( struct V_6 * V_7 , T_4 V_32 , const char * V_33 )
{
struct V_64 * V_65 ;
struct V_171 * V_172 = NULL ;
struct V_56 * V_57 ;
if ( ! V_32 || V_32 > V_7 -> V_66 . V_17 )
return 0 ;
V_65 = V_7 -> V_68 [ V_32 - 1 ] ;
V_57 = V_65 -> V_57 ;
if ( V_57 )
V_172 = F_84 ( V_57 -> V_106 . V_21 ,
V_33 ) ;
if ( ! V_172 )
V_172 = F_84 ( V_65 -> V_106 . V_21 ,
V_33 ) ;
if ( ! V_172 )
return 0 ;
return 1U << ( V_172 -> V_15 - 1 ) ;
}
static int F_101 ( struct V_6 * V_7 , void * V_161 )
{
struct V_40 * V_128 = NULL ;
struct V_127 * V_160 = NULL ;
int V_3 , V_9 ;
T_2 V_162 [ 2 ] ;
T_1 V_97 ;
if ( V_7 -> V_165 < V_166 )
return 0 ;
V_9 = F_71 ( V_162 , V_161 , sizeof( T_1 ) ) ;
if ( V_9 )
return V_9 ;
V_97 = F_72 ( V_162 [ 0 ] ) ;
for ( V_3 = 0 ; V_3 < V_97 ; V_3 ++ ) {
V_9 = - V_13 ;
V_128 = F_4 ( sizeof( * V_128 ) , V_12 ) ;
if ( ! V_128 )
goto V_19;
V_9 = F_71 ( V_162 , V_161 , ( sizeof( T_1 ) * 2 ) ) ;
if ( V_9 )
goto V_19;
V_128 -> V_41 = F_72 ( V_162 [ 0 ] ) ;
V_128 -> V_42 = F_72 ( V_162 [ 1 ] ) ;
if ( V_7 -> V_165 >= V_218 ) {
V_9 = F_71 ( V_162 , V_161 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_19;
V_128 -> V_43 = F_72 ( V_162 [ 0 ] ) ;
} else
V_128 -> V_43 = V_7 -> V_219 ;
V_9 = - V_14 ;
if ( ! F_66 ( V_7 , V_128 -> V_41 ) ||
! F_66 ( V_7 , V_128 -> V_42 ) ||
! F_64 ( V_7 , V_128 -> V_43 ) )
goto V_19;
V_9 = - V_13 ;
V_160 = F_4 ( sizeof( * V_160 ) , V_12 ) ;
if ( ! V_160 )
goto V_19;
V_9 = F_70 ( V_160 , V_161 ) ;
if ( V_9 )
goto V_19;
V_9 = - V_14 ;
if ( ! F_102 ( V_7 , V_160 ) ) {
F_31 ( V_220 L_33 ) ;
goto V_19;
}
V_9 = F_6 ( V_7 -> V_50 , V_128 , V_160 ) ;
if ( V_9 )
goto V_19;
V_128 = NULL ;
V_160 = NULL ;
}
F_29 ( V_7 -> V_50 , L_34 ) ;
V_9 = 0 ;
V_19:
F_7 ( V_128 ) ;
F_7 ( V_160 ) ;
return V_9 ;
}
static int F_103 ( struct V_6 * V_7 , void * V_161 )
{
struct V_25 * V_26 ;
struct V_221 * V_222 ;
char * V_33 ;
T_1 V_97 , V_169 ;
T_2 V_162 [ 4 ] ;
int V_9 , V_3 ;
if ( V_7 -> V_165 < V_223 )
return 0 ;
V_9 = F_71 ( V_162 , V_161 , sizeof( T_1 ) ) ;
if ( V_9 )
return V_9 ;
V_97 = F_72 ( V_162 [ 0 ] ) ;
for ( V_3 = 0 ; V_3 < V_97 ; V_3 ++ ) {
V_222 = NULL ;
V_33 = NULL ;
V_9 = - V_13 ;
V_26 = F_4 ( sizeof( * V_26 ) , V_12 ) ;
if ( ! V_26 )
goto V_19;
V_9 = - V_13 ;
V_222 = F_77 ( sizeof( * V_222 ) , V_12 ) ;
if ( ! V_222 )
goto V_19;
V_9 = F_71 ( V_162 , V_161 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_19;
V_169 = F_72 ( V_162 [ 0 ] ) ;
V_9 = F_76 ( & V_33 , V_12 , V_161 , V_169 ) ;
if ( V_9 )
goto V_19;
V_26 -> V_33 = V_33 ;
V_9 = F_71 ( V_162 , V_161 , sizeof( T_1 ) * 4 ) ;
if ( V_9 )
goto V_19;
V_26 -> V_30 = F_72 ( V_162 [ 0 ] ) ;
V_26 -> V_31 = F_72 ( V_162 [ 1 ] ) ;
V_26 -> V_32 = F_72 ( V_162 [ 2 ] ) ;
V_222 -> V_222 = F_72 ( V_162 [ 3 ] ) ;
V_9 = F_104 ( & V_7 -> V_51 , V_26 -> V_31 , 1 ) ;
if ( V_9 )
goto V_19;
V_9 = F_6 ( V_7 -> V_25 , V_26 , V_222 ) ;
if ( V_9 ) {
if ( V_9 != - V_224 )
goto V_19;
F_7 ( V_26 ) ;
F_7 ( V_33 ) ;
F_7 ( V_222 ) ;
}
}
F_29 ( V_7 -> V_25 , L_35 ) ;
return 0 ;
V_19:
F_7 ( V_26 ) ;
F_7 ( V_33 ) ;
F_7 ( V_222 ) ;
return V_9 ;
}
static int F_105 ( struct V_6 * V_7 , void * V_161 )
{
int V_3 , V_183 , V_9 ;
T_1 V_97 , V_225 , V_169 , V_196 ;
T_2 V_162 [ 1 ] ;
struct V_129 * V_226 , * V_130 ;
struct V_129 * V_227 = NULL ;
struct V_138 * V_228 , * V_138 ;
struct V_138 * V_229 = NULL ;
V_9 = F_71 ( V_162 , V_161 , sizeof( T_1 ) ) ;
if ( V_9 )
return V_9 ;
V_97 = F_72 ( V_162 [ 0 ] ) ;
for ( V_3 = 0 ; V_3 < V_97 ; V_3 ++ ) {
V_9 = F_71 ( V_162 , V_161 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_19;
V_169 = F_72 ( V_162 [ 0 ] ) ;
V_9 = - V_13 ;
V_229 = F_4 ( sizeof( * V_229 ) , V_12 ) ;
if ( ! V_229 )
goto V_19;
V_9 = F_76 ( & V_229 -> V_150 , V_12 , V_161 , V_169 ) ;
if ( V_9 )
goto V_19;
for ( V_228 = NULL , V_138 = V_7 -> V_138 ; V_138 ;
V_228 = V_138 , V_138 = V_138 -> V_119 ) {
V_9 = - V_14 ;
if ( strcmp ( V_229 -> V_150 , V_138 -> V_150 ) == 0 ) {
F_31 ( V_156 L_36 ,
V_229 -> V_150 ) ;
goto V_19;
}
if ( strcmp ( V_229 -> V_150 , V_138 -> V_150 ) < 0 )
break;
}
V_229 -> V_119 = V_138 ;
if ( V_228 )
V_228 -> V_119 = V_229 ;
else
V_7 -> V_138 = V_229 ;
V_138 = V_229 ;
V_229 = NULL ;
V_9 = F_71 ( V_162 , V_161 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_19;
V_225 = F_72 ( V_162 [ 0 ] ) ;
for ( V_183 = 0 ; V_183 < V_225 ; V_183 ++ ) {
V_9 = F_71 ( V_162 , V_161 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_19;
V_169 = F_72 ( V_162 [ 0 ] ) ;
V_9 = - V_13 ;
V_227 = F_4 ( sizeof( * V_227 ) , V_12 ) ;
if ( ! V_227 )
goto V_19;
V_9 = F_76 ( & V_227 -> V_136 . V_33 , V_12 , V_161 , V_169 ) ;
if ( V_9 )
goto V_19;
V_9 = F_71 ( V_162 , V_161 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_19;
V_227 -> V_39 . V_230 = F_72 ( V_162 [ 0 ] ) ;
V_9 = F_75 ( & V_227 -> V_131 [ 0 ] , V_7 , V_161 ) ;
if ( V_9 )
goto V_19;
for ( V_226 = NULL , V_130 = V_138 -> V_151 ; V_130 ;
V_226 = V_130 , V_130 = V_130 -> V_119 ) {
V_9 = - V_14 ;
if ( ! strcmp ( V_227 -> V_136 . V_33 , V_130 -> V_136 . V_33 ) &&
( ! V_130 -> V_39 . V_230 || ! V_227 -> V_39 . V_230 ||
V_227 -> V_39 . V_230 == V_130 -> V_39 . V_230 ) ) {
F_31 ( V_156 L_37 ,
V_138 -> V_150 , V_130 -> V_136 . V_33 ) ;
goto V_19;
}
V_169 = strlen ( V_227 -> V_136 . V_33 ) ;
V_196 = strlen ( V_130 -> V_136 . V_33 ) ;
if ( V_169 > V_196 )
break;
}
V_227 -> V_119 = V_130 ;
if ( V_226 )
V_226 -> V_119 = V_227 ;
else
V_138 -> V_151 = V_227 ;
V_227 = NULL ;
}
}
V_9 = 0 ;
V_19:
if ( V_229 ) {
F_7 ( V_229 -> V_150 ) ;
F_7 ( V_229 ) ;
}
F_54 ( V_227 , V_135 ) ;
return V_9 ;
}
static int F_106 ( struct V_6 * V_7 , struct V_1 * V_4 ,
void * V_161 )
{
int V_3 , V_183 , V_9 ;
T_1 V_97 , V_169 ;
T_2 V_162 [ 3 ] ;
struct V_129 * V_226 , * V_130 ;
T_1 V_231 [ 8 ] ;
for ( V_3 = 0 ; V_3 < V_4 -> V_232 ; V_3 ++ ) {
V_9 = F_71 ( V_162 , V_161 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_19;
V_97 = F_72 ( V_162 [ 0 ] ) ;
V_226 = NULL ;
for ( V_183 = 0 ; V_183 < V_97 ; V_183 ++ ) {
V_9 = - V_13 ;
V_130 = F_4 ( sizeof( * V_130 ) , V_12 ) ;
if ( ! V_130 )
goto V_19;
if ( V_226 )
V_226 -> V_119 = V_130 ;
else
V_7 -> V_149 [ V_3 ] = V_130 ;
V_226 = V_130 ;
switch ( V_3 ) {
case V_132 :
V_9 = F_71 ( V_162 , V_161 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_19;
V_130 -> V_158 [ 0 ] = F_72 ( V_162 [ 0 ] ) ;
V_9 = F_75 ( & V_130 -> V_131 [ 0 ] , V_7 , V_161 ) ;
if ( V_9 )
goto V_19;
break;
case V_133 :
case V_134 :
V_9 = F_71 ( V_162 , V_161 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_19;
V_169 = F_72 ( V_162 [ 0 ] ) ;
V_9 = F_76 ( & V_130 -> V_136 . V_33 , V_12 , V_161 , V_169 ) ;
if ( V_9 )
goto V_19;
V_9 = F_75 ( & V_130 -> V_131 [ 0 ] , V_7 , V_161 ) ;
if ( V_9 )
goto V_19;
V_9 = F_75 ( & V_130 -> V_131 [ 1 ] , V_7 , V_161 ) ;
if ( V_9 )
goto V_19;
break;
case V_233 :
V_9 = F_71 ( V_162 , V_161 , sizeof( T_1 ) * 3 ) ;
if ( V_9 )
goto V_19;
V_130 -> V_136 . V_234 . V_235 = F_72 ( V_162 [ 0 ] ) ;
V_130 -> V_136 . V_234 . V_236 = F_72 ( V_162 [ 1 ] ) ;
V_130 -> V_136 . V_234 . V_237 = F_72 ( V_162 [ 2 ] ) ;
V_9 = F_75 ( & V_130 -> V_131 [ 0 ] , V_7 , V_161 ) ;
if ( V_9 )
goto V_19;
break;
case V_238 :
V_9 = F_71 ( V_231 , V_161 , sizeof( T_1 ) * 2 ) ;
if ( V_9 )
goto V_19;
V_130 -> V_136 . V_215 . V_239 = V_231 [ 0 ] ;
V_130 -> V_136 . V_215 . V_240 = V_231 [ 1 ] ;
V_9 = F_75 ( & V_130 -> V_131 [ 0 ] , V_7 , V_161 ) ;
if ( V_9 )
goto V_19;
break;
case V_135 :
V_9 = F_71 ( V_162 , V_161 , sizeof( T_1 ) * 2 ) ;
if ( V_9 )
goto V_19;
V_9 = - V_14 ;
V_130 -> V_39 . V_241 = F_72 ( V_162 [ 0 ] ) ;
if ( V_130 -> V_39 . V_241 == V_242 )
goto V_19;
if ( V_130 -> V_39 . V_241 > V_243 )
goto V_19;
V_169 = F_72 ( V_162 [ 1 ] ) ;
V_9 = F_76 ( & V_130 -> V_136 . V_33 , V_12 , V_161 , V_169 ) ;
if ( V_9 )
goto V_19;
V_9 = F_75 ( & V_130 -> V_131 [ 0 ] , V_7 , V_161 ) ;
if ( V_9 )
goto V_19;
break;
case V_244 : {
int V_24 ;
V_9 = F_71 ( V_231 , V_161 , sizeof( T_1 ) * 8 ) ;
if ( V_9 )
goto V_19;
for ( V_24 = 0 ; V_24 < 4 ; V_24 ++ )
V_130 -> V_136 . V_245 . V_239 [ V_24 ] = V_231 [ V_24 ] ;
for ( V_24 = 0 ; V_24 < 4 ; V_24 ++ )
V_130 -> V_136 . V_245 . V_240 [ V_24 ] = V_231 [ V_24 + 4 ] ;
V_9 = F_75 ( & V_130 -> V_131 [ 0 ] , V_7 , V_161 ) ;
if ( V_9 )
goto V_19;
break;
}
case V_246 :
V_9 = F_71 ( V_231 , V_161 , sizeof( T_1 ) * 4 ) ;
if ( V_9 )
goto V_19;
V_130 -> V_136 . V_247 . V_248 = F_107 ( * ( ( V_249 * ) V_231 ) ) ;
if ( V_231 [ 2 ] > 0xffff ||
V_231 [ 3 ] > 0xffff ) {
V_9 = - V_14 ;
goto V_19;
}
V_130 -> V_136 . V_247 . V_250 = F_72 ( V_231 [ 2 ] ) ;
V_130 -> V_136 . V_247 . V_251 = F_72 ( V_231 [ 3 ] ) ;
V_9 = F_75 ( & V_130 -> V_131 [ 0 ] ,
V_7 ,
V_161 ) ;
if ( V_9 )
goto V_19;
break;
case V_252 :
V_9 = F_71 ( V_162 , V_161 , sizeof( T_1 ) * 2 ) ;
if ( V_9 )
goto V_19;
V_169 = F_72 ( V_162 [ 0 ] ) ;
V_9 = F_76 ( & V_130 -> V_136 . V_253 . V_254 , V_12 , V_161 , V_169 ) ;
if ( V_9 )
goto V_19;
if ( V_162 [ 1 ] > 0xff || V_162 [ 1 ] == 0 ) {
V_9 = - V_14 ;
goto V_19;
}
V_130 -> V_136 . V_253 . V_234 = F_72 ( V_162 [ 1 ] ) ;
V_9 = F_75 ( & V_130 -> V_131 [ 0 ] ,
V_7 ,
V_161 ) ;
if ( V_9 )
goto V_19;
break;
}
}
}
V_9 = 0 ;
V_19:
return V_9 ;
}
int F_108 ( struct V_6 * V_7 , void * V_161 )
{
struct V_141 * V_142 , * V_143 ;
struct V_144 * V_145 , * V_146 ;
int V_3 , V_183 , V_9 ;
T_2 V_162 [ 4 ] ;
T_1 V_169 , V_17 , V_97 ;
char * V_255 ;
struct V_1 * V_4 ;
V_9 = F_13 ( V_7 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_71 ( V_162 , V_161 , sizeof( T_1 ) * 2 ) ;
if ( V_9 )
goto V_173;
V_9 = - V_14 ;
if ( F_72 ( V_162 [ 0 ] ) != V_256 ) {
F_31 ( V_156 L_38
L_39 ,
F_72 ( V_162 [ 0 ] ) , V_256 ) ;
goto V_173;
}
V_9 = - V_14 ;
V_169 = F_72 ( V_162 [ 1 ] ) ;
if ( V_169 != strlen ( V_257 ) ) {
F_31 ( V_156 L_40
L_41 ,
V_169 , strlen ( V_257 ) ) ;
goto V_173;
}
V_9 = - V_13 ;
V_255 = F_77 ( V_169 + 1 , V_12 ) ;
if ( ! V_255 ) {
F_31 ( V_156 L_42
L_43 , V_169 ) ;
goto V_173;
}
V_9 = F_71 ( V_255 , V_161 , V_169 ) ;
if ( V_9 ) {
F_31 ( V_156 L_44 ) ;
F_7 ( V_255 ) ;
goto V_173;
}
V_9 = - V_14 ;
V_255 [ V_169 ] = '\0' ;
if ( strcmp ( V_255 , V_257 ) ) {
F_31 ( V_156 L_45
L_46 , V_255 , V_257 ) ;
F_7 ( V_255 ) ;
goto V_173;
}
F_7 ( V_255 ) ;
V_255 = NULL ;
V_9 = F_71 ( V_162 , V_161 , sizeof( T_1 ) * 4 ) ;
if ( V_9 )
goto V_173;
V_9 = - V_14 ;
V_7 -> V_165 = F_72 ( V_162 [ 0 ] ) ;
if ( V_7 -> V_165 < V_258 ||
V_7 -> V_165 > V_259 ) {
F_31 ( V_156 L_47
L_48 ,
F_72 ( V_162 [ 0 ] ) , V_258 , V_259 ) ;
goto V_173;
}
if ( ( F_72 ( V_162 [ 1 ] ) & V_260 ) ) {
V_7 -> V_103 = 1 ;
V_9 = - V_14 ;
if ( V_7 -> V_165 < V_166 ) {
F_31 ( V_156 L_49
L_50 ,
V_7 -> V_165 ) ;
goto V_173;
}
}
V_7 -> V_261 = ! ! ( F_72 ( V_162 [ 1 ] ) & V_262 ) ;
V_7 -> V_263 = ! ! ( F_72 ( V_162 [ 1 ] ) & V_264 ) ;
if ( V_7 -> V_165 >= V_265 ) {
V_9 = F_73 ( & V_7 -> V_52 , V_161 ) ;
if ( V_9 )
goto V_173;
}
if ( V_7 -> V_165 >= V_266 ) {
V_9 = F_73 ( & V_7 -> V_53 , V_161 ) ;
if ( V_9 )
goto V_173;
}
V_9 = - V_14 ;
V_4 = F_1 ( V_7 -> V_165 ) ;
if ( ! V_4 ) {
F_31 ( V_156 L_51
L_52 , V_7 -> V_165 ) ;
goto V_173;
}
V_9 = - V_14 ;
if ( F_72 ( V_162 [ 2 ] ) != V_4 -> V_267 ||
F_72 ( V_162 [ 3 ] ) != V_4 -> V_232 ) {
F_31 ( V_156 L_53
L_54 , F_72 ( V_162 [ 2 ] ) ,
F_72 ( V_162 [ 3 ] ) ,
V_4 -> V_267 , V_4 -> V_232 ) ;
goto V_173;
}
for ( V_3 = 0 ; V_3 < V_4 -> V_267 ; V_3 ++ ) {
V_9 = F_71 ( V_162 , V_161 , sizeof( T_1 ) * 2 ) ;
if ( V_9 )
goto V_173;
V_17 = F_72 ( V_162 [ 0 ] ) ;
V_97 = F_72 ( V_162 [ 1 ] ) ;
for ( V_183 = 0 ; V_183 < V_97 ; V_183 ++ ) {
V_9 = V_268 [ V_3 ] ( V_7 , V_7 -> V_47 [ V_3 ] . V_21 , V_161 ) ;
if ( V_9 )
goto V_173;
}
V_7 -> V_47 [ V_3 ] . V_17 = V_17 ;
}
V_9 = - V_14 ;
V_7 -> V_219 = F_99 ( V_7 , L_55 ) ;
if ( ! V_7 -> V_219 )
goto V_173;
V_9 = F_109 ( & V_7 -> V_49 , V_161 , V_7 ) ;
if ( V_9 )
goto V_173;
if ( V_7 -> V_165 >= V_269 ) {
V_9 = F_110 ( V_7 , V_161 ) ;
if ( V_9 )
goto V_173;
}
V_9 = F_71 ( V_162 , V_161 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_173;
V_97 = F_72 ( V_162 [ 0 ] ) ;
V_146 = NULL ;
for ( V_3 = 0 ; V_3 < V_97 ; V_3 ++ ) {
V_9 = - V_13 ;
V_145 = F_4 ( sizeof( * V_145 ) , V_12 ) ;
if ( ! V_145 )
goto V_173;
if ( V_146 )
V_146 -> V_119 = V_145 ;
else
V_7 -> V_152 = V_145 ;
V_9 = F_71 ( V_162 , V_161 , sizeof( T_1 ) * 3 ) ;
if ( V_9 )
goto V_173;
V_9 = - V_14 ;
V_145 -> V_11 = F_72 ( V_162 [ 0 ] ) ;
V_145 -> type = F_72 ( V_162 [ 1 ] ) ;
V_145 -> V_270 = F_72 ( V_162 [ 2 ] ) ;
if ( V_7 -> V_165 >= V_271 ) {
V_9 = F_71 ( V_162 , V_161 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_173;
V_145 -> V_32 = F_72 ( V_162 [ 0 ] ) ;
} else
V_145 -> V_32 = V_7 -> V_219 ;
V_9 = - V_14 ;
if ( ! F_65 ( V_7 , V_145 -> V_11 ) ||
! F_66 ( V_7 , V_145 -> type ) ||
! F_64 ( V_7 , V_145 -> V_32 ) ||
! F_65 ( V_7 , V_145 -> V_270 ) )
goto V_173;
V_146 = V_145 ;
}
V_9 = F_71 ( V_162 , V_161 , sizeof( T_1 ) ) ;
if ( V_9 )
goto V_173;
V_97 = F_72 ( V_162 [ 0 ] ) ;
V_143 = NULL ;
for ( V_3 = 0 ; V_3 < V_97 ; V_3 ++ ) {
V_9 = - V_13 ;
V_142 = F_4 ( sizeof( * V_142 ) , V_12 ) ;
if ( ! V_142 )
goto V_173;
if ( V_143 )
V_143 -> V_119 = V_142 ;
else
V_7 -> V_141 = V_142 ;
V_9 = F_71 ( V_162 , V_161 , sizeof( T_1 ) * 2 ) ;
if ( V_9 )
goto V_173;
V_9 = - V_14 ;
V_142 -> V_11 = F_72 ( V_162 [ 0 ] ) ;
V_142 -> V_270 = F_72 ( V_162 [ 1 ] ) ;
if ( ! F_65 ( V_7 , V_142 -> V_11 ) ||
! F_65 ( V_7 , V_142 -> V_270 ) )
goto V_173;
V_143 = V_142 ;
}
V_9 = F_103 ( V_7 , V_161 ) ;
if ( V_9 )
goto V_173;
V_9 = F_33 ( V_7 ) ;
if ( V_9 )
goto V_173;
V_9 = - V_14 ;
V_7 -> V_272 = F_100 ( V_7 , V_7 -> V_219 , L_56 ) ;
V_7 -> V_272 |= F_100 ( V_7 , V_7 -> V_219 , L_57 ) ;
if ( ! V_7 -> V_272 )
goto V_173;
V_9 = F_106 ( V_7 , V_4 , V_161 ) ;
if ( V_9 )
goto V_173;
V_9 = F_105 ( V_7 , V_161 ) ;
if ( V_9 )
goto V_173;
V_9 = F_101 ( V_7 , V_161 ) ;
if ( V_9 )
goto V_173;
V_9 = - V_13 ;
V_7 -> V_153 = F_37 ( sizeof( struct V_154 ) ,
V_7 -> V_75 . V_17 ,
V_12 | V_63 ) ;
if ( ! V_7 -> V_153 )
goto V_173;
V_9 = F_38 ( V_7 -> V_153 , 0 , V_7 -> V_75 . V_17 ,
V_12 | V_63 ) ;
if ( V_9 )
goto V_173;
for ( V_3 = 0 ; V_3 < V_7 -> V_75 . V_17 ; V_3 ++ ) {
struct V_154 * V_116 = F_60 ( V_7 -> V_153 , V_3 ) ;
F_97 ( ! V_116 ) ;
F_18 ( V_116 ) ;
if ( V_7 -> V_165 >= V_273 ) {
V_9 = F_73 ( V_116 , V_161 ) ;
if ( V_9 )
goto V_173;
}
V_9 = F_104 ( V_116 , V_3 , 1 ) ;
if ( V_9 )
goto V_173;
}
V_9 = F_98 ( V_7 ) ;
if ( V_9 )
goto V_173;
V_9 = 0 ;
V_19:
return V_9 ;
V_173:
F_56 ( V_7 ) ;
goto V_19;
}
static int F_111 ( struct V_210 * V_226 , void * V_161 )
{
T_2 V_162 [ 1 ] ;
int V_9 ;
V_162 [ 0 ] = F_112 ( V_226 -> V_87 ) ;
V_9 = F_113 ( V_162 , sizeof( T_1 ) , 1 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_114 ( & V_226 -> V_125 , V_161 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_115 ( struct V_127 * V_160 , void * V_161 )
{
T_2 V_162 [ 3 ] ;
T_5 V_163 ;
int V_9 , V_274 ;
V_274 = F_116 ( & V_160 -> V_86 [ 1 ] , & V_160 -> V_86 [ 0 ] ) ;
if ( V_274 )
V_163 = 2 ;
else
V_163 = 3 ;
V_162 [ 0 ] = F_112 ( V_163 - 1 ) ;
V_162 [ 1 ] = F_112 ( V_160 -> V_86 [ 0 ] . V_87 ) ;
if ( ! V_274 )
V_162 [ 2 ] = F_112 ( V_160 -> V_86 [ 1 ] . V_87 ) ;
F_97 ( V_163 > F_2 ( V_162 ) ) ;
V_9 = F_113 ( V_162 , sizeof( T_1 ) , V_163 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_114 ( & V_160 -> V_86 [ 0 ] . V_125 , V_161 ) ;
if ( V_9 )
return V_9 ;
if ( ! V_274 ) {
V_9 = F_114 ( & V_160 -> V_86 [ 1 ] . V_125 , V_161 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
static int F_117 ( void * V_275 , void * V_54 , void * V_276 )
{
char * V_8 = V_275 ;
struct V_83 * V_84 = V_54 ;
struct V_277 * V_278 = V_276 ;
void * V_161 = V_278 -> V_161 ;
T_2 V_162 [ 2 ] ;
T_5 V_169 ;
int V_9 ;
V_169 = strlen ( V_8 ) ;
V_162 [ 0 ] = F_112 ( V_169 ) ;
V_162 [ 1 ] = F_112 ( V_84 -> V_85 ) ;
V_9 = F_113 ( V_162 , sizeof( T_1 ) , 2 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_113 ( V_8 , 1 , V_169 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_111 ( V_84 -> V_86 , V_161 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_118 ( void * V_275 , void * V_54 , void * V_276 )
{
char * V_8 = V_275 ;
struct V_90 * V_91 = V_54 ;
struct V_277 * V_278 = V_276 ;
void * V_161 = V_278 -> V_161 ;
T_2 V_162 [ 3 ] ;
T_5 V_169 ;
int V_9 ;
V_169 = strlen ( V_8 ) ;
V_162 [ 0 ] = F_112 ( V_169 ) ;
V_162 [ 1 ] = F_112 ( V_91 -> V_15 ) ;
V_162 [ 2 ] = F_112 ( V_91 -> V_85 ) ;
V_9 = F_113 ( V_162 , sizeof( T_1 ) , 3 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_113 ( V_8 , 1 , V_169 , V_161 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_119 ( struct V_6 * V_7 , void * V_161 )
{
struct V_144 * V_160 = V_7 -> V_152 ;
struct V_144 * V_145 ;
T_1 V_162 [ 3 ] ;
T_5 V_97 ;
int V_9 ;
V_97 = 0 ;
for ( V_145 = V_160 ; V_145 ; V_145 = V_145 -> V_119 )
V_97 ++ ;
V_162 [ 0 ] = F_112 ( V_97 ) ;
V_9 = F_113 ( V_162 , sizeof( T_1 ) , 1 , V_161 ) ;
if ( V_9 )
return V_9 ;
for ( V_145 = V_160 ; V_145 ; V_145 = V_145 -> V_119 ) {
V_162 [ 0 ] = F_112 ( V_145 -> V_11 ) ;
V_162 [ 1 ] = F_112 ( V_145 -> type ) ;
V_162 [ 2 ] = F_112 ( V_145 -> V_270 ) ;
V_9 = F_113 ( V_162 , sizeof( T_1 ) , 3 , V_161 ) ;
if ( V_9 )
return V_9 ;
if ( V_7 -> V_165 >= V_271 ) {
V_162 [ 0 ] = F_112 ( V_145 -> V_32 ) ;
V_9 = F_113 ( V_162 , sizeof( T_1 ) , 1 , V_161 ) ;
if ( V_9 )
return V_9 ;
}
}
return 0 ;
}
static int F_120 ( struct V_141 * V_160 , void * V_161 )
{
struct V_141 * V_142 ;
T_1 V_162 [ 2 ] ;
T_5 V_97 ;
int V_9 ;
V_97 = 0 ;
for ( V_142 = V_160 ; V_142 ; V_142 = V_142 -> V_119 )
V_97 ++ ;
V_162 [ 0 ] = F_112 ( V_97 ) ;
V_9 = F_113 ( V_162 , sizeof( T_1 ) , 1 , V_161 ) ;
if ( V_9 )
return V_9 ;
for ( V_142 = V_160 ; V_142 ; V_142 = V_142 -> V_119 ) {
V_162 [ 0 ] = F_112 ( V_142 -> V_11 ) ;
V_162 [ 1 ] = F_112 ( V_142 -> V_270 ) ;
V_9 = F_113 ( V_162 , sizeof( T_1 ) , 2 , V_161 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
static int F_121 ( struct V_6 * V_7 , struct V_131 * V_130 ,
void * V_161 )
{
int V_9 ;
T_2 V_162 [ 3 ] ;
V_162 [ 0 ] = F_112 ( V_130 -> V_157 ) ;
V_162 [ 1 ] = F_112 ( V_130 -> V_11 ) ;
V_162 [ 2 ] = F_112 ( V_130 -> type ) ;
V_9 = F_113 ( V_162 , sizeof( T_1 ) , 3 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_115 ( & V_130 -> V_124 , V_161 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_122 ( void * V_275 , void * V_54 , void * V_161 )
{
char * V_8 = V_275 ;
struct V_171 * V_172 = V_54 ;
T_2 V_162 [ 2 ] ;
T_5 V_169 ;
int V_9 ;
V_169 = strlen ( V_8 ) ;
V_162 [ 0 ] = F_112 ( V_169 ) ;
V_162 [ 1 ] = F_112 ( V_172 -> V_15 ) ;
V_9 = F_113 ( V_162 , sizeof( T_1 ) , 2 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_113 ( V_8 , 1 , V_169 , V_161 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_123 ( void * V_275 , void * V_54 , void * V_276 )
{
char * V_8 = V_275 ;
struct V_56 * V_57 = V_54 ;
struct V_277 * V_278 = V_276 ;
void * V_161 = V_278 -> V_161 ;
T_2 V_162 [ 4 ] ;
T_5 V_169 ;
int V_9 ;
V_169 = strlen ( V_8 ) ;
V_162 [ 0 ] = F_112 ( V_169 ) ;
V_162 [ 1 ] = F_112 ( V_57 -> V_15 ) ;
V_162 [ 2 ] = F_112 ( V_57 -> V_106 . V_17 ) ;
V_162 [ 3 ] = F_112 ( V_57 -> V_106 . V_21 -> V_97 ) ;
V_9 = F_113 ( V_162 , sizeof( T_1 ) , 4 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_113 ( V_8 , 1 , V_169 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_40 ( V_57 -> V_106 . V_21 , F_122 , V_161 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_124 ( struct V_175 * V_176 , void * V_161 )
{
int V_9 ;
T_2 V_162 [ 1 ] ;
if ( F_114 ( & V_176 -> V_111 , V_161 ) )
return - V_14 ;
if ( F_114 ( & V_176 -> V_112 , V_161 ) )
return - V_14 ;
V_162 [ 0 ] = F_112 ( V_176 -> V_168 ) ;
V_9 = F_113 ( V_162 , sizeof( T_1 ) , 1 , V_161 ) ;
if ( V_9 )
return - V_14 ;
return 0 ;
}
static int F_125 ( struct V_6 * V_7 , struct V_113 * V_215 ,
void * V_161 )
{
struct V_113 * V_130 ;
struct V_107 * V_116 ;
T_2 V_162 [ 3 ] ;
T_1 V_97 ;
int V_9 ;
for ( V_130 = V_215 ; V_130 ; V_130 = V_130 -> V_119 ) {
V_97 = 0 ;
for ( V_116 = V_130 -> V_108 ; V_116 ; V_116 = V_116 -> V_119 )
V_97 ++ ;
V_162 [ 0 ] = F_112 ( V_130 -> V_106 ) ;
V_162 [ 1 ] = F_112 ( V_97 ) ;
V_9 = F_113 ( V_162 , sizeof( T_1 ) , 2 , V_161 ) ;
if ( V_9 )
return V_9 ;
for ( V_116 = V_130 -> V_108 ; V_116 ; V_116 = V_116 -> V_119 ) {
V_162 [ 0 ] = F_112 ( V_116 -> V_185 ) ;
V_162 [ 1 ] = F_112 ( V_116 -> V_186 ) ;
V_162 [ 2 ] = F_112 ( V_116 -> V_187 ) ;
V_9 = F_113 ( V_162 , sizeof( T_1 ) , 3 , V_161 ) ;
if ( V_9 )
return V_9 ;
switch ( V_116 -> V_185 ) {
case V_193 :
V_9 = F_114 ( & V_116 -> V_109 , V_161 ) ;
if ( V_9 )
return V_9 ;
if ( V_7 -> V_165 >=
V_195 ) {
V_9 = F_124 ( V_116 -> V_110 , V_161 ) ;
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
static int F_126 ( void * V_275 , void * V_54 , void * V_276 )
{
char * V_8 = V_275 ;
struct V_64 * V_65 = V_54 ;
struct V_277 * V_278 = V_276 ;
void * V_161 = V_278 -> V_161 ;
struct V_6 * V_7 = V_278 -> V_7 ;
struct V_113 * V_130 ;
T_2 V_162 [ 6 ] ;
T_1 V_178 ;
T_5 V_169 , V_196 ;
int V_9 ;
V_169 = strlen ( V_8 ) ;
if ( V_65 -> V_121 )
V_196 = strlen ( V_65 -> V_121 ) ;
else
V_196 = 0 ;
V_178 = 0 ;
for ( V_130 = V_65 -> V_118 ; V_130 ; V_130 = V_130 -> V_119 )
V_178 ++ ;
V_162 [ 0 ] = F_112 ( V_169 ) ;
V_162 [ 1 ] = F_112 ( V_196 ) ;
V_162 [ 2 ] = F_112 ( V_65 -> V_15 ) ;
V_162 [ 3 ] = F_112 ( V_65 -> V_106 . V_17 ) ;
if ( V_65 -> V_106 . V_21 )
V_162 [ 4 ] = F_112 ( V_65 -> V_106 . V_21 -> V_97 ) ;
else
V_162 [ 4 ] = 0 ;
V_162 [ 5 ] = F_112 ( V_178 ) ;
V_9 = F_113 ( V_162 , sizeof( T_1 ) , 6 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_113 ( V_8 , 1 , V_169 , V_161 ) ;
if ( V_9 )
return V_9 ;
if ( V_65 -> V_121 ) {
V_9 = F_113 ( V_65 -> V_121 , 1 , V_196 , V_161 ) ;
if ( V_9 )
return V_9 ;
}
V_9 = F_40 ( V_65 -> V_106 . V_21 , F_122 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_125 ( V_7 , V_65 -> V_118 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_178 = 0 ;
for ( V_130 = V_65 -> V_120 ; V_130 ; V_130 = V_130 -> V_119 )
V_178 ++ ;
V_162 [ 0 ] = F_112 ( V_178 ) ;
V_9 = F_113 ( V_162 , sizeof( T_1 ) , 1 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_125 ( V_7 , V_65 -> V_120 , V_161 ) ;
if ( V_9 )
return V_9 ;
if ( V_7 -> V_165 >= V_198 ) {
V_162 [ 0 ] = F_112 ( V_65 -> V_199 ) ;
V_162 [ 1 ] = F_112 ( V_65 -> V_200 ) ;
V_162 [ 2 ] = F_112 ( V_65 -> V_201 ) ;
V_9 = F_113 ( V_162 , sizeof( V_279 ) , 3 , V_161 ) ;
if ( V_9 )
return V_9 ;
}
if ( V_7 -> V_165 >= V_202 ) {
V_162 [ 0 ] = F_112 ( V_65 -> V_203 ) ;
V_9 = F_113 ( V_162 , sizeof( V_279 ) , 1 , V_161 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
static int F_127 ( void * V_275 , void * V_54 , void * V_276 )
{
char * V_8 = V_275 ;
struct V_10 * V_11 = V_54 ;
struct V_277 * V_278 = V_276 ;
void * V_161 = V_278 -> V_161 ;
struct V_6 * V_7 = V_278 -> V_7 ;
T_2 V_162 [ 3 ] ;
T_5 V_163 , V_169 ;
int V_9 ;
V_169 = strlen ( V_8 ) ;
V_163 = 0 ;
V_162 [ V_163 ++ ] = F_112 ( V_169 ) ;
V_162 [ V_163 ++ ] = F_112 ( V_11 -> V_15 ) ;
if ( V_7 -> V_165 >= V_205 )
V_162 [ V_163 ++ ] = F_112 ( V_11 -> V_69 ) ;
F_97 ( V_163 > F_2 ( V_162 ) ) ;
V_9 = F_113 ( V_162 , sizeof( T_1 ) , V_163 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_113 ( V_8 , 1 , V_169 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_114 ( & V_11 -> V_122 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_114 ( & V_11 -> V_111 , V_161 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_128 ( void * V_275 , void * V_54 , void * V_276 )
{
char * V_8 = V_275 ;
struct V_72 * V_73 = V_54 ;
struct V_277 * V_278 = V_276 ;
struct V_6 * V_7 = V_278 -> V_7 ;
void * V_161 = V_278 -> V_161 ;
T_2 V_162 [ 4 ] ;
int V_9 ;
T_5 V_163 , V_169 ;
V_169 = strlen ( V_8 ) ;
V_163 = 0 ;
V_162 [ V_163 ++ ] = F_112 ( V_169 ) ;
V_162 [ V_163 ++ ] = F_112 ( V_73 -> V_15 ) ;
if ( V_7 -> V_165 >= V_205 ) {
T_1 V_280 = 0 ;
if ( V_73 -> V_74 )
V_280 |= V_207 ;
if ( V_73 -> V_209 )
V_280 |= V_208 ;
V_162 [ V_163 ++ ] = F_112 ( V_280 ) ;
V_162 [ V_163 ++ ] = F_112 ( V_73 -> V_69 ) ;
} else {
V_162 [ V_163 ++ ] = F_112 ( V_73 -> V_74 ) ;
}
F_97 ( V_163 > F_2 ( V_162 ) ) ;
V_9 = F_113 ( V_162 , sizeof( T_1 ) , V_163 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_113 ( V_8 , 1 , V_169 , V_161 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_129 ( void * V_275 , void * V_54 , void * V_276 )
{
char * V_8 = V_275 ;
struct V_78 * V_79 = V_54 ;
struct V_277 * V_278 = V_276 ;
struct V_6 * V_7 = V_278 -> V_7 ;
void * V_161 = V_278 -> V_161 ;
T_2 V_162 [ 3 ] ;
T_5 V_163 , V_169 ;
int V_9 ;
V_169 = strlen ( V_8 ) ;
V_163 = 0 ;
V_162 [ V_163 ++ ] = F_112 ( V_169 ) ;
V_162 [ V_163 ++ ] = F_112 ( V_79 -> V_15 ) ;
if ( V_7 -> V_165 >= V_205 )
V_162 [ V_163 ++ ] = F_112 ( V_79 -> V_69 ) ;
F_97 ( V_163 > F_2 ( V_162 ) ) ;
V_9 = F_113 ( V_162 , sizeof( T_1 ) , V_163 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_113 ( V_8 , 1 , V_169 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_114 ( & V_79 -> V_123 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_115 ( & V_79 -> V_124 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_111 ( & V_79 -> V_126 , V_161 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_130 ( struct V_6 * V_7 , struct V_1 * V_4 ,
void * V_161 )
{
unsigned int V_3 , V_183 , V_9 ;
T_5 V_97 , V_169 ;
T_2 V_162 [ 3 ] ;
T_1 V_231 [ 8 ] ;
struct V_129 * V_130 ;
for ( V_3 = 0 ; V_3 < V_4 -> V_232 ; V_3 ++ ) {
V_97 = 0 ;
for ( V_130 = V_7 -> V_149 [ V_3 ] ; V_130 ; V_130 = V_130 -> V_119 )
V_97 ++ ;
V_162 [ 0 ] = F_112 ( V_97 ) ;
V_9 = F_113 ( V_162 , sizeof( T_1 ) , 1 , V_161 ) ;
if ( V_9 )
return V_9 ;
for ( V_130 = V_7 -> V_149 [ V_3 ] ; V_130 ; V_130 = V_130 -> V_119 ) {
switch ( V_3 ) {
case V_132 :
V_162 [ 0 ] = F_112 ( V_130 -> V_158 [ 0 ] ) ;
V_9 = F_113 ( V_162 , sizeof( T_1 ) , 1 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_121 ( V_7 , & V_130 -> V_131 [ 0 ] , V_161 ) ;
if ( V_9 )
return V_9 ;
break;
case V_133 :
case V_134 :
V_169 = strlen ( V_130 -> V_136 . V_33 ) ;
V_162 [ 0 ] = F_112 ( V_169 ) ;
V_9 = F_113 ( V_162 , sizeof( T_1 ) , 1 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_113 ( V_130 -> V_136 . V_33 , 1 , V_169 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_121 ( V_7 , & V_130 -> V_131 [ 0 ] , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_121 ( V_7 , & V_130 -> V_131 [ 1 ] , V_161 ) ;
if ( V_9 )
return V_9 ;
break;
case V_233 :
V_162 [ 0 ] = F_112 ( V_130 -> V_136 . V_234 . V_235 ) ;
V_162 [ 1 ] = F_112 ( V_130 -> V_136 . V_234 . V_236 ) ;
V_162 [ 2 ] = F_112 ( V_130 -> V_136 . V_234 . V_237 ) ;
V_9 = F_113 ( V_162 , sizeof( T_1 ) , 3 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_121 ( V_7 , & V_130 -> V_131 [ 0 ] , V_161 ) ;
if ( V_9 )
return V_9 ;
break;
case V_238 :
V_231 [ 0 ] = V_130 -> V_136 . V_215 . V_239 ;
V_231 [ 1 ] = V_130 -> V_136 . V_215 . V_240 ;
V_9 = F_113 ( V_231 , sizeof( T_1 ) , 2 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_121 ( V_7 , & V_130 -> V_131 [ 0 ] , V_161 ) ;
if ( V_9 )
return V_9 ;
break;
case V_135 :
V_162 [ 0 ] = F_112 ( V_130 -> V_39 . V_241 ) ;
V_169 = strlen ( V_130 -> V_136 . V_33 ) ;
V_162 [ 1 ] = F_112 ( V_169 ) ;
V_9 = F_113 ( V_162 , sizeof( T_1 ) , 2 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_113 ( V_130 -> V_136 . V_33 , 1 , V_169 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_121 ( V_7 , & V_130 -> V_131 [ 0 ] , V_161 ) ;
if ( V_9 )
return V_9 ;
break;
case V_244 :
for ( V_183 = 0 ; V_183 < 4 ; V_183 ++ )
V_231 [ V_183 ] = V_130 -> V_136 . V_245 . V_239 [ V_183 ] ;
for ( V_183 = 0 ; V_183 < 4 ; V_183 ++ )
V_231 [ V_183 + 4 ] = V_130 -> V_136 . V_245 . V_240 [ V_183 ] ;
V_9 = F_113 ( V_231 , sizeof( T_1 ) , 8 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_121 ( V_7 , & V_130 -> V_131 [ 0 ] , V_161 ) ;
if ( V_9 )
return V_9 ;
break;
case V_246 :
* ( ( V_249 * ) V_231 ) = F_131 ( V_130 -> V_136 . V_247 . V_248 ) ;
V_231 [ 2 ] = F_112 ( V_130 -> V_136 . V_247 . V_250 ) ;
V_231 [ 3 ] = F_112 ( V_130 -> V_136 . V_247 . V_251 ) ;
V_9 = F_113 ( V_231 , sizeof( T_1 ) , 4 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_121 ( V_7 , & V_130 -> V_131 [ 0 ] , V_161 ) ;
if ( V_9 )
return V_9 ;
break;
case V_252 :
V_169 = strlen ( V_130 -> V_136 . V_253 . V_254 ) ;
V_162 [ 0 ] = F_112 ( V_169 ) ;
V_162 [ 1 ] = F_112 ( V_130 -> V_136 . V_253 . V_234 ) ;
V_9 = F_113 ( V_162 , sizeof( T_1 ) , 2 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_113 ( V_130 -> V_136 . V_253 . V_254 , 1 , V_169 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_121 ( V_7 , & V_130 -> V_131 [ 0 ] , V_161 ) ;
if ( V_9 )
return V_9 ;
break;
}
}
}
return 0 ;
}
static int F_132 ( struct V_6 * V_7 , void * V_161 )
{
struct V_138 * V_138 ;
struct V_129 * V_130 ;
T_5 V_169 ;
T_2 V_162 [ 1 ] ;
int V_9 ;
V_169 = 0 ;
for ( V_138 = V_7 -> V_138 ; V_138 ; V_138 = V_138 -> V_119 )
V_169 ++ ;
V_162 [ 0 ] = F_112 ( V_169 ) ;
V_9 = F_113 ( V_162 , sizeof( T_1 ) , 1 , V_161 ) ;
if ( V_9 )
return V_9 ;
for ( V_138 = V_7 -> V_138 ; V_138 ; V_138 = V_138 -> V_119 ) {
V_169 = strlen ( V_138 -> V_150 ) ;
V_162 [ 0 ] = F_112 ( V_169 ) ;
V_9 = F_113 ( V_162 , sizeof( T_1 ) , 1 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_113 ( V_138 -> V_150 , 1 , V_169 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_169 = 0 ;
for ( V_130 = V_138 -> V_151 ; V_130 ; V_130 = V_130 -> V_119 )
V_169 ++ ;
V_162 [ 0 ] = F_112 ( V_169 ) ;
V_9 = F_113 ( V_162 , sizeof( T_1 ) , 1 , V_161 ) ;
if ( V_9 )
return V_9 ;
for ( V_130 = V_138 -> V_151 ; V_130 ; V_130 = V_130 -> V_119 ) {
V_169 = strlen ( V_130 -> V_136 . V_33 ) ;
V_162 [ 0 ] = F_112 ( V_169 ) ;
V_9 = F_113 ( V_162 , sizeof( T_1 ) , 1 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_113 ( V_130 -> V_136 . V_33 , 1 , V_169 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_162 [ 0 ] = F_112 ( V_130 -> V_39 . V_230 ) ;
V_9 = F_113 ( V_162 , sizeof( T_1 ) , 1 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_121 ( V_7 , & V_130 -> V_131 [ 0 ] , V_161 ) ;
if ( V_9 )
return V_9 ;
}
}
return 0 ;
}
static int F_133 ( void * V_8 , void * V_281 , void * V_276 )
{
int * V_282 = V_276 ;
* V_282 = * V_282 + 1 ;
return 0 ;
}
static int F_134 ( void * V_8 , void * V_281 , void * V_276 )
{
T_2 V_162 [ 2 ] ;
struct V_40 * V_128 = V_8 ;
struct V_127 * V_160 = V_281 ;
struct V_277 * V_278 = V_276 ;
void * V_161 = V_278 -> V_161 ;
struct V_6 * V_7 = V_278 -> V_7 ;
int V_9 ;
V_162 [ 0 ] = F_112 ( V_128 -> V_41 ) ;
V_162 [ 1 ] = F_112 ( V_128 -> V_42 ) ;
V_9 = F_113 ( V_162 , sizeof( T_1 ) , 2 , V_161 ) ;
if ( V_9 )
return V_9 ;
if ( V_7 -> V_165 >= V_218 ) {
V_162 [ 0 ] = F_112 ( V_128 -> V_43 ) ;
V_9 = F_113 ( V_162 , sizeof( T_1 ) , 1 , V_161 ) ;
if ( V_9 )
return V_9 ;
}
V_9 = F_115 ( V_160 , V_161 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_135 ( struct V_6 * V_7 , void * V_161 )
{
T_2 V_162 [ 1 ] ;
int V_9 , V_97 ;
struct V_277 V_278 ;
V_278 . V_7 = V_7 ;
V_278 . V_161 = V_161 ;
V_97 = 0 ;
V_9 = F_40 ( V_7 -> V_50 , F_133 , & V_97 ) ;
if ( V_9 )
return V_9 ;
V_162 [ 0 ] = F_112 ( V_97 ) ;
V_9 = F_113 ( V_162 , sizeof( T_1 ) , 1 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_40 ( V_7 -> V_50 , F_134 , & V_278 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_136 ( void * V_8 , void * V_281 , void * V_276 )
{
T_2 V_162 [ 4 ] ;
struct V_25 * V_26 = V_8 ;
struct V_221 * V_222 = V_281 ;
void * V_161 = V_276 ;
int V_9 ;
T_1 V_169 ;
V_169 = strlen ( V_26 -> V_33 ) ;
V_162 [ 0 ] = F_112 ( V_169 ) ;
V_9 = F_113 ( V_162 , sizeof( T_1 ) , 1 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_113 ( V_26 -> V_33 , sizeof( char ) , V_169 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_162 [ 0 ] = F_112 ( V_26 -> V_30 ) ;
V_162 [ 1 ] = F_112 ( V_26 -> V_31 ) ;
V_162 [ 2 ] = F_112 ( V_26 -> V_32 ) ;
V_162 [ 3 ] = F_112 ( V_222 -> V_222 ) ;
V_9 = F_113 ( V_162 , sizeof( T_1 ) , 4 , V_161 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_137 ( struct V_6 * V_7 , void * V_161 )
{
T_1 V_97 ;
T_2 V_162 [ 1 ] ;
int V_9 ;
if ( V_7 -> V_165 < V_223 )
return 0 ;
V_97 = 0 ;
V_9 = F_40 ( V_7 -> V_25 , F_133 , & V_97 ) ;
if ( V_9 )
return V_9 ;
V_162 [ 0 ] = F_112 ( V_97 ) ;
V_9 = F_113 ( V_162 , sizeof( T_1 ) , 1 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_40 ( V_7 -> V_25 , F_136 , V_161 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
int F_138 ( struct V_6 * V_7 , void * V_161 )
{
unsigned int V_3 , V_283 ;
int V_9 ;
T_2 V_162 [ 4 ] ;
T_1 V_284 ;
T_5 V_169 ;
struct V_1 * V_4 ;
if ( V_7 -> V_165 < V_273 ) {
F_31 ( V_156 L_58
L_59 , V_7 -> V_165 ,
V_273 ) ;
return - V_14 ;
}
V_284 = 0 ;
if ( V_7 -> V_103 )
V_284 |= V_260 ;
if ( V_7 -> V_261 )
V_284 |= V_262 ;
if ( V_7 -> V_263 )
V_284 |= V_264 ;
V_162 [ 0 ] = F_112 ( V_256 ) ;
V_169 = strlen ( V_257 ) ;
V_162 [ 1 ] = F_112 ( V_169 ) ;
V_9 = F_113 ( V_162 , sizeof( T_1 ) , 2 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_113 ( V_257 , 1 , V_169 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_4 = F_1 ( V_7 -> V_165 ) ;
if ( ! V_4 ) {
F_31 ( V_156 L_60
L_61 , V_7 -> V_165 ) ;
return - V_14 ;
}
V_162 [ 0 ] = F_112 ( V_7 -> V_165 ) ;
V_162 [ 1 ] = F_112 ( V_284 ) ;
V_162 [ 2 ] = F_112 ( V_4 -> V_267 ) ;
V_162 [ 3 ] = F_112 ( V_4 -> V_232 ) ;
V_9 = F_113 ( V_162 , sizeof( T_1 ) , 4 , V_161 ) ;
if ( V_9 )
return V_9 ;
if ( V_7 -> V_165 >= V_265 ) {
V_9 = F_114 ( & V_7 -> V_52 , V_161 ) ;
if ( V_9 )
return V_9 ;
}
if ( V_7 -> V_165 >= V_266 ) {
V_9 = F_114 ( & V_7 -> V_53 , V_161 ) ;
if ( V_9 )
return V_9 ;
}
V_283 = V_4 -> V_267 ;
for ( V_3 = 0 ; V_3 < V_283 ; V_3 ++ ) {
struct V_277 V_278 ;
V_278 . V_161 = V_161 ;
V_278 . V_7 = V_7 ;
V_162 [ 0 ] = F_112 ( V_7 -> V_47 [ V_3 ] . V_17 ) ;
V_162 [ 1 ] = F_112 ( V_7 -> V_47 [ V_3 ] . V_21 -> V_97 ) ;
V_9 = F_113 ( V_162 , sizeof( T_1 ) , 2 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_40 ( V_7 -> V_47 [ V_3 ] . V_21 , V_285 [ V_3 ] , & V_278 ) ;
if ( V_9 )
return V_9 ;
}
V_9 = F_139 ( V_7 , & V_7 -> V_49 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_140 ( V_7 , V_7 -> V_286 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_119 ( V_7 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_120 ( V_7 -> V_141 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_137 ( V_7 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_130 ( V_7 , V_4 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_132 ( V_7 , V_161 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_135 ( V_7 , V_161 ) ;
if ( V_9 )
return V_9 ;
for ( V_3 = 0 ; V_3 < V_7 -> V_75 . V_17 ; V_3 ++ ) {
struct V_154 * V_116 = F_60 ( V_7 -> V_153 , V_3 ) ;
F_97 ( ! V_116 ) ;
V_9 = F_114 ( V_116 , V_161 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
