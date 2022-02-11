static char *
F_1 ( void )
{
return V_1 ;
}
static char *
F_2 ( void )
{
char * V_2 ;
int V_3 ;
if ( * V_4 && * V_5 ) {
F_3 ( 0x101 , L_1 ) ;
return NULL ;
}
if ( * V_5 ) {
V_3 = F_4 ( & V_2 , V_5 ) ;
return ! V_3 ? V_2 : NULL ;
}
if ( * V_4 )
return V_4 ;
return L_2 ;
}
static void
F_5 ( void )
{
F_6 ( & V_6 . V_7 ) ;
F_7 ( & V_6 . V_8 ) ;
F_7 ( & V_6 . V_9 ) ;
F_8 ( & V_6 . V_10 ) ;
F_8 ( & V_6 . V_11 ) ;
}
static int
F_9 ( void )
{
int V_12 ;
struct V_13 * V_14 ;
F_10 ( ! V_6 . V_15 ) ;
F_10 ( V_6 . V_16 > 0 ) ;
F_11 ( V_14 , V_17 * sizeof( * V_14 ) ) ;
if ( ! V_14 ) {
F_12 ( L_3 ) ;
return - V_18 ;
}
for ( V_12 = 0 ; V_12 < V_17 ; V_12 ++ )
F_13 ( & V_14 [ V_12 ] ) ;
V_6 . V_15 = V_14 ;
return 0 ;
}
static void
F_14 ( void )
{
int V_12 ;
if ( ! V_6 . V_15 )
return;
for ( V_12 = 0 ; V_12 < V_17 ; V_12 ++ )
F_10 ( F_15 ( & V_6 . V_15 [ V_12 ] ) ) ;
F_16 ( V_6 . V_15 ,
V_17 *
sizeof( V_6 . V_15 [ 0 ] ) ) ;
V_6 . V_15 = NULL ;
}
static void
F_17 ( void )
{
if ( V_6 . V_19 ) {
F_18 ( V_6 . V_19 ) ;
V_6 . V_19 = NULL ;
}
if ( V_6 . V_20 ) {
F_18 ( V_6 . V_20 ) ;
V_6 . V_20 = NULL ;
}
}
static int
F_19 ( void )
{
F_5 () ;
V_6 . V_19 = F_20 ( F_21 () ) ;
if ( ! V_6 . V_19 )
goto V_21;
V_6 . V_20 = F_20 ( F_21 () ) ;
if ( ! V_6 . V_20 )
goto V_21;
return 0 ;
V_21:
F_17 () ;
return - V_18 ;
}
static void F_22 ( void )
{
F_23 ( V_22 != 0xeebc0ded ) ;
F_23 ( V_23 != 1 ) ;
F_23 ( V_24 != 0 ) ;
F_23 ( V_25 != 0 ) ;
F_23 ( V_26 != 1 ) ;
F_23 ( V_27 != 2 ) ;
F_23 ( V_28 != 3 ) ;
F_23 ( V_29 != 4 ) ;
F_23 ( ( int ) sizeof( struct V_30 ) != 16 ) ;
F_23 ( ( int ) F_24 ( struct V_30 , V_31 ) != 0 ) ;
F_23 ( ( int ) sizeof( ( (struct V_30 * ) 0 ) -> V_31 ) != 8 ) ;
F_23 ( ( int ) F_24 ( struct V_30 , V_32 ) != 8 ) ;
F_23 ( ( int ) sizeof( ( (struct V_30 * ) 0 ) -> V_32 ) != 8 ) ;
F_23 ( ( int ) sizeof( struct V_33 ) != 8 ) ;
F_23 ( ( int ) F_24 ( struct V_33 , V_34 ) != 0 ) ;
F_23 ( ( int ) sizeof( ( (struct V_33 * ) 0 ) -> V_34 ) != 4 ) ;
F_23 ( ( int ) F_24 ( struct V_33 , V_35 ) != 4 ) ;
F_23 ( ( int ) sizeof( ( (struct V_33 * ) 0 ) -> V_35 ) != 2 ) ;
F_23 ( ( int ) F_24 ( struct V_33 , V_36 ) != 6 ) ;
F_23 ( ( int ) sizeof( ( (struct V_33 * ) 0 ) -> V_36 ) != 2 ) ;
F_23 ( ( int ) sizeof( struct V_37 ) != 72 ) ;
F_23 ( ( int ) F_24 ( struct V_37 , V_38 ) != 0 ) ;
F_23 ( ( int ) sizeof( ( (struct V_37 * ) 0 ) -> V_38 ) != 8 ) ;
F_23 ( ( int ) F_24 ( struct V_37 , V_39 ) != 8 ) ;
F_23 ( ( int ) sizeof( ( (struct V_37 * ) 0 ) -> V_39 ) != 8 ) ;
F_23 ( ( int ) F_24 ( struct V_37 , V_40 ) != 16 ) ;
F_23 ( ( int ) sizeof( ( (struct V_37 * ) 0 ) -> V_40 ) != 4 ) ;
F_23 ( ( int ) F_24 ( struct V_37 , V_41 ) != 20 ) ;
F_23 ( ( int ) sizeof( ( (struct V_37 * ) 0 ) -> V_41 ) != 4 ) ;
F_23 ( ( int ) F_24 ( struct V_37 , type ) != 24 ) ;
F_23 ( ( int ) sizeof( ( (struct V_37 * ) 0 ) -> type ) != 4 ) ;
F_23 ( ( int ) F_24 ( struct V_37 , V_42 ) != 28 ) ;
F_23 ( ( int ) sizeof( ( (struct V_37 * ) 0 ) -> V_42 ) != 4 ) ;
F_23 ( ( int ) F_24 ( struct V_37 , V_43 ) != 32 ) ;
F_23 ( ( int ) sizeof( ( (struct V_37 * ) 0 ) -> V_43 ) != 40 ) ;
F_23 ( ( int ) F_24 ( struct V_37 , V_43 . V_44 . V_45 ) != 32 ) ;
F_23 ( ( int ) sizeof( ( (struct V_37 * ) 0 ) -> V_43 . V_44 . V_45 ) != 16 ) ;
F_23 ( ( int ) F_24 ( struct V_37 , V_43 . V_44 . V_46 ) != 48 ) ;
F_23 ( ( int ) sizeof( ( (struct V_37 * ) 0 ) -> V_43 . V_44 . V_46 ) != 8 ) ;
F_23 ( ( int ) F_24 ( struct V_37 , V_43 . V_44 . V_47 ) != 56 ) ;
F_23 ( ( int ) sizeof( ( (struct V_37 * ) 0 ) -> V_43 . V_44 . V_47 ) != 4 ) ;
F_23 ( ( int ) F_24 ( struct V_37 , V_43 . V_48 . V_49 ) != 32 ) ;
F_23 ( ( int ) sizeof( ( (struct V_37 * ) 0 ) -> V_43 . V_48 . V_49 ) != 16 ) ;
F_23 ( ( int ) F_24 ( struct V_37 , V_43 . V_48 . V_46 ) != 48 ) ;
F_23 ( ( int ) sizeof( ( (struct V_37 * ) 0 ) -> V_43 . V_48 . V_46 ) != 8 ) ;
F_23 ( ( int ) F_24 ( struct V_37 , V_43 . V_48 . V_50 ) != 56 ) ;
F_23 ( ( int ) sizeof( ( (struct V_37 * ) 0 ) -> V_43 . V_48 . V_50 ) != 8 ) ;
F_23 ( ( int ) F_24 ( struct V_37 , V_43 . V_48 . V_51 ) != 64 ) ;
F_23 ( ( int ) sizeof( ( (struct V_37 * ) 0 ) -> V_43 . V_48 . V_51 ) != 4 ) ;
F_23 ( ( int ) F_24 ( struct V_37 , V_43 . V_48 . V_52 ) != 68 ) ;
F_23 ( ( int ) sizeof( ( (struct V_37 * ) 0 ) -> V_43 . V_48 . V_52 ) != 4 ) ;
F_23 ( ( int ) F_24 ( struct V_37 , V_43 . V_53 . V_54 ) != 32 ) ;
F_23 ( ( int ) sizeof( ( (struct V_37 * ) 0 ) -> V_43 . V_53 . V_54 ) != 16 ) ;
F_23 ( ( int ) F_24 ( struct V_37 , V_43 . V_53 . V_46 ) != 48 ) ;
F_23 ( ( int ) sizeof( ( (struct V_37 * ) 0 ) -> V_43 . V_53 . V_46 ) != 8 ) ;
F_23 ( ( int ) F_24 ( struct V_37 , V_43 . V_53 . V_51 ) != 56 ) ;
F_23 ( ( int ) sizeof( ( (struct V_37 * ) 0 ) -> V_43 . V_53 . V_51 ) != 4 ) ;
F_23 ( ( int ) F_24 ( struct V_37 , V_43 . V_53 . V_55 ) != 60 ) ;
F_23 ( ( int ) sizeof( ( (struct V_37 * ) 0 ) -> V_43 . V_53 . V_55 ) != 4 ) ;
F_23 ( ( int ) F_24 ( struct V_37 , V_43 . V_53 . V_56 ) != 64 ) ;
F_23 ( ( int ) sizeof( ( (struct V_37 * ) 0 ) -> V_43 . V_53 . V_56 ) != 4 ) ;
F_23 ( ( int ) F_24 ( struct V_37 , V_43 . V_57 . V_45 ) != 32 ) ;
F_23 ( ( int ) sizeof( ( (struct V_37 * ) 0 ) -> V_43 . V_57 . V_45 ) != 16 ) ;
F_23 ( ( int ) F_24 ( struct V_37 , V_43 . V_58 . V_59 ) != 32 ) ;
F_23 ( ( int ) sizeof( ( (struct V_37 * ) 0 ) -> V_43 . V_58 . V_59 ) != 8 ) ;
F_23 ( ( int ) F_24 ( struct V_37 , V_43 . V_58 . type ) != 40 ) ;
F_23 ( ( int ) sizeof( ( (struct V_37 * ) 0 ) -> V_43 . V_58 . type ) != 4 ) ;
}
static struct V_60 *
F_25 ( T_1 type )
{
struct V_60 * V_61 ;
struct V_13 * V_62 ;
F_26 (tmp, &the_lnet.ln_lnds) {
V_61 = F_27 ( V_62 , struct V_60 , V_63 ) ;
if ( V_61 -> V_64 == type )
return V_61 ;
}
return NULL ;
}
void
F_28 ( struct V_60 * V_61 )
{
F_29 ( & V_6 . V_10 ) ;
F_10 ( F_30 ( V_61 -> V_64 ) ) ;
F_10 ( ! F_25 ( V_61 -> V_64 ) ) ;
F_31 ( & V_61 -> V_63 , & V_6 . V_65 ) ;
V_61 -> V_66 = 0 ;
F_32 ( V_67 , L_4 , F_33 ( V_61 -> V_64 ) ) ;
F_34 ( & V_6 . V_10 ) ;
}
void
F_35 ( struct V_60 * V_61 )
{
F_29 ( & V_6 . V_10 ) ;
F_10 ( F_25 ( V_61 -> V_64 ) == V_61 ) ;
F_10 ( ! V_61 -> V_66 ) ;
F_36 ( & V_61 -> V_63 ) ;
F_32 ( V_67 , L_5 , F_33 ( V_61 -> V_64 ) ) ;
F_34 ( & V_6 . V_10 ) ;
}
void
F_37 ( struct V_68 * V_69 )
{
struct V_68 * V_70 ;
int V_12 ;
memset ( V_69 , 0 , sizeof( * V_69 ) ) ;
F_38 ( V_71 ) ;
F_39 (ctr, i, the_lnet.ln_counters) {
V_69 -> V_72 += V_70 -> V_72 ;
V_69 -> V_73 += V_70 -> V_73 ;
V_69 -> V_74 += V_70 -> V_74 ;
V_69 -> V_75 += V_70 -> V_75 ;
V_69 -> V_76 += V_70 -> V_76 ;
V_69 -> V_77 += V_70 -> V_77 ;
V_69 -> V_78 += V_70 -> V_78 ;
V_69 -> V_79 += V_70 -> V_79 ;
V_69 -> V_80 += V_70 -> V_80 ;
V_69 -> V_81 += V_70 -> V_81 ;
V_69 -> V_82 += V_70 -> V_82 ;
}
F_40 ( V_71 ) ;
}
void
F_41 ( void )
{
struct V_68 * V_69 ;
int V_12 ;
F_38 ( V_71 ) ;
F_39 (counters, i, the_lnet.ln_counters)
memset ( V_69 , 0 , sizeof( struct V_68 ) ) ;
F_40 ( V_71 ) ;
}
static char *
F_42 ( int type )
{
switch ( type ) {
default:
F_43 () ;
case V_83 :
return L_6 ;
case V_84 :
return L_7 ;
case V_85 :
return L_8 ;
}
}
static void
F_44 ( struct V_86 * V_87 )
{
int V_88 = 0 ;
if ( ! V_87 -> V_89 )
return;
while ( ! F_15 ( & V_87 -> V_90 ) ) {
struct V_13 * V_91 = V_87 -> V_90 . V_92 ;
F_45 ( V_91 ) ;
if ( V_87 -> V_89 == V_85 ) {
F_46 ( F_27 ( V_91 , struct V_93 , V_94 ) ) ;
} else if ( V_87 -> V_89 == V_83 ) {
F_47 ( F_27 ( V_91 , struct V_95 , V_96 ) ) ;
} else {
F_43 () ;
}
V_88 ++ ;
}
if ( V_88 > 0 ) {
F_12 ( L_9 ,
V_88 , F_42 ( V_87 -> V_89 ) ) ;
}
if ( V_87 -> V_97 ) {
F_16 ( V_87 -> V_97 ,
V_98 * sizeof( V_87 -> V_97 [ 0 ] ) ) ;
V_87 -> V_97 = NULL ;
}
V_87 -> V_89 = 0 ;
}
static int
F_48 ( struct V_86 * V_87 , int V_99 , int type )
{
int V_3 = 0 ;
int V_12 ;
F_10 ( ! V_87 -> V_89 ) ;
V_87 -> V_89 = type ;
F_13 ( & V_87 -> V_90 ) ;
V_87 -> V_100 = ( V_99 << V_101 ) | type ;
F_49 ( V_87 -> V_97 , F_21 () , V_99 ,
V_98 * sizeof( V_87 -> V_97 [ 0 ] ) ) ;
if ( ! V_87 -> V_97 ) {
V_3 = - V_18 ;
goto V_102;
}
for ( V_12 = 0 ; V_12 < V_98 ; V_12 ++ )
F_13 ( & V_87 -> V_97 [ V_12 ] ) ;
return 0 ;
V_102:
F_12 ( L_10 ,
F_42 ( type ) ) ;
F_44 ( V_87 ) ;
return V_3 ;
}
static void
F_50 ( struct V_86 * * V_103 )
{
struct V_86 * V_87 ;
int V_12 ;
F_39 (rec, i, recs)
F_44 ( V_87 ) ;
F_51 ( V_103 ) ;
}
static struct V_86 * *
F_52 ( int type )
{
struct V_86 * * V_103 ;
struct V_86 * V_87 ;
int V_3 ;
int V_12 ;
V_103 = F_53 ( F_21 () , sizeof( * V_87 ) ) ;
if ( ! V_103 ) {
F_12 ( L_11 ,
F_42 ( type ) ) ;
return NULL ;
}
F_39 (rec, i, recs) {
V_3 = F_48 ( V_87 , V_12 , type ) ;
if ( V_3 ) {
F_50 ( V_103 ) ;
return NULL ;
}
}
return V_103 ;
}
struct V_104 *
F_54 ( struct V_86 * V_87 , T_2 V_105 )
{
struct V_13 * V_106 ;
struct V_104 * V_107 ;
unsigned int V_14 ;
if ( ( V_105 & V_108 ) != V_87 -> V_89 )
return NULL ;
V_14 = V_105 >> ( V_101 + V_109 ) ;
V_106 = & V_87 -> V_97 [ V_14 & V_110 ] ;
F_55 (lh, head, lh_hash_chain) {
if ( V_107 -> V_111 == V_105 )
return V_107 ;
}
return NULL ;
}
void
F_56 ( struct V_86 * V_87 ,
struct V_104 * V_107 )
{
unsigned int V_112 = V_101 + V_109 ;
unsigned int V_14 ;
V_107 -> V_111 = V_87 -> V_100 ;
V_87 -> V_100 += 1 << V_112 ;
V_14 = ( V_107 -> V_111 >> V_112 ) & V_110 ;
F_57 ( & V_107 -> V_113 , & V_87 -> V_97 [ V_14 ] ) ;
}
static int
F_58 ( T_3 V_114 )
{
struct V_86 * * V_103 ;
int V_3 = 0 ;
if ( V_114 == V_115 ) {
return - V_116 ;
}
F_10 ( ! V_6 . V_117 ) ;
V_6 . V_118 = 0 ;
F_10 ( ! ( V_114 & V_119 ) ) ;
V_6 . V_120 = V_114 ;
F_13 ( & V_6 . V_121 ) ;
F_13 ( & V_6 . V_122 ) ;
F_13 ( & V_6 . V_123 ) ;
F_13 ( & V_6 . V_124 ) ;
F_13 ( & V_6 . V_125 ) ;
F_13 ( & V_6 . V_126 ) ;
F_13 ( & V_6 . V_127 ) ;
V_3 = F_9 () ;
if ( V_3 )
goto V_21;
V_6 . V_128 = F_59 () ;
V_6 . V_129 = F_53 ( F_21 () ,
sizeof( struct V_68 ) ) ;
if ( ! V_6 . V_129 ) {
F_12 ( L_12 ) ;
V_3 = - V_18 ;
goto V_21;
}
V_3 = F_60 () ;
if ( V_3 )
goto V_21;
V_3 = F_61 () ;
if ( V_3 )
goto V_21;
V_3 = F_48 ( & V_6 . V_130 , 0 ,
V_85 ) ;
if ( V_3 )
goto V_21;
V_103 = F_52 ( V_84 ) ;
if ( ! V_103 ) {
V_3 = - V_18 ;
goto V_21;
}
V_6 . V_131 = V_103 ;
V_103 = F_52 ( V_83 ) ;
if ( ! V_103 ) {
V_3 = - V_18 ;
goto V_21;
}
V_6 . V_132 = V_103 ;
V_3 = F_62 () ;
if ( V_3 ) {
F_12 ( L_13 , V_3 ) ;
goto V_21;
}
return 0 ;
V_21:
F_63 () ;
return V_3 ;
}
static int
F_63 ( void )
{
F_64 ( V_133 , 0 ) ;
F_10 ( ! V_6 . V_117 ) ;
F_10 ( F_15 ( & V_6 . V_121 ) ) ;
F_10 ( F_15 ( & V_6 . V_122 ) ) ;
F_10 ( F_15 ( & V_6 . V_123 ) ) ;
F_10 ( F_15 ( & V_6 . V_124 ) ) ;
F_65 () ;
if ( V_6 . V_132 ) {
F_50 ( V_6 . V_132 ) ;
V_6 . V_132 = NULL ;
}
if ( V_6 . V_131 ) {
F_50 ( V_6 . V_131 ) ;
V_6 . V_131 = NULL ;
}
F_44 ( & V_6 . V_130 ) ;
F_66 () ;
F_67 () ;
F_68 ( 0 ) ;
if ( V_6 . V_129 ) {
F_51 ( V_6 . V_129 ) ;
V_6 . V_129 = NULL ;
}
F_14 () ;
return 0 ;
}
struct V_134 *
F_69 ( T_1 V_135 , int V_99 )
{
struct V_13 * V_62 ;
struct V_134 * V_136 ;
F_10 ( V_99 != V_71 ) ;
F_26 (tmp, &the_lnet.ln_nis) {
V_136 = F_27 ( V_62 , struct V_134 , V_137 ) ;
if ( F_70 ( V_136 -> V_138 ) == V_135 ) {
F_71 ( V_136 , V_99 ) ;
return V_136 ;
}
}
return NULL ;
}
struct V_134 *
F_72 ( T_1 V_135 )
{
struct V_134 * V_136 ;
F_38 ( 0 ) ;
V_136 = F_69 ( V_135 , 0 ) ;
F_40 ( 0 ) ;
return V_136 ;
}
static unsigned int
F_73 ( T_4 V_139 , unsigned int V_140 )
{
T_2 V_141 = V_139 ;
unsigned int V_142 ;
F_10 ( V_140 >= 1 && V_140 <= V_143 ) ;
if ( V_140 == 1 )
return 0 ;
V_142 = F_74 ( V_141 , V_109 ) ;
if ( V_142 < V_140 )
return V_142 ;
return ( unsigned int ) ( V_141 + V_142 + ( V_142 >> 1 ) ) % V_140 ;
}
int
F_75 ( T_4 V_139 )
{
struct V_134 * V_136 ;
if ( V_143 == 1 )
return 0 ;
if ( ! F_15 ( & V_6 . V_123 ) ) {
F_55 (ni, &the_lnet.ln_nis_cpt, ni_cptlist) {
if ( F_70 ( V_136 -> V_138 ) != F_70 ( V_139 ) )
continue;
F_10 ( V_136 -> V_144 ) ;
return V_136 -> V_144 [ F_73
( V_139 , V_136 -> V_145 ) ] ;
}
}
return F_73 ( V_139 , V_143 ) ;
}
int
F_76 ( T_4 V_139 )
{
int V_99 ;
int V_146 ;
if ( V_143 == 1 )
return 0 ;
if ( F_15 ( & V_6 . V_123 ) )
return F_73 ( V_139 , V_143 ) ;
V_99 = F_77 () ;
V_146 = F_75 ( V_139 ) ;
F_40 ( V_99 ) ;
return V_146 ;
}
int
F_78 ( T_1 V_135 )
{
struct V_134 * V_136 ;
int V_99 ;
V_99 = F_77 () ;
V_136 = F_69 ( V_135 , V_99 ) ;
if ( V_136 )
F_79 ( V_136 , V_99 ) ;
F_40 ( V_99 ) ;
return ! ! V_136 ;
}
struct V_134 *
F_80 ( T_4 V_139 , int V_99 )
{
struct V_134 * V_136 ;
struct V_13 * V_62 ;
F_10 ( V_99 != V_71 ) ;
F_26 (tmp, &the_lnet.ln_nis) {
V_136 = F_27 ( V_62 , struct V_134 , V_137 ) ;
if ( V_136 -> V_138 == V_139 ) {
F_71 ( V_136 , V_99 ) ;
return V_136 ;
}
}
return NULL ;
}
int
F_81 ( T_4 V_139 )
{
struct V_134 * V_136 ;
int V_99 ;
V_99 = F_77 () ;
V_136 = F_80 ( V_139 , V_99 ) ;
if ( V_136 )
F_79 ( V_136 , V_99 ) ;
F_40 ( V_99 ) ;
return ! ! V_136 ;
}
int
F_82 ( void )
{
int V_88 = 0 ;
struct V_13 * V_62 ;
struct V_134 * V_136 ;
int V_99 ;
V_99 = F_77 () ;
F_26 (tmp, &the_lnet.ln_nis) {
V_136 = F_27 ( V_62 , struct V_134 , V_137 ) ;
if ( V_136 -> V_147 -> V_148 )
V_88 ++ ;
}
F_40 ( V_99 ) ;
return V_88 ;
}
static struct V_149 *
F_83 ( int V_150 )
{
struct V_149 * V_151 ;
unsigned int V_152 ;
V_152 = F_24 ( struct V_149 , V_153 [ V_150 ] ) ;
F_11 ( V_151 , V_152 ) ;
if ( ! V_151 ) {
F_12 ( L_14 , V_150 ) ;
return NULL ;
}
V_151 -> V_154 = V_150 ;
V_151 -> V_155 = V_6 . V_120 ;
V_151 -> V_156 = V_157 ;
V_151 -> V_158 = V_159 ;
return V_151 ;
}
static inline int
F_84 ( void )
{
struct V_134 * V_136 ;
int V_88 = 0 ;
F_38 ( 0 ) ;
F_55 (ni, &the_lnet.ln_nis, ni_list)
V_88 ++ ;
F_40 ( 0 ) ;
return V_88 ;
}
static inline void
F_85 ( struct V_149 * V_160 )
{
F_16 ( V_160 ,
F_24 ( struct V_149 ,
V_153 [ V_160 -> V_154 ] ) ) ;
}
static void
F_86 ( void )
{
struct V_134 * V_136 ;
F_38 ( V_71 ) ;
F_55 (ni, &the_lnet.ln_nis, ni_list) {
F_87 ( V_136 ) ;
V_136 -> V_161 = NULL ;
F_88 ( V_136 ) ;
}
F_85 ( V_6 . V_162 ) ;
V_6 . V_162 = NULL ;
F_40 ( V_71 ) ;
}
static void
F_89 ( struct V_163 * V_164 )
{
struct V_149 * V_160 = V_164 -> V_165 . V_166 ;
if ( V_164 -> V_167 )
V_160 -> V_158 = V_168 ;
}
static int
F_90 ( struct V_149 * * V_169 ,
struct V_170 * V_171 ,
int V_172 , bool V_173 )
{
struct V_174 V_175 = { V_133 , V_115 } ;
struct V_176 V_177 ;
struct V_178 V_165 = { NULL } ;
int V_3 , V_179 ;
if ( V_173 ) {
V_3 = F_91 ( 0 , F_89 ,
& V_6 . V_180 ) ;
if ( V_3 ) {
F_12 ( L_15 , V_3 ) ;
return V_3 ;
}
}
* V_169 = F_83 ( V_172 ) ;
if ( ! * V_169 ) {
V_3 = - V_18 ;
goto V_181;
}
V_3 = F_92 ( V_182 , V_175 ,
V_183 , 0 ,
V_184 , V_185 ,
& V_177 ) ;
if ( V_3 ) {
F_12 ( L_16 , V_3 ) ;
goto V_186;
}
V_165 . V_187 = * V_169 ;
V_165 . V_188 = F_24 ( struct V_149 ,
V_153 [ ( * V_169 ) -> V_154 ] ) ;
V_165 . V_189 = V_190 ;
V_165 . V_191 = 0 ;
V_165 . V_192 = V_193 | V_194 |
V_195 ;
V_165 . V_166 = NULL ;
V_165 . V_196 = V_6 . V_180 ;
V_165 . V_166 = * V_169 ;
V_3 = F_93 ( V_177 , V_165 , V_197 , V_171 ) ;
if ( V_3 ) {
F_12 ( L_17 , V_3 ) ;
goto V_198;
}
return 0 ;
V_198:
V_179 = F_94 ( V_177 ) ;
F_10 ( ! V_179 ) ;
V_186:
F_85 ( * V_169 ) ;
* V_169 = NULL ;
V_181:
if ( V_173 )
F_95 ( V_6 . V_180 ) ;
return V_3 ;
}
static void
F_96 ( struct V_149 * V_160 ,
struct V_170 * V_171 )
{
T_5 V_199 = F_97 () ;
F_98 ( * V_171 ) ;
F_99 ( V_171 ) ;
while ( V_160 -> V_158 != V_168 ) {
F_32 ( V_67 , L_18 ) ;
F_100 ( V_200 ) ;
F_101 ( F_102 ( 1 ) ) ;
}
F_103 ( V_199 ) ;
}
static void
F_104 ( struct V_149 * V_151 )
{
struct V_201 * V_202 ;
struct V_134 * V_136 ;
int V_12 = 0 ;
F_55 (ni, &the_lnet.ln_nis, ni_list) {
F_10 ( V_12 < V_151 -> V_154 ) ;
V_202 = & V_151 -> V_153 [ V_12 ] ;
V_202 -> V_203 = V_136 -> V_138 ;
F_87 ( V_136 ) ;
V_202 -> V_204 = ( V_136 -> V_161 ) ?
V_136 -> V_161 -> V_204 : V_205 ;
V_136 -> V_161 = V_202 ;
F_88 ( V_136 ) ;
V_12 ++ ;
}
}
static void
F_105 ( struct V_149 * V_160 ,
struct V_170 V_171 )
{
struct V_149 * V_206 = NULL ;
struct V_170 V_207 ;
F_38 ( V_71 ) ;
if ( ! V_6 . V_118 )
V_160 -> V_158 |= V_208 ;
F_104 ( V_160 ) ;
if ( V_6 . V_162 ) {
V_206 = V_6 . V_162 ;
V_207 = V_6 . V_209 ;
}
V_6 . V_209 = V_171 ;
V_6 . V_162 = V_160 ;
F_40 ( V_71 ) ;
if ( V_206 ) {
F_96 ( V_206 , & V_207 ) ;
F_85 ( V_206 ) ;
}
}
static void
F_106 ( void )
{
int V_3 ;
F_96 ( V_6 . V_162 ,
& V_6 . V_209 ) ;
V_3 = F_95 ( V_6 . V_180 ) ;
F_10 ( ! V_3 ) ;
F_86 () ;
}
static int
F_107 ( struct V_134 * V_136 )
{
int V_210 ;
F_10 ( V_136 -> V_145 >= 1 ) ;
if ( V_136 -> V_145 == 1 )
return V_136 -> V_211 ;
V_210 = V_136 -> V_211 / V_136 -> V_145 ;
V_210 = F_108 ( V_210 , 8 * V_136 -> V_212 ) ;
V_210 = F_109 ( V_210 , V_136 -> V_211 ) ;
return V_210 ;
}
static void
F_110 ( struct V_134 * V_136 )
{
if ( ! F_15 ( & V_136 -> V_213 ) ) {
F_45 ( & V_136 -> V_213 ) ;
F_79 ( V_136 , 0 ) ;
}
F_10 ( ! F_15 ( & V_136 -> V_137 ) ) ;
F_111 ( & V_136 -> V_137 , & V_6 . V_124 ) ;
F_79 ( V_136 , 0 ) ;
}
static void
F_112 ( void )
{
int V_12 ;
int V_214 ;
struct V_134 * V_136 ;
struct V_134 * V_215 ;
V_12 = 2 ;
F_113 (ni, temp, &the_lnet.ln_nis_zombie, ni_list) {
int * V_216 ;
int V_217 ;
F_45 ( & V_136 -> V_137 ) ;
F_39 (ref, j, ni->ni_refs) {
if ( ! * V_216 )
continue;
F_57 ( & V_136 -> V_137 , & V_6 . V_124 ) ;
break;
}
if ( ! F_15 ( & V_136 -> V_137 ) ) {
F_40 ( V_71 ) ;
++ V_12 ;
if ( ( V_12 & ( - V_12 ) ) == V_12 ) {
F_32 ( V_218 , L_19 ,
F_114 ( V_136 -> V_138 ) ) ;
}
F_100 ( V_200 ) ;
F_101 ( F_102 ( 1 ) ) ;
F_38 ( V_71 ) ;
continue;
}
V_136 -> V_147 -> V_66 -- ;
F_40 ( V_71 ) ;
V_214 = V_136 -> V_147 -> V_64 == V_219 ;
F_10 ( ! F_115 () ) ;
V_136 -> V_147 -> V_220 ( V_136 ) ;
if ( ! V_214 )
F_32 ( V_221 , L_20 ,
F_114 ( V_136 -> V_138 ) ) ;
F_116 ( V_136 ) ;
V_12 = 2 ;
F_38 ( V_71 ) ;
}
}
static void
F_117 ( void )
{
struct V_134 * V_136 ;
struct V_134 * V_215 ;
int V_12 ;
F_10 ( ! V_6 . V_222 ) ;
F_10 ( ! V_6 . V_117 ) ;
F_10 ( F_15 ( & V_6 . V_124 ) ) ;
F_38 ( V_71 ) ;
V_6 . V_222 = 1 ;
F_113 (ni, temp, &the_lnet.ln_nis, ni_list) {
F_110 ( V_136 ) ;
}
if ( V_6 . V_223 ) {
F_79 ( V_6 . V_223 , 0 ) ;
V_6 . V_223 = NULL ;
}
F_40 ( V_71 ) ;
for ( V_12 = 0 ; V_12 < V_6 . V_224 ; V_12 ++ )
F_118 ( V_12 ) ;
F_119 ( NULL ) ;
F_38 ( V_71 ) ;
F_112 () ;
V_6 . V_222 = 0 ;
F_40 ( V_71 ) ;
}
static void
F_120 ( struct V_134 * V_136 )
{
int V_12 ;
F_38 ( V_71 ) ;
F_110 ( V_136 ) ;
F_40 ( V_71 ) ;
for ( V_12 = 0 ; V_12 < V_6 . V_224 ; V_12 ++ )
F_121 ( V_136 , V_12 , L_21 ) ;
F_119 ( V_136 ) ;
F_38 ( V_71 ) ;
F_112 () ;
F_40 ( V_71 ) ;
}
static int
F_122 ( struct V_134 * V_136 , struct V_225 * V_226 )
{
struct V_227 * V_228 = NULL ;
int V_3 = - V_229 ;
int V_64 ;
struct V_60 * V_61 ;
struct V_230 * V_231 ;
int V_12 ;
V_64 = F_123 ( F_70 ( V_136 -> V_138 ) ) ;
F_10 ( F_30 ( V_64 ) ) ;
if ( V_64 == V_232 || V_64 == V_233 ||
V_64 == V_234 || V_64 == V_235 ) {
F_12 ( L_22 , F_33 ( V_64 ) ) ;
goto V_236;
}
F_38 ( V_71 ) ;
V_3 = F_124 ( F_70 ( V_136 -> V_138 ) , & V_6 . V_122 ) ;
F_40 ( V_71 ) ;
if ( ! V_3 ) {
if ( V_64 == V_219 ) {
F_116 ( V_136 ) ;
return 0 ;
}
F_12 ( L_23 ,
F_125 ( F_70 ( V_136 -> V_138 ) ) ) ;
V_3 = - V_237 ;
goto V_236;
}
F_29 ( & V_6 . V_10 ) ;
V_61 = F_25 ( V_64 ) ;
if ( ! V_61 ) {
F_34 ( & V_6 . V_10 ) ;
V_3 = F_126 ( L_24 , F_127 ( V_64 ) ) ;
F_29 ( & V_6 . V_10 ) ;
V_61 = F_25 ( V_64 ) ;
if ( ! V_61 ) {
F_34 ( & V_6 . V_10 ) ;
F_12 ( L_25 ,
F_33 ( V_64 ) ,
F_127 ( V_64 ) , V_3 ) ;
V_3 = - V_229 ;
goto V_236;
}
}
F_38 ( V_71 ) ;
V_61 -> V_66 ++ ;
F_40 ( V_71 ) ;
V_136 -> V_147 = V_61 ;
if ( V_226 && V_226 -> V_238 . V_239 > sizeof( * V_226 ) )
V_228 = (struct V_227 * ) V_226 -> V_240 ;
if ( V_228 ) {
F_11 ( V_136 -> V_241 ,
sizeof( * V_136 -> V_241 ) ) ;
if ( ! V_136 -> V_241 ) {
F_34 ( & V_6 . V_10 ) ;
V_3 = - V_18 ;
goto V_236;
}
memcpy ( V_136 -> V_241 , V_228 ,
sizeof( * V_136 -> V_241 ) ) ;
}
if ( V_226 ) {
if ( V_226 -> V_242 . V_243 . V_244 >= 0 )
V_136 -> V_245 =
V_226 -> V_242 . V_243 . V_244 ;
if ( V_226 -> V_242 . V_243 . V_246 >= 0 )
V_136 -> V_247 =
V_226 -> V_242 . V_243 . V_246 ;
if ( V_226 -> V_242 . V_243 . V_248 != - 1 )
V_136 -> V_212 =
V_226 -> V_242 . V_243 . V_248 ;
if ( V_226 -> V_242 . V_243 . V_249 >= 0 )
V_136 -> V_211 =
V_226 -> V_242 . V_243 . V_249 ;
}
V_3 = V_61 -> V_250 ( V_136 ) ;
F_34 ( & V_6 . V_10 ) ;
if ( V_3 ) {
F_3 ( 0x105 , L_26 ,
V_3 , F_33 ( V_61 -> V_64 ) ) ;
F_38 ( V_71 ) ;
V_61 -> V_66 -- ;
F_40 ( V_71 ) ;
goto V_236;
}
F_10 ( V_136 -> V_247 <= 0 || V_61 -> V_251 ) ;
F_38 ( V_71 ) ;
F_71 ( V_136 , 0 ) ;
F_31 ( & V_136 -> V_137 , & V_6 . V_122 ) ;
if ( V_136 -> V_144 ) {
F_71 ( V_136 , 0 ) ;
F_31 ( & V_136 -> V_213 , & V_6 . V_123 ) ;
}
F_40 ( V_71 ) ;
if ( V_61 -> V_64 == V_219 ) {
F_128 ( V_136 ) ;
F_10 ( ! V_6 . V_223 ) ;
V_6 . V_223 = V_136 ;
return 0 ;
}
if ( ! V_136 -> V_212 || ! V_136 -> V_211 ) {
F_3 ( 0x107 , L_27 ,
F_33 ( V_61 -> V_64 ) ,
! V_136 -> V_212 ?
L_28 : L_29 ) ;
F_120 ( V_136 ) ;
return - V_229 ;
}
F_39 (tq, i, ni->ni_tx_queues) {
V_231 -> V_252 =
V_231 -> V_253 =
V_231 -> V_254 = F_107 ( V_136 ) ;
}
F_32 ( V_221 , L_30 ,
F_114 ( V_136 -> V_138 ) , V_136 -> V_212 ,
F_107 ( V_136 ) * V_143 ,
V_136 -> V_245 , V_136 -> V_247 ) ;
return 0 ;
V_236:
F_116 ( V_136 ) ;
return V_3 ;
}
static int
F_129 ( struct V_13 * V_255 )
{
struct V_134 * V_136 ;
int V_3 ;
int V_172 = 0 ;
while ( ! F_15 ( V_255 ) ) {
V_136 = F_27 ( V_255 -> V_92 , struct V_134 , V_137 ) ;
F_36 ( & V_136 -> V_137 ) ;
V_3 = F_122 ( V_136 , NULL ) ;
if ( V_3 < 0 )
goto V_21;
V_172 ++ ;
}
return V_172 ;
V_21:
F_117 () ;
return V_3 ;
}
int F_130 ( void )
{
int V_3 ;
F_22 () ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_256 = V_257 ;
V_6 . V_258 = F_131 ( V_257 ) ;
F_10 ( V_6 . V_258 > 0 ) ;
if ( V_6 . V_258 > V_259 ) {
F_12 ( L_31 ,
V_6 . V_258 , V_259 ) ;
return - V_260 ;
}
while ( ( 1 << V_6 . V_261 ) < V_6 . V_258 )
V_6 . V_261 ++ ;
V_3 = F_19 () ;
if ( V_3 ) {
F_12 ( L_32 , V_3 ) ;
return V_3 ;
}
V_6 . V_117 = 0 ;
F_132 ( & V_6 . V_262 ) ;
F_13 ( & V_6 . V_65 ) ;
F_13 ( & V_6 . V_263 ) ;
F_13 ( & V_6 . V_264 ) ;
if ( V_265 <= 0 )
V_265 = V_266 ;
else if ( V_265 > V_267 )
V_265 = V_267 ;
V_6 . V_16 = F_133 ( int , 1 ,
F_134 ( V_265 ) - 1 ) ;
F_28 ( & V_268 ) ;
return 0 ;
}
void F_135 ( void )
{
F_10 ( ! V_6 . V_117 ) ;
while ( ! F_15 ( & V_6 . V_65 ) )
F_35 ( F_27 ( V_6 . V_65 . V_92 ,
struct V_60 , V_63 ) ) ;
F_17 () ;
}
int
F_136 ( T_3 V_114 )
{
int V_269 = 0 ;
int V_3 ;
int V_172 ;
struct V_149 * V_160 ;
struct V_170 V_171 ;
struct V_13 V_270 ;
F_13 ( & V_270 ) ;
F_29 ( & V_6 . V_11 ) ;
F_32 ( V_271 , L_33 , V_6 . V_117 ) ;
if ( V_6 . V_117 > 0 ) {
V_3 = V_6 . V_117 ++ ;
F_34 ( & V_6 . V_11 ) ;
return V_3 ;
}
V_3 = F_58 ( V_114 ) ;
if ( V_3 ) {
F_34 ( & V_6 . V_11 ) ;
return V_3 ;
}
if ( ! F_137 ( F_138 ( V_219 , 0 ) , NULL , & V_270 ) ) {
V_3 = - V_18 ;
goto V_272;
}
if ( ! V_6 . V_273 ) {
V_3 = F_139 ( & V_270 , F_2 () ) ;
if ( V_3 < 0 )
goto V_272;
}
V_172 = F_129 ( & V_270 ) ;
if ( V_172 < 0 ) {
V_3 = V_172 ;
goto V_272;
}
if ( ! V_6 . V_273 ) {
V_3 = F_140 ( F_1 () , & V_269 ) ;
if ( V_3 )
goto V_274;
V_3 = F_141 () ;
if ( V_3 )
goto V_275;
V_3 = F_142 ( V_269 ) ;
if ( V_3 )
goto V_275;
}
V_3 = F_143 () ;
if ( V_3 )
goto V_275;
V_6 . V_117 = 1 ;
V_3 = F_90 ( & V_160 , & V_171 , V_172 , true ) ;
if ( V_3 )
goto V_276;
F_105 ( V_160 , V_171 ) ;
V_3 = F_144 () ;
if ( V_3 )
goto V_277;
F_145 () ;
F_146 () ;
F_34 ( & V_6 . V_11 ) ;
return 0 ;
V_277:
F_106 () ;
V_276:
V_6 . V_117 = 0 ;
F_147 () ;
V_275:
if ( ! V_6 . V_273 )
F_148 () ;
V_274:
F_117 () ;
V_272:
F_63 () ;
F_10 ( V_3 < 0 ) ;
F_34 ( & V_6 . V_11 ) ;
while ( ! F_15 ( & V_270 ) ) {
struct V_134 * V_136 ;
V_136 = F_27 ( V_270 . V_92 , struct V_134 , V_137 ) ;
F_45 ( & V_136 -> V_137 ) ;
F_116 ( V_136 ) ;
}
return V_3 ;
}
int
F_149 ( void )
{
F_29 ( & V_6 . V_11 ) ;
F_10 ( V_6 . V_117 > 0 ) ;
if ( V_6 . V_117 != 1 ) {
V_6 . V_117 -- ;
} else {
F_10 ( ! V_6 . V_278 ) ;
F_150 () ;
F_151 () ;
F_152 () ;
F_106 () ;
V_6 . V_117 = 0 ;
F_147 () ;
F_148 () ;
F_117 () ;
F_63 () ;
}
F_34 ( & V_6 . V_11 ) ;
return 0 ;
}
static void
F_153 ( struct V_134 * V_136 , struct V_225 * V_279 )
{
struct V_227 * V_280 = NULL ;
struct V_281 * V_282 ;
T_6 V_283 , V_284 = 0 ;
int V_12 ;
if ( ! V_136 || ! V_279 )
return;
V_282 = (struct V_281 * ) V_279 -> V_240 ;
if ( ! V_282 )
return;
F_23 ( F_154 ( V_136 -> V_285 ) !=
F_154 ( V_282 -> V_285 ) ) ;
for ( V_12 = 0 ; V_12 < F_154 ( V_136 -> V_285 ) ; V_12 ++ ) {
if ( ! V_136 -> V_285 [ V_12 ] )
break;
strncpy ( V_282 -> V_285 [ V_12 ] ,
V_136 -> V_285 [ V_12 ] ,
sizeof( V_282 -> V_285 [ V_12 ] ) ) ;
}
V_279 -> V_286 = V_136 -> V_138 ;
V_279 -> V_242 . V_243 . V_246 = V_136 -> V_247 ;
V_279 -> V_242 . V_243 . V_249 = V_136 -> V_211 ;
V_279 -> V_242 . V_243 . V_248 = V_136 -> V_212 ;
V_279 -> V_242 . V_243 . V_244 = V_136 -> V_245 ;
V_282 -> V_161 = V_136 -> V_161 -> V_204 ;
if ( V_136 -> V_144 ) {
int V_287 = F_109 ( V_136 -> V_145 , V_288 ) ;
for ( V_12 = 0 ; V_12 < V_287 ; V_12 ++ )
V_282 -> V_144 [ V_12 ] = V_136 -> V_144 [ V_12 ] ;
V_279 -> V_289 = V_287 ;
}
V_283 = sizeof( * V_279 ) + sizeof( * V_282 ) ;
if ( V_279 -> V_238 . V_239 > V_283 )
V_284 = V_279 -> V_238 . V_239 - V_283 ;
V_283 = F_109 ( V_284 , sizeof( * V_136 -> V_241 ) ) ;
V_280 = (struct V_227 * ) V_282 -> V_240 ;
if ( V_136 -> V_241 && V_280 && V_283 ) {
memcpy ( V_280 , V_136 -> V_241 , V_283 ) ;
V_279 -> V_242 . V_243 . V_290 = 1 ;
if ( V_284 > sizeof( * V_136 -> V_241 ) ) {
V_283 = V_284 - sizeof( V_136 -> V_241 ) ;
V_279 -> V_238 . V_239 -= V_283 ;
}
}
}
static int
F_155 ( struct V_225 * V_279 )
{
struct V_134 * V_136 ;
struct V_13 * V_62 ;
int V_291 = V_279 -> V_292 ;
int V_99 , V_12 = 0 ;
int V_3 = - V_293 ;
V_99 = F_77 () ;
F_26 (tmp, &the_lnet.ln_nis) {
if ( V_12 ++ != V_291 )
continue;
V_136 = F_27 ( V_62 , struct V_134 , V_137 ) ;
F_87 ( V_136 ) ;
F_153 ( V_136 , V_279 ) ;
F_88 ( V_136 ) ;
V_3 = 0 ;
break;
}
F_40 ( V_99 ) ;
return V_3 ;
}
int
F_156 ( T_3 V_114 , struct V_225 * V_226 )
{
char * V_2 = V_226 -> V_242 . V_243 . V_294 ;
struct V_149 * V_160 ;
struct V_170 V_171 ;
struct V_134 * V_136 ;
struct V_13 V_270 ;
struct V_295 * V_296 ;
int V_3 ;
F_13 ( & V_270 ) ;
V_3 = F_139 ( & V_270 , V_2 ) ;
if ( V_3 <= 0 )
return ! V_3 ? - V_229 : V_3 ;
F_29 ( & V_6 . V_11 ) ;
if ( V_3 > 1 ) {
V_3 = - V_229 ;
goto V_236;
}
V_136 = F_27 ( V_270 . V_92 , struct V_134 , V_137 ) ;
F_38 ( V_71 ) ;
V_296 = F_157 ( F_70 ( V_136 -> V_138 ) ) ;
F_40 ( V_71 ) ;
if ( V_296 ) {
F_12 ( L_34 ,
V_2 ) ;
V_3 = - V_297 ;
goto V_236;
}
V_3 = F_90 ( & V_160 , & V_171 , 1 + F_84 () ,
false ) ;
if ( V_3 )
goto V_236;
F_45 ( & V_136 -> V_137 ) ;
V_3 = F_122 ( V_136 , V_226 ) ;
if ( V_3 )
goto V_298;
if ( V_136 -> V_147 -> V_148 ) {
V_3 = F_143 () ;
if ( V_3 < 0 ) {
F_12 ( L_35 ) ;
F_120 ( V_136 ) ;
goto V_298;
}
}
F_105 ( V_160 , V_171 ) ;
F_34 ( & V_6 . V_11 ) ;
return 0 ;
V_298:
F_96 ( V_160 , & V_171 ) ;
F_85 ( V_160 ) ;
V_236:
F_34 ( & V_6 . V_11 ) ;
while ( ! F_15 ( & V_270 ) ) {
V_136 = F_27 ( V_270 . V_92 , struct V_134 , V_137 ) ;
F_45 ( & V_136 -> V_137 ) ;
F_116 ( V_136 ) ;
}
return V_3 ;
}
int
F_158 ( T_1 V_135 )
{
struct V_134 * V_136 ;
struct V_149 * V_160 ;
struct V_170 V_171 ;
int V_3 ;
if ( F_123 ( V_135 ) == V_219 )
return - V_229 ;
F_29 ( & V_6 . V_11 ) ;
V_3 = F_90 ( & V_160 , & V_171 ,
F_84 () - 1 , false ) ;
if ( V_3 )
goto V_102;
V_136 = F_72 ( V_135 ) ;
if ( ! V_136 ) {
V_3 = - V_229 ;
goto V_21;
}
F_79 ( V_136 , 0 ) ;
F_120 ( V_136 ) ;
if ( ! F_82 () )
F_147 () ;
F_105 ( V_160 , V_171 ) ;
goto V_102;
V_21:
F_96 ( V_160 , & V_171 ) ;
F_85 ( V_160 ) ;
V_102:
F_34 ( & V_6 . V_11 ) ;
return V_3 ;
}
int
F_159 ( unsigned int V_299 , void * V_300 )
{
struct V_301 * V_302 = V_300 ;
struct V_225 * V_279 ;
struct V_174 V_175 = { 0 } ;
struct V_134 * V_136 ;
int V_3 ;
unsigned long V_303 ;
F_23 ( V_304 <
sizeof( struct V_281 ) +
sizeof( struct V_225 ) ) ;
switch ( V_299 ) {
case V_305 :
V_3 = F_160 ( V_302 -> V_306 , & V_175 ) ;
V_302 -> V_307 = V_175 . V_139 ;
return V_3 ;
case V_308 :
return F_64 ( V_302 -> V_307 , V_302 -> V_306 ) ;
case V_309 :
V_279 = V_300 ;
if ( V_279 -> V_238 . V_239 < sizeof( * V_279 ) )
return - V_229 ;
F_29 ( & V_6 . V_11 ) ;
V_3 = F_161 ( V_279 -> V_243 ,
V_279 -> V_242 . V_310 . V_311 ,
V_279 -> V_286 ,
V_279 -> V_242 . V_310 . V_312 ) ;
if ( ! V_3 ) {
V_3 = F_141 () ;
if ( V_3 )
F_162 ( V_279 -> V_243 ,
V_279 -> V_286 ) ;
}
F_34 ( & V_6 . V_11 ) ;
return V_3 ;
case V_313 :
V_279 = V_300 ;
if ( V_279 -> V_238 . V_239 < sizeof( * V_279 ) )
return - V_229 ;
F_29 ( & V_6 . V_11 ) ;
V_3 = F_162 ( V_279 -> V_243 , V_279 -> V_286 ) ;
F_34 ( & V_6 . V_11 ) ;
return V_3 ;
case V_314 :
V_279 = V_300 ;
if ( V_279 -> V_238 . V_239 < sizeof( * V_279 ) )
return - V_229 ;
return F_163 ( V_279 -> V_292 ,
& V_279 -> V_243 ,
& V_279 -> V_242 . V_310 . V_311 ,
& V_279 -> V_286 ,
& V_279 -> V_242 . V_310 . V_315 ,
& V_279 -> V_242 . V_310 . V_312 ) ;
case V_316 : {
T_6 V_317 = sizeof( * V_279 ) +
sizeof( struct V_281 ) ;
V_279 = V_300 ;
if ( V_279 -> V_238 . V_239 < V_317 )
return - V_229 ;
return F_155 ( V_279 ) ;
}
case V_318 : {
struct V_319 * V_320 = V_300 ;
if ( V_320 -> V_321 . V_239 < sizeof( * V_320 ) )
return - V_229 ;
F_37 ( & V_320 -> V_322 ) ;
return 0 ;
}
case V_323 :
V_279 = V_300 ;
if ( V_279 -> V_238 . V_239 < sizeof( * V_279 ) )
return - V_229 ;
F_29 ( & V_6 . V_11 ) ;
if ( V_279 -> V_242 . V_324 . V_325 ) {
V_3 = F_164 () ;
F_34 ( & V_6 . V_11 ) ;
return V_3 ;
}
F_165 () ;
F_34 ( & V_6 . V_11 ) ;
return 0 ;
case V_326 :
V_279 = V_300 ;
if ( V_279 -> V_238 . V_239 < sizeof( * V_279 ) )
return - V_229 ;
F_29 ( & V_6 . V_11 ) ;
V_3 = F_166 ( V_279 -> V_242 . V_324 . V_327 ,
V_279 -> V_242 . V_324 . V_328 ,
V_279 -> V_242 . V_324 . V_329 ) ;
F_34 ( & V_6 . V_11 ) ;
return V_3 ;
case V_330 : {
struct V_331 * V_332 ;
T_6 V_317 = sizeof( * V_279 ) + sizeof( * V_332 ) ;
V_279 = V_300 ;
if ( V_279 -> V_238 . V_239 < V_317 )
return - V_229 ;
V_332 = (struct V_331 * ) V_279 -> V_240 ;
return F_167 ( V_279 -> V_292 , V_332 ) ;
}
case V_333 : {
struct V_334 * V_335 = V_300 ;
if ( V_335 -> V_336 . V_239 < sizeof( * V_335 ) )
return - V_229 ;
return F_168 ( V_335 -> V_337 ,
& V_335 -> V_338 ,
V_335 -> V_339 . V_340 . V_341 ,
& V_335 -> V_339 . V_340 . V_342 ,
& V_335 -> V_339 . V_340 . V_343 ,
& V_335 -> V_339 . V_340 . V_344 ,
& V_335 -> V_339 . V_340 . V_345 ,
& V_335 -> V_339 . V_340 . V_346 ,
& V_335 -> V_339 . V_340 . V_347 ,
& V_335 -> V_339 . V_340 . V_348 ) ;
}
case V_349 :
V_303 = ( F_169 () - V_302 -> V_350 [ 0 ] ) ;
V_303 *= F_170 ( V_351 ) ;
return F_171 ( NULL , V_302 -> V_307 , V_302 -> V_352 ,
V_353 - V_303 ) ;
case V_354 :
V_3 = F_172 ( V_302 -> V_307 , & V_302 -> V_307 , & V_302 -> V_355 [ 1 ] ) ;
if ( V_3 < 0 && V_3 != - V_356 )
return V_3 ;
V_302 -> V_355 [ 0 ] = V_3 ;
return 0 ;
case V_357 :
F_38 ( V_71 ) ;
V_6 . V_358 = V_302 -> V_352 ;
F_40 ( V_71 ) ;
return 0 ;
case V_359 :
return F_173 ( V_302 -> V_352 , V_302 ) ;
case V_360 :
V_175 . V_139 = V_302 -> V_307 ;
V_175 . V_361 = V_302 -> V_355 [ 0 ] ;
V_3 = F_174 ( V_175 , V_302 -> V_355 [ 1 ] ,
V_302 -> V_362 ,
V_302 -> V_363 / sizeof( struct V_174 ) ) ;
if ( V_3 < 0 )
return V_3 ;
V_302 -> V_306 = V_3 ;
return 0 ;
default:
V_136 = F_72 ( V_302 -> V_364 ) ;
if ( ! V_136 )
return - V_229 ;
if ( ! V_136 -> V_147 -> V_365 )
V_3 = - V_229 ;
else
V_3 = V_136 -> V_147 -> V_365 ( V_136 , V_299 , V_300 ) ;
F_175 ( V_136 ) ;
return V_3 ;
}
}
void F_176 ( struct V_174 V_175 )
{
F_177 ( V_175 . V_139 ) ;
}
int
F_160 ( unsigned int V_366 , struct V_174 * V_175 )
{
struct V_134 * V_136 ;
struct V_13 * V_62 ;
int V_99 ;
int V_3 = - V_293 ;
F_10 ( V_6 . V_117 > 0 ) ;
V_99 = F_77 () ;
F_26 (tmp, &the_lnet.ln_nis) {
if ( V_366 -- )
continue;
V_136 = F_27 ( V_62 , struct V_134 , V_137 ) ;
V_175 -> V_139 = V_136 -> V_138 ;
V_175 -> V_361 = V_6 . V_120 ;
V_3 = 0 ;
break;
}
F_40 ( V_99 ) ;
return V_3 ;
}
static int F_174 ( struct V_174 V_175 , int V_367 ,
struct V_174 T_7 * V_368 , int V_369 )
{
struct V_370 V_371 ;
struct V_170 V_372 ;
struct V_163 V_164 ;
struct V_178 V_165 = { NULL } ;
int V_373 ;
int V_167 = 0 ;
int V_374 = 0 ;
const int V_375 = 60000 ;
int V_152 ;
struct V_149 * V_376 ;
struct V_174 V_377 ;
int V_12 ;
int V_378 ;
int V_3 ;
int V_179 ;
T_5 V_199 ;
V_152 = F_24 ( struct V_149 , V_153 [ V_369 ] ) ;
if ( V_369 <= 0 ||
V_175 . V_139 == V_133 ||
V_367 > 500000 ||
V_369 > 20 )
return - V_229 ;
if ( V_175 . V_361 == V_115 )
V_175 . V_361 = V_379 ;
F_11 ( V_376 , V_152 ) ;
if ( ! V_376 )
return - V_18 ;
V_3 = F_91 ( 2 , V_380 , & V_371 ) ;
if ( V_3 ) {
F_12 ( L_36 , V_3 ) ;
goto V_381;
}
V_165 . V_187 = V_376 ;
V_165 . V_188 = V_152 ;
V_165 . V_189 = 2 ;
V_165 . V_191 = 0 ;
V_165 . V_192 = V_194 ;
V_165 . V_166 = NULL ;
V_165 . V_196 = V_371 ;
V_3 = F_178 ( V_165 , V_184 , & V_372 ) ;
if ( V_3 ) {
F_12 ( L_37 , V_3 ) ;
goto V_382;
}
V_3 = F_179 ( V_133 , V_372 , V_175 ,
V_182 ,
V_183 , 0 ) ;
if ( V_3 ) {
V_179 = F_98 ( V_372 ) ;
F_10 ( ! V_179 ) ;
V_167 = 1 ;
V_367 = V_375 ;
}
do {
if ( V_167 )
V_199 = F_97 () ;
V_179 = F_180 ( & V_371 , 1 , V_367 , & V_164 , & V_373 ) ;
if ( V_167 )
F_103 ( V_199 ) ;
F_32 ( V_67 , L_38 , V_179 ,
( V_179 <= 0 ) ? - 1 : V_164 . type ,
( V_179 <= 0 ) ? - 1 : V_164 . V_383 ,
( V_179 > 0 && V_164 . V_167 ) ? L_39 : L_28 ) ;
F_10 ( V_179 != - V_384 ) ;
if ( V_179 <= 0 || V_164 . V_383 ) {
if ( ! V_374 && ! V_3 )
V_3 = ( V_179 < 0 ) ? V_179 :
! V_179 ? - V_385 :
V_164 . V_383 ;
if ( ! V_167 ) {
F_98 ( V_372 ) ;
V_167 = 1 ;
V_367 = V_375 ;
} else if ( ! V_179 ) {
F_181 ( L_40 ,
F_182 ( V_175 ) ) ;
}
} else if ( V_164 . type == V_386 ) {
V_374 = 1 ;
V_3 = V_164 . V_47 ;
}
} while ( V_179 <= 0 || ! V_164 . V_167 );
if ( ! V_374 ) {
if ( V_3 >= 0 )
F_181 ( L_41 ,
F_182 ( V_175 ) ) ;
V_3 = - V_387 ;
goto V_382;
}
V_378 = V_3 ;
F_10 ( V_378 >= 0 && V_378 <= V_152 ) ;
V_3 = - V_388 ;
if ( V_378 < 8 ) {
F_12 ( L_42 ,
F_182 ( V_175 ) , V_378 ) ;
goto V_382;
}
if ( V_376 -> V_156 == F_183 ( V_157 ) ) {
F_184 ( V_376 ) ;
} else if ( V_376 -> V_156 != V_157 ) {
F_12 ( L_43 ,
F_182 ( V_175 ) , V_376 -> V_156 ) ;
goto V_382;
}
if ( ! ( V_376 -> V_158 & V_159 ) ) {
F_12 ( L_44 ,
F_182 ( V_175 ) , V_376 -> V_158 ) ;
goto V_382;
}
if ( V_378 < F_24 ( struct V_149 , V_153 [ 0 ] ) ) {
F_12 ( L_45 , F_182 ( V_175 ) ,
V_378 , ( int ) F_24 ( struct V_149 , V_153 [ 0 ] ) ) ;
goto V_382;
}
if ( V_376 -> V_154 < V_369 )
V_369 = V_376 -> V_154 ;
if ( V_378 < F_24 ( struct V_149 , V_153 [ V_369 ] ) ) {
F_12 ( L_46 , F_182 ( V_175 ) ,
V_378 , ( int ) F_24 ( struct V_149 , V_153 [ V_369 ] ) ) ;
goto V_382;
}
V_3 = - V_389 ;
memset ( & V_377 , 0 , sizeof( V_377 ) ) ;
for ( V_12 = 0 ; V_12 < V_369 ; V_12 ++ ) {
V_377 . V_361 = V_376 -> V_155 ;
V_377 . V_139 = V_376 -> V_153 [ V_12 ] . V_203 ;
if ( F_185 ( & V_368 [ V_12 ] , & V_377 , sizeof( V_377 ) ) )
goto V_382;
}
V_3 = V_376 -> V_154 ;
V_382:
V_179 = F_95 ( V_371 ) ;
if ( V_179 )
F_12 ( L_47 , V_179 ) ;
F_10 ( ! V_179 ) ;
V_381:
F_16 ( V_376 , V_152 ) ;
return V_3 ;
}
