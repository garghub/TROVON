static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
V_6 = F_2 ( sizeof( struct V_5 ) , V_7 ) ;
if ( ! V_6 )
return - V_8 ;
V_6 -> V_9 = 0 ;
V_6 -> V_10 = 0 ;
V_6 -> V_11 = F_3 ( V_4 -> V_12 -> V_13 . V_14 ) ;
switch ( V_6 -> V_11 ) {
case V_15 :
F_4 ( & V_4 -> V_12 -> V_12 , L_1 ) ;
break;
case V_16 :
F_4 ( & V_4 -> V_12 -> V_12 , L_2 ) ;
break;
case V_17 :
F_4 ( & V_4 -> V_12 -> V_12 , L_3 ) ;
break;
case V_18 :
F_4 ( & V_4 -> V_12 -> V_12 , L_4 ) ;
break;
}
F_5 ( V_2 , V_6 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
V_6 = F_7 ( V_2 ) ;
F_8 ( V_6 ) ;
return 0 ;
}
static void F_9 ( struct V_19 * V_20 )
{
V_20 -> V_21 . V_22 = 0 ;
V_20 -> V_21 . V_23 &= ~ ( V_24 | V_25 | V_26 | V_27 | V_28 ) ;
V_20 -> V_21 . V_23 |= V_29 | V_30 | V_31 ;
V_20 -> V_21 . V_32 &= ~ V_33 ;
}
static int F_10 ( struct V_19 * V_20 , struct V_1 * V_2 )
{
struct V_34 * V_12 = & V_2 -> V_12 ;
int V_35 = 0 ;
struct V_5 * V_6 ;
unsigned char * V_36 ;
int V_37 = 8 ;
V_6 = F_7 ( V_2 ) ;
V_36 = F_11 ( V_37 , V_7 ) ;
if ( ! V_36 )
return - V_8 ;
V_35 = F_12 ( V_2 -> V_4 -> V_12 ,
F_13 ( V_2 -> V_4 -> V_12 , 0 ) ,
V_38 ,
V_39 | V_40 | V_41 ,
V_42 ,
0 ,
V_36 ,
V_37 ,
V_43
) ;
F_4 ( V_12 , L_5 , V_44 , V_35 ) ;
F_4 ( V_12 , L_6 , V_36 [ 0 ] ,
V_36 [ 1 ] , V_36 [ 2 ] ) ;
V_35 = F_12 ( V_2 -> V_4 -> V_12 ,
F_13 ( V_2 -> V_4 -> V_12 , 0 ) ,
V_38 ,
V_39 | V_40 | V_41 ,
V_45 ,
0 ,
V_36 ,
V_37 ,
V_43
) ;
F_4 ( V_12 , L_7 , V_44 , V_35 ) ;
F_4 ( V_12 , L_8 , V_36 [ 0 ] ,
V_36 [ 1 ] , V_36 [ 2 ] ) ;
if ( V_6 -> V_11 == V_15 ||
V_6 -> V_11 == V_16 ) {
V_35 = F_12 ( V_2 -> V_4 -> V_12 ,
F_13 ( V_2 -> V_4 -> V_12 , 0 ) ,
V_46 ,
V_39 | V_40 | V_47 ,
V_48 | V_49 |
V_50 ,
0 ,
V_36 ,
0 ,
V_43
) ;
F_4 ( V_12 , L_9 , V_44 , V_35 ) ;
V_35 = F_12 ( V_2 -> V_4 -> V_12 ,
F_13 ( V_2 -> V_4 -> V_12 , 0 ) ,
V_51 ,
V_39 | V_40 | V_47 ,
V_52 ,
0 ,
V_36 ,
0 ,
V_43
) ;
F_4 ( V_12 , L_10 , V_44 , V_35 ) ;
}
if ( V_6 -> V_11 == V_17 ||
V_6 -> V_11 == V_15 ||
V_6 -> V_11 == V_18 ) {
V_35 = F_14 ( V_2 -> V_53 , V_54 ) ;
F_4 ( V_12 , L_11 , V_44 , V_35 ) ;
}
F_8 ( V_36 ) ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_16 ( V_2 -> V_55 ) ;
F_16 ( V_2 -> V_53 ) ;
}
static void F_17 ( struct V_56 * V_56 )
{
int V_35 ;
struct V_1 * V_2 = V_56 -> V_57 ;
unsigned char * V_58 = V_56 -> V_36 ;
int V_59 = V_56 -> V_59 ;
if ( V_59 ) {
F_4 ( & V_2 -> V_12 , L_12 , V_44 , V_59 ) ;
return;
}
if ( V_56 -> V_60 ) {
F_18 ( & V_2 -> V_12 , V_44 , V_56 -> V_60 ,
V_58 ) ;
F_19 ( & V_2 -> V_2 , V_58 , V_56 -> V_60 ) ;
F_20 ( & V_2 -> V_2 ) ;
}
V_35 = F_14 ( V_2 -> V_53 , V_54 ) ;
F_4 ( & V_2 -> V_12 , L_11 , V_44 , V_35 ) ;
}
static void F_21 ( struct V_56 * V_56 )
{
}
static int F_22 ( struct V_19 * V_20 , struct V_1 * V_2 ,
const unsigned char * V_61 , int V_62 )
{
int V_63 = 0 ;
int V_35 = 0 ;
int V_64 = 0 ;
struct V_5 * V_6 ;
if ( V_62 == 0 ) {
F_4 ( & V_2 -> V_12 , L_13 , V_44 ) ;
return 0 ;
}
V_6 = F_7 ( V_2 ) ;
if ( V_62 > ( V_65 - V_6 -> V_9 ) ) {
F_4 ( & V_2 -> V_12 , L_14 , V_44 ) ;
return - V_8 ;
}
memcpy ( V_6 -> V_61 + V_6 -> V_9 , V_61 , V_62 ) ;
F_18 ( & V_2 -> V_12 , V_44 , V_62 , V_6 -> V_61 + V_6 -> V_9 ) ;
V_6 -> V_9 = V_6 -> V_9 + V_62 ;
if ( ( ( V_6 -> V_11 != V_15 ) && ( V_6 -> V_9 > 2 ) && ( V_6 -> V_9 >= ( V_6 -> V_61 [ 1 ] + 3 ) ) ) ||
( ( V_6 -> V_11 == V_15 ) && ( V_6 -> V_9 > 3 ) && ( V_6 -> V_9 >= ( V_6 -> V_61 [ 2 ] + 4 ) ) ) ) {
if ( ( V_6 -> V_11 == V_15 )
|| ( V_6 -> V_11 == V_16 ) )
F_16 ( V_2 -> V_53 ) ;
V_64 = V_6 -> V_9 - V_6 -> V_10 ;
while ( V_64 > 0 ) {
V_63 = F_23 ( V_64 , V_2 -> V_66 ) ;
memcpy ( V_2 -> V_67 ,
V_6 -> V_61 + V_6 -> V_10 , V_63 ) ;
V_2 -> V_55 -> V_37 = V_63 ;
V_6 -> V_10 = V_6 -> V_10 + V_63 ;
V_35 = F_14 ( V_2 -> V_55 , V_68 ) ;
F_4 ( & V_2 -> V_12 , L_15 , V_44 , V_35 ) ;
V_64 = V_6 -> V_9 - V_6 -> V_10 ;
if ( V_64 > 0 )
F_24 ( 24 ) ;
}
V_6 -> V_9 = 0 ;
V_6 -> V_10 = 0 ;
if ( V_6 -> V_11 == V_15 ||
V_6 -> V_11 == V_16 ) {
V_35 = F_14 ( V_2 -> V_53 ,
V_68 ) ;
F_4 ( & V_2 -> V_12 , L_11 , V_44 , V_35 ) ;
}
}
return V_62 ;
}
static int F_25 ( struct V_19 * V_20 )
{
return 8 ;
}
static int F_26 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_69 ;
struct V_5 * V_6 ;
int V_35 ;
unsigned char * V_36 ;
int V_37 = 8 ;
V_6 = F_7 ( V_2 ) ;
if ( V_6 -> V_11 == V_17
|| V_6 -> V_11 == V_18 ) {
return - V_70 ;
}
V_36 = F_11 ( V_37 , V_7 ) ;
if ( ! V_36 )
return - V_8 ;
V_35 = F_12 ( V_2 -> V_4 -> V_12 ,
F_13 ( V_2 -> V_4 -> V_12 , 0 ) ,
V_71 ,
V_39 | V_40 | V_41 ,
0 ,
0 ,
V_36 ,
V_37 ,
V_43 ) ;
F_4 ( & V_2 -> V_12 , L_16 ,
V_44 , V_35 , V_36 [ 0 ] ) ;
V_35 = 0 ;
if ( ( V_36 [ 0 ] & V_72 ) != 0 )
V_35 = V_73 ;
F_8 ( V_36 ) ;
return V_35 ;
}
static int F_27 ( struct V_19 * V_20 ,
unsigned int V_74 , unsigned int V_75 )
{
struct V_1 * V_2 = V_20 -> V_69 ;
struct V_34 * V_12 = & V_2 -> V_12 ;
struct V_5 * V_6 ;
int V_35 ;
int V_76 = 0 ;
int V_77 = 0 ;
unsigned char * V_36 ;
int V_37 = 8 ;
V_6 = F_7 ( V_2 ) ;
if ( V_6 -> V_11 == V_17
|| V_6 -> V_11 == V_18 ) {
return - V_70 ;
}
V_36 = F_11 ( V_37 , V_7 ) ;
if ( ! V_36 )
return - V_8 ;
if ( V_74 & V_78 )
V_77 = 1 ;
if ( V_74 & V_79 )
V_76 = 1 ;
if ( V_75 & V_78 )
V_77 = 0 ;
if ( V_75 & V_79 )
V_76 = 0 ;
if ( V_6 -> V_11 == V_15 ) {
if ( V_76 != 0 )
F_4 ( V_12 , L_17 , V_44 ) ;
else
F_4 ( V_12 , L_18 , V_44 ) ;
V_35 = F_12 ( V_2 -> V_4 -> V_12 ,
F_13 ( V_2 -> V_4 -> V_12 , 0 ) ,
V_80 ,
V_39 | V_40 | V_47 ,
( ( V_76 != 0 ) ? V_81 : V_82 ) ,
0 ,
V_36 ,
0 ,
V_43 ) ;
} else {
if ( V_77 != 0 )
F_4 ( V_12 , L_19 , V_44 ) ;
else
F_4 ( V_12 , L_20 , V_44 ) ;
V_35 = F_12 ( V_2 -> V_4 -> V_12 ,
F_13 ( V_2 -> V_4 -> V_12 , 0 ) ,
V_80 ,
V_39 | V_40 | V_47 ,
( ( V_77 != 0 ) ? V_83 : V_84 ) ,
0 ,
V_36 ,
0 ,
V_43 ) ;
}
F_4 ( V_12 , L_21 , V_44 , V_35 ) ;
F_8 ( V_36 ) ;
return ( V_35 < 0 ) ? V_35 : 0 ;
}
static void F_28 ( struct V_19 * V_20 ,
struct V_1 * V_2 , struct V_85 * V_86 )
{
struct V_5 * V_6 ;
int V_35 ;
unsigned short V_87 = 0 ;
int V_88 = V_20 -> V_21 . V_88 ;
T_1 V_89 ;
V_6 = F_7 ( V_2 ) ;
if ( V_6 -> V_11 == V_17 ||
V_6 -> V_11 == V_18 ) {
F_29 ( & V_20 -> V_21 , V_86 ) ;
return;
}
V_89 = F_30 ( V_20 ) ;
switch ( V_89 ) {
case 1200 :
V_87 = V_90 ;
break;
default:
V_89 = 9600 ;
case 9600 :
V_87 = V_48 ;
break;
}
V_87 |= ( V_88 & V_91 ) ? V_92 :
V_50 ;
if ( V_88 & V_93 ) {
if ( V_88 & V_94 )
V_87 |= V_95 ;
else
V_87 |= V_49 ;
} else
V_87 |= V_96 ;
V_20 -> V_21 . V_88 &= ~ V_97 ;
F_31 ( V_20 , V_89 , V_89 ) ;
V_35 = F_12 ( V_2 -> V_4 -> V_12 ,
F_13 ( V_2 -> V_4 -> V_12 , 0 ) ,
V_46 ,
V_39 | V_40 | V_47 ,
V_87 ,
0 ,
NULL ,
0 ,
V_43
) ;
}
static int F_32 ( struct V_19 * V_20 ,
unsigned int V_98 , unsigned long V_99 )
{
struct V_1 * V_2 = V_20 -> V_69 ;
struct V_5 * V_6 = F_7 ( V_2 ) ;
unsigned char * V_36 ;
int V_37 = 8 ;
int V_35 ;
if ( V_6 -> V_11 == V_17 ||
V_6 -> V_11 == V_18 )
return - V_100 ;
switch ( V_98 ) {
case V_101 :
V_36 = F_2 ( V_37 , V_7 ) ;
if ( ! V_36 )
return - V_102 ;
V_35 = F_12 ( V_2 -> V_4 -> V_12 ,
F_13 ( V_2 -> V_4 -> V_12 , 0 ) ,
V_51 ,
V_39 | V_40 | V_47 ,
V_52 ,
0 ,
NULL ,
0 ,
V_43
) ;
F_4 ( & V_2 -> V_12 ,
L_22 , V_44 , V_35 ) ;
F_8 ( V_36 ) ;
return ( V_35 < 0 ) ? - V_103 : 0 ;
default:
return - V_100 ;
}
}
