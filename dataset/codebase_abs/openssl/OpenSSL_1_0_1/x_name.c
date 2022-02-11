static int F_1 ( T_1 * * V_1 , const T_2 * V_2 )
{
T_3 * V_3 = NULL ;
V_3 = F_2 ( sizeof( T_3 ) ) ;
if( ! V_3 ) goto V_4;
if ( ( V_3 -> V_5 = F_3 () ) == NULL )
goto V_4;
if( ( V_3 -> V_6 = F_4 () ) == NULL ) goto V_4;
V_3 -> V_7 = NULL ;
V_3 -> V_8 = 0 ;
V_3 -> V_9 = 1 ;
* V_1 = ( T_1 * ) V_3 ;
return 1 ;
V_4:
F_5 ( V_10 , V_11 ) ;
if ( V_3 )
{
if ( V_3 -> V_5 )
F_6 ( V_3 -> V_5 ) ;
F_7 ( V_3 ) ;
}
return 0 ;
}
static void F_8 ( T_1 * * V_12 , const T_2 * V_2 )
{
T_3 * V_13 ;
if( ! V_12 || ! * V_12 )
return;
V_13 = ( T_3 * ) * V_12 ;
F_9 ( V_13 -> V_6 ) ;
F_10 ( V_13 -> V_5 , V_14 ) ;
if ( V_13 -> V_7 )
F_7 ( V_13 -> V_7 ) ;
F_7 ( V_13 ) ;
* V_12 = NULL ;
}
static int F_11 ( T_1 * * V_1 ,
const unsigned char * * V_15 , long V_16 , const T_2 * V_2 ,
int V_17 , int V_18 , char V_19 , T_4 * V_20 )
{
const unsigned char * V_21 = * V_15 , * V_22 ;
union { F_12 ( V_23 ) * V_24 ;
T_1 * V_13 ; } V_25 = { NULL } ;
union { T_3 * V_26 ; T_1 * V_13 ; } V_27 = { NULL } ;
int V_28 , V_29 , V_3 ;
F_12 ( V_30 ) * V_5 ;
V_30 * V_31 ;
V_22 = V_21 ;
V_3 = F_13 ( & V_25 . V_13 ,
& V_21 , V_16 , F_14 ( V_32 ) ,
V_17 , V_18 , V_19 , V_20 ) ;
if( V_3 <= 0 ) return V_3 ;
if( * V_1 ) F_8 ( V_1 , NULL ) ;
if( ! F_1 ( & V_27 . V_13 , NULL ) ) goto V_33;
if( ! F_15 ( V_27 . V_26 -> V_6 , V_21 - V_22 ) ) goto V_33;
memcpy ( V_27 . V_26 -> V_6 -> V_34 , V_22 , V_21 - V_22 ) ;
for( V_28 = 0 ; V_28 < F_16 ( V_25 . V_24 ) ; V_28 ++ ) {
V_5 = F_17 ( V_25 . V_24 , V_28 ) ;
for( V_29 = 0 ; V_29 < F_18 ( V_5 ) ; V_29 ++ ) {
V_31 = F_19 ( V_5 , V_29 ) ;
V_31 -> V_35 = V_28 ;
if( ! F_20 ( V_27 . V_26 -> V_5 , V_31 ) )
goto V_33;
}
F_6 ( V_5 ) ;
}
F_21 ( V_25 . V_24 ) ;
V_3 = F_22 ( V_27 . V_26 ) ;
if ( ! V_3 )
goto V_33;
V_27 . V_26 -> V_9 = 0 ;
* V_1 = V_27 . V_13 ;
* V_15 = V_21 ;
return V_3 ;
V_33:
if ( V_27 . V_26 != NULL )
F_23 ( V_27 . V_26 ) ;
F_5 ( V_36 , V_37 ) ;
return 0 ;
}
static int F_24 ( T_1 * * V_1 , unsigned char * * V_38 , const T_2 * V_2 , int V_17 , int V_18 )
{
int V_3 ;
T_3 * V_13 = ( T_3 * ) * V_1 ;
if( V_13 -> V_9 ) {
V_3 = F_25 ( V_13 ) ;
if( V_3 < 0 )
return V_3 ;
V_3 = F_22 ( V_13 ) ;
if( V_3 < 0 )
return V_3 ;
}
V_3 = V_13 -> V_6 -> V_39 ;
if( V_38 != NULL ) {
memcpy ( * V_38 , V_13 -> V_6 -> V_34 , V_3 ) ;
* V_38 += V_3 ;
}
return V_3 ;
}
static int F_25 ( T_3 * V_13 )
{
union { F_12 ( V_23 ) * V_24 ;
T_1 * V_13 ; } V_25 = { NULL } ;
int V_16 ;
unsigned char * V_21 ;
F_12 ( V_30 ) * V_5 = NULL ;
V_30 * V_31 ;
int V_28 , V_35 = - 1 ;
V_25 . V_24 = F_26 () ;
if( ! V_25 . V_24 ) goto V_4;
for( V_28 = 0 ; V_28 < F_18 ( V_13 -> V_5 ) ; V_28 ++ ) {
V_31 = F_19 ( V_13 -> V_5 , V_28 ) ;
if( V_31 -> V_35 != V_35 ) {
V_5 = F_3 () ;
if( ! V_5 ) goto V_4;
if( ! F_27 ( V_25 . V_24 ,
V_5 ) )
goto V_4;
V_35 = V_31 -> V_35 ;
}
if( ! F_20 ( V_5 , V_31 ) ) goto V_4;
}
V_16 = F_28 ( & V_25 . V_13 , NULL ,
F_14 ( V_32 ) , - 1 , - 1 ) ;
if ( ! F_15 ( V_13 -> V_6 , V_16 ) ) goto V_4;
V_21 = ( unsigned char * ) V_13 -> V_6 -> V_34 ;
F_28 ( & V_25 . V_13 ,
& V_21 , F_14 ( V_32 ) , - 1 , - 1 ) ;
F_29 ( V_25 . V_24 ,
V_40 ) ;
V_13 -> V_9 = 0 ;
return V_16 ;
V_4:
F_29 ( V_25 . V_24 ,
V_40 ) ;
F_5 ( V_41 , V_11 ) ;
return - 1 ;
}
static int F_30 ( T_5 * V_38 , T_1 * * V_12 ,
int V_42 ,
const char * V_43 ,
const T_6 * V_44 )
{
if ( F_31 ( V_38 , ( T_3 * ) * V_12 ,
V_42 , V_44 -> V_45 ) <= 0 )
return 0 ;
return 2 ;
}
static int F_22 ( T_3 * V_13 )
{
unsigned char * V_21 ;
F_12 ( V_23 ) * V_25 = NULL ;
F_12 ( V_30 ) * V_5 = NULL ;
V_30 * V_31 , * V_46 = NULL ;
int V_28 , V_35 = - 1 , V_3 = 0 ;
if ( V_13 -> V_7 )
{
F_7 ( V_13 -> V_7 ) ;
V_13 -> V_7 = NULL ;
}
if ( F_18 ( V_13 -> V_5 ) == 0 )
{
V_13 -> V_8 = 0 ;
return 1 ;
}
V_25 = F_26 () ;
if( ! V_25 )
goto V_33;
for( V_28 = 0 ; V_28 < F_18 ( V_13 -> V_5 ) ; V_28 ++ )
{
V_31 = F_19 ( V_13 -> V_5 , V_28 ) ;
if( V_31 -> V_35 != V_35 )
{
V_5 = F_3 () ;
if( ! V_5 )
goto V_33;
if( ! F_27 ( V_25 , V_5 ) )
goto V_33;
V_35 = V_31 -> V_35 ;
}
V_46 = F_32 () ;
V_46 -> V_47 = F_33 ( V_31 -> V_47 ) ;
if ( ! F_34 ( V_46 -> V_48 , V_31 -> V_48 ) )
goto V_33;
if( ! F_20 ( V_5 , V_46 ) )
goto V_33;
V_46 = NULL ;
}
V_13 -> V_8 = F_35 ( V_25 , NULL ) ;
V_21 = F_2 ( V_13 -> V_8 ) ;
if ( ! V_21 )
goto V_33;
V_13 -> V_7 = V_21 ;
F_35 ( V_25 , & V_21 ) ;
V_3 = 1 ;
V_33:
if ( V_46 )
V_14 ( V_46 ) ;
if ( V_25 )
F_29 ( V_25 ,
V_49 ) ;
return V_3 ;
}
static int F_34 ( T_7 * V_38 , T_7 * V_15 )
{
unsigned char * V_50 , * V_51 ;
int V_16 , V_28 ;
if ( ! ( F_36 ( V_15 -> type ) & V_52 ) )
{
if ( ! F_37 ( V_38 , V_15 ) )
return 0 ;
return 1 ;
}
V_38 -> type = V_53 ;
V_38 -> V_39 = F_38 ( & V_38 -> V_34 , V_15 ) ;
if ( V_38 -> V_39 == - 1 )
return 0 ;
V_50 = V_38 -> V_34 ;
V_51 = V_50 ;
V_16 = V_38 -> V_39 ;
while( ( V_16 > 0 ) && ! ( * V_51 & 0x80 ) && isspace ( * V_51 ) )
{
V_51 ++ ;
V_16 -- ;
}
V_50 = V_51 + V_16 - 1 ;
while ( ( V_16 > 0 ) && ! ( * V_50 & 0x80 ) && isspace ( * V_50 ) )
{
V_50 -- ;
V_16 -- ;
}
V_50 = V_38 -> V_34 ;
V_28 = 0 ;
while( V_28 < V_16 )
{
if ( * V_51 & 0x80 )
{
* V_50 ++ = * V_51 ++ ;
V_28 ++ ;
}
else if ( isspace ( * V_51 ) )
{
* V_50 ++ = ' ' ;
do
{
V_51 ++ ;
V_28 ++ ;
}
while( ! ( * V_51 & 0x80 ) && isspace ( * V_51 ) );
}
else
{
* V_50 ++ = tolower ( * V_51 ) ;
V_51 ++ ;
V_28 ++ ;
}
}
V_38 -> V_39 = V_50 - V_38 -> V_34 ;
return 1 ;
}
int F_39 ( T_3 * * V_54 , T_3 * V_55 )
{
T_3 * V_15 ;
if ( ! V_54 || ! V_55 ) return ( 0 ) ;
if ( * V_54 != V_55 )
{
V_15 = F_40 ( V_55 ) ;
if ( V_15 != NULL )
{
F_23 ( * V_54 ) ;
* V_54 = V_15 ;
}
}
return ( * V_54 != NULL ) ;
}
