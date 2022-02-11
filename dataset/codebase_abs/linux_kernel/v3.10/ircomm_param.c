int F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 )
{
unsigned long V_5 ;
struct V_6 * V_7 ;
int V_8 ;
F_2 ( 2 , L_1 , V_9 ) ;
F_3 (self != NULL, return -1;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
if ( V_2 -> V_10 == V_11 )
return 0 ;
F_4 ( & V_2 -> V_12 , V_5 ) ;
V_7 = V_2 -> V_13 ;
if ( ! V_7 ) {
V_7 = F_5 ( 256 , V_14 ) ;
if ( ! V_7 ) {
F_6 ( & V_2 -> V_12 , V_5 ) ;
return - V_15 ;
}
F_7 ( V_7 , V_2 -> V_16 ) ;
V_2 -> V_13 = V_7 ;
}
V_8 = F_8 ( V_2 , V_3 , F_9 ( V_7 ) ,
F_10 ( V_7 ) , & V_17 ) ;
if ( V_8 < 0 ) {
F_11 ( L_2 , V_9 ) ;
F_6 ( & V_2 -> V_12 , V_5 ) ;
return - 1 ;
}
F_12 ( V_7 , V_8 ) ;
F_6 ( & V_2 -> V_12 , V_5 ) ;
F_2 ( 2 , L_3 , V_9 , V_7 -> V_18 ) ;
if ( V_4 ) {
F_13 ( & V_2 -> V_19 ) ;
}
return V_8 ;
}
static int F_14 ( void * V_20 , T_2 * V_21 ,
int V_22 )
{
struct V_1 * V_2 = (struct V_1 * ) V_20 ;
T_1 V_10 = ( T_1 ) V_21 -> V_23 . V_24 ;
F_3 (self != NULL, return -1;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
if ( V_22 ) {
V_21 -> V_23 . V_24 = V_2 -> V_25 . V_10 ;
return 0 ;
}
V_10 &= V_2 -> V_10 ;
if ( ! V_10 ) {
F_2 ( 2 ,
L_4 , V_9 ) ;
return - 1 ;
}
F_2 ( 0 , L_5 , V_9 ,
V_10 ) ;
if ( V_10 & V_26 )
V_2 -> V_25 . V_10 = V_26 ;
else if ( V_10 & V_27 )
V_2 -> V_25 . V_10 = V_27 ;
else if ( V_10 & V_28 )
V_2 -> V_25 . V_10 = V_28 ;
else if ( V_10 & V_11 )
V_2 -> V_25 . V_10 = V_11 ;
F_2 ( 0 , L_6 , V_9 ,
V_2 -> V_25 . V_10 ) ;
if ( ( V_2 -> V_16 != V_29 ) &&
( ! V_2 -> V_30 ) &&
( V_2 -> V_25 . V_10 != V_11 ) )
{
F_15 ( V_2 ) ;
F_16 ( V_2 ) ;
}
return 0 ;
}
static int F_17 ( void * V_20 , T_2 * V_21 , int V_22 )
{
struct V_1 * V_2 = (struct V_1 * ) V_20 ;
F_3 (self != NULL, return -1;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
if ( V_22 )
V_21 -> V_23 . V_24 = V_31 ;
else {
V_2 -> V_25 . V_32 = ( T_1 ) V_21 -> V_23 . V_24 ;
F_2 ( 0 , L_7 , V_9 ,
V_2 -> V_25 . V_32 ) ;
}
return 0 ;
}
static int F_18 ( void * V_20 , T_2 * V_21 , int V_22 )
{
struct V_1 * V_2 = (struct V_1 * ) V_20 ;
F_3 (self != NULL, return -1;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
if ( V_22 ) {
F_2 ( 0 , L_8 , V_9 ) ;
} else {
F_2 ( 0 , L_9 , V_9 , V_21 -> V_23 . V_33 ) ;
strncpy ( V_2 -> V_25 . V_34 , V_21 -> V_23 . V_33 , 32 ) ;
}
return 0 ;
}
static int F_19 ( void * V_20 , T_2 * V_21 , int V_22 )
{
struct V_1 * V_2 = (struct V_1 * ) V_20 ;
F_3 (self != NULL, return -1;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
if ( V_22 )
V_21 -> V_23 . V_24 = V_2 -> V_25 . V_35 ;
else
V_2 -> V_25 . V_35 = V_21 -> V_23 . V_24 ;
F_2 ( 2 , L_10 , V_9 , V_21 -> V_23 . V_24 ) ;
return 0 ;
}
static int F_20 ( void * V_20 , T_2 * V_21 ,
int V_22 )
{
struct V_1 * V_2 = (struct V_1 * ) V_20 ;
F_3 (self != NULL, return -1;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
if ( V_22 )
V_21 -> V_23 . V_24 = V_2 -> V_25 . V_36 ;
else
V_2 -> V_25 . V_36 = ( T_1 ) V_21 -> V_23 . V_24 ;
return 0 ;
}
static int F_21 ( void * V_20 , T_2 * V_21 ,
int V_22 )
{
struct V_1 * V_2 = (struct V_1 * ) V_20 ;
F_3 (self != NULL, return -1;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
if ( V_22 )
V_21 -> V_23 . V_24 = V_2 -> V_25 . V_37 ;
else
V_2 -> V_25 . V_37 = ( T_1 ) V_21 -> V_23 . V_24 ;
F_2 ( 1 , L_11 , V_9 , ( T_1 ) V_21 -> V_23 . V_24 ) ;
return 0 ;
}
static int F_22 ( void * V_20 , T_2 * V_21 , int V_22 )
{
struct V_1 * V_2 = (struct V_1 * ) V_20 ;
F_3 (self != NULL, return -1;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
if ( V_22 ) {
V_21 -> V_23 . V_24 = V_2 -> V_25 . V_38 [ 0 ] ;
V_21 -> V_23 . V_24 |= V_2 -> V_25 . V_38 [ 1 ] << 8 ;
} else {
V_2 -> V_25 . V_38 [ 0 ] = ( V_39 ) V_21 -> V_23 . V_24 & 0xff ;
V_2 -> V_25 . V_38 [ 1 ] = ( V_39 ) V_21 -> V_23 . V_24 >> 8 ;
}
F_2 ( 0 , L_12 , V_9 ,
V_21 -> V_23 . V_24 & 0xff , V_21 -> V_23 . V_24 >> 8 ) ;
return 0 ;
}
static int F_23 ( void * V_20 , T_2 * V_21 , int V_22 )
{
struct V_1 * V_2 = (struct V_1 * ) V_20 ;
F_3 (self != NULL, return -1;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
if ( V_22 ) {
V_21 -> V_23 . V_24 = V_2 -> V_25 . V_40 [ 0 ] ;
V_21 -> V_23 . V_24 |= V_2 -> V_25 . V_40 [ 1 ] << 8 ;
} else {
V_2 -> V_25 . V_40 [ 0 ] = ( V_39 ) V_21 -> V_23 . V_24 & 0xff ;
V_2 -> V_25 . V_40 [ 1 ] = ( V_39 ) V_21 -> V_23 . V_24 >> 8 ;
}
F_2 ( 0 , L_13 , V_9 ,
V_21 -> V_23 . V_24 & 0xff , V_21 -> V_23 . V_24 >> 8 ) ;
return 0 ;
}
static int F_24 ( void * V_20 , T_2 * V_21 ,
int V_22 )
{
F_2 ( 2 , L_14 , V_9 ) ;
return 0 ;
}
static int F_25 ( void * V_20 , T_2 * V_21 , int V_22 )
{
struct V_1 * V_2 = (struct V_1 * ) V_20 ;
T_1 V_41 ;
F_3 (self != NULL, return -1;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
if ( V_22 )
V_21 -> V_23 . V_24 = V_2 -> V_25 . V_41 ;
else {
V_41 = ( T_1 ) V_21 -> V_23 . V_24 ;
V_2 -> V_25 . V_42 = 0 ;
if ( V_41 & V_43 )
V_2 -> V_25 . V_42 |= ( V_44 |
V_45 |
V_46 ) ;
if ( V_41 & V_47 )
V_2 -> V_25 . V_42 |= ( V_48 |
V_49 |
V_50 ) ;
if ( V_41 & V_51 )
V_2 -> V_25 . V_42 |= V_52 ;
if ( V_41 & V_53 )
V_2 -> V_25 . V_42 |= V_54 ;
F_26 ( V_2 ) ;
V_2 -> V_25 . V_55 = TRUE ;
}
return 0 ;
}
static int F_27 ( void * V_20 , T_2 * V_21 , int V_22 )
{
struct V_1 * V_2 = (struct V_1 * ) V_20 ;
T_1 V_42 ;
F_2 ( 1 , L_15 , V_9 , ( T_1 ) V_21 -> V_23 . V_24 ) ;
V_42 = ( T_1 ) V_21 -> V_23 . V_24 ;
F_3 (self != NULL, return -1;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
V_2 -> V_25 . V_42 = V_42 ;
if ( V_42 & 0x0f ) {
if ( V_42 & V_52 ) {
F_2 ( 2 , L_16 , V_9 ) ;
}
}
F_26 ( V_2 ) ;
return 0 ;
}
static int F_28 ( void * V_20 , T_2 * V_21 , int V_22 )
{
struct V_1 * V_2 = (struct V_1 * ) V_20 ;
F_3 (self != NULL, return -1;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
if ( ! V_22 ) {
F_1 ( V_2 , V_56 , TRUE ) ;
}
return 0 ;
}
