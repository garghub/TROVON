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
V_19 -> V_72 = 1 ;
F_41 ( & V_19 -> V_73 , 0 ) ;
F_42 ( & V_19 -> V_74 . V_75 ) ;
V_19 -> V_74 . V_9 . V_76 = V_77 ;
V_19 -> V_74 . V_9 . V_78 = V_79 ;
F_43 ( V_19 , & V_19 -> V_74 , false ) ;
V_19 -> V_80 = 1 ;
if ( F_44 ( ! V_61 ) ) {
V_19 -> V_81 [ 0 ] = '0' ;
V_19 -> V_82 = 0 ;
V_19 -> V_19 . V_61 = V_39 -> V_69 ;
F_45 ( & V_19 -> V_19 , L_6 , V_39 -> V_46 ) ;
V_63 = 1 ;
} else {
if ( V_61 -> V_81 [ 0 ] == '0' ) {
snprintf ( V_19 -> V_81 , sizeof V_19 -> V_81 ,
L_7 , V_62 ) ;
V_19 -> V_82 = 0 ;
} else {
snprintf ( V_19 -> V_81 , sizeof V_19 -> V_81 ,
L_8 , V_61 -> V_81 , V_62 ) ;
if ( V_62 < 15 )
V_19 -> V_82 = V_61 -> V_82 +
( V_62 << ( ( V_61 -> V_83 - 1 ) * 4 ) ) ;
else
V_19 -> V_82 = V_61 -> V_82 +
( 15 << ( ( V_61 -> V_83 - 1 ) * 4 ) ) ;
}
V_19 -> V_19 . V_61 = & V_61 -> V_19 ;
F_45 ( & V_19 -> V_19 , L_9 , V_39 -> V_46 , V_19 -> V_81 ) ;
}
V_19 -> V_84 = V_62 ;
V_19 -> V_39 = V_39 ;
V_19 -> V_61 = V_61 ;
F_42 ( & V_19 -> V_85 ) ;
#ifdef F_46
F_47 ( & V_19 -> V_19 ,
V_86 * 1000 ) ;
V_19 -> V_87 = V_88 ;
V_19 -> V_89 = - V_88 ;
#endif
if ( V_63 )
V_19 -> V_90 = 1 ;
else {
V_19 -> V_90 = V_37 -> V_91 ;
V_19 -> V_92 = F_33 ( V_39 ) ? 1 : 0 ;
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
const struct V_17 * V_93 )
{
unsigned long V_94 = V_88 + V_95 ;
if ( V_36 -> V_70 == V_96 )
return - V_49 ;
if ( V_36 -> V_70 == V_97 )
return - V_98 ;
if ( V_93 && ( V_93 -> V_99 == V_100 ||
V_93 -> V_99 == V_101 ) )
return - V_102 ;
while ( ! F_54 ( V_36 ) ) {
if ( F_55 ( V_88 , V_94 ) )
return - V_103 ;
F_56 ( 15 ) ;
if ( V_36 -> V_70 == V_96 )
return - V_49 ;
if ( V_36 -> V_70 == V_97 )
return - V_98 ;
if ( V_93 && ( V_93 -> V_99 == V_100 ||
V_93 -> V_99 == V_101 ) )
return - V_102 ;
}
return 0 ;
}
int F_57 ( struct V_18 * V_19 )
{
return F_58 ( V_19 ) ;
}
int F_59 ( char * V_104 , unsigned V_105 ,
unsigned char type , void * * V_106 )
{
struct V_107 * V_108 ;
while ( V_105 >= sizeof( struct V_107 ) ) {
V_108 = (struct V_107 * ) V_104 ;
if ( V_108 -> V_76 < 2 ) {
F_2 ( V_109
L_10 ,
V_110 ,
V_108 -> V_78 ,
V_108 -> V_76 ) ;
return - 1 ;
}
if ( V_108 -> V_78 == type ) {
* V_106 = V_108 ;
return 0 ;
}
V_104 += V_108 -> V_76 ;
V_105 -= V_108 -> V_76 ;
}
return - 1 ;
}
void * F_60 ( struct V_18 * V_19 , T_2 V_105 , T_3 V_111 ,
T_4 * V_112 )
{
if ( ! V_19 || ! V_19 -> V_39 )
return NULL ;
return F_61 ( V_19 -> V_39 , V_105 , V_111 , V_112 ) ;
}
void F_62 ( struct V_18 * V_19 , T_2 V_105 , void * V_113 ,
T_4 V_112 )
{
if ( ! V_19 || ! V_19 -> V_39 )
return;
if ( ! V_113 )
return;
F_63 ( V_19 -> V_39 , V_105 , V_113 , V_112 ) ;
}
int F_64 ( void )
{
return V_114 ;
}
static int F_65 ( struct V_115 * V_116 , unsigned long V_117 ,
void * V_26 )
{
struct V_25 * V_19 = V_26 ;
switch ( V_117 ) {
case V_118 :
if ( V_19 -> type == & V_65 )
( void ) F_66 ( F_12 ( V_19 ) ) ;
else if ( V_19 -> type == & V_119 )
F_67 ( F_7 ( V_19 ) ) ;
break;
case V_120 :
if ( V_19 -> type == & V_65 )
F_68 ( F_12 ( V_19 ) ) ;
else if ( V_19 -> type == & V_119 )
F_69 ( F_7 ( V_19 ) ) ;
break;
}
return 0 ;
}
static int F_70 ( void )
{
V_121 = F_71 ( L_11 , NULL ) ;
if ( ! V_121 )
return - V_122 ;
V_123 = F_72 ( L_12 , 0444 ,
V_121 , NULL ,
& V_124 ) ;
if ( ! V_123 ) {
F_73 ( V_121 ) ;
V_121 = NULL ;
return - V_122 ;
}
return 0 ;
}
static void F_74 ( void )
{
F_73 ( V_123 ) ;
F_73 ( V_121 ) ;
}
static int T_5 F_75 ( void )
{
int V_125 ;
if ( V_114 ) {
F_76 ( L_13 , V_110 ) ;
return 0 ;
}
V_125 = F_70 () ;
if ( V_125 )
goto V_126;
F_77 () ;
V_125 = F_78 ( & V_35 ) ;
if ( V_125 )
goto V_127;
V_125 = F_79 ( & V_35 , & V_128 ) ;
if ( V_125 )
goto V_129;
V_125 = F_80 () ;
if ( V_125 )
goto V_130;
V_125 = F_81 ( & V_131 ) ;
if ( V_125 )
goto V_132;
V_125 = F_82 () ;
if ( V_125 )
goto V_133;
V_125 = F_83 () ;
if ( V_125 )
goto V_134;
V_125 = F_84 ( & V_135 , V_136 ) ;
if ( ! V_125 )
goto V_126;
F_85 () ;
V_134:
F_86 () ;
V_133:
F_87 ( & V_131 ) ;
V_132:
F_88 () ;
V_130:
F_89 ( & V_35 , & V_128 ) ;
V_129:
F_90 ( & V_35 ) ;
V_127:
F_91 () ;
F_74 () ;
V_126:
return V_125 ;
}
static void T_6 F_92 ( void )
{
if ( V_114 )
return;
F_93 ( & V_135 ) ;
F_88 () ;
F_87 ( & V_131 ) ;
F_86 () ;
F_85 () ;
F_89 ( & V_35 , & V_128 ) ;
F_90 ( & V_35 ) ;
F_91 () ;
F_74 () ;
}
