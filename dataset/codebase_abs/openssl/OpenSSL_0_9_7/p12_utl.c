unsigned char * F_1 ( const char * V_1 , int V_2 , unsigned char * * V_3 , int * V_4 )
{
int V_5 , V_6 ;
unsigned char * V_7 ;
if ( V_2 == - 1 ) V_2 = strlen ( V_1 ) ;
V_5 = V_2 * 2 + 2 ;
if ( ! ( V_7 = F_2 ( V_5 ) ) ) return NULL ;
for ( V_6 = 0 ; V_6 < V_5 - 2 ; V_6 += 2 ) {
V_7 [ V_6 ] = 0 ;
V_7 [ V_6 + 1 ] = V_1 [ V_6 >> 1 ] ;
}
V_7 [ V_5 - 2 ] = 0 ;
V_7 [ V_5 - 1 ] = 0 ;
if ( V_4 ) * V_4 = V_5 ;
if ( V_3 ) * V_3 = V_7 ;
return V_7 ;
}
char * F_3 ( unsigned char * V_3 , int V_4 )
{
int V_2 , V_6 ;
char * V_8 ;
V_2 = V_4 / 2 ;
if ( ! V_4 || V_3 [ V_4 - 1 ] ) V_2 ++ ;
V_3 ++ ;
if ( ! ( V_8 = F_2 ( V_2 ) ) ) return NULL ;
for ( V_6 = 0 ; V_6 < V_4 ; V_6 += 2 ) V_8 [ V_6 >> 1 ] = V_3 [ V_6 ] ;
V_8 [ V_2 - 1 ] = 0 ;
return V_8 ;
}
int F_4 ( T_1 * V_9 , T_2 * V_10 )
{
return F_5 ( F_6 ( T_2 ) , V_9 , V_10 ) ;
}
int F_7 ( T_3 * V_11 , T_2 * V_10 )
{
return F_8 ( F_6 ( T_2 ) , V_11 , V_10 ) ;
}
T_2 * F_9 ( T_1 * V_9 , T_2 * * V_10 )
{
return F_10 ( F_6 ( T_2 ) , V_9 , V_10 ) ;
}
T_2 * F_11 ( T_3 * V_11 , T_2 * * V_10 )
{
return F_12 ( F_6 ( T_2 ) , V_11 , V_10 ) ;
}
T_4 * F_13 ( T_5 * V_12 )
{
return F_14 ( V_12 , F_6 ( T_5 ) ,
V_13 , V_14 ) ;
}
T_4 * F_15 ( T_6 * V_15 )
{
return F_14 ( V_15 , F_6 ( T_6 ) ,
V_16 , V_17 ) ;
}
T_5 * F_16 ( T_4 * V_18 )
{
if( F_17 ( V_18 ) != V_14 ) return NULL ;
if( F_18 ( V_18 ) != V_13 ) return NULL ;
return F_19 ( V_18 -> V_19 . V_18 -> V_19 . V_20 , F_6 ( T_5 ) ) ;
}
T_6 * F_20 ( T_4 * V_18 )
{
if( F_17 ( V_18 ) != V_17 ) return NULL ;
if( F_18 ( V_18 ) != V_16 ) return NULL ;
return F_19 ( V_18 -> V_19 . V_18 -> V_19 . V_20 ,
F_6 ( T_6 ) ) ;
}
