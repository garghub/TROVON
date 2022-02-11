static int F_1 ( struct V_1 * V_2 , unsigned int type , unsigned int V_3 , int V_4 )
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
static int F_5 ( struct V_5 * V_6 , struct V_11 * V_12 )
{
int V_13 ;
int V_14 = - 1 ;
F_6 ( & V_6 -> V_15 ) ;
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ ) {
if ( ! V_6 -> V_17 [ V_13 ] ) {
V_12 -> V_13 = V_13 ;
V_6 -> V_17 [ V_13 ] = V_12 ;
V_14 = 0 ;
break;
}
}
F_7 ( & V_6 -> V_15 ) ;
return V_14 ;
}
static struct V_11 * F_8 ( struct V_5 * V_6 , int V_13 )
{
if ( V_13 >= V_16 || V_13 < 0 )
return NULL ;
return V_6 -> V_17 [ V_13 ] ;
}
static inline int F_9 ( struct V_5 * V_6 , struct V_11 * V_12 )
{
return F_10 ( V_6 -> V_18 ,
! F_5 ( V_6 , V_12 ) ) ;
}
static void F_11 ( struct V_5 * V_6 , struct V_11 * V_12 )
{
V_6 -> V_17 [ V_12 -> V_13 ] = NULL ;
F_12 ( & V_6 -> V_18 ) ;
F_13 ( & V_12 -> V_19 ) ;
}
static int F_14 ( struct V_5 * V_6 , struct V_11 * V_12 )
{
int V_20 ;
V_20 = F_9 ( V_6 , V_12 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_15 ( & V_6 -> V_21 ) ;
if ( V_20 )
return V_20 ;
if ( V_6 -> V_22 != V_23 ) {
V_20 = - V_24 ;
goto V_25;
}
F_1 ( V_6 -> V_2 , V_26 , V_12 -> V_3 , V_12 -> V_13 ) ;
V_25:
F_16 ( & V_6 -> V_21 ) ;
return V_20 ;
}
static void F_17 ( struct V_5 * V_6 )
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
static void F_18 ( struct V_1 * V_2 , T_1 V_28 )
{
F_1 ( V_2 , V_29 , V_30 , V_28 ) ;
}
static void F_19 ( struct V_1 * V_2 , T_1 V_31 )
{
F_1 ( V_2 , V_29 , V_32 , V_31 ) ;
}
static int F_20 ( struct V_1 * V_2 , int V_33 , int V_4 )
{
return F_1 ( V_2 , V_29 , V_33 , V_4 ) ;
}
static int F_21 ( struct V_1 * V_2 , struct V_34 * V_35 , struct V_34 * V_36 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_11 V_12 ;
int V_20 ;
if ( V_35 -> type == V_37 &&
V_35 -> V_38 . V_39 . V_40 == V_41 )
return - V_42 ;
V_12 . V_13 = - 1 ;
F_22 ( & V_12 . V_19 ) ;
V_12 . V_3 = V_43 ;
V_12 . V_38 . V_44 . V_35 = V_35 ;
V_12 . V_38 . V_44 . V_36 = V_36 ;
V_20 = F_14 ( V_6 , & V_12 ) ;
if ( ! V_20 ) {
F_23 ( & V_12 . V_19 ) ;
V_20 = V_12 . V_20 ;
}
return V_20 ;
}
static int F_24 ( struct V_1 * V_2 , int V_33 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_11 V_12 ;
int V_20 ;
if ( ! F_25 ( V_29 , V_2 -> V_45 ) )
return - V_46 ;
V_12 . V_13 = - 1 ;
F_22 ( & V_12 . V_19 ) ;
V_12 . V_3 = V_47 ;
V_12 . V_38 . V_33 = V_33 ;
V_20 = F_14 ( V_6 , & V_12 ) ;
if ( ! V_20 ) {
F_23 ( & V_12 . V_19 ) ;
V_20 = V_12 . V_20 ;
}
return V_20 ;
}
static void F_26 ( struct V_5 * V_6 )
{
const char * V_48 , * V_49 ;
struct V_1 * V_2 = V_6 -> V_2 ;
enum V_50 V_51 = V_6 -> V_22 ;
V_6 -> V_22 = V_52 ;
if ( V_2 ) {
V_48 = V_2 -> V_48 ;
V_49 = V_2 -> V_49 ;
if ( V_51 == V_23 ) {
F_17 ( V_6 ) ;
F_27 ( V_2 ) ;
} else {
F_28 ( V_2 ) ;
}
F_29 ( V_48 ) ;
F_29 ( V_49 ) ;
V_6 -> V_2 = NULL ;
}
}
static int F_30 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
int error ;
if ( V_6 -> V_22 != V_53 ) {
F_31 ( V_54 L_1 , V_55 ) ;
return - V_42 ;
}
if ( V_6 -> V_56 ) {
error = F_32 ( V_2 , V_6 -> V_56 ) ;
if ( error )
goto V_57;
V_2 -> V_58 -> V_44 = F_21 ;
V_2 -> V_58 -> V_59 = F_24 ;
V_2 -> V_58 -> V_60 = F_20 ;
V_2 -> V_58 -> V_61 = F_18 ;
V_2 -> V_58 -> V_62 = F_19 ;
}
error = F_33 ( V_6 -> V_2 ) ;
if ( error )
goto V_63;
V_6 -> V_22 = V_23 ;
return 0 ;
V_63: F_34 ( V_2 ) ;
V_57: F_26 ( V_6 ) ;
return error ;
}
static int F_35 ( struct V_64 * V_64 , struct V_65 * V_65 )
{
struct V_5 * V_66 ;
V_66 = F_36 ( sizeof( struct V_5 ) , V_67 ) ;
if ( ! V_66 )
return - V_68 ;
F_37 ( & V_66 -> V_21 ) ;
F_38 ( & V_66 -> V_15 ) ;
F_39 ( & V_66 -> V_18 ) ;
F_39 ( & V_66 -> V_10 ) ;
V_66 -> V_22 = V_52 ;
V_65 -> V_69 = V_66 ;
F_40 ( V_64 , V_65 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
unsigned int V_70 ;
int V_20 = 0 ;
for ( V_70 = 0 ; V_70 < V_71 ; V_70 ++ ) {
int V_72 , V_73 ;
if ( ! F_25 ( V_70 , V_2 -> V_74 ) )
continue;
V_72 = F_42 ( V_2 , V_70 ) ;
V_73 = F_43 ( V_2 , V_70 ) ;
if ( ( V_72 != 0 || V_73 != 0 ) && V_73 <= V_72 ) {
F_31 ( V_54
L_2 ,
V_55 , V_70 ,
F_42 ( V_2 , V_70 ) ,
F_43 ( V_2 , V_70 ) ) ;
V_20 = - V_42 ;
break;
}
if ( F_44 ( V_2 , V_70 ) >
F_43 ( V_2 , V_70 ) - F_42 ( V_2 , V_70 ) ) {
F_31 ( V_54
L_3
L_4 ,
V_55 , V_70 ,
F_44 ( V_2 , V_70 ) ,
F_42 ( V_2 , V_70 ) ,
F_43 ( V_2 , V_70 ) ) ;
V_20 = - V_42 ;
break;
}
}
return V_20 ;
}
static int F_45 ( struct V_5 * V_6 )
{
V_6 -> V_2 = F_46 () ;
if ( ! V_6 -> V_2 )
return - V_68 ;
V_6 -> V_2 -> V_75 = F_1 ;
F_47 ( V_6 -> V_2 , V_6 ) ;
return 0 ;
}
static int F_48 ( struct V_5 * V_6 , const char T_2 * V_76 , T_3 V_77 )
{
struct V_78 * V_79 ;
struct V_1 * V_2 ;
int V_27 ;
int V_20 ;
if ( V_77 != sizeof( struct V_78 ) )
return - V_42 ;
if ( ! V_6 -> V_2 ) {
V_20 = F_45 ( V_6 ) ;
if ( V_20 )
return V_20 ;
}
V_2 = V_6 -> V_2 ;
V_79 = F_49 ( V_76 , sizeof( struct V_78 ) ) ;
if ( F_50 ( V_79 ) )
return F_51 ( V_79 ) ;
V_6 -> V_56 = V_79 -> V_56 ;
if ( ! V_79 -> V_48 [ 0 ] ) {
V_20 = - V_42 ;
goto exit;
}
F_29 ( V_2 -> V_48 ) ;
V_2 -> V_48 = F_52 ( V_79 -> V_48 , V_80 ,
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
F_53 ( V_2 , V_27 , V_79 -> V_85 [ V_27 ] ) ;
F_54 ( V_2 , V_27 , V_79 -> V_86 [ V_27 ] ) ;
F_55 ( V_2 , V_27 , V_79 -> V_87 [ V_27 ] ) ;
F_56 ( V_2 , V_27 , V_79 -> V_88 [ V_27 ] ) ;
}
if ( F_25 ( V_89 , V_2 -> V_45 ) ) {
V_20 = F_41 ( V_2 ) ;
if ( V_20 < 0 )
goto exit;
if ( F_25 ( V_90 , V_2 -> V_74 ) ) {
int V_91 = F_43 ( V_2 , V_90 ) + 1 ;
F_57 ( V_2 , V_91 ) ;
} else if ( F_25 ( V_92 , V_2 -> V_74 ) ) {
F_58 ( V_2 , 60 ) ;
}
}
V_6 -> V_22 = V_53 ;
V_20 = V_77 ;
exit:
F_29 ( V_79 ) ;
return V_20 ;
}
static inline T_4 F_59 ( struct V_5 * V_6 , const char T_2 * V_76 , T_3 V_77 )
{
struct V_93 V_94 ;
if ( V_77 < F_60 () )
return - V_42 ;
if ( F_61 ( V_76 , & V_94 ) )
return - V_95 ;
V_93 ( V_6 -> V_2 , V_94 . type , V_94 . V_3 , V_94 . V_4 ) ;
return F_60 () ;
}
static T_4 F_62 ( struct V_65 * V_65 , const char T_2 * V_76 , T_3 V_77 , T_5 * V_96 )
{
struct V_5 * V_6 = V_65 -> V_69 ;
int V_20 ;
V_20 = F_15 ( & V_6 -> V_21 ) ;
if ( V_20 )
return V_20 ;
V_20 = V_6 -> V_22 == V_23 ?
F_59 ( V_6 , V_76 , V_77 ) :
F_48 ( V_6 , V_76 , V_77 ) ;
F_16 ( & V_6 -> V_21 ) ;
return V_20 ;
}
static T_4 F_63 ( struct V_65 * V_65 , char T_2 * V_76 , T_3 V_77 , T_5 * V_96 )
{
struct V_5 * V_6 = V_65 -> V_69 ;
int V_20 = 0 ;
if ( V_6 -> V_22 != V_23 )
return - V_24 ;
if ( V_6 -> V_8 == V_6 -> V_97 && ( V_65 -> V_98 & V_99 ) )
return - V_100 ;
V_20 = F_10 ( V_6 -> V_10 ,
V_6 -> V_8 != V_6 -> V_97 || V_6 -> V_22 != V_23 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_15 ( & V_6 -> V_21 ) ;
if ( V_20 )
return V_20 ;
if ( V_6 -> V_22 != V_23 ) {
V_20 = - V_24 ;
goto V_25;
}
while ( V_6 -> V_8 != V_6 -> V_97 && V_20 + F_60 () <= V_77 ) {
if ( F_64 ( V_76 + V_20 , & V_6 -> V_7 [ V_6 -> V_97 ] ) ) {
V_20 = - V_95 ;
goto V_25;
}
V_6 -> V_97 = ( V_6 -> V_97 + 1 ) % V_9 ;
V_20 += F_60 () ;
}
V_25:
F_16 ( & V_6 -> V_21 ) ;
return V_20 ;
}
static unsigned int F_65 ( struct V_65 * V_65 , T_6 * V_101 )
{
struct V_5 * V_6 = V_65 -> V_69 ;
F_66 ( V_65 , & V_6 -> V_10 , V_101 ) ;
if ( V_6 -> V_8 != V_6 -> V_97 )
return V_102 | V_103 ;
return 0 ;
}
static int F_67 ( struct V_64 * V_64 , struct V_65 * V_65 )
{
struct V_5 * V_6 = V_65 -> V_69 ;
F_26 ( V_6 ) ;
F_29 ( V_6 ) ;
return 0 ;
}
static int F_68 ( char T_2 * V_76 ,
const struct V_104 * V_105 )
{
if ( V_106 ) {
struct V_107 V_108 ;
V_108 . V_109 = V_105 -> V_109 ;
V_108 . V_20 = V_105 -> V_20 ;
memcpy ( & V_108 . V_35 , & V_105 -> V_35 ,
sizeof( struct V_110 ) ) ;
memcpy ( & V_108 . V_36 , & V_105 -> V_36 ,
sizeof( struct V_110 ) ) ;
if ( F_69 ( V_76 , & V_108 ,
sizeof( struct V_107 ) ) )
return - V_95 ;
} else {
if ( F_69 ( V_76 , V_105 ,
sizeof( struct V_104 ) ) )
return - V_95 ;
}
return 0 ;
}
static int F_70 ( const char T_2 * V_76 ,
struct V_104 * V_105 )
{
if ( V_106 ) {
struct V_107 V_108 ;
if ( F_71 ( & V_108 , V_76 ,
sizeof( struct V_107 ) ) )
return - V_95 ;
V_105 -> V_109 = V_108 . V_109 ;
V_105 -> V_20 = V_108 . V_20 ;
memcpy ( & V_105 -> V_35 , & V_108 . V_35 ,
sizeof( struct V_110 ) ) ;
memcpy ( & V_105 -> V_36 , & V_108 . V_36 ,
sizeof( struct V_110 ) ) ;
} else {
if ( F_71 ( V_105 , V_76 ,
sizeof( struct V_104 ) ) )
return - V_95 ;
}
return 0 ;
}
static int F_68 ( char T_2 * V_76 ,
const struct V_104 * V_105 )
{
if ( F_69 ( V_76 , V_105 , sizeof( struct V_104 ) ) )
return - V_95 ;
return 0 ;
}
static int F_70 ( const char T_2 * V_76 ,
struct V_104 * V_105 )
{
if ( F_71 ( V_105 , V_76 , sizeof( struct V_104 ) ) )
return - V_95 ;
return 0 ;
}
static long F_72 ( struct V_65 * V_65 , unsigned int V_111 ,
unsigned long V_112 , void T_2 * V_113 )
{
int V_20 ;
struct V_5 * V_6 = V_65 -> V_69 ;
struct V_104 V_105 ;
struct V_114 V_115 ;
struct V_11 * V_116 ;
char * V_49 ;
V_20 = F_15 ( & V_6 -> V_21 ) ;
if ( V_20 )
return V_20 ;
if ( ! V_6 -> V_2 ) {
V_20 = F_45 ( V_6 ) ;
if ( V_20 )
goto V_25;
}
switch ( V_111 ) {
case V_117 :
V_20 = F_30 ( V_6 ) ;
break;
case V_118 :
F_26 ( V_6 ) ;
break;
case V_119 :
V_20 = F_73 ( V_112 , V_45 , V_120 ) ;
break;
case V_121 :
V_20 = F_73 ( V_112 , V_122 , V_123 ) ;
break;
case V_124 :
V_20 = F_73 ( V_112 , V_125 , V_126 ) ;
break;
case V_127 :
V_20 = F_73 ( V_112 , V_74 , V_128 ) ;
break;
case V_129 :
V_20 = F_73 ( V_112 , V_130 , V_131 ) ;
break;
case V_132 :
V_20 = F_73 ( V_112 , V_133 , V_134 ) ;
break;
case V_135 :
V_20 = F_73 ( V_112 , V_136 , V_137 ) ;
break;
case V_138 :
V_20 = F_73 ( V_112 , V_139 , V_140 ) ;
break;
case V_141 :
V_20 = F_73 ( V_112 , V_142 , V_143 ) ;
break;
case V_144 :
V_20 = F_73 ( V_112 , V_145 , V_146 ) ;
break;
case V_147 :
if ( V_6 -> V_22 == V_23 ) {
V_20 = - V_42 ;
goto V_25;
}
V_49 = F_74 ( V_113 , 1024 ) ;
if ( F_50 ( V_49 ) ) {
V_20 = F_51 ( V_49 ) ;
goto V_25;
}
F_29 ( V_6 -> V_2 -> V_49 ) ;
V_6 -> V_2 -> V_49 = V_49 ;
break;
case V_148 :
V_20 = F_70 ( V_113 , & V_105 ) ;
if ( V_20 )
break;
V_116 = F_8 ( V_6 , V_105 . V_109 ) ;
if ( ! V_116 || V_116 -> V_3 != V_43 || ! V_116 -> V_38 . V_44 . V_35 ) {
V_20 = - V_42 ;
break;
}
V_105 . V_20 = 0 ;
V_105 . V_35 = * V_116 -> V_38 . V_44 . V_35 ;
if ( V_116 -> V_38 . V_44 . V_36 )
V_105 . V_36 = * V_116 -> V_38 . V_44 . V_36 ;
else
memset ( & V_105 . V_36 , 0 , sizeof( struct V_34 ) ) ;
V_20 = F_68 ( V_113 , & V_105 ) ;
break;
case V_149 :
if ( F_71 ( & V_115 , V_113 , sizeof( V_115 ) ) ) {
V_20 = - V_95 ;
break;
}
V_116 = F_8 ( V_6 , V_115 . V_109 ) ;
if ( ! V_116 || V_116 -> V_3 != V_47 ) {
V_20 = - V_42 ;
break;
}
V_115 . V_20 = 0 ;
V_115 . V_33 = V_116 -> V_38 . V_33 ;
if ( F_69 ( V_113 , & V_115 , sizeof( V_115 ) ) ) {
V_20 = - V_95 ;
break;
}
break;
case V_150 :
V_20 = F_70 ( V_113 , & V_105 ) ;
if ( V_20 )
break;
V_116 = F_8 ( V_6 , V_105 . V_109 ) ;
if ( ! V_116 || V_116 -> V_3 != V_43 ||
! V_116 -> V_38 . V_44 . V_35 ) {
V_20 = - V_42 ;
break;
}
V_116 -> V_20 = V_105 . V_20 ;
F_11 ( V_6 , V_116 ) ;
break;
case V_151 :
if ( F_71 ( & V_115 , V_113 , sizeof( V_115 ) ) ) {
V_20 = - V_95 ;
break;
}
V_116 = F_8 ( V_6 , V_115 . V_109 ) ;
if ( ! V_116 || V_116 -> V_3 != V_47 ) {
V_20 = - V_42 ;
break;
}
V_116 -> V_20 = V_115 . V_20 ;
F_11 ( V_6 , V_116 ) ;
break;
default:
V_20 = - V_42 ;
}
V_25:
F_16 ( & V_6 -> V_21 ) ;
return V_20 ;
}
static long F_75 ( struct V_65 * V_65 , unsigned int V_111 , unsigned long V_112 )
{
return F_72 ( V_65 , V_111 , V_112 , ( void T_2 * ) V_112 ) ;
}
static long F_76 ( struct V_65 * V_65 , unsigned int V_111 , unsigned long V_112 )
{
return F_72 ( V_65 , V_111 , V_112 , F_77 ( V_112 ) ) ;
}
static int T_7 F_78 ( void )
{
return F_79 ( & V_152 ) ;
}
static void T_8 F_80 ( void )
{
F_81 ( & V_152 ) ;
}
