static int F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
unsigned char V_4 ;
unsigned char V_5 ;
struct V_6 * V_7 = V_2 -> V_7 ;
V_3 /= 160 ;
if ( ! ( V_7 -> V_8 == 0x07 || V_7 -> V_8 >= 0xb0 ) )
V_3 /= 10 ;
V_4 = V_3 & 0xff ;
V_5 = V_3 >> 8 ;
return F_2 ( V_7 , V_9 , V_4 , V_5 ) ;
}
static int F_3 ( struct V_10 * V_10 , void * V_11 ,
struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_10 ) ;
F_5 ( V_13 -> V_14 , L_1 , sizeof( V_13 -> V_14 ) ) ;
F_5 ( V_13 -> V_15 , L_1 , sizeof( V_13 -> V_15 ) ) ;
snprintf ( V_13 -> V_16 , sizeof( V_13 -> V_16 ) , L_2 , V_2 -> V_17 . V_18 ) ;
V_13 -> V_19 = V_20 | V_21 ;
V_13 -> V_22 = V_13 -> V_19 | V_23 ;
return 0 ;
}
static int F_6 ( struct V_10 * V_10 , void * V_11 ,
struct V_24 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_10 ) ;
int V_25 ;
if ( V_13 -> V_26 )
return - V_27 ;
F_5 ( V_13 -> V_18 , L_3 , sizeof( V_13 -> V_18 ) ) ;
V_13 -> type = V_28 ;
V_13 -> V_29 = 87 * 16000 ;
V_13 -> V_30 = 108 * 16000 ;
V_25 = F_2 ( V_2 -> V_7 , V_31 , - 1 , - 1 ) ;
V_13 -> signal = ( V_25 & 0x80 ) ? 0 : 0xffff ;
V_25 = F_2 ( V_2 -> V_7 , V_32 , - 1 , - 1 ) ;
V_13 -> V_33 = ( V_25 & 0x40 ) ? V_34 :
V_35 ;
V_13 -> V_36 = V_37 | V_38 ;
V_13 -> V_39 = V_2 -> V_39 ;
return 0 ;
}
static int F_7 ( struct V_10 * V_10 , void * V_11 ,
struct V_24 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_10 ) ;
if ( V_13 -> V_26 )
return - V_27 ;
if ( V_13 -> V_39 > V_40 )
V_13 -> V_39 = V_40 ;
F_2 ( V_2 -> V_7 , V_41 ,
V_13 -> V_39 == V_42 , - 1 ) ;
return 0 ;
}
static int F_8 ( struct V_10 * V_10 , void * V_11 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 = F_4 ( V_10 ) ;
if ( V_44 -> V_45 != 0 )
return - V_27 ;
V_44 -> type = V_28 ;
V_44 -> V_46 = V_2 -> V_3 ;
return 0 ;
}
static int F_9 ( struct V_10 * V_10 , void * V_11 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 = F_4 ( V_10 ) ;
if ( V_44 -> V_45 != 0 || V_44 -> type != V_28 )
return - V_27 ;
V_2 -> V_3 = F_10 ( V_44 -> V_46 , 87 * 16000U , 108 * 16000U ) ;
F_1 ( V_2 , V_2 -> V_3 ) ;
return 0 ;
}
static int F_11 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_12 ( V_48 -> V_49 , struct V_1 , V_50 ) ;
switch ( V_48 -> V_51 ) {
case V_52 :
F_2 ( V_2 -> V_7 , V_53 , V_48 -> V_54 , - 1 ) ;
return 0 ;
}
return - V_27 ;
}
static int T_1 F_13 ( void )
{
struct V_1 * V_2 = & V_55 ;
struct V_56 * V_17 = & V_2 -> V_17 ;
struct V_57 * V_58 ;
int V_25 ;
V_2 -> V_7 = F_14 () ;
if ( V_2 -> V_7 == NULL ) {
F_15 ( V_17 ,
L_4 ) ;
return - V_59 ;
}
F_5 ( V_17 -> V_18 , L_5 , sizeof( V_17 -> V_18 ) ) ;
F_16 ( & V_2 -> V_60 ) ;
V_25 = F_17 ( NULL , V_17 ) ;
if ( V_25 < 0 ) {
F_15 ( V_17 , L_6 ) ;
return - V_27 ;
}
V_58 = & V_2 -> V_50 ;
F_18 ( V_58 , 1 ) ;
F_19 ( V_58 , & V_61 ,
V_52 , 0 , 1 , 1 , 1 ) ;
V_17 -> V_50 = V_58 ;
if ( V_58 -> error ) {
V_25 = V_58 -> error ;
F_15 ( V_17 , L_7 ) ;
goto V_62;
}
F_5 ( V_2 -> V_63 . V_18 , V_17 -> V_18 , sizeof( V_2 -> V_63 . V_18 ) ) ;
V_2 -> V_63 . V_17 = V_17 ;
V_2 -> V_63 . V_64 = & V_65 ;
V_2 -> V_63 . V_66 = & V_67 ;
V_2 -> V_63 . V_68 = V_69 ;
V_2 -> V_63 . V_60 = & V_2 -> V_60 ;
F_20 ( V_70 , & V_2 -> V_63 . V_71 ) ;
F_21 ( & V_2 -> V_63 , V_2 ) ;
F_2 ( V_2 -> V_7 , V_41 ,
V_2 -> V_39 == V_42 , - 1 ) ;
F_1 ( V_2 , V_2 -> V_3 ) ;
if ( F_22 ( & V_2 -> V_63 , V_72 , V_73 ) < 0 )
goto V_62;
F_23 ( V_17 , L_8 ) ;
return 0 ;
V_62:
F_24 ( V_58 ) ;
F_25 ( V_17 ) ;
return - V_27 ;
}
static void T_2 F_26 ( void )
{
struct V_1 * V_2 = & V_55 ;
F_27 ( & V_2 -> V_63 ) ;
F_2 ( V_2 -> V_7 , V_53 , 1 , - 1 ) ;
F_24 ( & V_2 -> V_50 ) ;
F_25 ( & V_2 -> V_17 ) ;
}
