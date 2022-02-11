struct V_1 * F_1 ( struct V_2 * V_3 , T_1 * V_4 ,
struct V_5 * V_6 ,
struct V_1 * V_7 ,
struct V_8 * V_9 ,
struct V_10 * V_11 , T_2 * V_12 ,
T_3 * V_13 )
{
struct V_1 * V_14 ;
int V_15 , V_16 , V_17 ;
struct V_18 * V_19 , * V_20 [ 16 ] ;
struct V_21 * V_22 = F_2 ( V_3 ) ;
V_6 -> V_23 = V_6 -> V_24 ;
if ( V_22 -> V_25 == V_26 ) {
V_14 = F_3 ( V_22 -> V_27 . V_28 -
( V_22 -> V_29 ?
sizeof( struct V_30 ) :
sizeof( struct V_31 ) ) ,
V_3 -> V_32 -> V_33 ,
& ( V_6 -> V_24 ) ) ;
if ( ! V_14 )
return NULL ;
* V_4 += V_6 -> V_24 - V_6 -> V_23 ;
memcpy ( ( V_34 * ) V_7 , ( V_34 * ) V_14 ,
sizeof( struct V_1 ) ) ;
return V_14 ;
}
if ( V_6 -> V_24 == V_3 -> V_32 -> V_33 ) {
int V_35 = V_9 -> V_13 ;
unsigned char V_36 = V_3 -> V_32 -> V_37 ;
if ( F_4 ( V_3 , V_9 , V_11 , V_12 , 1 ) !=
( V_38 >> 30 ) )
return NULL ;
V_17 = F_5 ( V_3 -> V_32 , V_11 , * V_13 ) ;
( * V_13 ) ++ ;
if ( ( * V_13 << V_36 ) >= * V_12 )
* V_13 = 0 ;
else
V_9 -> V_13 = V_35 ;
F_6 ( V_6 -> V_39 ) ;
V_6 -> V_39 = V_6 -> V_40 = F_7 ( V_3 -> V_32 , V_17 ) ;
if ( ! V_6 -> V_39 )
return NULL ;
V_6 -> V_23 = V_6 -> V_24 = 0 ;
if ( ! ( * V_13 & ( ( 16 >> ( V_36 - 9 ) ) - 1 ) ) ) {
V_15 = 16 >> ( V_36 - 9 ) ;
if ( V_15 + * V_13 > ( * V_12 >> V_36 ) )
V_15 = ( * V_12 >> V_36 ) - * V_13 ;
for ( V_16 = 0 ; V_15 > 0 ; V_15 -- ) {
V_17 = F_5 ( V_3 -> V_32 , V_11 ,
* V_13 + V_15 ) ;
V_19 = F_8 ( V_3 -> V_32 , V_17 ) ;
if ( V_19 && ! F_9 ( V_19 ) &&
! F_10 ( V_19 ) )
V_20 [ V_16 ++ ] = V_19 ;
else
F_6 ( V_19 ) ;
}
if ( V_16 ) {
F_11 ( V_41 , V_42 , V_16 , V_20 ) ;
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ )
F_6 ( V_20 [ V_15 ] ) ;
}
}
} else if ( V_6 -> V_39 != V_6 -> V_40 ) {
F_6 ( V_6 -> V_39 ) ;
V_6 -> V_39 = V_6 -> V_40 ;
}
V_14 = F_3 ( V_6 -> V_39 -> V_43 , V_3 -> V_32 -> V_33 ,
& ( V_6 -> V_24 ) ) ;
if ( ! V_14 )
return NULL ;
* V_4 += V_6 -> V_24 - V_6 -> V_23 ;
if ( V_6 -> V_24 <= V_3 -> V_32 -> V_33 ) {
memcpy ( ( V_34 * ) V_7 , ( V_34 * ) V_14 ,
sizeof( struct V_1 ) ) ;
} else if ( V_6 -> V_24 > V_3 -> V_32 -> V_33 ) {
int V_35 = V_9 -> V_13 ;
if ( F_4 ( V_3 , V_9 , V_11 , V_12 , 1 ) !=
( V_38 >> 30 ) )
return NULL ;
V_17 = F_5 ( V_3 -> V_32 , V_11 , * V_13 ) ;
( * V_13 ) ++ ;
if ( ( * V_13 << V_3 -> V_32 -> V_37 ) >= * V_12 )
* V_13 = 0 ;
else
V_9 -> V_13 = V_35 ;
V_6 -> V_23 -= V_3 -> V_32 -> V_33 ;
V_6 -> V_24 -= V_3 -> V_32 -> V_33 ;
V_6 -> V_40 = F_7 ( V_3 -> V_32 , V_17 ) ;
if ( ! V_6 -> V_40 )
return NULL ;
if ( sizeof( struct V_1 ) > - V_6 -> V_23 ) {
int V_44 ;
memcpy ( ( V_34 * ) V_7 , ( V_34 * ) V_14 , - V_6 -> V_23 ) ;
memcpy ( ( V_34 * ) V_7 - V_6 -> V_23 ,
V_6 -> V_40 -> V_43 ,
sizeof( struct V_1 ) + V_6 -> V_23 ) ;
V_44 = ( sizeof( struct V_1 ) +
V_7 -> V_45 +
F_12 ( V_7 -> V_46 ) + 3 ) & ~ 3 ;
* V_4 += V_44 - ( V_6 -> V_24 - V_6 -> V_23 ) ;
V_6 -> V_24 = V_6 -> V_23 + V_44 ;
} else {
memcpy ( ( V_34 * ) V_7 , ( V_34 * ) V_14 ,
sizeof( struct V_1 ) ) ;
}
}
return V_14 ;
}
struct V_1 * F_3 ( void * V_47 , int V_48 , int * V_13 )
{
struct V_1 * V_14 ;
int V_49 ;
V_34 * V_50 ;
int V_51 ;
if ( ( ! V_47 ) || ( ! V_13 ) ) {
F_13 ( L_1 ,
V_47 , V_13 ) ;
return NULL ;
}
V_50 = V_47 ;
if ( ( * V_13 > 0 ) && ( * V_13 < V_48 ) )
V_50 += * V_13 ;
V_14 = (struct V_1 * ) V_50 ;
if ( V_14 -> V_52 . V_53 != F_14 ( V_54 ) ) {
F_13 ( L_2 ,
F_12 ( V_14 -> V_52 . V_53 ) ) ;
F_13 ( L_3 ,
* V_13 , ( unsigned long ) sizeof( struct V_1 ) ,
V_48 ) ;
return NULL ;
}
if ( ( * V_13 + sizeof( struct V_1 ) ) > V_48 )
V_49 = sizeof( struct V_1 ) ;
else
V_49 = sizeof( struct V_1 ) +
V_14 -> V_45 + F_12 ( V_14 -> V_46 ) ;
V_51 = V_49 % V_55 ;
if ( V_51 )
V_49 += ( V_55 - V_51 ) ;
* V_13 = * V_13 + V_49 ;
return V_14 ;
}
struct V_56 * F_15 ( V_34 * V_50 , int V_57 , T_2 * V_13 ,
int V_58 )
{
struct V_56 * V_59 ;
if ( ( ! V_50 ) || ( ! V_13 ) ) {
F_16 ( L_4 , V_60 ) ;
return NULL ;
}
if ( ( * V_13 + sizeof( struct V_56 ) ) > V_57 )
return NULL ;
else {
V_59 = (struct V_56 * ) V_50 ;
if ( V_59 -> V_61 == 0 )
return NULL ;
}
if ( V_58 )
* V_13 += sizeof( struct V_56 ) ;
return V_59 ;
}
struct V_62 * F_17 ( V_34 * V_50 , int V_57 , T_2 * V_13 , int V_58 )
{
struct V_62 * V_63 ;
if ( ( ! V_50 ) || ( ! V_13 ) ) {
F_16 ( L_4 , V_60 ) ;
return NULL ;
}
if ( ( * V_13 + sizeof( struct V_62 ) ) > V_57 )
return NULL ;
else {
V_63 = (struct V_62 * ) V_50 ;
if ( V_63 -> V_61 == 0 )
return NULL ;
}
if ( V_58 )
* V_13 += sizeof( struct V_62 ) ;
return V_63 ;
}
