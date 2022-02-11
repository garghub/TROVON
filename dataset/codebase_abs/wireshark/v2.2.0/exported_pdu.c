static int F_1 ( const T_1 * V_1 )
{
if ( V_1 -> type == V_2 ) {
return 4 + V_3 ;
} else if( V_1 -> type == V_4 ) {
return 4 + V_5 ;
}
return 0 ;
}
static int F_2 ( T_2 * V_6 , void * T_3 V_7 )
{
return F_1 ( & V_6 -> V_8 ) ;
}
static int F_3 ( T_2 * V_6 , void * T_3 V_7 , T_4 * V_9 , T_5 T_6 V_7 )
{
if( V_6 -> V_8 . type == V_2 ) {
V_9 [ 0 ] = 0 ;
V_9 [ 1 ] = V_10 ;
V_9 [ 2 ] = 0 ;
V_9 [ 3 ] = V_3 ;
memcpy ( V_9 + 4 , V_6 -> V_8 . T_3 , V_3 ) ;
return 4 + V_3 ;
} else if( V_6 -> V_8 . type == V_4 ) {
V_9 [ 0 ] = 0 ;
V_9 [ 1 ] = V_11 ;
V_9 [ 2 ] = 0 ;
V_9 [ 3 ] = V_5 ;
memcpy ( V_9 + 4 , V_6 -> V_8 . T_3 , V_5 ) ;
return 4 + V_5 ;
}
return 0 ;
}
static int F_4 ( T_2 * V_6 , void * T_3 V_7 )
{
return F_1 ( & V_6 -> V_12 ) ;
}
static int F_5 ( T_2 * V_6 , void * T_3 V_7 , T_4 * V_9 , T_5 T_6 V_7 )
{
if( V_6 -> V_12 . type == V_2 ) {
V_9 [ 0 ] = 0 ;
V_9 [ 1 ] = V_13 ;
V_9 [ 2 ] = 0 ;
V_9 [ 3 ] = V_3 ;
memcpy ( V_9 + 4 , V_6 -> V_12 . T_3 , V_3 ) ;
return 4 + V_3 ;
} else if( V_6 -> V_12 . type == V_4 ) {
V_9 [ 0 ] = 0 ;
V_9 [ 1 ] = V_14 ;
V_9 [ 2 ] = 0 ;
V_9 [ 3 ] = V_5 ;
memcpy ( V_9 + 4 , V_6 -> V_12 . T_3 , V_5 ) ;
return 4 + V_5 ;
}
return 0 ;
}
static int F_6 ( T_2 * V_6 V_7 , void * T_3 V_7 )
{
return V_15 + 4 ;
}
static int F_7 ( T_2 * V_6 , void * T_3 , T_4 * V_9 , T_5 T_6 V_7 )
{
V_9 [ 0 ] = 0 ;
V_9 [ 1 ] = V_16 ;
V_9 [ 2 ] = 0 ;
V_9 [ 3 ] = V_17 ;
V_9 [ 4 ] = ( V_6 -> V_18 & 0xff000000 ) >> 24 ;
V_9 [ 5 ] = ( V_6 -> V_18 & 0x00ff0000 ) >> 16 ;
V_9 [ 6 ] = ( V_6 -> V_18 & 0x0000ff00 ) >> 8 ;
V_9 [ 7 ] = ( V_6 -> V_18 & 0x000000ff ) ;
return F_6 ( V_6 , T_3 ) ;
}
static int F_8 ( T_2 * V_6 V_7 , void * T_3 V_7 )
{
return V_15 + 4 ;
}
static int F_9 ( T_5 V_19 , T_4 V_20 , T_4 * V_9 , T_5 T_6 V_7 )
{
V_9 [ 0 ] = 0 ;
V_9 [ 1 ] = V_20 ;
V_9 [ 2 ] = 0 ;
V_9 [ 3 ] = V_15 ;
V_9 [ 4 ] = ( V_19 & 0xff000000 ) >> 24 ;
V_9 [ 5 ] = ( V_19 & 0x00ff0000 ) >> 16 ;
V_9 [ 6 ] = ( V_19 & 0x0000ff00 ) >> 8 ;
V_9 [ 7 ] = ( V_19 & 0x000000ff ) ;
return V_15 + 4 ;
}
static int F_10 ( T_2 * V_6 , void * T_3 V_7 , T_4 * V_9 , T_5 T_6 )
{
return F_9 ( V_6 -> V_21 , V_22 , V_9 , T_6 ) ;
}
static int F_11 ( T_2 * V_6 , void * T_3 V_7 , T_4 * V_9 , T_5 T_6 )
{
return F_9 ( V_6 -> V_23 , V_24 , V_9 , T_6 ) ;
}
static int F_12 ( T_2 * V_6 V_7 , void * T_3 V_7 )
{
return V_25 + 4 ;
}
static int F_13 ( T_2 * V_6 , void * T_3 , T_4 * V_9 , T_5 T_6 V_7 )
{
V_9 [ 0 ] = 0 ;
V_9 [ 1 ] = V_26 ;
V_9 [ 2 ] = 0 ;
V_9 [ 3 ] = V_25 ;
V_9 [ 4 ] = ( V_6 -> V_27 & 0xff000000 ) >> 24 ;
V_9 [ 5 ] = ( V_6 -> V_27 & 0x00ff0000 ) >> 16 ;
V_9 [ 6 ] = ( V_6 -> V_27 & 0x0000ff00 ) >> 8 ;
V_9 [ 7 ] = ( V_6 -> V_27 & 0x000000ff ) ;
return F_12 ( V_6 , T_3 ) ;
}
T_7 * F_14 ( T_2 * V_6 , const char * V_28 , T_8 V_29 )
{
const T_9 * V_30 [] = {
& V_31 ,
& V_32 ,
& V_33 ,
& V_34 ,
& V_35 ,
& V_36 ,
NULL
} ;
return F_15 ( V_6 , V_28 , V_29 , V_30 ) ;
}
T_7 *
F_15 ( T_2 * V_6 , const char * V_28 , T_8 V_29 , const T_9 * * V_37 )
{
T_7 * V_38 ;
const T_9 * * V_39 = V_37 ;
int V_40 = 0 ;
int V_41 , V_42 , V_43 , V_44 ;
T_4 * V_45 ;
F_16 ( V_28 != NULL ) ;
F_16 ( ( V_29 == V_46 ) || ( V_29 == V_47 ) || ( V_29 == V_48 ) ) ;
V_38 = ( T_7 * ) F_17 ( sizeof( T_7 ) ) ;
V_41 = ( int ) strlen ( V_28 ) ;
V_42 = ( ( V_41 + 3 ) & 0xfffffffc ) ;
V_40 += ( V_42 + 4 ) ;
while ( * V_39 ) {
V_40 += ( * V_39 ) -> V_49 ( V_6 , ( * V_39 ) -> T_3 ) ;
V_39 ++ ;
}
V_40 += 4 ;
V_38 -> V_9 = ( T_4 * ) F_18 ( V_40 ) ;
V_38 -> V_50 = V_40 ;
V_45 = V_38 -> V_9 ;
V_43 = V_38 -> V_50 ;
V_45 [ 0 ] = ( V_29 & 0xff00 ) >> 8 ;
V_45 [ 1 ] = V_29 & 0x00ff ;
V_45 [ 2 ] = ( V_42 & 0xff00 ) >> 8 ;
V_45 [ 3 ] = V_42 & 0x00ff ;
memcpy ( V_45 + 4 , V_28 , V_41 ) ;
V_45 += ( V_42 + 4 ) ;
V_43 -= ( V_42 + 4 ) ;
V_39 = V_37 ;
while ( * V_39 ) {
V_44 = ( * V_39 ) -> V_51 ( V_6 , ( * V_39 ) -> T_3 , V_45 , V_43 ) ;
V_45 += V_44 ;
V_43 -= V_44 ;
V_39 ++ ;
}
return V_38 ;
}
T_10
F_19 ( const char * V_52 )
{
T_11 * V_53 = F_20 ( V_52 ) ;
V_54 = F_21 ( V_54 , V_53 ) ;
return F_22 ( V_53 ) ;
}
static
T_10 F_23 ( T_12 V_55 , T_12 V_56 )
{
return F_24 ( ( const char * ) V_55 , ( const char * ) V_56 ) ;
}
T_13 *
F_25 ( void )
{
V_54 = F_26 ( V_54 , F_23 ) ;
return V_54 ;
}
void F_27 ( void )
{
}
