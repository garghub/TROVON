static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_2 * F_3 ( struct V_4 * V_5 )
{
return & F_2 ( V_5 -> V_6 , struct V_1 , V_7 ) -> V_3 ;
}
static int F_4 ( struct V_2 * V_3 , int V_8 , int V_9 )
{
struct V_10 * V_11 = F_5 ( V_3 ) ;
unsigned char V_12 [ 2 ] ;
F_6 ( 2 , V_13 , V_3 , L_1 ) ;
F_6 ( 1 , V_13 , V_3 , L_2 , V_8 , V_9 ) ;
V_12 [ 0 ] = V_8 ;
V_12 [ 1 ] = V_9 ;
if ( 2 != F_7 ( V_11 , V_12 , 2 ) ) {
F_8 ( V_3 , L_3 ,
V_8 , V_9 ) ;
return - 1 ;
}
return 0 ;
}
static int F_9 ( struct V_2 * V_3 )
{
struct V_10 * V_11 = F_5 ( V_3 ) ;
unsigned char V_14 [ 16 ] ;
V_14 [ 0 ] = V_15 ;
V_14 [ 1 ] = V_16 |
V_17 |
V_18 ;
V_14 [ 2 ] = 0x3b ;
if ( V_19 )
V_14 [ 2 ] |= V_20 ;
V_14 [ 3 ] = V_21 | ( V_22 << 4 ) ;
V_14 [ 4 ] = V_23 ;
V_14 [ 5 ] = V_23 ;
V_14 [ 6 ] = V_23 ;
V_14 [ 7 ] = V_23 ;
V_14 [ 8 ] = V_19 ;
if ( 9 != F_7 ( V_11 , V_14 , 9 ) ) {
F_8 ( V_3 , L_4 ) ;
return - 1 ;
}
return 0 ;
}
static int F_10 ( struct V_2 * V_3 )
{
struct V_1 * V_24 = F_1 ( V_3 ) ;
F_11 ( & V_24 -> V_7 , V_3 -> V_25 ) ;
return 0 ;
}
static int F_12 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
struct V_1 * V_26 = F_1 ( V_3 ) ;
T_1 V_27 , V_28 , V_29 ;
T_1 V_30 , V_31 , V_32 , V_33 ;
switch ( V_5 -> V_34 ) {
case V_35 :
if ( V_26 -> V_36 -> V_9 < 0 ) {
V_33 = V_32 = - V_26 -> V_36 -> V_9 ;
V_31 = V_30 = V_23 ;
} else if ( V_26 -> V_36 -> V_9 > 0 ) {
V_33 = V_32 = V_23 ;
V_31 = V_30 = V_26 -> V_36 -> V_9 ;
} else {
V_33 = V_32 = V_23 ;
V_31 = V_30 = V_23 ;
}
if ( V_26 -> V_37 -> V_9 ) {
V_30 |= V_38 ;
V_31 |= V_38 ;
V_32 |= V_38 ;
V_33 |= V_38 ;
}
F_4 ( V_3 , V_39 , V_30 ) ;
F_4 ( V_3 , V_40 , V_31 ) ;
F_4 ( V_3 , V_41 , V_32 ) ;
F_4 ( V_3 , V_42 , V_33 ) ;
return 0 ;
case V_43 :
V_29 = 0x6f - V_5 -> V_9 ;
if ( V_19 )
V_29 |= V_20 ;
F_4 ( V_3 , V_44 , V_29 ) ;
return 0 ;
case V_45 :
V_27 = V_26 -> V_27 -> V_9 ;
V_28 = V_26 -> V_28 -> V_9 ;
if ( V_27 >= 0x8 )
V_27 = 14 - ( V_27 - 8 ) ;
if ( V_28 >= 0x8 )
V_28 = 14 - ( V_28 - 8 ) ;
F_4 ( V_3 , V_46 , 0x10 | ( V_27 << 4 ) | V_28 ) ;
return 0 ;
}
return - V_47 ;
}
static int F_13 ( struct V_10 * V_11 ,
const struct V_48 * V_34 )
{
struct V_1 * V_26 ;
struct V_2 * V_3 ;
F_14 ( V_11 , L_5 ,
V_11 -> V_49 << 1 , V_11 -> V_50 -> V_25 ) ;
V_26 = F_15 ( & V_11 -> V_51 , sizeof( * V_26 ) , V_52 ) ;
if ( ! V_26 )
return - V_53 ;
V_3 = & V_26 -> V_3 ;
F_16 ( V_3 , V_11 , & V_54 ) ;
F_17 ( & V_26 -> V_7 , 5 ) ;
F_18 ( & V_26 -> V_7 , & V_55 ,
V_43 , 0 , V_56 ? 0x68 : 0x4f , 1 , V_56 ? 0x5d : 0x47 ) ;
V_26 -> V_37 = F_18 ( & V_26 -> V_7 , & V_55 ,
V_35 , 0 , 1 , 1 , 0 ) ;
V_26 -> V_36 = F_18 ( & V_26 -> V_7 , & V_55 ,
V_57 , - 31 , 31 , 1 , 0 ) ;
V_26 -> V_27 = F_18 ( & V_26 -> V_7 , & V_55 ,
V_45 , 0 , 14 , 1 , 7 ) ;
V_26 -> V_28 = F_18 ( & V_26 -> V_7 , & V_55 ,
V_58 , 0 , 14 , 1 , 7 ) ;
V_3 -> V_59 = & V_26 -> V_7 ;
if ( V_26 -> V_7 . error ) {
int V_60 = V_26 -> V_7 . error ;
F_19 ( & V_26 -> V_7 ) ;
return V_60 ;
}
F_20 ( 2 , & V_26 -> V_27 ) ;
F_20 ( 2 , & V_26 -> V_37 ) ;
F_21 ( & V_26 -> V_7 ) ;
if ( V_19 < 0 || V_19 > 15 ) {
F_22 ( V_3 , L_6 ) ;
if ( V_19 < 0 )
V_19 = 0 ;
if ( V_19 > 15 )
V_19 = 15 ;
}
F_9 ( V_3 ) ;
return 0 ;
}
static int F_23 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = F_24 ( V_11 ) ;
struct V_1 * V_26 = F_1 ( V_3 ) ;
F_9 ( V_3 ) ;
F_25 ( V_3 ) ;
F_19 ( & V_26 -> V_7 ) ;
return 0 ;
}
