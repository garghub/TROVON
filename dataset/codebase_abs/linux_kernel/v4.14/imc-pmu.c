struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 , struct V_1 , V_4 ) ;
}
static T_1 F_3 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
char * V_9 )
{
struct V_4 * V_4 = F_4 ( V_6 ) ;
struct V_1 * V_1 = F_2 ( V_4 , struct V_1 , V_4 ) ;
T_2 * V_10 ;
switch( V_1 -> V_11 ) {
case V_12 :
V_10 = & V_13 ;
break;
case V_14 :
V_10 = & V_15 ;
break;
default:
return 0 ;
}
return F_5 ( true , V_9 , V_10 ) ;
}
static struct V_16 * F_6 ( const char * V_17 , const char * V_18 )
{
struct V_19 * V_8 ;
V_8 = F_7 ( sizeof( * V_8 ) , V_20 ) ;
if ( ! V_8 )
return NULL ;
F_8 ( & V_8 -> V_8 . V_8 ) ;
V_8 -> V_21 = V_18 ;
V_8 -> V_8 . V_8 . V_17 = V_17 ;
V_8 -> V_8 . V_8 . V_22 = 0444 ;
V_8 -> V_8 . V_23 = V_24 ;
return & V_8 -> V_8 . V_8 ;
}
struct V_25 * F_9 ( struct V_26 * V_27 , const char * V_28 ,
const char * V_29 , const char * V_30 , T_3 V_31 )
{
struct V_25 * V_3 ;
const char * V_32 ;
T_3 V_33 ;
V_3 = F_7 ( sizeof( struct V_25 ) , V_20 ) ;
if ( ! V_3 )
return NULL ;
if ( F_10 ( V_27 , L_1 , & V_33 ) )
goto error;
V_3 -> V_34 = V_31 + V_33 ;
if ( F_11 ( V_27 , L_2 , & V_32 ) )
goto error;
V_3 -> V_17 = F_12 ( V_20 , L_3 , V_30 , V_32 ) ;
if ( ! V_3 -> V_17 )
goto error;
if ( F_11 ( V_27 , L_4 , & V_32 ) )
V_32 = V_28 ;
if ( V_32 ) {
V_3 -> V_28 = F_13 ( V_32 , V_20 ) ;
if ( ! V_3 -> V_28 )
goto error;
}
if ( F_11 ( V_27 , L_5 , & V_32 ) )
V_32 = V_29 ;
if ( V_32 ) {
V_3 -> V_29 = F_13 ( V_32 , V_20 ) ;
if ( ! V_3 -> V_29 )
goto error;
}
return V_3 ;
error:
F_14 ( V_3 -> V_29 ) ;
F_14 ( V_3 -> V_28 ) ;
F_14 ( V_3 -> V_17 ) ;
F_14 ( V_3 ) ;
return NULL ;
}
static int F_15 ( struct V_26 * V_35 , struct V_1 * V_4 )
{
struct V_36 * V_37 ;
struct V_16 * * V_38 , * V_39 ;
struct V_26 * V_27 , * V_40 ;
struct V_25 * V_41 ;
T_3 V_42 , V_43 ;
int V_44 = 0 , V_45 = 0 , V_46 ;
const char * V_30 , * V_47 , * V_48 ;
const char * V_49 , * V_50 , * V_51 ;
if ( ! F_10 ( V_35 , L_6 , & V_42 ) )
V_40 = F_16 ( V_42 ) ;
else
return 0 ;
if ( ! V_40 )
return 0 ;
V_46 = F_17 ( V_40 ) ;
if ( F_11 ( V_35 , L_7 , & V_30 ) )
return 0 ;
if ( F_11 ( V_35 , L_4 , & V_47 ) )
V_47 = NULL ;
if ( F_11 ( V_35 , L_5 , & V_48 ) )
V_48 = NULL ;
F_10 ( V_35 , L_1 , & V_43 ) ;
V_4 -> V_52 = F_18 ( V_46 , sizeof( struct V_25 ) , V_20 ) ;
if ( ! V_4 -> V_52 )
return - V_53 ;
V_46 = 0 ;
F_19 (pmu_events, np) {
V_41 = F_9 ( V_27 , V_47 , V_48 , V_30 , V_43 ) ;
if ( V_41 )
V_4 -> V_52 [ V_46 ++ ] = V_41 ;
}
V_37 = F_7 ( sizeof( * V_37 ) , V_20 ) ;
if ( ! V_37 )
return - V_53 ;
V_38 = F_18 ( ( ( V_46 * 3 ) + 1 ) , sizeof( struct V_16 * ) , V_20 ) ;
if ( ! V_38 ) {
F_14 ( V_37 ) ;
F_14 ( V_4 -> V_52 ) ;
return - V_53 ;
}
V_37 -> V_17 = L_6 ;
V_37 -> V_38 = V_38 ;
do {
V_49 = F_12 ( V_20 , L_8 , V_4 -> V_52 [ V_44 ] -> V_34 ) ;
V_39 = F_6 ( V_4 -> V_52 [ V_44 ] -> V_17 , V_49 ) ;
if ( ! V_39 )
continue;
V_38 [ V_45 ++ ] = V_39 ;
if ( V_4 -> V_52 [ V_44 ] -> V_28 ) {
V_50 = F_12 ( V_20 , L_9 , V_4 -> V_52 [ V_44 ] -> V_17 ) ;
V_39 = F_6 ( V_50 , V_4 -> V_52 [ V_44 ] -> V_28 ) ;
if ( ! V_39 )
continue;
V_38 [ V_45 ++ ] = V_39 ;
}
if ( V_4 -> V_52 [ V_44 ] -> V_29 ) {
V_51 = F_12 ( V_20 , L_10 , V_4 -> V_52 [ V_44 ] -> V_17 ) ;
V_39 = F_6 ( V_51 , V_4 -> V_52 [ V_44 ] -> V_29 ) ;
if ( ! V_39 )
continue;
V_38 [ V_45 ++ ] = V_39 ;
}
} while ( ++ V_44 < V_46 );
V_4 -> V_54 [ V_55 ] = V_37 ;
F_14 ( V_4 -> V_52 ) ;
return 0 ;
}
static struct V_56 * F_20 ( int V_57 )
{
return F_21 ( V_58 , V_57 ) ;
}
static void F_22 ( int V_59 , int V_60 )
{
struct V_1 * * V_61 = V_62 ;
int V_44 ;
if ( V_59 < 0 || V_60 < 0 )
return;
for ( V_44 = 0 ; * V_61 && V_44 < V_63 ; V_44 ++ , V_61 ++ )
F_23 ( & ( * V_61 ) -> V_4 , V_59 , V_60 ) ;
}
static int F_24 ( unsigned int V_57 )
{
int V_64 , V_65 = - 1 ;
const struct V_66 * V_67 ;
struct V_56 * V_68 ;
if ( ! F_25 ( V_57 , & V_13 ) )
return 0 ;
V_64 = F_26 ( V_57 ) ;
V_67 = F_27 ( V_64 ) ;
V_65 = F_28 ( V_67 , V_57 ) ;
if ( V_65 >= 0 && V_65 < V_69 ) {
F_29 ( V_65 , & V_13 ) ;
F_22 ( V_57 , V_65 ) ;
} else {
F_30 ( V_70 ,
F_31 ( V_57 ) ) ;
V_68 = F_20 ( V_57 ) ;
if ( ! V_68 )
return - V_71 ;
V_68 -> V_72 = 0 ;
}
return 0 ;
}
static int F_32 ( unsigned int V_57 )
{
const struct V_66 * V_67 ;
static struct V_66 V_73 ;
int V_74 ;
V_67 = F_27 ( F_26 ( V_57 ) ) ;
if ( F_33 ( & V_73 , V_67 , & V_13 ) )
return 0 ;
V_74 = F_30 ( V_70 ,
F_31 ( V_57 ) ) ;
if ( V_74 )
return V_74 ;
F_29 ( V_57 , & V_13 ) ;
return 0 ;
}
static int F_34 ( void )
{
return F_35 ( V_75 ,
L_11 ,
F_32 ,
F_24 ) ;
}
static void F_36 ( struct V_2 * V_3 )
{
int V_76 , V_77 ;
struct V_56 * V_68 ;
if ( V_3 -> V_57 < 0 )
return;
V_77 = F_26 ( V_3 -> V_57 ) ;
V_68 = F_20 ( V_3 -> V_57 ) ;
if ( ! V_68 )
return;
F_37 ( & V_68 -> V_78 ) ;
if ( V_68 -> V_72 == 0 ) {
F_38 ( & V_68 -> V_78 ) ;
return;
}
V_68 -> V_72 -- ;
if ( V_68 -> V_72 == 0 ) {
V_76 = F_30 ( V_70 ,
F_31 ( V_3 -> V_57 ) ) ;
if ( V_76 ) {
F_38 ( & V_68 -> V_78 ) ;
F_39 ( L_12 , V_77 ) ;
return;
}
} else if ( V_68 -> V_72 < 0 ) {
F_40 ( 1 , L_13 ) ;
V_68 -> V_72 = 0 ;
}
F_38 ( & V_68 -> V_78 ) ;
}
static int F_41 ( struct V_2 * V_3 )
{
int V_79 , V_76 , V_77 ;
T_3 V_80 , V_81 = V_3 -> V_8 . V_81 ;
struct V_82 * V_83 ;
struct V_1 * V_4 ;
struct V_56 * V_68 ;
bool V_84 = false ;
if ( V_3 -> V_8 . type != V_3 -> V_4 -> type )
return - V_85 ;
if ( V_3 -> V_86 . V_87 )
return - V_71 ;
if ( V_3 -> V_8 . V_88 ||
V_3 -> V_8 . V_89 ||
V_3 -> V_8 . V_90 ||
V_3 -> V_8 . V_91 ||
V_3 -> V_8 . V_92 ||
V_3 -> V_8 . V_93 )
return - V_71 ;
if ( V_3 -> V_57 < 0 )
return - V_71 ;
V_4 = F_1 ( V_3 ) ;
if ( ( V_81 & V_94 ) > V_4 -> V_95 )
return - V_71 ;
V_79 = F_42 ( V_3 -> V_57 ) ;
V_83 = V_4 -> V_96 ;
do {
if ( V_83 -> V_97 == V_79 ) {
V_84 = true ;
break;
}
V_83 ++ ;
} while ( V_83 );
if ( ! V_84 )
return - V_98 ;
V_80 = V_81 & V_94 ;
V_3 -> V_86 . V_99 = ( V_100 ) V_83 -> V_101 + V_80 ;
V_77 = F_26 ( V_3 -> V_57 ) ;
V_68 = F_20 ( V_3 -> V_57 ) ;
if ( ! V_68 )
return - V_71 ;
F_37 ( & V_68 -> V_78 ) ;
if ( V_68 -> V_72 == 0 ) {
V_76 = F_43 ( V_70 ,
F_31 ( V_3 -> V_57 ) ) ;
if ( V_76 ) {
F_38 ( & V_68 -> V_78 ) ;
F_39 ( L_14 ,
V_77 ) ;
return V_76 ;
}
}
++ V_68 -> V_72 ;
F_38 ( & V_68 -> V_78 ) ;
V_3 -> V_102 = F_36 ;
return 0 ;
}
static int F_44 ( int V_57 , int V_103 )
{
int V_104 , V_76 = 0 , V_105 = ( V_57 / V_106 ) ;
struct V_82 * V_96 ;
V_104 = F_42 ( V_57 ) ;
V_96 = & V_107 -> V_96 [ V_105 ] ;
V_96 -> V_97 = V_105 ;
V_96 -> V_101 = F_45 ( F_46 ( V_104 ,
V_20 | V_108 | V_109 |
V_110 , F_47 ( V_103 ) ) ) ;
if ( ! V_96 -> V_101 )
return - V_53 ;
V_111 [ V_105 ] . V_97 = V_105 ;
F_48 ( & V_111 [ V_105 ] . V_78 ) ;
V_76 = F_49 ( V_112 ,
F_50 ( ( void * ) V_96 -> V_101 ) ,
F_31 ( V_57 ) ) ;
if ( V_76 ) {
F_51 ( ( V_100 ) V_96 -> V_101 , F_47 ( V_103 ) ) ;
V_96 -> V_101 = NULL ;
}
return V_76 ;
}
static bool F_52 ( int V_57 )
{
struct V_82 * V_96 ;
int V_105 = ( V_57 / V_106 ) ;
V_96 = & V_107 -> V_96 [ V_105 ] ;
if ( ! V_96 -> V_101 )
return false ;
return true ;
}
static int F_53 ( unsigned int V_57 )
{
const struct V_66 * V_67 ;
static struct V_66 V_73 ;
int V_113 = 0 ;
V_67 = F_54 ( V_57 ) ;
if ( F_33 ( & V_73 , V_67 , & V_15 ) )
return 0 ;
if ( ! F_52 ( V_57 ) ) {
V_113 = F_44 ( V_57 , V_107 -> V_95 ) ;
if ( V_113 ) {
F_55 ( L_15 , V_57 ) ;
return V_113 ;
}
}
F_29 ( V_57 , & V_15 ) ;
return 0 ;
}
static int F_56 ( unsigned int V_57 )
{
unsigned int V_114 , V_105 ;
struct V_56 * V_68 ;
if ( ! F_25 ( V_57 , & V_15 ) )
return 0 ;
if ( ! V_107 -> V_4 . V_115 )
return 0 ;
V_114 = F_28 ( F_54 ( V_57 ) , V_57 ) ;
if ( V_114 >= 0 && V_114 < V_69 ) {
F_29 ( V_114 , & V_15 ) ;
F_23 ( & V_107 -> V_4 , V_57 , V_114 ) ;
} else {
F_30 ( V_112 ,
F_31 ( V_57 ) ) ;
V_105 = V_57 / V_106 ;
V_68 = & V_111 [ V_105 ] ;
if ( ! V_68 )
return - V_71 ;
V_68 -> V_72 = 0 ;
}
return 0 ;
}
static int F_57 ( void )
{
return F_35 ( V_116 ,
L_16 ,
F_53 ,
F_56 ) ;
}
static void F_58 ( struct V_2 * V_3 )
{
int V_76 , V_105 ;
struct V_56 * V_68 ;
if ( V_3 -> V_57 < 0 )
return;
V_105 = V_3 -> V_57 / V_106 ;
V_68 = & V_111 [ V_105 ] ;
if ( ! V_68 )
return;
F_37 ( & V_68 -> V_78 ) ;
if ( V_68 -> V_72 == 0 ) {
F_38 ( & V_68 -> V_78 ) ;
return;
}
V_68 -> V_72 -- ;
if ( V_68 -> V_72 == 0 ) {
V_76 = F_30 ( V_112 ,
F_31 ( V_3 -> V_57 ) ) ;
if ( V_76 ) {
F_38 ( & V_68 -> V_78 ) ;
F_39 ( L_17 , V_105 ) ;
return;
}
} else if ( V_68 -> V_72 < 0 ) {
F_40 ( 1 , L_18 ) ;
V_68 -> V_72 = 0 ;
}
F_38 ( & V_68 -> V_78 ) ;
}
static int F_59 ( struct V_2 * V_3 )
{
int V_105 , V_76 ;
V_100 V_81 = V_3 -> V_8 . V_81 ;
struct V_82 * V_117 ;
struct V_1 * V_4 ;
struct V_56 * V_68 ;
if ( V_3 -> V_8 . type != V_3 -> V_4 -> type )
return - V_85 ;
if ( V_3 -> V_86 . V_87 )
return - V_71 ;
if ( V_3 -> V_8 . V_88 ||
V_3 -> V_8 . V_89 ||
V_3 -> V_8 . V_90 ||
V_3 -> V_8 . V_91 ||
V_3 -> V_8 . V_92 ||
V_3 -> V_8 . V_93 )
return - V_71 ;
if ( V_3 -> V_57 < 0 )
return - V_71 ;
V_3 -> V_86 . V_118 = - 1 ;
V_4 = F_1 ( V_3 ) ;
if ( ( ( V_81 & V_94 ) > V_4 -> V_95 ) )
return - V_71 ;
if ( ! F_52 ( V_3 -> V_57 ) )
return - V_98 ;
V_105 = V_3 -> V_57 / V_106 ;
V_117 = & V_107 -> V_96 [ V_105 ] ;
if ( ( ! V_117 -> V_101 ) )
return - V_98 ;
V_68 = & V_111 [ V_105 ] ;
if ( ! V_68 )
return - V_71 ;
F_37 ( & V_68 -> V_78 ) ;
if ( V_68 -> V_72 == 0 ) {
V_76 = F_43 ( V_112 ,
F_31 ( V_3 -> V_57 ) ) ;
if ( V_76 ) {
F_38 ( & V_68 -> V_78 ) ;
F_39 ( L_19 ,
V_105 ) ;
return V_76 ;
}
}
++ V_68 -> V_72 ;
F_38 ( & V_68 -> V_78 ) ;
V_3 -> V_86 . V_99 = ( V_100 ) V_117 -> V_101 + ( V_81 & V_94 ) ;
V_3 -> V_102 = F_58 ;
return 0 ;
}
static int F_60 ( int V_119 , int V_103 )
{
V_100 V_120 , * V_121 = F_21 ( V_122 , V_119 ) ;
int V_104 = F_42 ( V_119 ) ;
if ( ! V_121 ) {
V_121 = F_45 ( F_46 ( V_104 ,
V_20 | V_108 | V_109 |
V_110 , F_47 ( V_103 ) ) ) ;
if ( ! V_121 )
return - V_53 ;
F_21 ( V_122 , V_119 ) = V_121 ;
}
V_120 = ( ( V_100 ) V_121 & V_123 ) | V_124 ;
F_61 ( V_125 , V_120 ) ;
return 0 ;
}
static int F_62 ( unsigned int V_57 )
{
return F_60 ( V_57 , V_126 ) ;
}
static int F_63 ( unsigned int V_57 )
{
F_61 ( V_125 , 0 ) ;
return 0 ;
}
static int F_64 ( void )
{
return F_35 ( V_127 ,
L_20 ,
F_62 ,
F_63 ) ;
}
void F_65 ( struct V_128 * V_129 ,
bool V_130 )
{
int V_105 ;
struct V_56 * V_68 ;
if ( ! F_52 ( F_66 () ) )
return;
V_105 = F_66 () / V_106 ;
V_68 = & V_111 [ V_105 ] ;
if ( ! V_68 )
return;
if ( V_130 ) {
F_37 ( & V_68 -> V_78 ) ;
if ( V_68 -> V_72 == 0 ) {
if ( F_43 ( V_112 ,
F_31 ( F_66 () ) ) ) {
F_38 ( & V_68 -> V_78 ) ;
F_39 ( L_21 , V_105 ) ;
return;
}
}
++ V_68 -> V_72 ;
F_38 ( & V_68 -> V_78 ) ;
} else {
F_37 ( & V_68 -> V_78 ) ;
V_68 -> V_72 -- ;
if ( V_68 -> V_72 == 0 ) {
if ( F_30 ( V_112 ,
F_31 ( F_66 () ) ) ) {
F_38 ( & V_68 -> V_78 ) ;
F_39 ( L_22 , V_105 ) ;
return;
}
} else if ( V_68 -> V_72 < 0 ) {
V_68 -> V_72 = 0 ;
}
F_38 ( & V_68 -> V_78 ) ;
}
return;
}
static int F_67 ( struct V_2 * V_3 )
{
T_3 V_81 = V_3 -> V_8 . V_81 ;
struct V_131 * V_65 ;
struct V_1 * V_4 ;
if ( V_3 -> V_8 . type != V_3 -> V_4 -> type )
return - V_85 ;
if ( V_3 -> V_86 . V_87 )
return - V_71 ;
V_3 -> V_86 . V_118 = - 1 ;
V_4 = F_1 ( V_3 ) ;
if ( ( ( V_81 & V_94 ) > V_4 -> V_95 ) )
return - V_71 ;
V_65 = V_3 -> V_86 . V_65 ;
if ( ! V_65 )
return - V_71 ;
V_3 -> V_4 -> V_132 = V_133 ;
return 0 ;
}
static bool F_68 ( struct V_2 * V_3 )
{
if ( ! strncmp ( V_3 -> V_4 -> V_17 , L_23 , strlen ( L_23 ) ) )
return true ;
return false ;
}
static V_100 * F_69 ( struct V_2 * V_3 )
{
V_100 V_134 ;
if ( F_68 ( V_3 ) ) {
V_134 = ( V_100 ) F_21 ( V_122 , F_66 () ) ;
return ( V_100 * ) ( V_134 + ( V_3 -> V_8 . V_81 & V_94 ) ) ;
}
return ( V_100 * ) V_3 -> V_86 . V_99 ;
}
static void F_70 ( struct V_4 * V_4 ,
unsigned int V_135 )
{
if ( V_135 & ~ V_136 )
return;
F_71 ( V_4 ) ;
}
static void F_72 ( struct V_4 * V_4 )
{
F_73 ( V_4 ) ;
}
static int F_74 ( struct V_4 * V_4 )
{
F_73 ( V_4 ) ;
return 0 ;
}
static V_100 F_75 ( struct V_2 * V_3 )
{
V_100 * V_134 , V_137 ;
V_134 = F_69 ( V_3 ) ;
V_137 = F_76 ( F_77 ( * V_134 ) ) ;
F_78 ( & V_3 -> V_86 . V_138 , V_137 ) ;
return V_137 ;
}
static void F_79 ( struct V_2 * V_3 )
{
V_100 V_139 , V_140 , V_141 ;
V_139 = F_80 ( & V_3 -> V_86 . V_138 ) ;
V_140 = F_75 ( V_3 ) ;
V_141 = V_140 - V_139 ;
F_81 ( V_141 , & V_3 -> V_142 ) ;
}
static void F_82 ( struct V_2 * V_3 , int V_143 )
{
F_75 ( V_3 ) ;
}
static void F_83 ( struct V_2 * V_3 , int V_143 )
{
F_79 ( V_3 ) ;
}
static int F_84 ( struct V_2 * V_3 , int V_143 )
{
if ( V_143 & V_144 )
F_82 ( V_3 , V_143 ) ;
return 0 ;
}
static int F_85 ( struct V_2 * V_3 , int V_143 )
{
if ( V_143 & V_144 )
F_82 ( V_3 , V_143 ) ;
F_86 ( V_3 -> V_129 -> V_4 ) ;
return 0 ;
}
static void F_87 ( struct V_2 * V_3 , int V_143 )
{
F_79 ( V_3 ) ;
F_88 ( V_3 -> V_129 -> V_4 ) ;
}
static int F_89 ( struct V_1 * V_4 )
{
V_4 -> V_4 . V_132 = V_145 ;
V_4 -> V_4 . V_146 = F_84 ;
V_4 -> V_4 . V_147 = F_83 ;
V_4 -> V_4 . V_148 = F_82 ;
V_4 -> V_4 . V_149 = F_83 ;
V_4 -> V_4 . V_150 = F_79 ;
V_4 -> V_4 . V_54 = V_4 -> V_54 ;
V_4 -> V_54 [ V_151 ] = & V_152 ;
switch ( V_4 -> V_11 ) {
case V_12 :
V_4 -> V_4 . V_115 = F_41 ;
V_4 -> V_54 [ V_153 ] = & V_154 ;
break;
case V_14 :
V_4 -> V_4 . V_115 = F_59 ;
V_4 -> V_54 [ V_153 ] = & V_154 ;
break;
case V_155 :
V_4 -> V_4 . V_115 = F_67 ;
V_4 -> V_4 . V_156 = F_65 ;
V_4 -> V_4 . V_146 = F_85 ;
V_4 -> V_4 . V_147 = F_87 ;
V_4 -> V_4 . V_157 = F_70 ;
V_4 -> V_4 . V_158 = F_72 ;
V_4 -> V_4 . V_159 = F_74 ;
break;
default:
break;
}
return 0 ;
}
static int F_90 ( void )
{
int V_64 , V_44 , V_57 ;
V_160 = F_18 ( F_91 () , sizeof( * V_160 ) ,
V_20 ) ;
if ( ! V_160 )
return - V_53 ;
V_44 = 0 ;
F_92 (nid) {
F_48 ( & V_160 [ V_44 ] . V_78 ) ;
V_160 [ V_44 ++ ] . V_97 = V_64 ;
}
F_93 (cpu) {
V_64 = F_26 ( V_57 ) ;
for ( V_44 = 0 ; V_44 < F_91 () ; V_44 ++ ) {
if ( V_160 [ V_44 ] . V_97 == V_64 ) {
F_21 ( V_58 , V_57 ) = & V_160 [ V_44 ] ;
break;
}
}
}
return 0 ;
}
static void F_94 ( void )
{
int V_44 , V_161 = F_95 ( F_96 () , V_106 ) ;
struct V_82 * V_162 = V_107 -> V_96 ;
int V_103 = V_107 -> V_95 ;
for ( V_44 = 0 ; V_44 < V_161 ; V_44 ++ ) {
if ( V_162 [ V_44 ] . V_101 )
F_51 ( ( V_100 ) V_162 -> V_101 , F_47 ( V_103 ) ) ;
}
F_14 ( V_162 ) ;
F_14 ( V_111 ) ;
}
static void F_97 ( void * V_163 )
{
F_61 ( V_125 , 0 ) ;
}
void F_98 ( void )
{
F_99 ( F_97 , NULL , 1 ) ;
}
static void F_100 ( void )
{
int V_44 , V_164 = F_47 ( V_126 ) ;
F_101 (i) {
if ( F_21 ( V_122 , V_44 ) )
F_51 ( ( V_100 ) F_21 ( V_122 , V_44 ) , V_164 ) ;
}
}
static void F_102 ( struct V_1 * V_165 )
{
if ( V_165 -> V_11 == V_12 ) {
F_37 ( & V_166 ) ;
if ( V_167 == 1 ) {
F_103 ( V_75 ) ;
F_14 ( V_160 ) ;
}
if ( V_167 > 0 )
V_167 -- ;
F_38 ( & V_166 ) ;
}
if ( V_165 -> V_11 == V_14 ) {
F_103 ( V_116 ) ;
F_94 () ;
}
if ( V_165 -> V_11 == V_155 ) {
F_103 ( V_127 ) ;
F_100 () ;
}
if ( V_165 -> V_54 [ V_55 ] )
F_14 ( V_165 -> V_54 [ V_55 ] -> V_38 ) ;
F_14 ( V_165 -> V_54 [ V_55 ] ) ;
F_14 ( V_165 ) ;
return;
}
static int F_104 ( struct V_1 * V_165 , struct V_26 * V_168 ,
int V_169 )
{
const char * V_32 ;
int V_161 , V_57 , V_74 ;
if ( F_11 ( V_168 , L_24 , & V_32 ) )
return - V_98 ;
switch ( V_165 -> V_11 ) {
case V_12 :
V_165 -> V_4 . V_17 = F_12 ( V_20 , L_25 , L_26 , V_32 ) ;
if ( ! V_165 -> V_4 . V_17 )
return - V_53 ;
V_62 [ V_169 ] = V_165 ;
break;
case V_14 :
V_165 -> V_4 . V_17 = F_12 ( V_20 , L_3 , V_32 , L_27 ) ;
if ( ! V_165 -> V_4 . V_17 )
return - V_53 ;
V_161 = F_95 ( F_96 () , V_106 ) ;
V_165 -> V_96 = F_18 ( V_161 , sizeof( struct V_82 ) ,
V_20 ) ;
if ( ! V_165 -> V_96 )
return - V_53 ;
V_111 = F_18 ( V_161 , sizeof( struct V_56 ) ,
V_20 ) ;
if ( ! V_111 )
return - V_53 ;
V_107 = V_165 ;
break;
case V_155 :
V_165 -> V_4 . V_17 = F_12 ( V_20 , L_3 , V_32 , L_27 ) ;
if ( ! V_165 -> V_4 . V_17 )
return - V_53 ;
V_126 = V_165 -> V_95 ;
F_101 (cpu) {
V_74 = F_60 ( V_57 , V_165 -> V_95 ) ;
if ( V_74 )
return V_74 ;
}
V_170 = V_165 ;
break;
default:
return - V_71 ;
}
return 0 ;
}
int F_105 ( struct V_26 * V_168 , struct V_1 * V_165 , int V_171 )
{
int V_113 ;
V_113 = F_104 ( V_165 , V_168 , V_171 ) ;
if ( V_113 )
goto V_172;
switch ( V_165 -> V_11 ) {
case V_12 :
F_37 ( & V_166 ) ;
if ( V_167 == 0 ) {
V_113 = F_90 () ;
if ( V_113 ) {
F_38 ( & V_166 ) ;
goto V_172;
}
V_113 = F_34 () ;
if ( V_113 ) {
F_38 ( & V_166 ) ;
goto V_172;
}
}
V_167 ++ ;
F_38 ( & V_166 ) ;
break;
case V_14 :
V_113 = F_57 () ;
if ( V_113 ) {
F_94 () ;
return V_113 ;
}
break;
case V_155 :
V_113 = F_64 () ;
if ( V_113 ) {
F_100 () ;
return V_113 ;
}
break;
default:
return - 1 ;
}
V_113 = F_15 ( V_168 , V_165 ) ;
if ( V_113 )
goto V_172;
V_113 = F_89 ( V_165 ) ;
if ( V_113 )
goto V_172;
V_113 = F_106 ( & V_165 -> V_4 , V_165 -> V_4 . V_17 , - 1 ) ;
if ( V_113 )
goto V_172;
F_55 ( L_28 ,
V_165 -> V_4 . V_17 ) ;
return 0 ;
V_172:
F_102 ( V_165 ) ;
return V_113 ;
}
