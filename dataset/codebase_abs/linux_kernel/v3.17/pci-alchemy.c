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
F_16 ( V_28 ) ;
V_31 = F_17 ( V_9 -> V_33 + V_34 ) & 0x0000ffff ;
V_31 |= F_18 ( 0x2000 ) ;
F_19 ( V_31 , V_9 -> V_33 + V_34 ) ;
F_20 () ;
if ( V_9 -> V_35 ( V_23 , 1 ) == 0 ) {
* V_21 = 0xffffffff ;
F_21 ( V_28 ) ;
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
F_19 ( * V_21 , V_9 -> V_11 -> V_12 + V_25 ) ;
else
* V_21 = F_17 ( V_9 -> V_11 -> V_12 + V_25 ) ;
F_20 () ;
F_22 ( L_1 ,
V_16 , V_18 -> V_36 , V_23 , V_20 , * V_21 , V_25 ) ;
V_26 = F_17 ( V_9 -> V_33 + V_34 ) ;
if ( V_26 & ( 1 << 29 ) ) {
* V_21 = 0xffffffff ;
error = - 1 ;
F_22 ( L_2 ,
V_16 , V_18 -> V_36 , V_23 ) ;
} else if ( ( V_26 >> 28 ) & 0xf ) {
F_22 ( L_3 ,
V_23 , ( V_26 >> 28 ) & 0xf ) ;
F_19 ( V_26 & 0xf000ffff , V_9 -> V_33 + V_34 ) ;
* V_21 = 0xffffffff ;
error = - 1 ;
}
( void ) V_9 -> V_35 ( V_23 , 0 ) ;
F_21 ( V_28 ) ;
return error ;
}
static int F_23 ( struct V_17 * V_18 , unsigned int V_39 ,
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
static int F_24 ( struct V_17 * V_18 , unsigned int V_39 ,
int V_20 , T_3 * V_40 )
{
T_1 V_21 ;
int V_41 = F_13 ( V_42 , V_18 , V_39 , V_20 , & V_21 ) ;
if ( V_20 & 2 )
V_21 >>= 16 ;
* V_40 = V_21 & 0xffff ;
return V_41 ;
}
static int F_25 ( struct V_17 * V_18 , unsigned int V_39 ,
int V_20 , T_1 * V_40 )
{
return F_13 ( V_42 , V_18 , V_39 , V_20 , V_40 ) ;
}
static int F_26 ( struct V_17 * V_18 , unsigned int V_39 ,
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
static int F_27 ( struct V_17 * V_18 , unsigned int V_39 ,
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
static int F_28 ( struct V_17 * V_18 , unsigned int V_39 ,
int V_20 , T_1 V_40 )
{
return F_13 ( V_38 , V_18 , V_39 , V_20 , & V_40 ) ;
}
static int F_29 ( struct V_17 * V_18 , unsigned int V_39 ,
int V_20 , int V_43 , T_1 * V_40 )
{
switch ( V_43 ) {
case 1 : {
T_2 V_44 ;
int V_45 = F_23 ( V_18 , V_39 , V_20 , & V_44 ) ;
* V_40 = V_44 ;
return V_45 ;
}
case 2 : {
T_3 V_44 ;
int V_45 = F_24 ( V_18 , V_39 , V_20 , & V_44 ) ;
* V_40 = V_44 ;
return V_45 ;
}
default:
return F_25 ( V_18 , V_39 , V_20 , V_40 ) ;
}
}
static int F_30 ( struct V_17 * V_18 , unsigned int V_39 ,
int V_20 , int V_43 , T_1 V_40 )
{
switch ( V_43 ) {
case 1 :
return F_26 ( V_18 , V_39 , V_20 , ( T_2 ) V_40 ) ;
case 2 :
return F_27 ( V_18 , V_39 , V_20 , ( T_3 ) V_40 ) ;
default:
return F_28 ( V_18 , V_39 , V_20 , V_40 ) ;
}
}
static int F_31 ( unsigned int V_46 , int assert )
{
return 1 ;
}
static int F_32 ( void )
{
struct V_8 * V_9 = V_47 ;
if ( ! V_9 )
return 0 ;
V_9 -> V_48 [ 0 ] = F_17 ( V_9 -> V_33 + V_49 ) ;
V_9 -> V_48 [ 1 ] = F_17 ( V_9 -> V_33 + V_50 ) & 0x0009ffff ;
V_9 -> V_48 [ 2 ] = F_17 ( V_9 -> V_33 + V_51 ) ;
V_9 -> V_48 [ 3 ] = F_17 ( V_9 -> V_33 + V_52 ) ;
V_9 -> V_48 [ 4 ] = F_17 ( V_9 -> V_33 + V_53 ) ;
V_9 -> V_48 [ 5 ] = F_17 ( V_9 -> V_33 + V_54 ) ;
V_9 -> V_48 [ 6 ] = F_17 ( V_9 -> V_33 + V_55 ) ;
V_9 -> V_48 [ 7 ] = F_17 ( V_9 -> V_33 + V_56 ) ;
V_9 -> V_48 [ 8 ] = F_17 ( V_9 -> V_33 + V_57 ) ;
V_9 -> V_48 [ 9 ] = F_17 ( V_9 -> V_33 + V_58 ) ;
V_9 -> V_48 [ 10 ] = F_17 ( V_9 -> V_33 + V_59 ) ;
V_9 -> V_48 [ 11 ] = F_17 ( V_9 -> V_33 + V_60 ) ;
return 0 ;
}
static void F_33 ( void )
{
struct V_8 * V_9 = V_47 ;
if ( ! V_9 )
return;
F_19 ( V_9 -> V_48 [ 0 ] , V_9 -> V_33 + V_49 ) ;
F_19 ( V_9 -> V_48 [ 2 ] , V_9 -> V_33 + V_51 ) ;
F_19 ( V_9 -> V_48 [ 3 ] , V_9 -> V_33 + V_52 ) ;
F_19 ( V_9 -> V_48 [ 4 ] , V_9 -> V_33 + V_53 ) ;
F_19 ( V_9 -> V_48 [ 5 ] , V_9 -> V_33 + V_54 ) ;
F_19 ( V_9 -> V_48 [ 6 ] , V_9 -> V_33 + V_55 ) ;
F_19 ( V_9 -> V_48 [ 7 ] , V_9 -> V_33 + V_56 ) ;
F_19 ( V_9 -> V_48 [ 8 ] , V_9 -> V_33 + V_57 ) ;
F_19 ( V_9 -> V_48 [ 9 ] , V_9 -> V_33 + V_58 ) ;
F_19 ( V_9 -> V_48 [ 10 ] , V_9 -> V_33 + V_59 ) ;
F_19 ( V_9 -> V_48 [ 11 ] , V_9 -> V_33 + V_60 ) ;
F_20 () ;
F_19 ( V_9 -> V_48 [ 1 ] , V_9 -> V_33 + V_50 ) ;
F_20 () ;
V_9 -> V_10 = 8191 ;
F_10 ( V_9 ) ;
}
static int F_34 ( struct V_61 * V_62 )
{
struct V_63 * V_64 = V_62 -> V_65 . V_66 ;
struct V_8 * V_9 ;
void T_4 * V_67 ;
unsigned long V_40 ;
struct V_68 * V_31 ;
struct V_69 * V_70 ;
int V_41 ;
if ( ! V_64 ) {
F_35 ( & V_62 -> V_65 , L_4 ) ;
V_41 = - V_71 ;
goto V_72;
}
V_9 = F_36 ( sizeof( * V_9 ) , V_73 ) ;
if ( ! V_9 ) {
F_35 ( & V_62 -> V_65 , L_5 ) ;
V_41 = - V_74 ;
goto V_72;
}
V_31 = F_37 ( V_62 , V_75 , 0 ) ;
if ( ! V_31 ) {
F_35 ( & V_62 -> V_65 , L_6 ) ;
V_41 = - V_71 ;
goto V_76;
}
if ( ! F_38 ( V_31 -> V_77 , F_39 ( V_31 ) , V_62 -> V_78 ) ) {
F_35 ( & V_62 -> V_65 , L_7 ) ;
V_41 = - V_71 ;
goto V_76;
}
V_70 = F_40 ( & V_62 -> V_65 , L_8 ) ;
if ( F_41 ( V_70 ) ) {
F_35 ( & V_62 -> V_65 , L_9 ) ;
V_41 = F_42 ( V_70 ) ;
goto V_79;
}
V_41 = F_43 ( V_70 ) ;
if ( V_41 ) {
F_35 ( & V_62 -> V_65 , L_10 ) ;
goto V_80;
}
V_9 -> V_33 = F_44 ( V_31 -> V_77 , F_39 ( V_31 ) ) ;
if ( ! V_9 -> V_33 ) {
F_35 ( & V_62 -> V_65 , L_11 ) ;
V_41 = - V_71 ;
goto V_81;
}
V_67 = F_45 ( V_82 , 0x00100000 ) ;
if ( ! V_67 ) {
F_35 ( & V_62 -> V_65 , L_12 ) ;
V_41 = - V_71 ;
goto V_83;
}
V_9 -> V_84 . V_85 = ( unsigned long ) V_67 ;
if ( ( F_46 () == V_86 ) &&
( F_47 () < 0x01030202 ) && ! V_87 ) {
V_40 = F_17 ( V_9 -> V_33 + V_50 ) ;
V_40 |= V_88 ;
F_19 ( V_40 , V_9 -> V_33 + V_50 ) ;
F_20 () ;
F_48 ( & V_62 -> V_65 , L_13 ) ;
}
if ( V_64 -> V_89 )
V_9 -> V_89 = V_64 -> V_89 ;
if ( V_64 -> V_35 )
V_9 -> V_35 = V_64 -> V_35 ;
else
V_9 -> V_35 = F_31 ;
V_9 -> V_84 . V_90 = & V_91 ;
V_9 -> V_84 . V_92 = & V_93 ;
V_9 -> V_84 . V_94 = & V_95 ;
V_9 -> V_11 = F_49 ( 0x2000 , V_96 ) ;
if ( ! V_9 -> V_11 ) {
F_35 ( & V_62 -> V_65 , L_14 ) ;
V_41 = - V_74 ;
goto V_97;
}
V_9 -> V_10 = 8191 ;
F_10 ( V_9 ) ;
F_50 ( ( unsigned long ) V_9 -> V_84 . V_85 ) ;
V_40 = F_17 ( V_9 -> V_33 + V_50 ) ;
V_40 &= ~ V_64 -> V_98 ;
V_40 |= V_64 -> V_99 ;
V_40 &= ~ V_100 ;
F_19 ( V_40 , V_9 -> V_33 + V_50 ) ;
F_20 () ;
V_47 = V_9 ;
F_51 ( V_62 , V_9 ) ;
F_52 ( & V_101 ) ;
F_53 ( & V_9 -> V_84 ) ;
F_48 ( & V_62 -> V_65 , L_15 ,
F_54 ( V_70 ) / 1000000 ) ;
return 0 ;
V_97:
F_55 ( V_67 ) ;
V_83:
F_55 ( V_9 -> V_33 ) ;
V_81:
F_56 ( V_70 ) ;
V_80:
F_57 ( V_70 ) ;
V_79:
F_58 ( V_31 -> V_77 , F_39 ( V_31 ) ) ;
V_76:
F_59 ( V_9 ) ;
V_72:
return V_41 ;
}
static int T_5 F_60 ( void )
{
switch ( F_46 () ) {
case V_86 :
case V_102 :
return F_61 ( & V_103 ) ;
}
return 0 ;
}
int T_5 F_62 ( const struct V_104 * V_65 , T_2 V_105 , T_2 V_106 )
{
struct V_8 * V_9 = V_65 -> V_22 ;
if ( V_9 && V_9 -> V_89 )
return V_9 -> V_89 ( V_65 , V_105 , V_106 ) ;
return - 1 ;
}
int F_63 ( struct V_104 * V_65 )
{
return 0 ;
}
