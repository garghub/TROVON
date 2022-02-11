static int F_1 ( struct V_1 * V_2 ,
unsigned int type , unsigned int V_3 , int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_7 [ V_6 -> V_8 ] . type = type ;
V_6 -> V_7 [ V_6 -> V_8 ] . V_3 = V_3 ;
V_6 -> V_7 [ V_6 -> V_8 ] . V_4 = V_4 ;
F_3 ( & V_6 -> V_7 [ V_6 -> V_8 ] . time ) ;
V_6 -> V_8 = ( V_6 -> V_8 + 1 ) % V_9 ;
F_4 ( & V_6 -> V_10 ) ;
return 0 ;
}
static bool F_5 ( struct V_5 * V_6 ,
struct V_11 * V_12 )
{
unsigned int V_13 ;
bool V_14 = false ;
F_6 ( & V_6 -> V_15 ) ;
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ ) {
if ( ! V_6 -> V_17 [ V_13 ] ) {
V_12 -> V_13 = V_13 ;
V_6 -> V_17 [ V_13 ] = V_12 ;
V_14 = true ;
break;
}
}
F_7 ( & V_6 -> V_15 ) ;
return V_14 ;
}
static struct V_11 * F_8 ( struct V_5 * V_6 ,
unsigned int V_13 )
{
if ( V_13 >= V_16 )
return NULL ;
return V_6 -> V_17 [ V_13 ] ;
}
static int F_9 ( struct V_5 * V_6 ,
struct V_11 * V_12 )
{
return F_10 ( V_6 -> V_18 ,
F_5 ( V_6 , V_12 ) ) ;
}
static void F_11 ( struct V_5 * V_6 ,
struct V_11 * V_12 )
{
V_6 -> V_17 [ V_12 -> V_13 ] = NULL ;
F_12 ( & V_6 -> V_18 ) ;
F_13 ( & V_12 -> V_19 ) ;
}
static int F_14 ( struct V_5 * V_6 ,
struct V_11 * V_12 )
{
int V_20 ;
V_20 = F_15 ( & V_6 -> V_21 ) ;
if ( V_20 )
return V_20 ;
if ( V_6 -> V_22 != V_23 ) {
V_20 = - V_24 ;
goto V_25;
}
F_16 ( & V_12 -> V_19 ) ;
F_1 ( V_6 -> V_2 , V_26 , V_12 -> V_3 , V_12 -> V_13 ) ;
V_25:
F_17 ( & V_6 -> V_21 ) ;
return V_20 ;
}
static int F_18 ( struct V_5 * V_6 ,
struct V_11 * V_12 )
{
int error ;
error = F_9 ( V_6 , V_12 ) ;
if ( error )
return error ;
error = F_14 ( V_6 , V_12 ) ;
if ( error ) {
F_11 ( V_6 , V_12 ) ;
return error ;
}
F_19 ( & V_12 -> V_19 ) ;
return V_12 -> V_20 ;
}
static void F_20 ( struct V_5 * V_6 )
{
struct V_11 * V_12 ;
int V_27 ;
F_6 ( & V_6 -> V_15 ) ;
for ( V_27 = 0 ; V_27 < V_16 ; V_27 ++ ) {
V_12 = V_6 -> V_17 [ V_27 ] ;
if ( V_12 ) {
V_12 -> V_20 = - V_24 ;
F_11 ( V_6 , V_12 ) ;
}
}
F_7 ( & V_6 -> V_15 ) ;
}
static void F_21 ( struct V_1 * V_2 , T_1 V_28 )
{
F_1 ( V_2 , V_29 , V_30 , V_28 ) ;
}
static void F_22 ( struct V_1 * V_2 , T_1 V_31 )
{
F_1 ( V_2 , V_29 , V_32 , V_31 ) ;
}
static int F_23 ( struct V_1 * V_2 , int V_33 , int V_4 )
{
return F_1 ( V_2 , V_29 , V_33 , V_4 ) ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_34 * V_35 ,
struct V_34 * V_36 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_11 V_12 ;
if ( V_35 -> type == V_37 &&
V_35 -> V_38 . V_39 . V_40 == V_41 )
return - V_42 ;
V_12 . V_3 = V_43 ;
V_12 . V_38 . V_44 . V_35 = V_35 ;
V_12 . V_38 . V_44 . V_36 = V_36 ;
return F_18 ( V_6 , & V_12 ) ;
}
static int F_25 ( struct V_1 * V_2 , int V_33 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_11 V_12 ;
if ( ! F_26 ( V_29 , V_2 -> V_45 ) )
return - V_46 ;
V_12 . V_3 = V_47 ;
V_12 . V_38 . V_33 = V_33 ;
return F_18 ( V_6 , & V_12 ) ;
}
static void F_27 ( struct V_5 * V_6 )
{
const char * V_48 , * V_49 ;
struct V_1 * V_2 = V_6 -> V_2 ;
enum V_50 V_51 = V_6 -> V_22 ;
V_6 -> V_22 = V_52 ;
if ( V_2 ) {
V_48 = V_2 -> V_48 ;
V_49 = V_2 -> V_49 ;
if ( V_51 == V_23 ) {
F_20 ( V_6 ) ;
F_28 ( V_2 ) ;
} else {
F_29 ( V_2 ) ;
}
F_30 ( V_48 ) ;
F_30 ( V_49 ) ;
V_6 -> V_2 = NULL ;
}
}
static int F_31 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
int error ;
if ( V_6 -> V_22 != V_53 ) {
F_32 ( V_54 L_1 , V_55 ) ;
return - V_42 ;
}
if ( V_6 -> V_56 ) {
error = F_33 ( V_2 , V_6 -> V_56 ) ;
if ( error )
goto V_57;
V_2 -> V_58 -> V_44 = F_24 ;
V_2 -> V_58 -> V_59 = F_25 ;
V_2 -> V_58 -> V_60 = F_23 ;
V_2 -> V_58 -> V_61 = F_21 ;
V_2 -> V_58 -> V_62 = F_22 ;
}
error = F_34 ( V_6 -> V_2 ) ;
if ( error )
goto V_63;
V_6 -> V_22 = V_23 ;
return 0 ;
V_63: F_35 ( V_2 ) ;
V_57: F_27 ( V_6 ) ;
return error ;
}
static int F_36 ( struct V_64 * V_64 , struct V_65 * V_65 )
{
struct V_5 * V_66 ;
V_66 = F_37 ( sizeof( struct V_5 ) , V_67 ) ;
if ( ! V_66 )
return - V_68 ;
F_38 ( & V_66 -> V_21 ) ;
F_39 ( & V_66 -> V_15 ) ;
F_40 ( & V_66 -> V_18 ) ;
F_40 ( & V_66 -> V_10 ) ;
V_66 -> V_22 = V_52 ;
V_65 -> V_69 = V_66 ;
F_41 ( V_64 , V_65 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
unsigned int V_70 ;
int V_20 = 0 ;
for ( V_70 = 0 ; V_70 < V_71 ; V_70 ++ ) {
int V_72 , V_73 ;
if ( ! F_26 ( V_70 , V_2 -> V_74 ) )
continue;
V_72 = F_43 ( V_2 , V_70 ) ;
V_73 = F_44 ( V_2 , V_70 ) ;
if ( ( V_72 != 0 || V_73 != 0 ) && V_73 <= V_72 ) {
F_32 ( V_54
L_2 ,
V_55 , V_70 ,
F_43 ( V_2 , V_70 ) ,
F_44 ( V_2 , V_70 ) ) ;
V_20 = - V_42 ;
break;
}
if ( F_45 ( V_2 , V_70 ) >
F_44 ( V_2 , V_70 ) - F_43 ( V_2 , V_70 ) ) {
F_32 ( V_54
L_3
L_4 ,
V_55 , V_70 ,
F_45 ( V_2 , V_70 ) ,
F_43 ( V_2 , V_70 ) ,
F_44 ( V_2 , V_70 ) ) ;
V_20 = - V_42 ;
break;
}
}
return V_20 ;
}
static int F_46 ( struct V_5 * V_6 )
{
V_6 -> V_2 = F_47 () ;
if ( ! V_6 -> V_2 )
return - V_68 ;
V_6 -> V_2 -> V_75 = F_1 ;
F_48 ( V_6 -> V_2 , V_6 ) ;
return 0 ;
}
static int F_49 ( struct V_5 * V_6 ,
const char T_2 * V_76 , T_3 V_77 )
{
struct V_78 * V_79 ;
struct V_1 * V_2 ;
int V_27 ;
int V_20 ;
if ( V_77 != sizeof( struct V_78 ) )
return - V_42 ;
if ( ! V_6 -> V_2 ) {
V_20 = F_46 ( V_6 ) ;
if ( V_20 )
return V_20 ;
}
V_2 = V_6 -> V_2 ;
V_79 = F_50 ( V_76 , sizeof( struct V_78 ) ) ;
if ( F_51 ( V_79 ) )
return F_52 ( V_79 ) ;
V_6 -> V_56 = V_79 -> V_56 ;
if ( ! V_79 -> V_48 [ 0 ] ) {
V_20 = - V_42 ;
goto exit;
}
F_30 ( V_2 -> V_48 ) ;
V_2 -> V_48 = F_53 ( V_79 -> V_48 , V_80 ,
V_67 ) ;
if ( ! V_2 -> V_48 ) {
V_20 = - V_68 ;
goto exit;
}
V_2 -> V_13 . V_81 = V_79 -> V_13 . V_81 ;
V_2 -> V_13 . V_82 = V_79 -> V_13 . V_82 ;
V_2 -> V_13 . V_83 = V_79 -> V_13 . V_83 ;
V_2 -> V_13 . V_84 = V_79 -> V_13 . V_84 ;
for ( V_27 = 0 ; V_27 < V_71 ; V_27 ++ ) {
F_54 ( V_2 , V_27 , V_79 -> V_85 [ V_27 ] ) ;
F_55 ( V_2 , V_27 , V_79 -> V_86 [ V_27 ] ) ;
F_56 ( V_2 , V_27 , V_79 -> V_87 [ V_27 ] ) ;
F_57 ( V_2 , V_27 , V_79 -> V_88 [ V_27 ] ) ;
}
if ( F_26 ( V_89 , V_2 -> V_45 ) ) {
V_20 = F_42 ( V_2 ) ;
if ( V_20 < 0 )
goto exit;
if ( F_26 ( V_90 , V_2 -> V_74 ) ) {
int V_91 = F_44 ( V_2 , V_90 ) + 1 ;
F_58 ( V_2 , V_91 , 0 ) ;
} else if ( F_26 ( V_92 , V_2 -> V_74 ) ) {
F_59 ( V_2 , 60 ) ;
}
}
V_6 -> V_22 = V_53 ;
V_20 = V_77 ;
exit:
F_30 ( V_79 ) ;
return V_20 ;
}
static T_4 F_60 ( struct V_5 * V_6 ,
const char T_2 * V_76 , T_3 V_77 )
{
struct V_93 V_94 ;
T_3 V_95 = 0 ;
if ( V_77 != 0 && V_77 < F_61 () )
return - V_42 ;
while ( V_95 + F_61 () <= V_77 ) {
if ( F_62 ( V_76 + V_95 , & V_94 ) )
return - V_96 ;
V_93 ( V_6 -> V_2 , V_94 . type , V_94 . V_3 , V_94 . V_4 ) ;
V_95 += F_61 () ;
}
return V_95 ;
}
static T_4 F_63 ( struct V_65 * V_65 , const char T_2 * V_76 ,
T_3 V_77 , T_5 * V_97 )
{
struct V_5 * V_6 = V_65 -> V_69 ;
int V_20 ;
if ( V_77 == 0 )
return 0 ;
V_20 = F_15 ( & V_6 -> V_21 ) ;
if ( V_20 )
return V_20 ;
V_20 = V_6 -> V_22 == V_23 ?
F_60 ( V_6 , V_76 , V_77 ) :
F_49 ( V_6 , V_76 , V_77 ) ;
F_17 ( & V_6 -> V_21 ) ;
return V_20 ;
}
static bool F_64 ( struct V_5 * V_6 ,
struct V_93 * V_75 )
{
bool V_98 ;
F_65 ( & V_6 -> V_2 -> V_99 ) ;
V_98 = V_6 -> V_8 != V_6 -> V_100 ;
if ( V_98 ) {
* V_75 = V_6 -> V_7 [ V_6 -> V_100 ] ;
V_6 -> V_100 = ( V_6 -> V_100 + 1 ) % V_9 ;
}
F_66 ( & V_6 -> V_2 -> V_99 ) ;
return V_98 ;
}
static T_4 F_67 ( struct V_5 * V_6 ,
char T_2 * V_76 , T_3 V_77 )
{
struct V_93 V_75 ;
T_3 V_101 = 0 ;
while ( V_101 + F_61 () <= V_77 &&
F_64 ( V_6 , & V_75 ) ) {
if ( F_68 ( V_76 + V_101 , & V_75 ) )
return - V_96 ;
V_101 += F_61 () ;
}
return V_101 ;
}
static T_4 F_69 ( struct V_65 * V_65 , char T_2 * V_76 ,
T_3 V_77 , T_5 * V_97 )
{
struct V_5 * V_6 = V_65 -> V_69 ;
T_4 V_20 ;
if ( V_77 != 0 && V_77 < F_61 () )
return - V_42 ;
do {
V_20 = F_15 ( & V_6 -> V_21 ) ;
if ( V_20 )
return V_20 ;
if ( V_6 -> V_22 != V_23 )
V_20 = - V_24 ;
else if ( V_6 -> V_8 == V_6 -> V_100 &&
( V_65 -> V_102 & V_103 ) )
V_20 = - V_104 ;
else
V_20 = F_67 ( V_6 , V_76 , V_77 ) ;
F_17 ( & V_6 -> V_21 ) ;
if ( V_20 || V_77 == 0 )
break;
if ( ! ( V_65 -> V_102 & V_103 ) )
V_20 = F_10 ( V_6 -> V_10 ,
V_6 -> V_8 != V_6 -> V_100 ||
V_6 -> V_22 != V_23 ) ;
} while ( V_20 == 0 );
return V_20 ;
}
static unsigned int F_70 ( struct V_65 * V_65 , T_6 * V_105 )
{
struct V_5 * V_6 = V_65 -> V_69 ;
F_71 ( V_65 , & V_6 -> V_10 , V_105 ) ;
if ( V_6 -> V_8 != V_6 -> V_100 )
return V_106 | V_107 ;
return 0 ;
}
static int F_72 ( struct V_64 * V_64 , struct V_65 * V_65 )
{
struct V_5 * V_6 = V_65 -> V_69 ;
F_27 ( V_6 ) ;
F_30 ( V_6 ) ;
return 0 ;
}
static int F_73 ( char T_2 * V_76 ,
const struct V_108 * V_109 )
{
if ( V_110 ) {
struct V_111 V_112 ;
V_112 . V_113 = V_109 -> V_113 ;
V_112 . V_20 = V_109 -> V_20 ;
memcpy ( & V_112 . V_35 , & V_109 -> V_35 ,
sizeof( struct V_114 ) ) ;
memcpy ( & V_112 . V_36 , & V_109 -> V_36 ,
sizeof( struct V_114 ) ) ;
if ( F_74 ( V_76 , & V_112 ,
sizeof( struct V_111 ) ) )
return - V_96 ;
} else {
if ( F_74 ( V_76 , V_109 ,
sizeof( struct V_108 ) ) )
return - V_96 ;
}
return 0 ;
}
static int F_75 ( const char T_2 * V_76 ,
struct V_108 * V_109 )
{
if ( V_110 ) {
struct V_111 V_112 ;
if ( F_76 ( & V_112 , V_76 ,
sizeof( struct V_111 ) ) )
return - V_96 ;
V_109 -> V_113 = V_112 . V_113 ;
V_109 -> V_20 = V_112 . V_20 ;
memcpy ( & V_109 -> V_35 , & V_112 . V_35 ,
sizeof( struct V_114 ) ) ;
memcpy ( & V_109 -> V_36 , & V_112 . V_36 ,
sizeof( struct V_114 ) ) ;
} else {
if ( F_76 ( V_109 , V_76 ,
sizeof( struct V_108 ) ) )
return - V_96 ;
}
return 0 ;
}
static int F_73 ( char T_2 * V_76 ,
const struct V_108 * V_109 )
{
if ( F_74 ( V_76 , V_109 , sizeof( struct V_108 ) ) )
return - V_96 ;
return 0 ;
}
static int F_75 ( const char T_2 * V_76 ,
struct V_108 * V_109 )
{
if ( F_76 ( V_109 , V_76 , sizeof( struct V_108 ) ) )
return - V_96 ;
return 0 ;
}
static int F_77 ( void T_2 * V_115 , const char * V_116 ,
unsigned int V_117 )
{
char T_2 * V_118 = V_115 ;
int V_119 , V_120 ;
if ( ! V_116 )
return - V_121 ;
if ( V_117 == 0 )
return - V_42 ;
V_119 = strlen ( V_116 ) + 1 ;
if ( V_119 > V_117 )
V_119 = V_117 ;
V_120 = F_74 ( V_118 , V_116 , V_119 ) ;
if ( V_120 )
return - V_96 ;
V_120 = F_78 ( 0 , V_118 + V_119 - 1 ) ;
return V_120 ? - V_96 : V_119 ;
}
static long F_79 ( struct V_65 * V_65 , unsigned int V_122 ,
unsigned long V_123 , void T_2 * V_118 )
{
int V_20 ;
struct V_5 * V_6 = V_65 -> V_69 ;
struct V_108 V_109 ;
struct V_124 V_125 ;
struct V_11 * V_126 ;
char * V_49 ;
const char * V_48 ;
unsigned int V_127 ;
V_20 = F_15 ( & V_6 -> V_21 ) ;
if ( V_20 )
return V_20 ;
if ( ! V_6 -> V_2 ) {
V_20 = F_46 ( V_6 ) ;
if ( V_20 )
goto V_25;
}
switch ( V_122 ) {
case V_128 :
V_20 = F_31 ( V_6 ) ;
goto V_25;
case V_129 :
F_27 ( V_6 ) ;
goto V_25;
case V_130 :
V_20 = F_80 ( V_123 , V_45 , V_131 ) ;
goto V_25;
case V_132 :
V_20 = F_80 ( V_123 , V_133 , V_134 ) ;
goto V_25;
case V_135 :
V_20 = F_80 ( V_123 , V_136 , V_137 ) ;
goto V_25;
case V_138 :
V_20 = F_80 ( V_123 , V_74 , V_139 ) ;
goto V_25;
case V_140 :
V_20 = F_80 ( V_123 , V_141 , V_142 ) ;
goto V_25;
case V_143 :
V_20 = F_80 ( V_123 , V_144 , V_145 ) ;
goto V_25;
case V_146 :
V_20 = F_80 ( V_123 , V_147 , V_148 ) ;
goto V_25;
case V_149 :
V_20 = F_80 ( V_123 , V_150 , V_151 ) ;
goto V_25;
case V_152 :
V_20 = F_80 ( V_123 , V_153 , V_154 ) ;
goto V_25;
case V_155 :
V_20 = F_80 ( V_123 , V_156 , V_157 ) ;
goto V_25;
case V_158 :
if ( V_6 -> V_22 == V_23 ) {
V_20 = - V_42 ;
goto V_25;
}
V_49 = F_81 ( V_118 , 1024 ) ;
if ( F_51 ( V_49 ) ) {
V_20 = F_52 ( V_49 ) ;
goto V_25;
}
F_30 ( V_6 -> V_2 -> V_49 ) ;
V_6 -> V_2 -> V_49 = V_49 ;
goto V_25;
case V_159 :
V_20 = F_75 ( V_118 , & V_109 ) ;
if ( V_20 )
goto V_25;
V_126 = F_8 ( V_6 , V_109 . V_113 ) ;
if ( ! V_126 || V_126 -> V_3 != V_43 ||
! V_126 -> V_38 . V_44 . V_35 ) {
V_20 = - V_42 ;
goto V_25;
}
V_109 . V_20 = 0 ;
V_109 . V_35 = * V_126 -> V_38 . V_44 . V_35 ;
if ( V_126 -> V_38 . V_44 . V_36 )
V_109 . V_36 = * V_126 -> V_38 . V_44 . V_36 ;
else
memset ( & V_109 . V_36 , 0 , sizeof( struct V_34 ) ) ;
V_20 = F_73 ( V_118 , & V_109 ) ;
goto V_25;
case V_160 :
if ( F_76 ( & V_125 , V_118 , sizeof( V_125 ) ) ) {
V_20 = - V_96 ;
goto V_25;
}
V_126 = F_8 ( V_6 , V_125 . V_113 ) ;
if ( ! V_126 || V_126 -> V_3 != V_47 ) {
V_20 = - V_42 ;
goto V_25;
}
V_125 . V_20 = 0 ;
V_125 . V_33 = V_126 -> V_38 . V_33 ;
if ( F_74 ( V_118 , & V_125 , sizeof( V_125 ) ) ) {
V_20 = - V_96 ;
goto V_25;
}
goto V_25;
case V_161 :
V_20 = F_75 ( V_118 , & V_109 ) ;
if ( V_20 )
goto V_25;
V_126 = F_8 ( V_6 , V_109 . V_113 ) ;
if ( ! V_126 || V_126 -> V_3 != V_43 ||
! V_126 -> V_38 . V_44 . V_35 ) {
V_20 = - V_42 ;
goto V_25;
}
V_126 -> V_20 = V_109 . V_20 ;
F_11 ( V_6 , V_126 ) ;
goto V_25;
case V_162 :
if ( F_76 ( & V_125 , V_118 , sizeof( V_125 ) ) ) {
V_20 = - V_96 ;
goto V_25;
}
V_126 = F_8 ( V_6 , V_125 . V_113 ) ;
if ( ! V_126 || V_126 -> V_3 != V_47 ) {
V_20 = - V_42 ;
goto V_25;
}
V_126 -> V_20 = V_125 . V_20 ;
F_11 ( V_6 , V_126 ) ;
goto V_25;
}
V_127 = F_82 ( V_122 ) ;
switch ( V_122 & ~ V_163 ) {
case F_83 ( 0 ) :
if ( V_6 -> V_22 != V_23 ) {
V_20 = - V_121 ;
goto V_25;
}
V_48 = F_84 ( & V_6 -> V_2 -> V_2 ) ;
V_20 = F_77 ( V_118 , V_48 , V_127 ) ;
goto V_25;
}
V_20 = - V_42 ;
V_25:
F_17 ( & V_6 -> V_21 ) ;
return V_20 ;
}
static long F_85 ( struct V_65 * V_65 , unsigned int V_122 , unsigned long V_123 )
{
return F_79 ( V_65 , V_122 , V_123 , ( void T_2 * ) V_123 ) ;
}
static long F_86 ( struct V_65 * V_65 ,
unsigned int V_122 , unsigned long V_123 )
{
return F_79 ( V_65 , V_122 , V_123 , F_87 ( V_123 ) ) ;
}
static int T_7 F_88 ( void )
{
return F_89 ( & V_164 ) ;
}
static void T_8 F_90 ( void )
{
F_91 ( & V_164 ) ;
}
