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
if ( V_2 -> V_31 -> V_21 -> V_32 == V_33 ) {
char V_34 [ 2 ] = {
'A' + F_10 ( V_2 -> V_31 -> V_35 ) , 0
} ;
if ( F_10 ( V_2 -> V_31 -> V_35 ) == V_36 )
V_34 [ 0 ] = 0 ;
snprintf ( V_2 -> V_30 , sizeof( V_2 -> V_30 ) ,
L_4 , V_20 , V_34 , V_23 ) ;
}
F_11 ( V_2 , L_5 ,
( V_2 -> V_24 == V_25 )
? L_6 : L_7 ,
V_2 -> V_30 ) ;
return F_12 ( V_37 , 1 , V_2 -> V_30 ,
V_2 -> V_31 -> V_38 ,
V_39 , V_2 , V_40 ) ;
}
static struct V_14 * F_13 ( struct V_41 * V_42 ,
enum V_43 type ,
int V_11 )
{
return & V_42 -> V_8 [ type ] . V_11 [ V_11 ] ;
}
static void F_14 ( struct V_41 * V_42 ,
enum V_43 type ,
int V_11 ,
const void * V_5 )
{
V_42 -> V_8 [ type ] . V_11 [ V_11 ] . V_5 = V_5 ;
}
static void F_15 ( struct V_41 * V_42 ,
enum V_43 type ,
int V_11 ,
T_1 V_15 )
{
V_42 -> V_8 [ type ] . V_11 [ V_11 ] . V_15 = V_15 ;
}
static T_1 F_16 ( struct V_41 * V_42 ,
enum V_43 type ,
int V_11 )
{
return V_42 -> V_8 [ type ] . V_11 [ V_11 ] . V_15 ;
}
static void F_17 ( struct V_41 * V_42 ,
enum V_43 type ,
int V_11 ,
T_2 V_18 )
{
V_42 -> V_8 [ type ] . V_11 [ V_11 ] . V_18 = V_18 ;
}
static int F_18 ( struct V_44 * V_13 , const T_3 * V_5 , const T_2 V_6 )
{
int V_9 , V_45 ;
struct V_46 * V_47 = (struct V_46 * ) V_5 ;
struct V_48 * V_49 ;
struct V_50 * V_51 ;
T_2 V_52 ;
if ( V_6 < sizeof( * V_47 ) ||
V_6 < sizeof( V_47 -> V_15 ) + V_47 -> V_15 * sizeof( V_47 -> V_51 [ 0 ] ) )
return - V_16 ;
for ( V_9 = 0 , V_45 = 0 ; V_9 < V_53 && V_9 < V_47 -> V_15 ; V_9 ++ ) {
V_49 = & V_47 -> V_51 [ V_45 ] ;
V_52 = F_19 ( V_49 -> V_52 ) ;
if ( ! V_52 )
continue;
V_51 = & V_13 -> V_51 [ V_45 ++ ] ;
V_51 -> V_52 = V_52 ;
V_51 -> V_54 = F_20 ( V_55 ) ;
V_51 -> V_56 = V_49 -> V_56 ;
V_51 -> V_57 = V_49 -> V_57 ;
V_51 -> V_58 = V_49 -> V_58 ;
V_51 -> V_59 = V_49 -> V_59 ;
V_51 -> V_60 = V_49 -> V_60 ;
V_51 -> V_61 = V_49 -> V_61 ;
V_51 -> V_62 = V_49 -> V_62 ;
}
return 0 ;
}
static int F_21 ( struct V_41 * V_42 ,
const void * V_5 , enum V_43 type ,
int V_15 )
{
struct V_63 * V_8 ;
struct V_14 * V_11 ;
struct V_64 * V_65 ;
if ( F_22 ( ! V_42 || ! V_5 || type >= V_12 ) )
return - 1 ;
V_65 = (struct V_64 * ) V_5 ;
V_8 = & V_42 -> V_8 [ type ] ;
V_11 = & V_8 -> V_11 [ V_8 -> V_66 ] ;
V_11 -> V_18 = F_19 ( V_65 -> V_18 ) ;
V_11 -> V_5 = V_65 -> V_5 ;
V_11 -> V_15 = V_15 - sizeof( V_65 -> V_18 ) ;
++ V_8 -> V_66 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , const T_3 * V_5 )
{
struct V_67 * V_68 =
(struct V_67 * ) V_5 ;
T_2 V_69 = F_19 ( V_68 -> V_69 ) ;
if ( V_69 >= V_12 ) {
F_9 ( V_2 , L_8 ,
V_69 ) ;
return - V_16 ;
}
V_2 -> V_13 . V_70 [ V_69 ] . V_71 =
V_68 -> V_72 . V_71 ;
V_2 -> V_13 . V_70 [ V_69 ] . V_73 =
V_68 -> V_72 . V_73 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , const T_3 * V_5 ,
struct V_74 * V_75 )
{
const struct V_76 * V_77 = ( void * ) V_5 ;
T_2 V_78 = F_19 ( V_77 -> V_78 ) ;
if ( V_78 >= V_79 ) {
F_9 ( V_2 , L_9 ) ;
return - V_16 ;
}
V_75 -> V_80 [ V_78 ] = F_19 ( V_77 -> V_81 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , const T_3 * V_5 ,
struct V_74 * V_75 )
{
const struct V_82 * V_83 = ( void * ) V_5 ;
T_2 V_78 = F_19 ( V_83 -> V_78 ) ;
if ( V_78 >= V_84 ) {
F_9 ( V_2 , L_9 ) ;
return - V_16 ;
}
V_75 -> V_75 [ V_78 ] = F_19 ( V_83 -> V_85 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
const struct V_86 * V_87 ,
struct V_41 * V_42 )
{
struct V_88 * V_89 = ( void * ) V_87 -> V_5 ;
T_2 V_90 , V_91 , V_92 ;
char V_93 [ 25 ] ;
const T_3 * V_94 ;
V_2 -> V_13 . V_95 = F_19 ( V_89 -> V_96 ) ;
V_90 = F_27 ( V_2 -> V_13 . V_95 ) ;
switch ( V_90 ) {
default:
V_91 = 28 ;
if ( V_87 -> V_15 < V_91 ) {
F_9 ( V_2 , L_10 ) ;
return - V_16 ;
}
V_92 = F_19 ( V_89 -> V_97 . V_98 . V_92 ) ;
F_15 ( V_42 , V_99 , V_100 ,
F_19 ( V_89 -> V_97 . V_98 . V_101 ) ) ;
F_15 ( V_42 , V_99 , V_102 ,
F_19 ( V_89 -> V_97 . V_98 . V_103 ) ) ;
F_15 ( V_42 , V_104 , V_100 ,
F_19 ( V_89 -> V_97 . V_98 . V_105 ) ) ;
F_15 ( V_42 , V_104 , V_102 ,
F_19 ( V_89 -> V_97 . V_98 . V_106 ) ) ;
V_94 = V_89 -> V_97 . V_98 . V_5 ;
break;
case 0 :
case 1 :
case 2 :
V_91 = 24 ;
if ( V_87 -> V_15 < V_91 ) {
F_9 ( V_2 , L_10 ) ;
return - V_16 ;
}
V_92 = 0 ;
F_15 ( V_42 , V_99 , V_100 ,
F_19 ( V_89 -> V_97 . V_107 . V_101 ) ) ;
F_15 ( V_42 , V_99 , V_102 ,
F_19 ( V_89 -> V_97 . V_107 . V_103 ) ) ;
F_15 ( V_42 , V_104 , V_100 ,
F_19 ( V_89 -> V_97 . V_107 . V_105 ) ) ;
F_15 ( V_42 , V_104 , V_102 ,
F_19 ( V_89 -> V_97 . V_107 . V_106 ) ) ;
V_94 = V_89 -> V_97 . V_107 . V_5 ;
break;
}
if ( V_92 )
sprintf ( V_93 , L_11 , V_92 ,
( V_2 -> V_24 == V_25 )
? L_12 : L_7 ) ;
else
V_93 [ 0 ] = '\0' ;
snprintf ( V_2 -> V_13 . V_108 ,
sizeof( V_2 -> V_13 . V_108 ) ,
L_13 ,
F_28 ( V_2 -> V_13 . V_95 ) ,
F_29 ( V_2 -> V_13 . V_95 ) ,
F_27 ( V_2 -> V_13 . V_95 ) ,
F_30 ( V_2 -> V_13 . V_95 ) ,
V_93 ) ;
if ( V_87 -> V_15 != V_91 +
F_16 ( V_42 , V_99 , V_100 ) +
F_16 ( V_42 , V_99 , V_102 ) +
F_16 ( V_42 , V_104 , V_100 ) +
F_16 ( V_42 , V_104 , V_102 ) ) {
F_9 ( V_2 ,
L_14 ,
( int ) V_87 -> V_15 ) ;
return - V_16 ;
}
F_14 ( V_42 , V_99 , V_100 , V_94 ) ;
V_94 += F_16 ( V_42 , V_99 , V_100 ) ;
F_17 ( V_42 , V_99 , V_100 ,
V_109 ) ;
F_14 ( V_42 , V_99 , V_102 , V_94 ) ;
V_94 += F_16 ( V_42 , V_99 , V_102 ) ;
F_17 ( V_42 , V_99 , V_102 ,
V_110 ) ;
F_14 ( V_42 , V_104 , V_100 , V_94 ) ;
V_94 += F_16 ( V_42 , V_104 , V_100 ) ;
F_17 ( V_42 , V_104 , V_100 ,
V_109 ) ;
F_14 ( V_42 , V_104 , V_102 , V_94 ) ;
V_94 += F_16 ( V_42 , V_104 , V_102 ) ;
F_17 ( V_42 , V_104 , V_102 ,
V_110 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
const struct V_86 * V_87 ,
struct V_41 * V_42 ,
struct V_74 * V_75 )
{
struct V_111 * V_89 = ( void * ) V_87 -> V_5 ;
struct V_112 * V_113 ;
T_1 V_6 = V_87 -> V_15 ;
const T_3 * V_5 ;
T_2 V_114 ;
enum V_115 V_116 ;
const T_3 * V_117 ;
char V_93 [ 25 ] ;
T_2 V_92 ;
int V_118 ;
if ( V_6 < sizeof( * V_89 ) ) {
F_9 ( V_2 , L_15 , V_6 ) ;
return - V_16 ;
}
if ( V_89 -> V_119 != F_32 ( V_120 ) ) {
F_9 ( V_2 , L_16 ,
F_19 ( V_89 -> V_119 ) ) ;
return - V_16 ;
}
V_2 -> V_13 . V_95 = F_19 ( V_89 -> V_96 ) ;
memcpy ( V_2 -> V_13 . V_121 , V_89 -> V_121 ,
sizeof( V_2 -> V_13 . V_121 ) ) ;
V_92 = F_19 ( V_89 -> V_92 ) ;
if ( V_92 )
sprintf ( V_93 , L_11 , V_92 ,
( V_2 -> V_24 == V_25 )
? L_12 : L_7 ) ;
else
V_93 [ 0 ] = '\0' ;
snprintf ( V_2 -> V_13 . V_108 ,
sizeof( V_2 -> V_13 . V_108 ) ,
L_13 ,
F_28 ( V_2 -> V_13 . V_95 ) ,
F_29 ( V_2 -> V_13 . V_95 ) ,
F_27 ( V_2 -> V_13 . V_95 ) ,
F_30 ( V_2 -> V_13 . V_95 ) ,
V_93 ) ;
V_5 = V_89 -> V_5 ;
V_6 -= sizeof( * V_89 ) ;
while ( V_6 >= sizeof( * V_113 ) ) {
V_6 -= sizeof( * V_113 ) ;
V_113 = ( void * ) V_5 ;
V_114 = F_19 ( V_113 -> V_122 ) ;
V_116 = F_19 ( V_113 -> type ) ;
V_117 = V_113 -> V_5 ;
if ( V_6 < V_114 ) {
F_9 ( V_2 , L_17 ,
V_6 , V_114 ) ;
return - V_16 ;
}
V_6 -= F_33 ( V_114 , 4 ) ;
V_5 += sizeof( * V_113 ) + F_33 ( V_114 , 4 ) ;
switch ( V_116 ) {
case V_123 :
F_14 ( V_42 , V_99 ,
V_100 , V_117 ) ;
F_15 ( V_42 , V_99 ,
V_100 , V_114 ) ;
F_17 ( V_42 , V_99 ,
V_100 ,
V_109 ) ;
break;
case V_124 :
F_14 ( V_42 , V_99 ,
V_102 , V_117 ) ;
F_15 ( V_42 , V_99 ,
V_102 , V_114 ) ;
F_17 ( V_42 , V_99 ,
V_102 ,
V_110 ) ;
break;
case V_125 :
F_14 ( V_42 , V_104 ,
V_100 , V_117 ) ;
F_15 ( V_42 , V_104 ,
V_100 , V_114 ) ;
F_17 ( V_42 , V_104 ,
V_100 ,
V_109 ) ;
break;
case V_126 :
F_14 ( V_42 , V_104 ,
V_102 , V_117 ) ;
F_15 ( V_42 , V_104 ,
V_102 , V_114 ) ;
F_17 ( V_42 , V_104 ,
V_102 ,
V_110 ) ;
break;
case V_127 :
F_9 ( V_2 , L_18 ) ;
break;
case V_128 :
if ( V_114 != sizeof( T_2 ) )
goto V_129;
V_75 -> V_130 =
F_34 ( ( V_131 * ) V_117 ) ;
break;
case V_132 :
if ( V_114 )
goto V_129;
V_75 -> V_133 |= V_134 ;
break;
case V_135 :
if ( V_114 < sizeof( T_2 ) )
goto V_129;
if ( V_114 % sizeof( T_2 ) )
goto V_129;
V_75 -> V_133 = F_34 ( ( V_131 * ) V_117 ) ;
break;
case V_136 :
if ( V_114 != sizeof( struct V_76 ) )
goto V_129;
if ( F_24 ( V_2 , V_117 , V_75 ) )
goto V_137;
break;
case V_138 :
if ( V_114 != sizeof( struct V_82 ) )
goto V_129;
if ( F_25 ( V_2 , V_117 , V_75 ) )
goto V_137;
break;
case V_139 :
if ( V_114 != sizeof( T_2 ) )
goto V_129;
V_42 -> V_140 =
F_34 ( ( V_131 * ) V_117 ) ;
break;
case V_141 :
if ( V_114 != sizeof( T_2 ) )
goto V_129;
V_42 -> V_142 =
F_34 ( ( V_131 * ) V_117 ) ;
break;
case V_143 :
if ( V_114 != sizeof( T_2 ) )
goto V_129;
V_42 -> V_144 =
F_34 ( ( V_131 * ) V_117 ) ;
break;
case V_145 :
if ( V_114 != sizeof( T_2 ) )
goto V_129;
V_42 -> V_146 =
F_34 ( ( V_131 * ) V_117 ) ;
break;
case V_147 :
if ( V_114 != sizeof( T_2 ) )
goto V_129;
V_42 -> V_148 =
F_34 ( ( V_131 * ) V_117 ) ;
break;
case V_149 :
if ( V_114 != sizeof( T_2 ) )
goto V_129;
V_42 -> V_150 =
F_34 ( ( V_131 * ) V_117 ) ;
break;
case V_151 :
if ( V_114 )
goto V_129;
V_2 -> V_13 . V_152 = true ;
break;
case V_153 :
F_14 ( V_42 , V_154 ,
V_100 , V_117 ) ;
F_15 ( V_42 , V_154 ,
V_100 , V_114 ) ;
F_17 ( V_42 , V_154 ,
V_100 ,
V_109 ) ;
break;
case V_155 :
F_14 ( V_42 , V_154 ,
V_102 , V_117 ) ;
F_15 ( V_42 , V_154 ,
V_102 , V_114 ) ;
F_17 ( V_42 , V_154 ,
V_102 ,
V_110 ) ;
break;
case V_156 :
if ( V_114 != sizeof( T_2 ) )
goto V_129;
V_75 -> V_157 =
F_34 ( ( V_131 * ) V_117 ) ;
break;
case V_158 :
F_21 ( V_42 , V_117 , V_99 ,
V_114 ) ;
V_2 -> V_13 . V_159 = true ;
break;
case V_160 :
F_21 ( V_42 , V_117 , V_104 ,
V_114 ) ;
V_2 -> V_13 . V_159 = true ;
break;
case V_161 :
F_21 ( V_42 , V_117 , V_154 ,
V_114 ) ;
V_2 -> V_13 . V_159 = true ;
break;
case V_162 :
if ( V_114 != sizeof( struct V_67 ) )
goto V_129;
if ( F_23 ( V_2 , V_117 ) )
goto V_137;
break;
case V_163 :
if ( V_114 != sizeof( T_2 ) )
goto V_129;
V_2 -> V_13 . V_164 = F_34 ( ( V_131 * ) V_117 ) ;
V_2 -> V_13 . V_165 = ( V_2 -> V_13 . V_164 &
V_166 ) >>
V_167 ;
V_2 -> V_13 . V_168 = ( V_2 -> V_13 . V_164 &
V_169 ) >>
V_170 ;
break;
case V_171 :
F_21 ( V_42 , V_117 , V_99 ,
V_114 ) ;
V_2 -> V_13 . V_159 = true ;
V_2 -> V_13 . V_8 [ V_99 ] . V_172 = true ;
break;
case V_173 :
F_21 ( V_42 , V_117 , V_104 ,
V_114 ) ;
V_2 -> V_13 . V_159 = true ;
V_2 -> V_13 . V_8 [ V_104 ] . V_172 = true ;
break;
case V_174 :
F_21 ( V_42 , V_117 , V_154 ,
V_114 ) ;
V_2 -> V_13 . V_159 = true ;
V_2 -> V_13 . V_8 [ V_154 ] . V_172 = true ;
break;
case V_175 :
if ( V_114 != sizeof( T_2 ) )
goto V_129;
V_118 =
F_34 ( ( V_131 * ) V_117 ) ;
if ( V_118 == 2 ) {
V_2 -> V_13 . V_8 [ V_99 ] . V_176 =
true ;
V_2 -> V_13 . V_8 [ V_104 ] . V_176 =
true ;
V_2 -> V_13 . V_8 [ V_154 ] . V_176 =
true ;
} else if ( ( V_118 > 2 ) || ( V_118 < 1 ) ) {
F_9 ( V_2 , L_19 ) ;
return - V_16 ;
}
break;
case V_177 :
if ( F_18 ( & V_2 -> V_13 , V_117 , V_114 ) )
goto V_129;
break;
case V_178 :
if ( V_114 != sizeof( T_2 ) )
goto V_129;
V_75 -> V_179 =
F_34 ( ( V_131 * ) V_117 ) ;
break;
default:
F_11 ( V_2 , L_20 , V_116 ) ;
break;
}
}
if ( V_6 ) {
F_9 ( V_2 , L_21 , V_6 ) ;
F_35 ( V_2 , V_180 , ( T_3 * ) V_5 , V_6 ) ;
return - V_16 ;
}
return 0 ;
V_129:
F_9 ( V_2 , L_22 , V_116 , V_114 ) ;
V_137:
F_35 ( V_2 , V_180 , V_117 , V_114 ) ;
return - V_16 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_41 * V_42 ,
enum V_43 type )
{
int V_9 ;
for ( V_9 = 0 ;
V_9 < V_10 && F_16 ( V_42 , type , V_9 ) ;
V_9 ++ )
if ( F_5 ( V_2 , & ( V_2 -> V_13 . V_8 [ type ] . V_11 [ V_9 ] ) ,
F_13 ( V_42 , type , V_9 ) ) )
return - V_17 ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_41 * V_42 ,
const struct V_181 * V_21 )
{
F_11 ( V_2 , L_23 ,
F_16 ( V_42 , V_99 ,
V_100 ) ) ;
F_11 ( V_2 , L_24 ,
F_16 ( V_42 , V_99 ,
V_102 ) ) ;
F_11 ( V_2 , L_25 ,
F_16 ( V_42 , V_104 , V_100 ) ) ;
F_11 ( V_2 , L_26 ,
F_16 ( V_42 , V_104 , V_102 ) ) ;
if ( F_16 ( V_42 , V_99 , V_100 ) >
V_21 -> V_182 ) {
F_9 ( V_2 , L_27 ,
F_16 ( V_42 , V_99 ,
V_100 ) ) ;
return - 1 ;
}
if ( F_16 ( V_42 , V_99 , V_102 ) >
V_21 -> V_183 ) {
F_9 ( V_2 , L_28 ,
F_16 ( V_42 , V_99 ,
V_102 ) ) ;
return - 1 ;
}
if ( F_16 ( V_42 , V_104 , V_100 ) >
V_21 -> V_182 ) {
F_9 ( V_2 , L_29 ,
F_16 ( V_42 , V_104 ,
V_100 ) ) ;
return - 1 ;
}
if ( F_16 ( V_42 , V_104 , V_102 ) >
V_21 -> V_183 ) {
F_9 ( V_2 , L_30 ,
F_16 ( V_42 , V_99 ,
V_102 ) ) ;
return - 1 ;
}
return 0 ;
}
static struct V_184 *
F_38 ( struct V_1 * V_2 , struct V_185 * V_186 )
{
const struct V_187 * V_188 = V_186 -> V_188 ;
struct V_189 * V_190 = NULL ;
struct V_184 * V_191 = NULL ;
#ifdef F_39
V_2 -> V_192 = F_40 ( V_186 -> V_193 ,
V_2 -> V_194 ) ;
if ( ! V_2 -> V_192 ) {
F_9 ( V_2 ,
L_31 ) ;
return V_191 ;
}
V_190 = V_2 -> V_192 ;
#endif
V_191 = V_188 -> V_195 ( V_2 -> V_31 , V_2 -> V_21 , & V_2 -> V_13 , V_190 ) ;
#ifdef F_39
if ( ! V_191 ) {
F_41 ( V_2 -> V_192 ) ;
V_2 -> V_192 = NULL ;
}
#endif
return V_191 ;
}
static void F_42 ( struct V_1 * V_2 )
{
if ( V_2 -> V_191 ) {
F_43 ( V_2 -> V_191 ) ;
V_2 -> V_191 = NULL ;
#ifdef F_39
F_41 ( V_2 -> V_192 ) ;
V_2 -> V_192 = NULL ;
#endif
}
}
static void V_40 ( const struct V_86 * V_87 , void * V_196 )
{
struct V_1 * V_2 = V_196 ;
struct V_44 * V_13 = & V_2 -> V_13 ;
struct V_88 * V_89 ;
struct V_185 * V_186 ;
int V_197 ;
struct V_41 V_42 ;
const unsigned int V_198 = V_2 -> V_21 -> V_27 ;
unsigned int V_199 = V_2 -> V_21 -> V_200 ;
const unsigned int V_201 = V_2 -> V_21 -> V_28 ;
T_2 V_90 ;
int V_9 ;
bool V_202 = false ;
V_13 -> V_83 . V_130 = V_203 ;
V_13 -> V_83 . V_157 =
V_204 ;
V_13 -> V_83 . V_179 = V_205 ;
if ( ! V_199 )
V_199 = V_198 ;
memset ( & V_42 , 0 , sizeof( V_42 ) ) ;
if ( ! V_87 ) {
if ( V_2 -> V_24 <= V_199 )
F_9 ( V_2 ,
L_32 ,
V_2 -> V_30 ) ;
goto V_206;
}
F_11 ( V_2 , L_33 ,
V_2 -> V_30 , V_87 -> V_15 ) ;
if ( V_87 -> V_15 < 4 ) {
F_9 ( V_2 , L_34 ) ;
goto V_206;
}
V_89 = (struct V_88 * ) V_87 -> V_5 ;
if ( V_89 -> V_96 )
V_197 = F_26 ( V_2 , V_87 , & V_42 ) ;
else
V_197 = F_31 ( V_2 , V_87 , & V_42 ,
& V_13 -> V_83 ) ;
if ( V_197 )
goto V_206;
V_90 = F_27 ( V_2 -> V_13 . V_95 ) ;
if ( V_2 -> V_24 != V_25 ) {
if ( V_90 < V_201 || V_90 > V_198 ) {
F_9 ( V_2 ,
L_35
L_36 ,
V_198 , V_90 ) ;
goto V_206;
}
if ( V_90 < V_199 ) {
if ( V_199 != V_198 )
F_9 ( V_2 , L_37
L_38 ,
V_199 , V_198 , V_90 ) ;
else
F_9 ( V_2 , L_37
L_39 ,
V_198 , V_90 ) ;
F_9 ( V_2 , L_40
L_41 ) ;
}
}
if ( ! V_13 -> V_159 && F_37 ( V_2 , & V_42 , V_2 -> V_21 ) )
goto V_206;
for ( V_9 = 0 ; V_9 < V_12 ; V_9 ++ )
if ( F_36 ( V_2 , & V_42 , V_9 ) )
goto V_207;
V_13 -> V_140 = V_42 . V_140 ;
if ( V_42 . V_142 )
V_13 -> V_142 = ( V_42 . V_142 - 16 ) / 12 ;
else
V_13 -> V_142 =
V_2 -> V_21 -> V_208 -> V_209 ;
V_13 -> V_144 = V_42 . V_144 ;
V_13 -> V_146 = V_42 . V_146 ;
if ( V_42 . V_148 )
V_13 -> V_148 = ( V_42 . V_148 - 16 ) / 12 ;
else
V_13 -> V_148 =
V_2 -> V_21 -> V_208 -> V_209 ;
V_13 -> V_150 = V_42 . V_150 ;
if ( V_13 -> V_83 . V_157 >
V_210 )
V_13 -> V_83 . V_157 =
V_211 ;
F_44 ( V_87 ) ;
F_45 ( & V_212 ) ;
if ( V_13 -> V_159 )
V_186 = & V_185 [ V_213 ] ;
else
V_186 = & V_185 [ V_214 ] ;
F_46 ( V_2 , L_42 ,
V_2 -> V_13 . V_108 , V_186 -> V_193 ) ;
F_47 ( & V_2 -> V_215 , & V_186 -> V_2 ) ;
if ( V_186 -> V_188 ) {
V_2 -> V_191 = F_38 ( V_2 , V_186 ) ;
if ( ! V_2 -> V_191 ) {
F_48 ( & V_212 ) ;
goto V_216;
}
} else {
V_202 = true ;
}
F_48 ( & V_212 ) ;
F_49 ( & V_2 -> V_217 ) ;
if ( V_202 ) {
V_197 = F_50 ( L_43 , V_186 -> V_193 ) ;
#ifdef F_51
if ( V_197 )
F_9 ( V_2 ,
L_44 ,
V_186 -> V_193 , V_197 ) ;
#endif
}
return;
V_206:
F_44 ( V_87 ) ;
if ( F_7 ( V_2 , false ) )
goto V_216;
return;
V_207:
F_9 ( V_2 , L_45 ) ;
F_4 ( V_2 ) ;
F_44 ( V_87 ) ;
V_216:
F_49 ( & V_2 -> V_217 ) ;
F_52 ( V_2 -> V_31 -> V_38 ) ;
}
struct V_1 * F_53 ( struct V_218 * V_31 ,
const struct V_181 * V_21 )
{
struct V_1 * V_2 ;
int V_219 ;
V_2 = F_54 ( sizeof( * V_2 ) , V_39 ) ;
if ( ! V_2 ) {
V_219 = - V_17 ;
goto V_197;
}
V_2 -> V_31 = V_31 ;
V_2 -> V_38 = V_31 -> V_38 ;
V_2 -> V_21 = V_21 ;
F_55 ( & V_2 -> V_217 ) ;
F_56 ( & V_2 -> V_215 ) ;
#ifdef F_39
V_2 -> V_194 = F_40 ( F_57 ( V_31 -> V_38 ) ,
V_220 ) ;
if ( ! V_2 -> V_194 ) {
F_9 ( V_2 , L_46 ) ;
V_219 = - V_17 ;
goto V_221;
}
V_2 -> V_31 -> V_190 = F_40 ( L_47 , V_2 -> V_194 ) ;
if ( ! V_2 -> V_31 -> V_190 ) {
F_9 ( V_2 , L_48 ) ;
V_219 = - V_17 ;
goto V_222;
}
#endif
V_219 = F_7 ( V_2 , true ) ;
if ( V_219 ) {
F_9 ( V_31 , L_49 ) ;
goto V_223;
}
return V_2 ;
V_223:
#ifdef F_39
V_222:
F_41 ( V_2 -> V_194 ) ;
V_221:
#endif
F_58 ( V_2 ) ;
V_197:
return F_59 ( V_219 ) ;
}
void F_60 ( struct V_1 * V_2 )
{
F_61 ( & V_2 -> V_217 ) ;
F_42 ( V_2 ) ;
F_4 ( V_2 ) ;
F_45 ( & V_212 ) ;
if ( ! F_62 ( & V_2 -> V_215 ) )
F_63 ( & V_2 -> V_215 ) ;
F_48 ( & V_212 ) ;
#ifdef F_39
F_41 ( V_2 -> V_194 ) ;
#endif
F_58 ( V_2 ) ;
}
int F_64 ( const char * V_193 , const struct V_187 * V_188 )
{
int V_9 ;
struct V_1 * V_2 ;
struct V_185 * V_186 ;
F_45 ( & V_212 ) ;
for ( V_9 = 0 ; V_9 < F_65 ( V_185 ) ; V_9 ++ ) {
V_186 = & V_185 [ V_9 ] ;
if ( strcmp ( V_186 -> V_193 , V_193 ) )
continue;
V_186 -> V_188 = V_188 ;
F_66 (drv, &op->drv, list)
V_2 -> V_191 = F_38 ( V_2 , V_186 ) ;
F_48 ( & V_212 ) ;
return 0 ;
}
F_48 ( & V_212 ) ;
return - V_224 ;
}
void F_67 ( const char * V_193 )
{
int V_9 ;
struct V_1 * V_2 ;
F_45 ( & V_212 ) ;
for ( V_9 = 0 ; V_9 < F_65 ( V_185 ) ; V_9 ++ ) {
if ( strcmp ( V_185 [ V_9 ] . V_193 , V_193 ) )
continue;
V_185 [ V_9 ] . V_188 = NULL ;
F_66 (drv, &iwlwifi_opmode_table[i].drv, list)
F_42 ( V_2 ) ;
F_48 ( & V_212 ) ;
return;
}
F_48 ( & V_212 ) ;
}
static int T_4 F_68 ( void )
{
int V_9 ;
F_69 ( & V_212 ) ;
for ( V_9 = 0 ; V_9 < F_65 ( V_185 ) ; V_9 ++ )
F_56 ( & V_185 [ V_9 ] . V_2 ) ;
F_70 ( V_225 L_50 V_226 L_51 ) ;
F_70 ( V_227 L_51 ) ;
#ifdef F_39
V_220 = F_40 ( V_228 , NULL ) ;
if ( ! V_220 )
return - V_229 ;
#endif
return F_71 () ;
}
static void T_5 F_72 ( void )
{
F_73 () ;
#ifdef F_39
F_41 ( V_220 ) ;
#endif
}
