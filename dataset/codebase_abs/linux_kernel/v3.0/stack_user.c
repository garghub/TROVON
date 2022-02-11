static inline void F_1 ( struct V_1 * V_1 ,
int V_2 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
V_4 -> V_6 = V_2 ;
}
static inline int F_2 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
return V_4 -> V_6 ;
}
static struct V_7 * F_3 ( const char * V_8 )
{
T_1 V_9 = strlen ( V_8 ) ;
struct V_7 * V_10 ;
F_4 ( ! F_5 ( & V_11 ) ) ;
F_6 (c, &ocfs2_live_connection_list, oc_list) {
if ( ( V_10 -> V_12 -> V_13 == V_9 ) &&
! strncmp ( V_10 -> V_12 -> V_14 , V_8 , V_9 ) )
return V_10 ;
}
return NULL ;
}
static int F_7 ( struct V_15 * V_16 ,
struct V_7 * * V_17 )
{
int V_18 = 0 ;
struct V_7 * V_10 ;
V_10 = F_8 ( sizeof( struct V_7 ) , V_19 ) ;
if ( ! V_10 )
return - V_20 ;
F_9 ( & V_11 ) ;
V_10 -> V_12 = V_16 ;
if ( F_10 ( & V_21 ) )
F_11 ( & V_10 -> V_22 , & V_23 ) ;
else {
F_12 ( V_24
L_1 ) ;
V_18 = - V_25 ;
}
F_13 ( & V_11 ) ;
if ( ! V_18 )
* V_17 = V_10 ;
else
F_14 ( V_10 ) ;
return V_18 ;
}
static void F_15 ( struct V_7 * V_10 )
{
F_9 ( & V_11 ) ;
F_16 ( & V_10 -> V_22 ) ;
V_10 -> V_12 = NULL ;
F_13 ( & V_11 ) ;
F_14 ( V_10 ) ;
}
static int F_17 ( void * V_26 , T_1 V_27 ,
const char T_2 * V_28 , T_1 V_29 )
{
if ( ( V_29 != V_27 ) ||
( V_29 > sizeof( union V_30 ) ) )
return - V_31 ;
if ( F_18 ( V_26 , V_28 , V_27 ) )
return - V_32 ;
return 0 ;
}
static T_3 F_19 ( struct V_1 * V_1 ,
const char T_2 * V_28 ,
T_1 V_29 )
{
T_3 V_33 ;
char V_34 [ V_35 ] ;
V_33 = F_17 ( V_34 , V_35 ,
V_28 , V_29 ) ;
if ( V_33 )
return V_33 ;
if ( strncmp ( V_34 , V_36 , V_35 ) )
return - V_31 ;
F_1 ( V_1 ,
V_37 ) ;
return V_29 ;
}
static void F_20 ( const char * V_38 ,
int V_39 )
{
struct V_7 * V_10 ;
F_9 ( & V_11 ) ;
V_10 = F_3 ( V_38 ) ;
if ( V_10 ) {
F_4 ( V_10 -> V_12 == NULL ) ;
V_10 -> V_12 -> V_40 ( V_39 ,
V_10 -> V_12 -> V_41 ) ;
}
F_13 ( & V_11 ) ;
}
static int F_21 ( struct V_1 * V_1 )
{
int V_18 = 0 ;
int V_42 = 1 ;
struct V_3 * V_4 = V_1 -> V_5 ;
F_4 ( V_4 -> V_6 != V_37 ) ;
F_9 ( & V_11 ) ;
if ( V_4 -> V_43 < 0 ) {
V_42 = 0 ;
} else if ( ( V_44 >= 0 ) &&
( V_44 != V_4 -> V_43 ) ) {
V_18 = - V_31 ;
goto V_45;
}
if ( ! V_4 -> V_46 . V_47 ) {
V_42 = 0 ;
} else if ( ! F_22 ( & V_23 ) &&
( ( V_48 . V_47 != V_4 -> V_46 . V_47 ) ||
( V_48 . V_49 != V_4 -> V_46 . V_49 ) ) ) {
V_18 = - V_31 ;
goto V_45;
}
if ( V_42 ) {
V_44 = V_4 -> V_43 ;
V_48 . V_47 = V_4 -> V_46 . V_47 ;
V_48 . V_49 = V_4 -> V_46 . V_49 ;
}
V_45:
F_13 ( & V_11 ) ;
if ( ! V_18 && V_42 ) {
F_23 ( & V_21 ) ;
F_1 ( V_1 ,
V_50 ) ;
}
return V_18 ;
}
static int F_24 ( void )
{
int V_18 ;
F_9 ( & V_11 ) ;
if ( V_44 < 0 )
V_18 = - V_31 ;
else
V_18 = V_44 ;
F_13 ( & V_11 ) ;
return V_18 ;
}
static int F_25 ( struct V_1 * V_1 ,
struct V_51 * V_52 )
{
long V_39 ;
char * V_53 = NULL ;
struct V_3 * V_4 = V_1 -> V_5 ;
if ( F_2 ( V_1 ) !=
V_37 )
return - V_31 ;
if ( strncmp ( V_52 -> V_54 , V_55 ,
V_56 ) )
return - V_31 ;
if ( ( V_52 -> V_57 != ' ' ) || ( V_52 -> V_58 != '\n' ) )
return - V_31 ;
V_52 -> V_57 = V_52 -> V_58 = '\0' ;
V_39 = F_26 ( V_52 -> V_59 , & V_53 , 16 ) ;
if ( ! V_53 || * V_53 )
return - V_31 ;
if ( ( V_39 == V_60 ) || ( V_39 == V_61 ) ||
( V_39 > V_62 ) || ( V_39 < 0 ) )
return - V_63 ;
V_4 -> V_43 = V_39 ;
return F_21 ( V_1 ) ;
}
static int F_27 ( struct V_1 * V_1 ,
struct V_64 * V_52 )
{
long V_65 , V_66 ;
char * V_53 = NULL ;
struct V_3 * V_4 = V_1 -> V_5 ;
struct V_67 * V_68 =
& V_69 . V_70 ;
if ( F_2 ( V_1 ) !=
V_37 )
return - V_31 ;
if ( strncmp ( V_52 -> V_54 , V_71 ,
V_56 ) )
return - V_31 ;
if ( ( V_52 -> V_72 != ' ' ) || ( V_52 -> V_73 != ' ' ) ||
( V_52 -> V_58 != '\n' ) )
return - V_31 ;
V_52 -> V_72 = V_52 -> V_73 = V_52 -> V_58 = '\0' ;
V_65 = F_26 ( V_52 -> V_65 , & V_53 , 16 ) ;
if ( ! V_53 || * V_53 )
return - V_31 ;
V_66 = F_26 ( V_52 -> V_66 , & V_53 , 16 ) ;
if ( ! V_53 || * V_53 )
return - V_31 ;
if ( ( V_65 == V_60 ) || ( V_65 == V_61 ) ||
( V_65 > ( V_74 ) - 1 ) || ( V_65 < 1 ) )
return - V_63 ;
if ( ( V_66 == V_60 ) || ( V_66 == V_61 ) ||
( V_66 > ( V_74 ) - 1 ) || ( V_66 < 0 ) )
return - V_63 ;
if ( ( V_65 != V_68 -> V_47 ) ||
( V_66 > V_68 -> V_49 ) )
return - V_31 ;
V_4 -> V_46 . V_47 = V_65 ;
V_4 -> V_46 . V_49 = V_66 ;
return F_21 ( V_1 ) ;
}
static int F_28 ( struct V_1 * V_1 ,
struct V_75 * V_52 )
{
long V_39 ;
char * V_4 = NULL ;
if ( F_2 ( V_1 ) !=
V_50 )
return - V_31 ;
if ( strncmp ( V_52 -> V_54 , V_76 ,
V_56 ) )
return - V_31 ;
if ( ( V_52 -> V_72 != ' ' ) || ( V_52 -> V_73 != ' ' ) ||
( V_52 -> V_58 != '\n' ) )
return - V_31 ;
V_52 -> V_72 = V_52 -> V_73 = V_52 -> V_58 = '\0' ;
V_39 = F_26 ( V_52 -> V_59 , & V_4 , 16 ) ;
if ( ! V_4 || * V_4 )
return - V_31 ;
if ( ( V_39 == V_60 ) || ( V_39 == V_61 ) ||
( V_39 > V_62 ) || ( V_39 < 0 ) )
return - V_63 ;
F_20 ( V_52 -> V_38 , V_39 ) ;
return 0 ;
}
static T_3 V_30 ( struct V_1 * V_1 ,
const char T_2 * V_28 ,
T_1 V_29 )
{
T_3 V_33 ;
union V_30 V_52 ;
F_29 ( F_30 ( struct V_75 , V_38 ) !=
( sizeof( V_52 . V_77 . V_54 ) + sizeof( V_52 . V_77 . V_72 ) ) ) ;
memset ( & V_52 , 0 , sizeof( union V_30 ) ) ;
V_33 = F_17 ( & V_52 , V_29 , V_28 , V_29 ) ;
if ( V_33 )
goto V_78;
if ( ( V_29 == V_79 ) &&
! strncmp ( V_52 . V_54 , V_55 ,
V_56 ) )
V_33 = F_25 ( V_1 , & V_52 . V_80 ) ;
else if ( ( V_29 == V_81 ) &&
! strncmp ( V_52 . V_54 , V_71 ,
V_56 ) )
V_33 = F_27 ( V_1 , & V_52 . V_82 ) ;
else if ( ( V_29 == V_83 ) &&
! strncmp ( V_52 . V_54 , V_76 ,
V_56 ) )
V_33 = F_28 ( V_1 , & V_52 . V_77 ) ;
else
V_33 = - V_31 ;
V_78:
return V_33 ? V_33 : V_29 ;
}
static T_3 F_31 ( struct V_1 * V_1 ,
const char T_2 * V_28 ,
T_1 V_29 ,
T_4 * V_84 )
{
T_3 V_33 ;
switch ( F_2 ( V_1 ) ) {
case V_85 :
V_33 = - V_31 ;
break;
case V_86 :
V_33 = F_19 ( V_1 , V_28 ,
V_29 ) ;
break;
case V_37 :
case V_50 :
V_33 = V_30 ( V_1 , V_28 , V_29 ) ;
break;
default:
F_32 () ;
V_33 = - V_87 ;
break;
}
return V_33 ;
}
static T_3 F_33 ( struct V_1 * V_1 ,
char T_2 * V_28 ,
T_1 V_29 ,
T_4 * V_84 )
{
T_3 V_33 ;
V_33 = F_34 ( V_28 , V_29 , V_84 ,
V_36 , V_35 ) ;
if ( V_33 > 0 && * V_84 >= V_35 )
F_1 ( V_1 ,
V_86 ) ;
return V_33 ;
}
static int F_35 ( struct V_88 * V_88 , struct V_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
F_9 ( & V_11 ) ;
if ( F_2 ( V_1 ) !=
V_50 )
goto V_78;
if ( F_36 ( & V_21 ) ) {
if ( ! F_22 ( & V_23 ) ) {
F_12 ( V_24
L_2
L_3
L_4 ) ;
F_37 () ;
}
V_44 = - 1 ;
V_48 . V_47 = 0 ;
V_48 . V_47 = 0 ;
}
V_78:
F_16 ( & V_4 -> V_89 ) ;
V_1 -> V_5 = NULL ;
F_13 ( & V_11 ) ;
F_14 ( V_4 ) ;
return 0 ;
}
static int F_38 ( struct V_88 * V_88 , struct V_1 * V_1 )
{
struct V_3 * V_4 ;
V_4 = F_8 ( sizeof( struct V_3 ) , V_19 ) ;
if ( ! V_4 )
return - V_20 ;
V_4 -> V_43 = - 1 ;
F_9 ( & V_11 ) ;
V_1 -> V_5 = V_4 ;
F_11 ( & V_4 -> V_89 , & V_90 ) ;
F_13 ( & V_11 ) ;
return 0 ;
}
static int F_39 ( void )
{
int V_18 ;
F_40 ( & V_21 , 0 ) ;
V_18 = F_41 ( & V_91 ) ;
if ( V_18 )
F_12 ( V_24
L_5
L_6 ,
- V_18 ) ;
return V_18 ;
}
static void F_42 ( void )
{
int V_18 ;
V_18 = F_43 ( & V_91 ) ;
if ( V_18 )
F_12 ( V_24
L_7
L_6 ,
- V_18 ) ;
}
static void F_44 ( void * V_92 )
{
struct V_93 * V_94 = V_92 ;
int V_95 = V_94 -> V_96 . V_97 ;
if ( V_95 == - V_98 || V_95 == - V_99 )
V_94 -> V_100 -> V_101 -> V_102 ( V_94 , 0 ) ;
else
V_94 -> V_100 -> V_101 -> V_103 ( V_94 ) ;
}
static void F_45 ( void * V_92 , int V_104 )
{
struct V_93 * V_94 = V_92 ;
V_94 -> V_100 -> V_101 -> V_105 ( V_94 , V_104 ) ;
}
static int F_46 ( struct V_15 * V_16 ,
int V_106 ,
struct V_93 * V_94 ,
T_5 V_107 ,
void * V_8 ,
unsigned int V_108 )
{
int V_33 ;
if ( ! V_94 -> V_96 . V_109 )
V_94 -> V_96 . V_109 = ( char * ) V_94 +
sizeof( struct V_110 ) ;
V_33 = F_47 ( V_16 -> V_111 , V_106 , & V_94 -> V_96 ,
V_107 | V_112 , V_8 , V_108 , 0 ,
F_44 , V_94 ,
F_45 ) ;
return V_33 ;
}
static int F_48 ( struct V_15 * V_16 ,
struct V_93 * V_94 ,
T_5 V_107 )
{
int V_33 ;
V_33 = F_49 ( V_16 -> V_111 , V_94 -> V_96 . V_113 ,
V_107 , & V_94 -> V_96 , V_94 ) ;
return V_33 ;
}
static int F_50 ( struct V_93 * V_94 )
{
return V_94 -> V_96 . V_97 ;
}
static int F_51 ( struct V_93 * V_94 )
{
int V_114 = V_94 -> V_96 . V_115 & V_116 ;
return ! V_114 ;
}
static void * F_52 ( struct V_93 * V_94 )
{
if ( ! V_94 -> V_96 . V_109 )
V_94 -> V_96 . V_109 = ( char * ) V_94 +
sizeof( struct V_110 ) ;
return ( void * ) ( V_94 -> V_96 . V_109 ) ;
}
static void F_53 ( struct V_93 * V_94 )
{
}
static int F_54 ( struct V_15 * V_16 ,
T_6 V_117 ,
struct V_1 * V_1 ,
int V_118 ,
struct V_119 * V_120 )
{
if ( V_118 == V_121 ) {
V_118 = V_122 ;
V_120 -> V_123 = V_124 ;
}
if ( F_55 ( V_118 ) )
return F_56 ( V_16 -> V_111 , V_117 , V_1 , V_120 ) ;
else if ( V_120 -> V_123 == V_124 )
return F_57 ( V_16 -> V_111 , V_117 , V_1 , V_120 ) ;
else
return F_58 ( V_16 -> V_111 , V_117 , V_1 , V_118 , V_120 ) ;
}
static int F_59 ( struct V_67 * V_125 ,
struct V_67 * V_126 )
{
if ( V_125 -> V_47 != V_126 -> V_47 )
return 1 ;
if ( V_125 -> V_49 > V_126 -> V_49 )
return 1 ;
if ( V_125 -> V_49 < V_126 -> V_49 )
V_126 -> V_49 = V_125 -> V_49 ;
return 0 ;
}
static int F_60 ( struct V_15 * V_16 )
{
T_7 * V_127 ;
struct V_7 * V_128 ( V_129 ) ;
int V_18 = 0 ;
F_4 ( V_16 == NULL ) ;
V_18 = F_7 ( V_16 , & V_129 ) ;
if ( V_18 )
goto V_78;
if ( F_59 ( & V_48 , & V_16 -> V_130 ) ) {
F_12 ( V_24
L_8
L_9
L_10 ,
V_16 -> V_130 . V_47 , V_16 -> V_130 . V_49 ,
V_48 . V_47 , V_48 . V_49 ) ;
V_18 = - V_131 ;
F_15 ( V_129 ) ;
goto V_78;
}
V_18 = F_61 ( V_16 -> V_14 , strlen ( V_16 -> V_14 ) ,
& V_127 , V_132 , V_133 ) ;
if ( V_18 ) {
F_15 ( V_129 ) ;
goto V_78;
}
V_16 -> V_134 = V_129 ;
V_16 -> V_111 = V_127 ;
V_78:
return V_18 ;
}
static int F_62 ( struct V_15 * V_16 )
{
F_63 ( V_16 -> V_111 , 2 ) ;
V_16 -> V_111 = NULL ;
F_15 ( V_16 -> V_134 ) ;
V_16 -> V_134 = NULL ;
return 0 ;
}
static int F_64 ( unsigned int * V_135 )
{
int V_18 ;
V_18 = F_24 () ;
if ( V_18 < 0 )
return V_18 ;
* V_135 = V_18 ;
return 0 ;
}
static int T_8 F_65 ( void )
{
int V_18 ;
V_18 = F_39 () ;
if ( ! V_18 ) {
V_18 = F_66 ( & V_69 ) ;
if ( V_18 )
F_42 () ;
}
return V_18 ;
}
static void T_9 F_67 ( void )
{
F_68 ( & V_69 ) ;
F_42 () ;
}
