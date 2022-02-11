static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
T_1 V_9 [ 2 ] ;
V_9 [ 0 ] = V_10 ;
V_9 [ 1 ] = V_3 ;
V_8 = F_3 ( V_7 , V_9 , sizeof( V_9 ) , V_4 , V_5 ) ;
if ( V_8 )
F_4 ( V_2 , L_1 ,
V_5 , V_3 ) ;
return V_8 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_11 , T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
T_1 V_9 [ 2 + V_5 ] ;
V_9 [ 0 ] = V_12 ;
V_9 [ 1 ] = V_3 ;
memcpy ( & V_9 [ 2 ] , V_11 , V_5 ) ;
V_8 = F_6 ( V_7 , V_9 , 2 + V_5 ) ;
if ( V_8 )
F_4 ( V_2 , L_2 ,
V_5 , V_3 ) ;
return V_8 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_13 , T_1 V_14 )
{
int V_8 ;
T_1 V_15 ;
V_8 = F_1 ( V_2 , V_3 , & V_15 , 1 ) ;
if ( V_8 )
return V_8 ;
if ( ( V_15 & V_13 ) != V_14 ) {
V_15 = ( V_15 & ~ V_13 ) | V_14 ;
V_8 = F_5 ( V_2 , V_3 , & V_15 , 1 ) ;
}
return V_8 ;
}
static int F_8 ( struct V_1 * V_2 , bool * V_16 )
{
int V_17 = 5 ;
int V_8 ;
T_1 V_11 ;
V_8 = F_7 ( V_2 , V_18 , V_19 , 0 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_1 ( V_2 , V_20 , & V_11 , 1 ) ;
if ( V_8 )
return V_8 ;
* V_16 = ! ! ( V_11 & V_21 ) ;
V_8 = F_7 (
V_2 , V_20 , V_21 , 0 ) ;
if ( V_8 )
return V_8 ;
do {
F_9 ( 700 , 800 ) ;
V_8 = F_1 ( V_2 , V_22 , & V_11 , 1 ) ;
if ( V_8 )
break;
if ( ! ( V_11 & V_23 ) )
break;
} while ( -- V_17 );
return ! V_17 ? - V_24 : V_8 ;
}
static int F_10 ( struct V_1 * V_2 , bool * V_16 )
{
if ( V_16 ) {
T_1 V_11 = * V_16 ? V_21 : 0 ;
int V_8 ;
V_8 = F_7 (
V_2 , V_20 , V_21 , V_11 ) ;
if ( V_8 )
return V_8 ;
}
return F_7 (
V_2 , V_18 , V_19 , V_19 ) ;
}
static int F_11 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
int V_8 ;
T_1 V_11 [ 7 ] ;
bool V_16 ;
V_8 = F_8 ( V_2 , & V_16 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_1 ( V_2 , V_18 , V_11 , sizeof( V_11 ) ) ;
if ( V_8 )
return V_8 ;
V_11 [ 0 ] = ( V_11 [ 0 ] & 0x80 ) | F_12 ( V_26 -> V_27 ) ;
V_11 [ 1 ] = ( V_11 [ 1 ] & 0x80 ) | F_12 ( V_26 -> V_28 ) ;
V_11 [ 2 ] = F_12 ( V_26 -> V_29 ) ;
V_11 [ 4 ] = F_12 ( V_26 -> V_30 ) ;
V_11 [ 5 ] = ( V_11 [ 5 ] & V_31 ) | F_12 ( V_26 -> V_32 + 1 ) ;
if ( V_26 -> V_33 > 100 )
V_26 -> V_33 -= 100 ;
V_11 [ 6 ] = F_12 ( V_26 -> V_33 ) ;
V_8 = F_5 ( V_2 , V_18 , V_11 , 5 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_5 ( V_2 , V_34 , & V_11 [ 5 ] , 2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_10 ( V_2 , V_16 ? & V_16 : NULL ) ;
if ( V_8 )
return V_8 ;
F_13 ( V_2 , L_3 ,
V_26 -> V_33 + 1900 , V_26 -> V_32 , V_26 -> V_30 ,
V_26 -> V_29 , V_26 -> V_28 , V_26 -> V_27 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
int V_8 ;
T_1 V_11 [ 7 ] ;
V_8 = F_1 ( V_2 , V_18 , V_11 , sizeof( V_11 ) ) ;
if ( V_8 )
return V_8 ;
V_26 -> V_27 = F_15 ( V_11 [ 0 ] & 0x7F ) ;
V_26 -> V_28 = F_15 ( V_11 [ 1 ] & 0x7F ) ;
V_26 -> V_29 = F_15 ( V_11 [ 2 ] & 0x3F ) ;
V_26 -> V_30 = F_15 ( V_11 [ 4 ] & 0x3F ) ;
V_26 -> V_32 = F_15 ( V_11 [ 5 ] & 0x1F ) - 1 ;
V_26 -> V_33 = F_15 ( V_11 [ 6 ] ) + 100 ;
F_13 ( V_2 , L_4 ,
V_26 -> V_33 + 1900 , V_26 -> V_32 , V_26 -> V_30 ,
V_26 -> V_29 , V_26 -> V_28 , V_26 -> V_27 ) ;
return F_16 ( V_26 ) ;
}
static int F_17 ( struct V_6 * V_7 )
{
struct V_35 * V_36 ;
int V_8 ;
V_7 -> V_37 = V_38 ;
V_7 -> V_39 = 8 ;
V_8 = F_18 ( V_7 ) ;
if ( V_8 ) {
F_4 ( & V_7 -> V_2 , L_5 ) ;
return V_8 ;
}
F_10 ( & V_7 -> V_2 , NULL ) ;
F_7 ( & V_7 -> V_2 , 0x03 , V_40 , 0 ) ;
V_36 = F_19 ( & V_7 -> V_2 , L_6 ,
& V_41 , V_42 ) ;
if ( F_20 ( V_36 ) )
return F_21 ( V_36 ) ;
F_22 ( V_7 , V_36 ) ;
return 0 ;
}
