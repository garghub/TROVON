static void F_1 ( int V_1 , unsigned long V_2 ,
unsigned long V_3 , unsigned long V_4 ,
unsigned long V_5 )
{
unsigned long V_6 ;
unsigned long V_7 ;
V_7 = F_2 () & V_8 ;
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
static void F_10 ( struct V_9 * V_10 )
{
V_10 -> V_11 = F_11 () ;
F_12 ( 0 , 0 , ( unsigned long ) V_10 -> V_12 -> V_13 , V_14 ) ;
V_10 -> V_15 = V_10 -> V_16 = ~ 0 ;
}
static int F_13 ( unsigned char V_17 , struct V_18 * V_19 ,
unsigned int V_20 , unsigned char V_21 , T_1 * V_22 )
{
struct V_9 * V_10 = V_19 -> V_23 ;
unsigned int V_24 = F_14 ( V_20 ) ;
unsigned int V_25 = F_15 ( V_20 ) ;
unsigned long V_26 , V_27 , V_28 , V_29 , V_30 , V_31 , V_32 ;
int error = V_33 ;
if ( V_24 > 19 ) {
* V_22 = 0xffffffff ;
return - 1 ;
}
F_16 ( V_29 ) ;
V_32 = F_17 ( V_10 -> V_34 + V_35 ) & 0x0000ffff ;
V_32 |= F_18 ( 0x2000 ) ;
F_19 ( V_32 , V_10 -> V_34 + V_35 ) ;
F_20 () ;
if ( V_10 -> V_36 ( V_24 , 1 ) == 0 ) {
* V_22 = 0xffffffff ;
F_21 ( V_29 ) ;
return - 1 ;
}
if ( V_19 -> V_37 == 0 )
V_28 = ( 1 << V_24 ) << 11 ;
else
V_28 = 0x80000000 | ( V_19 -> V_37 << 16 ) | ( V_24 << 11 ) ;
V_26 = ( V_25 << 8 ) | ( V_21 & ~ 0x3 ) ;
V_26 |= V_28 & ~ V_38 ;
V_28 = V_28 & V_38 ;
V_30 = ( 6 << 26 ) | ( V_28 >> 6 ) | ( 2 << 3 ) | 7 ;
V_31 = ( 6 << 26 ) | ( V_28 >> 6 ) | ( 0x1000 >> 6 ) | ( 2 << 3 ) | 7 ;
if ( ( V_30 != V_10 -> V_15 ) || ( V_31 != V_10 -> V_16 ) ) {
F_1 ( V_10 -> V_11 , V_30 , V_31 ,
( unsigned long ) V_10 -> V_12 -> V_13 , V_14 ) ;
V_10 -> V_15 = V_30 ;
V_10 -> V_16 = V_31 ;
}
if ( V_17 == V_39 )
F_19 ( * V_22 , V_10 -> V_12 -> V_13 + V_26 ) ;
else
* V_22 = F_17 ( V_10 -> V_12 -> V_13 + V_26 ) ;
F_20 () ;
F_22 ( L_1 ,
V_17 , V_19 -> V_37 , V_24 , V_21 , * V_22 , V_26 ) ;
V_27 = F_17 ( V_10 -> V_34 + V_35 ) ;
if ( V_27 & ( 1 << 29 ) ) {
* V_22 = 0xffffffff ;
error = - 1 ;
F_22 ( L_2 ,
V_17 , V_19 -> V_37 , V_24 ) ;
} else if ( ( V_27 >> 28 ) & 0xf ) {
F_22 ( L_3 ,
V_24 , ( V_27 >> 28 ) & 0xf ) ;
F_19 ( V_27 & 0xf000ffff , V_10 -> V_34 + V_35 ) ;
* V_22 = 0xffffffff ;
error = - 1 ;
}
( void ) V_10 -> V_36 ( V_24 , 0 ) ;
F_21 ( V_29 ) ;
return error ;
}
static int F_23 ( struct V_18 * V_19 , unsigned int V_40 ,
int V_21 , T_2 * V_41 )
{
T_1 V_22 ;
int V_42 = F_13 ( V_43 , V_19 , V_40 , V_21 , & V_22 ) ;
if ( V_21 & 1 )
V_22 >>= 8 ;
if ( V_21 & 2 )
V_22 >>= 16 ;
* V_41 = V_22 & 0xff ;
return V_42 ;
}
static int F_24 ( struct V_18 * V_19 , unsigned int V_40 ,
int V_21 , T_3 * V_41 )
{
T_1 V_22 ;
int V_42 = F_13 ( V_43 , V_19 , V_40 , V_21 , & V_22 ) ;
if ( V_21 & 2 )
V_22 >>= 16 ;
* V_41 = V_22 & 0xffff ;
return V_42 ;
}
static int F_25 ( struct V_18 * V_19 , unsigned int V_40 ,
int V_21 , T_1 * V_41 )
{
return F_13 ( V_43 , V_19 , V_40 , V_21 , V_41 ) ;
}
static int F_26 ( struct V_18 * V_19 , unsigned int V_40 ,
int V_21 , T_2 V_41 )
{
T_1 V_22 = 0 ;
if ( F_13 ( V_43 , V_19 , V_40 , V_21 , & V_22 ) )
return - 1 ;
V_22 = ( V_22 & ~ ( 0xff << ( ( V_21 & 3 ) << 3 ) ) ) |
( V_41 << ( ( V_21 & 3 ) << 3 ) ) ;
if ( F_13 ( V_39 , V_19 , V_40 , V_21 , & V_22 ) )
return - 1 ;
return V_33 ;
}
static int F_27 ( struct V_18 * V_19 , unsigned int V_40 ,
int V_21 , T_3 V_41 )
{
T_1 V_22 = 0 ;
if ( F_13 ( V_43 , V_19 , V_40 , V_21 , & V_22 ) )
return - 1 ;
V_22 = ( V_22 & ~ ( 0xffff << ( ( V_21 & 3 ) << 3 ) ) ) |
( V_41 << ( ( V_21 & 3 ) << 3 ) ) ;
if ( F_13 ( V_39 , V_19 , V_40 , V_21 , & V_22 ) )
return - 1 ;
return V_33 ;
}
static int F_28 ( struct V_18 * V_19 , unsigned int V_40 ,
int V_21 , T_1 V_41 )
{
return F_13 ( V_39 , V_19 , V_40 , V_21 , & V_41 ) ;
}
static int F_29 ( struct V_18 * V_19 , unsigned int V_40 ,
int V_21 , int V_44 , T_1 * V_41 )
{
switch ( V_44 ) {
case 1 : {
T_2 V_45 ;
int V_46 = F_23 ( V_19 , V_40 , V_21 , & V_45 ) ;
* V_41 = V_45 ;
return V_46 ;
}
case 2 : {
T_3 V_45 ;
int V_46 = F_24 ( V_19 , V_40 , V_21 , & V_45 ) ;
* V_41 = V_45 ;
return V_46 ;
}
default:
return F_25 ( V_19 , V_40 , V_21 , V_41 ) ;
}
}
static int F_30 ( struct V_18 * V_19 , unsigned int V_40 ,
int V_21 , int V_44 , T_1 V_41 )
{
switch ( V_44 ) {
case 1 :
return F_26 ( V_19 , V_40 , V_21 , ( T_2 ) V_41 ) ;
case 2 :
return F_27 ( V_19 , V_40 , V_21 , ( T_3 ) V_41 ) ;
default:
return F_28 ( V_19 , V_40 , V_21 , V_41 ) ;
}
}
static int F_31 ( unsigned int V_47 , int assert )
{
return 1 ;
}
static int F_32 ( void )
{
struct V_9 * V_10 = V_48 ;
if ( ! V_10 )
return 0 ;
V_10 -> V_49 [ 0 ] = F_17 ( V_10 -> V_34 + V_50 ) ;
V_10 -> V_49 [ 1 ] = F_17 ( V_10 -> V_34 + V_51 ) & 0x0009ffff ;
V_10 -> V_49 [ 2 ] = F_17 ( V_10 -> V_34 + V_52 ) ;
V_10 -> V_49 [ 3 ] = F_17 ( V_10 -> V_34 + V_53 ) ;
V_10 -> V_49 [ 4 ] = F_17 ( V_10 -> V_34 + V_54 ) ;
V_10 -> V_49 [ 5 ] = F_17 ( V_10 -> V_34 + V_55 ) ;
V_10 -> V_49 [ 6 ] = F_17 ( V_10 -> V_34 + V_56 ) ;
V_10 -> V_49 [ 7 ] = F_17 ( V_10 -> V_34 + V_57 ) ;
V_10 -> V_49 [ 8 ] = F_17 ( V_10 -> V_34 + V_58 ) ;
V_10 -> V_49 [ 9 ] = F_17 ( V_10 -> V_34 + V_59 ) ;
V_10 -> V_49 [ 10 ] = F_17 ( V_10 -> V_34 + V_60 ) ;
V_10 -> V_49 [ 11 ] = F_17 ( V_10 -> V_34 + V_61 ) ;
return 0 ;
}
static void F_33 ( void )
{
struct V_9 * V_10 = V_48 ;
if ( ! V_10 )
return;
F_19 ( V_10 -> V_49 [ 0 ] , V_10 -> V_34 + V_50 ) ;
F_19 ( V_10 -> V_49 [ 2 ] , V_10 -> V_34 + V_52 ) ;
F_19 ( V_10 -> V_49 [ 3 ] , V_10 -> V_34 + V_53 ) ;
F_19 ( V_10 -> V_49 [ 4 ] , V_10 -> V_34 + V_54 ) ;
F_19 ( V_10 -> V_49 [ 5 ] , V_10 -> V_34 + V_55 ) ;
F_19 ( V_10 -> V_49 [ 6 ] , V_10 -> V_34 + V_56 ) ;
F_19 ( V_10 -> V_49 [ 7 ] , V_10 -> V_34 + V_57 ) ;
F_19 ( V_10 -> V_49 [ 8 ] , V_10 -> V_34 + V_58 ) ;
F_19 ( V_10 -> V_49 [ 9 ] , V_10 -> V_34 + V_59 ) ;
F_19 ( V_10 -> V_49 [ 10 ] , V_10 -> V_34 + V_60 ) ;
F_19 ( V_10 -> V_49 [ 11 ] , V_10 -> V_34 + V_61 ) ;
F_20 () ;
F_19 ( V_10 -> V_49 [ 1 ] , V_10 -> V_34 + V_51 ) ;
F_20 () ;
V_10 -> V_11 = 8191 ;
F_10 ( V_10 ) ;
}
static int F_34 ( struct V_62 * V_63 )
{
struct V_64 * V_65 = V_63 -> V_66 . V_67 ;
struct V_9 * V_10 ;
void T_4 * V_68 ;
unsigned long V_41 ;
struct V_69 * V_32 ;
struct V_70 * V_71 ;
int V_42 ;
if ( ! V_65 ) {
F_35 ( & V_63 -> V_66 , L_4 ) ;
V_42 = - V_72 ;
goto V_73;
}
V_10 = F_36 ( sizeof( * V_10 ) , V_74 ) ;
if ( ! V_10 ) {
F_35 ( & V_63 -> V_66 , L_5 ) ;
V_42 = - V_75 ;
goto V_73;
}
V_32 = F_37 ( V_63 , V_76 , 0 ) ;
if ( ! V_32 ) {
F_35 ( & V_63 -> V_66 , L_6 ) ;
V_42 = - V_72 ;
goto V_77;
}
if ( ! F_38 ( V_32 -> V_78 , F_39 ( V_32 ) , V_63 -> V_79 ) ) {
F_35 ( & V_63 -> V_66 , L_7 ) ;
V_42 = - V_72 ;
goto V_77;
}
V_71 = F_40 ( & V_63 -> V_66 , L_8 ) ;
if ( F_41 ( V_71 ) ) {
F_35 ( & V_63 -> V_66 , L_9 ) ;
V_42 = F_42 ( V_71 ) ;
goto V_80;
}
V_42 = F_43 ( V_71 ) ;
if ( V_42 ) {
F_35 ( & V_63 -> V_66 , L_10 ) ;
goto V_81;
}
V_10 -> V_34 = F_44 ( V_32 -> V_78 , F_39 ( V_32 ) ) ;
if ( ! V_10 -> V_34 ) {
F_35 ( & V_63 -> V_66 , L_11 ) ;
V_42 = - V_72 ;
goto V_82;
}
V_68 = F_45 ( V_83 , 0x00100000 ) ;
if ( ! V_68 ) {
F_35 ( & V_63 -> V_66 , L_12 ) ;
V_42 = - V_72 ;
goto V_84;
}
V_10 -> V_85 . V_86 = ( unsigned long ) V_68 ;
if ( ( F_46 () == V_87 ) &&
( F_47 () < 0x01030202 ) &&
( V_88 == V_89 ) ) {
V_41 = F_17 ( V_10 -> V_34 + V_51 ) ;
V_41 |= V_90 ;
F_19 ( V_41 , V_10 -> V_34 + V_51 ) ;
F_20 () ;
F_48 ( & V_63 -> V_66 , L_13 ) ;
}
if ( V_65 -> V_91 )
V_10 -> V_91 = V_65 -> V_91 ;
if ( V_65 -> V_36 )
V_10 -> V_36 = V_65 -> V_36 ;
else
V_10 -> V_36 = F_31 ;
V_10 -> V_85 . V_92 = & V_93 ;
V_10 -> V_85 . V_94 = & V_95 ;
V_10 -> V_85 . V_96 = & V_97 ;
V_10 -> V_12 = F_49 ( 0x2000 , V_98 ) ;
if ( ! V_10 -> V_12 ) {
F_35 ( & V_63 -> V_66 , L_14 ) ;
V_42 = - V_75 ;
goto V_99;
}
V_10 -> V_11 = 8191 ;
F_10 ( V_10 ) ;
F_50 ( ( unsigned long ) V_10 -> V_85 . V_86 ) ;
V_41 = F_17 ( V_10 -> V_34 + V_51 ) ;
V_41 &= ~ V_65 -> V_100 ;
V_41 |= V_65 -> V_101 ;
V_41 &= ~ V_102 ;
F_19 ( V_41 , V_10 -> V_34 + V_51 ) ;
F_20 () ;
V_48 = V_10 ;
F_51 ( V_63 , V_10 ) ;
F_52 ( & V_103 ) ;
F_53 ( & V_10 -> V_85 ) ;
F_48 ( & V_63 -> V_66 , L_15 ,
F_54 ( V_71 ) / 1000000 ) ;
return 0 ;
V_99:
F_55 ( V_68 ) ;
V_84:
F_55 ( V_10 -> V_34 ) ;
V_82:
F_56 ( V_71 ) ;
V_81:
F_57 ( V_71 ) ;
V_80:
F_58 ( V_32 -> V_78 , F_39 ( V_32 ) ) ;
V_77:
F_59 ( V_10 ) ;
V_73:
return V_42 ;
}
static int T_5 F_60 ( void )
{
switch ( F_46 () ) {
case V_87 :
case V_104 :
return F_61 ( & V_105 ) ;
}
return 0 ;
}
int F_62 ( const struct V_106 * V_66 , T_2 V_107 , T_2 V_108 )
{
struct V_9 * V_10 = V_66 -> V_23 ;
if ( V_10 && V_10 -> V_91 )
return V_10 -> V_91 ( V_66 , V_107 , V_108 ) ;
return - 1 ;
}
int F_63 ( struct V_106 * V_66 )
{
return 0 ;
}
