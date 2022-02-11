T_1 * F_1 ( void )
{
return ( F_2 ( NULL ) ) ;
}
T_1 * F_2 ( const T_2 * V_1 )
{
T_1 * V_2 = F_3 ( sizeof( * V_2 ) ) ;
if ( V_2 == NULL ) {
F_4 ( V_3 , V_4 ) ;
return NULL ;
}
V_2 -> V_5 = F_5 () ;
if ( V_2 -> V_5 == NULL ) {
F_4 ( V_3 , V_4 ) ;
F_6 ( V_2 ) ;
return NULL ;
}
if ( V_1 == NULL )
V_2 -> V_6 = F_7 () ;
else
V_2 -> V_6 = V_1 ;
if ( ! F_8 ( V_7 , V_2 , & V_2 -> V_8 ) ) {
F_6 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
static void F_9 ( T_3 * V_9 )
{
if ( V_9 -> V_10 & V_11 ) {
F_6 ( ( char * ) V_9 -> V_12 ) ;
switch ( V_9 -> type ) {
case V_13 :
F_6 ( ( char * ) V_9 -> _ . V_14 . V_15 ) ;
F_6 ( ( char * ) V_9 -> _ . V_14 . V_16 ) ;
F_6 ( ( char * ) V_9 -> _ . V_14 . V_17 ) ;
break;
default:
break;
}
}
F_6 ( V_9 ) ;
}
void F_10 ( T_1 * V_18 )
{
if ( V_18 == NULL )
return;
F_11 ( V_18 -> V_19 , F_9 ) ;
F_12 ( V_7 , V_18 , & V_18 -> V_8 ) ;
F_13 ( V_18 -> V_5 ) ;
F_6 ( V_18 ) ;
}
static int F_14 ( T_1 * V_18 )
{
if ( V_18 -> V_19 == NULL ) {
V_18 -> V_19 = F_15 () ;
if ( V_18 -> V_19 == NULL ) {
return - 1 ;
}
}
return 0 ;
}
static T_3 * F_16 ( T_1 * V_18 , const char * V_20 ,
int V_21 ,
enum V_22 type ,
int V_23 , char * V_24 )
{
T_3 * V_2 = NULL ;
if ( V_20 == NULL ) {
F_4 ( V_25 , V_26 ) ;
} else if ( ( type == V_27 || type == V_28
|| type == V_13 ) && V_24 == NULL ) {
F_4 ( V_25 , V_29 ) ;
} else if ( ( V_2 = F_17 ( sizeof( * V_2 ) ) ) != NULL ) {
V_2 -> V_12 = V_20 ;
V_2 -> V_10 = V_21 ? V_11 : 0 ;
V_2 -> V_23 = V_23 ;
V_2 -> type = type ;
V_2 -> V_24 = V_24 ;
}
return V_2 ;
}
static int F_18 ( T_1 * V_18 , const char * V_20 ,
int V_21 ,
enum V_22 type , int V_23 ,
char * V_24 , int V_30 , int V_31 ,
const char * V_32 )
{
int V_2 = - 1 ;
T_3 * V_33 = F_16 ( V_18 , V_20 , V_21 ,
type , V_23 , V_24 ) ;
if ( V_33 ) {
if ( F_14 ( V_18 ) >= 0 ) {
V_33 -> _ . V_34 . V_35 = V_30 ;
V_33 -> _ . V_34 . V_36 = V_31 ;
V_33 -> _ . V_34 . V_32 = V_32 ;
V_2 = F_19 ( V_18 -> V_19 , V_33 ) ;
if ( V_2 <= 0 ) {
V_2 -- ;
F_9 ( V_33 ) ;
}
} else
F_9 ( V_33 ) ;
}
return V_2 ;
}
static int F_20 ( T_1 * V_18 ,
const char * V_20 ,
const char * V_15 ,
const char * V_16 ,
const char * V_17 ,
int V_21 ,
enum V_22 type ,
int V_23 , char * V_24 )
{
int V_2 = - 1 ;
T_3 * V_33 ;
const char * V_37 ;
if ( V_16 == NULL ) {
F_4 ( V_38 , V_26 ) ;
} else if ( V_17 == NULL ) {
F_4 ( V_38 , V_26 ) ;
} else {
for ( V_37 = V_16 ; * V_37 ; V_37 ++ ) {
if ( strchr ( V_17 , * V_37 ) ) {
F_4 ( V_38 ,
V_39 ) ;
}
}
V_33 = F_16 ( V_18 , V_20 , V_21 ,
type , V_23 , V_24 ) ;
if ( V_33 ) {
if ( F_14 ( V_18 ) >= 0 ) {
V_33 -> _ . V_14 . V_15 = V_15 ;
V_33 -> _ . V_14 . V_16 = V_16 ;
V_33 -> _ . V_14 . V_17 = V_17 ;
V_2 = F_19 ( V_18 -> V_19 , V_33 ) ;
if ( V_2 <= 0 ) {
V_2 -- ;
F_9 ( V_33 ) ;
}
} else
F_9 ( V_33 ) ;
}
}
return V_2 ;
}
int F_21 ( T_1 * V_18 , const char * V_20 , int V_10 ,
char * V_24 , int V_30 , int V_31 )
{
return F_18 ( V_18 , V_20 , 0 ,
V_27 , V_10 , V_24 , V_30 ,
V_31 , NULL ) ;
}
int F_22 ( T_1 * V_18 , const char * V_20 , int V_10 ,
char * V_24 , int V_30 , int V_31 )
{
char * V_40 = NULL ;
if ( V_20 ) {
V_40 = F_23 ( V_20 ) ;
if ( V_40 == NULL ) {
F_4 ( V_41 , V_4 ) ;
return 0 ;
}
}
return F_18 ( V_18 , V_40 , 1 ,
V_27 , V_10 , V_24 , V_30 ,
V_31 , NULL ) ;
}
int F_24 ( T_1 * V_18 , const char * V_20 , int V_10 ,
char * V_24 , int V_30 , int V_31 ,
const char * V_32 )
{
return F_18 ( V_18 , V_20 , 0 ,
V_28 , V_10 , V_24 , V_30 ,
V_31 , V_32 ) ;
}
int F_25 ( T_1 * V_18 , const char * V_20 , int V_10 ,
char * V_24 , int V_30 , int V_31 ,
const char * V_32 )
{
char * V_40 = NULL ;
if ( V_20 ) {
V_40 = F_23 ( V_20 ) ;
if ( V_40 == NULL ) {
F_4 ( V_42 , V_4 ) ;
return - 1 ;
}
}
return F_18 ( V_18 , V_40 , 1 ,
V_28 , V_10 , V_24 , V_30 ,
V_31 , V_32 ) ;
}
int F_26 ( T_1 * V_18 , const char * V_20 , const char * V_15 ,
const char * V_16 , const char * V_17 ,
int V_10 , char * V_24 )
{
return F_20 ( V_18 , V_20 , V_15 ,
V_16 , V_17 , 0 , V_13 ,
V_10 , V_24 ) ;
}
int F_27 ( T_1 * V_18 , const char * V_20 , const char * V_15 ,
const char * V_16 , const char * V_17 ,
int V_10 , char * V_24 )
{
char * V_40 = NULL ;
char * V_43 = NULL ;
char * V_44 = NULL ;
char * V_45 = NULL ;
if ( V_20 ) {
V_40 = F_23 ( V_20 ) ;
if ( V_40 == NULL ) {
F_4 ( V_46 , V_4 ) ;
goto V_47;
}
}
if ( V_15 ) {
V_43 = F_23 ( V_15 ) ;
if ( V_43 == NULL ) {
F_4 ( V_46 , V_4 ) ;
goto V_47;
}
}
if ( V_16 ) {
V_44 = F_23 ( V_16 ) ;
if ( V_44 == NULL ) {
F_4 ( V_46 , V_4 ) ;
goto V_47;
}
}
if ( V_17 ) {
V_45 = F_23 ( V_17 ) ;
if ( V_45 == NULL ) {
F_4 ( V_46 , V_4 ) ;
goto V_47;
}
}
return F_20 ( V_18 , V_40 , V_43 ,
V_44 , V_45 , 1 ,
V_13 , V_10 , V_24 ) ;
V_47:
F_6 ( V_40 ) ;
F_6 ( V_43 ) ;
F_6 ( V_44 ) ;
F_6 ( V_45 ) ;
return - 1 ;
}
int F_28 ( T_1 * V_18 , const char * V_48 )
{
return F_18 ( V_18 , V_48 , 0 , V_49 , 0 , NULL , 0 , 0 ,
NULL ) ;
}
int F_29 ( T_1 * V_18 , const char * V_48 )
{
char * V_50 = NULL ;
if ( V_48 ) {
V_50 = F_23 ( V_48 ) ;
if ( V_50 == NULL ) {
F_4 ( V_51 , V_4 ) ;
return - 1 ;
}
}
return F_18 ( V_18 , V_50 , 1 , V_49 , 0 , NULL ,
0 , 0 , NULL ) ;
}
int F_30 ( T_1 * V_18 , const char * V_48 )
{
return F_18 ( V_18 , V_48 , 0 , V_52 , 0 , NULL , 0 , 0 ,
NULL ) ;
}
int F_31 ( T_1 * V_18 , const char * V_48 )
{
char * V_50 = NULL ;
if ( V_48 ) {
V_50 = F_23 ( V_48 ) ;
if ( V_50 == NULL ) {
F_4 ( V_53 , V_4 ) ;
return - 1 ;
}
}
return F_18 ( V_18 , V_50 , 1 , V_52 , 0 , NULL ,
0 , 0 , NULL ) ;
}
char * F_32 ( T_1 * V_18 , const char * V_54 ,
const char * V_55 )
{
char * V_20 = NULL ;
if ( V_18 -> V_6 -> V_56 )
V_20 = V_18 -> V_6 -> V_56 ( V_18 , V_54 , V_55 ) ;
else {
char V_57 [] = L_1 ;
char V_58 [] = L_2 ;
char V_59 [] = L_3 ;
int V_60 = 0 ;
if ( V_54 == NULL )
return NULL ;
V_60 = sizeof( V_57 ) - 1 + strlen ( V_54 ) ;
if ( V_55 )
V_60 += sizeof( V_58 ) - 1 + strlen ( V_55 ) ;
V_60 += sizeof( V_59 ) - 1 ;
V_20 = F_17 ( V_60 + 1 ) ;
if ( V_20 == NULL )
return NULL ;
F_33 ( V_20 , V_57 , V_60 + 1 ) ;
F_34 ( V_20 , V_54 , V_60 + 1 ) ;
if ( V_55 ) {
F_34 ( V_20 , V_58 , V_60 + 1 ) ;
F_34 ( V_20 , V_55 , V_60 + 1 ) ;
}
F_34 ( V_20 , V_59 , V_60 + 1 ) ;
}
return V_20 ;
}
void * F_35 ( T_1 * V_18 , void * V_61 )
{
void * V_62 = V_18 -> V_61 ;
V_18 -> V_61 = V_61 ;
return V_62 ;
}
void * F_36 ( T_1 * V_18 )
{
return V_18 -> V_61 ;
}
const char * F_37 ( T_1 * V_18 , int V_63 )
{
if ( V_63 < 0 ) {
F_4 ( V_64 , V_65 ) ;
return NULL ;
}
if ( V_63 >= F_38 ( V_18 -> V_19 ) ) {
F_4 ( V_64 , V_66 ) ;
return NULL ;
}
return F_39 ( F_40 ( V_18 -> V_19 , V_63 ) ) ;
}
static int F_41 ( const char * V_67 , T_4 V_60 , T_1 * V_18 )
{
T_3 V_9 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . type = V_52 ;
V_9 . V_12 = V_67 ;
if ( V_18 -> V_6 -> V_68 && ! V_18 -> V_6 -> V_68 ( V_18 , & V_9 ) )
return - 1 ;
return 0 ;
}
int F_42 ( T_1 * V_18 )
{
int V_63 , V_69 = 0 ;
if ( V_18 -> V_6 -> V_70 && ! V_18 -> V_6 -> V_70 ( V_18 ) )
return - 1 ;
if ( V_18 -> V_10 & V_71 )
F_43 ( ( int ( * ) ( const char * , T_4 , void * ) )
F_41 , ( void * ) V_18 ) ;
for ( V_63 = 0 ; V_63 < F_38 ( V_18 -> V_19 ) ; V_63 ++ ) {
if ( V_18 -> V_6 -> V_68
&& ! V_18 -> V_6 -> V_68 ( V_18 ,
F_40 ( V_18 -> V_19 , V_63 ) ) )
{
V_69 = - 1 ;
goto V_47;
}
}
if ( V_18 -> V_6 -> V_72 )
switch ( V_18 -> V_6 -> V_72 ( V_18 ) ) {
case - 1 :
V_69 = - 2 ;
goto V_47;
case 0 :
V_69 = - 1 ;
goto V_47;
default:
V_69 = 0 ;
break;
}
for ( V_63 = 0 ; V_63 < F_38 ( V_18 -> V_19 ) ; V_63 ++ ) {
if ( V_18 -> V_6 -> V_73 ) {
switch ( V_18 -> V_6 -> V_73 ( V_18 ,
F_40 ( V_18 -> V_19 ,
V_63 ) ) ) {
case - 1 :
V_69 = - 2 ;
goto V_47;
case 0 :
V_69 = - 1 ;
goto V_47;
default:
V_69 = 0 ;
break;
}
}
}
V_47:
if ( V_18 -> V_6 -> V_74 && ! V_18 -> V_6 -> V_74 ( V_18 ) )
return - 1 ;
return V_69 ;
}
int F_44 ( T_1 * V_18 , int V_75 , long V_63 , void * V_37 , void (* F_45) ( void ) )
{
if ( V_18 == NULL ) {
F_4 ( V_76 , V_26 ) ;
return - 1 ;
}
switch ( V_75 ) {
case V_77 :
{
int V_78 = ! ! ( V_18 -> V_10 & V_71 ) ;
if ( V_63 )
V_18 -> V_10 |= V_71 ;
else
V_18 -> V_10 &= ~ V_71 ;
return V_78 ;
}
case V_79 :
return ! ! ( V_18 -> V_10 & V_80 ) ;
default:
break;
}
F_4 ( V_76 , V_81 ) ;
return - 1 ;
}
int F_46 ( T_1 * V_82 , int V_83 , void * V_84 )
{
return ( F_47 ( & V_82 -> V_8 , V_83 , V_84 ) ) ;
}
void * F_48 ( T_1 * V_82 , int V_83 )
{
return ( F_49 ( & V_82 -> V_8 , V_83 ) ) ;
}
void F_50 ( const T_2 * V_6 )
{
V_85 = V_6 ;
}
const T_2 * F_7 ( void )
{
if ( V_85 == NULL ) {
V_85 = F_51 () ;
}
return V_85 ;
}
const T_2 * F_52 ( T_1 * V_18 )
{
return V_18 -> V_6 ;
}
const T_2 * F_53 ( T_1 * V_18 , const T_2 * V_6 )
{
V_18 -> V_6 = V_6 ;
return V_18 -> V_6 ;
}
T_2 * F_54 ( const char * V_86 )
{
T_2 * V_87 = F_3 ( sizeof( * V_87 ) ) ;
if ( V_87 != NULL ) {
V_87 -> V_86 = F_23 ( V_86 ) ;
if ( V_87 -> V_86 == NULL ) {
F_6 ( V_87 ) ;
F_4 ( V_88 , V_4 ) ;
return NULL ;
}
}
return V_87 ;
}
void F_55 ( T_2 * V_87 )
{
F_6 ( V_87 -> V_86 ) ;
V_87 -> V_86 = NULL ;
F_6 ( V_87 ) ;
}
int F_56 ( T_2 * V_1 , int (* F_57) ( T_1 * V_18 ) )
{
if ( V_1 ) {
V_1 -> V_70 = F_57 ;
return 0 ;
} else
return - 1 ;
}
int F_58 ( T_2 * V_1 ,
int (* F_59) ( T_1 * V_18 , T_3 * V_9 ) )
{
if ( V_1 ) {
V_1 -> V_68 = F_59 ;
return 0 ;
} else
return - 1 ;
}
int F_60 ( T_2 * V_1 , int (* F_61) ( T_1 * V_18 ) )
{
if ( V_1 ) {
V_1 -> V_72 = F_61 ;
return 0 ;
} else
return - 1 ;
}
int F_62 ( T_2 * V_1 ,
int (* F_63) ( T_1 * V_18 , T_3 * V_9 ) )
{
if ( V_1 ) {
V_1 -> V_73 = F_63 ;
return 0 ;
} else
return - 1 ;
}
int F_64 ( T_2 * V_1 , int (* F_65) ( T_1 * V_18 ) )
{
if ( V_1 ) {
V_1 -> V_74 = F_65 ;
return 0 ;
} else
return - 1 ;
}
int F_66 ( T_2 * V_1 ,
char * (* F_67) ( T_1 * V_18 ,
const char
* V_54 ,
const char
* V_55 ) )
{
if ( V_1 ) {
V_1 -> V_56 = F_67 ;
return 0 ;
} else
return - 1 ;
}
enum V_22 F_68 ( T_3 * V_9 )
{
if ( ! V_9 )
return V_89 ;
return V_9 -> type ;
}
int F_69 ( T_3 * V_9 )
{
if ( ! V_9 )
return 0 ;
return V_9 -> V_23 ;
}
const char * F_70 ( T_3 * V_9 )
{
if ( ! V_9 )
return NULL ;
return V_9 -> V_12 ;
}
const char * F_71 ( T_3 * V_9 )
{
if ( ! V_9 )
return NULL ;
switch ( V_9 -> type ) {
case V_27 :
case V_13 :
return V_9 -> _ . V_14 . V_15 ;
default:
return NULL ;
}
}
const char * F_39 ( T_3 * V_9 )
{
if ( ! V_9 )
return NULL ;
switch ( V_9 -> type ) {
case V_27 :
case V_28 :
return V_9 -> V_24 ;
default:
return NULL ;
}
}
const char * F_72 ( T_3 * V_9 )
{
if ( ! V_9 )
return NULL ;
switch ( V_9 -> type ) {
case V_28 :
return V_9 -> _ . V_34 . V_32 ;
default:
return NULL ;
}
}
int F_73 ( T_3 * V_9 )
{
if ( ! V_9 )
return - 1 ;
switch ( V_9 -> type ) {
case V_27 :
case V_28 :
return V_9 -> _ . V_34 . V_35 ;
default:
return - 1 ;
}
}
int F_74 ( T_3 * V_9 )
{
if ( ! V_9 )
return - 1 ;
switch ( V_9 -> type ) {
case V_27 :
case V_28 :
return V_9 -> _ . V_34 . V_36 ;
default:
return - 1 ;
}
}
int F_75 ( T_1 * V_18 , T_3 * V_9 , const char * V_90 )
{
int V_91 = strlen ( V_90 ) ;
V_18 -> V_10 &= ~ V_80 ;
if ( ! V_9 )
return - 1 ;
switch ( V_9 -> type ) {
case V_27 :
case V_28 :
{
char V_92 [ F_76 ( V_9 -> _ . V_34 . V_35 ) + 1 ] ;
char V_93 [ F_76 ( V_9 -> _ . V_34 . V_36 ) + 1 ] ;
F_77 ( V_92 , sizeof( V_92 ) , L_4 ,
V_9 -> _ . V_34 . V_35 ) ;
F_77 ( V_93 , sizeof( V_93 ) , L_4 ,
V_9 -> _ . V_34 . V_36 ) ;
if ( V_91 < V_9 -> _ . V_34 . V_35 ) {
V_18 -> V_10 |= V_80 ;
F_4 ( V_94 , V_95 ) ;
F_78 ( 5 , L_5 ,
V_92 , L_6 , V_93 , L_7 ) ;
return - 1 ;
}
if ( V_91 > V_9 -> _ . V_34 . V_36 ) {
V_18 -> V_10 |= V_80 ;
F_4 ( V_94 , V_96 ) ;
F_78 ( 5 , L_5 ,
V_92 , L_6 , V_93 , L_7 ) ;
return - 1 ;
}
}
if ( ! V_9 -> V_24 ) {
F_4 ( V_94 , V_29 ) ;
return - 1 ;
}
F_33 ( V_9 -> V_24 , V_90 ,
V_9 -> _ . V_34 . V_36 + 1 ) ;
break;
case V_13 :
{
const char * V_37 ;
if ( ! V_9 -> V_24 ) {
F_4 ( V_94 , V_29 ) ;
return - 1 ;
}
V_9 -> V_24 [ 0 ] = '\0' ;
for ( V_37 = V_90 ; * V_37 ; V_37 ++ ) {
if ( strchr ( V_9 -> _ . V_14 . V_16 , * V_37 ) ) {
V_9 -> V_24 [ 0 ] = V_9 -> _ . V_14 . V_16 [ 0 ] ;
break;
}
if ( strchr ( V_9 -> _ . V_14 . V_17 , * V_37 ) ) {
V_9 -> V_24 [ 0 ] = V_9 -> _ . V_14 . V_17 [ 0 ] ;
break;
}
}
}
default:
break;
}
return 0 ;
}
