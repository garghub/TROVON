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
if ( V_8 < 0 || V_8 >= V_13 ) {
F_6 ( V_3 , L_1 , V_8 ) ;
return - 1 ;
}
F_7 ( 1 , V_14 , V_3 , L_2 , V_8 , V_9 ) ;
for ( V_12 = 0 ; V_12 < 3 ; V_12 ++ )
if ( F_8 ( V_11 ,
( V_8 << 1 ) | ( V_9 >> 8 ) , V_9 & 0xff ) == 0 )
return 0 ;
F_6 ( V_3 , L_3 , V_9 , V_8 ) ;
return - 1 ;
}
static int F_9 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
struct V_1 * V_15 = F_1 ( V_3 ) ;
unsigned int V_16 , V_17 ;
T_2 V_18 ;
T_2 V_19 ;
T_1 V_20 ;
switch ( V_5 -> V_21 ) {
case V_22 :
break;
default:
return - V_23 ;
}
V_16 = ( F_10 ( 65536 - V_15 -> V_24 -> V_9 , 32768 ) * V_15 -> V_25 -> V_9 ) / 32768 ;
V_17 = ( F_10 ( V_15 -> V_24 -> V_9 , 32768 ) * V_15 -> V_25 -> V_9 ) / 32768 ;
V_18 = ( long ) V_16 * 31 / 65535 ;
V_19 = ( long ) V_17 * 31 / 65535 ;
V_20 = V_15 -> V_20 -> V_9 ? 0x80 : 0 ;
F_4 ( V_3 , V_26 , ( V_18 & 0x1f ) | V_20 ) ;
F_4 ( V_3 , V_27 , ( V_19 & 0x1f ) | V_20 ) ;
return 0 ;
}
static int F_11 ( struct V_2 * V_3 , T_3 V_28 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
V_15 -> V_29 = V_28 ;
F_4 ( V_3 , V_30 , 0x000 ) ;
switch ( V_28 ) {
case 44100 :
F_4 ( V_3 , V_31 , 0x020 ) ;
break;
case 48000 :
F_4 ( V_3 , V_31 , 0x000 ) ;
break;
case 32000 :
F_4 ( V_3 , V_31 , 0x018 ) ;
break;
default:
break;
}
F_4 ( V_3 , V_30 , 0x001 ) ;
return 0 ;
}
static int F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
F_13 ( V_3 , L_4 , V_15 -> V_29 ) ;
F_14 ( & V_15 -> V_7 , V_3 -> V_32 ) ;
return 0 ;
}
static int F_15 ( struct V_10 * V_11 ,
const struct V_33 * V_21 )
{
struct V_1 * V_15 ;
struct V_2 * V_3 ;
if ( ! F_16 ( V_11 -> V_34 , V_35 ) )
return - V_36 ;
F_17 ( V_11 , L_5 ,
V_11 -> V_37 << 1 , V_11 -> V_34 -> V_32 ) ;
V_15 = F_18 ( & V_11 -> V_38 , sizeof( * V_15 ) , V_39 ) ;
if ( V_15 == NULL )
return - V_40 ;
V_3 = & V_15 -> V_3 ;
F_19 ( V_3 , V_11 , & V_41 ) ;
F_20 ( & V_15 -> V_7 , 2 ) ;
V_15 -> V_25 = F_21 ( & V_15 -> V_7 , & V_42 ,
V_22 , 0 , 65535 , 65535 / 100 , 50736 ) ;
V_15 -> V_20 = F_21 ( & V_15 -> V_7 , & V_42 ,
V_43 , 0 , 1 , 1 , 0 ) ;
V_15 -> V_24 = F_21 ( & V_15 -> V_7 , & V_42 ,
V_44 , 0 , 65535 , 65535 / 100 , 32768 ) ;
V_3 -> V_45 = & V_15 -> V_7 ;
if ( V_15 -> V_7 . error ) {
int V_46 = V_15 -> V_7 . error ;
F_22 ( & V_15 -> V_7 ) ;
return V_46 ;
}
F_23 ( 3 , & V_15 -> V_25 ) ;
V_15 -> V_29 = 48000 ;
F_4 ( V_3 , V_47 , 0x00 ) ;
F_4 ( V_3 , V_48 , 0x000 ) ;
F_4 ( V_3 , V_49 , 0x000 ) ;
F_4 ( V_3 , V_50 , 0x049 ) ;
F_4 ( V_3 , V_31 , 0x000 ) ;
F_4 ( V_3 , V_30 , 0x001 ) ;
F_24 ( & V_15 -> V_7 ) ;
return 0 ;
}
static int F_25 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = F_26 ( V_11 ) ;
struct V_1 * V_15 = F_1 ( V_3 ) ;
F_27 ( V_3 ) ;
F_22 ( & V_15 -> V_7 ) ;
return 0 ;
}
