T_1 long F_1 ( T_2 V_1 , T_2 V_2 , T_2 V_3 , T_2 V_4 , T_3 V_5 , T_2 V_6 )
{
int V_7 ;
V_7 = V_1 >> 16 ;
V_1 &= 0xffff ;
switch ( V_1 ) {
case V_8 :
if ( V_6 )
return F_2 ( ( int ) V_2 ,
F_3 ( V_5 ) , V_3 ,
F_3 ( V_6 ) ) ;
case V_9 :
return F_4 ( ( int ) V_2 , F_3 ( V_5 ) , V_3 ,
NULL ) ;
case V_10 :
return F_5 ( ( int ) V_2 , ( int ) V_3 , V_4 ) ;
case V_11 :
return F_6 ( ( int ) V_2 , ( int ) V_3 , V_4 ,
F_3 ( V_5 ) ) ;
case V_12 :
return F_7 ( ( int ) V_2 , ( int ) V_3 , V_4 ,
F_3 ( V_5 ) ) ;
case V_13 :
return F_8 ( ( int ) V_2 , V_3 , ( int ) V_6 ,
V_4 , V_7 , F_3 ( V_5 ) ) ;
case V_14 :
return F_9 ( ( int ) V_2 , V_3 ) ;
case V_15 :
return F_10 ( ( int ) V_2 , V_3 , F_3 ( V_5 ) ) ;
case V_16 :
return F_11 ( ( int ) V_2 , V_3 , V_4 , V_7 ,
F_3 ( V_5 ) ) ;
case V_17 :
return F_12 ( F_3 ( V_5 ) ) ;
case V_18 :
return F_13 ( ( int ) V_2 , V_3 , V_4 ) ;
case V_19 :
return F_14 ( ( int ) V_2 , V_3 , F_3 ( V_5 ) ) ;
default:
return - V_20 ;
}
return - V_20 ;
}
T_1 long F_15 ( const char T_4 * V_21 , unsigned long V_22 , unsigned long V_23 )
{
if ( ( int ) V_22 < 0 )
return - V_24 ;
else
return F_16 ( V_21 , ( V_22 << 32 ) | V_23 ) ;
}
T_1 long F_17 ( unsigned int V_25 , unsigned long V_22 , unsigned long V_23 )
{
if ( ( int ) V_22 < 0 )
return - V_24 ;
else
return F_18 ( V_25 , ( V_22 << 32 ) | V_23 ) ;
}
static int F_19 ( struct V_26 * V_27 ,
struct V_28 T_4 * V_29 )
{
int V_30 ;
V_30 = F_20 ( F_21 ( V_27 -> V_31 ) , & V_29 -> V_32 ) ;
V_30 |= F_20 ( V_27 -> V_33 , & V_29 -> V_34 ) ;
V_30 |= F_20 ( V_27 -> V_35 , & V_29 -> V_36 ) ;
V_30 |= F_20 ( V_27 -> V_37 , & V_29 -> V_38 ) ;
V_30 |= F_20 ( V_27 -> V_39 , & V_29 -> V_40 ) ;
V_30 |= F_20 ( V_27 -> V_41 , & V_29 -> V_42 ) ;
V_30 |= F_20 ( F_21 ( V_27 -> V_43 ) , & V_29 -> V_44 ) ;
V_30 |= F_20 ( 0 , ( unsigned long T_4 * ) & V_29 -> V_45 [ 0 ] ) ;
V_30 |= F_20 ( V_27 -> V_46 , & V_29 -> V_47 ) ;
V_30 |= F_20 ( V_27 -> V_48 , & V_29 -> V_49 ) ;
V_30 |= F_20 ( 0 , ( unsigned int T_4 * ) & V_29 -> V_50 [ 0 ] ) ;
V_30 |= F_20 ( 0 , ( unsigned int T_4 * ) & V_29 -> V_50 [ 4 ] ) ;
V_30 |= F_20 ( V_27 -> V_51 , & V_29 -> V_52 ) ;
V_30 |= F_20 ( V_27 -> V_53 . V_54 , & V_29 -> V_55 ) ;
V_30 |= F_20 ( V_27 -> V_53 . V_56 , & V_29 -> V_57 ) ;
V_30 |= F_20 ( V_27 -> V_58 . V_54 , & V_29 -> V_59 ) ;
V_30 |= F_20 ( V_27 -> V_58 . V_56 , & V_29 -> V_60 ) ;
V_30 |= F_20 ( V_27 -> ctime . V_54 , & V_29 -> V_61 ) ;
V_30 |= F_20 ( V_27 -> ctime . V_56 , & V_29 -> V_62 ) ;
V_30 |= F_20 ( 0 , & V_29 -> V_63 ) ;
V_30 |= F_20 ( 0 , & V_29 -> V_64 ) ;
return V_30 ;
}
T_1 long F_22 ( const char T_4 * V_65 ,
struct V_28 T_4 * V_29 )
{
struct V_26 V_27 ;
int error = F_23 ( V_65 , & V_27 ) ;
if ( ! error )
error = F_19 ( & V_27 , V_29 ) ;
return error ;
}
T_1 long F_24 ( const char T_4 * V_65 ,
struct V_28 T_4 * V_29 )
{
struct V_26 V_27 ;
int error = F_25 ( V_65 , & V_27 ) ;
if ( ! error )
error = F_19 ( & V_27 , V_29 ) ;
return error ;
}
T_1 long F_26 ( unsigned int V_25 ,
struct V_28 T_4 * V_29 )
{
struct V_26 V_27 ;
int error = F_27 ( V_25 , & V_27 ) ;
if ( ! error )
error = F_19 ( & V_27 , V_29 ) ;
return error ;
}
T_1 long F_28 ( unsigned int V_66 ,
const char T_4 * V_65 ,
struct V_28 T_4 * V_29 , int V_67 )
{
struct V_26 V_27 ;
int error ;
error = F_29 ( V_66 , V_65 , & V_27 , V_67 ) ;
if ( error )
return error ;
return F_19 ( & V_27 , V_29 ) ;
}
T_1 long F_30 ( int V_68 , T_2 V_69 , T_2 V_70 )
{
return F_31 ( V_68 , V_69 , V_70 ) ;
}
T_1 long F_32 ( T_5 V_71 , struct V_72 T_4 * V_73 )
{
struct V_74 V_75 ;
int V_76 ;
T_6 V_77 = F_33 () ;
F_34 ( V_78 ) ;
V_76 = F_35 ( V_71 , (struct V_74 T_4 * ) & V_75 ) ;
F_34 ( V_77 ) ;
if ( F_36 ( & V_75 , V_73 ) )
return - V_79 ;
return V_76 ;
}
T_1 long F_37 ( int V_80 ,
T_7 T_4 * V_81 ,
T_7 T_4 * V_82 ,
T_8 V_83 )
{
T_9 V_84 ;
T_7 V_85 ;
int V_76 ;
T_6 V_77 = F_33 () ;
if ( V_81 ) {
if ( F_38 ( & V_85 , V_81 , sizeof( T_7 ) ) )
return - V_79 ;
switch ( V_86 ) {
case 4 : V_84 . V_87 [ 3 ] = V_85 . V_87 [ 6 ] | ( ( ( long ) V_85 . V_87 [ 7 ] ) << 32 ) ;
case 3 : V_84 . V_87 [ 2 ] = V_85 . V_87 [ 4 ] | ( ( ( long ) V_85 . V_87 [ 5 ] ) << 32 ) ;
case 2 : V_84 . V_87 [ 1 ] = V_85 . V_87 [ 2 ] | ( ( ( long ) V_85 . V_87 [ 3 ] ) << 32 ) ;
case 1 : V_84 . V_87 [ 0 ] = V_85 . V_87 [ 0 ] | ( ( ( long ) V_85 . V_87 [ 1 ] ) << 32 ) ;
}
}
F_34 ( V_78 ) ;
V_76 = F_39 ( V_80 ,
V_81 ? ( T_9 T_4 * ) & V_84 : NULL ,
V_82 ? ( T_9 T_4 * ) & V_84 : NULL ,
V_83 ) ;
F_34 ( V_77 ) ;
if ( V_76 ) return V_76 ;
if ( V_82 ) {
switch ( V_86 ) {
case 4 : V_85 . V_87 [ 7 ] = ( V_84 . V_87 [ 3 ] >> 32 ) ; V_85 . V_87 [ 6 ] = V_84 . V_87 [ 3 ] ;
case 3 : V_85 . V_87 [ 5 ] = ( V_84 . V_87 [ 2 ] >> 32 ) ; V_85 . V_87 [ 4 ] = V_84 . V_87 [ 2 ] ;
case 2 : V_85 . V_87 [ 3 ] = ( V_84 . V_87 [ 1 ] >> 32 ) ; V_85 . V_87 [ 2 ] = V_84 . V_87 [ 1 ] ;
case 1 : V_85 . V_87 [ 1 ] = ( V_84 . V_87 [ 0 ] >> 32 ) ; V_85 . V_87 [ 0 ] = V_84 . V_87 [ 0 ] ;
}
if ( F_40 ( V_82 , & V_85 , sizeof( T_7 ) ) )
return - V_79 ;
}
return 0 ;
}
T_1 long F_41 ( T_7 T_4 * V_81 ,
T_8 V_83 )
{
T_9 V_84 ;
T_7 V_85 ;
int V_76 ;
T_6 V_77 = F_33 () ;
F_34 ( V_78 ) ;
V_76 = F_42 ( ( T_9 T_4 * ) & V_84 , V_83 ) ;
F_34 ( V_77 ) ;
if ( ! V_76 ) {
switch ( V_86 ) {
case 4 : V_85 . V_87 [ 7 ] = ( V_84 . V_87 [ 3 ] >> 32 ) ; V_85 . V_87 [ 6 ] = V_84 . V_87 [ 3 ] ;
case 3 : V_85 . V_87 [ 5 ] = ( V_84 . V_87 [ 2 ] >> 32 ) ; V_85 . V_87 [ 4 ] = V_84 . V_87 [ 2 ] ;
case 2 : V_85 . V_87 [ 3 ] = ( V_84 . V_87 [ 1 ] >> 32 ) ; V_85 . V_87 [ 2 ] = V_84 . V_87 [ 1 ] ;
case 1 : V_85 . V_87 [ 1 ] = ( V_84 . V_87 [ 0 ] >> 32 ) ; V_85 . V_87 [ 0 ] = V_84 . V_87 [ 0 ] ;
}
if ( F_40 ( V_81 , & V_85 , sizeof( T_7 ) ) )
return - V_79 ;
}
return V_76 ;
}
T_1 long F_43 ( int V_71 , int V_87 ,
struct V_88 T_4 * V_89 )
{
T_10 V_90 ;
int V_76 ;
T_6 V_77 = F_33 () ;
if ( F_44 ( & V_90 , V_89 ) )
return - V_79 ;
F_34 ( V_78 ) ;
V_76 = F_45 ( V_71 , V_87 , ( T_10 T_4 * ) & V_90 ) ;
F_34 ( V_77 ) ;
return V_76 ;
}
T_1 long F_46 ( int V_87 , struct V_91 T_4 * V_92 ,
struct V_91 T_4 * V_93 )
{
struct V_94 V_95 , V_96 ;
int V_76 ;
F_47 ( V_87 >= 0 ) ;
V_87 = - V_87 ;
if ( V_92 ) {
T_11 V_97 ;
T_2 V_98 , V_99 ;
V_76 = F_48 ( V_98 , & V_92 -> V_100 ) ;
V_95 . V_101 . V_100 = F_3 ( V_98 ) ;
V_76 |= F_49 ( V_99 , & V_92 -> V_102 ) ;
V_95 . V_101 . V_102 = F_3 ( V_99 ) ;
V_76 |= F_49 ( V_95 . V_101 . V_103 , & V_92 -> V_103 ) ;
V_76 |= F_49 ( V_97 , & V_92 -> V_104 ) ;
if ( V_76 )
return V_76 ;
V_95 . V_105 = NULL ;
F_50 ( & V_95 . V_101 . V_104 , V_97 ) ;
}
V_76 = F_51 ( V_87 , V_92 ? & V_95 : NULL , V_93 ? & V_96 : NULL ) ;
if ( ! V_76 && V_93 ) {
V_76 = F_20 ( F_52 ( V_96 . V_101 . V_100 ) , & V_93 -> V_100 ) ;
V_76 |= F_53 ( F_52 ( V_96 . V_101 . V_102 ) , & V_93 -> V_102 ) ;
V_76 |= F_53 ( V_96 . V_101 . V_103 , & V_93 -> V_103 ) ;
V_76 |= F_53 ( V_96 . V_101 . V_104 . V_87 [ 0 ] , & V_93 -> V_104 ) ;
}
return V_76 ;
}
T_1 long F_54 ( int V_87 ,
struct V_106 T_4 * V_92 ,
struct V_106 T_4 * V_93 ,
void T_4 * V_107 ,
T_8 V_83 )
{
struct V_94 V_95 , V_96 ;
int V_76 ;
T_7 V_108 ;
if ( V_83 != sizeof( T_7 ) )
return - V_24 ;
if ( V_92 ) {
T_2 V_98 , V_99 ;
V_95 . V_105 = V_107 ;
V_76 = F_48 ( V_98 , & V_92 -> V_100 ) ;
V_95 . V_101 . V_100 = F_3 ( V_98 ) ;
V_76 |= F_55 ( & V_108 , & V_92 -> V_104 , sizeof( T_7 ) ) ;
switch ( V_86 ) {
case 4 : V_95 . V_101 . V_104 . V_87 [ 3 ] = V_108 . V_87 [ 6 ] | ( ( ( long ) V_108 . V_87 [ 7 ] ) << 32 ) ;
case 3 : V_95 . V_101 . V_104 . V_87 [ 2 ] = V_108 . V_87 [ 4 ] | ( ( ( long ) V_108 . V_87 [ 5 ] ) << 32 ) ;
case 2 : V_95 . V_101 . V_104 . V_87 [ 1 ] = V_108 . V_87 [ 2 ] | ( ( ( long ) V_108 . V_87 [ 3 ] ) << 32 ) ;
case 1 : V_95 . V_101 . V_104 . V_87 [ 0 ] = V_108 . V_87 [ 0 ] | ( ( ( long ) V_108 . V_87 [ 1 ] ) << 32 ) ;
}
V_76 |= F_49 ( V_95 . V_101 . V_103 , & V_92 -> V_103 ) ;
V_76 |= F_49 ( V_99 , & V_92 -> V_102 ) ;
V_95 . V_101 . V_102 = F_3 ( V_99 ) ;
if ( V_76 )
return - V_79 ;
}
V_76 = F_51 ( V_87 , V_92 ? & V_95 : NULL , V_93 ? & V_96 : NULL ) ;
if ( ! V_76 && V_93 ) {
switch ( V_86 ) {
case 4 : V_108 . V_87 [ 7 ] = ( V_96 . V_101 . V_104 . V_87 [ 3 ] >> 32 ) ; V_108 . V_87 [ 6 ] = V_96 . V_101 . V_104 . V_87 [ 3 ] ;
case 3 : V_108 . V_87 [ 5 ] = ( V_96 . V_101 . V_104 . V_87 [ 2 ] >> 32 ) ; V_108 . V_87 [ 4 ] = V_96 . V_101 . V_104 . V_87 [ 2 ] ;
case 2 : V_108 . V_87 [ 3 ] = ( V_96 . V_101 . V_104 . V_87 [ 1 ] >> 32 ) ; V_108 . V_87 [ 2 ] = V_96 . V_101 . V_104 . V_87 [ 1 ] ;
case 1 : V_108 . V_87 [ 1 ] = ( V_96 . V_101 . V_104 . V_87 [ 0 ] >> 32 ) ; V_108 . V_87 [ 0 ] = V_96 . V_101 . V_104 . V_87 [ 0 ] ;
}
V_76 = F_20 ( F_52 ( V_96 . V_101 . V_100 ) , & V_93 -> V_100 ) ;
V_76 |= F_56 ( & V_93 -> V_104 , & V_108 , sizeof( T_7 ) ) ;
V_76 |= F_53 ( V_96 . V_101 . V_103 , & V_93 -> V_103 ) ;
V_76 |= F_53 ( F_52 ( V_96 . V_101 . V_102 ) , & V_93 -> V_102 ) ;
if ( V_76 )
V_76 = - V_79 ;
}
return V_76 ;
}
T_1 long F_57 ( struct V_109 * V_110 )
{
int error , V_111 = 0 ;
char * V_65 ;
if ( ( T_2 ) V_110 -> V_112 [ V_113 ] == 0 )
V_111 = 1 ;
V_65 = F_58 ( F_3 ( V_110 -> V_112 [ V_111 + V_114 ] ) ) ;
error = F_59 ( V_65 ) ;
if ( F_60 ( V_65 ) )
goto V_115;
error = F_61 ( V_65 ,
F_3 ( V_110 -> V_112 [ V_111 + V_116 ] ) ,
F_3 ( V_110 -> V_112 [ V_111 + V_117 ] ) , V_110 ) ;
F_62 ( V_65 ) ;
if ( ! error ) {
F_63 ( 0 ) ;
F_64 () -> V_118 [ 0 ] = 0 ;
F_64 () -> V_119 [ 0 ] = 0 ;
V_110 -> V_120 &= ~ V_121 ;
}
V_115:
return error ;
}
T_1 long F_65 ( void T_4 * V_122 , T_2 V_123 ,
const char T_4 * V_124 )
{
return F_66 ( V_122 , V_123 , V_124 ) ;
}
T_1 long F_67 ( const char T_4 * V_125 ,
unsigned int V_126 )
{
return F_68 ( V_125 , V_126 ) ;
}
T_1 long F_65 ( const char T_4 * V_125 ,
struct V_127 T_4 * V_128 )
{
return - V_20 ;
}
T_1 long F_67 ( const char T_4 * V_125 )
{
return - V_20 ;
}
T_1 T_12 F_69 ( unsigned int V_25 ,
char T_4 * V_129 ,
T_8 V_130 ,
unsigned long V_131 ,
unsigned long V_132 )
{
return F_70 ( V_25 , V_129 , V_130 , ( V_131 << 32 ) | V_132 ) ;
}
T_1 T_12 F_71 ( unsigned int V_25 ,
char T_4 * V_129 ,
T_8 V_130 ,
unsigned long V_131 ,
unsigned long V_132 )
{
return F_72 ( V_25 , V_129 , V_130 , ( V_131 << 32 ) | V_132 ) ;
}
T_1 long F_73 ( int V_25 ,
unsigned long V_133 ,
unsigned long V_134 ,
T_8 V_130 )
{
return F_74 ( V_25 , ( V_133 << 32 ) | V_134 , V_130 ) ;
}
long F_75 ( int V_25 ,
unsigned long V_133 ,
unsigned long V_134 ,
T_8 V_123 , int V_135 )
{
return F_76 ( V_25 , ( V_133 << 32 ) | V_134 , V_123 , V_135 ) ;
}
long F_77 ( int V_25 ,
unsigned long V_133 , unsigned long V_134 ,
unsigned long V_136 , unsigned long V_137 ,
int V_135 )
{
return F_76 ( V_25 ,
( V_133 << 32 ) | V_134 ,
( V_136 << 32 ) | V_137 ,
V_135 ) ;
}
T_1 long F_78 ( int V_138 , int V_139 ,
T_13 T_4 * V_140 ,
T_8 V_130 )
{
T_6 V_77 = F_33 () ;
int V_76 ;
T_14 V_141 ;
if ( V_140 && F_48 ( V_141 , V_140 ) )
return - V_79 ;
F_34 ( V_78 ) ;
V_76 = F_79 ( V_138 , V_139 ,
V_140 ? ( T_14 T_4 * ) & V_141 : NULL ,
V_130 ) ;
F_34 ( V_77 ) ;
if ( V_140 && F_20 ( V_141 , V_140 ) )
return - V_79 ;
return V_76 ;
}
T_1 long F_80 ( int V_138 , int V_139 ,
T_15 T_4 * V_140 ,
T_8 V_130 )
{
T_6 V_77 = F_33 () ;
int V_76 ;
T_16 V_142 ;
if ( V_140 && F_48 ( V_142 , V_140 ) )
return - V_79 ;
F_34 ( V_78 ) ;
V_76 = F_81 ( V_138 , V_139 ,
V_140 ? ( T_16 T_4 * ) & V_142 : NULL ,
V_130 ) ;
F_34 ( V_77 ) ;
if ( V_140 && F_20 ( V_142 , V_140 ) )
return - V_79 ;
return V_76 ;
}
T_1 long F_82 ( const char T_4 * V_65 ,
int V_126 , int V_35 )
{
return F_83 ( V_143 , V_65 , V_126 , V_35 ) ;
}
long F_84 ( unsigned long V_144 ,
unsigned long V_145 ,
char T_4 * V_146 , T_17 V_123 )
{
return F_85 ( ( V_144 << 32 ) | V_145 ,
V_146 , V_123 ) ;
}
long F_86 ( int V_25 , unsigned long V_147 , unsigned long V_148 , unsigned long V_149 , unsigned long V_150 , int V_126 )
{
return F_87 ( V_25 ,
( V_147 << 32 ) | V_148 ,
( V_149 << 32 ) | V_150 ,
V_126 ) ;
}
T_1 long F_88 ( int V_25 , int V_35 , T_2 V_133 , T_2 V_134 ,
T_2 V_136 , T_2 V_137 )
{
return F_89 ( V_25 , V_35 , ( ( T_16 ) V_133 << 32 ) | V_134 ,
( ( T_16 ) V_136 << 32 ) | V_137 ) ;
}
