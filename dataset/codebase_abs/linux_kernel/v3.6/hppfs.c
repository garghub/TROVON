static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_2 ( V_2 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
V_6 = V_4 -> V_8 ;
if ( V_4 -> V_9 != V_6 -> V_10 )
return 0 ;
for ( V_7 = 0 ; V_7 < V_4 -> V_11 . V_12 ; V_7 ++ ) {
if ( ! isdigit ( V_4 -> V_11 . V_13 [ V_7 ] ) )
return 0 ;
}
return 1 ;
}
static char * F_4 ( struct V_4 * V_4 , int V_14 )
{
struct V_4 * V_15 ;
char * V_16 , * V_13 ;
const char * V_17 ;
int V_12 , V_18 ;
V_12 = 0 ;
V_15 = V_4 ;
while ( V_15 -> V_9 != V_15 ) {
if ( F_3 ( V_15 ) )
V_12 += strlen ( L_1 ) + 1 ;
else V_12 += V_15 -> V_11 . V_12 + 1 ;
V_15 = V_15 -> V_9 ;
}
V_16 = L_2 ;
V_12 += strlen ( V_16 ) ;
V_13 = F_5 ( V_12 + V_14 + 1 , V_19 ) ;
if ( V_13 == NULL )
return NULL ;
V_13 [ V_12 ] = '\0' ;
V_15 = V_4 ;
while ( V_15 -> V_9 != V_15 ) {
if ( F_3 ( V_15 ) ) {
V_17 = L_1 ;
V_18 = strlen ( L_1 ) ;
}
else {
V_17 = V_15 -> V_11 . V_13 ;
V_18 = V_15 -> V_11 . V_12 ;
}
V_12 -= V_18 + 1 ;
V_13 [ V_12 ] = '/' ;
strncpy ( & V_13 [ V_12 + 1 ] , V_17 , V_18 ) ;
V_15 = V_15 -> V_9 ;
}
strncpy ( V_13 , V_16 , strlen ( V_16 ) ) ;
return V_13 ;
}
static int F_6 ( struct V_4 * V_4 , const char * V_20 )
{
char * V_21 ;
int V_14 , V_22 ;
V_14 = 0 ;
if ( V_20 != NULL )
V_14 += strlen ( V_20 ) + 1 ;
V_21 = F_4 ( V_4 , V_14 + strlen ( L_3 ) ) ;
if ( V_21 == NULL ) {
F_7 ( V_23 L_4 ) ;
return - V_24 ;
}
if ( V_20 != NULL ) {
strcat ( V_21 , L_5 ) ;
strcat ( V_21 , V_20 ) ;
}
strcat ( V_21 , L_3 ) ;
V_22 = F_8 ( V_21 , F_9 ( F_10 () ) , 0 ) ;
F_11 ( V_21 ) ;
if ( V_22 > 0 ) {
F_12 ( V_22 ) ;
return 1 ;
}
return 0 ;
}
static struct V_4 * F_13 ( struct V_2 * V_25 , struct V_4 * V_4 ,
unsigned int V_26 )
{
struct V_4 * V_27 , * V_15 ;
struct V_28 * V_13 = & V_4 -> V_11 ;
struct V_2 * V_2 ;
int V_29 , V_30 ;
V_30 = F_6 ( V_4 , NULL ) ;
if ( V_30 < 0 )
return F_14 ( V_30 ) ;
else if ( V_30 )
return F_14 ( - V_31 ) ;
V_15 = F_1 ( V_25 ) -> V_27 ;
F_15 ( & V_15 -> V_32 -> V_33 ) ;
V_27 = F_16 ( V_13 -> V_13 , V_15 , V_13 -> V_12 ) ;
F_17 ( & V_15 -> V_32 -> V_33 ) ;
if ( F_18 ( V_27 ) )
return V_27 ;
V_29 = - V_24 ;
V_2 = F_19 ( V_25 -> V_34 , V_27 ) ;
if ( ! V_2 )
goto V_35;
F_20 ( V_4 , V_2 ) ;
return NULL ;
V_35:
return F_14 ( V_29 ) ;
}
static T_1 F_21 ( struct V_20 * V_20 , char T_2 * V_36 , T_1 V_37 ,
T_3 * V_38 , int V_39 )
{
T_1 (* F_22)( struct V_20 * , char T_2 * , T_4 , T_3 * );
T_1 V_40 ;
F_22 = V_20 -> V_41 . V_4 -> V_32 -> V_42 -> F_22 ;
if ( ! V_39 )
F_23 ( V_43 ) ;
V_40 = (* F_22)( V_20 , V_36 , V_37 , & V_20 -> V_44 ) ;
if ( ! V_39 )
F_23 ( V_45 ) ;
if ( V_38 )
* V_38 = V_20 -> V_44 ;
return V_40 ;
}
static T_1 F_24 ( int V_22 , char T_2 * V_36 , T_1 V_37 )
{
T_1 V_40 ;
int V_46 , V_29 ;
char * V_47 ;
V_40 = - V_24 ;
V_47 = F_5 ( V_48 , V_19 ) ;
if ( V_47 == NULL ) {
F_7 ( V_23 L_6 ) ;
goto V_35;
}
V_40 = 0 ;
while ( V_37 > 0 ) {
V_46 = F_25 ( T_1 , V_37 , V_48 ) ;
V_29 = F_26 ( V_22 , V_47 , V_46 ) ;
if ( V_29 < 0 ) {
F_7 ( V_23 L_7
L_8 , V_29 ) ;
V_40 = V_29 ;
goto V_49;
} else if ( V_29 == 0 )
break;
if ( F_27 ( V_36 , V_47 , V_29 ) ) {
V_40 = - V_50 ;
goto V_49;
}
V_40 += V_29 ;
V_37 -= V_29 ;
}
V_49:
F_11 ( V_47 ) ;
V_35:
return V_40 ;
}
static T_1 F_28 ( struct V_20 * V_20 , char T_2 * V_36 , T_4 V_37 ,
T_3 * V_38 )
{
struct V_51 * V_52 = V_20 -> V_53 ;
struct V_54 * V_55 ;
T_3 V_56 ;
int V_29 ;
if ( V_52 -> V_57 != NULL ) {
int V_58 ;
if ( * V_38 >= V_52 -> V_12 )
return 0 ;
V_55 = V_52 -> V_57 ;
V_56 = * V_38 ;
while ( V_56 >= sizeof( V_55 -> V_57 ) ) {
V_55 = F_29 ( V_55 -> V_59 . V_60 , struct V_54 ,
V_59 ) ;
V_56 -= sizeof( V_55 -> V_57 ) ;
}
if ( V_56 + V_37 > V_52 -> V_12 )
V_37 = V_52 -> V_12 - V_56 ;
V_58 = F_27 ( V_36 , & V_55 -> V_57 [ V_56 ] , V_37 ) ;
* V_38 += V_37 - V_58 ;
if ( V_58 > 0 )
return - V_50 ;
} else if ( V_52 -> V_61 != - 1 ) {
V_29 = F_30 ( V_52 -> V_61 , * V_38 ) ;
if ( V_29 ) {
F_7 ( V_23 L_9
L_8 , V_29 ) ;
return V_29 ;
}
V_29 = F_24 ( V_52 -> V_61 , V_36 , V_37 ) ;
if ( V_29 < 0 ) {
F_7 ( V_23 L_10 , V_29 ) ;
return V_29 ;
}
V_37 = V_29 ;
if ( V_37 > 0 )
* V_38 += V_37 ;
}
else V_37 = F_21 ( V_52 -> V_62 , V_36 , V_37 , V_38 , 1 ) ;
return V_37 ;
}
static T_1 F_31 ( struct V_20 * V_20 , const char T_2 * V_36 ,
T_4 V_12 , T_3 * V_38 )
{
struct V_51 * V_55 = V_20 -> V_53 ;
struct V_20 * V_62 = V_55 -> V_62 ;
T_1 (* F_32)( struct V_20 * , const char T_2 * , T_4 , T_3 * );
F_32 = V_62 -> V_41 . V_4 -> V_32 -> V_42 -> F_32 ;
return (* F_32)( V_62 , V_36 , V_12 , V_38 ) ;
}
static int F_33 ( char * V_21 , int * V_63 )
{
char * V_64 ;
int V_22 ;
V_64 = & V_21 [ strlen ( V_21 ) ] ;
strcpy ( V_64 , L_11 ) ;
* V_63 = 1 ;
V_22 = F_34 ( V_21 ) ;
if ( V_22 > 0 )
return V_22 ;
strcpy ( V_64 , L_12 ) ;
* V_63 = 0 ;
V_22 = F_34 ( V_21 ) ;
return V_22 ;
}
static void F_35 ( struct V_54 * V_65 )
{
struct V_54 * V_55 ;
struct V_66 * V_67 , * V_60 ;
if ( V_65 == NULL )
return;
F_36 (ele, next, &head->list) {
V_55 = F_29 ( V_67 , struct V_54 , V_59 ) ;
F_11 ( V_55 ) ;
}
F_11 ( V_65 ) ;
}
static struct V_54 * F_37 ( int V_22 , int V_68 ,
struct V_20 * V_62 ,
struct V_20 * V_69 ,
T_3 * V_70 )
{
struct V_54 * V_55 , * V_71 , * V_65 ;
int V_40 , V_29 ;
V_29 = - V_24 ;
V_55 = F_5 ( sizeof( * V_55 ) , V_19 ) ;
if ( V_55 == NULL ) {
F_7 ( V_23 L_13 ) ;
goto V_72;
}
F_38 ( & V_55 -> V_59 ) ;
V_65 = V_55 ;
* V_70 = 0 ;
if ( V_68 ) {
while ( ( V_40 = F_21 ( V_62 , V_55 -> V_57 ,
sizeof( V_55 -> V_57 ) , NULL , 0 ) ) > 0 )
F_39 ( V_22 , V_55 -> V_57 , V_40 ) ;
V_29 = F_40 ( V_22 , 0 , 1 ) ;
if ( V_29 ) {
F_7 ( V_23 L_14
L_15 ) ;
goto V_73;
}
}
while ( 1 ) {
V_40 = F_26 ( V_22 , V_55 -> V_57 , sizeof( V_55 -> V_57 ) ) ;
if ( V_40 < 0 ) {
V_29 = V_40 ;
F_7 ( V_23 L_16
L_8 , V_29 ) ;
goto V_73;
} else if ( V_40 == 0 )
break;
* V_70 += V_40 ;
if ( V_40 < sizeof( V_55 -> V_57 ) )
break;
V_71 = F_5 ( sizeof( * V_55 ) , V_19 ) ;
if ( V_71 == 0 ) {
F_7 ( V_23 L_17
L_18 ) ;
V_29 = - V_24 ;
goto V_73;
}
F_38 ( & V_71 -> V_59 ) ;
F_41 ( & V_71 -> V_59 , & V_55 -> V_59 ) ;
V_55 = V_71 ;
}
return V_65 ;
V_73:
F_35 ( V_65 ) ;
V_72:
return F_14 ( V_29 ) ;
}
static struct V_51 * V_54 ( void )
{
struct V_51 * V_55 ;
V_55 = F_5 ( sizeof( * V_55 ) , V_19 ) ;
if ( V_55 == NULL )
return V_55 ;
* V_55 = ( (struct V_51 ) { . V_61 = - 1 ,
. V_12 = - 1 ,
. V_57 = NULL } ) ;
return V_55 ;
}
static int F_42 ( int V_74 )
{
if ( V_74 == ( V_75 | V_76 ) )
return V_77 ;
if ( V_74 == V_75 )
return V_78 ;
if ( V_74 == V_76 )
return V_79 ;
return 0 ;
}
static int F_43 ( struct V_2 * V_2 , struct V_20 * V_20 )
{
const struct V_80 * V_80 = V_20 -> V_81 ;
struct V_51 * V_55 ;
struct V_82 V_82 ;
char * V_21 ;
int V_29 , V_22 , type , V_68 ;
V_29 = - V_24 ;
V_55 = V_54 () ;
if ( V_55 == NULL )
goto V_35;
V_21 = F_4 ( V_20 -> V_41 . V_4 , strlen ( L_11 ) ) ;
if ( V_21 == NULL )
goto V_83;
V_82 . V_84 = V_2 -> V_34 -> V_85 ;
V_82 . V_4 = F_1 ( V_2 ) -> V_27 ;
V_55 -> V_62 = F_44 ( & V_82 , F_42 ( V_20 -> V_86 ) , V_80 ) ;
V_29 = F_45 ( V_55 -> V_62 ) ;
if ( F_18 ( V_55 -> V_62 ) )
goto V_87;
type = F_46 ( V_21 ) ;
if ( type == V_88 ) {
V_22 = F_8 ( V_21 , F_9 ( F_10 () ) , 0 ) ;
if ( V_22 >= 0 )
V_55 -> V_61 = V_22 ;
else
F_7 ( V_23 L_19
L_8 , V_21 , - V_22 ) ;
V_55 -> V_57 = NULL ;
} else if ( type == V_89 ) {
V_22 = F_33 ( V_21 , & V_68 ) ;
if ( V_22 > 0 ) {
V_55 -> V_57 = F_37 ( V_22 , V_68 ,
V_55 -> V_62 ,
V_20 , & V_55 -> V_12 ) ;
if ( ! F_18 ( V_55 -> V_57 ) )
V_55 -> V_61 = V_22 ;
} else
F_7 ( V_23 L_20
L_21 , V_21 , - V_22 ) ;
}
F_11 ( V_21 ) ;
V_20 -> V_53 = V_55 ;
return 0 ;
V_87:
F_11 ( V_21 ) ;
V_83:
F_35 ( V_55 -> V_57 ) ;
F_11 ( V_55 ) ;
V_35:
return V_29 ;
}
static int F_47 ( struct V_2 * V_2 , struct V_20 * V_20 )
{
const struct V_80 * V_80 = V_20 -> V_81 ;
struct V_51 * V_55 ;
struct V_82 V_82 ;
int V_29 ;
V_29 = - V_24 ;
V_55 = V_54 () ;
if ( V_55 == NULL )
goto V_35;
V_82 . V_84 = V_2 -> V_34 -> V_85 ;
V_82 . V_4 = F_1 ( V_2 ) -> V_27 ;
V_55 -> V_62 = F_44 ( & V_82 , F_42 ( V_20 -> V_86 ) , V_80 ) ;
V_29 = F_45 ( V_55 -> V_62 ) ;
if ( F_18 ( V_55 -> V_62 ) )
goto V_49;
V_20 -> V_53 = V_55 ;
return 0 ;
V_49:
F_11 ( V_55 ) ;
V_35:
return V_29 ;
}
static T_3 F_48 ( struct V_20 * V_20 , T_3 V_56 , int V_90 )
{
struct V_51 * V_55 = V_20 -> V_53 ;
struct V_20 * V_62 = V_55 -> V_62 ;
T_3 (* F_49)( struct V_20 * , T_3 , int );
T_3 V_91 ;
F_49 = V_62 -> V_41 . V_4 -> V_32 -> V_42 -> F_49 ;
if ( F_49 != NULL ) {
V_91 = (* F_49)( V_62 , V_56 , V_90 ) ;
if ( V_91 < 0 )
return V_91 ;
}
return F_50 ( V_20 , V_56 , V_90 ) ;
}
static int F_51 ( void * V_92 , const char * V_13 , int V_93 ,
T_3 V_94 , T_5 V_2 , unsigned int type )
{
struct V_95 * V_96 = V_92 ;
if ( F_6 ( V_96 -> V_4 , V_13 ) )
return 0 ;
return (* V_96 -> V_97 )( V_96 -> V_98 , V_13 , V_93 , V_94 ,
V_2 , type ) ;
}
static int F_52 ( struct V_20 * V_20 , void * V_99 , T_6 V_97 )
{
struct V_51 * V_55 = V_20 -> V_53 ;
struct V_20 * V_62 = V_55 -> V_62 ;
int (* F_53)( struct V_20 * , void * , T_6 );
struct V_95 V_96 = ( (struct V_95 )
{ . V_98 = V_99 ,
. V_97 = V_97 ,
. V_4 = V_20 -> V_41 . V_4
} ) ;
int V_29 ;
F_53 = V_62 -> V_41 . V_4 -> V_32 -> V_42 -> F_53 ;
V_62 -> V_44 = V_20 -> V_44 ;
V_29 = (* F_53)( V_62 , & V_96 , F_51 ) ;
V_20 -> V_44 = V_62 -> V_44 ;
return V_29 ;
}
static int F_54 ( struct V_20 * V_20 , T_3 V_100 , T_3 V_64 ,
int V_101 )
{
return F_55 ( V_20 -> V_102 , V_100 , V_64 ) ;
}
static int F_56 ( struct V_4 * V_4 , struct V_103 * V_104 )
{
V_104 -> V_105 = 0 ;
V_104 -> V_106 = 0 ;
V_104 -> V_107 = 0 ;
V_104 -> V_108 = 0 ;
V_104 -> V_109 = 0 ;
V_104 -> V_110 = V_111 ;
return 0 ;
}
static struct V_2 * F_57 ( struct V_5 * V_6 )
{
struct V_1 * V_112 ;
V_112 = F_5 ( sizeof( * V_112 ) , V_19 ) ;
if ( ! V_112 )
return NULL ;
V_112 -> V_27 = NULL ;
F_58 ( & V_112 -> V_3 ) ;
return & V_112 -> V_3 ;
}
void F_59 ( struct V_2 * V_25 )
{
F_60 ( V_25 ) ;
F_61 ( F_1 ( V_25 ) -> V_27 ) ;
F_62 ( V_25 -> V_34 -> V_85 ) ;
}
static void F_63 ( struct V_113 * V_65 )
{
struct V_2 * V_2 = F_2 ( V_65 , struct V_2 , V_114 ) ;
F_11 ( F_1 ( V_2 ) ) ;
}
static void F_64 ( struct V_2 * V_2 )
{
F_65 ( & V_2 -> V_114 , F_63 ) ;
}
static int F_66 ( struct V_4 * V_4 , char T_2 * V_115 ,
int V_116 )
{
struct V_4 * V_27 = F_1 ( V_4 -> V_32 ) -> V_27 ;
return V_27 -> V_32 -> V_117 -> V_118 ( V_27 , V_115 ,
V_116 ) ;
}
static void * F_67 ( struct V_4 * V_4 , struct V_119 * V_120 )
{
struct V_4 * V_27 = F_1 ( V_4 -> V_32 ) -> V_27 ;
return V_27 -> V_32 -> V_117 -> V_121 ( V_27 , V_120 ) ;
}
static void F_68 ( struct V_4 * V_4 , struct V_119 * V_120 ,
void * V_122 )
{
struct V_4 * V_27 = F_1 ( V_4 -> V_32 ) -> V_27 ;
if ( V_27 -> V_32 -> V_117 -> V_123 )
V_27 -> V_32 -> V_117 -> V_123 ( V_27 , V_120 , V_122 ) ;
}
static struct V_2 * F_19 ( struct V_5 * V_6 , struct V_4 * V_4 )
{
struct V_2 * V_124 = V_4 -> V_32 ;
struct V_2 * V_2 = F_69 ( V_6 ) ;
if ( ! V_2 ) {
F_61 ( V_4 ) ;
return F_14 ( - V_24 ) ;
}
if ( F_70 ( V_4 -> V_32 -> V_125 ) ) {
V_2 -> V_117 = & V_126 ;
V_2 -> V_42 = & V_127 ;
} else if ( F_71 ( V_4 -> V_32 -> V_125 ) ) {
V_2 -> V_117 = & V_128 ;
V_2 -> V_42 = & V_129 ;
} else {
V_2 -> V_117 = & V_130 ;
V_2 -> V_42 = & V_129 ;
}
F_1 ( V_2 ) -> V_27 = V_4 ;
V_2 -> V_131 = V_124 -> V_131 ;
V_2 -> V_132 = V_124 -> V_132 ;
V_2 -> V_133 = V_124 -> V_133 ;
V_2 -> V_134 = V_124 -> V_134 ;
V_2 -> V_135 = V_124 -> V_135 ;
V_2 -> V_136 = V_124 -> V_136 ;
V_2 -> V_125 = V_124 -> V_125 ;
F_72 ( V_2 , V_124 -> V_137 ) ;
V_2 -> V_138 = V_124 -> V_138 ;
V_2 -> V_139 = V_124 -> V_139 ;
return V_2 ;
}
static int F_73 ( struct V_5 * V_6 , void * V_92 , int V_140 )
{
struct V_2 * V_141 ;
struct V_142 * V_143 ;
int V_29 = - V_31 ;
V_143 = F_74 ( V_144 -> V_145 -> V_146 -> V_143 ) ;
if ( F_18 ( V_143 ) )
goto V_35;
V_6 -> V_147 = 1024 ;
V_6 -> V_148 = 10 ;
V_6 -> V_149 = V_111 ;
V_6 -> V_150 = & V_151 ;
V_6 -> V_85 = V_143 ;
V_29 = - V_24 ;
V_141 = F_19 ( V_6 , F_75 ( V_143 -> V_152 ) ) ;
V_6 -> V_10 = F_76 ( V_141 ) ;
if ( ! V_6 -> V_10 )
goto V_153;
return 0 ;
V_153:
F_62 ( V_143 ) ;
V_35:
return ( V_29 ) ;
}
static struct V_4 * F_77 ( struct V_154 * type ,
int V_26 , const char * V_155 ,
void * V_55 )
{
return F_78 ( type , V_26 , V_55 , F_73 ) ;
}
static int T_7 F_79 ( void )
{
return F_80 ( & V_156 ) ;
}
static void T_8 F_81 ( void )
{
F_82 ( & V_156 ) ;
}
