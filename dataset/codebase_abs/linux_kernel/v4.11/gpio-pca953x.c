static int F_1 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 ,
int V_5 )
{
int V_6 ;
int V_7 = F_2 ( ( V_2 -> V_8 . V_9 - 1 ) / V_10 ) ;
int V_11 = V_5 / V_10 ;
V_6 = F_3 ( V_2 -> V_12 ,
( V_3 << V_7 ) + V_11 ) ;
* V_4 = V_6 ;
if ( V_6 < 0 ) {
F_4 ( & V_2 -> V_12 -> V_13 , L_1 ) ;
return V_6 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 , T_1 V_4 ,
int V_5 )
{
int V_6 ;
int V_7 = F_2 ( ( V_2 -> V_8 . V_9 - 1 ) / V_10 ) ;
int V_11 = V_5 / V_10 ;
V_6 = F_6 ( V_2 -> V_12 ,
( V_3 << V_7 ) + V_11 , V_4 ) ;
if ( V_6 < 0 ) {
F_4 ( & V_2 -> V_12 -> V_13 , L_2 ) ;
return V_6 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , int V_3 , T_2 * V_4 )
{
return F_6 ( V_2 -> V_12 , V_3 , * V_4 ) ;
}
static int F_8 ( struct V_1 * V_2 , int V_3 , T_2 * V_4 )
{
T_3 V_14 = F_9 ( F_10 ( ( V_15 * ) V_4 ) ) ;
return F_11 ( V_2 -> V_12 ,
V_3 << 1 , ( V_16 V_15 ) V_14 ) ;
}
static int F_12 ( struct V_1 * V_2 , int V_3 , T_2 * V_4 )
{
int V_6 ;
V_6 = F_6 ( V_2 -> V_12 , V_3 << 1 , V_4 [ 0 ] ) ;
if ( V_6 < 0 )
return V_6 ;
return F_6 ( V_2 -> V_12 , ( V_3 << 1 ) + 1 , V_4 [ 1 ] ) ;
}
static int F_13 ( struct V_1 * V_2 , int V_3 , T_2 * V_4 )
{
int V_7 = F_2 ( ( V_2 -> V_8 . V_9 - 1 ) / V_10 ) ;
return F_14 ( V_2 -> V_12 ,
( V_3 << V_7 ) | V_17 ,
F_15 ( V_2 ) , V_4 ) ;
}
static int F_16 ( struct V_1 * V_2 , int V_3 , T_2 * V_4 )
{
int V_6 = 0 ;
V_6 = V_2 -> V_18 ( V_2 , V_3 , V_4 ) ;
if ( V_6 < 0 ) {
F_4 ( & V_2 -> V_12 -> V_13 , L_2 ) ;
return V_6 ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , int V_3 , T_2 * V_4 )
{
int V_6 ;
V_6 = F_3 ( V_2 -> V_12 , V_3 ) ;
* V_4 = V_6 ;
return V_6 ;
}
static int F_18 ( struct V_1 * V_2 , int V_3 , T_2 * V_4 )
{
int V_6 ;
V_6 = F_19 ( V_2 -> V_12 , V_3 << 1 ) ;
V_4 [ 0 ] = ( V_15 ) V_6 & 0xFF ;
V_4 [ 1 ] = ( V_15 ) V_6 >> 8 ;
return V_6 ;
}
static int F_20 ( struct V_1 * V_2 , int V_3 , T_2 * V_4 )
{
int V_7 = F_2 ( ( V_2 -> V_8 . V_9 - 1 ) / V_10 ) ;
return F_21 ( V_2 -> V_12 ,
( V_3 << V_7 ) | V_17 ,
F_15 ( V_2 ) , V_4 ) ;
}
static int F_22 ( struct V_1 * V_2 , int V_3 , T_2 * V_4 )
{
int V_6 ;
V_6 = V_2 -> V_19 ( V_2 , V_3 , V_4 ) ;
if ( V_6 < 0 ) {
F_4 ( & V_2 -> V_12 -> V_13 , L_1 ) ;
return V_6 ;
}
return 0 ;
}
static int F_23 ( struct V_8 * V_20 , unsigned V_5 )
{
struct V_1 * V_2 = F_24 ( V_20 ) ;
T_2 V_21 ;
int V_6 ;
F_25 ( & V_2 -> V_22 ) ;
V_21 = V_2 -> V_23 [ V_5 / V_10 ] | ( 1u << ( V_5 % V_10 ) ) ;
V_6 = F_5 ( V_2 , V_2 -> V_24 -> V_25 , V_21 , V_5 ) ;
if ( V_6 )
goto exit;
V_2 -> V_23 [ V_5 / V_10 ] = V_21 ;
exit:
F_26 ( & V_2 -> V_22 ) ;
return V_6 ;
}
static int F_27 ( struct V_8 * V_20 ,
unsigned V_5 , int V_4 )
{
struct V_1 * V_2 = F_24 ( V_20 ) ;
T_2 V_21 ;
int V_6 ;
F_25 ( & V_2 -> V_22 ) ;
if ( V_4 )
V_21 = V_2 -> V_26 [ V_5 / V_10 ]
| ( 1u << ( V_5 % V_10 ) ) ;
else
V_21 = V_2 -> V_26 [ V_5 / V_10 ]
& ~ ( 1u << ( V_5 % V_10 ) ) ;
V_6 = F_5 ( V_2 , V_2 -> V_24 -> V_27 , V_21 , V_5 ) ;
if ( V_6 )
goto exit;
V_2 -> V_26 [ V_5 / V_10 ] = V_21 ;
V_21 = V_2 -> V_23 [ V_5 / V_10 ] & ~ ( 1u << ( V_5 % V_10 ) ) ;
V_6 = F_5 ( V_2 , V_2 -> V_24 -> V_25 , V_21 , V_5 ) ;
if ( V_6 )
goto exit;
V_2 -> V_23 [ V_5 / V_10 ] = V_21 ;
exit:
F_26 ( & V_2 -> V_22 ) ;
return V_6 ;
}
static int F_28 ( struct V_8 * V_20 , unsigned V_5 )
{
struct V_1 * V_2 = F_24 ( V_20 ) ;
T_1 V_21 ;
int V_6 ;
F_25 ( & V_2 -> V_22 ) ;
V_6 = F_1 ( V_2 , V_2 -> V_24 -> V_28 , & V_21 , V_5 ) ;
F_26 ( & V_2 -> V_22 ) ;
if ( V_6 < 0 ) {
return 0 ;
}
return ( V_21 & ( 1u << ( V_5 % V_10 ) ) ) ? 1 : 0 ;
}
static void F_29 ( struct V_8 * V_20 , unsigned V_5 , int V_4 )
{
struct V_1 * V_2 = F_24 ( V_20 ) ;
T_2 V_21 ;
int V_6 ;
F_25 ( & V_2 -> V_22 ) ;
if ( V_4 )
V_21 = V_2 -> V_26 [ V_5 / V_10 ]
| ( 1u << ( V_5 % V_10 ) ) ;
else
V_21 = V_2 -> V_26 [ V_5 / V_10 ]
& ~ ( 1u << ( V_5 % V_10 ) ) ;
V_6 = F_5 ( V_2 , V_2 -> V_24 -> V_27 , V_21 , V_5 ) ;
if ( V_6 )
goto exit;
V_2 -> V_26 [ V_5 / V_10 ] = V_21 ;
exit:
F_26 ( & V_2 -> V_22 ) ;
}
static void F_30 ( struct V_8 * V_20 ,
unsigned long * V_29 , unsigned long * V_30 )
{
struct V_1 * V_2 = F_24 ( V_20 ) ;
unsigned int V_31 , V_32 ;
int V_7 , V_33 ;
T_2 V_21 [ V_34 ] ;
int V_6 ;
V_7 = F_2 ( ( V_2 -> V_8 . V_9 - 1 ) / V_10 ) ;
F_25 ( & V_2 -> V_22 ) ;
memcpy ( V_21 , V_2 -> V_26 , F_15 ( V_2 ) ) ;
for ( V_33 = 0 ; V_33 < F_15 ( V_2 ) ; V_33 ++ ) {
V_31 = V_29 [ V_33 / sizeof( * V_29 ) ] >>
( ( V_33 % sizeof( * V_29 ) ) * 8 ) ;
if ( V_31 ) {
V_32 = V_30 [ V_33 / sizeof( * V_30 ) ] >>
( ( V_33 % sizeof( * V_30 ) ) * 8 ) ;
V_32 &= V_31 ;
V_21 [ V_33 ] = ( V_21 [ V_33 ] & ~ V_31 ) | V_32 ;
}
}
V_6 = F_14 ( V_2 -> V_12 ,
V_2 -> V_24 -> V_27 << V_7 ,
F_15 ( V_2 ) , V_21 ) ;
if ( V_6 )
goto exit;
memcpy ( V_2 -> V_26 , V_21 , F_15 ( V_2 ) ) ;
exit:
F_26 ( & V_2 -> V_22 ) ;
}
static void F_31 ( struct V_1 * V_2 , int V_35 )
{
struct V_8 * V_20 ;
V_20 = & V_2 -> V_8 ;
V_20 -> V_36 = F_23 ;
V_20 -> V_37 = F_27 ;
V_20 -> V_38 = F_28 ;
V_20 -> V_39 = F_29 ;
V_20 -> V_40 = F_30 ;
V_20 -> V_41 = true ;
V_20 -> V_42 = V_2 -> V_43 ;
V_20 -> V_9 = V_35 ;
V_20 -> V_44 = V_2 -> V_12 -> V_45 ;
V_20 -> V_46 = & V_2 -> V_12 -> V_13 ;
V_20 -> V_47 = V_48 ;
V_20 -> V_49 = V_2 -> V_49 ;
}
static void F_32 ( struct V_50 * V_51 )
{
struct V_8 * V_20 = F_33 ( V_51 ) ;
struct V_1 * V_2 = F_24 ( V_20 ) ;
V_2 -> V_52 [ V_51 -> V_53 / V_10 ] &= ~ ( 1 << ( V_51 -> V_53 % V_10 ) ) ;
}
static void F_34 ( struct V_50 * V_51 )
{
struct V_8 * V_20 = F_33 ( V_51 ) ;
struct V_1 * V_2 = F_24 ( V_20 ) ;
V_2 -> V_52 [ V_51 -> V_53 / V_10 ] |= 1 << ( V_51 -> V_53 % V_10 ) ;
}
static void F_35 ( struct V_50 * V_51 )
{
struct V_8 * V_20 = F_33 ( V_51 ) ;
struct V_1 * V_2 = F_24 ( V_20 ) ;
F_25 ( & V_2 -> V_54 ) ;
}
static void F_36 ( struct V_50 * V_51 )
{
struct V_8 * V_20 = F_33 ( V_51 ) ;
struct V_1 * V_2 = F_24 ( V_20 ) ;
T_2 V_55 ;
int V_56 , V_57 ;
T_2 V_58 [ V_34 ] ;
if ( V_2 -> V_59 & V_60 ) {
F_16 ( V_2 , V_61 , V_2 -> V_52 ) ;
for ( V_57 = 0 ; V_57 < F_15 ( V_2 ) ; V_57 ++ )
V_58 [ V_57 ] = ~ V_2 -> V_52 [ V_57 ] ;
F_16 ( V_2 , V_62 , V_58 ) ;
}
for ( V_57 = 0 ; V_57 < F_15 ( V_2 ) ; V_57 ++ ) {
V_55 = V_2 -> V_63 [ V_57 ] | V_2 -> V_64 [ V_57 ] ;
V_55 &= ~ V_2 -> V_23 [ V_57 ] ;
while ( V_55 ) {
V_56 = F_37 ( V_55 ) ;
F_23 ( & V_2 -> V_8 ,
V_56 + ( V_10 * V_57 ) ) ;
V_55 &= ~ ( 1 << V_56 ) ;
}
}
F_26 ( & V_2 -> V_54 ) ;
}
static int F_38 ( struct V_50 * V_51 , unsigned int type )
{
struct V_8 * V_20 = F_33 ( V_51 ) ;
struct V_1 * V_2 = F_24 ( V_20 ) ;
int V_65 = V_51 -> V_53 / V_10 ;
T_2 V_29 = 1 << ( V_51 -> V_53 % V_10 ) ;
if ( ! ( type & V_66 ) ) {
F_4 ( & V_2 -> V_12 -> V_13 , L_3 ,
V_51 -> V_67 , type ) ;
return - V_68 ;
}
if ( type & V_69 )
V_2 -> V_63 [ V_65 ] |= V_29 ;
else
V_2 -> V_63 [ V_65 ] &= ~ V_29 ;
if ( type & V_70 )
V_2 -> V_64 [ V_65 ] |= V_29 ;
else
V_2 -> V_64 [ V_65 ] &= ~ V_29 ;
return 0 ;
}
static bool F_39 ( struct V_1 * V_2 , T_2 * V_71 )
{
T_2 V_72 [ V_34 ] ;
T_2 V_73 [ V_34 ] ;
bool V_74 = false ;
bool V_75 = false ;
T_2 V_76 [ V_34 ] ;
int V_6 , V_57 ;
if ( V_2 -> V_59 & V_60 ) {
V_6 = F_22 ( V_2 , V_77 , V_76 ) ;
if ( V_6 )
return false ;
V_6 = F_22 ( V_2 , V_78 , V_72 ) ;
if ( V_6 )
return false ;
for ( V_57 = 0 ; V_57 < F_15 ( V_2 ) ; V_57 ++ ) {
V_71 [ V_57 ] = ( ~ V_72 [ V_57 ] & V_2 -> V_63 [ V_57 ] ) |
( V_72 [ V_57 ] & V_2 -> V_64 [ V_57 ] ) ;
V_71 [ V_57 ] &= V_76 [ V_57 ] ;
if ( V_71 [ V_57 ] )
V_74 = true ;
}
return V_74 ;
}
V_6 = F_22 ( V_2 , V_2 -> V_24 -> V_28 , V_72 ) ;
if ( V_6 )
return false ;
for ( V_57 = 0 ; V_57 < F_15 ( V_2 ) ; V_57 ++ )
V_72 [ V_57 ] &= V_2 -> V_23 [ V_57 ] ;
memcpy ( V_73 , V_2 -> V_79 , F_15 ( V_2 ) ) ;
for ( V_57 = 0 ; V_57 < F_15 ( V_2 ) ; V_57 ++ ) {
V_76 [ V_57 ] = ( V_72 [ V_57 ] ^ V_73 [ V_57 ] ) & V_2 -> V_52 [ V_57 ] ;
if ( V_76 [ V_57 ] )
V_75 = true ;
}
if ( ! V_75 )
return false ;
memcpy ( V_2 -> V_79 , V_72 , F_15 ( V_2 ) ) ;
for ( V_57 = 0 ; V_57 < F_15 ( V_2 ) ; V_57 ++ ) {
V_71 [ V_57 ] = ( V_73 [ V_57 ] & V_2 -> V_63 [ V_57 ] ) |
( V_72 [ V_57 ] & V_2 -> V_64 [ V_57 ] ) ;
V_71 [ V_57 ] &= V_76 [ V_57 ] ;
if ( V_71 [ V_57 ] )
V_74 = true ;
}
return V_74 ;
}
static T_4 F_40 ( int V_67 , void * V_80 )
{
struct V_1 * V_2 = V_80 ;
T_2 V_71 [ V_34 ] ;
T_2 V_56 ;
unsigned V_81 = 0 ;
int V_57 ;
if ( ! F_39 ( V_2 , V_71 ) )
return V_82 ;
for ( V_57 = 0 ; V_57 < F_15 ( V_2 ) ; V_57 ++ ) {
while ( V_71 [ V_57 ] ) {
V_56 = F_37 ( V_71 [ V_57 ] ) ;
F_41 ( F_42 ( V_2 -> V_8 . V_83 ,
V_56 + ( V_10 * V_57 ) ) ) ;
V_71 [ V_57 ] &= ~ ( 1 << V_56 ) ;
V_81 ++ ;
}
}
return ( V_81 > 0 ) ? V_84 : V_82 ;
}
static int F_43 ( struct V_1 * V_2 ,
int V_85 )
{
struct V_86 * V_12 = V_2 -> V_12 ;
int V_6 , V_57 ;
if ( V_12 -> V_67 && V_85 != - 1
&& ( V_2 -> V_59 & V_87 ) ) {
V_6 = F_22 ( V_2 ,
V_2 -> V_24 -> V_28 , V_2 -> V_79 ) ;
if ( V_6 )
return V_6 ;
for ( V_57 = 0 ; V_57 < F_15 ( V_2 ) ; V_57 ++ )
V_2 -> V_79 [ V_57 ] &= V_2 -> V_23 [ V_57 ] ;
F_44 ( & V_2 -> V_54 ) ;
V_6 = F_45 ( & V_12 -> V_13 ,
V_12 -> V_67 ,
NULL ,
F_40 ,
V_88 | V_89 |
V_90 ,
F_46 ( & V_12 -> V_13 ) , V_2 ) ;
if ( V_6 ) {
F_4 ( & V_12 -> V_13 , L_4 ,
V_12 -> V_67 ) ;
return V_6 ;
}
V_6 = F_47 ( & V_2 -> V_8 ,
& V_91 ,
V_85 ,
V_92 ,
V_93 ) ;
if ( V_6 ) {
F_4 ( & V_12 -> V_13 ,
L_5 ) ;
return V_6 ;
}
F_48 ( & V_2 -> V_8 ,
& V_91 ,
V_12 -> V_67 ) ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 ,
int V_85 )
{
struct V_86 * V_12 = V_2 -> V_12 ;
if ( V_85 != - 1 && ( V_2 -> V_59 & V_87 ) )
F_49 ( & V_12 -> V_13 , L_6 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 , T_1 V_94 )
{
int V_6 ;
T_2 V_4 [ V_34 ] ;
V_2 -> V_24 = & V_95 ;
V_6 = F_22 ( V_2 , V_2 -> V_24 -> V_27 , V_2 -> V_26 ) ;
if ( V_6 )
goto V_96;
V_6 = F_22 ( V_2 , V_2 -> V_24 -> V_25 ,
V_2 -> V_23 ) ;
if ( V_6 )
goto V_96;
if ( V_94 )
memset ( V_4 , 0xFF , F_15 ( V_2 ) ) ;
else
memset ( V_4 , 0 , F_15 ( V_2 ) ) ;
V_6 = F_16 ( V_2 , V_97 , V_4 ) ;
V_96:
return V_6 ;
}
static int F_51 ( struct V_1 * V_2 , T_1 V_94 )
{
int V_6 ;
T_2 V_4 [ V_34 ] ;
V_2 -> V_24 = & V_98 ;
V_6 = F_22 ( V_2 , V_2 -> V_24 -> V_27 , V_2 -> V_26 ) ;
if ( V_6 )
goto V_96;
V_6 = F_22 ( V_2 , V_2 -> V_24 -> V_25 ,
V_2 -> V_23 ) ;
if ( V_6 )
goto V_96;
if ( V_94 )
memset ( V_4 , 0xFF , F_15 ( V_2 ) ) ;
else
memset ( V_4 , 0 , F_15 ( V_2 ) ) ;
V_6 = F_16 ( V_2 , V_99 , V_4 ) ;
if ( V_6 )
goto V_96;
memset ( V_4 , 0x02 , F_15 ( V_2 ) ) ;
V_6 = F_16 ( V_2 , V_100 , V_4 ) ;
if ( V_6 )
goto V_96;
return 0 ;
V_96:
return V_6 ;
}
static int F_52 ( struct V_86 * V_12 ,
const struct V_101 * V_102 )
{
struct V_103 * V_104 ;
struct V_1 * V_2 ;
int V_85 = 0 ;
int V_6 ;
T_1 V_94 = 0 ;
struct V_105 * V_3 ;
V_2 = F_53 ( & V_12 -> V_13 ,
sizeof( struct V_1 ) , V_106 ) ;
if ( V_2 == NULL )
return - V_107 ;
V_104 = F_54 ( & V_12 -> V_13 ) ;
if ( V_104 ) {
V_85 = V_104 -> V_85 ;
V_2 -> V_43 = V_104 -> V_108 ;
V_94 = V_104 -> V_94 ;
V_2 -> V_49 = V_104 -> V_49 ;
} else {
struct V_109 * V_110 ;
V_2 -> V_43 = - 1 ;
V_85 = 0 ;
V_110 = F_55 ( & V_12 -> V_13 , L_7 ,
V_111 ) ;
if ( F_56 ( V_110 ) )
return F_57 ( V_110 ) ;
}
V_2 -> V_12 = V_12 ;
V_3 = F_58 ( & V_12 -> V_13 , L_8 ) ;
if ( F_56 ( V_3 ) ) {
V_6 = F_57 ( V_3 ) ;
if ( V_6 != - V_112 )
F_4 ( & V_12 -> V_13 , L_9 , V_6 ) ;
return V_6 ;
}
V_6 = F_59 ( V_3 ) ;
if ( V_6 ) {
F_4 ( & V_12 -> V_13 , L_10 , V_6 ) ;
return V_6 ;
}
V_2 -> V_105 = V_3 ;
if ( V_102 ) {
V_2 -> V_59 = V_102 -> V_59 ;
} else {
const struct V_113 * V_114 ;
const struct V_115 * V_116 ;
V_116 = F_60 ( V_117 , & V_12 -> V_13 ) ;
if ( V_116 ) {
V_2 -> V_59 = ( int ) ( V_118 ) V_116 -> V_119 ;
} else {
V_114 = F_61 ( V_120 , & V_12 -> V_13 ) ;
if ( ! V_114 ) {
V_6 = - V_121 ;
goto V_122;
}
V_2 -> V_59 = V_114 -> V_59 ;
}
}
F_44 ( & V_2 -> V_22 ) ;
F_62 ( & V_2 -> V_22 ,
F_63 ( V_12 -> V_123 ) ) ;
F_31 ( V_2 , V_2 -> V_59 & V_124 ) ;
if ( V_2 -> V_8 . V_9 <= 8 ) {
V_2 -> V_18 = F_7 ;
V_2 -> V_19 = F_17 ;
} else if ( V_2 -> V_8 . V_9 >= 24 ) {
V_2 -> V_18 = F_13 ;
V_2 -> V_19 = F_20 ;
} else {
if ( F_64 ( V_2 -> V_59 ) == V_125 )
V_2 -> V_18 = F_8 ;
else
V_2 -> V_18 = F_12 ;
V_2 -> V_19 = F_18 ;
}
if ( F_64 ( V_2 -> V_59 ) == V_125 )
V_6 = F_50 ( V_2 , V_94 ) ;
else
V_6 = F_51 ( V_2 , V_94 ) ;
if ( V_6 )
goto V_122;
V_6 = F_65 ( & V_12 -> V_13 , & V_2 -> V_8 , V_2 ) ;
if ( V_6 )
goto V_122;
V_6 = F_43 ( V_2 , V_85 ) ;
if ( V_6 )
goto V_122;
if ( V_104 && V_104 -> V_126 ) {
V_6 = V_104 -> V_126 ( V_12 , V_2 -> V_8 . V_42 ,
V_2 -> V_8 . V_9 , V_104 -> V_127 ) ;
if ( V_6 < 0 )
F_49 ( & V_12 -> V_13 , L_11 , V_6 ) ;
}
F_66 ( V_12 , V_2 ) ;
return 0 ;
V_122:
F_67 ( V_2 -> V_105 ) ;
return V_6 ;
}
static int F_68 ( struct V_86 * V_12 )
{
struct V_103 * V_104 = F_54 ( & V_12 -> V_13 ) ;
struct V_1 * V_2 = F_69 ( V_12 ) ;
int V_6 ;
if ( V_104 && V_104 -> V_128 ) {
V_6 = V_104 -> V_128 ( V_12 , V_2 -> V_8 . V_42 ,
V_2 -> V_8 . V_9 , V_104 -> V_127 ) ;
if ( V_6 < 0 )
F_4 ( & V_12 -> V_13 , L_12 ,
L_13 , V_6 ) ;
} else {
V_6 = 0 ;
}
F_67 ( V_2 -> V_105 ) ;
return V_6 ;
}
static int T_5 F_70 ( void )
{
return F_71 ( & V_129 ) ;
}
static void T_6 F_72 ( void )
{
F_73 ( & V_129 ) ;
}
