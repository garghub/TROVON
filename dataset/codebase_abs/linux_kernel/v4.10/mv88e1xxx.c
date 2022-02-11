static void F_1 ( struct V_1 * V_1 , int V_2 , T_1 V_3 )
{
T_1 V_4 ;
( void ) F_2 ( V_1 , V_2 , & V_4 ) ;
( void ) F_3 ( V_1 , V_2 , V_4 | V_3 ) ;
}
static void F_4 ( struct V_1 * V_1 , int V_2 , T_1 V_3 )
{
T_1 V_4 ;
( void ) F_2 ( V_1 , V_2 , & V_4 ) ;
( void ) F_3 ( V_1 , V_2 , V_4 & ~ V_3 ) ;
}
static int F_5 ( struct V_1 * V_1 , int V_5 )
{
T_1 V_6 ;
int V_7 = 1000 ;
F_1 ( V_1 , V_8 , V_9 ) ;
do {
( void ) F_2 ( V_1 , V_8 , & V_6 ) ;
V_6 &= V_9 ;
if ( V_6 )
F_6 ( 1 ) ;
} while ( V_6 && -- V_7 );
return V_6 ? - 1 : 0 ;
}
static int F_7 ( struct V_1 * V_1 )
{
( void ) F_3 ( V_1 , V_10 ,
V_11 ) ;
if ( F_8 ( V_1 -> V_12 ) ) {
T_1 V_13 ;
F_9 ( V_1 -> V_12 , V_14 , & V_13 ) ;
V_13 |= V_15 ;
if ( F_10 ( V_1 -> V_12 ) )
V_13 |= V_16 | V_17 | V_18 ;
F_11 ( V_1 -> V_12 , V_14 , V_13 ) ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_1 )
{
( void ) F_3 ( V_1 , V_10 , 0 ) ;
if ( F_8 ( V_1 -> V_12 ) ) {
T_1 V_13 ;
F_9 ( V_1 -> V_12 , V_14 , & V_13 ) ;
V_13 &= ~ V_15 ;
if ( F_10 ( V_1 -> V_12 ) )
V_13 &= ~ ( V_16 | V_17 | V_18 ) ;
F_11 ( V_1 -> V_12 , V_14 , V_13 ) ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_1 )
{
T_1 V_13 ;
( void ) F_2 ( V_1 ,
V_19 , & V_13 ) ;
if ( F_8 ( V_1 -> V_12 ) ) {
F_9 ( V_1 -> V_12 , V_20 , & V_13 ) ;
V_13 |= V_15 ;
if ( F_10 ( V_1 -> V_12 ) )
V_13 |= V_16 | V_17 | V_18 ;
F_11 ( V_1 -> V_12 , V_20 , V_13 ) ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_21 , int V_22 , int V_23 )
{
T_1 V_6 ;
( void ) F_2 ( V_21 , V_8 , & V_6 ) ;
if ( V_22 >= 0 ) {
V_6 &= ~ ( V_24 | V_25 | V_26 ) ;
if ( V_22 == V_27 )
V_6 |= V_24 ;
else if ( V_22 == V_28 )
V_6 |= V_25 ;
}
if ( V_23 >= 0 ) {
V_6 &= ~ ( V_29 | V_26 ) ;
if ( V_23 == V_30 )
V_6 |= V_29 ;
}
if ( V_6 & V_25 )
V_6 |= V_26 ;
( void ) F_3 ( V_21 , V_8 , V_6 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_1 , int V_31 )
{
T_1 V_32 ;
( void ) F_2 ( V_1 ,
V_33 , & V_32 ) ;
V_32 &= ~ F_16 ( V_34 ) ;
V_32 |= F_16 ( V_31 ) ;
( void ) F_3 ( V_1 ,
V_33 , V_32 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_1 )
{
T_1 V_6 ;
( void ) F_15 ( V_1 , V_35 ) ;
( void ) F_2 ( V_1 , V_8 , & V_6 ) ;
V_6 |= V_26 | V_36 ;
( void ) F_3 ( V_1 , V_8 , V_6 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_1 )
{
T_1 V_6 ;
( void ) F_15 ( V_1 , V_37 ) ;
( void ) F_2 ( V_1 , V_8 , & V_6 ) ;
V_6 &= ~ V_26 ;
( void ) F_3 ( V_1 , V_8 , V_6 | V_36 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_1 )
{
F_1 ( V_1 , V_8 , V_36 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_21 , unsigned int V_38 )
{
T_1 V_4 = 0 ;
if ( V_38 &
( V_39 | V_40 ) ) {
( void ) F_2 ( V_21 , V_41 , & V_4 ) ;
V_4 &= ~ ( V_42 | V_43 ) ;
if ( V_38 & V_39 )
V_4 |= V_42 ;
if ( V_38 & V_40 )
V_4 |= V_43 ;
}
( void ) F_3 ( V_21 , V_41 , V_4 ) ;
V_4 = 1 ;
if ( V_38 & V_44 )
V_4 |= V_45 ;
if ( V_38 & V_46 )
V_4 |= V_47 ;
if ( V_38 & V_48 )
V_4 |= V_49 ;
if ( V_38 & V_50 )
V_4 |= V_51 ;
if ( V_38 & V_52 )
V_4 |= V_53 ;
if ( V_38 & V_54 )
V_4 |= V_55 ;
( void ) F_3 ( V_21 , V_56 , V_4 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_1 , int V_57 )
{
if ( V_57 )
F_1 ( V_1 , V_8 , V_58 ) ;
else
F_4 ( V_1 , V_8 , V_58 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_1 , int * V_59 ,
int * V_22 , int * V_23 , int * V_60 )
{
T_1 V_61 ;
int V_62 = - 1 , V_63 = - 1 , V_64 = 0 ;
( void ) F_2 ( V_1 ,
V_65 , & V_61 ) ;
if ( ( V_61 & V_66 ) != 0 ) {
if ( V_61 & V_67 )
V_64 |= V_68 ;
if ( V_61 & V_69 )
V_64 |= V_70 ;
V_63 = ( V_61 & V_71 ) ? V_30 : V_72 ;
V_62 = F_23 ( V_61 ) ;
if ( V_62 == 0 )
V_62 = V_73 ;
else if ( V_62 == 1 )
V_62 = V_27 ;
else
V_62 = V_28 ;
}
if ( V_59 )
* V_59 = ( V_61 & V_74 ) != 0 ;
if ( V_22 )
* V_22 = V_62 ;
if ( V_23 )
* V_23 = V_63 ;
if ( V_60 )
* V_60 = V_64 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_1 , int V_75 )
{
T_1 V_4 ;
( void ) F_2 ( V_1 ,
V_76 , & V_4 ) ;
V_4 &= ~ ( V_77 | F_25 ( V_78 ) ) ;
if ( V_75 )
V_4 |= V_77 | F_25 ( 2 ) ;
( void ) F_3 ( V_1 ,
V_76 , V_4 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_1 )
{
int V_79 = 0 ;
T_1 V_61 ;
while ( 1 ) {
T_1 V_80 ;
( void ) F_2 ( V_1 ,
V_19 ,
& V_80 ) ;
V_80 &= V_11 ;
if ( ! V_80 )
break;
if ( V_80 & V_81 ) {
( void ) F_2 ( V_1 ,
V_65 , & V_61 ) ;
if ( V_61 & V_81 )
V_1 -> V_82 |= V_83 ;
else {
V_1 -> V_82 &= ~ V_83 ;
if ( V_1 -> V_82 & V_84 )
V_1 -> V_82 &= ~ V_85 ;
V_79 |= V_86 ;
}
}
if ( V_80 & V_87 )
V_1 -> V_82 |= V_85 ;
if ( ( V_1 -> V_82 & ( V_83 | V_85 ) ) ==
( V_83 | V_85 ) )
V_79 |= V_86 ;
}
return V_79 ;
}
static void F_27 ( struct V_1 * V_1 )
{
F_28 ( V_1 ) ;
}
static struct V_1 * F_29 ( struct V_88 * V_89 , int V_90 ,
const struct V_91 * V_91 )
{
struct V_12 * V_12 = F_30 ( V_89 ) ;
struct V_1 * V_1 = F_31 ( sizeof( * V_1 ) , V_92 ) ;
if ( ! V_1 )
return NULL ;
F_32 ( V_1 , V_89 , V_90 , & V_93 , V_91 ) ;
if ( ( F_33 ( V_12 ) -> V_94 & V_95 ) &&
F_33 ( V_12 ) -> V_96 == V_97 ) {
( void ) F_3 ( V_1 ,
V_98 , 0xB ) ;
( void ) F_3 ( V_1 ,
V_99 , 0x8004 ) ;
}
( void ) F_24 ( V_1 , 1 ) ;
if ( F_10 ( V_12 ) ) {
( void ) F_3 ( V_1 ,
V_100 , 0x1 ) ;
}
return V_1 ;
}
static int F_34 ( T_2 * V_12 )
{
return 0 ;
}
