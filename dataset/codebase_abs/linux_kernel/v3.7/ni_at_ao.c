static void F_1 ( struct V_1 * V_2 )
{
V_3 -> V_4 = 0 ;
F_2 ( V_3 -> V_4 , V_2 -> V_5 + V_6 ) ;
F_3 ( V_7 | V_8 , V_2 -> V_5 + V_9 ) ;
F_3 ( 0x03 , V_2 -> V_5 + V_10 ) ;
F_3 ( V_11 | V_7 | V_8 , V_2 -> V_5 + V_9 ) ;
V_3 -> V_12 = 0 ;
F_2 ( V_3 -> V_12 , V_2 -> V_5 + V_13 ) ;
V_3 -> V_14 = 0 ;
F_2 ( V_3 -> V_14 , V_2 -> V_5 + V_15 ) ;
F_4 ( V_2 -> V_5 + V_16 ) ;
V_3 -> V_4 |= V_17 ;
F_2 ( V_3 -> V_4 , V_2 -> V_5 + V_6 ) ;
F_2 ( 0 , V_2 -> V_5 + V_18 ) ;
F_2 ( 0 , V_2 -> V_5 + V_19 ) ;
F_2 ( 0 , V_2 -> V_5 + V_20 ) ;
V_3 -> V_4 &= ~ V_17 ;
F_2 ( V_3 -> V_4 , V_2 -> V_5 + V_6 ) ;
}
static int F_5 ( struct V_1 * V_2 , struct V_21 * V_22 ,
struct V_23 * V_24 , unsigned int * V_25 )
{
int V_26 ;
int V_27 = F_6 ( V_24 -> V_28 ) ;
short V_29 ;
for ( V_26 = 0 ; V_26 < V_24 -> V_30 ; V_26 ++ ) {
V_29 = V_25 [ V_26 ] - 0x800 ;
if ( V_27 == 0 ) {
V_3 -> V_4 |= V_17 ;
F_2 ( V_3 -> V_4 , V_2 -> V_5 + V_6 ) ;
}
F_2 ( V_29 , V_2 -> V_5 + F_7 ( V_27 ) ) ;
if ( V_27 == 0 ) {
V_3 -> V_4 &= ~ V_17 ;
F_2 ( V_3 -> V_4 , V_2 -> V_5 + V_6 ) ;
}
V_3 -> V_31 [ V_27 ] = V_25 [ V_26 ] ;
}
return V_26 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_21 * V_22 ,
struct V_23 * V_24 , unsigned int * V_25 )
{
int V_26 ;
int V_27 = F_6 ( V_24 -> V_28 ) ;
for ( V_26 = 0 ; V_26 < V_24 -> V_30 ; V_26 ++ )
V_25 [ V_26 ] = V_3 -> V_31 [ V_27 ] ;
return V_26 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_23 * V_24 , unsigned int * V_25 )
{
if ( V_25 [ 0 ] ) {
V_22 -> V_32 &= ~ V_25 [ 0 ] ;
V_22 -> V_32 |= V_25 [ 0 ] & V_25 [ 1 ] ;
F_2 ( V_22 -> V_32 , V_2 -> V_5 + V_33 ) ;
}
V_25 [ 1 ] = F_4 ( V_2 -> V_5 + V_34 ) ;
return V_24 -> V_30 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_23 * V_24 , unsigned int * V_25 )
{
int V_27 = F_6 ( V_24 -> V_28 ) ;
unsigned int V_35 , V_36 ;
V_35 = ( V_27 < 4 ) ? 0x0f : 0xf0 ;
V_36 = ( V_27 < 4 ) ? V_37 : V_38 ;
switch ( V_25 [ 0 ] ) {
case V_39 :
V_22 -> V_40 |= V_35 ;
V_3 -> V_14 |= V_36 ;
break;
case V_41 :
V_22 -> V_40 &= ~ V_35 ;
V_3 -> V_14 &= ~ V_36 ;
break;
case V_42 :
V_25 [ 1 ] =
( V_22 -> V_40 & ( 1 << V_27 ) ) ? V_43 : V_44 ;
return V_24 -> V_30 ;
break;
default:
return - V_45 ;
break;
}
F_2 ( V_3 -> V_14 , V_2 -> V_5 + V_15 ) ;
return 1 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_23 * V_24 , unsigned int * V_25 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_24 -> V_30 ; V_26 ++ )
V_25 [ V_26 ] = 0 ;
return V_24 -> V_30 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_23 * V_24 , unsigned int * V_25 )
{
unsigned int V_46 , V_36 ;
unsigned int V_27 = F_6 ( V_24 -> V_28 ) ;
V_46 = ( ( V_27 & 0x7 ) << 8 ) | ( V_25 [ V_24 -> V_30 - 1 ] & 0xff ) ;
for ( V_36 = 1 << ( 11 - 1 ) ; V_36 ; V_36 >>= 1 ) {
F_2 ( V_3 -> V_12 | ( ( V_36 & V_46 ) ? V_47 : 0 ) ,
V_2 -> V_5 + V_13 ) ;
F_2 ( V_3 -> V_12 | V_48 | ( ( V_36 & V_46 ) ? V_47 : 0 ) ,
V_2 -> V_5 + V_13 ) ;
}
F_2 ( V_3 -> V_12 | ( ( ( V_27 >> 3 ) + 1 ) << 14 ) ,
V_2 -> V_5 + V_13 ) ;
F_2 ( V_3 -> V_12 , V_2 -> V_5 + V_13 ) ;
return V_24 -> V_30 ;
}
static int F_13 ( struct V_1 * V_2 , struct V_49 * V_50 )
{
const struct V_51 * V_52 = F_14 ( V_2 ) ;
struct V_21 * V_22 ;
unsigned long V_5 ;
int V_53 ;
int V_54 ;
V_5 = V_50 -> V_55 [ 0 ] ;
if ( V_5 == 0 )
V_5 = 0x1c0 ;
V_53 = V_50 -> V_55 [ 3 ] ;
F_15 ( V_56 L_1 , V_2 -> V_57 , V_5 ) ;
if ( ! F_16 ( V_5 , V_58 , L_2 ) ) {
F_15 ( L_3 ) ;
return - V_59 ;
}
V_2 -> V_5 = V_5 ;
V_2 -> V_60 = V_52 -> V_61 ;
if ( F_17 ( V_2 , sizeof( struct V_62 ) ) < 0 )
return - V_63 ;
V_54 = F_18 ( V_2 , 4 ) ;
if ( V_54 )
return V_54 ;
V_22 = & V_2 -> V_64 [ 0 ] ;
V_22 -> type = V_65 ;
V_22 -> V_66 = V_67 ;
V_22 -> V_68 = V_52 -> V_69 ;
V_22 -> V_70 = ( 1 << 12 ) - 1 ;
if ( V_53 )
V_22 -> V_71 = & V_72 ;
else
V_22 -> V_71 = & V_73 ;
V_22 -> V_74 = & F_5 ;
V_22 -> V_75 = & F_8 ;
V_22 = & V_2 -> V_64 [ 1 ] ;
V_22 -> type = V_76 ;
V_22 -> V_66 = V_77 | V_67 ;
V_22 -> V_68 = 8 ;
V_22 -> V_70 = 1 ;
V_22 -> V_71 = & V_78 ;
V_22 -> V_79 = F_9 ;
V_22 -> V_80 = F_10 ;
V_22 = & V_2 -> V_64 [ 2 ] ;
V_22 -> type = V_81 ;
V_22 -> V_66 = V_67 | V_82 ;
V_22 -> V_68 = 21 ;
V_22 -> V_70 = 0xff ;
V_22 -> V_75 = F_11 ;
V_22 -> V_74 = F_12 ;
V_22 = & V_2 -> V_64 [ 3 ] ;
V_22 -> type = V_83 ;
F_1 ( V_2 ) ;
F_15 ( V_56 L_4 ) ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 )
F_20 ( V_2 -> V_5 , V_58 ) ;
}
