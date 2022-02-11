static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
int V_4 ;
F_2 ( & V_2 -> V_5 ) ;
if ( V_2 -> V_6 == V_3 )
return 0 ;
V_4 = F_3 ( V_2 -> V_7 , V_8 , V_3 ) ;
if ( V_4 == 0 )
V_2 -> V_6 = V_3 ;
else
V_2 -> V_6 = - 1 ;
return V_4 ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_5 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned V_3 , unsigned V_9 )
{
struct V_10 * V_7 = V_2 -> V_7 ;
int V_4 ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( V_4 == 0 )
V_4 = F_7 ( V_7 , V_9 ) ;
F_4 ( V_2 ) ;
return V_4 ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned V_3 , unsigned V_9 )
{
struct V_10 * V_7 = V_2 -> V_7 ;
int V_4 , V_11 ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( V_4 == 0 ) {
V_4 = F_7 ( V_7 , V_9 ) ;
if ( V_4 >= 0 ) {
V_11 = V_4 ;
V_4 = F_7 ( V_7 , V_9 + 1 ) ;
if ( V_4 >= 0 )
V_4 |= V_11 << 8 ;
}
}
F_4 ( V_2 ) ;
return V_4 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned V_3 , unsigned V_9 , T_1 V_12 )
{
struct V_10 * V_7 = V_2 -> V_7 ;
int V_4 ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( V_4 == 0 )
V_4 = F_3 ( V_7 , V_9 , V_12 ) ;
F_4 ( V_2 ) ;
return V_4 ;
}
static T_2 F_10 ( struct V_13 * V_14 ,
struct V_15 * V_16 , char * V_17 )
{
int V_18 = F_11 ( V_16 ) -> V_18 ;
struct V_1 * V_2 = F_12 ( V_14 ) ;
int V_4 ;
unsigned V_19 , V_20 ;
V_4 = F_8 ( V_2 , V_21 , V_22 + V_18 * 2 ) ;
if ( V_4 < 0 )
return V_4 ;
V_19 = ( ( V_4 & 0xff00 ) >> 3 ) | ( V_4 & 0x1f ) ;
if ( V_19 == 0x1fff )
V_20 = 0 ;
else
V_20 = 1350000 / V_19 ;
return sprintf ( V_17 , L_1 , V_20 ) ;
}
static T_3 F_13 ( struct V_23 * V_24 ,
struct V_25 * V_26 , int V_27 )
{
struct V_13 * V_14 = F_14 ( V_24 , struct V_13 , V_24 ) ;
struct V_1 * V_2 = F_12 ( V_14 ) ;
if ( V_2 -> V_28 & ( 1 << V_27 ) )
return V_26 -> V_29 ;
return 0 ;
}
static T_2 F_15 ( struct V_13 * V_14 ,
struct V_15 * V_16 , char * V_17 )
{
int V_18 = F_11 ( V_16 ) -> V_18 ;
struct V_1 * V_2 = F_12 ( V_14 ) ;
int V_4 ;
int V_30 ;
V_4 = F_8 ( V_2 , V_21 , V_31 + V_18 * 2 ) ;
if ( V_4 < 0 )
return V_4 ;
V_30 = ( ( V_4 & 0xff00 ) >> 5 ) | ( V_4 & 0x7 ) ;
if ( V_18 < 14 )
V_30 *= 2 ;
else
V_30 *= 6 ;
return sprintf ( V_17 , L_2 , V_30 ) ;
}
static T_2 F_16 ( struct V_13 * V_14 ,
struct V_15 * V_16 , char * V_17 )
{
struct V_1 * V_2 = F_12 ( V_14 ) ;
int V_4 ;
int V_32 ;
V_4 = F_8 ( V_2 , V_21 , V_33 ) ;
if ( V_4 < 0 )
return V_4 ;
V_32 = ( ( V_4 & 0xff00 ) >> 5 ) | ( V_4 & 0x7 ) ;
V_32 = F_17 ( V_32 , 10 ) * 125 ;
return sprintf ( V_17 , L_2 , V_32 ) ;
}
static T_3 F_18 ( struct V_23 * V_24 ,
struct V_25 * V_26 , int V_27 )
{
struct V_13 * V_14 = F_14 ( V_24 , struct V_13 , V_24 ) ;
struct V_1 * V_2 = F_12 ( V_14 ) ;
if ( V_2 -> V_34 & ( 1 << V_27 ) )
return V_26 -> V_29 ;
return 0 ;
}
static T_2 F_19 ( struct V_13 * V_14 ,
struct V_15 * V_16 , char * V_17 )
{
int V_18 = F_11 ( V_16 ) -> V_18 ;
struct V_1 * V_2 = F_12 ( V_14 ) ;
int V_4 ;
int V_32 ;
V_4 = F_8 ( V_2 , V_21 , V_35 + V_18 * 2 ) ;
if ( V_4 < 0 )
return V_4 ;
V_32 = ( ( V_4 & 0xff00 ) >> 5 ) | ( V_4 & 0x7 ) ;
V_32 = F_17 ( V_32 , 10 ) * 125 ;
return sprintf ( V_17 , L_2 , V_32 ) ;
}
static T_3 F_20 ( struct V_23 * V_24 ,
struct V_25 * V_26 , int V_27 )
{
struct V_13 * V_14 = F_14 ( V_24 , struct V_13 , V_24 ) ;
struct V_1 * V_2 = F_12 ( V_14 ) ;
if ( V_2 -> V_36 & ( 1 << V_27 ) )
return V_26 -> V_29 ;
return 0 ;
}
static T_2 F_21 ( struct V_13 * V_14 , struct V_15 * V_16 ,
const char * V_17 , T_4 V_37 )
{
int V_18 = F_11 ( V_16 ) -> V_18 ;
struct V_1 * V_2 = F_12 ( V_14 ) ;
unsigned long V_12 ;
int V_4 ;
if ( F_22 ( V_17 , 10 , & V_12 ) < 0 )
return - V_38 ;
if ( V_12 > 255 )
return - V_38 ;
V_4 = F_9 ( V_2 , V_39 , V_40 + V_18 , V_12 ) ;
return V_4 ? V_4 : V_37 ;
}
static T_2 F_23 ( struct V_13 * V_14 ,
struct V_15 * V_16 , char * V_17 )
{
int V_18 = F_11 ( V_16 ) -> V_18 ;
struct V_1 * V_2 = F_12 ( V_14 ) ;
int V_12 ;
V_12 = F_6 ( V_2 , V_39 , V_40 + V_18 ) ;
if ( V_12 < 0 )
return V_12 ;
return sprintf ( V_17 , L_2 , V_12 ) ;
}
static T_2 F_24 ( struct V_13 * V_14 , struct V_15 * V_16 ,
const char * V_17 , T_4 V_37 )
{
int V_18 = F_11 ( V_16 ) -> V_18 ;
struct V_1 * V_2 = F_12 ( V_14 ) ;
unsigned long V_12 ;
int V_4 ;
if ( F_22 ( V_17 , 10 , & V_12 ) < 0 )
return - V_38 ;
if ( V_12 > 1 || ( V_12 && ! V_2 -> V_41 [ V_18 ] ) )
return - V_38 ;
V_4 = F_9 ( V_2 , V_39 , V_42 + V_18 ,
V_12 ? V_2 -> V_41 [ V_18 ] : 0 ) ;
return V_4 ? V_4 : V_37 ;
}
static T_2 F_25 ( struct V_13 * V_14 ,
struct V_15 * V_16 , char * V_17 )
{
int V_18 = F_11 ( V_16 ) -> V_18 ;
struct V_1 * V_2 = F_12 ( V_14 ) ;
int V_12 ;
V_12 = F_6 ( V_2 , V_39 , V_42 + V_18 ) ;
if ( V_12 < 0 )
return V_12 ;
return sprintf ( V_17 , L_2 , V_12 ? 1 : 0 ) ;
}
static int F_26 ( struct V_10 * V_7 ,
struct V_43 * V_44 )
{
struct V_45 * V_46 = V_7 -> V_46 ;
if ( ! F_27 ( V_46 ,
V_47 |
V_48 ) )
return - V_49 ;
if ( F_7 ( V_7 , V_50 ) != V_51 ||
F_7 ( V_7 , V_52 ) != V_53 ||
( F_7 ( V_7 , V_54 ) & 0xf0 ) != 0x50 ||
( F_7 ( V_7 , V_8 ) & 0xf8 ) != 0x00 )
return - V_49 ;
F_28 ( V_44 -> type , L_3 , V_55 ) ;
return 0 ;
}
static int F_29 ( struct V_10 * V_7 ,
const struct V_56 * V_57 )
{
struct V_1 * V_2 ;
struct V_13 * V_58 ;
struct V_13 * V_14 = & V_7 -> V_14 ;
int V_4 , V_59 ;
T_5 V_60 ;
V_2 = F_30 ( V_14 , sizeof( struct V_1 ) , V_61 ) ;
if ( ! V_2 )
return - V_62 ;
V_2 -> V_7 = V_7 ;
F_31 ( & V_2 -> V_5 ) ;
V_2 -> V_6 = - 1 ;
V_4 = F_8 ( V_2 , V_21 , V_63 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_28 = ( V_4 >> 8 ) | ( ( V_4 & 0xff ) << 8 ) ;
V_60 = 0 ;
V_4 = F_8 ( V_2 , V_21 , V_64 ) ;
if ( V_4 >= 0 )
V_60 = ( V_4 >> 8 ) | ( ( V_4 & 0xff ) << 8 ) ;
V_4 = F_6 ( V_2 , V_21 , V_65 ) ;
if ( V_4 >= 0 )
V_60 |= ( V_4 << 16 ) ;
V_2 -> V_34 = V_60 ;
V_4 = F_8 ( V_2 , V_21 , V_66 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_36 = ( ( V_4 >> 8 ) & 0xf ) | ( ( V_4 & 0xf ) << 4 ) ;
for ( V_59 = 0 ; V_59 < V_67 ; V_59 ++ ) {
V_4 = F_6 ( V_2 , V_39 , V_42 + V_59 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_41 [ V_59 ] = V_4 ;
}
V_58 =
F_32 ( V_14 , V_7 -> V_68 , V_2 ,
V_69 ) ;
return F_33 ( V_58 ) ;
}
