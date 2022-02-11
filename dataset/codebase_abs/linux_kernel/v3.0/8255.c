static int T_1 F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
static void T_2 F_3 ( void )
{
F_4 ( & V_1 ) ;
}
void F_5 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
short V_6 ;
V_6 = F_6 ( 0 , V_7 , 0 , V_8 ) ;
V_6 |= ( F_6 ( 0 , V_7 + 1 , 0 , V_8 ) << 8 ) ;
F_7 ( V_5 -> V_9 , V_6 ) ;
V_5 -> V_9 -> V_10 |= V_11 ;
F_8 ( V_3 , V_5 ) ;
}
static int F_9 ( int V_12 , int V_13 , int V_14 , unsigned long V_15 )
{
unsigned long V_16 = V_15 ;
if ( V_12 ) {
F_10 ( V_14 , V_16 + V_13 ) ;
return 0 ;
} else {
return F_11 ( V_16 + V_13 ) ;
}
}
static int F_12 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_17 * V_18 , unsigned int * V_14 )
{
if ( V_14 [ 0 ] ) {
V_5 -> V_19 &= ~ V_14 [ 0 ] ;
V_5 -> V_19 |= ( V_14 [ 0 ] & V_14 [ 1 ] ) ;
if ( V_14 [ 0 ] & 0xff )
F_6 ( 1 , V_7 , V_5 -> V_19 & 0xff ,
V_8 ) ;
if ( V_14 [ 0 ] & 0xff00 )
F_6 ( 1 , V_7 + 1 , ( V_5 -> V_19 >> 8 ) & 0xff ,
V_8 ) ;
if ( V_14 [ 0 ] & 0xff0000 )
F_6 ( 1 , V_7 + 2 ,
( V_5 -> V_19 >> 16 ) & 0xff , V_8 ) ;
}
V_14 [ 1 ] = F_6 ( 0 , V_7 , 0 , V_8 ) ;
V_14 [ 1 ] |= ( F_6 ( 0 , V_7 + 1 , 0 , V_8 ) << 8 ) ;
V_14 [ 1 ] |= ( F_6 ( 0 , V_7 + 2 , 0 , V_8 ) << 16 ) ;
return 2 ;
}
static int F_13 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_17 * V_18 , unsigned int * V_14 )
{
unsigned int V_20 ;
unsigned int V_21 ;
V_20 = 1 << F_14 ( V_18 -> V_22 ) ;
if ( V_20 & 0x0000ff )
V_21 = 0x0000ff ;
else if ( V_20 & 0x00ff00 )
V_21 = 0x00ff00 ;
else if ( V_20 & 0x0f0000 )
V_21 = 0x0f0000 ;
else
V_21 = 0xf00000 ;
switch ( V_14 [ 0 ] ) {
case V_23 :
V_5 -> V_24 &= ~ V_21 ;
break;
case V_25 :
V_5 -> V_24 |= V_21 ;
break;
case V_26 :
V_14 [ 1 ] = ( V_5 -> V_24 & V_21 ) ? V_27 : V_28 ;
return V_18 -> V_29 ;
break;
default:
return - V_30 ;
}
F_15 ( V_3 , V_5 ) ;
return 1 ;
}
static void F_15 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
int V_31 ;
V_31 = V_32 ;
if ( ! ( V_5 -> V_24 & 0x0000ff ) )
V_31 |= V_33 ;
if ( ! ( V_5 -> V_24 & 0x00ff00 ) )
V_31 |= V_34 ;
if ( ! ( V_5 -> V_24 & 0x0f0000 ) )
V_31 |= V_35 ;
if ( ! ( V_5 -> V_24 & 0xf00000 ) )
V_31 |= V_36 ;
F_6 ( 1 , V_37 , V_31 , V_8 ) ;
}
static int F_16 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_38 * V_39 )
{
int V_40 = 0 ;
unsigned int V_41 ;
V_41 = V_39 -> V_42 ;
V_39 -> V_42 &= V_43 ;
if ( ! V_39 -> V_42 || V_41 != V_39 -> V_42 )
V_40 ++ ;
V_41 = V_39 -> V_44 ;
V_39 -> V_44 &= V_45 ;
if ( ! V_39 -> V_44 || V_41 != V_39 -> V_44 )
V_40 ++ ;
V_41 = V_39 -> V_46 ;
V_39 -> V_46 &= V_47 ;
if ( ! V_39 -> V_46 || V_41 != V_39 -> V_46 )
V_40 ++ ;
V_41 = V_39 -> V_48 ;
V_39 -> V_48 &= V_49 ;
if ( ! V_39 -> V_48 || V_41 != V_39 -> V_48 )
V_40 ++ ;
V_41 = V_39 -> V_50 ;
V_39 -> V_50 &= V_51 ;
if ( ! V_39 -> V_50 || V_41 != V_39 -> V_50 )
V_40 ++ ;
if ( V_40 )
return 1 ;
if ( V_40 )
return 2 ;
if ( V_39 -> V_52 != 0 ) {
V_39 -> V_52 = 0 ;
V_40 ++ ;
}
if ( V_39 -> V_53 != 0 ) {
V_39 -> V_53 = 0 ;
V_40 ++ ;
}
if ( V_39 -> V_54 != 0 ) {
V_39 -> V_54 = 0 ;
V_40 ++ ;
}
if ( V_39 -> V_55 != 1 ) {
V_39 -> V_55 = 1 ;
V_40 ++ ;
}
if ( V_39 -> V_56 != 0 ) {
V_39 -> V_56 = 0 ;
V_40 ++ ;
}
if ( V_40 )
return 3 ;
if ( V_40 )
return 4 ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
return 0 ;
}
static int F_18 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
return 0 ;
}
int F_19 ( struct V_2 * V_3 , struct V_4 * V_5 ,
int (* F_20) ( int , int , int , unsigned long ) ,
unsigned long V_15 )
{
V_5 -> type = V_57 ;
V_5 -> V_58 = V_59 | V_60 ;
V_5 -> V_61 = 24 ;
V_5 -> V_62 = & V_63 ;
V_5 -> V_64 = 1 ;
V_5 -> V_65 = F_21 ( sizeof( struct V_66 ) , V_67 ) ;
if ( ! V_5 -> V_65 )
return - V_68 ;
V_8 = V_15 ;
if ( F_20 == NULL )
F_6 = F_9 ;
else
F_6 = F_20 ;
V_5 -> V_69 = F_12 ;
V_5 -> V_70 = F_13 ;
V_5 -> V_19 = 0 ;
V_5 -> V_24 = 0 ;
F_15 ( V_3 , V_5 ) ;
return 0 ;
}
int F_22 ( struct V_2 * V_3 , struct V_4 * V_5 ,
int (* F_20) ( int , int , int , unsigned long ) ,
unsigned long V_15 )
{
int V_71 ;
V_71 = F_19 ( V_3 , V_5 , F_20 , V_15 ) ;
if ( V_71 < 0 )
return V_71 ;
V_5 -> V_72 = F_16 ;
V_5 -> V_73 = F_17 ;
V_5 -> V_74 = F_18 ;
V_75 -> V_76 = 1 ;
return 0 ;
}
void F_23 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
F_24 ( V_5 -> V_65 ) ;
}
static int F_25 ( struct V_2 * V_3 ,
struct V_77 * V_78 )
{
int V_71 ;
unsigned long V_16 ;
int V_79 ;
V_3 -> V_80 = L_1 ;
for ( V_79 = 0 ; V_79 < V_81 ; V_79 ++ ) {
V_16 = V_78 -> V_82 [ V_79 ] ;
if ( ! V_16 )
break;
}
if ( V_79 == 0 ) {
F_26 ( V_83
L_2 , V_3 -> V_84 ) ;
return - V_30 ;
}
V_71 = F_27 ( V_3 , V_79 ) ;
if ( V_71 < 0 ) {
F_26 ( L_3 , V_3 -> V_84 ) ;
return V_71 ;
}
F_26 ( V_85 L_3 , V_3 -> V_84 ) ;
for ( V_79 = 0 ; V_79 < V_3 -> V_86 ; V_79 ++ ) {
V_16 = V_78 -> V_82 [ V_79 ] ;
F_26 ( L_4 , V_16 ) ;
if ( ! F_28 ( V_16 , V_87 , L_1 ) ) {
F_26 ( L_5 ) ;
V_3 -> V_88 [ V_79 ] . type = V_89 ;
} else {
F_19 ( V_3 , V_3 -> V_88 + V_79 , NULL ,
V_16 ) ;
}
}
F_26 ( L_6 ) ;
return 0 ;
}
static int F_29 ( struct V_2 * V_3 )
{
int V_79 ;
unsigned long V_16 ;
struct V_4 * V_5 ;
F_26 ( V_85 L_7 , V_3 -> V_84 ) ;
for ( V_79 = 0 ; V_79 < V_3 -> V_86 ; V_79 ++ ) {
V_5 = V_3 -> V_88 + V_79 ;
if ( V_5 -> type != V_89 ) {
V_16 = V_8 ;
F_30 ( V_16 , V_87 ) ;
}
F_23 ( V_3 , V_5 ) ;
}
return 0 ;
}
