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
static void F_11 ( struct V_25 * V_19 )
{
struct V_18 * V_36 ;
struct V_37 * V_38 ;
V_36 = F_12 ( V_19 ) ;
V_38 = F_13 ( V_36 -> V_39 ) ;
F_14 ( V_36 ) ;
F_15 ( V_36 ) ;
F_16 ( V_38 ) ;
F_17 ( V_36 -> V_40 ) ;
F_17 ( V_36 -> V_41 ) ;
F_17 ( V_36 -> V_42 ) ;
F_17 ( V_36 ) ;
}
static int F_18 ( struct V_25 * V_19 , struct V_43 * V_44 )
{
struct V_18 * V_45 ;
V_45 = F_12 ( V_19 ) ;
if ( F_19 ( V_44 , L_3 , V_45 -> V_39 -> V_46 ) )
return - V_47 ;
if ( F_19 ( V_44 , L_4 , V_45 -> V_48 ) )
return - V_47 ;
return 0 ;
}
static int F_18 ( struct V_25 * V_19 , struct V_43 * V_44 )
{
return - V_49 ;
}
static int F_20 ( struct V_25 * V_19 )
{
return 0 ;
}
static void F_21 ( struct V_25 * V_19 )
{
F_22 ( V_19 ) ;
}
static int F_23 ( struct V_25 * V_19 )
{
return F_24 ( V_19 , V_50 ) ;
}
static int F_25 ( struct V_25 * V_19 )
{
return F_26 ( V_19 , V_51 ) ;
}
static int F_27 ( struct V_25 * V_19 )
{
return F_24 ( V_19 , V_52 ) ;
}
static int F_28 ( struct V_25 * V_19 )
{
return F_26 ( V_19 , V_53 ) ;
}
static int F_29 ( struct V_25 * V_19 )
{
return F_24 ( V_19 , V_54 ) ;
}
static int F_30 ( struct V_25 * V_19 )
{
return F_26 ( V_19 , V_55 ) ;
}
static char * F_31 ( struct V_25 * V_19 , T_1 * V_56 )
{
struct V_18 * V_45 ;
V_45 = F_12 ( V_19 ) ;
return F_32 ( V_57 , L_5 ,
V_45 -> V_39 -> V_46 , V_45 -> V_48 ) ;
}
static unsigned F_33 ( struct V_58 * V_39 )
{
struct V_37 * V_38 = F_34 ( V_39 , struct V_37 , V_59 ) ;
return V_38 -> V_60 ;
}
struct V_18 * F_35 ( struct V_18 * V_61 ,
struct V_58 * V_39 , unsigned V_62 )
{
struct V_18 * V_19 ;
struct V_37 * V_37 = F_34 ( V_39 , struct V_37 , V_59 ) ;
unsigned V_63 = 0 ;
V_19 = F_36 ( sizeof( * V_19 ) , V_57 ) ;
if ( ! V_19 )
return NULL ;
if ( ! F_37 ( F_13 ( V_39 ) ) ) {
F_17 ( V_19 ) ;
return NULL ;
}
if ( V_37 -> V_29 -> V_64 && V_61 &&
! V_37 -> V_29 -> V_64 ( V_37 , V_19 ) ) {
F_16 ( F_13 ( V_39 ) ) ;
F_17 ( V_19 ) ;
return NULL ;
}
F_38 ( & V_19 -> V_19 ) ;
V_19 -> V_19 . V_39 = & V_35 ;
V_19 -> V_19 . type = & V_65 ;
V_19 -> V_19 . V_66 = V_67 ;
V_19 -> V_19 . V_68 = V_39 -> V_69 -> V_68 ;
F_39 ( & V_19 -> V_19 , F_40 ( V_39 -> V_69 ) ) ;
V_19 -> V_70 = V_71 ;
F_41 ( & V_19 -> V_72 , 0 ) ;
F_42 ( & V_19 -> V_73 . V_74 ) ;
V_19 -> V_73 . V_9 . V_75 = V_76 ;
V_19 -> V_73 . V_9 . V_77 = V_78 ;
F_43 ( V_19 , & V_19 -> V_73 , false ) ;
V_19 -> V_79 = 1 ;
if ( F_44 ( ! V_61 ) ) {
V_19 -> V_80 [ 0 ] = '0' ;
V_19 -> V_81 = 0 ;
V_19 -> V_19 . V_61 = V_39 -> V_69 ;
F_45 ( & V_19 -> V_19 , L_6 , V_39 -> V_46 ) ;
V_63 = 1 ;
} else {
if ( V_61 -> V_80 [ 0 ] == '0' ) {
snprintf ( V_19 -> V_80 , sizeof V_19 -> V_80 ,
L_7 , V_62 ) ;
V_19 -> V_81 = 0 ;
} else {
snprintf ( V_19 -> V_80 , sizeof V_19 -> V_80 ,
L_8 , V_61 -> V_80 , V_62 ) ;
if ( V_62 < 15 )
V_19 -> V_81 = V_61 -> V_81 +
( V_62 << ( ( V_61 -> V_82 - 1 ) * 4 ) ) ;
else
V_19 -> V_81 = V_61 -> V_81 +
( 15 << ( ( V_61 -> V_82 - 1 ) * 4 ) ) ;
}
V_19 -> V_19 . V_61 = & V_61 -> V_19 ;
F_45 ( & V_19 -> V_19 , L_9 , V_39 -> V_46 , V_19 -> V_80 ) ;
}
V_19 -> V_83 = V_62 ;
V_19 -> V_39 = V_39 ;
V_19 -> V_61 = V_61 ;
F_42 ( & V_19 -> V_84 ) ;
#ifdef F_46
F_47 ( & V_19 -> V_19 ,
V_85 * 1000 ) ;
V_19 -> V_86 = V_87 ;
V_19 -> V_88 = - V_87 ;
#endif
if ( V_63 )
V_19 -> V_89 = 1 ;
else {
V_19 -> V_89 = V_37 -> V_90 ;
V_19 -> V_91 = F_33 ( V_39 ) ? 1 : 0 ;
}
return V_19 ;
}
struct V_18 * F_48 ( struct V_18 * V_19 )
{
if ( V_19 )
F_49 ( & V_19 -> V_19 ) ;
return V_19 ;
}
void F_50 ( struct V_18 * V_19 )
{
if ( V_19 )
F_10 ( & V_19 -> V_19 ) ;
}
struct V_17 * F_51 ( struct V_17 * V_23 )
{
if ( V_23 )
F_49 ( & V_23 -> V_19 ) ;
return V_23 ;
}
void F_52 ( struct V_17 * V_23 )
{
if ( V_23 )
F_10 ( & V_23 -> V_19 ) ;
}
int F_53 ( struct V_18 * V_36 ,
const struct V_17 * V_92 )
{
unsigned long V_93 = V_87 + V_94 ;
if ( V_36 -> V_70 == V_95 )
return - V_49 ;
if ( V_36 -> V_70 == V_96 )
return - V_97 ;
if ( V_92 && ( V_92 -> V_98 == V_99 ||
V_92 -> V_98 == V_100 ) )
return - V_101 ;
while ( ! F_54 ( V_36 ) ) {
if ( F_55 ( V_87 , V_93 ) )
return - V_102 ;
F_56 ( 15 ) ;
if ( V_36 -> V_70 == V_95 )
return - V_49 ;
if ( V_36 -> V_70 == V_96 )
return - V_97 ;
if ( V_92 && ( V_92 -> V_98 == V_99 ||
V_92 -> V_98 == V_100 ) )
return - V_101 ;
}
return 0 ;
}
int F_57 ( struct V_18 * V_19 )
{
return F_58 ( V_19 ) ;
}
int F_59 ( char * V_103 , unsigned V_104 ,
unsigned char type , void * * V_105 )
{
struct V_106 * V_107 ;
while ( V_104 >= sizeof( struct V_106 ) ) {
V_107 = (struct V_106 * ) V_103 ;
if ( V_107 -> V_75 < 2 ) {
F_2 ( V_108
L_10 ,
V_109 ,
V_107 -> V_77 ,
V_107 -> V_75 ) ;
return - 1 ;
}
if ( V_107 -> V_77 == type ) {
* V_105 = V_107 ;
return 0 ;
}
V_103 += V_107 -> V_75 ;
V_104 -= V_107 -> V_75 ;
}
return - 1 ;
}
void * F_60 ( struct V_18 * V_19 , T_2 V_104 , T_3 V_110 ,
T_4 * V_111 )
{
if ( ! V_19 || ! V_19 -> V_39 )
return NULL ;
return F_61 ( V_19 -> V_39 , V_104 , V_110 , V_111 ) ;
}
void F_62 ( struct V_18 * V_19 , T_2 V_104 , void * V_112 ,
T_4 V_111 )
{
if ( ! V_19 || ! V_19 -> V_39 )
return;
if ( ! V_112 )
return;
F_63 ( V_19 -> V_39 , V_104 , V_112 , V_111 ) ;
}
int F_64 ( void )
{
return V_113 ;
}
static int F_65 ( struct V_114 * V_115 , unsigned long V_116 ,
void * V_26 )
{
struct V_25 * V_19 = V_26 ;
switch ( V_116 ) {
case V_117 :
if ( V_19 -> type == & V_65 )
( void ) F_66 ( F_12 ( V_19 ) ) ;
else if ( V_19 -> type == & V_118 )
F_67 ( F_7 ( V_19 ) ) ;
break;
case V_119 :
if ( V_19 -> type == & V_65 )
F_68 ( F_12 ( V_19 ) ) ;
else if ( V_19 -> type == & V_118 )
F_69 ( F_7 ( V_19 ) ) ;
break;
}
return 0 ;
}
static int F_70 ( void )
{
V_120 = F_71 ( L_11 , NULL ) ;
if ( ! V_120 )
return - V_121 ;
V_122 = F_72 ( L_12 , 0444 ,
V_120 , NULL ,
& V_123 ) ;
if ( ! V_122 ) {
F_73 ( V_120 ) ;
V_120 = NULL ;
return - V_121 ;
}
return 0 ;
}
static void F_74 ( void )
{
F_73 ( V_122 ) ;
F_73 ( V_120 ) ;
}
static int T_5 F_75 ( void )
{
int V_124 ;
if ( V_113 ) {
F_76 ( L_13 , V_109 ) ;
return 0 ;
}
V_124 = F_70 () ;
if ( V_124 )
goto V_125;
F_77 () ;
V_124 = F_78 ( & V_35 ) ;
if ( V_124 )
goto V_126;
V_124 = F_79 ( & V_35 , & V_127 ) ;
if ( V_124 )
goto V_128;
V_124 = F_80 () ;
if ( V_124 )
goto V_129;
V_124 = F_81 ( & V_130 ) ;
if ( V_124 )
goto V_131;
V_124 = F_82 () ;
if ( V_124 )
goto V_132;
V_124 = F_83 () ;
if ( V_124 )
goto V_133;
V_124 = F_84 ( & V_134 , V_135 ) ;
if ( ! V_124 )
goto V_125;
F_85 () ;
V_133:
F_86 () ;
V_132:
F_87 ( & V_130 ) ;
V_131:
F_88 () ;
V_129:
F_89 ( & V_35 , & V_127 ) ;
V_128:
F_90 ( & V_35 ) ;
V_126:
F_91 () ;
F_74 () ;
V_125:
return V_124 ;
}
static void T_6 F_92 ( void )
{
if ( V_113 )
return;
F_93 ( & V_134 ) ;
F_88 () ;
F_87 ( & V_130 ) ;
F_86 () ;
F_85 () ;
F_89 ( & V_35 , & V_127 ) ;
F_90 ( & V_35 ) ;
F_91 () ;
F_74 () ;
}
