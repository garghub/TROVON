char *
F_1 ( void )
{
return V_1 ;
}
char *
F_2 ( void )
{
char * V_2 ;
int V_3 ;
if ( * V_4 != 0 && * V_5 != 0 ) {
F_3 ( 0x101 , L_1
L_2 ) ;
return NULL ;
}
if ( * V_5 != 0 ) {
V_3 = F_4 ( & V_2 , V_5 ) ;
return ( V_3 == 0 ) ? V_2 : NULL ;
}
if ( * V_4 != 0 )
return V_4 ;
return L_3 ;
}
void
F_5 ( void )
{
F_6 ( & V_6 . V_7 ) ;
F_7 ( & V_6 . V_8 ) ;
F_8 ( & V_6 . V_9 ) ;
F_8 ( & V_6 . V_10 ) ;
}
void
F_9 ( void )
{
}
static int
F_10 ( void )
{
int V_11 ;
struct V_12 * V_13 ;
F_11 ( V_6 . V_14 == NULL ) ;
F_11 ( V_6 . V_15 > 0 ) ;
F_12 ( V_13 , V_16 * sizeof( * V_13 ) ) ;
if ( V_13 == NULL ) {
F_13 ( L_4 ) ;
return - V_17 ;
}
for ( V_11 = 0 ; V_11 < V_16 ; V_11 ++ )
F_14 ( & V_13 [ V_11 ] ) ;
V_6 . V_14 = V_13 ;
return 0 ;
}
static void
F_15 ( void )
{
int V_11 ;
struct V_12 * V_13 ;
if ( V_6 . V_14 == NULL )
return;
for ( V_11 = 0 ; V_11 < V_16 ; V_11 ++ )
F_11 ( F_16 ( & V_6 . V_14 [ V_11 ] ) ) ;
F_17 ( V_6 . V_14 ,
V_16 * sizeof( * V_13 ) ) ;
V_6 . V_14 = NULL ;
}
static void
F_18 ( void )
{
if ( V_6 . V_18 != NULL ) {
F_19 ( V_6 . V_18 ) ;
V_6 . V_18 = NULL ;
}
if ( V_6 . V_19 != NULL ) {
F_19 ( V_6 . V_19 ) ;
V_6 . V_19 = NULL ;
}
F_9 () ;
}
static int
F_20 ( void )
{
F_5 () ;
V_6 . V_18 = F_21 ( F_22 () ) ;
if ( V_6 . V_18 == NULL )
goto V_20;
V_6 . V_19 = F_21 ( F_22 () ) ;
if ( V_6 . V_19 == NULL )
goto V_20;
return 0 ;
V_20:
F_18 () ;
return - V_17 ;
}
void F_23 ( void )
{
F_24 ( V_21 == 0xeebc0ded ) ;
F_24 ( V_22 == 1 ) ;
F_24 ( V_23 == 0 ) ;
F_24 ( V_24 == 0 ) ;
F_24 ( V_25 == 1 ) ;
F_24 ( V_26 == 2 ) ;
F_24 ( V_27 == 3 ) ;
F_24 ( V_28 == 4 ) ;
F_24 ( ( int ) sizeof( V_29 ) == 16 ) ;
F_24 ( ( int ) F_25 ( V_29 , V_30 ) == 0 ) ;
F_24 ( ( int ) sizeof( ( ( V_29 * ) 0 ) -> V_30 ) == 8 ) ;
F_24 ( ( int ) F_25 ( V_29 , V_31 ) == 8 ) ;
F_24 ( ( int ) sizeof( ( ( V_29 * ) 0 ) -> V_31 ) == 8 ) ;
F_24 ( ( int ) sizeof( V_32 ) == 8 ) ;
F_24 ( ( int ) F_25 ( V_32 , V_33 ) == 0 ) ;
F_24 ( ( int ) sizeof( ( ( V_32 * ) 0 ) -> V_33 ) == 4 ) ;
F_24 ( ( int ) F_25 ( V_32 , V_34 ) == 4 ) ;
F_24 ( ( int ) sizeof( ( ( V_32 * ) 0 ) -> V_34 ) == 2 ) ;
F_24 ( ( int ) F_25 ( V_32 , V_35 ) == 6 ) ;
F_24 ( ( int ) sizeof( ( ( V_32 * ) 0 ) -> V_35 ) == 2 ) ;
F_24 ( ( int ) sizeof( V_36 ) == 72 ) ;
F_24 ( ( int ) F_25 ( V_36 , V_37 ) == 0 ) ;
F_24 ( ( int ) sizeof( ( ( V_36 * ) 0 ) -> V_37 ) == 8 ) ;
F_24 ( ( int ) F_25 ( V_36 , V_38 ) == 8 ) ;
F_24 ( ( int ) sizeof( ( ( V_36 * ) 0 ) -> V_38 ) == 8 ) ;
F_24 ( ( int ) F_25 ( V_36 , V_39 ) == 16 ) ;
F_24 ( ( int ) sizeof( ( ( V_36 * ) 0 ) -> V_39 ) == 4 ) ;
F_24 ( ( int ) F_25 ( V_36 , V_40 ) == 20 ) ;
F_24 ( ( int ) sizeof( ( ( V_36 * ) 0 ) -> V_40 ) == 4 ) ;
F_24 ( ( int ) F_25 ( V_36 , type ) == 24 ) ;
F_24 ( ( int ) sizeof( ( ( V_36 * ) 0 ) -> type ) == 4 ) ;
F_24 ( ( int ) F_25 ( V_36 , V_41 ) == 28 ) ;
F_24 ( ( int ) sizeof( ( ( V_36 * ) 0 ) -> V_41 ) == 4 ) ;
F_24 ( ( int ) F_25 ( V_36 , V_42 ) == 32 ) ;
F_24 ( ( int ) sizeof( ( ( V_36 * ) 0 ) -> V_42 ) == 40 ) ;
F_24 ( ( int ) F_25 ( V_36 , V_42 . V_43 . V_44 ) == 32 ) ;
F_24 ( ( int ) sizeof( ( ( V_36 * ) 0 ) -> V_42 . V_43 . V_44 ) == 16 ) ;
F_24 ( ( int ) F_25 ( V_36 , V_42 . V_43 . V_45 ) == 48 ) ;
F_24 ( ( int ) sizeof( ( ( V_36 * ) 0 ) -> V_42 . V_43 . V_45 ) == 8 ) ;
F_24 ( ( int ) F_25 ( V_36 , V_42 . V_43 . V_46 ) == 56 ) ;
F_24 ( ( int ) sizeof( ( ( V_36 * ) 0 ) -> V_42 . V_43 . V_46 ) == 4 ) ;
F_24 ( ( int ) F_25 ( V_36 , V_42 . V_47 . V_48 ) == 32 ) ;
F_24 ( ( int ) sizeof( ( ( V_36 * ) 0 ) -> V_42 . V_47 . V_48 ) == 16 ) ;
F_24 ( ( int ) F_25 ( V_36 , V_42 . V_47 . V_45 ) == 48 ) ;
F_24 ( ( int ) sizeof( ( ( V_36 * ) 0 ) -> V_42 . V_47 . V_45 ) == 8 ) ;
F_24 ( ( int ) F_25 ( V_36 , V_42 . V_47 . V_49 ) == 56 ) ;
F_24 ( ( int ) sizeof( ( ( V_36 * ) 0 ) -> V_42 . V_47 . V_49 ) == 8 ) ;
F_24 ( ( int ) F_25 ( V_36 , V_42 . V_47 . V_50 ) == 64 ) ;
F_24 ( ( int ) sizeof( ( ( V_36 * ) 0 ) -> V_42 . V_47 . V_50 ) == 4 ) ;
F_24 ( ( int ) F_25 ( V_36 , V_42 . V_47 . V_51 ) == 68 ) ;
F_24 ( ( int ) sizeof( ( ( V_36 * ) 0 ) -> V_42 . V_47 . V_51 ) == 4 ) ;
F_24 ( ( int ) F_25 ( V_36 , V_42 . V_52 . V_53 ) == 32 ) ;
F_24 ( ( int ) sizeof( ( ( V_36 * ) 0 ) -> V_42 . V_52 . V_53 ) == 16 ) ;
F_24 ( ( int ) F_25 ( V_36 , V_42 . V_52 . V_45 ) == 48 ) ;
F_24 ( ( int ) sizeof( ( ( V_36 * ) 0 ) -> V_42 . V_52 . V_45 ) == 8 ) ;
F_24 ( ( int ) F_25 ( V_36 , V_42 . V_52 . V_50 ) == 56 ) ;
F_24 ( ( int ) sizeof( ( ( V_36 * ) 0 ) -> V_42 . V_52 . V_50 ) == 4 ) ;
F_24 ( ( int ) F_25 ( V_36 , V_42 . V_52 . V_54 ) == 60 ) ;
F_24 ( ( int ) sizeof( ( ( V_36 * ) 0 ) -> V_42 . V_52 . V_54 ) == 4 ) ;
F_24 ( ( int ) F_25 ( V_36 , V_42 . V_52 . V_55 ) == 64 ) ;
F_24 ( ( int ) sizeof( ( ( V_36 * ) 0 ) -> V_42 . V_52 . V_55 ) == 4 ) ;
F_24 ( ( int ) F_25 ( V_36 , V_42 . V_56 . V_44 ) == 32 ) ;
F_24 ( ( int ) sizeof( ( ( V_36 * ) 0 ) -> V_42 . V_56 . V_44 ) == 16 ) ;
F_24 ( ( int ) F_25 ( V_36 , V_42 . V_57 . V_58 ) == 32 ) ;
F_24 ( ( int ) sizeof( ( ( V_36 * ) 0 ) -> V_42 . V_57 . V_58 ) == 8 ) ;
F_24 ( ( int ) F_25 ( V_36 , V_42 . V_57 . type ) == 40 ) ;
F_24 ( ( int ) sizeof( ( ( V_36 * ) 0 ) -> V_42 . V_57 . type ) == 4 ) ;
}
T_1 *
F_26 ( int type )
{
T_1 * V_59 ;
struct V_12 * V_60 ;
F_27 (tmp, &the_lnet.ln_lnds) {
V_59 = F_28 ( V_60 , T_1 , V_61 ) ;
if ( ( int ) V_59 -> V_62 == type )
return V_59 ;
}
return NULL ;
}
void
F_29 ( T_1 * V_59 )
{
F_30 ( & V_6 . V_9 ) ;
F_11 ( V_6 . V_63 ) ;
F_11 ( F_31 ( V_59 -> V_62 ) ) ;
F_11 ( F_26 ( V_59 -> V_62 ) == NULL ) ;
F_32 ( & V_59 -> V_61 , & V_6 . V_64 ) ;
V_59 -> V_65 = 0 ;
F_33 ( V_66 , L_5 , F_34 ( V_59 -> V_62 ) ) ;
F_35 ( & V_6 . V_9 ) ;
}
void
F_36 ( T_1 * V_59 )
{
F_30 ( & V_6 . V_9 ) ;
F_11 ( V_6 . V_63 ) ;
F_11 ( F_26 ( V_59 -> V_62 ) == V_59 ) ;
F_11 ( V_59 -> V_65 == 0 ) ;
F_37 ( & V_59 -> V_61 ) ;
F_33 ( V_66 , L_6 , F_34 ( V_59 -> V_62 ) ) ;
F_35 ( & V_6 . V_9 ) ;
}
void
F_38 ( T_2 * V_67 )
{
T_2 * V_68 ;
int V_11 ;
memset ( V_67 , 0 , sizeof( * V_67 ) ) ;
F_39 ( V_69 ) ;
F_40 (ctr, i, the_lnet.ln_counters) {
V_67 -> V_70 += V_68 -> V_70 ;
V_67 -> V_71 += V_68 -> V_71 ;
V_67 -> V_72 += V_68 -> V_72 ;
V_67 -> V_73 += V_68 -> V_73 ;
V_67 -> V_74 += V_68 -> V_74 ;
V_67 -> V_75 += V_68 -> V_75 ;
V_67 -> V_76 += V_68 -> V_76 ;
V_67 -> V_77 += V_68 -> V_77 ;
V_67 -> V_78 += V_68 -> V_78 ;
V_67 -> V_79 += V_68 -> V_79 ;
V_67 -> V_76 += V_68 -> V_76 ;
}
F_41 ( V_69 ) ;
}
void
F_42 ( void )
{
T_2 * V_67 ;
int V_11 ;
F_39 ( V_69 ) ;
F_40 (counters, i, the_lnet.ln_counters)
memset ( V_67 , 0 , sizeof( T_2 ) ) ;
F_41 ( V_69 ) ;
}
int
F_43 ( T_3 * V_80 , int V_81 , int V_82 )
{
char * V_83 ;
F_11 ( V_81 > 0 ) ;
V_82 += F_25 ( V_84 , V_85 ) ;
F_12 ( V_83 , V_81 * V_82 ) ;
if ( V_83 == NULL )
return ( - V_17 ) ;
F_14 ( & V_80 -> V_86 ) ;
V_80 -> V_87 = V_83 ;
V_80 -> V_88 = V_81 ;
V_80 -> V_89 = V_82 ;
do
{
memset ( V_83 , 0 , V_82 ) ;
F_44 ( (struct V_12 * ) V_83 , & V_80 -> V_86 ) ;
V_83 += V_82 ;
} while ( -- V_81 != 0 );
return ( 0 ) ;
}
void
F_45 ( T_3 * V_80 )
{
struct V_12 * V_90 ;
int V_91 ;
if ( V_80 -> V_88 == 0 )
return;
V_91 = 0 ;
for ( V_90 = V_80 -> V_86 . V_92 ; V_90 != & V_80 -> V_86 ; V_90 = V_90 -> V_92 )
V_91 ++ ;
F_11 ( V_91 == V_80 -> V_88 ) ;
F_17 ( V_80 -> V_87 , V_80 -> V_88 * V_80 -> V_89 ) ;
memset ( V_80 , 0 , sizeof ( * V_80 ) ) ;
}
T_4
F_46 ( void )
{
struct V_93 V_94 ;
T_4 V_95 ;
F_47 ( & V_94 ) ;
V_95 = V_94 . V_96 ;
V_95 *= 1000000 ;
V_95 += V_94 . V_97 ;
return V_95 ;
}
static char *
F_48 ( int type )
{
switch ( type ) {
default:
F_49 () ;
case V_98 :
return L_7 ;
case V_99 :
return L_8 ;
case V_100 :
return L_9 ;
}
}
void
F_50 ( struct V_101 * V_102 )
{
int V_91 = 0 ;
if ( V_102 -> V_103 == 0 )
return;
while ( ! F_16 ( & V_102 -> V_104 ) ) {
struct V_12 * V_105 = V_102 -> V_104 . V_92 ;
F_51 ( V_105 ) ;
if ( V_102 -> V_103 == V_100 ) {
F_52 ( F_28 ( V_105 , V_106 , V_107 ) ) ;
} else if ( V_102 -> V_103 == V_98 ) {
F_53 ( F_28 ( V_105 , V_108 , V_109 ) ) ;
} else {
F_49 () ;
}
V_91 ++ ;
}
if ( V_91 > 0 ) {
F_13 ( L_10 ,
V_91 , F_48 ( V_102 -> V_103 ) ) ;
}
#ifdef F_54
F_45 ( & V_102 -> V_110 ) ;
#endif
if ( V_102 -> V_111 != NULL ) {
F_17 ( V_102 -> V_111 ,
V_112 * sizeof( V_102 -> V_111 [ 0 ] ) ) ;
V_102 -> V_111 = NULL ;
}
V_102 -> V_103 = 0 ;
}
int
F_55 ( struct V_101 * V_102 ,
int V_113 , int type , int V_114 , int V_115 )
{
int V_3 = 0 ;
int V_11 ;
F_11 ( V_102 -> V_103 == 0 ) ;
V_102 -> V_103 = type ;
F_14 ( & V_102 -> V_104 ) ;
#ifdef F_54
memset ( & V_102 -> V_110 , 0 , sizeof( V_102 -> V_110 ) ) ;
V_3 = F_43 ( & V_102 -> V_110 , V_114 , V_115 ) ;
if ( V_3 != 0 )
goto V_116;
#endif
V_102 -> V_117 = ( V_113 << V_118 ) | type ;
F_56 ( V_102 -> V_111 , F_22 () , V_113 ,
V_112 * sizeof( V_102 -> V_111 [ 0 ] ) ) ;
if ( V_102 -> V_111 == NULL ) {
V_3 = - V_17 ;
goto V_116;
}
for ( V_11 = 0 ; V_11 < V_112 ; V_11 ++ )
F_14 ( & V_102 -> V_111 [ V_11 ] ) ;
return 0 ;
V_116:
F_13 ( L_11 ,
F_48 ( type ) ) ;
F_50 ( V_102 ) ;
return V_3 ;
}
static void
F_57 ( struct V_101 * * V_119 )
{
struct V_101 * V_102 ;
int V_11 ;
F_40 (rec, i, recs)
F_50 ( V_102 ) ;
F_58 ( V_119 ) ;
}
static struct V_101 * *
F_59 ( int type , int V_114 , int V_115 )
{
struct V_101 * * V_119 ;
struct V_101 * V_102 ;
int V_3 ;
int V_11 ;
V_119 = F_60 ( F_22 () , sizeof( * V_102 ) ) ;
if ( V_119 == NULL ) {
F_13 ( L_12 ,
F_48 ( type ) ) ;
return NULL ;
}
F_40 (rec, i, recs) {
V_3 = F_55 ( V_102 , V_11 , type , V_114 , V_115 ) ;
if ( V_3 != 0 ) {
F_57 ( V_119 ) ;
return NULL ;
}
}
return V_119 ;
}
T_5 *
F_61 ( struct V_101 * V_102 , T_4 V_95 )
{
struct V_12 * V_120 ;
T_5 * V_121 ;
unsigned int V_13 ;
if ( ( V_95 & V_122 ) != V_102 -> V_103 )
return NULL ;
V_13 = V_95 >> ( V_118 + V_123 ) ;
V_120 = & V_102 -> V_111 [ V_13 & V_124 ] ;
F_62 (lh, head, lh_hash_chain) {
if ( V_121 -> V_125 == V_95 )
return V_121 ;
}
return NULL ;
}
void
F_63 ( struct V_101 * V_102 , T_5 * V_121 )
{
unsigned int V_126 = V_118 + V_123 ;
unsigned int V_13 ;
V_121 -> V_125 = V_102 -> V_117 ;
V_102 -> V_117 += 1 << V_126 ;
V_13 = ( V_121 -> V_125 >> V_126 ) & V_124 ;
F_44 ( & V_121 -> V_127 , & V_102 -> V_111 [ V_13 ] ) ;
}
int
F_64 ( T_6 V_128 )
{
struct V_101 * * V_119 ;
int V_3 = 0 ;
F_11 ( V_6 . V_129 == 0 ) ;
V_6 . V_130 = 0 ;
F_11 ( ( V_128 & V_131 ) == 0 ) ;
V_6 . V_132 = V_128 ;
F_14 ( & V_6 . V_133 ) ;
F_14 ( & V_6 . V_134 ) ;
F_14 ( & V_6 . V_135 ) ;
F_14 ( & V_6 . V_136 ) ;
F_14 ( & V_6 . V_137 ) ;
V_3 = F_10 () ;
if ( V_3 != 0 )
goto V_20;
V_6 . V_138 = F_46 () ;
V_6 . V_139 = F_60 ( F_22 () ,
sizeof( T_2 ) ) ;
if ( V_6 . V_139 == NULL ) {
F_13 ( L_13 ) ;
V_3 = - V_17 ;
goto V_20;
}
V_3 = F_65 () ;
if ( V_3 != 0 )
goto V_20;
V_3 = F_66 () ;
if ( V_3 != 0 )
goto V_20;
V_3 = F_55 ( & V_6 . V_140 , 0 ,
V_100 , V_141 ,
sizeof( V_106 ) ) ;
if ( V_3 != 0 )
goto V_20;
V_119 = F_59 ( V_99 , V_142 ,
sizeof( V_143 ) ) ;
if ( V_119 == NULL )
goto V_20;
V_6 . V_144 = V_119 ;
V_119 = F_59 ( V_98 , V_145 ,
sizeof( V_108 ) ) ;
if ( V_119 == NULL )
goto V_20;
V_6 . V_146 = V_119 ;
V_3 = F_67 () ;
if ( V_3 != 0 ) {
F_13 ( L_14 , V_3 ) ;
goto V_20;
}
return 0 ;
V_20:
F_68 () ;
return V_3 ;
}
int
F_68 ( void )
{
F_69 ( V_147 , 0 ) ;
F_11 ( V_6 . V_129 == 0 ) ;
F_11 ( F_16 ( & V_6 . V_133 ) ) ;
F_11 ( F_16 ( & V_6 . V_134 ) ) ;
F_11 ( F_16 ( & V_6 . V_135 ) ) ;
F_11 ( F_16 ( & V_6 . V_136 ) ) ;
F_70 () ;
if ( V_6 . V_146 != NULL ) {
F_57 ( V_6 . V_146 ) ;
V_6 . V_146 = NULL ;
}
if ( V_6 . V_144 != NULL ) {
F_57 ( V_6 . V_144 ) ;
V_6 . V_144 = NULL ;
}
F_50 ( & V_6 . V_140 ) ;
F_71 () ;
F_72 () ;
F_73 () ;
if ( V_6 . V_139 != NULL ) {
F_58 ( V_6 . V_139 ) ;
V_6 . V_139 = NULL ;
}
F_15 () ;
return 0 ;
}
T_7 *
F_74 ( T_8 V_148 , int V_113 )
{
struct V_12 * V_60 ;
T_7 * V_149 ;
F_11 ( V_113 != V_69 ) ;
F_27 (tmp, &the_lnet.ln_nis) {
V_149 = F_28 ( V_60 , T_7 , V_150 ) ;
if ( F_75 ( V_149 -> V_151 ) == V_148 ) {
F_76 ( V_149 , V_113 ) ;
return V_149 ;
}
}
return NULL ;
}
T_7 *
F_77 ( T_8 V_148 )
{
T_7 * V_149 ;
F_39 ( 0 ) ;
V_149 = F_74 ( V_148 , 0 ) ;
F_41 ( 0 ) ;
return V_149 ;
}
static unsigned int
F_78 ( T_9 V_152 , unsigned int V_153 )
{
T_4 V_154 = V_152 ;
unsigned int V_155 ;
F_11 ( V_153 >= 1 && V_153 <= V_156 ) ;
if ( V_153 == 1 )
return 0 ;
V_155 = F_79 ( V_154 , V_123 ) ;
if ( V_155 < V_153 )
return V_155 ;
return ( unsigned int ) ( V_154 + V_155 + ( V_155 >> 1 ) ) % V_153 ;
}
int
F_80 ( T_9 V_152 )
{
struct V_157 * V_149 ;
if ( V_156 == 1 )
return 0 ;
if ( ! F_16 ( & V_6 . V_135 ) ) {
F_62 (ni, &the_lnet.ln_nis_cpt, ni_cptlist) {
if ( F_75 ( V_149 -> V_151 ) != F_75 ( V_152 ) )
continue;
F_11 ( V_149 -> V_158 != NULL ) ;
return V_149 -> V_158 [ F_78
( V_152 , V_149 -> V_159 ) ] ;
}
}
return F_78 ( V_152 , V_156 ) ;
}
int
F_81 ( T_9 V_152 )
{
int V_113 ;
int V_160 ;
if ( V_156 == 1 )
return 0 ;
if ( F_16 ( & V_6 . V_135 ) )
return F_78 ( V_152 , V_156 ) ;
V_113 = F_82 () ;
V_160 = F_80 ( V_152 ) ;
F_41 ( V_113 ) ;
return V_160 ;
}
int
F_83 ( T_8 V_148 )
{
struct V_157 * V_149 ;
int V_113 ;
V_113 = F_82 () ;
V_149 = F_74 ( V_148 , V_113 ) ;
if ( V_149 != NULL )
F_84 ( V_149 , V_113 ) ;
F_41 ( V_113 ) ;
return V_149 != NULL ;
}
T_7 *
F_85 ( T_9 V_152 , int V_113 )
{
struct V_157 * V_149 ;
struct V_12 * V_60 ;
F_11 ( V_113 != V_69 ) ;
F_27 (tmp, &the_lnet.ln_nis) {
V_149 = F_28 ( V_60 , T_7 , V_150 ) ;
if ( V_149 -> V_151 == V_152 ) {
F_76 ( V_149 , V_113 ) ;
return V_149 ;
}
}
return NULL ;
}
int
F_86 ( T_9 V_152 )
{
struct V_157 * V_149 ;
int V_113 ;
V_113 = F_82 () ;
V_149 = F_85 ( V_152 , V_113 ) ;
if ( V_149 != NULL )
F_84 ( V_149 , V_113 ) ;
F_41 ( V_113 ) ;
return V_149 != NULL ;
}
int
F_87 ( void )
{
int V_91 = 0 ;
struct V_12 * V_60 ;
struct V_157 * V_149 ;
int V_113 ;
V_113 = F_82 () ;
F_27 (tmp, &the_lnet.ln_nis) {
V_149 = F_28 ( V_60 , T_7 , V_150 ) ;
if ( V_149 -> V_161 -> V_162 != NULL )
V_91 ++ ;
}
F_41 ( V_113 ) ;
return V_91 ;
}
static int
F_88 ( T_7 * V_149 )
{
int V_163 ;
F_11 ( V_149 -> V_159 >= 1 ) ;
if ( V_149 -> V_159 == 1 )
return V_149 -> V_164 ;
V_163 = V_149 -> V_164 / V_149 -> V_159 ;
V_163 = F_89 ( V_163 , 8 * V_149 -> V_165 ) ;
V_163 = F_90 ( V_163 , V_149 -> V_164 ) ;
return V_163 ;
}
void
F_91 ( void )
{
int V_11 ;
int V_166 ;
T_7 * V_149 ;
F_11 ( ! V_6 . V_167 ) ;
F_11 ( V_6 . V_129 == 0 ) ;
F_11 ( F_16 ( & V_6 . V_136 ) ) ;
F_39 ( V_69 ) ;
V_6 . V_167 = 1 ;
while ( ! F_16 ( & V_6 . V_134 ) ) {
V_149 = F_28 ( V_6 . V_134 . V_92 ,
T_7 , V_150 ) ;
F_92 ( & V_149 -> V_150 , & V_6 . V_136 ) ;
F_84 ( V_149 , 0 ) ;
if ( ! F_16 ( & V_149 -> V_168 ) ) {
F_51 ( & V_149 -> V_168 ) ;
F_84 ( V_149 , 0 ) ;
}
}
if ( V_6 . V_169 != NULL ) {
F_84 ( V_6 . V_169 , 0 ) ;
V_6 . V_169 = NULL ;
}
if ( V_6 . V_170 != NULL ) {
F_84 ( V_6 . V_170 , 0 ) ;
V_6 . V_170 = NULL ;
}
F_41 ( V_69 ) ;
for ( V_11 = 0 ; V_11 < V_6 . V_171 ; V_11 ++ )
F_93 ( V_11 ) ;
F_94 () ;
F_39 ( V_69 ) ;
V_11 = 2 ;
while ( ! F_16 ( & V_6 . V_136 ) ) {
int * V_172 ;
int V_173 ;
V_149 = F_28 ( V_6 . V_136 . V_92 ,
T_7 , V_150 ) ;
F_51 ( & V_149 -> V_150 ) ;
F_40 (ref, j, ni->ni_refs) {
if ( * V_172 == 0 )
continue;
F_44 ( & V_149 -> V_150 , & V_6 . V_136 ) ;
break;
}
while ( ! F_16 ( & V_149 -> V_150 ) ) {
F_41 ( V_69 ) ;
++ V_11 ;
if ( ( V_11 & ( - V_11 ) ) == V_11 ) {
F_33 ( V_174 ,
L_15 ,
F_95 ( V_149 -> V_151 ) ) ;
}
F_96 ( V_175 ) ;
F_97 ( F_98 ( 1 ) ) ;
F_39 ( V_69 ) ;
continue;
}
V_149 -> V_161 -> V_65 -- ;
F_41 ( V_69 ) ;
V_166 = V_149 -> V_161 -> V_62 == V_176 ;
F_11 ( ! F_99 () ) ;
( V_149 -> V_161 -> V_177 ) ( V_149 ) ;
if ( ! V_166 )
F_33 ( V_178 , L_16 ,
F_95 ( V_149 -> V_151 ) ) ;
F_100 ( V_149 ) ;
F_39 ( V_69 ) ;
}
V_6 . V_167 = 0 ;
F_41 ( V_69 ) ;
if ( V_6 . V_179 != NULL ) {
F_17 ( V_6 . V_179 ,
V_6 . V_180 ) ;
V_6 . V_179 = NULL ;
}
}
int
F_101 ( void )
{
T_1 * V_59 ;
struct V_157 * V_149 ;
struct V_181 * V_182 ;
struct V_12 V_183 ;
int V_11 ;
int V_3 = 0 ;
int V_62 ;
int V_184 = 0 ;
char * V_2 = F_2 () ;
F_14 ( & V_183 ) ;
if ( V_2 == NULL )
goto V_20;
V_3 = F_102 ( & V_183 , V_2 ) ;
if ( V_3 != 0 )
goto V_20;
while ( ! F_16 ( & V_183 ) ) {
V_149 = F_28 ( V_183 . V_92 , T_7 , V_150 ) ;
V_62 = F_103 ( F_75 ( V_149 -> V_151 ) ) ;
F_11 ( F_31 ( V_62 ) ) ;
if ( V_62 == V_185 ||
V_62 == V_186 ||
V_62 == V_187 ||
V_62 == V_188 ) {
F_13 ( L_17 ,
F_34 ( V_62 ) ) ;
goto V_20;
}
F_30 ( & V_6 . V_9 ) ;
V_59 = F_26 ( V_62 ) ;
if ( V_59 == NULL ) {
F_35 ( & V_6 . V_9 ) ;
V_3 = F_104 ( L_18 ,
F_105 ( V_62 ) ) ;
F_30 ( & V_6 . V_9 ) ;
V_59 = F_26 ( V_62 ) ;
if ( V_59 == NULL ) {
F_35 ( & V_6 . V_9 ) ;
F_13 ( L_19 ,
F_34 ( V_62 ) ,
F_105 ( V_62 ) , V_3 ) ;
goto V_20;
}
}
F_39 ( V_69 ) ;
V_59 -> V_65 ++ ;
F_41 ( V_69 ) ;
V_149 -> V_161 = V_59 ;
V_3 = ( V_59 -> V_189 ) ( V_149 ) ;
F_35 ( & V_6 . V_9 ) ;
if ( V_3 != 0 ) {
F_3 ( 0x105 , L_20
L_21 ,
V_3 , F_34 ( V_59 -> V_62 ) ) ;
F_39 ( V_69 ) ;
V_59 -> V_65 -- ;
F_41 ( V_69 ) ;
goto V_20;
}
F_11 ( V_149 -> V_190 <= 0 || V_59 -> V_191 != NULL ) ;
F_37 ( & V_149 -> V_150 ) ;
F_39 ( V_69 ) ;
F_76 ( V_149 , 0 ) ;
F_32 ( & V_149 -> V_150 , & V_6 . V_134 ) ;
if ( V_149 -> V_158 != NULL ) {
F_32 ( & V_149 -> V_168 ,
& V_6 . V_135 ) ;
F_76 ( V_149 , 0 ) ;
}
F_41 ( V_69 ) ;
if ( V_59 -> V_62 == V_176 ) {
F_106 ( V_149 ) ;
F_11 ( V_6 . V_170 == NULL ) ;
V_6 . V_170 = V_149 ;
continue;
}
if ( V_149 -> V_165 == 0 ||
V_149 -> V_164 == 0 ) {
F_3 ( 0x107 , L_22 ,
F_34 ( V_59 -> V_62 ) ,
V_149 -> V_165 == 0 ?
L_23 : L_24 ) ;
goto V_20;
}
F_40 (tq, i, ni->ni_tx_queues) {
V_182 -> V_192 =
V_182 -> V_193 =
V_182 -> V_194 = F_88 ( V_149 ) ;
}
F_33 ( V_178 , L_25 ,
F_95 ( V_149 -> V_151 ) , V_149 -> V_165 ,
F_88 ( V_149 ) * V_156 ,
V_149 -> V_195 , V_149 -> V_190 ) ;
V_184 ++ ;
}
if ( V_6 . V_169 != NULL && V_184 > 1 ) {
V_62 = V_6 . V_169 -> V_161 -> V_62 ;
F_3 ( 0x109 , L_26
L_21 ,
F_34 ( V_62 ) ) ;
goto V_20;
}
return 0 ;
V_20:
F_91 () ;
while ( ! F_16 ( & V_183 ) ) {
V_149 = F_28 ( V_183 . V_92 , T_7 , V_150 ) ;
F_37 ( & V_149 -> V_150 ) ;
F_100 ( V_149 ) ;
}
return - V_196 ;
}
int
F_107 ( void )
{
int V_3 ;
F_23 () ;
F_11 ( ! V_6 . V_63 ) ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_197 = V_198 ;
V_6 . V_199 = F_108 ( V_198 ) ;
F_11 ( V_6 . V_199 > 0 ) ;
if ( V_6 . V_199 > V_200 ) {
F_13 ( L_27
L_28 ,
V_6 . V_199 , V_200 ) ;
return - 1 ;
}
while ( ( 1 << V_6 . V_201 ) < V_6 . V_199 )
V_6 . V_201 ++ ;
V_3 = F_20 () ;
if ( V_3 != 0 ) {
F_13 ( L_29 , V_3 ) ;
return - 1 ;
}
V_6 . V_129 = 0 ;
V_6 . V_63 = 1 ;
F_109 ( & V_6 . V_202 ) ;
F_14 ( & V_6 . V_64 ) ;
F_14 ( & V_6 . V_203 ) ;
F_14 ( & V_6 . V_204 ) ;
if ( V_205 <= 0 )
V_205 = V_206 ;
else if ( V_205 > V_207 )
V_205 = V_207 ;
V_6 . V_15 = F_110 ( int , 1 ,
F_111 ( V_205 ) - 1 ) ;
F_29 ( & V_208 ) ;
return 0 ;
}
void
F_112 ( void )
{
F_11 ( V_6 . V_63 ) ;
F_11 ( V_6 . V_129 == 0 ) ;
while ( ! F_16 ( & V_6 . V_64 ) )
F_36 ( F_28 ( V_6 . V_64 . V_92 ,
T_1 , V_61 ) ) ;
F_18 () ;
V_6 . V_63 = 0 ;
}
int
F_113 ( T_6 V_128 )
{
int V_209 = 0 ;
int V_3 ;
F_30 ( & V_6 . V_10 ) ;
F_11 ( V_6 . V_63 ) ;
F_33 ( V_210 , L_30 , V_6 . V_129 ) ;
if ( V_6 . V_129 > 0 ) {
V_3 = V_6 . V_129 ++ ;
goto V_116;
}
F_114 () ;
if ( V_128 == V_211 ) {
V_3 = - V_196 ;
goto V_212;
}
V_3 = F_64 ( V_128 ) ;
if ( V_3 != 0 )
goto V_212;
V_3 = F_101 () ;
if ( V_3 != 0 )
goto V_213;
V_3 = F_115 ( F_1 () , & V_209 ) ;
if ( V_3 != 0 )
goto V_214;
V_3 = F_116 () ;
if ( V_3 != 0 )
goto V_214;
V_3 = F_117 ( V_209 ) ;
if ( V_3 != 0 )
goto V_214;
V_3 = F_118 () ;
if ( V_3 != 0 )
goto V_214;
V_6 . V_129 = 1 ;
V_3 = F_119 () ;
if ( V_3 != 0 )
goto V_215;
V_3 = F_120 () ;
if ( V_3 != 0 )
goto V_216;
F_121 () ;
goto V_116;
V_216:
F_122 () ;
V_215:
V_6 . V_129 = 0 ;
F_123 () ;
V_214:
F_124 () ;
F_91 () ;
V_213:
F_68 () ;
V_212:
F_11 ( V_3 < 0 ) ;
V_116:
F_35 ( & V_6 . V_10 ) ;
return V_3 ;
}
int
F_125 ( void )
{
F_30 ( & V_6 . V_10 ) ;
F_11 ( V_6 . V_63 ) ;
F_11 ( V_6 . V_129 > 0 ) ;
if ( V_6 . V_129 != 1 ) {
V_6 . V_129 -- ;
} else {
F_11 ( ! V_6 . V_217 ) ;
F_126 () ;
F_127 () ;
F_122 () ;
V_6 . V_129 = 0 ;
F_123 () ;
F_124 () ;
F_91 () ;
F_68 () ;
}
F_35 ( & V_6 . V_10 ) ;
return 0 ;
}
int
F_128 ( unsigned int V_218 , void * V_219 )
{
struct V_220 * V_221 = V_219 ;
T_10 V_222 = { 0 } ;
T_7 * V_149 ;
int V_3 ;
F_11 ( V_6 . V_63 ) ;
F_11 ( V_6 . V_129 > 0 ) ;
switch ( V_218 ) {
case V_223 :
V_3 = F_129 ( V_221 -> V_224 , & V_222 ) ;
V_221 -> V_225 = V_222 . V_152 ;
return V_3 ;
case V_226 :
return F_69 ( V_221 -> V_225 , V_221 -> V_224 ) ;
case V_227 :
V_3 = F_130 ( V_221 -> V_228 , V_221 -> V_224 ,
V_221 -> V_225 , V_221 -> V_229 ) ;
return ( V_3 != 0 ) ? V_3 : F_116 () ;
case V_230 :
return F_131 ( V_221 -> V_228 , V_221 -> V_225 ) ;
case V_231 :
return F_132 ( V_221 -> V_224 ,
& V_221 -> V_228 , & V_221 -> V_224 ,
& V_221 -> V_225 , & V_221 -> V_232 ,
& V_221 -> V_229 ) ;
case V_233 :
return F_133 ( NULL , V_221 -> V_225 , V_221 -> V_232 ,
F_134 () -
F_98 ( F_135 () -
( V_234 ) V_221 -> V_235 [ 0 ] ) ) ;
case V_236 :
return 0 ;
case V_237 :
V_3 = F_136 ( V_221 -> V_225 , & V_221 -> V_225 , & V_221 -> V_238 [ 1 ] ) ;
if ( V_3 < 0 && V_3 != - V_239 )
return V_3 ;
V_221 -> V_238 [ 0 ] = V_3 ;
return 0 ;
case V_240 :
F_39 ( V_69 ) ;
V_6 . V_241 = V_221 -> V_232 ;
F_41 ( V_69 ) ;
return 0 ;
case V_242 :
V_222 . V_152 = V_221 -> V_225 ;
V_222 . V_243 = V_221 -> V_238 [ 0 ] ;
V_3 = F_137 ( V_222 , V_221 -> V_238 [ 1 ] ,
( T_10 * ) V_221 -> V_244 ,
V_221 -> V_245 / sizeof( T_10 ) ) ;
if ( V_3 < 0 )
return V_3 ;
V_221 -> V_224 = V_3 ;
return 0 ;
case V_246 : {
V_222 = * ( ( T_10 * ) V_219 ) ;
F_138 ( V_222 . V_152 ) ;
V_149 = F_77 ( F_75 ( V_222 . V_152 ) ) ;
if ( V_149 == NULL ) {
F_33 ( V_174 , L_31 , F_139 ( V_222 ) ) ;
} else {
if ( V_149 -> V_161 -> V_247 == NULL ) {
F_33 ( V_174 , L_32 ,
F_139 ( V_222 ) ) ;
} else {
( void ) V_149 -> V_161 -> V_247 ( V_149 , V_218 , V_219 ) ;
}
F_140 ( V_149 ) ;
}
return 0 ;
}
default:
V_149 = F_77 ( V_221 -> V_228 ) ;
if ( V_149 == NULL )
return - V_248 ;
if ( V_149 -> V_161 -> V_247 == NULL )
V_3 = - V_248 ;
else
V_3 = V_149 -> V_161 -> V_247 ( V_149 , V_218 , V_219 ) ;
F_140 ( V_149 ) ;
return V_3 ;
}
}
int
F_129 ( unsigned int V_249 , T_10 * V_222 )
{
struct V_157 * V_149 ;
struct V_12 * V_60 ;
int V_113 ;
int V_3 = - V_250 ;
F_11 ( V_6 . V_63 ) ;
if ( V_6 . V_129 == 0 )
return V_3 ;
V_113 = F_82 () ;
F_27 (tmp, &the_lnet.ln_nis) {
if ( V_249 -- != 0 )
continue;
V_149 = F_28 ( V_60 , T_7 , V_150 ) ;
V_222 -> V_152 = V_149 -> V_151 ;
V_222 -> V_243 = V_6 . V_132 ;
V_3 = 0 ;
break;
}
F_41 ( V_113 ) ;
return V_3 ;
}
void
F_141 ( char * V_251 , int V_252 , T_11 V_253 )
{
snprintf ( V_251 , V_252 , V_254 , V_253 . V_95 ) ;
}
static int
F_142 ( void )
{
int V_11 ;
int V_81 ;
int V_3 ;
unsigned int V_255 ;
T_7 * V_149 ;
T_10 V_222 ;
T_12 * V_256 ;
for ( V_81 = 0 ; ; V_81 ++ ) {
V_3 = F_129 ( V_81 , & V_222 ) ;
if ( V_3 == - V_250 )
break;
F_11 ( V_3 == 0 ) ;
}
V_255 = F_25 ( T_12 , V_257 [ V_81 ] ) ;
F_12 ( V_256 , V_255 ) ;
if ( V_256 == NULL ) {
F_13 ( L_33 , V_81 ) ;
return - V_17 ;
}
V_256 -> V_258 = V_81 ;
V_256 -> V_259 = V_6 . V_132 ;
V_256 -> V_260 = V_261 ;
V_256 -> V_262 = V_263 ;
for ( V_11 = 0 ; V_11 < V_81 ; V_11 ++ ) {
T_13 * V_264 = & V_256 -> V_257 [ V_11 ] ;
V_3 = F_129 ( V_11 , & V_222 ) ;
F_11 ( V_3 == 0 ) ;
V_264 -> V_265 = V_222 . V_152 ;
V_264 -> V_266 = V_267 ;
F_39 ( 0 ) ;
V_149 = F_85 ( V_222 . V_152 , 0 ) ;
F_11 ( V_149 != NULL ) ;
F_143 ( V_149 ) ;
F_11 ( V_149 -> V_268 == NULL ) ;
V_149 -> V_268 = V_264 ;
F_144 ( V_149 ) ;
F_84 ( V_149 , 0 ) ;
F_41 ( 0 ) ;
}
V_6 . V_269 = V_256 ;
return 0 ;
}
static void
F_145 ( void )
{
struct V_157 * V_149 ;
F_39 ( 0 ) ;
F_62 (ni, &the_lnet.ln_nis, ni_list) {
F_143 ( V_149 ) ;
V_149 -> V_268 = NULL ;
F_144 ( V_149 ) ;
}
F_41 ( 0 ) ;
F_17 ( V_6 . V_269 ,
F_25 ( T_12 ,
V_257 [ V_6 . V_269 -> V_258 ] ) ) ;
V_6 . V_269 = NULL ;
return;
}
int
F_119 ( void )
{
T_14 V_270 = { 0 } ;
T_15 V_271 ;
T_10 V_222 ;
int V_3 ;
int V_272 ;
int V_255 ;
V_3 = F_142 () ;
if ( V_3 != 0 )
return V_3 ;
V_3 = F_146 ( 2 , V_273 , & V_6 . V_274 ) ;
if ( V_3 != 0 ) {
F_13 ( L_34 , V_3 ) ;
goto V_275;
}
memset ( & V_222 , 0 , sizeof( T_10 ) ) ;
V_222 . V_152 = V_147 ;
V_222 . V_243 = V_211 ;
V_3 = F_147 ( V_276 , V_222 ,
V_277 , 0 ,
V_278 , V_279 ,
& V_271 ) ;
if ( V_3 != 0 ) {
F_13 ( L_35 , V_3 ) ;
goto V_280;
}
V_255 = F_25 ( T_12 ,
V_257 [ V_6 . V_269 -> V_258 ] ) ;
V_270 . V_281 = V_6 . V_269 ;
V_270 . V_282 = V_255 ;
V_270 . V_283 = V_284 ;
V_270 . V_285 = 0 ;
V_270 . V_286 = V_287 | V_288 |
V_289 ;
V_270 . V_290 = NULL ;
V_270 . V_291 = V_6 . V_274 ;
V_3 = F_148 ( V_271 , V_270 ,
V_292 ,
& V_6 . V_293 ) ;
if ( V_3 != 0 ) {
F_13 ( L_36 , V_3 ) ;
goto V_294;
}
return 0 ;
V_294:
V_272 = F_149 ( V_271 ) ;
F_11 ( V_272 == 0 ) ;
V_280:
V_272 = F_150 ( V_6 . V_274 ) ;
F_11 ( V_272 == 0 ) ;
V_275:
F_145 () ;
return V_3 ;
}
void
F_122 ( void )
{
T_16 V_295 ;
int V_3 ;
int V_296 ;
int V_297 = 1000 ;
T_17 V_298 = F_151 () ;
F_152 ( V_6 . V_293 ) ;
for (; ; ) {
V_3 = F_153 ( & V_6 . V_274 , 1 ,
V_297 , & V_295 , & V_296 ) ;
F_11 ( V_3 >= 0 || V_3 == - V_299 ) ;
if ( V_3 == 0 ) {
F_154 ( L_37 ) ;
V_297 *= 2 ;
continue;
}
if ( V_295 . V_300 )
break;
}
V_3 = F_150 ( V_6 . V_274 ) ;
F_11 ( V_3 == 0 ) ;
F_145 () ;
F_155 ( V_298 ) ;
}
int
F_137 ( T_10 V_222 , int V_297 , T_10 * V_301 , int V_302 )
{
T_18 V_303 ;
T_19 V_304 ;
T_16 V_295 ;
T_14 V_270 = { 0 } ;
int V_296 ;
int V_300 = 0 ;
int V_305 = 0 ;
const int V_306 = 60000 ;
int V_255 = F_25 ( T_12 , V_257 [ V_302 ] ) ;
T_12 * V_307 ;
T_10 V_308 ;
int V_11 ;
int V_309 ;
int V_3 ;
int V_272 ;
T_17 V_298 ;
if ( V_302 <= 0 ||
V_222 . V_152 == V_147 ||
V_297 > 500000 ||
V_302 > 20 )
return - V_248 ;
if ( V_222 . V_243 == V_211 )
V_222 . V_243 = V_310 ;
F_12 ( V_307 , V_255 ) ;
if ( V_307 == NULL )
return - V_17 ;
V_3 = F_146 ( 2 , V_273 , & V_303 ) ;
if ( V_3 != 0 ) {
F_13 ( L_38 , V_3 ) ;
goto V_311;
}
V_270 . V_281 = V_307 ;
V_270 . V_282 = V_255 ;
V_270 . V_283 = 2 ;
V_270 . V_285 = 0 ;
V_270 . V_286 = V_288 ;
V_270 . V_290 = NULL ;
V_270 . V_291 = V_303 ;
V_3 = F_156 ( V_270 , V_278 , & V_304 ) ;
if ( V_3 != 0 ) {
F_13 ( L_39 , V_3 ) ;
goto V_312;
}
V_3 = F_157 ( V_147 , V_304 , V_222 ,
V_276 ,
V_277 , 0 ) ;
if ( V_3 != 0 ) {
V_272 = F_152 ( V_304 ) ;
F_11 ( V_272 == 0 ) ;
V_300 = 1 ;
V_297 = V_306 ;
}
do {
if ( V_300 )
V_298 = F_151 () ;
V_272 = F_153 ( & V_303 , 1 , V_297 , & V_295 , & V_296 ) ;
if ( V_300 )
F_155 ( V_298 ) ;
F_33 ( V_66 , L_40 , V_272 ,
( V_272 <= 0 ) ? - 1 : V_295 . type ,
( V_272 <= 0 ) ? - 1 : V_295 . V_313 ,
( V_272 > 0 && V_295 . V_300 ) ? L_41 : L_23 ) ;
F_11 ( V_272 != - V_299 ) ;
if ( V_272 <= 0 || V_295 . V_313 != 0 ) {
if ( ! V_305 && V_3 == 0 )
V_3 = ( V_272 < 0 ) ? V_272 :
( V_272 == 0 ) ? - V_314 :
V_295 . V_313 ;
if ( ! V_300 ) {
F_152 ( V_304 ) ;
V_300 = 1 ;
V_297 = V_306 ;
} else if ( V_272 == 0 ) {
F_154 ( L_42 ,
F_139 ( V_222 ) ) ;
}
} else if ( V_295 . type == V_315 ) {
V_305 = 1 ;
V_3 = V_295 . V_46 ;
}
} while ( V_272 <= 0 || ! V_295 . V_300 );
if ( ! V_305 ) {
if ( V_3 >= 0 )
F_154 ( L_43 ,
F_139 ( V_222 ) ) ;
V_3 = - V_316 ;
goto V_312;
}
V_309 = V_3 ;
F_11 ( V_309 >= 0 && V_309 <= V_255 ) ;
V_3 = - V_317 ;
if ( V_309 < 8 ) {
F_13 ( L_44 ,
F_139 ( V_222 ) , V_309 ) ;
goto V_312;
}
if ( V_307 -> V_260 == F_158 ( V_261 ) ) {
F_159 ( V_307 ) ;
} else if ( V_307 -> V_260 != V_261 ) {
F_13 ( L_45 ,
F_139 ( V_222 ) , V_307 -> V_260 ) ;
goto V_312;
}
if ( ( V_307 -> V_262 & V_263 ) == 0 ) {
F_13 ( L_46 ,
F_139 ( V_222 ) , V_307 -> V_262 ) ;
goto V_312;
}
if ( V_309 < F_25 ( T_12 , V_257 [ 0 ] ) ) {
F_13 ( L_47 , F_139 ( V_222 ) ,
V_309 , ( int ) F_25 ( T_12 , V_257 [ 0 ] ) ) ;
goto V_312;
}
if ( V_307 -> V_258 < V_302 )
V_302 = V_307 -> V_258 ;
if ( V_309 < F_25 ( T_12 , V_257 [ V_302 ] ) ) {
F_13 ( L_48 , F_139 ( V_222 ) ,
V_309 , ( int ) F_25 ( T_12 , V_257 [ V_302 ] ) ) ;
goto V_312;
}
V_3 = - V_318 ;
for ( V_11 = 0 ; V_11 < V_302 ; V_11 ++ ) {
V_308 . V_243 = V_307 -> V_259 ;
V_308 . V_152 = V_307 -> V_257 [ V_11 ] . V_265 ;
if ( F_160 ( & V_301 [ V_11 ] , & V_308 , sizeof( V_308 ) ) )
goto V_312;
}
V_3 = V_307 -> V_258 ;
V_312:
V_272 = F_150 ( V_303 ) ;
if ( V_272 != 0 )
F_13 ( L_49 , V_272 ) ;
F_11 ( V_272 == 0 ) ;
V_311:
F_17 ( V_307 , V_255 ) ;
return V_3 ;
}
