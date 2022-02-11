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
int F_31 ( T_1 * V_38 , T_7 * V_39 )
{
T_4 V_8 ;
T_9 * V_40 ;
T_3 V_41 ;
int V_7 ;
if ( F_6 ( V_38 , V_42 , & V_8 ) == NULL )
return - V_13 ;
if ( F_20 ( & V_8 , V_39 ) != 0 ) {
V_7 = F_32 ( & V_8 , & V_40 , & V_41 ) ;
if ( V_7 < 0 || V_41 == 0 )
return - V_13 ;
if ( V_40 [ 0 ] . V_43 != V_44 || V_41 != 1 ) {
F_33 ( L_1 ,
V_40 [ 0 ] . V_43 , V_41 ) ;
return - V_45 ;
}
* V_39 = ( T_7 ) V_40 [ 0 ] . V_46 ;
}
return 0 ;
}
static int F_34 ( T_1 * V_21 )
{
T_8 V_47 ;
if ( F_28 ( V_21 , V_48 , & V_47 ) == 0 )
return ( int ) V_47 ;
else
return - V_13 ;
}
static int F_35 ( T_1 * V_49 )
{
T_8 V_47 ;
if ( F_28 ( V_49 , V_50 , & V_47 ) == 0 )
return ( int ) V_47 ;
else
return - V_13 ;
}
const char * F_36 ( T_1 * V_21 )
{
T_1 V_1 ;
T_2 * V_3 ;
int V_47 ;
V_47 = F_34 ( V_21 ) ;
if ( V_47 < 0 || ! F_37 ( V_21 , & V_1 , NULL , NULL ) ||
F_2 ( & V_1 , & V_3 , NULL ) != 0 )
return NULL ;
return F_3 ( V_3 , V_47 , NULL , NULL ) ;
}
T_1 * F_16 ( T_1 * V_51 ,
int (* F_14)( T_1 * , void * ) ,
void * V_14 , T_1 * V_15 )
{
T_1 V_52 ;
int V_7 ;
V_7 = F_38 ( V_51 , V_15 ) ;
if ( V_7 != 0 )
return NULL ;
do {
V_7 = F_14 ( V_15 , V_14 ) ;
if ( V_7 == V_53 )
return V_15 ;
if ( ( V_7 & V_54 ) &&
F_16 ( V_15 , F_14 , V_14 , & V_52 ) ) {
memcpy ( V_15 , & V_52 , sizeof( T_1 ) ) ;
return V_15 ;
}
} while ( ( V_7 & V_55 ) &&
F_39 ( V_15 , V_15 ) == 0 );
return NULL ;
}
static int F_40 ( T_1 * V_56 , void * V_14 )
{
struct V_57 * V_58 = V_14 ;
if ( F_25 ( V_56 ) == V_59 &&
F_41 ( V_56 , V_58 -> V_10 ) ) {
memcpy ( V_58 -> V_15 , V_56 , sizeof( T_1 ) ) ;
return V_60 ;
}
return V_61 ;
}
T_1 * F_15 ( T_1 * V_1 , T_6 V_10 ,
T_1 * V_15 )
{
struct V_57 V_58 ;
V_58 . V_10 = V_10 ;
V_58 . V_15 = V_15 ;
if ( ! F_42 ( V_1 , F_40 , & V_58 , 0 ) )
return NULL ;
else
return V_15 ;
}
static int V_17 ( T_1 * V_15 , void * V_14 )
{
T_6 * V_10 = V_14 ;
if ( F_25 ( V_15 ) == V_62 &&
F_41 ( V_15 , * V_10 ) )
return V_53 ;
return V_63 ;
}
T_1 * F_43 ( T_1 * V_64 , T_6 V_10 ,
T_1 * V_15 )
{
T_1 V_65 ;
V_64 = F_16 ( V_64 , V_17 , & V_10 , & V_65 ) ;
if ( ! V_64 )
return NULL ;
while ( V_64 ) {
memcpy ( V_15 , V_64 , sizeof( T_1 ) ) ;
V_64 = F_16 ( V_64 , V_17 , & V_10 ,
& V_65 ) ;
}
return V_15 ;
}
static int F_44 ( T_1 * V_66 , void * V_14 )
{
struct V_67 * V_68 = V_14 ;
T_4 V_69 ;
T_1 V_70 ;
T_4 * V_8 ;
T_1 * V_71 ;
int V_72 ;
V_8 = F_6 ( V_66 , V_73 , & V_69 ) ;
if ( V_8 == NULL )
return V_63 ;
V_71 = F_23 ( V_8 , & V_70 ) ;
if ( V_71 == NULL || V_71 -> V_10 != V_68 -> V_10 )
return V_63 ;
if ( F_25 ( V_66 ) == V_62 ) {
F_45 ( V_71 , & V_72 ) ;
if ( F_19 ( V_66 ) == V_72 ) {
V_72 = F_35 ( V_71 ) ;
if ( F_34 ( V_66 ) == V_72 )
return V_63 ;
}
}
V_68 -> V_74 = V_68 -> F_14 ( V_66 , V_68 -> V_14 ) ;
return ( V_68 -> V_74 ) ? V_53 : V_63 ;
}
int F_46 ( T_1 * V_75 , int (* F_14)( T_1 * , void * ) ,
void * V_14 )
{
T_1 V_1 ;
T_1 V_15 ;
struct V_67 V_68 = {
. V_10 = V_75 -> V_10 ,
. F_14 = F_14 ,
. V_14 = V_14 ,
. V_74 = - V_13 ,
} ;
if ( F_37 ( V_75 , & V_1 , NULL , NULL ) == NULL )
return - V_13 ;
F_16 ( & V_1 , F_44 , & V_68 , & V_15 ) ;
return V_68 . V_74 ;
}
static int F_47 ( T_1 * V_21 , void * V_14 )
{
struct V_76 * V_77 = V_14 ;
T_6 V_10 = 0 ;
const char * V_2 ;
int V_11 ;
if ( F_25 ( V_21 ) == V_62 ) {
V_2 = F_36 ( V_21 ) ;
V_11 = F_19 ( V_21 ) ;
if ( V_2 && V_11 > 0 && F_48 ( V_21 , & V_10 ) == 0 ) {
V_77 -> V_74 = V_77 -> F_14 ( V_2 , V_11 , V_10 , V_77 -> V_14 ) ;
if ( V_77 -> V_74 != 0 )
return V_53 ;
}
}
if ( ! V_77 -> V_78 )
return V_55 ;
if ( V_10 ) {
V_2 = F_49 ( V_21 ) ;
if ( V_2 && F_45 ( V_21 , & V_11 ) == 0 ) {
V_77 -> V_74 = V_77 -> F_14 ( V_2 , V_11 , V_10 , V_77 -> V_14 ) ;
if ( V_77 -> V_74 != 0 )
return V_53 ;
}
}
return V_63 ;
}
static int F_50 ( T_1 * V_64 , bool V_78 ,
T_10 F_14 , void * V_14 )
{
struct V_76 V_77 = {
. V_78 = V_78 ,
. F_14 = F_14 ,
. V_14 = V_14 ,
. V_74 = 0 ,
} ;
T_1 V_15 ;
T_6 V_10 ;
const char * V_2 ;
int V_11 ;
V_2 = F_49 ( V_64 ) ;
if ( V_2 && F_45 ( V_64 , & V_11 ) == 0 &&
F_48 ( V_64 , & V_10 ) == 0 ) {
V_77 . V_74 = F_14 ( V_2 , V_11 , V_10 , V_14 ) ;
if ( V_77 . V_74 != 0 )
goto V_79;
}
F_16 ( V_64 , F_47 , & V_77 , & V_15 ) ;
V_79:
return V_77 . V_74 ;
}
static int F_51 ( T_1 * V_64 , void * V_14 )
{
struct V_76 * V_77 = V_14 ;
V_77 -> V_74 = F_50 ( V_64 , true , V_77 -> F_14 , V_77 -> V_14 ) ;
if ( V_77 -> V_74 != 0 )
return V_60 ;
return V_61 ;
}
int F_52 ( T_1 * V_51 , T_10 F_14 , void * V_14 )
{
T_11 * V_80 ;
T_5 * line ;
T_6 V_10 ;
const char * V_2 ;
int V_11 , V_7 = 0 ;
T_1 V_15 , * V_1 ;
T_3 V_81 , V_5 ;
if ( F_25 ( V_51 ) != V_82 )
V_1 = F_37 ( V_51 , & V_15 , NULL , NULL ) ;
else
V_1 = V_51 ;
if ( ! V_1 ) {
F_53 ( L_2 ) ;
return - V_83 ;
}
if ( F_54 ( V_1 , & V_80 , & V_81 ) != 0 ) {
F_53 ( L_3 ) ;
return - V_13 ;
}
F_53 ( L_4 , V_81 ) ;
for ( V_5 = 0 ; V_5 < V_81 ; V_5 ++ ) {
line = F_55 ( V_80 , V_5 ) ;
if ( line == NULL ||
F_11 ( line , & V_11 ) != 0 ||
F_10 ( line , & V_10 ) != 0 ) {
F_53 ( L_5
L_6 ) ;
continue;
}
if ( V_51 != V_1 )
if ( ! F_41 ( V_51 , V_10 ) ||
F_43 ( V_51 , V_10 , & V_15 ) )
continue;
V_2 = F_12 ( line , NULL , NULL ) ;
V_7 = F_14 ( V_2 , V_11 , V_10 , V_14 ) ;
if ( V_7 != 0 )
return V_7 ;
}
if ( V_51 != V_1 )
V_7 = F_50 ( V_51 , false , F_14 , V_14 ) ;
else {
struct V_76 V_84 = {
. F_14 = F_14 ,
. V_14 = V_14 ,
. V_74 = 0 ,
} ;
F_42 ( V_1 , F_51 , & V_84 , 0 ) ;
V_7 = V_84 . V_74 ;
}
return V_7 ;
}
static int F_56 ( T_1 * V_15 , void * V_14 )
{
struct V_85 * V_86 = V_14 ;
int V_25 ;
V_25 = F_25 ( V_15 ) ;
if ( ( V_25 == V_87 ||
V_25 == V_88 ) &&
F_17 ( V_15 , V_86 -> V_20 ) )
return V_53 ;
if ( F_41 ( V_15 , V_86 -> V_10 ) )
return V_63 ;
else
return V_55 ;
}
T_1 * F_57 ( T_1 * V_64 , const char * V_20 ,
T_6 V_10 , T_1 * V_15 )
{
struct V_85 V_86 = { . V_20 = V_20 , . V_10 = V_10 } ;
return F_16 ( V_64 , F_56 , ( void * ) & V_86 ,
V_15 ) ;
}
static int F_58 ( T_1 * V_15 , void * V_14 )
{
const char * V_20 = V_14 ;
if ( ( F_25 ( V_15 ) == V_89 ) &&
F_17 ( V_15 , V_20 ) )
return V_53 ;
return V_55 ;
}
T_1 * F_59 ( T_1 * V_90 , const char * V_20 ,
T_1 * V_15 )
{
return F_16 ( V_90 , F_58 , ( void * ) V_20 ,
V_15 ) ;
}
int F_60 ( T_1 * V_23 , char * V_91 , int V_92 )
{
T_1 type ;
int V_25 , V_7 , V_93 ;
const char * V_72 = L_7 ;
if ( F_24 ( V_23 , & type ) == NULL )
return - V_13 ;
V_25 = F_25 ( & type ) ;
if ( V_25 == V_94 || V_25 == V_95 )
V_72 = L_8 ;
else if ( V_25 == V_96 ) {
V_7 = snprintf ( V_91 , V_92 , L_9 ) ;
return ( V_7 >= V_92 ) ? - V_97 : V_7 ;
} else {
if ( ! F_18 ( & type ) )
return - V_13 ;
if ( V_25 == V_98 )
V_72 = L_10 ;
else if ( V_25 == V_99 )
V_72 = L_11 ;
V_7 = snprintf ( V_91 , V_92 , L_12 , V_72 , F_18 ( & type ) ) ;
return ( V_7 >= V_92 ) ? - V_97 : V_7 ;
}
V_7 = F_60 ( & type , V_91 , V_92 ) ;
if ( V_7 > 0 ) {
V_93 = snprintf ( V_91 + V_7 , V_92 - V_7 , L_13 , V_72 ) ;
V_7 = ( V_93 >= V_92 - V_7 ) ? - V_97 : V_93 + V_7 ;
}
return V_7 ;
}
int F_61 ( T_1 * V_23 , char * V_91 , int V_92 )
{
int V_7 , V_93 ;
V_7 = F_60 ( V_23 , V_91 , V_92 ) ;
if ( V_7 < 0 ) {
F_33 ( L_14 ) ;
V_7 = snprintf ( V_91 , V_92 , L_15 ) ;
}
if ( V_7 > 0 ) {
V_93 = snprintf ( V_91 + V_7 , V_92 - V_7 , L_16 ,
F_18 ( V_23 ) ) ;
V_7 = ( V_93 >= V_92 - V_7 ) ? - V_97 : V_93 + V_7 ;
}
return V_7 ;
}
