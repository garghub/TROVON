T_1 *
F_1 ( T_2 * V_1 , T_3 V_2 ,
T_4 V_3 )
{
T_1 * V_4 ;
V_4 = F_2 ( V_1 , T_1 ) ;
V_4 -> V_1 = V_1 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_5 = 0 ;
V_4 -> V_3 = V_3 ? V_3 : 1 ;
V_4 -> V_6 = FALSE ;
V_4 -> V_7 = ( V_8 * ) F_3 ( V_4 -> V_1 ,
V_4 -> V_2 * V_4 -> V_3 ) ;
return V_4 ;
}
T_1 *
F_4 ( T_2 * V_1 , const T_3 V_2 )
{
T_1 * V_4 ;
V_4 = F_1 ( V_1 , V_2 , 1 ) ;
return V_4 ;
}
static void
F_5 ( T_1 * V_4 , const T_4 V_9 )
{
T_4 V_10 , V_11 ;
V_10 = V_4 -> V_3 ;
V_11 = V_4 -> V_5 + V_9 ;
while ( V_10 < V_11 ) {
V_10 *= 2 ;
}
if ( V_10 == V_4 -> V_3 ) {
return;
}
V_4 -> V_7 = ( V_8 * ) F_6 ( V_4 -> V_1 , V_4 -> V_7 ,
V_10 * V_4 -> V_2 ) ;
V_4 -> V_3 = V_10 ;
}
static void
F_7 ( T_1 * V_4 )
{
if ( V_4 -> V_6 ) {
F_5 ( V_4 , 1 ) ;
memset ( & V_4 -> V_7 [ V_4 -> V_5 * V_4 -> V_2 ] , 0x0 , V_4 -> V_2 ) ;
}
}
void
F_8 ( T_1 * V_4 )
{
V_4 -> V_6 = TRUE ;
F_7 ( V_4 ) ;
}
void
F_9 ( T_1 * V_4 )
{
memset ( V_4 -> V_7 , 0x0 , V_4 -> V_2 * V_4 -> V_5 ) ;
}
void
F_10 ( T_1 * V_4 , const void * V_12 , T_4 V_13 )
{
F_5 ( V_4 , V_13 ) ;
memcpy ( & V_4 -> V_7 [ V_4 -> V_5 * V_4 -> V_2 ] , V_12 ,
V_13 * V_4 -> V_2 ) ;
V_4 -> V_5 += V_13 ;
F_7 ( V_4 ) ;
}
void *
F_11 ( T_1 * V_4 , T_4 V_14 )
{
F_12 ( V_14 < V_4 -> V_5 ) ;
return & V_4 -> V_7 [ V_14 * V_4 -> V_2 ] ;
}
void
F_13 ( T_1 * V_4 , int (* F_14)( const void * , const void * ) )
{
qsort ( V_4 -> V_7 , V_4 -> V_5 , V_4 -> V_2 , F_14 ) ;
}
void *
F_15 ( T_1 * V_4 )
{
return V_4 -> V_7 ;
}
T_4
F_16 ( T_1 * V_4 )
{
return V_4 -> V_5 ;
}
