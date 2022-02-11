static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = V_6 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_10 * V_11 = & V_9 -> V_7 -> V_12 ;
struct V_3 * V_13 = V_4 ;
int V_14 = - V_15 ;
int V_16 , V_17 , V_18 = V_5 ;
T_1 V_19 = 0x00 , V_20 = 0x00 , V_21 ;
V_21 = F_2 ( V_11 , V_9 -> V_22 , 0x07 ) & ~ 0x10 ;
F_3 ( V_11 , V_9 -> V_22 , 0x07 , V_21 | 0x10 ) ;
F_3 ( V_11 , V_9 -> V_22 , 0x07 , V_21 ) ;
F_3 ( V_11 , V_7 -> V_22 , 0x43 , 0x05 ) ;
F_4 ( 5 ) ;
while ( V_18 -- ) {
if ( ( V_13 -> V_23 & V_24 ) && V_13 -> V_22 == 0x50 ) {
F_3 ( V_11 , V_7 -> V_22 , 0x40 , V_13 -> V_22 << 1 ) ;
F_3 ( V_11 , V_7 -> V_22 , 0x41 , V_19 ) ;
F_3 ( V_11 , V_7 -> V_22 , 0x42 , V_20 ) ;
F_3 ( V_11 , V_7 -> V_22 , 0x44 , V_13 -> V_25 ) ;
F_3 ( V_11 , V_7 -> V_22 , 0x45 , 0x00 ) ;
F_3 ( V_11 , V_7 -> V_22 , 0x43 , 0x01 ) ;
for ( V_16 = 0 ; V_16 < V_13 -> V_25 ; V_16 ++ ) {
V_17 = 0 ;
while ( F_2 ( V_11 , V_7 -> V_22 , 0x46 ) & 0x10 ) {
F_4 ( 5 ) ;
if ( V_17 ++ == 32 )
goto V_26;
}
V_13 -> V_27 [ V_16 ] = F_2 ( V_11 , V_7 -> V_22 , 0x47 ) ;
}
} else
if ( ! ( V_13 -> V_23 & V_24 ) ) {
if ( V_13 -> V_22 == 0x50 && V_13 -> V_25 == 0x01 ) {
V_20 = V_13 -> V_27 [ 0 ] ;
} else
if ( V_13 -> V_22 == 0x30 && V_13 -> V_25 == 0x01 ) {
V_19 = V_13 -> V_27 [ 0 ] ;
} else
goto V_26;
} else {
goto V_26;
}
V_13 ++ ;
}
V_14 = V_5 ;
V_26:
F_3 ( V_11 , V_7 -> V_22 , 0x43 , 0x00 ) ;
return V_14 ;
}
static int
F_5 ( struct V_28 * V_2 , int V_29 , T_1 V_30 ,
struct V_1 * * V_31 )
{
struct V_8 * V_9 = V_8 ( V_2 ) ;
struct V_6 * V_7 ;
int V_14 ;
if ( ! ( V_7 = F_6 ( sizeof( * V_7 ) , V_32 ) ) )
return - V_33 ;
* V_31 = & V_7 -> V_2 ;
V_7 -> V_9 = V_9 ;
V_14 = F_7 ( & V_34 , & V_9 -> V_2 , V_29 , & V_7 -> V_2 ) ;
if ( V_14 )
return V_14 ;
switch ( V_9 -> V_22 ) {
case 0x39 : V_7 -> V_22 = 0x3d ; break;
case 0x3b : V_7 -> V_22 = 0x3f ; break;
default:
return - V_35 ;
}
return 0 ;
}
static int
F_8 ( struct V_36 * V_2 , bool V_37 ,
T_1 type , T_2 V_22 , T_1 * V_38 , T_1 V_39 )
{
struct V_40 * V_41 = V_40 ( V_2 ) ;
struct V_8 * V_9 = V_41 -> V_9 ;
struct V_10 * V_11 = & V_9 -> V_7 -> V_12 ;
int V_16 , V_14 = - V_15 ;
T_1 V_27 [ 16 ] = {} ;
T_1 V_21 ;
F_9 ( & V_41 -> V_2 , L_1 , type , V_22 , V_39 ) ;
V_21 = F_2 ( V_11 , V_9 -> V_22 , 0x07 ) & ~ 0x04 ;
F_3 ( V_11 , V_9 -> V_22 , 0x07 , V_21 | 0x04 ) ;
F_3 ( V_11 , V_9 -> V_22 , 0x07 , V_21 ) ;
F_3 ( V_11 , V_9 -> V_22 , 0xf7 , 0x01 ) ;
F_3 ( V_11 , V_41 -> V_22 , 0xe4 , 0x80 ) ;
if ( ! ( type & 1 ) ) {
memcpy ( V_27 , V_38 , V_39 ) ;
F_9 ( & V_41 -> V_2 , L_2 , V_27 ) ;
for ( V_16 = 0 ; V_16 < V_39 ; V_16 ++ )
F_3 ( V_11 , V_41 -> V_22 , 0xf0 + V_16 , V_27 [ V_16 ] ) ;
}
F_3 ( V_11 , V_41 -> V_22 , 0xe5 , ( ( V_39 - 1 ) << 4 ) | type ) ;
F_3 ( V_11 , V_41 -> V_22 , 0xe6 , ( V_22 & 0x000ff ) >> 0 ) ;
F_3 ( V_11 , V_41 -> V_22 , 0xe7 , ( V_22 & 0x0ff00 ) >> 8 ) ;
F_3 ( V_11 , V_41 -> V_22 , 0xe8 , ( V_22 & 0xf0000 ) >> 16 ) ;
F_3 ( V_11 , V_41 -> V_22 , 0xe9 , 0x01 ) ;
V_16 = 0 ;
while ( ( V_21 = F_2 ( V_11 , V_41 -> V_22 , 0xe9 ) ) & 0x01 ) {
F_4 ( 5 ) ;
if ( V_16 ++ == 32 )
goto V_26;
}
if ( ( V_21 = F_2 ( V_11 , V_9 -> V_22 , 0xf7 ) ) & 0x01 ) {
V_14 = - V_42 ;
goto V_26;
}
if ( type & 1 ) {
for ( V_16 = 0 ; V_16 < V_39 ; V_16 ++ )
V_27 [ V_16 ] = F_2 ( V_11 , V_41 -> V_22 , 0xf0 + V_16 ) ;
F_9 ( & V_41 -> V_2 , L_2 , V_27 ) ;
memcpy ( V_38 , V_27 , V_39 ) ;
}
V_14 = 0 ;
V_26:
F_3 ( V_11 , V_9 -> V_22 , 0xf7 , 0x01 ) ;
return V_14 ;
}
static int
F_10 ( struct V_36 * V_2 ,
int V_43 , int V_44 , bool V_45 )
{
struct V_40 * V_41 = V_40 ( V_2 ) ;
struct V_8 * V_9 = V_41 -> V_9 ;
struct V_10 * V_11 = & V_9 -> V_7 -> V_12 ;
T_1 V_21 , V_16 ;
F_9 ( & V_41 -> V_2 , L_3 ,
V_43 , V_44 , V_45 ) ;
F_3 ( V_11 , V_41 -> V_22 , 0xa0 , V_44 ) ;
F_3 ( V_11 , V_41 -> V_22 , 0xa1 , V_43 | ( V_45 ? 0x80 : 0x00 ) ) ;
F_3 ( V_11 , V_41 -> V_22 , 0xa2 , 0x01 ) ;
F_3 ( V_11 , V_41 -> V_22 , 0xa8 , 0x01 ) ;
V_16 = 0 ;
while ( ( V_21 = F_2 ( V_11 , V_41 -> V_22 , 0xa8 ) ) & 0x01 ) {
F_4 ( 5 ) ;
if ( V_16 ++ == 100 ) {
F_11 ( & V_41 -> V_2 , L_4 ) ;
return - V_15 ;
}
}
if ( V_21 & 0x70 ) {
F_11 ( & V_41 -> V_2 , L_5 ) ;
return - V_42 ;
}
return 0 ;
}
static int
F_12 ( struct V_28 * V_2 , int V_29 , T_1 V_30 ,
struct V_36 * * V_31 )
{
struct V_8 * V_9 = V_8 ( V_2 ) ;
struct V_40 * V_41 ;
int V_14 ;
if ( ! ( V_41 = F_6 ( sizeof( * V_41 ) , V_32 ) ) )
return - V_33 ;
* V_31 = & V_41 -> V_2 ;
V_41 -> V_9 = V_9 ;
V_14 = F_13 ( & V_46 , & V_9 -> V_2 , V_29 , & V_41 -> V_2 ) ;
if ( V_14 )
return V_14 ;
switch ( V_9 -> V_22 ) {
case 0x39 : V_41 -> V_22 = 0x38 ; break;
case 0x3b : V_41 -> V_22 = 0x3c ; break;
default:
return - V_35 ;
}
return 0 ;
}
int
F_14 ( struct V_1 * V_7 , int V_29 , T_1 V_22 ,
struct V_28 * * V_47 )
{
struct V_8 * V_9 ;
if ( ! ( V_9 = F_6 ( sizeof( * V_9 ) , V_32 ) ) )
return - V_33 ;
* V_47 = & V_9 -> V_2 ;
F_15 ( & V_48 , V_7 -> V_9 -> V_12 , V_29 , & V_9 -> V_2 ) ;
V_9 -> V_7 = V_7 ;
V_9 -> V_22 = V_22 ;
return 0 ;
}
