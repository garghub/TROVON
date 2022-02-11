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
if ( F_11 ( ! V_20 ) )
return V_20 ;
if ( ( V_20 + V_27 ) > V_30 )
V_20 = V_30 - V_27 ;
V_29 = V_31 + V_27 ;
V_28 = F_12 ( V_8 -> V_9 , V_29 , V_14 , V_20 ) ;
if ( V_28 < 0 )
F_13 ( & V_8 -> V_32 -> V_2 , L_5 , V_28 ) ;
return ( V_28 < 0 ) ? V_28 : V_20 ;
}
static T_1 F_14 ( struct V_22 * V_23 , struct V_24 * V_25 ,
struct V_26 * V_13 ,
char * V_14 , T_3 V_27 , T_2 V_20 )
{
int V_28 ;
unsigned char V_29 ;
struct V_1 * V_2 = F_10 ( V_25 ) ;
struct V_15 * V_8 = F_6 ( V_2 ) ;
if ( F_11 ( ! V_20 ) )
return V_20 ;
if ( ( V_20 + V_27 ) > V_30 )
V_20 = V_30 - V_27 ;
V_29 = V_31 + V_27 ;
V_28 = F_15 ( V_8 -> V_9 , V_29 , V_14 , V_20 ) ;
if ( V_28 < 0 )
F_13 ( & V_8 -> V_32 -> V_2 , L_6 , V_28 ) ;
return ( V_28 < 0 ) ? V_28 : V_20 ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_15 * V_8 = F_6 ( V_2 ) ;
int V_33 , V_17 ;
F_7 ( V_8 -> V_9 , V_18 , & V_17 ) ;
V_33 = ! ! ( V_17 & V_34 ) ;
if ( V_33 )
return sprintf ( V_14 , L_1 ) ;
else
return sprintf ( V_14 , L_2 ) ;
}
static T_1 F_17 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_15 * V_8 = F_6 ( V_2 ) ;
int V_35 , V_17 ;
char * V_36 ;
F_7 ( V_8 -> V_9 , V_37 , & V_17 ) ;
V_35 = ( V_17 & 0x80 ) >> 4 ;
F_7 ( V_8 -> V_9 , V_38 , & V_17 ) ;
V_35 |= ( V_17 & 0x80 ) >> 5 ;
F_7 ( V_8 -> V_9 , V_39 , & V_17 ) ;
V_35 |= ( V_17 & 0x80 ) >> 6 ;
F_7 ( V_8 -> V_9 , V_40 , & V_17 ) ;
V_35 |= ( V_17 & 0x80 ) >> 7 ;
switch ( V_35 ) {
case 15 :
V_36 = L_7 ;
break;
case 7 :
V_36 = L_8 ;
break;
case 3 :
V_36 = L_9 ;
break;
case 1 :
V_36 = L_10 ;
break;
case 0 :
V_36 = L_11 ;
break;
default:
V_36 = L_12 ;
break;
}
return sprintf ( V_14 , L_13 , V_36 ) ;
}
static T_1 F_18 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_15 * V_8 = F_6 ( V_2 ) ;
int V_17 ;
char * V_41 = L_4 , * V_42 = L_14 ;
F_7 ( V_8 -> V_9 , V_10 , & V_17 ) ;
if ( ( V_17 & 0xf0 ) == V_43 ) {
switch ( V_17 & 0x0c ) {
case V_44 :
V_41 = L_15 ;
break;
default:
V_41 = L_16 ;
break;
}
switch ( V_17 & 0x03 ) {
case V_45 :
V_42 = L_17 ;
break;
case V_46 :
V_42 = L_18 ;
break;
case V_47 :
V_42 = L_19 ;
break;
default:
V_41 = L_4 ;
break;
}
}
return sprintf ( V_14 , L_20 , V_41 , V_42 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_15 * V_8 = F_6 ( V_2 ) ;
int V_48 ;
V_48 = F_20 ( V_2 , & V_49 ) ;
if ( V_48 )
return V_48 ;
V_48 = F_20 ( V_2 , & V_50 ) ;
if ( V_48 )
goto V_51;
V_48 = F_21 ( V_2 , & V_52 ) ;
if ( V_48 )
goto V_53;
if ( V_8 -> V_54 <= 0 )
return V_48 ;
V_48 = F_20 ( V_2 , & V_55 ) ;
if ( V_48 )
goto V_56;
V_48 = F_20 ( V_2 , & V_57 ) ;
if ( ! V_48 )
return V_48 ;
F_22 ( V_2 , & V_55 ) ;
V_56:
F_23 ( V_2 , & V_52 ) ;
V_53:
F_22 ( V_2 , & V_50 ) ;
V_51:
F_22 ( V_2 , & V_49 ) ;
return V_48 ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_15 * V_8 = F_6 ( V_2 ) ;
F_22 ( V_2 , & V_49 ) ;
F_22 ( V_2 , & V_50 ) ;
F_23 ( V_2 , & V_52 ) ;
if ( V_8 -> V_54 <= 0 )
return;
F_22 ( V_2 , & V_57 ) ;
F_22 ( V_2 , & V_55 ) ;
}
static int F_25 ( struct V_1 * V_2 , struct V_58 * V_59 )
{
struct V_15 * V_8 = F_6 ( V_2 ) ;
unsigned char V_14 [ 7 ] ;
int V_60 ;
V_60 = F_15 ( V_8 -> V_9 , V_61 , V_14 , 7 ) ;
if ( V_60 )
return V_60 ;
V_59 -> V_62 = F_26 ( V_14 [ 0 ] ) ;
V_59 -> V_63 = F_26 ( V_14 [ 1 ] ) ;
V_59 -> V_64 = F_26 ( V_14 [ 2 ] & 0x3F ) ;
V_59 -> V_65 = F_26 ( V_14 [ 3 ] ) - 1 ;
V_59 -> V_66 = F_26 ( V_14 [ 4 ] ) ;
V_59 -> V_67 = F_26 ( V_14 [ 5 ] & 0x1F ) - 1 ;
V_59 -> V_68 = F_26 ( V_14 [ 6 ] ) + 100 ;
return F_27 ( V_59 ) ;
}
static int F_28 ( struct V_1 * V_2 , struct V_58 * V_59 )
{
struct V_15 * V_8 = F_6 ( V_2 ) ;
int V_60 ;
V_60 = F_4 ( V_8 -> V_9 , V_61 ,
F_29 ( V_59 -> V_62 ) ) ;
if ( V_60 )
return V_60 ;
V_60 = F_4 ( V_8 -> V_9 , V_69 ,
F_29 ( V_59 -> V_63 ) ) ;
if ( V_60 )
return V_60 ;
V_60 = F_4 ( V_8 -> V_9 , V_70 ,
F_29 ( V_59 -> V_64 ) & 0x3F ) ;
if ( V_60 )
return V_60 ;
V_60 = F_4 ( V_8 -> V_9 , V_71 ,
F_29 ( V_59 -> V_65 + 1 ) ) ;
if ( V_60 )
return V_60 ;
V_60 = F_4 ( V_8 -> V_9 , V_72 ,
F_29 ( V_59 -> V_66 ) ) ;
if ( V_60 )
return V_60 ;
V_60 = F_4 ( V_8 -> V_9 , V_73 ,
F_29 ( V_59 -> V_67 + 1 ) ) ;
if ( V_60 )
return V_60 ;
V_59 -> V_68 %= 100 ;
V_60 = F_4 ( V_8 -> V_9 , V_74 ,
F_29 ( V_59 -> V_68 ) ) ;
if ( V_60 )
return V_60 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_15 * V_8 = F_6 ( V_2 ) ;
unsigned int V_75 , V_76 ;
unsigned char V_14 [ 4 ] ;
int V_60 = 0 ;
V_60 = F_7 ( V_8 -> V_9 , V_18 , & V_75 ) ;
if ( V_60 )
return V_60 ;
V_60 = F_7 ( V_8 -> V_9 , V_77 , & V_76 ) ;
if ( V_60 )
return V_60 ;
V_75 &= ~ ( V_34 ) ;
V_76 &= ~ ( V_78 ) ;
V_60 = F_4 ( V_8 -> V_9 , V_18 , V_75 ) ;
if ( V_60 )
return V_60 ;
V_60 = F_4 ( V_8 -> V_9 , V_77 , V_76 ) ;
if ( V_60 )
return V_60 ;
V_14 [ 0 ] = V_8 -> V_79 < 0 || ( V_8 -> V_80 & V_81 ) ?
0x80 : F_29 ( V_8 -> V_79 ) & 0x7F ;
V_14 [ 1 ] = V_8 -> V_82 < 0 || ( V_8 -> V_80 & V_81 ) ?
0x80 : F_29 ( V_8 -> V_82 ) & 0x7F ;
V_14 [ 2 ] = V_8 -> V_83 < 0 || ( V_8 -> V_80 & V_81 ) ?
0x80 : F_29 ( V_8 -> V_83 ) & 0x3F ;
V_14 [ 3 ] = V_8 -> V_84 < 0 || ( V_8 -> V_80 & V_81 ) ?
0x80 : F_29 ( V_8 -> V_84 ) & 0x7F ;
V_60 = F_12 ( V_8 -> V_9 , V_37 , V_14 , 4 ) ;
if ( V_60 )
return V_60 ;
if ( V_8 -> V_80 ) {
V_75 |= V_34 ;
V_60 = F_4 ( V_8 -> V_9 , V_18 , V_75 ) ;
}
return V_60 ;
}
static int F_31 ( struct V_1 * V_2 , struct V_85 * V_86 )
{
struct V_15 * V_8 = F_6 ( V_2 ) ;
int V_60 = 0 ;
unsigned int V_76 ;
if ( V_8 -> V_54 <= 0 )
return - V_21 ;
F_32 ( & V_8 -> V_87 ) ;
V_60 = F_7 ( V_8 -> V_9 , V_77 , & V_76 ) ;
if ( V_60 )
goto V_88;
V_86 -> V_89 = ! ! ( V_8 -> V_80 & V_90 ) ;
V_86 -> V_91 = ! ! ( V_76 & V_78 ) ;
V_86 -> time . V_62 = V_8 -> V_79 < 0 ? 0 : V_8 -> V_79 ;
V_86 -> time . V_63 = V_8 -> V_82 < 0 ? 0 : V_8 -> V_82 ;
V_86 -> time . V_64 = V_8 -> V_83 < 0 ? 0 : V_8 -> V_83 ;
V_86 -> time . V_66 = V_8 -> V_84 < 0 ? 0 : V_8 -> V_84 ;
V_86 -> time . V_67 = - 1 ;
V_86 -> time . V_68 = - 1 ;
V_86 -> time . V_65 = - 1 ;
V_86 -> time . V_92 = - 1 ;
V_86 -> time . V_93 = - 1 ;
V_88:
F_33 ( & V_8 -> V_87 ) ;
return V_60 ;
}
static int F_34 ( struct V_1 * V_2 , struct V_85 * V_86 )
{
struct V_15 * V_8 = F_6 ( V_2 ) ;
int V_60 = 0 ;
if ( V_8 -> V_54 <= 0 )
return - V_21 ;
F_32 ( & V_8 -> V_87 ) ;
V_8 -> V_79 = V_86 -> time . V_62 ;
V_8 -> V_82 = V_86 -> time . V_63 ;
V_8 -> V_83 = V_86 -> time . V_64 ;
V_8 -> V_84 = V_86 -> time . V_66 ;
if ( V_86 -> V_89 )
V_8 -> V_80 |= V_90 ;
V_60 = F_30 ( V_2 ) ;
F_33 ( & V_8 -> V_87 ) ;
return V_60 ;
}
static int F_35 ( struct V_1 * V_2 , unsigned int V_89 )
{
struct V_15 * V_8 = F_6 ( V_2 ) ;
int V_60 = 0 ;
if ( V_8 -> V_54 <= 0 )
return - V_21 ;
F_32 ( & V_8 -> V_87 ) ;
if ( V_89 )
V_8 -> V_80 |= V_90 ;
else
V_8 -> V_80 &= ~ V_90 ;
V_60 = F_30 ( V_2 ) ;
F_33 ( & V_8 -> V_87 ) ;
return V_60 ;
}
static T_4 F_36 ( int V_54 , void * V_94 )
{
struct V_15 * V_8 = V_94 ;
unsigned int V_76 , V_75 ;
int V_60 = 0 ;
F_32 ( & V_8 -> V_87 ) ;
V_60 = F_7 ( V_8 -> V_9 , V_77 , & V_76 ) ;
if ( V_60 )
goto V_88;
if ( V_76 & V_78 ) {
V_76 &= ~ V_78 ;
F_4 ( V_8 -> V_9 , V_77 , V_76 ) ;
V_60 = F_7 ( V_8 -> V_9 , V_18 , & V_75 ) ;
if ( V_60 )
goto V_88;
V_75 &= ~ V_34 ;
F_4 ( V_8 -> V_9 , V_18 , V_75 ) ;
F_37 ( V_8 -> V_95 , 1 , V_90 | V_96 ) ;
}
V_88:
F_33 ( & V_8 -> V_87 ) ;
return V_97 ;
}
static int F_38 ( struct V_98 * V_32 )
{
struct V_15 * V_8 ;
struct V_99 V_100 ;
unsigned int V_17 ;
int V_60 ;
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
V_100 . V_101 = 8 ;
V_100 . V_102 = 8 ;
V_100 . V_103 = 0x80 ;
V_8 = F_39 ( & V_32 -> V_2 , sizeof( struct V_15 ) , V_104 ) ;
if ( ! V_8 )
return - V_105 ;
V_8 -> V_32 = V_32 ;
F_40 ( & V_8 -> V_87 ) ;
V_32 -> V_106 = V_107 | V_108 ;
V_32 -> V_109 = 8 ;
V_60 = F_41 ( V_32 ) ;
if ( V_60 )
return V_60 ;
F_42 ( V_32 , V_8 ) ;
V_8 -> V_9 = F_43 ( V_32 , & V_100 ) ;
if ( F_44 ( V_8 -> V_9 ) ) {
F_13 ( & V_32 -> V_2 , L_21 ) ;
return F_45 ( V_8 -> V_9 ) ;
}
V_60 = F_7 ( V_8 -> V_9 , V_61 , & V_17 ) ;
if ( V_60 )
return V_60 ;
F_7 ( V_8 -> V_9 , V_18 , & V_17 ) ;
V_17 |= V_110 ;
V_17 &= ~ ( V_111 | V_112 | V_34 ) ;
F_4 ( V_8 -> V_9 , V_18 , V_17 ) ;
F_7 ( V_8 -> V_9 , V_77 , & V_17 ) ;
V_17 &= ~ ( V_113 | V_114 | V_78 ) ;
F_4 ( V_8 -> V_9 , V_77 , V_17 ) ;
V_8 -> V_95 = F_46 ( & V_32 -> V_2 , L_22 ,
& V_115 , V_116 ) ;
if ( F_44 ( V_8 -> V_95 ) ) {
F_13 ( & V_32 -> V_2 , L_23 ) ;
return F_45 ( V_8 -> V_95 ) ;
}
V_8 -> V_54 = V_32 -> V_54 ;
if ( V_8 -> V_54 >= 0 ) {
V_60 = F_47 ( & V_32 -> V_2 , V_32 -> V_54 , NULL ,
F_36 ,
V_117 | V_118 ,
L_22 , V_8 ) ;
if ( V_60 ) {
V_8 -> V_54 = - 1 ;
F_13 ( & V_32 -> V_2 ,
L_24 ) ;
} else {
F_48 ( & V_32 -> V_2 , 1 ) ;
}
}
V_60 = F_19 ( & V_32 -> V_2 ) ;
if ( V_60 )
F_13 ( & V_32 -> V_2 ,
L_25 ) ;
return 0 ;
}
static int F_49 ( struct V_98 * V_32 )
{
struct V_15 * V_8 = F_50 ( V_32 ) ;
if ( V_32 -> V_54 ) {
F_32 ( & V_8 -> V_87 ) ;
V_8 -> V_80 &= ~ V_90 ;
F_33 ( & V_8 -> V_87 ) ;
F_51 ( & V_32 -> V_2 , V_32 -> V_54 , V_8 ) ;
}
F_42 ( V_32 , NULL ) ;
F_24 ( & V_32 -> V_2 ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_98 * V_32 = F_53 ( V_2 ) ;
if ( V_32 -> V_54 >= 0 && F_54 ( V_2 ) )
F_55 ( V_32 -> V_54 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_98 * V_32 = F_53 ( V_2 ) ;
if ( V_32 -> V_54 >= 0 && F_54 ( V_2 ) )
F_57 ( V_32 -> V_54 ) ;
return 0 ;
}
