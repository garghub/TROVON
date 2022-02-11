static void F_1 ( int V_1 , unsigned long V_2 ,
unsigned long V_3 , unsigned long V_4 ,
unsigned long V_5 )
{
unsigned long V_6 ;
unsigned long V_7 ;
V_7 = F_2 () & 0xff ;
V_6 = F_3 () ;
F_4 ( V_1 ) ;
F_5 ( V_5 ) ;
F_6 ( V_4 ) ;
F_7 ( V_2 ) ;
F_8 ( V_3 ) ;
F_9 () ;
F_6 ( V_7 ) ;
F_5 ( V_6 ) ;
}
static void F_10 ( struct V_8 * V_9 )
{
V_9 -> V_10 = F_11 () ;
F_12 ( 0 , 0 , ( unsigned long ) V_9 -> V_11 -> V_12 , V_13 ) ;
V_9 -> V_14 = V_9 -> V_15 = ~ 0 ;
}
static int F_13 ( unsigned char V_16 , struct V_17 * V_18 ,
unsigned int V_19 , unsigned char V_20 , T_1 * V_21 )
{
struct V_8 * V_9 = V_18 -> V_22 ;
unsigned int V_23 = F_14 ( V_19 ) ;
unsigned int V_24 = F_15 ( V_19 ) ;
unsigned long V_25 , V_26 , V_27 , V_28 , V_29 , V_30 , V_31 ;
int error = V_32 ;
if ( V_23 > 19 ) {
* V_21 = 0xffffffff ;
return - 1 ;
}
if ( F_16 ( F_11 () < V_9 -> V_10 ) )
F_10 ( V_9 ) ;
F_17 ( V_28 ) ;
V_31 = F_18 ( V_9 -> V_33 + V_34 ) & 0x0000ffff ;
V_31 |= F_19 ( 0x2000 ) ;
F_20 ( V_31 , V_9 -> V_33 + V_34 ) ;
F_21 () ;
if ( V_9 -> V_35 ( V_23 , 1 ) == 0 ) {
* V_21 = 0xffffffff ;
F_22 ( V_28 ) ;
return - 1 ;
}
if ( V_18 -> V_36 == 0 )
V_27 = ( 1 << V_23 ) << 11 ;
else
V_27 = 0x80000000 | ( V_18 -> V_36 << 16 ) | ( V_23 << 11 ) ;
V_25 = ( V_24 << 8 ) | ( V_20 & ~ 0x3 ) ;
V_25 |= V_27 & ~ V_37 ;
V_27 = V_27 & V_37 ;
V_29 = ( 6 << 26 ) | ( V_27 >> 6 ) | ( 2 << 3 ) | 7 ;
V_30 = ( 6 << 26 ) | ( V_27 >> 6 ) | ( 0x1000 >> 6 ) | ( 2 << 3 ) | 7 ;
if ( ( V_29 != V_9 -> V_14 ) || ( V_30 != V_9 -> V_15 ) ) {
F_1 ( V_9 -> V_10 , V_29 , V_30 ,
( unsigned long ) V_9 -> V_11 -> V_12 , V_13 ) ;
V_9 -> V_14 = V_29 ;
V_9 -> V_15 = V_30 ;
}
if ( V_16 == V_38 )
F_20 ( * V_21 , V_9 -> V_11 -> V_12 + V_25 ) ;
else
* V_21 = F_18 ( V_9 -> V_11 -> V_12 + V_25 ) ;
F_21 () ;
F_23 ( L_1 ,
V_16 , V_18 -> V_36 , V_23 , V_20 , * V_21 , V_25 ) ;
V_26 = F_18 ( V_9 -> V_33 + V_34 ) ;
if ( V_26 & ( 1 << 29 ) ) {
* V_21 = 0xffffffff ;
error = - 1 ;
F_23 ( L_2 ,
V_16 , V_18 -> V_36 , V_23 ) ;
} else if ( ( V_26 >> 28 ) & 0xf ) {
F_23 ( L_3 ,
V_23 , ( V_26 >> 28 ) & 0xf ) ;
F_20 ( V_26 & 0xf000ffff , V_9 -> V_33 + V_34 ) ;
* V_21 = 0xffffffff ;
error = - 1 ;
}
( void ) V_9 -> V_35 ( V_23 , 0 ) ;
F_22 ( V_28 ) ;
return error ;
}
static int F_24 ( struct V_17 * V_18 , unsigned int V_39 ,
int V_20 , T_2 * V_40 )
{
T_1 V_21 ;
int V_41 = F_13 ( V_42 , V_18 , V_39 , V_20 , & V_21 ) ;
if ( V_20 & 1 )
V_21 >>= 8 ;
if ( V_20 & 2 )
V_21 >>= 16 ;
* V_40 = V_21 & 0xff ;
return V_41 ;
}
static int F_25 ( struct V_17 * V_18 , unsigned int V_39 ,
int V_20 , T_3 * V_40 )
{
T_1 V_21 ;
int V_41 = F_13 ( V_42 , V_18 , V_39 , V_20 , & V_21 ) ;
if ( V_20 & 2 )
V_21 >>= 16 ;
* V_40 = V_21 & 0xffff ;
return V_41 ;
}
static int F_26 ( struct V_17 * V_18 , unsigned int V_39 ,
int V_20 , T_1 * V_40 )
{
return F_13 ( V_42 , V_18 , V_39 , V_20 , V_40 ) ;
}
static int F_27 ( struct V_17 * V_18 , unsigned int V_39 ,
int V_20 , T_2 V_40 )
{
T_1 V_21 = 0 ;
if ( F_13 ( V_42 , V_18 , V_39 , V_20 , & V_21 ) )
return - 1 ;
V_21 = ( V_21 & ~ ( 0xff << ( ( V_20 & 3 ) << 3 ) ) ) |
( V_40 << ( ( V_20 & 3 ) << 3 ) ) ;
if ( F_13 ( V_38 , V_18 , V_39 , V_20 , & V_21 ) )
return - 1 ;
return V_32 ;
}
static int F_28 ( struct V_17 * V_18 , unsigned int V_39 ,
int V_20 , T_3 V_40 )
{
T_1 V_21 = 0 ;
if ( F_13 ( V_42 , V_18 , V_39 , V_20 , & V_21 ) )
return - 1 ;
V_21 = ( V_21 & ~ ( 0xffff << ( ( V_20 & 3 ) << 3 ) ) ) |
( V_40 << ( ( V_20 & 3 ) << 3 ) ) ;
if ( F_13 ( V_38 , V_18 , V_39 , V_20 , & V_21 ) )
return - 1 ;
return V_32 ;
}
static int F_29 ( struct V_17 * V_18 , unsigned int V_39 ,
int V_20 , T_1 V_40 )
{
return F_13 ( V_38 , V_18 , V_39 , V_20 , & V_40 ) ;
}
static int F_30 ( struct V_17 * V_18 , unsigned int V_39 ,
int V_20 , int V_43 , T_1 * V_40 )
{
switch ( V_43 ) {
case 1 : {
T_2 V_44 ;
int V_45 = F_24 ( V_18 , V_39 , V_20 , & V_44 ) ;
* V_40 = V_44 ;
return V_45 ;
}
case 2 : {
T_3 V_44 ;
int V_45 = F_25 ( V_18 , V_39 , V_20 , & V_44 ) ;
* V_40 = V_44 ;
return V_45 ;
}
default:
return F_26 ( V_18 , V_39 , V_20 , V_40 ) ;
}
}
static int F_31 ( struct V_17 * V_18 , unsigned int V_39 ,
int V_20 , int V_43 , T_1 V_40 )
{
switch ( V_43 ) {
case 1 :
return F_27 ( V_18 , V_39 , V_20 , ( T_2 ) V_40 ) ;
case 2 :
return F_28 ( V_18 , V_39 , V_20 , ( T_3 ) V_40 ) ;
default:
return F_29 ( V_18 , V_39 , V_20 , V_40 ) ;
}
}
static int F_32 ( unsigned int V_46 , int assert )
{
return 1 ;
}
static int T_4 F_33 ( struct V_47 * V_48 )
{
struct V_49 * V_50 = V_48 -> V_51 . V_52 ;
struct V_8 * V_9 ;
void T_5 * V_53 ;
unsigned long V_40 ;
struct V_54 * V_31 ;
int V_41 ;
if ( ! V_50 ) {
F_34 ( & V_48 -> V_51 , L_4 ) ;
V_41 = - V_55 ;
goto V_56;
}
V_9 = F_35 ( sizeof( * V_9 ) , V_57 ) ;
if ( ! V_9 ) {
F_34 ( & V_48 -> V_51 , L_5 ) ;
V_41 = - V_58 ;
goto V_56;
}
V_31 = F_36 ( V_48 , V_59 , 0 ) ;
if ( ! V_31 ) {
F_34 ( & V_48 -> V_51 , L_6 ) ;
V_41 = - V_55 ;
goto V_60;
}
if ( ! F_37 ( V_31 -> V_61 , F_38 ( V_31 ) , V_48 -> V_62 ) ) {
F_34 ( & V_48 -> V_51 , L_7 ) ;
V_41 = - V_55 ;
goto V_60;
}
V_9 -> V_33 = F_39 ( V_31 -> V_61 , F_38 ( V_31 ) ) ;
if ( ! V_9 -> V_33 ) {
F_34 ( & V_48 -> V_51 , L_8 ) ;
V_41 = - V_55 ;
goto V_63;
}
V_53 = F_40 ( V_64 , 0x00100000 ) ;
if ( ! V_53 ) {
F_34 ( & V_48 -> V_51 , L_9 ) ;
V_41 = - V_55 ;
goto V_65;
}
V_9 -> V_66 . V_67 = ( unsigned long ) V_53 ;
#ifdef F_41
if ( ( F_42 () == V_68 ) &&
( F_43 () < 0x01030202 ) ) {
V_40 = F_18 ( V_9 -> V_33 + V_69 ) ;
V_40 |= V_70 ;
F_20 ( V_40 , V_9 -> V_33 + V_69 ) ;
F_21 () ;
F_44 ( & V_48 -> V_51 , L_10 ) ;
}
#endif
if ( V_50 -> V_71 )
V_9 -> V_71 = V_50 -> V_71 ;
if ( V_50 -> V_35 )
V_9 -> V_35 = V_50 -> V_35 ;
else
V_9 -> V_35 = F_32 ;
V_9 -> V_66 . V_72 = & V_73 ;
V_9 -> V_66 . V_74 = & V_75 ;
V_9 -> V_66 . V_76 = & V_77 ;
V_9 -> V_11 = F_45 ( 0x2000 , V_78 ) ;
if ( ! V_9 -> V_11 ) {
F_34 ( & V_48 -> V_51 , L_11 ) ;
V_41 = - V_58 ;
goto V_79;
}
V_9 -> V_10 = 8192 ;
F_46 ( ( unsigned long ) V_9 -> V_66 . V_67 ) ;
V_40 = F_18 ( V_9 -> V_33 + V_69 ) ;
V_40 &= ~ V_50 -> V_80 ;
V_40 |= V_50 -> V_81 ;
V_40 &= ~ V_82 ;
F_20 ( V_40 , V_9 -> V_33 + V_69 ) ;
F_21 () ;
F_47 ( V_48 , V_9 ) ;
F_48 ( & V_9 -> V_66 ) ;
return 0 ;
V_79:
F_49 ( V_53 ) ;
V_65:
F_49 ( V_9 -> V_33 ) ;
V_63:
F_50 ( V_31 -> V_61 , F_38 ( V_31 ) ) ;
V_60:
F_51 ( V_9 ) ;
V_56:
return V_41 ;
}
static int F_52 ( struct V_23 * V_51 )
{
struct V_8 * V_9 = F_53 ( V_51 ) ;
V_9 -> V_83 [ 0 ] = F_18 ( V_9 -> V_33 + V_84 ) ;
V_9 -> V_83 [ 1 ] = F_18 ( V_9 -> V_33 + V_69 ) & 0x0009ffff ;
V_9 -> V_83 [ 2 ] = F_18 ( V_9 -> V_33 + V_85 ) ;
V_9 -> V_83 [ 3 ] = F_18 ( V_9 -> V_33 + V_86 ) ;
V_9 -> V_83 [ 4 ] = F_18 ( V_9 -> V_33 + V_87 ) ;
V_9 -> V_83 [ 5 ] = F_18 ( V_9 -> V_33 + V_88 ) ;
V_9 -> V_83 [ 6 ] = F_18 ( V_9 -> V_33 + V_89 ) ;
V_9 -> V_83 [ 7 ] = F_18 ( V_9 -> V_33 + V_90 ) ;
V_9 -> V_83 [ 8 ] = F_18 ( V_9 -> V_33 + V_91 ) ;
V_9 -> V_83 [ 9 ] = F_18 ( V_9 -> V_33 + V_92 ) ;
V_9 -> V_83 [ 10 ] = F_18 ( V_9 -> V_33 + V_93 ) ;
V_9 -> V_83 [ 11 ] = F_18 ( V_9 -> V_33 + V_94 ) ;
return 0 ;
}
static int F_54 ( struct V_23 * V_51 )
{
struct V_8 * V_9 = F_53 ( V_51 ) ;
F_20 ( V_9 -> V_83 [ 0 ] , V_9 -> V_33 + V_84 ) ;
F_20 ( V_9 -> V_83 [ 2 ] , V_9 -> V_33 + V_85 ) ;
F_20 ( V_9 -> V_83 [ 3 ] , V_9 -> V_33 + V_86 ) ;
F_20 ( V_9 -> V_83 [ 4 ] , V_9 -> V_33 + V_87 ) ;
F_20 ( V_9 -> V_83 [ 5 ] , V_9 -> V_33 + V_88 ) ;
F_20 ( V_9 -> V_83 [ 6 ] , V_9 -> V_33 + V_89 ) ;
F_20 ( V_9 -> V_83 [ 7 ] , V_9 -> V_33 + V_90 ) ;
F_20 ( V_9 -> V_83 [ 8 ] , V_9 -> V_33 + V_91 ) ;
F_20 ( V_9 -> V_83 [ 9 ] , V_9 -> V_33 + V_92 ) ;
F_20 ( V_9 -> V_83 [ 10 ] , V_9 -> V_33 + V_93 ) ;
F_20 ( V_9 -> V_83 [ 11 ] , V_9 -> V_33 + V_94 ) ;
F_21 () ;
F_20 ( V_9 -> V_83 [ 1 ] , V_9 -> V_33 + V_69 ) ;
F_21 () ;
return 0 ;
}
static int T_6 F_55 ( void )
{
switch ( F_42 () ) {
case V_68 :
case V_95 :
return F_56 ( & V_96 ) ;
}
return 0 ;
}
int T_6 F_57 ( const struct V_97 * V_51 , T_2 V_98 , T_2 V_99 )
{
struct V_8 * V_9 = V_51 -> V_22 ;
if ( V_9 && V_9 -> V_71 )
return V_9 -> V_71 ( V_51 , V_98 , V_99 ) ;
return - 1 ;
}
int F_58 ( struct V_97 * V_51 )
{
return 0 ;
}
