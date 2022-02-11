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
static const void * F_10 ( const void * V_1 , const char * V_2 ,
const char * V_5 , int * V_9 )
{
int V_3 = F_2 ( V_1 , V_2 ) ;
if ( V_3 == - V_4 )
return NULL ;
return F_11 ( V_1 , V_3 , V_5 , V_9 ) ;
}
static void F_12 ( void * V_1 , const char * V_10 )
{
char V_11 [ V_12 ] ;
const char * V_13 ;
char * V_14 = V_11 ;
int V_9 = 0 ;
V_13 = F_10 ( V_1 , L_1 , L_2 , & V_9 ) ;
if ( V_13 )
if ( V_9 < V_12 ) {
memcpy ( V_14 , V_13 , V_9 ) ;
V_14 += V_9 - 1 ;
}
if ( V_10 ) {
V_9 = strlen ( V_10 ) ;
if ( V_14 - V_11 + V_9 + 2 < V_12 ) {
* V_14 ++ = ' ' ;
memcpy ( V_14 , V_10 , V_9 ) ;
V_14 += V_9 ;
}
}
* V_14 = '\0' ;
F_6 ( V_1 , L_1 , L_2 , V_11 ) ;
}
int F_13 ( void * V_15 , void * V_1 , int V_16 )
{
struct V_17 * V_18 = V_15 ;
T_1 V_19 [ 2 * V_20 ] ;
int V_21 = 0 ;
int V_22 ;
if ( ( V_23 ) V_15 & 0x3 )
return 1 ;
if ( * ( V_23 * ) V_15 == F_14 ( V_24 ) )
return 0 ;
if ( V_18 -> V_25 . V_17 != V_26 ||
( V_18 -> V_25 . V_7 != F_15 ( V_27 ) &&
V_18 -> V_25 . V_7 != 2 ) )
return 1 ;
V_22 = F_16 ( V_1 , V_1 , V_16 ) ;
if ( V_22 < 0 )
return V_22 ;
F_17 (atag, atag_list) {
if ( V_18 -> V_25 . V_17 == V_28 ) {
if ( V_29 )
F_12 ( V_1 ,
V_18 -> V_30 . V_11 . V_11 ) ;
else
F_6 ( V_1 , L_1 , L_2 ,
V_18 -> V_30 . V_11 . V_11 ) ;
} else if ( V_18 -> V_25 . V_17 == V_31 ) {
if ( V_21 >= sizeof( V_19 ) / 4 )
continue;
if ( ! V_18 -> V_30 . V_32 . V_7 )
continue;
V_19 [ V_21 ++ ] = F_18 ( V_18 -> V_30 . V_32 . V_33 ) ;
V_19 [ V_21 ++ ] = F_18 ( V_18 -> V_30 . V_32 . V_7 ) ;
} else if ( V_18 -> V_25 . V_17 == V_34 ) {
T_1 V_35 , V_36 ;
V_35 = V_18 -> V_30 . V_37 . V_33 ;
V_36 = V_18 -> V_30 . V_37 . V_7 ;
F_8 ( V_1 , L_1 , L_3 ,
V_35 ) ;
F_8 ( V_1 , L_1 , L_4 ,
V_35 + V_36 ) ;
}
}
if ( V_21 )
F_4 ( V_1 , L_5 , L_6 , V_19 , 4 * V_21 ) ;
return F_19 ( V_1 ) ;
}
