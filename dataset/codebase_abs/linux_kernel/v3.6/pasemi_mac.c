static int F_1 ( void )
{
#if F_2 ( V_1 )
return 1 ;
#else
return F_3 ( V_2 ) ;
#endif
}
static void F_4 ( unsigned int V_3 , unsigned int V_4 )
{
F_5 ( V_3 , V_4 ) ;
}
static unsigned int F_6 ( const struct V_5 * V_6 , unsigned int V_3 )
{
return F_7 ( V_6 -> V_7 , V_3 ) ;
}
static void F_8 ( const struct V_5 * V_6 , unsigned int V_3 ,
unsigned int V_4 )
{
F_9 ( V_6 -> V_7 , V_3 , V_4 ) ;
}
static unsigned int F_10 ( unsigned int V_3 )
{
return F_11 ( V_3 ) ;
}
static void F_12 ( unsigned int V_3 , unsigned int V_4 )
{
F_13 ( V_3 , V_4 ) ;
}
static struct V_8 * F_14 ( const struct V_5 * V_6 )
{
return V_6 -> V_9 ;
}
static struct V_10 * F_15 ( const struct V_5 * V_6 )
{
return V_6 -> V_11 ;
}
static inline void F_16 ( const struct V_12 * V_13 )
{
const void * V_14 = V_13 ;
F_17 ( V_14 ) ;
F_17 ( V_14 + 64 ) ;
F_17 ( V_14 + 128 ) ;
F_17 ( V_14 + 192 ) ;
}
static int F_18 ( struct V_5 * V_6 )
{
struct V_15 * V_16 = V_6 -> V_16 ;
T_1 V_17 ;
int V_18 , V_19 , V_20 , V_21 ;
int V_22 = V_16 -> V_22 ;
V_17 = F_10 ( V_23 ) ;
V_18 = ( V_17 & V_24 ) >> V_25 ;
V_19 = ( V_17 & V_26 ) >> V_27 ;
for ( V_20 = 0 ; V_20 < ( V_18 + 3 ) / 4 ; V_20 ++ ) {
V_17 = F_10 ( V_19 + 4 * V_20 ) ;
for ( V_21 = 0 ; V_21 < 4 ; V_21 ++ ) {
if ( ( ( V_17 >> ( 8 * V_21 ) ) & 0xff ) == V_22 )
return V_20 * 4 + V_21 ;
}
}
return - 1 ;
}
static void F_19 ( struct V_5 * V_6 )
{
unsigned int V_28 ;
V_28 = F_6 ( V_6 , V_29 ) ;
V_28 &= ~ V_30 ;
F_8 ( V_6 , V_29 , V_28 ) ;
}
static void F_20 ( struct V_5 * V_6 )
{
unsigned int V_28 ;
V_28 = F_6 ( V_6 , V_29 ) ;
V_28 |= V_30 ;
F_8 ( V_6 , V_29 , V_28 ) ;
}
static int F_21 ( struct V_5 * V_6 )
{
struct V_15 * V_16 = V_6 -> V_16 ;
struct V_31 * V_32 = F_22 ( V_16 ) ;
int V_33 ;
const T_2 * V_34 ;
T_2 V_35 [ 6 ] ;
if ( ! V_32 ) {
F_23 ( & V_16 -> V_36 ,
L_1 ) ;
return - V_37 ;
}
V_34 = F_24 ( V_32 , L_2 , & V_33 ) ;
if ( V_34 && V_33 == 6 ) {
memcpy ( V_6 -> V_38 , V_34 , 6 ) ;
return 0 ;
}
if ( V_34 == NULL )
V_34 = F_24 ( V_32 , L_3 , NULL ) ;
if ( V_34 == NULL ) {
F_25 ( & V_16 -> V_36 ,
L_4 ) ;
return - V_37 ;
}
if ( sscanf ( V_34 , L_5 , & V_35 [ 0 ] ,
& V_35 [ 1 ] , & V_35 [ 2 ] , & V_35 [ 3 ] , & V_35 [ 4 ] , & V_35 [ 5 ] ) != 6 ) {
F_25 ( & V_16 -> V_36 ,
L_6 ) ;
return - V_39 ;
}
memcpy ( V_6 -> V_38 , V_35 , 6 ) ;
return 0 ;
}
static int F_26 ( struct V_40 * V_36 , void * V_41 )
{
struct V_5 * V_6 = F_27 ( V_36 ) ;
struct V_42 * V_35 = V_41 ;
unsigned int V_43 , V_44 ;
if ( ! F_28 ( V_35 -> V_45 ) )
return - V_46 ;
memcpy ( V_36 -> V_47 , V_35 -> V_45 , V_36 -> V_48 ) ;
V_43 = V_36 -> V_47 [ 2 ] << 24 |
V_36 -> V_47 [ 3 ] << 16 |
V_36 -> V_47 [ 4 ] << 8 |
V_36 -> V_47 [ 5 ] ;
V_44 = F_6 ( V_6 , V_49 ) ;
V_44 &= ~ 0xffff ;
V_44 |= V_36 -> V_47 [ 0 ] << 8 | V_36 -> V_47 [ 1 ] ;
F_19 ( V_6 ) ;
F_8 ( V_6 , V_50 , V_43 ) ;
F_8 ( V_6 , V_49 , V_44 ) ;
F_20 ( V_6 ) ;
return 0 ;
}
static int F_29 ( struct V_12 * V_13 , void * * V_51 ,
void * * V_52 , T_3 * V_53 , void * V_54 )
{
T_3 V_55 = ( T_3 ) V_54 ;
unsigned int V_56 ;
struct V_51 * V_57 ;
if ( ( V_55 & V_58 ) != V_59 )
return - 1 ;
F_30 ( V_13 ) ;
V_57 = F_31 ( V_13 ) ;
if ( V_57 -> V_60 != V_61 )
return - 1 ;
V_56 = F_32 ( V_13 ) ;
F_33 ( V_13 , V_56 ) ;
* V_52 = F_34 ( V_13 ) ;
if ( F_35 ( V_57 -> V_62 ) < V_56 + F_36 ( V_13 ) )
return - 1 ;
* V_53 = V_63 | V_64 ;
* V_51 = V_57 ;
return 0 ;
}
static int F_37 ( struct V_5 * V_6 ,
const int V_65 ,
struct V_12 * V_13 ,
const T_4 * V_66 )
{
int V_67 ;
struct V_15 * V_16 = V_6 -> V_68 ;
F_38 ( V_16 , V_66 [ 0 ] , F_39 ( V_13 ) , V_69 ) ;
for ( V_67 = 0 ; V_67 < V_65 ; V_67 ++ ) {
const T_5 * V_70 = & F_40 ( V_13 ) -> V_71 [ V_67 ] ;
F_41 ( V_16 , V_66 [ V_67 + 1 ] , F_42 ( V_70 ) , V_69 ) ;
}
F_43 ( V_13 ) ;
return ( V_65 + 3 ) & ~ 1 ;
}
static struct V_72 * F_44 ( struct V_5 * V_6 )
{
struct V_72 * V_73 ;
T_1 V_4 ;
unsigned int V_74 ;
int V_75 ;
V_73 = F_45 ( V_76 , sizeof( struct V_72 ) ,
F_46 ( struct V_72 , V_77 ) ) ;
if ( ! V_73 ) {
F_47 ( & V_6 -> V_16 -> V_36 , L_7 ) ;
goto V_78;
}
V_75 = V_73 -> V_77 . V_75 ;
V_73 -> V_79 = V_80 ;
V_73 -> V_81 = 0 ;
if ( F_48 ( & V_73 -> V_77 , V_80 ) )
goto V_82;
F_12 ( F_49 ( V_75 ) ,
F_50 ( V_73 -> V_77 . V_83 ) ) ;
V_4 = F_51 ( V_73 -> V_77 . V_83 >> 32 ) ;
V_4 |= F_52 ( V_80 >> 3 ) ;
F_12 ( F_53 ( V_75 ) , V_4 ) ;
V_73 -> V_84 [ 0 ] = F_54 () ;
V_73 -> V_84 [ 1 ] = F_54 () ;
if ( V_73 -> V_84 [ 0 ] < 0 || V_73 -> V_84 [ 1 ] < 0 )
goto V_85;
F_55 ( V_73 -> V_84 [ 0 ] ) ;
F_55 ( V_73 -> V_84 [ 1 ] ) ;
V_73 -> V_86 = F_56 () ;
if ( V_73 -> V_86 < 0 )
goto V_87;
V_74 = V_88 | V_89 |
F_57 ( V_73 -> V_86 ) |
V_90 | V_91 ;
if ( F_1 () )
V_74 |= V_92 | V_93 ;
F_12 ( F_58 ( V_75 ) , V_74 ) ;
F_59 ( & V_73 -> V_77 , V_94 |
V_95 |
V_96 |
V_97 ) ;
return V_73 ;
V_87:
V_85:
if ( V_73 -> V_84 [ 0 ] >= 0 )
F_60 ( V_73 -> V_84 [ 0 ] ) ;
if ( V_73 -> V_84 [ 1 ] >= 0 )
F_60 ( V_73 -> V_84 [ 1 ] ) ;
F_61 ( & V_73 -> V_77 ) ;
V_82:
F_62 ( & V_73 -> V_77 ) ;
V_78:
return NULL ;
}
static void F_63 ( struct V_5 * V_6 )
{
int V_20 ;
V_6 -> V_98 [ 0 ] = F_44 ( V_6 ) ;
if ( V_6 -> type == V_99 )
V_6 -> V_98 [ 1 ] = F_44 ( V_6 ) ;
else
V_6 -> V_98 [ 1 ] = 0 ;
for ( V_20 = 0 ; V_20 < V_100 ; V_20 ++ )
if ( V_6 -> V_98 [ V_20 ] )
V_6 -> V_101 ++ ;
}
static void F_64 ( struct V_72 * V_102 )
{
F_65 ( & V_102 -> V_77 ) ;
F_60 ( V_102 -> V_84 [ 0 ] ) ;
F_60 ( V_102 -> V_84 [ 1 ] ) ;
F_61 ( & V_102 -> V_77 ) ;
F_62 ( & V_102 -> V_77 ) ;
F_66 ( V_102 -> V_86 ) ;
}
static int F_67 ( const struct V_40 * V_36 )
{
struct V_8 * V_73 ;
struct V_5 * V_6 = F_27 ( V_36 ) ;
int V_75 ;
unsigned int V_74 ;
V_73 = F_45 ( V_103 , sizeof( struct V_8 ) ,
F_46 ( struct V_8 , V_77 ) ) ;
if ( ! V_73 ) {
F_47 ( & V_6 -> V_16 -> V_36 , L_8 ) ;
goto V_78;
}
V_75 = V_73 -> V_77 . V_75 ;
F_68 ( & V_73 -> V_104 ) ;
V_73 -> V_79 = V_105 ;
V_73 -> V_106 = F_69 ( sizeof( struct V_107 ) *
V_105 , V_108 ) ;
if ( ! V_73 -> V_106 )
goto V_109;
if ( F_48 ( & V_73 -> V_77 , V_105 ) )
goto V_82;
V_73 -> V_110 = F_70 ( & V_6 -> V_68 -> V_36 ,
V_105 * sizeof( T_3 ) ,
& V_73 -> V_111 , V_108 ) ;
if ( ! V_73 -> V_110 )
goto V_82;
memset ( V_73 -> V_110 , 0 , V_105 * sizeof( T_3 ) ) ;
F_12 ( F_71 ( V_75 ) ,
F_72 ( V_73 -> V_77 . V_83 ) ) ;
F_12 ( F_73 ( V_75 ) ,
F_74 ( V_73 -> V_77 . V_83 >> 32 ) |
F_75 ( V_105 >> 3 ) ) ;
V_74 = F_76 ( 2 ) ;
if ( F_1 () )
V_74 |= V_112 ;
F_12 ( F_77 ( V_75 ) , V_74 ) ;
F_12 ( F_78 ( V_6 -> V_7 ) ,
F_79 ( V_73 -> V_111 ) ) ;
F_12 ( F_80 ( V_6 -> V_7 ) ,
F_81 ( V_73 -> V_111 >> 32 ) |
F_82 ( V_105 >> 3 ) ) ;
V_74 = F_83 ( 2 ) | V_113 |
V_114 | V_115 |
V_116 ;
if ( F_1 () )
V_74 |= V_117 | V_118 ;
F_12 ( F_84 ( V_6 -> V_7 ) , V_74 ) ;
V_73 -> V_81 = 0 ;
V_73 -> V_119 = 0 ;
V_73 -> V_6 = V_6 ;
V_6 -> V_9 = V_73 ;
return 0 ;
V_82:
F_85 ( V_73 -> V_106 ) ;
V_109:
F_62 ( & V_73 -> V_77 ) ;
V_78:
return - V_120 ;
}
static struct V_10 *
F_86 ( const struct V_40 * V_36 )
{
struct V_5 * V_6 = F_27 ( V_36 ) ;
T_1 V_4 ;
struct V_10 * V_73 ;
unsigned int V_74 ;
int V_75 ;
V_73 = F_45 ( V_76 , sizeof( struct V_10 ) ,
F_46 ( struct V_10 , V_77 ) ) ;
if ( ! V_73 ) {
F_47 ( & V_6 -> V_16 -> V_36 , L_9 ) ;
goto V_78;
}
V_75 = V_73 -> V_77 . V_75 ;
F_68 ( & V_73 -> V_104 ) ;
V_73 -> V_79 = V_121 ;
V_73 -> V_106 = F_69 ( sizeof( struct V_107 ) *
V_121 , V_108 ) ;
if ( ! V_73 -> V_106 )
goto V_109;
if ( F_48 ( & V_73 -> V_77 , V_121 ) )
goto V_82;
F_12 ( F_49 ( V_75 ) ,
F_50 ( V_73 -> V_77 . V_83 ) ) ;
V_4 = F_51 ( V_73 -> V_77 . V_83 >> 32 ) ;
V_4 |= F_52 ( V_121 >> 3 ) ;
F_12 ( F_53 ( V_75 ) , V_4 ) ;
V_74 = V_122 |
F_57 ( V_6 -> V_7 ) |
V_89 |
F_87 ( 4 ) ;
if ( F_1 () )
V_74 |= V_92 | V_93 ;
F_12 ( F_58 ( V_75 ) , V_74 ) ;
V_73 -> V_81 = 0 ;
V_73 -> V_119 = 0 ;
V_73 -> V_6 = V_6 ;
return V_73 ;
V_82:
F_85 ( V_73 -> V_106 ) ;
V_109:
F_62 ( & V_73 -> V_77 ) ;
V_78:
return NULL ;
}
static void F_88 ( struct V_5 * V_6 )
{
struct V_10 * V_123 = F_15 ( V_6 ) ;
unsigned int V_20 , V_21 ;
struct V_107 * V_124 ;
T_4 V_66 [ V_125 + 1 ] ;
int V_126 , V_65 ;
int V_127 , V_128 ;
V_127 = V_123 -> V_119 ;
V_128 = V_123 -> V_81 ;
if ( V_127 > V_128 )
V_128 += V_121 ;
for ( V_20 = V_127 ; V_20 < V_128 ; V_20 += V_126 ) {
V_124 = & V_123 -> V_106 [ ( V_20 + 1 ) & ( V_121 - 1 ) ] ;
if ( V_124 -> V_129 && V_124 -> V_13 ) {
V_65 = F_40 ( V_124 -> V_13 ) -> V_130 ;
for ( V_21 = 0 ; V_21 <= V_65 ; V_21 ++ )
V_66 [ V_21 ] = V_123 -> V_106 [ ( V_20 + 1 + V_21 ) &
( V_121 - 1 ) ] . V_129 ;
V_126 = F_37 ( V_6 , V_65 ,
V_124 -> V_13 , V_66 ) ;
} else
V_126 = 2 ;
}
F_85 ( V_123 -> V_106 ) ;
F_62 ( & V_123 -> V_77 ) ;
}
static void F_89 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = F_14 ( V_6 ) ;
unsigned int V_20 ;
struct V_107 * V_124 ;
for ( V_20 = 0 ; V_20 < V_105 ; V_20 ++ ) {
V_124 = & F_90 ( V_9 , V_20 ) ;
if ( V_124 -> V_13 && V_124 -> V_129 ) {
F_38 ( V_6 -> V_68 ,
V_124 -> V_129 ,
V_124 -> V_13 -> V_33 ,
V_131 ) ;
F_91 ( V_124 -> V_13 ) ;
}
V_124 -> V_129 = 0 ;
V_124 -> V_13 = NULL ;
}
for ( V_20 = 0 ; V_20 < V_105 ; V_20 ++ )
F_92 ( V_9 , V_20 ) = 0 ;
}
static void F_93 ( struct V_5 * V_6 )
{
F_89 ( V_6 ) ;
F_94 ( & V_6 -> V_68 -> V_36 , V_105 * sizeof( T_3 ) ,
F_14 ( V_6 ) -> V_110 , F_14 ( V_6 ) -> V_111 ) ;
F_85 ( F_14 ( V_6 ) -> V_106 ) ;
F_62 ( & F_14 ( V_6 ) -> V_77 ) ;
V_6 -> V_9 = NULL ;
}
static void F_95 ( struct V_40 * V_36 ,
const int V_128 )
{
const struct V_5 * V_6 = F_27 ( V_36 ) ;
struct V_8 * V_9 = F_14 ( V_6 ) ;
int V_132 , V_133 ;
if ( V_128 <= 0 )
return;
V_132 = F_14 ( V_6 ) -> V_81 ;
for ( V_133 = 0 ; V_133 < V_128 ; V_133 ++ ) {
struct V_107 * V_124 = & F_90 ( V_9 , V_132 ) ;
T_3 * V_134 = & F_92 ( V_9 , V_132 ) ;
struct V_12 * V_13 ;
T_4 V_129 ;
F_96 ( * V_134 ) ;
V_13 = F_97 ( V_36 , V_6 -> V_135 ) ;
F_98 ( V_13 , V_136 ) ;
if ( F_99 ( ! V_13 ) )
break;
V_129 = F_100 ( V_6 -> V_68 , V_13 -> V_54 ,
V_6 -> V_135 - V_136 ,
V_131 ) ;
if ( F_99 ( F_101 ( V_6 -> V_68 , V_129 ) ) ) {
F_43 ( V_124 -> V_13 ) ;
break;
}
V_124 -> V_13 = V_13 ;
V_124 -> V_129 = V_129 ;
* V_134 = F_102 ( V_6 -> V_135 ) | F_103 ( V_129 ) ;
V_132 ++ ;
}
F_104 () ;
F_12 ( F_105 ( V_6 -> V_7 ) , V_133 ) ;
F_14 ( V_6 ) -> V_81 = ( F_14 ( V_6 ) -> V_81 + V_133 ) &
( V_105 - 1 ) ;
}
static void F_106 ( const struct V_5 * V_6 )
{
struct V_8 * V_9 = F_14 ( V_6 ) ;
unsigned int V_3 , V_137 ;
V_137 = * V_9 -> V_77 . V_138 & V_139 ;
V_3 = F_107 ( V_137 ) | V_140 ;
if ( * V_9 -> V_77 . V_138 & V_141 )
V_3 |= V_142 ;
F_4 ( F_108 ( V_6 -> V_9 -> V_77 . V_75 ) , V_3 ) ;
}
static void F_109 ( const struct V_5 * V_6 )
{
unsigned int V_3 , V_137 ;
V_137 = * F_15 ( V_6 ) -> V_77 . V_138 & V_139 ;
V_3 = F_110 ( V_137 ) | V_143 ;
F_4 ( F_111 ( F_15 ( V_6 ) -> V_77 . V_75 ) , V_3 ) ;
}
static inline void F_112 ( const struct V_5 * V_6 ,
const T_3 V_55 )
{
unsigned int V_144 , V_145 ;
struct V_146 * V_77 = & F_14 ( V_6 ) -> V_77 ;
if ( ! F_113 ( V_6 ) )
return;
V_144 = F_10 ( F_114 ( V_6 -> V_7 ) ) ;
V_145 = F_10 ( F_115 ( V_77 -> V_75 ) ) ;
F_116 ( V_147 L_10 ,
V_55 , * V_77 -> V_138 ) ;
F_116 ( V_147 L_11 ,
V_144 , V_145 ) ;
}
static inline void F_117 ( const struct V_5 * V_6 ,
const T_3 V_148 )
{
unsigned int V_149 ;
struct V_146 * V_77 = & F_15 ( V_6 ) -> V_77 ;
if ( ! F_118 ( V_6 ) )
return;
V_149 = F_10 ( F_119 ( V_77 -> V_75 ) ) ;
F_116 ( V_147 L_12\
L_13 , V_148 , * V_77 -> V_138 ) ;
F_116 ( V_147 L_14 , V_149 ) ;
}
static int F_120 ( struct V_8 * V_9 ,
const int V_128 )
{
const struct V_146 * V_77 = & V_9 -> V_77 ;
struct V_5 * V_6 = V_9 -> V_6 ;
struct V_15 * V_16 = V_6 -> V_68 ;
unsigned int V_150 ;
int V_133 , V_151 , V_152 , V_153 ;
struct V_107 * V_124 ;
struct V_12 * V_13 ;
unsigned int V_33 ;
T_3 V_55 , V_154 ;
T_4 V_129 ;
V_152 = 0 ;
V_153 = 0 ;
F_121 ( & V_9 -> V_104 ) ;
V_150 = V_9 -> V_119 ;
F_17 ( & F_122 ( V_9 , V_150 ) ) ;
for ( V_133 = 0 ; V_133 < V_128 ; V_133 ++ ) {
V_55 = F_122 ( V_9 , V_150 ) ;
F_17 ( & F_122 ( V_9 , V_150 + 4 ) ) ;
if ( ( V_55 & V_155 ) ||
( * V_77 -> V_138 & V_156 ) )
F_112 ( V_6 , V_55 ) ;
if ( ! ( V_55 & V_157 ) )
break;
V_124 = NULL ;
F_123 ( ! ( V_55 & V_158 ) ) ;
V_154 = ( F_122 ( V_9 , V_150 + 1 ) & V_159 ) >>
V_160 ;
V_151 = V_154 - 1 ;
V_129 = ( F_122 ( V_9 , V_150 + 2 ) & V_161 ) ;
V_124 = & F_90 ( V_9 , V_151 ) ;
V_13 = V_124 -> V_13 ;
F_16 ( V_13 ) ;
V_33 = ( V_55 & V_162 ) >> V_163 ;
F_38 ( V_16 , V_129 , V_6 -> V_135 - V_136 ,
V_131 ) ;
if ( V_55 & V_164 ) {
V_6 -> V_165 -> V_166 . V_167 ++ ;
V_6 -> V_165 -> V_166 . V_168 ++ ;
goto V_169;
}
V_124 -> V_13 = NULL ;
V_124 -> V_129 = 0 ;
if ( F_124 ( ( V_55 & V_58 ) == V_59 ) ) {
V_13 -> V_170 = V_171 ;
V_13 -> V_172 = ( V_55 & V_173 ) >>
V_174 ;
} else
F_125 ( V_13 ) ;
V_153 ++ ;
V_152 += V_33 ;
F_126 ( V_13 , V_33 - 4 ) ;
V_13 -> V_60 = F_127 ( V_13 , V_6 -> V_165 ) ;
F_128 ( & V_6 -> V_175 , V_13 , ( void * ) V_55 ) ;
V_169:
F_122 ( V_9 , V_150 ) = 0 ;
F_122 ( V_9 , V_150 + 1 ) = 0 ;
F_92 ( V_9 , V_151 ) = 0 ;
V_150 += 4 ;
}
if ( V_150 > V_105 ) {
F_4 ( V_176 , 0 ) ;
V_150 &= ( V_105 - 1 ) ;
}
F_14 ( V_6 ) -> V_119 = V_150 ;
F_129 ( & V_6 -> V_175 ) ;
F_12 ( F_130 ( V_6 -> V_9 -> V_77 . V_75 ) , V_133 << 1 ) ;
F_95 ( V_6 -> V_165 , V_133 ) ;
V_6 -> V_165 -> V_166 . V_177 += V_152 ;
V_6 -> V_165 -> V_166 . V_178 += V_153 ;
F_131 ( & F_14 ( V_6 ) -> V_104 ) ;
return V_133 ;
}
static int F_132 ( struct V_10 * V_123 )
{
struct V_146 * V_77 = & V_123 -> V_77 ;
struct V_5 * V_6 = V_123 -> V_6 ;
int V_20 , V_21 ;
unsigned int V_127 , V_179 , V_180 , V_181 ;
unsigned int V_182 ;
unsigned int V_183 ;
unsigned long V_28 ;
struct V_12 * V_184 [ V_185 ] ;
T_4 V_66 [ V_185 ] [ V_125 + 1 ] ;
int V_186 [ V_185 ] ;
int V_130 ;
V_183 = 0 ;
V_181 = V_185 ;
V_187:
F_133 ( & V_123 -> V_104 , V_28 ) ;
V_127 = V_123 -> V_119 ;
V_182 = V_123 -> V_81 ;
F_17 ( & F_134 ( V_123 , V_127 + 1 ) . V_13 ) ;
if ( V_127 > V_182 )
V_182 += V_121 ;
V_180 = 0 ;
V_179 = 0 ;
for ( V_20 = V_127 ;
V_179 < V_181 && V_20 < V_182 ;
V_20 += V_180 ) {
T_3 V_148 = F_135 ( V_123 , V_20 ) ;
struct V_12 * V_13 ;
if ( ( V_148 & V_188 ) ||
( * V_77 -> V_138 & V_156 ) )
F_117 ( V_6 , V_148 ) ;
if ( ! ( V_148 & V_189 ) ) {
F_135 ( V_123 , V_20 ) = 0 ;
F_135 ( V_123 , V_20 + 1 ) = 0 ;
V_180 = 2 ;
continue;
}
V_13 = F_134 ( V_123 , V_20 + 1 ) . V_13 ;
V_130 = F_134 ( V_123 , V_20 ) . V_129 ;
if ( F_99 ( V_148 & V_190 ) )
break;
V_180 = 2 + V_130 ;
if ( V_180 & 1 )
V_180 ++ ;
for ( V_21 = 0 ; V_21 <= V_130 ; V_21 ++ )
V_66 [ V_179 ] [ V_21 ] = F_134 ( V_123 , V_20 + 1 + V_21 ) . V_129 ;
V_184 [ V_179 ] = V_13 ;
V_186 [ V_179 ] = V_130 ;
F_135 ( V_123 , V_20 ) = 0 ;
F_135 ( V_123 , V_20 + 1 ) = 0 ;
V_179 ++ ;
}
V_123 -> V_119 = V_20 & ( V_121 - 1 ) ;
F_136 ( & V_123 -> V_104 , V_28 ) ;
F_137 ( V_6 -> V_165 ) ;
for ( V_20 = 0 ; V_20 < V_179 ; V_20 ++ )
F_37 ( V_6 , V_186 [ V_20 ] , V_184 [ V_20 ] , V_66 [ V_20 ] ) ;
V_183 += V_179 ;
if ( V_179 == V_181 )
goto V_187;
return V_183 ;
}
static T_6 F_138 ( int V_191 , void * V_54 )
{
const struct V_8 * V_192 = V_54 ;
struct V_5 * V_6 = V_192 -> V_6 ;
const struct V_146 * V_77 = & V_192 -> V_77 ;
unsigned int V_3 ;
if ( ! ( * V_77 -> V_138 & V_193 ) )
return V_194 ;
V_3 = 0 ;
if ( * V_77 -> V_138 & V_195 )
V_3 |= V_196 ;
if ( * V_77 -> V_138 & V_156 )
V_3 |= V_197 ;
F_139 ( & V_6 -> V_198 ) ;
F_4 ( F_108 ( V_77 -> V_75 ) , V_3 ) ;
return V_199 ;
}
static void F_140 ( unsigned long V_54 )
{
struct V_10 * V_123 = (struct V_10 * ) V_54 ;
struct V_5 * V_6 = V_123 -> V_6 ;
F_132 ( V_123 ) ;
F_141 ( & V_123 -> V_200 , V_201 + V_202 ) ;
F_109 ( V_6 ) ;
}
static T_6 F_142 ( int V_191 , void * V_54 )
{
struct V_10 * V_123 = V_54 ;
const struct V_146 * V_77 = & V_123 -> V_77 ;
struct V_5 * V_6 = V_123 -> V_6 ;
unsigned int V_3 ;
if ( ! ( * V_77 -> V_138 & V_193 ) )
return V_194 ;
V_3 = 0 ;
if ( * V_77 -> V_138 & V_195 )
V_3 |= V_203 ;
if ( * V_77 -> V_138 & V_156 )
V_3 |= V_204 ;
F_141 ( & V_123 -> V_200 , V_201 + ( V_202 ) * 2 ) ;
F_139 ( & V_6 -> V_198 ) ;
if ( V_3 )
F_4 ( F_111 ( V_77 -> V_75 ) , V_3 ) ;
return V_199 ;
}
static void F_143 ( struct V_40 * V_36 )
{
struct V_5 * V_6 = F_27 ( V_36 ) ;
int V_205 ;
unsigned int V_28 ;
unsigned int V_206 ;
if ( ! V_6 -> V_207 -> V_208 ) {
if ( V_6 -> V_208 && F_144 ( V_6 ) )
F_116 ( V_209 L_15 , V_36 -> V_210 ) ;
F_145 ( V_36 ) ;
F_19 ( V_6 ) ;
V_6 -> V_208 = 0 ;
return;
} else {
F_20 ( V_6 ) ;
F_146 ( V_36 ) ;
}
V_28 = F_6 ( V_6 , V_29 ) ;
V_206 = V_28 & ~ ( V_211 | V_212 |
V_213 ) ;
if ( ! V_6 -> V_207 -> V_214 )
V_206 |= V_211 ;
switch ( V_6 -> V_207 -> V_215 ) {
case 1000 :
V_206 |= V_216 |
V_217 ;
break;
case 100 :
V_206 |= V_218 |
V_219 ;
break;
case 10 :
V_206 |= V_220 |
V_221 ;
break;
default:
F_116 ( L_16 , V_6 -> V_207 -> V_215 ) ;
}
V_205 = V_6 -> V_208 != V_6 -> V_207 -> V_208 || V_28 != V_206 ;
V_6 -> V_214 = V_6 -> V_207 -> V_214 ;
V_6 -> V_215 = V_6 -> V_207 -> V_215 ;
V_6 -> V_208 = V_6 -> V_207 -> V_208 ;
if ( V_206 != V_28 )
F_8 ( V_6 , V_29 , V_206 ) ;
if ( V_205 && F_144 ( V_6 ) )
F_116 ( V_209 L_17 ,
V_36 -> V_210 , V_6 -> V_215 , V_6 -> V_214 ? L_18 : L_19 ) ;
}
static int F_147 ( struct V_40 * V_36 )
{
struct V_5 * V_6 = F_27 ( V_36 ) ;
struct V_31 * V_32 , * V_222 ;
struct V_223 * V_207 ;
V_32 = F_22 ( V_6 -> V_16 ) ;
V_222 = F_148 ( V_32 , L_20 , 0 ) ;
F_149 ( V_222 ) ;
V_6 -> V_208 = 0 ;
V_6 -> V_215 = 0 ;
V_6 -> V_214 = - 1 ;
V_207 = F_150 ( V_36 , V_222 , & F_143 , 0 ,
V_224 ) ;
if ( ! V_207 ) {
F_116 ( V_147 L_21 , V_36 -> V_210 ) ;
return - V_225 ;
}
V_6 -> V_207 = V_207 ;
return 0 ;
}
static int F_151 ( struct V_40 * V_36 )
{
struct V_5 * V_6 = F_27 ( V_36 ) ;
unsigned int V_28 ;
int V_20 , V_226 ;
V_28 = V_227 | F_152 ( 3 ) |
F_153 ( 3 ) | F_154 ( 0xf ) |
F_155 ( 8 ) | F_156 ( 12 ) ;
F_8 ( V_6 , V_228 , V_28 ) ;
V_226 = F_67 ( V_36 ) ;
if ( V_226 )
goto V_229;
V_6 -> V_11 = F_86 ( V_36 ) ;
if ( ! V_6 -> V_11 )
goto V_230;
if ( V_36 -> V_231 > 1500 && ! V_6 -> V_101 ) {
F_63 ( V_6 ) ;
if ( ! V_6 -> V_101 )
goto V_230;
}
for ( V_20 = 0 ; V_20 < 32 ; V_20 ++ )
F_8 ( V_6 , F_157 ( V_20 ) , 0 ) ;
F_4 ( V_232 ,
F_158 ( 0x3ff ) ) ;
F_4 ( F_159 ( V_6 -> V_9 -> V_77 . V_75 ) ,
F_160 ( 256 ) ) ;
F_4 ( F_161 ( V_6 -> V_11 -> V_77 . V_75 ) ,
F_162 ( 32 ) ) ;
F_8 ( V_6 , V_233 ,
F_163 ( V_6 -> V_9 -> V_77 . V_75 ) |
F_164 ( V_6 -> V_9 -> V_77 . V_75 ) ) ;
F_12 ( F_114 ( V_6 -> V_7 ) ,
V_234 |
V_235 |
V_236 |
V_237 |
V_238 ) ;
F_59 ( & F_14 ( V_6 ) -> V_77 , V_239 |
V_240 |
V_241 |
V_242 ) ;
F_59 ( & F_15 ( V_6 ) -> V_77 , V_94 |
V_95 |
V_96 |
V_97 ) ;
F_95 ( V_36 , V_105 ) ;
F_12 ( F_130 ( F_14 ( V_6 ) -> V_77 . V_75 ) ,
V_105 >> 1 ) ;
F_106 ( V_6 ) ;
F_109 ( V_6 ) ;
V_28 = V_243 | V_244 | V_245 ;
if ( V_6 -> type == V_246 )
V_28 |= V_217 | V_216 ;
else
V_28 |= V_247 | V_248 ;
F_8 ( V_6 , V_29 , V_28 ) ;
V_226 = F_147 ( V_36 ) ;
if ( V_226 ) {
F_20 ( V_6 ) ;
if ( V_6 -> type == V_246 ) {
F_25 ( & V_6 -> V_16 -> V_36 ,
L_22 , V_226 ) ;
F_25 ( & V_6 -> V_16 -> V_36 ,
L_23 ) ;
}
}
F_165 ( V_36 ) ;
F_166 ( & V_6 -> V_198 ) ;
snprintf ( V_6 -> V_249 , sizeof( V_6 -> V_249 ) , L_24 ,
V_36 -> V_210 ) ;
V_226 = F_167 ( V_6 -> V_11 -> V_77 . V_191 , F_142 , V_250 ,
V_6 -> V_249 , V_6 -> V_11 ) ;
if ( V_226 ) {
F_47 ( & V_6 -> V_16 -> V_36 , L_25 ,
V_6 -> V_11 -> V_77 . V_191 , V_226 ) ;
goto V_251;
}
snprintf ( V_6 -> V_252 , sizeof( V_6 -> V_252 ) , L_26 ,
V_36 -> V_210 ) ;
V_226 = F_167 ( V_6 -> V_9 -> V_77 . V_191 , F_138 , V_250 ,
V_6 -> V_252 , V_6 -> V_9 ) ;
if ( V_226 ) {
F_47 ( & V_6 -> V_16 -> V_36 , L_25 ,
V_6 -> V_9 -> V_77 . V_191 , V_226 ) ;
goto V_253;
}
if ( V_6 -> V_207 )
F_168 ( V_6 -> V_207 ) ;
F_169 ( & V_6 -> V_11 -> V_200 ) ;
V_6 -> V_11 -> V_200 . V_254 = F_140 ;
V_6 -> V_11 -> V_200 . V_54 = ( unsigned long ) V_6 -> V_11 ;
V_6 -> V_11 -> V_200 . V_255 = V_201 + V_256 ;
F_170 ( & V_6 -> V_11 -> V_200 ) ;
return 0 ;
V_253:
F_171 ( V_6 -> V_11 -> V_77 . V_191 , V_6 -> V_11 ) ;
V_251:
F_172 ( & V_6 -> V_198 ) ;
F_173 ( V_36 ) ;
V_230:
if ( V_6 -> V_11 )
F_88 ( V_6 ) ;
F_93 ( V_6 ) ;
V_229:
return V_226 ;
}
static void F_174 ( struct V_5 * V_6 )
{
unsigned int V_257 , V_258 ;
int V_259 = F_15 ( V_6 ) -> V_77 . V_75 ;
F_12 ( F_119 ( V_259 ) ,
V_260 ) ;
for ( V_258 = 0 ; V_258 < V_261 ; V_258 ++ ) {
V_257 = F_10 ( F_119 ( V_259 ) ) ;
if ( ! ( V_257 & V_262 ) )
break;
F_175 () ;
}
if ( V_257 & V_262 )
F_47 ( & V_6 -> V_68 -> V_36 ,
L_27 , V_257 ) ;
F_12 ( F_119 ( V_259 ) , 0 ) ;
}
static void F_176 ( struct V_5 * V_6 )
{
unsigned int V_257 , V_258 ;
int V_263 = F_14 ( V_6 ) -> V_77 . V_75 ;
F_12 ( F_115 ( V_263 ) ,
V_264 ) ;
for ( V_258 = 0 ; V_258 < V_261 ; V_258 ++ ) {
V_257 = F_10 ( F_115 ( V_263 ) ) ;
if ( ! ( V_257 & V_265 ) )
break;
F_175 () ;
}
if ( V_257 & V_265 )
F_47 ( & V_6 -> V_68 -> V_36 ,
L_28 , V_257 ) ;
F_12 ( F_115 ( V_263 ) , 0 ) ;
}
static void F_177 ( struct V_5 * V_6 )
{
unsigned int V_257 , V_258 ;
F_12 ( F_114 ( V_6 -> V_7 ) ,
V_266 ) ;
for ( V_258 = 0 ; V_258 < V_261 ; V_258 ++ ) {
V_257 = F_10 ( F_114 ( V_6 -> V_7 ) ) ;
if ( ! ( V_257 & V_267 ) )
break;
F_175 () ;
}
if ( V_257 & V_267 )
F_47 ( & V_6 -> V_68 -> V_36 ,
L_29 , V_257 ) ;
F_12 ( F_114 ( V_6 -> V_7 ) , 0 ) ;
}
static int F_178 ( struct V_40 * V_36 )
{
struct V_5 * V_6 = F_27 ( V_36 ) ;
unsigned int V_257 ;
int V_263 , V_259 , V_20 ;
V_263 = F_14 ( V_6 ) -> V_77 . V_75 ;
V_259 = F_15 ( V_6 ) -> V_77 . V_75 ;
if ( V_6 -> V_207 ) {
F_179 ( V_6 -> V_207 ) ;
F_180 ( V_6 -> V_207 ) ;
}
F_181 ( & V_6 -> V_11 -> V_200 ) ;
F_173 ( V_36 ) ;
F_172 ( & V_6 -> V_198 ) ;
V_257 = F_10 ( F_114 ( V_6 -> V_7 ) ) ;
if ( V_257 & ( V_236 |
V_237 |
V_238 ) )
F_116 ( V_268 L_30 , V_257 ) ;
V_257 = F_10 ( F_115 ( V_263 ) ) ;
if ( V_257 & ( V_239 |
V_240 |
V_241 |
V_242 ) )
F_116 ( V_268 L_31 , V_257 ) ;
V_257 = F_10 ( F_119 ( V_259 ) ) ;
if ( V_257 & ( V_94 | V_95 |
V_96 | V_97 ) )
F_116 ( V_268 L_32 , V_257 ) ;
F_132 ( F_15 ( V_6 ) ) ;
F_120 ( F_14 ( V_6 ) , V_105 ) ;
F_174 ( V_6 ) ;
F_177 ( V_6 ) ;
F_176 ( V_6 ) ;
F_19 ( V_6 ) ;
F_171 ( V_6 -> V_11 -> V_77 . V_191 , V_6 -> V_11 ) ;
F_171 ( V_6 -> V_9 -> V_77 . V_191 , V_6 -> V_9 ) ;
for ( V_20 = 0 ; V_20 < V_6 -> V_101 ; V_20 ++ ) {
F_64 ( V_6 -> V_98 [ V_20 ] ) ;
V_6 -> V_98 [ V_20 ] = NULL ;
}
V_6 -> V_101 = 0 ;
F_93 ( V_6 ) ;
F_88 ( V_6 ) ;
return 0 ;
}
static void F_182 ( const struct V_12 * V_13 ,
const T_4 * V_269 ,
const unsigned int * V_270 ,
struct V_10 * V_123 ,
struct V_72 * V_102 )
{
T_3 V_271 ;
T_4 V_272 ;
const int V_273 = F_183 ( V_13 ) ;
const int V_274 = F_184 ( V_13 ) ;
const int V_65 = F_40 ( V_13 ) -> V_130 ;
int V_275 , V_20 , V_132 , V_276 , V_277 , V_278 ;
T_4 V_279 ;
V_271 = V_280 | V_281 |
V_282 | F_185 ( V_102 -> V_86 ) |
V_283 | F_186 ( V_13 -> V_33 - V_273 ) |
F_187 ( V_274 >> 2 ) | V_284 ;
switch ( F_31 ( V_13 ) -> V_60 ) {
case V_61 :
V_271 |= V_285 ;
V_272 = V_269 [ 0 ] + F_188 ( V_13 ) + 16 ;
break;
case V_286 :
V_271 |= V_287 ;
V_272 = V_269 [ 0 ] + F_188 ( V_13 ) + 6 ;
break;
default:
F_189 () ;
}
V_132 = V_102 -> V_81 ;
V_276 = V_132 ;
F_190 ( V_102 , V_132 ++ ) = V_271 ;
V_279 = V_102 -> V_77 . V_83 + ( V_132 & ( V_80 - 1 ) ) * 8 + 2 ;
F_190 ( V_102 , V_132 ++ ) = 0 ;
F_190 ( V_102 , V_132 ) = F_191 ( V_270 [ 0 ] - V_273 ) | F_192 ( V_269 [ 0 ] + V_273 ) ;
for ( V_20 = 1 ; V_20 <= V_65 ; V_20 ++ )
F_190 ( V_102 , V_132 + V_20 ) = F_191 ( V_270 [ V_20 ] ) | F_192 ( V_269 [ V_20 ] ) ;
V_132 += V_20 ;
if ( V_132 & 1 )
V_132 ++ ;
V_277 = V_132 ;
F_190 ( V_102 , V_132 ++ ) = V_282 | F_185 ( V_102 -> V_86 ) |
F_186 ( 2 ) | V_284 ;
F_190 ( V_102 , V_132 ++ ) = F_191 ( 2 ) | F_192 ( V_272 ) | V_288 ;
F_190 ( V_102 , V_132 ++ ) = F_191 ( 2 ) | F_192 ( V_279 ) ;
V_132 ++ ;
V_278 = ! V_102 -> V_289 ;
V_102 -> V_289 = V_278 ;
F_190 ( V_102 , V_132 ++ ) = V_290 | V_291 | V_292 |
V_293 | F_193 ( V_102 -> V_84 [ V_278 ] ) ;
F_190 ( V_102 , V_132 ++ ) = 0 ;
F_190 ( V_102 , V_132 ++ ) = V_290 | V_291 | V_292 |
V_294 | F_193 ( V_102 -> V_84 [ ! V_278 ] ) ;
F_190 ( V_102 , V_132 ++ ) = 0 ;
V_102 -> V_81 = V_132 & ( V_80 - 1 ) ;
V_275 = V_132 - V_276 ;
F_12 ( F_194 ( V_102 -> V_77 . V_75 ) , ( V_275 ) >> 1 ) ;
V_132 = V_123 -> V_81 ;
F_135 ( V_123 , V_132 ++ ) = V_290 | V_291 | V_292 |
V_295 | F_193 ( V_102 -> V_84 [ V_278 ] ) ;
F_135 ( V_123 , V_132 ++ ) = 0 ;
F_135 ( V_123 , V_132 ++ ) = V_290 | V_291 | V_292 |
V_296 | F_193 ( V_102 -> V_84 [ ! V_278 ] ) ;
F_135 ( V_123 , V_132 ++ ) = 0 ;
V_123 -> V_81 = V_132 ;
F_12 ( F_194 ( V_123 -> V_77 . V_75 ) , 2 ) ;
}
static int F_195 ( struct V_12 * V_13 , struct V_40 * V_36 )
{
struct V_5 * const V_6 = F_27 ( V_36 ) ;
struct V_10 * const V_123 = F_15 ( V_6 ) ;
struct V_72 * V_102 ;
T_3 V_297 = 0 ;
T_3 V_148 ;
T_4 V_269 [ V_125 + 1 ] ;
unsigned int V_270 [ V_125 + 1 ] ;
unsigned long V_28 ;
int V_20 , V_65 ;
int V_132 ;
const int V_273 = F_183 ( V_13 ) ;
const int V_274 = F_184 ( V_13 ) ;
F_17 ( & V_123 -> V_106 ) ;
V_297 = V_190 | V_298 | V_299 ;
V_65 = F_40 ( V_13 ) -> V_130 ;
V_269 [ 0 ] = F_100 ( V_6 -> V_68 , V_13 -> V_54 , F_39 ( V_13 ) ,
V_69 ) ;
V_270 [ 0 ] = F_39 ( V_13 ) ;
if ( F_101 ( V_6 -> V_68 , V_269 [ 0 ] ) )
goto V_300;
for ( V_20 = 0 ; V_20 < V_65 ; V_20 ++ ) {
T_5 * V_70 = & F_40 ( V_13 ) -> V_71 [ V_20 ] ;
V_269 [ V_20 + 1 ] = F_196 ( & V_6 -> V_68 -> V_36 , V_70 , 0 ,
F_42 ( V_70 ) , V_301 ) ;
V_270 [ V_20 + 1 ] = F_42 ( V_70 ) ;
if ( F_197 ( & V_6 -> V_68 -> V_36 , V_269 [ V_20 + 1 ] ) ) {
V_65 = V_20 ;
goto V_300;
}
}
if ( V_13 -> V_170 == V_302 && V_13 -> V_33 <= 1540 ) {
switch ( F_31 ( V_13 ) -> V_60 ) {
case V_61 :
V_297 |= V_303 ;
V_297 |= F_198 ( V_274 >> 2 ) ;
V_297 |= F_199 ( V_273 ) ;
break;
case V_286 :
V_297 |= V_304 ;
V_297 |= F_198 ( V_274 >> 2 ) ;
V_297 |= F_199 ( V_273 ) ;
break;
default:
F_96 ( 1 ) ;
}
}
V_148 = V_297 | F_200 ( V_13 -> V_33 ) ;
F_133 ( & V_123 -> V_104 , V_28 ) ;
if ( F_201 ( V_123 ) < V_65 + 14 ) {
F_173 ( V_36 ) ;
goto V_305;
}
if ( V_6 -> V_101 && V_13 -> V_170 == V_302 && V_13 -> V_33 > 1540 ) {
V_102 = V_6 -> V_98 [ V_6 -> V_306 ] ;
V_6 -> V_306 = ( V_6 -> V_306 + 1 ) % V_6 -> V_101 ;
F_182 ( V_13 , V_269 , V_270 , V_123 , V_102 ) ;
}
V_132 = V_123 -> V_81 ;
F_135 ( V_123 , V_132 ) = V_148 ;
F_134 ( V_123 , V_132 ) . V_129 = V_65 ;
V_132 ++ ;
F_134 ( V_123 , V_132 ) . V_13 = V_13 ;
for ( V_20 = 0 ; V_20 <= V_65 ; V_20 ++ ) {
F_135 ( V_123 , V_132 + V_20 ) =
F_191 ( V_270 [ V_20 ] ) | F_192 ( V_269 [ V_20 ] ) ;
F_134 ( V_123 , V_132 + V_20 ) . V_129 = V_269 [ V_20 ] ;
}
if ( V_65 & 1 )
V_65 ++ ;
V_123 -> V_81 = ( V_132 + V_65 + 1 ) & ( V_121 - 1 ) ;
V_36 -> V_166 . V_307 ++ ;
V_36 -> V_166 . V_308 += V_13 -> V_33 ;
F_136 ( & V_123 -> V_104 , V_28 ) ;
F_12 ( F_194 ( V_123 -> V_77 . V_75 ) , ( V_65 + 2 ) >> 1 ) ;
return V_309 ;
V_305:
F_136 ( & V_123 -> V_104 , V_28 ) ;
V_300:
while ( V_65 -- )
F_38 ( V_6 -> V_68 , V_269 [ V_65 ] , V_270 [ V_65 ] ,
V_69 ) ;
return V_310 ;
}
static void F_202 ( struct V_40 * V_36 )
{
const struct V_5 * V_6 = F_27 ( V_36 ) ;
unsigned int V_28 ;
V_28 = F_6 ( V_6 , V_29 ) ;
if ( V_36 -> V_28 & V_311 )
V_28 |= V_244 ;
else
V_28 &= ~ V_244 ;
F_8 ( V_6 , V_29 , V_28 ) ;
}
static int F_203 ( struct V_312 * V_198 , int V_313 )
{
struct V_5 * V_6 = F_204 ( V_198 , struct V_5 , V_198 ) ;
int V_314 ;
F_132 ( F_15 ( V_6 ) ) ;
V_314 = F_120 ( F_14 ( V_6 ) , V_313 ) ;
if ( V_314 < V_313 ) {
F_205 ( V_198 ) ;
F_106 ( V_6 ) ;
F_109 ( V_6 ) ;
}
return V_314 ;
}
static void F_206 ( struct V_40 * V_36 )
{
const struct V_5 * V_6 = F_27 ( V_36 ) ;
F_207 ( V_6 -> V_11 -> V_77 . V_191 ) ;
F_142 ( V_6 -> V_11 -> V_77 . V_191 , V_6 -> V_11 ) ;
F_208 ( V_6 -> V_11 -> V_77 . V_191 ) ;
F_207 ( V_6 -> V_9 -> V_77 . V_191 ) ;
F_138 ( V_6 -> V_9 -> V_77 . V_191 , V_6 -> V_9 ) ;
F_208 ( V_6 -> V_9 -> V_77 . V_191 ) ;
}
static int F_209 ( struct V_40 * V_36 , int V_315 )
{
struct V_5 * V_6 = F_27 ( V_36 ) ;
unsigned int V_3 ;
unsigned int V_144 = 0 ;
int V_316 ;
int V_226 = 0 ;
if ( V_315 < V_317 || V_315 > V_318 )
return - V_39 ;
V_316 = F_210 ( V_36 ) ;
if ( V_316 ) {
F_172 ( & V_6 -> V_198 ) ;
F_211 ( V_36 ) ;
F_19 ( V_6 ) ;
V_144 = F_10 ( F_114 ( V_6 -> V_7 ) ) ;
F_177 ( V_6 ) ;
F_120 ( F_14 ( V_6 ) , V_105 ) ;
F_89 ( V_6 ) ;
}
if ( V_315 > 1500 && ! V_6 -> V_101 ) {
F_63 ( V_6 ) ;
if ( ! V_6 -> V_101 ) {
V_226 = - V_120 ;
goto V_319;
}
}
V_3 = F_6 ( V_6 , V_320 ) ;
V_3 &= ~ V_321 ;
V_3 |= F_212 ( V_315 + V_322 + 4 ) ;
F_8 ( V_6 , V_320 , V_3 ) ;
V_36 -> V_231 = V_315 ;
V_6 -> V_135 = V_315 + V_322 + V_323 + V_136 + 128 ;
V_319:
if ( V_316 ) {
F_12 ( F_114 ( V_6 -> V_7 ) ,
V_144 | V_234 ) ;
F_14 ( V_6 ) -> V_81 = 0 ;
F_95 ( V_36 , V_105 - 1 ) ;
F_166 ( & V_6 -> V_198 ) ;
F_165 ( V_36 ) ;
F_20 ( V_6 ) ;
}
return V_226 ;
}
static int T_7
F_213 ( struct V_15 * V_16 , const struct V_324 * V_325 )
{
struct V_40 * V_36 ;
struct V_5 * V_6 ;
int V_326 , V_226 ;
V_326 = F_214 ( V_16 ) ;
if ( V_326 )
return V_326 ;
V_36 = F_215 ( sizeof( struct V_5 ) ) ;
if ( V_36 == NULL ) {
V_326 = - V_120 ;
goto V_327;
}
F_216 ( V_16 , V_36 ) ;
F_217 ( V_36 , & V_16 -> V_36 ) ;
V_6 = F_27 ( V_36 ) ;
V_6 -> V_16 = V_16 ;
V_6 -> V_165 = V_36 ;
F_218 ( V_36 , & V_6 -> V_198 , F_203 , 64 ) ;
V_36 -> V_328 = V_329 | V_330 | V_331 |
V_332 | V_333 ;
V_6 -> V_175 . V_334 = V_335 ;
V_6 -> V_175 . V_336 = V_337 ;
V_6 -> V_175 . V_338 = V_6 -> V_339 ;
V_6 -> V_175 . V_340 = F_29 ;
V_6 -> V_175 . V_328 = V_341 | V_342 ;
V_6 -> V_175 . V_36 = V_6 -> V_165 ;
V_6 -> V_175 . V_170 = V_171 ;
V_6 -> V_175 . V_343 = V_171 ;
V_6 -> V_68 = F_219 ( V_344 , 0xa007 , NULL ) ;
if ( ! V_6 -> V_68 ) {
F_47 ( & V_6 -> V_16 -> V_36 , L_33 ) ;
V_326 = - V_225 ;
goto V_319;
}
V_6 -> V_345 = F_219 ( V_344 , 0xa001 , NULL ) ;
if ( ! V_6 -> V_345 ) {
F_47 ( & V_6 -> V_16 -> V_36 , L_34 ) ;
V_326 = - V_225 ;
goto V_319;
}
if ( F_21 ( V_6 ) || ! F_28 ( V_6 -> V_38 ) ) {
V_326 = - V_225 ;
goto V_319;
}
memcpy ( V_36 -> V_47 , V_6 -> V_38 , sizeof( V_6 -> V_38 ) ) ;
V_226 = F_18 ( V_6 ) ;
if ( V_226 < 0 ) {
F_47 ( & V_6 -> V_16 -> V_36 , L_35 ) ;
V_326 = - V_225 ;
goto V_319;
}
V_6 -> V_7 = V_226 ;
switch ( V_16 -> V_346 ) {
case 0xa005 :
V_6 -> type = V_246 ;
break;
case 0xa006 :
V_6 -> type = V_99 ;
break;
default:
V_326 = - V_225 ;
goto V_319;
}
V_36 -> V_347 = & V_348 ;
V_36 -> V_231 = V_349 ;
V_6 -> V_135 = V_36 -> V_231 + V_322 + V_323 + V_136 + 128 ;
V_36 -> V_350 = & V_351 ;
if ( V_326 )
goto V_319;
V_6 -> V_352 = F_220 ( V_353 , V_354 ) ;
V_6 -> V_352 = ( V_355 << 1 ) - 1 ;
V_326 = F_221 ( V_36 ) ;
if ( V_326 ) {
F_47 ( & V_6 -> V_16 -> V_36 , L_36 ,
V_326 ) ;
goto V_319;
} else if netif_msg_probe( V_6 )
F_116 ( V_209 L_37 ,
V_36 -> V_210 , V_6 -> type == V_246 ? L_38 : L_39 ,
V_6 -> V_7 , V_36 -> V_47 ) ;
return V_326 ;
V_319:
if ( V_6 -> V_345 )
F_222 ( V_6 -> V_345 ) ;
if ( V_6 -> V_68 )
F_222 ( V_6 -> V_68 ) ;
F_223 ( V_36 ) ;
V_327:
F_224 ( V_16 ) ;
return V_326 ;
}
static void T_8 F_225 ( struct V_15 * V_16 )
{
struct V_40 * V_165 = F_226 ( V_16 ) ;
struct V_5 * V_6 ;
if ( ! V_165 )
return;
V_6 = F_27 ( V_165 ) ;
F_227 ( V_165 ) ;
F_224 ( V_16 ) ;
F_222 ( V_6 -> V_68 ) ;
F_222 ( V_6 -> V_345 ) ;
F_62 ( & V_6 -> V_11 -> V_77 ) ;
F_62 ( & V_6 -> V_9 -> V_77 ) ;
F_216 ( V_16 , NULL ) ;
F_223 ( V_165 ) ;
}
static void T_9 F_228 ( void )
{
F_229 ( & V_356 ) ;
}
int F_230 ( void )
{
int V_326 ;
V_326 = F_231 () ;
if ( V_326 )
return V_326 ;
return F_232 ( & V_356 ) ;
}
