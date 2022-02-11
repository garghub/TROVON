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
static T_1 *
F_25 ( T_2 type )
{
T_1 * V_60 ;
struct V_13 * V_61 ;
F_26 (tmp, &the_lnet.ln_lnds) {
V_60 = F_27 ( V_61 , T_1 , V_62 ) ;
if ( V_60 -> V_63 == type )
return V_60 ;
}
return NULL ;
}
void
F_28 ( T_1 * V_60 )
{
F_29 ( & V_6 . V_10 ) ;
F_10 ( F_30 ( V_60 -> V_63 ) ) ;
F_10 ( ! F_25 ( V_60 -> V_63 ) ) ;
F_31 ( & V_60 -> V_62 , & V_6 . V_64 ) ;
V_60 -> V_65 = 0 ;
F_32 ( V_66 , L_4 , F_33 ( V_60 -> V_63 ) ) ;
F_34 ( & V_6 . V_10 ) ;
}
void
F_35 ( T_1 * V_60 )
{
F_29 ( & V_6 . V_10 ) ;
F_10 ( F_25 ( V_60 -> V_63 ) == V_60 ) ;
F_10 ( ! V_60 -> V_65 ) ;
F_36 ( & V_60 -> V_62 ) ;
F_32 ( V_66 , L_5 , F_33 ( V_60 -> V_63 ) ) ;
F_34 ( & V_6 . V_10 ) ;
}
void
F_37 ( T_3 * V_67 )
{
T_3 * V_68 ;
int V_12 ;
memset ( V_67 , 0 , sizeof( * V_67 ) ) ;
F_38 ( V_69 ) ;
F_39 (ctr, i, the_lnet.ln_counters) {
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
V_67 -> V_80 += V_68 -> V_80 ;
}
F_40 ( V_69 ) ;
}
void
F_41 ( void )
{
T_3 * V_67 ;
int V_12 ;
F_38 ( V_69 ) ;
F_39 (counters, i, the_lnet.ln_counters)
memset ( V_67 , 0 , sizeof( T_3 ) ) ;
F_40 ( V_69 ) ;
}
static char *
F_42 ( int type )
{
switch ( type ) {
default:
F_43 () ;
case V_81 :
return L_6 ;
case V_82 :
return L_7 ;
case V_83 :
return L_8 ;
}
}
static void
F_44 ( struct V_84 * V_85 )
{
int V_86 = 0 ;
if ( ! V_85 -> V_87 )
return;
while ( ! F_15 ( & V_85 -> V_88 ) ) {
struct V_13 * V_89 = V_85 -> V_88 . V_90 ;
F_45 ( V_89 ) ;
if ( V_85 -> V_87 == V_83 ) {
F_46 ( F_27 ( V_89 , V_91 , V_92 ) ) ;
} else if ( V_85 -> V_87 == V_81 ) {
F_47 ( F_27 ( V_89 , V_93 , V_94 ) ) ;
} else {
F_43 () ;
}
V_86 ++ ;
}
if ( V_86 > 0 ) {
F_12 ( L_9 ,
V_86 , F_42 ( V_85 -> V_87 ) ) ;
}
if ( V_85 -> V_95 ) {
F_16 ( V_85 -> V_95 ,
V_96 * sizeof( V_85 -> V_95 [ 0 ] ) ) ;
V_85 -> V_95 = NULL ;
}
V_85 -> V_87 = 0 ;
}
static int
F_48 ( struct V_84 * V_85 , int V_97 , int type )
{
int V_3 = 0 ;
int V_12 ;
F_10 ( ! V_85 -> V_87 ) ;
V_85 -> V_87 = type ;
F_13 ( & V_85 -> V_88 ) ;
V_85 -> V_98 = ( V_97 << V_99 ) | type ;
F_49 ( V_85 -> V_95 , F_21 () , V_97 ,
V_96 * sizeof( V_85 -> V_95 [ 0 ] ) ) ;
if ( ! V_85 -> V_95 ) {
V_3 = - V_18 ;
goto V_100;
}
for ( V_12 = 0 ; V_12 < V_96 ; V_12 ++ )
F_13 ( & V_85 -> V_95 [ V_12 ] ) ;
return 0 ;
V_100:
F_12 ( L_10 ,
F_42 ( type ) ) ;
F_44 ( V_85 ) ;
return V_3 ;
}
static void
F_50 ( struct V_84 * * V_101 )
{
struct V_84 * V_85 ;
int V_12 ;
F_39 (rec, i, recs)
F_44 ( V_85 ) ;
F_51 ( V_101 ) ;
}
static struct V_84 * *
F_52 ( int type )
{
struct V_84 * * V_101 ;
struct V_84 * V_85 ;
int V_3 ;
int V_12 ;
V_101 = F_53 ( F_21 () , sizeof( * V_85 ) ) ;
if ( ! V_101 ) {
F_12 ( L_11 ,
F_42 ( type ) ) ;
return NULL ;
}
F_39 (rec, i, recs) {
V_3 = F_48 ( V_85 , V_12 , type ) ;
if ( V_3 ) {
F_50 ( V_101 ) ;
return NULL ;
}
}
return V_101 ;
}
T_4 *
F_54 ( struct V_84 * V_85 , T_5 V_102 )
{
struct V_13 * V_103 ;
T_4 * V_104 ;
unsigned int V_14 ;
if ( ( V_102 & V_105 ) != V_85 -> V_87 )
return NULL ;
V_14 = V_102 >> ( V_99 + V_106 ) ;
V_103 = & V_85 -> V_95 [ V_14 & V_107 ] ;
F_55 (lh, head, lh_hash_chain) {
if ( V_104 -> V_108 == V_102 )
return V_104 ;
}
return NULL ;
}
void
F_56 ( struct V_84 * V_85 , T_4 * V_104 )
{
unsigned int V_109 = V_99 + V_106 ;
unsigned int V_14 ;
V_104 -> V_108 = V_85 -> V_98 ;
V_85 -> V_98 += 1 << V_109 ;
V_14 = ( V_104 -> V_108 >> V_109 ) & V_107 ;
F_57 ( & V_104 -> V_110 , & V_85 -> V_95 [ V_14 ] ) ;
}
static int
F_58 ( T_6 V_111 )
{
struct V_84 * * V_101 ;
int V_3 = 0 ;
if ( V_111 == V_112 ) {
return - V_113 ;
}
F_10 ( ! V_6 . V_114 ) ;
V_6 . V_115 = 0 ;
F_10 ( ! ( V_111 & V_116 ) ) ;
V_6 . V_117 = V_111 ;
F_13 ( & V_6 . V_118 ) ;
F_13 ( & V_6 . V_119 ) ;
F_13 ( & V_6 . V_120 ) ;
F_13 ( & V_6 . V_121 ) ;
F_13 ( & V_6 . V_122 ) ;
F_13 ( & V_6 . V_123 ) ;
F_13 ( & V_6 . V_124 ) ;
V_3 = F_9 () ;
if ( V_3 )
goto V_21;
V_6 . V_125 = F_59 () ;
V_6 . V_126 = F_53 ( F_21 () ,
sizeof( T_3 ) ) ;
if ( ! V_6 . V_126 ) {
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
V_3 = F_48 ( & V_6 . V_127 , 0 ,
V_83 ) ;
if ( V_3 )
goto V_21;
V_101 = F_52 ( V_82 ) ;
if ( ! V_101 ) {
V_3 = - V_18 ;
goto V_21;
}
V_6 . V_128 = V_101 ;
V_101 = F_52 ( V_81 ) ;
if ( ! V_101 ) {
V_3 = - V_18 ;
goto V_21;
}
V_6 . V_129 = V_101 ;
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
F_64 ( V_130 , 0 ) ;
F_10 ( ! V_6 . V_114 ) ;
F_10 ( F_15 ( & V_6 . V_118 ) ) ;
F_10 ( F_15 ( & V_6 . V_119 ) ) ;
F_10 ( F_15 ( & V_6 . V_120 ) ) ;
F_10 ( F_15 ( & V_6 . V_121 ) ) ;
F_65 () ;
if ( V_6 . V_129 ) {
F_50 ( V_6 . V_129 ) ;
V_6 . V_129 = NULL ;
}
if ( V_6 . V_128 ) {
F_50 ( V_6 . V_128 ) ;
V_6 . V_128 = NULL ;
}
F_44 ( & V_6 . V_127 ) ;
F_66 () ;
F_67 () ;
F_68 ( 0 ) ;
if ( V_6 . V_126 ) {
F_51 ( V_6 . V_126 ) ;
V_6 . V_126 = NULL ;
}
F_14 () ;
return 0 ;
}
T_7 *
F_69 ( T_2 V_131 , int V_97 )
{
struct V_13 * V_61 ;
T_7 * V_132 ;
F_10 ( V_97 != V_69 ) ;
F_26 (tmp, &the_lnet.ln_nis) {
V_132 = F_27 ( V_61 , T_7 , V_133 ) ;
if ( F_70 ( V_132 -> V_134 ) == V_131 ) {
F_71 ( V_132 , V_97 ) ;
return V_132 ;
}
}
return NULL ;
}
T_7 *
F_72 ( T_2 V_131 )
{
T_7 * V_132 ;
F_38 ( 0 ) ;
V_132 = F_69 ( V_131 , 0 ) ;
F_40 ( 0 ) ;
return V_132 ;
}
static unsigned int
F_73 ( T_8 V_135 , unsigned int V_136 )
{
T_5 V_137 = V_135 ;
unsigned int V_138 ;
F_10 ( V_136 >= 1 && V_136 <= V_139 ) ;
if ( V_136 == 1 )
return 0 ;
V_138 = F_74 ( V_137 , V_106 ) ;
if ( V_138 < V_136 )
return V_138 ;
return ( unsigned int ) ( V_137 + V_138 + ( V_138 >> 1 ) ) % V_136 ;
}
int
F_75 ( T_8 V_135 )
{
struct V_140 * V_132 ;
if ( V_139 == 1 )
return 0 ;
if ( ! F_15 ( & V_6 . V_120 ) ) {
F_55 (ni, &the_lnet.ln_nis_cpt, ni_cptlist) {
if ( F_70 ( V_132 -> V_134 ) != F_70 ( V_135 ) )
continue;
F_10 ( V_132 -> V_141 ) ;
return V_132 -> V_141 [ F_73
( V_135 , V_132 -> V_142 ) ] ;
}
}
return F_73 ( V_135 , V_139 ) ;
}
int
F_76 ( T_8 V_135 )
{
int V_97 ;
int V_143 ;
if ( V_139 == 1 )
return 0 ;
if ( F_15 ( & V_6 . V_120 ) )
return F_73 ( V_135 , V_139 ) ;
V_97 = F_77 () ;
V_143 = F_75 ( V_135 ) ;
F_40 ( V_97 ) ;
return V_143 ;
}
int
F_78 ( T_2 V_131 )
{
struct V_140 * V_132 ;
int V_97 ;
V_97 = F_77 () ;
V_132 = F_69 ( V_131 , V_97 ) ;
if ( V_132 )
F_79 ( V_132 , V_97 ) ;
F_40 ( V_97 ) ;
return ! ! V_132 ;
}
T_7 *
F_80 ( T_8 V_135 , int V_97 )
{
struct V_140 * V_132 ;
struct V_13 * V_61 ;
F_10 ( V_97 != V_69 ) ;
F_26 (tmp, &the_lnet.ln_nis) {
V_132 = F_27 ( V_61 , T_7 , V_133 ) ;
if ( V_132 -> V_134 == V_135 ) {
F_71 ( V_132 , V_97 ) ;
return V_132 ;
}
}
return NULL ;
}
int
F_81 ( T_8 V_135 )
{
struct V_140 * V_132 ;
int V_97 ;
V_97 = F_77 () ;
V_132 = F_80 ( V_135 , V_97 ) ;
if ( V_132 )
F_79 ( V_132 , V_97 ) ;
F_40 ( V_97 ) ;
return ! ! V_132 ;
}
int
F_82 ( void )
{
int V_86 = 0 ;
struct V_13 * V_61 ;
struct V_140 * V_132 ;
int V_97 ;
V_97 = F_77 () ;
F_26 (tmp, &the_lnet.ln_nis) {
V_132 = F_27 ( V_61 , T_7 , V_133 ) ;
if ( V_132 -> V_144 -> V_145 )
V_86 ++ ;
}
F_40 ( V_97 ) ;
return V_86 ;
}
static struct V_146 *
F_83 ( int V_147 )
{
struct V_146 * V_148 ;
unsigned int V_149 ;
V_149 = F_24 ( struct V_146 , V_150 [ V_147 ] ) ;
F_11 ( V_148 , V_149 ) ;
if ( ! V_148 ) {
F_12 ( L_14 , V_147 ) ;
return NULL ;
}
V_148 -> V_151 = V_147 ;
V_148 -> V_152 = V_6 . V_117 ;
V_148 -> V_153 = V_154 ;
V_148 -> V_155 = V_156 ;
return V_148 ;
}
static inline int
F_84 ( void )
{
struct V_140 * V_132 ;
int V_86 = 0 ;
F_38 ( 0 ) ;
F_55 (ni, &the_lnet.ln_nis, ni_list)
V_86 ++ ;
F_40 ( 0 ) ;
return V_86 ;
}
static inline void
F_85 ( struct V_146 * V_157 )
{
F_16 ( V_157 ,
F_24 ( struct V_146 ,
V_150 [ V_157 -> V_151 ] ) ) ;
}
static void
F_86 ( void )
{
struct V_140 * V_132 ;
F_38 ( V_69 ) ;
F_55 (ni, &the_lnet.ln_nis, ni_list) {
F_87 ( V_132 ) ;
V_132 -> V_158 = NULL ;
F_88 ( V_132 ) ;
}
F_85 ( V_6 . V_159 ) ;
V_6 . V_159 = NULL ;
F_40 ( V_69 ) ;
}
static void
F_89 ( T_9 * V_160 )
{
struct V_146 * V_157 = V_160 -> V_161 . V_162 ;
if ( V_160 -> V_163 )
V_157 -> V_155 = V_164 ;
}
static int
F_90 ( struct V_146 * * V_165 , T_10 * V_166 ,
int V_167 , bool V_168 )
{
T_11 V_169 = { V_130 , V_112 } ;
T_12 V_170 ;
T_13 V_161 = { NULL } ;
int V_3 , V_171 ;
if ( V_168 ) {
V_3 = F_91 ( 0 , F_89 ,
& V_6 . V_172 ) ;
if ( V_3 ) {
F_12 ( L_15 , V_3 ) ;
return V_3 ;
}
}
* V_165 = F_83 ( V_167 ) ;
if ( ! * V_165 ) {
V_3 = - V_18 ;
goto V_173;
}
V_3 = F_92 ( V_174 , V_169 ,
V_175 , 0 ,
V_176 , V_177 ,
& V_170 ) ;
if ( V_3 ) {
F_12 ( L_16 , V_3 ) ;
goto V_178;
}
V_161 . V_179 = * V_165 ;
V_161 . V_180 = F_24 ( struct V_146 ,
V_150 [ ( * V_165 ) -> V_151 ] ) ;
V_161 . V_181 = V_182 ;
V_161 . V_183 = 0 ;
V_161 . V_184 = V_185 | V_186 |
V_187 ;
V_161 . V_162 = NULL ;
V_161 . V_188 = V_6 . V_172 ;
V_161 . V_162 = * V_165 ;
V_3 = F_93 ( V_170 , V_161 , V_189 , V_166 ) ;
if ( V_3 ) {
F_12 ( L_17 , V_3 ) ;
goto V_190;
}
return 0 ;
V_190:
V_171 = F_94 ( V_170 ) ;
F_10 ( ! V_171 ) ;
V_178:
F_85 ( * V_165 ) ;
* V_165 = NULL ;
V_173:
if ( V_168 )
F_95 ( V_6 . V_172 ) ;
return V_3 ;
}
static void
F_96 ( struct V_146 * V_157 , T_10 * V_166 )
{
T_14 V_191 = F_97 () ;
F_98 ( * V_166 ) ;
F_99 ( V_166 ) ;
while ( V_157 -> V_155 != V_164 ) {
F_32 ( V_66 , L_18 ) ;
F_100 ( V_192 ) ;
F_101 ( F_102 ( 1 ) ) ;
}
F_103 ( V_191 ) ;
}
static void
F_104 ( struct V_146 * V_148 )
{
struct V_193 * V_194 ;
T_7 * V_132 ;
int V_12 = 0 ;
F_55 (ni, &the_lnet.ln_nis, ni_list) {
F_10 ( V_12 < V_148 -> V_151 ) ;
V_194 = & V_148 -> V_150 [ V_12 ] ;
V_194 -> V_195 = V_132 -> V_134 ;
F_87 ( V_132 ) ;
V_194 -> V_196 = ( V_132 -> V_158 ) ?
V_132 -> V_158 -> V_196 : V_197 ;
V_132 -> V_158 = V_194 ;
F_88 ( V_132 ) ;
V_12 ++ ;
}
}
static void
F_105 ( struct V_146 * V_157 , T_10 V_166 )
{
struct V_146 * V_198 = NULL ;
T_10 V_199 ;
F_38 ( V_69 ) ;
if ( ! V_6 . V_115 )
V_157 -> V_155 |= V_200 ;
F_104 ( V_157 ) ;
if ( V_6 . V_159 ) {
V_198 = V_6 . V_159 ;
V_199 = V_6 . V_201 ;
}
V_6 . V_201 = V_166 ;
V_6 . V_159 = V_157 ;
F_40 ( V_69 ) ;
if ( V_198 ) {
F_96 ( V_198 , & V_199 ) ;
F_85 ( V_198 ) ;
}
}
static void
F_106 ( void )
{
int V_3 ;
F_96 ( V_6 . V_159 ,
& V_6 . V_201 ) ;
V_3 = F_95 ( V_6 . V_172 ) ;
F_10 ( ! V_3 ) ;
F_86 () ;
}
static int
F_107 ( T_7 * V_132 )
{
int V_202 ;
F_10 ( V_132 -> V_142 >= 1 ) ;
if ( V_132 -> V_142 == 1 )
return V_132 -> V_203 ;
V_202 = V_132 -> V_203 / V_132 -> V_142 ;
V_202 = F_108 ( V_202 , 8 * V_132 -> V_204 ) ;
V_202 = F_109 ( V_202 , V_132 -> V_203 ) ;
return V_202 ;
}
static void
F_110 ( T_7 * V_132 )
{
if ( ! F_15 ( & V_132 -> V_205 ) ) {
F_45 ( & V_132 -> V_205 ) ;
F_79 ( V_132 , 0 ) ;
}
F_10 ( ! F_15 ( & V_132 -> V_133 ) ) ;
F_111 ( & V_132 -> V_133 , & V_6 . V_121 ) ;
F_79 ( V_132 , 0 ) ;
}
static void
F_112 ( void )
{
int V_12 ;
int V_206 ;
T_7 * V_132 ;
T_7 * V_207 ;
V_12 = 2 ;
F_113 (ni, temp, &the_lnet.ln_nis_zombie, ni_list) {
int * V_208 ;
int V_209 ;
F_45 ( & V_132 -> V_133 ) ;
F_39 (ref, j, ni->ni_refs) {
if ( ! * V_208 )
continue;
F_57 ( & V_132 -> V_133 , & V_6 . V_121 ) ;
break;
}
if ( ! F_15 ( & V_132 -> V_133 ) ) {
F_40 ( V_69 ) ;
++ V_12 ;
if ( ( V_12 & ( - V_12 ) ) == V_12 ) {
F_32 ( V_210 , L_19 ,
F_114 ( V_132 -> V_134 ) ) ;
}
F_100 ( V_192 ) ;
F_101 ( F_102 ( 1 ) ) ;
F_38 ( V_69 ) ;
continue;
}
V_132 -> V_144 -> V_65 -- ;
F_40 ( V_69 ) ;
V_206 = V_132 -> V_144 -> V_63 == V_211 ;
F_10 ( ! F_115 () ) ;
V_132 -> V_144 -> V_212 ( V_132 ) ;
if ( ! V_206 )
F_32 ( V_213 , L_20 ,
F_114 ( V_132 -> V_134 ) ) ;
F_116 ( V_132 ) ;
V_12 = 2 ;
F_38 ( V_69 ) ;
}
}
static void
F_117 ( void )
{
T_7 * V_132 ;
T_7 * V_207 ;
int V_12 ;
F_10 ( ! V_6 . V_214 ) ;
F_10 ( ! V_6 . V_114 ) ;
F_10 ( F_15 ( & V_6 . V_121 ) ) ;
F_38 ( V_69 ) ;
V_6 . V_214 = 1 ;
F_113 (ni, temp, &the_lnet.ln_nis, ni_list) {
F_110 ( V_132 ) ;
}
if ( V_6 . V_215 ) {
F_79 ( V_6 . V_215 , 0 ) ;
V_6 . V_215 = NULL ;
}
F_40 ( V_69 ) ;
for ( V_12 = 0 ; V_12 < V_6 . V_216 ; V_12 ++ )
F_118 ( V_12 ) ;
F_119 ( NULL ) ;
F_38 ( V_69 ) ;
F_112 () ;
V_6 . V_214 = 0 ;
F_40 ( V_69 ) ;
}
static void
F_120 ( struct V_140 * V_132 )
{
int V_12 ;
F_38 ( V_69 ) ;
F_110 ( V_132 ) ;
F_40 ( V_69 ) ;
for ( V_12 = 0 ; V_12 < V_6 . V_216 ; V_12 ++ )
F_121 ( V_132 , V_12 , L_21 ) ;
F_119 ( V_132 ) ;
F_38 ( V_69 ) ;
F_112 () ;
F_40 ( V_69 ) ;
}
static int
F_122 ( struct V_140 * V_132 , struct V_217 * V_218 )
{
struct V_219 * V_220 = NULL ;
int V_3 = - V_221 ;
int V_63 ;
T_1 * V_60 ;
struct V_222 * V_223 ;
int V_12 ;
V_63 = F_123 ( F_70 ( V_132 -> V_134 ) ) ;
F_10 ( F_30 ( V_63 ) ) ;
if ( V_63 == V_224 || V_63 == V_225 ||
V_63 == V_226 || V_63 == V_227 ) {
F_12 ( L_22 , F_33 ( V_63 ) ) ;
goto V_228;
}
F_38 ( V_69 ) ;
V_3 = F_124 ( F_70 ( V_132 -> V_134 ) , & V_6 . V_119 ) ;
F_40 ( V_69 ) ;
if ( ! V_3 ) {
if ( V_63 == V_211 ) {
F_116 ( V_132 ) ;
return 0 ;
}
F_12 ( L_23 ,
F_125 ( F_70 ( V_132 -> V_134 ) ) ) ;
V_3 = - V_229 ;
goto V_228;
}
F_29 ( & V_6 . V_10 ) ;
V_60 = F_25 ( V_63 ) ;
if ( ! V_60 ) {
F_34 ( & V_6 . V_10 ) ;
V_3 = F_126 ( L_24 , F_127 ( V_63 ) ) ;
F_29 ( & V_6 . V_10 ) ;
V_60 = F_25 ( V_63 ) ;
if ( ! V_60 ) {
F_34 ( & V_6 . V_10 ) ;
F_12 ( L_25 ,
F_33 ( V_63 ) ,
F_127 ( V_63 ) , V_3 ) ;
V_3 = - V_221 ;
goto V_228;
}
}
F_38 ( V_69 ) ;
V_60 -> V_65 ++ ;
F_40 ( V_69 ) ;
V_132 -> V_144 = V_60 ;
if ( V_218 && V_218 -> V_230 . V_231 > sizeof( * V_218 ) )
V_220 = (struct V_219 * ) V_218 -> V_232 ;
if ( V_220 ) {
F_11 ( V_132 -> V_233 ,
sizeof( * V_132 -> V_233 ) ) ;
if ( ! V_132 -> V_233 ) {
F_34 ( & V_6 . V_10 ) ;
V_3 = - V_18 ;
goto V_228;
}
memcpy ( V_132 -> V_233 , V_220 ,
sizeof( * V_132 -> V_233 ) ) ;
}
if ( V_218 ) {
if ( V_218 -> V_234 . V_235 . V_236 >= 0 )
V_132 -> V_237 =
V_218 -> V_234 . V_235 . V_236 ;
if ( V_218 -> V_234 . V_235 . V_238 >= 0 )
V_132 -> V_239 =
V_218 -> V_234 . V_235 . V_238 ;
if ( V_218 -> V_234 . V_235 . V_240 != - 1 )
V_132 -> V_204 =
V_218 -> V_234 . V_235 . V_240 ;
if ( V_218 -> V_234 . V_235 . V_241 >= 0 )
V_132 -> V_203 =
V_218 -> V_234 . V_235 . V_241 ;
}
V_3 = V_60 -> V_242 ( V_132 ) ;
F_34 ( & V_6 . V_10 ) ;
if ( V_3 ) {
F_3 ( 0x105 , L_26 ,
V_3 , F_33 ( V_60 -> V_63 ) ) ;
F_38 ( V_69 ) ;
V_60 -> V_65 -- ;
F_40 ( V_69 ) ;
goto V_228;
}
F_10 ( V_132 -> V_239 <= 0 || V_60 -> V_243 ) ;
F_38 ( V_69 ) ;
F_71 ( V_132 , 0 ) ;
F_31 ( & V_132 -> V_133 , & V_6 . V_119 ) ;
if ( V_132 -> V_141 ) {
F_71 ( V_132 , 0 ) ;
F_31 ( & V_132 -> V_205 , & V_6 . V_120 ) ;
}
F_40 ( V_69 ) ;
if ( V_60 -> V_63 == V_211 ) {
F_128 ( V_132 ) ;
F_10 ( ! V_6 . V_215 ) ;
V_6 . V_215 = V_132 ;
return 0 ;
}
if ( ! V_132 -> V_204 || ! V_132 -> V_203 ) {
F_3 ( 0x107 , L_27 ,
F_33 ( V_60 -> V_63 ) ,
! V_132 -> V_204 ?
L_28 : L_29 ) ;
F_120 ( V_132 ) ;
return - V_221 ;
}
F_39 (tq, i, ni->ni_tx_queues) {
V_223 -> V_244 =
V_223 -> V_245 =
V_223 -> V_246 = F_107 ( V_132 ) ;
}
F_32 ( V_213 , L_30 ,
F_114 ( V_132 -> V_134 ) , V_132 -> V_204 ,
F_107 ( V_132 ) * V_139 ,
V_132 -> V_237 , V_132 -> V_239 ) ;
return 0 ;
V_228:
F_116 ( V_132 ) ;
return V_3 ;
}
static int
F_129 ( struct V_13 * V_247 )
{
struct V_140 * V_132 ;
int V_3 ;
int V_167 = 0 ;
while ( ! F_15 ( V_247 ) ) {
V_132 = F_27 ( V_247 -> V_90 , T_7 , V_133 ) ;
F_36 ( & V_132 -> V_133 ) ;
V_3 = F_122 ( V_132 , NULL ) ;
if ( V_3 < 0 )
goto V_21;
V_167 ++ ;
}
return V_167 ;
V_21:
F_117 () ;
return V_3 ;
}
int F_130 ( void )
{
int V_3 ;
F_22 () ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_248 = V_249 ;
V_6 . V_250 = F_131 ( V_249 ) ;
F_10 ( V_6 . V_250 > 0 ) ;
if ( V_6 . V_250 > V_251 ) {
F_12 ( L_31 ,
V_6 . V_250 , V_251 ) ;
return - V_252 ;
}
while ( ( 1 << V_6 . V_253 ) < V_6 . V_250 )
V_6 . V_253 ++ ;
V_3 = F_19 () ;
if ( V_3 ) {
F_12 ( L_32 , V_3 ) ;
return V_3 ;
}
V_6 . V_114 = 0 ;
F_99 ( & V_6 . V_254 ) ;
F_13 ( & V_6 . V_64 ) ;
F_13 ( & V_6 . V_255 ) ;
F_13 ( & V_6 . V_256 ) ;
if ( V_257 <= 0 )
V_257 = V_258 ;
else if ( V_257 > V_259 )
V_257 = V_259 ;
V_6 . V_16 = F_132 ( int , 1 ,
F_133 ( V_257 ) - 1 ) ;
F_28 ( & V_260 ) ;
return 0 ;
}
void F_134 ( void )
{
F_10 ( ! V_6 . V_114 ) ;
while ( ! F_15 ( & V_6 . V_64 ) )
F_35 ( F_27 ( V_6 . V_64 . V_90 ,
T_1 , V_62 ) ) ;
F_17 () ;
}
int
F_135 ( T_6 V_111 )
{
int V_261 = 0 ;
int V_3 ;
int V_167 ;
struct V_146 * V_157 ;
T_10 V_166 ;
struct V_13 V_262 ;
F_13 ( & V_262 ) ;
F_29 ( & V_6 . V_11 ) ;
F_32 ( V_263 , L_33 , V_6 . V_114 ) ;
if ( V_6 . V_114 > 0 ) {
V_3 = V_6 . V_114 ++ ;
F_34 ( & V_6 . V_11 ) ;
return V_3 ;
}
V_3 = F_58 ( V_111 ) ;
if ( V_3 ) {
F_34 ( & V_6 . V_11 ) ;
return V_3 ;
}
if ( ! F_136 ( F_137 ( V_211 , 0 ) , NULL , & V_262 ) ) {
V_3 = - V_18 ;
goto V_264;
}
if ( ! V_6 . V_265 ) {
V_3 = F_138 ( & V_262 , F_2 () ) ;
if ( V_3 < 0 )
goto V_264;
}
V_167 = F_129 ( & V_262 ) ;
if ( V_167 < 0 ) {
V_3 = V_167 ;
goto V_264;
}
if ( ! V_6 . V_265 ) {
V_3 = F_139 ( F_1 () , & V_261 ) ;
if ( V_3 )
goto V_266;
V_3 = F_140 () ;
if ( V_3 )
goto V_267;
V_3 = F_141 ( V_261 ) ;
if ( V_3 )
goto V_267;
}
V_3 = F_142 () ;
if ( V_3 )
goto V_267;
V_6 . V_114 = 1 ;
V_3 = F_90 ( & V_157 , & V_166 , V_167 , true ) ;
if ( V_3 )
goto V_268;
F_105 ( V_157 , V_166 ) ;
V_3 = F_143 () ;
if ( V_3 )
goto V_269;
F_144 () ;
F_145 () ;
F_34 ( & V_6 . V_11 ) ;
return 0 ;
V_269:
F_106 () ;
V_268:
V_6 . V_114 = 0 ;
F_146 () ;
V_267:
if ( ! V_6 . V_265 )
F_147 () ;
V_266:
F_117 () ;
V_264:
F_63 () ;
F_10 ( V_3 < 0 ) ;
F_34 ( & V_6 . V_11 ) ;
while ( ! F_15 ( & V_262 ) ) {
struct V_140 * V_132 ;
V_132 = F_27 ( V_262 . V_90 , struct V_140 , V_133 ) ;
F_45 ( & V_132 -> V_133 ) ;
F_116 ( V_132 ) ;
}
return V_3 ;
}
int
F_148 ( void )
{
F_29 ( & V_6 . V_11 ) ;
F_10 ( V_6 . V_114 > 0 ) ;
if ( V_6 . V_114 != 1 ) {
V_6 . V_114 -- ;
} else {
F_10 ( ! V_6 . V_270 ) ;
F_149 () ;
F_150 () ;
F_151 () ;
F_106 () ;
V_6 . V_114 = 0 ;
F_146 () ;
F_147 () ;
F_117 () ;
F_63 () ;
}
F_34 ( & V_6 . V_11 ) ;
return 0 ;
}
static void
F_152 ( struct V_140 * V_132 , struct V_217 * V_271 )
{
struct V_219 * V_272 = NULL ;
struct V_273 * V_274 ;
T_15 V_275 , V_276 = 0 ;
int V_12 ;
if ( ! V_132 || ! V_271 )
return;
V_274 = (struct V_273 * ) V_271 -> V_232 ;
if ( ! V_274 )
return;
F_23 ( F_153 ( V_132 -> V_277 ) !=
F_153 ( V_274 -> V_277 ) ) ;
for ( V_12 = 0 ; V_12 < F_153 ( V_132 -> V_277 ) ; V_12 ++ ) {
if ( ! V_132 -> V_277 [ V_12 ] )
break;
strncpy ( V_274 -> V_277 [ V_12 ] ,
V_132 -> V_277 [ V_12 ] ,
sizeof( V_274 -> V_277 [ V_12 ] ) ) ;
}
V_271 -> V_278 = V_132 -> V_134 ;
V_271 -> V_234 . V_235 . V_238 = V_132 -> V_239 ;
V_271 -> V_234 . V_235 . V_241 = V_132 -> V_203 ;
V_271 -> V_234 . V_235 . V_240 = V_132 -> V_204 ;
V_271 -> V_234 . V_235 . V_236 = V_132 -> V_237 ;
V_274 -> V_158 = V_132 -> V_158 -> V_196 ;
if ( V_132 -> V_141 ) {
int V_279 = F_109 ( V_132 -> V_142 , V_280 ) ;
for ( V_12 = 0 ; V_12 < V_279 ; V_12 ++ )
V_274 -> V_141 [ V_12 ] = V_132 -> V_141 [ V_12 ] ;
V_271 -> V_281 = V_279 ;
}
V_275 = sizeof( * V_271 ) + sizeof( * V_274 ) ;
if ( V_271 -> V_230 . V_231 > V_275 )
V_276 = V_271 -> V_230 . V_231 - V_275 ;
V_275 = F_109 ( V_276 , sizeof( * V_132 -> V_233 ) ) ;
V_272 = (struct V_219 * ) V_274 -> V_232 ;
if ( V_132 -> V_233 && V_272 && V_275 ) {
memcpy ( V_272 , V_132 -> V_233 , V_275 ) ;
V_271 -> V_234 . V_235 . V_282 = 1 ;
if ( V_276 > sizeof( * V_132 -> V_233 ) ) {
V_275 = V_276 - sizeof( V_132 -> V_233 ) ;
V_271 -> V_230 . V_231 -= V_275 ;
}
}
}
static int
F_154 ( struct V_217 * V_271 )
{
struct V_140 * V_132 ;
struct V_13 * V_61 ;
int V_283 = V_271 -> V_284 ;
int V_97 , V_12 = 0 ;
int V_3 = - V_285 ;
V_97 = F_77 () ;
F_26 (tmp, &the_lnet.ln_nis) {
if ( V_12 ++ != V_283 )
continue;
V_132 = F_27 ( V_61 , T_7 , V_133 ) ;
F_87 ( V_132 ) ;
F_152 ( V_132 , V_271 ) ;
F_88 ( V_132 ) ;
V_3 = 0 ;
break;
}
F_40 ( V_97 ) ;
return V_3 ;
}
int
F_155 ( T_6 V_111 , struct V_217 * V_218 )
{
char * V_2 = V_218 -> V_234 . V_235 . V_286 ;
struct V_146 * V_157 ;
T_10 V_166 ;
struct V_140 * V_132 ;
struct V_13 V_262 ;
T_16 * V_287 ;
int V_3 ;
F_13 ( & V_262 ) ;
V_3 = F_138 ( & V_262 , V_2 ) ;
if ( V_3 <= 0 )
return ! V_3 ? - V_221 : V_3 ;
F_29 ( & V_6 . V_11 ) ;
if ( V_3 > 1 ) {
V_3 = - V_221 ;
goto V_228;
}
V_132 = F_27 ( V_262 . V_90 , struct V_140 , V_133 ) ;
F_38 ( V_69 ) ;
V_287 = F_156 ( F_70 ( V_132 -> V_134 ) ) ;
F_40 ( V_69 ) ;
if ( V_287 ) {
F_12 ( L_34 ,
V_2 ) ;
V_3 = - V_288 ;
goto V_228;
}
V_3 = F_90 ( & V_157 , & V_166 , 1 + F_84 () ,
false ) ;
if ( V_3 )
goto V_228;
F_45 ( & V_132 -> V_133 ) ;
V_3 = F_122 ( V_132 , V_218 ) ;
if ( V_3 )
goto V_289;
if ( V_132 -> V_144 -> V_145 ) {
V_3 = F_142 () ;
if ( V_3 < 0 ) {
F_12 ( L_35 ) ;
F_120 ( V_132 ) ;
goto V_289;
}
}
F_105 ( V_157 , V_166 ) ;
F_34 ( & V_6 . V_11 ) ;
return 0 ;
V_289:
F_96 ( V_157 , & V_166 ) ;
F_85 ( V_157 ) ;
V_228:
F_34 ( & V_6 . V_11 ) ;
while ( ! F_15 ( & V_262 ) ) {
V_132 = F_27 ( V_262 . V_90 , struct V_140 , V_133 ) ;
F_45 ( & V_132 -> V_133 ) ;
F_116 ( V_132 ) ;
}
return V_3 ;
}
int
F_157 ( T_2 V_131 )
{
T_7 * V_132 ;
struct V_146 * V_157 ;
T_10 V_166 ;
int V_3 ;
if ( F_123 ( V_131 ) == V_211 )
return - V_221 ;
F_29 ( & V_6 . V_11 ) ;
V_3 = F_90 ( & V_157 , & V_166 ,
F_84 () - 1 , false ) ;
if ( V_3 )
goto V_100;
V_132 = F_72 ( V_131 ) ;
if ( ! V_132 ) {
V_3 = - V_221 ;
goto V_21;
}
F_79 ( V_132 , 0 ) ;
F_120 ( V_132 ) ;
if ( ! F_82 () )
F_146 () ;
F_105 ( V_157 , V_166 ) ;
goto V_100;
V_21:
F_96 ( V_157 , & V_166 ) ;
F_85 ( V_157 ) ;
V_100:
F_34 ( & V_6 . V_11 ) ;
return V_3 ;
}
int
F_158 ( unsigned int V_290 , void * V_291 )
{
struct V_292 * V_293 = V_291 ;
struct V_217 * V_271 ;
T_11 V_169 = { 0 } ;
T_7 * V_132 ;
int V_3 ;
unsigned long V_294 ;
F_23 ( V_295 <
sizeof( struct V_273 ) +
sizeof( struct V_217 ) ) ;
switch ( V_290 ) {
case V_296 :
V_3 = F_159 ( V_293 -> V_297 , & V_169 ) ;
V_293 -> V_298 = V_169 . V_135 ;
return V_3 ;
case V_299 :
return F_64 ( V_293 -> V_298 , V_293 -> V_297 ) ;
case V_300 :
V_271 = V_291 ;
if ( V_271 -> V_230 . V_231 < sizeof( * V_271 ) )
return - V_221 ;
F_29 ( & V_6 . V_11 ) ;
V_3 = F_160 ( V_271 -> V_235 ,
V_271 -> V_234 . V_301 . V_302 ,
V_271 -> V_278 ,
V_271 -> V_234 . V_301 . V_303 ) ;
if ( ! V_3 ) {
V_3 = F_140 () ;
if ( V_3 )
F_161 ( V_271 -> V_235 ,
V_271 -> V_278 ) ;
}
F_34 ( & V_6 . V_11 ) ;
return V_3 ;
case V_304 :
V_271 = V_291 ;
if ( V_271 -> V_230 . V_231 < sizeof( * V_271 ) )
return - V_221 ;
F_29 ( & V_6 . V_11 ) ;
V_3 = F_161 ( V_271 -> V_235 , V_271 -> V_278 ) ;
F_34 ( & V_6 . V_11 ) ;
return V_3 ;
case V_305 :
V_271 = V_291 ;
if ( V_271 -> V_230 . V_231 < sizeof( * V_271 ) )
return - V_221 ;
return F_162 ( V_271 -> V_284 ,
& V_271 -> V_235 ,
& V_271 -> V_234 . V_301 . V_302 ,
& V_271 -> V_278 ,
& V_271 -> V_234 . V_301 . V_306 ,
& V_271 -> V_234 . V_301 . V_303 ) ;
case V_307 : {
T_15 V_308 = sizeof( * V_271 ) +
sizeof( struct V_273 ) ;
V_271 = V_291 ;
if ( V_271 -> V_230 . V_231 < V_308 )
return - V_221 ;
return F_154 ( V_271 ) ;
}
case V_309 : {
struct V_310 * V_311 = V_291 ;
if ( V_311 -> V_312 . V_231 < sizeof( * V_311 ) )
return - V_221 ;
F_37 ( & V_311 -> V_313 ) ;
return 0 ;
}
case V_314 :
V_271 = V_291 ;
if ( V_271 -> V_230 . V_231 < sizeof( * V_271 ) )
return - V_221 ;
F_29 ( & V_6 . V_11 ) ;
if ( V_271 -> V_234 . V_315 . V_316 ) {
V_3 = F_163 () ;
F_34 ( & V_6 . V_11 ) ;
return V_3 ;
}
F_164 () ;
F_34 ( & V_6 . V_11 ) ;
return 0 ;
case V_317 :
V_271 = V_291 ;
if ( V_271 -> V_230 . V_231 < sizeof( * V_271 ) )
return - V_221 ;
F_29 ( & V_6 . V_11 ) ;
V_3 = F_165 ( V_271 -> V_234 . V_315 . V_318 ,
V_271 -> V_234 . V_315 . V_319 ,
V_271 -> V_234 . V_315 . V_320 ) ;
F_34 ( & V_6 . V_11 ) ;
return V_3 ;
case V_321 : {
struct V_322 * V_323 ;
T_15 V_308 = sizeof( * V_271 ) + sizeof( * V_323 ) ;
V_271 = V_291 ;
if ( V_271 -> V_230 . V_231 < V_308 )
return - V_221 ;
V_323 = (struct V_322 * ) V_271 -> V_232 ;
return F_166 ( V_271 -> V_284 , V_323 ) ;
}
case V_324 : {
struct V_325 * V_326 = V_291 ;
if ( V_326 -> V_327 . V_231 < sizeof( * V_326 ) )
return - V_221 ;
return F_167 ( V_326 -> V_328 ,
& V_326 -> V_329 ,
V_326 -> V_330 . V_331 . V_332 ,
& V_326 -> V_330 . V_331 . V_333 ,
& V_326 -> V_330 . V_331 . V_334 ,
& V_326 -> V_330 . V_331 . V_335 ,
& V_326 -> V_330 . V_331 . V_336 ,
& V_326 -> V_330 . V_331 . V_337 ,
& V_326 -> V_330 . V_331 . V_338 ,
& V_326 -> V_330 . V_331 . V_339 ) ;
}
case V_340 :
V_294 = ( F_168 () - V_293 -> V_341 [ 0 ] ) ;
V_294 *= F_169 ( V_342 ) ;
return F_170 ( NULL , V_293 -> V_298 , V_293 -> V_343 ,
V_344 - V_294 ) ;
case V_345 :
V_3 = F_171 ( V_293 -> V_298 , & V_293 -> V_298 , & V_293 -> V_346 [ 1 ] ) ;
if ( V_3 < 0 && V_3 != - V_347 )
return V_3 ;
V_293 -> V_346 [ 0 ] = V_3 ;
return 0 ;
case V_348 :
F_38 ( V_69 ) ;
V_6 . V_349 = V_293 -> V_343 ;
F_40 ( V_69 ) ;
return 0 ;
case V_350 :
return F_172 ( V_293 -> V_343 , V_293 ) ;
case V_351 :
V_169 . V_135 = V_293 -> V_298 ;
V_169 . V_352 = V_293 -> V_346 [ 0 ] ;
V_3 = F_173 ( V_169 , V_293 -> V_346 [ 1 ] ,
V_293 -> V_353 ,
V_293 -> V_354 / sizeof( T_11 ) ) ;
if ( V_3 < 0 )
return V_3 ;
V_293 -> V_297 = V_3 ;
return 0 ;
default:
V_132 = F_72 ( V_293 -> V_355 ) ;
if ( ! V_132 )
return - V_221 ;
if ( ! V_132 -> V_144 -> V_356 )
V_3 = - V_221 ;
else
V_3 = V_132 -> V_144 -> V_356 ( V_132 , V_290 , V_291 ) ;
F_174 ( V_132 ) ;
return V_3 ;
}
}
void F_175 ( T_11 V_169 )
{
F_176 ( V_169 . V_135 ) ;
}
int
F_159 ( unsigned int V_357 , T_11 * V_169 )
{
struct V_140 * V_132 ;
struct V_13 * V_61 ;
int V_97 ;
int V_3 = - V_285 ;
F_10 ( V_6 . V_114 > 0 ) ;
V_97 = F_77 () ;
F_26 (tmp, &the_lnet.ln_nis) {
if ( V_357 -- )
continue;
V_132 = F_27 ( V_61 , T_7 , V_133 ) ;
V_169 -> V_135 = V_132 -> V_134 ;
V_169 -> V_352 = V_6 . V_117 ;
V_3 = 0 ;
break;
}
F_40 ( V_97 ) ;
return V_3 ;
}
void
F_177 ( char * V_358 , int V_359 , T_17 V_360 )
{
snprintf ( V_358 , V_359 , L_36 , V_360 . V_102 ) ;
}
static int F_173 ( T_11 V_169 , int V_361 ,
T_11 T_18 * V_362 , int V_363 )
{
T_19 V_364 ;
T_10 V_365 ;
T_9 V_160 ;
T_13 V_161 = { NULL } ;
int V_366 ;
int V_163 = 0 ;
int V_367 = 0 ;
const int V_368 = 60000 ;
int V_149 ;
struct V_146 * V_369 ;
T_11 V_370 ;
int V_12 ;
int V_371 ;
int V_3 ;
int V_171 ;
T_14 V_191 ;
V_149 = F_24 ( struct V_146 , V_150 [ V_363 ] ) ;
if ( V_363 <= 0 ||
V_169 . V_135 == V_130 ||
V_361 > 500000 ||
V_363 > 20 )
return - V_221 ;
if ( V_169 . V_352 == V_112 )
V_169 . V_352 = V_372 ;
F_11 ( V_369 , V_149 ) ;
if ( ! V_369 )
return - V_18 ;
V_3 = F_91 ( 2 , V_373 , & V_364 ) ;
if ( V_3 ) {
F_12 ( L_37 , V_3 ) ;
goto V_374;
}
V_161 . V_179 = V_369 ;
V_161 . V_180 = V_149 ;
V_161 . V_181 = 2 ;
V_161 . V_183 = 0 ;
V_161 . V_184 = V_186 ;
V_161 . V_162 = NULL ;
V_161 . V_188 = V_364 ;
V_3 = F_178 ( V_161 , V_176 , & V_365 ) ;
if ( V_3 ) {
F_12 ( L_38 , V_3 ) ;
goto V_375;
}
V_3 = F_179 ( V_130 , V_365 , V_169 ,
V_174 ,
V_175 , 0 ) ;
if ( V_3 ) {
V_171 = F_98 ( V_365 ) ;
F_10 ( ! V_171 ) ;
V_163 = 1 ;
V_361 = V_368 ;
}
do {
if ( V_163 )
V_191 = F_97 () ;
V_171 = F_180 ( & V_364 , 1 , V_361 , & V_160 , & V_366 ) ;
if ( V_163 )
F_103 ( V_191 ) ;
F_32 ( V_66 , L_39 , V_171 ,
( V_171 <= 0 ) ? - 1 : V_160 . type ,
( V_171 <= 0 ) ? - 1 : V_160 . V_376 ,
( V_171 > 0 && V_160 . V_163 ) ? L_40 : L_28 ) ;
F_10 ( V_171 != - V_377 ) ;
if ( V_171 <= 0 || V_160 . V_376 ) {
if ( ! V_367 && ! V_3 )
V_3 = ( V_171 < 0 ) ? V_171 :
! V_171 ? - V_378 :
V_160 . V_376 ;
if ( ! V_163 ) {
F_98 ( V_365 ) ;
V_163 = 1 ;
V_361 = V_368 ;
} else if ( ! V_171 ) {
F_181 ( L_41 ,
F_182 ( V_169 ) ) ;
}
} else if ( V_160 . type == V_379 ) {
V_367 = 1 ;
V_3 = V_160 . V_47 ;
}
} while ( V_171 <= 0 || ! V_160 . V_163 );
if ( ! V_367 ) {
if ( V_3 >= 0 )
F_181 ( L_42 ,
F_182 ( V_169 ) ) ;
V_3 = - V_380 ;
goto V_375;
}
V_371 = V_3 ;
F_10 ( V_371 >= 0 && V_371 <= V_149 ) ;
V_3 = - V_381 ;
if ( V_371 < 8 ) {
F_12 ( L_43 ,
F_182 ( V_169 ) , V_371 ) ;
goto V_375;
}
if ( V_369 -> V_153 == F_183 ( V_154 ) ) {
F_184 ( V_369 ) ;
} else if ( V_369 -> V_153 != V_154 ) {
F_12 ( L_44 ,
F_182 ( V_169 ) , V_369 -> V_153 ) ;
goto V_375;
}
if ( ! ( V_369 -> V_155 & V_156 ) ) {
F_12 ( L_45 ,
F_182 ( V_169 ) , V_369 -> V_155 ) ;
goto V_375;
}
if ( V_371 < F_24 ( struct V_146 , V_150 [ 0 ] ) ) {
F_12 ( L_46 , F_182 ( V_169 ) ,
V_371 , ( int ) F_24 ( struct V_146 , V_150 [ 0 ] ) ) ;
goto V_375;
}
if ( V_369 -> V_151 < V_363 )
V_363 = V_369 -> V_151 ;
if ( V_371 < F_24 ( struct V_146 , V_150 [ V_363 ] ) ) {
F_12 ( L_47 , F_182 ( V_169 ) ,
V_371 , ( int ) F_24 ( struct V_146 , V_150 [ V_363 ] ) ) ;
goto V_375;
}
V_3 = - V_382 ;
memset ( & V_370 , 0 , sizeof( V_370 ) ) ;
for ( V_12 = 0 ; V_12 < V_363 ; V_12 ++ ) {
V_370 . V_352 = V_369 -> V_152 ;
V_370 . V_135 = V_369 -> V_150 [ V_12 ] . V_195 ;
if ( F_185 ( & V_362 [ V_12 ] , & V_370 , sizeof( V_370 ) ) )
goto V_375;
}
V_3 = V_369 -> V_151 ;
V_375:
V_171 = F_95 ( V_364 ) ;
if ( V_171 )
F_12 ( L_48 , V_171 ) ;
F_10 ( ! V_171 ) ;
V_374:
F_16 ( V_369 , V_149 ) ;
return V_3 ;
}
