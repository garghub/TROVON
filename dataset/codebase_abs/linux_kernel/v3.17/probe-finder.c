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
V_2 -> V_8 = F_4 ( V_2 -> V_6 , L_1 , L_1 , V_4 ) ;
if ( ! V_2 -> V_8 )
goto error;
V_2 -> V_2 = F_5 ( V_2 -> V_8 , & V_2 -> V_9 ) ;
if ( ! V_2 -> V_2 )
goto error;
return 0 ;
error:
if ( V_2 -> V_6 )
F_6 ( V_2 -> V_6 ) ;
else
F_7 ( V_4 ) ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
return - V_10 ;
}
static struct V_1 * F_8 ( const char * V_3 )
{
struct V_1 * V_2 = F_9 ( sizeof( * V_2 ) ) ;
if ( ! V_2 )
return NULL ;
if ( F_1 ( V_2 , V_3 ) < 0 )
F_10 ( & V_2 ) ;
if ( V_2 )
F_11 ( L_2 , V_3 ) ;
return V_2 ;
}
struct V_1 * F_12 ( const char * V_3 )
{
enum V_11 * type ;
char V_12 [ V_13 ] , V_14 = '\0' ;
struct V_15 * V_15 ;
struct V_1 * V_16 = NULL ;
V_15 = F_13 ( V_3 ) ;
if ( ! V_15 )
goto V_17;
for ( type = V_18 ;
! V_16 && * type != V_19 ;
type ++ ) {
if ( F_14 ( V_15 , * type , & V_14 ,
V_12 , V_13 ) < 0 )
continue;
V_16 = F_8 ( V_12 ) ;
}
F_15 ( V_15 ) ;
V_17:
return V_16 ? : F_8 ( V_3 ) ;
}
void F_16 ( struct V_1 * V_2 )
{
if ( V_2 ) {
if ( V_2 -> V_6 )
F_6 ( V_2 -> V_6 ) ;
free ( V_2 ) ;
}
}
static struct V_20 * F_17 ( long V_21 )
{
struct V_20 * V_22 ;
V_22 = F_9 ( sizeof( struct V_20 ) ) ;
if ( V_22 != NULL )
V_22 -> V_23 = V_21 ;
return V_22 ;
}
static int F_18 ( T_1 * V_24 , T_2 V_25 ,
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
int V_36 ;
if ( F_19 ( V_24 , V_37 , & V_30 ) != NULL )
goto V_38;
if ( F_19 ( V_24 , V_39 , & V_30 ) == NULL )
return - V_40 ;
if ( F_20 ( & V_30 , V_25 , & V_32 , & V_33 , 1 ) <= 0 ) {
V_36 = F_21 ( V_27 , & V_31 ) ;
if ( V_36 || V_25 != V_31 ||
F_22 ( V_24 ) != V_41 ||
F_23 ( V_27 , & V_31 ) )
return - V_10 ;
for ( V_25 += 1 ; V_25 <= V_31 ; V_25 ++ ) {
if ( F_20 ( & V_30 , V_25 , & V_32 ,
& V_33 , 1 ) > 0 )
goto V_42;
}
return - V_10 ;
}
V_42:
if ( V_33 == 0 )
return - V_10 ;
if ( V_32 -> V_43 == V_44 ) {
V_38:
if ( ! V_29 )
return 0 ;
V_36 = strlen ( F_24 ( V_24 ) ) ;
V_29 -> V_45 = F_9 ( V_36 + 2 ) ;
if ( V_29 -> V_45 == NULL )
return - V_46 ;
snprintf ( V_29 -> V_45 , V_36 + 2 , L_3 , F_24 ( V_24 ) ) ;
V_29 -> V_22 = F_17 ( ( long ) V_21 ) ;
if ( V_29 -> V_22 == NULL )
return - V_46 ;
return 0 ;
}
if ( V_32 -> V_43 == V_47 ) {
if ( V_26 == NULL )
return - V_48 ;
V_22 = true ;
V_21 = V_32 -> V_49 ;
V_32 = & V_26 [ 0 ] ;
}
if ( V_32 -> V_43 >= V_50 && V_32 -> V_43 <= V_51 ) {
V_34 = V_32 -> V_43 - V_50 ;
V_21 += V_32 -> V_49 ;
V_22 = true ;
} else if ( V_32 -> V_43 >= V_52 && V_32 -> V_43 <= V_53 ) {
V_34 = V_32 -> V_43 - V_52 ;
} else if ( V_32 -> V_43 == V_54 ) {
V_34 = V_32 -> V_49 ;
V_21 += V_32 -> V_55 ;
V_22 = true ;
} else if ( V_32 -> V_43 == V_56 ) {
V_34 = V_32 -> V_49 ;
} else {
F_11 ( L_4 , V_32 -> V_43 ) ;
return - V_48 ;
}
if ( ! V_29 )
return 0 ;
V_35 = F_25 ( V_34 ) ;
if ( ! V_35 ) {
F_26 ( L_5
L_6 , V_34 ) ;
return - V_57 ;
}
V_29 -> V_45 = F_27 ( V_35 ) ;
if ( V_29 -> V_45 == NULL )
return - V_46 ;
if ( V_22 ) {
V_29 -> V_22 = F_17 ( ( long ) V_21 ) ;
if ( V_29 -> V_22 == NULL )
return - V_46 ;
}
return 0 ;
}
static int F_28 ( T_1 * V_24 ,
struct V_28 * V_29 ,
const char * V_58 )
{
struct V_20 * * V_59 = & V_29 -> V_22 ;
T_1 type ;
char V_12 [ 16 ] ;
int V_60 , V_61 , V_62 ;
int V_36 ;
if ( V_58 && strcmp ( V_58 , L_7 ) != 0 ) {
V_29 -> type = F_27 ( V_58 ) ;
return ( V_29 -> type == NULL ) ? - V_46 : 0 ;
}
V_60 = F_29 ( V_24 ) ;
if ( V_60 > 0 ) {
V_61 = F_30 ( V_24 ) ;
V_62 = F_31 ( V_24 ) ;
if ( V_61 < 0 || V_62 < 0 )
return - V_10 ;
V_36 = snprintf ( V_12 , 16 , L_8 , V_60 , V_61 ,
F_32 ( V_62 ) ) ;
goto V_63;
}
if ( F_33 ( V_24 , & type ) == NULL ) {
F_26 ( L_9 ,
F_24 ( V_24 ) ) ;
return - V_10 ;
}
F_11 ( L_10 ,
F_24 ( V_24 ) , F_24 ( & type ) ) ;
if ( V_58 && strcmp ( V_58 , L_7 ) == 0 ) {
V_36 = F_22 ( & type ) ;
if ( V_36 != V_64 &&
V_36 != V_65 ) {
F_26 ( L_11
L_12 ,
F_24 ( V_24 ) , F_24 ( & type ) ) ;
return - V_40 ;
}
if ( F_33 ( & type , & type ) == NULL ) {
F_26 ( L_13
L_14 ) ;
return - V_10 ;
}
if ( V_36 == V_64 ) {
while ( * V_59 )
V_59 = & ( * V_59 ) -> V_66 ;
* V_59 = F_9 ( sizeof( struct V_20 ) ) ;
if ( * V_59 == NULL ) {
F_26 ( L_15 ) ;
return - V_46 ;
}
}
if ( ! F_34 ( & type , L_16 ) &&
! F_34 ( & type , L_17 ) ) {
F_26 ( L_11
L_18 ,
F_24 ( V_24 ) ) ;
return - V_40 ;
}
V_29 -> type = F_27 ( V_58 ) ;
return ( V_29 -> type == NULL ) ? - V_46 : 0 ;
}
V_36 = F_31 ( & type ) ;
if ( V_36 <= 0 )
return 0 ;
V_36 = F_32 ( V_36 ) ;
if ( V_36 > V_67 ) {
F_35 ( L_19 ,
F_24 ( & type ) , V_67 ) ;
V_36 = V_67 ;
}
V_36 = snprintf ( V_12 , 16 , L_20 ,
F_36 ( & type ) ? 's' : 'u' , V_36 ) ;
V_63:
if ( V_36 < 0 || V_36 >= 16 ) {
if ( V_36 >= 16 )
V_36 = - V_68 ;
F_26 ( L_21 ,
strerror ( - V_36 ) ) ;
return V_36 ;
}
V_29 -> type = F_27 ( V_12 ) ;
if ( V_29 -> type == NULL )
return - V_46 ;
return 0 ;
}
static int F_37 ( T_1 * V_24 , const char * V_69 ,
struct V_70 * V_71 ,
struct V_20 * * V_59 ,
T_1 * V_72 )
{
struct V_20 * V_22 = * V_59 ;
T_1 type ;
T_6 V_21 ;
int V_36 , V_73 ;
F_11 ( L_22 , V_71 -> V_74 , V_69 ) ;
if ( F_33 ( V_24 , & type ) == NULL ) {
F_26 ( L_23 , V_69 ) ;
return - V_10 ;
}
F_38 ( L_24 , ( unsigned ) F_39 ( & type ) ) ;
V_73 = F_22 ( & type ) ;
if ( V_71 -> V_74 [ 0 ] == '[' &&
( V_73 == V_65 || V_73 == V_64 ) ) {
if ( V_71 -> V_66 )
memcpy ( V_72 , & type , sizeof( * V_72 ) ) ;
if ( F_33 ( & type , & type ) == NULL ) {
F_26 ( L_23 , V_69 ) ;
return - V_10 ;
}
F_38 ( L_25 ,
( unsigned ) F_39 ( & type ) ) ;
if ( V_73 == V_64 ) {
V_22 = F_9 ( sizeof( struct V_20 ) ) ;
if ( V_22 == NULL )
return - V_46 ;
if ( * V_59 )
( * V_59 ) -> V_66 = V_22 ;
else
* V_59 = V_22 ;
}
V_22 -> V_23 += F_31 ( & type ) * V_71 -> V_75 ;
if ( ! V_71 -> V_66 )
memcpy ( V_72 , V_24 , sizeof( * V_72 ) ) ;
goto V_66;
} else if ( V_73 == V_64 ) {
if ( ! V_71 -> V_22 ) {
F_40 ( L_26 ,
V_71 -> V_74 ) ;
return - V_40 ;
}
if ( F_33 ( & type , & type ) == NULL ) {
F_26 ( L_23 , V_69 ) ;
return - V_10 ;
}
V_73 = F_22 ( & type ) ;
if ( V_73 != V_76 && V_73 != V_77 ) {
F_26 ( L_27 ,
V_69 ) ;
return - V_40 ;
}
V_22 = F_9 ( sizeof( struct V_20 ) ) ;
if ( V_22 == NULL )
return - V_46 ;
if ( * V_59 )
( * V_59 ) -> V_66 = V_22 ;
else
* V_59 = V_22 ;
} else {
if ( V_73 != V_76 && V_73 != V_77 ) {
F_26 ( L_27 ,
V_69 ) ;
return - V_40 ;
}
if ( V_71 -> V_74 [ 0 ] == '[' ) {
F_40 ( L_28
L_29 , V_69 ) ;
return - V_40 ;
}
if ( V_71 -> V_22 ) {
F_40 ( L_30 ,
V_71 -> V_74 ) ;
return - V_40 ;
}
if ( ! V_22 ) {
F_26 ( L_31
L_32 ) ;
return - V_48 ;
}
}
if ( F_41 ( & type , V_71 -> V_74 , V_72 ) == NULL ) {
F_26 ( L_33 , V_69 ,
F_24 ( & type ) , V_71 -> V_74 ) ;
return - V_40 ;
}
if ( V_73 == V_77 ) {
V_21 = 0 ;
} else {
V_36 = F_42 ( V_72 , & V_21 ) ;
if ( V_36 < 0 ) {
F_26 ( L_34 ,
V_71 -> V_74 ) ;
return V_36 ;
}
}
V_22 -> V_23 += ( long ) V_21 ;
V_66:
if ( V_71 -> V_66 )
return F_37 ( V_72 , V_71 -> V_74 ,
V_71 -> V_66 , & V_22 , V_72 ) ;
else
return 0 ;
}
static int F_43 ( T_1 * V_24 , struct V_78 * V_79 )
{
T_1 V_72 ;
int V_36 ;
F_11 ( L_35 ,
F_24 ( V_24 ) ) ;
V_36 = F_18 ( V_24 , V_79 -> V_25 , V_79 -> V_26 ,
& V_79 -> V_27 , V_79 -> V_29 ) ;
if ( V_36 == - V_10 || V_36 == - V_40 )
F_40 ( L_36
L_37 , V_79 -> V_80 -> V_81 ) ;
else if ( V_36 == - V_48 )
F_40 ( L_38 ) ;
else if ( V_36 == 0 && V_79 -> V_80 -> V_71 ) {
V_36 = F_37 ( V_24 , V_79 -> V_80 -> V_81 ,
V_79 -> V_80 -> V_71 , & V_79 -> V_29 -> V_22 ,
& V_72 ) ;
V_24 = & V_72 ;
}
if ( V_36 == 0 )
V_36 = F_28 ( V_24 , V_79 -> V_29 , V_79 -> V_80 -> type ) ;
return V_36 ;
}
static int F_44 ( T_1 * V_82 , struct V_78 * V_79 )
{
T_1 V_24 ;
char V_12 [ 32 ] , * V_83 ;
int V_36 = 0 ;
if ( ! F_45 ( V_79 -> V_80 -> V_81 ) ) {
V_79 -> V_29 -> V_45 = F_27 ( V_79 -> V_80 -> V_81 ) ;
if ( V_79 -> V_29 -> V_45 == NULL )
return - V_46 ;
if ( V_79 -> V_80 -> type ) {
V_79 -> V_29 -> type = F_27 ( V_79 -> V_80 -> type ) ;
if ( V_79 -> V_29 -> type == NULL )
return - V_46 ;
}
if ( V_79 -> V_80 -> V_74 ) {
V_79 -> V_29 -> V_74 = F_27 ( V_79 -> V_80 -> V_74 ) ;
if ( V_79 -> V_29 -> V_74 == NULL )
return - V_46 ;
} else
V_79 -> V_29 -> V_74 = NULL ;
return 0 ;
}
if ( V_79 -> V_80 -> V_74 )
V_79 -> V_29 -> V_74 = F_27 ( V_79 -> V_80 -> V_74 ) ;
else {
V_36 = F_46 ( V_79 -> V_80 , V_12 , 32 ) ;
if ( V_36 < 0 )
return V_36 ;
V_83 = strchr ( V_12 , ':' ) ;
if ( V_83 )
* V_83 = '_' ;
V_79 -> V_29 -> V_74 = F_27 ( V_12 ) ;
}
if ( V_79 -> V_29 -> V_74 == NULL )
return - V_46 ;
F_11 ( L_39 , V_79 -> V_80 -> V_81 ) ;
if ( ! F_47 ( V_82 , V_79 -> V_80 -> V_81 , V_79 -> V_25 , & V_24 ) ) {
if ( ! F_47 ( & V_79 -> V_84 , V_79 -> V_80 -> V_81 , 0 , & V_24 ) )
F_26 ( L_40 ,
V_79 -> V_80 -> V_81 ) ;
V_36 = - V_10 ;
}
if ( V_36 >= 0 )
V_36 = F_43 ( & V_24 , V_79 ) ;
return V_36 ;
}
static int F_48 ( T_1 * V_27 , T_7 * V_8 ,
T_2 V_85 , bool V_86 ,
struct V_87 * V_88 )
{
T_2 V_89 , V_90 ;
T_8 V_91 ;
const char * V_92 ;
if ( F_21 ( V_27 , & V_89 ) != 0 ) {
F_26 ( L_41 ,
F_24 ( V_27 ) ) ;
return - V_10 ;
}
if ( F_23 ( V_27 , & V_90 ) != 0 ) {
F_26 ( L_42 ,
F_24 ( V_27 ) ) ;
return - V_10 ;
}
if ( V_85 > V_90 ) {
F_26 ( L_43 ,
F_24 ( V_27 ) ) ;
return - V_40 ;
}
V_92 = F_49 ( V_8 , V_85 , & V_91 , NULL ) ;
if ( ! V_92 ) {
F_26 ( L_44 ,
( unsigned long ) V_85 ) ;
return - V_10 ;
}
V_88 -> V_23 = ( unsigned long ) ( V_85 - V_91 . V_93 ) ;
V_88 -> V_94 = ( unsigned long ) V_85 ;
V_88 -> V_92 = F_27 ( V_92 ) ;
if ( ! V_88 -> V_92 )
return - V_46 ;
if ( V_86 ) {
if ( V_89 != V_85 ) {
F_26 ( L_45
L_46 ) ;
return - V_40 ;
}
V_88 -> V_86 = true ;
}
return 0 ;
}
static int F_50 ( T_1 * V_82 , struct V_78 * V_79 )
{
T_4 V_95 ;
T_5 V_33 ;
int V_36 ;
if ( ! V_82 ) {
F_40 ( L_47 ) ;
return - V_40 ;
}
if ( ! F_51 ( V_82 ) ) {
if ( ! F_52 ( & V_79 -> V_84 , V_79 -> V_25 , & V_79 -> V_27 ) ) {
F_26 ( L_48
L_49 ) ;
return - V_10 ;
}
} else
memcpy ( & V_79 -> V_27 , V_82 , sizeof( T_1 ) ) ;
F_19 ( & V_79 -> V_27 , V_96 , & V_95 ) ;
V_36 = F_20 ( & V_95 , V_79 -> V_25 , & V_79 -> V_26 , & V_33 , 1 ) ;
if ( V_36 <= 0 || V_33 == 0 ) {
V_79 -> V_26 = NULL ;
#if F_53 ( 0 , 142 )
} else if ( V_33 == 1 && V_79 -> V_26 [ 0 ] . V_43 == V_97 &&
V_79 -> V_98 != NULL ) {
T_9 * V_99 ;
if ( F_54 ( V_79 -> V_98 , V_79 -> V_25 , & V_99 ) != 0 ||
F_55 ( V_99 , & V_79 -> V_26 , & V_33 ) != 0 ) {
F_26 ( L_50 ,
( V_100 ) V_79 -> V_25 ) ;
return - V_10 ;
}
#endif
}
V_36 = V_79 -> V_101 ( V_82 , V_79 ) ;
V_79 -> V_26 = NULL ;
return V_36 ;
}
static int F_56 ( T_1 * V_102 , void * V_103 )
{
struct V_104 * V_105 = V_103 ;
const char * V_106 ;
int V_107 ;
if ( V_105 -> V_106 ) {
V_106 = F_57 ( V_102 ) ;
if ( ! V_106 || strcmp ( V_105 -> V_106 , V_106 ) != 0 )
return 0 ;
}
if ( V_105 -> V_108 ) {
if ( F_34 ( V_102 , V_105 -> V_108 ) ) {
memcpy ( V_105 -> V_72 , V_102 , sizeof( T_1 ) ) ;
V_105 -> V_42 = true ;
return 1 ;
}
} else {
F_58 ( V_102 , & V_107 ) ;
if ( V_107 < V_105 -> line && V_105 -> V_109 > V_105 -> line - V_107 ) {
V_105 -> V_109 = V_105 -> line - V_107 ;
memcpy ( V_105 -> V_72 , V_102 , sizeof( T_1 ) ) ;
V_105 -> V_42 = true ;
}
}
return 0 ;
}
static T_1 * F_59 ( struct V_78 * V_79 , T_1 * V_72 )
{
struct V_104 V_105 = {
. V_108 = V_79 -> V_110 -> V_111 . V_108 ,
. V_106 = V_79 -> V_112 ,
. line = V_79 -> V_107 ,
. V_109 = V_113 ,
. V_72 = V_72 ,
. V_42 = false ,
} ;
F_60 ( & V_79 -> V_84 , V_79 -> V_25 , F_56 , & V_105 ) ;
return V_105 . V_42 ? V_72 : NULL ;
}
static int F_61 ( const char * V_112 , int V_114 ,
T_2 V_25 , void * V_103 )
{
struct V_78 * V_79 = V_103 ;
T_1 * V_82 , V_72 ;
int V_36 ;
if ( V_114 != V_79 -> V_107 || F_62 ( V_112 , V_79 -> V_112 ) != 0 )
return 0 ;
V_79 -> V_25 = V_25 ;
V_82 = F_59 ( V_79 , & V_72 ) ;
if ( ! V_82 ) {
F_26 ( L_51 ) ;
return - V_10 ;
}
V_36 = F_50 ( V_82 , V_79 ) ;
return V_36 < 0 ? V_36 : 0 ;
}
static int F_63 ( struct V_78 * V_79 )
{
return F_64 ( & V_79 -> V_84 , F_61 , V_79 ) ;
}
static int F_65 ( struct V_115 * V_116 ,
const char * V_112 , const char * V_117 )
{
T_10 * V_118 ;
char * line = NULL ;
T_5 V_119 ;
T_11 V_120 ;
int V_121 = 0 , V_122 = 1 ;
V_118 = fopen ( V_112 , L_52 ) ;
if ( ! V_118 ) {
F_26 ( L_53 , V_112 , strerror ( V_123 ) ) ;
return - V_123 ;
}
while ( ( V_120 = F_66 ( & line , & V_119 , V_118 ) ) > 0 ) {
if ( line [ V_120 - 1 ] == '\n' )
line [ V_120 - 1 ] = '\0' ;
if ( F_67 ( line , V_117 ) ) {
F_68 ( V_116 , V_122 ) ;
V_121 ++ ;
}
V_122 ++ ;
}
if ( ferror ( V_118 ) )
V_121 = - V_123 ;
free ( line ) ;
fclose ( V_118 ) ;
if ( V_121 == 0 )
F_11 ( L_54 , V_112 ) ;
return V_121 ;
}
static int F_69 ( const char * V_112 , int V_114 ,
T_2 V_25 , void * V_103 )
{
struct V_78 * V_79 = V_103 ;
T_1 * V_82 , V_72 ;
int V_36 ;
if ( ! F_70 ( V_79 -> V_124 , V_114 ) ||
F_62 ( V_112 , V_79 -> V_112 ) != 0 )
return 0 ;
F_11 ( L_55 ,
V_114 , ( unsigned long long ) V_25 ) ;
V_79 -> V_25 = V_25 ;
V_79 -> V_107 = V_114 ;
V_82 = F_59 ( V_79 , & V_72 ) ;
if ( ! V_82 ) {
F_26 ( L_51 ) ;
return - V_10 ;
}
V_36 = F_50 ( V_82 , V_79 ) ;
return V_36 < 0 ? V_36 : 0 ;
}
static int F_71 ( T_1 * V_27 , struct V_78 * V_79 )
{
int V_36 = 0 ;
if ( F_72 ( V_79 -> V_124 ) ) {
V_36 = F_65 ( V_79 -> V_124 , V_79 -> V_112 ,
V_79 -> V_110 -> V_111 . V_125 ) ;
if ( V_36 <= 0 )
return V_36 ;
}
return F_64 ( V_27 , F_69 , V_79 ) ;
}
static int F_73 ( T_1 * V_126 , void * V_103 )
{
struct V_78 * V_79 = V_103 ;
struct V_127 * V_128 = & V_79 -> V_110 -> V_111 ;
T_2 V_25 ;
int V_36 ;
if ( V_128 -> V_125 )
V_36 = F_71 ( V_126 , V_79 ) ;
else {
if ( F_21 ( V_126 , & V_25 ) != 0 ) {
F_26 ( L_56 ,
F_24 ( V_126 ) ) ;
return - V_10 ;
}
V_79 -> V_25 = V_25 ;
V_79 -> V_25 += V_128 -> V_23 ;
F_11 ( L_57 ,
( V_100 ) V_79 -> V_25 ) ;
V_36 = F_50 ( V_126 , V_79 ) ;
}
return V_36 ;
}
static int F_74 ( T_1 * V_27 , void * V_103 )
{
struct V_129 * V_130 = V_103 ;
struct V_78 * V_79 = V_130 -> V_103 ;
struct V_127 * V_128 = & V_79 -> V_110 -> V_111 ;
if ( ! F_51 ( V_27 ) ||
! F_34 ( V_27 , V_128 -> V_108 ) )
return V_131 ;
if ( V_128 -> V_106 && F_62 ( V_128 -> V_106 , F_57 ( V_27 ) ) )
return V_131 ;
V_79 -> V_112 = F_57 ( V_27 ) ;
if ( V_128 -> line ) {
F_58 ( V_27 , & V_79 -> V_107 ) ;
V_79 -> V_107 += V_128 -> line ;
V_130 -> V_132 = F_63 ( V_79 ) ;
} else if ( ! F_75 ( V_27 ) ) {
if ( V_128 -> V_125 )
V_130 -> V_132 = F_71 ( V_27 , V_79 ) ;
else {
if ( F_21 ( V_27 , & V_79 -> V_25 ) != 0 ) {
F_26 ( L_58
L_59 , F_24 ( V_27 ) ) ;
V_130 -> V_132 = - V_10 ;
return V_133 ;
}
V_79 -> V_25 += V_128 -> V_23 ;
V_130 -> V_132 = F_50 ( V_27 , V_79 ) ;
}
} else
V_130 -> V_132 = F_76 ( V_27 ,
F_73 , ( void * ) V_79 ) ;
return V_133 ;
}
static int F_77 ( struct V_78 * V_79 )
{
struct V_129 V_134 = { . V_103 = ( void * ) V_79 ,
. V_132 = 0 } ;
F_78 ( & V_79 -> V_84 , F_74 , & V_134 , 0 ) ;
return V_134 . V_132 ;
}
static int F_79 ( T_12 * V_2 , T_13 * V_135 , void * V_103 )
{
struct V_136 * V_130 = V_103 ;
if ( F_80 ( V_2 , V_135 -> V_137 , V_130 -> V_27 ) ) {
if ( F_22 ( V_130 -> V_27 ) != V_138 )
return V_131 ;
if ( F_34 ( V_130 -> V_27 , V_130 -> V_108 ) ) {
if ( ! F_80 ( V_2 , V_135 -> V_139 , V_130 -> V_84 ) )
return V_131 ;
if ( V_130 -> V_106 &&
F_62 ( V_130 -> V_106 , F_57 ( V_130 -> V_27 ) ) )
return V_131 ;
V_130 -> V_42 = 1 ;
return V_133 ;
}
}
return V_131 ;
}
static int F_81 ( struct V_1 * V_2 ,
struct V_78 * V_79 )
{
struct V_127 * V_128 = & V_79 -> V_110 -> V_111 ;
T_14 V_140 , V_141 ;
T_5 V_142 ;
T_1 * V_143 ;
int V_36 = 0 ;
#if F_53 ( 0 , 142 )
V_79 -> V_98 = F_82 ( F_83 ( V_2 -> V_2 ) ) ;
#endif
V_140 = 0 ;
V_79 -> V_124 = F_84 ( NULL ) ;
if ( ! V_79 -> V_124 )
return - V_46 ;
if ( V_128 -> V_108 ) {
struct V_136 V_144 = {
. V_108 = V_128 -> V_108 ,
. V_106 = V_128 -> V_106 ,
. V_84 = & V_79 -> V_84 ,
. V_27 = & V_79 -> V_27 ,
. V_42 = 0 ,
} ;
struct V_129 V_145 = {
. V_103 = V_79 ,
} ;
F_85 ( V_2 -> V_2 , F_79 ,
& V_144 , 0 ) ;
if ( V_144 . V_42 ) {
V_36 = F_74 ( & V_79 -> V_27 , & V_145 ) ;
if ( V_36 )
goto V_42;
}
}
while ( ! F_86 ( V_2 -> V_2 , V_140 , & V_141 , & V_142 , NULL , NULL , NULL ) ) {
V_143 = F_80 ( V_2 -> V_2 , V_140 + V_142 , & V_79 -> V_84 ) ;
if ( ! V_143 )
continue;
if ( V_128 -> V_106 )
V_79 -> V_112 = F_87 ( & V_79 -> V_84 , V_128 -> V_106 ) ;
else
V_79 -> V_112 = NULL ;
if ( ! V_128 -> V_106 || V_79 -> V_112 ) {
if ( V_128 -> V_108 )
V_36 = F_77 ( V_79 ) ;
else if ( V_128 -> V_125 )
V_36 = F_71 ( NULL , V_79 ) ;
else {
V_79 -> V_107 = V_128 -> line ;
V_36 = F_63 ( V_79 ) ;
}
if ( V_36 < 0 )
break;
}
V_140 = V_141 ;
}
V_42:
F_88 ( V_79 -> V_124 ) ;
V_79 -> V_124 = NULL ;
return V_36 ;
}
static int F_89 ( T_1 * V_72 , void * V_103 )
{
struct V_146 * V_147 = V_103 ;
struct V_78 * V_79 = V_147 -> V_79 ;
int V_73 ;
V_73 = F_22 ( V_72 ) ;
if ( V_73 == V_41 ||
V_73 == V_148 ) {
if ( F_18 ( V_72 , V_147 -> V_79 -> V_25 ,
V_147 -> V_79 -> V_26 , & V_79 -> V_27 ,
NULL ) == 0 ) {
V_147 -> args [ V_147 -> V_149 ] . V_81 = ( char * ) F_24 ( V_72 ) ;
if ( V_147 -> args [ V_147 -> V_149 ] . V_81 == NULL ) {
V_147 -> V_36 = - V_46 ;
return V_150 ;
}
F_11 ( L_60 , V_147 -> args [ V_147 -> V_149 ] . V_81 ) ;
V_147 -> V_149 ++ ;
}
}
if ( F_90 ( V_72 , V_147 -> V_79 -> V_25 ) )
return V_151 ;
else
return V_152 ;
}
static int F_91 ( T_1 * V_82 , struct V_78 * V_79 ,
struct V_153 * args )
{
T_1 V_72 ;
int V_154 ;
int V_155 = 0 ;
struct V_146 V_147 = { . V_79 = V_79 , . args = args ,
. V_156 = V_157 , . V_36 = 0 } ;
for ( V_154 = 0 ; V_154 < V_79 -> V_110 -> V_149 ; V_154 ++ ) {
if ( strcmp ( V_79 -> V_110 -> args [ V_154 ] . V_81 , L_61 ) == 0 ) {
F_11 ( L_62 ) ;
V_147 . V_149 = V_155 ;
F_92 ( V_82 , F_89 , ( void * ) & V_147 ,
& V_72 ) ;
F_11 ( L_63 , V_147 . V_149 - V_155 ) ;
if ( V_147 . V_36 < 0 )
return V_147 . V_36 ;
V_155 = V_147 . V_149 ;
} else {
args [ V_155 ] = V_79 -> V_110 -> args [ V_154 ] ;
V_155 ++ ;
}
}
return V_155 ;
}
static int F_93 ( T_1 * V_82 , struct V_78 * V_79 )
{
struct V_158 * V_159 =
F_94 ( V_79 , struct V_158 , V_79 ) ;
struct V_160 * V_161 ;
struct V_153 * args ;
int V_36 , V_154 ;
if ( V_159 -> V_162 == V_159 -> V_163 ) {
F_26 ( L_64 ,
V_159 -> V_163 ) ;
return - V_57 ;
}
V_161 = & V_159 -> V_164 [ V_159 -> V_162 ++ ] ;
V_36 = F_48 ( & V_79 -> V_27 , V_159 -> V_8 , V_79 -> V_25 ,
V_79 -> V_110 -> V_111 . V_86 , & V_161 -> V_111 ) ;
if ( V_36 < 0 )
return V_36 ;
F_11 ( L_65 , V_161 -> V_111 . V_92 ,
V_161 -> V_111 . V_23 ) ;
args = F_9 ( sizeof( struct V_153 ) * V_157 ) ;
if ( args == NULL )
return - V_46 ;
V_36 = F_91 ( V_82 , V_79 , args ) ;
if ( V_36 < 0 )
goto V_165;
V_161 -> V_149 = V_36 ;
V_161 -> args = F_9 ( sizeof( struct V_28 ) * V_161 -> V_149 ) ;
if ( V_161 -> args == NULL ) {
V_36 = - V_46 ;
goto V_165;
}
for ( V_154 = 0 ; V_154 < V_161 -> V_149 ; V_154 ++ ) {
V_79 -> V_80 = & args [ V_154 ] ;
V_79 -> V_29 = & V_161 -> args [ V_154 ] ;
V_36 = F_44 ( V_82 , V_79 ) ;
if ( V_36 != 0 )
break;
}
V_165:
free ( args ) ;
return V_36 ;
}
int F_95 ( struct V_1 * V_2 ,
struct V_166 * V_110 ,
struct V_160 * * V_164 , int V_163 )
{
struct V_158 V_159 = {
. V_79 = { . V_110 = V_110 , . V_101 = F_93 } ,
. V_8 = V_2 -> V_8 , . V_163 = V_163 } ;
int V_36 ;
* V_164 = F_9 ( sizeof( struct V_160 ) * V_163 ) ;
if ( * V_164 == NULL )
return - V_46 ;
V_159 . V_164 = * V_164 ;
V_159 . V_162 = 0 ;
V_36 = F_81 ( V_2 , & V_159 . V_79 ) ;
if ( V_36 < 0 ) {
F_10 ( V_164 ) ;
return V_36 ;
}
return ( V_36 < 0 ) ? V_36 : V_159 . V_162 ;
}
static int F_96 ( T_1 * V_72 , void * V_103 )
{
struct V_167 * V_168 = V_103 ;
struct V_169 * V_170 ;
char V_12 [ V_171 ] ;
int V_73 , V_36 ;
V_170 = & V_168 -> V_172 [ V_168 -> V_173 - 1 ] ;
V_73 = F_22 ( V_72 ) ;
if ( V_73 == V_41 ||
V_73 == V_148 ) {
V_36 = F_18 ( V_72 , V_168 -> V_79 . V_25 ,
V_168 -> V_79 . V_26 , & V_168 -> V_79 . V_27 ,
NULL ) ;
if ( V_36 == 0 ) {
V_36 = F_97 ( V_72 , V_12 , V_171 ) ;
F_38 ( L_66 , V_12 ) ;
if ( V_36 > 0 )
F_98 ( V_170 -> V_174 , V_12 ) ;
}
}
if ( V_168 -> V_175 && F_90 ( V_72 , V_168 -> V_79 . V_25 ) )
return V_151 ;
else
return V_152 ;
}
static int F_99 ( T_1 * V_82 , struct V_78 * V_79 )
{
struct V_167 * V_168 =
F_94 ( V_79 , struct V_167 , V_79 ) ;
struct V_169 * V_170 ;
T_1 V_72 ;
int V_36 ;
if ( V_168 -> V_173 == V_168 -> V_176 ) {
F_26 ( L_64 , V_168 -> V_176 ) ;
return - V_57 ;
}
V_170 = & V_168 -> V_172 [ V_168 -> V_173 ++ ] ;
V_36 = F_48 ( & V_79 -> V_27 , V_168 -> V_8 , V_79 -> V_25 ,
V_79 -> V_110 -> V_111 . V_86 , & V_170 -> V_111 ) ;
if ( V_36 < 0 )
return V_36 ;
F_11 ( L_65 , V_170 -> V_111 . V_92 ,
V_170 -> V_111 . V_23 ) ;
V_170 -> V_174 = F_100 ( true , NULL ) ;
if ( V_170 -> V_174 == NULL )
return - V_46 ;
V_168 -> V_175 = true ;
F_92 ( V_82 , F_96 , ( void * ) V_168 , & V_72 ) ;
if ( ! V_168 -> V_177 )
goto V_17;
V_168 -> V_175 = false ;
F_92 ( & V_79 -> V_84 , F_96 , ( void * ) V_168 , & V_72 ) ;
V_17:
if ( F_101 ( V_170 -> V_174 ) ) {
F_102 ( V_170 -> V_174 ) ;
V_170 -> V_174 = NULL ;
}
return V_36 ;
}
int F_103 ( struct V_1 * V_2 ,
struct V_166 * V_110 ,
struct V_169 * * V_172 ,
int V_176 , bool V_177 )
{
struct V_167 V_168 = {
. V_79 = { . V_110 = V_110 , . V_101 = F_99 } ,
. V_8 = V_2 -> V_8 ,
. V_176 = V_176 , . V_177 = V_177 } ;
int V_36 ;
* V_172 = F_9 ( sizeof( struct V_169 ) * V_176 ) ;
if ( * V_172 == NULL )
return - V_46 ;
V_168 . V_172 = * V_172 ;
V_168 . V_173 = 0 ;
V_36 = F_81 ( V_2 , & V_168 . V_79 ) ;
if ( V_36 < 0 ) {
while ( V_168 . V_173 -- ) {
F_10 ( & V_168 . V_172 [ V_168 . V_173 ] . V_111 . V_92 ) ;
F_102 ( V_168 . V_172 [ V_168 . V_173 ] . V_174 ) ;
}
F_10 ( V_172 ) ;
return V_36 ;
}
return ( V_36 < 0 ) ? V_36 : V_168 . V_173 ;
}
int F_104 ( struct V_1 * V_2 , unsigned long V_25 ,
struct V_127 * V_178 )
{
T_1 V_179 , V_180 , V_181 ;
T_2 V_182 = 0 , V_183 = 0 ;
const char * V_112 = NULL , * V_184 = NULL , * V_185 = NULL , * V_31 ;
int V_186 = 0 , V_114 = 0 , V_36 = 0 ;
V_25 += V_2 -> V_9 ;
if ( ! F_105 ( V_2 -> V_2 , ( T_2 ) V_25 - V_2 -> V_9 , & V_179 ) ) {
F_26 ( L_67 ,
V_25 ) ;
V_36 = - V_40 ;
goto V_165;
}
F_106 ( & V_179 , V_25 , & V_112 , & V_114 ) ;
if ( F_52 ( & V_179 , ( T_2 ) V_25 , & V_180 ) ) {
V_184 = V_185 = F_24 ( & V_180 ) ;
if ( ! V_184 ||
F_21 ( & V_180 , & V_183 ) != 0 ||
F_58 ( & V_180 , & V_186 ) != 0 ) {
V_114 = 0 ;
goto V_187;
}
V_112 = F_57 ( & V_180 ) ;
if ( V_25 == ( unsigned long ) V_183 ) {
V_114 = V_186 ;
goto V_187;
}
while ( F_107 ( & V_180 , ( T_2 ) V_25 ,
& V_181 ) ) {
if ( F_21 ( & V_181 , & V_182 ) == 0 &&
V_182 == V_25 ) {
V_114 = F_108 ( & V_181 ) ;
V_112 = F_109 ( & V_181 ) ;
break;
} else {
V_31 = F_24 ( & V_181 ) ;
if ( ! V_31 ||
F_58 ( & V_181 , & V_186 ) != 0 )
break;
V_184 = V_31 ;
V_180 = V_181 ;
}
}
V_31 = F_57 ( & V_180 ) ;
if ( ! V_31 || strcmp ( V_31 , V_112 ) != 0 )
V_114 = 0 ;
}
V_187:
if ( V_114 )
V_178 -> line = V_114 - V_186 ;
else if ( V_185 ) {
V_178 -> V_23 = V_25 - ( unsigned long ) V_183 ;
V_184 = V_185 ;
}
if ( V_184 ) {
V_178 -> V_108 = F_27 ( V_184 ) ;
if ( V_178 -> V_108 == NULL ) {
V_36 = - V_46 ;
goto V_165;
}
}
if ( V_112 ) {
V_178 -> V_106 = F_27 ( V_112 ) ;
if ( V_178 -> V_106 == NULL ) {
F_10 ( & V_178 -> V_108 ) ;
V_36 = - V_46 ;
goto V_165;
}
}
V_165:
if ( V_36 == 0 && ( V_112 || V_184 ) )
V_36 = 1 ;
return V_36 ;
}
static int F_110 ( const char * V_188 , unsigned int V_114 ,
struct V_189 * V_190 )
{
if ( ! V_190 -> V_3 ) {
V_190 -> V_3 = F_27 ( V_188 ) ;
if ( V_190 -> V_3 == NULL )
return - V_46 ;
}
return F_68 ( V_190 -> V_191 , V_114 ) ;
}
static int F_111 ( const char * V_112 , int V_114 ,
T_2 V_25 V_192 ,
void * V_103 )
{
struct V_193 * V_194 = V_103 ;
int V_195 ;
if ( ( F_62 ( V_112 , V_194 -> V_112 ) != 0 ) ||
( V_194 -> V_196 > V_114 || V_194 -> V_197 < V_114 ) )
return 0 ;
V_195 = F_110 ( V_112 , V_114 , V_194 -> V_190 ) ;
if ( V_195 < 0 && V_195 != - V_198 )
return V_195 ;
return 0 ;
}
static int F_112 ( T_1 * V_27 , struct V_193 * V_194 )
{
int V_36 ;
V_36 = F_64 ( V_27 ? : & V_194 -> V_84 , F_111 , V_194 ) ;
if ( V_36 >= 0 )
if ( ! F_72 ( V_194 -> V_190 -> V_191 ) )
V_36 = V_194 -> V_42 = 1 ;
else
V_36 = 0 ;
else {
F_10 ( & V_194 -> V_190 -> V_3 ) ;
}
return V_36 ;
}
static int F_113 ( T_1 * V_126 , void * V_103 )
{
int V_36 = F_112 ( V_126 , V_103 ) ;
return V_36 < 0 ? V_36 : 0 ;
}
static int F_114 ( T_1 * V_27 , void * V_103 )
{
struct V_129 * V_130 = V_103 ;
struct V_193 * V_194 = V_130 -> V_103 ;
struct V_189 * V_190 = V_194 -> V_190 ;
if ( V_190 -> V_106 && F_62 ( V_190 -> V_106 , F_57 ( V_27 ) ) )
return V_131 ;
if ( F_51 ( V_27 ) &&
F_34 ( V_27 , V_190 -> V_108 ) ) {
V_194 -> V_112 = F_57 ( V_27 ) ;
F_58 ( V_27 , & V_190 -> V_23 ) ;
F_11 ( L_68 , V_194 -> V_112 , V_190 -> V_23 ) ;
V_194 -> V_196 = V_190 -> V_23 + V_190 -> V_199 ;
if ( V_194 -> V_196 < 0 )
V_194 -> V_196 = V_113 ;
V_194 -> V_197 = V_190 -> V_23 + V_190 -> V_165 ;
if ( V_194 -> V_197 < 0 )
V_194 -> V_197 = V_113 ;
F_11 ( L_69 , V_194 -> V_196 , V_194 -> V_197 ) ;
V_190 -> V_199 = V_194 -> V_196 ;
V_190 -> V_165 = V_194 -> V_197 ;
if ( F_75 ( V_27 ) )
V_130 -> V_132 = F_76 ( V_27 ,
F_113 , V_194 ) ;
else
V_130 -> V_132 = F_112 ( V_27 , V_194 ) ;
return V_133 ;
}
return V_131 ;
}
static int F_115 ( struct V_193 * V_194 )
{
struct V_129 V_130 = { . V_103 = ( void * ) V_194 , . V_132 = 0 } ;
F_78 ( & V_194 -> V_84 , F_114 , & V_130 , 0 ) ;
return V_130 . V_132 ;
}
int F_116 ( struct V_1 * V_2 , struct V_189 * V_190 )
{
struct V_193 V_194 = { . V_190 = V_190 , . V_42 = 0 } ;
int V_36 = 0 ;
T_14 V_140 = 0 , V_141 ;
T_5 V_142 ;
T_1 * V_143 ;
const char * V_200 ;
if ( V_190 -> V_108 ) {
struct V_136 V_144 = {
. V_108 = V_190 -> V_108 , . V_106 = V_190 -> V_106 ,
. V_84 = & V_194 . V_84 , . V_27 = & V_194 . V_27 , . V_42 = 0 } ;
struct V_129 V_201 = {
. V_103 = ( void * ) & V_194 , . V_132 = 0 } ;
F_85 ( V_2 -> V_2 , F_79 ,
& V_144 , 0 ) ;
if ( V_144 . V_42 ) {
F_114 ( & V_194 . V_27 , & V_201 ) ;
if ( V_194 . V_42 )
goto V_42;
}
}
while ( ! V_194 . V_42 && V_36 >= 0 ) {
if ( F_86 ( V_2 -> V_2 , V_140 , & V_141 , & V_142 ,
NULL , NULL , NULL ) != 0 )
break;
V_143 = F_80 ( V_2 -> V_2 , V_140 + V_142 , & V_194 . V_84 ) ;
if ( ! V_143 )
continue;
if ( V_190 -> V_106 )
V_194 . V_112 = F_87 ( & V_194 . V_84 , V_190 -> V_106 ) ;
else
V_194 . V_112 = 0 ;
if ( ! V_190 -> V_106 || V_194 . V_112 ) {
if ( V_190 -> V_108 )
V_36 = F_115 ( & V_194 ) ;
else {
V_194 . V_196 = V_190 -> V_199 ;
V_194 . V_197 = V_190 -> V_165 ;
V_36 = F_112 ( NULL , & V_194 ) ;
}
}
V_140 = V_141 ;
}
V_42:
if ( V_194 . V_42 ) {
V_200 = F_117 ( & V_194 . V_84 ) ;
if ( V_200 ) {
V_190 -> V_200 = F_27 ( V_200 ) ;
if ( ! V_190 -> V_200 )
V_36 = - V_46 ;
}
}
F_11 ( L_70 , V_190 -> V_3 ) ;
return ( V_36 < 0 ) ? V_36 : V_194 . V_42 ;
}
