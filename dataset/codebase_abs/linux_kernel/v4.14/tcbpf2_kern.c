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
struct V_4 V_5 ;
struct V_14 V_15 ;
int V_3 ;
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
V_15 . V_16 = F_8 ( 123 ) ;
V_3 = F_9 ( V_2 , & V_15 , sizeof( V_15 ) ) ;
if ( V_3 < 0 ) {
ERROR ( V_3 ) ;
return V_11 ;
}
return V_12 ;
}
int F_10 ( struct V_1 * V_2 )
{
char V_13 [] = L_2 ;
struct V_4 V_5 ;
struct V_14 V_15 ;
T_1 V_16 ;
int V_3 ;
V_3 = F_5 ( V_2 , & V_5 , sizeof( V_5 ) , 0 ) ;
if ( V_3 < 0 ) {
ERROR ( V_3 ) ;
return V_11 ;
}
V_3 = F_11 ( V_2 , & V_15 , sizeof( V_15 ) ) ;
if ( V_3 < 0 ) {
ERROR ( V_3 ) ;
return V_11 ;
}
V_16 = F_12 ( V_15 . V_16 ) ;
F_6 ( V_13 , sizeof( V_13 ) ,
V_5 . V_7 , V_5 . V_6 , V_16 ) ;
return V_12 ;
}
int F_13 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 V_5 ;
struct V_17 V_15 ;
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
V_15 . V_18 = 0x800FF ;
V_3 = F_9 ( V_2 , & V_15 , sizeof( V_15 ) ) ;
if ( V_3 < 0 ) {
ERROR ( V_3 ) ;
return V_11 ;
}
return V_12 ;
}
int F_14 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 V_5 ;
struct V_17 V_15 ;
char V_13 [] = L_3 ;
V_3 = F_5 ( V_2 , & V_5 , sizeof( V_5 ) , 0 ) ;
if ( V_3 < 0 ) {
ERROR ( V_3 ) ;
return V_11 ;
}
V_3 = F_11 ( V_2 , & V_15 , sizeof( V_15 ) ) ;
if ( V_3 < 0 ) {
ERROR ( V_3 ) ;
return V_11 ;
}
F_6 ( V_13 , sizeof( V_13 ) ,
V_5 . V_7 , V_5 . V_6 , V_15 . V_18 ) ;
return V_12 ;
}
int F_15 ( struct V_1 * V_2 )
{
int V_3 , V_19 ;
struct V_4 V_5 ;
struct V_20 V_21 ;
F_2 ( & V_5 , 0x0 , sizeof( V_5 ) ) ;
V_5 . V_6 = 0xac100164 ;
V_5 . V_7 = 2 ;
V_5 . V_8 = 0 ;
V_5 . V_9 = 64 ;
F_2 ( & V_21 , 0x0 , sizeof( V_21 ) ) ;
V_21 . V_22 = 0x102 ;
V_21 . type = 0x08 ;
V_21 . V_23 = 0 ;
V_21 . V_24 = 0 ;
V_21 . V_25 = 0 ;
V_21 . V_26 = 2 ;
* ( int * ) & V_21 . V_27 = 0xdeadbeef ;
V_3 = F_3 ( V_2 , & V_5 , sizeof( V_5 ) , V_10 ) ;
if ( V_3 < 0 ) {
ERROR ( V_3 ) ;
return V_11 ;
}
V_3 = F_9 ( V_2 , & V_21 , sizeof( V_21 ) ) ;
if ( V_3 < 0 ) {
ERROR ( V_3 ) ;
return V_11 ;
}
return V_12 ;
}
int F_16 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 V_5 ;
struct V_20 V_21 ;
char V_13 [] = L_4 ;
V_3 = F_5 ( V_2 , & V_5 , sizeof( V_5 ) , 0 ) ;
if ( V_3 < 0 ) {
ERROR ( V_3 ) ;
return V_11 ;
}
V_3 = F_11 ( V_2 , & V_21 , sizeof( V_21 ) ) ;
if ( V_3 < 0 ) {
ERROR ( V_3 ) ;
return V_11 ;
}
F_6 ( V_13 , sizeof( V_13 ) ,
V_5 . V_7 , V_5 . V_6 , V_21 . V_22 ) ;
return V_12 ;
}
int F_17 ( struct V_1 * V_2 )
{
struct V_4 V_5 = {} ;
void * V_28 = ( void * ) ( long ) V_2 -> V_28 ;
struct V_29 * V_30 = V_28 ;
struct V_31 * V_32 = V_28 + sizeof( * V_30 ) ;
void * V_33 = ( void * ) ( long ) V_2 -> V_33 ;
int V_3 ;
if ( V_28 + sizeof( * V_30 ) + sizeof( * V_32 ) > V_33 ) {
ERROR ( 1 ) ;
return V_11 ;
}
V_5 . V_9 = 64 ;
if ( V_30 -> V_34 == V_35 ) {
V_5 . V_6 = 0xac100164 ;
} else {
if ( V_30 -> V_34 != V_36 || V_30 -> V_37 != 5 )
return V_11 ;
if ( V_32 -> V_38 == F_18 ( 5200 ) )
V_5 . V_6 = 0xac100164 ;
else if ( V_32 -> V_38 == F_18 ( 5201 ) )
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
int F_19 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 V_5 ;
char V_13 [] = L_5 ;
V_3 = F_5 ( V_2 , & V_5 , sizeof( V_5 ) , 0 ) ;
if ( V_3 < 0 ) {
ERROR ( V_3 ) ;
return V_11 ;
}
F_6 ( V_13 , sizeof( V_13 ) , V_5 . V_6 ) ;
return V_12 ;
}
int F_20 ( struct V_1 * V_2 )
{
struct V_4 V_5 = {} ;
void * V_28 = ( void * ) ( long ) V_2 -> V_28 ;
struct V_29 * V_30 = V_28 ;
struct V_31 * V_32 = V_28 + sizeof( * V_30 ) ;
void * V_33 = ( void * ) ( long ) V_2 -> V_33 ;
int V_3 ;
if ( V_28 + sizeof( * V_30 ) + sizeof( * V_32 ) > V_33 ) {
ERROR ( 1 ) ;
return V_11 ;
}
V_5 . V_39 [ 0 ] = F_21 ( 0x2401db00 ) ;
V_5 . V_9 = 64 ;
if ( V_30 -> V_34 == V_35 ) {
V_5 . V_39 [ 3 ] = F_21 ( 1 ) ;
} else {
if ( V_30 -> V_34 != V_36 || V_30 -> V_37 != 5 ) {
ERROR ( V_30 -> V_34 ) ;
return V_11 ;
}
if ( V_32 -> V_38 == F_18 ( 5200 ) ) {
V_5 . V_39 [ 3 ] = F_21 ( 1 ) ;
} else if ( V_32 -> V_38 == F_18 ( 5201 ) ) {
V_5 . V_39 [ 3 ] = F_21 ( 2 ) ;
} else {
ERROR ( V_32 -> V_38 ) ;
return V_11 ;
}
}
V_3 = F_3 ( V_2 , & V_5 , sizeof( V_5 ) , V_40 ) ;
if ( V_3 < 0 ) {
ERROR ( V_3 ) ;
return V_11 ;
}
return V_12 ;
}
int F_22 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 V_5 ;
char V_13 [] = L_6 ;
V_3 = F_5 ( V_2 , & V_5 , sizeof( V_5 ) , V_40 ) ;
if ( V_3 < 0 ) {
ERROR ( V_3 ) ;
return V_11 ;
}
F_6 ( V_13 , sizeof( V_13 ) , F_21 ( V_5 . V_39 [ 0 ] ) ,
F_21 ( V_5 . V_39 [ 3 ] ) ) ;
return V_12 ;
}
int F_23 ( struct V_1 * V_2 )
{
struct V_4 V_5 = {} ;
void * V_28 = ( void * ) ( long ) V_2 -> V_28 ;
struct V_41 * V_30 = V_28 ;
struct V_31 * V_32 = V_28 + sizeof( * V_30 ) ;
void * V_33 = ( void * ) ( long ) V_2 -> V_33 ;
int V_3 ;
if ( V_28 + sizeof( * V_30 ) + sizeof( * V_32 ) > V_33 ) {
ERROR ( 1 ) ;
return V_11 ;
}
V_5 . V_39 [ 0 ] = F_21 ( 0x2401db00 ) ;
V_5 . V_9 = 64 ;
if ( V_30 -> V_42 == V_43 ) {
V_5 . V_39 [ 3 ] = F_21 ( 1 ) ;
} else {
if ( V_30 -> V_42 != V_44 ) {
ERROR ( V_30 -> V_42 ) ;
return V_11 ;
}
if ( V_32 -> V_38 == F_18 ( 5200 ) ) {
V_5 . V_39 [ 3 ] = F_21 ( 1 ) ;
} else if ( V_32 -> V_38 == F_18 ( 5201 ) ) {
V_5 . V_39 [ 3 ] = F_21 ( 2 ) ;
} else {
ERROR ( V_32 -> V_38 ) ;
return V_11 ;
}
}
V_3 = F_3 ( V_2 , & V_5 , sizeof( V_5 ) , V_40 ) ;
if ( V_3 < 0 ) {
ERROR ( V_3 ) ;
return V_11 ;
}
return V_12 ;
}
int F_24 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 V_5 ;
char V_13 [] = L_6 ;
V_3 = F_5 ( V_2 , & V_5 , sizeof( V_5 ) , V_40 ) ;
if ( V_3 < 0 ) {
ERROR ( V_3 ) ;
return V_11 ;
}
F_6 ( V_13 , sizeof( V_13 ) , F_21 ( V_5 . V_39 [ 0 ] ) ,
F_21 ( V_5 . V_39 [ 3 ] ) ) ;
return V_12 ;
}
