int F_1 ( void )
{
return V_1 ;
}
struct V_2 * F_2 (
struct V_3 * V_4 ,
unsigned int V_5 ,
unsigned int V_6 )
{
struct V_7 * V_8 = NULL ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_4 -> V_10 . V_11 ; V_9 ++ ) {
if ( V_4 -> V_8 [ V_9 ] -> V_12 [ 0 ] . V_10 . V_13
== V_5 ) {
V_8 = V_4 -> V_8 [ V_9 ] ;
break;
}
}
if ( ! V_8 )
return NULL ;
for ( V_9 = 0 ; V_9 < V_8 -> V_14 ; V_9 ++ )
if ( V_8 -> V_12 [ V_9 ] . V_10 . V_15 == V_6 )
return & V_8 -> V_12 [ V_9 ] ;
F_3 ( V_16 L_1
L_2 , V_6 , V_5 ,
V_4 -> V_10 . V_17 ) ;
return NULL ;
}
struct V_18 * F_4 ( const struct V_19 * V_20 ,
unsigned V_21 )
{
struct V_3 * V_4 = V_20 -> V_22 ;
int V_9 ;
if ( ! V_4 )
return NULL ;
for ( V_9 = 0 ; V_9 < V_4 -> V_10 . V_11 ; V_9 ++ )
if ( V_4 -> V_23 [ V_9 ] -> V_12 [ 0 ]
. V_10 . V_13 == V_21 )
return V_4 -> V_23 [ V_9 ] ;
return NULL ;
}
struct V_2 * F_5 (
const struct V_18 * V_24 ,
unsigned int V_25 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_24 -> V_14 ; V_9 ++ ) {
if ( V_24 -> V_12 [ V_9 ] . V_10 . V_15 == V_25 )
return & V_24 -> V_12 [ V_9 ] ;
}
return NULL ;
}
static int F_6 ( struct V_26 * V_20 , void * V_27 )
{
struct V_28 * V_29 = V_27 ;
struct V_18 * V_24 ;
if ( ! F_7 ( V_20 ) )
return 0 ;
if ( V_20 -> V_30 != V_29 -> V_31 )
return 0 ;
V_24 = F_8 ( V_20 ) ;
return V_24 -> V_32 == V_29 -> V_32 ;
}
struct V_18 * F_9 ( struct V_33 * V_31 , int V_32 )
{
struct V_28 V_34 ;
struct V_26 * V_20 ;
V_34 . V_32 = V_32 ;
V_34 . V_31 = & V_31 -> V_35 . V_30 ;
V_20 = F_10 ( & V_36 , NULL , & V_34 , F_6 ) ;
F_11 ( V_20 ) ;
return V_20 ? F_8 ( V_20 ) : NULL ;
}
static int F_12 ( struct V_26 * V_20 , void * V_27 )
{
struct V_37 * V_29 = (struct V_37 * ) V_27 ;
if ( ! F_13 ( V_20 ) )
return 0 ;
return V_29 -> V_38 ( F_14 ( V_20 , struct V_19 , V_20 ) , V_29 -> V_27 ) ;
}
int F_15 ( void * V_27 , int (* V_38)( struct V_19 * , void * ) )
{
struct V_37 V_29 = { V_27 , V_38 } ;
return F_16 ( & V_36 , NULL , & V_29 , F_12 ) ;
}
static void F_17 ( struct V_26 * V_20 )
{
struct V_19 * V_39 ;
struct V_40 * V_41 ;
V_39 = F_18 ( V_20 ) ;
V_41 = F_19 ( V_39 -> V_42 ) ;
F_20 ( V_39 ) ;
F_21 ( V_39 ) ;
F_22 ( V_41 ) ;
F_23 ( V_39 -> V_43 ) ;
F_23 ( V_39 -> V_44 ) ;
F_23 ( V_39 -> V_45 ) ;
F_23 ( V_39 ) ;
}
static int F_24 ( struct V_26 * V_20 , struct V_46 * V_47 )
{
struct V_19 * V_48 ;
V_48 = F_18 ( V_20 ) ;
if ( F_25 ( V_47 , L_3 , V_48 -> V_42 -> V_49 ) )
return - V_50 ;
if ( F_25 ( V_47 , L_4 , V_48 -> V_51 ) )
return - V_50 ;
return 0 ;
}
static int F_26 ( struct V_26 * V_20 )
{
struct V_19 * V_39 = F_18 ( V_20 ) ;
if ( V_39 -> V_52 != F_27 ( V_20 ) )
return 0 ;
return 1 ;
}
static void F_28 ( struct V_26 * V_20 )
{
F_29 ( V_20 ) ;
}
static int F_30 ( struct V_26 * V_20 )
{
return F_31 ( V_20 , V_53 ) ;
}
static int F_32 ( struct V_26 * V_20 )
{
return F_33 ( V_20 , V_54 ) ;
}
static int F_34 ( struct V_26 * V_20 )
{
return F_31 ( V_20 , V_55 ) ;
}
static int F_35 ( struct V_26 * V_20 )
{
return F_33 ( V_20 , V_56 ) ;
}
static int F_36 ( struct V_26 * V_20 )
{
return F_31 ( V_20 , V_57 ) ;
}
static int F_37 ( struct V_26 * V_20 )
{
return F_33 ( V_20 , V_58 ) ;
}
static char * F_38 ( struct V_26 * V_20 ,
T_1 * V_59 , T_2 * V_60 , T_3 * V_61 )
{
struct V_19 * V_48 ;
V_48 = F_18 ( V_20 ) ;
return F_39 ( V_62 , L_5 ,
V_48 -> V_42 -> V_49 , V_48 -> V_51 ) ;
}
static unsigned F_40 ( struct V_63 * V_42 )
{
struct V_40 * V_41 = F_14 ( V_42 , struct V_40 , V_64 ) ;
return V_41 -> V_65 ;
}
struct V_19 * F_41 ( struct V_19 * V_66 ,
struct V_63 * V_42 , unsigned V_67 )
{
struct V_19 * V_20 ;
struct V_40 * V_40 = F_19 ( V_42 ) ;
unsigned V_68 = 0 ;
V_20 = F_42 ( sizeof( * V_20 ) , V_62 ) ;
if ( ! V_20 )
return NULL ;
if ( ! F_43 ( V_40 ) ) {
F_23 ( V_20 ) ;
return NULL ;
}
if ( V_40 -> V_30 -> V_69 && V_66 &&
! V_40 -> V_30 -> V_69 ( V_40 , V_20 ) ) {
F_22 ( F_19 ( V_42 ) ) ;
F_23 ( V_20 ) ;
return NULL ;
}
F_44 ( & V_20 -> V_20 ) ;
V_20 -> V_20 . V_42 = & V_36 ;
V_20 -> V_20 . type = & V_70 ;
V_20 -> V_20 . V_71 = V_72 ;
V_20 -> V_20 . V_73 = V_42 -> V_74 -> V_73 ;
F_45 ( & V_20 -> V_20 , F_46 ( V_42 -> V_74 ) ) ;
V_20 -> V_75 = V_76 ;
V_20 -> V_77 = 1 ;
F_47 ( & V_20 -> V_78 , 0 ) ;
F_48 ( & V_20 -> V_79 . V_80 ) ;
V_20 -> V_79 . V_10 . V_81 = V_82 ;
V_20 -> V_79 . V_10 . V_83 = V_84 ;
F_49 ( V_20 , & V_20 -> V_79 , false ) ;
V_20 -> V_85 = 1 ;
if ( F_50 ( ! V_66 ) ) {
V_20 -> V_86 [ 0 ] = '0' ;
V_20 -> V_87 = 0 ;
V_20 -> V_20 . V_66 = V_42 -> V_74 ;
F_51 ( & V_20 -> V_20 , L_6 , V_42 -> V_49 ) ;
V_68 = 1 ;
} else {
if ( V_66 -> V_86 [ 0 ] == '0' ) {
snprintf ( V_20 -> V_86 , sizeof V_20 -> V_86 ,
L_7 , V_67 ) ;
V_20 -> V_87 = 0 ;
} else {
snprintf ( V_20 -> V_86 , sizeof V_20 -> V_86 ,
L_8 , V_66 -> V_86 , V_67 ) ;
if ( V_67 < 15 )
V_20 -> V_87 = V_66 -> V_87 +
( V_67 << ( ( V_66 -> V_88 - 1 ) * 4 ) ) ;
else
V_20 -> V_87 = V_66 -> V_87 +
( 15 << ( ( V_66 -> V_88 - 1 ) * 4 ) ) ;
}
V_20 -> V_20 . V_66 = & V_66 -> V_20 ;
F_51 ( & V_20 -> V_20 , L_9 , V_42 -> V_49 , V_20 -> V_86 ) ;
}
V_20 -> V_89 = V_67 ;
V_20 -> V_42 = V_42 ;
V_20 -> V_66 = V_66 ;
F_48 ( & V_20 -> V_90 ) ;
#ifdef F_52
F_53 ( & V_20 -> V_20 ,
V_91 * 1000 ) ;
V_20 -> V_92 = V_93 ;
V_20 -> V_94 = - V_93 ;
#endif
if ( V_68 )
V_20 -> V_95 = 1 ;
else {
V_20 -> V_95 = ! ! F_54 ( V_40 ) ;
V_20 -> V_96 = F_40 ( V_42 ) ? 1 : 0 ;
}
return V_20 ;
}
struct V_19 * F_55 ( struct V_19 * V_20 )
{
if ( V_20 )
F_56 ( & V_20 -> V_20 ) ;
return V_20 ;
}
void F_57 ( struct V_19 * V_20 )
{
if ( V_20 )
F_11 ( & V_20 -> V_20 ) ;
}
struct V_18 * F_58 ( struct V_18 * V_24 )
{
if ( V_24 )
F_56 ( & V_24 -> V_20 ) ;
return V_24 ;
}
void F_59 ( struct V_18 * V_24 )
{
if ( V_24 )
F_11 ( & V_24 -> V_20 ) ;
}
int F_60 ( struct V_19 * V_39 ,
const struct V_18 * V_97 )
{
unsigned long V_98 = V_93 + V_99 ;
if ( V_39 -> V_75 == V_100 )
return - V_101 ;
if ( V_39 -> V_75 == V_102 )
return - V_103 ;
if ( V_97 && ( V_97 -> V_104 == V_105 ||
V_97 -> V_104 == V_106 ) )
return - V_107 ;
while ( ! F_61 ( V_39 ) ) {
if ( F_62 ( V_93 , V_98 ) )
return - V_108 ;
F_63 ( 15 ) ;
if ( V_39 -> V_75 == V_100 )
return - V_101 ;
if ( V_39 -> V_75 == V_102 )
return - V_103 ;
if ( V_97 && ( V_97 -> V_104 == V_105 ||
V_97 -> V_104 == V_106 ) )
return - V_107 ;
}
return 0 ;
}
int F_64 ( struct V_19 * V_20 )
{
return F_65 ( V_20 ) ;
}
int F_66 ( char * V_109 , unsigned V_110 ,
unsigned char type , void * * V_111 )
{
struct V_112 * V_113 ;
while ( V_110 >= sizeof( struct V_112 ) ) {
V_113 = (struct V_112 * ) V_109 ;
if ( V_113 -> V_81 < 2 ) {
F_3 ( V_114
L_10 ,
V_115 ,
V_113 -> V_83 ,
V_113 -> V_81 ) ;
return - 1 ;
}
if ( V_113 -> V_83 == type ) {
* V_111 = V_113 ;
return 0 ;
}
V_109 += V_113 -> V_81 ;
V_110 -= V_113 -> V_81 ;
}
return - 1 ;
}
void * F_67 ( struct V_19 * V_20 , T_4 V_110 , T_5 V_116 ,
T_6 * V_117 )
{
if ( ! V_20 || ! V_20 -> V_42 )
return NULL ;
return F_68 ( V_20 -> V_42 , V_110 , V_116 , V_117 ) ;
}
void F_69 ( struct V_19 * V_20 , T_4 V_110 , void * V_118 ,
T_6 V_117 )
{
if ( ! V_20 || ! V_20 -> V_42 )
return;
if ( ! V_118 )
return;
F_70 ( V_20 -> V_42 , V_110 , V_118 , V_117 ) ;
}
static int F_71 ( struct V_119 * V_120 , unsigned long V_121 ,
void * V_27 )
{
struct V_26 * V_20 = V_27 ;
switch ( V_121 ) {
case V_122 :
if ( V_20 -> type == & V_70 )
( void ) F_72 ( F_18 ( V_20 ) ) ;
else if ( V_20 -> type == & V_123 )
F_73 ( F_8 ( V_20 ) ) ;
break;
case V_124 :
if ( V_20 -> type == & V_70 )
F_74 ( F_18 ( V_20 ) ) ;
else if ( V_20 -> type == & V_123 )
F_75 ( F_8 ( V_20 ) ) ;
break;
}
return 0 ;
}
static int F_76 ( void )
{
V_125 = F_77 ( L_11 , NULL ) ;
if ( ! V_125 )
return - V_126 ;
V_127 = F_78 ( L_12 , 0444 ,
V_125 , NULL ,
& V_128 ) ;
if ( ! V_127 ) {
F_79 ( V_125 ) ;
V_125 = NULL ;
return - V_126 ;
}
return 0 ;
}
static void F_80 ( void )
{
F_79 ( V_127 ) ;
F_79 ( V_125 ) ;
}
static int T_7 F_81 ( void )
{
int V_129 ;
if ( F_1 () ) {
F_82 ( L_13 , V_115 ) ;
return 0 ;
}
F_83 () ;
V_129 = F_76 () ;
if ( V_129 )
goto V_130;
F_84 () ;
V_129 = F_85 ( & V_36 ) ;
if ( V_129 )
goto V_131;
V_129 = F_86 ( & V_36 , & V_132 ) ;
if ( V_129 )
goto V_133;
V_129 = F_87 () ;
if ( V_129 )
goto V_134;
V_129 = F_88 ( & V_135 ) ;
if ( V_129 )
goto V_136;
V_129 = F_89 () ;
if ( V_129 )
goto V_137;
V_129 = F_90 () ;
if ( V_129 )
goto V_138;
V_129 = F_91 ( & V_139 , V_140 ) ;
if ( ! V_129 )
goto V_130;
F_92 () ;
V_138:
F_93 () ;
V_137:
F_94 ( & V_135 ) ;
V_136:
F_95 () ;
V_134:
F_96 ( & V_36 , & V_132 ) ;
V_133:
F_97 ( & V_36 ) ;
V_131:
F_98 () ;
F_80 () ;
V_130:
return V_129 ;
}
static void T_8 F_99 ( void )
{
if ( F_1 () )
return;
F_100 ( & V_139 ) ;
F_95 () ;
F_94 ( & V_135 ) ;
F_93 () ;
F_92 () ;
F_96 ( & V_36 , & V_132 ) ;
F_97 ( & V_36 ) ;
F_98 () ;
F_80 () ;
}
