void F_1 ( T_1 * V_1 , T_1 * V_2 , T_2 * V_3 )
{
* V_1 = V_2 [ * V_3 ] ;
* V_3 += sizeof( * V_1 ) ;
}
void F_2 ( T_3 * V_1 , T_1 * V_2 , T_2 * V_3 )
{
* V_1 = ( V_2 [ * V_3 + 0 ] << 0 ) |
( V_2 [ * V_3 + 1 ] << 8 ) ;
* V_3 += sizeof( * V_1 ) ;
}
void F_3 ( T_4 * V_1 , T_1 * V_2 , T_2 * V_3 )
{
* V_1 = ( V_2 [ * V_3 + 0 ] << 0 ) |
( V_2 [ * V_3 + 1 ] << 8 ) |
( V_2 [ * V_3 + 2 ] << 16 ) |
( V_2 [ * V_3 + 3 ] << 24 ) ;
* V_3 += sizeof( * V_1 ) ;
}
void F_4 ( void * V_1 , T_1 * V_2 , T_2 * V_3 , T_2 V_4 )
{
memcpy ( V_1 , & V_2 [ * V_3 ] , V_4 ) ;
* V_3 += V_4 ;
}
void F_5 ( char * * V_1 , T_1 * V_2 , T_2 * V_3 )
{
* V_1 = F_6 ( ( char * ) & V_2 [ * V_3 ] , V_5 ) ;
* V_3 += strlen ( * V_1 ) + 1 ;
}
void F_7 ( T_1 * V_2 , T_2 * V_3 , T_1 V_1 )
{
V_2 [ * V_3 ] = V_1 ;
* V_3 += sizeof( V_1 ) ;
}
void F_8 ( T_1 * V_2 , T_2 * V_3 , T_3 V_1 )
{
V_2 [ * V_3 + 0 ] = ( T_1 ) ( ( V_1 >> 0 ) & 0xFF ) ;
V_2 [ * V_3 + 1 ] = ( T_1 ) ( ( V_1 >> 8 ) & 0xFF ) ;
* V_3 += sizeof( V_1 ) ;
}
void F_9 ( T_1 * V_2 , T_2 * V_3 , T_4 V_1 )
{
V_2 [ * V_3 + 0 ] = ( T_1 ) ( ( V_1 >> 0 ) & 0xFF ) ;
V_2 [ * V_3 + 1 ] = ( T_1 ) ( ( V_1 >> 8 ) & 0xFF ) ;
V_2 [ * V_3 + 2 ] = ( T_1 ) ( ( V_1 >> 16 ) & 0xFF ) ;
V_2 [ * V_3 + 3 ] = ( T_1 ) ( ( V_1 >> 24 ) & 0xFF ) ;
* V_3 += sizeof( V_1 ) ;
}
void F_10 ( T_1 * V_2 , T_2 * V_3 , const void * V_1 , T_2 V_4 )
{
memcpy ( & V_2 [ * V_3 ] , V_1 , V_4 ) ;
* V_3 += V_4 ;
}
void F_11 ( T_1 * V_2 , T_2 * V_3 , const char * V_1 )
{
if ( V_1 )
{
strcpy ( ( ( char * ) & V_2 [ * V_3 ] ) , V_1 ) ;
* V_3 += strlen ( V_1 ) + 1 ;
}
else
{
F_7 ( V_2 , V_3 , 0 ) ;
}
}
