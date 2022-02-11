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
V_16 = F_4 ( V_4 , V_16 ) ;
F_5 ( V_16 & 0xff , V_11 + F_6 ( V_12 ) ) ;
F_5 ( ( V_16 >> 8 ) & 0xff , V_11 + F_7 ( V_12 ) ) ;
F_5 ( 0x00 , V_11 + F_8 ( V_12 ) ) ;
}
return V_9 -> V_15 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_8 * V_9 ,
unsigned long V_18 )
{
void T_1 * V_11 = F_1 ( V_2 , V_4 ) ;
unsigned char V_19 ;
V_19 = F_10 ( V_11 + V_20 ) ;
if ( ( V_19 & V_21 ) == 0 )
return 0 ;
return - V_22 ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_13 )
{
void T_1 * V_11 = F_1 ( V_2 , V_4 ) ;
unsigned int V_12 = F_3 ( V_13 ) ;
unsigned int V_23 = F_12 ( V_13 ) ;
unsigned char V_16 ;
F_5 ( V_24 , V_11 + V_25 ) ;
F_5 ( 0 , V_11 + V_26 ) ;
V_16 = ( V_23 < 3 ) ? F_13 ( 0 ) : F_13 ( 2 ) ;
F_5 ( V_16 , V_11 + V_27 ) ;
V_16 = ( V_23 < 2 ) ? 0x58 : ( V_23 < 3 ) ? 0x93 : 0x99 ;
F_5 ( V_16 , V_11 + V_28 ) ;
F_5 ( 1 , V_11 + V_29 ) ;
V_16 = V_30 |
V_31 |
F_14 ( V_23 ) |
F_15 ( V_12 ) ;
F_5 ( V_16 , V_11 + V_32 ) ;
F_5 ( 0 , V_11 + V_33 ) ;
F_5 ( 0 , V_11 + V_34 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_8 * V_9 ,
unsigned int * V_10 )
{
void T_1 * V_11 = F_1 ( V_2 , V_4 ) ;
int V_35 ;
int V_14 ;
F_11 ( V_2 , V_4 , V_9 -> V_13 ) ;
for ( V_14 = 0 ; V_14 < V_9 -> V_15 ; V_14 ++ ) {
unsigned int V_16 ;
F_10 ( V_11 + V_36 ) ;
V_35 = F_17 ( V_2 , V_4 , V_9 , F_9 , 0 ) ;
if ( V_35 )
return V_35 ;
V_16 = F_10 ( V_11 + V_37 ) ;
V_16 |= ( F_10 ( V_11 + V_38 ) << 8 ) ;
V_10 [ V_14 ] = F_4 ( V_4 , V_16 ) ;
}
return V_9 -> V_15 ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned char V_39 = 0 ;
unsigned char V_40 = 0 ;
unsigned char V_41 = 0 ;
if ( V_4 -> V_42 & 0x000000ff ) {
V_39 &= ~ V_43 ;
V_41 &= ~ V_44 ;
V_41 |= V_45 ;
} else {
V_39 |= V_43 ;
V_41 &= ~ V_45 ;
}
if ( V_4 -> V_42 & 0x0000ff00 ) {
V_39 &= ~ V_46 ;
V_41 &= ~ V_47 ;
V_41 |= V_48 ;
} else {
V_39 |= V_46 ;
V_41 &= ~ V_48 ;
}
if ( V_4 -> V_42 & 0x00ff0000 ) {
V_40 &= ~ V_49 ;
V_41 &= ~ V_50 ;
V_41 |= V_51 ;
} else {
V_40 |= V_49 ;
V_41 &= ~ V_51 ;
}
if ( V_4 -> V_42 & 0xff000000 ) {
V_40 &= ~ V_52 ;
V_41 &= ~ V_53 ;
V_41 |= V_54 ;
} else {
V_40 |= V_52 ;
V_41 &= ~ V_54 ;
}
V_40 |= V_55 ;
V_40 |= V_56 ;
F_5 ( V_39 , V_2 -> V_5 + V_57 ) ;
F_5 ( V_40 , V_2 -> V_5 + V_58 ) ;
F_5 ( V_41 , V_2 -> V_5 + V_59 ) ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_8 * V_9 ,
unsigned int * V_10 )
{
unsigned int V_12 = F_3 ( V_9 -> V_13 ) ;
unsigned int V_60 ;
int V_35 ;
if ( V_12 < 8 )
V_60 = 0x000000ff ;
else if ( V_12 < 16 )
V_60 = 0x0000ff00 ;
else if ( V_12 < 24 )
V_60 = 0x00ff0000 ;
else
V_60 = 0xff000000 ;
V_35 = F_20 ( V_2 , V_4 , V_9 , V_10 , V_60 ) ;
if ( V_35 )
return V_35 ;
F_18 ( V_2 , V_4 ) ;
return V_9 -> V_15 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_8 * V_9 ,
unsigned int * V_10 )
{
unsigned int V_60 ;
V_60 = F_22 ( V_4 , V_10 ) ;
if ( V_60 ) {
if ( V_60 & 0x000000ff )
F_5 ( ( V_4 -> V_61 >> 0 ) & 0xff ,
V_2 -> V_5 + V_62 ) ;
if ( V_60 & 0x0000ff00 )
F_5 ( ( V_4 -> V_61 >> 8 ) & 0xff ,
V_2 -> V_5 + V_63 ) ;
if ( V_60 & 0x00ff0000 )
F_5 ( ( V_4 -> V_61 >> 16 ) & 0xff ,
V_2 -> V_5 + V_64 ) ;
if ( V_60 & 0xff000000 )
F_5 ( ( V_4 -> V_61 >> 24 ) & 0xff ,
V_2 -> V_5 + V_65 ) ;
}
V_10 [ 1 ] = F_10 ( V_2 -> V_5 + V_62 ) ;
V_10 [ 1 ] |= F_10 ( V_2 -> V_5 + V_63 ) << 8 ;
V_10 [ 1 ] |= F_10 ( V_2 -> V_5 + V_64 ) << 16 ;
V_10 [ 1 ] |= F_10 ( V_2 -> V_5 + V_65 ) << 24 ;
return V_9 -> V_15 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
void T_1 * V_11 = F_1 ( V_2 , V_4 ) ;
unsigned char V_66 ;
int V_35 ;
V_66 = F_10 ( V_11 + V_67 ) ;
switch ( V_66 ) {
case V_68 :
case V_69 :
V_4 -> type = V_70 ;
V_4 -> V_71 = V_72 ;
V_4 -> V_73 = ( V_66 == V_69 ) ? 2 : 1 ;
V_4 -> V_74 = 0xffff ;
V_4 -> V_75 = & V_76 ;
V_4 -> V_77 = F_2 ;
V_35 = F_24 ( V_4 ) ;
if ( V_35 )
return V_35 ;
break;
case V_78 :
V_4 -> type = V_79 ;
V_4 -> V_71 = V_80 | V_81 ;
V_4 -> V_73 = 4 ;
V_4 -> V_74 = 0xffff ;
V_4 -> V_75 = & V_82 ;
V_4 -> V_83 = F_16 ;
break;
default:
V_4 -> type = V_84 ;
break;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_85 * V_86 )
{
struct V_3 * V_4 ;
unsigned int V_87 ;
unsigned char V_66 ;
bool V_88 ;
int V_35 ;
V_87 = V_86 -> V_89 [ 0 ] ;
if ( ! V_87 || ( V_87 & ~ ( 0x100000 - V_90 ) ) ) {
F_26 ( V_2 -> V_91 ,
L_1 ,
V_2 -> V_92 ) ;
return - V_93 ;
}
if ( ! F_27 ( V_87 , V_90 , V_2 -> V_92 ) ) {
F_26 ( V_2 -> V_91 , L_2 ,
V_2 -> V_92 , V_87 , V_90 ) ;
return - V_94 ;
}
V_2 -> V_11 = V_87 ;
V_2 -> V_5 = F_28 ( V_87 , V_90 ) ;
if ( ! V_2 -> V_5 )
return - V_95 ;
V_66 = F_10 ( V_2 -> V_5 + V_67 ) ;
switch ( V_66 & V_96 ) {
case V_97 :
V_88 = false ;
break;
case V_98 :
V_88 = true ;
break;
default:
return - V_99 ;
}
V_35 = F_29 ( V_2 , 4 ) ;
if ( V_35 )
return V_35 ;
V_4 = & V_2 -> V_100 [ 0 ] ;
if ( V_66 & V_101 ) {
V_4 -> type = V_84 ;
} else {
V_35 = F_23 ( V_2 , V_4 ) ;
if ( V_35 )
return V_35 ;
}
V_4 = & V_2 -> V_100 [ 1 ] ;
if ( V_66 & V_102 ) {
V_4 -> type = V_84 ;
} else {
V_35 = F_23 ( V_2 , V_4 ) ;
if ( V_35 )
return V_35 ;
}
V_4 = & V_2 -> V_100 [ 2 ] ;
if ( V_66 & V_103 ) {
V_4 -> type = V_84 ;
} else {
V_35 = F_23 ( V_2 , V_4 ) ;
if ( V_35 )
return V_35 ;
}
V_4 = & V_2 -> V_100 [ 3 ] ;
if ( V_88 ) {
V_4 -> type = V_104 ;
V_4 -> V_71 = V_80 | V_72 ;
V_4 -> V_73 = 32 ;
V_4 -> V_74 = 1 ;
V_4 -> V_75 = & V_105 ;
V_4 -> V_106 = F_21 ;
V_4 -> V_107 = F_19 ;
F_18 ( V_2 , V_4 ) ;
} else {
V_4 -> type = V_84 ;
}
return 0 ;
}
static void F_30 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 )
F_31 ( V_2 -> V_5 ) ;
if ( V_2 -> V_11 )
F_32 ( V_2 -> V_11 , V_90 ) ;
}
