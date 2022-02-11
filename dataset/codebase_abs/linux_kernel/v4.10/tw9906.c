static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , T_1 V_4 , T_1 V_5 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
return F_5 ( V_7 , V_4 , V_5 ) ;
}
static int F_6 ( struct V_2 * V_3 , const T_1 * V_8 )
{
int V_9 ;
for ( V_9 = 0 ; V_8 [ V_9 ] != 0x00 ; V_9 += 2 )
if ( F_3 ( V_3 , V_8 [ V_9 ] , V_8 [ V_9 + 1 ] ) < 0 )
return - 1 ;
return 0 ;
}
static int F_7 ( struct V_2 * V_3 , T_2 V_10 ,
T_2 V_11 , T_2 V_12 )
{
F_3 ( V_3 , 0x02 , 0x40 | ( V_10 << 1 ) ) ;
return 0 ;
}
static int F_8 ( struct V_2 * V_3 , T_3 V_13 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
bool V_15 = V_13 & V_16 ;
static const T_1 V_17 [] = {
0x05 , 0x81 ,
0x07 , 0x02 ,
0x08 , 0x14 ,
0x09 , 0xf0 ,
0 , 0 ,
} ;
static const T_1 V_18 [] = {
0x05 , 0x01 ,
0x07 , 0x12 ,
0x08 , 0x18 ,
0x09 , 0x20 ,
0 , 0 ,
} ;
F_6 ( V_3 , V_15 ? V_17 : V_18 ) ;
V_14 -> V_13 = V_13 ;
return 0 ;
}
static int F_9 ( struct V_19 * V_20 )
{
struct V_1 * V_14 = F_2 ( V_20 -> V_21 , struct V_1 , V_22 ) ;
struct V_2 * V_3 = & V_14 -> V_3 ;
switch ( V_20 -> V_23 ) {
case V_24 :
F_3 ( V_3 , 0x10 , V_20 -> V_25 ) ;
break;
case V_26 :
F_3 ( V_3 , 0x11 , V_20 -> V_25 ) ;
break;
case V_27 :
F_3 ( V_3 , 0x15 , V_20 -> V_25 ) ;
break;
default:
return - V_28 ;
}
return 0 ;
}
static int F_10 ( struct V_2 * V_3 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
bool V_15 = V_14 -> V_13 & V_16 ;
F_11 ( V_3 , L_1 , V_15 ? 60 : 50 ) ;
F_12 ( V_3 ) ;
return 0 ;
}
static int F_13 ( struct V_6 * V_7 ,
const struct V_29 * V_23 )
{
struct V_1 * V_14 ;
struct V_2 * V_3 ;
struct V_30 * V_22 ;
if ( ! F_14 ( V_7 -> V_31 , V_32 ) )
return - V_33 ;
F_15 ( V_7 , L_2 ,
V_7 -> V_34 << 1 , V_7 -> V_31 -> V_35 ) ;
V_14 = F_16 ( & V_7 -> V_36 , sizeof( * V_14 ) , V_37 ) ;
if ( V_14 == NULL )
return - V_38 ;
V_3 = & V_14 -> V_3 ;
F_17 ( V_3 , V_7 , & V_39 ) ;
V_22 = & V_14 -> V_22 ;
F_18 ( V_22 , 4 ) ;
F_19 ( V_22 , & V_40 ,
V_24 , - 128 , 127 , 1 , 0 ) ;
F_19 ( V_22 , & V_40 ,
V_26 , 0 , 255 , 1 , 0x60 ) ;
F_19 ( V_22 , & V_40 ,
V_27 , - 128 , 127 , 1 , 0 ) ;
V_3 -> V_41 = V_22 ;
if ( V_22 -> error ) {
int V_42 = V_22 -> error ;
F_20 ( V_22 ) ;
return V_42 ;
}
V_14 -> V_13 = V_43 ;
if ( F_6 ( V_3 , V_44 ) < 0 ) {
F_21 ( V_7 , L_3 ) ;
return - V_28 ;
}
return 0 ;
}
static int F_22 ( struct V_6 * V_7 )
{
struct V_2 * V_3 = F_23 ( V_7 ) ;
F_24 ( V_3 ) ;
F_20 ( & F_1 ( V_3 ) -> V_22 ) ;
return 0 ;
}
