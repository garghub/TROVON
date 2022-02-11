static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 =
(struct V_3 * ) V_2 ;
F_2 ( F_3 ( V_4 -> V_5 ) ) ;
F_4 ( & V_4 -> V_6 ) ;
return V_7 ;
}
static void F_5 ( struct V_8 * V_9 ,
struct V_3 * V_4 ,
int V_10 )
{
long V_11 = 0 ;
struct V_12 * V_13 = F_3 ( V_4 -> V_5 ) ;
F_6 ( V_13 -> V_1 , ( void * ) V_4 ) ;
F_7 ( & V_4 -> V_6 ) ;
do {
if ( V_11 )
F_8 ( 100 ) ;
V_11 = F_9 ( V_14 , V_13 -> V_15 ) ;
} while ( ( V_11 == V_16 ) || ( F_10 ( V_11 ) ) );
F_11 ( V_4 -> V_5 ,
V_9 -> V_17 ,
V_9 -> V_18 * sizeof( * V_9 -> V_19 ) , V_20 ) ;
F_12 ( ( unsigned long ) V_9 -> V_19 ) ;
}
static struct V_21 * F_13 ( struct V_8 * V_9 )
{
struct V_21 * V_22 ;
unsigned long V_23 ;
F_14 ( & V_9 -> V_24 , V_23 ) ;
V_22 = & V_9 -> V_19 [ V_9 -> V_25 ] ;
if ( V_22 -> V_26 != V_27 ) {
if ( ++ V_9 -> V_25 == V_9 -> V_18 )
V_9 -> V_25 = 0 ;
F_15 () ;
} else
V_22 = NULL ;
F_16 ( & V_9 -> V_24 , V_23 ) ;
return V_22 ;
}
static int F_17 ( struct V_3 * V_4 ,
T_2 V_28 , T_2 V_29 )
{
struct V_12 * V_13 = F_3 ( V_4 -> V_5 ) ;
F_18 () ;
return F_9 ( V_30 , V_13 -> V_15 , V_28 , V_29 ) ;
}
static void F_19 ( void * V_31 )
{
struct V_3 * V_4 = (struct V_3 * ) V_31 ;
struct V_12 * V_13 = F_3 ( V_4 -> V_5 ) ;
struct V_21 * V_22 ;
int V_32 = 0 ;
while ( ! V_32 ) {
while ( ( V_22 = F_13 ( & V_4 -> V_9 ) ) != NULL ) {
F_20 ( V_22 , V_4 ) ;
V_22 -> V_26 = V_27 ;
}
F_21 ( V_13 ) ;
V_22 = F_13 ( & V_4 -> V_9 ) ;
if ( V_22 != NULL ) {
F_2 ( V_13 ) ;
F_20 ( V_22 , V_4 ) ;
V_22 -> V_26 = V_27 ;
} else {
V_32 = 1 ;
}
}
}
static void F_22 ( void )
{
const char * V_33 ;
const T_3 * V_34 ;
if ( ! V_35 )
return;
F_23 ( V_35 ) ;
V_33 = F_24 ( V_35 , L_1 , NULL ) ;
if ( V_33 )
strncpy ( V_36 , V_33 ,
sizeof( V_36 ) ) ;
V_34 = F_24 ( V_35 , L_2 , NULL ) ;
if ( V_34 )
V_37 = F_25 ( V_34 , 1 ) ;
F_26 ( V_35 ) ;
}
static void F_27 ( struct V_3 * V_4 )
{
memset ( & V_4 -> V_38 , 0x00 ,
sizeof( V_4 -> V_38 ) ) ;
F_28 ( V_4 -> V_5 , L_3 , V_39 ) ;
strcpy ( V_4 -> V_38 . V_40 , V_39 ) ;
strncpy ( V_4 -> V_38 . V_36 , V_36 ,
sizeof( V_4 -> V_38 . V_36 ) ) ;
V_4 -> V_38 . V_37 =
F_29 ( V_37 ) ;
V_4 -> V_38 . V_41 = F_29 ( V_42 ) ;
V_4 -> V_38 . V_43 = F_29 ( V_44 ) ;
}
static int F_30 ( struct V_8 * V_9 ,
struct V_3 * V_4 )
{
int V_11 = 0 ;
struct V_12 * V_13 = F_3 ( V_4 -> V_5 ) ;
do {
if ( V_11 )
F_8 ( 100 ) ;
V_11 = F_9 ( V_14 , V_13 -> V_15 ) ;
} while ( ( V_11 == V_16 ) || ( F_10 ( V_11 ) ) );
memset ( V_9 -> V_19 , 0x00 , V_45 ) ;
V_9 -> V_25 = 0 ;
F_27 ( V_4 ) ;
V_11 = F_9 ( V_46 ,
V_13 -> V_15 ,
V_9 -> V_17 , V_45 ) ;
if ( V_11 == V_47 ) {
F_31 ( V_4 -> V_5 , L_4 ) ;
} else if ( V_11 != 0 ) {
F_31 ( V_4 -> V_5 , L_5 , V_11 ) ;
}
return V_11 ;
}
static int F_32 ( struct V_8 * V_9 ,
struct V_3 * V_4 ,
int V_10 )
{
int V_11 ;
int V_48 ;
struct V_12 * V_13 = F_3 ( V_4 -> V_5 ) ;
V_9 -> V_19 = (struct V_21 * ) F_33 ( V_49 ) ;
if ( ! V_9 -> V_19 )
goto V_50;
V_9 -> V_18 = V_45 / sizeof( * V_9 -> V_19 ) ;
V_9 -> V_17 = F_34 ( V_4 -> V_5 , V_9 -> V_19 ,
V_9 -> V_18 * sizeof( * V_9 -> V_19 ) ,
V_20 ) ;
if ( F_35 ( V_4 -> V_5 , V_9 -> V_17 ) )
goto V_51;
F_22 () ;
F_27 ( V_4 ) ;
V_48 = V_11 = F_9 ( V_46 ,
V_13 -> V_15 ,
V_9 -> V_17 , V_45 ) ;
if ( V_11 == V_52 )
V_11 = F_30 ( V_9 ,
V_4 ) ;
if ( V_11 == V_47 ) {
F_31 ( V_4 -> V_5 , L_4 ) ;
V_48 = 0 ;
} else if ( V_11 != 0 ) {
F_31 ( V_4 -> V_5 , L_6 , V_11 ) ;
goto V_53;
}
V_9 -> V_25 = 0 ;
F_36 ( & V_9 -> V_24 ) ;
F_37 ( & V_4 -> V_6 , ( void * ) F_19 ,
( unsigned long ) V_4 ) ;
if ( F_38 ( V_13 -> V_1 ,
F_1 ,
0 , L_7 , ( void * ) V_4 ) != 0 ) {
F_39 ( V_4 -> V_5 , L_8 ,
V_13 -> V_1 ) ;
goto V_54;
}
V_11 = F_21 ( V_13 ) ;
if ( V_11 != 0 ) {
F_39 ( V_4 -> V_5 , L_9 , V_11 ) ;
goto V_54;
}
return V_48 ;
V_54:
F_7 ( & V_4 -> V_6 ) ;
V_11 = 0 ;
do {
if ( V_11 )
F_8 ( 100 ) ;
V_11 = F_9 ( V_14 , V_13 -> V_15 ) ;
} while ( ( V_11 == V_16 ) || ( F_10 ( V_11 ) ) );
V_53:
F_11 ( V_4 -> V_5 ,
V_9 -> V_17 ,
V_9 -> V_18 * sizeof( * V_9 -> V_19 ) , V_20 ) ;
V_51:
F_12 ( ( unsigned long ) V_9 -> V_19 ) ;
V_50:
return - 1 ;
}
static int F_40 ( struct V_8 * V_9 ,
struct V_3 * V_4 )
{
int V_11 = 0 ;
struct V_12 * V_13 = F_3 ( V_4 -> V_5 ) ;
do {
if ( V_11 )
F_8 ( 100 ) ;
V_11 = F_9 ( V_55 , V_13 -> V_15 ) ;
} while ( ( V_11 == V_56 ) || ( V_11 == V_16 ) || ( F_10 ( V_11 ) ) );
if ( V_11 )
F_39 ( V_4 -> V_5 , L_10 , V_11 ) ;
return V_11 ;
}
static int F_41 ( struct V_57 * V_58 ,
int V_18 , struct V_3 * V_4 )
{
int V_59 ;
V_58 -> V_18 = V_18 ;
V_58 -> V_60 = 0 ;
V_58 -> V_61 = F_42 ( V_58 -> V_18 , sizeof( * V_58 -> V_61 ) , V_49 ) ;
if ( ! V_58 -> V_61 )
return - V_62 ;
V_58 -> V_63 =
F_43 ( V_4 -> V_5 ,
V_58 -> V_18 * sizeof( * V_58 -> V_63 ) ,
& V_58 -> V_64 , 0 ) ;
if ( ! V_58 -> V_63 ) {
F_44 ( V_58 -> V_61 ) ;
return - V_62 ;
}
for ( V_59 = 0 ; V_59 < V_58 -> V_18 ; ++ V_59 ) {
struct V_65 * V_66 = & V_58 -> V_61 [ V_59 ] ;
memset ( & V_66 -> V_22 , 0x00 , sizeof( V_66 -> V_22 ) ) ;
F_45 ( & V_66 -> free , 1 ) ;
V_66 -> V_22 . V_26 = V_67 ;
V_66 -> V_22 . V_68 = F_46 ( sizeof( * V_66 -> V_69 ) ) ;
V_66 -> V_22 . V_70 = F_47 ( V_58 -> V_64 +
sizeof( * V_66 -> V_69 ) * V_59 ) ;
V_66 -> V_69 = V_58 -> V_63 + V_59 ;
V_66 -> V_4 = V_4 ;
V_66 -> V_71 = NULL ;
V_66 -> V_72 = 0 ;
}
return 0 ;
}
static void F_48 ( struct V_57 * V_58 ,
struct V_3 * V_4 )
{
int V_59 , V_73 = 0 ;
for ( V_59 = 0 ; V_59 < V_58 -> V_18 ; ++ V_59 ) {
if ( F_49 ( & V_58 -> V_61 [ V_59 ] . free ) != 1 )
++ V_73 ;
if ( V_58 -> V_61 [ V_59 ] . V_71 ) {
F_50 ( V_4 -> V_5 ,
V_74 * sizeof( struct V_75 ) ,
V_58 -> V_61 [ V_59 ] . V_71 ,
V_58 -> V_61 [ V_59 ] . V_72 ) ;
}
}
if ( V_73 )
F_31 ( V_4 -> V_5 , L_11
L_12 , V_73 ) ;
F_44 ( V_58 -> V_61 ) ;
F_50 ( V_4 -> V_5 ,
V_58 -> V_18 * sizeof( * V_58 -> V_63 ) ,
V_58 -> V_63 , V_58 -> V_64 ) ;
}
static int F_51 ( struct V_57 * V_58 ,
struct V_65 * V_66 )
{
int V_76 = V_66 - V_58 -> V_61 ;
if ( V_76 < 0 || V_76 >= V_58 -> V_18 )
return 0 ;
if ( V_66 != V_58 -> V_61 + V_76 )
return 0 ;
return 1 ;
}
static void F_52 ( struct V_57 * V_58 ,
struct V_65 * V_66 )
{
if ( ! F_51 ( V_58 , V_66 ) ) {
F_39 ( V_66 -> V_4 -> V_5 , L_13
L_14 , V_66 , V_58 -> V_61 ) ;
return;
}
if ( F_53 ( & V_66 -> free ) != 1 ) {
F_39 ( V_66 -> V_4 -> V_5 , L_15
L_16 , V_66 ) ;
return;
}
}
static struct V_65 * F_54 ( struct V_57 * V_58 )
{
int V_59 ;
int V_77 = V_58 -> V_18 ;
int V_78 = V_58 -> V_60 ;
for ( V_59 = 0 ; V_59 < V_77 ; V_59 ++ ) {
V_78 = ( V_78 + 1 ) % V_77 ;
if ( ! F_55 ( & V_58 -> V_61 [ V_78 ] . free ) ) {
V_58 -> V_60 = V_78 ;
return & V_58 -> V_61 [ V_78 ] ;
}
}
F_56 ( V_79 L_17 ) ;
return NULL ;
}
static void F_57 ( struct V_65 * V_80 ,
void (* V_32) ( struct V_65 * ) ,
T_4 V_81 ,
int V_82 )
{
V_80 -> V_83 = NULL ;
V_80 -> V_84 = NULL ;
V_80 -> V_85 = NULL ;
V_80 -> V_22 . V_81 = V_81 ;
V_80 -> V_22 . V_82 = F_46 ( V_82 ) ;
V_80 -> V_32 = V_32 ;
}
static void F_58 ( struct V_86 * V_87 ,
struct V_88 * V_88 ,
int V_89 )
{
T_4 V_90 ;
if ( V_89 == 0 )
return;
if ( V_89 == 1 )
V_90 = V_91 ;
else {
V_90 = V_92 ;
V_89 = F_59 ( V_89 , V_93 ) ;
if ( V_87 -> V_94 == V_95 )
V_88 -> V_96 = V_89 ;
else
V_88 -> V_97 = V_89 ;
}
if ( V_87 -> V_94 == V_95 )
V_88 -> V_98 = V_90 << 4 ;
else
V_88 -> V_98 = V_90 ;
}
static void F_60 ( struct V_88 * V_87 ,
struct V_65 * V_80 ,
struct V_99 * V_5 )
{
T_4 V_100 , V_101 ;
V_100 = V_87 -> V_98 >> 4 ;
V_101 = V_87 -> V_98 & ( ( 1U << 4 ) - 1 ) ;
if ( V_100 == V_102 && V_101 == V_102 )
return;
if ( V_80 -> V_83 )
F_61 ( V_80 -> V_83 ) ;
}
static int F_62 ( struct V_86 * V_87 , int V_103 ,
struct V_75 * V_104 )
{
int V_59 ;
struct V_105 * V_106 ;
T_2 V_107 = 0 ;
F_63 (cmd, sg, nseg, i) {
struct V_75 * V_108 = V_104 + V_59 ;
V_108 -> V_109 = F_47 ( F_64 ( V_106 ) ) ;
V_108 -> V_110 = F_29 ( F_65 ( V_106 ) ) ;
V_108 -> V_111 = 0 ;
V_107 += F_65 ( V_106 ) ;
}
return V_107 ;
}
static int F_66 ( struct V_86 * V_87 ,
struct V_65 * V_80 ,
struct V_88 * V_88 , struct V_99 * V_5 )
{
int V_112 ;
T_2 V_107 = 0 ;
struct V_75 * V_31 =
(struct V_75 * ) V_88 -> V_113 ;
struct V_114 * V_115 =
(struct V_114 * ) V_31 ;
V_112 = F_67 ( V_87 ) ;
if ( ! V_112 )
return 1 ;
else if ( V_112 < 0 )
return 0 ;
F_58 ( V_87 , V_88 , V_112 ) ;
if ( V_112 == 1 ) {
F_62 ( V_87 , V_112 , V_31 ) ;
return 1 ;
}
V_115 -> V_116 . V_109 = 0 ;
V_115 -> V_116 . V_110 = F_29 ( V_112 *
sizeof( struct V_75 ) ) ;
V_115 -> V_116 . V_111 = 0 ;
if ( V_112 <= V_93 ) {
V_107 = F_62 ( V_87 , V_112 ,
& V_115 -> V_117 [ 0 ] ) ;
V_115 -> V_110 = F_29 ( V_107 ) ;
return 1 ;
}
if ( ! V_80 -> V_71 ) {
V_80 -> V_71 = (struct V_75 * )
F_43 ( V_5 ,
V_74 * sizeof( struct V_75 ) ,
& V_80 -> V_72 , 0 ) ;
if ( ! V_80 -> V_71 ) {
if ( ! F_68 ( V_118 ) )
F_69 ( V_79 , V_87 -> V_99 ,
L_18
L_19 ) ;
F_61 ( V_87 ) ;
return 0 ;
}
}
V_107 = F_62 ( V_87 , V_112 , V_80 -> V_71 ) ;
V_115 -> V_110 = F_29 ( V_107 ) ;
V_115 -> V_116 . V_109 = F_47 ( V_80 -> V_72 ) ;
V_115 -> V_116 . V_110 = F_29 ( V_112 *
sizeof( V_115 -> V_117 [ 0 ] ) ) ;
memcpy ( V_115 -> V_117 , V_80 -> V_71 ,
V_93 * sizeof( struct V_75 ) ) ;
return 1 ;
}
static int F_70 ( struct V_86 * V_87 ,
struct V_65 * V_80 ,
struct V_88 * V_88 , struct V_99 * V_5 )
{
switch ( V_87 -> V_94 ) {
case V_119 :
case V_95 :
break;
case V_120 :
return 1 ;
case V_20 :
F_69 ( V_79 , V_87 -> V_99 ,
L_20 ) ;
return 0 ;
default:
F_69 ( V_79 , V_87 -> V_99 ,
L_21 ,
V_87 -> V_94 ) ;
return 0 ;
}
return F_66 ( V_87 , V_80 , V_88 , V_5 ) ;
}
static void F_71 ( struct V_3 * V_4 , int V_121 )
{
struct V_65 * V_66 ;
unsigned long V_23 ;
F_14 ( V_4 -> V_122 -> V_123 , V_23 ) ;
while ( ! F_72 ( & V_4 -> V_124 ) ) {
V_66 = F_73 ( & V_4 -> V_124 , struct V_65 , V_125 ) ;
F_74 ( & V_66 -> V_125 ) ;
F_75 ( & V_66 -> V_126 ) ;
F_16 ( V_4 -> V_122 -> V_123 , V_23 ) ;
if ( V_66 -> V_83 ) {
V_66 -> V_83 -> V_127 = ( V_121 << 16 ) ;
F_60 ( & V_66 -> V_128 . V_129 . V_87 , V_66 ,
V_66 -> V_4 -> V_5 ) ;
if ( V_66 -> V_84 )
V_66 -> V_84 ( V_66 -> V_83 ) ;
} else if ( V_66 -> V_32 && V_66 -> V_22 . V_81 != V_130 &&
V_66 -> V_128 . V_129 . V_131 . V_132 != V_133 )
V_66 -> V_32 ( V_66 ) ;
F_52 ( & V_66 -> V_4 -> V_58 , V_66 ) ;
F_14 ( V_4 -> V_122 -> V_123 , V_23 ) ;
}
F_16 ( V_4 -> V_122 -> V_123 , V_23 ) ;
}
static void F_76 ( struct V_3 * V_4 )
{
F_77 ( V_4 -> V_122 ) ;
F_45 ( & V_4 -> V_134 , 0 ) ;
F_71 ( V_4 , V_135 ) ;
V_4 -> V_136 = 1 ;
F_78 ( & V_4 -> V_137 ) ;
}
static void F_79 ( struct V_65 * V_80 )
{
struct V_3 * V_4 = V_80 -> V_4 ;
F_39 ( V_4 -> V_5 , L_22 ,
V_80 -> V_128 . V_129 . V_87 . V_132 ) ;
F_76 ( V_4 ) ;
}
static int F_80 ( struct V_65 * V_80 ,
struct V_3 * V_4 ,
unsigned long V_82 )
{
T_5 * V_138 = ( T_5 * ) & V_80 -> V_22 ;
int V_139 = 0 ;
int V_11 ;
int V_140 = 0 ;
if ( V_80 -> V_22 . V_81 == V_141 ) {
V_140 = 1 ;
V_139 =
F_55 ( & V_4 -> V_134 ) ;
if ( V_139 < - 1 )
goto V_142;
else if ( V_139 == - 1 &&
V_80 -> V_128 . V_129 . V_131 . V_132 != V_133 )
goto V_143;
else if ( V_139 < 2 &&
V_80 -> V_128 . V_129 . V_87 . V_132 != V_144 ) {
int V_145 = V_139 ;
struct V_65 * V_146 ;
F_81 (tmp_evt, &hostdata->sent, list) {
V_145 ++ ;
}
if ( V_145 > 2 )
goto V_143;
}
}
* V_80 -> V_69 = V_80 -> V_128 ;
V_80 -> V_69 -> V_129 . V_147 . V_148 = ( T_2 ) V_80 ;
F_82 ( & V_80 -> V_125 , & V_4 -> V_124 ) ;
F_83 ( & V_80 -> V_126 ) ;
if ( V_82 ) {
V_80 -> V_126 . V_31 = ( unsigned long ) V_80 ;
V_80 -> V_126 . V_149 = V_150 + ( V_82 * V_151 ) ;
V_80 -> V_126 . V_152 = ( void (*) ( unsigned long ) ) F_79 ;
F_84 ( & V_80 -> V_126 ) ;
}
V_11 = F_17 ( V_4 , F_85 ( V_138 [ 0 ] ) ,
F_85 ( V_138 [ 1 ] ) ) ;
if ( V_11 != 0 ) {
F_74 ( & V_80 -> V_125 ) ;
F_75 ( & V_80 -> V_126 ) ;
if ( V_11 == V_47 ) {
F_31 ( V_4 -> V_5 , L_23
L_24 ) ;
goto V_143;
}
F_39 ( V_4 -> V_5 , L_25 , V_11 ) ;
if ( V_140 )
F_86 ( & V_4 -> V_134 ) ;
goto V_142;
}
return 0 ;
V_143:
F_60 ( & V_80 -> V_128 . V_129 . V_87 , V_80 , V_4 -> V_5 ) ;
F_52 ( & V_4 -> V_58 , V_80 ) ;
if ( V_140 && V_139 != - 1 )
F_86 ( & V_4 -> V_134 ) ;
return V_153 ;
V_142:
F_60 ( & V_80 -> V_128 . V_129 . V_87 , V_80 , V_4 -> V_5 ) ;
if ( V_80 -> V_83 != NULL ) {
V_80 -> V_83 -> V_127 = V_135 << 16 ;
V_80 -> V_84 ( V_80 -> V_83 ) ;
} else if ( V_80 -> V_32 )
V_80 -> V_32 ( V_80 ) ;
F_52 ( & V_4 -> V_58 , V_80 ) ;
return 0 ;
}
static void F_87 ( struct V_65 * V_80 )
{
struct V_154 * V_147 = & V_80 -> V_69 -> V_129 . V_147 ;
struct V_86 * V_83 = V_80 -> V_83 ;
if ( F_88 ( V_147 -> V_132 != V_155 ) ) {
if ( F_89 () )
F_31 ( V_80 -> V_4 -> V_5 ,
L_26 , V_147 -> V_132 ) ;
}
if ( V_83 ) {
V_83 -> V_127 |= V_147 -> V_156 ;
if ( ( ( V_83 -> V_127 >> 1 ) & 0x1f ) == V_157 )
memcpy ( V_83 -> V_158 ,
V_147 -> V_31 ,
F_90 ( V_147 -> V_159 ) ) ;
F_60 ( & V_80 -> V_128 . V_129 . V_87 ,
V_80 ,
V_80 -> V_4 -> V_5 ) ;
if ( V_147 -> V_23 & V_160 )
F_91 ( V_83 ,
F_90 ( V_147 -> V_161 ) ) ;
else if ( V_147 -> V_23 & V_162 )
F_91 ( V_83 , F_90 ( V_147 -> V_163 ) ) ;
}
if ( V_80 -> V_84 )
V_80 -> V_84 ( V_83 ) ;
}
static inline T_6 F_92 ( struct V_164 * V_5 )
{
return ( 0x2 << 14 ) | ( V_5 -> V_165 << 8 ) | ( V_5 -> V_166 << 5 ) | V_5 -> V_167 ;
}
static int F_93 ( struct V_86 * V_83 ,
void (* V_32) ( struct V_86 * ) )
{
struct V_88 * V_88 ;
struct V_65 * V_80 ;
struct V_114 * V_115 ;
struct V_3 * V_4 = F_94 ( V_83 -> V_99 -> V_122 ) ;
T_6 V_167 = F_92 ( V_83 -> V_99 ) ;
T_4 V_100 , V_101 ;
V_83 -> V_127 = ( V_168 << 16 ) ;
V_80 = F_54 ( & V_4 -> V_58 ) ;
if ( ! V_80 )
return V_153 ;
V_88 = & V_80 -> V_128 . V_129 . V_87 ;
memset ( V_88 , 0x00 , V_169 ) ;
V_88 -> V_132 = V_170 ;
memcpy ( V_88 -> V_171 , V_83 -> V_83 , sizeof( V_88 -> V_171 ) ) ;
F_95 ( V_167 , & V_88 -> V_167 ) ;
if ( ! F_70 ( V_83 , V_80 , V_88 , V_4 -> V_5 ) ) {
if ( ! F_68 ( V_118 ) )
F_69 ( V_79 , V_83 -> V_99 ,
L_27 ) ;
F_52 ( & V_4 -> V_58 , V_80 ) ;
return V_153 ;
}
F_57 ( V_80 ,
F_87 ,
V_141 ,
V_83 -> V_172 -> V_82 / V_151 ) ;
V_80 -> V_83 = V_83 ;
V_80 -> V_84 = V_32 ;
V_115 = (struct V_114 * ) V_88 -> V_113 ;
V_100 = V_88 -> V_98 >> 4 ;
V_101 = V_88 -> V_98 & ( ( 1U << 4 ) - 1 ) ;
if ( ( V_101 == V_92 ||
V_100 == V_92 ) &&
V_115 -> V_116 . V_109 == 0 ) {
V_115 -> V_116 . V_109 =
F_47 ( F_85 ( V_80 -> V_22 . V_70 ) +
F_96 ( struct V_88 , V_113 ) +
F_96 ( struct V_114 , V_117 ) ) ;
}
return F_80 ( V_80 , V_4 , 0 ) ;
}
void F_97 ( struct V_3 * V_4 )
{
F_11 ( V_4 -> V_5 , V_4 -> V_173 ,
sizeof( V_4 -> V_174 ) , V_20 ) ;
F_11 ( V_4 -> V_5 , V_4 -> V_175 ,
sizeof( V_4 -> V_38 ) , V_20 ) ;
}
static void F_98 ( struct V_65 * V_80 )
{
struct V_3 * V_4 = V_80 -> V_4 ;
switch ( V_80 -> V_69 -> V_129 . F_98 . V_132 ) {
case V_176 :
break;
case V_177 :
F_28 ( V_4 -> V_5 , L_28 ,
V_80 -> V_69 -> V_129 . V_178 . V_179 ) ;
F_45 ( & V_4 -> V_134 , - 1 ) ;
return;
default:
F_39 ( V_4 -> V_5 , L_29 ,
V_80 -> V_69 -> V_129 . F_98 . V_132 ) ;
F_45 ( & V_4 -> V_134 , - 1 ) ;
return;
}
F_28 ( V_4 -> V_5 , L_30 ) ;
V_4 -> V_180 = 0 ;
F_45 ( & V_4 -> V_134 ,
F_90 ( V_80 -> V_69 -> V_129 . F_98 . V_181 ) ) ;
F_99 ( V_4 -> V_122 ) ;
}
static int F_100 ( struct V_3 * V_4 )
{
int V_11 ;
unsigned long V_23 ;
struct V_182 * V_183 ;
struct V_65 * V_80 = F_54 ( & V_4 -> V_58 ) ;
F_101 ( ! V_80 ) ;
F_57 ( V_80 , F_98 ,
V_141 , V_184 ) ;
V_183 = & V_80 -> V_128 . V_129 . V_131 ;
memset ( V_183 , 0 , sizeof( * V_183 ) ) ;
V_183 -> V_132 = V_133 ;
V_183 -> V_185 = F_29 ( sizeof( union V_186 ) ) ;
V_183 -> V_187 = F_46 ( V_188 |
V_189 ) ;
F_14 ( V_4 -> V_122 -> V_123 , V_23 ) ;
F_45 ( & V_4 -> V_134 , 0 ) ;
V_11 = F_80 ( V_80 , V_4 , V_184 * 2 ) ;
F_16 ( V_4 -> V_122 -> V_123 , V_23 ) ;
F_28 ( V_4 -> V_5 , L_31 ) ;
return V_11 ;
}
static void F_102 ( struct V_65 * V_80 )
{
struct V_3 * V_4 = V_80 -> V_4 ;
if ( V_80 -> V_69 -> V_190 . V_191 . V_192 . V_156 ) {
F_39 ( V_4 -> V_5 , L_32 ,
V_80 -> V_69 -> V_190 . V_191 . V_192 . V_156 ) ;
} else {
if ( V_4 -> V_174 . V_193 . V_192 . V_194 !=
F_46 ( V_195 ) )
F_28 ( V_4 -> V_5 , L_33 ) ;
if ( V_196 ) {
if ( V_4 -> V_174 . V_197 . V_192 . V_194 ==
F_46 ( V_195 ) )
F_28 ( V_4 -> V_5 , L_34 ) ;
else
F_28 ( V_4 -> V_5 , L_35 ) ;
}
}
F_100 ( V_4 ) ;
}
static void F_103 ( struct V_3 * V_4 )
{
struct V_198 * V_199 ;
struct V_65 * V_80 ;
unsigned long V_23 ;
struct V_200 * V_201 = V_4 -> V_5 -> V_201 ;
const char * V_202 ;
V_80 = F_54 ( & V_4 -> V_58 ) ;
F_101 ( ! V_80 ) ;
F_57 ( V_80 , F_102 ,
V_130 , V_203 ) ;
V_199 = & V_80 -> V_128 . V_190 . V_191 ;
memset ( V_199 , 0 , sizeof( * V_199 ) ) ;
V_4 -> V_174 . V_23 = F_29 ( V_204 ) ;
if ( V_4 -> V_180 )
V_4 -> V_174 . V_23 |= F_29 ( V_205 ) ;
strncpy ( V_4 -> V_174 . V_206 , F_104 ( & V_4 -> V_122 -> V_207 ) ,
sizeof( V_4 -> V_174 . V_206 ) ) ;
V_4 -> V_174 . V_206 [ sizeof( V_4 -> V_174 . V_206 ) - 1 ] = '\0' ;
V_202 = F_24 ( V_201 , L_36 , NULL ) ;
V_202 = V_202 ? V_202 : F_104 ( V_4 -> V_5 ) ;
strncpy ( V_4 -> V_174 . V_208 , V_202 , sizeof( V_4 -> V_174 . V_208 ) ) ;
V_4 -> V_174 . V_208 [ sizeof( V_4 -> V_174 . V_208 ) - 1 ] = '\0' ;
V_199 -> V_192 . type = F_29 ( V_209 ) ;
V_199 -> V_210 = F_47 ( V_4 -> V_173 ) ;
V_4 -> V_174 . V_193 . V_192 . V_211 =
F_29 ( V_212 ) ;
V_4 -> V_174 . V_193 . V_192 . V_213 =
F_46 ( sizeof( V_4 -> V_174 . V_193 ) ) ;
V_4 -> V_174 . V_193 . V_192 . V_194 =
F_46 ( V_195 ) ;
V_4 -> V_174 . V_193 . V_214 = F_29 ( 1 ) ;
if ( V_196 ) {
V_4 -> V_174 . V_197 . V_192 . V_211 =
F_29 ( V_215 ) ;
V_4 -> V_174 . V_197 . V_192 . V_213 =
F_46 ( sizeof( V_4 -> V_174 . V_197 ) ) ;
V_4 -> V_174 . V_197 . V_192 . V_194 =
F_46 ( V_195 ) ;
V_4 -> V_174 . V_197 . type =
F_29 ( V_216 ) ;
V_199 -> V_192 . V_213 =
F_46 ( sizeof( V_4 -> V_174 ) ) ;
} else
V_199 -> V_192 . V_213 = F_46 ( sizeof( V_4 -> V_174 ) -
sizeof( V_4 -> V_174 . V_197 ) ) ;
F_14 ( V_4 -> V_122 -> V_123 , V_23 ) ;
if ( F_80 ( V_80 , V_4 , V_203 * 2 ) )
F_39 ( V_4 -> V_5 , L_37 ) ;
F_16 ( V_4 -> V_122 -> V_123 , V_23 ) ;
}
static void F_105 ( struct V_65 * V_80 )
{
struct V_3 * V_4 = V_80 -> V_4 ;
T_6 V_156 = F_106 ( V_80 -> V_69 -> V_190 . V_217 . V_192 . V_156 ) ;
if ( V_156 == V_218 )
F_39 ( V_4 -> V_5 , L_38 ) ;
else if ( V_156 == V_219 )
F_39 ( V_4 -> V_5 , L_39 ) ;
else if ( V_156 != V_220 )
F_39 ( V_4 -> V_5 , L_40 , V_156 ) ;
F_103 ( V_4 ) ;
}
static int F_107 ( struct V_3 * V_4 )
{
int V_11 ;
unsigned long V_23 ;
struct V_221 * V_222 ;
struct V_65 * V_80 ;
if ( ! V_217 ) {
F_103 ( V_4 ) ;
return 0 ;
}
V_80 = F_54 ( & V_4 -> V_58 ) ;
F_101 ( ! V_80 ) ;
F_57 ( V_80 , F_105 , V_130 , V_203 ) ;
V_222 = & V_80 -> V_128 . V_190 . V_217 ;
memset ( V_222 , 0 , sizeof( * V_222 ) ) ;
V_222 -> V_192 . type = F_29 ( V_223 ) ;
V_222 -> V_192 . V_213 = F_46 ( sizeof( * V_222 ) ) ;
F_14 ( V_4 -> V_122 -> V_123 , V_23 ) ;
V_11 = F_80 ( V_80 , V_4 , V_203 * 2 ) ;
F_16 ( V_4 -> V_122 -> V_123 , V_23 ) ;
return V_11 ;
}
static void F_108 ( struct V_65 * V_80 )
{
struct V_3 * V_4 = V_80 -> V_4 ;
if ( V_80 -> V_69 -> V_190 . V_224 . V_192 . V_156 ) {
F_39 ( V_4 -> V_5 , L_41 ,
V_80 -> V_69 -> V_190 . V_224 . V_192 . V_156 ) ;
} else {
F_28 ( V_4 -> V_5 , L_42
L_43 ,
V_4 -> V_38 . V_40 ,
V_4 -> V_38 . V_36 ,
F_90 ( V_4 -> V_38 . V_37 ) ,
F_90 ( V_4 -> V_38 . V_43 ) ,
F_90 ( V_4 -> V_38 . V_225 [ 0 ] ) ) ;
if ( V_4 -> V_38 . V_225 [ 0 ] )
V_4 -> V_122 -> V_226 =
F_90 ( V_4 -> V_38 . V_225 [ 0 ] ) >> 9 ;
if ( F_90 ( V_4 -> V_38 . V_43 ) == V_227 &&
strcmp ( V_4 -> V_38 . V_40 , L_44 ) <= 0 ) {
F_39 ( V_4 -> V_5 , L_45 ,
V_4 -> V_38 . V_40 ) ;
F_39 ( V_4 -> V_5 , L_46 ,
V_93 ) ;
V_4 -> V_122 -> V_228 = V_93 ;
}
if ( F_90 ( V_4 -> V_38 . V_43 ) == V_227 ) {
F_107 ( V_4 ) ;
return;
}
}
F_100 ( V_4 ) ;
}
static void F_109 ( struct V_3 * V_4 )
{
struct V_229 * V_199 ;
struct V_65 * V_80 ;
unsigned long V_23 ;
V_80 = F_54 ( & V_4 -> V_58 ) ;
F_101 ( ! V_80 ) ;
F_57 ( V_80 ,
F_108 ,
V_130 ,
V_203 ) ;
V_199 = & V_80 -> V_128 . V_190 . V_224 ;
memset ( V_199 , 0x00 , sizeof( * V_199 ) ) ;
V_199 -> V_192 . type = F_29 ( V_230 ) ;
V_199 -> V_192 . V_213 = F_46 ( sizeof( V_4 -> V_38 ) ) ;
V_199 -> V_210 = F_47 ( V_4 -> V_175 ) ;
F_14 ( V_4 -> V_122 -> V_123 , V_23 ) ;
if ( F_80 ( V_80 , V_4 , V_203 * 2 ) )
F_39 ( V_4 -> V_5 , L_47 ) ;
F_16 ( V_4 -> V_122 -> V_123 , V_23 ) ;
}
static void F_110 ( struct V_3 * V_4 )
{
F_109 ( V_4 ) ;
}
static void F_111 ( struct V_65 * V_80 )
{
if ( V_80 -> V_85 )
* V_80 -> V_85 = * V_80 -> V_69 ;
F_112 ( & V_80 -> V_231 ) ;
}
static int F_113 ( struct V_86 * V_87 )
{
struct V_3 * V_4 = F_94 ( V_87 -> V_99 -> V_122 ) ;
struct V_232 * V_233 ;
struct V_65 * V_66 ;
struct V_65 * V_146 , * V_234 ;
union V_235 V_154 ;
int V_236 ;
unsigned long V_23 ;
T_6 V_167 = F_92 ( V_87 -> V_99 ) ;
unsigned long V_237 = 0 ;
F_14 ( V_4 -> V_122 -> V_123 , V_23 ) ;
V_237 = V_150 + ( V_238 * V_151 ) ;
do {
V_234 = NULL ;
F_81 (tmp_evt, &hostdata->sent, list) {
if ( V_146 -> V_83 == V_87 ) {
V_234 = V_146 ;
break;
}
}
if ( ! V_234 ) {
F_16 ( V_4 -> V_122 -> V_123 , V_23 ) ;
return V_239 ;
}
V_66 = F_54 ( & V_4 -> V_58 ) ;
if ( V_66 == NULL ) {
F_16 ( V_4 -> V_122 -> V_123 , V_23 ) ;
F_69 ( V_79 , V_87 -> V_99 ,
L_48 ) ;
return V_240 ;
}
F_57 ( V_66 ,
F_111 ,
V_141 ,
V_241 ) ;
V_233 = & V_66 -> V_128 . V_129 . V_233 ;
memset ( V_233 , 0x00 , sizeof( * V_233 ) ) ;
V_233 -> V_132 = V_144 ;
F_95 ( V_167 , & V_233 -> V_167 ) ;
V_233 -> V_242 = V_243 ;
V_233 -> V_244 = ( T_2 ) V_234 ;
V_66 -> V_85 = & V_154 ;
F_114 ( & V_66 -> V_231 ) ;
V_236 = F_80 ( V_66 , V_4 , V_241 * 2 ) ;
if ( V_236 != V_153 )
break;
F_16 ( V_4 -> V_122 -> V_123 , V_23 ) ;
F_8 ( 10 ) ;
F_14 ( V_4 -> V_122 -> V_123 , V_23 ) ;
} while ( F_115 ( V_150 , V_237 ) );
F_16 ( V_4 -> V_122 -> V_123 , V_23 ) ;
if ( V_236 != 0 ) {
F_69 ( V_79 , V_87 -> V_99 ,
L_49 , V_236 ) ;
return V_240 ;
}
F_69 ( V_245 , V_87 -> V_99 ,
L_50 ,
( ( ( T_2 ) V_167 ) << 48 ) , ( T_2 ) V_234 ) ;
F_116 ( & V_66 -> V_231 ) ;
if ( F_88 ( V_154 . V_129 . V_147 . V_132 != V_155 ) ) {
if ( F_89 () )
F_69 ( V_246 , V_87 -> V_99 , L_51 ,
V_154 . V_129 . V_147 . V_132 ) ;
return V_240 ;
}
if ( V_154 . V_129 . V_147 . V_23 & V_247 )
V_236 = * ( ( int * ) V_154 . V_129 . V_147 . V_31 ) ;
else
V_236 = V_154 . V_129 . V_147 . V_156 ;
if ( V_236 ) {
if ( F_89 () )
F_69 ( V_246 , V_87 -> V_99 ,
L_52 ,
V_236 , V_233 -> V_244 ) ;
return V_240 ;
}
F_14 ( V_4 -> V_122 -> V_123 , V_23 ) ;
V_234 = NULL ;
F_81 (tmp_evt, &hostdata->sent, list) {
if ( V_146 -> V_83 == V_87 ) {
V_234 = V_146 ;
break;
}
}
if ( V_234 == NULL ) {
F_16 ( V_4 -> V_122 -> V_123 , V_23 ) ;
F_69 ( V_245 , V_87 -> V_99 , L_53 ,
V_233 -> V_244 ) ;
return V_239 ;
}
F_69 ( V_245 , V_87 -> V_99 , L_54 ,
V_233 -> V_244 ) ;
V_87 -> V_127 = ( V_248 << 16 ) ;
F_74 ( & V_234 -> V_125 ) ;
F_60 ( & V_234 -> V_128 . V_129 . V_87 , V_234 ,
V_234 -> V_4 -> V_5 ) ;
F_52 ( & V_234 -> V_4 -> V_58 , V_234 ) ;
F_16 ( V_4 -> V_122 -> V_123 , V_23 ) ;
F_86 ( & V_4 -> V_134 ) ;
return V_239 ;
}
static int F_117 ( struct V_86 * V_87 )
{
struct V_3 * V_4 = F_94 ( V_87 -> V_99 -> V_122 ) ;
struct V_232 * V_233 ;
struct V_65 * V_66 ;
struct V_65 * V_146 , * V_249 ;
union V_235 V_154 ;
int V_236 ;
unsigned long V_23 ;
T_6 V_167 = F_92 ( V_87 -> V_99 ) ;
unsigned long V_237 = 0 ;
F_14 ( V_4 -> V_122 -> V_123 , V_23 ) ;
V_237 = V_150 + ( V_238 * V_151 ) ;
do {
V_66 = F_54 ( & V_4 -> V_58 ) ;
if ( V_66 == NULL ) {
F_16 ( V_4 -> V_122 -> V_123 , V_23 ) ;
F_69 ( V_79 , V_87 -> V_99 ,
L_55 ) ;
return V_240 ;
}
F_57 ( V_66 ,
F_111 ,
V_141 ,
V_250 ) ;
V_233 = & V_66 -> V_128 . V_129 . V_233 ;
memset ( V_233 , 0x00 , sizeof( * V_233 ) ) ;
V_233 -> V_132 = V_144 ;
F_95 ( V_167 , & V_233 -> V_167 ) ;
V_233 -> V_242 = V_251 ;
V_66 -> V_85 = & V_154 ;
F_114 ( & V_66 -> V_231 ) ;
V_236 = F_80 ( V_66 , V_4 , V_250 * 2 ) ;
if ( V_236 != V_153 )
break;
F_16 ( V_4 -> V_122 -> V_123 , V_23 ) ;
F_8 ( 10 ) ;
F_14 ( V_4 -> V_122 -> V_123 , V_23 ) ;
} while ( F_115 ( V_150 , V_237 ) );
F_16 ( V_4 -> V_122 -> V_123 , V_23 ) ;
if ( V_236 != 0 ) {
F_69 ( V_79 , V_87 -> V_99 ,
L_56 , V_236 ) ;
return V_240 ;
}
F_69 ( V_245 , V_87 -> V_99 , L_57 ,
( ( ( T_2 ) V_167 ) << 48 ) ) ;
F_116 ( & V_66 -> V_231 ) ;
if ( F_88 ( V_154 . V_129 . V_147 . V_132 != V_155 ) ) {
if ( F_89 () )
F_69 ( V_246 , V_87 -> V_99 , L_58 ,
V_154 . V_129 . V_147 . V_132 ) ;
return V_240 ;
}
if ( V_154 . V_129 . V_147 . V_23 & V_247 )
V_236 = * ( ( int * ) V_154 . V_129 . V_147 . V_31 ) ;
else
V_236 = V_154 . V_129 . V_147 . V_156 ;
if ( V_236 ) {
if ( F_89 () )
F_69 ( V_246 , V_87 -> V_99 ,
L_59 ,
V_236 , V_233 -> V_244 ) ;
return V_240 ;
}
F_14 ( V_4 -> V_122 -> V_123 , V_23 ) ;
F_118 (tmp_evt, pos, &hostdata->sent, list) {
if ( ( V_146 -> V_83 ) && ( V_146 -> V_83 -> V_99 == V_87 -> V_99 ) ) {
if ( V_146 -> V_83 )
V_146 -> V_83 -> V_127 = ( V_252 << 16 ) ;
F_74 ( & V_146 -> V_125 ) ;
F_60 ( & V_146 -> V_128 . V_129 . V_87 , V_146 ,
V_146 -> V_4 -> V_5 ) ;
F_52 ( & V_146 -> V_4 -> V_58 ,
V_146 ) ;
F_86 ( & V_4 -> V_134 ) ;
if ( V_146 -> V_84 )
V_146 -> V_84 ( V_146 -> V_83 ) ;
else if ( V_146 -> V_32 )
V_146 -> V_32 ( V_146 ) ;
}
}
F_16 ( V_4 -> V_122 -> V_123 , V_23 ) ;
return V_239 ;
}
static int F_119 ( struct V_86 * V_87 )
{
unsigned long V_237 = 0 ;
struct V_3 * V_4 = F_94 ( V_87 -> V_99 -> V_122 ) ;
F_39 ( V_4 -> V_5 , L_60 ) ;
F_76 ( V_4 ) ;
for ( V_237 = V_150 + ( V_238 * V_151 ) ;
F_115 ( V_150 , V_237 ) &&
F_49 ( & V_4 -> V_134 ) < 2 ; ) {
F_8 ( 10 ) ;
}
if ( F_49 ( & V_4 -> V_134 ) <= 0 )
return V_240 ;
return V_239 ;
}
static void F_20 ( struct V_21 * V_22 ,
struct V_3 * V_4 )
{
long V_11 ;
unsigned long V_23 ;
struct V_65 * V_80 =
( V_253 struct V_65 * ) V_22 -> V_70 ;
switch ( V_22 -> V_26 ) {
case V_254 :
switch ( V_22 -> V_81 ) {
case V_255 :
F_28 ( V_4 -> V_5 , L_61 ) ;
V_11 = F_17 ( V_4 , 0xC002000000000000LL , 0 ) ;
if ( V_11 == 0 ) {
F_110 ( V_4 ) ;
} else {
F_39 ( V_4 -> V_5 , L_62 , V_11 ) ;
}
break;
case V_256 :
F_28 ( V_4 -> V_5 , L_63 ) ;
F_110 ( V_4 ) ;
break;
default:
F_39 ( V_4 -> V_5 , L_64 , V_22 -> V_81 ) ;
}
return;
case V_257 :
F_77 ( V_4 -> V_122 ) ;
F_45 ( & V_4 -> V_134 , 0 ) ;
if ( V_22 -> V_81 == 0x06 ) {
F_28 ( V_4 -> V_5 , L_65 ) ;
V_4 -> V_180 = 1 ;
V_4 -> V_258 = 1 ;
F_71 ( V_4 , V_259 ) ;
F_78 ( & V_4 -> V_137 ) ;
} else {
F_39 ( V_4 -> V_5 , L_66 ,
V_22 -> V_81 ) ;
F_76 ( V_4 ) ;
}
return;
case V_67 :
break;
default:
F_39 ( V_4 -> V_5 , L_67 ,
V_22 -> V_26 ) ;
return;
}
if ( ! F_51 ( & V_4 -> V_58 , V_80 ) ) {
F_39 ( V_4 -> V_5 , L_68 ,
V_80 ) ;
return;
}
if ( F_49 ( & V_80 -> free ) ) {
F_39 ( V_4 -> V_5 , L_69 ,
V_80 ) ;
return;
}
if ( V_22 -> V_81 == V_141 )
F_120 ( F_90 ( V_80 -> V_69 -> V_129 . V_147 . V_181 ) ,
& V_4 -> V_134 ) ;
F_75 ( & V_80 -> V_126 ) ;
if ( ( V_22 -> V_156 != V_260 && V_22 -> V_156 != V_261 ) && V_80 -> V_83 )
V_80 -> V_83 -> V_127 = V_135 << 16 ;
if ( V_80 -> V_32 )
V_80 -> V_32 ( V_80 ) ;
else
F_39 ( V_4 -> V_5 , L_70 ) ;
F_14 ( V_80 -> V_4 -> V_122 -> V_123 , V_23 ) ;
F_74 ( & V_80 -> V_125 ) ;
F_52 ( & V_80 -> V_4 -> V_58 , V_80 ) ;
F_16 ( V_80 -> V_4 -> V_122 -> V_123 , V_23 ) ;
}
static int F_121 ( struct V_164 * V_262 )
{
struct V_263 * V_264 = V_262 -> V_122 ;
unsigned long V_265 = 0 ;
F_14 ( V_264 -> V_123 , V_265 ) ;
if ( V_262 -> type == V_266 ) {
V_262 -> V_267 = 1 ;
F_122 ( V_262 -> V_268 , 120 * V_151 ) ;
}
F_16 ( V_264 -> V_123 , V_265 ) ;
return 0 ;
}
static int F_123 ( struct V_164 * V_262 , int V_269 )
{
if ( V_269 > V_270 )
V_269 = V_270 ;
return F_124 ( V_262 , V_269 ) ;
}
static T_7 F_125 ( struct V_99 * V_5 ,
struct V_271 * V_272 , char * V_273 )
{
struct V_263 * V_264 = F_126 ( V_5 ) ;
struct V_3 * V_4 = F_94 ( V_264 ) ;
int V_110 ;
V_110 = snprintf ( V_273 , sizeof( V_4 -> V_174 . V_208 ) , L_71 ,
V_4 -> V_174 . V_208 ) ;
return V_110 ;
}
static T_7 F_127 ( struct V_99 * V_5 ,
struct V_271 * V_272 , char * V_273 )
{
struct V_263 * V_264 = F_126 ( V_5 ) ;
struct V_3 * V_4 = F_94 ( V_264 ) ;
int V_110 ;
V_110 = snprintf ( V_273 , sizeof( V_4 -> V_174 . V_206 ) , L_71 ,
V_4 -> V_174 . V_206 ) ;
return V_110 ;
}
static T_7 F_128 ( struct V_99 * V_5 ,
struct V_271 * V_272 , char * V_273 )
{
struct V_263 * V_264 = F_126 ( V_5 ) ;
struct V_3 * V_4 = F_94 ( V_264 ) ;
int V_110 ;
V_110 = snprintf ( V_273 , V_45 , L_71 ,
V_4 -> V_38 . V_40 ) ;
return V_110 ;
}
static T_7 F_129 ( struct V_99 * V_5 ,
struct V_271 * V_272 ,
char * V_273 )
{
struct V_263 * V_264 = F_126 ( V_5 ) ;
struct V_3 * V_4 = F_94 ( V_264 ) ;
int V_110 ;
V_110 = snprintf ( V_273 , V_45 , L_71 ,
V_4 -> V_38 . V_36 ) ;
return V_110 ;
}
static T_7 F_130 ( struct V_99 * V_5 ,
struct V_271 * V_272 ,
char * V_273 )
{
struct V_263 * V_264 = F_126 ( V_5 ) ;
struct V_3 * V_4 = F_94 ( V_264 ) ;
int V_110 ;
V_110 = snprintf ( V_273 , V_45 , L_72 ,
F_90 ( V_4 -> V_38 . V_37 ) ) ;
return V_110 ;
}
static T_7 F_131 ( struct V_99 * V_5 ,
struct V_271 * V_272 , char * V_273 )
{
struct V_263 * V_264 = F_126 ( V_5 ) ;
struct V_3 * V_4 = F_94 ( V_264 ) ;
int V_110 ;
V_110 = snprintf ( V_273 , V_45 , L_72 ,
F_90 ( V_4 -> V_38 . V_41 ) ) ;
return V_110 ;
}
static T_7 F_132 ( struct V_99 * V_5 ,
struct V_271 * V_272 , char * V_273 )
{
struct V_263 * V_264 = F_126 ( V_5 ) ;
struct V_3 * V_4 = F_94 ( V_264 ) ;
int V_110 ;
V_110 = snprintf ( V_273 , V_45 , L_72 ,
F_90 ( V_4 -> V_38 . V_43 ) ) ;
return V_110 ;
}
static T_7 F_133 ( struct V_99 * V_5 ,
struct V_271 * V_272 , char * V_273 )
{
return 0 ;
}
static unsigned long F_134 ( struct V_12 * V_13 )
{
unsigned long V_274 = V_275 * sizeof( union V_235 ) ;
V_274 += ( V_276 * 512 *
V_277 ) ;
return V_274 ;
}
static void F_135 ( struct V_3 * V_4 )
{
int V_11 ;
char * V_278 = L_73 ;
if ( V_4 -> V_136 ) {
F_136 () ;
V_4 -> V_136 = 0 ;
V_11 = F_30 ( & V_4 -> V_9 , V_4 ) ;
if ( ! V_11 )
V_11 = F_17 ( V_4 , 0xC001000000000000LL , 0 ) ;
F_21 ( F_3 ( V_4 -> V_5 ) ) ;
} else if ( V_4 -> V_258 ) {
F_136 () ;
V_278 = L_74 ;
V_11 = F_40 ( & V_4 -> V_9 , V_4 ) ;
V_4 -> V_258 = 0 ;
if ( ! V_11 )
V_11 = F_17 ( V_4 , 0xC001000000000000LL , 0 ) ;
} else
return;
if ( V_11 ) {
F_45 ( & V_4 -> V_134 , - 1 ) ;
F_39 ( V_4 -> V_5 , L_75 , V_278 ) ;
}
F_99 ( V_4 -> V_122 ) ;
}
static int F_137 ( struct V_3 * V_4 )
{
if ( F_138 () )
return 1 ;
else if ( V_4 -> V_136 ) {
F_136 () ;
return 1 ;
} else if ( V_4 -> V_258 ) {
F_136 () ;
return 1 ;
}
return 0 ;
}
static int F_139 ( void * V_31 )
{
struct V_3 * V_4 = V_31 ;
int V_11 ;
F_140 ( V_279 , V_280 ) ;
while ( 1 ) {
V_11 = F_141 ( V_4 -> V_137 ,
F_137 ( V_4 ) ) ;
F_101 ( V_11 ) ;
if ( F_138 () )
break;
F_135 ( V_4 ) ;
}
return 0 ;
}
static int F_142 ( struct V_12 * V_13 , const struct V_281 * V_165 )
{
struct V_3 * V_4 ;
struct V_263 * V_122 ;
struct V_99 * V_5 = & V_13 -> V_5 ;
struct V_282 V_283 ;
struct V_284 * V_285 ;
unsigned long V_237 = 0 ;
int V_11 ;
F_143 ( & V_13 -> V_5 , NULL ) ;
V_122 = F_144 ( & V_286 , sizeof( * V_4 ) ) ;
if ( ! V_122 ) {
F_39 ( & V_13 -> V_5 , L_76 ) ;
goto V_287;
}
V_122 -> V_288 = V_289 ;
V_4 = F_94 ( V_122 ) ;
memset ( V_4 , 0x00 , sizeof( * V_4 ) ) ;
F_145 ( & V_4 -> V_124 ) ;
F_146 ( & V_4 -> V_137 ) ;
V_4 -> V_122 = V_122 ;
V_4 -> V_5 = V_5 ;
F_45 ( & V_4 -> V_134 , - 1 ) ;
V_4 -> V_122 -> V_226 = V_276 ;
if ( F_147 ( V_4 ) ) {
F_39 ( & V_13 -> V_5 , L_77 ) ;
goto V_290;
}
V_4 -> V_291 = F_148 ( F_139 , V_4 , L_78 ,
L_7 , V_122 -> V_292 ) ;
if ( F_149 ( V_4 -> V_291 ) ) {
F_39 ( & V_13 -> V_5 , L_79 ,
F_150 ( V_4 -> V_291 ) ) ;
goto V_293;
}
V_11 = F_32 ( & V_4 -> V_9 , V_4 , V_275 ) ;
if ( V_11 != 0 && V_11 != V_52 ) {
F_39 ( & V_13 -> V_5 , L_80 , V_11 ) ;
goto V_294;
}
if ( F_41 ( & V_4 -> V_58 , V_275 , V_4 ) != 0 ) {
F_39 ( & V_13 -> V_5 , L_81 ) ;
goto V_295;
}
V_122 -> V_296 = V_297 ;
V_122 -> V_298 = V_298 ;
V_122 -> V_299 = V_299 ;
V_122 -> V_300 = 16 ;
F_28 ( V_5 ,
L_82 ,
V_122 -> V_298 , V_122 -> V_296 , V_122 -> V_299 ) ;
if ( F_151 ( V_4 -> V_122 , V_4 -> V_5 ) )
goto V_301;
memcpy ( V_283 . V_302 , V_4 -> V_38 . V_36 ,
sizeof( V_283 . V_302 ) ) ;
V_283 . V_303 = V_304 ;
V_285 = F_152 ( V_122 , & V_283 ) ;
if ( F_149 ( V_285 ) )
goto V_305;
if ( F_17 ( V_4 , 0xC001000000000000LL , 0 ) == 0
|| V_11 == V_52 ) {
for ( V_237 = V_150 + ( V_238 * V_151 ) ;
F_115 ( V_150 , V_237 ) &&
F_49 ( & V_4 -> V_134 ) < 2 ; ) {
F_8 ( 10 ) ;
}
if ( F_49 ( & V_4 -> V_134 ) > 0 )
F_153 ( V_122 ) ;
}
F_143 ( & V_13 -> V_5 , V_4 ) ;
return 0 ;
V_305:
F_154 ( V_4 -> V_122 ) ;
V_301:
F_48 ( & V_4 -> V_58 , V_4 ) ;
V_295:
F_5 ( & V_4 -> V_9 , V_4 , V_275 ) ;
V_294:
F_155 ( V_4 -> V_291 ) ;
V_293:
F_97 ( V_4 ) ;
V_290:
F_156 ( V_122 ) ;
V_287:
return - 1 ;
}
static int F_157 ( struct V_12 * V_13 )
{
struct V_3 * V_4 = F_158 ( & V_13 -> V_5 ) ;
F_97 ( V_4 ) ;
F_48 ( & V_4 -> V_58 , V_4 ) ;
F_5 ( & V_4 -> V_9 , V_4 ,
V_275 ) ;
F_155 ( V_4 -> V_291 ) ;
F_159 ( V_4 -> V_122 ) ;
F_154 ( V_4 -> V_122 ) ;
F_156 ( V_4 -> V_122 ) ;
return 0 ;
}
static int F_160 ( struct V_99 * V_5 )
{
struct V_3 * V_4 = F_158 ( V_5 ) ;
F_2 ( F_3 ( V_4 -> V_5 ) ) ;
F_4 ( & V_4 -> V_6 ) ;
return 0 ;
}
int T_8 F_161 ( void )
{
int V_306 ;
V_286 . V_307 = V_10 ;
V_275 = V_10 + 2 ;
if ( ! F_68 ( V_308 ) )
return - V_309 ;
V_289 =
F_162 ( & V_310 ) ;
if ( ! V_289 )
return - V_62 ;
V_306 = F_163 ( & V_311 ) ;
if ( V_306 )
F_164 ( V_289 ) ;
return V_306 ;
}
void T_9 F_165 ( void )
{
F_166 ( & V_311 ) ;
F_164 ( V_289 ) ;
}
