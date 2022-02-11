void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
short V_5 ;
V_5 = F_2 ( 0 , V_6 , 0 , V_7 ) ;
V_5 |= ( F_2 ( 0 , V_6 + 1 , 0 , V_7 ) << 8 ) ;
F_3 ( V_4 -> V_8 , V_5 ) ;
V_4 -> V_8 -> V_9 |= V_10 ;
F_4 ( V_2 , V_4 ) ;
}
static int F_5 ( int V_11 , int V_12 , int V_13 , unsigned long V_14 )
{
unsigned long V_15 = V_14 ;
if ( V_11 ) {
F_6 ( V_13 , V_15 + V_12 ) ;
return 0 ;
} else {
return F_7 ( V_15 + V_12 ) ;
}
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_16 * V_17 , unsigned int * V_13 )
{
if ( V_13 [ 0 ] ) {
V_4 -> V_18 &= ~ V_13 [ 0 ] ;
V_4 -> V_18 |= ( V_13 [ 0 ] & V_13 [ 1 ] ) ;
if ( V_13 [ 0 ] & 0xff )
F_2 ( 1 , V_6 , V_4 -> V_18 & 0xff ,
V_7 ) ;
if ( V_13 [ 0 ] & 0xff00 )
F_2 ( 1 , V_6 + 1 , ( V_4 -> V_18 >> 8 ) & 0xff ,
V_7 ) ;
if ( V_13 [ 0 ] & 0xff0000 )
F_2 ( 1 , V_6 + 2 ,
( V_4 -> V_18 >> 16 ) & 0xff , V_7 ) ;
}
V_13 [ 1 ] = F_2 ( 0 , V_6 , 0 , V_7 ) ;
V_13 [ 1 ] |= ( F_2 ( 0 , V_6 + 1 , 0 , V_7 ) << 8 ) ;
V_13 [ 1 ] |= ( F_2 ( 0 , V_6 + 2 , 0 , V_7 ) << 16 ) ;
return 2 ;
}
static void F_9 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_19 ;
V_19 = V_20 ;
if ( ! ( V_4 -> V_21 & 0x0000ff ) )
V_19 |= V_22 ;
if ( ! ( V_4 -> V_21 & 0x00ff00 ) )
V_19 |= V_23 ;
if ( ! ( V_4 -> V_21 & 0x0f0000 ) )
V_19 |= V_24 ;
if ( ! ( V_4 -> V_21 & 0xf00000 ) )
V_19 |= V_25 ;
F_2 ( 1 , V_26 , V_19 , V_7 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_16 * V_17 , unsigned int * V_13 )
{
unsigned int V_27 ;
unsigned int V_28 ;
V_27 = 1 << F_11 ( V_17 -> V_29 ) ;
if ( V_27 & 0x0000ff )
V_28 = 0x0000ff ;
else if ( V_27 & 0x00ff00 )
V_28 = 0x00ff00 ;
else if ( V_27 & 0x0f0000 )
V_28 = 0x0f0000 ;
else
V_28 = 0xf00000 ;
switch ( V_13 [ 0 ] ) {
case V_30 :
V_4 -> V_21 &= ~ V_28 ;
break;
case V_31 :
V_4 -> V_21 |= V_28 ;
break;
case V_32 :
V_13 [ 1 ] = ( V_4 -> V_21 & V_28 ) ? V_33 : V_34 ;
return V_17 -> V_35 ;
break;
default:
return - V_36 ;
}
F_9 ( V_2 , V_4 ) ;
return 1 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_37 * V_38 )
{
int V_39 = 0 ;
unsigned int V_40 ;
V_40 = V_38 -> V_41 ;
V_38 -> V_41 &= V_42 ;
if ( ! V_38 -> V_41 || V_40 != V_38 -> V_41 )
V_39 ++ ;
V_40 = V_38 -> V_43 ;
V_38 -> V_43 &= V_44 ;
if ( ! V_38 -> V_43 || V_40 != V_38 -> V_43 )
V_39 ++ ;
V_40 = V_38 -> V_45 ;
V_38 -> V_45 &= V_46 ;
if ( ! V_38 -> V_45 || V_40 != V_38 -> V_45 )
V_39 ++ ;
V_40 = V_38 -> V_47 ;
V_38 -> V_47 &= V_48 ;
if ( ! V_38 -> V_47 || V_40 != V_38 -> V_47 )
V_39 ++ ;
V_40 = V_38 -> V_49 ;
V_38 -> V_49 &= V_50 ;
if ( ! V_38 -> V_49 || V_40 != V_38 -> V_49 )
V_39 ++ ;
if ( V_39 )
return 1 ;
if ( V_39 )
return 2 ;
if ( V_38 -> V_51 != 0 ) {
V_38 -> V_51 = 0 ;
V_39 ++ ;
}
if ( V_38 -> V_52 != 0 ) {
V_38 -> V_52 = 0 ;
V_39 ++ ;
}
if ( V_38 -> V_53 != 0 ) {
V_38 -> V_53 = 0 ;
V_39 ++ ;
}
if ( V_38 -> V_54 != 1 ) {
V_38 -> V_54 = 1 ;
V_39 ++ ;
}
if ( V_38 -> V_55 != 0 ) {
V_38 -> V_55 = 0 ;
V_39 ++ ;
}
if ( V_39 )
return 3 ;
if ( V_39 )
return 4 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return 0 ;
}
int F_15 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int (* F_16) ( int , int , int , unsigned long ) ,
unsigned long V_14 )
{
V_4 -> type = V_56 ;
V_4 -> V_57 = V_58 | V_59 ;
V_4 -> V_60 = 24 ;
V_4 -> V_61 = & V_62 ;
V_4 -> V_63 = 1 ;
V_4 -> V_64 = F_17 ( sizeof( struct V_65 ) , V_66 ) ;
if ( ! V_4 -> V_64 )
return - V_67 ;
V_7 = V_14 ;
if ( F_16 == NULL )
F_2 = F_5 ;
else
F_2 = F_16 ;
V_4 -> V_68 = F_8 ;
V_4 -> V_69 = F_10 ;
V_4 -> V_18 = 0 ;
V_4 -> V_21 = 0 ;
F_9 ( V_2 , V_4 ) ;
return 0 ;
}
int F_18 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int (* F_16) ( int , int , int , unsigned long ) ,
unsigned long V_14 )
{
int V_70 ;
V_70 = F_15 ( V_2 , V_4 , F_16 , V_14 ) ;
if ( V_70 < 0 )
return V_70 ;
V_4 -> V_71 = F_12 ;
V_4 -> V_72 = F_13 ;
V_4 -> V_73 = F_14 ;
V_74 -> V_75 = 1 ;
return 0 ;
}
void F_19 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_20 ( V_4 -> V_64 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_76 * V_77 )
{
int V_70 ;
unsigned long V_15 ;
int V_78 ;
V_2 -> V_79 = L_1 ;
for ( V_78 = 0 ; V_78 < V_80 ; V_78 ++ ) {
V_15 = V_77 -> V_81 [ V_78 ] ;
if ( ! V_15 )
break;
}
if ( V_78 == 0 ) {
F_22 ( V_82
L_2 , V_2 -> V_83 ) ;
return - V_36 ;
}
V_70 = F_23 ( V_2 , V_78 ) ;
if ( V_70 < 0 ) {
F_22 ( L_3 , V_2 -> V_83 ) ;
return V_70 ;
}
F_22 ( V_84 L_3 , V_2 -> V_83 ) ;
for ( V_78 = 0 ; V_78 < V_2 -> V_85 ; V_78 ++ ) {
V_15 = V_77 -> V_81 [ V_78 ] ;
F_22 ( L_4 , V_15 ) ;
if ( ! F_24 ( V_15 , V_86 , L_1 ) ) {
F_22 ( L_5 ) ;
V_2 -> V_87 [ V_78 ] . type = V_88 ;
} else {
F_15 ( V_2 , V_2 -> V_87 + V_78 , NULL ,
V_15 ) ;
}
}
F_22 ( L_6 ) ;
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
int V_78 ;
unsigned long V_15 ;
struct V_3 * V_4 ;
for ( V_78 = 0 ; V_78 < V_2 -> V_85 ; V_78 ++ ) {
V_4 = V_2 -> V_87 + V_78 ;
if ( V_4 -> type != V_88 ) {
V_15 = V_7 ;
F_26 ( V_15 , V_86 ) ;
}
F_19 ( V_2 , V_4 ) ;
}
}
