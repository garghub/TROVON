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
return 0 ;
}
static void F_27 ( struct V_26 * V_20 )
{
F_28 ( V_20 ) ;
}
static int F_29 ( struct V_26 * V_20 )
{
return F_30 ( V_20 , V_52 ) ;
}
static int F_31 ( struct V_26 * V_20 )
{
return F_32 ( V_20 , V_53 ) ;
}
static int F_33 ( struct V_26 * V_20 )
{
return F_30 ( V_20 , V_54 ) ;
}
static int F_34 ( struct V_26 * V_20 )
{
return F_32 ( V_20 , V_55 ) ;
}
static int F_35 ( struct V_26 * V_20 )
{
return F_30 ( V_20 , V_56 ) ;
}
static int F_36 ( struct V_26 * V_20 )
{
return F_32 ( V_20 , V_57 ) ;
}
static char * F_37 ( struct V_26 * V_20 ,
T_1 * V_58 , T_2 * V_59 , T_3 * V_60 )
{
struct V_19 * V_48 ;
V_48 = F_18 ( V_20 ) ;
return F_38 ( V_61 , L_5 ,
V_48 -> V_42 -> V_49 , V_48 -> V_51 ) ;
}
static unsigned F_39 ( struct V_62 * V_42 )
{
struct V_40 * V_41 = F_14 ( V_42 , struct V_40 , V_63 ) ;
return V_41 -> V_64 ;
}
struct V_19 * F_40 ( struct V_19 * V_65 ,
struct V_62 * V_42 , unsigned V_66 )
{
struct V_19 * V_20 ;
struct V_40 * V_40 = F_19 ( V_42 ) ;
unsigned V_67 = 0 ;
V_20 = F_41 ( sizeof( * V_20 ) , V_61 ) ;
if ( ! V_20 )
return NULL ;
if ( ! F_42 ( V_40 ) ) {
F_23 ( V_20 ) ;
return NULL ;
}
if ( V_40 -> V_30 -> V_68 && V_65 &&
! V_40 -> V_30 -> V_68 ( V_40 , V_20 ) ) {
F_22 ( F_19 ( V_42 ) ) ;
F_23 ( V_20 ) ;
return NULL ;
}
F_43 ( & V_20 -> V_20 ) ;
V_20 -> V_20 . V_42 = & V_36 ;
V_20 -> V_20 . type = & V_69 ;
V_20 -> V_20 . V_70 = V_71 ;
V_20 -> V_20 . V_72 = V_42 -> V_73 -> V_72 ;
F_44 ( & V_20 -> V_20 , F_45 ( V_42 -> V_73 ) ) ;
V_20 -> V_74 = V_75 ;
V_20 -> V_76 = 1 ;
F_46 ( & V_20 -> V_77 , 0 ) ;
F_47 ( & V_20 -> V_78 . V_79 ) ;
V_20 -> V_78 . V_10 . V_80 = V_81 ;
V_20 -> V_78 . V_10 . V_82 = V_83 ;
F_48 ( V_20 , & V_20 -> V_78 , false ) ;
V_20 -> V_84 = 1 ;
if ( F_49 ( ! V_65 ) ) {
V_20 -> V_85 [ 0 ] = '0' ;
V_20 -> V_86 = 0 ;
V_20 -> V_20 . V_65 = V_42 -> V_73 ;
F_50 ( & V_20 -> V_20 , L_6 , V_42 -> V_49 ) ;
V_67 = 1 ;
} else {
if ( V_65 -> V_85 [ 0 ] == '0' ) {
snprintf ( V_20 -> V_85 , sizeof V_20 -> V_85 ,
L_7 , V_66 ) ;
V_20 -> V_86 = 0 ;
} else {
snprintf ( V_20 -> V_85 , sizeof V_20 -> V_85 ,
L_8 , V_65 -> V_85 , V_66 ) ;
if ( V_66 < 15 )
V_20 -> V_86 = V_65 -> V_86 +
( V_66 << ( ( V_65 -> V_87 - 1 ) * 4 ) ) ;
else
V_20 -> V_86 = V_65 -> V_86 +
( 15 << ( ( V_65 -> V_87 - 1 ) * 4 ) ) ;
}
V_20 -> V_20 . V_65 = & V_65 -> V_20 ;
F_50 ( & V_20 -> V_20 , L_9 , V_42 -> V_49 , V_20 -> V_85 ) ;
}
V_20 -> V_88 = V_66 ;
V_20 -> V_42 = V_42 ;
V_20 -> V_65 = V_65 ;
F_47 ( & V_20 -> V_89 ) ;
#ifdef F_51
F_52 ( & V_20 -> V_20 ,
V_90 * 1000 ) ;
V_20 -> V_91 = V_92 ;
V_20 -> V_93 = - V_92 ;
#endif
if ( V_67 )
V_20 -> V_94 = 1 ;
else {
V_20 -> V_94 = ! ! F_53 ( V_40 ) ;
V_20 -> V_95 = F_39 ( V_42 ) ? 1 : 0 ;
}
return V_20 ;
}
struct V_19 * F_54 ( struct V_19 * V_20 )
{
if ( V_20 )
F_55 ( & V_20 -> V_20 ) ;
return V_20 ;
}
void F_56 ( struct V_19 * V_20 )
{
if ( V_20 )
F_11 ( & V_20 -> V_20 ) ;
}
struct V_18 * F_57 ( struct V_18 * V_24 )
{
if ( V_24 )
F_55 ( & V_24 -> V_20 ) ;
return V_24 ;
}
void F_58 ( struct V_18 * V_24 )
{
if ( V_24 )
F_11 ( & V_24 -> V_20 ) ;
}
int F_59 ( struct V_19 * V_39 ,
const struct V_18 * V_96 )
{
unsigned long V_97 = V_92 + V_98 ;
if ( V_39 -> V_74 == V_99 )
return - V_100 ;
if ( V_39 -> V_74 == V_101 )
return - V_102 ;
if ( V_96 && ( V_96 -> V_103 == V_104 ||
V_96 -> V_103 == V_105 ) )
return - V_106 ;
while ( ! F_60 ( V_39 ) ) {
if ( F_61 ( V_92 , V_97 ) )
return - V_107 ;
F_62 ( 15 ) ;
if ( V_39 -> V_74 == V_99 )
return - V_100 ;
if ( V_39 -> V_74 == V_101 )
return - V_102 ;
if ( V_96 && ( V_96 -> V_103 == V_104 ||
V_96 -> V_103 == V_105 ) )
return - V_106 ;
}
return 0 ;
}
int F_63 ( struct V_19 * V_20 )
{
return F_64 ( V_20 ) ;
}
int F_65 ( char * V_108 , unsigned V_109 ,
unsigned char type , void * * V_110 )
{
struct V_111 * V_112 ;
while ( V_109 >= sizeof( struct V_111 ) ) {
V_112 = (struct V_111 * ) V_108 ;
if ( V_112 -> V_80 < 2 ) {
F_3 ( V_113
L_10 ,
V_114 ,
V_112 -> V_82 ,
V_112 -> V_80 ) ;
return - 1 ;
}
if ( V_112 -> V_82 == type ) {
* V_110 = V_112 ;
return 0 ;
}
V_108 += V_112 -> V_80 ;
V_109 -= V_112 -> V_80 ;
}
return - 1 ;
}
void * F_66 ( struct V_19 * V_20 , T_4 V_109 , T_5 V_115 ,
T_6 * V_116 )
{
if ( ! V_20 || ! V_20 -> V_42 )
return NULL ;
return F_67 ( V_20 -> V_42 , V_109 , V_115 , V_116 ) ;
}
void F_68 ( struct V_19 * V_20 , T_4 V_109 , void * V_117 ,
T_6 V_116 )
{
if ( ! V_20 || ! V_20 -> V_42 )
return;
if ( ! V_117 )
return;
F_69 ( V_20 -> V_42 , V_109 , V_117 , V_116 ) ;
}
static int F_70 ( struct V_118 * V_119 , unsigned long V_120 ,
void * V_27 )
{
struct V_26 * V_20 = V_27 ;
switch ( V_120 ) {
case V_121 :
if ( V_20 -> type == & V_69 )
( void ) F_71 ( F_18 ( V_20 ) ) ;
else if ( V_20 -> type == & V_122 )
F_72 ( F_8 ( V_20 ) ) ;
break;
case V_123 :
if ( V_20 -> type == & V_69 )
F_73 ( F_18 ( V_20 ) ) ;
else if ( V_20 -> type == & V_122 )
F_74 ( F_8 ( V_20 ) ) ;
break;
}
return 0 ;
}
static int F_75 ( void )
{
V_124 = F_76 ( L_11 , NULL ) ;
if ( ! V_124 )
return - V_125 ;
V_126 = F_77 ( L_12 , 0444 ,
V_124 , NULL ,
& V_127 ) ;
if ( ! V_126 ) {
F_78 ( V_124 ) ;
V_124 = NULL ;
return - V_125 ;
}
return 0 ;
}
static void F_79 ( void )
{
F_78 ( V_126 ) ;
F_78 ( V_124 ) ;
}
static int T_7 F_80 ( void )
{
int V_128 ;
if ( F_1 () ) {
F_81 ( L_13 , V_114 ) ;
return 0 ;
}
F_82 () ;
V_128 = F_75 () ;
if ( V_128 )
goto V_129;
F_83 () ;
V_128 = F_84 ( & V_36 ) ;
if ( V_128 )
goto V_130;
V_128 = F_85 ( & V_36 , & V_131 ) ;
if ( V_128 )
goto V_132;
V_128 = F_86 () ;
if ( V_128 )
goto V_133;
V_128 = F_87 ( & V_134 ) ;
if ( V_128 )
goto V_135;
V_128 = F_88 () ;
if ( V_128 )
goto V_136;
V_128 = F_89 () ;
if ( V_128 )
goto V_137;
V_128 = F_90 ( & V_138 , V_139 ) ;
if ( ! V_128 )
goto V_129;
F_91 () ;
V_137:
F_92 () ;
V_136:
F_93 ( & V_134 ) ;
V_135:
F_94 () ;
V_133:
F_95 ( & V_36 , & V_131 ) ;
V_132:
F_96 ( & V_36 ) ;
V_130:
F_97 () ;
F_79 () ;
V_129:
return V_128 ;
}
static void T_8 F_98 ( void )
{
if ( F_1 () )
return;
F_99 ( & V_138 ) ;
F_94 () ;
F_93 ( & V_134 ) ;
F_92 () ;
F_91 () ;
F_95 ( & V_36 , & V_131 ) ;
F_96 ( & V_36 ) ;
F_97 () ;
F_79 () ;
}
