struct V_1 * F_1 ( const T_1 * V_2 , struct V_1 * V_3 )
{
struct V_1 * V_4 = NULL ;
#if F_2 ( V_5 ) && ! F_2 ( V_6 ) && ! F_2 ( V_7 ) && ! F_2 ( V_8 ) && ( ! F_2 ( V_9 ) || F_2 ( gmtime_r ) ) && ! F_2 ( V_10 )
gmtime_r ( V_2 , V_3 ) ;
V_4 = V_3 ;
#elif ! F_2 ( V_9 )
V_4 = gmtime ( V_2 ) ;
memcpy ( V_3 , V_4 , sizeof( struct V_1 ) ) ;
V_4 = V_3 ;
#endif
#ifdef V_9
if ( V_4 == NULL )
{
static F_3 ( V_11 , L_1 ) ;
static F_3 ( V_12 , L_2 ) ;
char V_13 [ 256 ] ;
unsigned int V_14 = 0 ;
struct {
short V_15 ;
short V_16 ;
void * V_17 ;
unsigned int * V_14 ;
} V_18 [] = {
{ 0 , V_19 , 0 , 0 } ,
{ 0 , 0 , 0 , 0 } ,
} ;
int V_20 ;
T_1 V_21 ;
V_18 [ 0 ] . V_15 = sizeof( V_13 ) ;
V_18 [ 0 ] . V_17 = V_13 ;
V_18 [ 0 ] . V_14 = & V_14 ;
V_20 = F_4 ( 0 , & V_11 , & V_12 , 0 , V_18 ) ;
if ( ! ( V_20 & 1 ) )
return NULL ;
V_13 [ V_14 ] = '\0' ;
V_20 = atoi ( V_13 ) ;
V_21 = * V_2 - V_20 ;
#ifndef V_5
V_4 = (struct V_1 * ) localtime ( & V_21 ) ;
#else
{
unsigned long V_22 [ 2 ] = { 1273708544 , 8164711 } ;
unsigned long V_23 [ 2 ] ;
unsigned long V_24 [ 2 ] ;
struct V_25
{
short V_26 , V_27 , V_28 , V_29 , V_30 , V_31 ,
V_32 ;
} V_33 ;
long V_34 ;
V_34 = V_35 ;
V_20 = F_5 ( & V_34 ,
& V_21 , V_23 ) ;
V_20 = F_6 ( V_22 , V_23 , V_24 ) ;
V_20 = F_7 ( & V_33 , V_24 ) ;
V_3 -> V_36 = V_33 . V_31 ;
V_3 -> V_37 = V_33 . V_30 ;
V_3 -> V_38 = V_33 . V_29 ;
V_3 -> V_39 = V_33 . V_28 ;
V_3 -> V_40 = V_33 . V_27 - 1 ;
V_3 -> V_41 = V_33 . V_26 - 1900 ;
V_34 = V_42 ;
V_20 = F_8 ( & V_34 ,
& V_3 -> V_43 , V_24 ) ;
V_3 -> V_43 %= 7 ;
V_34 = V_44 ;
V_20 = F_8 ( & V_34 ,
& V_3 -> V_45 , V_24 ) ;
V_3 -> V_45 -- ;
V_3 -> V_46 = 0 ;
V_4 = V_3 ;
#endif
}
}
#endif
return V_4 ;
}
