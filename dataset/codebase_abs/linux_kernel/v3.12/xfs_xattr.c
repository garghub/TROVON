static int
F_1 ( struct V_1 * V_1 , const char * V_2 ,
void * V_3 , T_1 V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_1 -> V_8 ) ;
int error , V_9 = V_4 ;
if ( strcmp ( V_2 , L_1 ) == 0 )
return - V_10 ;
if ( ! V_4 ) {
V_5 |= V_11 ;
V_3 = NULL ;
}
error = - F_3 ( V_7 , ( unsigned char * ) V_2 , V_3 , & V_9 , V_5 ) ;
if ( error )
return error ;
return V_9 ;
}
static int
F_4 ( struct V_1 * V_1 , const char * V_2 , const void * V_3 ,
T_1 V_4 , int V_12 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_1 -> V_8 ) ;
if ( strcmp ( V_2 , L_1 ) == 0 )
return - V_10 ;
if ( V_12 & V_13 )
V_5 |= V_14 ;
if ( V_12 & V_15 )
V_5 |= V_16 ;
if ( ! V_3 )
return - F_5 ( V_7 , ( unsigned char * ) V_2 , V_5 ) ;
return - F_6 ( V_7 , ( unsigned char * ) V_2 ,
( void * ) V_3 , V_4 , V_5 ) ;
}
static unsigned int F_7 ( int V_12 )
{
if ( V_12 & V_17 )
return sizeof( L_2 ) ;
else if ( V_12 & V_18 )
return sizeof( L_3 ) ;
else
return sizeof( L_4 ) ;
}
static const char * F_8 ( int V_12 )
{
if ( V_12 & V_17 )
return V_19 . V_20 ;
else if ( V_12 & V_18 )
return V_21 . V_20 ;
else
return V_22 . V_20 ;
}
static int
F_9 (
struct V_23 * V_24 ,
int V_12 ,
unsigned char * V_2 ,
int V_25 ,
int V_26 ,
unsigned char * V_3 )
{
unsigned int V_27 = F_7 ( V_12 ) ;
char * V_28 ;
int V_29 ;
ASSERT ( V_24 -> V_30 >= 0 ) ;
if ( ( V_12 & V_18 ) && ! F_10 ( V_31 ) )
return 0 ;
V_29 = V_24 -> V_30 + V_27 + V_25 + 1 ;
if ( V_29 > V_24 -> V_32 ) {
V_24 -> V_30 = - 1 ;
return 1 ;
}
V_28 = ( char * ) V_24 -> V_33 + V_24 -> V_30 ;
strncpy ( V_28 , F_8 ( V_12 ) , V_27 ) ;
V_28 += V_27 ;
strncpy ( V_28 , ( char * ) V_2 , V_25 ) ;
V_28 += V_25 ;
* V_28 = '\0' ;
V_24 -> V_30 += V_27 + V_25 + 1 ;
return 0 ;
}
static int
F_11 (
struct V_23 * V_24 ,
int V_12 ,
unsigned char * V_2 ,
int V_25 ,
int V_26 ,
unsigned char * V_3 )
{
V_24 -> V_30 += F_7 ( V_12 ) + V_25 + 1 ;
return 0 ;
}
static int
F_12 ( const char * V_2 , const T_1 V_34 , void * V_35 ,
T_1 V_4 , T_2 * V_36 )
{
char * V_37 = V_35 + * V_36 ;
* V_36 += V_34 ;
if ( ! V_4 )
return 0 ;
if ( * V_36 > V_4 )
return - V_38 ;
strcpy ( V_37 , V_2 ) ;
return 0 ;
}
T_2
F_13 ( struct V_1 * V_1 , char * V_35 , T_1 V_4 )
{
struct V_23 V_24 ;
struct V_39 V_40 = { 0 } ;
struct V_41 * V_41 = V_1 -> V_8 ;
int error ;
memset ( & V_24 , 0 , sizeof( V_24 ) ) ;
V_24 . V_42 = F_2 ( V_41 ) ;
V_24 . V_40 = & V_40 ;
V_24 . V_43 = 1 ;
V_24 . V_33 = V_35 ;
V_24 . V_44 = V_4 ;
V_24 . V_32 = V_24 . V_44 ;
if ( V_4 )
V_24 . V_45 = F_9 ;
else
V_24 . V_45 = F_11 ;
F_14 ( & V_24 ) ;
if ( V_24 . V_30 < 0 )
return - V_38 ;
if ( F_15 ( V_41 ) ) {
error = F_12 ( V_46 ,
strlen ( V_46 ) + 1 ,
V_35 , V_4 , & V_24 . V_30 ) ;
if ( error )
return error ;
}
if ( F_16 ( V_41 ) ) {
error = F_12 ( V_47 ,
strlen ( V_47 ) + 1 ,
V_35 , V_4 , & V_24 . V_30 ) ;
if ( error )
return error ;
}
return V_24 . V_30 ;
}
