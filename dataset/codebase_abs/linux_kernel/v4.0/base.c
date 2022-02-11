static int
F_1 ( struct V_1 * V_2 , T_1 V_3 , struct V_4 * * V_5 )
{
struct V_6 * V_7 = ( void * ) V_2 ;
int V_8 ;
V_8 = F_2 ( & V_7 -> V_9 , 0 , 1 , V_3 , V_3 , 1 , V_5 ) ;
if ( V_8 )
* V_5 = NULL ;
return V_8 ;
}
static void
F_3 ( struct V_1 * V_2 , struct V_4 * * V_5 )
{
struct V_6 * V_7 = ( void * ) V_2 ;
F_4 ( & V_7 -> V_9 , V_5 ) ;
}
static void
F_5 ( struct V_1 * V_2 , T_1 V_10 , T_1 V_11 )
{
const struct V_12 * V_13 = ( void * ) F_6 ( V_2 ) ;
struct V_6 * V_7 = ( void * ) V_2 ;
const T_1 V_14 = V_10 + V_11 - 1 ;
F_7 ( ( V_10 > V_14 ) || ( V_14 >= V_7 -> V_15 ) ) ;
V_13 -> V_16 ( V_7 , V_10 , V_14 ) ;
V_13 -> V_17 ( V_7 ) ;
}
static int
F_8 ( struct V_1 * V_2 , int V_18 , const T_1 V_19 [ 4 ] )
{
const struct V_12 * V_13 = ( void * ) F_6 ( V_2 ) ;
struct V_6 * V_7 = ( void * ) V_2 ;
memcpy ( V_7 -> V_20 [ V_18 ] , V_19 , sizeof( V_7 -> V_20 [ V_18 ] ) ) ;
V_13 -> V_21 ( V_7 , V_18 , V_19 ) ;
return V_18 ;
}
static int
F_9 ( struct V_1 * V_2 , int V_18 , const T_1 V_22 )
{
const struct V_12 * V_13 = ( void * ) F_6 ( V_2 ) ;
struct V_6 * V_7 = ( void * ) V_2 ;
V_7 -> V_23 [ V_18 ] = V_22 ;
V_13 -> V_24 ( V_7 , V_18 , V_22 ) ;
return V_18 ;
}
int
F_10 ( struct V_25 * V_26 )
{
const struct V_12 * V_13 = ( void * ) F_6 ( V_26 ) ;
struct V_6 * V_7 = ( void * ) V_26 ;
int V_8 , V_27 ;
V_8 = F_11 ( & V_7 -> V_28 . V_28 ) ;
if ( V_8 )
return V_8 ;
for ( V_27 = V_7 -> V_28 . V_29 ; V_27 <= V_7 -> V_28 . V_30 ; V_27 ++ ) {
V_13 -> V_21 ( V_7 , V_27 , V_7 -> V_20 [ V_27 ] ) ;
V_13 -> V_24 ( V_7 , V_27 , V_7 -> V_23 [ V_27 ] ) ;
}
return 0 ;
}
int
F_12 ( struct V_25 * V_31 , struct V_25 * V_32 ,
struct V_33 * V_34 , int V_35 , void * * V_36 )
{
const struct V_12 * V_13 = ( void * ) V_34 ;
struct V_6 * V_7 ;
int V_8 ;
V_8 = F_13 ( V_31 , V_32 , V_34 , 0 , L_1 ,
L_2 , V_35 , V_36 ) ;
V_7 = * V_36 ;
if ( V_8 )
return V_8 ;
memset ( V_7 -> V_20 , 0x00 , sizeof( V_7 -> V_20 ) ) ;
memset ( V_7 -> V_23 , 0x00 , sizeof( V_7 -> V_23 ) ) ;
V_7 -> V_28 . V_28 . V_37 = V_13 -> V_37 ;
V_7 -> V_28 . V_38 = F_1 ;
V_7 -> V_28 . V_39 = F_3 ;
V_7 -> V_28 . V_40 = F_5 ;
V_7 -> V_28 . V_29 = 1 ;
V_7 -> V_28 . V_30 = F_14 ( V_13 -> V_41 , V_42 ) - 1 ;
V_7 -> V_28 . V_43 = F_8 ;
V_7 -> V_28 . V_44 = F_9 ;
return 0 ;
}
