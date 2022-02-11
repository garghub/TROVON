void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( ! V_2 -> V_5 )
return;
F_2 ( 2 , L_1 , V_6 , V_5 -> V_7 ) ;
if ( V_3 )
V_5 -> V_7 = 1 ;
else
V_5 -> V_7 = 0 ;
}
static int F_3 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
T_2 V_8 = 0 , V_9 = 0 ;
F_2 ( 2 , L_2 , V_6 ) ;
switch ( V_5 -> V_10 ) {
case V_11 :
V_9 = 900 ;
V_8 = 700 ;
break;
default:
case V_12 :
V_9 = 900 ;
V_8 = 1780 ;
break;
}
V_8 = V_13 * V_8 ;
V_9 = V_13 * V_9 ;
if ( V_5 -> V_10 == V_11 )
V_9 = V_9 | 0x8000 ;
F_2 ( 2 , L_3 ,
V_6 ,
( V_5 -> V_10 == V_11 ) ? L_4 : L_5 ,
V_13 , V_9 , V_8 ) ;
F_4 ( V_2 , V_14 , 0xfe ) ;
F_4 ( V_2 , V_15 , 0x2f ) ;
F_4 ( V_2 , V_16 , 0xff ) ;
F_4 ( V_2 , V_17 , 0xff ) ;
F_4 ( V_2 , V_18 , V_9 >> 8 ) ;
F_4 ( V_2 , V_19 , V_9 ) ;
F_4 ( V_2 , V_20 , V_8 >> 8 ) ;
F_4 ( V_2 , V_21 , V_8 ) ;
if ( ! V_5 -> V_22 )
F_4 ( V_2 , V_23 , 2 , 0 ) ;
else
F_4 ( V_2 , V_23 , 2 , 1 ) ;
F_5 ( 10 ) ;
F_6 ( V_2 , 0 ) ;
F_5 ( 100 ) ;
F_6 ( V_2 , 1 ) ;
V_5 -> V_24 = 1 ;
return 0 ;
}
static void F_7 ( struct V_25 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_26 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_27 V_28 ;
char * V_29 ;
int V_30 ;
F_2 ( 2 , L_2 , V_6 ) ;
if ( V_25 -> V_31 < 0 || V_25 -> V_32 <= 0 ) {
F_8 ( V_33 L_6 ,
V_25 -> V_31 , V_25 -> V_32 ) ;
V_5 -> V_34 = 1 ;
F_9 ( & V_5 -> V_35 , F_10 ( V_36 ) ) ;
return;
}
V_29 = V_25 -> V_37 ;
if ( V_38 )
F_11 ( V_39 , L_7 ,
V_40 , 16 , 1 ,
V_29 , V_25 -> V_32 , false ) ;
V_28 . V_41 = V_29 [ 0 ] ;
if ( V_25 -> V_32 > 1 )
V_28 . V_41 |= V_29 [ 1 ] << 8 ;
F_2 ( 1 , L_8 , V_6 , V_28 . V_41 ) ;
F_12 ( V_5 -> V_30 , V_28 . V_41 , 0 ) ;
V_30 = F_13 ( V_25 , V_42 ) ;
V_5 -> V_24 = 2 ;
F_9 ( & V_5 -> V_35 , F_10 ( 10 ) ) ;
}
static void F_14 ( struct V_43 * V_35 )
{
struct V_4 * V_5 = F_15 ( V_35 , struct V_4 , V_35 . V_35 ) ;
struct V_1 * V_2 = V_5 -> V_2 ;
struct V_27 V_28 ;
int V_30 ;
T_1 V_29 [ 2 ] ;
if ( V_5 -> V_7 )
return;
F_2 ( 3 , L_2 , V_6 ) ;
V_30 = F_16 ( V_2 , V_44 |
V_45 | V_46 ,
V_47 , 0 , 0 , V_29 , 2 ) ;
if ( V_30 < 0 )
return;
if ( V_30 > 1 )
V_28 . V_41 = V_29 [ 0 ] | V_29 [ 1 ] << 8 ;
else
V_28 . V_41 = V_29 [ 0 ] ;
if ( ( V_28 . V_41 & 0xff ) == 0xff ) {
if ( ! V_5 -> V_24 ) {
F_6 ( V_2 , 1 ) ;
V_5 -> V_24 = 1 ;
}
return;
}
F_2 ( 1 , L_8 , V_6 , V_28 . V_41 ) ;
F_12 ( V_5 -> V_30 , V_28 . V_41 , 0 ) ;
F_6 ( V_2 , 0 ) ;
V_5 -> V_24 = 0 ;
F_9 ( & V_5 -> V_35 , F_10 ( V_5 -> V_22 ) ) ;
}
static void F_17 ( struct V_43 * V_35 )
{
struct V_4 * V_5 = F_15 ( V_35 , struct V_4 , V_35 . V_35 ) ;
struct V_1 * V_2 = V_5 -> V_2 ;
int V_30 ;
F_2 ( 3 , L_9 , V_6 , V_5 -> V_34 ,
V_5 -> V_24 ) ;
if ( V_5 -> V_34 ) {
F_2 ( 3 , L_10 ) ;
F_4 ( V_2 , V_23 , 2 , 0 ) ;
V_30 = F_13 ( V_5 -> V_48 , V_42 ) ;
if ( V_30 < 0 ) {
F_8 ( V_49 L_11 ,
V_30 ) ;
F_9 ( & V_5 -> V_35 , F_10 ( V_36 ) ) ;
return;
}
V_5 -> V_34 = 0 ;
}
if ( V_5 -> V_24 == 2 ) {
F_6 ( V_2 , 0 ) ;
V_5 -> V_24 = 0 ;
F_9 ( & V_5 -> V_35 , F_10 ( V_50 ) ) ;
} else if ( ! V_5 -> V_24 ) {
F_6 ( V_2 , 1 ) ;
V_5 -> V_24 = 1 ;
}
}
static int F_18 ( struct V_51 * V_30 )
{
struct V_4 * V_5 = V_30 -> V_52 ;
F_2 ( 2 , L_2 , V_6 ) ;
F_9 ( & V_5 -> V_35 , 0 ) ;
return 0 ;
}
static void F_19 ( struct V_51 * V_30 )
{
struct V_4 * V_5 = V_30 -> V_52 ;
F_2 ( 2 , L_2 , V_6 ) ;
F_20 ( & V_5 -> V_35 ) ;
}
static int F_21 ( struct V_51 * V_30 , T_3 V_10 )
{
struct V_4 * V_5 = V_30 -> V_52 ;
if ( ! V_5 )
return 0 ;
F_2 ( 2 , L_2 , V_6 ) ;
if ( ( V_30 -> V_53 . V_54 ) && ( V_10 == V_11 ) )
V_5 -> V_55 = ( ( V_30 -> V_53 . V_54 [ 0 ] . V_56 >> 8 ) & 0xffff ) ;
V_5 -> V_10 = V_10 ;
F_3 ( V_5 ) ;
return 0 ;
}
static int F_22 ( struct V_51 * V_30 )
{
struct V_4 * V_5 = V_30 -> V_52 ;
struct V_1 * V_2 = V_5 -> V_2 ;
int V_57 , V_58 ;
int V_59 = - V_60 ;
if ( ! V_5 )
return - V_61 ;
F_2 ( 2 , L_2 , V_6 ) ;
V_5 -> V_48 = F_23 ( 0 , V_42 ) ;
if ( ! V_5 -> V_48 )
return - V_60 ;
V_57 = F_24 ( V_2 -> V_62 ,
V_2 -> V_63 . V_64 -> V_65 . V_66
& V_67 ) ;
V_58 = F_25 ( V_2 -> V_62 , V_57 , F_26 ( V_57 ) ) ;
F_2 ( 1 , L_12 , V_58 ) ;
V_5 -> V_48 -> V_37 = F_27 ( V_58 , V_42 ) ;
if ( V_5 -> V_48 -> V_37 == NULL ) {
F_28 ( V_5 -> V_48 ) ;
return V_59 ;
}
F_2 ( 1 , L_13 , V_2 -> V_63 . V_64 -> V_65 . V_68 ) ;
F_29 ( V_5 -> V_48 , V_2 -> V_62 , V_57 ,
V_5 -> V_48 -> V_37 , V_58 ,
F_7 , V_2 ,
V_2 -> V_63 . V_64 -> V_65 . V_68 ) ;
V_5 -> V_34 = 1 ;
F_9 ( & V_5 -> V_35 , F_10 ( V_36 ) ) ;
return 0 ;
}
static void F_30 ( struct V_51 * V_30 )
{
struct V_4 * V_5 = V_30 -> V_52 ;
if ( ! V_5 || ! V_5 -> V_48 )
return;
F_2 ( 2 , L_2 , V_6 ) ;
F_31 ( V_5 -> V_48 ) ;
F_32 ( V_5 -> V_48 -> V_37 ) ;
F_28 ( V_5 -> V_48 ) ;
V_5 -> V_48 = NULL ;
}
int F_33 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( ! V_5 )
return 0 ;
return F_22 ( V_5 -> V_30 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( ! V_5 || ! V_5 -> V_30 )
return;
F_30 ( V_5 -> V_30 ) ;
}
int F_35 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_51 * V_30 ;
int V_59 = - V_60 ;
if ( ! V_69 )
return - V_61 ;
if ( ! V_2 -> V_70 . V_71 )
return 0 ;
if ( ! V_2 -> V_72 )
return 0 ;
V_5 = F_27 ( sizeof( * V_5 ) , V_42 ) ;
V_30 = F_36 () ;
if ( ! V_5 || ! V_30 )
goto V_73;
F_2 ( 2 , L_2 , V_6 ) ;
V_5 -> V_2 = V_2 ;
V_2 -> V_5 = V_5 ;
V_5 -> V_30 = V_30 ;
V_30 -> V_74 = V_12 | V_11 ;
V_30 -> V_75 = 0xffff ;
V_30 -> V_52 = V_5 ;
V_30 -> V_76 = F_21 ;
if ( V_2 -> V_63 . V_64 ) {
V_30 -> V_77 = F_22 ;
V_30 -> V_78 = F_30 ;
F_37 ( & V_5 -> V_35 , F_17 ) ;
} else {
V_30 -> V_77 = F_18 ;
V_30 -> V_78 = F_19 ;
V_5 -> V_22 = 50 ;
F_37 ( & V_5 -> V_35 , F_14 ) ;
}
V_30 -> V_79 = V_80 ;
snprintf ( V_5 -> V_81 , sizeof( V_5 -> V_81 ) , L_14 ,
V_2 -> V_81 ) ;
F_38 ( V_2 -> V_62 , V_5 -> V_82 , sizeof( V_5 -> V_82 ) ) ;
F_39 ( V_5 -> V_82 , L_15 , sizeof( V_5 -> V_82 ) ) ;
F_21 ( V_30 , V_83 ) ;
V_30 -> V_84 = V_5 -> V_81 ;
V_30 -> V_85 = V_5 -> V_82 ;
V_30 -> V_86 . V_87 = V_88 ;
V_30 -> V_86 . V_89 = 1 ;
V_30 -> V_86 . V_90 = F_40 ( V_2 -> V_62 -> V_91 . V_92 ) ;
V_30 -> V_86 . V_93 = F_40 ( V_2 -> V_62 -> V_91 . V_94 ) ;
V_30 -> V_95 = V_2 -> V_72 ;
V_30 -> V_96 = L_16 ;
V_30 -> V_2 . V_97 = & V_2 -> V_62 -> V_2 ;
V_59 = F_41 ( V_30 ) ;
if ( V_59 )
goto V_73;
return 0 ;
V_73:
V_2 -> V_5 = NULL ;
F_42 ( V_30 ) ;
F_32 ( V_5 ) ;
return V_59 ;
}
int F_43 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( ! V_5 )
return 0 ;
F_2 ( 2 , L_2 , V_6 ) ;
if ( ! V_5 -> V_22 )
F_30 ( V_5 -> V_30 ) ;
F_19 ( V_5 -> V_30 ) ;
F_6 ( V_2 , 0 ) ;
V_5 -> V_24 = 0 ;
F_44 ( V_5 -> V_30 ) ;
F_32 ( V_5 ) ;
V_2 -> V_5 = NULL ;
return 0 ;
}
