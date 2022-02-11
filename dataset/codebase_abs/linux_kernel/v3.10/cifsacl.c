static int
F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
char * V_4 ;
if ( V_3 -> V_5 <= sizeof( V_1 -> V_4 ) ) {
V_1 -> V_4 . V_6 = 0 ;
memcpy ( & V_1 -> V_4 . V_6 , V_3 -> V_7 , V_3 -> V_5 ) ;
V_1 -> V_5 = V_3 -> V_5 ;
return 0 ;
}
V_4 = F_2 ( V_3 -> V_7 , V_3 -> V_5 , V_8 ) ;
if ( ! V_4 )
return - V_9 ;
V_1 -> V_4 . V_7 = V_4 ;
V_1 -> V_5 = V_3 -> V_5 ;
return 0 ;
}
static inline void
F_3 ( struct V_1 * V_1 )
{
if ( V_1 -> V_5 > sizeof( V_1 -> V_4 ) )
F_4 ( V_1 -> V_4 . V_7 ) ;
}
static char *
F_5 ( struct V_10 * V_11 , unsigned int type )
{
int V_12 , V_13 ;
unsigned int V_14 ;
char * V_15 , * V_16 ;
unsigned long long V_17 ;
V_15 = F_6 ( 3 + V_18 +
( V_19 * V_11 -> V_20 ) ,
V_8 ) ;
if ( ! V_15 )
return V_15 ;
V_16 = V_15 ;
V_13 = sprintf ( V_16 , L_1 , type == V_21 ? 'o' : 'g' ,
V_11 -> V_22 ) ;
V_16 += V_13 ;
V_17 = ( unsigned long long ) V_11 -> V_23 [ 5 ] ;
V_17 |= ( unsigned long long ) V_11 -> V_23 [ 4 ] << 8 ;
V_17 |= ( unsigned long long ) V_11 -> V_23 [ 3 ] << 16 ;
V_17 |= ( unsigned long long ) V_11 -> V_23 [ 2 ] << 24 ;
V_17 |= ( unsigned long long ) V_11 -> V_23 [ 1 ] << 32 ;
V_17 |= ( unsigned long long ) V_11 -> V_23 [ 0 ] << 48 ;
if ( V_17 <= V_24 )
V_13 = sprintf ( V_16 , L_2 , V_17 ) ;
else
V_13 = sprintf ( V_16 , L_3 , V_17 ) ;
V_16 += V_13 ;
for ( V_12 = 0 ; V_12 < V_11 -> V_20 ; ++ V_12 ) {
V_14 = F_7 ( V_11 -> V_25 [ V_12 ] ) ;
V_13 = sprintf ( V_16 , L_4 , V_14 ) ;
V_16 += V_13 ;
}
return V_15 ;
}
static int
F_8 ( const struct V_10 * V_26 , const struct V_10 * V_27 )
{
int V_12 ;
int V_20 , V_28 , V_29 ;
if ( ( ! V_26 ) || ( ! V_27 ) )
return 1 ;
if ( V_26 -> V_22 != V_27 -> V_22 ) {
if ( V_26 -> V_22 > V_27 -> V_22 )
return 1 ;
else
return - 1 ;
}
for ( V_12 = 0 ; V_12 < V_30 ; ++ V_12 ) {
if ( V_26 -> V_23 [ V_12 ] != V_27 -> V_23 [ V_12 ] ) {
if ( V_26 -> V_23 [ V_12 ] > V_27 -> V_23 [ V_12 ] )
return 1 ;
else
return - 1 ;
}
}
V_28 = V_26 -> V_20 ;
V_29 = V_27 -> V_20 ;
V_20 = V_28 < V_29 ? V_28 : V_29 ;
if ( V_20 ) {
for ( V_12 = 0 ; V_12 < V_20 ; ++ V_12 ) {
if ( V_26 -> V_25 [ V_12 ] != V_27 -> V_25 [ V_12 ] ) {
if ( F_7 ( V_26 -> V_25 [ V_12 ] ) >
F_7 ( V_27 -> V_25 [ V_12 ] ) )
return 1 ;
else
return - 1 ;
}
}
}
return 0 ;
}
static void
F_9 ( struct V_10 * V_31 , const struct V_10 * V_32 )
{
int V_12 ;
V_31 -> V_22 = V_32 -> V_22 ;
V_31 -> V_20 = F_10 ( V_33 , V_32 -> V_20 , V_34 ) ;
for ( V_12 = 0 ; V_12 < V_30 ; ++ V_12 )
V_31 -> V_23 [ V_12 ] = V_32 -> V_23 [ V_12 ] ;
for ( V_12 = 0 ; V_12 < V_31 -> V_20 ; ++ V_12 )
V_31 -> V_25 [ V_12 ] = V_32 -> V_25 [ V_12 ] ;
}
static int
F_11 ( unsigned int V_35 , T_1 V_36 , struct V_10 * V_37 )
{
int V_38 ;
struct V_1 * V_39 ;
struct V_10 * V_40 ;
unsigned int V_41 ;
char V_42 [ 3 + 10 + 1 ] ;
const struct V_43 * V_44 ;
V_38 = snprintf ( V_42 , sizeof( V_42 ) , L_5 ,
V_36 == V_21 ? 'o' : 'g' , V_35 ) ;
if ( V_38 >= sizeof( V_42 ) )
return - V_45 ;
V_38 = 0 ;
V_44 = F_12 ( V_46 ) ;
V_39 = F_13 ( & V_47 , V_42 , L_6 ) ;
if ( F_14 ( V_39 ) ) {
V_38 = - V_45 ;
F_15 ( V_48 , L_7 ,
V_49 , V_36 == V_21 ? 'u' : 'g' , V_35 ) ;
goto V_50;
} else if ( V_39 -> V_5 < V_51 ) {
V_38 = - V_52 ;
F_15 ( V_48 , L_8 ,
V_49 , V_39 -> V_5 ) ;
goto V_53;
}
V_40 = V_39 -> V_5 <= sizeof( V_39 -> V_4 ) ?
(struct V_10 * ) & V_39 -> V_4 . V_6 :
(struct V_10 * ) V_39 -> V_4 . V_7 ;
V_41 = V_51 + ( V_40 -> V_20 * sizeof( V_54 ) ) ;
if ( V_41 > V_39 -> V_5 ) {
V_38 = - V_52 ;
F_15 ( V_48 , L_9 ,
V_49 , V_39 -> V_5 , V_41 ) ;
goto V_53;
}
F_9 ( V_37 , V_40 ) ;
V_55:
F_16 ( V_39 ) ;
V_50:
F_17 ( V_44 ) ;
return V_38 ;
V_53:
F_18 ( V_39 ) ;
goto V_55;
}
static int
F_19 ( struct V_56 * V_57 , struct V_10 * V_58 ,
struct V_59 * V_60 , T_1 V_36 )
{
int V_38 ;
struct V_1 * V_39 ;
char * V_15 ;
const struct V_43 * V_44 ;
T_2 V_61 = V_57 -> V_62 ;
T_3 V_63 = V_57 -> V_64 ;
if ( F_20 ( V_58 -> V_20 > V_34 ) ) {
F_15 ( V_48 , L_10 ,
V_49 , V_58 -> V_20 ) ;
return - V_52 ;
}
V_15 = F_5 ( V_58 , V_36 ) ;
if ( ! V_15 )
return - V_9 ;
V_44 = F_12 ( V_46 ) ;
V_39 = F_13 ( & V_47 , V_15 , L_6 ) ;
if ( F_14 ( V_39 ) ) {
V_38 = - V_45 ;
F_15 ( V_48 , L_11 ,
V_49 , V_15 , V_36 == V_21 ? 'u' : 'g' ) ;
goto V_50;
}
F_21 ( sizeof( V_65 ) != sizeof( V_66 ) ) ;
if ( V_39 -> V_5 != sizeof( V_65 ) ) {
V_38 = - V_52 ;
F_15 ( V_48 , L_8 ,
V_49 , V_39 -> V_5 ) ;
F_18 ( V_39 ) ;
goto V_55;
}
if ( V_36 == V_21 ) {
T_2 V_67 ;
V_65 V_68 ;
memcpy ( & V_68 , & V_39 -> V_4 . V_6 , sizeof( V_65 ) ) ;
V_67 = F_22 ( & V_69 , V_68 ) ;
if ( F_23 ( V_67 ) )
V_61 = V_67 ;
} else {
T_3 V_70 ;
V_66 V_68 ;
memcpy ( & V_68 , & V_39 -> V_4 . V_6 , sizeof( V_66 ) ) ;
V_70 = F_24 ( & V_69 , V_68 ) ;
if ( F_25 ( V_70 ) )
V_63 = V_70 ;
}
V_55:
F_16 ( V_39 ) ;
V_50:
F_17 ( V_44 ) ;
F_4 ( V_15 ) ;
if ( V_36 == V_21 )
V_60 -> V_71 = V_61 ;
else
V_60 -> V_72 = V_63 ;
return 0 ;
}
int
F_26 ( void )
{
struct V_43 * V_43 ;
struct V_1 * V_73 ;
int V_74 ;
F_15 ( V_48 , L_12 ,
V_47 . V_75 ) ;
V_43 = F_27 ( NULL ) ;
if ( ! V_43 )
return - V_9 ;
V_73 = F_28 ( L_13 ,
V_76 , V_77 , V_43 ,
( V_78 & ~ V_79 ) |
V_80 | V_81 ,
V_82 , NULL ) ;
if ( F_14 ( V_73 ) ) {
V_74 = F_29 ( V_73 ) ;
goto V_83;
}
V_74 = F_30 ( & V_47 ) ;
if ( V_74 < 0 )
goto V_84;
F_31 ( V_85 , & V_73 -> V_86 ) ;
V_43 -> V_87 = V_73 ;
V_43 -> V_88 = V_89 ;
V_46 = V_43 ;
F_15 ( V_48 , L_14 , F_32 ( V_73 ) ) ;
return 0 ;
V_84:
F_16 ( V_73 ) ;
V_83:
F_33 ( V_43 ) ;
return V_74 ;
}
void
F_34 ( void )
{
F_35 ( V_46 -> V_87 ) ;
F_36 ( & V_47 ) ;
F_33 ( V_46 ) ;
F_15 ( V_48 , L_15 , V_47 . V_75 ) ;
}
static void F_37 ( const struct V_90 * V_91 ,
struct V_90 * V_92 , T_4 V_93 )
{
struct V_10 * V_94 , * V_95 ;
struct V_10 * V_96 , * V_97 ;
V_92 -> V_22 = V_91 -> V_22 ;
V_92 -> type = V_91 -> type ;
V_92 -> V_98 = F_38 ( sizeof( struct V_90 ) ) ;
V_92 -> V_99 = 0 ;
V_92 -> V_100 = F_38 ( V_93 ) ;
V_92 -> V_101 = F_38 ( V_93 + sizeof( struct V_10 ) ) ;
V_94 = (struct V_10 * ) ( ( char * ) V_91 +
F_7 ( V_91 -> V_100 ) ) ;
V_96 = (struct V_10 * ) ( ( char * ) V_92 + V_93 ) ;
F_9 ( V_96 , V_94 ) ;
V_95 = (struct V_10 * ) ( ( char * ) V_91 +
F_7 ( V_91 -> V_101 ) ) ;
V_97 = (struct V_10 * ) ( ( char * ) V_92 + V_93 +
sizeof( struct V_10 ) ) ;
F_9 ( V_97 , V_95 ) ;
return;
}
static void F_39 ( V_54 V_102 , int type , T_5 * V_103 ,
T_5 * V_104 )
{
T_4 V_86 = F_7 ( V_102 ) ;
if ( type == V_105 ) {
if ( V_86 & V_106 )
* V_104 &= ~ V_107 ;
if ( ( V_86 & V_108 ) ||
( ( V_86 & V_109 ) == V_109 ) )
* V_104 &= ~ V_110 ;
if ( ( V_86 & V_111 ) ||
( ( V_86 & V_112 ) == V_112 ) )
* V_104 &= ~ V_113 ;
if ( ( V_86 & V_114 ) ||
( ( V_86 & V_115 ) == V_115 ) )
* V_104 &= ~ V_116 ;
return;
} else if ( type != V_117 ) {
F_15 ( V_118 , L_16 , type ) ;
return;
}
if ( V_86 & V_106 ) {
* V_103 |= ( V_107 & ( * V_104 ) ) ;
F_15 ( V_119 , L_17 ) ;
return;
}
if ( ( V_86 & V_108 ) ||
( ( V_86 & V_109 ) == V_109 ) )
* V_103 |= ( V_110 & ( * V_104 ) ) ;
if ( ( V_86 & V_111 ) ||
( ( V_86 & V_112 ) == V_112 ) )
* V_103 |= ( V_113 & ( * V_104 ) ) ;
if ( ( V_86 & V_114 ) ||
( ( V_86 & V_115 ) == V_115 ) )
* V_103 |= ( V_116 & ( * V_104 ) ) ;
F_15 ( V_119 , L_18 , V_86 , * V_103 ) ;
return;
}
static void F_40 ( T_5 V_120 , T_5 V_121 ,
T_4 * V_122 )
{
* V_122 = 0x0 ;
V_120 &= V_121 ;
if ( V_120 & V_113 )
* V_122 |= V_123 ;
if ( V_120 & V_110 )
* V_122 |= V_124 ;
if ( V_120 & V_116 )
* V_122 |= V_125 ;
F_15 ( V_119 , L_19 ,
V_120 , * V_122 ) ;
return;
}
static T_6 F_41 ( struct V_126 * V_127 ,
const struct V_10 * V_58 , T_7 V_128 , T_5 V_129 )
{
int V_12 ;
T_6 V_130 = 0 ;
T_4 V_131 = 0 ;
V_127 -> type = V_117 ;
V_127 -> V_86 = 0x0 ;
F_40 ( V_128 , V_129 , & V_131 ) ;
if ( ! V_131 )
V_131 = V_132 ;
V_127 -> V_131 = F_38 ( V_131 ) ;
V_127 -> V_133 . V_22 = V_58 -> V_22 ;
V_127 -> V_133 . V_20 = V_58 -> V_20 ;
for ( V_12 = 0 ; V_12 < V_30 ; V_12 ++ )
V_127 -> V_133 . V_23 [ V_12 ] = V_58 -> V_23 [ V_12 ] ;
for ( V_12 = 0 ; V_12 < V_58 -> V_20 ; V_12 ++ )
V_127 -> V_133 . V_25 [ V_12 ] = V_58 -> V_25 [ V_12 ] ;
V_130 = 1 + 1 + 2 + 4 + 1 + 1 + 6 + ( V_58 -> V_20 * 4 ) ;
V_127 -> V_130 = F_42 ( V_130 ) ;
return V_130 ;
}
static void F_43 ( struct V_126 * V_134 , char * V_135 )
{
int V_20 ;
if ( F_44 ( V_134 -> V_130 ) < 16 ) {
F_15 ( V_118 , L_20 , F_44 ( V_134 -> V_130 ) ) ;
return;
}
if ( V_135 < ( char * ) V_134 + F_44 ( V_134 -> V_130 ) ) {
F_15 ( V_118 , L_21 ) ;
return;
}
V_20 = V_134 -> V_133 . V_20 ;
if ( V_20 ) {
int V_12 ;
F_15 ( V_48 , L_22 ,
V_134 -> V_133 . V_22 , V_134 -> V_133 . V_20 , V_134 -> type ,
V_134 -> V_86 , F_44 ( V_134 -> V_130 ) ) ;
for ( V_12 = 0 ; V_12 < V_20 ; ++ V_12 ) {
F_15 ( V_48 , L_23 ,
V_12 , F_7 ( V_134 -> V_133 . V_25 [ V_12 ] ) ) ;
}
}
return;
}
static void F_45 ( struct V_136 * V_137 , char * V_135 ,
struct V_10 * V_138 , struct V_10 * V_139 ,
struct V_59 * V_60 )
{
int V_12 ;
int V_140 = 0 ;
int V_141 ;
char * V_142 ;
struct V_126 * * V_143 ;
if ( ! V_137 ) {
V_60 -> V_144 |= V_107 ;
return;
}
if ( V_135 < ( char * ) V_137 + F_44 ( V_137 -> V_130 ) ) {
F_15 ( V_118 , L_24 ) ;
return;
}
F_15 ( V_119 , L_25 ,
F_44 ( V_137 -> V_22 ) , F_44 ( V_137 -> V_130 ) ,
F_7 ( V_137 -> V_140 ) ) ;
V_60 -> V_144 &= ~ ( V_107 ) ;
V_142 = ( char * ) V_137 ;
V_141 = sizeof( struct V_136 ) ;
V_140 = F_7 ( V_137 -> V_140 ) ;
if ( V_140 > 0 ) {
T_5 V_145 = V_146 ;
T_5 V_147 = V_148 ;
T_5 V_149 = V_146 | V_148 | V_150 ;
if ( V_140 > V_151 / sizeof( struct V_126 * ) )
return;
V_143 = F_6 ( V_140 * sizeof( struct V_126 * ) ,
V_8 ) ;
if ( ! V_143 )
return;
for ( V_12 = 0 ; V_12 < V_140 ; ++ V_12 ) {
V_143 [ V_12 ] = (struct V_126 * ) ( V_142 + V_141 ) ;
#ifdef F_46
F_43 ( V_143 [ V_12 ] , V_135 ) ;
#endif
if ( F_8 ( & ( V_143 [ V_12 ] -> V_133 ) , V_138 ) == 0 )
F_39 ( V_143 [ V_12 ] -> V_131 ,
V_143 [ V_12 ] -> type ,
& V_60 -> V_144 ,
& V_145 ) ;
if ( F_8 ( & ( V_143 [ V_12 ] -> V_133 ) , V_139 ) == 0 )
F_39 ( V_143 [ V_12 ] -> V_131 ,
V_143 [ V_12 ] -> type ,
& V_60 -> V_144 ,
& V_147 ) ;
if ( F_8 ( & ( V_143 [ V_12 ] -> V_133 ) , & V_152 ) == 0 )
F_39 ( V_143 [ V_12 ] -> V_131 ,
V_143 [ V_12 ] -> type ,
& V_60 -> V_144 ,
& V_149 ) ;
if ( F_8 ( & ( V_143 [ V_12 ] -> V_133 ) , & V_153 ) == 0 )
F_39 ( V_143 [ V_12 ] -> V_131 ,
V_143 [ V_12 ] -> type ,
& V_60 -> V_144 ,
& V_149 ) ;
V_142 = ( char * ) V_143 [ V_12 ] ;
V_141 = F_44 ( V_143 [ V_12 ] -> V_130 ) ;
}
F_4 ( V_143 ) ;
}
return;
}
static int F_47 ( struct V_136 * V_154 , struct V_10 * V_138 ,
struct V_10 * V_139 , T_7 V_128 )
{
T_8 V_130 = 0 ;
struct V_136 * V_155 ;
V_155 = (struct V_136 * ) ( ( char * ) V_154 + sizeof( struct V_136 ) ) ;
V_130 += F_41 ( (struct V_126 * ) ( ( char * ) V_155 + V_130 ) ,
V_138 , V_128 , V_146 ) ;
V_130 += F_41 ( (struct V_126 * ) ( ( char * ) V_155 + V_130 ) ,
V_139 , V_128 , V_148 ) ;
V_130 += F_41 ( (struct V_126 * ) ( ( char * ) V_155 + V_130 ) ,
& V_152 , V_128 , V_150 ) ;
V_154 -> V_130 = F_42 ( V_130 + sizeof( struct V_136 ) ) ;
V_154 -> V_140 = F_38 ( 3 ) ;
return 0 ;
}
static int F_48 ( struct V_10 * V_58 , char * V_135 )
{
if ( V_135 < ( char * ) V_58 + 8 ) {
F_15 ( V_118 , L_26 , V_58 ) ;
return - V_45 ;
}
#ifdef F_46
if ( V_58 -> V_20 ) {
int V_12 ;
F_15 ( V_48 , L_27 ,
V_58 -> V_22 , V_58 -> V_20 ) ;
for ( V_12 = 0 ; V_12 < V_58 -> V_20 ; V_12 ++ ) {
F_15 ( V_48 , L_28 ,
V_12 , F_7 ( V_58 -> V_25 [ V_12 ] ) ) ;
}
F_15 ( V_48 , L_29 ,
F_7 ( V_58 -> V_25 [ V_58 -> V_20 - 1 ] ) ) ;
}
#endif
return 0 ;
}
static int F_49 ( struct V_56 * V_57 ,
struct V_90 * V_91 , int V_156 , struct V_59 * V_60 )
{
int V_38 = 0 ;
struct V_10 * V_94 , * V_95 ;
struct V_136 * V_157 ;
char * V_135 = ( ( char * ) V_91 ) + V_156 ;
T_4 V_98 ;
if ( V_91 == NULL )
return - V_52 ;
V_94 = (struct V_10 * ) ( ( char * ) V_91 +
F_7 ( V_91 -> V_100 ) ) ;
V_95 = (struct V_10 * ) ( ( char * ) V_91 +
F_7 ( V_91 -> V_101 ) ) ;
V_98 = F_7 ( V_91 -> V_98 ) ;
V_157 = (struct V_136 * ) ( ( char * ) V_91 + V_98 ) ;
F_15 ( V_119 , L_30 ,
V_91 -> V_22 , V_91 -> type , F_7 ( V_91 -> V_100 ) ,
F_7 ( V_91 -> V_101 ) ,
F_7 ( V_91 -> V_99 ) , V_98 ) ;
V_38 = F_48 ( V_94 , V_135 ) ;
if ( V_38 ) {
F_15 ( V_48 , L_31 , V_49 , V_38 ) ;
return V_38 ;
}
V_38 = F_19 ( V_57 , V_94 , V_60 , V_21 ) ;
if ( V_38 ) {
F_15 ( V_48 , L_32 ,
V_49 , V_38 ) ;
return V_38 ;
}
V_38 = F_48 ( V_95 , V_135 ) ;
if ( V_38 ) {
F_15 ( V_48 , L_33 ,
V_49 , V_38 ) ;
return V_38 ;
}
V_38 = F_19 ( V_57 , V_95 , V_60 , V_158 ) ;
if ( V_38 ) {
F_15 ( V_48 , L_34 ,
V_49 , V_38 ) ;
return V_38 ;
}
if ( V_98 )
F_45 ( V_157 , V_135 , V_94 ,
V_95 , V_60 ) ;
else
F_15 ( V_48 , L_35 ) ;
return V_38 ;
}
static int F_50 ( struct V_90 * V_91 , struct V_90 * V_92 ,
T_4 V_159 , T_7 V_128 , T_2 V_67 , T_3 V_70 , int * V_160 )
{
int V_38 = 0 ;
T_4 V_98 ;
T_4 V_161 ;
T_4 V_93 ;
struct V_10 * V_94 , * V_95 ;
struct V_10 * V_96 , * V_97 ;
struct V_136 * V_157 = NULL ;
struct V_136 * V_162 = NULL ;
if ( V_128 != V_163 ) {
V_94 = (struct V_10 * ) ( ( char * ) V_91 +
F_7 ( V_91 -> V_100 ) ) ;
V_95 = (struct V_10 * ) ( ( char * ) V_91 +
F_7 ( V_91 -> V_101 ) ) ;
V_98 = F_7 ( V_91 -> V_98 ) ;
V_157 = (struct V_136 * ) ( ( char * ) V_91 + V_98 ) ;
V_161 = sizeof( struct V_90 ) ;
V_162 = (struct V_136 * ) ( ( char * ) V_92 + V_161 ) ;
V_162 -> V_22 = V_157 -> V_22 ;
V_162 -> V_130 = 0 ;
V_162 -> V_140 = 0 ;
V_38 = F_47 ( V_162 , V_94 , V_95 ,
V_128 ) ;
V_93 = V_161 + F_44 ( V_162 -> V_130 ) ;
F_37 ( V_91 , V_92 , V_93 ) ;
* V_160 = V_164 ;
} else {
memcpy ( V_92 , V_91 , V_159 ) ;
if ( F_23 ( V_67 ) ) {
V_65 V_68 ;
V_94 = (struct V_10 * ) ( ( char * ) V_92 +
F_7 ( V_92 -> V_100 ) ) ;
V_96 = F_6 ( sizeof( struct V_10 ) ,
V_8 ) ;
if ( ! V_96 )
return - V_9 ;
V_68 = F_51 ( & V_69 , V_67 ) ;
V_38 = F_11 ( V_68 , V_21 , V_96 ) ;
if ( V_38 ) {
F_15 ( V_48 , L_36 ,
V_49 , V_38 , V_68 ) ;
F_4 ( V_96 ) ;
return V_38 ;
}
F_9 ( V_94 , V_96 ) ;
F_4 ( V_96 ) ;
* V_160 = V_165 ;
}
if ( F_25 ( V_70 ) ) {
V_66 V_68 ;
V_95 = (struct V_10 * ) ( ( char * ) V_92 +
F_7 ( V_92 -> V_101 ) ) ;
V_97 = F_6 ( sizeof( struct V_10 ) ,
V_8 ) ;
if ( ! V_97 )
return - V_9 ;
V_68 = F_52 ( & V_69 , V_70 ) ;
V_38 = F_11 ( V_68 , V_158 , V_97 ) ;
if ( V_38 ) {
F_15 ( V_48 , L_37 ,
V_49 , V_38 , V_68 ) ;
F_4 ( V_97 ) ;
return V_38 ;
}
F_9 ( V_95 , V_97 ) ;
F_4 ( V_97 ) ;
* V_160 = V_166 ;
}
}
return V_38 ;
}
static struct V_90 * F_53 ( struct V_56 * V_57 ,
T_6 V_167 , T_9 * V_168 )
{
struct V_90 * V_91 = NULL ;
unsigned int V_169 ;
int V_38 ;
struct V_170 * V_171 = F_54 ( V_57 ) ;
if ( F_14 ( V_171 ) )
return F_55 ( V_171 ) ;
V_169 = F_56 () ;
V_38 = F_57 ( V_169 , F_58 ( V_171 ) , V_167 , & V_91 , V_168 ) ;
F_59 ( V_169 ) ;
F_60 ( V_171 ) ;
F_15 ( V_48 , L_38 , V_49 , V_38 , * V_168 ) ;
if ( V_38 )
return F_61 ( V_38 ) ;
return V_91 ;
}
static struct V_90 * F_62 ( struct V_56 * V_57 ,
const char * V_172 , T_9 * V_168 )
{
struct V_90 * V_91 = NULL ;
int V_173 = 0 ;
unsigned int V_169 ;
int V_38 , V_174 = 0 ;
T_6 V_167 ;
struct V_175 * V_176 ;
struct V_170 * V_171 = F_54 ( V_57 ) ;
if ( F_14 ( V_171 ) )
return F_55 ( V_171 ) ;
V_176 = F_58 ( V_171 ) ;
V_169 = F_56 () ;
if ( F_63 ( V_57 ) )
V_174 |= V_177 ;
V_38 = F_64 ( V_169 , V_176 , V_172 , V_178 , V_179 ,
V_174 , & V_167 , & V_173 , NULL , V_57 -> V_180 ,
V_57 -> V_181 & V_182 ) ;
if ( ! V_38 ) {
V_38 = F_57 ( V_169 , V_176 , V_167 , & V_91 , V_168 ) ;
F_65 ( V_169 , V_176 , V_167 ) ;
}
F_60 ( V_171 ) ;
F_59 ( V_169 ) ;
F_15 ( V_48 , L_38 , V_49 , V_38 , * V_168 ) ;
if ( V_38 )
return F_61 ( V_38 ) ;
return V_91 ;
}
struct V_90 * F_66 ( struct V_56 * V_57 ,
struct V_183 * V_183 , const char * V_172 ,
T_9 * V_168 )
{
struct V_90 * V_91 = NULL ;
struct V_184 * V_185 = NULL ;
if ( V_183 )
V_185 = F_67 ( F_68 ( V_183 ) , true ) ;
if ( ! V_185 )
return F_62 ( V_57 , V_172 , V_168 ) ;
V_91 = F_53 ( V_57 , V_185 -> V_167 . V_186 , V_168 ) ;
F_69 ( V_185 ) ;
return V_91 ;
}
int F_70 ( struct V_90 * V_92 , T_4 V_187 ,
struct V_183 * V_183 , const char * V_172 , int V_160 )
{
int V_173 = 0 ;
unsigned int V_169 ;
int V_38 , V_188 , V_174 = 0 ;
T_6 V_167 ;
struct V_175 * V_176 ;
struct V_56 * V_57 = F_71 ( V_183 -> V_189 ) ;
struct V_170 * V_171 = F_54 ( V_57 ) ;
if ( F_14 ( V_171 ) )
return F_29 ( V_171 ) ;
V_176 = F_58 ( V_171 ) ;
V_169 = F_56 () ;
if ( F_63 ( V_57 ) )
V_174 |= V_177 ;
if ( V_160 == V_165 || V_160 == V_166 )
V_188 = V_190 ;
else
V_188 = V_191 ;
V_38 = F_64 ( V_169 , V_176 , V_172 , V_178 , V_188 ,
V_174 , & V_167 , & V_173 , NULL , V_57 -> V_180 ,
V_57 -> V_181 & V_182 ) ;
if ( V_38 ) {
F_15 ( V_118 , L_39 ) ;
goto V_192;
}
V_38 = F_72 ( V_169 , V_176 , V_167 , V_92 , V_187 , V_160 ) ;
F_15 ( V_119 , L_40 , V_38 ) ;
F_65 ( V_169 , V_176 , V_167 ) ;
V_192:
F_59 ( V_169 ) ;
F_60 ( V_171 ) ;
return V_38 ;
}
int
F_73 ( struct V_56 * V_57 , struct V_59 * V_60 ,
struct V_183 * V_183 , const char * V_172 , const T_6 * V_193 )
{
struct V_90 * V_91 = NULL ;
T_9 V_187 = 0 ;
int V_38 = 0 ;
F_15 ( V_119 , L_41 , V_172 ) ;
if ( V_193 )
V_91 = F_53 ( V_57 , * V_193 , & V_187 ) ;
else
V_91 = F_66 ( V_57 , V_183 , V_172 , & V_187 ) ;
if ( F_14 ( V_91 ) ) {
V_38 = F_29 ( V_91 ) ;
F_15 ( V_118 , L_42 , V_49 , V_38 ) ;
} else {
V_38 = F_49 ( V_57 , V_91 , V_187 , V_60 ) ;
F_4 ( V_91 ) ;
if ( V_38 )
F_15 ( V_118 , L_43 , V_38 ) ;
}
return V_38 ;
}
int
F_74 ( struct V_183 * V_183 , const char * V_172 , T_7 V_128 ,
T_2 V_67 , T_3 V_70 )
{
int V_38 = 0 ;
int V_160 = V_164 ;
T_4 V_159 = 0 ;
struct V_90 * V_91 = NULL ;
struct V_90 * V_92 = NULL ;
F_15 ( V_119 , L_44 , V_172 ) ;
V_91 = F_66 ( F_71 ( V_183 -> V_189 ) , V_183 , V_172 , & V_159 ) ;
if ( F_14 ( V_91 ) ) {
V_38 = F_29 ( V_91 ) ;
F_15 ( V_118 , L_42 , V_49 , V_38 ) ;
goto V_192;
}
V_159 = F_75 ( T_9 , V_159 , V_194 ) ;
V_92 = F_6 ( V_159 , V_8 ) ;
if ( ! V_92 ) {
F_4 ( V_91 ) ;
return - V_9 ;
}
V_38 = F_50 ( V_91 , V_92 , V_159 , V_128 , V_67 , V_70 ,
& V_160 ) ;
F_15 ( V_119 , L_45 , V_38 ) ;
if ( ! V_38 ) {
V_38 = F_70 ( V_92 , V_159 , V_183 , V_172 , V_160 ) ;
F_15 ( V_119 , L_46 , V_38 ) ;
}
F_4 ( V_92 ) ;
F_4 ( V_91 ) ;
V_192:
return V_38 ;
}
