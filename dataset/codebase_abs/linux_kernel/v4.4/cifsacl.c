static int
F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
char * V_4 ;
if ( V_3 -> V_5 <= sizeof( V_1 -> V_4 ) ) {
V_1 -> V_4 . V_6 [ 0 ] = NULL ;
memcpy ( & V_1 -> V_4 , V_3 -> V_6 , V_3 -> V_5 ) ;
} else {
V_4 = F_2 ( V_3 -> V_6 , V_3 -> V_5 , V_7 ) ;
if ( ! V_4 )
return - V_8 ;
V_1 -> V_4 . V_6 [ 0 ] = V_4 ;
}
V_1 -> V_5 = V_3 -> V_5 ;
return 0 ;
}
static inline void
F_3 ( struct V_1 * V_1 )
{
if ( V_1 -> V_5 > sizeof( V_1 -> V_4 ) )
F_4 ( V_1 -> V_4 . V_6 [ 0 ] ) ;
}
static char *
F_5 ( struct V_9 * V_10 , unsigned int type )
{
int V_11 , V_12 ;
unsigned int V_13 ;
char * V_14 , * V_15 ;
unsigned long long V_16 ;
V_14 = F_6 ( 3 + V_17 +
( V_18 * V_10 -> V_19 ) ,
V_7 ) ;
if ( ! V_14 )
return V_14 ;
V_15 = V_14 ;
V_12 = sprintf ( V_15 , L_1 , type == V_20 ? 'o' : 'g' ,
V_10 -> V_21 ) ;
V_15 += V_12 ;
V_16 = ( unsigned long long ) V_10 -> V_22 [ 5 ] ;
V_16 |= ( unsigned long long ) V_10 -> V_22 [ 4 ] << 8 ;
V_16 |= ( unsigned long long ) V_10 -> V_22 [ 3 ] << 16 ;
V_16 |= ( unsigned long long ) V_10 -> V_22 [ 2 ] << 24 ;
V_16 |= ( unsigned long long ) V_10 -> V_22 [ 1 ] << 32 ;
V_16 |= ( unsigned long long ) V_10 -> V_22 [ 0 ] << 48 ;
if ( V_16 <= V_23 )
V_12 = sprintf ( V_15 , L_2 , V_16 ) ;
else
V_12 = sprintf ( V_15 , L_3 , V_16 ) ;
V_15 += V_12 ;
for ( V_11 = 0 ; V_11 < V_10 -> V_19 ; ++ V_11 ) {
V_13 = F_7 ( V_10 -> V_24 [ V_11 ] ) ;
V_12 = sprintf ( V_15 , L_4 , V_13 ) ;
V_15 += V_12 ;
}
return V_14 ;
}
static int
F_8 ( const struct V_9 * V_25 , const struct V_9 * V_26 )
{
int V_11 ;
int V_19 , V_27 , V_28 ;
if ( ( ! V_25 ) || ( ! V_26 ) )
return 1 ;
if ( V_25 -> V_21 != V_26 -> V_21 ) {
if ( V_25 -> V_21 > V_26 -> V_21 )
return 1 ;
else
return - 1 ;
}
for ( V_11 = 0 ; V_11 < V_29 ; ++ V_11 ) {
if ( V_25 -> V_22 [ V_11 ] != V_26 -> V_22 [ V_11 ] ) {
if ( V_25 -> V_22 [ V_11 ] > V_26 -> V_22 [ V_11 ] )
return 1 ;
else
return - 1 ;
}
}
V_27 = V_25 -> V_19 ;
V_28 = V_26 -> V_19 ;
V_19 = V_27 < V_28 ? V_27 : V_28 ;
if ( V_19 ) {
for ( V_11 = 0 ; V_11 < V_19 ; ++ V_11 ) {
if ( V_25 -> V_24 [ V_11 ] != V_26 -> V_24 [ V_11 ] ) {
if ( F_7 ( V_25 -> V_24 [ V_11 ] ) >
F_7 ( V_26 -> V_24 [ V_11 ] ) )
return 1 ;
else
return - 1 ;
}
}
}
return 0 ;
}
static void
F_9 ( struct V_9 * V_30 , const struct V_9 * V_31 )
{
int V_11 ;
V_30 -> V_21 = V_31 -> V_21 ;
V_30 -> V_19 = F_10 ( V_32 , V_31 -> V_19 , V_33 ) ;
for ( V_11 = 0 ; V_11 < V_29 ; ++ V_11 )
V_30 -> V_22 [ V_11 ] = V_31 -> V_22 [ V_11 ] ;
for ( V_11 = 0 ; V_11 < V_30 -> V_19 ; ++ V_11 )
V_30 -> V_24 [ V_11 ] = V_31 -> V_24 [ V_11 ] ;
}
static int
F_11 ( unsigned int V_34 , T_1 V_35 , struct V_9 * V_36 )
{
int V_37 ;
struct V_1 * V_38 ;
struct V_9 * V_39 ;
unsigned int V_40 ;
char V_41 [ 3 + 10 + 1 ] ;
const struct V_42 * V_43 ;
V_37 = snprintf ( V_41 , sizeof( V_41 ) , L_5 ,
V_35 == V_20 ? 'o' : 'g' , V_34 ) ;
if ( V_37 >= sizeof( V_41 ) )
return - V_44 ;
V_37 = 0 ;
V_43 = F_12 ( V_45 ) ;
V_38 = F_13 ( & V_46 , V_41 , L_6 ) ;
if ( F_14 ( V_38 ) ) {
V_37 = - V_44 ;
F_15 ( V_47 , L_7 ,
V_48 , V_35 == V_20 ? 'u' : 'g' , V_34 ) ;
goto V_49;
} else if ( V_38 -> V_5 < V_50 ) {
V_37 = - V_51 ;
F_15 ( V_47 , L_8 ,
V_48 , V_38 -> V_5 ) ;
goto V_52;
}
V_39 = V_38 -> V_5 <= sizeof( V_38 -> V_4 ) ?
(struct V_9 * ) & V_38 -> V_4 :
(struct V_9 * ) V_38 -> V_4 . V_6 [ 0 ] ;
V_40 = V_50 + ( V_39 -> V_19 * sizeof( V_53 ) ) ;
if ( V_40 > V_38 -> V_5 ) {
V_37 = - V_51 ;
F_15 ( V_47 , L_9 ,
V_48 , V_38 -> V_5 , V_40 ) ;
goto V_52;
}
F_9 ( V_36 , V_39 ) ;
V_54:
F_16 ( V_38 ) ;
V_49:
F_17 ( V_43 ) ;
return V_37 ;
V_52:
F_18 ( V_38 ) ;
goto V_54;
}
static int
F_19 ( struct V_55 * V_56 , struct V_9 * V_57 ,
struct V_58 * V_59 , T_1 V_35 )
{
int V_37 ;
struct V_1 * V_38 ;
char * V_14 ;
const struct V_42 * V_43 ;
T_2 V_60 = V_56 -> V_61 ;
T_3 V_62 = V_56 -> V_63 ;
if ( F_20 ( V_57 -> V_19 > V_33 ) ) {
F_15 ( V_47 , L_10 ,
V_48 , V_57 -> V_19 ) ;
return - V_51 ;
}
V_14 = F_5 ( V_57 , V_35 ) ;
if ( ! V_14 )
return - V_8 ;
V_43 = F_12 ( V_45 ) ;
V_38 = F_13 ( & V_46 , V_14 , L_6 ) ;
if ( F_14 ( V_38 ) ) {
V_37 = - V_44 ;
F_15 ( V_47 , L_11 ,
V_48 , V_14 , V_35 == V_20 ? 'u' : 'g' ) ;
goto V_49;
}
F_21 ( sizeof( V_64 ) != sizeof( V_65 ) ) ;
if ( V_38 -> V_5 != sizeof( V_64 ) ) {
V_37 = - V_51 ;
F_15 ( V_47 , L_8 ,
V_48 , V_38 -> V_5 ) ;
F_18 ( V_38 ) ;
goto V_54;
}
if ( V_35 == V_20 ) {
T_2 V_66 ;
V_64 V_67 ;
memcpy ( & V_67 , & V_38 -> V_4 . V_6 [ 0 ] , sizeof( V_64 ) ) ;
V_66 = F_22 ( & V_68 , V_67 ) ;
if ( F_23 ( V_66 ) )
V_60 = V_66 ;
} else {
T_3 V_69 ;
V_65 V_67 ;
memcpy ( & V_67 , & V_38 -> V_4 . V_6 [ 0 ] , sizeof( V_65 ) ) ;
V_69 = F_24 ( & V_68 , V_67 ) ;
if ( F_25 ( V_69 ) )
V_62 = V_69 ;
}
V_54:
F_16 ( V_38 ) ;
V_49:
F_17 ( V_43 ) ;
F_4 ( V_14 ) ;
if ( V_35 == V_20 )
V_59 -> V_70 = V_60 ;
else
V_59 -> V_71 = V_62 ;
return 0 ;
}
int
F_26 ( void )
{
struct V_42 * V_42 ;
struct V_1 * V_72 ;
int V_73 ;
F_15 ( V_47 , L_12 ,
V_46 . V_74 ) ;
V_42 = F_27 ( NULL ) ;
if ( ! V_42 )
return - V_8 ;
V_72 = F_28 ( L_13 ,
V_75 , V_76 , V_42 ,
( V_77 & ~ V_78 ) |
V_79 | V_80 ,
V_81 , NULL ) ;
if ( F_14 ( V_72 ) ) {
V_73 = F_29 ( V_72 ) ;
goto V_82;
}
V_73 = F_30 ( & V_46 ) ;
if ( V_73 < 0 )
goto V_83;
F_31 ( V_84 , & V_72 -> V_85 ) ;
V_42 -> V_86 = V_72 ;
V_42 -> V_87 = V_88 ;
V_45 = V_42 ;
F_15 ( V_47 , L_14 , F_32 ( V_72 ) ) ;
return 0 ;
V_83:
F_16 ( V_72 ) ;
V_82:
F_33 ( V_42 ) ;
return V_73 ;
}
void
F_34 ( void )
{
F_35 ( V_45 -> V_86 ) ;
F_36 ( & V_46 ) ;
F_33 ( V_45 ) ;
F_15 ( V_47 , L_15 , V_46 . V_74 ) ;
}
static void F_37 ( const struct V_89 * V_90 ,
struct V_89 * V_91 , T_4 V_92 )
{
struct V_9 * V_93 , * V_94 ;
struct V_9 * V_95 , * V_96 ;
V_91 -> V_21 = V_90 -> V_21 ;
V_91 -> type = V_90 -> type ;
V_91 -> V_97 = F_38 ( sizeof( struct V_89 ) ) ;
V_91 -> V_98 = 0 ;
V_91 -> V_99 = F_38 ( V_92 ) ;
V_91 -> V_100 = F_38 ( V_92 + sizeof( struct V_9 ) ) ;
V_93 = (struct V_9 * ) ( ( char * ) V_90 +
F_7 ( V_90 -> V_99 ) ) ;
V_95 = (struct V_9 * ) ( ( char * ) V_91 + V_92 ) ;
F_9 ( V_95 , V_93 ) ;
V_94 = (struct V_9 * ) ( ( char * ) V_90 +
F_7 ( V_90 -> V_100 ) ) ;
V_96 = (struct V_9 * ) ( ( char * ) V_91 + V_92 +
sizeof( struct V_9 ) ) ;
F_9 ( V_96 , V_94 ) ;
return;
}
static void F_39 ( V_53 V_101 , int type , T_5 * V_102 ,
T_5 * V_103 )
{
T_4 V_85 = F_7 ( V_101 ) ;
if ( type == V_104 ) {
if ( V_85 & V_105 )
* V_103 &= ~ V_106 ;
if ( ( V_85 & V_107 ) ||
( ( V_85 & V_108 ) == V_108 ) )
* V_103 &= ~ V_109 ;
if ( ( V_85 & V_110 ) ||
( ( V_85 & V_111 ) == V_111 ) )
* V_103 &= ~ V_112 ;
if ( ( V_85 & V_113 ) ||
( ( V_85 & V_114 ) == V_114 ) )
* V_103 &= ~ V_115 ;
return;
} else if ( type != V_116 ) {
F_15 ( V_117 , L_16 , type ) ;
return;
}
if ( V_85 & V_105 ) {
* V_102 |= ( V_106 & ( * V_103 ) ) ;
F_15 ( V_118 , L_17 ) ;
return;
}
if ( ( V_85 & V_107 ) ||
( ( V_85 & V_108 ) == V_108 ) )
* V_102 |= ( V_109 & ( * V_103 ) ) ;
if ( ( V_85 & V_110 ) ||
( ( V_85 & V_111 ) == V_111 ) )
* V_102 |= ( V_112 & ( * V_103 ) ) ;
if ( ( V_85 & V_113 ) ||
( ( V_85 & V_114 ) == V_114 ) )
* V_102 |= ( V_115 & ( * V_103 ) ) ;
F_15 ( V_118 , L_18 , V_85 , * V_102 ) ;
return;
}
static void F_40 ( T_5 V_119 , T_5 V_120 ,
T_4 * V_121 )
{
* V_121 = 0x0 ;
V_119 &= V_120 ;
if ( V_119 & V_112 )
* V_121 |= V_122 ;
if ( V_119 & V_109 )
* V_121 |= V_123 ;
if ( V_119 & V_115 )
* V_121 |= V_124 ;
F_15 ( V_118 , L_19 ,
V_119 , * V_121 ) ;
return;
}
static T_6 F_41 ( struct V_125 * V_126 ,
const struct V_9 * V_57 , T_7 V_127 , T_5 V_128 )
{
int V_11 ;
T_6 V_129 = 0 ;
T_4 V_130 = 0 ;
V_126 -> type = V_116 ;
V_126 -> V_85 = 0x0 ;
F_40 ( V_127 , V_128 , & V_130 ) ;
if ( ! V_130 )
V_130 = V_131 ;
V_126 -> V_130 = F_38 ( V_130 ) ;
V_126 -> V_132 . V_21 = V_57 -> V_21 ;
V_126 -> V_132 . V_19 = V_57 -> V_19 ;
for ( V_11 = 0 ; V_11 < V_29 ; V_11 ++ )
V_126 -> V_132 . V_22 [ V_11 ] = V_57 -> V_22 [ V_11 ] ;
for ( V_11 = 0 ; V_11 < V_57 -> V_19 ; V_11 ++ )
V_126 -> V_132 . V_24 [ V_11 ] = V_57 -> V_24 [ V_11 ] ;
V_129 = 1 + 1 + 2 + 4 + 1 + 1 + 6 + ( V_57 -> V_19 * 4 ) ;
V_126 -> V_129 = F_42 ( V_129 ) ;
return V_129 ;
}
static void F_43 ( struct V_125 * V_133 , char * V_134 )
{
int V_19 ;
if ( F_44 ( V_133 -> V_129 ) < 16 ) {
F_15 ( V_117 , L_20 , F_44 ( V_133 -> V_129 ) ) ;
return;
}
if ( V_134 < ( char * ) V_133 + F_44 ( V_133 -> V_129 ) ) {
F_15 ( V_117 , L_21 ) ;
return;
}
V_19 = V_133 -> V_132 . V_19 ;
if ( V_19 ) {
int V_11 ;
F_15 ( V_47 , L_22 ,
V_133 -> V_132 . V_21 , V_133 -> V_132 . V_19 , V_133 -> type ,
V_133 -> V_85 , F_44 ( V_133 -> V_129 ) ) ;
for ( V_11 = 0 ; V_11 < V_19 ; ++ V_11 ) {
F_15 ( V_47 , L_23 ,
V_11 , F_7 ( V_133 -> V_132 . V_24 [ V_11 ] ) ) ;
}
}
return;
}
static void F_45 ( struct V_135 * V_136 , char * V_134 ,
struct V_9 * V_137 , struct V_9 * V_138 ,
struct V_58 * V_59 )
{
int V_11 ;
int V_139 = 0 ;
int V_140 ;
char * V_141 ;
struct V_125 * * V_142 ;
if ( ! V_136 ) {
V_59 -> V_143 |= V_106 ;
return;
}
if ( V_134 < ( char * ) V_136 + F_44 ( V_136 -> V_129 ) ) {
F_15 ( V_117 , L_24 ) ;
return;
}
F_15 ( V_118 , L_25 ,
F_44 ( V_136 -> V_21 ) , F_44 ( V_136 -> V_129 ) ,
F_7 ( V_136 -> V_139 ) ) ;
V_59 -> V_143 &= ~ ( V_106 ) ;
V_141 = ( char * ) V_136 ;
V_140 = sizeof( struct V_135 ) ;
V_139 = F_7 ( V_136 -> V_139 ) ;
if ( V_139 > 0 ) {
T_5 V_144 = V_145 ;
T_5 V_146 = V_147 ;
T_5 V_148 = V_145 | V_147 | V_149 ;
if ( V_139 > V_150 / sizeof( struct V_125 * ) )
return;
V_142 = F_6 ( V_139 * sizeof( struct V_125 * ) ,
V_7 ) ;
if ( ! V_142 )
return;
for ( V_11 = 0 ; V_11 < V_139 ; ++ V_11 ) {
V_142 [ V_11 ] = (struct V_125 * ) ( V_141 + V_140 ) ;
#ifdef F_46
F_43 ( V_142 [ V_11 ] , V_134 ) ;
#endif
if ( F_8 ( & ( V_142 [ V_11 ] -> V_132 ) , V_137 ) == 0 )
F_39 ( V_142 [ V_11 ] -> V_130 ,
V_142 [ V_11 ] -> type ,
& V_59 -> V_143 ,
& V_144 ) ;
if ( F_8 ( & ( V_142 [ V_11 ] -> V_132 ) , V_138 ) == 0 )
F_39 ( V_142 [ V_11 ] -> V_130 ,
V_142 [ V_11 ] -> type ,
& V_59 -> V_143 ,
& V_146 ) ;
if ( F_8 ( & ( V_142 [ V_11 ] -> V_132 ) , & V_151 ) == 0 )
F_39 ( V_142 [ V_11 ] -> V_130 ,
V_142 [ V_11 ] -> type ,
& V_59 -> V_143 ,
& V_148 ) ;
if ( F_8 ( & ( V_142 [ V_11 ] -> V_132 ) , & V_152 ) == 0 )
F_39 ( V_142 [ V_11 ] -> V_130 ,
V_142 [ V_11 ] -> type ,
& V_59 -> V_143 ,
& V_148 ) ;
V_141 = ( char * ) V_142 [ V_11 ] ;
V_140 = F_44 ( V_142 [ V_11 ] -> V_129 ) ;
}
F_4 ( V_142 ) ;
}
return;
}
static int F_47 ( struct V_135 * V_153 , struct V_9 * V_137 ,
struct V_9 * V_138 , T_7 V_127 )
{
T_8 V_129 = 0 ;
struct V_135 * V_154 ;
V_154 = (struct V_135 * ) ( ( char * ) V_153 + sizeof( struct V_135 ) ) ;
V_129 += F_41 ( (struct V_125 * ) ( ( char * ) V_154 + V_129 ) ,
V_137 , V_127 , V_145 ) ;
V_129 += F_41 ( (struct V_125 * ) ( ( char * ) V_154 + V_129 ) ,
V_138 , V_127 , V_147 ) ;
V_129 += F_41 ( (struct V_125 * ) ( ( char * ) V_154 + V_129 ) ,
& V_151 , V_127 , V_149 ) ;
V_153 -> V_129 = F_42 ( V_129 + sizeof( struct V_135 ) ) ;
V_153 -> V_139 = F_38 ( 3 ) ;
return 0 ;
}
static int F_48 ( struct V_9 * V_57 , char * V_134 )
{
if ( V_134 < ( char * ) V_57 + 8 ) {
F_15 ( V_117 , L_26 , V_57 ) ;
return - V_44 ;
}
#ifdef F_46
if ( V_57 -> V_19 ) {
int V_11 ;
F_15 ( V_47 , L_27 ,
V_57 -> V_21 , V_57 -> V_19 ) ;
for ( V_11 = 0 ; V_11 < V_57 -> V_19 ; V_11 ++ ) {
F_15 ( V_47 , L_28 ,
V_11 , F_7 ( V_57 -> V_24 [ V_11 ] ) ) ;
}
F_15 ( V_47 , L_29 ,
F_7 ( V_57 -> V_24 [ V_57 -> V_19 - 1 ] ) ) ;
}
#endif
return 0 ;
}
static int F_49 ( struct V_55 * V_56 ,
struct V_89 * V_90 , int V_155 , struct V_58 * V_59 )
{
int V_37 = 0 ;
struct V_9 * V_93 , * V_94 ;
struct V_135 * V_156 ;
char * V_134 = ( ( char * ) V_90 ) + V_155 ;
T_4 V_97 ;
if ( V_90 == NULL )
return - V_51 ;
V_93 = (struct V_9 * ) ( ( char * ) V_90 +
F_7 ( V_90 -> V_99 ) ) ;
V_94 = (struct V_9 * ) ( ( char * ) V_90 +
F_7 ( V_90 -> V_100 ) ) ;
V_97 = F_7 ( V_90 -> V_97 ) ;
V_156 = (struct V_135 * ) ( ( char * ) V_90 + V_97 ) ;
F_15 ( V_118 , L_30 ,
V_90 -> V_21 , V_90 -> type , F_7 ( V_90 -> V_99 ) ,
F_7 ( V_90 -> V_100 ) ,
F_7 ( V_90 -> V_98 ) , V_97 ) ;
V_37 = F_48 ( V_93 , V_134 ) ;
if ( V_37 ) {
F_15 ( V_47 , L_31 , V_48 , V_37 ) ;
return V_37 ;
}
V_37 = F_19 ( V_56 , V_93 , V_59 , V_20 ) ;
if ( V_37 ) {
F_15 ( V_47 , L_32 ,
V_48 , V_37 ) ;
return V_37 ;
}
V_37 = F_48 ( V_94 , V_134 ) ;
if ( V_37 ) {
F_15 ( V_47 , L_33 ,
V_48 , V_37 ) ;
return V_37 ;
}
V_37 = F_19 ( V_56 , V_94 , V_59 , V_157 ) ;
if ( V_37 ) {
F_15 ( V_47 , L_34 ,
V_48 , V_37 ) ;
return V_37 ;
}
if ( V_97 )
F_45 ( V_156 , V_134 , V_93 ,
V_94 , V_59 ) ;
else
F_15 ( V_47 , L_35 ) ;
return V_37 ;
}
static int F_50 ( struct V_89 * V_90 , struct V_89 * V_91 ,
T_4 V_158 , T_7 V_127 , T_2 V_66 , T_3 V_69 , int * V_159 )
{
int V_37 = 0 ;
T_4 V_97 ;
T_4 V_160 ;
T_4 V_92 ;
struct V_9 * V_93 , * V_94 ;
struct V_9 * V_95 , * V_96 ;
struct V_135 * V_156 = NULL ;
struct V_135 * V_161 = NULL ;
if ( V_127 != V_162 ) {
V_93 = (struct V_9 * ) ( ( char * ) V_90 +
F_7 ( V_90 -> V_99 ) ) ;
V_94 = (struct V_9 * ) ( ( char * ) V_90 +
F_7 ( V_90 -> V_100 ) ) ;
V_97 = F_7 ( V_90 -> V_97 ) ;
V_156 = (struct V_135 * ) ( ( char * ) V_90 + V_97 ) ;
V_160 = sizeof( struct V_89 ) ;
V_161 = (struct V_135 * ) ( ( char * ) V_91 + V_160 ) ;
V_161 -> V_21 = V_156 -> V_21 ;
V_161 -> V_129 = 0 ;
V_161 -> V_139 = 0 ;
V_37 = F_47 ( V_161 , V_93 , V_94 ,
V_127 ) ;
V_92 = V_160 + F_44 ( V_161 -> V_129 ) ;
F_37 ( V_90 , V_91 , V_92 ) ;
* V_159 = V_163 ;
} else {
memcpy ( V_91 , V_90 , V_158 ) ;
if ( F_23 ( V_66 ) ) {
V_64 V_67 ;
V_93 = (struct V_9 * ) ( ( char * ) V_91 +
F_7 ( V_91 -> V_99 ) ) ;
V_95 = F_6 ( sizeof( struct V_9 ) ,
V_7 ) ;
if ( ! V_95 )
return - V_8 ;
V_67 = F_51 ( & V_68 , V_66 ) ;
V_37 = F_11 ( V_67 , V_20 , V_95 ) ;
if ( V_37 ) {
F_15 ( V_47 , L_36 ,
V_48 , V_37 , V_67 ) ;
F_4 ( V_95 ) ;
return V_37 ;
}
F_9 ( V_93 , V_95 ) ;
F_4 ( V_95 ) ;
* V_159 = V_164 ;
}
if ( F_25 ( V_69 ) ) {
V_65 V_67 ;
V_94 = (struct V_9 * ) ( ( char * ) V_91 +
F_7 ( V_91 -> V_100 ) ) ;
V_96 = F_6 ( sizeof( struct V_9 ) ,
V_7 ) ;
if ( ! V_96 )
return - V_8 ;
V_67 = F_52 ( & V_68 , V_69 ) ;
V_37 = F_11 ( V_67 , V_157 , V_96 ) ;
if ( V_37 ) {
F_15 ( V_47 , L_37 ,
V_48 , V_37 , V_67 ) ;
F_4 ( V_96 ) ;
return V_37 ;
}
F_9 ( V_94 , V_96 ) ;
F_4 ( V_96 ) ;
* V_159 = V_165 ;
}
}
return V_37 ;
}
struct V_89 * F_53 ( struct V_55 * V_56 ,
const struct V_166 * V_167 , T_9 * V_168 )
{
struct V_89 * V_90 = NULL ;
unsigned int V_169 ;
int V_37 ;
struct V_170 * V_171 = F_54 ( V_56 ) ;
if ( F_14 ( V_171 ) )
return F_55 ( V_171 ) ;
V_169 = F_56 () ;
V_37 = F_57 ( V_169 , F_58 ( V_171 ) , V_167 -> V_172 , & V_90 ,
V_168 ) ;
F_59 ( V_169 ) ;
F_60 ( V_171 ) ;
F_15 ( V_47 , L_38 , V_48 , V_37 , * V_168 ) ;
if ( V_37 )
return F_61 ( V_37 ) ;
return V_90 ;
}
static struct V_89 * F_62 ( struct V_55 * V_56 ,
const char * V_173 , T_9 * V_168 )
{
struct V_89 * V_90 = NULL ;
int V_174 = 0 ;
unsigned int V_169 ;
int V_37 , V_175 = 0 ;
struct V_176 * V_177 ;
struct V_170 * V_171 = F_54 ( V_56 ) ;
struct V_166 V_178 ;
struct V_179 V_180 ;
if ( F_14 ( V_171 ) )
return F_55 ( V_171 ) ;
V_177 = F_58 ( V_171 ) ;
V_169 = F_56 () ;
if ( F_63 ( V_56 ) )
V_175 |= V_181 ;
V_180 . V_177 = V_177 ;
V_180 . V_56 = V_56 ;
V_180 . V_182 = V_183 ;
V_180 . V_175 = V_175 ;
V_180 . V_184 = V_185 ;
V_180 . V_173 = V_173 ;
V_180 . V_178 = & V_178 ;
V_180 . V_186 = false ;
V_37 = F_64 ( V_169 , & V_180 , & V_174 , NULL ) ;
if ( ! V_37 ) {
V_37 = F_57 ( V_169 , V_177 , V_178 . V_172 , & V_90 , V_168 ) ;
F_65 ( V_169 , V_177 , V_178 . V_172 ) ;
}
F_60 ( V_171 ) ;
F_59 ( V_169 ) ;
F_15 ( V_47 , L_38 , V_48 , V_37 , * V_168 ) ;
if ( V_37 )
return F_61 ( V_37 ) ;
return V_90 ;
}
struct V_89 * F_66 ( struct V_55 * V_56 ,
struct V_187 * V_187 , const char * V_173 ,
T_9 * V_168 )
{
struct V_89 * V_90 = NULL ;
struct V_188 * V_189 = NULL ;
if ( V_187 )
V_189 = F_67 ( F_68 ( V_187 ) , true ) ;
if ( ! V_189 )
return F_62 ( V_56 , V_173 , V_168 ) ;
V_90 = F_53 ( V_56 , & V_189 -> V_178 , V_168 ) ;
F_69 ( V_189 ) ;
return V_90 ;
}
int F_70 ( struct V_89 * V_91 , T_4 V_190 ,
struct V_187 * V_187 , const char * V_173 , int V_159 )
{
int V_174 = 0 ;
unsigned int V_169 ;
int V_37 , V_191 , V_175 = 0 ;
struct V_176 * V_177 ;
struct V_55 * V_56 = F_71 ( V_187 -> V_192 ) ;
struct V_170 * V_171 = F_54 ( V_56 ) ;
struct V_166 V_178 ;
struct V_179 V_180 ;
if ( F_14 ( V_171 ) )
return F_29 ( V_171 ) ;
V_177 = F_58 ( V_171 ) ;
V_169 = F_56 () ;
if ( F_63 ( V_56 ) )
V_175 |= V_181 ;
if ( V_159 == V_164 || V_159 == V_165 )
V_191 = V_193 ;
else
V_191 = V_194 ;
V_180 . V_177 = V_177 ;
V_180 . V_56 = V_56 ;
V_180 . V_182 = V_191 ;
V_180 . V_175 = V_175 ;
V_180 . V_184 = V_185 ;
V_180 . V_173 = V_173 ;
V_180 . V_178 = & V_178 ;
V_180 . V_186 = false ;
V_37 = F_64 ( V_169 , & V_180 , & V_174 , NULL ) ;
if ( V_37 ) {
F_15 ( V_117 , L_39 ) ;
goto V_195;
}
V_37 = F_72 ( V_169 , V_177 , V_178 . V_172 , V_91 , V_190 , V_159 ) ;
F_15 ( V_118 , L_40 , V_37 ) ;
F_65 ( V_169 , V_177 , V_178 . V_172 ) ;
V_195:
F_59 ( V_169 ) ;
F_60 ( V_171 ) ;
return V_37 ;
}
int
F_73 ( struct V_55 * V_56 , struct V_58 * V_59 ,
struct V_187 * V_187 , const char * V_173 ,
const struct V_166 * V_196 )
{
struct V_89 * V_90 = NULL ;
T_9 V_190 = 0 ;
int V_37 = 0 ;
struct V_170 * V_171 = F_54 ( V_56 ) ;
struct V_176 * V_177 ;
F_15 ( V_118 , L_41 , V_173 ) ;
if ( F_14 ( V_171 ) )
return F_29 ( V_171 ) ;
V_177 = F_58 ( V_171 ) ;
if ( V_196 && ( V_177 -> V_197 -> V_198 -> V_199 -> V_200 ) )
V_90 = V_177 -> V_197 -> V_198 -> V_199 -> V_200 ( V_56 , V_196 ,
& V_190 ) ;
else if ( V_177 -> V_197 -> V_198 -> V_199 -> V_201 )
V_90 = V_177 -> V_197 -> V_198 -> V_199 -> V_201 ( V_56 , V_187 , V_173 ,
& V_190 ) ;
else {
F_60 ( V_171 ) ;
return - V_202 ;
}
if ( F_14 ( V_90 ) ) {
V_37 = F_29 ( V_90 ) ;
F_15 ( V_117 , L_42 , V_48 , V_37 ) ;
} else {
V_37 = F_49 ( V_56 , V_90 , V_190 , V_59 ) ;
F_4 ( V_90 ) ;
if ( V_37 )
F_15 ( V_117 , L_43 , V_37 ) ;
}
F_60 ( V_171 ) ;
return V_37 ;
}
int
F_74 ( struct V_187 * V_187 , const char * V_173 , T_7 V_127 ,
T_2 V_66 , T_3 V_69 )
{
int V_37 = 0 ;
int V_159 = V_163 ;
T_4 V_158 = 0 ;
struct V_89 * V_90 = NULL ;
struct V_89 * V_91 = NULL ;
struct V_55 * V_56 = F_71 ( V_187 -> V_192 ) ;
struct V_170 * V_171 = F_54 ( V_56 ) ;
struct V_176 * V_177 ;
if ( F_14 ( V_171 ) )
return F_29 ( V_171 ) ;
V_177 = F_58 ( V_171 ) ;
F_15 ( V_118 , L_44 , V_173 ) ;
if ( V_177 -> V_197 -> V_198 -> V_199 -> V_201 == NULL ) {
F_60 ( V_171 ) ;
return - V_202 ;
}
V_90 = V_177 -> V_197 -> V_198 -> V_199 -> V_201 ( V_56 , V_187 , V_173 ,
& V_158 ) ;
if ( F_14 ( V_90 ) ) {
V_37 = F_29 ( V_90 ) ;
F_15 ( V_117 , L_42 , V_48 , V_37 ) ;
F_60 ( V_171 ) ;
return V_37 ;
}
V_158 = F_75 ( T_9 , V_158 , V_203 ) ;
V_91 = F_6 ( V_158 , V_7 ) ;
if ( ! V_91 ) {
F_4 ( V_90 ) ;
F_60 ( V_171 ) ;
return - V_8 ;
}
V_37 = F_50 ( V_90 , V_91 , V_158 , V_127 , V_66 , V_69 ,
& V_159 ) ;
F_15 ( V_118 , L_45 , V_37 ) ;
if ( V_177 -> V_197 -> V_198 -> V_199 -> V_204 == NULL )
V_37 = - V_202 ;
if ( ! V_37 ) {
V_37 = V_177 -> V_197 -> V_198 -> V_199 -> V_204 ( V_91 , V_158 , V_187 ,
V_173 , V_159 ) ;
F_15 ( V_118 , L_46 , V_37 ) ;
}
F_60 ( V_171 ) ;
F_4 ( V_91 ) ;
F_4 ( V_90 ) ;
return V_37 ;
}
