static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_2 * V_3 , T_1 V_5 , T_2 V_6 ,
T_3 * V_7 , T_3 V_8 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
int V_10 = 0 ;
int V_11 ;
struct V_12 V_13 ;
struct V_14 V_15 ;
T_3 V_16 ;
F_4 ( V_9 -> V_17 -> V_18 ) ;
while ( V_6 ) {
V_16 = F_5 ( T_2 , V_6 , V_19 ) ;
V_9 -> V_20 [ 0 ] = V_8 | ( V_16 - 1 ) ;
V_9 -> V_20 [ 1 ] = 0xd4 ;
V_9 -> V_20 [ 2 ] = V_5 >> 8 ;
V_9 -> V_20 [ 3 ] = V_5 ;
memset ( & V_15 , 0 , sizeof( V_15 ) ) ;
V_15 . V_20 = V_9 -> V_20 ;
V_15 . V_21 = V_9 -> V_21 ;
V_15 . V_6 = 4 ;
V_15 . V_22 = 1 ;
F_6 ( & V_13 ) ;
F_7 ( & V_15 , & V_13 ) ;
V_10 = F_8 ( V_9 -> V_17 , & V_13 ) ;
if ( V_10 < 0 )
goto exit;
if ( ( V_9 -> V_21 [ 3 ] & 0x01 ) == 0 ) {
V_9 -> V_20 [ 0 ] = 0 ;
for ( V_11 = 0 ; V_11 < V_23 ; V_11 ++ ) {
V_15 . V_6 = 1 ;
F_6 ( & V_13 ) ;
F_7 ( & V_15 , & V_13 ) ;
V_10 = F_8 ( V_9 -> V_17 , & V_13 ) ;
if ( V_10 < 0 )
goto exit;
if ( V_9 -> V_21 [ 0 ] & 0x01 )
break;
}
if ( V_11 == V_23 ) {
V_10 = - V_24 ;
goto exit;
}
}
V_15 . V_22 = 0 ;
V_15 . V_6 = V_16 ;
V_15 . V_25 = 5 ;
if ( V_8 ) {
V_15 . V_20 = NULL ;
V_15 . V_21 = V_7 ;
} else {
V_15 . V_20 = V_7 ;
V_15 . V_21 = NULL ;
}
F_6 ( & V_13 ) ;
F_7 ( & V_15 , & V_13 ) ;
V_10 = F_8 ( V_9 -> V_17 , & V_13 ) ;
if ( V_10 < 0 )
goto exit;
V_6 -= V_16 ;
V_7 += V_16 ;
}
exit:
F_9 ( V_9 -> V_17 -> V_18 ) ;
return V_10 ;
}
static int F_10 ( struct V_2 * V_3 , T_1 V_5 ,
T_2 V_6 , T_3 * V_26 )
{
return F_3 ( V_3 , V_5 , V_6 , V_26 , 0x80 ) ;
}
static int F_11 ( struct V_2 * V_3 , T_1 V_5 ,
T_2 V_6 , T_3 * V_27 )
{
return F_3 ( V_3 , V_5 , V_6 , V_27 , 0 ) ;
}
static int F_12 ( struct V_2 * V_3 , T_1 V_5 , T_2 * V_26 )
{
int V_28 ;
V_28 = V_3 -> V_29 -> V_30 ( V_3 , V_5 , sizeof( T_2 ) , ( T_3 * ) V_26 ) ;
if ( ! V_28 )
* V_26 = F_13 ( * V_26 ) ;
return V_28 ;
}
static int F_14 ( struct V_2 * V_3 , T_1 V_5 , T_1 * V_26 )
{
int V_28 ;
V_28 = V_3 -> V_29 -> V_30 ( V_3 , V_5 , sizeof( T_1 ) , ( T_3 * ) V_26 ) ;
if ( ! V_28 )
* V_26 = F_15 ( * V_26 ) ;
return V_28 ;
}
static int F_16 ( struct V_2 * V_3 , T_1 V_5 , T_1 V_27 )
{
V_27 = F_17 ( V_27 ) ;
return V_3 -> V_29 -> V_31 ( V_3 , V_5 , sizeof( T_1 ) ,
( T_3 * ) & V_27 ) ;
}
static int F_18 ( struct V_17 * V_32 )
{
struct V_1 * V_9 ;
V_9 = F_19 ( & V_32 -> V_32 , sizeof( struct V_1 ) ,
V_33 ) ;
if ( ! V_9 )
return - V_34 ;
V_9 -> V_17 = V_32 ;
return F_20 ( & V_32 -> V_32 , & V_9 -> V_4 , - 1 , & V_35 ,
NULL ) ;
}
static int F_21 ( struct V_17 * V_32 )
{
struct V_36 * V_37 = F_22 ( V_32 ) ;
F_23 ( V_37 ) ;
F_24 ( V_37 ) ;
return 0 ;
}
