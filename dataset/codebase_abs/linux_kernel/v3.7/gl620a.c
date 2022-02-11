static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_3 * V_9 ;
T_1 V_10 ;
T_1 V_11 ;
V_6 = (struct V_5 * ) V_4 -> V_12 ;
V_11 = F_2 ( V_6 -> V_13 ) ;
if ( V_11 > V_14 ) {
F_3 ( V_2 -> V_15 ,
L_1 ,
V_11 ) ;
return 0 ;
}
V_8 = & V_6 -> V_16 ;
F_4 ( V_4 , 4 ) ;
while ( V_11 > 1 ) {
V_10 = F_2 ( V_8 -> V_17 ) ;
if ( V_10 > V_18 ) {
F_3 ( V_2 -> V_15 , L_2 ,
V_10 ) ;
return 0 ;
}
V_9 = F_5 ( V_10 , V_19 ) ;
if ( V_9 ) {
memcpy ( F_6 ( V_9 , V_10 ) ,
V_8 -> V_20 , V_10 ) ;
F_7 ( V_2 , V_9 ) ;
}
V_8 = (struct V_7 * ) & V_8 -> V_20 [ V_10 ] ;
V_11 -- ;
F_4 ( V_4 , V_10 + 4 ) ;
}
F_4 ( V_4 , 4 ) ;
if ( V_4 -> V_21 > V_18 ) {
F_3 ( V_2 -> V_15 , L_2 ,
V_4 -> V_21 ) ;
return 0 ;
}
return 1 ;
}
static struct V_3 *
F_8 ( struct V_1 * V_2 , struct V_3 * V_4 , T_2 V_22 )
{
int V_23 ;
int V_24 = V_4 -> V_21 ;
int V_25 = F_9 ( V_4 ) ;
int V_26 = F_10 ( V_4 ) ;
T_3 * V_13 ;
T_3 * V_27 ;
V_23 = ( ( V_4 -> V_21 + ( 4 + 4 * 1 ) ) % 64 ) ? 0 : 1 ;
if ( ( ! F_11 ( V_4 ) )
&& ( ( V_25 + V_26 ) >= ( V_23 + ( 4 + 4 * 1 ) ) ) ) {
if ( ( V_25 < ( 4 + 4 * 1 ) ) || ( V_26 < V_23 ) ) {
V_4 -> V_12 = memmove ( V_4 -> V_28 + ( 4 + 4 * 1 ) ,
V_4 -> V_12 , V_4 -> V_21 ) ;
F_12 ( V_4 , V_4 -> V_21 ) ;
}
} else {
struct V_3 * V_29 ;
V_29 = F_13 ( V_4 , ( 4 + 4 * 1 ) , V_23 , V_22 ) ;
F_14 ( V_4 ) ;
V_4 = V_29 ;
if ( ! V_4 )
return NULL ;
}
V_13 = ( T_3 * ) F_15 ( V_4 , ( 4 + 4 * 1 ) ) ;
V_27 = V_13 + 1 ;
* V_13 = F_16 ( 1 ) ;
* V_27 = F_16 ( V_24 ) ;
if ( ( V_4 -> V_21 % V_2 -> V_30 ) == 0 )
F_6 ( V_4 , 1 ) ;
return V_4 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
V_2 -> V_33 = V_34 ;
V_2 -> V_15 -> V_35 += 4 ;
V_2 -> V_36 = F_18 ( V_2 -> V_37 , V_2 -> V_38 -> V_36 ) ;
V_2 -> V_39 = F_19 ( V_2 -> V_37 , V_2 -> V_38 -> V_39 ) ;
return 0 ;
}
