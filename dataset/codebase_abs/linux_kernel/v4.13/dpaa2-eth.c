static void * F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
T_2 V_4 ;
V_4 = V_2 ? F_2 ( V_2 , V_3 ) : V_3 ;
return F_3 ( V_4 ) ;
}
static void F_4 ( struct V_5 * V_6 ,
T_3 V_7 ,
struct V_8 * V_9 )
{
F_5 ( V_9 ) ;
if ( ! ( V_6 -> V_10 -> V_11 & V_12 ) )
return;
if ( ! ( ( V_7 & V_13 ) &&
( V_7 & V_14 ) ) )
return;
V_9 -> V_15 = V_16 ;
}
static void F_6 ( struct V_5 * V_6 ,
const struct V_17 * V_18 ,
void * V_19 )
{
struct V_20 * V_21 = V_6 -> V_10 -> V_21 . V_22 ;
T_1 V_23 = F_7 ( V_18 ) ;
T_4 V_24 = F_8 ( V_18 ) ;
struct V_25 * V_26 ;
void * V_27 ;
int V_28 ;
if ( V_24 == V_29 )
goto V_30;
else if ( V_24 != V_31 )
return;
V_26 = V_19 + F_9 ( V_18 ) ;
for ( V_28 = 0 ; V_28 < V_32 ; V_28 ++ ) {
V_23 = F_10 ( & V_26 [ V_28 ] ) ;
V_27 = F_1 ( V_6 -> V_1 , V_23 ) ;
F_11 ( V_21 , V_23 , V_33 ,
V_34 ) ;
F_12 ( V_27 ) ;
if ( F_13 ( & V_26 [ V_28 ] ) )
break;
}
V_30:
F_12 ( V_19 ) ;
}
static struct V_8 * F_14 ( struct V_5 * V_6 ,
struct V_35 * V_36 ,
const struct V_17 * V_18 ,
void * V_37 )
{
struct V_8 * V_9 = NULL ;
T_5 V_38 = F_9 ( V_18 ) ;
T_3 V_39 = F_15 ( V_18 ) ;
V_9 = F_16 ( V_37 , V_33 +
F_17 ( sizeof( struct V_40 ) ) ) ;
if ( F_18 ( ! V_9 ) )
return NULL ;
F_19 ( V_9 , V_38 ) ;
F_20 ( V_9 , V_39 ) ;
V_36 -> V_41 -- ;
return V_9 ;
}
static struct V_8 * F_21 ( struct V_5 * V_6 ,
struct V_35 * V_36 ,
struct V_25 * V_26 )
{
struct V_8 * V_9 = NULL ;
struct V_20 * V_21 = V_6 -> V_10 -> V_21 . V_22 ;
void * V_27 ;
T_1 V_42 ;
T_5 V_43 ;
T_3 V_44 ;
struct V_45 * V_45 , * V_46 ;
int V_47 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_32 ; V_28 ++ ) {
struct V_25 * V_48 = & V_26 [ V_28 ] ;
V_42 = F_10 ( V_48 ) ;
V_27 = F_1 ( V_6 -> V_1 , V_42 ) ;
F_11 ( V_21 , V_42 , V_33 ,
V_34 ) ;
V_44 = F_22 ( V_48 ) ;
if ( V_28 == 0 ) {
V_9 = F_16 ( V_27 , V_33 +
F_17 ( sizeof( struct V_40 ) ) ) ;
if ( F_18 ( ! V_9 ) )
return NULL ;
V_43 = F_23 ( V_48 ) ;
F_19 ( V_9 , V_43 ) ;
F_20 ( V_9 , V_44 ) ;
} else {
V_45 = F_24 ( V_27 ) ;
V_46 = F_25 ( V_27 ) ;
V_47 = ( ( unsigned long ) V_27 &
( V_49 - 1 ) ) +
( F_26 ( V_45 ) - F_26 ( V_46 ) ) ;
F_27 ( V_9 , V_28 - 1 , V_46 , V_47 ,
V_44 , V_33 ) ;
}
if ( F_13 ( V_48 ) )
break;
}
V_36 -> V_41 -= V_28 + 2 ;
return V_9 ;
}
static void F_28 ( struct V_5 * V_6 ,
struct V_35 * V_36 ,
const struct V_17 * V_18 ,
struct V_50 * V_51 )
{
T_1 V_23 = F_7 ( V_18 ) ;
T_4 V_24 = F_8 ( V_18 ) ;
void * V_19 ;
struct V_8 * V_9 ;
struct V_52 * V_53 ;
struct V_54 * V_55 ;
struct V_20 * V_21 = V_6 -> V_10 -> V_21 . V_22 ;
struct V_56 * V_57 ;
void * V_58 ;
T_3 V_59 = 0 ;
F_29 ( V_6 -> V_10 , V_18 ) ;
V_19 = F_1 ( V_6 -> V_1 , V_23 ) ;
F_11 ( V_21 , V_23 , V_33 , V_34 ) ;
V_57 = F_30 ( V_19 ) ;
F_31 ( V_57 ) ;
V_58 = V_19 + F_9 ( V_18 ) ;
F_31 ( V_58 ) ;
V_53 = F_32 ( V_6 -> V_53 ) ;
V_55 = F_32 ( V_6 -> V_55 ) ;
if ( V_24 == V_29 ) {
V_9 = F_14 ( V_6 , V_36 , V_18 , V_19 ) ;
} else if ( V_24 == V_31 ) {
V_9 = F_21 ( V_6 , V_36 , V_58 ) ;
F_12 ( V_19 ) ;
V_55 -> V_60 ++ ;
V_55 -> V_61 += F_15 ( V_18 ) ;
} else {
goto V_62;
}
if ( F_18 ( ! V_9 ) )
goto V_63;
F_31 ( V_9 -> V_64 ) ;
if ( F_33 ( F_34 ( V_18 ) & V_65 ) ) {
V_59 = F_35 ( V_57 -> V_59 ) ;
F_4 ( V_6 , V_59 , V_9 ) ;
}
V_9 -> V_66 = F_36 ( V_9 , V_6 -> V_10 ) ;
V_53 -> V_67 ++ ;
V_53 -> V_68 += F_15 ( V_18 ) ;
F_37 ( V_51 , V_9 ) ;
return;
V_63:
F_6 ( V_6 , V_18 , V_19 ) ;
V_62:
V_53 -> V_69 ++ ;
}
static int F_38 ( struct V_35 * V_36 )
{
struct V_5 * V_6 = V_36 -> V_6 ;
struct V_70 * V_71 ;
struct V_72 * V_73 ;
const struct V_17 * V_18 ;
int V_74 = 0 ;
int V_75 ;
do {
V_73 = F_39 ( V_36 -> V_76 , & V_75 ) ;
if ( F_18 ( ! V_73 ) ) {
continue;
}
V_18 = F_40 ( V_73 ) ;
V_71 = (struct V_70 * ) F_41 ( V_73 ) ;
V_71 -> V_77 . V_78 ++ ;
V_71 -> V_79 ( V_6 , V_36 , V_18 , & V_36 -> V_51 ) ;
V_74 ++ ;
} while ( ! V_75 );
return V_74 ;
}
static int F_42 ( struct V_5 * V_6 ,
struct V_8 * V_9 ,
struct V_17 * V_18 )
{
struct V_20 * V_21 = V_6 -> V_10 -> V_21 . V_22 ;
void * V_80 = NULL ;
T_1 V_23 ;
int V_81 = F_43 ( V_9 ) -> V_81 ;
struct V_25 * V_26 ;
int V_28 , V_82 ;
int V_83 ;
struct V_84 * V_85 , * V_86 ;
int V_87 ;
int V_88 ;
struct V_89 * V_90 ;
struct V_56 * V_57 ;
if ( F_18 ( V_49 / sizeof( struct V_84 ) < V_81 + 1 ) )
return - V_91 ;
V_85 = F_44 ( V_81 + 1 , sizeof( struct V_84 ) , V_92 ) ;
if ( F_18 ( ! V_85 ) )
return - V_93 ;
F_45 ( V_85 , V_81 + 1 ) ;
V_87 = F_46 ( V_9 , V_85 , 0 , V_9 -> V_94 ) ;
V_88 = F_47 ( V_21 , V_85 , V_87 , V_95 ) ;
if ( F_18 ( ! V_88 ) ) {
V_82 = - V_93 ;
goto V_96;
}
V_83 = V_6 -> V_97 +
sizeof( struct V_25 ) * ( 1 + V_88 ) ;
V_80 = F_48 ( V_83 + V_98 , V_92 ) ;
if ( F_18 ( ! V_80 ) ) {
V_82 = - V_93 ;
goto V_99;
}
V_80 = F_49 ( V_80 , V_98 ) ;
V_57 = F_30 ( V_80 ) ;
memset ( V_57 , 0 , V_100 ) ;
V_26 = (struct V_25 * ) ( V_80 + V_6 -> V_97 ) ;
F_50 (scl, crt_scl, num_dma_bufs, i) {
F_51 ( & V_26 [ V_28 ] , F_52 ( V_86 ) ) ;
F_53 ( & V_26 [ V_28 ] , F_54 ( V_86 ) ) ;
}
F_55 ( & V_26 [ V_28 - 1 ] , true ) ;
V_90 = (struct V_89 * ) V_80 ;
V_90 -> V_9 = V_9 ;
V_90 -> V_85 = V_85 ;
V_90 -> V_87 = V_87 ;
V_90 -> V_88 = V_88 ;
V_23 = F_56 ( V_21 , V_80 , V_83 , V_95 ) ;
if ( F_18 ( F_57 ( V_21 , V_23 ) ) ) {
V_82 = - V_93 ;
goto V_101;
}
F_58 ( V_18 , V_6 -> V_97 ) ;
F_59 ( V_18 , V_31 ) ;
F_60 ( V_18 , V_23 ) ;
F_61 ( V_18 , V_9 -> V_94 ) ;
F_62 ( V_18 , V_102 | V_103 |
V_104 ) ;
return 0 ;
V_101:
F_63 ( V_80 ) ;
V_99:
F_64 ( V_21 , V_85 , V_87 , V_95 ) ;
V_96:
F_63 ( V_85 ) ;
return V_82 ;
}
static int F_65 ( struct V_5 * V_6 ,
struct V_8 * V_9 ,
struct V_17 * V_18 )
{
struct V_20 * V_21 = V_6 -> V_10 -> V_21 . V_22 ;
T_4 * V_105 ;
struct V_56 * V_57 ;
struct V_8 * * V_106 ;
T_1 V_23 ;
V_105 = F_49 ( V_9 -> V_64 - V_6 -> V_97 -
V_98 ,
V_98 ) ;
V_57 = F_30 ( V_105 ) ;
memset ( V_57 , 0 , V_100 ) ;
V_106 = (struct V_8 * * ) V_105 ;
* V_106 = V_9 ;
V_23 = F_56 ( V_21 , V_105 ,
F_66 ( V_9 ) - V_105 ,
V_95 ) ;
if ( F_18 ( F_57 ( V_21 , V_23 ) ) )
return - V_93 ;
F_60 ( V_18 , V_23 ) ;
F_58 ( V_18 , ( T_5 ) ( V_9 -> V_64 - V_105 ) ) ;
F_61 ( V_18 , V_9 -> V_94 ) ;
F_59 ( V_18 , V_29 ) ;
F_62 ( V_18 , V_102 | V_103 |
V_104 ) ;
return 0 ;
}
static void F_67 ( const struct V_5 * V_6 ,
const struct V_17 * V_18 ,
T_3 * V_59 )
{
struct V_20 * V_21 = V_6 -> V_10 -> V_21 . V_22 ;
T_1 V_107 ;
struct V_8 * * V_106 , * V_9 ;
unsigned char * V_105 ;
int V_108 ;
struct V_84 * V_85 ;
int V_87 , V_88 ;
struct V_89 * V_90 ;
T_4 V_24 = F_8 ( V_18 ) ;
struct V_56 * V_57 ;
V_107 = F_7 ( V_18 ) ;
V_106 = F_1 ( V_6 -> V_1 , V_107 ) ;
V_57 = F_30 ( V_106 ) ;
if ( V_24 == V_29 ) {
V_9 = * V_106 ;
V_105 = ( unsigned char * ) V_106 ;
F_11 ( V_21 , V_107 ,
F_66 ( V_9 ) - V_105 ,
V_95 ) ;
} else if ( V_24 == V_31 ) {
V_90 = (struct V_89 * ) V_106 ;
V_9 = V_90 -> V_9 ;
V_85 = V_90 -> V_85 ;
V_87 = V_90 -> V_87 ;
V_88 = V_90 -> V_88 ;
F_64 ( V_21 , V_85 , V_87 , V_95 ) ;
F_63 ( V_85 ) ;
V_108 = V_6 -> V_97 +
sizeof( struct V_25 ) * ( 1 + V_88 ) ;
F_11 ( V_21 , V_107 , V_108 , V_95 ) ;
} else {
if ( V_59 )
* V_59 = ~ 0 ;
return;
}
if ( V_59 )
* V_59 = F_35 ( V_57 -> V_59 ) ;
if ( V_24 != V_29 )
F_63 ( V_106 ) ;
F_68 ( V_9 ) ;
}
static T_6 F_69 ( struct V_8 * V_9 , struct V_109 * V_10 )
{
struct V_5 * V_6 = F_70 ( V_10 ) ;
struct V_17 V_18 ;
struct V_52 * V_53 ;
struct V_54 * V_55 ;
struct V_70 * V_71 ;
T_5 V_110 ;
int V_82 , V_28 ;
V_53 = F_32 ( V_6 -> V_53 ) ;
V_55 = F_32 ( V_6 -> V_55 ) ;
if ( F_18 ( F_71 ( V_9 ) < F_72 ( V_6 ) ) ) {
struct V_8 * V_111 ;
V_111 = F_73 ( V_9 , F_72 ( V_6 ) ) ;
if ( F_18 ( ! V_111 ) ) {
V_53 -> V_112 ++ ;
goto V_113;
}
F_68 ( V_9 ) ;
V_9 = V_111 ;
}
V_9 = F_74 ( V_9 , V_92 ) ;
if ( F_18 ( ! V_9 ) ) {
V_53 -> V_112 ++ ;
return V_114 ;
}
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
if ( F_75 ( V_9 ) ) {
V_82 = F_42 ( V_6 , V_9 , & V_18 ) ;
V_55 -> V_115 ++ ;
V_55 -> V_116 += V_9 -> V_94 ;
} else {
V_82 = F_65 ( V_6 , V_9 , & V_18 ) ;
}
if ( F_18 ( V_82 ) ) {
V_53 -> V_112 ++ ;
goto V_117;
}
F_76 ( V_10 , & V_18 ) ;
V_110 = F_77 () % F_78 ( V_6 ) ;
V_71 = & V_6 -> V_71 [ V_110 ] ;
for ( V_28 = 0 ; V_28 < V_118 ; V_28 ++ ) {
V_82 = F_79 ( NULL , V_6 -> V_119 , 0 ,
V_71 -> V_120 , & V_18 ) ;
if ( V_82 != - V_121 )
break;
}
V_55 -> V_122 += V_28 ;
if ( F_18 ( V_82 < 0 ) ) {
V_53 -> V_123 ++ ;
F_67 ( V_6 , & V_18 , NULL ) ;
} else {
V_53 -> V_124 ++ ;
V_53 -> V_125 += V_9 -> V_94 ;
}
return V_114 ;
V_117:
V_113:
F_68 ( V_9 ) ;
return V_114 ;
}
static void F_80 ( struct V_5 * V_6 ,
struct V_35 * V_36 ,
const struct V_17 * V_18 ,
struct V_50 * V_51 V_126 )
{
struct V_52 * V_53 ;
struct V_54 * V_55 ;
T_3 V_59 = 0 ;
T_3 V_127 ;
bool V_128 = false ;
F_81 ( V_6 -> V_10 , V_18 ) ;
V_55 = F_32 ( V_6 -> V_55 ) ;
V_55 -> V_129 ++ ;
V_55 -> V_130 += F_15 ( V_18 ) ;
V_127 = F_82 ( V_18 ) & V_131 ;
if ( F_18 ( V_127 ) ) {
V_128 = ( V_127 & V_132 ) &&
! ! ( F_34 ( V_18 ) & V_65 ) ;
if ( F_83 () )
F_84 ( V_6 -> V_10 , L_1 ,
V_127 ) ;
}
F_67 ( V_6 , V_18 , V_128 ? & V_59 : NULL ) ;
if ( F_33 ( ! V_127 ) )
return;
V_53 = F_32 ( V_6 -> V_53 ) ;
V_53 -> V_123 ++ ;
if ( V_128 && F_83 () )
F_84 ( V_6 -> V_10 , L_2 ,
V_59 & V_133 ) ;
}
static int F_85 ( struct V_5 * V_6 , bool V_134 )
{
int V_82 ;
V_82 = F_86 ( V_6 -> V_135 , 0 , V_6 -> V_136 ,
V_137 , V_134 ) ;
if ( V_82 ) {
F_87 ( V_6 -> V_10 ,
L_3 ) ;
return V_82 ;
}
V_82 = F_86 ( V_6 -> V_135 , 0 , V_6 -> V_136 ,
V_138 , V_134 ) ;
if ( V_82 ) {
F_87 ( V_6 -> V_10 ,
L_4 ) ;
return V_82 ;
}
return 0 ;
}
static int F_88 ( struct V_5 * V_6 , bool V_134 )
{
int V_82 ;
V_82 = F_86 ( V_6 -> V_135 , 0 , V_6 -> V_136 ,
V_139 , V_134 ) ;
if ( V_82 ) {
F_87 ( V_6 -> V_10 , L_5 ) ;
return V_82 ;
}
V_82 = F_86 ( V_6 -> V_135 , 0 , V_6 -> V_136 ,
V_140 , V_134 ) ;
if ( V_82 ) {
F_87 ( V_6 -> V_10 , L_6 ) ;
return V_82 ;
}
return 0 ;
}
static int F_89 ( struct V_5 * V_6 , T_5 V_141 )
{
struct V_20 * V_21 = V_6 -> V_10 -> V_21 . V_22 ;
T_7 V_142 [ V_143 ] ;
void * V_144 ;
T_1 V_23 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_143 ; V_28 ++ ) {
V_144 = F_90 ( V_145 ) ;
if ( F_18 ( ! V_144 ) )
goto V_146;
V_144 = F_49 ( V_144 , V_147 ) ;
V_23 = F_56 ( V_21 , V_144 , V_33 ,
V_34 ) ;
if ( F_18 ( F_57 ( V_21 , V_23 ) ) )
goto V_148;
V_142 [ V_28 ] = V_23 ;
F_91 ( V_6 -> V_10 ,
V_144 , V_145 ,
V_23 , V_33 ,
V_141 ) ;
}
V_149:
while ( F_92 ( NULL , V_141 , V_142 , V_28 ) )
F_93 () ;
return V_28 ;
V_148:
F_12 ( V_144 ) ;
V_146:
if ( V_28 )
goto V_149;
return 0 ;
}
static int F_94 ( struct V_5 * V_6 , T_5 V_141 )
{
int V_28 , V_150 ;
int V_151 ;
F_95 () ;
for ( V_150 = 0 ; V_150 < V_6 -> V_152 ; V_150 ++ ) {
for ( V_28 = 0 ; V_28 < V_153 ;
V_28 += V_143 ) {
V_151 = F_89 ( V_6 , V_141 ) ;
V_6 -> V_154 [ V_150 ] -> V_41 += V_151 ;
if ( V_151 < V_143 ) {
F_96 () ;
return - V_93 ;
}
}
}
F_96 () ;
return 0 ;
}
static void F_97 ( struct V_5 * V_6 , int V_155 )
{
struct V_20 * V_21 = V_6 -> V_10 -> V_21 . V_22 ;
T_7 V_142 [ V_143 ] ;
void * V_19 ;
int V_156 , V_28 ;
do {
V_156 = F_98 ( NULL , V_6 -> V_141 ,
V_142 , V_155 ) ;
if ( V_156 < 0 ) {
F_87 ( V_6 -> V_10 , L_7 ) ;
return;
}
for ( V_28 = 0 ; V_28 < V_156 ; V_28 ++ ) {
V_19 = F_1 ( V_6 -> V_1 ,
V_142 [ V_28 ] ) ;
F_11 ( V_21 , V_142 [ V_28 ] ,
V_33 ,
V_34 ) ;
F_12 ( V_19 ) ;
}
} while ( V_156 );
}
static void F_99 ( struct V_5 * V_6 )
{
int V_28 ;
F_97 ( V_6 , V_143 ) ;
F_97 ( V_6 , 1 ) ;
for ( V_28 = 0 ; V_28 < V_6 -> V_152 ; V_28 ++ )
V_6 -> V_154 [ V_28 ] -> V_41 = 0 ;
}
static int F_100 ( struct V_5 * V_6 ,
struct V_35 * V_36 ,
T_5 V_141 )
{
int V_151 ;
if ( F_33 ( V_36 -> V_41 >= V_157 ) )
return 0 ;
do {
V_151 = F_89 ( V_6 , V_141 ) ;
if ( F_18 ( ! V_151 ) ) {
break;
}
V_36 -> V_41 += V_151 ;
} while ( V_36 -> V_41 < V_153 );
if ( F_18 ( V_36 -> V_41 < V_153 ) )
return - V_93 ;
return 0 ;
}
static int F_101 ( struct V_35 * V_36 )
{
int V_82 ;
int V_158 = - 1 ;
do {
V_82 = F_102 ( NULL , V_36 -> V_159 , V_36 -> V_76 ) ;
V_158 ++ ;
F_93 () ;
} while ( V_82 == - V_121 );
V_36 -> V_77 . V_160 += V_158 ;
if ( F_18 ( V_82 ) )
V_36 -> V_77 . V_161 ++ ;
return V_82 ;
}
static int F_103 ( struct V_50 * V_51 , int V_162 )
{
struct V_35 * V_36 ;
int V_74 = 0 , V_163 ;
struct V_5 * V_6 ;
int V_82 ;
V_36 = F_104 ( V_51 , struct V_35 , V_51 ) ;
V_6 = V_36 -> V_6 ;
while ( V_74 < V_162 ) {
V_82 = F_101 ( V_36 ) ;
if ( F_18 ( V_82 ) )
break;
F_100 ( V_6 , V_36 , V_6 -> V_141 ) ;
V_163 = F_38 ( V_36 ) ;
V_74 += V_163 ;
if ( V_163 == 0 ||
V_74 > V_162 - V_164 )
break;
}
if ( V_74 < V_162 ) {
F_105 ( V_51 , V_74 ) ;
do {
V_82 = F_106 ( NULL , & V_36 -> V_165 ) ;
F_93 () ;
} while ( V_82 == - V_121 );
}
V_36 -> V_77 . V_78 += V_74 ;
return V_74 ;
}
static void F_107 ( struct V_5 * V_6 )
{
struct V_35 * V_36 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_6 -> V_152 ; V_28 ++ ) {
V_36 = V_6 -> V_154 [ V_28 ] ;
F_108 ( & V_36 -> V_51 ) ;
}
}
static void F_109 ( struct V_5 * V_6 )
{
struct V_35 * V_36 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_6 -> V_152 ; V_28 ++ ) {
V_36 = V_6 -> V_154 [ V_28 ] ;
F_110 ( & V_36 -> V_51 ) ;
}
}
static int F_111 ( struct V_5 * V_6 )
{
struct V_166 V_167 ;
int V_82 ;
V_82 = F_112 ( V_6 -> V_135 , 0 , V_6 -> V_136 , & V_167 ) ;
if ( F_18 ( V_82 ) ) {
F_87 ( V_6 -> V_10 ,
L_8 ) ;
return V_82 ;
}
if ( V_6 -> V_168 . V_169 == V_167 . V_169 )
return 0 ;
V_6 -> V_168 = V_167 ;
if ( V_167 . V_169 ) {
F_113 ( V_6 -> V_10 ) ;
F_114 ( V_6 -> V_10 ) ;
} else {
F_115 ( V_6 -> V_10 ) ;
F_116 ( V_6 -> V_10 ) ;
}
F_117 ( V_6 -> V_10 , L_9 ,
V_167 . V_169 ? L_10 : L_11 ) ;
return 0 ;
}
static int F_118 ( struct V_109 * V_10 )
{
struct V_5 * V_6 = F_70 ( V_10 ) ;
int V_82 ;
V_82 = F_94 ( V_6 , V_6 -> V_141 ) ;
if ( V_82 ) {
F_87 ( V_10 , L_12 ,
V_6 -> V_170 -> V_171 . V_172 , V_6 -> V_141 ) ;
}
F_115 ( V_10 ) ;
F_107 ( V_6 ) ;
F_116 ( V_10 ) ;
V_82 = F_119 ( V_6 -> V_135 , 0 , V_6 -> V_136 ) ;
if ( V_82 < 0 ) {
F_87 ( V_10 , L_13 ) ;
goto V_173;
}
V_82 = F_111 ( V_6 ) ;
if ( V_82 < 0 ) {
F_87 ( V_10 , L_14 ) ;
goto V_174;
}
return 0 ;
V_174:
V_173:
F_109 ( V_6 ) ;
F_99 ( V_6 ) ;
return V_82 ;
}
static T_3 F_120 ( struct V_5 * V_6 ,
struct V_35 * V_36 )
{
T_3 V_175 = 0 , V_176 = 0 ;
do {
F_101 ( V_36 ) ;
V_175 = F_38 ( V_36 ) ;
V_176 += V_175 ;
} while ( V_175 );
return V_176 ;
}
static T_3 F_121 ( struct V_5 * V_6 )
{
struct V_35 * V_36 ;
int V_28 ;
T_3 V_175 = 0 ;
for ( V_28 = 0 ; V_28 < V_6 -> V_152 ; V_28 ++ ) {
V_36 = V_6 -> V_154 [ V_28 ] ;
V_175 += F_120 ( V_6 , V_36 ) ;
}
return V_175 ;
}
static int F_122 ( struct V_109 * V_10 )
{
struct V_5 * V_6 = F_70 ( V_10 ) ;
int V_177 ;
int V_178 = 10 ;
T_3 V_175 ;
F_115 ( V_10 ) ;
F_116 ( V_10 ) ;
do {
F_123 ( V_6 -> V_135 , 0 , V_6 -> V_136 ) ;
F_124 ( V_6 -> V_135 , 0 , V_6 -> V_136 , & V_177 ) ;
if ( V_177 )
F_125 ( 100 ) ;
} while ( V_177 && -- V_178 );
if ( ! V_178 ) {
F_126 ( V_10 , L_15 ) ;
}
F_109 ( V_6 ) ;
V_175 = F_121 ( V_6 ) ;
if ( V_175 )
F_84 ( V_10 , L_16 , V_175 ) ;
F_99 ( V_6 ) ;
return 0 ;
}
static int F_127 ( struct V_109 * V_10 )
{
T_7 V_179 = 0 ;
T_7 V_180 = 0 ;
struct V_5 * V_6 = F_70 ( V_10 ) ;
T_3 V_181 = V_6 -> V_182 . V_181 ;
V_179 |= V_183 ;
if ( V_181 & V_184 )
V_180 |= V_185 ;
else
V_179 |= V_185 ;
V_10 -> V_186 |= V_179 ;
V_10 -> V_186 &= ~ V_180 ;
V_10 -> V_11 = V_12 |
V_187 | V_188 |
V_189 | V_190 |
V_191 ;
V_10 -> V_192 = V_10 -> V_11 ;
return 0 ;
}
static int F_128 ( struct V_109 * V_10 , void * V_23 )
{
struct V_5 * V_6 = F_70 ( V_10 ) ;
struct V_20 * V_21 = V_10 -> V_21 . V_22 ;
int V_82 ;
V_82 = F_129 ( V_10 , V_23 ) ;
if ( V_82 < 0 ) {
F_130 ( V_21 , L_17 , V_82 ) ;
return V_82 ;
}
V_82 = F_131 ( V_6 -> V_135 , 0 , V_6 -> V_136 ,
V_10 -> V_193 ) ;
if ( V_82 ) {
F_130 ( V_21 , L_18 , V_82 ) ;
return V_82 ;
}
return 0 ;
}
static void F_132 ( struct V_109 * V_10 ,
struct V_52 * V_77 )
{
struct V_5 * V_6 = F_70 ( V_10 ) ;
struct V_52 * V_53 ;
T_7 * V_194 ;
T_7 * V_195 = ( T_7 * ) V_77 ;
int V_28 , V_150 ;
int V_196 = sizeof( struct V_52 ) / sizeof( T_7 ) ;
F_133 (i) {
V_53 = F_134 ( V_6 -> V_53 , V_28 ) ;
V_194 = ( T_7 * ) V_53 ;
for ( V_150 = 0 ; V_150 < V_196 ; V_150 ++ )
V_195 [ V_150 ] += V_194 [ V_150 ] ;
}
}
static int F_135 ( struct V_109 * V_10 , int V_197 )
{
struct V_5 * V_6 = F_70 ( V_10 ) ;
int V_82 ;
V_82 = F_136 ( V_6 -> V_135 , 0 , V_6 -> V_136 ,
( T_5 ) F_137 ( V_197 ) ) ;
if ( V_82 ) {
F_87 ( V_10 , L_19 ) ;
return V_82 ;
}
V_10 -> V_197 = V_197 ;
return 0 ;
}
static void F_138 ( const struct V_109 * V_10 ,
struct V_5 * V_6 )
{
struct V_198 * V_199 ;
int V_82 ;
F_139 (ha, net_dev) {
V_82 = F_140 ( V_6 -> V_135 , 0 , V_6 -> V_136 ,
V_199 -> V_23 ) ;
if ( V_82 )
F_126 ( V_6 -> V_10 ,
L_20 ,
V_199 -> V_23 , V_82 ) ;
}
}
static void F_141 ( const struct V_109 * V_10 ,
struct V_5 * V_6 )
{
struct V_198 * V_199 ;
int V_82 ;
F_142 (ha, net_dev) {
V_82 = F_140 ( V_6 -> V_135 , 0 , V_6 -> V_136 ,
V_199 -> V_23 ) ;
if ( V_82 )
F_126 ( V_6 -> V_10 ,
L_21 ,
V_199 -> V_23 , V_82 ) ;
}
}
static void F_143 ( struct V_109 * V_10 )
{
struct V_5 * V_6 = F_70 ( V_10 ) ;
int V_200 = F_144 ( V_10 ) ;
int V_201 = F_145 ( V_10 ) ;
T_4 V_202 = V_6 -> V_182 . V_203 ;
T_3 V_181 = V_6 -> V_182 . V_181 ;
T_5 V_136 = V_6 -> V_136 ;
struct V_204 * V_135 = V_6 -> V_135 ;
int V_82 ;
if ( V_181 & V_184 && V_202 != 0 )
F_117 ( V_10 ,
L_22 ,
V_202 ) ;
if ( V_200 > V_202 ) {
F_117 ( V_10 ,
L_23 ,
V_200 , V_202 ) ;
goto V_205;
}
if ( V_201 + V_200 > V_202 ) {
F_117 ( V_10 ,
L_24 ,
V_200 + V_201 , V_202 ) ;
goto V_206;
}
if ( V_10 -> V_207 & V_208 )
goto V_205;
if ( V_10 -> V_207 & V_209 ) {
V_82 = F_146 ( V_135 , 0 , V_136 , 1 ) ;
if ( V_82 )
F_126 ( V_10 , L_25 ) ;
V_82 = F_147 ( V_135 , 0 , V_136 , 1 , 0 ) ;
if ( V_82 )
F_126 ( V_10 , L_26 ) ;
F_138 ( V_10 , V_6 ) ;
V_82 = F_146 ( V_135 , 0 , V_136 , 0 ) ;
if ( V_82 )
F_126 ( V_10 , L_27 ) ;
goto V_206;
}
V_82 = F_146 ( V_135 , 0 , V_136 , 1 ) ;
if ( V_82 )
F_126 ( V_10 , L_28 , V_82 ) ;
V_82 = F_148 ( V_135 , 0 , V_136 , 1 ) ;
if ( V_82 )
F_126 ( V_10 , L_29 , V_82 ) ;
V_82 = F_147 ( V_135 , 0 , V_136 , 1 , 1 ) ;
if ( V_82 )
F_126 ( V_10 , L_30 ) ;
F_141 ( V_10 , V_6 ) ;
F_138 ( V_10 , V_6 ) ;
V_82 = F_146 ( V_135 , 0 , V_136 , 0 ) ;
if ( V_82 )
F_126 ( V_10 , L_31 ) ;
V_82 = F_148 ( V_135 , 0 , V_136 , 0 ) ;
if ( V_82 )
F_126 ( V_10 , L_32 ) ;
return;
V_205:
V_82 = F_146 ( V_135 , 0 , V_136 , 1 ) ;
if ( V_82 )
F_126 ( V_10 , L_33 ) ;
V_206:
V_82 = F_148 ( V_135 , 0 , V_136 , 1 ) ;
if ( V_82 )
F_126 ( V_10 , L_34 ) ;
}
static int F_149 ( struct V_109 * V_10 ,
T_8 V_11 )
{
struct V_5 * V_6 = F_70 ( V_10 ) ;
T_8 V_210 = V_11 ^ V_10 -> V_11 ;
bool V_134 ;
int V_82 ;
if ( V_210 & V_12 ) {
V_134 = ! ! ( V_11 & V_12 ) ;
V_82 = F_85 ( V_6 , V_134 ) ;
if ( V_82 )
return V_82 ;
}
if ( V_210 & ( V_187 | V_188 ) ) {
V_134 = ! ! ( V_11 & ( V_187 | V_188 ) ) ;
V_82 = F_88 ( V_6 , V_134 ) ;
if ( V_82 )
return V_82 ;
}
return 0 ;
}
static void F_150 ( struct V_211 * V_212 )
{
struct V_35 * V_36 ;
V_36 = F_104 ( V_212 , struct V_35 , V_165 ) ;
V_36 -> V_77 . V_213 ++ ;
F_151 ( & V_36 -> V_51 ) ;
}
static struct V_214 * F_152 ( struct V_5 * V_6 )
{
struct V_214 * V_215 ;
struct V_20 * V_21 = V_6 -> V_10 -> V_21 . V_22 ;
struct V_216 V_217 ;
int V_82 ;
V_82 = F_153 ( F_154 ( V_21 ) ,
V_218 , & V_215 ) ;
if ( V_82 ) {
F_155 ( V_21 , L_35 ) ;
return NULL ;
}
V_82 = F_156 ( V_6 -> V_135 , 0 , V_215 -> V_171 . V_172 , & V_215 -> V_219 ) ;
if ( V_82 ) {
F_130 ( V_21 , L_36 ) ;
goto V_220;
}
V_82 = F_157 ( V_6 -> V_135 , 0 , V_215 -> V_219 ) ;
if ( V_82 ) {
F_130 ( V_21 , L_37 ) ;
goto V_221;
}
V_82 = F_158 ( V_6 -> V_135 , 0 , V_215 -> V_219 , & V_217 ) ;
if ( V_82 ) {
F_130 ( V_21 , L_38 ) ;
goto V_222;
}
V_82 = F_159 ( V_6 -> V_135 , 0 , V_215 -> V_219 ) ;
if ( V_82 ) {
F_130 ( V_21 , L_39 ) ;
goto V_223;
}
return V_215 ;
V_223:
V_222:
V_221:
F_160 ( V_6 -> V_135 , 0 , V_215 -> V_219 ) ;
V_220:
F_161 ( V_215 ) ;
return NULL ;
}
static void F_162 ( struct V_5 * V_6 ,
struct V_214 * V_215 )
{
F_163 ( V_6 -> V_135 , 0 , V_215 -> V_219 ) ;
F_160 ( V_6 -> V_135 , 0 , V_215 -> V_219 ) ;
F_161 ( V_215 ) ;
}
static struct V_35 *
F_164 ( struct V_5 * V_6 )
{
struct V_35 * V_154 ;
struct V_216 V_224 ;
struct V_20 * V_21 = V_6 -> V_10 -> V_21 . V_22 ;
int V_82 ;
V_154 = F_48 ( sizeof( * V_154 ) , V_225 ) ;
if ( ! V_154 )
return NULL ;
V_154 -> V_215 = F_152 ( V_6 ) ;
if ( ! V_154 -> V_215 )
goto V_226;
V_82 = F_158 ( V_6 -> V_135 , 0 , V_154 -> V_215 -> V_219 ,
& V_224 ) ;
if ( V_82 ) {
F_130 ( V_21 , L_38 ) ;
goto V_222;
}
V_154 -> V_227 = V_224 . V_172 ;
V_154 -> V_159 = V_224 . V_228 ;
V_154 -> V_6 = V_6 ;
return V_154 ;
V_222:
F_162 ( V_6 , V_154 -> V_215 ) ;
V_226:
F_63 ( V_154 ) ;
return NULL ;
}
static void F_165 ( struct V_5 * V_6 ,
struct V_35 * V_154 )
{
F_162 ( V_6 , V_154 -> V_215 ) ;
F_63 ( V_154 ) ;
}
static int F_166 ( struct V_5 * V_6 )
{
struct V_211 * V_165 ;
struct V_35 * V_154 ;
struct V_229 V_230 ;
struct V_20 * V_21 = V_6 -> V_10 -> V_21 . V_22 ;
int V_28 , V_82 ;
F_167 ( & V_6 -> V_231 ) ;
F_168 (i) {
V_154 = F_164 ( V_6 ) ;
if ( ! V_154 ) {
F_155 ( V_21 ,
L_40 , V_28 ) ;
V_82 = - V_232 ;
goto V_233;
}
V_6 -> V_154 [ V_6 -> V_152 ] = V_154 ;
V_165 = & V_154 -> V_165 ;
V_165 -> V_234 = 1 ;
V_165 -> V_235 = F_150 ;
V_165 -> V_172 = V_154 -> V_159 ;
V_165 -> V_236 = V_28 ;
V_82 = F_169 ( NULL , V_165 ) ;
if ( V_82 ) {
F_170 ( V_21 , L_41 , V_28 ) ;
V_82 = - V_237 ;
goto V_238;
}
V_230 . V_239 = V_165 -> V_239 ;
V_230 . V_240 = 0 ;
V_230 . V_241 = V_165 -> V_242 ;
V_82 = F_171 ( V_6 -> V_135 , 0 ,
V_154 -> V_215 -> V_219 ,
& V_230 ) ;
if ( V_82 ) {
F_130 ( V_21 , L_42 ) ;
goto V_243;
}
F_172 ( V_28 , & V_6 -> V_231 ) ;
V_6 -> V_152 ++ ;
if ( V_6 -> V_152 == F_78 ( V_6 ) )
break;
}
return 0 ;
V_243:
F_173 ( NULL , V_165 ) ;
V_238:
F_165 ( V_6 , V_154 ) ;
V_233:
if ( F_174 ( & V_6 -> V_231 ) ) {
F_130 ( V_21 , L_43 ) ;
return V_82 ;
}
F_155 ( V_21 , L_44 ,
F_175 ( & V_6 -> V_231 ) ) ;
return 0 ;
}
static void F_176 ( struct V_5 * V_6 )
{
int V_28 ;
struct V_35 * V_36 ;
for ( V_28 = 0 ; V_28 < V_6 -> V_152 ; V_28 ++ ) {
V_36 = V_6 -> V_154 [ V_28 ] ;
F_173 ( NULL , & V_36 -> V_165 ) ;
F_165 ( V_6 , V_36 ) ;
}
}
static struct V_35 * F_177 ( struct V_5 * V_6 ,
int V_244 )
{
struct V_20 * V_21 = V_6 -> V_10 -> V_21 . V_22 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_6 -> V_152 ; V_28 ++ )
if ( V_6 -> V_154 [ V_28 ] -> V_165 . V_236 == V_244 )
return V_6 -> V_154 [ V_28 ] ;
F_178 ( V_21 , L_45 , V_244 ) ;
return V_6 -> V_154 [ 0 ] ;
}
static void F_179 ( struct V_5 * V_6 )
{
struct V_20 * V_21 = V_6 -> V_10 -> V_21 . V_22 ;
struct V_70 * V_71 ;
int V_245 , V_246 ;
int V_28 ;
V_245 = V_246 = F_180 ( & V_6 -> V_231 ) ;
for ( V_28 = 0 ; V_28 < V_6 -> V_247 ; V_28 ++ ) {
V_71 = & V_6 -> V_71 [ V_28 ] ;
switch ( V_71 -> type ) {
case V_248 :
V_71 -> V_249 = V_245 ;
V_245 = F_181 ( V_245 , & V_6 -> V_231 ) ;
if ( V_245 >= V_250 )
V_245 = F_180 ( & V_6 -> V_231 ) ;
break;
case V_251 :
V_71 -> V_249 = V_246 ;
V_246 = F_181 ( V_246 , & V_6 -> V_231 ) ;
if ( V_246 >= V_250 )
V_246 = F_180 ( & V_6 -> V_231 ) ;
break;
default:
F_130 ( V_21 , L_46 , V_71 -> type ) ;
}
V_71 -> V_154 = F_177 ( V_6 , V_71 -> V_249 ) ;
}
}
static void F_182 ( struct V_5 * V_6 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < F_78 ( V_6 ) ; V_28 ++ ) {
V_6 -> V_71 [ V_6 -> V_247 ] . type = V_251 ;
V_6 -> V_71 [ V_6 -> V_247 ] . V_79 = F_80 ;
V_6 -> V_71 [ V_6 -> V_247 ++ ] . V_252 = ( T_5 ) V_28 ;
}
for ( V_28 = 0 ; V_28 < F_78 ( V_6 ) ; V_28 ++ ) {
V_6 -> V_71 [ V_6 -> V_247 ] . type = V_248 ;
V_6 -> V_71 [ V_6 -> V_247 ] . V_79 = F_28 ;
V_6 -> V_71 [ V_6 -> V_247 ++ ] . V_252 = ( T_5 ) V_28 ;
}
F_179 ( V_6 ) ;
}
static int F_183 ( struct V_5 * V_6 )
{
int V_82 ;
struct V_214 * V_170 ;
struct V_20 * V_21 = V_6 -> V_10 -> V_21 . V_22 ;
struct V_253 V_254 ;
V_82 = F_153 ( F_154 ( V_21 ) , V_255 ,
& V_170 ) ;
if ( V_82 ) {
F_130 ( V_21 , L_47 ) ;
return V_82 ;
}
V_6 -> V_170 = V_170 ;
V_82 = F_184 ( V_6 -> V_135 , 0 , V_6 -> V_170 -> V_171 . V_172 ,
& V_170 -> V_219 ) ;
if ( V_82 ) {
F_130 ( V_21 , L_48 ) ;
goto V_220;
}
V_82 = F_185 ( V_6 -> V_135 , 0 , V_170 -> V_219 ) ;
if ( V_82 ) {
F_130 ( V_21 , L_49 ) ;
goto V_221;
}
V_82 = F_186 ( V_6 -> V_135 , 0 , V_170 -> V_219 ) ;
if ( V_82 ) {
F_130 ( V_21 , L_50 ) ;
goto V_223;
}
V_82 = F_187 ( V_6 -> V_135 , 0 , V_170 -> V_219 ,
& V_254 ) ;
if ( V_82 ) {
F_130 ( V_21 , L_51 ) ;
goto V_222;
}
V_6 -> V_141 = V_254 . V_141 ;
return 0 ;
V_222:
F_188 ( V_6 -> V_135 , 0 , V_170 -> V_219 ) ;
V_223:
V_221:
F_189 ( V_6 -> V_135 , 0 , V_170 -> V_219 ) ;
V_220:
F_161 ( V_170 ) ;
return V_82 ;
}
static void F_190 ( struct V_5 * V_6 )
{
F_99 ( V_6 ) ;
F_188 ( V_6 -> V_135 , 0 , V_6 -> V_170 -> V_219 ) ;
F_189 ( V_6 -> V_135 , 0 , V_6 -> V_170 -> V_219 ) ;
F_161 ( V_6 -> V_170 ) ;
}
static int F_191 ( struct V_214 * V_256 )
{
struct V_20 * V_21 = & V_256 -> V_21 ;
struct V_5 * V_6 ;
struct V_109 * V_10 ;
struct V_257 V_258 = { 0 } ;
int V_82 ;
V_10 = F_192 ( V_21 ) ;
V_6 = F_70 ( V_10 ) ;
V_82 = F_193 ( V_6 -> V_135 , 0 , V_256 -> V_171 . V_172 , & V_6 -> V_136 ) ;
if ( V_82 ) {
F_130 ( V_21 , L_52 ) ;
goto V_220;
}
V_256 -> V_135 = V_6 -> V_135 ;
V_256 -> V_219 = V_6 -> V_136 ;
V_82 = F_194 ( V_6 -> V_135 , 0 , V_6 -> V_136 ) ;
if ( V_82 ) {
F_130 ( V_21 , L_53 ) ;
goto V_221;
}
V_82 = F_195 ( V_6 -> V_135 , 0 , V_6 -> V_136 ,
& V_6 -> V_182 ) ;
if ( V_82 ) {
F_130 ( V_21 , L_54 , V_82 ) ;
goto V_222;
}
V_258 . V_259 = true ;
V_258 . V_260 = true ;
V_258 . V_261 = V_262 ;
V_258 . V_263 = V_147 ;
V_258 . V_181 = V_264 |
V_265 |
V_266 |
V_267 ;
V_82 = F_196 ( V_6 -> V_135 , 0 , V_6 -> V_136 ,
V_268 , & V_258 ) ;
if ( V_82 ) {
F_130 ( V_21 , L_55 ) ;
goto V_269;
}
V_258 . V_181 = V_265 |
V_266 ;
V_82 = F_196 ( V_6 -> V_135 , 0 , V_6 -> V_136 ,
V_270 , & V_258 ) ;
if ( V_82 ) {
F_130 ( V_21 , L_56 ) ;
goto V_269;
}
V_258 . V_181 = V_265 ;
V_82 = F_196 ( V_6 -> V_135 , 0 , V_6 -> V_136 ,
V_271 , & V_258 ) ;
if ( V_82 ) {
F_130 ( V_21 , L_57 ) ;
goto V_269;
}
V_82 = F_197 ( V_6 -> V_135 , 0 , V_6 -> V_136 ,
& V_6 -> V_97 ) ;
if ( V_82 ) {
F_130 ( V_21 , L_58 ) ;
goto V_272;
}
if ( ( V_6 -> V_97 % 64 ) != 0 )
F_178 ( V_21 , L_59 ,
V_6 -> V_97 ) ;
V_6 -> V_97 += V_262 ;
return 0 ;
V_272:
V_269:
V_222:
V_221:
F_198 ( V_6 -> V_135 , 0 , V_6 -> V_136 ) ;
V_220:
return V_82 ;
}
static void F_199 ( struct V_5 * V_6 )
{
int V_82 ;
V_82 = F_194 ( V_6 -> V_135 , 0 , V_6 -> V_136 ) ;
if ( V_82 )
F_126 ( V_6 -> V_10 , L_60 ,
V_82 ) ;
F_198 ( V_6 -> V_135 , 0 , V_6 -> V_136 ) ;
}
static int F_200 ( struct V_5 * V_6 ,
struct V_70 * V_71 )
{
struct V_20 * V_21 = V_6 -> V_10 -> V_21 . V_22 ;
struct V_273 V_274 ;
struct V_275 V_276 ;
struct V_277 V_278 ;
int V_82 ;
V_82 = F_201 ( V_6 -> V_135 , 0 , V_6 -> V_136 ,
V_268 , 0 , V_71 -> V_252 , & V_274 , & V_276 ) ;
if ( V_82 ) {
F_130 ( V_21 , L_61 ) ;
return V_82 ;
}
V_71 -> V_279 = V_276 . V_279 ;
V_274 . V_280 . V_172 = V_71 -> V_154 -> V_227 ;
V_274 . V_280 . type = V_281 ;
V_274 . V_280 . V_240 = 1 ;
V_274 . V_282 = ( T_7 ) V_71 ;
V_82 = F_202 ( V_6 -> V_135 , 0 , V_6 -> V_136 ,
V_268 , 0 , V_71 -> V_252 ,
V_283 | V_284 ,
& V_274 ) ;
if ( V_82 ) {
F_130 ( V_21 , L_62 ) ;
return V_82 ;
}
V_278 . V_134 = 1 ;
V_278 . V_285 = V_286 ;
V_82 = F_203 ( V_6 -> V_135 , 0 , V_6 -> V_136 , V_287 ,
V_268 , 0 , V_71 -> V_252 , & V_278 ) ;
if ( V_82 ) {
F_130 ( V_21 , L_63 ) ;
return V_82 ;
}
return 0 ;
}
static int F_204 ( struct V_5 * V_6 ,
struct V_70 * V_71 )
{
struct V_20 * V_21 = V_6 -> V_10 -> V_21 . V_22 ;
struct V_273 V_274 ;
struct V_275 V_276 ;
int V_82 ;
V_82 = F_201 ( V_6 -> V_135 , 0 , V_6 -> V_136 ,
V_270 , 0 , V_71 -> V_252 , & V_274 , & V_276 ) ;
if ( V_82 ) {
F_130 ( V_21 , L_64 ) ;
return V_82 ;
}
V_71 -> V_120 = V_276 . V_288 ;
V_82 = F_201 ( V_6 -> V_135 , 0 , V_6 -> V_136 ,
V_271 , 0 , V_71 -> V_252 ,
& V_274 , & V_276 ) ;
if ( V_82 ) {
F_130 ( V_21 , L_65 ) ;
return V_82 ;
}
V_71 -> V_279 = V_276 . V_279 ;
V_274 . V_280 . V_172 = V_71 -> V_154 -> V_227 ;
V_274 . V_280 . type = V_281 ;
V_274 . V_280 . V_240 = 0 ;
V_274 . V_282 = ( T_7 ) V_71 ;
V_82 = F_202 ( V_6 -> V_135 , 0 , V_6 -> V_136 ,
V_271 , 0 , V_71 -> V_252 ,
V_283 | V_284 ,
& V_274 ) ;
if ( V_82 ) {
F_130 ( V_21 , L_66 ) ;
return V_82 ;
}
return 0 ;
}
static int F_205 ( struct V_109 * V_10 , T_7 V_207 )
{
struct V_20 * V_21 = V_10 -> V_21 . V_22 ;
struct V_5 * V_6 = F_70 ( V_10 ) ;
struct V_289 V_290 ;
struct V_291 V_292 ;
T_4 * V_293 ;
int V_28 ;
int V_82 = 0 ;
if ( ! F_206 ( V_6 ) ) {
F_170 ( V_21 , L_67 ) ;
return 0 ;
}
memset ( & V_290 , 0 , sizeof( V_290 ) ) ;
for ( V_28 = 0 ; V_28 < F_207 ( V_294 ) ; V_28 ++ ) {
struct V_295 * V_296 =
& V_290 . V_297 [ V_290 . V_298 ] ;
if ( ! ( V_207 & V_294 [ V_28 ] . V_299 ) )
continue;
if ( V_290 . V_298 >= V_300 ) {
F_130 ( V_21 , L_68 ) ;
return - V_301 ;
}
V_296 -> type = V_302 ;
V_296 -> V_303 . V_304 . V_305 = V_294 [ V_28 ] . V_306 ;
V_296 -> V_303 . V_304 . type = V_307 ;
V_296 -> V_303 . V_304 . V_308 = V_294 [ V_28 ] . V_309 ;
V_290 . V_298 ++ ;
V_6 -> V_310 |= V_294 [ V_28 ] . V_299 ;
}
V_293 = F_48 ( V_311 , V_225 ) ;
if ( ! V_293 )
return - V_93 ;
V_82 = F_208 ( & V_290 , V_293 ) ;
if ( V_82 ) {
F_130 ( V_21 , L_69 , V_82 ) ;
goto V_312;
}
memset ( & V_292 , 0 , sizeof( V_292 ) ) ;
V_292 . V_313 = F_56 ( V_21 , V_293 ,
V_311 ,
V_314 ) ;
if ( F_57 ( V_21 , V_292 . V_313 ) ) {
F_130 ( V_21 , L_70 ) ;
V_82 = - V_93 ;
goto V_315;
}
V_292 . V_316 = F_78 ( V_6 ) ;
V_292 . V_317 = V_318 ;
V_82 = F_209 ( V_6 -> V_135 , 0 , V_6 -> V_136 , 0 , & V_292 ) ;
F_11 ( V_21 , V_292 . V_313 ,
V_311 , V_314 ) ;
if ( V_82 )
F_130 ( V_21 , L_71 , V_82 ) ;
V_315:
V_312:
F_63 ( V_293 ) ;
return V_82 ;
}
static int F_210 ( struct V_5 * V_6 )
{
struct V_109 * V_10 = V_6 -> V_10 ;
struct V_20 * V_21 = V_10 -> V_21 . V_22 ;
struct V_319 V_320 ;
struct V_321 V_322 ;
int V_82 = 0 ;
int V_28 ;
V_320 . V_323 = 1 ;
V_320 . V_324 [ 0 ] . V_325 = V_6 -> V_170 -> V_171 . V_172 ;
V_320 . V_324 [ 0 ] . V_326 = 0 ;
V_320 . V_324 [ 0 ] . V_327 = V_33 ;
V_82 = F_211 ( V_6 -> V_135 , 0 , V_6 -> V_136 , & V_320 ) ;
if ( V_82 ) {
F_130 ( V_21 , L_72 ) ;
return V_82 ;
}
V_82 = F_205 ( V_10 , V_328 ) ;
if ( V_82 )
F_87 ( V_10 , L_73 ) ;
V_322 . V_329 = V_330 ;
V_322 . V_331 = 1 ;
V_322 . V_332 = V_333 ;
V_82 = F_212 ( V_6 -> V_135 , 0 , V_6 -> V_136 ,
& V_322 ) ;
if ( V_82 ) {
F_130 ( V_21 , L_74 ) ;
return V_82 ;
}
for ( V_28 = 0 ; V_28 < V_6 -> V_247 ; V_28 ++ ) {
switch ( V_6 -> V_71 [ V_28 ] . type ) {
case V_248 :
V_82 = F_200 ( V_6 , & V_6 -> V_71 [ V_28 ] ) ;
break;
case V_251 :
V_82 = F_204 ( V_6 , & V_6 -> V_71 [ V_28 ] ) ;
break;
default:
F_130 ( V_21 , L_75 , V_6 -> V_71 [ V_28 ] . type ) ;
return - V_91 ;
}
if ( V_82 )
return V_82 ;
}
V_82 = F_213 ( V_6 -> V_135 , 0 , V_6 -> V_136 ,
V_270 , & V_6 -> V_119 ) ;
if ( V_82 ) {
F_130 ( V_21 , L_76 ) ;
return V_82 ;
}
return 0 ;
}
static int F_214 ( struct V_5 * V_6 )
{
struct V_109 * V_10 = V_6 -> V_10 ;
struct V_20 * V_21 = V_10 -> V_21 . V_22 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_6 -> V_152 ; V_28 ++ ) {
V_6 -> V_154 [ V_28 ] -> V_76 =
F_215 ( V_164 , V_21 ) ;
if ( ! V_6 -> V_154 [ V_28 ] -> V_76 ) {
F_87 ( V_10 , L_77 ) ;
goto V_334;
}
}
return 0 ;
V_334:
for ( V_28 = 0 ; V_28 < V_6 -> V_152 ; V_28 ++ ) {
if ( ! V_6 -> V_154 [ V_28 ] -> V_76 )
break;
F_216 ( V_6 -> V_154 [ V_28 ] -> V_76 ) ;
}
return - V_93 ;
}
static void F_217 ( struct V_5 * V_6 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_6 -> V_152 ; V_28 ++ )
F_216 ( V_6 -> V_154 [ V_28 ] -> V_76 ) ;
}
static int F_218 ( struct V_5 * V_6 )
{
struct V_109 * V_10 = V_6 -> V_10 ;
struct V_20 * V_21 = V_10 -> V_21 . V_22 ;
T_4 V_335 [ V_336 ] , V_337 [ V_336 ] ;
int V_82 ;
V_82 = F_219 ( V_6 -> V_135 , 0 , V_6 -> V_136 , V_335 ) ;
if ( V_82 ) {
F_130 ( V_21 , L_78 ) ;
return V_82 ;
}
V_82 = F_220 ( V_6 -> V_135 , 0 , V_6 -> V_136 ,
V_337 ) ;
if ( V_82 ) {
F_130 ( V_21 , L_79 ) ;
return V_82 ;
}
if ( ! F_221 ( V_335 ) ) {
if ( ! F_222 ( V_335 , V_337 ) ) {
V_82 = F_131 ( V_6 -> V_135 , 0 ,
V_6 -> V_136 ,
V_335 ) ;
if ( V_82 ) {
F_130 ( V_21 , L_80 ) ;
return V_82 ;
}
}
memcpy ( V_10 -> V_193 , V_335 , V_10 -> V_338 ) ;
} else if ( F_221 ( V_337 ) ) {
F_223 ( V_10 ) ;
F_224 ( V_21 , L_81 ) ;
V_82 = F_131 ( V_6 -> V_135 , 0 , V_6 -> V_136 ,
V_10 -> V_193 ) ;
if ( V_82 ) {
F_130 ( V_21 , L_80 ) ;
return V_82 ;
}
V_10 -> V_339 = V_340 ;
} else {
memcpy ( V_10 -> V_193 , V_337 , V_10 -> V_338 ) ;
}
return 0 ;
}
static int F_225 ( struct V_109 * V_10 )
{
struct V_20 * V_21 = V_10 -> V_21 . V_22 ;
struct V_5 * V_6 = F_70 ( V_10 ) ;
T_4 V_341 [ V_336 ] ;
T_4 V_342 ;
int V_82 ;
V_10 -> V_343 = & V_344 ;
V_82 = F_218 ( V_6 ) ;
if ( V_82 )
return V_82 ;
F_226 ( V_341 ) ;
V_82 = F_140 ( V_6 -> V_135 , 0 , V_6 -> V_136 , V_341 ) ;
if ( V_82 ) {
F_130 ( V_21 , L_82 ) ;
return V_82 ;
}
V_10 -> V_345 = F_72 ( V_6 ) ;
V_10 -> V_346 = 68 ;
V_10 -> V_347 = V_348 ;
V_342 = F_78 ( V_6 ) ;
V_82 = F_227 ( V_10 , V_342 ) ;
if ( V_82 ) {
F_130 ( V_21 , L_83 ) ;
return V_82 ;
}
V_82 = F_228 ( V_10 , V_342 ) ;
if ( V_82 ) {
F_130 ( V_21 , L_84 ) ;
return V_82 ;
}
V_82 = F_229 ( V_10 ) ;
if ( V_82 < 0 ) {
F_130 ( V_21 , L_85 ) ;
return V_82 ;
}
return 0 ;
}
static int F_230 ( void * V_349 )
{
struct V_5 * V_6 = (struct V_5 * ) V_349 ;
int V_82 ;
while ( ! F_231 () ) {
V_82 = F_111 ( V_6 ) ;
if ( F_18 ( V_82 ) )
return V_82 ;
F_125 ( V_350 ) ;
}
return 0 ;
}
static T_9 F_232 ( int V_351 , void * V_349 )
{
return V_352 ;
}
static T_9 F_233 ( int V_351 , void * V_349 )
{
T_3 V_59 = 0 , V_353 = 0 ;
struct V_20 * V_21 = (struct V_20 * ) V_349 ;
struct V_214 * V_354 = F_154 ( V_21 ) ;
struct V_109 * V_10 = F_192 ( V_21 ) ;
int V_82 ;
V_82 = F_234 ( V_354 -> V_135 , 0 , V_354 -> V_219 ,
V_355 , & V_59 ) ;
if ( F_18 ( V_82 ) ) {
F_87 ( V_10 , L_86 , V_82 ) ;
V_353 = 0xffffffff ;
goto V_356;
}
if ( V_59 & V_357 ) {
V_353 |= V_357 ;
F_111 ( F_70 ( V_10 ) ) ;
}
V_356:
F_235 ( V_354 -> V_135 , 0 , V_354 -> V_219 ,
V_355 , V_353 ) ;
return V_358 ;
}
static int F_236 ( struct V_214 * V_256 )
{
int V_82 = 0 ;
struct V_359 * V_360 ;
V_82 = F_237 ( V_256 ) ;
if ( V_82 ) {
F_130 ( & V_256 -> V_21 , L_87 ) ;
return V_82 ;
}
V_360 = V_256 -> V_361 [ 0 ] ;
V_82 = F_238 ( & V_256 -> V_21 , V_360 -> V_362 -> V_360 ,
F_232 ,
F_233 ,
V_363 | V_364 ,
F_239 ( & V_256 -> V_21 ) , & V_256 -> V_21 ) ;
if ( V_82 < 0 ) {
F_130 ( & V_256 -> V_21 , L_88 , V_82 ) ;
goto V_365;
}
V_82 = F_240 ( V_256 -> V_135 , 0 , V_256 -> V_219 ,
V_355 , V_357 ) ;
if ( V_82 < 0 ) {
F_130 ( & V_256 -> V_21 , L_89 , V_82 ) ;
goto V_366;
}
V_82 = F_241 ( V_256 -> V_135 , 0 , V_256 -> V_219 ,
V_355 , 1 ) ;
if ( V_82 < 0 ) {
F_130 ( & V_256 -> V_21 , L_90 , V_82 ) ;
goto V_366;
}
return 0 ;
V_366:
F_242 ( & V_256 -> V_21 , V_360 -> V_362 -> V_360 , & V_256 -> V_21 ) ;
V_365:
F_243 ( V_256 ) ;
return V_82 ;
}
static void F_244 ( struct V_5 * V_6 )
{
int V_28 ;
struct V_35 * V_36 ;
for ( V_28 = 0 ; V_28 < V_6 -> V_152 ; V_28 ++ ) {
V_36 = V_6 -> V_154 [ V_28 ] ;
F_245 ( V_6 -> V_10 , & V_36 -> V_51 , F_103 ,
V_367 ) ;
}
}
static void F_246 ( struct V_5 * V_6 )
{
int V_28 ;
struct V_35 * V_36 ;
for ( V_28 = 0 ; V_28 < V_6 -> V_152 ; V_28 ++ ) {
V_36 = V_6 -> V_154 [ V_28 ] ;
F_247 ( & V_36 -> V_51 ) ;
}
}
static int F_248 ( struct V_214 * V_354 )
{
struct V_20 * V_21 ;
struct V_109 * V_10 = NULL ;
struct V_5 * V_6 = NULL ;
int V_82 = 0 ;
V_21 = & V_354 -> V_21 ;
V_10 = F_249 ( sizeof( * V_6 ) , V_368 ) ;
if ( ! V_10 ) {
F_130 ( V_21 , L_91 ) ;
return - V_93 ;
}
F_250 ( V_10 , V_21 ) ;
F_251 ( V_21 , V_10 ) ;
V_6 = F_70 ( V_10 ) ;
V_6 -> V_10 = V_10 ;
V_6 -> V_1 = F_252 ( V_21 ) ;
V_82 = F_253 ( V_354 , V_369 ,
& V_6 -> V_135 ) ;
if ( V_82 ) {
F_130 ( V_21 , L_92 ) ;
goto V_370;
}
V_82 = F_191 ( V_354 ) ;
if ( V_82 )
goto V_371;
V_82 = F_166 ( V_6 ) ;
if ( V_82 )
goto V_372;
F_182 ( V_6 ) ;
V_82 = F_183 ( V_6 ) ;
if ( V_82 )
goto V_373;
V_82 = F_210 ( V_6 ) ;
if ( V_82 )
goto V_374;
F_244 ( V_6 ) ;
V_6 -> V_53 = F_254 ( * V_6 -> V_53 ) ;
if ( ! V_6 -> V_53 ) {
F_130 ( V_21 , L_93 ) ;
V_82 = - V_93 ;
goto V_375;
}
V_6 -> V_55 = F_254 ( * V_6 -> V_55 ) ;
if ( ! V_6 -> V_55 ) {
F_130 ( V_21 , L_94 ) ;
V_82 = - V_93 ;
goto V_376;
}
V_82 = F_225 ( V_10 ) ;
if ( V_82 )
goto V_377;
V_82 = F_85 ( V_6 , ! ! ( V_10 -> V_11 & V_12 ) ) ;
if ( V_82 )
goto V_378;
V_82 = F_88 ( V_6 , ! ! ( V_10 -> V_11 &
( V_187 | V_188 ) ) ) ;
if ( V_82 )
goto V_378;
V_82 = F_214 ( V_6 ) ;
if ( V_82 )
goto V_379;
V_10 -> V_380 = & V_381 ;
V_82 = F_236 ( V_354 ) ;
if ( V_82 ) {
F_126 ( V_10 , L_95 ) ;
V_6 -> V_382 = F_255 ( F_230 , V_6 ,
L_96 , V_10 -> V_383 ) ;
if ( F_256 ( V_6 -> V_382 ) ) {
F_87 ( V_10 , L_97 ) ;
goto V_384;
}
V_6 -> V_385 = true ;
}
F_155 ( V_21 , L_98 , V_10 -> V_383 ) ;
return 0 ;
V_384:
F_217 ( V_6 ) ;
V_379:
V_378:
F_257 ( V_10 ) ;
V_377:
F_258 ( V_6 -> V_55 ) ;
V_376:
F_258 ( V_6 -> V_53 ) ;
V_375:
F_246 ( V_6 ) ;
V_374:
F_190 ( V_6 ) ;
V_373:
F_176 ( V_6 ) ;
V_372:
F_199 ( V_6 ) ;
V_371:
F_259 ( V_6 -> V_135 ) ;
V_370:
F_251 ( V_21 , NULL ) ;
F_260 ( V_10 ) ;
return V_82 ;
}
static int F_261 ( struct V_214 * V_256 )
{
struct V_20 * V_21 ;
struct V_109 * V_10 ;
struct V_5 * V_6 ;
V_21 = & V_256 -> V_21 ;
V_10 = F_192 ( V_21 ) ;
V_6 = F_70 ( V_10 ) ;
F_257 ( V_10 ) ;
F_155 ( V_10 -> V_21 . V_22 , L_99 , V_10 -> V_383 ) ;
if ( V_6 -> V_385 )
F_262 ( V_6 -> V_382 ) ;
else
F_243 ( V_256 ) ;
F_217 ( V_6 ) ;
F_258 ( V_6 -> V_53 ) ;
F_258 ( V_6 -> V_55 ) ;
F_246 ( V_6 ) ;
F_190 ( V_6 ) ;
F_176 ( V_6 ) ;
F_199 ( V_6 ) ;
F_259 ( V_6 -> V_135 ) ;
F_251 ( V_21 , NULL ) ;
F_260 ( V_10 ) ;
return 0 ;
}
