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
if ( V_22 -> V_26 & 0x80 ) {
if ( ++ V_9 -> V_25 == V_9 -> V_18 )
V_9 -> V_25 = 0 ;
F_15 () ;
} else
V_22 = NULL ;
F_16 ( & V_9 -> V_24 , V_23 ) ;
return V_22 ;
}
static int F_17 ( struct V_3 * V_4 ,
T_2 V_27 , T_2 V_28 )
{
struct V_12 * V_13 = F_3 ( V_4 -> V_5 ) ;
F_18 () ;
return F_9 ( V_29 , V_13 -> V_15 , V_27 , V_28 ) ;
}
static void F_19 ( void * V_30 )
{
struct V_3 * V_4 = (struct V_3 * ) V_30 ;
struct V_12 * V_13 = F_3 ( V_4 -> V_5 ) ;
struct V_21 * V_22 ;
int V_31 = 0 ;
while ( ! V_31 ) {
while ( ( V_22 = F_13 ( & V_4 -> V_9 ) ) != NULL ) {
F_20 ( V_22 , V_4 ) ;
V_22 -> V_26 = 0x00 ;
}
F_21 ( V_13 ) ;
V_22 = F_13 ( & V_4 -> V_9 ) ;
if ( V_22 != NULL ) {
F_2 ( V_13 ) ;
F_20 ( V_22 , V_4 ) ;
V_22 -> V_26 = 0x00 ;
} else {
V_31 = 1 ;
}
}
}
static void F_22 ( void )
{
struct V_32 * V_33 ;
const char * V_34 ;
const T_3 * V_35 ;
V_33 = F_23 ( L_1 ) ;
if ( ! V_33 ) {
return;
}
V_34 = F_24 ( V_33 , L_2 , NULL ) ;
if ( V_34 )
strncpy ( V_36 , V_34 ,
sizeof( V_36 ) ) ;
V_35 = F_24 ( V_33 , L_3 , NULL ) ;
if ( V_35 )
V_37 = F_25 ( V_35 , 1 ) ;
F_26 ( V_33 ) ;
}
static void F_27 ( struct V_3 * V_4 )
{
memset ( & V_4 -> V_38 , 0x00 ,
sizeof( V_4 -> V_38 ) ) ;
F_28 ( V_4 -> V_5 , L_4 , V_39 ) ;
strcpy ( V_4 -> V_38 . V_40 , V_39 ) ;
strncpy ( V_4 -> V_38 . V_36 , V_36 ,
sizeof( V_4 -> V_38 . V_36 ) ) ;
V_4 -> V_38 . V_37 =
F_29 ( V_37 ) ;
V_4 -> V_38 . V_41 = F_29 ( 1 ) ;
V_4 -> V_38 . V_42 = F_29 ( 2 ) ;
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
memset ( V_9 -> V_19 , 0x00 , V_43 ) ;
V_9 -> V_25 = 0 ;
F_27 ( V_4 ) ;
V_11 = F_9 ( V_44 ,
V_13 -> V_15 ,
V_9 -> V_17 , V_43 ) ;
if ( V_11 == 2 ) {
F_31 ( V_4 -> V_5 , L_5 ) ;
} else if ( V_11 != 0 ) {
F_31 ( V_4 -> V_5 , L_6 , V_11 ) ;
}
return V_11 ;
}
static int F_32 ( struct V_8 * V_9 ,
struct V_3 * V_4 ,
int V_10 )
{
int V_11 ;
int V_45 ;
struct V_12 * V_13 = F_3 ( V_4 -> V_5 ) ;
V_9 -> V_19 = (struct V_21 * ) F_33 ( V_46 ) ;
if ( ! V_9 -> V_19 )
goto V_47;
V_9 -> V_18 = V_43 / sizeof( * V_9 -> V_19 ) ;
V_9 -> V_17 = F_34 ( V_4 -> V_5 , V_9 -> V_19 ,
V_9 -> V_18 * sizeof( * V_9 -> V_19 ) ,
V_20 ) ;
if ( F_35 ( V_4 -> V_5 , V_9 -> V_17 ) )
goto V_48;
F_22 () ;
F_27 ( V_4 ) ;
V_45 = V_11 = F_9 ( V_44 ,
V_13 -> V_15 ,
V_9 -> V_17 , V_43 ) ;
if ( V_11 == V_49 )
V_11 = F_30 ( V_9 ,
V_4 ) ;
if ( V_11 == 2 ) {
F_31 ( V_4 -> V_5 , L_5 ) ;
V_45 = 0 ;
} else if ( V_11 != 0 ) {
F_31 ( V_4 -> V_5 , L_7 , V_11 ) ;
goto V_50;
}
V_9 -> V_25 = 0 ;
F_36 ( & V_9 -> V_24 ) ;
F_37 ( & V_4 -> V_6 , ( void * ) F_19 ,
( unsigned long ) V_4 ) ;
if ( F_38 ( V_13 -> V_1 ,
F_1 ,
0 , L_8 , ( void * ) V_4 ) != 0 ) {
F_39 ( V_4 -> V_5 , L_9 ,
V_13 -> V_1 ) ;
goto V_51;
}
V_11 = F_21 ( V_13 ) ;
if ( V_11 != 0 ) {
F_39 ( V_4 -> V_5 , L_10 , V_11 ) ;
goto V_51;
}
return V_45 ;
V_51:
F_7 ( & V_4 -> V_6 ) ;
V_11 = 0 ;
do {
if ( V_11 )
F_8 ( 100 ) ;
V_11 = F_9 ( V_14 , V_13 -> V_15 ) ;
} while ( ( V_11 == V_16 ) || ( F_10 ( V_11 ) ) );
V_50:
F_11 ( V_4 -> V_5 ,
V_9 -> V_17 ,
V_9 -> V_18 * sizeof( * V_9 -> V_19 ) , V_20 ) ;
V_48:
F_12 ( ( unsigned long ) V_9 -> V_19 ) ;
V_47:
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
V_11 = F_9 ( V_52 , V_13 -> V_15 ) ;
} while ( ( V_11 == V_53 ) || ( V_11 == V_16 ) || ( F_10 ( V_11 ) ) );
if ( V_11 )
F_39 ( V_4 -> V_5 , L_11 , V_11 ) ;
return V_11 ;
}
static int F_41 ( struct V_54 * V_55 ,
int V_18 , struct V_3 * V_4 )
{
int V_56 ;
V_55 -> V_18 = V_18 ;
V_55 -> V_57 = 0 ;
V_55 -> V_58 = F_42 ( V_55 -> V_18 , sizeof( * V_55 -> V_58 ) , V_46 ) ;
if ( ! V_55 -> V_58 )
return - V_59 ;
V_55 -> V_60 =
F_43 ( V_4 -> V_5 ,
V_55 -> V_18 * sizeof( * V_55 -> V_60 ) ,
& V_55 -> V_61 , 0 ) ;
if ( ! V_55 -> V_60 ) {
F_44 ( V_55 -> V_58 ) ;
return - V_59 ;
}
for ( V_56 = 0 ; V_56 < V_55 -> V_18 ; ++ V_56 ) {
struct V_62 * V_63 = & V_55 -> V_58 [ V_56 ] ;
memset ( & V_63 -> V_22 , 0x00 , sizeof( V_63 -> V_22 ) ) ;
F_45 ( & V_63 -> free , 1 ) ;
V_63 -> V_22 . V_26 = 0x80 ;
V_63 -> V_22 . V_64 = F_46 ( sizeof( * V_63 -> V_65 ) ) ;
V_63 -> V_22 . V_66 = F_47 ( V_55 -> V_61 +
sizeof( * V_63 -> V_65 ) * V_56 ) ;
V_63 -> V_65 = V_55 -> V_60 + V_56 ;
V_63 -> V_4 = V_4 ;
V_63 -> V_67 = NULL ;
V_63 -> V_68 = 0 ;
}
return 0 ;
}
static void F_48 ( struct V_54 * V_55 ,
struct V_3 * V_4 )
{
int V_56 , V_69 = 0 ;
for ( V_56 = 0 ; V_56 < V_55 -> V_18 ; ++ V_56 ) {
if ( F_49 ( & V_55 -> V_58 [ V_56 ] . free ) != 1 )
++ V_69 ;
if ( V_55 -> V_58 [ V_56 ] . V_67 ) {
F_50 ( V_4 -> V_5 ,
V_70 * sizeof( struct V_71 ) ,
V_55 -> V_58 [ V_56 ] . V_67 ,
V_55 -> V_58 [ V_56 ] . V_68 ) ;
}
}
if ( V_69 )
F_31 ( V_4 -> V_5 , L_12
L_13 , V_69 ) ;
F_44 ( V_55 -> V_58 ) ;
F_50 ( V_4 -> V_5 ,
V_55 -> V_18 * sizeof( * V_55 -> V_60 ) ,
V_55 -> V_60 , V_55 -> V_61 ) ;
}
static int F_51 ( struct V_54 * V_55 ,
struct V_62 * V_63 )
{
int V_72 = V_63 - V_55 -> V_58 ;
if ( V_72 < 0 || V_72 >= V_55 -> V_18 )
return 0 ;
if ( V_63 != V_55 -> V_58 + V_72 )
return 0 ;
return 1 ;
}
static void F_52 ( struct V_54 * V_55 ,
struct V_62 * V_63 )
{
if ( ! F_51 ( V_55 , V_63 ) ) {
F_39 ( V_63 -> V_4 -> V_5 , L_14
L_15 , V_63 , V_55 -> V_58 ) ;
return;
}
if ( F_53 ( & V_63 -> free ) != 1 ) {
F_39 ( V_63 -> V_4 -> V_5 , L_16
L_17 , V_63 ) ;
return;
}
}
static struct V_62 * F_54 ( struct V_54 * V_55 )
{
int V_56 ;
int V_73 = V_55 -> V_18 ;
int V_74 = V_55 -> V_57 ;
for ( V_56 = 0 ; V_56 < V_73 ; V_56 ++ ) {
V_74 = ( V_74 + 1 ) % V_73 ;
if ( ! F_55 ( & V_55 -> V_58 [ V_74 ] . free ) ) {
V_55 -> V_57 = V_74 ;
return & V_55 -> V_58 [ V_74 ] ;
}
}
F_56 ( V_75 L_18 ) ;
return NULL ;
}
static void F_57 ( struct V_62 * V_76 ,
void (* V_31) ( struct V_62 * ) ,
T_4 V_77 ,
int V_78 )
{
V_76 -> V_79 = NULL ;
V_76 -> V_80 = NULL ;
V_76 -> V_81 = NULL ;
V_76 -> V_22 . V_77 = V_77 ;
V_76 -> V_22 . V_78 = F_46 ( V_78 ) ;
V_76 -> V_31 = V_31 ;
}
static void F_58 ( struct V_82 * V_83 ,
struct V_84 * V_84 ,
int V_85 )
{
T_4 V_86 ;
if ( V_85 == 0 )
return;
if ( V_85 == 1 )
V_86 = V_87 ;
else {
V_86 = V_88 ;
V_85 = F_59 ( V_85 , V_89 ) ;
if ( V_83 -> V_90 == V_91 )
V_84 -> V_92 = V_85 ;
else
V_84 -> V_93 = V_85 ;
}
if ( V_83 -> V_90 == V_91 )
V_84 -> V_94 = V_86 << 4 ;
else
V_84 -> V_94 = V_86 ;
}
static void F_60 ( struct V_84 * V_83 ,
struct V_62 * V_76 ,
struct V_95 * V_5 )
{
T_4 V_96 , V_97 ;
V_96 = V_83 -> V_94 >> 4 ;
V_97 = V_83 -> V_94 & ( ( 1U << 4 ) - 1 ) ;
if ( V_96 == V_98 && V_97 == V_98 )
return;
if ( V_76 -> V_79 )
F_61 ( V_76 -> V_79 ) ;
}
static int F_62 ( struct V_82 * V_83 , int V_99 ,
struct V_71 * V_100 )
{
int V_56 ;
struct V_101 * V_102 ;
T_2 V_103 = 0 ;
F_63 (cmd, sg, nseg, i) {
struct V_71 * V_104 = V_100 + V_56 ;
V_104 -> V_105 = F_47 ( F_64 ( V_102 ) ) ;
V_104 -> V_106 = F_29 ( F_65 ( V_102 ) ) ;
V_104 -> V_107 = 0 ;
V_103 += F_65 ( V_102 ) ;
}
return V_103 ;
}
static int F_66 ( struct V_82 * V_83 ,
struct V_62 * V_76 ,
struct V_84 * V_84 , struct V_95 * V_5 )
{
int V_108 ;
T_2 V_103 = 0 ;
struct V_71 * V_30 =
(struct V_71 * ) V_84 -> V_109 ;
struct V_110 * V_111 =
(struct V_110 * ) V_30 ;
V_108 = F_67 ( V_83 ) ;
if ( ! V_108 )
return 1 ;
else if ( V_108 < 0 )
return 0 ;
F_58 ( V_83 , V_84 , V_108 ) ;
if ( V_108 == 1 ) {
F_62 ( V_83 , V_108 , V_30 ) ;
return 1 ;
}
V_111 -> V_112 . V_105 = 0 ;
V_111 -> V_112 . V_106 = F_29 ( V_108 *
sizeof( struct V_71 ) ) ;
V_111 -> V_112 . V_107 = 0 ;
if ( V_108 <= V_89 ) {
V_103 = F_62 ( V_83 , V_108 ,
& V_111 -> V_113 [ 0 ] ) ;
V_111 -> V_106 = F_29 ( V_103 ) ;
return 1 ;
}
if ( ! V_76 -> V_67 ) {
V_76 -> V_67 = (struct V_71 * )
F_43 ( V_5 ,
V_70 * sizeof( struct V_71 ) ,
& V_76 -> V_68 , 0 ) ;
if ( ! V_76 -> V_67 ) {
if ( ! F_68 ( V_114 ) )
F_69 ( V_75 , V_83 -> V_95 ,
L_19
L_20 ) ;
F_61 ( V_83 ) ;
return 0 ;
}
}
V_103 = F_62 ( V_83 , V_108 , V_76 -> V_67 ) ;
V_111 -> V_106 = F_29 ( V_103 ) ;
V_111 -> V_112 . V_105 = F_47 ( V_76 -> V_68 ) ;
V_111 -> V_112 . V_106 = F_29 ( V_108 *
sizeof( V_111 -> V_113 [ 0 ] ) ) ;
memcpy ( V_111 -> V_113 , V_76 -> V_67 ,
V_89 * sizeof( struct V_71 ) ) ;
return 1 ;
}
static int F_70 ( struct V_82 * V_83 ,
struct V_62 * V_76 ,
struct V_84 * V_84 , struct V_95 * V_5 )
{
switch ( V_83 -> V_90 ) {
case V_115 :
case V_91 :
break;
case V_116 :
return 1 ;
case V_20 :
F_69 ( V_75 , V_83 -> V_95 ,
L_21 ) ;
return 0 ;
default:
F_69 ( V_75 , V_83 -> V_95 ,
L_22 ,
V_83 -> V_90 ) ;
return 0 ;
}
return F_66 ( V_83 , V_76 , V_84 , V_5 ) ;
}
static void F_71 ( struct V_3 * V_4 , int V_117 )
{
struct V_62 * V_63 ;
unsigned long V_23 ;
F_14 ( V_4 -> V_118 -> V_119 , V_23 ) ;
while ( ! F_72 ( & V_4 -> V_120 ) ) {
V_63 = F_73 ( & V_4 -> V_120 , struct V_62 , V_121 ) ;
F_74 ( & V_63 -> V_121 ) ;
F_75 ( & V_63 -> V_122 ) ;
F_16 ( V_4 -> V_118 -> V_119 , V_23 ) ;
if ( V_63 -> V_79 ) {
V_63 -> V_79 -> V_123 = ( V_117 << 16 ) ;
F_60 ( & V_63 -> V_124 . V_125 . V_83 , V_63 ,
V_63 -> V_4 -> V_5 ) ;
if ( V_63 -> V_80 )
V_63 -> V_80 ( V_63 -> V_79 ) ;
} else if ( V_63 -> V_31 && V_63 -> V_22 . V_77 != V_126 &&
V_63 -> V_124 . V_125 . V_127 . V_128 != V_129 )
V_63 -> V_31 ( V_63 ) ;
F_52 ( & V_63 -> V_4 -> V_55 , V_63 ) ;
F_14 ( V_4 -> V_118 -> V_119 , V_23 ) ;
}
F_16 ( V_4 -> V_118 -> V_119 , V_23 ) ;
}
static void F_76 ( struct V_3 * V_4 )
{
F_77 ( V_4 -> V_118 ) ;
F_45 ( & V_4 -> V_130 , 0 ) ;
F_71 ( V_4 , V_131 ) ;
V_4 -> V_132 = 1 ;
F_78 ( & V_4 -> V_133 ) ;
}
static void F_79 ( struct V_62 * V_76 )
{
struct V_3 * V_4 = V_76 -> V_4 ;
F_39 ( V_4 -> V_5 , L_23 ,
V_76 -> V_124 . V_125 . V_83 . V_128 ) ;
F_76 ( V_4 ) ;
}
static int F_80 ( struct V_62 * V_76 ,
struct V_3 * V_4 ,
unsigned long V_78 )
{
T_5 * V_134 = ( T_5 * ) & V_76 -> V_22 ;
int V_135 = 0 ;
int V_11 ;
int V_136 = 0 ;
if ( V_76 -> V_22 . V_77 == V_137 ) {
V_136 = 1 ;
V_135 =
F_55 ( & V_4 -> V_130 ) ;
if ( V_135 < - 1 )
goto V_138;
else if ( V_135 == - 1 &&
V_76 -> V_124 . V_125 . V_127 . V_128 != V_129 )
goto V_139;
else if ( V_135 < 2 &&
V_76 -> V_124 . V_125 . V_83 . V_128 != V_140 ) {
int V_141 = V_135 ;
struct V_62 * V_142 ;
F_81 (tmp_evt, &hostdata->sent, list) {
V_141 ++ ;
}
if ( V_141 > 2 )
goto V_139;
}
}
* V_76 -> V_65 = V_76 -> V_124 ;
V_76 -> V_65 -> V_125 . V_143 . V_144 = ( T_2 ) V_76 ;
F_82 ( & V_76 -> V_121 , & V_4 -> V_120 ) ;
F_83 ( & V_76 -> V_122 ) ;
if ( V_78 ) {
V_76 -> V_122 . V_30 = ( unsigned long ) V_76 ;
V_76 -> V_122 . V_145 = V_146 + ( V_78 * V_147 ) ;
V_76 -> V_122 . V_148 = ( void (*) ( unsigned long ) ) F_79 ;
F_84 ( & V_76 -> V_122 ) ;
}
V_11 = F_17 ( V_4 , F_85 ( V_134 [ 0 ] ) ,
F_85 ( V_134 [ 1 ] ) ) ;
if ( V_11 != 0 ) {
F_74 ( & V_76 -> V_121 ) ;
F_75 ( & V_76 -> V_122 ) ;
if ( V_11 == V_149 ) {
F_31 ( V_4 -> V_5 , L_24
L_25 ) ;
goto V_139;
}
F_39 ( V_4 -> V_5 , L_26 , V_11 ) ;
if ( V_136 )
F_86 ( & V_4 -> V_130 ) ;
goto V_138;
}
return 0 ;
V_139:
F_60 ( & V_76 -> V_124 . V_125 . V_83 , V_76 , V_4 -> V_5 ) ;
F_52 ( & V_4 -> V_55 , V_76 ) ;
if ( V_136 && V_135 != - 1 )
F_86 ( & V_4 -> V_130 ) ;
return V_150 ;
V_138:
F_60 ( & V_76 -> V_124 . V_125 . V_83 , V_76 , V_4 -> V_5 ) ;
if ( V_76 -> V_79 != NULL ) {
V_76 -> V_79 -> V_123 = V_131 << 16 ;
V_76 -> V_80 ( V_76 -> V_79 ) ;
} else if ( V_76 -> V_31 )
V_76 -> V_31 ( V_76 ) ;
F_52 ( & V_4 -> V_55 , V_76 ) ;
return 0 ;
}
static void F_87 ( struct V_62 * V_76 )
{
struct V_151 * V_143 = & V_76 -> V_65 -> V_125 . V_143 ;
struct V_82 * V_79 = V_76 -> V_79 ;
if ( F_88 ( V_143 -> V_128 != V_152 ) ) {
if ( F_89 () )
F_31 ( V_76 -> V_4 -> V_5 ,
L_27 , V_143 -> V_128 ) ;
}
if ( V_79 ) {
V_79 -> V_123 |= V_143 -> V_153 ;
if ( ( ( V_79 -> V_123 >> 1 ) & 0x1f ) == V_154 )
memcpy ( V_79 -> V_155 ,
V_143 -> V_30 ,
F_90 ( V_143 -> V_156 ) ) ;
F_60 ( & V_76 -> V_124 . V_125 . V_83 ,
V_76 ,
V_76 -> V_4 -> V_5 ) ;
if ( V_143 -> V_23 & V_157 )
F_91 ( V_79 ,
F_90 ( V_143 -> V_158 ) ) ;
else if ( V_143 -> V_23 & V_159 )
F_91 ( V_79 , F_90 ( V_143 -> V_160 ) ) ;
}
if ( V_76 -> V_80 )
V_76 -> V_80 ( V_79 ) ;
}
static inline T_6 F_92 ( struct V_161 * V_5 )
{
return ( 0x2 << 14 ) | ( V_5 -> V_162 << 8 ) | ( V_5 -> V_163 << 5 ) | V_5 -> V_164 ;
}
static int F_93 ( struct V_82 * V_79 ,
void (* V_31) ( struct V_82 * ) )
{
struct V_84 * V_84 ;
struct V_62 * V_76 ;
struct V_110 * V_111 ;
struct V_3 * V_4 = F_94 ( V_79 -> V_95 -> V_118 ) ;
T_6 V_164 = F_92 ( V_79 -> V_95 ) ;
T_4 V_96 , V_97 ;
V_79 -> V_123 = ( V_165 << 16 ) ;
V_76 = F_54 ( & V_4 -> V_55 ) ;
if ( ! V_76 )
return V_150 ;
V_84 = & V_76 -> V_124 . V_125 . V_83 ;
memset ( V_84 , 0x00 , V_166 ) ;
V_84 -> V_128 = V_167 ;
memcpy ( V_84 -> V_168 , V_79 -> V_79 , sizeof( V_84 -> V_168 ) ) ;
F_95 ( V_164 , & V_84 -> V_164 ) ;
if ( ! F_70 ( V_79 , V_76 , V_84 , V_4 -> V_5 ) ) {
if ( ! F_68 ( V_114 ) )
F_69 ( V_75 , V_79 -> V_95 ,
L_28 ) ;
F_52 ( & V_4 -> V_55 , V_76 ) ;
return V_150 ;
}
F_57 ( V_76 ,
F_87 ,
V_137 ,
V_79 -> V_169 -> V_78 / V_147 ) ;
V_76 -> V_79 = V_79 ;
V_76 -> V_80 = V_31 ;
V_111 = (struct V_110 * ) V_84 -> V_109 ;
V_96 = V_84 -> V_94 >> 4 ;
V_97 = V_84 -> V_94 & ( ( 1U << 4 ) - 1 ) ;
if ( ( V_97 == V_88 ||
V_96 == V_88 ) &&
V_111 -> V_112 . V_105 == 0 ) {
V_111 -> V_112 . V_105 =
F_47 ( F_85 ( V_76 -> V_22 . V_66 ) +
F_96 ( struct V_84 , V_109 ) +
F_96 ( struct V_110 , V_113 ) ) ;
}
return F_80 ( V_76 , V_4 , 0 ) ;
}
void F_97 ( struct V_3 * V_4 )
{
F_11 ( V_4 -> V_5 , V_4 -> V_170 ,
sizeof( V_4 -> V_171 ) , V_20 ) ;
F_11 ( V_4 -> V_5 , V_4 -> V_172 ,
sizeof( V_4 -> V_38 ) , V_20 ) ;
}
static void F_98 ( struct V_62 * V_76 )
{
struct V_3 * V_4 = V_76 -> V_4 ;
switch ( V_76 -> V_65 -> V_125 . F_98 . V_128 ) {
case V_173 :
break;
case V_174 :
F_28 ( V_4 -> V_5 , L_29 ,
V_76 -> V_65 -> V_125 . V_175 . V_176 ) ;
F_45 ( & V_4 -> V_130 , - 1 ) ;
return;
default:
F_39 ( V_4 -> V_5 , L_30 ,
V_76 -> V_65 -> V_125 . F_98 . V_128 ) ;
F_45 ( & V_4 -> V_130 , - 1 ) ;
return;
}
F_28 ( V_4 -> V_5 , L_31 ) ;
V_4 -> V_177 = 0 ;
F_45 ( & V_4 -> V_130 ,
F_90 ( V_76 -> V_65 -> V_125 . F_98 . V_178 ) ) ;
F_99 ( V_4 -> V_118 ) ;
}
static int F_100 ( struct V_3 * V_4 )
{
int V_11 ;
unsigned long V_23 ;
struct V_179 * V_180 ;
struct V_62 * V_76 = F_54 ( & V_4 -> V_55 ) ;
F_101 ( ! V_76 ) ;
F_57 ( V_76 , F_98 ,
V_137 , V_181 ) ;
V_180 = & V_76 -> V_124 . V_125 . V_127 ;
memset ( V_180 , 0 , sizeof( * V_180 ) ) ;
V_180 -> V_128 = V_129 ;
V_180 -> V_182 = F_29 ( sizeof( union V_183 ) ) ;
V_180 -> V_184 = F_46 ( V_185 |
V_186 ) ;
F_14 ( V_4 -> V_118 -> V_119 , V_23 ) ;
F_45 ( & V_4 -> V_130 , 0 ) ;
V_11 = F_80 ( V_76 , V_4 , V_181 * 2 ) ;
F_16 ( V_4 -> V_118 -> V_119 , V_23 ) ;
F_28 ( V_4 -> V_5 , L_32 ) ;
return V_11 ;
}
static void F_102 ( struct V_62 * V_76 )
{
struct V_3 * V_4 = V_76 -> V_4 ;
if ( V_76 -> V_65 -> V_187 . V_188 . V_189 . V_153 ) {
F_39 ( V_4 -> V_5 , L_33 ,
V_76 -> V_65 -> V_187 . V_188 . V_189 . V_153 ) ;
} else {
if ( V_4 -> V_171 . V_190 . V_189 . V_191 !=
F_46 ( V_192 ) )
F_28 ( V_4 -> V_5 , L_34 ) ;
if ( V_193 ) {
if ( V_4 -> V_171 . V_194 . V_189 . V_191 ==
F_46 ( V_192 ) )
F_28 ( V_4 -> V_5 , L_35 ) ;
else
F_28 ( V_4 -> V_5 , L_36 ) ;
}
}
F_100 ( V_4 ) ;
}
static void F_103 ( struct V_3 * V_4 )
{
struct V_195 * V_196 ;
struct V_62 * V_76 ;
unsigned long V_23 ;
struct V_32 * V_197 = V_4 -> V_5 -> V_197 ;
const char * V_198 ;
V_76 = F_54 ( & V_4 -> V_55 ) ;
F_101 ( ! V_76 ) ;
F_57 ( V_76 , F_102 ,
V_126 , V_199 ) ;
V_196 = & V_76 -> V_124 . V_187 . V_188 ;
memset ( V_196 , 0 , sizeof( * V_196 ) ) ;
V_4 -> V_171 . V_23 = F_29 ( V_200 ) ;
if ( V_4 -> V_177 )
V_4 -> V_171 . V_23 |= F_29 ( V_201 ) ;
strncpy ( V_4 -> V_171 . V_202 , F_104 ( & V_4 -> V_118 -> V_203 ) ,
sizeof( V_4 -> V_171 . V_202 ) ) ;
V_4 -> V_171 . V_202 [ sizeof( V_4 -> V_171 . V_202 ) - 1 ] = '\0' ;
V_198 = F_24 ( V_197 , L_37 , NULL ) ;
V_198 = V_198 ? V_198 : F_104 ( V_4 -> V_5 ) ;
strncpy ( V_4 -> V_171 . V_204 , V_198 , sizeof( V_4 -> V_171 . V_204 ) ) ;
V_4 -> V_171 . V_204 [ sizeof( V_4 -> V_171 . V_204 ) - 1 ] = '\0' ;
V_196 -> V_189 . type = F_29 ( V_205 ) ;
V_196 -> V_206 = F_47 ( V_4 -> V_170 ) ;
V_4 -> V_171 . V_190 . V_189 . V_207 =
F_29 ( V_208 ) ;
V_4 -> V_171 . V_190 . V_189 . V_209 =
F_46 ( sizeof( V_4 -> V_171 . V_190 ) ) ;
V_4 -> V_171 . V_190 . V_189 . V_191 =
F_46 ( V_192 ) ;
V_4 -> V_171 . V_190 . V_210 = F_29 ( 1 ) ;
if ( V_193 ) {
V_4 -> V_171 . V_194 . V_189 . V_207 =
F_29 ( V_211 ) ;
V_4 -> V_171 . V_194 . V_189 . V_209 =
F_46 ( sizeof( V_4 -> V_171 . V_194 ) ) ;
V_4 -> V_171 . V_194 . V_189 . V_191 =
F_46 ( V_192 ) ;
V_4 -> V_171 . V_194 . type =
F_29 ( V_212 ) ;
V_196 -> V_189 . V_209 =
F_46 ( sizeof( V_4 -> V_171 ) ) ;
} else
V_196 -> V_189 . V_209 = F_46 ( sizeof( V_4 -> V_171 ) -
sizeof( V_4 -> V_171 . V_194 ) ) ;
F_14 ( V_4 -> V_118 -> V_119 , V_23 ) ;
if ( F_80 ( V_76 , V_4 , V_199 * 2 ) )
F_39 ( V_4 -> V_5 , L_38 ) ;
F_16 ( V_4 -> V_118 -> V_119 , V_23 ) ;
}
static void F_105 ( struct V_62 * V_76 )
{
struct V_3 * V_4 = V_76 -> V_4 ;
T_6 V_153 = F_106 ( V_76 -> V_65 -> V_187 . V_213 . V_189 . V_153 ) ;
if ( V_153 == V_214 )
F_39 ( V_4 -> V_5 , L_39 ) ;
else if ( V_153 == V_215 )
F_39 ( V_4 -> V_5 , L_40 ) ;
else if ( V_153 != V_216 )
F_39 ( V_4 -> V_5 , L_41 , V_153 ) ;
F_103 ( V_4 ) ;
}
static int F_107 ( struct V_3 * V_4 )
{
int V_11 ;
unsigned long V_23 ;
struct V_217 * V_218 ;
struct V_62 * V_76 ;
if ( ! V_213 ) {
F_103 ( V_4 ) ;
return 0 ;
}
V_76 = F_54 ( & V_4 -> V_55 ) ;
F_101 ( ! V_76 ) ;
F_57 ( V_76 , F_105 , V_126 , V_199 ) ;
V_218 = & V_76 -> V_124 . V_187 . V_213 ;
memset ( V_218 , 0 , sizeof( * V_218 ) ) ;
V_218 -> V_189 . type = F_29 ( V_219 ) ;
V_218 -> V_189 . V_209 = F_46 ( sizeof( * V_218 ) ) ;
F_14 ( V_4 -> V_118 -> V_119 , V_23 ) ;
V_11 = F_80 ( V_76 , V_4 , V_199 * 2 ) ;
F_16 ( V_4 -> V_118 -> V_119 , V_23 ) ;
return V_11 ;
}
static void F_108 ( struct V_62 * V_76 )
{
struct V_3 * V_4 = V_76 -> V_4 ;
if ( V_76 -> V_65 -> V_187 . V_220 . V_189 . V_153 ) {
F_39 ( V_4 -> V_5 , L_42 ,
V_76 -> V_65 -> V_187 . V_220 . V_189 . V_153 ) ;
} else {
F_28 ( V_4 -> V_5 , L_43
L_44 ,
V_4 -> V_38 . V_40 ,
V_4 -> V_38 . V_36 ,
F_90 ( V_4 -> V_38 . V_37 ) ,
F_90 ( V_4 -> V_38 . V_42 ) ,
F_90 ( V_4 -> V_38 . V_221 [ 0 ] ) ) ;
if ( V_4 -> V_38 . V_221 [ 0 ] )
V_4 -> V_118 -> V_222 =
F_90 ( V_4 -> V_38 . V_221 [ 0 ] ) >> 9 ;
if ( F_90 ( V_4 -> V_38 . V_42 ) == 3 &&
strcmp ( V_4 -> V_38 . V_40 , L_45 ) <= 0 ) {
F_39 ( V_4 -> V_5 , L_46 ,
V_4 -> V_38 . V_40 ) ;
F_39 ( V_4 -> V_5 , L_47 ,
V_89 ) ;
V_4 -> V_118 -> V_223 = V_89 ;
}
if ( F_90 ( V_4 -> V_38 . V_42 ) == 3 ) {
F_107 ( V_4 ) ;
return;
}
}
F_100 ( V_4 ) ;
}
static void F_109 ( struct V_3 * V_4 )
{
struct V_224 * V_196 ;
struct V_62 * V_76 ;
unsigned long V_23 ;
V_76 = F_54 ( & V_4 -> V_55 ) ;
F_101 ( ! V_76 ) ;
F_57 ( V_76 ,
F_108 ,
V_126 ,
V_199 ) ;
V_196 = & V_76 -> V_124 . V_187 . V_220 ;
memset ( V_196 , 0x00 , sizeof( * V_196 ) ) ;
V_196 -> V_189 . type = F_29 ( V_225 ) ;
V_196 -> V_189 . V_209 = F_46 ( sizeof( V_4 -> V_38 ) ) ;
V_196 -> V_206 = F_47 ( V_4 -> V_172 ) ;
F_14 ( V_4 -> V_118 -> V_119 , V_23 ) ;
if ( F_80 ( V_76 , V_4 , V_199 * 2 ) )
F_39 ( V_4 -> V_5 , L_48 ) ;
F_16 ( V_4 -> V_118 -> V_119 , V_23 ) ;
}
static void F_110 ( struct V_3 * V_4 )
{
F_109 ( V_4 ) ;
}
static void F_111 ( struct V_62 * V_76 )
{
if ( V_76 -> V_81 )
* V_76 -> V_81 = * V_76 -> V_65 ;
F_112 ( & V_76 -> V_226 ) ;
}
static int F_113 ( struct V_82 * V_83 )
{
struct V_3 * V_4 = F_94 ( V_83 -> V_95 -> V_118 ) ;
struct V_227 * V_228 ;
struct V_62 * V_63 ;
struct V_62 * V_142 , * V_229 ;
union V_230 V_151 ;
int V_231 ;
unsigned long V_23 ;
T_6 V_164 = F_92 ( V_83 -> V_95 ) ;
unsigned long V_232 = 0 ;
F_14 ( V_4 -> V_118 -> V_119 , V_23 ) ;
V_232 = V_146 + ( V_233 * V_147 ) ;
do {
V_229 = NULL ;
F_81 (tmp_evt, &hostdata->sent, list) {
if ( V_142 -> V_79 == V_83 ) {
V_229 = V_142 ;
break;
}
}
if ( ! V_229 ) {
F_16 ( V_4 -> V_118 -> V_119 , V_23 ) ;
return V_234 ;
}
V_63 = F_54 ( & V_4 -> V_55 ) ;
if ( V_63 == NULL ) {
F_16 ( V_4 -> V_118 -> V_119 , V_23 ) ;
F_69 ( V_75 , V_83 -> V_95 ,
L_49 ) ;
return V_235 ;
}
F_57 ( V_63 ,
F_111 ,
V_137 ,
V_236 ) ;
V_228 = & V_63 -> V_124 . V_125 . V_228 ;
memset ( V_228 , 0x00 , sizeof( * V_228 ) ) ;
V_228 -> V_128 = V_140 ;
F_95 ( V_164 , & V_228 -> V_164 ) ;
V_228 -> V_237 = V_238 ;
V_228 -> V_239 = ( T_2 ) V_229 ;
V_63 -> V_81 = & V_151 ;
F_114 ( & V_63 -> V_226 ) ;
V_231 = F_80 ( V_63 , V_4 , V_236 * 2 ) ;
if ( V_231 != V_150 )
break;
F_16 ( V_4 -> V_118 -> V_119 , V_23 ) ;
F_8 ( 10 ) ;
F_14 ( V_4 -> V_118 -> V_119 , V_23 ) ;
} while ( F_115 ( V_146 , V_232 ) );
F_16 ( V_4 -> V_118 -> V_119 , V_23 ) ;
if ( V_231 != 0 ) {
F_69 ( V_75 , V_83 -> V_95 ,
L_50 , V_231 ) ;
return V_235 ;
}
F_69 ( V_240 , V_83 -> V_95 ,
L_51 ,
( ( ( T_2 ) V_164 ) << 48 ) , ( T_2 ) V_229 ) ;
F_116 ( & V_63 -> V_226 ) ;
if ( F_88 ( V_151 . V_125 . V_143 . V_128 != V_152 ) ) {
if ( F_89 () )
F_69 ( V_241 , V_83 -> V_95 , L_52 ,
V_151 . V_125 . V_143 . V_128 ) ;
return V_235 ;
}
if ( V_151 . V_125 . V_143 . V_23 & V_242 )
V_231 = * ( ( int * ) V_151 . V_125 . V_143 . V_30 ) ;
else
V_231 = V_151 . V_125 . V_143 . V_153 ;
if ( V_231 ) {
if ( F_89 () )
F_69 ( V_241 , V_83 -> V_95 ,
L_53 ,
V_231 , V_228 -> V_239 ) ;
return V_235 ;
}
F_14 ( V_4 -> V_118 -> V_119 , V_23 ) ;
V_229 = NULL ;
F_81 (tmp_evt, &hostdata->sent, list) {
if ( V_142 -> V_79 == V_83 ) {
V_229 = V_142 ;
break;
}
}
if ( V_229 == NULL ) {
F_16 ( V_4 -> V_118 -> V_119 , V_23 ) ;
F_69 ( V_240 , V_83 -> V_95 , L_54 ,
V_228 -> V_239 ) ;
return V_234 ;
}
F_69 ( V_240 , V_83 -> V_95 , L_55 ,
V_228 -> V_239 ) ;
V_83 -> V_123 = ( V_243 << 16 ) ;
F_74 ( & V_229 -> V_121 ) ;
F_60 ( & V_229 -> V_124 . V_125 . V_83 , V_229 ,
V_229 -> V_4 -> V_5 ) ;
F_52 ( & V_229 -> V_4 -> V_55 , V_229 ) ;
F_16 ( V_4 -> V_118 -> V_119 , V_23 ) ;
F_86 ( & V_4 -> V_130 ) ;
return V_234 ;
}
static int F_117 ( struct V_82 * V_83 )
{
struct V_3 * V_4 = F_94 ( V_83 -> V_95 -> V_118 ) ;
struct V_227 * V_228 ;
struct V_62 * V_63 ;
struct V_62 * V_142 , * V_244 ;
union V_230 V_151 ;
int V_231 ;
unsigned long V_23 ;
T_6 V_164 = F_92 ( V_83 -> V_95 ) ;
unsigned long V_232 = 0 ;
F_14 ( V_4 -> V_118 -> V_119 , V_23 ) ;
V_232 = V_146 + ( V_233 * V_147 ) ;
do {
V_63 = F_54 ( & V_4 -> V_55 ) ;
if ( V_63 == NULL ) {
F_16 ( V_4 -> V_118 -> V_119 , V_23 ) ;
F_69 ( V_75 , V_83 -> V_95 ,
L_56 ) ;
return V_235 ;
}
F_57 ( V_63 ,
F_111 ,
V_137 ,
V_245 ) ;
V_228 = & V_63 -> V_124 . V_125 . V_228 ;
memset ( V_228 , 0x00 , sizeof( * V_228 ) ) ;
V_228 -> V_128 = V_140 ;
F_95 ( V_164 , & V_228 -> V_164 ) ;
V_228 -> V_237 = V_246 ;
V_63 -> V_81 = & V_151 ;
F_114 ( & V_63 -> V_226 ) ;
V_231 = F_80 ( V_63 , V_4 , V_245 * 2 ) ;
if ( V_231 != V_150 )
break;
F_16 ( V_4 -> V_118 -> V_119 , V_23 ) ;
F_8 ( 10 ) ;
F_14 ( V_4 -> V_118 -> V_119 , V_23 ) ;
} while ( F_115 ( V_146 , V_232 ) );
F_16 ( V_4 -> V_118 -> V_119 , V_23 ) ;
if ( V_231 != 0 ) {
F_69 ( V_75 , V_83 -> V_95 ,
L_57 , V_231 ) ;
return V_235 ;
}
F_69 ( V_240 , V_83 -> V_95 , L_58 ,
( ( ( T_2 ) V_164 ) << 48 ) ) ;
F_116 ( & V_63 -> V_226 ) ;
if ( F_88 ( V_151 . V_125 . V_143 . V_128 != V_152 ) ) {
if ( F_89 () )
F_69 ( V_241 , V_83 -> V_95 , L_59 ,
V_151 . V_125 . V_143 . V_128 ) ;
return V_235 ;
}
if ( V_151 . V_125 . V_143 . V_23 & V_242 )
V_231 = * ( ( int * ) V_151 . V_125 . V_143 . V_30 ) ;
else
V_231 = V_151 . V_125 . V_143 . V_153 ;
if ( V_231 ) {
if ( F_89 () )
F_69 ( V_241 , V_83 -> V_95 ,
L_60 ,
V_231 , V_228 -> V_239 ) ;
return V_235 ;
}
F_14 ( V_4 -> V_118 -> V_119 , V_23 ) ;
F_118 (tmp_evt, pos, &hostdata->sent, list) {
if ( ( V_142 -> V_79 ) && ( V_142 -> V_79 -> V_95 == V_83 -> V_95 ) ) {
if ( V_142 -> V_79 )
V_142 -> V_79 -> V_123 = ( V_247 << 16 ) ;
F_74 ( & V_142 -> V_121 ) ;
F_60 ( & V_142 -> V_124 . V_125 . V_83 , V_142 ,
V_142 -> V_4 -> V_5 ) ;
F_52 ( & V_142 -> V_4 -> V_55 ,
V_142 ) ;
F_86 ( & V_4 -> V_130 ) ;
if ( V_142 -> V_80 )
V_142 -> V_80 ( V_142 -> V_79 ) ;
else if ( V_142 -> V_31 )
V_142 -> V_31 ( V_142 ) ;
}
}
F_16 ( V_4 -> V_118 -> V_119 , V_23 ) ;
return V_234 ;
}
static int F_119 ( struct V_82 * V_83 )
{
unsigned long V_232 = 0 ;
struct V_3 * V_4 = F_94 ( V_83 -> V_95 -> V_118 ) ;
F_39 ( V_4 -> V_5 , L_61 ) ;
F_76 ( V_4 ) ;
for ( V_232 = V_146 + ( V_233 * V_147 ) ;
F_115 ( V_146 , V_232 ) &&
F_49 ( & V_4 -> V_130 ) < 2 ; ) {
F_8 ( 10 ) ;
}
if ( F_49 ( & V_4 -> V_130 ) <= 0 )
return V_235 ;
return V_234 ;
}
static void F_20 ( struct V_21 * V_22 ,
struct V_3 * V_4 )
{
long V_11 ;
unsigned long V_23 ;
struct V_62 * V_76 =
( V_248 struct V_62 * ) V_22 -> V_66 ;
switch ( V_22 -> V_26 ) {
case 0xC0 :
switch ( V_22 -> V_77 ) {
case 0x01 :
F_28 ( V_4 -> V_5 , L_62 ) ;
V_11 = F_17 ( V_4 , 0xC002000000000000LL , 0 ) ;
if ( V_11 == 0 ) {
F_110 ( V_4 ) ;
} else {
F_39 ( V_4 -> V_5 , L_63 , V_11 ) ;
}
break;
case 0x02 :
F_28 ( V_4 -> V_5 , L_64 ) ;
F_110 ( V_4 ) ;
break;
default:
F_39 ( V_4 -> V_5 , L_65 , V_22 -> V_77 ) ;
}
return;
case 0xFF :
F_77 ( V_4 -> V_118 ) ;
F_45 ( & V_4 -> V_130 , 0 ) ;
if ( V_22 -> V_77 == 0x06 ) {
F_28 ( V_4 -> V_5 , L_66 ) ;
V_4 -> V_177 = 1 ;
V_4 -> V_249 = 1 ;
F_71 ( V_4 , V_250 ) ;
F_78 ( & V_4 -> V_133 ) ;
} else {
F_39 ( V_4 -> V_5 , L_67 ,
V_22 -> V_77 ) ;
F_76 ( V_4 ) ;
}
return;
case 0x80 :
break;
default:
F_39 ( V_4 -> V_5 , L_68 ,
V_22 -> V_26 ) ;
return;
}
if ( ! F_51 ( & V_4 -> V_55 , V_76 ) ) {
F_39 ( V_4 -> V_5 , L_69 ,
V_76 ) ;
return;
}
if ( F_49 ( & V_76 -> free ) ) {
F_39 ( V_4 -> V_5 , L_70 ,
V_76 ) ;
return;
}
if ( V_22 -> V_77 == V_137 )
F_120 ( F_90 ( V_76 -> V_65 -> V_125 . V_143 . V_178 ) ,
& V_4 -> V_130 ) ;
F_75 ( & V_76 -> V_122 ) ;
if ( ( V_22 -> V_153 != V_251 && V_22 -> V_153 != V_252 ) && V_76 -> V_79 )
V_76 -> V_79 -> V_123 = V_131 << 16 ;
if ( V_76 -> V_31 )
V_76 -> V_31 ( V_76 ) ;
else
F_39 ( V_4 -> V_5 , L_71 ) ;
F_14 ( V_76 -> V_4 -> V_118 -> V_119 , V_23 ) ;
F_74 ( & V_76 -> V_121 ) ;
F_52 ( & V_76 -> V_4 -> V_55 , V_76 ) ;
F_16 ( V_76 -> V_4 -> V_118 -> V_119 , V_23 ) ;
}
static int F_121 ( struct V_3 * V_4 ,
unsigned char * V_206 , int V_209 )
{
struct V_253 * V_254 ;
struct V_62 * V_76 ;
unsigned long V_23 ;
T_7 V_255 ;
int V_11 ;
V_76 = F_54 ( & V_4 -> V_55 ) ;
if ( ! V_76 ) {
F_39 ( V_4 -> V_5 , L_72 ) ;
return - 1 ;
}
F_57 ( V_76 ,
F_111 ,
V_126 ,
V_199 ) ;
V_254 = & V_76 -> V_124 . V_187 . V_254 ;
V_209 = F_59 ( 0xffff , V_209 ) ;
memset ( V_254 , 0x00 , sizeof( * V_254 ) ) ;
V_254 -> V_189 . type = F_29 ( V_256 ) ;
V_254 -> V_189 . V_209 = F_46 ( V_209 ) ;
V_255 = F_34 ( V_4 -> V_5 , V_206 , V_209 , V_20 ) ;
if ( F_35 ( V_4 -> V_5 , V_255 ) ) {
if ( ! F_68 ( V_114 ) )
F_39 ( V_4 -> V_5 ,
L_73 ) ;
F_52 ( & V_4 -> V_55 , V_76 ) ;
return - 1 ;
}
V_254 -> V_206 = F_47 ( V_255 ) ;
F_114 ( & V_76 -> V_226 ) ;
F_14 ( V_4 -> V_118 -> V_119 , V_23 ) ;
V_11 = F_80 ( V_76 , V_4 , V_199 * 2 ) ;
F_16 ( V_4 -> V_118 -> V_119 , V_23 ) ;
if ( V_11 == 0 )
F_116 ( & V_76 -> V_226 ) ;
F_11 ( V_4 -> V_5 , V_255 , V_209 , V_20 ) ;
return V_11 ;
}
static int F_122 ( struct V_161 * V_257 )
{
struct V_258 * V_259 = V_257 -> V_118 ;
unsigned long V_260 = 0 ;
F_14 ( V_259 -> V_119 , V_260 ) ;
if ( V_257 -> type == V_261 ) {
V_257 -> V_262 = 1 ;
F_123 ( V_257 -> V_263 , 120 * V_147 ) ;
}
F_16 ( V_259 -> V_119 , V_260 ) ;
return 0 ;
}
static int F_124 ( struct V_161 * V_257 , int V_264 )
{
if ( V_264 > V_265 )
V_264 = V_265 ;
return F_125 ( V_257 , V_264 ) ;
}
static T_8 F_126 ( struct V_95 * V_5 ,
struct V_266 * V_267 , char * V_268 )
{
struct V_258 * V_259 = F_127 ( V_5 ) ;
struct V_3 * V_4 = F_94 ( V_259 ) ;
int V_106 ;
V_106 = snprintf ( V_268 , sizeof( V_4 -> V_171 . V_204 ) , L_74 ,
V_4 -> V_171 . V_204 ) ;
return V_106 ;
}
static T_8 F_128 ( struct V_95 * V_5 ,
struct V_266 * V_267 , char * V_268 )
{
struct V_258 * V_259 = F_127 ( V_5 ) ;
struct V_3 * V_4 = F_94 ( V_259 ) ;
int V_106 ;
V_106 = snprintf ( V_268 , sizeof( V_4 -> V_171 . V_202 ) , L_74 ,
V_4 -> V_171 . V_202 ) ;
return V_106 ;
}
static T_8 F_129 ( struct V_95 * V_5 ,
struct V_266 * V_267 , char * V_268 )
{
struct V_258 * V_259 = F_127 ( V_5 ) ;
struct V_3 * V_4 = F_94 ( V_259 ) ;
int V_106 ;
V_106 = snprintf ( V_268 , V_43 , L_74 ,
V_4 -> V_38 . V_40 ) ;
return V_106 ;
}
static T_8 F_130 ( struct V_95 * V_5 ,
struct V_266 * V_267 ,
char * V_268 )
{
struct V_258 * V_259 = F_127 ( V_5 ) ;
struct V_3 * V_4 = F_94 ( V_259 ) ;
int V_106 ;
V_106 = snprintf ( V_268 , V_43 , L_74 ,
V_4 -> V_38 . V_36 ) ;
return V_106 ;
}
static T_8 F_131 ( struct V_95 * V_5 ,
struct V_266 * V_267 ,
char * V_268 )
{
struct V_258 * V_259 = F_127 ( V_5 ) ;
struct V_3 * V_4 = F_94 ( V_259 ) ;
int V_106 ;
V_106 = snprintf ( V_268 , V_43 , L_75 ,
V_4 -> V_38 . V_37 ) ;
return V_106 ;
}
static T_8 F_132 ( struct V_95 * V_5 ,
struct V_266 * V_267 , char * V_268 )
{
struct V_258 * V_259 = F_127 ( V_5 ) ;
struct V_3 * V_4 = F_94 ( V_259 ) ;
int V_106 ;
V_106 = snprintf ( V_268 , V_43 , L_75 ,
V_4 -> V_38 . V_41 ) ;
return V_106 ;
}
static T_8 F_133 ( struct V_95 * V_5 ,
struct V_266 * V_267 , char * V_268 )
{
struct V_258 * V_259 = F_127 ( V_5 ) ;
struct V_3 * V_4 = F_94 ( V_259 ) ;
int V_106 ;
V_106 = snprintf ( V_268 , V_43 , L_75 , V_4 -> V_38 . V_42 ) ;
return V_106 ;
}
static T_8 F_134 ( struct V_95 * V_5 ,
struct V_266 * V_267 , char * V_268 )
{
struct V_258 * V_259 = F_127 ( V_5 ) ;
struct V_3 * V_4 = F_94 ( V_259 ) ;
if ( F_121 ( V_4 , V_268 , V_43 ) == 0 )
return strlen ( V_268 ) ;
else
return 0 ;
}
static unsigned long F_135 ( struct V_12 * V_13 )
{
unsigned long V_269 = V_270 * sizeof( union V_230 ) ;
V_269 += ( V_271 * 512 *
V_272 ) ;
return V_269 ;
}
static void F_136 ( struct V_3 * V_4 )
{
int V_11 ;
char * V_273 = L_76 ;
if ( V_4 -> V_132 ) {
F_137 () ;
V_4 -> V_132 = 0 ;
V_11 = F_30 ( & V_4 -> V_9 , V_4 ) ;
if ( ! V_11 )
V_11 = F_17 ( V_4 , 0xC001000000000000LL , 0 ) ;
F_21 ( F_3 ( V_4 -> V_5 ) ) ;
} else if ( V_4 -> V_249 ) {
F_137 () ;
V_273 = L_77 ;
V_11 = F_40 ( & V_4 -> V_9 , V_4 ) ;
V_4 -> V_249 = 0 ;
if ( ! V_11 )
V_11 = F_17 ( V_4 , 0xC001000000000000LL , 0 ) ;
} else
return;
if ( V_11 ) {
F_45 ( & V_4 -> V_130 , - 1 ) ;
F_39 ( V_4 -> V_5 , L_78 , V_273 ) ;
}
F_99 ( V_4 -> V_118 ) ;
}
static int F_138 ( struct V_3 * V_4 )
{
if ( F_139 () )
return 1 ;
else if ( V_4 -> V_132 ) {
F_137 () ;
return 1 ;
} else if ( V_4 -> V_249 ) {
F_137 () ;
return 1 ;
}
return 0 ;
}
static int F_140 ( void * V_30 )
{
struct V_3 * V_4 = V_30 ;
int V_11 ;
F_141 ( V_274 , V_275 ) ;
while ( 1 ) {
V_11 = F_142 ( V_4 -> V_133 ,
F_138 ( V_4 ) ) ;
F_101 ( V_11 ) ;
if ( F_139 () )
break;
F_136 ( V_4 ) ;
}
return 0 ;
}
static int F_143 ( struct V_12 * V_13 , const struct V_276 * V_162 )
{
struct V_3 * V_4 ;
struct V_258 * V_118 ;
struct V_95 * V_5 = & V_13 -> V_5 ;
struct V_277 V_278 ;
struct V_279 * V_280 ;
unsigned long V_232 = 0 ;
int V_11 ;
F_144 ( & V_13 -> V_5 , NULL ) ;
V_118 = F_145 ( & V_281 , sizeof( * V_4 ) ) ;
if ( ! V_118 ) {
F_39 ( & V_13 -> V_5 , L_79 ) ;
goto V_282;
}
V_118 -> V_283 = V_284 ;
V_4 = F_94 ( V_118 ) ;
memset ( V_4 , 0x00 , sizeof( * V_4 ) ) ;
F_146 ( & V_4 -> V_120 ) ;
F_147 ( & V_4 -> V_133 ) ;
V_4 -> V_118 = V_118 ;
V_4 -> V_5 = V_5 ;
F_45 ( & V_4 -> V_130 , - 1 ) ;
V_4 -> V_118 -> V_222 = V_271 ;
if ( F_148 ( V_4 ) ) {
F_39 ( & V_13 -> V_5 , L_80 ) ;
goto V_285;
}
V_4 -> V_286 = F_149 ( F_140 , V_4 , L_81 ,
L_8 , V_118 -> V_287 ) ;
if ( F_150 ( V_4 -> V_286 ) ) {
F_39 ( & V_13 -> V_5 , L_82 ,
F_151 ( V_4 -> V_286 ) ) ;
goto V_288;
}
V_11 = F_32 ( & V_4 -> V_9 , V_4 , V_270 ) ;
if ( V_11 != 0 && V_11 != V_49 ) {
F_39 ( & V_13 -> V_5 , L_83 , V_11 ) ;
goto V_289;
}
if ( F_41 ( & V_4 -> V_55 , V_270 , V_4 ) != 0 ) {
F_39 ( & V_13 -> V_5 , L_84 ) ;
goto V_290;
}
V_118 -> V_291 = V_292 ;
V_118 -> V_293 = V_293 ;
V_118 -> V_294 = V_294 ;
V_118 -> V_295 = 16 ;
F_28 ( V_5 ,
L_85 ,
V_118 -> V_293 , V_118 -> V_291 , V_118 -> V_294 ) ;
if ( F_152 ( V_4 -> V_118 , V_4 -> V_5 ) )
goto V_296;
memcpy ( V_278 . V_297 , V_4 -> V_38 . V_36 ,
sizeof( V_278 . V_297 ) ) ;
V_278 . V_298 = V_299 ;
V_280 = F_153 ( V_118 , & V_278 ) ;
if ( F_150 ( V_280 ) )
goto V_300;
if ( F_17 ( V_4 , 0xC001000000000000LL , 0 ) == 0
|| V_11 == V_49 ) {
for ( V_232 = V_146 + ( V_233 * V_147 ) ;
F_115 ( V_146 , V_232 ) &&
F_49 ( & V_4 -> V_130 ) < 2 ; ) {
F_8 ( 10 ) ;
}
if ( F_49 ( & V_4 -> V_130 ) > 0 )
F_154 ( V_118 ) ;
}
F_144 ( & V_13 -> V_5 , V_4 ) ;
return 0 ;
V_300:
F_155 ( V_4 -> V_118 ) ;
V_296:
F_48 ( & V_4 -> V_55 , V_4 ) ;
V_290:
F_5 ( & V_4 -> V_9 , V_4 , V_270 ) ;
V_289:
F_156 ( V_4 -> V_286 ) ;
V_288:
F_97 ( V_4 ) ;
V_285:
F_157 ( V_118 ) ;
V_282:
return - 1 ;
}
static int F_158 ( struct V_12 * V_13 )
{
struct V_3 * V_4 = F_159 ( & V_13 -> V_5 ) ;
F_97 ( V_4 ) ;
F_48 ( & V_4 -> V_55 , V_4 ) ;
F_5 ( & V_4 -> V_9 , V_4 ,
V_270 ) ;
F_156 ( V_4 -> V_286 ) ;
F_160 ( V_4 -> V_118 ) ;
F_155 ( V_4 -> V_118 ) ;
F_157 ( V_4 -> V_118 ) ;
return 0 ;
}
static int F_161 ( struct V_95 * V_5 )
{
struct V_3 * V_4 = F_159 ( V_5 ) ;
F_2 ( F_3 ( V_4 -> V_5 ) ) ;
F_4 ( & V_4 -> V_6 ) ;
return 0 ;
}
int T_9 F_162 ( void )
{
int V_301 ;
V_281 . V_302 = V_10 ;
V_270 = V_10 + 2 ;
if ( ! F_68 ( V_303 ) )
return - V_304 ;
V_284 =
F_163 ( & V_305 ) ;
if ( ! V_284 )
return - V_59 ;
V_301 = F_164 ( & V_306 ) ;
if ( V_301 )
F_165 ( V_284 ) ;
return V_301 ;
}
void T_10 F_166 ( void )
{
F_167 ( & V_306 ) ;
F_165 ( V_284 ) ;
}
