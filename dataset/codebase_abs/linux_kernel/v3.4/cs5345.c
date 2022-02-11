static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_2 * F_3 ( struct V_4 * V_5 )
{
return & F_2 ( V_5 -> V_6 , struct V_1 , V_7 ) -> V_3 ;
}
static inline int F_4 ( struct V_2 * V_3 , T_1 V_8 , T_1 V_9 )
{
struct V_10 * V_11 = F_5 ( V_3 ) ;
return F_6 ( V_11 , V_8 , V_9 ) ;
}
static inline int F_7 ( struct V_2 * V_3 , T_1 V_8 )
{
struct V_10 * V_11 = F_5 ( V_3 ) ;
return F_8 ( V_11 , V_8 ) ;
}
static int F_9 ( struct V_2 * V_3 ,
T_2 V_12 , T_2 V_13 , T_2 V_14 )
{
if ( ( V_12 & 0xf ) > 6 ) {
F_10 ( V_3 , L_1 , V_12 ) ;
return - V_15 ;
}
F_4 ( V_3 , 0x09 , V_12 & 0xf ) ;
F_4 ( V_3 , 0x05 , V_12 & 0xf0 ) ;
return 0 ;
}
static int F_11 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
switch ( V_5 -> V_16 ) {
case V_17 :
F_4 ( V_3 , 0x04 , V_5 -> V_18 ? 0x80 : 0 ) ;
return 0 ;
case V_19 :
F_4 ( V_3 , 0x07 , ( ( T_1 ) V_5 -> V_18 ) & 0x3f ) ;
F_4 ( V_3 , 0x08 , ( ( T_1 ) V_5 -> V_18 ) & 0x3f ) ;
return 0 ;
}
return - V_15 ;
}
static int F_12 ( struct V_2 * V_3 , struct V_20 * V_8 )
{
struct V_10 * V_11 = F_5 ( V_3 ) ;
if ( ! F_13 ( V_11 , & V_8 -> V_21 ) )
return - V_15 ;
if ( ! F_14 ( V_22 ) )
return - V_23 ;
V_8 -> V_24 = 1 ;
V_8 -> V_18 = F_7 ( V_3 , V_8 -> V_8 & 0x1f ) ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 , struct V_20 * V_8 )
{
struct V_10 * V_11 = F_5 ( V_3 ) ;
if ( ! F_13 ( V_11 , & V_8 -> V_21 ) )
return - V_15 ;
if ( ! F_14 ( V_22 ) )
return - V_23 ;
F_4 ( V_3 , V_8 -> V_8 & 0x1f , V_8 -> V_18 & 0xff ) ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 , struct V_25 * V_26 )
{
struct V_10 * V_11 = F_5 ( V_3 ) ;
return F_17 ( V_11 , V_26 , V_27 , 0 ) ;
}
static int F_18 ( struct V_2 * V_3 )
{
T_1 V_28 = F_7 ( V_3 , 0x09 ) & 7 ;
T_1 V_29 = F_7 ( V_3 , 0x04 ) ;
int V_30 = F_7 ( V_3 , 0x08 ) & 0x3f ;
F_19 ( V_3 , L_2 , V_28 ,
( V_29 & 0x80 ) ? L_3 : L_4 ) ;
if ( V_30 >= 32 )
V_30 = V_30 - 64 ;
F_19 ( V_3 , L_5 , V_30 ) ;
return 0 ;
}
static int F_20 ( struct V_10 * V_11 ,
const struct V_31 * V_16 )
{
struct V_1 * V_32 ;
struct V_2 * V_3 ;
if ( ! F_21 ( V_11 -> V_33 , V_34 ) )
return - V_35 ;
F_22 ( V_11 , L_6 ,
V_11 -> V_36 << 1 , V_11 -> V_33 -> V_37 ) ;
V_32 = F_23 ( sizeof( struct V_1 ) , V_38 ) ;
if ( V_32 == NULL )
return - V_39 ;
V_3 = & V_32 -> V_3 ;
F_24 ( V_3 , V_11 , & V_40 ) ;
F_25 ( & V_32 -> V_7 , 2 ) ;
F_26 ( & V_32 -> V_7 , & V_41 ,
V_17 , 0 , 1 , 1 , 0 ) ;
F_26 ( & V_32 -> V_7 , & V_41 ,
V_19 , - 24 , 24 , 1 , 0 ) ;
V_3 -> V_42 = & V_32 -> V_7 ;
if ( V_32 -> V_7 . error ) {
int V_43 = V_32 -> V_7 . error ;
F_27 ( & V_32 -> V_7 ) ;
F_28 ( V_32 ) ;
return V_43 ;
}
F_29 ( & V_32 -> V_7 ) ;
F_4 ( V_3 , 0x02 , 0x00 ) ;
F_4 ( V_3 , 0x04 , 0x01 ) ;
F_4 ( V_3 , 0x09 , 0x01 ) ;
return 0 ;
}
static int F_30 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = F_31 ( V_11 ) ;
struct V_1 * V_32 = F_1 ( V_3 ) ;
F_32 ( V_3 ) ;
F_27 ( & V_32 -> V_7 ) ;
F_28 ( V_32 ) ;
return 0 ;
}
