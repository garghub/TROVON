static int
F_1 ( struct V_1 * V_1 , const char * V_2 ,
void * V_3 , T_1 V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( F_3 ( V_1 ) ) ;
int error , V_8 = V_4 ;
if ( strcmp ( V_2 , L_1 ) == 0 )
return - V_9 ;
if ( ! V_4 ) {
V_5 |= V_10 ;
V_3 = NULL ;
}
error = F_4 ( V_7 , ( unsigned char * ) V_2 , V_3 , & V_8 , V_5 ) ;
if ( error )
return error ;
return V_8 ;
}
static int
F_5 ( struct V_1 * V_1 , const char * V_2 , const void * V_3 ,
T_1 V_4 , int V_11 , int V_5 )
{
struct V_6 * V_7 = F_2 ( F_3 ( V_1 ) ) ;
if ( strcmp ( V_2 , L_1 ) == 0 )
return - V_9 ;
if ( V_11 & V_12 )
V_5 |= V_13 ;
if ( V_11 & V_14 )
V_5 |= V_15 ;
if ( ! V_3 )
return F_6 ( V_7 , ( unsigned char * ) V_2 , V_5 ) ;
return F_7 ( V_7 , ( unsigned char * ) V_2 ,
( void * ) V_3 , V_4 , V_5 ) ;
}
static unsigned int F_8 ( int V_11 )
{
if ( V_11 & V_16 )
return sizeof( L_2 ) ;
else if ( V_11 & V_17 )
return sizeof( L_3 ) ;
else
return sizeof( L_4 ) ;
}
static const char * F_9 ( int V_11 )
{
if ( V_11 & V_16 )
return V_18 . V_19 ;
else if ( V_11 & V_17 )
return V_20 . V_19 ;
else
return V_21 . V_19 ;
}
static int
F_10 (
struct V_22 * V_23 ,
int V_11 ,
unsigned char * V_2 ,
int V_24 ,
int V_25 ,
unsigned char * V_3 )
{
unsigned int V_26 = F_8 ( V_11 ) ;
char * V_27 ;
int V_28 ;
ASSERT ( V_23 -> V_29 >= 0 ) ;
if ( ( V_11 & V_17 ) && ! F_11 ( V_30 ) )
return 0 ;
V_28 = V_23 -> V_29 + V_26 + V_24 + 1 ;
if ( V_28 > V_23 -> V_31 ) {
V_23 -> V_29 = - 1 ;
return 1 ;
}
V_27 = ( char * ) V_23 -> V_32 + V_23 -> V_29 ;
strncpy ( V_27 , F_9 ( V_11 ) , V_26 ) ;
V_27 += V_26 ;
strncpy ( V_27 , ( char * ) V_2 , V_24 ) ;
V_27 += V_24 ;
* V_27 = '\0' ;
V_23 -> V_29 += V_26 + V_24 + 1 ;
return 0 ;
}
static int
F_12 (
struct V_22 * V_23 ,
int V_11 ,
unsigned char * V_2 ,
int V_24 ,
int V_25 ,
unsigned char * V_3 )
{
V_23 -> V_29 += F_8 ( V_11 ) + V_24 + 1 ;
return 0 ;
}
static int
F_13 ( const char * V_2 , const T_1 V_33 , void * V_34 ,
T_1 V_4 , T_2 * V_35 )
{
char * V_36 = V_34 + * V_35 ;
* V_35 += V_33 ;
if ( ! V_4 )
return 0 ;
if ( * V_35 > V_4 )
return - V_37 ;
strcpy ( V_36 , V_2 ) ;
return 0 ;
}
T_2
F_14 ( struct V_1 * V_1 , char * V_34 , T_1 V_4 )
{
struct V_22 V_23 ;
struct V_38 V_39 = { 0 } ;
struct V_40 * V_40 = F_3 ( V_1 ) ;
int error ;
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
V_23 . V_41 = F_2 ( V_40 ) ;
V_23 . V_39 = & V_39 ;
V_23 . V_42 = 1 ;
V_23 . V_32 = V_34 ;
V_23 . V_43 = V_4 ;
V_23 . V_31 = V_23 . V_43 ;
if ( V_4 )
V_23 . V_44 = F_10 ;
else
V_23 . V_44 = F_12 ;
F_15 ( & V_23 ) ;
if ( V_23 . V_29 < 0 )
return - V_37 ;
if ( F_16 ( V_40 ) ) {
error = F_13 ( V_45 ,
strlen ( V_45 ) + 1 ,
V_34 , V_4 , & V_23 . V_29 ) ;
if ( error )
return error ;
}
if ( F_17 ( V_40 ) ) {
error = F_13 ( V_46 ,
strlen ( V_46 ) + 1 ,
V_34 , V_4 , & V_23 . V_29 ) ;
if ( error )
return error ;
}
return V_23 . V_29 ;
}
