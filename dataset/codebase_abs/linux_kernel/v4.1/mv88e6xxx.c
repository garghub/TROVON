static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < 16 ; V_5 ++ ) {
V_4 = F_2 ( V_2 , V_3 , V_6 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( ( V_4 & V_7 ) == 0 )
return 0 ;
}
return - V_8 ;
}
int F_3 ( struct V_1 * V_2 , int V_3 , int V_9 , int V_10 )
{
int V_4 ;
if ( V_3 == 0 )
return F_2 ( V_2 , V_9 , V_10 ) ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_4 ( V_2 , V_3 , V_6 ,
V_11 | ( V_9 << 5 ) | V_10 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_2 ( V_2 , V_3 , V_12 ) ;
if ( V_4 < 0 )
return V_4 ;
return V_4 & 0xffff ;
}
static int F_5 ( struct V_13 * V_14 , int V_9 , int V_10 )
{
struct V_1 * V_2 = F_6 ( V_14 -> V_15 ) ;
int V_4 ;
if ( V_2 == NULL )
return - V_16 ;
V_4 = F_3 ( V_2 , V_14 -> V_17 -> V_3 , V_9 , V_10 ) ;
if ( V_4 < 0 )
return V_4 ;
F_7 ( V_14 -> V_15 , L_1 ,
V_9 , V_10 , V_4 ) ;
return V_4 ;
}
int F_8 ( struct V_13 * V_14 , int V_9 , int V_10 )
{
struct V_18 * V_19 = F_9 ( V_14 ) ;
int V_4 ;
F_10 ( & V_19 -> V_20 ) ;
V_4 = F_5 ( V_14 , V_9 , V_10 ) ;
F_11 ( & V_19 -> V_20 ) ;
return V_4 ;
}
int F_12 ( struct V_1 * V_2 , int V_3 , int V_9 ,
int V_10 , T_1 V_21 )
{
int V_4 ;
if ( V_3 == 0 )
return F_4 ( V_2 , V_9 , V_10 , V_21 ) ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_4 ( V_2 , V_3 , V_12 , V_21 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_4 ( V_2 , V_3 , V_6 ,
V_22 | ( V_9 << 5 ) | V_10 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
return 0 ;
}
static int F_13 ( struct V_13 * V_14 , int V_9 , int V_10 ,
T_1 V_21 )
{
struct V_1 * V_2 = F_6 ( V_14 -> V_15 ) ;
if ( V_2 == NULL )
return - V_16 ;
F_7 ( V_14 -> V_15 , L_2 ,
V_9 , V_10 , V_21 ) ;
return F_12 ( V_2 , V_14 -> V_17 -> V_3 , V_9 , V_10 , V_21 ) ;
}
int F_14 ( struct V_13 * V_14 , int V_9 , int V_10 , T_1 V_21 )
{
struct V_18 * V_19 = F_9 ( V_14 ) ;
int V_4 ;
F_10 ( & V_19 -> V_20 ) ;
V_4 = F_13 ( V_14 , V_9 , V_10 , V_21 ) ;
F_11 ( & V_19 -> V_20 ) ;
return V_4 ;
}
int F_15 ( struct V_13 * V_14 )
{
F_16 ( V_23 , V_24 , 0x0000 ) ;
F_16 ( V_23 , V_25 , 0x0000 ) ;
F_16 ( V_23 , V_26 , 0x5555 ) ;
F_16 ( V_23 , V_27 , 0x5555 ) ;
F_16 ( V_23 , V_28 , 0xaaaa ) ;
F_16 ( V_23 , V_29 , 0xaaaa ) ;
F_16 ( V_23 , V_30 , 0xffff ) ;
F_16 ( V_23 , V_31 , 0xffff ) ;
F_16 ( V_23 , V_32 , 0xfa41 ) ;
return 0 ;
}
int F_17 ( struct V_13 * V_14 , T_2 * V_9 )
{
F_16 ( V_23 , V_33 , ( V_9 [ 0 ] << 8 ) | V_9 [ 1 ] ) ;
F_16 ( V_23 , V_34 , ( V_9 [ 2 ] << 8 ) | V_9 [ 3 ] ) ;
F_16 ( V_23 , V_35 , ( V_9 [ 4 ] << 8 ) | V_9 [ 5 ] ) ;
return 0 ;
}
int F_18 ( struct V_13 * V_14 , T_2 * V_9 )
{
int V_5 ;
int V_4 ;
for ( V_5 = 0 ; V_5 < 6 ; V_5 ++ ) {
int V_36 ;
F_16 ( V_37 , V_38 ,
V_39 | ( V_5 << 8 ) | V_9 [ V_5 ] ) ;
for ( V_36 = 0 ; V_36 < 16 ; V_36 ++ ) {
V_4 = F_19 ( V_37 , V_38 ) ;
if ( ( V_4 & V_39 ) == 0 )
break;
}
if ( V_36 == 16 )
return - V_8 ;
}
return 0 ;
}
static int F_20 ( struct V_13 * V_14 , int V_9 , int V_40 )
{
if ( V_9 >= 0 )
return F_8 ( V_14 , V_9 , V_40 ) ;
return 0xffff ;
}
static int F_21 ( struct V_13 * V_14 , int V_9 , int V_40 ,
T_1 V_21 )
{
if ( V_9 >= 0 )
return F_14 ( V_14 , V_9 , V_40 , V_21 ) ;
return 0 ;
}
static int F_22 ( struct V_13 * V_14 )
{
int V_4 ;
unsigned long V_41 ;
V_4 = F_19 ( V_23 , V_42 ) ;
F_16 ( V_23 , V_42 ,
V_4 & ~ V_43 ) ;
V_41 = V_44 + 1 * V_45 ;
while ( F_23 ( V_44 , V_41 ) ) {
V_4 = F_19 ( V_23 , V_46 ) ;
F_24 ( 1000 , 2000 ) ;
if ( ( V_4 & V_47 ) !=
V_48 )
return 0 ;
}
return - V_8 ;
}
static int F_25 ( struct V_13 * V_14 )
{
int V_4 ;
unsigned long V_41 ;
V_4 = F_19 ( V_23 , V_42 ) ;
F_16 ( V_23 , V_42 , V_4 | V_43 ) ;
V_41 = V_44 + 1 * V_45 ;
while ( F_23 ( V_44 , V_41 ) ) {
V_4 = F_19 ( V_23 , V_46 ) ;
F_24 ( 1000 , 2000 ) ;
if ( ( V_4 & V_47 ) ==
V_48 )
return 0 ;
}
return - V_8 ;
}
static void F_26 ( struct V_49 * V_50 )
{
struct V_18 * V_19 ;
V_19 = F_27 ( V_50 , struct V_18 , V_51 ) ;
if ( F_28 ( & V_19 -> V_52 ) ) {
struct V_13 * V_14 = ( (struct V_13 * ) V_19 ) - 1 ;
if ( F_25 ( V_14 ) == 0 )
V_19 -> V_53 = 0 ;
F_11 ( & V_19 -> V_52 ) ;
}
}
static void F_29 ( unsigned long V_54 )
{
struct V_18 * V_19 = ( void * ) V_54 ;
F_30 ( & V_19 -> V_51 ) ;
}
static int F_31 ( struct V_13 * V_14 )
{
struct V_18 * V_19 = F_9 ( V_14 ) ;
int V_4 ;
F_10 ( & V_19 -> V_52 ) ;
if ( ! V_19 -> V_53 ) {
V_4 = F_22 ( V_14 ) ;
if ( V_4 < 0 ) {
F_11 ( & V_19 -> V_52 ) ;
return V_4 ;
}
V_19 -> V_53 = 1 ;
} else {
F_32 ( & V_19 -> V_55 ) ;
V_4 = 0 ;
}
return V_4 ;
}
static void F_33 ( struct V_13 * V_14 )
{
struct V_18 * V_19 = F_9 ( V_14 ) ;
F_34 ( & V_19 -> V_55 , V_44 + F_35 ( 10 ) ) ;
F_11 ( & V_19 -> V_52 ) ;
}
void F_36 ( struct V_13 * V_14 )
{
struct V_18 * V_19 = F_9 ( V_14 ) ;
F_37 ( & V_19 -> V_52 ) ;
F_38 ( & V_19 -> V_51 , F_26 ) ;
F_39 ( & V_19 -> V_55 ) ;
V_19 -> V_55 . V_56 = ( unsigned long ) V_19 ;
V_19 -> V_55 . V_57 = F_29 ;
}
int F_40 ( struct V_13 * V_14 , int V_9 , int V_40 )
{
int V_4 ;
V_4 = F_31 ( V_14 ) ;
if ( V_4 >= 0 ) {
V_4 = F_8 ( V_14 , V_9 , V_40 ) ;
F_33 ( V_14 ) ;
}
return V_4 ;
}
int F_41 ( struct V_13 * V_14 , int V_9 ,
int V_40 , T_1 V_21 )
{
int V_4 ;
V_4 = F_31 ( V_14 ) ;
if ( V_4 >= 0 ) {
V_4 = F_14 ( V_14 , V_9 , V_40 , V_21 ) ;
F_33 ( V_14 ) ;
}
return V_4 ;
}
void F_42 ( struct V_13 * V_14 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_58 ; V_5 ++ ) {
struct V_59 * V_60 ;
int V_61 ( V_62 ) ;
int V_63 ;
int V_64 ;
int V_65 ;
int V_66 ;
V_60 = V_14 -> V_67 [ V_5 ] ;
if ( V_60 == NULL )
continue;
V_63 = 0 ;
if ( V_60 -> V_68 & V_69 ) {
V_62 = F_8 ( V_14 , F_43 ( V_5 ) ,
V_70 ) ;
if ( V_62 < 0 )
continue;
V_63 = ! ! ( V_62 & V_71 ) ;
}
if ( ! V_63 ) {
if ( F_44 ( V_60 ) ) {
F_45 ( V_60 , L_3 ) ;
F_46 ( V_60 ) ;
}
continue;
}
switch ( V_62 & V_72 ) {
case V_73 :
V_64 = 10 ;
break;
case V_74 :
V_64 = 100 ;
break;
case V_75 :
V_64 = 1000 ;
break;
default:
V_64 = - 1 ;
break;
}
V_65 = ( V_62 & V_76 ) ? 1 : 0 ;
V_66 = ( V_62 & V_77 ) ? 1 : 0 ;
if ( ! F_44 ( V_60 ) ) {
F_45 ( V_60 ,
L_4 ,
V_64 ,
V_65 ? L_5 : L_6 ,
V_66 ? L_7 : L_8 ) ;
F_47 ( V_60 ) ;
}
}
}
static bool F_48 ( struct V_13 * V_14 )
{
struct V_18 * V_19 = F_9 ( V_14 ) ;
switch ( V_19 -> V_78 ) {
case V_79 :
case V_80 :
case V_81 :
return true ;
}
return false ;
}
static int F_49 ( struct V_13 * V_14 )
{
int V_4 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < 10 ; V_5 ++ ) {
V_4 = F_19 ( V_23 , V_82 ) ;
if ( ( V_4 & V_83 ) == 0 )
return 0 ;
}
return - V_8 ;
}
static int F_50 ( struct V_13 * V_14 , int V_84 )
{
int V_4 ;
if ( F_48 ( V_14 ) )
V_84 = ( V_84 + 1 ) << 5 ;
F_16 ( V_23 , V_82 ,
V_85 |
V_86 | V_84 ) ;
V_4 = F_49 ( V_14 ) ;
if ( V_4 < 0 )
return V_4 ;
return 0 ;
}
static void F_51 ( struct V_13 * V_14 , int V_87 , T_3 * V_21 )
{
T_3 V_88 ;
int V_4 ;
* V_21 = 0 ;
V_4 = F_14 ( V_14 , V_23 , V_82 ,
V_89 |
V_86 | V_87 ) ;
if ( V_4 < 0 )
return;
V_4 = F_49 ( V_14 ) ;
if ( V_4 < 0 )
return;
V_4 = F_8 ( V_14 , V_23 , V_90 ) ;
if ( V_4 < 0 )
return;
V_88 = V_4 << 16 ;
V_4 = F_8 ( V_14 , V_23 , V_91 ) ;
if ( V_4 < 0 )
return;
* V_21 = V_88 | V_4 ;
}
static bool F_52 ( struct V_13 * V_14 )
{
struct V_18 * V_19 = F_9 ( V_14 ) ;
switch ( V_19 -> V_78 ) {
case V_92 : case V_93 :
case V_94 : case V_95 :
case V_80 : case V_81 :
case V_96 : case V_97 :
case V_79 :
return true ;
default:
return false ;
}
}
static void F_53 ( struct V_13 * V_14 ,
int V_98 ,
struct V_99 * V_100 ,
int V_84 , T_4 * V_56 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_98 ; V_5 ++ ) {
memcpy ( V_56 + V_5 * V_101 ,
V_100 [ V_5 ] . string , V_101 ) ;
}
}
static void F_54 ( struct V_13 * V_14 ,
int V_98 ,
struct V_99 * V_100 ,
int V_84 , T_5 * V_56 )
{
struct V_18 * V_19 = F_9 ( V_14 ) ;
int V_4 ;
int V_5 ;
F_10 ( & V_19 -> V_102 ) ;
V_4 = F_50 ( V_14 , V_84 ) ;
if ( V_4 < 0 ) {
F_11 ( & V_19 -> V_102 ) ;
return;
}
for ( V_5 = 0 ; V_5 < V_98 ; V_5 ++ ) {
struct V_99 * V_103 = V_100 + V_5 ;
T_3 V_104 ;
T_3 V_105 = 0 ;
if ( V_103 -> V_10 >= 0x100 ) {
V_4 = F_8 ( V_14 , F_43 ( V_84 ) ,
V_103 -> V_10 - 0x100 ) ;
if ( V_4 < 0 )
goto error;
V_104 = V_4 ;
if ( V_103 -> V_106 == 4 ) {
V_4 = F_8 ( V_14 , F_43 ( V_84 ) ,
V_103 -> V_10 - 0x100 + 1 ) ;
if ( V_4 < 0 )
goto error;
V_105 = V_4 ;
}
V_56 [ V_5 ] = ( ( ( V_107 ) V_105 ) << 16 ) | V_104 ;
continue;
}
F_51 ( V_14 , V_103 -> V_10 , & V_104 ) ;
if ( V_103 -> V_106 == 8 )
F_51 ( V_14 , V_103 -> V_10 + 1 , & V_105 ) ;
V_56 [ V_5 ] = ( ( ( V_107 ) V_105 ) << 32 ) | V_104 ;
}
error:
F_11 ( & V_19 -> V_102 ) ;
}
void
F_55 ( struct V_13 * V_14 , int V_84 , T_4 * V_56 )
{
if ( F_52 ( V_14 ) )
F_53 ( V_14 , F_56 ( V_108 ) ,
V_108 , V_84 , V_56 ) ;
else
F_53 ( V_14 , F_56 ( V_108 ) - 3 ,
V_108 , V_84 , V_56 ) ;
}
int F_57 ( struct V_13 * V_14 )
{
if ( F_52 ( V_14 ) )
return F_56 ( V_108 ) ;
return F_56 ( V_108 ) - 3 ;
}
void
F_58 ( struct V_13 * V_14 ,
int V_84 , T_5 * V_56 )
{
if ( F_52 ( V_14 ) )
F_54 (
V_14 , F_56 ( V_108 ) ,
V_108 , V_84 , V_56 ) ;
else
F_54 (
V_14 , F_56 ( V_108 ) - 3 ,
V_108 , V_84 , V_56 ) ;
}
int F_59 ( struct V_13 * V_14 , int V_84 )
{
return 32 * sizeof( T_1 ) ;
}
void F_60 ( struct V_13 * V_14 , int V_84 ,
struct V_109 * V_110 , void * V_111 )
{
T_1 * V_112 = V_111 ;
int V_5 ;
V_110 -> V_113 = 0 ;
memset ( V_112 , 0xff , 32 * sizeof( T_1 ) ) ;
for ( V_5 = 0 ; V_5 < 32 ; V_5 ++ ) {
int V_4 ;
V_4 = F_8 ( V_14 , F_43 ( V_84 ) , V_5 ) ;
if ( V_4 >= 0 )
V_112 [ V_5 ] = V_4 ;
}
}
int F_61 ( struct V_13 * V_14 , int * V_114 )
{
struct V_18 * V_19 = F_9 ( V_14 ) ;
int V_4 ;
int V_21 ;
* V_114 = 0 ;
F_10 ( & V_19 -> V_115 ) ;
V_4 = F_21 ( V_14 , 0x0 , 0x16 , 0x6 ) ;
if ( V_4 < 0 )
goto error;
V_4 = F_20 ( V_14 , 0x0 , 0x1a ) ;
if ( V_4 < 0 )
goto error;
V_4 = F_21 ( V_14 , 0x0 , 0x1a , V_4 | ( 1 << 5 ) ) ;
if ( V_4 < 0 )
goto error;
F_24 ( 10000 , 12000 ) ;
V_21 = F_20 ( V_14 , 0x0 , 0x1a ) ;
if ( V_21 < 0 ) {
V_4 = V_21 ;
goto error;
}
V_4 = F_21 ( V_14 , 0x0 , 0x1a , V_4 & ~ ( 1 << 5 ) ) ;
if ( V_4 < 0 )
goto error;
* V_114 = ( ( V_21 & 0x1f ) - 5 ) * 5 ;
error:
F_21 ( V_14 , 0x0 , 0x16 , 0x0 ) ;
F_11 ( & V_19 -> V_115 ) ;
return V_4 ;
}
static int F_62 ( struct V_13 * V_14 , int V_10 , int V_116 , T_1 V_117 )
{
unsigned long V_41 = V_44 + V_45 / 10 ;
while ( F_23 ( V_44 , V_41 ) ) {
int V_4 ;
V_4 = F_19 ( V_10 , V_116 ) ;
if ( ! ( V_4 & V_117 ) )
return 0 ;
F_24 ( 1000 , 2000 ) ;
}
return - V_8 ;
}
int F_63 ( struct V_13 * V_14 )
{
return F_62 ( V_14 , V_37 , V_118 ,
V_119 ) ;
}
int F_64 ( struct V_13 * V_14 )
{
return F_62 ( V_14 , V_37 , V_120 ,
V_121 ) ;
}
int F_65 ( struct V_13 * V_14 )
{
return F_62 ( V_14 , V_37 , V_120 ,
V_122 ) ;
}
static int F_66 ( struct V_13 * V_14 , int V_10 , int V_116 , T_1 V_117 )
{
unsigned long V_41 = V_44 + V_45 / 10 ;
while ( F_23 ( V_44 , V_41 ) ) {
int V_4 ;
V_4 = F_5 ( V_14 , V_10 , V_116 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( ! ( V_4 & V_117 ) )
return 0 ;
F_24 ( 1000 , 2000 ) ;
}
return - V_8 ;
}
static int F_67 ( struct V_13 * V_14 )
{
return F_66 ( V_14 , V_23 , V_123 ,
V_124 ) ;
}
static int F_68 ( struct V_13 * V_14 , int V_9 ,
int V_40 )
{
int V_4 ;
F_16 ( V_37 , V_118 ,
V_125 | ( V_9 << 5 ) | V_40 ) ;
V_4 = F_63 ( V_14 ) ;
if ( V_4 < 0 )
return V_4 ;
return F_19 ( V_37 , V_126 ) ;
}
static int F_69 ( struct V_13 * V_14 , int V_9 ,
int V_40 , T_1 V_21 )
{
F_16 ( V_37 , V_126 , V_21 ) ;
F_16 ( V_37 , V_118 ,
V_127 | ( V_9 << 5 ) | V_40 ) ;
return F_63 ( V_14 ) ;
}
int F_70 ( struct V_13 * V_14 , int V_84 , struct V_128 * V_129 )
{
struct V_18 * V_19 = F_9 ( V_14 ) ;
int V_10 ;
F_10 ( & V_19 -> V_115 ) ;
V_10 = F_68 ( V_14 , V_84 , 16 ) ;
if ( V_10 < 0 )
goto V_130;
V_129 -> V_131 = ! ! ( V_10 & 0x0200 ) ;
V_129 -> V_132 = ! ! ( V_10 & 0x0100 ) ;
V_10 = F_8 ( V_14 , F_43 ( V_84 ) , V_70 ) ;
if ( V_10 < 0 )
goto V_130;
V_129 -> V_133 = ! ! ( V_10 & V_134 ) ;
V_10 = 0 ;
V_130:
F_11 ( & V_19 -> V_115 ) ;
return V_10 ;
}
int F_71 ( struct V_13 * V_14 , int V_84 ,
struct V_135 * V_136 , struct V_128 * V_129 )
{
struct V_18 * V_19 = F_9 ( V_14 ) ;
int V_10 ;
int V_4 ;
F_10 ( & V_19 -> V_115 ) ;
V_4 = F_68 ( V_14 , V_84 , 16 ) ;
if ( V_4 < 0 )
goto V_130;
V_10 = V_4 & ~ 0x0300 ;
if ( V_129 -> V_131 )
V_10 |= 0x0200 ;
if ( V_129 -> V_132 )
V_10 |= 0x0100 ;
V_4 = F_69 ( V_14 , V_84 , 16 , V_10 ) ;
V_130:
F_11 ( & V_19 -> V_115 ) ;
return V_4 ;
}
static int F_72 ( struct V_13 * V_14 , int V_137 , T_1 V_138 )
{
int V_4 ;
V_4 = F_13 ( V_14 , V_23 , 0x01 , V_137 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_13 ( V_14 , V_23 , V_123 , V_138 ) ;
if ( V_4 < 0 )
return V_4 ;
return F_67 ( V_14 ) ;
}
static int F_73 ( struct V_13 * V_14 , int V_137 )
{
int V_4 ;
V_4 = F_67 ( V_14 ) ;
if ( V_4 < 0 )
return V_4 ;
return F_72 ( V_14 , V_137 , V_139 ) ;
}
static int F_74 ( struct V_13 * V_14 , int V_84 , T_2 V_140 )
{
struct V_18 * V_19 = F_9 ( V_14 ) ;
int V_10 , V_4 = 0 ;
T_2 V_141 ;
F_10 ( & V_19 -> V_20 ) ;
V_10 = F_5 ( V_14 , F_43 ( V_84 ) , V_142 ) ;
if ( V_10 < 0 ) {
V_4 = V_10 ;
goto abort;
}
V_141 = V_10 & V_143 ;
if ( V_141 != V_140 ) {
if ( V_141 >= V_144 &&
V_140 <= V_145 ) {
V_4 = F_73 ( V_14 , V_19 -> V_137 [ V_84 ] ) ;
if ( V_4 )
goto abort;
}
V_10 = ( V_10 & ~ V_143 ) | V_140 ;
V_4 = F_13 ( V_14 , F_43 ( V_84 ) , V_142 ,
V_10 ) ;
}
abort:
F_11 ( & V_19 -> V_20 ) ;
return V_4 ;
}
static int F_75 ( struct V_13 * V_14 , int V_84 )
{
struct V_18 * V_19 = F_9 ( V_14 ) ;
T_2 V_137 = V_19 -> V_137 [ V_84 ] ;
T_1 V_10 = V_137 << 12 ;
if ( F_76 ( V_14 , V_84 ) )
V_10 |= V_14 -> V_146 ;
else
V_10 |= ( V_19 -> V_147 [ V_137 ] |
( 1 << F_77 ( V_14 ) ) ) & ~ ( 1 << V_84 ) ;
return F_13 ( V_14 , F_43 ( V_84 ) , V_148 , V_10 ) ;
}
static int F_78 ( struct V_13 * V_14 , int V_137 )
{
struct V_18 * V_19 = F_9 ( V_14 ) ;
int V_84 ;
T_3 V_117 ;
int V_4 ;
V_117 = V_14 -> V_146 ;
while ( V_117 ) {
V_84 = F_79 ( V_117 ) ;
V_117 &= ~ ( 1 << V_84 ) ;
if ( V_19 -> V_137 [ V_84 ] != V_137 )
continue;
V_4 = F_75 ( V_14 , V_84 ) ;
if ( V_4 )
return V_4 ;
}
return F_73 ( V_14 , V_137 ) ;
}
int F_80 ( struct V_13 * V_14 , int V_84 , T_3 V_149 )
{
struct V_18 * V_19 = F_9 ( V_14 ) ;
int V_4 = 0 ;
T_3 V_150 ;
int V_137 ;
V_137 = V_19 -> V_137 [ V_84 ] ;
V_150 = V_149 & ~ ( 1 << V_84 ) ;
if ( V_150 )
V_137 = V_19 -> V_137 [ F_79 ( V_150 ) ] ;
V_150 = V_19 -> V_147 [ V_137 ] | ( 1 << V_84 ) ;
if ( V_150 != V_149 ) {
F_81 ( V_14 -> V_67 [ V_84 ] ,
L_9 ,
V_137 , V_149 , V_150 ) ;
return - V_16 ;
}
F_10 ( & V_19 -> V_20 ) ;
V_19 -> V_147 [ V_137 ] = V_149 ;
if ( V_137 != V_19 -> V_137 [ V_84 ] ) {
V_19 -> V_151 |= 1 << V_19 -> V_137 [ V_84 ] ;
V_19 -> V_137 [ V_84 ] = V_137 ;
V_4 = F_78 ( V_14 , V_137 ) ;
}
F_11 ( & V_19 -> V_20 ) ;
return V_4 ;
}
int F_82 ( struct V_13 * V_14 , int V_84 , T_3 V_149 )
{
struct V_18 * V_19 = F_9 ( V_14 ) ;
T_2 V_137 , V_152 ;
int V_4 ;
V_137 = V_19 -> V_137 [ V_84 ] ;
if ( V_19 -> V_147 [ V_137 ] != V_149 ) {
F_81 ( V_14 -> V_67 [ V_84 ] ,
L_10 ,
V_137 , V_149 , V_19 -> V_147 [ V_137 ] ) ;
return - V_16 ;
}
if ( V_149 == ( 1 << V_84 ) )
return 0 ;
F_10 ( & V_19 -> V_20 ) ;
V_152 = F_79 ( V_19 -> V_151 ) ;
V_19 -> V_137 [ V_84 ] = V_152 ;
V_19 -> V_151 &= ( 1 << V_152 ) ;
V_19 -> V_147 [ V_137 ] &= ~ ( 1 << V_84 ) ;
V_19 -> V_147 [ V_152 ] = 1 << V_84 ;
V_4 = F_78 ( V_14 , V_137 ) ;
if ( ! V_4 )
V_4 = F_78 ( V_14 , V_152 ) ;
F_11 ( & V_19 -> V_20 ) ;
return V_4 ;
}
int F_83 ( struct V_13 * V_14 , int V_84 , T_2 V_140 )
{
struct V_18 * V_19 = F_9 ( V_14 ) ;
int V_153 ;
switch ( V_140 ) {
case V_154 :
V_153 = V_155 ;
break;
case V_156 :
case V_157 :
V_153 = V_145 ;
break;
case V_158 :
V_153 = V_144 ;
break;
case V_159 :
default:
V_153 = V_160 ;
break;
}
F_84 ( V_14 -> V_67 [ V_84 ] , L_11 , V_140 , V_153 ) ;
V_19 -> V_161 [ V_84 ] = V_153 ;
F_85 ( V_84 , & V_19 -> V_162 ) ;
F_30 ( & V_19 -> V_163 ) ;
return 0 ;
}
static int F_86 ( struct V_13 * V_14 ,
const unsigned char * V_9 )
{
int V_5 , V_4 ;
for ( V_5 = 0 ; V_5 < 3 ; V_5 ++ ) {
V_4 = F_13 (
V_14 , V_23 , V_164 + V_5 ,
( V_9 [ V_5 * 2 ] << 8 ) | V_9 [ V_5 * 2 + 1 ] ) ;
if ( V_4 < 0 )
return V_4 ;
}
return 0 ;
}
static int F_87 ( struct V_13 * V_14 , unsigned char * V_9 )
{
int V_5 , V_4 ;
for ( V_5 = 0 ; V_5 < 3 ; V_5 ++ ) {
V_4 = F_5 ( V_14 , V_23 ,
V_164 + V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_9 [ V_5 * 2 ] = V_4 >> 8 ;
V_9 [ V_5 * 2 + 1 ] = V_4 & 0xff ;
}
return 0 ;
}
static int F_88 ( struct V_13 * V_14 , int V_84 ,
const unsigned char * V_9 , int V_140 )
{
struct V_18 * V_19 = F_9 ( V_14 ) ;
T_2 V_137 = V_19 -> V_137 [ V_84 ] ;
int V_4 ;
V_4 = F_67 ( V_14 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_86 ( V_14 , V_9 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_13 ( V_14 , V_23 , V_165 ,
( 0x10 << V_84 ) | V_140 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_72 ( V_14 , V_137 , V_166 ) ;
return V_4 ;
}
int F_89 ( struct V_13 * V_14 , int V_84 ,
const unsigned char * V_9 , T_1 V_167 )
{
int V_140 = F_90 ( V_9 ) ?
V_168 :
V_169 ;
struct V_18 * V_19 = F_9 ( V_14 ) ;
int V_4 ;
F_10 ( & V_19 -> V_20 ) ;
V_4 = F_88 ( V_14 , V_84 , V_9 , V_140 ) ;
F_11 ( & V_19 -> V_20 ) ;
return V_4 ;
}
int F_91 ( struct V_13 * V_14 , int V_84 ,
const unsigned char * V_9 , T_1 V_167 )
{
struct V_18 * V_19 = F_9 ( V_14 ) ;
int V_4 ;
F_10 ( & V_19 -> V_20 ) ;
V_4 = F_88 ( V_14 , V_84 , V_9 ,
V_170 ) ;
F_11 ( & V_19 -> V_20 ) ;
return V_4 ;
}
static int F_92 ( struct V_13 * V_14 , int V_84 ,
unsigned char * V_9 , bool * V_171 )
{
struct V_18 * V_19 = F_9 ( V_14 ) ;
T_2 V_137 = V_19 -> V_137 [ V_84 ] ;
int V_4 , V_140 ;
V_4 = F_67 ( V_14 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_86 ( V_14 , V_9 ) ;
if ( V_4 < 0 )
return V_4 ;
do {
V_4 = F_72 ( V_14 , V_137 , V_172 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_5 ( V_14 , V_23 , V_165 ) ;
if ( V_4 < 0 )
return V_4 ;
V_140 = V_4 & V_173 ;
if ( V_140 == V_170 )
return - V_174 ;
} while ( ! ( ( ( V_4 >> 4 ) & 0xff ) & ( 1 << V_84 ) ) );
V_4 = F_87 ( V_14 , V_9 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_171 = V_140 == ( F_90 ( V_9 ) ?
V_168 :
V_169 ) ;
return 0 ;
}
int F_93 ( struct V_13 * V_14 , int V_84 ,
unsigned char * V_9 , bool * V_171 )
{
struct V_18 * V_19 = F_9 ( V_14 ) ;
int V_4 ;
F_10 ( & V_19 -> V_20 ) ;
V_4 = F_92 ( V_14 , V_84 , V_9 , V_171 ) ;
F_11 ( & V_19 -> V_20 ) ;
return V_4 ;
}
static void F_94 ( struct V_49 * V_175 )
{
struct V_18 * V_19 ;
struct V_13 * V_14 ;
int V_84 ;
V_19 = F_27 ( V_175 , struct V_18 , V_163 ) ;
V_14 = ( (struct V_13 * ) V_19 ) - 1 ;
while ( V_19 -> V_162 ) {
V_84 = F_79 ( V_19 -> V_162 ) ;
F_95 ( V_84 , & V_19 -> V_162 ) ;
F_74 ( V_14 , V_84 , V_19 -> V_161 [ V_84 ] ) ;
}
}
int F_96 ( struct V_13 * V_14 , int V_84 )
{
struct V_18 * V_19 = F_9 ( V_14 ) ;
int V_4 , V_137 ;
F_10 ( & V_19 -> V_20 ) ;
V_4 = F_13 ( V_14 , F_43 ( V_84 ) , V_176 , 0x0000 ) ;
if ( V_4 )
goto abort;
V_137 = F_79 ( V_19 -> V_151 ) ;
V_19 -> V_137 [ V_84 ] = V_137 ;
V_19 -> V_151 &= ~ ( 1 << V_137 ) ;
if ( ! F_76 ( V_14 , V_84 ) )
V_19 -> V_147 [ V_137 ] = 1 << V_84 ;
V_4 = F_75 ( V_14 , V_84 ) ;
if ( V_4 )
goto abort;
V_4 = F_13 ( V_14 , F_43 ( V_84 ) , V_177 ,
0x0000 ) ;
abort:
F_11 ( & V_19 -> V_20 ) ;
return V_4 ;
}
int F_97 ( struct V_13 * V_14 )
{
struct V_18 * V_19 = F_9 ( V_14 ) ;
F_37 ( & V_19 -> V_20 ) ;
F_37 ( & V_19 -> V_102 ) ;
F_37 ( & V_19 -> V_115 ) ;
V_19 -> V_78 = F_19 ( F_43 ( 0 ) , V_178 ) & 0xfff0 ;
V_19 -> V_151 = ( 1 << V_58 ) - 1 ;
F_38 ( & V_19 -> V_163 , F_94 ) ;
return 0 ;
}
int F_98 ( struct V_13 * V_14 , bool V_179 )
{
struct V_18 * V_19 = F_9 ( V_14 ) ;
T_1 V_180 = ( V_179 ? 0x8800 : 0xc800 ) ;
unsigned long V_41 ;
int V_4 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_19 -> V_181 ; V_5 ++ ) {
V_4 = F_19 ( F_43 ( V_5 ) , V_142 ) ;
F_16 ( F_43 ( V_5 ) , V_142 , V_4 & 0xfffc ) ;
}
F_24 ( 2000 , 4000 ) ;
if ( V_179 )
F_16 ( V_23 , 0x04 , 0xc000 ) ;
else
F_16 ( V_23 , 0x04 , 0xc400 ) ;
V_41 = V_44 + 1 * V_45 ;
while ( F_23 ( V_44 , V_41 ) ) {
V_4 = F_19 ( V_23 , 0x00 ) ;
if ( ( V_4 & V_180 ) == V_180 )
break;
F_24 ( 1000 , 2000 ) ;
}
if ( F_99 ( V_44 , V_41 ) )
return - V_8 ;
return 0 ;
}
int F_100 ( struct V_13 * V_14 , int V_84 , int V_182 , int V_10 )
{
struct V_18 * V_19 = F_9 ( V_14 ) ;
int V_4 ;
F_10 ( & V_19 -> V_115 ) ;
V_4 = F_69 ( V_14 , V_84 , 0x16 , V_182 ) ;
if ( V_4 < 0 )
goto error;
V_4 = F_68 ( V_14 , V_84 , V_10 ) ;
error:
F_69 ( V_14 , V_84 , 0x16 , 0x0 ) ;
F_11 ( & V_19 -> V_115 ) ;
return V_4 ;
}
int F_101 ( struct V_13 * V_14 , int V_84 , int V_182 ,
int V_10 , int V_21 )
{
struct V_18 * V_19 = F_9 ( V_14 ) ;
int V_4 ;
F_10 ( & V_19 -> V_115 ) ;
V_4 = F_69 ( V_14 , V_84 , 0x16 , V_182 ) ;
if ( V_4 < 0 )
goto error;
V_4 = F_69 ( V_14 , V_84 , V_10 , V_21 ) ;
error:
F_69 ( V_14 , V_84 , 0x16 , 0x0 ) ;
F_11 ( & V_19 -> V_115 ) ;
return V_4 ;
}
static int F_102 ( struct V_13 * V_14 , int V_84 )
{
struct V_18 * V_19 = F_9 ( V_14 ) ;
if ( V_84 >= 0 && V_84 < V_19 -> V_181 )
return V_84 ;
return - V_16 ;
}
int
F_103 ( struct V_13 * V_14 , int V_84 , int V_40 )
{
struct V_18 * V_19 = F_9 ( V_14 ) ;
int V_9 = F_102 ( V_14 , V_84 ) ;
int V_4 ;
if ( V_9 < 0 )
return V_9 ;
F_10 ( & V_19 -> V_115 ) ;
V_4 = F_20 ( V_14 , V_9 , V_40 ) ;
F_11 ( & V_19 -> V_115 ) ;
return V_4 ;
}
int
F_104 ( struct V_13 * V_14 , int V_84 , int V_40 , T_1 V_21 )
{
struct V_18 * V_19 = F_9 ( V_14 ) ;
int V_9 = F_102 ( V_14 , V_84 ) ;
int V_4 ;
if ( V_9 < 0 )
return V_9 ;
F_10 ( & V_19 -> V_115 ) ;
V_4 = F_21 ( V_14 , V_9 , V_40 , V_21 ) ;
F_11 ( & V_19 -> V_115 ) ;
return V_4 ;
}
int
F_105 ( struct V_13 * V_14 , int V_84 , int V_40 )
{
struct V_18 * V_19 = F_9 ( V_14 ) ;
int V_9 = F_102 ( V_14 , V_84 ) ;
int V_4 ;
if ( V_9 < 0 )
return V_9 ;
F_10 ( & V_19 -> V_115 ) ;
V_4 = F_68 ( V_14 , V_9 , V_40 ) ;
F_11 ( & V_19 -> V_115 ) ;
return V_4 ;
}
int
F_106 ( struct V_13 * V_14 , int V_84 , int V_40 ,
T_1 V_21 )
{
struct V_18 * V_19 = F_9 ( V_14 ) ;
int V_9 = F_102 ( V_14 , V_84 ) ;
int V_4 ;
if ( V_9 < 0 )
return V_9 ;
F_10 ( & V_19 -> V_115 ) ;
V_4 = F_69 ( V_14 , V_9 , V_40 , V_21 ) ;
F_11 ( & V_19 -> V_115 ) ;
return V_4 ;
}
static int T_6 F_107 ( void )
{
#if F_108 ( V_183 )
F_109 ( & V_184 ) ;
#endif
#if F_108 ( V_185 )
F_109 ( & V_186 ) ;
#endif
#if F_108 ( V_187 )
F_109 ( & V_188 ) ;
#endif
#if F_108 ( V_189 )
F_109 ( & V_190 ) ;
#endif
return 0 ;
}
static void T_7 F_110 ( void )
{
#if F_108 ( V_189 )
F_111 ( & V_190 ) ;
#endif
#if F_108 ( V_187 )
F_111 ( & V_188 ) ;
#endif
#if F_108 ( V_185 )
F_111 ( & V_186 ) ;
#endif
#if F_108 ( V_183 )
F_111 ( & V_184 ) ;
#endif
}
