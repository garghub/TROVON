struct V_1 * F_1 ( const T_1 * V_2 , struct V_1 * V_3 )
{
struct V_1 * V_4 = NULL ;
#if F_2 ( V_5 ) && ! F_2 ( V_6 ) && ! F_2 ( V_7 ) && ! F_2 ( V_8 ) && ( ! F_2 ( V_9 ) || F_2 ( gmtime_r ) ) && ! F_2 ( V_10 ) && ! F_2 ( V_11 )
gmtime_r ( V_2 , V_3 ) ;
V_4 = V_3 ;
#elif ! F_2 ( V_9 )
V_4 = gmtime ( V_2 ) ;
if ( V_4 == NULL )
return NULL ;
memcpy ( V_3 , V_4 , sizeof( struct V_1 ) ) ;
V_4 = V_3 ;
#endif
#ifdef V_9
if ( V_4 == NULL )
{
static F_3 ( V_12 , L_1 ) ;
static F_3 ( V_13 , L_2 ) ;
char V_14 [ 256 ] ;
unsigned int V_15 = 0 ;
struct {
short V_16 ;
short V_17 ;
void * V_18 ;
unsigned int * V_15 ;
} V_19 [] = {
{ 0 , V_20 , 0 , 0 } ,
{ 0 , 0 , 0 , 0 } ,
} ;
int V_21 ;
T_1 V_22 ;
V_19 [ 0 ] . V_16 = sizeof( V_14 ) ;
V_19 [ 0 ] . V_18 = V_14 ;
V_19 [ 0 ] . V_15 = & V_15 ;
V_21 = F_4 ( 0 , & V_12 , & V_13 , 0 , V_19 ) ;
if ( ! ( V_21 & 1 ) )
return NULL ;
V_14 [ V_15 ] = '\0' ;
V_22 = * V_2 ;
#if V_23 < 70000000 || F_2 V_24
V_21 = atoi ( V_14 ) ;
V_22 -= V_21 ;
#endif
{
unsigned long V_25 [ 2 ] = { 1273708544 , 8164711 } ;
unsigned long V_26 [ 2 ] ;
unsigned long V_27 [ 2 ] ;
struct V_28
{
short V_29 , V_30 , V_31 , V_32 , V_33 , V_34 ,
V_35 ;
} V_36 ;
long V_37 ;
V_37 = V_38 ;
V_21 = F_5 ( & V_37 ,
& V_22 , V_26 ) ;
V_21 = F_6 ( V_25 , V_26 , V_27 ) ;
V_21 = F_7 ( & V_36 , V_27 ) ;
V_3 -> V_39 = V_36 . V_34 ;
V_3 -> V_40 = V_36 . V_33 ;
V_3 -> V_41 = V_36 . V_32 ;
V_3 -> V_42 = V_36 . V_31 ;
V_3 -> V_43 = V_36 . V_30 - 1 ;
V_3 -> V_44 = V_36 . V_29 - 1900 ;
V_37 = V_45 ;
V_21 = F_8 ( & V_37 ,
& V_3 -> V_46 , V_27 ) ;
V_3 -> V_46 %= 7 ;
V_37 = V_47 ;
V_21 = F_8 ( & V_37 ,
& V_3 -> V_48 , V_27 ) ;
V_3 -> V_48 -- ;
V_3 -> V_49 = 0 ;
V_4 = V_3 ;
}
}
#endif
return V_4 ;
}
