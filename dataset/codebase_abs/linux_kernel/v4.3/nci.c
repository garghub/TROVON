static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 = V_4 -> V_6 [ 0 ] ;
F_2 ( V_2 , V_5 ) ;
return 0 ;
}
void F_3 ( struct V_7 * * V_8 , T_2 * V_9 )
{
* V_8 = V_10 ;
* V_9 = F_4 ( V_10 ) ;
}
int F_5 ( struct V_11 * V_12 , const char * V_13 )
{
const struct V_14 * V_15 ;
struct V_16 V_17 ;
struct V_18 V_19 ;
struct V_20 V_21 ;
T_3 V_22 ;
int V_23 , V_24 ;
int V_25 ;
V_25 = F_6 ( & V_15 , V_13 , & V_12 -> V_2 -> V_26 -> V_27 ) ;
if ( V_25 < 0 )
return V_25 ;
V_22 = 0 ;
for ( V_23 = 0 ; V_23 < V_15 -> V_28 ; V_23 += 4 )
V_22 += * ( ( T_3 * ) ( V_15 -> V_6 + V_23 ) ) ;
V_17 . V_29 = 0x01 ;
V_17 . V_30 = 0xff ;
V_17 . V_31 = 0xff ;
V_25 = F_7 ( V_12 -> V_2 , V_32 ,
sizeof( V_17 ) , ( T_1 * ) & V_17 ) ;
if ( V_25 < 0 )
goto V_33;
F_8 ( & V_12 -> V_2 -> V_26 -> V_27 ,
L_1 , V_13 ) ;
V_25 = F_7 ( V_12 -> V_2 , V_34 , 0 , NULL ) ;
if ( V_25 < 0 ) {
F_9 ( & V_12 -> V_2 -> V_26 -> V_27 ,
L_2 ) ;
goto V_33;
}
V_19 . V_35 = 0 ;
for ( V_23 = 0 ; V_23 < V_15 -> V_28 ; V_23 += V_36 ) {
V_24 = ( V_15 -> V_28 - V_23 < V_36 ) ?
( V_15 -> V_28 - V_23 ) : V_36 ;
memcpy ( V_19 . V_6 , V_15 -> V_6 + V_23 , V_24 ) ;
V_25 = F_7 ( V_12 -> V_2 , V_37 ,
V_24 + 1 , ( T_1 * ) & V_19 ) ;
if ( V_25 < 0 ) {
F_9 ( & V_12 -> V_2 -> V_26 -> V_27 ,
L_3 , V_25 ) ;
goto V_33;
}
V_19 . V_35 ++ ;
}
V_21 . V_22 = V_22 & 0xffff ;
V_25 = F_7 ( V_12 -> V_2 , V_38 ,
sizeof( V_21 ) , ( T_1 * ) & V_21 ) ;
if ( V_25 < 0 ) {
F_9 ( & V_12 -> V_2 -> V_26 -> V_27 ,
L_4 ) ;
goto V_33;
}
F_8 ( & V_12 -> V_2 -> V_26 -> V_27 ,
L_5 ) ;
V_33:
F_10 ( V_15 ) ;
return V_25 ;
}
