int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_2 -> V_5 = F_2 ( V_4 , V_6 ) ;
if ( ! V_2 -> V_5 -> V_7 )
return - V_8 ;
V_2 -> V_9 = V_2 -> V_5 -> V_7 ;
V_2 -> V_9 -> V_10 = V_11 ;
V_2 -> V_9 -> V_12 = sizeof( struct V_13 ) ;
V_2 -> V_9 -> V_14 = 0 ;
V_2 -> V_9 -> V_15 = 0 ;
V_2 -> V_9 -> V_16 = 0 ;
return 0 ;
}
int F_3 ( struct V_1 * V_2 )
{
struct V_13 * V_17 ;
F_4 ( V_2 -> V_5 ) ;
V_17 = V_2 -> V_5 -> V_7 ;
if ( V_17 -> V_10 == F_5 ( V_11 ) ) {
V_17 -> V_10 = V_11 ;
V_17 -> V_14 = F_5 ( V_17 -> V_14 ) ;
V_17 -> V_12 = F_6 ( V_17 -> V_12 ) ;
V_17 -> V_15 = F_5 ( V_17 -> V_15 ) ;
V_17 -> V_16 = F_5 ( V_17 -> V_16 ) ;
}
if ( V_17 -> V_10 != V_11 )
return - V_18 ;
if ( V_17 -> V_14 == 0 && V_17 -> V_15 == 0 )
return - V_19 ;
V_2 -> V_9 = V_17 ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 )
{
int V_20 ;
V_20 = F_3 ( V_2 ) ;
if ( ! V_20 && V_2 -> V_9 -> V_14 == 0 )
V_20 = - V_19 ;
return V_20 ;
}
int F_8 ( struct V_21 * V_22 , const struct V_23 * V_24 ,
const struct V_25 * V_26 )
{
struct V_25 V_27 ;
int V_28 ;
V_27 = * V_26 ;
if ( F_9 ( V_29 ) )
V_27 . V_30 = ~ 0 ;
F_10 ( & V_27 , & V_27 ) ;
memcpy ( & V_22 -> V_31 , & V_27 , sizeof( V_27 ) ) ;
memcpy ( V_22 -> V_32 , V_24 -> V_33 , V_24 -> V_34 ) ;
V_28 = sizeof( struct V_21 ) + V_24 -> V_34 ;
V_22 -> V_35 [ 0 ] = ( V_28 >> 8 ) & 0xff ;
V_22 -> V_35 [ 1 ] = V_28 & 0xff ;
return V_28 ;
}
void F_11 ( const struct V_21 * V_22 , int * V_28 ,
struct V_23 * V_24 , struct V_25 * V_26 )
{
F_4 ( V_22 ) ;
* V_28 = ( V_22 -> V_35 [ 0 ] << 8 ) | V_22 -> V_35 [ 1 ] ;
memcpy ( V_26 , & V_22 -> V_31 , sizeof( * V_26 ) ) ;
F_12 ( V_26 , V_26 ) ;
if ( V_24 ) {
V_24 -> V_33 = V_22 -> V_32 ;
V_24 -> V_34 = * V_28 - sizeof( struct V_21 ) ;
}
}
int F_13 ( struct V_1 * V_2 , const struct V_23 * V_24 ,
const struct V_25 * V_26 )
{
struct V_13 * V_17 = V_2 -> V_9 ;
int V_28 ;
F_4 ( V_17 ) ;
if ( ! V_24 || ! V_26 )
return - V_18 ;
V_28 = V_24 -> V_34 + sizeof( struct V_21 ) ;
if ( F_14 ( V_17 -> V_12 + V_28 > V_36 ) ) {
V_17 -> V_15 = F_15 () ;
if ( F_14 ( V_17 -> V_15 == 0 ) )
V_17 -> V_15 ++ ;
F_16 ( V_37 , L_1 V_38 L_2 ,
F_17 ( V_26 ) , V_24 -> V_34 ,
V_24 -> V_33 , V_17 -> V_15 ) ;
return 0 ;
}
if ( V_17 -> V_12 + V_28 > V_2 -> V_5 -> V_39 ) {
if ( F_18 ( V_2 -> V_5 ,
V_17 -> V_12 + V_28 ) < 0 )
return - V_8 ;
V_17 = V_2 -> V_9 = V_2 -> V_5 -> V_7 ;
}
V_2 -> V_40 = V_2 -> V_5 -> V_7 + V_17 -> V_12 ;
V_2 -> V_41 = F_8 ( V_2 -> V_40 , V_24 , V_26 ) ;
V_17 -> V_12 += V_2 -> V_41 ;
V_17 -> V_14 ++ ;
F_16 ( V_37 , L_3 V_38 L_4 ,
F_17 ( V_26 ) , V_24 -> V_34 , V_24 -> V_33 ) ;
return 0 ;
}
void F_19 ( struct V_1 * V_2 , const struct V_23 * V_24 )
{
F_4 ( V_2 -> V_9 && V_2 -> V_40 ) ;
F_4 ( V_2 -> V_9 -> V_14 > 0 ) ;
V_2 -> V_9 -> V_14 -- ;
V_2 -> V_9 -> V_12 -= V_2 -> V_41 ;
memmove ( V_2 -> V_40 , ( char * ) V_2 -> V_40 + V_2 -> V_41 ,
( char * ) V_2 -> V_9 + V_2 -> V_9 -> V_12 -
( char * ) V_2 -> V_40 ) ;
F_16 ( V_37 , L_5 ,
V_24 -> V_34 , V_24 -> V_33 ) ;
if ( ( char * ) V_2 -> V_40 >= ( ( char * ) V_2 -> V_9 +
V_2 -> V_9 -> V_12 ) )
V_2 -> V_40 = NULL ;
}
int F_20 ( struct V_1 * V_2 , const struct V_23 * V_24 ,
const struct V_25 * V_26 )
{
struct V_23 V_42 ;
struct V_25 V_27 ;
int V_43 ;
F_4 ( V_2 -> V_9 ) ;
if ( F_21 ( V_2 -> V_9 -> V_14 > 0 ) )
V_2 -> V_40 = (struct V_21 * ) ( V_2 -> V_9 + 1 ) ;
for ( V_43 = 0 ; V_43 < V_2 -> V_9 -> V_14 ; V_43 ++ ) {
F_11 ( V_2 -> V_40 , & V_2 -> V_41 ,
& V_42 , & V_27 ) ;
if ( V_42 . V_34 == V_24 -> V_34 &&
F_22 ( & V_27 , V_26 ) &&
( strncmp ( V_42 . V_33 , V_24 -> V_33 ,
V_42 . V_34 ) == 0 ) )
break;
V_2 -> V_40 = (struct V_21 * ) ( ( char * ) V_2 -> V_40 +
V_2 -> V_41 ) ;
}
if ( V_43 == V_2 -> V_9 -> V_14 ) {
F_16 ( V_37 , L_6 ,
V_24 -> V_34 , V_24 -> V_33 ) ;
V_2 -> V_40 = NULL ;
V_2 -> V_41 = 0 ;
return - V_44 ;
}
return 0 ;
}
