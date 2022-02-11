static int F_1 ( struct V_1 * V_2 , unsigned char V_3 )
{
V_2 -> V_4 = V_3 ;
return F_2 ( V_2 -> V_5 , V_6 , V_3 , - 1 ) ;
}
static int F_3 ( struct V_1 * V_2 , unsigned char V_7 )
{
return F_2 ( V_2 -> V_5 , V_8 , ! V_7 , - 1 ) ;
}
static int F_4 ( struct V_1 * V_2 , unsigned long V_9 )
{
unsigned char V_10 ;
unsigned char V_11 ;
struct V_12 * V_5 = V_2 -> V_5 ;
V_2 -> V_9 = V_9 ;
V_9 /= 160 ;
if ( ! ( V_5 -> V_13 == 0x07 || V_5 -> V_13 >= 0xb0 ) )
V_9 /= 10 ;
V_10 = V_9 & 0xff ;
V_11 = V_9 >> 8 ;
F_3 ( V_2 , ! V_14 ) ;
return F_2 ( V_5 , V_15 , V_10 , V_11 ) ;
}
static int F_5 ( struct V_16 * V_16 , void * V_17 ,
struct V_18 * V_19 )
{
F_6 ( V_19 -> V_20 , L_1 , sizeof( V_19 -> V_20 ) ) ;
F_6 ( V_19 -> V_21 , L_1 , sizeof( V_19 -> V_21 ) ) ;
F_6 ( V_19 -> V_22 , L_2 , sizeof( V_19 -> V_22 ) ) ;
V_19 -> V_23 = 0x1 ;
V_19 -> V_24 = V_25 | V_26 ;
return 0 ;
}
static int F_7 ( struct V_16 * V_16 , void * V_17 ,
struct V_27 * V_19 )
{
if ( V_19 -> V_28 )
return - V_29 ;
F_6 ( V_19 -> V_30 , L_3 , sizeof( V_19 -> V_30 ) ) ;
V_19 -> type = V_31 ;
V_19 -> V_32 = 87 * 16000 ;
V_19 -> V_33 = 108 * 16000 ;
V_19 -> signal = 0xffff ;
V_19 -> V_34 = V_35 | V_36 ;
V_19 -> V_37 = V_38 ;
V_19 -> V_39 = V_40 ;
return 0 ;
}
static int F_8 ( struct V_16 * V_16 , void * V_17 ,
struct V_27 * V_19 )
{
return V_19 -> V_28 ? - V_29 : 0 ;
}
static int F_9 ( struct V_16 * V_16 , void * V_17 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_10 ( V_16 ) ;
if ( V_42 -> V_43 != 0 )
return - V_29 ;
V_42 -> type = V_31 ;
V_42 -> V_44 = V_2 -> V_9 ;
return 0 ;
}
static int F_11 ( struct V_16 * V_16 , void * V_17 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_10 ( V_16 ) ;
if ( V_42 -> V_43 != 0 || V_42 -> type != V_31 )
return - V_29 ;
V_2 -> V_9 = V_42 -> V_44 ;
F_4 ( V_2 , V_42 -> V_44 ) ;
return 0 ;
}
static int F_12 ( struct V_16 * V_16 , void * V_17 ,
struct V_45 * V_46 )
{
switch ( V_46 -> V_47 ) {
case V_48 :
return F_13 ( V_46 , 0 , 1 , 1 , 1 ) ;
}
return - V_29 ;
}
static int F_14 ( struct V_16 * V_16 , void * V_17 ,
struct V_49 * V_50 )
{
struct V_1 * V_2 = F_10 ( V_16 ) ;
switch ( V_50 -> V_47 ) {
case V_48 :
V_50 -> V_51 = V_2 -> V_4 ;
break;
default:
return - V_29 ;
}
return 0 ;
}
static int F_15 ( struct V_16 * V_16 , void * V_17 ,
struct V_49 * V_50 )
{
struct V_1 * V_2 = F_10 ( V_16 ) ;
switch ( V_50 -> V_47 ) {
case V_48 :
F_1 ( V_2 , V_50 -> V_51 ) ;
break;
default:
return - V_29 ;
}
return 0 ;
}
static int F_16 ( struct V_16 * V_52 , void * V_17 , unsigned int * V_53 )
{
* V_53 = 0 ;
return 0 ;
}
static int F_17 ( struct V_16 * V_52 , void * V_17 , unsigned int V_53 )
{
return V_53 ? - V_29 : 0 ;
}
static int F_18 ( struct V_16 * V_16 , void * V_17 ,
struct V_54 * V_55 )
{
V_55 -> V_28 = 0 ;
F_6 ( V_55 -> V_30 , L_4 , sizeof( V_55 -> V_30 ) ) ;
V_55 -> V_37 = V_56 ;
return 0 ;
}
static int F_19 ( struct V_16 * V_16 , void * V_17 ,
const struct V_54 * V_55 )
{
return V_55 -> V_28 ? - V_29 : 0 ;
}
static int T_1 F_20 ( void )
{
struct V_1 * V_2 = & V_57 ;
struct V_58 * V_59 = & V_2 -> V_59 ;
int V_60 ;
V_2 -> V_5 = F_21 () ;
if ( V_2 -> V_5 == NULL ) {
F_22 ( V_59 ,
L_5 ) ;
return - V_61 ;
}
F_6 ( V_59 -> V_30 , L_6 , sizeof( V_59 -> V_30 ) ) ;
F_23 ( & V_2 -> V_62 ) ;
V_60 = F_24 ( NULL , V_59 ) ;
if ( V_60 < 0 ) {
F_22 ( V_59 , L_7 ) ;
return - V_29 ;
}
F_6 ( V_2 -> V_63 . V_30 , V_59 -> V_30 , sizeof( V_2 -> V_63 . V_30 ) ) ;
V_2 -> V_63 . V_59 = V_59 ;
V_2 -> V_63 . V_64 = & V_65 ;
V_2 -> V_63 . V_66 = & V_67 ;
V_2 -> V_63 . V_68 = V_69 ;
V_2 -> V_63 . V_62 = & V_2 -> V_62 ;
F_25 ( & V_2 -> V_63 , V_2 ) ;
if ( F_26 ( & V_2 -> V_63 , V_70 , V_71 ) < 0 )
goto V_72;
F_27 ( V_59 , L_8 ) ;
return 0 ;
V_72:
F_28 ( V_59 ) ;
return - V_29 ;
}
static void T_2 F_29 ( void )
{
struct V_1 * V_2 = & V_57 ;
F_30 ( & V_2 -> V_63 ) ;
F_28 ( & V_2 -> V_59 ) ;
}
