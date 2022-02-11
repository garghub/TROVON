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
F_27 ( V_81 , V_41 -> V_82 , L_19 ) ;
F_28 ( V_77 -> V_40 ) ;
V_77 -> V_40 = NULL ;
}
F_29 ( V_77 ) ;
F_30 ( & V_41 -> V_41 , NULL ) ;
return 0 ;
}
static int F_31 ( struct V_75 * V_41 ,
const struct V_83 * V_17 )
{
const char * V_84 ;
struct V_85 V_86 ;
int V_87 ;
int V_88 ;
struct V_76 * V_77 = F_32 ( sizeof( struct V_76 ) ,
V_89 ) ;
if ( ! V_77 ) {
F_33 ( V_41 , - V_90 ,
L_20 ) ;
return - V_90 ;
}
V_77 -> V_41 = V_41 ;
F_30 ( & V_41 -> V_41 , V_77 ) ;
V_88 = 1 ;
do {
V_87 = F_34 ( & V_86 ) ;
if ( V_87 ) {
F_33 ( V_41 , V_87 , L_21 ) ;
goto V_91;
}
V_87 = F_35 ( V_86 , V_41 -> V_82 , L_22 , L_23 , V_88 ) ;
if ( V_87 ) {
V_84 = L_24 ;
goto V_92;
}
V_87 = F_35 ( V_86 , V_41 -> V_82 , L_25 ,
L_23 , V_88 ) ;
if ( V_87 ) {
V_84 = L_26 ;
goto V_92;
}
V_87 = F_35 ( V_86 , V_41 -> V_82 , L_27 ,
L_23 , V_88 ) ;
if ( V_87 ) {
V_84 = L_28 ;
goto V_92;
}
V_87 = F_35 ( V_86 , V_41 -> V_82 ,
L_29 ,
L_23 , 1 ) ;
if ( V_87 ) {
V_84 = L_30 ;
goto V_92;
}
V_87 = F_35 ( V_86 , V_41 -> V_82 ,
L_31 , L_23 , 1 ) ;
if ( V_87 ) {
V_84 = L_32 ;
goto V_92;
}
V_87 = F_35 ( V_86 , V_41 -> V_82 ,
L_33 , L_23 , 0 ) ;
if ( V_87 ) {
V_84 = L_34 ;
goto V_92;
}
V_87 = F_36 ( V_86 , 0 ) ;
} while ( V_87 == - V_93 );
if ( V_87 ) {
F_33 ( V_41 , V_87 , L_35 ) ;
goto V_91;
}
V_87 = F_35 ( V_81 , V_41 -> V_82 ,
L_36 ,
L_37 , V_94 ) ;
if ( V_87 )
F_37 ( L_38 ) ;
V_87 = F_35 ( V_81 , V_41 -> V_82 ,
L_39 , L_37 , V_95 ) ;
if ( V_87 )
F_37 ( L_40 ) ;
V_87 = F_38 ( V_41 , V_96 ) ;
if ( V_87 )
goto V_91;
V_77 -> V_31 = V_96 ;
V_87 = F_39 ( V_77 ) ;
if ( V_87 )
goto V_91;
return 0 ;
V_92:
F_36 ( V_86 , 1 ) ;
F_33 ( V_41 , V_87 , L_41 , V_84 ) ;
V_91:
F_37 ( L_42 ) ;
F_22 ( V_41 ) ;
return V_87 ;
}
static int F_40 ( struct V_75 * V_97 ,
struct V_98 * V_99 )
{
struct V_76 * V_77 = F_23 ( & V_97 -> V_41 ) ;
char * V_100 ;
V_100 = F_41 ( V_81 , V_97 -> V_82 , L_43 , NULL ) ;
if ( F_42 ( V_100 ) ) {
int V_87 = F_18 ( V_100 ) ;
F_33 ( V_97 , V_87 , L_44 ) ;
return V_87 ;
} else {
if ( F_43 ( V_99 , L_45 , V_100 ) ) {
F_29 ( V_100 ) ;
return - V_90 ;
}
F_29 ( V_100 ) ;
}
if ( ! V_77 || ! V_77 -> V_40 )
return 0 ;
return F_43 ( V_99 , L_46 , V_77 -> V_40 -> V_41 -> V_68 ) ;
}
static int F_39 ( struct V_76 * V_77 )
{
int V_87 ;
long V_101 ;
struct V_75 * V_41 = V_77 -> V_41 ;
if ( V_77 -> V_40 != NULL )
return 0 ;
V_87 = F_44 ( V_81 , V_41 -> V_82 , L_47 , L_48 , & V_101 ) ;
if ( V_87 != 1 ) {
F_33 ( V_41 , V_87 , L_49 ) ;
return ( V_87 < 0 ) ? V_87 : - V_56 ;
}
V_77 -> V_40 = F_45 ( & V_41 -> V_41 , V_41 -> V_102 , V_101 ) ;
if ( F_42 ( V_77 -> V_40 ) ) {
V_87 = F_18 ( V_77 -> V_40 ) ;
V_77 -> V_40 = NULL ;
F_33 ( V_41 , V_87 , L_50 ) ;
return V_87 ;
}
F_26 ( & V_41 -> V_41 . V_79 , V_103 ) ;
return 0 ;
}
static void F_46 ( struct V_76 * V_77 )
{
if ( V_77 -> V_40 ) {
#ifdef F_47
F_20 ( V_77 -> V_40 ) ;
#endif
F_48 ( V_77 -> V_40 ) ;
}
}
static void F_49 ( struct V_76 * V_77 )
{
if ( V_77 -> V_40 )
F_50 ( V_77 ) ;
}
static inline void F_51 ( struct V_76 * V_77 ,
enum V_104 V_31 )
{
struct V_75 * V_41 = V_77 -> V_41 ;
F_37 ( L_51 , V_41 -> V_82 , F_52 ( V_31 ) ) ;
V_77 -> V_31 = V_31 ;
if ( ! V_77 -> V_105 )
F_38 ( V_41 , V_31 ) ;
}
static void F_24 ( struct V_76 * V_77 ,
enum V_104 V_31 )
{
while ( V_77 -> V_31 != V_31 ) {
switch ( V_77 -> V_31 ) {
case V_78 :
switch ( V_31 ) {
case V_96 :
case V_106 :
F_53 ( L_52 ,
V_77 -> V_41 -> V_82 ) ;
F_51 ( V_77 , V_96 ) ;
break;
case V_107 :
F_51 ( V_77 , V_107 ) ;
break;
default:
F_54 () ;
}
break;
case V_96 :
switch ( V_31 ) {
case V_106 :
F_49 ( V_77 ) ;
F_51 ( V_77 , V_106 ) ;
break;
case V_107 :
case V_78 :
F_51 ( V_77 , V_107 ) ;
break;
default:
F_54 () ;
}
break;
case V_106 :
switch ( V_31 ) {
case V_96 :
case V_107 :
case V_78 :
F_46 ( V_77 ) ;
F_51 ( V_77 , V_107 ) ;
break;
default:
F_54 () ;
}
break;
case V_107 :
switch ( V_31 ) {
case V_96 :
case V_106 :
case V_78 :
F_51 ( V_77 , V_78 ) ;
break;
default:
F_54 () ;
}
break;
default:
F_54 () ;
}
}
}
static void F_55 ( struct V_75 * V_41 ,
enum V_104 V_108 )
{
struct V_76 * V_77 = F_23 ( & V_41 -> V_41 ) ;
F_37 ( L_51 , V_41 -> V_109 , F_52 ( V_108 ) ) ;
V_77 -> V_108 = V_108 ;
switch ( V_108 ) {
case V_110 :
F_24 ( V_77 , V_96 ) ;
break;
case V_111 :
break;
case V_106 :
F_24 ( V_77 , V_106 ) ;
break;
case V_107 :
F_24 ( V_77 , V_107 ) ;
break;
case V_78 :
F_24 ( V_77 , V_78 ) ;
if ( F_56 ( V_41 ) )
break;
case V_112 :
F_24 ( V_77 , V_78 ) ;
F_57 ( & V_41 -> V_41 ) ;
break;
default:
F_33 ( V_41 , - V_56 , L_53 ,
V_108 ) ;
break;
}
}
static void F_58 ( struct V_75 * V_41 ,
unsigned long * V_113 , unsigned long * V_114 )
{
char * V_115 , * V_116 ;
unsigned long V_117 , V_118 ;
char * V_119 ;
* V_113 = ~ 0UL ;
* V_114 = 0 ;
V_119 = F_41 ( V_81 , V_41 -> V_82 , L_54 , NULL ) ;
if ( F_42 ( V_119 ) )
return;
V_115 = V_119 ;
V_117 = F_59 ( V_115 , & V_116 , 10 ) ;
if ( ( V_115 == V_116 ) || ( * V_116 != ',' ) )
goto V_91;
V_115 = V_116 + 1 ;
V_118 = F_59 ( V_115 , & V_116 , 10 ) ;
if ( ( V_115 == V_116 ) || ( * V_116 != '\0' ) )
goto V_91;
* V_113 = V_117 ;
* V_114 = V_118 ;
F_29 ( V_119 ) ;
return;
V_91:
F_11 ( L_55 ) ;
F_29 ( V_119 ) ;
}
static int F_60 ( struct V_75 * V_41 , T_5 V_120 [] )
{
char * V_115 , * V_116 , * V_121 ;
int V_65 ;
V_121 = V_115 = F_41 ( V_81 , V_41 -> V_82 , L_56 , NULL ) ;
if ( F_42 ( V_121 ) )
return F_18 ( V_121 ) ;
for ( V_65 = 0 ; V_65 < V_122 ; V_65 ++ ) {
V_120 [ V_65 ] = F_59 ( V_115 , & V_116 , 16 ) ;
if ( ( V_115 == V_116 ) || ( * V_116 != ( ( V_65 == V_122 - 1 ) ? '\0' : ':' ) ) ) {
F_29 ( V_121 ) ;
return - V_123 ;
}
V_115 = V_116 + 1 ;
}
F_29 ( V_121 ) ;
return 0 ;
}
static void F_25 ( struct V_76 * V_77 )
{
if ( V_77 -> V_105 ) {
F_61 ( & V_77 -> V_124 ) ;
F_29 ( V_77 -> V_124 . V_125 ) ;
}
V_77 -> V_105 = 0 ;
}
static void F_62 ( struct V_126 * V_127 ,
const char * * V_128 ,
unsigned int V_129 )
{
struct V_76 * V_77 = F_63 ( V_127 ,
struct V_76 ,
V_124 ) ;
char * V_130 ;
unsigned int V_51 ;
V_130 = F_41 ( V_81 , V_77 -> V_41 -> V_82 , L_19 , & V_51 ) ;
if ( F_42 ( V_130 ) )
return;
if ( V_51 == sizeof( L_57 ) - 1 && ! memcmp ( V_130 , L_57 , V_51 ) ) {
F_38 ( V_77 -> V_41 , V_77 -> V_31 ) ;
F_25 ( V_77 ) ;
}
F_29 ( V_130 ) ;
}
static void F_50 ( struct V_76 * V_77 )
{
int V_87 ;
struct V_75 * V_41 = V_77 -> V_41 ;
unsigned long V_35 , V_36 ;
unsigned int V_131 ;
unsigned int V_132 ;
struct V_4 * V_5 ;
V_87 = F_44 ( V_81 , V_41 -> V_109 ,
L_58 ,
L_37 , & V_132 ) ;
if ( V_87 < 0 ) {
V_132 = 1 ;
} else if ( V_132 > V_95 ) {
F_33 ( V_41 , V_87 ,
L_59 ,
V_132 , V_95 ) ;
return;
}
V_87 = F_60 ( V_41 , V_77 -> V_40 -> V_133 ) ;
if ( V_87 ) {
F_33 ( V_41 , V_87 , L_60 , V_41 -> V_82 ) ;
return;
}
F_58 ( V_41 , & V_35 , & V_36 ) ;
F_64 ( V_77 ) ;
V_77 -> V_40 -> V_73 = F_65 ( V_132 *
sizeof( struct V_4 ) ) ;
V_77 -> V_40 -> V_69 = V_132 ;
V_77 -> V_40 -> V_134 = V_132 ;
for ( V_131 = 0 ; V_131 < V_132 ; ++ V_131 ) {
V_5 = & V_77 -> V_40 -> V_73 [ V_131 ] ;
V_5 -> V_40 = V_77 -> V_40 ;
V_5 -> V_17 = V_131 ;
snprintf ( V_5 -> V_68 , sizeof( V_5 -> V_68 ) , L_61 ,
V_77 -> V_40 -> V_41 -> V_68 , V_5 -> V_17 ) ;
V_87 = F_66 ( V_5 ) ;
if ( V_87 ) {
V_77 -> V_40 -> V_69 = V_131 ;
goto V_87;
}
V_5 -> V_37 = V_35 ;
V_87 = F_67 ( V_77 , V_5 ) ;
if ( V_87 ) {
F_68 ( V_5 ) ;
V_77 -> V_40 -> V_69 = V_131 ;
goto V_87;
}
}
#ifdef F_47
F_14 ( V_77 -> V_40 ) ;
#endif
F_69 () ;
F_70 ( V_77 -> V_40 -> V_41 , V_132 ) ;
F_71 ( V_77 -> V_40 -> V_41 , V_132 ) ;
F_72 () ;
F_73 ( V_77 -> V_40 ) ;
F_25 ( V_77 ) ;
V_87 = F_74 ( V_41 , & V_77 -> V_124 ,
F_62 ,
L_62 , V_41 -> V_82 , L_19 ) ;
if ( ! V_87 )
V_77 -> V_105 = 1 ;
F_75 ( V_77 -> V_40 -> V_41 ) ;
return;
V_87:
if ( V_77 -> V_40 -> V_69 > 0 )
F_48 ( V_77 -> V_40 ) ;
F_76 ( V_77 -> V_40 -> V_73 ) ;
V_77 -> V_40 -> V_73 = NULL ;
V_77 -> V_40 -> V_69 = 0 ;
return;
}
static int F_67 ( struct V_76 * V_77 , struct V_4 * V_5 )
{
struct V_75 * V_41 = V_77 -> V_41 ;
unsigned int V_69 = V_5 -> V_40 -> V_69 ;
unsigned long V_135 , V_136 ;
unsigned int V_137 , V_138 ;
int V_87 ;
char * V_139 ;
T_3 V_140 ;
const T_3 V_141 = 11 ;
if ( V_69 == 1 ) {
V_139 = F_32 ( strlen ( V_41 -> V_109 ) + 1 , V_89 ) ;
if ( ! V_139 ) {
F_33 ( V_41 , - V_90 ,
L_63 ) ;
return - V_90 ;
}
strcpy ( V_139 , V_41 -> V_109 ) ;
} else {
V_140 = strlen ( V_41 -> V_109 ) + V_141 ;
V_139 = F_32 ( V_140 , V_89 ) ;
if ( ! V_139 ) {
F_33 ( V_41 , - V_90 ,
L_63 ) ;
return - V_90 ;
}
snprintf ( V_139 , V_140 , L_64 , V_41 -> V_109 ,
V_5 -> V_17 ) ;
}
V_87 = F_77 ( V_81 , V_139 ,
L_65 , L_66 , & V_135 ,
L_67 , L_66 , & V_136 , NULL ) ;
if ( V_87 ) {
F_33 ( V_41 , V_87 ,
L_68 ,
V_139 ) ;
goto V_87;
}
V_87 = F_77 ( V_81 , V_139 ,
L_69 , L_37 , & V_137 ,
L_70 , L_37 , & V_138 , NULL ) ;
if ( V_87 < 0 ) {
V_87 = F_44 ( V_81 , V_139 ,
L_71 , L_37 , & V_137 ) ;
if ( V_87 < 0 ) {
F_33 ( V_41 , V_87 ,
L_72 ,
V_139 ) ;
goto V_87;
}
V_138 = V_137 ;
}
V_87 = F_78 ( V_5 , V_135 , V_136 ,
V_137 , V_138 ) ;
if ( V_87 ) {
F_33 ( V_41 , V_87 ,
L_73 ,
V_135 , V_136 ,
V_137 , V_138 ) ;
goto V_87;
}
V_87 = 0 ;
V_87:
F_29 ( V_139 ) ;
return V_87 ;
}
static int F_64 ( struct V_76 * V_77 )
{
struct V_62 * V_40 = V_77 -> V_40 ;
struct V_75 * V_41 = V_77 -> V_41 ;
unsigned int V_142 ;
int V_87 , V_100 ;
V_87 = F_44 ( V_81 , V_41 -> V_109 , L_74 , L_37 ,
& V_142 ) ;
if ( V_87 == - V_123 ) {
V_87 = 0 ;
V_142 = 0 ;
}
if ( V_87 < 0 ) {
F_33 ( V_41 , V_87 , L_75 ,
V_41 -> V_109 ) ;
return V_87 ;
}
if ( ! V_142 )
return - V_143 ;
if ( F_44 ( V_81 , V_41 -> V_109 ,
L_76 , L_23 , & V_100 ) < 0 || V_100 == 0 ) {
F_33 ( V_41 , - V_56 , L_77 ) ;
return - V_56 ;
}
if ( F_44 ( V_81 , V_41 -> V_109 , L_22 ,
L_23 , & V_100 ) < 0 )
V_100 = 0 ;
V_40 -> V_144 = ! ! V_100 ;
V_40 -> V_145 = 0 ;
V_40 -> V_146 = 0 ;
if ( F_44 ( V_81 , V_41 -> V_109 , L_25 ,
L_23 , & V_100 ) < 0 )
V_100 = 0 ;
if ( V_100 )
V_40 -> V_145 |= F_79 ( V_147 ) ;
if ( F_44 ( V_81 , V_41 -> V_109 , L_78 ,
L_23 , & V_100 ) < 0 )
V_100 = 0 ;
if ( V_100 )
V_40 -> V_146 |= F_79 ( V_147 ) ;
if ( F_44 ( V_81 , V_41 -> V_109 , L_27 ,
L_23 , & V_100 ) < 0 )
V_100 = 0 ;
if ( V_100 )
V_40 -> V_145 |= F_79 ( V_148 ) ;
if ( F_44 ( V_81 , V_41 -> V_109 , L_79 ,
L_23 , & V_100 ) < 0 )
V_100 = 0 ;
if ( V_100 )
V_40 -> V_146 |= F_79 ( V_148 ) ;
if ( V_40 -> V_145 & V_40 -> V_146 ) {
F_33 ( V_41 , V_87 ,
L_80
L_81 ,
V_41 -> V_109 ) ;
return - V_143 ;
}
if ( F_44 ( V_81 , V_41 -> V_109 , L_82 ,
L_23 , & V_100 ) < 0 )
V_100 = 0 ;
V_40 -> V_149 = ! V_100 ;
if ( F_44 ( V_81 , V_41 -> V_109 , L_29 ,
L_23 , & V_100 ) < 0 )
V_100 = 0 ;
V_40 -> V_150 = ! ! V_100 ;
return 0 ;
}
int F_80 ( void )
{
return F_81 ( & V_151 ) ;
}
void F_82 ( void )
{
return F_83 ( & V_151 ) ;
}
