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
V_4 = F_2 ( V_3 -> V_5 , V_8 ) ;
if ( ! V_4 )
return - V_9 ;
memcpy ( V_4 , V_3 -> V_7 , V_3 -> V_5 ) ;
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
V_15 = F_2 ( 3 + V_18 +
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
V_14 = F_6 ( V_11 -> V_25 [ V_12 ] ) ;
V_13 = sprintf ( V_16 , L_4 , V_14 ) ;
V_16 += V_13 ;
}
return V_15 ;
}
static int
F_7 ( const struct V_10 * V_26 , const struct V_10 * V_27 )
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
if ( F_6 ( V_26 -> V_25 [ V_12 ] ) >
F_6 ( V_27 -> V_25 [ V_12 ] ) )
return 1 ;
else
return - 1 ;
}
}
}
return 0 ;
}
static void
F_8 ( struct V_10 * V_31 , const struct V_10 * V_32 )
{
int V_12 ;
V_31 -> V_22 = V_32 -> V_22 ;
V_31 -> V_20 = F_9 ( V_33 , V_32 -> V_20 , V_34 ) ;
for ( V_12 = 0 ; V_12 < V_30 ; ++ V_12 )
V_31 -> V_23 [ V_12 ] = V_32 -> V_23 [ V_12 ] ;
for ( V_12 = 0 ; V_12 < V_31 -> V_20 ; ++ V_12 )
V_31 -> V_25 [ V_12 ] = V_32 -> V_25 [ V_12 ] ;
}
static int
F_10 ( unsigned int V_35 , T_1 V_36 , struct V_10 * V_37 )
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
V_44 = F_11 ( V_46 ) ;
V_39 = F_12 ( & V_47 , V_42 , L_6 ) ;
if ( F_13 ( V_39 ) ) {
V_38 = - V_45 ;
F_14 ( 1 , L_7 , V_48 ,
V_36 == V_21 ? 'u' : 'g' , V_35 ) ;
goto V_49;
} else if ( V_39 -> V_5 < V_50 ) {
V_38 = - V_51 ;
F_14 ( 1 , L_8
L_9 , V_48 , V_39 -> V_5 ) ;
goto V_52;
}
V_40 = V_39 -> V_5 <= sizeof( V_39 -> V_4 ) ?
(struct V_10 * ) & V_39 -> V_4 . V_6 :
(struct V_10 * ) V_39 -> V_4 . V_7 ;
V_41 = V_50 + ( V_40 -> V_20 * sizeof( V_53 ) ) ;
if ( V_41 > V_39 -> V_5 ) {
V_38 = - V_51 ;
F_14 ( 1 , L_10
L_11 , V_48 , V_39 -> V_5 , V_41 ) ;
goto V_52;
}
F_8 ( V_37 , V_40 ) ;
V_54:
F_15 ( V_39 ) ;
V_49:
F_16 ( V_44 ) ;
return V_38 ;
V_52:
F_17 ( V_39 ) ;
goto V_54;
}
static int
F_18 ( struct V_55 * V_56 , struct V_10 * V_57 ,
struct V_58 * V_59 , T_1 V_36 )
{
int V_38 ;
struct V_1 * V_39 ;
char * V_15 ;
const struct V_43 * V_44 ;
T_2 V_60 = V_56 -> V_61 ;
T_3 V_62 = V_56 -> V_63 ;
if ( F_19 ( V_57 -> V_20 > V_34 ) ) {
F_14 ( 1 , L_12 , V_48 ,
V_57 -> V_20 ) ;
return - V_51 ;
}
V_15 = F_5 ( V_57 , V_36 ) ;
if ( ! V_15 )
return - V_9 ;
V_44 = F_11 ( V_46 ) ;
V_39 = F_12 ( & V_47 , V_15 , L_6 ) ;
if ( F_13 ( V_39 ) ) {
V_38 = - V_45 ;
F_14 ( 1 , L_13 , V_48 , V_15 ,
V_36 == V_21 ? 'u' : 'g' ) ;
goto V_49;
}
F_20 ( sizeof( V_64 ) != sizeof( V_65 ) ) ;
if ( V_39 -> V_5 != sizeof( V_64 ) ) {
V_38 = - V_51 ;
F_14 ( 1 , L_8
L_9 , V_48 , V_39 -> V_5 ) ;
F_17 ( V_39 ) ;
goto V_54;
}
if ( V_36 == V_21 ) {
T_2 V_66 ;
V_64 V_67 ;
memcpy ( & V_67 , & V_39 -> V_4 . V_6 , sizeof( V_64 ) ) ;
V_66 = F_21 ( & V_68 , V_67 ) ;
if ( F_22 ( V_66 ) )
V_60 = V_66 ;
} else {
T_3 V_69 ;
V_65 V_67 ;
memcpy ( & V_67 , & V_39 -> V_4 . V_6 , sizeof( V_65 ) ) ;
V_69 = F_23 ( & V_68 , V_67 ) ;
if ( F_24 ( V_69 ) )
V_62 = V_69 ;
}
V_54:
F_15 ( V_39 ) ;
V_49:
F_16 ( V_44 ) ;
F_4 ( V_15 ) ;
if ( V_36 == V_21 )
V_59 -> V_70 = V_60 ;
else
V_59 -> V_71 = V_62 ;
return 0 ;
}
int
F_25 ( void )
{
struct V_43 * V_43 ;
struct V_1 * V_72 ;
int V_73 ;
F_14 ( 1 , L_14 , V_47 . V_74 ) ;
V_43 = F_26 ( NULL ) ;
if ( ! V_43 )
return - V_9 ;
V_72 = F_27 ( L_15 ,
V_75 , V_76 , V_43 ,
( V_77 & ~ V_78 ) |
V_79 | V_80 ,
V_81 , NULL ) ;
if ( F_13 ( V_72 ) ) {
V_73 = F_28 ( V_72 ) ;
goto V_82;
}
V_73 = F_29 ( & V_47 ) ;
if ( V_73 < 0 )
goto V_83;
F_30 ( V_84 , & V_72 -> V_85 ) ;
V_43 -> V_86 = V_72 ;
V_43 -> V_87 = V_88 ;
V_46 = V_43 ;
F_14 ( 1 , L_16 , F_31 ( V_72 ) ) ;
return 0 ;
V_83:
F_15 ( V_72 ) ;
V_82:
F_32 ( V_43 ) ;
return V_73 ;
}
void
F_33 ( void )
{
F_34 ( V_46 -> V_86 ) ;
F_35 ( & V_47 ) ;
F_32 ( V_46 ) ;
F_14 ( 1 , L_17 , V_47 . V_74 ) ;
}
static void F_36 ( const struct V_89 * V_90 ,
struct V_89 * V_91 , T_4 V_92 )
{
struct V_10 * V_93 , * V_94 ;
struct V_10 * V_95 , * V_96 ;
V_91 -> V_22 = V_90 -> V_22 ;
V_91 -> type = V_90 -> type ;
V_91 -> V_97 = F_37 ( sizeof( struct V_89 ) ) ;
V_91 -> V_98 = 0 ;
V_91 -> V_99 = F_37 ( V_92 ) ;
V_91 -> V_100 = F_37 ( V_92 + sizeof( struct V_10 ) ) ;
V_93 = (struct V_10 * ) ( ( char * ) V_90 +
F_6 ( V_90 -> V_99 ) ) ;
V_95 = (struct V_10 * ) ( ( char * ) V_91 + V_92 ) ;
F_8 ( V_95 , V_93 ) ;
V_94 = (struct V_10 * ) ( ( char * ) V_90 +
F_6 ( V_90 -> V_100 ) ) ;
V_96 = (struct V_10 * ) ( ( char * ) V_91 + V_92 +
sizeof( struct V_10 ) ) ;
F_8 ( V_96 , V_94 ) ;
return;
}
static void F_38 ( V_53 V_101 , int type , T_5 * V_102 ,
T_5 * V_103 )
{
T_4 V_85 = F_6 ( V_101 ) ;
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
F_39 ( 1 , L_18 , type ) ;
return;
}
if ( V_85 & V_105 ) {
* V_102 |= ( V_106 & ( * V_103 ) ) ;
F_14 ( V_117 , L_19 ) ;
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
F_14 ( V_117 , L_20 , V_85 , * V_102 ) ;
return;
}
static void F_40 ( T_5 V_118 , T_5 V_119 ,
T_4 * V_120 )
{
* V_120 = 0x0 ;
V_118 &= V_119 ;
if ( V_118 & V_112 )
* V_120 |= V_121 ;
if ( V_118 & V_109 )
* V_120 |= V_122 ;
if ( V_118 & V_115 )
* V_120 |= V_123 ;
F_14 ( V_117 , L_21 , V_118 , * V_120 ) ;
return;
}
static T_6 F_41 ( struct V_124 * V_125 ,
const struct V_10 * V_57 , T_7 V_126 , T_5 V_127 )
{
int V_12 ;
T_6 V_128 = 0 ;
T_4 V_129 = 0 ;
V_125 -> type = V_116 ;
V_125 -> V_85 = 0x0 ;
F_40 ( V_126 , V_127 , & V_129 ) ;
if ( ! V_129 )
V_129 = V_130 ;
V_125 -> V_129 = F_37 ( V_129 ) ;
V_125 -> V_131 . V_22 = V_57 -> V_22 ;
V_125 -> V_131 . V_20 = V_57 -> V_20 ;
for ( V_12 = 0 ; V_12 < V_30 ; V_12 ++ )
V_125 -> V_131 . V_23 [ V_12 ] = V_57 -> V_23 [ V_12 ] ;
for ( V_12 = 0 ; V_12 < V_57 -> V_20 ; V_12 ++ )
V_125 -> V_131 . V_25 [ V_12 ] = V_57 -> V_25 [ V_12 ] ;
V_128 = 1 + 1 + 2 + 4 + 1 + 1 + 6 + ( V_57 -> V_20 * 4 ) ;
V_125 -> V_128 = F_42 ( V_128 ) ;
return V_128 ;
}
static void F_43 ( struct V_124 * V_132 , char * V_133 )
{
int V_20 ;
if ( F_44 ( V_132 -> V_128 ) < 16 ) {
F_39 ( 1 , L_22 , F_44 ( V_132 -> V_128 ) ) ;
return;
}
if ( V_133 < ( char * ) V_132 + F_44 ( V_132 -> V_128 ) ) {
F_39 ( 1 , L_23 ) ;
return;
}
V_20 = V_132 -> V_131 . V_20 ;
if ( V_20 ) {
int V_12 ;
F_14 ( 1 , L_24 ,
V_132 -> V_131 . V_22 , V_132 -> V_131 . V_20 , V_132 -> type ,
V_132 -> V_85 , F_44 ( V_132 -> V_128 ) ) ;
for ( V_12 = 0 ; V_12 < V_20 ; ++ V_12 ) {
F_14 ( 1 , L_25 , V_12 ,
F_6 ( V_132 -> V_131 . V_25 [ V_12 ] ) ) ;
}
}
return;
}
static void F_45 ( struct V_134 * V_135 , char * V_133 ,
struct V_10 * V_136 , struct V_10 * V_137 ,
struct V_58 * V_59 )
{
int V_12 ;
int V_138 = 0 ;
int V_139 ;
char * V_140 ;
struct V_124 * * V_141 ;
if ( ! V_135 ) {
V_59 -> V_142 |= V_106 ;
return;
}
if ( V_133 < ( char * ) V_135 + F_44 ( V_135 -> V_128 ) ) {
F_39 ( 1 , L_26 ) ;
return;
}
F_14 ( V_117 , L_27 ,
F_44 ( V_135 -> V_22 ) , F_44 ( V_135 -> V_128 ) ,
F_6 ( V_135 -> V_138 ) ) ;
V_59 -> V_142 &= ~ ( V_106 ) ;
V_140 = ( char * ) V_135 ;
V_139 = sizeof( struct V_134 ) ;
V_138 = F_6 ( V_135 -> V_138 ) ;
if ( V_138 > 0 ) {
T_5 V_143 = V_144 ;
T_5 V_145 = V_146 ;
T_5 V_147 = V_144 | V_146 | V_148 ;
if ( V_138 > V_149 / sizeof( struct V_124 * ) )
return;
V_141 = F_2 ( V_138 * sizeof( struct V_124 * ) ,
V_8 ) ;
if ( ! V_141 ) {
F_39 ( 1 , L_28 ) ;
return;
}
for ( V_12 = 0 ; V_12 < V_138 ; ++ V_12 ) {
V_141 [ V_12 ] = (struct V_124 * ) ( V_140 + V_139 ) ;
#ifdef F_46
F_43 ( V_141 [ V_12 ] , V_133 ) ;
#endif
if ( F_7 ( & ( V_141 [ V_12 ] -> V_131 ) , V_136 ) == 0 )
F_38 ( V_141 [ V_12 ] -> V_129 ,
V_141 [ V_12 ] -> type ,
& V_59 -> V_142 ,
& V_143 ) ;
if ( F_7 ( & ( V_141 [ V_12 ] -> V_131 ) , V_137 ) == 0 )
F_38 ( V_141 [ V_12 ] -> V_129 ,
V_141 [ V_12 ] -> type ,
& V_59 -> V_142 ,
& V_145 ) ;
if ( F_7 ( & ( V_141 [ V_12 ] -> V_131 ) , & V_150 ) == 0 )
F_38 ( V_141 [ V_12 ] -> V_129 ,
V_141 [ V_12 ] -> type ,
& V_59 -> V_142 ,
& V_147 ) ;
if ( F_7 ( & ( V_141 [ V_12 ] -> V_131 ) , & V_151 ) == 0 )
F_38 ( V_141 [ V_12 ] -> V_129 ,
V_141 [ V_12 ] -> type ,
& V_59 -> V_142 ,
& V_147 ) ;
V_140 = ( char * ) V_141 [ V_12 ] ;
V_139 = F_44 ( V_141 [ V_12 ] -> V_128 ) ;
}
F_4 ( V_141 ) ;
}
return;
}
static int F_47 ( struct V_134 * V_152 , struct V_10 * V_136 ,
struct V_10 * V_137 , T_7 V_126 )
{
T_8 V_128 = 0 ;
struct V_134 * V_153 ;
V_153 = (struct V_134 * ) ( ( char * ) V_152 + sizeof( struct V_134 ) ) ;
V_128 += F_41 ( (struct V_124 * ) ( ( char * ) V_153 + V_128 ) ,
V_136 , V_126 , V_144 ) ;
V_128 += F_41 ( (struct V_124 * ) ( ( char * ) V_153 + V_128 ) ,
V_137 , V_126 , V_146 ) ;
V_128 += F_41 ( (struct V_124 * ) ( ( char * ) V_153 + V_128 ) ,
& V_150 , V_126 , V_148 ) ;
V_152 -> V_128 = F_42 ( V_128 + sizeof( struct V_134 ) ) ;
V_152 -> V_138 = F_37 ( 3 ) ;
return 0 ;
}
static int F_48 ( struct V_10 * V_57 , char * V_133 )
{
if ( V_133 < ( char * ) V_57 + 8 ) {
F_39 ( 1 , L_29 , V_57 ) ;
return - V_45 ;
}
#ifdef F_46
if ( V_57 -> V_20 ) {
int V_12 ;
F_14 ( 1 , L_30 ,
V_57 -> V_22 , V_57 -> V_20 ) ;
for ( V_12 = 0 ; V_12 < V_57 -> V_20 ; V_12 ++ ) {
F_14 ( 1 , L_31 , V_12 ,
F_6 ( V_57 -> V_25 [ V_12 ] ) ) ;
}
F_14 ( 1 , L_32 ,
F_6 ( V_57 -> V_25 [ V_57 -> V_20 - 1 ] ) ) ;
}
#endif
return 0 ;
}
static int F_49 ( struct V_55 * V_56 ,
struct V_89 * V_90 , int V_154 , struct V_58 * V_59 )
{
int V_38 = 0 ;
struct V_10 * V_93 , * V_94 ;
struct V_134 * V_155 ;
char * V_133 = ( ( char * ) V_90 ) + V_154 ;
T_4 V_97 ;
if ( V_90 == NULL )
return - V_51 ;
V_93 = (struct V_10 * ) ( ( char * ) V_90 +
F_6 ( V_90 -> V_99 ) ) ;
V_94 = (struct V_10 * ) ( ( char * ) V_90 +
F_6 ( V_90 -> V_100 ) ) ;
V_97 = F_6 ( V_90 -> V_97 ) ;
V_155 = (struct V_134 * ) ( ( char * ) V_90 + V_97 ) ;
F_14 ( V_117 , L_33
L_34 ,
V_90 -> V_22 , V_90 -> type , F_6 ( V_90 -> V_99 ) ,
F_6 ( V_90 -> V_100 ) ,
F_6 ( V_90 -> V_98 ) , V_97 ) ;
V_38 = F_48 ( V_93 , V_133 ) ;
if ( V_38 ) {
F_14 ( 1 , L_35 , V_48 , V_38 ) ;
return V_38 ;
}
V_38 = F_18 ( V_56 , V_93 , V_59 , V_21 ) ;
if ( V_38 ) {
F_14 ( 1 , L_36 , V_48 , V_38 ) ;
return V_38 ;
}
V_38 = F_48 ( V_94 , V_133 ) ;
if ( V_38 ) {
F_14 ( 1 , L_37 , V_48 , V_38 ) ;
return V_38 ;
}
V_38 = F_18 ( V_56 , V_94 , V_59 , V_156 ) ;
if ( V_38 ) {
F_14 ( 1 , L_38 , V_48 , V_38 ) ;
return V_38 ;
}
if ( V_97 )
F_45 ( V_155 , V_133 , V_93 ,
V_94 , V_59 ) ;
else
F_14 ( 1 , L_39 ) ;
return V_38 ;
}
static int F_50 ( struct V_89 * V_90 , struct V_89 * V_91 ,
T_4 V_157 , T_7 V_126 , T_2 V_66 , T_3 V_69 , int * V_158 )
{
int V_38 = 0 ;
T_4 V_97 ;
T_4 V_159 ;
T_4 V_92 ;
struct V_10 * V_93 , * V_94 ;
struct V_10 * V_95 , * V_96 ;
struct V_134 * V_155 = NULL ;
struct V_134 * V_160 = NULL ;
if ( V_126 != V_161 ) {
V_93 = (struct V_10 * ) ( ( char * ) V_90 +
F_6 ( V_90 -> V_99 ) ) ;
V_94 = (struct V_10 * ) ( ( char * ) V_90 +
F_6 ( V_90 -> V_100 ) ) ;
V_97 = F_6 ( V_90 -> V_97 ) ;
V_155 = (struct V_134 * ) ( ( char * ) V_90 + V_97 ) ;
V_159 = sizeof( struct V_89 ) ;
V_160 = (struct V_134 * ) ( ( char * ) V_91 + V_159 ) ;
V_160 -> V_22 = V_155 -> V_22 ;
V_160 -> V_128 = 0 ;
V_160 -> V_138 = 0 ;
V_38 = F_47 ( V_160 , V_93 , V_94 ,
V_126 ) ;
V_92 = V_159 + F_44 ( V_160 -> V_128 ) ;
F_36 ( V_90 , V_91 , V_92 ) ;
* V_158 = V_162 ;
} else {
memcpy ( V_91 , V_90 , V_157 ) ;
if ( F_22 ( V_66 ) ) {
V_64 V_67 ;
V_93 = (struct V_10 * ) ( ( char * ) V_91 +
F_6 ( V_91 -> V_99 ) ) ;
V_95 = F_2 ( sizeof( struct V_10 ) ,
V_8 ) ;
if ( ! V_95 )
return - V_9 ;
V_67 = F_51 ( & V_68 , V_66 ) ;
V_38 = F_10 ( V_67 , V_21 , V_95 ) ;
if ( V_38 ) {
F_14 ( 1 , L_40 ,
V_48 , V_38 , V_67 ) ;
F_4 ( V_95 ) ;
return V_38 ;
}
F_8 ( V_93 , V_95 ) ;
F_4 ( V_95 ) ;
* V_158 = V_163 ;
}
if ( F_24 ( V_69 ) ) {
V_65 V_67 ;
V_94 = (struct V_10 * ) ( ( char * ) V_91 +
F_6 ( V_91 -> V_100 ) ) ;
V_96 = F_2 ( sizeof( struct V_10 ) ,
V_8 ) ;
if ( ! V_96 )
return - V_9 ;
V_67 = F_52 ( & V_68 , V_69 ) ;
V_38 = F_10 ( V_67 , V_156 , V_96 ) ;
if ( V_38 ) {
F_14 ( 1 , L_41 ,
V_48 , V_38 , V_67 ) ;
F_4 ( V_96 ) ;
return V_38 ;
}
F_8 ( V_94 , V_96 ) ;
F_4 ( V_96 ) ;
* V_158 = V_164 ;
}
}
return V_38 ;
}
static struct V_89 * F_53 ( struct V_55 * V_56 ,
T_6 V_165 , T_9 * V_166 )
{
struct V_89 * V_90 = NULL ;
unsigned int V_167 ;
int V_38 ;
struct V_168 * V_169 = F_54 ( V_56 ) ;
if ( F_13 ( V_169 ) )
return F_55 ( V_169 ) ;
V_167 = F_56 () ;
V_38 = F_57 ( V_167 , F_58 ( V_169 ) , V_165 , & V_90 , V_166 ) ;
F_59 ( V_167 ) ;
F_60 ( V_169 ) ;
F_14 ( 1 , L_42 , V_48 , V_38 , * V_166 ) ;
if ( V_38 )
return F_61 ( V_38 ) ;
return V_90 ;
}
static struct V_89 * F_62 ( struct V_55 * V_56 ,
const char * V_170 , T_9 * V_166 )
{
struct V_89 * V_90 = NULL ;
int V_171 = 0 ;
unsigned int V_167 ;
int V_38 , V_172 = 0 ;
T_6 V_165 ;
struct V_173 * V_174 ;
struct V_168 * V_169 = F_54 ( V_56 ) ;
if ( F_13 ( V_169 ) )
return F_55 ( V_169 ) ;
V_174 = F_58 ( V_169 ) ;
V_167 = F_56 () ;
if ( F_63 ( V_56 ) )
V_172 |= V_175 ;
V_38 = F_64 ( V_167 , V_174 , V_170 , V_176 , V_177 ,
V_172 , & V_165 , & V_171 , NULL , V_56 -> V_178 ,
V_56 -> V_179 & V_180 ) ;
if ( ! V_38 ) {
V_38 = F_57 ( V_167 , V_174 , V_165 , & V_90 , V_166 ) ;
F_65 ( V_167 , V_174 , V_165 ) ;
}
F_60 ( V_169 ) ;
F_59 ( V_167 ) ;
F_14 ( 1 , L_42 , V_48 , V_38 , * V_166 ) ;
if ( V_38 )
return F_61 ( V_38 ) ;
return V_90 ;
}
struct V_89 * F_66 ( struct V_55 * V_56 ,
struct V_181 * V_181 , const char * V_170 ,
T_9 * V_166 )
{
struct V_89 * V_90 = NULL ;
struct V_182 * V_183 = NULL ;
if ( V_181 )
V_183 = F_67 ( F_68 ( V_181 ) , true ) ;
if ( ! V_183 )
return F_62 ( V_56 , V_170 , V_166 ) ;
V_90 = F_53 ( V_56 , V_183 -> V_165 . V_184 , V_166 ) ;
F_69 ( V_183 ) ;
return V_90 ;
}
int F_70 ( struct V_89 * V_91 , T_4 V_185 ,
struct V_181 * V_181 , const char * V_170 , int V_158 )
{
int V_171 = 0 ;
unsigned int V_167 ;
int V_38 , V_186 , V_172 = 0 ;
T_6 V_165 ;
struct V_173 * V_174 ;
struct V_55 * V_56 = F_71 ( V_181 -> V_187 ) ;
struct V_168 * V_169 = F_54 ( V_56 ) ;
if ( F_13 ( V_169 ) )
return F_28 ( V_169 ) ;
V_174 = F_58 ( V_169 ) ;
V_167 = F_56 () ;
if ( F_63 ( V_56 ) )
V_172 |= V_175 ;
if ( V_158 == V_163 || V_158 == V_164 )
V_186 = V_188 ;
else
V_186 = V_189 ;
V_38 = F_64 ( V_167 , V_174 , V_170 , V_176 , V_186 ,
V_172 , & V_165 , & V_171 , NULL , V_56 -> V_178 ,
V_56 -> V_179 & V_180 ) ;
if ( V_38 ) {
F_39 ( 1 , L_43 ) ;
goto V_190;
}
V_38 = F_72 ( V_167 , V_174 , V_165 , V_91 , V_185 , V_158 ) ;
F_14 ( V_117 , L_44 , V_38 ) ;
F_65 ( V_167 , V_174 , V_165 ) ;
V_190:
F_59 ( V_167 ) ;
F_60 ( V_169 ) ;
return V_38 ;
}
int
F_73 ( struct V_55 * V_56 , struct V_58 * V_59 ,
struct V_181 * V_181 , const char * V_170 , const T_6 * V_191 )
{
struct V_89 * V_90 = NULL ;
T_9 V_185 = 0 ;
int V_38 = 0 ;
F_14 ( V_117 , L_45 , V_170 ) ;
if ( V_191 )
V_90 = F_53 ( V_56 , * V_191 , & V_185 ) ;
else
V_90 = F_66 ( V_56 , V_181 , V_170 , & V_185 ) ;
if ( F_13 ( V_90 ) ) {
V_38 = F_28 ( V_90 ) ;
F_39 ( 1 , L_46 , V_48 , V_38 ) ;
} else {
V_38 = F_49 ( V_56 , V_90 , V_185 , V_59 ) ;
F_4 ( V_90 ) ;
if ( V_38 )
F_39 ( 1 , L_47 , V_38 ) ;
}
return V_38 ;
}
int
F_74 ( struct V_181 * V_181 , const char * V_170 , T_7 V_126 ,
T_2 V_66 , T_3 V_69 )
{
int V_38 = 0 ;
int V_158 = V_162 ;
T_4 V_157 = 0 ;
struct V_89 * V_90 = NULL ;
struct V_89 * V_91 = NULL ;
F_14 ( V_117 , L_48 , V_170 ) ;
V_90 = F_66 ( F_71 ( V_181 -> V_187 ) , V_181 , V_170 , & V_157 ) ;
if ( F_13 ( V_90 ) ) {
V_38 = F_28 ( V_90 ) ;
F_39 ( 1 , L_46 , V_48 , V_38 ) ;
goto V_190;
}
V_157 = F_75 ( T_9 , V_157 , V_192 ) ;
V_91 = F_2 ( V_157 , V_8 ) ;
if ( ! V_91 ) {
F_39 ( 1 , L_49 ) ;
F_4 ( V_90 ) ;
return - V_9 ;
}
V_38 = F_50 ( V_90 , V_91 , V_157 , V_126 , V_66 , V_69 ,
& V_158 ) ;
F_14 ( V_117 , L_50 , V_38 ) ;
if ( ! V_38 ) {
V_38 = F_70 ( V_91 , V_157 , V_181 , V_170 , V_158 ) ;
F_14 ( V_117 , L_51 , V_38 ) ;
}
F_4 ( V_91 ) ;
F_4 ( V_90 ) ;
V_190:
return V_38 ;
}
