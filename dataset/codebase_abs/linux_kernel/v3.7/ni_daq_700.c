static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
if ( V_7 [ 0 ] ) {
V_4 -> V_8 &= ~ V_7 [ 0 ] ;
V_4 -> V_8 |= ( V_7 [ 0 ] & V_7 [ 1 ] ) ;
if ( V_7 [ 0 ] & 0xff )
F_2 ( V_4 -> V_8 & 0xff , V_2 -> V_9 + V_10 ) ;
}
V_7 [ 1 ] = V_4 -> V_8 & 0xff ;
V_7 [ 1 ] |= F_3 ( V_2 -> V_9 + V_11 ) << 8 ;
return V_6 -> V_12 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned int V_13 = 1 << F_5 ( V_6 -> V_14 ) ;
switch ( V_7 [ 0 ] ) {
case V_15 :
break;
case V_16 :
break;
case V_17 :
V_7 [ 1 ] = ( V_4 -> V_18 & V_13 ) ? V_19 : V_20 ;
break;
default:
return - V_21 ;
}
return V_6 -> V_12 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_12 , V_22 , V_13 ;
int V_23 ;
unsigned int V_24 ;
enum { V_25 = 100 };
V_13 = F_5 ( V_6 -> V_14 ) ;
F_2 ( V_13 | 0x80 , V_2 -> V_9 + V_26 ) ;
for ( V_12 = 0 ; V_12 < V_6 -> V_12 ; V_12 ++ ) {
F_2 ( 0x00 , V_2 -> V_9 + V_27 ) ;
F_2 ( 0x30 , V_2 -> V_9 + V_28 ) ;
F_2 ( 0x32 , V_2 -> V_9 + V_28 ) ;
for ( V_22 = 0 ; V_22 < V_25 ; V_22 ++ ) {
V_24 = F_3 ( V_2 -> V_9 + V_29 ) ;
if ( ( V_24 & 0x03 ) != 0 ) {
F_7 ( V_2 -> V_30 ,
L_1 ) ;
return - V_31 ;
}
V_24 = F_3 ( V_2 -> V_9 + V_32 ) ;
if ( ( V_24 & 0x02 ) != 0 ) {
F_7 ( V_2 -> V_30 , L_2 ) ;
return - V_33 ;
}
if ( ( V_24 & 0x11 ) == 0x01 ) {
break;
}
F_8 ( 1 ) ;
}
if ( V_22 == V_25 ) {
F_7 ( V_2 -> V_30 ,
L_3 ) ;
return - V_34 ;
}
V_23 = F_9 ( V_2 -> V_9 + V_35 ) ;
V_23 &= 0x0fff ;
V_23 ^= 0x0800 ;
V_7 [ V_12 ] = V_23 ;
}
return V_12 ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned long V_9 = V_2 -> V_9 ;
F_2 ( 0x80 , V_9 + V_26 ) ;
F_2 ( 0x00 , V_9 + V_27 ) ;
F_2 ( 0x00 , V_9 + V_36 ) ;
F_2 ( 0x32 , V_9 + V_28 ) ;
F_2 ( 0x00 , V_9 + V_37 ) ;
F_2 ( 0x00 , V_9 + V_38 ) ;
F_9 ( V_9 + V_35 ) ;
}
static int F_11 ( struct V_1 * V_2 , struct V_39 * V_40 )
{
const struct V_41 * V_42 = F_12 ( V_2 ) ;
struct V_3 * V_4 ;
struct V_43 * V_44 ;
int V_45 ;
V_44 = V_46 ;
if ( ! V_44 )
return - V_47 ;
V_2 -> V_9 = V_44 -> V_48 [ 0 ] -> V_49 ;
if ( ! V_2 -> V_9 ) {
F_13 ( V_2 -> V_30 , L_4 ) ;
return - V_21 ;
}
V_2 -> V_50 = V_42 -> V_51 ;
V_45 = F_14 ( V_2 , 2 ) ;
if ( V_45 )
return V_45 ;
V_4 = & V_2 -> V_52 [ 0 ] ;
V_4 -> type = V_53 ;
V_4 -> V_54 = V_55 | V_56 ;
V_4 -> V_57 = 16 ;
V_4 -> V_58 = & V_59 ;
V_4 -> V_60 = 1 ;
V_4 -> V_61 = F_1 ;
V_4 -> V_62 = F_4 ;
V_4 -> V_8 = 0 ;
V_4 -> V_18 = 0x00ff ;
V_4 = & V_2 -> V_52 [ 1 ] ;
V_4 -> type = V_63 ;
V_4 -> V_54 = V_55 | V_64 ;
V_4 -> V_57 = 16 ;
V_4 -> V_60 = ( 1 << 12 ) - 1 ;
V_4 -> V_58 = & V_65 ;
V_4 -> V_66 = F_6 ;
F_10 ( V_2 , V_4 ) ;
F_7 ( V_2 -> V_30 , L_5 ,
V_2 -> V_67 -> V_68 ,
V_2 -> V_50 ,
V_2 -> V_9 ) ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 )
{
}
static int F_16 ( struct V_43 * V_69 ,
void * V_70 )
{
if ( V_69 -> V_71 == 0 )
return - V_21 ;
return F_17 ( V_69 ) ;
}
static int F_18 ( struct V_43 * V_44 )
{
int V_45 ;
V_44 -> V_72 |= V_73 | V_74 |
V_75 ;
V_45 = F_19 ( V_44 , F_16 , NULL ) ;
if ( V_45 )
goto V_76;
if ( ! V_44 -> V_77 )
goto V_76;
V_45 = F_20 ( V_44 ) ;
if ( V_45 )
goto V_76;
V_46 = V_44 ;
return 0 ;
V_76:
F_21 ( V_44 ) ;
return V_45 ;
}
static void F_22 ( struct V_43 * V_44 )
{
F_21 ( V_44 ) ;
V_46 = NULL ;
}
static int T_1 F_23 ( void )
{
int V_45 ;
V_45 = F_24 ( & V_78 ) ;
if ( V_45 < 0 )
return V_45 ;
V_45 = F_25 ( & V_79 ) ;
if ( V_45 < 0 ) {
F_26 ( & V_78 ) ;
return V_45 ;
}
return 0 ;
}
static void T_2 F_27 ( void )
{
F_28 ( & V_79 ) ;
F_26 ( & V_78 ) ;
}
