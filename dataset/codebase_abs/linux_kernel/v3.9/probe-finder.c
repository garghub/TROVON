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
static int F_60 ( T_4 * V_88 , T_2 V_89 ,
bool V_90 , struct V_91 * V_92 )
{
T_2 V_93 , V_94 ;
const char * V_77 ;
V_77 = F_38 ( V_88 ) ;
if ( V_77 ) {
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
V_92 -> V_95 = F_24 ( V_77 ) ;
if ( V_92 -> V_95 == NULL )
return - V_8 ;
V_92 -> V_32 = ( unsigned long ) ( V_89 - V_93 ) ;
} else
V_92 -> V_32 = ( unsigned long ) V_89 ;
if ( V_90 ) {
if ( V_93 != V_89 ) {
F_40 ( L_49
L_50 ) ;
return - V_27 ;
}
V_92 -> V_90 = true ;
}
return 0 ;
}
static int F_63 ( T_4 * V_85 , struct V_81 * V_82 )
{
T_6 V_96 ;
T_7 V_39 ;
int V_42 ;
if ( ! V_85 ) {
F_30 ( L_51 ) ;
return - V_27 ;
}
if ( F_47 ( V_85 ) != V_97 ) {
if ( ! F_64 ( & V_82 -> V_87 , V_82 -> V_25 , & V_82 -> V_88 ) ) {
F_40 ( L_52
L_53 ) ;
return - V_19 ;
}
} else
memcpy ( & V_82 -> V_88 , V_85 , sizeof( T_4 ) ) ;
F_36 ( & V_82 -> V_88 , V_98 , & V_96 ) ;
V_42 = F_37 ( & V_96 , V_82 -> V_25 , & V_82 -> V_34 , & V_39 , 1 ) ;
if ( V_42 <= 0 || V_39 == 0 ) {
V_82 -> V_34 = NULL ;
#if F_65 ( 0 , 142 )
} else if ( V_39 == 1 && V_82 -> V_34 [ 0 ] . V_46 == V_99 &&
V_82 -> V_100 != NULL ) {
T_9 * V_101 ;
if ( F_66 ( V_82 -> V_100 , V_82 -> V_25 , & V_101 ) != 0 ||
F_67 ( V_101 , & V_82 -> V_34 , & V_39 ) != 0 ) {
F_40 ( L_54 ,
( V_102 ) V_82 -> V_25 ) ;
return - V_19 ;
}
#endif
}
V_42 = V_82 -> V_103 ( V_85 , V_82 ) ;
V_82 -> V_34 = NULL ;
return V_42 ;
}
static int F_68 ( T_4 * V_104 , void * V_105 )
{
struct V_106 * V_107 = V_105 ;
const char * V_108 ;
int V_109 ;
if ( V_107 -> V_108 ) {
V_108 = F_69 ( V_104 ) ;
if ( ! V_108 || strcmp ( V_107 -> V_108 , V_108 ) != 0 )
return 0 ;
}
if ( V_107 -> V_110 ) {
if ( F_48 ( V_104 , V_107 -> V_110 ) ) {
memcpy ( V_107 -> V_75 , V_104 , sizeof( T_4 ) ) ;
V_107 -> V_7 = true ;
return 1 ;
}
} else {
F_70 ( V_104 , & V_109 ) ;
if ( V_109 < V_107 -> line && V_107 -> V_111 > V_107 -> line - V_109 ) {
V_107 -> V_111 = V_107 -> line - V_109 ;
memcpy ( V_107 -> V_75 , V_104 , sizeof( T_4 ) ) ;
V_107 -> V_7 = true ;
}
}
return 0 ;
}
static T_4 * F_71 ( struct V_81 * V_82 , T_4 * V_75 )
{
struct V_106 V_107 = {
. V_110 = V_82 -> V_112 -> V_113 . V_110 ,
. V_108 = V_82 -> V_114 ,
. line = V_82 -> V_109 ,
. V_111 = V_115 ,
. V_75 = V_75 ,
. V_7 = false ,
} ;
F_72 ( & V_82 -> V_87 , V_82 -> V_25 , F_68 , & V_107 ) ;
return V_107 . V_7 ? V_75 : NULL ;
}
static int F_73 ( const char * V_114 , int V_116 ,
T_2 V_25 , void * V_105 )
{
struct V_81 * V_82 = V_105 ;
T_4 * V_85 , V_75 ;
int V_42 ;
if ( V_116 != V_82 -> V_109 || F_74 ( V_114 , V_82 -> V_114 ) != 0 )
return 0 ;
V_82 -> V_25 = V_25 ;
V_85 = F_71 ( V_82 , & V_75 ) ;
if ( ! V_85 ) {
F_40 ( L_55 ) ;
return - V_19 ;
}
V_42 = F_63 ( V_85 , V_82 ) ;
return V_42 < 0 ? V_42 : 0 ;
}
static int F_75 ( struct V_81 * V_82 )
{
return F_76 ( & V_82 -> V_87 , F_73 , V_82 ) ;
}
static int F_77 ( struct V_1 * V_2 ,
const char * V_114 , const char * V_117 )
{
T_10 * V_118 ;
char * line = NULL ;
T_7 V_119 ;
T_11 V_120 ;
int V_121 = 0 , V_122 = 1 ;
V_118 = fopen ( V_114 , L_56 ) ;
if ( ! V_118 ) {
F_40 ( L_57 , V_114 , strerror ( V_123 ) ) ;
return - V_123 ;
}
while ( ( V_120 = F_78 ( & line , & V_119 , V_118 ) ) > 0 ) {
if ( line [ V_120 - 1 ] == '\n' )
line [ V_120 - 1 ] = '\0' ;
if ( F_79 ( line , V_117 ) ) {
F_1 ( V_2 , V_122 ) ;
V_121 ++ ;
}
V_122 ++ ;
}
if ( ferror ( V_118 ) )
V_121 = - V_123 ;
free ( line ) ;
fclose ( V_118 ) ;
if ( V_121 == 0 )
F_3 ( L_58 , V_114 ) ;
return V_121 ;
}
static int F_80 ( const char * V_114 , int V_116 ,
T_2 V_25 , void * V_105 )
{
struct V_81 * V_82 = V_105 ;
T_4 * V_85 , V_75 ;
int V_42 ;
if ( ! F_7 ( & V_82 -> V_124 , V_116 ) ||
F_74 ( V_114 , V_82 -> V_114 ) != 0 )
return 0 ;
F_3 ( L_59 ,
V_116 , ( unsigned long long ) V_25 ) ;
V_82 -> V_25 = V_25 ;
V_82 -> V_109 = V_116 ;
V_85 = F_71 ( V_82 , & V_75 ) ;
if ( ! V_85 ) {
F_40 ( L_55 ) ;
return - V_19 ;
}
V_42 = F_63 ( V_85 , V_82 ) ;
return V_42 < 0 ? V_42 : 0 ;
}
static int F_81 ( T_4 * V_88 , struct V_81 * V_82 )
{
int V_42 = 0 ;
if ( F_11 ( & V_82 -> V_124 ) ) {
V_42 = F_77 ( & V_82 -> V_124 , V_82 -> V_114 ,
V_82 -> V_112 -> V_113 . V_125 ) ;
if ( V_42 <= 0 )
return V_42 ;
}
return F_76 ( V_88 , F_80 , V_82 ) ;
}
static int F_82 ( T_4 * V_126 , void * V_105 )
{
struct V_81 * V_82 = V_105 ;
struct V_127 * V_128 = & V_82 -> V_112 -> V_113 ;
T_2 V_25 ;
int V_42 ;
if ( V_128 -> V_125 )
V_42 = F_81 ( V_126 , V_82 ) ;
else {
if ( F_61 ( V_126 , & V_25 ) != 0 ) {
F_40 ( L_60 ,
F_38 ( V_126 ) ) ;
return - V_19 ;
}
V_82 -> V_25 = V_25 ;
V_82 -> V_25 += V_128 -> V_32 ;
F_3 ( L_61 ,
( V_102 ) V_82 -> V_25 ) ;
V_42 = F_63 ( V_126 , V_82 ) ;
}
return V_42 ;
}
static int F_83 ( T_4 * V_88 , void * V_105 )
{
struct V_129 * V_130 = V_105 ;
struct V_81 * V_82 = V_130 -> V_105 ;
struct V_127 * V_128 = & V_82 -> V_112 -> V_113 ;
T_6 V_37 ;
if ( F_47 ( V_88 ) != V_97 ||
! F_48 ( V_88 , V_128 -> V_110 ) ||
F_36 ( V_88 , V_131 , & V_37 ) )
return V_132 ;
if ( V_128 -> V_108 && F_74 ( V_128 -> V_108 , F_69 ( V_88 ) ) )
return V_132 ;
V_82 -> V_114 = F_69 ( V_88 ) ;
if ( V_128 -> line ) {
F_70 ( V_88 , & V_82 -> V_109 ) ;
V_82 -> V_109 += V_128 -> line ;
V_130 -> V_133 = F_75 ( V_82 ) ;
} else if ( ! F_84 ( V_88 ) ) {
if ( V_128 -> V_125 )
V_130 -> V_133 = F_81 ( V_88 , V_82 ) ;
else {
if ( F_61 ( V_88 , & V_82 -> V_25 ) != 0 ) {
F_40 ( L_62
L_63 , F_38 ( V_88 ) ) ;
V_130 -> V_133 = - V_19 ;
return V_134 ;
}
V_82 -> V_25 += V_128 -> V_32 ;
V_130 -> V_133 = F_63 ( V_88 , V_82 ) ;
}
} else
V_130 -> V_133 = F_85 ( V_88 ,
F_82 , ( void * ) V_82 ) ;
return V_134 ;
}
static int F_86 ( struct V_81 * V_82 )
{
struct V_129 V_135 = { . V_105 = ( void * ) V_82 ,
. V_133 = 0 } ;
F_87 ( & V_82 -> V_87 , F_83 , & V_135 , 0 ) ;
return V_135 . V_133 ;
}
static int F_88 ( T_12 * V_17 , T_13 * V_136 , void * V_105 )
{
struct V_137 * V_130 = V_105 ;
if ( F_89 ( V_17 , V_136 -> V_138 , V_130 -> V_88 ) ) {
if ( F_47 ( V_130 -> V_88 ) != V_97 )
return V_132 ;
if ( F_48 ( V_130 -> V_88 , V_130 -> V_110 ) ) {
if ( ! F_89 ( V_17 , V_136 -> V_139 , V_130 -> V_87 ) )
return V_132 ;
if ( V_130 -> V_108 &&
F_74 ( V_130 -> V_108 , F_69 ( V_130 -> V_88 ) ) )
return V_132 ;
V_130 -> V_7 = 1 ;
return V_134 ;
}
}
return V_132 ;
}
static int F_90 ( struct V_9 * V_10 ,
struct V_81 * V_82 )
{
struct V_127 * V_128 = & V_82 -> V_112 -> V_113 ;
T_14 V_140 , V_141 ;
T_7 V_142 ;
T_4 * V_143 ;
int V_42 = 0 ;
#if F_65 ( 0 , 142 )
V_82 -> V_100 = F_91 ( V_10 -> V_17 ) ;
#endif
V_140 = 0 ;
F_9 ( & V_82 -> V_124 ) ;
if ( V_128 -> V_110 ) {
struct V_137 V_144 = {
. V_110 = V_128 -> V_110 ,
. V_108 = V_128 -> V_108 ,
. V_87 = & V_82 -> V_87 ,
. V_88 = & V_82 -> V_88 ,
. V_7 = 0 ,
} ;
struct V_129 V_145 = {
. V_105 = V_82 ,
} ;
F_92 ( V_10 -> V_17 , F_88 ,
& V_144 , 0 ) ;
if ( V_144 . V_7 ) {
V_42 = F_83 ( & V_82 -> V_88 , & V_145 ) ;
if ( V_42 )
goto V_7;
}
}
while ( ! F_93 ( V_10 -> V_17 , V_140 , & V_141 , & V_142 , NULL , NULL , NULL ) ) {
V_143 = F_89 ( V_10 -> V_17 , V_140 + V_142 , & V_82 -> V_87 ) ;
if ( ! V_143 )
continue;
if ( V_128 -> V_108 )
V_82 -> V_114 = F_94 ( & V_82 -> V_87 , V_128 -> V_108 ) ;
else
V_82 -> V_114 = NULL ;
if ( ! V_128 -> V_108 || V_82 -> V_114 ) {
if ( V_128 -> V_110 )
V_42 = F_86 ( V_82 ) ;
else if ( V_128 -> V_125 )
V_42 = F_81 ( NULL , V_82 ) ;
else {
V_82 -> V_109 = V_128 -> line ;
V_42 = F_75 ( V_82 ) ;
}
if ( V_42 < 0 )
break;
}
V_140 = V_141 ;
}
V_7:
F_10 ( & V_82 -> V_124 ) ;
return V_42 ;
}
static int F_95 ( T_4 * V_85 , struct V_81 * V_82 )
{
struct V_146 * V_147 =
F_96 ( V_82 , struct V_146 , V_82 ) ;
struct V_148 * V_149 ;
int V_42 , V_150 ;
if ( V_147 -> V_151 == V_147 -> V_152 ) {
F_40 ( L_64 ,
V_147 -> V_152 ) ;
return - V_59 ;
}
V_149 = & V_147 -> V_153 [ V_147 -> V_151 ++ ] ;
V_42 = F_60 ( & V_82 -> V_88 , V_82 -> V_25 ,
V_82 -> V_112 -> V_113 . V_90 , & V_149 -> V_113 ) ;
if ( V_42 < 0 )
return V_42 ;
F_3 ( L_65 , V_149 -> V_113 . V_95 ,
V_149 -> V_113 . V_32 ) ;
V_149 -> V_154 = V_82 -> V_112 -> V_154 ;
V_149 -> args = F_4 ( sizeof( struct V_35 ) * V_149 -> V_154 ) ;
if ( V_149 -> args == NULL )
return - V_8 ;
for ( V_150 = 0 ; V_150 < V_82 -> V_112 -> V_154 ; V_150 ++ ) {
V_82 -> V_83 = & V_82 -> V_112 -> args [ V_150 ] ;
V_82 -> V_36 = & V_149 -> args [ V_150 ] ;
V_42 = F_56 ( V_85 , V_82 ) ;
if ( V_42 != 0 )
return V_42 ;
}
return 0 ;
}
int F_97 ( struct V_9 * V_10 ,
struct V_155 * V_112 ,
struct V_148 * * V_153 , int V_152 )
{
struct V_146 V_147 = {
. V_82 = { . V_112 = V_112 , . V_103 = F_95 } ,
. V_152 = V_152 } ;
int V_42 ;
* V_153 = F_4 ( sizeof( struct V_148 ) * V_152 ) ;
if ( * V_153 == NULL )
return - V_8 ;
V_147 . V_153 = * V_153 ;
V_147 . V_151 = 0 ;
V_42 = F_90 ( V_10 , & V_147 . V_82 ) ;
if ( V_42 < 0 ) {
free ( * V_153 ) ;
* V_153 = NULL ;
return V_42 ;
}
return ( V_42 < 0 ) ? V_42 : V_147 . V_151 ;
}
static int F_98 ( T_4 * V_75 , void * V_105 )
{
struct V_156 * V_157 = V_105 ;
struct V_158 * V_159 ;
char V_62 [ V_160 ] ;
int V_76 , V_42 ;
V_159 = & V_157 -> V_161 [ V_157 -> V_162 - 1 ] ;
V_76 = F_47 ( V_75 ) ;
if ( V_76 == V_163 ||
V_76 == V_164 ) {
V_42 = F_35 ( V_75 , V_157 -> V_82 . V_25 ,
V_157 -> V_82 . V_34 , NULL ) ;
if ( V_42 == 0 ) {
V_42 = F_99 ( V_75 , V_62 , V_160 ) ;
F_23 ( L_66 , V_62 ) ;
if ( V_42 > 0 )
F_100 ( V_159 -> V_165 , V_62 ) ;
}
}
if ( V_157 -> V_166 && F_101 ( V_75 , V_157 -> V_82 . V_25 ) )
return V_167 ;
else
return V_168 ;
}
static int F_102 ( T_4 * V_85 , struct V_81 * V_82 )
{
struct V_156 * V_157 =
F_96 ( V_82 , struct V_156 , V_82 ) ;
struct V_158 * V_159 ;
T_4 V_75 ;
int V_42 ;
if ( V_157 -> V_162 == V_157 -> V_169 ) {
F_40 ( L_64 , V_157 -> V_169 ) ;
return - V_59 ;
}
V_159 = & V_157 -> V_161 [ V_157 -> V_162 ++ ] ;
V_42 = F_60 ( & V_82 -> V_88 , V_82 -> V_25 ,
V_82 -> V_112 -> V_113 . V_90 , & V_159 -> V_113 ) ;
if ( V_42 < 0 )
return V_42 ;
F_3 ( L_65 , V_159 -> V_113 . V_95 ,
V_159 -> V_113 . V_32 ) ;
V_159 -> V_165 = F_103 ( true , NULL ) ;
if ( V_159 -> V_165 == NULL )
return - V_8 ;
V_157 -> V_166 = true ;
F_104 ( V_85 , F_98 , ( void * ) V_157 , & V_75 ) ;
if ( ! V_157 -> V_170 )
goto V_171;
V_157 -> V_166 = false ;
F_104 ( & V_82 -> V_87 , F_98 , ( void * ) V_157 , & V_75 ) ;
V_171:
if ( F_105 ( V_159 -> V_165 ) ) {
F_106 ( V_159 -> V_165 ) ;
V_159 -> V_165 = NULL ;
}
return V_42 ;
}
int F_107 ( struct V_9 * V_10 ,
struct V_155 * V_112 ,
struct V_158 * * V_161 ,
int V_169 , bool V_170 )
{
struct V_156 V_157 = {
. V_82 = { . V_112 = V_112 , . V_103 = F_102 } ,
. V_169 = V_169 , . V_170 = V_170 } ;
int V_42 ;
* V_161 = F_4 ( sizeof( struct V_158 ) * V_169 ) ;
if ( * V_161 == NULL )
return - V_8 ;
V_157 . V_161 = * V_161 ;
V_157 . V_162 = 0 ;
V_42 = F_90 ( V_10 , & V_157 . V_82 ) ;
if ( V_42 < 0 ) {
while ( V_157 . V_162 -- ) {
if ( V_157 . V_161 [ V_157 . V_162 ] . V_113 . V_95 )
free ( V_157 . V_161 [ V_157 . V_162 ] . V_113 . V_95 ) ;
if ( V_157 . V_161 [ V_157 . V_162 ] . V_165 )
F_106 ( V_157 . V_161 [ V_157 . V_162 ] . V_165 ) ;
}
free ( V_157 . V_161 ) ;
* V_161 = NULL ;
return V_42 ;
}
return ( V_42 < 0 ) ? V_42 : V_157 . V_162 ;
}
int F_108 ( struct V_9 * V_10 , unsigned long V_25 ,
struct V_127 * V_172 )
{
T_4 V_173 , V_174 , V_175 ;
T_2 V_176 , V_177 ;
const char * V_114 = NULL , * V_178 = NULL , * V_179 ;
int V_180 = 0 , V_116 = 0 , V_42 = 0 ;
V_25 += V_10 -> V_18 ;
if ( ! F_109 ( V_10 -> V_17 , ( T_2 ) V_25 - V_10 -> V_18 , & V_173 ) ) {
F_40 ( L_67 ,
V_25 ) ;
V_42 = - V_27 ;
goto V_181;
}
F_110 ( & V_173 , V_25 , & V_114 , & V_116 ) ;
if ( F_64 ( & V_173 , ( T_2 ) V_25 , & V_174 ) ) {
V_179 = F_38 ( & V_174 ) ;
if ( ! V_179 ||
F_61 ( & V_174 , & V_177 ) != 0 ||
F_70 ( & V_174 , & V_180 ) != 0 )
goto V_182;
V_178 = V_179 ;
if ( V_25 == ( unsigned long ) V_177 )
V_116 = V_180 ;
else if ( F_111 ( & V_174 , ( T_2 ) V_25 ,
& V_175 ) ) {
if ( F_61 ( & V_175 , & V_176 ) == 0 &&
V_176 == V_25 )
V_116 = F_112 ( & V_175 ) ;
else {
V_179 = F_38 ( & V_175 ) ;
if ( V_179 &&
F_70 ( & V_174 , & V_180 ) == 0 )
V_178 = V_179 ;
}
}
}
V_182:
if ( V_116 )
V_172 -> line = V_116 - V_180 ;
else if ( V_178 )
V_172 -> V_32 = V_25 - ( unsigned long ) V_177 ;
if ( V_178 ) {
V_172 -> V_110 = F_24 ( V_178 ) ;
if ( V_172 -> V_110 == NULL ) {
V_42 = - V_8 ;
goto V_181;
}
}
if ( V_114 ) {
V_172 -> V_108 = F_24 ( V_114 ) ;
if ( V_172 -> V_108 == NULL ) {
if ( V_172 -> V_110 ) {
free ( V_172 -> V_110 ) ;
V_172 -> V_110 = NULL ;
}
V_42 = - V_8 ;
goto V_181;
}
}
V_181:
if ( V_42 == 0 && ( V_114 || V_178 ) )
V_42 = 1 ;
return V_42 ;
}
static int F_113 ( const char * V_183 , unsigned int V_116 ,
struct V_184 * V_185 )
{
if ( ! V_185 -> V_11 ) {
V_185 -> V_11 = F_24 ( V_183 ) ;
if ( V_185 -> V_11 == NULL )
return - V_8 ;
}
return F_1 ( & V_185 -> V_186 , V_116 ) ;
}
static int F_114 ( const char * V_114 , int V_116 ,
T_2 V_25 V_28 ,
void * V_105 )
{
struct V_187 * V_188 = V_105 ;
if ( ( F_74 ( V_114 , V_188 -> V_114 ) != 0 ) ||
( V_188 -> V_189 > V_116 || V_188 -> V_190 < V_116 ) )
return 0 ;
if ( F_113 ( V_114 , V_116 , V_188 -> V_185 ) < 0 )
return - V_27 ;
return 0 ;
}
static int F_115 ( T_4 * V_88 , struct V_187 * V_188 )
{
int V_42 ;
V_42 = F_76 ( V_88 ? : & V_188 -> V_87 , F_114 , V_188 ) ;
if ( V_42 >= 0 )
if ( ! F_11 ( & V_188 -> V_185 -> V_186 ) )
V_42 = V_188 -> V_7 = 1 ;
else
V_42 = 0 ;
else {
free ( V_188 -> V_185 -> V_11 ) ;
V_188 -> V_185 -> V_11 = NULL ;
}
return V_42 ;
}
static int F_116 ( T_4 * V_126 , void * V_105 )
{
F_115 ( V_126 , V_105 ) ;
return 0 ;
}
static int F_117 ( T_4 * V_88 , void * V_105 )
{
struct V_129 * V_130 = V_105 ;
struct V_187 * V_188 = V_130 -> V_105 ;
struct V_184 * V_185 = V_188 -> V_185 ;
if ( V_185 -> V_108 && F_74 ( V_185 -> V_108 , F_69 ( V_88 ) ) )
return V_132 ;
if ( F_47 ( V_88 ) == V_97 &&
F_48 ( V_88 , V_185 -> V_110 ) ) {
V_188 -> V_114 = F_69 ( V_88 ) ;
F_70 ( V_88 , & V_185 -> V_32 ) ;
F_3 ( L_68 , V_188 -> V_114 , V_185 -> V_32 ) ;
V_188 -> V_189 = V_185 -> V_32 + V_185 -> V_191 ;
if ( V_188 -> V_189 < 0 )
V_188 -> V_189 = V_115 ;
V_188 -> V_190 = V_185 -> V_32 + V_185 -> V_181 ;
if ( V_188 -> V_190 < 0 )
V_188 -> V_190 = V_115 ;
F_3 ( L_69 , V_188 -> V_189 , V_188 -> V_190 ) ;
V_185 -> V_191 = V_188 -> V_189 ;
V_185 -> V_181 = V_188 -> V_190 ;
if ( F_84 ( V_88 ) )
V_130 -> V_133 = F_85 ( V_88 ,
F_116 , V_188 ) ;
else
V_130 -> V_133 = F_115 ( V_88 , V_188 ) ;
return V_134 ;
}
return V_132 ;
}
static int F_118 ( struct V_187 * V_188 )
{
struct V_129 V_130 = { . V_105 = ( void * ) V_188 , . V_133 = 0 } ;
F_87 ( & V_188 -> V_87 , F_117 , & V_130 , 0 ) ;
return V_130 . V_133 ;
}
int F_119 ( struct V_9 * V_10 , struct V_184 * V_185 )
{
struct V_187 V_188 = { . V_185 = V_185 , . V_7 = 0 } ;
int V_42 = 0 ;
T_14 V_140 = 0 , V_141 ;
T_7 V_142 ;
T_4 * V_143 ;
const char * V_192 ;
if ( V_185 -> V_110 ) {
struct V_137 V_144 = {
. V_110 = V_185 -> V_110 , . V_108 = V_185 -> V_108 ,
. V_87 = & V_188 . V_87 , . V_88 = & V_188 . V_88 , . V_7 = 0 } ;
struct V_129 V_193 = {
. V_105 = ( void * ) & V_188 , . V_133 = 0 } ;
F_92 ( V_10 -> V_17 , F_88 ,
& V_144 , 0 ) ;
if ( V_144 . V_7 ) {
F_117 ( & V_188 . V_88 , & V_193 ) ;
if ( V_188 . V_7 )
goto V_7;
}
}
while ( ! V_188 . V_7 && V_42 >= 0 ) {
if ( F_93 ( V_10 -> V_17 , V_140 , & V_141 , & V_142 ,
NULL , NULL , NULL ) != 0 )
break;
V_143 = F_89 ( V_10 -> V_17 , V_140 + V_142 , & V_188 . V_87 ) ;
if ( ! V_143 )
continue;
if ( V_185 -> V_108 )
V_188 . V_114 = F_94 ( & V_188 . V_87 , V_185 -> V_108 ) ;
else
V_188 . V_114 = 0 ;
if ( ! V_185 -> V_108 || V_188 . V_114 ) {
if ( V_185 -> V_110 )
V_42 = F_118 ( & V_188 ) ;
else {
V_188 . V_189 = V_185 -> V_191 ;
V_188 . V_190 = V_185 -> V_181 ;
V_42 = F_115 ( NULL , & V_188 ) ;
}
}
V_140 = V_141 ;
}
V_7:
if ( V_188 . V_7 ) {
V_192 = F_120 ( & V_188 . V_87 ) ;
if ( V_192 ) {
V_185 -> V_192 = F_24 ( V_192 ) ;
if ( ! V_185 -> V_192 )
V_42 = - V_8 ;
}
}
F_3 ( L_70 , V_185 -> V_11 ) ;
return ( V_42 < 0 ) ? V_42 : V_188 . V_7 ;
}
