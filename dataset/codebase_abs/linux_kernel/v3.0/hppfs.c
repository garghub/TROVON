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
struct V_26 * V_27 )
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
V_15 = F_1 ( V_25 ) -> V_28 ;
F_15 ( & V_15 -> V_33 -> V_34 ) ;
V_28 = F_16 ( V_13 -> V_13 , V_15 , V_13 -> V_12 ) ;
F_17 ( & V_15 -> V_33 -> V_34 ) ;
if ( F_18 ( V_28 ) )
return V_28 ;
V_30 = - V_24 ;
V_2 = F_19 ( V_25 -> V_35 , V_28 ) ;
if ( ! V_2 )
goto V_36;
F_20 ( V_4 , V_2 ) ;
return NULL ;
V_36:
return F_14 ( V_30 ) ;
}
static T_1 F_21 ( struct V_20 * V_20 , char T_2 * V_37 , T_1 V_38 ,
T_3 * V_39 , int V_40 )
{
T_1 (* F_22)( struct V_20 * , char T_2 * , T_4 , T_3 * );
T_1 V_41 ;
F_22 = V_20 -> V_42 . V_4 -> V_33 -> V_43 -> F_22 ;
if ( ! V_40 )
F_23 ( V_44 ) ;
V_41 = (* F_22)( V_20 , V_37 , V_38 , & V_20 -> V_45 ) ;
if ( ! V_40 )
F_23 ( V_46 ) ;
if ( V_39 )
* V_39 = V_20 -> V_45 ;
return V_41 ;
}
static T_1 F_24 ( int V_22 , char T_2 * V_37 , T_1 V_38 )
{
T_1 V_41 ;
int V_47 , V_30 ;
char * V_48 ;
V_41 = - V_24 ;
V_48 = F_5 ( V_49 , V_19 ) ;
if ( V_48 == NULL ) {
F_7 ( V_23 L_6 ) ;
goto V_36;
}
V_41 = 0 ;
while ( V_38 > 0 ) {
V_47 = F_25 ( T_1 , V_38 , V_49 ) ;
V_30 = F_26 ( V_22 , V_48 , V_47 ) ;
if ( V_30 < 0 ) {
F_7 ( V_23 L_7
L_8 , V_30 ) ;
V_41 = V_30 ;
goto V_50;
} else if ( V_30 == 0 )
break;
if ( F_27 ( V_37 , V_48 , V_30 ) ) {
V_41 = - V_51 ;
goto V_50;
}
V_41 += V_30 ;
V_38 -= V_30 ;
}
V_50:
F_11 ( V_48 ) ;
V_36:
return V_41 ;
}
static T_1 F_28 ( struct V_20 * V_20 , char T_2 * V_37 , T_4 V_38 ,
T_3 * V_39 )
{
struct V_52 * V_53 = V_20 -> V_54 ;
struct V_55 * V_56 ;
T_3 V_57 ;
int V_30 ;
if ( V_53 -> V_58 != NULL ) {
int V_59 ;
if ( * V_39 >= V_53 -> V_12 )
return 0 ;
V_56 = V_53 -> V_58 ;
V_57 = * V_39 ;
while ( V_57 >= sizeof( V_56 -> V_58 ) ) {
V_56 = F_29 ( V_56 -> V_60 . V_61 , struct V_55 ,
V_60 ) ;
V_57 -= sizeof( V_56 -> V_58 ) ;
}
if ( V_57 + V_38 > V_53 -> V_12 )
V_38 = V_53 -> V_12 - V_57 ;
V_59 = F_27 ( V_37 , & V_56 -> V_58 [ V_57 ] , V_38 ) ;
* V_39 += V_38 - V_59 ;
if ( V_59 > 0 )
return - V_51 ;
} else if ( V_53 -> V_62 != - 1 ) {
V_30 = F_30 ( V_53 -> V_62 , * V_39 ) ;
if ( V_30 ) {
F_7 ( V_23 L_9
L_8 , V_30 ) ;
return V_30 ;
}
V_30 = F_24 ( V_53 -> V_62 , V_37 , V_38 ) ;
if ( V_30 < 0 ) {
F_7 ( V_23 L_10 , V_30 ) ;
return V_30 ;
}
V_38 = V_30 ;
if ( V_38 > 0 )
* V_39 += V_38 ;
}
else V_38 = F_21 ( V_53 -> V_63 , V_37 , V_38 , V_39 , 1 ) ;
return V_38 ;
}
static T_1 F_31 ( struct V_20 * V_20 , const char T_2 * V_37 ,
T_4 V_12 , T_3 * V_39 )
{
struct V_52 * V_56 = V_20 -> V_54 ;
struct V_20 * V_63 = V_56 -> V_63 ;
T_1 (* F_32)( struct V_20 * , const char T_2 * , T_4 , T_3 * );
F_32 = V_63 -> V_42 . V_4 -> V_33 -> V_43 -> F_32 ;
return (* F_32)( V_63 , V_37 , V_12 , V_39 ) ;
}
static int F_33 ( char * V_21 , int * V_64 )
{
char * V_65 ;
int V_22 ;
V_65 = & V_21 [ strlen ( V_21 ) ] ;
strcpy ( V_65 , L_11 ) ;
* V_64 = 1 ;
V_22 = F_34 ( V_21 ) ;
if ( V_22 > 0 )
return V_22 ;
strcpy ( V_65 , L_12 ) ;
* V_64 = 0 ;
V_22 = F_34 ( V_21 ) ;
return V_22 ;
}
static void F_35 ( struct V_55 * V_66 )
{
struct V_55 * V_56 ;
struct V_67 * V_68 , * V_61 ;
if ( V_66 == NULL )
return;
F_36 (ele, next, &head->list) {
V_56 = F_29 ( V_68 , struct V_55 , V_60 ) ;
F_11 ( V_56 ) ;
}
F_11 ( V_66 ) ;
}
static struct V_55 * F_37 ( int V_22 , int V_69 ,
struct V_20 * V_63 ,
struct V_20 * V_70 ,
T_3 * V_71 )
{
struct V_55 * V_56 , * V_72 , * V_66 ;
int V_41 , V_30 ;
V_30 = - V_24 ;
V_56 = F_5 ( sizeof( * V_56 ) , V_19 ) ;
if ( V_56 == NULL ) {
F_7 ( V_23 L_13 ) ;
goto V_73;
}
F_38 ( & V_56 -> V_60 ) ;
V_66 = V_56 ;
* V_71 = 0 ;
if ( V_69 ) {
while ( ( V_41 = F_21 ( V_63 , V_56 -> V_58 ,
sizeof( V_56 -> V_58 ) , NULL , 0 ) ) > 0 )
F_39 ( V_22 , V_56 -> V_58 , V_41 ) ;
V_30 = F_40 ( V_22 , 0 , 1 ) ;
if ( V_30 ) {
F_7 ( V_23 L_14
L_15 ) ;
goto V_74;
}
}
while ( 1 ) {
V_41 = F_26 ( V_22 , V_56 -> V_58 , sizeof( V_56 -> V_58 ) ) ;
if ( V_41 < 0 ) {
V_30 = V_41 ;
F_7 ( V_23 L_16
L_8 , V_30 ) ;
goto V_74;
} else if ( V_41 == 0 )
break;
* V_71 += V_41 ;
if ( V_41 < sizeof( V_56 -> V_58 ) )
break;
V_72 = F_5 ( sizeof( * V_56 ) , V_19 ) ;
if ( V_72 == 0 ) {
F_7 ( V_23 L_17
L_18 ) ;
V_30 = - V_24 ;
goto V_74;
}
F_38 ( & V_72 -> V_60 ) ;
F_41 ( & V_72 -> V_60 , & V_56 -> V_60 ) ;
V_56 = V_72 ;
}
return V_66 ;
V_74:
F_35 ( V_66 ) ;
V_73:
return F_14 ( V_30 ) ;
}
static struct V_52 * V_55 ( void )
{
struct V_52 * V_56 ;
V_56 = F_5 ( sizeof( * V_56 ) , V_19 ) ;
if ( V_56 == NULL )
return V_56 ;
* V_56 = ( (struct V_52 ) { . V_62 = - 1 ,
. V_12 = - 1 ,
. V_58 = NULL } ) ;
return V_56 ;
}
static int F_42 ( int V_75 )
{
if ( V_75 == ( V_76 | V_77 ) )
return V_78 ;
if ( V_75 == V_76 )
return V_79 ;
if ( V_75 == V_77 )
return V_80 ;
return 0 ;
}
static int F_43 ( struct V_2 * V_2 , struct V_20 * V_20 )
{
const struct V_81 * V_81 = V_20 -> V_82 ;
struct V_52 * V_56 ;
struct V_83 * V_84 ;
struct V_4 * V_28 ;
char * V_21 ;
int V_30 , V_22 , type , V_69 ;
V_30 = - V_24 ;
V_56 = V_55 () ;
if ( V_56 == NULL )
goto V_36;
V_21 = F_4 ( V_20 -> V_42 . V_4 , strlen ( L_11 ) ) ;
if ( V_21 == NULL )
goto V_85;
V_28 = F_1 ( V_2 ) -> V_28 ;
V_84 = V_2 -> V_35 -> V_86 ;
V_56 -> V_63 = F_44 ( F_45 ( V_28 ) , F_46 ( V_84 ) ,
F_42 ( V_20 -> V_87 ) , V_81 ) ;
V_30 = F_47 ( V_56 -> V_63 ) ;
if ( F_18 ( V_56 -> V_63 ) )
goto V_88;
type = F_48 ( V_21 ) ;
if ( type == V_89 ) {
V_22 = F_8 ( V_21 , F_9 ( F_10 () ) , 0 ) ;
if ( V_22 >= 0 )
V_56 -> V_62 = V_22 ;
else
F_7 ( V_23 L_19
L_8 , V_21 , - V_22 ) ;
V_56 -> V_58 = NULL ;
} else if ( type == V_90 ) {
V_22 = F_33 ( V_21 , & V_69 ) ;
if ( V_22 > 0 ) {
V_56 -> V_58 = F_37 ( V_22 , V_69 ,
V_56 -> V_63 ,
V_20 , & V_56 -> V_12 ) ;
if ( ! F_18 ( V_56 -> V_58 ) )
V_56 -> V_62 = V_22 ;
} else
F_7 ( V_23 L_20
L_21 , V_21 , - V_22 ) ;
}
F_11 ( V_21 ) ;
V_20 -> V_54 = V_56 ;
return 0 ;
V_88:
F_11 ( V_21 ) ;
V_85:
F_35 ( V_56 -> V_58 ) ;
F_11 ( V_56 ) ;
V_36:
return V_30 ;
}
static int F_49 ( struct V_2 * V_2 , struct V_20 * V_20 )
{
const struct V_81 * V_81 = V_20 -> V_82 ;
struct V_52 * V_56 ;
struct V_83 * V_84 ;
struct V_4 * V_28 ;
int V_30 ;
V_30 = - V_24 ;
V_56 = V_55 () ;
if ( V_56 == NULL )
goto V_36;
V_28 = F_1 ( V_2 ) -> V_28 ;
V_84 = V_2 -> V_35 -> V_86 ;
V_56 -> V_63 = F_44 ( F_45 ( V_28 ) , F_46 ( V_84 ) ,
F_42 ( V_20 -> V_87 ) , V_81 ) ;
V_30 = F_47 ( V_56 -> V_63 ) ;
if ( F_18 ( V_56 -> V_63 ) )
goto V_50;
V_20 -> V_54 = V_56 ;
return 0 ;
V_50:
F_11 ( V_56 ) ;
V_36:
return V_30 ;
}
static T_3 F_50 ( struct V_20 * V_20 , T_3 V_57 , int V_91 )
{
struct V_52 * V_56 = V_20 -> V_54 ;
struct V_20 * V_63 = V_56 -> V_63 ;
T_3 (* F_51)( struct V_20 * , T_3 , int );
T_3 V_92 ;
F_51 = V_63 -> V_42 . V_4 -> V_33 -> V_43 -> F_51 ;
if ( F_51 != NULL ) {
V_92 = (* F_51)( V_63 , V_57 , V_91 ) ;
if ( V_92 < 0 )
return V_92 ;
}
return F_52 ( V_20 , V_57 , V_91 ) ;
}
static int F_53 ( void * V_93 , const char * V_13 , int V_94 ,
T_3 V_95 , T_5 V_2 , unsigned int type )
{
struct V_96 * V_97 = V_93 ;
if ( F_6 ( V_97 -> V_4 , V_13 ) )
return 0 ;
return (* V_97 -> V_98 )( V_97 -> V_99 , V_13 , V_94 , V_95 ,
V_2 , type ) ;
}
static int F_54 ( struct V_20 * V_20 , void * V_100 , T_6 V_98 )
{
struct V_52 * V_56 = V_20 -> V_54 ;
struct V_20 * V_63 = V_56 -> V_63 ;
int (* F_55)( struct V_20 * , void * , T_6 );
struct V_96 V_97 = ( (struct V_96 )
{ . V_99 = V_100 ,
. V_98 = V_98 ,
. V_4 = V_20 -> V_42 . V_4
} ) ;
int V_30 ;
F_55 = V_63 -> V_42 . V_4 -> V_33 -> V_43 -> F_55 ;
V_63 -> V_45 = V_20 -> V_45 ;
V_30 = (* F_55)( V_63 , & V_97 , F_53 ) ;
V_20 -> V_45 = V_63 -> V_45 ;
return V_30 ;
}
static int F_56 ( struct V_20 * V_20 , int V_101 )
{
return 0 ;
}
static int F_57 ( struct V_4 * V_4 , struct V_102 * V_103 )
{
V_103 -> V_104 = 0 ;
V_103 -> V_105 = 0 ;
V_103 -> V_106 = 0 ;
V_103 -> V_107 = 0 ;
V_103 -> V_108 = 0 ;
V_103 -> V_109 = V_110 ;
return 0 ;
}
static struct V_2 * F_58 ( struct V_5 * V_6 )
{
struct V_1 * V_111 ;
V_111 = F_5 ( sizeof( * V_111 ) , V_19 ) ;
if ( ! V_111 )
return NULL ;
V_111 -> V_28 = NULL ;
F_59 ( & V_111 -> V_3 ) ;
return & V_111 -> V_3 ;
}
void F_60 ( struct V_2 * V_25 )
{
F_61 ( V_25 ) ;
F_62 ( F_1 ( V_25 ) -> V_28 ) ;
F_63 ( V_25 -> V_35 -> V_86 ) ;
}
static void F_64 ( struct V_112 * V_66 )
{
struct V_2 * V_2 = F_2 ( V_66 , struct V_2 , V_113 ) ;
F_38 ( & V_2 -> V_114 ) ;
F_11 ( F_1 ( V_2 ) ) ;
}
static void F_65 ( struct V_2 * V_2 )
{
F_66 ( & V_2 -> V_113 , F_64 ) ;
}
static int F_67 ( struct V_4 * V_4 , char T_2 * V_115 ,
int V_116 )
{
struct V_4 * V_28 = F_1 ( V_4 -> V_33 ) -> V_28 ;
return V_28 -> V_33 -> V_117 -> V_118 ( V_28 , V_115 ,
V_116 ) ;
}
static void * F_68 ( struct V_4 * V_4 , struct V_26 * V_27 )
{
struct V_4 * V_28 = F_1 ( V_4 -> V_33 ) -> V_28 ;
return V_28 -> V_33 -> V_117 -> V_119 ( V_28 , V_27 ) ;
}
static void F_69 ( struct V_4 * V_4 , struct V_26 * V_27 ,
void * V_120 )
{
struct V_4 * V_28 = F_1 ( V_4 -> V_33 ) -> V_28 ;
if ( V_28 -> V_33 -> V_117 -> V_121 )
V_28 -> V_33 -> V_117 -> V_121 ( V_28 , V_27 , V_120 ) ;
}
static struct V_2 * F_19 ( struct V_5 * V_6 , struct V_4 * V_4 )
{
struct V_2 * V_122 = V_4 -> V_33 ;
struct V_2 * V_2 = F_70 ( V_6 ) ;
if ( ! V_2 ) {
F_62 ( V_4 ) ;
return F_14 ( - V_24 ) ;
}
if ( F_71 ( V_4 -> V_33 -> V_123 ) ) {
V_2 -> V_117 = & V_124 ;
V_2 -> V_43 = & V_125 ;
} else if ( F_72 ( V_4 -> V_33 -> V_123 ) ) {
V_2 -> V_117 = & V_126 ;
V_2 -> V_43 = & V_127 ;
} else {
V_2 -> V_117 = & V_128 ;
V_2 -> V_43 = & V_127 ;
}
F_1 ( V_2 ) -> V_28 = V_4 ;
V_2 -> V_129 = V_122 -> V_129 ;
V_2 -> V_130 = V_122 -> V_130 ;
V_2 -> V_131 = V_122 -> V_131 ;
V_2 -> V_132 = V_122 -> V_132 ;
V_2 -> V_133 = V_122 -> V_133 ;
V_2 -> V_134 = V_122 -> V_134 ;
V_2 -> V_123 = V_122 -> V_123 ;
V_2 -> V_135 = V_122 -> V_135 ;
V_2 -> V_136 = V_122 -> V_136 ;
V_2 -> V_137 = V_122 -> V_137 ;
return V_2 ;
}
static int F_73 ( struct V_5 * V_6 , void * V_93 , int V_138 )
{
struct V_2 * V_139 ;
struct V_83 * V_84 ;
int V_30 = - V_32 ;
V_84 = F_46 ( V_140 -> V_141 -> V_142 -> V_84 ) ;
if ( F_18 ( V_84 ) )
goto V_36;
V_6 -> V_143 = 1024 ;
V_6 -> V_144 = 10 ;
V_6 -> V_145 = V_110 ;
V_6 -> V_146 = & V_147 ;
V_6 -> V_86 = V_84 ;
V_30 = - V_24 ;
V_139 = F_19 ( V_6 , F_45 ( V_84 -> V_148 -> V_10 ) ) ;
if ( ! V_139 )
goto V_149;
V_6 -> V_10 = F_74 ( V_139 ) ;
if ( ! V_6 -> V_10 )
goto V_150;
return 0 ;
V_150:
F_75 ( V_139 ) ;
V_149:
F_63 ( V_84 ) ;
V_36:
return ( V_30 ) ;
}
static struct V_4 * F_76 ( struct V_151 * type ,
int V_152 , const char * V_153 ,
void * V_56 )
{
return F_77 ( type , V_152 , V_56 , F_73 ) ;
}
static int T_7 F_78 ( void )
{
return F_79 ( & V_154 ) ;
}
static void T_8 F_80 ( void )
{
F_81 ( & V_154 ) ;
}
