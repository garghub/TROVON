static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_4 , unsigned V_5 , bool V_6 )
{
unsigned short V_7 = V_5 ? ( V_5 - 76 * 16000 ) / 800 : 0 ;
int V_8 ;
V_4 -> V_9 [ 0 ] = 0x00 ;
V_4 -> V_9 [ 1 ] = 0x50 ;
V_4 -> V_9 [ 2 ] = ( V_7 >> 8 ) & 0xff ;
V_4 -> V_9 [ 3 ] = V_7 & 0xff ;
V_4 -> V_9 [ 4 ] = V_4 -> V_10 ;
V_4 -> V_9 [ 5 ] = ( V_4 -> V_11 ? 4 : 8 ) | ( V_6 ? 1 : 2 ) |
( V_5 ? 0x10 : 0 ) ;
V_4 -> V_9 [ 6 ] = 0x00 ;
V_4 -> V_9 [ 7 ] = 0x00 ;
V_8 = F_4 ( V_4 -> V_12 , F_5 ( V_4 -> V_12 , 0 ) ,
9 , 0x21 , 0x200 , 2 , V_4 -> V_9 , V_13 , V_14 ) ;
if ( V_8 < 0 ) {
F_6 ( & V_4 -> V_15 . V_16 , L_1 , V_17 , V_8 ) ;
return V_8 ;
}
if ( V_5 )
V_4 -> V_18 = V_5 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_4 )
{
int V_8 ;
V_4 -> V_9 [ 0 ] = 0x00 ;
V_4 -> V_9 [ 1 ] = 0x51 ;
V_4 -> V_9 [ 2 ] = V_4 -> V_19 ;
V_4 -> V_9 [ 3 ] = ( ! V_4 -> V_20 ) | ( V_4 -> V_21 ? 4 : 0 ) ;
V_4 -> V_9 [ 4 ] = 0x00 ;
V_4 -> V_9 [ 5 ] = 0x00 ;
V_4 -> V_9 [ 6 ] = 0x00 ;
V_4 -> V_9 [ 7 ] = 0x00 ;
V_8 = F_4 ( V_4 -> V_12 , F_5 ( V_4 -> V_12 , 0 ) ,
9 , 0x21 , 0x200 , 2 , V_4 -> V_9 , V_13 , V_14 ) ;
if ( V_8 < 0 ) {
F_6 ( & V_4 -> V_15 . V_16 , L_1 , V_17 , V_8 ) ;
return V_8 ;
}
return 0 ;
}
static void F_8 ( struct V_22 * V_23 )
{
struct V_1 * V_4 = F_1 ( F_9 ( V_23 ) ) ;
F_10 ( & V_4 -> V_24 ) ;
F_11 ( V_23 , NULL ) ;
F_12 ( & V_4 -> V_15 ) ;
F_13 ( & V_4 -> V_3 ) ;
F_14 ( & V_4 -> V_24 ) ;
F_15 ( & V_4 -> V_3 ) ;
}
static int F_16 ( struct V_22 * V_23 , T_1 V_25 )
{
struct V_1 * V_4 = F_1 ( F_9 ( V_23 ) ) ;
return F_3 ( V_4 , 0 , false ) ;
}
static int F_17 ( struct V_22 * V_23 )
{
struct V_1 * V_4 = F_1 ( F_9 ( V_23 ) ) ;
F_18 ( 50 ) ;
F_7 ( V_4 ) ;
F_3 ( V_4 , V_4 -> V_18 , true ) ;
return 0 ;
}
static int F_19 ( struct V_26 * V_26 , void * V_27 ,
struct V_28 * V_29 )
{
struct V_1 * V_4 = F_20 ( V_26 ) ;
F_21 ( V_29 -> V_30 , L_2 , sizeof( V_29 -> V_30 ) ) ;
F_21 ( V_29 -> V_31 , L_3 , sizeof( V_29 -> V_31 ) ) ;
F_22 ( V_4 -> V_12 , V_29 -> V_32 , sizeof( V_29 -> V_32 ) ) ;
V_29 -> V_33 = V_34 | V_35 ;
V_29 -> V_36 = V_29 -> V_33 | V_37 ;
return 0 ;
}
static int F_23 ( struct V_26 * V_26 , void * V_27 ,
struct V_38 * V_29 )
{
struct V_1 * V_4 = F_20 ( V_26 ) ;
if ( V_29 -> V_39 > 0 )
return - V_40 ;
F_21 ( V_29 -> V_41 , L_4 , sizeof( V_29 -> V_41 ) ) ;
V_29 -> V_42 = V_43 * V_44 ;
V_29 -> V_45 = V_46 * V_44 ;
V_29 -> V_47 = V_4 -> V_20 ? V_48 : V_49 ;
V_29 -> V_50 = V_51 | V_52 ;
return 0 ;
}
static int F_24 ( struct V_26 * V_26 , void * V_27 ,
struct V_38 * V_29 )
{
struct V_1 * V_4 = F_20 ( V_26 ) ;
if ( V_29 -> V_39 > 0 )
return - V_40 ;
V_4 -> V_20 = ( V_29 -> V_47 == V_48 ) ;
return F_7 ( V_4 ) ;
}
static int F_25 ( struct V_26 * V_26 , void * V_27 ,
struct V_53 * V_54 )
{
struct V_1 * V_4 = F_20 ( V_26 ) ;
if ( V_54 -> V_55 != 0 || V_54 -> type != V_56 )
return - V_40 ;
V_54 -> V_57 = F_26 ( V_54 -> V_57 ,
V_43 * V_44 , V_46 * V_44 ) ;
return F_3 ( V_4 , V_54 -> V_57 , true ) ;
}
static int F_27 ( struct V_26 * V_26 , void * V_27 ,
struct V_53 * V_54 )
{
struct V_1 * V_4 = F_20 ( V_26 ) ;
if ( V_54 -> V_55 != 0 )
return - V_40 ;
V_54 -> type = V_56 ;
V_54 -> V_57 = V_4 -> V_18 ;
return 0 ;
}
static int F_28 ( struct V_58 * V_59 )
{
static const T_2 V_60 [] = {
0x03 , 0x13 , 0x02 , 0x12 , 0x22 , 0x32 ,
0x21 , 0x31 , 0x20 , 0x30 , 0x40 , 0x50
} ;
struct V_1 * V_4 =
F_2 ( V_59 -> V_61 , struct V_1 , V_62 ) ;
switch ( V_59 -> V_63 ) {
case V_64 :
V_4 -> V_11 = V_59 -> V_65 ;
return F_3 ( V_4 , 0 , true ) ;
case V_66 :
V_4 -> V_10 = ( V_59 -> V_65 - 71 ) * 100 / 62 ;
return F_3 ( V_4 , 0 , true ) ;
case V_67 :
V_4 -> V_21 = V_59 -> V_65 == V_68 ;
return F_7 ( V_4 ) ;
case V_69 :
V_4 -> V_19 = V_60 [ ( V_59 -> V_65 - V_59 -> V_70 ) / V_59 -> V_71 ] ;
return F_7 ( V_4 ) ;
}
return - V_40 ;
}
static void F_29 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_30 ( & V_4 -> V_62 ) ;
F_31 ( V_4 -> V_9 ) ;
F_31 ( V_4 ) ;
}
static int F_32 ( struct V_22 * V_23 ,
const struct V_72 * V_63 )
{
struct V_73 * V_16 = F_33 ( V_23 ) ;
struct V_1 * V_4 ;
struct V_74 * V_62 ;
int V_75 = 0 ;
if ( V_16 -> V_76 && strcmp ( V_16 -> V_76 , L_5 ) )
return - V_77 ;
V_4 = F_34 ( sizeof( struct V_1 ) , V_78 ) ;
if ( V_4 )
V_4 -> V_9 = F_35 ( V_13 , V_78 ) ;
if ( ! V_4 || ! V_4 -> V_9 ) {
F_36 ( & V_23 -> V_16 , L_6 ) ;
F_31 ( V_4 ) ;
V_75 = - V_79 ;
goto V_80;
}
V_62 = & V_4 -> V_62 ;
F_37 ( V_62 , 4 ) ;
F_38 ( V_62 , & V_81 , V_64 ,
0 , 1 , 1 , 0 ) ;
F_39 ( V_62 , & V_81 , V_67 ,
V_68 , 1 , V_82 ) ;
F_38 ( V_62 , & V_81 , V_66 ,
84 , 118 , 1 , 118 ) ;
F_38 ( V_62 , & V_81 , V_69 ,
- 15 , 18 , 3 , 0 ) ;
V_4 -> V_10 = 118 ;
V_4 -> V_19 = 0x32 ;
V_4 -> V_20 = true ;
V_4 -> V_18 = 95.16 * V_44 ;
if ( V_62 -> error ) {
V_75 = V_62 -> error ;
F_30 ( V_62 ) ;
goto V_83;
}
V_75 = F_40 ( & V_23 -> V_16 , & V_4 -> V_3 ) ;
if ( V_75 < 0 ) {
F_36 ( & V_23 -> V_16 , L_7 ) ;
goto V_83;
}
F_41 ( & V_4 -> V_24 ) ;
V_4 -> V_3 . V_84 = V_62 ;
V_4 -> V_3 . V_85 = F_29 ;
F_21 ( V_4 -> V_15 . V_41 , V_4 -> V_3 . V_41 ,
sizeof( V_4 -> V_15 . V_41 ) ) ;
V_4 -> V_15 . V_3 = & V_4 -> V_3 ;
V_4 -> V_15 . V_86 = & V_87 ;
V_4 -> V_15 . V_88 = & V_89 ;
V_4 -> V_15 . V_24 = & V_4 -> V_24 ;
V_4 -> V_15 . V_85 = V_90 ;
V_4 -> V_12 = F_33 ( V_23 ) ;
V_4 -> V_23 = V_23 ;
F_11 ( V_23 , & V_4 -> V_3 ) ;
F_42 ( & V_4 -> V_15 , V_4 ) ;
F_43 ( V_91 , & V_4 -> V_15 . V_92 ) ;
V_75 = F_44 ( & V_4 -> V_15 , V_93 , - 1 ) ;
if ( V_75 < 0 ) {
F_36 ( & V_23 -> V_16 , L_8 ) ;
goto V_94;
}
F_45 ( V_62 ) ;
F_46 ( & V_23 -> V_16 , L_9 ,
F_47 ( & V_4 -> V_15 ) ) ;
return 0 ;
V_94:
F_48 ( & V_4 -> V_3 ) ;
V_83:
F_31 ( V_4 -> V_9 ) ;
F_31 ( V_4 ) ;
V_80:
return V_75 ;
}
static int T_3 F_49 ( void )
{
int V_75 = F_50 ( & V_95 ) ;
if ( V_75 )
F_51 ( V_96
L_10 , V_75 ) ;
return V_75 ;
}
static void T_4 F_52 ( void )
{
F_53 ( & V_95 ) ;
}
