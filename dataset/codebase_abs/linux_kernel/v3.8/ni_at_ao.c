static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_6 = 0 ;
F_2 ( V_4 -> V_6 , V_2 -> V_7 + V_8 ) ;
F_3 ( V_9 | V_10 , V_2 -> V_7 + V_11 ) ;
F_3 ( 0x03 , V_2 -> V_7 + V_12 ) ;
F_3 ( V_13 | V_9 | V_10 , V_2 -> V_7 + V_11 ) ;
V_4 -> V_14 = 0 ;
F_2 ( V_4 -> V_14 , V_2 -> V_7 + V_15 ) ;
V_4 -> V_16 = 0 ;
F_2 ( V_4 -> V_16 , V_2 -> V_7 + V_17 ) ;
F_4 ( V_2 -> V_7 + V_18 ) ;
V_4 -> V_6 |= V_19 ;
F_2 ( V_4 -> V_6 , V_2 -> V_7 + V_8 ) ;
F_2 ( 0 , V_2 -> V_7 + V_20 ) ;
F_2 ( 0 , V_2 -> V_7 + V_21 ) ;
F_2 ( 0 , V_2 -> V_7 + V_22 ) ;
V_4 -> V_6 &= ~ V_19 ;
F_2 ( V_4 -> V_6 , V_2 -> V_7 + V_8 ) ;
}
static int F_5 ( struct V_1 * V_2 , struct V_23 * V_24 ,
struct V_25 * V_26 , unsigned int * V_27 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_28 ;
int V_29 = F_6 ( V_26 -> V_30 ) ;
short V_31 ;
for ( V_28 = 0 ; V_28 < V_26 -> V_32 ; V_28 ++ ) {
V_31 = V_27 [ V_28 ] - 0x800 ;
if ( V_29 == 0 ) {
V_4 -> V_6 |= V_19 ;
F_2 ( V_4 -> V_6 , V_2 -> V_7 + V_8 ) ;
}
F_2 ( V_31 , V_2 -> V_7 + F_7 ( V_29 ) ) ;
if ( V_29 == 0 ) {
V_4 -> V_6 &= ~ V_19 ;
F_2 ( V_4 -> V_6 , V_2 -> V_7 + V_8 ) ;
}
V_4 -> V_33 [ V_29 ] = V_27 [ V_28 ] ;
}
return V_28 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_23 * V_24 ,
struct V_25 * V_26 , unsigned int * V_27 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_28 ;
int V_29 = F_6 ( V_26 -> V_30 ) ;
for ( V_28 = 0 ; V_28 < V_26 -> V_32 ; V_28 ++ )
V_27 [ V_28 ] = V_4 -> V_33 [ V_29 ] ;
return V_28 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_25 * V_26 , unsigned int * V_27 )
{
if ( V_27 [ 0 ] ) {
V_24 -> V_34 &= ~ V_27 [ 0 ] ;
V_24 -> V_34 |= V_27 [ 0 ] & V_27 [ 1 ] ;
F_2 ( V_24 -> V_34 , V_2 -> V_7 + V_35 ) ;
}
V_27 [ 1 ] = F_4 ( V_2 -> V_7 + V_36 ) ;
return V_26 -> V_32 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_25 * V_26 , unsigned int * V_27 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_29 = F_6 ( V_26 -> V_30 ) ;
unsigned int V_37 , V_38 ;
V_37 = ( V_29 < 4 ) ? 0x0f : 0xf0 ;
V_38 = ( V_29 < 4 ) ? V_39 : V_40 ;
switch ( V_27 [ 0 ] ) {
case V_41 :
V_24 -> V_42 |= V_37 ;
V_4 -> V_16 |= V_38 ;
break;
case V_43 :
V_24 -> V_42 &= ~ V_37 ;
V_4 -> V_16 &= ~ V_38 ;
break;
case V_44 :
V_27 [ 1 ] =
( V_24 -> V_42 & ( 1 << V_29 ) ) ? V_45 : V_46 ;
return V_26 -> V_32 ;
break;
default:
return - V_47 ;
break;
}
F_2 ( V_4 -> V_16 , V_2 -> V_7 + V_17 ) ;
return 1 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_25 * V_26 , unsigned int * V_27 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_26 -> V_32 ; V_28 ++ )
V_27 [ V_28 ] = 0 ;
return V_26 -> V_32 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_25 * V_26 , unsigned int * V_27 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_48 , V_38 ;
unsigned int V_29 = F_6 ( V_26 -> V_30 ) ;
V_48 = ( ( V_29 & 0x7 ) << 8 ) | ( V_27 [ V_26 -> V_32 - 1 ] & 0xff ) ;
for ( V_38 = 1 << ( 11 - 1 ) ; V_38 ; V_38 >>= 1 ) {
F_2 ( V_4 -> V_14 | ( ( V_38 & V_48 ) ? V_49 : 0 ) ,
V_2 -> V_7 + V_15 ) ;
F_2 ( V_4 -> V_14 | V_50 | ( ( V_38 & V_48 ) ? V_49 : 0 ) ,
V_2 -> V_7 + V_15 ) ;
}
F_2 ( V_4 -> V_14 | ( ( ( V_29 >> 3 ) + 1 ) << 14 ) ,
V_2 -> V_7 + V_15 ) ;
F_2 ( V_4 -> V_14 , V_2 -> V_7 + V_15 ) ;
return V_26 -> V_32 ;
}
static int F_13 ( struct V_1 * V_2 , struct V_51 * V_52 )
{
const struct V_53 * V_54 = F_14 ( V_2 ) ;
struct V_3 * V_4 ;
struct V_23 * V_24 ;
unsigned long V_7 ;
int V_55 ;
int V_56 ;
V_7 = V_52 -> V_57 [ 0 ] ;
if ( V_7 == 0 )
V_7 = 0x1c0 ;
V_55 = V_52 -> V_57 [ 3 ] ;
F_15 ( V_58 L_1 , V_2 -> V_59 , V_7 ) ;
if ( ! F_16 ( V_7 , V_60 , L_2 ) ) {
F_15 ( L_3 ) ;
return - V_61 ;
}
V_2 -> V_7 = V_7 ;
V_2 -> V_62 = V_54 -> V_63 ;
V_4 = F_17 ( sizeof( * V_4 ) , V_64 ) ;
if ( ! V_4 )
return - V_65 ;
V_2 -> V_5 = V_4 ;
V_56 = F_18 ( V_2 , 4 ) ;
if ( V_56 )
return V_56 ;
V_24 = & V_2 -> V_66 [ 0 ] ;
V_24 -> type = V_67 ;
V_24 -> V_68 = V_69 ;
V_24 -> V_70 = V_54 -> V_71 ;
V_24 -> V_72 = ( 1 << 12 ) - 1 ;
if ( V_55 )
V_24 -> V_73 = & V_74 ;
else
V_24 -> V_73 = & V_75 ;
V_24 -> V_76 = & F_5 ;
V_24 -> V_77 = & F_8 ;
V_24 = & V_2 -> V_66 [ 1 ] ;
V_24 -> type = V_78 ;
V_24 -> V_68 = V_79 | V_69 ;
V_24 -> V_70 = 8 ;
V_24 -> V_72 = 1 ;
V_24 -> V_73 = & V_80 ;
V_24 -> V_81 = F_9 ;
V_24 -> V_82 = F_10 ;
V_24 = & V_2 -> V_66 [ 2 ] ;
V_24 -> type = V_83 ;
V_24 -> V_68 = V_69 | V_84 ;
V_24 -> V_70 = 21 ;
V_24 -> V_72 = 0xff ;
V_24 -> V_77 = F_11 ;
V_24 -> V_76 = F_12 ;
V_24 = & V_2 -> V_66 [ 3 ] ;
V_24 -> type = V_85 ;
F_1 ( V_2 ) ;
F_15 ( V_58 L_4 ) ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
if ( V_2 -> V_7 )
F_20 ( V_2 -> V_7 , V_60 ) ;
}
