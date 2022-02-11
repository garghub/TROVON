static int
F_1 ( const struct V_1 * V_2 , struct V_3 * V_3 ,
const char * V_4 , void * V_5 , T_1 V_6 )
{
int V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = F_2 ( F_3 ( V_3 ) ) ;
int error , V_11 = V_6 ;
if ( strcmp ( V_4 , L_1 ) == 0 )
return - V_12 ;
if ( ! V_6 ) {
V_7 |= V_13 ;
V_5 = NULL ;
}
error = F_4 ( V_10 , ( unsigned char * ) V_4 , V_5 , & V_11 , V_7 ) ;
if ( error )
return error ;
return V_11 ;
}
void
F_5 (
struct V_14 * V_14 ,
const char * V_4 ,
int V_7 )
{
if ( V_7 & V_15 ) {
#ifdef F_6
if ( ! strcmp ( V_4 , V_16 ) )
F_7 ( V_14 , V_17 ) ;
else if ( ! strcmp ( V_4 , V_18 ) )
F_7 ( V_14 , V_19 ) ;
#endif
}
}
static int
F_8 ( const struct V_1 * V_2 , struct V_3 * V_3 ,
const char * V_4 , const void * V_5 , T_1 V_6 , int V_8 )
{
int V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = F_2 ( F_3 ( V_3 ) ) ;
int error ;
if ( strcmp ( V_4 , L_1 ) == 0 )
return - V_12 ;
if ( V_8 & V_20 )
V_7 |= V_21 ;
if ( V_8 & V_22 )
V_7 |= V_23 ;
if ( ! V_5 )
return F_9 ( V_10 , ( unsigned char * ) V_4 , V_7 ) ;
error = F_10 ( V_10 , ( unsigned char * ) V_4 ,
( void * ) V_5 , V_6 , V_7 ) ;
if ( ! error )
F_5 ( F_3 ( V_3 ) , V_4 , V_7 ) ;
return error ;
}
static unsigned int F_11 ( int V_8 )
{
if ( V_8 & V_24 )
return sizeof( L_2 ) ;
else if ( V_8 & V_25 )
return sizeof( L_3 ) ;
else
return sizeof( L_4 ) ;
}
static const char * F_12 ( int V_8 )
{
if ( V_8 & V_24 )
return V_26 . V_27 ;
else if ( V_8 & V_25 )
return V_28 . V_27 ;
else
return V_29 . V_27 ;
}
static int
F_13 (
struct V_30 * V_31 ,
int V_8 ,
unsigned char * V_4 ,
int V_32 ,
int V_33 ,
unsigned char * V_5 )
{
unsigned int V_34 = F_11 ( V_8 ) ;
char * V_35 ;
int V_36 ;
ASSERT ( V_31 -> V_37 >= 0 ) ;
if ( ( V_8 & V_25 ) && ! F_14 ( V_38 ) )
return 0 ;
V_36 = V_31 -> V_37 + V_34 + V_32 + 1 ;
if ( V_36 > V_31 -> V_39 ) {
V_31 -> V_37 = - 1 ;
return 1 ;
}
V_35 = ( char * ) V_31 -> V_40 + V_31 -> V_37 ;
strncpy ( V_35 , F_12 ( V_8 ) , V_34 ) ;
V_35 += V_34 ;
strncpy ( V_35 , ( char * ) V_4 , V_32 ) ;
V_35 += V_32 ;
* V_35 = '\0' ;
V_31 -> V_37 += V_34 + V_32 + 1 ;
return 0 ;
}
static int
F_15 (
struct V_30 * V_31 ,
int V_8 ,
unsigned char * V_4 ,
int V_32 ,
int V_33 ,
unsigned char * V_5 )
{
V_31 -> V_37 += F_11 ( V_8 ) + V_32 + 1 ;
return 0 ;
}
static int
F_16 ( const char * V_4 , const T_1 V_41 , void * V_42 ,
T_1 V_6 , T_2 * V_43 )
{
char * V_44 = V_42 + * V_43 ;
* V_43 += V_41 ;
if ( ! V_6 )
return 0 ;
if ( * V_43 > V_6 )
return - V_45 ;
strcpy ( V_44 , V_4 ) ;
return 0 ;
}
T_2
F_17 ( struct V_3 * V_3 , char * V_42 , T_1 V_6 )
{
struct V_30 V_31 ;
struct V_46 V_47 = { 0 } ;
struct V_14 * V_14 = F_3 ( V_3 ) ;
int error ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_48 = F_2 ( V_14 ) ;
V_31 . V_47 = & V_47 ;
V_31 . V_49 = 1 ;
V_31 . V_40 = V_42 ;
V_31 . V_50 = V_6 ;
V_31 . V_39 = V_31 . V_50 ;
if ( V_6 )
V_31 . V_51 = F_13 ;
else
V_31 . V_51 = F_15 ;
F_18 ( & V_31 ) ;
if ( V_31 . V_37 < 0 )
return - V_45 ;
if ( F_19 ( V_14 ) ) {
error = F_16 ( V_52 ,
strlen ( V_52 ) + 1 ,
V_42 , V_6 , & V_31 . V_37 ) ;
if ( error )
return error ;
}
if ( F_20 ( V_14 ) ) {
error = F_16 ( V_53 ,
strlen ( V_53 ) + 1 ,
V_42 , V_6 , & V_31 . V_37 ) ;
if ( error )
return error ;
}
return V_31 . V_37 ;
}
