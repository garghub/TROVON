static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_2 ) ;
}
static int F_3 ( struct V_1 * V_4 , int V_5 , T_1 V_6 )
{
struct V_7 * V_8 ;
int V_9 ;
V_8 = V_5 ? V_4 -> V_10 : V_4 -> V_11 ;
V_9 = F_4 ( V_8 , V_6 ) ;
if ( V_9 < 0 ) {
F_5 ( & V_8 -> V_12 , L_1 ) ;
return V_9 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_4 , int V_5 , T_1 * V_6 )
{
struct V_7 * V_8 ;
int V_9 ;
V_8 = V_5 ? V_4 -> V_10 : V_4 -> V_11 ;
V_9 = F_7 ( V_8 ) ;
if ( V_9 < 0 ) {
F_5 ( & V_8 -> V_12 , L_2 ) ;
return V_9 ;
}
* V_6 = ( T_1 ) V_9 ;
return 0 ;
}
static inline int F_8 ( struct V_1 * V_4 , unsigned V_13 )
{
return ( 1u << V_13 ) & V_4 -> V_14 ;
}
static int F_9 ( struct V_2 * V_3 , unsigned V_13 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_15 ;
int V_9 ;
V_9 = F_6 ( V_4 , F_8 ( V_4 , V_13 ) , & V_15 ) ;
if ( V_9 < 0 )
return 0 ;
return V_15 & ( 1u << ( V_13 & 0x7 ) ) ;
}
static void F_10 ( struct V_2 * V_3 , unsigned V_13 , int V_16 ,
int V_6 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_17 ;
int V_9 ;
F_11 ( & V_4 -> V_18 ) ;
V_17 = ( V_13 > 7 ) ? V_4 -> V_17 [ 1 ] : V_4 -> V_17 [ 0 ] ;
V_17 = ( V_17 & ~ V_16 ) | ( V_6 & V_16 ) ;
V_9 = F_3 ( V_4 , F_8 ( V_4 , V_13 ) , V_17 ) ;
if ( V_9 < 0 )
goto V_19;
if ( V_13 > 7 )
V_4 -> V_17 [ 1 ] = V_17 ;
else
V_4 -> V_17 [ 0 ] = V_17 ;
V_19:
F_12 ( & V_4 -> V_18 ) ;
}
static void F_13 ( struct V_2 * V_3 , unsigned V_13 , int V_6 )
{
unsigned V_20 = V_13 & ~ 0x7 ;
T_1 V_16 = 1u << ( V_13 & 0x7 ) ;
F_10 ( V_3 , V_20 , V_16 , V_6 << ( V_13 & 0x7 ) ) ;
}
static void F_14 ( struct V_2 * V_3 ,
unsigned long * V_16 , unsigned long * V_21 )
{
unsigned V_22 = V_16 [ 0 ] & 0xff ;
unsigned V_23 = ( V_16 [ 0 ] >> 8 ) & 0xff ;
if ( V_22 )
F_10 ( V_3 , 0 , V_22 , V_21 [ 0 ] & 0xff ) ;
if ( V_23 )
F_10 ( V_3 , 8 , V_23 , ( V_21 [ 0 ] >> 8 ) & 0xff ) ;
}
static int F_15 ( struct V_2 * V_3 , unsigned V_13 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned int V_16 = 1u << V_13 ;
if ( ( V_16 & V_4 -> V_24 ) == 0 ) {
F_16 ( & V_4 -> V_8 -> V_12 , L_3 ,
V_4 -> V_8 -> V_25 , V_13 ) ;
return - V_26 ;
}
if ( ( V_16 & V_4 -> V_27 ) )
F_13 ( V_3 , V_13 , 1 ) ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 ,
unsigned V_13 , int V_6 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned int V_16 = 1u << V_13 ;
if ( ( V_16 & V_4 -> V_27 ) == 0 ) {
F_16 ( & V_4 -> V_8 -> V_12 , L_4 ,
V_4 -> V_8 -> V_25 , V_13 ) ;
return - V_26 ;
}
F_13 ( V_3 , V_13 , V_6 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_4 , T_2 V_6 )
{
int V_9 ;
V_6 = F_19 ( V_6 ) ;
V_9 = F_20 ( V_4 -> V_10 , ( char * ) & V_6 , 2 ) ;
if ( V_9 < 0 ) {
F_5 ( & V_4 -> V_10 -> V_12 , L_1 ) ;
return V_9 ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_4 , T_2 * V_6 )
{
int V_9 ;
V_9 = F_22 ( V_4 -> V_10 , ( char * ) V_6 , 2 ) ;
if ( V_9 < 0 ) {
F_5 ( & V_4 -> V_10 -> V_12 , L_2 ) ;
return V_9 ;
}
* V_6 = F_23 ( * V_6 ) ;
return 0 ;
}
static void F_24 ( struct V_1 * V_4 )
{
T_2 V_28 ;
if ( V_4 -> V_29 == V_4 -> V_30 )
return;
V_4 -> V_29 = V_4 -> V_30 ;
if ( V_4 -> V_31 == V_32 )
return;
F_11 ( & V_4 -> V_18 ) ;
switch ( V_4 -> V_31 ) {
case V_33 :
V_28 = ( V_4 -> V_29 << 8 ) | V_4 -> V_17 [ 0 ] ;
F_18 ( V_4 , V_28 ) ;
break;
case V_34 :
V_28 = V_4 -> V_29 | V_4 -> V_17 [ 0 ] ;
F_3 ( V_4 , 1 , ( T_1 ) V_28 ) ;
break;
}
F_12 ( & V_4 -> V_18 ) ;
}
static void F_25 ( struct V_35 * V_36 )
{
struct V_2 * V_3 = F_26 ( V_36 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_4 -> V_30 &= ~ ( 1 << V_36 -> V_37 ) ;
}
static void F_27 ( struct V_35 * V_36 )
{
struct V_2 * V_3 = F_26 ( V_36 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_4 -> V_30 |= 1 << V_36 -> V_37 ;
}
static void F_28 ( struct V_35 * V_36 )
{
struct V_2 * V_3 = F_26 ( V_36 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_11 ( & V_4 -> V_38 ) ;
V_4 -> V_30 = V_4 -> V_29 ;
}
static void F_29 ( struct V_35 * V_36 )
{
struct V_2 * V_3 = F_26 ( V_36 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_2 V_39 ;
T_2 V_40 ;
F_24 ( V_4 ) ;
V_39 = V_4 -> V_41 | V_4 -> V_42 ;
while ( V_39 ) {
V_40 = F_30 ( V_39 ) ;
F_15 ( & V_4 -> V_2 , V_40 ) ;
V_39 &= ~ ( 1 << V_40 ) ;
}
F_12 ( & V_4 -> V_38 ) ;
}
static int F_31 ( struct V_35 * V_36 , unsigned int type )
{
struct V_2 * V_3 = F_26 ( V_36 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_2 V_13 = V_36 -> V_37 ;
T_2 V_16 = 1 << V_13 ;
if ( ! ( V_16 & V_4 -> V_24 ) ) {
F_16 ( & V_4 -> V_8 -> V_12 , L_3 ,
V_4 -> V_8 -> V_25 , V_13 ) ;
return - V_26 ;
}
if ( ! ( type & V_43 ) ) {
F_5 ( & V_4 -> V_8 -> V_12 , L_5 ,
V_36 -> V_44 , type ) ;
return - V_45 ;
}
if ( type & V_46 )
V_4 -> V_41 |= V_16 ;
else
V_4 -> V_41 &= ~ V_16 ;
if ( type & V_47 )
V_4 -> V_42 |= V_16 ;
else
V_4 -> V_42 &= ~ V_16 ;
return 0 ;
}
static T_1 F_32 ( struct V_1 * V_4 )
{
T_1 V_48 ;
T_1 V_49 ;
T_1 V_50 ;
T_1 V_51 ;
T_2 V_52 ;
int V_9 ;
V_9 = F_21 ( V_4 , & V_52 ) ;
if ( V_9 )
return 0 ;
V_50 = V_52 >> 8 ;
V_50 &= V_4 -> V_29 ;
if ( ! V_50 )
return 0 ;
V_48 = V_52 & 0xFF ;
V_48 &= V_4 -> V_29 ;
V_49 = V_48 ^ V_50 ;
V_51 = ( V_49 & V_4 -> V_41 ) |
( V_48 & V_4 -> V_42 ) ;
V_51 &= V_50 ;
return V_51 ;
}
static T_3 F_33 ( int V_44 , void * V_53 )
{
struct V_1 * V_4 = V_53 ;
T_1 V_51 ;
T_1 V_40 ;
V_51 = F_32 ( V_4 ) ;
if ( ! V_51 )
return V_54 ;
do {
V_40 = F_30 ( V_51 ) ;
F_34 ( F_35 ( V_4 -> V_2 . V_55 ,
V_40 ) ) ;
V_51 &= ~ ( 1 << V_40 ) ;
} while ( V_51 );
return V_54 ;
}
static int F_36 ( struct V_1 * V_4 ,
const struct V_56 * V_57 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_58 * V_59 = F_37 ( & V_8 -> V_12 ) ;
int V_60 = V_61 [ V_57 -> V_62 ] >> 32 ;
int V_63 = 0 ;
int V_9 ;
if ( ( ( V_59 && V_59 -> V_63 ) || V_8 -> V_44 )
&& V_60 != V_64 ) {
if ( V_59 )
V_63 = V_59 -> V_63 ;
V_4 -> V_31 = V_60 ;
F_38 ( & V_4 -> V_38 ) ;
V_9 = F_39 ( & V_8 -> V_12 ,
V_8 -> V_44 ,
NULL ,
F_33 ,
V_65 | V_66 ,
F_40 ( & V_8 -> V_12 ) , V_4 ) ;
if ( V_9 ) {
F_5 ( & V_8 -> V_12 , L_6 ,
V_8 -> V_44 ) ;
return V_9 ;
}
V_9 = F_41 ( & V_4 -> V_2 ,
& V_67 ,
V_63 ,
V_68 ,
V_69 ) ;
if ( V_9 ) {
F_5 ( & V_8 -> V_12 ,
L_7 ) ;
return V_9 ;
}
F_42 ( & V_4 -> V_2 ,
& V_67 ,
V_8 -> V_44 ,
NULL ) ;
}
return 0 ;
}
static int F_36 ( struct V_1 * V_4 ,
const struct V_56 * V_57 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_58 * V_59 = F_37 ( & V_8 -> V_12 ) ;
int V_60 = V_61 [ V_57 -> V_62 ] >> 32 ;
if ( ( ( V_59 && V_59 -> V_63 ) || V_8 -> V_44 ) && V_60 != V_64 )
F_43 ( & V_8 -> V_12 , L_8 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_4 ,
const struct V_56 * V_57 ,
unsigned V_70 )
{
struct V_2 * V_3 = & V_4 -> V_2 ;
T_4 V_71 = ( T_4 ) V_61 [ V_57 -> V_62 ] ;
int V_72 , V_73 = 0 ;
for ( V_72 = 0 ; V_72 < 16 ; V_72 ++ , V_71 >>= 2 ) {
unsigned int V_16 = 1 << V_73 ;
switch ( V_71 & 0x3 ) {
case V_74 :
V_4 -> V_27 |= V_16 ;
break;
case V_75 :
V_4 -> V_24 |= V_16 ;
break;
case V_76 :
V_4 -> V_27 |= V_16 ;
V_4 -> V_24 |= V_16 ;
break;
default:
continue;
}
if ( V_72 < 8 )
V_4 -> V_14 |= V_16 ;
V_73 ++ ;
}
if ( V_4 -> V_24 )
V_3 -> V_77 = F_15 ;
if ( V_4 -> V_27 ) {
V_3 -> V_78 = F_17 ;
V_3 -> V_79 = F_13 ;
V_3 -> V_80 = F_14 ;
}
V_3 -> V_81 = F_9 ;
V_3 -> V_82 = true ;
V_3 -> V_20 = V_70 ;
V_3 -> V_83 = V_73 ;
V_3 -> V_84 = V_4 -> V_8 -> V_25 ;
V_3 -> V_85 = V_86 ;
return V_73 ;
}
static struct V_58 * F_45 ( struct V_87 * V_12 )
{
struct V_58 * V_59 ;
V_59 = F_46 ( V_12 , sizeof( * V_59 ) , V_88 ) ;
if ( ! V_59 )
return NULL ;
V_59 -> V_89 = - 1 ;
return V_59 ;
}
static int F_47 ( struct V_7 * V_8 ,
const struct V_56 * V_57 )
{
struct V_58 * V_59 ;
struct V_90 * V_91 ;
struct V_1 * V_4 ;
struct V_7 * V_92 ;
T_2 V_93 , V_94 ;
int V_9 , V_95 ;
V_59 = F_37 ( & V_8 -> V_12 ) ;
V_91 = V_8 -> V_12 . V_96 ;
if ( ! V_59 && V_91 )
V_59 = F_45 ( & V_8 -> V_12 ) ;
if ( ! V_59 ) {
F_16 ( & V_8 -> V_12 , L_9 ) ;
return - V_45 ;
}
V_4 = F_46 ( & V_8 -> V_12 , sizeof( * V_4 ) , V_88 ) ;
if ( V_4 == NULL )
return - V_97 ;
V_4 -> V_8 = V_8 ;
V_95 = F_44 ( V_4 , V_57 , V_59 -> V_89 ) ;
V_4 -> V_2 . V_12 = & V_8 -> V_12 ;
V_93 = ( V_8 -> V_98 & 0x0f ) | 0x60 ;
V_94 = ( V_8 -> V_98 & 0x0f ) | 0x50 ;
switch ( V_8 -> V_98 & 0x70 ) {
case 0x60 :
V_4 -> V_10 = V_8 ;
if ( V_95 > 8 ) {
V_92 = F_48 ( V_8 -> V_99 , V_94 ) ;
V_4 -> V_11 = V_4 -> V_100 = V_92 ;
}
break;
case 0x50 :
V_4 -> V_11 = V_8 ;
if ( V_95 > 8 ) {
V_92 = F_48 ( V_8 -> V_99 , V_93 ) ;
V_4 -> V_10 = V_4 -> V_100 = V_92 ;
}
break;
default:
F_5 ( & V_8 -> V_12 , L_10 ,
V_8 -> V_98 ) ;
V_9 = - V_45 ;
goto V_101;
}
if ( V_95 > 8 && ! V_4 -> V_100 ) {
F_5 ( & V_8 -> V_12 ,
L_11 ) ;
V_9 = - V_102 ;
goto V_101;
}
F_38 ( & V_4 -> V_18 ) ;
F_6 ( V_4 , F_8 ( V_4 , 0 ) , & V_4 -> V_17 [ 0 ] ) ;
if ( V_95 > 8 )
F_6 ( V_4 , F_8 ( V_4 , 8 ) , & V_4 -> V_17 [ 1 ] ) ;
V_9 = F_49 ( & V_4 -> V_2 ) ;
if ( V_9 )
goto V_101;
V_9 = F_36 ( V_4 , V_57 ) ;
if ( V_9 ) {
F_50 ( & V_4 -> V_2 ) ;
goto V_101;
}
if ( V_59 && V_59 -> V_103 ) {
V_9 = V_59 -> V_103 ( V_8 , V_4 -> V_2 . V_20 ,
V_4 -> V_2 . V_83 , V_59 -> V_104 ) ;
if ( V_9 < 0 )
F_43 ( & V_8 -> V_12 , L_12 , V_9 ) ;
}
F_51 ( V_8 , V_4 ) ;
return 0 ;
V_101:
if ( V_4 -> V_100 )
F_52 ( V_4 -> V_100 ) ;
return V_9 ;
}
static int F_53 ( struct V_7 * V_8 )
{
struct V_58 * V_59 = F_37 ( & V_8 -> V_12 ) ;
struct V_1 * V_4 = F_54 ( V_8 ) ;
if ( V_59 && V_59 -> V_105 ) {
int V_9 ;
V_9 = V_59 -> V_105 ( V_8 , V_4 -> V_2 . V_20 ,
V_4 -> V_2 . V_83 , V_59 -> V_104 ) ;
if ( V_9 < 0 ) {
F_5 ( & V_8 -> V_12 , L_13 ,
L_14 , V_9 ) ;
return V_9 ;
}
}
F_50 ( & V_4 -> V_2 ) ;
if ( V_4 -> V_100 )
F_52 ( V_4 -> V_100 ) ;
return 0 ;
}
static int T_5 F_55 ( void )
{
return F_56 ( & V_106 ) ;
}
static void T_6 F_57 ( void )
{
F_58 ( & V_106 ) ;
}
