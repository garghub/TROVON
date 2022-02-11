static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = & V_5 -> V_9 ;
struct V_10 * V_11 = & V_5 -> V_12 ;
struct V_13 * V_14 ;
if ( V_8 -> V_15 ) {
struct V_16 * V_15 = V_8 -> V_15 ;
F_2 ( V_2 , L_1 , V_5 -> V_17 ,
V_8 -> V_18 ) ;
F_2 ( V_2 , L_2 ,
V_15 -> V_19 ,
V_15 -> V_19 - V_15 -> V_20 ,
V_8 -> V_21 ,
V_8 -> V_21 - V_15 -> V_20 ,
V_15 -> V_22 ,
V_15 -> V_22 - V_15 -> V_20 ) ;
F_2 ( V_2 , L_3 ,
V_15 -> V_20 ,
V_8 -> V_23 ,
V_8 -> V_23 - V_15 -> V_20 ,
V_15 -> V_24 ,
V_15 -> V_24 - V_15 -> V_20 ) ;
F_2 ( V_2 , L_4 ,
V_5 -> V_25 ,
V_5 -> V_26 ,
F_3 ( V_5 ) ) ;
F_2 ( V_2 , L_5 ,
V_5 -> V_27 ,
V_5 -> V_28 ,
V_5 -> V_27 - V_5 -> V_28 ) ;
}
if ( V_11 -> V_15 ) {
struct V_29 * V_15 = V_11 -> V_15 ;
F_2 ( V_2 , L_6 , V_11 -> V_18 ) ;
F_2 ( V_2 , L_2 ,
V_15 -> V_19 ,
V_15 -> V_19 - V_15 -> V_20 ,
V_11 -> V_21 ,
V_11 -> V_21 - V_15 -> V_20 ,
V_15 -> V_22 ,
V_15 -> V_22 - V_15 -> V_20 ) ;
F_2 ( V_2 , L_7 ,
V_15 -> V_20 ,
V_11 -> V_23 ,
V_11 -> V_23 - V_15 -> V_20 ,
V_15 -> V_24 ,
V_15 -> V_24 - V_15 -> V_20 ) ;
}
F_2 ( V_2 , L_8
L_9
L_10 ,
V_5 -> V_30 . V_31 , V_5 -> V_30 . V_32 ,
F_4 ( & V_5 -> V_33 ) ,
F_5 ( & V_5 -> V_34 ) ,
V_5 -> V_35 ,
V_5 -> V_36 ,
V_5 -> V_37 ,
V_5 -> V_34 . V_38 ,
V_39 ) ;
V_14 = F_6 ( V_5 -> V_40 -> V_41 , V_5 -> V_17 ) ;
F_2 ( V_2 , L_11 ,
V_5 -> V_42 , V_5 -> V_43 ,
F_4 ( & V_5 -> V_44 ) ,
F_7 ( V_14 ) ? L_12 : L_13 ) ;
return 0 ;
}
static T_1
F_8 ( struct V_45 * V_46 , const char T_2 * V_47 , T_3 V_48 ,
T_4 * V_49 )
{
struct V_4 * V_5 =
( (struct V_1 * ) V_46 -> V_50 ) -> V_6 ;
int V_51 ;
char V_52 [ V_53 ] ;
if ( * V_49 != 0 )
return 0 ;
if ( V_48 >= sizeof( V_52 ) )
return - V_54 ;
V_51 = F_9 ( V_52 ,
sizeof( V_52 ) - 1 ,
V_49 ,
V_47 ,
V_48 ) ;
if ( V_51 < 0 )
return V_51 ;
V_52 [ V_51 ] = '\0' ;
if ( ! strncmp ( V_52 , V_55 , sizeof( V_55 ) - 1 ) )
F_10 ( 0 , ( void * ) V_5 ) ;
else {
F_11 ( L_14 ,
V_5 -> V_17 ) ;
V_48 = - V_56 ;
}
return V_48 ;
}
static int F_12 ( struct V_57 * V_57 , struct V_45 * V_46 )
{
int V_58 ;
void * V_5 = NULL ;
if ( V_57 -> V_59 )
V_5 = V_57 -> V_59 ;
V_58 = F_13 ( V_46 , F_1 , V_5 ) ;
V_46 -> V_60 |= V_61 ;
return V_58 ;
}
static void F_14 ( struct V_62 * V_40 )
{
struct V_63 * V_64 ;
int V_65 ;
if ( F_15 ( V_66 ) )
return;
V_40 -> V_67 = F_16 ( V_40 -> V_41 -> V_68 ,
V_66 ) ;
if ( ! F_15 ( V_40 -> V_67 ) ) {
for ( V_65 = 0 ; V_65 < V_40 -> V_69 ; ++ V_65 ) {
char V_70 [ sizeof( L_15 ) + 4 ] ;
snprintf ( V_70 , sizeof( V_70 ) , L_16 , V_65 ) ;
V_64 = F_17 ( V_70 ,
V_71 | V_72 ,
V_40 -> V_67 ,
& V_40 -> V_73 [ V_65 ] ,
& V_74 ) ;
if ( F_15 ( V_64 ) )
F_11 ( L_17 ,
F_18 ( V_64 ) ) ;
}
} else
F_19 ( V_40 -> V_41 ,
L_18 ,
F_18 ( V_40 -> V_67 ) ) ;
}
static void F_20 ( struct V_62 * V_40 )
{
if ( F_15 ( V_66 ) )
return;
if ( ! F_15 ( V_40 -> V_67 ) )
F_21 ( V_40 -> V_67 ) ;
V_40 -> V_67 = NULL ;
}
static int F_22 ( struct V_75 * V_41 )
{
struct V_76 * V_77 = F_23 ( & V_41 -> V_41 ) ;
F_24 ( V_77 , V_78 ) ;
F_25 ( V_77 ) ;
if ( V_77 -> V_40 ) {
F_26 ( & V_41 -> V_41 . V_79 , V_80 ) ;
F_27 ( V_77 -> V_40 ) ;
F_28 ( V_81 , V_41 -> V_82 , L_19 ) ;
F_29 ( V_77 -> V_40 ) ;
V_77 -> V_40 = NULL ;
}
F_30 ( V_77 -> V_83 ) ;
F_30 ( V_77 ) ;
F_31 ( & V_41 -> V_41 , NULL ) ;
return 0 ;
}
static int F_32 ( struct V_75 * V_41 ,
const struct V_84 * V_17 )
{
const char * V_85 ;
struct V_86 V_87 ;
int V_88 ;
int V_89 ;
const char * V_90 ;
struct V_76 * V_77 = F_33 ( sizeof( struct V_76 ) ,
V_91 ) ;
if ( ! V_77 ) {
F_34 ( V_41 , - V_92 ,
L_20 ) ;
return - V_92 ;
}
V_77 -> V_41 = V_41 ;
F_31 ( & V_41 -> V_41 , V_77 ) ;
V_89 = 1 ;
do {
V_88 = F_35 ( & V_87 ) ;
if ( V_88 ) {
F_34 ( V_41 , V_88 , L_21 ) ;
goto V_93;
}
V_88 = F_36 ( V_87 , V_41 -> V_82 , L_22 , L_23 , V_89 ) ;
if ( V_88 ) {
V_85 = L_24 ;
goto V_94;
}
V_88 = F_36 ( V_87 , V_41 -> V_82 , L_25 ,
L_23 , V_89 ) ;
if ( V_88 ) {
V_85 = L_26 ;
goto V_94;
}
V_88 = F_36 ( V_87 , V_41 -> V_82 , L_27 ,
L_23 , V_89 ) ;
if ( V_88 ) {
V_85 = L_28 ;
goto V_94;
}
V_88 = F_36 ( V_87 , V_41 -> V_82 ,
L_29 ,
L_23 , 1 ) ;
if ( V_88 ) {
V_85 = L_30 ;
goto V_94;
}
V_88 = F_36 ( V_87 , V_41 -> V_82 ,
L_31 , L_23 , 1 ) ;
if ( V_88 ) {
V_85 = L_32 ;
goto V_94;
}
V_88 = F_36 ( V_87 , V_41 -> V_82 ,
L_33 , L_23 , 0 ) ;
if ( V_88 ) {
V_85 = L_34 ;
goto V_94;
}
V_88 = F_36 ( V_87 , V_41 -> V_82 ,
L_35 , L_23 , 1 ) ;
if ( V_88 ) {
V_85 = L_36 ;
goto V_94;
}
V_88 = F_37 ( V_87 , 0 ) ;
} while ( V_88 == - V_95 );
if ( V_88 ) {
F_34 ( V_41 , V_88 , L_37 ) ;
goto V_93;
}
V_88 = F_36 ( V_81 , V_41 -> V_82 ,
L_38 ,
L_39 , V_96 ) ;
if ( V_88 )
F_38 ( L_40 ) ;
V_88 = F_36 ( V_81 , V_41 -> V_82 ,
L_41 , L_39 , V_97 ) ;
if ( V_88 )
F_38 ( L_42 ) ;
V_90 = F_39 ( V_81 , V_41 -> V_82 , L_43 , NULL ) ;
if ( F_40 ( V_90 ) ) {
V_88 = F_18 ( V_90 ) ;
F_34 ( V_41 , V_88 , L_44 ) ;
goto V_93;
}
V_77 -> V_83 = V_90 ;
V_88 = F_41 ( V_41 , V_98 ) ;
if ( V_88 )
goto V_93;
V_77 -> V_31 = V_98 ;
V_88 = F_42 ( V_77 ) ;
if ( V_88 )
goto V_93;
return 0 ;
V_94:
F_37 ( V_87 , 1 ) ;
F_34 ( V_41 , V_88 , L_45 , V_85 ) ;
V_93:
F_38 ( L_46 ) ;
F_22 ( V_41 ) ;
return V_88 ;
}
static int F_43 ( struct V_75 * V_99 ,
struct V_100 * V_101 )
{
struct V_76 * V_77 = F_23 ( & V_99 -> V_41 ) ;
if ( ! V_77 )
return 0 ;
if ( F_44 ( V_101 , L_47 , V_77 -> V_83 ) )
return - V_92 ;
if ( ! V_77 -> V_40 )
return 0 ;
return F_44 ( V_101 , L_48 , V_77 -> V_40 -> V_41 -> V_68 ) ;
}
static int F_42 ( struct V_76 * V_77 )
{
int V_88 ;
long V_102 ;
struct V_75 * V_41 = V_77 -> V_41 ;
struct V_62 * V_40 ;
if ( V_77 -> V_40 != NULL )
return 0 ;
V_88 = F_45 ( V_81 , V_41 -> V_82 , L_49 , L_50 , & V_102 ) ;
if ( V_88 != 1 ) {
F_34 ( V_41 , V_88 , L_51 ) ;
return ( V_88 < 0 ) ? V_88 : - V_56 ;
}
V_40 = F_46 ( & V_41 -> V_41 , V_41 -> V_103 , V_102 ) ;
if ( F_40 ( V_40 ) ) {
V_88 = F_18 ( V_40 ) ;
F_34 ( V_41 , V_88 , L_52 ) ;
return V_88 ;
}
V_77 -> V_40 = V_40 ;
F_26 ( & V_41 -> V_41 . V_79 , V_104 ) ;
return 0 ;
}
static void F_47 ( struct V_76 * V_77 )
{
if ( V_77 -> V_40 ) {
F_27 ( V_77 -> V_40 ) ;
#ifdef F_48
F_20 ( V_77 -> V_40 ) ;
#endif
F_49 ( V_77 -> V_40 ) ;
}
}
static void F_50 ( struct V_76 * V_77 )
{
if ( V_77 -> V_40 )
F_51 ( V_77 ) ;
}
static inline void F_52 ( struct V_76 * V_77 ,
enum V_105 V_31 )
{
struct V_75 * V_41 = V_77 -> V_41 ;
F_38 ( L_53 , V_41 -> V_82 , F_53 ( V_31 ) ) ;
V_77 -> V_31 = V_31 ;
if ( ! V_77 -> V_106 )
F_41 ( V_41 , V_31 ) ;
}
static void F_24 ( struct V_76 * V_77 ,
enum V_105 V_31 )
{
while ( V_77 -> V_31 != V_31 ) {
switch ( V_77 -> V_31 ) {
case V_78 :
switch ( V_31 ) {
case V_98 :
case V_107 :
F_54 ( L_54 ,
V_77 -> V_41 -> V_82 ) ;
F_52 ( V_77 , V_98 ) ;
break;
case V_108 :
F_52 ( V_77 , V_108 ) ;
break;
default:
F_55 () ;
}
break;
case V_98 :
switch ( V_31 ) {
case V_107 :
F_50 ( V_77 ) ;
F_52 ( V_77 , V_107 ) ;
break;
case V_108 :
case V_78 :
F_52 ( V_77 , V_108 ) ;
break;
default:
F_55 () ;
}
break;
case V_107 :
switch ( V_31 ) {
case V_98 :
case V_108 :
case V_78 :
F_47 ( V_77 ) ;
F_52 ( V_77 , V_108 ) ;
break;
default:
F_55 () ;
}
break;
case V_108 :
switch ( V_31 ) {
case V_98 :
case V_107 :
case V_78 :
F_52 ( V_77 , V_78 ) ;
break;
default:
F_55 () ;
}
break;
default:
F_55 () ;
}
}
}
static void F_56 ( struct V_75 * V_41 ,
enum V_105 V_109 )
{
struct V_76 * V_77 = F_23 ( & V_41 -> V_41 ) ;
F_38 ( L_53 , V_41 -> V_110 , F_53 ( V_109 ) ) ;
V_77 -> V_109 = V_109 ;
switch ( V_109 ) {
case V_111 :
F_24 ( V_77 , V_98 ) ;
break;
case V_112 :
break;
case V_107 :
F_24 ( V_77 , V_107 ) ;
break;
case V_108 :
F_24 ( V_77 , V_108 ) ;
break;
case V_78 :
F_24 ( V_77 , V_78 ) ;
if ( F_57 ( V_41 ) )
break;
case V_113 :
F_24 ( V_77 , V_78 ) ;
F_58 ( & V_41 -> V_41 ) ;
break;
default:
F_34 ( V_41 , - V_56 , L_55 ,
V_109 ) ;
break;
}
}
static void F_59 ( struct V_75 * V_41 ,
unsigned long * V_114 , unsigned long * V_115 )
{
char * V_116 , * V_117 ;
unsigned long V_118 , V_119 ;
char * V_120 ;
* V_114 = ~ 0UL ;
* V_115 = 0 ;
V_120 = F_39 ( V_81 , V_41 -> V_82 , L_56 , NULL ) ;
if ( F_40 ( V_120 ) )
return;
V_116 = V_120 ;
V_118 = F_60 ( V_116 , & V_117 , 10 ) ;
if ( ( V_116 == V_117 ) || ( * V_117 != ',' ) )
goto V_93;
V_116 = V_117 + 1 ;
V_119 = F_60 ( V_116 , & V_117 , 10 ) ;
if ( ( V_116 == V_117 ) || ( * V_117 != '\0' ) )
goto V_93;
* V_114 = V_118 ;
* V_115 = V_119 ;
F_30 ( V_120 ) ;
return;
V_93:
F_11 ( L_57 ) ;
F_30 ( V_120 ) ;
}
static int F_61 ( struct V_75 * V_41 , T_5 V_121 [] )
{
char * V_116 , * V_117 , * V_122 ;
int V_65 ;
V_122 = V_116 = F_39 ( V_81 , V_41 -> V_82 , L_58 , NULL ) ;
if ( F_40 ( V_122 ) )
return F_18 ( V_122 ) ;
for ( V_65 = 0 ; V_65 < V_123 ; V_65 ++ ) {
V_121 [ V_65 ] = F_60 ( V_116 , & V_117 , 16 ) ;
if ( ( V_116 == V_117 ) || ( * V_117 != ( ( V_65 == V_123 - 1 ) ? '\0' : ':' ) ) ) {
F_30 ( V_122 ) ;
return - V_124 ;
}
V_116 = V_117 + 1 ;
}
F_30 ( V_122 ) ;
return 0 ;
}
static void F_62 ( struct V_125 * V_126 ,
const char * * V_127 , unsigned int V_51 )
{
struct V_62 * V_40 = F_63 ( V_126 , struct V_62 , V_128 ) ;
struct V_75 * V_41 = F_64 ( V_40 ) ;
unsigned long V_35 ;
unsigned long V_36 ;
unsigned int V_129 ;
F_59 ( V_41 , & V_35 , & V_36 ) ;
for ( V_129 = 0 ; V_129 < V_40 -> V_69 ; V_129 ++ ) {
struct V_4 * V_5 = & V_40 -> V_73 [ V_129 ] ;
V_5 -> V_35 = V_35 ;
V_5 -> V_36 = V_36 ;
if ( ! F_65 ( & V_5 -> V_34 , V_39 ) &&
V_5 -> V_37 > V_5 -> V_35 ) {
V_5 -> V_37 = V_5 -> V_35 ;
}
}
}
static int F_66 ( struct V_75 * V_41 , struct V_62 * V_40 )
{
int V_88 = 0 ;
char * V_130 ;
unsigned V_131 = strlen ( V_41 -> V_82 ) + sizeof( L_59 ) ;
if ( V_40 -> V_128 . V_130 )
return - V_132 ;
V_130 = F_67 ( V_131 , V_91 ) ;
if ( ! V_130 )
return - V_92 ;
snprintf ( V_130 , V_131 , L_60 , V_41 -> V_82 ) ;
V_40 -> V_128 . V_130 = V_130 ;
V_40 -> V_128 . V_133 = F_62 ;
V_88 = F_68 ( & V_40 -> V_128 ) ;
if ( V_88 ) {
F_69 ( L_61 , V_40 -> V_128 . V_130 ) ;
F_30 ( V_130 ) ;
V_40 -> V_128 . V_130 = NULL ;
V_40 -> V_128 . V_133 = NULL ;
}
return V_88 ;
}
static void F_27 ( struct V_62 * V_40 )
{
if ( V_40 -> V_128 . V_130 ) {
F_70 ( & V_40 -> V_128 ) ;
F_30 ( V_40 -> V_128 . V_130 ) ;
V_40 -> V_128 . V_130 = NULL ;
}
}
static void F_25 ( struct V_76 * V_77 )
{
if ( V_77 -> V_106 ) {
F_70 ( & V_77 -> V_134 ) ;
F_30 ( V_77 -> V_134 . V_130 ) ;
}
V_77 -> V_106 = 0 ;
}
static void F_71 ( struct V_125 * V_126 ,
const char * * V_127 ,
unsigned int V_135 )
{
struct V_76 * V_77 = F_63 ( V_126 ,
struct V_76 ,
V_134 ) ;
char * V_136 ;
unsigned int V_51 ;
V_136 = F_39 ( V_81 , V_77 -> V_41 -> V_82 , L_19 , & V_51 ) ;
if ( F_40 ( V_136 ) )
return;
if ( V_51 == sizeof( L_62 ) - 1 && ! memcmp ( V_136 , L_62 , V_51 ) ) {
F_41 ( V_77 -> V_41 , V_77 -> V_31 ) ;
F_25 ( V_77 ) ;
}
F_30 ( V_136 ) ;
}
static void F_51 ( struct V_76 * V_77 )
{
int V_88 ;
struct V_75 * V_41 = V_77 -> V_41 ;
unsigned long V_35 , V_36 ;
unsigned int V_129 ;
unsigned int V_137 ;
struct V_4 * V_5 ;
V_88 = F_45 ( V_81 , V_41 -> V_110 ,
L_63 ,
L_39 , & V_137 ) ;
if ( V_88 < 0 ) {
V_137 = 1 ;
} else if ( V_137 > V_97 ) {
F_34 ( V_41 , V_88 ,
L_64 ,
V_137 , V_97 ) ;
return;
}
V_88 = F_61 ( V_41 , V_77 -> V_40 -> V_138 ) ;
if ( V_88 ) {
F_34 ( V_41 , V_88 , L_65 , V_41 -> V_82 ) ;
return;
}
F_59 ( V_41 , & V_35 , & V_36 ) ;
F_27 ( V_77 -> V_40 ) ;
F_66 ( V_41 , V_77 -> V_40 ) ;
F_72 ( V_77 ) ;
V_77 -> V_40 -> V_73 = F_73 ( V_137 *
sizeof( struct V_4 ) ) ;
if ( ! V_77 -> V_40 -> V_73 ) {
F_34 ( V_41 , - V_92 ,
L_66 ) ;
return;
}
V_77 -> V_40 -> V_69 = V_137 ;
V_77 -> V_40 -> V_139 = V_137 ;
for ( V_129 = 0 ; V_129 < V_137 ; ++ V_129 ) {
V_5 = & V_77 -> V_40 -> V_73 [ V_129 ] ;
V_5 -> V_40 = V_77 -> V_40 ;
V_5 -> V_17 = V_129 ;
snprintf ( V_5 -> V_68 , sizeof( V_5 -> V_68 ) , L_67 ,
V_77 -> V_40 -> V_41 -> V_68 , V_5 -> V_17 ) ;
V_88 = F_74 ( V_5 ) ;
if ( V_88 ) {
V_77 -> V_40 -> V_69 = V_129 ;
goto V_88;
}
V_5 -> V_35 = V_35 ;
V_5 -> V_37 = V_35 ;
V_5 -> V_36 = V_36 ;
V_88 = F_75 ( V_77 , V_5 ) ;
if ( V_88 ) {
F_76 ( V_5 ) ;
V_77 -> V_40 -> V_69 = V_129 ;
goto V_88;
}
}
#ifdef F_48
F_14 ( V_77 -> V_40 ) ;
#endif
F_77 () ;
F_78 ( V_77 -> V_40 -> V_41 , V_137 ) ;
F_79 ( V_77 -> V_40 -> V_41 , V_137 ) ;
F_80 () ;
F_81 ( V_77 -> V_40 ) ;
F_25 ( V_77 ) ;
V_88 = F_82 ( V_41 , & V_77 -> V_134 ,
F_71 ,
L_68 , V_41 -> V_82 , L_19 ) ;
if ( ! V_88 )
V_77 -> V_106 = 1 ;
F_83 ( V_77 -> V_40 -> V_41 ) ;
return;
V_88:
if ( V_77 -> V_40 -> V_69 > 0 )
F_49 ( V_77 -> V_40 ) ;
F_84 ( V_77 -> V_40 -> V_73 ) ;
V_77 -> V_40 -> V_73 = NULL ;
V_77 -> V_40 -> V_69 = 0 ;
return;
}
static int F_75 ( struct V_76 * V_77 , struct V_4 * V_5 )
{
struct V_75 * V_41 = V_77 -> V_41 ;
unsigned int V_69 = V_5 -> V_40 -> V_69 ;
unsigned long V_140 , V_141 ;
unsigned int V_142 , V_143 ;
int V_88 ;
char * V_144 ;
T_3 V_145 ;
const T_3 V_146 = 11 ;
if ( V_69 == 1 ) {
V_144 = F_33 ( strlen ( V_41 -> V_110 ) + 1 , V_91 ) ;
if ( ! V_144 ) {
F_34 ( V_41 , - V_92 ,
L_69 ) ;
return - V_92 ;
}
strcpy ( V_144 , V_41 -> V_110 ) ;
} else {
V_145 = strlen ( V_41 -> V_110 ) + V_146 ;
V_144 = F_33 ( V_145 , V_91 ) ;
if ( ! V_144 ) {
F_34 ( V_41 , - V_92 ,
L_69 ) ;
return - V_92 ;
}
snprintf ( V_144 , V_145 , L_70 , V_41 -> V_110 ,
V_5 -> V_17 ) ;
}
V_88 = F_85 ( V_81 , V_144 ,
L_71 , L_72 , & V_140 ,
L_73 , L_72 , & V_141 , NULL ) ;
if ( V_88 ) {
F_34 ( V_41 , V_88 ,
L_74 ,
V_144 ) ;
goto V_88;
}
V_88 = F_85 ( V_81 , V_144 ,
L_75 , L_39 , & V_142 ,
L_76 , L_39 , & V_143 , NULL ) ;
if ( V_88 < 0 ) {
V_88 = F_45 ( V_81 , V_144 ,
L_77 , L_39 , & V_142 ) ;
if ( V_88 < 0 ) {
F_34 ( V_41 , V_88 ,
L_78 ,
V_144 ) ;
goto V_88;
}
V_143 = V_142 ;
}
V_88 = F_86 ( V_5 , V_140 , V_141 ,
V_142 , V_143 ) ;
if ( V_88 ) {
F_34 ( V_41 , V_88 ,
L_79 ,
V_140 , V_141 ,
V_142 , V_143 ) ;
goto V_88;
}
V_88 = 0 ;
V_88:
F_30 ( V_144 ) ;
return V_88 ;
}
static int F_72 ( struct V_76 * V_77 )
{
struct V_62 * V_40 = V_77 -> V_40 ;
struct V_75 * V_41 = V_77 -> V_41 ;
unsigned int V_147 ;
int V_88 , V_148 ;
V_88 = F_45 ( V_81 , V_41 -> V_110 , L_80 , L_39 ,
& V_147 ) ;
if ( V_88 == - V_124 ) {
V_88 = 0 ;
V_147 = 0 ;
}
if ( V_88 < 0 ) {
F_34 ( V_41 , V_88 , L_81 ,
V_41 -> V_110 ) ;
return V_88 ;
}
if ( ! V_147 )
return - V_149 ;
if ( F_45 ( V_81 , V_41 -> V_110 ,
L_82 , L_23 , & V_148 ) < 0 )
V_148 = 0 ;
if ( ! V_148 ) {
V_77 -> V_40 -> V_150 = F_87 ( 30 ) ;
V_77 -> V_40 -> V_151 = 0 ;
}
if ( F_45 ( V_81 , V_41 -> V_110 , L_22 ,
L_23 , & V_148 ) < 0 )
V_148 = 0 ;
V_40 -> V_152 = ! ! V_148 ;
V_40 -> V_153 = 0 ;
V_40 -> V_154 = 0 ;
if ( F_45 ( V_81 , V_41 -> V_110 , L_25 ,
L_23 , & V_148 ) < 0 )
V_148 = 0 ;
if ( V_148 )
V_40 -> V_153 |= F_88 ( V_155 ) ;
if ( F_45 ( V_81 , V_41 -> V_110 , L_83 ,
L_23 , & V_148 ) < 0 )
V_148 = 0 ;
if ( V_148 )
V_40 -> V_154 |= F_88 ( V_155 ) ;
if ( F_45 ( V_81 , V_41 -> V_110 , L_27 ,
L_23 , & V_148 ) < 0 )
V_148 = 0 ;
if ( V_148 )
V_40 -> V_153 |= F_88 ( V_156 ) ;
if ( F_45 ( V_81 , V_41 -> V_110 , L_84 ,
L_23 , & V_148 ) < 0 )
V_148 = 0 ;
if ( V_148 )
V_40 -> V_154 |= F_88 ( V_156 ) ;
if ( V_40 -> V_153 & V_40 -> V_154 ) {
F_34 ( V_41 , V_88 ,
L_85
L_86 ,
V_41 -> V_110 ) ;
return - V_149 ;
}
if ( F_45 ( V_81 , V_41 -> V_110 , L_87 ,
L_23 , & V_148 ) < 0 )
V_148 = 0 ;
V_40 -> V_157 = ! V_148 ;
if ( F_45 ( V_81 , V_41 -> V_110 , L_29 ,
L_23 , & V_148 ) < 0 )
V_148 = 0 ;
V_40 -> V_158 = ! ! V_148 ;
if ( F_45 ( V_81 , V_41 -> V_110 , L_88 ,
L_23 , & V_148 ) < 0 )
V_148 = 0 ;
V_40 -> V_159 = ! ! V_148 ;
return 0 ;
}
int F_89 ( void )
{
return F_90 ( & V_160 ) ;
}
void F_91 ( void )
{
return F_92 ( & V_160 ) ;
}
