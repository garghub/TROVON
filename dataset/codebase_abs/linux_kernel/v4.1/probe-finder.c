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
char V_60 [ V_61 ] ;
int V_62 , V_63 , V_64 ;
int V_36 ;
if ( V_58 && strcmp ( V_58 , L_7 ) != 0 ) {
V_29 -> type = F_27 ( V_58 ) ;
return ( V_29 -> type == NULL ) ? - V_46 : 0 ;
}
V_62 = F_29 ( V_24 ) ;
if ( V_62 > 0 ) {
V_63 = F_30 ( V_24 ) ;
V_64 = F_31 ( V_24 ) ;
if ( V_63 < 0 || V_64 < 0 )
return - V_10 ;
V_36 = snprintf ( V_12 , 16 , L_8 , V_62 , V_63 ,
F_32 ( V_64 ) ) ;
goto V_65;
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
if ( V_36 != V_66 &&
V_36 != V_67 ) {
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
if ( V_36 == V_66 ) {
while ( * V_59 )
V_59 = & ( * V_59 ) -> V_68 ;
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
if ( V_36 > V_69 ) {
F_35 ( L_19 ,
F_24 ( & type ) , V_69 ) ;
V_36 = V_69 ;
}
V_36 = snprintf ( V_12 , 16 , L_20 ,
F_36 ( & type ) ? 's' : 'u' , V_36 ) ;
V_65:
if ( V_36 < 0 || V_36 >= 16 ) {
if ( V_36 >= 16 )
V_36 = - V_70 ;
F_26 ( L_21 ,
F_37 ( - V_36 , V_60 , sizeof( V_60 ) ) ) ;
return V_36 ;
}
V_29 -> type = F_27 ( V_12 ) ;
if ( V_29 -> type == NULL )
return - V_46 ;
return 0 ;
}
static int F_38 ( T_1 * V_24 , const char * V_71 ,
struct V_72 * V_73 ,
struct V_20 * * V_59 ,
T_1 * V_74 )
{
struct V_20 * V_22 = * V_59 ;
T_1 type ;
T_6 V_21 ;
int V_36 , V_75 ;
F_11 ( L_22 , V_73 -> V_76 , V_71 ) ;
if ( F_33 ( V_24 , & type ) == NULL ) {
F_26 ( L_23 , V_71 ) ;
return - V_10 ;
}
F_39 ( L_24 , ( unsigned ) F_40 ( & type ) ) ;
V_75 = F_22 ( & type ) ;
if ( V_73 -> V_76 [ 0 ] == '[' &&
( V_75 == V_67 || V_75 == V_66 ) ) {
if ( V_73 -> V_68 )
memcpy ( V_74 , & type , sizeof( * V_74 ) ) ;
if ( F_33 ( & type , & type ) == NULL ) {
F_26 ( L_23 , V_71 ) ;
return - V_10 ;
}
F_39 ( L_25 ,
( unsigned ) F_40 ( & type ) ) ;
if ( V_75 == V_66 ) {
V_22 = F_9 ( sizeof( struct V_20 ) ) ;
if ( V_22 == NULL )
return - V_46 ;
if ( * V_59 )
( * V_59 ) -> V_68 = V_22 ;
else
* V_59 = V_22 ;
}
V_22 -> V_23 += F_31 ( & type ) * V_73 -> V_77 ;
if ( ! V_73 -> V_68 )
memcpy ( V_74 , V_24 , sizeof( * V_74 ) ) ;
goto V_68;
} else if ( V_75 == V_66 ) {
if ( ! V_73 -> V_22 ) {
F_41 ( L_26 ,
V_73 -> V_76 ) ;
return - V_40 ;
}
if ( F_33 ( & type , & type ) == NULL ) {
F_26 ( L_23 , V_71 ) ;
return - V_10 ;
}
V_75 = F_22 ( & type ) ;
if ( V_75 != V_78 && V_75 != V_79 ) {
F_26 ( L_27 ,
V_71 ) ;
return - V_40 ;
}
V_22 = F_9 ( sizeof( struct V_20 ) ) ;
if ( V_22 == NULL )
return - V_46 ;
if ( * V_59 )
( * V_59 ) -> V_68 = V_22 ;
else
* V_59 = V_22 ;
} else {
if ( V_75 != V_78 && V_75 != V_79 ) {
F_26 ( L_27 ,
V_71 ) ;
return - V_40 ;
}
if ( V_73 -> V_76 [ 0 ] == '[' ) {
F_41 ( L_28
L_29 , V_71 ) ;
return - V_40 ;
}
if ( V_73 -> V_22 && F_24 ( V_24 ) ) {
F_41 ( L_30 ,
V_73 -> V_76 ) ;
return - V_40 ;
}
if ( ! V_22 ) {
F_26 ( L_31
L_32 ) ;
return - V_48 ;
}
}
if ( F_42 ( & type , V_73 -> V_76 , V_74 ) == NULL ) {
F_26 ( L_33 , V_71 ,
F_24 ( & type ) , V_73 -> V_76 ) ;
return - V_40 ;
}
if ( V_75 == V_79 ) {
V_21 = 0 ;
} else {
V_36 = F_43 ( V_74 , & V_21 ) ;
if ( V_36 < 0 ) {
F_26 ( L_34 ,
V_73 -> V_76 ) ;
return V_36 ;
}
}
V_22 -> V_23 += ( long ) V_21 ;
if ( ! F_24 ( V_74 ) )
return F_38 ( V_74 , V_71 , V_73 ,
& V_22 , V_74 ) ;
V_68:
if ( V_73 -> V_68 )
return F_38 ( V_74 , V_73 -> V_76 ,
V_73 -> V_68 , & V_22 , V_74 ) ;
else
return 0 ;
}
static int F_44 ( T_1 * V_24 , struct V_80 * V_81 )
{
T_1 V_74 ;
int V_36 ;
F_11 ( L_35 ,
F_24 ( V_24 ) ) ;
V_36 = F_18 ( V_24 , V_81 -> V_25 , V_81 -> V_26 ,
& V_81 -> V_27 , V_81 -> V_29 ) ;
if ( V_36 == - V_10 || V_36 == - V_40 )
F_41 ( L_36
L_37 , V_81 -> V_82 -> V_83 ) ;
else if ( V_36 == - V_48 )
F_41 ( L_38 ) ;
else if ( V_36 == 0 && V_81 -> V_82 -> V_73 ) {
V_36 = F_38 ( V_24 , V_81 -> V_82 -> V_83 ,
V_81 -> V_82 -> V_73 , & V_81 -> V_29 -> V_22 ,
& V_74 ) ;
V_24 = & V_74 ;
}
if ( V_36 == 0 )
V_36 = F_28 ( V_24 , V_81 -> V_29 , V_81 -> V_82 -> type ) ;
return V_36 ;
}
static int F_45 ( T_1 * V_84 , struct V_80 * V_81 )
{
T_1 V_24 ;
char V_12 [ 32 ] , * V_85 ;
int V_36 = 0 ;
if ( ! F_46 ( V_81 -> V_82 -> V_83 ) ) {
V_81 -> V_29 -> V_45 = F_27 ( V_81 -> V_82 -> V_83 ) ;
if ( V_81 -> V_29 -> V_45 == NULL )
return - V_46 ;
if ( V_81 -> V_82 -> type ) {
V_81 -> V_29 -> type = F_27 ( V_81 -> V_82 -> type ) ;
if ( V_81 -> V_29 -> type == NULL )
return - V_46 ;
}
if ( V_81 -> V_82 -> V_76 ) {
V_81 -> V_29 -> V_76 = F_27 ( V_81 -> V_82 -> V_76 ) ;
if ( V_81 -> V_29 -> V_76 == NULL )
return - V_46 ;
} else
V_81 -> V_29 -> V_76 = NULL ;
return 0 ;
}
if ( V_81 -> V_82 -> V_76 )
V_81 -> V_29 -> V_76 = F_27 ( V_81 -> V_82 -> V_76 ) ;
else {
V_36 = F_47 ( V_81 -> V_82 , V_12 , 32 ) ;
if ( V_36 < 0 )
return V_36 ;
V_85 = strchr ( V_12 , ':' ) ;
if ( V_85 )
* V_85 = '_' ;
V_81 -> V_29 -> V_76 = F_27 ( V_12 ) ;
}
if ( V_81 -> V_29 -> V_76 == NULL )
return - V_46 ;
F_11 ( L_39 , V_81 -> V_82 -> V_83 ) ;
if ( ! F_48 ( V_84 , V_81 -> V_82 -> V_83 , V_81 -> V_25 , & V_24 ) ) {
if ( ! F_48 ( & V_81 -> V_86 , V_81 -> V_82 -> V_83 ,
0 , & V_24 ) ) {
F_26 ( L_40 ,
V_81 -> V_82 -> V_83 ) ;
V_36 = - V_10 ;
}
}
if ( V_36 >= 0 )
V_36 = F_44 ( & V_24 , V_81 ) ;
return V_36 ;
}
static int F_49 ( T_1 * V_27 , T_7 * V_8 ,
T_2 V_87 , bool V_88 ,
struct V_89 * V_90 )
{
T_2 V_91 , V_92 ;
T_8 V_93 ;
const char * V_94 ;
if ( F_21 ( V_27 , & V_91 ) != 0 ) {
F_26 ( L_41 ,
F_24 ( V_27 ) ) ;
return - V_10 ;
}
if ( F_23 ( V_27 , & V_92 ) != 0 ) {
F_26 ( L_42 ,
F_24 ( V_27 ) ) ;
return - V_10 ;
}
if ( V_87 > V_92 ) {
F_26 ( L_43 ,
F_24 ( V_27 ) ) ;
return - V_40 ;
}
V_94 = F_24 ( V_27 ) ;
if ( ! V_94 ) {
V_94 = F_50 ( V_8 , V_87 , & V_93 , NULL ) ;
if ( ! V_94 ) {
F_26 ( L_44 ,
( unsigned long ) V_87 ) ;
return - V_10 ;
}
V_91 = V_93 . V_95 ;
}
V_90 -> V_23 = ( unsigned long ) ( V_87 - V_91 ) ;
V_90 -> V_96 = ( unsigned long ) V_87 ;
V_90 -> V_94 = F_27 ( V_94 ) ;
if ( ! V_90 -> V_94 )
return - V_46 ;
if ( V_88 ) {
if ( V_91 != V_87 ) {
F_26 ( L_45
L_46 ) ;
return - V_40 ;
}
V_90 -> V_88 = true ;
}
return 0 ;
}
static int F_51 ( T_1 * V_84 , struct V_80 * V_81 )
{
T_4 V_97 ;
T_5 V_33 ;
int V_36 ;
if ( ! V_84 ) {
F_41 ( L_47 ) ;
return - V_40 ;
}
if ( ! F_52 ( V_84 ) ) {
if ( ! F_53 ( & V_81 -> V_86 , V_81 -> V_25 , & V_81 -> V_27 ) ) {
F_26 ( L_48
L_49 ) ;
return - V_10 ;
}
} else
memcpy ( & V_81 -> V_27 , V_84 , sizeof( T_1 ) ) ;
F_19 ( & V_81 -> V_27 , V_98 , & V_97 ) ;
V_36 = F_20 ( & V_97 , V_81 -> V_25 , & V_81 -> V_26 , & V_33 , 1 ) ;
if ( V_36 <= 0 || V_33 == 0 ) {
V_81 -> V_26 = NULL ;
#if F_54 ( 0 , 142 )
} else if ( V_33 == 1 && V_81 -> V_26 [ 0 ] . V_43 == V_99 &&
V_81 -> V_100 != NULL ) {
T_9 * V_101 ;
if ( F_55 ( V_81 -> V_100 , V_81 -> V_25 , & V_101 ) != 0 ||
F_56 ( V_101 , & V_81 -> V_26 , & V_33 ) != 0 ) {
F_26 ( L_50 ,
( V_102 ) V_81 -> V_25 ) ;
return - V_10 ;
}
#endif
}
V_36 = V_81 -> V_103 ( V_84 , V_81 ) ;
V_81 -> V_26 = NULL ;
return V_36 ;
}
static int F_57 ( T_1 * V_104 , void * V_105 )
{
struct V_106 * V_107 = V_105 ;
const char * V_108 ;
int V_109 ;
if ( V_107 -> V_108 ) {
V_108 = F_58 ( V_104 ) ;
if ( ! V_108 || strcmp ( V_107 -> V_108 , V_108 ) != 0 )
return 0 ;
}
if ( V_107 -> V_110 ) {
if ( F_34 ( V_104 , V_107 -> V_110 ) ) {
memcpy ( V_107 -> V_74 , V_104 , sizeof( T_1 ) ) ;
V_107 -> V_42 = true ;
return 1 ;
}
} else {
F_59 ( V_104 , & V_109 ) ;
if ( V_109 < V_107 -> line && V_107 -> V_111 > V_107 -> line - V_109 ) {
V_107 -> V_111 = V_107 -> line - V_109 ;
memcpy ( V_107 -> V_74 , V_104 , sizeof( T_1 ) ) ;
V_107 -> V_42 = true ;
}
}
return 0 ;
}
static T_1 * F_60 ( struct V_80 * V_81 , T_1 * V_74 )
{
struct V_106 V_107 = {
. V_110 = V_81 -> V_112 -> V_113 . V_110 ,
. V_108 = V_81 -> V_114 ,
. line = V_81 -> V_109 ,
. V_111 = V_115 ,
. V_74 = V_74 ,
. V_42 = false ,
} ;
F_61 ( & V_81 -> V_86 , V_81 -> V_25 , F_57 , & V_107 ) ;
return V_107 . V_42 ? V_74 : NULL ;
}
static int F_62 ( const char * V_114 , int V_116 ,
T_2 V_25 , void * V_105 )
{
struct V_80 * V_81 = V_105 ;
T_1 * V_84 , V_74 ;
int V_36 ;
if ( V_116 != V_81 -> V_109 || F_63 ( V_114 , V_81 -> V_114 ) != 0 )
return 0 ;
V_81 -> V_25 = V_25 ;
V_84 = F_60 ( V_81 , & V_74 ) ;
if ( ! V_84 ) {
F_26 ( L_51 ) ;
return - V_10 ;
}
V_36 = F_51 ( V_84 , V_81 ) ;
return V_36 < 0 ? V_36 : 0 ;
}
static int F_64 ( struct V_80 * V_81 )
{
return F_65 ( & V_81 -> V_86 , F_62 , V_81 ) ;
}
static int F_66 ( struct V_117 * V_118 ,
const char * V_114 , const char * V_119 )
{
T_10 * V_120 ;
char * line = NULL ;
T_5 V_121 ;
T_11 V_122 ;
int V_123 = 0 , V_124 = 1 ;
char V_60 [ V_61 ] ;
V_120 = fopen ( V_114 , L_52 ) ;
if ( ! V_120 ) {
F_26 ( L_53 , V_114 ,
F_37 ( V_125 , V_60 , sizeof( V_60 ) ) ) ;
return - V_125 ;
}
while ( ( V_122 = F_67 ( & line , & V_121 , V_120 ) ) > 0 ) {
if ( line [ V_122 - 1 ] == '\n' )
line [ V_122 - 1 ] = '\0' ;
if ( F_68 ( line , V_119 ) ) {
F_69 ( V_118 , V_124 ) ;
V_123 ++ ;
}
V_124 ++ ;
}
if ( ferror ( V_120 ) )
V_123 = - V_125 ;
free ( line ) ;
fclose ( V_120 ) ;
if ( V_123 == 0 )
F_11 ( L_54 , V_114 ) ;
return V_123 ;
}
static int F_70 ( const char * V_114 , int V_116 ,
T_2 V_25 , void * V_105 )
{
struct V_80 * V_81 = V_105 ;
T_1 * V_84 , V_74 ;
int V_36 ;
if ( ! F_71 ( V_81 -> V_126 , V_116 ) ||
F_63 ( V_114 , V_81 -> V_114 ) != 0 )
return 0 ;
F_11 ( L_55 ,
V_116 , ( unsigned long long ) V_25 ) ;
V_81 -> V_25 = V_25 ;
V_81 -> V_109 = V_116 ;
V_84 = F_60 ( V_81 , & V_74 ) ;
if ( ! V_84 ) {
F_26 ( L_51 ) ;
return - V_10 ;
}
V_36 = F_51 ( V_84 , V_81 ) ;
return V_36 < 0 ? V_36 : 0 ;
}
static int F_72 ( T_1 * V_27 , struct V_80 * V_81 )
{
int V_36 = 0 ;
char * V_127 ;
if ( F_73 ( V_81 -> V_126 ) ) {
const char * V_128 ;
V_128 = F_74 ( & V_81 -> V_86 ) ;
V_36 = F_75 ( V_81 -> V_114 , V_128 , & V_127 ) ;
if ( V_36 < 0 ) {
F_26 ( L_56 ) ;
return V_36 ;
}
V_36 = F_66 ( V_81 -> V_126 , V_127 ,
V_81 -> V_112 -> V_113 . V_129 ) ;
free ( V_127 ) ;
if ( V_36 <= 0 )
return V_36 ;
}
return F_65 ( V_27 , F_70 , V_81 ) ;
}
static int F_76 ( T_1 * V_130 , void * V_105 )
{
struct V_80 * V_81 = V_105 ;
struct V_131 * V_132 = & V_81 -> V_112 -> V_113 ;
T_2 V_25 ;
int V_36 ;
if ( V_132 -> V_129 )
V_36 = F_72 ( V_130 , V_81 ) ;
else {
if ( F_21 ( V_130 , & V_25 ) != 0 ) {
F_26 ( L_57 ,
F_24 ( V_130 ) ) ;
return - V_10 ;
}
V_81 -> V_25 = V_25 ;
V_81 -> V_25 += V_132 -> V_23 ;
F_11 ( L_58 ,
( V_102 ) V_81 -> V_25 ) ;
V_36 = F_51 ( V_130 , V_81 ) ;
}
return V_36 ;
}
static int F_77 ( T_1 * V_27 , void * V_105 )
{
struct V_133 * V_134 = V_105 ;
struct V_80 * V_81 = V_134 -> V_105 ;
struct V_131 * V_132 = & V_81 -> V_112 -> V_113 ;
if ( ! F_52 ( V_27 ) ||
! F_34 ( V_27 , V_132 -> V_110 ) )
return V_135 ;
if ( V_132 -> V_108 && F_63 ( V_132 -> V_108 , F_58 ( V_27 ) ) )
return V_135 ;
V_81 -> V_114 = F_58 ( V_27 ) ;
if ( V_132 -> line ) {
F_59 ( V_27 , & V_81 -> V_109 ) ;
V_81 -> V_109 += V_132 -> line ;
V_134 -> V_136 = F_64 ( V_81 ) ;
} else if ( F_78 ( V_27 ) ) {
F_21 ( V_27 , & V_81 -> V_25 ) ;
if ( V_132 -> V_129 )
V_134 -> V_136 = F_72 ( V_27 , V_81 ) ;
else {
V_81 -> V_25 += V_132 -> V_23 ;
V_134 -> V_136 = F_51 ( V_27 , V_81 ) ;
}
} else
V_134 -> V_136 = F_79 ( V_27 ,
F_76 , ( void * ) V_81 ) ;
return V_137 ;
}
static int F_80 ( struct V_80 * V_81 )
{
struct V_133 V_138 = { . V_105 = ( void * ) V_81 ,
. V_136 = 0 } ;
F_81 ( & V_81 -> V_86 , F_77 , & V_138 , 0 ) ;
return V_138 . V_136 ;
}
static int F_82 ( T_12 * V_2 , T_13 * V_139 , void * V_105 )
{
struct V_140 * V_134 = V_105 ;
if ( F_83 ( V_2 , V_139 -> V_141 , V_134 -> V_27 ) ) {
if ( F_22 ( V_134 -> V_27 ) != V_142 )
return V_135 ;
if ( F_34 ( V_134 -> V_27 , V_134 -> V_110 ) ) {
if ( ! F_83 ( V_2 , V_139 -> V_143 , V_134 -> V_86 ) )
return V_135 ;
if ( V_134 -> V_108 &&
F_63 ( V_134 -> V_108 , F_58 ( V_134 -> V_27 ) ) )
return V_135 ;
V_134 -> V_42 = 1 ;
return V_137 ;
}
}
return V_135 ;
}
static int F_84 ( struct V_1 * V_2 ,
struct V_80 * V_81 )
{
struct V_131 * V_132 = & V_81 -> V_112 -> V_113 ;
T_14 V_144 , V_145 ;
T_5 V_146 ;
T_1 * V_147 ;
int V_36 = 0 ;
#if F_54 ( 0 , 142 )
T_15 * V_148 ;
T_16 V_149 ;
T_17 V_150 ;
V_148 = F_85 ( V_2 -> V_2 ) ;
if ( V_148 == NULL )
return - V_40 ;
if ( F_86 ( V_148 , & V_149 ) == NULL )
return - V_40 ;
if ( F_87 ( V_148 , & V_149 , & V_150 , L_59 , NULL ) &&
V_150 . V_151 == V_152 ) {
V_81 -> V_100 = F_88 ( V_148 ) ;
} else {
V_81 -> V_100 = F_89 ( V_2 -> V_2 ) ;
}
#endif
V_144 = 0 ;
V_81 -> V_126 = F_90 ( NULL ) ;
if ( ! V_81 -> V_126 )
return - V_46 ;
if ( V_132 -> V_110 ) {
struct V_140 V_153 = {
. V_110 = V_132 -> V_110 ,
. V_108 = V_132 -> V_108 ,
. V_86 = & V_81 -> V_86 ,
. V_27 = & V_81 -> V_27 ,
. V_42 = 0 ,
} ;
struct V_133 V_154 = {
. V_105 = V_81 ,
} ;
F_91 ( V_2 -> V_2 , F_82 ,
& V_153 , 0 ) ;
if ( V_153 . V_42 ) {
V_36 = F_77 ( & V_81 -> V_27 , & V_154 ) ;
if ( V_36 )
goto V_42;
}
}
while ( ! F_92 ( V_2 -> V_2 , V_144 , & V_145 , & V_146 , NULL , NULL , NULL ) ) {
V_147 = F_83 ( V_2 -> V_2 , V_144 + V_146 , & V_81 -> V_86 ) ;
if ( ! V_147 )
continue;
if ( V_132 -> V_108 )
V_81 -> V_114 = F_93 ( & V_81 -> V_86 , V_132 -> V_108 ) ;
else
V_81 -> V_114 = NULL ;
if ( ! V_132 -> V_108 || V_81 -> V_114 ) {
if ( V_132 -> V_110 )
V_36 = F_80 ( V_81 ) ;
else if ( V_132 -> V_129 )
V_36 = F_72 ( & V_81 -> V_86 , V_81 ) ;
else {
V_81 -> V_109 = V_132 -> line ;
V_36 = F_64 ( V_81 ) ;
}
if ( V_36 < 0 )
break;
}
V_144 = V_145 ;
}
V_42:
F_94 ( V_81 -> V_126 ) ;
V_81 -> V_126 = NULL ;
return V_36 ;
}
static int F_95 ( T_1 * V_74 , void * V_105 )
{
struct V_155 * V_156 = V_105 ;
struct V_80 * V_81 = V_156 -> V_81 ;
int V_75 ;
V_75 = F_22 ( V_74 ) ;
if ( V_75 == V_41 ||
V_75 == V_157 ) {
if ( F_18 ( V_74 , V_156 -> V_81 -> V_25 ,
V_156 -> V_81 -> V_26 , & V_81 -> V_27 ,
NULL ) == 0 ) {
V_156 -> args [ V_156 -> V_158 ] . V_83 = ( char * ) F_24 ( V_74 ) ;
if ( V_156 -> args [ V_156 -> V_158 ] . V_83 == NULL ) {
V_156 -> V_36 = - V_46 ;
return V_159 ;
}
F_11 ( L_60 , V_156 -> args [ V_156 -> V_158 ] . V_83 ) ;
V_156 -> V_158 ++ ;
}
}
if ( F_96 ( V_74 , V_156 -> V_81 -> V_25 ) )
return V_160 ;
else
return V_161 ;
}
static int F_97 ( T_1 * V_84 , struct V_80 * V_81 ,
struct V_162 * args )
{
T_1 V_74 ;
int V_163 ;
int V_164 = 0 ;
struct V_155 V_156 = { . V_81 = V_81 , . args = args ,
. V_165 = V_166 , . V_36 = 0 } ;
for ( V_163 = 0 ; V_163 < V_81 -> V_112 -> V_158 ; V_163 ++ ) {
if ( strcmp ( V_81 -> V_112 -> args [ V_163 ] . V_83 , L_61 ) == 0 ) {
F_11 ( L_62 ) ;
V_156 . V_158 = V_164 ;
F_98 ( V_84 , F_95 , ( void * ) & V_156 ,
& V_74 ) ;
F_11 ( L_63 , V_156 . V_158 - V_164 ) ;
if ( V_156 . V_36 < 0 )
return V_156 . V_36 ;
V_164 = V_156 . V_158 ;
} else {
args [ V_164 ] = V_81 -> V_112 -> args [ V_163 ] ;
V_164 ++ ;
}
}
return V_164 ;
}
static int F_99 ( T_1 * V_84 , struct V_80 * V_81 )
{
struct V_167 * V_168 =
F_100 ( V_81 , struct V_167 , V_81 ) ;
struct V_169 * V_170 ;
struct V_162 * args ;
int V_36 , V_163 ;
if ( V_168 -> V_171 == V_168 -> V_172 ) {
F_26 ( L_64 ,
V_168 -> V_172 ) ;
return - V_57 ;
}
V_170 = & V_168 -> V_173 [ V_168 -> V_171 ++ ] ;
V_36 = F_49 ( & V_81 -> V_27 , V_168 -> V_8 , V_81 -> V_25 ,
V_81 -> V_112 -> V_113 . V_88 , & V_170 -> V_113 ) ;
if ( V_36 < 0 )
return V_36 ;
F_11 ( L_65 , V_170 -> V_113 . V_94 ,
V_170 -> V_113 . V_23 ) ;
args = F_9 ( sizeof( struct V_162 ) * V_166 ) ;
if ( args == NULL )
return - V_46 ;
V_36 = F_97 ( V_84 , V_81 , args ) ;
if ( V_36 < 0 )
goto V_174;
V_170 -> V_158 = V_36 ;
V_170 -> args = F_9 ( sizeof( struct V_28 ) * V_170 -> V_158 ) ;
if ( V_170 -> args == NULL ) {
V_36 = - V_46 ;
goto V_174;
}
for ( V_163 = 0 ; V_163 < V_170 -> V_158 ; V_163 ++ ) {
V_81 -> V_82 = & args [ V_163 ] ;
V_81 -> V_29 = & V_170 -> args [ V_163 ] ;
V_36 = F_45 ( V_84 , V_81 ) ;
if ( V_36 != 0 )
break;
}
V_174:
free ( args ) ;
return V_36 ;
}
int F_101 ( struct V_1 * V_2 ,
struct V_175 * V_112 ,
struct V_169 * * V_173 , int V_172 )
{
struct V_167 V_168 = {
. V_81 = { . V_112 = V_112 , . V_103 = F_99 } ,
. V_8 = V_2 -> V_8 , . V_172 = V_172 } ;
int V_36 ;
* V_173 = F_9 ( sizeof( struct V_169 ) * V_172 ) ;
if ( * V_173 == NULL )
return - V_46 ;
V_168 . V_173 = * V_173 ;
V_168 . V_171 = 0 ;
V_36 = F_84 ( V_2 , & V_168 . V_81 ) ;
if ( V_36 < 0 ) {
F_10 ( V_173 ) ;
return V_36 ;
}
return ( V_36 < 0 ) ? V_36 : V_168 . V_171 ;
}
static int F_102 ( T_1 * V_74 , void * V_105 )
{
struct V_176 * V_177 = V_105 ;
struct V_178 * V_179 ;
char V_12 [ V_180 ] ;
int V_75 , V_36 ;
V_179 = & V_177 -> V_181 [ V_177 -> V_182 - 1 ] ;
V_75 = F_22 ( V_74 ) ;
if ( V_75 == V_41 ||
V_75 == V_157 ) {
V_36 = F_18 ( V_74 , V_177 -> V_81 . V_25 ,
V_177 -> V_81 . V_26 , & V_177 -> V_81 . V_27 ,
NULL ) ;
if ( V_36 == 0 ) {
V_36 = F_103 ( V_74 , V_12 , V_180 ) ;
F_39 ( L_66 , V_12 ) ;
if ( V_36 > 0 )
F_104 ( V_179 -> V_183 , V_12 ) ;
}
}
if ( V_177 -> V_184 && F_96 ( V_74 , V_177 -> V_81 . V_25 ) )
return V_160 ;
else
return V_161 ;
}
static int F_105 ( T_1 * V_84 , struct V_80 * V_81 )
{
struct V_176 * V_177 =
F_100 ( V_81 , struct V_176 , V_81 ) ;
struct V_178 * V_179 ;
T_1 V_74 ;
int V_36 ;
if ( V_177 -> V_182 == V_177 -> V_185 ) {
F_26 ( L_64 , V_177 -> V_185 ) ;
return - V_57 ;
}
V_179 = & V_177 -> V_181 [ V_177 -> V_182 ++ ] ;
V_36 = F_49 ( & V_81 -> V_27 , V_177 -> V_8 , V_81 -> V_25 ,
V_81 -> V_112 -> V_113 . V_88 , & V_179 -> V_113 ) ;
if ( V_36 < 0 )
return V_36 ;
F_11 ( L_65 , V_179 -> V_113 . V_94 ,
V_179 -> V_113 . V_23 ) ;
V_179 -> V_183 = F_106 ( true , NULL ) ;
if ( V_179 -> V_183 == NULL )
return - V_46 ;
V_177 -> V_184 = true ;
F_98 ( V_84 , F_102 , ( void * ) V_177 , & V_74 ) ;
if ( ! V_177 -> V_186 )
goto V_17;
V_177 -> V_184 = false ;
F_98 ( & V_81 -> V_86 , F_102 , ( void * ) V_177 , & V_74 ) ;
V_17:
if ( F_107 ( V_179 -> V_183 ) ) {
F_108 ( V_179 -> V_183 ) ;
V_179 -> V_183 = NULL ;
}
return V_36 ;
}
int F_109 ( struct V_1 * V_2 ,
struct V_175 * V_112 ,
struct V_178 * * V_181 ,
int V_185 , bool V_186 )
{
struct V_176 V_177 = {
. V_81 = { . V_112 = V_112 , . V_103 = F_105 } ,
. V_8 = V_2 -> V_8 ,
. V_185 = V_185 , . V_186 = V_186 } ;
int V_36 ;
* V_181 = F_9 ( sizeof( struct V_178 ) * V_185 ) ;
if ( * V_181 == NULL )
return - V_46 ;
V_177 . V_181 = * V_181 ;
V_177 . V_182 = 0 ;
V_36 = F_84 ( V_2 , & V_177 . V_81 ) ;
if ( V_36 < 0 ) {
while ( V_177 . V_182 -- ) {
F_10 ( & V_177 . V_181 [ V_177 . V_182 ] . V_113 . V_94 ) ;
F_108 ( V_177 . V_181 [ V_177 . V_182 ] . V_183 ) ;
}
F_10 ( V_181 ) ;
return V_36 ;
}
return ( V_36 < 0 ) ? V_36 : V_177 . V_182 ;
}
int F_110 ( struct V_1 * V_2 , unsigned long V_25 ,
struct V_131 * V_187 )
{
T_1 V_188 , V_189 , V_190 ;
T_2 V_191 = 0 , V_192 = 0 ;
const char * V_114 = NULL , * V_193 = NULL , * V_194 = NULL , * V_31 ;
int V_195 = 0 , V_116 = 0 , V_36 = 0 ;
if ( ! F_111 ( V_2 -> V_2 , ( T_2 ) V_25 , & V_188 ) ) {
F_26 ( L_67 ,
V_25 ) ;
V_36 = - V_40 ;
goto V_174;
}
F_112 ( & V_188 , V_25 , & V_114 , & V_116 ) ;
if ( F_53 ( & V_188 , ( T_2 ) V_25 , & V_189 ) ) {
V_193 = V_194 = F_24 ( & V_189 ) ;
if ( ! V_193 ||
F_21 ( & V_189 , & V_192 ) != 0 ||
F_59 ( & V_189 , & V_195 ) != 0 ) {
V_116 = 0 ;
goto V_196;
}
V_114 = F_58 ( & V_189 ) ;
if ( V_25 == ( unsigned long ) V_192 ) {
V_116 = V_195 ;
goto V_196;
}
while ( F_113 ( & V_189 , ( T_2 ) V_25 ,
& V_190 ) ) {
if ( F_21 ( & V_190 , & V_191 ) == 0 &&
V_191 == V_25 ) {
V_116 = F_114 ( & V_190 ) ;
V_114 = F_115 ( & V_190 ) ;
break;
} else {
V_31 = F_24 ( & V_190 ) ;
if ( ! V_31 ||
F_59 ( & V_190 , & V_195 ) != 0 )
break;
V_193 = V_31 ;
V_189 = V_190 ;
}
}
V_31 = F_58 ( & V_189 ) ;
if ( ! V_31 || strcmp ( V_31 , V_114 ) != 0 )
V_116 = 0 ;
}
V_196:
if ( V_116 )
V_187 -> line = V_116 - V_195 ;
else if ( V_194 ) {
V_187 -> V_23 = V_25 - ( unsigned long ) V_192 ;
V_193 = V_194 ;
}
if ( V_193 ) {
V_187 -> V_110 = F_27 ( V_193 ) ;
if ( V_187 -> V_110 == NULL ) {
V_36 = - V_46 ;
goto V_174;
}
}
if ( V_114 ) {
V_187 -> V_108 = F_27 ( V_114 ) ;
if ( V_187 -> V_108 == NULL ) {
F_10 ( & V_187 -> V_110 ) ;
V_36 = - V_46 ;
goto V_174;
}
}
V_174:
if ( V_36 == 0 && ( V_114 || V_193 ) )
V_36 = 1 ;
return V_36 ;
}
static int F_116 ( const char * V_197 , unsigned int V_116 ,
struct V_198 * V_199 )
{
if ( ! V_199 -> V_3 ) {
V_199 -> V_3 = F_27 ( V_197 ) ;
if ( V_199 -> V_3 == NULL )
return - V_46 ;
}
return F_69 ( V_199 -> V_200 , V_116 ) ;
}
static int F_117 ( const char * V_114 , int V_116 ,
T_2 V_25 V_201 ,
void * V_105 )
{
struct V_202 * V_203 = V_105 ;
int V_204 ;
if ( ( F_63 ( V_114 , V_203 -> V_114 ) != 0 ) ||
( V_203 -> V_205 > V_116 || V_203 -> V_206 < V_116 ) )
return 0 ;
V_204 = F_116 ( V_114 , V_116 , V_203 -> V_199 ) ;
if ( V_204 < 0 && V_204 != - V_207 )
return V_204 ;
return 0 ;
}
static int F_118 ( T_1 * V_27 , struct V_202 * V_203 )
{
int V_36 ;
V_36 = F_65 ( V_27 ? : & V_203 -> V_86 , F_117 , V_203 ) ;
if ( V_36 >= 0 )
if ( ! F_73 ( V_203 -> V_199 -> V_200 ) )
V_36 = V_203 -> V_42 = 1 ;
else
V_36 = 0 ;
else {
F_10 ( & V_203 -> V_199 -> V_3 ) ;
}
return V_36 ;
}
static int F_119 ( T_1 * V_130 , void * V_105 )
{
int V_36 = F_118 ( V_130 , V_105 ) ;
return V_36 < 0 ? V_36 : 0 ;
}
static int F_120 ( T_1 * V_27 , void * V_105 )
{
struct V_133 * V_134 = V_105 ;
struct V_202 * V_203 = V_134 -> V_105 ;
struct V_198 * V_199 = V_203 -> V_199 ;
if ( V_199 -> V_108 && F_63 ( V_199 -> V_108 , F_58 ( V_27 ) ) )
return V_135 ;
if ( F_52 ( V_27 ) &&
F_34 ( V_27 , V_199 -> V_110 ) ) {
V_203 -> V_114 = F_58 ( V_27 ) ;
F_59 ( V_27 , & V_199 -> V_23 ) ;
F_11 ( L_68 , V_203 -> V_114 , V_199 -> V_23 ) ;
V_203 -> V_205 = V_199 -> V_23 + V_199 -> V_208 ;
if ( V_203 -> V_205 < 0 )
V_203 -> V_205 = V_115 ;
V_203 -> V_206 = V_199 -> V_23 + V_199 -> V_174 ;
if ( V_203 -> V_206 < 0 )
V_203 -> V_206 = V_115 ;
F_11 ( L_69 , V_203 -> V_205 , V_203 -> V_206 ) ;
V_199 -> V_208 = V_203 -> V_205 ;
V_199 -> V_174 = V_203 -> V_206 ;
if ( ! F_78 ( V_27 ) )
V_134 -> V_136 = F_79 ( V_27 ,
F_119 , V_203 ) ;
else
V_134 -> V_136 = F_118 ( V_27 , V_203 ) ;
return V_137 ;
}
return V_135 ;
}
static int F_121 ( struct V_202 * V_203 )
{
struct V_133 V_134 = { . V_105 = ( void * ) V_203 , . V_136 = 0 } ;
F_81 ( & V_203 -> V_86 , F_120 , & V_134 , 0 ) ;
return V_134 . V_136 ;
}
int F_122 ( struct V_1 * V_2 , struct V_198 * V_199 )
{
struct V_202 V_203 = { . V_199 = V_199 , . V_42 = 0 } ;
int V_36 = 0 ;
T_14 V_144 = 0 , V_145 ;
T_5 V_146 ;
T_1 * V_147 ;
const char * V_128 ;
if ( V_199 -> V_110 ) {
struct V_140 V_153 = {
. V_110 = V_199 -> V_110 , . V_108 = V_199 -> V_108 ,
. V_86 = & V_203 . V_86 , . V_27 = & V_203 . V_27 , . V_42 = 0 } ;
struct V_133 V_209 = {
. V_105 = ( void * ) & V_203 , . V_136 = 0 } ;
F_91 ( V_2 -> V_2 , F_82 ,
& V_153 , 0 ) ;
if ( V_153 . V_42 ) {
F_120 ( & V_203 . V_27 , & V_209 ) ;
if ( V_203 . V_42 )
goto V_42;
}
}
while ( ! V_203 . V_42 && V_36 >= 0 ) {
if ( F_92 ( V_2 -> V_2 , V_144 , & V_145 , & V_146 ,
NULL , NULL , NULL ) != 0 )
break;
V_147 = F_83 ( V_2 -> V_2 , V_144 + V_146 , & V_203 . V_86 ) ;
if ( ! V_147 )
continue;
if ( V_199 -> V_108 )
V_203 . V_114 = F_93 ( & V_203 . V_86 , V_199 -> V_108 ) ;
else
V_203 . V_114 = 0 ;
if ( ! V_199 -> V_108 || V_203 . V_114 ) {
if ( V_199 -> V_110 )
V_36 = F_121 ( & V_203 ) ;
else {
V_203 . V_205 = V_199 -> V_208 ;
V_203 . V_206 = V_199 -> V_174 ;
V_36 = F_118 ( NULL , & V_203 ) ;
}
}
V_144 = V_145 ;
}
V_42:
if ( V_203 . V_42 ) {
V_128 = F_74 ( & V_203 . V_86 ) ;
if ( V_128 ) {
V_199 -> V_128 = F_27 ( V_128 ) ;
if ( ! V_199 -> V_128 )
V_36 = - V_46 ;
}
}
F_11 ( L_70 , V_199 -> V_3 ) ;
return ( V_36 < 0 ) ? V_36 : V_203 . V_42 ;
}
int F_75 ( const char * V_210 , const char * V_128 ,
char * * V_211 )
{
const char * V_212 = V_213 . V_214 ;
if ( ! V_212 ) {
if ( V_210 [ 0 ] != '/' && V_128 )
V_212 = V_128 ;
else {
if ( F_123 ( V_210 , V_215 ) == 0 ) {
* V_211 = F_27 ( V_210 ) ;
return * V_211 ? 0 : - V_46 ;
} else
return - V_125 ;
}
}
* V_211 = malloc ( ( strlen ( V_212 ) + strlen ( V_210 ) + 2 ) ) ;
if ( ! * V_211 )
return - V_46 ;
for (; ; ) {
sprintf ( * V_211 , L_71 , V_212 , V_210 ) ;
if ( F_123 ( * V_211 , V_215 ) == 0 )
return 0 ;
if ( ! V_213 . V_214 ) {
F_10 ( V_211 ) ;
return - V_125 ;
}
switch ( V_125 ) {
case V_216 :
case V_10 :
case V_217 :
case V_218 :
V_210 = strchr ( ++ V_210 , '/' ) ;
if ( ! V_210 ) {
F_10 ( V_211 ) ;
return - V_10 ;
}
continue;
default:
F_10 ( V_211 ) ;
return - V_125 ;
}
}
}
