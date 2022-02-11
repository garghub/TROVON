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
static void F_7 ( struct V_4 * V_5 ,
const char * V_25 , unsigned int V_26 )
{
T_1 V_27 , V_28 ;
T_2 V_29 ;
enum V_10 V_30 ;
if ( V_26 < 1 )
return;
V_28 = V_25 [ 0 ] ;
V_27 = ( V_26 > 1 ? V_25 [ 1 ] : 0x0 ) ;
switch ( V_5 -> V_10 ) {
case V_12 :
V_30 = V_31 ;
V_29 = F_8 ( V_27 , V_28 ) ;
break;
case V_11 :
V_30 = V_32 ;
V_29 = F_9 ( V_27 , V_28 ) ;
break;
default:
V_30 = V_33 ;
V_29 = F_10 ( V_27 << 8 | V_28 ) ;
break;
}
F_2 ( 1 , L_6 ,
V_6 , V_30 , V_29 ) ;
F_11 ( V_5 -> V_34 , V_30 , V_29 , 0 ) ;
}
static void F_12 ( struct V_35 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_36 ;
struct V_4 * V_5 = V_2 -> V_5 ;
char * V_25 ;
F_2 ( 2 , L_2 , V_6 ) ;
if ( V_35 -> V_37 < 0 || V_35 -> V_38 <= 0 ) {
F_13 ( V_39 L_7 ,
V_35 -> V_37 , V_35 -> V_38 ) ;
V_5 -> V_40 = 1 ;
F_14 ( & V_5 -> V_41 , F_15 ( V_42 ) ) ;
return;
}
V_25 = V_35 -> V_43 ;
if ( V_44 )
F_16 ( V_45 , L_8 ,
V_46 , 16 , 1 ,
V_25 , V_35 -> V_38 , false ) ;
F_7 ( V_5 , V_35 -> V_43 , V_35 -> V_38 ) ;
F_17 ( V_35 , V_47 ) ;
V_5 -> V_24 = 2 ;
F_14 ( & V_5 -> V_41 , F_15 ( 10 ) ) ;
}
static void F_18 ( struct V_48 * V_41 )
{
struct V_4 * V_5 = F_19 ( V_41 , struct V_4 , V_41 . V_41 ) ;
struct V_1 * V_2 = V_5 -> V_2 ;
int V_34 ;
T_1 V_25 [ 2 ] ;
if ( V_5 -> V_7 )
return;
F_2 ( 3 , L_2 , V_6 ) ;
V_34 = F_20 ( V_2 , V_49 |
V_50 | V_51 ,
V_52 , 0 , 0 , V_25 , 2 ) ;
if ( V_34 < 0 )
return;
if ( ( V_25 [ 0 ] & 0xff ) == 0xff ) {
if ( ! V_5 -> V_24 ) {
F_6 ( V_2 , 1 ) ;
V_5 -> V_24 = 1 ;
}
return;
}
F_7 ( V_5 , V_25 , V_34 ) ;
F_6 ( V_2 , 0 ) ;
V_5 -> V_24 = 0 ;
F_14 ( & V_5 -> V_41 , F_15 ( V_5 -> V_22 ) ) ;
}
static void F_21 ( struct V_48 * V_41 )
{
struct V_4 * V_5 = F_19 ( V_41 , struct V_4 , V_41 . V_41 ) ;
struct V_1 * V_2 = V_5 -> V_2 ;
int V_34 ;
F_2 ( 3 , L_9 , V_6 , V_5 -> V_40 ,
V_5 -> V_24 ) ;
if ( V_5 -> V_40 ) {
F_2 ( 3 , L_10 ) ;
F_4 ( V_2 , V_23 , 2 , 0 ) ;
V_34 = F_17 ( V_5 -> V_53 , V_47 ) ;
if ( V_34 < 0 ) {
F_13 ( V_54 L_11 ,
V_34 ) ;
F_14 ( & V_5 -> V_41 , F_15 ( V_42 ) ) ;
return;
}
V_5 -> V_40 = 0 ;
}
if ( V_5 -> V_24 == 2 ) {
F_6 ( V_2 , 0 ) ;
V_5 -> V_24 = 0 ;
F_14 ( & V_5 -> V_41 , F_15 ( V_55 ) ) ;
} else if ( ! V_5 -> V_24 ) {
F_6 ( V_2 , 1 ) ;
V_5 -> V_24 = 1 ;
}
}
static int F_22 ( struct V_56 * V_34 )
{
struct V_4 * V_5 = V_34 -> V_57 ;
F_2 ( 2 , L_2 , V_6 ) ;
F_14 ( & V_5 -> V_41 , 0 ) ;
return 0 ;
}
static void F_23 ( struct V_56 * V_34 )
{
struct V_4 * V_5 = V_34 -> V_57 ;
F_2 ( 2 , L_2 , V_6 ) ;
F_24 ( & V_5 -> V_41 ) ;
}
static int F_25 ( struct V_56 * V_34 , T_3 * V_10 )
{
struct V_4 * V_5 = V_34 -> V_57 ;
if ( ! V_5 )
return 0 ;
F_2 ( 2 , L_2 , V_6 ) ;
if ( ( V_34 -> V_58 . V_59 ) && ( * V_10 == V_11 ) )
V_5 -> V_60 = ( ( V_34 -> V_58 . V_59 [ 0 ] . V_29 >> 8 ) & 0xffff ) ;
V_5 -> V_10 = * V_10 ;
F_3 ( V_5 ) ;
return 0 ;
}
static int F_26 ( struct V_56 * V_34 )
{
struct V_4 * V_5 = V_34 -> V_57 ;
struct V_1 * V_2 ;
int V_61 , V_62 ;
int V_63 = - V_64 ;
if ( ! V_5 )
return - V_65 ;
V_2 = V_5 -> V_2 ;
F_2 ( 2 , L_2 , V_6 ) ;
V_5 -> V_53 = F_27 ( 0 , V_47 ) ;
if ( ! V_5 -> V_53 )
return - V_64 ;
V_61 = F_28 ( V_2 -> V_66 ,
V_2 -> V_67 . V_68 -> V_69 . V_70
& V_71 ) ;
V_62 = F_29 ( V_2 -> V_66 , V_61 , F_30 ( V_61 ) ) ;
F_2 ( 1 , L_12 , V_62 ) ;
V_5 -> V_53 -> V_43 = F_31 ( V_62 , V_47 ) ;
if ( V_5 -> V_53 -> V_43 == NULL ) {
F_32 ( V_5 -> V_53 ) ;
return V_63 ;
}
F_2 ( 1 , L_13 , V_2 -> V_67 . V_68 -> V_69 . V_72 ) ;
F_33 ( V_5 -> V_53 , V_2 -> V_66 , V_61 ,
V_5 -> V_53 -> V_43 , V_62 ,
F_12 , V_2 ,
V_2 -> V_67 . V_68 -> V_69 . V_72 ) ;
V_5 -> V_40 = 1 ;
F_14 ( & V_5 -> V_41 , F_15 ( V_42 ) ) ;
return 0 ;
}
static void F_34 ( struct V_56 * V_34 )
{
struct V_4 * V_5 = V_34 -> V_57 ;
if ( ! V_5 || ! V_5 -> V_53 )
return;
F_2 ( 2 , L_2 , V_6 ) ;
F_35 ( V_5 -> V_53 ) ;
F_36 ( V_5 -> V_53 -> V_43 ) ;
F_32 ( V_5 -> V_53 ) ;
V_5 -> V_53 = NULL ;
}
int F_37 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( ! V_5 )
return 0 ;
return F_26 ( V_5 -> V_34 ) ;
}
void F_38 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( ! V_5 || ! V_5 -> V_34 )
return;
F_34 ( V_5 -> V_34 ) ;
}
int F_39 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_56 * V_34 ;
int V_63 = - V_64 ;
T_3 V_10 ;
if ( ! V_73 )
return - V_65 ;
if ( ! V_2 -> V_74 . V_75 )
return 0 ;
if ( ! V_2 -> V_76 )
return 0 ;
V_5 = F_31 ( sizeof( * V_5 ) , V_47 ) ;
V_34 = F_40 ( V_77 ) ;
if ( ! V_5 || ! V_34 )
goto V_78;
F_2 ( 2 , L_2 , V_6 ) ;
V_5 -> V_2 = V_2 ;
V_2 -> V_5 = V_5 ;
V_5 -> V_34 = V_34 ;
V_34 -> V_79 = V_12 | V_11 ;
V_34 -> V_80 = 0xffff ;
V_34 -> V_57 = V_5 ;
V_34 -> V_81 = F_25 ;
if ( V_2 -> V_67 . V_68 ) {
V_34 -> V_82 = F_26 ;
V_34 -> V_83 = F_34 ;
F_41 ( & V_5 -> V_41 , F_21 ) ;
} else {
V_34 -> V_82 = F_22 ;
V_34 -> V_83 = F_23 ;
V_5 -> V_22 = 50 ;
F_41 ( & V_5 -> V_41 , F_18 ) ;
}
snprintf ( V_5 -> V_84 , sizeof( V_5 -> V_84 ) , L_14 ,
V_2 -> V_84 ) ;
F_42 ( V_2 -> V_66 , V_5 -> V_85 , sizeof( V_5 -> V_85 ) ) ;
F_43 ( V_5 -> V_85 , L_15 , sizeof( V_5 -> V_85 ) ) ;
V_10 = V_86 ;
F_25 ( V_34 , & V_10 ) ;
V_34 -> V_87 = V_5 -> V_84 ;
V_34 -> V_88 = V_5 -> V_85 ;
V_34 -> V_89 . V_90 = V_91 ;
V_34 -> V_89 . V_92 = 1 ;
V_34 -> V_89 . V_93 = F_44 ( V_2 -> V_66 -> V_94 . V_95 ) ;
V_34 -> V_89 . V_96 = F_44 ( V_2 -> V_66 -> V_94 . V_97 ) ;
V_34 -> V_98 = V_2 -> V_76 ;
V_34 -> V_99 = L_16 ;
V_34 -> V_2 . V_100 = & V_2 -> V_66 -> V_2 ;
V_63 = F_45 ( V_34 ) ;
if ( V_63 )
goto V_78;
return 0 ;
V_78:
V_2 -> V_5 = NULL ;
F_46 ( V_34 ) ;
F_36 ( V_5 ) ;
return V_63 ;
}
int F_47 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( ! V_5 )
return 0 ;
F_2 ( 2 , L_2 , V_6 ) ;
if ( ! V_5 -> V_22 )
F_34 ( V_5 -> V_34 ) ;
F_23 ( V_5 -> V_34 ) ;
F_6 ( V_2 , 0 ) ;
V_5 -> V_24 = 0 ;
F_48 ( V_5 -> V_34 ) ;
F_36 ( V_5 ) ;
V_2 -> V_5 = NULL ;
return 0 ;
}
