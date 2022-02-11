static int F_1 ( const struct V_1 * V_2 ,
struct V_3 * * exp , struct V_4 * V_5 ,
struct V_6 * V_7 , struct V_8 * V_9 ,
void * V_10 )
{
struct V_11 V_12 = { 0 } ;
int V_13 ;
V_9 -> V_14 &= V_15 ;
V_13 = F_2 ( & V_12 , V_5 , V_7 ) ;
if ( V_13 ) {
F_3 ( L_1 , V_13 ) ;
return V_13 ;
}
* exp = F_4 ( & V_12 ) ;
return 0 ;
}
static int F_5 ( struct V_3 * exp )
{
F_6 ( exp != NULL ) ;
return F_7 ( exp ) ;
}
static int F_8 ( struct V_3 * exp )
{
return F_9 ( exp ) ;
}
static int F_10 ( struct V_3 * exp )
{
F_11 ( exp ) ;
F_12 ( exp ) ;
return 0 ;
}
static T_1 F_13 ( struct V_4 * V_16 )
{
T_2 V_17 ;
F_14 ( & V_16 -> V_18 . V_19 . V_20 ) ;
V_17 = ++ V_16 -> V_18 . V_19 . V_21 ;
F_15 ( & V_16 -> V_18 . V_19 . V_20 ) ;
return V_17 ;
}
static int F_16 ( const struct V_1 * V_2 , struct V_3 * exp ,
struct V_22 * V_23 , struct V_24 * * V_25 ,
struct V_26 * V_27 )
{
struct V_4 * V_5 = F_17 ( exp ) ;
if ( ! V_5 ) {
F_3 ( L_2 V_28 L_3 ,
exp -> V_29 . V_30 ) ;
return - V_31 ;
}
if ( ! ( V_23 -> V_32 && V_33 ) ) {
F_3 ( L_4 ) ;
return - V_34 ;
}
if ( ! ( V_23 -> V_35 & V_36 ) ) {
F_3 ( L_5 V_28 L_3 , V_23 -> V_35 ) ;
return - V_31 ;
}
F_18 ( & V_23 -> V_37 ) ;
F_19 ( & V_23 -> V_37 , F_13 ( V_5 ) ) ;
V_23 -> V_35 = V_38 ;
return 0 ;
}
static int F_20 ( const struct V_1 * V_2 , struct V_3 * exp ,
struct V_22 * V_23 , struct V_24 * V_25 ,
struct V_26 * V_27 , struct V_3 * V_39 ,
void * V_40 )
{
struct V_4 * V_5 = F_17 ( exp ) ;
if ( ! V_5 ) {
F_3 ( L_2 V_28 L_3 ,
exp -> V_29 . V_30 ) ;
return - V_31 ;
}
if ( ! ( V_23 -> V_35 & V_38 ) ) {
F_3 ( L_6 V_28 L_3 , V_23 -> V_35 ) ;
return - V_31 ;
}
if ( F_21 ( & V_23 -> V_37 ) > V_5 -> V_18 . V_19 . V_21 ||
F_21 ( & V_23 -> V_37 ) < V_41 ) {
F_3 ( L_7 V_42 L_3 , F_22 ( & V_23 -> V_37 ) ) ;
return - V_31 ;
}
return 0 ;
}
static int F_23 ( const struct V_1 * V_2 , struct V_3 * exp ,
struct V_43 * V_44 )
{
struct V_4 * V_5 = F_17 ( exp ) ;
T_2 V_17 = F_21 ( & V_44 -> V_45 -> V_37 ) ;
if ( ! V_5 ) {
F_3 ( L_2 V_28 L_3 ,
exp -> V_29 . V_30 ) ;
return - V_31 ;
}
if ( ! ( V_44 -> V_45 -> V_35 & V_38 ) ) {
F_3 ( L_6 V_28 L_3 ,
V_44 -> V_45 -> V_35 ) ;
return - V_31 ;
}
F_24 ( V_44 -> V_45 , & V_5 -> V_18 . V_19 . V_46 , V_44 -> V_45 -> V_35 ) ;
F_18 ( & V_44 -> V_45 -> V_37 ) ;
F_19 ( & V_44 -> V_45 -> V_37 , V_17 ) ;
return 0 ;
}
static int F_25 ( const struct V_1 * V_2 , struct V_3 * exp ,
struct V_43 * V_44 , struct V_26 * V_27 )
{
struct V_4 * V_5 = F_17 ( exp ) ;
if ( ! V_5 ) {
F_3 ( L_2 V_28 L_3 ,
exp -> V_29 . V_30 ) ;
return - V_31 ;
}
if ( ! ( V_44 -> V_45 -> V_35 & V_38 ) ) {
F_3 ( L_6 V_28 L_3 ,
V_44 -> V_45 -> V_35 ) ;
return - V_31 ;
}
memcpy ( & V_5 -> V_18 . V_19 . V_46 , V_44 -> V_45 , sizeof( * V_44 -> V_45 ) ) ;
if ( F_21 ( & V_44 -> V_45 -> V_37 ) & 4 ) {
F_26 ( & V_5 -> V_18 . V_19 . V_47 , V_48 ) ;
V_27 -> V_49 [ 0 ] . V_50 = V_48 ;
V_27 -> V_49 [ 0 ] . V_51 = V_5 -> V_18 . V_19 . V_47 ;
}
return 0 ;
}
static void
F_27 ( struct V_52 * V_52 , int V_53 , T_2 V_17 ,
T_1 V_54 , int V_55 )
{
int V_56 = V_54 & ~ V_57 ;
char * V_58 = ( ( char * ) F_28 ( V_52 ) ) + V_56 ;
if ( V_55 % V_59 != 0 )
F_3 ( L_8 , V_55 ) ;
while ( V_55 > 0 ) {
if ( V_53 & V_60 )
F_29 ( V_58 , V_59 ,
V_54 , V_17 ) ;
else
F_29 ( V_58 , V_59 ,
0xecc0ecc0ecc0ecc0ULL ,
0xecc0ecc0ecc0ecc0ULL ) ;
V_58 += V_59 ;
V_54 += V_59 ;
V_55 -= V_59 ;
}
F_30 ( V_52 ) ;
}
static int
F_31 ( struct V_52 * V_52 , T_2 V_17 ,
T_1 V_54 , int V_55 )
{
int V_56 = V_54 & ~ V_57 ;
char * V_58 = ( ( char * ) F_28 ( V_52 ) ) + V_56 ;
int V_13 = 0 ;
int V_61 ;
if ( V_55 % V_59 != 0 )
F_3 ( L_8 , V_55 ) ;
while ( V_55 > 0 ) {
V_61 = F_32 ( L_9 , V_58 , V_59 ,
V_54 , V_17 ) ;
if ( V_61 != 0 && V_13 == 0 )
V_13 = V_61 ;
V_58 += V_59 ;
V_54 += V_59 ;
V_55 -= V_59 ;
}
F_30 ( V_52 ) ;
return ( V_13 ) ;
}
static int F_33 ( struct V_22 * V_23 , struct V_62 * V_63 ,
struct V_64 * V_65 , int * V_66 ,
struct V_67 * V_68 , int V_69 , int * V_70 )
{
int V_71 = ( F_21 ( & V_63 -> V_72 ) & 1 ) ?
V_73 : V_74 ;
int V_75 = F_21 ( & V_63 -> V_72 ) == V_76 ;
int V_77 = ( ! V_75 &&
( V_23 -> V_35 & V_78 ) != 0 &&
( V_23 -> V_79 & V_80 ) != 0 ) ;
struct V_67 * V_81 = V_68 ;
T_3 V_54 = V_65 -> V_54 ;
int V_55 = V_65 -> V_55 ;
while ( V_55 > 0 ) {
int V_82 = V_83 - ( V_54 & ( V_83 - 1 ) ) ;
if ( V_55 < V_82 )
V_82 = V_55 ;
if ( * V_70 == 0 )
return - V_31 ;
V_81 -> V_84 = V_54 ;
V_81 -> V_55 = V_82 ;
F_6 ( ( V_81 -> V_84 & ~ V_57 ) + V_81 -> V_55 <=
V_83 ) ;
if ( V_75 &&
( ( V_81 -> V_84 >> V_85 ) <
V_86 ) ) {
V_81 -> V_52 =
V_87 [ V_81 -> V_84 >>
V_85 ] ;
F_34 ( V_81 -> V_52 ) ;
} else {
F_35 ( V_81 -> V_52 , V_71 ) ;
if ( V_81 -> V_52 == NULL ) {
F_3 ( L_10 V_42 L_3 ,
F_22 ( & V_63 -> V_72 ) ) ;
return - V_88 ;
}
}
F_36 ( V_89 , L_11 V_90 L_12 ,
V_81 -> V_52 , V_81 -> V_84 , V_81 -> V_55 ) ;
if ( V_69 & V_60 )
V_81 -> V_13 = V_81 -> V_55 ;
if ( V_77 )
F_27 ( V_81 -> V_52 , V_69 ,
F_21 ( & V_63 -> V_72 ) ,
V_81 -> V_84 , V_81 -> V_55 ) ;
V_54 += V_82 ;
V_55 -= V_82 ;
V_81 ++ ;
( * V_70 ) -- ;
( * V_66 ) ++ ;
}
return 0 ;
}
static int F_37 ( struct V_22 * V_23 , struct V_62 * V_63 ,
struct V_64 * V_91 , int * V_92 ,
struct V_67 * V_68 , int V_93 )
{
struct V_67 * V_81 = V_68 ;
T_3 V_94 = V_91 -> V_54 >> V_85 ;
T_3 V_95 = ( V_91 -> V_54 + V_91 -> V_55 + V_83 - 1 ) >> V_85 ;
int V_96 = ( int ) ( V_95 - V_94 ) ;
int V_13 = 0 ;
int V_97 ;
for ( V_97 = 0 ; V_97 < V_96 ; V_97 ++ , ( * V_92 ) ++ , V_81 ++ ) {
struct V_52 * V_52 = V_81 -> V_52 ;
void * V_58 ;
if ( V_52 == NULL ) {
F_3 ( L_13 V_90 L_14 ,
F_21 ( & V_63 -> V_72 ) , V_52 , V_97 ,
V_63 -> V_98 ) ;
return - V_99 ;
}
V_58 = F_28 ( V_52 ) ;
F_36 ( V_89 , L_15 V_90 L_3 ,
V_81 -> V_52 , V_58 , V_81 -> V_84 ) ;
if ( V_93 ) {
int V_100 = F_31 ( V_52 ,
F_21 ( & V_63 -> V_72 ) ,
V_81 -> V_84 ,
V_81 -> V_55 ) ;
if ( V_100 != 0 && V_13 == 0 )
V_13 = V_100 ;
}
F_30 ( V_52 ) ;
F_38 ( V_52 ) ;
}
return V_13 ;
}
static int F_39 ( const struct V_1 * V_2 , int V_69 ,
struct V_3 * V_101 , struct V_22 * V_23 ,
int V_102 , struct V_62 * V_63 ,
struct V_64 * V_65 , int * V_66 ,
struct V_67 * V_81 , struct V_26 * V_27 ,
struct V_103 * V_104 )
{
struct V_4 * V_5 ;
int V_105 = 0 ;
int V_13 = 0 ;
int V_97 , V_70 ;
V_5 = V_101 -> V_106 ;
if ( V_5 == NULL )
return - V_31 ;
V_23 -> V_35 &= ~ ( V_107 | V_108 ) ;
memset ( V_81 , 0 , sizeof( * V_81 ) * * V_66 ) ;
F_36 ( V_89 , L_16 ,
V_69 == V_60 ? L_17 : L_18 , V_102 , * V_66 ) ;
if ( V_27 )
V_27 -> V_109 = ( void * ) V_110 ;
V_70 = * V_66 ;
* V_66 = 0 ;
for ( V_97 = 0 ; V_97 < V_102 ; V_97 ++ , V_63 ++ ) {
int V_111 ;
for ( V_111 = 0 ; V_111 < V_63 -> V_98 ; V_111 ++ , V_65 ++ ) {
V_13 = F_33 ( V_23 , V_63 , V_65 , V_66 ,
V_81 + * V_66 , V_69 , & V_70 ) ;
if ( V_13 )
GOTO ( V_112 , V_13 ) ;
V_105 += V_65 -> V_55 ;
}
}
F_40 ( * V_66 , & V_5 -> V_18 . V_19 . V_113 ) ;
if ( V_69 & V_60 )
F_41 ( V_5 -> V_114 , V_115 ,
V_105 ) ;
else
F_41 ( V_5 -> V_114 , V_116 ,
V_105 ) ;
F_36 ( V_89 , L_19 ,
F_42 ( & V_5 -> V_18 . V_19 . V_113 ) ) ;
return 0 ;
V_112:
F_3 ( L_20 , * V_66 , V_102 ) ;
for ( V_97 = 0 ; V_97 < * V_66 ; V_97 ++ ) {
F_30 ( V_81 [ V_97 ] . V_52 ) ;
F_38 ( V_81 [ V_97 ] . V_52 ) ;
V_81 [ V_97 ] . V_52 = NULL ;
F_43 ( & V_5 -> V_18 . V_19 . V_113 ) ;
}
return V_13 ;
}
static int F_44 ( const struct V_1 * V_2 , int V_69 ,
struct V_3 * V_101 , struct V_22 * V_23 ,
int V_102 , struct V_62 * V_63 ,
struct V_64 * V_91 , int V_117 ,
struct V_67 * V_81 , struct V_26 * V_27 ,
int V_13 )
{
struct V_4 * V_5 ;
int V_92 = 0 ;
int V_97 ;
V_5 = V_101 -> V_106 ;
if ( V_5 == NULL )
return - V_31 ;
if ( V_13 )
GOTO ( V_118 , V_13 ) ;
if ( ( V_69 & V_119 ) == V_60 ) {
F_36 ( V_89 , L_21 ,
V_102 , V_117 ) ;
} else {
F_36 ( V_89 , L_22 ,
V_102 , V_117 ) ;
}
if ( V_117 && V_81 == NULL ) {
F_3 ( L_23 , V_117 ) ;
return - V_31 ;
}
F_6 ( V_27 == NULL || V_27 -> V_109 == ( void * ) V_110 ) ;
for ( V_97 = 0 ; V_97 < V_102 ; V_97 ++ , V_63 ++ ) {
int V_93 = ( V_13 == 0 &&
F_21 ( & V_63 -> V_72 ) != V_76 &&
( V_23 -> V_35 & V_78 ) != 0 &&
( V_23 -> V_79 & V_80 ) != 0 ) ;
int V_111 ;
for ( V_111 = 0 ; V_111 < V_63 -> V_98 ; V_111 ++ , V_91 ++ ) {
int V_100 = F_37 ( V_23 , V_63 , V_91 , & V_92 , & V_81 [ V_92 ] ,
V_93 ) ;
if ( V_100 == 0 )
continue;
if ( V_100 == - V_99 )
GOTO ( V_118 , V_13 = V_100 ) ;
if ( V_13 == 0 )
V_13 = V_100 ;
}
}
F_45 ( V_92 , & V_5 -> V_18 . V_19 . V_113 ) ;
F_36 ( V_89 , L_24 ,
F_42 ( & V_5 -> V_18 . V_19 . V_113 ) ) ;
return V_13 ;
V_118:
F_45 ( V_92 , & V_5 -> V_18 . V_19 . V_113 ) ;
F_3 ( L_25 ,
V_117 - V_92 - 1 , V_102 ) ;
while ( V_92 < V_117 ) {
struct V_52 * V_52 = V_81 [ V_92 ++ ] . V_52 ;
if ( V_52 == NULL )
continue;
F_38 ( V_52 ) ;
F_43 ( & V_5 -> V_18 . V_19 . V_113 ) ;
}
return V_13 ;
}
static int F_46 ( struct V_4 * V_5 , struct V_120 * V_121 )
{
struct V_122 V_123 ;
int V_13 ;
T_1 V_124 = 0 ;
struct V_125 V_126 = { . V_127 = { 1 } } ;
char V_128 [ 48 ] ;
V_5 -> V_18 . V_19 . V_129 . V_130 = V_131 ;
F_47 ( & V_5 -> V_18 . V_19 . V_20 ) ;
V_5 -> V_18 . V_19 . V_21 = V_41 ;
sprintf ( V_128 , L_26 , V_5 -> V_6 . V_132 ) ;
V_5 -> V_133 = F_48 ( V_5 , V_128 ,
V_134 ,
V_135 ,
V_136 ) ;
if ( V_5 -> V_133 == NULL ) {
F_49 () ;
return - V_88 ;
}
V_13 = F_50 ( V_5 -> V_133 , & V_126 , V_137 ,
NULL , V_48 , & V_124 , NULL ,
V_138 , NULL , NULL , 0 ,
V_139 , NULL , & V_5 -> V_18 . V_19 . V_47 ) ;
F_6 ( V_13 == V_140 ) ;
F_51 ( & V_123 ) ;
if ( F_52 ( V_5 , V_123 . V_141 ) == 0 &&
F_53 ( V_5 , V_142 ) == 0 ) {
F_54 ( V_5 -> V_114 , V_115 ,
V_143 ,
L_27 , L_28 ) ;
F_54 ( V_5 -> V_114 , V_116 ,
V_143 ,
L_29 , L_28 ) ;
}
F_55 ( V_144 , V_145 ,
L_30 , & V_5 -> V_146 ) ;
return 0 ;
}
static int F_56 ( struct V_4 * V_5 )
{
int V_147 ;
F_57 ( V_5 ) ;
F_58 ( V_5 ) ;
F_59 ( & V_5 -> V_18 . V_19 . V_47 , V_48 ) ;
F_60 ( V_148 , F_61 ( 1 ) ) ;
F_62 ( V_5 -> V_133 , NULL , V_5 -> V_149 ) ;
V_5 -> V_133 = NULL ;
V_147 = F_42 ( & V_5 -> V_18 . V_19 . V_113 ) ;
if ( V_147 != 0 )
F_3 ( L_31 , V_147 ) ;
return 0 ;
}
void F_63 ( void )
{
int V_97 ;
for ( V_97 = 0 ; V_97 < V_86 ; V_97 ++ )
if ( V_87 [ V_97 ] != NULL ) {
F_38 ( V_87 [ V_97 ] ) ;
V_87 [ V_97 ] = NULL ;
}
}
int F_64 ( void )
{
struct V_52 * V_150 ;
int V_97 ;
for ( V_97 = 0 ; V_97 < V_86 ; V_97 ++ ) {
int V_71 = ( V_97 < V_86 / 2 ) ?
V_74 : V_73 ;
F_35 ( V_150 , V_71 ) ;
if ( V_150 == NULL ) {
F_63 () ;
return ( - V_88 ) ;
}
memset ( F_28 ( V_150 ) , 0 , V_83 ) ;
F_30 ( V_150 ) ;
V_87 [ V_97 ] = V_150 ;
}
return ( 0 ) ;
}
