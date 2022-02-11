static int F_1 ( struct V_1 * V_2 , unsigned int V_3 , unsigned long V_4 )
{
switch ( V_3 ) {
#ifdef F_2
case F_2 :
{
int V_5 ;
if ( F_3 ( & V_5 , ( int V_6 * ) V_4 , sizeof( int ) ) )
return - V_7 ;
return F_4 ( V_8 -> V_9 , V_10 , V_5 ) ;
}
break;
#endif
}
return - V_11 ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_15 * V_8 = F_6 ( V_2 ) ;
int V_16 , V_17 ;
F_7 ( V_8 -> V_9 , V_18 , & V_17 ) ;
V_16 = ! ! ( V_17 & V_19 ) ;
if ( V_16 )
return sprintf ( V_14 , L_1 ) ;
else
return sprintf ( V_14 , L_2 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
const char * V_14 , T_2 V_20 )
{
struct V_15 * V_8 = F_6 ( V_2 ) ;
int V_17 ;
F_7 ( V_8 -> V_9 , V_18 , & V_17 ) ;
if ( strncmp ( V_14 , L_3 , 7 ) == 0 )
V_17 |= V_19 ;
else if ( strncmp ( V_14 , L_4 , 8 ) == 0 )
V_17 &= ~ ( V_19 ) ;
else
return - V_21 ;
F_4 ( V_8 -> V_9 , V_18 , V_17 ) ;
return V_20 ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_15 * V_8 = F_6 ( V_2 ) ;
int V_22 , V_17 ;
F_7 ( V_8 -> V_9 , V_18 , & V_17 ) ;
V_22 = ! ! ( V_17 & V_23 ) ;
if ( V_22 )
return sprintf ( V_14 , L_1 ) ;
else
return sprintf ( V_14 , L_2 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_15 * V_8 = F_6 ( V_2 ) ;
int V_24 , V_17 ;
char * V_25 ;
F_7 ( V_8 -> V_9 , V_26 , & V_17 ) ;
V_24 = ( V_17 & 0x80 ) >> 4 ;
F_7 ( V_8 -> V_9 , V_27 , & V_17 ) ;
V_24 |= ( V_17 & 0x80 ) >> 5 ;
F_7 ( V_8 -> V_9 , V_28 , & V_17 ) ;
V_24 |= ( V_17 & 0x80 ) >> 6 ;
F_7 ( V_8 -> V_9 , V_29 , & V_17 ) ;
V_24 |= ( V_17 & 0x80 ) >> 7 ;
switch ( V_24 ) {
case 15 :
V_25 = L_5 ;
break;
case 7 :
V_25 = L_6 ;
break;
case 3 :
V_25 = L_7 ;
break;
case 1 :
V_25 = L_8 ;
break;
case 0 :
V_25 = L_9 ;
break;
default:
V_25 = L_10 ;
break;
}
return sprintf ( V_14 , L_11 , V_25 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_15 * V_8 = F_6 ( V_2 ) ;
int V_17 ;
char * V_30 = L_4 , * V_31 = L_12 ;
F_7 ( V_8 -> V_9 , V_10 , & V_17 ) ;
if ( ( V_17 & 0xf0 ) == V_32 ) {
switch ( V_17 & 0x0c ) {
case V_33 :
V_30 = L_13 ;
break;
default:
V_30 = L_14 ;
break;
}
switch ( V_17 & 0x03 ) {
case V_34 :
V_31 = L_15 ;
break;
case V_35 :
V_31 = L_16 ;
break;
case V_36 :
V_31 = L_17 ;
break;
default:
V_30 = L_4 ;
break;
}
}
return sprintf ( V_14 , L_18 , V_30 , V_31 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_15 * V_8 = F_6 ( V_2 ) ;
int V_37 ;
V_37 = F_13 ( V_2 , & V_38 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_13 ( V_2 , & V_39 ) ;
if ( V_37 )
goto V_40;
if ( V_8 -> V_41 <= 0 )
return V_37 ;
V_37 = F_13 ( V_2 , & V_42 ) ;
if ( V_37 )
goto V_43;
V_37 = F_13 ( V_2 , & V_44 ) ;
if ( ! V_37 )
return V_37 ;
F_14 ( V_2 , & V_42 ) ;
V_43:
F_14 ( V_2 , & V_39 ) ;
V_40:
F_14 ( V_2 , & V_38 ) ;
return V_37 ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_15 * V_8 = F_6 ( V_2 ) ;
F_14 ( V_2 , & V_38 ) ;
F_14 ( V_2 , & V_39 ) ;
if ( V_8 -> V_41 <= 0 )
return;
F_14 ( V_2 , & V_44 ) ;
F_14 ( V_2 , & V_42 ) ;
}
static int F_16 ( struct V_1 * V_2 , struct V_45 * V_46 )
{
struct V_15 * V_8 = F_6 ( V_2 ) ;
unsigned char V_14 [ 7 ] ;
int V_47 ;
V_47 = F_17 ( V_8 -> V_9 , V_48 , V_14 , 7 ) ;
if ( V_47 )
return V_47 ;
V_46 -> V_49 = F_18 ( V_14 [ 0 ] ) ;
V_46 -> V_50 = F_18 ( V_14 [ 1 ] ) ;
V_46 -> V_51 = F_18 ( V_14 [ 2 ] & 0x3F ) ;
V_46 -> V_52 = F_18 ( V_14 [ 3 ] ) - 1 ;
V_46 -> V_53 = F_18 ( V_14 [ 4 ] ) ;
V_46 -> V_54 = F_18 ( V_14 [ 5 ] & 0x1F ) - 1 ;
V_46 -> V_55 = F_18 ( V_14 [ 6 ] ) + 100 ;
return F_19 ( V_46 ) ;
}
static int F_20 ( struct V_1 * V_2 , struct V_45 * V_46 )
{
struct V_15 * V_8 = F_6 ( V_2 ) ;
int V_47 ;
V_47 = F_4 ( V_8 -> V_9 , V_48 ,
F_21 ( V_46 -> V_49 ) ) ;
if ( V_47 )
return V_47 ;
V_47 = F_4 ( V_8 -> V_9 , V_56 ,
F_21 ( V_46 -> V_50 ) ) ;
if ( V_47 )
return V_47 ;
V_47 = F_4 ( V_8 -> V_9 , V_57 ,
F_21 ( V_46 -> V_51 ) & 0x3F ) ;
if ( V_47 )
return V_47 ;
V_47 = F_4 ( V_8 -> V_9 , V_58 ,
F_21 ( V_46 -> V_52 + 1 ) ) ;
if ( V_47 )
return V_47 ;
V_47 = F_4 ( V_8 -> V_9 , V_59 ,
F_21 ( V_46 -> V_53 ) ) ;
if ( V_47 )
return V_47 ;
V_47 = F_4 ( V_8 -> V_9 , V_60 ,
F_21 ( V_46 -> V_54 + 1 ) ) ;
if ( V_47 )
return V_47 ;
V_46 -> V_55 %= 100 ;
V_47 = F_4 ( V_8 -> V_9 , V_61 ,
F_21 ( V_46 -> V_55 ) ) ;
if ( V_47 )
return V_47 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_15 * V_8 = F_6 ( V_2 ) ;
unsigned int V_62 , V_63 ;
unsigned char V_14 [ 4 ] ;
int V_47 = 0 ;
V_47 = F_7 ( V_8 -> V_9 , V_18 , & V_62 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_7 ( V_8 -> V_9 , V_64 , & V_63 ) ;
if ( V_47 )
return V_47 ;
V_62 &= ~ ( V_23 ) ;
V_63 &= ~ ( V_65 ) ;
V_47 = F_4 ( V_8 -> V_9 , V_18 , V_62 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_4 ( V_8 -> V_9 , V_64 , V_63 ) ;
if ( V_47 )
return V_47 ;
V_14 [ 0 ] = V_8 -> V_66 < 0 || ( V_8 -> V_67 & V_68 ) ?
0x80 : F_21 ( V_8 -> V_66 ) & 0x7F ;
V_14 [ 1 ] = V_8 -> V_69 < 0 || ( V_8 -> V_67 & V_68 ) ?
0x80 : F_21 ( V_8 -> V_69 ) & 0x7F ;
V_14 [ 2 ] = V_8 -> V_70 < 0 || ( V_8 -> V_67 & V_68 ) ?
0x80 : F_21 ( V_8 -> V_70 ) & 0x3F ;
V_14 [ 3 ] = V_8 -> V_71 < 0 || ( V_8 -> V_67 & V_68 ) ?
0x80 : F_21 ( V_8 -> V_71 ) & 0x7F ;
V_47 = F_23 ( V_8 -> V_9 , V_26 , V_14 , 4 ) ;
if ( V_47 )
return V_47 ;
if ( V_8 -> V_67 ) {
V_62 |= V_23 ;
V_47 = F_4 ( V_8 -> V_9 , V_18 , V_62 ) ;
}
return V_47 ;
}
static int F_24 ( struct V_1 * V_2 , struct V_72 * V_73 )
{
struct V_15 * V_8 = F_6 ( V_2 ) ;
int V_47 = 0 ;
unsigned int V_63 ;
if ( V_8 -> V_41 <= 0 )
return - V_21 ;
F_25 ( & V_8 -> V_74 ) ;
V_47 = F_7 ( V_8 -> V_9 , V_64 , & V_63 ) ;
if ( V_47 )
goto V_75;
V_73 -> V_76 = ! ! ( V_8 -> V_67 & V_77 ) ;
V_73 -> V_78 = ! ! ( V_63 & V_65 ) ;
V_73 -> time . V_49 = V_8 -> V_66 < 0 ? 0 : V_8 -> V_66 ;
V_73 -> time . V_50 = V_8 -> V_69 < 0 ? 0 : V_8 -> V_69 ;
V_73 -> time . V_51 = V_8 -> V_70 < 0 ? 0 : V_8 -> V_70 ;
V_73 -> time . V_53 = V_8 -> V_71 < 0 ? 0 : V_8 -> V_71 ;
V_73 -> time . V_54 = - 1 ;
V_73 -> time . V_55 = - 1 ;
V_73 -> time . V_52 = - 1 ;
V_73 -> time . V_79 = - 1 ;
V_73 -> time . V_80 = - 1 ;
V_75:
F_26 ( & V_8 -> V_74 ) ;
return V_47 ;
}
static int F_27 ( struct V_1 * V_2 , struct V_72 * V_73 )
{
struct V_15 * V_8 = F_6 ( V_2 ) ;
int V_47 = 0 ;
if ( V_8 -> V_41 <= 0 )
return - V_21 ;
F_25 ( & V_8 -> V_74 ) ;
V_8 -> V_66 = V_73 -> time . V_49 ;
V_8 -> V_69 = V_73 -> time . V_50 ;
V_8 -> V_70 = V_73 -> time . V_51 ;
V_8 -> V_71 = V_73 -> time . V_53 ;
if ( V_73 -> V_76 )
V_8 -> V_67 |= V_77 ;
V_47 = F_22 ( V_2 ) ;
F_26 ( & V_8 -> V_74 ) ;
return V_47 ;
}
static int F_28 ( struct V_1 * V_2 , unsigned int V_76 )
{
struct V_15 * V_8 = F_6 ( V_2 ) ;
int V_47 = 0 ;
if ( V_8 -> V_41 <= 0 )
return - V_21 ;
F_25 ( & V_8 -> V_74 ) ;
if ( V_76 )
V_8 -> V_67 |= V_77 ;
else
V_8 -> V_67 &= ~ V_77 ;
V_47 = F_22 ( V_2 ) ;
F_26 ( & V_8 -> V_74 ) ;
return V_47 ;
}
static T_3 F_29 ( int V_41 , void * V_81 )
{
struct V_15 * V_8 = V_81 ;
unsigned int V_63 , V_62 ;
int V_47 = 0 ;
F_25 ( & V_8 -> V_74 ) ;
V_47 = F_7 ( V_8 -> V_9 , V_64 , & V_63 ) ;
if ( V_47 )
goto V_75;
if ( V_63 & V_65 ) {
V_63 &= ~ V_65 ;
F_4 ( V_8 -> V_9 , V_64 , V_63 ) ;
V_47 = F_7 ( V_8 -> V_9 , V_18 , & V_62 ) ;
if ( V_47 )
goto V_75;
V_62 &= ~ V_23 ;
F_4 ( V_8 -> V_9 , V_18 , V_62 ) ;
F_30 ( V_8 -> V_82 , 1 , V_77 | V_83 ) ;
}
V_75:
F_26 ( & V_8 -> V_74 ) ;
return V_84 ;
}
static int F_31 ( struct V_85 * V_86 )
{
struct V_15 * V_8 ;
struct V_87 V_88 ;
unsigned int V_17 ;
int V_47 ;
memset ( & V_88 , 0 , sizeof( V_88 ) ) ;
V_88 . V_89 = 8 ;
V_88 . V_90 = 8 ;
V_88 . V_91 = 0x80 ;
V_8 = F_32 ( & V_86 -> V_2 , sizeof( struct V_15 ) , V_92 ) ;
if ( ! V_8 )
return - V_93 ;
V_8 -> V_86 = V_86 ;
F_33 ( & V_8 -> V_74 ) ;
V_86 -> V_94 = V_95 | V_96 ;
V_86 -> V_97 = 8 ;
V_47 = F_34 ( V_86 ) ;
if ( V_47 )
return V_47 ;
F_35 ( V_86 , V_8 ) ;
V_8 -> V_9 = F_36 ( V_86 , & V_88 ) ;
if ( F_37 ( V_8 -> V_9 ) ) {
F_38 ( & V_86 -> V_2 , L_19 ) ;
return F_39 ( V_8 -> V_9 ) ;
}
V_47 = F_7 ( V_8 -> V_9 , V_48 , & V_17 ) ;
if ( V_47 )
return V_47 ;
F_7 ( V_8 -> V_9 , V_18 , & V_17 ) ;
V_17 |= V_98 ;
V_17 &= ~ ( V_99 | V_100 | V_23 ) ;
F_4 ( V_8 -> V_9 , V_18 , V_17 ) ;
F_7 ( V_8 -> V_9 , V_64 , & V_17 ) ;
V_17 &= ~ ( V_101 | V_102 | V_65 ) ;
F_4 ( V_8 -> V_9 , V_64 , V_17 ) ;
V_8 -> V_82 = F_40 ( & V_86 -> V_2 , L_20 ,
& V_103 , V_104 ) ;
if ( F_37 ( V_8 -> V_82 ) ) {
F_38 ( & V_86 -> V_2 , L_21 ) ;
return F_39 ( V_8 -> V_82 ) ;
}
V_8 -> V_41 = V_86 -> V_41 ;
if ( V_8 -> V_41 >= 0 ) {
V_47 = F_41 ( & V_86 -> V_2 , V_86 -> V_41 , NULL ,
F_29 ,
V_105 | V_106 ,
L_20 , V_8 ) ;
if ( V_47 ) {
V_8 -> V_41 = - 1 ;
F_38 ( & V_86 -> V_2 ,
L_22 ) ;
} else {
F_42 ( & V_86 -> V_2 , 1 ) ;
}
}
V_47 = F_12 ( & V_86 -> V_2 ) ;
if ( V_47 )
F_38 ( & V_86 -> V_2 ,
L_23 ) ;
return 0 ;
}
static int F_43 ( struct V_85 * V_86 )
{
struct V_15 * V_8 = F_44 ( V_86 ) ;
if ( V_86 -> V_41 ) {
F_25 ( & V_8 -> V_74 ) ;
V_8 -> V_67 &= ~ V_77 ;
F_26 ( & V_8 -> V_74 ) ;
F_45 ( & V_86 -> V_2 , V_86 -> V_41 , V_8 ) ;
}
F_35 ( V_86 , NULL ) ;
F_15 ( & V_86 -> V_2 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_85 * V_86 = F_47 ( V_2 ) ;
if ( V_86 -> V_41 >= 0 && F_48 ( V_2 ) )
F_49 ( V_86 -> V_41 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_85 * V_86 = F_47 ( V_2 ) ;
if ( V_86 -> V_41 >= 0 && F_48 ( V_2 ) )
F_51 ( V_86 -> V_41 ) ;
return 0 ;
}
