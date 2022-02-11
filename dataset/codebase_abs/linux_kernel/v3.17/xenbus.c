static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = & V_5 -> V_9 ;
struct V_10 * V_11 = & V_5 -> V_12 ;
if ( V_8 -> V_13 ) {
struct V_14 * V_13 = V_8 -> V_13 ;
F_2 ( V_2 , L_1 , V_5 -> V_15 ,
V_8 -> V_16 ) ;
F_2 ( V_2 , L_2 ,
V_13 -> V_17 ,
V_13 -> V_17 - V_13 -> V_18 ,
V_8 -> V_19 ,
V_8 -> V_19 - V_13 -> V_18 ,
V_13 -> V_20 ,
V_13 -> V_20 - V_13 -> V_18 ) ;
F_2 ( V_2 , L_3 ,
V_13 -> V_18 ,
V_8 -> V_21 ,
V_8 -> V_21 - V_13 -> V_18 ,
V_13 -> V_22 ,
V_13 -> V_22 - V_13 -> V_18 ) ;
F_2 ( V_2 , L_4 ,
V_5 -> V_23 ,
V_5 -> V_24 ,
F_3 ( V_5 ) ) ;
F_2 ( V_2 , L_5 ,
V_5 -> V_25 ,
V_5 -> V_26 ,
V_5 -> V_25 - V_5 -> V_26 ) ;
}
if ( V_11 -> V_13 ) {
struct V_27 * V_13 = V_11 -> V_13 ;
F_2 ( V_2 , L_6 , V_11 -> V_16 ) ;
F_2 ( V_2 , L_2 ,
V_13 -> V_17 ,
V_13 -> V_17 - V_13 -> V_18 ,
V_11 -> V_19 ,
V_11 -> V_19 - V_13 -> V_18 ,
V_13 -> V_20 ,
V_13 -> V_20 - V_13 -> V_18 ) ;
F_2 ( V_2 , L_7 ,
V_13 -> V_18 ,
V_11 -> V_21 ,
V_11 -> V_21 - V_13 -> V_18 ,
V_13 -> V_22 ,
V_13 -> V_22 - V_13 -> V_18 ) ;
}
F_2 ( V_2 , L_8
L_9
L_10 ,
V_5 -> V_28 . V_29 , V_5 -> V_28 . V_30 ,
F_4 ( & V_5 -> V_31 ) ,
F_5 ( & V_5 -> V_32 ) ,
V_5 -> V_33 ,
V_5 -> V_34 ,
V_5 -> V_35 ,
V_5 -> V_32 . V_36 ,
V_37 ) ;
return 0 ;
}
static T_1
F_6 ( struct V_38 * V_39 , const char T_2 * V_40 , T_3 V_41 ,
T_4 * V_42 )
{
struct V_4 * V_5 =
( (struct V_1 * ) V_39 -> V_43 ) -> V_6 ;
int V_44 ;
char V_45 [ V_46 ] ;
if ( * V_42 != 0 )
return 0 ;
if ( V_41 >= sizeof( V_45 ) )
return - V_47 ;
V_44 = F_7 ( V_45 ,
sizeof( V_45 ) - 1 ,
V_42 ,
V_40 ,
V_41 ) ;
if ( V_44 < 0 )
return V_44 ;
V_45 [ V_44 ] = '\0' ;
if ( ! strncmp ( V_45 , V_48 , sizeof( V_48 ) - 1 ) )
F_8 ( 0 , ( void * ) V_5 ) ;
else {
F_9 ( L_11 ,
V_5 -> V_15 ) ;
V_41 = - V_49 ;
}
return V_41 ;
}
static int F_10 ( struct V_50 * V_50 , struct V_38 * V_39 )
{
int V_51 ;
void * V_5 = NULL ;
if ( V_50 -> V_52 )
V_5 = V_50 -> V_52 ;
V_51 = F_11 ( V_39 , F_1 , V_5 ) ;
V_39 -> V_53 |= V_54 ;
return V_51 ;
}
static void F_12 ( struct V_55 * V_56 )
{
struct V_57 * V_58 ;
int V_59 ;
if ( F_13 ( V_60 ) )
return;
V_56 -> V_61 = F_14 ( V_56 -> V_62 -> V_63 ,
V_60 ) ;
if ( ! F_13 ( V_56 -> V_61 ) ) {
for ( V_59 = 0 ; V_59 < V_56 -> V_64 ; ++ V_59 ) {
char V_65 [ sizeof( L_12 ) + 4 ] ;
snprintf ( V_65 , sizeof( V_65 ) , L_13 , V_59 ) ;
V_58 = F_15 ( V_65 ,
V_66 | V_67 ,
V_56 -> V_61 ,
& V_56 -> V_68 [ V_59 ] ,
& V_69 ) ;
if ( F_13 ( V_58 ) )
F_9 ( L_14 ,
F_16 ( V_58 ) ) ;
}
} else
F_17 ( V_56 -> V_62 ,
L_15 ,
F_16 ( V_56 -> V_61 ) ) ;
}
static void F_18 ( struct V_55 * V_56 )
{
if ( F_13 ( V_60 ) )
return;
if ( ! F_13 ( V_56 -> V_61 ) )
F_19 ( V_56 -> V_61 ) ;
V_56 -> V_61 = NULL ;
}
static int F_20 ( struct V_70 * V_62 )
{
struct V_71 * V_72 = F_21 ( & V_62 -> V_62 ) ;
F_22 ( V_72 , V_73 ) ;
F_23 ( V_72 ) ;
if ( V_72 -> V_56 ) {
F_24 ( & V_62 -> V_62 . V_74 , V_75 ) ;
F_25 ( V_76 , V_62 -> V_77 , L_16 ) ;
F_26 ( V_72 -> V_56 ) ;
V_72 -> V_56 = NULL ;
}
F_27 ( V_72 ) ;
F_28 ( & V_62 -> V_62 , NULL ) ;
return 0 ;
}
static int F_29 ( struct V_70 * V_62 ,
const struct V_78 * V_15 )
{
const char * V_79 ;
struct V_80 V_81 ;
int V_82 ;
int V_83 ;
struct V_71 * V_72 = F_30 ( sizeof( struct V_71 ) ,
V_84 ) ;
if ( ! V_72 ) {
F_31 ( V_62 , - V_85 ,
L_17 ) ;
return - V_85 ;
}
V_72 -> V_62 = V_62 ;
F_28 ( & V_62 -> V_62 , V_72 ) ;
V_83 = 1 ;
do {
V_82 = F_32 ( & V_81 ) ;
if ( V_82 ) {
F_31 ( V_62 , V_82 , L_18 ) ;
goto V_86;
}
V_82 = F_33 ( V_81 , V_62 -> V_77 , L_19 , L_20 , V_83 ) ;
if ( V_82 ) {
V_79 = L_21 ;
goto V_87;
}
V_82 = F_33 ( V_81 , V_62 -> V_77 , L_22 ,
L_20 , V_83 ) ;
if ( V_82 ) {
V_79 = L_23 ;
goto V_87;
}
V_82 = F_33 ( V_81 , V_62 -> V_77 , L_24 ,
L_20 , V_83 ) ;
if ( V_82 ) {
V_79 = L_25 ;
goto V_87;
}
V_82 = F_33 ( V_81 , V_62 -> V_77 ,
L_26 ,
L_20 , 1 ) ;
if ( V_82 ) {
V_79 = L_27 ;
goto V_87;
}
V_82 = F_33 ( V_81 , V_62 -> V_77 ,
L_28 , L_20 , 1 ) ;
if ( V_82 ) {
V_79 = L_29 ;
goto V_87;
}
V_82 = F_33 ( V_81 , V_62 -> V_77 ,
L_30 , L_20 , 0 ) ;
if ( V_82 ) {
V_79 = L_31 ;
goto V_87;
}
V_82 = F_34 ( V_81 , 0 ) ;
} while ( V_82 == - V_88 );
if ( V_82 ) {
F_31 ( V_62 , V_82 , L_32 ) ;
goto V_86;
}
V_82 = F_33 ( V_76 , V_62 -> V_77 ,
L_33 ,
L_34 , V_89 ) ;
if ( V_82 )
F_35 ( L_35 ) ;
V_82 = F_33 ( V_76 , V_62 -> V_77 ,
L_36 , L_34 , V_90 ) ;
if ( V_82 )
F_35 ( L_37 ) ;
V_82 = F_36 ( V_62 , V_91 ) ;
if ( V_82 )
goto V_86;
V_72 -> V_29 = V_91 ;
F_37 ( V_72 ) ;
return 0 ;
V_87:
F_34 ( V_81 , 1 ) ;
F_31 ( V_62 , V_82 , L_38 , V_79 ) ;
V_86:
F_35 ( L_39 ) ;
F_20 ( V_62 ) ;
return V_82 ;
}
static int F_38 ( struct V_70 * V_92 ,
struct V_93 * V_94 )
{
struct V_71 * V_72 = F_21 ( & V_92 -> V_62 ) ;
char * V_95 ;
V_95 = F_39 ( V_76 , V_92 -> V_77 , L_40 , NULL ) ;
if ( F_40 ( V_95 ) ) {
int V_82 = F_16 ( V_95 ) ;
F_31 ( V_92 , V_82 , L_41 ) ;
return V_82 ;
} else {
if ( F_41 ( V_94 , L_42 , V_95 ) ) {
F_27 ( V_95 ) ;
return - V_85 ;
}
F_27 ( V_95 ) ;
}
if ( ! V_72 || ! V_72 -> V_56 )
return 0 ;
return F_41 ( V_94 , L_43 , V_72 -> V_56 -> V_62 -> V_63 ) ;
}
static void F_37 ( struct V_71 * V_72 )
{
int V_82 ;
long V_96 ;
struct V_70 * V_62 = V_72 -> V_62 ;
if ( V_72 -> V_56 != NULL )
return;
V_82 = F_42 ( V_76 , V_62 -> V_77 , L_44 , L_45 , & V_96 ) ;
if ( V_82 != 1 ) {
F_31 ( V_62 , V_82 , L_46 ) ;
return;
}
V_72 -> V_56 = F_43 ( & V_62 -> V_62 , V_62 -> V_97 , V_96 ) ;
if ( F_40 ( V_72 -> V_56 ) ) {
V_82 = F_16 ( V_72 -> V_56 ) ;
V_72 -> V_56 = NULL ;
F_31 ( V_62 , V_82 , L_47 ) ;
return;
}
F_24 ( & V_62 -> V_62 . V_74 , V_98 ) ;
}
static void F_44 ( struct V_71 * V_72 )
{
if ( V_72 -> V_56 ) {
#ifdef F_45
F_18 ( V_72 -> V_56 ) ;
#endif
F_46 ( V_72 -> V_56 ) ;
}
}
static void F_47 ( struct V_71 * V_72 )
{
if ( V_72 -> V_56 )
F_48 ( V_72 ) ;
}
static inline void F_49 ( struct V_71 * V_72 ,
enum V_99 V_29 )
{
struct V_70 * V_62 = V_72 -> V_62 ;
F_35 ( L_48 , V_62 -> V_77 , F_50 ( V_29 ) ) ;
V_72 -> V_29 = V_29 ;
if ( ! V_72 -> V_100 )
F_36 ( V_62 , V_29 ) ;
}
static void F_22 ( struct V_71 * V_72 ,
enum V_99 V_29 )
{
while ( V_72 -> V_29 != V_29 ) {
switch ( V_72 -> V_29 ) {
case V_73 :
switch ( V_29 ) {
case V_91 :
case V_101 :
F_51 ( L_49 ,
V_72 -> V_62 -> V_77 ) ;
F_49 ( V_72 , V_91 ) ;
break;
case V_102 :
F_49 ( V_72 , V_102 ) ;
break;
default:
F_52 () ;
}
break;
case V_91 :
switch ( V_29 ) {
case V_101 :
F_47 ( V_72 ) ;
F_49 ( V_72 , V_101 ) ;
break;
case V_102 :
case V_73 :
F_49 ( V_72 , V_102 ) ;
break;
default:
F_52 () ;
}
break;
case V_101 :
switch ( V_29 ) {
case V_91 :
case V_102 :
case V_73 :
F_44 ( V_72 ) ;
F_49 ( V_72 , V_102 ) ;
break;
default:
F_52 () ;
}
break;
case V_102 :
switch ( V_29 ) {
case V_91 :
case V_101 :
case V_73 :
F_49 ( V_72 , V_73 ) ;
break;
default:
F_52 () ;
}
break;
default:
F_52 () ;
}
}
}
static void F_53 ( struct V_70 * V_62 ,
enum V_99 V_103 )
{
struct V_71 * V_72 = F_21 ( & V_62 -> V_62 ) ;
F_35 ( L_48 , V_62 -> V_104 , F_50 ( V_103 ) ) ;
V_72 -> V_103 = V_103 ;
switch ( V_103 ) {
case V_105 :
F_22 ( V_72 , V_91 ) ;
break;
case V_106 :
break;
case V_101 :
F_22 ( V_72 , V_101 ) ;
break;
case V_102 :
F_22 ( V_72 , V_102 ) ;
break;
case V_73 :
F_22 ( V_72 , V_73 ) ;
if ( F_54 ( V_62 ) )
break;
case V_107 :
F_22 ( V_72 , V_73 ) ;
F_55 ( & V_62 -> V_62 ) ;
break;
default:
F_31 ( V_62 , - V_49 , L_50 ,
V_103 ) ;
break;
}
}
static void F_56 ( struct V_70 * V_62 ,
unsigned long * V_108 , unsigned long * V_109 )
{
char * V_110 , * V_111 ;
unsigned long V_112 , V_113 ;
char * V_114 ;
* V_108 = ~ 0UL ;
* V_109 = 0 ;
V_114 = F_39 ( V_76 , V_62 -> V_77 , L_51 , NULL ) ;
if ( F_40 ( V_114 ) )
return;
V_110 = V_114 ;
V_112 = F_57 ( V_110 , & V_111 , 10 ) ;
if ( ( V_110 == V_111 ) || ( * V_111 != ',' ) )
goto V_86;
V_110 = V_111 + 1 ;
V_113 = F_57 ( V_110 , & V_111 , 10 ) ;
if ( ( V_110 == V_111 ) || ( * V_111 != '\0' ) )
goto V_86;
* V_108 = V_112 ;
* V_109 = V_113 ;
F_27 ( V_114 ) ;
return;
V_86:
F_9 ( L_52 ) ;
F_27 ( V_114 ) ;
}
static int F_58 ( struct V_70 * V_62 , T_5 V_115 [] )
{
char * V_110 , * V_111 , * V_116 ;
int V_59 ;
V_116 = V_110 = F_39 ( V_76 , V_62 -> V_77 , L_53 , NULL ) ;
if ( F_40 ( V_116 ) )
return F_16 ( V_116 ) ;
for ( V_59 = 0 ; V_59 < V_117 ; V_59 ++ ) {
V_115 [ V_59 ] = F_57 ( V_110 , & V_111 , 16 ) ;
if ( ( V_110 == V_111 ) || ( * V_111 != ( ( V_59 == V_117 - 1 ) ? '\0' : ':' ) ) ) {
F_27 ( V_116 ) ;
return - V_118 ;
}
V_110 = V_111 + 1 ;
}
F_27 ( V_116 ) ;
return 0 ;
}
static void F_23 ( struct V_71 * V_72 )
{
if ( V_72 -> V_100 ) {
F_59 ( & V_72 -> V_119 ) ;
F_27 ( V_72 -> V_119 . V_120 ) ;
}
V_72 -> V_100 = 0 ;
}
static void F_60 ( struct V_121 * V_122 ,
const char * * V_123 ,
unsigned int V_124 )
{
struct V_71 * V_72 = F_61 ( V_122 ,
struct V_71 ,
V_119 ) ;
char * V_125 ;
unsigned int V_44 ;
V_125 = F_39 ( V_76 , V_72 -> V_62 -> V_77 , L_16 , & V_44 ) ;
if ( F_40 ( V_125 ) )
return;
if ( V_44 == sizeof( L_54 ) - 1 && ! memcmp ( V_125 , L_54 , V_44 ) ) {
F_36 ( V_72 -> V_62 , V_72 -> V_29 ) ;
F_23 ( V_72 ) ;
}
F_27 ( V_125 ) ;
}
static void F_48 ( struct V_71 * V_72 )
{
int V_82 ;
struct V_70 * V_62 = V_72 -> V_62 ;
unsigned long V_33 , V_34 ;
unsigned int V_126 ;
unsigned int V_127 ;
struct V_4 * V_5 ;
V_82 = F_42 ( V_76 , V_62 -> V_104 ,
L_55 ,
L_34 , & V_127 ) ;
if ( V_82 < 0 ) {
V_127 = 1 ;
} else if ( V_127 > V_90 ) {
F_31 ( V_62 , V_82 ,
L_56 ,
V_127 , V_90 ) ;
return;
}
V_82 = F_58 ( V_62 , V_72 -> V_56 -> V_128 ) ;
if ( V_82 ) {
F_31 ( V_62 , V_82 , L_57 , V_62 -> V_77 ) ;
return;
}
F_56 ( V_62 , & V_33 , & V_34 ) ;
F_62 ( V_72 ) ;
V_72 -> V_56 -> V_68 = F_63 ( V_127 *
sizeof( struct V_4 ) ) ;
V_72 -> V_56 -> V_64 = V_127 ;
for ( V_126 = 0 ; V_126 < V_127 ; ++ V_126 ) {
V_5 = & V_72 -> V_56 -> V_68 [ V_126 ] ;
V_5 -> V_56 = V_72 -> V_56 ;
V_5 -> V_15 = V_126 ;
snprintf ( V_5 -> V_63 , sizeof( V_5 -> V_63 ) , L_58 ,
V_72 -> V_56 -> V_62 -> V_63 , V_5 -> V_15 ) ;
V_82 = F_64 ( V_5 ) ;
if ( V_82 ) {
V_72 -> V_56 -> V_64 = V_126 ;
goto V_82;
}
V_5 -> V_35 = V_33 ;
V_82 = F_65 ( V_72 , V_5 ) ;
if ( V_82 ) {
F_66 ( V_5 ) ;
V_72 -> V_56 -> V_64 = V_126 ;
goto V_82;
}
}
#ifdef F_45
F_12 ( V_72 -> V_56 ) ;
#endif
F_67 () ;
F_68 ( V_72 -> V_56 -> V_62 , V_127 ) ;
F_69 ( V_72 -> V_56 -> V_62 , V_127 ) ;
F_70 () ;
F_71 ( V_72 -> V_56 ) ;
F_23 ( V_72 ) ;
V_82 = F_72 ( V_62 , & V_72 -> V_119 ,
F_60 ,
L_59 , V_62 -> V_77 , L_16 ) ;
if ( ! V_82 )
V_72 -> V_100 = 1 ;
F_73 ( V_72 -> V_56 -> V_62 ) ;
return;
V_82:
if ( V_72 -> V_56 -> V_64 > 0 )
F_46 ( V_72 -> V_56 ) ;
F_74 ( V_72 -> V_56 -> V_68 ) ;
V_72 -> V_56 -> V_68 = NULL ;
V_72 -> V_56 -> V_64 = 0 ;
return;
}
static int F_65 ( struct V_71 * V_72 , struct V_4 * V_5 )
{
struct V_70 * V_62 = V_72 -> V_62 ;
unsigned int V_64 = V_5 -> V_56 -> V_64 ;
unsigned long V_129 , V_130 ;
unsigned int V_131 , V_132 ;
int V_82 ;
char * V_133 ;
T_3 V_134 ;
const T_3 V_135 = 11 ;
if ( V_64 == 1 ) {
V_133 = F_30 ( strlen ( V_62 -> V_104 ) + 1 , V_84 ) ;
if ( ! V_133 ) {
F_31 ( V_62 , - V_85 ,
L_60 ) ;
return - V_85 ;
}
strcpy ( V_133 , V_62 -> V_104 ) ;
} else {
V_134 = strlen ( V_62 -> V_104 ) + V_135 ;
V_133 = F_30 ( V_134 , V_84 ) ;
if ( ! V_133 ) {
F_31 ( V_62 , - V_85 ,
L_60 ) ;
return - V_85 ;
}
snprintf ( V_133 , V_134 , L_61 , V_62 -> V_104 ,
V_5 -> V_15 ) ;
}
V_82 = F_75 ( V_76 , V_133 ,
L_62 , L_63 , & V_129 ,
L_64 , L_63 , & V_130 , NULL ) ;
if ( V_82 ) {
F_31 ( V_62 , V_82 ,
L_65 ,
V_133 ) ;
goto V_82;
}
V_82 = F_75 ( V_76 , V_133 ,
L_66 , L_34 , & V_131 ,
L_67 , L_34 , & V_132 , NULL ) ;
if ( V_82 < 0 ) {
V_82 = F_42 ( V_76 , V_133 ,
L_68 , L_34 , & V_131 ) ;
if ( V_82 < 0 ) {
F_31 ( V_62 , V_82 ,
L_69 ,
V_133 ) ;
goto V_82;
}
V_132 = V_131 ;
}
V_82 = F_76 ( V_5 , V_129 , V_130 ,
V_131 , V_132 ) ;
if ( V_82 ) {
F_31 ( V_62 , V_82 ,
L_70 ,
V_129 , V_130 ,
V_131 , V_132 ) ;
goto V_82;
}
V_82 = 0 ;
V_82:
F_27 ( V_133 ) ;
return V_82 ;
}
static int F_62 ( struct V_71 * V_72 )
{
struct V_55 * V_56 = V_72 -> V_56 ;
struct V_70 * V_62 = V_72 -> V_62 ;
unsigned int V_136 ;
int V_82 , V_95 ;
V_82 = F_42 ( V_76 , V_62 -> V_104 , L_71 , L_34 ,
& V_136 ) ;
if ( V_82 == - V_118 ) {
V_82 = 0 ;
V_136 = 0 ;
}
if ( V_82 < 0 ) {
F_31 ( V_62 , V_82 , L_72 ,
V_62 -> V_104 ) ;
return V_82 ;
}
if ( ! V_136 )
return - V_137 ;
if ( V_56 -> V_62 -> V_138 != 0 ) {
if ( F_42 ( V_76 , V_62 -> V_104 ,
L_73 , L_20 , & V_95 ) < 0 )
V_95 = 0 ;
if ( V_95 )
V_56 -> V_139 = 1 ;
else
V_56 -> V_62 -> V_138 = 1 ;
}
if ( F_42 ( V_76 , V_62 -> V_104 , L_19 ,
L_20 , & V_95 ) < 0 )
V_95 = 0 ;
V_56 -> V_140 = ! ! V_95 ;
V_56 -> V_141 = 0 ;
V_56 -> V_142 = 0 ;
if ( F_42 ( V_76 , V_62 -> V_104 , L_22 ,
L_20 , & V_95 ) < 0 )
V_95 = 0 ;
if ( V_95 )
V_56 -> V_141 |= F_77 ( V_143 ) ;
if ( F_42 ( V_76 , V_62 -> V_104 , L_74 ,
L_20 , & V_95 ) < 0 )
V_95 = 0 ;
if ( V_95 )
V_56 -> V_142 |= F_77 ( V_143 ) ;
if ( F_42 ( V_76 , V_62 -> V_104 , L_24 ,
L_20 , & V_95 ) < 0 )
V_95 = 0 ;
if ( V_95 )
V_56 -> V_141 |= F_77 ( V_144 ) ;
if ( F_42 ( V_76 , V_62 -> V_104 , L_75 ,
L_20 , & V_95 ) < 0 )
V_95 = 0 ;
if ( V_95 )
V_56 -> V_142 |= F_77 ( V_144 ) ;
if ( V_56 -> V_141 & V_56 -> V_142 ) {
F_31 ( V_62 , V_82 ,
L_76
L_77 ,
V_62 -> V_104 ) ;
return - V_137 ;
}
if ( F_42 ( V_76 , V_62 -> V_104 , L_78 ,
L_20 , & V_95 ) < 0 )
V_95 = 0 ;
V_56 -> V_145 = ! V_95 ;
if ( F_42 ( V_76 , V_62 -> V_104 , L_26 ,
L_20 , & V_95 ) < 0 )
V_95 = 0 ;
V_56 -> V_146 = ! ! V_95 ;
return 0 ;
}
int F_78 ( void )
{
return F_79 ( & V_147 ) ;
}
void F_80 ( void )
{
return F_81 ( & V_147 ) ;
}
