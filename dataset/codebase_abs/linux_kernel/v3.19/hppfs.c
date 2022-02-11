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
int V_12 , V_18 , V_19 ;
V_12 = 0 ;
V_15 = V_4 ;
while ( V_15 -> V_9 != V_15 ) {
if ( F_3 ( V_15 ) )
V_12 += strlen ( L_1 ) + 1 ;
else V_12 += V_15 -> V_11 . V_12 + 1 ;
V_15 = V_15 -> V_9 ;
}
V_16 = L_2 ;
V_19 = strlen ( V_16 ) ;
V_12 += V_19 ;
V_13 = F_5 ( V_12 + V_14 + 1 , V_20 ) ;
if ( V_13 == NULL )
return NULL ;
V_13 [ V_12 ] = '\0' ;
V_15 = V_4 ;
while ( V_15 -> V_9 != V_15 ) {
if ( F_3 ( V_15 ) ) {
V_17 = L_1 ;
V_18 = strlen ( V_17 ) ;
}
else {
V_17 = V_15 -> V_11 . V_13 ;
V_18 = V_15 -> V_11 . V_12 ;
}
V_12 -= V_18 + 1 ;
V_13 [ V_12 ] = '/' ;
memcpy ( & V_13 [ V_12 + 1 ] , V_17 , V_18 ) ;
V_15 = V_15 -> V_9 ;
}
memcpy ( V_13 , V_16 , V_19 ) ;
return V_13 ;
}
static int F_6 ( struct V_4 * V_4 , const char * V_21 )
{
char * V_22 ;
int V_14 , V_23 ;
V_14 = 0 ;
if ( V_21 != NULL )
V_14 += strlen ( V_21 ) + 1 ;
V_22 = F_4 ( V_4 , V_14 + strlen ( L_3 ) ) ;
if ( V_22 == NULL ) {
F_7 ( V_24 L_4 ) ;
return - V_25 ;
}
if ( V_21 != NULL ) {
strcat ( V_22 , L_5 ) ;
strcat ( V_22 , V_21 ) ;
}
strcat ( V_22 , L_3 ) ;
V_23 = F_8 ( V_22 , F_9 ( F_10 () ) , 0 ) ;
F_11 ( V_22 ) ;
if ( V_23 > 0 ) {
F_12 ( V_23 ) ;
return 1 ;
}
return 0 ;
}
static struct V_4 * F_13 ( struct V_2 * V_26 , struct V_4 * V_4 ,
unsigned int V_27 )
{
struct V_4 * V_28 , * V_15 ;
struct V_29 * V_13 = & V_4 -> V_11 ;
struct V_2 * V_2 ;
int V_30 , V_31 ;
V_31 = F_6 ( V_4 , NULL ) ;
if ( V_31 < 0 )
return F_14 ( V_31 ) ;
else if ( V_31 )
return F_14 ( - V_32 ) ;
V_15 = F_1 ( V_26 ) -> V_28 ;
F_15 ( & V_15 -> V_33 -> V_34 ) ;
V_28 = F_16 ( V_13 -> V_13 , V_15 , V_13 -> V_12 ) ;
F_17 ( & V_15 -> V_33 -> V_34 ) ;
if ( F_18 ( V_28 ) )
return V_28 ;
V_30 = - V_25 ;
V_2 = F_19 ( V_26 -> V_35 , V_28 ) ;
if ( ! V_2 )
goto V_36;
F_20 ( V_4 , V_2 ) ;
return NULL ;
V_36:
return F_14 ( V_30 ) ;
}
static T_1 F_21 ( struct V_21 * V_21 , char T_2 * V_37 , T_1 V_38 ,
T_3 * V_39 , int V_40 )
{
T_1 (* F_22)( struct V_21 * , char T_2 * , T_4 , T_3 * );
T_1 V_41 ;
F_22 = F_23 ( V_21 ) -> V_42 -> F_22 ;
if ( ! V_40 )
F_24 ( V_43 ) ;
V_41 = (* F_22)( V_21 , V_37 , V_38 , & V_21 -> V_44 ) ;
if ( ! V_40 )
F_24 ( V_45 ) ;
if ( V_39 )
* V_39 = V_21 -> V_44 ;
return V_41 ;
}
static T_1 F_25 ( int V_23 , char T_2 * V_37 , T_1 V_38 )
{
T_1 V_41 ;
int V_46 , V_30 ;
char * V_47 ;
V_41 = - V_25 ;
V_47 = F_5 ( V_48 , V_20 ) ;
if ( V_47 == NULL ) {
F_7 ( V_24 L_6 ) ;
goto V_36;
}
V_41 = 0 ;
while ( V_38 > 0 ) {
V_46 = F_26 ( T_1 , V_38 , V_48 ) ;
V_30 = F_27 ( V_23 , V_47 , V_46 ) ;
if ( V_30 < 0 ) {
F_7 ( V_24 L_7
L_8 , V_30 ) ;
V_41 = V_30 ;
goto V_49;
} else if ( V_30 == 0 )
break;
if ( F_28 ( V_37 , V_47 , V_30 ) ) {
V_41 = - V_50 ;
goto V_49;
}
V_41 += V_30 ;
V_38 -= V_30 ;
}
V_49:
F_11 ( V_47 ) ;
V_36:
return V_41 ;
}
static T_1 F_29 ( struct V_21 * V_21 , char T_2 * V_37 , T_4 V_38 ,
T_3 * V_39 )
{
struct V_51 * V_52 = V_21 -> V_53 ;
struct V_54 * V_55 ;
T_3 V_56 ;
int V_30 ;
if ( V_52 -> V_57 != NULL ) {
int V_58 ;
if ( * V_39 >= V_52 -> V_12 )
return 0 ;
V_55 = V_52 -> V_57 ;
V_56 = * V_39 ;
while ( V_56 >= sizeof( V_55 -> V_57 ) ) {
V_55 = F_30 ( V_55 -> V_59 . V_60 , struct V_54 ,
V_59 ) ;
V_56 -= sizeof( V_55 -> V_57 ) ;
}
if ( V_56 + V_38 > V_52 -> V_12 )
V_38 = V_52 -> V_12 - V_56 ;
V_58 = F_28 ( V_37 , & V_55 -> V_57 [ V_56 ] , V_38 ) ;
* V_39 += V_38 - V_58 ;
if ( V_58 > 0 )
return - V_50 ;
} else if ( V_52 -> V_61 != - 1 ) {
V_30 = F_31 ( V_52 -> V_61 , * V_39 ) ;
if ( V_30 ) {
F_7 ( V_24 L_9
L_8 , V_30 ) ;
return V_30 ;
}
V_30 = F_25 ( V_52 -> V_61 , V_37 , V_38 ) ;
if ( V_30 < 0 ) {
F_7 ( V_24 L_10 , V_30 ) ;
return V_30 ;
}
V_38 = V_30 ;
if ( V_38 > 0 )
* V_39 += V_38 ;
}
else V_38 = F_21 ( V_52 -> V_62 , V_37 , V_38 , V_39 , 1 ) ;
return V_38 ;
}
static T_1 F_32 ( struct V_21 * V_21 , const char T_2 * V_37 ,
T_4 V_12 , T_3 * V_39 )
{
struct V_51 * V_55 = V_21 -> V_53 ;
struct V_21 * V_62 = V_55 -> V_62 ;
T_1 (* F_33)( struct V_21 * , const char T_2 * , T_4 , T_3 * );
F_33 = F_23 ( V_62 ) -> V_42 -> F_33 ;
return (* F_33)( V_62 , V_37 , V_12 , V_39 ) ;
}
static int F_34 ( char * V_22 , int * V_63 )
{
char * V_64 ;
int V_23 ;
V_64 = & V_22 [ strlen ( V_22 ) ] ;
strcpy ( V_64 , L_11 ) ;
* V_63 = 1 ;
V_23 = F_35 ( V_22 ) ;
if ( V_23 > 0 )
return V_23 ;
strcpy ( V_64 , L_12 ) ;
* V_63 = 0 ;
V_23 = F_35 ( V_22 ) ;
return V_23 ;
}
static void F_36 ( struct V_54 * V_65 )
{
struct V_54 * V_55 ;
struct V_66 * V_67 , * V_60 ;
if ( V_65 == NULL )
return;
F_37 (ele, next, &head->list) {
V_55 = F_30 ( V_67 , struct V_54 , V_59 ) ;
F_11 ( V_55 ) ;
}
F_11 ( V_65 ) ;
}
static struct V_54 * F_38 ( int V_23 , int V_68 ,
struct V_21 * V_62 ,
struct V_21 * V_69 ,
T_3 * V_70 )
{
struct V_54 * V_55 , * V_71 , * V_65 ;
int V_41 , V_30 ;
V_30 = - V_25 ;
V_55 = F_5 ( sizeof( * V_55 ) , V_20 ) ;
if ( V_55 == NULL ) {
F_7 ( V_24 L_13 ) ;
goto V_72;
}
F_39 ( & V_55 -> V_59 ) ;
V_65 = V_55 ;
* V_70 = 0 ;
if ( V_68 ) {
while ( ( V_41 = F_21 ( V_62 , V_55 -> V_57 ,
sizeof( V_55 -> V_57 ) , NULL , 0 ) ) > 0 )
F_40 ( V_23 , V_55 -> V_57 , V_41 ) ;
V_30 = F_41 ( V_23 , 0 , 1 ) ;
if ( V_30 ) {
F_7 ( V_24 L_14
L_15 ) ;
goto V_73;
}
}
while ( 1 ) {
V_41 = F_27 ( V_23 , V_55 -> V_57 , sizeof( V_55 -> V_57 ) ) ;
if ( V_41 < 0 ) {
V_30 = V_41 ;
F_7 ( V_24 L_16
L_8 , V_30 ) ;
goto V_73;
} else if ( V_41 == 0 )
break;
* V_70 += V_41 ;
if ( V_41 < sizeof( V_55 -> V_57 ) )
break;
V_71 = F_5 ( sizeof( * V_55 ) , V_20 ) ;
if ( V_71 == 0 ) {
F_7 ( V_24 L_17
L_18 ) ;
V_30 = - V_25 ;
goto V_73;
}
F_39 ( & V_71 -> V_59 ) ;
F_42 ( & V_71 -> V_59 , & V_55 -> V_59 ) ;
V_55 = V_71 ;
}
return V_65 ;
V_73:
F_36 ( V_65 ) ;
V_72:
return F_14 ( V_30 ) ;
}
static struct V_51 * V_54 ( void )
{
struct V_51 * V_55 ;
V_55 = F_5 ( sizeof( * V_55 ) , V_20 ) ;
if ( V_55 == NULL )
return V_55 ;
* V_55 = ( (struct V_51 ) { . V_61 = - 1 ,
. V_12 = - 1 ,
. V_57 = NULL } ) ;
return V_55 ;
}
static int F_43 ( int V_74 )
{
if ( V_74 == ( V_75 | V_76 ) )
return V_77 ;
if ( V_74 == V_75 )
return V_78 ;
if ( V_74 == V_76 )
return V_79 ;
return 0 ;
}
static int F_44 ( struct V_2 * V_2 , struct V_21 * V_21 )
{
const struct V_80 * V_80 = V_21 -> V_81 ;
struct V_51 * V_55 ;
struct V_82 V_82 ;
char * V_22 ;
int V_30 , V_23 , type , V_68 ;
V_30 = - V_25 ;
V_55 = V_54 () ;
if ( V_55 == NULL )
goto V_36;
V_22 = F_4 ( V_21 -> V_83 . V_4 , strlen ( L_11 ) ) ;
if ( V_22 == NULL )
goto V_84;
V_82 . V_85 = V_2 -> V_35 -> V_86 ;
V_82 . V_4 = F_1 ( V_2 ) -> V_28 ;
V_55 -> V_62 = F_45 ( & V_82 , F_43 ( V_21 -> V_87 ) , V_80 ) ;
V_30 = F_46 ( V_55 -> V_62 ) ;
if ( F_18 ( V_55 -> V_62 ) )
goto V_88;
type = F_47 ( V_22 ) ;
if ( type == V_89 ) {
V_23 = F_8 ( V_22 , F_9 ( F_10 () ) , 0 ) ;
if ( V_23 >= 0 )
V_55 -> V_61 = V_23 ;
else
F_7 ( V_24 L_19
L_8 , V_22 , - V_23 ) ;
V_55 -> V_57 = NULL ;
} else if ( type == V_90 ) {
V_23 = F_34 ( V_22 , & V_68 ) ;
if ( V_23 > 0 ) {
V_55 -> V_57 = F_38 ( V_23 , V_68 ,
V_55 -> V_62 ,
V_21 , & V_55 -> V_12 ) ;
if ( ! F_18 ( V_55 -> V_57 ) )
V_55 -> V_61 = V_23 ;
} else
F_7 ( V_24 L_20
L_21 , V_22 , - V_23 ) ;
}
F_11 ( V_22 ) ;
V_21 -> V_53 = V_55 ;
return 0 ;
V_88:
F_11 ( V_22 ) ;
V_84:
F_36 ( V_55 -> V_57 ) ;
F_11 ( V_55 ) ;
V_36:
return V_30 ;
}
static int F_48 ( struct V_2 * V_2 , struct V_21 * V_21 )
{
const struct V_80 * V_80 = V_21 -> V_81 ;
struct V_51 * V_55 ;
struct V_82 V_82 ;
int V_30 ;
V_30 = - V_25 ;
V_55 = V_54 () ;
if ( V_55 == NULL )
goto V_36;
V_82 . V_85 = V_2 -> V_35 -> V_86 ;
V_82 . V_4 = F_1 ( V_2 ) -> V_28 ;
V_55 -> V_62 = F_45 ( & V_82 , F_43 ( V_21 -> V_87 ) , V_80 ) ;
V_30 = F_46 ( V_55 -> V_62 ) ;
if ( F_18 ( V_55 -> V_62 ) )
goto V_49;
V_21 -> V_53 = V_55 ;
return 0 ;
V_49:
F_11 ( V_55 ) ;
V_36:
return V_30 ;
}
static T_3 F_49 ( struct V_21 * V_21 , T_3 V_56 , int V_91 )
{
struct V_51 * V_55 = V_21 -> V_53 ;
struct V_21 * V_62 = V_55 -> V_62 ;
T_3 (* F_50)( struct V_21 * , T_3 , int );
T_3 V_92 ;
F_50 = F_23 ( V_62 ) -> V_42 -> F_50 ;
if ( F_50 != NULL ) {
V_92 = (* F_50)( V_62 , V_56 , V_91 ) ;
if ( V_92 < 0 )
return V_92 ;
}
return F_51 ( V_21 , V_56 , V_91 ) ;
}
static int F_52 ( struct V_2 * V_2 , struct V_21 * V_21 )
{
struct V_51 * V_55 = V_21 -> V_53 ;
struct V_21 * V_62 = V_55 -> V_62 ;
if ( V_62 )
F_53 ( V_62 ) ;
F_11 ( V_55 ) ;
return 0 ;
}
static int F_54 ( struct V_93 * V_94 , const char * V_13 , int V_95 ,
T_3 V_96 , T_5 V_2 , unsigned int type )
{
struct V_97 * V_98 =
F_2 ( V_94 , struct V_97 , V_94 ) ;
if ( F_6 ( V_98 -> V_4 , V_13 ) )
return 0 ;
V_98 -> V_99 -> V_100 = V_98 -> V_94 . V_100 ;
return ! F_55 ( V_98 -> V_99 , V_13 , V_95 , V_2 , type ) ;
}
static int F_56 ( struct V_21 * V_21 , struct V_93 * V_94 )
{
struct V_51 * V_55 = V_21 -> V_53 ;
struct V_21 * V_62 = V_55 -> V_62 ;
struct V_97 V_101 = {
. V_94 . V_102 = F_54 ,
. V_99 = V_94 ,
. V_4 = V_21 -> V_83 . V_4
} ;
int V_30 ;
V_62 -> V_44 = V_94 -> V_100 ;
V_30 = F_57 ( V_62 , & V_101 . V_94 ) ;
V_94 -> V_100 = V_101 . V_94 . V_100 ;
return V_30 ;
}
static int F_58 ( struct V_4 * V_4 , struct V_103 * V_104 )
{
V_104 -> V_105 = 0 ;
V_104 -> V_106 = 0 ;
V_104 -> V_107 = 0 ;
V_104 -> V_108 = 0 ;
V_104 -> V_109 = 0 ;
V_104 -> V_110 = V_111 ;
return 0 ;
}
static struct V_2 * F_59 ( struct V_5 * V_6 )
{
struct V_1 * V_112 ;
V_112 = F_5 ( sizeof( * V_112 ) , V_20 ) ;
if ( ! V_112 )
return NULL ;
V_112 -> V_28 = NULL ;
F_60 ( & V_112 -> V_3 ) ;
return & V_112 -> V_3 ;
}
void F_61 ( struct V_2 * V_26 )
{
F_62 ( V_26 ) ;
F_63 ( F_1 ( V_26 ) -> V_28 ) ;
F_64 ( V_26 -> V_35 -> V_86 ) ;
}
static void F_65 ( struct V_113 * V_65 )
{
struct V_2 * V_2 = F_2 ( V_65 , struct V_2 , V_114 ) ;
F_11 ( F_1 ( V_2 ) ) ;
}
static void F_66 ( struct V_2 * V_2 )
{
F_67 ( & V_2 -> V_114 , F_65 ) ;
}
static int F_68 ( struct V_4 * V_4 , char T_2 * V_115 ,
int V_116 )
{
struct V_4 * V_28 = F_1 ( V_4 -> V_33 ) -> V_28 ;
return V_28 -> V_33 -> V_117 -> V_118 ( V_28 , V_115 ,
V_116 ) ;
}
static void * F_69 ( struct V_4 * V_4 , struct V_119 * V_120 )
{
struct V_4 * V_28 = F_1 ( V_4 -> V_33 ) -> V_28 ;
return V_28 -> V_33 -> V_117 -> V_121 ( V_28 , V_120 ) ;
}
static void F_70 ( struct V_4 * V_4 , struct V_119 * V_120 ,
void * V_122 )
{
struct V_4 * V_28 = F_1 ( V_4 -> V_33 ) -> V_28 ;
if ( V_28 -> V_33 -> V_117 -> V_123 )
V_28 -> V_33 -> V_117 -> V_123 ( V_28 , V_120 , V_122 ) ;
}
static struct V_2 * F_19 ( struct V_5 * V_6 , struct V_4 * V_4 )
{
struct V_2 * V_124 = V_4 -> V_33 ;
struct V_2 * V_2 = F_71 ( V_6 ) ;
if ( ! V_2 ) {
F_63 ( V_4 ) ;
return NULL ;
}
if ( F_72 ( V_4 -> V_33 -> V_125 ) ) {
V_2 -> V_117 = & V_126 ;
V_2 -> V_42 = & V_127 ;
} else if ( F_73 ( V_4 -> V_33 -> V_125 ) ) {
V_2 -> V_117 = & V_128 ;
V_2 -> V_42 = & V_129 ;
} else {
V_2 -> V_117 = & V_130 ;
V_2 -> V_42 = & V_129 ;
}
F_1 ( V_2 ) -> V_28 = V_4 ;
V_2 -> V_131 = V_124 -> V_131 ;
V_2 -> V_132 = V_124 -> V_132 ;
V_2 -> V_133 = V_124 -> V_133 ;
V_2 -> V_134 = V_124 -> V_134 ;
V_2 -> V_135 = V_124 -> V_135 ;
V_2 -> V_136 = V_124 -> V_136 ;
V_2 -> V_125 = V_124 -> V_125 ;
F_74 ( V_2 , V_124 -> V_137 ) ;
V_2 -> V_138 = V_124 -> V_138 ;
V_2 -> V_139 = V_124 -> V_139 ;
return V_2 ;
}
static int F_75 ( struct V_5 * V_6 , void * V_101 , int V_140 )
{
struct V_2 * V_141 ;
struct V_142 * V_143 ;
int V_30 = - V_32 ;
V_143 = F_76 ( F_77 ( V_144 ) -> V_143 ) ;
if ( F_18 ( V_143 ) )
goto V_36;
V_6 -> V_145 = 1024 ;
V_6 -> V_146 = 10 ;
V_6 -> V_147 = V_111 ;
V_6 -> V_148 = & V_149 ;
V_6 -> V_86 = V_143 ;
V_30 = - V_25 ;
V_141 = F_19 ( V_6 , F_78 ( V_143 -> V_150 ) ) ;
V_6 -> V_10 = F_79 ( V_141 ) ;
if ( ! V_6 -> V_10 )
goto V_151;
return 0 ;
V_151:
F_64 ( V_143 ) ;
V_36:
return ( V_30 ) ;
}
static struct V_4 * F_80 ( struct V_152 * type ,
int V_27 , const char * V_153 ,
void * V_55 )
{
return F_81 ( type , V_27 , V_55 , F_75 ) ;
}
static int T_6 F_82 ( void )
{
return F_83 ( & V_154 ) ;
}
static void T_7 F_84 ( void )
{
F_85 ( & V_154 ) ;
}
