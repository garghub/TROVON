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
static int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
if ( V_4 == 0xff )
return 0 ;
else
return F_1 ( V_2 , V_3 , & V_4 , 1 ) ;
}
static int F_8 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
struct V_22 * V_23 = & V_20 -> V_24 ;
int V_6 = 0 , V_25 ;
unsigned int V_26 , V_27 , V_28 , V_29 , V_30 ;
T_1 V_31 , V_32 ;
T_2 V_33 ;
F_9 ( & V_2 -> V_14 -> V_15 , L_4 \
L_5 , V_34 ,
V_23 -> V_35 , V_23 -> V_36 , V_23 -> V_37 ) ;
if ( V_20 -> V_38 . V_39 )
V_20 -> V_38 . V_39 ( V_20 , 1 ) ;
for ( V_25 = 0 ; V_25 < F_10 ( V_40 ) ; V_25 ++ ) {
if ( V_23 -> V_36 <= V_40 [ V_25 ] . V_41 )
break;
}
if ( V_25 == F_10 ( V_40 ) )
goto V_42;
V_33 = V_23 -> V_36 ;
V_33 *= V_40 [ V_25 ] . div ;
if ( V_33 >= 2600000000UL )
V_31 = 0x0e | V_40 [ V_25 ] . V_43 ;
else
V_31 = 0x06 | V_40 [ V_25 ] . V_43 ;
V_6 = F_5 ( V_2 , 0x02 , V_31 ) ;
if ( V_6 < 0 )
goto V_42;
if ( V_33 >= 2UL * 76 * V_2 -> V_11 -> clock ) {
V_26 = 1 ;
V_32 = 0x00 ;
} else if ( V_33 >= 1UL * 76 * V_2 -> V_11 -> clock ) {
V_26 = 2 ;
V_32 = 0x10 ;
} else {
V_26 = 4 ;
V_32 = 0x20 ;
}
V_30 = 2UL * V_2 -> V_11 -> clock / V_26 ;
V_27 = F_11 ( V_33 , V_30 , & V_28 ) ;
V_29 = 1UL * V_28 * ( 1 << 20 ) / V_30 ;
V_6 = F_5 ( V_2 , 0x18 , V_32 | ( ( V_29 >> 16 ) & 0xff ) ) ;
if ( V_6 < 0 )
goto V_42;
V_6 = F_5 ( V_2 , 0x1a , ( V_29 >> 8 ) & 0xff ) ;
if ( V_6 < 0 )
goto V_42;
V_6 = F_5 ( V_2 , 0x1b , ( V_29 >> 0 ) & 0xff ) ;
if ( V_6 < 0 )
goto V_42;
V_6 = F_5 ( V_2 , 0x1c , V_27 ) ;
if ( V_6 < 0 )
goto V_42;
if ( V_2 -> V_11 -> clock >= 28000000 ) {
V_6 = F_5 ( V_2 , 0x4b , 0x22 ) ;
if ( V_6 < 0 )
goto V_42;
}
if ( V_40 [ V_25 ] . V_43 == 0x00 ) {
if ( V_23 -> V_36 <= 794000000 )
V_31 = 0x9f ;
else
V_31 = 0x8f ;
V_6 = F_5 ( V_2 , 0x2d , V_31 ) ;
if ( V_6 < 0 )
goto V_42;
}
for ( V_25 = 0 ; V_25 < F_10 ( V_44 ) ; V_25 ++ ) {
if ( V_23 -> V_36 <= V_44 [ V_25 ] . V_41 )
break;
}
if ( V_25 == F_10 ( V_44 ) )
goto V_42;
V_6 = F_7 ( V_2 , 0x25 , V_44 [ V_25 ] . V_45 ) ;
if ( V_6 < 0 )
goto V_42;
V_6 = F_7 ( V_2 , 0x27 , V_44 [ V_25 ] . V_46 ) ;
if ( V_6 < 0 )
goto V_42;
V_6 = F_7 ( V_2 , 0x28 , V_44 [ V_25 ] . V_47 ) ;
if ( V_6 < 0 )
goto V_42;
V_6 = F_7 ( V_2 , 0x29 , V_44 [ V_25 ] . V_48 ) ;
if ( V_6 < 0 )
goto V_42;
V_6 = F_7 ( V_2 , 0x2b , V_44 [ V_25 ] . V_49 ) ;
if ( V_6 < 0 )
goto V_42;
V_6 = F_7 ( V_2 , 0x2c , V_44 [ V_25 ] . V_50 ) ;
if ( V_6 < 0 )
goto V_42;
V_6 = F_7 ( V_2 , 0x2d , V_44 [ V_25 ] . V_51 ) ;
if ( V_6 < 0 )
goto V_42;
V_6 = F_7 ( V_2 , 0x30 , V_44 [ V_25 ] . V_52 ) ;
if ( V_6 < 0 )
goto V_42;
V_6 = F_7 ( V_2 , 0x44 , V_44 [ V_25 ] . V_53 ) ;
if ( V_6 < 0 )
goto V_42;
V_6 = F_7 ( V_2 , 0x50 , V_44 [ V_25 ] . V_54 ) ;
if ( V_6 < 0 )
goto V_42;
V_6 = F_7 ( V_2 , 0x53 , V_44 [ V_25 ] . V_55 ) ;
if ( V_6 < 0 )
goto V_42;
V_6 = F_7 ( V_2 , 0x5f , V_44 [ V_25 ] . V_56 ) ;
if ( V_6 < 0 )
goto V_42;
V_6 = F_7 ( V_2 , 0x61 , V_44 [ V_25 ] . V_57 ) ;
if ( V_6 < 0 )
goto V_42;
V_6 = F_7 ( V_2 , 0x62 , V_44 [ V_25 ] . V_58 ) ;
if ( V_6 < 0 )
goto V_42;
V_6 = F_7 ( V_2 , 0x63 , V_44 [ V_25 ] . V_59 ) ;
if ( V_6 < 0 )
goto V_42;
V_6 = F_7 ( V_2 , 0x67 , V_44 [ V_25 ] . V_60 ) ;
if ( V_6 < 0 )
goto V_42;
V_6 = F_7 ( V_2 , 0x68 , V_44 [ V_25 ] . V_61 ) ;
if ( V_6 < 0 )
goto V_42;
V_6 = F_7 ( V_2 , 0x69 , V_44 [ V_25 ] . V_62 ) ;
if ( V_6 < 0 )
goto V_42;
V_6 = F_7 ( V_2 , 0x6a , V_44 [ V_25 ] . V_63 ) ;
if ( V_6 < 0 )
goto V_42;
V_6 = F_7 ( V_2 , 0x6b , V_44 [ V_25 ] . V_64 ) ;
if ( V_6 < 0 )
goto V_42;
V_6 = F_7 ( V_2 , 0x6c , V_44 [ V_25 ] . V_65 ) ;
if ( V_6 < 0 )
goto V_42;
V_6 = F_7 ( V_2 , 0x6d , V_44 [ V_25 ] . V_66 ) ;
if ( V_6 < 0 )
goto V_42;
V_6 = F_7 ( V_2 , 0x6e , V_44 [ V_25 ] . V_67 ) ;
if ( V_6 < 0 )
goto V_42;
V_6 = F_7 ( V_2 , 0x6f , V_44 [ V_25 ] . V_68 ) ;
if ( V_6 < 0 )
goto V_42;
for ( V_25 = 0 ; V_25 < F_10 ( V_69 ) ; V_25 ++ ) {
if ( V_23 -> V_37 <= V_69 [ V_25 ] . V_41 )
break;
}
if ( V_25 == F_10 ( V_69 ) )
goto V_42;
V_6 = F_5 ( V_2 , 0x36 , V_69 [ V_25 ] . V_70 ) ;
if ( V_6 < 0 )
goto V_42;
V_6 = F_5 ( V_2 , 0x37 , 1UL * V_2 -> V_11 -> clock * \
V_69 [ V_25 ] . V_71 / 1000000000 ) ;
if ( V_6 < 0 )
goto V_42;
V_6 = F_5 ( V_2 , 0x39 , V_69 [ V_25 ] . V_72 ) ;
if ( V_6 < 0 )
goto V_42;
V_6 = F_5 ( V_2 , 0x2e , 0x09 ) ;
if ( V_6 < 0 )
goto V_42;
for ( V_25 = 0 ; V_25 < 5 ; V_25 ++ ) {
V_6 = F_6 ( V_2 , 0x2f , & V_31 ) ;
if ( V_6 < 0 )
goto V_42;
if ( ( V_31 & 0xc0 ) == 0xc0 )
break;
V_6 = F_5 ( V_2 , 0x2e , 0x01 ) ;
if ( V_6 < 0 )
goto V_42;
V_6 = F_5 ( V_2 , 0x2e , 0x09 ) ;
if ( V_6 < 0 )
goto V_42;
F_12 ( 5000 , 25000 ) ;
}
F_9 ( & V_2 -> V_14 -> V_15 , L_6 , V_34 , V_25 ) ;
V_6 = F_5 ( V_2 , 0x2e , 0x01 ) ;
if ( V_6 < 0 )
goto V_42;
if ( V_20 -> V_38 . V_39 )
V_20 -> V_38 . V_39 ( V_20 , 0 ) ;
return 0 ;
V_42:
if ( V_20 -> V_38 . V_39 )
V_20 -> V_38 . V_39 ( V_20 , 0 ) ;
F_9 ( & V_2 -> V_14 -> V_15 , L_7 , V_34 , V_6 ) ;
return V_6 ;
}
static int F_13 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
int V_6 , V_25 ;
F_9 ( & V_2 -> V_14 -> V_15 , L_8 , V_34 ) ;
if ( V_20 -> V_38 . V_39 )
V_20 -> V_38 . V_39 ( V_20 , 1 ) ;
for ( V_25 = 0 ; V_25 < F_10 ( V_73 ) ; V_25 ++ ) {
V_6 = F_5 ( V_2 , V_73 [ V_25 ] . V_3 ,
V_73 [ V_25 ] . V_4 ) ;
if ( V_6 < 0 )
goto V_42;
}
if ( V_20 -> V_38 . V_39 )
V_20 -> V_38 . V_39 ( V_20 , 0 ) ;
return 0 ;
V_42:
if ( V_20 -> V_38 . V_39 )
V_20 -> V_38 . V_39 ( V_20 , 0 ) ;
F_9 ( & V_2 -> V_14 -> V_15 , L_7 , V_34 , V_6 ) ;
return V_6 ;
}
static int F_14 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
int V_6 ;
F_9 ( & V_2 -> V_14 -> V_15 , L_8 , V_34 ) ;
if ( V_20 -> V_38 . V_39 )
V_20 -> V_38 . V_39 ( V_20 , 1 ) ;
V_6 = F_5 ( V_2 , 0x02 , 0x0a ) ;
if ( V_6 < 0 )
goto V_42;
if ( V_20 -> V_38 . V_39 )
V_20 -> V_38 . V_39 ( V_20 , 0 ) ;
return 0 ;
V_42:
if ( V_20 -> V_38 . V_39 )
V_20 -> V_38 . V_39 ( V_20 , 0 ) ;
F_9 ( & V_2 -> V_14 -> V_15 , L_7 , V_34 , V_6 ) ;
return V_6 ;
}
static int F_15 ( struct V_19 * V_20 , T_3 * V_36 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
F_9 ( & V_2 -> V_14 -> V_15 , L_8 , V_34 ) ;
* V_36 = 0 ;
return 0 ;
}
static int F_16 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
F_9 ( & V_2 -> V_14 -> V_15 , L_8 , V_34 ) ;
F_17 ( V_20 -> V_21 ) ;
return 0 ;
}
struct V_19 * F_18 ( struct V_19 * V_20 ,
struct V_74 * V_14 , const struct V_75 * V_11 )
{
struct V_1 * V_2 ;
int V_6 ;
T_1 V_76 ;
if ( V_20 -> V_38 . V_39 )
V_20 -> V_38 . V_39 ( V_20 , 1 ) ;
V_2 = F_19 ( sizeof( struct V_1 ) , V_77 ) ;
if ( ! V_2 ) {
V_6 = - V_78 ;
F_20 ( & V_14 -> V_15 , L_9 , V_16 ) ;
goto V_42;
}
V_2 -> V_11 = V_11 ;
V_2 -> V_14 = V_14 ;
V_6 = F_6 ( V_2 , 0x01 , & V_76 ) ;
if ( V_6 < 0 )
goto V_42;
F_9 ( & V_2 -> V_14 -> V_15 , L_10 , V_34 , V_76 ) ;
switch ( V_76 ) {
case 0x56 :
case 0x5a :
break;
default:
goto V_42;
}
F_21 ( & V_2 -> V_14 -> V_15 ,
L_11 ,
V_16 ) ;
V_20 -> V_21 = V_2 ;
memcpy ( & V_20 -> V_38 . V_79 , & V_80 ,
sizeof( struct V_81 ) ) ;
if ( V_20 -> V_38 . V_39 )
V_20 -> V_38 . V_39 ( V_20 , 0 ) ;
return V_20 ;
V_42:
if ( V_20 -> V_38 . V_39 )
V_20 -> V_38 . V_39 ( V_20 , 0 ) ;
F_9 ( & V_14 -> V_15 , L_7 , V_34 , V_6 ) ;
F_17 ( V_2 ) ;
return NULL ;
}
