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
sprintf ( V_2 -> V_30 , L_3 , V_20 , V_23 , L_4 ) ;
F_10 ( V_2 , L_5 ,
( V_2 -> V_24 == V_25 )
? L_6 : L_7 ,
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
F_9 ( V_2 , L_8 ,
V_64 ) ;
return - V_16 ;
}
V_2 -> V_13 . V_65 [ V_64 ] . V_66 =
V_63 -> V_67 . V_66 ;
V_2 -> V_13 . V_65 [ V_64 ] . V_68 =
V_63 -> V_67 . V_68 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
const struct V_69 * V_70 ,
struct V_36 * V_37 )
{
struct V_71 * V_72 = ( void * ) V_70 -> V_5 ;
T_2 V_73 , V_74 , V_75 ;
char V_76 [ 25 ] ;
const T_3 * V_77 ;
V_2 -> V_13 . V_78 = F_18 ( V_72 -> V_79 ) ;
V_73 = F_24 ( V_2 -> V_13 . V_78 ) ;
switch ( V_73 ) {
default:
V_74 = 28 ;
if ( V_70 -> V_15 < V_74 ) {
F_9 ( V_2 , L_9 ) ;
return - V_16 ;
}
V_75 = F_18 ( V_72 -> V_80 . V_81 . V_75 ) ;
F_14 ( V_37 , V_82 , V_83 ,
F_18 ( V_72 -> V_80 . V_81 . V_84 ) ) ;
F_14 ( V_37 , V_82 , V_85 ,
F_18 ( V_72 -> V_80 . V_81 . V_86 ) ) ;
F_14 ( V_37 , V_87 , V_83 ,
F_18 ( V_72 -> V_80 . V_81 . V_88 ) ) ;
F_14 ( V_37 , V_87 , V_85 ,
F_18 ( V_72 -> V_80 . V_81 . V_89 ) ) ;
V_77 = V_72 -> V_80 . V_81 . V_5 ;
break;
case 0 :
case 1 :
case 2 :
V_74 = 24 ;
if ( V_70 -> V_15 < V_74 ) {
F_9 ( V_2 , L_9 ) ;
return - V_16 ;
}
V_75 = 0 ;
F_14 ( V_37 , V_82 , V_83 ,
F_18 ( V_72 -> V_80 . V_90 . V_84 ) ) ;
F_14 ( V_37 , V_82 , V_85 ,
F_18 ( V_72 -> V_80 . V_90 . V_86 ) ) ;
F_14 ( V_37 , V_87 , V_83 ,
F_18 ( V_72 -> V_80 . V_90 . V_88 ) ) ;
F_14 ( V_37 , V_87 , V_85 ,
F_18 ( V_72 -> V_80 . V_90 . V_89 ) ) ;
V_77 = V_72 -> V_80 . V_90 . V_5 ;
break;
}
if ( V_75 )
sprintf ( V_76 , L_10 , V_75 ,
( V_2 -> V_24 == V_25 )
? L_11 : L_7 ) ;
else
V_76 [ 0 ] = '\0' ;
snprintf ( V_2 -> V_13 . V_91 ,
sizeof( V_2 -> V_13 . V_91 ) ,
L_12 ,
F_25 ( V_2 -> V_13 . V_78 ) ,
F_26 ( V_2 -> V_13 . V_78 ) ,
F_24 ( V_2 -> V_13 . V_78 ) ,
F_27 ( V_2 -> V_13 . V_78 ) ,
V_76 ) ;
if ( V_70 -> V_15 != V_74 +
F_15 ( V_37 , V_82 , V_83 ) +
F_15 ( V_37 , V_82 , V_85 ) +
F_15 ( V_37 , V_87 , V_83 ) +
F_15 ( V_37 , V_87 , V_85 ) ) {
F_9 ( V_2 ,
L_13 ,
( int ) V_70 -> V_15 ) ;
return - V_16 ;
}
F_13 ( V_37 , V_82 , V_83 , V_77 ) ;
V_77 += F_15 ( V_37 , V_82 , V_83 ) ;
F_16 ( V_37 , V_82 , V_83 ,
V_92 ) ;
F_13 ( V_37 , V_82 , V_85 , V_77 ) ;
V_77 += F_15 ( V_37 , V_82 , V_85 ) ;
F_16 ( V_37 , V_82 , V_85 ,
V_93 ) ;
F_13 ( V_37 , V_87 , V_83 , V_77 ) ;
V_77 += F_15 ( V_37 , V_87 , V_83 ) ;
F_16 ( V_37 , V_87 , V_83 ,
V_92 ) ;
F_13 ( V_37 , V_87 , V_85 , V_77 ) ;
V_77 += F_15 ( V_37 , V_87 , V_85 ) ;
F_16 ( V_37 , V_87 , V_85 ,
V_93 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
const struct V_69 * V_70 ,
struct V_36 * V_37 ,
struct V_94 * V_95 )
{
struct V_96 * V_72 = ( void * ) V_70 -> V_5 ;
struct V_97 * V_98 ;
T_1 V_6 = V_70 -> V_15 ;
const T_3 * V_5 ;
T_2 V_99 ;
enum V_100 V_101 ;
const T_3 * V_102 ;
char V_76 [ 25 ] ;
T_2 V_75 ;
int V_103 ;
if ( V_6 < sizeof( * V_72 ) ) {
F_9 ( V_2 , L_14 , V_6 ) ;
return - V_16 ;
}
if ( V_72 -> V_104 != F_29 ( V_105 ) ) {
F_9 ( V_2 , L_15 ,
F_18 ( V_72 -> V_104 ) ) ;
return - V_16 ;
}
V_2 -> V_13 . V_78 = F_18 ( V_72 -> V_79 ) ;
V_75 = F_18 ( V_72 -> V_75 ) ;
if ( V_75 )
sprintf ( V_76 , L_10 , V_75 ,
( V_2 -> V_24 == V_25 )
? L_11 : L_7 ) ;
else
V_76 [ 0 ] = '\0' ;
snprintf ( V_2 -> V_13 . V_91 ,
sizeof( V_2 -> V_13 . V_91 ) ,
L_12 ,
F_25 ( V_2 -> V_13 . V_78 ) ,
F_26 ( V_2 -> V_13 . V_78 ) ,
F_24 ( V_2 -> V_13 . V_78 ) ,
F_27 ( V_2 -> V_13 . V_78 ) ,
V_76 ) ;
V_5 = V_72 -> V_5 ;
V_6 -= sizeof( * V_72 ) ;
while ( V_6 >= sizeof( * V_98 ) ) {
V_6 -= sizeof( * V_98 ) ;
V_98 = ( void * ) V_5 ;
V_99 = F_18 ( V_98 -> V_106 ) ;
V_101 = F_18 ( V_98 -> type ) ;
V_102 = V_98 -> V_5 ;
if ( V_6 < V_99 ) {
F_9 ( V_2 , L_16 ,
V_6 , V_99 ) ;
return - V_16 ;
}
V_6 -= F_30 ( V_99 , 4 ) ;
V_5 += sizeof( * V_98 ) + F_30 ( V_99 , 4 ) ;
switch ( V_101 ) {
case V_107 :
F_13 ( V_37 , V_82 ,
V_83 , V_102 ) ;
F_14 ( V_37 , V_82 ,
V_83 , V_99 ) ;
F_16 ( V_37 , V_82 ,
V_83 ,
V_92 ) ;
break;
case V_108 :
F_13 ( V_37 , V_82 ,
V_85 , V_102 ) ;
F_14 ( V_37 , V_82 ,
V_85 , V_99 ) ;
F_16 ( V_37 , V_82 ,
V_85 ,
V_93 ) ;
break;
case V_109 :
F_13 ( V_37 , V_87 ,
V_83 , V_102 ) ;
F_14 ( V_37 , V_87 ,
V_83 , V_99 ) ;
F_16 ( V_37 , V_87 ,
V_83 ,
V_92 ) ;
break;
case V_110 :
F_13 ( V_37 , V_87 ,
V_85 , V_102 ) ;
F_14 ( V_37 , V_87 ,
V_85 , V_99 ) ;
F_16 ( V_37 , V_87 ,
V_85 ,
V_93 ) ;
break;
case V_111 :
F_9 ( V_2 , L_17 ) ;
break;
case V_112 :
if ( V_99 != sizeof( T_2 ) )
goto V_113;
V_95 -> V_114 =
F_31 ( ( V_115 * ) V_102 ) ;
break;
case V_116 :
if ( V_99 )
goto V_113;
V_95 -> V_117 |= V_118 ;
break;
case V_119 :
if ( V_99 < sizeof( T_2 ) )
goto V_113;
if ( V_99 % sizeof( T_2 ) )
goto V_113;
V_95 -> V_117 = F_31 ( ( V_115 * ) V_102 ) ;
break;
case V_120 :
if ( V_99 != sizeof( T_2 ) )
goto V_113;
V_37 -> V_121 =
F_31 ( ( V_115 * ) V_102 ) ;
break;
case V_122 :
if ( V_99 != sizeof( T_2 ) )
goto V_113;
V_37 -> V_123 =
F_31 ( ( V_115 * ) V_102 ) ;
break;
case V_124 :
if ( V_99 != sizeof( T_2 ) )
goto V_113;
V_37 -> V_125 =
F_31 ( ( V_115 * ) V_102 ) ;
break;
case V_126 :
if ( V_99 != sizeof( T_2 ) )
goto V_113;
V_37 -> V_127 =
F_31 ( ( V_115 * ) V_102 ) ;
break;
case V_128 :
if ( V_99 != sizeof( T_2 ) )
goto V_113;
V_37 -> V_129 =
F_31 ( ( V_115 * ) V_102 ) ;
break;
case V_130 :
if ( V_99 != sizeof( T_2 ) )
goto V_113;
V_37 -> V_131 =
F_31 ( ( V_115 * ) V_102 ) ;
break;
case V_132 :
if ( V_99 )
goto V_113;
V_2 -> V_13 . V_133 = true ;
break;
case V_134 :
F_13 ( V_37 , V_135 ,
V_83 , V_102 ) ;
F_14 ( V_37 , V_135 ,
V_83 , V_99 ) ;
F_16 ( V_37 , V_135 ,
V_83 ,
V_92 ) ;
break;
case V_136 :
F_13 ( V_37 , V_135 ,
V_85 , V_102 ) ;
F_14 ( V_37 , V_135 ,
V_85 , V_99 ) ;
F_16 ( V_37 , V_135 ,
V_85 ,
V_93 ) ;
break;
case V_137 :
if ( V_99 != sizeof( T_2 ) )
goto V_113;
V_95 -> V_138 =
F_31 ( ( V_115 * ) V_102 ) ;
break;
case V_139 :
F_20 ( V_37 , V_102 , V_82 ,
V_99 ) ;
V_2 -> V_13 . V_140 = true ;
break;
case V_141 :
F_20 ( V_37 , V_102 , V_87 ,
V_99 ) ;
V_2 -> V_13 . V_140 = true ;
break;
case V_142 :
F_20 ( V_37 , V_102 , V_135 ,
V_99 ) ;
V_2 -> V_13 . V_140 = true ;
break;
case V_143 :
if ( V_99 != sizeof( struct V_62 ) )
goto V_113;
if ( F_22 ( V_2 , V_102 ) )
goto V_144;
break;
case V_145 :
if ( V_99 != sizeof( T_2 ) )
goto V_113;
V_2 -> V_13 . V_146 = F_31 ( ( V_115 * ) V_102 ) ;
break;
case V_147 :
F_20 ( V_37 , V_102 , V_82 ,
V_99 ) ;
V_2 -> V_13 . V_140 = true ;
V_2 -> V_13 . V_8 [ V_82 ] . V_148 = true ;
break;
case V_149 :
F_20 ( V_37 , V_102 , V_87 ,
V_99 ) ;
V_2 -> V_13 . V_140 = true ;
V_2 -> V_13 . V_8 [ V_87 ] . V_148 = true ;
break;
case V_150 :
F_20 ( V_37 , V_102 , V_135 ,
V_99 ) ;
V_2 -> V_13 . V_140 = true ;
V_2 -> V_13 . V_8 [ V_135 ] . V_148 = true ;
break;
case V_151 :
if ( V_99 != sizeof( T_2 ) )
goto V_113;
V_103 =
F_31 ( ( V_115 * ) V_102 ) ;
if ( V_103 == 2 ) {
V_2 -> V_13 . V_8 [ V_82 ] . V_152 =
true ;
V_2 -> V_13 . V_8 [ V_87 ] . V_152 =
true ;
V_2 -> V_13 . V_8 [ V_135 ] . V_152 =
true ;
} else if ( ( V_103 > 2 ) || ( V_103 < 1 ) ) {
F_9 ( V_2 , L_18 ) ;
return - V_16 ;
}
break;
case V_153 :
if ( F_17 ( & V_2 -> V_13 , V_102 , V_99 ) )
goto V_113;
break;
default:
F_10 ( V_2 , L_19 , V_101 ) ;
break;
}
}
if ( V_6 ) {
F_9 ( V_2 , L_20 , V_6 ) ;
F_32 ( V_2 , V_154 , ( T_3 * ) V_5 , V_6 ) ;
return - V_16 ;
}
return 0 ;
V_113:
F_9 ( V_2 , L_21 , V_101 , V_99 ) ;
V_144:
F_32 ( V_2 , V_154 , V_102 , V_99 ) ;
return - V_16 ;
}
static int F_33 ( struct V_1 * V_2 ,
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
static int F_34 ( struct V_1 * V_2 ,
struct V_36 * V_37 ,
const struct V_155 * V_21 )
{
F_10 ( V_2 , L_22 ,
F_15 ( V_37 , V_82 ,
V_83 ) ) ;
F_10 ( V_2 , L_23 ,
F_15 ( V_37 , V_82 ,
V_85 ) ) ;
F_10 ( V_2 , L_24 ,
F_15 ( V_37 , V_87 , V_83 ) ) ;
F_10 ( V_2 , L_25 ,
F_15 ( V_37 , V_87 , V_85 ) ) ;
if ( F_15 ( V_37 , V_82 , V_83 ) >
V_21 -> V_156 ) {
F_9 ( V_2 , L_26 ,
F_15 ( V_37 , V_82 ,
V_83 ) ) ;
return - 1 ;
}
if ( F_15 ( V_37 , V_82 , V_85 ) >
V_21 -> V_157 ) {
F_9 ( V_2 , L_27 ,
F_15 ( V_37 , V_82 ,
V_85 ) ) ;
return - 1 ;
}
if ( F_15 ( V_37 , V_87 , V_83 ) >
V_21 -> V_156 ) {
F_9 ( V_2 , L_28 ,
F_15 ( V_37 , V_87 ,
V_83 ) ) ;
return - 1 ;
}
if ( F_15 ( V_37 , V_87 , V_85 ) >
V_21 -> V_157 ) {
F_9 ( V_2 , L_29 ,
F_15 ( V_37 , V_82 ,
V_85 ) ) ;
return - 1 ;
}
return 0 ;
}
static struct V_158 *
F_35 ( struct V_1 * V_2 , struct V_159 * V_160 )
{
const struct V_161 * V_162 = V_160 -> V_162 ;
struct V_163 * V_164 = NULL ;
struct V_158 * V_165 = NULL ;
#ifdef F_36
V_2 -> V_166 = F_37 ( V_160 -> V_167 ,
V_2 -> V_168 ) ;
if ( ! V_2 -> V_166 ) {
F_9 ( V_2 ,
L_30 ) ;
return V_165 ;
}
V_164 = V_2 -> V_166 ;
#endif
V_165 = V_162 -> V_169 ( V_2 -> V_32 , V_2 -> V_21 , & V_2 -> V_13 , V_164 ) ;
#ifdef F_36
if ( ! V_165 ) {
F_38 ( V_2 -> V_166 ) ;
V_2 -> V_166 = NULL ;
}
#endif
return V_165 ;
}
static void F_39 ( struct V_1 * V_2 )
{
if ( V_2 -> V_165 ) {
F_40 ( V_2 -> V_165 ) ;
V_2 -> V_165 = NULL ;
#ifdef F_36
F_38 ( V_2 -> V_166 ) ;
V_2 -> V_166 = NULL ;
#endif
}
}
static void V_35 ( const struct V_69 * V_70 , void * V_170 )
{
struct V_1 * V_2 = V_170 ;
struct V_39 * V_13 = & V_2 -> V_13 ;
struct V_71 * V_72 ;
struct V_159 * V_160 ;
int V_171 ;
struct V_36 V_37 ;
const unsigned int V_172 = V_2 -> V_21 -> V_27 ;
unsigned int V_173 = V_2 -> V_21 -> V_174 ;
const unsigned int V_175 = V_2 -> V_21 -> V_28 ;
T_2 V_73 ;
int V_9 ;
bool V_176 = false ;
V_13 -> V_177 . V_114 = V_178 ;
V_13 -> V_177 . V_138 =
V_179 ;
if ( ! V_173 )
V_173 = V_172 ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
if ( ! V_70 ) {
if ( V_2 -> V_24 <= V_173 )
F_9 ( V_2 ,
L_31 ,
V_2 -> V_30 ) ;
goto V_180;
}
F_10 ( V_2 , L_32 ,
V_2 -> V_30 , V_70 -> V_15 ) ;
if ( V_70 -> V_15 < 4 ) {
F_9 ( V_2 , L_33 ) ;
goto V_180;
}
V_72 = (struct V_71 * ) V_70 -> V_5 ;
if ( V_72 -> V_79 )
V_171 = F_23 ( V_2 , V_70 , & V_37 ) ;
else
V_171 = F_28 ( V_2 , V_70 , & V_37 ,
& V_13 -> V_177 ) ;
if ( V_171 )
goto V_180;
V_73 = F_24 ( V_2 -> V_13 . V_78 ) ;
if ( V_2 -> V_24 != V_25 ) {
if ( V_73 < V_175 || V_73 > V_172 ) {
F_9 ( V_2 ,
L_34
L_35 ,
V_172 , V_73 ) ;
goto V_180;
}
if ( V_73 < V_173 ) {
if ( V_173 != V_172 )
F_9 ( V_2 , L_36
L_37 ,
V_173 , V_172 , V_73 ) ;
else
F_9 ( V_2 , L_36
L_38 ,
V_172 , V_73 ) ;
F_9 ( V_2 , L_39
L_40 ) ;
}
}
if ( ! V_13 -> V_140 && F_34 ( V_2 , & V_37 , V_2 -> V_21 ) )
goto V_180;
for ( V_9 = 0 ; V_9 < V_12 ; V_9 ++ )
if ( F_33 ( V_2 , & V_37 , V_9 ) )
goto V_181;
V_13 -> V_121 = V_37 . V_121 ;
if ( V_37 . V_123 )
V_13 -> V_123 = ( V_37 . V_123 - 16 ) / 12 ;
else
V_13 -> V_123 =
V_2 -> V_21 -> V_182 -> V_183 ;
V_13 -> V_125 = V_37 . V_125 ;
V_13 -> V_127 = V_37 . V_127 ;
if ( V_37 . V_129 )
V_13 -> V_129 = ( V_37 . V_129 - 16 ) / 12 ;
else
V_13 -> V_129 =
V_2 -> V_21 -> V_182 -> V_183 ;
V_13 -> V_131 = V_37 . V_131 ;
if ( V_13 -> V_177 . V_138 >
V_184 )
V_13 -> V_177 . V_138 =
V_185 ;
F_41 ( V_70 ) ;
F_42 ( & V_186 ) ;
if ( V_13 -> V_140 )
V_160 = & V_159 [ V_187 ] ;
else
V_160 = & V_159 [ V_188 ] ;
F_43 ( V_2 , L_41 ,
V_2 -> V_13 . V_91 , V_160 -> V_167 ) ;
F_44 ( & V_2 -> V_189 , & V_160 -> V_2 ) ;
if ( V_160 -> V_162 ) {
V_2 -> V_165 = F_35 ( V_2 , V_160 ) ;
if ( ! V_2 -> V_165 ) {
F_45 ( & V_186 ) ;
goto V_190;
}
} else {
V_176 = true ;
}
F_45 ( & V_186 ) ;
F_46 ( & V_2 -> V_191 ) ;
if ( V_176 ) {
V_171 = F_47 ( L_42 , V_160 -> V_167 ) ;
#ifdef F_48
if ( V_171 )
F_9 ( V_2 ,
L_43 ,
V_160 -> V_167 , V_171 ) ;
#endif
}
return;
V_180:
F_41 ( V_70 ) ;
if ( F_7 ( V_2 , false ) )
goto V_190;
return;
V_181:
F_9 ( V_2 , L_44 ) ;
F_4 ( V_2 ) ;
F_41 ( V_70 ) ;
V_190:
F_46 ( & V_2 -> V_191 ) ;
F_49 ( V_2 -> V_32 -> V_33 ) ;
}
struct V_1 * F_50 ( struct V_192 * V_32 ,
const struct V_155 * V_21 )
{
struct V_1 * V_2 ;
int V_193 ;
V_2 = F_51 ( sizeof( * V_2 ) , V_34 ) ;
if ( ! V_2 ) {
V_193 = - V_17 ;
goto V_171;
}
V_2 -> V_32 = V_32 ;
V_2 -> V_33 = V_32 -> V_33 ;
V_2 -> V_21 = V_21 ;
F_52 ( & V_2 -> V_191 ) ;
F_53 ( & V_2 -> V_189 ) ;
#ifdef F_36
V_2 -> V_168 = F_37 ( F_54 ( V_32 -> V_33 ) ,
V_194 ) ;
if ( ! V_2 -> V_168 ) {
F_9 ( V_2 , L_45 ) ;
V_193 = - V_17 ;
goto V_195;
}
V_2 -> V_32 -> V_164 = F_37 ( L_46 , V_2 -> V_168 ) ;
if ( ! V_2 -> V_32 -> V_164 ) {
F_9 ( V_2 , L_47 ) ;
V_193 = - V_17 ;
goto V_196;
}
#endif
V_193 = F_7 ( V_2 , true ) ;
if ( V_193 ) {
F_9 ( V_32 , L_48 ) ;
goto V_197;
}
return V_2 ;
V_197:
#ifdef F_36
V_196:
F_38 ( V_2 -> V_168 ) ;
V_195:
#endif
F_55 ( V_2 ) ;
V_171:
return F_56 ( V_193 ) ;
}
void F_57 ( struct V_1 * V_2 )
{
F_58 ( & V_2 -> V_191 ) ;
F_39 ( V_2 ) ;
F_4 ( V_2 ) ;
F_42 ( & V_186 ) ;
if ( ! F_59 ( & V_2 -> V_189 ) )
F_60 ( & V_2 -> V_189 ) ;
F_45 ( & V_186 ) ;
#ifdef F_36
F_38 ( V_2 -> V_168 ) ;
#endif
F_55 ( V_2 ) ;
}
int F_61 ( const char * V_167 , const struct V_161 * V_162 )
{
int V_9 ;
struct V_1 * V_2 ;
struct V_159 * V_160 ;
F_42 ( & V_186 ) ;
for ( V_9 = 0 ; V_9 < F_62 ( V_159 ) ; V_9 ++ ) {
V_160 = & V_159 [ V_9 ] ;
if ( strcmp ( V_160 -> V_167 , V_167 ) )
continue;
V_160 -> V_162 = V_162 ;
F_63 (drv, &op->drv, list)
V_2 -> V_165 = F_35 ( V_2 , V_160 ) ;
F_45 ( & V_186 ) ;
return 0 ;
}
F_45 ( & V_186 ) ;
return - V_198 ;
}
void F_64 ( const char * V_167 )
{
int V_9 ;
struct V_1 * V_2 ;
F_42 ( & V_186 ) ;
for ( V_9 = 0 ; V_9 < F_62 ( V_159 ) ; V_9 ++ ) {
if ( strcmp ( V_159 [ V_9 ] . V_167 , V_167 ) )
continue;
V_159 [ V_9 ] . V_162 = NULL ;
F_63 (drv, &iwlwifi_opmode_table[i].drv, list)
F_39 ( V_2 ) ;
F_45 ( & V_186 ) ;
return;
}
F_45 ( & V_186 ) ;
}
static int T_4 F_65 ( void )
{
int V_9 ;
F_66 ( & V_186 ) ;
for ( V_9 = 0 ; V_9 < F_62 ( V_159 ) ; V_9 ++ )
F_53 ( & V_159 [ V_9 ] . V_2 ) ;
F_67 ( V_199 L_49 V_200 L_50 ) ;
F_67 ( V_201 L_50 ) ;
#ifdef F_36
V_194 = F_37 ( V_202 , NULL ) ;
if ( ! V_194 )
return - V_203 ;
#endif
return F_68 () ;
}
static void T_5 F_69 ( void )
{
F_70 () ;
#ifdef F_36
F_38 ( V_194 ) ;
#endif
}
