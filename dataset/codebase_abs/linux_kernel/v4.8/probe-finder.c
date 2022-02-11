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
struct V_28 * V_29 )
{
T_4 V_30 ;
T_2 V_31 = 0 ;
T_3 * V_32 ;
T_5 V_33 ;
unsigned int V_34 ;
T_6 V_21 = 0 ;
bool V_22 = false ;
const char * V_35 ;
int V_36 , V_37 = 0 ;
if ( F_21 ( V_24 , V_38 , & V_30 ) != NULL )
goto V_39;
if ( F_21 ( V_24 , V_40 , & V_30 ) == NULL )
return - V_41 ;
if ( F_22 ( & V_30 , V_25 , & V_32 , & V_33 , 1 ) <= 0 ) {
V_36 = F_23 ( V_27 , & V_31 ) ;
if ( V_36 )
return - V_10 ;
if ( V_42 . V_43 &&
( F_24 ( V_24 ) == V_44 ) ) {
V_37 = - V_45 ;
} else if ( V_25 != V_31 ||
F_24 ( V_24 ) != V_46 ) {
return - V_10 ;
}
V_36 = F_25 ( V_27 , & V_31 ) ;
if ( V_36 )
return - V_10 ;
for ( V_25 += 1 ; V_25 <= V_31 ; V_25 ++ ) {
if ( F_22 ( & V_30 , V_25 , & V_32 ,
& V_33 , 1 ) > 0 )
goto V_47;
}
return - V_10 ;
}
V_47:
if ( V_33 == 0 )
return - V_10 ;
if ( V_32 -> V_48 == V_49 ) {
V_39:
if ( ! V_29 )
return V_37 ;
V_36 = strlen ( F_26 ( V_24 ) ) ;
V_29 -> V_50 = F_11 ( V_36 + 2 ) ;
if ( V_29 -> V_50 == NULL )
return - V_51 ;
snprintf ( V_29 -> V_50 , V_36 + 2 , L_3 , F_26 ( V_24 ) ) ;
V_29 -> V_22 = F_19 ( ( long ) V_21 ) ;
if ( V_29 -> V_22 == NULL )
return - V_51 ;
return V_37 ;
}
if ( V_32 -> V_48 == V_52 ) {
if ( V_26 == NULL )
return - V_53 ;
V_22 = true ;
V_21 = V_32 -> V_54 ;
V_32 = & V_26 [ 0 ] ;
}
if ( V_32 -> V_48 >= V_55 && V_32 -> V_48 <= V_56 ) {
V_34 = V_32 -> V_48 - V_55 ;
V_21 += V_32 -> V_54 ;
V_22 = true ;
} else if ( V_32 -> V_48 >= V_57 && V_32 -> V_48 <= V_58 ) {
V_34 = V_32 -> V_48 - V_57 ;
} else if ( V_32 -> V_48 == V_59 ) {
V_34 = V_32 -> V_54 ;
V_21 += V_32 -> V_60 ;
V_22 = true ;
} else if ( V_32 -> V_48 == V_61 ) {
V_34 = V_32 -> V_54 ;
} else {
F_13 ( L_4 , V_32 -> V_48 ) ;
return - V_53 ;
}
if ( ! V_29 )
return V_37 ;
V_35 = F_27 ( V_34 ) ;
if ( ! V_35 ) {
F_28 ( L_5
L_6 , V_34 ) ;
return - V_53 ;
}
V_29 -> V_50 = F_29 ( V_35 ) ;
if ( V_29 -> V_50 == NULL )
return - V_51 ;
if ( V_22 ) {
V_29 -> V_22 = F_19 ( ( long ) V_21 ) ;
if ( V_29 -> V_22 == NULL )
return - V_51 ;
}
return V_37 ;
}
static int F_30 ( T_1 * V_24 ,
struct V_28 * V_29 ,
const char * V_62 )
{
struct V_20 * * V_63 = & V_29 -> V_22 ;
T_1 type ;
char V_12 [ 16 ] ;
char V_64 [ V_65 ] ;
int V_66 , V_67 , V_68 ;
int V_36 ;
char V_69 ;
if ( V_62 && strcmp ( V_62 , L_7 ) != 0 &&
strcmp ( V_62 , L_8 ) != 0 && strcmp ( V_62 , L_9 ) != 0 ) {
V_29 -> type = F_29 ( V_62 ) ;
return ( V_29 -> type == NULL ) ? - V_51 : 0 ;
}
V_66 = F_31 ( V_24 ) ;
if ( V_66 > 0 ) {
V_67 = F_32 ( V_24 ) ;
V_68 = F_33 ( V_24 ) ;
if ( V_67 < 0 || V_68 < 0 )
return - V_10 ;
V_36 = snprintf ( V_12 , 16 , L_10 , V_66 , V_67 ,
F_34 ( V_68 ) ) ;
goto V_70;
}
if ( F_35 ( V_24 , & type ) == NULL ) {
F_28 ( L_11 ,
F_26 ( V_24 ) ) ;
return - V_10 ;
}
F_13 ( L_12 ,
F_26 ( V_24 ) , F_26 ( & type ) ) ;
if ( V_62 && strcmp ( V_62 , L_7 ) == 0 ) {
V_36 = F_24 ( & type ) ;
if ( V_36 != V_71 &&
V_36 != V_72 ) {
F_28 ( L_13
L_14 ,
F_26 ( V_24 ) , F_26 ( & type ) ) ;
return - V_41 ;
}
if ( F_35 ( & type , & type ) == NULL ) {
F_28 ( L_15
L_16 ) ;
return - V_10 ;
}
if ( V_36 == V_71 ) {
while ( * V_63 )
V_63 = & ( * V_63 ) -> V_73 ;
* V_63 = F_11 ( sizeof( struct V_20 ) ) ;
if ( * V_63 == NULL ) {
F_28 ( L_17 ) ;
return - V_51 ;
}
}
if ( ! F_36 ( & type , L_18 ) &&
! F_36 ( & type , L_19 ) ) {
F_28 ( L_13
L_20 ,
F_26 ( V_24 ) ) ;
return - V_41 ;
}
V_29 -> type = F_29 ( V_62 ) ;
return ( V_29 -> type == NULL ) ? - V_51 : 0 ;
}
if ( V_62 && ( strcmp ( V_62 , L_9 ) == 0 ) )
V_69 = 'u' ;
else if ( V_62 && ( strcmp ( V_62 , L_8 ) == 0 ) )
V_69 = 's' ;
else
V_69 = F_37 ( & type ) ? 's' : 'u' ;
V_36 = F_33 ( & type ) ;
if ( V_36 <= 0 )
return 0 ;
V_36 = F_34 ( V_36 ) ;
if ( V_36 > V_74 ) {
F_38 ( L_21 ,
F_26 ( & type ) , V_74 ) ;
V_36 = V_74 ;
}
V_36 = snprintf ( V_12 , 16 , L_22 , V_69 , V_36 ) ;
V_70:
if ( V_36 < 0 || V_36 >= 16 ) {
if ( V_36 >= 16 )
V_36 = - V_75 ;
F_28 ( L_23 ,
F_39 ( - V_36 , V_64 , sizeof( V_64 ) ) ) ;
return V_36 ;
}
V_29 -> type = F_29 ( V_12 ) ;
if ( V_29 -> type == NULL )
return - V_51 ;
return 0 ;
}
static int F_40 ( T_1 * V_24 , const char * V_76 ,
struct V_77 * V_78 ,
struct V_20 * * V_63 ,
T_1 * V_79 )
{
struct V_20 * V_22 = * V_63 ;
T_1 type ;
T_6 V_21 ;
int V_36 , V_80 ;
F_13 ( L_24 , V_78 -> V_81 , V_76 ) ;
if ( F_35 ( V_24 , & type ) == NULL ) {
F_28 ( L_25 , V_76 ) ;
return - V_10 ;
}
F_41 ( L_26 , ( unsigned ) F_42 ( & type ) ) ;
V_80 = F_24 ( & type ) ;
if ( V_78 -> V_81 [ 0 ] == '[' &&
( V_80 == V_72 || V_80 == V_71 ) ) {
if ( V_78 -> V_73 )
memcpy ( V_79 , & type , sizeof( * V_79 ) ) ;
if ( F_35 ( & type , & type ) == NULL ) {
F_28 ( L_25 , V_76 ) ;
return - V_10 ;
}
F_41 ( L_27 ,
( unsigned ) F_42 ( & type ) ) ;
if ( V_80 == V_71 ) {
V_22 = F_11 ( sizeof( struct V_20 ) ) ;
if ( V_22 == NULL )
return - V_51 ;
if ( * V_63 )
( * V_63 ) -> V_73 = V_22 ;
else
* V_63 = V_22 ;
}
V_22 -> V_23 += F_33 ( & type ) * V_78 -> V_82 ;
if ( ! V_78 -> V_73 )
memcpy ( V_79 , V_24 , sizeof( * V_79 ) ) ;
goto V_73;
} else if ( V_80 == V_71 ) {
if ( ! V_78 -> V_22 ) {
F_43 ( L_28 ,
V_78 -> V_81 ) ;
return - V_41 ;
}
if ( F_35 ( & type , & type ) == NULL ) {
F_28 ( L_25 , V_76 ) ;
return - V_10 ;
}
V_80 = F_24 ( & type ) ;
if ( V_80 != V_83 && V_80 != V_84 ) {
F_28 ( L_29 ,
V_76 ) ;
return - V_41 ;
}
V_22 = F_11 ( sizeof( struct V_20 ) ) ;
if ( V_22 == NULL )
return - V_51 ;
if ( * V_63 )
( * V_63 ) -> V_73 = V_22 ;
else
* V_63 = V_22 ;
} else {
if ( V_80 != V_83 && V_80 != V_84 ) {
F_28 ( L_29 ,
V_76 ) ;
return - V_41 ;
}
if ( V_78 -> V_81 [ 0 ] == '[' ) {
F_43 ( L_30
L_31 , V_76 ) ;
return - V_41 ;
}
if ( V_78 -> V_22 && F_26 ( V_24 ) ) {
F_43 ( L_32 ,
V_78 -> V_81 ) ;
return - V_41 ;
}
if ( ! V_22 ) {
F_28 ( L_33
L_34 ) ;
return - V_53 ;
}
}
if ( F_44 ( & type , V_78 -> V_81 , V_79 ) == NULL ) {
F_28 ( L_35 , V_76 ,
F_26 ( & type ) , V_78 -> V_81 ) ;
return - V_41 ;
}
if ( V_80 == V_84 ) {
V_21 = 0 ;
} else {
V_36 = F_45 ( V_79 , & V_21 ) ;
if ( V_36 < 0 ) {
F_28 ( L_36 ,
V_78 -> V_81 ) ;
return V_36 ;
}
}
V_22 -> V_23 += ( long ) V_21 ;
if ( ! F_26 ( V_79 ) )
return F_40 ( V_79 , V_76 , V_78 ,
& V_22 , V_79 ) ;
V_73:
if ( V_78 -> V_73 )
return F_40 ( V_79 , V_78 -> V_81 ,
V_78 -> V_73 , & V_22 , V_79 ) ;
else
return 0 ;
}
static int F_46 ( T_1 * V_24 , struct V_85 * V_86 )
{
T_1 V_79 ;
int V_36 ;
F_13 ( L_37 ,
F_26 ( V_24 ) ) ;
V_36 = F_20 ( V_24 , V_86 -> V_25 , V_86 -> V_26 ,
& V_86 -> V_27 , V_86 -> V_29 ) ;
if ( V_36 == - V_10 || V_36 == - V_41 ) {
F_43 ( L_38
L_39
L_40 ,
V_86 -> V_87 -> V_88 , V_86 -> V_87 -> V_88 ) ;
} else if ( V_36 == - V_53 )
F_43 ( L_41 ) ;
else if ( V_36 == 0 && V_86 -> V_87 -> V_78 ) {
V_36 = F_40 ( V_24 , V_86 -> V_87 -> V_88 ,
V_86 -> V_87 -> V_78 , & V_86 -> V_29 -> V_22 ,
& V_79 ) ;
V_24 = & V_79 ;
}
if ( V_36 == 0 )
V_36 = F_30 ( V_24 , V_86 -> V_29 , V_86 -> V_87 -> type ) ;
return V_36 ;
}
static int F_47 ( T_1 * V_89 , struct V_85 * V_86 )
{
T_1 V_24 ;
char * V_12 , * V_90 ;
int V_36 = 0 ;
if ( ! F_48 ( V_86 -> V_87 -> V_88 ) )
return F_49 ( V_86 -> V_29 , V_86 -> V_87 ) ;
if ( V_86 -> V_87 -> V_81 )
V_86 -> V_29 -> V_81 = F_29 ( V_86 -> V_87 -> V_81 ) ;
else {
V_12 = F_50 ( V_86 -> V_87 ) ;
if ( ! V_12 )
return - V_51 ;
V_90 = strchr ( V_12 , ':' ) ;
if ( V_90 )
* V_90 = '_' ;
V_86 -> V_29 -> V_81 = V_12 ;
}
if ( V_86 -> V_29 -> V_81 == NULL )
return - V_51 ;
F_13 ( L_42 , V_86 -> V_87 -> V_88 ) ;
if ( ! F_51 ( V_89 , V_86 -> V_87 -> V_88 , V_86 -> V_25 , & V_24 ) ) {
if ( ! F_51 ( & V_86 -> V_91 , V_86 -> V_87 -> V_88 ,
0 , & V_24 ) ) {
F_28 ( L_43 ,
V_86 -> V_87 -> V_88 ) ;
V_36 = - V_10 ;
}
}
if ( V_36 >= 0 )
V_36 = F_46 ( & V_24 , V_86 ) ;
return V_36 ;
}
static int F_52 ( T_1 * V_27 , T_7 * V_8 ,
T_2 V_92 , bool V_93 ,
const char * V_94 ,
struct V_95 * V_96 )
{
T_2 V_97 , V_98 ;
T_8 V_99 ;
const char * V_100 ;
if ( F_23 ( V_27 , & V_97 ) != 0 ) {
F_28 ( L_44 ,
F_26 ( V_27 ) ) ;
return - V_10 ;
}
if ( F_25 ( V_27 , & V_98 ) != 0 ) {
F_28 ( L_45 ,
F_26 ( V_27 ) ) ;
return - V_10 ;
}
if ( V_92 > V_98 ) {
F_28 ( L_46 ,
F_26 ( V_27 ) ) ;
return - V_41 ;
}
V_100 = F_26 ( V_27 ) ;
if ( ! V_100 ) {
V_100 = F_53 ( V_8 , V_92 , & V_99 , NULL ) ;
if ( ! V_100 ) {
F_28 ( L_47 ,
( unsigned long ) V_92 ) ;
return - V_10 ;
}
V_97 = V_99 . V_101 ;
}
V_96 -> V_23 = ( unsigned long ) ( V_92 - V_97 ) ;
V_96 -> V_102 = ( unsigned long ) V_92 ;
V_96 -> V_100 = F_29 ( V_100 ) ;
if ( ! V_96 -> V_100 )
return - V_51 ;
if ( V_93 ) {
if ( V_97 != V_92 ) {
F_28 ( L_48
L_49
L_50 , V_94 ,
V_94 ) ;
return - V_41 ;
}
V_96 -> V_93 = true ;
}
return 0 ;
}
static int F_54 ( T_1 * V_89 , struct V_85 * V_86 )
{
T_4 V_103 ;
T_9 * V_104 = NULL ;
T_5 V_33 ;
int V_36 ;
if ( ! V_89 ) {
F_43 ( L_51 ) ;
return - V_41 ;
}
if ( ! F_55 ( V_89 ) ) {
if ( ! F_56 ( & V_86 -> V_91 , V_86 -> V_25 , & V_86 -> V_27 ) ) {
if ( F_57 ( & V_86 -> V_91 , V_86 -> V_25 , & V_86 -> V_27 ) ) {
F_28 ( L_52 ,
F_26 ( & V_86 -> V_27 ) ) ;
return 0 ;
} else {
F_28 ( L_53
L_54 ) ;
return - V_10 ;
}
}
} else
memcpy ( & V_86 -> V_27 , V_89 , sizeof( T_1 ) ) ;
F_21 ( & V_86 -> V_27 , V_105 , & V_103 ) ;
V_36 = F_22 ( & V_103 , V_86 -> V_25 , & V_86 -> V_26 , & V_33 , 1 ) ;
if ( V_36 <= 0 || V_33 == 0 ) {
V_86 -> V_26 = NULL ;
#if F_58 ( 0 , 142 )
} else if ( V_33 == 1 && V_86 -> V_26 [ 0 ] . V_48 == V_106 &&
( V_86 -> V_107 != NULL || V_86 -> V_108 != NULL ) ) {
if ( ( F_59 ( V_86 -> V_107 , V_86 -> V_25 , & V_104 ) != 0 &&
( F_59 ( V_86 -> V_108 , V_86 -> V_25 , & V_104 ) != 0 ) ) ||
F_60 ( V_104 , & V_86 -> V_26 , & V_33 ) != 0 ) {
F_28 ( L_55 ,
( V_109 ) V_86 -> V_25 ) ;
free ( V_104 ) ;
return - V_10 ;
}
#endif
}
V_36 = V_86 -> V_110 ( V_89 , V_86 ) ;
free ( V_104 ) ;
V_86 -> V_26 = NULL ;
return V_36 ;
}
static int F_61 ( T_1 * V_111 , void * V_112 )
{
struct V_113 * V_114 = V_112 ;
const char * V_115 ;
int V_116 ;
if ( V_114 -> V_115 ) {
V_115 = F_62 ( V_111 ) ;
if ( ! V_115 || strcmp ( V_114 -> V_115 , V_115 ) != 0 )
return 0 ;
}
if ( V_114 -> V_94 ) {
if ( F_63 ( V_111 , V_114 -> V_94 ) ) {
memcpy ( V_114 -> V_79 , V_111 , sizeof( T_1 ) ) ;
V_114 -> V_47 = true ;
return 1 ;
}
} else {
F_64 ( V_111 , & V_116 ) ;
if ( V_116 < V_114 -> line && V_114 -> V_117 > V_114 -> line - V_116 ) {
V_114 -> V_117 = V_114 -> line - V_116 ;
memcpy ( V_114 -> V_79 , V_111 , sizeof( T_1 ) ) ;
V_114 -> V_47 = true ;
}
}
return 0 ;
}
static T_1 * F_65 ( struct V_85 * V_86 , T_1 * V_79 )
{
struct V_113 V_114 = {
. V_94 = V_86 -> V_118 -> V_119 . V_94 ,
. V_115 = V_86 -> V_120 ,
. line = V_86 -> V_116 ,
. V_117 = V_121 ,
. V_79 = V_79 ,
. V_47 = false ,
} ;
F_66 ( & V_86 -> V_91 , V_86 -> V_25 , F_61 , & V_114 ) ;
return V_114 . V_47 ? V_79 : NULL ;
}
static int F_67 ( const char * V_120 , int V_122 ,
T_2 V_25 , void * V_112 )
{
struct V_85 * V_86 = V_112 ;
T_1 * V_89 , V_79 ;
int V_36 ;
if ( V_122 != V_86 -> V_116 || F_68 ( V_120 , V_86 -> V_120 ) != 0 )
return 0 ;
V_86 -> V_25 = V_25 ;
V_89 = F_65 ( V_86 , & V_79 ) ;
if ( ! V_89 ) {
F_28 ( L_56 ) ;
return - V_10 ;
}
V_36 = F_54 ( V_89 , V_86 ) ;
return V_36 < 0 ? V_36 : 0 ;
}
static int F_69 ( struct V_85 * V_86 )
{
return F_70 ( & V_86 -> V_91 , F_67 , V_86 ) ;
}
static int F_71 ( struct V_123 * V_124 ,
const char * V_120 , const char * V_125 )
{
T_10 * V_126 ;
char * line = NULL ;
T_5 V_127 ;
T_11 V_128 ;
int V_129 = 0 , V_130 = 1 ;
char V_64 [ V_65 ] ;
V_126 = fopen ( V_120 , L_57 ) ;
if ( ! V_126 ) {
F_28 ( L_58 , V_120 ,
F_39 ( V_131 , V_64 , sizeof( V_64 ) ) ) ;
return - V_131 ;
}
while ( ( V_128 = F_72 ( & line , & V_127 , V_126 ) ) > 0 ) {
if ( line [ V_128 - 1 ] == '\n' )
line [ V_128 - 1 ] = '\0' ;
if ( F_73 ( line , V_125 ) ) {
F_74 ( V_124 , V_130 ) ;
V_129 ++ ;
}
V_130 ++ ;
}
if ( ferror ( V_126 ) )
V_129 = - V_131 ;
free ( line ) ;
fclose ( V_126 ) ;
if ( V_129 == 0 )
F_13 ( L_59 , V_120 ) ;
return V_129 ;
}
static int F_75 ( const char * V_120 , int V_122 ,
T_2 V_25 , void * V_112 )
{
struct V_85 * V_86 = V_112 ;
T_1 * V_89 , V_79 ;
int V_36 ;
if ( ! F_76 ( V_86 -> V_132 , V_122 ) ||
F_68 ( V_120 , V_86 -> V_120 ) != 0 )
return 0 ;
F_13 ( L_60 ,
V_122 , ( unsigned long long ) V_25 ) ;
V_86 -> V_25 = V_25 ;
V_86 -> V_116 = V_122 ;
V_89 = F_65 ( V_86 , & V_79 ) ;
if ( ! V_89 ) {
F_28 ( L_56 ) ;
return - V_10 ;
}
V_36 = F_54 ( V_89 , V_86 ) ;
return V_36 < 0 ? V_36 : 0 ;
}
static int F_77 ( T_1 * V_27 , struct V_85 * V_86 )
{
int V_36 = 0 ;
char * V_133 ;
if ( F_78 ( V_86 -> V_132 ) ) {
const char * V_134 ;
V_134 = F_79 ( & V_86 -> V_91 ) ;
V_36 = F_80 ( V_86 -> V_120 , V_134 , & V_133 ) ;
if ( V_36 < 0 ) {
F_28 ( L_61 ) ;
return V_36 ;
}
V_36 = F_71 ( V_86 -> V_132 , V_133 ,
V_86 -> V_118 -> V_119 . V_135 ) ;
free ( V_133 ) ;
if ( V_36 <= 0 )
return V_36 ;
}
return F_70 ( V_27 , F_75 , V_86 ) ;
}
static int F_81 ( T_1 * V_136 , void * V_112 )
{
struct V_85 * V_86 = V_112 ;
struct V_137 * V_138 = & V_86 -> V_118 -> V_119 ;
T_2 V_25 ;
int V_36 ;
if ( V_138 -> V_135 )
V_36 = F_77 ( V_136 , V_86 ) ;
else {
if ( F_23 ( V_136 , & V_25 ) != 0 ) {
F_28 ( L_62 ,
F_26 ( V_136 ) ) ;
return - V_10 ;
}
V_86 -> V_25 = V_25 ;
V_86 -> V_25 += V_138 -> V_23 ;
F_13 ( L_63 ,
( V_109 ) V_86 -> V_25 ) ;
V_36 = F_54 ( V_136 , V_86 ) ;
}
return V_36 ;
}
static int F_82 ( T_1 * V_27 , void * V_112 )
{
struct V_139 * V_140 = V_112 ;
struct V_85 * V_86 = V_140 -> V_112 ;
struct V_137 * V_138 = & V_86 -> V_118 -> V_119 ;
if ( ! F_55 ( V_27 ) ||
! F_63 ( V_27 , V_138 -> V_94 ) )
return V_141 ;
if ( V_138 -> V_115 && F_68 ( V_138 -> V_115 , F_62 ( V_27 ) ) )
return V_141 ;
F_13 ( L_64 , F_26 ( V_27 ) ) ;
V_86 -> V_120 = F_62 ( V_27 ) ;
if ( V_138 -> line ) {
F_64 ( V_27 , & V_86 -> V_116 ) ;
V_86 -> V_116 += V_138 -> line ;
V_140 -> V_142 = F_69 ( V_86 ) ;
} else if ( F_83 ( V_27 ) ) {
F_23 ( V_27 , & V_86 -> V_25 ) ;
if ( V_138 -> V_135 )
V_140 -> V_142 = F_77 ( V_27 , V_86 ) ;
else {
V_86 -> V_25 += V_138 -> V_23 ;
V_140 -> V_142 = F_54 ( V_27 , V_86 ) ;
}
} else if ( ! V_42 . V_143 ) {
V_140 -> V_142 = F_84 ( V_27 ,
F_81 , ( void * ) V_86 ) ;
if ( V_140 -> V_142 == - V_10 && F_85 ( V_138 -> V_94 ) )
V_140 -> V_142 = 0 ;
}
if ( F_85 ( V_138 -> V_94 ) && V_140 -> V_142 >= 0 ) {
V_140 -> V_142 = 0 ;
return V_141 ;
}
return V_144 ;
}
static int F_86 ( struct V_85 * V_86 )
{
struct V_139 V_145 = { . V_112 = ( void * ) V_86 ,
. V_142 = 0 } ;
F_87 ( & V_86 -> V_91 , F_82 , & V_145 , 0 ) ;
return V_145 . V_142 ;
}
static int F_88 ( T_12 * V_2 , T_13 * V_146 , void * V_112 )
{
struct V_147 * V_140 = V_112 ;
if ( F_89 ( V_2 , V_146 -> V_148 , V_140 -> V_27 ) ) {
if ( F_24 ( V_140 -> V_27 ) != V_149 )
return V_141 ;
if ( F_63 ( V_140 -> V_27 , V_140 -> V_94 ) ) {
if ( ! F_89 ( V_2 , V_146 -> V_150 , V_140 -> V_91 ) )
return V_141 ;
if ( V_140 -> V_115 &&
F_68 ( V_140 -> V_115 , F_62 ( V_140 -> V_27 ) ) )
return V_141 ;
V_140 -> V_47 = 1 ;
return V_144 ;
}
}
return V_141 ;
}
static int F_90 ( struct V_1 * V_2 ,
struct V_85 * V_86 )
{
struct V_137 * V_138 = & V_86 -> V_118 -> V_119 ;
T_14 V_151 , V_152 ;
T_5 V_153 ;
T_1 * V_154 ;
int V_36 = 0 ;
V_151 = 0 ;
V_86 -> V_132 = F_91 ( NULL ) ;
if ( ! V_86 -> V_132 )
return - V_51 ;
if ( V_138 -> V_94 && ! F_85 ( V_138 -> V_94 ) ) {
struct V_147 V_155 = {
. V_94 = V_138 -> V_94 ,
. V_115 = V_138 -> V_115 ,
. V_91 = & V_86 -> V_91 ,
. V_27 = & V_86 -> V_27 ,
. V_47 = 0 ,
} ;
struct V_139 V_156 = {
. V_112 = V_86 ,
} ;
F_92 ( V_2 -> V_2 , F_88 ,
& V_155 , 0 ) ;
if ( V_155 . V_47 ) {
V_36 = F_82 ( & V_86 -> V_27 , & V_156 ) ;
if ( V_36 )
goto V_47;
}
}
while ( ! F_93 ( V_2 -> V_2 , V_151 , & V_152 , & V_153 , NULL , NULL , NULL ) ) {
V_154 = F_89 ( V_2 -> V_2 , V_151 + V_153 , & V_86 -> V_91 ) ;
if ( ! V_154 )
continue;
if ( V_138 -> V_115 )
V_86 -> V_120 = F_94 ( & V_86 -> V_91 , V_138 -> V_115 ) ;
else
V_86 -> V_120 = NULL ;
if ( ! V_138 -> V_115 || V_86 -> V_120 ) {
if ( V_138 -> V_94 )
V_36 = F_86 ( V_86 ) ;
else if ( V_138 -> V_135 )
V_36 = F_77 ( & V_86 -> V_91 , V_86 ) ;
else {
V_86 -> V_116 = V_138 -> line ;
V_36 = F_69 ( V_86 ) ;
}
if ( V_36 < 0 )
break;
}
V_151 = V_152 ;
}
V_47:
F_95 ( V_86 -> V_132 ) ;
V_86 -> V_132 = NULL ;
return V_36 ;
}
static int F_96 ( struct V_1 * V_2 ,
struct V_85 * V_86 )
{
int V_36 = 0 ;
#if F_58 ( 0 , 142 )
T_15 * V_157 ;
T_16 V_158 ;
T_17 V_159 ;
if ( V_86 -> V_107 || V_86 -> V_108 )
return F_90 ( V_2 , V_86 ) ;
V_157 = F_97 ( V_2 -> V_2 ) ;
if ( V_157 == NULL )
return - V_41 ;
if ( F_98 ( V_157 , & V_158 ) == NULL )
return - V_41 ;
if ( F_99 ( V_157 , & V_158 , & V_159 , L_65 , NULL ) &&
V_159 . V_160 == V_161 )
V_86 -> V_107 = F_100 ( V_157 ) ;
V_86 -> V_108 = F_101 ( V_2 -> V_2 ) ;
#endif
V_36 = F_90 ( V_2 , V_86 ) ;
return V_36 ;
}
static int F_102 ( T_1 * V_79 , void * V_112 )
{
struct V_162 * V_163 = V_112 ;
struct V_85 * V_86 = V_163 -> V_86 ;
int V_80 ;
V_80 = F_24 ( V_79 ) ;
if ( V_80 == V_46 ||
( V_80 == V_44 && V_163 -> V_164 ) ) {
if ( F_20 ( V_79 , V_163 -> V_86 -> V_25 ,
V_163 -> V_86 -> V_26 , & V_86 -> V_27 ,
NULL ) == 0 ) {
V_163 -> args [ V_163 -> V_165 ] . V_88 = ( char * ) F_26 ( V_79 ) ;
if ( V_163 -> args [ V_163 -> V_165 ] . V_88 == NULL ) {
V_163 -> V_36 = - V_51 ;
return V_166 ;
}
F_13 ( L_66 , V_163 -> args [ V_163 -> V_165 ] . V_88 ) ;
V_163 -> V_165 ++ ;
}
}
if ( F_103 ( V_79 , V_163 -> V_86 -> V_25 ) )
return V_167 ;
else
return V_168 ;
}
static int F_104 ( T_1 * V_89 , struct V_85 * V_86 ,
struct V_169 * args )
{
T_1 V_79 ;
int V_170 ;
int V_171 = 0 ;
struct V_162 V_163 = { . V_86 = V_86 , . args = args , . V_164 = false ,
. V_172 = V_173 , . V_36 = 0 } ;
for ( V_170 = 0 ; V_170 < V_86 -> V_118 -> V_165 ; V_170 ++ ) {
if ( strcmp ( V_86 -> V_118 -> args [ V_170 ] . V_88 , V_174 ) == 0 )
V_163 . V_164 = true ;
else if ( strcmp ( V_86 -> V_118 -> args [ V_170 ] . V_88 , V_175 ) != 0 ) {
args [ V_171 ] = V_86 -> V_118 -> args [ V_170 ] ;
V_171 ++ ;
continue;
}
F_13 ( L_67 , V_86 -> V_118 -> args [ V_170 ] . V_88 ) ;
V_163 . V_165 = V_171 ;
F_105 ( V_89 , F_102 , ( void * ) & V_163 ,
& V_79 ) ;
F_13 ( L_68 , V_163 . V_165 - V_171 ) ;
if ( V_163 . V_36 < 0 )
return V_163 . V_36 ;
V_171 = V_163 . V_165 ;
}
return V_171 ;
}
static int F_106 ( T_1 * V_89 , struct V_85 * V_86 )
{
struct V_176 * V_177 =
F_107 ( V_86 , struct V_176 , V_86 ) ;
struct V_137 * V_138 = & V_86 -> V_118 -> V_119 ;
struct V_178 * V_179 ;
struct V_169 * args = NULL ;
int V_36 , V_170 ;
if ( V_177 -> V_180 == V_177 -> V_181 ) {
F_28 ( L_69 ,
V_177 -> V_181 ) ;
return - V_45 ;
}
V_179 = & V_177 -> V_182 [ V_177 -> V_180 ++ ] ;
V_36 = F_52 ( & V_86 -> V_27 , V_177 -> V_8 , V_86 -> V_25 ,
V_138 -> V_93 , V_138 -> V_94 , & V_179 -> V_119 ) ;
if ( V_36 < 0 )
goto V_183;
V_179 -> V_119 . V_184 = F_29 ( F_26 ( V_89 ) ) ;
if ( ! V_179 -> V_119 . V_184 ) {
V_36 = - V_51 ;
goto V_183;
}
F_13 ( L_70 , V_179 -> V_119 . V_100 ,
V_179 -> V_119 . V_23 ) ;
args = F_11 ( sizeof( struct V_169 ) * V_173 ) ;
if ( args == NULL ) {
V_36 = - V_51 ;
goto V_183;
}
V_36 = F_104 ( V_89 , V_86 , args ) ;
if ( V_36 < 0 )
goto V_183;
V_179 -> V_165 = V_36 ;
V_179 -> args = F_11 ( sizeof( struct V_28 ) * V_179 -> V_165 ) ;
if ( V_179 -> args == NULL ) {
V_36 = - V_51 ;
goto V_183;
}
for ( V_170 = 0 ; V_170 < V_179 -> V_165 ; V_170 ++ ) {
V_86 -> V_87 = & args [ V_170 ] ;
V_86 -> V_29 = & V_179 -> args [ V_170 ] ;
V_36 = F_47 ( V_89 , V_86 ) ;
if ( V_36 != 0 )
break;
}
V_183:
if ( V_36 ) {
F_108 ( V_179 ) ;
V_177 -> V_180 -- ;
}
free ( args ) ;
return V_36 ;
}
int F_109 ( struct V_1 * V_2 ,
struct V_185 * V_118 ,
struct V_178 * * V_182 )
{
struct V_176 V_177 = {
. V_86 = { . V_118 = V_118 , . V_110 = F_106 } ,
. V_181 = V_42 . V_186 , . V_8 = V_2 -> V_8 } ;
int V_36 , V_170 ;
* V_182 = F_11 ( sizeof( struct V_178 ) * V_177 . V_181 ) ;
if ( * V_182 == NULL )
return - V_51 ;
V_177 . V_182 = * V_182 ;
V_177 . V_180 = 0 ;
V_36 = F_96 ( V_2 , & V_177 . V_86 ) ;
if ( V_36 < 0 ) {
for ( V_170 = 0 ; V_170 < V_177 . V_180 ; V_170 ++ )
F_108 ( & V_177 . V_182 [ V_170 ] ) ;
F_12 ( V_182 ) ;
return V_36 ;
}
return ( V_36 < 0 ) ? V_36 : V_177 . V_180 ;
}
static int F_110 ( T_1 * V_79 , void * V_112 )
{
struct V_187 * V_188 = V_112 ;
struct V_189 * V_190 ;
struct V_191 V_12 = V_192 ;
int V_80 , V_36 ;
V_190 = & V_188 -> V_193 [ V_188 -> V_194 - 1 ] ;
V_80 = F_24 ( V_79 ) ;
if ( V_80 == V_46 ||
V_80 == V_44 ) {
V_36 = F_20 ( V_79 , V_188 -> V_86 . V_25 ,
V_188 -> V_86 . V_26 , & V_188 -> V_86 . V_27 ,
NULL ) ;
if ( V_36 == 0 || V_36 == - V_45 ) {
int V_37 ;
bool V_195 = ! V_188 -> V_196 ;
if ( F_111 ( & V_12 , 64 ) < 0 )
goto error;
if ( V_42 . V_43 ) {
if ( ! V_195 )
V_37 = F_112 ( & V_12 ,
V_36 ? L_71 : L_72 , 6 ) ;
else
V_37 = F_112 ( & V_12 , L_73 , 6 ) ;
if ( V_37 )
goto error;
}
V_37 = F_113 ( V_79 , & V_12 ) ;
if ( ! V_37 && V_42 . V_43 &&
! V_195 ) {
if ( F_114 ( & V_12 , '\t' ) < 0 )
goto error;
V_37 = F_115 ( & V_188 -> V_86 . V_27 ,
V_79 , & V_12 ) ;
}
F_13 ( L_74 , V_12 . V_12 ) ;
if ( V_37 == 0 ) {
F_116 ( V_190 -> V_164 ,
F_117 ( & V_12 , NULL ) ) ;
}
F_118 ( & V_12 ) ;
}
}
if ( V_188 -> V_196 && F_103 ( V_79 , V_188 -> V_86 . V_25 ) )
return V_167 ;
else
return V_168 ;
error:
F_118 ( & V_12 ) ;
F_13 ( L_75 ) ;
return V_166 ;
}
static int F_119 ( T_1 * V_89 , struct V_85 * V_86 )
{
struct V_187 * V_188 =
F_107 ( V_86 , struct V_187 , V_86 ) ;
struct V_137 * V_138 = & V_86 -> V_118 -> V_119 ;
struct V_189 * V_190 ;
T_1 V_79 ;
int V_36 ;
if ( V_188 -> V_194 == V_188 -> V_197 ) {
F_28 ( L_69 , V_188 -> V_197 ) ;
return - V_45 ;
}
V_190 = & V_188 -> V_193 [ V_188 -> V_194 ++ ] ;
V_36 = F_52 ( & V_86 -> V_27 , V_188 -> V_8 , V_86 -> V_25 ,
V_138 -> V_93 , V_138 -> V_94 , & V_190 -> V_119 ) ;
if ( V_36 < 0 )
return V_36 ;
F_13 ( L_70 , V_190 -> V_119 . V_100 ,
V_190 -> V_119 . V_23 ) ;
V_190 -> V_164 = F_120 ( NULL , NULL ) ;
if ( V_190 -> V_164 == NULL )
return - V_51 ;
V_188 -> V_196 = true ;
F_105 ( V_89 , F_110 , ( void * ) V_188 , & V_79 ) ;
if ( ! V_42 . V_198 )
goto V_17;
V_188 -> V_196 = false ;
F_105 ( & V_86 -> V_91 , F_110 , ( void * ) V_188 , & V_79 ) ;
V_17:
if ( F_121 ( V_190 -> V_164 ) ) {
F_122 ( V_190 -> V_164 ) ;
V_190 -> V_164 = NULL ;
}
return V_36 ;
}
int F_123 ( struct V_1 * V_2 ,
struct V_185 * V_118 ,
struct V_189 * * V_193 )
{
struct V_187 V_188 = {
. V_86 = { . V_118 = V_118 , . V_110 = F_119 } ,
. V_8 = V_2 -> V_8 ,
. V_197 = V_42 . V_186 } ;
int V_36 ;
* V_193 = F_11 ( sizeof( struct V_189 ) * V_188 . V_197 ) ;
if ( * V_193 == NULL )
return - V_51 ;
V_188 . V_193 = * V_193 ;
V_188 . V_194 = 0 ;
V_36 = F_96 ( V_2 , & V_188 . V_86 ) ;
if ( V_36 < 0 ) {
while ( V_188 . V_194 -- ) {
F_12 ( & V_188 . V_193 [ V_188 . V_194 ] . V_119 . V_100 ) ;
F_122 ( V_188 . V_193 [ V_188 . V_194 ] . V_164 ) ;
}
F_12 ( V_193 ) ;
return V_36 ;
}
return ( V_36 < 0 ) ? V_36 : V_188 . V_194 ;
}
static int F_124 ( struct V_1 * V_2 , T_2 * V_21 )
{
int V_171 , V_170 ;
T_18 V_199 ;
T_19 * V_200 ;
T_15 * V_157 ;
T_17 V_201 , * V_159 ;
const char * V_202 ;
V_157 = F_125 ( V_2 -> V_8 , & V_2 -> V_9 ) ;
if ( ! V_157 )
return - V_41 ;
V_171 = F_126 ( V_2 -> V_8 ) ;
if ( V_171 < 0 )
return - V_10 ;
for ( V_170 = 0 ; V_170 < V_171 ; V_170 ++ ) {
V_202 = F_127 ( V_2 -> V_8 , V_170 , & V_199 ) ;
if ( strcmp ( V_202 , L_76 ) == 0 ) {
V_200 = F_128 ( V_157 , V_199 ) ;
if ( ! V_200 )
return - V_10 ;
V_159 = F_129 ( V_200 , & V_201 ) ;
if ( ! V_159 )
return - V_10 ;
* V_21 = V_159 -> V_203 ;
}
}
return 0 ;
}
int F_130 ( struct V_1 * V_2 , unsigned long V_25 ,
struct V_137 * V_204 )
{
T_1 V_205 , V_206 , V_207 ;
T_2 V_208 = 0 , V_209 = 0 ;
const char * V_120 = NULL , * V_210 = NULL , * V_211 = NULL , * V_31 ;
int V_212 = 0 , V_122 = 0 , V_36 = 0 ;
bool V_213 = false ;
V_214:
if ( ! F_131 ( V_2 -> V_2 , ( T_2 ) V_25 , & V_205 ) ) {
if ( ! V_213 && F_124 ( V_2 , & V_209 ) == 0 ) {
V_25 += V_209 ;
V_213 = true ;
goto V_214;
}
F_28 ( L_77 ,
V_25 ) ;
V_36 = - V_41 ;
goto V_183;
}
F_132 ( & V_205 , V_25 , & V_120 , & V_122 ) ;
if ( F_56 ( & V_205 , ( T_2 ) V_25 , & V_206 ) ) {
V_210 = V_211 = F_26 ( & V_206 ) ;
if ( ! V_210 ||
F_23 ( & V_206 , & V_209 ) != 0 ||
F_64 ( & V_206 , & V_212 ) != 0 ) {
V_122 = 0 ;
goto V_215;
}
V_120 = F_62 ( & V_206 ) ;
if ( V_25 == ( unsigned long ) V_209 ) {
V_122 = V_212 ;
goto V_215;
}
while ( F_133 ( & V_206 , ( T_2 ) V_25 ,
& V_207 ) ) {
if ( F_23 ( & V_207 , & V_208 ) == 0 &&
V_208 == V_25 ) {
V_122 = F_134 ( & V_207 ) ;
V_120 = F_135 ( & V_207 ) ;
break;
} else {
V_31 = F_26 ( & V_207 ) ;
if ( ! V_31 ||
F_64 ( & V_207 , & V_212 ) != 0 )
break;
V_210 = V_31 ;
V_206 = V_207 ;
}
}
V_31 = F_62 ( & V_206 ) ;
if ( ! V_31 || strcmp ( V_31 , V_120 ) != 0 )
V_122 = 0 ;
}
V_215:
if ( V_122 )
V_204 -> line = V_122 - V_212 ;
else if ( V_211 ) {
V_204 -> V_23 = V_25 - ( unsigned long ) V_209 ;
V_210 = V_211 ;
}
if ( V_210 ) {
V_204 -> V_94 = F_29 ( V_210 ) ;
if ( V_204 -> V_94 == NULL ) {
V_36 = - V_51 ;
goto V_183;
}
}
if ( V_120 ) {
V_204 -> V_115 = F_29 ( V_120 ) ;
if ( V_204 -> V_115 == NULL ) {
F_12 ( & V_204 -> V_94 ) ;
V_36 = - V_51 ;
goto V_183;
}
}
V_183:
if ( V_36 == 0 && ( V_120 || V_210 ) )
V_36 = 1 ;
return V_36 ;
}
static int F_136 ( const char * V_216 , unsigned int V_122 ,
struct V_217 * V_218 )
{
if ( ! V_218 -> V_3 ) {
V_218 -> V_3 = F_29 ( V_216 ) ;
if ( V_218 -> V_3 == NULL )
return - V_51 ;
}
return F_74 ( V_218 -> V_219 , V_122 ) ;
}
static int F_137 ( const char * V_120 , int V_122 ,
T_2 V_25 V_220 ,
void * V_112 )
{
struct V_221 * V_222 = V_112 ;
int V_223 ;
if ( ( F_68 ( V_120 , V_222 -> V_120 ) != 0 ) ||
( V_222 -> V_224 > V_122 || V_222 -> V_225 < V_122 ) )
return 0 ;
V_223 = F_136 ( V_120 , V_122 , V_222 -> V_218 ) ;
if ( V_223 < 0 && V_223 != - V_226 )
return V_223 ;
return 0 ;
}
static int F_138 ( T_1 * V_27 , struct V_221 * V_222 )
{
int V_36 ;
V_36 = F_70 ( V_27 ? : & V_222 -> V_91 , F_137 , V_222 ) ;
if ( V_36 >= 0 )
if ( ! F_78 ( V_222 -> V_218 -> V_219 ) )
V_36 = V_222 -> V_47 = 1 ;
else
V_36 = 0 ;
else {
F_12 ( & V_222 -> V_218 -> V_3 ) ;
}
return V_36 ;
}
static int F_139 ( T_1 * V_136 , void * V_112 )
{
int V_36 = F_138 ( V_136 , V_112 ) ;
return V_36 < 0 ? V_36 : 0 ;
}
static int F_140 ( T_1 * V_27 , void * V_112 )
{
struct V_139 * V_140 = V_112 ;
struct V_221 * V_222 = V_140 -> V_112 ;
struct V_217 * V_218 = V_222 -> V_218 ;
if ( V_218 -> V_115 && F_68 ( V_218 -> V_115 , F_62 ( V_27 ) ) )
return V_141 ;
if ( F_55 ( V_27 ) &&
F_63 ( V_27 , V_218 -> V_94 ) ) {
V_222 -> V_120 = F_62 ( V_27 ) ;
F_64 ( V_27 , & V_218 -> V_23 ) ;
F_13 ( L_78 , V_222 -> V_120 , V_218 -> V_23 ) ;
V_222 -> V_224 = V_218 -> V_23 + V_218 -> V_227 ;
if ( V_222 -> V_224 < 0 )
V_222 -> V_224 = V_121 ;
V_222 -> V_225 = V_218 -> V_23 + V_218 -> V_183 ;
if ( V_222 -> V_225 < 0 )
V_222 -> V_225 = V_121 ;
F_13 ( L_79 , V_222 -> V_224 , V_222 -> V_225 ) ;
V_218 -> V_227 = V_222 -> V_224 ;
V_218 -> V_183 = V_222 -> V_225 ;
if ( ! F_83 ( V_27 ) )
V_140 -> V_142 = F_84 ( V_27 ,
F_139 , V_222 ) ;
else
V_140 -> V_142 = F_138 ( V_27 , V_222 ) ;
return V_144 ;
}
return V_141 ;
}
static int F_141 ( struct V_221 * V_222 )
{
struct V_139 V_140 = { . V_112 = ( void * ) V_222 , . V_142 = 0 } ;
F_87 ( & V_222 -> V_91 , F_140 , & V_140 , 0 ) ;
return V_140 . V_142 ;
}
int F_142 ( struct V_1 * V_2 , struct V_217 * V_218 )
{
struct V_221 V_222 = { . V_218 = V_218 , . V_47 = 0 } ;
int V_36 = 0 ;
T_14 V_151 = 0 , V_152 ;
T_5 V_153 ;
T_1 * V_154 ;
const char * V_134 ;
if ( V_218 -> V_94 ) {
struct V_147 V_155 = {
. V_94 = V_218 -> V_94 , . V_115 = V_218 -> V_115 ,
. V_91 = & V_222 . V_91 , . V_27 = & V_222 . V_27 , . V_47 = 0 } ;
struct V_139 V_228 = {
. V_112 = ( void * ) & V_222 , . V_142 = 0 } ;
F_92 ( V_2 -> V_2 , F_88 ,
& V_155 , 0 ) ;
if ( V_155 . V_47 ) {
F_140 ( & V_222 . V_27 , & V_228 ) ;
if ( V_222 . V_47 )
goto V_47;
}
}
while ( ! V_222 . V_47 && V_36 >= 0 ) {
if ( F_93 ( V_2 -> V_2 , V_151 , & V_152 , & V_153 ,
NULL , NULL , NULL ) != 0 )
break;
V_154 = F_89 ( V_2 -> V_2 , V_151 + V_153 , & V_222 . V_91 ) ;
if ( ! V_154 )
continue;
if ( V_218 -> V_115 )
V_222 . V_120 = F_94 ( & V_222 . V_91 , V_218 -> V_115 ) ;
else
V_222 . V_120 = 0 ;
if ( ! V_218 -> V_115 || V_222 . V_120 ) {
if ( V_218 -> V_94 )
V_36 = F_141 ( & V_222 ) ;
else {
V_222 . V_224 = V_218 -> V_227 ;
V_222 . V_225 = V_218 -> V_183 ;
V_36 = F_138 ( NULL , & V_222 ) ;
}
}
V_151 = V_152 ;
}
V_47:
if ( V_222 . V_47 ) {
V_134 = F_79 ( & V_222 . V_91 ) ;
if ( V_134 ) {
V_218 -> V_134 = F_29 ( V_134 ) ;
if ( ! V_218 -> V_134 )
V_36 = - V_51 ;
}
}
F_13 ( L_80 , V_218 -> V_3 ) ;
return ( V_36 < 0 ) ? V_36 : V_222 . V_47 ;
}
int F_80 ( const char * V_229 , const char * V_134 ,
char * * V_230 )
{
const char * V_231 = V_232 . V_233 ;
if ( ! V_231 ) {
if ( V_229 [ 0 ] != '/' && V_134 )
V_231 = V_134 ;
else {
if ( F_143 ( V_229 , V_234 ) == 0 ) {
* V_230 = F_29 ( V_229 ) ;
return * V_230 ? 0 : - V_51 ;
} else
return - V_131 ;
}
}
* V_230 = malloc ( ( strlen ( V_231 ) + strlen ( V_229 ) + 2 ) ) ;
if ( ! * V_230 )
return - V_51 ;
for (; ; ) {
sprintf ( * V_230 , L_81 , V_231 , V_229 ) ;
if ( F_143 ( * V_230 , V_234 ) == 0 )
return 0 ;
if ( ! V_232 . V_233 ) {
F_12 ( V_230 ) ;
return - V_131 ;
}
switch ( V_131 ) {
case V_235 :
case V_10 :
case V_236 :
case V_237 :
V_229 = strchr ( ++ V_229 , '/' ) ;
if ( ! V_229 ) {
F_12 ( V_230 ) ;
return - V_10 ;
}
continue;
default:
F_12 ( V_230 ) ;
return - V_131 ;
}
}
}
