static int F_1 ( const void * V_1 ,
int V_2 , int V_3 )
{
return ( F_2 ( V_1 ) < F_3 ( sizeof( struct V_4 ) , 8 ) )
|| ( F_4 ( V_1 ) <
( F_2 ( V_1 ) + V_2 ) )
|| ( F_5 ( V_1 ) <
( F_4 ( V_1 ) + V_3 ) )
|| ( F_6 ( V_1 ) <
( F_5 ( V_1 ) + F_7 ( V_1 ) ) ) ;
}
static int F_8 ( void * V_1 )
{
F_9 ( V_1 ) ;
if ( F_10 ( V_1 ) < 17 )
return - V_5 ;
if ( F_1 ( V_1 , sizeof( struct V_6 ) ,
F_11 ( V_1 ) ) )
return - V_7 ;
if ( F_10 ( V_1 ) > 17 )
F_12 ( V_1 , 17 ) ;
return 0 ;
}
static inline int F_13 ( void * V_1 )
{
return F_5 ( V_1 ) + F_7 ( V_1 ) ;
}
static int F_14 ( void * V_1 , void * V_8 , int V_9 , int V_10 )
{
char * V_11 = V_8 ;
char * V_12 = ( char * ) V_1 + F_13 ( V_1 ) ;
if ( ( ( V_11 + V_9 ) < V_11 ) || ( ( V_11 + V_9 ) > V_12 ) )
return - V_13 ;
if ( ( V_12 - V_9 + V_10 ) > ( ( char * ) V_1 + F_6 ( V_1 ) ) )
return - V_14 ;
memmove ( V_11 + V_10 , V_11 + V_9 , V_12 - V_11 - V_9 ) ;
return 0 ;
}
static int F_15 ( void * V_1 , struct V_6 * V_11 ,
int V_15 , int V_16 )
{
int V_17 = ( V_16 - V_15 ) * sizeof( * V_11 ) ;
int V_18 ;
V_18 = F_14 ( V_1 , V_11 , V_15 * sizeof( * V_11 ) , V_16 * sizeof( * V_11 ) ) ;
if ( V_18 )
return V_18 ;
F_16 ( V_1 , F_4 ( V_1 ) + V_17 ) ;
F_17 ( V_1 , F_5 ( V_1 ) + V_17 ) ;
return 0 ;
}
static int F_18 ( void * V_1 , void * V_11 ,
int V_9 , int V_10 )
{
int V_17 = V_10 - V_9 ;
int V_18 ;
if ( ( V_18 = F_14 ( V_1 , V_11 , V_9 , V_10 ) ) )
return V_18 ;
F_19 ( V_1 , F_11 ( V_1 ) + V_17 ) ;
F_17 ( V_1 , F_5 ( V_1 ) + V_17 ) ;
return 0 ;
}
static int F_20 ( void * V_1 , int V_10 )
{
void * V_11 = ( char * ) V_1
+ F_5 ( V_1 ) + F_7 ( V_1 ) ;
int V_18 ;
if ( ( V_18 = F_14 ( V_1 , V_11 , 0 , V_10 ) ) )
return V_18 ;
F_21 ( V_1 , F_7 ( V_1 ) + V_10 ) ;
return 0 ;
}
static int F_22 ( void * V_1 , const char * V_19 )
{
char * V_20 = ( char * ) V_1 + F_5 ( V_1 ) ;
const char * V_11 ;
char * V_21 ;
int V_22 = strlen ( V_19 ) + 1 ;
int V_18 ;
V_11 = F_23 ( V_20 , F_7 ( V_1 ) , V_19 ) ;
if ( V_11 )
return ( V_11 - V_20 ) ;
V_21 = V_20 + F_7 ( V_1 ) ;
V_18 = F_20 ( V_1 , V_22 ) ;
if ( V_18 )
return V_18 ;
memcpy ( V_21 , V_19 , V_22 ) ;
return ( V_21 - V_20 ) ;
}
int F_24 ( void * V_1 , T_1 V_23 , T_1 V_24 )
{
struct V_6 * V_25 ;
int V_18 ;
F_25 ( V_1 ) ;
V_25 = F_26 ( V_1 , F_27 ( V_1 ) ) ;
V_18 = F_15 ( V_1 , V_25 , 0 , 1 ) ;
if ( V_18 )
return V_18 ;
V_25 -> V_23 = F_28 ( V_23 ) ;
V_25 -> V_24 = F_28 ( V_24 ) ;
return 0 ;
}
int F_29 ( void * V_1 , int V_26 )
{
struct V_6 * V_25 = F_26 ( V_1 , V_26 ) ;
int V_18 ;
F_25 ( V_1 ) ;
if ( V_26 >= F_27 ( V_1 ) )
return - V_27 ;
V_18 = F_15 ( V_1 , V_25 , 1 , 0 ) ;
if ( V_18 )
return V_18 ;
return 0 ;
}
static int F_30 ( void * V_1 , int V_28 , const char * V_29 ,
int V_22 , struct V_30 * * V_31 )
{
int V_9 ;
int V_18 ;
* V_31 = F_31 ( V_1 , V_28 , V_29 , & V_9 ) ;
if ( ! ( * V_31 ) )
return V_9 ;
if ( ( V_18 = F_18 ( V_1 , ( * V_31 ) -> V_32 , F_32 ( V_9 ) ,
F_32 ( V_22 ) ) ) )
return V_18 ;
( * V_31 ) -> V_22 = F_33 ( V_22 ) ;
return 0 ;
}
static int F_34 ( void * V_1 , int V_28 , const char * V_29 ,
int V_22 , struct V_30 * * V_31 )
{
int V_33 ;
int V_34 ;
int V_35 ;
int V_18 ;
if ( ( V_34 = F_35 ( V_1 , V_28 ) ) < 0 )
return V_34 ;
V_35 = F_22 ( V_1 , V_29 ) ;
if ( V_35 < 0 )
return V_35 ;
* V_31 = F_36 ( V_1 , V_34 ) ;
V_33 = sizeof( * * V_31 ) + F_32 ( V_22 ) ;
V_18 = F_18 ( V_1 , * V_31 , 0 , V_33 ) ;
if ( V_18 )
return V_18 ;
( * V_31 ) -> V_36 = F_33 ( V_37 ) ;
( * V_31 ) -> V_38 = F_33 ( V_35 ) ;
( * V_31 ) -> V_22 = F_33 ( V_22 ) ;
return 0 ;
}
int F_37 ( void * V_1 , int V_28 , const char * V_29 )
{
char * V_39 ;
int V_9 , V_10 ;
int V_18 ;
F_25 ( V_1 ) ;
V_39 = ( char * ) ( V_40 ) F_38 ( V_1 , V_28 , & V_9 ) ;
if ( ! V_39 )
return V_9 ;
V_10 = strlen ( V_29 ) ;
V_18 = F_18 ( V_1 , V_39 , F_32 ( V_9 + 1 ) ,
F_32 ( V_10 + 1 ) ) ;
if ( V_18 )
return V_18 ;
memcpy ( V_39 , V_29 , V_10 + 1 ) ;
return 0 ;
}
int F_39 ( void * V_1 , int V_28 , const char * V_29 ,
const void * V_41 , int V_22 )
{
struct V_30 * V_31 ;
int V_18 ;
F_25 ( V_1 ) ;
V_18 = F_30 ( V_1 , V_28 , V_29 , V_22 , & V_31 ) ;
if ( V_18 == - V_27 )
V_18 = F_34 ( V_1 , V_28 , V_29 , V_22 , & V_31 ) ;
if ( V_18 )
return V_18 ;
memcpy ( V_31 -> V_32 , V_41 , V_22 ) ;
return 0 ;
}
int F_40 ( void * V_1 , int V_28 , const char * V_29 )
{
struct V_30 * V_31 ;
int V_22 , V_33 ;
F_25 ( V_1 ) ;
V_31 = F_31 ( V_1 , V_28 , V_29 , & V_22 ) ;
if ( ! V_31 )
return V_22 ;
V_33 = sizeof( * V_31 ) + F_32 ( V_22 ) ;
return F_18 ( V_1 , V_31 , V_33 , 0 ) ;
}
int F_41 ( void * V_1 , int V_42 ,
const char * V_29 , int V_43 )
{
struct V_44 * V_45 ;
int V_46 , V_34 ;
int V_47 ;
int V_18 ;
T_2 V_36 ;
T_2 * V_48 ;
F_25 ( V_1 ) ;
V_46 = F_42 ( V_1 , V_42 , V_29 , V_43 ) ;
if ( V_46 >= 0 )
return - V_49 ;
else if ( V_46 != - V_27 )
return V_46 ;
F_43 ( V_1 , V_42 , & V_34 ) ;
do {
V_46 = V_34 ;
V_36 = F_43 ( V_1 , V_46 , & V_34 ) ;
} while ( ( V_36 == V_37 ) || ( V_36 == V_50 ) );
V_45 = F_36 ( V_1 , V_46 ) ;
V_47 = sizeof( * V_45 ) + F_32 ( V_43 + 1 ) + V_51 ;
V_18 = F_18 ( V_1 , V_45 , 0 , V_47 ) ;
if ( V_18 )
return V_18 ;
V_45 -> V_36 = F_33 ( V_52 ) ;
memset ( V_45 -> V_29 , 0 , F_32 ( V_43 + 1 ) ) ;
memcpy ( V_45 -> V_29 , V_29 , V_43 ) ;
V_48 = ( T_2 * ) ( ( char * ) V_45 + V_47 - V_51 ) ;
* V_48 = F_33 ( V_53 ) ;
return V_46 ;
}
int F_44 ( void * V_1 , int V_42 , const char * V_29 )
{
return F_41 ( V_1 , V_42 , V_29 , strlen ( V_29 ) ) ;
}
int F_45 ( void * V_1 , int V_28 )
{
int V_54 ;
F_25 ( V_1 ) ;
V_54 = F_46 ( V_1 , V_28 ) ;
if ( V_54 < 0 )
return V_54 ;
return F_18 ( V_1 , F_36 ( V_1 , V_28 ) ,
V_54 - V_28 , 0 ) ;
}
static void F_47 ( const char * V_55 , char * V_21 ,
int V_2 , int V_3 )
{
int V_56 , V_57 , V_58 ;
V_56 = F_3 ( sizeof( struct V_4 ) , 8 ) ;
V_57 = V_56 + V_2 ;
V_58 = V_57 + V_3 ;
memmove ( V_21 + V_56 , V_55 + F_2 ( V_55 ) , V_2 ) ;
F_48 ( V_21 , V_56 ) ;
memmove ( V_21 + V_57 , V_55 + F_4 ( V_55 ) , V_3 ) ;
F_16 ( V_21 , V_57 ) ;
F_19 ( V_21 , V_3 ) ;
memmove ( V_21 + V_58 , V_55 + F_5 ( V_55 ) ,
F_7 ( V_55 ) ) ;
F_17 ( V_21 , V_58 ) ;
F_21 ( V_21 , F_7 ( V_55 ) ) ;
}
int F_49 ( const void * V_1 , void * V_59 , int V_60 )
{
int V_18 ;
int V_2 , V_3 ;
int V_61 ;
const char * V_62 = V_1 ;
const char * V_63 = V_62 + F_6 ( V_1 ) ;
char * V_64 ;
F_9 ( V_1 ) ;
V_2 = ( F_27 ( V_1 ) + 1 )
* sizeof( struct V_6 ) ;
if ( F_10 ( V_1 ) >= 17 ) {
V_3 = F_11 ( V_1 ) ;
} else {
V_3 = 0 ;
while ( F_43 ( V_1 , V_3 , & V_3 ) != V_65 )
;
}
if ( ! F_1 ( V_1 , V_2 , V_3 ) ) {
V_18 = F_50 ( V_1 , V_59 , V_60 ) ;
if ( V_18 )
return V_18 ;
F_12 ( V_59 , 17 ) ;
F_19 ( V_59 , V_3 ) ;
F_51 ( V_59 , V_60 ) ;
return 0 ;
}
V_61 = F_3 ( sizeof( struct V_4 ) , 8 ) + V_2
+ V_3 + F_7 ( V_1 ) ;
if ( V_60 < V_61 )
return - V_14 ;
V_64 = V_59 ;
if ( ( ( V_64 + V_61 ) > V_62 ) && ( V_64 < V_63 ) ) {
V_64 = ( char * ) ( V_40 ) V_63 ;
if ( ( V_64 + V_61 ) > ( ( char * ) V_59 + V_60 ) )
return - V_14 ;
}
F_47 ( V_1 , V_64 , V_2 , V_3 ) ;
memmove ( V_59 , V_64 , V_61 ) ;
F_52 ( V_59 , V_66 ) ;
F_51 ( V_59 , V_60 ) ;
F_12 ( V_59 , 17 ) ;
F_53 ( V_59 , 16 ) ;
F_54 ( V_59 , F_55 ( V_1 ) ) ;
return 0 ;
}
int F_56 ( void * V_1 )
{
int V_2 ;
F_25 ( V_1 ) ;
V_2 = ( F_27 ( V_1 ) + 1 )
* sizeof( struct V_6 ) ;
F_47 ( V_1 , V_1 , V_2 , F_11 ( V_1 ) ) ;
F_51 ( V_1 , F_13 ( V_1 ) ) ;
return 0 ;
}
