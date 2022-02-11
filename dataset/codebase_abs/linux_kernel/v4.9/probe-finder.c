static int F_1 ( struct V_1 * V_2 ,
const char * V_3 )
{
int V_4 ;
V_4 = F_2 ( V_3 , V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_6 = F_3 ( & V_7 ) ;
if ( ! V_2 -> V_6 )
goto error;
F_4 ( V_2 -> V_6 ) ;
V_2 -> V_8 = F_5 ( V_2 -> V_6 , L_1 , L_1 , V_4 ) ;
if ( ! V_2 -> V_8 )
goto error;
V_2 -> V_2 = F_6 ( V_2 -> V_8 , & V_2 -> V_9 ) ;
if ( ! V_2 -> V_2 )
goto error;
F_7 ( V_2 -> V_6 , NULL , NULL ) ;
return 0 ;
error:
if ( V_2 -> V_6 )
F_8 ( V_2 -> V_6 ) ;
else
F_9 ( V_4 ) ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
return - V_10 ;
}
static struct V_1 * F_10 ( const char * V_3 )
{
struct V_1 * V_2 = F_11 ( sizeof( * V_2 ) ) ;
if ( ! V_2 )
return NULL ;
if ( F_1 ( V_2 , V_3 ) < 0 )
F_12 ( & V_2 ) ;
if ( V_2 )
F_13 ( L_2 , V_3 ) ;
return V_2 ;
}
struct V_1 * F_14 ( const char * V_3 )
{
enum V_11 * type ;
char V_12 [ V_13 ] , V_14 = '\0' ;
struct V_15 * V_15 ;
struct V_1 * V_16 = NULL ;
V_15 = F_15 ( V_3 ) ;
if ( ! V_15 )
goto V_17;
for ( type = V_18 ;
! V_16 && * type != V_19 ;
type ++ ) {
if ( F_16 ( V_15 , * type , & V_14 ,
V_12 , V_13 ) < 0 )
continue;
V_16 = F_10 ( V_12 ) ;
}
F_17 ( V_15 ) ;
V_17:
return V_16 ? : F_10 ( V_3 ) ;
}
void F_18 ( struct V_1 * V_2 )
{
if ( V_2 ) {
if ( V_2 -> V_6 )
F_8 ( V_2 -> V_6 ) ;
free ( V_2 ) ;
}
}
static struct V_20 * F_19 ( long V_21 )
{
struct V_20 * V_22 ;
V_22 = F_11 ( sizeof( struct V_20 ) ) ;
if ( V_22 != NULL )
V_22 -> V_23 = V_21 ;
return V_22 ;
}
static int F_20 ( T_1 * V_24 , T_2 V_25 ,
T_3 * V_26 , T_1 * V_27 ,
unsigned int V_28 ,
struct V_29 * V_30 )
{
T_4 V_31 ;
T_2 V_32 = 0 ;
T_3 * V_33 ;
T_5 V_34 ;
unsigned int V_35 ;
T_6 V_21 = 0 ;
bool V_22 = false ;
const char * V_36 ;
int V_37 , V_38 = 0 ;
if ( F_21 ( V_24 , V_39 , & V_31 ) != NULL )
goto V_40;
if ( F_21 ( V_24 , V_41 , & V_31 ) == NULL )
return - V_42 ;
if ( F_22 ( & V_31 , V_25 , & V_33 , & V_34 , 1 ) <= 0 ) {
V_37 = F_23 ( V_27 , & V_32 ) ;
if ( V_37 )
return - V_10 ;
if ( V_43 . V_44 &&
( F_24 ( V_24 ) == V_45 ) ) {
V_38 = - V_46 ;
} else if ( V_25 != V_32 ||
F_24 ( V_24 ) != V_47 ) {
return - V_10 ;
}
V_37 = F_25 ( V_27 , & V_32 ) ;
if ( V_37 )
return - V_10 ;
for ( V_25 += 1 ; V_25 <= V_32 ; V_25 ++ ) {
if ( F_22 ( & V_31 , V_25 , & V_33 ,
& V_34 , 1 ) > 0 )
goto V_48;
}
return - V_10 ;
}
V_48:
if ( V_34 == 0 )
return - V_10 ;
if ( V_33 -> V_49 == V_50 ) {
V_40:
if ( ! V_30 )
return V_38 ;
V_37 = strlen ( F_26 ( V_24 ) ) ;
V_30 -> V_51 = F_11 ( V_37 + 2 ) ;
if ( V_30 -> V_51 == NULL )
return - V_52 ;
snprintf ( V_30 -> V_51 , V_37 + 2 , L_3 , F_26 ( V_24 ) ) ;
V_30 -> V_22 = F_19 ( ( long ) V_21 ) ;
if ( V_30 -> V_22 == NULL )
return - V_52 ;
return V_38 ;
}
if ( V_33 -> V_49 == V_53 ) {
if ( V_26 == NULL )
return - V_54 ;
V_22 = true ;
V_21 = V_33 -> V_55 ;
V_33 = & V_26 [ 0 ] ;
}
if ( V_33 -> V_49 >= V_56 && V_33 -> V_49 <= V_57 ) {
V_35 = V_33 -> V_49 - V_56 ;
V_21 += V_33 -> V_55 ;
V_22 = true ;
} else if ( V_33 -> V_49 >= V_58 && V_33 -> V_49 <= V_59 ) {
V_35 = V_33 -> V_49 - V_58 ;
} else if ( V_33 -> V_49 == V_60 ) {
V_35 = V_33 -> V_55 ;
V_21 += V_33 -> V_61 ;
V_22 = true ;
} else if ( V_33 -> V_49 == V_62 ) {
V_35 = V_33 -> V_55 ;
} else {
F_13 ( L_4 , V_33 -> V_49 ) ;
return - V_54 ;
}
if ( ! V_30 )
return V_38 ;
V_36 = F_27 ( V_35 , V_28 ) ;
if ( ! V_36 ) {
F_28 ( L_5
L_6 , V_35 ) ;
return - V_54 ;
}
V_30 -> V_51 = F_29 ( V_36 ) ;
if ( V_30 -> V_51 == NULL )
return - V_52 ;
if ( V_22 ) {
V_30 -> V_22 = F_19 ( ( long ) V_21 ) ;
if ( V_30 -> V_22 == NULL )
return - V_52 ;
}
return V_38 ;
}
static int F_30 ( T_1 * V_24 ,
struct V_29 * V_30 ,
const char * V_63 )
{
struct V_20 * * V_64 = & V_30 -> V_22 ;
T_1 type ;
char V_12 [ 16 ] ;
char V_65 [ V_66 ] ;
int V_67 , V_68 , V_69 ;
int V_37 ;
char V_70 ;
if ( V_63 && strcmp ( V_63 , L_7 ) != 0 && strcmp ( V_63 , L_8 ) != 0 &&
strcmp ( V_63 , L_9 ) != 0 && strcmp ( V_63 , L_10 ) != 0 ) {
V_30 -> type = F_29 ( V_63 ) ;
return ( V_30 -> type == NULL ) ? - V_52 : 0 ;
}
V_67 = F_31 ( V_24 ) ;
if ( V_67 > 0 ) {
V_68 = F_32 ( V_24 ) ;
V_69 = F_33 ( V_24 ) ;
if ( V_68 < 0 || V_69 < 0 )
return - V_10 ;
V_37 = snprintf ( V_12 , 16 , L_11 , V_67 , V_68 ,
F_34 ( V_69 ) ) ;
goto V_71;
}
if ( F_35 ( V_24 , & type ) == NULL ) {
F_28 ( L_12 ,
F_26 ( V_24 ) ) ;
return - V_10 ;
}
F_13 ( L_13 ,
F_26 ( V_24 ) , F_26 ( & type ) ) ;
if ( V_63 && strcmp ( V_63 , L_7 ) == 0 ) {
V_37 = F_24 ( & type ) ;
if ( V_37 != V_72 &&
V_37 != V_73 ) {
F_28 ( L_14
L_15 ,
F_26 ( V_24 ) , F_26 ( & type ) ) ;
return - V_42 ;
}
if ( F_35 ( & type , & type ) == NULL ) {
F_28 ( L_16
L_17 ) ;
return - V_10 ;
}
if ( V_37 == V_72 ) {
while ( * V_64 )
V_64 = & ( * V_64 ) -> V_74 ;
* V_64 = F_11 ( sizeof( struct V_20 ) ) ;
if ( * V_64 == NULL ) {
F_28 ( L_18 ) ;
return - V_52 ;
}
}
if ( ! F_36 ( & type , L_19 ) &&
! F_36 ( & type , L_20 ) ) {
F_28 ( L_14
L_21 ,
F_26 ( V_24 ) ) ;
return - V_42 ;
}
V_30 -> type = F_29 ( V_63 ) ;
return ( V_30 -> type == NULL ) ? - V_52 : 0 ;
}
if ( V_63 && ( strcmp ( V_63 , L_10 ) == 0 ) )
V_70 = 'u' ;
else if ( V_63 && ( strcmp ( V_63 , L_9 ) == 0 ) )
V_70 = 's' ;
else if ( V_63 && ( strcmp ( V_63 , L_8 ) == 0 ) &&
F_37 ( V_75 ) )
V_70 = 'x' ;
else
V_70 = F_38 ( & type ) ? 's' :
F_37 ( V_75 ) ? 'x' : 'u' ;
V_37 = F_33 ( & type ) ;
if ( V_37 <= 0 )
return 0 ;
V_37 = F_34 ( V_37 ) ;
if ( V_37 > V_76 ) {
F_39 ( L_22 ,
F_26 ( & type ) , V_76 ) ;
V_37 = V_76 ;
}
V_37 = snprintf ( V_12 , 16 , L_23 , V_70 , V_37 ) ;
V_71:
if ( V_37 < 0 || V_37 >= 16 ) {
if ( V_37 >= 16 )
V_37 = - V_77 ;
F_28 ( L_24 ,
F_40 ( - V_37 , V_65 , sizeof( V_65 ) ) ) ;
return V_37 ;
}
V_30 -> type = F_29 ( V_12 ) ;
if ( V_30 -> type == NULL )
return - V_52 ;
return 0 ;
}
static int F_41 ( T_1 * V_24 , const char * V_78 ,
struct V_79 * V_80 ,
struct V_20 * * V_64 ,
T_1 * V_81 )
{
struct V_20 * V_22 = * V_64 ;
T_1 type ;
T_6 V_21 ;
int V_37 , V_82 ;
F_13 ( L_25 , V_80 -> V_83 , V_78 ) ;
if ( F_35 ( V_24 , & type ) == NULL ) {
F_28 ( L_26 , V_78 ) ;
return - V_10 ;
}
F_42 ( L_27 , ( unsigned ) F_43 ( & type ) ) ;
V_82 = F_24 ( & type ) ;
if ( V_80 -> V_83 [ 0 ] == '[' &&
( V_82 == V_73 || V_82 == V_72 ) ) {
if ( V_80 -> V_74 )
memcpy ( V_81 , & type , sizeof( * V_81 ) ) ;
if ( F_35 ( & type , & type ) == NULL ) {
F_28 ( L_26 , V_78 ) ;
return - V_10 ;
}
F_42 ( L_28 ,
( unsigned ) F_43 ( & type ) ) ;
if ( V_82 == V_72 ) {
V_22 = F_11 ( sizeof( struct V_20 ) ) ;
if ( V_22 == NULL )
return - V_52 ;
if ( * V_64 )
( * V_64 ) -> V_74 = V_22 ;
else
* V_64 = V_22 ;
}
V_22 -> V_23 += F_33 ( & type ) * V_80 -> V_84 ;
if ( ! V_80 -> V_74 )
memcpy ( V_81 , V_24 , sizeof( * V_81 ) ) ;
goto V_74;
} else if ( V_82 == V_72 ) {
if ( ! V_80 -> V_22 ) {
F_44 ( L_29 ,
V_80 -> V_83 ) ;
return - V_42 ;
}
if ( F_35 ( & type , & type ) == NULL ) {
F_28 ( L_26 , V_78 ) ;
return - V_10 ;
}
V_82 = F_24 ( & type ) ;
if ( V_82 != V_85 && V_82 != V_86 ) {
F_28 ( L_30 ,
V_78 ) ;
return - V_42 ;
}
V_22 = F_11 ( sizeof( struct V_20 ) ) ;
if ( V_22 == NULL )
return - V_52 ;
if ( * V_64 )
( * V_64 ) -> V_74 = V_22 ;
else
* V_64 = V_22 ;
} else {
if ( V_82 != V_85 && V_82 != V_86 ) {
F_28 ( L_30 ,
V_78 ) ;
return - V_42 ;
}
if ( V_80 -> V_83 [ 0 ] == '[' ) {
F_44 ( L_31
L_32 , V_78 ) ;
return - V_42 ;
}
if ( V_80 -> V_22 && F_26 ( V_24 ) ) {
F_44 ( L_33 ,
V_80 -> V_83 ) ;
return - V_42 ;
}
if ( ! V_22 ) {
F_28 ( L_34
L_35 ) ;
return - V_54 ;
}
}
if ( F_45 ( & type , V_80 -> V_83 , V_81 ) == NULL ) {
F_28 ( L_36 , V_78 ,
F_26 ( & type ) , V_80 -> V_83 ) ;
return - V_42 ;
}
if ( V_82 == V_86 ) {
V_21 = 0 ;
} else {
V_37 = F_46 ( V_81 , & V_21 ) ;
if ( V_37 < 0 ) {
F_28 ( L_37 ,
V_80 -> V_83 ) ;
return V_37 ;
}
}
V_22 -> V_23 += ( long ) V_21 ;
if ( ! F_26 ( V_81 ) )
return F_41 ( V_81 , V_78 , V_80 ,
& V_22 , V_81 ) ;
V_74:
if ( V_80 -> V_74 )
return F_41 ( V_81 , V_80 -> V_83 ,
V_80 -> V_74 , & V_22 , V_81 ) ;
else
return 0 ;
}
static int F_47 ( T_1 * V_24 , struct V_87 * V_88 )
{
T_1 V_81 ;
int V_37 ;
F_13 ( L_38 ,
F_26 ( V_24 ) ) ;
V_37 = F_20 ( V_24 , V_88 -> V_25 , V_88 -> V_26 ,
& V_88 -> V_27 , V_88 -> V_28 , V_88 -> V_30 ) ;
if ( V_37 == - V_10 || V_37 == - V_42 ) {
F_44 ( L_39
L_40
L_41 ,
V_88 -> V_89 -> V_90 , V_88 -> V_89 -> V_90 ) ;
} else if ( V_37 == - V_54 )
F_44 ( L_42 ) ;
else if ( V_37 == 0 && V_88 -> V_89 -> V_80 ) {
V_37 = F_41 ( V_24 , V_88 -> V_89 -> V_90 ,
V_88 -> V_89 -> V_80 , & V_88 -> V_30 -> V_22 ,
& V_81 ) ;
V_24 = & V_81 ;
}
if ( V_37 == 0 )
V_37 = F_30 ( V_24 , V_88 -> V_30 , V_88 -> V_89 -> type ) ;
return V_37 ;
}
static int F_48 ( T_1 * V_91 , struct V_87 * V_88 )
{
T_1 V_24 ;
char * V_12 , * V_92 ;
int V_37 = 0 ;
if ( ! F_49 ( V_88 -> V_89 -> V_90 ) )
return F_50 ( V_88 -> V_30 , V_88 -> V_89 ) ;
if ( V_88 -> V_89 -> V_83 )
V_88 -> V_30 -> V_83 = F_29 ( V_88 -> V_89 -> V_83 ) ;
else {
V_12 = F_51 ( V_88 -> V_89 ) ;
if ( ! V_12 )
return - V_52 ;
V_92 = strchr ( V_12 , ':' ) ;
if ( V_92 )
* V_92 = '_' ;
V_88 -> V_30 -> V_83 = V_12 ;
}
if ( V_88 -> V_30 -> V_83 == NULL )
return - V_52 ;
F_13 ( L_43 , V_88 -> V_89 -> V_90 ) ;
if ( ! F_52 ( V_91 , V_88 -> V_89 -> V_90 , V_88 -> V_25 , & V_24 ) ) {
if ( ! F_52 ( & V_88 -> V_93 , V_88 -> V_89 -> V_90 ,
0 , & V_24 ) ) {
F_28 ( L_44 ,
V_88 -> V_89 -> V_90 ) ;
V_37 = - V_10 ;
}
}
if ( V_37 >= 0 )
V_37 = F_47 ( & V_24 , V_88 ) ;
return V_37 ;
}
static int F_53 ( T_1 * V_27 , T_7 * V_8 ,
T_2 V_94 , bool V_95 ,
const char * V_96 ,
struct V_97 * V_98 )
{
T_2 V_99 , V_100 ;
T_8 V_101 ;
const char * V_102 ;
if ( F_23 ( V_27 , & V_99 ) != 0 ) {
F_28 ( L_45 ,
F_26 ( V_27 ) ) ;
return - V_10 ;
}
if ( F_25 ( V_27 , & V_100 ) != 0 ) {
F_28 ( L_46 ,
F_26 ( V_27 ) ) ;
return - V_10 ;
}
if ( V_94 > V_100 ) {
F_28 ( L_47 ,
F_26 ( V_27 ) ) ;
return - V_42 ;
}
V_102 = F_26 ( V_27 ) ;
if ( ! V_102 ) {
V_102 = F_54 ( V_8 , V_94 , & V_101 , NULL ) ;
if ( ! V_102 ) {
F_28 ( L_48 ,
( unsigned long ) V_94 ) ;
return - V_10 ;
}
V_99 = V_101 . V_103 ;
}
V_98 -> V_23 = ( unsigned long ) ( V_94 - V_99 ) ;
V_98 -> V_104 = ( unsigned long ) V_94 ;
V_98 -> V_102 = F_29 ( V_102 ) ;
if ( ! V_98 -> V_102 )
return - V_52 ;
if ( V_95 ) {
if ( V_99 != V_94 ) {
F_28 ( L_49
L_50
L_51 , V_96 ,
V_96 ) ;
return - V_42 ;
}
V_98 -> V_95 = true ;
}
return 0 ;
}
static int F_55 ( T_1 * V_91 , struct V_87 * V_88 )
{
T_4 V_105 ;
T_9 * V_106 = NULL ;
T_5 V_34 ;
int V_37 ;
if ( ! V_91 ) {
F_44 ( L_52 ) ;
return - V_42 ;
}
if ( ! F_56 ( V_91 ) ) {
if ( ! F_57 ( & V_88 -> V_93 , V_88 -> V_25 , & V_88 -> V_27 ) ) {
if ( F_58 ( & V_88 -> V_93 , V_88 -> V_25 , & V_88 -> V_27 ) ) {
F_28 ( L_53 ,
F_26 ( & V_88 -> V_27 ) ) ;
return 0 ;
} else {
F_28 ( L_54
L_55 ) ;
return - V_10 ;
}
}
} else
memcpy ( & V_88 -> V_27 , V_91 , sizeof( T_1 ) ) ;
F_21 ( & V_88 -> V_27 , V_107 , & V_105 ) ;
V_37 = F_22 ( & V_105 , V_88 -> V_25 , & V_88 -> V_26 , & V_34 , 1 ) ;
if ( V_37 <= 0 || V_34 == 0 ) {
V_88 -> V_26 = NULL ;
#if F_59 ( 0 , 142 )
} else if ( V_34 == 1 && V_88 -> V_26 [ 0 ] . V_49 == V_108 &&
( V_88 -> V_109 != NULL || V_88 -> V_110 != NULL ) ) {
if ( ( F_60 ( V_88 -> V_109 , V_88 -> V_25 , & V_106 ) != 0 &&
( F_60 ( V_88 -> V_110 , V_88 -> V_25 , & V_106 ) != 0 ) ) ||
F_61 ( V_106 , & V_88 -> V_26 , & V_34 ) != 0 ) {
F_28 ( L_56 ,
( V_111 ) V_88 -> V_25 ) ;
free ( V_106 ) ;
return - V_10 ;
}
#endif
}
V_37 = V_88 -> V_112 ( V_91 , V_88 ) ;
free ( V_106 ) ;
V_88 -> V_26 = NULL ;
return V_37 ;
}
static int F_62 ( T_1 * V_113 , void * V_114 )
{
struct V_115 * V_116 = V_114 ;
const char * V_117 ;
int V_118 ;
if ( V_116 -> V_117 ) {
V_117 = F_63 ( V_113 ) ;
if ( ! V_117 || strcmp ( V_116 -> V_117 , V_117 ) != 0 )
return 0 ;
}
if ( V_116 -> V_96 ) {
if ( F_64 ( V_113 , V_116 -> V_96 ) ) {
memcpy ( V_116 -> V_81 , V_113 , sizeof( T_1 ) ) ;
V_116 -> V_48 = true ;
return 1 ;
}
} else {
F_65 ( V_113 , & V_118 ) ;
if ( V_118 < V_116 -> line && V_116 -> V_119 > V_116 -> line - V_118 ) {
V_116 -> V_119 = V_116 -> line - V_118 ;
memcpy ( V_116 -> V_81 , V_113 , sizeof( T_1 ) ) ;
V_116 -> V_48 = true ;
}
}
return 0 ;
}
static T_1 * F_66 ( struct V_87 * V_88 , T_1 * V_81 )
{
struct V_115 V_116 = {
. V_96 = V_88 -> V_120 -> V_121 . V_96 ,
. V_117 = V_88 -> V_122 ,
. line = V_88 -> V_118 ,
. V_119 = V_123 ,
. V_81 = V_81 ,
. V_48 = false ,
} ;
F_67 ( & V_88 -> V_93 , V_88 -> V_25 , F_62 , & V_116 ) ;
return V_116 . V_48 ? V_81 : NULL ;
}
static int F_68 ( const char * V_122 , int V_124 ,
T_2 V_25 , void * V_114 )
{
struct V_87 * V_88 = V_114 ;
T_1 * V_91 , V_81 ;
int V_37 ;
if ( V_124 != V_88 -> V_118 || F_69 ( V_122 , V_88 -> V_122 ) != 0 )
return 0 ;
V_88 -> V_25 = V_25 ;
V_91 = F_66 ( V_88 , & V_81 ) ;
if ( ! V_91 ) {
F_28 ( L_57 ) ;
return - V_10 ;
}
V_37 = F_55 ( V_91 , V_88 ) ;
return V_37 < 0 ? V_37 : 0 ;
}
static int F_70 ( struct V_87 * V_88 )
{
return F_71 ( & V_88 -> V_93 , F_68 , V_88 ) ;
}
static int F_72 ( struct V_125 * V_126 ,
const char * V_122 , const char * V_127 )
{
T_10 * V_128 ;
char * line = NULL ;
T_5 V_129 ;
T_11 V_130 ;
int V_131 = 0 , V_132 = 1 ;
char V_65 [ V_66 ] ;
V_128 = fopen ( V_122 , L_58 ) ;
if ( ! V_128 ) {
F_28 ( L_59 , V_122 ,
F_40 ( V_133 , V_65 , sizeof( V_65 ) ) ) ;
return - V_133 ;
}
while ( ( V_130 = F_73 ( & line , & V_129 , V_128 ) ) > 0 ) {
if ( line [ V_130 - 1 ] == '\n' )
line [ V_130 - 1 ] = '\0' ;
if ( F_74 ( line , V_127 ) ) {
F_75 ( V_126 , V_132 ) ;
V_131 ++ ;
}
V_132 ++ ;
}
if ( ferror ( V_128 ) )
V_131 = - V_133 ;
free ( line ) ;
fclose ( V_128 ) ;
if ( V_131 == 0 )
F_13 ( L_60 , V_122 ) ;
return V_131 ;
}
static int F_76 ( const char * V_122 , int V_124 ,
T_2 V_25 , void * V_114 )
{
struct V_87 * V_88 = V_114 ;
T_1 * V_91 , V_81 ;
int V_37 ;
if ( ! F_77 ( V_88 -> V_134 , V_124 ) ||
F_69 ( V_122 , V_88 -> V_122 ) != 0 )
return 0 ;
F_13 ( L_61 ,
V_124 , ( unsigned long long ) V_25 ) ;
V_88 -> V_25 = V_25 ;
V_88 -> V_118 = V_124 ;
V_91 = F_66 ( V_88 , & V_81 ) ;
if ( ! V_91 ) {
F_28 ( L_57 ) ;
return - V_10 ;
}
V_37 = F_55 ( V_91 , V_88 ) ;
return V_37 < 0 ? V_37 : 0 ;
}
static int F_78 ( T_1 * V_27 , struct V_87 * V_88 )
{
int V_37 = 0 ;
char * V_135 ;
if ( F_79 ( V_88 -> V_134 ) ) {
const char * V_136 ;
V_136 = F_80 ( & V_88 -> V_93 ) ;
V_37 = F_81 ( V_88 -> V_122 , V_136 , & V_135 ) ;
if ( V_37 < 0 ) {
F_28 ( L_62 ) ;
return V_37 ;
}
V_37 = F_72 ( V_88 -> V_134 , V_135 ,
V_88 -> V_120 -> V_121 . V_137 ) ;
free ( V_135 ) ;
if ( V_37 <= 0 )
return V_37 ;
}
return F_71 ( V_27 , F_76 , V_88 ) ;
}
static void F_82 ( T_1 * V_27 , struct V_87 * V_88 )
{
struct V_138 * V_139 = & V_88 -> V_120 -> V_121 ;
if ( ! V_88 -> V_120 -> V_140 )
return;
if ( F_83 ( & V_88 -> V_93 ) )
return;
if ( ! V_88 -> V_25 )
return;
if ( ! V_139 -> V_96 || V_139 -> line || V_139 -> V_95 || V_139 -> V_137 ||
V_139 -> V_23 || V_139 -> V_141 )
return;
if ( ! F_84 ( V_88 -> V_120 ) )
return;
F_39 ( L_63
L_64 V_142 L_65 ,
V_88 -> V_25 ) ;
F_85 ( V_27 , & V_88 -> V_93 , & V_88 -> V_25 ) ;
}
static int F_86 ( T_1 * V_143 , void * V_114 )
{
struct V_87 * V_88 = V_114 ;
struct V_138 * V_139 = & V_88 -> V_120 -> V_121 ;
T_2 V_25 ;
int V_37 ;
if ( V_139 -> V_137 )
V_37 = F_78 ( V_143 , V_88 ) ;
else {
if ( F_23 ( V_143 , & V_25 ) != 0 ) {
F_28 ( L_66 ,
F_26 ( V_143 ) ) ;
return - V_10 ;
}
if ( V_25 == 0 ) {
F_13 ( L_67 ,
F_26 ( V_143 ) ) ;
return - V_10 ;
}
V_88 -> V_25 = V_25 ;
V_88 -> V_25 += V_139 -> V_23 ;
F_13 ( L_68 ,
( V_111 ) V_88 -> V_25 ) ;
V_37 = F_55 ( V_143 , V_88 ) ;
}
return V_37 ;
}
static int F_87 ( T_1 * V_27 , void * V_114 )
{
struct V_144 * V_145 = V_114 ;
struct V_87 * V_88 = V_145 -> V_114 ;
struct V_138 * V_139 = & V_88 -> V_120 -> V_121 ;
if ( ! F_56 ( V_27 ) ||
! F_64 ( V_27 , V_139 -> V_96 ) )
return V_146 ;
if ( V_139 -> V_117 && F_69 ( V_139 -> V_117 , F_63 ( V_27 ) ) )
return V_146 ;
F_13 ( L_69 , F_26 ( V_27 ) ,
( unsigned long ) F_43 ( V_27 ) ) ;
V_88 -> V_122 = F_63 ( V_27 ) ;
if ( V_139 -> line ) {
F_65 ( V_27 , & V_88 -> V_118 ) ;
V_88 -> V_118 += V_139 -> line ;
V_145 -> V_147 = F_70 ( V_88 ) ;
} else if ( F_88 ( V_27 ) ) {
F_23 ( V_27 , & V_88 -> V_25 ) ;
if ( V_88 -> V_25 == 0 ) {
F_13 ( L_70 ,
F_26 ( V_27 ) ) ;
V_145 -> V_147 = 0 ;
} else if ( V_139 -> V_137 )
V_145 -> V_147 = F_78 ( V_27 , V_88 ) ;
else {
F_82 ( V_27 , V_88 ) ;
V_88 -> V_25 += V_139 -> V_23 ;
V_145 -> V_147 = F_55 ( V_27 , V_88 ) ;
}
} else if ( ! V_43 . V_148 ) {
V_145 -> V_147 = F_89 ( V_27 ,
F_86 , ( void * ) V_88 ) ;
if ( V_145 -> V_147 == - V_10 )
V_145 -> V_147 = 0 ;
}
if ( F_90 ( V_139 -> V_96 ) && V_145 -> V_147 >= 0 ) {
V_145 -> V_147 = 0 ;
return V_146 ;
}
return V_149 ;
}
static int F_91 ( struct V_87 * V_88 )
{
struct V_144 V_150 = { . V_114 = ( void * ) V_88 ,
. V_147 = 0 } ;
F_92 ( & V_88 -> V_93 , F_87 , & V_150 , 0 ) ;
return V_150 . V_147 ;
}
static int F_93 ( T_12 * V_2 , T_13 * V_151 , void * V_114 )
{
struct V_152 * V_145 = V_114 ;
if ( F_94 ( V_2 , V_151 -> V_153 , V_145 -> V_27 ) ) {
if ( F_24 ( V_145 -> V_27 ) != V_154 )
return V_146 ;
if ( F_64 ( V_145 -> V_27 , V_145 -> V_96 ) ) {
if ( ! F_94 ( V_2 , V_151 -> V_155 , V_145 -> V_93 ) )
return V_146 ;
if ( V_145 -> V_117 &&
F_69 ( V_145 -> V_117 , F_63 ( V_145 -> V_27 ) ) )
return V_146 ;
V_145 -> V_48 = 1 ;
return V_149 ;
}
}
return V_146 ;
}
static int F_95 ( struct V_1 * V_2 ,
struct V_87 * V_88 )
{
struct V_138 * V_139 = & V_88 -> V_120 -> V_121 ;
T_14 V_156 , V_157 ;
T_5 V_158 ;
T_1 * V_159 ;
int V_37 = 0 ;
V_156 = 0 ;
V_88 -> V_134 = F_96 ( NULL ) ;
if ( ! V_88 -> V_134 )
return - V_52 ;
if ( V_139 -> V_96 && ! F_90 ( V_139 -> V_96 ) ) {
struct V_152 V_160 = {
. V_96 = V_139 -> V_96 ,
. V_117 = V_139 -> V_117 ,
. V_93 = & V_88 -> V_93 ,
. V_27 = & V_88 -> V_27 ,
. V_48 = 0 ,
} ;
struct V_144 V_161 = {
. V_114 = V_88 ,
} ;
F_97 ( V_2 -> V_2 , F_93 ,
& V_160 , 0 ) ;
if ( V_160 . V_48 ) {
V_37 = F_87 ( & V_88 -> V_27 , & V_161 ) ;
if ( V_37 )
goto V_48;
}
}
while ( ! F_98 ( V_2 -> V_2 , V_156 , & V_157 , & V_158 , NULL , NULL , NULL ) ) {
V_159 = F_94 ( V_2 -> V_2 , V_156 + V_158 , & V_88 -> V_93 ) ;
if ( ! V_159 )
continue;
if ( V_139 -> V_117 )
V_88 -> V_122 = F_99 ( & V_88 -> V_93 , V_139 -> V_117 ) ;
else
V_88 -> V_122 = NULL ;
if ( ! V_139 -> V_117 || V_88 -> V_122 ) {
if ( V_139 -> V_96 )
V_37 = F_91 ( V_88 ) ;
else if ( V_139 -> V_137 )
V_37 = F_78 ( & V_88 -> V_93 , V_88 ) ;
else {
V_88 -> V_118 = V_139 -> line ;
V_37 = F_70 ( V_88 ) ;
}
if ( V_37 < 0 )
break;
}
V_156 = V_157 ;
}
V_48:
F_100 ( V_88 -> V_134 ) ;
V_88 -> V_134 = NULL ;
return V_37 ;
}
static int F_101 ( struct V_1 * V_2 ,
struct V_87 * V_88 )
{
int V_37 = 0 ;
T_15 * V_162 ;
T_16 V_163 ;
if ( V_88 -> V_109 || V_88 -> V_110 )
return F_95 ( V_2 , V_88 ) ;
V_162 = F_102 ( V_2 -> V_2 ) ;
if ( V_162 == NULL )
return - V_42 ;
if ( F_103 ( V_162 , & V_163 ) == NULL )
return - V_42 ;
V_88 -> V_28 = V_163 . V_164 ;
#if F_59 ( 0 , 142 )
do {
T_17 V_165 ;
if ( F_104 ( V_162 , & V_163 , & V_165 , L_71 , NULL ) &&
V_165 . V_166 == V_167 )
V_88 -> V_109 = F_105 ( V_162 ) ;
V_88 -> V_110 = F_106 ( V_2 -> V_2 ) ;
} while ( 0 );
#endif
V_37 = F_95 ( V_2 , V_88 ) ;
return V_37 ;
}
static int F_107 ( T_1 * V_81 , void * V_114 )
{
struct V_168 * V_169 = V_114 ;
struct V_87 * V_88 = V_169 -> V_88 ;
int V_82 ;
V_82 = F_24 ( V_81 ) ;
if ( V_82 == V_47 ||
( V_82 == V_45 && V_169 -> V_170 ) ) {
if ( F_20 ( V_81 , V_169 -> V_88 -> V_25 ,
V_169 -> V_88 -> V_26 , & V_88 -> V_27 ,
V_88 -> V_28 , NULL ) == 0 ) {
V_169 -> args [ V_169 -> V_171 ] . V_90 = ( char * ) F_26 ( V_81 ) ;
if ( V_169 -> args [ V_169 -> V_171 ] . V_90 == NULL ) {
V_169 -> V_37 = - V_52 ;
return V_172 ;
}
F_13 ( L_72 , V_169 -> args [ V_169 -> V_171 ] . V_90 ) ;
V_169 -> V_171 ++ ;
}
}
if ( F_108 ( V_81 , V_169 -> V_88 -> V_25 ) )
return V_173 ;
else
return V_174 ;
}
static int F_109 ( T_1 * V_91 , struct V_87 * V_88 ,
struct V_175 * args )
{
T_1 V_81 ;
int V_176 ;
int V_177 = 0 ;
struct V_168 V_169 = { . V_88 = V_88 , . args = args , . V_170 = false ,
. V_178 = V_179 , . V_37 = 0 } ;
for ( V_176 = 0 ; V_176 < V_88 -> V_120 -> V_171 ; V_176 ++ ) {
if ( strcmp ( V_88 -> V_120 -> args [ V_176 ] . V_90 , V_180 ) == 0 )
V_169 . V_170 = true ;
else if ( strcmp ( V_88 -> V_120 -> args [ V_176 ] . V_90 , V_181 ) != 0 ) {
args [ V_177 ] = V_88 -> V_120 -> args [ V_176 ] ;
V_177 ++ ;
continue;
}
F_13 ( L_73 , V_88 -> V_120 -> args [ V_176 ] . V_90 ) ;
V_169 . V_171 = V_177 ;
F_110 ( V_91 , F_107 , ( void * ) & V_169 ,
& V_81 ) ;
F_13 ( L_74 , V_169 . V_171 - V_177 ) ;
if ( V_169 . V_37 < 0 )
return V_169 . V_37 ;
V_177 = V_169 . V_171 ;
}
return V_177 ;
}
static int F_111 ( T_1 * V_91 , struct V_87 * V_88 )
{
struct V_182 * V_183 =
F_112 ( V_88 , struct V_182 , V_88 ) ;
struct V_138 * V_139 = & V_88 -> V_120 -> V_121 ;
struct V_184 * V_185 ;
struct V_175 * args = NULL ;
int V_37 , V_176 ;
if ( V_183 -> V_186 == V_183 -> V_187 ) {
F_28 ( L_75 ,
V_183 -> V_187 ) ;
return - V_46 ;
}
V_185 = & V_183 -> V_188 [ V_183 -> V_186 ++ ] ;
V_37 = F_53 ( & V_88 -> V_27 , V_183 -> V_8 , V_88 -> V_25 ,
V_139 -> V_95 , V_139 -> V_96 , & V_185 -> V_121 ) ;
if ( V_37 < 0 )
goto V_189;
V_185 -> V_121 . V_190 = F_29 ( F_26 ( V_91 ) ) ;
if ( ! V_185 -> V_121 . V_190 ) {
V_37 = - V_52 ;
goto V_189;
}
F_13 ( L_76 , V_185 -> V_121 . V_102 ,
V_185 -> V_121 . V_23 ) ;
args = F_11 ( sizeof( struct V_175 ) * V_179 ) ;
if ( args == NULL ) {
V_37 = - V_52 ;
goto V_189;
}
V_37 = F_109 ( V_91 , V_88 , args ) ;
if ( V_37 < 0 )
goto V_189;
V_185 -> V_171 = V_37 ;
V_185 -> args = F_11 ( sizeof( struct V_29 ) * V_185 -> V_171 ) ;
if ( V_185 -> args == NULL ) {
V_37 = - V_52 ;
goto V_189;
}
for ( V_176 = 0 ; V_176 < V_185 -> V_171 ; V_176 ++ ) {
V_88 -> V_89 = & args [ V_176 ] ;
V_88 -> V_30 = & V_185 -> args [ V_176 ] ;
V_37 = F_48 ( V_91 , V_88 ) ;
if ( V_37 != 0 )
break;
}
V_189:
if ( V_37 ) {
F_113 ( V_185 ) ;
V_183 -> V_186 -- ;
}
free ( args ) ;
return V_37 ;
}
int F_114 ( struct V_1 * V_2 ,
struct V_191 * V_120 ,
struct V_184 * * V_188 )
{
struct V_182 V_183 = {
. V_88 = { . V_120 = V_120 , . V_112 = F_111 } ,
. V_187 = V_43 . V_192 , . V_8 = V_2 -> V_8 } ;
int V_37 , V_176 ;
* V_188 = F_11 ( sizeof( struct V_184 ) * V_183 . V_187 ) ;
if ( * V_188 == NULL )
return - V_52 ;
V_183 . V_188 = * V_188 ;
V_183 . V_186 = 0 ;
V_37 = F_101 ( V_2 , & V_183 . V_88 ) ;
if ( V_37 < 0 ) {
for ( V_176 = 0 ; V_176 < V_183 . V_186 ; V_176 ++ )
F_113 ( & V_183 . V_188 [ V_176 ] ) ;
F_12 ( V_188 ) ;
return V_37 ;
}
return ( V_37 < 0 ) ? V_37 : V_183 . V_186 ;
}
static int F_115 ( T_1 * V_81 , void * V_114 )
{
struct V_193 * V_194 = V_114 ;
struct V_195 * V_196 ;
struct V_197 V_12 = V_198 ;
int V_82 , V_37 ;
V_196 = & V_194 -> V_199 [ V_194 -> V_200 - 1 ] ;
V_82 = F_24 ( V_81 ) ;
if ( V_82 == V_47 ||
V_82 == V_45 ) {
V_37 = F_20 ( V_81 , V_194 -> V_88 . V_25 ,
V_194 -> V_88 . V_26 , & V_194 -> V_88 . V_27 ,
V_194 -> V_88 . V_28 , NULL ) ;
if ( V_37 == 0 || V_37 == - V_46 ) {
int V_38 ;
bool V_201 = ! V_194 -> V_202 ;
if ( F_116 ( & V_12 , 64 ) < 0 )
goto error;
if ( V_43 . V_44 ) {
if ( ! V_201 )
V_38 = F_117 ( & V_12 ,
V_37 ? L_77 : L_78 , 6 ) ;
else
V_38 = F_117 ( & V_12 , L_79 , 6 ) ;
if ( V_38 )
goto error;
}
V_38 = F_118 ( V_81 , & V_12 ) ;
if ( ! V_38 && V_43 . V_44 &&
! V_201 ) {
if ( F_119 ( & V_12 , '\t' ) < 0 )
goto error;
V_38 = F_120 ( & V_194 -> V_88 . V_27 ,
V_81 , & V_12 ) ;
}
F_13 ( L_80 , V_12 . V_12 ) ;
if ( V_38 == 0 ) {
F_121 ( V_196 -> V_170 ,
F_122 ( & V_12 , NULL ) ) ;
}
F_123 ( & V_12 ) ;
}
}
if ( V_194 -> V_202 && F_108 ( V_81 , V_194 -> V_88 . V_25 ) )
return V_173 ;
else
return V_174 ;
error:
F_123 ( & V_12 ) ;
F_13 ( L_81 ) ;
return V_172 ;
}
static int F_124 ( T_1 * V_91 , struct V_87 * V_88 )
{
struct V_193 * V_194 =
F_112 ( V_88 , struct V_193 , V_88 ) ;
struct V_138 * V_139 = & V_88 -> V_120 -> V_121 ;
struct V_195 * V_196 ;
T_1 V_81 ;
int V_37 ;
if ( V_194 -> V_200 == V_194 -> V_203 ) {
F_28 ( L_75 , V_194 -> V_203 ) ;
return - V_46 ;
}
V_196 = & V_194 -> V_199 [ V_194 -> V_200 ++ ] ;
V_37 = F_53 ( & V_88 -> V_27 , V_194 -> V_8 , V_88 -> V_25 ,
V_139 -> V_95 , V_139 -> V_96 , & V_196 -> V_121 ) ;
if ( V_37 < 0 )
return V_37 ;
F_13 ( L_76 , V_196 -> V_121 . V_102 ,
V_196 -> V_121 . V_23 ) ;
V_196 -> V_170 = F_125 ( NULL , NULL ) ;
if ( V_196 -> V_170 == NULL )
return - V_52 ;
V_194 -> V_202 = true ;
F_110 ( V_91 , F_115 , ( void * ) V_194 , & V_81 ) ;
if ( ! V_43 . V_204 )
goto V_17;
V_194 -> V_202 = false ;
F_110 ( & V_88 -> V_93 , F_115 , ( void * ) V_194 , & V_81 ) ;
V_17:
if ( F_126 ( V_196 -> V_170 ) ) {
F_127 ( V_196 -> V_170 ) ;
V_196 -> V_170 = NULL ;
}
return V_37 ;
}
int F_128 ( struct V_1 * V_2 ,
struct V_191 * V_120 ,
struct V_195 * * V_199 )
{
struct V_193 V_194 = {
. V_88 = { . V_120 = V_120 , . V_112 = F_124 } ,
. V_8 = V_2 -> V_8 ,
. V_203 = V_43 . V_192 } ;
int V_37 ;
* V_199 = F_11 ( sizeof( struct V_195 ) * V_194 . V_203 ) ;
if ( * V_199 == NULL )
return - V_52 ;
V_194 . V_199 = * V_199 ;
V_194 . V_200 = 0 ;
V_37 = F_101 ( V_2 , & V_194 . V_88 ) ;
if ( V_37 < 0 ) {
while ( V_194 . V_200 -- ) {
F_12 ( & V_194 . V_199 [ V_194 . V_200 ] . V_121 . V_102 ) ;
F_127 ( V_194 . V_199 [ V_194 . V_200 ] . V_170 ) ;
}
F_12 ( V_199 ) ;
return V_37 ;
}
return ( V_37 < 0 ) ? V_37 : V_194 . V_200 ;
}
static int F_129 ( struct V_1 * V_2 , T_2 * V_21 )
{
int V_177 , V_176 ;
T_18 V_205 ;
T_19 * V_206 ;
T_15 * V_162 ;
T_17 V_207 , * V_165 ;
const char * V_208 ;
V_162 = F_130 ( V_2 -> V_8 , & V_2 -> V_9 ) ;
if ( ! V_162 )
return - V_42 ;
V_177 = F_131 ( V_2 -> V_8 ) ;
if ( V_177 < 0 )
return - V_10 ;
for ( V_176 = 0 ; V_176 < V_177 ; V_176 ++ ) {
V_208 = F_132 ( V_2 -> V_8 , V_176 , & V_205 ) ;
if ( strcmp ( V_208 , L_82 ) == 0 ) {
V_206 = F_133 ( V_162 , V_205 ) ;
if ( ! V_206 )
return - V_10 ;
V_165 = F_134 ( V_206 , & V_207 ) ;
if ( ! V_165 )
return - V_10 ;
* V_21 = V_165 -> V_209 ;
}
}
return 0 ;
}
int F_135 ( struct V_1 * V_2 , unsigned long V_25 ,
struct V_138 * V_210 )
{
T_1 V_211 , V_212 , V_213 ;
T_2 V_214 = 0 , V_215 = 0 ;
const char * V_122 = NULL , * V_216 = NULL , * V_217 = NULL , * V_32 ;
int V_218 = 0 , V_124 = 0 , V_37 = 0 ;
bool V_219 = false ;
V_220:
if ( ! F_136 ( V_2 -> V_2 , ( T_2 ) V_25 , & V_211 ) ) {
if ( ! V_219 && F_129 ( V_2 , & V_215 ) == 0 ) {
V_25 += V_215 ;
V_219 = true ;
goto V_220;
}
F_28 ( L_83 ,
V_25 ) ;
V_37 = - V_42 ;
goto V_189;
}
F_137 ( & V_211 , V_25 , & V_122 , & V_124 ) ;
if ( F_57 ( & V_211 , ( T_2 ) V_25 , & V_212 ) ) {
V_216 = V_217 = F_26 ( & V_212 ) ;
if ( ! V_216 ||
F_23 ( & V_212 , & V_215 ) != 0 ||
F_65 ( & V_212 , & V_218 ) != 0 ) {
V_124 = 0 ;
goto V_221;
}
V_122 = F_63 ( & V_212 ) ;
if ( V_25 == ( unsigned long ) V_215 ) {
V_124 = V_218 ;
goto V_221;
}
while ( F_138 ( & V_212 , ( T_2 ) V_25 ,
& V_213 ) ) {
if ( F_23 ( & V_213 , & V_214 ) == 0 &&
V_214 == V_25 ) {
V_124 = F_139 ( & V_213 ) ;
V_122 = F_140 ( & V_213 ) ;
break;
} else {
V_32 = F_26 ( & V_213 ) ;
if ( ! V_32 ||
F_65 ( & V_213 , & V_218 ) != 0 )
break;
V_216 = V_32 ;
V_212 = V_213 ;
}
}
V_32 = F_63 ( & V_212 ) ;
if ( ! V_32 || strcmp ( V_32 , V_122 ) != 0 )
V_124 = 0 ;
}
V_221:
if ( V_124 )
V_210 -> line = V_124 - V_218 ;
else if ( V_217 ) {
V_210 -> V_23 = V_25 - ( unsigned long ) V_215 ;
V_216 = V_217 ;
}
if ( V_216 ) {
V_210 -> V_96 = F_29 ( V_216 ) ;
if ( V_210 -> V_96 == NULL ) {
V_37 = - V_52 ;
goto V_189;
}
}
if ( V_122 ) {
V_210 -> V_117 = F_29 ( V_122 ) ;
if ( V_210 -> V_117 == NULL ) {
F_12 ( & V_210 -> V_96 ) ;
V_37 = - V_52 ;
goto V_189;
}
}
V_189:
if ( V_37 == 0 && ( V_122 || V_216 ) )
V_37 = 1 ;
return V_37 ;
}
static int F_141 ( const char * V_222 , unsigned int V_124 ,
struct V_223 * V_224 )
{
if ( ! V_224 -> V_3 ) {
V_224 -> V_3 = F_29 ( V_222 ) ;
if ( V_224 -> V_3 == NULL )
return - V_52 ;
}
return F_75 ( V_224 -> V_225 , V_124 ) ;
}
static int F_142 ( const char * V_122 , int V_124 ,
T_2 V_25 V_226 ,
void * V_114 )
{
struct V_227 * V_228 = V_114 ;
int V_229 ;
if ( ( F_69 ( V_122 , V_228 -> V_122 ) != 0 ) ||
( V_228 -> V_230 > V_124 || V_228 -> V_231 < V_124 ) )
return 0 ;
V_229 = F_141 ( V_122 , V_124 , V_228 -> V_224 ) ;
if ( V_229 < 0 && V_229 != - V_232 )
return V_229 ;
return 0 ;
}
static int F_143 ( T_1 * V_27 , struct V_227 * V_228 )
{
int V_37 ;
V_37 = F_71 ( V_27 ? : & V_228 -> V_93 , F_142 , V_228 ) ;
if ( V_37 >= 0 )
if ( ! F_79 ( V_228 -> V_224 -> V_225 ) )
V_37 = V_228 -> V_48 = 1 ;
else
V_37 = 0 ;
else {
F_12 ( & V_228 -> V_224 -> V_3 ) ;
}
return V_37 ;
}
static int F_144 ( T_1 * V_143 , void * V_114 )
{
int V_37 = F_143 ( V_143 , V_114 ) ;
return V_37 < 0 ? V_37 : 0 ;
}
static int F_145 ( T_1 * V_27 , void * V_114 )
{
struct V_144 * V_145 = V_114 ;
struct V_227 * V_228 = V_145 -> V_114 ;
struct V_223 * V_224 = V_228 -> V_224 ;
if ( V_224 -> V_117 && F_69 ( V_224 -> V_117 , F_63 ( V_27 ) ) )
return V_146 ;
if ( F_56 ( V_27 ) &&
F_64 ( V_27 , V_224 -> V_96 ) ) {
V_228 -> V_122 = F_63 ( V_27 ) ;
F_65 ( V_27 , & V_224 -> V_23 ) ;
F_13 ( L_84 , V_228 -> V_122 , V_224 -> V_23 ) ;
V_228 -> V_230 = V_224 -> V_23 + V_224 -> V_233 ;
if ( V_228 -> V_230 < 0 )
V_228 -> V_230 = V_123 ;
V_228 -> V_231 = V_224 -> V_23 + V_224 -> V_189 ;
if ( V_228 -> V_231 < 0 )
V_228 -> V_231 = V_123 ;
F_13 ( L_85 , V_228 -> V_230 , V_228 -> V_231 ) ;
V_224 -> V_233 = V_228 -> V_230 ;
V_224 -> V_189 = V_228 -> V_231 ;
if ( ! F_88 ( V_27 ) )
V_145 -> V_147 = F_89 ( V_27 ,
F_144 , V_228 ) ;
else
V_145 -> V_147 = F_143 ( V_27 , V_228 ) ;
return V_149 ;
}
return V_146 ;
}
static int F_146 ( struct V_227 * V_228 )
{
struct V_144 V_145 = { . V_114 = ( void * ) V_228 , . V_147 = 0 } ;
F_92 ( & V_228 -> V_93 , F_145 , & V_145 , 0 ) ;
return V_145 . V_147 ;
}
int F_147 ( struct V_1 * V_2 , struct V_223 * V_224 )
{
struct V_227 V_228 = { . V_224 = V_224 , . V_48 = 0 } ;
int V_37 = 0 ;
T_14 V_156 = 0 , V_157 ;
T_5 V_158 ;
T_1 * V_159 ;
const char * V_136 ;
if ( V_224 -> V_96 ) {
struct V_152 V_160 = {
. V_96 = V_224 -> V_96 , . V_117 = V_224 -> V_117 ,
. V_93 = & V_228 . V_93 , . V_27 = & V_228 . V_27 , . V_48 = 0 } ;
struct V_144 V_234 = {
. V_114 = ( void * ) & V_228 , . V_147 = 0 } ;
F_97 ( V_2 -> V_2 , F_93 ,
& V_160 , 0 ) ;
if ( V_160 . V_48 ) {
F_145 ( & V_228 . V_27 , & V_234 ) ;
if ( V_228 . V_48 )
goto V_48;
}
}
while ( ! V_228 . V_48 && V_37 >= 0 ) {
if ( F_98 ( V_2 -> V_2 , V_156 , & V_157 , & V_158 ,
NULL , NULL , NULL ) != 0 )
break;
V_159 = F_94 ( V_2 -> V_2 , V_156 + V_158 , & V_228 . V_93 ) ;
if ( ! V_159 )
continue;
if ( V_224 -> V_117 )
V_228 . V_122 = F_99 ( & V_228 . V_93 , V_224 -> V_117 ) ;
else
V_228 . V_122 = 0 ;
if ( ! V_224 -> V_117 || V_228 . V_122 ) {
if ( V_224 -> V_96 )
V_37 = F_146 ( & V_228 ) ;
else {
V_228 . V_230 = V_224 -> V_233 ;
V_228 . V_231 = V_224 -> V_189 ;
V_37 = F_143 ( NULL , & V_228 ) ;
}
}
V_156 = V_157 ;
}
V_48:
if ( V_228 . V_48 ) {
V_136 = F_80 ( & V_228 . V_93 ) ;
if ( V_136 ) {
V_224 -> V_136 = F_29 ( V_136 ) ;
if ( ! V_224 -> V_136 )
V_37 = - V_52 ;
}
}
F_13 ( L_86 , V_224 -> V_3 ) ;
return ( V_37 < 0 ) ? V_37 : V_228 . V_48 ;
}
int F_81 ( const char * V_235 , const char * V_136 ,
char * * V_236 )
{
const char * V_70 = V_237 . V_238 ;
if ( ! V_70 ) {
if ( V_235 [ 0 ] != '/' && V_136 )
V_70 = V_136 ;
else {
if ( F_148 ( V_235 , V_239 ) == 0 ) {
* V_236 = F_29 ( V_235 ) ;
return * V_236 ? 0 : - V_52 ;
} else
return - V_133 ;
}
}
* V_236 = malloc ( ( strlen ( V_70 ) + strlen ( V_235 ) + 2 ) ) ;
if ( ! * V_236 )
return - V_52 ;
for (; ; ) {
sprintf ( * V_236 , L_87 , V_70 , V_235 ) ;
if ( F_148 ( * V_236 , V_239 ) == 0 )
return 0 ;
if ( ! V_237 . V_238 ) {
F_12 ( V_236 ) ;
return - V_133 ;
}
switch ( V_133 ) {
case V_240 :
case V_10 :
case V_241 :
case V_242 :
V_235 = strchr ( ++ V_235 , '/' ) ;
if ( ! V_235 ) {
F_12 ( V_236 ) ;
return - V_10 ;
}
continue;
default:
F_12 ( V_236 ) ;
return - V_133 ;
}
}
}
