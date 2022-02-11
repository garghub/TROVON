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
return F_24 ( V_19 , V_49 ) ;
}
static int F_25 ( struct V_25 * V_19 )
{
return F_26 ( V_19 , V_50 ) ;
}
static int F_27 ( struct V_25 * V_19 )
{
return F_24 ( V_19 , V_51 ) ;
}
static int F_28 ( struct V_25 * V_19 )
{
return F_26 ( V_19 , V_52 ) ;
}
static int F_29 ( struct V_25 * V_19 )
{
return F_24 ( V_19 , V_53 ) ;
}
static int F_30 ( struct V_25 * V_19 )
{
return F_26 ( V_19 , V_54 ) ;
}
static char * F_31 ( struct V_25 * V_19 ,
T_1 * V_55 , T_2 * V_56 , T_3 * V_57 )
{
struct V_18 * V_45 ;
V_45 = F_12 ( V_19 ) ;
return F_32 ( V_58 , L_5 ,
V_45 -> V_39 -> V_46 , V_45 -> V_48 ) ;
}
static unsigned F_33 ( struct V_59 * V_39 )
{
struct V_37 * V_38 = F_34 ( V_39 , struct V_37 , V_60 ) ;
return V_38 -> V_61 ;
}
struct V_18 * F_35 ( struct V_18 * V_62 ,
struct V_59 * V_39 , unsigned V_63 )
{
struct V_18 * V_19 ;
struct V_37 * V_37 = F_13 ( V_39 ) ;
unsigned V_64 = 0 ;
V_19 = F_36 ( sizeof( * V_19 ) , V_58 ) ;
if ( ! V_19 )
return NULL ;
if ( ! F_37 ( V_37 ) ) {
F_17 ( V_19 ) ;
return NULL ;
}
if ( V_37 -> V_29 -> V_65 && V_62 &&
! V_37 -> V_29 -> V_65 ( V_37 , V_19 ) ) {
F_16 ( F_13 ( V_39 ) ) ;
F_17 ( V_19 ) ;
return NULL ;
}
F_38 ( & V_19 -> V_19 ) ;
V_19 -> V_19 . V_39 = & V_35 ;
V_19 -> V_19 . type = & V_66 ;
V_19 -> V_19 . V_67 = V_68 ;
V_19 -> V_19 . V_69 = V_39 -> V_70 -> V_69 ;
F_39 ( & V_19 -> V_19 , F_40 ( V_39 -> V_70 ) ) ;
V_19 -> V_71 = V_72 ;
V_19 -> V_73 = 1 ;
F_41 ( & V_19 -> V_74 , 0 ) ;
F_42 ( & V_19 -> V_75 . V_76 ) ;
V_19 -> V_75 . V_9 . V_77 = V_78 ;
V_19 -> V_75 . V_9 . V_79 = V_80 ;
F_43 ( V_19 , & V_19 -> V_75 , false ) ;
V_19 -> V_81 = 1 ;
if ( F_44 ( ! V_62 ) ) {
V_19 -> V_82 [ 0 ] = '0' ;
V_19 -> V_83 = 0 ;
V_19 -> V_19 . V_62 = V_39 -> V_70 ;
F_45 ( & V_19 -> V_19 , L_6 , V_39 -> V_46 ) ;
V_64 = 1 ;
} else {
if ( V_62 -> V_82 [ 0 ] == '0' ) {
snprintf ( V_19 -> V_82 , sizeof V_19 -> V_82 ,
L_7 , V_63 ) ;
V_19 -> V_83 = 0 ;
} else {
snprintf ( V_19 -> V_82 , sizeof V_19 -> V_82 ,
L_8 , V_62 -> V_82 , V_63 ) ;
if ( V_63 < 15 )
V_19 -> V_83 = V_62 -> V_83 +
( V_63 << ( ( V_62 -> V_84 - 1 ) * 4 ) ) ;
else
V_19 -> V_83 = V_62 -> V_83 +
( 15 << ( ( V_62 -> V_84 - 1 ) * 4 ) ) ;
}
V_19 -> V_19 . V_62 = & V_62 -> V_19 ;
F_45 ( & V_19 -> V_19 , L_9 , V_39 -> V_46 , V_19 -> V_82 ) ;
}
V_19 -> V_85 = V_63 ;
V_19 -> V_39 = V_39 ;
V_19 -> V_62 = V_62 ;
F_42 ( & V_19 -> V_86 ) ;
#ifdef F_46
F_47 ( & V_19 -> V_19 ,
V_87 * 1000 ) ;
V_19 -> V_88 = V_89 ;
V_19 -> V_90 = - V_89 ;
#endif
if ( V_64 )
V_19 -> V_91 = 1 ;
else {
V_19 -> V_91 = V_37 -> V_92 ;
V_19 -> V_93 = F_33 ( V_39 ) ? 1 : 0 ;
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
const struct V_17 * V_94 )
{
unsigned long V_95 = V_89 + V_96 ;
if ( V_36 -> V_71 == V_97 )
return - V_98 ;
if ( V_36 -> V_71 == V_99 )
return - V_100 ;
if ( V_94 && ( V_94 -> V_101 == V_102 ||
V_94 -> V_101 == V_103 ) )
return - V_104 ;
while ( ! F_54 ( V_36 ) ) {
if ( F_55 ( V_89 , V_95 ) )
return - V_105 ;
F_56 ( 15 ) ;
if ( V_36 -> V_71 == V_97 )
return - V_98 ;
if ( V_36 -> V_71 == V_99 )
return - V_100 ;
if ( V_94 && ( V_94 -> V_101 == V_102 ||
V_94 -> V_101 == V_103 ) )
return - V_104 ;
}
return 0 ;
}
int F_57 ( struct V_18 * V_19 )
{
return F_58 ( V_19 ) ;
}
int F_59 ( char * V_106 , unsigned V_107 ,
unsigned char type , void * * V_108 )
{
struct V_109 * V_110 ;
while ( V_107 >= sizeof( struct V_109 ) ) {
V_110 = (struct V_109 * ) V_106 ;
if ( V_110 -> V_77 < 2 ) {
F_2 ( V_111
L_10 ,
V_112 ,
V_110 -> V_79 ,
V_110 -> V_77 ) ;
return - 1 ;
}
if ( V_110 -> V_79 == type ) {
* V_108 = V_110 ;
return 0 ;
}
V_106 += V_110 -> V_77 ;
V_107 -= V_110 -> V_77 ;
}
return - 1 ;
}
void * F_60 ( struct V_18 * V_19 , T_4 V_107 , T_5 V_113 ,
T_6 * V_114 )
{
if ( ! V_19 || ! V_19 -> V_39 )
return NULL ;
return F_61 ( V_19 -> V_39 , V_107 , V_113 , V_114 ) ;
}
void F_62 ( struct V_18 * V_19 , T_4 V_107 , void * V_115 ,
T_6 V_114 )
{
if ( ! V_19 || ! V_19 -> V_39 )
return;
if ( ! V_115 )
return;
F_63 ( V_19 -> V_39 , V_107 , V_115 , V_114 ) ;
}
int F_64 ( void )
{
return V_116 ;
}
static int F_65 ( struct V_117 * V_118 , unsigned long V_119 ,
void * V_26 )
{
struct V_25 * V_19 = V_26 ;
switch ( V_119 ) {
case V_120 :
if ( V_19 -> type == & V_66 )
( void ) F_66 ( F_12 ( V_19 ) ) ;
else if ( V_19 -> type == & V_121 )
F_67 ( F_7 ( V_19 ) ) ;
break;
case V_122 :
if ( V_19 -> type == & V_66 )
F_68 ( F_12 ( V_19 ) ) ;
else if ( V_19 -> type == & V_121 )
F_69 ( F_7 ( V_19 ) ) ;
break;
}
return 0 ;
}
static int F_70 ( void )
{
V_123 = F_71 ( L_11 , NULL ) ;
if ( ! V_123 )
return - V_124 ;
V_125 = F_72 ( L_12 , 0444 ,
V_123 , NULL ,
& V_126 ) ;
if ( ! V_125 ) {
F_73 ( V_123 ) ;
V_123 = NULL ;
return - V_124 ;
}
return 0 ;
}
static void F_74 ( void )
{
F_73 ( V_125 ) ;
F_73 ( V_123 ) ;
}
static int T_7 F_75 ( void )
{
int V_127 ;
if ( V_116 ) {
F_76 ( L_13 , V_112 ) ;
return 0 ;
}
V_127 = F_70 () ;
if ( V_127 )
goto V_128;
F_77 () ;
V_127 = F_78 ( & V_35 ) ;
if ( V_127 )
goto V_129;
V_127 = F_79 ( & V_35 , & V_130 ) ;
if ( V_127 )
goto V_131;
V_127 = F_80 () ;
if ( V_127 )
goto V_132;
V_127 = F_81 ( & V_133 ) ;
if ( V_127 )
goto V_134;
V_127 = F_82 () ;
if ( V_127 )
goto V_135;
V_127 = F_83 () ;
if ( V_127 )
goto V_136;
V_127 = F_84 ( & V_137 , V_138 ) ;
if ( ! V_127 )
goto V_128;
F_85 () ;
V_136:
F_86 () ;
V_135:
F_87 ( & V_133 ) ;
V_134:
F_88 () ;
V_132:
F_89 ( & V_35 , & V_130 ) ;
V_131:
F_90 ( & V_35 ) ;
V_129:
F_91 () ;
F_74 () ;
V_128:
return V_127 ;
}
static void T_8 F_92 ( void )
{
if ( V_116 )
return;
F_93 ( & V_137 ) ;
F_88 () ;
F_87 ( & V_133 ) ;
F_86 () ;
F_85 () ;
F_89 ( & V_35 , & V_130 ) ;
F_90 ( & V_35 ) ;
F_91 () ;
F_74 () ;
}
