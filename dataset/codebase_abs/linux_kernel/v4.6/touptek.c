static int F_1 ( struct V_1 * V_1 , const char * V_2 , int V_3 )
{
if ( V_3 < 0 ) {
F_2 ( L_1 , V_3 ) ;
return - V_4 ;
}
if ( V_3 != 1 ) {
F_2 ( L_2 , V_3 ) ;
return - V_4 ;
}
if ( V_2 [ 0 ] != 0x08 ) {
F_2 ( L_3 , ( int ) V_2 [ 0 ] ) ;
return - V_4 ;
}
return 0 ;
}
static void F_3 ( struct V_1 * V_1 , T_1 V_5 , T_1 V_6 )
{
char * V_7 = V_1 -> V_8 ;
int V_3 ;
F_4 ( V_9 ,
L_4 ,
V_5 , V_6 ) ;
V_3 = F_5 ( V_1 -> V_10 , F_6 ( V_1 -> V_10 , 0 ) ,
0x0B , 0xC0 , V_5 , V_6 , V_7 , 1 , 500 ) ;
F_4 ( V_9 , L_5 , V_3 , ( int ) V_7 [ 0 ] ) ;
if ( V_3 < 0 ) {
F_2 ( L_6 ,
V_5 , V_6 , V_3 ) ;
V_1 -> V_11 = V_3 ;
return;
}
if ( F_1 ( V_1 , V_7 , V_3 ) ) {
F_2 ( L_7 ,
V_5 , V_6 ) ;
V_1 -> V_11 = - V_4 ;
}
}
static void F_7 ( struct V_1 * V_1 ,
const struct V_12 * V_13 , int V_14 )
{
do {
F_3 ( V_1 , V_13 -> V_5 , V_13 -> V_6 ) ;
V_13 ++ ;
} while ( -- V_14 > 0 );
}
static void F_8 ( struct V_1 * V_1 , T_2 V_15 )
{
T_1 V_5 ;
unsigned int V_16 = V_1 -> V_17 . V_18 ;
if ( V_16 == 800 )
V_5 = V_15 * 5 ;
else if ( V_16 == 1600 )
V_5 = V_15 * 3 ;
else if ( V_16 == 3264 )
V_5 = V_15 * 3 / 2 ;
else {
F_2 ( L_8 , V_16 ) ;
V_1 -> V_11 = - V_19 ;
return;
}
F_4 ( V_20 , L_9 , V_5 ) ;
F_3 ( V_1 , V_5 , V_21 ) ;
F_3 ( V_1 , V_5 , V_21 ) ;
}
static int F_9 ( int V_22 )
{
if ( V_22 <= 0x7F )
return 0x1000 | V_22 ;
else if ( V_22 <= 0xFF )
return 0x1080 | V_22 / 2 ;
else
return 0x1180 | V_22 / 4 ;
}
static void F_10 ( struct V_1 * V_1 , T_1 V_23 )
{
T_1 V_24 ;
V_24 = F_9 ( V_23 ) ;
F_4 ( V_20 , L_10 ,
V_25 ,
V_24 , V_23 ) ;
F_3 ( V_1 , V_24 , V_25 ) ;
F_3 ( V_1 , V_24 , V_26 ) ;
}
static void F_11 ( struct V_1 * V_1 ,
T_1 V_27 , T_1 V_23 )
{
T_1 V_24 ;
V_24 = V_23 +
( ( V_28 ) V_23 ) * V_27 / V_29 ;
if ( V_24 > V_29 ) {
F_4 ( V_20 , L_11 ,
V_29 , V_24 ) ;
V_24 = V_29 ;
}
V_24 = F_9 ( V_24 ) ;
F_4 ( V_20 , L_12 ,
V_30 , V_24 , V_27 ) ;
F_3 ( V_1 , V_24 , V_30 ) ;
}
static void F_12 ( struct V_1 * V_1 ,
T_1 V_27 , T_1 V_23 )
{
T_1 V_24 ;
V_24 = V_23 +
( ( V_28 ) V_23 ) * V_27 / V_29 ;
if ( V_24 > V_29 ) {
F_4 ( V_20 , L_13 ,
V_29 , V_24 ) ;
V_24 = V_29 ;
}
V_24 = F_9 ( V_24 ) ;
F_4 ( V_20 , L_14 ,
V_31 , V_24 , V_27 ) ;
F_3 ( V_1 , V_24 , V_31 ) ;
}
static void F_13 ( struct V_1 * V_1 )
{
unsigned int V_16 = V_1 -> V_17 . V_18 ;
F_4 ( V_20 , L_15 ) ;
if ( V_16 == 800 ) {
static const struct V_12 V_32 [] = {
{ 0x0060 , V_33 } ,
{ 0x0CD9 , V_34 } ,
{ 0x0036 , V_35 } ,
{ 0x098F , V_36 } ,
{ 0x07C7 , V_37 } ,
} ;
F_7 ( V_1 ,
V_32 , F_14 ( V_32 ) ) ;
} else if ( V_16 == 1600 ) {
static const struct V_12 V_32 [] = {
{ 0x009C , V_33 } ,
{ 0x0D19 , V_34 } ,
{ 0x0068 , V_35 } ,
{ 0x09C5 , V_36 } ,
{ 0x06C3 , V_37 } ,
} ;
F_7 ( V_1 ,
V_32 , F_14 ( V_32 ) ) ;
} else if ( V_16 == 3264 ) {
static const struct V_12 V_32 [] = {
{ 0x00E8 , V_33 } ,
{ 0x0DA7 , V_34 } ,
{ 0x009E , V_35 } ,
{ 0x0A2D , V_36 } ,
{ 0x0241 , V_37 } ,
} ;
F_7 ( V_1 ,
V_32 , F_14 ( V_32 ) ) ;
} else {
F_2 ( L_16 , V_16 ) ;
V_1 -> V_11 = - V_19 ;
return;
}
F_3 ( V_1 , 0x0000 , V_38 ) ;
F_3 ( V_1 , 0x0010 , V_39 ) ;
F_3 ( V_1 , V_16 , V_40 ) ;
F_3 ( V_1 , V_1 -> V_17 . V_41 , V_42 ) ;
if ( V_16 == 800 ) {
F_3 ( V_1 , 0x0384 , V_43 ) ;
F_3 ( V_1 , 0x0960 , V_44 ) ;
} else if ( V_16 == 1600 ) {
F_3 ( V_1 , 0x0640 , V_43 ) ;
F_3 ( V_1 , 0x0FA0 , V_44 ) ;
} else if ( V_16 == 3264 ) {
F_3 ( V_1 , 0x0B4B , V_43 ) ;
F_3 ( V_1 , 0x1F40 , V_44 ) ;
} else {
F_2 ( L_16 , V_16 ) ;
V_1 -> V_11 = - V_19 ;
return;
}
}
static void F_15 ( struct V_1 * V_1 )
{
static const struct V_12 V_45 [] = {
{ 0x0100 , V_46 } ,
{ 0x0000 , V_47 } ,
{ 0x0100 , V_48 } ,
{ 0x0004 , V_49 } ,
{ 0x0001 , V_50 } ,
{ 0x0008 , V_51 } ,
{ 0x0001 , V_52 } ,
{ 0x0004 , V_53 } ,
{ 0x0040 , V_54 } ,
{ 0x0000 , V_48 } ,
{ 0x0100 , V_48 } ,
} ;
static const struct V_12 V_55 [] = {
{ 0x0000 , V_48 } ,
{ 0x0301 , 0x31AE } ,
{ 0x0805 , 0x3064 } ,
{ 0x0071 , 0x3170 } ,
{ 0x10DE , V_56 } ,
{ 0x0000 , V_47 } ,
{ 0x0010 , V_54 } ,
{ 0x0100 , V_47 } ,
} ;
F_4 ( V_20 , L_17 , V_1 -> V_17 . V_18 ) ;
F_7 ( V_1 , V_45 , F_14 ( V_45 ) ) ;
F_13 ( V_1 ) ;
F_7 ( V_1 , V_55 , F_14 ( V_55 ) ) ;
F_3 ( V_1 , 0x0100 , V_48 ) ;
F_3 ( V_1 , 0x0000 , V_48 ) ;
F_4 ( V_20 , L_18 ) ;
}
static int F_16 ( struct V_1 * V_1 )
{
int V_3 ;
char * V_7 = V_1 -> V_8 ;
F_4 ( V_20 , L_19 ) ;
V_3 = F_5 ( V_1 -> V_10 , F_6 ( V_1 -> V_10 , 0 ) ,
0x16 , 0xC0 , 0x0000 , 0x0000 , V_7 , 2 , 500 ) ;
if ( F_1 ( V_1 , V_7 , V_3 ) ) {
F_2 ( L_20 ) ;
return - V_4 ;
}
V_3 = F_5 ( V_1 -> V_10 , F_17 ( V_1 -> V_10 , 0 ) ,
0x01 , 0x40 , 0x0001 , 0x000F , NULL , 0 , 500 ) ;
if ( V_3 < 0 ) {
F_2 ( L_21 , V_3 ) ;
return V_3 ;
}
V_3 = F_5 ( V_1 -> V_10 , F_17 ( V_1 -> V_10 , 0 ) ,
0x01 , 0x40 , 0x0000 , 0x000F , NULL , 0 , 500 ) ;
if ( V_3 < 0 ) {
F_2 ( L_22 , V_3 ) ;
return V_3 ;
}
V_3 = F_5 ( V_1 -> V_10 , F_17 ( V_1 -> V_10 , 0 ) ,
0x01 , 0x40 , 0x0001 , 0x000F , NULL , 0 , 500 ) ;
if ( V_3 < 0 ) {
F_2 ( L_23 , V_3 ) ;
return V_3 ;
}
V_1 -> V_11 = 0 ;
F_15 ( V_1 ) ;
if ( V_1 -> V_11 )
return V_1 -> V_11 ;
V_3 = F_5 ( V_1 -> V_10 , F_17 ( V_1 -> V_10 , 0 ) ,
0x01 , 0x40 , 0x0003 , 0x000F , NULL , 0 , 500 ) ;
if ( V_3 < 0 ) {
F_2 ( L_24 , V_3 ) ;
return V_3 ;
}
F_4 ( V_20 , L_25 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_1 ,
const struct V_57 * V_58 )
{
V_1 -> V_59 . V_60 = V_61 ;
V_1 -> V_59 . V_62 = F_14 ( V_61 ) ;
V_1 -> V_59 . V_63 = 0 ;
V_1 -> V_59 . V_64 = 4 ;
V_1 -> V_59 . V_65 = V_66 ;
V_1 -> V_59 . V_67 = 1 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_1 )
{
struct V_68 * V_68 = (struct V_68 * ) V_1 ;
int V_3 ;
V_68 -> V_69 = 0 ;
V_3 = F_16 ( V_1 ) ;
if ( V_3 < 0 ) {
F_2 ( L_26 ) ;
return V_3 ;
}
return 0 ;
}
static void F_20 ( struct V_1 * V_1 ,
T_3 * V_70 ,
int V_71 )
{
struct V_68 * V_68 = (struct V_68 * ) V_1 ;
if ( V_71 != V_66 ) {
if ( V_68 -> V_69 + V_71 == V_1 -> V_17 . V_72 ) {
F_21 ( V_1 , V_73 , V_70 , V_71 ) ;
F_4 ( V_74 , L_27 ,
V_68 -> V_69 , V_1 -> V_17 . V_72 , V_71 ) ;
} else {
F_21 ( V_1 , V_75 , NULL , 0 ) ;
F_4 ( V_74 , L_28 ,
V_68 -> V_69 , V_1 -> V_17 . V_72 , V_71 ) ;
}
V_68 -> V_69 = 0 ;
} else {
if ( V_68 -> V_69 == 0 )
F_21 ( V_1 , V_76 , V_70 , V_71 ) ;
else
F_21 ( V_1 , V_77 , V_70 , V_71 ) ;
V_68 -> V_69 += V_71 ;
}
}
static int F_22 ( struct V_1 * V_1 )
{
return 0 ;
}
static int F_23 ( struct V_78 * V_79 )
{
struct V_1 * V_1 =
F_24 ( V_79 -> V_80 , struct V_1 , V_81 ) ;
struct V_68 * V_68 = (struct V_68 * ) V_1 ;
V_1 -> V_11 = 0 ;
if ( ! V_1 -> V_82 )
return 0 ;
switch ( V_79 -> V_58 ) {
case V_83 :
F_8 ( V_1 , V_79 -> V_15 ) ;
break;
case V_84 :
F_10 ( V_1 , V_1 -> V_27 -> V_15 ) ;
break;
case V_85 :
V_68 -> V_86 -> V_15 = V_79 -> V_15 ;
F_11 ( V_1 , V_68 -> V_86 -> V_15 , V_1 -> V_27 -> V_15 ) ;
break;
case V_87 :
V_68 -> V_88 -> V_15 = V_79 -> V_15 ;
F_12 ( V_1 , V_68 -> V_88 -> V_15 , V_1 -> V_27 -> V_15 ) ;
break;
}
return V_1 -> V_11 ;
}
static int F_25 ( struct V_1 * V_1 )
{
struct V_68 * V_68 = (struct V_68 * ) V_1 ;
struct V_89 * V_90 = & V_1 -> V_81 ;
V_1 -> V_91 . V_81 = V_90 ;
F_26 ( V_90 , 4 ) ;
V_1 -> V_92 = F_27 ( V_90 , & V_93 ,
V_83 , 0 , 800 , 1 , 350 ) ;
V_1 -> V_27 = F_27 ( V_90 , & V_93 ,
V_84 , 0 , 511 , 1 , 128 ) ;
V_68 -> V_86 = F_27 ( V_90 , & V_93 ,
V_85 , 0 , 1023 , 1 , 80 ) ;
V_68 -> V_88 = F_27 ( V_90 , & V_93 ,
V_87 , 0 , 1023 , 1 , 295 ) ;
if ( V_90 -> error ) {
F_2 ( L_29 ) ;
return V_90 -> error ;
}
return 0 ;
}
static int F_28 ( struct V_94 * V_95 ,
const struct V_57 * V_58 )
{
return F_29 ( V_95 , V_58 , & V_96 , sizeof( struct V_68 ) ,
V_97 ) ;
}
static int T_4 F_30 ( void )
{
int V_98 ;
V_98 = F_31 ( & V_99 ) ;
if ( V_98 < 0 )
return V_98 ;
return 0 ;
}
static void T_5 F_32 ( void )
{
F_33 ( & V_99 ) ;
}
