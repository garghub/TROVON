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
static T_1 F_9 ( struct V_22 * V_23 , struct V_24 * V_25 ,
struct V_26 * V_13 ,
char * V_14 , T_3 V_27 , T_2 V_20 )
{
int V_28 ;
unsigned char V_29 ;
struct V_1 * V_2 = F_10 ( V_25 ) ;
struct V_15 * V_8 = F_6 ( V_2 ) ;
V_29 = V_30 + V_27 ;
V_28 = F_11 ( V_8 -> V_9 , V_29 , V_14 , V_20 ) ;
if ( V_28 < 0 )
F_12 ( & V_8 -> V_31 -> V_2 , L_5 , V_28 ) ;
return ( V_28 < 0 ) ? V_28 : V_20 ;
}
static T_1 F_13 ( struct V_22 * V_23 , struct V_24 * V_25 ,
struct V_26 * V_13 ,
char * V_14 , T_3 V_27 , T_2 V_20 )
{
int V_28 ;
unsigned char V_29 ;
struct V_1 * V_2 = F_10 ( V_25 ) ;
struct V_15 * V_8 = F_6 ( V_2 ) ;
V_29 = V_30 + V_27 ;
V_28 = F_14 ( V_8 -> V_9 , V_29 , V_14 , V_20 ) ;
if ( V_28 < 0 )
F_12 ( & V_8 -> V_31 -> V_2 , L_6 , V_28 ) ;
return ( V_28 < 0 ) ? V_28 : V_20 ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_15 * V_8 = F_6 ( V_2 ) ;
int V_32 , V_17 ;
F_7 ( V_8 -> V_9 , V_18 , & V_17 ) ;
V_32 = ! ! ( V_17 & V_33 ) ;
if ( V_32 )
return sprintf ( V_14 , L_1 ) ;
else
return sprintf ( V_14 , L_2 ) ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_15 * V_8 = F_6 ( V_2 ) ;
int V_34 , V_17 ;
char * V_35 ;
F_7 ( V_8 -> V_9 , V_36 , & V_17 ) ;
V_34 = ( V_17 & 0x80 ) >> 4 ;
F_7 ( V_8 -> V_9 , V_37 , & V_17 ) ;
V_34 |= ( V_17 & 0x80 ) >> 5 ;
F_7 ( V_8 -> V_9 , V_38 , & V_17 ) ;
V_34 |= ( V_17 & 0x80 ) >> 6 ;
F_7 ( V_8 -> V_9 , V_39 , & V_17 ) ;
V_34 |= ( V_17 & 0x80 ) >> 7 ;
switch ( V_34 ) {
case 15 :
V_35 = L_7 ;
break;
case 7 :
V_35 = L_8 ;
break;
case 3 :
V_35 = L_9 ;
break;
case 1 :
V_35 = L_10 ;
break;
case 0 :
V_35 = L_11 ;
break;
default:
V_35 = L_12 ;
break;
}
return sprintf ( V_14 , L_13 , V_35 ) ;
}
static T_1 F_17 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_15 * V_8 = F_6 ( V_2 ) ;
int V_17 ;
char * V_40 = L_4 , * V_41 = L_14 ;
F_7 ( V_8 -> V_9 , V_10 , & V_17 ) ;
if ( ( V_17 & 0xf0 ) == V_42 ) {
switch ( V_17 & 0x0c ) {
case V_43 :
V_40 = L_15 ;
break;
default:
V_40 = L_16 ;
break;
}
switch ( V_17 & 0x03 ) {
case V_44 :
V_41 = L_17 ;
break;
case V_45 :
V_41 = L_18 ;
break;
case V_46 :
V_41 = L_19 ;
break;
default:
V_40 = L_4 ;
break;
}
}
return sprintf ( V_14 , L_20 , V_40 , V_41 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_15 * V_8 = F_6 ( V_2 ) ;
int V_47 ;
V_47 = F_19 ( V_2 , & V_48 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_19 ( V_2 , & V_49 ) ;
if ( V_47 )
goto V_50;
V_47 = F_20 ( V_2 , & V_51 ) ;
if ( V_47 )
goto V_52;
if ( V_8 -> V_53 <= 0 )
return V_47 ;
V_47 = F_19 ( V_2 , & V_54 ) ;
if ( V_47 )
goto V_55;
V_47 = F_19 ( V_2 , & V_56 ) ;
if ( ! V_47 )
return V_47 ;
F_21 ( V_2 , & V_54 ) ;
V_55:
F_22 ( V_2 , & V_51 ) ;
V_52:
F_21 ( V_2 , & V_49 ) ;
V_50:
F_21 ( V_2 , & V_48 ) ;
return V_47 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_15 * V_8 = F_6 ( V_2 ) ;
F_21 ( V_2 , & V_48 ) ;
F_21 ( V_2 , & V_49 ) ;
F_22 ( V_2 , & V_51 ) ;
if ( V_8 -> V_53 <= 0 )
return;
F_21 ( V_2 , & V_56 ) ;
F_21 ( V_2 , & V_54 ) ;
}
static int F_24 ( struct V_1 * V_2 , struct V_57 * V_58 )
{
struct V_15 * V_8 = F_6 ( V_2 ) ;
unsigned char V_14 [ 7 ] ;
int V_59 ;
V_59 = F_14 ( V_8 -> V_9 , V_60 , V_14 , 7 ) ;
if ( V_59 )
return V_59 ;
V_58 -> V_61 = F_25 ( V_14 [ 0 ] ) ;
V_58 -> V_62 = F_25 ( V_14 [ 1 ] ) ;
V_58 -> V_63 = F_25 ( V_14 [ 2 ] & 0x3F ) ;
V_58 -> V_64 = F_25 ( V_14 [ 3 ] ) - 1 ;
V_58 -> V_65 = F_25 ( V_14 [ 4 ] ) ;
V_58 -> V_66 = F_25 ( V_14 [ 5 ] & 0x1F ) - 1 ;
V_58 -> V_67 = F_25 ( V_14 [ 6 ] ) + 100 ;
return F_26 ( V_58 ) ;
}
static int F_27 ( struct V_1 * V_2 , struct V_57 * V_58 )
{
struct V_15 * V_8 = F_6 ( V_2 ) ;
int V_59 ;
V_59 = F_4 ( V_8 -> V_9 , V_60 ,
F_28 ( V_58 -> V_61 ) ) ;
if ( V_59 )
return V_59 ;
V_59 = F_4 ( V_8 -> V_9 , V_68 ,
F_28 ( V_58 -> V_62 ) ) ;
if ( V_59 )
return V_59 ;
V_59 = F_4 ( V_8 -> V_9 , V_69 ,
F_28 ( V_58 -> V_63 ) & 0x3F ) ;
if ( V_59 )
return V_59 ;
V_59 = F_4 ( V_8 -> V_9 , V_70 ,
F_28 ( V_58 -> V_64 + 1 ) ) ;
if ( V_59 )
return V_59 ;
V_59 = F_4 ( V_8 -> V_9 , V_71 ,
F_28 ( V_58 -> V_65 ) ) ;
if ( V_59 )
return V_59 ;
V_59 = F_4 ( V_8 -> V_9 , V_72 ,
F_28 ( V_58 -> V_66 + 1 ) ) ;
if ( V_59 )
return V_59 ;
V_58 -> V_67 %= 100 ;
V_59 = F_4 ( V_8 -> V_9 , V_73 ,
F_28 ( V_58 -> V_67 ) ) ;
if ( V_59 )
return V_59 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_15 * V_8 = F_6 ( V_2 ) ;
unsigned int V_74 , V_75 ;
unsigned char V_14 [ 4 ] ;
int V_59 = 0 ;
V_59 = F_7 ( V_8 -> V_9 , V_18 , & V_74 ) ;
if ( V_59 )
return V_59 ;
V_59 = F_7 ( V_8 -> V_9 , V_76 , & V_75 ) ;
if ( V_59 )
return V_59 ;
V_74 &= ~ ( V_33 ) ;
V_75 &= ~ ( V_77 ) ;
V_59 = F_4 ( V_8 -> V_9 , V_18 , V_74 ) ;
if ( V_59 )
return V_59 ;
V_59 = F_4 ( V_8 -> V_9 , V_76 , V_75 ) ;
if ( V_59 )
return V_59 ;
V_14 [ 0 ] = V_8 -> V_78 < 0 || ( V_8 -> V_79 & V_80 ) ?
0x80 : F_28 ( V_8 -> V_78 ) & 0x7F ;
V_14 [ 1 ] = V_8 -> V_81 < 0 || ( V_8 -> V_79 & V_80 ) ?
0x80 : F_28 ( V_8 -> V_81 ) & 0x7F ;
V_14 [ 2 ] = V_8 -> V_82 < 0 || ( V_8 -> V_79 & V_80 ) ?
0x80 : F_28 ( V_8 -> V_82 ) & 0x3F ;
V_14 [ 3 ] = V_8 -> V_83 < 0 || ( V_8 -> V_79 & V_80 ) ?
0x80 : F_28 ( V_8 -> V_83 ) & 0x7F ;
V_59 = F_11 ( V_8 -> V_9 , V_36 , V_14 , 4 ) ;
if ( V_59 )
return V_59 ;
if ( V_8 -> V_79 ) {
V_74 |= V_33 ;
V_59 = F_4 ( V_8 -> V_9 , V_18 , V_74 ) ;
}
return V_59 ;
}
static int F_30 ( struct V_1 * V_2 , struct V_84 * V_85 )
{
struct V_15 * V_8 = F_6 ( V_2 ) ;
int V_59 = 0 ;
unsigned int V_75 ;
if ( V_8 -> V_53 <= 0 )
return - V_21 ;
F_31 ( & V_8 -> V_86 ) ;
V_59 = F_7 ( V_8 -> V_9 , V_76 , & V_75 ) ;
if ( V_59 )
goto V_87;
V_85 -> V_88 = ! ! ( V_8 -> V_79 & V_89 ) ;
V_85 -> V_90 = ! ! ( V_75 & V_77 ) ;
V_85 -> time . V_61 = V_8 -> V_78 < 0 ? 0 : V_8 -> V_78 ;
V_85 -> time . V_62 = V_8 -> V_81 < 0 ? 0 : V_8 -> V_81 ;
V_85 -> time . V_63 = V_8 -> V_82 < 0 ? 0 : V_8 -> V_82 ;
V_85 -> time . V_65 = V_8 -> V_83 < 0 ? 0 : V_8 -> V_83 ;
V_85 -> time . V_66 = - 1 ;
V_85 -> time . V_67 = - 1 ;
V_85 -> time . V_64 = - 1 ;
V_85 -> time . V_91 = - 1 ;
V_85 -> time . V_92 = - 1 ;
V_87:
F_32 ( & V_8 -> V_86 ) ;
return V_59 ;
}
static int F_33 ( struct V_1 * V_2 , struct V_84 * V_85 )
{
struct V_15 * V_8 = F_6 ( V_2 ) ;
int V_59 = 0 ;
if ( V_8 -> V_53 <= 0 )
return - V_21 ;
F_31 ( & V_8 -> V_86 ) ;
V_8 -> V_78 = V_85 -> time . V_61 ;
V_8 -> V_81 = V_85 -> time . V_62 ;
V_8 -> V_82 = V_85 -> time . V_63 ;
V_8 -> V_83 = V_85 -> time . V_65 ;
if ( V_85 -> V_88 )
V_8 -> V_79 |= V_89 ;
V_59 = F_29 ( V_2 ) ;
F_32 ( & V_8 -> V_86 ) ;
return V_59 ;
}
static int F_34 ( struct V_1 * V_2 , unsigned int V_88 )
{
struct V_15 * V_8 = F_6 ( V_2 ) ;
int V_59 = 0 ;
if ( V_8 -> V_53 <= 0 )
return - V_21 ;
F_31 ( & V_8 -> V_86 ) ;
if ( V_88 )
V_8 -> V_79 |= V_89 ;
else
V_8 -> V_79 &= ~ V_89 ;
V_59 = F_29 ( V_2 ) ;
F_32 ( & V_8 -> V_86 ) ;
return V_59 ;
}
static T_4 F_35 ( int V_53 , void * V_93 )
{
struct V_15 * V_8 = V_93 ;
unsigned int V_75 , V_74 ;
int V_59 = 0 ;
F_31 ( & V_8 -> V_86 ) ;
V_59 = F_7 ( V_8 -> V_9 , V_76 , & V_75 ) ;
if ( V_59 )
goto V_87;
if ( V_75 & V_77 ) {
V_75 &= ~ V_77 ;
F_4 ( V_8 -> V_9 , V_76 , V_75 ) ;
V_59 = F_7 ( V_8 -> V_9 , V_18 , & V_74 ) ;
if ( V_59 )
goto V_87;
V_74 &= ~ V_33 ;
F_4 ( V_8 -> V_9 , V_18 , V_74 ) ;
F_36 ( V_8 -> V_94 , 1 , V_89 | V_95 ) ;
}
V_87:
F_32 ( & V_8 -> V_86 ) ;
return V_96 ;
}
static int F_37 ( struct V_97 * V_31 )
{
struct V_15 * V_8 ;
struct V_98 V_99 ;
unsigned int V_17 ;
int V_59 ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
V_99 . V_100 = 8 ;
V_99 . V_101 = 8 ;
V_99 . V_102 = 0x80 ;
V_8 = F_38 ( & V_31 -> V_2 , sizeof( struct V_15 ) , V_103 ) ;
if ( ! V_8 )
return - V_104 ;
V_8 -> V_31 = V_31 ;
F_39 ( & V_8 -> V_86 ) ;
V_31 -> V_105 = V_106 | V_107 ;
V_31 -> V_108 = 8 ;
V_59 = F_40 ( V_31 ) ;
if ( V_59 )
return V_59 ;
F_41 ( V_31 , V_8 ) ;
V_8 -> V_9 = F_42 ( V_31 , & V_99 ) ;
if ( F_43 ( V_8 -> V_9 ) ) {
F_12 ( & V_31 -> V_2 , L_21 ) ;
return F_44 ( V_8 -> V_9 ) ;
}
V_59 = F_7 ( V_8 -> V_9 , V_60 , & V_17 ) ;
if ( V_59 )
return V_59 ;
F_7 ( V_8 -> V_9 , V_18 , & V_17 ) ;
V_17 |= V_109 ;
V_17 &= ~ ( V_110 | V_111 | V_33 ) ;
F_4 ( V_8 -> V_9 , V_18 , V_17 ) ;
F_7 ( V_8 -> V_9 , V_76 , & V_17 ) ;
V_17 &= ~ ( V_112 | V_113 | V_77 ) ;
F_4 ( V_8 -> V_9 , V_76 , V_17 ) ;
V_8 -> V_94 = F_45 ( & V_31 -> V_2 , L_22 ,
& V_114 , V_115 ) ;
if ( F_43 ( V_8 -> V_94 ) ) {
F_12 ( & V_31 -> V_2 , L_23 ) ;
return F_44 ( V_8 -> V_94 ) ;
}
V_8 -> V_53 = V_31 -> V_53 ;
if ( V_8 -> V_53 >= 0 ) {
V_59 = F_46 ( & V_31 -> V_2 , V_31 -> V_53 , NULL ,
F_35 , V_116 ,
L_22 , V_8 ) ;
if ( V_59 ) {
V_8 -> V_53 = - 1 ;
F_12 ( & V_31 -> V_2 ,
L_24 ) ;
} else {
F_47 ( & V_31 -> V_2 , true ) ;
F_48 ( & V_31 -> V_2 , V_31 -> V_53 ) ;
}
}
V_59 = F_18 ( & V_31 -> V_2 ) ;
if ( V_59 )
F_12 ( & V_31 -> V_2 ,
L_25 ) ;
return 0 ;
}
static int F_49 ( struct V_97 * V_31 )
{
struct V_15 * V_8 = F_50 ( V_31 ) ;
if ( V_31 -> V_53 ) {
F_31 ( & V_8 -> V_86 ) ;
V_8 -> V_79 &= ~ V_89 ;
F_32 ( & V_8 -> V_86 ) ;
F_51 ( & V_31 -> V_2 ) ;
F_47 ( & V_31 -> V_2 , false ) ;
F_52 ( & V_31 -> V_2 , V_31 -> V_53 , V_8 ) ;
}
F_41 ( V_31 , NULL ) ;
F_23 ( & V_31 -> V_2 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_97 * V_31 = F_54 ( V_2 ) ;
if ( V_31 -> V_53 >= 0 && F_55 ( V_2 ) )
F_56 ( V_31 -> V_53 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_97 * V_31 = F_54 ( V_2 ) ;
if ( V_31 -> V_53 >= 0 && F_55 ( V_2 ) )
F_58 ( V_31 -> V_53 ) ;
return 0 ;
}
