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
F_2 ( & V_2 -> V_15 -> V_16 , L_2 \
L_3 , V_17 , V_6 , V_3 , V_5 ) ;
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
L_4 ,
V_17 , V_3 , V_5 ) ;
return - V_18 ;
}
V_6 = F_3 ( V_2 -> V_15 , V_10 , 2 ) ;
if ( V_6 == 2 ) {
memcpy ( V_4 , V_7 , V_5 ) ;
V_6 = 0 ;
} else {
F_2 ( & V_2 -> V_15 -> V_16 , L_5 \
L_3 , V_17 , V_6 , V_3 , V_5 ) ;
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
static int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
if ( V_4 == 0xff )
return 0 ;
else
return F_1 ( V_2 , V_3 , & V_4 , 1 ) ;
}
static int F_8 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
struct V_24 * V_25 = & V_22 -> V_26 ;
int V_6 = 0 , V_27 ;
unsigned int V_28 , V_29 , V_30 , V_31 , V_32 ;
T_1 V_33 , V_34 ;
T_2 V_35 ;
F_9 ( & V_2 -> V_15 -> V_16 , L_6 \
L_7 , V_36 ,
V_25 -> V_37 , V_25 -> V_38 , V_25 -> V_39 ) ;
if ( V_22 -> V_40 . V_41 )
V_22 -> V_40 . V_41 ( V_22 , 1 ) ;
for ( V_27 = 0 ; V_27 < F_10 ( V_42 ) ; V_27 ++ ) {
if ( V_25 -> V_38 <= V_42 [ V_27 ] . V_43 )
break;
}
if ( V_27 == F_10 ( V_42 ) )
goto V_44;
V_35 = V_25 -> V_38 ;
V_35 *= V_42 [ V_27 ] . div ;
if ( V_35 >= 2600000000UL )
V_33 = 0x0e | V_42 [ V_27 ] . V_45 ;
else
V_33 = 0x06 | V_42 [ V_27 ] . V_45 ;
V_6 = F_5 ( V_2 , 0x02 , V_33 ) ;
if ( V_6 < 0 )
goto V_44;
if ( V_35 >= 2UL * 76 * V_2 -> V_12 -> clock ) {
V_28 = 1 ;
V_34 = 0x00 ;
} else if ( V_35 >= 1UL * 76 * V_2 -> V_12 -> clock ) {
V_28 = 2 ;
V_34 = 0x10 ;
} else {
V_28 = 4 ;
V_34 = 0x20 ;
}
V_32 = 2UL * V_2 -> V_12 -> clock / V_28 ;
V_29 = F_11 ( V_35 , V_32 , & V_30 ) ;
V_31 = F_12 ( 1ULL * V_30 * ( 1 << 20 ) , V_32 ) ;
V_6 = F_5 ( V_2 , 0x18 , V_34 | ( ( V_31 >> 16 ) & 0xff ) ) ;
if ( V_6 < 0 )
goto V_44;
V_6 = F_5 ( V_2 , 0x1a , ( V_31 >> 8 ) & 0xff ) ;
if ( V_6 < 0 )
goto V_44;
V_6 = F_5 ( V_2 , 0x1b , ( V_31 >> 0 ) & 0xff ) ;
if ( V_6 < 0 )
goto V_44;
V_6 = F_5 ( V_2 , 0x1c , V_29 ) ;
if ( V_6 < 0 )
goto V_44;
if ( V_2 -> V_12 -> clock >= 28000000 ) {
V_6 = F_5 ( V_2 , 0x4b , 0x22 ) ;
if ( V_6 < 0 )
goto V_44;
}
if ( V_42 [ V_27 ] . V_45 == 0x00 ) {
if ( V_25 -> V_38 <= 794000000 )
V_33 = 0x9f ;
else
V_33 = 0x8f ;
V_6 = F_5 ( V_2 , 0x2d , V_33 ) ;
if ( V_6 < 0 )
goto V_44;
}
for ( V_27 = 0 ; V_27 < F_10 ( V_46 ) ; V_27 ++ ) {
if ( V_25 -> V_38 <= V_46 [ V_27 ] . V_43 )
break;
}
if ( V_27 == F_10 ( V_46 ) )
goto V_44;
V_6 = F_7 ( V_2 , 0x25 , V_46 [ V_27 ] . V_47 ) ;
if ( V_6 < 0 )
goto V_44;
V_6 = F_7 ( V_2 , 0x27 , V_46 [ V_27 ] . V_48 ) ;
if ( V_6 < 0 )
goto V_44;
V_6 = F_7 ( V_2 , 0x28 , V_46 [ V_27 ] . V_49 ) ;
if ( V_6 < 0 )
goto V_44;
V_6 = F_7 ( V_2 , 0x29 , V_46 [ V_27 ] . V_50 ) ;
if ( V_6 < 0 )
goto V_44;
V_6 = F_7 ( V_2 , 0x2b , V_46 [ V_27 ] . V_51 ) ;
if ( V_6 < 0 )
goto V_44;
V_6 = F_7 ( V_2 , 0x2c , V_46 [ V_27 ] . V_52 ) ;
if ( V_6 < 0 )
goto V_44;
V_6 = F_7 ( V_2 , 0x2d , V_46 [ V_27 ] . V_53 ) ;
if ( V_6 < 0 )
goto V_44;
V_6 = F_7 ( V_2 , 0x30 , V_46 [ V_27 ] . V_54 ) ;
if ( V_6 < 0 )
goto V_44;
V_6 = F_7 ( V_2 , 0x44 , V_46 [ V_27 ] . V_55 ) ;
if ( V_6 < 0 )
goto V_44;
V_6 = F_7 ( V_2 , 0x50 , V_46 [ V_27 ] . V_56 ) ;
if ( V_6 < 0 )
goto V_44;
V_6 = F_7 ( V_2 , 0x53 , V_46 [ V_27 ] . V_57 ) ;
if ( V_6 < 0 )
goto V_44;
V_6 = F_7 ( V_2 , 0x5f , V_46 [ V_27 ] . V_58 ) ;
if ( V_6 < 0 )
goto V_44;
V_6 = F_7 ( V_2 , 0x61 , V_46 [ V_27 ] . V_59 ) ;
if ( V_6 < 0 )
goto V_44;
V_6 = F_7 ( V_2 , 0x62 , V_46 [ V_27 ] . V_60 ) ;
if ( V_6 < 0 )
goto V_44;
V_6 = F_7 ( V_2 , 0x63 , V_46 [ V_27 ] . V_61 ) ;
if ( V_6 < 0 )
goto V_44;
V_6 = F_7 ( V_2 , 0x67 , V_46 [ V_27 ] . V_62 ) ;
if ( V_6 < 0 )
goto V_44;
V_6 = F_7 ( V_2 , 0x68 , V_46 [ V_27 ] . V_63 ) ;
if ( V_6 < 0 )
goto V_44;
V_6 = F_7 ( V_2 , 0x69 , V_46 [ V_27 ] . V_64 ) ;
if ( V_6 < 0 )
goto V_44;
V_6 = F_7 ( V_2 , 0x6a , V_46 [ V_27 ] . V_65 ) ;
if ( V_6 < 0 )
goto V_44;
V_6 = F_7 ( V_2 , 0x6b , V_46 [ V_27 ] . V_66 ) ;
if ( V_6 < 0 )
goto V_44;
V_6 = F_7 ( V_2 , 0x6c , V_46 [ V_27 ] . V_67 ) ;
if ( V_6 < 0 )
goto V_44;
V_6 = F_7 ( V_2 , 0x6d , V_46 [ V_27 ] . V_68 ) ;
if ( V_6 < 0 )
goto V_44;
V_6 = F_7 ( V_2 , 0x6e , V_46 [ V_27 ] . V_69 ) ;
if ( V_6 < 0 )
goto V_44;
V_6 = F_7 ( V_2 , 0x6f , V_46 [ V_27 ] . V_70 ) ;
if ( V_6 < 0 )
goto V_44;
for ( V_27 = 0 ; V_27 < F_10 ( V_71 ) ; V_27 ++ ) {
if ( V_25 -> V_39 <= V_71 [ V_27 ] . V_43 )
break;
}
if ( V_27 == F_10 ( V_71 ) )
goto V_44;
V_6 = F_5 ( V_2 , 0x36 , V_71 [ V_27 ] . V_72 ) ;
if ( V_6 < 0 )
goto V_44;
V_6 = F_5 ( V_2 , 0x37 , F_12 ( 1ULL * V_2 -> V_12 -> clock *
V_71 [ V_27 ] . V_73 , 1000000000 ) ) ;
if ( V_6 < 0 )
goto V_44;
V_6 = F_5 ( V_2 , 0x39 , V_71 [ V_27 ] . V_74 ) ;
if ( V_6 < 0 )
goto V_44;
V_6 = F_5 ( V_2 , 0x2e , 0x09 ) ;
if ( V_6 < 0 )
goto V_44;
for ( V_27 = 0 ; V_27 < 5 ; V_27 ++ ) {
V_6 = F_6 ( V_2 , 0x2f , & V_33 ) ;
if ( V_6 < 0 )
goto V_44;
if ( ( V_33 & 0xc0 ) == 0xc0 )
break;
V_6 = F_5 ( V_2 , 0x2e , 0x01 ) ;
if ( V_6 < 0 )
goto V_44;
V_6 = F_5 ( V_2 , 0x2e , 0x09 ) ;
if ( V_6 < 0 )
goto V_44;
F_13 ( 5000 , 25000 ) ;
}
F_9 ( & V_2 -> V_15 -> V_16 , L_8 , V_36 , V_27 ) ;
V_6 = F_5 ( V_2 , 0x2e , 0x01 ) ;
if ( V_6 < 0 )
goto V_44;
if ( V_22 -> V_40 . V_41 )
V_22 -> V_40 . V_41 ( V_22 , 0 ) ;
return 0 ;
V_44:
if ( V_22 -> V_40 . V_41 )
V_22 -> V_40 . V_41 ( V_22 , 0 ) ;
F_9 ( & V_2 -> V_15 -> V_16 , L_9 , V_36 , V_6 ) ;
return V_6 ;
}
static int F_14 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
int V_6 , V_27 ;
F_9 ( & V_2 -> V_15 -> V_16 , L_10 , V_36 ) ;
if ( V_22 -> V_40 . V_41 )
V_22 -> V_40 . V_41 ( V_22 , 1 ) ;
for ( V_27 = 0 ; V_27 < F_10 ( V_75 ) ; V_27 ++ ) {
V_6 = F_5 ( V_2 , V_75 [ V_27 ] . V_3 ,
V_75 [ V_27 ] . V_4 ) ;
if ( V_6 < 0 )
goto V_44;
}
if ( V_22 -> V_40 . V_41 )
V_22 -> V_40 . V_41 ( V_22 , 0 ) ;
return 0 ;
V_44:
if ( V_22 -> V_40 . V_41 )
V_22 -> V_40 . V_41 ( V_22 , 0 ) ;
F_9 ( & V_2 -> V_15 -> V_16 , L_9 , V_36 , V_6 ) ;
return V_6 ;
}
static int F_15 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
int V_6 ;
F_9 ( & V_2 -> V_15 -> V_16 , L_10 , V_36 ) ;
if ( V_22 -> V_40 . V_41 )
V_22 -> V_40 . V_41 ( V_22 , 1 ) ;
V_6 = F_5 ( V_2 , 0x02 , 0x0a ) ;
if ( V_6 < 0 )
goto V_44;
if ( V_22 -> V_40 . V_41 )
V_22 -> V_40 . V_41 ( V_22 , 0 ) ;
return 0 ;
V_44:
if ( V_22 -> V_40 . V_41 )
V_22 -> V_40 . V_41 ( V_22 , 0 ) ;
F_9 ( & V_2 -> V_15 -> V_16 , L_9 , V_36 , V_6 ) ;
return V_6 ;
}
static int F_16 ( struct V_21 * V_22 , T_3 * V_38 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_9 ( & V_2 -> V_15 -> V_16 , L_10 , V_36 ) ;
* V_38 = 0 ;
return 0 ;
}
static int F_17 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_9 ( & V_2 -> V_15 -> V_16 , L_10 , V_36 ) ;
F_18 ( V_22 -> V_23 ) ;
return 0 ;
}
struct V_21 * F_19 ( struct V_21 * V_22 ,
struct V_76 * V_15 , const struct V_77 * V_12 )
{
struct V_1 * V_2 ;
int V_6 ;
T_1 V_78 ;
if ( V_22 -> V_40 . V_41 )
V_22 -> V_40 . V_41 ( V_22 , 1 ) ;
V_2 = F_20 ( sizeof( struct V_1 ) , V_79 ) ;
if ( ! V_2 ) {
V_6 = - V_80 ;
F_21 ( & V_15 -> V_16 , L_11 , V_17 ) ;
goto V_44;
}
V_2 -> V_12 = V_12 ;
V_2 -> V_15 = V_15 ;
V_6 = F_6 ( V_2 , 0x01 , & V_78 ) ;
if ( V_6 < 0 )
goto V_44;
F_9 ( & V_2 -> V_15 -> V_16 , L_12 , V_36 , V_78 ) ;
switch ( V_78 ) {
case 0x56 :
case 0x5a :
break;
default:
goto V_44;
}
F_22 ( & V_2 -> V_15 -> V_16 ,
L_13 ,
V_17 ) ;
V_22 -> V_23 = V_2 ;
memcpy ( & V_22 -> V_40 . V_81 , & V_82 ,
sizeof( struct V_83 ) ) ;
if ( V_22 -> V_40 . V_41 )
V_22 -> V_40 . V_41 ( V_22 , 0 ) ;
return V_22 ;
V_44:
if ( V_22 -> V_40 . V_41 )
V_22 -> V_40 . V_41 ( V_22 , 0 ) ;
F_9 ( & V_15 -> V_16 , L_9 , V_36 , V_6 ) ;
F_18 ( V_2 ) ;
return NULL ;
}
