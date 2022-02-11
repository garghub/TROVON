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
const char * F_17 ( T_1 * V_18 )
{
T_4 V_8 ;
if ( F_18 ( V_18 , V_19 , & V_8 ) == NULL )
return NULL ;
return F_7 ( & V_8 ) ;
}
bool F_19 ( T_1 * V_18 , const char * V_20 )
{
const char * V_21 ;
V_21 = F_20 ( V_18 ) ;
return V_21 ? ( strcmp ( V_20 , V_21 ) == 0 ) : false ;
}
bool F_21 ( T_1 * V_18 , const char * V_22 )
{
const char * V_21 ;
V_21 = F_20 ( V_18 ) ;
if ( V_21 && F_22 ( V_21 , V_22 ) )
return true ;
V_21 = F_17 ( V_18 ) ;
if ( V_21 && F_22 ( V_21 , V_22 ) )
return true ;
return false ;
}
int F_23 ( T_1 * V_23 )
{
T_4 V_8 ;
T_7 V_7 ;
if ( ! F_6 ( V_23 , V_24 , & V_8 ) )
return - V_13 ;
F_24 ( & V_8 , & V_7 ) ;
return ( int ) V_7 ;
}
T_1 * F_25 ( T_1 * V_25 , T_1 * V_15 )
{
T_4 V_8 ;
if ( F_18 ( V_25 , V_26 , & V_8 ) &&
F_26 ( & V_8 , V_15 ) )
return V_15 ;
else
return NULL ;
}
static T_1 * F_27 ( T_1 * V_25 , T_1 * V_15 )
{
int V_27 ;
do {
V_25 = F_25 ( V_25 , V_15 ) ;
if ( ! V_25 )
break;
V_27 = F_28 ( V_25 ) ;
} while ( V_27 == V_28 ||
V_27 == V_29 ||
V_27 == V_30 ||
V_27 == V_31 );
return V_25 ;
}
T_1 * F_29 ( T_1 * V_25 , T_1 * V_15 )
{
do {
V_25 = F_27 ( V_25 , V_15 ) ;
} while ( V_25 && F_28 ( V_25 ) == V_32 );
return V_25 ;
}
static int F_30 ( T_1 * V_33 , unsigned int V_34 ,
T_7 * V_35 )
{
T_4 V_8 ;
if ( F_6 ( V_33 , V_34 , & V_8 ) == NULL ||
F_24 ( & V_8 , V_35 ) != 0 )
return - V_13 ;
return 0 ;
}
static int F_31 ( T_1 * V_33 , unsigned int V_34 ,
T_8 * V_35 )
{
T_4 V_8 ;
if ( F_6 ( V_33 , V_34 , & V_8 ) == NULL ||
F_32 ( & V_8 , V_35 ) != 0 )
return - V_13 ;
return 0 ;
}
bool F_33 ( T_1 * V_33 )
{
T_7 V_7 ;
if ( F_30 ( V_33 , V_36 , & V_7 ) )
return false ;
return ( V_7 == V_37 || V_7 == V_38 ||
V_7 == V_39 ) ;
}
bool F_34 ( T_1 * V_18 )
{
T_4 V_8 ;
return ( F_28 ( V_18 ) == V_40 &&
F_6 ( V_18 , V_41 , & V_8 ) == NULL ) ;
}
bool F_35 ( T_1 * V_18 )
{
T_6 V_42 ;
return ! F_36 ( V_18 ) && F_37 ( V_18 , & V_42 ) == 0 ;
}
int F_38 ( T_1 * V_43 , T_7 * V_44 )
{
T_4 V_8 ;
T_9 * V_45 ;
T_3 V_46 ;
int V_7 ;
if ( F_6 ( V_43 , V_47 , & V_8 ) == NULL )
return - V_13 ;
if ( F_24 ( & V_8 , V_44 ) != 0 ) {
V_7 = F_39 ( & V_8 , & V_45 , & V_46 ) ;
if ( V_7 < 0 || V_46 == 0 )
return - V_13 ;
if ( V_45 [ 0 ] . V_48 != V_49 || V_46 != 1 ) {
F_40 ( L_1 ,
V_45 [ 0 ] . V_48 , V_46 ) ;
return - V_50 ;
}
* V_44 = ( T_7 ) V_45 [ 0 ] . V_51 ;
}
return 0 ;
}
static int F_41 ( T_1 * V_23 )
{
T_8 V_52 ;
if ( F_31 ( V_23 , V_53 , & V_52 ) == 0 )
return ( int ) V_52 ;
else
return - V_13 ;
}
static int F_42 ( T_1 * V_54 )
{
T_8 V_52 ;
if ( F_31 ( V_54 , V_55 , & V_52 ) == 0 )
return ( int ) V_52 ;
else
return - V_13 ;
}
const char * F_43 ( T_1 * V_23 )
{
T_1 V_1 ;
T_2 * V_3 ;
int V_52 ;
V_52 = F_41 ( V_23 ) ;
if ( V_52 < 0 || ! F_44 ( V_23 , & V_1 , NULL , NULL ) ||
F_2 ( & V_1 , & V_3 , NULL ) != 0 )
return NULL ;
return F_3 ( V_3 , V_52 , NULL , NULL ) ;
}
T_1 * F_16 ( T_1 * V_56 ,
int (* F_14)( T_1 * , void * ) ,
void * V_14 , T_1 * V_15 )
{
T_1 V_57 ;
int V_7 ;
V_7 = F_45 ( V_56 , V_15 ) ;
if ( V_7 != 0 )
return NULL ;
do {
V_7 = F_14 ( V_15 , V_14 ) ;
if ( V_7 == V_58 )
return V_15 ;
if ( ( V_7 & V_59 ) &&
F_16 ( V_15 , F_14 , V_14 , & V_57 ) ) {
memcpy ( V_15 , & V_57 , sizeof( T_1 ) ) ;
return V_15 ;
}
} while ( ( V_7 & V_60 ) &&
F_46 ( V_15 , V_15 ) == 0 );
return NULL ;
}
static int F_47 ( T_1 * V_61 , void * V_14 )
{
struct V_62 * V_63 = V_14 ;
T_6 V_10 = 0 ;
if ( F_28 ( V_61 ) == V_40 &&
! F_48 ( V_61 , & V_10 ) &&
V_10 == V_63 -> V_10 ) {
memcpy ( V_63 -> V_15 , V_61 , sizeof( T_1 ) ) ;
return V_64 ;
}
return V_65 ;
}
T_1 * F_49 ( T_1 * V_1 , T_6 V_10 ,
T_1 * V_15 )
{
struct V_62 V_63 ;
V_63 . V_10 = V_10 ;
V_63 . V_15 = V_15 ;
if ( ! F_50 ( V_1 , F_47 , & V_63 , 0 ) )
return NULL ;
else
return V_15 ;
}
static int F_51 ( T_1 * V_61 , void * V_14 )
{
struct V_62 * V_63 = V_14 ;
if ( F_28 ( V_61 ) == V_40 &&
F_52 ( V_61 , V_63 -> V_10 ) ) {
memcpy ( V_63 -> V_15 , V_61 , sizeof( T_1 ) ) ;
return V_64 ;
}
return V_65 ;
}
T_1 * F_15 ( T_1 * V_1 , T_6 V_10 ,
T_1 * V_15 )
{
struct V_62 V_63 ;
V_63 . V_10 = V_10 ;
V_63 . V_15 = V_15 ;
if ( ! F_50 ( V_1 , F_51 , & V_63 , 0 ) )
return NULL ;
else
return V_15 ;
}
static int V_17 ( T_1 * V_15 , void * V_14 )
{
T_6 * V_10 = V_14 ;
if ( F_28 ( V_15 ) == V_66 &&
F_52 ( V_15 , * V_10 ) )
return V_58 ;
return V_67 ;
}
T_1 * F_53 ( T_1 * V_68 , T_6 V_10 ,
T_1 * V_15 )
{
return F_16 ( V_68 , V_17 , & V_10 , V_15 ) ;
}
T_1 * F_54 ( T_1 * V_68 , T_6 V_10 ,
T_1 * V_15 )
{
T_1 V_69 ;
V_68 = F_16 ( V_68 , V_17 , & V_10 , & V_69 ) ;
if ( ! V_68 )
return NULL ;
while ( V_68 ) {
memcpy ( V_15 , V_68 , sizeof( T_1 ) ) ;
V_68 = F_16 ( V_68 , V_17 , & V_10 ,
& V_69 ) ;
}
return V_15 ;
}
static int F_55 ( T_1 * V_70 , void * V_14 )
{
struct V_71 * V_72 = V_14 ;
T_4 V_73 ;
T_1 V_74 ;
T_4 * V_8 ;
T_1 * V_75 ;
int V_42 ;
V_8 = F_6 ( V_70 , V_76 , & V_73 ) ;
if ( V_8 == NULL )
return V_67 ;
V_75 = F_26 ( V_8 , & V_74 ) ;
if ( V_75 == NULL || V_75 -> V_10 != V_72 -> V_10 )
return V_67 ;
if ( F_28 ( V_70 ) == V_66 ) {
F_56 ( V_75 , & V_42 ) ;
if ( F_23 ( V_70 ) == V_42 ) {
V_42 = F_42 ( V_75 ) ;
if ( F_41 ( V_70 ) == V_42 )
return V_67 ;
}
}
V_72 -> V_77 = V_72 -> F_14 ( V_70 , V_72 -> V_14 ) ;
return ( V_72 -> V_77 ) ? V_58 : V_67 ;
}
int F_57 ( T_1 * V_78 , int (* F_14)( T_1 * , void * ) ,
void * V_14 )
{
T_1 V_1 ;
T_1 V_15 ;
struct V_71 V_72 = {
. V_10 = V_78 -> V_10 ,
. F_14 = F_14 ,
. V_14 = V_14 ,
. V_77 = - V_13 ,
} ;
if ( F_44 ( V_78 , & V_1 , NULL , NULL ) == NULL )
return - V_13 ;
F_16 ( & V_1 , F_55 , & V_72 , & V_15 ) ;
return V_72 . V_77 ;
}
static int F_58 ( T_1 * V_23 , void * V_14 )
{
struct V_79 * V_80 = V_14 ;
T_6 V_10 = 0 ;
const char * V_2 ;
int V_11 ;
if ( F_28 ( V_23 ) == V_66 ) {
V_2 = F_43 ( V_23 ) ;
V_11 = F_23 ( V_23 ) ;
if ( V_2 && V_11 > 0 && F_37 ( V_23 , & V_10 ) == 0 ) {
V_80 -> V_77 = V_80 -> F_14 ( V_2 , V_11 , V_10 , V_80 -> V_14 ) ;
if ( V_80 -> V_77 != 0 )
return V_58 ;
}
}
if ( ! V_80 -> V_81 )
return V_60 ;
if ( V_10 ) {
V_2 = F_59 ( V_23 ) ;
if ( V_2 && F_56 ( V_23 , & V_11 ) == 0 ) {
V_80 -> V_77 = V_80 -> F_14 ( V_2 , V_11 , V_10 , V_80 -> V_14 ) ;
if ( V_80 -> V_77 != 0 )
return V_58 ;
}
}
return V_67 ;
}
static int F_60 ( T_1 * V_68 , bool V_81 ,
T_10 F_14 , void * V_14 )
{
struct V_79 V_80 = {
. V_81 = V_81 ,
. F_14 = F_14 ,
. V_14 = V_14 ,
. V_77 = 0 ,
} ;
T_1 V_15 ;
T_6 V_10 ;
const char * V_2 ;
int V_11 ;
V_2 = F_59 ( V_68 ) ;
if ( V_2 && F_56 ( V_68 , & V_11 ) == 0 &&
F_37 ( V_68 , & V_10 ) == 0 ) {
V_80 . V_77 = F_14 ( V_2 , V_11 , V_10 , V_14 ) ;
if ( V_80 . V_77 != 0 )
goto V_82;
}
F_16 ( V_68 , F_58 , & V_80 , & V_15 ) ;
V_82:
return V_80 . V_77 ;
}
static int F_61 ( T_1 * V_68 , void * V_14 )
{
struct V_79 * V_80 = V_14 ;
V_80 -> V_77 = F_60 ( V_68 , true , V_80 -> F_14 , V_80 -> V_14 ) ;
if ( V_80 -> V_77 != 0 )
return V_64 ;
return V_65 ;
}
int F_62 ( T_1 * V_56 , T_10 F_14 , void * V_14 )
{
T_11 * V_83 ;
T_5 * line ;
T_6 V_10 ;
const char * V_2 , * V_84 = NULL ;
int V_11 , V_7 = 0 ;
int V_85 = 0 , V_86 ;
T_1 V_15 , * V_1 ;
T_3 V_87 , V_5 ;
if ( F_28 ( V_56 ) != V_88 ) {
V_1 = F_44 ( V_56 , & V_15 , NULL , NULL ) ;
F_56 ( V_56 , & V_85 ) ;
V_84 = F_59 ( V_56 ) ;
} else
V_1 = V_56 ;
if ( ! V_1 ) {
F_63 ( L_2 ) ;
return - V_89 ;
}
if ( F_64 ( V_1 , & V_83 , & V_87 ) != 0 ) {
F_63 ( L_3 ) ;
return - V_13 ;
}
F_63 ( L_4 , V_87 ) ;
for ( V_5 = 0 ; V_5 < V_87 ; V_5 ++ ) {
line = F_65 ( V_83 , V_5 ) ;
if ( line == NULL ||
F_11 ( line , & V_11 ) != 0 ||
F_10 ( line , & V_10 ) != 0 ) {
F_63 ( L_5
L_6 ) ;
continue;
}
if ( V_56 != V_1 ) {
if ( ! F_52 ( V_56 , V_10 ) )
continue;
if ( F_54 ( V_56 , V_10 , & V_15 ) ) {
F_56 ( & V_15 , & V_86 ) ;
if ( V_86 != V_85 ||
V_84 != F_59 ( & V_15 ) )
continue;
}
}
V_2 = F_12 ( line , NULL , NULL ) ;
V_7 = F_14 ( V_2 , V_11 , V_10 , V_14 ) ;
if ( V_7 != 0 )
return V_7 ;
}
if ( V_56 != V_1 )
V_7 = F_60 ( V_56 , false , F_14 , V_14 ) ;
else {
struct V_79 V_90 = {
. F_14 = F_14 ,
. V_14 = V_14 ,
. V_77 = 0 ,
} ;
F_50 ( V_1 , F_61 , & V_90 , 0 ) ;
V_7 = V_90 . V_77 ;
}
return V_7 ;
}
static int F_66 ( T_1 * V_15 , void * V_14 )
{
struct V_91 * V_92 = V_14 ;
T_4 V_8 ;
int V_27 ;
V_27 = F_28 ( V_15 ) ;
if ( ( V_27 == V_93 ||
V_27 == V_94 ) &&
F_19 ( V_15 , V_92 -> V_21 ) &&
( F_6 ( V_15 , V_95 , & V_8 ) ||
F_6 ( V_15 , V_96 , & V_8 ) ) )
return V_58 ;
if ( F_52 ( V_15 , V_92 -> V_10 ) )
return V_67 ;
else
return V_60 ;
}
T_1 * F_67 ( T_1 * V_68 , const char * V_21 ,
T_6 V_10 , T_1 * V_15 )
{
struct V_91 V_92 = { . V_21 = V_21 , . V_10 = V_10 } ;
return F_16 ( V_68 , F_66 , ( void * ) & V_92 ,
V_15 ) ;
}
static int F_68 ( T_1 * V_15 , void * V_14 )
{
const char * V_21 = V_14 ;
if ( F_28 ( V_15 ) == V_97 ) {
if ( F_19 ( V_15 , V_21 ) )
return V_58 ;
else if ( ! F_20 ( V_15 ) ) {
T_1 V_98 , V_69 ;
if ( F_25 ( V_15 , & V_98 ) &&
F_69 ( & V_98 , V_21 , & V_69 ) )
return V_58 ;
}
}
return V_60 ;
}
T_1 * F_69 ( T_1 * V_99 , const char * V_21 ,
T_1 * V_15 )
{
return F_16 ( V_99 , F_68 , ( void * ) V_21 ,
V_15 ) ;
}
int F_70 ( T_1 * V_25 , struct V_100 * V_101 )
{
T_1 type ;
int V_27 , V_7 ;
const char * V_42 = L_7 ;
if ( F_27 ( V_25 , & type ) == NULL )
return - V_13 ;
V_27 = F_28 ( & type ) ;
if ( V_27 == V_102 || V_27 == V_103 )
V_42 = L_8 ;
else if ( V_27 == V_104 ) {
return F_71 ( V_101 , L_9 , 15 ) ;
} else {
if ( ! F_20 ( & type ) )
return - V_13 ;
if ( V_27 == V_105 )
V_42 = L_10 ;
else if ( V_27 == V_106 )
V_42 = L_11 ;
else if ( V_27 == V_107 )
V_42 = L_12 ;
return F_72 ( V_101 , L_13 , V_42 , F_20 ( & type ) ) ;
}
V_7 = F_70 ( & type , V_101 ) ;
return V_7 ? V_7 : F_73 ( V_101 , V_42 ) ;
}
int F_74 ( T_1 * V_25 , struct V_100 * V_101 )
{
int V_7 ;
V_7 = F_70 ( V_25 , V_101 ) ;
if ( V_7 < 0 ) {
F_40 ( L_14 ) ;
V_7 = F_71 ( V_101 , L_15 , 14 ) ;
}
return V_7 < 0 ? V_7 : F_72 ( V_101 , L_16 , F_20 ( V_25 ) ) ;
}
static int F_75 ( T_1 * V_68 , T_1 * V_25 ,
struct V_100 * V_101 )
{
T_1 * V_108 ;
int V_109 ;
T_3 V_110 = 0 ;
T_6 V_111 ;
T_6 V_112 , V_113 ;
T_6 V_114 ;
int V_7 ;
bool V_115 = true ;
const char * V_21 ;
V_7 = F_37 ( V_68 , & V_114 ) ;
if ( V_7 )
return V_7 ;
V_21 = F_20 ( V_68 ) ;
if ( ! V_21 )
return - V_13 ;
V_109 = F_76 ( V_25 , & V_108 ) ;
if ( V_109 <= 1 ) {
V_7 = - V_89 ;
goto V_116;
}
while ( ( V_110 = F_77 ( & V_108 [ 1 ] , V_110 , & V_111 ,
& V_112 , & V_113 ) ) > 0 ) {
V_112 -= V_114 ;
V_113 -= V_114 ;
if ( V_115 ) {
V_7 = F_72 ( V_101 , L_17 V_117 L_18 V_117 ,
V_21 , V_112 , V_113 ) ;
V_115 = false ;
} else {
V_7 = F_72 ( V_101 , L_19 V_117 L_18 V_117 ,
V_112 , V_113 ) ;
}
if ( V_7 < 0 )
goto V_116;
}
if ( ! V_115 )
V_7 = F_71 ( V_101 , L_20 , 2 ) ;
V_116:
free ( V_108 ) ;
return V_7 ;
}
int F_78 ( T_1 * V_68 , T_1 * V_25 , struct V_100 * V_101 )
{
int V_7 = 0 ;
T_6 V_111 ;
T_6 V_112 , V_113 ;
T_6 V_114 ;
T_9 * V_118 ;
T_3 V_119 ;
T_3 V_110 = 0 ;
T_4 V_8 ;
bool V_115 = true ;
const char * V_21 ;
V_7 = F_37 ( V_68 , & V_114 ) ;
if ( V_7 )
return V_7 ;
V_21 = F_20 ( V_68 ) ;
if ( ! V_21 )
return - V_13 ;
if ( F_6 ( V_25 , V_96 , & V_8 ) == NULL )
return - V_89 ;
while ( ( V_110 = F_79 ( & V_8 , V_110 , & V_111 ,
& V_112 , & V_113 , & V_118 , & V_119 ) ) > 0 ) {
if ( V_112 == 0 ) {
V_7 = F_75 ( V_68 , V_25 , V_101 ) ;
goto V_116;
}
V_112 -= V_114 ;
V_113 -= V_114 ;
if ( V_115 ) {
V_7 = F_72 ( V_101 , L_17 V_117 L_18 V_117 ,
V_21 , V_112 , V_113 ) ;
V_115 = false ;
} else {
V_7 = F_72 ( V_101 , L_19 V_117 L_18 V_117 ,
V_112 , V_113 ) ;
}
if ( V_7 < 0 )
goto V_116;
}
if ( ! V_115 )
V_7 = F_71 ( V_101 , L_20 , 2 ) ;
V_116:
return V_7 ;
}
int F_78 ( T_1 * V_68 V_120 ,
T_1 * V_25 V_120 ,
struct V_100 * V_101 V_120 )
{
return - V_50 ;
}
static bool F_80 ( T_1 * V_25 )
{
T_4 V_121 ;
int V_27 = F_28 ( V_25 ) ;
if ( V_27 != V_93 &&
V_27 != V_94 )
return false ;
return ( F_18 ( V_25 , V_96 , & V_121 ) &&
F_81 ( & V_121 ) == V_122 ) ;
}
bool F_82 ( T_1 * V_1 )
{
T_1 V_69 ;
if ( F_80 ( V_1 ) )
return true ;
if ( ! F_45 ( V_1 , & V_69 ) &&
F_82 ( & V_69 ) )
return true ;
if ( ! F_46 ( V_1 , & V_69 ) &&
F_82 ( & V_69 ) )
return true ;
return false ;
}
static bool F_83 ( T_11 * V_83 , unsigned long V_123 ,
T_6 V_10 , unsigned long * V_52 )
{
unsigned long V_5 ;
T_6 V_42 ;
for ( V_5 = 0 ; V_5 < V_123 ; V_5 ++ ) {
if ( F_10 ( F_65 ( V_83 , V_5 ) , & V_42 ) )
return false ;
if ( V_42 == V_10 ) {
* V_52 = V_5 ;
return true ;
}
}
return false ;
}
static bool F_84 ( unsigned long V_124 ,
T_11 * V_83 ,
unsigned long V_123 ,
T_6 V_125 ,
T_6 * V_126 )
{
unsigned long V_5 ;
int V_127 , V_128 ;
T_5 * line ;
T_6 V_10 ;
bool V_129 ;
line = F_65 ( V_83 , V_124 ) ;
if ( F_11 ( line , & V_127 ) )
return false ;
for ( V_5 = V_124 ; V_5 < V_123 ; V_5 ++ ) {
line = F_65 ( V_83 , V_5 ) ;
if ( F_10 ( line , & V_10 ) ||
F_11 ( line , & V_128 ) ||
F_85 ( line , & V_129 ) )
return false ;
if ( V_10 >= V_125 )
break;
if ( V_129 )
break;
if ( V_128 != V_127 )
break;
if ( V_5 != V_124 )
break;
}
F_10 ( line , V_126 ) ;
if ( * V_126 >= V_125 )
F_10 ( F_65 ( V_83 , V_5 - 1 ) ,
V_126 ) ;
return true ;
}
void F_86 ( T_1 * V_68 , T_1 * V_1 ,
T_6 * V_130 )
{
T_3 V_123 = 0 ;
unsigned long V_124 = 0 ;
T_11 * V_83 = NULL ;
T_6 V_126 ;
T_6 V_125 ;
if ( F_48 ( V_68 , & V_125 ) )
return;
if ( F_64 ( V_1 , & V_83 , & V_123 ) )
return;
if ( ! F_83 ( V_83 , V_123 , * V_130 , & V_124 ) )
return;
if ( ! F_84 ( V_124 , V_83 , V_123 ,
V_125 , & V_126 ) )
return;
* V_130 = V_126 ;
}
