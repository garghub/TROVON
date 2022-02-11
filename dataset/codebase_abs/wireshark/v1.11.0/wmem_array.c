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
V_4 -> V_6 = ( V_7 * ) F_3 ( V_4 -> V_1 ,
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
F_5 ( T_1 * V_4 , const T_4 V_8 )
{
T_4 V_9 , V_10 ;
V_9 = V_4 -> V_3 ;
V_10 = V_4 -> V_5 + V_8 ;
while ( V_9 < V_10 ) {
V_9 *= 2 ;
}
if ( V_9 == V_4 -> V_3 ) {
return;
}
V_4 -> V_6 = ( V_7 * ) F_6 ( V_4 -> V_1 , V_4 -> V_6 ,
V_9 * V_4 -> V_2 ) ;
V_4 -> V_3 = V_9 ;
}
void
F_7 ( T_1 * V_4 , const void * V_11 , T_4 V_12 )
{
F_5 ( V_4 , V_12 ) ;
memcpy ( & V_4 -> V_6 [ V_4 -> V_5 * V_4 -> V_2 ] , V_11 ,
V_12 * V_4 -> V_2 ) ;
V_4 -> V_5 += V_12 ;
}
void *
F_8 ( T_1 * V_4 , T_4 V_13 )
{
F_9 ( V_13 < V_4 -> V_5 ) ;
return & V_4 -> V_6 [ V_13 * V_4 -> V_2 ] ;
}
void
F_10 ( T_1 * V_4 , int (* F_11)( const void * , const void * ) )
{
qsort ( V_4 -> V_6 , V_4 -> V_5 , V_4 -> V_2 , F_11 ) ;
}
void *
F_12 ( T_1 * V_4 )
{
return V_4 -> V_6 ;
}
T_4
F_13 ( T_1 * V_4 )
{
return V_4 -> V_5 ;
}
