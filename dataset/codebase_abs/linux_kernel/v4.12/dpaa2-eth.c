static void F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
struct V_4 * V_5 )
{
F_2 ( V_5 ) ;
if ( ! ( V_2 -> V_6 -> V_7 & V_8 ) )
return;
if ( ! ( ( V_3 & V_9 ) &&
( V_3 & V_10 ) ) )
return;
V_5 -> V_11 = V_12 ;
}
static void F_3 ( struct V_1 * V_2 ,
const struct V_13 * V_14 ,
void * V_15 )
{
struct V_16 * V_17 = V_2 -> V_6 -> V_17 . V_18 ;
T_2 V_19 = F_4 ( V_14 ) ;
T_3 V_20 = F_5 ( V_14 ) ;
struct V_21 * V_22 ;
void * V_23 ;
int V_24 ;
if ( V_20 == V_25 )
goto V_26;
else if ( V_20 != V_27 )
return;
V_22 = V_15 + F_6 ( V_14 ) ;
for ( V_24 = 0 ; V_24 < V_28 ; V_24 ++ ) {
V_19 = F_7 ( & V_22 [ V_24 ] ) ;
F_8 ( V_17 , V_19 , V_29 ,
V_30 ) ;
V_23 = F_9 ( V_19 ) ;
F_10 ( V_23 ) ;
if ( F_11 ( & V_22 [ V_24 ] ) )
break;
}
V_26:
F_10 ( V_15 ) ;
}
static struct V_4 * F_12 ( struct V_1 * V_2 ,
struct V_31 * V_32 ,
const struct V_13 * V_14 ,
void * V_33 )
{
struct V_4 * V_5 = NULL ;
T_4 V_34 = F_6 ( V_14 ) ;
T_1 V_35 = F_13 ( V_14 ) ;
V_5 = F_14 ( V_33 , V_29 +
F_15 ( sizeof( struct V_36 ) ) ) ;
if ( F_16 ( ! V_5 ) )
return NULL ;
F_17 ( V_5 , V_34 ) ;
F_18 ( V_5 , V_35 ) ;
V_32 -> V_37 -- ;
return V_5 ;
}
static struct V_4 * F_19 ( struct V_1 * V_2 ,
struct V_31 * V_32 ,
struct V_21 * V_22 )
{
struct V_4 * V_5 = NULL ;
struct V_16 * V_17 = V_2 -> V_6 -> V_17 . V_18 ;
void * V_23 ;
T_2 V_38 ;
T_4 V_39 ;
T_1 V_40 ;
struct V_41 * V_41 , * V_42 ;
int V_43 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_28 ; V_24 ++ ) {
struct V_21 * V_44 = & V_22 [ V_24 ] ;
V_38 = F_7 ( V_44 ) ;
F_8 ( V_17 , V_38 , V_29 ,
V_30 ) ;
V_23 = F_9 ( V_38 ) ;
V_40 = F_20 ( V_44 ) ;
if ( V_24 == 0 ) {
V_5 = F_14 ( V_23 , V_29 +
F_15 ( sizeof( struct V_36 ) ) ) ;
if ( F_16 ( ! V_5 ) )
return NULL ;
V_39 = F_21 ( V_44 ) ;
F_17 ( V_5 , V_39 ) ;
F_18 ( V_5 , V_40 ) ;
} else {
V_41 = F_22 ( V_23 ) ;
V_42 = F_23 ( V_23 ) ;
V_43 = ( ( unsigned long ) V_23 &
( V_45 - 1 ) ) +
( F_24 ( V_41 ) - F_24 ( V_42 ) ) ;
F_25 ( V_5 , V_24 - 1 , V_42 , V_43 ,
V_40 , V_29 ) ;
}
if ( F_11 ( V_44 ) )
break;
}
V_32 -> V_37 -= V_24 + 2 ;
return V_5 ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_31 * V_32 ,
const struct V_13 * V_14 ,
struct V_46 * V_47 )
{
T_2 V_19 = F_4 ( V_14 ) ;
T_3 V_20 = F_5 ( V_14 ) ;
void * V_15 ;
struct V_4 * V_5 ;
struct V_48 * V_49 ;
struct V_50 * V_51 ;
struct V_16 * V_17 = V_2 -> V_6 -> V_17 . V_18 ;
struct V_52 * V_53 ;
T_1 V_54 = 0 ;
F_27 ( V_2 -> V_6 , V_14 ) ;
F_8 ( V_17 , V_19 , V_29 , V_30 ) ;
V_15 = F_9 ( V_19 ) ;
F_28 ( V_15 + V_2 -> V_55 . V_56 ) ;
F_28 ( V_15 + F_6 ( V_14 ) ) ;
V_49 = F_29 ( V_2 -> V_49 ) ;
V_51 = F_29 ( V_2 -> V_51 ) ;
if ( V_20 == V_25 ) {
V_5 = F_12 ( V_2 , V_32 , V_14 , V_15 ) ;
} else if ( V_20 == V_27 ) {
struct V_21 * V_22 =
V_15 + F_6 ( V_14 ) ;
V_5 = F_19 ( V_2 , V_32 , V_22 ) ;
F_10 ( V_15 ) ;
V_51 -> V_57 ++ ;
V_51 -> V_58 += F_13 ( V_14 ) ;
} else {
goto V_59;
}
if ( F_16 ( ! V_5 ) )
goto V_60;
F_28 ( V_5 -> V_61 ) ;
if ( F_30 ( F_31 ( V_14 ) & V_62 ) ) {
V_53 = (struct V_52 * )
( V_15 + V_2 -> V_55 . V_56 ) ;
V_54 = F_32 ( V_53 -> V_54 ) ;
F_1 ( V_2 , V_54 , V_5 ) ;
}
V_5 -> V_63 = F_33 ( V_5 , V_2 -> V_6 ) ;
V_49 -> V_64 ++ ;
V_49 -> V_65 += F_13 ( V_14 ) ;
if ( V_2 -> V_6 -> V_7 & V_66 )
F_34 ( V_47 , V_5 ) ;
else
F_35 ( V_5 ) ;
return;
V_60:
F_3 ( V_2 , V_14 , V_15 ) ;
V_59:
V_49 -> V_67 ++ ;
}
static int F_36 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_2 ;
struct V_68 * V_69 ;
struct V_70 * V_71 ;
const struct V_13 * V_14 ;
int V_72 = 0 ;
int V_73 ;
do {
V_71 = F_37 ( V_32 -> V_74 , & V_73 ) ;
if ( F_16 ( ! V_71 ) ) {
continue;
}
V_14 = F_38 ( V_71 ) ;
V_69 = (struct V_68 * ) F_39 ( V_71 ) ;
V_69 -> V_75 . V_76 ++ ;
V_69 -> V_77 ( V_2 , V_32 , V_14 , & V_32 -> V_47 ) ;
V_72 ++ ;
} while ( ! V_73 );
return V_72 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_4 * V_5 ,
struct V_13 * V_14 )
{
struct V_16 * V_17 = V_2 -> V_6 -> V_17 . V_18 ;
void * V_78 = NULL ;
void * V_79 ;
T_2 V_19 ;
int V_80 = F_41 ( V_5 ) -> V_80 ;
struct V_21 * V_22 ;
int V_24 , V_81 ;
int V_82 ;
struct V_83 * V_84 , * V_85 ;
int V_86 ;
int V_87 ;
struct V_88 * V_89 ;
if ( F_16 ( V_45 / sizeof( struct V_83 ) < V_80 + 1 ) )
return - V_90 ;
V_84 = F_42 ( V_80 + 1 , sizeof( struct V_83 ) , V_91 ) ;
if ( F_16 ( ! V_84 ) )
return - V_92 ;
F_43 ( V_84 , V_80 + 1 ) ;
V_86 = F_44 ( V_5 , V_84 , 0 , V_5 -> V_93 ) ;
V_87 = F_45 ( V_17 , V_84 , V_86 , V_94 ) ;
if ( F_16 ( ! V_87 ) ) {
V_81 = - V_92 ;
goto V_95;
}
V_82 = V_2 -> V_96 +
sizeof( struct V_21 ) * ( 1 + V_87 ) ;
V_78 = F_46 ( V_82 + V_97 , V_91 ) ;
if ( F_16 ( ! V_78 ) ) {
V_81 = - V_92 ;
goto V_98;
}
V_78 = F_47 ( V_78 , V_97 ) ;
V_79 = V_78 + V_2 -> V_55 . V_56 ;
memset ( V_79 + V_99 , 0 , V_100 ) ;
V_22 = (struct V_21 * ) ( V_78 + V_2 -> V_96 ) ;
F_48 (scl, crt_scl, num_dma_bufs, i) {
F_49 ( & V_22 [ V_24 ] , F_50 ( V_85 ) ) ;
F_51 ( & V_22 [ V_24 ] , F_52 ( V_85 ) ) ;
}
F_53 ( & V_22 [ V_24 - 1 ] , true ) ;
V_89 = (struct V_88 * ) V_78 ;
V_89 -> V_5 = V_5 ;
V_89 -> V_84 = V_84 ;
V_89 -> V_86 = V_86 ;
V_89 -> V_87 = V_87 ;
V_19 = F_54 ( V_17 , V_78 , V_82 , V_94 ) ;
if ( F_16 ( F_55 ( V_17 , V_19 ) ) ) {
V_81 = - V_92 ;
goto V_101;
}
F_56 ( V_14 , V_2 -> V_96 ) ;
F_57 ( V_14 , V_27 ) ;
F_58 ( V_14 , V_19 ) ;
F_59 ( V_14 , V_5 -> V_93 ) ;
F_60 ( V_14 , V_102 | V_103 |
V_104 ) ;
return 0 ;
V_101:
F_61 ( V_78 ) ;
V_98:
F_62 ( V_17 , V_84 , V_86 , V_94 ) ;
V_95:
F_61 ( V_84 ) ;
return V_81 ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_4 * V_5 ,
struct V_13 * V_14 )
{
struct V_16 * V_17 = V_2 -> V_6 -> V_17 . V_18 ;
T_3 * V_105 ;
void * V_79 ;
struct V_4 * * V_106 ;
T_2 V_19 ;
V_105 = F_47 ( V_5 -> V_61 - V_2 -> V_96 -
V_97 ,
V_97 ) ;
V_79 = V_105 + V_2 -> V_55 . V_56 ;
memset ( V_79 + V_99 , 0 , V_100 ) ;
V_106 = (struct V_4 * * ) V_105 ;
* V_106 = V_5 ;
V_19 = F_54 ( V_17 , V_105 ,
F_64 ( V_5 ) - V_105 ,
V_94 ) ;
if ( F_16 ( F_55 ( V_17 , V_19 ) ) )
return - V_92 ;
F_58 ( V_14 , V_19 ) ;
F_56 ( V_14 , ( T_4 ) ( V_5 -> V_61 - V_105 ) ) ;
F_59 ( V_14 , V_5 -> V_93 ) ;
F_57 ( V_14 , V_25 ) ;
F_60 ( V_14 , V_102 | V_103 |
V_104 ) ;
return 0 ;
}
static void F_65 ( const struct V_1 * V_2 ,
const struct V_13 * V_14 ,
T_1 * V_54 )
{
struct V_16 * V_17 = V_2 -> V_6 -> V_17 . V_18 ;
T_2 V_107 ;
struct V_4 * * V_106 , * V_5 ;
unsigned char * V_105 ;
int V_108 ;
struct V_83 * V_84 ;
int V_86 , V_87 ;
struct V_88 * V_89 ;
T_3 V_20 = F_5 ( V_14 ) ;
struct V_52 * V_53 ;
V_107 = F_4 ( V_14 ) ;
V_106 = F_9 ( V_107 ) ;
if ( V_20 == V_25 ) {
V_5 = * V_106 ;
V_105 = ( unsigned char * ) V_106 ;
F_8 ( V_17 , V_107 ,
F_64 ( V_5 ) - V_105 ,
V_94 ) ;
} else if ( V_20 == V_27 ) {
V_89 = (struct V_88 * ) V_106 ;
V_5 = V_89 -> V_5 ;
V_84 = V_89 -> V_84 ;
V_86 = V_89 -> V_86 ;
V_87 = V_89 -> V_87 ;
F_62 ( V_17 , V_84 , V_86 , V_94 ) ;
F_61 ( V_84 ) ;
V_108 = V_2 -> V_96 +
sizeof( struct V_21 ) * ( 1 + V_87 ) ;
F_8 ( V_17 , V_107 , V_108 , V_94 ) ;
} else {
if ( V_54 )
* V_54 = ~ 0 ;
return;
}
if ( V_54 && ( F_31 ( V_14 ) & V_62 ) ) {
V_53 = (struct V_52 * )
( ( void * ) V_106 + V_2 -> V_55 . V_56 ) ;
* V_54 = F_32 ( V_53 -> V_54 ) ;
}
if ( V_20 != V_25 )
F_61 ( V_106 ) ;
F_66 ( V_5 ) ;
}
static int F_67 ( struct V_4 * V_5 , struct V_109 * V_6 )
{
struct V_1 * V_2 = F_68 ( V_6 ) ;
struct V_13 V_14 ;
struct V_48 * V_49 ;
struct V_50 * V_51 ;
struct V_68 * V_69 ;
T_4 V_110 ;
int V_81 , V_24 ;
V_49 = F_29 ( V_2 -> V_49 ) ;
V_51 = F_29 ( V_2 -> V_51 ) ;
if ( F_16 ( F_69 ( V_5 ) < F_70 ( V_2 ) ) ) {
struct V_4 * V_111 ;
V_111 = F_71 ( V_5 , F_70 ( V_2 ) ) ;
if ( F_16 ( ! V_111 ) ) {
V_49 -> V_112 ++ ;
goto V_113;
}
F_66 ( V_5 ) ;
V_5 = V_111 ;
}
V_5 = F_72 ( V_5 , V_91 ) ;
if ( F_16 ( ! V_5 ) ) {
V_49 -> V_112 ++ ;
return V_114 ;
}
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
if ( F_73 ( V_5 ) ) {
V_81 = F_40 ( V_2 , V_5 , & V_14 ) ;
V_51 -> V_115 ++ ;
V_51 -> V_116 += V_5 -> V_93 ;
} else {
V_81 = F_63 ( V_2 , V_5 , & V_14 ) ;
}
if ( F_16 ( V_81 ) ) {
V_49 -> V_112 ++ ;
goto V_117;
}
F_74 ( V_6 , & V_14 ) ;
V_110 = F_75 () % F_76 ( V_2 ) ;
V_69 = & V_2 -> V_69 [ V_110 ] ;
for ( V_24 = 0 ; V_24 < V_118 ; V_24 ++ ) {
V_81 = F_77 ( NULL , V_2 -> V_119 , 0 ,
V_69 -> V_120 , & V_14 ) ;
if ( V_81 != - V_121 )
break;
}
V_51 -> V_122 += V_24 ;
if ( F_16 ( V_81 < 0 ) ) {
V_49 -> V_123 ++ ;
F_65 ( V_2 , & V_14 , NULL ) ;
} else {
V_49 -> V_124 ++ ;
V_49 -> V_125 += V_5 -> V_93 ;
}
return V_114 ;
V_117:
V_113:
F_66 ( V_5 ) ;
return V_114 ;
}
static void F_78 ( struct V_1 * V_2 ,
struct V_31 * V_32 ,
const struct V_13 * V_14 ,
struct V_46 * V_47 V_126 )
{
struct V_48 * V_49 ;
struct V_50 * V_51 ;
T_1 V_54 = 0 ;
F_79 ( V_2 -> V_6 , V_14 ) ;
V_51 = F_29 ( V_2 -> V_51 ) ;
V_51 -> V_127 ++ ;
V_51 -> V_128 += F_13 ( V_14 ) ;
F_65 ( V_2 , V_14 , & V_54 ) ;
if ( F_16 ( V_54 & V_129 ) ) {
V_49 = F_29 ( V_2 -> V_49 ) ;
V_49 -> V_123 ++ ;
}
}
static int F_80 ( struct V_1 * V_2 , bool V_130 )
{
int V_81 ;
V_81 = F_81 ( V_2 -> V_131 , 0 , V_2 -> V_132 ,
V_133 , V_130 ) ;
if ( V_81 ) {
F_82 ( V_2 -> V_6 ,
L_1 ) ;
return V_81 ;
}
V_81 = F_81 ( V_2 -> V_131 , 0 , V_2 -> V_132 ,
V_134 , V_130 ) ;
if ( V_81 ) {
F_82 ( V_2 -> V_6 ,
L_2 ) ;
return V_81 ;
}
return 0 ;
}
static int F_83 ( struct V_1 * V_2 , bool V_130 )
{
int V_81 ;
V_81 = F_81 ( V_2 -> V_131 , 0 , V_2 -> V_132 ,
V_135 , V_130 ) ;
if ( V_81 ) {
F_82 ( V_2 -> V_6 , L_3 ) ;
return V_81 ;
}
V_81 = F_81 ( V_2 -> V_131 , 0 , V_2 -> V_132 ,
V_136 , V_130 ) ;
if ( V_81 ) {
F_82 ( V_2 -> V_6 , L_4 ) ;
return V_81 ;
}
return 0 ;
}
static int F_84 ( struct V_1 * V_2 , T_4 V_137 )
{
struct V_16 * V_17 = V_2 -> V_6 -> V_17 . V_18 ;
T_5 V_138 [ V_139 ] ;
void * V_140 ;
T_2 V_19 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_139 ; V_24 ++ ) {
V_140 = F_85 ( V_141 ) ;
if ( F_16 ( ! V_140 ) )
goto V_142;
V_140 = F_47 ( V_140 , V_143 ) ;
V_19 = F_54 ( V_17 , V_140 , V_29 ,
V_30 ) ;
if ( F_16 ( F_55 ( V_17 , V_19 ) ) )
goto V_144;
V_138 [ V_24 ] = V_19 ;
F_86 ( V_2 -> V_6 ,
V_140 , V_141 ,
V_19 , V_29 ,
V_137 ) ;
}
V_145:
while ( F_87 ( NULL , V_137 , V_138 , V_24 ) )
F_88 () ;
return V_24 ;
V_144:
F_10 ( V_140 ) ;
V_142:
if ( V_24 )
goto V_145;
return 0 ;
}
static int F_89 ( struct V_1 * V_2 , T_4 V_137 )
{
int V_24 , V_146 ;
int V_147 ;
F_90 () ;
for ( V_146 = 0 ; V_146 < V_2 -> V_148 ; V_146 ++ ) {
for ( V_24 = 0 ; V_24 < V_149 ;
V_24 += V_139 ) {
V_147 = F_84 ( V_2 , V_137 ) ;
V_2 -> V_150 [ V_146 ] -> V_37 += V_147 ;
if ( V_147 < V_139 ) {
F_91 () ;
return - V_92 ;
}
}
}
F_91 () ;
return 0 ;
}
static void F_92 ( struct V_1 * V_2 , int V_151 )
{
struct V_16 * V_17 = V_2 -> V_6 -> V_17 . V_18 ;
T_5 V_138 [ V_139 ] ;
void * V_15 ;
int V_152 , V_24 ;
do {
V_152 = F_93 ( NULL , V_2 -> V_153 . V_137 ,
V_138 , V_151 ) ;
if ( V_152 < 0 ) {
F_82 ( V_2 -> V_6 , L_5 ) ;
return;
}
for ( V_24 = 0 ; V_24 < V_152 ; V_24 ++ ) {
F_8 ( V_17 , V_138 [ V_24 ] ,
V_29 ,
V_30 ) ;
V_15 = F_9 ( V_138 [ V_24 ] ) ;
F_10 ( V_15 ) ;
}
} while ( V_152 );
}
static void F_94 ( struct V_1 * V_2 )
{
int V_24 ;
F_92 ( V_2 , V_139 ) ;
F_92 ( V_2 , 1 ) ;
for ( V_24 = 0 ; V_24 < V_2 -> V_148 ; V_24 ++ )
V_2 -> V_150 [ V_24 ] -> V_37 = 0 ;
}
static int F_95 ( struct V_1 * V_2 ,
struct V_31 * V_32 ,
T_4 V_137 )
{
int V_147 ;
if ( F_30 ( V_32 -> V_37 >= V_154 ) )
return 0 ;
do {
V_147 = F_84 ( V_2 , V_137 ) ;
if ( F_16 ( ! V_147 ) ) {
break;
}
V_32 -> V_37 += V_147 ;
} while ( V_32 -> V_37 < V_149 );
if ( F_16 ( V_32 -> V_37 < V_149 ) )
return - V_92 ;
return 0 ;
}
static int F_96 ( struct V_31 * V_32 )
{
int V_81 ;
int V_155 = - 1 ;
do {
V_81 = F_97 ( NULL , V_32 -> V_156 , V_32 -> V_74 ) ;
V_155 ++ ;
F_88 () ;
} while ( V_81 == - V_121 );
V_32 -> V_75 . V_157 += V_155 ;
if ( F_16 ( V_81 ) )
V_32 -> V_75 . V_158 ++ ;
return V_81 ;
}
static int F_98 ( struct V_46 * V_47 , int V_159 )
{
struct V_31 * V_32 ;
int V_72 = 0 , V_160 ;
struct V_1 * V_2 ;
int V_81 ;
V_32 = F_99 ( V_47 , struct V_31 , V_47 ) ;
V_2 = V_32 -> V_2 ;
while ( V_72 < V_159 ) {
V_81 = F_96 ( V_32 ) ;
if ( F_16 ( V_81 ) )
break;
F_95 ( V_2 , V_32 , V_2 -> V_153 . V_137 ) ;
V_160 = F_36 ( V_32 ) ;
V_72 += V_160 ;
if ( V_160 == 0 ||
V_72 > V_159 - V_161 )
break;
}
if ( V_72 < V_159 ) {
F_100 ( V_47 , V_72 ) ;
do {
V_81 = F_101 ( NULL , & V_32 -> V_162 ) ;
F_88 () ;
} while ( V_81 == - V_121 );
}
V_32 -> V_75 . V_76 += V_72 ;
return V_72 ;
}
static void F_102 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_148 ; V_24 ++ ) {
V_32 = V_2 -> V_150 [ V_24 ] ;
F_103 ( & V_32 -> V_47 ) ;
}
}
static void F_104 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_148 ; V_24 ++ ) {
V_32 = V_2 -> V_150 [ V_24 ] ;
F_105 ( & V_32 -> V_47 ) ;
}
}
static int F_106 ( struct V_1 * V_2 )
{
struct V_163 V_164 ;
int V_81 ;
V_81 = F_107 ( V_2 -> V_131 , 0 , V_2 -> V_132 , & V_164 ) ;
if ( F_16 ( V_81 ) ) {
F_82 ( V_2 -> V_6 ,
L_6 ) ;
return V_81 ;
}
if ( V_2 -> V_165 . V_166 == V_164 . V_166 )
return 0 ;
V_2 -> V_165 = V_164 ;
if ( V_164 . V_166 ) {
F_108 ( V_2 -> V_6 ) ;
F_109 ( V_2 -> V_6 ) ;
} else {
F_110 ( V_2 -> V_6 ) ;
F_111 ( V_2 -> V_6 ) ;
}
F_112 ( V_2 -> V_6 , L_7 ,
V_164 . V_166 ? L_8 : L_9 ) ;
return 0 ;
}
static int F_113 ( struct V_109 * V_6 )
{
struct V_1 * V_2 = F_68 ( V_6 ) ;
int V_81 ;
V_81 = F_89 ( V_2 , V_2 -> V_153 . V_137 ) ;
if ( V_81 ) {
F_82 ( V_6 , L_10 ,
V_2 -> V_167 -> V_168 . V_169 , V_2 -> V_153 . V_137 ) ;
}
F_110 ( V_6 ) ;
F_102 ( V_2 ) ;
F_111 ( V_6 ) ;
V_81 = F_114 ( V_2 -> V_131 , 0 , V_2 -> V_132 ) ;
if ( V_81 < 0 ) {
F_82 ( V_6 , L_11 ) ;
goto V_170;
}
V_81 = F_106 ( V_2 ) ;
if ( V_81 < 0 ) {
F_82 ( V_6 , L_12 ) ;
goto V_171;
}
return 0 ;
V_171:
V_170:
F_104 ( V_2 ) ;
F_94 ( V_2 ) ;
return V_81 ;
}
static T_1 F_115 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
T_1 V_172 = 0 , V_173 = 0 ;
do {
F_96 ( V_32 ) ;
V_172 = F_36 ( V_32 ) ;
V_173 += V_172 ;
} while ( V_172 );
return V_173 ;
}
static T_1 F_116 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
int V_24 ;
T_1 V_172 = 0 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_148 ; V_24 ++ ) {
V_32 = V_2 -> V_150 [ V_24 ] ;
V_172 += F_115 ( V_2 , V_32 ) ;
}
return V_172 ;
}
static int F_117 ( struct V_109 * V_6 )
{
struct V_1 * V_2 = F_68 ( V_6 ) ;
int V_174 ;
int V_175 = 10 ;
T_1 V_172 ;
F_110 ( V_6 ) ;
F_111 ( V_6 ) ;
do {
F_118 ( V_2 -> V_131 , 0 , V_2 -> V_132 ) ;
F_119 ( V_2 -> V_131 , 0 , V_2 -> V_132 , & V_174 ) ;
if ( V_174 )
F_120 ( 100 ) ;
} while ( V_174 && -- V_175 );
if ( ! V_175 ) {
F_121 ( V_6 , L_13 ) ;
}
F_104 ( V_2 ) ;
V_172 = F_116 ( V_2 ) ;
if ( V_172 )
F_122 ( V_6 , L_14 , V_172 ) ;
F_94 ( V_2 ) ;
return 0 ;
}
static int F_123 ( struct V_109 * V_6 )
{
T_5 V_176 = 0 ;
T_5 V_177 = 0 ;
struct V_1 * V_2 = F_68 ( V_6 ) ;
T_1 V_178 = V_2 -> V_179 . V_178 ;
V_176 |= V_180 ;
if ( V_178 & V_181 )
V_177 |= V_182 ;
else
V_176 |= V_182 ;
V_6 -> V_183 |= V_176 ;
V_6 -> V_183 &= ~ V_177 ;
V_6 -> V_7 = V_8 |
V_184 | V_185 |
V_186 | V_187 |
V_188 ;
V_6 -> V_189 = V_6 -> V_7 ;
return 0 ;
}
static int F_124 ( struct V_109 * V_6 , void * V_19 )
{
struct V_1 * V_2 = F_68 ( V_6 ) ;
struct V_16 * V_17 = V_6 -> V_17 . V_18 ;
int V_81 ;
V_81 = F_125 ( V_6 , V_19 ) ;
if ( V_81 < 0 ) {
F_126 ( V_17 , L_15 , V_81 ) ;
return V_81 ;
}
V_81 = F_127 ( V_2 -> V_131 , 0 , V_2 -> V_132 ,
V_6 -> V_190 ) ;
if ( V_81 ) {
F_126 ( V_17 , L_16 , V_81 ) ;
return V_81 ;
}
return 0 ;
}
void F_128 ( struct V_109 * V_6 ,
struct V_48 * V_75 )
{
struct V_1 * V_2 = F_68 ( V_6 ) ;
struct V_48 * V_49 ;
T_5 * V_191 ;
T_5 * V_192 = ( T_5 * ) V_75 ;
int V_24 , V_146 ;
int V_193 = sizeof( struct V_48 ) / sizeof( T_5 ) ;
F_129 (i) {
V_49 = F_130 ( V_2 -> V_49 , V_24 ) ;
V_191 = ( T_5 * ) V_49 ;
for ( V_146 = 0 ; V_146 < V_193 ; V_146 ++ )
V_192 [ V_146 ] += V_191 [ V_146 ] ;
}
}
static int F_131 ( struct V_109 * V_6 , int V_194 )
{
struct V_1 * V_2 = F_68 ( V_6 ) ;
int V_81 ;
V_81 = F_132 ( V_2 -> V_131 , 0 , V_2 -> V_132 ,
( T_4 ) F_133 ( V_194 ) ) ;
if ( V_81 ) {
F_82 ( V_6 , L_17 ) ;
return V_81 ;
}
V_6 -> V_194 = V_194 ;
return 0 ;
}
static void F_134 ( const struct V_109 * V_6 ,
struct V_1 * V_2 )
{
struct V_195 * V_196 ;
int V_81 ;
F_135 (ha, net_dev) {
V_81 = F_136 ( V_2 -> V_131 , 0 , V_2 -> V_132 ,
V_196 -> V_19 ) ;
if ( V_81 )
F_121 ( V_2 -> V_6 ,
L_18 ,
V_196 -> V_19 , V_81 ) ;
}
}
static void F_137 ( const struct V_109 * V_6 ,
struct V_1 * V_2 )
{
struct V_195 * V_196 ;
int V_81 ;
F_138 (ha, net_dev) {
V_81 = F_136 ( V_2 -> V_131 , 0 , V_2 -> V_132 ,
V_196 -> V_19 ) ;
if ( V_81 )
F_121 ( V_2 -> V_6 ,
L_19 ,
V_196 -> V_19 , V_81 ) ;
}
}
static void F_139 ( struct V_109 * V_6 )
{
struct V_1 * V_2 = F_68 ( V_6 ) ;
int V_197 = F_140 ( V_6 ) ;
int V_198 = F_141 ( V_6 ) ;
T_3 V_199 = V_2 -> V_179 . V_200 ;
T_1 V_178 = V_2 -> V_179 . V_178 ;
T_4 V_132 = V_2 -> V_132 ;
struct V_201 * V_131 = V_2 -> V_131 ;
int V_81 ;
if ( V_178 & V_181 && V_199 != 0 )
F_112 ( V_6 ,
L_20 ,
V_199 ) ;
if ( V_197 > V_199 ) {
F_112 ( V_6 ,
L_21 ,
V_197 , V_199 ) ;
goto V_202;
}
if ( V_198 + V_197 > V_199 ) {
F_112 ( V_6 ,
L_22 ,
V_197 + V_198 , V_199 ) ;
goto V_203;
}
if ( V_6 -> V_204 & V_205 )
goto V_202;
if ( V_6 -> V_204 & V_206 ) {
V_81 = F_142 ( V_131 , 0 , V_132 , 1 ) ;
if ( V_81 )
F_121 ( V_6 , L_23 ) ;
V_81 = F_143 ( V_131 , 0 , V_132 , 1 , 0 ) ;
if ( V_81 )
F_121 ( V_6 , L_24 ) ;
F_134 ( V_6 , V_2 ) ;
V_81 = F_142 ( V_131 , 0 , V_132 , 0 ) ;
if ( V_81 )
F_121 ( V_6 , L_25 ) ;
goto V_203;
}
V_81 = F_142 ( V_131 , 0 , V_132 , 1 ) ;
if ( V_81 )
F_121 ( V_6 , L_26 , V_81 ) ;
V_81 = F_144 ( V_131 , 0 , V_132 , 1 ) ;
if ( V_81 )
F_121 ( V_6 , L_27 , V_81 ) ;
V_81 = F_143 ( V_131 , 0 , V_132 , 1 , 1 ) ;
if ( V_81 )
F_121 ( V_6 , L_28 ) ;
F_137 ( V_6 , V_2 ) ;
F_134 ( V_6 , V_2 ) ;
V_81 = F_142 ( V_131 , 0 , V_132 , 0 ) ;
if ( V_81 )
F_121 ( V_6 , L_29 ) ;
V_81 = F_144 ( V_131 , 0 , V_132 , 0 ) ;
if ( V_81 )
F_121 ( V_6 , L_30 ) ;
return;
V_202:
V_81 = F_142 ( V_131 , 0 , V_132 , 1 ) ;
if ( V_81 )
F_121 ( V_6 , L_31 ) ;
V_203:
V_81 = F_144 ( V_131 , 0 , V_132 , 1 ) ;
if ( V_81 )
F_121 ( V_6 , L_32 ) ;
}
static int F_145 ( struct V_109 * V_6 ,
T_6 V_7 )
{
struct V_1 * V_2 = F_68 ( V_6 ) ;
T_6 V_207 = V_7 ^ V_6 -> V_7 ;
bool V_130 ;
int V_81 ;
if ( V_207 & V_8 ) {
V_130 = ! ! ( V_7 & V_8 ) ;
V_81 = F_80 ( V_2 , V_130 ) ;
if ( V_81 )
return V_81 ;
}
if ( V_207 & ( V_184 | V_185 ) ) {
V_130 = ! ! ( V_7 & ( V_184 | V_185 ) ) ;
V_81 = F_83 ( V_2 , V_130 ) ;
if ( V_81 )
return V_81 ;
}
return 0 ;
}
static void F_146 ( struct V_208 * V_209 )
{
struct V_31 * V_32 ;
V_32 = F_99 ( V_209 , struct V_31 , V_162 ) ;
V_32 -> V_75 . V_210 ++ ;
F_147 ( & V_32 -> V_47 ) ;
}
static struct V_211 * F_148 ( struct V_1 * V_2 )
{
struct V_211 * V_212 ;
struct V_16 * V_17 = V_2 -> V_6 -> V_17 . V_18 ;
struct V_213 V_214 ;
int V_81 ;
V_81 = F_149 ( F_150 ( V_17 ) ,
V_215 , & V_212 ) ;
if ( V_81 ) {
F_151 ( V_17 , L_33 ) ;
return NULL ;
}
V_81 = F_152 ( V_2 -> V_131 , 0 , V_212 -> V_168 . V_169 , & V_212 -> V_216 ) ;
if ( V_81 ) {
F_126 ( V_17 , L_34 ) ;
goto V_217;
}
V_81 = F_153 ( V_2 -> V_131 , 0 , V_212 -> V_216 ) ;
if ( V_81 ) {
F_126 ( V_17 , L_35 ) ;
goto V_218;
}
V_81 = F_154 ( V_2 -> V_131 , 0 , V_212 -> V_216 , & V_214 ) ;
if ( V_81 ) {
F_126 ( V_17 , L_36 ) ;
goto V_219;
}
V_81 = F_155 ( V_2 -> V_131 , 0 , V_212 -> V_216 ) ;
if ( V_81 ) {
F_126 ( V_17 , L_37 ) ;
goto V_220;
}
return V_212 ;
V_220:
V_219:
V_218:
F_156 ( V_2 -> V_131 , 0 , V_212 -> V_216 ) ;
V_217:
F_157 ( V_212 ) ;
return NULL ;
}
static void F_158 ( struct V_1 * V_2 ,
struct V_211 * V_212 )
{
F_159 ( V_2 -> V_131 , 0 , V_212 -> V_216 ) ;
F_156 ( V_2 -> V_131 , 0 , V_212 -> V_216 ) ;
F_157 ( V_212 ) ;
}
static struct V_31 *
F_160 ( struct V_1 * V_2 )
{
struct V_31 * V_150 ;
struct V_213 V_221 ;
struct V_16 * V_17 = V_2 -> V_6 -> V_17 . V_18 ;
int V_81 ;
V_150 = F_46 ( sizeof( * V_150 ) , V_222 ) ;
if ( ! V_150 )
return NULL ;
V_150 -> V_212 = F_148 ( V_2 ) ;
if ( ! V_150 -> V_212 )
goto V_223;
V_81 = F_154 ( V_2 -> V_131 , 0 , V_150 -> V_212 -> V_216 ,
& V_221 ) ;
if ( V_81 ) {
F_126 ( V_17 , L_36 ) ;
goto V_219;
}
V_150 -> V_224 = V_221 . V_169 ;
V_150 -> V_156 = V_221 . V_225 ;
V_150 -> V_2 = V_2 ;
return V_150 ;
V_219:
F_158 ( V_2 , V_150 -> V_212 ) ;
V_223:
F_61 ( V_150 ) ;
return NULL ;
}
static void F_161 ( struct V_1 * V_2 ,
struct V_31 * V_150 )
{
F_158 ( V_2 , V_150 -> V_212 ) ;
F_61 ( V_150 ) ;
}
static int F_162 ( struct V_1 * V_2 )
{
struct V_208 * V_162 ;
struct V_31 * V_150 ;
struct V_226 V_227 ;
struct V_16 * V_17 = V_2 -> V_6 -> V_17 . V_18 ;
int V_24 , V_81 ;
F_163 ( & V_2 -> V_228 ) ;
F_164 (i) {
V_150 = F_160 ( V_2 ) ;
if ( ! V_150 ) {
F_151 ( V_17 ,
L_38 , V_24 ) ;
goto V_229;
}
V_2 -> V_150 [ V_2 -> V_148 ] = V_150 ;
V_162 = & V_150 -> V_162 ;
V_162 -> V_230 = 1 ;
V_162 -> V_231 = F_146 ;
V_162 -> V_169 = V_150 -> V_156 ;
V_162 -> V_232 = V_24 ;
V_81 = F_165 ( NULL , V_162 ) ;
if ( V_81 ) {
F_151 ( V_17 , L_39 , V_24 ) ;
goto V_233;
}
V_227 . V_234 = V_162 -> V_234 ;
V_227 . V_235 = 0 ;
V_227 . V_236 = V_162 -> V_237 ;
V_81 = F_166 ( V_2 -> V_131 , 0 ,
V_150 -> V_212 -> V_216 ,
& V_227 ) ;
if ( V_81 ) {
F_126 ( V_17 , L_40 ) ;
goto V_238;
}
F_167 ( V_24 , & V_2 -> V_228 ) ;
V_2 -> V_148 ++ ;
if ( V_2 -> V_148 == F_76 ( V_2 ) )
break;
}
return 0 ;
V_238:
F_168 ( NULL , V_162 ) ;
V_233:
F_161 ( V_2 , V_150 ) ;
V_229:
if ( F_169 ( & V_2 -> V_228 ) ) {
F_126 ( V_17 , L_41 ) ;
return - V_239 ;
}
F_151 ( V_17 , L_42 ,
F_170 ( & V_2 -> V_228 ) ) ;
return 0 ;
}
static void F_171 ( struct V_1 * V_2 )
{
int V_24 ;
struct V_31 * V_32 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_148 ; V_24 ++ ) {
V_32 = V_2 -> V_150 [ V_24 ] ;
F_168 ( NULL , & V_32 -> V_162 ) ;
F_161 ( V_2 , V_32 ) ;
}
}
static struct V_31 * F_172 ( struct V_1 * V_2 ,
int V_240 )
{
struct V_16 * V_17 = V_2 -> V_6 -> V_17 . V_18 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_148 ; V_24 ++ )
if ( V_2 -> V_150 [ V_24 ] -> V_162 . V_232 == V_240 )
return V_2 -> V_150 [ V_24 ] ;
F_173 ( V_17 , L_43 , V_240 ) ;
return V_2 -> V_150 [ 0 ] ;
}
static void F_174 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_6 -> V_17 . V_18 ;
struct V_68 * V_69 ;
int V_241 , V_242 ;
int V_24 ;
V_241 = V_242 = F_175 ( & V_2 -> V_228 ) ;
for ( V_24 = 0 ; V_24 < V_2 -> V_243 ; V_24 ++ ) {
V_69 = & V_2 -> V_69 [ V_24 ] ;
switch ( V_69 -> type ) {
case V_244 :
V_69 -> V_245 = V_241 ;
V_241 = F_176 ( V_241 , & V_2 -> V_228 ) ;
if ( V_241 >= V_246 )
V_241 = F_175 ( & V_2 -> V_228 ) ;
break;
case V_247 :
V_69 -> V_245 = V_242 ;
V_242 = F_176 ( V_242 , & V_2 -> V_228 ) ;
if ( V_242 >= V_246 )
V_242 = F_175 ( & V_2 -> V_228 ) ;
break;
default:
F_126 ( V_17 , L_44 , V_69 -> type ) ;
}
V_69 -> V_150 = F_172 ( V_2 , V_69 -> V_245 ) ;
}
}
static void F_177 ( struct V_1 * V_2 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < F_76 ( V_2 ) ; V_24 ++ ) {
V_2 -> V_69 [ V_2 -> V_243 ] . type = V_247 ;
V_2 -> V_69 [ V_2 -> V_243 ] . V_77 = F_78 ;
V_2 -> V_69 [ V_2 -> V_243 ++ ] . V_248 = ( T_4 ) V_24 ;
}
for ( V_24 = 0 ; V_24 < F_76 ( V_2 ) ; V_24 ++ ) {
V_2 -> V_69 [ V_2 -> V_243 ] . type = V_244 ;
V_2 -> V_69 [ V_2 -> V_243 ] . V_77 = F_26 ;
V_2 -> V_69 [ V_2 -> V_243 ++ ] . V_248 = ( T_4 ) V_24 ;
}
F_174 ( V_2 ) ;
}
static int F_178 ( struct V_1 * V_2 )
{
int V_81 ;
struct V_211 * V_167 ;
struct V_16 * V_17 = V_2 -> V_6 -> V_17 . V_18 ;
V_81 = F_149 ( F_150 ( V_17 ) , V_249 ,
& V_167 ) ;
if ( V_81 ) {
F_126 ( V_17 , L_45 ) ;
return V_81 ;
}
V_2 -> V_167 = V_167 ;
V_81 = F_179 ( V_2 -> V_131 , 0 , V_2 -> V_167 -> V_168 . V_169 ,
& V_167 -> V_216 ) ;
if ( V_81 ) {
F_126 ( V_17 , L_46 ) ;
goto V_217;
}
V_81 = F_180 ( V_2 -> V_131 , 0 , V_167 -> V_216 ) ;
if ( V_81 ) {
F_126 ( V_17 , L_47 ) ;
goto V_220;
}
V_81 = F_181 ( V_2 -> V_131 , 0 , V_167 -> V_216 ,
& V_2 -> V_153 ) ;
if ( V_81 ) {
F_126 ( V_17 , L_48 ) ;
goto V_219;
}
return 0 ;
V_219:
F_182 ( V_2 -> V_131 , 0 , V_167 -> V_216 ) ;
V_220:
F_183 ( V_2 -> V_131 , 0 , V_167 -> V_216 ) ;
V_217:
F_157 ( V_167 ) ;
return V_81 ;
}
static void F_184 ( struct V_1 * V_2 )
{
F_94 ( V_2 ) ;
F_182 ( V_2 -> V_131 , 0 , V_2 -> V_167 -> V_216 ) ;
F_183 ( V_2 -> V_131 , 0 , V_2 -> V_167 -> V_216 ) ;
F_157 ( V_2 -> V_167 ) ;
}
static int F_185 ( struct V_211 * V_250 )
{
struct V_16 * V_17 = & V_250 -> V_17 ;
struct V_1 * V_2 ;
struct V_109 * V_6 ;
int V_81 ;
V_6 = F_186 ( V_17 ) ;
V_2 = F_68 ( V_6 ) ;
V_2 -> V_251 = V_250 -> V_168 . V_169 ;
V_81 = F_187 ( V_2 -> V_131 , 0 , V_2 -> V_251 , & V_2 -> V_132 ) ;
if ( V_81 ) {
F_126 ( V_17 , L_49 ) ;
goto V_217;
}
V_250 -> V_131 = V_2 -> V_131 ;
V_250 -> V_216 = V_2 -> V_132 ;
V_81 = F_188 ( V_2 -> V_131 , 0 , V_2 -> V_132 ) ;
if ( V_81 ) {
F_126 ( V_17 , L_50 ) ;
goto V_218;
}
V_81 = F_189 ( V_2 -> V_131 , 0 , V_2 -> V_132 ,
& V_2 -> V_179 ) ;
if ( V_81 ) {
F_126 ( V_17 , L_51 , V_81 ) ;
goto V_219;
}
V_2 -> V_55 . V_252 = true ;
V_2 -> V_55 . V_253 = true ;
V_2 -> V_55 . V_56 = V_254 ;
V_2 -> V_55 . V_255 = V_143 ;
V_2 -> V_55 . V_178 = V_256 |
V_257 |
V_258 |
V_259 ;
V_81 = F_190 ( V_2 -> V_131 , 0 , V_2 -> V_132 ,
V_260 , & V_2 -> V_55 ) ;
if ( V_81 ) {
F_126 ( V_17 , L_52 ) ;
goto V_261;
}
V_2 -> V_55 . V_178 = V_257 |
V_258 ;
V_81 = F_190 ( V_2 -> V_131 , 0 , V_2 -> V_132 ,
V_262 , & V_2 -> V_55 ) ;
if ( V_81 ) {
F_126 ( V_17 , L_53 ) ;
goto V_261;
}
V_2 -> V_55 . V_178 = V_257 ;
V_81 = F_190 ( V_2 -> V_131 , 0 , V_2 -> V_132 ,
V_263 , & V_2 -> V_55 ) ;
if ( V_81 ) {
F_126 ( V_17 , L_54 ) ;
goto V_261;
}
V_81 = F_191 ( V_2 -> V_131 , 0 , V_2 -> V_132 ,
& V_2 -> V_96 ) ;
if ( V_81 ) {
F_126 ( V_17 , L_55 ) ;
goto V_264;
}
if ( ( V_2 -> V_96 % 64 ) != 0 )
F_173 ( V_17 , L_56 ,
V_2 -> V_96 ) ;
V_2 -> V_96 += V_254 ;
return 0 ;
V_264:
V_261:
V_219:
V_218:
F_192 ( V_2 -> V_131 , 0 , V_2 -> V_132 ) ;
V_217:
return V_81 ;
}
static void F_193 ( struct V_1 * V_2 )
{
int V_81 ;
V_81 = F_188 ( V_2 -> V_131 , 0 , V_2 -> V_132 ) ;
if ( V_81 )
F_121 ( V_2 -> V_6 , L_57 ,
V_81 ) ;
F_192 ( V_2 -> V_131 , 0 , V_2 -> V_132 ) ;
}
static int F_194 ( struct V_1 * V_2 ,
struct V_68 * V_69 )
{
struct V_16 * V_17 = V_2 -> V_6 -> V_17 . V_18 ;
struct V_265 V_266 ;
struct V_267 V_268 ;
struct V_269 V_270 ;
int V_81 ;
V_81 = F_195 ( V_2 -> V_131 , 0 , V_2 -> V_132 ,
V_260 , 0 , V_69 -> V_248 , & V_266 , & V_268 ) ;
if ( V_81 ) {
F_126 ( V_17 , L_58 ) ;
return V_81 ;
}
V_69 -> V_271 = V_268 . V_271 ;
V_266 . V_272 . V_169 = V_69 -> V_150 -> V_224 ;
V_266 . V_272 . type = V_273 ;
V_266 . V_272 . V_235 = 1 ;
V_266 . V_274 = ( T_5 ) V_69 ;
V_81 = F_196 ( V_2 -> V_131 , 0 , V_2 -> V_132 ,
V_260 , 0 , V_69 -> V_248 ,
V_275 | V_276 ,
& V_266 ) ;
if ( V_81 ) {
F_126 ( V_17 , L_59 ) ;
return V_81 ;
}
V_270 . V_130 = 1 ;
V_270 . V_277 = V_278 ;
V_81 = F_197 ( V_2 -> V_131 , 0 , V_2 -> V_132 , V_279 ,
V_260 , 0 , V_69 -> V_248 , & V_270 ) ;
if ( V_81 ) {
F_126 ( V_17 , L_60 ) ;
return V_81 ;
}
return 0 ;
}
static int F_198 ( struct V_1 * V_2 ,
struct V_68 * V_69 )
{
struct V_16 * V_17 = V_2 -> V_6 -> V_17 . V_18 ;
struct V_265 V_266 ;
struct V_267 V_268 ;
int V_81 ;
V_81 = F_195 ( V_2 -> V_131 , 0 , V_2 -> V_132 ,
V_262 , 0 , V_69 -> V_248 , & V_266 , & V_268 ) ;
if ( V_81 ) {
F_126 ( V_17 , L_61 ) ;
return V_81 ;
}
V_69 -> V_120 = V_268 . V_280 ;
V_81 = F_195 ( V_2 -> V_131 , 0 , V_2 -> V_132 ,
V_263 , 0 , V_69 -> V_248 ,
& V_266 , & V_268 ) ;
if ( V_81 ) {
F_126 ( V_17 , L_62 ) ;
return V_81 ;
}
V_69 -> V_271 = V_268 . V_271 ;
V_266 . V_272 . V_169 = V_69 -> V_150 -> V_224 ;
V_266 . V_272 . type = V_273 ;
V_266 . V_272 . V_235 = 0 ;
V_266 . V_274 = ( T_5 ) V_69 ;
V_81 = F_196 ( V_2 -> V_131 , 0 , V_2 -> V_132 ,
V_263 , 0 , V_69 -> V_248 ,
V_275 | V_276 ,
& V_266 ) ;
if ( V_81 ) {
F_126 ( V_17 , L_63 ) ;
return V_81 ;
}
return 0 ;
}
int F_199 ( struct V_109 * V_6 , T_5 V_204 )
{
struct V_16 * V_17 = V_6 -> V_17 . V_18 ;
struct V_1 * V_2 = F_68 ( V_6 ) ;
struct V_281 V_282 ;
struct V_283 V_284 ;
T_3 * V_285 ;
int V_24 ;
int V_81 = 0 ;
if ( ! F_200 ( V_2 ) ) {
F_126 ( V_17 , L_64 ) ;
return - V_286 ;
}
memset ( & V_282 , 0 , sizeof( V_282 ) ) ;
for ( V_24 = 0 ; V_24 < F_201 ( V_287 ) ; V_24 ++ ) {
struct V_288 * V_289 =
& V_282 . V_290 [ V_282 . V_291 ] ;
if ( ! ( V_204 & V_287 [ V_24 ] . V_292 ) )
continue;
if ( V_282 . V_291 >= V_293 ) {
F_126 ( V_17 , L_65 ) ;
return - V_294 ;
}
V_289 -> type = V_295 ;
V_289 -> V_296 . V_297 . V_298 = V_287 [ V_24 ] . V_299 ;
V_289 -> V_296 . V_297 . type = V_300 ;
V_289 -> V_296 . V_297 . V_301 = V_287 [ V_24 ] . V_302 ;
V_282 . V_291 ++ ;
V_2 -> V_303 |= V_287 [ V_24 ] . V_292 ;
}
V_285 = F_46 ( V_304 , V_305 | V_222 ) ;
if ( ! V_285 )
return - V_92 ;
V_81 = F_202 ( & V_282 , V_285 ) ;
if ( V_81 ) {
F_126 ( V_17 , L_66 , V_81 ) ;
goto V_306;
}
memset ( & V_284 , 0 , sizeof( V_284 ) ) ;
V_284 . V_307 = F_54 ( V_6 -> V_17 . V_18 , V_285 ,
V_304 ,
V_94 ) ;
if ( F_55 ( V_6 -> V_17 . V_18 , V_284 . V_307 ) ) {
F_126 ( V_17 , L_67 ) ;
V_81 = - V_92 ;
goto V_308;
}
V_284 . V_309 = F_76 ( V_2 ) ;
V_284 . V_310 = V_311 ;
V_81 = F_203 ( V_2 -> V_131 , 0 , V_2 -> V_132 , 0 , & V_284 ) ;
F_8 ( V_6 -> V_17 . V_18 , V_284 . V_307 ,
V_304 , V_94 ) ;
if ( V_81 )
F_126 ( V_17 , L_68 , V_81 ) ;
V_308:
V_306:
F_61 ( V_285 ) ;
return V_81 ;
}
static int F_204 ( struct V_1 * V_2 )
{
struct V_109 * V_6 = V_2 -> V_6 ;
struct V_16 * V_17 = V_6 -> V_17 . V_18 ;
struct V_312 V_313 ;
struct V_314 V_315 ;
int V_81 = 0 ;
int V_24 ;
V_313 . V_316 = 1 ;
V_313 . V_317 [ 0 ] . V_318 = V_2 -> V_167 -> V_168 . V_169 ;
V_313 . V_317 [ 0 ] . V_319 = 0 ;
V_313 . V_317 [ 0 ] . V_320 = V_29 ;
V_81 = F_205 ( V_2 -> V_131 , 0 , V_2 -> V_132 , & V_313 ) ;
if ( V_81 ) {
F_126 ( V_17 , L_69 ) ;
return V_81 ;
}
V_81 = F_199 ( V_6 , V_321 ) ;
if ( V_81 )
F_82 ( V_6 , L_70 ) ;
V_315 . V_322 = V_323 ;
V_315 . V_324 = 1 ;
V_315 . V_325 = V_326 ;
V_81 = F_206 ( V_2 -> V_131 , 0 , V_2 -> V_132 ,
& V_315 ) ;
if ( V_81 ) {
F_126 ( V_17 , L_71 ) ;
return V_81 ;
}
for ( V_24 = 0 ; V_24 < V_2 -> V_243 ; V_24 ++ ) {
switch ( V_2 -> V_69 [ V_24 ] . type ) {
case V_244 :
V_81 = F_194 ( V_2 , & V_2 -> V_69 [ V_24 ] ) ;
break;
case V_247 :
V_81 = F_198 ( V_2 , & V_2 -> V_69 [ V_24 ] ) ;
break;
default:
F_126 ( V_17 , L_72 , V_2 -> V_69 [ V_24 ] . type ) ;
return - V_90 ;
}
if ( V_81 )
return V_81 ;
}
V_81 = F_207 ( V_2 -> V_131 , 0 , V_2 -> V_132 ,
V_262 , & V_2 -> V_119 ) ;
if ( V_81 ) {
F_126 ( V_17 , L_73 ) ;
return V_81 ;
}
return 0 ;
}
static int F_208 ( struct V_1 * V_2 )
{
struct V_109 * V_6 = V_2 -> V_6 ;
struct V_16 * V_17 = V_6 -> V_17 . V_18 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_148 ; V_24 ++ ) {
V_2 -> V_150 [ V_24 ] -> V_74 =
F_209 ( V_161 , V_17 ) ;
if ( ! V_2 -> V_150 [ V_24 ] -> V_74 ) {
F_82 ( V_6 , L_74 ) ;
goto V_327;
}
}
return 0 ;
V_327:
for ( V_24 = 0 ; V_24 < V_2 -> V_148 ; V_24 ++ ) {
if ( ! V_2 -> V_150 [ V_24 ] -> V_74 )
break;
F_210 ( V_2 -> V_150 [ V_24 ] -> V_74 ) ;
}
return - V_92 ;
}
static void F_211 ( struct V_1 * V_2 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_148 ; V_24 ++ )
F_210 ( V_2 -> V_150 [ V_24 ] -> V_74 ) ;
}
static int F_212 ( struct V_109 * V_6 )
{
int V_81 ;
struct V_16 * V_17 = V_6 -> V_17 . V_18 ;
struct V_1 * V_2 = F_68 ( V_6 ) ;
T_3 V_328 [ V_329 ] , V_330 [ V_329 ] ;
T_3 V_331 [ V_329 ] ;
V_6 -> V_332 = & V_333 ;
V_81 = F_213 ( V_2 -> V_131 , 0 , V_2 -> V_132 , V_328 ) ;
if ( V_81 ) {
F_126 ( V_17 , L_75 ) ;
return V_81 ;
}
V_81 = F_214 ( V_2 -> V_131 , 0 , V_2 -> V_132 ,
V_330 ) ;
if ( V_81 ) {
F_126 ( V_17 , L_76 , V_81 ) ;
return V_81 ;
}
if ( ! F_215 ( V_328 ) ) {
if ( ! F_216 ( V_328 , V_330 ) ) {
V_81 = F_127 ( V_2 -> V_131 , 0 ,
V_2 -> V_132 ,
V_328 ) ;
if ( V_81 ) {
F_126 ( V_17 , L_77 ) ;
return V_81 ;
}
}
memcpy ( V_6 -> V_190 , V_328 , V_6 -> V_334 ) ;
} else if ( F_215 ( V_330 ) ) {
F_217 ( V_6 ) ;
F_218 ( V_17 , L_78 ) ;
V_81 = F_127 ( V_2 -> V_131 , 0 , V_2 -> V_132 ,
V_6 -> V_190 ) ;
if ( V_81 ) {
F_126 ( V_17 , L_79 , V_81 ) ;
return V_81 ;
}
V_6 -> V_335 = V_336 ;
} else {
memcpy ( V_6 -> V_190 , V_330 , V_6 -> V_334 ) ;
}
F_219 ( V_331 ) ;
V_81 = F_136 ( V_2 -> V_131 , 0 , V_2 -> V_132 , V_331 ) ;
if ( V_81 ) {
F_173 ( V_17 , L_80 , V_81 ) ;
}
V_6 -> V_337 = F_70 ( V_2 ) ;
V_6 -> V_338 = 68 ;
V_6 -> V_339 = V_340 ;
V_81 = F_220 ( V_6 ) ;
if ( V_81 < 0 ) {
F_126 ( V_17 , L_81 ) ;
return V_81 ;
}
return 0 ;
}
static int F_221 ( void * V_341 )
{
struct V_1 * V_2 = (struct V_1 * ) V_341 ;
int V_81 ;
while ( ! F_222 () ) {
V_81 = F_106 ( V_2 ) ;
if ( F_16 ( V_81 ) )
return V_81 ;
F_120 ( V_342 ) ;
}
return 0 ;
}
static T_7 F_223 ( int V_343 , void * V_341 )
{
return V_344 ;
}
static T_7 F_224 ( int V_343 , void * V_341 )
{
T_1 V_54 , V_345 = 0 ;
struct V_16 * V_17 = (struct V_16 * ) V_341 ;
struct V_211 * V_346 = F_150 ( V_17 ) ;
struct V_109 * V_6 = F_186 ( V_17 ) ;
int V_81 ;
V_81 = F_225 ( V_346 -> V_131 , 0 , V_346 -> V_216 ,
V_347 , & V_54 ) ;
if ( F_16 ( V_81 ) ) {
F_82 ( V_6 , L_82 , V_81 ) ;
V_345 = 0xffffffff ;
goto V_348;
}
if ( V_54 & V_349 ) {
V_345 |= V_349 ;
F_106 ( F_68 ( V_6 ) ) ;
}
V_348:
F_226 ( V_346 -> V_131 , 0 , V_346 -> V_216 ,
V_347 , V_345 ) ;
return V_350 ;
}
static int F_227 ( struct V_211 * V_250 )
{
int V_81 = 0 ;
struct V_351 * V_352 ;
V_81 = F_228 ( V_250 ) ;
if ( V_81 ) {
F_126 ( & V_250 -> V_17 , L_83 ) ;
return V_81 ;
}
V_352 = V_250 -> V_353 [ 0 ] ;
V_81 = F_229 ( & V_250 -> V_17 , V_352 -> V_354 -> V_352 ,
F_223 ,
F_224 ,
V_355 | V_356 ,
F_230 ( & V_250 -> V_17 ) , & V_250 -> V_17 ) ;
if ( V_81 < 0 ) {
F_126 ( & V_250 -> V_17 , L_84 , V_81 ) ;
goto V_357;
}
V_81 = F_231 ( V_250 -> V_131 , 0 , V_250 -> V_216 ,
V_347 , V_349 ) ;
if ( V_81 < 0 ) {
F_126 ( & V_250 -> V_17 , L_85 , V_81 ) ;
goto V_358;
}
V_81 = F_232 ( V_250 -> V_131 , 0 , V_250 -> V_216 ,
V_347 , 1 ) ;
if ( V_81 < 0 ) {
F_126 ( & V_250 -> V_17 , L_86 , V_81 ) ;
goto V_358;
}
return 0 ;
V_358:
F_233 ( & V_250 -> V_17 , V_352 -> V_354 -> V_352 , & V_250 -> V_17 ) ;
V_357:
F_234 ( V_250 ) ;
return V_81 ;
}
static void F_235 ( struct V_1 * V_2 )
{
int V_24 ;
struct V_31 * V_32 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_148 ; V_24 ++ ) {
V_32 = V_2 -> V_150 [ V_24 ] ;
F_236 ( V_2 -> V_6 , & V_32 -> V_47 , F_98 ,
V_359 ) ;
}
}
static void F_237 ( struct V_1 * V_2 )
{
int V_24 ;
struct V_31 * V_32 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_148 ; V_24 ++ ) {
V_32 = V_2 -> V_150 [ V_24 ] ;
F_238 ( & V_32 -> V_47 ) ;
}
}
static int F_239 ( struct V_211 * V_346 )
{
struct V_16 * V_17 ;
struct V_109 * V_6 = NULL ;
struct V_1 * V_2 = NULL ;
int V_81 = 0 ;
V_17 = & V_346 -> V_17 ;
V_6 = F_240 ( sizeof( * V_2 ) , V_360 ) ;
if ( ! V_6 ) {
F_126 ( V_17 , L_87 ) ;
return - V_92 ;
}
F_241 ( V_6 , V_17 ) ;
F_242 ( V_17 , V_6 ) ;
V_2 = F_68 ( V_6 ) ;
V_2 -> V_6 = V_6 ;
V_81 = F_243 ( V_346 , V_361 ,
& V_2 -> V_131 ) ;
if ( V_81 ) {
F_126 ( V_17 , L_88 ) ;
goto V_362;
}
V_81 = F_185 ( V_346 ) ;
if ( V_81 )
goto V_363;
V_81 = F_162 ( V_2 ) ;
if ( V_81 )
goto V_364;
F_177 ( V_2 ) ;
V_81 = F_178 ( V_2 ) ;
if ( V_81 )
goto V_365;
V_81 = F_204 ( V_2 ) ;
if ( V_81 )
goto V_366;
F_235 ( V_2 ) ;
V_2 -> V_49 = F_244 ( * V_2 -> V_49 ) ;
if ( ! V_2 -> V_49 ) {
F_126 ( V_17 , L_89 ) ;
V_81 = - V_92 ;
goto V_367;
}
V_2 -> V_51 = F_244 ( * V_2 -> V_51 ) ;
if ( ! V_2 -> V_51 ) {
F_126 ( V_17 , L_90 ) ;
V_81 = - V_92 ;
goto V_368;
}
V_81 = F_212 ( V_6 ) ;
if ( V_81 )
goto V_369;
V_81 = F_80 ( V_2 , ! ! ( V_6 -> V_7 & V_8 ) ) ;
if ( V_81 )
goto V_370;
V_81 = F_83 ( V_2 , ! ! ( V_6 -> V_7 &
( V_184 | V_185 ) ) ) ;
if ( V_81 )
goto V_370;
V_81 = F_208 ( V_2 ) ;
if ( V_81 )
goto V_371;
V_6 -> V_372 = & V_373 ;
V_81 = F_227 ( V_346 ) ;
if ( V_81 ) {
F_121 ( V_6 , L_91 ) ;
V_2 -> V_374 = F_245 ( F_221 , V_2 ,
L_92 , V_6 -> V_375 ) ;
if ( F_246 ( V_2 -> V_374 ) ) {
F_82 ( V_6 , L_93 ) ;
goto V_376;
}
V_2 -> V_377 = true ;
}
F_151 ( V_17 , L_94 , V_6 -> V_375 ) ;
return 0 ;
V_376:
F_211 ( V_2 ) ;
V_371:
V_370:
F_247 ( V_6 ) ;
V_369:
F_248 ( V_2 -> V_51 ) ;
V_368:
F_248 ( V_2 -> V_49 ) ;
V_367:
F_237 ( V_2 ) ;
V_366:
F_184 ( V_2 ) ;
V_365:
F_171 ( V_2 ) ;
V_364:
F_193 ( V_2 ) ;
V_363:
F_249 ( V_2 -> V_131 ) ;
V_362:
F_242 ( V_17 , NULL ) ;
F_250 ( V_6 ) ;
return V_81 ;
}
static int F_251 ( struct V_211 * V_250 )
{
struct V_16 * V_17 ;
struct V_109 * V_6 ;
struct V_1 * V_2 ;
V_17 = & V_250 -> V_17 ;
V_6 = F_186 ( V_17 ) ;
V_2 = F_68 ( V_6 ) ;
F_247 ( V_6 ) ;
F_151 ( V_6 -> V_17 . V_18 , L_95 , V_6 -> V_375 ) ;
if ( V_2 -> V_377 )
F_252 ( V_2 -> V_374 ) ;
else
F_234 ( V_250 ) ;
F_211 ( V_2 ) ;
F_248 ( V_2 -> V_49 ) ;
F_248 ( V_2 -> V_51 ) ;
F_237 ( V_2 ) ;
F_184 ( V_2 ) ;
F_171 ( V_2 ) ;
F_193 ( V_2 ) ;
F_249 ( V_2 -> V_131 ) ;
F_242 ( V_17 , NULL ) ;
F_250 ( V_6 ) ;
return 0 ;
}
