const char * F_1 ( T_1 * V_1 , const char * V_2 )
{
T_2 * V_3 ;
T_3 V_4 , V_5 ;
const char * V_6 = NULL ;
int V_7 ;
if ( ! V_2 )
return NULL ;
V_7 = F_2 ( V_1 , & V_3 , & V_4 ) ;
if ( V_7 != 0 )
return NULL ;
for ( V_5 = 0 ; V_5 < V_4 ; V_5 ++ ) {
V_6 = F_3 ( V_3 , V_5 , NULL , NULL ) ;
if ( F_4 ( V_6 , V_2 ) == 0 )
break;
}
if ( V_5 == V_4 )
return NULL ;
return V_6 ;
}
const char * F_5 ( T_1 * V_1 )
{
T_4 V_8 ;
if ( F_6 ( V_1 , V_9 , & V_8 ) == NULL )
return NULL ;
return F_7 ( & V_8 ) ;
}
int F_8 ( T_1 * V_1 , unsigned long V_10 ,
const char * * V_2 , int * V_11 )
{
T_5 * line ;
T_6 V_12 ;
line = F_9 ( V_1 , ( T_6 ) V_10 ) ;
if ( line && F_10 ( line , & V_12 ) == 0 &&
V_10 == ( unsigned long ) V_12 && F_11 ( line , V_11 ) == 0 ) {
* V_2 = F_12 ( line , NULL , NULL ) ;
if ( ! * V_2 )
* V_11 = 0 ;
}
return * V_11 ? : - V_13 ;
}
int F_13 ( T_1 * V_1 , T_6 V_10 ,
int (* F_14)( T_1 * , void * ) , void * V_14 )
{
T_1 V_15 ;
T_1 * V_16 ;
int V_7 = - V_13 ;
for ( V_16 = F_15 ( V_1 , V_10 , & V_15 ) ;
V_16 != NULL ;
V_16 = F_16 ( V_16 , V_17 , & V_10 ,
& V_15 ) ) {
V_7 = F_14 ( V_16 , V_14 ) ;
if ( V_7 )
break;
}
return V_7 ;
}
bool F_17 ( T_1 * V_18 , const char * V_19 )
{
const char * V_20 ;
V_20 = F_18 ( V_18 ) ;
return V_20 ? ( strcmp ( V_19 , V_20 ) == 0 ) : false ;
}
bool F_19 ( T_1 * V_18 , const char * V_21 )
{
const char * V_20 ;
V_20 = F_18 ( V_18 ) ;
return V_20 ? F_20 ( V_20 , V_21 ) : false ;
}
int F_21 ( T_1 * V_22 )
{
T_4 V_8 ;
T_7 V_7 ;
if ( ! F_6 ( V_22 , V_23 , & V_8 ) )
return - V_13 ;
F_22 ( & V_8 , & V_7 ) ;
return ( int ) V_7 ;
}
T_1 * F_23 ( T_1 * V_24 , T_1 * V_15 )
{
T_4 V_8 ;
if ( F_24 ( V_24 , V_25 , & V_8 ) &&
F_25 ( & V_8 , V_15 ) )
return V_15 ;
else
return NULL ;
}
static T_1 * F_26 ( T_1 * V_24 , T_1 * V_15 )
{
int V_26 ;
do {
V_24 = F_23 ( V_24 , V_15 ) ;
if ( ! V_24 )
break;
V_26 = F_27 ( V_24 ) ;
} while ( V_26 == V_27 ||
V_26 == V_28 ||
V_26 == V_29 ||
V_26 == V_30 );
return V_24 ;
}
T_1 * F_28 ( T_1 * V_24 , T_1 * V_15 )
{
do {
V_24 = F_26 ( V_24 , V_15 ) ;
} while ( V_24 && F_27 ( V_24 ) == V_31 );
return V_24 ;
}
static int F_29 ( T_1 * V_32 , unsigned int V_33 ,
T_7 * V_34 )
{
T_4 V_8 ;
if ( F_6 ( V_32 , V_33 , & V_8 ) == NULL ||
F_22 ( & V_8 , V_34 ) != 0 )
return - V_13 ;
return 0 ;
}
static int F_30 ( T_1 * V_32 , unsigned int V_33 ,
T_8 * V_34 )
{
T_4 V_8 ;
if ( F_6 ( V_32 , V_33 , & V_8 ) == NULL ||
F_31 ( & V_8 , V_34 ) != 0 )
return - V_13 ;
return 0 ;
}
bool F_32 ( T_1 * V_32 )
{
T_7 V_7 ;
if ( F_29 ( V_32 , V_35 , & V_7 ) )
return false ;
return ( V_7 == V_36 || V_7 == V_37 ||
V_7 == V_38 ) ;
}
bool F_33 ( T_1 * V_18 )
{
T_4 V_8 ;
return ( F_27 ( V_18 ) == V_39 &&
F_6 ( V_18 , V_40 , & V_8 ) == NULL ) ;
}
bool F_34 ( T_1 * V_18 )
{
T_6 V_41 ;
return ! F_35 ( V_18 ) && F_36 ( V_18 , & V_41 ) == 0 ;
}
int F_37 ( T_1 * V_42 , T_7 * V_43 )
{
T_4 V_8 ;
T_9 * V_44 ;
T_3 V_45 ;
int V_7 ;
if ( F_6 ( V_42 , V_46 , & V_8 ) == NULL )
return - V_13 ;
if ( F_22 ( & V_8 , V_43 ) != 0 ) {
V_7 = F_38 ( & V_8 , & V_44 , & V_45 ) ;
if ( V_7 < 0 || V_45 == 0 )
return - V_13 ;
if ( V_44 [ 0 ] . V_47 != V_48 || V_45 != 1 ) {
F_39 ( L_1 ,
V_44 [ 0 ] . V_47 , V_45 ) ;
return - V_49 ;
}
* V_43 = ( T_7 ) V_44 [ 0 ] . V_50 ;
}
return 0 ;
}
static int F_40 ( T_1 * V_22 )
{
T_8 V_51 ;
if ( F_30 ( V_22 , V_52 , & V_51 ) == 0 )
return ( int ) V_51 ;
else
return - V_13 ;
}
static int F_41 ( T_1 * V_53 )
{
T_8 V_51 ;
if ( F_30 ( V_53 , V_54 , & V_51 ) == 0 )
return ( int ) V_51 ;
else
return - V_13 ;
}
const char * F_42 ( T_1 * V_22 )
{
T_1 V_1 ;
T_2 * V_3 ;
int V_51 ;
V_51 = F_40 ( V_22 ) ;
if ( V_51 < 0 || ! F_43 ( V_22 , & V_1 , NULL , NULL ) ||
F_2 ( & V_1 , & V_3 , NULL ) != 0 )
return NULL ;
return F_3 ( V_3 , V_51 , NULL , NULL ) ;
}
T_1 * F_16 ( T_1 * V_55 ,
int (* F_14)( T_1 * , void * ) ,
void * V_14 , T_1 * V_15 )
{
T_1 V_56 ;
int V_7 ;
V_7 = F_44 ( V_55 , V_15 ) ;
if ( V_7 != 0 )
return NULL ;
do {
V_7 = F_14 ( V_15 , V_14 ) ;
if ( V_7 == V_57 )
return V_15 ;
if ( ( V_7 & V_58 ) &&
F_16 ( V_15 , F_14 , V_14 , & V_56 ) ) {
memcpy ( V_15 , & V_56 , sizeof( T_1 ) ) ;
return V_15 ;
}
} while ( ( V_7 & V_59 ) &&
F_45 ( V_15 , V_15 ) == 0 );
return NULL ;
}
static int F_46 ( T_1 * V_60 , void * V_14 )
{
struct V_61 * V_62 = V_14 ;
T_6 V_10 = 0 ;
if ( F_27 ( V_60 ) == V_39 &&
! F_47 ( V_60 , & V_10 ) &&
V_10 == V_62 -> V_10 ) {
memcpy ( V_62 -> V_15 , V_60 , sizeof( T_1 ) ) ;
return V_63 ;
}
return V_64 ;
}
T_1 * F_48 ( T_1 * V_1 , T_6 V_10 ,
T_1 * V_15 )
{
struct V_61 V_62 ;
V_62 . V_10 = V_10 ;
V_62 . V_15 = V_15 ;
if ( ! F_49 ( V_1 , F_46 , & V_62 , 0 ) )
return NULL ;
else
return V_15 ;
}
static int F_50 ( T_1 * V_60 , void * V_14 )
{
struct V_61 * V_62 = V_14 ;
if ( F_27 ( V_60 ) == V_39 &&
F_51 ( V_60 , V_62 -> V_10 ) ) {
memcpy ( V_62 -> V_15 , V_60 , sizeof( T_1 ) ) ;
return V_63 ;
}
return V_64 ;
}
T_1 * F_15 ( T_1 * V_1 , T_6 V_10 ,
T_1 * V_15 )
{
struct V_61 V_62 ;
V_62 . V_10 = V_10 ;
V_62 . V_15 = V_15 ;
if ( ! F_49 ( V_1 , F_50 , & V_62 , 0 ) )
return NULL ;
else
return V_15 ;
}
static int V_17 ( T_1 * V_15 , void * V_14 )
{
T_6 * V_10 = V_14 ;
if ( F_27 ( V_15 ) == V_65 &&
F_51 ( V_15 , * V_10 ) )
return V_57 ;
return V_66 ;
}
T_1 * F_52 ( T_1 * V_67 , T_6 V_10 ,
T_1 * V_15 )
{
return F_16 ( V_67 , V_17 , & V_10 , V_15 ) ;
}
T_1 * F_53 ( T_1 * V_67 , T_6 V_10 ,
T_1 * V_15 )
{
T_1 V_68 ;
V_67 = F_16 ( V_67 , V_17 , & V_10 , & V_68 ) ;
if ( ! V_67 )
return NULL ;
while ( V_67 ) {
memcpy ( V_15 , V_67 , sizeof( T_1 ) ) ;
V_67 = F_16 ( V_67 , V_17 , & V_10 ,
& V_68 ) ;
}
return V_15 ;
}
static int F_54 ( T_1 * V_69 , void * V_14 )
{
struct V_70 * V_71 = V_14 ;
T_4 V_72 ;
T_1 V_73 ;
T_4 * V_8 ;
T_1 * V_74 ;
int V_41 ;
V_8 = F_6 ( V_69 , V_75 , & V_72 ) ;
if ( V_8 == NULL )
return V_66 ;
V_74 = F_25 ( V_8 , & V_73 ) ;
if ( V_74 == NULL || V_74 -> V_10 != V_71 -> V_10 )
return V_66 ;
if ( F_27 ( V_69 ) == V_65 ) {
F_55 ( V_74 , & V_41 ) ;
if ( F_21 ( V_69 ) == V_41 ) {
V_41 = F_41 ( V_74 ) ;
if ( F_40 ( V_69 ) == V_41 )
return V_66 ;
}
}
V_71 -> V_76 = V_71 -> F_14 ( V_69 , V_71 -> V_14 ) ;
return ( V_71 -> V_76 ) ? V_57 : V_66 ;
}
int F_56 ( T_1 * V_77 , int (* F_14)( T_1 * , void * ) ,
void * V_14 )
{
T_1 V_1 ;
T_1 V_15 ;
struct V_70 V_71 = {
. V_10 = V_77 -> V_10 ,
. F_14 = F_14 ,
. V_14 = V_14 ,
. V_76 = - V_13 ,
} ;
if ( F_43 ( V_77 , & V_1 , NULL , NULL ) == NULL )
return - V_13 ;
F_16 ( & V_1 , F_54 , & V_71 , & V_15 ) ;
return V_71 . V_76 ;
}
static int F_57 ( T_1 * V_22 , void * V_14 )
{
struct V_78 * V_79 = V_14 ;
T_6 V_10 = 0 ;
const char * V_2 ;
int V_11 ;
if ( F_27 ( V_22 ) == V_65 ) {
V_2 = F_42 ( V_22 ) ;
V_11 = F_21 ( V_22 ) ;
if ( V_2 && V_11 > 0 && F_36 ( V_22 , & V_10 ) == 0 ) {
V_79 -> V_76 = V_79 -> F_14 ( V_2 , V_11 , V_10 , V_79 -> V_14 ) ;
if ( V_79 -> V_76 != 0 )
return V_57 ;
}
}
if ( ! V_79 -> V_80 )
return V_59 ;
if ( V_10 ) {
V_2 = F_58 ( V_22 ) ;
if ( V_2 && F_55 ( V_22 , & V_11 ) == 0 ) {
V_79 -> V_76 = V_79 -> F_14 ( V_2 , V_11 , V_10 , V_79 -> V_14 ) ;
if ( V_79 -> V_76 != 0 )
return V_57 ;
}
}
return V_66 ;
}
static int F_59 ( T_1 * V_67 , bool V_80 ,
T_10 F_14 , void * V_14 )
{
struct V_78 V_79 = {
. V_80 = V_80 ,
. F_14 = F_14 ,
. V_14 = V_14 ,
. V_76 = 0 ,
} ;
T_1 V_15 ;
T_6 V_10 ;
const char * V_2 ;
int V_11 ;
V_2 = F_58 ( V_67 ) ;
if ( V_2 && F_55 ( V_67 , & V_11 ) == 0 &&
F_36 ( V_67 , & V_10 ) == 0 ) {
V_79 . V_76 = F_14 ( V_2 , V_11 , V_10 , V_14 ) ;
if ( V_79 . V_76 != 0 )
goto V_81;
}
F_16 ( V_67 , F_57 , & V_79 , & V_15 ) ;
V_81:
return V_79 . V_76 ;
}
static int F_60 ( T_1 * V_67 , void * V_14 )
{
struct V_78 * V_79 = V_14 ;
V_79 -> V_76 = F_59 ( V_67 , true , V_79 -> F_14 , V_79 -> V_14 ) ;
if ( V_79 -> V_76 != 0 )
return V_63 ;
return V_64 ;
}
int F_61 ( T_1 * V_55 , T_10 F_14 , void * V_14 )
{
T_11 * V_82 ;
T_5 * line ;
T_6 V_10 ;
const char * V_2 , * V_83 = NULL ;
int V_11 , V_7 = 0 ;
int V_84 = 0 , V_85 ;
T_1 V_15 , * V_1 ;
T_3 V_86 , V_5 ;
if ( F_27 ( V_55 ) != V_87 ) {
V_1 = F_43 ( V_55 , & V_15 , NULL , NULL ) ;
F_55 ( V_55 , & V_84 ) ;
V_83 = F_58 ( V_55 ) ;
} else
V_1 = V_55 ;
if ( ! V_1 ) {
F_62 ( L_2 ) ;
return - V_88 ;
}
if ( F_63 ( V_1 , & V_82 , & V_86 ) != 0 ) {
F_62 ( L_3 ) ;
return - V_13 ;
}
F_62 ( L_4 , V_86 ) ;
for ( V_5 = 0 ; V_5 < V_86 ; V_5 ++ ) {
line = F_64 ( V_82 , V_5 ) ;
if ( line == NULL ||
F_11 ( line , & V_11 ) != 0 ||
F_10 ( line , & V_10 ) != 0 ) {
F_62 ( L_5
L_6 ) ;
continue;
}
if ( V_55 != V_1 ) {
if ( ! F_51 ( V_55 , V_10 ) )
continue;
if ( F_53 ( V_55 , V_10 , & V_15 ) ) {
F_55 ( & V_15 , & V_85 ) ;
if ( V_85 != V_84 ||
V_83 != F_58 ( & V_15 ) )
continue;
}
}
V_2 = F_12 ( line , NULL , NULL ) ;
V_7 = F_14 ( V_2 , V_11 , V_10 , V_14 ) ;
if ( V_7 != 0 )
return V_7 ;
}
if ( V_55 != V_1 )
V_7 = F_59 ( V_55 , false , F_14 , V_14 ) ;
else {
struct V_78 V_89 = {
. F_14 = F_14 ,
. V_14 = V_14 ,
. V_76 = 0 ,
} ;
F_49 ( V_1 , F_60 , & V_89 , 0 ) ;
V_7 = V_89 . V_76 ;
}
return V_7 ;
}
static int F_65 ( T_1 * V_15 , void * V_14 )
{
struct V_90 * V_91 = V_14 ;
T_4 V_8 ;
int V_26 ;
V_26 = F_27 ( V_15 ) ;
if ( ( V_26 == V_92 ||
V_26 == V_93 ) &&
F_17 ( V_15 , V_91 -> V_20 ) &&
( F_6 ( V_15 , V_94 , & V_8 ) ||
F_6 ( V_15 , V_95 , & V_8 ) ) )
return V_57 ;
if ( F_51 ( V_15 , V_91 -> V_10 ) )
return V_66 ;
else
return V_59 ;
}
T_1 * F_66 ( T_1 * V_67 , const char * V_20 ,
T_6 V_10 , T_1 * V_15 )
{
struct V_90 V_91 = { . V_20 = V_20 , . V_10 = V_10 } ;
return F_16 ( V_67 , F_65 , ( void * ) & V_91 ,
V_15 ) ;
}
static int F_67 ( T_1 * V_15 , void * V_14 )
{
const char * V_20 = V_14 ;
if ( F_27 ( V_15 ) == V_96 ) {
if ( F_17 ( V_15 , V_20 ) )
return V_57 ;
else if ( ! F_18 ( V_15 ) ) {
T_1 V_97 , V_68 ;
if ( F_23 ( V_15 , & V_97 ) &&
F_68 ( & V_97 , V_20 , & V_68 ) )
return V_57 ;
}
}
return V_59 ;
}
T_1 * F_68 ( T_1 * V_98 , const char * V_20 ,
T_1 * V_15 )
{
return F_16 ( V_98 , F_67 , ( void * ) V_20 ,
V_15 ) ;
}
int F_69 ( T_1 * V_24 , struct V_99 * V_100 )
{
T_1 type ;
int V_26 , V_7 ;
const char * V_41 = L_7 ;
if ( F_26 ( V_24 , & type ) == NULL )
return - V_13 ;
V_26 = F_27 ( & type ) ;
if ( V_26 == V_101 || V_26 == V_102 )
V_41 = L_8 ;
else if ( V_26 == V_103 ) {
F_70 ( V_100 , L_9 , 15 ) ;
return 0 ;
} else {
if ( ! F_18 ( & type ) )
return - V_13 ;
if ( V_26 == V_104 )
V_41 = L_10 ;
else if ( V_26 == V_105 )
V_41 = L_11 ;
else if ( V_26 == V_106 )
V_41 = L_12 ;
F_71 ( V_100 , L_13 , V_41 , F_18 ( & type ) ) ;
return 0 ;
}
V_7 = F_69 ( & type , V_100 ) ;
if ( V_7 == 0 )
F_72 ( V_100 , V_41 ) ;
return V_7 ;
}
int F_73 ( T_1 * V_24 , struct V_99 * V_100 )
{
int V_7 ;
V_7 = F_69 ( V_24 , V_100 ) ;
if ( V_7 < 0 ) {
F_39 ( L_14 ) ;
F_70 ( V_100 , L_15 , 14 ) ;
}
F_71 ( V_100 , L_16 , F_18 ( V_24 ) ) ;
return 0 ;
}
static int F_74 ( T_1 * V_67 , T_1 * V_24 ,
struct V_99 * V_100 )
{
T_1 * V_107 ;
int V_108 ;
T_3 V_109 = 0 ;
T_6 V_110 ;
T_6 V_111 , V_112 ;
T_6 V_113 ;
int V_7 ;
bool V_114 = true ;
const char * V_20 ;
V_7 = F_36 ( V_67 , & V_113 ) ;
if ( V_7 )
return V_7 ;
V_20 = F_18 ( V_67 ) ;
if ( ! V_20 )
return - V_13 ;
V_108 = F_75 ( V_24 , & V_107 ) ;
if ( V_108 <= 1 ) {
V_7 = - V_88 ;
goto V_115;
}
while ( ( V_109 = F_76 ( & V_107 [ 1 ] , V_109 , & V_110 ,
& V_111 , & V_112 ) ) > 0 ) {
V_111 -= V_113 ;
V_112 -= V_113 ;
if ( V_114 ) {
F_71 ( V_100 , L_17 V_116 L_18 V_116 ,
V_20 , V_111 , V_112 ) ;
V_114 = false ;
} else {
F_71 ( V_100 , L_19 V_116 L_18 V_116 ,
V_111 , V_112 ) ;
}
}
if ( ! V_114 )
F_70 ( V_100 , L_20 , 2 ) ;
V_115:
free ( V_107 ) ;
return V_7 ;
}
int F_77 ( T_1 * V_67 , T_1 * V_24 , struct V_99 * V_100 )
{
int V_7 = 0 ;
T_6 V_110 ;
T_6 V_111 , V_112 ;
T_6 V_113 ;
T_9 * V_117 ;
T_3 V_118 ;
T_3 V_109 = 0 ;
T_4 V_8 ;
bool V_114 = true ;
const char * V_20 ;
V_7 = F_36 ( V_67 , & V_113 ) ;
if ( V_7 )
return V_7 ;
V_20 = F_18 ( V_67 ) ;
if ( ! V_20 )
return - V_13 ;
if ( F_6 ( V_24 , V_95 , & V_8 ) == NULL )
return - V_88 ;
while ( ( V_109 = F_78 (
& V_8 , V_109 , & V_110 ,
& V_111 , & V_112 , & V_117 , & V_118 ) ) > 0 ) {
if ( V_111 == 0 ) {
V_7 = F_74 ( V_67 , V_24 , V_100 ) ;
return V_7 ;
}
V_111 -= V_113 ;
V_112 -= V_113 ;
if ( V_114 ) {
F_71 ( V_100 , L_17 V_116 L_18 V_116 ,
V_20 , V_111 , V_112 ) ;
V_114 = false ;
} else {
F_71 ( V_100 , L_19 V_116 L_18 V_116 ,
V_111 , V_112 ) ;
}
}
if ( ! V_114 )
F_70 ( V_100 , L_20 , 2 ) ;
return V_7 ;
}
int F_77 ( T_1 * V_67 V_119 ,
T_1 * V_24 V_119 ,
struct V_99 * V_100 V_119 )
{
return - V_49 ;
}
