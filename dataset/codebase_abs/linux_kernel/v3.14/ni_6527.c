static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
void T_1 * V_7 = V_5 -> V_8 ;
if ( V_3 != V_5 -> V_9 ) {
F_2 ( V_3 & 0xff , V_7 + F_3 ( 0 ) ) ;
F_2 ( ( V_3 >> 8 ) & 0xff , V_7 + F_3 ( 1 ) ) ;
F_2 ( ( V_3 >> 16 ) & 0x0f , V_7 + F_3 ( 2 ) ) ;
F_2 ( V_10 , V_7 + V_11 ) ;
V_5 -> V_9 = V_3 ;
}
}
static void F_4 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
void T_1 * V_7 = V_5 -> V_8 ;
F_2 ( V_3 & 0xff , V_7 + F_5 ( 0 ) ) ;
F_2 ( ( V_3 >> 8 ) & 0xff , V_7 + F_5 ( 1 ) ) ;
F_2 ( ( V_3 >> 16 ) & 0xff , V_7 + F_5 ( 2 ) ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_14 * V_15 ,
unsigned int * V_16 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_17 = F_7 ( V_15 -> V_18 ) ;
unsigned int V_19 ;
switch ( V_16 [ 0 ] ) {
case V_20 :
V_19 = ( V_16 [ 1 ] + 100 ) / 200 ;
V_16 [ 1 ] = V_19 * 200 ;
if ( V_19 ) {
F_1 ( V_2 , V_19 ) ;
V_5 -> V_21 |= 1 << V_17 ;
} else {
V_5 -> V_21 &= ~ ( 1 << V_17 ) ;
}
F_4 ( V_2 , V_5 -> V_21 ) ;
break;
default:
return - V_22 ;
}
return V_15 -> V_23 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_14 * V_15 ,
unsigned int * V_16 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
void T_1 * V_7 = V_5 -> V_8 ;
unsigned int V_3 ;
V_3 = F_9 ( V_7 + F_10 ( 0 ) ) ;
V_3 |= ( F_9 ( V_7 + F_10 ( 1 ) ) << 8 ) ;
V_3 |= ( F_9 ( V_7 + F_10 ( 2 ) ) << 16 ) ;
V_16 [ 1 ] = V_3 ;
return V_15 -> V_23 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_14 * V_15 ,
unsigned int * V_16 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
void T_1 * V_7 = V_5 -> V_8 ;
unsigned int V_24 ;
V_24 = F_12 ( V_13 , V_16 ) ;
if ( V_24 ) {
unsigned int V_3 = V_13 -> V_25 ^ 0xffffff ;
if ( V_24 & 0x0000ff )
F_2 ( V_3 & 0xff , V_7 + F_13 ( 0 ) ) ;
if ( V_24 & 0x00ff00 )
F_2 ( ( V_3 >> 8 ) & 0xff , V_7 + F_13 ( 1 ) ) ;
if ( V_24 & 0xff0000 )
F_2 ( ( V_3 >> 16 ) & 0xff , V_7 + F_13 ( 2 ) ) ;
}
V_16 [ 1 ] = V_13 -> V_25 ;
return V_15 -> V_23 ;
}
static T_2 F_14 ( int V_26 , void * V_27 )
{
struct V_1 * V_2 = V_27 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_12 * V_13 = V_2 -> V_28 ;
void T_1 * V_7 = V_5 -> V_8 ;
unsigned int V_29 ;
V_29 = F_9 ( V_7 + V_30 ) ;
if ( ! ( V_29 & V_31 ) )
return V_32 ;
if ( V_29 & V_33 ) {
F_15 ( V_13 -> V_34 , 0 ) ;
V_13 -> V_34 -> V_35 |= V_36 ;
F_16 ( V_2 , V_13 ) ;
}
F_2 ( V_37 , V_7 + V_11 ) ;
return V_38 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_39 * V_40 )
{
int V_41 = 0 ;
V_41 |= F_18 ( & V_40 -> V_42 , V_43 ) ;
V_41 |= F_18 ( & V_40 -> V_44 , V_45 ) ;
V_41 |= F_18 ( & V_40 -> V_46 , V_47 ) ;
V_41 |= F_18 ( & V_40 -> V_48 , V_49 ) ;
V_41 |= F_18 ( & V_40 -> V_50 , V_49 ) ;
if ( V_41 )
return 1 ;
if ( V_41 )
return 2 ;
V_41 |= F_19 ( & V_40 -> V_51 , 0 ) ;
V_41 |= F_19 ( & V_40 -> V_52 , 0 ) ;
V_41 |= F_19 ( & V_40 -> V_53 , 0 ) ;
V_41 |= F_19 ( & V_40 -> V_54 , 1 ) ;
V_41 |= F_19 ( & V_40 -> V_55 , 0 ) ;
if ( V_41 )
return 3 ;
if ( V_41 )
return 4 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
void T_1 * V_7 = V_5 -> V_8 ;
F_2 ( V_37 , V_7 + V_11 ) ;
F_2 ( V_56 , V_7 + V_57 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
void T_1 * V_7 = V_5 -> V_8 ;
F_2 ( V_58 , V_7 + V_57 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_14 * V_15 , unsigned int * V_16 )
{
V_16 [ 1 ] = 0 ;
return V_15 -> V_23 ;
}
static void F_23 ( struct V_1 * V_2 ,
unsigned int V_59 ,
unsigned int V_60 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
void T_1 * V_7 = V_5 -> V_8 ;
F_2 ( V_59 & 0xff , V_7 + F_24 ( 0 ) ) ;
F_2 ( ( V_59 >> 8 ) & 0xff , V_7 + F_24 ( 1 ) ) ;
F_2 ( ( V_59 >> 16 ) & 0xff , V_7 + F_24 ( 2 ) ) ;
F_2 ( V_60 & 0xff , V_7 + F_25 ( 0 ) ) ;
F_2 ( ( V_60 >> 8 ) & 0xff , V_7 + F_25 ( 1 ) ) ;
F_2 ( ( V_60 >> 16 ) & 0xff , V_7 + F_25 ( 2 ) ) ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_14 * V_15 ,
unsigned int * V_16 )
{
switch ( V_16 [ 0 ] ) {
case V_61 :
if ( V_15 -> V_23 != 3 )
return - V_22 ;
F_23 ( V_2 , V_16 [ 1 ] , V_16 [ 2 ] ) ;
break;
default:
return - V_22 ;
}
return V_15 -> V_23 ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
void T_1 * V_7 = V_5 -> V_8 ;
F_4 ( V_2 , 0 ) ;
F_2 ( V_37 | V_62 ,
V_7 + V_11 ) ;
F_2 ( V_58 , V_7 + V_57 ) ;
}
static int F_28 ( struct V_1 * V_2 ,
unsigned long V_63 )
{
struct V_64 * V_65 = F_29 ( V_2 ) ;
const struct V_66 * V_67 = NULL ;
struct V_4 * V_5 ;
struct V_12 * V_13 ;
int V_68 ;
if ( V_63 < F_30 ( V_69 ) )
V_67 = & V_69 [ V_63 ] ;
if ( ! V_67 )
return - V_70 ;
V_2 -> V_71 = V_67 ;
V_2 -> V_72 = V_67 -> V_73 ;
V_5 = F_31 ( V_2 , sizeof( * V_5 ) ) ;
if ( ! V_5 )
return - V_74 ;
V_68 = F_32 ( V_2 ) ;
if ( V_68 )
return V_68 ;
V_5 -> V_8 = F_33 ( V_65 , 1 ) ;
if ( ! V_5 -> V_8 )
return - V_74 ;
if ( F_9 ( V_5 -> V_8 + V_75 ) != 0x27 )
return - V_70 ;
F_27 ( V_2 ) ;
V_68 = F_34 ( V_65 -> V_26 , F_14 , V_76 ,
V_2 -> V_72 , V_2 ) ;
if ( V_68 == 0 )
V_2 -> V_26 = V_65 -> V_26 ;
V_68 = F_35 ( V_2 , 3 ) ;
if ( V_68 )
return V_68 ;
V_13 = & V_2 -> V_77 [ 0 ] ;
V_13 -> type = V_78 ;
V_13 -> V_79 = V_80 ;
V_13 -> V_81 = 24 ;
V_13 -> V_82 = 1 ;
V_13 -> V_83 = & V_84 ;
V_13 -> V_85 = F_6 ;
V_13 -> V_86 = F_8 ;
V_13 = & V_2 -> V_77 [ 1 ] ;
V_13 -> type = V_87 ;
V_13 -> V_79 = V_88 ;
V_13 -> V_81 = 24 ;
V_13 -> V_82 = 1 ;
V_13 -> V_83 = & V_84 ;
V_13 -> V_86 = F_11 ;
V_13 = & V_2 -> V_77 [ 2 ] ;
if ( V_2 -> V_26 ) {
V_2 -> V_28 = V_13 ;
V_13 -> type = V_78 ;
V_13 -> V_79 = V_80 | V_89 ;
V_13 -> V_81 = 1 ;
V_13 -> V_82 = 1 ;
V_13 -> V_83 = & V_84 ;
V_13 -> V_85 = F_26 ;
V_13 -> V_86 = F_22 ;
V_13 -> V_90 = F_17 ;
V_13 -> V_91 = F_20 ;
V_13 -> V_92 = F_21 ;
} else {
V_13 -> type = V_93 ;
}
return 0 ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 && V_5 -> V_8 )
F_27 ( V_2 ) ;
if ( V_2 -> V_26 )
F_37 ( V_2 -> V_26 , V_2 ) ;
F_38 ( V_2 ) ;
}
static int F_39 ( struct V_64 * V_2 ,
const struct V_94 * V_95 )
{
return F_40 ( V_2 , & V_96 , V_95 -> V_97 ) ;
}
