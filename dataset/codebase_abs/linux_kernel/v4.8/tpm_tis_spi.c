static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_2 * V_3 , T_1 V_5 ,
T_2 V_6 , T_3 * V_7 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
int V_9 , V_10 ;
struct V_11 V_12 ;
struct V_13 V_14 = {
. V_15 = V_8 -> V_15 ,
. V_16 = V_8 -> V_16 ,
. V_6 = 4 ,
} ;
if ( V_6 > V_17 )
return - V_18 ;
V_8 -> V_15 [ 0 ] = 0x80 | ( V_6 - 1 ) ;
V_8 -> V_15 [ 1 ] = 0xd4 ;
V_8 -> V_15 [ 2 ] = ( V_5 >> 8 ) & 0xFF ;
V_8 -> V_15 [ 3 ] = V_5 & 0xFF ;
V_14 . V_19 = 1 ;
F_4 ( & V_12 ) ;
F_5 ( & V_14 , & V_12 ) ;
F_6 ( V_8 -> V_20 -> V_21 ) ;
V_9 = F_7 ( V_8 -> V_20 , & V_12 ) ;
if ( V_9 < 0 )
goto exit;
memset ( V_8 -> V_15 , 0 , V_6 ) ;
for ( V_10 = 0 ; ( V_8 -> V_16 [ 0 ] & 0x01 ) == 0 && V_10 < V_22 ; V_10 ++ ) {
V_14 . V_6 = 1 ;
F_4 ( & V_12 ) ;
F_5 ( & V_14 , & V_12 ) ;
V_9 = F_7 ( V_8 -> V_20 , & V_12 ) ;
if ( V_9 < 0 )
goto exit;
}
V_14 . V_19 = 0 ;
V_14 . V_6 = V_6 ;
V_14 . V_16 = V_7 ;
F_4 ( & V_12 ) ;
F_5 ( & V_14 , & V_12 ) ;
V_9 = F_7 ( V_8 -> V_20 , & V_12 ) ;
exit:
F_8 ( V_8 -> V_20 -> V_21 ) ;
return V_9 ;
}
static int F_9 ( struct V_2 * V_3 , T_1 V_5 ,
T_2 V_6 , T_3 * V_23 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
int V_9 , V_10 ;
struct V_11 V_12 ;
struct V_13 V_14 = {
. V_15 = V_8 -> V_15 ,
. V_16 = V_8 -> V_16 ,
. V_6 = 4 ,
} ;
if ( V_6 > V_17 )
return - V_18 ;
V_8 -> V_15 [ 0 ] = V_6 - 1 ;
V_8 -> V_15 [ 1 ] = 0xd4 ;
V_8 -> V_15 [ 2 ] = ( V_5 >> 8 ) & 0xFF ;
V_8 -> V_15 [ 3 ] = V_5 & 0xFF ;
V_14 . V_19 = 1 ;
F_4 ( & V_12 ) ;
F_5 ( & V_14 , & V_12 ) ;
F_6 ( V_8 -> V_20 -> V_21 ) ;
V_9 = F_7 ( V_8 -> V_20 , & V_12 ) ;
if ( V_9 < 0 )
goto exit;
memset ( V_8 -> V_15 , 0 , V_6 ) ;
for ( V_10 = 0 ; ( V_8 -> V_16 [ 0 ] & 0x01 ) == 0 && V_10 < V_22 ; V_10 ++ ) {
V_14 . V_6 = 1 ;
F_4 ( & V_12 ) ;
F_5 ( & V_14 , & V_12 ) ;
V_9 = F_7 ( V_8 -> V_20 , & V_12 ) ;
if ( V_9 < 0 )
goto exit;
}
V_14 . V_6 = V_6 ;
V_14 . V_15 = V_23 ;
V_14 . V_19 = 0 ;
V_14 . V_15 = V_23 ;
F_4 ( & V_12 ) ;
F_5 ( & V_14 , & V_12 ) ;
V_9 = F_7 ( V_8 -> V_20 , & V_12 ) ;
exit:
F_8 ( V_8 -> V_20 -> V_21 ) ;
return V_9 ;
}
static int F_10 ( struct V_2 * V_3 , T_1 V_5 , T_2 * V_7 )
{
int V_24 ;
V_24 = V_3 -> V_25 -> V_26 ( V_3 , V_5 , sizeof( T_2 ) , ( T_3 * ) V_7 ) ;
if ( ! V_24 )
* V_7 = F_11 ( * V_7 ) ;
return V_24 ;
}
static int F_12 ( struct V_2 * V_3 , T_1 V_5 , T_1 * V_7 )
{
int V_24 ;
V_24 = V_3 -> V_25 -> V_26 ( V_3 , V_5 , sizeof( T_1 ) , ( T_3 * ) V_7 ) ;
if ( ! V_24 )
* V_7 = F_13 ( * V_7 ) ;
return V_24 ;
}
static int F_14 ( struct V_2 * V_3 , T_1 V_5 , T_1 V_23 )
{
V_23 = F_15 ( V_23 ) ;
return V_3 -> V_25 -> V_27 ( V_3 , V_5 , sizeof( T_1 ) ,
( T_3 * ) & V_23 ) ;
}
static int F_16 ( struct V_20 * V_28 )
{
struct V_1 * V_8 ;
V_8 = F_17 ( & V_28 -> V_28 , sizeof( struct V_1 ) ,
V_29 ) ;
if ( ! V_8 )
return - V_18 ;
V_8 -> V_20 = V_28 ;
return F_18 ( & V_28 -> V_28 , & V_8 -> V_4 , - 1 , & V_30 ,
NULL ) ;
}
static int F_19 ( struct V_20 * V_28 )
{
struct V_31 * V_32 = F_20 ( V_28 ) ;
F_21 ( V_32 ) ;
F_22 ( V_32 ) ;
return 0 ;
}
