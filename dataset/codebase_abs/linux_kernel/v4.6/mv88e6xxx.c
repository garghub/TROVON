static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_3 ( ! F_4 ( & V_4 -> V_5 ) ) ) {
F_5 ( V_2 -> V_6 , L_1 ) ;
F_6 () ;
}
}
static int F_7 ( struct V_7 * V_8 , int V_9 )
{
int V_10 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ ) {
V_10 = F_8 ( V_8 , V_9 , V_12 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( ( V_10 & V_13 ) == 0 )
return 0 ;
}
return - V_14 ;
}
static int F_9 ( struct V_7 * V_8 , int V_9 , int V_15 ,
int V_16 )
{
int V_10 ;
if ( V_9 == 0 )
return F_8 ( V_8 , V_15 , V_16 ) ;
V_10 = F_7 ( V_8 , V_9 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_10 ( V_8 , V_9 , V_12 ,
V_17 | ( V_15 << 5 ) | V_16 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_7 ( V_8 , V_9 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_8 ( V_8 , V_9 , V_18 ) ;
if ( V_10 < 0 )
return V_10 ;
return V_10 & 0xffff ;
}
static int F_11 ( struct V_1 * V_2 , int V_15 , int V_16 )
{
struct V_7 * V_8 = F_12 ( V_2 -> V_6 ) ;
int V_10 ;
F_1 ( V_2 ) ;
if ( V_8 == NULL )
return - V_19 ;
V_10 = F_9 ( V_8 , V_2 -> V_20 -> V_9 , V_15 , V_16 ) ;
if ( V_10 < 0 )
return V_10 ;
F_13 ( V_2 -> V_6 , L_2 ,
V_15 , V_16 , V_10 ) ;
return V_10 ;
}
int F_14 ( struct V_1 * V_2 , int V_15 , int V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_10 ;
F_15 ( & V_4 -> V_5 ) ;
V_10 = F_11 ( V_2 , V_15 , V_16 ) ;
F_16 ( & V_4 -> V_5 ) ;
return V_10 ;
}
static int F_17 ( struct V_7 * V_8 , int V_9 , int V_15 ,
int V_16 , T_1 V_21 )
{
int V_10 ;
if ( V_9 == 0 )
return F_10 ( V_8 , V_15 , V_16 , V_21 ) ;
V_10 = F_7 ( V_8 , V_9 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_10 ( V_8 , V_9 , V_18 , V_21 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_10 ( V_8 , V_9 , V_12 ,
V_22 | ( V_15 << 5 ) | V_16 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_7 ( V_8 , V_9 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , int V_15 , int V_16 ,
T_1 V_21 )
{
struct V_7 * V_8 = F_12 ( V_2 -> V_6 ) ;
F_1 ( V_2 ) ;
if ( V_8 == NULL )
return - V_19 ;
F_13 ( V_2 -> V_6 , L_3 ,
V_15 , V_16 , V_21 ) ;
return F_17 ( V_8 , V_2 -> V_20 -> V_9 , V_15 , V_16 , V_21 ) ;
}
int F_19 ( struct V_1 * V_2 , int V_15 , int V_16 , T_1 V_21 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_10 ;
F_15 ( & V_4 -> V_5 ) ;
V_10 = F_18 ( V_2 , V_15 , V_16 , V_21 ) ;
F_16 ( & V_4 -> V_5 ) ;
return V_10 ;
}
int F_20 ( struct V_1 * V_2 , T_2 * V_15 )
{
F_21 ( V_23 , V_24 , ( V_15 [ 0 ] << 8 ) | V_15 [ 1 ] ) ;
F_21 ( V_23 , V_25 , ( V_15 [ 2 ] << 8 ) | V_15 [ 3 ] ) ;
F_21 ( V_23 , V_26 , ( V_15 [ 4 ] << 8 ) | V_15 [ 5 ] ) ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 , T_2 * V_15 )
{
int V_11 ;
int V_10 ;
for ( V_11 = 0 ; V_11 < 6 ; V_11 ++ ) {
int V_27 ;
F_21 ( V_28 , V_29 ,
V_30 | ( V_11 << 8 ) | V_15 [ V_11 ] ) ;
for ( V_27 = 0 ; V_27 < 16 ; V_27 ++ ) {
V_10 = F_23 ( V_28 , V_29 ) ;
if ( ( V_10 & V_30 ) == 0 )
break;
}
if ( V_27 == 16 )
return - V_14 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , int V_15 , int V_31 )
{
if ( V_15 >= 0 )
return F_11 ( V_2 , V_15 , V_31 ) ;
return 0xffff ;
}
static int F_25 ( struct V_1 * V_2 , int V_15 , int V_31 ,
T_1 V_21 )
{
if ( V_15 >= 0 )
return F_18 ( V_2 , V_15 , V_31 , V_21 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_10 ;
unsigned long V_32 ;
V_10 = F_23 ( V_23 , V_33 ) ;
F_21 ( V_23 , V_33 ,
V_10 & ~ V_34 ) ;
V_32 = V_35 + 1 * V_36 ;
while ( F_27 ( V_35 , V_32 ) ) {
V_10 = F_23 ( V_23 , V_37 ) ;
F_28 ( 1000 , 2000 ) ;
if ( ( V_10 & V_38 ) !=
V_39 )
return 0 ;
}
return - V_14 ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_10 ;
unsigned long V_32 ;
V_10 = F_23 ( V_23 , V_33 ) ;
F_21 ( V_23 , V_33 , V_10 | V_34 ) ;
V_32 = V_35 + 1 * V_36 ;
while ( F_27 ( V_35 , V_32 ) ) {
V_10 = F_23 ( V_23 , V_37 ) ;
F_28 ( 1000 , 2000 ) ;
if ( ( V_10 & V_38 ) ==
V_39 )
return 0 ;
}
return - V_14 ;
}
static void F_30 ( struct V_40 * V_41 )
{
struct V_3 * V_4 ;
V_4 = F_31 ( V_41 , struct V_3 , V_42 ) ;
if ( F_32 ( & V_4 -> V_43 ) ) {
struct V_1 * V_2 = ( (struct V_1 * ) V_4 ) - 1 ;
if ( F_29 ( V_2 ) == 0 )
V_4 -> V_44 = 0 ;
F_16 ( & V_4 -> V_43 ) ;
}
}
static void F_33 ( unsigned long V_45 )
{
struct V_3 * V_4 = ( void * ) V_45 ;
F_34 ( & V_4 -> V_42 ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_10 ;
F_15 ( & V_4 -> V_43 ) ;
if ( ! V_4 -> V_44 ) {
V_10 = F_26 ( V_2 ) ;
if ( V_10 < 0 ) {
F_16 ( & V_4 -> V_43 ) ;
return V_10 ;
}
V_4 -> V_44 = 1 ;
} else {
F_36 ( & V_4 -> V_46 ) ;
V_10 = 0 ;
}
return V_10 ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_38 ( & V_4 -> V_46 , V_35 + F_39 ( 10 ) ) ;
F_16 ( & V_4 -> V_43 ) ;
}
void F_40 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_41 ( & V_4 -> V_43 ) ;
F_42 ( & V_4 -> V_42 , F_30 ) ;
F_43 ( & V_4 -> V_46 ) ;
V_4 -> V_46 . V_47 = ( unsigned long ) V_4 ;
V_4 -> V_46 . V_48 = F_33 ;
}
int F_44 ( struct V_1 * V_2 , int V_15 , int V_31 )
{
int V_10 ;
V_10 = F_35 ( V_2 ) ;
if ( V_10 >= 0 ) {
V_10 = F_14 ( V_2 , V_15 , V_31 ) ;
F_37 ( V_2 ) ;
}
return V_10 ;
}
int F_45 ( struct V_1 * V_2 , int V_15 ,
int V_31 , T_1 V_21 )
{
int V_10 ;
V_10 = F_35 ( V_2 ) ;
if ( V_10 >= 0 ) {
V_10 = F_19 ( V_2 , V_15 , V_31 , V_21 ) ;
F_37 ( V_2 ) ;
}
return V_10 ;
}
static bool F_46 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_4 -> V_49 ) {
case V_50 :
case V_51 :
case V_52 :
case V_53 :
return true ;
}
return false ;
}
static bool F_47 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_4 -> V_49 ) {
case V_54 :
case V_55 :
return true ;
}
return false ;
}
static bool F_48 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_4 -> V_49 ) {
case V_56 :
case V_57 :
case V_58 :
case V_59 :
return true ;
}
return false ;
}
static bool F_49 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_4 -> V_49 ) {
case V_60 :
case V_61 :
case V_62 :
return true ;
}
return false ;
}
static bool F_50 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_4 -> V_49 ) {
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
return true ;
}
return false ;
}
static bool F_51 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_4 -> V_49 ) {
case V_71 :
case V_72 :
return true ;
}
return false ;
}
static bool F_52 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_4 -> V_49 ) {
case V_73 :
case V_74 :
case V_75 :
case V_76 :
return true ;
}
return false ;
}
static bool F_53 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_4 -> V_49 ) {
case V_77 :
case V_78 :
case V_79 :
case V_80 :
return true ;
}
return false ;
}
void F_54 ( struct V_1 * V_2 , int V_81 ,
struct V_82 * V_83 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_3 V_16 ;
int V_10 ;
if ( ! F_55 ( V_83 ) )
return;
F_15 ( & V_4 -> V_5 ) ;
V_10 = F_11 ( V_2 , F_56 ( V_81 ) , V_84 ) ;
if ( V_10 < 0 )
goto V_85;
V_16 = V_10 & ~ ( V_86 |
V_87 |
V_88 |
V_89 |
V_90 ) ;
V_16 |= V_87 ;
if ( V_83 -> V_91 )
V_16 |= V_86 ;
if ( F_46 ( V_2 ) && V_83 -> V_92 > V_93 )
goto V_85;
switch ( V_83 -> V_92 ) {
case V_94 :
V_16 |= V_95 ;
break;
case V_93 :
V_16 |= V_96 ;
break;
case V_97 :
V_16 |= V_98 ;
break;
default:
F_57 ( L_4 ) ;
goto V_85;
}
V_16 |= V_89 ;
if ( V_83 -> V_99 == V_100 )
V_16 |= V_88 ;
if ( ( F_53 ( V_2 ) || F_52 ( V_2 ) ) &&
( V_81 >= V_4 -> V_101 - 2 ) ) {
if ( V_83 -> V_102 == V_103 )
V_16 |= V_104 ;
if ( V_83 -> V_102 == V_105 )
V_16 |= V_106 ;
if ( V_83 -> V_102 == V_107 )
V_16 |= ( V_104 |
V_106 ) ;
}
F_18 ( V_2 , F_56 ( V_81 ) , V_84 , V_16 ) ;
V_85:
F_16 ( & V_4 -> V_5 ) ;
}
static int F_58 ( struct V_1 * V_2 )
{
int V_10 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < 10 ; V_11 ++ ) {
V_10 = F_11 ( V_2 , V_23 , V_108 ) ;
if ( ( V_10 & V_109 ) == 0 )
return 0 ;
}
return - V_14 ;
}
static int F_59 ( struct V_1 * V_2 , int V_81 )
{
int V_10 ;
if ( F_51 ( V_2 ) || F_53 ( V_2 ) )
V_81 = ( V_81 + 1 ) << 5 ;
V_10 = F_18 ( V_2 , V_23 , V_108 ,
V_110 |
V_111 | V_81 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_58 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
static void F_60 ( struct V_1 * V_2 , int V_112 , T_3 * V_21 )
{
T_3 V_113 ;
int V_10 ;
* V_21 = 0 ;
V_10 = F_18 ( V_2 , V_23 , V_108 ,
V_114 |
V_111 | V_112 ) ;
if ( V_10 < 0 )
return;
V_10 = F_58 ( V_2 ) ;
if ( V_10 < 0 )
return;
V_10 = F_11 ( V_2 , V_23 , V_115 ) ;
if ( V_10 < 0 )
return;
V_113 = V_10 << 16 ;
V_10 = F_11 ( V_2 , V_23 , V_116 ) ;
if ( V_10 < 0 )
return;
* V_21 = V_113 | V_10 ;
}
static bool F_61 ( struct V_1 * V_2 ,
struct V_117 * V_112 )
{
switch ( V_112 -> type ) {
case V_118 :
return true ;
case V_119 :
return F_51 ( V_2 ) ;
case V_120 :
return F_47 ( V_2 ) ||
F_50 ( V_2 ) ||
F_48 ( V_2 ) ||
F_49 ( V_2 ) ||
F_52 ( V_2 ) ||
F_53 ( V_2 ) ;
}
return false ;
}
static T_4 F_62 ( struct V_1 * V_2 ,
struct V_117 * V_121 ,
int V_81 )
{
T_3 V_122 ;
T_3 V_123 = 0 ;
int V_10 ;
T_5 V_124 ;
switch ( V_121 -> type ) {
case V_120 :
V_10 = F_11 ( V_2 , F_56 ( V_81 ) , V_121 -> V_16 ) ;
if ( V_10 < 0 )
return V_125 ;
V_122 = V_10 ;
if ( V_121 -> V_126 == 4 ) {
V_10 = F_11 ( V_2 , F_56 ( V_81 ) ,
V_121 -> V_16 + 1 ) ;
if ( V_10 < 0 )
return V_125 ;
V_123 = V_10 ;
}
break;
case V_118 :
case V_119 :
F_60 ( V_2 , V_121 -> V_16 , & V_122 ) ;
if ( V_121 -> V_126 == 8 )
F_60 ( V_2 , V_121 -> V_16 + 1 , & V_123 ) ;
}
V_124 = ( ( ( T_5 ) V_123 ) << 16 ) | V_122 ;
return V_124 ;
}
void F_63 ( struct V_1 * V_2 , int V_81 , T_6 * V_47 )
{
struct V_117 * V_112 ;
int V_11 , V_27 ;
for ( V_11 = 0 , V_27 = 0 ; V_11 < F_64 ( V_127 ) ; V_11 ++ ) {
V_112 = & V_127 [ V_11 ] ;
if ( F_61 ( V_2 , V_112 ) ) {
memcpy ( V_47 + V_27 * V_128 , V_112 -> string ,
V_128 ) ;
V_27 ++ ;
}
}
}
int F_65 ( struct V_1 * V_2 )
{
struct V_117 * V_112 ;
int V_11 , V_27 ;
for ( V_11 = 0 , V_27 = 0 ; V_11 < F_64 ( V_127 ) ; V_11 ++ ) {
V_112 = & V_127 [ V_11 ] ;
if ( F_61 ( V_2 , V_112 ) )
V_27 ++ ;
}
return V_27 ;
}
void
F_66 ( struct V_1 * V_2 ,
int V_81 , T_4 * V_47 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_117 * V_112 ;
int V_10 ;
int V_11 , V_27 ;
F_15 ( & V_4 -> V_5 ) ;
V_10 = F_59 ( V_2 , V_81 ) ;
if ( V_10 < 0 ) {
F_16 ( & V_4 -> V_5 ) ;
return;
}
for ( V_11 = 0 , V_27 = 0 ; V_11 < F_64 ( V_127 ) ; V_11 ++ ) {
V_112 = & V_127 [ V_11 ] ;
if ( F_61 ( V_2 , V_112 ) ) {
V_47 [ V_27 ] = F_62 ( V_2 , V_112 , V_81 ) ;
V_27 ++ ;
}
}
F_16 ( & V_4 -> V_5 ) ;
}
int F_67 ( struct V_1 * V_2 , int V_81 )
{
return 32 * sizeof( T_1 ) ;
}
void F_68 ( struct V_1 * V_2 , int V_81 ,
struct V_129 * V_130 , void * V_131 )
{
T_1 * V_132 = V_131 ;
int V_11 ;
V_130 -> V_133 = 0 ;
memset ( V_132 , 0xff , 32 * sizeof( T_1 ) ) ;
for ( V_11 = 0 ; V_11 < 32 ; V_11 ++ ) {
int V_10 ;
V_10 = F_14 ( V_2 , F_56 ( V_81 ) , V_11 ) ;
if ( V_10 >= 0 )
V_132 [ V_11 ] = V_10 ;
}
}
static int F_69 ( struct V_1 * V_2 , int V_16 , int V_134 ,
T_1 V_135 )
{
unsigned long V_32 = V_35 + V_36 / 10 ;
while ( F_27 ( V_35 , V_32 ) ) {
int V_10 ;
V_10 = F_11 ( V_2 , V_16 , V_134 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( ! ( V_10 & V_135 ) )
return 0 ;
F_28 ( 1000 , 2000 ) ;
}
return - V_14 ;
}
static int F_70 ( struct V_1 * V_2 , int V_16 , int V_134 , T_1 V_135 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_10 ;
F_15 ( & V_4 -> V_5 ) ;
V_10 = F_69 ( V_2 , V_16 , V_134 , V_135 ) ;
F_16 ( & V_4 -> V_5 ) ;
return V_10 ;
}
static int F_71 ( struct V_1 * V_2 )
{
return F_69 ( V_2 , V_28 , V_136 ,
V_137 ) ;
}
int F_72 ( struct V_1 * V_2 )
{
return F_70 ( V_2 , V_28 , V_138 ,
V_139 ) ;
}
int F_73 ( struct V_1 * V_2 )
{
return F_70 ( V_2 , V_28 , V_138 ,
V_140 ) ;
}
static int F_74 ( struct V_1 * V_2 )
{
return F_69 ( V_2 , V_23 , V_141 ,
V_142 ) ;
}
static int F_75 ( struct V_1 * V_2 , int V_15 ,
int V_31 )
{
int V_10 ;
V_10 = F_18 ( V_2 , V_28 , V_136 ,
V_143 | ( V_15 << 5 ) |
V_31 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_71 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
return F_11 ( V_2 , V_28 , V_144 ) ;
}
static int F_76 ( struct V_1 * V_2 , int V_15 ,
int V_31 , T_1 V_21 )
{
int V_10 ;
V_10 = F_18 ( V_2 , V_28 , V_144 , V_21 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_18 ( V_2 , V_28 , V_136 ,
V_145 | ( V_15 << 5 ) |
V_31 ) ;
return F_71 ( V_2 ) ;
}
int F_77 ( struct V_1 * V_2 , int V_81 , struct V_146 * V_147 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_16 ;
F_15 ( & V_4 -> V_5 ) ;
V_16 = F_75 ( V_2 , V_81 , 16 ) ;
if ( V_16 < 0 )
goto V_85;
V_147 -> V_148 = ! ! ( V_16 & 0x0200 ) ;
V_147 -> V_149 = ! ! ( V_16 & 0x0100 ) ;
V_16 = F_11 ( V_2 , F_56 ( V_81 ) , V_150 ) ;
if ( V_16 < 0 )
goto V_85;
V_147 -> V_151 = ! ! ( V_16 & V_152 ) ;
V_16 = 0 ;
V_85:
F_16 ( & V_4 -> V_5 ) ;
return V_16 ;
}
int F_78 ( struct V_1 * V_2 , int V_81 ,
struct V_82 * V_83 , struct V_146 * V_147 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_16 ;
int V_10 ;
F_15 ( & V_4 -> V_5 ) ;
V_10 = F_75 ( V_2 , V_81 , 16 ) ;
if ( V_10 < 0 )
goto V_85;
V_16 = V_10 & ~ 0x0300 ;
if ( V_147 -> V_148 )
V_16 |= 0x0200 ;
if ( V_147 -> V_149 )
V_16 |= 0x0100 ;
V_10 = F_76 ( V_2 , V_81 , 16 , V_16 ) ;
V_85:
F_16 ( & V_4 -> V_5 ) ;
return V_10 ;
}
static int F_79 ( struct V_1 * V_2 , T_1 V_153 )
{
int V_10 ;
V_10 = F_18 ( V_2 , V_23 , V_141 , V_153 ) ;
if ( V_10 < 0 )
return V_10 ;
return F_74 ( V_2 ) ;
}
static int F_80 ( struct V_1 * V_2 ,
struct V_154 * V_155 )
{
T_1 V_47 = V_155 -> V_156 & V_157 ;
if ( V_155 -> V_156 != V_158 ) {
unsigned int V_135 , V_159 ;
if ( V_155 -> V_160 ) {
V_47 |= V_161 ;
V_135 = V_162 ;
V_159 = V_163 ;
} else {
V_135 = V_164 ;
V_159 = V_165 ;
}
V_47 |= ( V_155 -> V_166 << V_159 ) & V_135 ;
}
return F_18 ( V_2 , V_23 , V_167 , V_47 ) ;
}
static int F_81 ( struct V_1 * V_2 ,
struct V_154 * V_155 ,
bool V_168 )
{
int V_169 ;
int V_170 ;
V_170 = F_74 ( V_2 ) ;
if ( V_170 )
return V_170 ;
V_170 = F_80 ( V_2 , V_155 ) ;
if ( V_170 )
return V_170 ;
if ( V_155 -> V_171 ) {
V_170 = F_18 ( V_2 , V_23 , V_172 ,
V_155 -> V_171 ) ;
if ( V_170 )
return V_170 ;
V_169 = V_168 ? V_173 :
V_174 ;
} else {
V_169 = V_168 ? V_175 :
V_176 ;
}
return F_79 ( V_2 , V_169 ) ;
}
static int F_82 ( struct V_1 * V_2 , T_1 V_171 , bool V_168 )
{
struct V_154 V_155 = {
. V_171 = V_171 ,
. V_156 = 0 ,
} ;
return F_81 ( V_2 , & V_155 , V_168 ) ;
}
static int F_83 ( struct V_1 * V_2 , T_1 V_171 , int V_177 ,
int V_178 , bool V_168 )
{
struct V_154 V_155 = {
. V_160 = false ,
. V_171 = V_171 ,
} ;
V_155 . V_156 = V_157 ;
V_155 . V_166 = ( V_178 & 0x0f ) << 4 ;
V_155 . V_166 |= V_177 & 0x0f ;
return F_81 ( V_2 , & V_155 , V_168 ) ;
}
static int F_84 ( struct V_1 * V_2 , T_1 V_171 , int V_81 ,
bool V_168 )
{
return F_83 ( V_2 , V_171 , V_81 , 0x0f , V_168 ) ;
}
static int F_85 ( struct V_1 * V_2 , int V_81 , T_2 V_156 )
{
int V_16 , V_10 = 0 ;
T_2 V_179 ;
V_16 = F_11 ( V_2 , F_56 ( V_81 ) , V_180 ) ;
if ( V_16 < 0 )
return V_16 ;
V_179 = V_16 & V_181 ;
if ( V_179 != V_156 ) {
if ( ( V_179 == V_182 ||
V_179 == V_183 )
&& ( V_156 == V_184 ||
V_156 == V_185 ) ) {
V_10 = F_84 ( V_2 , 0 , V_81 , false ) ;
if ( V_10 )
return V_10 ;
}
V_16 = ( V_16 & ~ V_181 ) | V_156 ;
V_10 = F_18 ( V_2 , F_56 ( V_81 ) , V_180 ,
V_16 ) ;
if ( V_10 )
return V_10 ;
F_86 ( V_2 -> V_186 [ V_81 ] , L_5 ,
V_187 [ V_156 ] ,
V_187 [ V_179 ] ) ;
}
return V_10 ;
}
static int F_87 ( struct V_1 * V_2 , int V_81 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_188 * V_189 = V_4 -> V_186 [ V_81 ] . V_190 ;
const T_1 V_135 = ( 1 << V_4 -> V_101 ) - 1 ;
T_1 V_191 = 0 ;
int V_16 ;
int V_11 ;
if ( F_88 ( V_2 , V_81 ) || F_89 ( V_2 , V_81 ) ) {
V_191 = V_135 ;
} else {
for ( V_11 = 0 ; V_11 < V_4 -> V_101 ; ++ V_11 ) {
if ( V_189 && V_4 -> V_186 [ V_11 ] . V_190 == V_189 )
V_191 |= F_90 ( V_11 ) ;
if ( F_88 ( V_2 , V_11 ) || F_89 ( V_2 , V_11 ) )
V_191 |= F_90 ( V_11 ) ;
}
}
V_191 &= ~ F_90 ( V_81 ) ;
V_16 = F_11 ( V_2 , F_56 ( V_81 ) , V_192 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 &= ~ V_135 ;
V_16 |= V_191 & V_135 ;
return F_18 ( V_2 , F_56 ( V_81 ) , V_192 , V_16 ) ;
}
int F_91 ( struct V_1 * V_2 , int V_81 , T_2 V_156 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_193 ;
switch ( V_156 ) {
case V_194 :
V_193 = V_184 ;
break;
case V_195 :
case V_196 :
V_193 = V_185 ;
break;
case V_197 :
V_193 = V_182 ;
break;
case V_198 :
default:
V_193 = V_183 ;
break;
}
V_4 -> V_186 [ V_81 ] . V_156 = V_193 ;
F_92 ( V_81 , V_4 -> V_199 ) ;
F_34 ( & V_4 -> V_200 ) ;
return 0 ;
}
static int F_93 ( struct V_1 * V_2 , int V_81 , T_1 * V_201 ,
T_1 * V_202 )
{
T_1 V_203 ;
int V_10 ;
V_10 = F_11 ( V_2 , F_56 ( V_81 ) , V_204 ) ;
if ( V_10 < 0 )
return V_10 ;
V_203 = V_10 & V_205 ;
if ( V_201 ) {
V_10 &= ~ V_205 ;
V_10 |= * V_201 & V_205 ;
V_10 = F_18 ( V_2 , F_56 ( V_81 ) ,
V_204 , V_10 ) ;
if ( V_10 < 0 )
return V_10 ;
F_86 ( V_2 -> V_186 [ V_81 ] , L_6 , * V_201 ,
V_203 ) ;
}
if ( V_202 )
* V_202 = V_203 ;
return 0 ;
}
static int F_94 ( struct V_1 * V_2 , int V_81 , T_1 * V_203 )
{
return F_93 ( V_2 , V_81 , NULL , V_203 ) ;
}
static int F_95 ( struct V_1 * V_2 , int V_81 , T_1 V_203 )
{
return F_93 ( V_2 , V_81 , & V_203 , NULL ) ;
}
static int F_96 ( struct V_1 * V_2 )
{
return F_69 ( V_2 , V_23 , V_206 ,
V_207 ) ;
}
static int F_97 ( struct V_1 * V_2 , T_1 V_169 )
{
int V_10 ;
V_10 = F_18 ( V_2 , V_23 , V_206 , V_169 ) ;
if ( V_10 < 0 )
return V_10 ;
return F_96 ( V_2 ) ;
}
static int F_98 ( struct V_1 * V_2 )
{
int V_10 ;
V_10 = F_96 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
return F_97 ( V_2 , V_208 ) ;
}
static int F_99 ( struct V_1 * V_2 ,
struct V_209 * V_155 ,
unsigned int V_210 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_130 [ 3 ] ;
int V_11 ;
int V_10 ;
for ( V_11 = 0 ; V_11 < 3 ; ++ V_11 ) {
V_10 = F_11 ( V_2 , V_23 ,
V_211 + V_11 ) ;
if ( V_10 < 0 )
return V_10 ;
V_130 [ V_11 ] = V_10 ;
}
for ( V_11 = 0 ; V_11 < V_4 -> V_101 ; ++ V_11 ) {
unsigned int V_159 = ( V_11 % 4 ) * 4 + V_210 ;
T_1 V_16 = V_130 [ V_11 / 4 ] ;
V_155 -> V_47 [ V_11 ] = ( V_16 >> V_159 ) & V_212 ;
}
return 0 ;
}
static int F_100 ( struct V_1 * V_2 ,
struct V_209 * V_155 ,
unsigned int V_210 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_130 [ 3 ] = { 0 } ;
int V_11 ;
int V_10 ;
for ( V_11 = 0 ; V_11 < V_4 -> V_101 ; ++ V_11 ) {
unsigned int V_159 = ( V_11 % 4 ) * 4 + V_210 ;
T_2 V_47 = V_155 -> V_47 [ V_11 ] ;
V_130 [ V_11 / 4 ] |= ( V_47 & V_212 ) << V_159 ;
}
for ( V_11 = 0 ; V_11 < 3 ; ++ V_11 ) {
V_10 = F_18 ( V_2 , V_23 ,
V_211 + V_11 , V_130 [ V_11 ] ) ;
if ( V_10 < 0 )
return V_10 ;
}
return 0 ;
}
static int F_101 ( struct V_1 * V_2 , T_1 V_213 )
{
return F_18 ( V_2 , V_23 , V_214 ,
V_213 & V_215 ) ;
}
static int F_102 ( struct V_1 * V_2 ,
struct V_209 * V_155 )
{
struct V_209 V_216 = { 0 } ;
int V_10 ;
V_10 = F_96 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_97 ( V_2 , V_217 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_11 ( V_2 , V_23 , V_214 ) ;
if ( V_10 < 0 )
return V_10 ;
V_216 . V_213 = V_10 & V_215 ;
V_216 . V_218 = ! ! ( V_10 & V_219 ) ;
if ( V_216 . V_218 ) {
V_10 = F_99 ( V_2 , & V_216 , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( F_48 ( V_2 ) || F_49 ( V_2 ) ||
F_52 ( V_2 ) || F_53 ( V_2 ) ) {
V_10 = F_11 ( V_2 , V_23 ,
V_220 ) ;
if ( V_10 < 0 )
return V_10 ;
V_216 . V_171 = V_10 & V_221 ;
V_10 = F_11 ( V_2 , V_23 ,
V_222 ) ;
if ( V_10 < 0 )
return V_10 ;
V_216 . V_223 = V_10 & V_224 ;
}
}
* V_155 = V_216 ;
return 0 ;
}
int F_103 ( struct V_1 * V_2 , int V_81 ,
struct V_225 * V_226 ,
int (* F_104)( struct V_227 * V_228 ) )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_209 V_216 ;
T_1 V_203 ;
int V_170 ;
F_15 ( & V_4 -> V_5 ) ;
V_170 = F_94 ( V_2 , V_81 , & V_203 ) ;
if ( V_170 )
goto V_229;
V_170 = F_101 ( V_2 , V_215 ) ;
if ( V_170 )
goto V_229;
do {
V_170 = F_102 ( V_2 , & V_216 ) ;
if ( V_170 )
break;
if ( ! V_216 . V_218 )
break;
if ( V_216 . V_47 [ V_81 ] == V_230 )
continue;
V_226 -> V_231 = V_226 -> V_232 = V_216 . V_213 ;
V_226 -> V_233 = 0 ;
if ( V_216 . V_47 [ V_81 ] == V_234 )
V_226 -> V_233 |= V_235 ;
if ( V_216 . V_213 == V_203 )
V_226 -> V_233 |= V_236 ;
V_170 = F_104 ( & V_226 -> V_228 ) ;
if ( V_170 )
break;
} while ( V_216 . V_213 < V_215 );
V_229:
F_16 ( & V_4 -> V_5 ) ;
return V_170 ;
}
static int F_105 ( struct V_1 * V_2 ,
struct V_209 * V_155 )
{
T_1 V_16 = 0 ;
int V_10 ;
V_10 = F_96 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( ! V_155 -> V_218 )
goto V_237;
V_10 = F_100 ( V_2 , V_155 , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( F_48 ( V_2 ) || F_49 ( V_2 ) ||
F_52 ( V_2 ) || F_53 ( V_2 ) ) {
V_16 = V_155 -> V_223 & V_224 ;
V_10 = F_18 ( V_2 , V_23 , V_222 , V_16 ) ;
if ( V_10 < 0 )
return V_10 ;
V_16 = V_155 -> V_171 & V_221 ;
V_10 = F_18 ( V_2 , V_23 , V_220 , V_16 ) ;
if ( V_10 < 0 )
return V_10 ;
}
V_16 = V_219 ;
V_237:
V_16 |= V_155 -> V_213 & V_215 ;
V_10 = F_18 ( V_2 , V_23 , V_214 , V_16 ) ;
if ( V_10 < 0 )
return V_10 ;
return F_97 ( V_2 , V_238 ) ;
}
static int F_106 ( struct V_1 * V_2 , T_2 V_223 ,
struct V_209 * V_155 )
{
struct V_209 V_216 = { 0 } ;
int V_10 ;
V_10 = F_96 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_18 ( V_2 , V_23 , V_222 ,
V_223 & V_224 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_97 ( V_2 , V_239 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_11 ( V_2 , V_23 , V_222 ) ;
if ( V_10 < 0 )
return V_10 ;
V_216 . V_223 = V_10 & V_224 ;
V_10 = F_11 ( V_2 , V_23 , V_214 ) ;
if ( V_10 < 0 )
return V_10 ;
V_216 . V_218 = ! ! ( V_10 & V_219 ) ;
if ( V_216 . V_218 ) {
V_10 = F_99 ( V_2 , & V_216 , 2 ) ;
if ( V_10 < 0 )
return V_10 ;
}
* V_155 = V_216 ;
return 0 ;
}
static int F_107 ( struct V_1 * V_2 ,
struct V_209 * V_155 )
{
T_1 V_16 = 0 ;
int V_10 ;
V_10 = F_96 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( ! V_155 -> V_218 )
goto V_237;
V_10 = F_100 ( V_2 , V_155 , 2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_16 = V_219 ;
V_237:
V_10 = F_18 ( V_2 , V_23 , V_214 , V_16 ) ;
if ( V_10 < 0 )
return V_10 ;
V_16 = V_155 -> V_223 & V_224 ;
V_10 = F_18 ( V_2 , V_23 , V_222 , V_16 ) ;
if ( V_10 < 0 )
return V_10 ;
return F_97 ( V_2 , V_240 ) ;
}
static int F_108 ( struct V_1 * V_2 , int V_81 , T_1 * V_201 ,
T_1 * V_202 )
{
T_1 V_171 ;
int V_10 ;
V_10 = F_11 ( V_2 , F_56 ( V_81 ) , V_192 ) ;
if ( V_10 < 0 )
return V_10 ;
V_171 = ( V_10 & V_241 ) >> 12 ;
if ( V_201 ) {
V_10 &= ~ V_241 ;
V_10 |= ( * V_201 << 12 ) & V_241 ;
V_10 = F_18 ( V_2 , F_56 ( V_81 ) , V_192 ,
V_10 ) ;
if ( V_10 < 0 )
return V_10 ;
}
V_10 = F_11 ( V_2 , F_56 ( V_81 ) , V_242 ) ;
if ( V_10 < 0 )
return V_10 ;
V_171 |= ( V_10 & V_243 ) << 4 ;
if ( V_201 ) {
V_10 &= ~ V_243 ;
V_10 |= ( * V_201 >> 4 ) & V_243 ;
V_10 = F_18 ( V_2 , F_56 ( V_81 ) , V_242 ,
V_10 ) ;
if ( V_10 < 0 )
return V_10 ;
F_86 ( V_2 -> V_186 [ V_81 ] , L_7 , * V_201 , V_171 ) ;
}
if ( V_202 )
* V_202 = V_171 ;
return 0 ;
}
static int F_109 ( struct V_1 * V_2 , int V_81 , T_1 * V_171 )
{
return F_108 ( V_2 , V_81 , NULL , V_171 ) ;
}
static int F_110 ( struct V_1 * V_2 , int V_81 , T_1 V_171 )
{
return F_108 ( V_2 , V_81 , & V_171 , NULL ) ;
}
static int F_111 ( struct V_1 * V_2 , T_1 * V_171 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_112 ( V_244 , V_245 ) ;
struct V_209 V_226 ;
int V_11 , V_170 ;
F_113 ( V_244 , V_245 ) ;
for ( V_11 = 0 ; V_11 < V_4 -> V_101 ; ++ V_11 ) {
V_170 = F_109 ( V_2 , V_11 , V_171 ) ;
if ( V_170 )
return V_170 ;
F_92 ( * V_171 , V_244 ) ;
}
V_170 = F_101 ( V_2 , V_215 ) ;
if ( V_170 )
return V_170 ;
do {
V_170 = F_102 ( V_2 , & V_226 ) ;
if ( V_170 )
return V_170 ;
if ( ! V_226 . V_218 )
break;
F_92 ( V_226 . V_171 , V_244 ) ;
} while ( V_226 . V_213 < V_215 );
* V_171 = F_114 ( V_244 , V_245 , 1 ) ;
if ( F_3 ( * V_171 == V_245 ) )
return - V_246 ;
return F_82 ( V_2 , * V_171 , true ) ;
}
static int F_115 ( struct V_1 * V_2 , T_1 V_213 ,
struct V_209 * V_155 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_209 V_226 = {
. V_218 = true ,
. V_213 = V_213 ,
} ;
int V_11 , V_170 ;
V_170 = F_111 ( V_2 , & V_226 . V_171 ) ;
if ( V_170 )
return V_170 ;
for ( V_11 = 0 ; V_11 < V_4 -> V_101 ; ++ V_11 )
V_226 . V_47 [ V_11 ] = F_88 ( V_2 , V_11 ) || F_89 ( V_2 , V_11 )
? V_247
: V_230 ;
if ( F_48 ( V_2 ) || F_49 ( V_2 ) ||
F_52 ( V_2 ) || F_53 ( V_2 ) ) {
struct V_209 V_248 ;
V_226 . V_223 = 0 ;
V_170 = F_106 ( V_2 , V_224 , & V_248 ) ;
if ( V_170 )
return V_170 ;
if ( V_248 . V_223 != V_226 . V_223 || ! V_248 . V_218 ) {
memset ( & V_248 , 0 , sizeof( V_248 ) ) ;
V_248 . V_218 = true ;
V_248 . V_223 = V_226 . V_223 ;
V_170 = F_107 ( V_2 , & V_248 ) ;
if ( V_170 )
return V_170 ;
}
}
* V_155 = V_226 ;
return 0 ;
}
static int F_116 ( struct V_1 * V_2 , T_1 V_213 ,
struct V_209 * V_155 , bool V_249 )
{
int V_170 ;
if ( ! V_213 )
return - V_19 ;
V_170 = F_101 ( V_2 , V_213 - 1 ) ;
if ( V_170 )
return V_170 ;
V_170 = F_102 ( V_2 , V_155 ) ;
if ( V_170 )
return V_170 ;
if ( V_155 -> V_213 != V_213 || ! V_155 -> V_218 ) {
if ( ! V_249 )
return - V_250 ;
V_170 = F_115 ( V_2 , V_213 , V_155 ) ;
}
return V_170 ;
}
static int F_117 ( struct V_1 * V_2 , int V_81 ,
T_1 V_231 , T_1 V_232 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_209 V_226 ;
int V_11 , V_170 ;
if ( ! V_231 )
return - V_250 ;
F_15 ( & V_4 -> V_5 ) ;
V_170 = F_101 ( V_2 , V_231 - 1 ) ;
if ( V_170 )
goto V_229;
do {
V_170 = F_102 ( V_2 , & V_226 ) ;
if ( V_170 )
goto V_229;
if ( ! V_226 . V_218 )
break;
if ( V_226 . V_213 > V_232 )
break;
for ( V_11 = 0 ; V_11 < V_4 -> V_101 ; ++ V_11 ) {
if ( F_89 ( V_2 , V_11 ) || F_88 ( V_2 , V_11 ) )
continue;
if ( V_226 . V_47 [ V_11 ] ==
V_230 )
continue;
if ( V_4 -> V_186 [ V_11 ] . V_190 ==
V_4 -> V_186 [ V_81 ] . V_190 )
break;
F_118 ( V_2 -> V_186 [ V_81 ] ,
L_8 ,
V_226 . V_213 ,
F_119 ( V_4 -> V_186 [ V_11 ] . V_190 ) ) ;
V_170 = - V_250 ;
goto V_229;
}
} while ( V_226 . V_213 < V_232 );
V_229:
F_16 ( & V_4 -> V_5 ) ;
return V_170 ;
}
int F_120 ( struct V_1 * V_2 , int V_81 ,
bool V_251 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_202 , V_201 = V_251 ? V_252 :
V_253 ;
int V_10 ;
F_15 ( & V_4 -> V_5 ) ;
V_10 = F_11 ( V_2 , F_56 ( V_81 ) , V_254 ) ;
if ( V_10 < 0 )
goto V_229;
V_202 = V_10 & V_255 ;
if ( V_201 != V_202 ) {
V_10 &= ~ V_255 ;
V_10 |= V_201 & V_255 ;
V_10 = F_18 ( V_2 , F_56 ( V_81 ) , V_254 ,
V_10 ) ;
if ( V_10 < 0 )
goto V_229;
F_86 ( V_2 -> V_186 [ V_81 ] , L_9 ,
V_256 [ V_201 ] ,
V_256 [ V_202 ] ) ;
}
V_10 = 0 ;
V_229:
F_16 ( & V_4 -> V_5 ) ;
return V_10 ;
}
int F_121 ( struct V_1 * V_2 , int V_81 ,
const struct V_225 * V_226 ,
struct V_257 * V_258 )
{
int V_170 ;
V_170 = F_117 ( V_2 , V_81 , V_226 -> V_231 ,
V_226 -> V_232 ) ;
if ( V_170 )
return V_170 ;
return 0 ;
}
static int F_122 ( struct V_1 * V_2 , int V_81 , T_1 V_213 ,
bool V_259 )
{
struct V_209 V_226 ;
int V_170 ;
V_170 = F_116 ( V_2 , V_213 , & V_226 , true ) ;
if ( V_170 )
return V_170 ;
V_226 . V_47 [ V_81 ] = V_259 ?
V_234 :
V_260 ;
return F_105 ( V_2 , & V_226 ) ;
}
int F_123 ( struct V_1 * V_2 , int V_81 ,
const struct V_225 * V_226 ,
struct V_257 * V_258 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
bool V_259 = V_226 -> V_233 & V_235 ;
bool V_203 = V_226 -> V_233 & V_236 ;
T_1 V_213 ;
int V_170 = 0 ;
F_15 ( & V_4 -> V_5 ) ;
for ( V_213 = V_226 -> V_231 ; V_213 <= V_226 -> V_232 ; ++ V_213 ) {
V_170 = F_122 ( V_2 , V_81 , V_213 , V_259 ) ;
if ( V_170 )
goto V_229;
}
if ( V_203 )
V_170 = F_95 ( V_2 , V_81 , V_226 -> V_232 ) ;
V_229:
F_16 ( & V_4 -> V_5 ) ;
return V_170 ;
}
static int F_124 ( struct V_1 * V_2 , int V_81 , T_1 V_213 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_209 V_226 ;
int V_11 , V_170 ;
V_170 = F_116 ( V_2 , V_213 , & V_226 , false ) ;
if ( V_170 )
return V_170 ;
if ( V_226 . V_47 [ V_81 ] == V_230 )
return - V_250 ;
V_226 . V_47 [ V_81 ] = V_230 ;
V_226 . V_218 = false ;
for ( V_11 = 0 ; V_11 < V_4 -> V_101 ; ++ V_11 ) {
if ( F_88 ( V_2 , V_11 ) || F_89 ( V_2 , V_11 ) )
continue;
if ( V_226 . V_47 [ V_11 ] != V_230 ) {
V_226 . V_218 = true ;
break;
}
}
V_170 = F_105 ( V_2 , & V_226 ) ;
if ( V_170 )
return V_170 ;
return F_84 ( V_2 , V_226 . V_171 , V_81 , false ) ;
}
int F_125 ( struct V_1 * V_2 , int V_81 ,
const struct V_225 * V_226 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_203 , V_213 ;
int V_170 = 0 ;
F_15 ( & V_4 -> V_5 ) ;
V_170 = F_94 ( V_2 , V_81 , & V_203 ) ;
if ( V_170 )
goto V_229;
for ( V_213 = V_226 -> V_231 ; V_213 <= V_226 -> V_232 ; ++ V_213 ) {
V_170 = F_124 ( V_2 , V_81 , V_213 ) ;
if ( V_170 )
goto V_229;
if ( V_213 == V_203 ) {
V_170 = F_95 ( V_2 , V_81 , 0 ) ;
if ( V_170 )
goto V_229;
}
}
V_229:
F_16 ( & V_4 -> V_5 ) ;
return V_170 ;
}
static int F_126 ( struct V_1 * V_2 ,
const unsigned char * V_15 )
{
int V_11 , V_10 ;
for ( V_11 = 0 ; V_11 < 3 ; V_11 ++ ) {
V_10 = F_18 (
V_2 , V_23 , V_261 + V_11 ,
( V_15 [ V_11 * 2 ] << 8 ) | V_15 [ V_11 * 2 + 1 ] ) ;
if ( V_10 < 0 )
return V_10 ;
}
return 0 ;
}
static int F_127 ( struct V_1 * V_2 , unsigned char * V_15 )
{
int V_11 , V_10 ;
for ( V_11 = 0 ; V_11 < 3 ; V_11 ++ ) {
V_10 = F_11 ( V_2 , V_23 ,
V_261 + V_11 ) ;
if ( V_10 < 0 )
return V_10 ;
V_15 [ V_11 * 2 ] = V_10 >> 8 ;
V_15 [ V_11 * 2 + 1 ] = V_10 & 0xff ;
}
return 0 ;
}
static int F_128 ( struct V_1 * V_2 ,
struct V_154 * V_155 )
{
int V_10 ;
V_10 = F_74 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_126 ( V_2 , V_155 -> V_262 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_80 ( V_2 , V_155 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_18 ( V_2 , V_23 , V_172 , V_155 -> V_171 ) ;
if ( V_10 < 0 )
return V_10 ;
return F_79 ( V_2 , V_263 ) ;
}
static int F_129 ( struct V_1 * V_2 , int V_81 ,
const unsigned char * V_15 , T_1 V_213 ,
T_2 V_156 )
{
struct V_154 V_155 = { 0 } ;
struct V_209 V_226 ;
int V_170 ;
if ( V_213 == 0 )
V_170 = F_109 ( V_2 , V_81 , & V_226 . V_171 ) ;
else
V_170 = F_116 ( V_2 , V_213 , & V_226 , false ) ;
if ( V_170 )
return V_170 ;
V_155 . V_171 = V_226 . V_171 ;
V_155 . V_156 = V_156 ;
F_130 ( V_155 . V_262 , V_15 ) ;
if ( V_156 != V_158 ) {
V_155 . V_160 = false ;
V_155 . V_166 = F_90 ( V_81 ) ;
}
return F_128 ( V_2 , & V_155 ) ;
}
int F_131 ( struct V_1 * V_2 , int V_81 ,
const struct V_264 * V_265 ,
struct V_257 * V_258 )
{
return 0 ;
}
int F_132 ( struct V_1 * V_2 , int V_81 ,
const struct V_264 * V_265 ,
struct V_257 * V_258 )
{
int V_156 = F_133 ( V_265 -> V_15 ) ?
V_266 :
V_267 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_10 ;
F_15 ( & V_4 -> V_5 ) ;
V_10 = F_129 ( V_2 , V_81 , V_265 -> V_15 , V_265 -> V_213 , V_156 ) ;
F_16 ( & V_4 -> V_5 ) ;
return V_10 ;
}
int F_134 ( struct V_1 * V_2 , int V_81 ,
const struct V_264 * V_265 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_10 ;
F_15 ( & V_4 -> V_5 ) ;
V_10 = F_129 ( V_2 , V_81 , V_265 -> V_15 , V_265 -> V_213 ,
V_158 ) ;
F_16 ( & V_4 -> V_5 ) ;
return V_10 ;
}
static int F_135 ( struct V_1 * V_2 , T_1 V_171 ,
struct V_154 * V_155 )
{
struct V_154 V_216 = { 0 } ;
int V_10 ;
V_216 . V_171 = V_171 ;
V_10 = F_74 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_18 ( V_2 , V_23 , V_172 , V_171 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_79 ( V_2 , V_268 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_127 ( V_2 , V_216 . V_262 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_11 ( V_2 , V_23 , V_167 ) ;
if ( V_10 < 0 )
return V_10 ;
V_216 . V_156 = V_10 & V_157 ;
if ( V_216 . V_156 != V_158 ) {
unsigned int V_135 , V_159 ;
if ( V_10 & V_161 ) {
V_216 . V_160 = true ;
V_135 = V_162 ;
V_159 = V_163 ;
} else {
V_216 . V_160 = false ;
V_135 = V_164 ;
V_159 = V_165 ;
}
V_216 . V_166 = ( V_10 & V_135 ) >> V_159 ;
}
* V_155 = V_216 ;
return 0 ;
}
static int F_136 ( struct V_1 * V_2 , T_1 V_171 , T_1 V_213 ,
int V_81 ,
struct V_264 * V_265 ,
int (* F_104)( struct V_227 * V_228 ) )
{
struct V_154 V_15 = {
. V_262 = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ,
} ;
int V_170 ;
V_170 = F_126 ( V_2 , V_15 . V_262 ) ;
if ( V_170 )
return V_170 ;
do {
V_170 = F_135 ( V_2 , V_171 , & V_15 ) ;
if ( V_170 )
break;
if ( V_15 . V_156 == V_158 )
break;
if ( ! V_15 . V_160 && V_15 . V_166 & F_90 ( V_81 ) ) {
bool V_269 = V_15 . V_156 ==
( F_133 ( V_15 . V_262 ) ?
V_266 :
V_267 ) ;
V_265 -> V_213 = V_213 ;
F_130 ( V_265 -> V_15 , V_15 . V_262 ) ;
V_265 -> V_270 = V_269 ? V_271 : V_272 ;
V_170 = F_104 ( & V_265 -> V_228 ) ;
if ( V_170 )
break;
}
} while ( ! F_137 ( V_15 . V_262 ) );
return V_170 ;
}
int F_138 ( struct V_1 * V_2 , int V_81 ,
struct V_264 * V_265 ,
int (* F_104)( struct V_227 * V_228 ) )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_209 V_226 = {
. V_213 = V_215 ,
} ;
T_1 V_171 ;
int V_170 ;
F_15 ( & V_4 -> V_5 ) ;
V_170 = F_109 ( V_2 , V_81 , & V_171 ) ;
if ( V_170 )
goto V_229;
V_170 = F_136 ( V_2 , V_171 , 0 , V_81 , V_265 , F_104 ) ;
if ( V_170 )
goto V_229;
V_170 = F_101 ( V_2 , V_226 . V_213 ) ;
if ( V_170 )
goto V_229;
do {
V_170 = F_102 ( V_2 , & V_226 ) ;
if ( V_170 )
break;
if ( ! V_226 . V_218 )
break;
V_170 = F_136 ( V_2 , V_226 . V_171 , V_226 . V_213 , V_81 ,
V_265 , F_104 ) ;
if ( V_170 )
break;
} while ( V_226 . V_213 < V_215 );
V_229:
F_16 ( & V_4 -> V_5 ) ;
return V_170 ;
}
int F_139 ( struct V_1 * V_2 , int V_81 ,
struct V_188 * V_189 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_11 , V_170 = 0 ;
F_15 ( & V_4 -> V_5 ) ;
V_4 -> V_186 [ V_81 ] . V_190 = V_189 ;
for ( V_11 = 0 ; V_11 < V_4 -> V_101 ; ++ V_11 ) {
if ( V_4 -> V_186 [ V_11 ] . V_190 == V_189 ) {
V_170 = F_87 ( V_2 , V_11 ) ;
if ( V_170 )
break;
}
}
F_16 ( & V_4 -> V_5 ) ;
return V_170 ;
}
void F_140 ( struct V_1 * V_2 , int V_81 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_188 * V_189 = V_4 -> V_186 [ V_81 ] . V_190 ;
int V_11 ;
F_15 ( & V_4 -> V_5 ) ;
V_4 -> V_186 [ V_81 ] . V_190 = NULL ;
for ( V_11 = 0 ; V_11 < V_4 -> V_101 ; ++ V_11 )
if ( V_11 == V_81 || V_4 -> V_186 [ V_11 ] . V_190 == V_189 )
if ( F_87 ( V_2 , V_11 ) )
F_118 ( V_2 -> V_186 [ V_11 ] , L_10 ) ;
F_16 ( & V_4 -> V_5 ) ;
}
static void F_141 ( struct V_40 * V_273 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
int V_81 ;
V_4 = F_31 ( V_273 , struct V_3 , V_200 ) ;
V_2 = ( (struct V_1 * ) V_4 ) - 1 ;
F_15 ( & V_4 -> V_5 ) ;
for ( V_81 = 0 ; V_81 < V_4 -> V_101 ; ++ V_81 )
if ( F_142 ( V_81 , V_4 -> V_199 ) &&
F_85 ( V_2 , V_81 , V_4 -> V_186 [ V_81 ] . V_156 ) )
F_118 ( V_2 -> V_186 [ V_81 ] , L_11 ,
V_187 [ V_4 -> V_186 [ V_81 ] . V_156 ] ) ;
F_16 ( & V_4 -> V_5 ) ;
}
static int F_143 ( struct V_1 * V_2 , int V_81 , int V_274 ,
int V_16 , int V_21 )
{
int V_10 ;
V_10 = F_76 ( V_2 , V_81 , 0x16 , V_274 ) ;
if ( V_10 < 0 )
goto V_275;
V_10 = F_76 ( V_2 , V_81 , V_16 , V_21 ) ;
V_275:
F_76 ( V_2 , V_81 , 0x16 , 0x0 ) ;
return V_10 ;
}
static int F_144 ( struct V_1 * V_2 , int V_81 , int V_274 ,
int V_16 )
{
int V_10 ;
V_10 = F_76 ( V_2 , V_81 , 0x16 , V_274 ) ;
if ( V_10 < 0 )
goto V_275;
V_10 = F_75 ( V_2 , V_81 , V_16 ) ;
V_275:
F_76 ( V_2 , V_81 , 0x16 , 0x0 ) ;
return V_10 ;
}
static int F_145 ( struct V_1 * V_2 )
{
int V_10 ;
V_10 = F_144 ( V_2 , V_276 , V_277 ,
V_278 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_10 & V_279 ) {
V_10 &= ~ V_279 ;
V_10 = F_143 ( V_2 , V_276 ,
V_277 , V_278 ,
V_10 ) ;
}
return V_10 ;
}
static int F_146 ( struct V_1 * V_2 , int V_81 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_10 ;
T_1 V_16 ;
F_15 ( & V_4 -> V_5 ) ;
if ( F_53 ( V_2 ) || F_52 ( V_2 ) ||
F_49 ( V_2 ) || F_48 ( V_2 ) ||
F_50 ( V_2 ) || F_47 ( V_2 ) ||
F_46 ( V_2 ) || F_51 ( V_2 ) ) {
V_16 = F_11 ( V_2 , F_56 ( V_81 ) , V_84 ) ;
if ( F_88 ( V_2 , V_81 ) || F_89 ( V_2 , V_81 ) ) {
V_16 &= ~ V_90 ;
V_16 |= V_87 |
V_86 |
V_88 |
V_89 ;
if ( F_46 ( V_2 ) )
V_16 |= V_96 ;
else
V_16 |= V_95 ;
} else {
V_16 |= V_90 ;
}
V_10 = F_18 ( V_2 , F_56 ( V_81 ) ,
V_84 , V_16 ) ;
if ( V_10 )
goto abort;
}
V_16 = 0 ;
if ( F_53 ( V_2 ) || F_52 ( V_2 ) ||
F_49 ( V_2 ) || F_48 ( V_2 ) ||
F_47 ( V_2 ) || F_46 ( V_2 ) ||
F_50 ( V_2 ) || F_51 ( V_2 ) )
V_16 = V_280 |
V_281 | V_282 |
V_183 ;
if ( F_88 ( V_2 , V_81 ) ) {
if ( F_47 ( V_2 ) || F_50 ( V_2 ) )
V_16 |= V_283 ;
if ( F_53 ( V_2 ) || F_52 ( V_2 ) ||
F_49 ( V_2 ) || F_48 ( V_2 ) ||
F_51 ( V_2 ) ) {
if ( V_2 -> V_284 -> V_285 == V_286 )
V_16 |= V_287 ;
else
V_16 |= V_288 ;
V_16 |= V_289 |
V_290 ;
}
if ( F_53 ( V_2 ) || F_52 ( V_2 ) ||
F_49 ( V_2 ) || F_48 ( V_2 ) ||
F_47 ( V_2 ) || F_46 ( V_2 ) ||
F_50 ( V_2 ) || F_51 ( V_2 ) ) {
if ( V_2 -> V_284 -> V_285 == V_286 )
V_16 |= V_291 ;
}
}
if ( F_89 ( V_2 , V_81 ) ) {
if ( F_47 ( V_2 ) || F_50 ( V_2 ) )
V_16 |= V_283 ;
if ( F_53 ( V_2 ) || F_52 ( V_2 ) ||
F_49 ( V_2 ) || F_48 ( V_2 ) ||
F_51 ( V_2 ) ) {
V_16 |= V_288 ;
}
if ( V_81 == F_147 ( V_2 ) )
V_16 |= V_289 |
V_290 ;
}
if ( V_16 ) {
V_10 = F_18 ( V_2 , F_56 ( V_81 ) ,
V_180 , V_16 ) ;
if ( V_10 )
goto abort;
}
if ( F_53 ( V_2 ) ) {
V_10 = F_11 ( V_2 , F_56 ( V_81 ) , V_150 ) ;
if ( V_10 < 0 )
goto abort;
V_10 &= V_292 ;
if ( ( V_10 == V_293 ) ||
( V_10 == V_294 ) ||
( V_10 == V_295 ) ) {
V_10 = F_145 ( V_2 ) ;
if ( V_10 < 0 )
goto abort;
}
}
V_16 = 0 ;
if ( F_53 ( V_2 ) || F_52 ( V_2 ) ||
F_49 ( V_2 ) || F_48 ( V_2 ) ||
F_47 ( V_2 ) || F_51 ( V_2 ) )
V_16 = V_296 ;
if ( F_53 ( V_2 ) || F_52 ( V_2 ) ||
F_49 ( V_2 ) || F_51 ( V_2 ) )
V_16 |= V_297 ;
if ( F_47 ( V_2 ) || F_50 ( V_2 ) ) {
V_16 |= F_147 ( V_2 ) ;
if ( V_81 == F_147 ( V_2 ) )
V_16 |= V_298 ;
}
V_16 |= V_253 ;
if ( V_16 ) {
V_10 = F_18 ( V_2 , F_56 ( V_81 ) ,
V_254 , V_16 ) ;
if ( V_10 )
goto abort;
}
V_16 = 1 << V_81 ;
if ( F_88 ( V_2 , V_81 ) )
V_16 = 0 ;
V_10 = F_18 ( V_2 , F_56 ( V_81 ) , V_299 , V_16 ) ;
if ( V_10 )
goto abort;
V_10 = F_18 ( V_2 , F_56 ( V_81 ) , V_300 ,
0x0000 ) ;
if ( V_10 )
goto abort;
if ( F_53 ( V_2 ) || F_52 ( V_2 ) ||
F_49 ( V_2 ) || F_48 ( V_2 ) ||
F_51 ( V_2 ) ) {
V_10 = F_18 ( V_2 , F_56 ( V_81 ) ,
V_301 , 0x0000 ) ;
if ( V_10 )
goto abort;
V_10 = F_18 ( V_2 , F_56 ( V_81 ) ,
V_302 , 0x0000 ) ;
V_10 = F_18 ( V_2 , F_56 ( V_81 ) ,
V_303 , 0x0000 ) ;
if ( V_10 )
goto abort;
V_10 = F_18 ( V_2 , F_56 ( V_81 ) ,
V_304 , V_305 ) ;
if ( V_10 )
goto abort;
V_10 = F_18 ( V_2 , F_56 ( V_81 ) ,
V_306 , 0x3210 ) ;
if ( V_10 )
goto abort;
V_10 = F_18 ( V_2 , F_56 ( V_81 ) ,
V_307 , 0x7654 ) ;
if ( V_10 )
goto abort;
}
if ( F_53 ( V_2 ) || F_52 ( V_2 ) ||
F_49 ( V_2 ) || F_48 ( V_2 ) ||
F_50 ( V_2 ) || F_47 ( V_2 ) ||
F_51 ( V_2 ) ) {
V_10 = F_18 ( V_2 , F_56 ( V_81 ) ,
V_308 , 0x0001 ) ;
if ( V_10 )
goto abort;
}
V_10 = F_18 ( V_2 , F_56 ( V_81 ) , V_242 , 0x0000 ) ;
if ( V_10 )
goto abort;
V_10 = F_110 ( V_2 , V_81 , 0 ) ;
if ( V_10 )
goto abort;
V_10 = F_87 ( V_2 , V_81 ) ;
if ( V_10 )
goto abort;
V_10 = F_18 ( V_2 , F_56 ( V_81 ) , V_204 ,
0x0000 ) ;
abort:
F_16 ( & V_4 -> V_5 ) ;
return V_10 ;
}
int F_148 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_10 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_4 -> V_101 ; V_11 ++ ) {
V_10 = F_146 ( V_2 , V_11 ) ;
if ( V_10 < 0 )
return V_10 ;
}
return 0 ;
}
int F_149 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_41 ( & V_4 -> V_5 ) ;
V_4 -> V_49 = F_23 ( F_56 ( 0 ) , V_309 ) & 0xfff0 ;
F_42 ( & V_4 -> V_200 , F_141 ) ;
return 0 ;
}
int F_150 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_10 ;
int V_11 ;
F_21 ( V_23 , V_310 ,
0x0140 | V_311 ) ;
F_21 ( V_23 , V_312 , 0x0000 ) ;
F_21 ( V_23 , V_313 , 0x0000 ) ;
F_21 ( V_23 , V_314 , 0x5555 ) ;
F_21 ( V_23 , V_315 , 0x5555 ) ;
F_21 ( V_23 , V_316 , 0xaaaa ) ;
F_21 ( V_23 , V_317 , 0xaaaa ) ;
F_21 ( V_23 , V_318 , 0xffff ) ;
F_21 ( V_23 , V_319 , 0xffff ) ;
F_21 ( V_23 , V_320 , 0xfa41 ) ;
F_21 ( V_28 , V_321 , 0xffff ) ;
F_21 ( V_28 , V_322 ,
0x7 | V_323 | 0x70 |
V_324 ) ;
for ( V_11 = 0 ; V_11 < 32 ; V_11 ++ ) {
int V_325 = 0x1f ;
if ( V_2 -> V_20 -> V_326 &&
V_11 != V_2 -> V_327 && V_11 < V_2 -> V_284 -> V_20 -> V_328 )
V_325 = V_2 -> V_20 -> V_326 [ V_11 ] & 0x1f ;
F_21 ( V_28 , V_329 ,
V_330 |
( V_11 << V_331 ) |
V_325 ) ;
}
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ )
F_21 ( V_28 , V_332 ,
0x8000 | ( V_11 << V_333 ) |
( ( 1 << V_4 -> V_101 ) - 1 ) ) ;
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ )
F_21 ( V_28 , V_334 ,
V_335 |
( V_11 << V_336 ) ) ;
if ( F_53 ( V_2 ) || F_52 ( V_2 ) ||
F_49 ( V_2 ) || F_48 ( V_2 ) ||
F_51 ( V_2 ) ) {
F_21 ( V_28 , V_337 , 0xffff ) ;
F_21 ( V_28 , V_338 , 0x9000 ) ;
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ )
F_21 ( V_28 , V_339 ,
0x8000 | ( V_11 << 8 ) ) ;
}
if ( F_53 ( V_2 ) || F_52 ( V_2 ) ||
F_49 ( V_2 ) || F_48 ( V_2 ) ||
F_50 ( V_2 ) || F_47 ( V_2 ) ||
F_51 ( V_2 ) ) {
for ( V_11 = 0 ; V_11 < V_4 -> V_101 ; V_11 ++ )
F_21 ( V_28 , V_340 ,
0x9000 | ( V_11 << 8 ) ) ;
}
F_21 ( V_23 , V_108 , V_341 ) ;
F_15 ( & V_4 -> V_5 ) ;
V_10 = F_58 ( V_2 ) ;
if ( V_10 < 0 )
goto V_229;
V_10 = F_82 ( V_2 , 0 , true ) ;
if ( V_10 < 0 )
goto V_229;
V_10 = F_98 ( V_2 ) ;
V_229:
F_16 ( & V_4 -> V_5 ) ;
return V_10 ;
}
int F_151 ( struct V_1 * V_2 , bool V_342 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_343 = ( V_342 ? 0x8800 : 0xc800 ) ;
struct V_344 * V_345 = V_2 -> V_20 -> V_346 ;
unsigned long V_32 ;
int V_10 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_4 -> V_101 ; V_11 ++ ) {
V_10 = F_23 ( F_56 ( V_11 ) , V_180 ) ;
F_21 ( F_56 ( V_11 ) , V_180 , V_10 & 0xfffc ) ;
}
F_28 ( 2000 , 4000 ) ;
if ( V_345 ) {
F_152 ( V_345 , 1 ) ;
F_28 ( 10000 , 20000 ) ;
F_152 ( V_345 , 0 ) ;
F_28 ( 10000 , 20000 ) ;
}
if ( V_342 )
F_21 ( V_23 , 0x04 , 0xc000 ) ;
else
F_21 ( V_23 , 0x04 , 0xc400 ) ;
V_32 = V_35 + 1 * V_36 ;
while ( F_27 ( V_35 , V_32 ) ) {
V_10 = F_23 ( V_23 , 0x00 ) ;
if ( ( V_10 & V_343 ) == V_343 )
break;
F_28 ( 1000 , 2000 ) ;
}
if ( F_153 ( V_35 , V_32 ) )
return - V_14 ;
return 0 ;
}
int F_154 ( struct V_1 * V_2 , int V_81 , int V_274 , int V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_10 ;
F_15 ( & V_4 -> V_5 ) ;
V_10 = F_144 ( V_2 , V_81 , V_274 , V_16 ) ;
F_16 ( & V_4 -> V_5 ) ;
return V_10 ;
}
int F_155 ( struct V_1 * V_2 , int V_81 , int V_274 ,
int V_16 , int V_21 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_10 ;
F_15 ( & V_4 -> V_5 ) ;
V_10 = F_143 ( V_2 , V_81 , V_274 , V_16 , V_21 ) ;
F_16 ( & V_4 -> V_5 ) ;
return V_10 ;
}
static int F_156 ( struct V_1 * V_2 , int V_81 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_81 >= 0 && V_81 < V_4 -> V_101 )
return V_81 ;
return - V_19 ;
}
int
F_157 ( struct V_1 * V_2 , int V_81 , int V_31 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_15 = F_156 ( V_2 , V_81 ) ;
int V_10 ;
if ( V_15 < 0 )
return V_15 ;
F_15 ( & V_4 -> V_5 ) ;
V_10 = F_24 ( V_2 , V_15 , V_31 ) ;
F_16 ( & V_4 -> V_5 ) ;
return V_10 ;
}
int
F_158 ( struct V_1 * V_2 , int V_81 , int V_31 , T_1 V_21 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_15 = F_156 ( V_2 , V_81 ) ;
int V_10 ;
if ( V_15 < 0 )
return V_15 ;
F_15 ( & V_4 -> V_5 ) ;
V_10 = F_25 ( V_2 , V_15 , V_31 , V_21 ) ;
F_16 ( & V_4 -> V_5 ) ;
return V_10 ;
}
int
F_159 ( struct V_1 * V_2 , int V_81 , int V_31 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_15 = F_156 ( V_2 , V_81 ) ;
int V_10 ;
if ( V_15 < 0 )
return V_15 ;
F_15 ( & V_4 -> V_5 ) ;
V_10 = F_75 ( V_2 , V_15 , V_31 ) ;
F_16 ( & V_4 -> V_5 ) ;
return V_10 ;
}
int
F_160 ( struct V_1 * V_2 , int V_81 , int V_31 ,
T_1 V_21 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_15 = F_156 ( V_2 , V_81 ) ;
int V_10 ;
if ( V_15 < 0 )
return V_15 ;
F_15 ( & V_4 -> V_5 ) ;
V_10 = F_76 ( V_2 , V_15 , V_31 , V_21 ) ;
F_16 ( & V_4 -> V_5 ) ;
return V_10 ;
}
static int F_161 ( struct V_1 * V_2 , int * V_347 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_10 ;
int V_21 ;
* V_347 = 0 ;
F_15 ( & V_4 -> V_5 ) ;
V_10 = F_25 ( V_2 , 0x0 , 0x16 , 0x6 ) ;
if ( V_10 < 0 )
goto error;
V_10 = F_24 ( V_2 , 0x0 , 0x1a ) ;
if ( V_10 < 0 )
goto error;
V_10 = F_25 ( V_2 , 0x0 , 0x1a , V_10 | ( 1 << 5 ) ) ;
if ( V_10 < 0 )
goto error;
F_28 ( 10000 , 12000 ) ;
V_21 = F_24 ( V_2 , 0x0 , 0x1a ) ;
if ( V_21 < 0 ) {
V_10 = V_21 ;
goto error;
}
V_10 = F_25 ( V_2 , 0x0 , 0x1a , V_10 & ~ ( 1 << 5 ) ) ;
if ( V_10 < 0 )
goto error;
* V_347 = ( ( V_21 & 0x1f ) - 5 ) * 5 ;
error:
F_25 ( V_2 , 0x0 , 0x16 , 0x0 ) ;
F_16 ( & V_4 -> V_5 ) ;
return V_10 ;
}
static int F_162 ( struct V_1 * V_2 , int * V_347 )
{
int V_348 = F_51 ( V_2 ) ? 3 : 0 ;
int V_10 ;
* V_347 = 0 ;
V_10 = F_154 ( V_2 , V_348 , 6 , 27 ) ;
if ( V_10 < 0 )
return V_10 ;
* V_347 = ( V_10 & 0xff ) - 25 ;
return 0 ;
}
int F_163 ( struct V_1 * V_2 , int * V_347 )
{
if ( F_51 ( V_2 ) || F_53 ( V_2 ) )
return F_162 ( V_2 , V_347 ) ;
return F_161 ( V_2 , V_347 ) ;
}
int F_164 ( struct V_1 * V_2 , int * V_347 )
{
int V_348 = F_51 ( V_2 ) ? 3 : 0 ;
int V_10 ;
if ( ! F_51 ( V_2 ) && ! F_53 ( V_2 ) )
return - V_250 ;
* V_347 = 0 ;
V_10 = F_154 ( V_2 , V_348 , 6 , 26 ) ;
if ( V_10 < 0 )
return V_10 ;
* V_347 = ( ( ( V_10 >> 8 ) & 0x1f ) * 5 ) - 25 ;
return 0 ;
}
int F_165 ( struct V_1 * V_2 , int V_347 )
{
int V_348 = F_51 ( V_2 ) ? 3 : 0 ;
int V_10 ;
if ( ! F_51 ( V_2 ) && ! F_53 ( V_2 ) )
return - V_250 ;
V_10 = F_154 ( V_2 , V_348 , 6 , 26 ) ;
if ( V_10 < 0 )
return V_10 ;
V_347 = F_166 ( F_167 ( V_347 , 5 ) + 5 , 0 , 0x1f ) ;
return F_155 ( V_2 , V_348 , 6 , 26 ,
( V_10 & 0xe0ff ) | ( V_347 << 8 ) ) ;
}
int F_168 ( struct V_1 * V_2 , bool * V_349 )
{
int V_348 = F_51 ( V_2 ) ? 3 : 0 ;
int V_10 ;
if ( ! F_51 ( V_2 ) && ! F_53 ( V_2 ) )
return - V_250 ;
* V_349 = false ;
V_10 = F_154 ( V_2 , V_348 , 6 , 26 ) ;
if ( V_10 < 0 )
return V_10 ;
* V_349 = ! ! ( V_10 & 0x40 ) ;
return 0 ;
}
char * F_169 ( struct V_350 * V_351 , int V_9 ,
const struct V_352 * V_353 ,
unsigned int V_354 )
{
struct V_7 * V_8 = F_12 ( V_351 ) ;
int V_11 , V_10 ;
if ( ! V_8 )
return NULL ;
V_10 = F_9 ( V_8 , V_9 , F_56 ( 0 ) , V_309 ) ;
if ( V_10 < 0 )
return NULL ;
for ( V_11 = 0 ; V_11 < V_354 ; ++ V_11 )
if ( V_353 [ V_11 ] . V_49 == V_10 )
return V_353 [ V_11 ] . V_355 ;
for ( V_11 = 0 ; V_11 < V_354 ; ++ V_11 ) {
if ( V_353 [ V_11 ] . V_49 == ( V_10 & V_356 ) ) {
F_170 ( V_351 , L_12 ,
V_10 & V_357 ,
V_10 & V_356 ) ;
return V_353 [ V_11 ] . V_355 ;
}
}
return NULL ;
}
static int T_7 F_171 ( void )
{
#if F_172 ( V_358 )
F_173 ( & V_359 ) ;
#endif
#if F_172 ( V_360 )
F_173 ( & V_361 ) ;
#endif
#if F_172 ( V_362 )
F_173 ( & V_363 ) ;
#endif
#if F_172 ( V_364 )
F_173 ( & V_365 ) ;
#endif
return 0 ;
}
static void T_8 F_174 ( void )
{
#if F_172 ( V_364 )
F_175 ( & V_365 ) ;
#endif
#if F_172 ( V_362 )
F_175 ( & V_363 ) ;
#endif
#if F_172 ( V_360 )
F_175 ( & V_361 ) ;
#endif
#if F_172 ( V_358 )
F_175 ( & V_359 ) ;
#endif
}
