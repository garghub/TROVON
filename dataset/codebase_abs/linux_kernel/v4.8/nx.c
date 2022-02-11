int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
int V_6 , V_7 = 10 ;
struct V_8 * V_9 = V_10 . V_9 ;
F_2 ( & ( V_2 -> V_11 -> V_12 ) ) ;
do {
V_6 = F_3 ( V_9 , V_4 ) ;
} while ( V_6 == - V_13 && ! V_5 && V_7 -- );
if ( V_6 ) {
F_4 ( & V_9 -> V_14 , L_1
L_2 , V_6 , V_4 -> V_15 ) ;
F_2 ( & ( V_2 -> V_11 -> V_16 ) ) ;
F_5 ( & ( V_2 -> V_11 -> V_17 ) , V_4 -> V_15 ) ;
F_5 ( & ( V_2 -> V_11 -> V_18 ) , V_19 -> V_20 ) ;
}
return V_6 ;
}
struct V_21 * F_6 ( struct V_21 * V_22 ,
T_2 * V_23 ,
unsigned int * V_24 ,
T_1 V_25 )
{
unsigned int V_26 = 0 ;
struct V_21 * V_27 ;
T_3 V_28 = ( T_3 ) V_23 ;
T_3 V_29 ;
if ( F_7 ( V_23 ) )
V_28 = F_8 ( F_9 ( V_23 ) )
+ F_10 ( V_28 ) ;
else
V_28 = F_11 ( V_28 ) ;
V_29 = V_28 + * V_24 ;
for ( V_27 = V_22 ; V_26 < * V_24 ; V_27 ++ ) {
T_3 V_30 ;
V_27 -> V_31 = V_28 ;
V_28 = F_12 ( T_3 , F_13 ( V_28 + V_32 ) ,
V_29 ) ;
V_30 = ( V_27 -> V_31 & V_33 ) + V_34 ;
V_27 -> V_24 = F_12 ( T_3 , V_28 , V_30 ) - V_27 -> V_31 ;
V_26 += V_27 -> V_24 ;
if ( V_28 >= V_30 &&
F_7 ( V_23 + V_26 ) ) {
V_28 = F_8 ( F_9 (
V_23 + V_26 ) ) ;
V_29 = V_28 + * V_24 - V_26 ;
}
if ( ( V_27 - V_22 ) == V_25 ) {
F_14 ( L_3 ,
V_19 -> V_20 ) ;
V_27 ++ ;
break;
}
}
* V_24 = V_26 ;
return V_27 ;
}
struct V_21 * F_15 ( struct V_21 * V_35 ,
unsigned int V_36 ,
struct V_37 * V_38 ,
unsigned int V_39 ,
unsigned int * V_40 )
{
struct V_41 V_42 ;
struct V_21 * V_21 = V_35 ;
unsigned int V_43 , V_44 = 0 , V_24 = * V_40 ;
char * V_45 ;
for (; ; ) {
F_16 ( & V_42 , V_38 ) ;
if ( V_39 < V_44 + V_38 -> V_46 )
break;
V_44 += V_38 -> V_46 ;
V_38 = F_17 ( V_38 ) ;
}
F_18 ( & V_42 , V_39 - V_44 ) ;
while ( V_24 && ( V_21 - V_35 ) < V_36 ) {
V_43 = F_19 ( & V_42 , V_24 ) ;
if ( ! V_43 ) {
F_16 ( & V_42 , F_17 ( V_42 . V_27 ) ) ;
V_43 = F_19 ( & V_42 , V_24 ) ;
}
V_45 = F_20 ( & V_42 ) ;
V_21 = F_6 ( V_21 , V_45 , & V_43 , V_36 - ( V_21 - V_35 ) ) ;
V_24 -= V_43 ;
F_21 ( V_45 ) ;
F_18 ( & V_42 , V_43 ) ;
F_22 ( & V_42 , V_47 , V_24 ) ;
}
* V_40 -= V_24 ;
return V_21 ;
}
static long int F_23 ( struct V_21 * V_27 ,
struct V_21 * V_48 ,
unsigned int V_49 ,
unsigned int * V_50 )
{
long int V_51 ;
long int V_52 ;
unsigned int V_53 = V_49 ;
while ( V_49 && V_48 > V_27 ) {
struct V_21 * V_54 = V_48 - 1 ;
if ( V_54 -> V_24 > V_49 ) {
V_54 -> V_24 -= V_49 ;
V_49 = 0 ;
} else {
V_48 -- ;
V_49 -= V_54 -> V_24 ;
}
}
V_51 = ( V_27 - V_48 ) * sizeof( struct V_21 ) ;
if ( V_53 ) {
V_52 = ( abs ( V_51 ) / V_55 ) * V_27 -> V_24 ;
V_52 = * V_50 - ( V_52 & ~ ( V_55 - 1 ) ) ;
* V_50 -= V_52 ;
}
return V_51 ;
}
int F_24 ( struct V_1 * V_2 ,
struct V_56 * V_57 ,
struct V_37 * V_45 ,
struct V_37 * V_58 ,
unsigned int * V_50 ,
unsigned int V_44 ,
T_2 * V_59 )
{
unsigned int V_49 = 0 ;
unsigned int V_60 = * V_50 ;
struct V_21 * V_61 = V_2 -> V_62 ;
struct V_21 * V_63 = V_2 -> V_64 ;
unsigned int V_65 ;
V_65 = F_12 ( T_3 , V_2 -> V_66 -> V_36 ,
V_10 . V_67 . V_65 / sizeof( struct V_21 ) ) ;
V_65 = F_12 ( T_3 , V_65 ,
V_2 -> V_66 -> V_68 / V_32 ) ;
if ( V_59 )
memcpy ( V_59 , V_57 -> V_69 , V_55 ) ;
* V_50 = F_12 ( T_3 , * V_50 , V_2 -> V_66 -> V_68 ) ;
V_63 = F_15 ( V_63 , V_65 , V_45 ,
V_44 , V_50 ) ;
V_61 = F_15 ( V_61 , V_65 , V_58 ,
V_44 , V_50 ) ;
if ( * V_50 < V_60 )
V_49 = * V_50 - ( * V_50 & ~ ( V_55 - 1 ) ) ;
V_2 -> V_4 . V_70 = F_23 ( V_2 -> V_62 , V_61 , V_49 , V_50 ) ;
V_2 -> V_4 . V_71 = F_23 ( V_2 -> V_64 , V_63 , V_49 , V_50 ) ;
return 0 ;
}
void F_25 ( struct V_1 * V_2 , unsigned int V_72 )
{
F_26 ( & V_2 -> V_73 ) ;
memset ( V_2 -> V_74 , 0 , V_2 -> V_75 ) ;
V_2 -> V_76 -> V_77 . V_78 |= V_79 ;
V_2 -> V_4 . V_80 = V_72 ;
V_2 -> V_4 . V_76 = F_11 ( V_2 -> V_76 ) ;
V_2 -> V_4 . V_81 = F_11 ( V_2 -> V_62 ) ;
V_2 -> V_4 . V_82 = F_11 ( V_2 -> V_64 ) ;
if ( V_2 -> V_83 ) {
V_2 -> V_83 -> V_77 . V_78 |= V_79 ;
V_2 -> V_84 . V_80 = V_72 ;
V_2 -> V_84 . V_76 = F_11 ( V_2 -> V_83 ) ;
V_2 -> V_84 . V_81 = F_11 ( V_2 -> V_62 ) ;
V_2 -> V_84 . V_82 = F_11 ( V_2 -> V_64 ) ;
}
}
static void F_27 ( struct V_85 * V_14 ,
struct V_86 * V_87 ,
struct V_88 * V_89 )
{
if ( ! strncmp ( V_87 -> V_90 , L_4 , V_87 -> V_46 ) ) {
V_89 -> V_91 = V_92 ;
V_89 -> V_80 |= V_93 ;
} else {
F_28 ( V_14 , L_5 , V_94 ,
( char * ) V_87 -> V_90 ) ;
}
}
static void F_29 ( struct V_85 * V_14 ,
struct V_86 * V_87 ,
struct V_88 * V_89 )
{
if ( V_87 -> V_46 != sizeof( V_89 -> V_65 ) ) {
F_30 ( V_14 , L_6
L_7 , V_94 ) ;
F_4 ( V_14 , L_8
L_9 , V_94 ,
V_87 -> V_46 , sizeof( V_89 -> V_65 ) ) ;
return;
}
V_89 -> V_65 = * ( T_1 * ) V_87 -> V_90 ;
V_89 -> V_80 |= V_95 ;
}
static void F_31 ( struct V_85 * V_14 ,
struct V_86 * V_87 ,
struct V_88 * V_89 )
{
struct V_96 * V_97 ;
struct V_98 * V_99 ;
unsigned int V_100 , V_101 , V_102 ;
V_99 = (struct V_98 * ) V_87 -> V_90 ;
V_102 = V_87 -> V_46 ;
V_100 = 0 ;
while ( ( V_100 + sizeof( struct V_98 ) ) <= V_102 ) {
V_100 += sizeof( struct V_98 ) ;
V_97 = V_99 -> V_97 ;
for ( V_101 = 0 ;
( ( V_100 + sizeof( struct V_96 ) ) <= V_102 ) &&
V_101 < V_99 -> V_103 ;
V_101 ++ ) {
if ( V_99 -> V_104 >= V_105 || V_99 -> V_106 >= V_107 ) {
F_30 ( V_14 , L_10
L_11 , V_99 -> V_104 ,
V_99 -> V_106 ) ;
goto V_108;
}
if ( ! V_97 -> V_36 || V_97 -> V_68 < V_32 ) {
F_32 ( V_14 , L_12
L_13 , V_97 -> V_36 ,
V_97 -> V_68 ) ;
goto V_108;
}
switch ( V_97 -> V_109 ) {
case 128 :
case 160 :
V_89 -> V_66 [ V_99 -> V_104 ] [ V_99 -> V_106 ] [ 0 ] . V_68 =
V_97 -> V_68 ;
V_89 -> V_66 [ V_99 -> V_104 ] [ V_99 -> V_106 ] [ 0 ] . V_36 =
V_97 -> V_36 ;
break;
case 192 :
V_89 -> V_66 [ V_99 -> V_104 ] [ V_99 -> V_106 ] [ 1 ] . V_68 =
V_97 -> V_68 ;
V_89 -> V_66 [ V_99 -> V_104 ] [ V_99 -> V_106 ] [ 1 ] . V_36 =
V_97 -> V_36 ;
break;
case 256 :
if ( V_99 -> V_104 == V_110 ) {
V_89 -> V_66 [ V_99 -> V_104 ] [ V_99 -> V_106 ] [ 2 ] .
V_68 = V_97 -> V_68 ;
V_89 -> V_66 [ V_99 -> V_104 ] [ V_99 -> V_106 ] [ 2 ] . V_36 =
V_97 -> V_36 ;
} else if ( V_99 -> V_104 == V_111 ||
V_99 -> V_104 == V_112 ) {
V_89 -> V_66 [ V_99 -> V_104 ] [ V_99 -> V_106 ] [ 1 ] .
V_68 = V_97 -> V_68 ;
V_89 -> V_66 [ V_99 -> V_104 ] [ V_99 -> V_106 ] [ 1 ] . V_36 =
V_97 -> V_36 ;
} else {
F_32 ( V_14 , L_14
L_15
L_16 , V_99 -> V_104 ) ;
}
break;
case 512 :
V_89 -> V_66 [ V_99 -> V_104 ] [ V_99 -> V_106 ] [ 2 ] . V_68 =
V_97 -> V_68 ;
V_89 -> V_66 [ V_99 -> V_104 ] [ V_99 -> V_106 ] [ 2 ] . V_36 =
V_97 -> V_36 ;
break;
default:
F_32 ( V_14 , L_17
L_18 , V_99 -> V_104 ,
V_97 -> V_109 ) ;
break;
}
V_108:
V_100 += sizeof( struct V_96 ) ;
V_97 ++ ;
}
V_99 = (struct V_98 * ) V_97 ;
}
V_89 -> V_80 |= V_113 ;
}
static void F_33 ( struct V_85 * V_14 , struct V_88 * V_89 )
{
struct V_114 * V_115 = V_14 -> V_116 ;
struct V_86 * V_87 ;
V_87 = F_34 ( V_115 , L_19 , NULL ) ;
if ( ! V_87 )
F_28 ( V_14 , L_20 , V_94 ) ;
else
F_27 ( V_14 , V_87 , V_89 ) ;
V_87 = F_34 ( V_115 , L_21 , NULL ) ;
if ( ! V_87 )
F_28 ( V_14 , L_22 ,
V_94 ) ;
else
F_29 ( V_14 , V_87 , V_89 ) ;
V_87 = F_34 ( V_115 , L_23 , NULL ) ;
if ( ! V_87 )
F_28 ( V_14 , L_24 ,
V_94 ) ;
else
F_31 ( V_14 , V_87 , V_89 ) ;
}
static bool F_35 ( struct V_85 * V_14 , T_1 V_104 , T_1 V_106 , int V_117 )
{
struct V_118 * V_89 = & V_10 . V_67 . V_66 [ V_104 ] [ V_106 ] [ V_117 ] ;
if ( ! V_89 -> V_36 || V_89 -> V_68 < V_32 ) {
if ( V_14 )
F_32 ( V_14 , L_25
L_13 , V_104 , V_106 , V_117 ,
V_89 -> V_36 , V_89 -> V_68 ) ;
return false ;
}
return true ;
}
static bool F_36 ( struct V_85 * V_14 , T_1 V_104 , T_1 V_106 )
{
int V_101 ;
for ( V_101 = 0 ; V_101 < 3 ; V_101 ++ )
if ( ! F_35 ( V_14 , V_104 , V_106 , V_101 ) )
return false ;
return true ;
}
static int F_37 ( struct V_119 * V_120 , T_1 V_104 , T_1 V_106 )
{
return F_36 ( & V_10 . V_9 -> V_14 , V_104 , V_106 ) ?
F_38 ( V_120 ) : 0 ;
}
static int F_39 ( struct V_121 * V_120 , T_1 V_104 , T_1 V_106 )
{
return F_36 ( & V_10 . V_9 -> V_14 , V_104 , V_106 ) ?
F_40 ( V_120 ) : 0 ;
}
static int F_41 ( struct V_122 * V_120 , T_1 V_104 , T_1 V_106 , int V_117 )
{
return ( V_117 >= 0 ? F_35 ( & V_10 . V_9 -> V_14 ,
V_104 , V_106 , V_117 ) :
F_36 ( & V_10 . V_9 -> V_14 , V_104 , V_106 ) ) ?
F_42 ( V_120 ) : 0 ;
}
static void F_43 ( struct V_119 * V_120 , T_1 V_104 , T_1 V_106 )
{
if ( F_36 ( NULL , V_104 , V_106 ) )
F_44 ( V_120 ) ;
}
static void F_45 ( struct V_121 * V_120 , T_1 V_104 , T_1 V_106 )
{
if ( F_36 ( NULL , V_104 , V_106 ) )
F_46 ( V_120 ) ;
}
static void F_47 ( struct V_122 * V_120 , T_1 V_104 , T_1 V_106 ,
int V_117 )
{
if ( V_117 >= 0 ? F_35 ( NULL , V_104 , V_106 , V_117 ) :
F_36 ( NULL , V_104 , V_106 ) )
F_48 ( V_120 ) ;
}
static int F_49 ( void )
{
int V_6 = - 1 ;
if ( V_10 . V_67 . V_80 != V_123 )
goto V_82;
memset ( & V_10 . V_11 , 0 , sizeof( struct V_124 ) ) ;
V_6 = F_50 ( & V_10 ) ;
if ( V_6 )
goto V_82;
V_10 . V_67 . V_91 = V_125 ;
V_6 = F_37 ( & V_126 , V_110 , V_127 ) ;
if ( V_6 )
goto V_82;
V_6 = F_37 ( & V_128 , V_110 , V_129 ) ;
if ( V_6 )
goto V_130;
V_6 = F_37 ( & V_131 , V_110 , V_132 ) ;
if ( V_6 )
goto V_133;
V_6 = F_39 ( & V_134 , V_110 , V_135 ) ;
if ( V_6 )
goto V_136;
V_6 = F_39 ( & V_137 , V_110 , V_135 ) ;
if ( V_6 )
goto V_138;
V_6 = F_39 ( & V_139 , V_110 , V_140 ) ;
if ( V_6 )
goto V_141;
V_6 = F_39 ( & V_142 , V_110 , V_140 ) ;
if ( V_6 )
goto V_143;
V_6 = F_41 ( & V_144 , V_112 , V_145 ,
V_146 ) ;
if ( V_6 )
goto V_147;
V_6 = F_41 ( & V_148 , V_112 , V_145 ,
V_149 ) ;
if ( V_6 )
goto V_150;
V_6 = F_41 ( & V_151 ,
V_110 , V_152 , - 1 ) ;
if ( V_6 )
goto V_153;
goto V_82;
V_153:
F_47 ( & V_148 , V_112 , V_145 ,
V_149 ) ;
V_150:
F_47 ( & V_144 , V_112 , V_145 ,
V_146 ) ;
V_147:
F_45 ( & V_142 , V_110 , V_140 ) ;
V_143:
F_45 ( & V_139 , V_110 , V_140 ) ;
V_141:
F_45 ( & V_137 , V_110 , V_135 ) ;
V_138:
F_45 ( & V_134 , V_110 , V_135 ) ;
V_136:
F_43 ( & V_131 , V_110 , V_132 ) ;
V_133:
F_43 ( & V_128 , V_110 , V_129 ) ;
V_130:
F_43 ( & V_126 , V_110 , V_127 ) ;
V_82:
return V_6 ;
}
static int F_51 ( struct V_1 * V_2 , T_1 V_104 , T_1 V_106 )
{
if ( V_10 . V_67 . V_91 != V_125 ) {
F_14 ( L_26
L_27 ) ;
return - V_154 ;
}
if ( V_106 == V_135 || V_106 == V_140 )
V_2 -> V_75 = ( 5 * V_32 ) +
sizeof( struct V_155 ) ;
else
V_2 -> V_75 = ( 4 * V_32 ) +
sizeof( struct V_155 ) ;
V_2 -> V_74 = F_52 ( V_2 -> V_75 , V_156 ) ;
if ( ! V_2 -> V_74 )
return - V_157 ;
V_2 -> V_76 = (struct V_155 * ) ( F_53 ( ( T_3 ) V_2 -> V_74 ,
( T_3 ) V_32 ) ) ;
V_2 -> V_62 = (struct V_21 * ) ( ( T_2 * ) V_2 -> V_76 + V_32 ) ;
V_2 -> V_64 = (struct V_21 * ) ( ( T_2 * ) V_2 -> V_62 + V_32 ) ;
if ( V_106 == V_135 || V_106 == V_140 )
V_2 -> V_83 =
(struct V_155 * ) ( ( T_2 * ) V_2 -> V_64 +
V_32 ) ;
V_2 -> V_11 = & V_10 . V_11 ;
memcpy ( V_2 -> V_89 , V_10 . V_67 . V_66 [ V_104 ] [ V_106 ] ,
sizeof( struct V_118 ) * 3 ) ;
return 0 ;
}
int F_54 ( struct V_158 * V_159 )
{
F_55 ( V_159 , sizeof( struct V_160 ) ) ;
return F_51 ( F_56 ( V_159 ) , V_110 ,
V_140 ) ;
}
int F_57 ( struct V_158 * V_159 )
{
F_55 ( V_159 , sizeof( struct V_161 ) ) ;
return F_51 ( F_56 ( V_159 ) , V_110 ,
V_135 ) ;
}
int F_58 ( struct V_162 * V_159 )
{
return F_51 ( F_59 ( V_159 ) , V_110 ,
V_132 ) ;
}
int F_60 ( struct V_162 * V_159 )
{
return F_51 ( F_59 ( V_159 ) , V_110 ,
V_129 ) ;
}
int F_61 ( struct V_162 * V_159 )
{
return F_51 ( F_59 ( V_159 ) , V_110 ,
V_127 ) ;
}
int F_62 ( struct V_162 * V_159 )
{
return F_51 ( F_59 ( V_159 ) , V_112 , V_145 ) ;
}
int F_63 ( struct V_162 * V_159 )
{
return F_51 ( F_59 ( V_159 ) , V_110 ,
V_152 ) ;
}
void F_64 ( struct V_162 * V_159 )
{
struct V_1 * V_2 = F_59 ( V_159 ) ;
F_65 ( V_2 -> V_74 ) ;
V_2 -> V_76 = NULL ;
V_2 -> V_83 = NULL ;
V_2 -> V_62 = NULL ;
V_2 -> V_64 = NULL ;
}
void F_66 ( struct V_158 * V_159 )
{
struct V_1 * V_2 = F_56 ( V_159 ) ;
F_65 ( V_2 -> V_74 ) ;
}
static int F_67 ( struct V_8 * V_9 , const struct V_163 * V_164 )
{
F_4 ( & V_9 -> V_14 , L_28 ,
V_9 -> V_165 , V_9 -> V_166 ) ;
if ( V_10 . V_9 ) {
F_30 ( & V_9 -> V_14 , L_29
L_30 , V_94 ) ;
return - V_167 ;
}
V_10 . V_9 = V_9 ;
F_33 ( & V_9 -> V_14 , & V_10 . V_67 ) ;
return F_49 () ;
}
static int F_68 ( struct V_8 * V_9 )
{
F_4 ( & V_9 -> V_14 , L_31 ,
V_9 -> V_168 ) ;
if ( V_10 . V_67 . V_91 == V_125 ) {
F_69 ( & V_10 ) ;
F_47 ( & V_151 ,
V_110 , V_152 , - 1 ) ;
F_47 ( & V_148 ,
V_112 , V_145 , V_146 ) ;
F_47 ( & V_144 ,
V_112 , V_145 , V_149 ) ;
F_45 ( & V_142 ,
V_110 , V_140 ) ;
F_45 ( & V_139 , V_110 , V_140 ) ;
F_45 ( & V_137 ,
V_110 , V_135 ) ;
F_45 ( & V_134 ,
V_110 , V_135 ) ;
F_43 ( & V_131 ,
V_110 , V_132 ) ;
F_43 ( & V_128 , V_110 , V_129 ) ;
F_43 ( & V_126 , V_110 , V_127 ) ;
}
return 0 ;
}
static int T_4 F_70 ( void )
{
return F_71 ( & V_10 . V_169 ) ;
}
static void T_5 F_72 ( void )
{
F_73 ( & V_10 . V_169 ) ;
}
