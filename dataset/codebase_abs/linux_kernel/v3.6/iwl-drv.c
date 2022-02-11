static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_5 )
F_2 ( V_2 -> V_6 -> V_7 , V_4 -> V_8 ,
V_4 -> V_5 , V_4 -> V_9 ) ;
V_4 -> V_5 = NULL ;
V_4 -> V_8 = 0 ;
}
static void F_3 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ )
F_1 ( V_2 , & V_11 -> V_14 [ V_12 ] ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_15 ; V_12 ++ )
F_3 ( V_2 , V_2 -> V_16 . V_11 + V_12 ) ;
}
static int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_17 * V_14 )
{
if ( ! V_14 || ! V_14 -> V_18 ) {
V_4 -> V_5 = NULL ;
return - V_19 ;
}
V_4 -> V_5 = F_6 ( V_2 -> V_6 -> V_7 , V_14 -> V_18 ,
& V_4 -> V_9 , V_20 ) ;
if ( ! V_4 -> V_5 )
return - V_21 ;
V_4 -> V_8 = V_14 -> V_18 ;
V_4 -> V_22 = V_14 -> V_22 ;
memcpy ( V_4 -> V_5 , V_14 -> V_23 , V_14 -> V_18 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , bool V_24 )
{
const char * V_25 = V_2 -> V_26 -> V_27 ;
char V_28 [ 8 ] ;
if ( V_24 ) {
#ifdef F_8
V_2 -> V_29 = V_30 ;
strcpy ( V_28 , V_31 ) ;
} else if ( V_2 -> V_29 == V_30 ) {
#endif
V_2 -> V_29 = V_2 -> V_26 -> V_32 ;
sprintf ( V_28 , L_1 , V_2 -> V_29 ) ;
} else {
V_2 -> V_29 -- ;
sprintf ( V_28 , L_1 , V_2 -> V_29 ) ;
}
if ( V_2 -> V_29 < V_2 -> V_26 -> V_33 ) {
F_9 ( V_2 , L_2 ) ;
return - V_34 ;
}
sprintf ( V_2 -> V_35 , L_3 , V_25 , V_28 , L_4 ) ;
F_10 ( V_2 , L_5 ,
( V_2 -> V_29 == V_30 )
? L_6 : L_7 ,
V_2 -> V_35 ) ;
return F_11 ( V_36 , 1 , V_2 -> V_35 ,
V_2 -> V_6 -> V_7 ,
V_20 , V_2 , V_37 ) ;
}
static struct V_17 * F_12 ( struct V_38 * V_39 ,
enum V_40 type ,
int V_14 )
{
return & V_39 -> V_11 [ type ] . V_14 [ V_14 ] ;
}
static void F_13 ( struct V_38 * V_39 ,
enum V_40 type ,
int V_14 ,
const void * V_23 )
{
V_39 -> V_11 [ type ] . V_14 [ V_14 ] . V_23 = V_23 ;
}
static void F_14 ( struct V_38 * V_39 ,
enum V_40 type ,
int V_14 ,
T_1 V_18 )
{
V_39 -> V_11 [ type ] . V_14 [ V_14 ] . V_18 = V_18 ;
}
static T_1 F_15 ( struct V_38 * V_39 ,
enum V_40 type ,
int V_14 )
{
return V_39 -> V_11 [ type ] . V_14 [ V_14 ] . V_18 ;
}
static void F_16 ( struct V_38 * V_39 ,
enum V_40 type ,
int V_14 ,
T_2 V_22 )
{
V_39 -> V_11 [ type ] . V_14 [ V_14 ] . V_22 = V_22 ;
}
static int F_17 ( struct V_38 * V_39 ,
const void * V_23 , enum V_40 type ,
int V_18 )
{
struct V_41 * V_11 ;
struct V_17 * V_14 ;
struct V_42 * V_43 ;
if ( F_18 ( ! V_39 || ! V_23 || type >= V_15 ) )
return - 1 ;
V_43 = (struct V_42 * ) V_23 ;
V_11 = & V_39 -> V_11 [ type ] ;
V_14 = & V_11 -> V_14 [ V_11 -> V_44 ] ;
V_14 -> V_22 = F_19 ( V_43 -> V_22 ) ;
V_14 -> V_23 = V_43 -> V_23 ;
V_14 -> V_18 = V_18 - sizeof( V_43 -> V_22 ) ;
++ V_11 -> V_44 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , const T_3 * V_23 )
{
struct V_45 * V_46 =
(struct V_45 * ) V_23 ;
T_2 V_47 = F_19 ( V_46 -> V_47 ) ;
if ( V_47 >= V_15 ) {
F_9 ( V_2 , L_8 ,
V_47 ) ;
return - V_19 ;
}
V_2 -> V_16 . V_48 [ V_47 ] = F_21 ( V_46 -> V_49 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
const struct V_50 * V_51 ,
struct V_38 * V_39 )
{
struct V_52 * V_53 = ( void * ) V_51 -> V_23 ;
T_2 V_54 , V_55 , V_56 ;
char V_57 [ 25 ] ;
const T_3 * V_58 ;
V_2 -> V_16 . V_59 = F_19 ( V_53 -> V_60 ) ;
V_54 = F_23 ( V_2 -> V_16 . V_59 ) ;
switch ( V_54 ) {
default:
V_55 = 28 ;
if ( V_51 -> V_18 < V_55 ) {
F_9 ( V_2 , L_9 ) ;
return - V_19 ;
}
V_56 = F_19 ( V_53 -> V_61 . V_62 . V_56 ) ;
F_14 ( V_39 , V_63 , V_64 ,
F_19 ( V_53 -> V_61 . V_62 . V_65 ) ) ;
F_14 ( V_39 , V_63 , V_66 ,
F_19 ( V_53 -> V_61 . V_62 . V_67 ) ) ;
F_14 ( V_39 , V_68 , V_64 ,
F_19 ( V_53 -> V_61 . V_62 . V_69 ) ) ;
F_14 ( V_39 , V_68 , V_66 ,
F_19 ( V_53 -> V_61 . V_62 . V_70 ) ) ;
V_58 = V_53 -> V_61 . V_62 . V_23 ;
break;
case 0 :
case 1 :
case 2 :
V_55 = 24 ;
if ( V_51 -> V_18 < V_55 ) {
F_9 ( V_2 , L_9 ) ;
return - V_19 ;
}
V_56 = 0 ;
F_14 ( V_39 , V_63 , V_64 ,
F_19 ( V_53 -> V_61 . V_71 . V_65 ) ) ;
F_14 ( V_39 , V_63 , V_66 ,
F_19 ( V_53 -> V_61 . V_71 . V_67 ) ) ;
F_14 ( V_39 , V_68 , V_64 ,
F_19 ( V_53 -> V_61 . V_71 . V_69 ) ) ;
F_14 ( V_39 , V_68 , V_66 ,
F_19 ( V_53 -> V_61 . V_71 . V_70 ) ) ;
V_58 = V_53 -> V_61 . V_71 . V_23 ;
break;
}
if ( V_56 )
sprintf ( V_57 , L_10 , V_56 ,
( V_2 -> V_29 == V_30 )
? L_11 : L_7 ) ;
else
V_57 [ 0 ] = '\0' ;
snprintf ( V_2 -> V_16 . V_72 ,
sizeof( V_2 -> V_16 . V_72 ) ,
L_12 ,
F_24 ( V_2 -> V_16 . V_59 ) ,
F_25 ( V_2 -> V_16 . V_59 ) ,
F_23 ( V_2 -> V_16 . V_59 ) ,
F_26 ( V_2 -> V_16 . V_59 ) ,
V_57 ) ;
if ( V_51 -> V_18 != V_55 +
F_15 ( V_39 , V_63 , V_64 ) +
F_15 ( V_39 , V_63 , V_66 ) +
F_15 ( V_39 , V_68 , V_64 ) +
F_15 ( V_39 , V_68 , V_66 ) ) {
F_9 ( V_2 ,
L_13 ,
( int ) V_51 -> V_18 ) ;
return - V_19 ;
}
F_13 ( V_39 , V_63 , V_64 , V_58 ) ;
V_58 += F_15 ( V_39 , V_63 , V_64 ) ;
F_16 ( V_39 , V_63 , V_64 ,
V_73 ) ;
F_13 ( V_39 , V_63 , V_66 , V_58 ) ;
V_58 += F_15 ( V_39 , V_63 , V_66 ) ;
F_16 ( V_39 , V_63 , V_66 ,
V_74 ) ;
F_13 ( V_39 , V_68 , V_64 , V_58 ) ;
V_58 += F_15 ( V_39 , V_68 , V_64 ) ;
F_16 ( V_39 , V_68 , V_64 ,
V_73 ) ;
F_13 ( V_39 , V_68 , V_66 , V_58 ) ;
V_58 += F_15 ( V_39 , V_68 , V_66 ) ;
F_16 ( V_39 , V_68 , V_66 ,
V_74 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
const struct V_50 * V_51 ,
struct V_38 * V_39 ,
struct V_75 * V_76 )
{
struct V_77 * V_53 = ( void * ) V_51 -> V_23 ;
struct V_78 * V_79 ;
T_1 V_8 = V_51 -> V_18 ;
const T_3 * V_23 ;
T_2 V_80 ;
enum V_81 V_82 ;
const T_3 * V_83 ;
char V_57 [ 25 ] ;
T_2 V_56 ;
if ( V_8 < sizeof( * V_53 ) ) {
F_9 ( V_2 , L_14 , V_8 ) ;
return - V_19 ;
}
if ( V_53 -> V_84 != F_28 ( V_85 ) ) {
F_9 ( V_2 , L_15 ,
F_19 ( V_53 -> V_84 ) ) ;
return - V_19 ;
}
V_2 -> V_16 . V_59 = F_19 ( V_53 -> V_60 ) ;
V_56 = F_19 ( V_53 -> V_56 ) ;
if ( V_56 )
sprintf ( V_57 , L_10 , V_56 ,
( V_2 -> V_29 == V_30 )
? L_11 : L_7 ) ;
else
V_57 [ 0 ] = '\0' ;
snprintf ( V_2 -> V_16 . V_72 ,
sizeof( V_2 -> V_16 . V_72 ) ,
L_12 ,
F_24 ( V_2 -> V_16 . V_59 ) ,
F_25 ( V_2 -> V_16 . V_59 ) ,
F_23 ( V_2 -> V_16 . V_59 ) ,
F_26 ( V_2 -> V_16 . V_59 ) ,
V_57 ) ;
V_23 = V_53 -> V_23 ;
V_8 -= sizeof( * V_53 ) ;
while ( V_8 >= sizeof( * V_79 ) ) {
V_8 -= sizeof( * V_79 ) ;
V_79 = ( void * ) V_23 ;
V_80 = F_19 ( V_79 -> V_86 ) ;
V_82 = F_19 ( V_79 -> type ) ;
V_83 = V_79 -> V_23 ;
if ( V_8 < V_80 ) {
F_9 ( V_2 , L_16 ,
V_8 , V_80 ) ;
return - V_19 ;
}
V_8 -= F_29 ( V_80 , 4 ) ;
V_23 += sizeof( * V_79 ) + F_29 ( V_80 , 4 ) ;
switch ( V_82 ) {
case V_87 :
F_13 ( V_39 , V_63 ,
V_64 , V_83 ) ;
F_14 ( V_39 , V_63 ,
V_64 , V_80 ) ;
F_16 ( V_39 , V_63 ,
V_64 ,
V_73 ) ;
break;
case V_88 :
F_13 ( V_39 , V_63 ,
V_66 , V_83 ) ;
F_14 ( V_39 , V_63 ,
V_66 , V_80 ) ;
F_16 ( V_39 , V_63 ,
V_66 ,
V_74 ) ;
break;
case V_89 :
F_13 ( V_39 , V_68 ,
V_64 , V_83 ) ;
F_14 ( V_39 , V_68 ,
V_64 , V_80 ) ;
F_16 ( V_39 , V_68 ,
V_64 ,
V_73 ) ;
break;
case V_90 :
F_13 ( V_39 , V_68 ,
V_66 , V_83 ) ;
F_14 ( V_39 , V_68 ,
V_66 , V_80 ) ;
F_16 ( V_39 , V_68 ,
V_66 ,
V_74 ) ;
break;
case V_91 :
F_9 ( V_2 , L_17 ) ;
break;
case V_92 :
if ( V_80 != sizeof( T_2 ) )
goto V_93;
V_76 -> V_94 =
F_30 ( ( V_95 * ) V_83 ) ;
break;
case V_96 :
if ( V_80 )
goto V_93;
V_76 -> V_97 |= V_98 ;
break;
case V_99 :
if ( V_80 < sizeof( T_2 ) )
goto V_93;
if ( V_80 % sizeof( T_2 ) )
goto V_93;
V_76 -> V_97 = F_30 ( ( V_95 * ) V_83 ) ;
break;
case V_100 :
if ( V_80 != sizeof( T_2 ) )
goto V_93;
V_39 -> V_101 =
F_30 ( ( V_95 * ) V_83 ) ;
break;
case V_102 :
if ( V_80 != sizeof( T_2 ) )
goto V_93;
V_39 -> V_103 =
F_30 ( ( V_95 * ) V_83 ) ;
break;
case V_104 :
if ( V_80 != sizeof( T_2 ) )
goto V_93;
V_39 -> V_105 =
F_30 ( ( V_95 * ) V_83 ) ;
break;
case V_106 :
if ( V_80 != sizeof( T_2 ) )
goto V_93;
V_39 -> V_107 =
F_30 ( ( V_95 * ) V_83 ) ;
break;
case V_108 :
if ( V_80 != sizeof( T_2 ) )
goto V_93;
V_39 -> V_109 =
F_30 ( ( V_95 * ) V_83 ) ;
break;
case V_110 :
if ( V_80 != sizeof( T_2 ) )
goto V_93;
V_39 -> V_111 =
F_30 ( ( V_95 * ) V_83 ) ;
break;
case V_112 :
if ( V_80 )
goto V_93;
V_2 -> V_16 . V_113 = true ;
break;
case V_114 :
F_13 ( V_39 , V_115 ,
V_64 , V_83 ) ;
F_14 ( V_39 , V_115 ,
V_64 , V_80 ) ;
F_16 ( V_39 , V_115 ,
V_64 ,
V_73 ) ;
break;
case V_116 :
F_13 ( V_39 , V_115 ,
V_66 , V_83 ) ;
F_14 ( V_39 , V_115 ,
V_66 , V_80 ) ;
F_16 ( V_39 , V_115 ,
V_66 ,
V_74 ) ;
break;
case V_117 :
if ( V_80 != sizeof( T_2 ) )
goto V_93;
V_76 -> V_118 =
F_30 ( ( V_95 * ) V_83 ) ;
break;
case V_119 :
F_17 ( V_39 , V_83 , V_63 ,
V_80 ) ;
V_2 -> V_16 . V_120 = true ;
break;
case V_121 :
F_17 ( V_39 , V_83 , V_68 ,
V_80 ) ;
V_2 -> V_16 . V_120 = true ;
break;
case V_122 :
F_17 ( V_39 , V_83 , V_115 ,
V_80 ) ;
V_2 -> V_16 . V_120 = true ;
break;
case V_123 :
if ( V_80 != sizeof( struct V_45 ) )
goto V_93;
if ( F_20 ( V_2 , V_83 ) )
goto V_124;
break;
case V_125 :
if ( V_80 != sizeof( T_2 ) )
goto V_93;
V_2 -> V_16 . V_126 = F_30 ( ( V_95 * ) V_83 ) ;
break;
default:
F_10 ( V_2 , L_18 , V_82 ) ;
break;
}
}
if ( V_8 ) {
F_9 ( V_2 , L_19 , V_8 ) ;
F_31 ( V_2 , V_127 , ( T_3 * ) V_23 , V_8 ) ;
return - V_19 ;
}
return 0 ;
V_93:
F_9 ( V_2 , L_20 , V_82 , V_80 ) ;
V_124:
F_31 ( V_2 , V_127 , V_83 , V_80 ) ;
return - V_19 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_38 * V_39 ,
enum V_40 type )
{
int V_12 ;
for ( V_12 = 0 ;
V_12 < V_13 && F_15 ( V_39 , type , V_12 ) ;
V_12 ++ )
if ( F_5 ( V_2 , & ( V_2 -> V_16 . V_11 [ type ] . V_14 [ V_12 ] ) ,
F_12 ( V_39 , type , V_12 ) ) )
return - V_21 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_38 * V_39 ,
const struct V_128 * V_26 )
{
F_10 ( V_2 , L_21 ,
F_15 ( V_39 , V_63 ,
V_64 ) ) ;
F_10 ( V_2 , L_22 ,
F_15 ( V_39 , V_63 ,
V_66 ) ) ;
F_10 ( V_2 , L_23 ,
F_15 ( V_39 , V_68 , V_64 ) ) ;
F_10 ( V_2 , L_24 ,
F_15 ( V_39 , V_68 , V_66 ) ) ;
if ( F_15 ( V_39 , V_63 , V_64 ) >
V_26 -> V_129 ) {
F_9 ( V_2 , L_25 ,
F_15 ( V_39 , V_63 ,
V_64 ) ) ;
return - 1 ;
}
if ( F_15 ( V_39 , V_63 , V_66 ) >
V_26 -> V_130 ) {
F_9 ( V_2 , L_26 ,
F_15 ( V_39 , V_63 ,
V_66 ) ) ;
return - 1 ;
}
if ( F_15 ( V_39 , V_68 , V_64 ) >
V_26 -> V_129 ) {
F_9 ( V_2 , L_27 ,
F_15 ( V_39 , V_68 ,
V_64 ) ) ;
return - 1 ;
}
if ( F_15 ( V_39 , V_68 , V_66 ) >
V_26 -> V_130 ) {
F_9 ( V_2 , L_28 ,
F_15 ( V_39 , V_63 ,
V_66 ) ) ;
return - 1 ;
}
return 0 ;
}
static void V_37 ( const struct V_50 * V_51 , void * V_131 )
{
struct V_1 * V_2 = V_131 ;
struct V_132 * V_16 = & V_2 -> V_16 ;
struct V_52 * V_53 ;
struct V_133 * V_134 ;
int V_135 ;
struct V_38 V_39 ;
const unsigned int V_136 = V_2 -> V_26 -> V_32 ;
unsigned int V_137 = V_2 -> V_26 -> V_138 ;
const unsigned int V_139 = V_2 -> V_26 -> V_33 ;
T_2 V_54 ;
int V_12 ;
bool V_140 = false ;
V_16 -> V_141 . V_94 = 200 ;
V_16 -> V_141 . V_118 =
V_142 ;
if ( ! V_137 )
V_137 = V_136 ;
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
if ( ! V_51 ) {
if ( V_2 -> V_29 <= V_137 )
F_9 ( V_2 ,
L_29 ,
V_2 -> V_35 ) ;
goto V_143;
}
F_10 ( V_2 , L_30 ,
V_2 -> V_35 , V_51 -> V_18 ) ;
if ( V_51 -> V_18 < 4 ) {
F_9 ( V_2 , L_31 ) ;
goto V_143;
}
V_53 = (struct V_52 * ) V_51 -> V_23 ;
if ( V_53 -> V_60 )
V_135 = F_22 ( V_2 , V_51 , & V_39 ) ;
else
V_135 = F_27 ( V_2 , V_51 , & V_39 ,
& V_16 -> V_141 ) ;
if ( V_135 )
goto V_143;
V_54 = F_23 ( V_2 -> V_16 . V_59 ) ;
if ( V_2 -> V_29 != V_30 ) {
if ( V_54 < V_139 || V_54 > V_136 ) {
F_9 ( V_2 ,
L_32
L_33 ,
V_136 , V_54 ) ;
goto V_143;
}
if ( V_54 < V_137 ) {
if ( V_137 != V_136 )
F_9 ( V_2 , L_34
L_35 ,
V_137 , V_136 , V_54 ) ;
else
F_9 ( V_2 , L_34
L_36 ,
V_136 , V_54 ) ;
F_9 ( V_2 , L_37
L_38 ) ;
}
}
F_34 ( V_2 , L_39 , V_2 -> V_16 . V_72 ) ;
if ( ! V_16 -> V_120 && F_33 ( V_2 , & V_39 , V_2 -> V_26 ) )
goto V_143;
for ( V_12 = 0 ; V_12 < V_15 ; V_12 ++ )
if ( F_32 ( V_2 , & V_39 , V_12 ) )
goto V_144;
V_16 -> V_101 = V_39 . V_101 ;
if ( V_39 . V_103 )
V_16 -> V_103 = ( V_39 . V_103 - 16 ) / 12 ;
else
V_16 -> V_103 =
V_2 -> V_26 -> V_145 -> V_146 ;
V_16 -> V_105 = V_39 . V_105 ;
V_16 -> V_107 = V_39 . V_107 ;
if ( V_39 . V_109 )
V_16 -> V_109 = ( V_39 . V_109 - 16 ) / 12 ;
else
V_16 -> V_109 =
V_2 -> V_26 -> V_145 -> V_146 ;
V_16 -> V_111 = V_39 . V_111 ;
if ( V_16 -> V_141 . V_118 >
V_147 )
V_16 -> V_141 . V_118 =
V_148 ;
F_35 ( V_51 ) ;
F_36 ( & V_149 ) ;
V_134 = & V_133 [ V_150 ] ;
F_37 ( & V_2 -> V_151 , & V_134 -> V_2 ) ;
if ( V_134 -> V_152 ) {
const struct V_153 * V_152 = V_134 -> V_152 ;
V_2 -> V_154 = V_152 -> V_155 ( V_2 -> V_6 , V_2 -> V_26 , & V_2 -> V_16 ) ;
if ( ! V_2 -> V_154 ) {
F_38 ( & V_149 ) ;
goto V_156;
}
} else {
V_140 = true ;
}
F_38 ( & V_149 ) ;
F_39 ( & V_2 -> V_157 ) ;
if ( V_140 )
F_40 ( L_40 , V_134 -> V_158 ) ;
return;
V_143:
F_35 ( V_51 ) ;
if ( F_7 ( V_2 , false ) )
goto V_156;
return;
V_144:
F_9 ( V_2 , L_41 ) ;
F_4 ( V_2 ) ;
F_35 ( V_51 ) ;
V_156:
F_39 ( & V_2 -> V_157 ) ;
F_41 ( V_2 -> V_6 -> V_7 ) ;
}
struct V_1 * F_42 ( struct V_159 * V_6 ,
const struct V_128 * V_26 )
{
struct V_1 * V_2 ;
int V_160 ;
V_2 = F_43 ( sizeof( * V_2 ) , V_20 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_6 = V_6 ;
V_2 -> V_7 = V_6 -> V_7 ;
V_2 -> V_26 = V_26 ;
F_44 ( & V_2 -> V_157 ) ;
F_45 ( & V_2 -> V_151 ) ;
V_160 = F_7 ( V_2 , true ) ;
if ( V_160 ) {
F_9 ( V_6 , L_42 ) ;
F_46 ( V_2 ) ;
V_2 = NULL ;
}
return V_2 ;
}
void F_47 ( struct V_1 * V_2 )
{
F_48 ( & V_2 -> V_157 ) ;
if ( V_2 -> V_154 )
F_49 ( V_2 -> V_154 ) ;
F_4 ( V_2 ) ;
F_36 ( & V_149 ) ;
if ( ! F_50 ( & V_2 -> V_151 ) )
F_51 ( & V_2 -> V_151 ) ;
F_38 ( & V_149 ) ;
F_46 ( V_2 ) ;
}
int F_52 ( const char * V_158 , const struct V_153 * V_152 )
{
int V_12 ;
struct V_1 * V_2 ;
F_36 ( & V_149 ) ;
for ( V_12 = 0 ; V_12 < F_53 ( V_133 ) ; V_12 ++ ) {
if ( strcmp ( V_133 [ V_12 ] . V_158 , V_158 ) )
continue;
V_133 [ V_12 ] . V_152 = V_152 ;
F_54 (drv, &iwlwifi_opmode_table[i].drv, list)
V_2 -> V_154 = V_152 -> V_155 ( V_2 -> V_6 , V_2 -> V_26 ,
& V_2 -> V_16 ) ;
F_38 ( & V_149 ) ;
return 0 ;
}
F_38 ( & V_149 ) ;
return - V_161 ;
}
void F_55 ( const char * V_158 )
{
int V_12 ;
struct V_1 * V_2 ;
F_36 ( & V_149 ) ;
for ( V_12 = 0 ; V_12 < F_53 ( V_133 ) ; V_12 ++ ) {
if ( strcmp ( V_133 [ V_12 ] . V_158 , V_158 ) )
continue;
V_133 [ V_12 ] . V_152 = NULL ;
F_54 (drv, &iwlwifi_opmode_table[i].drv, list) {
if ( V_2 -> V_154 ) {
F_49 ( V_2 -> V_154 ) ;
V_2 -> V_154 = NULL ;
}
}
F_38 ( & V_149 ) ;
return;
}
F_38 ( & V_149 ) ;
}
static int T_4 F_56 ( void )
{
int V_12 ;
F_57 ( & V_149 ) ;
for ( V_12 = 0 ; V_12 < F_53 ( V_133 ) ; V_12 ++ )
F_45 ( & V_133 [ V_12 ] . V_2 ) ;
F_58 ( V_162 L_43 V_163 L_44 ) ;
F_58 ( V_164 L_44 ) ;
return F_59 () ;
}
static void T_5 F_60 ( void )
{
F_61 () ;
}
