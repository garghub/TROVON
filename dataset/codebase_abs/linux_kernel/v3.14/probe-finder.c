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
if ( F_14 ( V_10 , V_11 ) < 0 )
F_32 ( & V_10 ) ;
return V_10 ;
}
struct V_9 * F_33 ( unsigned long V_24 )
{
struct V_9 * V_10 = F_4 ( sizeof( * V_10 ) ) ;
if ( ! V_10 )
return NULL ;
if ( F_26 ( V_10 , ( T_2 ) V_24 ) < 0 )
F_32 ( & V_10 ) ;
return V_10 ;
}
void F_34 ( struct V_9 * V_10 )
{
if ( V_10 ) {
if ( V_10 -> V_14 )
F_19 ( V_10 -> V_14 ) ;
free ( V_10 ) ;
}
}
static struct V_28 * F_35 ( long V_29 )
{
struct V_28 * V_30 ;
V_30 = F_4 ( sizeof( struct V_28 ) ) ;
if ( V_30 != NULL )
V_30 -> V_31 = V_29 ;
return V_30 ;
}
static int F_36 ( T_4 * V_32 , T_2 V_24 ,
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
if ( F_37 ( V_32 , V_44 , & V_37 ) != NULL )
goto V_45;
if ( F_37 ( V_32 , V_46 , & V_37 ) == NULL )
return - V_26 ;
if ( F_38 ( & V_37 , V_24 , & V_39 , & V_40 , 1 ) <= 0 ) {
V_43 = F_39 ( V_34 , & V_38 ) ;
if ( V_43 || V_24 != V_38 ||
F_40 ( V_32 ) != V_47 ||
F_41 ( V_34 , & V_38 ) )
return - V_18 ;
for ( V_24 += 1 ; V_24 <= V_38 ; V_24 ++ ) {
if ( F_38 ( & V_37 , V_24 , & V_39 ,
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
V_43 = strlen ( F_42 ( V_32 ) ) ;
V_36 -> V_50 = F_4 ( V_43 + 2 ) ;
if ( V_36 -> V_50 == NULL )
return - V_8 ;
snprintf ( V_36 -> V_50 , V_43 + 2 , L_8 , F_42 ( V_32 ) ) ;
V_36 -> V_30 = F_35 ( ( long ) V_29 ) ;
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
V_42 = F_43 ( V_41 ) ;
if ( ! V_42 ) {
F_44 ( L_10
L_11 , V_41 ) ;
return - V_61 ;
}
V_36 -> V_50 = F_24 ( V_42 ) ;
if ( V_36 -> V_50 == NULL )
return - V_8 ;
if ( V_30 ) {
V_36 -> V_30 = F_35 ( ( long ) V_29 ) ;
if ( V_36 -> V_30 == NULL )
return - V_8 ;
}
return 0 ;
}
static int F_45 ( T_4 * V_32 ,
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
V_65 = F_46 ( V_32 ) ;
if ( V_65 > 0 ) {
V_66 = F_47 ( V_32 ) ;
V_67 = F_48 ( V_32 ) ;
if ( V_66 < 0 || V_67 < 0 )
return - V_18 ;
V_43 = snprintf ( V_64 , 16 , L_13 , V_65 , V_66 ,
F_49 ( V_67 ) ) ;
goto V_68;
}
if ( F_50 ( V_32 , & type ) == NULL ) {
F_44 ( L_14 ,
F_42 ( V_32 ) ) ;
return - V_18 ;
}
F_3 ( L_15 ,
F_42 ( V_32 ) , F_42 ( & type ) ) ;
if ( V_62 && strcmp ( V_62 , L_12 ) == 0 ) {
V_43 = F_40 ( & type ) ;
if ( V_43 != V_69 &&
V_43 != V_70 ) {
F_44 ( L_16
L_17 ,
F_42 ( V_32 ) , F_42 ( & type ) ) ;
return - V_26 ;
}
if ( F_50 ( & type , & type ) == NULL ) {
F_44 ( L_18
L_19 ) ;
return - V_18 ;
}
if ( V_43 == V_69 ) {
while ( * V_63 )
V_63 = & ( * V_63 ) -> V_71 ;
* V_63 = F_4 ( sizeof( struct V_28 ) ) ;
if ( * V_63 == NULL ) {
F_44 ( L_20 ) ;
return - V_8 ;
}
}
if ( ! F_51 ( & type , L_21 ) &&
! F_51 ( & type , L_22 ) ) {
F_44 ( L_16
L_23 ,
F_42 ( V_32 ) ) ;
return - V_26 ;
}
V_36 -> type = F_24 ( V_62 ) ;
return ( V_36 -> type == NULL ) ? - V_8 : 0 ;
}
V_43 = F_48 ( & type ) ;
if ( V_43 <= 0 )
return 0 ;
V_43 = F_49 ( V_43 ) ;
if ( V_43 > V_72 ) {
F_52 ( L_24 ,
F_42 ( & type ) , V_72 ) ;
V_43 = V_72 ;
}
V_43 = snprintf ( V_64 , 16 , L_25 ,
F_53 ( & type ) ? 's' : 'u' , V_43 ) ;
V_68:
if ( V_43 < 0 || V_43 >= 16 ) {
if ( V_43 >= 16 )
V_43 = - V_73 ;
F_44 ( L_26 ,
strerror ( - V_43 ) ) ;
return V_43 ;
}
V_36 -> type = F_24 ( V_64 ) ;
if ( V_36 -> type == NULL )
return - V_8 ;
return 0 ;
}
static int F_54 ( T_4 * V_32 , const char * V_74 ,
struct V_75 * V_76 ,
struct V_28 * * V_63 ,
T_4 * V_77 )
{
struct V_28 * V_30 = * V_63 ;
T_4 type ;
T_8 V_29 ;
int V_43 , V_78 ;
F_3 ( L_27 , V_76 -> V_79 , V_74 ) ;
if ( F_50 ( V_32 , & type ) == NULL ) {
F_44 ( L_28 , V_74 ) ;
return - V_18 ;
}
F_23 ( L_29 , ( unsigned ) F_55 ( & type ) ) ;
V_78 = F_40 ( & type ) ;
if ( V_76 -> V_79 [ 0 ] == '[' &&
( V_78 == V_70 || V_78 == V_69 ) ) {
if ( V_76 -> V_71 )
memcpy ( V_77 , & type , sizeof( * V_77 ) ) ;
if ( F_50 ( & type , & type ) == NULL ) {
F_44 ( L_28 , V_74 ) ;
return - V_18 ;
}
F_23 ( L_30 ,
( unsigned ) F_55 ( & type ) ) ;
if ( V_78 == V_69 ) {
V_30 = F_4 ( sizeof( struct V_28 ) ) ;
if ( V_30 == NULL )
return - V_8 ;
if ( * V_63 )
( * V_63 ) -> V_71 = V_30 ;
else
* V_63 = V_30 ;
}
V_30 -> V_31 += F_48 ( & type ) * V_76 -> V_80 ;
if ( ! V_76 -> V_71 )
memcpy ( V_77 , V_32 , sizeof( * V_77 ) ) ;
goto V_71;
} else if ( V_78 == V_69 ) {
if ( ! V_76 -> V_30 ) {
F_30 ( L_31 ,
V_76 -> V_79 ) ;
return - V_26 ;
}
if ( F_50 ( & type , & type ) == NULL ) {
F_44 ( L_28 , V_74 ) ;
return - V_18 ;
}
V_78 = F_40 ( & type ) ;
if ( V_78 != V_81 && V_78 != V_82 ) {
F_44 ( L_32 ,
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
F_44 ( L_32 ,
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
F_44 ( L_36
L_37 ) ;
return - V_52 ;
}
}
if ( F_56 ( & type , V_76 -> V_79 , V_77 ) == NULL ) {
F_44 ( L_38 , V_74 ,
F_42 ( & type ) , V_76 -> V_79 ) ;
return - V_26 ;
}
if ( V_78 == V_82 ) {
V_29 = 0 ;
} else {
V_43 = F_57 ( V_77 , & V_29 ) ;
if ( V_43 < 0 ) {
F_44 ( L_39 ,
V_76 -> V_79 ) ;
return V_43 ;
}
}
V_30 -> V_31 += ( long ) V_29 ;
V_71:
if ( V_76 -> V_71 )
return F_54 ( V_77 , V_76 -> V_79 ,
V_76 -> V_71 , & V_30 , V_77 ) ;
else
return 0 ;
}
static int F_58 ( T_4 * V_32 , struct V_83 * V_84 )
{
T_4 V_77 ;
int V_43 ;
F_3 ( L_40 ,
F_42 ( V_32 ) ) ;
V_43 = F_36 ( V_32 , V_84 -> V_24 , V_84 -> V_33 ,
& V_84 -> V_34 , V_84 -> V_36 ) ;
if ( V_43 == - V_18 )
F_30 ( L_41
L_42 , V_84 -> V_85 -> V_86 ) ;
else if ( V_43 == - V_52 )
F_30 ( L_43 ) ;
else if ( V_84 -> V_85 -> V_76 ) {
V_43 = F_54 ( V_32 , V_84 -> V_85 -> V_86 ,
V_84 -> V_85 -> V_76 , & V_84 -> V_36 -> V_30 ,
& V_77 ) ;
V_32 = & V_77 ;
}
if ( V_43 == 0 )
V_43 = F_45 ( V_32 , V_84 -> V_36 , V_84 -> V_85 -> type ) ;
return V_43 ;
}
static int F_59 ( T_4 * V_87 , struct V_83 * V_84 )
{
T_4 V_32 ;
char V_64 [ 32 ] , * V_88 ;
int V_43 = 0 ;
if ( ! F_60 ( V_84 -> V_85 -> V_86 ) ) {
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
V_43 = F_61 ( V_84 -> V_85 , V_64 , 32 ) ;
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
if ( ! F_62 ( V_87 , V_84 -> V_85 -> V_86 , V_84 -> V_24 , & V_32 ) ) {
if ( ! F_62 ( & V_84 -> V_89 , V_84 -> V_85 -> V_86 , 0 , & V_32 ) )
V_43 = - V_18 ;
}
if ( V_43 >= 0 )
V_43 = F_58 ( & V_32 , V_84 ) ;
if ( V_43 < 0 )
F_44 ( L_45 ,
V_84 -> V_85 -> V_86 ) ;
return V_43 ;
}
static int F_63 ( T_4 * V_34 , T_1 * V_16 ,
T_2 V_90 , bool V_91 ,
struct V_92 * V_93 )
{
T_2 V_94 , V_95 ;
T_9 V_96 ;
const char * V_97 ;
if ( F_39 ( V_34 , & V_94 ) != 0 ) {
F_44 ( L_46 ,
F_42 ( V_34 ) ) ;
return - V_18 ;
}
if ( F_41 ( V_34 , & V_95 ) != 0 ) {
F_44 ( L_47 ,
F_42 ( V_34 ) ) ;
return - V_18 ;
}
if ( V_90 > V_95 ) {
F_44 ( L_48 ,
F_42 ( V_34 ) ) ;
return - V_26 ;
}
V_97 = F_64 ( V_16 , V_90 , & V_96 , NULL ) ;
if ( ! V_97 ) {
F_44 ( L_49 ,
( unsigned long ) V_90 ) ;
return - V_18 ;
}
V_93 -> V_31 = ( unsigned long ) ( V_90 - V_96 . V_98 ) ;
V_93 -> V_99 = ( unsigned long ) V_90 ;
V_93 -> V_97 = F_24 ( V_97 ) ;
if ( ! V_93 -> V_97 )
return - V_8 ;
if ( V_91 ) {
if ( V_94 != V_90 ) {
F_44 ( L_50
L_51 ) ;
return - V_26 ;
}
V_93 -> V_91 = true ;
}
return 0 ;
}
static int F_65 ( T_4 * V_87 , struct V_83 * V_84 )
{
T_6 V_100 ;
T_7 V_40 ;
int V_43 ;
if ( ! V_87 ) {
F_30 ( L_52 ) ;
return - V_26 ;
}
if ( ! F_66 ( V_87 ) ) {
if ( ! F_67 ( & V_84 -> V_89 , V_84 -> V_24 , & V_84 -> V_34 ) ) {
F_44 ( L_53
L_54 ) ;
return - V_18 ;
}
} else
memcpy ( & V_84 -> V_34 , V_87 , sizeof( T_4 ) ) ;
F_37 ( & V_84 -> V_34 , V_101 , & V_100 ) ;
V_43 = F_38 ( & V_100 , V_84 -> V_24 , & V_84 -> V_33 , & V_40 , 1 ) ;
if ( V_43 <= 0 || V_40 == 0 ) {
V_84 -> V_33 = NULL ;
#if F_68 ( 0 , 142 )
} else if ( V_40 == 1 && V_84 -> V_33 [ 0 ] . V_48 == V_102 &&
V_84 -> V_103 != NULL ) {
T_10 * V_104 ;
if ( F_69 ( V_84 -> V_103 , V_84 -> V_24 , & V_104 ) != 0 ||
F_70 ( V_104 , & V_84 -> V_33 , & V_40 ) != 0 ) {
F_44 ( L_55 ,
( V_105 ) V_84 -> V_24 ) ;
return - V_18 ;
}
#endif
}
V_43 = V_84 -> V_106 ( V_87 , V_84 ) ;
V_84 -> V_33 = NULL ;
return V_43 ;
}
static int F_71 ( T_4 * V_107 , void * V_108 )
{
struct V_109 * V_110 = V_108 ;
const char * V_111 ;
int V_112 ;
if ( V_110 -> V_111 ) {
V_111 = F_72 ( V_107 ) ;
if ( ! V_111 || strcmp ( V_110 -> V_111 , V_111 ) != 0 )
return 0 ;
}
if ( V_110 -> V_113 ) {
if ( F_51 ( V_107 , V_110 -> V_113 ) ) {
memcpy ( V_110 -> V_77 , V_107 , sizeof( T_4 ) ) ;
V_110 -> V_7 = true ;
return 1 ;
}
} else {
F_73 ( V_107 , & V_112 ) ;
if ( V_112 < V_110 -> line && V_110 -> V_114 > V_110 -> line - V_112 ) {
V_110 -> V_114 = V_110 -> line - V_112 ;
memcpy ( V_110 -> V_77 , V_107 , sizeof( T_4 ) ) ;
V_110 -> V_7 = true ;
}
}
return 0 ;
}
static T_4 * F_74 ( struct V_83 * V_84 , T_4 * V_77 )
{
struct V_109 V_110 = {
. V_113 = V_84 -> V_115 -> V_116 . V_113 ,
. V_111 = V_84 -> V_117 ,
. line = V_84 -> V_112 ,
. V_114 = V_118 ,
. V_77 = V_77 ,
. V_7 = false ,
} ;
F_75 ( & V_84 -> V_89 , V_84 -> V_24 , F_71 , & V_110 ) ;
return V_110 . V_7 ? V_77 : NULL ;
}
static int F_76 ( const char * V_117 , int V_119 ,
T_2 V_24 , void * V_108 )
{
struct V_83 * V_84 = V_108 ;
T_4 * V_87 , V_77 ;
int V_43 ;
if ( V_119 != V_84 -> V_112 || F_77 ( V_117 , V_84 -> V_117 ) != 0 )
return 0 ;
V_84 -> V_24 = V_24 ;
V_87 = F_74 ( V_84 , & V_77 ) ;
if ( ! V_87 ) {
F_44 ( L_56 ) ;
return - V_18 ;
}
V_43 = F_65 ( V_87 , V_84 ) ;
return V_43 < 0 ? V_43 : 0 ;
}
static int F_78 ( struct V_83 * V_84 )
{
return F_79 ( & V_84 -> V_89 , F_76 , V_84 ) ;
}
static int F_80 ( struct V_1 * V_2 ,
const char * V_117 , const char * V_120 )
{
T_11 * V_121 ;
char * line = NULL ;
T_7 V_122 ;
T_12 V_123 ;
int V_124 = 0 , V_125 = 1 ;
V_121 = fopen ( V_117 , L_57 ) ;
if ( ! V_121 ) {
F_44 ( L_58 , V_117 , strerror ( V_126 ) ) ;
return - V_126 ;
}
while ( ( V_123 = F_81 ( & line , & V_122 , V_121 ) ) > 0 ) {
if ( line [ V_123 - 1 ] == '\n' )
line [ V_123 - 1 ] = '\0' ;
if ( F_82 ( line , V_120 ) ) {
F_1 ( V_2 , V_125 ) ;
V_124 ++ ;
}
V_125 ++ ;
}
if ( ferror ( V_121 ) )
V_124 = - V_126 ;
free ( line ) ;
fclose ( V_121 ) ;
if ( V_124 == 0 )
F_3 ( L_59 , V_117 ) ;
return V_124 ;
}
static int F_83 ( const char * V_117 , int V_119 ,
T_2 V_24 , void * V_108 )
{
struct V_83 * V_84 = V_108 ;
T_4 * V_87 , V_77 ;
int V_43 ;
if ( ! F_7 ( & V_84 -> V_127 , V_119 ) ||
F_77 ( V_117 , V_84 -> V_117 ) != 0 )
return 0 ;
F_3 ( L_60 ,
V_119 , ( unsigned long long ) V_24 ) ;
V_84 -> V_24 = V_24 ;
V_84 -> V_112 = V_119 ;
V_87 = F_74 ( V_84 , & V_77 ) ;
if ( ! V_87 ) {
F_44 ( L_56 ) ;
return - V_18 ;
}
V_43 = F_65 ( V_87 , V_84 ) ;
return V_43 < 0 ? V_43 : 0 ;
}
static int F_84 ( T_4 * V_34 , struct V_83 * V_84 )
{
int V_43 = 0 ;
if ( F_11 ( & V_84 -> V_127 ) ) {
V_43 = F_80 ( & V_84 -> V_127 , V_84 -> V_117 ,
V_84 -> V_115 -> V_116 . V_128 ) ;
if ( V_43 <= 0 )
return V_43 ;
}
return F_79 ( V_34 , F_83 , V_84 ) ;
}
static int F_85 ( T_4 * V_129 , void * V_108 )
{
struct V_83 * V_84 = V_108 ;
struct V_130 * V_131 = & V_84 -> V_115 -> V_116 ;
T_2 V_24 ;
int V_43 ;
if ( V_131 -> V_128 )
V_43 = F_84 ( V_129 , V_84 ) ;
else {
if ( F_39 ( V_129 , & V_24 ) != 0 ) {
F_44 ( L_61 ,
F_42 ( V_129 ) ) ;
return - V_18 ;
}
V_84 -> V_24 = V_24 ;
V_84 -> V_24 += V_131 -> V_31 ;
F_3 ( L_62 ,
( V_105 ) V_84 -> V_24 ) ;
V_43 = F_65 ( V_129 , V_84 ) ;
}
return V_43 ;
}
static int F_86 ( T_4 * V_34 , void * V_108 )
{
struct V_132 * V_133 = V_108 ;
struct V_83 * V_84 = V_133 -> V_108 ;
struct V_130 * V_131 = & V_84 -> V_115 -> V_116 ;
if ( ! F_66 ( V_34 ) ||
! F_51 ( V_34 , V_131 -> V_113 ) )
return V_134 ;
if ( V_131 -> V_111 && F_77 ( V_131 -> V_111 , F_72 ( V_34 ) ) )
return V_134 ;
V_84 -> V_117 = F_72 ( V_34 ) ;
if ( V_131 -> line ) {
F_73 ( V_34 , & V_84 -> V_112 ) ;
V_84 -> V_112 += V_131 -> line ;
V_133 -> V_135 = F_78 ( V_84 ) ;
} else if ( ! F_87 ( V_34 ) ) {
if ( V_131 -> V_128 )
V_133 -> V_135 = F_84 ( V_34 , V_84 ) ;
else {
if ( F_39 ( V_34 , & V_84 -> V_24 ) != 0 ) {
F_44 ( L_63
L_64 , F_42 ( V_34 ) ) ;
V_133 -> V_135 = - V_18 ;
return V_136 ;
}
V_84 -> V_24 += V_131 -> V_31 ;
V_133 -> V_135 = F_65 ( V_34 , V_84 ) ;
}
} else
V_133 -> V_135 = F_88 ( V_34 ,
F_85 , ( void * ) V_84 ) ;
return V_136 ;
}
static int F_89 ( struct V_83 * V_84 )
{
struct V_132 V_137 = { . V_108 = ( void * ) V_84 ,
. V_135 = 0 } ;
F_90 ( & V_84 -> V_89 , F_86 , & V_137 , 0 ) ;
return V_137 . V_135 ;
}
static int F_91 ( T_13 * V_10 , T_14 * V_138 , void * V_108 )
{
struct V_139 * V_133 = V_108 ;
if ( F_92 ( V_10 , V_138 -> V_140 , V_133 -> V_34 ) ) {
if ( F_40 ( V_133 -> V_34 ) != V_141 )
return V_134 ;
if ( F_51 ( V_133 -> V_34 , V_133 -> V_113 ) ) {
if ( ! F_92 ( V_10 , V_138 -> V_142 , V_133 -> V_89 ) )
return V_134 ;
if ( V_133 -> V_111 &&
F_77 ( V_133 -> V_111 , F_72 ( V_133 -> V_34 ) ) )
return V_134 ;
V_133 -> V_7 = 1 ;
return V_136 ;
}
}
return V_134 ;
}
static int F_93 ( struct V_9 * V_10 ,
struct V_83 * V_84 )
{
struct V_130 * V_131 = & V_84 -> V_115 -> V_116 ;
T_15 V_143 , V_144 ;
T_7 V_145 ;
T_4 * V_146 ;
int V_43 = 0 ;
#if F_68 ( 0 , 142 )
V_84 -> V_103 = F_94 ( V_10 -> V_10 ) ;
#endif
V_143 = 0 ;
F_9 ( & V_84 -> V_127 ) ;
if ( V_131 -> V_113 ) {
struct V_139 V_147 = {
. V_113 = V_131 -> V_113 ,
. V_111 = V_131 -> V_111 ,
. V_89 = & V_84 -> V_89 ,
. V_34 = & V_84 -> V_34 ,
. V_7 = 0 ,
} ;
struct V_132 V_148 = {
. V_108 = V_84 ,
} ;
F_95 ( V_10 -> V_10 , F_91 ,
& V_147 , 0 ) ;
if ( V_147 . V_7 ) {
V_43 = F_86 ( & V_84 -> V_34 , & V_148 ) ;
if ( V_43 )
goto V_7;
}
}
while ( ! F_96 ( V_10 -> V_10 , V_143 , & V_144 , & V_145 , NULL , NULL , NULL ) ) {
V_146 = F_92 ( V_10 -> V_10 , V_143 + V_145 , & V_84 -> V_89 ) ;
if ( ! V_146 )
continue;
if ( V_131 -> V_111 )
V_84 -> V_117 = F_97 ( & V_84 -> V_89 , V_131 -> V_111 ) ;
else
V_84 -> V_117 = NULL ;
if ( ! V_131 -> V_111 || V_84 -> V_117 ) {
if ( V_131 -> V_113 )
V_43 = F_89 ( V_84 ) ;
else if ( V_131 -> V_128 )
V_43 = F_84 ( NULL , V_84 ) ;
else {
V_84 -> V_112 = V_131 -> line ;
V_43 = F_78 ( V_84 ) ;
}
if ( V_43 < 0 )
break;
}
V_143 = V_144 ;
}
V_7:
F_10 ( & V_84 -> V_127 ) ;
return V_43 ;
}
static int F_98 ( T_4 * V_77 , void * V_108 )
{
struct V_149 * V_150 = V_108 ;
struct V_83 * V_84 = V_150 -> V_84 ;
int V_78 ;
V_78 = F_40 ( V_77 ) ;
if ( V_78 == V_47 ||
V_78 == V_151 ) {
if ( F_36 ( V_77 , V_150 -> V_84 -> V_24 ,
V_150 -> V_84 -> V_33 , & V_84 -> V_34 ,
NULL ) == 0 ) {
V_150 -> args [ V_150 -> V_152 ] . V_86 = ( char * ) F_42 ( V_77 ) ;
if ( V_150 -> args [ V_150 -> V_152 ] . V_86 == NULL ) {
V_150 -> V_43 = - V_8 ;
return V_153 ;
}
F_3 ( L_65 , V_150 -> args [ V_150 -> V_152 ] . V_86 ) ;
V_150 -> V_152 ++ ;
}
}
if ( F_99 ( V_77 , V_150 -> V_84 -> V_24 ) )
return V_154 ;
else
return V_155 ;
}
static int F_100 ( T_4 * V_87 , struct V_83 * V_84 ,
struct V_156 * args )
{
T_4 V_77 ;
int V_157 ;
int V_158 = 0 ;
struct V_149 V_150 = { . V_84 = V_84 , . args = args ,
. V_159 = V_160 , . V_43 = 0 } ;
for ( V_157 = 0 ; V_157 < V_84 -> V_115 -> V_152 ; V_157 ++ ) {
if ( strcmp ( V_84 -> V_115 -> args [ V_157 ] . V_86 , L_66 ) == 0 ) {
F_3 ( L_67 ) ;
V_150 . V_152 = V_158 ;
F_101 ( V_87 , F_98 , ( void * ) & V_150 ,
& V_77 ) ;
F_3 ( L_68 , V_150 . V_152 - V_158 ) ;
if ( V_150 . V_43 < 0 )
return V_150 . V_43 ;
V_158 = V_150 . V_152 ;
} else {
args [ V_158 ] = V_84 -> V_115 -> args [ V_157 ] ;
V_158 ++ ;
}
}
return V_158 ;
}
static int F_102 ( T_4 * V_87 , struct V_83 * V_84 )
{
struct V_161 * V_162 =
F_103 ( V_84 , struct V_161 , V_84 ) ;
struct V_163 * V_164 ;
struct V_156 * args ;
int V_43 , V_157 ;
if ( V_162 -> V_165 == V_162 -> V_166 ) {
F_44 ( L_69 ,
V_162 -> V_166 ) ;
return - V_61 ;
}
V_164 = & V_162 -> V_167 [ V_162 -> V_165 ++ ] ;
V_43 = F_63 ( & V_84 -> V_34 , V_162 -> V_16 , V_84 -> V_24 ,
V_84 -> V_115 -> V_116 . V_91 , & V_164 -> V_116 ) ;
if ( V_43 < 0 )
return V_43 ;
F_3 ( L_70 , V_164 -> V_116 . V_97 ,
V_164 -> V_116 . V_31 ) ;
args = F_4 ( sizeof( struct V_156 ) * V_160 ) ;
if ( args == NULL )
return - V_8 ;
V_43 = F_100 ( V_87 , V_84 , args ) ;
if ( V_43 < 0 )
goto V_168;
V_164 -> V_152 = V_43 ;
V_164 -> args = F_4 ( sizeof( struct V_35 ) * V_164 -> V_152 ) ;
if ( V_164 -> args == NULL ) {
V_43 = - V_8 ;
goto V_168;
}
for ( V_157 = 0 ; V_157 < V_164 -> V_152 ; V_157 ++ ) {
V_84 -> V_85 = & args [ V_157 ] ;
V_84 -> V_36 = & V_164 -> args [ V_157 ] ;
V_43 = F_59 ( V_87 , V_84 ) ;
if ( V_43 != 0 )
break;
}
V_168:
free ( args ) ;
return V_43 ;
}
int F_104 ( struct V_9 * V_10 ,
struct V_169 * V_115 ,
struct V_163 * * V_167 , int V_166 )
{
struct V_161 V_162 = {
. V_84 = { . V_115 = V_115 , . V_106 = F_102 } ,
. V_16 = V_10 -> V_16 , . V_166 = V_166 } ;
int V_43 ;
* V_167 = F_4 ( sizeof( struct V_163 ) * V_166 ) ;
if ( * V_167 == NULL )
return - V_8 ;
V_162 . V_167 = * V_167 ;
V_162 . V_165 = 0 ;
V_43 = F_93 ( V_10 , & V_162 . V_84 ) ;
if ( V_43 < 0 ) {
F_32 ( V_167 ) ;
return V_43 ;
}
return ( V_43 < 0 ) ? V_43 : V_162 . V_165 ;
}
static int F_105 ( T_4 * V_77 , void * V_108 )
{
struct V_170 * V_171 = V_108 ;
struct V_172 * V_173 ;
char V_64 [ V_174 ] ;
int V_78 , V_43 ;
V_173 = & V_171 -> V_175 [ V_171 -> V_176 - 1 ] ;
V_78 = F_40 ( V_77 ) ;
if ( V_78 == V_47 ||
V_78 == V_151 ) {
V_43 = F_36 ( V_77 , V_171 -> V_84 . V_24 ,
V_171 -> V_84 . V_33 , & V_171 -> V_84 . V_34 ,
NULL ) ;
if ( V_43 == 0 ) {
V_43 = F_106 ( V_77 , V_64 , V_174 ) ;
F_23 ( L_71 , V_64 ) ;
if ( V_43 > 0 )
F_107 ( V_173 -> V_177 , V_64 ) ;
}
}
if ( V_171 -> V_178 && F_99 ( V_77 , V_171 -> V_84 . V_24 ) )
return V_154 ;
else
return V_155 ;
}
static int F_108 ( T_4 * V_87 , struct V_83 * V_84 )
{
struct V_170 * V_171 =
F_103 ( V_84 , struct V_170 , V_84 ) ;
struct V_172 * V_173 ;
T_4 V_77 ;
int V_43 ;
if ( V_171 -> V_176 == V_171 -> V_179 ) {
F_44 ( L_69 , V_171 -> V_179 ) ;
return - V_61 ;
}
V_173 = & V_171 -> V_175 [ V_171 -> V_176 ++ ] ;
V_43 = F_63 ( & V_84 -> V_34 , V_171 -> V_16 , V_84 -> V_24 ,
V_84 -> V_115 -> V_116 . V_91 , & V_173 -> V_116 ) ;
if ( V_43 < 0 )
return V_43 ;
F_3 ( L_70 , V_173 -> V_116 . V_97 ,
V_173 -> V_116 . V_31 ) ;
V_173 -> V_177 = F_109 ( true , NULL ) ;
if ( V_173 -> V_177 == NULL )
return - V_8 ;
V_171 -> V_178 = true ;
F_101 ( V_87 , F_105 , ( void * ) V_171 , & V_77 ) ;
if ( ! V_171 -> V_180 )
goto V_181;
V_171 -> V_178 = false ;
F_101 ( & V_84 -> V_89 , F_105 , ( void * ) V_171 , & V_77 ) ;
V_181:
if ( F_110 ( V_173 -> V_177 ) ) {
F_111 ( V_173 -> V_177 ) ;
V_173 -> V_177 = NULL ;
}
return V_43 ;
}
int F_112 ( struct V_9 * V_10 ,
struct V_169 * V_115 ,
struct V_172 * * V_175 ,
int V_179 , bool V_180 )
{
struct V_170 V_171 = {
. V_84 = { . V_115 = V_115 , . V_106 = F_108 } ,
. V_16 = V_10 -> V_16 ,
. V_179 = V_179 , . V_180 = V_180 } ;
int V_43 ;
* V_175 = F_4 ( sizeof( struct V_172 ) * V_179 ) ;
if ( * V_175 == NULL )
return - V_8 ;
V_171 . V_175 = * V_175 ;
V_171 . V_176 = 0 ;
V_43 = F_93 ( V_10 , & V_171 . V_84 ) ;
if ( V_43 < 0 ) {
while ( V_171 . V_176 -- ) {
F_32 ( & V_171 . V_175 [ V_171 . V_176 ] . V_116 . V_97 ) ;
F_111 ( V_171 . V_175 [ V_171 . V_176 ] . V_177 ) ;
}
F_32 ( V_175 ) ;
return V_43 ;
}
return ( V_43 < 0 ) ? V_43 : V_171 . V_176 ;
}
int F_113 ( struct V_9 * V_10 , unsigned long V_24 ,
struct V_130 * V_182 )
{
T_4 V_183 , V_184 , V_185 ;
T_2 V_186 = 0 , V_187 = 0 ;
const char * V_117 = NULL , * V_188 = NULL , * V_189 = NULL , * V_38 ;
int V_190 = 0 , V_119 = 0 , V_43 = 0 ;
V_24 += V_10 -> V_17 ;
if ( ! F_114 ( V_10 -> V_10 , ( T_2 ) V_24 - V_10 -> V_17 , & V_183 ) ) {
F_44 ( L_72 ,
V_24 ) ;
V_43 = - V_26 ;
goto V_168;
}
F_115 ( & V_183 , V_24 , & V_117 , & V_119 ) ;
if ( F_67 ( & V_183 , ( T_2 ) V_24 , & V_184 ) ) {
V_188 = V_189 = F_42 ( & V_184 ) ;
if ( ! V_188 ||
F_39 ( & V_184 , & V_187 ) != 0 ||
F_73 ( & V_184 , & V_190 ) != 0 ) {
V_119 = 0 ;
goto V_191;
}
V_117 = F_72 ( & V_184 ) ;
if ( V_24 == ( unsigned long ) V_187 ) {
V_119 = V_190 ;
goto V_191;
}
while ( F_116 ( & V_184 , ( T_2 ) V_24 ,
& V_185 ) ) {
if ( F_39 ( & V_185 , & V_186 ) == 0 &&
V_186 == V_24 ) {
V_119 = F_117 ( & V_185 ) ;
V_117 = F_118 ( & V_185 ) ;
break;
} else {
V_38 = F_42 ( & V_185 ) ;
if ( ! V_38 ||
F_73 ( & V_185 , & V_190 ) != 0 )
break;
V_188 = V_38 ;
V_184 = V_185 ;
}
}
V_38 = F_72 ( & V_184 ) ;
if ( ! V_38 || strcmp ( V_38 , V_117 ) != 0 )
V_119 = 0 ;
}
V_191:
if ( V_119 )
V_182 -> line = V_119 - V_190 ;
else if ( V_189 ) {
V_182 -> V_31 = V_24 - ( unsigned long ) V_187 ;
V_188 = V_189 ;
}
if ( V_188 ) {
V_182 -> V_113 = F_24 ( V_188 ) ;
if ( V_182 -> V_113 == NULL ) {
V_43 = - V_8 ;
goto V_168;
}
}
if ( V_117 ) {
V_182 -> V_111 = F_24 ( V_117 ) ;
if ( V_182 -> V_111 == NULL ) {
F_32 ( & V_182 -> V_113 ) ;
V_43 = - V_8 ;
goto V_168;
}
}
V_168:
if ( V_43 == 0 && ( V_117 || V_188 ) )
V_43 = 1 ;
return V_43 ;
}
static int F_119 ( const char * V_192 , unsigned int V_119 ,
struct V_193 * V_194 )
{
if ( ! V_194 -> V_11 ) {
V_194 -> V_11 = F_24 ( V_192 ) ;
if ( V_194 -> V_11 == NULL )
return - V_8 ;
}
return F_1 ( & V_194 -> V_195 , V_119 ) ;
}
static int F_120 ( const char * V_117 , int V_119 ,
T_2 V_24 V_27 ,
void * V_108 )
{
struct V_196 * V_197 = V_108 ;
if ( ( F_77 ( V_117 , V_197 -> V_117 ) != 0 ) ||
( V_197 -> V_198 > V_119 || V_197 -> V_199 < V_119 ) )
return 0 ;
if ( F_119 ( V_117 , V_119 , V_197 -> V_194 ) < 0 )
return - V_26 ;
return 0 ;
}
static int F_121 ( T_4 * V_34 , struct V_196 * V_197 )
{
int V_43 ;
V_43 = F_79 ( V_34 ? : & V_197 -> V_89 , F_120 , V_197 ) ;
if ( V_43 >= 0 )
if ( ! F_11 ( & V_197 -> V_194 -> V_195 ) )
V_43 = V_197 -> V_7 = 1 ;
else
V_43 = 0 ;
else {
F_32 ( & V_197 -> V_194 -> V_11 ) ;
}
return V_43 ;
}
static int F_122 ( T_4 * V_129 , void * V_108 )
{
F_121 ( V_129 , V_108 ) ;
return 0 ;
}
static int F_123 ( T_4 * V_34 , void * V_108 )
{
struct V_132 * V_133 = V_108 ;
struct V_196 * V_197 = V_133 -> V_108 ;
struct V_193 * V_194 = V_197 -> V_194 ;
if ( V_194 -> V_111 && F_77 ( V_194 -> V_111 , F_72 ( V_34 ) ) )
return V_134 ;
if ( F_66 ( V_34 ) &&
F_51 ( V_34 , V_194 -> V_113 ) ) {
V_197 -> V_117 = F_72 ( V_34 ) ;
F_73 ( V_34 , & V_194 -> V_31 ) ;
F_3 ( L_73 , V_197 -> V_117 , V_194 -> V_31 ) ;
V_197 -> V_198 = V_194 -> V_31 + V_194 -> V_200 ;
if ( V_197 -> V_198 < 0 )
V_197 -> V_198 = V_118 ;
V_197 -> V_199 = V_194 -> V_31 + V_194 -> V_168 ;
if ( V_197 -> V_199 < 0 )
V_197 -> V_199 = V_118 ;
F_3 ( L_74 , V_197 -> V_198 , V_197 -> V_199 ) ;
V_194 -> V_200 = V_197 -> V_198 ;
V_194 -> V_168 = V_197 -> V_199 ;
if ( F_87 ( V_34 ) )
V_133 -> V_135 = F_88 ( V_34 ,
F_122 , V_197 ) ;
else
V_133 -> V_135 = F_121 ( V_34 , V_197 ) ;
return V_136 ;
}
return V_134 ;
}
static int F_124 ( struct V_196 * V_197 )
{
struct V_132 V_133 = { . V_108 = ( void * ) V_197 , . V_135 = 0 } ;
F_90 ( & V_197 -> V_89 , F_123 , & V_133 , 0 ) ;
return V_133 . V_135 ;
}
int F_125 ( struct V_9 * V_10 , struct V_193 * V_194 )
{
struct V_196 V_197 = { . V_194 = V_194 , . V_7 = 0 } ;
int V_43 = 0 ;
T_15 V_143 = 0 , V_144 ;
T_7 V_145 ;
T_4 * V_146 ;
const char * V_201 ;
if ( V_194 -> V_113 ) {
struct V_139 V_147 = {
. V_113 = V_194 -> V_113 , . V_111 = V_194 -> V_111 ,
. V_89 = & V_197 . V_89 , . V_34 = & V_197 . V_34 , . V_7 = 0 } ;
struct V_132 V_202 = {
. V_108 = ( void * ) & V_197 , . V_135 = 0 } ;
F_95 ( V_10 -> V_10 , F_91 ,
& V_147 , 0 ) ;
if ( V_147 . V_7 ) {
F_123 ( & V_197 . V_34 , & V_202 ) ;
if ( V_197 . V_7 )
goto V_7;
}
}
while ( ! V_197 . V_7 && V_43 >= 0 ) {
if ( F_96 ( V_10 -> V_10 , V_143 , & V_144 , & V_145 ,
NULL , NULL , NULL ) != 0 )
break;
V_146 = F_92 ( V_10 -> V_10 , V_143 + V_145 , & V_197 . V_89 ) ;
if ( ! V_146 )
continue;
if ( V_194 -> V_111 )
V_197 . V_117 = F_97 ( & V_197 . V_89 , V_194 -> V_111 ) ;
else
V_197 . V_117 = 0 ;
if ( ! V_194 -> V_111 || V_197 . V_117 ) {
if ( V_194 -> V_113 )
V_43 = F_124 ( & V_197 ) ;
else {
V_197 . V_198 = V_194 -> V_200 ;
V_197 . V_199 = V_194 -> V_168 ;
V_43 = F_121 ( NULL , & V_197 ) ;
}
}
V_143 = V_144 ;
}
V_7:
if ( V_197 . V_7 ) {
V_201 = F_126 ( & V_197 . V_89 ) ;
if ( V_201 ) {
V_194 -> V_201 = F_24 ( V_201 ) ;
if ( ! V_194 -> V_201 )
V_43 = - V_8 ;
}
}
F_3 ( L_75 , V_194 -> V_11 ) ;
return ( V_43 < 0 ) ? V_43 : V_197 . V_7 ;
}
