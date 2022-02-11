static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , int V_5 )
{
int V_6 ;
T_1 V_7 [ V_8 ] ;
struct V_9 V_10 [ 1 ] = {
{
. V_11 = V_2 -> V_12 -> V_13 ,
. V_14 = 0 ,
. V_5 = 1 + V_5 ,
. V_7 = V_7 ,
}
} ;
if ( 1 + V_5 > sizeof( V_7 ) ) {
F_2 ( & V_2 -> V_15 -> V_16 ,
L_1 ,
V_17 , V_3 , V_5 ) ;
return - V_18 ;
}
V_7 [ 0 ] = V_3 ;
memcpy ( & V_7 [ 1 ] , V_4 , V_5 ) ;
V_6 = F_3 ( V_2 -> V_15 , V_10 , 1 ) ;
if ( V_6 == 1 ) {
V_6 = 0 ;
} else {
F_2 ( & V_2 -> V_15 -> V_16 ,
L_2 ,
V_17 , V_6 , V_3 , V_5 ) ;
V_6 = - V_19 ;
}
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , int V_5 )
{
int V_6 ;
T_1 V_7 [ V_8 ] ;
struct V_9 V_10 [ 2 ] = {
{
. V_11 = V_2 -> V_12 -> V_13 ,
. V_14 = 0 ,
. V_5 = 1 ,
. V_7 = & V_3 ,
} , {
. V_11 = V_2 -> V_12 -> V_13 ,
. V_14 = V_20 ,
. V_5 = V_5 ,
. V_7 = V_7 ,
}
} ;
if ( V_5 > sizeof( V_7 ) ) {
F_2 ( & V_2 -> V_15 -> V_16 ,
L_3 ,
V_17 , V_3 , V_5 ) ;
return - V_18 ;
}
V_6 = F_3 ( V_2 -> V_15 , V_10 , 2 ) ;
if ( V_6 == 2 ) {
memcpy ( V_4 , V_7 , V_5 ) ;
V_6 = 0 ;
} else {
F_2 ( & V_2 -> V_15 -> V_16 ,
L_4 ,
V_17 , V_6 , V_3 , V_5 ) ;
V_6 = - V_19 ;
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
static int F_7 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
int V_6 ;
F_8 ( & V_2 -> V_15 -> V_16 , L_5 , V_24 ) ;
if ( V_22 -> V_25 . V_26 )
V_22 -> V_25 . V_26 ( V_22 , 1 ) ;
V_6 = F_5 ( V_2 , 0x02 , 0x40 ) ;
V_6 = F_5 ( V_2 , 0x00 , 0x01 ) ;
if ( V_6 < 0 )
goto V_27;
V_6 = F_5 ( V_2 , 0x06 , 0x00 ) ;
if ( V_6 < 0 )
goto V_27;
V_6 = F_5 ( V_2 , 0x7a , 0x96 ) ;
if ( V_6 < 0 )
goto V_27;
V_6 = F_1 ( V_2 , 0x7e , L_6 , 2 ) ;
if ( V_6 < 0 )
goto V_27;
V_6 = F_5 ( V_2 , 0x82 , 0x00 ) ;
if ( V_6 < 0 )
goto V_27;
V_6 = F_5 ( V_2 , 0x24 , 0x05 ) ;
if ( V_6 < 0 )
goto V_27;
V_6 = F_1 ( V_2 , 0x87 , L_7 , 2 ) ;
if ( V_6 < 0 )
goto V_27;
V_6 = F_1 ( V_2 , 0x9f , L_8 , 2 ) ;
if ( V_6 < 0 )
goto V_27;
V_6 = F_5 ( V_2 , 0x2d , 0x1f ) ;
if ( V_6 < 0 )
goto V_27;
V_6 = F_1 ( V_2 , 0x70 , L_9 , 2 ) ;
if ( V_6 < 0 )
goto V_27;
V_6 = F_5 ( V_2 , 0x1a , 0x17 ) ;
if ( V_6 < 0 )
goto V_27;
V_6 = F_5 ( V_2 , 0x1f , 0x1a ) ;
if ( V_6 < 0 )
goto V_27;
if ( V_22 -> V_25 . V_26 )
V_22 -> V_25 . V_26 ( V_22 , 0 ) ;
return 0 ;
V_27:
if ( V_22 -> V_25 . V_26 )
V_22 -> V_25 . V_26 ( V_22 , 0 ) ;
F_8 ( & V_2 -> V_15 -> V_16 , L_10 , V_24 , V_6 ) ;
return V_6 ;
}
static int F_9 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
int V_6 ;
F_8 ( & V_2 -> V_15 -> V_16 , L_5 , V_24 ) ;
if ( V_22 -> V_25 . V_26 )
V_22 -> V_25 . V_26 ( V_22 , 1 ) ;
V_6 = F_5 ( V_2 , 0x00 , 0x00 ) ;
if ( V_6 < 0 )
goto V_27;
if ( V_22 -> V_25 . V_26 )
V_22 -> V_25 . V_26 ( V_22 , 0 ) ;
return 0 ;
V_27:
if ( V_22 -> V_25 . V_26 )
V_22 -> V_25 . V_26 ( V_22 , 0 ) ;
F_8 ( & V_2 -> V_15 -> V_16 , L_10 , V_24 , V_6 ) ;
return V_6 ;
}
static int F_10 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
struct V_28 * V_29 = & V_22 -> V_30 ;
int V_6 , V_31 , V_32 ;
unsigned int V_33 ;
T_1 V_7 [ 5 ] , V_34 [ 4 ] , V_35 [ 4 ] ;
F_8 ( & V_2 -> V_15 -> V_16 ,
L_11 ,
V_24 , V_29 -> V_36 , V_29 -> V_37 ,
V_29 -> V_38 ) ;
if ( V_22 -> V_25 . V_26 )
V_22 -> V_25 . V_26 ( V_22 , 1 ) ;
V_6 = F_5 ( V_2 , 0x1a , 0x00 ) ;
if ( V_6 < 0 )
goto V_27;
for ( V_31 = 0 ; V_31 < F_11 ( V_39 ) ; V_31 ++ ) {
if ( V_29 -> V_37 <= V_39 [ V_31 ] . V_40 )
break;
}
if ( V_31 == F_11 ( V_39 ) )
goto V_27;
V_33 = V_29 -> V_37 * V_39 [ V_31 ] . V_41 ;
V_32 = F_12 ( 0x10000ULL * ( V_33 % V_2 -> V_12 -> clock ) , V_2 -> V_12 -> clock ) ;
V_7 [ 0 ] = V_33 / V_2 -> V_12 -> clock ;
V_7 [ 1 ] = ( V_32 >> 0 ) & 0xff ;
V_7 [ 2 ] = ( V_32 >> 8 ) & 0xff ;
V_7 [ 3 ] = 0x00 ;
V_7 [ 4 ] = V_39 [ V_31 ] . div ;
F_8 ( & V_2 -> V_15 -> V_16 , L_12 ,
V_24 , V_33 , V_7 [ 0 ] , V_32 ) ;
V_6 = F_1 ( V_2 , 0x09 , V_7 , 5 ) ;
if ( V_6 < 0 )
goto V_27;
for ( V_31 = 0 ; V_31 < F_11 ( V_42 ) ; V_31 ++ ) {
if ( V_29 -> V_37 <= V_42 [ V_31 ] . V_40 )
break;
}
if ( V_31 == F_11 ( V_42 ) )
goto V_27;
V_6 = F_5 ( V_2 , 0x10 , V_42 [ V_31 ] . V_4 ) ;
if ( V_6 < 0 )
goto V_27;
for ( V_31 = 0 ; V_31 < F_11 ( V_43 ) ; V_31 ++ ) {
if ( V_29 -> V_38 <= V_43 [ V_31 ] . V_40 )
break;
}
if ( V_31 == F_11 ( V_43 ) )
goto V_27;
V_7 [ 0 ] = V_43 [ V_31 ] . V_44 ;
V_7 [ 1 ] = V_43 [ V_31 ] . V_45 ;
V_6 = F_1 ( V_2 , 0x11 , V_7 , 2 ) ;
if ( V_6 < 0 )
goto V_27;
for ( V_31 = 0 ; V_31 < F_11 ( V_46 ) ; V_31 ++ ) {
if ( V_29 -> V_37 <= V_46 [ V_31 ] . V_40 )
break;
}
if ( V_31 == F_11 ( V_46 ) )
goto V_27;
V_6 = F_5 ( V_2 , 0x07 , V_46 [ V_31 ] . V_47 ) ;
if ( V_6 < 0 )
goto V_27;
V_6 = F_5 ( V_2 , 0x78 , V_46 [ V_31 ] . V_48 ) ;
if ( V_6 < 0 )
goto V_27;
for ( V_31 = 0 ; V_31 < 4 ; V_31 ++ ) {
if ( V_31 == 0 )
V_6 = F_1 ( V_2 , 0x15 , L_13 , 3 ) ;
else if ( V_31 == 1 )
V_6 = F_1 ( V_2 , 0x15 , L_14 , 2 ) ;
else if ( V_31 == 2 )
V_6 = F_1 ( V_2 , 0x15 , L_15 , 1 ) ;
else
V_6 = F_1 ( V_2 , 0x16 , L_16 , 1 ) ;
if ( V_6 < 0 )
goto V_27;
V_6 = F_5 ( V_2 , 0x29 , 0x01 ) ;
if ( V_6 < 0 )
goto V_27;
V_6 = F_4 ( V_2 , 0x2a , V_7 , 3 ) ;
if ( V_6 < 0 )
goto V_27;
V_34 [ V_31 ] = ( ( ( V_7 [ 2 ] >> 0 ) & 0x3 ) << 6 ) | ( V_7 [ 0 ] & 0x3f ) ;
V_35 [ V_31 ] = ( ( ( V_7 [ 2 ] >> 4 ) & 0x3 ) << 6 ) | ( V_7 [ 1 ] & 0x3f ) ;
}
F_13 ( V_35 [ 2 ] , V_35 [ 3 ] ) ;
F_13 ( V_34 [ 2 ] , V_34 [ 3 ] ) ;
V_6 = F_1 ( V_2 , 0x50 , V_35 , 4 ) ;
if ( V_6 < 0 )
goto V_27;
V_6 = F_1 ( V_2 , 0x60 , V_34 , 4 ) ;
if ( V_6 < 0 )
goto V_27;
V_6 = F_5 ( V_2 , 0x1a , 0x17 ) ;
if ( V_6 < 0 )
goto V_27;
if ( V_22 -> V_25 . V_26 )
V_22 -> V_25 . V_26 ( V_22 , 0 ) ;
return 0 ;
V_27:
if ( V_22 -> V_25 . V_26 )
V_22 -> V_25 . V_26 ( V_22 , 0 ) ;
F_8 ( & V_2 -> V_15 -> V_16 , L_10 , V_24 , V_6 ) ;
return V_6 ;
}
static int F_14 ( struct V_21 * V_22 , T_2 * V_37 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_8 ( & V_2 -> V_15 -> V_16 , L_5 , V_24 ) ;
* V_37 = 0 ;
return 0 ;
}
static int F_15 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_8 ( & V_2 -> V_15 -> V_16 , L_5 , V_24 ) ;
F_16 ( V_22 -> V_23 ) ;
return 0 ;
}
struct V_21 * F_17 ( struct V_21 * V_22 ,
struct V_49 * V_15 , const struct V_50 * V_12 )
{
struct V_1 * V_2 ;
int V_6 ;
T_1 V_51 ;
if ( V_22 -> V_25 . V_26 )
V_22 -> V_25 . V_26 ( V_22 , 1 ) ;
V_2 = F_18 ( sizeof( struct V_1 ) , V_52 ) ;
if ( ! V_2 ) {
V_6 = - V_53 ;
F_19 ( & V_15 -> V_16 , L_17 , V_17 ) ;
goto V_27;
}
V_2 -> V_12 = V_12 ;
V_2 -> V_15 = V_15 ;
V_6 = F_6 ( V_2 , 0x02 , & V_51 ) ;
if ( V_6 < 0 )
goto V_27;
F_8 ( & V_2 -> V_15 -> V_16 , L_18 , V_24 , V_51 ) ;
if ( V_51 != 0x40 )
goto V_27;
V_6 = F_5 ( V_2 , 0x00 , 0x00 ) ;
if ( V_6 < 0 )
goto V_27;
F_20 ( & V_2 -> V_15 -> V_16 ,
L_19 ,
V_17 ) ;
V_22 -> V_23 = V_2 ;
memcpy ( & V_22 -> V_25 . V_54 , & V_55 ,
sizeof( struct V_56 ) ) ;
if ( V_22 -> V_25 . V_26 )
V_22 -> V_25 . V_26 ( V_22 , 0 ) ;
return V_22 ;
V_27:
if ( V_22 -> V_25 . V_26 )
V_22 -> V_25 . V_26 ( V_22 , 0 ) ;
F_8 ( & V_15 -> V_16 , L_10 , V_24 , V_6 ) ;
F_16 ( V_2 ) ;
return NULL ;
}
