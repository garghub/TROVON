struct V_1 * F_1 (
struct V_2 * V_3 ,
unsigned int V_4 ,
unsigned int V_5 )
{
struct V_6 * V_7 = NULL ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_3 -> V_9 . V_10 ; V_8 ++ ) {
if ( V_3 -> V_7 [ V_8 ] -> V_11 [ 0 ] . V_9 . V_12
== V_4 ) {
V_7 = V_3 -> V_7 [ V_8 ] ;
break;
}
}
if ( ! V_7 )
return NULL ;
for ( V_8 = 0 ; V_8 < V_7 -> V_13 ; V_8 ++ )
if ( V_7 -> V_11 [ V_8 ] . V_9 . V_14 == V_5 )
return & V_7 -> V_11 [ V_8 ] ;
F_2 ( V_15 L_1
L_2 , V_5 , V_4 ,
V_3 -> V_9 . V_16 ) ;
return NULL ;
}
struct V_17 * F_3 ( const struct V_18 * V_19 ,
unsigned V_20 )
{
struct V_2 * V_3 = V_19 -> V_21 ;
int V_8 ;
if ( ! V_3 )
return NULL ;
for ( V_8 = 0 ; V_8 < V_3 -> V_9 . V_10 ; V_8 ++ )
if ( V_3 -> V_22 [ V_8 ] -> V_11 [ 0 ]
. V_9 . V_12 == V_20 )
return V_3 -> V_22 [ V_8 ] ;
return NULL ;
}
struct V_1 * F_4 (
const struct V_17 * V_23 ,
unsigned int V_24 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_23 -> V_13 ; V_8 ++ ) {
if ( V_23 -> V_11 [ V_8 ] . V_9 . V_14 == V_24 )
return & V_23 -> V_11 [ V_8 ] ;
}
return NULL ;
}
static int F_5 ( struct V_25 * V_19 , void * V_26 )
{
struct V_27 * V_28 = V_26 ;
struct V_17 * V_23 ;
if ( ! F_6 ( V_19 ) )
return 0 ;
if ( V_19 -> V_29 != V_28 -> V_30 )
return 0 ;
V_23 = F_7 ( V_19 ) ;
return V_23 -> V_31 == V_28 -> V_31 ;
}
struct V_17 * F_8 ( struct V_32 * V_30 , int V_31 )
{
struct V_27 V_33 ;
struct V_25 * V_19 ;
V_33 . V_31 = V_31 ;
V_33 . V_30 = & V_30 -> V_34 . V_29 ;
V_19 = F_9 ( & V_35 , NULL , & V_33 , F_5 ) ;
F_10 ( V_19 ) ;
return V_19 ? F_7 ( V_19 ) : NULL ;
}
static int F_11 ( struct V_25 * V_19 , void * V_26 )
{
struct V_36 * V_28 = (struct V_36 * ) V_26 ;
if ( ! F_12 ( V_19 ) )
return 0 ;
return V_28 -> V_37 ( F_13 ( V_19 , struct V_18 , V_19 ) , V_28 -> V_26 ) ;
}
int F_14 ( void * V_26 , int (* V_37)( struct V_18 * , void * ) )
{
struct V_36 V_28 = { V_26 , V_37 } ;
return F_15 ( & V_35 , NULL , & V_28 , F_11 ) ;
}
static void F_16 ( struct V_25 * V_19 )
{
struct V_18 * V_38 ;
struct V_39 * V_40 ;
V_38 = F_17 ( V_19 ) ;
V_40 = F_18 ( V_38 -> V_41 ) ;
F_19 ( V_38 ) ;
F_20 ( V_38 ) ;
F_21 ( V_40 ) ;
F_22 ( V_38 -> V_42 ) ;
F_22 ( V_38 -> V_43 ) ;
F_22 ( V_38 -> V_44 ) ;
F_22 ( V_38 ) ;
}
static int F_23 ( struct V_25 * V_19 , struct V_45 * V_46 )
{
struct V_18 * V_47 ;
V_47 = F_17 ( V_19 ) ;
if ( F_24 ( V_46 , L_3 , V_47 -> V_41 -> V_48 ) )
return - V_49 ;
if ( F_24 ( V_46 , L_4 , V_47 -> V_50 ) )
return - V_49 ;
return 0 ;
}
static int F_25 ( struct V_25 * V_19 )
{
return 0 ;
}
static void F_26 ( struct V_25 * V_19 )
{
F_27 ( V_19 ) ;
}
static int F_28 ( struct V_25 * V_19 )
{
return F_29 ( V_19 , V_51 ) ;
}
static int F_30 ( struct V_25 * V_19 )
{
return F_31 ( V_19 , V_52 ) ;
}
static int F_32 ( struct V_25 * V_19 )
{
return F_29 ( V_19 , V_53 ) ;
}
static int F_33 ( struct V_25 * V_19 )
{
return F_31 ( V_19 , V_54 ) ;
}
static int F_34 ( struct V_25 * V_19 )
{
return F_29 ( V_19 , V_55 ) ;
}
static int F_35 ( struct V_25 * V_19 )
{
return F_31 ( V_19 , V_56 ) ;
}
static char * F_36 ( struct V_25 * V_19 ,
T_1 * V_57 , T_2 * V_58 , T_3 * V_59 )
{
struct V_18 * V_47 ;
V_47 = F_17 ( V_19 ) ;
return F_37 ( V_60 , L_5 ,
V_47 -> V_41 -> V_48 , V_47 -> V_50 ) ;
}
static unsigned F_38 ( struct V_61 * V_41 )
{
struct V_39 * V_40 = F_13 ( V_41 , struct V_39 , V_62 ) ;
return V_40 -> V_63 ;
}
struct V_18 * F_39 ( struct V_18 * V_64 ,
struct V_61 * V_41 , unsigned V_65 )
{
struct V_18 * V_19 ;
struct V_39 * V_39 = F_18 ( V_41 ) ;
unsigned V_66 = 0 ;
V_19 = F_40 ( sizeof( * V_19 ) , V_60 ) ;
if ( ! V_19 )
return NULL ;
if ( ! F_41 ( V_39 ) ) {
F_22 ( V_19 ) ;
return NULL ;
}
if ( V_39 -> V_29 -> V_67 && V_64 &&
! V_39 -> V_29 -> V_67 ( V_39 , V_19 ) ) {
F_21 ( F_18 ( V_41 ) ) ;
F_22 ( V_19 ) ;
return NULL ;
}
F_42 ( & V_19 -> V_19 ) ;
V_19 -> V_19 . V_41 = & V_35 ;
V_19 -> V_19 . type = & V_68 ;
V_19 -> V_19 . V_69 = V_70 ;
V_19 -> V_19 . V_71 = V_41 -> V_72 -> V_71 ;
F_43 ( & V_19 -> V_19 , F_44 ( V_41 -> V_72 ) ) ;
V_19 -> V_73 = V_74 ;
V_19 -> V_75 = 1 ;
F_45 ( & V_19 -> V_76 , 0 ) ;
F_46 ( & V_19 -> V_77 . V_78 ) ;
V_19 -> V_77 . V_9 . V_79 = V_80 ;
V_19 -> V_77 . V_9 . V_81 = V_82 ;
F_47 ( V_19 , & V_19 -> V_77 , false ) ;
V_19 -> V_83 = 1 ;
if ( F_48 ( ! V_64 ) ) {
V_19 -> V_84 [ 0 ] = '0' ;
V_19 -> V_85 = 0 ;
V_19 -> V_19 . V_64 = V_41 -> V_72 ;
F_49 ( & V_19 -> V_19 , L_6 , V_41 -> V_48 ) ;
V_66 = 1 ;
} else {
if ( V_64 -> V_84 [ 0 ] == '0' ) {
snprintf ( V_19 -> V_84 , sizeof V_19 -> V_84 ,
L_7 , V_65 ) ;
V_19 -> V_85 = 0 ;
} else {
snprintf ( V_19 -> V_84 , sizeof V_19 -> V_84 ,
L_8 , V_64 -> V_84 , V_65 ) ;
if ( V_65 < 15 )
V_19 -> V_85 = V_64 -> V_85 +
( V_65 << ( ( V_64 -> V_86 - 1 ) * 4 ) ) ;
else
V_19 -> V_85 = V_64 -> V_85 +
( 15 << ( ( V_64 -> V_86 - 1 ) * 4 ) ) ;
}
V_19 -> V_19 . V_64 = & V_64 -> V_19 ;
F_49 ( & V_19 -> V_19 , L_9 , V_41 -> V_48 , V_19 -> V_84 ) ;
}
V_19 -> V_87 = V_65 ;
V_19 -> V_41 = V_41 ;
V_19 -> V_64 = V_64 ;
F_46 ( & V_19 -> V_88 ) ;
#ifdef F_50
F_51 ( & V_19 -> V_19 ,
V_89 * 1000 ) ;
V_19 -> V_90 = V_91 ;
V_19 -> V_92 = - V_91 ;
#endif
if ( V_66 )
V_19 -> V_93 = 1 ;
else {
V_19 -> V_93 = V_39 -> V_94 ;
V_19 -> V_95 = F_38 ( V_41 ) ? 1 : 0 ;
}
return V_19 ;
}
struct V_18 * F_52 ( struct V_18 * V_19 )
{
if ( V_19 )
F_53 ( & V_19 -> V_19 ) ;
return V_19 ;
}
void F_54 ( struct V_18 * V_19 )
{
if ( V_19 )
F_10 ( & V_19 -> V_19 ) ;
}
struct V_17 * F_55 ( struct V_17 * V_23 )
{
if ( V_23 )
F_53 ( & V_23 -> V_19 ) ;
return V_23 ;
}
void F_56 ( struct V_17 * V_23 )
{
if ( V_23 )
F_10 ( & V_23 -> V_19 ) ;
}
int F_57 ( struct V_18 * V_38 ,
const struct V_17 * V_96 )
{
unsigned long V_97 = V_91 + V_98 ;
if ( V_38 -> V_73 == V_99 )
return - V_100 ;
if ( V_38 -> V_73 == V_101 )
return - V_102 ;
if ( V_96 && ( V_96 -> V_103 == V_104 ||
V_96 -> V_103 == V_105 ) )
return - V_106 ;
while ( ! F_58 ( V_38 ) ) {
if ( F_59 ( V_91 , V_97 ) )
return - V_107 ;
F_60 ( 15 ) ;
if ( V_38 -> V_73 == V_99 )
return - V_100 ;
if ( V_38 -> V_73 == V_101 )
return - V_102 ;
if ( V_96 && ( V_96 -> V_103 == V_104 ||
V_96 -> V_103 == V_105 ) )
return - V_106 ;
}
return 0 ;
}
int F_61 ( struct V_18 * V_19 )
{
return F_62 ( V_19 ) ;
}
int F_63 ( char * V_108 , unsigned V_109 ,
unsigned char type , void * * V_110 )
{
struct V_111 * V_112 ;
while ( V_109 >= sizeof( struct V_111 ) ) {
V_112 = (struct V_111 * ) V_108 ;
if ( V_112 -> V_79 < 2 ) {
F_2 ( V_113
L_10 ,
V_114 ,
V_112 -> V_81 ,
V_112 -> V_79 ) ;
return - 1 ;
}
if ( V_112 -> V_81 == type ) {
* V_110 = V_112 ;
return 0 ;
}
V_108 += V_112 -> V_79 ;
V_109 -= V_112 -> V_79 ;
}
return - 1 ;
}
void * F_64 ( struct V_18 * V_19 , T_4 V_109 , T_5 V_115 ,
T_6 * V_116 )
{
if ( ! V_19 || ! V_19 -> V_41 )
return NULL ;
return F_65 ( V_19 -> V_41 , V_109 , V_115 , V_116 ) ;
}
void F_66 ( struct V_18 * V_19 , T_4 V_109 , void * V_117 ,
T_6 V_116 )
{
if ( ! V_19 || ! V_19 -> V_41 )
return;
if ( ! V_117 )
return;
F_67 ( V_19 -> V_41 , V_109 , V_117 , V_116 ) ;
}
int F_68 ( void )
{
return V_118 ;
}
static int F_69 ( struct V_119 * V_120 , unsigned long V_121 ,
void * V_26 )
{
struct V_25 * V_19 = V_26 ;
switch ( V_121 ) {
case V_122 :
if ( V_19 -> type == & V_68 )
( void ) F_70 ( F_17 ( V_19 ) ) ;
else if ( V_19 -> type == & V_123 )
F_71 ( F_7 ( V_19 ) ) ;
break;
case V_124 :
if ( V_19 -> type == & V_68 )
F_72 ( F_17 ( V_19 ) ) ;
else if ( V_19 -> type == & V_123 )
F_73 ( F_7 ( V_19 ) ) ;
break;
}
return 0 ;
}
static int F_74 ( void )
{
V_125 = F_75 ( L_11 , NULL ) ;
if ( ! V_125 )
return - V_126 ;
V_127 = F_76 ( L_12 , 0444 ,
V_125 , NULL ,
& V_128 ) ;
if ( ! V_127 ) {
F_77 ( V_125 ) ;
V_125 = NULL ;
return - V_126 ;
}
return 0 ;
}
static void F_78 ( void )
{
F_77 ( V_127 ) ;
F_77 ( V_125 ) ;
}
static int T_7 F_79 ( void )
{
int V_129 ;
if ( V_118 ) {
F_80 ( L_13 , V_114 ) ;
return 0 ;
}
V_129 = F_74 () ;
if ( V_129 )
goto V_130;
F_81 () ;
V_129 = F_82 ( & V_35 ) ;
if ( V_129 )
goto V_131;
V_129 = F_83 ( & V_35 , & V_132 ) ;
if ( V_129 )
goto V_133;
V_129 = F_84 () ;
if ( V_129 )
goto V_134;
V_129 = F_85 ( & V_135 ) ;
if ( V_129 )
goto V_136;
V_129 = F_86 () ;
if ( V_129 )
goto V_137;
V_129 = F_87 () ;
if ( V_129 )
goto V_138;
V_129 = F_88 ( & V_139 , V_140 ) ;
if ( ! V_129 )
goto V_130;
F_89 () ;
V_138:
F_90 () ;
V_137:
F_91 ( & V_135 ) ;
V_136:
F_92 () ;
V_134:
F_93 ( & V_35 , & V_132 ) ;
V_133:
F_94 ( & V_35 ) ;
V_131:
F_95 () ;
F_78 () ;
V_130:
return V_129 ;
}
static void T_8 F_96 ( void )
{
if ( V_118 )
return;
F_97 ( & V_139 ) ;
F_92 () ;
F_91 ( & V_135 ) ;
F_90 () ;
F_89 () ;
F_93 ( & V_35 , & V_132 ) ;
F_94 ( & V_35 ) ;
F_95 () ;
F_78 () ;
}
