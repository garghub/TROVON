static int F_1 ( T_1 * * V_1 , const T_2 * V_2 )
{
T_3 * V_3 = F_2 ( sizeof( * V_3 ) ) ;
if ( V_3 == NULL )
goto V_4;
if ( ( V_3 -> V_5 = F_3 () ) == NULL )
goto V_4;
if ( ( V_3 -> V_6 = F_4 () ) == NULL )
goto V_4;
V_3 -> V_7 = 1 ;
* V_1 = ( T_1 * ) V_3 ;
return 1 ;
V_4:
F_5 ( V_8 , V_9 ) ;
if ( V_3 ) {
F_6 ( V_3 -> V_5 ) ;
F_7 ( V_3 ) ;
}
return 0 ;
}
static void F_8 ( T_1 * * V_10 , const T_2 * V_2 )
{
T_3 * V_11 ;
if ( ! V_10 || ! * V_10 )
return;
V_11 = ( T_3 * ) * V_10 ;
F_9 ( V_11 -> V_6 ) ;
F_10 ( V_11 -> V_5 , V_12 ) ;
F_7 ( V_11 -> V_13 ) ;
F_7 ( V_11 ) ;
* V_10 = NULL ;
}
static int F_11 ( T_1 * * V_1 ,
const unsigned char * * V_14 , long V_15 ,
const T_2 * V_2 , int V_16 , int V_17 ,
char V_18 , T_4 * V_19 )
{
const unsigned char * V_20 = * V_14 , * V_21 ;
union {
F_12 ( V_22 ) * V_23 ;
T_1 * V_11 ;
} V_24 = {
NULL
} ;
union {
T_3 * V_25 ;
T_1 * V_11 ;
} V_26 = {
NULL
} ;
int V_27 , V_28 , V_3 ;
F_12 ( V_29 ) * V_5 ;
V_29 * V_30 ;
if ( V_15 > V_31 )
V_15 = V_31 ;
V_21 = V_20 ;
V_3 = F_13 ( & V_24 . V_11 ,
& V_20 , V_15 , F_14 ( V_32 ) ,
V_16 , V_17 , V_18 , V_19 ) ;
if ( V_3 <= 0 )
return V_3 ;
if ( * V_1 )
F_8 ( V_1 , NULL ) ;
if ( ! F_1 ( & V_26 . V_11 , NULL ) )
goto V_33;
if ( ! F_15 ( V_26 . V_25 -> V_6 , V_20 - V_21 ) )
goto V_33;
memcpy ( V_26 . V_25 -> V_6 -> V_34 , V_21 , V_20 - V_21 ) ;
for ( V_27 = 0 ; V_27 < F_16 ( V_24 . V_23 ) ; V_27 ++ ) {
V_5 = F_17 ( V_24 . V_23 , V_27 ) ;
for ( V_28 = 0 ; V_28 < F_18 ( V_5 ) ; V_28 ++ ) {
V_30 = F_19 ( V_5 , V_28 ) ;
V_30 -> V_35 = V_27 ;
if ( ! F_20 ( V_26 . V_25 -> V_5 , V_30 ) ) {
F_10 ( V_5 , V_12 ) ;
goto V_33;
}
F_21 ( V_5 , V_28 , NULL ) ;
}
F_6 ( V_5 ) ;
F_22 ( V_24 . V_23 , V_27 , NULL ) ;
}
F_23 ( V_24 . V_23 ) ;
V_24 . V_23 = NULL ;
V_3 = F_24 ( V_26 . V_25 ) ;
if ( ! V_3 )
goto V_33;
V_26 . V_25 -> V_7 = 0 ;
* V_1 = V_26 . V_11 ;
* V_14 = V_20 ;
return V_3 ;
V_33:
F_25 ( V_26 . V_25 ) ;
F_26 ( V_24 . V_23 , F_6 ) ;
F_5 ( V_36 , V_37 ) ;
return 0 ;
}
static int F_27 ( T_1 * * V_1 , unsigned char * * V_38 ,
const T_2 * V_2 , int V_16 , int V_17 )
{
int V_3 ;
T_3 * V_11 = ( T_3 * ) * V_1 ;
if ( V_11 -> V_7 ) {
V_3 = F_28 ( V_11 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_24 ( V_11 ) ;
if ( V_3 < 0 )
return V_3 ;
}
V_3 = V_11 -> V_6 -> V_39 ;
if ( V_38 != NULL ) {
memcpy ( * V_38 , V_11 -> V_6 -> V_34 , V_3 ) ;
* V_38 += V_3 ;
}
return V_3 ;
}
static int F_28 ( T_3 * V_11 )
{
union {
F_12 ( V_22 ) * V_23 ;
T_1 * V_11 ;
} V_24 = {
NULL
} ;
int V_15 ;
unsigned char * V_20 ;
F_12 ( V_29 ) * V_5 = NULL ;
V_29 * V_30 ;
int V_27 , V_35 = - 1 ;
V_24 . V_23 = F_29 () ;
if ( ! V_24 . V_23 )
goto V_4;
for ( V_27 = 0 ; V_27 < F_18 ( V_11 -> V_5 ) ; V_27 ++ ) {
V_30 = F_19 ( V_11 -> V_5 , V_27 ) ;
if ( V_30 -> V_35 != V_35 ) {
V_5 = F_3 () ;
if ( ! V_5 )
goto V_4;
if ( ! F_30 ( V_24 . V_23 , V_5 ) )
goto V_4;
V_35 = V_30 -> V_35 ;
}
if ( ! F_20 ( V_5 , V_30 ) )
goto V_4;
}
V_15 = F_31 ( & V_24 . V_11 , NULL ,
F_14 ( V_32 ) , - 1 , - 1 ) ;
if ( ! F_15 ( V_11 -> V_6 , V_15 ) )
goto V_4;
V_20 = ( unsigned char * ) V_11 -> V_6 -> V_34 ;
F_31 ( & V_24 . V_11 ,
& V_20 , F_14 ( V_32 ) , - 1 , - 1 ) ;
F_26 ( V_24 . V_23 ,
V_40 ) ;
V_11 -> V_7 = 0 ;
return V_15 ;
V_4:
F_26 ( V_24 . V_23 ,
V_40 ) ;
F_5 ( V_41 , V_9 ) ;
return - 1 ;
}
static int F_32 ( T_5 * V_38 , T_1 * * V_10 ,
int V_42 ,
const char * V_43 , const T_6 * V_44 )
{
if ( F_33 ( V_38 , ( const T_3 * ) * V_10 ,
V_42 , V_44 -> V_45 ) <= 0 )
return 0 ;
return 2 ;
}
static int F_24 ( T_3 * V_11 )
{
unsigned char * V_20 ;
F_12 ( V_22 ) * V_24 = NULL ;
F_12 ( V_29 ) * V_5 = NULL ;
V_29 * V_30 , * V_46 = NULL ;
int V_27 , V_35 = - 1 , V_3 = 0 , V_15 ;
F_7 ( V_11 -> V_13 ) ;
V_11 -> V_13 = NULL ;
if ( F_18 ( V_11 -> V_5 ) == 0 ) {
V_11 -> V_47 = 0 ;
return 1 ;
}
V_24 = F_29 () ;
if ( ! V_24 )
goto V_33;
for ( V_27 = 0 ; V_27 < F_18 ( V_11 -> V_5 ) ; V_27 ++ ) {
V_30 = F_19 ( V_11 -> V_5 , V_27 ) ;
if ( V_30 -> V_35 != V_35 ) {
V_5 = F_3 () ;
if ( ! V_5 )
goto V_33;
if ( ! F_30 ( V_24 , V_5 ) )
goto V_33;
V_35 = V_30 -> V_35 ;
}
V_46 = F_34 () ;
if ( V_46 == NULL )
goto V_33;
V_46 -> V_48 = F_35 ( V_30 -> V_48 ) ;
if ( V_46 -> V_48 == NULL )
goto V_33;
if ( ! F_36 ( V_46 -> V_49 , V_30 -> V_49 ) )
goto V_33;
if ( ! F_20 ( V_5 , V_46 ) )
goto V_33;
V_46 = NULL ;
}
V_15 = F_37 ( V_24 , NULL ) ;
if ( V_15 < 0 )
goto V_33;
V_11 -> V_47 = V_15 ;
V_20 = F_38 ( V_11 -> V_47 ) ;
if ( V_20 == NULL )
goto V_33;
V_11 -> V_13 = V_20 ;
F_37 ( V_24 , & V_20 ) ;
V_3 = 1 ;
V_33:
V_12 ( V_46 ) ;
F_26 ( V_24 ,
V_50 ) ;
return V_3 ;
}
static int F_36 ( T_7 * V_38 , const T_7 * V_14 )
{
unsigned char * V_51 , * V_52 ;
int V_15 , V_27 ;
if ( ! ( F_39 ( V_14 -> type ) & V_53 ) ) {
if ( ! F_40 ( V_38 , V_14 ) )
return 0 ;
return 1 ;
}
V_38 -> type = V_54 ;
V_38 -> V_39 = F_41 ( & V_38 -> V_34 , V_14 ) ;
if ( V_38 -> V_39 == - 1 )
return 0 ;
V_51 = V_38 -> V_34 ;
V_52 = V_51 ;
V_15 = V_38 -> V_39 ;
while ( ( V_15 > 0 ) && ! ( * V_52 & 0x80 ) && isspace ( * V_52 ) ) {
V_52 ++ ;
V_15 -- ;
}
V_51 = V_52 + V_15 ;
while ( ( V_15 > 0 ) && ! ( V_51 [ - 1 ] & 0x80 ) && isspace ( V_51 [ - 1 ] ) ) {
V_51 -- ;
V_15 -- ;
}
V_51 = V_38 -> V_34 ;
V_27 = 0 ;
while ( V_27 < V_15 ) {
if ( * V_52 & 0x80 ) {
* V_51 ++ = * V_52 ++ ;
V_27 ++ ;
}
else if ( isspace ( * V_52 ) ) {
* V_51 ++ = ' ' ;
do {
V_52 ++ ;
V_27 ++ ;
}
while ( ! ( * V_52 & 0x80 ) && isspace ( * V_52 ) );
} else {
* V_51 ++ = tolower ( * V_52 ) ;
V_52 ++ ;
V_27 ++ ;
}
}
V_38 -> V_39 = V_51 - V_38 -> V_34 ;
return 1 ;
}
int F_42 ( T_3 * * V_55 , T_3 * V_56 )
{
T_3 * V_14 ;
if ( ! V_55 || ! V_56 )
return ( 0 ) ;
if ( * V_55 != V_56 ) {
V_14 = F_43 ( V_56 ) ;
if ( V_14 != NULL ) {
F_25 ( * V_55 ) ;
* V_55 = V_14 ;
}
}
return ( * V_55 != NULL ) ;
}
int F_44 ( T_5 * V_57 , const T_3 * V_56 , int V_58 )
{
char * V_23 , * V_59 , * V_60 ;
int V_61 , V_27 ;
V_61 = 80 - 2 - V_58 ;
V_60 = F_45 ( V_56 , NULL , 0 ) ;
if ( ! V_60 )
return 0 ;
if ( ! * V_60 ) {
F_7 ( V_60 ) ;
return 1 ;
}
V_23 = V_60 + 1 ;
V_59 = V_23 ;
for (; ; ) {
#ifndef F_46
if ( ( ( * V_23 == '/' ) &&
( ( V_23 [ 1 ] >= 'A' ) && ( V_23 [ 1 ] <= 'Z' ) && ( ( V_23 [ 2 ] == '=' ) ||
( ( V_23 [ 2 ] >= 'A' )
&& ( V_23 [ 2 ] <= 'Z' )
&& ( V_23 [ 3 ] == '=' ) )
) ) ) || ( * V_23 == '\0' ) )
#else
if ( ( ( * V_23 == '/' ) &&
( isupper ( V_23 [ 1 ] ) && ( ( V_23 [ 2 ] == '=' ) ||
( isupper ( V_23 [ 2 ] ) && ( V_23 [ 3 ] == '=' ) )
) ) ) || ( * V_23 == '\0' ) )
#endif
{
V_27 = V_23 - V_59 ;
if ( F_47 ( V_57 , V_59 , V_27 ) != V_27 )
goto V_33;
V_59 = V_23 + 1 ;
if ( * V_23 != '\0' ) {
if ( F_47 ( V_57 , L_1 , 2 ) != 2 )
goto V_33;
}
V_61 -- ;
}
if ( * V_23 == '\0' )
break;
V_23 ++ ;
V_61 -- ;
}
F_7 ( V_60 ) ;
return 1 ;
V_33:
F_48 ( V_62 , V_63 ) ;
F_7 ( V_60 ) ;
return 0 ;
}
int F_49 ( T_3 * V_26 , const unsigned char * * V_64 ,
T_8 * V_65 )
{
if ( F_50 ( V_26 , NULL ) <= 0 )
return 0 ;
if ( V_64 != NULL )
* V_64 = ( unsigned char * ) V_26 -> V_6 -> V_34 ;
if ( V_65 != NULL )
* V_65 = V_26 -> V_6 -> V_39 ;
return 1 ;
}
