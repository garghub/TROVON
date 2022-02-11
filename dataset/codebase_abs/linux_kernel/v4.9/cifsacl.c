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
static bool
F_9 ( const struct V_9 * V_30 , T_1 * V_31 , bool V_32 )
{
int V_11 ;
int V_19 ;
const struct V_9 * V_33 ;
if ( ! V_30 || ( V_31 == NULL ) )
return false ;
V_19 = V_30 -> V_19 ;
if ( V_19 == 2 ) {
if ( V_32 )
V_33 = & V_34 ;
else
V_33 = & V_35 ;
} else if ( V_19 == 3 ) {
if ( V_32 )
V_33 = & V_36 ;
else
V_33 = & V_37 ;
} else
return false ;
if ( V_30 -> V_21 != V_33 -> V_21 )
return false ;
for ( V_11 = 0 ; V_11 < V_29 ; ++ V_11 ) {
if ( V_30 -> V_22 [ V_11 ] != V_33 -> V_22 [ V_11 ] ) {
F_10 ( V_38 , L_5 , V_11 ) ;
return false ;
}
}
if ( V_19 == 2 ) {
if ( V_30 -> V_24 [ 0 ] != V_33 -> V_24 [ 0 ] )
return false ;
* V_31 = F_7 ( V_30 -> V_24 [ 1 ] ) ;
} else {
* V_31 = F_7 ( V_30 -> V_24 [ 0 ] ) ;
if ( ( V_30 -> V_24 [ 0 ] != V_33 -> V_24 [ 0 ] ) ||
( V_30 -> V_24 [ 1 ] != V_33 -> V_24 [ 1 ] ) )
return false ;
* V_31 = F_7 ( V_30 -> V_24 [ 2 ] ) ;
}
F_10 ( V_38 , L_6 , * V_31 ) ;
return true ;
}
static void
F_11 ( struct V_9 * V_39 , const struct V_9 * V_40 )
{
int V_11 ;
V_39 -> V_21 = V_40 -> V_21 ;
V_39 -> V_19 = F_12 ( V_41 , V_40 -> V_19 , V_42 ) ;
for ( V_11 = 0 ; V_11 < V_29 ; ++ V_11 )
V_39 -> V_22 [ V_11 ] = V_40 -> V_22 [ V_11 ] ;
for ( V_11 = 0 ; V_11 < V_39 -> V_19 ; ++ V_11 )
V_39 -> V_24 [ V_11 ] = V_40 -> V_24 [ V_11 ] ;
}
static int
F_13 ( unsigned int V_43 , T_2 V_44 , struct V_9 * V_45 )
{
int V_46 ;
struct V_1 * V_47 ;
struct V_9 * V_48 ;
unsigned int V_49 ;
char V_50 [ 3 + 10 + 1 ] ;
const struct V_51 * V_52 ;
V_46 = snprintf ( V_50 , sizeof( V_50 ) , L_7 ,
V_44 == V_20 ? 'o' : 'g' , V_43 ) ;
if ( V_46 >= sizeof( V_50 ) )
return - V_53 ;
V_46 = 0 ;
V_52 = F_14 ( V_54 ) ;
V_47 = F_15 ( & V_55 , V_50 , L_8 ) ;
if ( F_16 ( V_47 ) ) {
V_46 = - V_53 ;
F_10 ( V_38 , L_9 ,
V_56 , V_44 == V_20 ? 'u' : 'g' , V_43 ) ;
goto V_57;
} else if ( V_47 -> V_5 < V_58 ) {
V_46 = - V_59 ;
F_10 ( V_38 , L_10 ,
V_56 , V_47 -> V_5 ) ;
goto V_60;
}
V_48 = V_47 -> V_5 <= sizeof( V_47 -> V_4 ) ?
(struct V_9 * ) & V_47 -> V_4 :
(struct V_9 * ) V_47 -> V_4 . V_6 [ 0 ] ;
V_49 = V_58 + ( V_48 -> V_19 * sizeof( V_61 ) ) ;
if ( V_49 > V_47 -> V_5 ) {
V_46 = - V_59 ;
F_10 ( V_38 , L_11 ,
V_56 , V_47 -> V_5 , V_49 ) ;
goto V_60;
}
F_11 ( V_45 , V_48 ) ;
V_62:
F_17 ( V_47 ) ;
V_57:
F_18 ( V_52 ) ;
return V_46 ;
V_60:
F_19 ( V_47 ) ;
goto V_62;
}
static int
F_20 ( struct V_63 * V_64 , struct V_9 * V_30 ,
struct V_65 * V_66 , T_2 V_44 )
{
int V_46 ;
struct V_1 * V_47 ;
char * V_14 ;
const struct V_51 * V_52 ;
T_3 V_67 = V_64 -> V_68 ;
T_4 V_69 = V_64 -> V_70 ;
if ( F_21 ( V_30 -> V_19 > V_42 ) ) {
F_10 ( V_38 , L_12 ,
V_56 , V_30 -> V_19 ) ;
return - V_59 ;
}
if ( V_64 -> V_71 & V_72 ) {
T_1 V_73 ;
bool V_32 ;
if ( V_44 != V_20 )
V_32 = true ;
else
V_32 = false ;
if ( F_9 ( V_30 , & V_73 , V_32 ) == false )
goto V_74;
if ( V_32 ) {
T_4 V_75 ;
T_5 V_76 ;
V_76 = ( T_5 ) V_73 ;
V_75 = F_22 ( & V_77 , V_76 ) ;
if ( F_23 ( V_75 ) ) {
V_69 = V_75 ;
goto V_78;
}
} else {
T_3 V_79 ;
T_6 V_76 ;
V_76 = ( T_6 ) V_73 ;
V_79 = F_24 ( & V_77 , V_76 ) ;
if ( F_25 ( V_79 ) ) {
V_67 = V_79 ;
goto V_78;
}
}
}
V_74:
V_14 = F_5 ( V_30 , V_44 ) ;
if ( ! V_14 )
return - V_8 ;
V_52 = F_14 ( V_54 ) ;
V_47 = F_15 ( & V_55 , V_14 , L_8 ) ;
if ( F_16 ( V_47 ) ) {
V_46 = - V_53 ;
F_10 ( V_38 , L_13 ,
V_56 , V_14 , V_44 == V_20 ? 'u' : 'g' ) ;
goto V_57;
}
F_26 ( sizeof( T_6 ) != sizeof( T_5 ) ) ;
if ( V_47 -> V_5 != sizeof( T_6 ) ) {
V_46 = - V_59 ;
F_10 ( V_38 , L_10 ,
V_56 , V_47 -> V_5 ) ;
F_19 ( V_47 ) ;
goto V_62;
}
if ( V_44 == V_20 ) {
T_3 V_79 ;
T_6 V_76 ;
memcpy ( & V_76 , & V_47 -> V_4 . V_6 [ 0 ] , sizeof( T_6 ) ) ;
V_79 = F_24 ( & V_77 , V_76 ) ;
if ( F_25 ( V_79 ) )
V_67 = V_79 ;
} else {
T_4 V_75 ;
T_5 V_76 ;
memcpy ( & V_76 , & V_47 -> V_4 . V_6 [ 0 ] , sizeof( T_5 ) ) ;
V_75 = F_22 ( & V_77 , V_76 ) ;
if ( F_23 ( V_75 ) )
V_69 = V_75 ;
}
V_62:
F_17 ( V_47 ) ;
V_57:
F_18 ( V_52 ) ;
F_4 ( V_14 ) ;
V_78:
if ( V_44 == V_20 )
V_66 -> V_80 = V_67 ;
else
V_66 -> V_81 = V_69 ;
return 0 ;
}
int
F_27 ( void )
{
struct V_51 * V_51 ;
struct V_1 * V_82 ;
int V_83 ;
F_10 ( V_38 , L_14 ,
V_55 . V_84 ) ;
V_51 = F_28 ( NULL ) ;
if ( ! V_51 )
return - V_8 ;
V_82 = F_29 ( L_15 ,
V_85 , V_86 , V_51 ,
( V_87 & ~ V_88 ) |
V_89 | V_90 ,
V_91 , NULL , NULL ) ;
if ( F_16 ( V_82 ) ) {
V_83 = F_30 ( V_82 ) ;
goto V_92;
}
V_83 = F_31 ( & V_55 ) ;
if ( V_83 < 0 )
goto V_93;
F_32 ( V_94 , & V_82 -> V_95 ) ;
V_51 -> V_96 = V_82 ;
V_51 -> V_97 = V_98 ;
V_54 = V_51 ;
F_10 ( V_38 , L_16 , F_33 ( V_82 ) ) ;
return 0 ;
V_93:
F_17 ( V_82 ) ;
V_92:
F_34 ( V_51 ) ;
return V_83 ;
}
void
F_35 ( void )
{
F_36 ( V_54 -> V_96 ) ;
F_37 ( & V_55 ) ;
F_34 ( V_54 ) ;
F_10 ( V_38 , L_17 , V_55 . V_84 ) ;
}
static void F_38 ( const struct V_99 * V_100 ,
struct V_99 * V_101 , T_7 V_102 )
{
struct V_9 * V_103 , * V_104 ;
struct V_9 * V_105 , * V_106 ;
V_101 -> V_21 = V_100 -> V_21 ;
V_101 -> type = V_100 -> type ;
V_101 -> V_107 = F_39 ( sizeof( struct V_99 ) ) ;
V_101 -> V_108 = 0 ;
V_101 -> V_109 = F_39 ( V_102 ) ;
V_101 -> V_110 = F_39 ( V_102 + sizeof( struct V_9 ) ) ;
V_103 = (struct V_9 * ) ( ( char * ) V_100 +
F_7 ( V_100 -> V_109 ) ) ;
V_105 = (struct V_9 * ) ( ( char * ) V_101 + V_102 ) ;
F_11 ( V_105 , V_103 ) ;
V_104 = (struct V_9 * ) ( ( char * ) V_100 +
F_7 ( V_100 -> V_110 ) ) ;
V_106 = (struct V_9 * ) ( ( char * ) V_101 + V_102 +
sizeof( struct V_9 ) ) ;
F_11 ( V_106 , V_104 ) ;
return;
}
static void F_40 ( V_61 V_111 , int type , T_8 * V_112 ,
T_8 * V_113 )
{
T_7 V_95 = F_7 ( V_111 ) ;
if ( type == V_114 ) {
if ( V_95 & V_115 )
* V_113 &= ~ V_116 ;
if ( ( V_95 & V_117 ) ||
( ( V_95 & V_118 ) == V_118 ) )
* V_113 &= ~ V_119 ;
if ( ( V_95 & V_120 ) ||
( ( V_95 & V_121 ) == V_121 ) )
* V_113 &= ~ V_122 ;
if ( ( V_95 & V_123 ) ||
( ( V_95 & V_124 ) == V_124 ) )
* V_113 &= ~ V_125 ;
return;
} else if ( type != V_126 ) {
F_10 ( V_127 , L_18 , type ) ;
return;
}
if ( V_95 & V_115 ) {
* V_112 |= ( V_116 & ( * V_113 ) ) ;
F_10 ( V_128 , L_19 ) ;
return;
}
if ( ( V_95 & V_117 ) ||
( ( V_95 & V_118 ) == V_118 ) )
* V_112 |= ( V_119 & ( * V_113 ) ) ;
if ( ( V_95 & V_120 ) ||
( ( V_95 & V_121 ) == V_121 ) )
* V_112 |= ( V_122 & ( * V_113 ) ) ;
if ( ( V_95 & V_123 ) ||
( ( V_95 & V_124 ) == V_124 ) )
* V_112 |= ( V_125 & ( * V_113 ) ) ;
F_10 ( V_128 , L_20 , V_95 , * V_112 ) ;
return;
}
static void F_41 ( T_8 V_129 , T_8 V_130 ,
T_7 * V_131 )
{
* V_131 = 0x0 ;
V_129 &= V_130 ;
if ( V_129 & V_122 )
* V_131 |= V_132 ;
if ( V_129 & V_119 )
* V_131 |= V_133 ;
if ( V_129 & V_125 )
* V_131 |= V_134 ;
F_10 ( V_128 , L_21 ,
V_129 , * V_131 ) ;
return;
}
static T_9 F_42 ( struct V_135 * V_136 ,
const struct V_9 * V_30 , T_10 V_137 , T_8 V_138 )
{
int V_11 ;
T_9 V_139 = 0 ;
T_7 V_140 = 0 ;
V_136 -> type = V_126 ;
V_136 -> V_95 = 0x0 ;
F_41 ( V_137 , V_138 , & V_140 ) ;
if ( ! V_140 )
V_140 = V_141 ;
V_136 -> V_140 = F_39 ( V_140 ) ;
V_136 -> V_142 . V_21 = V_30 -> V_21 ;
V_136 -> V_142 . V_19 = V_30 -> V_19 ;
for ( V_11 = 0 ; V_11 < V_29 ; V_11 ++ )
V_136 -> V_142 . V_22 [ V_11 ] = V_30 -> V_22 [ V_11 ] ;
for ( V_11 = 0 ; V_11 < V_30 -> V_19 ; V_11 ++ )
V_136 -> V_142 . V_24 [ V_11 ] = V_30 -> V_24 [ V_11 ] ;
V_139 = 1 + 1 + 2 + 4 + 1 + 1 + 6 + ( V_30 -> V_19 * 4 ) ;
V_136 -> V_139 = F_43 ( V_139 ) ;
return V_139 ;
}
static void F_44 ( struct V_135 * V_143 , char * V_144 )
{
int V_19 ;
if ( F_45 ( V_143 -> V_139 ) < 16 ) {
F_10 ( V_127 , L_22 , F_45 ( V_143 -> V_139 ) ) ;
return;
}
if ( V_144 < ( char * ) V_143 + F_45 ( V_143 -> V_139 ) ) {
F_10 ( V_127 , L_23 ) ;
return;
}
V_19 = V_143 -> V_142 . V_19 ;
if ( V_19 ) {
int V_11 ;
F_10 ( V_38 , L_24 ,
V_143 -> V_142 . V_21 , V_143 -> V_142 . V_19 , V_143 -> type ,
V_143 -> V_95 , F_45 ( V_143 -> V_139 ) ) ;
for ( V_11 = 0 ; V_11 < V_19 ; ++ V_11 ) {
F_10 ( V_38 , L_25 ,
V_11 , F_7 ( V_143 -> V_142 . V_24 [ V_11 ] ) ) ;
}
}
return;
}
static void F_46 ( struct V_145 * V_146 , char * V_144 ,
struct V_9 * V_147 , struct V_9 * V_148 ,
struct V_65 * V_66 )
{
int V_11 ;
int V_149 = 0 ;
int V_150 ;
char * V_151 ;
struct V_135 * * V_152 ;
if ( ! V_146 ) {
V_66 -> V_153 |= V_116 ;
return;
}
if ( V_144 < ( char * ) V_146 + F_45 ( V_146 -> V_139 ) ) {
F_10 ( V_127 , L_26 ) ;
return;
}
F_10 ( V_128 , L_27 ,
F_45 ( V_146 -> V_21 ) , F_45 ( V_146 -> V_139 ) ,
F_7 ( V_146 -> V_149 ) ) ;
V_66 -> V_153 &= ~ ( V_116 ) ;
V_151 = ( char * ) V_146 ;
V_150 = sizeof( struct V_145 ) ;
V_149 = F_7 ( V_146 -> V_149 ) ;
if ( V_149 > 0 ) {
T_8 V_154 = V_155 ;
T_8 V_156 = V_157 ;
T_8 V_158 = V_155 | V_157 | V_159 ;
if ( V_149 > V_160 / sizeof( struct V_135 * ) )
return;
V_152 = F_6 ( V_149 * sizeof( struct V_135 * ) ,
V_7 ) ;
if ( ! V_152 )
return;
for ( V_11 = 0 ; V_11 < V_149 ; ++ V_11 ) {
V_152 [ V_11 ] = (struct V_135 * ) ( V_151 + V_150 ) ;
#ifdef F_47
F_44 ( V_152 [ V_11 ] , V_144 ) ;
#endif
if ( F_8 ( & ( V_152 [ V_11 ] -> V_142 ) , V_147 ) == 0 )
F_40 ( V_152 [ V_11 ] -> V_140 ,
V_152 [ V_11 ] -> type ,
& V_66 -> V_153 ,
& V_154 ) ;
if ( F_8 ( & ( V_152 [ V_11 ] -> V_142 ) , V_148 ) == 0 )
F_40 ( V_152 [ V_11 ] -> V_140 ,
V_152 [ V_11 ] -> type ,
& V_66 -> V_153 ,
& V_156 ) ;
if ( F_8 ( & ( V_152 [ V_11 ] -> V_142 ) , & V_161 ) == 0 )
F_40 ( V_152 [ V_11 ] -> V_140 ,
V_152 [ V_11 ] -> type ,
& V_66 -> V_153 ,
& V_158 ) ;
if ( F_8 ( & ( V_152 [ V_11 ] -> V_142 ) , & V_162 ) == 0 )
F_40 ( V_152 [ V_11 ] -> V_140 ,
V_152 [ V_11 ] -> type ,
& V_66 -> V_153 ,
& V_158 ) ;
V_151 = ( char * ) V_152 [ V_11 ] ;
V_150 = F_45 ( V_152 [ V_11 ] -> V_139 ) ;
}
F_4 ( V_152 ) ;
}
return;
}
static int F_48 ( struct V_145 * V_163 , struct V_9 * V_147 ,
struct V_9 * V_148 , T_10 V_137 )
{
T_11 V_139 = 0 ;
struct V_145 * V_164 ;
V_164 = (struct V_145 * ) ( ( char * ) V_163 + sizeof( struct V_145 ) ) ;
V_139 += F_42 ( (struct V_135 * ) ( ( char * ) V_164 + V_139 ) ,
V_147 , V_137 , V_155 ) ;
V_139 += F_42 ( (struct V_135 * ) ( ( char * ) V_164 + V_139 ) ,
V_148 , V_137 , V_157 ) ;
V_139 += F_42 ( (struct V_135 * ) ( ( char * ) V_164 + V_139 ) ,
& V_161 , V_137 , V_159 ) ;
V_163 -> V_139 = F_43 ( V_139 + sizeof( struct V_145 ) ) ;
V_163 -> V_149 = F_39 ( 3 ) ;
return 0 ;
}
static int F_49 ( struct V_9 * V_30 , char * V_144 )
{
if ( V_144 < ( char * ) V_30 + 8 ) {
F_10 ( V_127 , L_28 , V_30 ) ;
return - V_53 ;
}
#ifdef F_47
if ( V_30 -> V_19 ) {
int V_11 ;
F_10 ( V_38 , L_29 ,
V_30 -> V_21 , V_30 -> V_19 ) ;
for ( V_11 = 0 ; V_11 < V_30 -> V_19 ; V_11 ++ ) {
F_10 ( V_38 , L_30 ,
V_11 , F_7 ( V_30 -> V_24 [ V_11 ] ) ) ;
}
F_10 ( V_38 , L_31 ,
F_7 ( V_30 -> V_24 [ V_30 -> V_19 - 1 ] ) ) ;
}
#endif
return 0 ;
}
static int F_50 ( struct V_63 * V_64 ,
struct V_99 * V_100 , int V_165 , struct V_65 * V_66 )
{
int V_46 = 0 ;
struct V_9 * V_103 , * V_104 ;
struct V_145 * V_166 ;
char * V_144 = ( ( char * ) V_100 ) + V_165 ;
T_7 V_107 ;
if ( V_100 == NULL )
return - V_59 ;
V_103 = (struct V_9 * ) ( ( char * ) V_100 +
F_7 ( V_100 -> V_109 ) ) ;
V_104 = (struct V_9 * ) ( ( char * ) V_100 +
F_7 ( V_100 -> V_110 ) ) ;
V_107 = F_7 ( V_100 -> V_107 ) ;
V_166 = (struct V_145 * ) ( ( char * ) V_100 + V_107 ) ;
F_10 ( V_128 , L_32 ,
V_100 -> V_21 , V_100 -> type , F_7 ( V_100 -> V_109 ) ,
F_7 ( V_100 -> V_110 ) ,
F_7 ( V_100 -> V_108 ) , V_107 ) ;
V_46 = F_49 ( V_103 , V_144 ) ;
if ( V_46 ) {
F_10 ( V_38 , L_33 , V_56 , V_46 ) ;
return V_46 ;
}
V_46 = F_20 ( V_64 , V_103 , V_66 , V_20 ) ;
if ( V_46 ) {
F_10 ( V_38 , L_34 ,
V_56 , V_46 ) ;
return V_46 ;
}
V_46 = F_49 ( V_104 , V_144 ) ;
if ( V_46 ) {
F_10 ( V_38 , L_35 ,
V_56 , V_46 ) ;
return V_46 ;
}
V_46 = F_20 ( V_64 , V_104 , V_66 , V_167 ) ;
if ( V_46 ) {
F_10 ( V_38 , L_36 ,
V_56 , V_46 ) ;
return V_46 ;
}
if ( V_107 )
F_46 ( V_166 , V_144 , V_103 ,
V_104 , V_66 ) ;
else
F_10 ( V_38 , L_37 ) ;
return V_46 ;
}
static int F_51 ( struct V_99 * V_100 , struct V_99 * V_101 ,
T_7 V_168 , T_10 V_137 , T_3 V_79 , T_4 V_75 , int * V_169 )
{
int V_46 = 0 ;
T_7 V_107 ;
T_7 V_170 ;
T_7 V_102 ;
struct V_9 * V_103 , * V_104 ;
struct V_9 * V_105 , * V_106 ;
struct V_145 * V_166 = NULL ;
struct V_145 * V_171 = NULL ;
if ( V_137 != V_172 ) {
V_103 = (struct V_9 * ) ( ( char * ) V_100 +
F_7 ( V_100 -> V_109 ) ) ;
V_104 = (struct V_9 * ) ( ( char * ) V_100 +
F_7 ( V_100 -> V_110 ) ) ;
V_107 = F_7 ( V_100 -> V_107 ) ;
V_166 = (struct V_145 * ) ( ( char * ) V_100 + V_107 ) ;
V_170 = sizeof( struct V_99 ) ;
V_171 = (struct V_145 * ) ( ( char * ) V_101 + V_170 ) ;
V_171 -> V_21 = V_166 -> V_21 ;
V_171 -> V_139 = 0 ;
V_171 -> V_149 = 0 ;
V_46 = F_48 ( V_171 , V_103 , V_104 ,
V_137 ) ;
V_102 = V_170 + F_45 ( V_171 -> V_139 ) ;
F_38 ( V_100 , V_101 , V_102 ) ;
* V_169 = V_173 ;
} else {
memcpy ( V_101 , V_100 , V_168 ) ;
if ( F_25 ( V_79 ) ) {
T_6 V_76 ;
V_103 = (struct V_9 * ) ( ( char * ) V_101 +
F_7 ( V_101 -> V_109 ) ) ;
V_105 = F_6 ( sizeof( struct V_9 ) ,
V_7 ) ;
if ( ! V_105 )
return - V_8 ;
V_76 = F_52 ( & V_77 , V_79 ) ;
V_46 = F_13 ( V_76 , V_20 , V_105 ) ;
if ( V_46 ) {
F_10 ( V_38 , L_38 ,
V_56 , V_46 , V_76 ) ;
F_4 ( V_105 ) ;
return V_46 ;
}
F_11 ( V_103 , V_105 ) ;
F_4 ( V_105 ) ;
* V_169 = V_174 ;
}
if ( F_23 ( V_75 ) ) {
T_5 V_76 ;
V_104 = (struct V_9 * ) ( ( char * ) V_101 +
F_7 ( V_101 -> V_110 ) ) ;
V_106 = F_6 ( sizeof( struct V_9 ) ,
V_7 ) ;
if ( ! V_106 )
return - V_8 ;
V_76 = F_53 ( & V_77 , V_75 ) ;
V_46 = F_13 ( V_76 , V_167 , V_106 ) ;
if ( V_46 ) {
F_10 ( V_38 , L_39 ,
V_56 , V_46 , V_76 ) ;
F_4 ( V_106 ) ;
return V_46 ;
}
F_11 ( V_104 , V_106 ) ;
F_4 ( V_106 ) ;
* V_169 = V_175 ;
}
}
return V_46 ;
}
struct V_99 * F_54 ( struct V_63 * V_64 ,
const struct V_176 * V_177 , T_12 * V_178 )
{
struct V_99 * V_100 = NULL ;
unsigned int V_179 ;
int V_46 ;
struct V_180 * V_181 = F_55 ( V_64 ) ;
if ( F_16 ( V_181 ) )
return F_56 ( V_181 ) ;
V_179 = F_57 () ;
V_46 = F_58 ( V_179 , F_59 ( V_181 ) , V_177 -> V_182 , & V_100 ,
V_178 ) ;
F_60 ( V_179 ) ;
F_61 ( V_181 ) ;
F_10 ( V_38 , L_40 , V_56 , V_46 , * V_178 ) ;
if ( V_46 )
return F_62 ( V_46 ) ;
return V_100 ;
}
static struct V_99 * F_63 ( struct V_63 * V_64 ,
const char * V_183 , T_12 * V_178 )
{
struct V_99 * V_100 = NULL ;
int V_184 = 0 ;
unsigned int V_179 ;
int V_46 , V_185 = 0 ;
struct V_186 * V_187 ;
struct V_180 * V_181 = F_55 ( V_64 ) ;
struct V_176 V_188 ;
struct V_189 V_190 ;
if ( F_16 ( V_181 ) )
return F_56 ( V_181 ) ;
V_187 = F_59 ( V_181 ) ;
V_179 = F_57 () ;
if ( F_64 ( V_64 ) )
V_185 |= V_191 ;
V_190 . V_187 = V_187 ;
V_190 . V_64 = V_64 ;
V_190 . V_192 = V_193 ;
V_190 . V_185 = V_185 ;
V_190 . V_194 = V_195 ;
V_190 . V_183 = V_183 ;
V_190 . V_188 = & V_188 ;
V_190 . V_196 = false ;
V_46 = F_65 ( V_179 , & V_190 , & V_184 , NULL ) ;
if ( ! V_46 ) {
V_46 = F_58 ( V_179 , V_187 , V_188 . V_182 , & V_100 , V_178 ) ;
F_66 ( V_179 , V_187 , V_188 . V_182 ) ;
}
F_61 ( V_181 ) ;
F_60 ( V_179 ) ;
F_10 ( V_38 , L_40 , V_56 , V_46 , * V_178 ) ;
if ( V_46 )
return F_62 ( V_46 ) ;
return V_100 ;
}
struct V_99 * F_67 ( struct V_63 * V_64 ,
struct V_197 * V_197 , const char * V_183 ,
T_12 * V_178 )
{
struct V_99 * V_100 = NULL ;
struct V_198 * V_199 = NULL ;
if ( V_197 )
V_199 = F_68 ( F_69 ( V_197 ) , true ) ;
if ( ! V_199 )
return F_63 ( V_64 , V_183 , V_178 ) ;
V_100 = F_54 ( V_64 , & V_199 -> V_188 , V_178 ) ;
F_70 ( V_199 ) ;
return V_100 ;
}
int F_71 ( struct V_99 * V_101 , T_7 V_200 ,
struct V_197 * V_197 , const char * V_183 , int V_169 )
{
int V_184 = 0 ;
unsigned int V_179 ;
int V_46 , V_201 , V_185 = 0 ;
struct V_186 * V_187 ;
struct V_63 * V_64 = F_72 ( V_197 -> V_202 ) ;
struct V_180 * V_181 = F_55 ( V_64 ) ;
struct V_176 V_188 ;
struct V_189 V_190 ;
if ( F_16 ( V_181 ) )
return F_30 ( V_181 ) ;
V_187 = F_59 ( V_181 ) ;
V_179 = F_57 () ;
if ( F_64 ( V_64 ) )
V_185 |= V_191 ;
if ( V_169 == V_174 || V_169 == V_175 )
V_201 = V_203 ;
else
V_201 = V_204 ;
V_190 . V_187 = V_187 ;
V_190 . V_64 = V_64 ;
V_190 . V_192 = V_201 ;
V_190 . V_185 = V_185 ;
V_190 . V_194 = V_195 ;
V_190 . V_183 = V_183 ;
V_190 . V_188 = & V_188 ;
V_190 . V_196 = false ;
V_46 = F_65 ( V_179 , & V_190 , & V_184 , NULL ) ;
if ( V_46 ) {
F_10 ( V_127 , L_41 ) ;
goto V_205;
}
V_46 = F_73 ( V_179 , V_187 , V_188 . V_182 , V_101 , V_200 , V_169 ) ;
F_10 ( V_128 , L_42 , V_46 ) ;
F_66 ( V_179 , V_187 , V_188 . V_182 ) ;
V_205:
F_60 ( V_179 ) ;
F_61 ( V_181 ) ;
return V_46 ;
}
int
F_74 ( struct V_63 * V_64 , struct V_65 * V_66 ,
struct V_197 * V_197 , const char * V_183 ,
const struct V_176 * V_206 )
{
struct V_99 * V_100 = NULL ;
T_12 V_200 = 0 ;
int V_46 = 0 ;
struct V_180 * V_181 = F_55 ( V_64 ) ;
struct V_186 * V_187 ;
F_10 ( V_128 , L_43 , V_183 ) ;
if ( F_16 ( V_181 ) )
return F_30 ( V_181 ) ;
V_187 = F_59 ( V_181 ) ;
if ( V_206 && ( V_187 -> V_207 -> V_208 -> V_209 -> V_210 ) )
V_100 = V_187 -> V_207 -> V_208 -> V_209 -> V_210 ( V_64 , V_206 ,
& V_200 ) ;
else if ( V_187 -> V_207 -> V_208 -> V_209 -> V_211 )
V_100 = V_187 -> V_207 -> V_208 -> V_209 -> V_211 ( V_64 , V_197 , V_183 ,
& V_200 ) ;
else {
F_61 ( V_181 ) ;
return - V_212 ;
}
if ( F_16 ( V_100 ) ) {
V_46 = F_30 ( V_100 ) ;
F_10 ( V_127 , L_44 , V_56 , V_46 ) ;
} else {
V_46 = F_50 ( V_64 , V_100 , V_200 , V_66 ) ;
F_4 ( V_100 ) ;
if ( V_46 )
F_10 ( V_127 , L_45 , V_46 ) ;
}
F_61 ( V_181 ) ;
return V_46 ;
}
int
F_75 ( struct V_197 * V_197 , const char * V_183 , T_10 V_137 ,
T_3 V_79 , T_4 V_75 )
{
int V_46 = 0 ;
int V_169 = V_173 ;
T_7 V_168 = 0 ;
struct V_99 * V_100 = NULL ;
struct V_99 * V_101 = NULL ;
struct V_63 * V_64 = F_72 ( V_197 -> V_202 ) ;
struct V_180 * V_181 = F_55 ( V_64 ) ;
struct V_186 * V_187 ;
if ( F_16 ( V_181 ) )
return F_30 ( V_181 ) ;
V_187 = F_59 ( V_181 ) ;
F_10 ( V_128 , L_46 , V_183 ) ;
if ( V_187 -> V_207 -> V_208 -> V_209 -> V_211 == NULL ) {
F_61 ( V_181 ) ;
return - V_212 ;
}
V_100 = V_187 -> V_207 -> V_208 -> V_209 -> V_211 ( V_64 , V_197 , V_183 ,
& V_168 ) ;
if ( F_16 ( V_100 ) ) {
V_46 = F_30 ( V_100 ) ;
F_10 ( V_127 , L_44 , V_56 , V_46 ) ;
F_61 ( V_181 ) ;
return V_46 ;
}
V_168 = F_76 ( T_12 , V_168 , V_213 ) ;
V_101 = F_6 ( V_168 , V_7 ) ;
if ( ! V_101 ) {
F_4 ( V_100 ) ;
F_61 ( V_181 ) ;
return - V_8 ;
}
V_46 = F_51 ( V_100 , V_101 , V_168 , V_137 , V_79 , V_75 ,
& V_169 ) ;
F_10 ( V_128 , L_47 , V_46 ) ;
if ( V_187 -> V_207 -> V_208 -> V_209 -> V_214 == NULL )
V_46 = - V_212 ;
if ( ! V_46 ) {
V_46 = V_187 -> V_207 -> V_208 -> V_209 -> V_214 ( V_101 , V_168 , V_197 ,
V_183 , V_169 ) ;
F_10 ( V_128 , L_48 , V_46 ) ;
}
F_61 ( V_181 ) ;
F_4 ( V_101 ) ;
F_4 ( V_100 ) ;
return V_46 ;
}
