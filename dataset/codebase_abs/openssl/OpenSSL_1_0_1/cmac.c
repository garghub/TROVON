static void F_1 ( unsigned char * V_1 , unsigned char * V_2 , int V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ )
{
V_1 [ V_4 ] = V_2 [ V_4 ] << 1 ;
if ( V_4 < V_3 - 1 && V_2 [ V_4 + 1 ] & 0x80 )
V_1 [ V_4 ] |= 1 ;
}
if ( V_2 [ 0 ] & 0x80 )
V_1 [ V_3 - 1 ] ^= V_3 == 16 ? 0x87 : 0x1b ;
}
T_1 * F_2 ( void )
{
T_1 * V_5 ;
V_5 = F_3 ( sizeof( T_1 ) ) ;
if ( ! V_5 )
return NULL ;
F_4 ( & V_5 -> V_6 ) ;
V_5 -> V_7 = - 1 ;
return V_5 ;
}
void F_5 ( T_1 * V_5 )
{
#ifdef F_6
if ( F_7 () && ! V_5 -> V_6 . V_8 )
{
F_8 ( V_5 ) ;
return;
}
#endif
F_9 ( & V_5 -> V_6 ) ;
F_10 ( V_5 -> V_9 , V_10 ) ;
F_10 ( V_5 -> V_1 , V_10 ) ;
F_10 ( V_5 -> V_11 , V_10 ) ;
F_10 ( V_5 -> V_12 , V_10 ) ;
V_5 -> V_7 = - 1 ;
}
T_2 * F_11 ( T_1 * V_5 )
{
return & V_5 -> V_6 ;
}
void F_12 ( T_1 * V_5 )
{
F_5 ( V_5 ) ;
F_13 ( V_5 ) ;
}
int F_14 ( T_1 * V_13 , const T_1 * V_14 )
{
int V_3 ;
if ( V_14 -> V_7 == - 1 )
return 0 ;
if ( ! F_15 ( & V_13 -> V_6 , & V_14 -> V_6 ) )
return 0 ;
V_3 = F_16 ( & V_14 -> V_6 ) ;
memcpy ( V_13 -> V_1 , V_14 -> V_1 , V_3 ) ;
memcpy ( V_13 -> V_11 , V_14 -> V_11 , V_3 ) ;
memcpy ( V_13 -> V_9 , V_14 -> V_9 , V_3 ) ;
memcpy ( V_13 -> V_12 , V_14 -> V_12 , V_3 ) ;
V_13 -> V_7 = V_14 -> V_7 ;
return 1 ;
}
int F_17 ( T_1 * V_5 , const void * V_15 , T_3 V_16 ,
const T_4 * V_17 , T_5 * V_18 )
{
static unsigned char V_19 [ V_10 ] ;
#ifdef F_6
if ( F_7 () )
{
if ( ( V_18 || V_5 -> V_6 . V_8 )
&& ! ( V_5 -> V_6 . V_20 & V_21 ) )
{
F_18 ( V_22 , V_23 ) ;
return 0 ;
}
if ( ! V_18 && ! V_5 -> V_6 . V_8 )
return F_19 ( V_5 , V_15 , V_16 , V_17 , NULL ) ;
}
#endif
if ( ! V_15 && ! V_17 && ! V_18 && V_16 == 0 )
{
if ( V_5 -> V_7 == - 1 )
return 0 ;
if ( ! F_20 ( & V_5 -> V_6 , NULL , NULL , NULL , V_19 ) )
return 0 ;
return 1 ;
}
if ( V_17 && ! F_20 ( & V_5 -> V_6 , V_17 , V_18 , NULL , NULL ) )
return 0 ;
if ( V_15 )
{
int V_3 ;
if ( ! F_21 ( & V_5 -> V_6 ) )
return 0 ;
if ( ! F_22 ( & V_5 -> V_6 , V_16 ) )
return 0 ;
if ( ! F_20 ( & V_5 -> V_6 , NULL , NULL , V_15 , V_19 ) )
return 0 ;
V_3 = F_16 ( & V_5 -> V_6 ) ;
if ( ! F_23 ( & V_5 -> V_6 , V_5 -> V_9 , V_19 , V_3 ) )
return 0 ;
F_1 ( V_5 -> V_1 , V_5 -> V_9 , V_3 ) ;
F_1 ( V_5 -> V_11 , V_5 -> V_1 , V_3 ) ;
F_10 ( V_5 -> V_9 , V_3 ) ;
if ( ! F_20 ( & V_5 -> V_6 , NULL , NULL , NULL , V_19 ) )
return 0 ;
memset ( V_5 -> V_9 , 0 , V_3 ) ;
V_5 -> V_7 = 0 ;
}
return 1 ;
}
int F_24 ( T_1 * V_5 , const void * V_14 , T_3 V_24 )
{
const unsigned char * V_25 = V_14 ;
T_3 V_3 ;
#ifdef F_6
if ( F_7 () && ! V_5 -> V_6 . V_8 )
return F_25 ( V_5 , V_14 , V_24 ) ;
#endif
if ( V_5 -> V_7 == - 1 )
return 0 ;
if ( V_24 == 0 )
return 1 ;
V_3 = F_16 ( & V_5 -> V_6 ) ;
if ( V_5 -> V_7 > 0 )
{
T_3 V_26 ;
V_26 = V_3 - V_5 -> V_7 ;
if ( V_24 < V_26 )
V_26 = V_24 ;
memcpy ( V_5 -> V_12 + V_5 -> V_7 , V_25 , V_26 ) ;
V_24 -= V_26 ;
V_5 -> V_7 += V_26 ;
if ( V_24 == 0 )
return 1 ;
V_25 += V_26 ;
if ( ! F_23 ( & V_5 -> V_6 , V_5 -> V_9 , V_5 -> V_12 , V_3 ) )
return 0 ;
}
while( V_24 > V_3 )
{
if ( ! F_23 ( & V_5 -> V_6 , V_5 -> V_9 , V_25 , V_3 ) )
return 0 ;
V_24 -= V_3 ;
V_25 += V_3 ;
}
memcpy ( V_5 -> V_12 , V_25 , V_24 ) ;
V_5 -> V_7 = V_24 ;
return 1 ;
}
int F_26 ( T_1 * V_5 , unsigned char * V_13 , T_3 * V_27 )
{
int V_4 , V_3 , V_28 ;
#ifdef F_6
if ( F_7 () && ! V_5 -> V_6 . V_8 )
return F_27 ( V_5 , V_13 , V_27 ) ;
#endif
if ( V_5 -> V_7 == - 1 )
return 0 ;
V_3 = F_16 ( & V_5 -> V_6 ) ;
* V_27 = ( T_3 ) V_3 ;
if ( ! V_13 )
return 1 ;
V_28 = V_5 -> V_7 ;
if ( V_28 == V_3 )
{
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ )
V_13 [ V_4 ] = V_5 -> V_12 [ V_4 ] ^ V_5 -> V_1 [ V_4 ] ;
}
else
{
V_5 -> V_12 [ V_28 ] = 0x80 ;
if ( V_3 - V_28 > 1 )
memset ( V_5 -> V_12 + V_28 + 1 , 0 , V_3 - V_28 - 1 ) ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ )
V_13 [ V_4 ] = V_5 -> V_12 [ V_4 ] ^ V_5 -> V_11 [ V_4 ] ;
}
if ( ! F_23 ( & V_5 -> V_6 , V_13 , V_13 , V_3 ) )
{
F_10 ( V_13 , V_3 ) ;
return 0 ;
}
return 1 ;
}
int F_28 ( T_1 * V_5 )
{
if ( V_5 -> V_7 == - 1 )
return 0 ;
return F_20 ( & V_5 -> V_6 , NULL , NULL , NULL , V_5 -> V_9 ) ;
}
