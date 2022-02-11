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
int V_36 , V_37 = 0 ;
if ( F_19 ( V_24 , V_38 , & V_30 ) != NULL )
goto V_39;
if ( F_19 ( V_24 , V_40 , & V_30 ) == NULL )
return - V_41 ;
if ( F_20 ( & V_30 , V_25 , & V_32 , & V_33 , 1 ) <= 0 ) {
V_36 = F_21 ( V_27 , & V_31 ) ;
if ( V_36 )
return - V_10 ;
if ( V_42 . V_43 &&
( F_22 ( V_24 ) == V_44 ) ) {
V_37 = - V_45 ;
} else if ( V_25 != V_31 ||
F_22 ( V_24 ) != V_46 ) {
return - V_10 ;
}
V_36 = F_23 ( V_27 , & V_31 ) ;
if ( V_36 )
return - V_10 ;
for ( V_25 += 1 ; V_25 <= V_31 ; V_25 ++ ) {
if ( F_20 ( & V_30 , V_25 , & V_32 ,
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
V_36 = strlen ( F_24 ( V_24 ) ) ;
V_29 -> V_50 = F_9 ( V_36 + 2 ) ;
if ( V_29 -> V_50 == NULL )
return - V_51 ;
snprintf ( V_29 -> V_50 , V_36 + 2 , L_3 , F_24 ( V_24 ) ) ;
V_29 -> V_22 = F_17 ( ( long ) V_21 ) ;
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
F_11 ( L_4 , V_32 -> V_48 ) ;
return - V_53 ;
}
if ( ! V_29 )
return V_37 ;
V_35 = F_25 ( V_34 ) ;
if ( ! V_35 ) {
F_26 ( L_5
L_6 , V_34 ) ;
return - V_53 ;
}
V_29 -> V_50 = F_27 ( V_35 ) ;
if ( V_29 -> V_50 == NULL )
return - V_51 ;
if ( V_22 ) {
V_29 -> V_22 = F_17 ( ( long ) V_21 ) ;
if ( V_29 -> V_22 == NULL )
return - V_51 ;
}
return V_37 ;
}
static int F_28 ( T_1 * V_24 ,
struct V_28 * V_29 ,
const char * V_62 )
{
struct V_20 * * V_63 = & V_29 -> V_22 ;
T_1 type ;
char V_12 [ 16 ] ;
char V_64 [ V_65 ] ;
int V_66 , V_67 , V_68 ;
int V_36 ;
if ( V_62 && strcmp ( V_62 , L_7 ) != 0 ) {
V_29 -> type = F_27 ( V_62 ) ;
return ( V_29 -> type == NULL ) ? - V_51 : 0 ;
}
V_66 = F_29 ( V_24 ) ;
if ( V_66 > 0 ) {
V_67 = F_30 ( V_24 ) ;
V_68 = F_31 ( V_24 ) ;
if ( V_67 < 0 || V_68 < 0 )
return - V_10 ;
V_36 = snprintf ( V_12 , 16 , L_8 , V_66 , V_67 ,
F_32 ( V_68 ) ) ;
goto V_69;
}
if ( F_33 ( V_24 , & type ) == NULL ) {
F_26 ( L_9 ,
F_24 ( V_24 ) ) ;
return - V_10 ;
}
F_11 ( L_10 ,
F_24 ( V_24 ) , F_24 ( & type ) ) ;
if ( V_62 && strcmp ( V_62 , L_7 ) == 0 ) {
V_36 = F_22 ( & type ) ;
if ( V_36 != V_70 &&
V_36 != V_71 ) {
F_26 ( L_11
L_12 ,
F_24 ( V_24 ) , F_24 ( & type ) ) ;
return - V_41 ;
}
if ( F_33 ( & type , & type ) == NULL ) {
F_26 ( L_13
L_14 ) ;
return - V_10 ;
}
if ( V_36 == V_70 ) {
while ( * V_63 )
V_63 = & ( * V_63 ) -> V_72 ;
* V_63 = F_9 ( sizeof( struct V_20 ) ) ;
if ( * V_63 == NULL ) {
F_26 ( L_15 ) ;
return - V_51 ;
}
}
if ( ! F_34 ( & type , L_16 ) &&
! F_34 ( & type , L_17 ) ) {
F_26 ( L_11
L_18 ,
F_24 ( V_24 ) ) ;
return - V_41 ;
}
V_29 -> type = F_27 ( V_62 ) ;
return ( V_29 -> type == NULL ) ? - V_51 : 0 ;
}
V_36 = F_31 ( & type ) ;
if ( V_36 <= 0 )
return 0 ;
V_36 = F_32 ( V_36 ) ;
if ( V_36 > V_73 ) {
F_35 ( L_19 ,
F_24 ( & type ) , V_73 ) ;
V_36 = V_73 ;
}
V_36 = snprintf ( V_12 , 16 , L_20 ,
F_36 ( & type ) ? 's' : 'u' , V_36 ) ;
V_69:
if ( V_36 < 0 || V_36 >= 16 ) {
if ( V_36 >= 16 )
V_36 = - V_74 ;
F_26 ( L_21 ,
F_37 ( - V_36 , V_64 , sizeof( V_64 ) ) ) ;
return V_36 ;
}
V_29 -> type = F_27 ( V_12 ) ;
if ( V_29 -> type == NULL )
return - V_51 ;
return 0 ;
}
static int F_38 ( T_1 * V_24 , const char * V_75 ,
struct V_76 * V_77 ,
struct V_20 * * V_63 ,
T_1 * V_78 )
{
struct V_20 * V_22 = * V_63 ;
T_1 type ;
T_6 V_21 ;
int V_36 , V_79 ;
F_11 ( L_22 , V_77 -> V_80 , V_75 ) ;
if ( F_33 ( V_24 , & type ) == NULL ) {
F_26 ( L_23 , V_75 ) ;
return - V_10 ;
}
F_39 ( L_24 , ( unsigned ) F_40 ( & type ) ) ;
V_79 = F_22 ( & type ) ;
if ( V_77 -> V_80 [ 0 ] == '[' &&
( V_79 == V_71 || V_79 == V_70 ) ) {
if ( V_77 -> V_72 )
memcpy ( V_78 , & type , sizeof( * V_78 ) ) ;
if ( F_33 ( & type , & type ) == NULL ) {
F_26 ( L_23 , V_75 ) ;
return - V_10 ;
}
F_39 ( L_25 ,
( unsigned ) F_40 ( & type ) ) ;
if ( V_79 == V_70 ) {
V_22 = F_9 ( sizeof( struct V_20 ) ) ;
if ( V_22 == NULL )
return - V_51 ;
if ( * V_63 )
( * V_63 ) -> V_72 = V_22 ;
else
* V_63 = V_22 ;
}
V_22 -> V_23 += F_31 ( & type ) * V_77 -> V_81 ;
if ( ! V_77 -> V_72 )
memcpy ( V_78 , V_24 , sizeof( * V_78 ) ) ;
goto V_72;
} else if ( V_79 == V_70 ) {
if ( ! V_77 -> V_22 ) {
F_41 ( L_26 ,
V_77 -> V_80 ) ;
return - V_41 ;
}
if ( F_33 ( & type , & type ) == NULL ) {
F_26 ( L_23 , V_75 ) ;
return - V_10 ;
}
V_79 = F_22 ( & type ) ;
if ( V_79 != V_82 && V_79 != V_83 ) {
F_26 ( L_27 ,
V_75 ) ;
return - V_41 ;
}
V_22 = F_9 ( sizeof( struct V_20 ) ) ;
if ( V_22 == NULL )
return - V_51 ;
if ( * V_63 )
( * V_63 ) -> V_72 = V_22 ;
else
* V_63 = V_22 ;
} else {
if ( V_79 != V_82 && V_79 != V_83 ) {
F_26 ( L_27 ,
V_75 ) ;
return - V_41 ;
}
if ( V_77 -> V_80 [ 0 ] == '[' ) {
F_41 ( L_28
L_29 , V_75 ) ;
return - V_41 ;
}
if ( V_77 -> V_22 && F_24 ( V_24 ) ) {
F_41 ( L_30 ,
V_77 -> V_80 ) ;
return - V_41 ;
}
if ( ! V_22 ) {
F_26 ( L_31
L_32 ) ;
return - V_53 ;
}
}
if ( F_42 ( & type , V_77 -> V_80 , V_78 ) == NULL ) {
F_26 ( L_33 , V_75 ,
F_24 ( & type ) , V_77 -> V_80 ) ;
return - V_41 ;
}
if ( V_79 == V_83 ) {
V_21 = 0 ;
} else {
V_36 = F_43 ( V_78 , & V_21 ) ;
if ( V_36 < 0 ) {
F_26 ( L_34 ,
V_77 -> V_80 ) ;
return V_36 ;
}
}
V_22 -> V_23 += ( long ) V_21 ;
if ( ! F_24 ( V_78 ) )
return F_38 ( V_78 , V_75 , V_77 ,
& V_22 , V_78 ) ;
V_72:
if ( V_77 -> V_72 )
return F_38 ( V_78 , V_77 -> V_80 ,
V_77 -> V_72 , & V_22 , V_78 ) ;
else
return 0 ;
}
static int F_44 ( T_1 * V_24 , struct V_84 * V_85 )
{
T_1 V_78 ;
int V_36 ;
F_11 ( L_35 ,
F_24 ( V_24 ) ) ;
V_36 = F_18 ( V_24 , V_85 -> V_25 , V_85 -> V_26 ,
& V_85 -> V_27 , V_85 -> V_29 ) ;
if ( V_36 == - V_10 || V_36 == - V_41 ) {
F_41 ( L_36
L_37
L_38 ,
V_85 -> V_86 -> V_87 , V_85 -> V_86 -> V_87 ) ;
} else if ( V_36 == - V_53 )
F_41 ( L_39 ) ;
else if ( V_36 == 0 && V_85 -> V_86 -> V_77 ) {
V_36 = F_38 ( V_24 , V_85 -> V_86 -> V_87 ,
V_85 -> V_86 -> V_77 , & V_85 -> V_29 -> V_22 ,
& V_78 ) ;
V_24 = & V_78 ;
}
if ( V_36 == 0 )
V_36 = F_28 ( V_24 , V_85 -> V_29 , V_85 -> V_86 -> type ) ;
return V_36 ;
}
static int F_45 ( T_1 * V_88 , struct V_84 * V_85 )
{
T_1 V_24 ;
char V_12 [ 32 ] , * V_89 ;
int V_36 = 0 ;
if ( ! F_46 ( V_85 -> V_86 -> V_87 ) ) {
V_85 -> V_29 -> V_50 = F_27 ( V_85 -> V_86 -> V_87 ) ;
if ( V_85 -> V_29 -> V_50 == NULL )
return - V_51 ;
if ( V_85 -> V_86 -> type ) {
V_85 -> V_29 -> type = F_27 ( V_85 -> V_86 -> type ) ;
if ( V_85 -> V_29 -> type == NULL )
return - V_51 ;
}
if ( V_85 -> V_86 -> V_80 ) {
V_85 -> V_29 -> V_80 = F_27 ( V_85 -> V_86 -> V_80 ) ;
if ( V_85 -> V_29 -> V_80 == NULL )
return - V_51 ;
} else
V_85 -> V_29 -> V_80 = NULL ;
return 0 ;
}
if ( V_85 -> V_86 -> V_80 )
V_85 -> V_29 -> V_80 = F_27 ( V_85 -> V_86 -> V_80 ) ;
else {
V_36 = F_47 ( V_85 -> V_86 , V_12 , 32 ) ;
if ( V_36 < 0 )
return V_36 ;
V_89 = strchr ( V_12 , ':' ) ;
if ( V_89 )
* V_89 = '_' ;
V_85 -> V_29 -> V_80 = F_27 ( V_12 ) ;
}
if ( V_85 -> V_29 -> V_80 == NULL )
return - V_51 ;
F_11 ( L_40 , V_85 -> V_86 -> V_87 ) ;
if ( ! F_48 ( V_88 , V_85 -> V_86 -> V_87 , V_85 -> V_25 , & V_24 ) ) {
if ( ! F_48 ( & V_85 -> V_90 , V_85 -> V_86 -> V_87 ,
0 , & V_24 ) ) {
F_26 ( L_41 ,
V_85 -> V_86 -> V_87 ) ;
V_36 = - V_10 ;
}
}
if ( V_36 >= 0 )
V_36 = F_44 ( & V_24 , V_85 ) ;
return V_36 ;
}
static int F_49 ( T_1 * V_27 , T_7 * V_8 ,
T_2 V_91 , bool V_92 ,
struct V_93 * V_94 )
{
T_2 V_95 , V_96 ;
T_8 V_97 ;
const char * V_98 ;
if ( F_21 ( V_27 , & V_95 ) != 0 ) {
F_26 ( L_42 ,
F_24 ( V_27 ) ) ;
return - V_10 ;
}
if ( F_23 ( V_27 , & V_96 ) != 0 ) {
F_26 ( L_43 ,
F_24 ( V_27 ) ) ;
return - V_10 ;
}
if ( V_91 > V_96 ) {
F_26 ( L_44 ,
F_24 ( V_27 ) ) ;
return - V_41 ;
}
V_98 = F_24 ( V_27 ) ;
if ( ! V_98 ) {
V_98 = F_50 ( V_8 , V_91 , & V_97 , NULL ) ;
if ( ! V_98 ) {
F_26 ( L_45 ,
( unsigned long ) V_91 ) ;
return - V_10 ;
}
V_95 = V_97 . V_99 ;
}
V_94 -> V_23 = ( unsigned long ) ( V_91 - V_95 ) ;
V_94 -> V_100 = ( unsigned long ) V_91 ;
V_94 -> V_98 = F_27 ( V_98 ) ;
if ( ! V_94 -> V_98 )
return - V_51 ;
if ( V_92 ) {
if ( V_95 != V_91 ) {
F_26 ( L_46
L_47 ) ;
return - V_41 ;
}
V_94 -> V_92 = true ;
}
return 0 ;
}
static int F_51 ( T_1 * V_88 , struct V_84 * V_85 )
{
T_4 V_101 ;
T_5 V_33 ;
int V_36 ;
if ( ! V_88 ) {
F_41 ( L_48 ) ;
return - V_41 ;
}
if ( ! F_52 ( V_88 ) ) {
if ( ! F_53 ( & V_85 -> V_90 , V_85 -> V_25 , & V_85 -> V_27 ) ) {
if ( F_54 ( & V_85 -> V_90 , V_85 -> V_25 , & V_85 -> V_27 ) ) {
F_26 ( L_49 ,
F_24 ( & V_85 -> V_27 ) ) ;
return 0 ;
} else {
F_26 ( L_50
L_51 ) ;
return - V_10 ;
}
}
} else
memcpy ( & V_85 -> V_27 , V_88 , sizeof( T_1 ) ) ;
F_19 ( & V_85 -> V_27 , V_102 , & V_101 ) ;
V_36 = F_20 ( & V_101 , V_85 -> V_25 , & V_85 -> V_26 , & V_33 , 1 ) ;
if ( V_36 <= 0 || V_33 == 0 ) {
V_85 -> V_26 = NULL ;
#if F_55 ( 0 , 142 )
} else if ( V_33 == 1 && V_85 -> V_26 [ 0 ] . V_48 == V_103 &&
V_85 -> V_104 != NULL ) {
T_9 * V_105 ;
if ( F_56 ( V_85 -> V_104 , V_85 -> V_25 , & V_105 ) != 0 ||
F_57 ( V_105 , & V_85 -> V_26 , & V_33 ) != 0 ) {
F_26 ( L_52 ,
( V_106 ) V_85 -> V_25 ) ;
return - V_10 ;
}
#endif
}
V_36 = V_85 -> V_107 ( V_88 , V_85 ) ;
V_85 -> V_26 = NULL ;
return V_36 ;
}
static int F_58 ( T_1 * V_108 , void * V_109 )
{
struct V_110 * V_111 = V_109 ;
const char * V_112 ;
int V_113 ;
if ( V_111 -> V_112 ) {
V_112 = F_59 ( V_108 ) ;
if ( ! V_112 || strcmp ( V_111 -> V_112 , V_112 ) != 0 )
return 0 ;
}
if ( V_111 -> V_114 ) {
if ( F_60 ( V_108 , V_111 -> V_114 ) ) {
memcpy ( V_111 -> V_78 , V_108 , sizeof( T_1 ) ) ;
V_111 -> V_47 = true ;
return 1 ;
}
} else {
F_61 ( V_108 , & V_113 ) ;
if ( V_113 < V_111 -> line && V_111 -> V_115 > V_111 -> line - V_113 ) {
V_111 -> V_115 = V_111 -> line - V_113 ;
memcpy ( V_111 -> V_78 , V_108 , sizeof( T_1 ) ) ;
V_111 -> V_47 = true ;
}
}
return 0 ;
}
static T_1 * F_62 ( struct V_84 * V_85 , T_1 * V_78 )
{
struct V_110 V_111 = {
. V_114 = V_85 -> V_116 -> V_117 . V_114 ,
. V_112 = V_85 -> V_118 ,
. line = V_85 -> V_113 ,
. V_115 = V_119 ,
. V_78 = V_78 ,
. V_47 = false ,
} ;
F_63 ( & V_85 -> V_90 , V_85 -> V_25 , F_58 , & V_111 ) ;
return V_111 . V_47 ? V_78 : NULL ;
}
static int F_64 ( const char * V_118 , int V_120 ,
T_2 V_25 , void * V_109 )
{
struct V_84 * V_85 = V_109 ;
T_1 * V_88 , V_78 ;
int V_36 ;
if ( V_120 != V_85 -> V_113 || F_65 ( V_118 , V_85 -> V_118 ) != 0 )
return 0 ;
V_85 -> V_25 = V_25 ;
V_88 = F_62 ( V_85 , & V_78 ) ;
if ( ! V_88 ) {
F_26 ( L_53 ) ;
return - V_10 ;
}
V_36 = F_51 ( V_88 , V_85 ) ;
return V_36 < 0 ? V_36 : 0 ;
}
static int F_66 ( struct V_84 * V_85 )
{
return F_67 ( & V_85 -> V_90 , F_64 , V_85 ) ;
}
static int F_68 ( struct V_121 * V_122 ,
const char * V_118 , const char * V_123 )
{
T_10 * V_124 ;
char * line = NULL ;
T_5 V_125 ;
T_11 V_126 ;
int V_127 = 0 , V_128 = 1 ;
char V_64 [ V_65 ] ;
V_124 = fopen ( V_118 , L_54 ) ;
if ( ! V_124 ) {
F_26 ( L_55 , V_118 ,
F_37 ( V_129 , V_64 , sizeof( V_64 ) ) ) ;
return - V_129 ;
}
while ( ( V_126 = F_69 ( & line , & V_125 , V_124 ) ) > 0 ) {
if ( line [ V_126 - 1 ] == '\n' )
line [ V_126 - 1 ] = '\0' ;
if ( F_70 ( line , V_123 ) ) {
F_71 ( V_122 , V_128 ) ;
V_127 ++ ;
}
V_128 ++ ;
}
if ( ferror ( V_124 ) )
V_127 = - V_129 ;
free ( line ) ;
fclose ( V_124 ) ;
if ( V_127 == 0 )
F_11 ( L_56 , V_118 ) ;
return V_127 ;
}
static int F_72 ( const char * V_118 , int V_120 ,
T_2 V_25 , void * V_109 )
{
struct V_84 * V_85 = V_109 ;
T_1 * V_88 , V_78 ;
int V_36 ;
if ( ! F_73 ( V_85 -> V_130 , V_120 ) ||
F_65 ( V_118 , V_85 -> V_118 ) != 0 )
return 0 ;
F_11 ( L_57 ,
V_120 , ( unsigned long long ) V_25 ) ;
V_85 -> V_25 = V_25 ;
V_85 -> V_113 = V_120 ;
V_88 = F_62 ( V_85 , & V_78 ) ;
if ( ! V_88 ) {
F_26 ( L_53 ) ;
return - V_10 ;
}
V_36 = F_51 ( V_88 , V_85 ) ;
return V_36 < 0 ? V_36 : 0 ;
}
static int F_74 ( T_1 * V_27 , struct V_84 * V_85 )
{
int V_36 = 0 ;
char * V_131 ;
if ( F_75 ( V_85 -> V_130 ) ) {
const char * V_132 ;
V_132 = F_76 ( & V_85 -> V_90 ) ;
V_36 = F_77 ( V_85 -> V_118 , V_132 , & V_131 ) ;
if ( V_36 < 0 ) {
F_26 ( L_58 ) ;
return V_36 ;
}
V_36 = F_68 ( V_85 -> V_130 , V_131 ,
V_85 -> V_116 -> V_117 . V_133 ) ;
free ( V_131 ) ;
if ( V_36 <= 0 )
return V_36 ;
}
return F_67 ( V_27 , F_72 , V_85 ) ;
}
static int F_78 ( T_1 * V_134 , void * V_109 )
{
struct V_84 * V_85 = V_109 ;
struct V_135 * V_136 = & V_85 -> V_116 -> V_117 ;
T_2 V_25 ;
int V_36 ;
if ( V_136 -> V_133 )
V_36 = F_74 ( V_134 , V_85 ) ;
else {
if ( F_21 ( V_134 , & V_25 ) != 0 ) {
F_26 ( L_59 ,
F_24 ( V_134 ) ) ;
return - V_10 ;
}
V_85 -> V_25 = V_25 ;
V_85 -> V_25 += V_136 -> V_23 ;
F_11 ( L_60 ,
( V_106 ) V_85 -> V_25 ) ;
V_36 = F_51 ( V_134 , V_85 ) ;
}
return V_36 ;
}
static int F_79 ( T_1 * V_27 , void * V_109 )
{
struct V_137 * V_138 = V_109 ;
struct V_84 * V_85 = V_138 -> V_109 ;
struct V_135 * V_136 = & V_85 -> V_116 -> V_117 ;
if ( ! F_52 ( V_27 ) ||
! F_60 ( V_27 , V_136 -> V_114 ) )
return V_139 ;
if ( V_136 -> V_112 && F_65 ( V_136 -> V_112 , F_59 ( V_27 ) ) )
return V_139 ;
F_11 ( L_61 , F_24 ( V_27 ) ) ;
V_85 -> V_118 = F_59 ( V_27 ) ;
if ( V_136 -> line ) {
F_61 ( V_27 , & V_85 -> V_113 ) ;
V_85 -> V_113 += V_136 -> line ;
V_138 -> V_140 = F_66 ( V_85 ) ;
} else if ( F_80 ( V_27 ) ) {
F_21 ( V_27 , & V_85 -> V_25 ) ;
if ( V_136 -> V_133 )
V_138 -> V_140 = F_74 ( V_27 , V_85 ) ;
else {
V_85 -> V_25 += V_136 -> V_23 ;
V_138 -> V_140 = F_51 ( V_27 , V_85 ) ;
}
} else if ( ! V_42 . V_141 ) {
V_138 -> V_140 = F_81 ( V_27 ,
F_78 , ( void * ) V_85 ) ;
if ( V_138 -> V_140 == - V_10 && F_82 ( V_136 -> V_114 ) )
V_138 -> V_140 = 0 ;
}
if ( F_82 ( V_136 -> V_114 ) && V_138 -> V_140 >= 0 ) {
V_138 -> V_140 = 0 ;
return V_139 ;
}
return V_142 ;
}
static int F_83 ( struct V_84 * V_85 )
{
struct V_137 V_143 = { . V_109 = ( void * ) V_85 ,
. V_140 = 0 } ;
F_84 ( & V_85 -> V_90 , F_79 , & V_143 , 0 ) ;
return V_143 . V_140 ;
}
static int F_85 ( T_12 * V_2 , T_13 * V_144 , void * V_109 )
{
struct V_145 * V_138 = V_109 ;
if ( F_86 ( V_2 , V_144 -> V_146 , V_138 -> V_27 ) ) {
if ( F_22 ( V_138 -> V_27 ) != V_147 )
return V_139 ;
if ( F_60 ( V_138 -> V_27 , V_138 -> V_114 ) ) {
if ( ! F_86 ( V_2 , V_144 -> V_148 , V_138 -> V_90 ) )
return V_139 ;
if ( V_138 -> V_112 &&
F_65 ( V_138 -> V_112 , F_59 ( V_138 -> V_27 ) ) )
return V_139 ;
V_138 -> V_47 = 1 ;
return V_142 ;
}
}
return V_139 ;
}
static int F_87 ( struct V_1 * V_2 ,
struct V_84 * V_85 )
{
struct V_135 * V_136 = & V_85 -> V_116 -> V_117 ;
T_14 V_149 , V_150 ;
T_5 V_151 ;
T_1 * V_152 ;
int V_36 = 0 ;
#if F_55 ( 0 , 142 )
T_15 * V_153 ;
T_16 V_154 ;
T_17 V_155 ;
V_153 = F_88 ( V_2 -> V_2 ) ;
if ( V_153 == NULL )
return - V_41 ;
if ( F_89 ( V_153 , & V_154 ) == NULL )
return - V_41 ;
if ( F_90 ( V_153 , & V_154 , & V_155 , L_62 , NULL ) &&
V_155 . V_156 == V_157 ) {
V_85 -> V_104 = F_91 ( V_153 ) ;
} else {
V_85 -> V_104 = F_92 ( V_2 -> V_2 ) ;
}
#endif
V_149 = 0 ;
V_85 -> V_130 = F_93 ( NULL ) ;
if ( ! V_85 -> V_130 )
return - V_51 ;
if ( V_136 -> V_114 && ! F_82 ( V_136 -> V_114 ) ) {
struct V_145 V_158 = {
. V_114 = V_136 -> V_114 ,
. V_112 = V_136 -> V_112 ,
. V_90 = & V_85 -> V_90 ,
. V_27 = & V_85 -> V_27 ,
. V_47 = 0 ,
} ;
struct V_137 V_159 = {
. V_109 = V_85 ,
} ;
F_94 ( V_2 -> V_2 , F_85 ,
& V_158 , 0 ) ;
if ( V_158 . V_47 ) {
V_36 = F_79 ( & V_85 -> V_27 , & V_159 ) ;
if ( V_36 )
goto V_47;
}
}
while ( ! F_95 ( V_2 -> V_2 , V_149 , & V_150 , & V_151 , NULL , NULL , NULL ) ) {
V_152 = F_86 ( V_2 -> V_2 , V_149 + V_151 , & V_85 -> V_90 ) ;
if ( ! V_152 )
continue;
if ( V_136 -> V_112 )
V_85 -> V_118 = F_96 ( & V_85 -> V_90 , V_136 -> V_112 ) ;
else
V_85 -> V_118 = NULL ;
if ( ! V_136 -> V_112 || V_85 -> V_118 ) {
if ( V_136 -> V_114 )
V_36 = F_83 ( V_85 ) ;
else if ( V_136 -> V_133 )
V_36 = F_74 ( & V_85 -> V_90 , V_85 ) ;
else {
V_85 -> V_113 = V_136 -> line ;
V_36 = F_66 ( V_85 ) ;
}
if ( V_36 < 0 )
break;
}
V_149 = V_150 ;
}
V_47:
F_97 ( V_85 -> V_130 ) ;
V_85 -> V_130 = NULL ;
return V_36 ;
}
static int F_98 ( T_1 * V_78 , void * V_109 )
{
struct V_160 * V_161 = V_109 ;
struct V_84 * V_85 = V_161 -> V_85 ;
int V_79 ;
V_79 = F_22 ( V_78 ) ;
if ( V_79 == V_46 ||
( V_79 == V_44 && V_161 -> V_162 ) ) {
if ( F_18 ( V_78 , V_161 -> V_85 -> V_25 ,
V_161 -> V_85 -> V_26 , & V_85 -> V_27 ,
NULL ) == 0 ) {
V_161 -> args [ V_161 -> V_163 ] . V_87 = ( char * ) F_24 ( V_78 ) ;
if ( V_161 -> args [ V_161 -> V_163 ] . V_87 == NULL ) {
V_161 -> V_36 = - V_51 ;
return V_164 ;
}
F_11 ( L_63 , V_161 -> args [ V_161 -> V_163 ] . V_87 ) ;
V_161 -> V_163 ++ ;
}
}
if ( F_99 ( V_78 , V_161 -> V_85 -> V_25 ) )
return V_165 ;
else
return V_166 ;
}
static int F_100 ( T_1 * V_88 , struct V_84 * V_85 ,
struct V_167 * args )
{
T_1 V_78 ;
int V_168 ;
int V_169 = 0 ;
struct V_160 V_161 = { . V_85 = V_85 , . args = args , . V_162 = false ,
. V_170 = V_171 , . V_36 = 0 } ;
for ( V_168 = 0 ; V_168 < V_85 -> V_116 -> V_163 ; V_168 ++ ) {
if ( strcmp ( V_85 -> V_116 -> args [ V_168 ] . V_87 , V_172 ) == 0 )
V_161 . V_162 = true ;
else if ( strcmp ( V_85 -> V_116 -> args [ V_168 ] . V_87 , V_173 ) != 0 ) {
args [ V_169 ] = V_85 -> V_116 -> args [ V_168 ] ;
V_169 ++ ;
continue;
}
F_11 ( L_64 , V_85 -> V_116 -> args [ V_168 ] . V_87 ) ;
V_161 . V_163 = V_169 ;
F_101 ( V_88 , F_98 , ( void * ) & V_161 ,
& V_78 ) ;
F_11 ( L_65 , V_161 . V_163 - V_169 ) ;
if ( V_161 . V_36 < 0 )
return V_161 . V_36 ;
V_169 = V_161 . V_163 ;
}
return V_169 ;
}
static int F_102 ( T_1 * V_88 , struct V_84 * V_85 )
{
struct V_174 * V_175 =
F_103 ( V_85 , struct V_174 , V_85 ) ;
struct V_176 * V_177 ;
struct V_167 * args ;
int V_36 , V_168 ;
if ( V_175 -> V_178 == V_175 -> V_179 ) {
F_26 ( L_66 ,
V_175 -> V_179 ) ;
return - V_45 ;
}
V_177 = & V_175 -> V_180 [ V_175 -> V_178 ++ ] ;
V_36 = F_49 ( & V_85 -> V_27 , V_175 -> V_8 , V_85 -> V_25 ,
V_85 -> V_116 -> V_117 . V_92 , & V_177 -> V_117 ) ;
if ( V_36 < 0 )
return V_36 ;
V_177 -> V_117 . V_181 = F_27 ( F_24 ( V_88 ) ) ;
if ( ! V_177 -> V_117 . V_181 )
return - V_51 ;
F_11 ( L_67 , V_177 -> V_117 . V_98 ,
V_177 -> V_117 . V_23 ) ;
args = F_9 ( sizeof( struct V_167 ) * V_171 ) ;
if ( args == NULL )
return - V_51 ;
V_36 = F_100 ( V_88 , V_85 , args ) ;
if ( V_36 < 0 )
goto V_182;
V_177 -> V_163 = V_36 ;
V_177 -> args = F_9 ( sizeof( struct V_28 ) * V_177 -> V_163 ) ;
if ( V_177 -> args == NULL ) {
V_36 = - V_51 ;
goto V_182;
}
for ( V_168 = 0 ; V_168 < V_177 -> V_163 ; V_168 ++ ) {
V_85 -> V_86 = & args [ V_168 ] ;
V_85 -> V_29 = & V_177 -> args [ V_168 ] ;
V_36 = F_45 ( V_88 , V_85 ) ;
if ( V_36 != 0 )
break;
}
V_182:
free ( args ) ;
return V_36 ;
}
int F_104 ( struct V_1 * V_2 ,
struct V_183 * V_116 ,
struct V_176 * * V_180 )
{
struct V_174 V_175 = {
. V_85 = { . V_116 = V_116 , . V_107 = F_102 } ,
. V_179 = V_42 . V_184 , . V_8 = V_2 -> V_8 } ;
int V_36 ;
* V_180 = F_9 ( sizeof( struct V_176 ) * V_175 . V_179 ) ;
if ( * V_180 == NULL )
return - V_51 ;
V_175 . V_180 = * V_180 ;
V_175 . V_178 = 0 ;
V_36 = F_87 ( V_2 , & V_175 . V_85 ) ;
if ( V_36 < 0 ) {
F_10 ( V_180 ) ;
return V_36 ;
}
return ( V_36 < 0 ) ? V_36 : V_175 . V_178 ;
}
static int F_105 ( T_1 * V_78 , void * V_109 )
{
struct V_185 * V_186 = V_109 ;
struct V_187 * V_188 ;
int V_79 , V_36 ;
V_188 = & V_186 -> V_189 [ V_186 -> V_190 - 1 ] ;
V_79 = F_22 ( V_78 ) ;
if ( V_79 == V_46 ||
V_79 == V_44 ) {
V_36 = F_18 ( V_78 , V_186 -> V_85 . V_25 ,
V_186 -> V_85 . V_26 , & V_186 -> V_85 . V_27 ,
NULL ) ;
if ( V_36 == 0 || V_36 == - V_45 ) {
int V_37 ;
bool V_191 = ! V_186 -> V_192 ;
struct V_193 V_12 ;
F_106 ( & V_12 , 64 ) ;
if ( V_42 . V_43 ) {
if ( ! V_191 ) {
if ( V_36 )
F_107 ( & V_12 , L_68 ) ;
else
F_107 ( & V_12 , L_69 ) ;
} else
F_107 ( & V_12 , L_70 ) ;
}
V_37 = F_108 ( V_78 , & V_12 ) ;
if ( ! V_37 && V_42 . V_43 &&
! V_191 ) {
F_107 ( & V_12 , L_71 ) ;
V_37 = F_109 ( & V_186 -> V_85 . V_27 ,
V_78 , & V_12 ) ;
}
F_11 ( L_72 , V_12 . V_12 ) ;
if ( V_37 == 0 ) {
F_110 ( V_188 -> V_162 ,
F_111 ( & V_12 , NULL ) ) ;
}
F_112 ( & V_12 ) ;
}
}
if ( V_186 -> V_192 && F_99 ( V_78 , V_186 -> V_85 . V_25 ) )
return V_165 ;
else
return V_166 ;
}
static int F_113 ( T_1 * V_88 , struct V_84 * V_85 )
{
struct V_185 * V_186 =
F_103 ( V_85 , struct V_185 , V_85 ) ;
struct V_187 * V_188 ;
T_1 V_78 ;
int V_36 ;
if ( V_186 -> V_190 == V_186 -> V_194 ) {
F_26 ( L_66 , V_186 -> V_194 ) ;
return - V_45 ;
}
V_188 = & V_186 -> V_189 [ V_186 -> V_190 ++ ] ;
V_36 = F_49 ( & V_85 -> V_27 , V_186 -> V_8 , V_85 -> V_25 ,
V_85 -> V_116 -> V_117 . V_92 , & V_188 -> V_117 ) ;
if ( V_36 < 0 )
return V_36 ;
F_11 ( L_67 , V_188 -> V_117 . V_98 ,
V_188 -> V_117 . V_23 ) ;
V_188 -> V_162 = F_114 ( true , NULL ) ;
if ( V_188 -> V_162 == NULL )
return - V_51 ;
V_186 -> V_192 = true ;
F_101 ( V_88 , F_105 , ( void * ) V_186 , & V_78 ) ;
if ( ! V_42 . V_195 )
goto V_17;
V_186 -> V_192 = false ;
F_101 ( & V_85 -> V_90 , F_105 , ( void * ) V_186 , & V_78 ) ;
V_17:
if ( F_115 ( V_188 -> V_162 ) ) {
F_116 ( V_188 -> V_162 ) ;
V_188 -> V_162 = NULL ;
}
return V_36 ;
}
int F_117 ( struct V_1 * V_2 ,
struct V_183 * V_116 ,
struct V_187 * * V_189 )
{
struct V_185 V_186 = {
. V_85 = { . V_116 = V_116 , . V_107 = F_113 } ,
. V_8 = V_2 -> V_8 ,
. V_194 = V_42 . V_184 } ;
int V_36 ;
* V_189 = F_9 ( sizeof( struct V_187 ) * V_186 . V_194 ) ;
if ( * V_189 == NULL )
return - V_51 ;
V_186 . V_189 = * V_189 ;
V_186 . V_190 = 0 ;
V_36 = F_87 ( V_2 , & V_186 . V_85 ) ;
if ( V_36 < 0 ) {
while ( V_186 . V_190 -- ) {
F_10 ( & V_186 . V_189 [ V_186 . V_190 ] . V_117 . V_98 ) ;
F_116 ( V_186 . V_189 [ V_186 . V_190 ] . V_162 ) ;
}
F_10 ( V_189 ) ;
return V_36 ;
}
return ( V_36 < 0 ) ? V_36 : V_186 . V_190 ;
}
int F_118 ( struct V_1 * V_2 , unsigned long V_25 ,
struct V_135 * V_196 )
{
T_1 V_197 , V_198 , V_199 ;
T_2 V_200 = 0 , V_201 = 0 ;
const char * V_118 = NULL , * V_202 = NULL , * V_203 = NULL , * V_31 ;
int V_204 = 0 , V_120 = 0 , V_36 = 0 ;
if ( ! F_119 ( V_2 -> V_2 , ( T_2 ) V_25 , & V_197 ) ) {
F_26 ( L_73 ,
V_25 ) ;
V_36 = - V_41 ;
goto V_182;
}
F_120 ( & V_197 , V_25 , & V_118 , & V_120 ) ;
if ( F_53 ( & V_197 , ( T_2 ) V_25 , & V_198 ) ) {
V_202 = V_203 = F_24 ( & V_198 ) ;
if ( ! V_202 ||
F_21 ( & V_198 , & V_201 ) != 0 ||
F_61 ( & V_198 , & V_204 ) != 0 ) {
V_120 = 0 ;
goto V_205;
}
V_118 = F_59 ( & V_198 ) ;
if ( V_25 == ( unsigned long ) V_201 ) {
V_120 = V_204 ;
goto V_205;
}
while ( F_121 ( & V_198 , ( T_2 ) V_25 ,
& V_199 ) ) {
if ( F_21 ( & V_199 , & V_200 ) == 0 &&
V_200 == V_25 ) {
V_120 = F_122 ( & V_199 ) ;
V_118 = F_123 ( & V_199 ) ;
break;
} else {
V_31 = F_24 ( & V_199 ) ;
if ( ! V_31 ||
F_61 ( & V_199 , & V_204 ) != 0 )
break;
V_202 = V_31 ;
V_198 = V_199 ;
}
}
V_31 = F_59 ( & V_198 ) ;
if ( ! V_31 || strcmp ( V_31 , V_118 ) != 0 )
V_120 = 0 ;
}
V_205:
if ( V_120 )
V_196 -> line = V_120 - V_204 ;
else if ( V_203 ) {
V_196 -> V_23 = V_25 - ( unsigned long ) V_201 ;
V_202 = V_203 ;
}
if ( V_202 ) {
V_196 -> V_114 = F_27 ( V_202 ) ;
if ( V_196 -> V_114 == NULL ) {
V_36 = - V_51 ;
goto V_182;
}
}
if ( V_118 ) {
V_196 -> V_112 = F_27 ( V_118 ) ;
if ( V_196 -> V_112 == NULL ) {
F_10 ( & V_196 -> V_114 ) ;
V_36 = - V_51 ;
goto V_182;
}
}
V_182:
if ( V_36 == 0 && ( V_118 || V_202 ) )
V_36 = 1 ;
return V_36 ;
}
static int F_124 ( const char * V_206 , unsigned int V_120 ,
struct V_207 * V_208 )
{
if ( ! V_208 -> V_3 ) {
V_208 -> V_3 = F_27 ( V_206 ) ;
if ( V_208 -> V_3 == NULL )
return - V_51 ;
}
return F_71 ( V_208 -> V_209 , V_120 ) ;
}
static int F_125 ( const char * V_118 , int V_120 ,
T_2 V_25 V_210 ,
void * V_109 )
{
struct V_211 * V_212 = V_109 ;
int V_213 ;
if ( ( F_65 ( V_118 , V_212 -> V_118 ) != 0 ) ||
( V_212 -> V_214 > V_120 || V_212 -> V_215 < V_120 ) )
return 0 ;
V_213 = F_124 ( V_118 , V_120 , V_212 -> V_208 ) ;
if ( V_213 < 0 && V_213 != - V_216 )
return V_213 ;
return 0 ;
}
static int F_126 ( T_1 * V_27 , struct V_211 * V_212 )
{
int V_36 ;
V_36 = F_67 ( V_27 ? : & V_212 -> V_90 , F_125 , V_212 ) ;
if ( V_36 >= 0 )
if ( ! F_75 ( V_212 -> V_208 -> V_209 ) )
V_36 = V_212 -> V_47 = 1 ;
else
V_36 = 0 ;
else {
F_10 ( & V_212 -> V_208 -> V_3 ) ;
}
return V_36 ;
}
static int F_127 ( T_1 * V_134 , void * V_109 )
{
int V_36 = F_126 ( V_134 , V_109 ) ;
return V_36 < 0 ? V_36 : 0 ;
}
static int F_128 ( T_1 * V_27 , void * V_109 )
{
struct V_137 * V_138 = V_109 ;
struct V_211 * V_212 = V_138 -> V_109 ;
struct V_207 * V_208 = V_212 -> V_208 ;
if ( V_208 -> V_112 && F_65 ( V_208 -> V_112 , F_59 ( V_27 ) ) )
return V_139 ;
if ( F_52 ( V_27 ) &&
F_60 ( V_27 , V_208 -> V_114 ) ) {
V_212 -> V_118 = F_59 ( V_27 ) ;
F_61 ( V_27 , & V_208 -> V_23 ) ;
F_11 ( L_74 , V_212 -> V_118 , V_208 -> V_23 ) ;
V_212 -> V_214 = V_208 -> V_23 + V_208 -> V_217 ;
if ( V_212 -> V_214 < 0 )
V_212 -> V_214 = V_119 ;
V_212 -> V_215 = V_208 -> V_23 + V_208 -> V_182 ;
if ( V_212 -> V_215 < 0 )
V_212 -> V_215 = V_119 ;
F_11 ( L_75 , V_212 -> V_214 , V_212 -> V_215 ) ;
V_208 -> V_217 = V_212 -> V_214 ;
V_208 -> V_182 = V_212 -> V_215 ;
if ( ! F_80 ( V_27 ) )
V_138 -> V_140 = F_81 ( V_27 ,
F_127 , V_212 ) ;
else
V_138 -> V_140 = F_126 ( V_27 , V_212 ) ;
return V_142 ;
}
return V_139 ;
}
static int F_129 ( struct V_211 * V_212 )
{
struct V_137 V_138 = { . V_109 = ( void * ) V_212 , . V_140 = 0 } ;
F_84 ( & V_212 -> V_90 , F_128 , & V_138 , 0 ) ;
return V_138 . V_140 ;
}
int F_130 ( struct V_1 * V_2 , struct V_207 * V_208 )
{
struct V_211 V_212 = { . V_208 = V_208 , . V_47 = 0 } ;
int V_36 = 0 ;
T_14 V_149 = 0 , V_150 ;
T_5 V_151 ;
T_1 * V_152 ;
const char * V_132 ;
if ( V_208 -> V_114 ) {
struct V_145 V_158 = {
. V_114 = V_208 -> V_114 , . V_112 = V_208 -> V_112 ,
. V_90 = & V_212 . V_90 , . V_27 = & V_212 . V_27 , . V_47 = 0 } ;
struct V_137 V_218 = {
. V_109 = ( void * ) & V_212 , . V_140 = 0 } ;
F_94 ( V_2 -> V_2 , F_85 ,
& V_158 , 0 ) ;
if ( V_158 . V_47 ) {
F_128 ( & V_212 . V_27 , & V_218 ) ;
if ( V_212 . V_47 )
goto V_47;
}
}
while ( ! V_212 . V_47 && V_36 >= 0 ) {
if ( F_95 ( V_2 -> V_2 , V_149 , & V_150 , & V_151 ,
NULL , NULL , NULL ) != 0 )
break;
V_152 = F_86 ( V_2 -> V_2 , V_149 + V_151 , & V_212 . V_90 ) ;
if ( ! V_152 )
continue;
if ( V_208 -> V_112 )
V_212 . V_118 = F_96 ( & V_212 . V_90 , V_208 -> V_112 ) ;
else
V_212 . V_118 = 0 ;
if ( ! V_208 -> V_112 || V_212 . V_118 ) {
if ( V_208 -> V_114 )
V_36 = F_129 ( & V_212 ) ;
else {
V_212 . V_214 = V_208 -> V_217 ;
V_212 . V_215 = V_208 -> V_182 ;
V_36 = F_126 ( NULL , & V_212 ) ;
}
}
V_149 = V_150 ;
}
V_47:
if ( V_212 . V_47 ) {
V_132 = F_76 ( & V_212 . V_90 ) ;
if ( V_132 ) {
V_208 -> V_132 = F_27 ( V_132 ) ;
if ( ! V_208 -> V_132 )
V_36 = - V_51 ;
}
}
F_11 ( L_76 , V_208 -> V_3 ) ;
return ( V_36 < 0 ) ? V_36 : V_212 . V_47 ;
}
int F_77 ( const char * V_219 , const char * V_132 ,
char * * V_220 )
{
const char * V_221 = V_222 . V_223 ;
if ( ! V_221 ) {
if ( V_219 [ 0 ] != '/' && V_132 )
V_221 = V_132 ;
else {
if ( F_131 ( V_219 , V_224 ) == 0 ) {
* V_220 = F_27 ( V_219 ) ;
return * V_220 ? 0 : - V_51 ;
} else
return - V_129 ;
}
}
* V_220 = malloc ( ( strlen ( V_221 ) + strlen ( V_219 ) + 2 ) ) ;
if ( ! * V_220 )
return - V_51 ;
for (; ; ) {
sprintf ( * V_220 , L_77 , V_221 , V_219 ) ;
if ( F_131 ( * V_220 , V_224 ) == 0 )
return 0 ;
if ( ! V_222 . V_223 ) {
F_10 ( V_220 ) ;
return - V_129 ;
}
switch ( V_129 ) {
case V_225 :
case V_10 :
case V_226 :
case V_227 :
V_219 = strchr ( ++ V_219 , '/' ) ;
if ( ! V_219 ) {
F_10 ( V_220 ) ;
return - V_10 ;
}
continue;
default:
F_10 ( V_220 ) ;
return - V_129 ;
}
}
}
