T_1 T_2 F_1 ( T_1 V_1 , unsigned char const * V_2 , T_3 V_3 )
{
return F_2 ( V_1 , V_2 , V_3 , NULL , V_4 ) ;
}
T_1 T_2 F_3 ( T_1 V_1 , unsigned char const * V_2 , T_3 V_3 )
{
return F_2 ( V_1 , V_2 , V_3 , NULL , V_5 ) ;
}
T_1 T_2 F_1 ( T_1 V_1 , unsigned char const * V_2 , T_3 V_3 )
{
return F_2 ( V_1 , V_2 , V_3 ,
( const T_1 ( * ) [ 256 ] ) V_6 , V_4 ) ;
}
T_1 T_2 F_3 ( T_1 V_1 , unsigned char const * V_2 , T_3 V_3 )
{
return F_2 ( V_1 , V_2 , V_3 ,
( const T_1 ( * ) [ 256 ] ) V_7 , V_5 ) ;
}
static T_1 T_4 F_4 ( T_1 V_8 , T_1 V_9 , T_1 V_10 )
{
T_1 V_11 = V_8 & 1 ? V_9 : 0 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < 31 ; V_12 ++ ) {
V_11 = ( V_11 >> 1 ) ^ ( V_11 & 1 ? V_10 : 0 ) ;
V_8 >>= 1 ;
V_11 ^= V_8 & 1 ? V_9 : 0 ;
}
return V_11 ;
}
static T_1 T_4 F_5 ( T_1 V_1 , T_3 V_3 ,
T_1 V_13 )
{
T_1 V_14 = V_13 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < 8 * ( int ) ( V_3 & 3 ) ; V_12 ++ )
V_1 = ( V_1 >> 1 ) ^ ( V_1 & 1 ? V_13 : 0 ) ;
V_3 >>= 2 ;
if ( ! V_3 )
return V_1 ;
for (; ; ) {
if ( V_3 & 1 )
V_1 = F_4 ( V_1 , V_14 , V_13 ) ;
V_3 >>= 1 ;
if ( ! V_3 )
break;
V_14 = F_4 ( V_14 , V_14 , V_13 ) ;
}
return V_1 ;
}
T_1 T_4 F_6 ( T_1 V_1 , T_3 V_3 )
{
return F_5 ( V_1 , V_3 , V_4 ) ;
}
T_1 T_4 F_7 ( T_1 V_1 , T_3 V_3 )
{
return F_5 ( V_1 , V_3 , V_5 ) ;
}
T_1 T_2 F_8 ( T_1 V_1 , unsigned char const * V_2 , T_3 V_3 )
{
return F_9 ( V_1 , V_2 , V_3 , NULL , V_15 ) ;
}
T_1 T_2 F_8 ( T_1 V_1 , unsigned char const * V_2 , T_3 V_3 )
{
return F_9 ( V_1 , V_2 , V_3 ,
( const T_1 ( * ) [ 256 ] ) V_16 , V_15 ) ;
}
