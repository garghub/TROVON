T_1 * F_1 ( T_2 * V_1 , T_3 * V_2 , char * V_3 ,
char * V_4 )
{
int V_5 ;
int V_6 ;
T_1 * V_7 ;
V_5 = F_2 ( & V_4 ) ;
if ( ( V_6 = F_3 ( & V_4 ) ) )
return F_4 ( V_3 , V_4 , V_5 , V_6 , V_2 ) ;
V_7 = F_5 ( V_1 , V_2 , F_6 ( V_3 ) , V_5 , V_4 ) ;
if ( ! V_7 )
{
F_7 ( V_8 , V_9 ) ;
F_8 ( 4 , L_1 , V_3 , L_2 , V_4 ) ;
}
return V_7 ;
}
T_1 * F_9 ( T_2 * V_1 , T_3 * V_2 , int V_10 ,
char * V_4 )
{
int V_5 ;
int V_6 ;
V_5 = F_2 ( & V_4 ) ;
if ( ( V_6 = F_3 ( & V_4 ) ) )
return F_4 ( F_10 ( V_10 ) ,
V_4 , V_5 , V_6 , V_2 ) ;
return F_5 ( V_1 , V_2 , V_10 , V_5 , V_4 ) ;
}
static T_1 * F_5 ( T_2 * V_1 , T_3 * V_2 , int V_10 ,
int V_5 , char * V_4 )
{
const T_4 * V_11 ;
T_1 * V_12 ;
F_11 ( V_13 ) * V_14 ;
void * V_15 ;
if ( V_10 == V_16 )
{
F_7 ( V_17 , V_18 ) ;
return NULL ;
}
if ( ! ( V_11 = F_12 ( V_10 ) ) )
{
F_7 ( V_17 , V_19 ) ;
return NULL ;
}
if ( V_11 -> V_20 )
{
if( * V_4 == '@' ) V_14 = F_13 ( V_1 , V_4 + 1 ) ;
else V_14 = F_14 ( V_4 ) ;
if( F_15 ( V_14 ) <= 0 )
{
F_7 ( V_17 , V_21 ) ;
F_8 ( 4 , L_1 , F_10 ( V_10 ) , L_3 , V_4 ) ;
return NULL ;
}
V_15 = V_11 -> V_20 ( V_11 , V_2 , V_14 ) ;
if( * V_4 != '@' ) F_16 ( V_14 ,
V_22 ) ;
if( ! V_15 ) return NULL ;
}
else if( V_11 -> V_23 )
{
if( ! ( V_15 = V_11 -> V_23 ( V_11 , V_2 , V_4 ) ) ) return NULL ;
}
else if( V_11 -> V_24 )
{
if( ! V_2 -> V_25 || ! V_2 -> V_26 )
{
F_7 ( V_17 , V_27 ) ;
return NULL ;
}
if( ! ( V_15 = V_11 -> V_24 ( V_11 , V_2 , V_4 ) ) ) return NULL ;
}
else
{
F_7 ( V_17 , V_28 ) ;
F_8 ( 2 , L_1 , F_10 ( V_10 ) ) ;
return NULL ;
}
V_12 = F_17 ( V_11 , V_10 , V_5 , V_15 ) ;
if( V_11 -> V_29 ) F_18 ( V_15 , F_19 ( V_11 -> V_29 ) ) ;
else V_11 -> V_30 ( V_15 ) ;
return V_12 ;
}
static T_1 * F_17 ( const T_4 * V_11 , int V_10 ,
int V_5 , void * V_15 )
{
unsigned char * V_31 ;
int V_32 ;
T_5 * V_33 ;
T_1 * V_12 ;
if ( V_11 -> V_29 )
{
V_31 = NULL ;
V_32 = F_20 ( V_15 , & V_31 , F_19 ( V_11 -> V_29 ) ) ;
if ( V_32 < 0 ) goto V_34;
}
else
{
unsigned char * V_35 ;
V_32 = V_11 -> V_36 ( V_15 , NULL ) ;
if( ! ( V_31 = F_21 ( V_32 ) ) ) goto V_34;
V_35 = V_31 ;
V_11 -> V_36 ( V_15 , & V_35 ) ;
}
if ( ! ( V_33 = F_22 () ) ) goto V_34;
V_33 -> V_37 = V_31 ;
V_33 -> V_38 = V_32 ;
V_12 = F_23 ( NULL , V_10 , V_5 , V_33 ) ;
if ( ! V_12 ) goto V_34;
F_24 ( V_33 ) ;
return V_12 ;
V_34:
F_7 ( V_39 , V_40 ) ;
return NULL ;
}
T_1 * F_25 ( int V_10 , int V_5 , void * V_15 )
{
const T_4 * V_11 ;
if ( ! ( V_11 = F_12 ( V_10 ) ) ) {
F_7 ( V_41 , V_19 ) ;
return NULL ;
}
return F_17 ( V_11 , V_10 , V_5 , V_15 ) ;
}
static int F_2 ( char * * V_4 )
{
char * V_35 = * V_4 ;
if ( ( strlen ( V_35 ) < 9 ) || strncmp ( V_35 , L_4 , 9 ) ) return 0 ;
V_35 += 9 ;
while( isspace ( ( unsigned char ) * V_35 ) ) V_35 ++ ;
* V_4 = V_35 ;
return 1 ;
}
static int F_3 ( char * * V_4 )
{
int V_42 = 0 ;
char * V_35 = * V_4 ;
if ( ( strlen ( V_35 ) >= 4 ) && ! strncmp ( V_35 , L_5 , 4 ) )
{
V_35 += 4 ;
V_42 = 1 ;
}
else if ( ( strlen ( V_35 ) >= 5 ) && ! strncmp ( V_35 , L_6 , 5 ) )
{
V_35 += 5 ;
V_42 = 2 ;
}
else
return 0 ;
while ( isspace ( ( unsigned char ) * V_35 ) ) V_35 ++ ;
* V_4 = V_35 ;
return V_42 ;
}
static T_1 * F_4 ( const char * V_12 , char * V_4 ,
int V_5 , int V_42 ,
T_3 * V_2 )
{
unsigned char * V_31 = NULL ;
long V_32 ;
T_6 * V_43 = NULL ;
T_5 * V_44 = NULL ;
T_1 * V_45 = NULL ;
if ( ! ( V_43 = F_26 ( V_12 , 0 ) ) )
{
F_7 ( V_46 , V_47 ) ;
F_8 ( 2 , L_1 , V_12 ) ;
goto V_48;
}
if ( V_42 == 1 )
V_31 = F_27 ( V_4 , & V_32 ) ;
else if ( V_42 == 2 )
V_31 = F_28 ( V_4 , V_2 , & V_32 ) ;
if ( V_31 == NULL )
{
F_7 ( V_46 , V_49 ) ;
F_8 ( 2 , L_7 , V_4 ) ;
goto V_48;
}
if ( ! ( V_44 = F_22 () ) )
{
F_7 ( V_46 , V_40 ) ;
goto V_48;
}
V_44 -> V_37 = V_31 ;
V_44 -> V_38 = V_32 ;
V_31 = NULL ;
V_45 = F_29 ( NULL , V_43 , V_5 , V_44 ) ;
V_48:
F_30 ( V_43 ) ;
F_24 ( V_44 ) ;
if( V_31 ) F_31 ( V_31 ) ;
return V_45 ;
}
static unsigned char * F_28 ( char * V_4 , T_3 * V_2 , long * V_32 )
{
T_7 * V_50 ;
unsigned char * V_31 = NULL ;
V_50 = F_32 ( V_4 , V_2 ) ;
if ( V_50 == NULL )
return NULL ;
* V_32 = F_33 ( V_50 , & V_31 ) ;
F_34 ( V_50 ) ;
return V_31 ;
}
int F_35 ( T_2 * V_1 , T_3 * V_2 , char * V_51 ,
T_8 * V_52 )
{
F_11 ( T_1 ) * * V_53 = NULL ;
if ( V_52 )
V_53 = & V_52 -> V_54 -> V_55 ;
return F_36 ( V_1 , V_2 , V_51 , V_53 ) ;
}
int F_37 ( T_2 * V_1 , T_3 * V_2 , char * V_51 ,
T_9 * V_56 )
{
F_11 ( T_1 ) * * V_53 = NULL ;
if ( V_56 )
V_53 = & V_56 -> V_56 -> V_55 ;
return F_36 ( V_1 , V_2 , V_51 , V_53 ) ;
}
int F_38 ( T_2 * V_1 , T_3 * V_2 , char * V_51 ,
T_10 * V_57 )
{
F_11 ( T_1 ) * V_58 = NULL , * * V_53 = NULL ;
int V_59 ;
if ( V_57 )
V_53 = & V_58 ;
V_59 = F_36 ( V_1 , V_2 , V_51 , V_53 ) ;
if ( ! V_59 || ! V_53 )
return V_59 ;
V_59 = F_39 ( V_57 , V_58 ) ;
F_40 ( V_58 , V_60 ) ;
return V_59 ;
}
char * F_41 ( T_3 * V_2 , char * V_3 , char * V_51 )
{
if( ! V_2 -> V_25 || ! V_2 -> V_26 || ! V_2 -> V_26 -> V_61 )
{
F_7 ( V_62 , V_63 ) ;
return NULL ;
}
if ( V_2 -> V_26 -> V_61 )
return V_2 -> V_26 -> V_61 ( V_2 -> V_25 , V_3 , V_51 ) ;
return NULL ;
}
static char * F_42 ( void * V_25 , char * V_51 , char * V_4 )
{
return F_43 ( V_25 , V_51 , V_4 ) ;
}
void F_44 ( T_3 * V_2 , T_2 * V_1 )
{
V_2 -> V_26 = & V_64 ;
V_2 -> V_25 = V_1 ;
}
void F_45 ( T_3 * V_2 , T_8 * V_65 , T_8 * V_66 , T_10 * V_57 ,
T_9 * V_56 , int V_67 )
{
V_2 -> V_68 = V_65 ;
V_2 -> V_69 = V_66 ;
V_2 -> V_56 = V_56 ;
V_2 -> V_70 = V_57 ;
V_2 -> V_67 = V_67 ;
}
static char * F_46 ( void * V_25 , char * V_51 , char * V_4 )
{
return F_47 ( V_25 , V_51 , V_4 ) ;
}
