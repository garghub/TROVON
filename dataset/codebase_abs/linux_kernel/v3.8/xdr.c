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
V_35 = F_13 ( * V_33 ) ;
memmove ( V_36 + V_31 , V_35 + V_32 , V_37 ) ;
F_18 ( * V_34 ) ;
F_14 ( V_35 ) ;
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
T_1 * F_27 ( struct V_46 * V_20 , T_3 V_10 )
{
T_1 * V_1 = V_20 -> V_1 ;
T_1 * V_51 ;
V_10 += 3 ;
V_10 &= ~ 3 ;
V_51 = V_1 + ( V_10 >> 2 ) ;
if ( F_28 ( V_51 > V_20 -> V_50 || V_51 < V_1 ) )
return NULL ;
V_20 -> V_1 = V_51 ;
V_20 -> V_48 -> V_29 += V_10 ;
V_20 -> V_16 -> V_5 += V_10 ;
return V_1 ;
}
void F_29 ( struct V_46 * V_20 , struct V_22 * * V_18 , unsigned int V_23 ,
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
unsigned int V_52 = 4 - ( V_5 & 3 ) ;
F_17 ( V_20 -> V_1 >= V_20 -> V_50 ) ;
V_48 -> V_27 = ( char * ) V_20 -> V_1 + ( V_5 & 3 ) ;
V_48 -> V_29 += V_52 ;
V_5 += V_52 ;
* V_20 -> V_1 ++ = 0 ;
}
V_16 -> V_28 += V_5 ;
V_16 -> V_5 += V_5 ;
}
static void F_30 ( struct V_46 * V_20 , struct V_24 * V_48 ,
unsigned int V_5 )
{
if ( V_5 > V_48 -> V_29 )
V_5 = V_48 -> V_29 ;
V_20 -> V_1 = ( T_1 * ) V_48 -> V_27 ;
V_20 -> V_50 = ( T_1 * ) ( V_48 -> V_27 + V_5 ) ;
V_20 -> V_48 = V_48 ;
V_20 -> V_53 = NULL ;
}
static int F_31 ( struct V_46 * V_20 ,
unsigned int V_23 , unsigned int V_5 )
{
unsigned int V_54 ;
unsigned int V_14 ;
unsigned int V_55 ;
unsigned int V_56 ;
void * V_17 ;
V_14 = V_20 -> V_16 -> V_30 ;
if ( V_23 >= V_14 )
return - V_57 ;
V_14 -= V_23 ;
if ( V_5 > V_14 )
V_5 = V_14 ;
V_23 += V_20 -> V_16 -> V_19 ;
V_54 = V_23 >> V_58 ;
V_20 -> V_53 = & V_20 -> V_16 -> V_18 [ V_54 ] ;
V_17 = F_32 ( * V_20 -> V_53 ) ;
V_55 = V_23 & ~ V_59 ;
V_20 -> V_1 = ( T_1 * ) ( V_17 + V_55 ) ;
V_56 = V_55 + V_5 ;
if ( V_56 > V_60 )
V_56 = V_60 ;
V_20 -> V_50 = ( T_1 * ) ( V_17 + V_56 ) ;
V_20 -> V_48 = NULL ;
return 0 ;
}
static void F_33 ( struct V_46 * V_20 )
{
unsigned int V_61 ;
V_61 = ( 1 + V_20 -> V_53 - V_20 -> V_16 -> V_18 ) << V_58 ;
V_61 -= V_20 -> V_16 -> V_19 ;
if ( F_31 ( V_20 , V_61 , V_60 ) < 0 )
F_30 ( V_20 , V_20 -> V_16 -> V_26 , V_20 -> V_16 -> V_5 ) ;
}
static bool F_34 ( struct V_46 * V_20 )
{
if ( V_20 -> V_53 != NULL )
F_33 ( V_20 ) ;
else if ( V_20 -> V_48 == V_20 -> V_16 -> V_25 ) {
if ( F_31 ( V_20 , 0 , V_60 ) < 0 )
F_30 ( V_20 , V_20 -> V_16 -> V_26 , V_20 -> V_16 -> V_5 ) ;
}
return V_20 -> V_1 != V_20 -> V_50 ;
}
void F_35 ( struct V_46 * V_20 , struct V_15 * V_16 , T_1 * V_1 )
{
V_20 -> V_16 = V_16 ;
V_20 -> V_62 . V_27 = NULL ;
V_20 -> V_62 . V_29 = 0 ;
V_20 -> V_47 = F_2 ( V_16 -> V_5 ) ;
if ( V_16 -> V_25 [ 0 ] . V_29 != 0 )
F_30 ( V_20 , V_16 -> V_25 , V_16 -> V_5 ) ;
else if ( V_16 -> V_30 != 0 )
F_31 ( V_20 , 0 , V_16 -> V_5 ) ;
if ( V_1 != NULL && V_1 > V_20 -> V_1 && V_20 -> V_50 >= V_1 ) {
V_20 -> V_47 -= V_1 - V_20 -> V_1 ;
V_20 -> V_1 = V_1 ;
}
}
void F_36 ( struct V_46 * V_20 , struct V_15 * V_16 ,
struct V_22 * * V_18 , unsigned int V_5 )
{
memset ( V_16 , 0 , sizeof( * V_16 ) ) ;
V_16 -> V_18 = V_18 ;
V_16 -> V_30 = V_5 ;
V_16 -> V_28 = V_5 ;
V_16 -> V_5 = V_5 ;
F_35 ( V_20 , V_16 , NULL ) ;
}
static T_1 * F_37 ( struct V_46 * V_20 , T_3 V_10 )
{
unsigned int V_47 = F_2 ( V_10 ) ;
T_1 * V_1 = V_20 -> V_1 ;
T_1 * V_51 = V_1 + V_47 ;
if ( F_28 ( V_47 > V_20 -> V_47 || V_51 > V_20 -> V_50 || V_51 < V_1 ) )
return NULL ;
V_20 -> V_1 = V_51 ;
V_20 -> V_47 -= V_47 ;
return V_1 ;
}
void F_38 ( struct V_46 * V_20 , void * V_16 , T_3 V_28 )
{
V_20 -> V_62 . V_27 = V_16 ;
V_20 -> V_62 . V_29 = V_28 ;
}
static T_1 * F_39 ( struct V_46 * V_20 , T_3 V_10 )
{
T_1 * V_1 ;
void * V_63 = V_20 -> V_62 . V_27 ;
T_3 V_64 = ( char * ) V_20 -> V_50 - ( char * ) V_20 -> V_1 ;
if ( V_10 > V_20 -> V_62 . V_29 )
return NULL ;
memcpy ( V_63 , V_20 -> V_1 , V_64 ) ;
V_63 += V_64 ;
V_10 -= V_64 ;
if ( ! F_34 ( V_20 ) )
return NULL ;
V_1 = F_37 ( V_20 , V_10 ) ;
if ( V_1 == NULL )
return NULL ;
memcpy ( V_63 , V_1 , V_10 ) ;
return V_20 -> V_62 . V_27 ;
}
T_1 * F_40 ( struct V_46 * V_20 , T_3 V_10 )
{
T_1 * V_1 ;
if ( V_10 == 0 )
return V_20 -> V_1 ;
if ( V_20 -> V_1 == V_20 -> V_50 && ! F_34 ( V_20 ) )
return NULL ;
V_1 = F_37 ( V_20 , V_10 ) ;
if ( V_1 != NULL )
return V_1 ;
return F_39 ( V_20 , V_10 ) ;
}
static unsigned int F_41 ( struct V_46 * V_20 , unsigned int V_5 )
{
struct V_15 * V_16 = V_20 -> V_16 ;
struct V_24 * V_48 ;
unsigned int V_47 = F_2 ( V_5 ) ;
unsigned int V_65 = F_25 ( V_20 ) ;
if ( V_20 -> V_47 == 0 )
return 0 ;
V_48 = V_16 -> V_25 ;
if ( V_48 -> V_29 > V_65 ) {
F_21 ( V_16 , V_48 -> V_29 - V_65 ) ;
V_20 -> V_47 = F_2 ( V_16 -> V_5 - V_65 ) ;
}
if ( V_47 > V_20 -> V_47 ) {
V_47 = V_20 -> V_47 ;
V_5 = V_47 << 2 ;
}
if ( V_16 -> V_30 <= V_5 )
V_5 = V_16 -> V_30 ;
else if ( V_47 < V_20 -> V_47 ) {
F_23 ( V_16 , V_16 -> V_30 - V_5 ) ;
V_20 -> V_47 = F_2 ( V_16 -> V_5 - V_65 ) ;
}
return V_5 ;
}
unsigned int F_42 ( struct V_46 * V_20 , unsigned int V_5 )
{
struct V_15 * V_16 = V_20 -> V_16 ;
struct V_24 * V_48 ;
unsigned int V_47 ;
unsigned int V_50 ;
unsigned int V_11 ;
V_5 = F_41 ( V_20 , V_5 ) ;
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
void F_43 ( struct V_46 * V_20 , unsigned int V_5 )
{
V_5 = F_41 ( V_20 , V_5 ) ;
if ( V_5 != 0 )
F_31 ( V_20 , 0 , V_5 ) ;
}
void
F_44 ( struct V_24 * V_48 , struct V_15 * V_16 )
{
V_16 -> V_25 [ 0 ] = * V_48 ;
V_16 -> V_26 [ 0 ] = V_66 ;
V_16 -> V_30 = 0 ;
V_16 -> V_28 = V_16 -> V_5 = V_48 -> V_29 ;
}
int
F_45 ( struct V_15 * V_16 , struct V_15 * V_67 ,
unsigned int V_23 , unsigned int V_5 )
{
V_67 -> V_28 = V_67 -> V_5 = V_5 ;
if ( V_23 < V_16 -> V_25 [ 0 ] . V_29 ) {
V_67 -> V_25 [ 0 ] . V_27 = V_16 -> V_25 [ 0 ] . V_27 + V_23 ;
V_67 -> V_25 [ 0 ] . V_29 = F_46 (unsigned int, len,
buf->head[0].iov_len - base) ;
V_5 -= V_67 -> V_25 [ 0 ] . V_29 ;
V_23 = 0 ;
} else {
V_67 -> V_25 [ 0 ] . V_27 = NULL ;
V_67 -> V_25 [ 0 ] . V_29 = 0 ;
V_23 -= V_16 -> V_25 [ 0 ] . V_29 ;
}
if ( V_23 < V_16 -> V_30 ) {
V_67 -> V_30 = F_47 ( V_16 -> V_30 - V_23 , V_5 ) ;
V_23 += V_16 -> V_19 ;
V_67 -> V_19 = V_23 & ~ V_39 ;
V_67 -> V_18 = & V_16 -> V_18 [ V_23 >> V_38 ] ;
V_5 -= V_67 -> V_30 ;
V_23 = 0 ;
} else {
V_23 -= V_16 -> V_30 ;
V_67 -> V_30 = 0 ;
}
if ( V_23 < V_16 -> V_26 [ 0 ] . V_29 ) {
V_67 -> V_26 [ 0 ] . V_27 = V_16 -> V_26 [ 0 ] . V_27 + V_23 ;
V_67 -> V_26 [ 0 ] . V_29 = F_46 (unsigned int, len,
buf->tail[0].iov_len - base) ;
V_5 -= V_67 -> V_26 [ 0 ] . V_29 ;
V_23 = 0 ;
} else {
V_67 -> V_26 [ 0 ] . V_27 = NULL ;
V_67 -> V_26 [ 0 ] . V_29 = 0 ;
V_23 -= V_16 -> V_26 [ 0 ] . V_29 ;
}
if ( V_23 || V_5 )
return - 1 ;
return 0 ;
}
static void F_48 ( struct V_15 * V_67 , void * V_3 , unsigned int V_5 )
{
unsigned int V_68 ;
V_68 = F_46 (unsigned int, len, subbuf->head[0].iov_len) ;
memcpy ( V_3 , V_67 -> V_25 [ 0 ] . V_27 , V_68 ) ;
V_5 -= V_68 ;
V_3 += V_68 ;
V_68 = F_46 (unsigned int, len, subbuf->page_len) ;
if ( V_68 )
F_20 ( V_3 , V_67 -> V_18 , V_67 -> V_19 , V_68 ) ;
V_5 -= V_68 ;
V_3 += V_68 ;
V_68 = F_46 (unsigned int, len, subbuf->tail[0].iov_len) ;
memcpy ( V_3 , V_67 -> V_26 [ 0 ] . V_27 , V_68 ) ;
}
int F_49 ( struct V_15 * V_16 , unsigned int V_23 , void * V_3 , unsigned int V_5 )
{
struct V_15 V_67 ;
int V_69 ;
V_69 = F_45 ( V_16 , & V_67 , V_23 , V_5 ) ;
if ( V_69 != 0 )
return V_69 ;
F_48 ( & V_67 , V_3 , V_5 ) ;
return 0 ;
}
static void F_50 ( struct V_15 * V_67 , void * V_3 , unsigned int V_5 )
{
unsigned int V_68 ;
V_68 = F_46 (unsigned int, len, subbuf->head[0].iov_len) ;
memcpy ( V_67 -> V_25 [ 0 ] . V_27 , V_3 , V_68 ) ;
V_5 -= V_68 ;
V_3 += V_68 ;
V_68 = F_46 (unsigned int, len, subbuf->page_len) ;
if ( V_68 )
F_19 ( V_67 -> V_18 , V_67 -> V_19 , V_3 , V_68 ) ;
V_5 -= V_68 ;
V_3 += V_68 ;
V_68 = F_46 (unsigned int, len, subbuf->tail[0].iov_len) ;
memcpy ( V_67 -> V_26 [ 0 ] . V_27 , V_3 , V_68 ) ;
}
int F_51 ( struct V_15 * V_16 , unsigned int V_23 , void * V_3 , unsigned int V_5 )
{
struct V_15 V_67 ;
int V_69 ;
V_69 = F_45 ( V_16 , & V_67 , V_23 , V_5 ) ;
if ( V_69 != 0 )
return V_69 ;
F_50 ( & V_67 , V_3 , V_5 ) ;
return 0 ;
}
int
F_52 ( struct V_15 * V_16 , unsigned int V_23 , T_2 * V_3 )
{
T_1 V_70 ;
int V_69 ;
V_69 = F_49 ( V_16 , V_23 , & V_70 , sizeof( * V_3 ) ) ;
if ( V_69 )
return V_69 ;
* V_3 = F_5 ( V_70 ) ;
return 0 ;
}
int
F_53 ( struct V_15 * V_16 , unsigned int V_23 , T_2 V_3 )
{
T_1 V_70 = F_3 ( V_3 ) ;
return F_51 ( V_16 , V_23 , & V_70 , sizeof( V_3 ) ) ;
}
int F_54 ( struct V_15 * V_16 , struct V_2 * V_3 , unsigned int V_21 )
{
struct V_15 V_67 ;
if ( F_52 ( V_16 , V_21 , & V_3 -> V_5 ) )
return - V_71 ;
if ( F_45 ( V_16 , & V_67 , V_21 + 4 , V_3 -> V_5 ) )
return - V_71 ;
V_3 -> V_6 = V_67 . V_25 [ 0 ] . V_27 ;
if ( V_67 . V_25 [ 0 ] . V_29 == V_3 -> V_5 )
return 0 ;
V_3 -> V_6 = V_67 . V_26 [ 0 ] . V_27 ;
if ( V_67 . V_26 [ 0 ] . V_29 == V_3 -> V_5 )
return 0 ;
if ( V_3 -> V_5 > V_16 -> V_28 - V_16 -> V_5 )
return - V_72 ;
if ( V_16 -> V_26 [ 0 ] . V_29 != 0 )
V_3 -> V_6 = V_16 -> V_26 [ 0 ] . V_27 + V_16 -> V_26 [ 0 ] . V_29 ;
else
V_3 -> V_6 = V_16 -> V_25 [ 0 ] . V_27 + V_16 -> V_25 [ 0 ] . V_29 ;
F_48 ( & V_67 , V_3 -> V_6 , V_3 -> V_5 ) ;
return 0 ;
}
static int
F_55 ( struct V_15 * V_16 , unsigned int V_23 ,
struct V_73 * V_74 , int V_75 )
{
char * V_76 = NULL , * V_77 ;
unsigned int V_78 = 0 , V_79 , V_80 ;
struct V_22 * * V_81 = NULL ;
int V_82 ;
if ( V_75 ) {
if ( F_53 ( V_16 , V_23 , V_74 -> V_83 ) != 0 )
return - V_57 ;
} else {
if ( F_52 ( V_16 , V_23 , & V_74 -> V_83 ) != 0 ||
V_74 -> V_83 > V_74 -> V_84 ||
( unsigned long ) V_23 + 4 + V_74 -> V_83 *
V_74 -> V_85 > V_16 -> V_5 )
return - V_57 ;
}
V_23 += 4 ;
if ( ! V_74 -> V_86 )
return 0 ;
V_79 = V_74 -> V_83 * V_74 -> V_85 ;
if ( V_79 && V_23 < V_16 -> V_25 -> V_29 ) {
V_77 = V_16 -> V_25 -> V_27 + V_23 ;
V_80 = F_46 (unsigned int, todo,
buf->head->iov_len - base) ;
V_79 -= V_80 ;
while ( V_80 >= V_74 -> V_85 ) {
V_82 = V_74 -> V_86 ( V_74 , V_77 ) ;
if ( V_82 )
goto V_87;
V_77 += V_74 -> V_85 ;
V_80 -= V_74 -> V_85 ;
}
if ( V_80 ) {
if ( ! V_76 ) {
V_76 = F_56 ( V_74 -> V_85 , V_88 ) ;
V_82 = - V_72 ;
if ( ! V_76 )
goto V_87;
}
if ( V_75 ) {
V_82 = V_74 -> V_86 ( V_74 , V_76 ) ;
if ( V_82 )
goto V_87;
memcpy ( V_77 , V_76 , V_80 ) ;
} else
memcpy ( V_76 , V_77 , V_80 ) ;
V_78 = V_80 ;
}
V_23 = V_16 -> V_25 -> V_29 ;
}
V_23 -= V_16 -> V_25 -> V_29 ;
if ( V_79 && V_23 < V_16 -> V_30 ) {
unsigned int V_89 ;
V_80 = F_47 ( V_79 , V_16 -> V_30 - V_23 ) ;
V_79 -= V_80 ;
V_23 += V_16 -> V_19 ;
V_81 = V_16 -> V_18 + ( V_23 >> V_38 ) ;
V_23 &= ~ V_39 ;
V_89 = F_46 (unsigned int, PAGE_CACHE_SIZE - base,
avail_here) ;
V_77 = F_57 ( * V_81 ) + V_23 ;
while ( V_80 ) {
V_80 -= V_89 ;
if ( V_78 || V_89 < V_74 -> V_85 ) {
unsigned int V_90 = F_47 ( V_89 ,
V_74 -> V_85 - V_78 ) ;
if ( ! V_76 ) {
V_76 = F_56 ( V_74 -> V_85 ,
V_88 ) ;
V_82 = - V_72 ;
if ( ! V_76 )
goto V_87;
}
if ( V_75 ) {
if ( ! V_78 ) {
V_82 = V_74 -> V_86 ( V_74 , V_76 ) ;
if ( V_82 )
goto V_87;
}
memcpy ( V_77 , V_76 + V_78 , V_90 ) ;
V_78 += V_90 ;
if ( V_78 == V_74 -> V_85 )
V_78 = 0 ;
} else {
memcpy ( V_76 + V_78 , V_77 , V_90 ) ;
V_78 += V_90 ;
if ( V_78 == V_74 -> V_85 ) {
V_82 = V_74 -> V_86 ( V_74 , V_76 ) ;
if ( V_82 )
goto V_87;
V_78 = 0 ;
}
}
V_89 -= V_90 ;
V_77 += V_90 ;
}
while ( V_89 >= V_74 -> V_85 ) {
V_82 = V_74 -> V_86 ( V_74 , V_77 ) ;
if ( V_82 )
goto V_87;
V_77 += V_74 -> V_85 ;
V_89 -= V_74 -> V_85 ;
}
if ( V_89 ) {
unsigned int V_90 = F_47 ( V_89 ,
V_74 -> V_85 - V_78 ) ;
if ( ! V_76 ) {
V_76 = F_56 ( V_74 -> V_85 ,
V_88 ) ;
V_82 = - V_72 ;
if ( ! V_76 )
goto V_87;
}
if ( V_75 ) {
if ( ! V_78 ) {
V_82 = V_74 -> V_86 ( V_74 , V_76 ) ;
if ( V_82 )
goto V_87;
}
memcpy ( V_77 , V_76 + V_78 , V_90 ) ;
V_78 += V_90 ;
if ( V_78 == V_74 -> V_85 )
V_78 = 0 ;
} else {
memcpy ( V_76 + V_78 , V_77 , V_90 ) ;
V_78 += V_90 ;
if ( V_78 == V_74 -> V_85 ) {
V_82 = V_74 -> V_86 ( V_74 , V_76 ) ;
if ( V_82 )
goto V_87;
V_78 = 0 ;
}
}
}
if ( V_80 ) {
F_58 ( * V_81 ) ;
V_81 ++ ;
V_77 = F_57 ( * V_81 ) ;
}
V_89 = F_47 ( V_80 ,
( unsigned int ) V_40 ) ;
}
V_23 = V_16 -> V_30 ;
}
V_23 -= V_16 -> V_30 ;
if ( V_79 ) {
V_77 = V_16 -> V_26 -> V_27 + V_23 ;
if ( V_78 ) {
unsigned int V_90 = V_74 -> V_85 - V_78 ;
if ( V_75 )
memcpy ( V_77 , V_76 + V_78 , V_90 ) ;
else {
memcpy ( V_76 + V_78 , V_77 , V_90 ) ;
V_82 = V_74 -> V_86 ( V_74 , V_76 ) ;
if ( V_82 )
goto V_87;
}
V_79 -= V_90 ;
V_77 += V_90 ;
}
while ( V_79 ) {
V_82 = V_74 -> V_86 ( V_74 , V_77 ) ;
if ( V_82 )
goto V_87;
V_77 += V_74 -> V_85 ;
V_79 -= V_74 -> V_85 ;
}
}
V_82 = 0 ;
V_87:
F_59 ( V_76 ) ;
if ( V_81 )
F_58 ( * V_81 ) ;
return V_82 ;
}
int
F_60 ( struct V_15 * V_16 , unsigned int V_23 ,
struct V_73 * V_74 )
{
if ( V_23 >= V_16 -> V_5 )
return - V_57 ;
return F_55 ( V_16 , V_23 , V_74 , 0 ) ;
}
int
F_61 ( struct V_15 * V_16 , unsigned int V_23 ,
struct V_73 * V_74 )
{
if ( ( unsigned long ) V_23 + 4 + V_74 -> V_83 * V_74 -> V_85 >
V_16 -> V_25 -> V_29 + V_16 -> V_30 + V_16 -> V_26 -> V_29 )
return - V_57 ;
return F_55 ( V_16 , V_23 , V_74 , 1 ) ;
}
int
F_62 ( struct V_15 * V_16 , unsigned int V_21 , unsigned int V_5 ,
int (* F_63)( struct V_91 * , void * ) , void * V_6 )
{
int V_92 , V_93 = 0 ;
unsigned int V_30 , V_94 , V_95 ;
struct V_91 V_96 [ 1 ] ;
F_64 ( V_96 , 1 ) ;
if ( V_21 >= V_16 -> V_25 [ 0 ] . V_29 ) {
V_21 -= V_16 -> V_25 [ 0 ] . V_29 ;
} else {
V_94 = V_16 -> V_25 [ 0 ] . V_29 - V_21 ;
if ( V_94 > V_5 )
V_94 = V_5 ;
F_65 ( V_96 , V_16 -> V_25 [ 0 ] . V_27 + V_21 , V_94 ) ;
V_93 = F_63 ( V_96 , V_6 ) ;
if ( V_93 )
goto V_87;
V_21 = 0 ;
V_5 -= V_94 ;
}
if ( V_5 == 0 )
goto V_87;
if ( V_21 >= V_16 -> V_30 ) {
V_21 -= V_16 -> V_30 ;
} else {
V_30 = V_16 -> V_30 - V_21 ;
if ( V_30 > V_5 )
V_30 = V_5 ;
V_5 -= V_30 ;
V_95 = ( V_21 + V_16 -> V_19 ) & ( V_40 - 1 ) ;
V_92 = ( V_21 + V_16 -> V_19 ) >> V_38 ;
V_94 = V_40 - V_95 ;
do {
if ( V_94 > V_30 )
V_94 = V_30 ;
F_66 ( V_96 , V_16 -> V_18 [ V_92 ] , V_94 , V_95 ) ;
V_93 = F_63 ( V_96 , V_6 ) ;
if ( V_93 )
goto V_87;
V_30 -= V_94 ;
V_92 ++ ;
V_95 = 0 ;
V_94 = V_40 ;
} while ( V_30 != 0 );
V_21 = 0 ;
}
if ( V_5 == 0 )
goto V_87;
if ( V_21 < V_16 -> V_26 [ 0 ] . V_29 ) {
V_94 = V_16 -> V_26 [ 0 ] . V_29 - V_21 ;
if ( V_94 > V_5 )
V_94 = V_5 ;
F_65 ( V_96 , V_16 -> V_26 [ 0 ] . V_27 + V_21 , V_94 ) ;
V_93 = F_63 ( V_96 , V_6 ) ;
V_5 -= V_94 ;
}
if ( V_5 != 0 )
V_93 = - V_57 ;
V_87:
return V_93 ;
}
