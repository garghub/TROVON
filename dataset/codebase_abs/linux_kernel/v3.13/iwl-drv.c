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
static int F_17 ( struct V_36 * V_37 ,
const void * V_5 , enum V_38 type ,
int V_15 )
{
struct V_39 * V_8 ;
struct V_14 * V_11 ;
struct V_40 * V_41 ;
if ( F_18 ( ! V_37 || ! V_5 || type >= V_12 ) )
return - 1 ;
V_41 = (struct V_40 * ) V_5 ;
V_8 = & V_37 -> V_8 [ type ] ;
V_11 = & V_8 -> V_11 [ V_8 -> V_42 ] ;
V_11 -> V_18 = F_19 ( V_41 -> V_18 ) ;
V_11 -> V_5 = V_41 -> V_5 ;
V_11 -> V_15 = V_15 - sizeof( V_41 -> V_18 ) ;
++ V_8 -> V_42 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , const T_3 * V_5 )
{
struct V_43 * V_44 =
(struct V_43 * ) V_5 ;
T_2 V_45 = F_19 ( V_44 -> V_45 ) ;
if ( V_45 >= V_12 ) {
F_9 ( V_2 , L_8 ,
V_45 ) ;
return - V_16 ;
}
V_2 -> V_13 . V_46 [ V_45 ] . V_47 =
V_44 -> V_48 . V_47 ;
V_2 -> V_13 . V_46 [ V_45 ] . V_49 =
V_44 -> V_48 . V_49 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
const struct V_50 * V_51 ,
struct V_36 * V_37 )
{
struct V_52 * V_53 = ( void * ) V_51 -> V_5 ;
T_2 V_54 , V_55 , V_56 ;
char V_57 [ 25 ] ;
const T_3 * V_58 ;
V_2 -> V_13 . V_59 = F_19 ( V_53 -> V_60 ) ;
V_54 = F_22 ( V_2 -> V_13 . V_59 ) ;
switch ( V_54 ) {
default:
V_55 = 28 ;
if ( V_51 -> V_15 < V_55 ) {
F_9 ( V_2 , L_9 ) ;
return - V_16 ;
}
V_56 = F_19 ( V_53 -> V_61 . V_62 . V_56 ) ;
F_14 ( V_37 , V_63 , V_64 ,
F_19 ( V_53 -> V_61 . V_62 . V_65 ) ) ;
F_14 ( V_37 , V_63 , V_66 ,
F_19 ( V_53 -> V_61 . V_62 . V_67 ) ) ;
F_14 ( V_37 , V_68 , V_64 ,
F_19 ( V_53 -> V_61 . V_62 . V_69 ) ) ;
F_14 ( V_37 , V_68 , V_66 ,
F_19 ( V_53 -> V_61 . V_62 . V_70 ) ) ;
V_58 = V_53 -> V_61 . V_62 . V_5 ;
break;
case 0 :
case 1 :
case 2 :
V_55 = 24 ;
if ( V_51 -> V_15 < V_55 ) {
F_9 ( V_2 , L_9 ) ;
return - V_16 ;
}
V_56 = 0 ;
F_14 ( V_37 , V_63 , V_64 ,
F_19 ( V_53 -> V_61 . V_71 . V_65 ) ) ;
F_14 ( V_37 , V_63 , V_66 ,
F_19 ( V_53 -> V_61 . V_71 . V_67 ) ) ;
F_14 ( V_37 , V_68 , V_64 ,
F_19 ( V_53 -> V_61 . V_71 . V_69 ) ) ;
F_14 ( V_37 , V_68 , V_66 ,
F_19 ( V_53 -> V_61 . V_71 . V_70 ) ) ;
V_58 = V_53 -> V_61 . V_71 . V_5 ;
break;
}
if ( V_56 )
sprintf ( V_57 , L_10 , V_56 ,
( V_2 -> V_24 == V_25 )
? L_11 : L_7 ) ;
else
V_57 [ 0 ] = '\0' ;
snprintf ( V_2 -> V_13 . V_72 ,
sizeof( V_2 -> V_13 . V_72 ) ,
L_12 ,
F_23 ( V_2 -> V_13 . V_59 ) ,
F_24 ( V_2 -> V_13 . V_59 ) ,
F_22 ( V_2 -> V_13 . V_59 ) ,
F_25 ( V_2 -> V_13 . V_59 ) ,
V_57 ) ;
if ( V_51 -> V_15 != V_55 +
F_15 ( V_37 , V_63 , V_64 ) +
F_15 ( V_37 , V_63 , V_66 ) +
F_15 ( V_37 , V_68 , V_64 ) +
F_15 ( V_37 , V_68 , V_66 ) ) {
F_9 ( V_2 ,
L_13 ,
( int ) V_51 -> V_15 ) ;
return - V_16 ;
}
F_13 ( V_37 , V_63 , V_64 , V_58 ) ;
V_58 += F_15 ( V_37 , V_63 , V_64 ) ;
F_16 ( V_37 , V_63 , V_64 ,
V_73 ) ;
F_13 ( V_37 , V_63 , V_66 , V_58 ) ;
V_58 += F_15 ( V_37 , V_63 , V_66 ) ;
F_16 ( V_37 , V_63 , V_66 ,
V_74 ) ;
F_13 ( V_37 , V_68 , V_64 , V_58 ) ;
V_58 += F_15 ( V_37 , V_68 , V_64 ) ;
F_16 ( V_37 , V_68 , V_64 ,
V_73 ) ;
F_13 ( V_37 , V_68 , V_66 , V_58 ) ;
V_58 += F_15 ( V_37 , V_68 , V_66 ) ;
F_16 ( V_37 , V_68 , V_66 ,
V_74 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
const struct V_50 * V_51 ,
struct V_36 * V_37 ,
struct V_75 * V_76 )
{
struct V_77 * V_53 = ( void * ) V_51 -> V_5 ;
struct V_78 * V_79 ;
T_1 V_6 = V_51 -> V_15 ;
const T_3 * V_5 ;
T_2 V_80 ;
enum V_81 V_82 ;
const T_3 * V_83 ;
char V_57 [ 25 ] ;
T_2 V_56 ;
int V_84 ;
if ( V_6 < sizeof( * V_53 ) ) {
F_9 ( V_2 , L_14 , V_6 ) ;
return - V_16 ;
}
if ( V_53 -> V_85 != F_27 ( V_86 ) ) {
F_9 ( V_2 , L_15 ,
F_19 ( V_53 -> V_85 ) ) ;
return - V_16 ;
}
V_2 -> V_13 . V_59 = F_19 ( V_53 -> V_60 ) ;
V_56 = F_19 ( V_53 -> V_56 ) ;
if ( V_56 )
sprintf ( V_57 , L_10 , V_56 ,
( V_2 -> V_24 == V_25 )
? L_11 : L_7 ) ;
else
V_57 [ 0 ] = '\0' ;
snprintf ( V_2 -> V_13 . V_72 ,
sizeof( V_2 -> V_13 . V_72 ) ,
L_12 ,
F_23 ( V_2 -> V_13 . V_59 ) ,
F_24 ( V_2 -> V_13 . V_59 ) ,
F_22 ( V_2 -> V_13 . V_59 ) ,
F_25 ( V_2 -> V_13 . V_59 ) ,
V_57 ) ;
V_5 = V_53 -> V_5 ;
V_6 -= sizeof( * V_53 ) ;
while ( V_6 >= sizeof( * V_79 ) ) {
V_6 -= sizeof( * V_79 ) ;
V_79 = ( void * ) V_5 ;
V_80 = F_19 ( V_79 -> V_87 ) ;
V_82 = F_19 ( V_79 -> type ) ;
V_83 = V_79 -> V_5 ;
if ( V_6 < V_80 ) {
F_9 ( V_2 , L_16 ,
V_6 , V_80 ) ;
return - V_16 ;
}
V_6 -= F_28 ( V_80 , 4 ) ;
V_5 += sizeof( * V_79 ) + F_28 ( V_80 , 4 ) ;
switch ( V_82 ) {
case V_88 :
F_13 ( V_37 , V_63 ,
V_64 , V_83 ) ;
F_14 ( V_37 , V_63 ,
V_64 , V_80 ) ;
F_16 ( V_37 , V_63 ,
V_64 ,
V_73 ) ;
break;
case V_89 :
F_13 ( V_37 , V_63 ,
V_66 , V_83 ) ;
F_14 ( V_37 , V_63 ,
V_66 , V_80 ) ;
F_16 ( V_37 , V_63 ,
V_66 ,
V_74 ) ;
break;
case V_90 :
F_13 ( V_37 , V_68 ,
V_64 , V_83 ) ;
F_14 ( V_37 , V_68 ,
V_64 , V_80 ) ;
F_16 ( V_37 , V_68 ,
V_64 ,
V_73 ) ;
break;
case V_91 :
F_13 ( V_37 , V_68 ,
V_66 , V_83 ) ;
F_14 ( V_37 , V_68 ,
V_66 , V_80 ) ;
F_16 ( V_37 , V_68 ,
V_66 ,
V_74 ) ;
break;
case V_92 :
F_9 ( V_2 , L_17 ) ;
break;
case V_93 :
if ( V_80 != sizeof( T_2 ) )
goto V_94;
V_76 -> V_95 =
F_29 ( ( V_96 * ) V_83 ) ;
break;
case V_97 :
if ( V_80 )
goto V_94;
V_76 -> V_98 |= V_99 ;
break;
case V_100 :
if ( V_80 < sizeof( T_2 ) )
goto V_94;
if ( V_80 % sizeof( T_2 ) )
goto V_94;
V_76 -> V_98 = F_29 ( ( V_96 * ) V_83 ) ;
break;
case V_101 :
if ( V_80 != sizeof( T_2 ) )
goto V_94;
V_37 -> V_102 =
F_29 ( ( V_96 * ) V_83 ) ;
break;
case V_103 :
if ( V_80 != sizeof( T_2 ) )
goto V_94;
V_37 -> V_104 =
F_29 ( ( V_96 * ) V_83 ) ;
break;
case V_105 :
if ( V_80 != sizeof( T_2 ) )
goto V_94;
V_37 -> V_106 =
F_29 ( ( V_96 * ) V_83 ) ;
break;
case V_107 :
if ( V_80 != sizeof( T_2 ) )
goto V_94;
V_37 -> V_108 =
F_29 ( ( V_96 * ) V_83 ) ;
break;
case V_109 :
if ( V_80 != sizeof( T_2 ) )
goto V_94;
V_37 -> V_110 =
F_29 ( ( V_96 * ) V_83 ) ;
break;
case V_111 :
if ( V_80 != sizeof( T_2 ) )
goto V_94;
V_37 -> V_112 =
F_29 ( ( V_96 * ) V_83 ) ;
break;
case V_113 :
if ( V_80 )
goto V_94;
V_2 -> V_13 . V_114 = true ;
break;
case V_115 :
F_13 ( V_37 , V_116 ,
V_64 , V_83 ) ;
F_14 ( V_37 , V_116 ,
V_64 , V_80 ) ;
F_16 ( V_37 , V_116 ,
V_64 ,
V_73 ) ;
break;
case V_117 :
F_13 ( V_37 , V_116 ,
V_66 , V_83 ) ;
F_14 ( V_37 , V_116 ,
V_66 , V_80 ) ;
F_16 ( V_37 , V_116 ,
V_66 ,
V_74 ) ;
break;
case V_118 :
if ( V_80 != sizeof( T_2 ) )
goto V_94;
V_76 -> V_119 =
F_29 ( ( V_96 * ) V_83 ) ;
break;
case V_120 :
F_17 ( V_37 , V_83 , V_63 ,
V_80 ) ;
V_2 -> V_13 . V_121 = true ;
break;
case V_122 :
F_17 ( V_37 , V_83 , V_68 ,
V_80 ) ;
V_2 -> V_13 . V_121 = true ;
break;
case V_123 :
F_17 ( V_37 , V_83 , V_116 ,
V_80 ) ;
V_2 -> V_13 . V_121 = true ;
break;
case V_124 :
if ( V_80 != sizeof( struct V_43 ) )
goto V_94;
if ( F_20 ( V_2 , V_83 ) )
goto V_125;
break;
case V_126 :
if ( V_80 != sizeof( T_2 ) )
goto V_94;
V_2 -> V_13 . V_127 = F_29 ( ( V_96 * ) V_83 ) ;
break;
case V_128 :
F_17 ( V_37 , V_83 , V_63 ,
V_80 ) ;
V_2 -> V_13 . V_121 = true ;
V_2 -> V_13 . V_8 [ V_63 ] . V_129 = true ;
break;
case V_130 :
F_17 ( V_37 , V_83 , V_68 ,
V_80 ) ;
V_2 -> V_13 . V_121 = true ;
V_2 -> V_13 . V_8 [ V_68 ] . V_129 = true ;
break;
case V_131 :
F_17 ( V_37 , V_83 , V_116 ,
V_80 ) ;
V_2 -> V_13 . V_121 = true ;
V_2 -> V_13 . V_8 [ V_116 ] . V_129 = true ;
break;
case V_132 :
if ( V_80 != sizeof( T_2 ) )
goto V_94;
V_84 =
F_29 ( ( V_96 * ) V_83 ) ;
if ( V_84 == 2 ) {
V_2 -> V_13 . V_8 [ V_63 ] . V_133 =
true ;
V_2 -> V_13 . V_8 [ V_68 ] . V_133 =
true ;
V_2 -> V_13 . V_8 [ V_116 ] . V_133 =
true ;
} else if ( ( V_84 > 2 ) || ( V_84 < 1 ) ) {
F_9 ( V_2 , L_18 ) ;
return - V_16 ;
}
break;
default:
F_10 ( V_2 , L_19 , V_82 ) ;
break;
}
}
if ( V_6 ) {
F_9 ( V_2 , L_20 , V_6 ) ;
F_30 ( V_2 , V_134 , ( T_3 * ) V_5 , V_6 ) ;
return - V_16 ;
}
return 0 ;
V_94:
F_9 ( V_2 , L_21 , V_82 , V_80 ) ;
V_125:
F_30 ( V_2 , V_134 , V_83 , V_80 ) ;
return - V_16 ;
}
static int F_31 ( struct V_1 * V_2 ,
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
static int F_32 ( struct V_1 * V_2 ,
struct V_36 * V_37 ,
const struct V_135 * V_21 )
{
F_10 ( V_2 , L_22 ,
F_15 ( V_37 , V_63 ,
V_64 ) ) ;
F_10 ( V_2 , L_23 ,
F_15 ( V_37 , V_63 ,
V_66 ) ) ;
F_10 ( V_2 , L_24 ,
F_15 ( V_37 , V_68 , V_64 ) ) ;
F_10 ( V_2 , L_25 ,
F_15 ( V_37 , V_68 , V_66 ) ) ;
if ( F_15 ( V_37 , V_63 , V_64 ) >
V_21 -> V_136 ) {
F_9 ( V_2 , L_26 ,
F_15 ( V_37 , V_63 ,
V_64 ) ) ;
return - 1 ;
}
if ( F_15 ( V_37 , V_63 , V_66 ) >
V_21 -> V_137 ) {
F_9 ( V_2 , L_27 ,
F_15 ( V_37 , V_63 ,
V_66 ) ) ;
return - 1 ;
}
if ( F_15 ( V_37 , V_68 , V_64 ) >
V_21 -> V_136 ) {
F_9 ( V_2 , L_28 ,
F_15 ( V_37 , V_68 ,
V_64 ) ) ;
return - 1 ;
}
if ( F_15 ( V_37 , V_68 , V_66 ) >
V_21 -> V_137 ) {
F_9 ( V_2 , L_29 ,
F_15 ( V_37 , V_63 ,
V_66 ) ) ;
return - 1 ;
}
return 0 ;
}
static struct V_138 *
F_33 ( struct V_1 * V_2 , struct V_139 * V_140 )
{
const struct V_141 * V_142 = V_140 -> V_142 ;
struct V_143 * V_144 = NULL ;
struct V_138 * V_145 = NULL ;
#ifdef F_34
V_2 -> V_146 = F_35 ( V_140 -> V_147 ,
V_2 -> V_148 ) ;
if ( ! V_2 -> V_146 ) {
F_9 ( V_2 ,
L_30 ) ;
return V_145 ;
}
V_144 = V_2 -> V_146 ;
#endif
V_145 = V_142 -> V_149 ( V_2 -> V_32 , V_2 -> V_21 , & V_2 -> V_13 , V_144 ) ;
#ifdef F_34
if ( ! V_145 ) {
F_36 ( V_2 -> V_146 ) ;
V_2 -> V_146 = NULL ;
}
#endif
return V_145 ;
}
static void F_37 ( struct V_1 * V_2 )
{
if ( V_2 -> V_145 ) {
F_38 ( V_2 -> V_145 ) ;
V_2 -> V_145 = NULL ;
#ifdef F_34
F_36 ( V_2 -> V_146 ) ;
V_2 -> V_146 = NULL ;
#endif
}
}
static void V_35 ( const struct V_50 * V_51 , void * V_150 )
{
struct V_1 * V_2 = V_150 ;
struct V_151 * V_13 = & V_2 -> V_13 ;
struct V_52 * V_53 ;
struct V_139 * V_140 ;
int V_152 ;
struct V_36 V_37 ;
const unsigned int V_153 = V_2 -> V_21 -> V_27 ;
unsigned int V_154 = V_2 -> V_21 -> V_155 ;
const unsigned int V_156 = V_2 -> V_21 -> V_28 ;
T_2 V_54 ;
int V_9 ;
bool V_157 = false ;
V_13 -> V_158 . V_95 = V_159 ;
V_13 -> V_158 . V_119 =
V_160 ;
if ( ! V_154 )
V_154 = V_153 ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
if ( ! V_51 ) {
if ( V_2 -> V_24 <= V_154 )
F_9 ( V_2 ,
L_31 ,
V_2 -> V_30 ) ;
goto V_161;
}
F_10 ( V_2 , L_32 ,
V_2 -> V_30 , V_51 -> V_15 ) ;
if ( V_51 -> V_15 < 4 ) {
F_9 ( V_2 , L_33 ) ;
goto V_161;
}
V_53 = (struct V_52 * ) V_51 -> V_5 ;
if ( V_53 -> V_60 )
V_152 = F_21 ( V_2 , V_51 , & V_37 ) ;
else
V_152 = F_26 ( V_2 , V_51 , & V_37 ,
& V_13 -> V_158 ) ;
if ( V_152 )
goto V_161;
V_54 = F_22 ( V_2 -> V_13 . V_59 ) ;
if ( V_2 -> V_24 != V_25 ) {
if ( V_54 < V_156 || V_54 > V_153 ) {
F_9 ( V_2 ,
L_34
L_35 ,
V_153 , V_54 ) ;
goto V_161;
}
if ( V_54 < V_154 ) {
if ( V_154 != V_153 )
F_9 ( V_2 , L_36
L_37 ,
V_154 , V_153 , V_54 ) ;
else
F_9 ( V_2 , L_36
L_38 ,
V_153 , V_54 ) ;
F_9 ( V_2 , L_39
L_40 ) ;
}
}
if ( ! V_13 -> V_121 && F_32 ( V_2 , & V_37 , V_2 -> V_21 ) )
goto V_161;
for ( V_9 = 0 ; V_9 < V_12 ; V_9 ++ )
if ( F_31 ( V_2 , & V_37 , V_9 ) )
goto V_162;
V_13 -> V_102 = V_37 . V_102 ;
if ( V_37 . V_104 )
V_13 -> V_104 = ( V_37 . V_104 - 16 ) / 12 ;
else
V_13 -> V_104 =
V_2 -> V_21 -> V_163 -> V_164 ;
V_13 -> V_106 = V_37 . V_106 ;
V_13 -> V_108 = V_37 . V_108 ;
if ( V_37 . V_110 )
V_13 -> V_110 = ( V_37 . V_110 - 16 ) / 12 ;
else
V_13 -> V_110 =
V_2 -> V_21 -> V_163 -> V_164 ;
V_13 -> V_112 = V_37 . V_112 ;
if ( V_13 -> V_158 . V_119 >
V_165 )
V_13 -> V_158 . V_119 =
V_166 ;
F_39 ( V_51 ) ;
F_40 ( & V_167 ) ;
if ( V_13 -> V_121 )
V_140 = & V_139 [ V_168 ] ;
else
V_140 = & V_139 [ V_169 ] ;
F_41 ( V_2 , L_41 ,
V_2 -> V_13 . V_72 , V_140 -> V_147 ) ;
F_42 ( & V_2 -> V_170 , & V_140 -> V_2 ) ;
if ( V_140 -> V_142 ) {
V_2 -> V_145 = F_33 ( V_2 , V_140 ) ;
if ( ! V_2 -> V_145 ) {
F_43 ( & V_167 ) ;
goto V_171;
}
} else {
V_157 = true ;
}
F_43 ( & V_167 ) ;
F_44 ( & V_2 -> V_172 ) ;
if ( V_157 ) {
V_152 = F_45 ( L_42 , V_140 -> V_147 ) ;
#ifdef F_46
if ( V_152 )
F_9 ( V_2 ,
L_43 ,
V_140 -> V_147 , V_152 ) ;
#endif
}
return;
V_161:
F_39 ( V_51 ) ;
if ( F_7 ( V_2 , false ) )
goto V_171;
return;
V_162:
F_9 ( V_2 , L_44 ) ;
F_4 ( V_2 ) ;
F_39 ( V_51 ) ;
V_171:
F_44 ( & V_2 -> V_172 ) ;
F_47 ( V_2 -> V_32 -> V_33 ) ;
}
struct V_1 * F_48 ( struct V_173 * V_32 ,
const struct V_135 * V_21 )
{
struct V_1 * V_2 ;
int V_174 ;
V_2 = F_49 ( sizeof( * V_2 ) , V_34 ) ;
if ( ! V_2 ) {
V_174 = - V_17 ;
goto V_152;
}
V_2 -> V_32 = V_32 ;
V_2 -> V_33 = V_32 -> V_33 ;
V_2 -> V_21 = V_21 ;
F_50 ( & V_2 -> V_172 ) ;
F_51 ( & V_2 -> V_170 ) ;
#ifdef F_34
V_2 -> V_148 = F_35 ( F_52 ( V_32 -> V_33 ) ,
V_175 ) ;
if ( ! V_2 -> V_148 ) {
F_9 ( V_2 , L_45 ) ;
V_174 = - V_17 ;
goto V_176;
}
V_2 -> V_32 -> V_144 = F_35 ( L_46 , V_2 -> V_148 ) ;
if ( ! V_2 -> V_32 -> V_144 ) {
F_9 ( V_2 , L_47 ) ;
V_174 = - V_17 ;
goto V_177;
}
#endif
V_174 = F_7 ( V_2 , true ) ;
if ( V_174 ) {
F_9 ( V_32 , L_48 ) ;
goto V_178;
}
return V_2 ;
V_178:
#ifdef F_34
V_177:
F_36 ( V_2 -> V_148 ) ;
V_176:
#endif
F_53 ( V_2 ) ;
V_152:
return F_54 ( V_174 ) ;
}
void F_55 ( struct V_1 * V_2 )
{
F_56 ( & V_2 -> V_172 ) ;
F_37 ( V_2 ) ;
F_4 ( V_2 ) ;
F_40 ( & V_167 ) ;
if ( ! F_57 ( & V_2 -> V_170 ) )
F_58 ( & V_2 -> V_170 ) ;
F_43 ( & V_167 ) ;
#ifdef F_34
F_36 ( V_2 -> V_148 ) ;
#endif
F_53 ( V_2 ) ;
}
int F_59 ( const char * V_147 , const struct V_141 * V_142 )
{
int V_9 ;
struct V_1 * V_2 ;
struct V_139 * V_140 ;
F_40 ( & V_167 ) ;
for ( V_9 = 0 ; V_9 < F_60 ( V_139 ) ; V_9 ++ ) {
V_140 = & V_139 [ V_9 ] ;
if ( strcmp ( V_140 -> V_147 , V_147 ) )
continue;
V_140 -> V_142 = V_142 ;
F_61 (drv, &op->drv, list)
V_2 -> V_145 = F_33 ( V_2 , V_140 ) ;
F_43 ( & V_167 ) ;
return 0 ;
}
F_43 ( & V_167 ) ;
return - V_179 ;
}
void F_62 ( const char * V_147 )
{
int V_9 ;
struct V_1 * V_2 ;
F_40 ( & V_167 ) ;
for ( V_9 = 0 ; V_9 < F_60 ( V_139 ) ; V_9 ++ ) {
if ( strcmp ( V_139 [ V_9 ] . V_147 , V_147 ) )
continue;
V_139 [ V_9 ] . V_142 = NULL ;
F_61 (drv, &iwlwifi_opmode_table[i].drv, list)
F_37 ( V_2 ) ;
F_43 ( & V_167 ) ;
return;
}
F_43 ( & V_167 ) ;
}
static int T_4 F_63 ( void )
{
int V_9 ;
F_64 ( & V_167 ) ;
for ( V_9 = 0 ; V_9 < F_60 ( V_139 ) ; V_9 ++ )
F_51 ( & V_139 [ V_9 ] . V_2 ) ;
F_65 ( V_180 L_49 V_181 L_50 ) ;
F_65 ( V_182 L_50 ) ;
#ifdef F_34
V_175 = F_35 ( V_183 , NULL ) ;
if ( ! V_175 )
return - V_184 ;
#endif
return F_66 () ;
}
static void T_5 F_67 ( void )
{
F_68 () ;
#ifdef F_34
F_36 ( V_175 ) ;
#endif
}
