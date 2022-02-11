static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 ,
unsigned int V_4 )
{
int div = V_3 / V_4 / 2 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_6 ) ; V_5 ++ ) {
const struct V_7 * V_8 = & V_6 [ V_5 ] ;
if ( V_8 -> div == div )
return V_8 -> V_9 ;
}
return - V_10 ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned int V_3 ,
unsigned int V_11 ,
unsigned int V_12 )
{
int div = V_11 / V_12 / V_3 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_13 ) ; V_5 ++ ) {
const struct V_7 * V_14 = & V_13 [ V_5 ] ;
if ( V_14 -> div == div )
return V_14 -> V_9 ;
}
return - V_10 ;
}
static bool F_4 ( unsigned int V_15 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_16 ) ; V_5 ++ )
if ( V_16 [ V_5 ] == V_15 )
return true ;
return false ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned int V_17 ,
unsigned int V_4 )
{
unsigned int V_3 , V_18 ;
int V_19 , V_20 ;
int V_21 ;
switch ( V_17 ) {
case 176400 :
case 88200 :
case 44100 :
case 22050 :
case 11025 :
V_18 = 22579200 ;
break;
case 192000 :
case 128000 :
case 96000 :
case 64000 :
case 48000 :
case 32000 :
case 24000 :
case 16000 :
case 12000 :
case 8000 :
V_18 = 24576000 ;
break;
default:
return - V_10 ;
}
V_21 = F_6 ( V_2 -> V_22 , V_18 ) ;
if ( V_21 )
return V_21 ;
V_3 = V_2 -> V_23 / V_17 ;
if ( ! F_4 ( V_3 ) )
return - V_10 ;
V_19 = F_1 ( V_2 , V_3 ,
V_4 ) ;
if ( V_19 < 0 )
return - V_10 ;
V_20 = F_3 ( V_2 , V_3 ,
V_18 , V_17 ) ;
if ( V_20 < 0 )
return - V_10 ;
F_7 ( V_2 -> V_24 , V_25 ,
F_8 ( V_19 ) |
F_9 ( V_20 ) |
V_26 ) ;
return 0 ;
}
static int F_10 ( struct V_27 * V_28 ,
struct V_29 * V_30 ,
struct V_31 * V_32 )
{
struct V_1 * V_2 = F_11 ( V_32 ) ;
int V_33 , V_34 ;
T_1 V_35 ;
if ( F_12 ( V_30 ) != 2 )
return - V_10 ;
switch ( F_13 ( V_30 ) ) {
case 16 :
V_35 = V_36 ;
break;
default:
return - V_10 ;
}
V_2 -> V_37 . V_38 = V_35 ;
switch ( F_14 ( V_30 ) ) {
case 16 :
V_33 = 0 ;
V_34 = 0 ;
break;
default:
return - V_10 ;
}
F_15 ( V_2 -> V_24 , V_39 ,
V_40 | V_41 ,
F_16 ( V_34 ) | F_17 ( V_33 ) ) ;
return F_5 ( V_2 , F_18 ( V_30 ) ,
F_14 ( V_30 ) ) ;
}
static int F_19 ( struct V_31 * V_32 , unsigned int V_42 )
{
struct V_1 * V_2 = F_11 ( V_32 ) ;
T_1 V_9 ;
switch ( V_42 & V_43 ) {
case V_44 :
V_9 = V_45 ;
break;
case V_46 :
V_9 = V_47 ;
break;
case V_48 :
V_9 = V_49 ;
break;
default:
return - V_10 ;
}
F_15 ( V_2 -> V_24 , V_39 ,
V_50 ,
V_9 ) ;
switch ( V_42 & V_51 ) {
case V_52 :
V_9 = V_53 |
V_54 ;
break;
case V_55 :
V_9 = V_53 |
V_56 ;
break;
case V_57 :
V_9 = V_54 |
V_58 ;
break;
case V_59 :
V_9 = V_58 |
V_56 ;
break;
default:
return - V_10 ;
}
F_15 ( V_2 -> V_24 , V_39 ,
V_60 |
V_61 ,
V_9 ) ;
switch ( V_42 & V_62 ) {
case V_63 :
V_9 = V_64 ;
break;
case V_65 :
V_9 = V_66 ;
break;
default:
return - V_10 ;
}
F_15 ( V_2 -> V_24 , V_67 ,
V_68 ,
V_9 ) ;
F_15 ( V_2 -> V_24 , V_69 ,
V_70 |
V_71 ,
F_20 ( 1 ) |
F_21 ( 1 ) ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_15 ( V_2 -> V_24 , V_69 ,
V_72 ,
V_72 ) ;
F_7 ( V_2 -> V_24 , V_73 , 0 ) ;
F_15 ( V_2 -> V_24 , V_67 ,
V_74 ,
V_74 ) ;
F_15 ( V_2 -> V_24 , V_75 ,
V_76 ,
V_76 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
F_15 ( V_2 -> V_24 , V_69 ,
V_77 ,
V_77 ) ;
F_7 ( V_2 -> V_24 , V_78 , 0 ) ;
F_15 ( V_2 -> V_24 , V_67 ,
V_79 ,
V_79 ) ;
F_15 ( V_2 -> V_24 , V_75 ,
V_80 ,
V_80 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_15 ( V_2 -> V_24 , V_67 ,
V_74 ,
0 ) ;
F_15 ( V_2 -> V_24 , V_75 ,
V_76 ,
0 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
F_15 ( V_2 -> V_24 , V_67 ,
V_79 ,
0 ) ;
F_15 ( V_2 -> V_24 , V_75 ,
V_80 ,
0 ) ;
}
static int F_26 ( struct V_27 * V_28 , int V_81 ,
struct V_31 * V_32 )
{
struct V_1 * V_2 = F_11 ( V_32 ) ;
switch ( V_81 ) {
case V_82 :
case V_83 :
case V_84 :
if ( V_28 -> V_85 == V_86 )
F_23 ( V_2 ) ;
else
F_22 ( V_2 ) ;
break;
case V_87 :
case V_88 :
case V_89 :
if ( V_28 -> V_85 == V_86 )
F_25 ( V_2 ) ;
else
F_24 ( V_2 ) ;
break;
default:
return - V_10 ;
}
return 0 ;
}
static int F_27 ( struct V_27 * V_28 ,
struct V_31 * V_32 )
{
struct V_1 * V_2 = F_11 ( V_32 ) ;
F_7 ( V_2 -> V_24 , V_67 ,
V_90 ) ;
F_15 ( V_2 -> V_24 , V_67 ,
V_91 ,
F_28 ( 0 ) ) ;
F_7 ( V_2 -> V_24 , V_92 ,
F_29 ( 2 ) ) ;
F_7 ( V_2 -> V_24 , V_93 ,
F_30 ( 0 , 0 ) | F_30 ( 1 , 1 ) ) ;
return F_31 ( V_2 -> V_22 ) ;
}
static void F_32 ( struct V_27 * V_28 ,
struct V_31 * V_32 )
{
struct V_1 * V_2 = F_11 ( V_32 ) ;
F_33 ( V_2 -> V_22 ) ;
F_15 ( V_2 -> V_24 , V_67 ,
V_91 , 0 ) ;
F_7 ( V_2 -> V_24 , V_67 , 0 ) ;
}
static int F_34 ( struct V_31 * V_32 , int V_94 ,
unsigned int V_95 , int V_96 )
{
struct V_1 * V_2 = F_11 ( V_32 ) ;
if ( V_94 != 0 )
return - V_10 ;
V_2 -> V_23 = V_95 ;
return 0 ;
}
static int F_35 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_11 ( V_32 ) ;
F_36 ( V_32 ,
& V_2 -> V_37 ,
& V_2 -> V_97 ) ;
F_37 ( V_32 , V_2 ) ;
return 0 ;
}
static bool F_38 ( struct V_98 * V_99 , unsigned int V_100 )
{
switch ( V_100 ) {
case V_101 :
return false ;
default:
return true ;
}
}
static bool F_39 ( struct V_98 * V_99 , unsigned int V_100 )
{
switch ( V_100 ) {
case V_102 :
case V_103 :
return false ;
default:
return true ;
}
}
static bool F_40 ( struct V_98 * V_99 , unsigned int V_100 )
{
switch ( V_100 ) {
case V_102 :
case V_104 :
case V_73 :
case V_78 :
return true ;
default:
return false ;
}
}
static int F_41 ( struct V_98 * V_99 )
{
struct V_1 * V_2 = F_42 ( V_99 ) ;
int V_21 ;
V_21 = F_31 ( V_2 -> V_105 ) ;
if ( V_21 ) {
F_43 ( V_99 , L_1 ) ;
return V_21 ;
}
F_44 ( V_2 -> V_24 , false ) ;
F_45 ( V_2 -> V_24 ) ;
V_21 = F_46 ( V_2 -> V_24 ) ;
if ( V_21 ) {
F_43 ( V_99 , L_2 ) ;
goto V_106;
}
return 0 ;
V_106:
F_33 ( V_2 -> V_105 ) ;
return V_21 ;
}
static int F_47 ( struct V_98 * V_99 )
{
struct V_1 * V_2 = F_42 ( V_99 ) ;
F_44 ( V_2 -> V_24 , true ) ;
F_33 ( V_2 -> V_105 ) ;
return 0 ;
}
static int F_48 ( struct V_107 * V_108 )
{
struct V_1 * V_2 ;
struct V_109 * V_110 ;
void T_2 * V_111 ;
int V_112 , V_21 ;
V_2 = F_49 ( & V_108 -> V_99 , sizeof( * V_2 ) , V_113 ) ;
if ( ! V_2 )
return - V_114 ;
F_50 ( V_108 , V_2 ) ;
V_110 = F_51 ( V_108 , V_115 , 0 ) ;
V_111 = F_52 ( & V_108 -> V_99 , V_110 ) ;
if ( F_53 ( V_111 ) )
return F_54 ( V_111 ) ;
V_112 = F_55 ( V_108 , 0 ) ;
if ( V_112 < 0 ) {
F_43 ( & V_108 -> V_99 , L_3 ) ;
return V_112 ;
}
V_2 -> V_105 = F_56 ( & V_108 -> V_99 , L_4 ) ;
if ( F_53 ( V_2 -> V_105 ) ) {
F_43 ( & V_108 -> V_99 , L_5 ) ;
return F_54 ( V_2 -> V_105 ) ;
}
V_2 -> V_24 = F_57 ( & V_108 -> V_99 , V_111 ,
& V_116 ) ;
if ( F_53 ( V_2 -> V_24 ) ) {
F_43 ( & V_108 -> V_99 , L_6 ) ;
return F_54 ( V_2 -> V_24 ) ;
}
V_2 -> V_22 = F_56 ( & V_108 -> V_99 , L_7 ) ;
if ( F_53 ( V_2 -> V_22 ) ) {
F_43 ( & V_108 -> V_99 , L_8 ) ;
return F_54 ( V_2 -> V_22 ) ;
}
V_2 -> V_37 . V_117 = V_110 -> V_118 + V_101 ;
V_2 -> V_37 . V_119 = 4 ;
V_2 -> V_97 . V_117 = V_110 -> V_118 + V_102 ;
V_2 -> V_97 . V_119 = 4 ;
F_58 ( & V_108 -> V_99 ) ;
if ( ! F_59 ( & V_108 -> V_99 ) ) {
V_21 = F_41 ( & V_108 -> V_99 ) ;
if ( V_21 )
goto V_120;
}
V_21 = F_60 ( & V_108 -> V_99 ,
& V_121 ,
& V_122 , 1 ) ;
if ( V_21 ) {
F_43 ( & V_108 -> V_99 , L_9 ) ;
goto V_123;
}
V_21 = F_61 ( & V_108 -> V_99 , NULL , 0 ) ;
if ( V_21 ) {
F_43 ( & V_108 -> V_99 , L_10 ) ;
goto V_123;
}
return 0 ;
V_123:
if ( ! F_62 ( & V_108 -> V_99 ) )
F_47 ( & V_108 -> V_99 ) ;
V_120:
F_63 ( & V_108 -> V_99 ) ;
return V_21 ;
}
static int F_64 ( struct V_107 * V_108 )
{
F_65 ( & V_108 -> V_99 ) ;
F_63 ( & V_108 -> V_99 ) ;
if ( ! F_62 ( & V_108 -> V_99 ) )
F_47 ( & V_108 -> V_99 ) ;
return 0 ;
}
