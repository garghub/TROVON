T_1 * F_1 ( void )
{
return ( F_2 ( NULL ) ) ;
}
T_1 * F_2 ( const T_2 * V_1 )
{
T_1 * V_2 ;
V_2 = ( T_1 * ) F_3 ( sizeof( T_1 ) ) ;
if ( V_2 == NULL )
{
F_4 ( V_3 , V_4 ) ;
return NULL ;
}
if ( V_1 == NULL )
V_2 -> V_5 = F_5 () ;
else
V_2 -> V_5 = V_1 ;
V_2 -> V_6 = NULL ;
V_2 -> V_7 = NULL ;
F_6 ( V_8 , V_2 , & V_2 -> V_9 ) ;
return V_2 ;
}
static void F_7 ( T_3 * V_10 )
{
if ( V_10 -> V_11 & V_12 )
{
F_8 ( ( char * ) V_10 -> V_13 ) ;
switch( V_10 -> type )
{
case V_14 :
F_8 ( ( char * ) V_10 -> _ . V_15 . V_16 ) ;
F_8 ( ( char * ) V_10 -> _ . V_15 . V_17 ) ;
F_8 ( ( char * ) V_10 -> _ . V_15 . V_18 ) ;
break;
default:
break;
}
}
F_8 ( V_10 ) ;
}
void F_9 ( T_1 * V_19 )
{
if ( V_19 == NULL )
return;
F_10 ( V_19 -> V_6 , F_7 ) ;
F_11 ( V_8 , V_19 , & V_19 -> V_9 ) ;
F_8 ( V_19 ) ;
}
static int F_12 ( T_1 * V_19 )
{
if ( V_19 -> V_6 == NULL )
{
V_19 -> V_6 = F_13 () ;
if ( V_19 -> V_6 == NULL )
{
return - 1 ;
}
}
return 0 ;
}
static T_3 * F_14 ( T_1 * V_19 , const char * V_20 ,
int V_21 , enum V_22 type , int V_23 ,
char * V_24 )
{
T_3 * V_2 = NULL ;
if ( V_20 == NULL )
{
F_4 ( V_25 , V_26 ) ;
}
else if ( ( type == V_27 || type == V_28
|| type == V_14 ) && V_24 == NULL )
{
F_4 ( V_25 , V_29 ) ;
}
else if ( ( V_2 = ( T_3 * ) F_3 ( sizeof( T_3 ) ) ) )
{
V_2 -> V_13 = V_20 ;
V_2 -> V_11 = V_21 ? V_12 : 0 ;
V_2 -> V_23 = V_23 ;
V_2 -> type = type ;
V_2 -> V_24 = V_24 ;
}
return V_2 ;
}
static int F_15 ( T_1 * V_19 , const char * V_20 ,
int V_21 , enum V_22 type , int V_23 ,
char * V_24 , int V_30 , int V_31 , const char * V_32 )
{
int V_2 = - 1 ;
T_3 * V_33 = F_14 ( V_19 , V_20 , V_21 ,
type , V_23 , V_24 ) ;
if ( V_33 )
{
if ( F_12 ( V_19 ) >= 0 )
{
V_33 -> _ . V_34 . V_35 = V_30 ;
V_33 -> _ . V_34 . V_36 = V_31 ;
V_33 -> _ . V_34 . V_32 = V_32 ;
V_2 = F_16 ( V_19 -> V_6 , V_33 ) ;
if ( V_2 <= 0 ) V_2 -- ;
}
else
F_7 ( V_33 ) ;
}
return V_2 ;
}
static int F_17 ( T_1 * V_19 ,
const char * V_20 , const char * V_16 ,
const char * V_17 , const char * V_18 ,
int V_21 , enum V_22 type , int V_23 ,
char * V_24 )
{
int V_2 = - 1 ;
T_3 * V_33 ;
const char * V_37 ;
if ( V_17 == NULL )
{
F_4 ( V_38 , V_26 ) ;
}
else if ( V_18 == NULL )
{
F_4 ( V_38 , V_26 ) ;
}
else
{
for( V_37 = V_17 ; * V_37 ; V_37 ++ )
{
if ( strchr ( V_18 , * V_37 ) )
{
F_4 ( V_38 ,
V_39 ) ;
}
}
V_33 = F_14 ( V_19 , V_20 , V_21 ,
type , V_23 , V_24 ) ;
if ( V_33 )
{
if ( F_12 ( V_19 ) >= 0 )
{
V_33 -> _ . V_15 . V_16 = V_16 ;
V_33 -> _ . V_15 . V_17 = V_17 ;
V_33 -> _ . V_15 . V_18 = V_18 ;
V_2 = F_16 ( V_19 -> V_6 , V_33 ) ;
if ( V_2 <= 0 ) V_2 -- ;
}
else
F_7 ( V_33 ) ;
}
}
return V_2 ;
}
int F_18 ( T_1 * V_19 , const char * V_20 , int V_11 ,
char * V_24 , int V_30 , int V_31 )
{
return F_15 ( V_19 , V_20 , 0 ,
V_27 , V_11 , V_24 , V_30 , V_31 , NULL ) ;
}
int F_19 ( T_1 * V_19 , const char * V_20 , int V_11 ,
char * V_24 , int V_30 , int V_31 )
{
char * V_40 = NULL ;
if ( V_20 )
{
V_40 = F_20 ( V_20 ) ;
if ( V_40 == NULL )
{
F_4 ( V_41 , V_4 ) ;
return 0 ;
}
}
return F_15 ( V_19 , V_40 , 1 ,
V_27 , V_11 , V_24 , V_30 , V_31 , NULL ) ;
}
int F_21 ( T_1 * V_19 , const char * V_20 , int V_11 ,
char * V_24 , int V_30 , int V_31 , const char * V_32 )
{
return F_15 ( V_19 , V_20 , 0 ,
V_28 , V_11 , V_24 , V_30 , V_31 , V_32 ) ;
}
int F_22 ( T_1 * V_19 , const char * V_20 , int V_11 ,
char * V_24 , int V_30 , int V_31 , const char * V_32 )
{
char * V_40 = NULL ;
if ( V_20 )
{
V_40 = F_20 ( V_20 ) ;
if ( V_40 == NULL )
{
F_4 ( V_42 , V_4 ) ;
return - 1 ;
}
}
return F_15 ( V_19 , V_40 , 1 ,
V_28 , V_11 , V_24 , V_30 , V_31 , V_32 ) ;
}
int F_23 ( T_1 * V_19 , const char * V_20 , const char * V_16 ,
const char * V_17 , const char * V_18 ,
int V_11 , char * V_24 )
{
return F_17 ( V_19 , V_20 , V_16 ,
V_17 , V_18 , 0 , V_14 , V_11 , V_24 ) ;
}
int F_24 ( T_1 * V_19 , const char * V_20 , const char * V_16 ,
const char * V_17 , const char * V_18 ,
int V_11 , char * V_24 )
{
char * V_40 = NULL ;
char * V_43 = NULL ;
char * V_44 = NULL ;
char * V_45 = NULL ;
if ( V_20 )
{
V_40 = F_20 ( V_20 ) ;
if ( V_40 == NULL )
{
F_4 ( V_46 , V_4 ) ;
goto V_47;
}
}
if ( V_16 )
{
V_43 = F_20 ( V_16 ) ;
if ( V_43 == NULL )
{
F_4 ( V_46 , V_4 ) ;
goto V_47;
}
}
if ( V_17 )
{
V_44 = F_20 ( V_17 ) ;
if ( V_44 == NULL )
{
F_4 ( V_46 , V_4 ) ;
goto V_47;
}
}
if ( V_18 )
{
V_45 = F_20 ( V_18 ) ;
if ( V_45 == NULL )
{
F_4 ( V_46 , V_4 ) ;
goto V_47;
}
}
return F_17 ( V_19 , V_40 , V_43 ,
V_44 , V_45 , 1 , V_14 , V_11 ,
V_24 ) ;
V_47:
if ( V_40 ) F_8 ( V_40 ) ;
if ( V_43 ) F_8 ( V_43 ) ;
if ( V_44 ) F_8 ( V_44 ) ;
if ( V_45 ) F_8 ( V_45 ) ;
return - 1 ;
}
int F_25 ( T_1 * V_19 , const char * V_48 )
{
return F_15 ( V_19 , V_48 , 0 , V_49 , 0 , NULL , 0 , 0 ,
NULL ) ;
}
int F_26 ( T_1 * V_19 , const char * V_48 )
{
char * V_50 = NULL ;
if ( V_48 )
{
V_50 = F_20 ( V_48 ) ;
if ( V_50 == NULL )
{
F_4 ( V_51 , V_4 ) ;
return - 1 ;
}
}
return F_15 ( V_19 , V_50 , 1 , V_49 , 0 , NULL ,
0 , 0 , NULL ) ;
}
int F_27 ( T_1 * V_19 , const char * V_48 )
{
return F_15 ( V_19 , V_48 , 0 , V_52 , 0 , NULL , 0 , 0 ,
NULL ) ;
}
int F_28 ( T_1 * V_19 , const char * V_48 )
{
char * V_50 = NULL ;
if ( V_48 )
{
V_50 = F_20 ( V_48 ) ;
if ( V_50 == NULL )
{
F_4 ( V_53 , V_4 ) ;
return - 1 ;
}
}
return F_15 ( V_19 , V_50 , 1 , V_52 , 0 , NULL ,
0 , 0 , NULL ) ;
}
char * F_29 ( T_1 * V_19 , const char * V_54 ,
const char * V_55 )
{
char * V_20 = NULL ;
if ( V_19 -> V_5 -> V_56 )
V_20 = V_19 -> V_5 -> V_56 ( V_19 ,
V_54 , V_55 ) ;
else
{
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
V_20 = ( char * ) F_3 ( V_60 + 1 ) ;
F_30 ( V_20 , V_57 , V_60 + 1 ) ;
F_31 ( V_20 , V_54 , V_60 + 1 ) ;
if ( V_55 )
{
F_31 ( V_20 , V_58 , V_60 + 1 ) ;
F_31 ( V_20 , V_55 , V_60 + 1 ) ;
}
F_31 ( V_20 , V_59 , V_60 + 1 ) ;
}
return V_20 ;
}
void * F_32 ( T_1 * V_19 , void * V_7 )
{
void * V_61 = V_19 -> V_7 ;
V_19 -> V_7 = V_7 ;
return V_61 ;
}
void * F_33 ( T_1 * V_19 )
{
return V_19 -> V_7 ;
}
const char * F_34 ( T_1 * V_19 , int V_62 )
{
if ( V_62 < 0 )
{
F_4 ( V_63 , V_64 ) ;
return NULL ;
}
if ( V_62 >= F_35 ( V_19 -> V_6 ) )
{
F_4 ( V_63 , V_65 ) ;
return NULL ;
}
return F_36 ( F_37 ( V_19 -> V_6 , V_62 ) ) ;
}
static int F_38 ( const char * V_66 , T_4 V_60 , T_1 * V_19 )
{
T_3 V_10 ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_10 . type = V_52 ;
V_10 . V_13 = V_66 ;
if ( V_19 -> V_5 -> V_67
&& ! V_19 -> V_5 -> V_67 ( V_19 , & V_10 ) )
return - 1 ;
return 0 ;
}
int F_39 ( T_1 * V_19 )
{
int V_62 , V_68 = 0 ;
if ( V_19 -> V_5 -> V_69 && ! V_19 -> V_5 -> V_69 ( V_19 ) )
return - 1 ;
if ( V_19 -> V_11 & V_70 )
F_40 (
( int ( * ) ( const char * , T_4 , void * ) ) F_38 ,
( void * ) V_19 ) ;
for( V_62 = 0 ; V_62 < F_35 ( V_19 -> V_6 ) ; V_62 ++ )
{
if ( V_19 -> V_5 -> V_67
&& ! V_19 -> V_5 -> V_67 ( V_19 ,
F_37 ( V_19 -> V_6 , V_62 ) ) )
{
V_68 = - 1 ;
goto V_47;
}
}
if ( V_19 -> V_5 -> V_71 )
switch( V_19 -> V_5 -> V_71 ( V_19 ) )
{
case - 1 :
V_68 = - 2 ;
goto V_47;
case 0 :
V_68 = - 1 ;
goto V_47;
default:
V_68 = 0 ;
break;
}
for( V_62 = 0 ; V_62 < F_35 ( V_19 -> V_6 ) ; V_62 ++ )
{
if ( V_19 -> V_5 -> V_72 )
{
switch( V_19 -> V_5 -> V_72 ( V_19 ,
F_37 ( V_19 -> V_6 , V_62 ) ) )
{
case - 1 :
V_68 = - 2 ;
goto V_47;
case 0 :
V_68 = - 1 ;
goto V_47;
default:
V_68 = 0 ;
break;
}
}
}
V_47:
if ( V_19 -> V_5 -> V_73 && ! V_19 -> V_5 -> V_73 ( V_19 ) )
return - 1 ;
return V_68 ;
}
int F_41 ( T_1 * V_19 , int V_74 , long V_62 , void * V_37 , void (* F_42)( void ) )
{
if ( V_19 == NULL )
{
F_4 ( V_75 , V_26 ) ;
return - 1 ;
}
switch( V_74 )
{
case V_76 :
{
int V_77 = ! ! ( V_19 -> V_11 & V_70 ) ;
if ( V_62 )
V_19 -> V_11 |= V_70 ;
else
V_19 -> V_11 &= ~ V_70 ;
return V_77 ;
}
case V_78 :
return ! ! ( V_19 -> V_11 & V_79 ) ;
default:
break;
}
F_4 ( V_75 , V_80 ) ;
return - 1 ;
}
int F_43 ( long V_81 , void * V_82 , T_5 * V_83 ,
T_6 * V_84 , T_7 * V_85 )
{
return F_44 ( V_8 , V_81 , V_82 ,
V_83 , V_84 , V_85 ) ;
}
int F_45 ( T_1 * V_86 , int V_87 , void * V_88 )
{
return ( F_46 ( & V_86 -> V_9 , V_87 , V_88 ) ) ;
}
void * F_47 ( T_1 * V_86 , int V_87 )
{
return ( F_48 ( & V_86 -> V_9 , V_87 ) ) ;
}
void F_49 ( const T_2 * V_5 )
{
V_89 = V_5 ;
}
const T_2 * F_5 ( void )
{
if ( V_89 == NULL )
{
V_89 = F_50 () ;
}
return V_89 ;
}
const T_2 * F_51 ( T_1 * V_19 )
{
return V_19 -> V_5 ;
}
const T_2 * F_52 ( T_1 * V_19 , const T_2 * V_5 )
{
V_19 -> V_5 = V_5 ;
return V_19 -> V_5 ;
}
T_2 * F_53 ( char * V_90 )
{
T_2 * V_91 = ( T_2 * ) F_3 ( sizeof( T_2 ) ) ;
if ( V_91 )
memset ( V_91 , 0 , sizeof( * V_91 ) ) ;
V_91 -> V_90 = F_20 ( V_90 ) ;
return V_91 ;
}
void F_54 ( T_2 * V_91 )
{
F_8 ( V_91 -> V_90 ) ;
V_91 -> V_90 = NULL ;
F_8 ( V_91 ) ;
}
int F_55 ( T_2 * V_1 , int (* F_56)( T_1 * V_19 ) )
{
if ( V_1 )
{
V_1 -> V_69 = F_56 ;
return 0 ;
}
else
return - 1 ;
}
int F_57 ( T_2 * V_1 , int (* F_58)( T_1 * V_19 , T_3 * V_10 ) )
{
if ( V_1 )
{
V_1 -> V_67 = F_58 ;
return 0 ;
}
else
return - 1 ;
}
int F_59 ( T_2 * V_1 , int (* F_60)( T_1 * V_19 ) )
{
if ( V_1 )
{
V_1 -> V_71 = F_60 ;
return 0 ;
}
else
return - 1 ;
}
int F_61 ( T_2 * V_1 , int (* F_62)( T_1 * V_19 , T_3 * V_10 ) )
{
if ( V_1 )
{
V_1 -> V_72 = F_62 ;
return 0 ;
}
else
return - 1 ;
}
int F_63 ( T_2 * V_1 , int (* F_64)( T_1 * V_19 ) )
{
if ( V_1 )
{
V_1 -> V_73 = F_64 ;
return 0 ;
}
else
return - 1 ;
}
enum V_22 F_65 ( T_3 * V_10 )
{
if ( ! V_10 )
return V_92 ;
return V_10 -> type ;
}
int F_66 ( T_3 * V_10 )
{
if ( ! V_10 )
return 0 ;
return V_10 -> V_23 ;
}
const char * F_67 ( T_3 * V_10 )
{
if ( ! V_10 )
return NULL ;
return V_10 -> V_13 ;
}
const char * F_68 ( T_3 * V_10 )
{
if ( ! V_10 )
return NULL ;
switch( V_10 -> type )
{
case V_27 :
case V_14 :
return V_10 -> _ . V_15 . V_16 ;
default:
return NULL ;
}
}
const char * F_36 ( T_3 * V_10 )
{
if ( ! V_10 )
return NULL ;
switch( V_10 -> type )
{
case V_27 :
case V_28 :
return V_10 -> V_24 ;
default:
return NULL ;
}
}
const char * F_69 ( T_3 * V_10 )
{
if ( ! V_10 )
return NULL ;
switch( V_10 -> type )
{
case V_28 :
return V_10 -> _ . V_34 . V_32 ;
default:
return NULL ;
}
}
int F_70 ( T_3 * V_10 )
{
if ( ! V_10 )
return - 1 ;
switch( V_10 -> type )
{
case V_27 :
case V_28 :
return V_10 -> _ . V_34 . V_35 ;
default:
return - 1 ;
}
}
int F_71 ( T_3 * V_10 )
{
if ( ! V_10 )
return - 1 ;
switch( V_10 -> type )
{
case V_27 :
case V_28 :
return V_10 -> _ . V_34 . V_36 ;
default:
return - 1 ;
}
}
int F_72 ( T_1 * V_19 , T_3 * V_10 , const char * V_93 )
{
int V_94 = strlen ( V_93 ) ;
V_19 -> V_11 &= ~ V_79 ;
if ( ! V_10 )
return - 1 ;
switch ( V_10 -> type )
{
case V_27 :
case V_28 :
{
char V_95 [ F_73 ( V_10 -> _ . V_34 . V_35 ) + 1 ] ;
char V_96 [ F_73 ( V_10 -> _ . V_34 . V_36 ) + 1 ] ;
F_74 ( V_95 , sizeof( V_95 ) , L_4 ,
V_10 -> _ . V_34 . V_35 ) ;
F_74 ( V_96 , sizeof( V_96 ) , L_4 ,
V_10 -> _ . V_34 . V_36 ) ;
if ( V_94 < V_10 -> _ . V_34 . V_35 )
{
V_19 -> V_11 |= V_79 ;
F_4 ( V_97 , V_98 ) ;
F_75 ( 5 , L_5 ,
V_95 , L_6 , V_96 , L_7 ) ;
return - 1 ;
}
if ( V_94 > V_10 -> _ . V_34 . V_36 )
{
V_19 -> V_11 |= V_79 ;
F_4 ( V_97 , V_99 ) ;
F_75 ( 5 , L_5 ,
V_95 , L_6 , V_96 , L_7 ) ;
return - 1 ;
}
}
if ( ! V_10 -> V_24 )
{
F_4 ( V_97 , V_29 ) ;
return - 1 ;
}
F_30 ( V_10 -> V_24 , V_93 ,
V_10 -> _ . V_34 . V_36 + 1 ) ;
break;
case V_14 :
{
const char * V_37 ;
if ( ! V_10 -> V_24 )
{
F_4 ( V_97 , V_29 ) ;
return - 1 ;
}
V_10 -> V_24 [ 0 ] = '\0' ;
for( V_37 = V_93 ; * V_37 ; V_37 ++ )
{
if ( strchr ( V_10 -> _ . V_15 . V_17 , * V_37 ) )
{
V_10 -> V_24 [ 0 ] =
V_10 -> _ . V_15 . V_17 [ 0 ] ;
break;
}
if ( strchr ( V_10 -> _ . V_15 . V_18 , * V_37 ) )
{
V_10 -> V_24 [ 0 ] =
V_10 -> _ . V_15 . V_18 [ 0 ] ;
break;
}
}
default:
break;
}
}
return 0 ;
}
