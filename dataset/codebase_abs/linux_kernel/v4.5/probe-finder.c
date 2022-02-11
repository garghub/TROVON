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
if ( V_62 && strcmp ( V_62 , L_7 ) != 0 ) {
V_29 -> type = F_29 ( V_62 ) ;
return ( V_29 -> type == NULL ) ? - V_51 : 0 ;
}
V_66 = F_31 ( V_24 ) ;
if ( V_66 > 0 ) {
V_67 = F_32 ( V_24 ) ;
V_68 = F_33 ( V_24 ) ;
if ( V_67 < 0 || V_68 < 0 )
return - V_10 ;
V_36 = snprintf ( V_12 , 16 , L_8 , V_66 , V_67 ,
F_34 ( V_68 ) ) ;
goto V_69;
}
if ( F_35 ( V_24 , & type ) == NULL ) {
F_28 ( L_9 ,
F_26 ( V_24 ) ) ;
return - V_10 ;
}
F_13 ( L_10 ,
F_26 ( V_24 ) , F_26 ( & type ) ) ;
if ( V_62 && strcmp ( V_62 , L_7 ) == 0 ) {
V_36 = F_24 ( & type ) ;
if ( V_36 != V_70 &&
V_36 != V_71 ) {
F_28 ( L_11
L_12 ,
F_26 ( V_24 ) , F_26 ( & type ) ) ;
return - V_41 ;
}
if ( F_35 ( & type , & type ) == NULL ) {
F_28 ( L_13
L_14 ) ;
return - V_10 ;
}
if ( V_36 == V_70 ) {
while ( * V_63 )
V_63 = & ( * V_63 ) -> V_72 ;
* V_63 = F_11 ( sizeof( struct V_20 ) ) ;
if ( * V_63 == NULL ) {
F_28 ( L_15 ) ;
return - V_51 ;
}
}
if ( ! F_36 ( & type , L_16 ) &&
! F_36 ( & type , L_17 ) ) {
F_28 ( L_11
L_18 ,
F_26 ( V_24 ) ) ;
return - V_41 ;
}
V_29 -> type = F_29 ( V_62 ) ;
return ( V_29 -> type == NULL ) ? - V_51 : 0 ;
}
V_36 = F_33 ( & type ) ;
if ( V_36 <= 0 )
return 0 ;
V_36 = F_34 ( V_36 ) ;
if ( V_36 > V_73 ) {
F_37 ( L_19 ,
F_26 ( & type ) , V_73 ) ;
V_36 = V_73 ;
}
V_36 = snprintf ( V_12 , 16 , L_20 ,
F_38 ( & type ) ? 's' : 'u' , V_36 ) ;
V_69:
if ( V_36 < 0 || V_36 >= 16 ) {
if ( V_36 >= 16 )
V_36 = - V_74 ;
F_28 ( L_21 ,
F_39 ( - V_36 , V_64 , sizeof( V_64 ) ) ) ;
return V_36 ;
}
V_29 -> type = F_29 ( V_12 ) ;
if ( V_29 -> type == NULL )
return - V_51 ;
return 0 ;
}
static int F_40 ( T_1 * V_24 , const char * V_75 ,
struct V_76 * V_77 ,
struct V_20 * * V_63 ,
T_1 * V_78 )
{
struct V_20 * V_22 = * V_63 ;
T_1 type ;
T_6 V_21 ;
int V_36 , V_79 ;
F_13 ( L_22 , V_77 -> V_80 , V_75 ) ;
if ( F_35 ( V_24 , & type ) == NULL ) {
F_28 ( L_23 , V_75 ) ;
return - V_10 ;
}
F_41 ( L_24 , ( unsigned ) F_42 ( & type ) ) ;
V_79 = F_24 ( & type ) ;
if ( V_77 -> V_80 [ 0 ] == '[' &&
( V_79 == V_71 || V_79 == V_70 ) ) {
if ( V_77 -> V_72 )
memcpy ( V_78 , & type , sizeof( * V_78 ) ) ;
if ( F_35 ( & type , & type ) == NULL ) {
F_28 ( L_23 , V_75 ) ;
return - V_10 ;
}
F_41 ( L_25 ,
( unsigned ) F_42 ( & type ) ) ;
if ( V_79 == V_70 ) {
V_22 = F_11 ( sizeof( struct V_20 ) ) ;
if ( V_22 == NULL )
return - V_51 ;
if ( * V_63 )
( * V_63 ) -> V_72 = V_22 ;
else
* V_63 = V_22 ;
}
V_22 -> V_23 += F_33 ( & type ) * V_77 -> V_81 ;
if ( ! V_77 -> V_72 )
memcpy ( V_78 , V_24 , sizeof( * V_78 ) ) ;
goto V_72;
} else if ( V_79 == V_70 ) {
if ( ! V_77 -> V_22 ) {
F_43 ( L_26 ,
V_77 -> V_80 ) ;
return - V_41 ;
}
if ( F_35 ( & type , & type ) == NULL ) {
F_28 ( L_23 , V_75 ) ;
return - V_10 ;
}
V_79 = F_24 ( & type ) ;
if ( V_79 != V_82 && V_79 != V_83 ) {
F_28 ( L_27 ,
V_75 ) ;
return - V_41 ;
}
V_22 = F_11 ( sizeof( struct V_20 ) ) ;
if ( V_22 == NULL )
return - V_51 ;
if ( * V_63 )
( * V_63 ) -> V_72 = V_22 ;
else
* V_63 = V_22 ;
} else {
if ( V_79 != V_82 && V_79 != V_83 ) {
F_28 ( L_27 ,
V_75 ) ;
return - V_41 ;
}
if ( V_77 -> V_80 [ 0 ] == '[' ) {
F_43 ( L_28
L_29 , V_75 ) ;
return - V_41 ;
}
if ( V_77 -> V_22 && F_26 ( V_24 ) ) {
F_43 ( L_30 ,
V_77 -> V_80 ) ;
return - V_41 ;
}
if ( ! V_22 ) {
F_28 ( L_31
L_32 ) ;
return - V_53 ;
}
}
if ( F_44 ( & type , V_77 -> V_80 , V_78 ) == NULL ) {
F_28 ( L_33 , V_75 ,
F_26 ( & type ) , V_77 -> V_80 ) ;
return - V_41 ;
}
if ( V_79 == V_83 ) {
V_21 = 0 ;
} else {
V_36 = F_45 ( V_78 , & V_21 ) ;
if ( V_36 < 0 ) {
F_28 ( L_34 ,
V_77 -> V_80 ) ;
return V_36 ;
}
}
V_22 -> V_23 += ( long ) V_21 ;
if ( ! F_26 ( V_78 ) )
return F_40 ( V_78 , V_75 , V_77 ,
& V_22 , V_78 ) ;
V_72:
if ( V_77 -> V_72 )
return F_40 ( V_78 , V_77 -> V_80 ,
V_77 -> V_72 , & V_22 , V_78 ) ;
else
return 0 ;
}
static int F_46 ( T_1 * V_24 , struct V_84 * V_85 )
{
T_1 V_78 ;
int V_36 ;
F_13 ( L_35 ,
F_26 ( V_24 ) ) ;
V_36 = F_20 ( V_24 , V_85 -> V_25 , V_85 -> V_26 ,
& V_85 -> V_27 , V_85 -> V_29 ) ;
if ( V_36 == - V_10 || V_36 == - V_41 ) {
F_43 ( L_36
L_37
L_38 ,
V_85 -> V_86 -> V_87 , V_85 -> V_86 -> V_87 ) ;
} else if ( V_36 == - V_53 )
F_43 ( L_39 ) ;
else if ( V_36 == 0 && V_85 -> V_86 -> V_77 ) {
V_36 = F_40 ( V_24 , V_85 -> V_86 -> V_87 ,
V_85 -> V_86 -> V_77 , & V_85 -> V_29 -> V_22 ,
& V_78 ) ;
V_24 = & V_78 ;
}
if ( V_36 == 0 )
V_36 = F_30 ( V_24 , V_85 -> V_29 , V_85 -> V_86 -> type ) ;
return V_36 ;
}
static int F_47 ( T_1 * V_88 , struct V_84 * V_85 )
{
T_1 V_24 ;
char V_12 [ 32 ] , * V_89 ;
int V_36 = 0 ;
if ( ! F_48 ( V_85 -> V_86 -> V_87 ) )
return F_49 ( V_85 -> V_29 , V_85 -> V_86 ) ;
if ( V_85 -> V_86 -> V_80 )
V_85 -> V_29 -> V_80 = F_29 ( V_85 -> V_86 -> V_80 ) ;
else {
V_36 = F_50 ( V_85 -> V_86 , V_12 , 32 ) ;
if ( V_36 < 0 )
return V_36 ;
V_89 = strchr ( V_12 , ':' ) ;
if ( V_89 )
* V_89 = '_' ;
V_85 -> V_29 -> V_80 = F_29 ( V_12 ) ;
}
if ( V_85 -> V_29 -> V_80 == NULL )
return - V_51 ;
F_13 ( L_40 , V_85 -> V_86 -> V_87 ) ;
if ( ! F_51 ( V_88 , V_85 -> V_86 -> V_87 , V_85 -> V_25 , & V_24 ) ) {
if ( ! F_51 ( & V_85 -> V_90 , V_85 -> V_86 -> V_87 ,
0 , & V_24 ) ) {
F_28 ( L_41 ,
V_85 -> V_86 -> V_87 ) ;
V_36 = - V_10 ;
}
}
if ( V_36 >= 0 )
V_36 = F_46 ( & V_24 , V_85 ) ;
return V_36 ;
}
static int F_52 ( T_1 * V_27 , T_7 * V_8 ,
T_2 V_91 , bool V_92 ,
const char * V_93 ,
struct V_94 * V_95 )
{
T_2 V_96 , V_97 ;
T_8 V_98 ;
const char * V_99 ;
if ( F_23 ( V_27 , & V_96 ) != 0 ) {
F_28 ( L_42 ,
F_26 ( V_27 ) ) ;
return - V_10 ;
}
if ( F_25 ( V_27 , & V_97 ) != 0 ) {
F_28 ( L_43 ,
F_26 ( V_27 ) ) ;
return - V_10 ;
}
if ( V_91 > V_97 ) {
F_28 ( L_44 ,
F_26 ( V_27 ) ) ;
return - V_41 ;
}
V_99 = F_26 ( V_27 ) ;
if ( ! V_99 ) {
V_99 = F_53 ( V_8 , V_91 , & V_98 , NULL ) ;
if ( ! V_99 ) {
F_28 ( L_45 ,
( unsigned long ) V_91 ) ;
return - V_10 ;
}
V_96 = V_98 . V_100 ;
}
V_95 -> V_23 = ( unsigned long ) ( V_91 - V_96 ) ;
V_95 -> V_101 = ( unsigned long ) V_91 ;
V_95 -> V_99 = F_29 ( V_99 ) ;
if ( ! V_95 -> V_99 )
return - V_51 ;
if ( V_92 ) {
if ( V_96 != V_91 ) {
F_28 ( L_46
L_47
L_48 , V_93 ,
V_93 ) ;
return - V_41 ;
}
V_95 -> V_92 = true ;
}
return 0 ;
}
static int F_54 ( T_1 * V_88 , struct V_84 * V_85 )
{
T_4 V_102 ;
T_9 * V_103 = NULL ;
T_5 V_33 ;
int V_36 ;
if ( ! V_88 ) {
F_43 ( L_49 ) ;
return - V_41 ;
}
if ( ! F_55 ( V_88 ) ) {
if ( ! F_56 ( & V_85 -> V_90 , V_85 -> V_25 , & V_85 -> V_27 ) ) {
if ( F_57 ( & V_85 -> V_90 , V_85 -> V_25 , & V_85 -> V_27 ) ) {
F_28 ( L_50 ,
F_26 ( & V_85 -> V_27 ) ) ;
return 0 ;
} else {
F_28 ( L_51
L_52 ) ;
return - V_10 ;
}
}
} else
memcpy ( & V_85 -> V_27 , V_88 , sizeof( T_1 ) ) ;
F_21 ( & V_85 -> V_27 , V_104 , & V_102 ) ;
V_36 = F_22 ( & V_102 , V_85 -> V_25 , & V_85 -> V_26 , & V_33 , 1 ) ;
if ( V_36 <= 0 || V_33 == 0 ) {
V_85 -> V_26 = NULL ;
#if F_58 ( 0 , 142 )
} else if ( V_33 == 1 && V_85 -> V_26 [ 0 ] . V_48 == V_105 &&
( V_85 -> V_106 != NULL || V_85 -> V_107 != NULL ) ) {
if ( ( F_59 ( V_85 -> V_106 , V_85 -> V_25 , & V_103 ) != 0 &&
( F_59 ( V_85 -> V_107 , V_85 -> V_25 , & V_103 ) != 0 ) ) ||
F_60 ( V_103 , & V_85 -> V_26 , & V_33 ) != 0 ) {
F_28 ( L_53 ,
( V_108 ) V_85 -> V_25 ) ;
free ( V_103 ) ;
return - V_10 ;
}
#endif
}
V_36 = V_85 -> V_109 ( V_88 , V_85 ) ;
free ( V_103 ) ;
V_85 -> V_26 = NULL ;
return V_36 ;
}
static int F_61 ( T_1 * V_110 , void * V_111 )
{
struct V_112 * V_113 = V_111 ;
const char * V_114 ;
int V_115 ;
if ( V_113 -> V_114 ) {
V_114 = F_62 ( V_110 ) ;
if ( ! V_114 || strcmp ( V_113 -> V_114 , V_114 ) != 0 )
return 0 ;
}
if ( V_113 -> V_93 ) {
if ( F_63 ( V_110 , V_113 -> V_93 ) ) {
memcpy ( V_113 -> V_78 , V_110 , sizeof( T_1 ) ) ;
V_113 -> V_47 = true ;
return 1 ;
}
} else {
F_64 ( V_110 , & V_115 ) ;
if ( V_115 < V_113 -> line && V_113 -> V_116 > V_113 -> line - V_115 ) {
V_113 -> V_116 = V_113 -> line - V_115 ;
memcpy ( V_113 -> V_78 , V_110 , sizeof( T_1 ) ) ;
V_113 -> V_47 = true ;
}
}
return 0 ;
}
static T_1 * F_65 ( struct V_84 * V_85 , T_1 * V_78 )
{
struct V_112 V_113 = {
. V_93 = V_85 -> V_117 -> V_118 . V_93 ,
. V_114 = V_85 -> V_119 ,
. line = V_85 -> V_115 ,
. V_116 = V_120 ,
. V_78 = V_78 ,
. V_47 = false ,
} ;
F_66 ( & V_85 -> V_90 , V_85 -> V_25 , F_61 , & V_113 ) ;
return V_113 . V_47 ? V_78 : NULL ;
}
static int F_67 ( const char * V_119 , int V_121 ,
T_2 V_25 , void * V_111 )
{
struct V_84 * V_85 = V_111 ;
T_1 * V_88 , V_78 ;
int V_36 ;
if ( V_121 != V_85 -> V_115 || F_68 ( V_119 , V_85 -> V_119 ) != 0 )
return 0 ;
V_85 -> V_25 = V_25 ;
V_88 = F_65 ( V_85 , & V_78 ) ;
if ( ! V_88 ) {
F_28 ( L_54 ) ;
return - V_10 ;
}
V_36 = F_54 ( V_88 , V_85 ) ;
return V_36 < 0 ? V_36 : 0 ;
}
static int F_69 ( struct V_84 * V_85 )
{
return F_70 ( & V_85 -> V_90 , F_67 , V_85 ) ;
}
static int F_71 ( struct V_122 * V_123 ,
const char * V_119 , const char * V_124 )
{
T_10 * V_125 ;
char * line = NULL ;
T_5 V_126 ;
T_11 V_127 ;
int V_128 = 0 , V_129 = 1 ;
char V_64 [ V_65 ] ;
V_125 = fopen ( V_119 , L_55 ) ;
if ( ! V_125 ) {
F_28 ( L_56 , V_119 ,
F_39 ( V_130 , V_64 , sizeof( V_64 ) ) ) ;
return - V_130 ;
}
while ( ( V_127 = F_72 ( & line , & V_126 , V_125 ) ) > 0 ) {
if ( line [ V_127 - 1 ] == '\n' )
line [ V_127 - 1 ] = '\0' ;
if ( F_73 ( line , V_124 ) ) {
F_74 ( V_123 , V_129 ) ;
V_128 ++ ;
}
V_129 ++ ;
}
if ( ferror ( V_125 ) )
V_128 = - V_130 ;
free ( line ) ;
fclose ( V_125 ) ;
if ( V_128 == 0 )
F_13 ( L_57 , V_119 ) ;
return V_128 ;
}
static int F_75 ( const char * V_119 , int V_121 ,
T_2 V_25 , void * V_111 )
{
struct V_84 * V_85 = V_111 ;
T_1 * V_88 , V_78 ;
int V_36 ;
if ( ! F_76 ( V_85 -> V_131 , V_121 ) ||
F_68 ( V_119 , V_85 -> V_119 ) != 0 )
return 0 ;
F_13 ( L_58 ,
V_121 , ( unsigned long long ) V_25 ) ;
V_85 -> V_25 = V_25 ;
V_85 -> V_115 = V_121 ;
V_88 = F_65 ( V_85 , & V_78 ) ;
if ( ! V_88 ) {
F_28 ( L_54 ) ;
return - V_10 ;
}
V_36 = F_54 ( V_88 , V_85 ) ;
return V_36 < 0 ? V_36 : 0 ;
}
static int F_77 ( T_1 * V_27 , struct V_84 * V_85 )
{
int V_36 = 0 ;
char * V_132 ;
if ( F_78 ( V_85 -> V_131 ) ) {
const char * V_133 ;
V_133 = F_79 ( & V_85 -> V_90 ) ;
V_36 = F_80 ( V_85 -> V_119 , V_133 , & V_132 ) ;
if ( V_36 < 0 ) {
F_28 ( L_59 ) ;
return V_36 ;
}
V_36 = F_71 ( V_85 -> V_131 , V_132 ,
V_85 -> V_117 -> V_118 . V_134 ) ;
free ( V_132 ) ;
if ( V_36 <= 0 )
return V_36 ;
}
return F_70 ( V_27 , F_75 , V_85 ) ;
}
static int F_81 ( T_1 * V_135 , void * V_111 )
{
struct V_84 * V_85 = V_111 ;
struct V_136 * V_137 = & V_85 -> V_117 -> V_118 ;
T_2 V_25 ;
int V_36 ;
if ( V_137 -> V_134 )
V_36 = F_77 ( V_135 , V_85 ) ;
else {
if ( F_23 ( V_135 , & V_25 ) != 0 ) {
F_28 ( L_60 ,
F_26 ( V_135 ) ) ;
return - V_10 ;
}
V_85 -> V_25 = V_25 ;
V_85 -> V_25 += V_137 -> V_23 ;
F_13 ( L_61 ,
( V_108 ) V_85 -> V_25 ) ;
V_36 = F_54 ( V_135 , V_85 ) ;
}
return V_36 ;
}
static int F_82 ( T_1 * V_27 , void * V_111 )
{
struct V_138 * V_139 = V_111 ;
struct V_84 * V_85 = V_139 -> V_111 ;
struct V_136 * V_137 = & V_85 -> V_117 -> V_118 ;
if ( ! F_55 ( V_27 ) ||
! F_63 ( V_27 , V_137 -> V_93 ) )
return V_140 ;
if ( V_137 -> V_114 && F_68 ( V_137 -> V_114 , F_62 ( V_27 ) ) )
return V_140 ;
F_13 ( L_62 , F_26 ( V_27 ) ) ;
V_85 -> V_119 = F_62 ( V_27 ) ;
if ( V_137 -> line ) {
F_64 ( V_27 , & V_85 -> V_115 ) ;
V_85 -> V_115 += V_137 -> line ;
V_139 -> V_141 = F_69 ( V_85 ) ;
} else if ( F_83 ( V_27 ) ) {
F_23 ( V_27 , & V_85 -> V_25 ) ;
if ( V_137 -> V_134 )
V_139 -> V_141 = F_77 ( V_27 , V_85 ) ;
else {
V_85 -> V_25 += V_137 -> V_23 ;
V_139 -> V_141 = F_54 ( V_27 , V_85 ) ;
}
} else if ( ! V_42 . V_142 ) {
V_139 -> V_141 = F_84 ( V_27 ,
F_81 , ( void * ) V_85 ) ;
if ( V_139 -> V_141 == - V_10 && F_85 ( V_137 -> V_93 ) )
V_139 -> V_141 = 0 ;
}
if ( F_85 ( V_137 -> V_93 ) && V_139 -> V_141 >= 0 ) {
V_139 -> V_141 = 0 ;
return V_140 ;
}
return V_143 ;
}
static int F_86 ( struct V_84 * V_85 )
{
struct V_138 V_144 = { . V_111 = ( void * ) V_85 ,
. V_141 = 0 } ;
F_87 ( & V_85 -> V_90 , F_82 , & V_144 , 0 ) ;
return V_144 . V_141 ;
}
static int F_88 ( T_12 * V_2 , T_13 * V_145 , void * V_111 )
{
struct V_146 * V_139 = V_111 ;
if ( F_89 ( V_2 , V_145 -> V_147 , V_139 -> V_27 ) ) {
if ( F_24 ( V_139 -> V_27 ) != V_148 )
return V_140 ;
if ( F_63 ( V_139 -> V_27 , V_139 -> V_93 ) ) {
if ( ! F_89 ( V_2 , V_145 -> V_149 , V_139 -> V_90 ) )
return V_140 ;
if ( V_139 -> V_114 &&
F_68 ( V_139 -> V_114 , F_62 ( V_139 -> V_27 ) ) )
return V_140 ;
V_139 -> V_47 = 1 ;
return V_143 ;
}
}
return V_140 ;
}
static int F_90 ( struct V_1 * V_2 ,
struct V_84 * V_85 )
{
struct V_136 * V_137 = & V_85 -> V_117 -> V_118 ;
T_14 V_150 , V_151 ;
T_5 V_152 ;
T_1 * V_153 ;
int V_36 = 0 ;
V_150 = 0 ;
V_85 -> V_131 = F_91 ( NULL ) ;
if ( ! V_85 -> V_131 )
return - V_51 ;
if ( V_137 -> V_93 && ! F_85 ( V_137 -> V_93 ) ) {
struct V_146 V_154 = {
. V_93 = V_137 -> V_93 ,
. V_114 = V_137 -> V_114 ,
. V_90 = & V_85 -> V_90 ,
. V_27 = & V_85 -> V_27 ,
. V_47 = 0 ,
} ;
struct V_138 V_155 = {
. V_111 = V_85 ,
} ;
F_92 ( V_2 -> V_2 , F_88 ,
& V_154 , 0 ) ;
if ( V_154 . V_47 ) {
V_36 = F_82 ( & V_85 -> V_27 , & V_155 ) ;
if ( V_36 )
goto V_47;
}
}
while ( ! F_93 ( V_2 -> V_2 , V_150 , & V_151 , & V_152 , NULL , NULL , NULL ) ) {
V_153 = F_89 ( V_2 -> V_2 , V_150 + V_152 , & V_85 -> V_90 ) ;
if ( ! V_153 )
continue;
if ( V_137 -> V_114 )
V_85 -> V_119 = F_94 ( & V_85 -> V_90 , V_137 -> V_114 ) ;
else
V_85 -> V_119 = NULL ;
if ( ! V_137 -> V_114 || V_85 -> V_119 ) {
if ( V_137 -> V_93 )
V_36 = F_86 ( V_85 ) ;
else if ( V_137 -> V_134 )
V_36 = F_77 ( & V_85 -> V_90 , V_85 ) ;
else {
V_85 -> V_115 = V_137 -> line ;
V_36 = F_69 ( V_85 ) ;
}
if ( V_36 < 0 )
break;
}
V_150 = V_151 ;
}
V_47:
F_95 ( V_85 -> V_131 ) ;
V_85 -> V_131 = NULL ;
return V_36 ;
}
static int F_96 ( struct V_1 * V_2 ,
struct V_84 * V_85 )
{
int V_36 = 0 ;
#if F_58 ( 0 , 142 )
T_15 * V_156 ;
T_16 V_157 ;
T_17 V_158 ;
if ( V_85 -> V_106 || V_85 -> V_107 )
return F_90 ( V_2 , V_85 ) ;
V_156 = F_97 ( V_2 -> V_2 ) ;
if ( V_156 == NULL )
return - V_41 ;
if ( F_98 ( V_156 , & V_157 ) == NULL )
return - V_41 ;
if ( F_99 ( V_156 , & V_157 , & V_158 , L_63 , NULL ) &&
V_158 . V_159 == V_160 )
V_85 -> V_106 = F_100 ( V_156 ) ;
V_85 -> V_107 = F_101 ( V_2 -> V_2 ) ;
#endif
V_36 = F_90 ( V_2 , V_85 ) ;
return V_36 ;
}
static int F_102 ( T_1 * V_78 , void * V_111 )
{
struct V_161 * V_162 = V_111 ;
struct V_84 * V_85 = V_162 -> V_85 ;
int V_79 ;
V_79 = F_24 ( V_78 ) ;
if ( V_79 == V_46 ||
( V_79 == V_44 && V_162 -> V_163 ) ) {
if ( F_20 ( V_78 , V_162 -> V_85 -> V_25 ,
V_162 -> V_85 -> V_26 , & V_85 -> V_27 ,
NULL ) == 0 ) {
V_162 -> args [ V_162 -> V_164 ] . V_87 = ( char * ) F_26 ( V_78 ) ;
if ( V_162 -> args [ V_162 -> V_164 ] . V_87 == NULL ) {
V_162 -> V_36 = - V_51 ;
return V_165 ;
}
F_13 ( L_64 , V_162 -> args [ V_162 -> V_164 ] . V_87 ) ;
V_162 -> V_164 ++ ;
}
}
if ( F_103 ( V_78 , V_162 -> V_85 -> V_25 ) )
return V_166 ;
else
return V_167 ;
}
static int F_104 ( T_1 * V_88 , struct V_84 * V_85 ,
struct V_168 * args )
{
T_1 V_78 ;
int V_169 ;
int V_170 = 0 ;
struct V_161 V_162 = { . V_85 = V_85 , . args = args , . V_163 = false ,
. V_171 = V_172 , . V_36 = 0 } ;
for ( V_169 = 0 ; V_169 < V_85 -> V_117 -> V_164 ; V_169 ++ ) {
if ( strcmp ( V_85 -> V_117 -> args [ V_169 ] . V_87 , V_173 ) == 0 )
V_162 . V_163 = true ;
else if ( strcmp ( V_85 -> V_117 -> args [ V_169 ] . V_87 , V_174 ) != 0 ) {
args [ V_170 ] = V_85 -> V_117 -> args [ V_169 ] ;
V_170 ++ ;
continue;
}
F_13 ( L_65 , V_85 -> V_117 -> args [ V_169 ] . V_87 ) ;
V_162 . V_164 = V_170 ;
F_105 ( V_88 , F_102 , ( void * ) & V_162 ,
& V_78 ) ;
F_13 ( L_66 , V_162 . V_164 - V_170 ) ;
if ( V_162 . V_36 < 0 )
return V_162 . V_36 ;
V_170 = V_162 . V_164 ;
}
return V_170 ;
}
static int F_106 ( T_1 * V_88 , struct V_84 * V_85 )
{
struct V_175 * V_176 =
F_107 ( V_85 , struct V_175 , V_85 ) ;
struct V_136 * V_137 = & V_85 -> V_117 -> V_118 ;
struct V_177 * V_178 ;
struct V_168 * args = NULL ;
int V_36 , V_169 ;
if ( V_176 -> V_179 == V_176 -> V_180 ) {
F_28 ( L_67 ,
V_176 -> V_180 ) ;
return - V_45 ;
}
V_178 = & V_176 -> V_181 [ V_176 -> V_179 ++ ] ;
V_36 = F_52 ( & V_85 -> V_27 , V_176 -> V_8 , V_85 -> V_25 ,
V_137 -> V_92 , V_137 -> V_93 , & V_178 -> V_118 ) ;
if ( V_36 < 0 )
goto V_182;
V_178 -> V_118 . V_183 = F_29 ( F_26 ( V_88 ) ) ;
if ( ! V_178 -> V_118 . V_183 ) {
V_36 = - V_51 ;
goto V_182;
}
F_13 ( L_68 , V_178 -> V_118 . V_99 ,
V_178 -> V_118 . V_23 ) ;
args = F_11 ( sizeof( struct V_168 ) * V_172 ) ;
if ( args == NULL ) {
V_36 = - V_51 ;
goto V_182;
}
V_36 = F_104 ( V_88 , V_85 , args ) ;
if ( V_36 < 0 )
goto V_182;
V_178 -> V_164 = V_36 ;
V_178 -> args = F_11 ( sizeof( struct V_28 ) * V_178 -> V_164 ) ;
if ( V_178 -> args == NULL ) {
V_36 = - V_51 ;
goto V_182;
}
for ( V_169 = 0 ; V_169 < V_178 -> V_164 ; V_169 ++ ) {
V_85 -> V_86 = & args [ V_169 ] ;
V_85 -> V_29 = & V_178 -> args [ V_169 ] ;
V_36 = F_47 ( V_88 , V_85 ) ;
if ( V_36 != 0 )
break;
}
V_182:
if ( V_36 ) {
F_108 ( V_178 ) ;
V_176 -> V_179 -- ;
}
free ( args ) ;
return V_36 ;
}
int F_109 ( struct V_1 * V_2 ,
struct V_184 * V_117 ,
struct V_177 * * V_181 )
{
struct V_175 V_176 = {
. V_85 = { . V_117 = V_117 , . V_109 = F_106 } ,
. V_180 = V_42 . V_185 , . V_8 = V_2 -> V_8 } ;
int V_36 , V_169 ;
* V_181 = F_11 ( sizeof( struct V_177 ) * V_176 . V_180 ) ;
if ( * V_181 == NULL )
return - V_51 ;
V_176 . V_181 = * V_181 ;
V_176 . V_179 = 0 ;
V_36 = F_96 ( V_2 , & V_176 . V_85 ) ;
if ( V_36 < 0 ) {
for ( V_169 = 0 ; V_169 < V_176 . V_179 ; V_169 ++ )
F_108 ( & V_176 . V_181 [ V_169 ] ) ;
F_12 ( V_181 ) ;
return V_36 ;
}
return ( V_36 < 0 ) ? V_36 : V_176 . V_179 ;
}
static int F_110 ( T_1 * V_78 , void * V_111 )
{
struct V_186 * V_187 = V_111 ;
struct V_188 * V_189 ;
int V_79 , V_36 ;
V_189 = & V_187 -> V_190 [ V_187 -> V_191 - 1 ] ;
V_79 = F_24 ( V_78 ) ;
if ( V_79 == V_46 ||
V_79 == V_44 ) {
V_36 = F_20 ( V_78 , V_187 -> V_85 . V_25 ,
V_187 -> V_85 . V_26 , & V_187 -> V_85 . V_27 ,
NULL ) ;
if ( V_36 == 0 || V_36 == - V_45 ) {
int V_37 ;
bool V_192 = ! V_187 -> V_193 ;
struct V_194 V_12 ;
F_111 ( & V_12 , 64 ) ;
if ( V_42 . V_43 ) {
if ( ! V_192 ) {
if ( V_36 )
F_112 ( & V_12 , L_69 ) ;
else
F_112 ( & V_12 , L_70 ) ;
} else
F_112 ( & V_12 , L_71 ) ;
}
V_37 = F_113 ( V_78 , & V_12 ) ;
if ( ! V_37 && V_42 . V_43 &&
! V_192 ) {
F_112 ( & V_12 , L_72 ) ;
V_37 = F_114 ( & V_187 -> V_85 . V_27 ,
V_78 , & V_12 ) ;
}
F_13 ( L_73 , V_12 . V_12 ) ;
if ( V_37 == 0 ) {
F_115 ( V_189 -> V_163 ,
F_116 ( & V_12 , NULL ) ) ;
}
F_117 ( & V_12 ) ;
}
}
if ( V_187 -> V_193 && F_103 ( V_78 , V_187 -> V_85 . V_25 ) )
return V_166 ;
else
return V_167 ;
}
static int F_118 ( T_1 * V_88 , struct V_84 * V_85 )
{
struct V_186 * V_187 =
F_107 ( V_85 , struct V_186 , V_85 ) ;
struct V_136 * V_137 = & V_85 -> V_117 -> V_118 ;
struct V_188 * V_189 ;
T_1 V_78 ;
int V_36 ;
if ( V_187 -> V_191 == V_187 -> V_195 ) {
F_28 ( L_67 , V_187 -> V_195 ) ;
return - V_45 ;
}
V_189 = & V_187 -> V_190 [ V_187 -> V_191 ++ ] ;
V_36 = F_52 ( & V_85 -> V_27 , V_187 -> V_8 , V_85 -> V_25 ,
V_137 -> V_92 , V_137 -> V_93 , & V_189 -> V_118 ) ;
if ( V_36 < 0 )
return V_36 ;
F_13 ( L_68 , V_189 -> V_118 . V_99 ,
V_189 -> V_118 . V_23 ) ;
V_189 -> V_163 = F_119 ( NULL , NULL ) ;
if ( V_189 -> V_163 == NULL )
return - V_51 ;
V_187 -> V_193 = true ;
F_105 ( V_88 , F_110 , ( void * ) V_187 , & V_78 ) ;
if ( ! V_42 . V_196 )
goto V_17;
V_187 -> V_193 = false ;
F_105 ( & V_85 -> V_90 , F_110 , ( void * ) V_187 , & V_78 ) ;
V_17:
if ( F_120 ( V_189 -> V_163 ) ) {
F_121 ( V_189 -> V_163 ) ;
V_189 -> V_163 = NULL ;
}
return V_36 ;
}
int F_122 ( struct V_1 * V_2 ,
struct V_184 * V_117 ,
struct V_188 * * V_190 )
{
struct V_186 V_187 = {
. V_85 = { . V_117 = V_117 , . V_109 = F_118 } ,
. V_8 = V_2 -> V_8 ,
. V_195 = V_42 . V_185 } ;
int V_36 ;
* V_190 = F_11 ( sizeof( struct V_188 ) * V_187 . V_195 ) ;
if ( * V_190 == NULL )
return - V_51 ;
V_187 . V_190 = * V_190 ;
V_187 . V_191 = 0 ;
V_36 = F_96 ( V_2 , & V_187 . V_85 ) ;
if ( V_36 < 0 ) {
while ( V_187 . V_191 -- ) {
F_12 ( & V_187 . V_190 [ V_187 . V_191 ] . V_118 . V_99 ) ;
F_121 ( V_187 . V_190 [ V_187 . V_191 ] . V_163 ) ;
}
F_12 ( V_190 ) ;
return V_36 ;
}
return ( V_36 < 0 ) ? V_36 : V_187 . V_191 ;
}
static int F_123 ( struct V_1 * V_2 , T_2 * V_21 )
{
int V_170 , V_169 ;
T_18 V_197 ;
T_19 * V_198 ;
T_15 * V_156 ;
T_17 V_199 , * V_158 ;
const char * V_200 ;
V_156 = F_124 ( V_2 -> V_8 , & V_2 -> V_9 ) ;
if ( ! V_156 )
return - V_41 ;
V_170 = F_125 ( V_2 -> V_8 ) ;
if ( V_170 < 0 )
return - V_10 ;
for ( V_169 = 0 ; V_169 < V_170 ; V_169 ++ ) {
V_200 = F_126 ( V_2 -> V_8 , V_169 , & V_197 ) ;
if ( strcmp ( V_200 , L_74 ) == 0 ) {
V_198 = F_127 ( V_156 , V_197 ) ;
if ( ! V_198 )
return - V_10 ;
V_158 = F_128 ( V_198 , & V_199 ) ;
if ( ! V_158 )
return - V_10 ;
* V_21 = V_158 -> V_201 ;
}
}
return 0 ;
}
int F_129 ( struct V_1 * V_2 , unsigned long V_25 ,
struct V_136 * V_202 )
{
T_1 V_203 , V_204 , V_205 ;
T_2 V_206 = 0 , V_207 = 0 ;
const char * V_119 = NULL , * V_208 = NULL , * V_209 = NULL , * V_31 ;
int V_210 = 0 , V_121 = 0 , V_36 = 0 ;
bool V_211 = false ;
V_212:
if ( ! F_130 ( V_2 -> V_2 , ( T_2 ) V_25 , & V_203 ) ) {
if ( ! V_211 && F_123 ( V_2 , & V_207 ) == 0 ) {
V_25 += V_207 ;
V_211 = true ;
goto V_212;
}
F_28 ( L_75 ,
V_25 ) ;
V_36 = - V_41 ;
goto V_182;
}
F_131 ( & V_203 , V_25 , & V_119 , & V_121 ) ;
if ( F_56 ( & V_203 , ( T_2 ) V_25 , & V_204 ) ) {
V_208 = V_209 = F_26 ( & V_204 ) ;
if ( ! V_208 ||
F_23 ( & V_204 , & V_207 ) != 0 ||
F_64 ( & V_204 , & V_210 ) != 0 ) {
V_121 = 0 ;
goto V_213;
}
V_119 = F_62 ( & V_204 ) ;
if ( V_25 == ( unsigned long ) V_207 ) {
V_121 = V_210 ;
goto V_213;
}
while ( F_132 ( & V_204 , ( T_2 ) V_25 ,
& V_205 ) ) {
if ( F_23 ( & V_205 , & V_206 ) == 0 &&
V_206 == V_25 ) {
V_121 = F_133 ( & V_205 ) ;
V_119 = F_134 ( & V_205 ) ;
break;
} else {
V_31 = F_26 ( & V_205 ) ;
if ( ! V_31 ||
F_64 ( & V_205 , & V_210 ) != 0 )
break;
V_208 = V_31 ;
V_204 = V_205 ;
}
}
V_31 = F_62 ( & V_204 ) ;
if ( ! V_31 || strcmp ( V_31 , V_119 ) != 0 )
V_121 = 0 ;
}
V_213:
if ( V_121 )
V_202 -> line = V_121 - V_210 ;
else if ( V_209 ) {
V_202 -> V_23 = V_25 - ( unsigned long ) V_207 ;
V_208 = V_209 ;
}
if ( V_208 ) {
V_202 -> V_93 = F_29 ( V_208 ) ;
if ( V_202 -> V_93 == NULL ) {
V_36 = - V_51 ;
goto V_182;
}
}
if ( V_119 ) {
V_202 -> V_114 = F_29 ( V_119 ) ;
if ( V_202 -> V_114 == NULL ) {
F_12 ( & V_202 -> V_93 ) ;
V_36 = - V_51 ;
goto V_182;
}
}
V_182:
if ( V_36 == 0 && ( V_119 || V_208 ) )
V_36 = 1 ;
return V_36 ;
}
static int F_135 ( const char * V_214 , unsigned int V_121 ,
struct V_215 * V_216 )
{
if ( ! V_216 -> V_3 ) {
V_216 -> V_3 = F_29 ( V_214 ) ;
if ( V_216 -> V_3 == NULL )
return - V_51 ;
}
return F_74 ( V_216 -> V_217 , V_121 ) ;
}
static int F_136 ( const char * V_119 , int V_121 ,
T_2 V_25 V_218 ,
void * V_111 )
{
struct V_219 * V_220 = V_111 ;
int V_221 ;
if ( ( F_68 ( V_119 , V_220 -> V_119 ) != 0 ) ||
( V_220 -> V_222 > V_121 || V_220 -> V_223 < V_121 ) )
return 0 ;
V_221 = F_135 ( V_119 , V_121 , V_220 -> V_216 ) ;
if ( V_221 < 0 && V_221 != - V_224 )
return V_221 ;
return 0 ;
}
static int F_137 ( T_1 * V_27 , struct V_219 * V_220 )
{
int V_36 ;
V_36 = F_70 ( V_27 ? : & V_220 -> V_90 , F_136 , V_220 ) ;
if ( V_36 >= 0 )
if ( ! F_78 ( V_220 -> V_216 -> V_217 ) )
V_36 = V_220 -> V_47 = 1 ;
else
V_36 = 0 ;
else {
F_12 ( & V_220 -> V_216 -> V_3 ) ;
}
return V_36 ;
}
static int F_138 ( T_1 * V_135 , void * V_111 )
{
int V_36 = F_137 ( V_135 , V_111 ) ;
return V_36 < 0 ? V_36 : 0 ;
}
static int F_139 ( T_1 * V_27 , void * V_111 )
{
struct V_138 * V_139 = V_111 ;
struct V_219 * V_220 = V_139 -> V_111 ;
struct V_215 * V_216 = V_220 -> V_216 ;
if ( V_216 -> V_114 && F_68 ( V_216 -> V_114 , F_62 ( V_27 ) ) )
return V_140 ;
if ( F_55 ( V_27 ) &&
F_63 ( V_27 , V_216 -> V_93 ) ) {
V_220 -> V_119 = F_62 ( V_27 ) ;
F_64 ( V_27 , & V_216 -> V_23 ) ;
F_13 ( L_76 , V_220 -> V_119 , V_216 -> V_23 ) ;
V_220 -> V_222 = V_216 -> V_23 + V_216 -> V_225 ;
if ( V_220 -> V_222 < 0 )
V_220 -> V_222 = V_120 ;
V_220 -> V_223 = V_216 -> V_23 + V_216 -> V_182 ;
if ( V_220 -> V_223 < 0 )
V_220 -> V_223 = V_120 ;
F_13 ( L_77 , V_220 -> V_222 , V_220 -> V_223 ) ;
V_216 -> V_225 = V_220 -> V_222 ;
V_216 -> V_182 = V_220 -> V_223 ;
if ( ! F_83 ( V_27 ) )
V_139 -> V_141 = F_84 ( V_27 ,
F_138 , V_220 ) ;
else
V_139 -> V_141 = F_137 ( V_27 , V_220 ) ;
return V_143 ;
}
return V_140 ;
}
static int F_140 ( struct V_219 * V_220 )
{
struct V_138 V_139 = { . V_111 = ( void * ) V_220 , . V_141 = 0 } ;
F_87 ( & V_220 -> V_90 , F_139 , & V_139 , 0 ) ;
return V_139 . V_141 ;
}
int F_141 ( struct V_1 * V_2 , struct V_215 * V_216 )
{
struct V_219 V_220 = { . V_216 = V_216 , . V_47 = 0 } ;
int V_36 = 0 ;
T_14 V_150 = 0 , V_151 ;
T_5 V_152 ;
T_1 * V_153 ;
const char * V_133 ;
if ( V_216 -> V_93 ) {
struct V_146 V_154 = {
. V_93 = V_216 -> V_93 , . V_114 = V_216 -> V_114 ,
. V_90 = & V_220 . V_90 , . V_27 = & V_220 . V_27 , . V_47 = 0 } ;
struct V_138 V_226 = {
. V_111 = ( void * ) & V_220 , . V_141 = 0 } ;
F_92 ( V_2 -> V_2 , F_88 ,
& V_154 , 0 ) ;
if ( V_154 . V_47 ) {
F_139 ( & V_220 . V_27 , & V_226 ) ;
if ( V_220 . V_47 )
goto V_47;
}
}
while ( ! V_220 . V_47 && V_36 >= 0 ) {
if ( F_93 ( V_2 -> V_2 , V_150 , & V_151 , & V_152 ,
NULL , NULL , NULL ) != 0 )
break;
V_153 = F_89 ( V_2 -> V_2 , V_150 + V_152 , & V_220 . V_90 ) ;
if ( ! V_153 )
continue;
if ( V_216 -> V_114 )
V_220 . V_119 = F_94 ( & V_220 . V_90 , V_216 -> V_114 ) ;
else
V_220 . V_119 = 0 ;
if ( ! V_216 -> V_114 || V_220 . V_119 ) {
if ( V_216 -> V_93 )
V_36 = F_140 ( & V_220 ) ;
else {
V_220 . V_222 = V_216 -> V_225 ;
V_220 . V_223 = V_216 -> V_182 ;
V_36 = F_137 ( NULL , & V_220 ) ;
}
}
V_150 = V_151 ;
}
V_47:
if ( V_220 . V_47 ) {
V_133 = F_79 ( & V_220 . V_90 ) ;
if ( V_133 ) {
V_216 -> V_133 = F_29 ( V_133 ) ;
if ( ! V_216 -> V_133 )
V_36 = - V_51 ;
}
}
F_13 ( L_78 , V_216 -> V_3 ) ;
return ( V_36 < 0 ) ? V_36 : V_220 . V_47 ;
}
int F_80 ( const char * V_227 , const char * V_133 ,
char * * V_228 )
{
const char * V_229 = V_230 . V_231 ;
if ( ! V_229 ) {
if ( V_227 [ 0 ] != '/' && V_133 )
V_229 = V_133 ;
else {
if ( F_142 ( V_227 , V_232 ) == 0 ) {
* V_228 = F_29 ( V_227 ) ;
return * V_228 ? 0 : - V_51 ;
} else
return - V_130 ;
}
}
* V_228 = malloc ( ( strlen ( V_229 ) + strlen ( V_227 ) + 2 ) ) ;
if ( ! * V_228 )
return - V_51 ;
for (; ; ) {
sprintf ( * V_228 , L_79 , V_229 , V_227 ) ;
if ( F_142 ( * V_228 , V_232 ) == 0 )
return 0 ;
if ( ! V_230 . V_231 ) {
F_12 ( V_228 ) ;
return - V_130 ;
}
switch ( V_130 ) {
case V_233 :
case V_10 :
case V_234 :
case V_235 :
V_227 = strchr ( ++ V_227 , '/' ) ;
if ( ! V_227 ) {
F_12 ( V_228 ) ;
return - V_10 ;
}
continue;
default:
F_12 ( V_228 ) ;
return - V_130 ;
}
}
}
