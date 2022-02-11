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
int F_19 ( T_1 * V_21 )
{
T_4 V_8 ;
T_7 V_7 ;
if ( ! F_6 ( V_21 , V_22 , & V_8 ) )
return - V_13 ;
F_20 ( & V_8 , & V_7 ) ;
return ( int ) V_7 ;
}
T_1 * F_21 ( T_1 * V_23 , T_1 * V_15 )
{
T_4 V_8 ;
if ( F_22 ( V_23 , V_24 , & V_8 ) &&
F_23 ( & V_8 , V_15 ) )
return V_15 ;
else
return NULL ;
}
static T_1 * F_24 ( T_1 * V_23 , T_1 * V_15 )
{
int V_25 ;
do {
V_23 = F_21 ( V_23 , V_15 ) ;
if ( ! V_23 )
break;
V_25 = F_25 ( V_23 ) ;
} while ( V_25 == V_26 ||
V_25 == V_27 ||
V_25 == V_28 ||
V_25 == V_29 );
return V_23 ;
}
T_1 * F_26 ( T_1 * V_23 , T_1 * V_15 )
{
do {
V_23 = F_24 ( V_23 , V_15 ) ;
} while ( V_23 && F_25 ( V_23 ) == V_30 );
return V_23 ;
}
static int F_27 ( T_1 * V_31 , unsigned int V_32 ,
T_7 * V_33 )
{
T_4 V_8 ;
if ( F_6 ( V_31 , V_32 , & V_8 ) == NULL ||
F_20 ( & V_8 , V_33 ) != 0 )
return - V_13 ;
return 0 ;
}
static int F_28 ( T_1 * V_31 , unsigned int V_32 ,
T_8 * V_33 )
{
T_4 V_8 ;
if ( F_6 ( V_31 , V_32 , & V_8 ) == NULL ||
F_29 ( & V_8 , V_33 ) != 0 )
return - V_13 ;
return 0 ;
}
bool F_30 ( T_1 * V_31 )
{
T_7 V_7 ;
if ( F_27 ( V_31 , V_34 , & V_7 ) )
return false ;
return ( V_7 == V_35 || V_7 == V_36 ||
V_7 == V_37 ) ;
}
bool F_31 ( T_1 * V_18 )
{
T_4 V_8 ;
return ( F_25 ( V_18 ) == V_38 &&
F_6 ( V_18 , V_39 , & V_8 ) == NULL ) ;
}
int F_32 ( T_1 * V_40 , T_7 * V_41 )
{
T_4 V_8 ;
T_9 * V_42 ;
T_3 V_43 ;
int V_7 ;
if ( F_6 ( V_40 , V_44 , & V_8 ) == NULL )
return - V_13 ;
if ( F_20 ( & V_8 , V_41 ) != 0 ) {
V_7 = F_33 ( & V_8 , & V_42 , & V_43 ) ;
if ( V_7 < 0 || V_43 == 0 )
return - V_13 ;
if ( V_42 [ 0 ] . V_45 != V_46 || V_43 != 1 ) {
F_34 ( L_1 ,
V_42 [ 0 ] . V_45 , V_43 ) ;
return - V_47 ;
}
* V_41 = ( T_7 ) V_42 [ 0 ] . V_48 ;
}
return 0 ;
}
static int F_35 ( T_1 * V_21 )
{
T_8 V_49 ;
if ( F_28 ( V_21 , V_50 , & V_49 ) == 0 )
return ( int ) V_49 ;
else
return - V_13 ;
}
static int F_36 ( T_1 * V_51 )
{
T_8 V_49 ;
if ( F_28 ( V_51 , V_52 , & V_49 ) == 0 )
return ( int ) V_49 ;
else
return - V_13 ;
}
const char * F_37 ( T_1 * V_21 )
{
T_1 V_1 ;
T_2 * V_3 ;
int V_49 ;
V_49 = F_35 ( V_21 ) ;
if ( V_49 < 0 || ! F_38 ( V_21 , & V_1 , NULL , NULL ) ||
F_2 ( & V_1 , & V_3 , NULL ) != 0 )
return NULL ;
return F_3 ( V_3 , V_49 , NULL , NULL ) ;
}
T_1 * F_16 ( T_1 * V_53 ,
int (* F_14)( T_1 * , void * ) ,
void * V_14 , T_1 * V_15 )
{
T_1 V_54 ;
int V_7 ;
V_7 = F_39 ( V_53 , V_15 ) ;
if ( V_7 != 0 )
return NULL ;
do {
V_7 = F_14 ( V_15 , V_14 ) ;
if ( V_7 == V_55 )
return V_15 ;
if ( ( V_7 & V_56 ) &&
F_16 ( V_15 , F_14 , V_14 , & V_54 ) ) {
memcpy ( V_15 , & V_54 , sizeof( T_1 ) ) ;
return V_15 ;
}
} while ( ( V_7 & V_57 ) &&
F_40 ( V_15 , V_15 ) == 0 );
return NULL ;
}
static int F_41 ( T_1 * V_58 , void * V_14 )
{
struct V_59 * V_60 = V_14 ;
if ( F_25 ( V_58 ) == V_38 &&
F_42 ( V_58 , V_60 -> V_10 ) ) {
memcpy ( V_60 -> V_15 , V_58 , sizeof( T_1 ) ) ;
return V_61 ;
}
return V_62 ;
}
T_1 * F_15 ( T_1 * V_1 , T_6 V_10 ,
T_1 * V_15 )
{
struct V_59 V_60 ;
V_60 . V_10 = V_10 ;
V_60 . V_15 = V_15 ;
if ( ! F_43 ( V_1 , F_41 , & V_60 , 0 ) )
return NULL ;
else
return V_15 ;
}
static int V_17 ( T_1 * V_15 , void * V_14 )
{
T_6 * V_10 = V_14 ;
if ( F_25 ( V_15 ) == V_63 &&
F_42 ( V_15 , * V_10 ) )
return V_55 ;
return V_64 ;
}
T_1 * F_44 ( T_1 * V_65 , T_6 V_10 ,
T_1 * V_15 )
{
return F_16 ( V_65 , V_17 , & V_10 , V_15 ) ;
}
T_1 * F_45 ( T_1 * V_65 , T_6 V_10 ,
T_1 * V_15 )
{
T_1 V_66 ;
V_65 = F_16 ( V_65 , V_17 , & V_10 , & V_66 ) ;
if ( ! V_65 )
return NULL ;
while ( V_65 ) {
memcpy ( V_15 , V_65 , sizeof( T_1 ) ) ;
V_65 = F_16 ( V_65 , V_17 , & V_10 ,
& V_66 ) ;
}
return V_15 ;
}
static int F_46 ( T_1 * V_67 , void * V_14 )
{
struct V_68 * V_69 = V_14 ;
T_4 V_70 ;
T_1 V_71 ;
T_4 * V_8 ;
T_1 * V_72 ;
int V_73 ;
V_8 = F_6 ( V_67 , V_74 , & V_70 ) ;
if ( V_8 == NULL )
return V_64 ;
V_72 = F_23 ( V_8 , & V_71 ) ;
if ( V_72 == NULL || V_72 -> V_10 != V_69 -> V_10 )
return V_64 ;
if ( F_25 ( V_67 ) == V_63 ) {
F_47 ( V_72 , & V_73 ) ;
if ( F_19 ( V_67 ) == V_73 ) {
V_73 = F_36 ( V_72 ) ;
if ( F_35 ( V_67 ) == V_73 )
return V_64 ;
}
}
V_69 -> V_75 = V_69 -> F_14 ( V_67 , V_69 -> V_14 ) ;
return ( V_69 -> V_75 ) ? V_55 : V_64 ;
}
int F_48 ( T_1 * V_76 , int (* F_14)( T_1 * , void * ) ,
void * V_14 )
{
T_1 V_1 ;
T_1 V_15 ;
struct V_68 V_69 = {
. V_10 = V_76 -> V_10 ,
. F_14 = F_14 ,
. V_14 = V_14 ,
. V_75 = - V_13 ,
} ;
if ( F_38 ( V_76 , & V_1 , NULL , NULL ) == NULL )
return - V_13 ;
F_16 ( & V_1 , F_46 , & V_69 , & V_15 ) ;
return V_69 . V_75 ;
}
static int F_49 ( T_1 * V_21 , void * V_14 )
{
struct V_77 * V_78 = V_14 ;
T_6 V_10 = 0 ;
const char * V_2 ;
int V_11 ;
if ( F_25 ( V_21 ) == V_63 ) {
V_2 = F_37 ( V_21 ) ;
V_11 = F_19 ( V_21 ) ;
if ( V_2 && V_11 > 0 && F_50 ( V_21 , & V_10 ) == 0 ) {
V_78 -> V_75 = V_78 -> F_14 ( V_2 , V_11 , V_10 , V_78 -> V_14 ) ;
if ( V_78 -> V_75 != 0 )
return V_55 ;
}
}
if ( ! V_78 -> V_79 )
return V_57 ;
if ( V_10 ) {
V_2 = F_51 ( V_21 ) ;
if ( V_2 && F_47 ( V_21 , & V_11 ) == 0 ) {
V_78 -> V_75 = V_78 -> F_14 ( V_2 , V_11 , V_10 , V_78 -> V_14 ) ;
if ( V_78 -> V_75 != 0 )
return V_55 ;
}
}
return V_64 ;
}
static int F_52 ( T_1 * V_65 , bool V_79 ,
T_10 F_14 , void * V_14 )
{
struct V_77 V_78 = {
. V_79 = V_79 ,
. F_14 = F_14 ,
. V_14 = V_14 ,
. V_75 = 0 ,
} ;
T_1 V_15 ;
T_6 V_10 ;
const char * V_2 ;
int V_11 ;
V_2 = F_51 ( V_65 ) ;
if ( V_2 && F_47 ( V_65 , & V_11 ) == 0 &&
F_50 ( V_65 , & V_10 ) == 0 ) {
V_78 . V_75 = F_14 ( V_2 , V_11 , V_10 , V_14 ) ;
if ( V_78 . V_75 != 0 )
goto V_80;
}
F_16 ( V_65 , F_49 , & V_78 , & V_15 ) ;
V_80:
return V_78 . V_75 ;
}
static int F_53 ( T_1 * V_65 , void * V_14 )
{
struct V_77 * V_78 = V_14 ;
V_78 -> V_75 = F_52 ( V_65 , true , V_78 -> F_14 , V_78 -> V_14 ) ;
if ( V_78 -> V_75 != 0 )
return V_61 ;
return V_62 ;
}
int F_54 ( T_1 * V_53 , T_10 F_14 , void * V_14 )
{
T_11 * V_81 ;
T_5 * line ;
T_6 V_10 ;
const char * V_2 ;
int V_11 , V_7 = 0 ;
T_1 V_15 , * V_1 ;
T_3 V_82 , V_5 ;
if ( F_25 ( V_53 ) != V_83 )
V_1 = F_38 ( V_53 , & V_15 , NULL , NULL ) ;
else
V_1 = V_53 ;
if ( ! V_1 ) {
F_55 ( L_2 ) ;
return - V_84 ;
}
if ( F_56 ( V_1 , & V_81 , & V_82 ) != 0 ) {
F_55 ( L_3 ) ;
return - V_13 ;
}
F_55 ( L_4 , V_82 ) ;
for ( V_5 = 0 ; V_5 < V_82 ; V_5 ++ ) {
line = F_57 ( V_81 , V_5 ) ;
if ( line == NULL ||
F_11 ( line , & V_11 ) != 0 ||
F_10 ( line , & V_10 ) != 0 ) {
F_55 ( L_5
L_6 ) ;
continue;
}
if ( V_53 != V_1 )
if ( ! F_42 ( V_53 , V_10 ) ||
F_45 ( V_53 , V_10 , & V_15 ) )
continue;
V_2 = F_12 ( line , NULL , NULL ) ;
V_7 = F_14 ( V_2 , V_11 , V_10 , V_14 ) ;
if ( V_7 != 0 )
return V_7 ;
}
if ( V_53 != V_1 )
V_7 = F_52 ( V_53 , false , F_14 , V_14 ) ;
else {
struct V_77 V_85 = {
. F_14 = F_14 ,
. V_14 = V_14 ,
. V_75 = 0 ,
} ;
F_43 ( V_1 , F_53 , & V_85 , 0 ) ;
V_7 = V_85 . V_75 ;
}
return V_7 ;
}
static int F_58 ( T_1 * V_15 , void * V_14 )
{
struct V_86 * V_87 = V_14 ;
T_4 V_8 ;
int V_25 ;
V_25 = F_25 ( V_15 ) ;
if ( ( V_25 == V_88 ||
V_25 == V_89 ) &&
F_17 ( V_15 , V_87 -> V_20 ) &&
( F_6 ( V_15 , V_90 , & V_8 ) ||
F_6 ( V_15 , V_91 , & V_8 ) ) )
return V_55 ;
if ( F_42 ( V_15 , V_87 -> V_10 ) )
return V_64 ;
else
return V_57 ;
}
T_1 * F_59 ( T_1 * V_65 , const char * V_20 ,
T_6 V_10 , T_1 * V_15 )
{
struct V_86 V_87 = { . V_20 = V_20 , . V_10 = V_10 } ;
return F_16 ( V_65 , F_58 , ( void * ) & V_87 ,
V_15 ) ;
}
static int F_60 ( T_1 * V_15 , void * V_14 )
{
const char * V_20 = V_14 ;
if ( ( F_25 ( V_15 ) == V_92 ) &&
F_17 ( V_15 , V_20 ) )
return V_55 ;
return V_57 ;
}
T_1 * F_61 ( T_1 * V_93 , const char * V_20 ,
T_1 * V_15 )
{
return F_16 ( V_93 , F_60 , ( void * ) V_20 ,
V_15 ) ;
}
int F_62 ( T_1 * V_23 , char * V_94 , int V_95 )
{
T_1 type ;
int V_25 , V_7 , V_96 ;
const char * V_73 = L_7 ;
if ( F_24 ( V_23 , & type ) == NULL )
return - V_13 ;
V_25 = F_25 ( & type ) ;
if ( V_25 == V_97 || V_25 == V_98 )
V_73 = L_8 ;
else if ( V_25 == V_99 ) {
V_7 = snprintf ( V_94 , V_95 , L_9 ) ;
return ( V_7 >= V_95 ) ? - V_100 : V_7 ;
} else {
if ( ! F_18 ( & type ) )
return - V_13 ;
if ( V_25 == V_101 )
V_73 = L_10 ;
else if ( V_25 == V_102 )
V_73 = L_11 ;
else if ( V_25 == V_103 )
V_73 = L_12 ;
V_7 = snprintf ( V_94 , V_95 , L_13 , V_73 , F_18 ( & type ) ) ;
return ( V_7 >= V_95 ) ? - V_100 : V_7 ;
}
V_7 = F_62 ( & type , V_94 , V_95 ) ;
if ( V_7 > 0 ) {
V_96 = snprintf ( V_94 + V_7 , V_95 - V_7 , L_14 , V_73 ) ;
V_7 = ( V_96 >= V_95 - V_7 ) ? - V_100 : V_96 + V_7 ;
}
return V_7 ;
}
int F_63 ( T_1 * V_23 , char * V_94 , int V_95 )
{
int V_7 , V_96 ;
V_7 = F_62 ( V_23 , V_94 , V_95 ) ;
if ( V_7 < 0 ) {
F_34 ( L_15 ) ;
V_7 = snprintf ( V_94 , V_95 , L_16 ) ;
}
if ( V_7 > 0 ) {
V_96 = snprintf ( V_94 + V_7 , V_95 - V_7 , L_17 ,
F_18 ( V_23 ) ) ;
V_7 = ( V_96 >= V_95 - V_7 ) ? - V_100 : V_96 + V_7 ;
}
return V_7 ;
}
