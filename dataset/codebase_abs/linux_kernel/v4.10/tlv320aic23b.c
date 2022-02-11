static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_2 * F_3 ( struct V_4 * V_5 )
{
return & F_2 ( V_5 -> V_6 , struct V_1 , V_7 ) -> V_3 ;
}
static int F_4 ( struct V_2 * V_3 , int V_8 , T_1 V_9 )
{
struct V_10 * V_11 = F_5 ( V_3 ) ;
int V_12 ;
if ( ( V_8 < 0 || V_8 > 9 ) && ( V_8 != 15 ) ) {
F_6 ( V_3 , L_1 , V_8 ) ;
return - 1 ;
}
for ( V_12 = 0 ; V_12 < 3 ; V_12 ++ )
if ( F_7 ( V_11 ,
( V_8 << 1 ) | ( V_9 >> 8 ) , V_9 & 0xff ) == 0 )
return 0 ;
F_6 ( V_3 , L_2 , V_9 , V_8 ) ;
return - 1 ;
}
static int F_8 ( struct V_2 * V_3 , T_2 V_13 )
{
switch ( V_13 ) {
case 32000 :
F_4 ( V_3 , 8 , 0x018 ) ;
break;
case 44100 :
F_4 ( V_3 , 8 , 0x022 ) ;
break;
case 48000 :
F_4 ( V_3 , 8 , 0x000 ) ;
break;
default:
return - V_14 ;
}
return 0 ;
}
static int F_9 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
switch ( V_5 -> V_15 ) {
case V_16 :
F_4 ( V_3 , 0 , 0x180 ) ;
if ( ! V_5 -> V_9 )
F_4 ( V_3 , 0 , 0x119 ) ;
return 0 ;
}
return - V_14 ;
}
static int F_10 ( struct V_2 * V_3 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
F_11 ( & V_17 -> V_7 , V_3 -> V_18 ) ;
return 0 ;
}
static int F_12 ( struct V_10 * V_11 ,
const struct V_19 * V_15 )
{
struct V_1 * V_17 ;
struct V_2 * V_3 ;
if ( ! F_13 ( V_11 -> V_20 , V_21 ) )
return - V_22 ;
F_14 ( V_11 , L_3 ,
V_11 -> V_23 << 1 , V_11 -> V_20 -> V_18 ) ;
V_17 = F_15 ( & V_11 -> V_24 , sizeof( * V_17 ) , V_25 ) ;
if ( V_17 == NULL )
return - V_26 ;
V_3 = & V_17 -> V_3 ;
F_16 ( V_3 , V_11 , & V_27 ) ;
F_4 ( V_3 , 15 , 0x000 ) ;
F_4 ( V_3 , 6 , 0x00A ) ;
F_4 ( V_3 , 7 , 0x049 ) ;
F_4 ( V_3 , 0 , 0x119 ) ;
F_4 ( V_3 , 8 , 0x000 ) ;
F_4 ( V_3 , 9 , 0x001 ) ;
F_17 ( & V_17 -> V_7 , 1 ) ;
F_18 ( & V_17 -> V_7 , & V_28 ,
V_16 , 0 , 1 , 1 , 0 ) ;
V_3 -> V_29 = & V_17 -> V_7 ;
if ( V_17 -> V_7 . error ) {
int V_30 = V_17 -> V_7 . error ;
F_19 ( & V_17 -> V_7 ) ;
return V_30 ;
}
F_20 ( & V_17 -> V_7 ) ;
return 0 ;
}
static int F_21 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = F_22 ( V_11 ) ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
F_23 ( V_3 ) ;
F_19 ( & V_17 -> V_7 ) ;
return 0 ;
}
