int F_1 ( const T_1 * V_1 , const char * V_2 ,
unsigned long V_3 )
{
F_2 ( V_4 ) * V_5 ;
V_4 * V_6 ;
char * V_7 ;
int V_8 , V_9 ;
if ( ! V_1 )
return 1 ;
if ( V_2 == NULL )
V_2 = L_1 ;
V_7 = F_3 ( V_1 , NULL , V_2 ) ;
if ( ! V_7 )
{
F_4 () ;
return 1 ;
}
V_5 = F_5 ( V_1 , V_7 ) ;
if ( ! V_5 )
return 0 ;
for ( V_9 = 0 ; V_9 < F_6 ( V_5 ) ; V_9 ++ )
{
V_6 = F_7 ( V_5 , V_9 ) ;
V_8 = F_8 ( V_1 , V_6 -> V_10 , V_6 -> V_11 , V_3 ) ;
if ( V_8 <= 0 )
if( ! ( V_3 & V_12 ) )
return V_8 ;
}
return 1 ;
}
int F_9 ( const char * V_13 , const char * V_2 ,
unsigned long V_3 )
{
char * V_14 = NULL ;
T_1 * V_15 = NULL ;
int V_8 = 0 ;
V_15 = F_10 ( NULL ) ;
if ( ! V_15 )
goto V_16;
if ( V_13 == NULL )
{
V_14 = F_11 () ;
if ( ! V_14 )
goto V_16;
}
else
V_14 = ( char * ) V_13 ;
if ( F_12 ( V_15 , V_14 , NULL ) <= 0 )
{
if ( ( V_3 & V_17 ) &&
( F_13 ( F_14 () ) == V_18 ) )
{
F_4 () ;
V_8 = 1 ;
}
goto V_16;
}
V_8 = F_1 ( V_15 , V_2 , V_3 ) ;
V_16:
if ( V_13 == NULL )
F_15 ( V_14 ) ;
F_16 ( V_15 ) ;
return V_8 ;
}
static int F_8 ( const T_1 * V_1 , char * V_10 , char * V_11 ,
unsigned long V_3 )
{
T_2 * V_19 ;
int V_8 ;
V_19 = F_17 ( V_10 ) ;
if ( ! V_19 && ! ( V_3 & V_20 ) )
V_19 = F_18 ( V_1 , V_10 , V_11 , V_3 ) ;
if ( ! V_19 )
{
if ( ! ( V_3 & V_21 ) )
{
F_19 ( V_22 , V_23 ) ;
F_20 ( 2 , L_2 , V_10 ) ;
}
return - 1 ;
}
V_8 = F_21 ( V_19 , V_10 , V_11 , V_1 ) ;
if ( V_8 <= 0 )
{
if ( ! ( V_3 & V_21 ) )
{
char V_24 [ F_22 ( V_8 ) + 1 ] ;
F_19 ( V_22 , V_25 ) ;
F_23 ( V_24 , sizeof V_24 , L_3 , V_8 ) ;
F_20 ( 6 , L_2 , V_10 , L_4 , V_11 , L_5 , V_24 ) ;
}
}
return V_8 ;
}
static T_2 * F_18 ( const T_1 * V_1 , char * V_10 , char * V_11 ,
unsigned long V_3 )
{
T_3 * V_26 = NULL ;
T_4 * V_27 ;
T_5 * V_28 ;
char * V_29 = NULL ;
int V_30 = 0 ;
T_2 * V_19 ;
V_29 = F_3 ( V_1 , V_11 , L_6 ) ;
if ( ! V_29 )
{
F_4 () ;
V_29 = V_10 ;
}
V_26 = F_24 ( NULL , V_29 , NULL , 0 ) ;
if ( ! V_26 )
{
V_30 = V_31 ;
goto V_16;
}
V_27 = ( T_4 * ) F_25 ( V_26 , V_32 ) ;
if ( ! V_27 )
{
V_30 = V_33 ;
goto V_16;
}
V_28 = ( T_5 * ) F_25 ( V_26 , V_34 ) ;
V_19 = F_26 ( V_26 , V_10 , V_27 , V_28 ) ;
if ( ! V_19 )
goto V_16;
return V_19 ;
V_16:
if ( V_26 )
F_27 ( V_26 ) ;
F_19 ( V_35 , V_30 ) ;
F_20 ( 4 , L_2 , V_10 , L_7 , V_29 ) ;
return NULL ;
}
static T_2 * F_26 ( T_3 * V_26 , const char * V_10 ,
T_4 * V_27 , T_5 * V_28 )
{
T_2 * V_36 = NULL ;
if ( V_37 == NULL )
V_37 = F_28 () ;
if ( V_37 == NULL )
return NULL ;
V_36 = F_29 ( sizeof( T_2 ) ) ;
if ( V_36 == NULL )
return NULL ;
V_36 -> V_26 = V_26 ;
V_36 -> V_10 = F_30 ( V_10 ) ;
V_36 -> V_38 = V_27 ;
V_36 -> V_39 = V_28 ;
V_36 -> V_40 = 0 ;
if ( ! F_31 ( V_37 , V_36 ) )
{
F_15 ( V_36 ) ;
return NULL ;
}
return V_36 ;
}
static T_2 * F_17 ( char * V_10 )
{
T_2 * V_36 ;
int V_9 , V_41 ;
char * V_42 ;
V_42 = strrchr ( V_10 , '.' ) ;
if ( V_42 )
V_41 = V_42 - V_10 ;
else
V_41 = strlen ( V_10 ) ;
for ( V_9 = 0 ; V_9 < F_32 ( V_37 ) ; V_9 ++ )
{
V_36 = F_33 ( V_37 , V_9 ) ;
if ( ! strncmp ( V_36 -> V_10 , V_10 , V_41 ) )
return V_36 ;
}
return NULL ;
}
static int F_21 ( T_2 * V_43 , char * V_10 , char * V_11 ,
const T_1 * V_1 )
{
int V_8 = 1 ;
int V_44 = 0 ;
T_6 * V_45 = NULL ;
V_45 = F_29 ( sizeof( T_6 ) ) ;
if ( ! V_45 )
goto V_16;
V_45 -> V_43 = V_43 ;
V_45 -> V_10 = F_30 ( V_10 ) ;
V_45 -> V_11 = F_30 ( V_11 ) ;
V_45 -> V_46 = NULL ;
if ( ! V_45 -> V_10 || ! V_45 -> V_11 )
goto V_47;
if( V_43 -> V_38 )
{
V_8 = V_43 -> V_38 ( V_45 , V_1 ) ;
V_44 = 1 ;
if ( V_8 <= 0 )
goto V_16;
}
if ( V_48 == NULL )
{
V_48 = F_34 () ;
if ( ! V_48 )
{
F_19 ( V_49 , V_50 ) ;
goto V_16;
}
}
if ( ! F_35 ( V_48 , V_45 ) )
{
F_19 ( V_49 , V_50 ) ;
goto V_16;
}
V_43 -> V_40 ++ ;
return V_8 ;
V_16:
if ( V_43 -> V_39 && V_44 )
V_43 -> V_39 ( V_45 ) ;
V_47:
if ( V_45 )
{
if ( V_45 -> V_10 )
F_15 ( V_45 -> V_10 ) ;
if ( V_45 -> V_11 )
F_15 ( V_45 -> V_11 ) ;
F_15 ( V_45 ) ;
}
return - 1 ;
}
void F_36 ( int V_51 )
{
int V_9 ;
T_2 * V_19 ;
F_37 () ;
for ( V_9 = F_32 ( V_37 ) - 1 ; V_9 >= 0 ; V_9 -- )
{
V_19 = F_33 ( V_37 , V_9 ) ;
if ( ( ( V_19 -> V_40 > 0 ) || ! V_19 -> V_26 ) && ! V_51 )
continue;
F_38 ( V_37 , V_9 ) ;
F_39 ( V_19 ) ;
}
if ( F_32 ( V_37 ) == 0 )
{
F_40 ( V_37 ) ;
V_37 = NULL ;
}
}
static void F_39 ( T_2 * V_19 )
{
if ( V_19 -> V_26 )
F_27 ( V_19 -> V_26 ) ;
F_15 ( V_19 -> V_10 ) ;
F_15 ( V_19 ) ;
}
void F_37 ( void )
{
T_6 * V_45 ;
while ( F_41 ( V_48 ) > 0 )
{
V_45 = F_42 ( V_48 ) ;
F_43 ( V_45 ) ;
}
F_44 ( V_48 ) ;
V_48 = NULL ;
}
static void F_43 ( T_6 * V_45 )
{
if ( V_45 -> V_43 -> V_39 )
V_45 -> V_43 -> V_39 ( V_45 ) ;
V_45 -> V_43 -> V_40 -- ;
F_15 ( V_45 -> V_10 ) ;
F_15 ( V_45 -> V_11 ) ;
F_15 ( V_45 ) ;
}
int F_45 ( const char * V_10 , T_4 * V_27 ,
T_5 * V_28 )
{
if ( F_26 ( NULL , V_10 , V_27 , V_28 ) )
return 1 ;
else
return 0 ;
}
void F_46 ( void )
{
F_37 () ;
F_36 ( 1 ) ;
}
const char * F_47 ( const T_6 * V_19 )
{
return V_19 -> V_10 ;
}
const char * F_48 ( const T_6 * V_19 )
{
return V_19 -> V_11 ;
}
void * F_49 ( const T_6 * V_19 )
{
return V_19 -> V_46 ;
}
void F_50 ( T_6 * V_19 , void * V_46 )
{
V_19 -> V_46 = V_46 ;
}
T_2 * F_51 ( const T_6 * V_19 )
{
return V_19 -> V_43 ;
}
unsigned long F_52 ( const T_6 * V_19 )
{
return V_19 -> V_3 ;
}
void F_53 ( T_6 * V_19 , unsigned long V_3 )
{
V_19 -> V_3 = V_3 ;
}
void * F_54 ( T_2 * V_43 )
{
return V_43 -> V_46 ;
}
void F_55 ( T_2 * V_43 , void * V_46 )
{
V_43 -> V_46 = V_46 ;
}
char * F_11 ( void )
{
char * V_14 ;
int V_52 ;
V_14 = getenv ( L_8 ) ;
if ( V_14 )
return F_30 ( V_14 ) ;
V_52 = strlen ( F_56 () ) ;
#ifndef F_57
V_52 ++ ;
#endif
V_52 += strlen ( V_53 ) ;
V_14 = F_29 ( V_52 + 1 ) ;
if ( ! V_14 )
return NULL ;
F_58 ( V_14 , F_56 () , V_52 + 1 ) ;
#ifndef F_57
F_59 ( V_14 , L_9 , V_52 + 1 ) ;
#endif
F_59 ( V_14 , V_53 , V_52 + 1 ) ;
return V_14 ;
}
int F_60 ( const char * V_54 , int V_55 , int V_56 ,
int (* F_61)( const char * V_57 , int V_52 , void * V_58 ) , void * V_59 )
{
int V_8 ;
const char * V_60 , * V_61 , * V_42 ;
V_60 = V_54 ;
for(; ; )
{
if ( V_56 )
{
while( * V_60 && isspace ( ( unsigned char ) * V_60 ) )
V_60 ++ ;
}
V_42 = strchr ( V_60 , V_55 ) ;
if ( V_42 == V_60 || ! * V_60 )
V_8 = F_61 ( NULL , 0 , V_59 ) ;
else
{
if ( V_42 )
V_61 = V_42 - 1 ;
else
V_61 = V_60 + strlen ( V_60 ) - 1 ;
if ( V_56 )
{
while( isspace ( ( unsigned char ) * V_61 ) )
V_61 -- ;
}
V_8 = F_61 ( V_60 , V_61 - V_60 + 1 , V_59 ) ;
}
if ( V_8 <= 0 )
return V_8 ;
if ( V_42 == NULL )
return 1 ;
V_60 = V_42 + 1 ;
}
}
