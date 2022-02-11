static int F_1 ( struct V_1 * V_2 , const void * V_3 , T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
return F_3 ( V_6 , V_3 , V_4 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
F_5 ( V_2 , 0xf0 , 0x5a , 0x5a ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
F_5 ( V_2 , 0xf0 , 0xa5 , 0xa5 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
F_5 ( V_2 , 0xfc , 0x5a , 0x5a ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
F_5 ( V_2 , 0xfc , 0xa5 , 0xa5 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
F_5 ( V_2 , 0xf2 , 0x67 ) ;
F_5 ( V_2 , 0xf9 , 0x09 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
F_5 ( V_2 , 0xfd , 0x1c ) ;
if ( V_2 -> V_8 -> type == V_9 )
F_5 ( V_2 , 0xf2 , 0x67 , 0x40 , 0xc5 ) ;
F_5 ( V_2 , 0xfe , 0x20 , 0x39 ) ;
F_5 ( V_2 , 0xfe , 0xa0 ) ;
F_5 ( V_2 , 0xfe , 0x20 ) ;
if ( V_2 -> V_8 -> type == V_10 )
F_5 ( V_2 , 0xce , 0x03 , 0x3b , 0x12 , 0x62 ,
0x40 , 0x80 , 0xc0 , 0x28 , 0x28 ,
0x28 , 0x28 , 0x39 , 0xc5 ) ;
else
F_5 ( V_2 , 0xce , 0x03 , 0x3b , 0x14 , 0x6d ,
0x40 , 0x80 , 0xc0 , 0x28 , 0x28 ,
0x28 , 0x28 , 0x39 , 0xc5 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
F_5 ( V_2 , 0xb2 , 0x03 , 0x10 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
F_5 ( V_2 , 0xb6 , 0x9c , 0x0a ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
F_5 ( V_2 , 0x55 , 0x00 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
F_5 ( V_2 , 0xb5 , 0x40 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
F_5 ( V_2 , 0xb0 , 0x07 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
F_5 ( V_2 , 0xb8 , 0x19 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
F_5 ( V_2 , 0xbd , 0x33 , 0x11 , 0x02 ,
0x16 , 0x02 , 0x16 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
F_5 ( V_2 , 0xc0 , 0x00 , 0x00 , 0xd8 , 0xd8 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
F_5 ( V_2 , 0xb0 , 0x20 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
F_5 ( V_2 , 0xfe , 0x08 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
F_5 ( V_2 , 0xcc , 0x40 , 0x51 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
F_5 ( V_2 , 0xed , 0x44 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
F_5 ( V_2 , 0x53 , 0x00 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
F_5 ( V_2 , 0xb9 , 0x10 , 0x09 , 0xff , 0x00 , 0x09 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
F_5 ( V_2 , 0xf7 , 0x03 ) ;
F_26 ( 100 ) ;
F_5 ( V_2 , 0xf7 , 0x00 ) ;
return 0 ;
}
static int F_27 ( struct V_11 * V_12 )
{
return V_12 -> V_13 . V_14 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
unsigned int V_14 = V_12 -> V_13 . V_14 ;
unsigned char V_3 [] = { 0xf4 , 0x8b ,
V_15 [ V_14 * ( V_16 - 1 ) /
V_17 ] } ;
return F_1 ( V_2 , V_3 , F_29 ( V_3 ) ) ;
}
static unsigned int F_30 ( unsigned int V_14 )
{
return ( V_14 * ( V_18 - 1 ) ) /
V_17 ;
}
static int F_31 ( struct V_1 * V_2 , unsigned int V_14 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
unsigned int V_19 = F_30 ( V_14 ) ;
T_2 V_3 [ V_20 + 1 ] = { 0xca , } ;
int V_21 ;
memcpy ( V_3 + 1 , V_22 + V_19 , V_20 ) ;
F_32 ( V_21 ,
F_1 ( V_2 , V_3 , F_29 ( V_3 ) ) ) ;
F_32 ( V_21 , F_25 ( V_2 ) ) ;
V_12 -> V_13 . V_14 = V_14 ;
return 0 ;
}
static int F_33 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_34 ( V_12 ) ;
unsigned int V_14 = V_12 -> V_13 . V_14 ;
int V_21 ;
if ( V_14 < V_23 ||
V_14 > V_12 -> V_13 . V_24 ) {
F_35 ( V_2 -> V_7 , L_1 , V_14 ) ;
return - V_25 ;
}
if ( V_12 -> V_13 . V_26 > V_27 )
return - V_28 ;
F_32 ( V_21 , F_4 ( V_2 ) ) ;
F_32 ( V_21 , F_31 ( V_2 , V_14 ) ) ;
F_32 ( V_21 , F_11 ( V_2 ) ) ;
F_32 ( V_21 , F_28 ( V_2 ) ) ;
F_32 ( V_21 , F_6 ( V_2 ) ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
int V_21 ;
F_32 ( V_21 , F_37 ( V_6 ) ) ;
F_38 ( 5000 , 6000 ) ;
F_32 ( V_21 , F_4 ( V_2 ) ) ;
F_32 ( V_21 , F_9 ( V_2 ) ) ;
F_32 ( V_21 , F_7 ( V_2 ) ) ;
F_32 ( V_21 , F_10 ( V_2 ) ) ;
F_32 ( V_21 , F_8 ( V_2 ) ) ;
F_32 ( V_21 , F_6 ( V_2 ) ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
return F_40 ( F_29 ( V_2 -> V_29 ) , V_2 -> V_29 ) ;
}
static int F_41 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_42 ( V_31 , struct V_1 , V_31 ) ;
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
int V_21 ;
F_32 ( V_21 , F_43 ( V_6 ) ) ;
F_32 ( V_21 , F_44 ( V_6 ) ) ;
F_45 ( 40 ) ;
V_2 -> V_12 -> V_13 . V_26 = V_27 ;
return 0 ;
}
static int F_46 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_42 ( V_31 , struct V_1 , V_31 ) ;
return F_39 ( V_2 ) ;
}
static int F_47 ( struct V_1 * V_2 )
{
int V_21 ;
V_21 = F_48 ( F_29 ( V_2 -> V_29 ) , V_2 -> V_29 ) ;
if ( V_21 < 0 )
return V_21 ;
F_45 ( 120 ) ;
F_49 ( V_2 -> V_32 , 0 ) ;
F_38 ( 5000 , 6000 ) ;
F_49 ( V_2 -> V_32 , 1 ) ;
F_49 ( V_2 -> V_33 , 1 ) ;
F_38 ( 5000 , 6000 ) ;
F_49 ( V_2 -> V_33 , 0 ) ;
F_38 ( 5000 , 6000 ) ;
return 0 ;
}
static int F_50 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_42 ( V_31 , struct V_1 , V_31 ) ;
int V_21 ;
V_21 = F_47 ( V_2 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_36 ( V_2 ) ;
if ( V_21 < 0 )
goto V_34;
V_2 -> V_12 -> V_13 . V_26 = V_27 ;
return 0 ;
V_34:
F_39 ( V_2 ) ;
return V_21 ;
}
static int F_51 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_42 ( V_31 , struct V_1 , V_31 ) ;
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
int V_21 ;
F_32 ( V_21 ,
F_52 ( V_6 , V_35 ) ) ;
F_32 ( V_21 , F_4 ( V_2 ) ) ;
F_32 ( V_21 , F_7 ( V_2 ) ) ;
F_32 ( V_21 , F_17 ( V_2 ) ) ;
F_32 ( V_21 , F_18 ( V_2 ) ) ;
F_32 ( V_21 , F_19 ( V_2 ) ) ;
F_32 ( V_21 , F_20 ( V_2 ) ) ;
F_32 ( V_21 , F_8 ( V_2 ) ) ;
F_32 ( V_21 , F_21 ( V_2 ) ) ;
F_32 ( V_21 , F_22 ( V_2 ) ) ;
F_32 ( V_21 , F_24 ( V_2 ) ) ;
F_32 ( V_21 , F_33 ( V_2 -> V_12 ) ) ;
F_32 ( V_21 , F_11 ( V_2 ) ) ;
F_32 ( V_21 , F_12 ( V_2 ) ) ;
F_32 ( V_21 , F_25 ( V_2 ) ) ;
F_32 ( V_21 , F_13 ( V_2 ) ) ;
F_32 ( V_21 , F_14 ( V_2 ) ) ;
F_32 ( V_21 , F_23 ( V_2 ) ) ;
F_32 ( V_21 , F_15 ( V_2 ) ) ;
F_32 ( V_21 , F_16 ( V_2 ) ) ;
F_32 ( V_21 , F_6 ( V_2 ) ) ;
F_32 ( V_21 , F_53 ( V_6 ) ) ;
V_2 -> V_12 -> V_13 . V_26 = V_36 ;
return 0 ;
}
static int F_54 ( struct V_30 * V_31 )
{
struct V_37 * V_38 = V_31 -> V_38 ;
struct V_1 * V_2 = F_42 ( V_31 , struct V_1 , V_31 ) ;
struct V_39 * V_40 ;
V_40 = F_55 ( V_31 -> V_41 , V_2 -> V_8 -> V_40 ) ;
if ( ! V_40 ) {
F_56 ( L_2 ,
V_2 -> V_8 -> V_40 -> V_42 , V_2 -> V_8 -> V_40 -> V_43 ,
V_2 -> V_8 -> V_40 -> V_44 ) ;
return - V_45 ;
}
F_57 ( V_40 ) ;
V_40 -> type = V_46 | V_47 ;
F_58 ( V_38 , V_40 ) ;
V_38 -> V_48 . V_49 = 71 ;
V_38 -> V_48 . V_50 = 125 ;
return 1 ;
}
static int F_59 ( struct V_5 * V_6 )
{
struct V_51 * V_7 = & V_6 -> V_7 ;
struct V_1 * V_2 ;
int V_21 ;
V_2 = F_60 ( V_7 , sizeof( * V_2 ) , V_52 ) ;
if ( ! V_2 )
return - V_45 ;
F_61 ( V_6 , V_2 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_8 = F_62 ( V_7 ) ;
V_6 -> V_53 = 4 ;
V_6 -> V_54 = V_55 ;
V_6 -> V_56 = V_57 ;
V_2 -> V_29 [ 0 ] . V_58 = L_3 ;
V_2 -> V_29 [ 1 ] . V_58 = L_4 ;
V_21 = F_63 ( V_7 , F_29 ( V_2 -> V_29 ) ,
V_2 -> V_29 ) ;
if ( V_21 < 0 ) {
F_35 ( V_7 , L_5 , V_21 ) ;
return V_21 ;
}
V_2 -> V_33 = F_64 ( V_7 , L_6 , V_59 ) ;
if ( F_65 ( V_2 -> V_33 ) ) {
F_35 ( V_7 , L_7 ,
F_66 ( V_2 -> V_33 ) ) ;
return F_66 ( V_2 -> V_33 ) ;
}
V_2 -> V_32 = F_64 ( V_7 , L_8 , V_60 ) ;
if ( F_65 ( V_2 -> V_32 ) ) {
F_35 ( V_7 , L_9 ,
F_66 ( V_2 -> V_32 ) ) ;
return F_66 ( V_2 -> V_32 ) ;
}
V_2 -> V_12 = F_67 ( L_10 , V_7 , V_2 ,
& V_61 , NULL ) ;
if ( F_65 ( V_2 -> V_12 ) ) {
F_35 ( V_7 , L_11 ) ;
return F_66 ( V_2 -> V_12 ) ;
}
V_2 -> V_12 -> V_13 . V_24 = V_17 ;
V_2 -> V_12 -> V_13 . V_14 = V_62 ;
V_2 -> V_12 -> V_13 . V_26 = V_63 ;
F_68 ( & V_2 -> V_31 ) ;
V_2 -> V_31 . V_7 = V_7 ;
V_2 -> V_31 . V_64 = & V_65 ;
V_21 = F_69 ( & V_2 -> V_31 ) ;
if ( V_21 < 0 )
goto V_66;
V_21 = F_70 ( V_6 ) ;
if ( V_21 < 0 )
goto V_67;
return V_21 ;
V_67:
F_71 ( & V_2 -> V_31 ) ;
V_66:
F_72 ( V_2 -> V_12 ) ;
return V_21 ;
}
static int F_73 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_74 ( V_6 ) ;
F_75 ( V_6 ) ;
F_71 ( & V_2 -> V_31 ) ;
F_72 ( V_2 -> V_12 ) ;
return 0 ;
}
