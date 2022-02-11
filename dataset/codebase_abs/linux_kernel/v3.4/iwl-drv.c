static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_5 )
F_2 ( F_3 ( V_2 ) -> V_6 , V_4 -> V_7 ,
V_4 -> V_5 , V_4 -> V_8 ) ;
V_4 -> V_5 = NULL ;
V_4 -> V_7 = 0 ;
}
static void F_4 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ )
F_1 ( V_2 , & V_10 -> V_13 [ V_11 ] ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_14 ; V_11 ++ )
F_4 ( V_2 , V_2 -> V_15 . V_10 + V_11 ) ;
}
static int F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_16 * V_13 )
{
if ( ! V_13 || ! V_13 -> V_17 ) {
V_4 -> V_5 = NULL ;
return - V_18 ;
}
V_4 -> V_5 = F_7 ( F_3 ( V_2 ) -> V_6 , V_13 -> V_17 ,
& V_4 -> V_8 , V_19 ) ;
if ( ! V_4 -> V_5 )
return - V_20 ;
V_4 -> V_7 = V_13 -> V_17 ;
V_4 -> V_21 = V_13 -> V_21 ;
memcpy ( V_4 -> V_5 , V_13 -> V_22 , V_13 -> V_17 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , bool V_23 )
{
const struct V_24 * V_25 = V_25 ( V_2 ) ;
const char * V_26 = V_25 -> V_27 ;
char V_28 [ 8 ] ;
if ( V_23 ) {
#ifdef F_9
V_2 -> V_29 = V_30 ;
strcpy ( V_28 , V_31 ) ;
} else if ( V_2 -> V_29 == V_30 ) {
#endif
V_2 -> V_29 = V_25 -> V_32 ;
sprintf ( V_28 , L_1 , V_2 -> V_29 ) ;
} else {
V_2 -> V_29 -- ;
sprintf ( V_28 , L_1 , V_2 -> V_29 ) ;
}
if ( V_2 -> V_29 < V_25 -> V_33 ) {
F_10 ( V_2 , L_2 ) ;
return - V_34 ;
}
sprintf ( V_2 -> V_35 , L_3 , V_26 , V_28 , L_4 ) ;
F_11 ( V_2 , L_5 ,
( V_2 -> V_29 == V_30 )
? L_6 : L_7 ,
V_2 -> V_35 ) ;
return F_12 ( V_36 , 1 , V_2 -> V_35 ,
F_3 ( V_2 ) -> V_6 ,
V_19 , V_2 , V_37 ) ;
}
static struct V_16 * F_13 ( struct V_38 * V_39 ,
enum V_40 type ,
int V_13 )
{
return & V_39 -> V_10 [ type ] . V_13 [ V_13 ] ;
}
static void F_14 ( struct V_38 * V_39 ,
enum V_40 type ,
int V_13 ,
const void * V_22 )
{
V_39 -> V_10 [ type ] . V_13 [ V_13 ] . V_22 = V_22 ;
}
static void F_15 ( struct V_38 * V_39 ,
enum V_40 type ,
int V_13 ,
T_1 V_17 )
{
V_39 -> V_10 [ type ] . V_13 [ V_13 ] . V_17 = V_17 ;
}
static T_1 F_16 ( struct V_38 * V_39 ,
enum V_40 type ,
int V_13 )
{
return V_39 -> V_10 [ type ] . V_13 [ V_13 ] . V_17 ;
}
static void F_17 ( struct V_38 * V_39 ,
enum V_40 type ,
int V_13 ,
T_2 V_21 )
{
V_39 -> V_10 [ type ] . V_13 [ V_13 ] . V_21 = V_21 ;
}
static int F_18 ( struct V_38 * V_39 ,
const void * V_22 , enum V_40 type ,
int V_17 )
{
struct V_41 * V_10 ;
struct V_16 * V_13 ;
struct V_42 * V_43 ;
if ( F_19 ( ! V_39 || ! V_22 || type >= V_14 ) )
return - 1 ;
V_43 = (struct V_42 * ) V_22 ;
V_10 = & V_39 -> V_10 [ type ] ;
V_13 = & V_10 -> V_13 [ V_10 -> V_44 ] ;
V_13 -> V_21 = F_20 ( V_43 -> V_21 ) ;
V_13 -> V_22 = V_43 -> V_22 ;
++ V_10 -> V_44 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , const T_3 * V_22 )
{
struct V_45 * V_46 =
(struct V_45 * ) V_22 ;
T_2 V_47 = F_20 ( V_46 -> V_47 ) ;
if ( V_47 >= V_14 ) {
F_10 ( V_2 , L_8 ,
V_47 ) ;
return - V_18 ;
}
V_2 -> V_15 . V_48 [ V_47 ] = F_22 ( V_46 -> V_49 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
const struct V_50 * V_51 ,
struct V_38 * V_39 )
{
struct V_52 * V_53 = ( void * ) V_51 -> V_22 ;
T_2 V_54 , V_55 , V_56 ;
char V_57 [ 25 ] ;
const T_3 * V_58 ;
V_2 -> V_15 . V_59 = F_20 ( V_53 -> V_60 ) ;
V_54 = F_24 ( V_2 -> V_15 . V_59 ) ;
switch ( V_54 ) {
default:
V_55 = 28 ;
if ( V_51 -> V_17 < V_55 ) {
F_10 ( V_2 , L_9 ) ;
return - V_18 ;
}
V_56 = F_20 ( V_53 -> V_61 . V_62 . V_56 ) ;
F_15 ( V_39 , V_63 , V_64 ,
F_20 ( V_53 -> V_61 . V_62 . V_65 ) ) ;
F_15 ( V_39 , V_63 , V_66 ,
F_20 ( V_53 -> V_61 . V_62 . V_67 ) ) ;
F_15 ( V_39 , V_68 , V_64 ,
F_20 ( V_53 -> V_61 . V_62 . V_69 ) ) ;
F_15 ( V_39 , V_68 , V_66 ,
F_20 ( V_53 -> V_61 . V_62 . V_70 ) ) ;
V_58 = V_53 -> V_61 . V_62 . V_22 ;
break;
case 0 :
case 1 :
case 2 :
V_55 = 24 ;
if ( V_51 -> V_17 < V_55 ) {
F_10 ( V_2 , L_9 ) ;
return - V_18 ;
}
V_56 = 0 ;
F_15 ( V_39 , V_63 , V_64 ,
F_20 ( V_53 -> V_61 . V_71 . V_65 ) ) ;
F_15 ( V_39 , V_63 , V_66 ,
F_20 ( V_53 -> V_61 . V_71 . V_67 ) ) ;
F_15 ( V_39 , V_68 , V_64 ,
F_20 ( V_53 -> V_61 . V_71 . V_69 ) ) ;
F_15 ( V_39 , V_68 , V_66 ,
F_20 ( V_53 -> V_61 . V_71 . V_70 ) ) ;
V_58 = V_53 -> V_61 . V_71 . V_22 ;
break;
}
if ( V_56 )
sprintf ( V_57 , L_10 , V_56 ,
( V_2 -> V_29 == V_30 )
? L_11 : L_7 ) ;
else
V_57 [ 0 ] = '\0' ;
snprintf ( V_2 -> V_15 . V_72 ,
sizeof( V_2 -> V_15 . V_72 ) ,
L_12 ,
F_25 ( V_2 -> V_15 . V_59 ) ,
F_26 ( V_2 -> V_15 . V_59 ) ,
F_24 ( V_2 -> V_15 . V_59 ) ,
F_27 ( V_2 -> V_15 . V_59 ) ,
V_57 ) ;
if ( V_51 -> V_17 != V_55 +
F_16 ( V_39 , V_63 , V_64 ) +
F_16 ( V_39 , V_63 , V_66 ) +
F_16 ( V_39 , V_68 , V_64 ) +
F_16 ( V_39 , V_68 , V_66 ) ) {
F_10 ( V_2 ,
L_13 ,
( int ) V_51 -> V_17 ) ;
return - V_18 ;
}
F_14 ( V_39 , V_63 , V_64 , V_58 ) ;
V_58 += F_16 ( V_39 , V_63 , V_64 ) ;
F_17 ( V_39 , V_63 , V_64 ,
V_73 ) ;
F_14 ( V_39 , V_63 , V_66 , V_58 ) ;
V_58 += F_16 ( V_39 , V_63 , V_66 ) ;
F_17 ( V_39 , V_63 , V_66 ,
V_74 ) ;
F_14 ( V_39 , V_68 , V_64 , V_58 ) ;
V_58 += F_16 ( V_39 , V_68 , V_64 ) ;
F_17 ( V_39 , V_68 , V_64 ,
V_73 ) ;
F_14 ( V_39 , V_68 , V_66 , V_58 ) ;
V_58 += F_16 ( V_39 , V_68 , V_66 ) ;
F_17 ( V_39 , V_68 , V_66 ,
V_74 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
const struct V_50 * V_51 ,
struct V_38 * V_39 ,
struct V_75 * V_76 )
{
struct V_77 * V_53 = ( void * ) V_51 -> V_22 ;
struct V_78 * V_79 ;
T_1 V_7 = V_51 -> V_17 ;
const T_3 * V_22 ;
int V_80 = V_81 . V_82 ;
int V_83 ;
T_4 V_84 ;
T_2 V_85 ;
enum V_86 V_87 ;
const T_3 * V_88 ;
char V_57 [ 25 ] ;
T_2 V_56 ;
if ( V_7 < sizeof( * V_53 ) ) {
F_10 ( V_2 , L_14 , V_7 ) ;
return - V_18 ;
}
if ( V_53 -> V_89 != F_29 ( V_90 ) ) {
F_10 ( V_2 , L_15 ,
F_20 ( V_53 -> V_89 ) ) ;
return - V_18 ;
}
V_84 = F_22 ( V_53 -> V_84 ) ;
V_83 = V_80 ;
if ( V_80 > 63 )
V_80 = 63 ;
while ( V_80 && ! ( V_84 & F_30 ( V_80 ) ) )
V_80 -- ;
if ( V_80 && V_80 != V_83 )
F_31 ( V_2 ,
L_16 ,
V_83 , V_80 ) ;
V_2 -> V_15 . V_59 = F_20 ( V_53 -> V_60 ) ;
V_56 = F_20 ( V_53 -> V_56 ) ;
if ( V_56 )
sprintf ( V_57 , L_10 , V_56 ,
( V_2 -> V_29 == V_30 )
? L_11 : L_7 ) ;
else
V_57 [ 0 ] = '\0' ;
snprintf ( V_2 -> V_15 . V_72 ,
sizeof( V_2 -> V_15 . V_72 ) ,
L_12 ,
F_25 ( V_2 -> V_15 . V_59 ) ,
F_26 ( V_2 -> V_15 . V_59 ) ,
F_24 ( V_2 -> V_15 . V_59 ) ,
F_27 ( V_2 -> V_15 . V_59 ) ,
V_57 ) ;
V_22 = V_53 -> V_22 ;
V_7 -= sizeof( * V_53 ) ;
while ( V_7 >= sizeof( * V_79 ) ) {
T_5 V_91 ;
V_7 -= sizeof( * V_79 ) ;
V_79 = ( void * ) V_22 ;
V_85 = F_20 ( V_79 -> V_92 ) ;
V_87 = F_32 ( V_79 -> type ) ;
V_91 = F_32 ( V_79 -> V_93 ) ;
V_88 = V_79 -> V_22 ;
if ( V_7 < V_85 ) {
F_10 ( V_2 , L_17 ,
V_7 , V_85 ) ;
return - V_18 ;
}
V_7 -= F_33 ( V_85 , 4 ) ;
V_22 += sizeof( * V_79 ) + F_33 ( V_85 , 4 ) ;
if ( V_91 != 0 && V_91 != V_80 )
continue;
switch ( V_87 ) {
case V_94 :
F_14 ( V_39 , V_63 ,
V_64 , V_88 ) ;
F_15 ( V_39 , V_63 ,
V_64 , V_85 ) ;
F_17 ( V_39 , V_63 ,
V_64 ,
V_73 ) ;
break;
case V_95 :
F_14 ( V_39 , V_63 ,
V_66 , V_88 ) ;
F_15 ( V_39 , V_63 ,
V_66 , V_85 ) ;
F_17 ( V_39 , V_63 ,
V_66 ,
V_74 ) ;
break;
case V_96 :
F_14 ( V_39 , V_68 ,
V_64 , V_88 ) ;
F_15 ( V_39 , V_68 ,
V_64 , V_85 ) ;
F_17 ( V_39 , V_68 ,
V_64 ,
V_73 ) ;
break;
case V_97 :
F_14 ( V_39 , V_68 ,
V_66 , V_88 ) ;
F_15 ( V_39 , V_68 ,
V_66 , V_85 ) ;
F_17 ( V_39 , V_68 ,
V_66 ,
V_74 ) ;
break;
case V_98 :
F_10 ( V_2 , L_18 ) ;
break;
case V_99 :
if ( V_85 != sizeof( T_2 ) )
goto V_100;
V_76 -> V_101 =
F_34 ( ( V_102 * ) V_88 ) ;
break;
case V_103 :
if ( V_85 )
goto V_100;
V_76 -> V_104 |= V_105 ;
break;
case V_106 :
if ( V_85 < sizeof( T_2 ) )
goto V_100;
if ( V_85 % sizeof( T_2 ) )
goto V_100;
V_76 -> V_104 = F_34 ( ( V_102 * ) V_88 ) ;
break;
case V_107 :
if ( V_85 != sizeof( T_2 ) )
goto V_100;
V_39 -> V_108 =
F_34 ( ( V_102 * ) V_88 ) ;
break;
case V_109 :
if ( V_85 != sizeof( T_2 ) )
goto V_100;
V_39 -> V_110 =
F_34 ( ( V_102 * ) V_88 ) ;
break;
case V_111 :
if ( V_85 != sizeof( T_2 ) )
goto V_100;
V_39 -> V_112 =
F_34 ( ( V_102 * ) V_88 ) ;
break;
case V_113 :
if ( V_85 != sizeof( T_2 ) )
goto V_100;
V_39 -> V_114 =
F_34 ( ( V_102 * ) V_88 ) ;
break;
case V_115 :
if ( V_85 != sizeof( T_2 ) )
goto V_100;
V_39 -> V_116 =
F_34 ( ( V_102 * ) V_88 ) ;
break;
case V_117 :
if ( V_85 != sizeof( T_2 ) )
goto V_100;
V_39 -> V_118 =
F_34 ( ( V_102 * ) V_88 ) ;
break;
case V_119 :
if ( V_85 )
goto V_100;
V_2 -> V_15 . V_120 = true ;
break;
case V_121 :
F_14 ( V_39 , V_122 ,
V_64 , V_88 ) ;
F_15 ( V_39 , V_122 ,
V_64 , V_85 ) ;
F_17 ( V_39 , V_122 ,
V_64 ,
V_73 ) ;
break;
case V_123 :
F_14 ( V_39 , V_122 ,
V_66 , V_88 ) ;
F_15 ( V_39 , V_122 ,
V_66 , V_85 ) ;
F_17 ( V_39 , V_122 ,
V_66 ,
V_74 ) ;
break;
case V_124 :
if ( V_85 != sizeof( T_2 ) )
goto V_100;
V_76 -> V_125 =
F_34 ( ( V_102 * ) V_88 ) ;
break;
case V_126 :
F_18 ( V_39 , V_88 , V_63 ,
V_85 ) ;
V_2 -> V_15 . V_127 = true ;
break;
case V_128 :
F_18 ( V_39 , V_88 , V_68 ,
V_85 ) ;
V_2 -> V_15 . V_127 = true ;
break;
case V_129 :
F_18 ( V_39 , V_88 , V_122 ,
V_85 ) ;
V_2 -> V_15 . V_127 = true ;
break;
case V_130 :
if ( V_85 != sizeof( struct V_45 ) )
goto V_100;
if ( F_21 ( V_2 , V_88 ) )
goto V_131;
break;
case V_132 :
if ( V_85 != sizeof( T_2 ) )
goto V_100;
V_2 -> V_15 . V_133 = F_34 ( ( V_102 * ) V_88 ) ;
break;
default:
F_11 ( V_2 , L_19 , V_87 ) ;
break;
}
}
if ( V_7 ) {
F_10 ( V_2 , L_20 , V_7 ) ;
F_35 ( V_2 , V_134 , ( T_3 * ) V_22 , V_7 ) ;
return - V_18 ;
}
return 0 ;
V_100:
F_10 ( V_2 , L_21 , V_87 , V_85 ) ;
V_131:
F_35 ( V_2 , V_134 , V_88 , V_85 ) ;
return - V_18 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_38 * V_39 ,
enum V_40 type )
{
int V_11 ;
for ( V_11 = 0 ;
V_11 < V_12 && F_16 ( V_39 , type , V_11 ) ;
V_11 ++ )
if ( F_6 ( V_2 , & ( V_2 -> V_15 . V_10 [ type ] . V_13 [ V_11 ] ) ,
F_13 ( V_39 , type , V_11 ) ) )
return - 1 ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_38 * V_39 ,
const struct V_24 * V_25 )
{
F_11 ( V_2 , L_22 ,
F_16 ( V_39 , V_63 ,
V_64 ) ) ;
F_11 ( V_2 , L_23 ,
F_16 ( V_39 , V_63 ,
V_66 ) ) ;
F_11 ( V_2 , L_24 ,
F_16 ( V_39 , V_68 , V_64 ) ) ;
F_11 ( V_2 , L_25 ,
F_16 ( V_39 , V_68 , V_66 ) ) ;
if ( F_16 ( V_39 , V_63 , V_64 ) >
V_25 -> V_135 ) {
F_10 ( V_2 , L_26 ,
F_16 ( V_39 , V_63 ,
V_64 ) ) ;
return - 1 ;
}
if ( F_16 ( V_39 , V_63 , V_66 ) >
V_25 -> V_136 ) {
F_10 ( V_2 , L_27 ,
F_16 ( V_39 , V_63 ,
V_66 ) ) ;
return - 1 ;
}
if ( F_16 ( V_39 , V_68 , V_64 ) >
V_25 -> V_135 ) {
F_10 ( V_2 , L_28 ,
F_16 ( V_39 , V_68 ,
V_64 ) ) ;
return - 1 ;
}
if ( F_16 ( V_39 , V_68 , V_66 ) >
V_25 -> V_136 ) {
F_10 ( V_2 , L_29 ,
F_16 ( V_39 , V_63 ,
V_66 ) ) ;
return - 1 ;
}
return 0 ;
}
static void V_37 ( const struct V_50 * V_51 , void * V_137 )
{
struct V_1 * V_2 = V_137 ;
const struct V_24 * V_25 = V_25 ( V_2 ) ;
struct V_138 * V_15 = & V_2 -> V_15 ;
struct V_52 * V_53 ;
int V_139 ;
struct V_38 V_39 ;
const unsigned int V_140 = V_25 -> V_32 ;
unsigned int V_141 = V_25 -> V_142 ;
const unsigned int V_143 = V_25 -> V_33 ;
T_2 V_54 ;
int V_11 ;
V_15 -> V_144 . V_101 = 200 ;
V_15 -> V_144 . V_125 =
V_145 ;
if ( ! V_141 )
V_141 = V_140 ;
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
if ( ! V_51 ) {
if ( V_2 -> V_29 <= V_141 )
F_10 ( V_2 ,
L_30 ,
V_2 -> V_35 ) ;
goto V_146;
}
F_11 ( V_2 , L_31 ,
V_2 -> V_35 , V_51 -> V_17 ) ;
if ( V_51 -> V_17 < 4 ) {
F_10 ( V_2 , L_32 ) ;
goto V_146;
}
V_53 = (struct V_52 * ) V_51 -> V_22 ;
if ( V_53 -> V_60 )
V_139 = F_23 ( V_2 , V_51 , & V_39 ) ;
else
V_139 = F_28 ( V_2 , V_51 , & V_39 ,
& V_15 -> V_144 ) ;
if ( V_139 )
goto V_146;
V_54 = F_24 ( V_2 -> V_15 . V_59 ) ;
if ( V_2 -> V_29 != V_30 ) {
if ( V_54 < V_143 || V_54 > V_140 ) {
F_10 ( V_2 ,
L_33
L_34 ,
V_140 , V_54 ) ;
goto V_146;
}
if ( V_54 < V_141 ) {
if ( V_141 != V_140 )
F_10 ( V_2 , L_35
L_36 ,
V_141 , V_140 , V_54 ) ;
else
F_10 ( V_2 , L_35
L_37 ,
V_140 , V_54 ) ;
F_10 ( V_2 , L_38
L_39 ) ;
}
}
F_38 ( V_2 , L_40 , V_2 -> V_15 . V_72 ) ;
F_11 ( V_2 , L_41 ,
V_2 -> V_15 . V_59 ) ;
F_11 ( V_2 , L_22 ,
F_16 ( & V_39 , V_63 ,
V_64 ) ) ;
F_11 ( V_2 , L_23 ,
F_16 ( & V_39 , V_63 ,
V_66 ) ) ;
F_11 ( V_2 , L_24 ,
F_16 ( & V_39 , V_68 , V_64 ) ) ;
F_11 ( V_2 , L_25 ,
F_16 ( & V_39 , V_68 , V_66 ) ) ;
if ( F_16 ( & V_39 , V_63 , V_64 ) >
V_25 -> V_135 ) {
F_10 ( V_2 , L_26 ,
F_16 ( & V_39 , V_63 ,
V_64 ) ) ;
goto V_146;
}
if ( F_16 ( & V_39 , V_63 , V_66 ) >
V_25 -> V_136 ) {
F_10 ( V_2 , L_27 ,
F_16 ( & V_39 , V_63 ,
V_66 ) ) ;
goto V_146;
}
if ( ! V_15 -> V_127 && F_37 ( V_2 , & V_39 , V_25 ) )
goto V_146;
for ( V_11 = 0 ; V_11 < V_14 ; V_11 ++ )
if ( F_36 ( V_2 , & V_39 , V_11 ) )
goto V_147;
V_15 -> V_108 = V_39 . V_108 ;
if ( V_39 . V_110 )
V_15 -> V_110 = ( V_39 . V_110 - 16 ) / 12 ;
else
V_15 -> V_110 =
V_25 -> V_148 -> V_149 ;
V_15 -> V_112 = V_39 . V_112 ;
V_15 -> V_114 = V_39 . V_114 ;
if ( V_39 . V_116 )
V_15 -> V_116 = ( V_39 . V_116 - 16 ) / 12 ;
else
V_15 -> V_116 =
V_25 -> V_148 -> V_149 ;
V_15 -> V_118 = V_39 . V_118 ;
if ( V_15 -> V_144 . V_125 >
V_150 )
V_15 -> V_144 . V_125 =
V_151 ;
F_39 ( V_51 ) ;
F_40 ( & V_2 -> V_152 ) ;
V_2 -> V_153 = V_154 . V_155 ( V_2 -> V_156 -> F_3 , & V_2 -> V_15 ) ;
if ( ! V_2 -> V_153 )
goto V_157;
return;
V_146:
F_39 ( V_51 ) ;
if ( F_8 ( V_2 , false ) )
goto V_157;
return;
V_147:
F_10 ( V_2 , L_42 ) ;
F_5 ( V_2 ) ;
F_39 ( V_51 ) ;
V_157:
F_40 ( & V_2 -> V_152 ) ;
F_41 ( F_3 ( V_2 ) -> V_6 ) ;
}
int F_42 ( struct V_158 * V_156 ,
struct V_159 * F_3 , const struct V_24 * V_25 )
{
struct V_1 * V_2 ;
int V_160 ;
V_156 -> V_25 = V_25 ;
V_2 = F_43 ( sizeof( * V_2 ) , V_19 ) ;
if ( ! V_2 ) {
F_44 ( V_161 , F_3 -> V_6 , L_43 ) ;
return - V_20 ;
}
V_2 -> V_156 = V_156 ;
V_156 -> V_2 = V_2 ;
F_45 ( & V_2 -> V_152 ) ;
V_160 = F_8 ( V_2 , true ) ;
if ( V_160 ) {
F_44 ( V_161 , F_3 -> V_6 , L_44 ) ;
F_46 ( V_2 ) ;
V_156 -> V_2 = NULL ;
}
return V_160 ;
}
void F_47 ( struct V_158 * V_156 )
{
struct V_1 * V_2 = V_156 -> V_2 ;
F_48 ( & V_2 -> V_152 ) ;
if ( V_2 -> V_153 )
F_49 ( V_2 -> V_153 ) ;
F_5 ( V_2 ) ;
F_46 ( V_2 ) ;
V_156 -> V_2 = NULL ;
}
