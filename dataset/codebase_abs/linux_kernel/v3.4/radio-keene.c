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
F_10 ( & V_4 -> V_3 ) ;
F_11 ( & V_4 -> V_24 ) ;
F_12 ( V_23 , NULL ) ;
F_13 ( & V_4 -> V_15 ) ;
F_14 ( & V_4 -> V_3 ) ;
F_15 ( & V_4 -> V_24 ) ;
F_16 ( & V_4 -> V_3 ) ;
}
static int F_17 ( struct V_25 * V_25 , void * V_26 ,
struct V_27 * V_28 )
{
struct V_1 * V_4 = F_18 ( V_25 ) ;
F_19 ( V_28 -> V_29 , L_2 , sizeof( V_28 -> V_29 ) ) ;
F_19 ( V_28 -> V_30 , L_3 , sizeof( V_28 -> V_30 ) ) ;
F_20 ( V_4 -> V_12 , V_28 -> V_31 , sizeof( V_28 -> V_31 ) ) ;
V_28 -> V_32 = V_33 | V_34 ;
V_28 -> V_35 = V_28 -> V_32 | V_36 ;
return 0 ;
}
static int F_21 ( struct V_25 * V_25 , void * V_26 ,
struct V_37 * V_28 )
{
struct V_1 * V_4 = F_18 ( V_25 ) ;
if ( V_28 -> V_38 > 0 )
return - V_39 ;
F_19 ( V_28 -> V_40 , L_4 , sizeof( V_28 -> V_40 ) ) ;
V_28 -> V_41 = V_42 * V_43 ;
V_28 -> V_44 = V_45 * V_43 ;
V_28 -> V_46 = V_4 -> V_20 ? V_47 : V_48 ;
V_28 -> V_49 = V_50 | V_51 ;
return 0 ;
}
static int F_22 ( struct V_25 * V_25 , void * V_26 ,
struct V_37 * V_28 )
{
struct V_1 * V_4 = F_18 ( V_25 ) ;
if ( V_28 -> V_38 > 0 )
return - V_39 ;
V_4 -> V_20 = ( V_28 -> V_46 == V_47 ) ;
return F_7 ( V_4 ) ;
}
static int F_23 ( struct V_25 * V_25 , void * V_26 ,
struct V_52 * V_53 )
{
struct V_1 * V_4 = F_18 ( V_25 ) ;
if ( V_53 -> V_54 != 0 || V_53 -> type != V_55 )
return - V_39 ;
V_53 -> V_56 = F_24 ( V_53 -> V_56 ,
V_42 * V_43 , V_45 * V_43 ) ;
return F_3 ( V_4 , V_53 -> V_56 , true ) ;
}
static int F_25 ( struct V_25 * V_25 , void * V_26 ,
struct V_52 * V_53 )
{
struct V_1 * V_4 = F_18 ( V_25 ) ;
if ( V_53 -> V_54 != 0 )
return - V_39 ;
V_53 -> type = V_55 ;
V_53 -> V_56 = V_4 -> V_18 ;
return 0 ;
}
static int F_26 ( struct V_57 * V_58 )
{
static const T_1 V_59 [] = {
0x03 , 0x13 , 0x02 , 0x12 , 0x22 , 0x32 ,
0x21 , 0x31 , 0x20 , 0x30 , 0x40 , 0x50
} ;
struct V_1 * V_4 =
F_2 ( V_58 -> V_60 , struct V_1 , V_61 ) ;
switch ( V_58 -> V_62 ) {
case V_63 :
V_4 -> V_11 = V_58 -> V_64 ;
return F_3 ( V_4 , 0 , true ) ;
case V_65 :
V_4 -> V_10 = ( V_58 -> V_64 - 71 ) * 100 / 62 ;
return F_3 ( V_4 , 0 , true ) ;
case V_66 :
V_4 -> V_21 = V_58 -> V_64 == V_67 ;
return F_7 ( V_4 ) ;
case V_68 :
V_4 -> V_19 = V_59 [ ( V_58 -> V_64 - V_58 -> V_69 ) / V_58 -> V_70 ] ;
return F_7 ( V_4 ) ;
}
return - V_39 ;
}
static int F_27 ( struct V_71 * V_72 ,
struct V_73 * V_74 )
{
switch ( V_74 -> type ) {
case V_75 :
return F_28 ( V_72 , V_74 , 0 ) ;
default:
return - V_39 ;
}
}
static void F_29 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_30 ( & V_4 -> V_61 ) ;
F_31 ( V_4 -> V_9 ) ;
F_31 ( V_4 ) ;
}
static int F_32 ( struct V_22 * V_23 ,
const struct V_76 * V_62 )
{
struct V_77 * V_16 = F_33 ( V_23 ) ;
struct V_1 * V_4 ;
struct V_78 * V_61 ;
int V_79 = 0 ;
if ( V_16 -> V_80 && strcmp ( V_16 -> V_80 , L_5 ) )
return - V_81 ;
V_4 = F_34 ( sizeof( struct V_1 ) , V_82 ) ;
if ( V_4 )
V_4 -> V_9 = F_35 ( V_13 , V_82 ) ;
if ( ! V_4 || ! V_4 -> V_9 ) {
F_36 ( & V_23 -> V_16 , L_6 ) ;
F_31 ( V_4 ) ;
V_79 = - V_83 ;
goto V_84;
}
V_61 = & V_4 -> V_61 ;
F_37 ( V_61 , 4 ) ;
F_38 ( V_61 , & V_85 , V_63 ,
0 , 1 , 1 , 0 ) ;
F_39 ( V_61 , & V_85 , V_66 ,
V_67 , 1 , V_86 ) ;
F_38 ( V_61 , & V_85 , V_65 ,
84 , 118 , 1 , 118 ) ;
F_38 ( V_61 , & V_85 , V_68 ,
- 15 , 18 , 3 , 0 ) ;
V_4 -> V_10 = 118 ;
V_4 -> V_19 = 0x32 ;
V_4 -> V_20 = true ;
V_4 -> V_18 = 95.16 * V_43 ;
if ( V_61 -> error ) {
V_79 = V_61 -> error ;
F_30 ( V_61 ) ;
goto V_87;
}
V_79 = F_40 ( & V_23 -> V_16 , & V_4 -> V_3 ) ;
if ( V_79 < 0 ) {
F_36 ( & V_23 -> V_16 , L_7 ) ;
goto V_87;
}
F_41 ( & V_4 -> V_24 ) ;
V_4 -> V_3 . V_88 = V_61 ;
V_4 -> V_3 . V_89 = F_29 ;
F_19 ( V_4 -> V_15 . V_40 , V_4 -> V_3 . V_40 ,
sizeof( V_4 -> V_15 . V_40 ) ) ;
V_4 -> V_15 . V_3 = & V_4 -> V_3 ;
V_4 -> V_15 . V_90 = & V_91 ;
V_4 -> V_15 . V_92 = & V_93 ;
V_4 -> V_15 . V_24 = & V_4 -> V_24 ;
V_4 -> V_15 . V_89 = V_94 ;
V_4 -> V_12 = F_33 ( V_23 ) ;
V_4 -> V_23 = V_23 ;
F_12 ( V_23 , & V_4 -> V_3 ) ;
F_42 ( & V_4 -> V_15 , V_4 ) ;
F_43 ( V_95 , & V_4 -> V_15 . V_96 ) ;
V_79 = F_44 ( & V_4 -> V_15 , V_97 , - 1 ) ;
if ( V_79 < 0 ) {
F_36 ( & V_23 -> V_16 , L_8 ) ;
goto V_98;
}
F_45 ( V_61 ) ;
F_46 ( & V_23 -> V_16 , L_9 ,
F_47 ( & V_4 -> V_15 ) ) ;
return 0 ;
V_98:
F_48 ( & V_4 -> V_3 ) ;
V_87:
F_31 ( V_4 -> V_9 ) ;
F_31 ( V_4 ) ;
V_84:
return V_79 ;
}
static int T_2 F_49 ( void )
{
int V_79 = F_50 ( & V_99 ) ;
if ( V_79 )
F_51 ( V_100
L_10 , V_79 ) ;
return V_79 ;
}
static void T_3 F_52 ( void )
{
F_53 ( & V_99 ) ;
}
