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
static T_1 F_12 ( const void * V_1 )
{
int V_9 ;
T_1 V_10 = 1 ;
const T_1 * V_11 = F_10 ( V_1 , L_1 , L_2 , & V_9 ) ;
if ( V_11 )
V_10 = F_13 ( * V_11 ) ;
return V_10 ;
}
static void F_14 ( void * V_1 , const char * V_12 )
{
char V_13 [ V_14 ] ;
const char * V_15 ;
char * V_16 = V_13 ;
int V_9 = 0 ;
V_15 = F_10 ( V_1 , L_3 , L_4 , & V_9 ) ;
if ( V_15 )
if ( V_9 < V_14 ) {
memcpy ( V_16 , V_15 , V_9 ) ;
V_16 += V_9 - 1 ;
}
if ( V_12 ) {
V_9 = strlen ( V_12 ) ;
if ( V_16 - V_13 + V_9 + 2 < V_14 ) {
* V_16 ++ = ' ' ;
memcpy ( V_16 , V_12 , V_9 ) ;
V_16 += V_9 ;
}
}
* V_16 = '\0' ;
F_6 ( V_1 , L_3 , L_4 , V_13 ) ;
}
int F_15 ( void * V_17 , void * V_1 , int V_18 )
{
struct V_19 * V_20 = V_17 ;
T_1 V_21 [ 2 * 2 * V_22 ] ;
int V_23 = 0 ;
int V_24 , V_25 ;
if ( ( V_26 ) V_17 & 0x3 )
return 1 ;
if ( * ( V_26 * ) V_17 == F_13 ( V_27 ) )
return 0 ;
if ( V_20 -> V_28 . V_19 != V_29 ||
( V_20 -> V_28 . V_7 != F_16 ( V_30 ) &&
V_20 -> V_28 . V_7 != 2 ) )
return 1 ;
V_24 = F_17 ( V_1 , V_1 , V_18 ) ;
if ( V_24 < 0 )
return V_24 ;
F_18 (atag, atag_list) {
if ( V_20 -> V_28 . V_19 == V_31 ) {
if ( V_32 )
F_14 ( V_1 ,
V_20 -> V_33 . V_13 . V_13 ) ;
else
F_6 ( V_1 , L_3 , L_4 ,
V_20 -> V_33 . V_13 . V_13 ) ;
} else if ( V_20 -> V_28 . V_19 == V_34 ) {
if ( V_23 >= sizeof( V_21 ) / 4 )
continue;
if ( ! V_20 -> V_33 . V_35 . V_7 )
continue;
V_25 = F_12 ( V_1 ) ;
if ( V_25 == 2 ) {
T_2 * V_36 =
( T_2 * ) V_21 ;
V_36 [ V_23 ++ ] =
F_19 ( V_20 -> V_33 . V_35 . V_37 ) ;
V_36 [ V_23 ++ ] =
F_19 ( V_20 -> V_33 . V_35 . V_7 ) ;
} else {
V_21 [ V_23 ++ ] =
F_20 ( V_20 -> V_33 . V_35 . V_37 ) ;
V_21 [ V_23 ++ ] =
F_20 ( V_20 -> V_33 . V_35 . V_7 ) ;
}
} else if ( V_20 -> V_28 . V_19 == V_38 ) {
T_1 V_39 , V_40 ;
V_39 = V_20 -> V_33 . V_41 . V_37 ;
V_40 = V_20 -> V_33 . V_41 . V_7 ;
F_8 ( V_1 , L_3 , L_5 ,
V_39 ) ;
F_8 ( V_1 , L_3 , L_6 ,
V_39 + V_40 ) ;
}
}
if ( V_23 ) {
F_4 ( V_1 , L_7 , L_8 , V_21 ,
4 * V_23 * V_25 ) ;
}
return F_21 ( V_1 ) ;
}
