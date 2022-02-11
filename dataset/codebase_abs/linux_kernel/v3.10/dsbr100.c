static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
unsigned V_4 = ( V_3 / 16 * 80 ) / 1000 + 856 ;
int V_5 = 0 ;
if ( ! V_2 -> V_6 ) {
V_5 = F_2 ( V_2 -> V_7 ,
F_3 ( V_2 -> V_7 , 0 ) ,
V_8 ,
V_9 | V_10 | V_11 ,
( V_4 >> 8 ) & 0x00ff , V_4 & 0xff ,
V_2 -> V_12 , 8 , 300 ) ;
if ( V_5 >= 0 )
F_4 ( 1 ) ;
}
if ( V_5 >= 0 ) {
V_2 -> V_13 = V_3 ;
return 0 ;
}
F_5 ( & V_2 -> V_7 -> V_14 ,
L_1 ,
V_15 , V_5 , V_8 ) ;
return V_5 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_5 = F_2 ( V_2 -> V_7 ,
F_3 ( V_2 -> V_7 , 0 ) ,
V_16 ,
V_9 | V_10 | V_11 ,
0x01 , 0x00 , V_2 -> V_12 , 8 , 300 ) ;
if ( V_5 >= 0 )
return F_1 ( V_2 , V_2 -> V_13 ) ;
F_5 ( & V_2 -> V_7 -> V_14 ,
L_1 ,
V_15 , V_5 , V_16 ) ;
return V_5 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_5 = F_2 ( V_2 -> V_7 ,
F_3 ( V_2 -> V_7 , 0 ) ,
V_16 ,
V_9 | V_10 | V_11 ,
0x00 , 0x00 , V_2 -> V_12 , 8 , 300 ) ;
if ( V_5 >= 0 )
return 0 ;
F_5 ( & V_2 -> V_7 -> V_14 ,
L_1 ,
V_15 , V_5 , V_16 ) ;
return V_5 ;
}
static void F_8 ( struct V_1 * V_2 )
{
int V_5 = F_2 ( V_2 -> V_7 ,
F_3 ( V_2 -> V_7 , 0 ) ,
V_17 ,
V_9 | V_10 | V_11 ,
0x00 , 0x24 , V_2 -> V_12 , 8 , 300 ) ;
if ( V_5 < 0 ) {
V_2 -> V_18 = false ;
F_5 ( & V_2 -> V_7 -> V_14 ,
L_1 ,
V_15 , V_5 , V_17 ) ;
} else {
V_2 -> V_18 = ! ( V_2 -> V_12 [ 0 ] & 0x01 ) ;
}
}
static int F_9 ( struct V_19 * V_19 , void * V_20 ,
struct V_21 * V_22 )
{
struct V_1 * V_2 = F_10 ( V_19 ) ;
F_11 ( V_22 -> V_23 , L_2 , sizeof( V_22 -> V_23 ) ) ;
F_11 ( V_22 -> V_24 , L_3 , sizeof( V_22 -> V_24 ) ) ;
F_12 ( V_2 -> V_7 , V_22 -> V_25 , sizeof( V_22 -> V_25 ) ) ;
V_22 -> V_26 = V_27 | V_28 ;
V_22 -> V_29 = V_22 -> V_26 | V_30 ;
return 0 ;
}
static int F_13 ( struct V_19 * V_19 , void * V_20 ,
struct V_31 * V_22 )
{
struct V_1 * V_2 = F_10 ( V_19 ) ;
if ( V_22 -> V_32 > 0 )
return - V_33 ;
F_8 ( V_2 ) ;
strcpy ( V_22 -> V_34 , L_4 ) ;
V_22 -> type = V_35 ;
V_22 -> V_36 = V_37 * V_38 ;
V_22 -> V_39 = V_40 * V_38 ;
V_22 -> V_41 = V_2 -> V_18 ? V_42 :
V_43 ;
V_22 -> V_44 = V_45 | V_46 ;
V_22 -> V_47 = V_48 ;
V_22 -> signal = V_2 -> V_18 ? 0xffff : 0 ;
return 0 ;
}
static int F_14 ( struct V_19 * V_19 , void * V_20 ,
const struct V_31 * V_22 )
{
return V_22 -> V_32 ? - V_33 : 0 ;
}
static int F_15 ( struct V_19 * V_19 , void * V_20 ,
const struct V_49 * V_4 )
{
struct V_1 * V_2 = F_10 ( V_19 ) ;
if ( V_4 -> V_50 != 0 || V_4 -> type != V_35 )
return - V_33 ;
return F_1 ( V_2 , F_16 ( unsigned , V_4 -> V_51 ,
V_37 * V_38 , V_40 * V_38 ) ) ;
}
static int F_17 ( struct V_19 * V_19 , void * V_20 ,
struct V_49 * V_4 )
{
struct V_1 * V_2 = F_10 ( V_19 ) ;
if ( V_4 -> V_50 )
return - V_33 ;
V_4 -> type = V_35 ;
V_4 -> V_51 = V_2 -> V_13 ;
return 0 ;
}
static int F_18 ( struct V_52 * V_53 )
{
struct V_1 * V_2 =
F_19 ( V_53 -> V_54 , struct V_1 , V_55 ) ;
switch ( V_53 -> V_56 ) {
case V_57 :
V_2 -> V_6 = V_53 -> V_58 ;
return V_2 -> V_6 ? F_7 ( V_2 ) : F_6 ( V_2 ) ;
}
return - V_33 ;
}
static void F_20 ( struct V_59 * V_60 )
{
struct V_1 * V_2 = F_21 ( V_60 ) ;
F_22 ( & V_2 -> V_61 ) ;
F_2 ( V_2 -> V_7 ,
F_3 ( V_2 -> V_7 , 0 ) ,
V_16 ,
V_9 | V_10 | V_11 ,
0x00 , 0x00 , V_2 -> V_12 , 8 , 300 ) ;
F_23 ( V_60 , NULL ) ;
F_24 ( & V_2 -> V_62 ) ;
F_25 ( & V_2 -> V_63 ) ;
F_26 ( & V_2 -> V_61 ) ;
F_27 ( & V_2 -> V_63 ) ;
}
static int F_28 ( struct V_59 * V_60 , T_1 V_64 )
{
struct V_1 * V_2 = F_21 ( V_60 ) ;
F_22 ( & V_2 -> V_61 ) ;
if ( ! V_2 -> V_6 && F_7 ( V_2 ) < 0 )
F_29 ( & V_60 -> V_14 , L_5 ) ;
F_26 ( & V_2 -> V_61 ) ;
F_30 ( & V_60 -> V_14 , L_6 ) ;
return 0 ;
}
static int F_31 ( struct V_59 * V_60 )
{
struct V_1 * V_2 = F_21 ( V_60 ) ;
F_22 ( & V_2 -> V_61 ) ;
if ( ! V_2 -> V_6 && F_6 ( V_2 ) < 0 )
F_29 ( & V_60 -> V_14 , L_7 ) ;
F_26 ( & V_2 -> V_61 ) ;
F_30 ( & V_60 -> V_14 , L_8 ) ;
return 0 ;
}
static void F_32 ( struct V_65 * V_63 )
{
struct V_1 * V_2 = F_33 ( V_63 ) ;
F_34 ( & V_2 -> V_55 ) ;
F_35 ( & V_2 -> V_63 ) ;
F_36 ( V_2 -> V_12 ) ;
F_36 ( V_2 ) ;
}
static int F_37 ( struct V_59 * V_60 ,
const struct V_66 * V_56 )
{
struct V_1 * V_2 ;
struct V_65 * V_63 ;
int V_5 ;
V_2 = F_38 ( sizeof( struct V_1 ) , V_67 ) ;
if ( ! V_2 )
return - V_68 ;
V_2 -> V_12 = F_39 ( V_69 , V_67 ) ;
if ( ! ( V_2 -> V_12 ) ) {
F_36 ( V_2 ) ;
return - V_68 ;
}
V_63 = & V_2 -> V_63 ;
V_63 -> V_70 = F_32 ;
V_5 = F_40 ( & V_60 -> V_14 , V_63 ) ;
if ( V_5 < 0 ) {
F_41 ( V_63 , L_9 ) ;
goto V_71;
}
F_42 ( & V_2 -> V_55 , 1 ) ;
F_43 ( & V_2 -> V_55 , & V_72 ,
V_57 , 0 , 1 , 1 , 1 ) ;
if ( V_2 -> V_55 . error ) {
V_5 = V_2 -> V_55 . error ;
F_41 ( V_63 , L_10 ) ;
goto V_73;
}
F_44 ( & V_2 -> V_61 ) ;
F_11 ( V_2 -> V_62 . V_34 , V_63 -> V_34 , sizeof( V_2 -> V_62 . V_34 ) ) ;
V_2 -> V_62 . V_63 = V_63 ;
V_2 -> V_62 . V_74 = & V_75 ;
V_2 -> V_62 . V_76 = & V_77 ;
V_2 -> V_62 . V_70 = V_78 ;
V_2 -> V_62 . V_79 = & V_2 -> V_61 ;
V_2 -> V_62 . V_80 = & V_2 -> V_55 ;
F_45 ( V_81 , & V_2 -> V_62 . V_82 ) ;
V_2 -> V_7 = F_46 ( V_60 ) ;
V_2 -> V_13 = V_37 * V_38 ;
V_2 -> V_6 = true ;
F_47 ( & V_2 -> V_62 , V_2 ) ;
F_23 ( V_60 , V_2 ) ;
V_5 = F_48 ( & V_2 -> V_62 , V_83 , V_84 ) ;
if ( V_5 == 0 )
return 0 ;
F_41 ( V_63 , L_11 ) ;
V_73:
F_34 ( & V_2 -> V_55 ) ;
F_35 ( V_63 ) ;
V_71:
F_36 ( V_2 -> V_12 ) ;
F_36 ( V_2 ) ;
return V_5 ;
}
