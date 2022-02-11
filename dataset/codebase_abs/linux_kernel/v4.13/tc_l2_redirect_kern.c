static T_1 bool F_1 ( T_2 V_1 , T_3 V_2 )
{
if ( V_1 == F_2 ( V_3 ) )
return ( F_3 ( 0xffffff00 ) & V_2 ) == F_3 ( 0x0a0a0100 ) ;
else if ( V_1 == F_2 ( V_4 ) )
return ( V_2 == F_3 ( 0x2401face ) ) ;
return false ;
}
int F_4 ( struct V_5 * V_6 )
{
struct V_7 V_8 = {} ;
void * V_9 = ( void * ) ( long ) V_6 -> V_9 ;
struct V_10 * V_11 = V_9 ;
void * V_12 = ( void * ) ( long ) V_6 -> V_12 ;
int V_13 = 0 , * V_14 ;
int V_15 ;
if ( V_9 + sizeof( * V_11 ) > V_12 )
return V_16 ;
V_14 = F_5 ( & V_17 , & V_13 ) ;
if ( ! V_14 )
return V_16 ;
if ( V_11 -> V_18 == F_2 ( V_3 ) ) {
char V_19 [] = L_1 ;
struct V_20 * V_21 = V_9 + sizeof( * V_11 ) ;
if ( V_9 + sizeof( * V_11 ) + sizeof( * V_21 ) > V_12 )
return V_16 ;
if ( V_21 -> V_22 != V_23 )
return V_16 ;
F_6 ( V_19 , sizeof( V_19 ) , * V_14 ,
F_3 ( V_21 -> V_2 ) ) ;
return F_7 ( * V_14 , V_24 ) ;
} else if ( V_11 -> V_18 == F_2 ( V_4 ) ) {
char V_25 [] = L_2 ;
struct V_26 * V_27 = V_9 + sizeof( * V_11 ) ;
if ( V_9 + sizeof( * V_11 ) + sizeof( * V_27 ) > V_12 )
return V_16 ;
if ( V_27 -> V_28 != V_23 &&
V_27 -> V_28 != V_29 )
return V_16 ;
F_6 ( V_25 , sizeof( V_25 ) , * V_14 ,
F_3 ( V_27 -> V_2 . V_30 [ 0 ] ) ,
F_3 ( V_27 -> V_2 . V_30 [ 3 ] ) ) ;
return F_7 ( * V_14 , V_24 ) ;
}
return V_16 ;
}
int F_8 ( struct V_5 * V_6 )
{
struct V_7 V_8 = {} ;
void * V_9 = ( void * ) ( long ) V_6 -> V_9 ;
struct V_10 * V_11 = V_9 ;
void * V_12 = ( void * ) ( long ) V_6 -> V_12 ;
int V_13 = 0 , * V_14 ;
int V_15 ;
if ( V_9 + sizeof( * V_11 ) > V_12 )
return V_16 ;
V_14 = F_5 ( & V_17 , & V_13 ) ;
if ( ! V_14 )
return V_16 ;
if ( V_11 -> V_18 == F_2 ( V_3 ) ) {
char V_19 [] = L_3 ;
struct V_20 * V_21 = V_9 + sizeof( * V_11 ) ;
T_3 V_2 = V_21 -> V_2 ;
if ( V_9 + sizeof( * V_11 ) + sizeof( * V_21 ) > V_12 )
return V_16 ;
if ( ! F_1 ( V_11 -> V_18 , V_2 ) )
return V_16 ;
F_6 ( V_19 , sizeof( V_19 ) , F_3 ( V_2 ) , * V_14 ) ;
} else {
return V_16 ;
}
V_8 . V_31 = 10000 ;
V_8 . V_32 = 64 ;
V_8 . V_33 = 0x0a020166 ;
F_9 ( V_6 , & V_8 , sizeof( V_8 ) , 0 ) ;
return F_7 ( * V_14 , 0 ) ;
}
int F_10 ( struct V_5 * V_6 )
{
struct V_7 V_8 = {} ;
void * V_9 = ( void * ) ( long ) V_6 -> V_9 ;
struct V_10 * V_11 = V_9 ;
void * V_12 = ( void * ) ( long ) V_6 -> V_12 ;
int V_13 = 0 , * V_14 ;
if ( V_9 + sizeof( * V_11 ) > V_12 )
return V_16 ;
V_14 = F_5 ( & V_17 , & V_13 ) ;
if ( ! V_14 )
return V_16 ;
if ( V_11 -> V_18 == F_2 ( V_3 ) ) {
char V_19 [] = L_3 ;
struct V_20 * V_21 = V_9 + sizeof( * V_11 ) ;
if ( V_9 + sizeof( * V_11 ) + sizeof( * V_21 ) > V_12 )
return V_16 ;
if ( ! F_1 ( V_11 -> V_18 , V_21 -> V_2 ) )
return V_16 ;
F_6 ( V_19 , sizeof( V_19 ) , F_3 ( V_21 -> V_2 ) ,
* V_14 ) ;
} else if ( V_11 -> V_18 == F_2 ( V_4 ) ) {
char V_25 [] = L_4 ;
struct V_26 * V_27 = V_9 + sizeof( * V_11 ) ;
if ( V_9 + sizeof( * V_11 ) + sizeof( * V_27 ) > V_12 )
return V_16 ;
if ( ! F_1 ( V_11 -> V_18 , V_27 -> V_2 . V_30 [ 0 ] ) )
return V_16 ;
F_6 ( V_25 , sizeof( V_25 ) ,
F_3 ( V_27 -> V_2 . V_30 [ 0 ] ) , * V_14 ) ;
} else {
return V_16 ;
}
V_8 . V_31 = 10000 ;
V_8 . V_32 = 64 ;
V_8 . V_34 [ 0 ] = F_3 ( 0x2401db02 ) ;
V_8 . V_34 [ 1 ] = 0 ;
V_8 . V_34 [ 2 ] = 0 ;
V_8 . V_34 [ 3 ] = F_3 ( 0x00000066 ) ;
F_9 ( V_6 , & V_8 , sizeof( V_8 ) , V_35 ) ;
return F_7 ( * V_14 , 0 ) ;
}
int F_11 ( struct V_5 * V_6 )
{
struct V_7 V_8 = {} ;
void * V_9 = ( void * ) ( long ) V_6 -> V_9 ;
struct V_10 * V_11 = V_9 ;
void * V_12 = ( void * ) ( long ) V_6 -> V_12 ;
if ( V_9 + sizeof( * V_11 ) > V_12 )
return V_16 ;
if ( V_11 -> V_18 == F_2 ( V_3 ) ) {
struct V_20 * V_21 = V_9 + sizeof( * V_11 ) ;
if ( V_9 + sizeof( * V_11 ) + sizeof( * V_21 ) > V_12 )
return V_16 ;
if ( F_1 ( V_11 -> V_18 , V_21 -> V_2 ) )
return V_36 ;
} else if ( V_11 -> V_18 == F_2 ( V_4 ) ) {
struct V_26 * V_27 = V_9 + sizeof( * V_11 ) ;
if ( V_9 + sizeof( * V_11 ) + sizeof( * V_27 ) > V_12 )
return V_16 ;
if ( F_1 ( V_11 -> V_18 , V_27 -> V_2 . V_30 [ 0 ] ) )
return V_36 ;
}
return V_16 ;
}
