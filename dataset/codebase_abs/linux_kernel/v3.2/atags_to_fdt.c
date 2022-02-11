static int F_1 ( void * V_1 , const char * V_2 )
{
int V_3 = F_2 ( V_1 , V_2 ) ;
if ( V_3 == - V_4 )
V_3 = F_3 ( V_1 , 0 , V_2 ) ;
return V_3 ;
}
static int F_4 ( void * V_1 , const char * V_2 , const char * V_5 ,
T_1 * V_6 , int V_7 )
{
int V_3 = F_1 ( V_1 , V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_5 ( V_1 , V_3 , V_5 , V_6 , V_7 ) ;
}
static int F_6 ( void * V_1 , const char * V_2 ,
const char * V_5 , const char * string )
{
int V_3 = F_1 ( V_1 , V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_7 ( V_1 , V_3 , V_5 , string ) ;
}
static int F_8 ( void * V_1 , const char * V_2 ,
const char * V_5 , T_1 V_8 )
{
int V_3 = F_1 ( V_1 , V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_9 ( V_1 , V_3 , V_5 , V_8 ) ;
}
int F_10 ( void * V_9 , void * V_1 , int V_10 )
{
struct V_11 * V_12 = V_9 ;
T_1 V_13 [ 2 * V_14 ] ;
int V_15 = 0 ;
int V_16 ;
if ( ( V_17 ) V_9 & 0x3 )
return 1 ;
if ( * ( V_17 * ) V_9 == F_11 ( V_18 ) )
return 0 ;
if ( V_12 -> V_19 . V_11 != V_20 ||
( V_12 -> V_19 . V_7 != F_12 ( V_21 ) &&
V_12 -> V_19 . V_7 != 2 ) )
return 1 ;
V_16 = F_13 ( V_1 , V_1 , V_10 ) ;
if ( V_16 < 0 )
return V_16 ;
F_14 (atag, atag_list) {
if ( V_12 -> V_19 . V_11 == V_22 ) {
F_6 ( V_1 , L_1 , L_2 ,
V_12 -> V_23 . V_24 . V_24 ) ;
} else if ( V_12 -> V_19 . V_11 == V_25 ) {
if ( V_15 >= sizeof( V_13 ) / 4 )
continue;
V_13 [ V_15 ++ ] = F_15 ( V_12 -> V_23 . V_26 . V_27 ) ;
V_13 [ V_15 ++ ] = F_15 ( V_12 -> V_23 . V_26 . V_7 ) ;
} else if ( V_12 -> V_19 . V_11 == V_28 ) {
T_1 V_29 , V_30 ;
V_29 = V_12 -> V_23 . V_31 . V_27 ;
V_30 = V_12 -> V_23 . V_31 . V_7 ;
F_8 ( V_1 , L_1 , L_3 ,
V_29 ) ;
F_8 ( V_1 , L_1 , L_4 ,
V_29 + V_30 ) ;
}
}
if ( V_15 )
F_4 ( V_1 , L_5 , L_6 , V_13 , 4 * V_15 ) ;
return F_16 ( V_1 ) ;
}
