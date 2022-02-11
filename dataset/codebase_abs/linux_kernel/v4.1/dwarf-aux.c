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
bool F_32 ( T_1 * V_18 )
{
T_6 V_40 ;
return ! F_33 ( V_18 ) && F_34 ( V_18 , & V_40 ) == 0 ;
}
int F_35 ( T_1 * V_41 , T_7 * V_42 )
{
T_4 V_8 ;
T_9 * V_43 ;
T_3 V_44 ;
int V_7 ;
if ( F_6 ( V_41 , V_45 , & V_8 ) == NULL )
return - V_13 ;
if ( F_20 ( & V_8 , V_42 ) != 0 ) {
V_7 = F_36 ( & V_8 , & V_43 , & V_44 ) ;
if ( V_7 < 0 || V_44 == 0 )
return - V_13 ;
if ( V_43 [ 0 ] . V_46 != V_47 || V_44 != 1 ) {
F_37 ( L_1 ,
V_43 [ 0 ] . V_46 , V_44 ) ;
return - V_48 ;
}
* V_42 = ( T_7 ) V_43 [ 0 ] . V_49 ;
}
return 0 ;
}
static int F_38 ( T_1 * V_21 )
{
T_8 V_50 ;
if ( F_28 ( V_21 , V_51 , & V_50 ) == 0 )
return ( int ) V_50 ;
else
return - V_13 ;
}
static int F_39 ( T_1 * V_52 )
{
T_8 V_50 ;
if ( F_28 ( V_52 , V_53 , & V_50 ) == 0 )
return ( int ) V_50 ;
else
return - V_13 ;
}
const char * F_40 ( T_1 * V_21 )
{
T_1 V_1 ;
T_2 * V_3 ;
int V_50 ;
V_50 = F_38 ( V_21 ) ;
if ( V_50 < 0 || ! F_41 ( V_21 , & V_1 , NULL , NULL ) ||
F_2 ( & V_1 , & V_3 , NULL ) != 0 )
return NULL ;
return F_3 ( V_3 , V_50 , NULL , NULL ) ;
}
T_1 * F_16 ( T_1 * V_54 ,
int (* F_14)( T_1 * , void * ) ,
void * V_14 , T_1 * V_15 )
{
T_1 V_55 ;
int V_7 ;
V_7 = F_42 ( V_54 , V_15 ) ;
if ( V_7 != 0 )
return NULL ;
do {
V_7 = F_14 ( V_15 , V_14 ) ;
if ( V_7 == V_56 )
return V_15 ;
if ( ( V_7 & V_57 ) &&
F_16 ( V_15 , F_14 , V_14 , & V_55 ) ) {
memcpy ( V_15 , & V_55 , sizeof( T_1 ) ) ;
return V_15 ;
}
} while ( ( V_7 & V_58 ) &&
F_43 ( V_15 , V_15 ) == 0 );
return NULL ;
}
static int F_44 ( T_1 * V_59 , void * V_14 )
{
struct V_60 * V_61 = V_14 ;
if ( F_25 ( V_59 ) == V_38 &&
F_45 ( V_59 , V_61 -> V_10 ) ) {
memcpy ( V_61 -> V_15 , V_59 , sizeof( T_1 ) ) ;
return V_62 ;
}
return V_63 ;
}
T_1 * F_15 ( T_1 * V_1 , T_6 V_10 ,
T_1 * V_15 )
{
struct V_60 V_61 ;
V_61 . V_10 = V_10 ;
V_61 . V_15 = V_15 ;
if ( ! F_46 ( V_1 , F_44 , & V_61 , 0 ) )
return NULL ;
else
return V_15 ;
}
static int V_17 ( T_1 * V_15 , void * V_14 )
{
T_6 * V_10 = V_14 ;
if ( F_25 ( V_15 ) == V_64 &&
F_45 ( V_15 , * V_10 ) )
return V_56 ;
return V_65 ;
}
T_1 * F_47 ( T_1 * V_66 , T_6 V_10 ,
T_1 * V_15 )
{
return F_16 ( V_66 , V_17 , & V_10 , V_15 ) ;
}
T_1 * F_48 ( T_1 * V_66 , T_6 V_10 ,
T_1 * V_15 )
{
T_1 V_67 ;
V_66 = F_16 ( V_66 , V_17 , & V_10 , & V_67 ) ;
if ( ! V_66 )
return NULL ;
while ( V_66 ) {
memcpy ( V_15 , V_66 , sizeof( T_1 ) ) ;
V_66 = F_16 ( V_66 , V_17 , & V_10 ,
& V_67 ) ;
}
return V_15 ;
}
static int F_49 ( T_1 * V_68 , void * V_14 )
{
struct V_69 * V_70 = V_14 ;
T_4 V_71 ;
T_1 V_72 ;
T_4 * V_8 ;
T_1 * V_73 ;
int V_40 ;
V_8 = F_6 ( V_68 , V_74 , & V_71 ) ;
if ( V_8 == NULL )
return V_65 ;
V_73 = F_23 ( V_8 , & V_72 ) ;
if ( V_73 == NULL || V_73 -> V_10 != V_70 -> V_10 )
return V_65 ;
if ( F_25 ( V_68 ) == V_64 ) {
F_50 ( V_73 , & V_40 ) ;
if ( F_19 ( V_68 ) == V_40 ) {
V_40 = F_39 ( V_73 ) ;
if ( F_38 ( V_68 ) == V_40 )
return V_65 ;
}
}
V_70 -> V_75 = V_70 -> F_14 ( V_68 , V_70 -> V_14 ) ;
return ( V_70 -> V_75 ) ? V_56 : V_65 ;
}
int F_51 ( T_1 * V_76 , int (* F_14)( T_1 * , void * ) ,
void * V_14 )
{
T_1 V_1 ;
T_1 V_15 ;
struct V_69 V_70 = {
. V_10 = V_76 -> V_10 ,
. F_14 = F_14 ,
. V_14 = V_14 ,
. V_75 = - V_13 ,
} ;
if ( F_41 ( V_76 , & V_1 , NULL , NULL ) == NULL )
return - V_13 ;
F_16 ( & V_1 , F_49 , & V_70 , & V_15 ) ;
return V_70 . V_75 ;
}
static int F_52 ( T_1 * V_21 , void * V_14 )
{
struct V_77 * V_78 = V_14 ;
T_6 V_10 = 0 ;
const char * V_2 ;
int V_11 ;
if ( F_25 ( V_21 ) == V_64 ) {
V_2 = F_40 ( V_21 ) ;
V_11 = F_19 ( V_21 ) ;
if ( V_2 && V_11 > 0 && F_34 ( V_21 , & V_10 ) == 0 ) {
V_78 -> V_75 = V_78 -> F_14 ( V_2 , V_11 , V_10 , V_78 -> V_14 ) ;
if ( V_78 -> V_75 != 0 )
return V_56 ;
}
}
if ( ! V_78 -> V_79 )
return V_58 ;
if ( V_10 ) {
V_2 = F_53 ( V_21 ) ;
if ( V_2 && F_50 ( V_21 , & V_11 ) == 0 ) {
V_78 -> V_75 = V_78 -> F_14 ( V_2 , V_11 , V_10 , V_78 -> V_14 ) ;
if ( V_78 -> V_75 != 0 )
return V_56 ;
}
}
return V_65 ;
}
static int F_54 ( T_1 * V_66 , bool V_79 ,
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
V_2 = F_53 ( V_66 ) ;
if ( V_2 && F_50 ( V_66 , & V_11 ) == 0 &&
F_34 ( V_66 , & V_10 ) == 0 ) {
V_78 . V_75 = F_14 ( V_2 , V_11 , V_10 , V_14 ) ;
if ( V_78 . V_75 != 0 )
goto V_80;
}
F_16 ( V_66 , F_52 , & V_78 , & V_15 ) ;
V_80:
return V_78 . V_75 ;
}
static int F_55 ( T_1 * V_66 , void * V_14 )
{
struct V_77 * V_78 = V_14 ;
V_78 -> V_75 = F_54 ( V_66 , true , V_78 -> F_14 , V_78 -> V_14 ) ;
if ( V_78 -> V_75 != 0 )
return V_62 ;
return V_63 ;
}
int F_56 ( T_1 * V_54 , T_10 F_14 , void * V_14 )
{
T_11 * V_81 ;
T_5 * line ;
T_6 V_10 ;
const char * V_2 ;
int V_11 , V_7 = 0 ;
T_1 V_15 , * V_1 ;
T_3 V_82 , V_5 ;
if ( F_25 ( V_54 ) != V_83 )
V_1 = F_41 ( V_54 , & V_15 , NULL , NULL ) ;
else
V_1 = V_54 ;
if ( ! V_1 ) {
F_57 ( L_2 ) ;
return - V_84 ;
}
if ( F_58 ( V_1 , & V_81 , & V_82 ) != 0 ) {
F_57 ( L_3 ) ;
return - V_13 ;
}
F_57 ( L_4 , V_82 ) ;
for ( V_5 = 0 ; V_5 < V_82 ; V_5 ++ ) {
line = F_59 ( V_81 , V_5 ) ;
if ( line == NULL ||
F_11 ( line , & V_11 ) != 0 ||
F_10 ( line , & V_10 ) != 0 ) {
F_57 ( L_5
L_6 ) ;
continue;
}
if ( V_54 != V_1 )
if ( ! F_45 ( V_54 , V_10 ) ||
F_48 ( V_54 , V_10 , & V_15 ) )
continue;
V_2 = F_12 ( line , NULL , NULL ) ;
V_7 = F_14 ( V_2 , V_11 , V_10 , V_14 ) ;
if ( V_7 != 0 )
return V_7 ;
}
if ( V_54 != V_1 )
V_7 = F_54 ( V_54 , false , F_14 , V_14 ) ;
else {
struct V_77 V_85 = {
. F_14 = F_14 ,
. V_14 = V_14 ,
. V_75 = 0 ,
} ;
F_46 ( V_1 , F_55 , & V_85 , 0 ) ;
V_7 = V_85 . V_75 ;
}
return V_7 ;
}
static int F_60 ( T_1 * V_15 , void * V_14 )
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
return V_56 ;
if ( F_45 ( V_15 , V_87 -> V_10 ) )
return V_65 ;
else
return V_58 ;
}
T_1 * F_61 ( T_1 * V_66 , const char * V_20 ,
T_6 V_10 , T_1 * V_15 )
{
struct V_86 V_87 = { . V_20 = V_20 , . V_10 = V_10 } ;
return F_16 ( V_66 , F_60 , ( void * ) & V_87 ,
V_15 ) ;
}
static int F_62 ( T_1 * V_15 , void * V_14 )
{
const char * V_20 = V_14 ;
if ( F_25 ( V_15 ) == V_92 ) {
if ( F_17 ( V_15 , V_20 ) )
return V_56 ;
else if ( ! F_18 ( V_15 ) ) {
T_1 V_93 , V_67 ;
if ( F_21 ( V_15 , & V_93 ) &&
F_63 ( & V_93 , V_20 , & V_67 ) )
return V_56 ;
}
}
return V_58 ;
}
T_1 * F_63 ( T_1 * V_94 , const char * V_20 ,
T_1 * V_15 )
{
return F_16 ( V_94 , F_62 , ( void * ) V_20 ,
V_15 ) ;
}
int F_64 ( T_1 * V_23 , char * V_95 , int V_96 )
{
T_1 type ;
int V_25 , V_7 , V_97 ;
const char * V_40 = L_7 ;
if ( F_24 ( V_23 , & type ) == NULL )
return - V_13 ;
V_25 = F_25 ( & type ) ;
if ( V_25 == V_98 || V_25 == V_99 )
V_40 = L_8 ;
else if ( V_25 == V_100 ) {
V_7 = snprintf ( V_95 , V_96 , L_9 ) ;
return ( V_7 >= V_96 ) ? - V_101 : V_7 ;
} else {
if ( ! F_18 ( & type ) )
return - V_13 ;
if ( V_25 == V_102 )
V_40 = L_10 ;
else if ( V_25 == V_103 )
V_40 = L_11 ;
else if ( V_25 == V_104 )
V_40 = L_12 ;
V_7 = snprintf ( V_95 , V_96 , L_13 , V_40 , F_18 ( & type ) ) ;
return ( V_7 >= V_96 ) ? - V_101 : V_7 ;
}
V_7 = F_64 ( & type , V_95 , V_96 ) ;
if ( V_7 > 0 ) {
V_97 = snprintf ( V_95 + V_7 , V_96 - V_7 , L_14 , V_40 ) ;
V_7 = ( V_97 >= V_96 - V_7 ) ? - V_101 : V_97 + V_7 ;
}
return V_7 ;
}
int F_65 ( T_1 * V_23 , char * V_95 , int V_96 )
{
int V_7 , V_97 ;
V_7 = F_64 ( V_23 , V_95 , V_96 ) ;
if ( V_7 < 0 ) {
F_37 ( L_15 ) ;
V_7 = snprintf ( V_95 , V_96 , L_16 ) ;
}
if ( V_7 > 0 ) {
V_97 = snprintf ( V_95 + V_7 , V_96 - V_7 , L_17 ,
F_18 ( V_23 ) ) ;
V_7 = ( V_97 >= V_96 - V_7 ) ? - V_101 : V_97 + V_7 ;
}
return V_7 ;
}
