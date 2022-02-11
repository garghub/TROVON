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
static int F_12 ( struct V_2 * V_3 , struct V_20 * V_21 )
{
struct V_10 * V_11 = F_5 ( V_3 ) ;
return F_13 ( V_11 ,
V_21 , V_22 , 0 ) ;
}
static int F_14 ( struct V_2 * V_3 )
{
struct V_1 * V_23 = F_1 ( V_3 ) ;
T_1 V_24 = F_7 ( V_3 , 0x01 ) ;
F_15 ( V_3 , L_2 , ( V_24 >> 4 ) & 3 ) ;
F_16 ( & V_23 -> V_7 , V_3 -> V_25 ) ;
return 0 ;
}
static int F_17 ( struct V_10 * V_11 ,
const struct V_26 * V_16 )
{
struct V_1 * V_23 ;
struct V_2 * V_3 ;
int V_27 ;
if ( ! F_18 ( V_11 -> V_28 , V_29 ) )
return - V_30 ;
if ( ! V_16 )
F_19 ( V_11 -> V_25 , L_3 , sizeof( V_11 -> V_25 ) ) ;
F_20 ( V_11 , L_4 ,
V_11 -> V_31 << 1 , V_11 -> V_28 -> V_25 ) ;
V_23 = F_21 ( sizeof( struct V_1 ) , V_32 ) ;
if ( V_23 == NULL )
return - V_33 ;
V_3 = & V_23 -> V_3 ;
F_22 ( V_3 , V_11 , & V_34 ) ;
for ( V_27 = 1 ; V_27 <= 7 ; V_27 ++ ) {
T_1 V_24 = F_7 ( V_3 , V_27 ) ;
F_23 ( 1 , V_35 , V_3 , L_5 , V_27 , V_24 ) ;
}
F_24 ( & V_23 -> V_7 , 2 ) ;
F_25 ( & V_23 -> V_7 , & V_36 ,
V_19 , - 96 , 12 , 1 , 0 ) ;
F_25 ( & V_23 -> V_7 , & V_36 ,
V_17 , 0 , 1 , 1 , 0 ) ;
V_3 -> V_37 = & V_23 -> V_7 ;
if ( V_23 -> V_7 . error ) {
int V_38 = V_23 -> V_7 . error ;
F_26 ( & V_23 -> V_7 ) ;
F_27 ( V_23 ) ;
return V_38 ;
}
F_4 ( V_3 , 0x01 , 0x21 ) ;
F_4 ( V_3 , 0x02 , 0x29 ) ;
F_4 ( V_3 , 0x03 , 0x30 ) ;
F_4 ( V_3 , 0x04 , 0x00 ) ;
F_4 ( V_3 , 0x05 , 0x00 ) ;
F_4 ( V_3 , 0x06 , 0x00 ) ;
F_4 ( V_3 , 0x07 , 0x00 ) ;
for ( V_27 = 1 ; V_27 <= 7 ; V_27 ++ ) {
T_1 V_24 = F_7 ( V_3 , V_27 ) ;
F_23 ( 1 , V_35 , V_3 , L_5 , V_27 , V_24 ) ;
}
return 0 ;
}
static int F_28 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = F_29 ( V_11 ) ;
struct V_1 * V_23 = F_1 ( V_3 ) ;
F_30 ( V_3 ) ;
F_26 ( & V_23 -> V_7 ) ;
F_27 ( V_23 ) ;
return 0 ;
}
static T_3 int F_31 ( void )
{
return F_32 ( & V_39 ) ;
}
static T_4 void F_33 ( void )
{
F_34 ( & V_39 ) ;
}
