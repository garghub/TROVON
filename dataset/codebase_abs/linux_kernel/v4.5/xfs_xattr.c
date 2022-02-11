static int
F_1 ( const struct V_1 * V_2 , struct V_3 * V_3 ,
const char * V_4 , void * V_5 , T_1 V_6 )
{
int V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = F_2 ( F_3 ( V_3 ) ) ;
int error , V_11 = V_6 ;
if ( ! V_6 ) {
V_7 |= V_12 ;
V_5 = NULL ;
}
error = F_4 ( V_10 , ( unsigned char * ) V_4 , V_5 , & V_11 , V_7 ) ;
if ( error )
return error ;
return V_11 ;
}
void
F_5 (
struct V_13 * V_13 ,
const char * V_4 ,
int V_7 )
{
if ( V_7 & V_14 ) {
#ifdef F_6
if ( ! strcmp ( V_4 , V_15 ) )
F_7 ( V_13 , V_16 ) ;
else if ( ! strcmp ( V_4 , V_17 ) )
F_7 ( V_13 , V_18 ) ;
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
if ( V_8 & V_19 )
V_7 |= V_20 ;
if ( V_8 & V_21 )
V_7 |= V_22 ;
if ( ! V_5 )
return F_9 ( V_10 , ( unsigned char * ) V_4 , V_7 ) ;
error = F_10 ( V_10 , ( unsigned char * ) V_4 ,
( void * ) V_5 , V_6 , V_7 ) ;
if ( ! error )
F_5 ( F_3 ( V_3 ) , V_4 , V_7 ) ;
return error ;
}
static int
F_11 (
struct V_23 * V_24 ,
char * V_25 ,
int V_26 ,
unsigned char * V_4 ,
int V_27 )
{
char * V_28 ;
int V_29 ;
if ( ! V_24 -> V_30 )
goto V_31;
V_29 = V_24 -> V_32 + V_26 + V_27 + 1 ;
if ( V_29 > V_24 -> V_33 ) {
V_24 -> V_32 = - 1 ;
return 1 ;
}
V_28 = ( char * ) V_24 -> V_30 + V_24 -> V_32 ;
strncpy ( V_28 , V_25 , V_26 ) ;
V_28 += V_26 ;
strncpy ( V_28 , ( char * ) V_4 , V_27 ) ;
V_28 += V_27 ;
* V_28 = '\0' ;
V_31:
V_24 -> V_32 += V_26 + V_27 + 1 ;
return 0 ;
}
static int
F_12 (
struct V_23 * V_24 ,
int V_8 ,
unsigned char * V_4 ,
int V_27 ,
int V_34 ,
unsigned char * V_5 )
{
char * V_25 ;
int V_26 ;
ASSERT ( V_24 -> V_32 >= 0 ) ;
if ( V_8 & V_35 ) {
#ifdef F_6
if ( V_27 == V_36 &&
strncmp ( V_4 , V_15 ,
V_36 ) == 0 ) {
int V_37 = F_11 (
V_24 , V_38 ,
V_39 ,
V_40 ,
strlen ( V_40 ) ) ;
if ( V_37 )
return V_37 ;
} else if ( V_27 == V_41 &&
strncmp ( V_4 , V_17 ,
V_41 ) == 0 ) {
int V_37 = F_11 (
V_24 , V_38 ,
V_39 ,
V_42 ,
strlen ( V_42 ) ) ;
if ( V_37 )
return V_37 ;
}
#endif
if ( ! F_13 ( V_43 ) )
return 0 ;
V_25 = V_44 ;
V_26 = V_45 ;
} else if ( V_8 & V_46 ) {
V_25 = V_47 ;
V_26 = V_48 ;
} else {
V_25 = V_49 ;
V_26 = V_50 ;
}
return F_11 ( V_24 , V_25 , V_26 , V_4 ,
V_27 ) ;
}
T_2
F_14 ( struct V_3 * V_3 , char * V_51 , T_1 V_6 )
{
struct V_23 V_24 ;
struct V_52 V_53 = { 0 } ;
struct V_13 * V_13 = F_3 ( V_3 ) ;
memset ( & V_24 , 0 , sizeof( V_24 ) ) ;
V_24 . V_54 = F_2 ( V_13 ) ;
V_24 . V_53 = & V_53 ;
V_24 . V_55 = 1 ;
V_24 . V_30 = V_6 ? V_51 : NULL ;
V_24 . V_56 = V_6 ;
V_24 . V_33 = V_24 . V_56 ;
V_24 . V_57 = F_12 ;
F_15 ( & V_24 ) ;
if ( V_24 . V_32 < 0 )
return - V_58 ;
return V_24 . V_32 ;
}
