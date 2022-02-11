static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_2 . V_9 ;
return V_8 -> V_10 ( V_8 -> V_11 , V_3 , V_4 ) ;
}
static int F_2 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_2 . V_9 ;
return V_8 -> V_12 ( V_8 -> V_11 , V_3 , V_4 ) ;
}
static int F_3 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_15 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_16 * V_17 = & V_14 -> V_18 ;
int V_19 ;
T_3 V_20 ;
T_2 V_21 ;
F_4 ( & V_6 -> V_2 , L_1 ,
V_17 -> V_22 , V_17 -> V_23 ) ;
if ( V_14 -> V_24 . V_25 . V_26 &&
V_14 -> V_24 . V_25 . V_27 ) {
V_19 = V_14 -> V_24 . V_25 . V_26 ( V_14 ) ;
if ( V_19 )
goto V_28;
V_19 = V_14 -> V_24 . V_25 . V_27 ( V_14 , & V_20 ) ;
if ( V_19 )
goto V_28;
} else {
V_19 = - V_29 ;
goto V_28;
}
F_4 ( & V_6 -> V_2 , L_2 , V_20 ) ;
if ( V_20 != 36150000 ) {
V_19 = - V_29 ;
goto V_28;
}
switch ( V_17 -> V_23 ) {
case 6000000 :
V_21 = 0x78 ;
break;
case 7000000 :
V_21 = 0x68 ;
break;
case 8000000 :
V_21 = 0x58 ;
break;
default:
V_19 = - V_29 ;
goto V_28;
}
V_19 = F_1 ( V_2 , 0x6a60 , 0x11 ) ;
if ( V_19 )
goto V_28;
V_19 = F_1 ( V_2 , 0x6a47 , 0x46 ) ;
if ( V_19 )
goto V_28;
V_19 = F_1 ( V_2 , 0x6a48 , 0x46 ) ;
if ( V_19 )
goto V_28;
V_19 = F_1 ( V_2 , 0x6a4a , 0x15 ) ;
if ( V_19 )
goto V_28;
V_19 = F_1 ( V_2 , 0x6a4b , 0x63 ) ;
if ( V_19 )
goto V_28;
V_19 = F_1 ( V_2 , 0x6a5b , 0x99 ) ;
if ( V_19 )
goto V_28;
V_19 = F_1 ( V_2 , 0x6a3b , 0x10 ) ;
if ( V_19 )
goto V_28;
V_19 = F_1 ( V_2 , 0x6806 , 0x01 ) ;
if ( V_19 )
goto V_28;
V_19 = F_1 ( V_2 , 0x6a41 , 0x08 ) ;
if ( V_19 )
goto V_28;
V_19 = F_1 ( V_2 , 0x6a42 , 0x46 ) ;
if ( V_19 )
goto V_28;
V_19 = F_1 ( V_2 , 0x6a44 , 0x14 ) ;
if ( V_19 )
goto V_28;
V_19 = F_1 ( V_2 , 0x6a45 , 0x67 ) ;
if ( V_19 )
goto V_28;
V_19 = F_1 ( V_2 , 0x6a38 , 0x00 ) ;
if ( V_19 )
goto V_28;
V_19 = F_1 ( V_2 , 0x6a4c , 0x52 ) ;
if ( V_19 )
goto V_28;
V_19 = F_1 ( V_2 , 0x6a49 , 0x2a ) ;
if ( V_19 )
goto V_28;
V_19 = F_1 ( V_2 , 0x6840 , 0x2e ) ;
if ( V_19 )
goto V_28;
V_19 = F_1 ( V_2 , 0x6a50 , V_21 ) ;
if ( V_19 )
goto V_28;
V_19 = F_1 ( V_2 , 0x6a38 , 0x07 ) ;
if ( V_19 )
goto V_28;
return 0 ;
V_28:
F_4 ( & V_6 -> V_2 , L_3 , V_19 ) ;
return V_19 ;
}
static int F_5 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_15 ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_19 ;
F_4 ( & V_6 -> V_2 , L_4 ) ;
V_19 = F_1 ( V_2 , 0x6a43 , 0x70 ) ;
if ( V_19 )
goto V_28;
V_19 = F_1 ( V_2 , 0x684e , 0x00 ) ;
if ( V_19 )
goto V_28;
V_19 = F_1 ( V_2 , 0x6849 , 0x00 ) ;
if ( V_19 )
goto V_28;
V_19 = F_1 ( V_2 , 0x68e2 , 0xd7 ) ;
if ( V_19 )
goto V_28;
V_19 = F_1 ( V_2 , 0x68e0 , 0x39 ) ;
if ( V_19 )
goto V_28;
V_19 = F_1 ( V_2 , 0x6840 , 0x21 ) ;
if ( V_19 )
goto V_28;
return 0 ;
V_28:
F_4 ( & V_6 -> V_2 , L_3 , V_19 ) ;
return V_19 ;
}
static int F_6 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_15 ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_19 ;
F_4 ( & V_6 -> V_2 , L_4 ) ;
V_19 = F_1 ( V_2 , 0x6840 , 0x26 ) ;
if ( V_19 )
goto V_28;
V_19 = F_1 ( V_2 , 0x68e0 , 0xff ) ;
if ( V_19 )
goto V_28;
V_19 = F_1 ( V_2 , 0x68e2 , 0xd8 ) ;
if ( V_19 )
goto V_28;
V_19 = F_1 ( V_2 , 0x6849 , 0x4e ) ;
if ( V_19 )
goto V_28;
V_19 = F_1 ( V_2 , 0x684e , 0x01 ) ;
if ( V_19 )
goto V_28;
V_19 = F_1 ( V_2 , 0x6a43 , V_30 ) ;
if ( V_19 )
goto V_28;
return 0 ;
V_28:
F_4 ( & V_6 -> V_2 , L_3 , V_19 ) ;
return V_19 ;
}
static int F_7 ( struct V_13 * V_14 ,
struct V_31 * V_32 )
{
struct V_1 * V_2 = V_14 -> V_15 ;
struct V_5 * V_6 = V_2 -> V_6 ;
F_4 ( & V_6 -> V_2 , L_4 ) ;
V_32 -> V_33 = 400 ;
return 0 ;
}
static int F_8 ( struct V_13 * V_14 ,
enum V_34 * V_35 )
{
struct V_1 * V_2 = V_14 -> V_15 ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_19 ;
T_2 V_36 ;
V_19 = F_2 ( V_2 , 0x6a24 , & V_36 ) ;
if ( V_19 )
goto V_28;
if ( V_36 > 0x00 && V_36 < 0x20 )
* V_35 = V_37 | V_38 | V_39 |
V_40 | V_41 ;
else
* V_35 = 0 ;
F_4 ( & V_6 -> V_2 , L_5 , V_36 ) ;
if ( V_2 -> V_42 != V_30 ) {
V_2 -> V_42 = V_30 ;
V_19 = F_1 ( V_2 , 0x6a43 , V_2 -> V_42 ) ;
if ( V_19 )
goto V_28;
}
return 0 ;
V_28:
F_4 ( & V_6 -> V_2 , L_3 , V_19 ) ;
return V_19 ;
}
struct V_13 * F_9 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_10 ( V_6 ) ;
F_4 ( & V_6 -> V_2 , L_4 ) ;
return & V_2 -> V_43 ;
}
static int F_11 ( struct V_44 * V_45 ,
struct V_46 V_47 [] , int V_48 )
{
struct V_1 * V_2 = F_12 ( V_45 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_19 , V_49 ;
unsigned long V_50 ;
T_2 V_36 ;
#define F_13 5
#define F_14 ( T_4 , T_5 ) \
(_num == 2 && !(_msg[0].flags & I2C_M_RD) && (_msg[1].flags & I2C_M_RD))
#define F_15 ( T_4 , T_5 ) \
(_num == 1 && !(_msg[0].flags & I2C_M_RD))
#define F_16 ( T_4 , T_5 ) \
(_num == 1 && (_msg[0].flags & I2C_M_RD))
if ( F_14 ( V_47 , V_48 ) ) {
F_4 ( & V_6 -> V_2 , L_6 ,
V_47 [ 0 ] . V_51 , V_47 [ 1 ] . V_51 ) ;
if ( V_47 [ 0 ] . V_51 > 1 || V_47 [ 1 ] . V_51 > 8 ) {
V_19 = - V_52 ;
goto V_28;
}
V_19 = F_1 ( V_2 , 0x6811 , 0x80 ) ;
if ( V_19 )
goto V_28;
V_19 = F_1 ( V_2 , 0x6812 , 0x05 ) ;
if ( V_19 )
goto V_28;
V_19 = F_1 ( V_2 , 0x6813 , V_47 [ 1 ] . V_53 << 1 ) ;
if ( V_19 )
goto V_28;
V_19 = F_1 ( V_2 , 0x6801 , V_47 [ 0 ] . V_54 [ 0 ] ) ;
if ( V_19 )
goto V_28;
V_19 = F_1 ( V_2 , 0x6802 , 0x00 ) ;
if ( V_19 )
goto V_28;
V_19 = F_1 ( V_2 , 0x6803 , 0x06 ) ;
if ( V_19 )
goto V_28;
V_19 = F_1 ( V_2 , 0x6805 , 0x00 ) ;
if ( V_19 )
goto V_28;
V_19 = F_1 ( V_2 , 0x6804 , V_47 [ 1 ] . V_51 ) ;
if ( V_19 )
goto V_28;
V_50 = V_55 + F_17 ( F_13 ) ;
for ( V_36 = 1 ; ! F_18 ( V_55 , V_50 ) && V_36 ; ) {
F_19 ( 500 , 800 ) ;
V_19 = F_2 ( V_2 , 0x6804 , & V_36 ) ;
if ( V_19 )
goto V_28;
}
for ( V_49 = 0 ; V_49 < V_47 [ 1 ] . V_51 ; V_49 ++ ) {
V_19 = F_2 ( V_2 , 0x0600 + V_49 , & V_47 [ 1 ] . V_54 [ V_49 ] ) ;
if ( V_19 )
goto V_28;
}
} else if ( F_15 ( V_47 , V_48 ) ) {
F_4 ( & V_6 -> V_2 , L_7 , V_47 [ 0 ] . V_51 ) ;
if ( V_47 [ 0 ] . V_51 > 1 + 8 ) {
V_19 = - V_52 ;
goto V_28;
}
V_19 = F_1 ( V_2 , 0x6811 , 0x80 ) ;
if ( V_19 )
goto V_28;
V_19 = F_1 ( V_2 , 0x6812 , 0x01 ) ;
if ( V_19 )
goto V_28;
V_19 = F_1 ( V_2 , 0x6813 , V_47 [ 0 ] . V_53 << 1 ) ;
if ( V_19 )
goto V_28;
V_19 = F_1 ( V_2 , 0x6800 , V_47 [ 0 ] . V_54 [ 0 ] ) ;
if ( V_19 )
goto V_28;
V_19 = F_1 ( V_2 , 0x6802 , 0x00 ) ;
if ( V_19 )
goto V_28;
V_19 = F_1 ( V_2 , 0x6803 , 0x06 ) ;
if ( V_19 )
goto V_28;
for ( V_49 = 0 ; V_49 < V_47 [ 0 ] . V_51 - 1 ; V_49 ++ ) {
V_19 = F_1 ( V_2 , 0x0600 + V_49 , V_47 [ 0 ] . V_54 [ 1 + V_49 ] ) ;
if ( V_19 )
goto V_28;
}
V_19 = F_1 ( V_2 , 0x6805 , 0x80 ) ;
if ( V_19 )
goto V_28;
V_19 = F_1 ( V_2 , 0x6804 , V_47 [ 0 ] . V_51 - 1 ) ;
if ( V_19 )
goto V_28;
V_50 = V_55 + F_17 ( F_13 ) ;
for ( V_36 = 1 ; ! F_18 ( V_55 , V_50 ) && V_36 ; ) {
F_19 ( 500 , 800 ) ;
V_19 = F_2 ( V_2 , 0x6804 , & V_36 ) ;
if ( V_19 )
goto V_28;
}
} else {
F_4 ( & V_6 -> V_2 , L_8 , V_47 [ 0 ] . V_51 ) ;
V_19 = - V_52 ;
if ( V_19 )
goto V_28;
}
return V_48 ;
V_28:
F_4 ( & V_6 -> V_2 , L_3 , V_19 ) ;
return V_19 ;
}
static T_3 F_20 ( struct V_44 * V_45 )
{
return V_56 ;
}
struct V_44 * F_21 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_10 ( V_6 ) ;
F_4 ( & V_6 -> V_2 , L_4 ) ;
return & V_2 -> V_45 ;
}
static int F_22 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
struct V_7 * V_8 = V_6 -> V_2 . V_9 ;
int V_19 ;
F_4 ( & V_6 -> V_2 , L_4 ) ;
if ( ! V_8 ) {
V_19 = - V_29 ;
F_23 ( & V_6 -> V_2 , L_9 ) ;
goto V_28;
}
if ( ! V_6 -> V_2 . V_57 -> V_58 ) {
V_19 = - V_29 ;
F_4 ( & V_6 -> V_2 , L_10 ) ;
goto V_28;
}
V_2 = F_24 ( sizeof( * V_2 ) , V_59 ) ;
if ( ! V_2 ) {
V_19 = - V_60 ;
goto V_28;
}
V_2 -> V_6 = V_6 ;
V_2 -> V_42 = V_30 ;
V_19 = F_1 ( V_2 , 0x6840 , 0x21 ) ;
if ( V_19 )
goto V_61;
V_19 = F_1 ( V_2 , 0x6a38 , 0x07 ) ;
if ( V_19 )
goto V_61;
F_25 ( V_2 -> V_45 . V_62 , L_11 , sizeof( V_2 -> V_45 . V_62 ) ) ;
V_2 -> V_45 . V_63 = & V_64 ;
V_2 -> V_45 . V_65 = NULL ;
V_2 -> V_45 . V_2 . V_57 = V_6 -> V_2 . V_57 ;
F_26 ( & V_2 -> V_45 , V_2 ) ;
V_19 = F_27 ( & V_2 -> V_45 ) ;
if ( V_19 ) {
F_23 ( & V_6 -> V_2 , L_12 , V_19 ) ;
goto V_61;
}
memcpy ( & V_2 -> V_43 . V_24 , & V_66 , sizeof( V_2 -> V_43 . V_24 ) ) ;
V_2 -> V_43 . V_15 = V_2 ;
F_28 ( V_6 , V_2 ) ;
F_29 ( & V_6 -> V_2 , L_13 ) ;
return 0 ;
V_61:
F_30 ( V_2 ) ;
V_28:
F_4 ( & V_6 -> V_2 , L_3 , V_19 ) ;
return V_19 ;
}
static int F_31 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_10 ( V_6 ) ;
F_4 ( & V_6 -> V_2 , L_4 ) ;
F_32 ( & V_2 -> V_45 ) ;
F_30 ( V_2 ) ;
return 0 ;
}
