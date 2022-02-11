static struct V_1 * F_1 ( char * V_2 ,
struct V_1 * V_3 )
{
struct V_1 * V_4 = V_3 ;
for ( V_4 = V_4 -> V_5 ; V_4 ; V_4 = V_4 -> V_6 ) {
if ( V_4 -> V_7 && ( strcmp ( V_2 , V_4 -> V_2 ) == 0 ) ) {
break;
}
}
if ( V_4 == (struct V_1 * ) 0 ) {
V_4 = F_2 ( V_2 , V_8 , V_3 ) ;
if ( V_4 == (struct V_1 * ) 0 )
return V_4 ;
}
return V_4 ;
}
int
F_3 ( struct V_9 * V_10 ,
char * V_11 ,
T_1 * V_12 ,
T_2 * V_13 ,
struct V_1 * V_14 , void * V_15 )
{
strcpy ( V_10 -> V_11 , V_11 ) ;
V_10 -> V_16 = F_2 ( V_10 -> V_11 ,
V_17 | V_18 |
V_19 | V_20 |
V_21 , V_14 ) ;
if ( V_10 -> V_16 == 0 )
return - 1 ;
V_10 -> V_16 -> V_13 = V_13 ;
V_10 -> V_16 -> V_12 = V_12 ;
V_10 -> V_16 -> V_15 = V_15 ;
return 0 ;
}
int
F_4 ( char * V_22 , char * * V_23 , T_3 V_24 , int V_25 ,
int * V_26 , void * V_15 )
{
T_4 * V_27 = ( T_4 * ) V_15 ;
int V_28 = 0 ;
V_28 += sprintf ( V_22 , L_1 , V_27 -> V_29 ) ;
V_28 +=
sprintf ( V_22 + V_28 , L_2 ,
V_27 -> V_30 ) ;
* V_26 = 1 ;
return V_28 ;
}
int
F_5 ( char * V_22 , char * * V_23 , T_3 V_24 , int V_25 ,
int * V_26 , void * V_15 )
{
T_4 * V_27 = ( T_4 * ) V_15 ;
struct V_31 * V_32 = V_27 -> V_33 ;
struct V_34 * V_35 ;
int V_28 = 0 ;
if ( F_6 ( V_27 ) ) {
V_35 = F_7 ( V_32 ) ;
if ( V_35 )
V_28 = sprintf ( V_22 , L_3 , V_35 -> V_2 ) ;
else
V_28 = sprintf ( V_22 , L_4 ) ;
} else
V_28 = sprintf ( V_22 , L_4 ) ;
* V_26 = 1 ;
return V_28 ;
}
int
F_8 ( char * V_22 , char * * V_23 , T_3 V_24 , int V_25 ,
int * V_26 , void * V_15 )
{
T_4 * V_27 = ( T_4 * ) V_15 ;
int V_28 = 0 , V_36 = 0 ;
V_36 = F_9 ( V_27 ) ;
if ( V_36 == V_37 )
V_28 = sprintf ( V_22 , L_5 ) ;
else
V_28 = sprintf ( V_22 , L_6 , V_36 ) ;
* V_26 = 1 ;
return V_28 ;
}
int
F_10 ( char * V_22 , char * * V_23 , T_3 V_24 , int V_25 ,
int * V_26 , void * V_15 )
{
T_4 * V_27 = ( T_4 * ) V_15 ;
int V_28 = 0 , V_36 = 0 ;
V_36 = F_11 ( V_27 ) ;
if ( V_36 == V_37 )
V_28 = sprintf ( V_22 , L_5 ) ;
else
V_28 = sprintf ( V_22 , L_6 , V_36 ) ;
* V_26 = 1 ;
return V_28 ;
}
int
F_12 ( struct V_38 * V_38 , const char * V_39 ,
unsigned long V_25 , void * V_15 )
{
char V_40 [ 256 ] ;
T_4 * V_27 = ( T_4 * ) V_15 ;
int V_41 = 0 , V_42 = 0 ;
if ( V_25 > ( sizeof( V_40 ) - 1 ) )
return - 1 ;
if ( F_13 ( & V_40 , V_39 , V_25 ) )
return - 1 ;
V_40 [ V_25 ] = '\0' ;
V_42 = strlen ( V_40 ) ;
if ( V_40 [ V_42 - 1 ] == '\n' )
V_40 [ -- V_42 ] = '\0' ;
if ( strcmp ( V_40 , L_7 ) == 0 )
V_41 = 1 ;
else if ( strcmp ( V_40 , L_8 ) == 0 )
V_41 = 0 ;
F_14 ( V_27 , V_41 ) ;
return V_25 ;
}
int
F_15 ( struct V_38 * V_38 , const char * V_39 ,
unsigned long V_25 , void * V_15 )
{
char V_40 [ 256 ] ;
T_4 * V_27 = ( T_4 * ) V_15 ;
int V_43 = 0 , V_42 = 0 ;
if ( V_25 > ( sizeof( V_40 ) - 1 ) )
return - 1 ;
if ( F_13 ( & V_40 , V_39 , V_25 ) )
return - 1 ;
V_40 [ V_25 ] = '\0' ;
V_42 = strlen ( V_40 ) ;
if ( V_40 [ V_42 - 1 ] == '\n' )
V_40 [ -- V_42 ] = '\0' ;
if ( strcmp ( V_40 , L_7 ) == 0 )
V_43 = 1 ;
else if ( strcmp ( V_40 , L_8 ) == 0 )
V_43 = 0 ;
F_16 ( V_27 , V_43 ) ;
return V_25 ;
}
int
F_17 ( struct V_38 * V_38 , const char * V_39 ,
unsigned long V_25 , void * V_15 )
{
char V_40 [ 256 ] ;
T_4 * V_27 = ( T_4 * ) V_15 ;
int V_43 = 0 , V_42 = 0 ;
if ( V_25 > ( sizeof( V_40 ) - 1 ) )
return - 1 ;
if ( F_13 ( & V_40 , V_39 , V_25 ) )
return - 1 ;
V_40 [ V_25 ] = '\0' ;
V_42 = strlen ( V_40 ) ;
if ( V_40 [ V_42 - 1 ] == '\n' )
V_40 [ -- V_42 ] = '\0' ;
if ( strcmp ( V_40 , L_7 ) == 0 )
V_43 = 1 ;
else if ( strcmp ( V_40 , L_8 ) == 0 )
V_43 = 0 ;
F_18 ( V_27 , V_43 ) ;
return V_25 ;
}
int
F_19 ( char * V_22 , char * * V_23 , T_3 V_24 , int V_25 ,
int * V_26 , void * V_15 )
{
T_4 * V_27 = ( T_4 * ) V_15 ;
int V_28 = 0 , V_36 = 0 ;
V_36 = F_20 ( V_27 ) ;
if ( V_36 == V_37 )
V_28 = sprintf ( V_22 , L_4 ) ;
else if ( V_36 == 1 )
V_28 = sprintf ( V_22 , L_9 ) ;
else if ( V_36 == 0 )
V_28 = sprintf ( V_22 , L_10 ) ;
* V_26 = 1 ;
return V_28 ;
}
int
F_21 ( char * V_22 , char * * V_23 , T_3 V_24 , int V_25 ,
int * V_26 , void * V_15 )
{
T_4 * V_27 = ( T_4 * ) V_15 ;
int V_28 = 0 , V_36 = 0 ;
V_36 = F_22 ( V_27 ) ;
if ( V_36 == V_37 )
V_28 = sprintf ( V_22 , L_4 ) ;
else if ( V_36 == 1 )
V_28 = sprintf ( V_22 , L_9 ) ;
else if ( V_36 == 0 )
V_28 = sprintf ( V_22 , L_10 ) ;
* V_26 = 1 ;
return V_28 ;
}
int
F_23 ( char * V_22 , char * * V_23 , T_3 V_24 , int V_25 ,
int * V_26 , void * V_15 )
{
T_4 * V_27 = ( T_4 * ) V_15 ;
int V_28 = 0 , V_36 = 0 ;
V_36 = F_24 ( V_27 ) ;
if ( V_36 == V_37 )
V_28 = sprintf ( V_22 , L_4 ) ;
else if ( V_36 == 1 )
V_28 = sprintf ( V_22 , L_9 ) ;
else if ( V_36 == 0 )
V_28 = sprintf ( V_22 , L_10 ) ;
* V_26 = 1 ;
return V_28 ;
}
int
F_25 ( char * V_22 , char * * V_23 , T_3 V_24 , int V_25 ,
int * V_26 , void * V_15 )
{
T_4 * V_27 = ( T_4 * ) V_15 ;
int V_28 = 0 , V_36 = 0 ;
V_36 = F_26 ( V_27 ) ;
if ( V_36 == 1 )
V_28 = sprintf ( V_22 , L_9 ) ;
else if ( V_36 == 0 )
V_28 = sprintf ( V_22 , L_10 ) ;
else
V_28 = sprintf ( V_22 , L_4 ) ;
* V_26 = 1 ;
return V_28 ;
}
int
F_27 ( char * V_22 , char * * V_23 , T_3 V_24 , int V_25 ,
int * V_26 , void * V_15 )
{
T_4 * V_27 = ( T_4 * ) V_15 ;
int V_28 = 0 , V_36 = 0 ;
V_36 = F_28 ( V_27 ) ;
if ( V_36 == 1 )
V_28 = sprintf ( V_22 , L_9 ) ;
else if ( V_36 == 0 )
V_28 = sprintf ( V_22 , L_10 ) ;
else
V_28 = sprintf ( V_22 , L_4 ) ;
* V_26 = 1 ;
return V_28 ;
}
int
F_29 ( char * V_22 , char * * V_23 , T_3 V_24 , int V_25 ,
int * V_26 , void * V_15 )
{
T_4 * V_27 = ( T_4 * ) V_15 ;
int V_28 = 0 , V_36 = 0 ;
V_36 = F_30 ( V_27 ) ;
if ( V_36 == 1 )
V_28 = sprintf ( V_22 , L_9 ) ;
else if ( V_36 == 0 )
V_28 = sprintf ( V_22 , L_10 ) ;
else
V_28 = sprintf ( V_22 , L_4 ) ;
* V_26 = 1 ;
return V_28 ;
}
int
F_31 ( struct V_38 * V_38 , const char * V_39 ,
unsigned long V_25 , void * V_15 )
{
char V_40 [ 256 ] ;
T_4 * V_27 = ( T_4 * ) V_15 ;
unsigned int V_44 = 0 ;
char * V_45 = V_40 ;
if ( F_13 ( & V_40 , V_39 , V_25 ) )
return - 1 ;
V_45 = V_40 ;
V_44 = atoi ( & V_45 ) ;
F_32 ( V_27 , V_44 ) ;
return V_25 ;
}
int
F_33 ( char * V_22 , char * * V_23 , T_3 V_24 , int V_25 ,
int * V_26 , void * V_15 )
{
T_4 * V_27 = ( T_4 * ) V_15 ;
int V_28 = 0 , V_36 = 0 , V_44 = 0 ;
V_36 = F_34 ( V_27 , & V_44 ) ;
if ( V_36 == V_37 )
V_28 = sprintf ( V_22 , L_4 ) ;
else if ( V_44 == - 1 )
V_28 = sprintf ( V_22 , L_11 ) ;
else if ( V_44 == 0 )
V_28 = sprintf ( V_22 , L_12 ) ;
else
V_28 = sprintf ( V_22 , L_13 , V_44 ) ;
* V_26 = 1 ;
return V_28 ;
}
int
F_35 ( char * V_22 , char * * V_23 , T_3 V_24 , int V_25 ,
int * V_26 , void * V_15 )
{
T_4 * V_27 = ( T_4 * ) V_15 ;
int V_28 = 0 , V_36 = 0 , V_44 = 0 ;
V_36 = F_36 ( V_27 , & V_44 ) ;
if ( V_36 == V_37 )
V_28 = sprintf ( V_22 , L_4 ) ;
else if ( V_44 == - 1 )
V_28 = sprintf ( V_22 , L_14 ) ;
else if ( V_44 == 0 )
V_28 = sprintf ( V_22 , L_12 ) ;
else
V_28 = sprintf ( V_22 , L_13 , V_44 ) ;
* V_26 = 1 ;
return V_28 ;
}
int
F_37 ( char * V_22 , char * * V_23 , T_3 V_24 , int V_25 ,
int * V_26 , void * V_15 )
{
T_4 * V_27 = ( T_4 * ) V_15 ;
int V_28 = 0 , V_36 = 0 ;
V_36 = F_38 ( V_27 ) ;
if ( V_36 == V_37 )
V_28 = sprintf ( V_22 , L_4 ) ;
else if ( V_36 == 1 )
V_28 = sprintf ( V_22 , L_9 ) ;
else if ( V_36 == 0 )
V_28 = sprintf ( V_22 , L_10 ) ;
* V_26 = 1 ;
return V_28 ;
}
int
F_39 ( char * V_22 , char * * V_23 , T_3 V_24 , int V_25 ,
int * V_26 , void * V_15 )
{
T_4 * V_27 = ( T_4 * ) V_15 ;
int V_28 = 0 , V_36 = 0 ;
V_36 = F_40 ( V_27 ) ;
if ( V_36 == V_37 )
V_28 = sprintf ( V_22 , L_4 ) ;
else if ( V_36 == 1 )
V_28 = sprintf ( V_22 , L_9 ) ;
else if ( V_36 == 0 )
V_28 = sprintf ( V_22 , L_10 ) ;
* V_26 = 1 ;
return V_28 ;
}
int
F_41 ( char * V_22 , char * * V_23 , T_3 V_24 , int V_25 ,
int * V_26 , void * V_15 )
{
T_4 * V_27 = ( T_4 * ) V_15 ;
int V_28 = 0 , V_36 = 0 ;
V_36 = F_42 ( V_27 ) ;
if ( V_36 == V_37 )
V_28 = sprintf ( V_22 , L_4 ) ;
else if ( V_36 == 1 )
V_28 = sprintf ( V_22 , L_9 ) ;
else if ( V_36 == 0 )
V_28 = sprintf ( V_22 , L_10 ) ;
* V_26 = 1 ;
return V_28 ;
}
int
F_43 ( char * V_22 , char * * V_23 , T_3 V_24 , int V_25 ,
int * V_26 , void * V_15 )
{
T_4 * V_27 = ( T_4 * ) V_15 ;
int V_28 = 0 , V_36 = 0 ;
V_36 = F_44 ( V_27 ) ;
if ( V_36 == V_37 )
V_28 = sprintf ( V_22 , L_4 ) ;
else if ( V_36 == 0 )
V_28 = sprintf ( V_22 , L_12 ) ;
else if ( V_36 == 1 )
V_28 = sprintf ( V_22 , L_15 ) ;
* V_26 = 1 ;
return V_28 ;
}
int
F_45 ( struct V_38 * V_38 , const char * V_39 ,
unsigned long V_25 , void * V_15 )
{
char V_40 [ 256 ] ;
T_4 * V_27 = ( T_4 * ) V_15 ;
int V_41 = 0 , V_42 = 0 ;
if ( F_13 ( & V_40 , V_39 , V_25 ) )
return - 1 ;
V_40 [ V_25 ] = '\0' ;
V_42 = strlen ( V_40 ) ;
if ( V_40 [ V_42 - 1 ] == '\n' )
V_40 [ -- V_42 ] = '\0' ;
if ( strcmp ( V_40 , L_7 ) == 0 )
V_41 = 1 ;
else if ( strcmp ( V_40 , L_8 ) == 0 )
V_41 = 0 ;
F_46 ( V_27 , V_41 ) ;
return V_25 ;
}
int
F_47 ( struct V_38 * V_38 , const char * V_39 ,
unsigned long V_25 , void * V_15 )
{
char V_40 [ 256 ] ;
T_4 * V_27 = ( T_4 * ) V_15 ;
int V_43 = 0 , V_42 = 0 ;
if ( F_13 ( & V_40 , V_39 , V_25 ) )
return - 1 ;
V_40 [ V_25 ] = '\0' ;
V_42 = strlen ( V_40 ) ;
if ( V_40 [ V_42 - 1 ] == '\n' )
V_40 [ -- V_42 ] = '\0' ;
if ( strcmp ( V_40 , L_7 ) == 0 )
V_43 = 1 ;
else if ( strcmp ( V_40 , L_8 ) == 0 )
V_43 = 0 ;
F_48 ( V_27 , V_43 ) ;
return V_25 ;
}
int
F_49 ( struct V_38 * V_38 , const char * V_39 ,
unsigned long V_25 , void * V_15 )
{
char V_40 [ 256 ] ;
T_4 * V_27 = ( T_4 * ) V_15 ;
int V_43 = 0 , V_42 = 0 ;
if ( F_13 ( & V_40 , V_39 , V_25 ) )
return - 1 ;
V_40 [ V_25 ] = '\0' ;
V_42 = strlen ( V_40 ) ;
if ( V_40 [ V_42 - 1 ] == '\n' )
V_40 [ -- V_42 ] = '\0' ;
if ( strcmp ( V_40 , L_7 ) == 0 )
V_43 = 1 ;
else if ( strcmp ( V_40 , L_8 ) == 0 )
V_43 = 0 ;
F_50 ( V_27 , V_43 ) ;
return V_25 ;
}
int
F_51 ( char * V_22 , char * * V_23 , T_3 V_24 , int V_25 ,
int * V_26 , void * V_15 )
{
T_4 * V_27 = ( T_4 * ) V_15 ;
int V_28 = 0 , V_36 = 0 ;
V_36 = F_52 ( V_27 ) ;
if ( V_36 == V_37 )
V_28 = sprintf ( V_22 , L_4 ) ;
else if ( V_36 == 0 )
V_28 = sprintf ( V_22 , L_10 ) ;
else
V_28 = sprintf ( V_22 , L_9 ) ;
* V_26 = 1 ;
return V_28 ;
}
int
F_53 ( char * V_22 , char * * V_23 , T_3 V_24 , int V_25 ,
int * V_26 , void * V_15 )
{
T_4 * V_27 = ( T_4 * ) V_15 ;
int V_28 = 0 , V_36 = 0 ;
V_36 = F_54 ( V_27 ) ;
if ( V_36 == V_37 )
V_28 = sprintf ( V_22 , L_4 ) ;
else if ( V_36 == 0 )
V_28 = sprintf ( V_22 , L_10 ) ;
else
V_28 = sprintf ( V_22 , L_9 ) ;
* V_26 = 1 ;
return V_28 ;
}
int
F_55 ( char * V_22 , char * * V_23 , T_3 V_24 , int V_25 ,
int * V_26 , void * V_15 )
{
T_4 * V_27 = ( T_4 * ) V_15 ;
int V_28 = 0 , V_36 = 0 ;
V_36 = F_56 ( V_27 ) ;
if ( V_36 == V_37 )
V_28 = sprintf ( V_22 , L_4 ) ;
else if ( V_36 == 0 )
V_28 = sprintf ( V_22 , L_10 ) ;
else
V_28 = sprintf ( V_22 , L_9 ) ;
* V_26 = 1 ;
return V_28 ;
}
int
F_57 ( struct V_38 * V_38 , const char * V_39 ,
unsigned long V_25 , void * V_15 )
{
char V_40 [ 256 ] ;
T_4 * V_27 = ( T_4 * ) V_15 ;
int V_41 = 0 , V_42 = 0 ;
if ( F_13 ( & V_40 , V_39 , V_25 ) )
return - 1 ;
V_40 [ V_25 ] = '\0' ;
V_42 = strlen ( V_40 ) ;
if ( V_40 [ V_42 - 1 ] == '\n' )
V_40 [ -- V_42 ] = '\0' ;
if ( strcmp ( V_40 , L_7 ) == 0 )
V_41 = 1 ;
else if ( strcmp ( V_40 , L_8 ) == 0 )
V_41 = 0 ;
F_58 ( V_27 , V_41 ) ;
return V_25 ;
}
int
F_59 ( struct V_38 * V_38 , const char * V_39 ,
unsigned long V_25 , void * V_15 )
{
char V_40 [ 256 ] ;
T_4 * V_27 = ( T_4 * ) V_15 ;
int V_41 = 0 , V_42 = 0 ;
if ( F_13 ( & V_40 , V_39 , V_25 ) )
return - 1 ;
V_40 [ V_25 ] = '\0' ;
V_42 = strlen ( V_40 ) ;
if ( V_40 [ V_42 - 1 ] == '\n' )
V_40 [ -- V_42 ] = '\0' ;
if ( strcmp ( V_40 , L_7 ) == 0 )
V_41 = 1 ;
else if ( strcmp ( V_40 , L_8 ) == 0 )
V_41 = 0 ;
F_60 ( V_27 , V_41 ) ;
return V_25 ;
}
int
F_61 ( struct V_38 * V_38 , const char * V_39 ,
unsigned long V_25 , void * V_15 )
{
char V_40 [ 256 ] ;
T_4 * V_27 = ( T_4 * ) V_15 ;
int V_43 = 0 , V_42 = 0 ;
if ( F_13 ( & V_40 , V_39 , V_25 ) )
return - 1 ;
V_40 [ V_25 ] = '\0' ;
V_42 = strlen ( V_40 ) ;
if ( V_40 [ V_42 - 1 ] == '\n' )
V_40 [ -- V_42 ] = '\0' ;
if ( strcmp ( V_40 , L_7 ) == 0 )
V_43 = 1 ;
else if ( strcmp ( V_40 , L_8 ) == 0 )
V_43 = 0 ;
F_62 ( V_27 , V_43 ) ;
return V_25 ;
}
int
F_63 ( struct V_38 * V_38 , const char * V_39 ,
unsigned long V_25 , void * V_15 )
{
char V_40 [ 256 ] ;
T_4 * V_27 = ( T_4 * ) V_15 ;
int V_43 = 0 , V_42 = 0 ;
if ( F_13 ( & V_40 , V_39 , V_25 ) )
return - 1 ;
V_40 [ V_25 ] = '\0' ;
V_42 = strlen ( V_40 ) ;
if ( V_40 [ V_42 - 1 ] == '\n' )
V_40 [ -- V_42 ] = '\0' ;
if ( strcmp ( V_40 , L_7 ) == 0 )
V_43 = 1 ;
else if ( strcmp ( V_40 , L_8 ) == 0 )
V_43 = 0 ;
F_64 ( V_27 , V_43 ) ;
return V_25 ;
}
int
F_65 ( char * V_22 , char * * V_23 , T_3 V_24 , int V_25 ,
int * V_26 , void * V_15 )
{
T_4 * V_27 = ( T_4 * ) V_15 ;
int V_28 = 0 , V_36 = 0 ;
V_36 = F_66 ( V_27 ) ;
if ( V_36 == V_37 )
V_28 = sprintf ( V_22 , L_4 ) ;
else if ( V_36 == 0 )
V_28 = sprintf ( V_22 , L_10 ) ;
else
V_28 = sprintf ( V_22 , L_9 ) ;
* V_26 = 1 ;
return V_28 ;
}
int
F_67 ( char * V_22 , char * * V_23 , T_3 V_24 , int V_25 ,
int * V_26 , void * V_15 )
{
T_4 * V_27 = ( T_4 * ) V_15 ;
int V_28 = 0 , V_36 = 0 ;
V_36 = F_68 ( V_27 ) ;
if ( V_36 == V_37 )
V_28 = sprintf ( V_22 , L_4 ) ;
else if ( V_36 == 0 )
V_28 = sprintf ( V_22 , L_10 ) ;
else
V_28 = sprintf ( V_22 , L_9 ) ;
* V_26 = 1 ;
return V_28 ;
}
int
F_69 ( char * V_22 , char * * V_23 , T_3 V_24 , int V_25 ,
int * V_26 , void * V_15 )
{
T_4 * V_27 = ( T_4 * ) V_15 ;
int V_28 = 0 , V_36 = 0 ;
V_36 = F_70 ( V_27 ) ;
if ( V_36 == V_37 )
V_28 = sprintf ( V_22 , L_4 ) ;
else if ( V_36 == 0 )
V_28 = sprintf ( V_22 , L_10 ) ;
else
V_28 = sprintf ( V_22 , L_9 ) ;
* V_26 = 1 ;
return V_28 ;
}
int
F_71 ( char * V_22 , char * * V_23 , T_3 V_24 , int V_25 ,
int * V_26 , void * V_15 )
{
T_4 * V_27 = ( T_4 * ) V_15 ;
int V_28 = 0 , V_36 = 0 ;
V_36 = F_72 ( V_27 ) ;
if ( V_36 == V_37 )
V_28 = sprintf ( V_22 , L_4 ) ;
else if ( V_36 == 0 )
V_28 = sprintf ( V_22 , L_10 ) ;
else
V_28 = sprintf ( V_22 , L_9 ) ;
* V_26 = 1 ;
return V_28 ;
}
int
F_73 ( struct V_38 * V_38 , const char * V_39 ,
unsigned long V_25 , void * V_15 )
{
char V_40 [ 256 ] ;
T_4 * V_27 = ( T_4 * ) V_15 ;
int V_41 = 0 , V_42 = 0 ;
if ( F_13 ( & V_40 , V_39 , V_25 ) )
return - 1 ;
V_40 [ V_25 ] = '\0' ;
V_42 = strlen ( V_40 ) ;
if ( V_40 [ V_42 - 1 ] == '\n' )
V_40 [ -- V_42 ] = '\0' ;
if ( strcmp ( V_40 , L_7 ) == 0 )
V_41 = 1 ;
else if ( strcmp ( V_40 , L_8 ) == 0 )
V_41 = 0 ;
F_74 ( V_27 , V_41 ) ;
return V_25 ;
}
int
F_75 ( char * V_22 , char * * V_23 , T_3 V_24 , int V_25 ,
int * V_26 , void * V_15 )
{
T_4 * V_27 = ( T_4 * ) V_15 ;
int V_28 = 0 , V_36 = 0 ;
V_36 = F_76 ( V_27 ) ;
if ( V_36 == V_37 )
V_28 = sprintf ( V_22 , L_4 ) ;
else if ( V_36 == 0 )
V_28 = sprintf ( V_22 , L_10 ) ;
else
V_28 = sprintf ( V_22 , L_9 ) ;
* V_26 = 1 ;
return V_28 ;
}
int
F_77 ( char * V_22 , char * * V_23 , T_3 V_24 , int V_25 ,
int * V_26 , void * V_15 )
{
T_4 * V_27 = ( T_4 * ) V_15 ;
int V_28 = 0 , V_36 = 0 ;
V_36 = F_78 ( V_27 ) ;
if ( V_36 == 1 )
V_28 = sprintf ( V_22 , L_16 ) ;
else if ( V_36 == 0 )
V_28 = sprintf ( V_22 , L_17 ) ;
else if ( V_36 == 2 )
V_28 = sprintf ( V_22 , L_18 ) ;
else
V_28 = sprintf ( V_22 , L_4 ) ;
* V_26 = 1 ;
return V_28 ;
}
int
F_79 ( struct V_38 * V_38 , const char * V_39 ,
unsigned long V_25 , void * V_15 )
{
char V_40 [ 256 ] ;
T_4 * V_27 = ( T_4 * ) V_15 ;
int V_41 = 0 , V_42 = 0 ;
if ( V_25 > ( sizeof( V_40 ) - 1 ) )
return - 1 ;
if ( F_13 ( & V_40 , V_39 , V_25 ) )
return - 1 ;
V_40 [ V_25 ] = '\0' ;
V_42 = strlen ( V_40 ) ;
if ( V_40 [ V_42 - 1 ] == '\n' )
V_40 [ -- V_42 ] = '\0' ;
if ( strcmp ( V_40 , L_19 ) == 0 )
V_41 = 1 ;
else if ( strcmp ( V_40 , L_20 ) == 0 )
V_41 = 0 ;
else if ( strcmp ( V_40 , L_21 ) == 0 )
V_41 = 2 ;
F_80 ( V_27 , V_41 ) ;
return V_25 ;
}
int
F_81 ( char * V_22 , char * * V_23 , T_3 V_24 , int V_25 ,
int * V_26 , void * V_15 )
{
T_4 * V_27 = ( T_4 * ) V_15 ;
int V_28 = 0 , V_36 = 0 ;
V_36 = F_82 ( V_27 ) ;
if ( V_36 >= 0 )
V_28 = sprintf ( V_22 , L_13 , V_36 ) ;
else
V_28 = sprintf ( V_22 , L_4 ) ;
* V_26 = 1 ;
return V_28 ;
}
int
F_83 ( struct V_38 * V_38 , const char * V_39 ,
unsigned long V_25 , void * V_15 )
{
char V_40 [ 256 ] ;
T_4 * V_27 = ( T_4 * ) V_15 ;
T_5 V_44 = 0 ;
char * V_45 = V_40 ;
if ( F_13 ( & V_40 , V_39 , V_25 ) )
return - 1 ;
V_45 = V_40 ;
V_44 = atoi ( & V_45 ) ;
F_84 ( V_27 , V_44 ) ;
return V_25 ;
}
int
F_85 ( struct V_38 * V_38 , const char * V_39 ,
unsigned long V_25 , void * V_15 )
{
char V_40 [ 256 ] ;
T_4 * V_27 = ( T_4 * ) V_15 ;
int V_46 = 0 , V_42 = 0 ;
if ( V_25 > ( sizeof( V_40 ) - 1 ) )
return - 1 ;
if ( F_13 ( & V_40 , V_39 , V_25 ) )
return - 1 ;
V_40 [ V_25 ] = '\0' ;
V_42 = strlen ( V_40 ) ;
if ( V_40 [ V_42 - 1 ] == '\n' )
V_40 [ -- V_42 ] = '\0' ;
if ( strcmp ( V_40 , L_7 ) == 0 )
V_46 = 1 ;
else if ( strcmp ( V_40 , L_8 ) == 0 )
V_46 = 0 ;
F_86 ( V_27 , V_46 ) ;
return V_25 ;
}
int
F_87 ( struct V_38 * V_38 , const char * V_39 ,
unsigned long V_25 , void * V_15 )
{
char V_40 [ 256 ] ;
T_4 * V_27 = ( T_4 * ) V_15 ;
int V_46 = 0 , V_42 = 0 ;
if ( V_25 > ( sizeof( V_40 ) - 1 ) )
return - 1 ;
if ( F_13 ( & V_40 , V_39 , V_25 ) )
return - 1 ;
V_40 [ V_25 ] = '\0' ;
V_42 = strlen ( V_40 ) ;
if ( V_40 [ V_42 - 1 ] == '\n' )
V_40 [ -- V_42 ] = '\0' ;
if ( strcmp ( V_40 , L_7 ) == 0 )
V_46 = 1 ;
else if ( strcmp ( V_40 , L_8 ) == 0 )
V_46 = 0 ;
F_88 ( V_27 , V_46 ) ;
return V_25 ;
}
int
F_89 ( struct V_38 * V_38 , const char * V_39 ,
unsigned long V_25 , void * V_15 )
{
char V_40 [ 256 ] ;
T_4 * V_27 = ( T_4 * ) V_15 ;
int V_46 = 0 , V_42 = 0 ;
if ( V_25 > ( sizeof( V_40 ) - 1 ) )
return - 1 ;
if ( F_13 ( & V_40 , V_39 , V_25 ) )
return - 1 ;
V_40 [ V_25 ] = '\0' ;
V_42 = strlen ( V_40 ) ;
if ( V_40 [ V_42 - 1 ] == '\n' )
V_40 [ -- V_42 ] = '\0' ;
if ( strcmp ( V_40 , L_7 ) == 0 )
V_46 = 1 ;
else if ( strcmp ( V_40 , L_8 ) == 0 )
V_46 = 0 ;
F_90 ( V_27 , V_46 ) ;
return V_25 ;
}
int F_91 ( T_4 * V_27 )
{
struct V_47 * V_48 = & ( V_27 -> V_49 ) ;
static struct V_1 * V_50 ;
int V_36 = 0 ;
sprintf ( V_48 -> V_51 , L_22 , V_52 -> V_2 ) ;
if ( ! V_53 )
return - 1 ;
V_50 = F_1 ( V_48 -> V_51 , V_53 ) ;
if ( V_50 == 0 ) {
F_92 ( V_54 L_23 ,
V_48 -> V_51 ) ;
return - 1 ;
}
V_48 -> V_55 = V_50 ;
if ( F_93 ( & ( V_48 -> V_56 ) , V_57 , NULL ,
F_4 ,
V_50 , V_27 ) )
V_36 = - 1 ;
if ( V_27 -> V_58 & V_59 ) {
if ( F_3 ( & ( V_48 -> V_60 ) , V_61 , NULL ,
F_5 ,
V_50 , V_27 ) )
V_36 = - 1 ;
if ( F_3 ( & ( V_48 -> V_62 ) , V_63 , NULL ,
F_8 ,
V_50 , V_27 ) )
V_36 = - 1 ;
if ( F_3 ( & ( V_48 -> V_64 ) , V_65 , NULL ,
F_10 ,
V_50 , V_27 ) )
V_36 = - 1 ;
if ( F_3 ( & ( V_48 -> V_66 ) , V_67 , F_31 ,
F_33 ,
V_50 , V_27 ) )
V_36 = - 1 ;
if ( F_3 ( & ( V_48 -> V_68 ) , V_69 , NULL ,
F_35 ,
V_50 , V_27 ) )
V_36 = - 1 ;
if ( F_3 ( & ( V_48 -> V_70 ) , V_71 , NULL ,
F_43 ,
V_50 , V_27 ) )
V_36 = - 1 ;
if ( F_3 ( & ( V_48 -> V_72 ) , V_73 , F_73 ,
F_75 ,
V_50 , V_27 ) )
V_36 = - 1 ;
if ( V_27 -> V_58 & V_74 ) {
if ( F_3 ( & ( V_48 -> V_75 ) , V_76 , F_12 ,
F_19 ,
V_50 ,
V_27 ) )
V_36 = - 1 ;
if ( F_3 ( & ( V_48 -> V_77 ) , V_78 , F_45 ,
F_51 ,
V_50 ,
V_27 ) )
V_36 = - 1 ;
if ( F_3 ( & ( V_48 -> V_79 ) , V_80 , F_57 ,
F_65 ,
V_50 ,
V_27 ) )
V_36 = - 1 ;
if ( F_3 ( & ( V_48 -> V_81 ) , V_82 , F_59 ,
F_67 ,
V_50 ,
V_27 ) )
V_36 = - 1 ;
if ( F_3 ( & ( V_48 -> V_83 ) , V_84 , NULL ,
F_25 ,
V_50 ,
V_27 ) )
V_36 = - 1 ;
}
if ( V_27 -> V_58 & V_85 ) {
if ( F_3 ( & ( V_48 -> V_86 ) , V_87 , F_15 ,
F_21 ,
V_50 ,
V_27 ) )
V_36 = - 1 ;
if ( F_3 ( & ( V_48 -> V_88 ) , V_89 , F_47 ,
F_53 ,
V_50 ,
V_27 ) )
V_36 = - 1 ;
if ( F_3 ( & ( V_48 -> V_90 ) , V_91 , F_61 ,
F_69 ,
V_50 ,
V_27 ) )
V_36 = - 1 ;
if ( F_3 ( & ( V_48 -> V_92 ) , V_93 , NULL ,
F_27 ,
V_50 ,
V_27 ) )
V_36 = - 1 ;
}
if ( V_27 -> V_58 & V_94 ) {
if ( F_3 ( & ( V_48 -> V_86 ) , V_95 , F_17 ,
F_23 ,
V_50 ,
V_27 ) )
V_36 = - 1 ;
#if 1
if ( F_3 ( & ( V_48 -> V_88 ) , V_96 , F_49 ,
F_55 ,
V_50 ,
V_27 ) )
V_36 = - 1 ;
#endif
if ( F_3 ( & ( V_48 -> V_90 ) , V_97 , F_63 ,
F_71 ,
V_50 ,
V_27 ) )
V_36 = - 1 ;
if ( F_3 ( & ( V_48 -> V_92 ) , V_98 , NULL ,
F_29 ,
V_50 ,
V_27 ) )
V_36 = - 1 ;
}
if ( F_3 ( & ( V_48 -> V_99 ) , V_100 , F_79 ,
F_77 ,
V_50 , V_27 ) )
V_36 = - 1 ;
if ( F_3 ( & ( V_48 -> V_101 ) , V_102 , F_83 ,
F_81 ,
V_50 , V_27 ) )
V_36 = - 1 ;
if ( F_3 ( & ( V_48 -> V_103 ) , V_104 , F_85 ,
F_37 ,
V_50 , V_27 ) )
V_36 = - 1 ;
#ifdef F_94
if ( F_3 ( & ( V_48 -> V_103 ) , V_105 , F_87 ,
F_39 ,
V_50 , V_27 ) )
V_36 = - 1 ;
if ( F_3 ( & ( V_48 -> V_103 ) , V_106 , F_89 ,
F_41 ,
V_50 , V_27 ) )
V_36 = - 1 ;
#endif
}
if ( V_36 < 0 )
F_92 ( V_54 L_24 ) ;
return V_36 ;
}
int F_95 ( T_4 * V_27 )
{
struct V_47 * V_48 = & V_27 -> V_49 ;
struct V_1 * V_4 = V_48 -> V_55 , * V_107 =
NULL ;
char V_2 [ 256 ] ;
for ( V_4 = V_4 -> V_5 ; V_4 ; ) {
strcpy ( V_2 , V_4 -> V_2 ) ;
V_107 = V_4 ;
V_4 = V_4 -> V_6 ;
F_96 ( V_2 , V_48 -> V_55 ) ;
}
if ( ! V_4 )
F_96 ( V_48 -> V_51 , V_53 ) ;
return 0 ;
}
