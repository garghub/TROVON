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
V_10 -> V_17 = F_18 ( V_10 -> V_16 , & V_10 -> V_18 ) ;
if ( ! V_10 -> V_17 )
goto error;
return 0 ;
error:
if ( V_10 -> V_14 )
F_19 ( V_10 -> V_14 ) ;
else
F_20 ( V_12 ) ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
return - V_19 ;
}
static int F_21 ( T_1 * V_16 ,
void * * V_20 ,
const char * V_21 ,
T_2 V_22 ,
char * * V_23 , T_3 * * V_24 )
{
int V_12 ;
const char * V_11 = F_22 ( V_21 ) ;
F_23 ( L_3 , V_11 , V_21 ) ;
if ( V_11 ) {
V_12 = F_15 ( V_11 , V_13 ) ;
if ( V_12 >= 0 ) {
* V_23 = F_24 ( V_11 ) ;
return V_12 ;
}
}
return F_25 ( V_16 , V_20 , V_21 , V_22 ,
V_23 , V_24 ) ;
}
static int F_26 ( struct V_9 * V_10 ,
T_2 V_25 )
{
V_10 -> V_14 = F_16 ( & V_26 ) ;
if ( ! V_10 -> V_14 )
return - V_27 ;
F_27 ( V_10 -> V_14 ) ;
F_28 ( V_10 -> V_14 ) ;
V_10 -> V_17 = F_29 ( V_10 -> V_14 , V_25 , & V_10 -> V_18 ) ;
if ( ! V_10 -> V_17 ) {
F_3 ( L_4 ,
( unsigned long ) V_25 ) ;
F_19 ( V_10 -> V_14 ) ;
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
if ( V_10 -> V_14 )
F_19 ( V_10 -> V_14 ) ;
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
if ( F_46 ( & type , & type ) == NULL ) {
F_40 ( L_18
L_19 ) ;
return - V_19 ;
}
if ( V_42 == V_67 ) {
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
V_76 = F_47 ( & type ) ;
if ( V_76 != V_79 && V_76 != V_80 ) {
F_40 ( L_32 ,
V_72 ) ;
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
if ( V_76 != V_79 && V_76 != V_80 ) {
F_40 ( L_32 ,
V_72 ) ;
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
if ( V_76 == V_80 ) {
V_30 = 0 ;
} else {
V_42 = F_54 ( V_75 , & V_30 ) ;
if ( V_42 < 0 ) {
F_40 ( L_39 ,
V_74 -> V_77 ) ;
return V_42 ;
}
}
V_31 -> V_32 += ( long ) V_30 ;
V_69:
if ( V_74 -> V_69 )
return F_51 ( V_75 , V_74 -> V_77 ,
V_74 -> V_69 , & V_31 , V_75 ) ;
else
return 0 ;
}
static int F_55 ( T_4 * V_33 , struct V_81 * V_82 )
{
T_4 V_75 ;
int V_42 ;
F_3 ( L_40 ,
F_38 ( V_33 ) ) ;
V_42 = F_35 ( V_33 , V_82 -> V_25 , V_82 -> V_34 ,
V_82 -> V_36 ) ;
if ( V_42 == - V_19 )
F_30 ( L_41
L_42 , V_82 -> V_83 -> V_84 ) ;
else if ( V_42 == - V_50 )
F_30 ( L_43 ) ;
else if ( V_82 -> V_83 -> V_74 ) {
V_42 = F_51 ( V_33 , V_82 -> V_83 -> V_84 ,
V_82 -> V_83 -> V_74 , & V_82 -> V_36 -> V_31 ,
& V_75 ) ;
V_33 = & V_75 ;
}
if ( V_42 == 0 )
V_42 = F_41 ( V_33 , V_82 -> V_36 , V_82 -> V_83 -> type ) ;
return V_42 ;
}
static int F_56 ( T_4 * V_85 , struct V_81 * V_82 )
{
T_4 V_33 ;
char V_62 [ 32 ] , * V_86 ;
int V_42 = 0 ;
if ( ! F_57 ( V_82 -> V_83 -> V_84 ) ) {
V_82 -> V_36 -> V_48 = F_24 ( V_82 -> V_83 -> V_84 ) ;
if ( V_82 -> V_36 -> V_48 == NULL )
return - V_8 ;
if ( V_82 -> V_83 -> type ) {
V_82 -> V_36 -> type = F_24 ( V_82 -> V_83 -> type ) ;
if ( V_82 -> V_36 -> type == NULL )
return - V_8 ;
}
if ( V_82 -> V_83 -> V_77 ) {
V_82 -> V_36 -> V_77 = F_24 ( V_82 -> V_83 -> V_77 ) ;
if ( V_82 -> V_36 -> V_77 == NULL )
return - V_8 ;
} else
V_82 -> V_36 -> V_77 = NULL ;
return 0 ;
}
if ( V_82 -> V_83 -> V_77 )
V_82 -> V_36 -> V_77 = F_24 ( V_82 -> V_83 -> V_77 ) ;
else {
V_42 = F_58 ( V_82 -> V_83 , V_62 , 32 ) ;
if ( V_42 < 0 )
return V_42 ;
V_86 = strchr ( V_62 , ':' ) ;
if ( V_86 )
* V_86 = '_' ;
V_82 -> V_36 -> V_77 = F_24 ( V_62 ) ;
}
if ( V_82 -> V_36 -> V_77 == NULL )
return - V_8 ;
F_3 ( L_44 , V_82 -> V_83 -> V_84 ) ;
if ( ! F_59 ( V_85 , V_82 -> V_83 -> V_84 , V_82 -> V_25 , & V_33 ) ) {
if ( ! F_59 ( & V_82 -> V_87 , V_82 -> V_83 -> V_84 , 0 , & V_33 ) )
V_42 = - V_19 ;
}
if ( V_42 >= 0 )
V_42 = F_55 ( & V_33 , V_82 ) ;
if ( V_42 < 0 )
F_40 ( L_45 ,
V_82 -> V_83 -> V_84 ) ;
return V_42 ;
}
static int F_60 ( T_4 * V_88 , T_1 * V_16 ,
T_2 V_89 , bool V_90 ,
struct V_91 * V_92 )
{
T_2 V_93 , V_94 ;
T_9 V_95 ;
const char * V_96 ;
if ( F_61 ( V_88 , & V_93 ) != 0 ) {
F_40 ( L_46 ,
F_38 ( V_88 ) ) ;
return - V_19 ;
}
if ( F_62 ( V_88 , & V_94 ) != 0 ) {
F_40 ( L_47 ,
F_38 ( V_88 ) ) ;
return - V_19 ;
}
if ( V_89 > V_94 ) {
F_40 ( L_48 ,
F_38 ( V_88 ) ) ;
return - V_27 ;
}
V_96 = F_63 ( V_16 , V_89 , & V_95 , NULL ) ;
if ( ! V_96 ) {
F_40 ( L_49 ,
( unsigned long ) V_89 ) ;
return - V_19 ;
}
V_92 -> V_32 = ( unsigned long ) ( V_89 - V_95 . V_97 ) ;
V_92 -> V_96 = F_24 ( V_96 ) ;
if ( ! V_92 -> V_96 )
return - V_8 ;
if ( V_90 ) {
if ( V_93 != V_89 ) {
F_40 ( L_50
L_51 ) ;
return - V_27 ;
}
V_92 -> V_90 = true ;
}
return 0 ;
}
static int F_64 ( T_4 * V_85 , struct V_81 * V_82 )
{
T_6 V_98 ;
T_7 V_39 ;
int V_42 ;
if ( ! V_85 ) {
F_30 ( L_52 ) ;
return - V_27 ;
}
if ( ! F_65 ( V_85 ) ) {
if ( ! F_66 ( & V_82 -> V_87 , V_82 -> V_25 , & V_82 -> V_88 ) ) {
F_40 ( L_53
L_54 ) ;
return - V_19 ;
}
} else
memcpy ( & V_82 -> V_88 , V_85 , sizeof( T_4 ) ) ;
F_36 ( & V_82 -> V_88 , V_99 , & V_98 ) ;
V_42 = F_37 ( & V_98 , V_82 -> V_25 , & V_82 -> V_34 , & V_39 , 1 ) ;
if ( V_42 <= 0 || V_39 == 0 ) {
V_82 -> V_34 = NULL ;
#if F_67 ( 0 , 142 )
} else if ( V_39 == 1 && V_82 -> V_34 [ 0 ] . V_46 == V_100 &&
V_82 -> V_101 != NULL ) {
T_10 * V_102 ;
if ( F_68 ( V_82 -> V_101 , V_82 -> V_25 , & V_102 ) != 0 ||
F_69 ( V_102 , & V_82 -> V_34 , & V_39 ) != 0 ) {
F_40 ( L_55 ,
( V_103 ) V_82 -> V_25 ) ;
return - V_19 ;
}
#endif
}
V_42 = V_82 -> V_104 ( V_85 , V_82 ) ;
V_82 -> V_34 = NULL ;
return V_42 ;
}
static int F_70 ( T_4 * V_105 , void * V_106 )
{
struct V_107 * V_108 = V_106 ;
const char * V_109 ;
int V_110 ;
if ( V_108 -> V_109 ) {
V_109 = F_71 ( V_105 ) ;
if ( ! V_109 || strcmp ( V_108 -> V_109 , V_109 ) != 0 )
return 0 ;
}
if ( V_108 -> V_111 ) {
if ( F_48 ( V_105 , V_108 -> V_111 ) ) {
memcpy ( V_108 -> V_75 , V_105 , sizeof( T_4 ) ) ;
V_108 -> V_7 = true ;
return 1 ;
}
} else {
F_72 ( V_105 , & V_110 ) ;
if ( V_110 < V_108 -> line && V_108 -> V_112 > V_108 -> line - V_110 ) {
V_108 -> V_112 = V_108 -> line - V_110 ;
memcpy ( V_108 -> V_75 , V_105 , sizeof( T_4 ) ) ;
V_108 -> V_7 = true ;
}
}
return 0 ;
}
static T_4 * F_73 ( struct V_81 * V_82 , T_4 * V_75 )
{
struct V_107 V_108 = {
. V_111 = V_82 -> V_113 -> V_114 . V_111 ,
. V_109 = V_82 -> V_115 ,
. line = V_82 -> V_110 ,
. V_112 = V_116 ,
. V_75 = V_75 ,
. V_7 = false ,
} ;
F_74 ( & V_82 -> V_87 , V_82 -> V_25 , F_70 , & V_108 ) ;
return V_108 . V_7 ? V_75 : NULL ;
}
static int F_75 ( const char * V_115 , int V_117 ,
T_2 V_25 , void * V_106 )
{
struct V_81 * V_82 = V_106 ;
T_4 * V_85 , V_75 ;
int V_42 ;
if ( V_117 != V_82 -> V_110 || F_76 ( V_115 , V_82 -> V_115 ) != 0 )
return 0 ;
V_82 -> V_25 = V_25 ;
V_85 = F_73 ( V_82 , & V_75 ) ;
if ( ! V_85 ) {
F_40 ( L_56 ) ;
return - V_19 ;
}
V_42 = F_64 ( V_85 , V_82 ) ;
return V_42 < 0 ? V_42 : 0 ;
}
static int F_77 ( struct V_81 * V_82 )
{
return F_78 ( & V_82 -> V_87 , F_75 , V_82 ) ;
}
static int F_79 ( struct V_1 * V_2 ,
const char * V_115 , const char * V_118 )
{
T_11 * V_119 ;
char * line = NULL ;
T_7 V_120 ;
T_12 V_121 ;
int V_122 = 0 , V_123 = 1 ;
V_119 = fopen ( V_115 , L_57 ) ;
if ( ! V_119 ) {
F_40 ( L_58 , V_115 , strerror ( V_124 ) ) ;
return - V_124 ;
}
while ( ( V_121 = F_80 ( & line , & V_120 , V_119 ) ) > 0 ) {
if ( line [ V_121 - 1 ] == '\n' )
line [ V_121 - 1 ] = '\0' ;
if ( F_81 ( line , V_118 ) ) {
F_1 ( V_2 , V_123 ) ;
V_122 ++ ;
}
V_123 ++ ;
}
if ( ferror ( V_119 ) )
V_122 = - V_124 ;
free ( line ) ;
fclose ( V_119 ) ;
if ( V_122 == 0 )
F_3 ( L_59 , V_115 ) ;
return V_122 ;
}
static int F_82 ( const char * V_115 , int V_117 ,
T_2 V_25 , void * V_106 )
{
struct V_81 * V_82 = V_106 ;
T_4 * V_85 , V_75 ;
int V_42 ;
if ( ! F_7 ( & V_82 -> V_125 , V_117 ) ||
F_76 ( V_115 , V_82 -> V_115 ) != 0 )
return 0 ;
F_3 ( L_60 ,
V_117 , ( unsigned long long ) V_25 ) ;
V_82 -> V_25 = V_25 ;
V_82 -> V_110 = V_117 ;
V_85 = F_73 ( V_82 , & V_75 ) ;
if ( ! V_85 ) {
F_40 ( L_56 ) ;
return - V_19 ;
}
V_42 = F_64 ( V_85 , V_82 ) ;
return V_42 < 0 ? V_42 : 0 ;
}
static int F_83 ( T_4 * V_88 , struct V_81 * V_82 )
{
int V_42 = 0 ;
if ( F_11 ( & V_82 -> V_125 ) ) {
V_42 = F_79 ( & V_82 -> V_125 , V_82 -> V_115 ,
V_82 -> V_113 -> V_114 . V_126 ) ;
if ( V_42 <= 0 )
return V_42 ;
}
return F_78 ( V_88 , F_82 , V_82 ) ;
}
static int F_84 ( T_4 * V_127 , void * V_106 )
{
struct V_81 * V_82 = V_106 ;
struct V_128 * V_129 = & V_82 -> V_113 -> V_114 ;
T_2 V_25 ;
int V_42 ;
if ( V_129 -> V_126 )
V_42 = F_83 ( V_127 , V_82 ) ;
else {
if ( F_61 ( V_127 , & V_25 ) != 0 ) {
F_40 ( L_61 ,
F_38 ( V_127 ) ) ;
return - V_19 ;
}
V_82 -> V_25 = V_25 ;
V_82 -> V_25 += V_129 -> V_32 ;
F_3 ( L_62 ,
( V_103 ) V_82 -> V_25 ) ;
V_42 = F_64 ( V_127 , V_82 ) ;
}
return V_42 ;
}
static int F_85 ( T_4 * V_88 , void * V_106 )
{
struct V_130 * V_131 = V_106 ;
struct V_81 * V_82 = V_131 -> V_106 ;
struct V_128 * V_129 = & V_82 -> V_113 -> V_114 ;
if ( ! F_65 ( V_88 ) ||
! F_48 ( V_88 , V_129 -> V_111 ) )
return V_132 ;
if ( V_129 -> V_109 && F_76 ( V_129 -> V_109 , F_71 ( V_88 ) ) )
return V_132 ;
V_82 -> V_115 = F_71 ( V_88 ) ;
if ( V_129 -> line ) {
F_72 ( V_88 , & V_82 -> V_110 ) ;
V_82 -> V_110 += V_129 -> line ;
V_131 -> V_133 = F_77 ( V_82 ) ;
} else if ( ! F_86 ( V_88 ) ) {
if ( V_129 -> V_126 )
V_131 -> V_133 = F_83 ( V_88 , V_82 ) ;
else {
if ( F_61 ( V_88 , & V_82 -> V_25 ) != 0 ) {
F_40 ( L_63
L_64 , F_38 ( V_88 ) ) ;
V_131 -> V_133 = - V_19 ;
return V_134 ;
}
V_82 -> V_25 += V_129 -> V_32 ;
V_131 -> V_133 = F_64 ( V_88 , V_82 ) ;
}
} else
V_131 -> V_133 = F_87 ( V_88 ,
F_84 , ( void * ) V_82 ) ;
return V_134 ;
}
static int F_88 ( struct V_81 * V_82 )
{
struct V_130 V_135 = { . V_106 = ( void * ) V_82 ,
. V_133 = 0 } ;
F_89 ( & V_82 -> V_87 , F_85 , & V_135 , 0 ) ;
return V_135 . V_133 ;
}
static int F_90 ( T_13 * V_17 , T_14 * V_136 , void * V_106 )
{
struct V_137 * V_131 = V_106 ;
if ( F_91 ( V_17 , V_136 -> V_138 , V_131 -> V_88 ) ) {
if ( F_47 ( V_131 -> V_88 ) != V_139 )
return V_132 ;
if ( F_48 ( V_131 -> V_88 , V_131 -> V_111 ) ) {
if ( ! F_91 ( V_17 , V_136 -> V_140 , V_131 -> V_87 ) )
return V_132 ;
if ( V_131 -> V_109 &&
F_76 ( V_131 -> V_109 , F_71 ( V_131 -> V_88 ) ) )
return V_132 ;
V_131 -> V_7 = 1 ;
return V_134 ;
}
}
return V_132 ;
}
static int F_92 ( struct V_9 * V_10 ,
struct V_81 * V_82 )
{
struct V_128 * V_129 = & V_82 -> V_113 -> V_114 ;
T_15 V_141 , V_142 ;
T_7 V_143 ;
T_4 * V_144 ;
int V_42 = 0 ;
#if F_67 ( 0 , 142 )
V_82 -> V_101 = F_93 ( V_10 -> V_17 ) ;
#endif
V_141 = 0 ;
F_9 ( & V_82 -> V_125 ) ;
if ( V_129 -> V_111 ) {
struct V_137 V_145 = {
. V_111 = V_129 -> V_111 ,
. V_109 = V_129 -> V_109 ,
. V_87 = & V_82 -> V_87 ,
. V_88 = & V_82 -> V_88 ,
. V_7 = 0 ,
} ;
struct V_130 V_146 = {
. V_106 = V_82 ,
} ;
F_94 ( V_10 -> V_17 , F_90 ,
& V_145 , 0 ) ;
if ( V_145 . V_7 ) {
V_42 = F_85 ( & V_82 -> V_88 , & V_146 ) ;
if ( V_42 )
goto V_7;
}
}
while ( ! F_95 ( V_10 -> V_17 , V_141 , & V_142 , & V_143 , NULL , NULL , NULL ) ) {
V_144 = F_91 ( V_10 -> V_17 , V_141 + V_143 , & V_82 -> V_87 ) ;
if ( ! V_144 )
continue;
if ( V_129 -> V_109 )
V_82 -> V_115 = F_96 ( & V_82 -> V_87 , V_129 -> V_109 ) ;
else
V_82 -> V_115 = NULL ;
if ( ! V_129 -> V_109 || V_82 -> V_115 ) {
if ( V_129 -> V_111 )
V_42 = F_88 ( V_82 ) ;
else if ( V_129 -> V_126 )
V_42 = F_83 ( NULL , V_82 ) ;
else {
V_82 -> V_110 = V_129 -> line ;
V_42 = F_77 ( V_82 ) ;
}
if ( V_42 < 0 )
break;
}
V_141 = V_142 ;
}
V_7:
F_10 ( & V_82 -> V_125 ) ;
return V_42 ;
}
static int F_97 ( T_4 * V_85 , struct V_81 * V_82 )
{
struct V_147 * V_148 =
F_98 ( V_82 , struct V_147 , V_82 ) ;
struct V_149 * V_150 ;
int V_42 , V_151 ;
if ( V_148 -> V_152 == V_148 -> V_153 ) {
F_40 ( L_65 ,
V_148 -> V_153 ) ;
return - V_59 ;
}
V_150 = & V_148 -> V_154 [ V_148 -> V_152 ++ ] ;
V_42 = F_60 ( & V_82 -> V_88 , V_148 -> V_16 , V_82 -> V_25 ,
V_82 -> V_113 -> V_114 . V_90 , & V_150 -> V_114 ) ;
if ( V_42 < 0 )
return V_42 ;
F_3 ( L_66 , V_150 -> V_114 . V_96 ,
V_150 -> V_114 . V_32 ) ;
V_150 -> V_155 = V_82 -> V_113 -> V_155 ;
V_150 -> args = F_4 ( sizeof( struct V_35 ) * V_150 -> V_155 ) ;
if ( V_150 -> args == NULL )
return - V_8 ;
for ( V_151 = 0 ; V_151 < V_82 -> V_113 -> V_155 ; V_151 ++ ) {
V_82 -> V_83 = & V_82 -> V_113 -> args [ V_151 ] ;
V_82 -> V_36 = & V_150 -> args [ V_151 ] ;
V_42 = F_56 ( V_85 , V_82 ) ;
if ( V_42 != 0 )
return V_42 ;
}
return 0 ;
}
int F_99 ( struct V_9 * V_10 ,
struct V_156 * V_113 ,
struct V_149 * * V_154 , int V_153 )
{
struct V_147 V_148 = {
. V_82 = { . V_113 = V_113 , . V_104 = F_97 } ,
. V_16 = V_10 -> V_16 , . V_153 = V_153 } ;
int V_42 ;
* V_154 = F_4 ( sizeof( struct V_149 ) * V_153 ) ;
if ( * V_154 == NULL )
return - V_8 ;
V_148 . V_154 = * V_154 ;
V_148 . V_152 = 0 ;
V_42 = F_92 ( V_10 , & V_148 . V_82 ) ;
if ( V_42 < 0 ) {
free ( * V_154 ) ;
* V_154 = NULL ;
return V_42 ;
}
return ( V_42 < 0 ) ? V_42 : V_148 . V_152 ;
}
static int F_100 ( T_4 * V_75 , void * V_106 )
{
struct V_157 * V_158 = V_106 ;
struct V_159 * V_160 ;
char V_62 [ V_161 ] ;
int V_76 , V_42 ;
V_160 = & V_158 -> V_162 [ V_158 -> V_163 - 1 ] ;
V_76 = F_47 ( V_75 ) ;
if ( V_76 == V_164 ||
V_76 == V_165 ) {
V_42 = F_35 ( V_75 , V_158 -> V_82 . V_25 ,
V_158 -> V_82 . V_34 , NULL ) ;
if ( V_42 == 0 ) {
V_42 = F_101 ( V_75 , V_62 , V_161 ) ;
F_23 ( L_67 , V_62 ) ;
if ( V_42 > 0 )
F_102 ( V_160 -> V_166 , V_62 ) ;
}
}
if ( V_158 -> V_167 && F_103 ( V_75 , V_158 -> V_82 . V_25 ) )
return V_168 ;
else
return V_169 ;
}
static int F_104 ( T_4 * V_85 , struct V_81 * V_82 )
{
struct V_157 * V_158 =
F_98 ( V_82 , struct V_157 , V_82 ) ;
struct V_159 * V_160 ;
T_4 V_75 ;
int V_42 ;
if ( V_158 -> V_163 == V_158 -> V_170 ) {
F_40 ( L_65 , V_158 -> V_170 ) ;
return - V_59 ;
}
V_160 = & V_158 -> V_162 [ V_158 -> V_163 ++ ] ;
V_42 = F_60 ( & V_82 -> V_88 , V_158 -> V_16 , V_82 -> V_25 ,
V_82 -> V_113 -> V_114 . V_90 , & V_160 -> V_114 ) ;
if ( V_42 < 0 )
return V_42 ;
F_3 ( L_66 , V_160 -> V_114 . V_96 ,
V_160 -> V_114 . V_32 ) ;
V_160 -> V_166 = F_105 ( true , NULL ) ;
if ( V_160 -> V_166 == NULL )
return - V_8 ;
V_158 -> V_167 = true ;
F_106 ( V_85 , F_100 , ( void * ) V_158 , & V_75 ) ;
if ( ! V_158 -> V_171 )
goto V_172;
V_158 -> V_167 = false ;
F_106 ( & V_82 -> V_87 , F_100 , ( void * ) V_158 , & V_75 ) ;
V_172:
if ( F_107 ( V_160 -> V_166 ) ) {
F_108 ( V_160 -> V_166 ) ;
V_160 -> V_166 = NULL ;
}
return V_42 ;
}
int F_109 ( struct V_9 * V_10 ,
struct V_156 * V_113 ,
struct V_159 * * V_162 ,
int V_170 , bool V_171 )
{
struct V_157 V_158 = {
. V_82 = { . V_113 = V_113 , . V_104 = F_104 } ,
. V_16 = V_10 -> V_16 ,
. V_170 = V_170 , . V_171 = V_171 } ;
int V_42 ;
* V_162 = F_4 ( sizeof( struct V_159 ) * V_170 ) ;
if ( * V_162 == NULL )
return - V_8 ;
V_158 . V_162 = * V_162 ;
V_158 . V_163 = 0 ;
V_42 = F_92 ( V_10 , & V_158 . V_82 ) ;
if ( V_42 < 0 ) {
while ( V_158 . V_163 -- ) {
if ( V_158 . V_162 [ V_158 . V_163 ] . V_114 . V_96 )
free ( V_158 . V_162 [ V_158 . V_163 ] . V_114 . V_96 ) ;
if ( V_158 . V_162 [ V_158 . V_163 ] . V_166 )
F_108 ( V_158 . V_162 [ V_158 . V_163 ] . V_166 ) ;
}
free ( V_158 . V_162 ) ;
* V_162 = NULL ;
return V_42 ;
}
return ( V_42 < 0 ) ? V_42 : V_158 . V_163 ;
}
int F_110 ( struct V_9 * V_10 , unsigned long V_25 ,
struct V_128 * V_173 )
{
T_4 V_174 , V_175 , V_176 ;
T_2 V_177 = 0 , V_178 = 0 ;
const char * V_115 = NULL , * V_179 = NULL , * V_180 = NULL , * V_181 ;
int V_182 = 0 , V_117 = 0 , V_42 = 0 ;
V_25 += V_10 -> V_18 ;
if ( ! F_111 ( V_10 -> V_17 , ( T_2 ) V_25 - V_10 -> V_18 , & V_174 ) ) {
F_40 ( L_68 ,
V_25 ) ;
V_42 = - V_27 ;
goto V_183;
}
F_112 ( & V_174 , V_25 , & V_115 , & V_117 ) ;
if ( F_66 ( & V_174 , ( T_2 ) V_25 , & V_175 ) ) {
V_179 = V_180 = F_38 ( & V_175 ) ;
if ( ! V_179 ||
F_61 ( & V_175 , & V_178 ) != 0 ||
F_72 ( & V_175 , & V_182 ) != 0 ) {
V_117 = 0 ;
goto V_184;
}
V_115 = F_71 ( & V_175 ) ;
if ( V_25 == ( unsigned long ) V_178 ) {
V_117 = V_182 ;
goto V_184;
}
while ( F_113 ( & V_175 , ( T_2 ) V_25 ,
& V_176 ) ) {
if ( F_61 ( & V_176 , & V_177 ) == 0 &&
V_177 == V_25 ) {
V_117 = F_114 ( & V_176 ) ;
V_115 = F_115 ( & V_176 ) ;
break;
} else {
V_181 = F_38 ( & V_176 ) ;
if ( ! V_181 ||
F_72 ( & V_176 , & V_182 ) != 0 )
break;
V_179 = V_181 ;
V_175 = V_176 ;
}
}
V_181 = F_71 ( & V_175 ) ;
if ( ! V_181 || strcmp ( V_181 , V_115 ) != 0 )
V_117 = 0 ;
}
V_184:
if ( V_117 )
V_173 -> line = V_117 - V_182 ;
else if ( V_180 ) {
V_173 -> V_32 = V_25 - ( unsigned long ) V_178 ;
V_179 = V_180 ;
}
if ( V_179 ) {
V_173 -> V_111 = F_24 ( V_179 ) ;
if ( V_173 -> V_111 == NULL ) {
V_42 = - V_8 ;
goto V_183;
}
}
if ( V_115 ) {
V_173 -> V_109 = F_24 ( V_115 ) ;
if ( V_173 -> V_109 == NULL ) {
if ( V_173 -> V_111 ) {
free ( V_173 -> V_111 ) ;
V_173 -> V_111 = NULL ;
}
V_42 = - V_8 ;
goto V_183;
}
}
V_183:
if ( V_42 == 0 && ( V_115 || V_179 ) )
V_42 = 1 ;
return V_42 ;
}
static int F_116 ( const char * V_185 , unsigned int V_117 ,
struct V_186 * V_187 )
{
if ( ! V_187 -> V_11 ) {
V_187 -> V_11 = F_24 ( V_185 ) ;
if ( V_187 -> V_11 == NULL )
return - V_8 ;
}
return F_1 ( & V_187 -> V_188 , V_117 ) ;
}
static int F_117 ( const char * V_115 , int V_117 ,
T_2 V_25 V_28 ,
void * V_106 )
{
struct V_189 * V_190 = V_106 ;
if ( ( F_76 ( V_115 , V_190 -> V_115 ) != 0 ) ||
( V_190 -> V_191 > V_117 || V_190 -> V_192 < V_117 ) )
return 0 ;
if ( F_116 ( V_115 , V_117 , V_190 -> V_187 ) < 0 )
return - V_27 ;
return 0 ;
}
static int F_118 ( T_4 * V_88 , struct V_189 * V_190 )
{
int V_42 ;
V_42 = F_78 ( V_88 ? : & V_190 -> V_87 , F_117 , V_190 ) ;
if ( V_42 >= 0 )
if ( ! F_11 ( & V_190 -> V_187 -> V_188 ) )
V_42 = V_190 -> V_7 = 1 ;
else
V_42 = 0 ;
else {
free ( V_190 -> V_187 -> V_11 ) ;
V_190 -> V_187 -> V_11 = NULL ;
}
return V_42 ;
}
static int F_119 ( T_4 * V_127 , void * V_106 )
{
F_118 ( V_127 , V_106 ) ;
return 0 ;
}
static int F_120 ( T_4 * V_88 , void * V_106 )
{
struct V_130 * V_131 = V_106 ;
struct V_189 * V_190 = V_131 -> V_106 ;
struct V_186 * V_187 = V_190 -> V_187 ;
if ( V_187 -> V_109 && F_76 ( V_187 -> V_109 , F_71 ( V_88 ) ) )
return V_132 ;
if ( F_65 ( V_88 ) &&
F_48 ( V_88 , V_187 -> V_111 ) ) {
V_190 -> V_115 = F_71 ( V_88 ) ;
F_72 ( V_88 , & V_187 -> V_32 ) ;
F_3 ( L_69 , V_190 -> V_115 , V_187 -> V_32 ) ;
V_190 -> V_191 = V_187 -> V_32 + V_187 -> V_193 ;
if ( V_190 -> V_191 < 0 )
V_190 -> V_191 = V_116 ;
V_190 -> V_192 = V_187 -> V_32 + V_187 -> V_183 ;
if ( V_190 -> V_192 < 0 )
V_190 -> V_192 = V_116 ;
F_3 ( L_70 , V_190 -> V_191 , V_190 -> V_192 ) ;
V_187 -> V_193 = V_190 -> V_191 ;
V_187 -> V_183 = V_190 -> V_192 ;
if ( F_86 ( V_88 ) )
V_131 -> V_133 = F_87 ( V_88 ,
F_119 , V_190 ) ;
else
V_131 -> V_133 = F_118 ( V_88 , V_190 ) ;
return V_134 ;
}
return V_132 ;
}
static int F_121 ( struct V_189 * V_190 )
{
struct V_130 V_131 = { . V_106 = ( void * ) V_190 , . V_133 = 0 } ;
F_89 ( & V_190 -> V_87 , F_120 , & V_131 , 0 ) ;
return V_131 . V_133 ;
}
int F_122 ( struct V_9 * V_10 , struct V_186 * V_187 )
{
struct V_189 V_190 = { . V_187 = V_187 , . V_7 = 0 } ;
int V_42 = 0 ;
T_15 V_141 = 0 , V_142 ;
T_7 V_143 ;
T_4 * V_144 ;
const char * V_194 ;
if ( V_187 -> V_111 ) {
struct V_137 V_145 = {
. V_111 = V_187 -> V_111 , . V_109 = V_187 -> V_109 ,
. V_87 = & V_190 . V_87 , . V_88 = & V_190 . V_88 , . V_7 = 0 } ;
struct V_130 V_195 = {
. V_106 = ( void * ) & V_190 , . V_133 = 0 } ;
F_94 ( V_10 -> V_17 , F_90 ,
& V_145 , 0 ) ;
if ( V_145 . V_7 ) {
F_120 ( & V_190 . V_88 , & V_195 ) ;
if ( V_190 . V_7 )
goto V_7;
}
}
while ( ! V_190 . V_7 && V_42 >= 0 ) {
if ( F_95 ( V_10 -> V_17 , V_141 , & V_142 , & V_143 ,
NULL , NULL , NULL ) != 0 )
break;
V_144 = F_91 ( V_10 -> V_17 , V_141 + V_143 , & V_190 . V_87 ) ;
if ( ! V_144 )
continue;
if ( V_187 -> V_109 )
V_190 . V_115 = F_96 ( & V_190 . V_87 , V_187 -> V_109 ) ;
else
V_190 . V_115 = 0 ;
if ( ! V_187 -> V_109 || V_190 . V_115 ) {
if ( V_187 -> V_111 )
V_42 = F_121 ( & V_190 ) ;
else {
V_190 . V_191 = V_187 -> V_193 ;
V_190 . V_192 = V_187 -> V_183 ;
V_42 = F_118 ( NULL , & V_190 ) ;
}
}
V_141 = V_142 ;
}
V_7:
if ( V_190 . V_7 ) {
V_194 = F_123 ( & V_190 . V_87 ) ;
if ( V_194 ) {
V_187 -> V_194 = F_24 ( V_194 ) ;
if ( ! V_187 -> V_194 )
V_42 = - V_8 ;
}
}
F_3 ( L_71 , V_187 -> V_11 ) ;
return ( V_42 < 0 ) ? V_42 : V_190 . V_7 ;
}
