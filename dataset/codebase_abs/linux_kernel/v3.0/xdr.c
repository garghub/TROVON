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
V_17 = F_13 ( V_16 -> V_18 [ 0 ] , V_19 ) ;
V_17 [ V_16 -> V_20 + V_5 ] = '\0' ;
F_14 ( V_17 , V_19 ) ;
}
void
F_15 ( struct V_15 * V_21 , struct V_22 * * V_18 , unsigned int V_23 ,
unsigned int V_5 )
{
struct V_24 * V_25 = V_21 -> V_25 ;
T_2 * V_1 ;
V_21 -> V_18 = V_18 ;
V_21 -> V_20 = V_23 ;
V_21 -> V_26 = V_5 ;
V_1 = ( T_2 * ) V_21 -> V_27 [ 0 ] . V_28 + F_2 ( V_21 -> V_27 [ 0 ] . V_29 ) ;
V_25 -> V_28 = V_1 ;
V_25 -> V_29 = 0 ;
if ( V_5 & 3 ) {
unsigned int V_30 = 4 - ( V_5 & 3 ) ;
* V_1 = 0 ;
V_25 -> V_28 = ( char * ) V_1 + ( V_5 & 3 ) ;
V_25 -> V_29 = V_30 ;
V_5 += V_30 ;
}
V_21 -> V_31 += V_5 ;
V_21 -> V_5 += V_5 ;
}
void
F_16 ( struct V_15 * V_21 , unsigned int V_32 ,
struct V_22 * * V_18 , unsigned int V_23 , unsigned int V_5 )
{
struct V_24 * V_27 = V_21 -> V_27 ;
struct V_24 * V_25 = V_21 -> V_25 ;
char * V_16 = ( char * ) V_27 -> V_28 ;
unsigned int V_31 = V_27 -> V_29 ;
V_27 -> V_29 = V_32 ;
V_21 -> V_18 = V_18 ;
V_21 -> V_20 = V_23 ;
V_21 -> V_26 = V_5 ;
V_25 -> V_28 = V_16 + V_32 ;
V_25 -> V_29 = V_31 - V_32 ;
V_21 -> V_31 += V_5 ;
}
static void
F_17 ( struct V_22 * * V_18 , T_3 V_33 ,
T_3 V_34 , T_3 V_5 )
{
struct V_22 * * V_35 , * * V_36 ;
char * V_37 , * V_38 ;
T_3 V_39 ;
F_18 ( V_33 <= V_34 ) ;
V_33 += V_5 ;
V_34 += V_5 ;
V_36 = V_18 + ( V_33 >> V_40 ) ;
V_35 = V_18 + ( V_34 >> V_40 ) ;
V_33 &= ~ V_41 ;
V_34 &= ~ V_41 ;
do {
if ( V_33 == 0 ) {
V_33 = V_42 ;
V_36 -- ;
}
if ( V_34 == 0 ) {
V_34 = V_42 ;
V_35 -- ;
}
V_39 = V_5 ;
if ( V_39 > V_33 )
V_39 = V_33 ;
if ( V_39 > V_34 )
V_39 = V_34 ;
V_33 -= V_39 ;
V_34 -= V_39 ;
V_38 = F_13 ( * V_36 , V_19 ) ;
V_37 = F_13 ( * V_35 , V_43 ) ;
memmove ( V_38 + V_33 , V_37 + V_34 , V_39 ) ;
F_19 ( * V_36 ) ;
F_14 ( V_37 , V_43 ) ;
F_14 ( V_38 , V_19 ) ;
} while ( ( V_5 -= V_39 ) != 0 );
}
static void
F_20 ( struct V_22 * * V_18 , T_3 V_44 , const char * V_1 , T_3 V_5 )
{
struct V_22 * * V_36 ;
char * V_38 ;
T_3 V_39 ;
V_36 = V_18 + ( V_44 >> V_40 ) ;
V_44 &= ~ V_41 ;
for (; ; ) {
V_39 = V_42 - V_44 ;
if ( V_39 > V_5 )
V_39 = V_5 ;
V_38 = F_13 ( * V_36 , V_19 ) ;
memcpy ( V_38 + V_44 , V_1 , V_39 ) ;
F_14 ( V_38 , V_19 ) ;
V_5 -= V_39 ;
if ( V_5 == 0 )
break;
V_44 += V_39 ;
if ( V_44 == V_42 ) {
F_19 ( * V_36 ) ;
V_44 = 0 ;
V_36 ++ ;
}
V_1 += V_39 ;
}
F_19 ( * V_36 ) ;
}
static void
F_21 ( char * V_1 , struct V_22 * * V_18 , T_3 V_44 , T_3 V_5 )
{
struct V_22 * * V_35 ;
char * V_37 ;
T_3 V_39 ;
V_35 = V_18 + ( V_44 >> V_40 ) ;
V_44 &= ~ V_41 ;
do {
V_39 = V_42 - V_44 ;
if ( V_39 > V_5 )
V_39 = V_5 ;
V_37 = F_13 ( * V_35 , V_19 ) ;
memcpy ( V_1 , V_37 + V_44 , V_39 ) ;
F_14 ( V_37 , V_19 ) ;
V_44 += V_39 ;
if ( V_44 == V_42 ) {
V_44 = 0 ;
V_35 ++ ;
}
V_1 += V_39 ;
} while ( ( V_5 -= V_39 ) != 0 );
}
static void
F_22 ( struct V_15 * V_16 , T_3 V_5 )
{
struct V_24 * V_27 , * V_25 ;
T_3 V_39 , V_45 ;
unsigned int V_46 = V_16 -> V_26 ;
V_25 = V_16 -> V_25 ;
V_27 = V_16 -> V_27 ;
F_18 ( V_5 > V_27 -> V_29 ) ;
if ( V_25 -> V_29 != 0 ) {
if ( V_25 -> V_29 > V_5 ) {
V_39 = V_25 -> V_29 - V_5 ;
memmove ( ( char * ) V_25 -> V_28 + V_5 ,
V_25 -> V_28 , V_39 ) ;
}
V_39 = V_5 ;
if ( V_39 > V_46 )
V_39 = V_46 ;
V_45 = V_5 - V_39 ;
if ( V_45 >= V_25 -> V_29 )
V_39 = 0 ;
else if ( V_39 > V_25 -> V_29 - V_45 )
V_39 = V_25 -> V_29 - V_45 ;
if ( V_39 != 0 )
F_21 ( ( char * ) V_25 -> V_28 + V_45 ,
V_16 -> V_18 ,
V_16 -> V_20 + V_46 + V_45 - V_5 ,
V_39 ) ;
if ( V_5 > V_46 ) {
V_45 = V_39 = V_5 - V_46 ;
if ( V_39 > V_25 -> V_29 )
V_39 = V_25 -> V_29 ;
memcpy ( V_25 -> V_28 ,
( char * ) V_27 -> V_28 +
V_27 -> V_29 - V_45 ,
V_39 ) ;
}
}
if ( V_46 != 0 ) {
if ( V_46 > V_5 )
F_17 ( V_16 -> V_18 ,
V_16 -> V_20 + V_5 ,
V_16 -> V_20 ,
V_46 - V_5 ) ;
V_39 = V_5 ;
if ( V_5 > V_46 )
V_39 = V_46 ;
F_20 ( V_16 -> V_18 , V_16 -> V_20 ,
( char * ) V_27 -> V_28 + V_27 -> V_29 - V_5 ,
V_39 ) ;
}
V_27 -> V_29 -= V_5 ;
V_16 -> V_31 -= V_5 ;
if ( V_16 -> V_5 > V_16 -> V_31 )
V_16 -> V_5 = V_16 -> V_31 ;
}
static void
F_23 ( struct V_15 * V_16 , T_3 V_5 )
{
struct V_24 * V_25 ;
T_3 V_39 ;
unsigned int V_46 = V_16 -> V_26 ;
unsigned int V_47 ;
V_25 = V_16 -> V_25 ;
F_18 ( V_5 > V_46 ) ;
V_47 = V_16 -> V_31 - V_16 -> V_27 -> V_29 - V_16 -> V_26 ;
if ( V_47 != 0 ) {
unsigned int V_48 = V_47 - V_25 -> V_29 ;
if ( V_5 < V_48 )
V_48 = V_5 ;
V_25 -> V_29 += V_48 ;
V_39 = V_5 ;
if ( V_25 -> V_29 > V_5 ) {
char * V_1 = ( char * ) V_25 -> V_28 + V_5 ;
memmove ( V_1 , V_25 -> V_28 , V_25 -> V_29 - V_5 ) ;
} else
V_39 = V_25 -> V_29 ;
F_21 ( ( char * ) V_25 -> V_28 ,
V_16 -> V_18 , V_16 -> V_20 + V_46 - V_5 ,
V_39 ) ;
}
V_16 -> V_26 -= V_5 ;
V_16 -> V_31 -= V_5 ;
if ( V_16 -> V_5 > V_16 -> V_31 )
V_16 -> V_5 = V_16 -> V_31 ;
}
void
F_24 ( struct V_15 * V_16 , T_3 V_5 )
{
F_22 ( V_16 , V_5 ) ;
}
void F_25 ( struct V_49 * V_21 , struct V_15 * V_16 , T_1 * V_1 )
{
struct V_24 * V_50 = V_16 -> V_27 ;
int V_51 = V_16 -> V_31 - V_16 -> V_26 - V_16 -> V_25 [ 0 ] . V_29 ;
F_18 ( V_51 < 0 ) ;
V_21 -> V_16 = V_16 ;
V_21 -> V_50 = V_50 ;
V_21 -> V_1 = ( T_1 * ) ( ( char * ) V_50 -> V_28 + V_50 -> V_29 ) ;
V_21 -> V_52 = ( T_1 * ) ( ( char * ) V_50 -> V_28 + V_51 ) ;
F_18 ( V_50 -> V_29 > V_51 ) ;
if ( V_1 != V_21 -> V_1 && V_1 != NULL ) {
T_3 V_5 ;
F_18 ( V_1 < V_21 -> V_1 || V_1 > V_21 -> V_52 ) ;
V_5 = ( char * ) V_1 - ( char * ) V_21 -> V_1 ;
V_21 -> V_1 = V_1 ;
V_16 -> V_5 += V_5 ;
V_50 -> V_29 += V_5 ;
}
}
T_1 * F_26 ( struct V_49 * V_21 , T_3 V_10 )
{
T_1 * V_1 = V_21 -> V_1 ;
T_1 * V_53 ;
V_10 += 3 ;
V_10 &= ~ 3 ;
V_53 = V_1 + ( V_10 >> 2 ) ;
if ( F_27 ( V_53 > V_21 -> V_52 || V_53 < V_1 ) )
return NULL ;
V_21 -> V_1 = V_53 ;
V_21 -> V_50 -> V_29 += V_10 ;
V_21 -> V_16 -> V_5 += V_10 ;
return V_1 ;
}
void F_28 ( struct V_49 * V_21 , struct V_22 * * V_18 , unsigned int V_23 ,
unsigned int V_5 )
{
struct V_15 * V_16 = V_21 -> V_16 ;
struct V_24 * V_50 = V_16 -> V_25 ;
V_16 -> V_18 = V_18 ;
V_16 -> V_20 = V_23 ;
V_16 -> V_26 = V_5 ;
V_50 -> V_28 = ( char * ) V_21 -> V_1 ;
V_50 -> V_29 = 0 ;
V_21 -> V_50 = V_50 ;
if ( V_5 & 3 ) {
unsigned int V_30 = 4 - ( V_5 & 3 ) ;
F_18 ( V_21 -> V_1 >= V_21 -> V_52 ) ;
V_50 -> V_28 = ( char * ) V_21 -> V_1 + ( V_5 & 3 ) ;
V_50 -> V_29 += V_30 ;
V_5 += V_30 ;
* V_21 -> V_1 ++ = 0 ;
}
V_16 -> V_31 += V_5 ;
V_16 -> V_5 += V_5 ;
}
static void F_29 ( struct V_49 * V_21 , struct V_24 * V_50 ,
T_1 * V_1 , unsigned int V_5 )
{
if ( V_5 > V_50 -> V_29 )
V_5 = V_50 -> V_29 ;
if ( V_1 == NULL )
V_1 = ( T_1 * ) V_50 -> V_28 ;
V_21 -> V_1 = V_1 ;
V_21 -> V_52 = ( T_1 * ) ( V_50 -> V_28 + V_5 ) ;
V_21 -> V_50 = V_50 ;
V_21 -> V_54 = NULL ;
}
static int F_30 ( struct V_49 * V_21 ,
unsigned int V_23 , unsigned int V_5 )
{
unsigned int V_55 ;
unsigned int V_14 ;
unsigned int V_56 ;
unsigned int V_57 ;
void * V_17 ;
V_14 = V_21 -> V_16 -> V_26 ;
if ( V_23 >= V_14 )
return - V_58 ;
V_14 -= V_23 ;
if ( V_5 > V_14 )
V_5 = V_14 ;
V_23 += V_21 -> V_16 -> V_20 ;
V_55 = V_23 >> V_59 ;
V_21 -> V_54 = & V_21 -> V_16 -> V_18 [ V_55 ] ;
V_17 = F_31 ( * V_21 -> V_54 ) ;
V_56 = V_23 & ~ V_60 ;
V_21 -> V_1 = ( T_1 * ) ( V_17 + V_56 ) ;
V_57 = V_56 + V_5 ;
if ( V_57 > V_61 )
V_57 = V_61 ;
V_21 -> V_52 = ( T_1 * ) ( V_17 + V_57 ) ;
V_21 -> V_50 = NULL ;
return 0 ;
}
static void F_32 ( struct V_49 * V_21 )
{
unsigned int V_62 ;
V_62 = ( 1 + V_21 -> V_54 - V_21 -> V_16 -> V_18 ) << V_59 ;
V_62 -= V_21 -> V_16 -> V_20 ;
if ( F_30 ( V_21 , V_62 , V_61 ) < 0 )
F_29 ( V_21 , V_21 -> V_16 -> V_25 , NULL , V_21 -> V_16 -> V_5 ) ;
}
static bool F_33 ( struct V_49 * V_21 )
{
if ( V_21 -> V_54 != NULL )
F_32 ( V_21 ) ;
else if ( V_21 -> V_50 == V_21 -> V_16 -> V_27 ) {
if ( F_30 ( V_21 , 0 , V_61 ) < 0 )
F_29 ( V_21 , V_21 -> V_16 -> V_25 , NULL , V_21 -> V_16 -> V_5 ) ;
}
return V_21 -> V_1 != V_21 -> V_52 ;
}
void F_34 ( struct V_49 * V_21 , struct V_15 * V_16 , T_1 * V_1 )
{
V_21 -> V_16 = V_16 ;
V_21 -> V_63 . V_28 = NULL ;
V_21 -> V_63 . V_29 = 0 ;
if ( V_16 -> V_27 [ 0 ] . V_29 != 0 )
F_29 ( V_21 , V_16 -> V_27 , V_1 , V_16 -> V_5 ) ;
else if ( V_16 -> V_26 != 0 )
F_30 ( V_21 , 0 , V_16 -> V_5 ) ;
}
void F_35 ( struct V_49 * V_21 , struct V_15 * V_16 ,
struct V_22 * * V_18 , unsigned int V_5 )
{
memset ( V_16 , 0 , sizeof( * V_16 ) ) ;
V_16 -> V_18 = V_18 ;
V_16 -> V_26 = V_5 ;
V_16 -> V_31 = V_5 ;
V_16 -> V_5 = V_5 ;
F_34 ( V_21 , V_16 , NULL ) ;
}
static T_1 * F_36 ( struct V_49 * V_21 , T_3 V_10 )
{
T_1 * V_1 = V_21 -> V_1 ;
T_1 * V_53 = V_1 + F_2 ( V_10 ) ;
if ( F_27 ( V_53 > V_21 -> V_52 || V_53 < V_1 ) )
return NULL ;
V_21 -> V_1 = V_53 ;
return V_1 ;
}
void F_37 ( struct V_49 * V_21 , void * V_16 , T_3 V_31 )
{
V_21 -> V_63 . V_28 = V_16 ;
V_21 -> V_63 . V_29 = V_31 ;
}
static T_1 * F_38 ( struct V_49 * V_21 , T_3 V_10 )
{
T_1 * V_1 ;
void * V_64 = V_21 -> V_63 . V_28 ;
T_3 V_65 = ( char * ) V_21 -> V_52 - ( char * ) V_21 -> V_1 ;
if ( V_10 > V_21 -> V_63 . V_29 )
return NULL ;
memcpy ( V_64 , V_21 -> V_1 , V_65 ) ;
V_64 += V_65 ;
V_10 -= V_65 ;
if ( ! F_33 ( V_21 ) )
return NULL ;
V_1 = F_36 ( V_21 , V_10 ) ;
if ( V_1 == NULL )
return NULL ;
memcpy ( V_64 , V_1 , V_10 ) ;
return V_21 -> V_63 . V_28 ;
}
T_1 * F_39 ( struct V_49 * V_21 , T_3 V_10 )
{
T_1 * V_1 ;
if ( V_10 == 0 )
return V_21 -> V_1 ;
if ( V_21 -> V_1 == V_21 -> V_52 && ! F_33 ( V_21 ) )
return NULL ;
V_1 = F_36 ( V_21 , V_10 ) ;
if ( V_1 != NULL )
return V_1 ;
return F_38 ( V_21 , V_10 ) ;
}
void F_40 ( struct V_49 * V_21 , unsigned int V_5 )
{
struct V_15 * V_16 = V_21 -> V_16 ;
struct V_24 * V_50 ;
T_4 V_66 ;
unsigned int V_52 ;
int V_11 ;
V_50 = V_16 -> V_27 ;
V_66 = V_50 -> V_29 + ( char * ) V_50 -> V_28 - ( char * ) V_21 -> V_1 ;
if ( V_66 > 0 )
F_22 ( V_16 , V_66 ) ;
if ( V_16 -> V_26 > V_5 )
F_23 ( V_16 , V_16 -> V_26 - V_5 ) ;
V_11 = ( F_2 ( V_5 ) << 2 ) - V_5 ;
V_21 -> V_50 = V_50 = V_16 -> V_25 ;
V_52 = V_50 -> V_29 ;
V_66 = V_16 -> V_31 - V_16 -> V_5 ;
if ( V_66 < V_52 )
V_52 -= V_66 ;
else if ( V_66 > 0 )
V_52 = 0 ;
V_21 -> V_1 = ( T_1 * ) ( ( char * ) V_50 -> V_28 + V_11 ) ;
V_21 -> V_52 = ( T_1 * ) ( ( char * ) V_50 -> V_28 + V_52 ) ;
}
void F_41 ( struct V_49 * V_21 , unsigned int V_5 )
{
F_40 ( V_21 , V_5 ) ;
F_30 ( V_21 , 0 , V_5 ) ;
}
void
F_42 ( struct V_24 * V_50 , struct V_15 * V_16 )
{
V_16 -> V_27 [ 0 ] = * V_50 ;
V_16 -> V_25 [ 0 ] = V_67 ;
V_16 -> V_26 = 0 ;
V_16 -> V_31 = V_16 -> V_5 = V_50 -> V_29 ;
}
int
F_43 ( struct V_15 * V_16 , struct V_15 * V_68 ,
unsigned int V_23 , unsigned int V_5 )
{
V_68 -> V_31 = V_68 -> V_5 = V_5 ;
if ( V_23 < V_16 -> V_27 [ 0 ] . V_29 ) {
V_68 -> V_27 [ 0 ] . V_28 = V_16 -> V_27 [ 0 ] . V_28 + V_23 ;
V_68 -> V_27 [ 0 ] . V_29 = F_44 (unsigned int, len,
buf->head[0].iov_len - base) ;
V_5 -= V_68 -> V_27 [ 0 ] . V_29 ;
V_23 = 0 ;
} else {
V_68 -> V_27 [ 0 ] . V_28 = NULL ;
V_68 -> V_27 [ 0 ] . V_29 = 0 ;
V_23 -= V_16 -> V_27 [ 0 ] . V_29 ;
}
if ( V_23 < V_16 -> V_26 ) {
V_68 -> V_26 = F_45 ( V_16 -> V_26 - V_23 , V_5 ) ;
V_23 += V_16 -> V_20 ;
V_68 -> V_20 = V_23 & ~ V_41 ;
V_68 -> V_18 = & V_16 -> V_18 [ V_23 >> V_40 ] ;
V_5 -= V_68 -> V_26 ;
V_23 = 0 ;
} else {
V_23 -= V_16 -> V_26 ;
V_68 -> V_26 = 0 ;
}
if ( V_23 < V_16 -> V_25 [ 0 ] . V_29 ) {
V_68 -> V_25 [ 0 ] . V_28 = V_16 -> V_25 [ 0 ] . V_28 + V_23 ;
V_68 -> V_25 [ 0 ] . V_29 = F_44 (unsigned int, len,
buf->tail[0].iov_len - base) ;
V_5 -= V_68 -> V_25 [ 0 ] . V_29 ;
V_23 = 0 ;
} else {
V_68 -> V_25 [ 0 ] . V_28 = NULL ;
V_68 -> V_25 [ 0 ] . V_29 = 0 ;
V_23 -= V_16 -> V_25 [ 0 ] . V_29 ;
}
if ( V_23 || V_5 )
return - 1 ;
return 0 ;
}
static void F_46 ( struct V_15 * V_68 , void * V_3 , unsigned int V_5 )
{
unsigned int V_69 ;
V_69 = F_44 (unsigned int, len, subbuf->head[0].iov_len) ;
memcpy ( V_3 , V_68 -> V_27 [ 0 ] . V_28 , V_69 ) ;
V_5 -= V_69 ;
V_3 += V_69 ;
V_69 = F_44 (unsigned int, len, subbuf->page_len) ;
if ( V_69 )
F_21 ( V_3 , V_68 -> V_18 , V_68 -> V_20 , V_69 ) ;
V_5 -= V_69 ;
V_3 += V_69 ;
V_69 = F_44 (unsigned int, len, subbuf->tail[0].iov_len) ;
memcpy ( V_3 , V_68 -> V_25 [ 0 ] . V_28 , V_69 ) ;
}
int F_47 ( struct V_15 * V_16 , unsigned int V_23 , void * V_3 , unsigned int V_5 )
{
struct V_15 V_68 ;
int V_70 ;
V_70 = F_43 ( V_16 , & V_68 , V_23 , V_5 ) ;
if ( V_70 != 0 )
return V_70 ;
F_46 ( & V_68 , V_3 , V_5 ) ;
return 0 ;
}
static void F_48 ( struct V_15 * V_68 , void * V_3 , unsigned int V_5 )
{
unsigned int V_69 ;
V_69 = F_44 (unsigned int, len, subbuf->head[0].iov_len) ;
memcpy ( V_68 -> V_27 [ 0 ] . V_28 , V_3 , V_69 ) ;
V_5 -= V_69 ;
V_3 += V_69 ;
V_69 = F_44 (unsigned int, len, subbuf->page_len) ;
if ( V_69 )
F_20 ( V_68 -> V_18 , V_68 -> V_20 , V_3 , V_69 ) ;
V_5 -= V_69 ;
V_3 += V_69 ;
V_69 = F_44 (unsigned int, len, subbuf->tail[0].iov_len) ;
memcpy ( V_68 -> V_25 [ 0 ] . V_28 , V_3 , V_69 ) ;
}
int F_49 ( struct V_15 * V_16 , unsigned int V_23 , void * V_3 , unsigned int V_5 )
{
struct V_15 V_68 ;
int V_70 ;
V_70 = F_43 ( V_16 , & V_68 , V_23 , V_5 ) ;
if ( V_70 != 0 )
return V_70 ;
F_48 ( & V_68 , V_3 , V_5 ) ;
return 0 ;
}
int
F_50 ( struct V_15 * V_16 , unsigned int V_23 , T_2 * V_3 )
{
T_1 V_71 ;
int V_70 ;
V_70 = F_47 ( V_16 , V_23 , & V_71 , sizeof( * V_3 ) ) ;
if ( V_70 )
return V_70 ;
* V_3 = F_5 ( V_71 ) ;
return 0 ;
}
int
F_51 ( struct V_15 * V_16 , unsigned int V_23 , T_2 V_3 )
{
T_1 V_71 = F_3 ( V_3 ) ;
return F_49 ( V_16 , V_23 , & V_71 , sizeof( V_3 ) ) ;
}
int F_52 ( struct V_15 * V_16 , struct V_2 * V_3 , unsigned int V_32 )
{
struct V_15 V_68 ;
if ( F_50 ( V_16 , V_32 , & V_3 -> V_5 ) )
return - V_72 ;
if ( F_43 ( V_16 , & V_68 , V_32 + 4 , V_3 -> V_5 ) )
return - V_72 ;
V_3 -> V_6 = V_68 . V_27 [ 0 ] . V_28 ;
if ( V_68 . V_27 [ 0 ] . V_29 == V_3 -> V_5 )
return 0 ;
V_3 -> V_6 = V_68 . V_25 [ 0 ] . V_28 ;
if ( V_68 . V_25 [ 0 ] . V_29 == V_3 -> V_5 )
return 0 ;
if ( V_3 -> V_5 > V_16 -> V_31 - V_16 -> V_5 )
return - V_73 ;
if ( V_16 -> V_25 [ 0 ] . V_29 != 0 )
V_3 -> V_6 = V_16 -> V_25 [ 0 ] . V_28 + V_16 -> V_25 [ 0 ] . V_29 ;
else
V_3 -> V_6 = V_16 -> V_27 [ 0 ] . V_28 + V_16 -> V_27 [ 0 ] . V_29 ;
F_46 ( & V_68 , V_3 -> V_6 , V_3 -> V_5 ) ;
return 0 ;
}
static int
F_53 ( struct V_15 * V_16 , unsigned int V_23 ,
struct V_74 * V_75 , int V_76 )
{
char * V_77 = NULL , * V_78 ;
unsigned int V_79 = 0 , V_80 , V_81 ;
struct V_22 * * V_82 = NULL ;
int V_83 ;
if ( V_76 ) {
if ( F_51 ( V_16 , V_23 , V_75 -> V_84 ) != 0 )
return - V_58 ;
} else {
if ( F_50 ( V_16 , V_23 , & V_75 -> V_84 ) != 0 ||
V_75 -> V_84 > V_75 -> V_85 ||
( unsigned long ) V_23 + 4 + V_75 -> V_84 *
V_75 -> V_86 > V_16 -> V_5 )
return - V_58 ;
}
V_23 += 4 ;
if ( ! V_75 -> V_87 )
return 0 ;
V_80 = V_75 -> V_84 * V_75 -> V_86 ;
if ( V_80 && V_23 < V_16 -> V_27 -> V_29 ) {
V_78 = V_16 -> V_27 -> V_28 + V_23 ;
V_81 = F_44 (unsigned int, todo,
buf->head->iov_len - base) ;
V_80 -= V_81 ;
while ( V_81 >= V_75 -> V_86 ) {
V_83 = V_75 -> V_87 ( V_75 , V_78 ) ;
if ( V_83 )
goto V_88;
V_78 += V_75 -> V_86 ;
V_81 -= V_75 -> V_86 ;
}
if ( V_81 ) {
if ( ! V_77 ) {
V_77 = F_54 ( V_75 -> V_86 , V_89 ) ;
V_83 = - V_73 ;
if ( ! V_77 )
goto V_88;
}
if ( V_76 ) {
V_83 = V_75 -> V_87 ( V_75 , V_77 ) ;
if ( V_83 )
goto V_88;
memcpy ( V_78 , V_77 , V_81 ) ;
} else
memcpy ( V_77 , V_78 , V_81 ) ;
V_79 = V_81 ;
}
V_23 = V_16 -> V_27 -> V_29 ;
}
V_23 -= V_16 -> V_27 -> V_29 ;
if ( V_80 && V_23 < V_16 -> V_26 ) {
unsigned int V_90 ;
V_81 = F_45 ( V_80 , V_16 -> V_26 - V_23 ) ;
V_80 -= V_81 ;
V_23 += V_16 -> V_20 ;
V_82 = V_16 -> V_18 + ( V_23 >> V_40 ) ;
V_23 &= ~ V_41 ;
V_90 = F_44 (unsigned int, PAGE_CACHE_SIZE - base,
avail_here) ;
V_78 = F_55 ( * V_82 ) + V_23 ;
while ( V_81 ) {
V_81 -= V_90 ;
if ( V_79 || V_90 < V_75 -> V_86 ) {
unsigned int V_91 = F_45 ( V_90 ,
V_75 -> V_86 - V_79 ) ;
if ( ! V_77 ) {
V_77 = F_54 ( V_75 -> V_86 ,
V_89 ) ;
V_83 = - V_73 ;
if ( ! V_77 )
goto V_88;
}
if ( V_76 ) {
if ( ! V_79 ) {
V_83 = V_75 -> V_87 ( V_75 , V_77 ) ;
if ( V_83 )
goto V_88;
}
memcpy ( V_78 , V_77 + V_79 , V_91 ) ;
V_79 += V_91 ;
if ( V_79 == V_75 -> V_86 )
V_79 = 0 ;
} else {
memcpy ( V_77 + V_79 , V_78 , V_91 ) ;
V_79 += V_91 ;
if ( V_79 == V_75 -> V_86 ) {
V_83 = V_75 -> V_87 ( V_75 , V_77 ) ;
if ( V_83 )
goto V_88;
V_79 = 0 ;
}
}
V_90 -= V_91 ;
V_78 += V_91 ;
}
while ( V_90 >= V_75 -> V_86 ) {
V_83 = V_75 -> V_87 ( V_75 , V_78 ) ;
if ( V_83 )
goto V_88;
V_78 += V_75 -> V_86 ;
V_90 -= V_75 -> V_86 ;
}
if ( V_90 ) {
unsigned int V_91 = F_45 ( V_90 ,
V_75 -> V_86 - V_79 ) ;
if ( ! V_77 ) {
V_77 = F_54 ( V_75 -> V_86 ,
V_89 ) ;
V_83 = - V_73 ;
if ( ! V_77 )
goto V_88;
}
if ( V_76 ) {
if ( ! V_79 ) {
V_83 = V_75 -> V_87 ( V_75 , V_77 ) ;
if ( V_83 )
goto V_88;
}
memcpy ( V_78 , V_77 + V_79 , V_91 ) ;
V_79 += V_91 ;
if ( V_79 == V_75 -> V_86 )
V_79 = 0 ;
} else {
memcpy ( V_77 + V_79 , V_78 , V_91 ) ;
V_79 += V_91 ;
if ( V_79 == V_75 -> V_86 ) {
V_83 = V_75 -> V_87 ( V_75 , V_77 ) ;
if ( V_83 )
goto V_88;
V_79 = 0 ;
}
}
}
if ( V_81 ) {
F_56 ( * V_82 ) ;
V_82 ++ ;
V_78 = F_55 ( * V_82 ) ;
}
V_90 = F_45 ( V_81 ,
( unsigned int ) V_42 ) ;
}
V_23 = V_16 -> V_26 ;
}
V_23 -= V_16 -> V_26 ;
if ( V_80 ) {
V_78 = V_16 -> V_25 -> V_28 + V_23 ;
if ( V_79 ) {
unsigned int V_91 = V_75 -> V_86 - V_79 ;
if ( V_76 )
memcpy ( V_78 , V_77 + V_79 , V_91 ) ;
else {
memcpy ( V_77 + V_79 , V_78 , V_91 ) ;
V_83 = V_75 -> V_87 ( V_75 , V_77 ) ;
if ( V_83 )
goto V_88;
}
V_80 -= V_91 ;
V_78 += V_91 ;
}
while ( V_80 ) {
V_83 = V_75 -> V_87 ( V_75 , V_78 ) ;
if ( V_83 )
goto V_88;
V_78 += V_75 -> V_86 ;
V_80 -= V_75 -> V_86 ;
}
}
V_83 = 0 ;
V_88:
F_57 ( V_77 ) ;
if ( V_82 )
F_56 ( * V_82 ) ;
return V_83 ;
}
int
F_58 ( struct V_15 * V_16 , unsigned int V_23 ,
struct V_74 * V_75 )
{
if ( V_23 >= V_16 -> V_5 )
return - V_58 ;
return F_53 ( V_16 , V_23 , V_75 , 0 ) ;
}
int
F_59 ( struct V_15 * V_16 , unsigned int V_23 ,
struct V_74 * V_75 )
{
if ( ( unsigned long ) V_23 + 4 + V_75 -> V_84 * V_75 -> V_86 >
V_16 -> V_27 -> V_29 + V_16 -> V_26 + V_16 -> V_25 -> V_29 )
return - V_58 ;
return F_53 ( V_16 , V_23 , V_75 , 1 ) ;
}
int
F_60 ( struct V_15 * V_16 , unsigned int V_32 , unsigned int V_5 ,
int (* F_61)( struct V_92 * , void * ) , void * V_6 )
{
int V_93 , V_94 = 0 ;
unsigned V_26 , V_95 , V_96 ;
struct V_92 V_97 [ 1 ] ;
F_62 ( V_97 , 1 ) ;
if ( V_32 >= V_16 -> V_27 [ 0 ] . V_29 ) {
V_32 -= V_16 -> V_27 [ 0 ] . V_29 ;
} else {
V_95 = V_16 -> V_27 [ 0 ] . V_29 - V_32 ;
if ( V_95 > V_5 )
V_95 = V_5 ;
F_63 ( V_97 , V_16 -> V_27 [ 0 ] . V_28 + V_32 , V_95 ) ;
V_94 = F_61 ( V_97 , V_6 ) ;
if ( V_94 )
goto V_88;
V_32 = 0 ;
V_5 -= V_95 ;
}
if ( V_5 == 0 )
goto V_88;
if ( V_32 >= V_16 -> V_26 ) {
V_32 -= V_16 -> V_26 ;
} else {
V_26 = V_16 -> V_26 - V_32 ;
if ( V_26 > V_5 )
V_26 = V_5 ;
V_5 -= V_26 ;
V_96 = ( V_32 + V_16 -> V_20 ) & ( V_42 - 1 ) ;
V_93 = ( V_32 + V_16 -> V_20 ) >> V_40 ;
V_95 = V_42 - V_96 ;
do {
if ( V_95 > V_26 )
V_95 = V_26 ;
F_64 ( V_97 , V_16 -> V_18 [ V_93 ] , V_95 , V_96 ) ;
V_94 = F_61 ( V_97 , V_6 ) ;
if ( V_94 )
goto V_88;
V_26 -= V_95 ;
V_93 ++ ;
V_96 = 0 ;
V_95 = V_42 ;
} while ( V_26 != 0 );
V_32 = 0 ;
}
if ( V_5 == 0 )
goto V_88;
if ( V_32 < V_16 -> V_25 [ 0 ] . V_29 ) {
V_95 = V_16 -> V_25 [ 0 ] . V_29 - V_32 ;
if ( V_95 > V_5 )
V_95 = V_5 ;
F_63 ( V_97 , V_16 -> V_25 [ 0 ] . V_28 + V_32 , V_95 ) ;
V_94 = F_61 ( V_97 , V_6 ) ;
V_5 -= V_95 ;
}
if ( V_5 != 0 )
V_94 = - V_58 ;
V_88:
return V_94 ;
}
