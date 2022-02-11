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
F_15 ( & F_16 ( V_15 ) -> V_33 ) ;
V_28 = F_17 ( V_13 -> V_13 , V_15 , V_13 -> V_12 ) ;
F_18 ( & F_16 ( V_15 ) -> V_33 ) ;
if ( F_19 ( V_28 ) )
return V_28 ;
V_30 = - V_25 ;
V_2 = F_20 ( V_26 -> V_34 , V_28 ) ;
if ( ! V_2 )
goto V_35;
F_21 ( V_4 , V_2 ) ;
return NULL ;
V_35:
return F_14 ( V_30 ) ;
}
static T_1 F_22 ( struct V_21 * V_21 , char T_2 * V_36 , T_1 V_37 ,
T_3 * V_38 , int V_39 )
{
T_1 (* F_23)( struct V_21 * , char T_2 * , T_4 , T_3 * );
T_1 V_40 ;
F_23 = F_24 ( V_21 ) -> V_41 -> F_23 ;
if ( ! V_39 )
F_25 ( V_42 ) ;
V_40 = (* F_23)( V_21 , V_36 , V_37 , & V_21 -> V_43 ) ;
if ( ! V_39 )
F_25 ( V_44 ) ;
if ( V_38 )
* V_38 = V_21 -> V_43 ;
return V_40 ;
}
static T_1 F_26 ( int V_23 , char T_2 * V_36 , T_1 V_37 )
{
T_1 V_40 ;
int V_45 , V_30 ;
char * V_46 ;
V_40 = - V_25 ;
V_46 = F_5 ( V_47 , V_20 ) ;
if ( V_46 == NULL ) {
F_7 ( V_24 L_6 ) ;
goto V_35;
}
V_40 = 0 ;
while ( V_37 > 0 ) {
V_45 = F_27 ( T_1 , V_37 , V_47 ) ;
V_30 = F_28 ( V_23 , V_46 , V_45 ) ;
if ( V_30 < 0 ) {
F_7 ( V_24 L_7
L_8 , V_30 ) ;
V_40 = V_30 ;
goto V_48;
} else if ( V_30 == 0 )
break;
if ( F_29 ( V_36 , V_46 , V_30 ) ) {
V_40 = - V_49 ;
goto V_48;
}
V_40 += V_30 ;
V_37 -= V_30 ;
}
V_48:
F_11 ( V_46 ) ;
V_35:
return V_40 ;
}
static T_1 F_30 ( struct V_21 * V_21 , char T_2 * V_36 , T_4 V_37 ,
T_3 * V_38 )
{
struct V_50 * V_51 = V_21 -> V_52 ;
struct V_53 * V_54 ;
T_3 V_55 ;
int V_30 ;
if ( V_51 -> V_56 != NULL ) {
int V_57 ;
if ( * V_38 >= V_51 -> V_12 )
return 0 ;
V_54 = V_51 -> V_56 ;
V_55 = * V_38 ;
while ( V_55 >= sizeof( V_54 -> V_56 ) ) {
V_54 = F_31 ( V_54 -> V_58 . V_59 , struct V_53 ,
V_58 ) ;
V_55 -= sizeof( V_54 -> V_56 ) ;
}
if ( V_55 + V_37 > V_51 -> V_12 )
V_37 = V_51 -> V_12 - V_55 ;
V_57 = F_29 ( V_36 , & V_54 -> V_56 [ V_55 ] , V_37 ) ;
* V_38 += V_37 - V_57 ;
if ( V_57 > 0 )
return - V_49 ;
} else if ( V_51 -> V_60 != - 1 ) {
V_30 = F_32 ( V_51 -> V_60 , * V_38 ) ;
if ( V_30 ) {
F_7 ( V_24 L_9
L_8 , V_30 ) ;
return V_30 ;
}
V_30 = F_26 ( V_51 -> V_60 , V_36 , V_37 ) ;
if ( V_30 < 0 ) {
F_7 ( V_24 L_10 , V_30 ) ;
return V_30 ;
}
V_37 = V_30 ;
if ( V_37 > 0 )
* V_38 += V_37 ;
}
else V_37 = F_22 ( V_51 -> V_61 , V_36 , V_37 , V_38 , 1 ) ;
return V_37 ;
}
static T_1 F_33 ( struct V_21 * V_21 , const char T_2 * V_36 ,
T_4 V_12 , T_3 * V_38 )
{
struct V_50 * V_54 = V_21 -> V_52 ;
struct V_21 * V_61 = V_54 -> V_61 ;
T_1 (* F_34)( struct V_21 * , const char T_2 * , T_4 , T_3 * );
F_34 = F_24 ( V_61 ) -> V_41 -> F_34 ;
return (* F_34)( V_61 , V_36 , V_12 , V_38 ) ;
}
static int F_35 ( char * V_22 , int * V_62 )
{
char * V_63 ;
int V_23 ;
V_63 = & V_22 [ strlen ( V_22 ) ] ;
strcpy ( V_63 , L_11 ) ;
* V_62 = 1 ;
V_23 = F_36 ( V_22 ) ;
if ( V_23 > 0 )
return V_23 ;
strcpy ( V_63 , L_12 ) ;
* V_62 = 0 ;
V_23 = F_36 ( V_22 ) ;
return V_23 ;
}
static void F_37 ( struct V_53 * V_64 )
{
struct V_53 * V_54 ;
struct V_65 * V_66 , * V_59 ;
if ( V_64 == NULL )
return;
F_38 (ele, next, &head->list) {
V_54 = F_31 ( V_66 , struct V_53 , V_58 ) ;
F_11 ( V_54 ) ;
}
F_11 ( V_64 ) ;
}
static struct V_53 * F_39 ( int V_23 , int V_67 ,
struct V_21 * V_61 ,
struct V_21 * V_68 ,
T_3 * V_69 )
{
struct V_53 * V_54 , * V_70 , * V_64 ;
int V_40 , V_30 ;
V_30 = - V_25 ;
V_54 = F_5 ( sizeof( * V_54 ) , V_20 ) ;
if ( V_54 == NULL ) {
F_7 ( V_24 L_13 ) ;
goto V_71;
}
F_40 ( & V_54 -> V_58 ) ;
V_64 = V_54 ;
* V_69 = 0 ;
if ( V_67 ) {
while ( ( V_40 = F_22 ( V_61 , V_54 -> V_56 ,
sizeof( V_54 -> V_56 ) , NULL , 0 ) ) > 0 )
F_41 ( V_23 , V_54 -> V_56 , V_40 ) ;
V_30 = F_42 ( V_23 , 0 , 1 ) ;
if ( V_30 ) {
F_7 ( V_24 L_14
L_15 ) ;
goto V_72;
}
}
while ( 1 ) {
V_40 = F_28 ( V_23 , V_54 -> V_56 , sizeof( V_54 -> V_56 ) ) ;
if ( V_40 < 0 ) {
V_30 = V_40 ;
F_7 ( V_24 L_16
L_8 , V_30 ) ;
goto V_72;
} else if ( V_40 == 0 )
break;
* V_69 += V_40 ;
if ( V_40 < sizeof( V_54 -> V_56 ) )
break;
V_70 = F_5 ( sizeof( * V_54 ) , V_20 ) ;
if ( V_70 == 0 ) {
F_7 ( V_24 L_17
L_18 ) ;
V_30 = - V_25 ;
goto V_72;
}
F_40 ( & V_70 -> V_58 ) ;
F_43 ( & V_70 -> V_58 , & V_54 -> V_58 ) ;
V_54 = V_70 ;
}
return V_64 ;
V_72:
F_37 ( V_64 ) ;
V_71:
return F_14 ( V_30 ) ;
}
static struct V_50 * V_53 ( void )
{
struct V_50 * V_54 ;
V_54 = F_5 ( sizeof( * V_54 ) , V_20 ) ;
if ( V_54 == NULL )
return V_54 ;
* V_54 = ( (struct V_50 ) { . V_60 = - 1 ,
. V_12 = - 1 ,
. V_56 = NULL } ) ;
return V_54 ;
}
static int F_44 ( int V_73 )
{
if ( V_73 == ( V_74 | V_75 ) )
return V_76 ;
if ( V_73 == V_74 )
return V_77 ;
if ( V_73 == V_75 )
return V_78 ;
return 0 ;
}
static int F_45 ( struct V_2 * V_2 , struct V_21 * V_21 )
{
const struct V_79 * V_79 = V_21 -> V_80 ;
struct V_50 * V_54 ;
struct V_81 V_81 ;
char * V_22 ;
int V_30 , V_23 , type , V_67 ;
V_30 = - V_25 ;
V_54 = V_53 () ;
if ( V_54 == NULL )
goto V_35;
V_22 = F_4 ( V_21 -> V_82 . V_4 , strlen ( L_11 ) ) ;
if ( V_22 == NULL )
goto V_83;
V_81 . V_84 = V_2 -> V_34 -> V_85 ;
V_81 . V_4 = F_1 ( V_2 ) -> V_28 ;
V_54 -> V_61 = F_46 ( & V_81 , F_44 ( V_21 -> V_86 ) , V_79 ) ;
V_30 = F_47 ( V_54 -> V_61 ) ;
if ( F_19 ( V_54 -> V_61 ) )
goto V_87;
type = F_48 ( V_22 ) ;
if ( type == V_88 ) {
V_23 = F_8 ( V_22 , F_9 ( F_10 () ) , 0 ) ;
if ( V_23 >= 0 )
V_54 -> V_60 = V_23 ;
else
F_7 ( V_24 L_19
L_8 , V_22 , - V_23 ) ;
V_54 -> V_56 = NULL ;
} else if ( type == V_89 ) {
V_23 = F_35 ( V_22 , & V_67 ) ;
if ( V_23 > 0 ) {
V_54 -> V_56 = F_39 ( V_23 , V_67 ,
V_54 -> V_61 ,
V_21 , & V_54 -> V_12 ) ;
if ( ! F_19 ( V_54 -> V_56 ) )
V_54 -> V_60 = V_23 ;
} else
F_7 ( V_24 L_20
L_21 , V_22 , - V_23 ) ;
}
F_11 ( V_22 ) ;
V_21 -> V_52 = V_54 ;
return 0 ;
V_87:
F_11 ( V_22 ) ;
V_83:
F_37 ( V_54 -> V_56 ) ;
F_11 ( V_54 ) ;
V_35:
return V_30 ;
}
static int F_49 ( struct V_2 * V_2 , struct V_21 * V_21 )
{
const struct V_79 * V_79 = V_21 -> V_80 ;
struct V_50 * V_54 ;
struct V_81 V_81 ;
int V_30 ;
V_30 = - V_25 ;
V_54 = V_53 () ;
if ( V_54 == NULL )
goto V_35;
V_81 . V_84 = V_2 -> V_34 -> V_85 ;
V_81 . V_4 = F_1 ( V_2 ) -> V_28 ;
V_54 -> V_61 = F_46 ( & V_81 , F_44 ( V_21 -> V_86 ) , V_79 ) ;
V_30 = F_47 ( V_54 -> V_61 ) ;
if ( F_19 ( V_54 -> V_61 ) )
goto V_48;
V_21 -> V_52 = V_54 ;
return 0 ;
V_48:
F_11 ( V_54 ) ;
V_35:
return V_30 ;
}
static T_3 F_50 ( struct V_21 * V_21 , T_3 V_55 , int V_90 )
{
struct V_50 * V_54 = V_21 -> V_52 ;
struct V_21 * V_61 = V_54 -> V_61 ;
T_3 (* F_51)( struct V_21 * , T_3 , int );
T_3 V_91 ;
F_51 = F_24 ( V_61 ) -> V_41 -> F_51 ;
if ( F_51 != NULL ) {
V_91 = (* F_51)( V_61 , V_55 , V_90 ) ;
if ( V_91 < 0 )
return V_91 ;
}
return F_52 ( V_21 , V_55 , V_90 ) ;
}
static int F_53 ( struct V_2 * V_2 , struct V_21 * V_21 )
{
struct V_50 * V_54 = V_21 -> V_52 ;
struct V_21 * V_61 = V_54 -> V_61 ;
if ( V_61 )
F_54 ( V_61 ) ;
F_11 ( V_54 ) ;
return 0 ;
}
static int F_55 ( struct V_92 * V_93 , const char * V_13 , int V_94 ,
T_3 V_95 , T_5 V_2 , unsigned int type )
{
struct V_96 * V_97 =
F_2 ( V_93 , struct V_96 , V_93 ) ;
if ( F_6 ( V_97 -> V_4 , V_13 ) )
return 0 ;
V_97 -> V_98 -> V_99 = V_97 -> V_93 . V_99 ;
return ! F_56 ( V_97 -> V_98 , V_13 , V_94 , V_2 , type ) ;
}
static int F_57 ( struct V_21 * V_21 , struct V_92 * V_93 )
{
struct V_50 * V_54 = V_21 -> V_52 ;
struct V_21 * V_61 = V_54 -> V_61 ;
struct V_96 V_100 = {
. V_93 . V_101 = F_55 ,
. V_98 = V_93 ,
. V_4 = V_21 -> V_82 . V_4
} ;
int V_30 ;
V_61 -> V_43 = V_93 -> V_99 ;
V_30 = F_58 ( V_61 , & V_100 . V_93 ) ;
V_93 -> V_99 = V_100 . V_93 . V_99 ;
return V_30 ;
}
static int F_59 ( struct V_4 * V_4 , struct V_102 * V_103 )
{
V_103 -> V_104 = 0 ;
V_103 -> V_105 = 0 ;
V_103 -> V_106 = 0 ;
V_103 -> V_107 = 0 ;
V_103 -> V_108 = 0 ;
V_103 -> V_109 = V_110 ;
return 0 ;
}
static struct V_2 * F_60 ( struct V_5 * V_6 )
{
struct V_1 * V_111 ;
V_111 = F_5 ( sizeof( * V_111 ) , V_20 ) ;
if ( ! V_111 )
return NULL ;
V_111 -> V_28 = NULL ;
F_61 ( & V_111 -> V_3 ) ;
return & V_111 -> V_3 ;
}
void F_62 ( struct V_2 * V_26 )
{
F_63 ( V_26 ) ;
F_64 ( F_1 ( V_26 ) -> V_28 ) ;
F_65 ( V_26 -> V_34 -> V_85 ) ;
}
static void F_66 ( struct V_112 * V_64 )
{
struct V_2 * V_2 = F_2 ( V_64 , struct V_2 , V_113 ) ;
F_11 ( F_1 ( V_2 ) ) ;
}
static void F_67 ( struct V_2 * V_2 )
{
F_68 ( & V_2 -> V_113 , F_66 ) ;
}
static int F_69 ( struct V_4 * V_4 , char T_2 * V_114 ,
int V_115 )
{
struct V_4 * V_28 = F_1 ( F_16 ( V_4 ) ) -> V_28 ;
return F_16 ( V_28 ) -> V_116 -> V_117 ( V_28 , V_114 ,
V_115 ) ;
}
static void * F_70 ( struct V_4 * V_4 , struct V_118 * V_119 )
{
struct V_4 * V_28 = F_1 ( F_16 ( V_4 ) ) -> V_28 ;
return F_16 ( V_28 ) -> V_116 -> V_120 ( V_28 , V_119 ) ;
}
static void F_71 ( struct V_4 * V_4 , struct V_118 * V_119 ,
void * V_121 )
{
struct V_4 * V_28 = F_1 ( F_16 ( V_4 ) ) -> V_28 ;
if ( F_16 ( V_28 ) -> V_116 -> V_122 )
F_16 ( V_28 ) -> V_116 -> V_122 ( V_28 , V_119 , V_121 ) ;
}
static struct V_2 * F_20 ( struct V_5 * V_6 , struct V_4 * V_4 )
{
struct V_2 * V_123 = F_16 ( V_4 ) ;
struct V_2 * V_2 = F_72 ( V_6 ) ;
if ( ! V_2 ) {
F_64 ( V_4 ) ;
return NULL ;
}
if ( F_73 ( V_4 ) ) {
V_2 -> V_116 = & V_124 ;
V_2 -> V_41 = & V_125 ;
} else if ( F_74 ( V_4 ) ) {
V_2 -> V_116 = & V_126 ;
V_2 -> V_41 = & V_127 ;
} else {
V_2 -> V_116 = & V_128 ;
V_2 -> V_41 = & V_127 ;
}
F_1 ( V_2 ) -> V_28 = V_4 ;
V_2 -> V_129 = V_123 -> V_129 ;
V_2 -> V_130 = V_123 -> V_130 ;
V_2 -> V_131 = V_123 -> V_131 ;
V_2 -> V_132 = V_123 -> V_132 ;
V_2 -> V_133 = V_123 -> V_133 ;
V_2 -> V_134 = V_123 -> V_134 ;
V_2 -> V_135 = V_123 -> V_135 ;
F_75 ( V_2 , V_123 -> V_136 ) ;
V_2 -> V_137 = V_123 -> V_137 ;
V_2 -> V_138 = V_123 -> V_138 ;
return V_2 ;
}
static int F_76 ( struct V_5 * V_6 , void * V_100 , int V_139 )
{
struct V_2 * V_140 ;
struct V_141 * V_142 ;
int V_30 = - V_32 ;
V_142 = F_77 ( F_78 ( V_143 ) -> V_142 ) ;
if ( F_19 ( V_142 ) )
goto V_35;
V_6 -> V_144 = 1024 ;
V_6 -> V_145 = 10 ;
V_6 -> V_146 = V_110 ;
V_6 -> V_147 = & V_148 ;
V_6 -> V_85 = V_142 ;
V_30 = - V_25 ;
V_140 = F_20 ( V_6 , F_79 ( V_142 -> V_149 ) ) ;
V_6 -> V_10 = F_80 ( V_140 ) ;
if ( ! V_6 -> V_10 )
goto V_150;
return 0 ;
V_150:
F_65 ( V_142 ) ;
V_35:
return ( V_30 ) ;
}
static struct V_4 * F_81 ( struct V_151 * type ,
int V_27 , const char * V_152 ,
void * V_54 )
{
return F_82 ( type , V_27 , V_54 , F_76 ) ;
}
static int T_6 F_83 ( void )
{
return F_84 ( & V_153 ) ;
}
static void T_7 F_85 ( void )
{
F_86 ( & V_153 ) ;
}
