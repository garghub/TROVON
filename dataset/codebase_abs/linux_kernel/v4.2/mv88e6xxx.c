static int F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
int V_5 ;
F_2 ( & V_2 -> V_6 , V_7 ) ;
V_5 = V_2 -> V_8 ( V_2 , V_3 , V_4 ) ;
F_3 ( & V_2 -> V_6 ) ;
return V_5 ;
}
static int F_4 ( struct V_1 * V_2 , int V_3 , T_1 V_4 ,
T_2 V_9 )
{
int V_5 ;
F_2 ( & V_2 -> V_6 , V_7 ) ;
V_5 = V_2 -> V_10 ( V_2 , V_3 , V_4 , V_9 ) ;
F_3 ( & V_2 -> V_6 ) ;
return V_5 ;
}
static int F_5 ( struct V_1 * V_2 , int V_11 )
{
int V_5 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < 16 ; V_12 ++ ) {
V_5 = F_1 ( V_2 , V_11 , V_13 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( ( V_5 & V_14 ) == 0 )
return 0 ;
}
return - V_15 ;
}
int F_6 ( struct V_1 * V_2 , int V_11 , int V_3 , int V_16 )
{
int V_5 ;
if ( V_11 == 0 )
return F_1 ( V_2 , V_3 , V_16 ) ;
V_5 = F_5 ( V_2 , V_11 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_4 ( V_2 , V_11 , V_13 ,
V_17 | ( V_3 << 5 ) | V_16 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_5 ( V_2 , V_11 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_1 ( V_2 , V_11 , V_18 ) ;
if ( V_5 < 0 )
return V_5 ;
return V_5 & 0xffff ;
}
static int F_7 ( struct V_19 * V_20 , int V_3 , int V_16 )
{
struct V_1 * V_2 = F_8 ( V_20 -> V_21 ) ;
int V_5 ;
if ( V_2 == NULL )
return - V_22 ;
V_5 = F_6 ( V_2 , V_20 -> V_23 -> V_11 , V_3 , V_16 ) ;
if ( V_5 < 0 )
return V_5 ;
F_9 ( V_20 -> V_21 , L_1 ,
V_3 , V_16 , V_5 ) ;
return V_5 ;
}
int F_10 ( struct V_19 * V_20 , int V_3 , int V_16 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_5 ;
F_12 ( & V_25 -> V_26 ) ;
V_5 = F_7 ( V_20 , V_3 , V_16 ) ;
F_3 ( & V_25 -> V_26 ) ;
return V_5 ;
}
int F_13 ( struct V_1 * V_2 , int V_11 , int V_3 ,
int V_16 , T_2 V_9 )
{
int V_5 ;
if ( V_11 == 0 )
return F_4 ( V_2 , V_3 , V_16 , V_9 ) ;
V_5 = F_5 ( V_2 , V_11 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_4 ( V_2 , V_11 , V_18 , V_9 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_4 ( V_2 , V_11 , V_13 ,
V_27 | ( V_3 << 5 ) | V_16 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_5 ( V_2 , V_11 ) ;
if ( V_5 < 0 )
return V_5 ;
return 0 ;
}
static int F_14 ( struct V_19 * V_20 , int V_3 , int V_16 ,
T_2 V_9 )
{
struct V_1 * V_2 = F_8 ( V_20 -> V_21 ) ;
if ( V_2 == NULL )
return - V_22 ;
F_9 ( V_20 -> V_21 , L_2 ,
V_3 , V_16 , V_9 ) ;
return F_13 ( V_2 , V_20 -> V_23 -> V_11 , V_3 , V_16 , V_9 ) ;
}
int F_15 ( struct V_19 * V_20 , int V_3 , int V_16 , T_2 V_9 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_5 ;
F_12 ( & V_25 -> V_26 ) ;
V_5 = F_14 ( V_20 , V_3 , V_16 , V_9 ) ;
F_3 ( & V_25 -> V_26 ) ;
return V_5 ;
}
int F_16 ( struct V_19 * V_20 , T_3 * V_3 )
{
F_17 ( V_28 , V_29 , ( V_3 [ 0 ] << 8 ) | V_3 [ 1 ] ) ;
F_17 ( V_28 , V_30 , ( V_3 [ 2 ] << 8 ) | V_3 [ 3 ] ) ;
F_17 ( V_28 , V_31 , ( V_3 [ 4 ] << 8 ) | V_3 [ 5 ] ) ;
return 0 ;
}
int F_18 ( struct V_19 * V_20 , T_3 * V_3 )
{
int V_12 ;
int V_5 ;
for ( V_12 = 0 ; V_12 < 6 ; V_12 ++ ) {
int V_32 ;
F_17 ( V_33 , V_34 ,
V_35 | ( V_12 << 8 ) | V_3 [ V_12 ] ) ;
for ( V_32 = 0 ; V_32 < 16 ; V_32 ++ ) {
V_5 = F_19 ( V_33 , V_34 ) ;
if ( ( V_5 & V_35 ) == 0 )
break;
}
if ( V_32 == 16 )
return - V_15 ;
}
return 0 ;
}
static int F_20 ( struct V_19 * V_20 , int V_3 , int V_4 )
{
if ( V_3 >= 0 )
return F_7 ( V_20 , V_3 , V_4 ) ;
return 0xffff ;
}
static int F_21 ( struct V_19 * V_20 , int V_3 , int V_4 ,
T_2 V_9 )
{
if ( V_3 >= 0 )
return F_14 ( V_20 , V_3 , V_4 , V_9 ) ;
return 0 ;
}
static int F_22 ( struct V_19 * V_20 )
{
int V_5 ;
unsigned long V_36 ;
V_5 = F_19 ( V_28 , V_37 ) ;
F_17 ( V_28 , V_37 ,
V_5 & ~ V_38 ) ;
V_36 = V_39 + 1 * V_40 ;
while ( F_23 ( V_39 , V_36 ) ) {
V_5 = F_19 ( V_28 , V_41 ) ;
F_24 ( 1000 , 2000 ) ;
if ( ( V_5 & V_42 ) !=
V_43 )
return 0 ;
}
return - V_15 ;
}
static int F_25 ( struct V_19 * V_20 )
{
int V_5 ;
unsigned long V_36 ;
V_5 = F_19 ( V_28 , V_37 ) ;
F_17 ( V_28 , V_37 , V_5 | V_38 ) ;
V_36 = V_39 + 1 * V_40 ;
while ( F_23 ( V_39 , V_36 ) ) {
V_5 = F_19 ( V_28 , V_41 ) ;
F_24 ( 1000 , 2000 ) ;
if ( ( V_5 & V_42 ) ==
V_43 )
return 0 ;
}
return - V_15 ;
}
static void F_26 ( struct V_44 * V_45 )
{
struct V_24 * V_25 ;
V_25 = F_27 ( V_45 , struct V_24 , V_46 ) ;
if ( F_28 ( & V_25 -> V_47 ) ) {
struct V_19 * V_20 = ( (struct V_19 * ) V_25 ) - 1 ;
if ( F_25 ( V_20 ) == 0 )
V_25 -> V_48 = 0 ;
F_3 ( & V_25 -> V_47 ) ;
}
}
static void F_29 ( unsigned long V_49 )
{
struct V_24 * V_25 = ( void * ) V_49 ;
F_30 ( & V_25 -> V_46 ) ;
}
static int F_31 ( struct V_19 * V_20 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_5 ;
F_12 ( & V_25 -> V_47 ) ;
if ( ! V_25 -> V_48 ) {
V_5 = F_22 ( V_20 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_25 -> V_47 ) ;
return V_5 ;
}
V_25 -> V_48 = 1 ;
} else {
F_32 ( & V_25 -> V_50 ) ;
V_5 = 0 ;
}
return V_5 ;
}
static void F_33 ( struct V_19 * V_20 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
F_34 ( & V_25 -> V_50 , V_39 + F_35 ( 10 ) ) ;
F_3 ( & V_25 -> V_47 ) ;
}
void F_36 ( struct V_19 * V_20 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
F_37 ( & V_25 -> V_47 ) ;
F_38 ( & V_25 -> V_46 , F_26 ) ;
F_39 ( & V_25 -> V_50 ) ;
V_25 -> V_50 . V_51 = ( unsigned long ) V_25 ;
V_25 -> V_50 . V_52 = F_29 ;
}
int F_40 ( struct V_19 * V_20 , int V_3 , int V_4 )
{
int V_5 ;
V_5 = F_31 ( V_20 ) ;
if ( V_5 >= 0 ) {
V_5 = F_10 ( V_20 , V_3 , V_4 ) ;
F_33 ( V_20 ) ;
}
return V_5 ;
}
int F_41 ( struct V_19 * V_20 , int V_3 ,
int V_4 , T_2 V_9 )
{
int V_5 ;
V_5 = F_31 ( V_20 ) ;
if ( V_5 >= 0 ) {
V_5 = F_15 ( V_20 , V_3 , V_4 , V_9 ) ;
F_33 ( V_20 ) ;
}
return V_5 ;
}
void F_42 ( struct V_19 * V_20 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_53 ; V_12 ++ ) {
struct V_54 * V_55 ;
int V_56 ( V_57 ) ;
int V_58 ;
int V_59 ;
int V_60 ;
int V_61 ;
V_55 = V_20 -> V_62 [ V_12 ] ;
if ( V_55 == NULL )
continue;
V_58 = 0 ;
if ( V_55 -> V_63 & V_64 ) {
V_57 = F_10 ( V_20 , F_43 ( V_12 ) ,
V_65 ) ;
if ( V_57 < 0 )
continue;
V_58 = ! ! ( V_57 & V_66 ) ;
}
if ( ! V_58 ) {
if ( F_44 ( V_55 ) ) {
F_45 ( V_55 , L_3 ) ;
F_46 ( V_55 ) ;
}
continue;
}
switch ( V_57 & V_67 ) {
case V_68 :
V_59 = 10 ;
break;
case V_69 :
V_59 = 100 ;
break;
case V_70 :
V_59 = 1000 ;
break;
default:
V_59 = - 1 ;
break;
}
V_60 = ( V_57 & V_71 ) ? 1 : 0 ;
V_61 = ( V_57 & V_72 ) ? 1 : 0 ;
if ( ! F_44 ( V_55 ) ) {
F_45 ( V_55 ,
L_4 ,
V_59 ,
V_60 ? L_5 : L_6 ,
V_61 ? L_7 : L_8 ) ;
F_47 ( V_55 ) ;
}
}
}
static bool F_48 ( struct V_19 * V_20 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
switch ( V_25 -> V_73 ) {
case V_74 :
case V_75 :
case V_76 :
case V_77 :
return true ;
}
return false ;
}
static bool F_49 ( struct V_19 * V_20 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
switch ( V_25 -> V_73 ) {
case V_78 :
case V_79 :
return true ;
}
return false ;
}
static bool F_50 ( struct V_19 * V_20 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
switch ( V_25 -> V_73 ) {
case V_80 :
case V_81 :
case V_82 :
case V_83 :
return true ;
}
return false ;
}
static bool F_51 ( struct V_19 * V_20 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
switch ( V_25 -> V_73 ) {
case V_84 :
case V_85 :
case V_86 :
return true ;
}
return false ;
}
static bool F_52 ( struct V_19 * V_20 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
switch ( V_25 -> V_73 ) {
case V_87 :
case V_88 :
case V_89 :
case V_90 :
case V_91 :
case V_92 :
case V_93 :
case V_94 :
return true ;
}
return false ;
}
static bool F_53 ( struct V_19 * V_20 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
switch ( V_25 -> V_73 ) {
case V_95 :
case V_96 :
case V_97 :
case V_98 :
return true ;
}
return false ;
}
static bool F_54 ( struct V_19 * V_20 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
switch ( V_25 -> V_73 ) {
case V_99 :
case V_100 :
case V_101 :
case V_102 :
return true ;
}
return false ;
}
static int F_55 ( struct V_19 * V_20 )
{
int V_5 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < 10 ; V_12 ++ ) {
V_5 = F_7 ( V_20 , V_28 , V_103 ) ;
if ( ( V_5 & V_104 ) == 0 )
return 0 ;
}
return - V_15 ;
}
static int F_56 ( struct V_19 * V_20 , int V_105 )
{
int V_5 ;
if ( F_54 ( V_20 ) )
V_105 = ( V_105 + 1 ) << 5 ;
V_5 = F_14 ( V_20 , V_28 , V_103 ,
V_106 |
V_107 | V_105 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_55 ( V_20 ) ;
if ( V_5 < 0 )
return V_5 ;
return 0 ;
}
static void F_57 ( struct V_19 * V_20 , int V_108 , T_1 * V_9 )
{
T_1 V_109 ;
int V_5 ;
* V_9 = 0 ;
V_5 = F_14 ( V_20 , V_28 , V_103 ,
V_110 |
V_107 | V_108 ) ;
if ( V_5 < 0 )
return;
V_5 = F_55 ( V_20 ) ;
if ( V_5 < 0 )
return;
V_5 = F_7 ( V_20 , V_28 , V_111 ) ;
if ( V_5 < 0 )
return;
V_109 = V_5 << 16 ;
V_5 = F_7 ( V_20 , V_28 , V_112 ) ;
if ( V_5 < 0 )
return;
* V_9 = V_109 | V_5 ;
}
static bool F_58 ( struct V_19 * V_20 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
switch ( V_25 -> V_73 ) {
case V_79 : case V_85 :
case V_86 : case V_95 :
case V_99 : case V_100 :
case V_91 : case V_92 :
case V_102 :
return true ;
default:
return false ;
}
}
static void F_59 ( struct V_19 * V_20 ,
int V_113 ,
struct V_114 * V_115 ,
int V_105 , T_4 * V_51 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_113 ; V_12 ++ ) {
memcpy ( V_51 + V_12 * V_116 ,
V_115 [ V_12 ] . string , V_116 ) ;
}
}
static T_5 F_60 ( struct V_19 * V_20 ,
int V_108 ,
struct V_114 * V_115 ,
int V_105 )
{
struct V_114 * V_117 = V_115 + V_108 ;
T_1 V_118 ;
T_1 V_119 = 0 ;
int V_5 ;
T_6 V_120 ;
if ( V_117 -> V_16 >= 0x100 ) {
V_5 = F_7 ( V_20 , F_43 ( V_105 ) ,
V_117 -> V_16 - 0x100 ) ;
if ( V_5 < 0 )
return V_121 ;
V_118 = V_5 ;
if ( V_117 -> V_122 == 4 ) {
V_5 = F_7 ( V_20 , F_43 ( V_105 ) ,
V_117 -> V_16 - 0x100 + 1 ) ;
if ( V_5 < 0 )
return V_121 ;
V_119 = V_5 ;
}
} else {
F_57 ( V_20 , V_117 -> V_16 , & V_118 ) ;
if ( V_117 -> V_122 == 8 )
F_57 ( V_20 , V_117 -> V_16 + 1 , & V_119 ) ;
}
V_120 = ( ( ( T_6 ) V_119 ) << 16 ) | V_118 ;
return V_120 ;
}
static void F_61 ( struct V_19 * V_20 ,
int V_113 ,
struct V_114 * V_115 ,
int V_105 , T_5 * V_51 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_5 ;
int V_12 ;
F_12 ( & V_25 -> V_26 ) ;
V_5 = F_56 ( V_20 , V_105 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_25 -> V_26 ) ;
return;
}
for ( V_12 = 0 ; V_12 < V_113 ; V_12 ++ )
V_51 [ V_12 ] = F_60 ( V_20 , V_12 , V_115 , V_105 ) ;
F_3 ( & V_25 -> V_26 ) ;
}
void
F_62 ( struct V_19 * V_20 , int V_105 , T_4 * V_51 )
{
if ( F_58 ( V_20 ) )
F_59 ( V_20 , F_63 ( V_123 ) ,
V_123 , V_105 , V_51 ) ;
else
F_59 ( V_20 , F_63 ( V_123 ) - 3 ,
V_123 , V_105 , V_51 ) ;
}
int F_64 ( struct V_19 * V_20 )
{
if ( F_58 ( V_20 ) )
return F_63 ( V_123 ) ;
return F_63 ( V_123 ) - 3 ;
}
void
F_65 ( struct V_19 * V_20 ,
int V_105 , T_5 * V_51 )
{
if ( F_58 ( V_20 ) )
F_61 (
V_20 , F_63 ( V_123 ) ,
V_123 , V_105 , V_51 ) ;
else
F_61 (
V_20 , F_63 ( V_123 ) - 3 ,
V_123 , V_105 , V_51 ) ;
}
int F_66 ( struct V_19 * V_20 , int V_105 )
{
return 32 * sizeof( T_2 ) ;
}
void F_67 ( struct V_19 * V_20 , int V_105 ,
struct V_124 * V_125 , void * V_126 )
{
T_2 * V_127 = V_126 ;
int V_12 ;
V_125 -> V_128 = 0 ;
memset ( V_127 , 0xff , 32 * sizeof( T_2 ) ) ;
for ( V_12 = 0 ; V_12 < 32 ; V_12 ++ ) {
int V_5 ;
V_5 = F_10 ( V_20 , F_43 ( V_105 ) , V_12 ) ;
if ( V_5 >= 0 )
V_127 [ V_12 ] = V_5 ;
}
}
int F_68 ( struct V_19 * V_20 , int * V_129 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_5 ;
int V_9 ;
* V_129 = 0 ;
F_12 ( & V_25 -> V_26 ) ;
V_5 = F_21 ( V_20 , 0x0 , 0x16 , 0x6 ) ;
if ( V_5 < 0 )
goto error;
V_5 = F_20 ( V_20 , 0x0 , 0x1a ) ;
if ( V_5 < 0 )
goto error;
V_5 = F_21 ( V_20 , 0x0 , 0x1a , V_5 | ( 1 << 5 ) ) ;
if ( V_5 < 0 )
goto error;
F_24 ( 10000 , 12000 ) ;
V_9 = F_20 ( V_20 , 0x0 , 0x1a ) ;
if ( V_9 < 0 ) {
V_5 = V_9 ;
goto error;
}
V_5 = F_21 ( V_20 , 0x0 , 0x1a , V_5 & ~ ( 1 << 5 ) ) ;
if ( V_5 < 0 )
goto error;
* V_129 = ( ( V_9 & 0x1f ) - 5 ) * 5 ;
error:
F_21 ( V_20 , 0x0 , 0x16 , 0x0 ) ;
F_3 ( & V_25 -> V_26 ) ;
return V_5 ;
}
static int F_69 ( struct V_19 * V_20 , int V_16 , int V_130 ,
T_2 V_131 )
{
unsigned long V_36 = V_39 + V_40 / 10 ;
while ( F_23 ( V_39 , V_36 ) ) {
int V_5 ;
V_5 = F_7 ( V_20 , V_16 , V_130 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( ! ( V_5 & V_131 ) )
return 0 ;
F_24 ( 1000 , 2000 ) ;
}
return - V_15 ;
}
static int F_70 ( struct V_19 * V_20 , int V_16 , int V_130 , T_2 V_131 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_5 ;
F_12 ( & V_25 -> V_26 ) ;
V_5 = F_69 ( V_20 , V_16 , V_130 , V_131 ) ;
F_3 ( & V_25 -> V_26 ) ;
return V_5 ;
}
static int F_71 ( struct V_19 * V_20 )
{
return F_69 ( V_20 , V_33 , V_132 ,
V_133 ) ;
}
int F_72 ( struct V_19 * V_20 )
{
return F_70 ( V_20 , V_33 , V_134 ,
V_135 ) ;
}
int F_73 ( struct V_19 * V_20 )
{
return F_70 ( V_20 , V_33 , V_134 ,
V_136 ) ;
}
static int F_74 ( struct V_19 * V_20 )
{
return F_69 ( V_20 , V_28 , V_137 ,
V_138 ) ;
}
static int F_75 ( struct V_19 * V_20 )
{
return F_69 ( V_20 , V_33 , V_139 ,
V_140 ) ;
}
static int F_76 ( struct V_19 * V_20 , int V_3 ,
int V_4 )
{
int V_5 ;
V_5 = F_14 ( V_20 , V_33 , V_132 ,
V_141 | ( V_3 << 5 ) |
V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_71 ( V_20 ) ;
if ( V_5 < 0 )
return V_5 ;
return F_7 ( V_20 , V_33 , V_142 ) ;
}
static int F_77 ( struct V_19 * V_20 , int V_3 ,
int V_4 , T_2 V_9 )
{
int V_5 ;
V_5 = F_14 ( V_20 , V_33 , V_142 , V_9 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_14 ( V_20 , V_33 , V_132 ,
V_143 | ( V_3 << 5 ) |
V_4 ) ;
return F_71 ( V_20 ) ;
}
int F_78 ( struct V_19 * V_20 , int V_105 , struct V_144 * V_145 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_16 ;
F_12 ( & V_25 -> V_26 ) ;
V_16 = F_76 ( V_20 , V_105 , 16 ) ;
if ( V_16 < 0 )
goto V_146;
V_145 -> V_147 = ! ! ( V_16 & 0x0200 ) ;
V_145 -> V_148 = ! ! ( V_16 & 0x0100 ) ;
V_16 = F_7 ( V_20 , F_43 ( V_105 ) , V_65 ) ;
if ( V_16 < 0 )
goto V_146;
V_145 -> V_149 = ! ! ( V_16 & V_150 ) ;
V_16 = 0 ;
V_146:
F_3 ( & V_25 -> V_26 ) ;
return V_16 ;
}
int F_79 ( struct V_19 * V_20 , int V_105 ,
struct V_151 * V_152 , struct V_144 * V_145 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_16 ;
int V_5 ;
F_12 ( & V_25 -> V_26 ) ;
V_5 = F_76 ( V_20 , V_105 , 16 ) ;
if ( V_5 < 0 )
goto V_146;
V_16 = V_5 & ~ 0x0300 ;
if ( V_145 -> V_147 )
V_16 |= 0x0200 ;
if ( V_145 -> V_148 )
V_16 |= 0x0100 ;
V_5 = F_77 ( V_20 , V_105 , 16 , V_16 ) ;
V_146:
F_3 ( & V_25 -> V_26 ) ;
return V_5 ;
}
static int F_80 ( struct V_19 * V_20 , int V_153 , T_2 V_154 )
{
int V_5 ;
V_5 = F_14 ( V_20 , V_28 , 0x01 , V_153 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_14 ( V_20 , V_28 , V_137 , V_154 ) ;
if ( V_5 < 0 )
return V_5 ;
return F_74 ( V_20 ) ;
}
static int F_81 ( struct V_19 * V_20 , int V_153 )
{
int V_5 ;
V_5 = F_74 ( V_20 ) ;
if ( V_5 < 0 )
return V_5 ;
return F_80 ( V_20 , V_153 , V_155 ) ;
}
static int F_82 ( struct V_19 * V_20 , int V_105 , T_3 V_156 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_16 , V_5 = 0 ;
T_3 V_157 ;
F_12 ( & V_25 -> V_26 ) ;
V_16 = F_7 ( V_20 , F_43 ( V_105 ) , V_158 ) ;
if ( V_16 < 0 ) {
V_5 = V_16 ;
goto abort;
}
V_157 = V_16 & V_159 ;
if ( V_157 != V_156 ) {
if ( V_157 >= V_160 &&
V_156 <= V_161 ) {
V_5 = F_81 ( V_20 , V_25 -> V_153 [ V_105 ] ) ;
if ( V_5 )
goto abort;
}
V_16 = ( V_16 & ~ V_159 ) | V_156 ;
V_5 = F_14 ( V_20 , F_43 ( V_105 ) , V_158 ,
V_16 ) ;
}
abort:
F_3 ( & V_25 -> V_26 ) ;
return V_5 ;
}
static int F_83 ( struct V_19 * V_20 , int V_105 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
T_3 V_153 = V_25 -> V_153 [ V_105 ] ;
T_2 V_16 = V_153 << 12 ;
if ( F_84 ( V_20 , V_105 ) )
V_16 |= V_20 -> V_162 ;
else
V_16 |= ( V_25 -> V_163 [ V_153 ] |
( 1 << F_85 ( V_20 ) ) ) & ~ ( 1 << V_105 ) ;
return F_14 ( V_20 , F_43 ( V_105 ) , V_164 , V_16 ) ;
}
static int F_86 ( struct V_19 * V_20 , int V_153 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_105 ;
T_1 V_131 ;
int V_5 ;
V_131 = V_20 -> V_162 ;
while ( V_131 ) {
V_105 = F_87 ( V_131 ) ;
V_131 &= ~ ( 1 << V_105 ) ;
if ( V_25 -> V_153 [ V_105 ] != V_153 )
continue;
V_5 = F_83 ( V_20 , V_105 ) ;
if ( V_5 )
return V_5 ;
}
return F_81 ( V_20 , V_153 ) ;
}
int F_88 ( struct V_19 * V_20 , int V_105 , T_1 V_165 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_5 = 0 ;
T_1 V_166 ;
int V_153 ;
V_153 = V_25 -> V_153 [ V_105 ] ;
V_166 = V_165 & ~ ( 1 << V_105 ) ;
if ( V_166 )
V_153 = V_25 -> V_153 [ F_87 ( V_166 ) ] ;
V_166 = V_25 -> V_163 [ V_153 ] | ( 1 << V_105 ) ;
if ( V_166 != V_165 ) {
F_89 ( V_20 -> V_62 [ V_105 ] ,
L_9 ,
V_153 , V_165 , V_166 ) ;
return - V_22 ;
}
F_12 ( & V_25 -> V_26 ) ;
V_25 -> V_163 [ V_153 ] = V_165 ;
if ( V_153 != V_25 -> V_153 [ V_105 ] ) {
V_25 -> V_167 |= 1 << V_25 -> V_153 [ V_105 ] ;
V_25 -> V_153 [ V_105 ] = V_153 ;
V_5 = F_86 ( V_20 , V_153 ) ;
}
F_3 ( & V_25 -> V_26 ) ;
return V_5 ;
}
int F_90 ( struct V_19 * V_20 , int V_105 , T_1 V_165 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
T_3 V_153 , V_168 ;
int V_5 ;
V_153 = V_25 -> V_153 [ V_105 ] ;
if ( V_25 -> V_163 [ V_153 ] != V_165 ) {
F_89 ( V_20 -> V_62 [ V_105 ] ,
L_10 ,
V_153 , V_165 , V_25 -> V_163 [ V_153 ] ) ;
return - V_22 ;
}
if ( V_165 == ( 1 << V_105 ) )
return 0 ;
F_12 ( & V_25 -> V_26 ) ;
V_168 = F_87 ( V_25 -> V_167 ) ;
V_25 -> V_153 [ V_105 ] = V_168 ;
V_25 -> V_167 &= ~ ( 1 << V_168 ) ;
V_25 -> V_163 [ V_153 ] &= ~ ( 1 << V_105 ) ;
V_25 -> V_163 [ V_168 ] = 1 << V_105 ;
V_5 = F_86 ( V_20 , V_153 ) ;
if ( ! V_5 )
V_5 = F_86 ( V_20 , V_168 ) ;
F_3 ( & V_25 -> V_26 ) ;
return V_5 ;
}
int F_91 ( struct V_19 * V_20 , int V_105 , T_3 V_156 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_169 ;
switch ( V_156 ) {
case V_170 :
V_169 = V_171 ;
break;
case V_172 :
case V_173 :
V_169 = V_161 ;
break;
case V_174 :
V_169 = V_160 ;
break;
case V_175 :
default:
V_169 = V_176 ;
break;
}
F_92 ( V_20 -> V_62 [ V_105 ] , L_11 , V_156 , V_169 ) ;
V_25 -> V_177 [ V_105 ] = V_169 ;
F_93 ( V_105 , & V_25 -> V_178 ) ;
F_30 ( & V_25 -> V_179 ) ;
return 0 ;
}
static int F_94 ( struct V_19 * V_20 ,
const unsigned char * V_3 )
{
int V_12 , V_5 ;
for ( V_12 = 0 ; V_12 < 3 ; V_12 ++ ) {
V_5 = F_14 (
V_20 , V_28 , V_180 + V_12 ,
( V_3 [ V_12 * 2 ] << 8 ) | V_3 [ V_12 * 2 + 1 ] ) ;
if ( V_5 < 0 )
return V_5 ;
}
return 0 ;
}
static int F_95 ( struct V_19 * V_20 , unsigned char * V_3 )
{
int V_12 , V_5 ;
for ( V_12 = 0 ; V_12 < 3 ; V_12 ++ ) {
V_5 = F_7 ( V_20 , V_28 ,
V_180 + V_12 ) ;
if ( V_5 < 0 )
return V_5 ;
V_3 [ V_12 * 2 ] = V_5 >> 8 ;
V_3 [ V_12 * 2 + 1 ] = V_5 & 0xff ;
}
return 0 ;
}
static int F_96 ( struct V_19 * V_20 , int V_105 ,
const unsigned char * V_3 , int V_156 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
T_3 V_153 = V_25 -> V_153 [ V_105 ] ;
int V_5 ;
V_5 = F_74 ( V_20 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_94 ( V_20 , V_3 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_14 ( V_20 , V_28 , V_181 ,
( 0x10 << V_105 ) | V_156 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_80 ( V_20 , V_153 , V_182 ) ;
return V_5 ;
}
int F_97 ( struct V_19 * V_20 , int V_105 ,
const unsigned char * V_3 , T_2 V_183 )
{
int V_156 = F_98 ( V_3 ) ?
V_184 :
V_185 ;
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_5 ;
F_12 ( & V_25 -> V_26 ) ;
V_5 = F_96 ( V_20 , V_105 , V_3 , V_156 ) ;
F_3 ( & V_25 -> V_26 ) ;
return V_5 ;
}
int F_99 ( struct V_19 * V_20 , int V_105 ,
const unsigned char * V_3 , T_2 V_183 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_5 ;
F_12 ( & V_25 -> V_26 ) ;
V_5 = F_96 ( V_20 , V_105 , V_3 ,
V_186 ) ;
F_3 ( & V_25 -> V_26 ) ;
return V_5 ;
}
static int F_100 ( struct V_19 * V_20 , int V_105 ,
unsigned char * V_3 , bool * V_187 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
T_3 V_153 = V_25 -> V_153 [ V_105 ] ;
int V_5 , V_156 ;
V_5 = F_74 ( V_20 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_94 ( V_20 , V_3 ) ;
if ( V_5 < 0 )
return V_5 ;
do {
V_5 = F_80 ( V_20 , V_153 , V_188 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_7 ( V_20 , V_28 , V_181 ) ;
if ( V_5 < 0 )
return V_5 ;
V_156 = V_5 & V_189 ;
if ( V_156 == V_186 )
return - V_190 ;
} while ( ! ( ( ( V_5 >> 4 ) & 0xff ) & ( 1 << V_105 ) ) );
V_5 = F_95 ( V_20 , V_3 ) ;
if ( V_5 < 0 )
return V_5 ;
* V_187 = V_156 == ( F_98 ( V_3 ) ?
V_184 :
V_185 ) ;
return 0 ;
}
int F_101 ( struct V_19 * V_20 , int V_105 ,
unsigned char * V_3 , bool * V_187 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_5 ;
F_12 ( & V_25 -> V_26 ) ;
V_5 = F_100 ( V_20 , V_105 , V_3 , V_187 ) ;
F_3 ( & V_25 -> V_26 ) ;
return V_5 ;
}
static void F_102 ( struct V_44 * V_191 )
{
struct V_24 * V_25 ;
struct V_19 * V_20 ;
int V_105 ;
V_25 = F_27 ( V_191 , struct V_24 , V_179 ) ;
V_20 = ( (struct V_19 * ) V_25 ) - 1 ;
while ( V_25 -> V_178 ) {
V_105 = F_87 ( V_25 -> V_178 ) ;
F_103 ( V_105 , & V_25 -> V_178 ) ;
F_82 ( V_20 , V_105 , V_25 -> V_177 [ V_105 ] ) ;
}
}
static int F_104 ( struct V_19 * V_20 , int V_105 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_5 , V_153 ;
T_2 V_16 ;
F_12 ( & V_25 -> V_26 ) ;
if ( F_54 ( V_20 ) || F_53 ( V_20 ) ||
F_51 ( V_20 ) || F_50 ( V_20 ) ||
F_52 ( V_20 ) || F_49 ( V_20 ) ||
F_48 ( V_20 ) ) {
V_16 = F_7 ( V_20 , F_43 ( V_105 ) , V_192 ) ;
if ( F_84 ( V_20 , V_105 ) ||
V_20 -> V_193 & ( 1 << V_105 ) ) {
V_16 |= V_194 |
V_195 |
V_196 |
V_197 ;
if ( F_48 ( V_20 ) )
V_16 |= V_198 ;
else
V_16 |= V_199 ;
} else {
V_16 |= V_200 ;
}
V_5 = F_14 ( V_20 , F_43 ( V_105 ) ,
V_192 , V_16 ) ;
if ( V_5 )
goto abort;
}
V_16 = 0 ;
if ( F_54 ( V_20 ) || F_53 ( V_20 ) ||
F_51 ( V_20 ) || F_50 ( V_20 ) ||
F_49 ( V_20 ) || F_48 ( V_20 ) ||
F_52 ( V_20 ) )
V_16 = V_201 |
V_202 | V_203 |
V_176 ;
if ( F_84 ( V_20 , V_105 ) ) {
if ( F_49 ( V_20 ) || F_52 ( V_20 ) )
V_16 |= V_204 ;
if ( F_54 ( V_20 ) || F_53 ( V_20 ) ||
F_51 ( V_20 ) || F_50 ( V_20 ) ) {
if ( V_20 -> V_205 -> V_206 == V_207 )
V_16 |= V_208 ;
else
V_16 |= V_209 ;
}
if ( F_54 ( V_20 ) || F_53 ( V_20 ) ||
F_51 ( V_20 ) || F_50 ( V_20 ) ||
F_49 ( V_20 ) || F_48 ( V_20 ) ||
F_52 ( V_20 ) ) {
if ( V_20 -> V_205 -> V_206 == V_207 )
V_16 |= V_210 ;
}
}
if ( F_54 ( V_20 ) || F_53 ( V_20 ) ||
F_51 ( V_20 ) || F_50 ( V_20 ) ||
F_49 ( V_20 ) || F_48 ( V_20 ) ) {
if ( V_20 -> V_193 & ( 1 << V_105 ) )
V_16 |= V_209 ;
if ( V_105 == F_85 ( V_20 ) )
V_16 |= V_211 |
V_212 ;
}
if ( V_16 ) {
V_5 = F_14 ( V_20 , F_43 ( V_105 ) ,
V_158 , V_16 ) ;
if ( V_5 )
goto abort;
}
V_16 = 0 ;
if ( F_54 ( V_20 ) || F_53 ( V_20 ) ||
F_51 ( V_20 ) || F_50 ( V_20 ) ||
F_49 ( V_20 ) )
V_16 = V_213 ;
if ( F_54 ( V_20 ) || F_53 ( V_20 ) ||
F_51 ( V_20 ) )
V_16 |= V_214 ;
if ( F_49 ( V_20 ) || F_52 ( V_20 ) ) {
V_16 |= F_85 ( V_20 ) ;
if ( V_105 == F_85 ( V_20 ) )
V_16 |= V_215 ;
}
if ( V_16 ) {
V_5 = F_14 ( V_20 , F_43 ( V_105 ) ,
V_216 , V_16 ) ;
if ( V_5 )
goto abort;
}
V_5 = F_14 ( V_20 , F_43 ( V_105 ) , V_217 ,
1 << V_105 ) ;
if ( V_5 )
goto abort;
V_5 = F_14 ( V_20 , F_43 ( V_105 ) , V_218 ,
0x0000 ) ;
if ( V_5 )
goto abort;
if ( F_54 ( V_20 ) || F_53 ( V_20 ) ||
F_51 ( V_20 ) || F_50 ( V_20 ) ) {
V_5 = F_14 ( V_20 , F_43 ( V_105 ) ,
V_219 , 0x0000 ) ;
if ( V_5 )
goto abort;
V_5 = F_14 ( V_20 , F_43 ( V_105 ) ,
V_220 , 0x0000 ) ;
V_5 = F_14 ( V_20 , F_43 ( V_105 ) ,
V_221 , 0x0000 ) ;
if ( V_5 )
goto abort;
V_5 = F_14 ( V_20 , F_43 ( V_105 ) ,
V_222 , V_223 ) ;
if ( V_5 )
goto abort;
V_5 = F_14 ( V_20 , F_43 ( V_105 ) ,
V_224 , 0x3210 ) ;
if ( V_5 )
goto abort;
V_5 = F_14 ( V_20 , F_43 ( V_105 ) ,
V_225 , 0x7654 ) ;
if ( V_5 )
goto abort;
}
if ( F_54 ( V_20 ) || F_53 ( V_20 ) ||
F_51 ( V_20 ) || F_50 ( V_20 ) ||
F_52 ( V_20 ) || F_49 ( V_20 ) ) {
V_5 = F_14 ( V_20 , F_43 ( V_105 ) ,
V_226 , 0x0001 ) ;
if ( V_5 )
goto abort;
}
V_5 = F_14 ( V_20 , F_43 ( V_105 ) , V_227 , 0x0000 ) ;
if ( V_5 )
goto abort;
V_153 = F_87 ( V_25 -> V_167 ) ;
V_25 -> V_153 [ V_105 ] = V_153 ;
V_25 -> V_167 &= ~ ( 1 << V_153 ) ;
if ( ! F_84 ( V_20 , V_105 ) )
V_25 -> V_163 [ V_153 ] = 1 << V_105 ;
V_5 = F_83 ( V_20 , V_105 ) ;
if ( V_5 )
goto abort;
V_5 = F_14 ( V_20 , F_43 ( V_105 ) , V_228 ,
0x0000 ) ;
abort:
F_3 ( & V_25 -> V_26 ) ;
return V_5 ;
}
int F_105 ( struct V_19 * V_20 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_5 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_25 -> V_229 ; V_12 ++ ) {
V_5 = F_104 ( V_20 , V_12 ) ;
if ( V_5 < 0 )
return V_5 ;
}
return 0 ;
}
static int F_106 ( struct V_230 * V_117 , void * V_127 )
{
struct V_19 * V_20 = V_117 -> V_231 ;
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_16 , V_105 ;
F_107 ( V_117 , L_12 ) ;
for ( V_105 = 0 ; V_105 < V_25 -> V_229 ; V_105 ++ )
F_108 ( V_117 , L_13 , V_105 ) ;
F_107 ( V_117 , L_14 ) ;
for ( V_16 = 0 ; V_16 < 32 ; V_16 ++ ) {
F_108 ( V_117 , L_15 , V_16 ) ;
F_108 ( V_117 , L_16 ,
F_10 ( V_20 , V_28 , V_16 ) ,
F_10 ( V_20 , V_33 , V_16 ) ) ;
for ( V_105 = 0 ; V_105 < V_25 -> V_229 ; V_105 ++ )
F_108 ( V_117 , L_17 ,
F_10 ( V_20 , F_43 ( V_105 ) , V_16 ) ) ;
F_107 ( V_117 , L_14 ) ;
}
return 0 ;
}
static int F_109 ( struct V_232 * V_232 , struct V_233 * V_233 )
{
return F_110 ( V_233 , F_106 , V_232 -> V_234 ) ;
}
static void F_111 ( struct V_230 * V_117 )
{
F_107 ( V_117 , L_18 ) ;
}
static void F_112 ( struct V_230 * V_117 , int V_235 ,
unsigned char * V_3 , int V_51 )
{
bool V_236 = ! ! ( V_51 & V_237 ) ;
int V_238 = ( ( V_51 & V_239 ) >>
V_240 ) ;
int V_156 = V_51 & V_189 ;
F_108 ( V_117 , L_19 ,
V_235 , ( V_236 ? L_20 : L_21 ) , & V_238 , V_156 , V_3 ) ;
}
static int F_113 ( struct V_230 * V_117 , struct V_19 * V_20 ,
int V_235 )
{
unsigned char V_241 [] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
unsigned char V_3 [ 6 ] ;
int V_5 , V_51 , V_156 ;
V_5 = F_94 ( V_20 , V_241 ) ;
if ( V_5 < 0 )
return V_5 ;
do {
V_5 = F_80 ( V_20 , V_235 , V_188 ) ;
if ( V_5 < 0 )
return V_5 ;
V_51 = F_7 ( V_20 , V_28 , V_181 ) ;
if ( V_51 < 0 )
return V_51 ;
V_156 = V_51 & V_189 ;
if ( V_156 == V_186 )
break;
V_5 = F_95 ( V_20 , V_3 ) ;
if ( V_5 < 0 )
return V_5 ;
F_112 ( V_117 , V_235 , V_3 , V_51 ) ;
} while ( V_156 != V_186 );
return 0 ;
}
static int F_114 ( struct V_230 * V_117 , void * V_127 )
{
struct V_19 * V_20 = V_117 -> V_231 ;
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_235 ;
F_111 ( V_117 ) ;
for ( V_235 = 0 ; V_235 < 255 ; V_235 ++ ) {
F_12 ( & V_25 -> V_26 ) ;
F_113 ( V_117 , V_20 , V_235 ) ;
F_3 ( & V_25 -> V_26 ) ;
}
return 0 ;
}
static int F_115 ( struct V_232 * V_232 , struct V_233 * V_233 )
{
return F_110 ( V_233 , F_114 , V_232 -> V_234 ) ;
}
static void F_116 ( struct V_230 * V_117 ,
struct V_24 * V_25 )
{
int V_105 ;
F_107 ( V_117 , L_22 ) ;
for ( V_105 = 0 ; V_105 < V_25 -> V_229 ; V_105 ++ )
F_108 ( V_117 , L_23 , V_105 ) ;
F_107 ( V_117 , L_14 ) ;
}
static int F_117 ( struct V_230 * V_117 , void * V_127 )
{
struct V_19 * V_20 = V_117 -> V_231 ;
struct V_24 * V_25 = F_11 ( V_20 ) ;
struct V_114 * V_115 = V_123 ;
int V_105 , V_108 , V_242 ;
T_5 V_120 ;
if ( F_58 ( V_20 ) )
V_242 = F_63 ( V_123 ) ;
else
V_242 = F_63 ( V_123 ) - 3 ;
F_116 ( V_117 , V_25 ) ;
F_12 ( & V_25 -> V_26 ) ;
for ( V_108 = 0 ; V_108 < V_242 ; V_108 ++ ) {
F_108 ( V_117 , L_24 , V_115 [ V_108 ] . string ) ;
for ( V_105 = 0 ; V_105 < V_25 -> V_229 ; V_105 ++ ) {
F_56 ( V_20 , V_105 ) ;
V_120 = F_60 ( V_20 , V_108 , V_115 ,
V_105 ) ;
F_108 ( V_117 , L_25 , V_120 ) ;
}
F_107 ( V_117 , L_14 ) ;
}
F_3 ( & V_25 -> V_26 ) ;
return 0 ;
}
static int F_118 ( struct V_232 * V_232 , struct V_233 * V_233 )
{
return F_110 ( V_233 , F_117 , V_232 -> V_234 ) ;
}
static int F_119 ( struct V_230 * V_117 , void * V_127 )
{
struct V_19 * V_20 = V_117 -> V_231 ;
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_243 , V_5 ;
F_107 ( V_117 , L_26 ) ;
F_12 ( & V_25 -> V_26 ) ;
for ( V_243 = 0 ; V_243 < 32 ; V_243 ++ ) {
V_5 = F_14 (
V_20 , V_33 , V_244 ,
V_243 << V_245 ) ;
if ( V_5 < 0 )
goto V_146;
V_5 = F_7 ( V_20 , V_33 ,
V_244 ) ;
F_108 ( V_117 , L_27 , V_243 ,
V_5 & V_246 ) ;
}
V_146:
F_3 ( & V_25 -> V_26 ) ;
return 0 ;
}
static int F_120 ( struct V_232 * V_232 , struct V_233 * V_233 )
{
return F_110 ( V_233 , F_119 , V_232 -> V_234 ) ;
}
static int F_121 ( struct V_230 * V_117 , void * V_127 )
{
struct V_19 * V_20 = V_117 -> V_231 ;
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_16 , V_5 ;
F_107 ( V_117 , L_28 ) ;
F_12 ( & V_25 -> V_26 ) ;
for ( V_16 = 0 ; V_16 < 0x80 ; V_16 ++ ) {
V_5 = F_14 (
V_20 , V_33 , V_139 ,
V_16 << V_247 ) ;
if ( V_5 < 0 )
goto V_146;
V_5 = F_75 ( V_20 ) ;
if ( V_5 < 0 )
goto V_146;
V_5 = F_7 ( V_20 , V_33 ,
V_139 ) ;
F_108 ( V_117 , L_29 , V_16 ,
V_5 & V_248 ) ;
}
V_146:
F_3 ( & V_25 -> V_26 ) ;
return 0 ;
}
static int F_122 ( struct V_232 * V_232 , struct V_233 * V_233 )
{
return F_110 ( V_233 , F_121 , V_232 -> V_234 ) ;
}
int F_123 ( struct V_19 * V_20 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
char * V_249 ;
F_37 ( & V_25 -> V_26 ) ;
V_25 -> V_73 = F_19 ( F_43 ( 0 ) , V_250 ) & 0xfff0 ;
V_25 -> V_167 = ( 1 << V_53 ) - 1 ;
F_38 ( & V_25 -> V_179 , F_102 ) ;
V_249 = F_124 ( V_251 , L_30 , V_20 -> V_252 ) ;
V_25 -> V_253 = F_125 ( V_249 , NULL ) ;
F_126 ( V_249 ) ;
F_127 ( L_31 , V_254 , V_25 -> V_253 , V_20 ,
& V_255 ) ;
F_127 ( L_32 , V_254 , V_25 -> V_253 , V_20 ,
& V_256 ) ;
F_127 ( L_33 , V_254 , V_25 -> V_253 , V_20 ,
& V_257 ) ;
F_127 ( L_34 , V_254 , V_25 -> V_253 , V_20 ,
& V_258 ) ;
F_127 ( L_35 , V_254 , V_25 -> V_253 , V_20 ,
& V_259 ) ;
return 0 ;
}
int F_128 ( struct V_19 * V_20 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_12 ;
F_17 ( V_28 , V_260 ,
0x0140 | V_261 ) ;
F_17 ( V_28 , V_262 , 0x0000 ) ;
F_17 ( V_28 , V_263 , 0x0000 ) ;
F_17 ( V_28 , V_264 , 0x5555 ) ;
F_17 ( V_28 , V_265 , 0x5555 ) ;
F_17 ( V_28 , V_266 , 0xaaaa ) ;
F_17 ( V_28 , V_267 , 0xaaaa ) ;
F_17 ( V_28 , V_268 , 0xffff ) ;
F_17 ( V_28 , V_269 , 0xffff ) ;
F_17 ( V_28 , V_270 , 0xfa41 ) ;
F_17 ( V_33 , V_271 , 0xffff ) ;
F_17 ( V_33 , V_272 ,
0x7 | V_273 | 0x70 |
V_274 ) ;
for ( V_12 = 0 ; V_12 < 32 ; V_12 ++ ) {
int V_275 = 0x1f ;
if ( V_20 -> V_23 -> V_276 &&
V_12 != V_20 -> V_252 && V_12 < V_20 -> V_205 -> V_23 -> V_277 )
V_275 = V_20 -> V_23 -> V_276 [ V_12 ] & 0x1f ;
F_17 ( V_33 , V_244 ,
V_278 |
( V_12 << V_245 ) |
V_275 ) ;
}
for ( V_12 = 0 ; V_12 < 8 ; V_12 ++ )
F_17 ( V_33 , V_279 ,
0x8000 | ( V_12 << V_280 ) |
( ( 1 << V_25 -> V_229 ) - 1 ) ) ;
for ( V_12 = 0 ; V_12 < 16 ; V_12 ++ )
F_17 ( V_33 , V_281 ,
V_282 |
( V_12 << V_283 ) ) ;
if ( F_54 ( V_20 ) || F_53 ( V_20 ) ||
F_51 ( V_20 ) || F_50 ( V_20 ) ) {
F_17 ( V_33 , V_284 , 0xffff ) ;
F_17 ( V_33 , V_285 , 0x9000 ) ;
for ( V_12 = 0 ; V_12 < 16 ; V_12 ++ )
F_17 ( V_33 , V_286 ,
0x8000 | ( V_12 << 8 ) ) ;
}
if ( F_54 ( V_20 ) || F_53 ( V_20 ) ||
F_51 ( V_20 ) || F_50 ( V_20 ) ||
F_52 ( V_20 ) || F_49 ( V_20 ) ) {
for ( V_12 = 0 ; V_12 < V_25 -> V_229 ; V_12 ++ )
F_17 ( V_33 , V_287 ,
0x9000 | ( V_12 << 8 ) ) ;
}
F_17 ( V_28 , V_103 , V_288 ) ;
F_55 ( V_20 ) ;
return 0 ;
}
int F_129 ( struct V_19 * V_20 , bool V_289 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
T_2 V_290 = ( V_289 ? 0x8800 : 0xc800 ) ;
unsigned long V_36 ;
int V_5 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_25 -> V_229 ; V_12 ++ ) {
V_5 = F_19 ( F_43 ( V_12 ) , V_158 ) ;
F_17 ( F_43 ( V_12 ) , V_158 , V_5 & 0xfffc ) ;
}
F_24 ( 2000 , 4000 ) ;
if ( V_289 )
F_17 ( V_28 , 0x04 , 0xc000 ) ;
else
F_17 ( V_28 , 0x04 , 0xc400 ) ;
V_36 = V_39 + 1 * V_40 ;
while ( F_23 ( V_39 , V_36 ) ) {
V_5 = F_19 ( V_28 , 0x00 ) ;
if ( ( V_5 & V_290 ) == V_290 )
break;
F_24 ( 1000 , 2000 ) ;
}
if ( F_130 ( V_39 , V_36 ) )
return - V_15 ;
return 0 ;
}
int F_131 ( struct V_19 * V_20 , int V_105 , int V_291 , int V_16 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_5 ;
F_12 ( & V_25 -> V_26 ) ;
V_5 = F_77 ( V_20 , V_105 , 0x16 , V_291 ) ;
if ( V_5 < 0 )
goto error;
V_5 = F_76 ( V_20 , V_105 , V_16 ) ;
error:
F_77 ( V_20 , V_105 , 0x16 , 0x0 ) ;
F_3 ( & V_25 -> V_26 ) ;
return V_5 ;
}
int F_132 ( struct V_19 * V_20 , int V_105 , int V_291 ,
int V_16 , int V_9 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_5 ;
F_12 ( & V_25 -> V_26 ) ;
V_5 = F_77 ( V_20 , V_105 , 0x16 , V_291 ) ;
if ( V_5 < 0 )
goto error;
V_5 = F_77 ( V_20 , V_105 , V_16 , V_9 ) ;
error:
F_77 ( V_20 , V_105 , 0x16 , 0x0 ) ;
F_3 ( & V_25 -> V_26 ) ;
return V_5 ;
}
static int F_133 ( struct V_19 * V_20 , int V_105 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
if ( V_105 >= 0 && V_105 < V_25 -> V_229 )
return V_105 ;
return - V_22 ;
}
int
F_134 ( struct V_19 * V_20 , int V_105 , int V_4 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_3 = F_133 ( V_20 , V_105 ) ;
int V_5 ;
if ( V_3 < 0 )
return V_3 ;
F_12 ( & V_25 -> V_26 ) ;
V_5 = F_20 ( V_20 , V_3 , V_4 ) ;
F_3 ( & V_25 -> V_26 ) ;
return V_5 ;
}
int
F_135 ( struct V_19 * V_20 , int V_105 , int V_4 , T_2 V_9 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_3 = F_133 ( V_20 , V_105 ) ;
int V_5 ;
if ( V_3 < 0 )
return V_3 ;
F_12 ( & V_25 -> V_26 ) ;
V_5 = F_21 ( V_20 , V_3 , V_4 , V_9 ) ;
F_3 ( & V_25 -> V_26 ) ;
return V_5 ;
}
int
F_136 ( struct V_19 * V_20 , int V_105 , int V_4 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_3 = F_133 ( V_20 , V_105 ) ;
int V_5 ;
if ( V_3 < 0 )
return V_3 ;
F_12 ( & V_25 -> V_26 ) ;
V_5 = F_76 ( V_20 , V_3 , V_4 ) ;
F_3 ( & V_25 -> V_26 ) ;
return V_5 ;
}
int
F_137 ( struct V_19 * V_20 , int V_105 , int V_4 ,
T_2 V_9 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_3 = F_133 ( V_20 , V_105 ) ;
int V_5 ;
if ( V_3 < 0 )
return V_3 ;
F_12 ( & V_25 -> V_26 ) ;
V_5 = F_77 ( V_20 , V_3 , V_4 , V_9 ) ;
F_3 ( & V_25 -> V_26 ) ;
return V_5 ;
}
static int T_7 F_138 ( void )
{
#if F_139 ( V_292 )
F_140 ( & V_293 ) ;
#endif
#if F_139 ( V_294 )
F_140 ( & V_295 ) ;
#endif
#if F_139 ( V_296 )
F_140 ( & V_297 ) ;
#endif
#if F_139 ( V_298 )
F_140 ( & V_299 ) ;
#endif
return 0 ;
}
static void T_8 F_141 ( void )
{
#if F_139 ( V_298 )
F_142 ( & V_299 ) ;
#endif
#if F_139 ( V_296 )
F_142 ( & V_297 ) ;
#endif
#if F_139 ( V_294 )
F_142 ( & V_295 ) ;
#endif
#if F_139 ( V_292 )
F_142 ( & V_293 ) ;
#endif
}
