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
static int F_30 ( struct V_8 * V_20 , unsigned V_5 )
{
struct V_1 * V_2 = F_24 ( V_20 ) ;
T_1 V_21 ;
int V_6 ;
F_25 ( & V_2 -> V_22 ) ;
V_6 = F_1 ( V_2 , V_2 -> V_24 -> V_25 , & V_21 , V_5 ) ;
F_26 ( & V_2 -> V_22 ) ;
if ( V_6 < 0 )
return V_6 ;
return ! ! ( V_21 & ( 1u << ( V_5 % V_10 ) ) ) ;
}
static void F_31 ( struct V_8 * V_20 ,
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
static void F_32 ( struct V_1 * V_2 , int V_35 )
{
struct V_8 * V_20 ;
V_20 = & V_2 -> V_8 ;
V_20 -> V_36 = F_23 ;
V_20 -> V_37 = F_27 ;
V_20 -> V_38 = F_28 ;
V_20 -> V_39 = F_29 ;
V_20 -> V_40 = F_30 ;
V_20 -> V_41 = F_31 ;
V_20 -> V_42 = true ;
V_20 -> V_43 = V_2 -> V_44 ;
V_20 -> V_9 = V_35 ;
V_20 -> V_45 = V_2 -> V_12 -> V_46 ;
V_20 -> V_47 = & V_2 -> V_12 -> V_13 ;
V_20 -> V_48 = V_49 ;
V_20 -> V_50 = V_2 -> V_50 ;
}
static void F_33 ( struct V_51 * V_52 )
{
struct V_8 * V_20 = F_34 ( V_52 ) ;
struct V_1 * V_2 = F_24 ( V_20 ) ;
V_2 -> V_53 [ V_52 -> V_54 / V_10 ] &= ~ ( 1 << ( V_52 -> V_54 % V_10 ) ) ;
}
static void F_35 ( struct V_51 * V_52 )
{
struct V_8 * V_20 = F_34 ( V_52 ) ;
struct V_1 * V_2 = F_24 ( V_20 ) ;
V_2 -> V_53 [ V_52 -> V_54 / V_10 ] |= 1 << ( V_52 -> V_54 % V_10 ) ;
}
static void F_36 ( struct V_51 * V_52 )
{
struct V_8 * V_20 = F_34 ( V_52 ) ;
struct V_1 * V_2 = F_24 ( V_20 ) ;
F_25 ( & V_2 -> V_55 ) ;
}
static void F_37 ( struct V_51 * V_52 )
{
struct V_8 * V_20 = F_34 ( V_52 ) ;
struct V_1 * V_2 = F_24 ( V_20 ) ;
T_2 V_56 ;
int V_57 , V_58 ;
T_2 V_59 [ V_34 ] ;
if ( V_2 -> V_60 & V_61 ) {
F_16 ( V_2 , V_62 , V_2 -> V_53 ) ;
for ( V_58 = 0 ; V_58 < F_15 ( V_2 ) ; V_58 ++ )
V_59 [ V_58 ] = ~ V_2 -> V_53 [ V_58 ] ;
F_16 ( V_2 , V_63 , V_59 ) ;
}
for ( V_58 = 0 ; V_58 < F_15 ( V_2 ) ; V_58 ++ ) {
V_56 = V_2 -> V_64 [ V_58 ] | V_2 -> V_65 [ V_58 ] ;
V_56 &= ~ V_2 -> V_23 [ V_58 ] ;
while ( V_56 ) {
V_57 = F_38 ( V_56 ) ;
F_23 ( & V_2 -> V_8 ,
V_57 + ( V_10 * V_58 ) ) ;
V_56 &= ~ ( 1 << V_57 ) ;
}
}
F_26 ( & V_2 -> V_55 ) ;
}
static int F_39 ( struct V_51 * V_52 , unsigned int type )
{
struct V_8 * V_20 = F_34 ( V_52 ) ;
struct V_1 * V_2 = F_24 ( V_20 ) ;
int V_66 = V_52 -> V_54 / V_10 ;
T_2 V_29 = 1 << ( V_52 -> V_54 % V_10 ) ;
if ( ! ( type & V_67 ) ) {
F_4 ( & V_2 -> V_12 -> V_13 , L_3 ,
V_52 -> V_68 , type ) ;
return - V_69 ;
}
if ( type & V_70 )
V_2 -> V_64 [ V_66 ] |= V_29 ;
else
V_2 -> V_64 [ V_66 ] &= ~ V_29 ;
if ( type & V_71 )
V_2 -> V_65 [ V_66 ] |= V_29 ;
else
V_2 -> V_65 [ V_66 ] &= ~ V_29 ;
return 0 ;
}
static bool F_40 ( struct V_1 * V_2 , T_2 * V_72 )
{
T_2 V_73 [ V_34 ] ;
T_2 V_74 [ V_34 ] ;
bool V_75 = false ;
bool V_76 = false ;
T_2 V_77 [ V_34 ] ;
int V_6 , V_58 ;
if ( V_2 -> V_60 & V_61 ) {
V_6 = F_22 ( V_2 , V_78 , V_77 ) ;
if ( V_6 )
return false ;
V_6 = F_22 ( V_2 , V_79 , V_73 ) ;
if ( V_6 )
return false ;
for ( V_58 = 0 ; V_58 < F_15 ( V_2 ) ; V_58 ++ ) {
V_72 [ V_58 ] = ( ~ V_73 [ V_58 ] & V_2 -> V_64 [ V_58 ] ) |
( V_73 [ V_58 ] & V_2 -> V_65 [ V_58 ] ) ;
V_72 [ V_58 ] &= V_77 [ V_58 ] ;
if ( V_72 [ V_58 ] )
V_75 = true ;
}
return V_75 ;
}
V_6 = F_22 ( V_2 , V_2 -> V_24 -> V_28 , V_73 ) ;
if ( V_6 )
return false ;
for ( V_58 = 0 ; V_58 < F_15 ( V_2 ) ; V_58 ++ )
V_73 [ V_58 ] &= V_2 -> V_23 [ V_58 ] ;
memcpy ( V_74 , V_2 -> V_80 , F_15 ( V_2 ) ) ;
for ( V_58 = 0 ; V_58 < F_15 ( V_2 ) ; V_58 ++ ) {
V_77 [ V_58 ] = ( V_73 [ V_58 ] ^ V_74 [ V_58 ] ) & V_2 -> V_53 [ V_58 ] ;
if ( V_77 [ V_58 ] )
V_76 = true ;
}
if ( ! V_76 )
return false ;
memcpy ( V_2 -> V_80 , V_73 , F_15 ( V_2 ) ) ;
for ( V_58 = 0 ; V_58 < F_15 ( V_2 ) ; V_58 ++ ) {
V_72 [ V_58 ] = ( V_74 [ V_58 ] & V_2 -> V_64 [ V_58 ] ) |
( V_73 [ V_58 ] & V_2 -> V_65 [ V_58 ] ) ;
V_72 [ V_58 ] &= V_77 [ V_58 ] ;
if ( V_72 [ V_58 ] )
V_75 = true ;
}
return V_75 ;
}
static T_4 F_41 ( int V_68 , void * V_81 )
{
struct V_1 * V_2 = V_81 ;
T_2 V_72 [ V_34 ] ;
T_2 V_57 ;
unsigned V_82 = 0 ;
int V_58 ;
if ( ! F_40 ( V_2 , V_72 ) )
return V_83 ;
for ( V_58 = 0 ; V_58 < F_15 ( V_2 ) ; V_58 ++ ) {
while ( V_72 [ V_58 ] ) {
V_57 = F_38 ( V_72 [ V_58 ] ) ;
F_42 ( F_43 ( V_2 -> V_8 . V_84 ,
V_57 + ( V_10 * V_58 ) ) ) ;
V_72 [ V_58 ] &= ~ ( 1 << V_57 ) ;
V_82 ++ ;
}
}
return ( V_82 > 0 ) ? V_85 : V_83 ;
}
static int F_44 ( struct V_1 * V_2 ,
int V_86 )
{
struct V_87 * V_12 = V_2 -> V_12 ;
int V_6 , V_58 ;
if ( V_12 -> V_68 && V_86 != - 1
&& ( V_2 -> V_60 & V_88 ) ) {
V_6 = F_22 ( V_2 ,
V_2 -> V_24 -> V_28 , V_2 -> V_80 ) ;
if ( V_6 )
return V_6 ;
for ( V_58 = 0 ; V_58 < F_15 ( V_2 ) ; V_58 ++ )
V_2 -> V_80 [ V_58 ] &= V_2 -> V_23 [ V_58 ] ;
F_45 ( & V_2 -> V_55 ) ;
V_6 = F_46 ( & V_12 -> V_13 ,
V_12 -> V_68 ,
NULL ,
F_41 ,
V_89 | V_90 |
V_91 ,
F_47 ( & V_12 -> V_13 ) , V_2 ) ;
if ( V_6 ) {
F_4 ( & V_12 -> V_13 , L_4 ,
V_12 -> V_68 ) ;
return V_6 ;
}
V_6 = F_48 ( & V_2 -> V_8 ,
& V_92 ,
V_86 ,
V_93 ,
V_94 ) ;
if ( V_6 ) {
F_4 ( & V_12 -> V_13 ,
L_5 ) ;
return V_6 ;
}
F_49 ( & V_2 -> V_8 ,
& V_92 ,
V_12 -> V_68 ) ;
}
return 0 ;
}
static int F_44 ( struct V_1 * V_2 ,
int V_86 )
{
struct V_87 * V_12 = V_2 -> V_12 ;
if ( V_86 != - 1 && ( V_2 -> V_60 & V_88 ) )
F_50 ( & V_12 -> V_13 , L_6 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 , T_1 V_95 )
{
int V_6 ;
T_2 V_4 [ V_34 ] ;
V_2 -> V_24 = & V_96 ;
V_6 = F_22 ( V_2 , V_2 -> V_24 -> V_27 , V_2 -> V_26 ) ;
if ( V_6 )
goto V_97;
V_6 = F_22 ( V_2 , V_2 -> V_24 -> V_25 ,
V_2 -> V_23 ) ;
if ( V_6 )
goto V_97;
if ( V_95 )
memset ( V_4 , 0xFF , F_15 ( V_2 ) ) ;
else
memset ( V_4 , 0 , F_15 ( V_2 ) ) ;
V_6 = F_16 ( V_2 , V_98 , V_4 ) ;
V_97:
return V_6 ;
}
static int F_52 ( struct V_1 * V_2 , T_1 V_95 )
{
int V_6 ;
T_2 V_4 [ V_34 ] ;
V_2 -> V_24 = & V_99 ;
V_6 = F_22 ( V_2 , V_2 -> V_24 -> V_27 , V_2 -> V_26 ) ;
if ( V_6 )
goto V_97;
V_6 = F_22 ( V_2 , V_2 -> V_24 -> V_25 ,
V_2 -> V_23 ) ;
if ( V_6 )
goto V_97;
if ( V_95 )
memset ( V_4 , 0xFF , F_15 ( V_2 ) ) ;
else
memset ( V_4 , 0 , F_15 ( V_2 ) ) ;
V_6 = F_16 ( V_2 , V_100 , V_4 ) ;
if ( V_6 )
goto V_97;
memset ( V_4 , 0x02 , F_15 ( V_2 ) ) ;
V_6 = F_16 ( V_2 , V_101 , V_4 ) ;
if ( V_6 )
goto V_97;
return 0 ;
V_97:
return V_6 ;
}
static int F_53 ( struct V_87 * V_12 ,
const struct V_102 * V_103 )
{
struct V_104 * V_105 ;
struct V_1 * V_2 ;
int V_86 = 0 ;
int V_6 ;
T_1 V_95 = 0 ;
struct V_106 * V_3 ;
V_2 = F_54 ( & V_12 -> V_13 ,
sizeof( struct V_1 ) , V_107 ) ;
if ( V_2 == NULL )
return - V_108 ;
V_105 = F_55 ( & V_12 -> V_13 ) ;
if ( V_105 ) {
V_86 = V_105 -> V_86 ;
V_2 -> V_44 = V_105 -> V_109 ;
V_95 = V_105 -> V_95 ;
V_2 -> V_50 = V_105 -> V_50 ;
} else {
struct V_110 * V_111 ;
V_2 -> V_44 = - 1 ;
V_86 = 0 ;
V_111 = F_56 ( & V_12 -> V_13 , L_7 ,
V_112 ) ;
if ( F_57 ( V_111 ) )
return F_58 ( V_111 ) ;
}
V_2 -> V_12 = V_12 ;
V_3 = F_59 ( & V_12 -> V_13 , L_8 ) ;
if ( F_57 ( V_3 ) ) {
V_6 = F_58 ( V_3 ) ;
if ( V_6 != - V_113 )
F_4 ( & V_12 -> V_13 , L_9 , V_6 ) ;
return V_6 ;
}
V_6 = F_60 ( V_3 ) ;
if ( V_6 ) {
F_4 ( & V_12 -> V_13 , L_10 , V_6 ) ;
return V_6 ;
}
V_2 -> V_106 = V_3 ;
if ( V_103 ) {
V_2 -> V_60 = V_103 -> V_60 ;
} else {
const struct V_114 * V_115 ;
const struct V_116 * V_117 ;
V_117 = F_61 ( V_118 , & V_12 -> V_13 ) ;
if ( V_117 ) {
V_2 -> V_60 = ( int ) ( V_119 ) V_117 -> V_120 ;
} else {
V_115 = F_62 ( V_121 , & V_12 -> V_13 ) ;
if ( ! V_115 ) {
V_6 = - V_122 ;
goto V_123;
}
V_2 -> V_60 = V_115 -> V_60 ;
}
}
F_45 ( & V_2 -> V_22 ) ;
F_63 ( & V_2 -> V_22 ,
F_64 ( V_12 -> V_124 ) ) ;
F_32 ( V_2 , V_2 -> V_60 & V_125 ) ;
if ( V_2 -> V_8 . V_9 <= 8 ) {
V_2 -> V_18 = F_7 ;
V_2 -> V_19 = F_17 ;
} else if ( V_2 -> V_8 . V_9 >= 24 ) {
V_2 -> V_18 = F_13 ;
V_2 -> V_19 = F_20 ;
} else {
if ( F_65 ( V_2 -> V_60 ) == V_126 )
V_2 -> V_18 = F_8 ;
else
V_2 -> V_18 = F_12 ;
V_2 -> V_19 = F_18 ;
}
if ( F_65 ( V_2 -> V_60 ) == V_126 )
V_6 = F_51 ( V_2 , V_95 ) ;
else
V_6 = F_52 ( V_2 , V_95 ) ;
if ( V_6 )
goto V_123;
V_6 = F_66 ( & V_12 -> V_13 , & V_2 -> V_8 , V_2 ) ;
if ( V_6 )
goto V_123;
V_6 = F_44 ( V_2 , V_86 ) ;
if ( V_6 )
goto V_123;
if ( V_105 && V_105 -> V_127 ) {
V_6 = V_105 -> V_127 ( V_12 , V_2 -> V_8 . V_43 ,
V_2 -> V_8 . V_9 , V_105 -> V_128 ) ;
if ( V_6 < 0 )
F_50 ( & V_12 -> V_13 , L_11 , V_6 ) ;
}
F_67 ( V_12 , V_2 ) ;
return 0 ;
V_123:
F_68 ( V_2 -> V_106 ) ;
return V_6 ;
}
static int F_69 ( struct V_87 * V_12 )
{
struct V_104 * V_105 = F_55 ( & V_12 -> V_13 ) ;
struct V_1 * V_2 = F_70 ( V_12 ) ;
int V_6 ;
if ( V_105 && V_105 -> V_129 ) {
V_6 = V_105 -> V_129 ( V_12 , V_2 -> V_8 . V_43 ,
V_2 -> V_8 . V_9 , V_105 -> V_128 ) ;
if ( V_6 < 0 )
F_4 ( & V_12 -> V_13 , L_12 ,
L_13 , V_6 ) ;
} else {
V_6 = 0 ;
}
F_68 ( V_2 -> V_106 ) ;
return V_6 ;
}
static int T_5 F_71 ( void )
{
return F_72 ( & V_130 ) ;
}
static void T_6 F_73 ( void )
{
F_74 ( & V_130 ) ;
}
