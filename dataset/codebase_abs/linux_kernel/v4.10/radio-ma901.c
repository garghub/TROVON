static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_4 , int V_5 )
{
unsigned int V_6 = 0x300 + ( V_5 >> 5 ) / 25 ;
int V_7 ;
V_4 -> V_8 [ 0 ] = 0x0a ;
V_4 -> V_8 [ 1 ] = V_9 ;
V_4 -> V_8 [ 2 ] = ( ( V_6 >> 8 ) & 0xff ) + 0x80 ;
V_4 -> V_8 [ 3 ] = V_6 & 0xff ;
V_4 -> V_8 [ 4 ] = 0x00 ;
V_4 -> V_8 [ 5 ] = 0x00 ;
V_4 -> V_8 [ 6 ] = 0x00 ;
V_4 -> V_8 [ 7 ] = 0x00 ;
V_7 = F_4 ( V_4 -> V_10 , F_5 ( V_4 -> V_10 , 0 ) ,
9 , 0x21 , 0x0300 , 0 ,
V_4 -> V_8 , V_11 , V_12 ) ;
if ( V_7 < 0 )
return V_7 ;
V_4 -> V_13 = V_5 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_4 , T_1 V_14 )
{
int V_7 ;
V_4 -> V_8 [ 0 ] = 0x0a ;
V_4 -> V_8 [ 1 ] = V_15 ;
V_4 -> V_8 [ 2 ] = 0xc2 ;
V_4 -> V_8 [ 3 ] = V_14 + 0x20 ;
V_4 -> V_8 [ 4 ] = 0x00 ;
V_4 -> V_8 [ 5 ] = 0x00 ;
V_4 -> V_8 [ 6 ] = 0x00 ;
V_4 -> V_8 [ 7 ] = 0x00 ;
V_7 = F_4 ( V_4 -> V_10 , F_5 ( V_4 -> V_10 , 0 ) ,
9 , 0x21 , 0x0300 , 0 ,
V_4 -> V_8 , V_11 , V_12 ) ;
if ( V_7 < 0 )
return V_7 ;
V_4 -> V_16 = V_14 ;
return V_7 ;
}
static int F_7 ( struct V_1 * V_4 , T_2 V_17 )
{
int V_7 ;
V_4 -> V_8 [ 0 ] = 0x0a ;
V_4 -> V_8 [ 1 ] = V_18 ;
V_4 -> V_8 [ 2 ] = V_17 ;
V_4 -> V_8 [ 3 ] = 0x00 ;
V_4 -> V_8 [ 4 ] = 0x00 ;
V_4 -> V_8 [ 5 ] = 0x00 ;
V_4 -> V_8 [ 6 ] = 0x00 ;
V_4 -> V_8 [ 7 ] = 0x00 ;
V_7 = F_4 ( V_4 -> V_10 , F_5 ( V_4 -> V_10 , 0 ) ,
9 , 0x21 , 0x0300 , 0 ,
V_4 -> V_8 , V_11 , V_12 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_17 == V_19 )
V_4 -> V_17 = V_20 ;
else
V_4 -> V_17 = V_21 ;
return V_7 ;
}
static void F_8 ( struct V_22 * V_23 )
{
struct V_1 * V_4 = F_1 ( F_9 ( V_23 ) ) ;
F_10 ( & V_4 -> V_24 ) ;
F_11 ( & V_4 -> V_25 ) ;
F_12 ( V_23 , NULL ) ;
F_13 ( & V_4 -> V_3 ) ;
F_14 ( & V_4 -> V_24 ) ;
F_15 ( & V_4 -> V_3 ) ;
}
static int F_16 ( struct V_26 * V_26 , void * V_27 ,
struct V_28 * V_29 )
{
struct V_1 * V_4 = F_17 ( V_26 ) ;
F_18 ( V_29 -> V_30 , L_1 , sizeof( V_29 -> V_30 ) ) ;
F_18 ( V_29 -> V_31 , L_2 , sizeof( V_29 -> V_31 ) ) ;
F_19 ( V_4 -> V_10 , V_29 -> V_32 , sizeof( V_29 -> V_32 ) ) ;
V_29 -> V_33 = V_34 | V_35 ;
V_29 -> V_36 = V_29 -> V_33 | V_37 ;
return 0 ;
}
static int F_20 ( struct V_26 * V_26 , void * V_27 ,
struct V_38 * V_29 )
{
struct V_1 * V_4 = F_17 ( V_26 ) ;
if ( V_29 -> V_39 > 0 )
return - V_40 ;
V_29 -> signal = 0 ;
strcpy ( V_29 -> V_41 , L_3 ) ;
V_29 -> type = V_42 ;
V_29 -> V_43 = V_44 * V_45 ;
V_29 -> V_46 = V_47 * V_45 ;
V_29 -> V_48 = V_49 | V_50 ;
V_29 -> V_51 = V_4 -> V_17 ?
V_20 : V_21 ;
return 0 ;
}
static int F_21 ( struct V_26 * V_26 , void * V_27 ,
const struct V_38 * V_29 )
{
struct V_1 * V_4 = F_17 ( V_26 ) ;
if ( V_29 -> V_39 > 0 )
return - V_40 ;
switch ( V_29 -> V_51 ) {
case V_21 :
return F_7 ( V_4 , V_52 ) ;
default:
return F_7 ( V_4 , V_19 ) ;
}
}
static int F_22 ( struct V_26 * V_26 , void * V_27 ,
const struct V_53 * V_54 )
{
struct V_1 * V_4 = F_17 ( V_26 ) ;
if ( V_54 -> V_55 != 0 )
return - V_40 ;
return F_3 ( V_4 , F_23 ( unsigned , V_54 -> V_56 ,
V_44 * V_45 , V_47 * V_45 ) ) ;
}
static int F_24 ( struct V_26 * V_26 , void * V_27 ,
struct V_53 * V_54 )
{
struct V_1 * V_4 = F_17 ( V_26 ) ;
if ( V_54 -> V_55 != 0 )
return - V_40 ;
V_54 -> V_56 = V_4 -> V_13 ;
return 0 ;
}
static int F_25 ( struct V_57 * V_58 )
{
struct V_1 * V_4 =
F_2 ( V_58 -> V_59 , struct V_1 , V_60 ) ;
switch ( V_58 -> V_61 ) {
case V_62 :
return F_6 ( V_4 , ( T_1 ) V_58 -> V_63 ) ;
}
return - V_40 ;
}
static int F_26 ( struct V_22 * V_23 , T_3 V_64 )
{
return 0 ;
}
static int F_27 ( struct V_22 * V_23 )
{
return 0 ;
}
static void F_28 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_29 ( & V_4 -> V_60 ) ;
F_30 ( & V_4 -> V_3 ) ;
F_31 ( V_4 -> V_8 ) ;
F_31 ( V_4 ) ;
}
static int F_32 ( struct V_22 * V_23 ,
const struct V_65 * V_61 )
{
struct V_66 * V_67 = F_33 ( V_23 ) ;
struct V_1 * V_4 ;
int V_7 = 0 ;
if ( V_67 -> V_68 && V_67 -> V_69 &&
( strncmp ( V_67 -> V_68 , L_4 , 5 ) != 0
|| strncmp ( V_67 -> V_69 , L_5 , 16 ) != 0 ) )
return - V_70 ;
V_4 = F_34 ( sizeof( struct V_1 ) , V_71 ) ;
if ( ! V_4 ) {
F_35 ( & V_23 -> V_67 , L_6 ) ;
V_7 = - V_72 ;
goto V_73;
}
V_4 -> V_8 = F_36 ( V_11 , V_71 ) ;
if ( ! V_4 -> V_8 ) {
F_35 ( & V_23 -> V_67 , L_7 ) ;
V_7 = - V_72 ;
goto V_74;
}
V_7 = F_37 ( & V_23 -> V_67 , & V_4 -> V_3 ) ;
if ( V_7 < 0 ) {
F_35 ( & V_23 -> V_67 , L_8 ) ;
goto V_75;
}
F_38 ( & V_4 -> V_60 , 1 ) ;
F_39 ( & V_4 -> V_60 , & V_76 ,
V_62 , V_77 ,
V_78 , 1 , V_78 ) ;
if ( V_4 -> V_60 . error ) {
V_7 = V_4 -> V_60 . error ;
F_35 ( & V_23 -> V_67 , L_9 ) ;
goto V_79;
}
F_40 ( & V_4 -> V_24 ) ;
V_4 -> V_3 . V_80 = & V_4 -> V_60 ;
V_4 -> V_3 . V_81 = F_28 ;
F_18 ( V_4 -> V_25 . V_41 , V_4 -> V_3 . V_41 ,
sizeof( V_4 -> V_25 . V_41 ) ) ;
V_4 -> V_25 . V_3 = & V_4 -> V_3 ;
V_4 -> V_25 . V_82 = & V_83 ;
V_4 -> V_25 . V_84 = & V_85 ;
V_4 -> V_25 . V_81 = V_86 ;
V_4 -> V_25 . V_24 = & V_4 -> V_24 ;
V_4 -> V_10 = F_33 ( V_23 ) ;
V_4 -> V_23 = V_23 ;
F_12 ( V_23 , & V_4 -> V_3 ) ;
V_4 -> V_13 = 95.21 * V_45 ;
F_41 ( & V_4 -> V_25 , V_4 ) ;
V_7 = F_42 ( & V_4 -> V_25 , V_87 ,
V_88 ) ;
if ( V_7 < 0 ) {
F_35 ( & V_23 -> V_67 , L_10 ) ;
goto V_89;
}
return 0 ;
V_89:
F_29 ( & V_4 -> V_60 ) ;
V_79:
F_30 ( & V_4 -> V_3 ) ;
V_75:
F_31 ( V_4 -> V_8 ) ;
V_74:
F_31 ( V_4 ) ;
V_73:
return V_7 ;
}
