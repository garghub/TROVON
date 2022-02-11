T_1 *
F_1 ( T_1 * V_1 , const struct V_2 * V_3 )
{
unsigned int V_4 = F_2 ( V_3 -> V_5 ) ;
V_1 [ V_4 ] = 0 ;
* V_1 ++ = F_3 ( V_3 -> V_5 ) ;
memcpy ( V_1 , V_3 -> V_6 , V_3 -> V_5 ) ;
return V_1 + F_2 ( V_3 -> V_5 ) ;
}
T_1 *
F_4 ( T_1 * V_1 , struct V_2 * V_3 )
{
unsigned int V_5 ;
if ( ( V_5 = F_5 ( * V_1 ++ ) ) > V_7 )
return NULL ;
V_3 -> V_5 = V_5 ;
V_3 -> V_6 = ( V_8 * ) V_1 ;
return V_1 + F_2 ( V_5 ) ;
}
T_1 * F_6 ( T_1 * V_1 , const void * V_9 , unsigned int V_10 )
{
if ( F_7 ( V_10 != 0 ) ) {
unsigned int V_4 = F_2 ( V_10 ) ;
unsigned int V_11 = ( V_4 << 2 ) - V_10 ;
if ( V_9 != NULL )
memcpy ( V_1 , V_9 , V_10 ) ;
if ( V_11 != 0 )
memset ( ( char * ) V_1 + V_10 , 0 , V_11 ) ;
V_1 += V_4 ;
}
return V_1 ;
}
T_1 * F_8 ( T_1 * V_1 , const void * V_9 , unsigned int V_10 )
{
* V_1 ++ = F_3 ( V_10 ) ;
return F_6 ( V_1 , V_9 , V_10 ) ;
}
T_1 *
F_9 ( T_1 * V_1 , const char * string )
{
return F_10 ( V_1 , string , strlen ( string ) ) ;
}
T_1 *
F_11 ( T_1 * V_1 , char * * V_12 ,
unsigned int * V_13 , unsigned int V_14 )
{
T_2 V_5 ;
V_5 = F_5 ( * V_1 ++ ) ;
if ( V_5 > V_14 )
return NULL ;
* V_13 = V_5 ;
* V_12 = ( char * ) V_1 ;
return V_1 + F_2 ( V_5 ) ;
}
void
F_12 ( struct V_15 * V_16 , const T_2 V_5 )
{
char * V_17 ;
V_17 = F_13 ( V_16 -> V_18 [ 0 ] ) ;
V_17 [ V_16 -> V_19 + V_5 ] = '\0' ;
F_14 ( V_17 ) ;
}
void
F_15 ( struct V_15 * V_20 , unsigned int V_21 ,
struct V_22 * * V_18 , unsigned int V_23 , unsigned int V_5 )
{
struct V_24 * V_25 = V_20 -> V_25 ;
struct V_24 * V_26 = V_20 -> V_26 ;
char * V_16 = ( char * ) V_25 -> V_27 ;
unsigned int V_28 = V_25 -> V_29 ;
V_25 -> V_29 = V_21 ;
V_20 -> V_18 = V_18 ;
V_20 -> V_19 = V_23 ;
V_20 -> V_30 = V_5 ;
V_26 -> V_27 = V_16 + V_21 ;
V_26 -> V_29 = V_28 - V_21 ;
V_20 -> V_28 += V_5 ;
}
static void
F_16 ( struct V_22 * * V_18 , T_3 V_31 ,
T_3 V_32 , T_3 V_5 )
{
struct V_22 * * V_33 , * * V_34 ;
char * V_35 , * V_36 ;
T_3 V_37 ;
F_17 ( V_31 <= V_32 ) ;
V_31 += V_5 ;
V_32 += V_5 ;
V_34 = V_18 + ( V_31 >> V_38 ) ;
V_33 = V_18 + ( V_32 >> V_38 ) ;
V_31 &= ~ V_39 ;
V_32 &= ~ V_39 ;
do {
if ( V_31 == 0 ) {
V_31 = V_40 ;
V_34 -- ;
}
if ( V_32 == 0 ) {
V_32 = V_40 ;
V_33 -- ;
}
V_37 = V_5 ;
if ( V_37 > V_31 )
V_37 = V_31 ;
if ( V_37 > V_32 )
V_37 = V_32 ;
V_31 -= V_37 ;
V_32 -= V_37 ;
V_36 = F_13 ( * V_34 ) ;
if ( * V_34 != * V_33 ) {
V_35 = F_13 ( * V_33 ) ;
memcpy ( V_36 + V_31 , V_35 + V_32 , V_37 ) ;
F_14 ( V_35 ) ;
} else
memmove ( V_36 + V_31 , V_36 + V_32 , V_37 ) ;
F_18 ( * V_34 ) ;
F_14 ( V_36 ) ;
} while ( ( V_5 -= V_37 ) != 0 );
}
static void
F_19 ( struct V_22 * * V_18 , T_3 V_41 , const char * V_1 , T_3 V_5 )
{
struct V_22 * * V_34 ;
char * V_36 ;
T_3 V_37 ;
V_34 = V_18 + ( V_41 >> V_38 ) ;
V_41 &= ~ V_39 ;
for (; ; ) {
V_37 = V_40 - V_41 ;
if ( V_37 > V_5 )
V_37 = V_5 ;
V_36 = F_13 ( * V_34 ) ;
memcpy ( V_36 + V_41 , V_1 , V_37 ) ;
F_14 ( V_36 ) ;
V_5 -= V_37 ;
if ( V_5 == 0 )
break;
V_41 += V_37 ;
if ( V_41 == V_40 ) {
F_18 ( * V_34 ) ;
V_41 = 0 ;
V_34 ++ ;
}
V_1 += V_37 ;
}
F_18 ( * V_34 ) ;
}
void
F_20 ( char * V_1 , struct V_22 * * V_18 , T_3 V_41 , T_3 V_5 )
{
struct V_22 * * V_33 ;
char * V_35 ;
T_3 V_37 ;
V_33 = V_18 + ( V_41 >> V_38 ) ;
V_41 &= ~ V_39 ;
do {
V_37 = V_40 - V_41 ;
if ( V_37 > V_5 )
V_37 = V_5 ;
V_35 = F_13 ( * V_33 ) ;
memcpy ( V_1 , V_35 + V_41 , V_37 ) ;
F_14 ( V_35 ) ;
V_41 += V_37 ;
if ( V_41 == V_40 ) {
V_41 = 0 ;
V_33 ++ ;
}
V_1 += V_37 ;
} while ( ( V_5 -= V_37 ) != 0 );
}
static void
F_21 ( struct V_15 * V_16 , T_3 V_5 )
{
struct V_24 * V_25 , * V_26 ;
T_3 V_37 , V_42 ;
unsigned int V_43 = V_16 -> V_30 ;
V_26 = V_16 -> V_26 ;
V_25 = V_16 -> V_25 ;
F_22 ( V_5 > V_25 -> V_29 ) ;
if ( V_5 > V_25 -> V_29 )
V_5 = V_25 -> V_29 ;
if ( V_26 -> V_29 != 0 ) {
if ( V_26 -> V_29 > V_5 ) {
V_37 = V_26 -> V_29 - V_5 ;
memmove ( ( char * ) V_26 -> V_27 + V_5 ,
V_26 -> V_27 , V_37 ) ;
}
V_37 = V_5 ;
if ( V_37 > V_43 )
V_37 = V_43 ;
V_42 = V_5 - V_37 ;
if ( V_42 >= V_26 -> V_29 )
V_37 = 0 ;
else if ( V_37 > V_26 -> V_29 - V_42 )
V_37 = V_26 -> V_29 - V_42 ;
if ( V_37 != 0 )
F_20 ( ( char * ) V_26 -> V_27 + V_42 ,
V_16 -> V_18 ,
V_16 -> V_19 + V_43 + V_42 - V_5 ,
V_37 ) ;
if ( V_5 > V_43 ) {
V_42 = V_37 = V_5 - V_43 ;
if ( V_37 > V_26 -> V_29 )
V_37 = V_26 -> V_29 ;
memcpy ( V_26 -> V_27 ,
( char * ) V_25 -> V_27 +
V_25 -> V_29 - V_42 ,
V_37 ) ;
}
}
if ( V_43 != 0 ) {
if ( V_43 > V_5 )
F_16 ( V_16 -> V_18 ,
V_16 -> V_19 + V_5 ,
V_16 -> V_19 ,
V_43 - V_5 ) ;
V_37 = V_5 ;
if ( V_5 > V_43 )
V_37 = V_43 ;
F_19 ( V_16 -> V_18 , V_16 -> V_19 ,
( char * ) V_25 -> V_27 + V_25 -> V_29 - V_5 ,
V_37 ) ;
}
V_25 -> V_29 -= V_5 ;
V_16 -> V_28 -= V_5 ;
if ( V_16 -> V_5 > V_16 -> V_28 )
V_16 -> V_5 = V_16 -> V_28 ;
}
static void
F_23 ( struct V_15 * V_16 , T_3 V_5 )
{
struct V_24 * V_26 ;
T_3 V_37 ;
unsigned int V_43 = V_16 -> V_30 ;
unsigned int V_44 ;
V_26 = V_16 -> V_26 ;
F_17 ( V_5 > V_43 ) ;
V_44 = V_16 -> V_28 - V_16 -> V_25 -> V_29 - V_16 -> V_30 ;
if ( V_44 != 0 ) {
unsigned int V_45 = V_44 - V_26 -> V_29 ;
if ( V_5 < V_45 )
V_45 = V_5 ;
V_26 -> V_29 += V_45 ;
V_37 = V_5 ;
if ( V_26 -> V_29 > V_5 ) {
char * V_1 = ( char * ) V_26 -> V_27 + V_5 ;
memmove ( V_1 , V_26 -> V_27 , V_26 -> V_29 - V_5 ) ;
} else
V_37 = V_26 -> V_29 ;
F_20 ( ( char * ) V_26 -> V_27 ,
V_16 -> V_18 , V_16 -> V_19 + V_43 - V_5 ,
V_37 ) ;
}
V_16 -> V_30 -= V_5 ;
V_16 -> V_28 -= V_5 ;
if ( V_16 -> V_5 > V_16 -> V_28 )
V_16 -> V_5 = V_16 -> V_28 ;
}
void
F_24 ( struct V_15 * V_16 , T_3 V_5 )
{
F_21 ( V_16 , V_5 ) ;
}
unsigned int F_25 ( const struct V_46 * V_20 )
{
return ( unsigned int ) ( F_2 ( V_20 -> V_16 -> V_5 ) - V_20 -> V_47 ) << 2 ;
}
void F_26 ( struct V_46 * V_20 , struct V_15 * V_16 , T_1 * V_1 )
{
struct V_24 * V_48 = V_16 -> V_25 ;
int V_49 = V_16 -> V_28 - V_16 -> V_30 - V_16 -> V_26 [ 0 ] . V_29 ;
F_27 ( V_20 , NULL , 0 ) ;
F_17 ( V_49 < 0 ) ;
V_20 -> V_16 = V_16 ;
V_20 -> V_48 = V_48 ;
V_20 -> V_1 = ( T_1 * ) ( ( char * ) V_48 -> V_27 + V_48 -> V_29 ) ;
V_20 -> V_50 = ( T_1 * ) ( ( char * ) V_48 -> V_27 + V_49 ) ;
F_17 ( V_48 -> V_29 > V_49 ) ;
if ( V_1 != V_20 -> V_1 && V_1 != NULL ) {
T_3 V_5 ;
F_17 ( V_1 < V_20 -> V_1 || V_1 > V_20 -> V_50 ) ;
V_5 = ( char * ) V_1 - ( char * ) V_20 -> V_1 ;
V_20 -> V_1 = V_1 ;
V_16 -> V_5 += V_5 ;
V_48 -> V_29 += V_5 ;
}
}
void F_28 ( struct V_46 * V_20 )
{
int V_51 = V_20 -> V_52 . V_29 ;
void * V_22 ;
if ( V_51 == 0 )
return;
V_22 = F_29 ( * V_20 -> V_53 ) ;
memcpy ( V_20 -> V_52 . V_27 , V_22 , V_51 ) ;
memmove ( V_22 , V_22 + V_51 , ( void * ) V_20 -> V_1 - V_22 ) ;
V_20 -> V_52 . V_29 = 0 ;
}
static T_1 * F_30 ( struct V_46 * V_20 ,
T_3 V_10 )
{
static T_1 * V_1 ;
int V_54 ;
int V_55 , V_56 ;
if ( V_10 > V_40 )
return NULL ;
if ( V_20 -> V_16 -> V_5 + V_10 > V_20 -> V_16 -> V_28 )
return NULL ;
V_55 = ( V_20 -> V_50 - V_20 -> V_1 ) << 2 ;
V_56 = V_10 - V_55 ;
if ( V_20 -> V_48 )
V_20 -> V_48 -> V_29 += V_55 ;
else
V_20 -> V_16 -> V_30 += V_55 ;
V_20 -> V_53 ++ ;
V_20 -> V_48 = NULL ;
V_20 -> V_52 . V_27 = V_20 -> V_1 ;
V_20 -> V_52 . V_29 = V_55 ;
V_1 = F_29 ( * V_20 -> V_53 ) ;
V_20 -> V_1 = ( void * ) V_1 + V_56 ;
V_54 = V_20 -> V_16 -> V_28 - V_20 -> V_16 -> V_5 ;
V_20 -> V_50 = ( void * ) V_1 + F_31 ( int , V_54 , V_40 ) ;
V_20 -> V_16 -> V_30 += V_56 ;
V_20 -> V_16 -> V_5 += V_10 ;
return V_1 ;
}
T_1 * F_32 ( struct V_46 * V_20 , T_3 V_10 )
{
T_1 * V_1 = V_20 -> V_1 ;
T_1 * V_57 ;
F_28 ( V_20 ) ;
V_10 += 3 ;
V_10 &= ~ 3 ;
V_57 = V_1 + ( V_10 >> 2 ) ;
if ( F_33 ( V_57 > V_20 -> V_50 || V_57 < V_1 ) )
return F_30 ( V_20 , V_10 ) ;
V_20 -> V_1 = V_57 ;
if ( V_20 -> V_48 )
V_20 -> V_48 -> V_29 += V_10 ;
else
V_20 -> V_16 -> V_30 += V_10 ;
V_20 -> V_16 -> V_5 += V_10 ;
return V_1 ;
}
void F_34 ( struct V_46 * V_20 , T_3 V_5 )
{
struct V_15 * V_16 = V_20 -> V_16 ;
struct V_24 * V_25 = V_16 -> V_25 ;
struct V_24 * V_26 = V_16 -> V_26 ;
int V_58 ;
int V_59 ;
if ( V_5 > V_16 -> V_5 ) {
F_22 ( 1 ) ;
return;
}
F_28 ( V_20 ) ;
V_58 = F_31 ( int , V_16 -> V_5 - V_5 , V_26 -> V_29 ) ;
V_26 -> V_29 -= V_58 ;
V_16 -> V_5 -= V_58 ;
if ( V_26 -> V_29 ) {
V_20 -> V_1 = V_26 -> V_27 + V_26 -> V_29 ;
F_22 ( ! V_20 -> V_50 ) ;
F_22 ( ! V_20 -> V_48 ) ;
return;
}
F_22 ( V_58 ) ;
V_58 = F_31 ( int , V_16 -> V_5 - V_5 , V_16 -> V_30 ) ;
V_16 -> V_30 -= V_58 ;
V_16 -> V_5 -= V_58 ;
V_59 = V_16 -> V_19 + V_16 -> V_30 ;
V_20 -> V_53 = V_16 -> V_18 + ( V_59 >> V_38 ) ;
if ( V_16 -> V_30 ) {
V_20 -> V_1 = F_29 ( * V_20 -> V_53 ) ;
V_20 -> V_50 = ( void * ) V_20 -> V_1 + V_40 ;
V_20 -> V_1 = ( void * ) V_20 -> V_1 + ( V_59 % V_40 ) ;
F_22 ( V_20 -> V_48 ) ;
return;
}
if ( V_58 ) {
V_20 -> V_50 = V_25 -> V_27 + V_25 -> V_29 ;
V_20 -> V_53 -- ;
}
V_25 -> V_29 = V_5 ;
V_16 -> V_5 = V_5 ;
V_20 -> V_1 = V_25 -> V_27 + V_25 -> V_29 ;
V_20 -> V_48 = V_16 -> V_25 ;
}
int F_35 ( struct V_46 * V_20 , int V_60 )
{
struct V_15 * V_16 = V_20 -> V_16 ;
int V_61 = ( void * ) V_20 -> V_50 - ( void * ) V_20 -> V_1 ;
int V_62 = V_16 -> V_5 + V_61 ;
if ( V_60 < 0 || V_60 < V_16 -> V_5 )
return - 1 ;
if ( V_60 > V_16 -> V_28 )
return 0 ;
if ( V_60 < V_62 )
V_20 -> V_50 = ( void * ) V_20 -> V_50 + V_60 - V_62 ;
V_16 -> V_28 = V_60 ;
return 0 ;
}
void F_36 ( struct V_46 * V_20 , struct V_22 * * V_18 , unsigned int V_23 ,
unsigned int V_5 )
{
struct V_15 * V_16 = V_20 -> V_16 ;
struct V_24 * V_48 = V_16 -> V_26 ;
V_16 -> V_18 = V_18 ;
V_16 -> V_19 = V_23 ;
V_16 -> V_30 = V_5 ;
V_48 -> V_27 = ( char * ) V_20 -> V_1 ;
V_48 -> V_29 = 0 ;
V_20 -> V_48 = V_48 ;
if ( V_5 & 3 ) {
unsigned int V_63 = 4 - ( V_5 & 3 ) ;
F_17 ( V_20 -> V_1 >= V_20 -> V_50 ) ;
V_48 -> V_27 = ( char * ) V_20 -> V_1 + ( V_5 & 3 ) ;
V_48 -> V_29 += V_63 ;
V_5 += V_63 ;
* V_20 -> V_1 ++ = 0 ;
}
V_16 -> V_28 += V_5 ;
V_16 -> V_5 += V_5 ;
}
static void F_37 ( struct V_46 * V_20 , struct V_24 * V_48 ,
unsigned int V_5 )
{
if ( V_5 > V_48 -> V_29 )
V_5 = V_48 -> V_29 ;
V_20 -> V_1 = ( T_1 * ) V_48 -> V_27 ;
V_20 -> V_50 = ( T_1 * ) ( V_48 -> V_27 + V_5 ) ;
V_20 -> V_48 = V_48 ;
V_20 -> V_53 = NULL ;
}
static int F_38 ( struct V_46 * V_20 ,
unsigned int V_23 , unsigned int V_5 )
{
unsigned int V_64 ;
unsigned int V_14 ;
unsigned int V_65 ;
unsigned int V_66 ;
void * V_17 ;
V_14 = V_20 -> V_16 -> V_30 ;
if ( V_23 >= V_14 )
return - V_67 ;
V_14 -= V_23 ;
if ( V_5 > V_14 )
V_5 = V_14 ;
V_23 += V_20 -> V_16 -> V_19 ;
V_64 = V_23 >> V_38 ;
V_20 -> V_53 = & V_20 -> V_16 -> V_18 [ V_64 ] ;
V_17 = F_29 ( * V_20 -> V_53 ) ;
V_65 = V_23 & ~ V_39 ;
V_20 -> V_1 = ( T_1 * ) ( V_17 + V_65 ) ;
V_66 = V_65 + V_5 ;
if ( V_66 > V_40 )
V_66 = V_40 ;
V_20 -> V_50 = ( T_1 * ) ( V_17 + V_66 ) ;
V_20 -> V_48 = NULL ;
return 0 ;
}
static void F_39 ( struct V_46 * V_20 )
{
unsigned int V_68 ;
V_68 = ( 1 + V_20 -> V_53 - V_20 -> V_16 -> V_18 ) << V_38 ;
V_68 -= V_20 -> V_16 -> V_19 ;
if ( F_38 ( V_20 , V_68 , V_40 ) < 0 )
F_37 ( V_20 , V_20 -> V_16 -> V_26 , V_20 -> V_47 << 2 ) ;
}
static bool F_40 ( struct V_46 * V_20 )
{
if ( V_20 -> V_53 != NULL )
F_39 ( V_20 ) ;
else if ( V_20 -> V_48 == V_20 -> V_16 -> V_25 ) {
if ( F_38 ( V_20 , 0 , V_40 ) < 0 )
F_37 ( V_20 , V_20 -> V_16 -> V_26 , V_20 -> V_47 << 2 ) ;
}
return V_20 -> V_1 != V_20 -> V_50 ;
}
void F_41 ( struct V_46 * V_20 , struct V_15 * V_16 , T_1 * V_1 )
{
V_20 -> V_16 = V_16 ;
V_20 -> V_52 . V_27 = NULL ;
V_20 -> V_52 . V_29 = 0 ;
V_20 -> V_47 = F_2 ( V_16 -> V_5 ) ;
if ( V_16 -> V_25 [ 0 ] . V_29 != 0 )
F_37 ( V_20 , V_16 -> V_25 , V_16 -> V_5 ) ;
else if ( V_16 -> V_30 != 0 )
F_38 ( V_20 , 0 , V_16 -> V_5 ) ;
else
F_37 ( V_20 , V_16 -> V_25 , V_16 -> V_5 ) ;
if ( V_1 != NULL && V_1 > V_20 -> V_1 && V_20 -> V_50 >= V_1 ) {
V_20 -> V_47 -= V_1 - V_20 -> V_1 ;
V_20 -> V_1 = V_1 ;
}
}
void F_42 ( struct V_46 * V_20 , struct V_15 * V_16 ,
struct V_22 * * V_18 , unsigned int V_5 )
{
memset ( V_16 , 0 , sizeof( * V_16 ) ) ;
V_16 -> V_18 = V_18 ;
V_16 -> V_30 = V_5 ;
V_16 -> V_28 = V_5 ;
V_16 -> V_5 = V_5 ;
F_41 ( V_20 , V_16 , NULL ) ;
}
static T_1 * F_43 ( struct V_46 * V_20 , T_3 V_10 )
{
unsigned int V_47 = F_2 ( V_10 ) ;
T_1 * V_1 = V_20 -> V_1 ;
T_1 * V_57 = V_1 + V_47 ;
if ( F_33 ( V_47 > V_20 -> V_47 || V_57 > V_20 -> V_50 || V_57 < V_1 ) )
return NULL ;
V_20 -> V_1 = V_57 ;
V_20 -> V_47 -= V_47 ;
return V_1 ;
}
void F_27 ( struct V_46 * V_20 , void * V_16 , T_3 V_28 )
{
V_20 -> V_52 . V_27 = V_16 ;
V_20 -> V_52 . V_29 = V_28 ;
}
static T_1 * F_44 ( struct V_46 * V_20 , T_3 V_10 )
{
T_1 * V_1 ;
char * V_69 = V_20 -> V_52 . V_27 ;
T_3 V_70 = ( char * ) V_20 -> V_50 - ( char * ) V_20 -> V_1 ;
if ( V_10 > V_20 -> V_52 . V_29 )
return NULL ;
V_1 = F_43 ( V_20 , V_70 ) ;
if ( V_1 == NULL )
return NULL ;
memcpy ( V_69 , V_1 , V_70 ) ;
V_69 += V_70 ;
V_10 -= V_70 ;
if ( ! F_40 ( V_20 ) )
return NULL ;
V_1 = F_43 ( V_20 , V_10 ) ;
if ( V_1 == NULL )
return NULL ;
memcpy ( V_69 , V_1 , V_10 ) ;
return V_20 -> V_52 . V_27 ;
}
T_1 * F_45 ( struct V_46 * V_20 , T_3 V_10 )
{
T_1 * V_1 ;
if ( V_10 == 0 )
return V_20 -> V_1 ;
if ( V_20 -> V_1 == V_20 -> V_50 && ! F_40 ( V_20 ) )
return NULL ;
V_1 = F_43 ( V_20 , V_10 ) ;
if ( V_1 != NULL )
return V_1 ;
return F_44 ( V_20 , V_10 ) ;
}
static unsigned int F_46 ( struct V_46 * V_20 , unsigned int V_5 )
{
struct V_15 * V_16 = V_20 -> V_16 ;
struct V_24 * V_48 ;
unsigned int V_47 = F_2 ( V_5 ) ;
unsigned int V_71 = F_25 ( V_20 ) ;
if ( V_20 -> V_47 == 0 )
return 0 ;
V_48 = V_16 -> V_25 ;
if ( V_48 -> V_29 > V_71 ) {
F_21 ( V_16 , V_48 -> V_29 - V_71 ) ;
V_20 -> V_47 = F_2 ( V_16 -> V_5 - V_71 ) ;
}
if ( V_47 > V_20 -> V_47 ) {
V_47 = V_20 -> V_47 ;
V_5 = V_47 << 2 ;
}
if ( V_16 -> V_30 <= V_5 )
V_5 = V_16 -> V_30 ;
else if ( V_47 < V_20 -> V_47 ) {
F_23 ( V_16 , V_16 -> V_30 - V_5 ) ;
V_20 -> V_47 = F_2 ( V_16 -> V_5 - V_71 ) ;
}
return V_5 ;
}
unsigned int F_47 ( struct V_46 * V_20 , unsigned int V_5 )
{
struct V_15 * V_16 = V_20 -> V_16 ;
struct V_24 * V_48 ;
unsigned int V_47 ;
unsigned int V_50 ;
unsigned int V_11 ;
V_5 = F_46 ( V_20 , V_5 ) ;
if ( V_5 == 0 )
return 0 ;
V_47 = F_2 ( V_5 ) ;
V_11 = ( V_47 << 2 ) - V_5 ;
V_20 -> V_48 = V_48 = V_16 -> V_26 ;
V_50 = ( ( V_20 -> V_47 - V_47 ) << 2 ) + V_11 ;
if ( V_50 > V_48 -> V_29 )
V_50 = V_48 -> V_29 ;
V_20 -> V_1 = ( T_1 * ) ( ( char * ) V_48 -> V_27 + V_11 ) ;
V_20 -> V_50 = ( T_1 * ) ( ( char * ) V_48 -> V_27 + V_50 ) ;
V_20 -> V_53 = NULL ;
V_20 -> V_47 = F_2 ( V_50 - V_11 ) ;
return V_5 ;
}
void F_48 ( struct V_46 * V_20 , unsigned int V_5 )
{
V_5 = F_46 ( V_20 , V_5 ) ;
if ( V_5 != 0 )
F_38 ( V_20 , 0 , V_5 ) ;
}
void
F_49 ( struct V_24 * V_48 , struct V_15 * V_16 )
{
V_16 -> V_25 [ 0 ] = * V_48 ;
V_16 -> V_26 [ 0 ] = V_72 ;
V_16 -> V_30 = 0 ;
V_16 -> V_28 = V_16 -> V_5 = V_48 -> V_29 ;
}
int
F_50 ( struct V_15 * V_16 , struct V_15 * V_73 ,
unsigned int V_23 , unsigned int V_5 )
{
V_73 -> V_28 = V_73 -> V_5 = V_5 ;
if ( V_23 < V_16 -> V_25 [ 0 ] . V_29 ) {
V_73 -> V_25 [ 0 ] . V_27 = V_16 -> V_25 [ 0 ] . V_27 + V_23 ;
V_73 -> V_25 [ 0 ] . V_29 = F_31 (unsigned int, len,
buf->head[0].iov_len - base) ;
V_5 -= V_73 -> V_25 [ 0 ] . V_29 ;
V_23 = 0 ;
} else {
V_23 -= V_16 -> V_25 [ 0 ] . V_29 ;
V_73 -> V_25 [ 0 ] . V_29 = 0 ;
}
if ( V_23 < V_16 -> V_30 ) {
V_73 -> V_30 = F_51 ( V_16 -> V_30 - V_23 , V_5 ) ;
V_23 += V_16 -> V_19 ;
V_73 -> V_19 = V_23 & ~ V_39 ;
V_73 -> V_18 = & V_16 -> V_18 [ V_23 >> V_38 ] ;
V_5 -= V_73 -> V_30 ;
V_23 = 0 ;
} else {
V_23 -= V_16 -> V_30 ;
V_73 -> V_30 = 0 ;
}
if ( V_23 < V_16 -> V_26 [ 0 ] . V_29 ) {
V_73 -> V_26 [ 0 ] . V_27 = V_16 -> V_26 [ 0 ] . V_27 + V_23 ;
V_73 -> V_26 [ 0 ] . V_29 = F_31 (unsigned int, len,
buf->tail[0].iov_len - base) ;
V_5 -= V_73 -> V_26 [ 0 ] . V_29 ;
V_23 = 0 ;
} else {
V_23 -= V_16 -> V_26 [ 0 ] . V_29 ;
V_73 -> V_26 [ 0 ] . V_29 = 0 ;
}
if ( V_23 || V_5 )
return - 1 ;
return 0 ;
}
void F_52 ( struct V_15 * V_16 , unsigned int V_5 )
{
T_3 V_71 ;
unsigned int V_74 = V_5 ;
if ( V_16 -> V_26 [ 0 ] . V_29 ) {
V_71 = F_31 ( T_3 , V_16 -> V_26 [ 0 ] . V_29 , V_74 ) ;
V_16 -> V_26 [ 0 ] . V_29 -= V_71 ;
V_74 -= V_71 ;
if ( ! V_74 )
goto V_75;
}
if ( V_16 -> V_30 ) {
V_71 = F_31 (unsigned int, buf->page_len, trim) ;
V_16 -> V_30 -= V_71 ;
V_74 -= V_71 ;
if ( ! V_74 )
goto V_75;
}
if ( V_16 -> V_25 [ 0 ] . V_29 ) {
V_71 = F_31 ( T_3 , V_16 -> V_25 [ 0 ] . V_29 , V_74 ) ;
V_16 -> V_25 [ 0 ] . V_29 -= V_71 ;
V_74 -= V_71 ;
}
V_75:
V_16 -> V_5 -= ( V_5 - V_74 ) ;
}
static void F_53 ( struct V_15 * V_73 , void * V_3 , unsigned int V_5 )
{
unsigned int V_76 ;
V_76 = F_31 (unsigned int, len, subbuf->head[0].iov_len) ;
memcpy ( V_3 , V_73 -> V_25 [ 0 ] . V_27 , V_76 ) ;
V_5 -= V_76 ;
V_3 += V_76 ;
V_76 = F_31 (unsigned int, len, subbuf->page_len) ;
if ( V_76 )
F_20 ( V_3 , V_73 -> V_18 , V_73 -> V_19 , V_76 ) ;
V_5 -= V_76 ;
V_3 += V_76 ;
V_76 = F_31 (unsigned int, len, subbuf->tail[0].iov_len) ;
memcpy ( V_3 , V_73 -> V_26 [ 0 ] . V_27 , V_76 ) ;
}
int F_54 ( struct V_15 * V_16 , unsigned int V_23 , void * V_3 , unsigned int V_5 )
{
struct V_15 V_73 ;
int V_77 ;
V_77 = F_50 ( V_16 , & V_73 , V_23 , V_5 ) ;
if ( V_77 != 0 )
return V_77 ;
F_53 ( & V_73 , V_3 , V_5 ) ;
return 0 ;
}
static void F_55 ( struct V_15 * V_73 , void * V_3 , unsigned int V_5 )
{
unsigned int V_76 ;
V_76 = F_31 (unsigned int, len, subbuf->head[0].iov_len) ;
memcpy ( V_73 -> V_25 [ 0 ] . V_27 , V_3 , V_76 ) ;
V_5 -= V_76 ;
V_3 += V_76 ;
V_76 = F_31 (unsigned int, len, subbuf->page_len) ;
if ( V_76 )
F_19 ( V_73 -> V_18 , V_73 -> V_19 , V_3 , V_76 ) ;
V_5 -= V_76 ;
V_3 += V_76 ;
V_76 = F_31 (unsigned int, len, subbuf->tail[0].iov_len) ;
memcpy ( V_73 -> V_26 [ 0 ] . V_27 , V_3 , V_76 ) ;
}
int F_56 ( struct V_15 * V_16 , unsigned int V_23 , void * V_3 , unsigned int V_5 )
{
struct V_15 V_73 ;
int V_77 ;
V_77 = F_50 ( V_16 , & V_73 , V_23 , V_5 ) ;
if ( V_77 != 0 )
return V_77 ;
F_55 ( & V_73 , V_3 , V_5 ) ;
return 0 ;
}
int
F_57 ( struct V_15 * V_16 , unsigned int V_23 , T_2 * V_3 )
{
T_1 V_78 ;
int V_77 ;
V_77 = F_54 ( V_16 , V_23 , & V_78 , sizeof( * V_3 ) ) ;
if ( V_77 )
return V_77 ;
* V_3 = F_5 ( V_78 ) ;
return 0 ;
}
int
F_58 ( struct V_15 * V_16 , unsigned int V_23 , T_2 V_3 )
{
T_1 V_78 = F_3 ( V_3 ) ;
return F_56 ( V_16 , V_23 , & V_78 , sizeof( V_3 ) ) ;
}
int F_59 ( struct V_15 * V_16 , struct V_2 * V_3 , unsigned int V_21 )
{
struct V_15 V_73 ;
if ( F_57 ( V_16 , V_21 , & V_3 -> V_5 ) )
return - V_79 ;
if ( F_50 ( V_16 , & V_73 , V_21 + 4 , V_3 -> V_5 ) )
return - V_79 ;
V_3 -> V_6 = V_73 . V_25 [ 0 ] . V_27 ;
if ( V_73 . V_25 [ 0 ] . V_29 == V_3 -> V_5 )
return 0 ;
V_3 -> V_6 = V_73 . V_26 [ 0 ] . V_27 ;
if ( V_73 . V_26 [ 0 ] . V_29 == V_3 -> V_5 )
return 0 ;
if ( V_3 -> V_5 > V_16 -> V_28 - V_16 -> V_5 )
return - V_80 ;
if ( V_16 -> V_26 [ 0 ] . V_29 != 0 )
V_3 -> V_6 = V_16 -> V_26 [ 0 ] . V_27 + V_16 -> V_26 [ 0 ] . V_29 ;
else
V_3 -> V_6 = V_16 -> V_25 [ 0 ] . V_27 + V_16 -> V_25 [ 0 ] . V_29 ;
F_53 ( & V_73 , V_3 -> V_6 , V_3 -> V_5 ) ;
return 0 ;
}
static int
F_60 ( struct V_15 * V_16 , unsigned int V_23 ,
struct V_81 * V_82 , int V_83 )
{
char * V_84 = NULL , * V_85 ;
unsigned int V_86 = 0 , V_87 , V_88 ;
struct V_22 * * V_89 = NULL ;
int V_90 ;
if ( V_83 ) {
if ( F_58 ( V_16 , V_23 , V_82 -> V_91 ) != 0 )
return - V_67 ;
} else {
if ( F_57 ( V_16 , V_23 , & V_82 -> V_91 ) != 0 ||
V_82 -> V_91 > V_82 -> V_92 ||
( unsigned long ) V_23 + 4 + V_82 -> V_91 *
V_82 -> V_93 > V_16 -> V_5 )
return - V_67 ;
}
V_23 += 4 ;
if ( ! V_82 -> V_94 )
return 0 ;
V_87 = V_82 -> V_91 * V_82 -> V_93 ;
if ( V_87 && V_23 < V_16 -> V_25 -> V_29 ) {
V_85 = V_16 -> V_25 -> V_27 + V_23 ;
V_88 = F_31 (unsigned int, todo,
buf->head->iov_len - base) ;
V_87 -= V_88 ;
while ( V_88 >= V_82 -> V_93 ) {
V_90 = V_82 -> V_94 ( V_82 , V_85 ) ;
if ( V_90 )
goto V_95;
V_85 += V_82 -> V_93 ;
V_88 -= V_82 -> V_93 ;
}
if ( V_88 ) {
if ( ! V_84 ) {
V_84 = F_61 ( V_82 -> V_93 , V_96 ) ;
V_90 = - V_80 ;
if ( ! V_84 )
goto V_95;
}
if ( V_83 ) {
V_90 = V_82 -> V_94 ( V_82 , V_84 ) ;
if ( V_90 )
goto V_95;
memcpy ( V_85 , V_84 , V_88 ) ;
} else
memcpy ( V_84 , V_85 , V_88 ) ;
V_86 = V_88 ;
}
V_23 = V_16 -> V_25 -> V_29 ;
}
V_23 -= V_16 -> V_25 -> V_29 ;
if ( V_87 && V_23 < V_16 -> V_30 ) {
unsigned int V_97 ;
V_88 = F_51 ( V_87 , V_16 -> V_30 - V_23 ) ;
V_87 -= V_88 ;
V_23 += V_16 -> V_19 ;
V_89 = V_16 -> V_18 + ( V_23 >> V_38 ) ;
V_23 &= ~ V_39 ;
V_97 = F_31 (unsigned int, PAGE_SIZE - base,
avail_here) ;
V_85 = F_62 ( * V_89 ) + V_23 ;
while ( V_88 ) {
V_88 -= V_97 ;
if ( V_86 || V_97 < V_82 -> V_93 ) {
unsigned int V_98 = F_51 ( V_97 ,
V_82 -> V_93 - V_86 ) ;
if ( ! V_84 ) {
V_84 = F_61 ( V_82 -> V_93 ,
V_96 ) ;
V_90 = - V_80 ;
if ( ! V_84 )
goto V_95;
}
if ( V_83 ) {
if ( ! V_86 ) {
V_90 = V_82 -> V_94 ( V_82 , V_84 ) ;
if ( V_90 )
goto V_95;
}
memcpy ( V_85 , V_84 + V_86 , V_98 ) ;
V_86 += V_98 ;
if ( V_86 == V_82 -> V_93 )
V_86 = 0 ;
} else {
memcpy ( V_84 + V_86 , V_85 , V_98 ) ;
V_86 += V_98 ;
if ( V_86 == V_82 -> V_93 ) {
V_90 = V_82 -> V_94 ( V_82 , V_84 ) ;
if ( V_90 )
goto V_95;
V_86 = 0 ;
}
}
V_97 -= V_98 ;
V_85 += V_98 ;
}
while ( V_97 >= V_82 -> V_93 ) {
V_90 = V_82 -> V_94 ( V_82 , V_85 ) ;
if ( V_90 )
goto V_95;
V_85 += V_82 -> V_93 ;
V_97 -= V_82 -> V_93 ;
}
if ( V_97 ) {
unsigned int V_98 = F_51 ( V_97 ,
V_82 -> V_93 - V_86 ) ;
if ( ! V_84 ) {
V_84 = F_61 ( V_82 -> V_93 ,
V_96 ) ;
V_90 = - V_80 ;
if ( ! V_84 )
goto V_95;
}
if ( V_83 ) {
if ( ! V_86 ) {
V_90 = V_82 -> V_94 ( V_82 , V_84 ) ;
if ( V_90 )
goto V_95;
}
memcpy ( V_85 , V_84 + V_86 , V_98 ) ;
V_86 += V_98 ;
if ( V_86 == V_82 -> V_93 )
V_86 = 0 ;
} else {
memcpy ( V_84 + V_86 , V_85 , V_98 ) ;
V_86 += V_98 ;
if ( V_86 == V_82 -> V_93 ) {
V_90 = V_82 -> V_94 ( V_82 , V_84 ) ;
if ( V_90 )
goto V_95;
V_86 = 0 ;
}
}
}
if ( V_88 ) {
F_63 ( * V_89 ) ;
V_89 ++ ;
V_85 = F_62 ( * V_89 ) ;
}
V_97 = F_51 ( V_88 ,
( unsigned int ) V_40 ) ;
}
V_23 = V_16 -> V_30 ;
}
V_23 -= V_16 -> V_30 ;
if ( V_87 ) {
V_85 = V_16 -> V_26 -> V_27 + V_23 ;
if ( V_86 ) {
unsigned int V_98 = V_82 -> V_93 - V_86 ;
if ( V_83 )
memcpy ( V_85 , V_84 + V_86 , V_98 ) ;
else {
memcpy ( V_84 + V_86 , V_85 , V_98 ) ;
V_90 = V_82 -> V_94 ( V_82 , V_84 ) ;
if ( V_90 )
goto V_95;
}
V_87 -= V_98 ;
V_85 += V_98 ;
}
while ( V_87 ) {
V_90 = V_82 -> V_94 ( V_82 , V_85 ) ;
if ( V_90 )
goto V_95;
V_85 += V_82 -> V_93 ;
V_87 -= V_82 -> V_93 ;
}
}
V_90 = 0 ;
V_95:
F_64 ( V_84 ) ;
if ( V_89 )
F_63 ( * V_89 ) ;
return V_90 ;
}
int
F_65 ( struct V_15 * V_16 , unsigned int V_23 ,
struct V_81 * V_82 )
{
if ( V_23 >= V_16 -> V_5 )
return - V_67 ;
return F_60 ( V_16 , V_23 , V_82 , 0 ) ;
}
int
F_66 ( struct V_15 * V_16 , unsigned int V_23 ,
struct V_81 * V_82 )
{
if ( ( unsigned long ) V_23 + 4 + V_82 -> V_91 * V_82 -> V_93 >
V_16 -> V_25 -> V_29 + V_16 -> V_30 + V_16 -> V_26 -> V_29 )
return - V_67 ;
return F_60 ( V_16 , V_23 , V_82 , 1 ) ;
}
int
F_67 ( struct V_15 * V_16 , unsigned int V_21 , unsigned int V_5 ,
int (* F_68)( struct V_99 * , void * ) , void * V_6 )
{
int V_100 , V_101 = 0 ;
unsigned int V_30 , V_102 , V_103 ;
struct V_99 V_104 [ 1 ] ;
F_69 ( V_104 , 1 ) ;
if ( V_21 >= V_16 -> V_25 [ 0 ] . V_29 ) {
V_21 -= V_16 -> V_25 [ 0 ] . V_29 ;
} else {
V_102 = V_16 -> V_25 [ 0 ] . V_29 - V_21 ;
if ( V_102 > V_5 )
V_102 = V_5 ;
F_70 ( V_104 , V_16 -> V_25 [ 0 ] . V_27 + V_21 , V_102 ) ;
V_101 = F_68 ( V_104 , V_6 ) ;
if ( V_101 )
goto V_95;
V_21 = 0 ;
V_5 -= V_102 ;
}
if ( V_5 == 0 )
goto V_95;
if ( V_21 >= V_16 -> V_30 ) {
V_21 -= V_16 -> V_30 ;
} else {
V_30 = V_16 -> V_30 - V_21 ;
if ( V_30 > V_5 )
V_30 = V_5 ;
V_5 -= V_30 ;
V_103 = ( V_21 + V_16 -> V_19 ) & ( V_40 - 1 ) ;
V_100 = ( V_21 + V_16 -> V_19 ) >> V_38 ;
V_102 = V_40 - V_103 ;
do {
if ( V_102 > V_30 )
V_102 = V_30 ;
F_71 ( V_104 , V_16 -> V_18 [ V_100 ] , V_102 , V_103 ) ;
V_101 = F_68 ( V_104 , V_6 ) ;
if ( V_101 )
goto V_95;
V_30 -= V_102 ;
V_100 ++ ;
V_103 = 0 ;
V_102 = V_40 ;
} while ( V_30 != 0 );
V_21 = 0 ;
}
if ( V_5 == 0 )
goto V_95;
if ( V_21 < V_16 -> V_26 [ 0 ] . V_29 ) {
V_102 = V_16 -> V_26 [ 0 ] . V_29 - V_21 ;
if ( V_102 > V_5 )
V_102 = V_5 ;
F_70 ( V_104 , V_16 -> V_26 [ 0 ] . V_27 + V_21 , V_102 ) ;
V_101 = F_68 ( V_104 , V_6 ) ;
V_5 -= V_102 ;
}
if ( V_5 != 0 )
V_101 = - V_67 ;
V_95:
return V_101 ;
}
