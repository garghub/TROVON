static int T_1 F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
static void T_2 F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static int F_5 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_6 * V_7 ;
unsigned long V_8 ;
int V_9 ;
V_8 = V_5 -> V_10 [ 0 ] ;
if ( V_8 == 0 )
V_8 = 0x1c0 ;
V_9 = V_5 -> V_10 [ 3 ] ;
F_6 ( V_11 L_1 , V_3 -> V_12 , V_8 ) ;
if ( ! F_7 ( V_8 , V_13 , L_2 ) ) {
F_6 ( L_3 ) ;
return - V_14 ;
}
V_3 -> V_8 = V_8 ;
V_3 -> V_15 = V_16 -> V_17 ;
if ( F_8 ( V_3 , sizeof( struct V_18 ) ) < 0 )
return - V_19 ;
if ( F_9 ( V_3 , 4 ) < 0 )
return - V_19 ;
V_7 = V_3 -> V_20 + 0 ;
V_7 -> type = V_21 ;
V_7 -> V_22 = V_23 ;
V_7 -> V_24 = V_16 -> V_25 ;
V_7 -> V_26 = ( 1 << 12 ) - 1 ;
if ( V_9 )
V_7 -> V_27 = & V_28 ;
else
V_7 -> V_27 = & V_29 ;
V_7 -> V_30 = & V_31 ;
V_7 -> V_32 = & V_33 ;
V_7 = V_3 -> V_20 + 1 ;
V_7 -> type = V_34 ;
V_7 -> V_22 = V_35 | V_23 ;
V_7 -> V_24 = 8 ;
V_7 -> V_26 = 1 ;
V_7 -> V_27 = & V_36 ;
V_7 -> V_37 = V_38 ;
V_7 -> V_39 = V_40 ;
V_7 = V_3 -> V_20 + 2 ;
V_7 -> type = V_41 ;
V_7 -> V_22 = V_23 | V_42 ;
V_7 -> V_24 = 21 ;
V_7 -> V_26 = 0xff ;
V_7 -> V_32 = V_43 ;
V_7 -> V_30 = V_44 ;
V_7 = V_3 -> V_20 + 3 ;
V_7 -> type = V_45 ;
F_10 ( V_3 ) ;
F_6 ( V_11 L_4 ) ;
return 0 ;
}
static int F_11 ( struct V_2 * V_3 )
{
F_6 ( V_11 L_5 , V_3 -> V_12 ) ;
if ( V_3 -> V_8 )
F_12 ( V_3 -> V_8 , V_13 ) ;
return 0 ;
}
static void F_10 ( struct V_2 * V_3 )
{
V_46 -> V_47 = 0 ;
F_13 ( V_46 -> V_47 , V_3 -> V_8 + V_48 ) ;
F_14 ( V_49 | V_50 , V_3 -> V_8 + V_51 ) ;
F_14 ( 0x03 , V_3 -> V_8 + V_52 ) ;
F_14 ( V_53 | V_49 | V_50 , V_3 -> V_8 + V_51 ) ;
V_46 -> V_54 = 0 ;
F_13 ( V_46 -> V_54 , V_3 -> V_8 + V_55 ) ;
V_46 -> V_56 = 0 ;
F_13 ( V_46 -> V_56 , V_3 -> V_8 + V_57 ) ;
F_15 ( V_3 -> V_8 + V_58 ) ;
V_46 -> V_47 |= V_59 ;
F_13 ( V_46 -> V_47 , V_3 -> V_8 + V_48 ) ;
F_13 ( 0 , V_3 -> V_8 + V_60 ) ;
F_13 ( 0 , V_3 -> V_8 + V_61 ) ;
F_13 ( 0 , V_3 -> V_8 + V_62 ) ;
V_46 -> V_47 &= ~ V_59 ;
F_13 ( V_46 -> V_47 , V_3 -> V_8 + V_48 ) ;
}
static int V_31 ( struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_63 * V_64 , unsigned int * V_65 )
{
int V_66 ;
int V_67 = F_16 ( V_64 -> V_68 ) ;
short V_69 ;
for ( V_66 = 0 ; V_66 < V_64 -> V_70 ; V_66 ++ ) {
V_69 = V_65 [ V_66 ] - 0x800 ;
if ( V_67 == 0 ) {
V_46 -> V_47 |= V_59 ;
F_13 ( V_46 -> V_47 , V_3 -> V_8 + V_48 ) ;
}
F_13 ( V_69 , V_3 -> V_8 + F_17 ( V_67 ) ) ;
if ( V_67 == 0 ) {
V_46 -> V_47 &= ~ V_59 ;
F_13 ( V_46 -> V_47 , V_3 -> V_8 + V_48 ) ;
}
V_46 -> V_71 [ V_67 ] = V_65 [ V_66 ] ;
}
return V_66 ;
}
static int V_33 ( struct V_2 * V_3 , struct V_6 * V_7 ,
struct V_63 * V_64 , unsigned int * V_65 )
{
int V_66 ;
int V_67 = F_16 ( V_64 -> V_68 ) ;
for ( V_66 = 0 ; V_66 < V_64 -> V_70 ; V_66 ++ )
V_65 [ V_66 ] = V_46 -> V_71 [ V_67 ] ;
return V_66 ;
}
static int V_38 ( struct V_2 * V_3 ,
struct V_6 * V_7 ,
struct V_63 * V_64 , unsigned int * V_65 )
{
if ( V_64 -> V_70 != 2 )
return - V_72 ;
if ( V_65 [ 0 ] ) {
V_7 -> V_73 &= ~ V_65 [ 0 ] ;
V_7 -> V_73 |= V_65 [ 0 ] & V_65 [ 1 ] ;
F_13 ( V_7 -> V_73 , V_3 -> V_8 + V_74 ) ;
}
V_65 [ 1 ] = F_15 ( V_3 -> V_8 + V_75 ) ;
return 2 ;
}
static int V_40 ( struct V_2 * V_3 ,
struct V_6 * V_7 ,
struct V_63 * V_64 , unsigned int * V_65 )
{
int V_67 = F_16 ( V_64 -> V_68 ) ;
unsigned int V_76 , V_77 ;
V_76 = ( V_67 < 4 ) ? 0x0f : 0xf0 ;
V_77 = ( V_67 < 4 ) ? V_78 : V_79 ;
switch ( V_65 [ 0 ] ) {
case V_80 :
V_7 -> V_81 |= V_76 ;
V_46 -> V_56 |= V_77 ;
break;
case V_82 :
V_7 -> V_81 &= ~ V_76 ;
V_46 -> V_56 &= ~ V_77 ;
break;
case V_83 :
V_65 [ 1 ] =
( V_7 -> V_81 & ( 1 << V_67 ) ) ? V_84 : V_85 ;
return V_64 -> V_70 ;
break;
default:
return - V_72 ;
break;
}
F_13 ( V_46 -> V_56 , V_3 -> V_8 + V_57 ) ;
return 1 ;
}
static int V_43 ( struct V_2 * V_3 ,
struct V_6 * V_7 ,
struct V_63 * V_64 , unsigned int * V_65 )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < V_64 -> V_70 ; V_66 ++ )
V_65 [ V_66 ] = 0 ;
return V_64 -> V_70 ;
}
static int V_44 ( struct V_2 * V_3 ,
struct V_6 * V_7 ,
struct V_63 * V_64 , unsigned int * V_65 )
{
unsigned int V_86 , V_77 ;
unsigned int V_67 = F_16 ( V_64 -> V_68 ) ;
V_86 = ( ( V_67 & 0x7 ) << 8 ) | ( V_65 [ V_64 -> V_70 - 1 ] & 0xff ) ;
for ( V_77 = 1 << ( 11 - 1 ) ; V_77 ; V_77 >>= 1 ) {
F_13 ( V_46 -> V_54 | ( ( V_77 & V_86 ) ? V_87 : 0 ) ,
V_3 -> V_8 + V_55 ) ;
F_13 ( V_46 -> V_54 | V_88 | ( ( V_77 & V_86 ) ? V_87 : 0 ) ,
V_3 -> V_8 + V_55 ) ;
}
F_13 ( V_46 -> V_54 | ( ( ( V_67 >> 3 ) + 1 ) << 14 ) ,
V_3 -> V_8 + V_55 ) ;
F_13 ( V_46 -> V_54 , V_3 -> V_8 + V_55 ) ;
return V_64 -> V_70 ;
}
