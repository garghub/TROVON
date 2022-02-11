int F_1 ( void )
{
return V_1 ;
}
static bool F_2 ( struct V_2 * V_3 ,
struct V_2 * * V_4 ,
struct V_2 * * V_5 ,
struct V_2 * * V_6 ,
struct V_2 * * V_7 )
{
switch ( F_3 ( V_3 ) ) {
case V_8 :
if ( F_4 ( V_3 ) ) {
if ( V_4 && ! * V_4 ) {
* V_4 = V_3 ;
break;
}
} else {
if ( V_5 && ! * V_5 ) {
* V_5 = V_3 ;
break;
}
}
return false ;
case V_9 :
if ( F_4 ( V_3 ) ) {
if ( V_6 && ! * V_6 ) {
* V_6 = V_3 ;
break;
}
} else {
if ( V_7 && ! * V_7 ) {
* V_7 = V_3 ;
break;
}
}
return false ;
default:
return false ;
}
return ( ! V_4 || * V_4 ) && ( ! V_5 || * V_5 ) &&
( ! V_6 || * V_6 ) && ( ! V_7 || * V_7 ) ;
}
int F_5 ( struct V_10 * V_11 ,
struct V_2 * * V_4 ,
struct V_2 * * V_5 ,
struct V_2 * * V_6 ,
struct V_2 * * V_7 )
{
struct V_2 * V_3 ;
int V_12 ;
if ( V_4 )
* V_4 = NULL ;
if ( V_5 )
* V_5 = NULL ;
if ( V_6 )
* V_6 = NULL ;
if ( V_7 )
* V_7 = NULL ;
for ( V_12 = 0 ; V_12 < V_11 -> V_13 . V_14 ; ++ V_12 ) {
V_3 = & V_11 -> V_15 [ V_12 ] . V_13 ;
if ( F_2 ( V_3 , V_4 , V_5 , V_6 , V_7 ) )
return 0 ;
}
return - V_16 ;
}
int F_6 ( struct V_10 * V_11 ,
struct V_2 * * V_4 ,
struct V_2 * * V_5 ,
struct V_2 * * V_6 ,
struct V_2 * * V_7 )
{
struct V_2 * V_3 ;
int V_12 ;
if ( V_4 )
* V_4 = NULL ;
if ( V_5 )
* V_5 = NULL ;
if ( V_6 )
* V_6 = NULL ;
if ( V_7 )
* V_7 = NULL ;
for ( V_12 = V_11 -> V_13 . V_14 - 1 ; V_12 >= 0 ; -- V_12 ) {
V_3 = & V_11 -> V_15 [ V_12 ] . V_13 ;
if ( F_2 ( V_3 , V_4 , V_5 , V_6 , V_7 ) )
return 0 ;
}
return - V_16 ;
}
struct V_10 * F_7 (
struct V_17 * V_18 ,
unsigned int V_19 ,
unsigned int V_20 )
{
struct V_21 * V_22 = NULL ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_18 -> V_13 . V_23 ; V_12 ++ ) {
if ( V_18 -> V_22 [ V_12 ] -> V_24 [ 0 ] . V_13 . V_25
== V_19 ) {
V_22 = V_18 -> V_22 [ V_12 ] ;
break;
}
}
if ( ! V_22 )
return NULL ;
for ( V_12 = 0 ; V_12 < V_22 -> V_26 ; V_12 ++ )
if ( V_22 -> V_24 [ V_12 ] . V_13 . V_27 == V_20 )
return & V_22 -> V_24 [ V_12 ] ;
F_8 ( V_28 L_1
L_2 , V_20 , V_19 ,
V_18 -> V_13 . V_29 ) ;
return NULL ;
}
struct V_30 * F_9 ( const struct V_31 * V_32 ,
unsigned V_33 )
{
struct V_17 * V_18 = V_32 -> V_34 ;
int V_12 ;
if ( ! V_18 )
return NULL ;
for ( V_12 = 0 ; V_12 < V_18 -> V_13 . V_23 ; V_12 ++ )
if ( V_18 -> V_35 [ V_12 ] -> V_24 [ 0 ]
. V_13 . V_25 == V_33 )
return V_18 -> V_35 [ V_12 ] ;
return NULL ;
}
struct V_10 * F_10 (
const struct V_30 * V_36 ,
unsigned int V_37 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_36 -> V_26 ; V_12 ++ ) {
if ( V_36 -> V_24 [ V_12 ] . V_13 . V_27 == V_37 )
return & V_36 -> V_24 [ V_12 ] ;
}
return NULL ;
}
static int F_11 ( struct V_38 * V_32 , void * V_39 )
{
struct V_40 * V_41 = V_39 ;
struct V_30 * V_36 ;
if ( ! F_12 ( V_32 ) )
return 0 ;
if ( V_32 -> V_42 != V_41 -> V_43 )
return 0 ;
V_36 = F_13 ( V_32 ) ;
return V_36 -> V_44 == V_41 -> V_44 ;
}
struct V_30 * F_14 ( struct V_45 * V_43 , int V_44 )
{
struct V_40 V_46 ;
struct V_38 * V_32 ;
V_46 . V_44 = V_44 ;
V_46 . V_43 = & V_43 -> V_47 . V_42 ;
V_32 = F_15 ( & V_48 , NULL , & V_46 , F_11 ) ;
F_16 ( V_32 ) ;
return V_32 ? F_13 ( V_32 ) : NULL ;
}
static int F_17 ( struct V_38 * V_32 , void * V_39 )
{
struct V_49 * V_41 = (struct V_49 * ) V_39 ;
if ( ! F_18 ( V_32 ) )
return 0 ;
return V_41 -> V_50 ( F_19 ( V_32 ) , V_41 -> V_39 ) ;
}
int F_20 ( void * V_39 , int (* V_50)( struct V_31 * , void * ) )
{
struct V_49 V_41 = { V_39 , V_50 } ;
return F_21 ( & V_48 , NULL , & V_41 , F_17 ) ;
}
static void F_22 ( struct V_38 * V_32 )
{
struct V_31 * V_51 ;
struct V_52 * V_53 ;
V_51 = F_19 ( V_32 ) ;
V_53 = F_23 ( V_51 -> V_54 ) ;
F_24 ( V_51 ) ;
F_25 ( V_51 ) ;
F_26 ( V_53 ) ;
F_27 ( V_51 -> V_55 ) ;
F_27 ( V_51 -> V_56 ) ;
F_27 ( V_51 -> V_57 ) ;
F_27 ( V_51 ) ;
}
static int F_28 ( struct V_38 * V_32 , struct V_58 * V_59 )
{
struct V_31 * V_60 ;
V_60 = F_19 ( V_32 ) ;
if ( F_29 ( V_59 , L_3 , V_60 -> V_54 -> V_61 ) )
return - V_62 ;
if ( F_29 ( V_59 , L_4 , V_60 -> V_63 ) )
return - V_62 ;
return 0 ;
}
static int F_30 ( struct V_38 * V_32 )
{
return 0 ;
}
static void F_31 ( struct V_38 * V_32 )
{
F_32 ( V_32 ) ;
}
static int F_33 ( struct V_38 * V_32 )
{
return F_34 ( V_32 , V_64 ) ;
}
static int F_35 ( struct V_38 * V_32 )
{
return F_36 ( V_32 , V_65 ) ;
}
static int F_37 ( struct V_38 * V_32 )
{
return F_34 ( V_32 , V_66 ) ;
}
static int F_38 ( struct V_38 * V_32 )
{
return F_36 ( V_32 , V_67 ) ;
}
static int F_39 ( struct V_38 * V_32 )
{
return F_34 ( V_32 , V_68 ) ;
}
static int F_40 ( struct V_38 * V_32 )
{
return F_36 ( V_32 , V_69 ) ;
}
static char * F_41 ( struct V_38 * V_32 ,
T_1 * V_70 , T_2 * V_71 , T_3 * V_72 )
{
struct V_31 * V_60 ;
V_60 = F_19 ( V_32 ) ;
return F_42 ( V_73 , L_5 ,
V_60 -> V_54 -> V_61 , V_60 -> V_63 ) ;
}
static unsigned F_43 ( struct V_74 * V_54 )
{
struct V_52 * V_53 = F_23 ( V_54 ) ;
return V_53 -> V_75 ;
}
struct V_31 * F_44 ( struct V_31 * V_76 ,
struct V_74 * V_54 , unsigned V_77 )
{
struct V_31 * V_32 ;
struct V_52 * V_52 = F_23 ( V_54 ) ;
unsigned V_78 = 0 ;
unsigned V_79 = V_77 ;
V_32 = F_45 ( sizeof( * V_32 ) , V_73 ) ;
if ( ! V_32 )
return NULL ;
if ( ! F_46 ( V_52 ) ) {
F_27 ( V_32 ) ;
return NULL ;
}
if ( V_52 -> V_42 -> V_80 && V_76 &&
! V_52 -> V_42 -> V_80 ( V_52 , V_32 ) ) {
F_26 ( F_23 ( V_54 ) ) ;
F_27 ( V_32 ) ;
return NULL ;
}
F_47 ( & V_32 -> V_32 ) ;
V_32 -> V_32 . V_54 = & V_48 ;
V_32 -> V_32 . type = & V_81 ;
V_32 -> V_32 . V_82 = V_83 ;
V_32 -> V_32 . V_84 = V_54 -> V_85 -> V_84 ;
V_32 -> V_32 . V_86 = V_54 -> V_85 -> V_86 ;
F_48 ( & V_32 -> V_32 , F_49 ( V_54 -> V_85 ) ) ;
V_32 -> V_87 = V_88 ;
V_32 -> V_89 = 1 ;
F_50 ( & V_32 -> V_90 , 0 ) ;
F_51 ( & V_32 -> V_91 . V_92 ) ;
V_32 -> V_91 . V_13 . V_93 = V_94 ;
V_32 -> V_91 . V_13 . V_95 = V_96 ;
F_52 ( V_32 , & V_32 -> V_91 , false ) ;
V_32 -> V_97 = 1 ;
if ( F_53 ( ! V_76 ) ) {
V_32 -> V_98 [ 0 ] = '0' ;
V_32 -> V_99 = 0 ;
V_32 -> V_32 . V_76 = V_54 -> V_100 ;
F_54 ( & V_32 -> V_32 , L_6 , V_54 -> V_61 ) ;
V_78 = 1 ;
} else {
if ( V_76 -> V_98 [ 0 ] == '0' ) {
snprintf ( V_32 -> V_98 , sizeof V_32 -> V_98 ,
L_7 , V_77 ) ;
V_32 -> V_99 = 0 ;
} else {
snprintf ( V_32 -> V_98 , sizeof V_32 -> V_98 ,
L_8 , V_76 -> V_98 , V_77 ) ;
if ( V_77 < 15 )
V_32 -> V_99 = V_76 -> V_99 +
( V_77 << ( ( V_76 -> V_101 - 1 ) * 4 ) ) ;
else
V_32 -> V_99 = V_76 -> V_99 +
( 15 << ( ( V_76 -> V_101 - 1 ) * 4 ) ) ;
}
V_32 -> V_32 . V_76 = & V_76 -> V_32 ;
F_54 ( & V_32 -> V_32 , L_9 , V_54 -> V_61 , V_32 -> V_98 ) ;
if ( ! V_76 -> V_76 ) {
V_79 = F_55 ( V_52 ,
V_77 ) ;
}
V_32 -> V_32 . V_102 = F_56 ( V_76 -> V_32 . V_102 ,
V_79 ) ;
}
V_32 -> V_103 = V_77 ;
V_32 -> V_54 = V_54 ;
V_32 -> V_76 = V_76 ;
F_51 ( & V_32 -> V_104 ) ;
#ifdef F_57
F_58 ( & V_32 -> V_32 ,
V_105 * 1000 ) ;
V_32 -> V_106 = V_107 ;
V_32 -> V_108 = - V_107 ;
#endif
if ( V_78 )
V_32 -> V_109 = 1 ;
else {
V_32 -> V_109 = ! ! F_59 ( V_52 ) ;
V_32 -> V_110 = F_43 ( V_54 ) ? 1 : 0 ;
}
return V_32 ;
}
struct V_31 * F_60 ( struct V_31 * V_32 )
{
if ( V_32 )
F_61 ( & V_32 -> V_32 ) ;
return V_32 ;
}
void F_62 ( struct V_31 * V_32 )
{
if ( V_32 )
F_16 ( & V_32 -> V_32 ) ;
}
struct V_30 * F_63 ( struct V_30 * V_36 )
{
if ( V_36 )
F_61 ( & V_36 -> V_32 ) ;
return V_36 ;
}
void F_64 ( struct V_30 * V_36 )
{
if ( V_36 )
F_16 ( & V_36 -> V_32 ) ;
}
int F_65 ( struct V_31 * V_51 ,
const struct V_30 * V_111 )
{
unsigned long V_112 = V_107 + V_113 ;
if ( V_51 -> V_87 == V_114 )
return - V_115 ;
if ( V_51 -> V_87 == V_116 )
return - V_117 ;
if ( V_111 && ( V_111 -> V_118 == V_119 ||
V_111 -> V_118 == V_120 ) )
return - V_121 ;
while ( ! F_66 ( V_51 ) ) {
if ( F_67 ( V_107 , V_112 ) )
return - V_122 ;
F_68 ( 15 ) ;
if ( V_51 -> V_87 == V_114 )
return - V_115 ;
if ( V_51 -> V_87 == V_116 )
return - V_117 ;
if ( V_111 && ( V_111 -> V_118 == V_119 ||
V_111 -> V_118 == V_120 ) )
return - V_121 ;
}
return 0 ;
}
int F_69 ( struct V_31 * V_32 )
{
return F_70 ( V_32 ) ;
}
int F_71 ( char * V_123 , unsigned V_124 ,
unsigned char type , void * * V_125 )
{
struct V_126 * V_127 ;
while ( V_124 >= sizeof( struct V_126 ) ) {
V_127 = (struct V_126 * ) V_123 ;
if ( V_127 -> V_93 < 2 ) {
F_8 ( V_128
L_10 ,
V_129 ,
V_127 -> V_95 ,
V_127 -> V_93 ) ;
return - 1 ;
}
if ( V_127 -> V_95 == type ) {
* V_125 = V_127 ;
return 0 ;
}
V_123 += V_127 -> V_93 ;
V_124 -= V_127 -> V_93 ;
}
return - 1 ;
}
void * F_72 ( struct V_31 * V_32 , T_4 V_124 , T_5 V_130 ,
T_6 * V_131 )
{
if ( ! V_32 || ! V_32 -> V_54 )
return NULL ;
return F_73 ( V_32 -> V_54 , V_124 , V_130 , V_131 ) ;
}
void F_74 ( struct V_31 * V_32 , T_4 V_124 , void * V_132 ,
T_6 V_131 )
{
if ( ! V_32 || ! V_32 -> V_54 )
return;
if ( ! V_132 )
return;
F_75 ( V_32 -> V_54 , V_124 , V_132 , V_131 ) ;
}
static int F_76 ( struct V_133 * V_134 , unsigned long V_135 ,
void * V_39 )
{
struct V_38 * V_32 = V_39 ;
switch ( V_135 ) {
case V_136 :
if ( V_32 -> type == & V_81 )
( void ) F_77 ( F_19 ( V_32 ) ) ;
else if ( V_32 -> type == & V_137 )
F_78 ( F_13 ( V_32 ) ) ;
break;
case V_138 :
if ( V_32 -> type == & V_81 )
F_79 ( F_19 ( V_32 ) ) ;
else if ( V_32 -> type == & V_137 )
F_80 ( F_13 ( V_32 ) ) ;
break;
}
return 0 ;
}
static int F_81 ( void )
{
V_139 = F_82 ( L_11 , NULL ) ;
if ( ! V_139 )
return - V_140 ;
V_141 = F_83 ( L_12 , 0444 ,
V_139 , NULL ,
& V_142 ) ;
if ( ! V_141 ) {
F_84 ( V_139 ) ;
V_139 = NULL ;
return - V_140 ;
}
return 0 ;
}
static void F_85 ( void )
{
F_84 ( V_141 ) ;
F_84 ( V_139 ) ;
}
static int T_7 F_86 ( void )
{
int V_143 ;
if ( F_1 () ) {
F_87 ( L_13 , V_129 ) ;
return 0 ;
}
F_88 () ;
V_143 = F_81 () ;
if ( V_143 )
goto V_144;
F_89 () ;
V_143 = F_90 ( & V_48 ) ;
if ( V_143 )
goto V_145;
V_143 = F_91 ( & V_48 , & V_146 ) ;
if ( V_143 )
goto V_147;
V_143 = F_92 () ;
if ( V_143 )
goto V_148;
V_143 = F_93 ( & V_149 ) ;
if ( V_143 )
goto V_150;
V_143 = F_94 () ;
if ( V_143 )
goto V_151;
V_143 = F_95 () ;
if ( V_143 )
goto V_152;
V_143 = F_96 ( & V_153 , V_154 ) ;
if ( ! V_143 )
goto V_144;
F_97 () ;
V_152:
F_98 () ;
V_151:
F_99 ( & V_149 ) ;
V_150:
F_100 () ;
V_148:
F_101 ( & V_48 , & V_146 ) ;
V_147:
F_102 ( & V_48 ) ;
V_145:
F_103 () ;
F_85 () ;
V_144:
return V_143 ;
}
static void T_8 F_104 ( void )
{
if ( F_1 () )
return;
F_105 ( & V_153 ) ;
F_100 () ;
F_99 ( & V_149 ) ;
F_98 () ;
F_97 () ;
F_101 ( & V_48 , & V_146 ) ;
F_102 ( & V_48 ) ;
F_103 () ;
F_85 () ;
F_106 ( & V_155 ) ;
}
