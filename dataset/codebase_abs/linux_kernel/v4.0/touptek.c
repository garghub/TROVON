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
F_2 ( L_3 , V_2 [ 0 ] ) ;
return - V_4 ;
}
return 0 ;
}
static void F_3 ( struct V_1 * V_1 , T_1 V_5 , T_1 V_6 )
{
char V_7 [ 1 ] ;
int V_3 ;
F_4 ( V_8 ,
L_4 ,
V_5 , V_6 ) ;
V_3 = F_5 ( V_1 -> V_9 , F_6 ( V_1 -> V_9 , 0 ) ,
0x0B , 0xC0 , V_5 , V_6 , V_7 , 1 , 500 ) ;
F_4 ( V_8 , L_5 , V_3 , V_7 [ 0 ] ) ;
if ( V_3 < 0 ) {
F_2 ( L_6 ,
V_5 , V_6 , V_3 ) ;
V_1 -> V_10 = V_3 ;
return;
}
if ( F_1 ( V_1 , V_7 , V_3 ) ) {
F_2 ( L_7 ,
V_5 , V_6 ) ;
V_1 -> V_10 = - V_4 ;
}
}
static void F_7 ( struct V_1 * V_1 ,
const struct V_11 * V_12 , int V_13 )
{
do {
F_3 ( V_1 , V_12 -> V_5 , V_12 -> V_6 ) ;
V_12 ++ ;
} while ( -- V_13 > 0 );
}
static void F_8 ( struct V_1 * V_1 , T_2 V_14 )
{
T_1 V_5 ;
unsigned int V_15 = V_1 -> V_16 . V_17 ;
if ( V_15 == 800 )
V_5 = V_14 * 5 ;
else if ( V_15 == 1600 )
V_5 = V_14 * 3 ;
else if ( V_15 == 3264 )
V_5 = V_14 * 3 / 2 ;
else {
F_2 ( L_8 , V_15 ) ;
V_1 -> V_10 = - V_18 ;
return;
}
F_4 ( V_19 , L_9 , V_5 ) ;
F_3 ( V_1 , V_5 , V_20 ) ;
F_3 ( V_1 , V_5 , V_20 ) ;
}
static int F_9 ( int V_21 )
{
if ( V_21 <= 0x7F )
return 0x1000 | V_21 ;
else if ( V_21 <= 0xFF )
return 0x1080 | V_21 / 2 ;
else
return 0x1180 | V_21 / 4 ;
}
static void F_10 ( struct V_1 * V_1 , T_1 V_22 )
{
T_1 V_23 ;
V_23 = F_9 ( V_22 ) ;
F_4 ( V_19 , L_10 ,
V_24 ,
V_23 , V_22 ) ;
F_3 ( V_1 , V_23 , V_24 ) ;
F_3 ( V_1 , V_23 , V_25 ) ;
}
static void F_11 ( struct V_1 * V_1 ,
T_1 V_26 , T_1 V_22 )
{
T_1 V_23 ;
V_23 = V_22 +
( ( V_27 ) V_22 ) * V_26 / V_28 ;
if ( V_23 > V_28 ) {
F_4 ( V_19 , L_11 ,
V_28 , V_23 ) ;
V_23 = V_28 ;
}
V_23 = F_9 ( V_23 ) ;
F_4 ( V_19 , L_12 ,
V_29 , V_23 , V_26 ) ;
F_3 ( V_1 , V_23 , V_29 ) ;
}
static void F_12 ( struct V_1 * V_1 ,
T_1 V_26 , T_1 V_22 )
{
T_1 V_23 ;
V_23 = V_22 +
( ( V_27 ) V_22 ) * V_26 / V_28 ;
if ( V_23 > V_28 ) {
F_4 ( V_19 , L_13 ,
V_28 , V_23 ) ;
V_23 = V_28 ;
}
V_23 = F_9 ( V_23 ) ;
F_4 ( V_19 , L_14 ,
V_30 , V_23 , V_26 ) ;
F_3 ( V_1 , V_23 , V_30 ) ;
}
static void F_13 ( struct V_1 * V_1 )
{
unsigned int V_15 = V_1 -> V_16 . V_17 ;
F_4 ( V_19 , L_15 ) ;
if ( V_15 == 800 ) {
static const struct V_11 V_31 [] = {
{ 0x0060 , V_32 } ,
{ 0x0CD9 , V_33 } ,
{ 0x0036 , V_34 } ,
{ 0x098F , V_35 } ,
{ 0x07C7 , V_36 } ,
} ;
F_7 ( V_1 ,
V_31 , F_14 ( V_31 ) ) ;
} else if ( V_15 == 1600 ) {
static const struct V_11 V_31 [] = {
{ 0x009C , V_32 } ,
{ 0x0D19 , V_33 } ,
{ 0x0068 , V_34 } ,
{ 0x09C5 , V_35 } ,
{ 0x06C3 , V_36 } ,
} ;
F_7 ( V_1 ,
V_31 , F_14 ( V_31 ) ) ;
} else if ( V_15 == 3264 ) {
static const struct V_11 V_31 [] = {
{ 0x00E8 , V_32 } ,
{ 0x0DA7 , V_33 } ,
{ 0x009E , V_34 } ,
{ 0x0A2D , V_35 } ,
{ 0x0241 , V_36 } ,
} ;
F_7 ( V_1 ,
V_31 , F_14 ( V_31 ) ) ;
} else {
F_2 ( L_16 , V_15 ) ;
V_1 -> V_10 = - V_18 ;
return;
}
F_3 ( V_1 , 0x0000 , V_37 ) ;
F_3 ( V_1 , 0x0010 , V_38 ) ;
F_3 ( V_1 , V_15 , V_39 ) ;
F_3 ( V_1 , V_1 -> V_16 . V_40 , V_41 ) ;
if ( V_15 == 800 ) {
F_3 ( V_1 , 0x0384 , V_42 ) ;
F_3 ( V_1 , 0x0960 , V_43 ) ;
} else if ( V_15 == 1600 ) {
F_3 ( V_1 , 0x0640 , V_42 ) ;
F_3 ( V_1 , 0x0FA0 , V_43 ) ;
} else if ( V_15 == 3264 ) {
F_3 ( V_1 , 0x0B4B , V_42 ) ;
F_3 ( V_1 , 0x1F40 , V_43 ) ;
} else {
F_2 ( L_16 , V_15 ) ;
V_1 -> V_10 = - V_18 ;
return;
}
}
static void F_15 ( struct V_1 * V_1 )
{
static const struct V_11 V_44 [] = {
{ 0x0100 , V_45 } ,
{ 0x0000 , V_46 } ,
{ 0x0100 , V_47 } ,
{ 0x0004 , V_48 } ,
{ 0x0001 , V_49 } ,
{ 0x0008 , V_50 } ,
{ 0x0001 , V_51 } ,
{ 0x0004 , V_52 } ,
{ 0x0040 , V_53 } ,
{ 0x0000 , V_47 } ,
{ 0x0100 , V_47 } ,
} ;
static const struct V_11 V_54 [] = {
{ 0x0000 , V_47 } ,
{ 0x0301 , 0x31AE } ,
{ 0x0805 , 0x3064 } ,
{ 0x0071 , 0x3170 } ,
{ 0x10DE , V_55 } ,
{ 0x0000 , V_46 } ,
{ 0x0010 , V_53 } ,
{ 0x0100 , V_46 } ,
} ;
F_4 ( V_19 , L_17 , V_1 -> V_16 . V_17 ) ;
F_7 ( V_1 , V_44 , F_14 ( V_44 ) ) ;
F_13 ( V_1 ) ;
F_7 ( V_1 , V_54 , F_14 ( V_54 ) ) ;
F_3 ( V_1 , 0x0100 , V_47 ) ;
F_3 ( V_1 , 0x0000 , V_47 ) ;
F_4 ( V_19 , L_18 ) ;
}
static int F_16 ( struct V_1 * V_1 )
{
int V_3 ;
T_3 V_7 [ 4 ] ;
F_4 ( V_19 , L_19 ) ;
V_3 = F_5 ( V_1 -> V_9 , F_6 ( V_1 -> V_9 , 0 ) ,
0x16 , 0xC0 , 0x0000 , 0x0000 , V_7 , 2 , 500 ) ;
if ( F_1 ( V_1 , V_7 , V_3 ) ) {
F_2 ( L_20 ) ;
return - V_4 ;
}
V_3 = F_5 ( V_1 -> V_9 , F_17 ( V_1 -> V_9 , 0 ) ,
0x01 , 0x40 , 0x0001 , 0x000F , NULL , 0 , 500 ) ;
if ( V_3 < 0 ) {
F_2 ( L_21 , V_3 ) ;
return V_3 ;
}
V_3 = F_5 ( V_1 -> V_9 , F_17 ( V_1 -> V_9 , 0 ) ,
0x01 , 0x40 , 0x0000 , 0x000F , NULL , 0 , 500 ) ;
if ( V_3 < 0 ) {
F_2 ( L_22 , V_3 ) ;
return V_3 ;
}
V_3 = F_5 ( V_1 -> V_9 , F_17 ( V_1 -> V_9 , 0 ) ,
0x01 , 0x40 , 0x0001 , 0x000F , NULL , 0 , 500 ) ;
if ( V_3 < 0 ) {
F_2 ( L_23 , V_3 ) ;
return V_3 ;
}
V_1 -> V_10 = 0 ;
F_15 ( V_1 ) ;
if ( V_1 -> V_10 )
return V_1 -> V_10 ;
V_3 = F_5 ( V_1 -> V_9 , F_17 ( V_1 -> V_9 , 0 ) ,
0x01 , 0x40 , 0x0003 , 0x000F , NULL , 0 , 500 ) ;
if ( V_3 < 0 ) {
F_2 ( L_24 , V_3 ) ;
return V_3 ;
}
F_4 ( V_19 , L_25 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_1 ,
const struct V_56 * V_57 )
{
V_1 -> V_58 . V_59 = V_60 ;
V_1 -> V_58 . V_61 = F_14 ( V_60 ) ;
V_1 -> V_58 . V_62 = 0 ;
V_1 -> V_58 . V_63 = 4 ;
V_1 -> V_58 . V_64 = V_65 ;
V_1 -> V_58 . V_66 = 1 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_1 )
{
struct V_67 * V_67 = (struct V_67 * ) V_1 ;
int V_3 ;
V_67 -> V_68 = 0 ;
V_3 = F_16 ( V_1 ) ;
if ( V_3 < 0 ) {
F_2 ( L_26 ) ;
return V_3 ;
}
return 0 ;
}
static void F_20 ( struct V_1 * V_1 ,
T_4 * V_69 ,
int V_70 )
{
struct V_67 * V_67 = (struct V_67 * ) V_1 ;
if ( V_70 != V_65 ) {
if ( V_67 -> V_68 + V_70 == V_1 -> V_16 . V_71 ) {
F_21 ( V_1 , V_72 , V_69 , V_70 ) ;
F_4 ( V_73 , L_27 ,
V_67 -> V_68 , V_1 -> V_16 . V_71 , V_70 ) ;
} else {
F_21 ( V_1 , V_74 , NULL , 0 ) ;
F_4 ( V_73 , L_28 ,
V_67 -> V_68 , V_1 -> V_16 . V_71 , V_70 ) ;
}
V_67 -> V_68 = 0 ;
} else {
if ( V_67 -> V_68 == 0 )
F_21 ( V_1 , V_75 , V_69 , V_70 ) ;
else
F_21 ( V_1 , V_76 , V_69 , V_70 ) ;
V_67 -> V_68 += V_70 ;
}
}
static int F_22 ( struct V_1 * V_1 )
{
return 0 ;
}
static int F_23 ( struct V_77 * V_78 )
{
struct V_1 * V_1 =
F_24 ( V_78 -> V_79 , struct V_1 , V_80 ) ;
struct V_67 * V_67 = (struct V_67 * ) V_1 ;
V_1 -> V_10 = 0 ;
if ( ! V_1 -> V_81 )
return 0 ;
switch ( V_78 -> V_57 ) {
case V_82 :
F_8 ( V_1 , V_78 -> V_14 ) ;
break;
case V_83 :
F_10 ( V_1 , V_1 -> V_26 -> V_14 ) ;
break;
case V_84 :
V_67 -> V_85 -> V_14 = V_78 -> V_14 ;
F_11 ( V_1 , V_67 -> V_85 -> V_14 , V_1 -> V_26 -> V_14 ) ;
break;
case V_86 :
V_67 -> V_87 -> V_14 = V_78 -> V_14 ;
F_12 ( V_1 , V_67 -> V_87 -> V_14 , V_1 -> V_26 -> V_14 ) ;
break;
}
return V_1 -> V_10 ;
}
static int F_25 ( struct V_1 * V_1 )
{
struct V_67 * V_67 = (struct V_67 * ) V_1 ;
struct V_88 * V_89 = & V_1 -> V_80 ;
V_1 -> V_90 . V_80 = V_89 ;
F_26 ( V_89 , 4 ) ;
V_1 -> V_91 = F_27 ( V_89 , & V_92 ,
V_82 , 0 , 800 , 1 , 350 ) ;
V_1 -> V_26 = F_27 ( V_89 , & V_92 ,
V_83 , 0 , 511 , 1 , 128 ) ;
V_67 -> V_85 = F_27 ( V_89 , & V_92 ,
V_84 , 0 , 1023 , 1 , 80 ) ;
V_67 -> V_87 = F_27 ( V_89 , & V_92 ,
V_86 , 0 , 1023 , 1 , 295 ) ;
if ( V_89 -> error ) {
F_2 ( L_29 ) ;
return V_89 -> error ;
}
return 0 ;
}
static int F_28 ( struct V_93 * V_94 ,
const struct V_56 * V_57 )
{
return F_29 ( V_94 , V_57 , & V_95 , sizeof( struct V_67 ) ,
V_96 ) ;
}
static int T_5 F_30 ( void )
{
int V_97 ;
V_97 = F_31 ( & V_98 ) ;
if ( V_97 < 0 )
return V_97 ;
return 0 ;
}
static void T_6 F_32 ( void )
{
F_33 ( & V_98 ) ;
}
