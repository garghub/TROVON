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
static int F_16 ( struct V_1 * V_2 ,
T_1 V_6 ,
T_1 * V_7 ,
int V_31 ,
T_2 V_8 ,
T_3 V_9 ,
T_4 V_10 ,
unsigned long V_32 ,
T_3 * V_33 )
{
int V_26 = 0 ;
unsigned long V_21 ;
F_17 ( & V_2 -> V_13 . V_34 ) ;
V_26 = F_12 ( V_2 , V_6 ,
V_7 ? * V_7 : 0 ,
V_8 , V_9 ,
V_10 , V_35 , 0 ) ;
if ( V_26 )
goto V_36;
V_21 = V_32 + V_22 ;
while ( F_1 ( V_2 ) && F_9 ( V_22 , V_21 ) ) {
F_10 ( V_24 ) ;
F_11 () ;
}
if ( F_1 ( V_2 ) ) {
V_26 = - V_37 ;
goto V_36;
}
if ( V_31 )
* V_7 =
( T_1 ) F_18 ( ( V_17 V_38 )
F_19 ( V_2 -> V_3 + V_39 ) ) << 32 |
( T_1 ) F_18 ( ( V_17 V_38 )
F_19 ( V_2 -> V_3 + V_39 + 4 ) ) ;
* V_33 = F_18 ( ( V_17 V_38 ) F_19 ( V_2 -> V_3 + V_4 ) ) >> 24 ;
V_36:
F_20 ( & V_2 -> V_13 . V_34 ) ;
return V_26 ;
}
void F_21 ( struct V_1 * V_2 ,
T_4 V_11 ,
T_3 V_33 ,
T_1 V_7 )
{
struct V_40 * V_41 =
& V_2 -> V_13 . V_41 [ V_11 & V_2 -> V_13 . V_42 ] ;
if ( V_11 != V_41 -> V_11 )
return;
V_41 -> V_43 = 0 ;
V_41 -> V_33 = V_33 ;
V_41 -> V_7 = V_7 ;
F_22 ( & V_41 -> V_44 ) ;
}
static int F_23 ( struct V_1 * V_2 ,
T_1 V_6 ,
T_1 * V_7 ,
int V_31 ,
T_2 V_8 ,
T_3 V_9 ,
T_4 V_10 ,
unsigned long V_32 ,
T_3 * V_33 )
{
int V_26 = 0 ;
struct V_40 * V_41 ;
F_17 ( & V_2 -> V_13 . V_45 ) ;
F_24 ( & V_2 -> V_13 . V_46 ) ;
F_25 ( V_2 -> V_13 . V_47 < 0 ) ;
V_41 = & V_2 -> V_13 . V_41 [ V_2 -> V_13 . V_47 ] ;
V_41 -> V_11 += V_2 -> V_13 . V_42 + 1 ;
V_2 -> V_13 . V_47 = V_41 -> V_48 ;
F_26 ( & V_2 -> V_13 . V_46 ) ;
F_27 ( & V_41 -> V_44 ) ;
V_26 = F_12 ( V_2 , V_6 ,
V_7 ? * V_7 : 0 ,
V_8 , V_9 ,
V_10 , V_41 -> V_11 , 1 ) ;
if ( V_26 )
goto V_36;
if ( ! F_28 ( & V_41 -> V_44 , V_32 ) ) {
V_26 = - V_37 ;
goto V_36;
}
V_26 = V_41 -> V_43 ;
if ( V_26 )
goto V_36;
* V_33 = V_41 -> V_33 ;
if ( * V_33 )
F_29 ( V_2 , L_1 ,
V_10 , * V_33 ) ;
if ( V_31 )
* V_7 = V_41 -> V_7 ;
V_36:
F_24 ( & V_2 -> V_13 . V_46 ) ;
V_41 -> V_48 = V_2 -> V_13 . V_47 ;
V_2 -> V_13 . V_47 = V_41 - V_2 -> V_13 . V_41 ;
F_26 ( & V_2 -> V_13 . V_46 ) ;
F_20 ( & V_2 -> V_13 . V_45 ) ;
return V_26 ;
}
static int F_30 ( struct V_1 * V_2 ,
T_1 V_6 ,
T_1 V_7 ,
T_2 V_8 ,
T_3 V_9 ,
T_4 V_10 ,
unsigned long V_32 ,
T_3 * V_33 )
{
if ( V_2 -> V_13 . V_28 & V_49 )
return F_23 ( V_2 , V_6 , & V_7 , 0 ,
V_8 , V_9 , V_10 ,
V_32 , V_33 ) ;
else
return F_16 ( V_2 , V_6 , & V_7 , 0 ,
V_8 , V_9 , V_10 ,
V_32 , V_33 ) ;
}
static int F_31 ( struct V_1 * V_2 ,
T_1 V_6 ,
T_2 V_8 ,
T_3 V_9 ,
T_4 V_10 ,
unsigned long V_32 ,
T_3 * V_33 )
{
return F_30 ( V_2 , V_6 , 0 , V_8 ,
V_9 , V_10 , V_32 , V_33 ) ;
}
static int F_32 ( struct V_1 * V_2 ,
T_1 V_6 ,
T_1 * V_7 ,
T_2 V_8 ,
T_3 V_9 ,
T_4 V_10 ,
unsigned long V_32 ,
T_3 * V_33 )
{
if ( V_2 -> V_13 . V_28 & V_49 )
return F_23 ( V_2 , V_6 , V_7 , 1 ,
V_8 , V_9 , V_10 ,
V_32 , V_33 ) ;
else
return F_16 ( V_2 , V_6 , V_7 , 1 ,
V_8 , V_9 , V_10 ,
V_32 , V_33 ) ;
}
int F_33 ( struct V_1 * V_2 )
{
F_34 ( & V_2 -> V_13 . V_27 ) ;
F_35 ( & V_2 -> V_13 . V_34 , 1 ) ;
V_2 -> V_13 . V_28 = 0 ;
V_2 -> V_3 = F_36 ( F_37 ( V_2 -> V_50 , 0 ) + V_51 ,
V_52 ) ;
if ( ! V_2 -> V_3 ) {
F_38 ( V_2 , L_2 ) ;
return - V_53 ;
}
V_2 -> V_13 . V_54 = F_39 ( L_3 , V_2 -> V_50 ,
V_55 ,
V_55 , 0 ) ;
if ( ! V_2 -> V_13 . V_54 ) {
F_40 ( V_2 -> V_3 ) ;
return - V_53 ;
}
return 0 ;
}
void F_41 ( struct V_1 * V_2 )
{
F_42 ( V_2 -> V_13 . V_54 ) ;
F_40 ( V_2 -> V_3 ) ;
if ( V_2 -> V_13 . V_28 & V_29 )
F_40 ( V_2 -> V_13 . V_14 ) ;
}
int F_43 ( struct V_1 * V_2 )
{
int V_56 ;
V_2 -> V_13 . V_41 = F_44 ( V_2 -> V_13 . V_57 *
sizeof ( struct V_40 ) ,
V_58 ) ;
if ( ! V_2 -> V_13 . V_41 )
return - V_53 ;
for ( V_56 = 0 ; V_56 < V_2 -> V_13 . V_57 ; ++ V_56 ) {
V_2 -> V_13 . V_41 [ V_56 ] . V_11 = V_56 ;
V_2 -> V_13 . V_41 [ V_56 ] . V_48 = V_56 + 1 ;
}
V_2 -> V_13 . V_41 [ V_2 -> V_13 . V_57 - 1 ] . V_48 = - 1 ;
V_2 -> V_13 . V_47 = 0 ;
F_35 ( & V_2 -> V_13 . V_45 , V_2 -> V_13 . V_57 ) ;
F_45 ( & V_2 -> V_13 . V_46 ) ;
for ( V_2 -> V_13 . V_42 = 1 ;
V_2 -> V_13 . V_42 < V_2 -> V_13 . V_57 ;
V_2 -> V_13 . V_42 <<= 1 )
;
-- V_2 -> V_13 . V_42 ;
V_2 -> V_13 . V_28 |= V_49 ;
F_17 ( & V_2 -> V_13 . V_34 ) ;
return 0 ;
}
void F_46 ( struct V_1 * V_2 )
{
int V_56 ;
V_2 -> V_13 . V_28 &= ~ V_49 ;
for ( V_56 = 0 ; V_56 < V_2 -> V_13 . V_57 ; ++ V_56 )
F_17 ( & V_2 -> V_13 . V_45 ) ;
F_47 ( V_2 -> V_13 . V_41 ) ;
F_20 ( & V_2 -> V_13 . V_34 ) ;
}
struct V_59 * F_48 ( struct V_1 * V_2 ,
T_6 V_60 )
{
struct V_59 * V_61 ;
V_61 = F_44 ( sizeof *V_61 , V_60 ) ;
if ( ! V_61 )
return F_49 ( - V_53 ) ;
V_61 -> V_62 = F_50 ( V_2 -> V_13 . V_54 , V_60 , & V_61 -> V_63 ) ;
if ( ! V_61 -> V_62 ) {
F_47 ( V_61 ) ;
return F_49 ( - V_53 ) ;
}
return V_61 ;
}
void F_51 ( struct V_1 * V_2 , struct V_59 * V_61 )
{
if ( ! V_61 )
return;
F_52 ( V_2 -> V_13 . V_54 , V_61 -> V_62 , V_61 -> V_63 ) ;
F_47 ( V_61 ) ;
}
int F_53 ( struct V_1 * V_2 , T_3 * V_33 )
{
T_1 V_36 ;
int V_64 ;
V_64 = F_32 ( V_2 , 0 , & V_36 , 0 , 0 , V_65 , V_66 , V_33 ) ;
if ( * V_33 == V_67 )
F_54 ( V_2 , L_4
L_5 ,
( int ) ( V_36 >> 6 ) & 0xf , ( int ) ( V_36 >> 4 ) & 3 ,
( int ) ( V_36 >> 1 ) & 7 , ( int ) V_36 & 1 ? L_6 : L_7 ) ;
return V_64 ;
}
int F_55 ( struct V_1 * V_2 , T_3 * V_33 )
{
return F_31 ( V_2 , 0 , 0 , 0 , V_68 , V_69 , V_33 ) ;
}
static int F_56 ( struct V_1 * V_2 , T_4 V_10 , struct V_70 * V_71 ,
T_1 V_72 , T_3 * V_33 )
{
struct V_59 * V_61 ;
struct V_73 V_74 ;
T_7 * V_75 ;
int V_76 ;
int V_77 = 0 ;
int V_56 ;
int V_26 = 0 ;
int V_78 = 0 , V_79 = 0 ;
V_61 = F_48 ( V_2 , V_58 ) ;
if ( F_57 ( V_61 ) )
return F_58 ( V_61 ) ;
memset ( V_61 -> V_62 , 0 , V_55 ) ;
V_75 = V_61 -> V_62 ;
for ( F_59 ( V_71 , & V_74 ) ;
! F_60 ( & V_74 ) ;
F_61 ( & V_74 ) ) {
V_76 = F_62 ( F_63 ( & V_74 ) | F_64 ( & V_74 ) ) - 1 ;
if ( V_76 < V_80 ) {
F_54 ( V_2 , L_8 ,
V_81 ,
( unsigned long long ) F_63 ( & V_74 ) ,
F_64 ( & V_74 ) ) ;
V_26 = - V_82 ;
goto V_36;
}
for ( V_56 = 0 ; V_56 < F_64 ( & V_74 ) > > V_76 ; ++ V_56 ) {
if ( V_72 != - 1 ) {
V_75 [ V_77 * 2 ] = F_65 ( V_72 ) ;
V_72 += 1 << V_76 ;
}
V_75 [ V_77 * 2 + 1 ] =
F_65 ( ( F_63 ( & V_74 ) + ( V_56 << V_76 ) ) |
( V_76 - V_80 ) ) ;
V_78 += 1 << ( V_76 - 10 ) ;
++ V_79 ;
if ( ++ V_77 == V_55 / 16 ) {
V_26 = F_31 ( V_2 , V_61 -> V_63 , V_77 , 0 , V_10 ,
V_83 , V_33 ) ;
if ( V_26 || * V_33 )
goto V_36;
V_77 = 0 ;
}
}
}
if ( V_77 )
V_26 = F_31 ( V_2 , V_61 -> V_63 , V_77 , 0 , V_10 ,
V_83 , V_33 ) ;
switch ( V_10 ) {
case V_84 :
F_29 ( V_2 , L_9 , V_79 , V_78 ) ;
break;
case V_85 :
F_29 ( V_2 , L_10 , V_79 , V_78 ) ;
break;
case V_86 :
F_29 ( V_2 , L_11 ,
V_79 , V_78 , ( unsigned long long ) V_72 - ( V_78 << 10 ) ) ;
break;
}
V_36:
F_51 ( V_2 , V_61 ) ;
return V_26 ;
}
int F_66 ( struct V_1 * V_2 , struct V_70 * V_71 , T_3 * V_33 )
{
return F_56 ( V_2 , V_84 , V_71 , - 1 , V_33 ) ;
}
int F_67 ( struct V_1 * V_2 , T_3 * V_33 )
{
return F_31 ( V_2 , 0 , 0 , 0 , V_87 , V_83 , V_33 ) ;
}
int F_68 ( struct V_1 * V_2 , T_3 * V_33 )
{
return F_31 ( V_2 , 0 , 0 , 0 , V_88 , V_89 , V_33 ) ;
}
static void F_69 ( struct V_1 * V_2 , T_1 V_90 )
{
T_8 V_91 ;
T_4 V_92 = 0 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < 8 ; ++ V_56 )
V_92 = F_70 ( V_92 , V_2 -> V_13 . V_16 [ V_56 ] ) ;
if ( ( V_90 & V_93 ) != ( ( V_90 + V_92 ) & V_93 ) ) {
F_54 ( V_2 , L_12
L_13 ,
( unsigned long long ) V_90 , V_92 ) ;
return;
}
V_91 = F_37 ( V_2 -> V_50 , 2 ) +
( ( F_71 ( V_2 -> V_50 , 2 ) - 1 ) & V_90 ) ;
V_2 -> V_13 . V_14 = F_36 ( V_91 , V_92 + sizeof( T_2 ) ) ;
if ( ! V_2 -> V_13 . V_14 )
return;
V_2 -> V_13 . V_28 |= V_29 ;
F_29 ( V_2 , L_14 ) ;
}
int F_72 ( struct V_1 * V_2 , T_3 * V_33 )
{
struct V_59 * V_61 ;
T_2 * V_94 ;
T_1 V_90 ;
T_2 V_95 ;
int V_26 = 0 ;
T_3 V_76 ;
int V_56 ;
#define F_73 0x100
#define F_74 0x00
#define F_75 0x0f
#define F_76 0x30
#define F_77 0x38
#define F_78 0x10
#define F_79 0x50
#define F_80 0x60
#define F_81 0x20
#define F_82 0x28
#define F_83 0x00
#define F_84 0x20
#define F_85 0x40
#define F_86 0x48
V_61 = F_48 ( V_2 , V_58 ) ;
if ( F_57 ( V_61 ) )
return F_58 ( V_61 ) ;
V_94 = V_61 -> V_62 ;
V_26 = F_30 ( V_2 , 0 , V_61 -> V_63 , 0 , 0 , V_96 ,
V_89 , V_33 ) ;
if ( V_26 )
goto V_36;
F_87 ( V_2 -> V_97 , V_94 , F_74 ) ;
V_2 -> V_97 = ( V_2 -> V_97 & 0xffff00000000ull ) |
( ( V_2 -> V_97 & 0xffff0000ull ) >> 16 ) |
( ( V_2 -> V_97 & 0x0000ffffull ) << 16 ) ;
F_87 ( V_76 , V_94 , F_75 ) ;
V_2 -> V_13 . V_57 = 1 << V_76 ;
F_29 ( V_2 , L_15 ,
( unsigned long long ) V_2 -> V_97 , V_2 -> V_13 . V_57 ) ;
F_87 ( V_2 -> V_98 . V_91 , V_94 , F_76 ) ;
F_87 ( V_2 -> V_98 . V_99 , V_94 , F_77 ) ;
F_29 ( V_2 , L_16 ,
( unsigned long long ) V_2 -> V_98 . V_91 , V_2 -> V_98 . V_99 ) ;
F_87 ( V_95 , V_94 , F_78 ) ;
if ( V_95 & 0x1 ) {
F_29 ( V_2 , L_17 ) ;
F_87 ( V_90 , V_94 , F_80 ) ;
for ( V_56 = 0 ; V_56 < V_100 ; ++ V_56 )
F_87 ( V_2 -> V_13 . V_16 [ V_56 ] , V_94 ,
F_79 + ( V_56 << 1 ) ) ;
F_69 ( V_2 , V_90 ) ;
}
if ( F_88 ( V_2 ) ) {
F_87 ( V_2 -> V_101 . V_102 . V_103 , V_94 , F_83 ) ;
F_87 ( V_2 -> V_101 . V_102 . V_104 , V_94 , F_84 ) ;
F_87 ( V_2 -> V_101 . V_102 . V_105 , V_94 , F_85 ) ;
F_87 ( V_2 -> V_101 . V_102 . V_106 , V_94 , F_86 ) ;
F_29 ( V_2 , L_18 , V_2 -> V_101 . V_102 . V_103 << 2 ) ;
V_2 -> V_101 . V_102 . V_103 =
F_89 ( V_2 -> V_101 . V_102 . V_103 , V_107 / V_81 ) >>
( V_108 - V_80 ) ;
F_29 ( V_2 , L_19 ,
( unsigned long long ) V_2 -> V_101 . V_102 . V_104 ,
( unsigned long long ) V_2 -> V_101 . V_102 . V_105 ,
( unsigned long long ) V_2 -> V_101 . V_102 . V_106 ) ;
} else {
F_87 ( V_2 -> V_101 . V_109 . V_110 , V_94 , F_81 ) ;
F_87 ( V_2 -> V_101 . V_109 . V_111 , V_94 , F_82 ) ;
F_29 ( V_2 , L_20 ,
( int ) ( ( V_2 -> V_101 . V_109 . V_111 - V_2 -> V_101 . V_109 . V_110 ) >> 10 ) ,
( unsigned long long ) V_2 -> V_101 . V_109 . V_110 ,
( unsigned long long ) V_2 -> V_101 . V_109 . V_111 ) ;
}
V_36:
F_51 ( V_2 , V_61 ) ;
return V_26 ;
}
int F_90 ( struct V_1 * V_2 , T_3 * V_33 )
{
struct V_59 * V_61 ;
T_3 V_112 ;
T_2 * V_94 ;
int V_26 = 0 ;
#define F_91 0x100
#define F_92 0x00
#define F_93 0x08
#define F_94 0x13
#define F_95 (1 << 4)
#define F_96 0x3
V_61 = F_48 ( V_2 , V_58 ) ;
if ( F_57 ( V_61 ) )
return F_58 ( V_61 ) ;
V_94 = V_61 -> V_62 ;
V_26 = F_30 ( V_2 , 0 , V_61 -> V_63 , 0 , 0 , V_113 ,
V_69 , V_33 ) ;
if ( V_26 )
goto V_36;
if ( * V_33 == V_114 )
goto V_36;
F_87 ( V_2 -> V_115 , V_94 , F_92 ) ;
F_87 ( V_2 -> V_116 , V_94 , F_93 ) ;
F_87 ( V_112 , V_94 , F_94 ) ;
if ( ! ! ( V_112 & F_95 ) !=
! ! ( V_2 -> V_117 & V_118 ) ) {
F_97 ( V_2 , L_21
L_22 ,
( V_112 & F_95 ) ?
L_23 : L_24 ) ;
}
if ( V_112 & F_95 )
F_29 ( V_2 , L_25 ) ;
F_29 ( V_2 , L_26 ,
( int ) ( ( V_2 -> V_116 - V_2 -> V_115 ) >> 10 ) ,
( unsigned long long ) V_2 -> V_115 ,
( unsigned long long ) V_2 -> V_116 ) ;
V_36:
F_51 ( V_2 , V_61 ) ;
return V_26 ;
}
int F_98 ( struct V_1 * V_2 , T_3 * V_33 )
{
return F_31 ( V_2 , 0 , 0 , 0 , V_68 , V_69 , V_33 ) ;
}
int F_99 ( struct V_1 * V_2 , T_3 * V_33 )
{
struct V_59 * V_61 ;
T_3 V_112 ;
T_2 * V_94 ;
int V_26 = 0 ;
#define F_100 0x100
#define F_101 0x00
#define F_102 0x08
#define F_103 0x13
#define F_104 (1 << 4)
#define F_105 0x3
V_61 = F_48 ( V_2 , V_58 ) ;
if ( F_57 ( V_61 ) )
return F_58 ( V_61 ) ;
V_94 = V_61 -> V_62 ;
V_26 = F_30 ( V_2 , 0 , V_61 -> V_63 , 0 , 0 , V_119 ,
V_89 , V_33 ) ;
if ( V_26 )
goto V_36;
F_87 ( V_2 -> V_115 , V_94 , F_101 ) ;
F_87 ( V_2 -> V_116 , V_94 , F_102 ) ;
F_87 ( V_112 , V_94 , F_103 ) ;
if ( ! ! ( V_112 & F_104 ) !=
! ! ( V_2 -> V_117 & V_118 ) ) {
F_97 ( V_2 , L_21
L_22 ,
( V_112 & F_104 ) ?
L_23 : L_24 ) ;
}
if ( V_112 & F_104 )
F_29 ( V_2 , L_25 ) ;
F_29 ( V_2 , L_26 ,
( int ) ( ( V_2 -> V_116 - V_2 -> V_115 ) >> 10 ) ,
( unsigned long long ) V_2 -> V_115 ,
( unsigned long long ) V_2 -> V_116 ) ;
V_36:
F_51 ( V_2 , V_61 ) ;
return V_26 ;
}
int F_106 ( struct V_1 * V_2 ,
struct V_120 * V_121 , T_3 * V_33 )
{
struct V_59 * V_61 ;
T_2 * V_94 ;
T_3 V_122 ;
T_4 V_99 ;
T_4 V_123 ;
int V_26 ;
#define F_107 0x100
#define F_108 0x10
#define F_109 0x11
#define F_110 0x12
#define F_111 0x13
#define F_112 0x14
#define F_113 0x15
#define F_114 0x16
#define F_115 0x17
#define F_116 0x19
#define F_117 0x1a
#define F_118 0x1b
#define F_119 0x1d
#define F_120 0x1e
#define F_121 0x1f
#define F_122 0x20
#define F_123 0x21
#define F_124 0x22
#define F_125 0x23
#define F_126 0x27
#define F_127 0x29
#define F_128 0x2b
#define F_129 0x2f
#define F_130 0x33
#define F_131 0x35
#define F_132 0x36
#define F_133 0x37
#define F_134 0x3b
#define F_135 0x3c
#define F_136 0x3f
#define F_137 0x44
#define F_138 0x48
#define F_139 0x49
#define F_140 0x4b
#define F_141 0x51
#define F_142 0x52
#define F_143 0x55
#define F_144 0x56
#define F_145 0x61
#define F_146 0x62
#define F_147 0x63
#define F_148 0x64
#define F_149 0x65
#define F_150 0x66
#define F_151 0x67
#define F_152 0x80
#define F_153 0x82
#define F_154 0x84
#define F_155 0x86
#define F_156 0x88
#define F_157 0x8a
#define F_158 0x8c
#define F_159 0x8e
#define F_160 0x90
#define F_161 0x92
#define F_162 0x96
#define F_163 0x97
#define F_164 0x98
#define F_165 0x9f
#define F_166 0xa0
V_61 = F_48 ( V_2 , V_58 ) ;
if ( F_57 ( V_61 ) )
return F_58 ( V_61 ) ;
V_94 = V_61 -> V_62 ;
V_26 = F_30 ( V_2 , 0 , V_61 -> V_63 , 0 , 0 , V_124 ,
V_89 , V_33 ) ;
if ( V_26 )
goto V_36;
F_87 ( V_122 , V_94 , F_110 ) ;
V_121 -> V_125 = 1 << ( V_122 & 0xf ) ;
F_87 ( V_122 , V_94 , F_111 ) ;
V_121 -> V_126 = 1 << ( V_122 & 0x1f ) ;
F_87 ( V_122 , V_94 , F_112 ) ;
V_121 -> V_127 = 1 << ( V_122 >> 4 ) ;
F_87 ( V_122 , V_94 , F_113 ) ;
V_121 -> V_128 = 1 << ( V_122 & 0x1f ) ;
F_87 ( V_122 , V_94 , F_114 ) ;
V_121 -> V_129 = 1 << ( V_122 & 0xf ) ;
F_87 ( V_122 , V_94 , F_115 ) ;
V_121 -> V_130 = 1 << ( V_122 & 0x1f ) ;
F_87 ( V_122 , V_94 , F_116 ) ;
V_121 -> V_131 = 1 << V_122 ;
F_87 ( V_122 , V_94 , F_117 ) ;
V_121 -> V_132 = 1 << ( V_122 & 0xf ) ;
F_87 ( V_122 , V_94 , F_118 ) ;
V_121 -> V_133 = 1 << ( V_122 & 0x1f ) ;
F_87 ( V_122 , V_94 , F_119 ) ;
V_121 -> V_134 = 1 << ( V_122 & 0x3f ) ;
F_87 ( V_122 , V_94 , F_120 ) ;
V_121 -> V_135 = 1 << ( V_122 & 0xf ) ;
F_87 ( V_122 , V_94 , F_121 ) ;
V_121 -> V_136 = 1 << ( V_122 & 0x7 ) ;
F_87 ( V_122 , V_94 , F_122 ) ;
if ( F_88 ( V_2 ) )
V_121 -> V_137 = F_89 ( ( 1 << ( V_122 >> 4 ) ) * sizeof( T_1 ) ,
V_2 -> V_138 . V_139 ) / V_2 -> V_138 . V_139 ;
else
V_121 -> V_137 = 1 << ( V_122 >> 4 ) ;
F_87 ( V_122 , V_94 , F_123 ) ;
V_121 -> V_140 = 1 << V_122 ;
F_87 ( V_122 , V_94 , F_124 ) ;
V_121 -> V_141 = 1 << ( V_122 & 0xf ) ;
F_87 ( V_122 , V_94 , F_125 ) ;
V_121 -> V_142 = 1 << ( V_122 & 0x3f ) ;
F_87 ( V_122 , V_94 , F_127 ) ;
V_121 -> V_143 = 1 << ( V_122 & 0x3f ) ;
F_87 ( V_122 , V_94 , F_128 ) ;
V_121 -> V_144 = 1 << ( V_122 & 0x3f ) ;
F_87 ( V_122 , V_94 , F_129 ) ;
V_121 -> V_145 = 1 << ( V_122 & 0x3f ) ;
F_87 ( V_122 , V_94 , F_131 ) ;
V_121 -> V_146 = V_122 & 0x1f ;
F_87 ( V_122 , V_94 , F_132 ) ;
V_121 -> V_147 = V_122 >> 4 ;
V_121 -> V_148 = V_122 & 0xf ;
F_87 ( V_122 , V_94 , F_133 ) ;
V_121 -> V_149 = V_122 >> 4 ;
V_121 -> V_150 = V_122 & 0xf ;
F_87 ( V_122 , V_94 , F_134 ) ;
V_121 -> V_151 = 1 << ( V_122 & 0xf ) ;
F_87 ( V_123 , V_94 , F_135 ) ;
V_121 -> V_152 = V_123 ;
F_87 ( V_122 , V_94 , F_136 ) ;
V_121 -> V_153 = 1 << ( V_122 & 0xf ) ;
F_87 ( V_121 -> V_28 , V_94 , F_137 ) ;
F_87 ( V_122 , V_94 , F_138 ) ;
V_121 -> V_154 = V_122 >> 4 ;
F_87 ( V_122 , V_94 , F_139 ) ;
V_121 -> V_155 = 1 << ( ( V_122 & 0x3f ) + 20 ) ;
F_87 ( V_122 , V_94 , F_140 ) ;
V_121 -> V_156 = 1 << V_122 ;
F_87 ( V_122 , V_94 , F_141 ) ;
V_121 -> V_157 = V_122 ;
F_87 ( V_99 , V_94 , F_142 ) ;
V_121 -> V_158 = V_99 ;
F_87 ( V_122 , V_94 , F_145 ) ;
V_121 -> V_159 = 1 << V_122 ;
F_87 ( V_122 , V_94 , F_146 ) ;
V_121 -> V_160 = V_122 & 0xf ;
F_87 ( V_122 , V_94 , F_147 ) ;
V_121 -> V_161 = 1 << V_122 ;
F_87 ( V_122 , V_94 , F_148 ) ;
V_121 -> V_162 = V_122 >> 4 ;
F_87 ( V_122 , V_94 , F_149 ) ;
V_121 -> V_163 = 1 << ( V_122 & 0x3f ) ;
F_87 ( V_122 , V_94 , F_150 ) ;
V_121 -> V_164 = V_122 >> 4 ;
F_87 ( V_122 , V_94 , F_151 ) ;
V_121 -> V_165 = 1 << ( V_122 & 0x3f ) ;
F_87 ( V_99 , V_94 , F_152 ) ;
V_121 -> V_166 = V_99 ;
F_87 ( V_99 , V_94 , F_153 ) ;
V_121 -> V_167 = V_99 ;
F_87 ( V_99 , V_94 , F_154 ) ;
V_121 -> V_168 = V_99 ;
F_87 ( V_99 , V_94 , F_155 ) ;
V_121 -> V_169 = V_99 ;
F_87 ( V_99 , V_94 , F_156 ) ;
V_121 -> V_170 = V_99 ;
F_87 ( V_99 , V_94 , F_157 ) ;
V_121 -> V_171 = V_99 ;
F_87 ( V_99 , V_94 , F_158 ) ;
V_121 -> V_172 = V_99 ;
F_87 ( V_99 , V_94 , F_159 ) ;
V_121 -> V_173 = V_99 ;
if ( F_88 ( V_2 ) ) {
F_87 ( V_122 , V_94 , F_108 ) ;
V_121 -> V_174 = 1 << V_122 ;
F_87 ( V_122 , V_94 , F_109 ) ;
V_121 -> V_175 = 1 << V_122 ;
F_87 ( V_122 , V_94 , F_130 ) ;
V_121 -> V_176 . V_102 . V_177 = V_122 & 1 ;
F_87 ( V_122 , V_94 , F_143 ) ;
V_121 -> V_157 = F_167 ( int , V_122 , V_121 -> V_157 ) ;
F_87 ( V_99 , V_94 , F_144 ) ;
V_121 -> V_158 = F_167 ( int , V_99 , V_121 -> V_158 ) ;
F_87 ( V_99 , V_94 , F_161 ) ;
V_121 -> V_178 = V_99 ;
F_87 ( V_122 , V_94 , F_162 ) ;
V_121 -> V_176 . V_102 . V_179 = 1 << ( V_122 & 0x3f ) ;
F_87 ( V_121 -> V_176 . V_102 . V_180 , V_94 ,
F_163 ) ;
F_87 ( V_121 -> V_176 . V_102 . V_181 , V_94 ,
F_164 ) ;
F_87 ( V_122 , V_94 , F_165 ) ;
V_121 -> V_176 . V_102 . V_182 = V_122 & 1 ;
F_87 ( V_121 -> V_176 . V_102 . V_183 , V_94 ,
F_166 ) ;
if ( V_121 -> V_176 . V_102 . V_180 & 1 )
F_29 ( V_2 , L_27
L_28 ,
V_121 -> V_176 . V_102 . V_180 ,
V_121 -> V_176 . V_102 . V_179 ,
V_121 -> V_176 . V_102 . V_181 ) ;
else
F_29 ( V_2 , L_29 ) ;
F_29 ( V_2 , L_30 ,
( unsigned long long ) V_121 -> V_176 . V_102 . V_183 >> 20 ) ;
} else {
F_87 ( V_122 , V_94 , F_108 ) ;
V_121 -> V_174 = ( 1 << V_122 ) - 1 ;
F_87 ( V_122 , V_94 , F_109 ) ;
V_121 -> V_175 = ( 1 << V_122 ) - 1 ;
F_87 ( V_122 , V_94 , F_126 ) ;
V_121 -> V_176 . V_109 . V_184 = 1 << ( V_122 & 0x3f ) ;
V_121 -> V_178 = V_185 ;
}
F_29 ( V_2 , L_31 ,
V_121 -> V_126 , V_121 -> V_125 , V_121 -> V_167 ) ;
F_29 ( V_2 , L_32 ,
V_121 -> V_128 , V_121 -> V_127 , V_121 -> V_172 ) ;
F_29 ( V_2 , L_33 ,
V_121 -> V_133 , V_121 -> V_132 , V_121 -> V_171 ) ;
F_29 ( V_2 , L_34 ,
V_121 -> V_136 , V_121 -> V_135 , V_121 -> V_170 ) ;
F_29 ( V_2 , L_35 ,
V_121 -> V_141 , V_121 -> V_137 ) ;
F_29 ( V_2 , L_36 ,
V_121 -> V_163 , V_121 -> V_162 , V_121 -> V_154 ) ;
F_29 ( V_2 , L_37 ,
V_121 -> V_163 , V_121 -> V_160 ) ;
F_29 ( V_2 , L_38 ,
V_121 -> V_131 , V_121 -> V_175 , V_121 -> V_174 ) ;
F_29 ( V_2 , L_39 , V_121 -> V_28 ) ;
V_36:
F_51 ( V_2 , V_61 ) ;
return V_26 ;
}
static void F_168 ( void * V_186 , char * V_187 )
{
int V_56 ;
#define F_169 0x00
#define F_170 0xde
#define F_171 0xd0
#define F_172 0x20
#define F_173 0x5ad
memset ( V_187 , 0 , V_188 ) ;
if ( F_174 ( V_186 + F_169 ) == F_173 &&
F_174 ( V_186 + F_170 ) == F_173 ) {
F_175 ( V_187 , V_186 + F_172 , V_188 ) ;
} else {
for ( V_56 = 0 ; V_56 < 4 ; ++ V_56 )
( ( T_2 * ) V_187 ) [ V_56 ] =
F_3 ( * ( T_2 * ) ( V_186 + F_171 + V_56 * 4 ) ) ;
}
}
int F_176 ( struct V_1 * V_2 ,
struct V_189 * V_190 , T_3 * V_33 )
{
struct V_59 * V_61 ;
T_2 * V_94 ;
int V_26 ;
#define F_177 0x100
#define F_178 0x00
#define F_179 0x04
#define F_180 0x08
#define F_181 0x10
#define F_182 0x20
V_61 = F_48 ( V_2 , V_58 ) ;
if ( F_57 ( V_61 ) )
return F_58 ( V_61 ) ;
V_94 = V_61 -> V_62 ;
V_26 = F_30 ( V_2 , 0 , V_61 -> V_63 , 0 , 0 , V_191 ,
V_89 , V_33 ) ;
if ( V_26 )
goto V_36;
if ( ! F_88 ( V_2 ) ) {
F_87 ( V_190 -> V_192 , V_94 ,
F_178 ) ;
F_87 ( V_190 -> V_193 , V_94 ,
F_179 ) ;
F_87 ( V_190 -> V_194 , V_94 ,
F_180 ) ;
}
F_87 ( V_190 -> V_195 , V_94 , F_181 ) ;
F_168 ( V_94 + F_182 / 4 ,
V_190 -> V_187 ) ;
V_36:
F_51 ( V_2 , V_61 ) ;
return V_26 ;
}
int F_183 ( struct V_1 * V_2 ,
struct V_196 * V_197 ,
T_3 * V_33 )
{
struct V_59 * V_61 ;
V_38 * V_198 ;
int V_26 ;
#define F_184 0x200
#define F_185 0x00c
#define F_186 0x014
#define F_187 0x020
#define F_188 (INIT_HCA_QPC_OFFSET + 0x10)
#define F_189 (INIT_HCA_QPC_OFFSET + 0x17)
#define F_190 (INIT_HCA_QPC_OFFSET + 0x20)
#define F_191 (INIT_HCA_QPC_OFFSET + 0x27)
#define F_192 (INIT_HCA_QPC_OFFSET + 0x28)
#define F_193 (INIT_HCA_QPC_OFFSET + 0x2f)
#define F_194 (INIT_HCA_QPC_OFFSET + 0x30)
#define F_195 (INIT_HCA_QPC_OFFSET + 0x37)
#define F_196 (INIT_HCA_QPC_OFFSET + 0x40)
#define F_197 (INIT_HCA_QPC_OFFSET + 0x50)
#define F_198 (INIT_HCA_QPC_OFFSET + 0x60)
#define F_199 (INIT_HCA_QPC_OFFSET + 0x67)
#define F_200 (INIT_HCA_QPC_OFFSET + 0x70)
#define F_201 0x0b0
#define F_202 (INIT_HCA_UDAV_OFFSET + 0x0)
#define F_203 (INIT_HCA_UDAV_OFFSET + 0x4)
#define F_204 0x0c0
#define F_205 (INIT_HCA_MCAST_OFFSET + 0x00)
#define F_206 (INIT_HCA_MCAST_OFFSET + 0x12)
#define F_207 (INIT_HCA_MCAST_OFFSET + 0x16)
#define F_208 (INIT_HCA_MCAST_OFFSET + 0x1b)
#define F_209 0x0f0
#define F_210 (INIT_HCA_TPT_OFFSET + 0x00)
#define F_211 (INIT_HCA_TPT_OFFSET + 0x09)
#define F_212 (INIT_HCA_TPT_OFFSET + 0x0b)
#define F_213 (INIT_HCA_TPT_OFFSET + 0x10)
#define F_214 0x120
#define F_215 (INIT_HCA_UAR_OFFSET + 0x00)
#define F_216 (INIT_HCA_UAR_OFFSET + 0x09)
#define F_217 (INIT_HCA_UAR_OFFSET + 0x0a)
#define F_218 (INIT_HCA_UAR_OFFSET + 0x0b)
#define F_219 (INIT_HCA_UAR_OFFSET + 0x10)
#define F_220 (INIT_HCA_UAR_OFFSET + 0x18)
V_61 = F_48 ( V_2 , V_58 ) ;
if ( F_57 ( V_61 ) )
return F_58 ( V_61 ) ;
V_198 = V_61 -> V_62 ;
memset ( V_198 , 0 , F_184 ) ;
if ( V_2 -> V_117 & V_199 )
F_221 ( V_198 , 0x1 , F_185 ) ;
#if F_222 ( V_200 )
* ( V_198 + F_186 / 4 ) &= ~ F_6 ( 1 << 1 ) ;
#elif F_222 ( V_201 )
* ( V_198 + F_186 / 4 ) |= F_6 ( 1 << 1 ) ;
#else
#error Host endianness not defined
#endif
* ( V_198 + F_186 / 4 ) |= F_6 ( 1 ) ;
if ( V_2 -> V_202 & V_203 )
* ( V_198 + F_186 / 4 ) |= F_6 ( 7 << 3 ) ;
F_221 ( V_198 , V_197 -> V_204 , F_188 ) ;
F_221 ( V_198 , V_197 -> V_205 , F_189 ) ;
F_221 ( V_198 , V_197 -> V_206 , F_190 ) ;
F_221 ( V_198 , V_197 -> V_207 , F_191 ) ;
F_221 ( V_198 , V_197 -> V_208 , F_192 ) ;
F_221 ( V_198 , V_197 -> V_209 , F_193 ) ;
F_221 ( V_198 , V_197 -> V_210 , F_194 ) ;
F_221 ( V_198 , V_197 -> V_211 , F_195 ) ;
F_221 ( V_198 , V_197 -> V_212 , F_196 ) ;
F_221 ( V_198 , V_197 -> V_213 , F_197 ) ;
F_221 ( V_198 , V_197 -> V_214 , F_198 ) ;
F_221 ( V_198 , V_197 -> V_215 , F_199 ) ;
F_221 ( V_198 , V_197 -> V_216 , F_200 ) ;
F_221 ( V_198 , V_197 -> V_217 , F_205 ) ;
F_221 ( V_198 , V_197 -> V_218 , F_206 ) ;
F_221 ( V_198 , V_197 -> V_219 , F_207 ) ;
F_221 ( V_198 , V_197 -> V_220 , F_208 ) ;
F_221 ( V_198 , V_197 -> V_221 , F_210 ) ;
if ( ! F_88 ( V_2 ) )
F_221 ( V_198 , V_197 -> V_222 , F_211 ) ;
F_221 ( V_198 , V_197 -> V_223 , F_212 ) ;
F_221 ( V_198 , V_197 -> V_224 , F_213 ) ;
{
T_3 V_225 = V_108 - 12 ;
F_221 ( V_198 , V_225 , F_218 ) ;
}
F_221 ( V_198 , V_197 -> V_226 , F_219 ) ;
if ( F_88 ( V_2 ) ) {
F_221 ( V_198 , V_197 -> V_227 , F_216 ) ;
F_221 ( V_198 , V_197 -> V_228 , F_217 ) ;
F_221 ( V_198 , V_197 -> V_229 , F_220 ) ;
}
V_26 = F_31 ( V_2 , V_61 -> V_63 , 0 , 0 , V_230 , V_66 , V_33 ) ;
F_51 ( V_2 , V_61 ) ;
return V_26 ;
}
int F_223 ( struct V_1 * V_2 ,
struct V_231 * V_197 ,
int V_232 , T_3 * V_33 )
{
struct V_59 * V_61 ;
T_2 * V_198 ;
int V_26 ;
T_2 V_28 ;
#define F_224 56
#define F_225 0x00
#define F_226 (1 << 18)
#define F_227 (1 << 17)
#define F_228 (1 << 16)
#define F_229 4
#define F_230 8
#define F_231 12
#define F_232 0x06
#define F_233 0x0a
#define F_234 0x10
#define F_235 0x18
#define F_236 0x20
V_61 = F_48 ( V_2 , V_58 ) ;
if ( F_57 ( V_61 ) )
return F_58 ( V_61 ) ;
V_198 = V_61 -> V_62 ;
memset ( V_198 , 0 , F_224 ) ;
V_28 = 0 ;
V_28 |= V_197 -> V_233 ? F_228 : 0 ;
V_28 |= V_197 -> V_234 ? F_227 : 0 ;
V_28 |= V_197 -> V_235 ? F_226 : 0 ;
V_28 |= V_197 -> V_236 << F_229 ;
V_28 |= V_197 -> V_237 << F_230 ;
V_28 |= V_197 -> V_238 << F_231 ;
F_221 ( V_198 , V_28 , F_225 ) ;
F_221 ( V_198 , V_197 -> V_239 , F_232 ) ;
F_221 ( V_198 , V_197 -> V_240 , F_233 ) ;
F_221 ( V_198 , V_197 -> V_241 , F_234 ) ;
F_221 ( V_198 , V_197 -> V_242 , F_235 ) ;
F_221 ( V_198 , V_197 -> V_243 , F_236 ) ;
V_26 = F_31 ( V_2 , V_61 -> V_63 , V_232 , 0 , V_244 ,
V_89 , V_33 ) ;
F_51 ( V_2 , V_61 ) ;
return V_26 ;
}
int F_237 ( struct V_1 * V_2 , int V_232 , T_3 * V_33 )
{
return F_31 ( V_2 , 0 , V_232 , 0 , V_245 , V_89 , V_33 ) ;
}
int F_238 ( struct V_1 * V_2 , int V_246 , T_3 * V_33 )
{
return F_31 ( V_2 , 0 , 0 , V_246 , V_247 , V_69 , V_33 ) ;
}
int F_239 ( struct V_1 * V_2 , struct V_248 * V_197 ,
int V_232 , T_3 * V_33 )
{
struct V_59 * V_61 ;
T_2 * V_198 ;
int V_26 ;
T_2 V_28 = 0 ;
#define F_240 0x40
#define F_241 0x00
#define F_242 (1 << 18)
#define F_243 (1 << 0)
#define F_244 0x04
#define F_245 0x08
V_61 = F_48 ( V_2 , V_58 ) ;
if ( F_57 ( V_61 ) )
return F_58 ( V_61 ) ;
V_198 = V_61 -> V_62 ;
memset ( V_198 , 0 , F_240 ) ;
V_28 |= V_197 -> V_235 ? F_242 : 0 ;
V_28 |= V_197 -> V_249 ? F_243 : 0 ;
F_221 ( V_198 , V_28 , F_241 ) ;
F_221 ( V_198 , V_197 -> V_250 , F_244 ) ;
F_221 ( V_198 , V_197 -> V_243 , F_245 ) ;
V_26 = F_31 ( V_2 , V_61 -> V_63 , V_232 , 0 , V_251 ,
V_83 , V_33 ) ;
F_51 ( V_2 , V_61 ) ;
return V_26 ;
}
int F_246 ( struct V_1 * V_2 , struct V_70 * V_71 , T_1 V_72 , T_3 * V_33 )
{
return F_56 ( V_2 , V_86 , V_71 , V_72 , V_33 ) ;
}
int F_247 ( struct V_1 * V_2 , T_1 V_252 , T_1 V_72 , T_3 * V_33 )
{
struct V_59 * V_61 ;
T_7 * V_198 ;
int V_26 ;
V_61 = F_48 ( V_2 , V_58 ) ;
if ( F_57 ( V_61 ) )
return F_58 ( V_61 ) ;
V_198 = V_61 -> V_62 ;
V_198 [ 0 ] = F_65 ( V_72 ) ;
V_198 [ 1 ] = F_65 ( V_252 ) ;
V_26 = F_31 ( V_2 , V_61 -> V_63 , 1 , 0 , V_86 ,
V_83 , V_33 ) ;
F_51 ( V_2 , V_61 ) ;
if ( ! V_26 )
F_29 ( V_2 , L_40 ,
( unsigned long long ) V_252 , ( unsigned long long ) V_72 ) ;
return V_26 ;
}
int F_248 ( struct V_1 * V_2 , T_1 V_72 , T_2 V_253 , T_3 * V_33 )
{
F_29 ( V_2 , L_41 ,
V_253 , ( unsigned long long ) V_72 ) ;
return F_31 ( V_2 , V_72 , V_253 , 0 , V_254 , V_83 , V_33 ) ;
}
int F_249 ( struct V_1 * V_2 , struct V_70 * V_71 , T_3 * V_33 )
{
return F_56 ( V_2 , V_85 , V_71 , - 1 , V_33 ) ;
}
int F_250 ( struct V_1 * V_2 , T_3 * V_33 )
{
return F_31 ( V_2 , 0 , 0 , 0 , V_255 , V_83 , V_33 ) ;
}
int F_251 ( struct V_1 * V_2 , T_1 V_256 , T_1 * V_257 ,
T_3 * V_33 )
{
int V_64 = F_32 ( V_2 , V_256 , V_257 , 0 , 0 , V_258 ,
V_89 , V_33 ) ;
if ( V_64 || V_33 )
return V_64 ;
* V_257 = F_89 ( * V_257 , V_107 / V_81 ) >>
( V_108 - V_80 ) ;
return 0 ;
}
int F_252 ( struct V_1 * V_2 , struct V_59 * V_61 ,
int V_259 , T_3 * V_33 )
{
return F_31 ( V_2 , V_61 -> V_63 , V_259 , 0 , V_260 ,
V_83 , V_33 ) ;
}
int F_253 ( struct V_1 * V_2 , struct V_59 * V_61 ,
int V_259 , T_3 * V_33 )
{
return F_30 ( V_2 , 0 , V_61 ? V_61 -> V_63 : 0 , V_259 ,
! V_61 , V_261 ,
V_83 , V_33 ) ;
}
int F_254 ( struct V_1 * V_2 , struct V_59 * V_61 ,
int V_262 , T_3 * V_33 )
{
return F_31 ( V_2 , V_61 -> V_63 , V_262 , 0 , V_263 ,
V_83 , V_33 ) ;
}
int F_255 ( struct V_1 * V_2 , T_3 * V_33 )
{
return F_31 ( V_2 , 0 , 0 , 0 , V_264 , V_83 , V_33 ) ;
}
int F_256 ( struct V_1 * V_2 , T_1 V_265 , int V_266 ,
int V_267 , T_3 * V_33 )
{
F_29 ( V_2 , L_42 ,
V_266 ? L_43 : L_44 ,
( unsigned long long ) V_265 , V_267 ) ;
return F_31 ( V_2 , V_265 , ( V_266 << 31 ) | V_267 ,
0 , V_268 , V_83 , V_33 ) ;
}
int F_257 ( struct V_1 * V_2 , struct V_59 * V_61 ,
int V_267 , T_3 * V_33 )
{
return F_31 ( V_2 , V_61 -> V_63 , V_267 , 0 , V_269 ,
V_89 , V_33 ) ;
}
int F_258 ( struct V_1 * V_2 , struct V_59 * V_61 ,
int V_267 , T_3 * V_33 )
{
return F_30 ( V_2 , 0 , V_61 -> V_63 , V_267 , 0 ,
V_270 ,
V_89 , V_33 ) ;
}
int F_259 ( struct V_1 * V_2 , struct V_59 * V_61 ,
int V_271 , T_3 * V_33 )
{
return F_31 ( V_2 , V_61 -> V_63 , V_271 , 0 , V_272 ,
V_89 , V_33 ) ;
}
int F_260 ( struct V_1 * V_2 , struct V_59 * V_61 ,
int V_271 , T_3 * V_33 )
{
return F_30 ( V_2 , 0 , V_61 -> V_63 , V_271 , 0 ,
V_273 ,
V_89 , V_33 ) ;
}
int F_261 ( struct V_1 * V_2 , int V_271 , T_2 V_274 , T_3 V_275 ,
T_3 * V_33 )
{
struct V_59 * V_61 ;
V_38 * V_198 ;
int V_26 ;
#define F_262 0x40
#define F_263 0x0c
#define F_264 0x1c
V_61 = F_48 ( V_2 , V_58 ) ;
if ( F_57 ( V_61 ) )
return F_58 ( V_61 ) ;
V_198 = V_61 -> V_62 ;
memset ( V_198 , 0 , F_262 ) ;
F_221 ( V_198 , V_275 , F_263 ) ;
F_221 ( V_198 , V_274 , F_264 ) ;
V_26 = F_31 ( V_2 , V_61 -> V_63 , V_271 , 1 , V_276 ,
V_83 , V_33 ) ;
F_51 ( V_2 , V_61 ) ;
return V_26 ;
}
int F_265 ( struct V_1 * V_2 , struct V_59 * V_61 ,
int V_277 , T_3 * V_33 )
{
return F_31 ( V_2 , V_61 -> V_63 , V_277 , 0 , V_278 ,
V_89 , V_33 ) ;
}
int F_266 ( struct V_1 * V_2 , struct V_59 * V_61 ,
int V_277 , T_3 * V_33 )
{
return F_30 ( V_2 , 0 , V_61 -> V_63 , V_277 , 0 ,
V_279 ,
V_89 , V_33 ) ;
}
int F_267 ( struct V_1 * V_2 , T_2 V_280 ,
struct V_59 * V_61 , T_3 * V_33 )
{
return F_30 ( V_2 , 0 , V_61 -> V_63 , V_280 , 0 ,
V_281 , V_89 , V_33 ) ;
}
int F_268 ( struct V_1 * V_2 , int V_277 , int V_282 , T_3 * V_33 )
{
return F_31 ( V_2 , V_282 , V_277 , 0 , V_283 ,
V_83 , V_33 ) ;
}
int F_269 ( struct V_1 * V_2 , enum V_284 V_285 ,
enum V_284 V_48 , T_2 V_280 , int V_286 ,
struct V_59 * V_61 , T_2 V_287 ,
T_3 * V_33 )
{
static const T_4 V_10 [ V_288 + 1 ] [ V_288 + 1 ] = {
[ V_289 ] = {
[ V_289 ] = V_290 ,
[ V_288 ] = V_291 ,
[ V_292 ] = V_293 ,
} ,
[ V_292 ] = {
[ V_289 ] = V_290 ,
[ V_288 ] = V_291 ,
[ V_292 ] = V_294 ,
[ V_295 ] = V_296 ,
} ,
[ V_295 ] = {
[ V_289 ] = V_290 ,
[ V_288 ] = V_291 ,
[ V_297 ] = V_298 ,
} ,
[ V_297 ] = {
[ V_289 ] = V_290 ,
[ V_288 ] = V_291 ,
[ V_297 ] = V_299 ,
[ V_300 ] = V_301 ,
} ,
[ V_300 ] = {
[ V_289 ] = V_290 ,
[ V_288 ] = V_291 ,
[ V_297 ] = V_302 ,
[ V_300 ] = V_303 ,
} ,
[ V_304 ] = {
[ V_289 ] = V_290 ,
[ V_288 ] = V_291 ,
[ V_297 ] = V_305 ,
} ,
[ V_288 ] = {
[ V_289 ] = V_290 ,
[ V_288 ] = V_291 ,
}
} ;
T_3 V_306 = 0 ;
int V_307 = 0 ;
int V_26 ;
if ( V_10 [ V_285 ] [ V_48 ] == V_290 ) {
V_306 = 3 ;
if ( ! V_61 ) {
V_61 = F_48 ( V_2 , V_58 ) ;
if ( ! F_57 ( V_61 ) ) {
V_307 = 1 ;
V_306 = 2 ;
} else
V_61 = NULL ;
}
V_26 = F_30 ( V_2 , 0 , V_61 ? V_61 -> V_63 : 0 ,
( ! ! V_286 << 24 ) | V_280 , V_306 ,
V_10 [ V_285 ] [ V_48 ] , V_69 , V_33 ) ;
if ( 0 && V_61 ) {
int V_56 ;
F_29 ( V_2 , L_45 ) ;
F_270 ( L_46 , F_271 ( V_61 -> V_62 ) ) ;
for ( V_56 = 0 ; V_56 < 0x100 / 4 ; ++ V_56 ) {
if ( V_56 % 8 == 0 )
F_270 ( L_47 , V_56 * 4 ) ;
F_270 ( L_48 ,
F_18 ( ( ( V_38 * ) V_61 -> V_62 ) [ V_56 + 2 ] ) ) ;
if ( ( V_56 + 1 ) % 8 == 0 )
F_270 ( L_49 ) ;
}
}
if ( V_307 )
F_51 ( V_2 , V_61 ) ;
} else {
if ( 0 ) {
int V_56 ;
F_29 ( V_2 , L_45 ) ;
F_270 ( L_50 , F_271 ( V_61 -> V_62 ) ) ;
for ( V_56 = 0 ; V_56 < 0x100 / 4 ; ++ V_56 ) {
if ( V_56 % 8 == 0 )
F_270 ( L_51 , V_56 * 4 ) ;
F_270 ( L_48 ,
F_18 ( ( ( V_38 * ) V_61 -> V_62 ) [ V_56 + 2 ] ) ) ;
if ( ( V_56 + 1 ) % 8 == 0 )
F_270 ( L_49 ) ;
}
}
V_26 = F_31 ( V_2 , V_61 -> V_63 , V_287 | ( ! ! V_286 << 24 ) | V_280 ,
V_306 , V_10 [ V_285 ] [ V_48 ] , V_69 , V_33 ) ;
}
return V_26 ;
}
int F_272 ( struct V_1 * V_2 , T_2 V_280 , int V_286 ,
struct V_59 * V_61 , T_3 * V_33 )
{
return F_30 ( V_2 , 0 , V_61 -> V_63 , ( ! ! V_286 << 24 ) | V_280 , 0 ,
V_308 , V_89 , V_33 ) ;
}
int F_273 ( struct V_1 * V_2 , int type , T_2 V_309 ,
T_3 * V_33 )
{
T_3 V_306 ;
switch ( type ) {
case V_310 :
V_306 = 0 ;
break;
case V_311 :
V_306 = 1 ;
break;
case V_312 :
V_306 = 2 ;
break;
case V_313 :
V_306 = 3 ;
break;
default:
return - V_82 ;
}
return F_31 ( V_2 , 0 , V_309 , V_306 , V_314 ,
V_83 , V_33 ) ;
}
int F_274 ( struct V_1 * V_2 , int V_315 , int V_316 ,
int V_232 , struct V_317 * V_318 , struct V_319 * V_320 ,
void * V_321 , void * V_322 , T_3 * V_33 )
{
struct V_59 * V_323 , * V_324 ;
void * V_198 ;
int V_26 ;
T_2 V_8 = V_232 ;
T_3 V_9 = 0 ;
#define F_275 0x400
#define F_276 0x100
#define F_277 0x108
#define F_278 0x10c
#define F_279 0x10d
#define F_280 0x10e
#define F_281 0x112
#define F_282 0x140
V_323 = F_48 ( V_2 , V_58 ) ;
if ( F_57 ( V_323 ) )
return F_58 ( V_323 ) ;
V_198 = V_323 -> V_62 ;
V_324 = F_48 ( V_2 , V_58 ) ;
if ( F_57 ( V_324 ) ) {
F_51 ( V_2 , V_323 ) ;
return F_58 ( V_324 ) ;
}
memcpy ( V_198 , V_321 , 256 ) ;
if ( V_315 || ! V_318 )
V_9 |= 0x1 ;
if ( V_316 || ! V_318 )
V_9 |= 0x2 ;
if ( V_318 ) {
T_3 V_325 ;
memset ( V_198 + 256 , 0 , 256 ) ;
F_221 ( V_198 , V_318 -> V_326 -> V_327 , F_276 ) ;
F_221 ( V_198 , V_318 -> V_328 , F_277 ) ;
V_325 = V_318 -> V_329 << 4 ;
F_221 ( V_198 , V_325 , F_278 ) ;
V_325 = V_318 -> V_330 |
( V_318 -> V_331 & V_332 ? 0x80 : 0 ) ;
F_221 ( V_198 , V_325 , F_279 ) ;
F_221 ( V_198 , V_318 -> V_333 , F_280 ) ;
F_221 ( V_198 , V_318 -> V_334 , F_281 ) ;
if ( V_320 )
memcpy ( V_198 + F_282 , V_320 , 40 ) ;
V_9 |= 0x4 ;
V_8 |= V_318 -> V_333 << 16 ;
}
V_26 = F_30 ( V_2 , V_323 -> V_63 , V_324 -> V_63 ,
V_8 , V_9 ,
V_335 , V_69 , V_33 ) ;
if ( ! V_26 && ! * V_33 )
memcpy ( V_322 , V_324 -> V_62 , 256 ) ;
F_51 ( V_2 , V_323 ) ;
F_51 ( V_2 , V_324 ) ;
return V_26 ;
}
int F_283 ( struct V_1 * V_2 , int V_336 ,
struct V_59 * V_61 , T_3 * V_33 )
{
return F_30 ( V_2 , 0 , V_61 -> V_63 , V_336 , 0 ,
V_337 , V_89 , V_33 ) ;
}
int F_284 ( struct V_1 * V_2 , int V_336 ,
struct V_59 * V_61 , T_3 * V_33 )
{
return F_31 ( V_2 , V_61 -> V_63 , V_336 , 0 , V_338 ,
V_89 , V_33 ) ;
}
int F_285 ( struct V_1 * V_2 , struct V_59 * V_61 ,
T_4 * V_339 , T_3 * V_33 )
{
T_1 V_340 ;
int V_26 ;
V_26 = F_32 ( V_2 , V_61 -> V_63 , & V_340 , 0 , 0 , V_341 ,
V_89 , V_33 ) ;
* V_339 = V_340 ;
return V_26 ;
}
int F_286 ( struct V_1 * V_2 , T_3 * V_33 )
{
return F_31 ( V_2 , 0 , 0x1f , 0 , V_342 , F_287 ( 100 ) , V_33 ) ;
}
