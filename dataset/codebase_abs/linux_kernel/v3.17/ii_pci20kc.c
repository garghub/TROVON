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
struct V_11 * V_12 = V_4 -> V_13 ;
unsigned int V_14 = F_3 ( V_9 -> V_15 ) ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_9 -> V_17 ; V_16 ++ )
V_10 [ V_16 ] = V_12 -> V_18 [ V_14 ] ;
return V_9 -> V_17 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_8 * V_9 ,
unsigned int * V_10 )
{
struct V_11 * V_12 = V_4 -> V_13 ;
void T_1 * V_19 = F_1 ( V_2 , V_4 ) ;
unsigned int V_14 = F_3 ( V_9 -> V_15 ) ;
unsigned int V_20 = V_12 -> V_18 [ V_14 ] ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_9 -> V_17 ; V_16 ++ ) {
V_20 = V_10 [ V_16 ] ;
V_20 += ( ( V_4 -> V_21 + 1 ) >> 1 ) ;
V_20 &= V_4 -> V_21 ;
F_5 ( V_20 & 0xff , V_19 + F_6 ( V_14 ) ) ;
F_5 ( ( V_20 >> 8 ) & 0xff , V_19 + F_7 ( V_14 ) ) ;
F_5 ( 0x00 , V_19 + F_8 ( V_14 ) ) ;
}
V_12 -> V_18 [ V_14 ] = V_20 ;
return V_9 -> V_17 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_8 * V_9 ,
unsigned long V_22 )
{
void T_1 * V_19 = F_1 ( V_2 , V_4 ) ;
unsigned char V_23 ;
V_23 = F_10 ( V_19 + V_24 ) ;
if ( ( V_23 & V_25 ) == 0 )
return 0 ;
return - V_26 ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_15 )
{
void T_1 * V_19 = F_1 ( V_2 , V_4 ) ;
unsigned int V_14 = F_3 ( V_15 ) ;
unsigned int V_27 = F_12 ( V_15 ) ;
unsigned char V_20 ;
F_5 ( V_28 , V_19 + V_29 ) ;
F_5 ( 0 , V_19 + V_30 ) ;
V_20 = ( V_27 < 3 ) ? F_13 ( 0 ) : F_13 ( 2 ) ;
F_5 ( V_20 , V_19 + V_31 ) ;
V_20 = ( V_27 < 2 ) ? 0x58 : ( V_27 < 3 ) ? 0x93 : 0x99 ;
F_5 ( V_20 , V_19 + V_32 ) ;
F_5 ( 1 , V_19 + V_33 ) ;
V_20 = V_34 |
V_35 |
F_14 ( V_27 ) |
F_15 ( V_14 ) ;
F_5 ( V_20 , V_19 + V_36 ) ;
F_5 ( 0 , V_19 + V_37 ) ;
F_5 ( 0 , V_19 + V_38 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_8 * V_9 ,
unsigned int * V_10 )
{
void T_1 * V_19 = F_1 ( V_2 , V_4 ) ;
int V_39 ;
int V_16 ;
F_11 ( V_2 , V_4 , V_9 -> V_15 ) ;
for ( V_16 = 0 ; V_16 < V_9 -> V_17 ; V_16 ++ ) {
unsigned int V_20 ;
F_10 ( V_19 + V_40 ) ;
V_39 = F_17 ( V_2 , V_4 , V_9 , F_9 , 0 ) ;
if ( V_39 )
return V_39 ;
V_20 = F_10 ( V_19 + V_41 ) ;
V_20 |= ( F_10 ( V_19 + V_42 ) << 8 ) ;
V_20 += ( ( V_4 -> V_21 + 1 ) >> 1 ) ;
V_20 &= V_4 -> V_21 ;
V_10 [ V_16 ] = V_20 ;
}
return V_9 -> V_17 ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned char V_43 = 0 ;
unsigned char V_44 = 0 ;
unsigned char V_45 = 0 ;
if ( V_4 -> V_46 & 0x000000ff ) {
V_43 &= ~ V_47 ;
V_45 &= ~ V_48 ;
V_45 |= V_49 ;
} else {
V_43 |= V_47 ;
V_45 &= ~ V_49 ;
}
if ( V_4 -> V_46 & 0x0000ff00 ) {
V_43 &= ~ V_50 ;
V_45 &= ~ V_51 ;
V_45 |= V_52 ;
} else {
V_43 |= V_50 ;
V_45 &= ~ V_52 ;
}
if ( V_4 -> V_46 & 0x00ff0000 ) {
V_44 &= ~ V_53 ;
V_45 &= ~ V_54 ;
V_45 |= V_55 ;
} else {
V_44 |= V_53 ;
V_45 &= ~ V_55 ;
}
if ( V_4 -> V_46 & 0xff000000 ) {
V_44 &= ~ V_56 ;
V_45 &= ~ V_57 ;
V_45 |= V_58 ;
} else {
V_44 |= V_56 ;
V_45 &= ~ V_58 ;
}
V_44 |= V_59 ;
V_44 |= V_60 ;
F_5 ( V_43 , V_2 -> V_5 + V_61 ) ;
F_5 ( V_44 , V_2 -> V_5 + V_62 ) ;
F_5 ( V_45 , V_2 -> V_5 + V_63 ) ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_8 * V_9 ,
unsigned int * V_10 )
{
unsigned int V_14 = F_3 ( V_9 -> V_15 ) ;
unsigned int V_64 ;
int V_39 ;
if ( V_14 < 8 )
V_64 = 0x000000ff ;
else if ( V_14 < 16 )
V_64 = 0x0000ff00 ;
else if ( V_14 < 24 )
V_64 = 0x00ff0000 ;
else
V_64 = 0xff000000 ;
V_39 = F_20 ( V_2 , V_4 , V_9 , V_10 , V_64 ) ;
if ( V_39 )
return V_39 ;
F_18 ( V_2 , V_4 ) ;
return V_9 -> V_17 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_8 * V_9 ,
unsigned int * V_10 )
{
unsigned int V_64 ;
V_64 = F_22 ( V_4 , V_10 ) ;
if ( V_64 ) {
if ( V_64 & 0x000000ff )
F_5 ( ( V_4 -> V_65 >> 0 ) & 0xff ,
V_2 -> V_5 + V_66 ) ;
if ( V_64 & 0x0000ff00 )
F_5 ( ( V_4 -> V_65 >> 8 ) & 0xff ,
V_2 -> V_5 + V_67 ) ;
if ( V_64 & 0x00ff0000 )
F_5 ( ( V_4 -> V_65 >> 16 ) & 0xff ,
V_2 -> V_5 + V_68 ) ;
if ( V_64 & 0xff000000 )
F_5 ( ( V_4 -> V_65 >> 24 ) & 0xff ,
V_2 -> V_5 + V_69 ) ;
}
V_10 [ 1 ] = F_10 ( V_2 -> V_5 + V_66 ) ;
V_10 [ 1 ] |= F_10 ( V_2 -> V_5 + V_67 ) << 8 ;
V_10 [ 1 ] |= F_10 ( V_2 -> V_5 + V_68 ) << 16 ;
V_10 [ 1 ] |= F_10 ( V_2 -> V_5 + V_69 ) << 24 ;
return V_9 -> V_17 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_11 * V_12 ;
void T_1 * V_19 = F_1 ( V_2 , V_4 ) ;
unsigned char V_70 ;
V_70 = F_10 ( V_19 + V_71 ) ;
switch ( V_70 ) {
case V_72 :
case V_73 :
V_12 = F_24 ( V_4 , sizeof( * V_12 ) ) ;
if ( ! V_12 )
return - V_74 ;
V_4 -> type = V_75 ;
V_4 -> V_76 = V_77 ;
V_4 -> V_78 = ( V_70 == V_73 ) ? 2 : 1 ;
V_4 -> V_21 = 0xffff ;
V_4 -> V_79 = & V_80 ;
V_4 -> V_81 = F_2 ;
V_4 -> V_82 = F_4 ;
break;
case V_83 :
V_4 -> type = V_84 ;
V_4 -> V_76 = V_85 | V_86 ;
V_4 -> V_78 = 4 ;
V_4 -> V_21 = 0xffff ;
V_4 -> V_79 = & V_87 ;
V_4 -> V_81 = F_16 ;
break;
default:
V_4 -> type = V_88 ;
break;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_89 * V_90 )
{
struct V_3 * V_4 ;
unsigned int V_91 ;
unsigned char V_70 ;
bool V_92 ;
int V_39 ;
V_91 = V_90 -> V_93 [ 0 ] ;
if ( ! V_91 || ( V_91 & ~ ( 0x100000 - V_94 ) ) ) {
F_26 ( V_2 -> V_95 ,
L_1 ,
V_2 -> V_96 ) ;
return - V_97 ;
}
if ( ! F_27 ( V_91 , V_94 , V_2 -> V_96 ) ) {
F_26 ( V_2 -> V_95 , L_2 ,
V_2 -> V_96 , V_91 , V_94 ) ;
return - V_98 ;
}
V_2 -> V_19 = V_91 ;
V_2 -> V_5 = F_28 ( V_91 , V_94 ) ;
if ( ! V_2 -> V_5 )
return - V_74 ;
V_70 = F_10 ( V_2 -> V_5 + V_71 ) ;
switch ( V_70 & V_99 ) {
case V_100 :
V_92 = false ;
break;
case V_101 :
V_92 = true ;
break;
default:
return - V_102 ;
}
V_39 = F_29 ( V_2 , 4 ) ;
if ( V_39 )
return V_39 ;
V_4 = & V_2 -> V_103 [ 0 ] ;
if ( V_70 & V_104 ) {
V_4 -> type = V_88 ;
} else {
V_39 = F_23 ( V_2 , V_4 ) ;
if ( V_39 )
return V_39 ;
}
V_4 = & V_2 -> V_103 [ 1 ] ;
if ( V_70 & V_105 ) {
V_4 -> type = V_88 ;
} else {
V_39 = F_23 ( V_2 , V_4 ) ;
if ( V_39 )
return V_39 ;
}
V_4 = & V_2 -> V_103 [ 2 ] ;
if ( V_70 & V_106 ) {
V_4 -> type = V_88 ;
} else {
V_39 = F_23 ( V_2 , V_4 ) ;
if ( V_39 )
return V_39 ;
}
V_4 = & V_2 -> V_103 [ 3 ] ;
if ( V_92 ) {
V_4 -> type = V_107 ;
V_4 -> V_76 = V_85 | V_77 ;
V_4 -> V_78 = 32 ;
V_4 -> V_21 = 1 ;
V_4 -> V_79 = & V_108 ;
V_4 -> V_109 = F_21 ;
V_4 -> V_110 = F_19 ;
F_18 ( V_2 , V_4 ) ;
} else {
V_4 -> type = V_88 ;
}
return 0 ;
}
static void F_30 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 )
F_31 ( V_2 -> V_5 ) ;
if ( V_2 -> V_19 )
F_32 ( V_2 -> V_19 , V_94 ) ;
}
