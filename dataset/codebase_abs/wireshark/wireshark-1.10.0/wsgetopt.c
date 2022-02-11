static void
F_1 ( char * * V_1 , struct V_2 * V_3 )
{
int V_4 = V_3 -> V_5 ;
int V_6 = V_3 -> V_7 ;
int V_8 = V_3 -> V_9 ;
char * V_10 ;
#if V_11 V_12 && V_11 V_13
if ( V_3 -> V_14 > 0 && V_8 >= V_3 -> V_15 )
{
char * V_16 = malloc ( V_8 + 1 ) ;
if ( V_16 == NULL )
V_3 -> V_14 = V_3 -> V_15 = 0 ;
else
{
memset ( F_2 ( V_16 , V_17 ,
V_3 -> V_15 ) ,
'\0' , V_8 + 1 - V_3 -> V_15 ) ;
V_3 -> V_15 = V_8 + 1 ;
V_17 = V_16 ;
}
}
#endif
while ( V_8 > V_6 && V_6 > V_4 )
{
if ( V_8 - V_6 > V_6 - V_4 )
{
int V_18 = V_6 - V_4 ;
register int V_19 ;
for ( V_19 = 0 ; V_19 < V_18 ; V_19 ++ )
{
V_10 = V_1 [ V_4 + V_19 ] ;
V_1 [ V_4 + V_19 ] = V_1 [ V_8 - ( V_6 - V_4 ) + V_19 ] ;
V_1 [ V_8 - ( V_6 - V_4 ) + V_19 ] = V_10 ;
F_3 ( V_4 + V_19 , V_8 - ( V_6 - V_4 ) + V_19 ) ;
}
V_8 -= V_18 ;
}
else
{
int V_18 = V_8 - V_6 ;
register int V_19 ;
for ( V_19 = 0 ; V_19 < V_18 ; V_19 ++ )
{
V_10 = V_1 [ V_4 + V_19 ] ;
V_1 [ V_4 + V_19 ] = V_1 [ V_6 + V_19 ] ;
V_1 [ V_6 + V_19 ] = V_10 ;
F_3 ( V_4 + V_19 , V_6 + V_19 ) ;
}
V_4 += V_18 ;
}
}
V_3 -> V_5 += ( V_3 -> V_9 - V_3 -> V_7 ) ;
V_3 -> V_7 = V_3 -> V_9 ;
}
static const char *
F_4 ( int V_20 , char * const * V_1 , const char * V_21 ,
struct V_2 * V_3 , int V_22 )
{
V_3 -> V_5 = V_3 -> V_7 = V_3 -> V_9 ;
V_3 -> V_23 = NULL ;
V_3 -> V_24 = V_22 | ! ! getenv ( L_1 ) ;
if ( V_21 [ 0 ] == '-' )
{
V_3 -> V_25 = V_26 ;
++ V_21 ;
}
else if ( V_21 [ 0 ] == '+' )
{
V_3 -> V_25 = V_27 ;
++ V_21 ;
}
else if ( V_3 -> V_24 )
V_3 -> V_25 = V_27 ;
else
V_3 -> V_25 = V_28 ;
#if V_11 V_12 && V_11 V_13
if ( ! V_3 -> V_24
&& V_20 == V_29 && V_1 == V_30 )
{
if ( V_3 -> V_15 == 0 )
{
if ( V_17 == NULL
|| V_17 [ 0 ] == '\0' )
V_3 -> V_15 = - 1 ;
else
{
const char * V_31 = V_17 ;
int V_18 = V_3 -> V_15 = strlen ( V_31 ) ;
if ( V_3 -> V_15 < V_20 )
V_3 -> V_15 = V_20 ;
V_17 =
( char * ) malloc ( V_3 -> V_15 ) ;
if ( V_17 == NULL )
V_3 -> V_15 = - 1 ;
else
memset ( F_2 ( V_17 , V_31 , V_18 ) ,
'\0' , V_3 -> V_15 - V_18 ) ;
}
}
V_3 -> V_14 = V_3 -> V_15 ;
}
else
V_3 -> V_14 = 0 ;
#endif
return V_21 ;
}
int
F_5 ( int V_20 , char * const * V_1 , const char * V_21 ,
const struct V_32 * V_33 , int * V_34 ,
int V_35 , struct V_2 * V_3 , int V_22 )
{
int V_36 = V_3 -> V_37 ;
if ( V_20 < 1 )
return - 1 ;
V_3 -> V_38 = NULL ;
if ( V_3 -> V_9 == 0 || ! V_3 -> V_39 )
{
if ( V_3 -> V_9 == 0 )
V_3 -> V_9 = 1 ;
V_21 = F_4 ( V_20 , V_1 , V_21 , V_3 ,
V_22 ) ;
V_3 -> V_39 = 1 ;
}
else if ( V_21 [ 0 ] == '-' || V_21 [ 0 ] == '+' )
V_21 ++ ;
if ( V_21 [ 0 ] == ':' )
V_36 = 0 ;
#if V_11 V_12 && V_11 V_13
# define F_6 (argv[d->optind][0] != '-' || argv[d->optind][1] == '\0' \
|| (d->optind < d->__nonoption_flags_len \
&& __getopt_nonoption_flags[d->optind] == '1'))
#else
# define F_6 (argv[d->optind][0] != '-' || argv[d->optind][1] == '\0')
#endif
if ( V_3 -> V_23 == NULL || * V_3 -> V_23 == '\0' )
{
if ( V_3 -> V_7 > V_3 -> V_9 )
V_3 -> V_7 = V_3 -> V_9 ;
if ( V_3 -> V_5 > V_3 -> V_9 )
V_3 -> V_5 = V_3 -> V_9 ;
if ( V_3 -> V_25 == V_28 )
{
if ( V_3 -> V_5 != V_3 -> V_7
&& V_3 -> V_7 != V_3 -> V_9 )
F_1 ( ( char * * ) V_1 , V_3 ) ;
else if ( V_3 -> V_7 != V_3 -> V_9 )
V_3 -> V_5 = V_3 -> V_9 ;
while ( V_3 -> V_9 < V_20 && F_6 )
V_3 -> V_9 ++ ;
V_3 -> V_7 = V_3 -> V_9 ;
}
if ( V_3 -> V_9 != V_20 && ! strcmp ( V_1 [ V_3 -> V_9 ] , L_2 ) )
{
V_3 -> V_9 ++ ;
if ( V_3 -> V_5 != V_3 -> V_7
&& V_3 -> V_7 != V_3 -> V_9 )
F_1 ( ( char * * ) V_1 , V_3 ) ;
else if ( V_3 -> V_5 == V_3 -> V_7 )
V_3 -> V_5 = V_3 -> V_9 ;
V_3 -> V_7 = V_20 ;
V_3 -> V_9 = V_20 ;
}
if ( V_3 -> V_9 == V_20 )
{
if ( V_3 -> V_5 != V_3 -> V_7 )
V_3 -> V_9 = V_3 -> V_5 ;
return - 1 ;
}
if ( F_6 )
{
if ( V_3 -> V_25 == V_27 )
return - 1 ;
V_3 -> V_38 = V_1 [ V_3 -> V_9 ++ ] ;
return 1 ;
}
V_3 -> V_23 = ( V_1 [ V_3 -> V_9 ] + 1
+ ( V_33 != NULL && V_1 [ V_3 -> V_9 ] [ 1 ] == '-' ) ) ;
}
if ( V_33 != NULL
&& ( V_1 [ V_3 -> V_9 ] [ 1 ] == '-'
|| ( V_35 && ( V_1 [ V_3 -> V_9 ] [ 2 ]
|| ! strchr ( V_21 , V_1 [ V_3 -> V_9 ] [ 1 ] ) ) ) ) )
{
char * V_40 ;
T_1 V_41 ;
const struct V_32 * V_42 ;
const struct V_32 * V_43 = NULL ;
struct V_44
{
const struct V_32 * V_42 ;
struct V_44 * V_45 ;
} * V_46 = NULL ;
int V_47 = 0 ;
int V_48 = - 1 ;
int V_49 ;
for ( V_40 = V_3 -> V_23 ; * V_40 && * V_40 != '=' ; V_40 ++ )
;
V_41 = V_40 - V_3 -> V_23 ;
for ( V_42 = V_33 , V_49 = 0 ; V_42 -> V_50 ; V_42 ++ , V_49 ++ )
if ( ! strncmp ( V_42 -> V_50 , V_3 -> V_23 , V_41 ) )
{
if ( V_41 == ( unsigned int ) strlen ( V_42 -> V_50 ) )
{
V_43 = V_42 ;
V_48 = V_49 ;
V_47 = 1 ;
break;
}
else if ( V_43 == NULL )
{
V_43 = V_42 ;
V_48 = V_49 ;
}
else if ( V_35
|| V_43 -> V_51 != V_42 -> V_51
|| V_43 -> V_52 != V_42 -> V_52
|| V_43 -> V_53 != V_42 -> V_53 )
{
struct V_44 * V_54 = F_7 ( sizeof ( * V_54 ) ) ;
V_54 -> V_42 = V_42 ;
V_54 -> V_45 = V_46 ;
V_46 = V_54 ;
}
}
if ( V_46 != NULL && ! V_47 )
{
if ( V_36 )
{
struct V_44 V_55 ;
V_55 . V_42 = V_43 ;
V_55 . V_45 = V_46 ;
V_46 = & V_55 ;
#if V_11 V_12
char * V_56 = NULL ;
T_1 V_57 = 0 ;
T_2 * V_58 = F_8 ( & V_56 , & V_57 ) ;
if ( V_58 != NULL )
{
fprintf ( V_58 ,
_ ( L_3 ) ,
V_1 [ 0 ] , V_1 [ V_3 -> V_9 ] ) ;
do
{
fprintf ( V_58 , L_4 , V_46 -> V_42 -> V_50 ) ;
V_46 = V_46 -> V_45 ;
}
while ( V_46 != NULL );
F_9 ( '\n' , V_58 ) ;
if ( F_10 ( fclose ( V_58 ) != V_59 , 1 ) )
{
F_11 ( V_60 ) ;
int V_61 = ( ( V_62 * ) V_60 ) -> V_63 ;
( ( V_62 * ) V_60 ) -> V_63 |= V_64 ;
F_12 ( NULL , L_5 , V_56 ) ;
( ( V_62 * ) V_60 ) -> V_63 = V_61 ;
F_13 ( V_60 ) ;
free ( V_56 ) ;
}
}
#else
fprintf ( V_60 ,
_ ( L_3 ) ,
V_1 [ 0 ] , V_1 [ V_3 -> V_9 ] ) ;
do
{
fprintf ( V_60 , L_4 , V_46 -> V_42 -> V_50 ) ;
V_46 = V_46 -> V_45 ;
}
while ( V_46 != NULL );
fputc ( '\n' , V_60 ) ;
#endif
}
V_3 -> V_23 += strlen ( V_3 -> V_23 ) ;
V_3 -> V_9 ++ ;
V_3 -> V_65 = 0 ;
return '?' ;
}
if ( V_43 != NULL )
{
V_49 = V_48 ;
V_3 -> V_9 ++ ;
if ( * V_40 )
{
if ( V_43 -> V_51 )
V_3 -> V_38 = V_40 + 1 ;
else
{
if ( V_36 )
{
#if V_11 V_12
char * V_56 ;
int V_66 ;
#endif
if ( V_1 [ V_3 -> V_9 - 1 ] [ 1 ] == '-' )
{
#if V_11 V_12
V_66 = F_14 ( & V_56 , _ ( L_6 ) ,
V_1 [ 0 ] , V_43 -> V_50 ) ;
#else
fprintf ( V_60 , _ ( L_6 ) ,
V_1 [ 0 ] , V_43 -> V_50 ) ;
#endif
}
else
{
#if V_11 V_12
V_66 = F_14 ( & V_56 , _ ( L_7 ) ,
V_1 [ 0 ] , V_1 [ V_3 -> V_9 - 1 ] [ 0 ] ,
V_43 -> V_50 ) ;
#else
fprintf ( V_60 , _ ( L_7 ) ,
V_1 [ 0 ] , V_1 [ V_3 -> V_9 - 1 ] [ 0 ] ,
V_43 -> V_50 ) ;
#endif
}
#if V_11 V_12
if ( V_66 >= 0 )
{
F_11 ( V_60 ) ;
int V_61 = ( ( V_62 * ) V_60 ) -> V_63 ;
( ( V_62 * ) V_60 ) -> V_63
|= V_64 ;
F_12 ( NULL , L_5 , V_56 ) ;
( ( V_62 * ) V_60 ) -> V_63 = V_61 ;
F_13 ( V_60 ) ;
free ( V_56 ) ;
}
#endif
}
V_3 -> V_23 += strlen ( V_3 -> V_23 ) ;
V_3 -> V_65 = V_43 -> V_53 ;
return '?' ;
}
}
else if ( V_43 -> V_51 == 1 )
{
if ( V_3 -> V_9 < V_20 )
V_3 -> V_38 = V_1 [ V_3 -> V_9 ++ ] ;
else
{
if ( V_36 )
{
#if V_11 V_12
char * V_56 ;
if ( F_14 ( & V_56 , _ ( L_8 ) ,
V_1 [ 0 ] , V_43 -> V_50 ) >= 0 )
{
F_11 ( V_60 ) ;
int V_61 = ( ( V_62 * ) V_60 ) -> V_63 ;
( ( V_62 * ) V_60 ) -> V_63
|= V_64 ;
F_12 ( NULL , L_5 , V_56 ) ;
( ( V_62 * ) V_60 ) -> V_63 = V_61 ;
F_13 ( V_60 ) ;
free ( V_56 ) ;
}
#else
fprintf ( V_60 ,
_ ( L_9 ) ,
V_1 [ 0 ] , V_43 -> V_50 ) ;
#endif
}
V_3 -> V_23 += strlen ( V_3 -> V_23 ) ;
V_3 -> V_65 = V_43 -> V_53 ;
return V_21 [ 0 ] == ':' ? ':' : '?' ;
}
}
V_3 -> V_23 += strlen ( V_3 -> V_23 ) ;
if ( V_34 != NULL )
* V_34 = V_49 ;
if ( V_43 -> V_52 )
{
* ( V_43 -> V_52 ) = V_43 -> V_53 ;
return 0 ;
}
return V_43 -> V_53 ;
}
if ( ! V_35 || V_1 [ V_3 -> V_9 ] [ 1 ] == '-'
|| strchr ( V_21 , * V_3 -> V_23 ) == NULL )
{
if ( V_36 )
{
#if V_11 V_12
char * V_56 ;
int V_66 ;
#endif
if ( V_1 [ V_3 -> V_9 ] [ 1 ] == '-' )
{
#if V_11 V_12
V_66 = F_14 ( & V_56 , _ ( L_10 ) ,
V_1 [ 0 ] , V_3 -> V_23 ) ;
#else
fprintf ( V_60 , _ ( L_10 ) ,
V_1 [ 0 ] , V_3 -> V_23 ) ;
#endif
}
else
{
#if V_11 V_12
V_66 = F_14 ( & V_56 , _ ( L_11 ) ,
V_1 [ 0 ] , V_1 [ V_3 -> V_9 ] [ 0 ] , V_3 -> V_23 ) ;
#else
fprintf ( V_60 , _ ( L_11 ) ,
V_1 [ 0 ] , V_1 [ V_3 -> V_9 ] [ 0 ] , V_3 -> V_23 ) ;
#endif
}
#if V_11 V_12
if ( V_66 >= 0 )
{
F_11 ( V_60 ) ;
int V_61 = ( ( V_62 * ) V_60 ) -> V_63 ;
( ( V_62 * ) V_60 ) -> V_63 |= V_64 ;
F_12 ( NULL , L_5 , V_56 ) ;
( ( V_62 * ) V_60 ) -> V_63 = V_61 ;
F_13 ( V_60 ) ;
free ( V_56 ) ;
}
#endif
}
V_3 -> V_23 = ( char * ) L_12 ;
V_3 -> V_9 ++ ;
V_3 -> V_65 = 0 ;
return '?' ;
}
}
{
char V_67 = * V_3 -> V_23 ++ ;
char * V_68 = strchr ( V_21 , V_67 ) ;
char * V_40 ;
const struct V_32 * V_42 ;
const struct V_32 * V_43 = NULL ;
int V_47 = 0 ;
int V_69 = 0 ;
int V_48 = 0 ;
int V_49 ;
if ( * V_3 -> V_23 == '\0' )
++ V_3 -> V_9 ;
if ( V_68 == NULL || V_67 == ':' || V_67 == ';' )
{
if ( V_36 )
{
#if V_11 V_12
char * V_56 ;
int V_66 ;
#endif
#if V_11 V_12
V_66 = F_14 ( & V_56 , _ ( L_13 ) ,
V_1 [ 0 ] , V_67 ) ;
#else
fprintf ( V_60 , _ ( L_13 ) , V_1 [ 0 ] , V_67 ) ;
#endif
#if V_11 V_12
if ( V_66 >= 0 )
{
F_11 ( V_60 ) ;
int V_61 = ( ( V_62 * ) V_60 ) -> V_63 ;
( ( V_62 * ) V_60 ) -> V_63 |= V_64 ;
F_12 ( NULL , L_5 , V_56 ) ;
( ( V_62 * ) V_60 ) -> V_63 = V_61 ;
F_13 ( V_60 ) ;
free ( V_56 ) ;
}
#endif
}
V_3 -> V_65 = V_67 ;
return '?' ;
}
if ( V_68 [ 0 ] == 'W' && V_68 [ 1 ] == ';' )
{
if ( V_33 == NULL )
goto V_70;
if ( * V_3 -> V_23 != '\0' )
{
V_3 -> V_38 = V_3 -> V_23 ;
V_3 -> V_9 ++ ;
}
else if ( V_3 -> V_9 == V_20 )
{
if ( V_36 )
{
#if V_11 V_12
char * V_56 ;
if ( F_14 ( & V_56 ,
_ ( L_14 ) ,
V_1 [ 0 ] , V_67 ) >= 0 )
{
F_11 ( V_60 ) ;
int V_61 = ( ( V_62 * ) V_60 ) -> V_63 ;
( ( V_62 * ) V_60 ) -> V_63 |= V_64 ;
F_12 ( NULL , L_5 , V_56 ) ;
( ( V_62 * ) V_60 ) -> V_63 = V_61 ;
F_13 ( V_60 ) ;
free ( V_56 ) ;
}
#else
fprintf ( V_60 ,
_ ( L_14 ) ,
V_1 [ 0 ] , V_67 ) ;
#endif
}
V_3 -> V_65 = V_67 ;
if ( V_21 [ 0 ] == ':' )
V_67 = ':' ;
else
V_67 = '?' ;
return V_67 ;
}
else
V_3 -> V_38 = V_1 [ V_3 -> V_9 ++ ] ;
for ( V_3 -> V_23 = V_40 = V_3 -> V_38 ; * V_40 && * V_40 != '=' ;
V_40 ++ )
;
for ( V_42 = V_33 , V_49 = 0 ; V_42 -> V_50 ; V_42 ++ , V_49 ++ )
if ( ! strncmp ( V_42 -> V_50 , V_3 -> V_23 , V_40 - V_3 -> V_23 ) )
{
if ( ( unsigned int ) ( V_40 - V_3 -> V_23 ) == strlen ( V_42 -> V_50 ) )
{
V_43 = V_42 ;
V_48 = V_49 ;
V_47 = 1 ;
break;
}
else if ( V_43 == NULL )
{
V_43 = V_42 ;
V_48 = V_49 ;
}
else if ( V_35
|| V_43 -> V_51 != V_42 -> V_51
|| V_43 -> V_52 != V_42 -> V_52
|| V_43 -> V_53 != V_42 -> V_53 )
V_69 = 1 ;
}
if ( V_69 && ! V_47 )
{
if ( V_36 )
{
#if V_11 V_12
char * V_56 ;
if ( F_14 ( & V_56 , _ ( L_15 ) ,
V_1 [ 0 ] , V_3 -> V_38 ) >= 0 )
{
F_11 ( V_60 ) ;
int V_61 = ( ( V_62 * ) V_60 ) -> V_63 ;
( ( V_62 * ) V_60 ) -> V_63 |= V_64 ;
F_12 ( NULL , L_5 , V_56 ) ;
( ( V_62 * ) V_60 ) -> V_63 = V_61 ;
F_13 ( V_60 ) ;
free ( V_56 ) ;
}
#else
fprintf ( V_60 , _ ( L_15 ) ,
V_1 [ 0 ] , V_3 -> V_38 ) ;
#endif
}
V_3 -> V_23 += strlen ( V_3 -> V_23 ) ;
V_3 -> V_9 ++ ;
return '?' ;
}
if ( V_43 != NULL )
{
V_49 = V_48 ;
if ( * V_40 )
{
if ( V_43 -> V_51 )
V_3 -> V_38 = V_40 + 1 ;
else
{
if ( V_36 )
{
#if V_11 V_12
char * V_56 ;
if ( F_14 ( & V_56 , _ ( L_16 ) ,
V_1 [ 0 ] , V_43 -> V_50 ) >= 0 )
{
F_11 ( V_60 ) ;
int V_61 = ( ( V_62 * ) V_60 ) -> V_63 ;
( ( V_62 * ) V_60 ) -> V_63
|= V_64 ;
F_12 ( NULL , L_5 , V_56 ) ;
( ( V_62 * ) V_60 ) -> V_63 = V_61 ;
F_13 ( V_60 ) ;
free ( V_56 ) ;
}
#else
fprintf ( V_60 , _ ( L_16 ) ,
V_1 [ 0 ] , V_43 -> V_50 ) ;
#endif
}
V_3 -> V_23 += strlen ( V_3 -> V_23 ) ;
return '?' ;
}
}
else if ( V_43 -> V_51 == 1 )
{
if ( V_3 -> V_9 < V_20 )
V_3 -> V_38 = V_1 [ V_3 -> V_9 ++ ] ;
else
{
if ( V_36 )
{
#if V_11 V_12
char * V_56 ;
if ( F_14 ( & V_56 , _ ( L_17 ) ,
V_1 [ 0 ] , V_43 -> V_50 ) >= 0 )
{
F_11 ( V_60 ) ;
int V_61 = ( ( V_62 * ) V_60 ) -> V_63 ;
( ( V_62 * ) V_60 ) -> V_63
|= V_64 ;
F_12 ( NULL , L_5 , V_56 ) ;
( ( V_62 * ) V_60 ) -> V_63 = V_61 ;
F_13 ( V_60 ) ;
free ( V_56 ) ;
}
#else
fprintf ( V_60 , _ ( L_17 ) ,
V_1 [ 0 ] , V_43 -> V_50 ) ;
#endif
}
V_3 -> V_23 += strlen ( V_3 -> V_23 ) ;
return V_21 [ 0 ] == ':' ? ':' : '?' ;
}
}
else
V_3 -> V_38 = NULL ;
V_3 -> V_23 += strlen ( V_3 -> V_23 ) ;
if ( V_34 != NULL )
* V_34 = V_49 ;
if ( V_43 -> V_52 )
{
* ( V_43 -> V_52 ) = V_43 -> V_53 ;
return 0 ;
}
return V_43 -> V_53 ;
}
V_70:
V_3 -> V_23 = NULL ;
return 'W' ;
}
if ( V_68 [ 1 ] == ':' )
{
if ( V_68 [ 2 ] == ':' )
{
if ( * V_3 -> V_23 != '\0' )
{
V_3 -> V_38 = V_3 -> V_23 ;
V_3 -> V_9 ++ ;
}
else
V_3 -> V_38 = NULL ;
V_3 -> V_23 = NULL ;
}
else
{
if ( * V_3 -> V_23 != '\0' )
{
V_3 -> V_38 = V_3 -> V_23 ;
V_3 -> V_9 ++ ;
}
else if ( V_3 -> V_9 == V_20 )
{
if ( V_36 )
{
#if V_11 V_12
char * V_56 ;
if ( F_14 ( & V_56 , _ ( L_18 ) ,
V_1 [ 0 ] , V_67 ) >= 0 )
{
F_11 ( V_60 ) ;
int V_61 = ( ( V_62 * ) V_60 ) -> V_63 ;
( ( V_62 * ) V_60 ) -> V_63 |= V_64 ;
F_12 ( NULL , L_5 , V_56 ) ;
( ( V_62 * ) V_60 ) -> V_63 = V_61 ;
F_13 ( V_60 ) ;
free ( V_56 ) ;
}
#else
fprintf ( V_60 ,
_ ( L_14 ) ,
V_1 [ 0 ] , V_67 ) ;
#endif
}
V_3 -> V_65 = V_67 ;
if ( V_21 [ 0 ] == ':' )
V_67 = ':' ;
else
V_67 = '?' ;
}
else
V_3 -> V_38 = V_1 [ V_3 -> V_9 ++ ] ;
V_3 -> V_23 = NULL ;
}
}
return V_67 ;
}
}
int
F_15 ( int V_20 , char * const * V_1 , const char * V_21 ,
const struct V_32 * V_33 , int * V_34 , int V_35 ,
int V_22 )
{
int V_71 ;
V_72 . V_9 = V_9 ;
V_72 . V_37 = V_37 ;
V_71 = F_5 ( V_20 , V_1 , V_21 , V_33 ,
V_34 , V_35 , & V_72 ,
V_22 ) ;
V_9 = V_72 . V_9 ;
V_38 = V_72 . V_38 ;
V_65 = V_72 . V_65 ;
return V_71 ;
}
int
F_16 ( int V_20 , char * const * V_1 , const char * V_21 )
{
return F_15 ( V_20 , V_1 , V_21 ,
( const struct V_32 * ) 0 ,
( int * ) 0 ,
0 , 0 ) ;
}
int
F_17 ( int V_20 , char * const * V_1 , const char * V_21 )
{
return F_15 ( V_20 , V_1 , V_21 ,
( const struct V_32 * ) 0 ,
( int * ) 0 ,
0 , 1 ) ;
}
int
main ( int V_20 , char * * V_1 )
{
int V_67 ;
int V_73 = 0 ;
while ( 1 )
{
int V_74 = V_9 ? V_9 : 1 ;
V_67 = F_16 ( V_20 , V_1 , L_19 ) ;
if ( V_67 == - 1 )
break;
switch ( V_67 )
{
case '0' :
case '1' :
case '2' :
case '3' :
case '4' :
case '5' :
case '6' :
case '7' :
case '8' :
case '9' :
if ( V_73 != 0 && V_73 != V_74 )
printf ( L_20 ) ;
V_73 = V_74 ;
printf ( L_21 , V_67 ) ;
break;
case 'a' :
printf ( L_22 ) ;
break;
case 'b' :
printf ( L_23 ) ;
break;
case 'c' :
printf ( L_24 , V_38 ) ;
break;
case '?' :
break;
default:
printf ( L_25 , V_67 ) ;
}
}
if ( V_9 < V_20 )
{
printf ( L_26 ) ;
while ( V_9 < V_20 )
printf ( L_27 , V_1 [ V_9 ++ ] ) ;
printf ( L_28 ) ;
}
exit ( 0 ) ;
}
