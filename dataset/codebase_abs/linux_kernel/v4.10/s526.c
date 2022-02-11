static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
F_2 ( ( V_4 >> 16 ) & 0xffff , V_2 -> V_5 + F_3 ( V_3 ) ) ;
F_2 ( V_4 & 0xffff , V_2 -> V_5 + F_4 ( V_3 ) ) ;
}
static unsigned int F_5 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
unsigned int V_4 ;
V_4 = F_6 ( V_2 -> V_5 + F_4 ( V_3 ) ) & 0xffff ;
V_4 |= ( F_6 ( V_2 -> V_5 + F_3 ( V_3 ) ) & 0xff ) << 16 ;
return V_4 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_8 * V_9 ,
unsigned int * V_10 )
{
unsigned int V_3 = F_8 ( V_9 -> V_11 ) ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_9 -> V_13 ; V_12 ++ )
V_10 [ V_12 ] = F_5 ( V_2 , V_3 ) ;
return V_9 -> V_13 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_8 * V_9 ,
unsigned int * V_10 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
unsigned int V_3 = F_8 ( V_9 -> V_11 ) ;
unsigned int V_4 ;
switch ( V_10 [ 0 ] ) {
case V_17 :
V_15 -> V_18 [ V_3 ] = V_10 [ 0 ] ;
#if 1
V_4 = V_10 [ 1 ] & 0xffff ;
F_2 ( V_4 , V_2 -> V_5 + F_10 ( V_3 ) ) ;
if ( ( V_4 & V_19 ) ==
V_20 ) {
F_2 ( V_21 ,
V_2 -> V_5 + F_11 ( V_3 ) ) ;
}
#else
V_4 = V_22 ;
if ( V_10 [ 1 ] == V_23 )
V_4 |= V_24 ;
else if ( V_10 [ 1 ] == V_25 )
V_4 |= V_26 ;
else
V_4 |= V_27 ;
if ( V_10 [ 3 ] == V_28 ) {
V_4 |= V_29 ;
}
V_4 = V_10 [ 1 ] & 0xffff ;
F_2 ( V_4 , V_2 -> V_5 + F_10 ( V_3 ) ) ;
F_1 ( V_2 , V_3 , V_10 [ 2 ] ) ;
if ( V_10 [ 3 ] )
F_2 ( V_10 [ 3 ] & 0xffff ,
V_2 -> V_5 + F_11 ( V_3 ) ) ;
if ( ( V_4 & V_19 ) ==
V_20 ) {
F_2 ( V_21 ,
V_2 -> V_5 + F_11 ( V_3 ) ) ;
F_2 ( V_30 ,
V_2 -> V_5 + F_11 ( V_3 ) ) ;
}
#endif
break;
case V_31 :
V_15 -> V_18 [ V_3 ] = V_10 [ 0 ] ;
V_4 = V_10 [ 1 ] & 0xffff ;
V_4 &= ~ V_32 ;
V_4 |= V_33 ;
F_2 ( V_4 , V_2 -> V_5 + F_10 ( V_3 ) ) ;
F_1 ( V_2 , V_3 , V_10 [ 2 ] ) ;
V_4 = V_10 [ 1 ] & 0xffff ;
V_4 &= ~ V_32 ;
V_4 |= V_34 ;
F_2 ( V_4 , V_2 -> V_5 + F_10 ( V_3 ) ) ;
F_1 ( V_2 , V_3 , V_10 [ 3 ] ) ;
if ( V_10 [ 4 ] ) {
V_4 = V_10 [ 4 ] & 0xffff ;
F_2 ( V_4 , V_2 -> V_5 + F_11 ( V_3 ) ) ;
}
break;
case V_35 :
V_15 -> V_18 [ V_3 ] = V_10 [ 0 ] ;
V_4 = V_10 [ 1 ] & 0xffff ;
V_4 &= ~ V_32 ;
V_4 |= V_33 ;
F_2 ( V_4 , V_2 -> V_5 + F_10 ( V_3 ) ) ;
F_1 ( V_2 , V_3 , V_10 [ 2 ] ) ;
V_4 = V_10 [ 1 ] & 0xffff ;
V_4 &= ~ V_32 ;
V_4 |= V_34 ;
F_2 ( V_4 , V_2 -> V_5 + F_10 ( V_3 ) ) ;
F_1 ( V_2 , V_3 , V_10 [ 3 ] ) ;
if ( V_10 [ 4 ] ) {
V_4 = V_10 [ 4 ] & 0xffff ;
F_2 ( V_4 , V_2 -> V_5 + F_11 ( V_3 ) ) ;
}
break;
default:
return - V_36 ;
}
return V_9 -> V_13 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_8 * V_9 ,
unsigned int * V_10 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
unsigned int V_3 = F_8 ( V_9 -> V_11 ) ;
F_6 ( V_2 -> V_5 + F_10 ( V_3 ) ) ;
switch ( V_15 -> V_18 [ V_3 ] ) {
case V_35 :
if ( ( V_10 [ 1 ] <= V_10 [ 0 ] ) || ! V_10 [ 0 ] )
return - V_36 ;
case V_17 :
case V_31 :
F_1 ( V_2 , V_3 , V_10 [ 0 ] ) ;
break;
default:
return - V_36 ;
}
return V_9 -> V_13 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_8 * V_9 ,
unsigned long V_37 )
{
unsigned int V_38 ;
V_38 = F_6 ( V_2 -> V_5 + V_39 ) ;
if ( V_38 & V_37 ) {
F_2 ( V_37 , V_2 -> V_5 + V_39 ) ;
return 0 ;
}
return - V_40 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_8 * V_9 ,
unsigned int * V_10 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
unsigned int V_3 = F_8 ( V_9 -> V_11 ) ;
unsigned int V_41 ;
unsigned int V_4 ;
int V_42 ;
int V_12 ;
V_41 = F_15 ( V_3 ) | F_16 ( V_3 ) |
V_43 ;
if ( V_41 != V_15 -> V_44 ) {
V_15 -> V_44 = V_41 ;
V_41 |= V_45 ;
}
for ( V_12 = 0 ; V_12 < V_9 -> V_13 ; V_12 ++ ) {
F_2 ( V_41 , V_2 -> V_5 + V_46 ) ;
V_41 &= ~ V_45 ;
V_42 = F_17 ( V_2 , V_7 , V_9 , F_13 , V_47 ) ;
if ( V_42 )
return V_42 ;
V_4 = F_6 ( V_2 -> V_5 + V_48 ) ;
V_10 [ V_12 ] = F_18 ( V_7 , V_4 ) ;
}
return V_9 -> V_13 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_8 * V_9 ,
unsigned int * V_10 )
{
unsigned int V_3 = F_8 ( V_9 -> V_11 ) ;
unsigned int V_41 = F_20 ( V_3 ) ;
unsigned int V_4 = V_7 -> V_49 [ V_3 ] ;
int V_42 ;
int V_12 ;
F_2 ( V_41 , V_2 -> V_5 + V_50 ) ;
V_41 |= V_51 ;
for ( V_12 = 0 ; V_12 < V_9 -> V_13 ; V_12 ++ ) {
V_4 = V_10 [ V_12 ] ;
F_2 ( V_4 , V_2 -> V_5 + V_52 ) ;
F_2 ( V_41 , V_2 -> V_5 + V_50 ) ;
V_42 = F_17 ( V_2 , V_7 , V_9 , F_13 , V_53 ) ;
if ( V_42 )
return V_42 ;
}
V_7 -> V_49 [ V_3 ] = V_4 ;
return V_9 -> V_13 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_8 * V_9 ,
unsigned int * V_10 )
{
if ( F_22 ( V_7 , V_10 ) )
F_2 ( V_7 -> V_54 , V_2 -> V_5 + V_55 ) ;
V_10 [ 1 ] = F_6 ( V_2 -> V_5 + V_55 ) & 0xff ;
return V_9 -> V_13 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_8 * V_9 ,
unsigned int * V_10 )
{
unsigned int V_3 = F_8 ( V_9 -> V_11 ) ;
unsigned int V_56 ;
int V_42 ;
if ( V_3 < 4 )
V_56 = 0x0f ;
else
V_56 = 0xf0 ;
V_42 = F_24 ( V_2 , V_7 , V_9 , V_10 , V_56 ) ;
if ( V_42 )
return V_42 ;
if ( V_7 -> V_57 & 0x0f )
V_7 -> V_54 |= V_58 ;
else
V_7 -> V_54 &= ~ V_58 ;
if ( V_7 -> V_57 & 0xf0 )
V_7 -> V_54 |= V_59 ;
else
V_7 -> V_54 &= ~ V_59 ;
F_2 ( V_7 -> V_54 , V_2 -> V_5 + V_55 ) ;
return V_9 -> V_13 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_60 * V_61 )
{
struct V_14 * V_15 ;
struct V_6 * V_7 ;
int V_42 ;
V_42 = F_26 ( V_2 , V_61 -> V_62 [ 0 ] , 0x40 ) ;
if ( V_42 )
return V_42 ;
V_15 = F_27 ( V_2 , sizeof( * V_15 ) ) ;
if ( ! V_15 )
return - V_63 ;
V_42 = F_28 ( V_2 , 4 ) ;
if ( V_42 )
return V_42 ;
V_7 = & V_2 -> V_64 [ 0 ] ;
V_7 -> type = V_65 ;
V_7 -> V_66 = V_67 | V_68 | V_69 ;
V_7 -> V_70 = 4 ;
V_7 -> V_71 = 0x00ffffff ;
V_7 -> V_72 = F_7 ;
V_7 -> V_73 = F_9 ;
V_7 -> V_74 = F_12 ;
V_7 = & V_2 -> V_64 [ 1 ] ;
V_7 -> type = V_75 ;
V_7 -> V_66 = V_67 | V_76 ;
V_7 -> V_70 = 10 ;
V_7 -> V_71 = 0xffff ;
V_7 -> V_77 = & V_78 ;
V_7 -> V_79 = 16 ;
V_7 -> V_72 = F_14 ;
V_7 = & V_2 -> V_64 [ 2 ] ;
V_7 -> type = V_80 ;
V_7 -> V_66 = V_68 ;
V_7 -> V_70 = 4 ;
V_7 -> V_71 = 0xffff ;
V_7 -> V_77 = & V_78 ;
V_7 -> V_74 = F_19 ;
V_42 = F_29 ( V_7 ) ;
if ( V_42 )
return V_42 ;
V_7 = & V_2 -> V_64 [ 3 ] ;
V_7 -> type = V_81 ;
V_7 -> V_66 = V_67 | V_68 ;
V_7 -> V_70 = 8 ;
V_7 -> V_71 = 1 ;
V_7 -> V_77 = & V_82 ;
V_7 -> V_83 = F_21 ;
V_7 -> V_73 = F_23 ;
return 0 ;
}
