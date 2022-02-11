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
T_7 int F_14 ( T_2 * V_6 V_7 , void * T_3 V_7 )
{
return V_28 + 4 ;
}
T_7 int F_15 ( T_2 * V_6 V_7 , void * T_3 , T_4 * V_9 , T_5 T_6 V_7 )
{
T_5 V_29 = F_16 ( T_3 ) ;
V_9 [ 0 ] = 0 ;
V_9 [ 1 ] = V_30 ;
V_9 [ 2 ] = 0 ;
V_9 [ 3 ] = V_28 ;
V_9 [ 4 ] = ( V_29 & 0xff000000 ) >> 24 ;
V_9 [ 5 ] = ( V_29 & 0x00ff0000 ) >> 16 ;
V_9 [ 6 ] = ( V_29 & 0x0000ff00 ) >> 8 ;
V_9 [ 7 ] = ( V_29 & 0x000000ff ) ;
return F_14 ( V_6 , T_3 ) ;
}
T_8 * F_17 ( T_2 * V_6 , const char * V_31 , T_9 V_32 )
{
const T_10 * V_33 [] = {
& V_34 ,
& V_35 ,
& V_36 ,
& V_37 ,
& V_38 ,
& V_39 ,
NULL
} ;
return F_18 ( V_6 , V_31 , V_32 , V_33 ) ;
}
T_8 *
F_18 ( T_2 * V_6 , const char * V_31 , T_9 V_32 , const T_10 * * V_40 )
{
T_8 * V_41 ;
const T_10 * * V_42 = V_40 ;
int V_43 = 0 ;
int V_44 , V_45 , V_46 , V_47 ;
T_4 * V_48 ;
F_19 ( V_31 != NULL ) ;
F_19 ( ( V_32 == V_49 ) || ( V_32 == V_50 ) || ( V_32 == V_51 ) ) ;
V_41 = ( T_8 * ) F_20 ( sizeof( T_8 ) ) ;
V_44 = ( int ) strlen ( V_31 ) ;
V_45 = ( ( V_44 + 3 ) & 0xfffffffc ) ;
V_43 += ( V_45 + 4 ) ;
while ( * V_42 ) {
V_43 += ( * V_42 ) -> V_52 ( V_6 , ( * V_42 ) -> T_3 ) ;
V_42 ++ ;
}
V_43 += 4 ;
V_41 -> V_9 = ( T_4 * ) F_21 ( V_43 ) ;
V_41 -> V_53 = V_43 ;
V_48 = V_41 -> V_9 ;
V_46 = V_41 -> V_53 ;
V_48 [ 0 ] = ( V_32 & 0xff00 ) >> 8 ;
V_48 [ 1 ] = V_32 & 0x00ff ;
V_48 [ 2 ] = ( V_45 & 0xff00 ) >> 8 ;
V_48 [ 3 ] = V_45 & 0x00ff ;
memcpy ( V_48 + 4 , V_31 , V_44 ) ;
V_48 += ( V_45 + 4 ) ;
V_46 -= ( V_45 + 4 ) ;
V_42 = V_40 ;
while ( * V_42 ) {
V_47 = ( * V_42 ) -> V_54 ( V_6 , ( * V_42 ) -> T_3 , V_48 , V_46 ) ;
V_48 += V_47 ;
V_46 -= V_47 ;
V_42 ++ ;
}
return V_41 ;
}
T_11
F_22 ( const char * V_55 )
{
T_12 * V_56 = F_23 ( V_55 ) ;
V_57 = F_24 ( V_57 , V_56 ) ;
return F_25 ( V_56 ) ;
}
static
T_11 F_26 ( T_13 V_58 , T_13 V_59 )
{
return F_27 ( ( const char * ) V_58 , ( const char * ) V_59 ) ;
}
T_14 *
F_28 ( void )
{
V_57 = F_29 ( V_57 , F_26 ) ;
return V_57 ;
}
void F_30 ( void )
{
}
static void
F_31 ( T_15 V_60 , T_15 T_3 V_7 )
{
F_32 ( V_60 ) ;
}
void F_33 ( void )
{
F_34 ( V_57 , F_31 , NULL ) ;
F_35 ( V_57 ) ;
}
