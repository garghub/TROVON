static inline int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 + V_4 ) &
F_3 ( 1 << V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
T_1 V_6 ,
T_1 V_7 ,
T_2 V_8 ,
T_3 V_9 ,
T_4 V_10 ,
T_4 V_11 )
{
void T_5 * V_12 = V_2 -> V_13 . V_14 ;
T_4 * V_15 = V_2 -> V_13 . V_16 ;
F_5 ( ( V_17 T_2 ) F_6 ( V_6 >> 32 ) , V_12 + V_15 [ 0 ] ) ;
F_7 () ;
F_5 ( ( V_17 T_2 ) F_6 ( V_6 & 0xfffffffful ) , V_12 + V_15 [ 1 ] ) ;
F_7 () ;
F_5 ( ( V_17 T_2 ) F_6 ( V_8 ) , V_12 + V_15 [ 2 ] ) ;
F_7 () ;
F_5 ( ( V_17 T_2 ) F_6 ( V_7 >> 32 ) , V_12 + V_15 [ 3 ] ) ;
F_7 () ;
F_5 ( ( V_17 T_2 ) F_6 ( V_7 & 0xfffffffful ) , V_12 + V_15 [ 4 ] ) ;
F_7 () ;
F_5 ( ( V_17 T_2 ) F_6 ( V_11 << 16 ) , V_12 + V_15 [ 5 ] ) ;
F_7 () ;
F_5 ( ( V_17 T_2 ) F_6 ( ( 1 << V_5 ) |
( 1 << V_18 ) |
( V_9 << V_19 ) |
V_10 ) , V_12 + V_15 [ 6 ] ) ;
F_7 () ;
F_5 ( ( V_17 T_2 ) 0 , V_12 + V_15 [ 7 ] ) ;
F_7 () ;
}
static int F_8 ( struct V_1 * V_2 ,
T_1 V_6 ,
T_1 V_7 ,
T_2 V_8 ,
T_3 V_9 ,
T_4 V_10 ,
T_4 V_11 ,
int V_20 )
{
if ( V_20 ) {
unsigned long V_21 = V_22 + V_23 ;
while ( F_1 ( V_2 ) && F_9 ( V_22 , V_21 ) ) {
F_10 ( V_24 ) ;
F_11 () ;
}
}
if ( F_1 ( V_2 ) )
return - V_25 ;
F_5 ( ( V_17 T_2 ) F_6 ( V_6 >> 32 ) , V_2 -> V_3 + 0 * 4 ) ;
F_5 ( ( V_17 T_2 ) F_6 ( V_6 & 0xfffffffful ) , V_2 -> V_3 + 1 * 4 ) ;
F_5 ( ( V_17 T_2 ) F_6 ( V_8 ) , V_2 -> V_3 + 2 * 4 ) ;
F_5 ( ( V_17 T_2 ) F_6 ( V_7 >> 32 ) , V_2 -> V_3 + 3 * 4 ) ;
F_5 ( ( V_17 T_2 ) F_6 ( V_7 & 0xfffffffful ) , V_2 -> V_3 + 4 * 4 ) ;
F_5 ( ( V_17 T_2 ) F_6 ( V_11 << 16 ) , V_2 -> V_3 + 5 * 4 ) ;
F_7 () ;
F_5 ( ( V_17 T_2 ) F_6 ( ( 1 << V_5 ) |
( V_20 ? ( 1 << V_18 ) : 0 ) |
( V_9 << V_19 ) |
V_10 ) , V_2 -> V_3 + 6 * 4 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
T_1 V_6 ,
T_1 V_7 ,
T_2 V_8 ,
T_3 V_9 ,
T_4 V_10 ,
T_4 V_11 ,
int V_20 )
{
int V_26 = 0 ;
F_13 ( & V_2 -> V_13 . V_27 ) ;
if ( V_20 && V_2 -> V_13 . V_28 & V_29 && V_30 )
F_4 ( V_2 , V_6 , V_7 , V_8 ,
V_9 , V_10 , V_11 ) ;
else
V_26 = F_8 ( V_2 , V_6 , V_7 , V_8 ,
V_9 , V_10 , V_11 , V_20 ) ;
F_14 () ;
F_15 ( & V_2 -> V_13 . V_27 ) ;
return V_26 ;
}
static int F_16 ( T_3 V_31 )
{
static const int V_32 [] = {
[ V_33 ] = - V_34 ,
[ V_35 ] = - V_36 ,
[ V_37 ] = - V_38 ,
[ V_39 ] = - V_40 ,
[ V_41 ] = - V_42 ,
[ V_43 ] = - V_44 ,
[ V_45 ] = - V_46 ,
[ V_47 ] = - V_46 ,
[ V_48 ] = - V_42 ,
[ V_49 ] = - V_42 ,
[ V_50 ] = - V_51 ,
[ V_52 ] = - V_38 ,
[ V_53 ] = - V_51 ,
[ V_54 ] = - V_44 ,
[ V_55 ] = - V_25 ,
[ V_56 ] = - V_57 ,
[ V_58 ] = - V_46 ,
} ;
if ( V_31 >= F_17 ( V_32 ) ||
( V_31 != V_59
&& V_32 [ V_31 ] == 0 ) )
return - V_38 ;
return V_32 [ V_31 ] ;
}
static int F_18 ( struct V_1 * V_2 ,
T_1 V_6 ,
T_1 * V_7 ,
int V_60 ,
T_2 V_8 ,
T_3 V_9 ,
T_4 V_10 ,
unsigned long V_61 )
{
int V_26 = 0 ;
unsigned long V_21 ;
T_3 V_31 ;
F_19 ( & V_2 -> V_13 . V_62 ) ;
V_26 = F_12 ( V_2 , V_6 ,
V_7 ? * V_7 : 0 ,
V_8 , V_9 ,
V_10 , V_63 , 0 ) ;
if ( V_26 )
goto V_64;
V_21 = V_61 + V_22 ;
while ( F_1 ( V_2 ) && F_9 ( V_22 , V_21 ) ) {
F_10 ( V_24 ) ;
F_11 () ;
}
if ( F_1 ( V_2 ) ) {
V_26 = - V_44 ;
goto V_64;
}
if ( V_60 && V_7 ) {
* V_7 =
( T_1 ) F_20 ( ( V_17 V_65 )
F_21 ( V_2 -> V_3 + V_66 ) ) << 32 |
( T_1 ) F_20 ( ( V_17 V_65 )
F_21 ( V_2 -> V_3 + V_66 + 4 ) ) ;
} else if ( V_60 ) {
V_26 = - V_38 ;
goto V_64;
}
V_31 = F_20 ( ( V_17 V_65 ) F_21 ( V_2 -> V_3 + V_4 ) ) >> 24 ;
if ( V_31 ) {
F_22 ( V_2 , L_1 ,
V_10 , V_31 ) ;
V_26 = F_16 ( V_31 ) ;
}
V_64:
F_23 ( & V_2 -> V_13 . V_62 ) ;
return V_26 ;
}
void F_24 ( struct V_1 * V_2 ,
T_4 V_11 ,
T_3 V_31 ,
T_1 V_7 )
{
struct V_67 * V_68 =
& V_2 -> V_13 . V_68 [ V_11 & V_2 -> V_13 . V_69 ] ;
if ( V_11 != V_68 -> V_11 )
return;
V_68 -> V_70 = 0 ;
V_68 -> V_31 = V_31 ;
V_68 -> V_7 = V_7 ;
F_25 ( & V_68 -> V_71 ) ;
}
static int F_26 ( struct V_1 * V_2 ,
T_1 V_6 ,
T_1 * V_7 ,
int V_60 ,
T_2 V_8 ,
T_3 V_9 ,
T_4 V_10 ,
unsigned long V_61 )
{
int V_26 = 0 ;
struct V_67 * V_68 ;
F_19 ( & V_2 -> V_13 . V_72 ) ;
F_27 ( & V_2 -> V_13 . V_73 ) ;
F_28 ( V_2 -> V_13 . V_74 < 0 ) ;
V_68 = & V_2 -> V_13 . V_68 [ V_2 -> V_13 . V_74 ] ;
V_68 -> V_11 += V_2 -> V_13 . V_69 + 1 ;
V_2 -> V_13 . V_74 = V_68 -> V_75 ;
F_29 ( & V_2 -> V_13 . V_73 ) ;
F_30 ( & V_68 -> V_71 ) ;
V_26 = F_12 ( V_2 , V_6 ,
V_7 ? * V_7 : 0 ,
V_8 , V_9 ,
V_10 , V_68 -> V_11 , 1 ) ;
if ( V_26 )
goto V_64;
if ( ! F_31 ( & V_68 -> V_71 , V_61 ) ) {
V_26 = - V_44 ;
goto V_64;
}
V_26 = V_68 -> V_70 ;
if ( V_26 )
goto V_64;
if ( V_68 -> V_31 ) {
F_22 ( V_2 , L_1 ,
V_10 , V_68 -> V_31 ) ;
V_26 = F_16 ( V_68 -> V_31 ) ;
}
if ( V_60 && V_7 ) {
* V_7 = V_68 -> V_7 ;
} else if ( V_60 ) {
V_26 = - V_38 ;
goto V_64;
}
V_64:
F_27 ( & V_2 -> V_13 . V_73 ) ;
V_68 -> V_75 = V_2 -> V_13 . V_74 ;
V_2 -> V_13 . V_74 = V_68 - V_2 -> V_13 . V_68 ;
F_29 ( & V_2 -> V_13 . V_73 ) ;
F_23 ( & V_2 -> V_13 . V_72 ) ;
return V_26 ;
}
static int F_32 ( struct V_1 * V_2 ,
T_1 V_6 ,
T_1 V_7 ,
T_2 V_8 ,
T_3 V_9 ,
T_4 V_10 ,
unsigned long V_61 )
{
if ( V_2 -> V_13 . V_28 & V_76 )
return F_26 ( V_2 , V_6 , & V_7 , 0 ,
V_8 , V_9 , V_10 ,
V_61 ) ;
else
return F_18 ( V_2 , V_6 , & V_7 , 0 ,
V_8 , V_9 , V_10 ,
V_61 ) ;
}
static int F_33 ( struct V_1 * V_2 ,
T_1 V_6 ,
T_2 V_8 ,
T_3 V_9 ,
T_4 V_10 ,
unsigned long V_61 )
{
return F_32 ( V_2 , V_6 , 0 , V_8 ,
V_9 , V_10 , V_61 ) ;
}
static int F_34 ( struct V_1 * V_2 ,
T_1 V_6 ,
T_1 * V_7 ,
T_2 V_8 ,
T_3 V_9 ,
T_4 V_10 ,
unsigned long V_61 )
{
if ( V_2 -> V_13 . V_28 & V_76 )
return F_26 ( V_2 , V_6 , V_7 , 1 ,
V_8 , V_9 , V_10 ,
V_61 ) ;
else
return F_18 ( V_2 , V_6 , V_7 , 1 ,
V_8 , V_9 , V_10 ,
V_61 ) ;
}
int F_35 ( struct V_1 * V_2 )
{
F_36 ( & V_2 -> V_13 . V_27 ) ;
F_37 ( & V_2 -> V_13 . V_62 , 1 ) ;
V_2 -> V_13 . V_28 = 0 ;
V_2 -> V_3 = F_38 ( F_39 ( V_2 -> V_77 , 0 ) + V_78 ,
V_79 ) ;
if ( ! V_2 -> V_3 ) {
F_40 ( V_2 , L_2 ) ;
return - V_46 ;
}
V_2 -> V_13 . V_80 = F_41 ( L_3 , V_2 -> V_77 ,
V_81 ,
V_81 , 0 ) ;
if ( ! V_2 -> V_13 . V_80 ) {
F_42 ( V_2 -> V_3 ) ;
return - V_46 ;
}
return 0 ;
}
void F_43 ( struct V_1 * V_2 )
{
F_44 ( V_2 -> V_13 . V_80 ) ;
F_42 ( V_2 -> V_3 ) ;
if ( V_2 -> V_13 . V_28 & V_29 )
F_42 ( V_2 -> V_13 . V_14 ) ;
}
int F_45 ( struct V_1 * V_2 )
{
int V_82 ;
V_2 -> V_13 . V_68 = F_46 ( V_2 -> V_13 . V_83 *
sizeof ( struct V_67 ) ,
V_84 ) ;
if ( ! V_2 -> V_13 . V_68 )
return - V_46 ;
for ( V_82 = 0 ; V_82 < V_2 -> V_13 . V_83 ; ++ V_82 ) {
V_2 -> V_13 . V_68 [ V_82 ] . V_11 = V_82 ;
V_2 -> V_13 . V_68 [ V_82 ] . V_75 = V_82 + 1 ;
}
V_2 -> V_13 . V_68 [ V_2 -> V_13 . V_83 - 1 ] . V_75 = - 1 ;
V_2 -> V_13 . V_74 = 0 ;
F_37 ( & V_2 -> V_13 . V_72 , V_2 -> V_13 . V_83 ) ;
F_47 ( & V_2 -> V_13 . V_73 ) ;
for ( V_2 -> V_13 . V_69 = 1 ;
V_2 -> V_13 . V_69 < V_2 -> V_13 . V_83 ;
V_2 -> V_13 . V_69 <<= 1 )
;
-- V_2 -> V_13 . V_69 ;
V_2 -> V_13 . V_28 |= V_76 ;
F_19 ( & V_2 -> V_13 . V_62 ) ;
return 0 ;
}
void F_48 ( struct V_1 * V_2 )
{
int V_82 ;
V_2 -> V_13 . V_28 &= ~ V_76 ;
for ( V_82 = 0 ; V_82 < V_2 -> V_13 . V_83 ; ++ V_82 )
F_19 ( & V_2 -> V_13 . V_72 ) ;
F_49 ( V_2 -> V_13 . V_68 ) ;
F_23 ( & V_2 -> V_13 . V_62 ) ;
}
struct V_85 * F_50 ( struct V_1 * V_2 ,
T_6 V_86 )
{
struct V_85 * V_87 ;
V_87 = F_46 ( sizeof *V_87 , V_86 ) ;
if ( ! V_87 )
return F_51 ( - V_46 ) ;
V_87 -> V_88 = F_52 ( V_2 -> V_13 . V_80 , V_86 , & V_87 -> V_89 ) ;
if ( ! V_87 -> V_88 ) {
F_49 ( V_87 ) ;
return F_51 ( - V_46 ) ;
}
return V_87 ;
}
void F_53 ( struct V_1 * V_2 , struct V_85 * V_87 )
{
if ( ! V_87 )
return;
F_54 ( V_2 -> V_13 . V_80 , V_87 -> V_88 , V_87 -> V_89 ) ;
F_49 ( V_87 ) ;
}
int F_55 ( struct V_1 * V_2 )
{
T_1 V_64 ;
int V_90 ;
V_90 = F_34 ( V_2 , 0 , & V_64 , 0 , 0 , V_91 , V_92 ) ;
if ( V_90 == - V_46 )
F_56 ( V_2 , L_4
L_5 ,
( int ) ( V_64 >> 6 ) & 0xf , ( int ) ( V_64 >> 4 ) & 3 ,
( int ) ( V_64 >> 1 ) & 7 , ( int ) V_64 & 1 ? L_6 : L_7 ) ;
return V_90 ;
}
int F_57 ( struct V_1 * V_2 )
{
return F_33 ( V_2 , 0 , 0 , 0 , V_93 , V_94 ) ;
}
static int F_58 ( struct V_1 * V_2 , T_4 V_10 , struct V_95 * V_96 ,
T_1 V_97 )
{
struct V_85 * V_87 ;
struct V_98 V_99 ;
T_7 * V_100 ;
int V_101 ;
int V_102 = 0 ;
int V_82 ;
int V_26 = 0 ;
int V_103 = 0 , V_104 = 0 ;
V_87 = F_50 ( V_2 , V_84 ) ;
if ( F_59 ( V_87 ) )
return F_60 ( V_87 ) ;
memset ( V_87 -> V_88 , 0 , V_81 ) ;
V_100 = V_87 -> V_88 ;
for ( F_61 ( V_96 , & V_99 ) ;
! F_62 ( & V_99 ) ;
F_63 ( & V_99 ) ) {
V_101 = F_64 ( F_65 ( & V_99 ) | F_66 ( & V_99 ) ) - 1 ;
if ( V_101 < V_105 ) {
F_56 ( V_2 , L_8 ,
V_106 ,
( unsigned long long ) F_65 ( & V_99 ) ,
F_66 ( & V_99 ) ) ;
V_26 = - V_38 ;
goto V_64;
}
for ( V_82 = 0 ; V_82 < F_66 ( & V_99 ) > > V_101 ; ++ V_82 ) {
if ( V_97 != - 1 ) {
V_100 [ V_102 * 2 ] = F_67 ( V_97 ) ;
V_97 += 1 << V_101 ;
}
V_100 [ V_102 * 2 + 1 ] =
F_67 ( ( F_65 ( & V_99 ) + ( V_82 << V_101 ) ) |
( V_101 - V_105 ) ) ;
V_103 += 1 << ( V_101 - 10 ) ;
++ V_104 ;
if ( ++ V_102 == V_81 / 16 ) {
V_26 = F_33 ( V_2 , V_87 -> V_89 , V_102 , 0 , V_10 ,
V_107 ) ;
if ( V_26 )
goto V_64;
V_102 = 0 ;
}
}
}
if ( V_102 )
V_26 = F_33 ( V_2 , V_87 -> V_89 , V_102 , 0 , V_10 ,
V_107 ) ;
switch ( V_10 ) {
case V_108 :
F_22 ( V_2 , L_9 , V_104 , V_103 ) ;
break;
case V_109 :
F_22 ( V_2 , L_10 , V_104 , V_103 ) ;
break;
case V_110 :
F_22 ( V_2 , L_11 ,
V_104 , V_103 , ( unsigned long long ) V_97 - ( V_103 << 10 ) ) ;
break;
}
V_64:
F_53 ( V_2 , V_87 ) ;
return V_26 ;
}
int F_68 ( struct V_1 * V_2 , struct V_95 * V_96 )
{
return F_58 ( V_2 , V_108 , V_96 , - 1 ) ;
}
int F_69 ( struct V_1 * V_2 )
{
return F_33 ( V_2 , 0 , 0 , 0 , V_111 , V_107 ) ;
}
int F_70 ( struct V_1 * V_2 )
{
return F_33 ( V_2 , 0 , 0 , 0 , V_112 , V_113 ) ;
}
static void F_71 ( struct V_1 * V_2 , T_1 V_114 )
{
T_8 V_115 ;
T_4 V_116 = 0 ;
int V_82 ;
for ( V_82 = 0 ; V_82 < 8 ; ++ V_82 )
V_116 = F_72 ( V_116 , V_2 -> V_13 . V_16 [ V_82 ] ) ;
if ( ( V_114 & V_117 ) != ( ( V_114 + V_116 ) & V_117 ) ) {
F_56 ( V_2 , L_12
L_13 ,
( unsigned long long ) V_114 , V_116 ) ;
return;
}
V_115 = F_39 ( V_2 -> V_77 , 2 ) +
( ( F_73 ( V_2 -> V_77 , 2 ) - 1 ) & V_114 ) ;
V_2 -> V_13 . V_14 = F_38 ( V_115 , V_116 + sizeof( T_2 ) ) ;
if ( ! V_2 -> V_13 . V_14 )
return;
V_2 -> V_13 . V_28 |= V_29 ;
F_22 ( V_2 , L_14 ) ;
}
int F_74 ( struct V_1 * V_2 )
{
struct V_85 * V_87 ;
T_2 * V_118 ;
T_1 V_114 ;
T_2 V_119 ;
int V_26 = 0 ;
T_3 V_101 ;
int V_82 ;
#define F_75 0x100
#define F_76 0x00
#define F_77 0x0f
#define F_78 0x30
#define F_79 0x38
#define F_80 0x10
#define F_81 0x50
#define F_82 0x60
#define F_83 0x20
#define F_84 0x28
#define F_85 0x00
#define F_86 0x20
#define F_87 0x40
#define F_88 0x48
V_87 = F_50 ( V_2 , V_84 ) ;
if ( F_59 ( V_87 ) )
return F_60 ( V_87 ) ;
V_118 = V_87 -> V_88 ;
V_26 = F_32 ( V_2 , 0 , V_87 -> V_89 , 0 , 0 , V_120 ,
V_113 ) ;
if ( V_26 )
goto V_64;
F_89 ( V_2 -> V_121 , V_118 , F_76 ) ;
V_2 -> V_121 = ( V_2 -> V_121 & 0xffff00000000ull ) |
( ( V_2 -> V_121 & 0xffff0000ull ) >> 16 ) |
( ( V_2 -> V_121 & 0x0000ffffull ) << 16 ) ;
F_89 ( V_101 , V_118 , F_77 ) ;
V_2 -> V_13 . V_83 = 1 << V_101 ;
F_22 ( V_2 , L_15 ,
( unsigned long long ) V_2 -> V_121 , V_2 -> V_13 . V_83 ) ;
F_89 ( V_2 -> V_122 . V_115 , V_118 , F_78 ) ;
F_89 ( V_2 -> V_122 . V_123 , V_118 , F_79 ) ;
F_22 ( V_2 , L_16 ,
( unsigned long long ) V_2 -> V_122 . V_115 , V_2 -> V_122 . V_123 ) ;
F_89 ( V_119 , V_118 , F_80 ) ;
if ( V_119 & 0x1 ) {
F_22 ( V_2 , L_17 ) ;
F_89 ( V_114 , V_118 , F_82 ) ;
for ( V_82 = 0 ; V_82 < V_124 ; ++ V_82 )
F_89 ( V_2 -> V_13 . V_16 [ V_82 ] , V_118 ,
F_81 + ( V_82 << 1 ) ) ;
F_71 ( V_2 , V_114 ) ;
}
if ( F_90 ( V_2 ) ) {
F_89 ( V_2 -> V_125 . V_126 . V_127 , V_118 , F_85 ) ;
F_89 ( V_2 -> V_125 . V_126 . V_128 , V_118 , F_86 ) ;
F_89 ( V_2 -> V_125 . V_126 . V_129 , V_118 , F_87 ) ;
F_89 ( V_2 -> V_125 . V_126 . V_130 , V_118 , F_88 ) ;
F_22 ( V_2 , L_18 , V_2 -> V_125 . V_126 . V_127 << 2 ) ;
V_2 -> V_125 . V_126 . V_127 =
F_91 ( V_2 -> V_125 . V_126 . V_127 , V_131 / V_106 ) >>
( V_132 - V_105 ) ;
F_22 ( V_2 , L_19 ,
( unsigned long long ) V_2 -> V_125 . V_126 . V_128 ,
( unsigned long long ) V_2 -> V_125 . V_126 . V_129 ,
( unsigned long long ) V_2 -> V_125 . V_126 . V_130 ) ;
} else {
F_89 ( V_2 -> V_125 . V_133 . V_134 , V_118 , F_83 ) ;
F_89 ( V_2 -> V_125 . V_133 . V_135 , V_118 , F_84 ) ;
F_22 ( V_2 , L_20 ,
( int ) ( ( V_2 -> V_125 . V_133 . V_135 - V_2 -> V_125 . V_133 . V_134 ) >> 10 ) ,
( unsigned long long ) V_2 -> V_125 . V_133 . V_134 ,
( unsigned long long ) V_2 -> V_125 . V_133 . V_135 ) ;
}
V_64:
F_53 ( V_2 , V_87 ) ;
return V_26 ;
}
int F_92 ( struct V_1 * V_2 )
{
struct V_85 * V_87 ;
T_3 V_136 ;
T_2 * V_118 ;
int V_26 = 0 ;
#define F_93 0x100
#define F_94 0x00
#define F_95 0x08
#define F_96 0x13
#define F_97 (1 << 4)
#define F_98 0x3
V_87 = F_50 ( V_2 , V_84 ) ;
if ( F_59 ( V_87 ) )
return F_60 ( V_87 ) ;
V_118 = V_87 -> V_88 ;
V_26 = F_32 ( V_2 , 0 , V_87 -> V_89 , 0 , 0 , V_137 ,
V_94 ) ;
if ( V_26 )
goto V_64;
F_89 ( V_2 -> V_138 , V_118 , F_94 ) ;
F_89 ( V_2 -> V_139 , V_118 , F_95 ) ;
F_89 ( V_136 , V_118 , F_96 ) ;
if ( ! ! ( V_136 & F_97 ) !=
! ! ( V_2 -> V_140 & V_141 ) ) {
F_99 ( V_2 , L_21
L_22 ,
( V_136 & F_97 ) ?
L_23 : L_24 ) ;
}
if ( V_136 & F_97 )
F_22 ( V_2 , L_25 ) ;
F_22 ( V_2 , L_26 ,
( int ) ( ( V_2 -> V_139 - V_2 -> V_138 ) >> 10 ) ,
( unsigned long long ) V_2 -> V_138 ,
( unsigned long long ) V_2 -> V_139 ) ;
V_64:
F_53 ( V_2 , V_87 ) ;
return V_26 ;
}
int F_100 ( struct V_1 * V_2 )
{
return F_33 ( V_2 , 0 , 0 , 0 , V_93 , V_94 ) ;
}
int F_101 ( struct V_1 * V_2 )
{
struct V_85 * V_87 ;
T_3 V_136 ;
T_2 * V_118 ;
int V_26 = 0 ;
#define F_102 0x100
#define F_103 0x00
#define F_104 0x08
#define F_105 0x13
#define F_106 (1 << 4)
#define F_107 0x3
V_87 = F_50 ( V_2 , V_84 ) ;
if ( F_59 ( V_87 ) )
return F_60 ( V_87 ) ;
V_118 = V_87 -> V_88 ;
V_26 = F_32 ( V_2 , 0 , V_87 -> V_89 , 0 , 0 , V_142 ,
V_113 ) ;
if ( V_26 )
goto V_64;
F_89 ( V_2 -> V_138 , V_118 , F_103 ) ;
F_89 ( V_2 -> V_139 , V_118 , F_104 ) ;
F_89 ( V_136 , V_118 , F_105 ) ;
if ( ! ! ( V_136 & F_106 ) !=
! ! ( V_2 -> V_140 & V_141 ) ) {
F_99 ( V_2 , L_21
L_22 ,
( V_136 & F_106 ) ?
L_23 : L_24 ) ;
}
if ( V_136 & F_106 )
F_22 ( V_2 , L_25 ) ;
F_22 ( V_2 , L_26 ,
( int ) ( ( V_2 -> V_139 - V_2 -> V_138 ) >> 10 ) ,
( unsigned long long ) V_2 -> V_138 ,
( unsigned long long ) V_2 -> V_139 ) ;
V_64:
F_53 ( V_2 , V_87 ) ;
return V_26 ;
}
int F_108 ( struct V_1 * V_2 ,
struct V_143 * V_144 )
{
struct V_85 * V_87 ;
T_2 * V_118 ;
T_3 V_145 ;
T_4 V_123 ;
T_4 V_146 ;
int V_26 ;
#define F_109 0x100
#define F_110 0x10
#define F_111 0x11
#define F_112 0x12
#define F_113 0x13
#define F_114 0x14
#define F_115 0x15
#define F_116 0x16
#define F_117 0x17
#define F_118 0x19
#define F_119 0x1a
#define F_120 0x1b
#define F_121 0x1d
#define F_122 0x1e
#define F_123 0x1f
#define F_124 0x20
#define F_125 0x21
#define F_126 0x22
#define F_127 0x23
#define F_128 0x27
#define F_129 0x29
#define F_130 0x2b
#define F_131 0x2f
#define F_132 0x33
#define F_133 0x35
#define F_134 0x36
#define F_135 0x37
#define F_136 0x3b
#define F_137 0x3c
#define F_138 0x3f
#define F_139 0x44
#define F_140 0x48
#define F_141 0x49
#define F_142 0x4b
#define F_143 0x51
#define F_144 0x52
#define F_145 0x55
#define F_146 0x56
#define F_147 0x61
#define F_148 0x62
#define F_149 0x63
#define F_150 0x64
#define F_151 0x65
#define F_152 0x66
#define F_153 0x67
#define F_154 0x80
#define F_155 0x82
#define F_156 0x84
#define F_157 0x86
#define F_158 0x88
#define F_159 0x8a
#define F_160 0x8c
#define F_161 0x8e
#define F_162 0x90
#define F_163 0x92
#define F_164 0x96
#define F_165 0x97
#define F_166 0x98
#define F_167 0x9f
#define F_168 0xa0
V_87 = F_50 ( V_2 , V_84 ) ;
if ( F_59 ( V_87 ) )
return F_60 ( V_87 ) ;
V_118 = V_87 -> V_88 ;
V_26 = F_32 ( V_2 , 0 , V_87 -> V_89 , 0 , 0 , V_147 ,
V_113 ) ;
if ( V_26 )
goto V_64;
F_89 ( V_145 , V_118 , F_112 ) ;
V_144 -> V_148 = 1 << ( V_145 & 0xf ) ;
F_89 ( V_145 , V_118 , F_113 ) ;
V_144 -> V_149 = 1 << ( V_145 & 0x1f ) ;
F_89 ( V_145 , V_118 , F_114 ) ;
V_144 -> V_150 = 1 << ( V_145 >> 4 ) ;
F_89 ( V_145 , V_118 , F_115 ) ;
V_144 -> V_151 = 1 << ( V_145 & 0x1f ) ;
F_89 ( V_145 , V_118 , F_116 ) ;
V_144 -> V_152 = 1 << ( V_145 & 0xf ) ;
F_89 ( V_145 , V_118 , F_117 ) ;
V_144 -> V_153 = 1 << ( V_145 & 0x1f ) ;
F_89 ( V_145 , V_118 , F_118 ) ;
V_144 -> V_154 = 1 << V_145 ;
F_89 ( V_145 , V_118 , F_119 ) ;
V_144 -> V_155 = 1 << ( V_145 & 0xf ) ;
F_89 ( V_145 , V_118 , F_120 ) ;
V_144 -> V_156 = 1 << ( V_145 & 0x1f ) ;
F_89 ( V_145 , V_118 , F_121 ) ;
V_144 -> V_157 = 1 << ( V_145 & 0x3f ) ;
F_89 ( V_145 , V_118 , F_122 ) ;
V_144 -> V_158 = 1 << ( V_145 & 0xf ) ;
F_89 ( V_145 , V_118 , F_123 ) ;
V_144 -> V_159 = 1 << ( V_145 & 0x7 ) ;
F_89 ( V_145 , V_118 , F_124 ) ;
if ( F_90 ( V_2 ) )
V_144 -> V_160 = F_91 ( ( 1 << ( V_145 >> 4 ) ) * sizeof( T_1 ) ,
V_2 -> V_161 . V_162 ) / V_2 -> V_161 . V_162 ;
else
V_144 -> V_160 = 1 << ( V_145 >> 4 ) ;
F_89 ( V_145 , V_118 , F_125 ) ;
V_144 -> V_163 = 1 << V_145 ;
F_89 ( V_145 , V_118 , F_126 ) ;
V_144 -> V_164 = 1 << ( V_145 & 0xf ) ;
F_89 ( V_145 , V_118 , F_127 ) ;
V_144 -> V_165 = 1 << ( V_145 & 0x3f ) ;
F_89 ( V_145 , V_118 , F_129 ) ;
V_144 -> V_166 = 1 << ( V_145 & 0x3f ) ;
F_89 ( V_145 , V_118 , F_130 ) ;
V_144 -> V_167 = 1 << ( V_145 & 0x3f ) ;
F_89 ( V_145 , V_118 , F_131 ) ;
V_144 -> V_168 = 1 << ( V_145 & 0x3f ) ;
F_89 ( V_145 , V_118 , F_133 ) ;
V_144 -> V_169 = V_145 & 0x1f ;
F_89 ( V_145 , V_118 , F_134 ) ;
V_144 -> V_170 = V_145 >> 4 ;
V_144 -> V_171 = V_145 & 0xf ;
F_89 ( V_145 , V_118 , F_135 ) ;
V_144 -> V_172 = V_145 >> 4 ;
V_144 -> V_173 = V_145 & 0xf ;
F_89 ( V_145 , V_118 , F_136 ) ;
V_144 -> V_174 = 1 << ( V_145 & 0xf ) ;
F_89 ( V_146 , V_118 , F_137 ) ;
V_144 -> V_175 = V_146 ;
F_89 ( V_145 , V_118 , F_138 ) ;
V_144 -> V_176 = 1 << ( V_145 & 0xf ) ;
F_89 ( V_144 -> V_28 , V_118 , F_139 ) ;
F_89 ( V_145 , V_118 , F_140 ) ;
V_144 -> V_177 = V_145 >> 4 ;
F_89 ( V_145 , V_118 , F_141 ) ;
V_144 -> V_178 = 1 << ( ( V_145 & 0x3f ) + 20 ) ;
F_89 ( V_145 , V_118 , F_142 ) ;
V_144 -> V_179 = 1 << V_145 ;
F_89 ( V_145 , V_118 , F_143 ) ;
V_144 -> V_180 = V_145 ;
F_89 ( V_123 , V_118 , F_144 ) ;
V_144 -> V_181 = V_123 ;
F_89 ( V_145 , V_118 , F_147 ) ;
V_144 -> V_182 = 1 << V_145 ;
F_89 ( V_145 , V_118 , F_148 ) ;
V_144 -> V_183 = V_145 & 0xf ;
F_89 ( V_145 , V_118 , F_149 ) ;
V_144 -> V_184 = 1 << V_145 ;
F_89 ( V_145 , V_118 , F_150 ) ;
V_144 -> V_185 = V_145 >> 4 ;
F_89 ( V_145 , V_118 , F_151 ) ;
V_144 -> V_186 = 1 << ( V_145 & 0x3f ) ;
F_89 ( V_145 , V_118 , F_152 ) ;
V_144 -> V_187 = V_145 >> 4 ;
F_89 ( V_145 , V_118 , F_153 ) ;
V_144 -> V_188 = 1 << ( V_145 & 0x3f ) ;
F_89 ( V_123 , V_118 , F_154 ) ;
V_144 -> V_189 = V_123 ;
F_89 ( V_123 , V_118 , F_155 ) ;
V_144 -> V_190 = V_123 ;
F_89 ( V_123 , V_118 , F_156 ) ;
V_144 -> V_191 = V_123 ;
F_89 ( V_123 , V_118 , F_157 ) ;
V_144 -> V_192 = V_123 ;
F_89 ( V_123 , V_118 , F_158 ) ;
V_144 -> V_193 = V_123 ;
F_89 ( V_123 , V_118 , F_159 ) ;
V_144 -> V_194 = V_123 ;
F_89 ( V_123 , V_118 , F_160 ) ;
V_144 -> V_195 = V_123 ;
F_89 ( V_123 , V_118 , F_161 ) ;
V_144 -> V_196 = V_123 ;
if ( F_90 ( V_2 ) ) {
F_89 ( V_145 , V_118 , F_110 ) ;
V_144 -> V_197 = 1 << V_145 ;
F_89 ( V_145 , V_118 , F_111 ) ;
V_144 -> V_198 = 1 << V_145 ;
F_89 ( V_145 , V_118 , F_132 ) ;
V_144 -> V_199 . V_126 . V_200 = V_145 & 1 ;
F_89 ( V_145 , V_118 , F_145 ) ;
V_144 -> V_180 = F_169 ( int , V_145 , V_144 -> V_180 ) ;
F_89 ( V_123 , V_118 , F_146 ) ;
V_144 -> V_181 = F_169 ( int , V_123 , V_144 -> V_181 ) ;
F_89 ( V_123 , V_118 , F_163 ) ;
V_144 -> V_201 = V_123 ;
F_89 ( V_145 , V_118 , F_164 ) ;
V_144 -> V_199 . V_126 . V_202 = 1 << ( V_145 & 0x3f ) ;
F_89 ( V_144 -> V_199 . V_126 . V_203 , V_118 ,
F_165 ) ;
F_89 ( V_144 -> V_199 . V_126 . V_204 , V_118 ,
F_166 ) ;
F_89 ( V_145 , V_118 , F_167 ) ;
V_144 -> V_199 . V_126 . V_205 = V_145 & 1 ;
F_89 ( V_144 -> V_199 . V_126 . V_206 , V_118 ,
F_168 ) ;
if ( V_144 -> V_199 . V_126 . V_203 & 1 )
F_22 ( V_2 , L_27
L_28 ,
V_144 -> V_199 . V_126 . V_203 ,
V_144 -> V_199 . V_126 . V_202 ,
V_144 -> V_199 . V_126 . V_204 ) ;
else
F_22 ( V_2 , L_29 ) ;
F_22 ( V_2 , L_30 ,
( unsigned long long ) V_144 -> V_199 . V_126 . V_206 >> 20 ) ;
} else {
F_89 ( V_145 , V_118 , F_110 ) ;
V_144 -> V_197 = ( 1 << V_145 ) - 1 ;
F_89 ( V_145 , V_118 , F_111 ) ;
V_144 -> V_198 = ( 1 << V_145 ) - 1 ;
F_89 ( V_145 , V_118 , F_128 ) ;
V_144 -> V_199 . V_133 . V_207 = 1 << ( V_145 & 0x3f ) ;
V_144 -> V_201 = V_208 ;
}
F_22 ( V_2 , L_31 ,
V_144 -> V_149 , V_144 -> V_148 , V_144 -> V_190 ) ;
F_22 ( V_2 , L_32 ,
V_144 -> V_151 , V_144 -> V_150 , V_144 -> V_195 ) ;
F_22 ( V_2 , L_33 ,
V_144 -> V_156 , V_144 -> V_155 , V_144 -> V_194 ) ;
F_22 ( V_2 , L_34 ,
V_144 -> V_159 , V_144 -> V_158 , V_144 -> V_193 ) ;
F_22 ( V_2 , L_35 ,
V_144 -> V_164 , V_144 -> V_160 ) ;
F_22 ( V_2 , L_36 ,
V_144 -> V_186 , V_144 -> V_185 , V_144 -> V_177 ) ;
F_22 ( V_2 , L_37 ,
V_144 -> V_186 , V_144 -> V_183 ) ;
F_22 ( V_2 , L_38 ,
V_144 -> V_154 , V_144 -> V_198 , V_144 -> V_197 ) ;
F_22 ( V_2 , L_39 , V_144 -> V_28 ) ;
V_64:
F_53 ( V_2 , V_87 ) ;
return V_26 ;
}
static void F_170 ( void * V_209 , char * V_210 )
{
int V_82 ;
#define F_171 0x00
#define F_172 0xde
#define F_173 0xd0
#define F_174 0x20
#define F_175 0x5ad
memset ( V_210 , 0 , V_211 ) ;
if ( F_176 ( V_209 + F_171 ) == F_175 &&
F_176 ( V_209 + F_172 ) == F_175 ) {
F_177 ( V_210 , V_209 + F_174 , V_211 ) ;
} else {
for ( V_82 = 0 ; V_82 < 4 ; ++ V_82 )
( ( T_2 * ) V_210 ) [ V_82 ] =
F_3 ( * ( T_2 * ) ( V_209 + F_173 + V_82 * 4 ) ) ;
}
}
int F_178 ( struct V_1 * V_2 ,
struct V_212 * V_213 )
{
struct V_85 * V_87 ;
T_2 * V_118 ;
int V_26 ;
#define F_179 0x100
#define F_180 0x00
#define F_181 0x04
#define F_182 0x08
#define F_183 0x10
#define F_184 0x20
V_87 = F_50 ( V_2 , V_84 ) ;
if ( F_59 ( V_87 ) )
return F_60 ( V_87 ) ;
V_118 = V_87 -> V_88 ;
V_26 = F_32 ( V_2 , 0 , V_87 -> V_89 , 0 , 0 , V_214 ,
V_113 ) ;
if ( V_26 )
goto V_64;
if ( ! F_90 ( V_2 ) ) {
F_89 ( V_213 -> V_215 , V_118 ,
F_180 ) ;
F_89 ( V_213 -> V_216 , V_118 ,
F_181 ) ;
F_89 ( V_213 -> V_217 , V_118 ,
F_182 ) ;
}
F_89 ( V_213 -> V_218 , V_118 , F_183 ) ;
F_170 ( V_118 + F_184 / 4 ,
V_213 -> V_210 ) ;
V_64:
F_53 ( V_2 , V_87 ) ;
return V_26 ;
}
int F_185 ( struct V_1 * V_2 ,
struct V_219 * V_220 )
{
struct V_85 * V_87 ;
V_65 * V_221 ;
int V_26 ;
#define F_186 0x200
#define F_187 0x00c
#define F_188 0x014
#define F_189 0x020
#define F_190 (INIT_HCA_QPC_OFFSET + 0x10)
#define F_191 (INIT_HCA_QPC_OFFSET + 0x17)
#define F_192 (INIT_HCA_QPC_OFFSET + 0x20)
#define F_193 (INIT_HCA_QPC_OFFSET + 0x27)
#define F_194 (INIT_HCA_QPC_OFFSET + 0x28)
#define F_195 (INIT_HCA_QPC_OFFSET + 0x2f)
#define F_196 (INIT_HCA_QPC_OFFSET + 0x30)
#define F_197 (INIT_HCA_QPC_OFFSET + 0x37)
#define F_198 (INIT_HCA_QPC_OFFSET + 0x40)
#define F_199 (INIT_HCA_QPC_OFFSET + 0x50)
#define F_200 (INIT_HCA_QPC_OFFSET + 0x60)
#define F_201 (INIT_HCA_QPC_OFFSET + 0x67)
#define F_202 (INIT_HCA_QPC_OFFSET + 0x70)
#define F_203 0x0b0
#define F_204 (INIT_HCA_UDAV_OFFSET + 0x0)
#define F_205 (INIT_HCA_UDAV_OFFSET + 0x4)
#define F_206 0x0c0
#define F_207 (INIT_HCA_MCAST_OFFSET + 0x00)
#define F_208 (INIT_HCA_MCAST_OFFSET + 0x12)
#define F_209 (INIT_HCA_MCAST_OFFSET + 0x16)
#define F_210 (INIT_HCA_MCAST_OFFSET + 0x1b)
#define F_211 0x0f0
#define F_212 (INIT_HCA_TPT_OFFSET + 0x00)
#define F_213 (INIT_HCA_TPT_OFFSET + 0x09)
#define F_214 (INIT_HCA_TPT_OFFSET + 0x0b)
#define F_215 (INIT_HCA_TPT_OFFSET + 0x10)
#define F_216 0x120
#define F_217 (INIT_HCA_UAR_OFFSET + 0x00)
#define F_218 (INIT_HCA_UAR_OFFSET + 0x09)
#define F_219 (INIT_HCA_UAR_OFFSET + 0x0a)
#define F_220 (INIT_HCA_UAR_OFFSET + 0x0b)
#define F_221 (INIT_HCA_UAR_OFFSET + 0x10)
#define F_222 (INIT_HCA_UAR_OFFSET + 0x18)
V_87 = F_50 ( V_2 , V_84 ) ;
if ( F_59 ( V_87 ) )
return F_60 ( V_87 ) ;
V_221 = V_87 -> V_88 ;
memset ( V_221 , 0 , F_186 ) ;
if ( V_2 -> V_140 & V_222 )
F_223 ( V_221 , 0x1 , F_187 ) ;
#if F_224 ( V_223 )
* ( V_221 + F_188 / 4 ) &= ~ F_6 ( 1 << 1 ) ;
#elif F_224 ( V_224 )
* ( V_221 + F_188 / 4 ) |= F_6 ( 1 << 1 ) ;
#else
#error Host endianness not defined
#endif
* ( V_221 + F_188 / 4 ) |= F_6 ( 1 ) ;
if ( V_2 -> V_225 & V_226 )
* ( V_221 + F_188 / 4 ) |= F_6 ( 7 << 3 ) ;
F_223 ( V_221 , V_220 -> V_227 , F_190 ) ;
F_223 ( V_221 , V_220 -> V_228 , F_191 ) ;
F_223 ( V_221 , V_220 -> V_229 , F_192 ) ;
F_223 ( V_221 , V_220 -> V_230 , F_193 ) ;
F_223 ( V_221 , V_220 -> V_231 , F_194 ) ;
F_223 ( V_221 , V_220 -> V_232 , F_195 ) ;
F_223 ( V_221 , V_220 -> V_233 , F_196 ) ;
F_223 ( V_221 , V_220 -> V_234 , F_197 ) ;
F_223 ( V_221 , V_220 -> V_235 , F_198 ) ;
F_223 ( V_221 , V_220 -> V_236 , F_199 ) ;
F_223 ( V_221 , V_220 -> V_237 , F_200 ) ;
F_223 ( V_221 , V_220 -> V_238 , F_201 ) ;
F_223 ( V_221 , V_220 -> V_239 , F_202 ) ;
F_223 ( V_221 , V_220 -> V_240 , F_207 ) ;
F_223 ( V_221 , V_220 -> V_241 , F_208 ) ;
F_223 ( V_221 , V_220 -> V_242 , F_209 ) ;
F_223 ( V_221 , V_220 -> V_243 , F_210 ) ;
F_223 ( V_221 , V_220 -> V_244 , F_212 ) ;
if ( ! F_90 ( V_2 ) )
F_223 ( V_221 , V_220 -> V_245 , F_213 ) ;
F_223 ( V_221 , V_220 -> V_246 , F_214 ) ;
F_223 ( V_221 , V_220 -> V_247 , F_215 ) ;
{
T_3 V_248 = V_132 - 12 ;
F_223 ( V_221 , V_248 , F_220 ) ;
}
F_223 ( V_221 , V_220 -> V_249 , F_221 ) ;
if ( F_90 ( V_2 ) ) {
F_223 ( V_221 , V_220 -> V_250 , F_218 ) ;
F_223 ( V_221 , V_220 -> V_251 , F_219 ) ;
F_223 ( V_221 , V_220 -> V_252 , F_222 ) ;
}
V_26 = F_33 ( V_2 , V_87 -> V_89 , 0 , 0 ,
V_253 , V_92 ) ;
F_53 ( V_2 , V_87 ) ;
return V_26 ;
}
int F_225 ( struct V_1 * V_2 ,
struct V_254 * V_220 ,
int V_255 )
{
struct V_85 * V_87 ;
T_2 * V_221 ;
int V_26 ;
T_2 V_28 ;
#define F_226 56
#define F_227 0x00
#define F_228 (1 << 18)
#define F_229 (1 << 17)
#define F_230 (1 << 16)
#define F_231 4
#define F_232 8
#define F_233 12
#define F_234 0x06
#define F_235 0x0a
#define F_236 0x10
#define F_237 0x18
#define F_238 0x20
V_87 = F_50 ( V_2 , V_84 ) ;
if ( F_59 ( V_87 ) )
return F_60 ( V_87 ) ;
V_221 = V_87 -> V_88 ;
memset ( V_221 , 0 , F_226 ) ;
V_28 = 0 ;
V_28 |= V_220 -> V_256 ? F_230 : 0 ;
V_28 |= V_220 -> V_257 ? F_229 : 0 ;
V_28 |= V_220 -> V_258 ? F_228 : 0 ;
V_28 |= V_220 -> V_259 << F_231 ;
V_28 |= V_220 -> V_260 << F_232 ;
V_28 |= V_220 -> V_261 << F_233 ;
F_223 ( V_221 , V_28 , F_227 ) ;
F_223 ( V_221 , V_220 -> V_262 , F_234 ) ;
F_223 ( V_221 , V_220 -> V_263 , F_235 ) ;
F_223 ( V_221 , V_220 -> V_264 , F_236 ) ;
F_223 ( V_221 , V_220 -> V_265 , F_237 ) ;
F_223 ( V_221 , V_220 -> V_266 , F_238 ) ;
V_26 = F_33 ( V_2 , V_87 -> V_89 , V_255 , 0 , V_267 ,
V_113 ) ;
F_53 ( V_2 , V_87 ) ;
return V_26 ;
}
int F_239 ( struct V_1 * V_2 , int V_255 )
{
return F_33 ( V_2 , 0 , V_255 , 0 , V_268 , V_113 ) ;
}
int F_240 ( struct V_1 * V_2 , int V_269 )
{
return F_33 ( V_2 , 0 , 0 , V_269 , V_270 , V_94 ) ;
}
int F_241 ( struct V_1 * V_2 , struct V_271 * V_220 ,
int V_255 )
{
struct V_85 * V_87 ;
T_2 * V_221 ;
int V_26 ;
T_2 V_28 = 0 ;
#define F_242 0x40
#define F_243 0x00
#define F_244 (1 << 18)
#define F_245 (1 << 0)
#define F_246 0x04
#define F_247 0x08
V_87 = F_50 ( V_2 , V_84 ) ;
if ( F_59 ( V_87 ) )
return F_60 ( V_87 ) ;
V_221 = V_87 -> V_88 ;
memset ( V_221 , 0 , F_242 ) ;
V_28 |= V_220 -> V_258 ? F_244 : 0 ;
V_28 |= V_220 -> V_272 ? F_245 : 0 ;
F_223 ( V_221 , V_28 , F_243 ) ;
F_223 ( V_221 , V_220 -> V_273 , F_246 ) ;
F_223 ( V_221 , V_220 -> V_266 , F_247 ) ;
V_26 = F_33 ( V_2 , V_87 -> V_89 , V_255 , 0 , V_274 ,
V_107 ) ;
F_53 ( V_2 , V_87 ) ;
return V_26 ;
}
int F_248 ( struct V_1 * V_2 , struct V_95 * V_96 , T_1 V_97 )
{
return F_58 ( V_2 , V_110 , V_96 , V_97 ) ;
}
int F_249 ( struct V_1 * V_2 , T_1 V_275 , T_1 V_97 )
{
struct V_85 * V_87 ;
T_7 * V_221 ;
int V_26 ;
V_87 = F_50 ( V_2 , V_84 ) ;
if ( F_59 ( V_87 ) )
return F_60 ( V_87 ) ;
V_221 = V_87 -> V_88 ;
V_221 [ 0 ] = F_67 ( V_97 ) ;
V_221 [ 1 ] = F_67 ( V_275 ) ;
V_26 = F_33 ( V_2 , V_87 -> V_89 , 1 , 0 , V_110 ,
V_107 ) ;
F_53 ( V_2 , V_87 ) ;
if ( ! V_26 )
F_22 ( V_2 , L_40 ,
( unsigned long long ) V_275 , ( unsigned long long ) V_97 ) ;
return V_26 ;
}
int F_250 ( struct V_1 * V_2 , T_1 V_97 , T_2 V_276 )
{
F_22 ( V_2 , L_41 ,
V_276 , ( unsigned long long ) V_97 ) ;
return F_33 ( V_2 , V_97 , V_276 , 0 ,
V_277 , V_107 ) ;
}
int F_251 ( struct V_1 * V_2 , struct V_95 * V_96 )
{
return F_58 ( V_2 , V_109 , V_96 , - 1 ) ;
}
int F_252 ( struct V_1 * V_2 )
{
return F_33 ( V_2 , 0 , 0 , 0 , V_278 , V_107 ) ;
}
int F_253 ( struct V_1 * V_2 , T_1 V_279 , T_1 * V_280 )
{
int V_90 = F_34 ( V_2 , V_279 , V_280 , 0 ,
0 , V_281 , V_113 ) ;
if ( V_90 )
return V_90 ;
* V_280 = F_91 ( * V_280 , V_131 / V_106 ) >>
( V_132 - V_105 ) ;
return 0 ;
}
int F_254 ( struct V_1 * V_2 , struct V_85 * V_87 ,
int V_282 )
{
return F_33 ( V_2 , V_87 -> V_89 , V_282 , 0 , V_283 ,
V_107 ) ;
}
int F_255 ( struct V_1 * V_2 , struct V_85 * V_87 ,
int V_282 )
{
return F_32 ( V_2 , 0 , V_87 ? V_87 -> V_89 : 0 , V_282 ,
! V_87 , V_284 ,
V_107 ) ;
}
int F_256 ( struct V_1 * V_2 , struct V_85 * V_87 ,
int V_285 )
{
return F_33 ( V_2 , V_87 -> V_89 , V_285 , 0 , V_286 ,
V_107 ) ;
}
int F_257 ( struct V_1 * V_2 )
{
return F_33 ( V_2 , 0 , 0 , 0 , V_287 , V_107 ) ;
}
int F_258 ( struct V_1 * V_2 , T_1 V_288 , int V_289 ,
int V_290 )
{
F_22 ( V_2 , L_42 ,
V_289 ? L_43 : L_44 ,
( unsigned long long ) V_288 , V_290 ) ;
return F_33 ( V_2 , V_288 , ( V_289 << 31 ) | V_290 ,
0 , V_291 , V_107 ) ;
}
int F_259 ( struct V_1 * V_2 , struct V_85 * V_87 ,
int V_290 )
{
return F_33 ( V_2 , V_87 -> V_89 , V_290 , 0 , V_292 ,
V_113 ) ;
}
int F_260 ( struct V_1 * V_2 , struct V_85 * V_87 ,
int V_290 )
{
return F_32 ( V_2 , 0 , V_87 -> V_89 , V_290 , 0 ,
V_293 ,
V_113 ) ;
}
int F_261 ( struct V_1 * V_2 , struct V_85 * V_87 ,
int V_294 )
{
return F_33 ( V_2 , V_87 -> V_89 , V_294 , 0 , V_295 ,
V_113 ) ;
}
int F_262 ( struct V_1 * V_2 , struct V_85 * V_87 ,
int V_294 )
{
return F_32 ( V_2 , 0 , V_87 -> V_89 , V_294 , 0 ,
V_296 ,
V_113 ) ;
}
int F_263 ( struct V_1 * V_2 , int V_294 , T_2 V_297 , T_3 V_298 )
{
struct V_85 * V_87 ;
V_65 * V_221 ;
int V_26 ;
#define F_264 0x40
#define F_265 0x0c
#define F_266 0x1c
V_87 = F_50 ( V_2 , V_84 ) ;
if ( F_59 ( V_87 ) )
return F_60 ( V_87 ) ;
V_221 = V_87 -> V_88 ;
memset ( V_221 , 0 , F_264 ) ;
F_223 ( V_221 , V_298 , F_265 ) ;
F_223 ( V_221 , V_297 , F_266 ) ;
V_26 = F_33 ( V_2 , V_87 -> V_89 , V_294 , 1 , V_299 ,
V_107 ) ;
F_53 ( V_2 , V_87 ) ;
return V_26 ;
}
int F_267 ( struct V_1 * V_2 , struct V_85 * V_87 ,
int V_300 )
{
return F_33 ( V_2 , V_87 -> V_89 , V_300 , 0 , V_301 ,
V_113 ) ;
}
int F_268 ( struct V_1 * V_2 , struct V_85 * V_87 ,
int V_300 )
{
return F_32 ( V_2 , 0 , V_87 -> V_89 , V_300 , 0 ,
V_302 ,
V_113 ) ;
}
int F_269 ( struct V_1 * V_2 , T_2 V_303 ,
struct V_85 * V_87 )
{
return F_32 ( V_2 , 0 , V_87 -> V_89 , V_303 , 0 ,
V_304 , V_113 ) ;
}
int F_270 ( struct V_1 * V_2 , int V_300 , int V_305 )
{
return F_33 ( V_2 , V_305 , V_300 , 0 , V_306 ,
V_107 ) ;
}
int F_271 ( struct V_1 * V_2 , enum V_307 V_308 ,
enum V_307 V_75 , T_2 V_303 , int V_309 ,
struct V_85 * V_87 , T_2 V_310 )
{
static const T_4 V_10 [ V_311 + 1 ] [ V_311 + 1 ] = {
[ V_312 ] = {
[ V_312 ] = V_313 ,
[ V_311 ] = V_314 ,
[ V_315 ] = V_316 ,
} ,
[ V_315 ] = {
[ V_312 ] = V_313 ,
[ V_311 ] = V_314 ,
[ V_315 ] = V_317 ,
[ V_318 ] = V_319 ,
} ,
[ V_318 ] = {
[ V_312 ] = V_313 ,
[ V_311 ] = V_314 ,
[ V_320 ] = V_321 ,
} ,
[ V_320 ] = {
[ V_312 ] = V_313 ,
[ V_311 ] = V_314 ,
[ V_320 ] = V_322 ,
[ V_323 ] = V_324 ,
} ,
[ V_323 ] = {
[ V_312 ] = V_313 ,
[ V_311 ] = V_314 ,
[ V_320 ] = V_325 ,
[ V_323 ] = V_326 ,
} ,
[ V_327 ] = {
[ V_312 ] = V_313 ,
[ V_311 ] = V_314 ,
[ V_320 ] = V_328 ,
} ,
[ V_311 ] = {
[ V_312 ] = V_313 ,
[ V_311 ] = V_314 ,
}
} ;
T_3 V_329 = 0 ;
int V_330 = 0 ;
int V_26 ;
if ( V_10 [ V_308 ] [ V_75 ] == V_313 ) {
V_329 = 3 ;
if ( ! V_87 ) {
V_87 = F_50 ( V_2 , V_84 ) ;
if ( ! F_59 ( V_87 ) ) {
V_330 = 1 ;
V_329 = 2 ;
} else
V_87 = NULL ;
}
V_26 = F_32 ( V_2 , 0 , V_87 ? V_87 -> V_89 : 0 ,
( ! ! V_309 << 24 ) | V_303 , V_329 ,
V_10 [ V_308 ] [ V_75 ] , V_94 ) ;
if ( 0 && V_87 ) {
int V_82 ;
F_22 ( V_2 , L_45 ) ;
F_272 ( L_46 , F_273 ( V_87 -> V_88 ) ) ;
for ( V_82 = 0 ; V_82 < 0x100 / 4 ; ++ V_82 ) {
if ( V_82 % 8 == 0 )
F_272 ( L_47 , V_82 * 4 ) ;
F_272 ( L_48 ,
F_20 ( ( ( V_65 * ) V_87 -> V_88 ) [ V_82 + 2 ] ) ) ;
if ( ( V_82 + 1 ) % 8 == 0 )
F_272 ( L_49 ) ;
}
}
if ( V_330 )
F_53 ( V_2 , V_87 ) ;
} else {
if ( 0 ) {
int V_82 ;
F_22 ( V_2 , L_45 ) ;
F_272 ( L_50 , F_273 ( V_87 -> V_88 ) ) ;
for ( V_82 = 0 ; V_82 < 0x100 / 4 ; ++ V_82 ) {
if ( V_82 % 8 == 0 )
F_272 ( L_51 , V_82 * 4 ) ;
F_272 ( L_48 ,
F_20 ( ( ( V_65 * ) V_87 -> V_88 ) [ V_82 + 2 ] ) ) ;
if ( ( V_82 + 1 ) % 8 == 0 )
F_272 ( L_49 ) ;
}
}
V_26 = F_33 ( V_2 , V_87 -> V_89 , V_310 | ( ! ! V_309 << 24 ) | V_303 ,
V_329 , V_10 [ V_308 ] [ V_75 ] , V_94 ) ;
}
return V_26 ;
}
int F_274 ( struct V_1 * V_2 , T_2 V_303 , int V_309 ,
struct V_85 * V_87 )
{
return F_32 ( V_2 , 0 , V_87 -> V_89 , ( ! ! V_309 << 24 ) | V_303 , 0 ,
V_331 , V_113 ) ;
}
int F_275 ( struct V_1 * V_2 , int type , T_2 V_332 )
{
T_3 V_329 ;
switch ( type ) {
case V_333 :
V_329 = 0 ;
break;
case V_334 :
V_329 = 1 ;
break;
case V_335 :
V_329 = 2 ;
break;
case V_336 :
V_329 = 3 ;
break;
default:
return - V_38 ;
}
return F_33 ( V_2 , 0 , V_332 , V_329 , V_337 ,
V_107 ) ;
}
int F_276 ( struct V_1 * V_2 , int V_338 , int V_339 ,
int V_255 , const struct V_340 * V_341 , const struct V_342 * V_343 ,
const void * V_344 , void * V_345 )
{
struct V_85 * V_346 , * V_347 ;
void * V_221 ;
int V_26 ;
T_2 V_8 = V_255 ;
T_3 V_9 = 0 ;
#define F_277 0x400
#define F_278 0x100
#define F_279 0x108
#define F_280 0x10c
#define F_281 0x10d
#define F_282 0x10e
#define F_283 0x112
#define F_284 0x140
V_346 = F_50 ( V_2 , V_84 ) ;
if ( F_59 ( V_346 ) )
return F_60 ( V_346 ) ;
V_221 = V_346 -> V_88 ;
V_347 = F_50 ( V_2 , V_84 ) ;
if ( F_59 ( V_347 ) ) {
F_53 ( V_2 , V_346 ) ;
return F_60 ( V_347 ) ;
}
memcpy ( V_221 , V_344 , 256 ) ;
if ( V_338 || ! V_341 )
V_9 |= 0x1 ;
if ( V_339 || ! V_341 )
V_9 |= 0x2 ;
if ( V_341 ) {
T_3 V_348 ;
memset ( V_221 + 256 , 0 , 256 ) ;
F_223 ( V_221 , V_341 -> V_349 -> V_350 , F_278 ) ;
F_223 ( V_221 , V_341 -> V_351 , F_279 ) ;
V_348 = V_341 -> V_352 << 4 ;
F_223 ( V_221 , V_348 , F_280 ) ;
V_348 = V_341 -> V_353 |
( V_341 -> V_354 & V_355 ? 0x80 : 0 ) ;
F_223 ( V_221 , V_348 , F_281 ) ;
F_223 ( V_221 , V_341 -> V_356 , F_282 ) ;
F_223 ( V_221 , V_341 -> V_357 , F_283 ) ;
if ( V_343 )
memcpy ( V_221 + F_284 , V_343 , 40 ) ;
V_9 |= 0x4 ;
V_8 |= V_341 -> V_356 << 16 ;
}
V_26 = F_32 ( V_2 , V_346 -> V_89 , V_347 -> V_89 ,
V_8 , V_9 ,
V_358 , V_94 ) ;
if ( ! V_26 )
memcpy ( V_345 , V_347 -> V_88 , 256 ) ;
F_53 ( V_2 , V_346 ) ;
F_53 ( V_2 , V_347 ) ;
return V_26 ;
}
int F_285 ( struct V_1 * V_2 , int V_359 ,
struct V_85 * V_87 )
{
return F_32 ( V_2 , 0 , V_87 -> V_89 , V_359 , 0 ,
V_360 , V_113 ) ;
}
int F_286 ( struct V_1 * V_2 , int V_359 ,
struct V_85 * V_87 )
{
return F_33 ( V_2 , V_87 -> V_89 , V_359 , 0 , V_361 ,
V_113 ) ;
}
int F_287 ( struct V_1 * V_2 , struct V_85 * V_87 ,
T_4 * V_362 )
{
T_1 V_363 ;
int V_26 ;
V_26 = F_34 ( V_2 , V_87 -> V_89 , & V_363 , 0 , 0 , V_364 ,
V_113 ) ;
* V_362 = V_363 ;
return V_26 ;
}
int F_288 ( struct V_1 * V_2 )
{
return F_33 ( V_2 , 0 , 0x1f , 0 , V_365 , F_289 ( 100 ) ) ;
}
