static int F_1 ( struct V_1 * V_2 , int line )
{
struct V_3 * V_4 ;
struct V_1 * V_5 ;
F_2 (ln, head, list) {
if ( V_4 -> line < line ) {
V_5 = & V_4 -> V_6 ;
goto V_7;
} else if ( V_4 -> line == line )
return 1 ;
}
V_5 = V_2 ;
V_7:
F_3 ( L_1 , line ) ;
V_4 = F_4 ( sizeof( struct V_3 ) ) ;
if ( V_4 == NULL )
return - V_8 ;
V_4 -> line = line ;
F_5 ( & V_4 -> V_6 ) ;
F_6 ( & V_4 -> V_6 , V_5 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , int line )
{
struct V_3 * V_4 ;
F_8 (ln, head, list)
if ( V_4 -> line == line )
return 1 ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_5 ( V_2 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
while ( ! F_11 ( V_2 ) ) {
V_4 = F_12 ( V_2 , struct V_3 , V_6 ) ;
F_13 ( & V_4 -> V_6 ) ;
free ( V_4 ) ;
}
}
static int F_14 ( struct V_9 * V_10 ,
const char * V_11 )
{
int V_12 ;
V_12 = F_15 ( V_11 , V_13 ) ;
if ( V_12 < 0 )
return V_12 ;
V_10 -> V_14 = F_16 ( & V_15 ) ;
if ( ! V_10 -> V_14 )
goto error;
V_10 -> V_16 = F_17 ( V_10 -> V_14 , L_2 , L_2 , V_12 ) ;
if ( ! V_10 -> V_16 )
goto error;
V_10 -> V_10 = F_18 ( V_10 -> V_16 , & V_10 -> V_17 ) ;
if ( ! V_10 -> V_10 )
goto error;
return 0 ;
error:
if ( V_10 -> V_14 )
F_19 ( V_10 -> V_14 ) ;
else
F_20 ( V_12 ) ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
return - V_18 ;
}
static int F_21 ( T_1 * V_16 ,
void * * V_19 ,
const char * V_20 ,
T_2 V_21 ,
char * * V_22 , T_3 * * V_23 )
{
int V_12 ;
const char * V_11 = F_22 ( V_20 ) ;
F_23 ( L_3 , V_11 , V_20 ) ;
if ( V_11 ) {
V_12 = F_15 ( V_11 , V_13 ) ;
if ( V_12 >= 0 ) {
* V_22 = F_24 ( V_11 ) ;
return V_12 ;
}
}
return F_25 ( V_16 , V_19 , V_20 , V_21 ,
V_22 , V_23 ) ;
}
static int F_26 ( struct V_9 * V_10 ,
T_2 V_24 )
{
V_10 -> V_14 = F_16 ( & V_25 ) ;
if ( ! V_10 -> V_14 )
return - V_26 ;
F_27 ( V_10 -> V_14 ) ;
F_28 ( V_10 -> V_14 ) ;
V_10 -> V_10 = F_29 ( V_10 -> V_14 , V_24 , & V_10 -> V_17 ) ;
if ( ! V_10 -> V_10 ) {
F_3 ( L_4 ,
( unsigned long ) V_24 ) ;
F_19 ( V_10 -> V_14 ) ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
return - V_18 ;
}
return 0 ;
}
static int F_26 ( struct V_9 * V_10 ,
T_2 V_24 V_27 )
{
const char * V_11 = F_22 ( L_5 ) ;
if ( ! V_11 ) {
F_30 ( L_6 ) ;
return - V_18 ;
}
F_23 ( L_7 , V_11 ) ;
return F_14 ( V_10 , V_11 ) ;
}
struct V_9 * F_31 ( const char * V_11 )
{
struct V_9 * V_10 = F_4 ( sizeof( * V_10 ) ) ;
if ( ! V_10 )
return NULL ;
if ( F_14 ( V_10 , V_11 ) < 0 ) {
free ( V_10 ) ;
V_10 = NULL ;
}
return V_10 ;
}
struct V_9 * F_32 ( unsigned long V_24 )
{
struct V_9 * V_10 = F_4 ( sizeof( * V_10 ) ) ;
if ( ! V_10 )
return NULL ;
if ( F_26 ( V_10 , ( T_2 ) V_24 ) < 0 ) {
free ( V_10 ) ;
V_10 = NULL ;
}
return V_10 ;
}
void F_33 ( struct V_9 * V_10 )
{
if ( V_10 ) {
if ( V_10 -> V_14 )
F_19 ( V_10 -> V_14 ) ;
free ( V_10 ) ;
}
}
static struct V_28 * F_34 ( long V_29 )
{
struct V_28 * V_30 ;
V_30 = F_4 ( sizeof( struct V_28 ) ) ;
if ( V_30 != NULL )
V_30 -> V_31 = V_29 ;
return V_30 ;
}
static int F_35 ( T_4 * V_32 , T_2 V_24 ,
T_5 * V_33 , T_4 * V_34 ,
struct V_35 * V_36 )
{
T_6 V_37 ;
T_2 V_38 = 0 ;
T_5 * V_39 ;
T_7 V_40 ;
unsigned int V_41 ;
T_8 V_29 = 0 ;
bool V_30 = false ;
const char * V_42 ;
int V_43 ;
if ( F_36 ( V_32 , V_44 , & V_37 ) != NULL )
goto V_45;
if ( F_36 ( V_32 , V_46 , & V_37 ) == NULL )
return - V_26 ;
if ( F_37 ( & V_37 , V_24 , & V_39 , & V_40 , 1 ) <= 0 ) {
V_43 = F_38 ( V_34 , & V_38 ) ;
if ( V_43 || V_24 != V_38 ||
F_39 ( V_32 ) != V_47 ||
F_40 ( V_34 , & V_38 ) )
return - V_18 ;
for ( V_24 += 1 ; V_24 <= V_38 ; V_24 ++ ) {
if ( F_37 ( & V_37 , V_24 , & V_39 ,
& V_40 , 1 ) > 0 )
goto V_7;
}
return - V_18 ;
}
V_7:
if ( V_40 == 0 )
return - V_18 ;
if ( V_39 -> V_48 == V_49 ) {
V_45:
if ( ! V_36 )
return 0 ;
V_43 = strlen ( F_41 ( V_32 ) ) ;
V_36 -> V_50 = F_4 ( V_43 + 2 ) ;
if ( V_36 -> V_50 == NULL )
return - V_8 ;
snprintf ( V_36 -> V_50 , V_43 + 2 , L_8 , F_41 ( V_32 ) ) ;
V_36 -> V_30 = F_34 ( ( long ) V_29 ) ;
if ( V_36 -> V_30 == NULL )
return - V_8 ;
return 0 ;
}
if ( V_39 -> V_48 == V_51 ) {
if ( V_33 == NULL )
return - V_52 ;
V_30 = true ;
V_29 = V_39 -> V_53 ;
V_39 = & V_33 [ 0 ] ;
}
if ( V_39 -> V_48 >= V_54 && V_39 -> V_48 <= V_55 ) {
V_41 = V_39 -> V_48 - V_54 ;
V_29 += V_39 -> V_53 ;
V_30 = true ;
} else if ( V_39 -> V_48 >= V_56 && V_39 -> V_48 <= V_57 ) {
V_41 = V_39 -> V_48 - V_56 ;
} else if ( V_39 -> V_48 == V_58 ) {
V_41 = V_39 -> V_53 ;
V_29 += V_39 -> V_59 ;
V_30 = true ;
} else if ( V_39 -> V_48 == V_60 ) {
V_41 = V_39 -> V_53 ;
} else {
F_3 ( L_9 , V_39 -> V_48 ) ;
return - V_52 ;
}
if ( ! V_36 )
return 0 ;
V_42 = F_42 ( V_41 ) ;
if ( ! V_42 ) {
F_43 ( L_10
L_11 , V_41 ) ;
return - V_61 ;
}
V_36 -> V_50 = F_24 ( V_42 ) ;
if ( V_36 -> V_50 == NULL )
return - V_8 ;
if ( V_30 ) {
V_36 -> V_30 = F_34 ( ( long ) V_29 ) ;
if ( V_36 -> V_30 == NULL )
return - V_8 ;
}
return 0 ;
}
static int F_44 ( T_4 * V_32 ,
struct V_35 * V_36 ,
const char * V_62 )
{
struct V_28 * * V_63 = & V_36 -> V_30 ;
T_4 type ;
char V_64 [ 16 ] ;
int V_65 , V_66 , V_67 ;
int V_43 ;
if ( V_62 && strcmp ( V_62 , L_12 ) != 0 ) {
V_36 -> type = F_24 ( V_62 ) ;
return ( V_36 -> type == NULL ) ? - V_8 : 0 ;
}
V_65 = F_45 ( V_32 ) ;
if ( V_65 > 0 ) {
V_66 = F_46 ( V_32 ) ;
V_67 = F_47 ( V_32 ) ;
if ( V_66 < 0 || V_67 < 0 )
return - V_18 ;
V_43 = snprintf ( V_64 , 16 , L_13 , V_65 , V_66 ,
F_48 ( V_67 ) ) ;
goto V_68;
}
if ( F_49 ( V_32 , & type ) == NULL ) {
F_43 ( L_14 ,
F_41 ( V_32 ) ) ;
return - V_18 ;
}
F_3 ( L_15 ,
F_41 ( V_32 ) , F_41 ( & type ) ) ;
if ( V_62 && strcmp ( V_62 , L_12 ) == 0 ) {
V_43 = F_39 ( & type ) ;
if ( V_43 != V_69 &&
V_43 != V_70 ) {
F_43 ( L_16
L_17 ,
F_41 ( V_32 ) , F_41 ( & type ) ) ;
return - V_26 ;
}
if ( F_49 ( & type , & type ) == NULL ) {
F_43 ( L_18
L_19 ) ;
return - V_18 ;
}
if ( V_43 == V_69 ) {
while ( * V_63 )
V_63 = & ( * V_63 ) -> V_71 ;
* V_63 = F_4 ( sizeof( struct V_28 ) ) ;
if ( * V_63 == NULL ) {
F_43 ( L_20 ) ;
return - V_8 ;
}
}
if ( ! F_50 ( & type , L_21 ) &&
! F_50 ( & type , L_22 ) ) {
F_43 ( L_16
L_23 ,
F_41 ( V_32 ) ) ;
return - V_26 ;
}
V_36 -> type = F_24 ( V_62 ) ;
return ( V_36 -> type == NULL ) ? - V_8 : 0 ;
}
V_43 = F_47 ( & type ) ;
if ( V_43 <= 0 )
return 0 ;
V_43 = F_48 ( V_43 ) ;
if ( V_43 > V_72 ) {
F_51 ( L_24 ,
F_41 ( & type ) , V_72 ) ;
V_43 = V_72 ;
}
V_43 = snprintf ( V_64 , 16 , L_25 ,
F_52 ( & type ) ? 's' : 'u' , V_43 ) ;
V_68:
if ( V_43 < 0 || V_43 >= 16 ) {
if ( V_43 >= 16 )
V_43 = - V_73 ;
F_43 ( L_26 ,
strerror ( - V_43 ) ) ;
return V_43 ;
}
V_36 -> type = F_24 ( V_64 ) ;
if ( V_36 -> type == NULL )
return - V_8 ;
return 0 ;
}
static int F_53 ( T_4 * V_32 , const char * V_74 ,
struct V_75 * V_76 ,
struct V_28 * * V_63 ,
T_4 * V_77 )
{
struct V_28 * V_30 = * V_63 ;
T_4 type ;
T_8 V_29 ;
int V_43 , V_78 ;
F_3 ( L_27 , V_76 -> V_79 , V_74 ) ;
if ( F_49 ( V_32 , & type ) == NULL ) {
F_43 ( L_28 , V_74 ) ;
return - V_18 ;
}
F_23 ( L_29 , ( unsigned ) F_54 ( & type ) ) ;
V_78 = F_39 ( & type ) ;
if ( V_76 -> V_79 [ 0 ] == '[' &&
( V_78 == V_70 || V_78 == V_69 ) ) {
if ( V_76 -> V_71 )
memcpy ( V_77 , & type , sizeof( * V_77 ) ) ;
if ( F_49 ( & type , & type ) == NULL ) {
F_43 ( L_28 , V_74 ) ;
return - V_18 ;
}
F_23 ( L_30 ,
( unsigned ) F_54 ( & type ) ) ;
if ( V_78 == V_69 ) {
V_30 = F_4 ( sizeof( struct V_28 ) ) ;
if ( V_30 == NULL )
return - V_8 ;
if ( * V_63 )
( * V_63 ) -> V_71 = V_30 ;
else
* V_63 = V_30 ;
}
V_30 -> V_31 += F_47 ( & type ) * V_76 -> V_80 ;
if ( ! V_76 -> V_71 )
memcpy ( V_77 , V_32 , sizeof( * V_77 ) ) ;
goto V_71;
} else if ( V_78 == V_69 ) {
if ( ! V_76 -> V_30 ) {
F_30 ( L_31 ,
V_76 -> V_79 ) ;
return - V_26 ;
}
if ( F_49 ( & type , & type ) == NULL ) {
F_43 ( L_28 , V_74 ) ;
return - V_18 ;
}
V_78 = F_39 ( & type ) ;
if ( V_78 != V_81 && V_78 != V_82 ) {
F_43 ( L_32 ,
V_74 ) ;
return - V_26 ;
}
V_30 = F_4 ( sizeof( struct V_28 ) ) ;
if ( V_30 == NULL )
return - V_8 ;
if ( * V_63 )
( * V_63 ) -> V_71 = V_30 ;
else
* V_63 = V_30 ;
} else {
if ( V_78 != V_81 && V_78 != V_82 ) {
F_43 ( L_32 ,
V_74 ) ;
return - V_26 ;
}
if ( V_76 -> V_79 [ 0 ] == '[' ) {
F_30 ( L_33
L_34 , V_74 ) ;
return - V_26 ;
}
if ( V_76 -> V_30 ) {
F_30 ( L_35 ,
V_76 -> V_79 ) ;
return - V_26 ;
}
if ( ! V_30 ) {
F_43 ( L_36
L_37 ) ;
return - V_52 ;
}
}
if ( F_55 ( & type , V_76 -> V_79 , V_77 ) == NULL ) {
F_43 ( L_38 , V_74 ,
F_41 ( & type ) , V_76 -> V_79 ) ;
return - V_26 ;
}
if ( V_78 == V_82 ) {
V_29 = 0 ;
} else {
V_43 = F_56 ( V_77 , & V_29 ) ;
if ( V_43 < 0 ) {
F_43 ( L_39 ,
V_76 -> V_79 ) ;
return V_43 ;
}
}
V_30 -> V_31 += ( long ) V_29 ;
V_71:
if ( V_76 -> V_71 )
return F_53 ( V_77 , V_76 -> V_79 ,
V_76 -> V_71 , & V_30 , V_77 ) ;
else
return 0 ;
}
static int F_57 ( T_4 * V_32 , struct V_83 * V_84 )
{
T_4 V_77 ;
int V_43 ;
F_3 ( L_40 ,
F_41 ( V_32 ) ) ;
V_43 = F_35 ( V_32 , V_84 -> V_24 , V_84 -> V_33 ,
& V_84 -> V_34 , V_84 -> V_36 ) ;
if ( V_43 == - V_18 )
F_30 ( L_41
L_42 , V_84 -> V_85 -> V_86 ) ;
else if ( V_43 == - V_52 )
F_30 ( L_43 ) ;
else if ( V_84 -> V_85 -> V_76 ) {
V_43 = F_53 ( V_32 , V_84 -> V_85 -> V_86 ,
V_84 -> V_85 -> V_76 , & V_84 -> V_36 -> V_30 ,
& V_77 ) ;
V_32 = & V_77 ;
}
if ( V_43 == 0 )
V_43 = F_44 ( V_32 , V_84 -> V_36 , V_84 -> V_85 -> type ) ;
return V_43 ;
}
static int F_58 ( T_4 * V_87 , struct V_83 * V_84 )
{
T_4 V_32 ;
char V_64 [ 32 ] , * V_88 ;
int V_43 = 0 ;
if ( ! F_59 ( V_84 -> V_85 -> V_86 ) ) {
V_84 -> V_36 -> V_50 = F_24 ( V_84 -> V_85 -> V_86 ) ;
if ( V_84 -> V_36 -> V_50 == NULL )
return - V_8 ;
if ( V_84 -> V_85 -> type ) {
V_84 -> V_36 -> type = F_24 ( V_84 -> V_85 -> type ) ;
if ( V_84 -> V_36 -> type == NULL )
return - V_8 ;
}
if ( V_84 -> V_85 -> V_79 ) {
V_84 -> V_36 -> V_79 = F_24 ( V_84 -> V_85 -> V_79 ) ;
if ( V_84 -> V_36 -> V_79 == NULL )
return - V_8 ;
} else
V_84 -> V_36 -> V_79 = NULL ;
return 0 ;
}
if ( V_84 -> V_85 -> V_79 )
V_84 -> V_36 -> V_79 = F_24 ( V_84 -> V_85 -> V_79 ) ;
else {
V_43 = F_60 ( V_84 -> V_85 , V_64 , 32 ) ;
if ( V_43 < 0 )
return V_43 ;
V_88 = strchr ( V_64 , ':' ) ;
if ( V_88 )
* V_88 = '_' ;
V_84 -> V_36 -> V_79 = F_24 ( V_64 ) ;
}
if ( V_84 -> V_36 -> V_79 == NULL )
return - V_8 ;
F_3 ( L_44 , V_84 -> V_85 -> V_86 ) ;
if ( ! F_61 ( V_87 , V_84 -> V_85 -> V_86 , V_84 -> V_24 , & V_32 ) ) {
if ( ! F_61 ( & V_84 -> V_89 , V_84 -> V_85 -> V_86 , 0 , & V_32 ) )
V_43 = - V_18 ;
}
if ( V_43 >= 0 )
V_43 = F_57 ( & V_32 , V_84 ) ;
if ( V_43 < 0 )
F_43 ( L_45 ,
V_84 -> V_85 -> V_86 ) ;
return V_43 ;
}
static int F_62 ( T_4 * V_34 , T_1 * V_16 ,
T_2 V_90 , bool V_91 ,
struct V_92 * V_93 )
{
T_2 V_94 , V_95 ;
T_9 V_96 ;
const char * V_97 ;
if ( F_38 ( V_34 , & V_94 ) != 0 ) {
F_43 ( L_46 ,
F_41 ( V_34 ) ) ;
return - V_18 ;
}
if ( F_40 ( V_34 , & V_95 ) != 0 ) {
F_43 ( L_47 ,
F_41 ( V_34 ) ) ;
return - V_18 ;
}
if ( V_90 > V_95 ) {
F_43 ( L_48 ,
F_41 ( V_34 ) ) ;
return - V_26 ;
}
V_97 = F_63 ( V_16 , V_90 , & V_96 , NULL ) ;
if ( ! V_97 ) {
F_43 ( L_49 ,
( unsigned long ) V_90 ) ;
return - V_18 ;
}
V_93 -> V_31 = ( unsigned long ) ( V_90 - V_96 . V_98 ) ;
V_93 -> V_97 = F_24 ( V_97 ) ;
if ( ! V_93 -> V_97 )
return - V_8 ;
if ( V_91 ) {
if ( V_94 != V_90 ) {
F_43 ( L_50
L_51 ) ;
return - V_26 ;
}
V_93 -> V_91 = true ;
}
return 0 ;
}
static int F_64 ( T_4 * V_87 , struct V_83 * V_84 )
{
T_6 V_99 ;
T_7 V_40 ;
int V_43 ;
if ( ! V_87 ) {
F_30 ( L_52 ) ;
return - V_26 ;
}
if ( ! F_65 ( V_87 ) ) {
if ( ! F_66 ( & V_84 -> V_89 , V_84 -> V_24 , & V_84 -> V_34 ) ) {
F_43 ( L_53
L_54 ) ;
return - V_18 ;
}
} else
memcpy ( & V_84 -> V_34 , V_87 , sizeof( T_4 ) ) ;
F_36 ( & V_84 -> V_34 , V_100 , & V_99 ) ;
V_43 = F_37 ( & V_99 , V_84 -> V_24 , & V_84 -> V_33 , & V_40 , 1 ) ;
if ( V_43 <= 0 || V_40 == 0 ) {
V_84 -> V_33 = NULL ;
#if F_67 ( 0 , 142 )
} else if ( V_40 == 1 && V_84 -> V_33 [ 0 ] . V_48 == V_101 &&
V_84 -> V_102 != NULL ) {
T_10 * V_103 ;
if ( F_68 ( V_84 -> V_102 , V_84 -> V_24 , & V_103 ) != 0 ||
F_69 ( V_103 , & V_84 -> V_33 , & V_40 ) != 0 ) {
F_43 ( L_55 ,
( V_104 ) V_84 -> V_24 ) ;
return - V_18 ;
}
#endif
}
V_43 = V_84 -> V_105 ( V_87 , V_84 ) ;
V_84 -> V_33 = NULL ;
return V_43 ;
}
static int F_70 ( T_4 * V_106 , void * V_107 )
{
struct V_108 * V_109 = V_107 ;
const char * V_110 ;
int V_111 ;
if ( V_109 -> V_110 ) {
V_110 = F_71 ( V_106 ) ;
if ( ! V_110 || strcmp ( V_109 -> V_110 , V_110 ) != 0 )
return 0 ;
}
if ( V_109 -> V_112 ) {
if ( F_50 ( V_106 , V_109 -> V_112 ) ) {
memcpy ( V_109 -> V_77 , V_106 , sizeof( T_4 ) ) ;
V_109 -> V_7 = true ;
return 1 ;
}
} else {
F_72 ( V_106 , & V_111 ) ;
if ( V_111 < V_109 -> line && V_109 -> V_113 > V_109 -> line - V_111 ) {
V_109 -> V_113 = V_109 -> line - V_111 ;
memcpy ( V_109 -> V_77 , V_106 , sizeof( T_4 ) ) ;
V_109 -> V_7 = true ;
}
}
return 0 ;
}
static T_4 * F_73 ( struct V_83 * V_84 , T_4 * V_77 )
{
struct V_108 V_109 = {
. V_112 = V_84 -> V_114 -> V_115 . V_112 ,
. V_110 = V_84 -> V_116 ,
. line = V_84 -> V_111 ,
. V_113 = V_117 ,
. V_77 = V_77 ,
. V_7 = false ,
} ;
F_74 ( & V_84 -> V_89 , V_84 -> V_24 , F_70 , & V_109 ) ;
return V_109 . V_7 ? V_77 : NULL ;
}
static int F_75 ( const char * V_116 , int V_118 ,
T_2 V_24 , void * V_107 )
{
struct V_83 * V_84 = V_107 ;
T_4 * V_87 , V_77 ;
int V_43 ;
if ( V_118 != V_84 -> V_111 || F_76 ( V_116 , V_84 -> V_116 ) != 0 )
return 0 ;
V_84 -> V_24 = V_24 ;
V_87 = F_73 ( V_84 , & V_77 ) ;
if ( ! V_87 ) {
F_43 ( L_56 ) ;
return - V_18 ;
}
V_43 = F_64 ( V_87 , V_84 ) ;
return V_43 < 0 ? V_43 : 0 ;
}
static int F_77 ( struct V_83 * V_84 )
{
return F_78 ( & V_84 -> V_89 , F_75 , V_84 ) ;
}
static int F_79 ( struct V_1 * V_2 ,
const char * V_116 , const char * V_119 )
{
T_11 * V_120 ;
char * line = NULL ;
T_7 V_121 ;
T_12 V_122 ;
int V_123 = 0 , V_124 = 1 ;
V_120 = fopen ( V_116 , L_57 ) ;
if ( ! V_120 ) {
F_43 ( L_58 , V_116 , strerror ( V_125 ) ) ;
return - V_125 ;
}
while ( ( V_122 = F_80 ( & line , & V_121 , V_120 ) ) > 0 ) {
if ( line [ V_122 - 1 ] == '\n' )
line [ V_122 - 1 ] = '\0' ;
if ( F_81 ( line , V_119 ) ) {
F_1 ( V_2 , V_124 ) ;
V_123 ++ ;
}
V_124 ++ ;
}
if ( ferror ( V_120 ) )
V_123 = - V_125 ;
free ( line ) ;
fclose ( V_120 ) ;
if ( V_123 == 0 )
F_3 ( L_59 , V_116 ) ;
return V_123 ;
}
static int F_82 ( const char * V_116 , int V_118 ,
T_2 V_24 , void * V_107 )
{
struct V_83 * V_84 = V_107 ;
T_4 * V_87 , V_77 ;
int V_43 ;
if ( ! F_7 ( & V_84 -> V_126 , V_118 ) ||
F_76 ( V_116 , V_84 -> V_116 ) != 0 )
return 0 ;
F_3 ( L_60 ,
V_118 , ( unsigned long long ) V_24 ) ;
V_84 -> V_24 = V_24 ;
V_84 -> V_111 = V_118 ;
V_87 = F_73 ( V_84 , & V_77 ) ;
if ( ! V_87 ) {
F_43 ( L_56 ) ;
return - V_18 ;
}
V_43 = F_64 ( V_87 , V_84 ) ;
return V_43 < 0 ? V_43 : 0 ;
}
static int F_83 ( T_4 * V_34 , struct V_83 * V_84 )
{
int V_43 = 0 ;
if ( F_11 ( & V_84 -> V_126 ) ) {
V_43 = F_79 ( & V_84 -> V_126 , V_84 -> V_116 ,
V_84 -> V_114 -> V_115 . V_127 ) ;
if ( V_43 <= 0 )
return V_43 ;
}
return F_78 ( V_34 , F_82 , V_84 ) ;
}
static int F_84 ( T_4 * V_128 , void * V_107 )
{
struct V_83 * V_84 = V_107 ;
struct V_129 * V_130 = & V_84 -> V_114 -> V_115 ;
T_2 V_24 ;
int V_43 ;
if ( V_130 -> V_127 )
V_43 = F_83 ( V_128 , V_84 ) ;
else {
if ( F_38 ( V_128 , & V_24 ) != 0 ) {
F_43 ( L_61 ,
F_41 ( V_128 ) ) ;
return - V_18 ;
}
V_84 -> V_24 = V_24 ;
V_84 -> V_24 += V_130 -> V_31 ;
F_3 ( L_62 ,
( V_104 ) V_84 -> V_24 ) ;
V_43 = F_64 ( V_128 , V_84 ) ;
}
return V_43 ;
}
static int F_85 ( T_4 * V_34 , void * V_107 )
{
struct V_131 * V_132 = V_107 ;
struct V_83 * V_84 = V_132 -> V_107 ;
struct V_129 * V_130 = & V_84 -> V_114 -> V_115 ;
if ( ! F_65 ( V_34 ) ||
! F_50 ( V_34 , V_130 -> V_112 ) )
return V_133 ;
if ( V_130 -> V_110 && F_76 ( V_130 -> V_110 , F_71 ( V_34 ) ) )
return V_133 ;
V_84 -> V_116 = F_71 ( V_34 ) ;
if ( V_130 -> line ) {
F_72 ( V_34 , & V_84 -> V_111 ) ;
V_84 -> V_111 += V_130 -> line ;
V_132 -> V_134 = F_77 ( V_84 ) ;
} else if ( ! F_86 ( V_34 ) ) {
if ( V_130 -> V_127 )
V_132 -> V_134 = F_83 ( V_34 , V_84 ) ;
else {
if ( F_38 ( V_34 , & V_84 -> V_24 ) != 0 ) {
F_43 ( L_63
L_64 , F_41 ( V_34 ) ) ;
V_132 -> V_134 = - V_18 ;
return V_135 ;
}
V_84 -> V_24 += V_130 -> V_31 ;
V_132 -> V_134 = F_64 ( V_34 , V_84 ) ;
}
} else
V_132 -> V_134 = F_87 ( V_34 ,
F_84 , ( void * ) V_84 ) ;
return V_135 ;
}
static int F_88 ( struct V_83 * V_84 )
{
struct V_131 V_136 = { . V_107 = ( void * ) V_84 ,
. V_134 = 0 } ;
F_89 ( & V_84 -> V_89 , F_85 , & V_136 , 0 ) ;
return V_136 . V_134 ;
}
static int F_90 ( T_13 * V_10 , T_14 * V_137 , void * V_107 )
{
struct V_138 * V_132 = V_107 ;
if ( F_91 ( V_10 , V_137 -> V_139 , V_132 -> V_34 ) ) {
if ( F_39 ( V_132 -> V_34 ) != V_140 )
return V_133 ;
if ( F_50 ( V_132 -> V_34 , V_132 -> V_112 ) ) {
if ( ! F_91 ( V_10 , V_137 -> V_141 , V_132 -> V_89 ) )
return V_133 ;
if ( V_132 -> V_110 &&
F_76 ( V_132 -> V_110 , F_71 ( V_132 -> V_34 ) ) )
return V_133 ;
V_132 -> V_7 = 1 ;
return V_135 ;
}
}
return V_133 ;
}
static int F_92 ( struct V_9 * V_10 ,
struct V_83 * V_84 )
{
struct V_129 * V_130 = & V_84 -> V_114 -> V_115 ;
T_15 V_142 , V_143 ;
T_7 V_144 ;
T_4 * V_145 ;
int V_43 = 0 ;
#if F_67 ( 0 , 142 )
V_84 -> V_102 = F_93 ( V_10 -> V_10 ) ;
#endif
V_142 = 0 ;
F_9 ( & V_84 -> V_126 ) ;
if ( V_130 -> V_112 ) {
struct V_138 V_146 = {
. V_112 = V_130 -> V_112 ,
. V_110 = V_130 -> V_110 ,
. V_89 = & V_84 -> V_89 ,
. V_34 = & V_84 -> V_34 ,
. V_7 = 0 ,
} ;
struct V_131 V_147 = {
. V_107 = V_84 ,
} ;
F_94 ( V_10 -> V_10 , F_90 ,
& V_146 , 0 ) ;
if ( V_146 . V_7 ) {
V_43 = F_85 ( & V_84 -> V_34 , & V_147 ) ;
if ( V_43 )
goto V_7;
}
}
while ( ! F_95 ( V_10 -> V_10 , V_142 , & V_143 , & V_144 , NULL , NULL , NULL ) ) {
V_145 = F_91 ( V_10 -> V_10 , V_142 + V_144 , & V_84 -> V_89 ) ;
if ( ! V_145 )
continue;
if ( V_130 -> V_110 )
V_84 -> V_116 = F_96 ( & V_84 -> V_89 , V_130 -> V_110 ) ;
else
V_84 -> V_116 = NULL ;
if ( ! V_130 -> V_110 || V_84 -> V_116 ) {
if ( V_130 -> V_112 )
V_43 = F_88 ( V_84 ) ;
else if ( V_130 -> V_127 )
V_43 = F_83 ( NULL , V_84 ) ;
else {
V_84 -> V_111 = V_130 -> line ;
V_43 = F_77 ( V_84 ) ;
}
if ( V_43 < 0 )
break;
}
V_142 = V_143 ;
}
V_7:
F_10 ( & V_84 -> V_126 ) ;
return V_43 ;
}
static int F_97 ( T_4 * V_77 , void * V_107 )
{
struct V_148 * V_149 = V_107 ;
struct V_83 * V_84 = V_149 -> V_84 ;
int V_78 ;
V_78 = F_39 ( V_77 ) ;
if ( V_78 == V_47 ||
V_78 == V_150 ) {
if ( F_35 ( V_77 , V_149 -> V_84 -> V_24 ,
V_149 -> V_84 -> V_33 , & V_84 -> V_34 ,
NULL ) == 0 ) {
V_149 -> args [ V_149 -> V_151 ] . V_86 = ( char * ) F_41 ( V_77 ) ;
if ( V_149 -> args [ V_149 -> V_151 ] . V_86 == NULL ) {
V_149 -> V_43 = - V_8 ;
return V_152 ;
}
F_3 ( L_65 , V_149 -> args [ V_149 -> V_151 ] . V_86 ) ;
V_149 -> V_151 ++ ;
}
}
if ( F_98 ( V_77 , V_149 -> V_84 -> V_24 ) )
return V_153 ;
else
return V_154 ;
}
static int F_99 ( T_4 * V_87 , struct V_83 * V_84 ,
struct V_155 * args )
{
T_4 V_77 ;
int V_156 ;
int V_157 = 0 ;
struct V_148 V_149 = { . V_84 = V_84 , . args = args ,
. V_158 = V_159 , . V_43 = 0 } ;
for ( V_156 = 0 ; V_156 < V_84 -> V_114 -> V_151 ; V_156 ++ ) {
if ( strcmp ( V_84 -> V_114 -> args [ V_156 ] . V_86 , L_66 ) == 0 ) {
F_3 ( L_67 ) ;
V_149 . V_151 = V_157 ;
F_100 ( V_87 , F_97 , ( void * ) & V_149 ,
& V_77 ) ;
F_3 ( L_68 , V_149 . V_151 - V_157 ) ;
if ( V_149 . V_43 < 0 )
return V_149 . V_43 ;
V_157 = V_149 . V_151 ;
} else {
args [ V_157 ] = V_84 -> V_114 -> args [ V_156 ] ;
V_157 ++ ;
}
}
return V_157 ;
}
static int F_101 ( T_4 * V_87 , struct V_83 * V_84 )
{
struct V_160 * V_161 =
F_102 ( V_84 , struct V_160 , V_84 ) ;
struct V_162 * V_163 ;
struct V_155 * args ;
int V_43 , V_156 ;
if ( V_161 -> V_164 == V_161 -> V_165 ) {
F_43 ( L_69 ,
V_161 -> V_165 ) ;
return - V_61 ;
}
V_163 = & V_161 -> V_166 [ V_161 -> V_164 ++ ] ;
V_43 = F_62 ( & V_84 -> V_34 , V_161 -> V_16 , V_84 -> V_24 ,
V_84 -> V_114 -> V_115 . V_91 , & V_163 -> V_115 ) ;
if ( V_43 < 0 )
return V_43 ;
F_3 ( L_70 , V_163 -> V_115 . V_97 ,
V_163 -> V_115 . V_31 ) ;
args = F_4 ( sizeof( struct V_155 ) * V_159 ) ;
if ( args == NULL )
return - V_8 ;
V_43 = F_99 ( V_87 , V_84 , args ) ;
if ( V_43 < 0 )
goto V_167;
V_163 -> V_151 = V_43 ;
V_163 -> args = F_4 ( sizeof( struct V_35 ) * V_163 -> V_151 ) ;
if ( V_163 -> args == NULL ) {
V_43 = - V_8 ;
goto V_167;
}
for ( V_156 = 0 ; V_156 < V_163 -> V_151 ; V_156 ++ ) {
V_84 -> V_85 = & args [ V_156 ] ;
V_84 -> V_36 = & V_163 -> args [ V_156 ] ;
V_43 = F_58 ( V_87 , V_84 ) ;
if ( V_43 != 0 )
break;
}
V_167:
free ( args ) ;
return V_43 ;
}
int F_103 ( struct V_9 * V_10 ,
struct V_168 * V_114 ,
struct V_162 * * V_166 , int V_165 )
{
struct V_160 V_161 = {
. V_84 = { . V_114 = V_114 , . V_105 = F_101 } ,
. V_16 = V_10 -> V_16 , . V_165 = V_165 } ;
int V_43 ;
* V_166 = F_4 ( sizeof( struct V_162 ) * V_165 ) ;
if ( * V_166 == NULL )
return - V_8 ;
V_161 . V_166 = * V_166 ;
V_161 . V_164 = 0 ;
V_43 = F_92 ( V_10 , & V_161 . V_84 ) ;
if ( V_43 < 0 ) {
free ( * V_166 ) ;
* V_166 = NULL ;
return V_43 ;
}
return ( V_43 < 0 ) ? V_43 : V_161 . V_164 ;
}
static int F_104 ( T_4 * V_77 , void * V_107 )
{
struct V_169 * V_170 = V_107 ;
struct V_171 * V_172 ;
char V_64 [ V_173 ] ;
int V_78 , V_43 ;
V_172 = & V_170 -> V_174 [ V_170 -> V_175 - 1 ] ;
V_78 = F_39 ( V_77 ) ;
if ( V_78 == V_47 ||
V_78 == V_150 ) {
V_43 = F_35 ( V_77 , V_170 -> V_84 . V_24 ,
V_170 -> V_84 . V_33 , & V_170 -> V_84 . V_34 ,
NULL ) ;
if ( V_43 == 0 ) {
V_43 = F_105 ( V_77 , V_64 , V_173 ) ;
F_23 ( L_71 , V_64 ) ;
if ( V_43 > 0 )
F_106 ( V_172 -> V_176 , V_64 ) ;
}
}
if ( V_170 -> V_177 && F_98 ( V_77 , V_170 -> V_84 . V_24 ) )
return V_153 ;
else
return V_154 ;
}
static int F_107 ( T_4 * V_87 , struct V_83 * V_84 )
{
struct V_169 * V_170 =
F_102 ( V_84 , struct V_169 , V_84 ) ;
struct V_171 * V_172 ;
T_4 V_77 ;
int V_43 ;
if ( V_170 -> V_175 == V_170 -> V_178 ) {
F_43 ( L_69 , V_170 -> V_178 ) ;
return - V_61 ;
}
V_172 = & V_170 -> V_174 [ V_170 -> V_175 ++ ] ;
V_43 = F_62 ( & V_84 -> V_34 , V_170 -> V_16 , V_84 -> V_24 ,
V_84 -> V_114 -> V_115 . V_91 , & V_172 -> V_115 ) ;
if ( V_43 < 0 )
return V_43 ;
F_3 ( L_70 , V_172 -> V_115 . V_97 ,
V_172 -> V_115 . V_31 ) ;
V_172 -> V_176 = F_108 ( true , NULL ) ;
if ( V_172 -> V_176 == NULL )
return - V_8 ;
V_170 -> V_177 = true ;
F_100 ( V_87 , F_104 , ( void * ) V_170 , & V_77 ) ;
if ( ! V_170 -> V_179 )
goto V_180;
V_170 -> V_177 = false ;
F_100 ( & V_84 -> V_89 , F_104 , ( void * ) V_170 , & V_77 ) ;
V_180:
if ( F_109 ( V_172 -> V_176 ) ) {
F_110 ( V_172 -> V_176 ) ;
V_172 -> V_176 = NULL ;
}
return V_43 ;
}
int F_111 ( struct V_9 * V_10 ,
struct V_168 * V_114 ,
struct V_171 * * V_174 ,
int V_178 , bool V_179 )
{
struct V_169 V_170 = {
. V_84 = { . V_114 = V_114 , . V_105 = F_107 } ,
. V_16 = V_10 -> V_16 ,
. V_178 = V_178 , . V_179 = V_179 } ;
int V_43 ;
* V_174 = F_4 ( sizeof( struct V_171 ) * V_178 ) ;
if ( * V_174 == NULL )
return - V_8 ;
V_170 . V_174 = * V_174 ;
V_170 . V_175 = 0 ;
V_43 = F_92 ( V_10 , & V_170 . V_84 ) ;
if ( V_43 < 0 ) {
while ( V_170 . V_175 -- ) {
if ( V_170 . V_174 [ V_170 . V_175 ] . V_115 . V_97 )
free ( V_170 . V_174 [ V_170 . V_175 ] . V_115 . V_97 ) ;
if ( V_170 . V_174 [ V_170 . V_175 ] . V_176 )
F_110 ( V_170 . V_174 [ V_170 . V_175 ] . V_176 ) ;
}
free ( V_170 . V_174 ) ;
* V_174 = NULL ;
return V_43 ;
}
return ( V_43 < 0 ) ? V_43 : V_170 . V_175 ;
}
int F_112 ( struct V_9 * V_10 , unsigned long V_24 ,
struct V_129 * V_181 )
{
T_4 V_182 , V_183 , V_184 ;
T_2 V_185 = 0 , V_186 = 0 ;
const char * V_116 = NULL , * V_187 = NULL , * V_188 = NULL , * V_38 ;
int V_189 = 0 , V_118 = 0 , V_43 = 0 ;
V_24 += V_10 -> V_17 ;
if ( ! F_113 ( V_10 -> V_10 , ( T_2 ) V_24 - V_10 -> V_17 , & V_182 ) ) {
F_43 ( L_72 ,
V_24 ) ;
V_43 = - V_26 ;
goto V_167;
}
F_114 ( & V_182 , V_24 , & V_116 , & V_118 ) ;
if ( F_66 ( & V_182 , ( T_2 ) V_24 , & V_183 ) ) {
V_187 = V_188 = F_41 ( & V_183 ) ;
if ( ! V_187 ||
F_38 ( & V_183 , & V_186 ) != 0 ||
F_72 ( & V_183 , & V_189 ) != 0 ) {
V_118 = 0 ;
goto V_190;
}
V_116 = F_71 ( & V_183 ) ;
if ( V_24 == ( unsigned long ) V_186 ) {
V_118 = V_189 ;
goto V_190;
}
while ( F_115 ( & V_183 , ( T_2 ) V_24 ,
& V_184 ) ) {
if ( F_38 ( & V_184 , & V_185 ) == 0 &&
V_185 == V_24 ) {
V_118 = F_116 ( & V_184 ) ;
V_116 = F_117 ( & V_184 ) ;
break;
} else {
V_38 = F_41 ( & V_184 ) ;
if ( ! V_38 ||
F_72 ( & V_184 , & V_189 ) != 0 )
break;
V_187 = V_38 ;
V_183 = V_184 ;
}
}
V_38 = F_71 ( & V_183 ) ;
if ( ! V_38 || strcmp ( V_38 , V_116 ) != 0 )
V_118 = 0 ;
}
V_190:
if ( V_118 )
V_181 -> line = V_118 - V_189 ;
else if ( V_188 ) {
V_181 -> V_31 = V_24 - ( unsigned long ) V_186 ;
V_187 = V_188 ;
}
if ( V_187 ) {
V_181 -> V_112 = F_24 ( V_187 ) ;
if ( V_181 -> V_112 == NULL ) {
V_43 = - V_8 ;
goto V_167;
}
}
if ( V_116 ) {
V_181 -> V_110 = F_24 ( V_116 ) ;
if ( V_181 -> V_110 == NULL ) {
if ( V_181 -> V_112 ) {
free ( V_181 -> V_112 ) ;
V_181 -> V_112 = NULL ;
}
V_43 = - V_8 ;
goto V_167;
}
}
V_167:
if ( V_43 == 0 && ( V_116 || V_187 ) )
V_43 = 1 ;
return V_43 ;
}
static int F_118 ( const char * V_191 , unsigned int V_118 ,
struct V_192 * V_193 )
{
if ( ! V_193 -> V_11 ) {
V_193 -> V_11 = F_24 ( V_191 ) ;
if ( V_193 -> V_11 == NULL )
return - V_8 ;
}
return F_1 ( & V_193 -> V_194 , V_118 ) ;
}
static int F_119 ( const char * V_116 , int V_118 ,
T_2 V_24 V_27 ,
void * V_107 )
{
struct V_195 * V_196 = V_107 ;
if ( ( F_76 ( V_116 , V_196 -> V_116 ) != 0 ) ||
( V_196 -> V_197 > V_118 || V_196 -> V_198 < V_118 ) )
return 0 ;
if ( F_118 ( V_116 , V_118 , V_196 -> V_193 ) < 0 )
return - V_26 ;
return 0 ;
}
static int F_120 ( T_4 * V_34 , struct V_195 * V_196 )
{
int V_43 ;
V_43 = F_78 ( V_34 ? : & V_196 -> V_89 , F_119 , V_196 ) ;
if ( V_43 >= 0 )
if ( ! F_11 ( & V_196 -> V_193 -> V_194 ) )
V_43 = V_196 -> V_7 = 1 ;
else
V_43 = 0 ;
else {
free ( V_196 -> V_193 -> V_11 ) ;
V_196 -> V_193 -> V_11 = NULL ;
}
return V_43 ;
}
static int F_121 ( T_4 * V_128 , void * V_107 )
{
F_120 ( V_128 , V_107 ) ;
return 0 ;
}
static int F_122 ( T_4 * V_34 , void * V_107 )
{
struct V_131 * V_132 = V_107 ;
struct V_195 * V_196 = V_132 -> V_107 ;
struct V_192 * V_193 = V_196 -> V_193 ;
if ( V_193 -> V_110 && F_76 ( V_193 -> V_110 , F_71 ( V_34 ) ) )
return V_133 ;
if ( F_65 ( V_34 ) &&
F_50 ( V_34 , V_193 -> V_112 ) ) {
V_196 -> V_116 = F_71 ( V_34 ) ;
F_72 ( V_34 , & V_193 -> V_31 ) ;
F_3 ( L_73 , V_196 -> V_116 , V_193 -> V_31 ) ;
V_196 -> V_197 = V_193 -> V_31 + V_193 -> V_199 ;
if ( V_196 -> V_197 < 0 )
V_196 -> V_197 = V_117 ;
V_196 -> V_198 = V_193 -> V_31 + V_193 -> V_167 ;
if ( V_196 -> V_198 < 0 )
V_196 -> V_198 = V_117 ;
F_3 ( L_74 , V_196 -> V_197 , V_196 -> V_198 ) ;
V_193 -> V_199 = V_196 -> V_197 ;
V_193 -> V_167 = V_196 -> V_198 ;
if ( F_86 ( V_34 ) )
V_132 -> V_134 = F_87 ( V_34 ,
F_121 , V_196 ) ;
else
V_132 -> V_134 = F_120 ( V_34 , V_196 ) ;
return V_135 ;
}
return V_133 ;
}
static int F_123 ( struct V_195 * V_196 )
{
struct V_131 V_132 = { . V_107 = ( void * ) V_196 , . V_134 = 0 } ;
F_89 ( & V_196 -> V_89 , F_122 , & V_132 , 0 ) ;
return V_132 . V_134 ;
}
int F_124 ( struct V_9 * V_10 , struct V_192 * V_193 )
{
struct V_195 V_196 = { . V_193 = V_193 , . V_7 = 0 } ;
int V_43 = 0 ;
T_15 V_142 = 0 , V_143 ;
T_7 V_144 ;
T_4 * V_145 ;
const char * V_200 ;
if ( V_193 -> V_112 ) {
struct V_138 V_146 = {
. V_112 = V_193 -> V_112 , . V_110 = V_193 -> V_110 ,
. V_89 = & V_196 . V_89 , . V_34 = & V_196 . V_34 , . V_7 = 0 } ;
struct V_131 V_201 = {
. V_107 = ( void * ) & V_196 , . V_134 = 0 } ;
F_94 ( V_10 -> V_10 , F_90 ,
& V_146 , 0 ) ;
if ( V_146 . V_7 ) {
F_122 ( & V_196 . V_34 , & V_201 ) ;
if ( V_196 . V_7 )
goto V_7;
}
}
while ( ! V_196 . V_7 && V_43 >= 0 ) {
if ( F_95 ( V_10 -> V_10 , V_142 , & V_143 , & V_144 ,
NULL , NULL , NULL ) != 0 )
break;
V_145 = F_91 ( V_10 -> V_10 , V_142 + V_144 , & V_196 . V_89 ) ;
if ( ! V_145 )
continue;
if ( V_193 -> V_110 )
V_196 . V_116 = F_96 ( & V_196 . V_89 , V_193 -> V_110 ) ;
else
V_196 . V_116 = 0 ;
if ( ! V_193 -> V_110 || V_196 . V_116 ) {
if ( V_193 -> V_112 )
V_43 = F_123 ( & V_196 ) ;
else {
V_196 . V_197 = V_193 -> V_199 ;
V_196 . V_198 = V_193 -> V_167 ;
V_43 = F_120 ( NULL , & V_196 ) ;
}
}
V_142 = V_143 ;
}
V_7:
if ( V_196 . V_7 ) {
V_200 = F_125 ( & V_196 . V_89 ) ;
if ( V_200 ) {
V_193 -> V_200 = F_24 ( V_200 ) ;
if ( ! V_193 -> V_200 )
V_43 = - V_8 ;
}
}
F_3 ( L_75 , V_193 -> V_11 ) ;
return ( V_43 < 0 ) ? V_43 : V_196 . V_7 ;
}
