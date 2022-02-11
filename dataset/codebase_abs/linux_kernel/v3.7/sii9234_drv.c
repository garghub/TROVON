static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline int F_3 ( struct V_4 * V_5 , int V_6 )
{
return F_4 ( V_5 , V_6 ) ;
}
static inline int F_5 ( struct V_4 * V_5 , int V_6 , int V_7 )
{
return F_6 ( V_5 , V_6 , V_7 ) ;
}
static inline int F_7 ( struct V_4 * V_5 , int V_6 ,
int V_7 , int V_8 )
{
int V_9 ;
V_9 = F_4 ( V_5 , V_6 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = ( V_9 & ~ V_8 ) | ( V_7 & V_8 ) ;
return F_6 ( V_5 , V_6 , V_9 ) ;
}
static inline int F_8 ( struct V_4 * V_5 , int V_6 )
{
int V_9 ;
V_9 = F_6 ( V_5 , 0xbc , V_6 >> 8 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_6 ( V_5 , 0xbd , V_6 & 0xff ) ;
if ( V_9 < 0 )
return V_9 ;
return F_4 ( V_5 , 0xbe ) ;
}
static inline int F_9 ( struct V_4 * V_5 , int V_6 ,
int V_7 )
{
int V_9 ;
V_9 = F_6 ( V_5 , 0xbc , V_6 >> 8 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_6 ( V_5 , 0xbd , V_6 & 0xff ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_6 ( V_5 , 0xbe , V_7 ) ;
return V_9 ;
}
static inline int F_10 ( struct V_4 * V_5 , int V_6 ,
int V_7 , int V_8 )
{
int V_9 ;
V_9 = F_8 ( V_5 , V_6 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = ( V_9 & ~ V_8 ) | ( V_7 & V_8 ) ;
return F_9 ( V_5 , V_6 , V_9 ) ;
}
static int F_11 ( struct V_1 * V_10 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_11 * V_12 = & V_5 -> V_12 ;
int V_9 , V_13 ;
F_12 ( V_10 -> V_14 , 1 ) ;
F_13 ( 1 ) ;
F_12 ( V_10 -> V_14 , 0 ) ;
F_13 ( 1 ) ;
F_12 ( V_10 -> V_14 , 1 ) ;
F_13 ( 1 ) ;
V_9 = F_5 ( V_5 , 0xc7 , 0 ) ;
if ( V_9 < 0 ) {
F_14 ( V_12 , L_1 ) ;
return V_9 ;
}
for ( V_13 = 0 ; V_13 < 100 ; ++ V_13 ) {
V_9 = F_3 ( V_5 , 0x1b ) ;
if ( V_9 > 0 )
break;
if ( V_9 < 0 ) {
F_14 ( V_12 , L_2 ) ;
return - V_15 ;
}
F_13 ( 1 ) ;
}
if ( V_13 == 100 ) {
F_14 ( V_12 , L_3 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_15 ( struct V_4 * V_5 )
{
struct V_11 * V_12 = & V_5 -> V_12 ;
int V_16 , V_17 , V_18 , V_19 , V_20 , V_21 , V_22 ;
V_16 = F_3 ( V_5 , 0x1b ) ;
V_17 = F_3 ( V_5 , 0x1c ) & 0x0f ;
V_18 = F_3 ( V_5 , 0x1d ) & 0x7f ;
V_19 = F_8 ( V_5 , 0x0103 ) ;
V_20 = F_8 ( V_5 , 0x0102 ) ;
V_21 = F_3 ( V_5 , 0x30 ) ;
if ( V_16 < 0 || V_17 < 0 || V_18 < 0 || V_19 < 0 ||
V_20 < 0 || V_21 < 0 ) {
F_14 ( V_12 , L_4 ) ;
return - V_15 ;
}
V_22 = ( V_19 << 8 ) | V_20 ;
F_16 ( V_12 , L_5 ,
V_22 , V_16 , V_17 ) ;
F_16 ( V_12 , L_6 , V_18 , V_21 ) ;
if ( V_22 != 0x9234 ) {
F_14 ( V_12 , L_7 ) ;
return - V_23 ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_10 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
int V_24 , V_9 ;
for ( V_24 = 0 ; V_24 < F_18 ( V_25 ) ; ++ V_24 ) {
int V_6 = ( V_25 [ V_24 ] [ 0 ] << 8 ) | V_25 [ V_24 ] [ 1 ] ;
V_9 = F_9 ( V_5 , V_6 , V_25 [ V_24 ] [ 2 ] ) ;
if ( V_9 < 0 )
return V_9 ;
}
return 0 ;
}
static int F_19 ( struct V_11 * V_12 )
{
struct V_2 * V_3 = F_20 ( V_12 ) ;
struct V_1 * V_10 = F_1 ( V_3 ) ;
struct V_4 * V_5 = V_10 -> V_5 ;
F_16 ( V_12 , L_8 ) ;
F_7 ( V_5 , 0x1e , 3 , 3 ) ;
F_21 ( V_10 -> V_26 ) ;
return 0 ;
}
static int F_22 ( struct V_11 * V_12 )
{
struct V_2 * V_3 = F_20 ( V_12 ) ;
struct V_1 * V_10 = F_1 ( V_3 ) ;
struct V_4 * V_5 = V_10 -> V_5 ;
int V_9 ;
F_16 ( V_12 , L_9 ) ;
F_23 ( V_10 -> V_26 ) ;
V_9 = F_11 ( V_10 ) ;
if ( V_9 )
goto V_27;
V_9 = F_7 ( V_5 , 0x1e , 1 , 0 ) ;
if ( V_9 < 0 )
goto V_27;
V_9 = F_17 ( V_10 ) ;
if ( V_9 < 0 )
goto V_27;
return 0 ;
V_27:
F_14 ( V_12 , L_10 ) ;
F_21 ( V_10 -> V_26 ) ;
return V_9 ;
}
static int F_24 ( struct V_2 * V_3 , int V_28 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
int V_9 ;
if ( V_28 )
V_9 = F_25 ( & V_10 -> V_5 -> V_12 ) ;
else
V_9 = F_26 ( & V_10 -> V_5 -> V_12 ) ;
return F_27 ( V_9 ) ? V_9 : 0 ;
}
static int F_28 ( struct V_2 * V_3 , int V_29 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
F_7 ( V_10 -> V_5 , 0x1a , V_29 ? 0 : ~ 0 , 1 << 4 ) ;
return 0 ;
}
static int T_1 F_29 ( struct V_4 * V_5 ,
const struct V_30 * V_22 )
{
struct V_11 * V_12 = & V_5 -> V_12 ;
struct V_31 * V_32 = V_12 -> V_33 ;
struct V_1 * V_10 ;
int V_9 ;
V_10 = F_30 ( & V_5 -> V_12 , sizeof( * V_10 ) , V_34 ) ;
if ( ! V_10 ) {
F_14 ( V_12 , L_11 ) ;
V_9 = - V_35 ;
goto V_27;
}
V_10 -> V_5 = V_5 ;
V_10 -> V_26 = F_31 ( V_12 , L_12 ) ;
if ( F_32 ( V_10 -> V_26 ) ) {
F_14 ( V_12 , L_13 ) ;
return F_33 ( V_10 -> V_26 ) ;
}
V_10 -> V_14 = V_32 -> V_14 ;
V_9 = F_34 ( V_10 -> V_14 , L_14 ) ;
if ( V_9 ) {
F_14 ( V_12 , L_15 ) ;
return V_9 ;
}
F_35 ( & V_10 -> V_3 , V_5 , & V_36 ) ;
F_36 ( V_12 ) ;
V_9 = F_25 ( V_12 ) ;
if ( V_9 )
goto V_37;
V_9 = F_15 ( V_5 ) ;
if ( V_9 )
goto V_38;
F_26 ( V_12 ) ;
F_16 ( V_12 , L_16 ) ;
return 0 ;
V_38:
F_37 ( V_12 ) ;
V_37:
F_38 ( V_12 ) ;
F_39 ( V_10 -> V_14 ) ;
V_27:
F_14 ( V_12 , L_17 ) ;
return V_9 ;
}
static int T_2 F_40 ( struct V_4 * V_5 )
{
struct V_11 * V_12 = & V_5 -> V_12 ;
struct V_2 * V_3 = F_41 ( V_5 ) ;
struct V_1 * V_10 = F_1 ( V_3 ) ;
F_38 ( V_12 ) ;
F_39 ( V_10 -> V_14 ) ;
F_16 ( V_12 , L_18 ) ;
return 0 ;
}
