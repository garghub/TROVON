int F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 )
{
struct V_5 * V_6 ;
unsigned long V_7 ;
struct V_8 * V_9 ;
int V_10 ;
F_2 ( 2 , L_1 , V_11 ) ;
F_3 (self != NULL, return -1;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
V_6 = V_2 -> V_6 ;
if ( ! V_6 )
return 0 ;
if ( V_2 -> V_12 == V_13 )
return 0 ;
F_4 ( & V_2 -> V_14 , V_7 ) ;
V_9 = V_2 -> V_15 ;
if ( ! V_9 ) {
V_9 = F_5 ( 256 , V_16 ) ;
if ( ! V_9 ) {
F_6 ( & V_2 -> V_14 , V_7 ) ;
return - V_17 ;
}
F_7 ( V_9 , V_2 -> V_18 ) ;
V_2 -> V_15 = V_9 ;
}
V_10 = F_8 ( V_2 , V_3 , F_9 ( V_9 ) ,
F_10 ( V_9 ) , & V_19 ) ;
if ( V_10 < 0 ) {
F_11 ( L_2 , V_11 ) ;
F_6 ( & V_2 -> V_14 , V_7 ) ;
return - 1 ;
}
F_12 ( V_9 , V_10 ) ;
F_6 ( & V_2 -> V_14 , V_7 ) ;
F_2 ( 2 , L_3 , V_11 , V_9 -> V_20 ) ;
if ( V_4 ) {
F_13 ( & V_2 -> V_21 ) ;
}
return V_10 ;
}
static int F_14 ( void * V_22 , T_2 * V_23 ,
int V_24 )
{
struct V_1 * V_2 = (struct V_1 * ) V_22 ;
T_1 V_12 = ( T_1 ) V_23 -> V_25 . V_26 ;
F_3 (self != NULL, return -1;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
if ( V_24 ) {
V_23 -> V_25 . V_26 = V_2 -> V_27 . V_12 ;
return 0 ;
}
V_12 &= V_2 -> V_12 ;
if ( ! V_12 ) {
F_2 ( 2 ,
L_4 , V_11 ) ;
return - 1 ;
}
F_2 ( 0 , L_5 , V_11 ,
V_12 ) ;
if ( V_12 & V_28 )
V_2 -> V_27 . V_12 = V_28 ;
else if ( V_12 & V_29 )
V_2 -> V_27 . V_12 = V_29 ;
else if ( V_12 & V_30 )
V_2 -> V_27 . V_12 = V_30 ;
else if ( V_12 & V_13 )
V_2 -> V_27 . V_12 = V_13 ;
F_2 ( 0 , L_6 , V_11 ,
V_2 -> V_27 . V_12 ) ;
if ( ( V_2 -> V_18 != V_31 ) &&
( ! V_2 -> V_32 ) &&
( V_2 -> V_27 . V_12 != V_13 ) )
{
F_15 ( V_2 ) ;
F_16 ( V_2 ) ;
}
return 0 ;
}
static int F_17 ( void * V_22 , T_2 * V_23 , int V_24 )
{
struct V_1 * V_2 = (struct V_1 * ) V_22 ;
F_3 (self != NULL, return -1;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
if ( V_24 )
V_23 -> V_25 . V_26 = V_33 ;
else {
V_2 -> V_27 . V_34 = ( T_1 ) V_23 -> V_25 . V_26 ;
F_2 ( 0 , L_7 , V_11 ,
V_2 -> V_27 . V_34 ) ;
}
return 0 ;
}
static int F_18 ( void * V_22 , T_2 * V_23 , int V_24 )
{
struct V_1 * V_2 = (struct V_1 * ) V_22 ;
F_3 (self != NULL, return -1;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
if ( V_24 ) {
F_2 ( 0 , L_8 , V_11 ) ;
} else {
F_2 ( 0 , L_9 , V_11 , V_23 -> V_25 . V_35 ) ;
strncpy ( V_2 -> V_27 . V_36 , V_23 -> V_25 . V_35 , 32 ) ;
}
return 0 ;
}
static int F_19 ( void * V_22 , T_2 * V_23 , int V_24 )
{
struct V_1 * V_2 = (struct V_1 * ) V_22 ;
F_3 (self != NULL, return -1;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
if ( V_24 )
V_23 -> V_25 . V_26 = V_2 -> V_27 . V_37 ;
else
V_2 -> V_27 . V_37 = V_23 -> V_25 . V_26 ;
F_2 ( 2 , L_10 , V_11 , V_23 -> V_25 . V_26 ) ;
return 0 ;
}
static int F_20 ( void * V_22 , T_2 * V_23 ,
int V_24 )
{
struct V_1 * V_2 = (struct V_1 * ) V_22 ;
F_3 (self != NULL, return -1;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
if ( V_24 )
V_23 -> V_25 . V_26 = V_2 -> V_27 . V_38 ;
else
V_2 -> V_27 . V_38 = ( T_1 ) V_23 -> V_25 . V_26 ;
return 0 ;
}
static int F_21 ( void * V_22 , T_2 * V_23 ,
int V_24 )
{
struct V_1 * V_2 = (struct V_1 * ) V_22 ;
F_3 (self != NULL, return -1;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
if ( V_24 )
V_23 -> V_25 . V_26 = V_2 -> V_27 . V_39 ;
else
V_2 -> V_27 . V_39 = ( T_1 ) V_23 -> V_25 . V_26 ;
F_2 ( 1 , L_11 , V_11 , ( T_1 ) V_23 -> V_25 . V_26 ) ;
return 0 ;
}
static int F_22 ( void * V_22 , T_2 * V_23 , int V_24 )
{
struct V_1 * V_2 = (struct V_1 * ) V_22 ;
F_3 (self != NULL, return -1;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
if ( V_24 ) {
V_23 -> V_25 . V_26 = V_2 -> V_27 . V_40 [ 0 ] ;
V_23 -> V_25 . V_26 |= V_2 -> V_27 . V_40 [ 1 ] << 8 ;
} else {
V_2 -> V_27 . V_40 [ 0 ] = ( V_41 ) V_23 -> V_25 . V_26 & 0xff ;
V_2 -> V_27 . V_40 [ 1 ] = ( V_41 ) V_23 -> V_25 . V_26 >> 8 ;
}
F_2 ( 0 , L_12 , V_11 ,
V_23 -> V_25 . V_26 & 0xff , V_23 -> V_25 . V_26 >> 8 ) ;
return 0 ;
}
static int F_23 ( void * V_22 , T_2 * V_23 , int V_24 )
{
struct V_1 * V_2 = (struct V_1 * ) V_22 ;
F_3 (self != NULL, return -1;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
if ( V_24 ) {
V_23 -> V_25 . V_26 = V_2 -> V_27 . V_42 [ 0 ] ;
V_23 -> V_25 . V_26 |= V_2 -> V_27 . V_42 [ 1 ] << 8 ;
} else {
V_2 -> V_27 . V_42 [ 0 ] = ( V_41 ) V_23 -> V_25 . V_26 & 0xff ;
V_2 -> V_27 . V_42 [ 1 ] = ( V_41 ) V_23 -> V_25 . V_26 >> 8 ;
}
F_2 ( 0 , L_13 , V_11 ,
V_23 -> V_25 . V_26 & 0xff , V_23 -> V_25 . V_26 >> 8 ) ;
return 0 ;
}
static int F_24 ( void * V_22 , T_2 * V_23 ,
int V_24 )
{
F_2 ( 2 , L_14 , V_11 ) ;
return 0 ;
}
static int F_25 ( void * V_22 , T_2 * V_23 , int V_24 )
{
struct V_1 * V_2 = (struct V_1 * ) V_22 ;
T_1 V_43 ;
F_3 (self != NULL, return -1;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
if ( V_24 )
V_23 -> V_25 . V_26 = V_2 -> V_27 . V_43 ;
else {
V_43 = ( T_1 ) V_23 -> V_25 . V_26 ;
V_2 -> V_27 . V_44 = 0 ;
if ( V_43 & V_45 )
V_2 -> V_27 . V_44 |= ( V_46 |
V_47 |
V_48 ) ;
if ( V_43 & V_49 )
V_2 -> V_27 . V_44 |= ( V_50 |
V_51 |
V_52 ) ;
if ( V_43 & V_53 )
V_2 -> V_27 . V_44 |= V_54 ;
if ( V_43 & V_55 )
V_2 -> V_27 . V_44 |= V_56 ;
F_26 ( V_2 ) ;
V_2 -> V_27 . V_57 = TRUE ;
}
return 0 ;
}
static int F_27 ( void * V_22 , T_2 * V_23 , int V_24 )
{
struct V_1 * V_2 = (struct V_1 * ) V_22 ;
T_1 V_44 ;
F_2 ( 1 , L_15 , V_11 , ( T_1 ) V_23 -> V_25 . V_26 ) ;
V_44 = ( T_1 ) V_23 -> V_25 . V_26 ;
F_3 (self != NULL, return -1;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
V_2 -> V_27 . V_44 = V_44 ;
if ( V_44 & 0x0f ) {
if ( V_44 & V_54 ) {
F_2 ( 2 , L_16 , V_11 ) ;
}
}
F_26 ( V_2 ) ;
return 0 ;
}
static int F_28 ( void * V_22 , T_2 * V_23 , int V_24 )
{
struct V_1 * V_2 = (struct V_1 * ) V_22 ;
F_3 (self != NULL, return -1;) ;
F_3 (self->magic == IRCOMM_TTY_MAGIC, return -1;) ;
if ( ! V_24 ) {
F_1 ( V_2 , V_58 , TRUE ) ;
}
return 0 ;
}
