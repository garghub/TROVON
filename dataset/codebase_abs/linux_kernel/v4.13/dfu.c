int F_1 ( const struct V_1 * V_1 , const struct V_2 * V_3 ,
const char * V_4 , T_1 V_5 , T_1 V_6 ,
unsigned V_7 )
{
int V_8 = 0 ;
struct V_9 * V_10 = V_1 -> V_10 ;
if ( V_3 -> V_11 != V_5 ) {
if ( V_4 )
F_2 ( V_10 , L_1
L_2 , V_4 ,
V_3 -> V_11 , V_5 ) ;
V_8 = - V_12 ;
}
if ( V_3 -> V_13 != V_6 ) {
if ( V_4 )
F_2 ( V_10 , L_3
L_2 , V_4 ,
V_3 -> V_13 , V_6 ) ;
V_8 = - V_12 ;
}
if ( F_3 ( V_3 -> V_14 ) != V_7 ) {
if ( V_4 )
F_2 ( V_10 , L_4
L_5 , V_4 ,
F_3 ( V_3 -> V_14 ) , V_7 ) ;
V_8 = - V_12 ;
}
return V_8 ;
}
T_2 F_4 ( struct V_1 * V_1 , const char * V_15 , T_3 V_16 ,
T_3 V_17 )
{
T_2 V_8 ;
struct V_2 * V_18 = V_1 -> V_19 ;
struct V_20 * V_4 = V_1 -> V_21 ;
T_4 V_7 = V_18 -> V_14 ;
T_1 V_6 = V_18 -> V_13 ;
T_1 V_5 ;
F_5 ( & V_1 -> V_22 ) ;
V_1 -> V_23 = - V_24 ;
do {
F_6 ( & V_5 , 1 ) ;
} while ( V_5 == 0x00 || V_5 == 0xff );
V_4 -> V_25 = V_5 ;
V_8 = V_1 -> V_4 ( V_1 , V_15 , V_16 ) ;
if ( V_8 < 0 )
goto error;
V_8 = F_7 (
& V_1 -> V_22 , V_26 ) ;
if ( V_8 == 0 ) {
V_8 = - V_27 ;
goto error;
}
if ( V_8 < 0 )
goto error;
V_8 = V_1 -> V_23 ;
if ( V_8 < 0 ) {
F_2 ( V_1 -> V_10 , L_6 ,
V_15 , V_8 ) ;
goto error;
}
if ( F_1 ( V_1 , V_1 -> V_19 , NULL ,
0 , 0xfd , 0x0022 ) == 0 ) {
V_8 = V_1 -> V_28 ( V_1 ) ;
if ( V_8 < 0 )
goto error;
V_8 = V_1 -> V_23 ;
}
if ( V_8 != V_17 ) {
F_2 ( V_1 -> V_10 , L_7 ,
V_15 , V_8 , V_17 ) ;
V_8 = - V_12 ;
goto error;
}
V_8 = F_1 ( V_1 , V_1 -> V_19 , V_15 , V_5 ,
V_6 , V_7 ) ;
error:
return V_8 ;
}
static
int F_8 ( struct V_1 * V_1 )
{
int V_8 ;
T_5 * V_29 = ( T_5 * ) V_1 -> V_21 ;
V_8 = V_1 -> V_30 ( V_1 , 0x80080000 , 2 * sizeof( * V_29 ) ) ;
if ( V_8 < 0 ) {
F_2 ( V_1 -> V_10 , L_8 , V_8 ) ;
goto error;
}
F_9 ( V_1 -> V_10 , L_9 , V_29 [ 0 ] , V_29 [ 1 ] ) ;
error:
return V_8 ;
}
int F_10 ( struct V_1 * V_1 )
{
int V_8 ;
V_8 = F_11 ( V_1 ) ;
if ( V_8 < 0 && V_8 != - V_31 ) {
F_8 ( V_1 ) ;
goto error;
}
V_8 = F_12 ( V_1 ) ;
if ( V_8 < 0 ) {
if ( V_8 == - V_31 )
F_2 ( V_1 -> V_10 , L_10 ,
V_1 -> V_32 ) ;
else
F_8 ( V_1 ) ;
goto error;
}
V_8 = F_13 ( V_1 ) ;
if ( V_8 < 0 && V_8 != - V_31 ) {
F_8 ( V_1 ) ;
goto V_33;
}
F_9 ( V_1 -> V_10 , L_11 ) ;
V_33:
if ( V_1 -> V_34 )
V_1 -> V_34 ( V_1 ) ;
V_8 = 0 ;
error:
return V_8 ;
}
