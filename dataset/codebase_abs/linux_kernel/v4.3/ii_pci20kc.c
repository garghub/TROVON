static void T_1 * F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return V_2 -> V_5 + ( V_4 -> V_6 + 1 ) * V_7 ;
}
static int F_2 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_8 * V_9 ,
unsigned int * V_10 )
{
void T_1 * V_11 = F_1 ( V_2 , V_4 ) ;
unsigned int V_12 = F_3 ( V_9 -> V_13 ) ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_9 -> V_15 ; V_14 ++ ) {
unsigned int V_16 = V_10 [ V_14 ] ;
V_4 -> V_17 [ V_12 ] = V_16 ;
V_16 += ( ( V_4 -> V_18 + 1 ) >> 1 ) ;
V_16 &= V_4 -> V_18 ;
F_4 ( V_16 & 0xff , V_11 + F_5 ( V_12 ) ) ;
F_4 ( ( V_16 >> 8 ) & 0xff , V_11 + F_6 ( V_12 ) ) ;
F_4 ( 0x00 , V_11 + F_7 ( V_12 ) ) ;
}
return V_9 -> V_15 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_8 * V_9 ,
unsigned long V_19 )
{
void T_1 * V_11 = F_1 ( V_2 , V_4 ) ;
unsigned char V_20 ;
V_20 = F_9 ( V_11 + V_21 ) ;
if ( ( V_20 & V_22 ) == 0 )
return 0 ;
return - V_23 ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_13 )
{
void T_1 * V_11 = F_1 ( V_2 , V_4 ) ;
unsigned int V_12 = F_3 ( V_13 ) ;
unsigned int V_24 = F_11 ( V_13 ) ;
unsigned char V_16 ;
F_4 ( V_25 , V_11 + V_26 ) ;
F_4 ( 0 , V_11 + V_27 ) ;
V_16 = ( V_24 < 3 ) ? F_12 ( 0 ) : F_12 ( 2 ) ;
F_4 ( V_16 , V_11 + V_28 ) ;
V_16 = ( V_24 < 2 ) ? 0x58 : ( V_24 < 3 ) ? 0x93 : 0x99 ;
F_4 ( V_16 , V_11 + V_29 ) ;
F_4 ( 1 , V_11 + V_30 ) ;
V_16 = V_31 |
V_32 |
F_13 ( V_24 ) |
F_14 ( V_12 ) ;
F_4 ( V_16 , V_11 + V_33 ) ;
F_4 ( 0 , V_11 + V_34 ) ;
F_4 ( 0 , V_11 + V_35 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_8 * V_9 ,
unsigned int * V_10 )
{
void T_1 * V_11 = F_1 ( V_2 , V_4 ) ;
int V_36 ;
int V_14 ;
F_10 ( V_2 , V_4 , V_9 -> V_13 ) ;
for ( V_14 = 0 ; V_14 < V_9 -> V_15 ; V_14 ++ ) {
unsigned int V_16 ;
F_9 ( V_11 + V_37 ) ;
V_36 = F_16 ( V_2 , V_4 , V_9 , F_8 , 0 ) ;
if ( V_36 )
return V_36 ;
V_16 = F_9 ( V_11 + V_38 ) ;
V_16 |= ( F_9 ( V_11 + V_39 ) << 8 ) ;
V_16 += ( ( V_4 -> V_18 + 1 ) >> 1 ) ;
V_16 &= V_4 -> V_18 ;
V_10 [ V_14 ] = V_16 ;
}
return V_9 -> V_15 ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned char V_40 = 0 ;
unsigned char V_41 = 0 ;
unsigned char V_42 = 0 ;
if ( V_4 -> V_43 & 0x000000ff ) {
V_40 &= ~ V_44 ;
V_42 &= ~ V_45 ;
V_42 |= V_46 ;
} else {
V_40 |= V_44 ;
V_42 &= ~ V_46 ;
}
if ( V_4 -> V_43 & 0x0000ff00 ) {
V_40 &= ~ V_47 ;
V_42 &= ~ V_48 ;
V_42 |= V_49 ;
} else {
V_40 |= V_47 ;
V_42 &= ~ V_49 ;
}
if ( V_4 -> V_43 & 0x00ff0000 ) {
V_41 &= ~ V_50 ;
V_42 &= ~ V_51 ;
V_42 |= V_52 ;
} else {
V_41 |= V_50 ;
V_42 &= ~ V_52 ;
}
if ( V_4 -> V_43 & 0xff000000 ) {
V_41 &= ~ V_53 ;
V_42 &= ~ V_54 ;
V_42 |= V_55 ;
} else {
V_41 |= V_53 ;
V_42 &= ~ V_55 ;
}
V_41 |= V_56 ;
V_41 |= V_57 ;
F_4 ( V_40 , V_2 -> V_5 + V_58 ) ;
F_4 ( V_41 , V_2 -> V_5 + V_59 ) ;
F_4 ( V_42 , V_2 -> V_5 + V_60 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_8 * V_9 ,
unsigned int * V_10 )
{
unsigned int V_12 = F_3 ( V_9 -> V_13 ) ;
unsigned int V_61 ;
int V_36 ;
if ( V_12 < 8 )
V_61 = 0x000000ff ;
else if ( V_12 < 16 )
V_61 = 0x0000ff00 ;
else if ( V_12 < 24 )
V_61 = 0x00ff0000 ;
else
V_61 = 0xff000000 ;
V_36 = F_19 ( V_2 , V_4 , V_9 , V_10 , V_61 ) ;
if ( V_36 )
return V_36 ;
F_17 ( V_2 , V_4 ) ;
return V_9 -> V_15 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_8 * V_9 ,
unsigned int * V_10 )
{
unsigned int V_61 ;
V_61 = F_21 ( V_4 , V_10 ) ;
if ( V_61 ) {
if ( V_61 & 0x000000ff )
F_4 ( ( V_4 -> V_62 >> 0 ) & 0xff ,
V_2 -> V_5 + V_63 ) ;
if ( V_61 & 0x0000ff00 )
F_4 ( ( V_4 -> V_62 >> 8 ) & 0xff ,
V_2 -> V_5 + V_64 ) ;
if ( V_61 & 0x00ff0000 )
F_4 ( ( V_4 -> V_62 >> 16 ) & 0xff ,
V_2 -> V_5 + V_65 ) ;
if ( V_61 & 0xff000000 )
F_4 ( ( V_4 -> V_62 >> 24 ) & 0xff ,
V_2 -> V_5 + V_66 ) ;
}
V_10 [ 1 ] = F_9 ( V_2 -> V_5 + V_63 ) ;
V_10 [ 1 ] |= F_9 ( V_2 -> V_5 + V_64 ) << 8 ;
V_10 [ 1 ] |= F_9 ( V_2 -> V_5 + V_65 ) << 16 ;
V_10 [ 1 ] |= F_9 ( V_2 -> V_5 + V_66 ) << 24 ;
return V_9 -> V_15 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
void T_1 * V_11 = F_1 ( V_2 , V_4 ) ;
unsigned char V_67 ;
int V_36 ;
V_67 = F_9 ( V_11 + V_68 ) ;
switch ( V_67 ) {
case V_69 :
case V_70 :
V_4 -> type = V_71 ;
V_4 -> V_72 = V_73 ;
V_4 -> V_74 = ( V_67 == V_70 ) ? 2 : 1 ;
V_4 -> V_18 = 0xffff ;
V_4 -> V_75 = & V_76 ;
V_4 -> V_77 = F_2 ;
V_36 = F_23 ( V_4 ) ;
if ( V_36 )
return V_36 ;
break;
case V_78 :
V_4 -> type = V_79 ;
V_4 -> V_72 = V_80 | V_81 ;
V_4 -> V_74 = 4 ;
V_4 -> V_18 = 0xffff ;
V_4 -> V_75 = & V_82 ;
V_4 -> V_83 = F_15 ;
break;
default:
V_4 -> type = V_84 ;
break;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_85 * V_86 )
{
struct V_3 * V_4 ;
unsigned int V_87 ;
unsigned char V_67 ;
bool V_88 ;
int V_36 ;
V_87 = V_86 -> V_89 [ 0 ] ;
if ( ! V_87 || ( V_87 & ~ ( 0x100000 - V_90 ) ) ) {
F_25 ( V_2 -> V_91 ,
L_1 ,
V_2 -> V_92 ) ;
return - V_93 ;
}
if ( ! F_26 ( V_87 , V_90 , V_2 -> V_92 ) ) {
F_25 ( V_2 -> V_91 , L_2 ,
V_2 -> V_92 , V_87 , V_90 ) ;
return - V_94 ;
}
V_2 -> V_11 = V_87 ;
V_2 -> V_5 = F_27 ( V_87 , V_90 ) ;
if ( ! V_2 -> V_5 )
return - V_95 ;
V_67 = F_9 ( V_2 -> V_5 + V_68 ) ;
switch ( V_67 & V_96 ) {
case V_97 :
V_88 = false ;
break;
case V_98 :
V_88 = true ;
break;
default:
return - V_99 ;
}
V_36 = F_28 ( V_2 , 4 ) ;
if ( V_36 )
return V_36 ;
V_4 = & V_2 -> V_100 [ 0 ] ;
if ( V_67 & V_101 ) {
V_4 -> type = V_84 ;
} else {
V_36 = F_22 ( V_2 , V_4 ) ;
if ( V_36 )
return V_36 ;
}
V_4 = & V_2 -> V_100 [ 1 ] ;
if ( V_67 & V_102 ) {
V_4 -> type = V_84 ;
} else {
V_36 = F_22 ( V_2 , V_4 ) ;
if ( V_36 )
return V_36 ;
}
V_4 = & V_2 -> V_100 [ 2 ] ;
if ( V_67 & V_103 ) {
V_4 -> type = V_84 ;
} else {
V_36 = F_22 ( V_2 , V_4 ) ;
if ( V_36 )
return V_36 ;
}
V_4 = & V_2 -> V_100 [ 3 ] ;
if ( V_88 ) {
V_4 -> type = V_104 ;
V_4 -> V_72 = V_80 | V_73 ;
V_4 -> V_74 = 32 ;
V_4 -> V_18 = 1 ;
V_4 -> V_75 = & V_105 ;
V_4 -> V_106 = F_20 ;
V_4 -> V_107 = F_18 ;
F_17 ( V_2 , V_4 ) ;
} else {
V_4 -> type = V_84 ;
}
return 0 ;
}
static void F_29 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 )
F_30 ( V_2 -> V_5 ) ;
if ( V_2 -> V_11 )
F_31 ( V_2 -> V_11 , V_90 ) ;
}
