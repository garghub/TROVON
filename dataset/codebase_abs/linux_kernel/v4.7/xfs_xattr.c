static int
F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_5 , const char * V_6 , void * V_7 , T_1 V_8 )
{
int V_9 = V_2 -> V_10 ;
struct V_11 * V_12 = F_2 ( V_5 ) ;
int error , V_13 = V_8 ;
if ( ! V_8 ) {
V_9 |= V_14 ;
V_7 = NULL ;
}
error = F_3 ( V_12 , ( unsigned char * ) V_6 , V_7 , & V_13 , V_9 ) ;
if ( error )
return error ;
return V_13 ;
}
void
F_4 (
struct V_5 * V_5 ,
const char * V_6 ,
int V_9 )
{
if ( V_9 & V_15 ) {
#ifdef F_5
if ( ! strcmp ( V_6 , V_16 ) )
F_6 ( V_5 , V_17 ) ;
else if ( ! strcmp ( V_6 , V_18 ) )
F_6 ( V_5 , V_19 ) ;
#endif
}
}
static int
F_7 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_5 , const char * V_6 , const void * V_7 ,
T_1 V_8 , int V_10 )
{
int V_9 = V_2 -> V_10 ;
struct V_11 * V_12 = F_2 ( V_5 ) ;
int error ;
if ( V_10 & V_20 )
V_9 |= V_21 ;
if ( V_10 & V_22 )
V_9 |= V_23 ;
if ( ! V_7 )
return F_8 ( V_12 , ( unsigned char * ) V_6 , V_9 ) ;
error = F_9 ( V_12 , ( unsigned char * ) V_6 ,
( void * ) V_7 , V_8 , V_9 ) ;
if ( ! error )
F_4 ( V_5 , V_6 , V_9 ) ;
return error ;
}
static int
F_10 (
struct V_24 * V_25 ,
char * V_26 ,
int V_27 ,
unsigned char * V_6 ,
int V_28 )
{
char * V_29 ;
int V_30 ;
if ( ! V_25 -> V_31 )
goto V_32;
V_30 = V_25 -> V_33 + V_27 + V_28 + 1 ;
if ( V_30 > V_25 -> V_34 ) {
V_25 -> V_33 = - 1 ;
return 0 ;
}
V_29 = ( char * ) V_25 -> V_31 + V_25 -> V_33 ;
strncpy ( V_29 , V_26 , V_27 ) ;
V_29 += V_27 ;
strncpy ( V_29 , ( char * ) V_6 , V_28 ) ;
V_29 += V_28 ;
* V_29 = '\0' ;
V_32:
V_25 -> V_33 += V_27 + V_28 + 1 ;
return 0 ;
}
static int
F_11 (
struct V_24 * V_25 ,
int V_10 ,
unsigned char * V_6 ,
int V_28 ,
int V_35 )
{
char * V_26 ;
int V_27 ;
ASSERT ( V_25 -> V_33 >= 0 ) ;
if ( V_10 & V_36 ) {
#ifdef F_5
if ( V_28 == V_37 &&
strncmp ( V_6 , V_16 ,
V_37 ) == 0 ) {
int V_38 = F_10 (
V_25 , V_39 ,
V_40 ,
V_41 ,
strlen ( V_41 ) ) ;
if ( V_38 )
return V_38 ;
} else if ( V_28 == V_42 &&
strncmp ( V_6 , V_18 ,
V_42 ) == 0 ) {
int V_38 = F_10 (
V_25 , V_39 ,
V_40 ,
V_43 ,
strlen ( V_43 ) ) ;
if ( V_38 )
return V_38 ;
}
#endif
if ( ! F_12 ( V_44 ) )
return 0 ;
V_26 = V_45 ;
V_27 = V_46 ;
} else if ( V_10 & V_47 ) {
V_26 = V_48 ;
V_27 = V_49 ;
} else {
V_26 = V_50 ;
V_27 = V_51 ;
}
return F_10 ( V_25 , V_26 , V_27 , V_6 ,
V_28 ) ;
}
T_2
F_13 (
struct V_3 * V_3 ,
char * V_52 ,
T_1 V_8 )
{
struct V_24 V_25 ;
struct V_53 V_54 = { 0 } ;
struct V_5 * V_5 = F_14 ( V_3 ) ;
int error ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
V_25 . V_55 = F_2 ( V_5 ) ;
V_25 . V_54 = & V_54 ;
V_25 . V_56 = 1 ;
V_25 . V_31 = V_8 ? V_52 : NULL ;
V_25 . V_57 = V_8 ;
V_25 . V_34 = V_25 . V_57 ;
V_25 . V_58 = F_11 ;
error = F_15 ( & V_25 ) ;
if ( error )
return error ;
if ( V_25 . V_33 < 0 )
return - V_59 ;
return V_25 . V_33 ;
}
