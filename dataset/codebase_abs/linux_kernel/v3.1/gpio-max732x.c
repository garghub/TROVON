static int F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
V_6 = V_3 ? V_2 -> V_8 : V_2 -> V_9 ;
V_7 = F_2 ( V_6 , V_4 ) ;
if ( V_7 < 0 ) {
F_3 ( & V_6 -> V_10 , L_1 ) ;
return V_7 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
V_6 = V_3 ? V_2 -> V_8 : V_2 -> V_9 ;
V_7 = F_5 ( V_6 ) ;
if ( V_7 < 0 ) {
F_3 ( & V_6 -> V_10 , L_2 ) ;
return V_7 ;
}
* V_4 = ( T_1 ) V_7 ;
return 0 ;
}
static inline int F_6 ( struct V_1 * V_2 , unsigned V_11 )
{
return ( 1u << V_11 ) & V_2 -> V_12 ;
}
static int F_7 ( struct V_13 * V_14 , unsigned V_11 )
{
struct V_1 * V_2 ;
T_1 V_15 ;
int V_7 ;
V_2 = F_8 ( V_14 , struct V_1 , V_13 ) ;
V_7 = F_4 ( V_2 , F_6 ( V_2 , V_11 ) , & V_15 ) ;
if ( V_7 < 0 )
return 0 ;
return V_15 & ( 1u << ( V_11 & 0x7 ) ) ;
}
static void F_9 ( struct V_13 * V_14 , unsigned V_11 , int V_4 )
{
struct V_1 * V_2 ;
T_1 V_16 , V_17 = 1u << ( V_11 & 0x7 ) ;
int V_7 ;
V_2 = F_8 ( V_14 , struct V_1 , V_13 ) ;
F_10 ( & V_2 -> V_18 ) ;
V_16 = ( V_11 > 7 ) ? V_2 -> V_16 [ 1 ] : V_2 -> V_16 [ 0 ] ;
V_16 = ( V_4 ) ? V_16 | V_17 : V_16 & ~ V_17 ;
V_7 = F_1 ( V_2 , F_6 ( V_2 , V_11 ) , V_16 ) ;
if ( V_7 < 0 )
goto V_19;
if ( V_11 > 7 )
V_2 -> V_16 [ 1 ] = V_16 ;
else
V_2 -> V_16 [ 0 ] = V_16 ;
V_19:
F_11 ( & V_2 -> V_18 ) ;
}
static int F_12 ( struct V_13 * V_14 , unsigned V_11 )
{
struct V_1 * V_2 ;
unsigned int V_17 = 1u << V_11 ;
V_2 = F_8 ( V_14 , struct V_1 , V_13 ) ;
if ( ( V_17 & V_2 -> V_20 ) == 0 ) {
F_13 ( & V_2 -> V_6 -> V_10 , L_3 ,
V_2 -> V_6 -> V_21 , V_11 ) ;
return - V_22 ;
}
if ( ( V_17 & V_2 -> V_23 ) )
F_9 ( V_14 , V_11 , 1 ) ;
return 0 ;
}
static int F_14 ( struct V_13 * V_14 ,
unsigned V_11 , int V_4 )
{
struct V_1 * V_2 ;
unsigned int V_17 = 1u << V_11 ;
V_2 = F_8 ( V_14 , struct V_1 , V_13 ) ;
if ( ( V_17 & V_2 -> V_23 ) == 0 ) {
F_13 ( & V_2 -> V_6 -> V_10 , L_4 ,
V_2 -> V_6 -> V_21 , V_11 ) ;
return - V_22 ;
}
F_9 ( V_14 , V_11 , V_4 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , T_2 V_4 )
{
int V_7 ;
V_4 = F_16 ( V_4 ) ;
V_7 = F_17 ( V_2 -> V_8 , ( char * ) & V_4 , 2 ) ;
if ( V_7 < 0 ) {
F_3 ( & V_2 -> V_8 -> V_10 , L_1 ) ;
return V_7 ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , T_2 * V_4 )
{
int V_7 ;
V_7 = F_19 ( V_2 -> V_8 , ( char * ) V_4 , 2 ) ;
if ( V_7 < 0 ) {
F_3 ( & V_2 -> V_8 -> V_10 , L_2 ) ;
return V_7 ;
}
* V_4 = F_20 ( * V_4 ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 )
{
T_2 V_24 ;
if ( V_2 -> V_25 == V_2 -> V_26 )
return;
V_2 -> V_25 = V_2 -> V_26 ;
if ( V_2 -> V_27 == V_28 )
return;
F_10 ( & V_2 -> V_18 ) ;
switch ( V_2 -> V_27 ) {
case V_29 :
V_24 = ( V_2 -> V_25 << 8 ) | V_2 -> V_16 [ 0 ] ;
F_15 ( V_2 , V_24 ) ;
break;
case V_30 :
V_24 = V_2 -> V_25 | V_2 -> V_16 [ 0 ] ;
F_1 ( V_2 , 1 , ( T_1 ) V_24 ) ;
break;
}
F_11 ( & V_2 -> V_18 ) ;
}
static int F_22 ( struct V_13 * V_14 , unsigned V_11 )
{
struct V_1 * V_2 ;
V_2 = F_8 ( V_14 , struct V_1 , V_13 ) ;
return V_2 -> V_31 + V_11 ;
}
static void F_23 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_24 ( V_33 ) ;
V_2 -> V_26 &= ~ ( 1 << ( V_33 -> V_34 - V_2 -> V_31 ) ) ;
}
static void F_25 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_24 ( V_33 ) ;
V_2 -> V_26 |= 1 << ( V_33 -> V_34 - V_2 -> V_31 ) ;
}
static void F_26 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_24 ( V_33 ) ;
F_10 ( & V_2 -> V_35 ) ;
V_2 -> V_26 = V_2 -> V_25 ;
}
static void F_27 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_24 ( V_33 ) ;
F_21 ( V_2 ) ;
F_11 ( & V_2 -> V_35 ) ;
}
static int F_28 ( struct V_32 * V_33 , unsigned int type )
{
struct V_1 * V_2 = F_24 ( V_33 ) ;
T_2 V_11 = V_33 -> V_34 - V_2 -> V_31 ;
T_2 V_17 = 1 << V_11 ;
if ( ! ( V_17 & V_2 -> V_20 ) ) {
F_13 ( & V_2 -> V_6 -> V_10 , L_3 ,
V_2 -> V_6 -> V_21 , V_11 ) ;
return - V_22 ;
}
if ( ! ( type & V_36 ) ) {
F_3 ( & V_2 -> V_6 -> V_10 , L_5 ,
V_33 -> V_34 , type ) ;
return - V_37 ;
}
if ( type & V_38 )
V_2 -> V_39 |= V_17 ;
else
V_2 -> V_39 &= ~ V_17 ;
if ( type & V_40 )
V_2 -> V_41 |= V_17 ;
else
V_2 -> V_41 &= ~ V_17 ;
return F_12 ( & V_2 -> V_13 , V_11 ) ;
}
static T_1 F_29 ( struct V_1 * V_2 )
{
T_1 V_42 ;
T_1 V_43 ;
T_1 V_44 ;
T_1 V_45 ;
T_2 V_46 ;
int V_7 ;
V_7 = F_18 ( V_2 , & V_46 ) ;
if ( V_7 )
return 0 ;
V_44 = V_46 >> 8 ;
V_44 &= V_2 -> V_25 ;
if ( ! V_44 )
return 0 ;
V_42 = V_46 & 0xFF ;
V_42 &= V_2 -> V_25 ;
V_43 = V_42 ^ V_44 ;
V_45 = ( V_43 & V_2 -> V_39 ) |
( V_42 & V_2 -> V_41 ) ;
V_45 &= V_44 ;
return V_45 ;
}
static T_3 F_30 ( int V_34 , void * V_47 )
{
struct V_1 * V_2 = V_47 ;
T_1 V_45 ;
T_1 V_48 ;
V_45 = F_29 ( V_2 ) ;
if ( ! V_45 )
return V_49 ;
do {
V_48 = F_31 ( V_45 ) ;
F_32 ( V_48 + V_2 -> V_31 ) ;
V_45 &= ~ ( 1 << V_48 ) ;
} while ( V_45 );
return V_49 ;
}
static int F_33 ( struct V_1 * V_2 ,
const struct V_50 * V_51 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_52 * V_53 = V_6 -> V_10 . V_54 ;
int V_55 = V_56 [ V_51 -> V_57 ] >> 32 ;
int V_7 ;
if ( V_53 -> V_31 && V_55 != V_58 ) {
int V_59 ;
V_2 -> V_31 = V_53 -> V_31 ;
V_2 -> V_27 = V_55 ;
F_34 ( & V_2 -> V_35 ) ;
for ( V_59 = 0 ; V_59 < V_2 -> V_13 . V_60 ; V_59 ++ ) {
int V_34 = V_59 + V_2 -> V_31 ;
if ( ! ( V_2 -> V_20 & ( 1 << V_59 ) ) )
continue;
F_35 ( V_34 , V_2 ) ;
F_36 ( V_34 , & V_61 ,
V_62 ) ;
F_37 ( V_34 , 1 ) ;
#ifdef F_38
F_39 ( V_34 , V_63 ) ;
#else
F_40 ( V_34 ) ;
#endif
}
V_7 = F_41 ( V_6 -> V_34 ,
NULL ,
F_30 ,
V_64 | V_65 ,
F_42 ( & V_6 -> V_10 ) , V_2 ) ;
if ( V_7 ) {
F_3 ( & V_6 -> V_10 , L_6 ,
V_6 -> V_34 ) ;
goto V_66;
}
V_2 -> V_13 . V_67 = F_22 ;
}
return 0 ;
V_66:
V_2 -> V_31 = 0 ;
return V_7 ;
}
static void F_43 ( struct V_1 * V_2 )
{
if ( V_2 -> V_31 )
F_44 ( V_2 -> V_6 -> V_34 , V_2 ) ;
}
static int F_33 ( struct V_1 * V_2 ,
const struct V_50 * V_51 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_52 * V_53 = V_6 -> V_10 . V_54 ;
int V_55 = V_56 [ V_51 -> V_57 ] >> 32 ;
if ( V_53 -> V_31 && V_55 != V_58 )
F_45 ( & V_6 -> V_10 , L_7 ) ;
return 0 ;
}
static void F_43 ( struct V_1 * V_2 )
{
}
static int T_4 F_46 ( struct V_1 * V_2 ,
const struct V_50 * V_51 ,
unsigned V_68 )
{
struct V_13 * V_14 = & V_2 -> V_13 ;
T_5 V_69 = ( T_5 ) V_56 [ V_51 -> V_57 ] ;
int V_70 , V_71 = 0 ;
for ( V_70 = 0 ; V_70 < 16 ; V_70 ++ , V_69 >>= 2 ) {
unsigned int V_17 = 1 << V_71 ;
switch ( V_69 & 0x3 ) {
case V_72 :
V_2 -> V_23 |= V_17 ;
break;
case V_73 :
V_2 -> V_20 |= V_17 ;
break;
case V_74 :
V_2 -> V_23 |= V_17 ;
V_2 -> V_20 |= V_17 ;
break;
default:
continue;
}
if ( V_70 < 8 )
V_2 -> V_12 |= V_17 ;
V_71 ++ ;
}
if ( V_2 -> V_20 )
V_14 -> V_75 = F_12 ;
if ( V_2 -> V_23 ) {
V_14 -> V_76 = F_14 ;
V_14 -> V_77 = F_9 ;
}
V_14 -> V_78 = F_7 ;
V_14 -> V_79 = 1 ;
V_14 -> V_80 = V_68 ;
V_14 -> V_60 = V_71 ;
V_14 -> V_81 = V_2 -> V_6 -> V_21 ;
V_14 -> V_82 = V_83 ;
return V_71 ;
}
static int T_4 F_47 ( struct V_5 * V_6 ,
const struct V_50 * V_51 )
{
struct V_52 * V_53 ;
struct V_1 * V_2 ;
struct V_5 * V_84 ;
T_2 V_85 , V_86 ;
int V_7 , V_87 ;
V_53 = V_6 -> V_10 . V_54 ;
if ( V_53 == NULL ) {
F_13 ( & V_6 -> V_10 , L_8 ) ;
return - V_37 ;
}
V_2 = F_48 ( sizeof( struct V_1 ) , V_88 ) ;
if ( V_2 == NULL )
return - V_89 ;
V_2 -> V_6 = V_6 ;
V_87 = F_46 ( V_2 , V_51 , V_53 -> V_90 ) ;
V_85 = ( V_6 -> V_91 & 0x0f ) | 0x60 ;
V_86 = ( V_6 -> V_91 & 0x0f ) | 0x50 ;
switch ( V_6 -> V_91 & 0x70 ) {
case 0x60 :
V_2 -> V_8 = V_6 ;
if ( V_87 > 8 ) {
V_84 = F_49 ( V_6 -> V_92 , V_86 ) ;
V_2 -> V_9 = V_2 -> V_93 = V_84 ;
}
break;
case 0x50 :
V_2 -> V_9 = V_6 ;
if ( V_87 > 8 ) {
V_84 = F_49 ( V_6 -> V_92 , V_85 ) ;
V_2 -> V_8 = V_2 -> V_93 = V_84 ;
}
break;
default:
F_3 ( & V_6 -> V_10 , L_9 ,
V_6 -> V_91 ) ;
V_7 = - V_37 ;
goto V_66;
}
F_34 ( & V_2 -> V_18 ) ;
F_4 ( V_2 , F_6 ( V_2 , 0 ) , & V_2 -> V_16 [ 0 ] ) ;
if ( V_87 > 8 )
F_4 ( V_2 , F_6 ( V_2 , 8 ) , & V_2 -> V_16 [ 1 ] ) ;
V_7 = F_33 ( V_2 , V_51 ) ;
if ( V_7 )
goto V_66;
V_7 = F_50 ( & V_2 -> V_13 ) ;
if ( V_7 )
goto V_66;
if ( V_53 -> V_94 ) {
V_7 = V_53 -> V_94 ( V_6 , V_2 -> V_13 . V_80 ,
V_2 -> V_13 . V_60 , V_53 -> V_95 ) ;
if ( V_7 < 0 )
F_45 ( & V_6 -> V_10 , L_10 , V_7 ) ;
}
F_51 ( V_6 , V_2 ) ;
return 0 ;
V_66:
F_43 ( V_2 ) ;
F_52 ( V_2 ) ;
return V_7 ;
}
static int T_6 F_53 ( struct V_5 * V_6 )
{
struct V_52 * V_53 = V_6 -> V_10 . V_54 ;
struct V_1 * V_2 = F_54 ( V_6 ) ;
int V_7 ;
if ( V_53 -> V_96 ) {
V_7 = V_53 -> V_96 ( V_6 , V_2 -> V_13 . V_80 ,
V_2 -> V_13 . V_60 , V_53 -> V_95 ) ;
if ( V_7 < 0 ) {
F_3 ( & V_6 -> V_10 , L_11 ,
L_12 , V_7 ) ;
return V_7 ;
}
}
V_7 = F_55 ( & V_2 -> V_13 ) ;
if ( V_7 ) {
F_3 ( & V_6 -> V_10 , L_11 ,
L_13 , V_7 ) ;
return V_7 ;
}
F_43 ( V_2 ) ;
if ( V_2 -> V_93 )
F_56 ( V_2 -> V_93 ) ;
F_52 ( V_2 ) ;
return 0 ;
}
static int T_7 F_57 ( void )
{
return F_58 ( & V_97 ) ;
}
static void T_8 F_59 ( void )
{
F_60 ( & V_97 ) ;
}
