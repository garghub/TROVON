static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_2 * F_3 ( struct V_4 * V_5 )
{
return & F_2 ( V_5 -> V_6 , struct V_1 , V_7 ) -> V_3 ;
}
static int F_4 ( struct V_2 * V_3 , T_1 V_8 , T_1 V_9 )
{
struct V_10 * V_11 = F_5 ( V_3 ) ;
return F_6 ( V_11 , V_8 , V_9 ) ;
}
static int F_7 ( struct V_2 * V_3 , T_1 V_8 )
{
struct V_10 * V_11 = F_5 ( V_3 ) ;
return F_8 ( V_11 , V_8 ) ;
}
static int F_9 ( struct V_2 * V_3 ,
T_2 V_12 , T_2 V_13 , T_2 V_14 )
{
if ( V_12 > 2 ) {
F_10 ( V_3 , L_1 , V_12 ) ;
return - V_15 ;
}
F_4 ( V_3 , 0x01 , 0x01 + ( V_12 << 4 ) ) ;
return 0 ;
}
static int F_11 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
switch ( V_5 -> V_16 ) {
case V_17 :
F_4 ( V_3 , 0x03 , V_5 -> V_18 ? 0xf0 : 0x30 ) ;
return 0 ;
case V_19 :
F_4 ( V_3 , 0x04 , ( T_1 ) V_5 -> V_18 ) ;
F_4 ( V_3 , 0x05 , ( T_1 ) V_5 -> V_18 ) ;
return 0 ;
}
return - V_15 ;
}
static int F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
T_1 V_21 = F_7 ( V_3 , 0x01 ) ;
F_13 ( V_3 , L_2 , ( V_21 >> 4 ) & 3 ) ;
F_14 ( & V_20 -> V_7 , V_3 -> V_22 ) ;
return 0 ;
}
static int F_15 ( struct V_10 * V_11 ,
const struct V_23 * V_16 )
{
struct V_1 * V_20 ;
struct V_2 * V_3 ;
int V_24 ;
if ( ! F_16 ( V_11 -> V_25 , V_26 ) )
return - V_27 ;
if ( ! V_16 )
F_17 ( V_11 -> V_22 , L_3 , sizeof( V_11 -> V_22 ) ) ;
F_18 ( V_11 , L_4 ,
V_11 -> V_28 << 1 , V_11 -> V_25 -> V_22 ) ;
V_20 = F_19 ( & V_11 -> V_29 , sizeof( * V_20 ) , V_30 ) ;
if ( V_20 == NULL )
return - V_31 ;
V_3 = & V_20 -> V_3 ;
F_20 ( V_3 , V_11 , & V_32 ) ;
for ( V_24 = 1 ; V_24 <= 7 ; V_24 ++ ) {
T_1 V_21 = F_7 ( V_3 , V_24 ) ;
F_21 ( 1 , V_33 , V_3 , L_5 , V_24 , V_21 ) ;
}
F_22 ( & V_20 -> V_7 , 2 ) ;
F_23 ( & V_20 -> V_7 , & V_34 ,
V_19 , - 96 , 12 , 1 , 0 ) ;
F_23 ( & V_20 -> V_7 , & V_34 ,
V_17 , 0 , 1 , 1 , 0 ) ;
V_3 -> V_35 = & V_20 -> V_7 ;
if ( V_20 -> V_7 . error ) {
int V_36 = V_20 -> V_7 . error ;
F_24 ( & V_20 -> V_7 ) ;
return V_36 ;
}
F_4 ( V_3 , 0x01 , 0x21 ) ;
F_4 ( V_3 , 0x02 , 0x29 ) ;
F_4 ( V_3 , 0x03 , 0x30 ) ;
F_4 ( V_3 , 0x04 , 0x00 ) ;
F_4 ( V_3 , 0x05 , 0x00 ) ;
F_4 ( V_3 , 0x06 , 0x00 ) ;
F_4 ( V_3 , 0x07 , 0x00 ) ;
for ( V_24 = 1 ; V_24 <= 7 ; V_24 ++ ) {
T_1 V_21 = F_7 ( V_3 , V_24 ) ;
F_21 ( 1 , V_33 , V_3 , L_5 , V_24 , V_21 ) ;
}
return 0 ;
}
static int F_25 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = F_26 ( V_11 ) ;
struct V_1 * V_20 = F_1 ( V_3 ) ;
F_27 ( V_3 ) ;
F_24 ( & V_20 -> V_7 ) ;
return 0 ;
}
