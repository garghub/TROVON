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
F_15 ( struct V_15 * V_20 , struct V_21 * * V_18 , unsigned int V_22 ,
unsigned int V_5 )
{
struct V_23 * V_24 = V_20 -> V_24 ;
T_2 * V_1 ;
V_20 -> V_18 = V_18 ;
V_20 -> V_19 = V_22 ;
V_20 -> V_25 = V_5 ;
V_1 = ( T_2 * ) V_20 -> V_26 [ 0 ] . V_27 + F_2 ( V_20 -> V_26 [ 0 ] . V_28 ) ;
V_24 -> V_27 = V_1 ;
V_24 -> V_28 = 0 ;
if ( V_5 & 3 ) {
unsigned int V_29 = 4 - ( V_5 & 3 ) ;
* V_1 = 0 ;
V_24 -> V_27 = ( char * ) V_1 + ( V_5 & 3 ) ;
V_24 -> V_28 = V_29 ;
V_5 += V_29 ;
}
V_20 -> V_30 += V_5 ;
V_20 -> V_5 += V_5 ;
}
void
F_16 ( struct V_15 * V_20 , unsigned int V_31 ,
struct V_21 * * V_18 , unsigned int V_22 , unsigned int V_5 )
{
struct V_23 * V_26 = V_20 -> V_26 ;
struct V_23 * V_24 = V_20 -> V_24 ;
char * V_16 = ( char * ) V_26 -> V_27 ;
unsigned int V_30 = V_26 -> V_28 ;
V_26 -> V_28 = V_31 ;
V_20 -> V_18 = V_18 ;
V_20 -> V_19 = V_22 ;
V_20 -> V_25 = V_5 ;
V_24 -> V_27 = V_16 + V_31 ;
V_24 -> V_28 = V_30 - V_31 ;
V_20 -> V_30 += V_5 ;
}
static void
F_17 ( struct V_21 * * V_18 , T_3 V_32 ,
T_3 V_33 , T_3 V_5 )
{
struct V_21 * * V_34 , * * V_35 ;
char * V_36 , * V_37 ;
T_3 V_38 ;
F_18 ( V_32 <= V_33 ) ;
V_32 += V_5 ;
V_33 += V_5 ;
V_35 = V_18 + ( V_32 >> V_39 ) ;
V_34 = V_18 + ( V_33 >> V_39 ) ;
V_32 &= ~ V_40 ;
V_33 &= ~ V_40 ;
do {
if ( V_32 == 0 ) {
V_32 = V_41 ;
V_35 -- ;
}
if ( V_33 == 0 ) {
V_33 = V_41 ;
V_34 -- ;
}
V_38 = V_5 ;
if ( V_38 > V_32 )
V_38 = V_32 ;
if ( V_38 > V_33 )
V_38 = V_33 ;
V_32 -= V_38 ;
V_33 -= V_38 ;
V_37 = F_13 ( * V_35 ) ;
V_36 = F_13 ( * V_34 ) ;
memmove ( V_37 + V_32 , V_36 + V_33 , V_38 ) ;
F_19 ( * V_35 ) ;
F_14 ( V_36 ) ;
F_14 ( V_37 ) ;
} while ( ( V_5 -= V_38 ) != 0 );
}
static void
F_20 ( struct V_21 * * V_18 , T_3 V_42 , const char * V_1 , T_3 V_5 )
{
struct V_21 * * V_35 ;
char * V_37 ;
T_3 V_38 ;
V_35 = V_18 + ( V_42 >> V_39 ) ;
V_42 &= ~ V_40 ;
for (; ; ) {
V_38 = V_41 - V_42 ;
if ( V_38 > V_5 )
V_38 = V_5 ;
V_37 = F_13 ( * V_35 ) ;
memcpy ( V_37 + V_42 , V_1 , V_38 ) ;
F_14 ( V_37 ) ;
V_5 -= V_38 ;
if ( V_5 == 0 )
break;
V_42 += V_38 ;
if ( V_42 == V_41 ) {
F_19 ( * V_35 ) ;
V_42 = 0 ;
V_35 ++ ;
}
V_1 += V_38 ;
}
F_19 ( * V_35 ) ;
}
void
F_21 ( char * V_1 , struct V_21 * * V_18 , T_3 V_42 , T_3 V_5 )
{
struct V_21 * * V_34 ;
char * V_36 ;
T_3 V_38 ;
V_34 = V_18 + ( V_42 >> V_39 ) ;
V_42 &= ~ V_40 ;
do {
V_38 = V_41 - V_42 ;
if ( V_38 > V_5 )
V_38 = V_5 ;
V_36 = F_13 ( * V_34 ) ;
memcpy ( V_1 , V_36 + V_42 , V_38 ) ;
F_14 ( V_36 ) ;
V_42 += V_38 ;
if ( V_42 == V_41 ) {
V_42 = 0 ;
V_34 ++ ;
}
V_1 += V_38 ;
} while ( ( V_5 -= V_38 ) != 0 );
}
static void
F_22 ( struct V_15 * V_16 , T_3 V_5 )
{
struct V_23 * V_26 , * V_24 ;
T_3 V_38 , V_43 ;
unsigned int V_44 = V_16 -> V_25 ;
V_24 = V_16 -> V_24 ;
V_26 = V_16 -> V_26 ;
F_18 ( V_5 > V_26 -> V_28 ) ;
if ( V_24 -> V_28 != 0 ) {
if ( V_24 -> V_28 > V_5 ) {
V_38 = V_24 -> V_28 - V_5 ;
memmove ( ( char * ) V_24 -> V_27 + V_5 ,
V_24 -> V_27 , V_38 ) ;
}
V_38 = V_5 ;
if ( V_38 > V_44 )
V_38 = V_44 ;
V_43 = V_5 - V_38 ;
if ( V_43 >= V_24 -> V_28 )
V_38 = 0 ;
else if ( V_38 > V_24 -> V_28 - V_43 )
V_38 = V_24 -> V_28 - V_43 ;
if ( V_38 != 0 )
F_21 ( ( char * ) V_24 -> V_27 + V_43 ,
V_16 -> V_18 ,
V_16 -> V_19 + V_44 + V_43 - V_5 ,
V_38 ) ;
if ( V_5 > V_44 ) {
V_43 = V_38 = V_5 - V_44 ;
if ( V_38 > V_24 -> V_28 )
V_38 = V_24 -> V_28 ;
memcpy ( V_24 -> V_27 ,
( char * ) V_26 -> V_27 +
V_26 -> V_28 - V_43 ,
V_38 ) ;
}
}
if ( V_44 != 0 ) {
if ( V_44 > V_5 )
F_17 ( V_16 -> V_18 ,
V_16 -> V_19 + V_5 ,
V_16 -> V_19 ,
V_44 - V_5 ) ;
V_38 = V_5 ;
if ( V_5 > V_44 )
V_38 = V_44 ;
F_20 ( V_16 -> V_18 , V_16 -> V_19 ,
( char * ) V_26 -> V_27 + V_26 -> V_28 - V_5 ,
V_38 ) ;
}
V_26 -> V_28 -= V_5 ;
V_16 -> V_30 -= V_5 ;
if ( V_16 -> V_5 > V_16 -> V_30 )
V_16 -> V_5 = V_16 -> V_30 ;
}
static void
F_23 ( struct V_15 * V_16 , T_3 V_5 )
{
struct V_23 * V_24 ;
T_3 V_38 ;
unsigned int V_44 = V_16 -> V_25 ;
unsigned int V_45 ;
V_24 = V_16 -> V_24 ;
F_18 ( V_5 > V_44 ) ;
V_45 = V_16 -> V_30 - V_16 -> V_26 -> V_28 - V_16 -> V_25 ;
if ( V_45 != 0 ) {
unsigned int V_46 = V_45 - V_24 -> V_28 ;
if ( V_5 < V_46 )
V_46 = V_5 ;
V_24 -> V_28 += V_46 ;
V_38 = V_5 ;
if ( V_24 -> V_28 > V_5 ) {
char * V_1 = ( char * ) V_24 -> V_27 + V_5 ;
memmove ( V_1 , V_24 -> V_27 , V_24 -> V_28 - V_5 ) ;
} else
V_38 = V_24 -> V_28 ;
F_21 ( ( char * ) V_24 -> V_27 ,
V_16 -> V_18 , V_16 -> V_19 + V_44 - V_5 ,
V_38 ) ;
}
V_16 -> V_25 -= V_5 ;
V_16 -> V_30 -= V_5 ;
if ( V_16 -> V_5 > V_16 -> V_30 )
V_16 -> V_5 = V_16 -> V_30 ;
}
void
F_24 ( struct V_15 * V_16 , T_3 V_5 )
{
F_22 ( V_16 , V_5 ) ;
}
void F_25 ( struct V_47 * V_20 , struct V_15 * V_16 , T_1 * V_1 )
{
struct V_23 * V_48 = V_16 -> V_26 ;
int V_49 = V_16 -> V_30 - V_16 -> V_25 - V_16 -> V_24 [ 0 ] . V_28 ;
F_18 ( V_49 < 0 ) ;
V_20 -> V_16 = V_16 ;
V_20 -> V_48 = V_48 ;
V_20 -> V_1 = ( T_1 * ) ( ( char * ) V_48 -> V_27 + V_48 -> V_28 ) ;
V_20 -> V_50 = ( T_1 * ) ( ( char * ) V_48 -> V_27 + V_49 ) ;
F_18 ( V_48 -> V_28 > V_49 ) ;
if ( V_1 != V_20 -> V_1 && V_1 != NULL ) {
T_3 V_5 ;
F_18 ( V_1 < V_20 -> V_1 || V_1 > V_20 -> V_50 ) ;
V_5 = ( char * ) V_1 - ( char * ) V_20 -> V_1 ;
V_20 -> V_1 = V_1 ;
V_16 -> V_5 += V_5 ;
V_48 -> V_28 += V_5 ;
}
}
T_1 * F_26 ( struct V_47 * V_20 , T_3 V_10 )
{
T_1 * V_1 = V_20 -> V_1 ;
T_1 * V_51 ;
V_10 += 3 ;
V_10 &= ~ 3 ;
V_51 = V_1 + ( V_10 >> 2 ) ;
if ( F_27 ( V_51 > V_20 -> V_50 || V_51 < V_1 ) )
return NULL ;
V_20 -> V_1 = V_51 ;
V_20 -> V_48 -> V_28 += V_10 ;
V_20 -> V_16 -> V_5 += V_10 ;
return V_1 ;
}
void F_28 ( struct V_47 * V_20 , struct V_21 * * V_18 , unsigned int V_22 ,
unsigned int V_5 )
{
struct V_15 * V_16 = V_20 -> V_16 ;
struct V_23 * V_48 = V_16 -> V_24 ;
V_16 -> V_18 = V_18 ;
V_16 -> V_19 = V_22 ;
V_16 -> V_25 = V_5 ;
V_48 -> V_27 = ( char * ) V_20 -> V_1 ;
V_48 -> V_28 = 0 ;
V_20 -> V_48 = V_48 ;
if ( V_5 & 3 ) {
unsigned int V_29 = 4 - ( V_5 & 3 ) ;
F_18 ( V_20 -> V_1 >= V_20 -> V_50 ) ;
V_48 -> V_27 = ( char * ) V_20 -> V_1 + ( V_5 & 3 ) ;
V_48 -> V_28 += V_29 ;
V_5 += V_29 ;
* V_20 -> V_1 ++ = 0 ;
}
V_16 -> V_30 += V_5 ;
V_16 -> V_5 += V_5 ;
}
static void F_29 ( struct V_47 * V_20 , struct V_23 * V_48 ,
T_1 * V_1 , unsigned int V_5 )
{
if ( V_5 > V_48 -> V_28 )
V_5 = V_48 -> V_28 ;
if ( V_1 == NULL )
V_1 = ( T_1 * ) V_48 -> V_27 ;
V_20 -> V_1 = V_1 ;
V_20 -> V_50 = ( T_1 * ) ( V_48 -> V_27 + V_5 ) ;
V_20 -> V_48 = V_48 ;
V_20 -> V_52 = NULL ;
}
static int F_30 ( struct V_47 * V_20 ,
unsigned int V_22 , unsigned int V_5 )
{
unsigned int V_53 ;
unsigned int V_14 ;
unsigned int V_54 ;
unsigned int V_55 ;
void * V_17 ;
V_14 = V_20 -> V_16 -> V_25 ;
if ( V_22 >= V_14 )
return - V_56 ;
V_14 -= V_22 ;
if ( V_5 > V_14 )
V_5 = V_14 ;
V_22 += V_20 -> V_16 -> V_19 ;
V_53 = V_22 >> V_57 ;
V_20 -> V_52 = & V_20 -> V_16 -> V_18 [ V_53 ] ;
V_17 = F_31 ( * V_20 -> V_52 ) ;
V_54 = V_22 & ~ V_58 ;
V_20 -> V_1 = ( T_1 * ) ( V_17 + V_54 ) ;
V_55 = V_54 + V_5 ;
if ( V_55 > V_59 )
V_55 = V_59 ;
V_20 -> V_50 = ( T_1 * ) ( V_17 + V_55 ) ;
V_20 -> V_48 = NULL ;
return 0 ;
}
static void F_32 ( struct V_47 * V_20 )
{
unsigned int V_60 ;
V_60 = ( 1 + V_20 -> V_52 - V_20 -> V_16 -> V_18 ) << V_57 ;
V_60 -= V_20 -> V_16 -> V_19 ;
if ( F_30 ( V_20 , V_60 , V_59 ) < 0 )
F_29 ( V_20 , V_20 -> V_16 -> V_24 , NULL , V_20 -> V_16 -> V_5 ) ;
}
static bool F_33 ( struct V_47 * V_20 )
{
if ( V_20 -> V_52 != NULL )
F_32 ( V_20 ) ;
else if ( V_20 -> V_48 == V_20 -> V_16 -> V_26 ) {
if ( F_30 ( V_20 , 0 , V_59 ) < 0 )
F_29 ( V_20 , V_20 -> V_16 -> V_24 , NULL , V_20 -> V_16 -> V_5 ) ;
}
return V_20 -> V_1 != V_20 -> V_50 ;
}
void F_34 ( struct V_47 * V_20 , struct V_15 * V_16 , T_1 * V_1 )
{
V_20 -> V_16 = V_16 ;
V_20 -> V_61 . V_27 = NULL ;
V_20 -> V_61 . V_28 = 0 ;
if ( V_16 -> V_26 [ 0 ] . V_28 != 0 )
F_29 ( V_20 , V_16 -> V_26 , V_1 , V_16 -> V_5 ) ;
else if ( V_16 -> V_25 != 0 )
F_30 ( V_20 , 0 , V_16 -> V_5 ) ;
}
void F_35 ( struct V_47 * V_20 , struct V_15 * V_16 ,
struct V_21 * * V_18 , unsigned int V_5 )
{
memset ( V_16 , 0 , sizeof( * V_16 ) ) ;
V_16 -> V_18 = V_18 ;
V_16 -> V_25 = V_5 ;
V_16 -> V_30 = V_5 ;
V_16 -> V_5 = V_5 ;
F_34 ( V_20 , V_16 , NULL ) ;
}
static T_1 * F_36 ( struct V_47 * V_20 , T_3 V_10 )
{
T_1 * V_1 = V_20 -> V_1 ;
T_1 * V_51 = V_1 + F_2 ( V_10 ) ;
if ( F_27 ( V_51 > V_20 -> V_50 || V_51 < V_1 ) )
return NULL ;
V_20 -> V_1 = V_51 ;
return V_1 ;
}
void F_37 ( struct V_47 * V_20 , void * V_16 , T_3 V_30 )
{
V_20 -> V_61 . V_27 = V_16 ;
V_20 -> V_61 . V_28 = V_30 ;
}
static T_1 * F_38 ( struct V_47 * V_20 , T_3 V_10 )
{
T_1 * V_1 ;
void * V_62 = V_20 -> V_61 . V_27 ;
T_3 V_63 = ( char * ) V_20 -> V_50 - ( char * ) V_20 -> V_1 ;
if ( V_10 > V_20 -> V_61 . V_28 )
return NULL ;
memcpy ( V_62 , V_20 -> V_1 , V_63 ) ;
V_62 += V_63 ;
V_10 -= V_63 ;
if ( ! F_33 ( V_20 ) )
return NULL ;
V_1 = F_36 ( V_20 , V_10 ) ;
if ( V_1 == NULL )
return NULL ;
memcpy ( V_62 , V_1 , V_10 ) ;
return V_20 -> V_61 . V_27 ;
}
T_1 * F_39 ( struct V_47 * V_20 , T_3 V_10 )
{
T_1 * V_1 ;
if ( V_10 == 0 )
return V_20 -> V_1 ;
if ( V_20 -> V_1 == V_20 -> V_50 && ! F_33 ( V_20 ) )
return NULL ;
V_1 = F_36 ( V_20 , V_10 ) ;
if ( V_1 != NULL )
return V_1 ;
return F_38 ( V_20 , V_10 ) ;
}
void F_40 ( struct V_47 * V_20 , unsigned int V_5 )
{
struct V_15 * V_16 = V_20 -> V_16 ;
struct V_23 * V_48 ;
T_4 V_64 ;
unsigned int V_50 ;
int V_11 ;
V_48 = V_16 -> V_26 ;
V_64 = V_48 -> V_28 + ( char * ) V_48 -> V_27 - ( char * ) V_20 -> V_1 ;
if ( V_64 > 0 )
F_22 ( V_16 , V_64 ) ;
if ( V_16 -> V_25 > V_5 )
F_23 ( V_16 , V_16 -> V_25 - V_5 ) ;
V_11 = ( F_2 ( V_5 ) << 2 ) - V_5 ;
V_20 -> V_48 = V_48 = V_16 -> V_24 ;
V_50 = V_48 -> V_28 ;
V_64 = V_16 -> V_30 - V_16 -> V_5 ;
if ( V_64 < V_50 )
V_50 -= V_64 ;
else if ( V_64 > 0 )
V_50 = 0 ;
V_20 -> V_1 = ( T_1 * ) ( ( char * ) V_48 -> V_27 + V_11 ) ;
V_20 -> V_50 = ( T_1 * ) ( ( char * ) V_48 -> V_27 + V_50 ) ;
}
void F_41 ( struct V_47 * V_20 , unsigned int V_5 )
{
F_40 ( V_20 , V_5 ) ;
F_30 ( V_20 , 0 , V_5 ) ;
}
void
F_42 ( struct V_23 * V_48 , struct V_15 * V_16 )
{
V_16 -> V_26 [ 0 ] = * V_48 ;
V_16 -> V_24 [ 0 ] = V_65 ;
V_16 -> V_25 = 0 ;
V_16 -> V_30 = V_16 -> V_5 = V_48 -> V_28 ;
}
int
F_43 ( struct V_15 * V_16 , struct V_15 * V_66 ,
unsigned int V_22 , unsigned int V_5 )
{
V_66 -> V_30 = V_66 -> V_5 = V_5 ;
if ( V_22 < V_16 -> V_26 [ 0 ] . V_28 ) {
V_66 -> V_26 [ 0 ] . V_27 = V_16 -> V_26 [ 0 ] . V_27 + V_22 ;
V_66 -> V_26 [ 0 ] . V_28 = F_44 (unsigned int, len,
buf->head[0].iov_len - base) ;
V_5 -= V_66 -> V_26 [ 0 ] . V_28 ;
V_22 = 0 ;
} else {
V_66 -> V_26 [ 0 ] . V_27 = NULL ;
V_66 -> V_26 [ 0 ] . V_28 = 0 ;
V_22 -= V_16 -> V_26 [ 0 ] . V_28 ;
}
if ( V_22 < V_16 -> V_25 ) {
V_66 -> V_25 = F_45 ( V_16 -> V_25 - V_22 , V_5 ) ;
V_22 += V_16 -> V_19 ;
V_66 -> V_19 = V_22 & ~ V_40 ;
V_66 -> V_18 = & V_16 -> V_18 [ V_22 >> V_39 ] ;
V_5 -= V_66 -> V_25 ;
V_22 = 0 ;
} else {
V_22 -= V_16 -> V_25 ;
V_66 -> V_25 = 0 ;
}
if ( V_22 < V_16 -> V_24 [ 0 ] . V_28 ) {
V_66 -> V_24 [ 0 ] . V_27 = V_16 -> V_24 [ 0 ] . V_27 + V_22 ;
V_66 -> V_24 [ 0 ] . V_28 = F_44 (unsigned int, len,
buf->tail[0].iov_len - base) ;
V_5 -= V_66 -> V_24 [ 0 ] . V_28 ;
V_22 = 0 ;
} else {
V_66 -> V_24 [ 0 ] . V_27 = NULL ;
V_66 -> V_24 [ 0 ] . V_28 = 0 ;
V_22 -= V_16 -> V_24 [ 0 ] . V_28 ;
}
if ( V_22 || V_5 )
return - 1 ;
return 0 ;
}
static void F_46 ( struct V_15 * V_66 , void * V_3 , unsigned int V_5 )
{
unsigned int V_67 ;
V_67 = F_44 (unsigned int, len, subbuf->head[0].iov_len) ;
memcpy ( V_3 , V_66 -> V_26 [ 0 ] . V_27 , V_67 ) ;
V_5 -= V_67 ;
V_3 += V_67 ;
V_67 = F_44 (unsigned int, len, subbuf->page_len) ;
if ( V_67 )
F_21 ( V_3 , V_66 -> V_18 , V_66 -> V_19 , V_67 ) ;
V_5 -= V_67 ;
V_3 += V_67 ;
V_67 = F_44 (unsigned int, len, subbuf->tail[0].iov_len) ;
memcpy ( V_3 , V_66 -> V_24 [ 0 ] . V_27 , V_67 ) ;
}
int F_47 ( struct V_15 * V_16 , unsigned int V_22 , void * V_3 , unsigned int V_5 )
{
struct V_15 V_66 ;
int V_68 ;
V_68 = F_43 ( V_16 , & V_66 , V_22 , V_5 ) ;
if ( V_68 != 0 )
return V_68 ;
F_46 ( & V_66 , V_3 , V_5 ) ;
return 0 ;
}
static void F_48 ( struct V_15 * V_66 , void * V_3 , unsigned int V_5 )
{
unsigned int V_67 ;
V_67 = F_44 (unsigned int, len, subbuf->head[0].iov_len) ;
memcpy ( V_66 -> V_26 [ 0 ] . V_27 , V_3 , V_67 ) ;
V_5 -= V_67 ;
V_3 += V_67 ;
V_67 = F_44 (unsigned int, len, subbuf->page_len) ;
if ( V_67 )
F_20 ( V_66 -> V_18 , V_66 -> V_19 , V_3 , V_67 ) ;
V_5 -= V_67 ;
V_3 += V_67 ;
V_67 = F_44 (unsigned int, len, subbuf->tail[0].iov_len) ;
memcpy ( V_66 -> V_24 [ 0 ] . V_27 , V_3 , V_67 ) ;
}
int F_49 ( struct V_15 * V_16 , unsigned int V_22 , void * V_3 , unsigned int V_5 )
{
struct V_15 V_66 ;
int V_68 ;
V_68 = F_43 ( V_16 , & V_66 , V_22 , V_5 ) ;
if ( V_68 != 0 )
return V_68 ;
F_48 ( & V_66 , V_3 , V_5 ) ;
return 0 ;
}
int
F_50 ( struct V_15 * V_16 , unsigned int V_22 , T_2 * V_3 )
{
T_1 V_69 ;
int V_68 ;
V_68 = F_47 ( V_16 , V_22 , & V_69 , sizeof( * V_3 ) ) ;
if ( V_68 )
return V_68 ;
* V_3 = F_5 ( V_69 ) ;
return 0 ;
}
int
F_51 ( struct V_15 * V_16 , unsigned int V_22 , T_2 V_3 )
{
T_1 V_69 = F_3 ( V_3 ) ;
return F_49 ( V_16 , V_22 , & V_69 , sizeof( V_3 ) ) ;
}
int F_52 ( struct V_15 * V_16 , struct V_2 * V_3 , unsigned int V_31 )
{
struct V_15 V_66 ;
if ( F_50 ( V_16 , V_31 , & V_3 -> V_5 ) )
return - V_70 ;
if ( F_43 ( V_16 , & V_66 , V_31 + 4 , V_3 -> V_5 ) )
return - V_70 ;
V_3 -> V_6 = V_66 . V_26 [ 0 ] . V_27 ;
if ( V_66 . V_26 [ 0 ] . V_28 == V_3 -> V_5 )
return 0 ;
V_3 -> V_6 = V_66 . V_24 [ 0 ] . V_27 ;
if ( V_66 . V_24 [ 0 ] . V_28 == V_3 -> V_5 )
return 0 ;
if ( V_3 -> V_5 > V_16 -> V_30 - V_16 -> V_5 )
return - V_71 ;
if ( V_16 -> V_24 [ 0 ] . V_28 != 0 )
V_3 -> V_6 = V_16 -> V_24 [ 0 ] . V_27 + V_16 -> V_24 [ 0 ] . V_28 ;
else
V_3 -> V_6 = V_16 -> V_26 [ 0 ] . V_27 + V_16 -> V_26 [ 0 ] . V_28 ;
F_46 ( & V_66 , V_3 -> V_6 , V_3 -> V_5 ) ;
return 0 ;
}
static int
F_53 ( struct V_15 * V_16 , unsigned int V_22 ,
struct V_72 * V_73 , int V_74 )
{
char * V_75 = NULL , * V_76 ;
unsigned int V_77 = 0 , V_78 , V_79 ;
struct V_21 * * V_80 = NULL ;
int V_81 ;
if ( V_74 ) {
if ( F_51 ( V_16 , V_22 , V_73 -> V_82 ) != 0 )
return - V_56 ;
} else {
if ( F_50 ( V_16 , V_22 , & V_73 -> V_82 ) != 0 ||
V_73 -> V_82 > V_73 -> V_83 ||
( unsigned long ) V_22 + 4 + V_73 -> V_82 *
V_73 -> V_84 > V_16 -> V_5 )
return - V_56 ;
}
V_22 += 4 ;
if ( ! V_73 -> V_85 )
return 0 ;
V_78 = V_73 -> V_82 * V_73 -> V_84 ;
if ( V_78 && V_22 < V_16 -> V_26 -> V_28 ) {
V_76 = V_16 -> V_26 -> V_27 + V_22 ;
V_79 = F_44 (unsigned int, todo,
buf->head->iov_len - base) ;
V_78 -= V_79 ;
while ( V_79 >= V_73 -> V_84 ) {
V_81 = V_73 -> V_85 ( V_73 , V_76 ) ;
if ( V_81 )
goto V_86;
V_76 += V_73 -> V_84 ;
V_79 -= V_73 -> V_84 ;
}
if ( V_79 ) {
if ( ! V_75 ) {
V_75 = F_54 ( V_73 -> V_84 , V_87 ) ;
V_81 = - V_71 ;
if ( ! V_75 )
goto V_86;
}
if ( V_74 ) {
V_81 = V_73 -> V_85 ( V_73 , V_75 ) ;
if ( V_81 )
goto V_86;
memcpy ( V_76 , V_75 , V_79 ) ;
} else
memcpy ( V_75 , V_76 , V_79 ) ;
V_77 = V_79 ;
}
V_22 = V_16 -> V_26 -> V_28 ;
}
V_22 -= V_16 -> V_26 -> V_28 ;
if ( V_78 && V_22 < V_16 -> V_25 ) {
unsigned int V_88 ;
V_79 = F_45 ( V_78 , V_16 -> V_25 - V_22 ) ;
V_78 -= V_79 ;
V_22 += V_16 -> V_19 ;
V_80 = V_16 -> V_18 + ( V_22 >> V_39 ) ;
V_22 &= ~ V_40 ;
V_88 = F_44 (unsigned int, PAGE_CACHE_SIZE - base,
avail_here) ;
V_76 = F_55 ( * V_80 ) + V_22 ;
while ( V_79 ) {
V_79 -= V_88 ;
if ( V_77 || V_88 < V_73 -> V_84 ) {
unsigned int V_89 = F_45 ( V_88 ,
V_73 -> V_84 - V_77 ) ;
if ( ! V_75 ) {
V_75 = F_54 ( V_73 -> V_84 ,
V_87 ) ;
V_81 = - V_71 ;
if ( ! V_75 )
goto V_86;
}
if ( V_74 ) {
if ( ! V_77 ) {
V_81 = V_73 -> V_85 ( V_73 , V_75 ) ;
if ( V_81 )
goto V_86;
}
memcpy ( V_76 , V_75 + V_77 , V_89 ) ;
V_77 += V_89 ;
if ( V_77 == V_73 -> V_84 )
V_77 = 0 ;
} else {
memcpy ( V_75 + V_77 , V_76 , V_89 ) ;
V_77 += V_89 ;
if ( V_77 == V_73 -> V_84 ) {
V_81 = V_73 -> V_85 ( V_73 , V_75 ) ;
if ( V_81 )
goto V_86;
V_77 = 0 ;
}
}
V_88 -= V_89 ;
V_76 += V_89 ;
}
while ( V_88 >= V_73 -> V_84 ) {
V_81 = V_73 -> V_85 ( V_73 , V_76 ) ;
if ( V_81 )
goto V_86;
V_76 += V_73 -> V_84 ;
V_88 -= V_73 -> V_84 ;
}
if ( V_88 ) {
unsigned int V_89 = F_45 ( V_88 ,
V_73 -> V_84 - V_77 ) ;
if ( ! V_75 ) {
V_75 = F_54 ( V_73 -> V_84 ,
V_87 ) ;
V_81 = - V_71 ;
if ( ! V_75 )
goto V_86;
}
if ( V_74 ) {
if ( ! V_77 ) {
V_81 = V_73 -> V_85 ( V_73 , V_75 ) ;
if ( V_81 )
goto V_86;
}
memcpy ( V_76 , V_75 + V_77 , V_89 ) ;
V_77 += V_89 ;
if ( V_77 == V_73 -> V_84 )
V_77 = 0 ;
} else {
memcpy ( V_75 + V_77 , V_76 , V_89 ) ;
V_77 += V_89 ;
if ( V_77 == V_73 -> V_84 ) {
V_81 = V_73 -> V_85 ( V_73 , V_75 ) ;
if ( V_81 )
goto V_86;
V_77 = 0 ;
}
}
}
if ( V_79 ) {
F_56 ( * V_80 ) ;
V_80 ++ ;
V_76 = F_55 ( * V_80 ) ;
}
V_88 = F_45 ( V_79 ,
( unsigned int ) V_41 ) ;
}
V_22 = V_16 -> V_25 ;
}
V_22 -= V_16 -> V_25 ;
if ( V_78 ) {
V_76 = V_16 -> V_24 -> V_27 + V_22 ;
if ( V_77 ) {
unsigned int V_89 = V_73 -> V_84 - V_77 ;
if ( V_74 )
memcpy ( V_76 , V_75 + V_77 , V_89 ) ;
else {
memcpy ( V_75 + V_77 , V_76 , V_89 ) ;
V_81 = V_73 -> V_85 ( V_73 , V_75 ) ;
if ( V_81 )
goto V_86;
}
V_78 -= V_89 ;
V_76 += V_89 ;
}
while ( V_78 ) {
V_81 = V_73 -> V_85 ( V_73 , V_76 ) ;
if ( V_81 )
goto V_86;
V_76 += V_73 -> V_84 ;
V_78 -= V_73 -> V_84 ;
}
}
V_81 = 0 ;
V_86:
F_57 ( V_75 ) ;
if ( V_80 )
F_56 ( * V_80 ) ;
return V_81 ;
}
int
F_58 ( struct V_15 * V_16 , unsigned int V_22 ,
struct V_72 * V_73 )
{
if ( V_22 >= V_16 -> V_5 )
return - V_56 ;
return F_53 ( V_16 , V_22 , V_73 , 0 ) ;
}
int
F_59 ( struct V_15 * V_16 , unsigned int V_22 ,
struct V_72 * V_73 )
{
if ( ( unsigned long ) V_22 + 4 + V_73 -> V_82 * V_73 -> V_84 >
V_16 -> V_26 -> V_28 + V_16 -> V_25 + V_16 -> V_24 -> V_28 )
return - V_56 ;
return F_53 ( V_16 , V_22 , V_73 , 1 ) ;
}
int
F_60 ( struct V_15 * V_16 , unsigned int V_31 , unsigned int V_5 ,
int (* F_61)( struct V_90 * , void * ) , void * V_6 )
{
int V_91 , V_92 = 0 ;
unsigned int V_25 , V_93 , V_94 ;
struct V_90 V_95 [ 1 ] ;
F_62 ( V_95 , 1 ) ;
if ( V_31 >= V_16 -> V_26 [ 0 ] . V_28 ) {
V_31 -= V_16 -> V_26 [ 0 ] . V_28 ;
} else {
V_93 = V_16 -> V_26 [ 0 ] . V_28 - V_31 ;
if ( V_93 > V_5 )
V_93 = V_5 ;
F_63 ( V_95 , V_16 -> V_26 [ 0 ] . V_27 + V_31 , V_93 ) ;
V_92 = F_61 ( V_95 , V_6 ) ;
if ( V_92 )
goto V_86;
V_31 = 0 ;
V_5 -= V_93 ;
}
if ( V_5 == 0 )
goto V_86;
if ( V_31 >= V_16 -> V_25 ) {
V_31 -= V_16 -> V_25 ;
} else {
V_25 = V_16 -> V_25 - V_31 ;
if ( V_25 > V_5 )
V_25 = V_5 ;
V_5 -= V_25 ;
V_94 = ( V_31 + V_16 -> V_19 ) & ( V_41 - 1 ) ;
V_91 = ( V_31 + V_16 -> V_19 ) >> V_39 ;
V_93 = V_41 - V_94 ;
do {
if ( V_93 > V_25 )
V_93 = V_25 ;
F_64 ( V_95 , V_16 -> V_18 [ V_91 ] , V_93 , V_94 ) ;
V_92 = F_61 ( V_95 , V_6 ) ;
if ( V_92 )
goto V_86;
V_25 -= V_93 ;
V_91 ++ ;
V_94 = 0 ;
V_93 = V_41 ;
} while ( V_25 != 0 );
V_31 = 0 ;
}
if ( V_5 == 0 )
goto V_86;
if ( V_31 < V_16 -> V_24 [ 0 ] . V_28 ) {
V_93 = V_16 -> V_24 [ 0 ] . V_28 - V_31 ;
if ( V_93 > V_5 )
V_93 = V_5 ;
F_63 ( V_95 , V_16 -> V_24 [ 0 ] . V_27 + V_31 , V_93 ) ;
V_92 = F_61 ( V_95 , V_6 ) ;
V_5 -= V_93 ;
}
if ( V_5 != 0 )
V_92 = - V_56 ;
V_86:
return V_92 ;
}
