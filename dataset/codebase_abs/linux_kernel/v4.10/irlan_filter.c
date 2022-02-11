void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 (self != NULL, return;) ;
F_2 (self->magic == IRLAN_MAGIC, return;) ;
if ( ( V_2 -> V_5 . V_6 == V_7 ) &&
( V_2 -> V_5 . V_8 == V_9 ) )
{
F_3 ( L_1 ) ;
V_2 -> V_5 . V_10 [ 0 ] = 0x40 ;
V_2 -> V_5 . V_10 [ 1 ] = 0x00 ;
V_2 -> V_5 . V_10 [ 2 ] = 0x00 ;
V_2 -> V_5 . V_10 [ 3 ] = 0x00 ;
if ( V_2 -> V_5 . V_11 == V_12 ) {
V_2 -> V_5 . V_10 [ 4 ] =
V_2 -> V_5 . V_13 & 0xff ;
V_2 -> V_5 . V_10 [ 5 ] =
( V_2 -> V_5 . V_13 >> 8 ) & 0xff ;
} else {
F_4 ( V_2 -> V_5 . V_10 + 4 , 1 ) ;
F_4 ( V_2 -> V_5 . V_10 + 5 , 1 ) ;
}
V_4 -> V_14 [ 0 ] = 0x00 ;
V_4 -> V_14 [ 1 ] = 0x03 ;
F_5 ( V_4 , L_2 , L_3 ) ;
F_6 ( V_4 , L_4 , 0x0001 ) ;
F_7 ( V_4 , L_5 ,
V_2 -> V_5 . V_10 , 6 ) ;
return;
}
if ( ( V_2 -> V_5 . V_6 == V_7 ) &&
( V_2 -> V_5 . V_15 == V_16 ) )
{
F_3 ( L_6 ) ;
V_4 -> V_14 [ 0 ] = 0x00 ;
V_4 -> V_14 [ 1 ] = 0x00 ;
return;
}
if ( ( V_2 -> V_5 . V_6 == V_7 ) &&
( V_2 -> V_5 . V_15 == V_17 ) )
{
F_3 ( L_7 ) ;
V_4 -> V_14 [ 0 ] = 0x00 ;
V_4 -> V_14 [ 1 ] = 0x00 ;
return;
}
if ( ( V_2 -> V_5 . V_6 == V_18 ) &&
( V_2 -> V_5 . V_15 == V_16 ) )
{
F_3 ( L_8 ) ;
V_4 -> V_14 [ 0 ] = 0x00 ;
V_4 -> V_14 [ 1 ] = 0x00 ;
return;
}
if ( ( V_2 -> V_5 . V_6 == V_18 ) &&
( V_2 -> V_5 . V_15 == V_17 ) )
{
F_3 ( L_9 ) ;
V_4 -> V_14 [ 0 ] = 0x00 ;
V_4 -> V_14 [ 1 ] = 0x00 ;
return;
}
if ( ( V_2 -> V_5 . V_6 == V_19 ) &&
( V_2 -> V_5 . V_15 == V_16 ) )
{
F_3 ( L_10 ) ;
V_4 -> V_14 [ 0 ] = 0x00 ;
V_4 -> V_14 [ 1 ] = 0x00 ;
return;
}
if ( ( V_2 -> V_5 . V_6 == V_19 ) &&
( V_2 -> V_5 . V_15 == V_17 ) )
{
F_3 ( L_11 ) ;
V_4 -> V_14 [ 0 ] = 0x00 ;
V_4 -> V_14 [ 1 ] = 0x00 ;
return;
}
if ( ( V_2 -> V_5 . V_6 == V_19 ) &&
( V_2 -> V_5 . V_8 == V_20 ) )
{
F_3 ( L_12 ) ;
V_4 -> V_14 [ 0 ] = 0x00 ;
V_4 -> V_14 [ 1 ] = 0x02 ;
F_5 ( V_4 , L_2 , L_3 ) ;
F_6 ( V_4 , L_4 , 16 ) ;
return;
}
V_4 -> V_14 [ 0 ] = 0x00 ;
V_4 -> V_14 [ 1 ] = 0x00 ;
F_3 ( L_13 ) ;
}
void F_8 ( struct V_1 * V_2 , char * V_21 , char * V_22 )
{
F_2 (self != NULL, return;) ;
F_2 (self->magic == IRLAN_MAGIC, return;) ;
F_3 ( L_14 , V_21 , V_22 ) ;
if ( strcmp ( V_21 , L_15 ) == 0 ) {
V_2 -> V_23 = TRUE ;
return;
}
if ( strcmp ( V_21 , L_16 ) == 0 ) {
if ( strcmp ( V_22 , L_17 ) == 0 ) {
V_2 -> V_5 . V_6 = V_7 ;
return;
}
if ( strcmp ( V_22 , L_18 ) == 0 ) {
V_2 -> V_5 . V_6 = V_19 ;
return;
}
if ( strcmp ( V_22 , L_19 ) == 0 ) {
V_2 -> V_5 . V_6 = V_18 ;
return;
}
}
if ( strcmp ( V_21 , L_2 ) == 0 ) {
if ( strcmp ( V_22 , L_20 ) == 0 ) {
V_2 -> V_5 . V_15 = V_24 ;
return;
}
if ( strcmp ( V_22 , L_21 ) == 0 ) {
V_2 -> V_5 . V_15 = V_16 ;
return;
}
if ( strcmp ( V_22 , L_3 ) == 0 ) {
V_2 -> V_5 . V_15 = V_16 ;
return;
}
}
if ( strcmp ( V_21 , L_22 ) == 0 ) {
if ( strcmp ( V_22 , L_23 ) == 0 ) {
V_2 -> V_5 . V_8 = V_9 ;
return;
}
if ( strcmp ( V_22 , L_24 ) == 0 ) {
V_2 -> V_5 . V_8 = V_20 ;
return;
}
}
}
void F_9 ( struct V_25 * V_26 , int V_6 )
{
static struct {
int V_27 ;
const char * V_28 ;
} V_29 [] = {
F_10 ( V_7 , L_17 ) ,
F_10 ( V_30 , L_25 ) ,
F_10 ( V_31 , L_26 ) ,
F_10 ( V_32 , L_27 ) ,
F_10 ( V_19 , L_18 ) ,
F_10 ( V_18 , L_19 ) ,
F_10 ( V_33 , L_28 ) ,
F_10 ( 0 , NULL)
} , * V_34 ;
for ( V_34 = V_29 ; V_34 -> V_28 ; V_34 ++ ) {
if ( V_6 & V_34 -> V_27 )
F_11 ( V_26 , L_29 , V_34 -> V_28 ) ;
}
F_12 ( V_26 , '\n' ) ;
}
