static void T_1 * F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
return V_6 -> V_8 + ( V_4 -> V_9 + 1 ) * V_10 ;
}
static int F_2 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_11 * V_12 ,
unsigned int * V_13 )
{
struct V_14 * V_15 = V_4 -> V_7 ;
unsigned int V_16 = F_3 ( V_12 -> V_17 ) ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_12 -> V_19 ; V_18 ++ )
V_13 [ V_18 ] = V_15 -> V_20 [ V_16 ] ;
return V_12 -> V_19 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_11 * V_12 ,
unsigned int * V_13 )
{
struct V_14 * V_15 = V_4 -> V_7 ;
void T_1 * V_21 = F_1 ( V_2 , V_4 ) ;
unsigned int V_16 = F_3 ( V_12 -> V_17 ) ;
unsigned int V_22 = V_15 -> V_20 [ V_16 ] ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_12 -> V_19 ; V_18 ++ ) {
V_22 = V_13 [ V_18 ] ;
V_22 += ( ( V_4 -> V_23 + 1 ) >> 1 ) ;
V_22 &= V_4 -> V_23 ;
F_5 ( V_22 & 0xff , V_21 + F_6 ( V_16 ) ) ;
F_5 ( ( V_22 >> 8 ) & 0xff , V_21 + F_7 ( V_16 ) ) ;
F_5 ( 0x00 , V_21 + F_8 ( V_16 ) ) ;
}
V_15 -> V_20 [ V_16 ] = V_22 ;
return V_12 -> V_19 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_11 * V_12 ,
unsigned long V_24 )
{
void T_1 * V_21 = F_1 ( V_2 , V_4 ) ;
unsigned char V_25 ;
V_25 = F_10 ( V_21 + V_26 ) ;
if ( ( V_25 & V_27 ) == 0 )
return 0 ;
return - V_28 ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_17 )
{
void T_1 * V_21 = F_1 ( V_2 , V_4 ) ;
unsigned int V_16 = F_3 ( V_17 ) ;
unsigned int V_29 = F_12 ( V_17 ) ;
unsigned char V_22 ;
F_5 ( V_30 , V_21 + V_31 ) ;
F_5 ( 0 , V_21 + V_32 ) ;
V_22 = ( V_29 < 3 ) ? F_13 ( 0 ) : F_13 ( 2 ) ;
F_5 ( V_22 , V_21 + V_33 ) ;
V_22 = ( V_29 < 2 ) ? 0x58 : ( V_29 < 3 ) ? 0x93 : 0x99 ;
F_5 ( V_22 , V_21 + V_34 ) ;
F_5 ( 1 , V_21 + V_35 ) ;
V_22 = V_36 |
V_37 |
F_14 ( V_29 ) |
F_15 ( V_16 ) ;
F_5 ( V_22 , V_21 + V_38 ) ;
F_5 ( 0 , V_21 + V_39 ) ;
F_5 ( 0 , V_21 + V_40 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_11 * V_12 ,
unsigned int * V_13 )
{
void T_1 * V_21 = F_1 ( V_2 , V_4 ) ;
int V_41 ;
int V_18 ;
F_11 ( V_2 , V_4 , V_12 -> V_17 ) ;
for ( V_18 = 0 ; V_18 < V_12 -> V_19 ; V_18 ++ ) {
unsigned int V_22 ;
F_10 ( V_21 + V_42 ) ;
V_41 = F_17 ( V_2 , V_4 , V_12 , F_9 , 0 ) ;
if ( V_41 )
return V_41 ;
V_22 = F_10 ( V_21 + V_43 ) ;
V_22 |= ( F_10 ( V_21 + V_44 ) << 8 ) ;
V_22 += ( ( V_4 -> V_23 + 1 ) >> 1 ) ;
V_22 &= V_4 -> V_23 ;
V_13 [ V_18 ] = V_22 ;
}
return V_12 -> V_19 ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned char V_45 = 0 ;
unsigned char V_46 = 0 ;
unsigned char V_47 = 0 ;
if ( V_4 -> V_48 & 0x000000ff ) {
V_45 &= ~ V_49 ;
V_47 &= ~ V_50 ;
V_47 |= V_51 ;
} else {
V_45 |= V_49 ;
V_47 &= ~ V_51 ;
}
if ( V_4 -> V_48 & 0x0000ff00 ) {
V_45 &= ~ V_52 ;
V_47 &= ~ V_53 ;
V_47 |= V_54 ;
} else {
V_45 |= V_52 ;
V_47 &= ~ V_54 ;
}
if ( V_4 -> V_48 & 0x00ff0000 ) {
V_46 &= ~ V_55 ;
V_47 &= ~ V_56 ;
V_47 |= V_57 ;
} else {
V_46 |= V_55 ;
V_47 &= ~ V_57 ;
}
if ( V_4 -> V_48 & 0xff000000 ) {
V_46 &= ~ V_58 ;
V_47 &= ~ V_59 ;
V_47 |= V_60 ;
} else {
V_46 |= V_58 ;
V_47 &= ~ V_60 ;
}
V_46 |= V_61 ;
V_46 |= V_62 ;
F_5 ( V_45 , V_6 -> V_8 + V_63 ) ;
F_5 ( V_46 , V_6 -> V_8 + V_64 ) ;
F_5 ( V_47 , V_6 -> V_8 + V_65 ) ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_11 * V_12 ,
unsigned int * V_13 )
{
unsigned int V_16 = F_3 ( V_12 -> V_17 ) ;
unsigned int V_66 ;
int V_41 ;
if ( V_16 < 8 )
V_66 = 0x000000ff ;
else if ( V_16 < 16 )
V_66 = 0x0000ff00 ;
else if ( V_16 < 24 )
V_66 = 0x00ff0000 ;
else
V_66 = 0xff000000 ;
V_41 = F_20 ( V_2 , V_4 , V_12 , V_13 , V_66 ) ;
if ( V_41 )
return V_41 ;
F_18 ( V_2 , V_4 ) ;
return V_12 -> V_19 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_11 * V_12 ,
unsigned int * V_13 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_66 ;
V_66 = F_22 ( V_4 , V_13 ) ;
if ( V_66 ) {
if ( V_66 & 0x000000ff )
F_5 ( ( V_4 -> V_67 >> 0 ) & 0xff ,
V_6 -> V_8 + V_68 ) ;
if ( V_66 & 0x0000ff00 )
F_5 ( ( V_4 -> V_67 >> 8 ) & 0xff ,
V_6 -> V_8 + V_69 ) ;
if ( V_66 & 0x00ff0000 )
F_5 ( ( V_4 -> V_67 >> 16 ) & 0xff ,
V_6 -> V_8 + V_70 ) ;
if ( V_66 & 0xff000000 )
F_5 ( ( V_4 -> V_67 >> 24 ) & 0xff ,
V_6 -> V_8 + V_71 ) ;
}
V_13 [ 1 ] = F_10 ( V_6 -> V_8 + V_68 ) ;
V_13 [ 1 ] |= F_10 ( V_6 -> V_8 + V_69 ) << 8 ;
V_13 [ 1 ] |= F_10 ( V_6 -> V_8 + V_70 ) << 16 ;
V_13 [ 1 ] |= F_10 ( V_6 -> V_8 + V_71 ) << 24 ;
return V_12 -> V_19 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_14 * V_15 ;
void T_1 * V_21 = F_1 ( V_2 , V_4 ) ;
unsigned char V_72 ;
V_72 = F_10 ( V_21 + V_73 ) ;
switch ( V_72 ) {
case V_74 :
case V_75 :
V_15 = F_24 ( V_4 , sizeof( * V_15 ) ) ;
if ( ! V_15 )
return - V_76 ;
V_4 -> type = V_77 ;
V_4 -> V_78 = V_79 ;
V_4 -> V_80 = ( V_72 == V_75 ) ? 2 : 1 ;
V_4 -> V_23 = 0xffff ;
V_4 -> V_81 = & V_82 ;
V_4 -> V_83 = F_2 ;
V_4 -> V_84 = F_4 ;
break;
case V_85 :
V_4 -> type = V_86 ;
V_4 -> V_78 = V_87 | V_88 ;
V_4 -> V_80 = 4 ;
V_4 -> V_23 = 0xffff ;
V_4 -> V_81 = & V_89 ;
V_4 -> V_83 = F_16 ;
break;
default:
V_4 -> type = V_90 ;
break;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_91 * V_92 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
unsigned char V_72 ;
bool V_93 ;
int V_41 ;
V_6 = F_26 ( V_2 , sizeof( * V_6 ) ) ;
if ( ! V_6 )
return - V_76 ;
V_6 -> V_8 = ( void T_1 * ) ( unsigned long ) V_92 -> V_94 [ 0 ] ;
V_72 = F_10 ( V_6 -> V_8 + V_73 ) ;
switch ( V_72 & V_95 ) {
case V_96 :
break;
case V_97 :
V_93 = true ;
break;
default:
return - V_98 ;
}
V_41 = F_27 ( V_2 , 4 ) ;
if ( V_41 )
return V_41 ;
V_4 = & V_2 -> V_99 [ 0 ] ;
if ( V_72 & V_100 ) {
V_4 -> type = V_90 ;
} else {
V_41 = F_23 ( V_2 , V_4 ) ;
if ( V_41 )
return V_41 ;
}
V_4 = & V_2 -> V_99 [ 1 ] ;
if ( V_72 & V_101 ) {
V_4 -> type = V_90 ;
} else {
V_41 = F_23 ( V_2 , V_4 ) ;
if ( V_41 )
return V_41 ;
}
V_4 = & V_2 -> V_99 [ 2 ] ;
if ( V_72 & V_102 ) {
V_4 -> type = V_90 ;
} else {
V_41 = F_23 ( V_2 , V_4 ) ;
if ( V_41 )
return V_41 ;
}
V_4 = & V_2 -> V_99 [ 3 ] ;
if ( V_93 ) {
V_4 -> type = V_103 ;
V_4 -> V_78 = V_87 | V_79 ;
V_4 -> V_80 = 32 ;
V_4 -> V_23 = 1 ;
V_4 -> V_81 = & V_104 ;
V_4 -> V_105 = F_21 ;
V_4 -> V_106 = F_19 ;
F_18 ( V_2 , V_4 ) ;
} else {
V_4 -> type = V_90 ;
}
return 0 ;
}
