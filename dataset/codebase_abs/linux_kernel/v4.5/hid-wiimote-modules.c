static void F_1 ( struct V_1 * V_2 , const T_1 * V_3 )
{
F_2 ( V_2 -> V_4 , V_5 [ V_6 ] ,
! ! ( V_3 [ 0 ] & 0x01 ) ) ;
F_2 ( V_2 -> V_4 , V_5 [ V_7 ] ,
! ! ( V_3 [ 0 ] & 0x02 ) ) ;
F_2 ( V_2 -> V_4 , V_5 [ V_8 ] ,
! ! ( V_3 [ 0 ] & 0x04 ) ) ;
F_2 ( V_2 -> V_4 , V_5 [ V_9 ] ,
! ! ( V_3 [ 0 ] & 0x08 ) ) ;
F_2 ( V_2 -> V_4 , V_5 [ V_10 ] ,
! ! ( V_3 [ 0 ] & 0x10 ) ) ;
F_2 ( V_2 -> V_4 , V_5 [ V_11 ] ,
! ! ( V_3 [ 1 ] & 0x01 ) ) ;
F_2 ( V_2 -> V_4 , V_5 [ V_12 ] ,
! ! ( V_3 [ 1 ] & 0x02 ) ) ;
F_2 ( V_2 -> V_4 , V_5 [ V_13 ] ,
! ! ( V_3 [ 1 ] & 0x04 ) ) ;
F_2 ( V_2 -> V_4 , V_5 [ V_14 ] ,
! ! ( V_3 [ 1 ] & 0x08 ) ) ;
F_2 ( V_2 -> V_4 , V_5 [ V_15 ] ,
! ! ( V_3 [ 1 ] & 0x10 ) ) ;
F_2 ( V_2 -> V_4 , V_5 [ V_16 ] ,
! ! ( V_3 [ 1 ] & 0x80 ) ) ;
F_3 ( V_2 -> V_4 ) ;
}
static int F_4 ( const struct V_17 * V_18 ,
struct V_1 * V_2 )
{
unsigned int V_19 ;
F_5 ( V_20 , V_2 -> V_4 -> V_21 ) ;
for ( V_19 = 0 ; V_19 < V_22 ; ++ V_19 )
F_5 ( V_5 [ V_19 ] , V_2 -> V_4 -> V_23 ) ;
return 0 ;
}
static void F_6 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_7 ( V_25 , struct V_1 ,
V_26 ) ;
F_8 ( & V_2 -> V_27 . V_28 ) ;
F_9 ( V_2 , V_2 -> V_27 . V_29 ) ;
F_10 ( & V_2 -> V_27 . V_28 ) ;
}
static int F_11 ( struct V_30 * V_31 , void * V_32 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 = F_12 ( V_31 ) ;
T_1 V_35 ;
if ( V_34 -> V_36 . V_37 . V_38 || V_34 -> V_36 . V_37 . V_39 )
V_35 = 1 ;
else
V_35 = 0 ;
V_2 -> V_27 . V_29 = V_35 ;
F_13 ( & V_2 -> V_26 ) ;
return 0 ;
}
static int F_14 ( const struct V_17 * V_18 ,
struct V_1 * V_2 )
{
F_15 ( & V_2 -> V_26 , F_6 ) ;
F_5 ( V_40 , V_2 -> V_4 -> V_41 ) ;
if ( F_16 ( V_2 -> V_4 , NULL , F_11 ) )
return - V_42 ;
return 0 ;
}
static void F_17 ( const struct V_17 * V_18 ,
struct V_1 * V_2 )
{
unsigned long V_43 ;
F_18 ( & V_2 -> V_26 ) ;
F_19 ( & V_2 -> V_27 . V_28 , V_43 ) ;
F_9 ( V_2 , 0 ) ;
F_20 ( & V_2 -> V_27 . V_28 , V_43 ) ;
}
static int F_21 ( struct V_44 * V_45 ,
enum V_46 V_47 ,
union V_48 * V_49 )
{
struct V_1 * V_2 = F_22 ( V_45 ) ;
int V_50 = 0 , V_27 ;
unsigned long V_43 ;
if ( V_47 == V_51 ) {
V_49 -> V_52 = V_53 ;
return 0 ;
} else if ( V_47 != V_54 ) {
return - V_55 ;
}
V_50 = F_23 ( V_2 ) ;
if ( V_50 )
return V_50 ;
F_19 ( & V_2 -> V_27 . V_28 , V_43 ) ;
F_24 ( V_2 , V_56 , 0 ) ;
F_25 ( V_2 ) ;
F_20 ( & V_2 -> V_27 . V_28 , V_43 ) ;
F_26 ( V_2 ) ;
F_27 ( V_2 ) ;
F_19 ( & V_2 -> V_27 . V_28 , V_43 ) ;
V_27 = V_2 -> V_27 . V_57 ;
F_20 ( & V_2 -> V_27 . V_28 , V_43 ) ;
V_49 -> V_52 = V_27 * 100 / 255 ;
return V_50 ;
}
static int F_28 ( const struct V_17 * V_18 ,
struct V_1 * V_2 )
{
struct V_58 V_59 = { . V_60 = V_2 , } ;
int V_50 ;
V_2 -> V_61 . V_62 = V_63 ;
V_2 -> V_61 . V_64 = F_29 ( V_63 ) ;
V_2 -> V_61 . V_65 = F_21 ;
V_2 -> V_61 . type = V_66 ;
V_2 -> V_61 . V_67 = 0 ;
V_2 -> V_61 . V_68 = F_30 ( V_69 , L_1 ,
V_2 -> V_70 -> V_71 ) ;
if ( ! V_2 -> V_61 . V_68 )
return - V_42 ;
V_2 -> V_72 = F_31 ( & V_2 -> V_70 -> V_31 ,
& V_2 -> V_61 ,
& V_59 ) ;
if ( F_32 ( V_2 -> V_72 ) ) {
F_33 ( V_2 -> V_70 , L_2 ) ;
V_50 = F_34 ( V_2 -> V_72 ) ;
goto V_73;
}
F_35 ( V_2 -> V_72 , & V_2 -> V_70 -> V_31 ) ;
return 0 ;
V_73:
F_36 ( V_2 -> V_61 . V_68 ) ;
V_2 -> V_61 . V_68 = NULL ;
return V_50 ;
}
static void F_37 ( const struct V_17 * V_18 ,
struct V_1 * V_2 )
{
if ( ! V_2 -> V_61 . V_68 )
return;
F_38 ( V_2 -> V_72 ) ;
F_36 ( V_2 -> V_61 . V_68 ) ;
V_2 -> V_61 . V_68 = NULL ;
}
static enum V_74 F_39 ( struct V_75 * V_76 )
{
struct V_77 * V_31 = V_76 -> V_31 -> V_78 ;
struct V_1 * V_2 = F_40 ( V_31 ) ;
int V_19 ;
unsigned long V_43 ;
bool V_35 = false ;
for ( V_19 = 0 ; V_19 < 4 ; ++ V_19 ) {
if ( V_2 -> V_79 [ V_19 ] == V_76 ) {
F_19 ( & V_2 -> V_27 . V_28 , V_43 ) ;
V_35 = V_2 -> V_27 . V_43 & F_41 ( V_19 + 1 ) ;
F_20 ( & V_2 -> V_27 . V_28 , V_43 ) ;
break;
}
}
return V_35 ? V_80 : V_81 ;
}
static void F_42 ( struct V_75 * V_76 ,
enum V_74 V_35 )
{
struct V_77 * V_31 = V_76 -> V_31 -> V_78 ;
struct V_1 * V_2 = F_40 ( V_31 ) ;
int V_19 ;
unsigned long V_43 ;
T_1 V_27 , V_82 ;
for ( V_19 = 0 ; V_19 < 4 ; ++ V_19 ) {
if ( V_2 -> V_79 [ V_19 ] == V_76 ) {
V_82 = F_41 ( V_19 + 1 ) ;
F_19 ( & V_2 -> V_27 . V_28 , V_43 ) ;
V_27 = V_2 -> V_27 . V_43 ;
if ( V_35 == V_81 )
F_43 ( V_2 , V_27 & ~ V_82 ) ;
else
F_43 ( V_2 , V_27 | V_82 ) ;
F_20 ( & V_2 -> V_27 . V_28 , V_43 ) ;
break;
}
}
}
static int F_44 ( const struct V_17 * V_18 ,
struct V_1 * V_2 )
{
struct V_77 * V_31 = & V_2 -> V_70 -> V_31 ;
T_2 V_83 = strlen ( F_45 ( V_31 ) ) + 9 ;
struct V_75 * V_84 ;
unsigned long V_43 ;
char * V_68 ;
int V_50 ;
V_84 = F_46 ( sizeof( struct V_75 ) + V_83 , V_69 ) ;
if ( ! V_84 )
return - V_42 ;
V_68 = ( void * ) & V_84 [ 1 ] ;
snprintf ( V_68 , V_83 , L_3 , F_45 ( V_31 ) , V_18 -> V_85 ) ;
V_84 -> V_68 = V_68 ;
V_84 -> V_86 = 0 ;
V_84 -> V_87 = 1 ;
V_84 -> V_88 = F_39 ;
V_84 -> V_89 = F_42 ;
V_2 -> V_79 [ V_18 -> V_85 ] = V_84 ;
V_50 = F_47 ( V_31 , V_84 ) ;
if ( V_50 )
goto V_73;
if ( V_18 -> V_85 == 0 ) {
F_19 ( & V_2 -> V_27 . V_28 , V_43 ) ;
F_43 ( V_2 , V_90 ) ;
F_20 ( & V_2 -> V_27 . V_28 , V_43 ) ;
}
return 0 ;
V_73:
V_2 -> V_79 [ V_18 -> V_85 ] = NULL ;
F_36 ( V_84 ) ;
return V_50 ;
}
static void F_48 ( const struct V_17 * V_18 ,
struct V_1 * V_2 )
{
if ( ! V_2 -> V_79 [ V_18 -> V_85 ] )
return;
F_49 ( V_2 -> V_79 [ V_18 -> V_85 ] ) ;
F_36 ( V_2 -> V_79 [ V_18 -> V_85 ] ) ;
V_2 -> V_79 [ V_18 -> V_85 ] = NULL ;
}
static void F_50 ( struct V_1 * V_2 ,
const T_1 * V_91 )
{
T_3 V_92 , V_93 , V_94 ;
if ( ! ( V_2 -> V_27 . V_43 & V_95 ) )
return;
V_92 = V_91 [ 2 ] << 2 ;
V_93 = V_91 [ 3 ] << 2 ;
V_94 = V_91 [ 4 ] << 2 ;
V_92 |= ( V_91 [ 0 ] >> 5 ) & 0x3 ;
V_93 |= ( V_91 [ 1 ] >> 4 ) & 0x2 ;
V_94 |= ( V_91 [ 1 ] >> 5 ) & 0x2 ;
F_51 ( V_2 -> V_91 , V_96 , V_92 - 0x200 ) ;
F_51 ( V_2 -> V_91 , V_97 , V_93 - 0x200 ) ;
F_51 ( V_2 -> V_91 , V_98 , V_94 - 0x200 ) ;
F_3 ( V_2 -> V_91 ) ;
}
static int F_52 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_12 ( V_31 ) ;
unsigned long V_43 ;
F_19 ( & V_2 -> V_27 . V_28 , V_43 ) ;
F_53 ( V_2 , true ) ;
F_20 ( & V_2 -> V_27 . V_28 , V_43 ) ;
return 0 ;
}
static void F_54 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_12 ( V_31 ) ;
unsigned long V_43 ;
F_19 ( & V_2 -> V_27 . V_28 , V_43 ) ;
F_53 ( V_2 , false ) ;
F_20 ( & V_2 -> V_27 . V_28 , V_43 ) ;
}
static int F_55 ( const struct V_17 * V_18 ,
struct V_1 * V_2 )
{
int V_50 ;
V_2 -> V_91 = F_56 () ;
if ( ! V_2 -> V_91 )
return - V_42 ;
F_57 ( V_2 -> V_91 , V_2 ) ;
V_2 -> V_91 -> V_99 = F_52 ;
V_2 -> V_91 -> V_100 = F_54 ;
V_2 -> V_91 -> V_31 . V_78 = & V_2 -> V_70 -> V_31 ;
V_2 -> V_91 -> V_101 . V_102 = V_2 -> V_70 -> V_103 ;
V_2 -> V_91 -> V_101 . V_104 = V_2 -> V_70 -> V_104 ;
V_2 -> V_91 -> V_101 . V_105 = V_2 -> V_70 -> V_105 ;
V_2 -> V_91 -> V_101 . V_106 = V_2 -> V_70 -> V_106 ;
V_2 -> V_91 -> V_68 = V_107 L_4 ;
F_5 ( V_108 , V_2 -> V_91 -> V_21 ) ;
F_5 ( V_96 , V_2 -> V_91 -> V_109 ) ;
F_5 ( V_97 , V_2 -> V_91 -> V_109 ) ;
F_5 ( V_98 , V_2 -> V_91 -> V_109 ) ;
F_58 ( V_2 -> V_91 , V_96 , - 500 , 500 , 2 , 4 ) ;
F_58 ( V_2 -> V_91 , V_97 , - 500 , 500 , 2 , 4 ) ;
F_58 ( V_2 -> V_91 , V_98 , - 500 , 500 , 2 , 4 ) ;
V_50 = F_59 ( V_2 -> V_91 ) ;
if ( V_50 ) {
F_33 ( V_2 -> V_70 , L_5 ) ;
goto V_73;
}
return 0 ;
V_73:
F_60 ( V_2 -> V_91 ) ;
V_2 -> V_91 = NULL ;
return V_50 ;
}
static void F_61 ( const struct V_17 * V_18 ,
struct V_1 * V_2 )
{
if ( ! V_2 -> V_91 )
return;
F_62 ( V_2 -> V_91 ) ;
V_2 -> V_91 = NULL ;
}
static void F_63 ( struct V_1 * V_2 , const T_1 * V_110 ,
bool V_111 , unsigned int V_101 )
{
T_3 V_92 , V_93 ;
T_1 V_112 , V_113 ;
bool V_114 = false ;
if ( ! ( V_2 -> V_27 . V_43 & V_115 ) )
return;
switch ( V_101 ) {
case 0 :
V_112 = V_116 ;
V_113 = V_117 ;
break;
case 1 :
V_112 = V_118 ;
V_113 = V_119 ;
break;
case 2 :
V_112 = V_120 ;
V_113 = V_121 ;
break;
case 3 :
V_112 = V_122 ;
V_113 = V_123 ;
V_114 = true ;
break;
default:
return;
}
if ( V_111 ) {
V_92 = V_110 [ 1 ] | ( ( V_110 [ 0 ] & 0x03 ) << 8 ) ;
V_93 = V_110 [ 2 ] | ( ( V_110 [ 0 ] & 0x0c ) << 6 ) ;
} else {
V_92 = V_110 [ 0 ] | ( ( V_110 [ 2 ] & 0x30 ) << 4 ) ;
V_93 = V_110 [ 1 ] | ( ( V_110 [ 2 ] & 0xc0 ) << 2 ) ;
}
F_51 ( V_2 -> V_110 , V_112 , V_92 ) ;
F_51 ( V_2 -> V_110 , V_113 , V_93 ) ;
if ( V_114 )
F_3 ( V_2 -> V_110 ) ;
}
static int F_64 ( struct V_1 * V_2 , T_3 V_124 )
{
int V_50 ;
unsigned long V_43 ;
T_1 V_125 = 0 ;
static const T_1 V_126 [] = { 0x01 } ;
static const T_1 V_127 [] = { 0x02 , 0x00 , 0x00 , 0x71 , 0x01 ,
0x00 , 0xaa , 0x00 , 0x64 } ;
static const T_1 V_128 [] = { 0x63 , 0x03 } ;
static const T_1 V_129 [] = { 0x08 } ;
F_19 ( & V_2 -> V_27 . V_28 , V_43 ) ;
if ( V_124 == ( V_2 -> V_27 . V_43 & V_115 ) ) {
F_20 ( & V_2 -> V_27 . V_28 , V_43 ) ;
return 0 ;
}
if ( V_124 == 0 ) {
V_2 -> V_27 . V_43 &= ~ V_115 ;
F_65 ( V_2 , 0 ) ;
F_66 ( V_2 , 0 ) ;
F_67 ( V_2 , V_130 ) ;
F_20 ( & V_2 -> V_27 . V_28 , V_43 ) ;
return 0 ;
}
F_20 ( & V_2 -> V_27 . V_28 , V_43 ) ;
V_50 = F_23 ( V_2 ) ;
if ( V_50 )
return V_50 ;
F_19 ( & V_2 -> V_27 . V_28 , V_43 ) ;
F_24 ( V_2 , V_131 , 0 ) ;
F_65 ( V_2 , 0x06 ) ;
F_20 ( & V_2 -> V_27 . V_28 , V_43 ) ;
V_50 = F_26 ( V_2 ) ;
if ( V_50 )
goto V_132;
if ( V_2 -> V_27 . V_133 ) {
V_50 = - V_134 ;
goto V_132;
}
F_19 ( & V_2 -> V_27 . V_28 , V_43 ) ;
F_24 ( V_2 , V_135 , 0 ) ;
F_66 ( V_2 , 0x06 ) ;
F_20 ( & V_2 -> V_27 . V_28 , V_43 ) ;
V_50 = F_26 ( V_2 ) ;
if ( V_50 )
goto V_132;
if ( V_2 -> V_27 . V_133 ) {
V_50 = - V_134 ;
goto V_132;
}
V_50 = F_68 ( V_2 , 0xb00030 , V_126 ,
sizeof( V_126 ) ) ;
if ( V_50 )
goto V_132;
V_50 = F_68 ( V_2 , 0xb00000 , V_127 ,
sizeof( V_127 ) ) ;
if ( V_50 )
goto V_132;
V_50 = F_68 ( V_2 , 0xb0001a , V_128 ,
sizeof( V_128 ) ) ;
if ( V_50 )
goto V_132;
switch ( V_124 ) {
case V_136 :
V_125 = 5 ;
break;
case V_137 :
V_125 = 3 ;
break;
case V_138 :
V_125 = 1 ;
break;
}
V_50 = F_68 ( V_2 , 0xb00033 , & V_125 , sizeof( V_125 ) ) ;
if ( V_50 )
goto V_132;
V_50 = F_68 ( V_2 , 0xb00030 , V_129 , sizeof( V_129 ) ) ;
if ( V_50 )
goto V_132;
F_19 ( & V_2 -> V_27 . V_28 , V_43 ) ;
V_2 -> V_27 . V_43 &= ~ V_115 ;
V_2 -> V_27 . V_43 |= V_124 & V_115 ;
F_67 ( V_2 , V_130 ) ;
F_20 ( & V_2 -> V_27 . V_28 , V_43 ) ;
V_132:
F_27 ( V_2 ) ;
return V_50 ;
}
static int F_69 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_12 ( V_31 ) ;
return F_64 ( V_2 , V_138 ) ;
}
static void F_70 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_12 ( V_31 ) ;
F_64 ( V_2 , 0 ) ;
}
static int F_71 ( const struct V_17 * V_18 ,
struct V_1 * V_2 )
{
int V_50 ;
V_2 -> V_110 = F_56 () ;
if ( ! V_2 -> V_110 )
return - V_42 ;
F_57 ( V_2 -> V_110 , V_2 ) ;
V_2 -> V_110 -> V_99 = F_69 ;
V_2 -> V_110 -> V_100 = F_70 ;
V_2 -> V_110 -> V_31 . V_78 = & V_2 -> V_70 -> V_31 ;
V_2 -> V_110 -> V_101 . V_102 = V_2 -> V_70 -> V_103 ;
V_2 -> V_110 -> V_101 . V_104 = V_2 -> V_70 -> V_104 ;
V_2 -> V_110 -> V_101 . V_105 = V_2 -> V_70 -> V_105 ;
V_2 -> V_110 -> V_101 . V_106 = V_2 -> V_70 -> V_106 ;
V_2 -> V_110 -> V_68 = V_107 L_6 ;
F_5 ( V_108 , V_2 -> V_110 -> V_21 ) ;
F_5 ( V_116 , V_2 -> V_110 -> V_109 ) ;
F_5 ( V_117 , V_2 -> V_110 -> V_109 ) ;
F_5 ( V_118 , V_2 -> V_110 -> V_109 ) ;
F_5 ( V_119 , V_2 -> V_110 -> V_109 ) ;
F_5 ( V_120 , V_2 -> V_110 -> V_109 ) ;
F_5 ( V_121 , V_2 -> V_110 -> V_109 ) ;
F_5 ( V_122 , V_2 -> V_110 -> V_109 ) ;
F_5 ( V_123 , V_2 -> V_110 -> V_109 ) ;
F_58 ( V_2 -> V_110 , V_116 , 0 , 1023 , 2 , 4 ) ;
F_58 ( V_2 -> V_110 , V_117 , 0 , 767 , 2 , 4 ) ;
F_58 ( V_2 -> V_110 , V_118 , 0 , 1023 , 2 , 4 ) ;
F_58 ( V_2 -> V_110 , V_119 , 0 , 767 , 2 , 4 ) ;
F_58 ( V_2 -> V_110 , V_120 , 0 , 1023 , 2 , 4 ) ;
F_58 ( V_2 -> V_110 , V_121 , 0 , 767 , 2 , 4 ) ;
F_58 ( V_2 -> V_110 , V_122 , 0 , 1023 , 2 , 4 ) ;
F_58 ( V_2 -> V_110 , V_123 , 0 , 767 , 2 , 4 ) ;
V_50 = F_59 ( V_2 -> V_110 ) ;
if ( V_50 ) {
F_33 ( V_2 -> V_70 , L_5 ) ;
goto V_73;
}
return 0 ;
V_73:
F_60 ( V_2 -> V_110 ) ;
V_2 -> V_110 = NULL ;
return V_50 ;
}
static void F_72 ( const struct V_17 * V_18 ,
struct V_1 * V_2 )
{
if ( ! V_2 -> V_110 )
return;
F_62 ( V_2 -> V_110 ) ;
V_2 -> V_110 = NULL ;
}
static void F_73 ( struct V_1 * V_2 , const T_1 * V_139 )
{
T_4 V_92 , V_93 , V_94 , V_140 , V_141 ;
V_140 = V_139 [ 0 ] ;
V_141 = V_139 [ 1 ] ;
V_140 -= 128 ;
V_141 -= 128 ;
V_92 = V_139 [ 2 ] << 2 ;
V_93 = V_139 [ 3 ] << 2 ;
V_94 = V_139 [ 4 ] << 2 ;
if ( V_2 -> V_27 . V_43 & V_142 ) {
V_92 |= ( V_139 [ 5 ] >> 3 ) & 0x02 ;
V_93 |= ( V_139 [ 5 ] >> 4 ) & 0x02 ;
V_94 &= ~ 0x4 ;
V_94 |= ( V_139 [ 5 ] >> 5 ) & 0x06 ;
} else {
V_92 |= ( V_139 [ 5 ] >> 2 ) & 0x03 ;
V_93 |= ( V_139 [ 5 ] >> 4 ) & 0x03 ;
V_94 |= ( V_139 [ 5 ] >> 6 ) & 0x03 ;
}
V_92 -= 0x200 ;
V_93 -= 0x200 ;
V_94 -= 0x200 ;
F_51 ( V_2 -> V_143 . V_4 , V_116 , V_140 ) ;
F_51 ( V_2 -> V_143 . V_4 , V_117 , V_141 ) ;
F_51 ( V_2 -> V_143 . V_4 , V_96 , V_92 ) ;
F_51 ( V_2 -> V_143 . V_4 , V_97 , V_93 ) ;
F_51 ( V_2 -> V_143 . V_4 , V_98 , V_94 ) ;
if ( V_2 -> V_27 . V_43 & V_142 ) {
F_2 ( V_2 -> V_143 . V_4 ,
V_144 [ V_145 ] ,
! ( V_139 [ 5 ] & 0x04 ) ) ;
F_2 ( V_2 -> V_143 . V_4 ,
V_144 [ V_146 ] ,
! ( V_139 [ 5 ] & 0x08 ) ) ;
} else {
F_2 ( V_2 -> V_143 . V_4 ,
V_144 [ V_145 ] ,
! ( V_139 [ 5 ] & 0x01 ) ) ;
F_2 ( V_2 -> V_143 . V_4 ,
V_144 [ V_146 ] ,
! ( V_139 [ 5 ] & 0x02 ) ) ;
}
F_3 ( V_2 -> V_143 . V_4 ) ;
}
static int F_74 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_12 ( V_31 ) ;
unsigned long V_43 ;
F_19 ( & V_2 -> V_27 . V_28 , V_43 ) ;
V_2 -> V_27 . V_43 |= V_147 ;
F_67 ( V_2 , V_130 ) ;
F_20 ( & V_2 -> V_27 . V_28 , V_43 ) ;
return 0 ;
}
static void F_75 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_12 ( V_31 ) ;
unsigned long V_43 ;
F_19 ( & V_2 -> V_27 . V_28 , V_43 ) ;
V_2 -> V_27 . V_43 &= ~ V_147 ;
F_67 ( V_2 , V_130 ) ;
F_20 ( & V_2 -> V_27 . V_28 , V_43 ) ;
}
static int F_76 ( const struct V_17 * V_18 ,
struct V_1 * V_2 )
{
int V_50 , V_19 ;
V_2 -> V_143 . V_4 = F_56 () ;
if ( ! V_2 -> V_143 . V_4 )
return - V_42 ;
F_57 ( V_2 -> V_143 . V_4 , V_2 ) ;
V_2 -> V_143 . V_4 -> V_99 = F_74 ;
V_2 -> V_143 . V_4 -> V_100 = F_75 ;
V_2 -> V_143 . V_4 -> V_31 . V_78 = & V_2 -> V_70 -> V_31 ;
V_2 -> V_143 . V_4 -> V_101 . V_102 = V_2 -> V_70 -> V_103 ;
V_2 -> V_143 . V_4 -> V_101 . V_104 = V_2 -> V_70 -> V_104 ;
V_2 -> V_143 . V_4 -> V_101 . V_105 = V_2 -> V_70 -> V_105 ;
V_2 -> V_143 . V_4 -> V_101 . V_106 = V_2 -> V_70 -> V_106 ;
V_2 -> V_143 . V_4 -> V_68 = V_107 L_7 ;
F_5 ( V_20 , V_2 -> V_143 . V_4 -> V_21 ) ;
for ( V_19 = 0 ; V_19 < V_148 ; ++ V_19 )
F_5 ( V_144 [ V_19 ] ,
V_2 -> V_143 . V_4 -> V_23 ) ;
F_5 ( V_108 , V_2 -> V_143 . V_4 -> V_21 ) ;
F_5 ( V_116 , V_2 -> V_143 . V_4 -> V_109 ) ;
F_5 ( V_117 , V_2 -> V_143 . V_4 -> V_109 ) ;
F_58 ( V_2 -> V_143 . V_4 ,
V_116 , - 120 , 120 , 2 , 4 ) ;
F_58 ( V_2 -> V_143 . V_4 ,
V_117 , - 120 , 120 , 2 , 4 ) ;
F_5 ( V_96 , V_2 -> V_143 . V_4 -> V_109 ) ;
F_5 ( V_97 , V_2 -> V_143 . V_4 -> V_109 ) ;
F_5 ( V_98 , V_2 -> V_143 . V_4 -> V_109 ) ;
F_58 ( V_2 -> V_143 . V_4 ,
V_96 , - 500 , 500 , 2 , 4 ) ;
F_58 ( V_2 -> V_143 . V_4 ,
V_97 , - 500 , 500 , 2 , 4 ) ;
F_58 ( V_2 -> V_143 . V_4 ,
V_98 , - 500 , 500 , 2 , 4 ) ;
V_50 = F_59 ( V_2 -> V_143 . V_4 ) ;
if ( V_50 )
goto V_73;
return 0 ;
V_73:
F_60 ( V_2 -> V_143 . V_4 ) ;
V_2 -> V_143 . V_4 = NULL ;
return V_50 ;
}
static void F_77 ( const struct V_17 * V_18 ,
struct V_1 * V_2 )
{
if ( ! V_2 -> V_143 . V_4 )
return;
F_62 ( V_2 -> V_143 . V_4 ) ;
V_2 -> V_143 . V_4 = NULL ;
}
static void F_78 ( struct V_1 * V_2 , const T_1 * V_139 )
{
T_5 V_149 , V_150 , V_151 , V_152 , V_153 , V_154 ;
if ( V_2 -> V_27 . V_43 & V_142 ) {
V_151 = V_139 [ 0 ] & 0x3e ;
V_152 = V_139 [ 1 ] & 0x3e ;
} else {
V_151 = V_139 [ 0 ] & 0x3f ;
V_152 = V_139 [ 1 ] & 0x3f ;
}
V_149 = ( V_139 [ 0 ] >> 3 ) & 0x18 ;
V_149 |= ( V_139 [ 1 ] >> 5 ) & 0x06 ;
V_149 |= ( V_139 [ 2 ] >> 7 ) & 0x01 ;
V_150 = V_139 [ 2 ] & 0x1f ;
V_154 = V_139 [ 3 ] & 0x1f ;
V_153 = ( V_139 [ 2 ] >> 2 ) & 0x18 ;
V_153 |= ( V_139 [ 3 ] >> 5 ) & 0x07 ;
V_149 <<= 1 ;
V_150 <<= 1 ;
V_154 <<= 1 ;
V_153 <<= 1 ;
F_51 ( V_2 -> V_143 . V_4 , V_118 , V_151 - 0x20 ) ;
F_51 ( V_2 -> V_143 . V_4 , V_119 , V_152 - 0x20 ) ;
F_51 ( V_2 -> V_143 . V_4 , V_120 , V_149 - 0x20 ) ;
F_51 ( V_2 -> V_143 . V_4 , V_121 , V_150 - 0x20 ) ;
F_51 ( V_2 -> V_143 . V_4 , V_122 , V_154 ) ;
F_51 ( V_2 -> V_143 . V_4 , V_123 , V_153 ) ;
F_2 ( V_2 -> V_143 . V_4 ,
V_155 [ V_156 ] ,
! ( V_139 [ 4 ] & 0x80 ) ) ;
F_2 ( V_2 -> V_143 . V_4 ,
V_155 [ V_157 ] ,
! ( V_139 [ 4 ] & 0x40 ) ) ;
F_2 ( V_2 -> V_143 . V_4 ,
V_155 [ V_158 ] ,
! ( V_139 [ 4 ] & 0x20 ) ) ;
F_2 ( V_2 -> V_143 . V_4 ,
V_155 [ V_159 ] ,
! ( V_139 [ 4 ] & 0x10 ) ) ;
F_2 ( V_2 -> V_143 . V_4 ,
V_155 [ V_160 ] ,
! ( V_139 [ 4 ] & 0x08 ) ) ;
F_2 ( V_2 -> V_143 . V_4 ,
V_155 [ V_161 ] ,
! ( V_139 [ 4 ] & 0x04 ) ) ;
F_2 ( V_2 -> V_143 . V_4 ,
V_155 [ V_162 ] ,
! ( V_139 [ 4 ] & 0x02 ) ) ;
F_2 ( V_2 -> V_143 . V_4 ,
V_155 [ V_163 ] ,
! ( V_139 [ 5 ] & 0x80 ) ) ;
F_2 ( V_2 -> V_143 . V_4 ,
V_155 [ V_164 ] ,
! ( V_139 [ 5 ] & 0x40 ) ) ;
F_2 ( V_2 -> V_143 . V_4 ,
V_155 [ V_165 ] ,
! ( V_139 [ 5 ] & 0x20 ) ) ;
F_2 ( V_2 -> V_143 . V_4 ,
V_155 [ V_166 ] ,
! ( V_139 [ 5 ] & 0x10 ) ) ;
F_2 ( V_2 -> V_143 . V_4 ,
V_155 [ V_167 ] ,
! ( V_139 [ 5 ] & 0x08 ) ) ;
F_2 ( V_2 -> V_143 . V_4 ,
V_155 [ V_168 ] ,
! ( V_139 [ 5 ] & 0x04 ) ) ;
if ( V_2 -> V_27 . V_43 & V_142 ) {
F_2 ( V_2 -> V_143 . V_4 ,
V_155 [ V_169 ] ,
! ( V_139 [ 1 ] & 0x01 ) ) ;
F_2 ( V_2 -> V_143 . V_4 ,
V_155 [ V_170 ] ,
! ( V_139 [ 0 ] & 0x01 ) ) ;
} else {
F_2 ( V_2 -> V_143 . V_4 ,
V_155 [ V_169 ] ,
! ( V_139 [ 5 ] & 0x02 ) ) ;
F_2 ( V_2 -> V_143 . V_4 ,
V_155 [ V_170 ] ,
! ( V_139 [ 5 ] & 0x01 ) ) ;
}
F_3 ( V_2 -> V_143 . V_4 ) ;
}
static int F_79 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_12 ( V_31 ) ;
unsigned long V_43 ;
F_19 ( & V_2 -> V_27 . V_28 , V_43 ) ;
V_2 -> V_27 . V_43 |= V_147 ;
F_67 ( V_2 , V_130 ) ;
F_20 ( & V_2 -> V_27 . V_28 , V_43 ) ;
return 0 ;
}
static void F_80 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_12 ( V_31 ) ;
unsigned long V_43 ;
F_19 ( & V_2 -> V_27 . V_28 , V_43 ) ;
V_2 -> V_27 . V_43 &= ~ V_147 ;
F_67 ( V_2 , V_130 ) ;
F_20 ( & V_2 -> V_27 . V_28 , V_43 ) ;
}
static int F_81 ( const struct V_17 * V_18 ,
struct V_1 * V_2 )
{
int V_50 , V_19 ;
V_2 -> V_143 . V_4 = F_56 () ;
if ( ! V_2 -> V_143 . V_4 )
return - V_42 ;
F_57 ( V_2 -> V_143 . V_4 , V_2 ) ;
V_2 -> V_143 . V_4 -> V_99 = F_79 ;
V_2 -> V_143 . V_4 -> V_100 = F_80 ;
V_2 -> V_143 . V_4 -> V_31 . V_78 = & V_2 -> V_70 -> V_31 ;
V_2 -> V_143 . V_4 -> V_101 . V_102 = V_2 -> V_70 -> V_103 ;
V_2 -> V_143 . V_4 -> V_101 . V_104 = V_2 -> V_70 -> V_104 ;
V_2 -> V_143 . V_4 -> V_101 . V_105 = V_2 -> V_70 -> V_105 ;
V_2 -> V_143 . V_4 -> V_101 . V_106 = V_2 -> V_70 -> V_106 ;
V_2 -> V_143 . V_4 -> V_68 = V_107 L_8 ;
F_5 ( V_20 , V_2 -> V_143 . V_4 -> V_21 ) ;
for ( V_19 = 0 ; V_19 < V_171 ; ++ V_19 )
F_5 ( V_155 [ V_19 ] ,
V_2 -> V_143 . V_4 -> V_23 ) ;
F_5 ( V_108 , V_2 -> V_143 . V_4 -> V_21 ) ;
F_5 ( V_118 , V_2 -> V_143 . V_4 -> V_109 ) ;
F_5 ( V_119 , V_2 -> V_143 . V_4 -> V_109 ) ;
F_5 ( V_120 , V_2 -> V_143 . V_4 -> V_109 ) ;
F_5 ( V_121 , V_2 -> V_143 . V_4 -> V_109 ) ;
F_5 ( V_122 , V_2 -> V_143 . V_4 -> V_109 ) ;
F_5 ( V_123 , V_2 -> V_143 . V_4 -> V_109 ) ;
F_58 ( V_2 -> V_143 . V_4 ,
V_118 , - 30 , 30 , 1 , 1 ) ;
F_58 ( V_2 -> V_143 . V_4 ,
V_119 , - 30 , 30 , 1 , 1 ) ;
F_58 ( V_2 -> V_143 . V_4 ,
V_120 , - 30 , 30 , 1 , 1 ) ;
F_58 ( V_2 -> V_143 . V_4 ,
V_121 , - 30 , 30 , 1 , 1 ) ;
F_58 ( V_2 -> V_143 . V_4 ,
V_122 , - 30 , 30 , 1 , 1 ) ;
F_58 ( V_2 -> V_143 . V_4 ,
V_123 , - 30 , 30 , 1 , 1 ) ;
V_50 = F_59 ( V_2 -> V_143 . V_4 ) ;
if ( V_50 )
goto V_73;
return 0 ;
V_73:
F_60 ( V_2 -> V_143 . V_4 ) ;
V_2 -> V_143 . V_4 = NULL ;
return V_50 ;
}
static void F_82 ( const struct V_17 * V_18 ,
struct V_1 * V_2 )
{
if ( ! V_2 -> V_143 . V_4 )
return;
F_62 ( V_2 -> V_143 . V_4 ) ;
V_2 -> V_143 . V_4 = NULL ;
}
static void F_83 ( struct V_1 * V_2 , const T_1 * V_3 )
{
F_2 ( V_2 -> V_143 . V_4 , V_172 ,
! ! ( V_3 [ 1 ] & 0x08 ) ) ;
F_3 ( V_2 -> V_143 . V_4 ) ;
}
static void F_84 ( struct V_1 * V_2 ,
const T_1 * V_139 )
{
T_6 V_49 [ 4 ] , V_173 , div ;
unsigned int V_19 ;
struct V_174 * V_175 = & V_2 -> V_27 ;
V_49 [ 0 ] = V_139 [ 0 ] ;
V_49 [ 0 ] <<= 8 ;
V_49 [ 0 ] |= V_139 [ 1 ] ;
V_49 [ 1 ] = V_139 [ 2 ] ;
V_49 [ 1 ] <<= 8 ;
V_49 [ 1 ] |= V_139 [ 3 ] ;
V_49 [ 2 ] = V_139 [ 4 ] ;
V_49 [ 2 ] <<= 8 ;
V_49 [ 2 ] |= V_139 [ 5 ] ;
V_49 [ 3 ] = V_139 [ 6 ] ;
V_49 [ 3 ] <<= 8 ;
V_49 [ 3 ] |= V_139 [ 7 ] ;
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
if ( V_49 [ V_19 ] <= V_175 -> V_176 [ V_19 ] [ 0 ] ) {
V_173 = 0 ;
} else if ( V_49 [ V_19 ] < V_175 -> V_176 [ V_19 ] [ 1 ] ) {
V_173 = V_49 [ V_19 ] - V_175 -> V_176 [ V_19 ] [ 0 ] ;
V_173 *= 1700 ;
div = V_175 -> V_176 [ V_19 ] [ 1 ] - V_175 -> V_176 [ V_19 ] [ 0 ] ;
V_173 /= div ? div : 1 ;
} else {
V_173 = V_49 [ V_19 ] - V_175 -> V_176 [ V_19 ] [ 1 ] ;
V_173 *= 1700 ;
div = V_175 -> V_176 [ V_19 ] [ 2 ] - V_175 -> V_176 [ V_19 ] [ 1 ] ;
V_173 /= div ? div : 1 ;
V_173 += 1700 ;
}
V_49 [ V_19 ] = V_173 ;
}
F_51 ( V_2 -> V_143 . V_4 , V_116 , V_49 [ 0 ] ) ;
F_51 ( V_2 -> V_143 . V_4 , V_117 , V_49 [ 1 ] ) ;
F_51 ( V_2 -> V_143 . V_4 , V_118 , V_49 [ 2 ] ) ;
F_51 ( V_2 -> V_143 . V_4 , V_119 , V_49 [ 3 ] ) ;
F_3 ( V_2 -> V_143 . V_4 ) ;
}
static int F_85 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_12 ( V_31 ) ;
unsigned long V_43 ;
F_19 ( & V_2 -> V_27 . V_28 , V_43 ) ;
V_2 -> V_27 . V_43 |= V_147 ;
F_67 ( V_2 , V_130 ) ;
F_20 ( & V_2 -> V_27 . V_28 , V_43 ) ;
return 0 ;
}
static void F_86 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_12 ( V_31 ) ;
unsigned long V_43 ;
F_19 ( & V_2 -> V_27 . V_28 , V_43 ) ;
V_2 -> V_27 . V_43 &= ~ V_147 ;
F_67 ( V_2 , V_130 ) ;
F_20 ( & V_2 -> V_27 . V_28 , V_43 ) ;
}
static T_7 F_87 ( struct V_77 * V_31 ,
struct V_177 * V_178 ,
char * V_179 )
{
struct V_1 * V_2 = F_40 ( V_31 ) ;
int V_19 , V_180 , V_50 ;
T_3 V_49 ;
T_1 V_181 [ 24 ] , V_182 ;
V_50 = F_23 ( V_2 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_88 ( V_2 , 0xa40024 , V_181 , 12 ) ;
if ( V_50 != 12 ) {
F_27 ( V_2 ) ;
return V_50 < 0 ? V_50 : - V_134 ;
}
V_50 = F_88 ( V_2 , 0xa40024 + 12 , V_181 + 12 , 12 ) ;
if ( V_50 != 12 ) {
F_27 ( V_2 ) ;
return V_50 < 0 ? V_50 : - V_134 ;
}
F_27 ( V_2 ) ;
F_8 ( & V_2 -> V_27 . V_28 ) ;
V_182 = 0 ;
for ( V_19 = 0 ; V_19 < 3 ; ++ V_19 ) {
for ( V_180 = 0 ; V_180 < 4 ; ++ V_180 ) {
V_2 -> V_27 . V_176 [ V_180 ] [ V_19 ] = V_181 [ V_182 ] ;
V_2 -> V_27 . V_176 [ V_180 ] [ V_19 ] <<= 8 ;
V_2 -> V_27 . V_176 [ V_180 ] [ V_19 ] |= V_181 [ V_182 + 1 ] ;
V_182 += 2 ;
}
}
F_10 ( & V_2 -> V_27 . V_28 ) ;
V_50 = 0 ;
for ( V_19 = 0 ; V_19 < 3 ; ++ V_19 ) {
for ( V_180 = 0 ; V_180 < 4 ; ++ V_180 ) {
V_49 = V_2 -> V_27 . V_176 [ V_180 ] [ V_19 ] ;
if ( V_19 == 2 && V_180 == 3 )
V_50 += sprintf ( & V_179 [ V_50 ] , L_9 , V_49 ) ;
else
V_50 += sprintf ( & V_179 [ V_50 ] , L_10 , V_49 ) ;
}
}
return V_50 ;
}
static int F_89 ( const struct V_17 * V_18 ,
struct V_1 * V_2 )
{
int V_50 , V_19 , V_180 ;
T_1 V_181 [ 24 ] , V_182 ;
F_90 ( V_2 ) ;
V_50 = F_88 ( V_2 , 0xa40024 , V_181 , 12 ) ;
if ( V_50 != 12 ) {
F_27 ( V_2 ) ;
return V_50 < 0 ? V_50 : - V_134 ;
}
V_50 = F_88 ( V_2 , 0xa40024 + 12 , V_181 + 12 , 12 ) ;
if ( V_50 != 12 ) {
F_27 ( V_2 ) ;
return V_50 < 0 ? V_50 : - V_134 ;
}
F_27 ( V_2 ) ;
V_182 = 0 ;
for ( V_19 = 0 ; V_19 < 3 ; ++ V_19 ) {
for ( V_180 = 0 ; V_180 < 4 ; ++ V_180 ) {
V_2 -> V_27 . V_176 [ V_180 ] [ V_19 ] = V_181 [ V_182 ] ;
V_2 -> V_27 . V_176 [ V_180 ] [ V_19 ] <<= 8 ;
V_2 -> V_27 . V_176 [ V_180 ] [ V_19 ] |= V_181 [ V_182 + 1 ] ;
V_182 += 2 ;
}
}
V_2 -> V_143 . V_4 = F_56 () ;
if ( ! V_2 -> V_143 . V_4 )
return - V_42 ;
V_50 = F_91 ( & V_2 -> V_70 -> V_31 ,
& V_183 ) ;
if ( V_50 ) {
F_33 ( V_2 -> V_70 , L_11 ) ;
goto V_73;
}
F_57 ( V_2 -> V_143 . V_4 , V_2 ) ;
V_2 -> V_143 . V_4 -> V_99 = F_85 ;
V_2 -> V_143 . V_4 -> V_100 = F_86 ;
V_2 -> V_143 . V_4 -> V_31 . V_78 = & V_2 -> V_70 -> V_31 ;
V_2 -> V_143 . V_4 -> V_101 . V_102 = V_2 -> V_70 -> V_103 ;
V_2 -> V_143 . V_4 -> V_101 . V_104 = V_2 -> V_70 -> V_104 ;
V_2 -> V_143 . V_4 -> V_101 . V_105 = V_2 -> V_70 -> V_105 ;
V_2 -> V_143 . V_4 -> V_101 . V_106 = V_2 -> V_70 -> V_106 ;
V_2 -> V_143 . V_4 -> V_68 = V_107 L_12 ;
F_5 ( V_20 , V_2 -> V_143 . V_4 -> V_21 ) ;
F_5 ( V_172 , V_2 -> V_143 . V_4 -> V_23 ) ;
F_5 ( V_108 , V_2 -> V_143 . V_4 -> V_21 ) ;
F_5 ( V_116 , V_2 -> V_143 . V_4 -> V_109 ) ;
F_5 ( V_117 , V_2 -> V_143 . V_4 -> V_109 ) ;
F_5 ( V_118 , V_2 -> V_143 . V_4 -> V_109 ) ;
F_5 ( V_119 , V_2 -> V_143 . V_4 -> V_109 ) ;
F_58 ( V_2 -> V_143 . V_4 ,
V_116 , 0 , 65535 , 2 , 4 ) ;
F_58 ( V_2 -> V_143 . V_4 ,
V_117 , 0 , 65535 , 2 , 4 ) ;
F_58 ( V_2 -> V_143 . V_4 ,
V_118 , 0 , 65535 , 2 , 4 ) ;
F_58 ( V_2 -> V_143 . V_4 ,
V_119 , 0 , 65535 , 2 , 4 ) ;
V_50 = F_59 ( V_2 -> V_143 . V_4 ) ;
if ( V_50 )
goto V_184;
return 0 ;
V_184:
F_92 ( & V_2 -> V_70 -> V_31 ,
& V_183 ) ;
V_73:
F_60 ( V_2 -> V_143 . V_4 ) ;
V_2 -> V_143 . V_4 = NULL ;
return V_50 ;
}
static void F_93 ( const struct V_17 * V_18 ,
struct V_1 * V_2 )
{
if ( ! V_2 -> V_143 . V_4 )
return;
F_62 ( V_2 -> V_143 . V_4 ) ;
V_2 -> V_143 . V_4 = NULL ;
F_92 ( & V_2 -> V_70 -> V_31 ,
& V_183 ) ;
}
static void F_94 ( struct V_1 * V_2 , const T_1 * V_139 )
{
T_4 V_149 , V_150 , V_151 , V_152 ;
V_151 = ( V_139 [ 0 ] & 0xff ) | ( ( V_139 [ 1 ] & 0x0f ) << 8 ) ;
V_149 = ( V_139 [ 2 ] & 0xff ) | ( ( V_139 [ 3 ] & 0x0f ) << 8 ) ;
V_152 = ( V_139 [ 4 ] & 0xff ) | ( ( V_139 [ 5 ] & 0x0f ) << 8 ) ;
V_150 = ( V_139 [ 6 ] & 0xff ) | ( ( V_139 [ 7 ] & 0x0f ) << 8 ) ;
V_151 -= 0x800 ;
V_152 = 0x800 - V_152 ;
V_149 -= 0x800 ;
V_150 = 0x800 - V_150 ;
if ( ! ( V_2 -> V_27 . V_43 & V_185 ) ) {
V_2 -> V_27 . V_43 |= V_185 ;
if ( abs ( V_151 ) < 500 )
V_2 -> V_27 . V_186 [ 0 ] = - V_151 ;
if ( abs ( V_152 ) < 500 )
V_2 -> V_27 . V_186 [ 1 ] = - V_152 ;
if ( abs ( V_149 ) < 500 )
V_2 -> V_27 . V_186 [ 2 ] = - V_149 ;
if ( abs ( V_150 ) < 500 )
V_2 -> V_27 . V_186 [ 3 ] = - V_150 ;
}
V_151 += V_2 -> V_27 . V_186 [ 0 ] ;
V_152 += V_2 -> V_27 . V_186 [ 1 ] ;
V_149 += V_2 -> V_27 . V_186 [ 2 ] ;
V_150 += V_2 -> V_27 . V_186 [ 3 ] ;
F_51 ( V_2 -> V_143 . V_4 , V_187 , V_151 ) ;
F_51 ( V_2 -> V_143 . V_4 , V_188 , V_152 ) ;
F_51 ( V_2 -> V_143 . V_4 , V_96 , V_149 ) ;
F_51 ( V_2 -> V_143 . V_4 , V_97 , V_150 ) ;
F_2 ( V_2 -> V_143 . V_4 ,
V_189 [ V_190 ] ,
! ( V_139 [ 8 ] & 0x80 ) ) ;
F_2 ( V_2 -> V_143 . V_4 ,
V_189 [ V_191 ] ,
! ( V_139 [ 8 ] & 0x40 ) ) ;
F_2 ( V_2 -> V_143 . V_4 ,
V_189 [ V_192 ] ,
! ( V_139 [ 8 ] & 0x20 ) ) ;
F_2 ( V_2 -> V_143 . V_4 ,
V_189 [ V_193 ] ,
! ( V_139 [ 8 ] & 0x10 ) ) ;
F_2 ( V_2 -> V_143 . V_4 ,
V_189 [ V_194 ] ,
! ( V_139 [ 8 ] & 0x08 ) ) ;
F_2 ( V_2 -> V_143 . V_4 ,
V_189 [ V_195 ] ,
! ( V_139 [ 8 ] & 0x04 ) ) ;
F_2 ( V_2 -> V_143 . V_4 ,
V_189 [ V_196 ] ,
! ( V_139 [ 8 ] & 0x02 ) ) ;
F_2 ( V_2 -> V_143 . V_4 ,
V_189 [ V_197 ] ,
! ( V_139 [ 9 ] & 0x80 ) ) ;
F_2 ( V_2 -> V_143 . V_4 ,
V_189 [ V_198 ] ,
! ( V_139 [ 9 ] & 0x40 ) ) ;
F_2 ( V_2 -> V_143 . V_4 ,
V_189 [ V_199 ] ,
! ( V_139 [ 9 ] & 0x20 ) ) ;
F_2 ( V_2 -> V_143 . V_4 ,
V_189 [ V_200 ] ,
! ( V_139 [ 9 ] & 0x10 ) ) ;
F_2 ( V_2 -> V_143 . V_4 ,
V_189 [ V_201 ] ,
! ( V_139 [ 9 ] & 0x08 ) ) ;
F_2 ( V_2 -> V_143 . V_4 ,
V_189 [ V_202 ] ,
! ( V_139 [ 9 ] & 0x04 ) ) ;
F_2 ( V_2 -> V_143 . V_4 ,
V_189 [ V_203 ] ,
! ( V_139 [ 9 ] & 0x02 ) ) ;
F_2 ( V_2 -> V_143 . V_4 ,
V_189 [ V_204 ] ,
! ( V_139 [ 9 ] & 0x01 ) ) ;
F_2 ( V_2 -> V_143 . V_4 ,
V_189 [ V_205 ] ,
! ( V_139 [ 10 ] & 0x02 ) ) ;
F_2 ( V_2 -> V_143 . V_4 ,
V_189 [ V_206 ] ,
! ( V_139 [ 10 ] & 0x01 ) ) ;
F_3 ( V_2 -> V_143 . V_4 ) ;
}
static int F_95 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_12 ( V_31 ) ;
unsigned long V_43 ;
F_19 ( & V_2 -> V_27 . V_28 , V_43 ) ;
V_2 -> V_27 . V_43 |= V_147 ;
F_67 ( V_2 , V_130 ) ;
F_20 ( & V_2 -> V_27 . V_28 , V_43 ) ;
return 0 ;
}
static void F_96 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_12 ( V_31 ) ;
unsigned long V_43 ;
F_19 ( & V_2 -> V_27 . V_28 , V_43 ) ;
V_2 -> V_27 . V_43 &= ~ V_147 ;
F_67 ( V_2 , V_130 ) ;
F_20 ( & V_2 -> V_27 . V_28 , V_43 ) ;
}
static int F_97 ( struct V_30 * V_31 , void * V_32 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 = F_12 ( V_31 ) ;
T_1 V_35 ;
if ( V_34 -> V_36 . V_37 . V_38 || V_34 -> V_36 . V_37 . V_39 )
V_35 = 1 ;
else
V_35 = 0 ;
V_2 -> V_27 . V_29 = V_35 ;
F_13 ( & V_2 -> V_26 ) ;
return 0 ;
}
static T_7 F_98 ( struct V_77 * V_31 ,
struct V_177 * V_178 ,
char * V_179 )
{
struct V_1 * V_2 = F_40 ( V_31 ) ;
int V_207 ;
V_207 = 0 ;
V_207 += sprintf ( & V_179 [ V_207 ] , L_13 , V_2 -> V_27 . V_186 [ 0 ] ) ;
V_207 += sprintf ( & V_179 [ V_207 ] , L_14 , V_2 -> V_27 . V_186 [ 1 ] ) ;
V_207 += sprintf ( & V_179 [ V_207 ] , L_13 , V_2 -> V_27 . V_186 [ 2 ] ) ;
V_207 += sprintf ( & V_179 [ V_207 ] , L_15 , V_2 -> V_27 . V_186 [ 3 ] ) ;
return V_207 ;
}
static T_7 F_99 ( struct V_77 * V_31 ,
struct V_177 * V_178 ,
const char * V_181 , T_2 V_208 )
{
struct V_1 * V_2 = F_40 ( V_31 ) ;
int V_207 ;
T_8 V_209 , y1 , V_210 , V_211 ;
if ( ! strncmp ( V_181 , L_16 , 5 ) ) {
F_8 ( & V_2 -> V_27 . V_28 ) ;
V_2 -> V_27 . V_43 &= ~ V_185 ;
F_10 ( & V_2 -> V_27 . V_28 ) ;
} else {
V_207 = sscanf ( V_181 , L_17 , & V_209 , & y1 , & V_210 , & V_211 ) ;
if ( V_207 != 4 )
return - V_55 ;
F_8 ( & V_2 -> V_27 . V_28 ) ;
V_2 -> V_27 . V_43 |= V_185 ;
F_10 ( & V_2 -> V_27 . V_28 ) ;
V_2 -> V_27 . V_186 [ 0 ] = V_209 ;
V_2 -> V_27 . V_186 [ 1 ] = y1 ;
V_2 -> V_27 . V_186 [ 2 ] = V_210 ;
V_2 -> V_27 . V_186 [ 3 ] = V_211 ;
}
return F_100 ( V_181 , V_212 ) ;
}
static int F_101 ( const struct V_17 * V_18 ,
struct V_1 * V_2 )
{
int V_50 , V_19 ;
unsigned long V_43 ;
F_15 ( & V_2 -> V_26 , F_6 ) ;
V_2 -> V_27 . V_186 [ 0 ] = 0 ;
V_2 -> V_27 . V_186 [ 1 ] = 0 ;
V_2 -> V_27 . V_186 [ 2 ] = 0 ;
V_2 -> V_27 . V_186 [ 3 ] = 0 ;
F_19 ( & V_2 -> V_27 . V_28 , V_43 ) ;
V_2 -> V_27 . V_43 &= ~ V_185 ;
F_20 ( & V_2 -> V_27 . V_28 , V_43 ) ;
V_2 -> V_143 . V_4 = F_56 () ;
if ( ! V_2 -> V_143 . V_4 )
return - V_42 ;
F_5 ( V_40 , V_2 -> V_143 . V_4 -> V_41 ) ;
F_57 ( V_2 -> V_143 . V_4 , V_2 ) ;
if ( F_16 ( V_2 -> V_143 . V_4 , NULL ,
F_97 ) ) {
V_50 = - V_42 ;
goto V_73;
}
V_50 = F_91 ( & V_2 -> V_70 -> V_31 ,
& V_213 ) ;
if ( V_50 ) {
F_33 ( V_2 -> V_70 , L_11 ) ;
goto V_73;
}
V_2 -> V_143 . V_4 -> V_99 = F_95 ;
V_2 -> V_143 . V_4 -> V_100 = F_96 ;
V_2 -> V_143 . V_4 -> V_31 . V_78 = & V_2 -> V_70 -> V_31 ;
V_2 -> V_143 . V_4 -> V_101 . V_102 = V_2 -> V_70 -> V_103 ;
V_2 -> V_143 . V_4 -> V_101 . V_104 = V_2 -> V_70 -> V_104 ;
V_2 -> V_143 . V_4 -> V_101 . V_105 = V_2 -> V_70 -> V_105 ;
V_2 -> V_143 . V_4 -> V_101 . V_106 = V_2 -> V_70 -> V_106 ;
V_2 -> V_143 . V_4 -> V_68 = V_107 L_18 ;
F_5 ( V_20 , V_2 -> V_143 . V_4 -> V_21 ) ;
for ( V_19 = 0 ; V_19 < V_214 ; ++ V_19 )
F_5 ( V_189 [ V_19 ] ,
V_2 -> V_143 . V_4 -> V_23 ) ;
F_5 ( V_108 , V_2 -> V_143 . V_4 -> V_21 ) ;
F_5 ( V_187 , V_2 -> V_143 . V_4 -> V_109 ) ;
F_5 ( V_188 , V_2 -> V_143 . V_4 -> V_109 ) ;
F_5 ( V_96 , V_2 -> V_143 . V_4 -> V_109 ) ;
F_5 ( V_97 , V_2 -> V_143 . V_4 -> V_109 ) ;
F_58 ( V_2 -> V_143 . V_4 ,
V_187 , - 0x400 , 0x400 , 4 , 100 ) ;
F_58 ( V_2 -> V_143 . V_4 ,
V_188 , - 0x400 , 0x400 , 4 , 100 ) ;
F_58 ( V_2 -> V_143 . V_4 ,
V_96 , - 0x400 , 0x400 , 4 , 100 ) ;
F_58 ( V_2 -> V_143 . V_4 ,
V_97 , - 0x400 , 0x400 , 4 , 100 ) ;
V_50 = F_59 ( V_2 -> V_143 . V_4 ) ;
if ( V_50 )
goto V_184;
return 0 ;
V_184:
F_92 ( & V_2 -> V_70 -> V_31 ,
& V_213 ) ;
V_73:
F_60 ( V_2 -> V_143 . V_4 ) ;
V_2 -> V_143 . V_4 = NULL ;
return V_50 ;
}
static void F_102 ( const struct V_17 * V_18 ,
struct V_1 * V_2 )
{
unsigned long V_43 ;
if ( ! V_2 -> V_143 . V_4 )
return;
F_62 ( V_2 -> V_143 . V_4 ) ;
V_2 -> V_143 . V_4 = NULL ;
F_18 ( & V_2 -> V_26 ) ;
F_92 ( & V_2 -> V_70 -> V_31 ,
& V_213 ) ;
F_19 ( & V_2 -> V_27 . V_28 , V_43 ) ;
F_9 ( V_2 , 0 ) ;
F_20 ( & V_2 -> V_27 . V_28 , V_43 ) ;
}
static int F_103 ( const struct V_17 * V_18 ,
struct V_1 * V_2 )
{
unsigned long V_43 ;
F_19 ( & V_2 -> V_27 . V_28 , V_43 ) ;
V_2 -> V_27 . V_43 |= V_215 ;
F_20 ( & V_2 -> V_27 . V_28 , V_43 ) ;
return 0 ;
}
static void F_104 ( const struct V_17 * V_18 ,
struct V_1 * V_2 )
{
unsigned long V_43 ;
F_19 ( & V_2 -> V_27 . V_28 , V_43 ) ;
V_2 -> V_27 . V_43 |= V_215 ;
F_20 ( & V_2 -> V_27 . V_28 , V_43 ) ;
}
static int F_105 ( const struct V_17 * V_18 ,
struct V_1 * V_2 )
{
unsigned long V_43 ;
F_19 ( & V_2 -> V_27 . V_28 , V_43 ) ;
V_2 -> V_27 . V_43 |= V_216 ;
F_20 ( & V_2 -> V_27 . V_28 , V_43 ) ;
return 0 ;
}
static void F_106 ( const struct V_17 * V_18 ,
struct V_1 * V_2 )
{
unsigned long V_43 ;
F_19 ( & V_2 -> V_27 . V_28 , V_43 ) ;
V_2 -> V_27 . V_43 |= V_216 ;
F_20 ( & V_2 -> V_27 . V_28 , V_43 ) ;
}
static void F_107 ( struct V_1 * V_2 , const T_1 * V_139 )
{
T_6 V_92 , V_93 , V_94 ;
V_92 = V_139 [ 0 ] ;
V_93 = V_139 [ 1 ] ;
V_94 = V_139 [ 2 ] ;
V_92 |= ( ( ( T_3 ) V_139 [ 3 ] ) << 6 ) & 0xff00 ;
V_93 |= ( ( ( T_3 ) V_139 [ 4 ] ) << 6 ) & 0xff00 ;
V_94 |= ( ( ( T_3 ) V_139 [ 5 ] ) << 6 ) & 0xff00 ;
V_92 -= 8192 ;
V_93 -= 8192 ;
V_94 -= 8192 ;
if ( ! ( V_139 [ 3 ] & 0x02 ) )
V_92 *= 18 ;
else
V_92 *= 9 ;
if ( ! ( V_139 [ 4 ] & 0x02 ) )
V_93 *= 18 ;
else
V_93 *= 9 ;
if ( ! ( V_139 [ 3 ] & 0x01 ) )
V_94 *= 18 ;
else
V_94 *= 9 ;
F_51 ( V_2 -> V_217 , V_96 , V_92 ) ;
F_51 ( V_2 -> V_217 , V_97 , V_93 ) ;
F_51 ( V_2 -> V_217 , V_98 , V_94 ) ;
F_3 ( V_2 -> V_217 ) ;
}
static int F_108 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_12 ( V_31 ) ;
unsigned long V_43 ;
F_19 ( & V_2 -> V_27 . V_28 , V_43 ) ;
V_2 -> V_27 . V_43 |= V_218 ;
F_67 ( V_2 , V_130 ) ;
F_109 ( V_2 ) ;
F_20 ( & V_2 -> V_27 . V_28 , V_43 ) ;
return 0 ;
}
static void F_110 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_12 ( V_31 ) ;
unsigned long V_43 ;
F_19 ( & V_2 -> V_27 . V_28 , V_43 ) ;
V_2 -> V_27 . V_43 &= ~ V_218 ;
F_67 ( V_2 , V_130 ) ;
F_109 ( V_2 ) ;
F_20 ( & V_2 -> V_27 . V_28 , V_43 ) ;
}
static int F_111 ( const struct V_17 * V_18 ,
struct V_1 * V_2 )
{
int V_50 ;
V_2 -> V_217 = F_56 () ;
if ( ! V_2 -> V_217 )
return - V_42 ;
F_57 ( V_2 -> V_217 , V_2 ) ;
V_2 -> V_217 -> V_99 = F_108 ;
V_2 -> V_217 -> V_100 = F_110 ;
V_2 -> V_217 -> V_31 . V_78 = & V_2 -> V_70 -> V_31 ;
V_2 -> V_217 -> V_101 . V_102 = V_2 -> V_70 -> V_103 ;
V_2 -> V_217 -> V_101 . V_104 = V_2 -> V_70 -> V_104 ;
V_2 -> V_217 -> V_101 . V_105 = V_2 -> V_70 -> V_105 ;
V_2 -> V_217 -> V_101 . V_106 = V_2 -> V_70 -> V_106 ;
V_2 -> V_217 -> V_68 = V_107 L_19 ;
F_5 ( V_108 , V_2 -> V_217 -> V_21 ) ;
F_5 ( V_96 , V_2 -> V_217 -> V_109 ) ;
F_5 ( V_97 , V_2 -> V_217 -> V_109 ) ;
F_5 ( V_98 , V_2 -> V_217 -> V_109 ) ;
F_58 ( V_2 -> V_217 ,
V_96 , - 16000 , 16000 , 4 , 8 ) ;
F_58 ( V_2 -> V_217 ,
V_97 , - 16000 , 16000 , 4 , 8 ) ;
F_58 ( V_2 -> V_217 ,
V_98 , - 16000 , 16000 , 4 , 8 ) ;
V_50 = F_59 ( V_2 -> V_217 ) ;
if ( V_50 )
goto V_73;
return 0 ;
V_73:
F_60 ( V_2 -> V_217 ) ;
V_2 -> V_217 = NULL ;
return V_50 ;
}
static void F_112 ( const struct V_17 * V_18 ,
struct V_1 * V_2 )
{
if ( ! V_2 -> V_217 )
return;
F_62 ( V_2 -> V_217 ) ;
V_2 -> V_217 = NULL ;
}
