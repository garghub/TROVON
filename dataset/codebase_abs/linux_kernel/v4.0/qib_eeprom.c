int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_4 , int V_5 )
{
int V_6 ;
V_6 = F_2 ( & V_2 -> V_7 ) ;
if ( ! V_6 ) {
V_6 = F_3 ( V_2 ) ;
if ( V_6 )
F_4 ( V_2 , L_1 ) ;
else
V_6 = F_5 ( V_2 , V_2 -> V_8 ,
V_3 , V_4 , V_5 ) ;
F_6 ( & V_2 -> V_7 ) ;
}
return V_6 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_9 ,
const void * V_10 , int V_5 )
{
int V_6 , V_11 ;
V_11 = V_2 -> V_12 ( V_2 , 1 ) ;
V_6 = F_3 ( V_2 ) ;
if ( V_6 )
F_4 ( V_2 , L_2 ) ;
else
V_6 = F_8 ( V_2 , V_2 -> V_8 ,
V_9 , V_10 , V_5 ) ;
V_2 -> V_12 ( V_2 , V_11 ) ;
return V_6 ;
}
int F_9 ( struct V_1 * V_2 , T_1 V_3 ,
const void * V_4 , int V_5 )
{
int V_6 ;
V_6 = F_2 ( & V_2 -> V_7 ) ;
if ( ! V_6 ) {
V_6 = F_7 ( V_2 , V_3 , V_4 , V_5 ) ;
F_6 ( & V_2 -> V_7 ) ;
}
return V_6 ;
}
static T_1 F_10 ( struct V_13 * V_14 , int V_15 )
{
T_1 * V_16 = ( T_1 * ) V_14 ;
T_1 V_17 = 0 , V_5 ;
V_5 = V_14 -> V_18 ;
if ( V_5 > sizeof( struct V_13 ) )
V_5 = sizeof( struct V_13 ) ;
while ( V_5 -- )
V_17 += * V_16 ++ ;
V_17 -= V_14 -> V_19 ;
V_17 = ~ V_17 ;
if ( V_15 )
V_14 -> V_19 = V_17 ;
return V_17 ;
}
void F_11 ( struct V_1 * V_2 )
{
void * V_10 ;
struct V_13 * V_14 ;
T_2 V_20 ;
int V_5 , V_21 ;
T_1 V_17 , * V_22 ;
int V_23 = V_2 -> V_24 ;
struct V_1 * V_25 = F_12 ( 0 ) ;
if ( V_23 && V_25 -> V_26 > 1 && V_23 <= V_25 -> V_26 ) {
T_1 V_27 ;
V_2 -> V_28 = V_25 -> V_28 ;
V_22 = ( T_1 * ) & V_2 -> V_28 ;
V_27 = V_22 [ 7 ] ;
V_22 [ 7 ] += V_23 ;
if ( V_27 > V_22 [ 7 ] ) {
if ( V_22 [ 6 ] == 0xff ) {
if ( V_22 [ 5 ] == 0xff ) {
F_4 ( V_2 ,
L_3 ,
F_13 ( V_23 ) ) ;
V_2 -> V_28 = 0 ;
goto V_29;
}
V_22 [ 5 ] ++ ;
}
V_22 [ 6 ] ++ ;
}
V_2 -> V_26 = 1 ;
goto V_29;
}
V_5 = sizeof( struct V_13 ) ;
V_10 = F_14 ( V_5 ) ;
if ( ! V_10 ) {
F_4 ( V_2 ,
L_4 ,
V_5 ) ;
goto V_29;
}
V_21 = F_1 ( V_2 , 0 , V_10 , V_5 ) ;
if ( V_21 ) {
F_4 ( V_2 , L_5 ) ;
goto V_30;
}
V_14 = (struct V_13 * ) V_10 ;
V_17 = F_10 ( V_14 , 0 ) ;
if ( V_17 != V_14 -> V_19 ) {
F_15 ( V_2 -> V_31 ,
L_6 ,
V_17 , V_14 -> V_19 ) ;
goto V_30;
}
if ( * ( T_2 * ) V_14 -> V_32 == F_16 ( 0 ) ||
* ( T_2 * ) V_14 -> V_32 == ~ F_16 ( 0 ) ) {
F_4 ( V_2 ,
L_7 ,
* ( unsigned long long * ) V_14 -> V_32 ) ;
goto V_30;
}
if ( * ( V_33 * ) V_14 -> V_32 == 0x100007511000000ULL )
F_15 ( V_2 -> V_31 ,
L_8 ,
* ( unsigned long long * ) V_14 -> V_32 ) ;
V_22 = V_14 -> V_32 ;
if ( ! V_22 [ 0 ] && ! V_22 [ 1 ] && ! V_22 [ 2 ] ) {
V_22 [ 1 ] = V_22 [ 3 ] ;
V_22 [ 2 ] = V_22 [ 4 ] ;
V_22 [ 3 ] = 0 ;
V_22 [ 4 ] = 0 ;
V_20 = * ( T_2 * ) V_14 -> V_32 ;
} else
V_20 = * ( T_2 * ) V_14 -> V_32 ;
V_2 -> V_28 = V_20 ;
V_2 -> V_26 = V_14 -> V_34 ;
if ( ( V_14 -> V_35 > 1 ) && V_14 -> V_36 [ 0 ] &&
( ( T_1 * ) V_14 -> V_36 ) [ 0 ] != 0xFF ) {
char * V_37 = V_2 -> V_38 ;
memcpy ( V_37 , V_14 -> V_36 , sizeof( V_14 -> V_36 ) ) ;
V_37 [ sizeof( V_14 -> V_36 ) ] = '\0' ;
V_5 = strlen ( V_37 ) ;
V_37 += V_5 ;
V_5 = sizeof( V_2 -> V_38 ) - V_5 ;
if ( V_5 > sizeof( V_14 -> V_39 ) )
V_5 = sizeof( V_14 -> V_39 ) ;
memcpy ( V_37 , V_14 -> V_39 , V_5 ) ;
} else {
memcpy ( V_2 -> V_38 , V_14 -> V_39 , sizeof( V_14 -> V_39 ) ) ;
}
if ( ! strstr ( V_14 -> V_40 , L_9 ) )
F_4 ( V_2 ,
L_10 ,
V_2 -> V_38 , V_14 -> V_40 ) ;
V_30:
F_17 ( V_10 ) ;
V_29: ;
}
