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
T_1 * V_12 ;
int V_13 ;
V_13 = F_15 ( V_11 , V_14 ) ;
if ( V_13 < 0 )
return V_13 ;
V_10 -> V_15 = F_16 ( & V_16 ) ;
if ( ! V_10 -> V_15 )
goto error;
V_12 = F_17 ( V_10 -> V_15 , L_2 , L_2 , V_13 ) ;
if ( ! V_12 )
goto error;
V_10 -> V_17 = F_18 ( V_12 , & V_10 -> V_18 ) ;
if ( ! V_10 -> V_17 )
goto error;
return 0 ;
error:
if ( V_10 -> V_15 )
F_19 ( V_10 -> V_15 ) ;
else
F_20 ( V_13 ) ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
return - V_19 ;
}
static int F_21 ( T_1 * V_12 ,
void * * V_20 ,
const char * V_21 ,
T_2 V_22 ,
char * * V_23 , T_3 * * V_24 )
{
int V_13 ;
const char * V_11 = F_22 ( V_21 ) ;
F_23 ( L_3 , V_11 , V_21 ) ;
if ( V_11 ) {
V_13 = F_15 ( V_11 , V_14 ) ;
if ( V_13 >= 0 ) {
* V_23 = F_24 ( V_11 ) ;
return V_13 ;
}
}
return F_25 ( V_12 , V_20 , V_21 , V_22 ,
V_23 , V_24 ) ;
}
static int F_26 ( struct V_9 * V_10 ,
T_2 V_25 )
{
V_10 -> V_15 = F_16 ( & V_26 ) ;
if ( ! V_10 -> V_15 )
return - V_27 ;
F_27 ( V_10 -> V_15 ) ;
F_28 ( V_10 -> V_15 ) ;
V_10 -> V_17 = F_29 ( V_10 -> V_15 , V_25 , & V_10 -> V_18 ) ;
if ( ! V_10 -> V_17 ) {
F_3 ( L_4 ,
( unsigned long ) V_25 ) ;
F_19 ( V_10 -> V_15 ) ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
return - V_19 ;
}
return 0 ;
}
static int F_26 ( struct V_9 * V_10 ,
T_2 V_25 V_28 )
{
const char * V_11 = F_22 ( L_5 ) ;
if ( ! V_11 ) {
F_30 ( L_6 ) ;
return - V_19 ;
}
F_23 ( L_7 , V_11 ) ;
return F_14 ( V_10 , V_11 ) ;
}
struct V_9 * F_31 ( const char * V_11 )
{
struct V_9 * V_10 = F_4 ( sizeof( struct V_9 ) ) ;
if ( ! V_10 )
return NULL ;
if ( F_14 ( V_10 , V_11 ) < 0 ) {
free ( V_10 ) ;
V_10 = NULL ;
}
return V_10 ;
}
struct V_9 * F_32 ( unsigned long V_25 )
{
struct V_9 * V_10 = F_4 ( sizeof( struct V_9 ) ) ;
if ( ! V_10 )
return NULL ;
if ( F_26 ( V_10 , ( T_2 ) V_25 ) < 0 ) {
free ( V_10 ) ;
V_10 = NULL ;
}
return V_10 ;
}
void F_33 ( struct V_9 * V_10 )
{
if ( V_10 ) {
if ( V_10 -> V_15 )
F_19 ( V_10 -> V_15 ) ;
free ( V_10 ) ;
}
}
static struct V_29 * F_34 ( long V_30 )
{
struct V_29 * V_31 ;
V_31 = F_4 ( sizeof( struct V_29 ) ) ;
if ( V_31 != NULL )
V_31 -> V_32 = V_30 ;
return V_31 ;
}
static int F_35 ( T_4 * V_33 , T_2 V_25 ,
T_5 * V_34 ,
struct V_35 * V_36 )
{
T_6 V_37 ;
T_5 * V_38 ;
T_7 V_39 ;
unsigned int V_40 ;
T_8 V_30 = 0 ;
bool V_31 = false ;
const char * V_41 ;
int V_42 ;
if ( F_36 ( V_33 , V_43 , & V_37 ) != NULL )
goto V_44;
if ( F_36 ( V_33 , V_45 , & V_37 ) == NULL ||
F_37 ( & V_37 , V_25 , & V_38 , & V_39 , 1 ) <= 0 ||
V_39 == 0 ) {
return - V_19 ;
}
if ( V_38 -> V_46 == V_47 ) {
V_44:
if ( ! V_36 )
return 0 ;
V_42 = strlen ( F_38 ( V_33 ) ) ;
V_36 -> V_48 = F_4 ( V_42 + 2 ) ;
if ( V_36 -> V_48 == NULL )
return - V_8 ;
snprintf ( V_36 -> V_48 , V_42 + 2 , L_8 , F_38 ( V_33 ) ) ;
V_36 -> V_31 = F_34 ( ( long ) V_30 ) ;
if ( V_36 -> V_31 == NULL )
return - V_8 ;
return 0 ;
}
if ( V_38 -> V_46 == V_49 ) {
if ( V_34 == NULL )
return - V_50 ;
V_31 = true ;
V_30 = V_38 -> V_51 ;
V_38 = & V_34 [ 0 ] ;
}
if ( V_38 -> V_46 >= V_52 && V_38 -> V_46 <= V_53 ) {
V_40 = V_38 -> V_46 - V_52 ;
V_30 += V_38 -> V_51 ;
V_31 = true ;
} else if ( V_38 -> V_46 >= V_54 && V_38 -> V_46 <= V_55 ) {
V_40 = V_38 -> V_46 - V_54 ;
} else if ( V_38 -> V_46 == V_56 ) {
V_40 = V_38 -> V_51 ;
V_30 += V_38 -> V_57 ;
V_31 = true ;
} else if ( V_38 -> V_46 == V_58 ) {
V_40 = V_38 -> V_51 ;
} else {
F_3 ( L_9 , V_38 -> V_46 ) ;
return - V_50 ;
}
if ( ! V_36 )
return 0 ;
V_41 = F_39 ( V_40 ) ;
if ( ! V_41 ) {
F_40 ( L_10
L_11 , V_40 ) ;
return - V_59 ;
}
V_36 -> V_48 = F_24 ( V_41 ) ;
if ( V_36 -> V_48 == NULL )
return - V_8 ;
if ( V_31 ) {
V_36 -> V_31 = F_34 ( ( long ) V_30 ) ;
if ( V_36 -> V_31 == NULL )
return - V_8 ;
}
return 0 ;
}
static int F_41 ( T_4 * V_33 ,
struct V_35 * V_36 ,
const char * V_60 )
{
struct V_29 * * V_61 = & V_36 -> V_31 ;
T_4 type ;
char V_62 [ 16 ] ;
int V_63 , V_64 , V_65 ;
int V_42 ;
if ( V_60 && strcmp ( V_60 , L_12 ) != 0 ) {
V_36 -> type = F_24 ( V_60 ) ;
return ( V_36 -> type == NULL ) ? - V_8 : 0 ;
}
V_63 = F_42 ( V_33 ) ;
if ( V_63 > 0 ) {
V_64 = F_43 ( V_33 ) ;
V_65 = F_44 ( V_33 ) ;
if ( V_64 < 0 || V_65 < 0 )
return - V_19 ;
V_42 = snprintf ( V_62 , 16 , L_13 , V_63 , V_64 ,
F_45 ( V_65 ) ) ;
goto V_66;
}
if ( F_46 ( V_33 , & type ) == NULL ) {
F_40 ( L_14 ,
F_38 ( V_33 ) ) ;
return - V_19 ;
}
F_3 ( L_15 ,
F_38 ( V_33 ) , F_38 ( & type ) ) ;
if ( V_60 && strcmp ( V_60 , L_12 ) == 0 ) {
V_42 = F_47 ( & type ) ;
if ( V_42 != V_67 &&
V_42 != V_68 ) {
F_40 ( L_16
L_17 ,
F_38 ( V_33 ) , F_38 ( & type ) ) ;
return - V_27 ;
}
if ( V_42 == V_67 ) {
if ( F_46 ( & type , & type ) == NULL ) {
F_40 ( L_18
L_19 ) ;
return - V_19 ;
}
while ( * V_61 )
V_61 = & ( * V_61 ) -> V_69 ;
* V_61 = F_4 ( sizeof( struct V_29 ) ) ;
if ( * V_61 == NULL ) {
F_40 ( L_20 ) ;
return - V_8 ;
}
}
if ( ! F_48 ( & type , L_21 ) &&
! F_48 ( & type , L_22 ) ) {
F_40 ( L_16
L_23 ,
F_38 ( V_33 ) ) ;
return - V_27 ;
}
V_36 -> type = F_24 ( V_60 ) ;
return ( V_36 -> type == NULL ) ? - V_8 : 0 ;
}
V_42 = F_44 ( & type ) ;
if ( V_42 <= 0 )
return 0 ;
V_42 = F_45 ( V_42 ) ;
if ( V_42 > V_70 ) {
F_49 ( L_24 ,
F_38 ( & type ) , V_70 ) ;
V_42 = V_70 ;
}
V_42 = snprintf ( V_62 , 16 , L_25 ,
F_50 ( & type ) ? 's' : 'u' , V_42 ) ;
V_66:
if ( V_42 < 0 || V_42 >= 16 ) {
if ( V_42 >= 16 )
V_42 = - V_71 ;
F_40 ( L_26 ,
strerror ( - V_42 ) ) ;
return V_42 ;
}
V_36 -> type = F_24 ( V_62 ) ;
if ( V_36 -> type == NULL )
return - V_8 ;
return 0 ;
}
static int F_51 ( T_4 * V_33 , const char * V_72 ,
struct V_73 * V_74 ,
struct V_29 * * V_61 ,
T_4 * V_75 )
{
struct V_29 * V_31 = * V_61 ;
T_4 type ;
T_8 V_30 ;
int V_42 , V_76 ;
F_3 ( L_27 , V_74 -> V_77 , V_72 ) ;
if ( F_46 ( V_33 , & type ) == NULL ) {
F_40 ( L_28 , V_72 ) ;
return - V_19 ;
}
F_23 ( L_29 , ( unsigned ) F_52 ( & type ) ) ;
V_76 = F_47 ( & type ) ;
if ( V_74 -> V_77 [ 0 ] == '[' &&
( V_76 == V_68 || V_76 == V_67 ) ) {
if ( V_74 -> V_69 )
memcpy ( V_75 , & type , sizeof( * V_75 ) ) ;
if ( F_46 ( & type , & type ) == NULL ) {
F_40 ( L_28 , V_72 ) ;
return - V_19 ;
}
F_23 ( L_30 ,
( unsigned ) F_52 ( & type ) ) ;
if ( V_76 == V_67 ) {
V_31 = F_4 ( sizeof( struct V_29 ) ) ;
if ( V_31 == NULL )
return - V_8 ;
if ( * V_61 )
( * V_61 ) -> V_69 = V_31 ;
else
* V_61 = V_31 ;
}
V_31 -> V_32 += F_44 ( & type ) * V_74 -> V_78 ;
if ( ! V_74 -> V_69 )
memcpy ( V_75 , V_33 , sizeof( * V_75 ) ) ;
goto V_69;
} else if ( V_76 == V_67 ) {
if ( ! V_74 -> V_31 ) {
F_30 ( L_31 ,
V_74 -> V_77 ) ;
return - V_27 ;
}
if ( F_46 ( & type , & type ) == NULL ) {
F_40 ( L_28 , V_72 ) ;
return - V_19 ;
}
if ( F_47 ( & type ) != V_79 ) {
F_40 ( L_32 , V_72 ) ;
return - V_27 ;
}
V_31 = F_4 ( sizeof( struct V_29 ) ) ;
if ( V_31 == NULL )
return - V_8 ;
if ( * V_61 )
( * V_61 ) -> V_69 = V_31 ;
else
* V_61 = V_31 ;
} else {
if ( V_76 != V_79 ) {
F_40 ( L_32 , V_72 ) ;
return - V_27 ;
}
if ( V_74 -> V_77 [ 0 ] == '[' ) {
F_30 ( L_33
L_34 , V_72 ) ;
return - V_27 ;
}
if ( V_74 -> V_31 ) {
F_30 ( L_35 ,
V_74 -> V_77 ) ;
return - V_27 ;
}
if ( ! V_31 ) {
F_40 ( L_36
L_37 ) ;
return - V_50 ;
}
}
if ( F_53 ( & type , V_74 -> V_77 , V_75 ) == NULL ) {
F_40 ( L_38 , V_72 ,
F_38 ( & type ) , V_74 -> V_77 ) ;
return - V_27 ;
}
V_42 = F_54 ( V_75 , & V_30 ) ;
if ( V_42 < 0 ) {
F_40 ( L_39 , V_74 -> V_77 ) ;
return V_42 ;
}
V_31 -> V_32 += ( long ) V_30 ;
V_69:
if ( V_74 -> V_69 )
return F_51 ( V_75 , V_74 -> V_77 ,
V_74 -> V_69 , & V_31 , V_75 ) ;
else
return 0 ;
}
static int F_55 ( T_4 * V_33 , struct V_80 * V_81 )
{
T_4 V_75 ;
int V_42 ;
F_3 ( L_40 ,
F_38 ( V_33 ) ) ;
V_42 = F_35 ( V_33 , V_81 -> V_25 , V_81 -> V_34 ,
V_81 -> V_36 ) ;
if ( V_42 == - V_19 )
F_30 ( L_41
L_42 , V_81 -> V_82 -> V_83 ) ;
else if ( V_42 == - V_50 )
F_30 ( L_43 ) ;
else if ( V_81 -> V_82 -> V_74 ) {
V_42 = F_51 ( V_33 , V_81 -> V_82 -> V_83 ,
V_81 -> V_82 -> V_74 , & V_81 -> V_36 -> V_31 ,
& V_75 ) ;
V_33 = & V_75 ;
}
if ( V_42 == 0 )
V_42 = F_41 ( V_33 , V_81 -> V_36 , V_81 -> V_82 -> type ) ;
return V_42 ;
}
static int F_56 ( T_4 * V_84 , struct V_80 * V_81 )
{
T_4 V_33 ;
char V_62 [ 32 ] , * V_85 ;
int V_42 = 0 ;
if ( ! F_57 ( V_81 -> V_82 -> V_83 ) ) {
V_81 -> V_36 -> V_48 = F_24 ( V_81 -> V_82 -> V_83 ) ;
if ( V_81 -> V_36 -> V_48 == NULL )
return - V_8 ;
if ( V_81 -> V_82 -> type ) {
V_81 -> V_36 -> type = F_24 ( V_81 -> V_82 -> type ) ;
if ( V_81 -> V_36 -> type == NULL )
return - V_8 ;
}
if ( V_81 -> V_82 -> V_77 ) {
V_81 -> V_36 -> V_77 = F_24 ( V_81 -> V_82 -> V_77 ) ;
if ( V_81 -> V_36 -> V_77 == NULL )
return - V_8 ;
} else
V_81 -> V_36 -> V_77 = NULL ;
return 0 ;
}
if ( V_81 -> V_82 -> V_77 )
V_81 -> V_36 -> V_77 = F_24 ( V_81 -> V_82 -> V_77 ) ;
else {
V_42 = F_58 ( V_81 -> V_82 , V_62 , 32 ) ;
if ( V_42 < 0 )
return V_42 ;
V_85 = strchr ( V_62 , ':' ) ;
if ( V_85 )
* V_85 = '_' ;
V_81 -> V_36 -> V_77 = F_24 ( V_62 ) ;
}
if ( V_81 -> V_36 -> V_77 == NULL )
return - V_8 ;
F_3 ( L_44 , V_81 -> V_82 -> V_83 ) ;
if ( ! F_59 ( V_84 , V_81 -> V_82 -> V_83 , V_81 -> V_25 , & V_33 ) ) {
if ( ! F_59 ( & V_81 -> V_86 , V_81 -> V_82 -> V_83 , 0 , & V_33 ) )
V_42 = - V_19 ;
}
if ( V_42 >= 0 )
V_42 = F_55 ( & V_33 , V_81 ) ;
if ( V_42 < 0 )
F_40 ( L_45 ,
V_81 -> V_82 -> V_83 ) ;
return V_42 ;
}
static int F_60 ( T_4 * V_87 , T_2 V_88 ,
bool V_89 , struct V_90 * V_91 )
{
T_2 V_92 , V_93 ;
const char * V_77 ;
V_77 = F_38 ( V_87 ) ;
if ( V_77 ) {
if ( F_61 ( V_87 , & V_92 ) != 0 ) {
F_40 ( L_46 ,
F_38 ( V_87 ) ) ;
return - V_19 ;
}
if ( F_62 ( V_87 , & V_93 ) != 0 ) {
F_40 ( L_47 ,
F_38 ( V_87 ) ) ;
return - V_19 ;
}
if ( V_88 > V_93 ) {
F_40 ( L_48 ,
F_38 ( V_87 ) ) ;
return - V_27 ;
}
V_91 -> V_94 = F_24 ( V_77 ) ;
if ( V_91 -> V_94 == NULL )
return - V_8 ;
V_91 -> V_32 = ( unsigned long ) ( V_88 - V_92 ) ;
} else
V_91 -> V_32 = ( unsigned long ) V_88 ;
if ( V_89 ) {
if ( V_92 != V_88 ) {
F_40 ( L_49
L_50 ) ;
return - V_27 ;
}
V_91 -> V_89 = true ;
}
return 0 ;
}
static int F_63 ( T_4 * V_84 , struct V_80 * V_81 )
{
T_6 V_95 ;
T_7 V_39 ;
int V_42 ;
if ( ! V_84 ) {
F_30 ( L_51 ) ;
return - V_27 ;
}
if ( F_47 ( V_84 ) != V_96 ) {
if ( ! F_64 ( & V_81 -> V_86 , V_81 -> V_25 , & V_81 -> V_87 ) ) {
F_40 ( L_52
L_53 ) ;
return - V_19 ;
}
} else
memcpy ( & V_81 -> V_87 , V_84 , sizeof( T_4 ) ) ;
F_36 ( & V_81 -> V_87 , V_97 , & V_95 ) ;
V_42 = F_37 ( & V_95 , V_81 -> V_25 , & V_81 -> V_34 , & V_39 , 1 ) ;
if ( V_42 <= 0 || V_39 == 0 ) {
V_81 -> V_34 = NULL ;
#if F_65 ( 0 , 142 )
} else if ( V_39 == 1 && V_81 -> V_34 [ 0 ] . V_46 == V_98 &&
V_81 -> V_99 != NULL ) {
T_9 * V_100 ;
if ( F_66 ( V_81 -> V_99 , V_81 -> V_25 , & V_100 ) != 0 ||
F_67 ( V_100 , & V_81 -> V_34 , & V_39 ) != 0 ) {
F_40 ( L_54 ,
( V_101 ) V_81 -> V_25 ) ;
return - V_19 ;
}
#endif
}
V_42 = V_81 -> V_102 ( V_84 , V_81 ) ;
V_81 -> V_34 = NULL ;
return V_42 ;
}
static int F_68 ( T_4 * V_103 , void * V_104 )
{
struct V_105 * V_106 = V_104 ;
const char * V_107 ;
int V_108 ;
if ( V_106 -> V_107 ) {
V_107 = F_69 ( V_103 ) ;
if ( ! V_107 || strcmp ( V_106 -> V_107 , V_107 ) != 0 )
return 0 ;
}
if ( V_106 -> V_109 ) {
if ( F_48 ( V_103 , V_106 -> V_109 ) ) {
memcpy ( V_106 -> V_75 , V_103 , sizeof( T_4 ) ) ;
V_106 -> V_7 = true ;
return 1 ;
}
} else {
F_70 ( V_103 , & V_108 ) ;
if ( V_108 < V_106 -> line && V_106 -> V_110 > V_106 -> line - V_108 ) {
V_106 -> V_110 = V_106 -> line - V_108 ;
memcpy ( V_106 -> V_75 , V_103 , sizeof( T_4 ) ) ;
V_106 -> V_7 = true ;
}
}
return 0 ;
}
static T_4 * F_71 ( struct V_80 * V_81 , T_4 * V_75 )
{
struct V_105 V_106 = {
. V_109 = V_81 -> V_111 -> V_112 . V_109 ,
. V_107 = V_81 -> V_113 ,
. line = V_81 -> V_108 ,
. V_110 = V_114 ,
. V_75 = V_75 ,
. V_7 = false ,
} ;
F_72 ( & V_81 -> V_86 , V_81 -> V_25 , F_68 , & V_106 ) ;
return V_106 . V_7 ? V_75 : NULL ;
}
static int F_73 ( const char * V_113 , int V_115 ,
T_2 V_25 , void * V_104 )
{
struct V_80 * V_81 = V_104 ;
T_4 * V_84 , V_75 ;
int V_42 ;
if ( V_115 != V_81 -> V_108 || F_74 ( V_113 , V_81 -> V_113 ) != 0 )
return 0 ;
V_81 -> V_25 = V_25 ;
V_84 = F_71 ( V_81 , & V_75 ) ;
if ( ! V_84 ) {
F_40 ( L_55 ) ;
return - V_19 ;
}
V_42 = F_63 ( V_84 , V_81 ) ;
return V_42 < 0 ? V_42 : 0 ;
}
static int F_75 ( struct V_80 * V_81 )
{
return F_76 ( & V_81 -> V_86 , F_73 , V_81 ) ;
}
static int F_77 ( struct V_1 * V_2 ,
const char * V_113 , const char * V_116 )
{
T_10 * V_117 ;
char * line = NULL ;
T_7 V_118 ;
T_11 V_119 ;
int V_120 = 0 , V_121 = 1 ;
V_117 = fopen ( V_113 , L_56 ) ;
if ( ! V_117 ) {
F_40 ( L_57 , V_113 , strerror ( V_122 ) ) ;
return - V_122 ;
}
while ( ( V_119 = F_78 ( & line , & V_118 , V_117 ) ) > 0 ) {
if ( line [ V_119 - 1 ] == '\n' )
line [ V_119 - 1 ] = '\0' ;
if ( F_79 ( line , V_116 ) ) {
F_1 ( V_2 , V_121 ) ;
V_120 ++ ;
}
V_121 ++ ;
}
if ( ferror ( V_117 ) )
V_120 = - V_122 ;
free ( line ) ;
fclose ( V_117 ) ;
if ( V_120 == 0 )
F_3 ( L_58 , V_113 ) ;
return V_120 ;
}
static int F_80 ( const char * V_113 , int V_115 ,
T_2 V_25 , void * V_104 )
{
struct V_80 * V_81 = V_104 ;
T_4 * V_84 , V_75 ;
int V_42 ;
if ( ! F_7 ( & V_81 -> V_123 , V_115 ) ||
F_74 ( V_113 , V_81 -> V_113 ) != 0 )
return 0 ;
F_3 ( L_59 ,
V_115 , ( unsigned long long ) V_25 ) ;
V_81 -> V_25 = V_25 ;
V_81 -> V_108 = V_115 ;
V_84 = F_71 ( V_81 , & V_75 ) ;
if ( ! V_84 ) {
F_40 ( L_55 ) ;
return - V_19 ;
}
V_42 = F_63 ( V_84 , V_81 ) ;
return V_42 < 0 ? V_42 : 0 ;
}
static int F_81 ( T_4 * V_87 , struct V_80 * V_81 )
{
int V_42 = 0 ;
if ( F_11 ( & V_81 -> V_123 ) ) {
V_42 = F_77 ( & V_81 -> V_123 , V_81 -> V_113 ,
V_81 -> V_111 -> V_112 . V_124 ) ;
if ( V_42 <= 0 )
return V_42 ;
}
return F_76 ( V_87 , F_80 , V_81 ) ;
}
static int F_82 ( T_4 * V_125 , void * V_104 )
{
struct V_80 * V_81 = V_104 ;
struct V_126 * V_127 = & V_81 -> V_111 -> V_112 ;
T_2 V_25 ;
int V_42 ;
if ( V_127 -> V_124 )
V_42 = F_81 ( V_125 , V_81 ) ;
else {
if ( F_61 ( V_125 , & V_25 ) != 0 ) {
F_40 ( L_60 ,
F_38 ( V_125 ) ) ;
return - V_19 ;
}
V_81 -> V_25 = V_25 ;
V_81 -> V_25 += V_127 -> V_32 ;
F_3 ( L_61 ,
( V_101 ) V_81 -> V_25 ) ;
V_42 = F_63 ( V_125 , V_81 ) ;
}
return V_42 ;
}
static int F_83 ( T_4 * V_87 , void * V_104 )
{
struct V_128 * V_129 = V_104 ;
struct V_80 * V_81 = V_129 -> V_104 ;
struct V_126 * V_127 = & V_81 -> V_111 -> V_112 ;
if ( F_47 ( V_87 ) != V_96 ||
! F_48 ( V_87 , V_127 -> V_109 ) )
return V_130 ;
if ( V_127 -> V_107 && F_74 ( V_127 -> V_107 , F_69 ( V_87 ) ) )
return V_130 ;
V_81 -> V_113 = F_69 ( V_87 ) ;
if ( V_127 -> line ) {
F_70 ( V_87 , & V_81 -> V_108 ) ;
V_81 -> V_108 += V_127 -> line ;
V_129 -> V_131 = F_75 ( V_81 ) ;
} else if ( ! F_84 ( V_87 ) ) {
if ( V_127 -> V_124 )
V_129 -> V_131 = F_81 ( V_87 , V_81 ) ;
else {
if ( F_61 ( V_87 , & V_81 -> V_25 ) != 0 ) {
F_40 ( L_62
L_63 , F_38 ( V_87 ) ) ;
V_129 -> V_131 = - V_19 ;
return V_132 ;
}
V_81 -> V_25 += V_127 -> V_32 ;
V_129 -> V_131 = F_63 ( V_87 , V_81 ) ;
}
} else
V_129 -> V_131 = F_85 ( V_87 ,
F_82 , ( void * ) V_81 ) ;
return V_132 ;
}
static int F_86 ( struct V_80 * V_81 )
{
struct V_128 V_133 = { . V_104 = ( void * ) V_81 ,
. V_131 = 0 } ;
F_87 ( & V_81 -> V_86 , F_83 , & V_133 , 0 ) ;
return V_133 . V_131 ;
}
static int F_88 ( T_12 * V_17 , T_13 * V_134 , void * V_104 )
{
struct V_135 * V_129 = V_104 ;
if ( F_89 ( V_17 , V_134 -> V_136 , V_129 -> V_87 ) ) {
if ( F_47 ( V_129 -> V_87 ) != V_96 )
return V_130 ;
if ( F_48 ( V_129 -> V_87 , V_129 -> V_109 ) ) {
if ( ! F_89 ( V_17 , V_134 -> V_137 , V_129 -> V_86 ) )
return V_130 ;
if ( V_129 -> V_107 &&
F_74 ( V_129 -> V_107 , F_69 ( V_129 -> V_87 ) ) )
return V_130 ;
V_129 -> V_7 = 1 ;
return V_132 ;
}
}
return V_130 ;
}
static int F_90 ( struct V_9 * V_10 ,
struct V_80 * V_81 )
{
struct V_126 * V_127 = & V_81 -> V_111 -> V_112 ;
T_14 V_138 , V_139 ;
T_7 V_140 ;
T_4 * V_141 ;
int V_42 = 0 ;
#if F_65 ( 0 , 142 )
V_81 -> V_99 = F_91 ( V_10 -> V_17 ) ;
#endif
V_138 = 0 ;
F_9 ( & V_81 -> V_123 ) ;
if ( V_127 -> V_109 ) {
struct V_135 V_142 = {
. V_109 = V_127 -> V_109 ,
. V_107 = V_127 -> V_107 ,
. V_86 = & V_81 -> V_86 ,
. V_87 = & V_81 -> V_87 ,
. V_7 = 0 ,
} ;
struct V_128 V_143 = {
. V_104 = V_81 ,
} ;
F_92 ( V_10 -> V_17 , F_88 ,
& V_142 , 0 ) ;
if ( V_142 . V_7 ) {
V_42 = F_83 ( & V_81 -> V_87 , & V_143 ) ;
if ( V_42 )
goto V_7;
}
}
while ( ! F_93 ( V_10 -> V_17 , V_138 , & V_139 , & V_140 , NULL , NULL , NULL ) ) {
V_141 = F_89 ( V_10 -> V_17 , V_138 + V_140 , & V_81 -> V_86 ) ;
if ( ! V_141 )
continue;
if ( V_127 -> V_107 )
V_81 -> V_113 = F_94 ( & V_81 -> V_86 , V_127 -> V_107 ) ;
else
V_81 -> V_113 = NULL ;
if ( ! V_127 -> V_107 || V_81 -> V_113 ) {
if ( V_127 -> V_109 )
V_42 = F_86 ( V_81 ) ;
else if ( V_127 -> V_124 )
V_42 = F_81 ( NULL , V_81 ) ;
else {
V_81 -> V_108 = V_127 -> line ;
V_42 = F_75 ( V_81 ) ;
}
if ( V_42 < 0 )
break;
}
V_138 = V_139 ;
}
V_7:
F_10 ( & V_81 -> V_123 ) ;
return V_42 ;
}
static int F_95 ( T_4 * V_84 , struct V_80 * V_81 )
{
struct V_144 * V_145 =
F_96 ( V_81 , struct V_144 , V_81 ) ;
struct V_146 * V_147 ;
int V_42 , V_148 ;
if ( V_145 -> V_149 == V_145 -> V_150 ) {
F_40 ( L_64 ,
V_145 -> V_150 ) ;
return - V_59 ;
}
V_147 = & V_145 -> V_151 [ V_145 -> V_149 ++ ] ;
V_42 = F_60 ( & V_81 -> V_87 , V_81 -> V_25 ,
V_81 -> V_111 -> V_112 . V_89 , & V_147 -> V_112 ) ;
if ( V_42 < 0 )
return V_42 ;
F_3 ( L_65 , V_147 -> V_112 . V_94 ,
V_147 -> V_112 . V_32 ) ;
V_147 -> V_152 = V_81 -> V_111 -> V_152 ;
V_147 -> args = F_4 ( sizeof( struct V_35 ) * V_147 -> V_152 ) ;
if ( V_147 -> args == NULL )
return - V_8 ;
for ( V_148 = 0 ; V_148 < V_81 -> V_111 -> V_152 ; V_148 ++ ) {
V_81 -> V_82 = & V_81 -> V_111 -> args [ V_148 ] ;
V_81 -> V_36 = & V_147 -> args [ V_148 ] ;
V_42 = F_56 ( V_84 , V_81 ) ;
if ( V_42 != 0 )
return V_42 ;
}
return 0 ;
}
int F_97 ( struct V_9 * V_10 ,
struct V_153 * V_111 ,
struct V_146 * * V_151 , int V_150 )
{
struct V_144 V_145 = {
. V_81 = { . V_111 = V_111 , . V_102 = F_95 } ,
. V_150 = V_150 } ;
int V_42 ;
* V_151 = F_4 ( sizeof( struct V_146 ) * V_150 ) ;
if ( * V_151 == NULL )
return - V_8 ;
V_145 . V_151 = * V_151 ;
V_145 . V_149 = 0 ;
V_42 = F_90 ( V_10 , & V_145 . V_81 ) ;
if ( V_42 < 0 ) {
free ( * V_151 ) ;
* V_151 = NULL ;
return V_42 ;
}
return ( V_42 < 0 ) ? V_42 : V_145 . V_149 ;
}
static int F_98 ( T_4 * V_75 , void * V_104 )
{
struct V_154 * V_155 = V_104 ;
struct V_156 * V_157 ;
char V_62 [ V_158 ] ;
int V_76 , V_42 ;
V_157 = & V_155 -> V_159 [ V_155 -> V_160 - 1 ] ;
V_76 = F_47 ( V_75 ) ;
if ( V_76 == V_161 ||
V_76 == V_162 ) {
V_42 = F_35 ( V_75 , V_155 -> V_81 . V_25 ,
V_155 -> V_81 . V_34 , NULL ) ;
if ( V_42 == 0 ) {
V_42 = F_99 ( V_75 , V_62 , V_158 ) ;
F_23 ( L_66 , V_62 ) ;
if ( V_42 > 0 )
F_100 ( V_157 -> V_163 , V_62 ) ;
}
}
if ( V_155 -> V_164 && F_101 ( V_75 , V_155 -> V_81 . V_25 ) )
return V_165 ;
else
return V_166 ;
}
static int F_102 ( T_4 * V_84 , struct V_80 * V_81 )
{
struct V_154 * V_155 =
F_96 ( V_81 , struct V_154 , V_81 ) ;
struct V_156 * V_157 ;
T_4 V_75 ;
int V_42 ;
if ( V_155 -> V_160 == V_155 -> V_167 ) {
F_40 ( L_64 , V_155 -> V_167 ) ;
return - V_59 ;
}
V_157 = & V_155 -> V_159 [ V_155 -> V_160 ++ ] ;
V_42 = F_60 ( & V_81 -> V_87 , V_81 -> V_25 ,
V_81 -> V_111 -> V_112 . V_89 , & V_157 -> V_112 ) ;
if ( V_42 < 0 )
return V_42 ;
F_3 ( L_65 , V_157 -> V_112 . V_94 ,
V_157 -> V_112 . V_32 ) ;
V_157 -> V_163 = F_103 ( true , NULL ) ;
if ( V_157 -> V_163 == NULL )
return - V_8 ;
V_155 -> V_164 = true ;
F_104 ( V_84 , F_98 , ( void * ) V_155 , & V_75 ) ;
if ( ! V_155 -> V_168 )
goto V_169;
V_155 -> V_164 = false ;
F_104 ( & V_81 -> V_86 , F_98 , ( void * ) V_155 , & V_75 ) ;
V_169:
if ( F_105 ( V_157 -> V_163 ) ) {
F_106 ( V_157 -> V_163 ) ;
V_157 -> V_163 = NULL ;
}
return V_42 ;
}
int F_107 ( struct V_9 * V_10 ,
struct V_153 * V_111 ,
struct V_156 * * V_159 ,
int V_167 , bool V_168 )
{
struct V_154 V_155 = {
. V_81 = { . V_111 = V_111 , . V_102 = F_102 } ,
. V_167 = V_167 , . V_168 = V_168 } ;
int V_42 ;
* V_159 = F_4 ( sizeof( struct V_156 ) * V_167 ) ;
if ( * V_159 == NULL )
return - V_8 ;
V_155 . V_159 = * V_159 ;
V_155 . V_160 = 0 ;
V_42 = F_90 ( V_10 , & V_155 . V_81 ) ;
if ( V_42 < 0 ) {
while ( V_155 . V_160 -- ) {
if ( V_155 . V_159 [ V_155 . V_160 ] . V_112 . V_94 )
free ( V_155 . V_159 [ V_155 . V_160 ] . V_112 . V_94 ) ;
if ( V_155 . V_159 [ V_155 . V_160 ] . V_163 )
F_106 ( V_155 . V_159 [ V_155 . V_160 ] . V_163 ) ;
}
free ( V_155 . V_159 ) ;
* V_159 = NULL ;
return V_42 ;
}
return ( V_42 < 0 ) ? V_42 : V_155 . V_160 ;
}
int F_108 ( struct V_9 * V_10 , unsigned long V_25 ,
struct V_126 * V_170 )
{
T_4 V_171 , V_172 , V_173 ;
T_2 V_174 , V_175 ;
const char * V_113 = NULL , * V_176 = NULL , * V_177 ;
int V_178 = 0 , V_115 = 0 , V_42 = 0 ;
V_25 += V_10 -> V_18 ;
if ( ! F_109 ( V_10 -> V_17 , ( T_2 ) V_25 - V_10 -> V_18 , & V_171 ) ) {
F_40 ( L_67 ,
V_25 ) ;
V_42 = - V_27 ;
goto V_179;
}
F_110 ( & V_171 , V_25 , & V_113 , & V_115 ) ;
if ( F_64 ( & V_171 , ( T_2 ) V_25 , & V_172 ) ) {
V_177 = F_38 ( & V_172 ) ;
if ( ! V_177 ||
F_61 ( & V_172 , & V_175 ) != 0 ||
F_70 ( & V_172 , & V_178 ) != 0 )
goto V_180;
V_176 = V_177 ;
if ( V_25 == ( unsigned long ) V_175 )
V_115 = V_178 ;
else if ( F_111 ( & V_172 , ( T_2 ) V_25 ,
& V_173 ) ) {
if ( F_61 ( & V_173 , & V_174 ) == 0 &&
V_174 == V_25 )
V_115 = F_112 ( & V_173 ) ;
else {
V_177 = F_38 ( & V_173 ) ;
if ( V_177 &&
F_70 ( & V_172 , & V_178 ) == 0 )
V_176 = V_177 ;
}
}
}
V_180:
if ( V_115 )
V_170 -> line = V_115 - V_178 ;
else if ( V_176 )
V_170 -> V_32 = V_25 - ( unsigned long ) V_175 ;
if ( V_176 ) {
V_170 -> V_109 = F_24 ( V_176 ) ;
if ( V_170 -> V_109 == NULL ) {
V_42 = - V_8 ;
goto V_179;
}
}
if ( V_113 ) {
V_170 -> V_107 = F_24 ( V_113 ) ;
if ( V_170 -> V_107 == NULL ) {
if ( V_170 -> V_109 ) {
free ( V_170 -> V_109 ) ;
V_170 -> V_109 = NULL ;
}
V_42 = - V_8 ;
goto V_179;
}
}
V_179:
if ( V_42 == 0 && ( V_113 || V_176 ) )
V_42 = 1 ;
return V_42 ;
}
static int F_113 ( const char * V_181 , unsigned int V_115 ,
struct V_182 * V_183 )
{
if ( ! V_183 -> V_11 ) {
V_183 -> V_11 = F_24 ( V_181 ) ;
if ( V_183 -> V_11 == NULL )
return - V_8 ;
}
return F_1 ( & V_183 -> V_184 , V_115 ) ;
}
static int F_114 ( const char * V_113 , int V_115 ,
T_2 V_25 V_28 ,
void * V_104 )
{
struct V_185 * V_186 = V_104 ;
if ( ( F_74 ( V_113 , V_186 -> V_113 ) != 0 ) ||
( V_186 -> V_187 > V_115 || V_186 -> V_188 < V_115 ) )
return 0 ;
if ( F_113 ( V_113 , V_115 , V_186 -> V_183 ) < 0 )
return - V_27 ;
return 0 ;
}
static int F_115 ( T_4 * V_87 , struct V_185 * V_186 )
{
int V_42 ;
V_42 = F_76 ( V_87 ? : & V_186 -> V_86 , F_114 , V_186 ) ;
if ( V_42 >= 0 )
if ( ! F_11 ( & V_186 -> V_183 -> V_184 ) )
V_42 = V_186 -> V_7 = 1 ;
else
V_42 = 0 ;
else {
free ( V_186 -> V_183 -> V_11 ) ;
V_186 -> V_183 -> V_11 = NULL ;
}
return V_42 ;
}
static int F_116 ( T_4 * V_125 , void * V_104 )
{
F_115 ( V_125 , V_104 ) ;
return 0 ;
}
static int F_117 ( T_4 * V_87 , void * V_104 )
{
struct V_128 * V_129 = V_104 ;
struct V_185 * V_186 = V_129 -> V_104 ;
struct V_182 * V_183 = V_186 -> V_183 ;
if ( V_183 -> V_107 && F_74 ( V_183 -> V_107 , F_69 ( V_87 ) ) )
return V_130 ;
if ( F_47 ( V_87 ) == V_96 &&
F_48 ( V_87 , V_183 -> V_109 ) ) {
V_186 -> V_113 = F_69 ( V_87 ) ;
F_70 ( V_87 , & V_183 -> V_32 ) ;
F_3 ( L_68 , V_186 -> V_113 , V_183 -> V_32 ) ;
V_186 -> V_187 = V_183 -> V_32 + V_183 -> V_189 ;
if ( V_186 -> V_187 < 0 )
V_186 -> V_187 = V_114 ;
V_186 -> V_188 = V_183 -> V_32 + V_183 -> V_179 ;
if ( V_186 -> V_188 < 0 )
V_186 -> V_188 = V_114 ;
F_3 ( L_69 , V_186 -> V_187 , V_186 -> V_188 ) ;
V_183 -> V_189 = V_186 -> V_187 ;
V_183 -> V_179 = V_186 -> V_188 ;
if ( F_84 ( V_87 ) )
V_129 -> V_131 = F_85 ( V_87 ,
F_116 , V_186 ) ;
else
V_129 -> V_131 = F_115 ( V_87 , V_186 ) ;
return V_132 ;
}
return V_130 ;
}
static int F_118 ( struct V_185 * V_186 )
{
struct V_128 V_129 = { . V_104 = ( void * ) V_186 , . V_131 = 0 } ;
F_87 ( & V_186 -> V_86 , F_117 , & V_129 , 0 ) ;
return V_129 . V_131 ;
}
int F_119 ( struct V_9 * V_10 , struct V_182 * V_183 )
{
struct V_185 V_186 = { . V_183 = V_183 , . V_7 = 0 } ;
int V_42 = 0 ;
T_14 V_138 = 0 , V_139 ;
T_7 V_140 ;
T_4 * V_141 ;
const char * V_190 ;
if ( V_183 -> V_109 ) {
struct V_135 V_142 = {
. V_109 = V_183 -> V_109 , . V_107 = V_183 -> V_107 ,
. V_86 = & V_186 . V_86 , . V_87 = & V_186 . V_87 , . V_7 = 0 } ;
struct V_128 V_191 = {
. V_104 = ( void * ) & V_186 , . V_131 = 0 } ;
F_92 ( V_10 -> V_17 , F_88 ,
& V_142 , 0 ) ;
if ( V_142 . V_7 ) {
F_117 ( & V_186 . V_87 , & V_191 ) ;
if ( V_186 . V_7 )
goto V_7;
}
}
while ( ! V_186 . V_7 && V_42 >= 0 ) {
if ( F_93 ( V_10 -> V_17 , V_138 , & V_139 , & V_140 ,
NULL , NULL , NULL ) != 0 )
break;
V_141 = F_89 ( V_10 -> V_17 , V_138 + V_140 , & V_186 . V_86 ) ;
if ( ! V_141 )
continue;
if ( V_183 -> V_107 )
V_186 . V_113 = F_94 ( & V_186 . V_86 , V_183 -> V_107 ) ;
else
V_186 . V_113 = 0 ;
if ( ! V_183 -> V_107 || V_186 . V_113 ) {
if ( V_183 -> V_109 )
V_42 = F_118 ( & V_186 ) ;
else {
V_186 . V_187 = V_183 -> V_189 ;
V_186 . V_188 = V_183 -> V_179 ;
V_42 = F_115 ( NULL , & V_186 ) ;
}
}
V_138 = V_139 ;
}
V_7:
if ( V_186 . V_7 ) {
V_190 = F_120 ( & V_186 . V_86 ) ;
if ( V_190 ) {
V_183 -> V_190 = F_24 ( V_190 ) ;
if ( ! V_183 -> V_190 )
V_42 = - V_8 ;
}
}
F_3 ( L_70 , V_183 -> V_11 ) ;
return ( V_42 < 0 ) ? V_42 : V_186 . V_7 ;
}
