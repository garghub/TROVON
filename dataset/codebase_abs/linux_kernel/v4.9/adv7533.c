static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = & V_2 -> V_7 ;
unsigned int V_8 , V_9 , V_10 , V_11 , V_12 , V_13 ;
T_1 V_14 [] = { 6 , 4 , 3 } ;
V_8 = V_6 -> V_15 - V_6 -> V_16 ;
V_9 = V_6 -> V_16 - V_6 -> V_17 ;
V_10 = V_6 -> V_18 - V_6 -> V_15 ;
V_11 = V_6 -> V_19 - V_6 -> V_20 ;
V_12 = V_6 -> V_20 - V_6 -> V_21 ;
V_13 = V_6 -> V_22 - V_6 -> V_19 ;
F_2 ( V_2 -> V_23 , 0x16 ,
V_14 [ V_4 -> V_24 - 2 ] << 3 ) ;
F_2 ( V_2 -> V_23 , 0x28 , V_6 -> V_18 >> 4 ) ;
F_2 ( V_2 -> V_23 , 0x29 , ( V_6 -> V_18 << 4 ) & 0xff ) ;
F_2 ( V_2 -> V_23 , 0x2a , V_8 >> 4 ) ;
F_2 ( V_2 -> V_23 , 0x2b , ( V_8 << 4 ) & 0xff ) ;
F_2 ( V_2 -> V_23 , 0x2c , V_9 >> 4 ) ;
F_2 ( V_2 -> V_23 , 0x2d , ( V_9 << 4 ) & 0xff ) ;
F_2 ( V_2 -> V_23 , 0x2e , V_10 >> 4 ) ;
F_2 ( V_2 -> V_23 , 0x2f , ( V_10 << 4 ) & 0xff ) ;
F_2 ( V_2 -> V_23 , 0x30 , V_6 -> V_22 >> 4 ) ;
F_2 ( V_2 -> V_23 , 0x31 , ( V_6 -> V_22 << 4 ) & 0xff ) ;
F_2 ( V_2 -> V_23 , 0x32 , V_11 >> 4 ) ;
F_2 ( V_2 -> V_23 , 0x33 , ( V_11 << 4 ) & 0xff ) ;
F_2 ( V_2 -> V_23 , 0x34 , V_12 >> 4 ) ;
F_2 ( V_2 -> V_23 , 0x35 , ( V_12 << 4 ) & 0xff ) ;
F_2 ( V_2 -> V_23 , 0x36 , V_13 >> 4 ) ;
F_2 ( V_2 -> V_23 , 0x37 , ( V_13 << 4 ) & 0xff ) ;
}
void F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_2 -> V_25 )
F_1 ( V_2 ) ;
F_2 ( V_2 -> V_23 , 0x1c , V_4 -> V_24 << 4 ) ;
if ( V_2 -> V_25 ) {
F_2 ( V_2 -> V_23 , 0x27 , 0xcb ) ;
F_2 ( V_2 -> V_23 , 0x27 , 0x8b ) ;
F_2 ( V_2 -> V_23 , 0x27 , 0xcb ) ;
} else {
F_2 ( V_2 -> V_23 , 0x27 , 0x0b ) ;
}
F_2 ( V_2 -> V_23 , 0x03 , 0x89 ) ;
F_2 ( V_2 -> V_23 , 0x55 , 0x00 ) ;
F_4 ( V_2 -> V_23 , V_26 ,
F_5 ( V_26 ) ) ;
}
void F_6 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_23 , 0x03 , 0x0b ) ;
F_2 ( V_2 -> V_23 , 0x27 , 0x0b ) ;
}
void F_7 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_24 , V_27 ;
if ( V_2 -> V_28 != 4 )
return;
if ( V_6 -> clock > 80000 )
V_24 = 4 ;
else
V_24 = 3 ;
if ( V_24 != V_4 -> V_24 ) {
F_8 ( V_4 ) ;
V_4 -> V_24 = V_24 ;
V_27 = F_9 ( V_4 ) ;
if ( V_27 )
F_10 ( & V_4 -> V_29 , L_1 ) ;
}
}
int F_11 ( struct V_1 * V_2 )
{
return F_4 ( V_2 -> V_30 ,
V_31 ,
F_5 ( V_31 ) ) ;
}
void F_12 ( struct V_1 * V_2 )
{
F_13 ( V_2 -> V_32 ) ;
}
int F_14 ( struct V_1 * V_2 )
{
int V_27 ;
V_2 -> V_32 = F_15 ( V_2 -> V_33 -> V_34 ,
V_2 -> V_33 -> V_35 - 1 ) ;
if ( ! V_2 -> V_32 )
return - V_36 ;
V_2 -> V_23 = F_16 ( V_2 -> V_32 ,
& V_37 ) ;
if ( F_17 ( V_2 -> V_23 ) ) {
V_27 = F_18 ( V_2 -> V_23 ) ;
goto V_38;
}
V_27 = F_4 ( V_2 -> V_23 ,
V_26 ,
F_5 ( V_26 ) ) ;
if ( V_27 )
goto V_38;
return 0 ;
V_38:
F_12 ( V_2 ) ;
return V_27 ;
}
int F_19 ( struct V_1 * V_2 )
{
struct V_39 * V_29 = & V_2 -> V_33 -> V_29 ;
struct V_40 * V_41 ;
struct V_3 * V_4 ;
int V_27 = 0 ;
const struct V_42 V_43 = { . type = L_2 ,
. V_44 = 0 ,
. V_45 = NULL ,
} ;
V_41 = F_20 ( V_2 -> V_46 ) ;
if ( ! V_41 ) {
F_10 ( V_29 , L_3 ) ;
return - V_47 ;
}
V_4 = F_21 ( V_41 , & V_43 ) ;
if ( F_17 ( V_4 ) ) {
F_10 ( V_29 , L_4 ) ;
V_27 = F_18 ( V_4 ) ;
goto V_48;
}
V_2 -> V_4 = V_4 ;
V_4 -> V_24 = V_2 -> V_28 ;
V_4 -> V_49 = V_50 ;
V_4 -> V_51 = V_52 | V_53 |
V_54 | V_55 ;
V_27 = F_9 ( V_4 ) ;
if ( V_27 < 0 ) {
F_10 ( V_29 , L_5 ) ;
goto V_56;
}
return 0 ;
V_56:
F_22 ( V_4 ) ;
V_48:
return V_27 ;
}
void F_23 ( struct V_1 * V_2 )
{
F_8 ( V_2 -> V_4 ) ;
F_22 ( V_2 -> V_4 ) ;
}
int F_24 ( struct V_57 * V_58 , struct V_1 * V_2 )
{
T_2 V_59 ;
struct V_57 * V_60 ;
F_25 ( V_58 , L_6 , & V_59 ) ;
if ( V_59 < 1 || V_59 > 4 )
return - V_61 ;
V_2 -> V_28 = V_59 ;
V_60 = F_26 ( V_58 , NULL ) ;
if ( ! V_60 )
return - V_62 ;
V_2 -> V_46 = F_27 ( V_60 ) ;
if ( ! V_2 -> V_46 ) {
F_28 ( V_60 ) ;
return - V_62 ;
}
F_28 ( V_60 ) ;
F_28 ( V_2 -> V_46 ) ;
V_2 -> V_25 = ! F_29 ( V_58 ,
L_7 ) ;
V_2 -> V_63 = true ;
V_2 -> V_64 = false ;
return 0 ;
}
