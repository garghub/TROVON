static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , int V_5 )
{
int V_6 ;
T_1 V_7 [ 1 + V_5 ] ;
struct V_8 V_9 [ 1 ] = {
{
. V_10 = V_2 -> V_11 -> V_12 ,
. V_13 = 0 ,
. V_5 = sizeof( V_7 ) ,
. V_7 = V_7 ,
}
} ;
V_7 [ 0 ] = V_3 ;
memcpy ( & V_7 [ 1 ] , V_4 , V_5 ) ;
V_6 = F_2 ( V_2 -> V_14 , V_9 , 1 ) ;
if ( V_6 == 1 ) {
V_6 = 0 ;
} else {
F_3 ( & V_2 -> V_14 -> V_15 , L_1 \
L_2 , V_16 , V_6 , V_3 , V_5 ) ;
V_6 = - V_17 ;
}
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , int V_5 )
{
int V_6 ;
T_1 V_7 [ V_5 ] ;
struct V_8 V_9 [ 2 ] = {
{
. V_10 = V_2 -> V_11 -> V_12 ,
. V_13 = 0 ,
. V_5 = 1 ,
. V_7 = & V_3 ,
} , {
. V_10 = V_2 -> V_11 -> V_12 ,
. V_13 = V_18 ,
. V_5 = sizeof( V_7 ) ,
. V_7 = V_7 ,
}
} ;
V_6 = F_2 ( V_2 -> V_14 , V_9 , 2 ) ;
if ( V_6 == 2 ) {
memcpy ( V_4 , V_7 , V_5 ) ;
V_6 = 0 ;
} else {
F_3 ( & V_2 -> V_14 -> V_15 , L_3 \
L_2 , V_16 , V_6 , V_3 , V_5 ) ;
V_6 = - V_17 ;
}
return V_6 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return F_1 ( V_2 , V_3 , & V_4 , 1 ) ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
return F_4 ( V_2 , V_3 , V_4 , 1 ) ;
}
static int F_7 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
int V_6 ;
F_8 ( & V_2 -> V_14 -> V_15 , L_4 , V_22 ) ;
if ( V_20 -> V_23 . V_24 )
V_20 -> V_23 . V_24 ( V_20 , 1 ) ;
V_6 = F_5 ( V_2 , 0x02 , 0x40 ) ;
V_6 = F_5 ( V_2 , 0x00 , 0x01 ) ;
if ( V_6 < 0 )
goto V_25;
V_6 = F_5 ( V_2 , 0x06 , 0x00 ) ;
if ( V_6 < 0 )
goto V_25;
V_6 = F_5 ( V_2 , 0x7a , 0x96 ) ;
if ( V_6 < 0 )
goto V_25;
V_6 = F_1 ( V_2 , 0x7e , L_5 , 2 ) ;
if ( V_6 < 0 )
goto V_25;
V_6 = F_5 ( V_2 , 0x82 , 0x00 ) ;
if ( V_6 < 0 )
goto V_25;
V_6 = F_5 ( V_2 , 0x24 , 0x05 ) ;
if ( V_6 < 0 )
goto V_25;
V_6 = F_1 ( V_2 , 0x87 , L_6 , 2 ) ;
if ( V_6 < 0 )
goto V_25;
V_6 = F_1 ( V_2 , 0x9f , L_7 , 2 ) ;
if ( V_6 < 0 )
goto V_25;
V_6 = F_5 ( V_2 , 0x2d , 0x0c ) ;
if ( V_6 < 0 )
goto V_25;
V_6 = F_5 ( V_2 , 0x1a , 0x17 ) ;
if ( V_6 < 0 )
goto V_25;
V_6 = F_5 ( V_2 , 0x1f , 0x1a ) ;
if ( V_6 < 0 )
goto V_25;
if ( V_20 -> V_23 . V_24 )
V_20 -> V_23 . V_24 ( V_20 , 0 ) ;
return 0 ;
V_25:
if ( V_20 -> V_23 . V_24 )
V_20 -> V_23 . V_24 ( V_20 , 0 ) ;
F_8 ( & V_2 -> V_14 -> V_15 , L_8 , V_22 , V_6 ) ;
return V_6 ;
}
static int F_9 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
int V_6 ;
F_8 ( & V_2 -> V_14 -> V_15 , L_4 , V_22 ) ;
if ( V_20 -> V_23 . V_24 )
V_20 -> V_23 . V_24 ( V_20 , 1 ) ;
V_6 = F_5 ( V_2 , 0x00 , 0x00 ) ;
if ( V_6 < 0 )
goto V_25;
if ( V_20 -> V_23 . V_24 )
V_20 -> V_23 . V_24 ( V_20 , 0 ) ;
return 0 ;
V_25:
if ( V_20 -> V_23 . V_24 )
V_20 -> V_23 . V_24 ( V_20 , 0 ) ;
F_8 ( & V_2 -> V_14 -> V_15 , L_8 , V_22 , V_6 ) ;
return V_6 ;
}
static int F_10 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
struct V_26 * V_27 = & V_20 -> V_28 ;
int V_6 , V_29 , V_30 ;
unsigned int V_31 ;
T_1 V_7 [ 5 ] ;
F_8 ( & V_2 -> V_14 -> V_15 , L_9 \
L_10 , V_22 ,
V_27 -> V_32 , V_27 -> V_33 , V_27 -> V_34 ) ;
if ( V_20 -> V_23 . V_24 )
V_20 -> V_23 . V_24 ( V_20 , 1 ) ;
V_6 = F_5 ( V_2 , 0x1a , 0x00 ) ;
if ( V_6 < 0 )
goto V_25;
for ( V_29 = 0 ; V_29 < F_11 ( V_35 ) ; V_29 ++ ) {
if ( V_27 -> V_33 <= V_35 [ V_29 ] . V_36 )
break;
}
if ( V_29 == F_11 ( V_35 ) )
goto V_25;
V_31 = V_27 -> V_33 * V_35 [ V_29 ] . V_37 ;
V_30 = 0x10000UL * ( V_31 % V_2 -> V_11 -> clock ) / V_2 -> V_11 -> clock ;
V_7 [ 0 ] = V_31 / V_2 -> V_11 -> clock ;
V_7 [ 1 ] = ( V_30 >> 0 ) & 0xff ;
V_7 [ 2 ] = ( V_30 >> 8 ) & 0xff ;
V_7 [ 3 ] = 0x00 ;
V_7 [ 4 ] = V_35 [ V_29 ] . div ;
F_8 ( & V_2 -> V_14 -> V_15 , L_11 ,
V_22 , V_31 , V_7 [ 0 ] , V_30 ) ;
V_6 = F_1 ( V_2 , 0x09 , V_7 , 5 ) ;
if ( V_6 < 0 )
goto V_25;
for ( V_29 = 0 ; V_29 < F_11 ( V_38 ) ; V_29 ++ ) {
if ( V_27 -> V_33 <= V_38 [ V_29 ] . V_36 )
break;
}
if ( V_29 == F_11 ( V_38 ) )
goto V_25;
V_6 = F_5 ( V_2 , 0x10 , V_38 [ V_29 ] . V_4 ) ;
if ( V_6 < 0 )
goto V_25;
for ( V_29 = 0 ; V_29 < F_11 ( V_39 ) ; V_29 ++ ) {
if ( V_27 -> V_34 <= V_39 [ V_29 ] . V_36 )
break;
}
if ( V_29 == F_11 ( V_39 ) )
goto V_25;
V_7 [ 0 ] = V_39 [ V_29 ] . V_40 ;
V_7 [ 1 ] = V_39 [ V_29 ] . V_41 ;
V_6 = F_1 ( V_2 , 0x11 , V_7 , 2 ) ;
if ( V_6 < 0 )
goto V_25;
for ( V_29 = 0 ; V_29 < F_11 ( V_42 ) ; V_29 ++ ) {
if ( V_27 -> V_33 <= V_42 [ V_29 ] . V_36 )
break;
}
if ( V_29 == F_11 ( V_42 ) )
goto V_25;
V_6 = F_5 ( V_2 , 0x07 , V_42 [ V_29 ] . V_43 ) ;
if ( V_6 < 0 )
goto V_25;
V_6 = F_5 ( V_2 , 0x78 , V_42 [ V_29 ] . V_44 ) ;
if ( V_6 < 0 )
goto V_25;
V_6 = F_5 ( V_2 , 0x1a , 0x17 ) ;
if ( V_6 < 0 )
goto V_25;
if ( V_20 -> V_23 . V_24 )
V_20 -> V_23 . V_24 ( V_20 , 0 ) ;
return 0 ;
V_25:
if ( V_20 -> V_23 . V_24 )
V_20 -> V_23 . V_24 ( V_20 , 0 ) ;
F_8 ( & V_2 -> V_14 -> V_15 , L_8 , V_22 , V_6 ) ;
return V_6 ;
}
static int F_12 ( struct V_19 * V_20 , T_2 * V_33 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
F_8 ( & V_2 -> V_14 -> V_15 , L_4 , V_22 ) ;
* V_33 = 0 ;
return 0 ;
}
static int F_13 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
F_8 ( & V_2 -> V_14 -> V_15 , L_4 , V_22 ) ;
F_14 ( V_20 -> V_21 ) ;
return 0 ;
}
struct V_19 * F_15 ( struct V_19 * V_20 ,
struct V_45 * V_14 , const struct V_46 * V_11 )
{
struct V_1 * V_2 ;
int V_6 ;
T_1 V_47 ;
if ( V_20 -> V_23 . V_24 )
V_20 -> V_23 . V_24 ( V_20 , 1 ) ;
V_2 = F_16 ( sizeof( struct V_1 ) , V_48 ) ;
if ( ! V_2 ) {
V_6 = - V_49 ;
F_17 ( & V_14 -> V_15 , L_12 , V_16 ) ;
goto V_25;
}
V_2 -> V_11 = V_11 ;
V_2 -> V_14 = V_14 ;
V_6 = F_6 ( V_2 , 0x02 , & V_47 ) ;
if ( V_6 < 0 )
goto V_25;
F_8 ( & V_2 -> V_14 -> V_15 , L_13 , V_22 , V_47 ) ;
if ( V_47 != 0x40 )
goto V_25;
V_6 = F_5 ( V_2 , 0x00 , 0x00 ) ;
if ( V_6 < 0 )
goto V_25;
F_18 ( & V_2 -> V_14 -> V_15 ,
L_14 ,
V_16 ) ;
V_20 -> V_21 = V_2 ;
memcpy ( & V_20 -> V_23 . V_50 , & V_51 ,
sizeof( struct V_52 ) ) ;
if ( V_20 -> V_23 . V_24 )
V_20 -> V_23 . V_24 ( V_20 , 0 ) ;
return V_20 ;
V_25:
if ( V_20 -> V_23 . V_24 )
V_20 -> V_23 . V_24 ( V_20 , 0 ) ;
F_8 ( & V_14 -> V_15 , L_8 , V_22 , V_6 ) ;
F_14 ( V_2 ) ;
return NULL ;
}
