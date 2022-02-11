static int F_1 ( struct V_1 * V_2 , struct V_3 * time )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_6 [ 1 + V_7 ] ;
T_1 * V_8 = V_6 ;
int V_9 ;
V_8 = V_6 ;
* V_8 ++ = V_10 << 1 | V_11 ;
* V_8 ++ = V_12 ;
V_9 = F_3 ( V_5 , V_6 , 2 ,
NULL , 0 ) ;
if ( V_9 )
return V_9 ;
V_8 = V_6 ;
* V_8 ++ = V_13 << 1 | V_11 ;
* V_8 ++ = F_4 ( time -> V_14 ) ;
* V_8 ++ = F_4 ( time -> V_15 ) ;
* V_8 ++ = F_4 ( time -> V_16 ) ;
* V_8 ++ = F_4 ( time -> V_17 ) ;
* V_8 ++ = F_4 ( time -> V_18 + 1 ) ;
* V_8 ++ = time -> V_19 + 1 ;
* V_8 ++ = F_4 ( time -> V_20 % 100 ) ;
* V_8 ++ = V_21 ;
return F_3 ( V_5 , V_6 , sizeof( V_6 ) ,
NULL , 0 ) ;
}
static int F_5 ( struct V_1 * V_2 , struct V_3 * time )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_22 = V_13 << 1 | V_23 ;
T_1 V_6 [ V_7 - 1 ] ;
int V_9 ;
V_9 = F_3 ( V_5 , & V_22 , sizeof( V_22 ) ,
V_6 , sizeof( V_6 ) ) ;
if ( V_9 < 0 )
return V_9 ;
time -> V_14 = F_6 ( V_6 [ V_24 ] ) ;
time -> V_15 = F_6 ( V_6 [ V_25 ] ) ;
time -> V_16 = F_6 ( V_6 [ V_26 ] ) ;
time -> V_19 = V_6 [ V_27 ] - 1 ;
time -> V_17 = F_6 ( V_6 [ V_28 ] ) ;
time -> V_18 = F_6 ( V_6 [ V_29 ] ) - 1 ;
time -> V_20 = F_6 ( V_6 [ V_30 ] ) + 100 ;
return F_7 ( time ) ;
}
static int F_8 ( struct V_4 * V_5 )
{
struct V_31 * V_32 ;
T_1 V_22 ;
T_1 V_6 [ 4 ] ;
T_1 * V_8 = V_6 ;
int V_9 ;
if ( V_5 -> V_33 && ( V_5 -> V_33 != 8 ) ) {
F_9 ( & V_5 -> V_2 , L_1 ) ;
return - V_34 ;
} else if ( V_5 -> V_35 > 2000000 ) {
F_9 ( & V_5 -> V_2 , L_2 ) ;
return - V_34 ;
} else if ( V_5 -> V_36 & V_37 ) {
F_9 ( & V_5 -> V_2 , L_3 ) ;
return - V_34 ;
}
V_22 = V_10 << 1 | V_23 ;
V_9 = F_3 ( V_5 , & V_22 , sizeof( V_22 ) , V_6 , 1 ) ;
if ( V_9 < 0 ) {
F_9 ( & V_5 -> V_2 , L_4 ,
V_9 ) ;
return V_9 ;
}
if ( ( V_6 [ 0 ] & ~ V_21 ) != 0 ) {
V_9 = F_3 ( V_5 , & V_22 , sizeof( V_22 ) , V_6 , 1 ) ;
if ( V_9 < 0 ) {
F_9 ( & V_5 -> V_2 , L_4 ,
V_9 ) ;
return V_9 ;
}
if ( ( V_6 [ 0 ] & ~ V_21 ) != 0 ) {
F_9 ( & V_5 -> V_2 , L_5 ) ;
return - V_38 ;
}
}
if ( V_6 [ 0 ] == 0 ) {
V_8 = V_6 ;
* V_8 ++ = V_10 << 1 | V_11 ;
* V_8 ++ = V_21 ;
V_9 = F_3 ( V_5 , V_6 , 2 , NULL , 0 ) ;
if ( V_9 < 0 ) {
F_9 ( & V_5 -> V_2 , L_6 ,
V_9 ) ;
return V_9 ;
}
V_22 = V_10 << 1 | V_23 ;
V_9 = F_3 ( V_5 , & V_22 , sizeof( V_22 ) , V_6 , 1 ) ;
if ( V_9 < 0 ) {
F_9 ( & V_5 -> V_2 ,
L_7 ,
V_9 ) ;
return V_9 ;
}
if ( V_6 [ 0 ] != V_21 ) {
F_9 ( & V_5 -> V_2 , L_8 ) ;
return - V_38 ;
}
}
F_10 ( V_5 , V_5 ) ;
V_32 = F_11 ( & V_5 -> V_2 , L_9 ,
& V_39 , V_40 ) ;
if ( F_12 ( V_32 ) ) {
V_9 = F_13 ( V_32 ) ;
F_9 ( & V_5 -> V_2 , L_10 , V_9 ) ;
return V_9 ;
}
return 0 ;
}
static int F_14 ( struct V_4 * V_5 )
{
F_10 ( V_5 , NULL ) ;
return 0 ;
}
