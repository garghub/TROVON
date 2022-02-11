int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 V_5 ;
F_2 ( & V_5 , 0x0 , sizeof( V_5 ) ) ;
V_5 . V_6 = 0xac100164 ;
V_5 . V_7 = 2 ;
V_5 . V_8 = 0 ;
V_5 . V_9 = 64 ;
V_3 = F_3 ( V_2 , & V_5 , sizeof( V_5 ) , V_10 ) ;
if ( V_3 < 0 ) {
ERROR ( V_3 ) ;
return V_11 ;
}
return V_12 ;
}
int F_4 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 V_5 ;
char V_13 [] = L_1 ;
V_3 = F_5 ( V_2 , & V_5 , sizeof( V_5 ) , 0 ) ;
if ( V_3 < 0 ) {
ERROR ( V_3 ) ;
return V_11 ;
}
F_6 ( V_13 , sizeof( V_13 ) , V_5 . V_7 , V_5 . V_6 ) ;
return V_12 ;
}
int F_7 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 V_5 ;
struct V_14 V_15 ;
F_2 ( & V_5 , 0x0 , sizeof( V_5 ) ) ;
V_5 . V_6 = 0xac100164 ;
V_5 . V_7 = 2 ;
V_5 . V_8 = 0 ;
V_5 . V_9 = 64 ;
V_3 = F_3 ( V_2 , & V_5 , sizeof( V_5 ) , V_10 ) ;
if ( V_3 < 0 ) {
ERROR ( V_3 ) ;
return V_11 ;
}
V_15 . V_16 = 0x800FF ;
V_3 = F_8 ( V_2 , & V_15 , sizeof( V_15 ) ) ;
if ( V_3 < 0 ) {
ERROR ( V_3 ) ;
return V_11 ;
}
return V_12 ;
}
int F_9 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 V_5 ;
struct V_14 V_15 ;
char V_13 [] = L_2 ;
V_3 = F_5 ( V_2 , & V_5 , sizeof( V_5 ) , 0 ) ;
if ( V_3 < 0 ) {
ERROR ( V_3 ) ;
return V_11 ;
}
V_3 = F_10 ( V_2 , & V_15 , sizeof( V_15 ) ) ;
if ( V_3 < 0 ) {
ERROR ( V_3 ) ;
return V_11 ;
}
F_6 ( V_13 , sizeof( V_13 ) ,
V_5 . V_7 , V_5 . V_6 , V_15 . V_16 ) ;
return V_12 ;
}
int F_11 ( struct V_1 * V_2 )
{
int V_3 , V_17 ;
struct V_4 V_5 ;
struct V_18 V_19 ;
F_2 ( & V_5 , 0x0 , sizeof( V_5 ) ) ;
V_5 . V_6 = 0xac100164 ;
V_5 . V_7 = 2 ;
V_5 . V_8 = 0 ;
V_5 . V_9 = 64 ;
F_2 ( & V_19 , 0x0 , sizeof( V_19 ) ) ;
V_19 . V_20 = 0x102 ;
V_19 . type = 0x08 ;
V_19 . V_21 = 1 ;
V_19 . V_22 = 0 ;
V_19 . V_23 = 1 ;
V_19 . V_24 = 2 ;
* ( int * ) & V_19 . V_25 = 0xdeadbeef ;
V_3 = F_3 ( V_2 , & V_5 , sizeof( V_5 ) , V_10 ) ;
if ( V_3 < 0 ) {
ERROR ( V_3 ) ;
return V_11 ;
}
V_3 = F_8 ( V_2 , & V_19 , sizeof( V_19 ) ) ;
if ( V_3 < 0 ) {
ERROR ( V_3 ) ;
return V_11 ;
}
return V_12 ;
}
int F_12 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 V_5 ;
struct V_18 V_19 ;
char V_13 [] = L_3 ;
V_3 = F_5 ( V_2 , & V_5 , sizeof( V_5 ) , 0 ) ;
if ( V_3 < 0 ) {
ERROR ( V_3 ) ;
return V_11 ;
}
V_3 = F_10 ( V_2 , & V_19 , sizeof( V_19 ) ) ;
if ( V_3 < 0 ) {
ERROR ( V_3 ) ;
return V_11 ;
}
F_6 ( V_13 , sizeof( V_13 ) ,
V_5 . V_7 , V_5 . V_6 , V_19 . V_20 ) ;
return V_12 ;
}
int F_13 ( struct V_1 * V_2 )
{
struct V_4 V_5 = {} ;
void * V_26 = ( void * ) ( long ) V_2 -> V_26 ;
struct V_27 * V_28 = V_26 ;
struct V_29 * V_30 = V_26 + sizeof( * V_28 ) ;
void * V_31 = ( void * ) ( long ) V_2 -> V_31 ;
int V_3 ;
if ( V_26 + sizeof( * V_28 ) + sizeof( * V_30 ) > V_31 ) {
ERROR ( 1 ) ;
return V_11 ;
}
V_5 . V_9 = 64 ;
if ( V_28 -> V_32 == V_33 ) {
V_5 . V_6 = 0xac100164 ;
} else {
if ( V_28 -> V_32 != V_34 || V_28 -> V_35 != 5 )
return V_11 ;
if ( V_30 -> V_36 == F_14 ( 5200 ) )
V_5 . V_6 = 0xac100164 ;
else if ( V_30 -> V_36 == F_14 ( 5201 ) )
V_5 . V_6 = 0xac100165 ;
else
return V_11 ;
}
V_3 = F_3 ( V_2 , & V_5 , sizeof( V_5 ) , 0 ) ;
if ( V_3 < 0 ) {
ERROR ( V_3 ) ;
return V_11 ;
}
return V_12 ;
}
int F_15 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 V_5 ;
char V_13 [] = L_4 ;
V_3 = F_5 ( V_2 , & V_5 , sizeof( V_5 ) , 0 ) ;
if ( V_3 < 0 ) {
ERROR ( V_3 ) ;
return V_11 ;
}
F_6 ( V_13 , sizeof( V_13 ) , V_5 . V_6 ) ;
return V_12 ;
}
int F_16 ( struct V_1 * V_2 )
{
struct V_4 V_5 = {} ;
void * V_26 = ( void * ) ( long ) V_2 -> V_26 ;
struct V_27 * V_28 = V_26 ;
struct V_29 * V_30 = V_26 + sizeof( * V_28 ) ;
void * V_31 = ( void * ) ( long ) V_2 -> V_31 ;
int V_3 ;
if ( V_26 + sizeof( * V_28 ) + sizeof( * V_30 ) > V_31 ) {
ERROR ( 1 ) ;
return V_11 ;
}
V_5 . V_37 [ 0 ] = F_17 ( 0x2401db00 ) ;
V_5 . V_9 = 64 ;
if ( V_28 -> V_32 == V_33 ) {
V_5 . V_37 [ 3 ] = F_17 ( 1 ) ;
} else {
if ( V_28 -> V_32 != V_34 || V_28 -> V_35 != 5 ) {
ERROR ( V_28 -> V_32 ) ;
return V_11 ;
}
if ( V_30 -> V_36 == F_14 ( 5200 ) ) {
V_5 . V_37 [ 3 ] = F_17 ( 1 ) ;
} else if ( V_30 -> V_36 == F_14 ( 5201 ) ) {
V_5 . V_37 [ 3 ] = F_17 ( 2 ) ;
} else {
ERROR ( V_30 -> V_36 ) ;
return V_11 ;
}
}
V_3 = F_3 ( V_2 , & V_5 , sizeof( V_5 ) , V_38 ) ;
if ( V_3 < 0 ) {
ERROR ( V_3 ) ;
return V_11 ;
}
return V_12 ;
}
int F_18 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 V_5 ;
char V_13 [] = L_5 ;
V_3 = F_5 ( V_2 , & V_5 , sizeof( V_5 ) , V_38 ) ;
if ( V_3 < 0 ) {
ERROR ( V_3 ) ;
return V_11 ;
}
F_6 ( V_13 , sizeof( V_13 ) , F_17 ( V_5 . V_37 [ 0 ] ) ,
F_17 ( V_5 . V_37 [ 3 ] ) ) ;
return V_12 ;
}
int F_19 ( struct V_1 * V_2 )
{
struct V_4 V_5 = {} ;
void * V_26 = ( void * ) ( long ) V_2 -> V_26 ;
struct V_39 * V_28 = V_26 ;
struct V_29 * V_30 = V_26 + sizeof( * V_28 ) ;
void * V_31 = ( void * ) ( long ) V_2 -> V_31 ;
int V_3 ;
if ( V_26 + sizeof( * V_28 ) + sizeof( * V_30 ) > V_31 ) {
ERROR ( 1 ) ;
return V_11 ;
}
V_5 . V_37 [ 0 ] = F_17 ( 0x2401db00 ) ;
V_5 . V_9 = 64 ;
if ( V_28 -> V_40 == V_41 ) {
V_5 . V_37 [ 3 ] = F_17 ( 1 ) ;
} else {
if ( V_28 -> V_40 != V_42 ) {
ERROR ( V_28 -> V_40 ) ;
return V_11 ;
}
if ( V_30 -> V_36 == F_14 ( 5200 ) ) {
V_5 . V_37 [ 3 ] = F_17 ( 1 ) ;
} else if ( V_30 -> V_36 == F_14 ( 5201 ) ) {
V_5 . V_37 [ 3 ] = F_17 ( 2 ) ;
} else {
ERROR ( V_30 -> V_36 ) ;
return V_11 ;
}
}
V_3 = F_3 ( V_2 , & V_5 , sizeof( V_5 ) , V_38 ) ;
if ( V_3 < 0 ) {
ERROR ( V_3 ) ;
return V_11 ;
}
return V_12 ;
}
int F_20 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 V_5 ;
char V_13 [] = L_5 ;
V_3 = F_5 ( V_2 , & V_5 , sizeof( V_5 ) , V_38 ) ;
if ( V_3 < 0 ) {
ERROR ( V_3 ) ;
return V_11 ;
}
F_6 ( V_13 , sizeof( V_13 ) , F_17 ( V_5 . V_37 [ 0 ] ) ,
F_17 ( V_5 . V_37 [ 3 ] ) ) ;
return V_12 ;
}
