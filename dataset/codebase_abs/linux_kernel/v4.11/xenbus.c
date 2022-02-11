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
static int F_14 ( struct V_1 * V_2 , void * V_3 )
{
struct V_62 * V_40 = V_2 -> V_6 ;
F_15 ( V_40 , V_2 ) ;
return 0 ;
}
static int F_16 ( struct V_57 * V_57 , struct V_45 * V_46 )
{
return F_13 ( V_46 , F_14 , V_57 -> V_59 ) ;
}
static void F_17 ( struct V_62 * V_40 )
{
struct V_63 * V_64 ;
int V_65 ;
if ( F_18 ( V_66 ) )
return;
V_40 -> V_67 = F_19 ( V_40 -> V_41 -> V_68 ,
V_66 ) ;
if ( ! F_18 ( V_40 -> V_67 ) ) {
for ( V_65 = 0 ; V_65 < V_40 -> V_69 ; ++ V_65 ) {
char V_70 [ sizeof( L_15 ) + 4 ] ;
snprintf ( V_70 , sizeof( V_70 ) , L_16 , V_65 ) ;
V_64 = F_20 ( V_70 ,
V_71 | V_72 ,
V_40 -> V_67 ,
& V_40 -> V_73 [ V_65 ] ,
& V_74 ) ;
if ( F_18 ( V_64 ) )
F_11 ( L_17 ,
F_21 ( V_64 ) ) ;
}
if ( V_40 -> V_75 ) {
V_64 = F_20 ( L_18 ,
V_71 ,
V_40 -> V_67 ,
V_40 ,
& V_76 ) ;
if ( F_18 ( V_64 ) )
F_11 ( L_19 ,
F_21 ( V_64 ) ) ;
}
} else
F_22 ( V_40 -> V_41 ,
L_20 ,
F_21 ( V_40 -> V_67 ) ) ;
}
static void F_23 ( struct V_62 * V_40 )
{
if ( F_18 ( V_66 ) )
return;
if ( ! F_18 ( V_40 -> V_67 ) )
F_24 ( V_40 -> V_67 ) ;
V_40 -> V_67 = NULL ;
}
static int F_25 ( struct V_77 * V_41 )
{
struct V_78 * V_79 = F_26 ( & V_41 -> V_41 ) ;
F_27 ( V_79 , V_80 ) ;
F_28 ( V_79 ) ;
if ( V_79 -> V_40 ) {
F_29 ( & V_41 -> V_41 . V_81 , V_82 ) ;
F_30 ( V_79 -> V_40 ) ;
F_31 ( V_83 , V_41 -> V_84 , L_21 ) ;
F_32 ( V_79 -> V_40 ) ;
V_79 -> V_40 = NULL ;
}
F_33 ( V_79 -> V_85 ) ;
F_33 ( V_79 ) ;
F_34 ( & V_41 -> V_41 , NULL ) ;
return 0 ;
}
static int F_35 ( struct V_77 * V_41 ,
const struct V_86 * V_17 )
{
const char * V_87 ;
struct V_88 V_89 ;
int V_90 ;
int V_91 ;
const char * V_92 ;
struct V_78 * V_79 = F_36 ( sizeof( struct V_78 ) ,
V_93 ) ;
if ( ! V_79 ) {
F_37 ( V_41 , - V_94 ,
L_22 ) ;
return - V_94 ;
}
V_79 -> V_41 = V_41 ;
F_34 ( & V_41 -> V_41 , V_79 ) ;
V_79 -> V_31 = V_95 ;
V_90 = F_38 ( V_41 , V_95 ) ;
if ( V_90 )
goto V_96;
V_91 = 1 ;
do {
V_90 = F_39 ( & V_89 ) ;
if ( V_90 ) {
F_37 ( V_41 , V_90 , L_23 ) ;
goto V_96;
}
V_90 = F_40 ( V_89 , V_41 -> V_84 , L_24 , L_25 , V_91 ) ;
if ( V_90 ) {
V_87 = L_26 ;
goto V_97;
}
V_90 = F_40 ( V_89 , V_41 -> V_84 , L_27 ,
L_25 , V_91 ) ;
if ( V_90 ) {
V_87 = L_28 ;
goto V_97;
}
V_90 = F_40 ( V_89 , V_41 -> V_84 , L_29 ,
L_25 , V_91 ) ;
if ( V_90 ) {
V_87 = L_30 ;
goto V_97;
}
V_90 = F_40 ( V_89 , V_41 -> V_84 ,
L_31 ,
L_25 , 1 ) ;
if ( V_90 ) {
V_87 = L_32 ;
goto V_97;
}
V_90 = F_40 ( V_89 , V_41 -> V_84 ,
L_33 , L_25 , 1 ) ;
if ( V_90 ) {
V_87 = L_34 ;
goto V_97;
}
V_90 = F_40 ( V_89 , V_41 -> V_84 ,
L_35 , L_25 , 0 ) ;
if ( V_90 ) {
V_87 = L_36 ;
goto V_97;
}
V_90 = F_40 ( V_89 , V_41 -> V_84 ,
L_37 , L_25 , 1 ) ;
if ( V_90 ) {
V_87 = L_38 ;
goto V_97;
}
V_90 = F_40 ( V_89 , V_41 -> V_84 ,
L_39 ,
L_25 , 1 ) ;
if ( V_90 ) {
V_87 = L_40 ;
goto V_97;
}
V_90 = F_41 ( V_89 , 0 ) ;
} while ( V_90 == - V_98 );
if ( V_90 ) {
F_37 ( V_41 , V_90 , L_41 ) ;
goto V_96;
}
V_90 = F_40 ( V_83 , V_41 -> V_84 ,
L_42 ,
L_43 , V_99 ) ;
if ( V_90 )
F_42 ( L_44 ) ;
V_90 = F_40 ( V_83 , V_41 -> V_84 ,
L_45 , L_43 , V_100 ) ;
if ( V_90 )
F_42 ( L_46 ) ;
V_90 = F_40 ( V_83 , V_41 -> V_84 ,
L_47 ,
L_43 , true ) ;
if ( V_90 )
F_42 ( L_48 ) ;
V_92 = F_43 ( V_83 , V_41 -> V_84 , L_49 , NULL ) ;
if ( F_44 ( V_92 ) ) {
V_90 = F_21 ( V_92 ) ;
F_37 ( V_41 , V_90 , L_50 ) ;
goto V_96;
}
V_79 -> V_85 = V_92 ;
V_90 = F_45 ( V_79 ) ;
if ( V_90 )
goto V_96;
return 0 ;
V_97:
F_41 ( V_89 , 1 ) ;
F_37 ( V_41 , V_90 , L_51 , V_87 ) ;
V_96:
F_42 ( L_52 ) ;
F_25 ( V_41 ) ;
return V_90 ;
}
static int F_46 ( struct V_77 * V_101 ,
struct V_102 * V_103 )
{
struct V_78 * V_79 = F_26 ( & V_101 -> V_41 ) ;
if ( ! V_79 )
return 0 ;
if ( F_47 ( V_103 , L_53 , V_79 -> V_85 ) )
return - V_94 ;
if ( ! V_79 -> V_40 )
return 0 ;
return F_47 ( V_103 , L_54 , V_79 -> V_40 -> V_41 -> V_68 ) ;
}
static int F_45 ( struct V_78 * V_79 )
{
int V_90 ;
long V_104 ;
struct V_77 * V_41 = V_79 -> V_41 ;
struct V_62 * V_40 ;
if ( V_79 -> V_40 != NULL )
return 0 ;
V_90 = F_48 ( V_83 , V_41 -> V_84 , L_55 , L_56 , & V_104 ) ;
if ( V_90 != 1 ) {
F_37 ( V_41 , V_90 , L_57 ) ;
return ( V_90 < 0 ) ? V_90 : - V_56 ;
}
V_40 = F_49 ( & V_41 -> V_41 , V_41 -> V_105 , V_104 ) ;
if ( F_44 ( V_40 ) ) {
V_90 = F_21 ( V_40 ) ;
F_37 ( V_41 , V_90 , L_58 ) ;
return V_90 ;
}
V_79 -> V_40 = V_40 ;
F_29 ( & V_41 -> V_41 . V_81 , V_106 ) ;
return 0 ;
}
static void F_50 ( struct V_78 * V_79 )
{
struct V_62 * V_40 = V_79 -> V_40 ;
if ( V_40 ) {
unsigned int V_69 = V_40 -> V_69 ;
unsigned int V_107 ;
F_30 ( V_40 ) ;
#ifdef F_51
F_23 ( V_40 ) ;
#endif
F_52 ( V_40 ) ;
V_40 -> V_69 = 0 ;
F_53 () ;
for ( V_107 = 0 ; V_107 < V_69 ; ++ V_107 )
F_54 ( & V_40 -> V_73 [ V_107 ] ) ;
F_55 ( V_40 -> V_73 ) ;
V_40 -> V_73 = NULL ;
F_56 ( V_40 ) ;
}
}
static void F_57 ( struct V_78 * V_79 )
{
if ( V_79 -> V_40 )
F_58 ( V_79 ) ;
}
static inline void F_59 ( struct V_78 * V_79 ,
enum V_108 V_31 )
{
struct V_77 * V_41 = V_79 -> V_41 ;
F_42 ( L_59 , V_41 -> V_84 , F_60 ( V_31 ) ) ;
V_79 -> V_31 = V_31 ;
if ( ! V_79 -> V_109 )
F_38 ( V_41 , V_31 ) ;
}
static void F_27 ( struct V_78 * V_79 ,
enum V_108 V_31 )
{
while ( V_79 -> V_31 != V_31 ) {
switch ( V_79 -> V_31 ) {
case V_95 :
switch ( V_31 ) {
case V_110 :
case V_111 :
case V_112 :
F_59 ( V_79 , V_110 ) ;
break;
case V_80 :
F_59 ( V_79 , V_80 ) ;
break;
default:
F_61 () ;
}
break;
case V_80 :
switch ( V_31 ) {
case V_110 :
case V_111 :
F_59 ( V_79 , V_110 ) ;
break;
case V_112 :
F_59 ( V_79 , V_112 ) ;
break;
default:
F_61 () ;
}
break;
case V_110 :
switch ( V_31 ) {
case V_111 :
F_57 ( V_79 ) ;
F_59 ( V_79 , V_111 ) ;
break;
case V_112 :
case V_80 :
F_59 ( V_79 , V_112 ) ;
break;
default:
F_61 () ;
}
break;
case V_111 :
switch ( V_31 ) {
case V_110 :
case V_112 :
case V_80 :
F_50 ( V_79 ) ;
F_59 ( V_79 , V_112 ) ;
break;
default:
F_61 () ;
}
break;
case V_112 :
switch ( V_31 ) {
case V_110 :
case V_111 :
case V_80 :
F_59 ( V_79 , V_80 ) ;
break;
default:
F_61 () ;
}
break;
default:
F_61 () ;
}
}
}
static void F_62 ( struct V_77 * V_41 ,
enum V_108 V_113 )
{
struct V_78 * V_79 = F_26 ( & V_41 -> V_41 ) ;
F_42 ( L_59 , V_41 -> V_114 , F_60 ( V_113 ) ) ;
V_79 -> V_113 = V_113 ;
switch ( V_113 ) {
case V_95 :
F_27 ( V_79 , V_110 ) ;
break;
case V_115 :
break;
case V_111 :
F_27 ( V_79 , V_111 ) ;
break;
case V_112 :
F_27 ( V_79 , V_112 ) ;
break;
case V_80 :
F_27 ( V_79 , V_80 ) ;
if ( F_63 ( V_41 ) )
break;
case V_116 :
F_27 ( V_79 , V_80 ) ;
F_64 ( & V_41 -> V_41 ) ;
break;
default:
F_37 ( V_41 , - V_56 , L_60 ,
V_113 ) ;
break;
}
}
static void F_65 ( struct V_77 * V_41 ,
unsigned long * V_117 , unsigned long * V_118 )
{
char * V_119 , * V_120 ;
unsigned long V_121 , V_122 ;
char * V_123 ;
* V_117 = ~ 0UL ;
* V_118 = 0 ;
V_123 = F_43 ( V_83 , V_41 -> V_84 , L_61 , NULL ) ;
if ( F_44 ( V_123 ) )
return;
V_119 = V_123 ;
V_121 = F_66 ( V_119 , & V_120 , 10 ) ;
if ( ( V_119 == V_120 ) || ( * V_120 != ',' ) )
goto V_96;
V_119 = V_120 + 1 ;
V_122 = F_66 ( V_119 , & V_120 , 10 ) ;
if ( ( V_119 == V_120 ) || ( * V_120 != '\0' ) )
goto V_96;
* V_117 = V_121 ;
* V_118 = V_122 ;
F_33 ( V_123 ) ;
return;
V_96:
F_11 ( L_62 ) ;
F_33 ( V_123 ) ;
}
static int F_67 ( struct V_77 * V_41 , T_5 V_124 [] )
{
char * V_119 , * V_120 , * V_125 ;
int V_65 ;
V_125 = V_119 = F_43 ( V_83 , V_41 -> V_84 , L_63 , NULL ) ;
if ( F_44 ( V_125 ) )
return F_21 ( V_125 ) ;
for ( V_65 = 0 ; V_65 < V_126 ; V_65 ++ ) {
V_124 [ V_65 ] = F_66 ( V_119 , & V_120 , 16 ) ;
if ( ( V_119 == V_120 ) || ( * V_120 != ( ( V_65 == V_126 - 1 ) ? '\0' : ':' ) ) ) {
F_33 ( V_125 ) ;
return - V_127 ;
}
V_119 = V_120 + 1 ;
}
F_33 ( V_125 ) ;
return 0 ;
}
static void F_68 ( struct V_128 * V_129 ,
const char * V_130 , const char * V_131 )
{
struct V_62 * V_40 = F_69 ( V_129 , struct V_62 , V_132 ) ;
struct V_77 * V_41 = F_70 ( V_40 ) ;
unsigned long V_35 ;
unsigned long V_36 ;
unsigned int V_107 ;
F_65 ( V_41 , & V_35 , & V_36 ) ;
for ( V_107 = 0 ; V_107 < V_40 -> V_69 ; V_107 ++ ) {
struct V_4 * V_5 = & V_40 -> V_73 [ V_107 ] ;
V_5 -> V_35 = V_35 ;
V_5 -> V_36 = V_36 ;
if ( ! F_71 ( & V_5 -> V_34 , V_39 ) &&
V_5 -> V_37 > V_5 -> V_35 ) {
V_5 -> V_37 = V_5 -> V_35 ;
}
}
}
static int F_72 ( struct V_77 * V_41 ,
struct V_62 * V_40 )
{
int V_90 = 0 ;
char * V_133 ;
unsigned V_134 = strlen ( V_41 -> V_84 ) + sizeof( L_64 ) ;
if ( V_40 -> V_132 . V_133 )
return - V_135 ;
V_133 = F_73 ( V_134 , V_93 ) ;
if ( ! V_133 )
return - V_94 ;
snprintf ( V_133 , V_134 , L_65 , V_41 -> V_84 ) ;
V_40 -> V_132 . V_133 = V_133 ;
V_40 -> V_132 . V_136 = F_68 ;
V_90 = F_74 ( & V_40 -> V_132 ) ;
if ( V_90 ) {
F_75 ( L_66 , V_40 -> V_132 . V_133 ) ;
F_33 ( V_133 ) ;
V_40 -> V_132 . V_133 = NULL ;
V_40 -> V_132 . V_136 = NULL ;
}
return V_90 ;
}
static void F_76 ( struct V_62 * V_40 )
{
if ( V_40 -> V_132 . V_133 ) {
F_77 ( & V_40 -> V_132 ) ;
F_33 ( V_40 -> V_132 . V_133 ) ;
V_40 -> V_132 . V_133 = NULL ;
}
}
static void F_78 ( struct V_128 * V_129 ,
const char * V_130 , const char * V_131 )
{
struct V_62 * V_40 = F_69 ( V_129 , struct V_62 ,
V_137 ) ;
struct V_77 * V_41 = F_70 ( V_40 ) ;
V_40 -> V_138 = ! ! F_79 ( V_41 -> V_114 ,
L_67 , 0 ) ;
}
static int F_80 ( struct V_77 * V_41 ,
struct V_62 * V_40 )
{
int V_90 = 0 ;
char * V_133 ;
unsigned V_134 = strlen ( V_41 -> V_114 ) +
sizeof( L_68 ) ;
if ( V_40 -> V_137 . V_133 ) {
F_81 ( L_69 ) ;
return - V_135 ;
}
V_133 = F_73 ( V_134 , V_93 ) ;
if ( ! V_133 ) {
F_75 ( L_70 ) ;
return - V_94 ;
}
snprintf ( V_133 , V_134 , L_71 ,
V_41 -> V_114 ) ;
V_40 -> V_137 . V_133 = V_133 ;
V_40 -> V_137 . V_136 = F_78 ;
V_90 = F_74 ( & V_40 -> V_137 ) ;
if ( V_90 ) {
F_75 ( L_66 ,
V_40 -> V_137 . V_133 ) ;
F_33 ( V_133 ) ;
V_40 -> V_137 . V_133 = NULL ;
V_40 -> V_137 . V_136 = NULL ;
}
return V_90 ;
}
static void F_82 ( struct V_62 * V_40 )
{
if ( V_40 -> V_137 . V_133 ) {
F_77 ( & V_40 -> V_137 ) ;
F_33 ( V_40 -> V_137 . V_133 ) ;
V_40 -> V_137 . V_133 = NULL ;
}
}
static void F_83 ( struct V_77 * V_41 ,
struct V_62 * V_40 )
{
F_72 ( V_41 , V_40 ) ;
F_80 ( V_41 , V_40 ) ;
}
static void F_30 ( struct V_62 * V_40 )
{
F_82 ( V_40 ) ;
F_76 ( V_40 ) ;
}
static void F_28 ( struct V_78 * V_79 )
{
if ( V_79 -> V_109 ) {
F_77 ( & V_79 -> V_139 ) ;
F_33 ( V_79 -> V_139 . V_133 ) ;
}
V_79 -> V_109 = 0 ;
}
static void F_84 ( struct V_128 * V_129 ,
const char * V_130 ,
const char * V_131 )
{
struct V_78 * V_79 = F_69 ( V_129 ,
struct V_78 ,
V_139 ) ;
char * V_140 ;
unsigned int V_51 ;
V_140 = F_43 ( V_83 , V_79 -> V_41 -> V_84 , L_21 , & V_51 ) ;
if ( F_44 ( V_140 ) )
return;
if ( V_51 == sizeof( L_72 ) - 1 && ! memcmp ( V_140 , L_72 , V_51 ) ) {
F_38 ( V_79 -> V_41 , V_79 -> V_31 ) ;
F_28 ( V_79 ) ;
}
F_33 ( V_140 ) ;
}
static int F_85 ( struct V_78 * V_79 )
{
struct V_77 * V_41 = V_79 -> V_41 ;
struct V_62 * V_40 = V_79 -> V_40 ;
unsigned int V_141 ;
T_6 V_142 ;
unsigned int V_143 ;
int V_90 ;
V_90 = F_48 ( V_83 , V_41 -> V_114 ,
L_73 , L_43 , & V_141 ) ;
if ( V_90 < 0 )
goto V_144;
V_142 = V_141 ;
V_90 = F_48 ( V_83 , V_41 -> V_114 ,
L_74 , L_43 , & V_141 ) ;
if ( V_90 < 0 ) {
F_37 ( V_41 , V_90 ,
L_75 ,
V_41 -> V_114 ) ;
goto V_96;
}
V_143 = V_141 ;
V_90 = F_86 ( V_40 , V_142 , V_143 ) ;
if ( V_90 ) {
F_37 ( V_41 , V_90 ,
L_76 ,
V_142 , V_143 ) ;
goto V_96;
}
V_144:
return 0 ;
V_96:
return V_90 ;
}
static void F_58 ( struct V_78 * V_79 )
{
int V_90 ;
struct V_77 * V_41 = V_79 -> V_41 ;
unsigned long V_35 , V_36 ;
unsigned int V_107 ;
unsigned int V_145 ;
struct V_4 * V_5 ;
V_145 = F_79 ( V_41 -> V_114 ,
L_77 , 1 ) ;
if ( V_145 > V_100 ) {
F_37 ( V_41 , - V_56 ,
L_78 ,
V_145 , V_100 ) ;
return;
}
V_90 = F_67 ( V_41 , V_79 -> V_40 -> V_146 ) ;
if ( V_90 ) {
F_37 ( V_41 , V_90 , L_79 , V_41 -> V_84 ) ;
return;
}
F_65 ( V_41 , & V_35 , & V_36 ) ;
F_30 ( V_79 -> V_40 ) ;
F_83 ( V_41 , V_79 -> V_40 ) ;
F_87 ( V_79 ) ;
V_90 = F_85 ( V_79 ) ;
if ( V_90 ) {
F_37 ( V_41 , V_90 , L_80 ) ;
return;
}
V_79 -> V_40 -> V_73 = F_88 ( V_145 *
sizeof( struct V_4 ) ) ;
if ( ! V_79 -> V_40 -> V_73 ) {
F_37 ( V_41 , - V_94 ,
L_81 ) ;
return;
}
V_79 -> V_40 -> V_69 = V_145 ;
V_79 -> V_40 -> V_147 = V_145 ;
for ( V_107 = 0 ; V_107 < V_145 ; ++ V_107 ) {
V_5 = & V_79 -> V_40 -> V_73 [ V_107 ] ;
V_5 -> V_40 = V_79 -> V_40 ;
V_5 -> V_17 = V_107 ;
snprintf ( V_5 -> V_68 , sizeof( V_5 -> V_68 ) , L_82 ,
V_79 -> V_40 -> V_41 -> V_68 , V_5 -> V_17 ) ;
V_90 = F_89 ( V_5 ) ;
if ( V_90 ) {
V_79 -> V_40 -> V_69 = V_107 ;
goto V_90;
}
V_5 -> V_35 = V_35 ;
V_5 -> V_37 = V_35 ;
V_5 -> V_36 = V_36 ;
V_90 = F_90 ( V_79 , V_5 ) ;
if ( V_90 ) {
F_54 ( V_5 ) ;
V_79 -> V_40 -> V_69 = V_107 ;
goto V_90;
}
}
#ifdef F_51
F_17 ( V_79 -> V_40 ) ;
#endif
F_91 () ;
F_92 ( V_79 -> V_40 -> V_41 , V_145 ) ;
F_93 ( V_79 -> V_40 -> V_41 , V_145 ) ;
F_94 () ;
F_95 ( V_79 -> V_40 ) ;
F_28 ( V_79 ) ;
V_90 = F_96 ( V_41 , & V_79 -> V_139 ,
F_84 ,
L_83 , V_41 -> V_84 , L_21 ) ;
if ( ! V_90 )
V_79 -> V_109 = 1 ;
F_97 ( V_79 -> V_40 -> V_41 ) ;
return;
V_90:
if ( V_79 -> V_40 -> V_69 > 0 )
F_52 ( V_79 -> V_40 ) ;
for ( V_107 = 0 ; V_107 < V_79 -> V_40 -> V_69 ; ++ V_107 )
F_54 ( & V_79 -> V_40 -> V_73 [ V_107 ] ) ;
F_55 ( V_79 -> V_40 -> V_73 ) ;
V_79 -> V_40 -> V_73 = NULL ;
V_79 -> V_40 -> V_69 = 0 ;
F_56 ( V_79 -> V_40 ) ;
return;
}
static int F_90 ( struct V_78 * V_79 ,
struct V_4 * V_5 )
{
struct V_77 * V_41 = V_79 -> V_41 ;
unsigned int V_69 = V_5 -> V_40 -> V_69 ;
unsigned long V_148 , V_149 ;
unsigned int V_150 , V_151 ;
int V_90 ;
char * V_152 ;
T_3 V_153 ;
const T_3 V_154 = 11 ;
if ( V_69 == 1 ) {
V_152 = F_36 ( strlen ( V_41 -> V_114 ) + 1 , V_93 ) ;
if ( ! V_152 ) {
F_37 ( V_41 , - V_94 ,
L_84 ) ;
return - V_94 ;
}
strcpy ( V_152 , V_41 -> V_114 ) ;
} else {
V_153 = strlen ( V_41 -> V_114 ) + V_154 ;
V_152 = F_36 ( V_153 , V_93 ) ;
if ( ! V_152 ) {
F_37 ( V_41 , - V_94 ,
L_84 ) ;
return - V_94 ;
}
snprintf ( V_152 , V_153 , L_85 , V_41 -> V_114 ,
V_5 -> V_17 ) ;
}
V_90 = F_98 ( V_83 , V_152 ,
L_86 , L_87 , & V_148 ,
L_88 , L_87 , & V_149 , NULL ) ;
if ( V_90 ) {
F_37 ( V_41 , V_90 ,
L_89 ,
V_152 ) ;
goto V_90;
}
V_90 = F_98 ( V_83 , V_152 ,
L_90 , L_43 , & V_150 ,
L_91 , L_43 , & V_151 , NULL ) ;
if ( V_90 < 0 ) {
V_90 = F_48 ( V_83 , V_152 ,
L_92 , L_43 , & V_150 ) ;
if ( V_90 < 0 ) {
F_37 ( V_41 , V_90 ,
L_93 ,
V_152 ) ;
goto V_90;
}
V_151 = V_150 ;
}
V_90 = F_99 ( V_5 , V_148 , V_149 ,
V_150 , V_151 ) ;
if ( V_90 ) {
F_37 ( V_41 , V_90 ,
L_94 ,
V_148 , V_149 ,
V_150 , V_151 ) ;
goto V_90;
}
V_90 = 0 ;
V_90:
F_33 ( V_152 ) ;
return V_90 ;
}
static int F_87 ( struct V_78 * V_79 )
{
struct V_62 * V_40 = V_79 -> V_40 ;
struct V_77 * V_41 = V_79 -> V_41 ;
unsigned int V_155 ;
int V_90 ;
V_90 = F_48 ( V_83 , V_41 -> V_114 , L_95 , L_43 ,
& V_155 ) ;
if ( V_90 == - V_127 ) {
V_90 = 0 ;
V_155 = 0 ;
}
if ( V_90 < 0 ) {
F_37 ( V_41 , V_90 , L_96 ,
V_41 -> V_114 ) ;
return V_90 ;
}
if ( ! V_155 )
return - V_156 ;
if ( ! F_79 ( V_41 -> V_114 , L_97 , 0 ) ) {
V_79 -> V_40 -> V_157 = F_100 ( 30 ) ;
V_79 -> V_40 -> V_158 = 0 ;
}
V_40 -> V_159 = ! ! F_79 ( V_41 -> V_114 , L_24 , 0 ) ;
V_40 -> V_160 = 0 ;
if ( F_79 ( V_41 -> V_114 , L_27 , 0 ) )
V_40 -> V_160 |= F_101 ( V_161 ) ;
if ( F_79 ( V_41 -> V_114 , L_29 , 0 ) )
V_40 -> V_160 |= F_101 ( V_162 ) ;
V_40 -> V_163 = ! F_79 ( V_41 -> V_114 ,
L_98 , 0 ) ;
V_40 -> V_164 = ! ! F_79 ( V_41 -> V_114 ,
L_31 , 0 ) ;
return 0 ;
}
int F_102 ( void )
{
return F_103 ( & V_165 ) ;
}
void F_104 ( void )
{
return F_105 ( & V_165 ) ;
}
