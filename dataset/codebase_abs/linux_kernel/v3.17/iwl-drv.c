static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( V_4 -> V_5 ) ;
V_4 -> V_5 = NULL ;
V_4 -> V_6 = 0 ;
}
static void F_3 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ )
F_1 ( V_2 , & V_8 -> V_11 [ V_9 ] ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_12 ; V_9 ++ )
F_3 ( V_2 , V_2 -> V_13 . V_8 + V_9 ) ;
}
static int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_14 * V_11 )
{
void * V_5 ;
V_4 -> V_5 = NULL ;
if ( ! V_11 || ! V_11 -> V_15 )
return - V_16 ;
V_5 = F_6 ( V_11 -> V_15 ) ;
if ( ! V_5 )
return - V_17 ;
V_4 -> V_6 = V_11 -> V_15 ;
V_4 -> V_18 = V_11 -> V_18 ;
memcpy ( V_5 , V_11 -> V_5 , V_4 -> V_6 ) ;
V_4 -> V_5 = V_5 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , bool V_19 )
{
const char * V_20 = V_2 -> V_21 -> V_22 ;
char V_23 [ 8 ] ;
if ( V_19 ) {
#ifdef F_8
V_2 -> V_24 = V_25 ;
strcpy ( V_23 , V_26 ) ;
} else if ( V_2 -> V_24 == V_25 ) {
#endif
V_2 -> V_24 = V_2 -> V_21 -> V_27 ;
sprintf ( V_23 , L_1 , V_2 -> V_24 ) ;
} else {
V_2 -> V_24 -- ;
sprintf ( V_23 , L_1 , V_2 -> V_24 ) ;
}
if ( V_2 -> V_24 < V_2 -> V_21 -> V_28 ) {
F_9 ( V_2 , L_2 ) ;
return - V_29 ;
}
snprintf ( V_2 -> V_30 , sizeof( V_2 -> V_30 ) , L_3 ,
V_20 , V_23 ) ;
F_10 ( V_2 , L_4 ,
( V_2 -> V_24 == V_25 )
? L_5 : L_6 ,
V_2 -> V_30 ) ;
return F_11 ( V_31 , 1 , V_2 -> V_30 ,
V_2 -> V_32 -> V_33 ,
V_34 , V_2 , V_35 ) ;
}
static struct V_14 * F_12 ( struct V_36 * V_37 ,
enum V_38 type ,
int V_11 )
{
return & V_37 -> V_8 [ type ] . V_11 [ V_11 ] ;
}
static void F_13 ( struct V_36 * V_37 ,
enum V_38 type ,
int V_11 ,
const void * V_5 )
{
V_37 -> V_8 [ type ] . V_11 [ V_11 ] . V_5 = V_5 ;
}
static void F_14 ( struct V_36 * V_37 ,
enum V_38 type ,
int V_11 ,
T_1 V_15 )
{
V_37 -> V_8 [ type ] . V_11 [ V_11 ] . V_15 = V_15 ;
}
static T_1 F_15 ( struct V_36 * V_37 ,
enum V_38 type ,
int V_11 )
{
return V_37 -> V_8 [ type ] . V_11 [ V_11 ] . V_15 ;
}
static void F_16 ( struct V_36 * V_37 ,
enum V_38 type ,
int V_11 ,
T_2 V_18 )
{
V_37 -> V_8 [ type ] . V_11 [ V_11 ] . V_18 = V_18 ;
}
static int F_17 ( struct V_39 * V_13 , const T_3 * V_5 , const T_2 V_6 )
{
int V_9 , V_40 ;
struct V_41 * V_42 = (struct V_41 * ) V_5 ;
struct V_43 * V_44 ;
struct V_45 * V_46 ;
T_2 V_47 ;
if ( V_6 < sizeof( * V_42 ) ||
V_6 < sizeof( V_42 -> V_15 ) + V_42 -> V_15 * sizeof( V_42 -> V_46 [ 0 ] ) )
return - V_16 ;
for ( V_9 = 0 , V_40 = 0 ; V_9 < V_48 && V_9 < V_42 -> V_15 ; V_9 ++ ) {
V_44 = & V_42 -> V_46 [ V_40 ] ;
V_47 = F_18 ( V_44 -> V_47 ) ;
if ( ! V_47 )
continue;
V_46 = & V_13 -> V_46 [ V_40 ++ ] ;
V_46 -> V_47 = V_47 ;
V_46 -> V_49 = F_19 ( V_50 ) ;
V_46 -> V_51 = V_44 -> V_51 ;
V_46 -> V_52 = V_44 -> V_52 ;
V_46 -> V_53 = V_44 -> V_53 ;
V_46 -> V_54 = V_44 -> V_54 ;
V_46 -> V_55 = V_44 -> V_55 ;
V_46 -> V_56 = V_44 -> V_56 ;
V_46 -> V_57 = V_44 -> V_57 ;
}
return 0 ;
}
static int F_20 ( struct V_36 * V_37 ,
const void * V_5 , enum V_38 type ,
int V_15 )
{
struct V_58 * V_8 ;
struct V_14 * V_11 ;
struct V_59 * V_60 ;
if ( F_21 ( ! V_37 || ! V_5 || type >= V_12 ) )
return - 1 ;
V_60 = (struct V_59 * ) V_5 ;
V_8 = & V_37 -> V_8 [ type ] ;
V_11 = & V_8 -> V_11 [ V_8 -> V_61 ] ;
V_11 -> V_18 = F_18 ( V_60 -> V_18 ) ;
V_11 -> V_5 = V_60 -> V_5 ;
V_11 -> V_15 = V_15 - sizeof( V_60 -> V_18 ) ;
++ V_8 -> V_61 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , const T_3 * V_5 )
{
struct V_62 * V_63 =
(struct V_62 * ) V_5 ;
T_2 V_64 = F_18 ( V_63 -> V_64 ) ;
if ( V_64 >= V_12 ) {
F_9 ( V_2 , L_7 ,
V_64 ) ;
return - V_16 ;
}
V_2 -> V_13 . V_65 [ V_64 ] . V_66 =
V_63 -> V_67 . V_66 ;
V_2 -> V_13 . V_65 [ V_64 ] . V_68 =
V_63 -> V_67 . V_68 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , const T_3 * V_5 ,
struct V_69 * V_70 )
{
const struct V_71 * V_72 = ( void * ) V_5 ;
T_2 V_73 = F_18 ( V_72 -> V_73 ) ;
if ( V_73 >= V_74 ) {
F_9 ( V_2 , L_8 ) ;
return - V_16 ;
}
V_70 -> V_75 [ V_73 ] = F_18 ( V_72 -> V_76 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , const T_3 * V_5 ,
struct V_69 * V_70 )
{
const struct V_77 * V_78 = ( void * ) V_5 ;
T_2 V_73 = F_18 ( V_78 -> V_73 ) ;
if ( V_73 >= V_79 ) {
F_9 ( V_2 , L_8 ) ;
return - V_16 ;
}
V_70 -> V_70 [ V_73 ] = F_18 ( V_78 -> V_80 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
const struct V_81 * V_82 ,
struct V_36 * V_37 )
{
struct V_83 * V_84 = ( void * ) V_82 -> V_5 ;
T_2 V_85 , V_86 , V_87 ;
char V_88 [ 25 ] ;
const T_3 * V_89 ;
V_2 -> V_13 . V_90 = F_18 ( V_84 -> V_91 ) ;
V_85 = F_26 ( V_2 -> V_13 . V_90 ) ;
switch ( V_85 ) {
default:
V_86 = 28 ;
if ( V_82 -> V_15 < V_86 ) {
F_9 ( V_2 , L_9 ) ;
return - V_16 ;
}
V_87 = F_18 ( V_84 -> V_92 . V_93 . V_87 ) ;
F_14 ( V_37 , V_94 , V_95 ,
F_18 ( V_84 -> V_92 . V_93 . V_96 ) ) ;
F_14 ( V_37 , V_94 , V_97 ,
F_18 ( V_84 -> V_92 . V_93 . V_98 ) ) ;
F_14 ( V_37 , V_99 , V_95 ,
F_18 ( V_84 -> V_92 . V_93 . V_100 ) ) ;
F_14 ( V_37 , V_99 , V_97 ,
F_18 ( V_84 -> V_92 . V_93 . V_101 ) ) ;
V_89 = V_84 -> V_92 . V_93 . V_5 ;
break;
case 0 :
case 1 :
case 2 :
V_86 = 24 ;
if ( V_82 -> V_15 < V_86 ) {
F_9 ( V_2 , L_9 ) ;
return - V_16 ;
}
V_87 = 0 ;
F_14 ( V_37 , V_94 , V_95 ,
F_18 ( V_84 -> V_92 . V_102 . V_96 ) ) ;
F_14 ( V_37 , V_94 , V_97 ,
F_18 ( V_84 -> V_92 . V_102 . V_98 ) ) ;
F_14 ( V_37 , V_99 , V_95 ,
F_18 ( V_84 -> V_92 . V_102 . V_100 ) ) ;
F_14 ( V_37 , V_99 , V_97 ,
F_18 ( V_84 -> V_92 . V_102 . V_101 ) ) ;
V_89 = V_84 -> V_92 . V_102 . V_5 ;
break;
}
if ( V_87 )
sprintf ( V_88 , L_10 , V_87 ,
( V_2 -> V_24 == V_25 )
? L_11 : L_6 ) ;
else
V_88 [ 0 ] = '\0' ;
snprintf ( V_2 -> V_13 . V_103 ,
sizeof( V_2 -> V_13 . V_103 ) ,
L_12 ,
F_27 ( V_2 -> V_13 . V_90 ) ,
F_28 ( V_2 -> V_13 . V_90 ) ,
F_26 ( V_2 -> V_13 . V_90 ) ,
F_29 ( V_2 -> V_13 . V_90 ) ,
V_88 ) ;
if ( V_82 -> V_15 != V_86 +
F_15 ( V_37 , V_94 , V_95 ) +
F_15 ( V_37 , V_94 , V_97 ) +
F_15 ( V_37 , V_99 , V_95 ) +
F_15 ( V_37 , V_99 , V_97 ) ) {
F_9 ( V_2 ,
L_13 ,
( int ) V_82 -> V_15 ) ;
return - V_16 ;
}
F_13 ( V_37 , V_94 , V_95 , V_89 ) ;
V_89 += F_15 ( V_37 , V_94 , V_95 ) ;
F_16 ( V_37 , V_94 , V_95 ,
V_104 ) ;
F_13 ( V_37 , V_94 , V_97 , V_89 ) ;
V_89 += F_15 ( V_37 , V_94 , V_97 ) ;
F_16 ( V_37 , V_94 , V_97 ,
V_105 ) ;
F_13 ( V_37 , V_99 , V_95 , V_89 ) ;
V_89 += F_15 ( V_37 , V_99 , V_95 ) ;
F_16 ( V_37 , V_99 , V_95 ,
V_104 ) ;
F_13 ( V_37 , V_99 , V_97 , V_89 ) ;
V_89 += F_15 ( V_37 , V_99 , V_97 ) ;
F_16 ( V_37 , V_99 , V_97 ,
V_105 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
const struct V_81 * V_82 ,
struct V_36 * V_37 ,
struct V_69 * V_70 )
{
struct V_106 * V_84 = ( void * ) V_82 -> V_5 ;
struct V_107 * V_108 ;
T_1 V_6 = V_82 -> V_15 ;
const T_3 * V_5 ;
T_2 V_109 ;
enum V_110 V_111 ;
const T_3 * V_112 ;
char V_88 [ 25 ] ;
T_2 V_87 ;
int V_113 ;
if ( V_6 < sizeof( * V_84 ) ) {
F_9 ( V_2 , L_14 , V_6 ) ;
return - V_16 ;
}
if ( V_84 -> V_114 != F_31 ( V_115 ) ) {
F_9 ( V_2 , L_15 ,
F_18 ( V_84 -> V_114 ) ) ;
return - V_16 ;
}
V_2 -> V_13 . V_90 = F_18 ( V_84 -> V_91 ) ;
memcpy ( V_2 -> V_13 . V_116 , V_84 -> V_116 ,
sizeof( V_2 -> V_13 . V_116 ) ) ;
V_87 = F_18 ( V_84 -> V_87 ) ;
if ( V_87 )
sprintf ( V_88 , L_10 , V_87 ,
( V_2 -> V_24 == V_25 )
? L_11 : L_6 ) ;
else
V_88 [ 0 ] = '\0' ;
snprintf ( V_2 -> V_13 . V_103 ,
sizeof( V_2 -> V_13 . V_103 ) ,
L_12 ,
F_27 ( V_2 -> V_13 . V_90 ) ,
F_28 ( V_2 -> V_13 . V_90 ) ,
F_26 ( V_2 -> V_13 . V_90 ) ,
F_29 ( V_2 -> V_13 . V_90 ) ,
V_88 ) ;
V_5 = V_84 -> V_5 ;
V_6 -= sizeof( * V_84 ) ;
while ( V_6 >= sizeof( * V_108 ) ) {
V_6 -= sizeof( * V_108 ) ;
V_108 = ( void * ) V_5 ;
V_109 = F_18 ( V_108 -> V_117 ) ;
V_111 = F_18 ( V_108 -> type ) ;
V_112 = V_108 -> V_5 ;
if ( V_6 < V_109 ) {
F_9 ( V_2 , L_16 ,
V_6 , V_109 ) ;
return - V_16 ;
}
V_6 -= F_32 ( V_109 , 4 ) ;
V_5 += sizeof( * V_108 ) + F_32 ( V_109 , 4 ) ;
switch ( V_111 ) {
case V_118 :
F_13 ( V_37 , V_94 ,
V_95 , V_112 ) ;
F_14 ( V_37 , V_94 ,
V_95 , V_109 ) ;
F_16 ( V_37 , V_94 ,
V_95 ,
V_104 ) ;
break;
case V_119 :
F_13 ( V_37 , V_94 ,
V_97 , V_112 ) ;
F_14 ( V_37 , V_94 ,
V_97 , V_109 ) ;
F_16 ( V_37 , V_94 ,
V_97 ,
V_105 ) ;
break;
case V_120 :
F_13 ( V_37 , V_99 ,
V_95 , V_112 ) ;
F_14 ( V_37 , V_99 ,
V_95 , V_109 ) ;
F_16 ( V_37 , V_99 ,
V_95 ,
V_104 ) ;
break;
case V_121 :
F_13 ( V_37 , V_99 ,
V_97 , V_112 ) ;
F_14 ( V_37 , V_99 ,
V_97 , V_109 ) ;
F_16 ( V_37 , V_99 ,
V_97 ,
V_105 ) ;
break;
case V_122 :
F_9 ( V_2 , L_17 ) ;
break;
case V_123 :
if ( V_109 != sizeof( T_2 ) )
goto V_124;
V_70 -> V_125 =
F_33 ( ( V_126 * ) V_112 ) ;
break;
case V_127 :
if ( V_109 )
goto V_124;
V_70 -> V_128 |= V_129 ;
break;
case V_130 :
if ( V_109 < sizeof( T_2 ) )
goto V_124;
if ( V_109 % sizeof( T_2 ) )
goto V_124;
V_70 -> V_128 = F_33 ( ( V_126 * ) V_112 ) ;
break;
case V_131 :
if ( V_109 != sizeof( struct V_71 ) )
goto V_124;
if ( F_23 ( V_2 , V_112 , V_70 ) )
goto V_132;
break;
case V_133 :
if ( V_109 != sizeof( struct V_77 ) )
goto V_124;
if ( F_24 ( V_2 , V_112 , V_70 ) )
goto V_132;
break;
case V_134 :
if ( V_109 != sizeof( T_2 ) )
goto V_124;
V_37 -> V_135 =
F_33 ( ( V_126 * ) V_112 ) ;
break;
case V_136 :
if ( V_109 != sizeof( T_2 ) )
goto V_124;
V_37 -> V_137 =
F_33 ( ( V_126 * ) V_112 ) ;
break;
case V_138 :
if ( V_109 != sizeof( T_2 ) )
goto V_124;
V_37 -> V_139 =
F_33 ( ( V_126 * ) V_112 ) ;
break;
case V_140 :
if ( V_109 != sizeof( T_2 ) )
goto V_124;
V_37 -> V_141 =
F_33 ( ( V_126 * ) V_112 ) ;
break;
case V_142 :
if ( V_109 != sizeof( T_2 ) )
goto V_124;
V_37 -> V_143 =
F_33 ( ( V_126 * ) V_112 ) ;
break;
case V_144 :
if ( V_109 != sizeof( T_2 ) )
goto V_124;
V_37 -> V_145 =
F_33 ( ( V_126 * ) V_112 ) ;
break;
case V_146 :
if ( V_109 )
goto V_124;
V_2 -> V_13 . V_147 = true ;
break;
case V_148 :
F_13 ( V_37 , V_149 ,
V_95 , V_112 ) ;
F_14 ( V_37 , V_149 ,
V_95 , V_109 ) ;
F_16 ( V_37 , V_149 ,
V_95 ,
V_104 ) ;
break;
case V_150 :
F_13 ( V_37 , V_149 ,
V_97 , V_112 ) ;
F_14 ( V_37 , V_149 ,
V_97 , V_109 ) ;
F_16 ( V_37 , V_149 ,
V_97 ,
V_105 ) ;
break;
case V_151 :
if ( V_109 != sizeof( T_2 ) )
goto V_124;
V_70 -> V_152 =
F_33 ( ( V_126 * ) V_112 ) ;
break;
case V_153 :
F_20 ( V_37 , V_112 , V_94 ,
V_109 ) ;
V_2 -> V_13 . V_154 = true ;
break;
case V_155 :
F_20 ( V_37 , V_112 , V_99 ,
V_109 ) ;
V_2 -> V_13 . V_154 = true ;
break;
case V_156 :
F_20 ( V_37 , V_112 , V_149 ,
V_109 ) ;
V_2 -> V_13 . V_154 = true ;
break;
case V_157 :
if ( V_109 != sizeof( struct V_62 ) )
goto V_124;
if ( F_22 ( V_2 , V_112 ) )
goto V_132;
break;
case V_158 :
if ( V_109 != sizeof( T_2 ) )
goto V_124;
V_2 -> V_13 . V_159 = F_33 ( ( V_126 * ) V_112 ) ;
V_2 -> V_13 . V_160 = ( V_2 -> V_13 . V_159 &
V_161 ) >>
V_162 ;
V_2 -> V_13 . V_163 = ( V_2 -> V_13 . V_159 &
V_164 ) >>
V_165 ;
break;
case V_166 :
F_20 ( V_37 , V_112 , V_94 ,
V_109 ) ;
V_2 -> V_13 . V_154 = true ;
V_2 -> V_13 . V_8 [ V_94 ] . V_167 = true ;
break;
case V_168 :
F_20 ( V_37 , V_112 , V_99 ,
V_109 ) ;
V_2 -> V_13 . V_154 = true ;
V_2 -> V_13 . V_8 [ V_99 ] . V_167 = true ;
break;
case V_169 :
F_20 ( V_37 , V_112 , V_149 ,
V_109 ) ;
V_2 -> V_13 . V_154 = true ;
V_2 -> V_13 . V_8 [ V_149 ] . V_167 = true ;
break;
case V_170 :
if ( V_109 != sizeof( T_2 ) )
goto V_124;
V_113 =
F_33 ( ( V_126 * ) V_112 ) ;
if ( V_113 == 2 ) {
V_2 -> V_13 . V_8 [ V_94 ] . V_171 =
true ;
V_2 -> V_13 . V_8 [ V_99 ] . V_171 =
true ;
V_2 -> V_13 . V_8 [ V_149 ] . V_171 =
true ;
} else if ( ( V_113 > 2 ) || ( V_113 < 1 ) ) {
F_9 ( V_2 , L_18 ) ;
return - V_16 ;
}
break;
case V_172 :
if ( F_17 ( & V_2 -> V_13 , V_112 , V_109 ) )
goto V_124;
break;
case V_173 :
if ( V_109 != sizeof( T_2 ) )
goto V_124;
V_70 -> V_174 =
F_33 ( ( V_126 * ) V_112 ) ;
break;
default:
F_10 ( V_2 , L_19 , V_111 ) ;
break;
}
}
if ( V_6 ) {
F_9 ( V_2 , L_20 , V_6 ) ;
F_34 ( V_2 , V_175 , ( T_3 * ) V_5 , V_6 ) ;
return - V_16 ;
}
return 0 ;
V_124:
F_9 ( V_2 , L_21 , V_111 , V_109 ) ;
V_132:
F_34 ( V_2 , V_175 , V_112 , V_109 ) ;
return - V_16 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_36 * V_37 ,
enum V_38 type )
{
int V_9 ;
for ( V_9 = 0 ;
V_9 < V_10 && F_15 ( V_37 , type , V_9 ) ;
V_9 ++ )
if ( F_5 ( V_2 , & ( V_2 -> V_13 . V_8 [ type ] . V_11 [ V_9 ] ) ,
F_12 ( V_37 , type , V_9 ) ) )
return - V_17 ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_36 * V_37 ,
const struct V_176 * V_21 )
{
F_10 ( V_2 , L_22 ,
F_15 ( V_37 , V_94 ,
V_95 ) ) ;
F_10 ( V_2 , L_23 ,
F_15 ( V_37 , V_94 ,
V_97 ) ) ;
F_10 ( V_2 , L_24 ,
F_15 ( V_37 , V_99 , V_95 ) ) ;
F_10 ( V_2 , L_25 ,
F_15 ( V_37 , V_99 , V_97 ) ) ;
if ( F_15 ( V_37 , V_94 , V_95 ) >
V_21 -> V_177 ) {
F_9 ( V_2 , L_26 ,
F_15 ( V_37 , V_94 ,
V_95 ) ) ;
return - 1 ;
}
if ( F_15 ( V_37 , V_94 , V_97 ) >
V_21 -> V_178 ) {
F_9 ( V_2 , L_27 ,
F_15 ( V_37 , V_94 ,
V_97 ) ) ;
return - 1 ;
}
if ( F_15 ( V_37 , V_99 , V_95 ) >
V_21 -> V_177 ) {
F_9 ( V_2 , L_28 ,
F_15 ( V_37 , V_99 ,
V_95 ) ) ;
return - 1 ;
}
if ( F_15 ( V_37 , V_99 , V_97 ) >
V_21 -> V_178 ) {
F_9 ( V_2 , L_29 ,
F_15 ( V_37 , V_94 ,
V_97 ) ) ;
return - 1 ;
}
return 0 ;
}
static struct V_179 *
F_37 ( struct V_1 * V_2 , struct V_180 * V_181 )
{
const struct V_182 * V_183 = V_181 -> V_183 ;
struct V_184 * V_185 = NULL ;
struct V_179 * V_186 = NULL ;
#ifdef F_38
V_2 -> V_187 = F_39 ( V_181 -> V_188 ,
V_2 -> V_189 ) ;
if ( ! V_2 -> V_187 ) {
F_9 ( V_2 ,
L_30 ) ;
return V_186 ;
}
V_185 = V_2 -> V_187 ;
#endif
V_186 = V_183 -> V_190 ( V_2 -> V_32 , V_2 -> V_21 , & V_2 -> V_13 , V_185 ) ;
#ifdef F_38
if ( ! V_186 ) {
F_40 ( V_2 -> V_187 ) ;
V_2 -> V_187 = NULL ;
}
#endif
return V_186 ;
}
static void F_41 ( struct V_1 * V_2 )
{
if ( V_2 -> V_186 ) {
F_42 ( V_2 -> V_186 ) ;
V_2 -> V_186 = NULL ;
#ifdef F_38
F_40 ( V_2 -> V_187 ) ;
V_2 -> V_187 = NULL ;
#endif
}
}
static void V_35 ( const struct V_81 * V_82 , void * V_191 )
{
struct V_1 * V_2 = V_191 ;
struct V_39 * V_13 = & V_2 -> V_13 ;
struct V_83 * V_84 ;
struct V_180 * V_181 ;
int V_192 ;
struct V_36 V_37 ;
const unsigned int V_193 = V_2 -> V_21 -> V_27 ;
unsigned int V_194 = V_2 -> V_21 -> V_195 ;
const unsigned int V_196 = V_2 -> V_21 -> V_28 ;
T_2 V_85 ;
int V_9 ;
bool V_197 = false ;
V_13 -> V_78 . V_125 = V_198 ;
V_13 -> V_78 . V_152 =
V_199 ;
V_13 -> V_78 . V_174 = V_200 ;
if ( ! V_194 )
V_194 = V_193 ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
if ( ! V_82 ) {
if ( V_2 -> V_24 <= V_194 )
F_9 ( V_2 ,
L_31 ,
V_2 -> V_30 ) ;
goto V_201;
}
F_10 ( V_2 , L_32 ,
V_2 -> V_30 , V_82 -> V_15 ) ;
if ( V_82 -> V_15 < 4 ) {
F_9 ( V_2 , L_33 ) ;
goto V_201;
}
V_84 = (struct V_83 * ) V_82 -> V_5 ;
if ( V_84 -> V_91 )
V_192 = F_25 ( V_2 , V_82 , & V_37 ) ;
else
V_192 = F_30 ( V_2 , V_82 , & V_37 ,
& V_13 -> V_78 ) ;
if ( V_192 )
goto V_201;
V_85 = F_26 ( V_2 -> V_13 . V_90 ) ;
if ( V_2 -> V_24 != V_25 ) {
if ( V_85 < V_196 || V_85 > V_193 ) {
F_9 ( V_2 ,
L_34
L_35 ,
V_193 , V_85 ) ;
goto V_201;
}
if ( V_85 < V_194 ) {
if ( V_194 != V_193 )
F_9 ( V_2 , L_36
L_37 ,
V_194 , V_193 , V_85 ) ;
else
F_9 ( V_2 , L_36
L_38 ,
V_193 , V_85 ) ;
F_9 ( V_2 , L_39
L_40 ) ;
}
}
if ( ! V_13 -> V_154 && F_36 ( V_2 , & V_37 , V_2 -> V_21 ) )
goto V_201;
for ( V_9 = 0 ; V_9 < V_12 ; V_9 ++ )
if ( F_35 ( V_2 , & V_37 , V_9 ) )
goto V_202;
V_13 -> V_135 = V_37 . V_135 ;
if ( V_37 . V_137 )
V_13 -> V_137 = ( V_37 . V_137 - 16 ) / 12 ;
else
V_13 -> V_137 =
V_2 -> V_21 -> V_203 -> V_204 ;
V_13 -> V_139 = V_37 . V_139 ;
V_13 -> V_141 = V_37 . V_141 ;
if ( V_37 . V_143 )
V_13 -> V_143 = ( V_37 . V_143 - 16 ) / 12 ;
else
V_13 -> V_143 =
V_2 -> V_21 -> V_203 -> V_204 ;
V_13 -> V_145 = V_37 . V_145 ;
if ( V_13 -> V_78 . V_152 >
V_205 )
V_13 -> V_78 . V_152 =
V_206 ;
F_43 ( V_82 ) ;
F_44 ( & V_207 ) ;
if ( V_13 -> V_154 )
V_181 = & V_180 [ V_208 ] ;
else
V_181 = & V_180 [ V_209 ] ;
F_45 ( V_2 , L_41 ,
V_2 -> V_13 . V_103 , V_181 -> V_188 ) ;
F_46 ( & V_2 -> V_210 , & V_181 -> V_2 ) ;
if ( V_181 -> V_183 ) {
V_2 -> V_186 = F_37 ( V_2 , V_181 ) ;
if ( ! V_2 -> V_186 ) {
F_47 ( & V_207 ) ;
goto V_211;
}
} else {
V_197 = true ;
}
F_47 ( & V_207 ) ;
F_48 ( & V_2 -> V_212 ) ;
if ( V_197 ) {
V_192 = F_49 ( L_42 , V_181 -> V_188 ) ;
#ifdef F_50
if ( V_192 )
F_9 ( V_2 ,
L_43 ,
V_181 -> V_188 , V_192 ) ;
#endif
}
return;
V_201:
F_43 ( V_82 ) ;
if ( F_7 ( V_2 , false ) )
goto V_211;
return;
V_202:
F_9 ( V_2 , L_44 ) ;
F_4 ( V_2 ) ;
F_43 ( V_82 ) ;
V_211:
F_48 ( & V_2 -> V_212 ) ;
F_51 ( V_2 -> V_32 -> V_33 ) ;
}
struct V_1 * F_52 ( struct V_213 * V_32 ,
const struct V_176 * V_21 )
{
struct V_1 * V_2 ;
int V_214 ;
V_2 = F_53 ( sizeof( * V_2 ) , V_34 ) ;
if ( ! V_2 ) {
V_214 = - V_17 ;
goto V_192;
}
V_2 -> V_32 = V_32 ;
V_2 -> V_33 = V_32 -> V_33 ;
V_2 -> V_21 = V_21 ;
F_54 ( & V_2 -> V_212 ) ;
F_55 ( & V_2 -> V_210 ) ;
#ifdef F_38
V_2 -> V_189 = F_39 ( F_56 ( V_32 -> V_33 ) ,
V_215 ) ;
if ( ! V_2 -> V_189 ) {
F_9 ( V_2 , L_45 ) ;
V_214 = - V_17 ;
goto V_216;
}
V_2 -> V_32 -> V_185 = F_39 ( L_46 , V_2 -> V_189 ) ;
if ( ! V_2 -> V_32 -> V_185 ) {
F_9 ( V_2 , L_47 ) ;
V_214 = - V_17 ;
goto V_217;
}
#endif
V_214 = F_7 ( V_2 , true ) ;
if ( V_214 ) {
F_9 ( V_32 , L_48 ) ;
goto V_218;
}
return V_2 ;
V_218:
#ifdef F_38
V_217:
F_40 ( V_2 -> V_189 ) ;
V_216:
#endif
F_57 ( V_2 ) ;
V_192:
return F_58 ( V_214 ) ;
}
void F_59 ( struct V_1 * V_2 )
{
F_60 ( & V_2 -> V_212 ) ;
F_41 ( V_2 ) ;
F_4 ( V_2 ) ;
F_44 ( & V_207 ) ;
if ( ! F_61 ( & V_2 -> V_210 ) )
F_62 ( & V_2 -> V_210 ) ;
F_47 ( & V_207 ) ;
#ifdef F_38
F_40 ( V_2 -> V_189 ) ;
#endif
F_57 ( V_2 ) ;
}
int F_63 ( const char * V_188 , const struct V_182 * V_183 )
{
int V_9 ;
struct V_1 * V_2 ;
struct V_180 * V_181 ;
F_44 ( & V_207 ) ;
for ( V_9 = 0 ; V_9 < F_64 ( V_180 ) ; V_9 ++ ) {
V_181 = & V_180 [ V_9 ] ;
if ( strcmp ( V_181 -> V_188 , V_188 ) )
continue;
V_181 -> V_183 = V_183 ;
F_65 (drv, &op->drv, list)
V_2 -> V_186 = F_37 ( V_2 , V_181 ) ;
F_47 ( & V_207 ) ;
return 0 ;
}
F_47 ( & V_207 ) ;
return - V_219 ;
}
void F_66 ( const char * V_188 )
{
int V_9 ;
struct V_1 * V_2 ;
F_44 ( & V_207 ) ;
for ( V_9 = 0 ; V_9 < F_64 ( V_180 ) ; V_9 ++ ) {
if ( strcmp ( V_180 [ V_9 ] . V_188 , V_188 ) )
continue;
V_180 [ V_9 ] . V_183 = NULL ;
F_65 (drv, &iwlwifi_opmode_table[i].drv, list)
F_41 ( V_2 ) ;
F_47 ( & V_207 ) ;
return;
}
F_47 ( & V_207 ) ;
}
static int T_4 F_67 ( void )
{
int V_9 ;
F_68 ( & V_207 ) ;
for ( V_9 = 0 ; V_9 < F_64 ( V_180 ) ; V_9 ++ )
F_55 ( & V_180 [ V_9 ] . V_2 ) ;
F_69 ( V_220 L_49 V_221 L_50 ) ;
F_69 ( V_222 L_50 ) ;
#ifdef F_38
V_215 = F_39 ( V_223 , NULL ) ;
if ( ! V_215 )
return - V_224 ;
#endif
return F_70 () ;
}
static void T_5 F_71 ( void )
{
F_72 () ;
#ifdef F_38
F_40 ( V_215 ) ;
#endif
}
