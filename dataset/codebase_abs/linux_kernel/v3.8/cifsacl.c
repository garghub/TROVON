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
if ( V_39 -> V_5 != sizeof( T_2 ) ) {
V_38 = - V_51 ;
F_14 ( 1 , L_8
L_9 , V_48 , V_39 -> V_5 ) ;
F_17 ( V_39 ) ;
goto V_54;
}
if ( V_36 == V_21 )
memcpy ( & V_60 , & V_39 -> V_4 . V_6 , sizeof( T_2 ) ) ;
else
memcpy ( & V_62 , & V_39 -> V_4 . V_6 , sizeof( T_3 ) ) ;
V_54:
F_15 ( V_39 ) ;
V_49:
F_16 ( V_44 ) ;
F_4 ( V_15 ) ;
if ( V_36 == V_21 )
V_59 -> V_64 = V_60 ;
else
V_59 -> V_65 = V_62 ;
return 0 ;
}
int
F_20 ( void )
{
struct V_43 * V_43 ;
struct V_1 * V_66 ;
int V_67 ;
F_14 ( 1 , L_14 , V_47 . V_68 ) ;
V_43 = F_21 ( NULL ) ;
if ( ! V_43 )
return - V_9 ;
V_66 = F_22 ( L_15 , 0 , 0 , V_43 ,
( V_69 & ~ V_70 ) |
V_71 | V_72 ,
V_73 , NULL ) ;
if ( F_13 ( V_66 ) ) {
V_67 = F_23 ( V_66 ) ;
goto V_74;
}
V_67 = F_24 ( & V_47 ) ;
if ( V_67 < 0 )
goto V_75;
F_25 ( V_76 , & V_66 -> V_77 ) ;
V_43 -> V_78 = V_66 ;
V_43 -> V_79 = V_80 ;
V_46 = V_43 ;
F_14 ( 1 , L_16 , F_26 ( V_66 ) ) ;
return 0 ;
V_75:
F_15 ( V_66 ) ;
V_74:
F_27 ( V_43 ) ;
return V_67 ;
}
void
F_28 ( void )
{
F_29 ( V_46 -> V_78 ) ;
F_30 ( & V_47 ) ;
F_27 ( V_46 ) ;
F_14 ( 1 , L_17 , V_47 . V_68 ) ;
}
static void F_31 ( const struct V_81 * V_82 ,
struct V_81 * V_83 , T_4 V_84 )
{
struct V_10 * V_85 , * V_86 ;
struct V_10 * V_87 , * V_88 ;
V_83 -> V_22 = V_82 -> V_22 ;
V_83 -> type = V_82 -> type ;
V_83 -> V_89 = F_32 ( sizeof( struct V_81 ) ) ;
V_83 -> V_90 = 0 ;
V_83 -> V_91 = F_32 ( V_84 ) ;
V_83 -> V_92 = F_32 ( V_84 + sizeof( struct V_10 ) ) ;
V_85 = (struct V_10 * ) ( ( char * ) V_82 +
F_6 ( V_82 -> V_91 ) ) ;
V_87 = (struct V_10 * ) ( ( char * ) V_83 + V_84 ) ;
F_8 ( V_87 , V_85 ) ;
V_86 = (struct V_10 * ) ( ( char * ) V_82 +
F_6 ( V_82 -> V_92 ) ) ;
V_88 = (struct V_10 * ) ( ( char * ) V_83 + V_84 +
sizeof( struct V_10 ) ) ;
F_8 ( V_88 , V_86 ) ;
return;
}
static void F_33 ( V_53 V_93 , int type , T_5 * V_94 ,
T_5 * V_95 )
{
T_4 V_77 = F_6 ( V_93 ) ;
if ( type == V_96 ) {
if ( V_77 & V_97 )
* V_95 &= ~ V_98 ;
if ( ( V_77 & V_99 ) ||
( ( V_77 & V_100 ) == V_100 ) )
* V_95 &= ~ V_101 ;
if ( ( V_77 & V_102 ) ||
( ( V_77 & V_103 ) == V_103 ) )
* V_95 &= ~ V_104 ;
if ( ( V_77 & V_105 ) ||
( ( V_77 & V_106 ) == V_106 ) )
* V_95 &= ~ V_107 ;
return;
} else if ( type != V_108 ) {
F_34 ( 1 , L_18 , type ) ;
return;
}
if ( V_77 & V_97 ) {
* V_94 |= ( V_98 & ( * V_95 ) ) ;
F_14 ( V_109 , L_19 ) ;
return;
}
if ( ( V_77 & V_99 ) ||
( ( V_77 & V_100 ) == V_100 ) )
* V_94 |= ( V_101 & ( * V_95 ) ) ;
if ( ( V_77 & V_102 ) ||
( ( V_77 & V_103 ) == V_103 ) )
* V_94 |= ( V_104 & ( * V_95 ) ) ;
if ( ( V_77 & V_105 ) ||
( ( V_77 & V_106 ) == V_106 ) )
* V_94 |= ( V_107 & ( * V_95 ) ) ;
F_14 ( V_109 , L_20 , V_77 , * V_94 ) ;
return;
}
static void F_35 ( T_5 V_110 , T_5 V_111 ,
T_4 * V_112 )
{
* V_112 = 0x0 ;
V_110 &= V_111 ;
if ( V_110 & V_104 )
* V_112 |= V_113 ;
if ( V_110 & V_101 )
* V_112 |= V_114 ;
if ( V_110 & V_107 )
* V_112 |= V_115 ;
F_14 ( V_109 , L_21 , V_110 , * V_112 ) ;
return;
}
static T_6 F_36 ( struct V_116 * V_117 ,
const struct V_10 * V_57 , T_7 V_118 , T_5 V_119 )
{
int V_12 ;
T_6 V_120 = 0 ;
T_4 V_121 = 0 ;
V_117 -> type = V_108 ;
V_117 -> V_77 = 0x0 ;
F_35 ( V_118 , V_119 , & V_121 ) ;
if ( ! V_121 )
V_121 = V_122 ;
V_117 -> V_121 = F_32 ( V_121 ) ;
V_117 -> V_123 . V_22 = V_57 -> V_22 ;
V_117 -> V_123 . V_20 = V_57 -> V_20 ;
for ( V_12 = 0 ; V_12 < V_30 ; V_12 ++ )
V_117 -> V_123 . V_23 [ V_12 ] = V_57 -> V_23 [ V_12 ] ;
for ( V_12 = 0 ; V_12 < V_57 -> V_20 ; V_12 ++ )
V_117 -> V_123 . V_25 [ V_12 ] = V_57 -> V_25 [ V_12 ] ;
V_120 = 1 + 1 + 2 + 4 + 1 + 1 + 6 + ( V_57 -> V_20 * 4 ) ;
V_117 -> V_120 = F_37 ( V_120 ) ;
return V_120 ;
}
static void F_38 ( struct V_116 * V_124 , char * V_125 )
{
int V_20 ;
if ( F_39 ( V_124 -> V_120 ) < 16 ) {
F_34 ( 1 , L_22 , F_39 ( V_124 -> V_120 ) ) ;
return;
}
if ( V_125 < ( char * ) V_124 + F_39 ( V_124 -> V_120 ) ) {
F_34 ( 1 , L_23 ) ;
return;
}
V_20 = V_124 -> V_123 . V_20 ;
if ( V_20 ) {
int V_12 ;
F_14 ( 1 , L_24 ,
V_124 -> V_123 . V_22 , V_124 -> V_123 . V_20 , V_124 -> type ,
V_124 -> V_77 , F_39 ( V_124 -> V_120 ) ) ;
for ( V_12 = 0 ; V_12 < V_20 ; ++ V_12 ) {
F_14 ( 1 , L_25 , V_12 ,
F_6 ( V_124 -> V_123 . V_25 [ V_12 ] ) ) ;
}
}
return;
}
static void F_40 ( struct V_126 * V_127 , char * V_125 ,
struct V_10 * V_128 , struct V_10 * V_129 ,
struct V_58 * V_59 )
{
int V_12 ;
int V_130 = 0 ;
int V_131 ;
char * V_132 ;
struct V_116 * * V_133 ;
if ( ! V_127 ) {
V_59 -> V_134 |= V_98 ;
return;
}
if ( V_125 < ( char * ) V_127 + F_39 ( V_127 -> V_120 ) ) {
F_34 ( 1 , L_26 ) ;
return;
}
F_14 ( V_109 , L_27 ,
F_39 ( V_127 -> V_22 ) , F_39 ( V_127 -> V_120 ) ,
F_6 ( V_127 -> V_130 ) ) ;
V_59 -> V_134 &= ~ ( V_98 ) ;
V_132 = ( char * ) V_127 ;
V_131 = sizeof( struct V_126 ) ;
V_130 = F_6 ( V_127 -> V_130 ) ;
if ( V_130 > 0 ) {
T_5 V_135 = V_136 ;
T_5 V_137 = V_138 ;
T_5 V_139 = V_136 | V_138 | V_140 ;
if ( V_130 > V_141 / sizeof( struct V_116 * ) )
return;
V_133 = F_2 ( V_130 * sizeof( struct V_116 * ) ,
V_8 ) ;
if ( ! V_133 ) {
F_34 ( 1 , L_28 ) ;
return;
}
for ( V_12 = 0 ; V_12 < V_130 ; ++ V_12 ) {
V_133 [ V_12 ] = (struct V_116 * ) ( V_132 + V_131 ) ;
#ifdef F_41
F_38 ( V_133 [ V_12 ] , V_125 ) ;
#endif
if ( F_7 ( & ( V_133 [ V_12 ] -> V_123 ) , V_128 ) == 0 )
F_33 ( V_133 [ V_12 ] -> V_121 ,
V_133 [ V_12 ] -> type ,
& V_59 -> V_134 ,
& V_135 ) ;
if ( F_7 ( & ( V_133 [ V_12 ] -> V_123 ) , V_129 ) == 0 )
F_33 ( V_133 [ V_12 ] -> V_121 ,
V_133 [ V_12 ] -> type ,
& V_59 -> V_134 ,
& V_137 ) ;
if ( F_7 ( & ( V_133 [ V_12 ] -> V_123 ) , & V_142 ) == 0 )
F_33 ( V_133 [ V_12 ] -> V_121 ,
V_133 [ V_12 ] -> type ,
& V_59 -> V_134 ,
& V_139 ) ;
if ( F_7 ( & ( V_133 [ V_12 ] -> V_123 ) , & V_143 ) == 0 )
F_33 ( V_133 [ V_12 ] -> V_121 ,
V_133 [ V_12 ] -> type ,
& V_59 -> V_134 ,
& V_139 ) ;
V_132 = ( char * ) V_133 [ V_12 ] ;
V_131 = F_39 ( V_133 [ V_12 ] -> V_120 ) ;
}
F_4 ( V_133 ) ;
}
return;
}
static int F_42 ( struct V_126 * V_144 , struct V_10 * V_128 ,
struct V_10 * V_129 , T_7 V_118 )
{
T_8 V_120 = 0 ;
struct V_126 * V_145 ;
V_145 = (struct V_126 * ) ( ( char * ) V_144 + sizeof( struct V_126 ) ) ;
V_120 += F_36 ( (struct V_116 * ) ( ( char * ) V_145 + V_120 ) ,
V_128 , V_118 , V_136 ) ;
V_120 += F_36 ( (struct V_116 * ) ( ( char * ) V_145 + V_120 ) ,
V_129 , V_118 , V_138 ) ;
V_120 += F_36 ( (struct V_116 * ) ( ( char * ) V_145 + V_120 ) ,
& V_142 , V_118 , V_140 ) ;
V_144 -> V_120 = F_37 ( V_120 + sizeof( struct V_126 ) ) ;
V_144 -> V_130 = F_32 ( 3 ) ;
return 0 ;
}
static int F_43 ( struct V_10 * V_57 , char * V_125 )
{
if ( V_125 < ( char * ) V_57 + 8 ) {
F_34 ( 1 , L_29 , V_57 ) ;
return - V_45 ;
}
#ifdef F_41
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
static int F_44 ( struct V_55 * V_56 ,
struct V_81 * V_82 , int V_146 , struct V_58 * V_59 )
{
int V_38 = 0 ;
struct V_10 * V_85 , * V_86 ;
struct V_126 * V_147 ;
char * V_125 = ( ( char * ) V_82 ) + V_146 ;
T_4 V_89 ;
if ( V_82 == NULL )
return - V_51 ;
V_85 = (struct V_10 * ) ( ( char * ) V_82 +
F_6 ( V_82 -> V_91 ) ) ;
V_86 = (struct V_10 * ) ( ( char * ) V_82 +
F_6 ( V_82 -> V_92 ) ) ;
V_89 = F_6 ( V_82 -> V_89 ) ;
V_147 = (struct V_126 * ) ( ( char * ) V_82 + V_89 ) ;
F_14 ( V_109 , L_33
L_34 ,
V_82 -> V_22 , V_82 -> type , F_6 ( V_82 -> V_91 ) ,
F_6 ( V_82 -> V_92 ) ,
F_6 ( V_82 -> V_90 ) , V_89 ) ;
V_38 = F_43 ( V_85 , V_125 ) ;
if ( V_38 ) {
F_14 ( 1 , L_35 , V_48 , V_38 ) ;
return V_38 ;
}
V_38 = F_18 ( V_56 , V_85 , V_59 , V_21 ) ;
if ( V_38 ) {
F_14 ( 1 , L_36 , V_48 , V_38 ) ;
return V_38 ;
}
V_38 = F_43 ( V_86 , V_125 ) ;
if ( V_38 ) {
F_14 ( 1 , L_37 , V_48 , V_38 ) ;
return V_38 ;
}
V_38 = F_18 ( V_56 , V_86 , V_59 , V_148 ) ;
if ( V_38 ) {
F_14 ( 1 , L_38 , V_48 , V_38 ) ;
return V_38 ;
}
if ( V_89 )
F_40 ( V_147 , V_125 , V_85 ,
V_86 , V_59 ) ;
else
F_14 ( 1 , L_39 ) ;
return V_38 ;
}
static int F_45 ( struct V_81 * V_82 , struct V_81 * V_83 ,
T_4 V_149 , T_7 V_118 , T_2 V_150 , T_3 V_151 , int * V_152 )
{
int V_38 = 0 ;
T_4 V_89 ;
T_4 V_153 ;
T_4 V_84 ;
struct V_10 * V_85 , * V_86 ;
struct V_10 * V_87 , * V_88 ;
struct V_126 * V_147 = NULL ;
struct V_126 * V_154 = NULL ;
if ( V_118 != V_155 ) {
V_85 = (struct V_10 * ) ( ( char * ) V_82 +
F_6 ( V_82 -> V_91 ) ) ;
V_86 = (struct V_10 * ) ( ( char * ) V_82 +
F_6 ( V_82 -> V_92 ) ) ;
V_89 = F_6 ( V_82 -> V_89 ) ;
V_147 = (struct V_126 * ) ( ( char * ) V_82 + V_89 ) ;
V_153 = sizeof( struct V_81 ) ;
V_154 = (struct V_126 * ) ( ( char * ) V_83 + V_153 ) ;
V_154 -> V_22 = V_147 -> V_22 ;
V_154 -> V_120 = 0 ;
V_154 -> V_130 = 0 ;
V_38 = F_42 ( V_154 , V_85 , V_86 ,
V_118 ) ;
V_84 = V_153 + F_39 ( V_154 -> V_120 ) ;
F_31 ( V_82 , V_83 , V_84 ) ;
* V_152 = V_156 ;
} else {
memcpy ( V_83 , V_82 , V_149 ) ;
if ( V_150 != V_157 ) {
V_85 = (struct V_10 * ) ( ( char * ) V_83 +
F_6 ( V_83 -> V_91 ) ) ;
V_87 = F_2 ( sizeof( struct V_10 ) ,
V_8 ) ;
if ( ! V_87 )
return - V_9 ;
V_38 = F_10 ( V_150 , V_21 , V_87 ) ;
if ( V_38 ) {
F_14 ( 1 , L_40 ,
V_48 , V_38 , V_150 ) ;
F_4 ( V_87 ) ;
return V_38 ;
}
F_8 ( V_85 , V_87 ) ;
F_4 ( V_87 ) ;
* V_152 = V_158 ;
}
if ( V_151 != V_157 ) {
V_86 = (struct V_10 * ) ( ( char * ) V_83 +
F_6 ( V_83 -> V_92 ) ) ;
V_88 = F_2 ( sizeof( struct V_10 ) ,
V_8 ) ;
if ( ! V_88 )
return - V_9 ;
V_38 = F_10 ( V_151 , V_148 , V_88 ) ;
if ( V_38 ) {
F_14 ( 1 , L_41 ,
V_48 , V_38 , V_151 ) ;
F_4 ( V_88 ) ;
return V_38 ;
}
F_8 ( V_86 , V_88 ) ;
F_4 ( V_88 ) ;
* V_152 = V_159 ;
}
}
return V_38 ;
}
static struct V_81 * F_46 ( struct V_55 * V_56 ,
T_6 V_160 , T_9 * V_161 )
{
struct V_81 * V_82 = NULL ;
unsigned int V_162 ;
int V_38 ;
struct V_163 * V_164 = F_47 ( V_56 ) ;
if ( F_13 ( V_164 ) )
return F_48 ( V_164 ) ;
V_162 = F_49 () ;
V_38 = F_50 ( V_162 , F_51 ( V_164 ) , V_160 , & V_82 , V_161 ) ;
F_52 ( V_162 ) ;
F_53 ( V_164 ) ;
F_14 ( 1 , L_42 , V_48 , V_38 , * V_161 ) ;
if ( V_38 )
return F_54 ( V_38 ) ;
return V_82 ;
}
static struct V_81 * F_55 ( struct V_55 * V_56 ,
const char * V_165 , T_9 * V_161 )
{
struct V_81 * V_82 = NULL ;
int V_166 = 0 ;
unsigned int V_162 ;
int V_38 , V_167 = 0 ;
T_6 V_160 ;
struct V_168 * V_169 ;
struct V_163 * V_164 = F_47 ( V_56 ) ;
if ( F_13 ( V_164 ) )
return F_48 ( V_164 ) ;
V_169 = F_51 ( V_164 ) ;
V_162 = F_49 () ;
if ( F_56 ( V_56 ) )
V_167 |= V_170 ;
V_38 = F_57 ( V_162 , V_169 , V_165 , V_171 , V_172 ,
V_167 , & V_160 , & V_166 , NULL , V_56 -> V_173 ,
V_56 -> V_174 & V_175 ) ;
if ( ! V_38 ) {
V_38 = F_50 ( V_162 , V_169 , V_160 , & V_82 , V_161 ) ;
F_58 ( V_162 , V_169 , V_160 ) ;
}
F_53 ( V_164 ) ;
F_52 ( V_162 ) ;
F_14 ( 1 , L_42 , V_48 , V_38 , * V_161 ) ;
if ( V_38 )
return F_54 ( V_38 ) ;
return V_82 ;
}
struct V_81 * F_59 ( struct V_55 * V_56 ,
struct V_176 * V_176 , const char * V_165 ,
T_9 * V_161 )
{
struct V_81 * V_82 = NULL ;
struct V_177 * V_178 = NULL ;
if ( V_176 )
V_178 = F_60 ( F_61 ( V_176 ) , true ) ;
if ( ! V_178 )
return F_55 ( V_56 , V_165 , V_161 ) ;
V_82 = F_46 ( V_56 , V_178 -> V_160 . V_179 , V_161 ) ;
F_62 ( V_178 ) ;
return V_82 ;
}
int F_63 ( struct V_81 * V_83 , T_4 V_180 ,
struct V_176 * V_176 , const char * V_165 , int V_152 )
{
int V_166 = 0 ;
unsigned int V_162 ;
int V_38 , V_181 , V_167 = 0 ;
T_6 V_160 ;
struct V_168 * V_169 ;
struct V_55 * V_56 = F_64 ( V_176 -> V_182 ) ;
struct V_163 * V_164 = F_47 ( V_56 ) ;
if ( F_13 ( V_164 ) )
return F_23 ( V_164 ) ;
V_169 = F_51 ( V_164 ) ;
V_162 = F_49 () ;
if ( F_56 ( V_56 ) )
V_167 |= V_170 ;
if ( V_152 == V_158 || V_152 == V_159 )
V_181 = V_183 ;
else
V_181 = V_184 ;
V_38 = F_57 ( V_162 , V_169 , V_165 , V_171 , V_181 ,
V_167 , & V_160 , & V_166 , NULL , V_56 -> V_173 ,
V_56 -> V_174 & V_175 ) ;
if ( V_38 ) {
F_34 ( 1 , L_43 ) ;
goto V_185;
}
V_38 = F_65 ( V_162 , V_169 , V_160 , V_83 , V_180 , V_152 ) ;
F_14 ( V_109 , L_44 , V_38 ) ;
F_58 ( V_162 , V_169 , V_160 ) ;
V_185:
F_52 ( V_162 ) ;
F_53 ( V_164 ) ;
return V_38 ;
}
int
F_66 ( struct V_55 * V_56 , struct V_58 * V_59 ,
struct V_176 * V_176 , const char * V_165 , const T_6 * V_186 )
{
struct V_81 * V_82 = NULL ;
T_9 V_180 = 0 ;
int V_38 = 0 ;
F_14 ( V_109 , L_45 , V_165 ) ;
if ( V_186 )
V_82 = F_46 ( V_56 , * V_186 , & V_180 ) ;
else
V_82 = F_59 ( V_56 , V_176 , V_165 , & V_180 ) ;
if ( F_13 ( V_82 ) ) {
V_38 = F_23 ( V_82 ) ;
F_34 ( 1 , L_46 , V_48 , V_38 ) ;
} else {
V_38 = F_44 ( V_56 , V_82 , V_180 , V_59 ) ;
F_4 ( V_82 ) ;
if ( V_38 )
F_34 ( 1 , L_47 , V_38 ) ;
}
return V_38 ;
}
int
F_67 ( struct V_176 * V_176 , const char * V_165 , T_7 V_118 ,
T_2 V_150 , T_3 V_151 )
{
int V_38 = 0 ;
int V_152 = V_156 ;
T_4 V_149 = 0 ;
struct V_81 * V_82 = NULL ;
struct V_81 * V_83 = NULL ;
F_14 ( V_109 , L_48 , V_165 ) ;
V_82 = F_59 ( F_64 ( V_176 -> V_182 ) , V_176 , V_165 , & V_149 ) ;
if ( F_13 ( V_82 ) ) {
V_38 = F_23 ( V_82 ) ;
F_34 ( 1 , L_46 , V_48 , V_38 ) ;
goto V_185;
}
V_149 = F_68 ( T_9 , V_149 , V_187 ) ;
V_83 = F_2 ( V_149 , V_8 ) ;
if ( ! V_83 ) {
F_34 ( 1 , L_49 ) ;
F_4 ( V_82 ) ;
return - V_9 ;
}
V_38 = F_45 ( V_82 , V_83 , V_149 , V_118 , V_150 , V_151 ,
& V_152 ) ;
F_14 ( V_109 , L_50 , V_38 ) ;
if ( ! V_38 ) {
V_38 = F_63 ( V_83 , V_149 , V_176 , V_165 , V_152 ) ;
F_14 ( V_109 , L_51 , V_38 ) ;
}
F_4 ( V_83 ) ;
F_4 ( V_82 ) ;
V_185:
return V_38 ;
}
