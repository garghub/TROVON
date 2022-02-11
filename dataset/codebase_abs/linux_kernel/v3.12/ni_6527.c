static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 = F_2 ( V_6 -> V_12 ) ;
unsigned int V_13 ;
if ( V_6 -> V_14 != 2 )
return - V_15 ;
if ( V_7 [ 0 ] != V_16 )
return - V_15 ;
if ( V_7 [ 1 ] ) {
V_13 = ( V_7 [ 1 ] + 100 ) / 200 ;
V_7 [ 1 ] = V_13 * 200 ;
if ( V_13 != V_9 -> V_17 ) {
F_3 ( V_13 & 0xff ,
V_9 -> V_18 -> V_19 + F_4 ( 0 ) ) ;
F_3 ( ( V_13 >> 8 ) & 0xff ,
V_9 -> V_18 -> V_19 + F_4 ( 1 ) ) ;
F_3 ( ( V_13 >> 16 ) & 0x0f ,
V_9 -> V_18 -> V_19 + F_4 ( 2 ) ) ;
F_3 ( V_20 ,
V_9 -> V_18 -> V_19 + V_21 ) ;
V_9 -> V_17 = V_13 ;
}
V_9 -> V_22 |= 1 << V_11 ;
} else {
V_9 -> V_22 &= ~ ( 1 << V_11 ) ;
}
F_3 ( V_9 -> V_22 ,
V_9 -> V_18 -> V_19 + F_5 ( 0 ) ) ;
F_3 ( V_9 -> V_22 >> 8 ,
V_9 -> V_18 -> V_19 + F_5 ( 1 ) ) ;
F_3 ( V_9 -> V_22 >> 16 ,
V_9 -> V_18 -> V_19 + F_5 ( 2 ) ) ;
return 2 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
V_7 [ 1 ] = F_7 ( V_9 -> V_18 -> V_19 + F_8 ( 0 ) ) ;
V_7 [ 1 ] |= F_7 ( V_9 -> V_18 -> V_19 + F_8 ( 1 ) ) << 8 ;
V_7 [ 1 ] |= F_7 ( V_9 -> V_18 -> V_19 + F_8 ( 2 ) ) << 16 ;
return V_6 -> V_14 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
if ( V_7 [ 0 ] ) {
V_4 -> V_23 &= ~ V_7 [ 0 ] ;
V_4 -> V_23 |= ( V_7 [ 0 ] & V_7 [ 1 ] ) ;
if ( V_7 [ 0 ] & 0x0000ff ) {
F_3 ( ( V_4 -> V_23 ^ 0xff ) ,
V_9 -> V_18 -> V_19 + F_8 ( 3 ) ) ;
}
if ( V_7 [ 0 ] & 0x00ff00 ) {
F_3 ( ( V_4 -> V_23 >> 8 ) ^ 0xff ,
V_9 -> V_18 -> V_19 + F_8 ( 4 ) ) ;
}
if ( V_7 [ 0 ] & 0xff0000 ) {
F_3 ( ( V_4 -> V_23 >> 16 ) ^ 0xff ,
V_9 -> V_18 -> V_19 + F_8 ( 5 ) ) ;
}
}
V_7 [ 1 ] = V_4 -> V_23 ;
return V_6 -> V_14 ;
}
static T_1 F_10 ( int V_24 , void * V_25 )
{
struct V_1 * V_2 = V_25 ;
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_3 * V_4 = & V_2 -> V_26 [ 2 ] ;
unsigned int V_27 ;
V_27 = F_7 ( V_9 -> V_18 -> V_19 + V_28 ) ;
if ( ( V_27 & V_29 ) == 0 )
return V_30 ;
if ( ( V_27 & V_31 ) == 0 )
return V_30 ;
F_3 ( V_32 | V_33 ,
V_9 -> V_18 -> V_19 + V_21 ) ;
F_11 ( V_4 -> V_34 , 0 ) ;
V_4 -> V_34 -> V_35 |= V_36 ;
F_12 ( V_2 , V_4 ) ;
return V_37 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_38 * V_39 )
{
int V_40 = 0 ;
V_40 |= F_14 ( & V_39 -> V_41 , V_42 ) ;
V_40 |= F_14 ( & V_39 -> V_43 , V_44 ) ;
V_40 |= F_14 ( & V_39 -> V_45 , V_46 ) ;
V_40 |= F_14 ( & V_39 -> V_47 , V_48 ) ;
V_40 |= F_14 ( & V_39 -> V_49 , V_48 ) ;
if ( V_40 )
return 1 ;
if ( V_40 )
return 2 ;
V_40 |= F_15 ( & V_39 -> V_50 , 0 ) ;
V_40 |= F_15 ( & V_39 -> V_51 , 0 ) ;
V_40 |= F_15 ( & V_39 -> V_52 , 0 ) ;
V_40 |= F_15 ( & V_39 -> V_53 , 1 ) ;
V_40 |= F_15 ( & V_39 -> V_54 , 0 ) ;
if ( V_40 )
return 3 ;
if ( V_40 )
return 4 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
F_3 ( V_32 | V_33 ,
V_9 -> V_18 -> V_19 + V_21 ) ;
F_3 ( V_55 | V_56 |
V_57 | V_58 ,
V_9 -> V_18 -> V_19 + V_59 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
F_3 ( 0x00 , V_9 -> V_18 -> V_19 + V_59 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
V_7 [ 1 ] = 0 ;
return V_6 -> V_14 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
if ( V_6 -> V_14 < 1 )
return - V_15 ;
if ( V_7 [ 0 ] != V_60 )
return - V_15 ;
F_3 ( V_7 [ 1 ] ,
V_9 -> V_18 -> V_19 + F_20 ( 0 ) ) ;
F_3 ( V_7 [ 1 ] >> 8 ,
V_9 -> V_18 -> V_19 + F_20 ( 1 ) ) ;
F_3 ( V_7 [ 1 ] >> 16 ,
V_9 -> V_18 -> V_19 + F_20 ( 2 ) ) ;
F_3 ( V_7 [ 2 ] ,
V_9 -> V_18 -> V_19 + F_21 ( 0 ) ) ;
F_3 ( V_7 [ 2 ] >> 8 ,
V_9 -> V_18 -> V_19 + F_21 ( 1 ) ) ;
F_3 ( V_7 [ 2 ] >> 16 ,
V_9 -> V_18 -> V_19 + F_21 ( 2 ) ) ;
return 2 ;
}
static int F_22 ( struct V_1 * V_2 ,
unsigned long V_61 )
{
struct V_62 * V_63 = F_23 ( V_2 ) ;
const struct V_64 * V_65 = NULL ;
struct V_8 * V_9 ;
struct V_3 * V_4 ;
int V_66 ;
if ( V_61 < F_24 ( V_67 ) )
V_65 = & V_67 [ V_61 ] ;
if ( ! V_65 )
return - V_68 ;
V_2 -> V_69 = V_65 ;
V_2 -> V_70 = V_65 -> V_71 ;
V_66 = F_25 ( V_2 ) ;
if ( V_66 )
return V_66 ;
V_9 = F_26 ( V_2 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_72 ;
V_9 -> V_18 = F_27 ( V_63 ) ;
if ( ! V_9 -> V_18 )
return - V_72 ;
V_66 = F_28 ( V_9 -> V_18 ) ;
if ( V_66 < 0 ) {
F_29 ( V_2 -> V_73 , L_1 ) ;
return V_66 ;
}
F_30 ( V_2 -> V_73 , L_2 , V_2 -> V_70 ,
F_7 ( V_9 -> V_18 -> V_19 + V_74 ) ) ;
V_66 = F_31 ( V_2 , 3 ) ;
if ( V_66 )
return V_66 ;
V_4 = & V_2 -> V_26 [ 0 ] ;
V_4 -> type = V_75 ;
V_4 -> V_76 = V_77 ;
V_4 -> V_78 = 24 ;
V_4 -> V_79 = & V_80 ;
V_4 -> V_81 = 1 ;
V_4 -> V_82 = F_1 ;
V_4 -> V_83 = F_6 ;
V_4 = & V_2 -> V_26 [ 1 ] ;
V_4 -> type = V_84 ;
V_4 -> V_76 = V_77 | V_85 ;
V_4 -> V_78 = 24 ;
V_4 -> V_79 = & V_86 ;
V_4 -> V_81 = 1 ;
V_4 -> V_83 = F_9 ;
V_4 = & V_2 -> V_26 [ 2 ] ;
V_2 -> V_87 = V_4 ;
V_4 -> type = V_75 ;
V_4 -> V_76 = V_77 | V_88 ;
V_4 -> V_78 = 1 ;
V_4 -> V_79 = & V_86 ;
V_4 -> V_81 = 1 ;
V_4 -> V_89 = F_13 ;
V_4 -> V_90 = F_16 ;
V_4 -> V_91 = F_17 ;
V_4 -> V_83 = F_18 ;
V_4 -> V_82 = F_19 ;
F_3 ( 0x00 , V_9 -> V_18 -> V_19 + F_5 ( 0 ) ) ;
F_3 ( 0x00 , V_9 -> V_18 -> V_19 + F_5 ( 1 ) ) ;
F_3 ( 0x00 , V_9 -> V_18 -> V_19 + F_5 ( 2 ) ) ;
F_3 ( V_32 | V_33 | V_92 | V_20 ,
V_9 -> V_18 -> V_19 + V_21 ) ;
F_3 ( 0x00 , V_9 -> V_18 -> V_19 + V_59 ) ;
V_66 = F_32 ( F_33 ( V_9 -> V_18 ) , F_10 ,
V_93 , V_94 , V_2 ) ;
if ( V_66 < 0 )
F_34 ( V_2 -> V_73 , L_3 ) ;
else
V_2 -> V_24 = F_33 ( V_9 -> V_18 ) ;
return 0 ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
if ( V_9 && V_9 -> V_18 && V_9 -> V_18 -> V_19 )
F_3 ( 0x00 ,
V_9 -> V_18 -> V_19 + V_59 ) ;
if ( V_2 -> V_24 )
F_36 ( V_2 -> V_24 , V_2 ) ;
if ( V_9 && V_9 -> V_18 ) {
F_37 ( V_9 -> V_18 ) ;
F_38 ( V_9 -> V_18 ) ;
}
F_39 ( V_2 ) ;
}
static int F_40 ( struct V_62 * V_2 ,
const struct V_95 * V_96 )
{
return F_41 ( V_2 , & V_97 , V_96 -> V_98 ) ;
}
