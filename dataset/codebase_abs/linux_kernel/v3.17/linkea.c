int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_2 -> V_5 = F_2 ( V_4 , V_6 ) ;
if ( V_2 -> V_5 -> V_7 == NULL )
return - V_8 ;
V_2 -> V_9 = V_2 -> V_5 -> V_7 ;
V_2 -> V_9 -> V_10 = V_11 ;
V_2 -> V_9 -> V_12 = sizeof( struct V_13 ) ;
V_2 -> V_9 -> V_14 = 0 ;
return 0 ;
}
int F_3 ( struct V_1 * V_2 )
{
struct V_13 * V_15 ;
F_4 ( V_2 -> V_5 != NULL ) ;
V_15 = V_2 -> V_5 -> V_7 ;
if ( V_15 -> V_10 == F_5 ( V_11 ) ) {
V_15 -> V_10 = V_11 ;
V_15 -> V_14 = F_5 ( V_15 -> V_14 ) ;
V_15 -> V_12 = F_6 ( V_15 -> V_12 ) ;
}
if ( V_15 -> V_10 != V_11 )
return - V_16 ;
if ( V_15 -> V_14 == 0 )
return - V_17 ;
V_2 -> V_9 = V_15 ;
return 0 ;
}
static int F_7 ( struct V_18 * V_19 ,
const struct V_20 * V_21 ,
const struct V_22 * V_23 )
{
struct V_22 V_24 ;
int V_25 ;
F_8 ( & V_24 , V_23 ) ;
if ( F_9 ( V_26 ) )
V_24 . V_27 = ~ 0 ;
memcpy ( & V_19 -> V_28 , & V_24 , sizeof( V_24 ) ) ;
memcpy ( V_19 -> V_29 , V_21 -> V_30 , V_21 -> V_31 ) ;
V_25 = sizeof( struct V_18 ) + V_21 -> V_31 ;
V_19 -> V_32 [ 0 ] = ( V_25 >> 8 ) & 0xff ;
V_19 -> V_32 [ 1 ] = V_25 & 0xff ;
return V_25 ;
}
void F_10 ( const struct V_18 * V_19 , int * V_25 ,
struct V_20 * V_21 , struct V_22 * V_23 )
{
* V_25 = ( V_19 -> V_32 [ 0 ] << 8 ) | V_19 -> V_32 [ 1 ] ;
memcpy ( V_23 , & V_19 -> V_28 , sizeof( * V_23 ) ) ;
F_11 ( V_23 , V_23 ) ;
V_21 -> V_30 = V_19 -> V_29 ;
V_21 -> V_31 = * V_25 - sizeof( struct V_18 ) ;
}
int F_12 ( struct V_1 * V_2 , const struct V_20 * V_21 ,
const struct V_22 * V_23 )
{
F_4 ( V_2 -> V_9 != NULL ) ;
if ( V_21 == NULL || V_23 == NULL )
return - V_16 ;
V_2 -> V_33 = V_21 -> V_31 + sizeof( struct V_18 ) ;
if ( V_2 -> V_9 -> V_12 + V_2 -> V_33 >
V_2 -> V_5 -> V_34 ) {
if ( F_13 ( V_2 -> V_5 ,
V_2 -> V_9 -> V_12 +
V_2 -> V_33 ) < 0 )
return - V_8 ;
}
V_2 -> V_9 = V_2 -> V_5 -> V_7 ;
V_2 -> V_35 = V_2 -> V_5 -> V_7 + V_2 -> V_9 -> V_12 ;
V_2 -> V_33 = F_7 ( V_2 -> V_35 , V_21 , V_23 ) ;
V_2 -> V_9 -> V_12 += V_2 -> V_33 ;
V_2 -> V_9 -> V_14 ++ ;
F_14 ( V_36 , L_1 ,
V_21 -> V_31 , V_21 -> V_30 ) ;
return 0 ;
}
void F_15 ( struct V_1 * V_2 , const struct V_20 * V_21 )
{
F_4 ( V_2 -> V_9 != NULL && V_2 -> V_35 != NULL ) ;
V_2 -> V_9 -> V_14 -- ;
V_2 -> V_9 -> V_12 -= V_2 -> V_33 ;
memmove ( V_2 -> V_35 , ( char * ) V_2 -> V_35 + V_2 -> V_33 ,
( char * ) V_2 -> V_9 + V_2 -> V_9 -> V_12 -
( char * ) V_2 -> V_35 ) ;
F_14 ( V_36 , L_2 ,
V_21 -> V_31 , V_21 -> V_30 ) ;
}
int F_16 ( struct V_1 * V_2 , const struct V_20 * V_21 ,
const struct V_22 * V_23 )
{
struct V_20 V_37 ;
struct V_22 V_24 ;
int V_38 ;
F_4 ( V_2 -> V_9 != NULL ) ;
V_2 -> V_35 = (struct V_18 * ) ( V_2 -> V_9 + 1 ) ;
for ( V_38 = 0 ; V_38 < V_2 -> V_9 -> V_14 ; V_38 ++ ) {
F_10 ( V_2 -> V_35 , & V_2 -> V_33 ,
& V_37 , & V_24 ) ;
if ( V_37 . V_31 == V_21 -> V_31 &&
F_17 ( & V_24 , V_23 ) &&
( strncmp ( V_37 . V_30 , V_21 -> V_30 ,
V_37 . V_31 ) == 0 ) )
break;
V_2 -> V_35 = (struct V_18 * ) ( ( char * ) V_2 -> V_35 +
V_2 -> V_33 ) ;
}
if ( V_38 == V_2 -> V_9 -> V_14 ) {
F_14 ( V_36 , L_3 ,
V_21 -> V_31 , V_21 -> V_30 ) ;
V_2 -> V_35 = NULL ;
return - V_39 ;
}
return 0 ;
}
