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
V_16 ;
F_11 ( exp ) ;
F_12 ( exp ) ;
RETURN ( 0 ) ;
}
static T_1 F_13 ( struct V_4 * V_17 )
{
T_2 V_18 ;
F_14 ( & V_17 -> V_19 . V_20 . V_21 ) ;
V_18 = ++ V_17 -> V_19 . V_20 . V_22 ;
F_15 ( & V_17 -> V_19 . V_20 . V_21 ) ;
return V_18 ;
}
static int F_16 ( const struct V_1 * V_2 , struct V_3 * exp ,
struct V_23 * V_24 , struct V_25 * * V_26 ,
struct V_27 * V_28 )
{
struct V_4 * V_5 = F_17 ( exp ) ;
if ( ! V_5 ) {
F_3 ( L_2 V_29 L_3 ,
exp -> V_30 . V_31 ) ;
return - V_32 ;
}
if ( ! ( V_24 -> V_33 && V_34 ) ) {
F_3 ( L_4 ) ;
return - V_35 ;
}
if ( ! ( V_24 -> V_36 & V_37 ) ) {
F_3 ( L_5 V_29 L_3 , V_24 -> V_36 ) ;
return - V_32 ;
}
F_18 ( & V_24 -> V_38 ) ;
F_19 ( & V_24 -> V_38 , F_13 ( V_5 ) ) ;
V_24 -> V_36 = V_39 ;
return 0 ;
}
static int F_20 ( const struct V_1 * V_2 , struct V_3 * exp ,
struct V_23 * V_24 , struct V_25 * V_26 ,
struct V_27 * V_28 , struct V_3 * V_40 ,
void * V_41 )
{
struct V_4 * V_5 = F_17 ( exp ) ;
V_16 ;
if ( ! V_5 ) {
F_3 ( L_2 V_29 L_3 ,
exp -> V_30 . V_31 ) ;
RETURN ( - V_32 ) ;
}
if ( ! ( V_24 -> V_36 & V_39 ) ) {
F_3 ( L_6 V_29 L_3 , V_24 -> V_36 ) ;
RETURN ( - V_32 ) ;
}
if ( F_21 ( & V_24 -> V_38 ) > V_5 -> V_19 . V_20 . V_22 ||
F_21 ( & V_24 -> V_38 ) < V_42 ) {
F_3 ( L_7 V_43 L_3 , F_22 ( & V_24 -> V_38 ) ) ;
RETURN ( - V_32 ) ;
}
RETURN ( 0 ) ;
}
static int F_23 ( const struct V_1 * V_2 , struct V_3 * exp ,
struct V_44 * V_45 )
{
struct V_4 * V_5 = F_17 ( exp ) ;
T_2 V_18 = F_21 ( & V_45 -> V_46 -> V_38 ) ;
V_16 ;
if ( ! V_5 ) {
F_3 ( L_2 V_29 L_3 ,
exp -> V_30 . V_31 ) ;
RETURN ( - V_32 ) ;
}
if ( ! ( V_45 -> V_46 -> V_36 & V_39 ) ) {
F_3 ( L_6 V_29 L_3 ,
V_45 -> V_46 -> V_36 ) ;
RETURN ( - V_32 ) ;
}
F_24 ( V_45 -> V_46 , & V_5 -> V_19 . V_20 . V_47 , V_45 -> V_46 -> V_36 ) ;
F_18 ( & V_45 -> V_46 -> V_38 ) ;
F_19 ( & V_45 -> V_46 -> V_38 , V_18 ) ;
RETURN ( 0 ) ;
}
static int F_25 ( const struct V_1 * V_2 , struct V_3 * exp ,
struct V_44 * V_45 , struct V_27 * V_28 )
{
struct V_4 * V_5 = F_17 ( exp ) ;
V_16 ;
if ( ! V_5 ) {
F_3 ( L_2 V_29 L_3 ,
exp -> V_30 . V_31 ) ;
RETURN ( - V_32 ) ;
}
if ( ! ( V_45 -> V_46 -> V_36 & V_39 ) ) {
F_3 ( L_6 V_29 L_3 ,
V_45 -> V_46 -> V_36 ) ;
RETURN ( - V_32 ) ;
}
memcpy ( & V_5 -> V_19 . V_20 . V_47 , V_45 -> V_46 , sizeof( * V_45 -> V_46 ) ) ;
if ( F_21 ( & V_45 -> V_46 -> V_38 ) & 4 ) {
F_26 ( & V_5 -> V_19 . V_20 . V_48 , V_49 ) ;
V_28 -> V_50 [ 0 ] . V_51 = V_49 ;
V_28 -> V_50 [ 0 ] . V_52 = V_5 -> V_19 . V_20 . V_48 ;
}
RETURN ( 0 ) ;
}
static void
F_27 ( struct V_53 * V_53 , int V_54 , T_2 V_18 ,
T_1 V_55 , int V_56 )
{
int V_57 = V_55 & ~ V_58 ;
char * V_59 = ( ( char * ) F_28 ( V_53 ) ) + V_57 ;
if ( V_56 % V_60 != 0 )
F_3 ( L_8 , V_56 ) ;
while ( V_56 > 0 ) {
if ( V_54 & V_61 )
F_29 ( V_59 , V_60 ,
V_55 , V_18 ) ;
else
F_29 ( V_59 , V_60 ,
0xecc0ecc0ecc0ecc0ULL ,
0xecc0ecc0ecc0ecc0ULL ) ;
V_59 += V_60 ;
V_55 += V_60 ;
V_56 -= V_60 ;
}
F_30 ( V_53 ) ;
}
static int
F_31 ( struct V_53 * V_53 , T_2 V_18 ,
T_1 V_55 , int V_56 )
{
int V_57 = V_55 & ~ V_58 ;
char * V_59 = ( ( char * ) F_28 ( V_53 ) ) + V_57 ;
int V_13 = 0 ;
int V_62 ;
if ( V_56 % V_60 != 0 )
F_3 ( L_8 , V_56 ) ;
while ( V_56 > 0 ) {
V_62 = F_32 ( L_9 , V_59 , V_60 ,
V_55 , V_18 ) ;
if ( V_62 != 0 && V_13 == 0 )
V_13 = V_62 ;
V_59 += V_60 ;
V_55 += V_60 ;
V_56 -= V_60 ;
}
F_30 ( V_53 ) ;
return ( V_13 ) ;
}
static int F_33 ( struct V_23 * V_24 , struct V_63 * V_64 ,
struct V_65 * V_66 , int * V_67 ,
struct V_68 * V_69 , int V_70 , int * V_71 )
{
int V_72 = ( F_21 ( & V_64 -> V_73 ) & 1 ) ?
V_74 : V_75 ;
int V_76 = F_21 ( & V_64 -> V_73 ) == V_77 ;
int V_78 = ( ! V_76 &&
( V_24 -> V_36 & V_79 ) != 0 &&
( V_24 -> V_80 & V_81 ) != 0 ) ;
struct V_68 * V_82 = V_69 ;
T_3 V_55 = V_66 -> V_55 ;
int V_56 = V_66 -> V_56 ;
while ( V_56 > 0 ) {
int V_83 = V_84 - ( V_55 & ( V_84 - 1 ) ) ;
if ( V_56 < V_83 )
V_83 = V_56 ;
if ( * V_71 == 0 )
return - V_32 ;
V_82 -> V_85 = V_55 ;
V_82 -> V_56 = V_83 ;
F_6 ( ( V_82 -> V_85 & ~ V_58 ) + V_82 -> V_56 <=
V_84 ) ;
if ( V_76 &&
( ( V_82 -> V_85 >> V_86 ) <
V_87 ) ) {
V_82 -> V_53 =
V_88 [ V_82 -> V_85 >>
V_86 ] ;
F_34 ( V_82 -> V_53 ) ;
} else {
F_35 ( V_82 -> V_53 , V_72 ) ;
if ( V_82 -> V_53 == NULL ) {
F_3 ( L_10 V_43 L_3 ,
F_22 ( & V_64 -> V_73 ) ) ;
return - V_89 ;
}
}
F_36 ( V_90 , L_11 V_91 L_12 ,
V_82 -> V_53 , V_82 -> V_85 , V_82 -> V_56 ) ;
if ( V_70 & V_61 )
V_82 -> V_13 = V_82 -> V_56 ;
if ( V_78 )
F_27 ( V_82 -> V_53 , V_70 ,
F_21 ( & V_64 -> V_73 ) ,
V_82 -> V_85 , V_82 -> V_56 ) ;
V_55 += V_83 ;
V_56 -= V_83 ;
V_82 ++ ;
( * V_71 ) -- ;
( * V_67 ) ++ ;
}
return 0 ;
}
static int F_37 ( struct V_23 * V_24 , struct V_63 * V_64 ,
struct V_65 * V_92 , int * V_93 ,
struct V_68 * V_69 , int V_94 )
{
struct V_68 * V_82 = V_69 ;
T_3 V_95 = V_92 -> V_55 >> V_86 ;
T_3 V_96 = ( V_92 -> V_55 + V_92 -> V_56 + V_84 - 1 ) >> V_86 ;
int V_97 = ( int ) ( V_96 - V_95 ) ;
int V_13 = 0 ;
int V_98 ;
for ( V_98 = 0 ; V_98 < V_97 ; V_98 ++ , ( * V_93 ) ++ , V_82 ++ ) {
struct V_53 * V_53 = V_82 -> V_53 ;
void * V_59 ;
if ( V_53 == NULL ) {
F_3 ( L_13 V_91 L_14 ,
F_21 ( & V_64 -> V_73 ) , V_53 , V_98 ,
V_64 -> V_99 ) ;
return - V_100 ;
}
V_59 = F_28 ( V_53 ) ;
F_36 ( V_90 , L_15 V_91 L_3 ,
V_82 -> V_53 , V_59 , V_82 -> V_85 ) ;
if ( V_94 ) {
int V_101 = F_31 ( V_53 ,
F_21 ( & V_64 -> V_73 ) ,
V_82 -> V_85 ,
V_82 -> V_56 ) ;
if ( V_101 != 0 && V_13 == 0 )
V_13 = V_101 ;
}
F_30 ( V_53 ) ;
F_38 ( V_53 ) ;
}
return V_13 ;
}
static int F_39 ( const struct V_1 * V_2 , int V_70 ,
struct V_3 * V_102 , struct V_23 * V_24 ,
int V_103 , struct V_63 * V_64 ,
struct V_65 * V_66 , int * V_67 ,
struct V_68 * V_82 , struct V_27 * V_28 ,
struct V_104 * V_105 )
{
struct V_4 * V_5 ;
int V_106 = 0 ;
int V_13 = 0 ;
int V_98 , V_71 ;
V_16 ;
V_5 = V_102 -> V_107 ;
if ( V_5 == NULL )
RETURN ( - V_32 ) ;
V_24 -> V_36 &= ~ ( V_108 | V_109 ) ;
memset ( V_82 , 0 , sizeof( * V_82 ) * * V_67 ) ;
F_36 ( V_90 , L_16 ,
V_70 == V_61 ? L_17 : L_18 , V_103 , * V_67 ) ;
if ( V_28 )
V_28 -> V_110 = ( void * ) V_111 ;
V_71 = * V_67 ;
* V_67 = 0 ;
for ( V_98 = 0 ; V_98 < V_103 ; V_98 ++ , V_64 ++ ) {
int V_112 ;
for ( V_112 = 0 ; V_112 < V_64 -> V_99 ; V_112 ++ , V_66 ++ ) {
V_13 = F_33 ( V_24 , V_64 , V_66 , V_67 ,
V_82 + * V_67 , V_70 , & V_71 ) ;
if ( V_13 )
GOTO ( V_113 , V_13 ) ;
V_106 += V_66 -> V_56 ;
}
}
F_40 ( * V_67 , & V_5 -> V_19 . V_20 . V_114 ) ;
if ( V_70 & V_61 )
F_41 ( V_5 -> V_115 , V_116 ,
V_106 ) ;
else
F_41 ( V_5 -> V_115 , V_117 ,
V_106 ) ;
F_36 ( V_90 , L_19 ,
F_42 ( & V_5 -> V_19 . V_20 . V_114 ) ) ;
RETURN ( 0 ) ;
V_113:
F_3 ( L_20 , * V_67 , V_103 ) ;
for ( V_98 = 0 ; V_98 < * V_67 ; V_98 ++ ) {
F_30 ( V_82 [ V_98 ] . V_53 ) ;
F_38 ( V_82 [ V_98 ] . V_53 ) ;
V_82 [ V_98 ] . V_53 = NULL ;
F_43 ( & V_5 -> V_19 . V_20 . V_114 ) ;
}
return V_13 ;
}
static int F_44 ( const struct V_1 * V_2 , int V_70 ,
struct V_3 * V_102 , struct V_23 * V_24 ,
int V_103 , struct V_63 * V_64 ,
struct V_65 * V_92 , int V_118 ,
struct V_68 * V_82 , struct V_27 * V_28 ,
int V_13 )
{
struct V_4 * V_5 ;
int V_93 = 0 ;
int V_98 ;
V_16 ;
V_5 = V_102 -> V_107 ;
if ( V_5 == NULL )
RETURN ( - V_32 ) ;
if ( V_13 )
GOTO ( V_119 , V_13 ) ;
if ( ( V_70 & V_120 ) == V_61 ) {
F_36 ( V_90 , L_21 ,
V_103 , V_118 ) ;
} else {
F_36 ( V_90 , L_22 ,
V_103 , V_118 ) ;
}
if ( V_118 && V_82 == NULL ) {
F_3 ( L_23 , V_118 ) ;
RETURN ( - V_32 ) ;
}
F_6 ( V_28 == NULL || V_28 -> V_110 == ( void * ) V_111 ) ;
for ( V_98 = 0 ; V_98 < V_103 ; V_98 ++ , V_64 ++ ) {
int V_94 = ( V_13 == 0 &&
F_21 ( & V_64 -> V_73 ) != V_77 &&
( V_24 -> V_36 & V_79 ) != 0 &&
( V_24 -> V_80 & V_81 ) != 0 ) ;
int V_112 ;
for ( V_112 = 0 ; V_112 < V_64 -> V_99 ; V_112 ++ , V_92 ++ ) {
int V_101 = F_37 ( V_24 , V_64 , V_92 , & V_93 , & V_82 [ V_93 ] ,
V_94 ) ;
if ( V_101 == 0 )
continue;
if ( V_101 == - V_100 )
GOTO ( V_119 , V_13 = V_101 ) ;
if ( V_13 == 0 )
V_13 = V_101 ;
}
}
F_45 ( V_93 , & V_5 -> V_19 . V_20 . V_114 ) ;
F_36 ( V_90 , L_24 ,
F_42 ( & V_5 -> V_19 . V_20 . V_114 ) ) ;
RETURN ( V_13 ) ;
V_119:
F_45 ( V_93 , & V_5 -> V_19 . V_20 . V_114 ) ;
F_3 ( L_25 ,
V_118 - V_93 - 1 , V_103 ) ;
while ( V_93 < V_118 ) {
struct V_53 * V_53 = V_82 [ V_93 ++ ] . V_53 ;
if ( V_53 == NULL )
continue;
F_38 ( V_53 ) ;
F_43 ( & V_5 -> V_19 . V_20 . V_114 ) ;
}
return V_13 ;
}
static int F_46 ( struct V_4 * V_5 , struct V_121 * V_122 )
{
struct V_123 V_124 ;
int V_13 ;
T_1 V_125 = 0 ;
struct V_126 V_127 = { . V_128 = { 1 } } ;
char V_129 [ 48 ] ;
V_16 ;
V_5 -> V_19 . V_20 . V_130 . V_131 = V_132 ;
F_47 ( & V_5 -> V_19 . V_20 . V_21 ) ;
V_5 -> V_19 . V_20 . V_22 = V_42 ;
sprintf ( V_129 , L_26 , V_5 -> V_6 . V_133 ) ;
V_5 -> V_134 = F_48 ( V_5 , V_129 ,
V_135 ,
V_136 ,
V_137 ) ;
if ( V_5 -> V_134 == NULL ) {
F_49 () ;
RETURN ( - V_89 ) ;
}
V_13 = F_50 ( V_5 -> V_134 , & V_127 , V_138 ,
NULL , V_49 , & V_125 , NULL ,
V_139 , NULL , NULL , 0 ,
V_140 , NULL , & V_5 -> V_19 . V_20 . V_48 ) ;
F_6 ( V_13 == V_141 ) ;
F_51 ( & V_124 ) ;
if ( F_52 ( V_5 , V_124 . V_142 ) == 0 &&
F_53 ( V_5 , V_143 ) == 0 ) {
F_54 ( V_5 -> V_115 , V_116 ,
V_144 ,
L_27 , L_28 ) ;
F_54 ( V_5 -> V_115 , V_117 ,
V_144 ,
L_29 , L_28 ) ;
}
F_55 ( V_145 , V_146 ,
L_30 , & V_5 -> V_147 ) ;
RETURN ( 0 ) ;
}
static int F_56 ( struct V_4 * V_5 )
{
int V_148 ;
V_16 ;
F_57 ( V_5 ) ;
F_58 ( V_5 ) ;
F_59 ( & V_5 -> V_19 . V_20 . V_48 , V_49 ) ;
F_60 ( V_149 , F_61 ( 1 ) ) ;
F_62 ( V_5 -> V_134 , NULL , V_5 -> V_150 ) ;
V_5 -> V_134 = NULL ;
V_148 = F_42 ( & V_5 -> V_19 . V_20 . V_114 ) ;
if ( V_148 != 0 )
F_3 ( L_31 , V_148 ) ;
RETURN ( 0 ) ;
}
void F_63 ( void )
{
int V_98 ;
for ( V_98 = 0 ; V_98 < V_87 ; V_98 ++ )
if ( V_88 [ V_98 ] != NULL ) {
F_38 ( V_88 [ V_98 ] ) ;
V_88 [ V_98 ] = NULL ;
}
}
int F_64 ( void )
{
struct V_53 * V_151 ;
int V_98 ;
for ( V_98 = 0 ; V_98 < V_87 ; V_98 ++ ) {
int V_72 = ( V_98 < V_87 / 2 ) ?
V_75 : V_74 ;
F_35 ( V_151 , V_72 ) ;
if ( V_151 == NULL ) {
F_63 () ;
return ( - V_89 ) ;
}
memset ( F_28 ( V_151 ) , 0 , V_84 ) ;
F_30 ( V_151 ) ;
V_88 [ V_98 ] = V_151 ;
}
return ( 0 ) ;
}
