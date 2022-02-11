static int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 < V_2 -> V_4 ) {
F_2 ( & V_2 -> V_5 -> V_6 , L_1 ) ;
return - V_7 ;
}
return 0 ;
}
static int F_3 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_10 * V_11 ;
V_11 = F_4 ( sizeof( struct V_10 ) , V_12 ) ;
if ( ! V_11 )
return - V_13 ;
V_11 -> V_14 = 0 ;
V_11 -> V_15 = 0 ;
V_11 -> V_16 = F_5 ( V_2 -> V_6 -> V_17 . V_18 ) ;
switch ( V_11 -> V_16 ) {
case V_19 :
F_6 ( & V_2 -> V_6 -> V_6 , L_2 ) ;
break;
case V_20 :
F_6 ( & V_2 -> V_6 -> V_6 , L_3 ) ;
break;
case V_21 :
F_6 ( & V_2 -> V_6 -> V_6 , L_4 ) ;
break;
case V_22 :
F_6 ( & V_2 -> V_6 -> V_6 , L_5 ) ;
break;
}
F_7 ( V_9 , V_11 ) ;
return 0 ;
}
static int F_8 ( struct V_8 * V_9 )
{
struct V_10 * V_11 ;
V_11 = F_9 ( V_9 ) ;
F_10 ( V_11 ) ;
return 0 ;
}
static void F_11 ( struct V_23 * V_24 )
{
V_24 -> V_25 . V_26 = 0 ;
V_24 -> V_25 . V_27 &= ~ ( V_28 | V_29 | V_30 | V_31 | V_32 ) ;
V_24 -> V_25 . V_27 |= V_33 | V_34 | V_35 ;
V_24 -> V_25 . V_36 &= ~ V_37 ;
}
static int F_12 ( struct V_23 * V_24 , struct V_8 * V_9 )
{
struct V_38 * V_6 = & V_9 -> V_6 ;
int V_39 = 0 ;
struct V_10 * V_11 ;
unsigned char * V_40 ;
int V_41 = 8 ;
V_11 = F_9 ( V_9 ) ;
V_40 = F_13 ( V_41 , V_12 ) ;
if ( ! V_40 )
return - V_13 ;
V_39 = F_14 ( V_9 -> V_2 -> V_6 ,
F_15 ( V_9 -> V_2 -> V_6 , 0 ) ,
V_42 ,
V_43 | V_44 | V_45 ,
V_46 ,
0 ,
V_40 ,
V_41 ,
V_47
) ;
F_6 ( V_6 , L_6 , V_48 , V_39 ) ;
F_6 ( V_6 , L_7 , V_40 [ 0 ] ,
V_40 [ 1 ] , V_40 [ 2 ] ) ;
V_39 = F_14 ( V_9 -> V_2 -> V_6 ,
F_15 ( V_9 -> V_2 -> V_6 , 0 ) ,
V_42 ,
V_43 | V_44 | V_45 ,
V_49 ,
0 ,
V_40 ,
V_41 ,
V_47
) ;
F_6 ( V_6 , L_8 , V_48 , V_39 ) ;
F_6 ( V_6 , L_9 , V_40 [ 0 ] ,
V_40 [ 1 ] , V_40 [ 2 ] ) ;
if ( V_11 -> V_16 == V_19 ||
V_11 -> V_16 == V_20 ) {
V_39 = F_14 ( V_9 -> V_2 -> V_6 ,
F_16 ( V_9 -> V_2 -> V_6 , 0 ) ,
V_50 ,
V_43 | V_44 | V_51 ,
V_52 | V_53 |
V_54 ,
0 ,
NULL ,
0 ,
V_47
) ;
F_6 ( V_6 , L_10 , V_48 , V_39 ) ;
V_39 = F_14 ( V_9 -> V_2 -> V_6 ,
F_16 ( V_9 -> V_2 -> V_6 , 0 ) ,
V_55 ,
V_43 | V_44 | V_51 ,
V_56 ,
0 ,
NULL ,
0 ,
V_47
) ;
F_6 ( V_6 , L_11 , V_48 , V_39 ) ;
}
if ( V_11 -> V_16 == V_21 ||
V_11 -> V_16 == V_19 ||
V_11 -> V_16 == V_22 ) {
V_39 = F_17 ( V_9 -> V_57 , V_12 ) ;
F_6 ( V_6 , L_12 , V_48 , V_39 ) ;
}
F_10 ( V_40 ) ;
return 0 ;
}
static void F_18 ( struct V_8 * V_9 )
{
F_19 ( V_9 -> V_58 ) ;
F_19 ( V_9 -> V_57 ) ;
}
static void F_20 ( struct V_59 * V_59 )
{
int V_39 ;
struct V_8 * V_9 = V_59 -> V_60 ;
unsigned char * V_61 = V_59 -> V_40 ;
int V_62 = V_59 -> V_62 ;
if ( V_62 ) {
F_6 ( & V_9 -> V_6 , L_13 , V_48 , V_62 ) ;
return;
}
if ( V_59 -> V_63 ) {
F_21 ( & V_9 -> V_6 , V_48 , V_59 -> V_63 ,
V_61 ) ;
F_22 ( & V_9 -> V_9 , V_61 , V_59 -> V_63 ) ;
F_23 ( & V_9 -> V_9 ) ;
}
V_39 = F_17 ( V_9 -> V_57 , V_64 ) ;
F_6 ( & V_9 -> V_6 , L_12 , V_48 , V_39 ) ;
}
static void F_24 ( struct V_59 * V_59 )
{
}
static int F_25 ( struct V_23 * V_24 , struct V_8 * V_9 ,
const unsigned char * V_65 , int V_66 )
{
int V_67 = 0 ;
int V_39 = 0 ;
int V_68 = 0 ;
struct V_10 * V_11 ;
if ( V_66 == 0 ) {
F_6 ( & V_9 -> V_6 , L_14 , V_48 ) ;
return 0 ;
}
V_11 = F_9 ( V_9 ) ;
if ( V_66 > ( V_69 - V_11 -> V_14 ) ) {
F_6 ( & V_9 -> V_6 , L_15 , V_48 ) ;
return - V_13 ;
}
memcpy ( V_11 -> V_65 + V_11 -> V_14 , V_65 , V_66 ) ;
F_21 ( & V_9 -> V_6 , V_48 , V_66 , V_11 -> V_65 + V_11 -> V_14 ) ;
V_11 -> V_14 = V_11 -> V_14 + V_66 ;
if ( ( ( V_11 -> V_16 != V_19 ) && ( V_11 -> V_14 > 2 ) && ( V_11 -> V_14 >= ( V_11 -> V_65 [ 1 ] + 3 ) ) ) ||
( ( V_11 -> V_16 == V_19 ) && ( V_11 -> V_14 > 3 ) && ( V_11 -> V_14 >= ( V_11 -> V_65 [ 2 ] + 4 ) ) ) ) {
if ( ( V_11 -> V_16 == V_19 )
|| ( V_11 -> V_16 == V_20 ) )
F_19 ( V_9 -> V_57 ) ;
V_68 = V_11 -> V_14 - V_11 -> V_15 ;
while ( V_68 > 0 ) {
V_67 = F_26 ( V_68 , V_9 -> V_70 ) ;
memcpy ( V_9 -> V_71 ,
V_11 -> V_65 + V_11 -> V_15 , V_67 ) ;
V_9 -> V_58 -> V_41 = V_67 ;
V_11 -> V_15 = V_11 -> V_15 + V_67 ;
V_39 = F_17 ( V_9 -> V_58 ,
V_64 ) ;
F_6 ( & V_9 -> V_6 , L_16 , V_48 , V_39 ) ;
V_68 = V_11 -> V_14 - V_11 -> V_15 ;
if ( V_68 > 0 )
F_27 ( 24 ) ;
}
V_11 -> V_14 = 0 ;
V_11 -> V_15 = 0 ;
if ( V_11 -> V_16 == V_19 ||
V_11 -> V_16 == V_20 ) {
V_39 = F_17 ( V_9 -> V_57 ,
V_64 ) ;
F_6 ( & V_9 -> V_6 , L_12 , V_48 , V_39 ) ;
}
}
return V_66 ;
}
static int F_28 ( struct V_23 * V_24 )
{
return 8 ;
}
static int F_29 ( struct V_23 * V_24 )
{
struct V_8 * V_9 = V_24 -> V_72 ;
struct V_10 * V_11 ;
int V_39 ;
unsigned char * V_40 ;
int V_41 = 8 ;
V_11 = F_9 ( V_9 ) ;
if ( V_11 -> V_16 == V_21
|| V_11 -> V_16 == V_22 ) {
return - V_73 ;
}
V_40 = F_13 ( V_41 , V_12 ) ;
if ( ! V_40 )
return - V_13 ;
V_39 = F_14 ( V_9 -> V_2 -> V_6 ,
F_15 ( V_9 -> V_2 -> V_6 , 0 ) ,
V_74 ,
V_43 | V_44 | V_45 ,
0 ,
0 ,
V_40 ,
V_41 ,
V_47 ) ;
F_6 ( & V_9 -> V_6 , L_17 ,
V_48 , V_39 , V_40 [ 0 ] ) ;
V_39 = 0 ;
if ( ( V_40 [ 0 ] & V_75 ) != 0 )
V_39 = V_76 ;
F_10 ( V_40 ) ;
return V_39 ;
}
static int F_30 ( struct V_23 * V_24 ,
unsigned int V_77 , unsigned int V_78 )
{
struct V_8 * V_9 = V_24 -> V_72 ;
struct V_38 * V_6 = & V_9 -> V_6 ;
struct V_10 * V_11 ;
int V_39 ;
int V_79 = 0 ;
int V_80 = 0 ;
V_11 = F_9 ( V_9 ) ;
if ( V_11 -> V_16 == V_21
|| V_11 -> V_16 == V_22 ) {
return - V_73 ;
}
if ( V_77 & V_81 )
V_80 = 1 ;
if ( V_77 & V_82 )
V_79 = 1 ;
if ( V_78 & V_81 )
V_80 = 0 ;
if ( V_78 & V_82 )
V_79 = 0 ;
if ( V_11 -> V_16 == V_19 ) {
if ( V_79 != 0 )
F_6 ( V_6 , L_18 , V_48 ) ;
else
F_6 ( V_6 , L_19 , V_48 ) ;
V_39 = F_14 ( V_9 -> V_2 -> V_6 ,
F_16 ( V_9 -> V_2 -> V_6 , 0 ) ,
V_83 ,
V_43 | V_44 | V_51 ,
( ( V_79 != 0 ) ? V_84 : V_85 ) ,
0 ,
NULL ,
0 ,
V_47 ) ;
} else {
if ( V_80 != 0 )
F_6 ( V_6 , L_20 , V_48 ) ;
else
F_6 ( V_6 , L_21 , V_48 ) ;
V_39 = F_14 ( V_9 -> V_2 -> V_6 ,
F_16 ( V_9 -> V_2 -> V_6 , 0 ) ,
V_83 ,
V_43 | V_44 | V_51 ,
( ( V_80 != 0 ) ? V_86 : V_87 ) ,
0 ,
NULL ,
0 ,
V_47 ) ;
}
F_6 ( V_6 , L_22 , V_48 , V_39 ) ;
return ( V_39 < 0 ) ? V_39 : 0 ;
}
static void F_31 ( struct V_23 * V_24 ,
struct V_8 * V_9 , struct V_88 * V_89 )
{
struct V_10 * V_11 ;
int V_39 ;
unsigned short V_90 = 0 ;
int V_91 = V_24 -> V_25 . V_91 ;
T_1 V_92 ;
V_11 = F_9 ( V_9 ) ;
if ( V_11 -> V_16 == V_21 ||
V_11 -> V_16 == V_22 ) {
F_32 ( & V_24 -> V_25 , V_89 ) ;
return;
}
V_92 = F_33 ( V_24 ) ;
switch ( V_92 ) {
case 1200 :
V_90 = V_93 ;
break;
default:
V_92 = 9600 ;
case 9600 :
V_90 = V_52 ;
break;
}
V_90 |= ( V_91 & V_94 ) ? V_95 :
V_54 ;
if ( V_91 & V_96 ) {
if ( V_91 & V_97 )
V_90 |= V_98 ;
else
V_90 |= V_53 ;
} else
V_90 |= V_99 ;
V_24 -> V_25 . V_91 &= ~ V_100 ;
F_34 ( V_24 , V_92 , V_92 ) ;
V_39 = F_14 ( V_9 -> V_2 -> V_6 ,
F_16 ( V_9 -> V_2 -> V_6 , 0 ) ,
V_50 ,
V_43 | V_44 | V_51 ,
V_90 ,
0 ,
NULL ,
0 ,
V_47
) ;
}
static int F_35 ( struct V_23 * V_24 ,
unsigned int V_101 , unsigned long V_102 )
{
struct V_8 * V_9 = V_24 -> V_72 ;
struct V_10 * V_11 = F_9 ( V_9 ) ;
int V_39 ;
if ( V_11 -> V_16 == V_21 ||
V_11 -> V_16 == V_22 )
return - V_103 ;
switch ( V_101 ) {
case V_104 :
V_39 = F_14 ( V_9 -> V_2 -> V_6 ,
F_16 ( V_9 -> V_2 -> V_6 , 0 ) ,
V_55 ,
V_43 | V_44 | V_51 ,
V_56 ,
0 ,
NULL ,
0 ,
V_47
) ;
F_6 ( & V_9 -> V_6 ,
L_23 ,
V_48 , V_39 ) ;
return ( V_39 < 0 ) ? - V_105 : 0 ;
default:
return - V_103 ;
}
}
