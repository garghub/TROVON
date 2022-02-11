static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
T_1 V_7 = 0 ;
int V_8 , V_9 ;
V_6 = F_2 ( sizeof( * V_6 ) , V_10 ) ;
if ( V_6 == NULL ) {
F_3 ( & V_2 -> V_11 , L_1 ) ;
return - V_12 ;
}
F_4 ( & V_6 -> V_13 ) ;
V_6 -> V_14 = F_5 ( F_6 ( V_2 ) ) ;
F_7 ( V_2 , V_6 ) ;
F_8 ( & V_6 -> V_15 . V_11 , V_6 ) ;
V_8 = F_9 ( V_6 -> V_14 , 0 ) ;
V_9 = F_10 ( V_6 -> V_14 , V_8 , V_16 ,
V_17 , 0x0000 , 0x0000 , V_6 -> V_18 , 1 ,
V_19 ) ;
if ( V_9 == 1 )
V_7 = V_6 -> V_18 [ 0 ] ;
V_9 = F_10 ( V_6 -> V_14 , V_8 , V_20 ,
V_17 , 0x0000 , 0x0000 , V_6 -> V_18 , 1 ,
V_19 ) ;
if ( V_9 == 1 ) {
V_7 <<= 8 ;
V_7 = V_7 | V_6 -> V_18 [ 0 ] ;
}
F_11 ( & V_2 -> V_11 ,
L_2 ,
V_7 >> 8 , V_7 & 0xff ,
V_6 -> V_14 -> V_21 -> V_22 , V_6 -> V_14 -> V_23 ) ;
V_9 = F_12 ( & V_2 -> V_11 , V_24 ,
F_13 ( V_24 ) ) ;
if ( V_9 != 0 ) {
F_3 ( & V_2 -> V_11 , L_3 ) ;
goto error;
}
return 0 ;
error:
if ( V_6 ) {
F_14 ( V_6 -> V_14 ) ;
F_15 ( V_6 ) ;
}
return V_9 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_17 ( V_2 ) ;
F_18 ( & V_2 -> V_11 ) ;
F_7 ( V_2 , NULL ) ;
F_14 ( V_6 -> V_14 ) ;
F_15 ( V_6 ) ;
F_19 ( & V_2 -> V_11 , L_4 ) ;
}
