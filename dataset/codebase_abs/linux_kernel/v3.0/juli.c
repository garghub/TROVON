static int F_1 ( int V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; V_2 ++ )
if ( V_3 [ V_2 ] == V_1 )
return V_4 [ V_2 ] ;
return 0 ;
}
static void F_3 ( void * V_5 , unsigned char V_6 ,
unsigned char V_7 )
{
F_4 ( (struct V_8 * ) V_5 , V_9 ,
V_6 , V_7 ) ;
}
static unsigned char F_5 ( void * V_5 , unsigned char V_6 )
{
return F_6 ( (struct V_8 * ) V_5 ,
V_9 , V_6 ) ;
}
static void F_7 ( struct V_8 * V_10 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 = V_10 -> V_14 ;
struct V_15 * V_16 = V_12 -> V_16 ;
int V_1 ;
if ( V_12 -> V_17 == V_18 ||
! V_10 -> V_19 ( V_10 ) )
return;
V_1 = F_8 ( V_14 -> V_20 ) ;
if ( V_1 >= V_16 -> V_21 . V_22 && V_1 <= V_16 -> V_21 . V_23 ) {
V_16 -> V_21 . V_22 = V_1 ;
V_16 -> V_21 . V_23 = V_1 ;
}
}
static void F_9 ( struct V_24 * V_25 , int V_26 )
{
}
static void F_10 ( struct V_24 * V_25 , int V_26 )
{
}
static void F_11 ( struct V_24 * V_25 , int V_26 ,
unsigned char V_27 , unsigned char V_28 )
{
struct V_8 * V_10 = V_25 -> V_5 [ 0 ] ;
if ( F_12 ( V_26 ) )
return;
F_4 ( V_10 , V_29 , V_27 , V_28 ) ;
}
static void F_13 ( struct V_24 * V_25 , unsigned int V_1 )
{
unsigned char V_30 , V_31 , V_32 ;
unsigned int V_33 , V_34 , V_35 ;
struct V_8 * V_10 = V_25 -> V_5 [ 0 ] ;
struct V_13 * V_14 = V_10 -> V_14 ;
if ( V_1 == 0 )
return;
if ( V_1 > 96000 ) {
V_32 = 2 ;
V_33 = V_36 | V_37 ;
} else if ( V_1 > 48000 ) {
V_32 = 1 ;
V_33 = V_38 ;
} else {
V_32 = 0 ;
V_33 = 0 ;
}
V_34 = V_10 -> V_39 . V_40 ( V_10 ) ;
V_35 = ( V_34 & ~ V_41 ) | V_33 ;
V_10 -> V_39 . V_42 ( V_10 , V_35 ) ;
V_30 = F_14 ( F_15 ( V_10 , V_43 ) ) ;
F_16 ( V_30 | V_44 , F_15 ( V_10 , V_43 ) ) ;
F_17 ( 1 ) ;
F_16 ( V_30 & ~ V_44 , F_15 ( V_10 , V_43 ) ) ;
V_31 = F_18 ( V_25 , 0 , 2 ) ;
F_19 ( V_25 , 1 ) ;
V_31 = F_18 ( V_25 , 0 , 2 ) ;
V_31 &= ~ ( 0x03 << 4 ) ;
V_31 |= V_32 << 4 ;
F_20 ( V_25 , 0 , 2 , V_31 ) ;
F_19 ( V_25 , 0 ) ;
F_21 ( V_14 -> V_20 ) ;
}
static int F_22 ( struct V_45 * V_46 ,
struct V_47 * V_48 )
{
struct V_8 * V_10 = F_23 ( V_46 ) ;
unsigned int V_7 ;
V_7 = V_10 -> V_39 . V_40 ( V_10 ) & ( unsigned int ) V_46 -> V_49 ;
if ( V_46 -> V_49 == V_50 )
V_48 -> V_51 . integer . V_51 [ 0 ] = ( V_7 ) ? 0 : 1 ;
else
V_48 -> V_51 . integer . V_51 [ 0 ] = ( V_7 ) ? 1 : 0 ;
return 0 ;
}
static int F_24 ( struct V_45 * V_46 ,
struct V_47 * V_48 )
{
struct V_8 * V_10 = F_23 ( V_46 ) ;
unsigned int V_34 , V_35 ;
V_34 = V_10 -> V_39 . V_40 ( V_10 ) ;
if ( V_48 -> V_51 . integer . V_51 [ 0 ] ) {
if ( V_46 -> V_49 == V_50 ) {
V_35 = V_34 & ~ V_50 ;
F_25 ( V_10 -> V_52 , 0 , 0x01 , 0x01 ) ;
} else
V_35 = V_34 |
( unsigned int ) V_46 -> V_49 ;
} else {
if ( V_46 -> V_49 == V_50 ) {
V_35 = V_34 | V_50 ;
F_25 ( V_10 -> V_52 , 0 , 0x01 , 0x03 ) ;
} else
V_35 = V_34 &
~ ( ( unsigned int ) V_46 -> V_49 ) ;
}
if ( V_34 != V_35 ) {
V_10 -> V_39 . V_42 ( V_10 , V_35 ) ;
return 1 ;
}
return 0 ;
}
static struct V_45 T_1 * F_26 ( struct V_53 * V_54 ,
const char * V_55 )
{
struct V_56 V_57 ;
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
strcpy ( V_57 . V_55 , V_55 ) ;
V_57 . V_58 = V_59 ;
return F_27 ( V_54 , & V_57 ) ;
}
static void T_1 F_28 ( struct V_53 * V_54 ,
struct V_45 * V_60 , char * * V_61 )
{
for (; * V_61 ; V_61 ++ ) {
struct V_45 * V_62 = F_26 ( V_54 , * V_61 ) ;
if ( V_62 ) {
F_29 ( V_60 , V_62 ) ;
}
}
}
static int T_1 F_30 ( struct V_8 * V_10 )
{
struct V_13 * V_14 = V_10 -> V_14 ;
int V_63 ;
unsigned int V_2 ;
struct V_45 * V_64 ;
V_63 = F_31 ( V_10 ) ;
if ( V_63 < 0 )
return V_63 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_65 ) ; V_2 ++ ) {
V_63 = F_32 ( V_10 -> V_54 ,
F_33 ( & V_65 [ V_2 ] , V_10 ) ) ;
if ( V_63 < 0 )
return V_63 ;
}
V_64 = F_34 ( L_1 ,
V_66 ) ;
if ( ! V_64 )
return - V_67 ;
F_28 ( V_10 -> V_54 , V_64 , V_68 ) ;
V_63 = F_32 ( V_10 -> V_54 , V_64 ) ;
if ( V_63 < 0 )
return V_63 ;
V_63 = F_35 ( V_14 -> V_20 , NULL ,
V_10 -> V_69 -> V_70 [ V_71 ] . V_12 ) ;
if ( V_63 < 0 )
return V_63 ;
return 0 ;
}
static int F_36 ( struct V_8 * V_10 )
{
struct V_24 * V_25 = V_10 -> V_52 ;
struct V_13 * V_14 = V_10 -> V_14 ;
F_19 ( V_25 , 0 ) ;
F_21 ( V_14 -> V_20 ) ;
return 0 ;
}
static int F_37 ( struct V_8 * V_10 )
{
struct V_24 * V_25 = V_10 -> V_52 ;
F_19 ( V_25 , 1 ) ;
return 0 ;
}
static inline int F_38 ( struct V_8 * V_10 )
{
return ( V_10 -> V_39 . V_40 ( V_10 ) & V_72 ) ? 0 : 1 ;
}
static unsigned int F_39 ( struct V_8 * V_10 )
{
int V_2 ;
unsigned char V_73 ;
V_73 = V_10 -> V_39 . V_40 ( V_10 ) & V_74 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_4 ) ; V_2 ++ )
if ( V_4 [ V_2 ] == V_73 )
return V_3 [ V_2 ] ;
return 0 ;
}
static void F_40 ( struct V_8 * V_10 , unsigned int V_1 )
{
unsigned int V_30 , V_75 ;
unsigned char V_7 ;
V_30 = V_10 -> V_39 . V_40 ( V_10 ) ;
V_75 = ( V_30 & ~ V_74 ) | F_1 ( V_1 ) ;
V_10 -> V_39 . V_42 ( V_10 , V_75 ) ;
V_7 = F_14 ( F_15 ( V_10 , V_76 ) ) ;
F_16 ( V_7 | V_77 , F_15 ( V_10 , V_76 ) ) ;
}
static inline unsigned char F_41 ( struct V_8 * V_10 ,
unsigned int V_1 )
{
return 0 ;
}
static int F_42 ( struct V_8 * V_10 , int type )
{
unsigned int V_30 ;
V_30 = V_10 -> V_39 . V_40 ( V_10 ) ;
V_10 -> V_39 . V_42 ( V_10 , ( V_30 & ~ V_74 ) | V_78 |
V_79 ) ;
return 0 ;
}
static void F_43 ( struct V_20 * V_20 , unsigned char V_80 ,
unsigned char V_81 )
{
struct V_8 * V_10 = V_20 -> V_82 ;
int V_1 ;
if ( V_10 -> V_19 ( V_10 ) && V_81 ) {
V_1 = F_8 ( V_20 ) ;
F_13 ( V_10 -> V_52 , V_1 ) ;
}
}
static int T_1 F_44 ( struct V_8 * V_10 )
{
static const unsigned char V_83 [] = {
V_84 | V_85 |
V_86 | V_87 ,
V_88 ,
V_89 ,
V_90 | V_91 |
F_45 ( 1 ) ,
0 ,
0
} ;
static const unsigned char V_92 [] = {
0x41 , 0x02 , 0x2c , 0x00 , 0x00
} ;
int V_63 ;
struct V_13 * V_14 ;
struct V_24 * V_25 ;
V_14 = F_46 ( sizeof( * V_14 ) , V_93 ) ;
if ( ! V_14 )
return - V_67 ;
V_10 -> V_14 = V_14 ;
V_63 = F_47 ( V_10 -> V_54 ,
F_5 ,
F_3 ,
V_83 , V_92 ,
V_10 , & V_14 -> V_20 ) ;
if ( V_63 < 0 )
return V_63 ;
V_14 -> V_20 -> V_94 = F_43 ;
V_14 -> V_20 -> V_82 = V_10 ;
V_14 -> V_20 -> V_95 = 0 ;
#if 0
spec->analog = (ice->gpio.get_data(ice) & GPIO_ANALOG_PRESENT) ? 0 : 1;
#else
V_14 -> V_96 = 1 ;
#endif
if ( V_14 -> V_96 ) {
F_48 ( V_97 L_2 ) ;
V_10 -> V_98 = 2 ;
V_10 -> V_99 = 2 ;
V_10 -> V_52 = F_46 ( sizeof( struct V_24 ) , V_93 ) ;
V_25 = V_10 -> V_52 ;
if ( ! V_25 )
return - V_67 ;
V_10 -> V_100 = 1 ;
V_63 = F_49 ( V_25 , & V_101 , NULL , V_10 ) ;
if ( V_63 < 0 )
return V_63 ;
}
V_10 -> V_102 = & V_103 ;
V_10 -> V_19 = F_38 ;
V_10 -> V_104 = F_39 ;
V_10 -> V_105 = F_40 ;
V_10 -> V_106 = F_41 ;
V_10 -> V_107 = F_42 ;
V_10 -> V_108 . V_109 . V_110 = F_7 ;
#ifdef F_50
V_10 -> V_111 = F_36 ;
V_10 -> V_112 = F_37 ;
V_10 -> V_113 = 1 ;
#endif
return 0 ;
}
