static int F_1 ( int V_1 , int V_2 , int V_3 , unsigned long V_4 )
{
if ( V_1 ) {
F_2 ( V_3 , V_4 + V_2 ) ;
return 0 ;
} else {
return F_3 ( V_4 + V_2 ) ;
}
}
void F_4 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
unsigned long V_4 = V_10 -> V_4 ;
short V_12 ;
V_12 = V_10 -> V_13 ( 0 , V_14 , 0 , V_4 ) ;
V_12 |= ( V_10 -> V_13 ( 0 , V_14 + 1 , 0 , V_4 ) << 8 ) ;
F_5 ( V_8 -> V_15 , V_12 ) ;
V_8 -> V_15 -> V_16 |= V_17 ;
F_6 ( V_6 , V_8 ) ;
}
static int F_7 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned int * V_3 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
unsigned long V_4 = V_10 -> V_4 ;
unsigned int V_20 ;
unsigned int V_21 ;
unsigned int V_22 ;
V_20 = V_3 [ 0 ] ;
V_21 = V_3 [ 1 ] ;
if ( V_20 ) {
V_22 = V_8 -> V_23 ;
V_22 &= ~ V_20 ;
V_22 |= ( V_21 & V_20 ) ;
if ( V_20 & 0xff )
V_10 -> V_13 ( 1 , V_14 , V_22 & 0xff , V_4 ) ;
if ( V_20 & 0xff00 )
V_10 -> V_13 ( 1 , V_14 + 1 , ( V_22 >> 8 ) & 0xff , V_4 ) ;
if ( V_20 & 0xff0000 )
V_10 -> V_13 ( 1 , V_14 + 2 , ( V_22 >> 16 ) & 0xff , V_4 ) ;
V_8 -> V_23 = V_22 ;
}
V_22 = V_10 -> V_13 ( 0 , V_14 , 0 , V_4 ) ;
V_22 |= ( V_10 -> V_13 ( 0 , V_14 + 1 , 0 , V_4 ) << 8 ) ;
V_22 |= ( V_10 -> V_13 ( 0 , V_14 + 2 , 0 , V_4 ) << 16 ) ;
V_3 [ 1 ] = V_22 ;
return V_19 -> V_24 ;
}
static void F_8 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
unsigned long V_4 = V_10 -> V_4 ;
int V_25 ;
V_25 = V_26 ;
if ( ! ( V_8 -> V_27 & 0x0000ff ) )
V_25 |= V_28 ;
if ( ! ( V_8 -> V_27 & 0x00ff00 ) )
V_25 |= V_29 ;
if ( ! ( V_8 -> V_27 & 0x0f0000 ) )
V_25 |= V_30 ;
if ( ! ( V_8 -> V_27 & 0xf00000 ) )
V_25 |= V_31 ;
V_10 -> V_13 ( 1 , V_32 , V_25 , V_4 ) ;
}
static int F_9 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_18 * V_19 , unsigned int * V_3 )
{
unsigned int V_20 ;
unsigned int V_21 ;
V_20 = 1 << F_10 ( V_19 -> V_33 ) ;
if ( V_20 & 0x0000ff )
V_21 = 0x0000ff ;
else if ( V_20 & 0x00ff00 )
V_21 = 0x00ff00 ;
else if ( V_20 & 0x0f0000 )
V_21 = 0x0f0000 ;
else
V_21 = 0xf00000 ;
switch ( V_3 [ 0 ] ) {
case V_34 :
V_8 -> V_27 &= ~ V_21 ;
break;
case V_35 :
V_8 -> V_27 |= V_21 ;
break;
case V_36 :
V_3 [ 1 ] = ( V_8 -> V_27 & V_21 ) ? V_37 : V_38 ;
return V_19 -> V_24 ;
break;
default:
return - V_39 ;
}
F_8 ( V_6 , V_8 ) ;
return 1 ;
}
static int F_11 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_40 * V_41 )
{
int V_42 = 0 ;
V_42 |= F_12 ( & V_41 -> V_43 , V_44 ) ;
V_42 |= F_12 ( & V_41 -> V_45 , V_46 ) ;
V_42 |= F_12 ( & V_41 -> V_47 , V_48 ) ;
V_42 |= F_12 ( & V_41 -> V_49 , V_50 ) ;
V_42 |= F_12 ( & V_41 -> V_51 , V_52 ) ;
if ( V_42 )
return 1 ;
if ( V_42 )
return 2 ;
V_42 |= F_13 ( & V_41 -> V_53 , 0 ) ;
V_42 |= F_13 ( & V_41 -> V_54 , 0 ) ;
V_42 |= F_13 ( & V_41 -> V_55 , 0 ) ;
V_42 |= F_13 ( & V_41 -> V_56 , 1 ) ;
V_42 |= F_13 ( & V_41 -> V_57 , 0 ) ;
if ( V_42 )
return 3 ;
if ( V_42 )
return 4 ;
return 0 ;
}
static int F_14 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
return 0 ;
}
static int F_15 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
return 0 ;
}
int F_16 ( struct V_5 * V_6 , struct V_7 * V_8 ,
int (* V_13) ( int , int , int , unsigned long ) ,
unsigned long V_4 )
{
struct V_9 * V_10 ;
V_10 = F_17 ( V_8 , sizeof( * V_10 ) ) ;
if ( ! V_10 )
return - V_58 ;
V_10 -> V_4 = V_4 ;
V_10 -> V_13 = V_13 ? V_13 : F_1 ;
V_8 -> type = V_59 ;
V_8 -> V_60 = V_61 | V_62 ;
V_8 -> V_63 = 24 ;
V_8 -> V_64 = & V_65 ;
V_8 -> V_66 = 1 ;
V_8 -> V_67 = F_7 ;
V_8 -> V_68 = F_9 ;
V_8 -> V_23 = 0 ;
V_8 -> V_27 = 0 ;
F_8 ( V_6 , V_8 ) ;
return 0 ;
}
int F_18 ( struct V_5 * V_6 , struct V_7 * V_8 ,
int (* V_13) ( int , int , int , unsigned long ) ,
unsigned long V_4 )
{
int V_69 ;
V_69 = F_16 ( V_6 , V_8 , V_13 , V_4 ) ;
if ( V_69 )
return V_69 ;
V_8 -> V_70 = F_11 ;
V_8 -> V_71 = F_14 ;
V_8 -> V_72 = F_15 ;
return 0 ;
}
static int F_19 ( struct V_5 * V_6 ,
struct V_73 * V_74 )
{
struct V_7 * V_8 ;
int V_69 ;
unsigned long V_4 ;
int V_75 ;
for ( V_75 = 0 ; V_75 < V_76 ; V_75 ++ ) {
V_4 = V_74 -> V_77 [ V_75 ] ;
if ( ! V_4 )
break;
}
if ( V_75 == 0 ) {
F_20 ( V_6 -> V_78 , L_1 ) ;
return - V_39 ;
}
V_69 = F_21 ( V_6 , V_75 ) ;
if ( V_69 )
return V_69 ;
for ( V_75 = 0 ; V_75 < V_6 -> V_79 ; V_75 ++ ) {
V_8 = & V_6 -> V_80 [ V_75 ] ;
V_4 = V_74 -> V_77 [ V_75 ] ;
V_69 = F_22 ( V_6 , V_4 , V_81 ) ;
if ( V_69 ) {
V_8 -> type = V_82 ;
} else {
V_69 = F_16 ( V_6 , V_8 , NULL , V_4 ) ;
if ( V_69 )
return V_69 ;
}
}
return 0 ;
}
static void F_23 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
int V_75 ;
for ( V_75 = 0 ; V_75 < V_6 -> V_79 ; V_75 ++ ) {
V_8 = & V_6 -> V_80 [ V_75 ] ;
if ( V_8 -> type != V_82 ) {
V_10 = V_8 -> V_11 ;
F_24 ( V_10 -> V_4 , V_81 ) ;
}
}
}
