static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( V_6 , V_8 , V_3 ) ;
F_2 ( V_6 , V_9 , V_4 & 0xff ) ;
F_2 ( V_6 , V_9 + 1 , ( V_4 & 0xff00 ) >> 8 ) ;
F_2 ( V_6 , V_10 , 0x8c ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_2 V_11 = 0 ;
T_2 V_12 = 0 ;
F_2 ( V_6 , V_8 , V_3 ) ;
F_2 ( V_6 , V_10 , 0x8b ) ;
F_4 ( V_6 , V_9 , & V_11 ) ;
F_4 ( V_6 , V_9 + 1 , & V_12 ) ;
return ( V_12 << 8 ) | V_11 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( V_6 , V_10 , 0x94 ) ;
F_2 ( V_6 , V_10 , 0x88 ) ;
F_2 ( V_6 , V_13 + 2 , 0x01 ) ;
}
int F_6 ( struct V_5 * V_6 )
{
struct V_14 * V_15 = NULL ;
struct V_16 * V_17 ;
struct V_18 V_19 ;
int V_20 ;
V_20 = F_7 ( V_6 -> V_6 , V_21 , V_22 ,
V_23 , 0 , & V_15 ) ;
if ( V_20 < 0 )
return V_20 ;
snprintf ( V_15 -> V_24 , sizeof( V_15 -> V_24 ) ,
L_1 ) ;
snprintf ( V_15 -> V_25 , sizeof( V_15 -> V_25 ) ,
L_2 ) ;
F_8 ( V_15 -> V_26 , V_6 -> V_6 -> V_26 -> V_27 , sizeof( V_15 -> V_26 ) ) ;
V_20 = V_16 ( V_15 , 0 , & V_28 , NULL , & V_17 ) ;
if ( V_20 )
goto V_29;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_19 . V_7 = V_6 ;
V_19 . V_30 = V_31 ;
V_20 = F_9 ( V_17 , & V_19 , & V_32 ) ;
if ( V_20 )
goto V_29;
V_6 -> V_14 = V_15 ;
V_20 = F_10 ( V_15 ) ;
if ( V_20 )
goto V_29;
return 0 ;
V_29:
V_6 -> V_14 = NULL ;
F_11 ( V_15 ) ;
return V_20 ;
}
int F_12 ( struct V_5 * V_6 )
{
struct V_14 * V_15 = V_6 -> V_14 ;
if ( V_15 && V_6 -> V_33 )
F_11 ( V_15 ) ;
return 0 ;
}
