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
V_30 |= F_20 ( F_22 ( F_23 () , V_27 -> V_39 ) , & V_29 -> V_40 ) ;
V_30 |= F_20 ( F_24 ( F_23 () , V_27 -> V_41 ) , & V_29 -> V_42 ) ;
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
T_1 long F_25 ( const char T_4 * V_65 ,
struct V_28 T_4 * V_29 )
{
struct V_26 V_27 ;
int error = F_26 ( V_65 , & V_27 ) ;
if ( ! error )
error = F_19 ( & V_27 , V_29 ) ;
return error ;
}
T_1 long F_27 ( const char T_4 * V_65 ,
struct V_28 T_4 * V_29 )
{
struct V_26 V_27 ;
int error = F_28 ( V_65 , & V_27 ) ;
if ( ! error )
error = F_19 ( & V_27 , V_29 ) ;
return error ;
}
T_1 long F_29 ( unsigned int V_25 ,
struct V_28 T_4 * V_29 )
{
struct V_26 V_27 ;
int error = F_30 ( V_25 , & V_27 ) ;
if ( ! error )
error = F_19 ( & V_27 , V_29 ) ;
return error ;
}
T_1 long F_31 ( unsigned int V_66 ,
const char T_4 * V_65 ,
struct V_28 T_4 * V_29 , int V_67 )
{
struct V_26 V_27 ;
int error ;
error = F_32 ( V_66 , V_65 , & V_27 , V_67 ) ;
if ( error )
return error ;
return F_19 ( & V_27 , V_29 ) ;
}
T_1 long F_33 ( int V_68 , T_2 V_69 , T_2 V_70 )
{
return F_34 ( V_68 , V_69 , V_70 ) ;
}
T_1 long F_35 ( int V_71 ,
T_5 T_4 * V_72 ,
T_5 T_4 * V_73 ,
T_6 V_74 )
{
T_7 V_75 ;
T_5 V_76 ;
int V_77 ;
T_8 V_78 = F_36 () ;
if ( V_72 ) {
if ( F_37 ( & V_76 , V_72 , sizeof( T_5 ) ) )
return - V_79 ;
switch ( V_80 ) {
case 4 : V_75 . V_81 [ 3 ] = V_76 . V_81 [ 6 ] | ( ( ( long ) V_76 . V_81 [ 7 ] ) << 32 ) ;
case 3 : V_75 . V_81 [ 2 ] = V_76 . V_81 [ 4 ] | ( ( ( long ) V_76 . V_81 [ 5 ] ) << 32 ) ;
case 2 : V_75 . V_81 [ 1 ] = V_76 . V_81 [ 2 ] | ( ( ( long ) V_76 . V_81 [ 3 ] ) << 32 ) ;
case 1 : V_75 . V_81 [ 0 ] = V_76 . V_81 [ 0 ] | ( ( ( long ) V_76 . V_81 [ 1 ] ) << 32 ) ;
}
}
F_38 ( V_82 ) ;
V_77 = F_39 ( V_71 ,
V_72 ? ( T_7 T_4 * ) & V_75 : NULL ,
V_73 ? ( T_7 T_4 * ) & V_75 : NULL ,
V_74 ) ;
F_38 ( V_78 ) ;
if ( V_77 ) return V_77 ;
if ( V_73 ) {
switch ( V_80 ) {
case 4 : V_76 . V_81 [ 7 ] = ( V_75 . V_81 [ 3 ] >> 32 ) ; V_76 . V_81 [ 6 ] = V_75 . V_81 [ 3 ] ;
case 3 : V_76 . V_81 [ 5 ] = ( V_75 . V_81 [ 2 ] >> 32 ) ; V_76 . V_81 [ 4 ] = V_75 . V_81 [ 2 ] ;
case 2 : V_76 . V_81 [ 3 ] = ( V_75 . V_81 [ 1 ] >> 32 ) ; V_76 . V_81 [ 2 ] = V_75 . V_81 [ 1 ] ;
case 1 : V_76 . V_81 [ 1 ] = ( V_75 . V_81 [ 0 ] >> 32 ) ; V_76 . V_81 [ 0 ] = V_75 . V_81 [ 0 ] ;
}
if ( F_40 ( V_73 , & V_76 , sizeof( T_5 ) ) )
return - V_79 ;
}
return 0 ;
}
T_1 long F_41 ( T_5 T_4 * V_72 ,
T_6 V_74 )
{
T_7 V_75 ;
T_5 V_76 ;
int V_77 ;
T_8 V_78 = F_36 () ;
F_38 ( V_82 ) ;
V_77 = F_42 ( ( T_7 T_4 * ) & V_75 , V_74 ) ;
F_38 ( V_78 ) ;
if ( ! V_77 ) {
switch ( V_80 ) {
case 4 : V_76 . V_81 [ 7 ] = ( V_75 . V_81 [ 3 ] >> 32 ) ; V_76 . V_81 [ 6 ] = V_75 . V_81 [ 3 ] ;
case 3 : V_76 . V_81 [ 5 ] = ( V_75 . V_81 [ 2 ] >> 32 ) ; V_76 . V_81 [ 4 ] = V_75 . V_81 [ 2 ] ;
case 2 : V_76 . V_81 [ 3 ] = ( V_75 . V_81 [ 1 ] >> 32 ) ; V_76 . V_81 [ 2 ] = V_75 . V_81 [ 1 ] ;
case 1 : V_76 . V_81 [ 1 ] = ( V_75 . V_81 [ 0 ] >> 32 ) ; V_76 . V_81 [ 0 ] = V_75 . V_81 [ 0 ] ;
}
if ( F_40 ( V_72 , & V_76 , sizeof( T_5 ) ) )
return - V_79 ;
}
return V_77 ;
}
T_1 long F_43 ( int V_83 , int V_81 ,
struct V_84 T_4 * V_85 )
{
T_9 V_86 ;
int V_77 ;
T_8 V_78 = F_36 () ;
if ( F_44 ( & V_86 , V_85 ) )
return - V_79 ;
F_38 ( V_82 ) ;
V_77 = F_45 ( V_83 , V_81 , ( T_9 T_4 * ) & V_86 ) ;
F_38 ( V_78 ) ;
return V_77 ;
}
T_1 long F_46 ( int V_81 , struct V_87 T_4 * V_88 ,
struct V_87 T_4 * V_89 )
{
struct V_90 V_91 , V_92 ;
int V_77 ;
F_47 ( V_81 >= 0 ) ;
V_81 = - V_81 ;
if ( V_88 ) {
T_10 V_93 ;
T_2 V_94 , V_95 ;
V_77 = F_48 ( V_94 , & V_88 -> V_96 ) ;
V_91 . V_97 . V_96 = F_3 ( V_94 ) ;
V_77 |= F_49 ( V_95 , & V_88 -> V_98 ) ;
V_91 . V_97 . V_98 = F_3 ( V_95 ) ;
V_77 |= F_49 ( V_91 . V_97 . V_99 , & V_88 -> V_99 ) ;
V_77 |= F_49 ( V_93 , & V_88 -> V_100 ) ;
if ( V_77 )
return V_77 ;
V_91 . V_101 = NULL ;
F_50 ( & V_91 . V_97 . V_100 , V_93 ) ;
}
V_77 = F_51 ( V_81 , V_88 ? & V_91 : NULL , V_89 ? & V_92 : NULL ) ;
if ( ! V_77 && V_89 ) {
V_77 = F_20 ( F_52 ( V_92 . V_97 . V_96 ) , & V_89 -> V_96 ) ;
V_77 |= F_53 ( F_52 ( V_92 . V_97 . V_98 ) , & V_89 -> V_98 ) ;
V_77 |= F_53 ( V_92 . V_97 . V_99 , & V_89 -> V_99 ) ;
V_77 |= F_53 ( V_92 . V_97 . V_100 . V_81 [ 0 ] , & V_89 -> V_100 ) ;
}
return V_77 ;
}
T_1 long F_54 ( int V_81 ,
struct V_102 T_4 * V_88 ,
struct V_102 T_4 * V_89 ,
void T_4 * V_103 ,
T_6 V_74 )
{
struct V_90 V_91 , V_92 ;
int V_77 ;
T_5 V_104 ;
if ( V_74 != sizeof( T_5 ) )
return - V_24 ;
if ( V_88 ) {
T_2 V_94 , V_95 ;
V_91 . V_101 = V_103 ;
V_77 = F_48 ( V_94 , & V_88 -> V_96 ) ;
V_91 . V_97 . V_96 = F_3 ( V_94 ) ;
V_77 |= F_55 ( & V_104 , & V_88 -> V_100 , sizeof( T_5 ) ) ;
switch ( V_80 ) {
case 4 : V_91 . V_97 . V_100 . V_81 [ 3 ] = V_104 . V_81 [ 6 ] | ( ( ( long ) V_104 . V_81 [ 7 ] ) << 32 ) ;
case 3 : V_91 . V_97 . V_100 . V_81 [ 2 ] = V_104 . V_81 [ 4 ] | ( ( ( long ) V_104 . V_81 [ 5 ] ) << 32 ) ;
case 2 : V_91 . V_97 . V_100 . V_81 [ 1 ] = V_104 . V_81 [ 2 ] | ( ( ( long ) V_104 . V_81 [ 3 ] ) << 32 ) ;
case 1 : V_91 . V_97 . V_100 . V_81 [ 0 ] = V_104 . V_81 [ 0 ] | ( ( ( long ) V_104 . V_81 [ 1 ] ) << 32 ) ;
}
V_77 |= F_49 ( V_91 . V_97 . V_99 , & V_88 -> V_99 ) ;
V_77 |= F_49 ( V_95 , & V_88 -> V_98 ) ;
V_91 . V_97 . V_98 = F_3 ( V_95 ) ;
if ( V_77 )
return - V_79 ;
}
V_77 = F_51 ( V_81 , V_88 ? & V_91 : NULL , V_89 ? & V_92 : NULL ) ;
if ( ! V_77 && V_89 ) {
switch ( V_80 ) {
case 4 : V_104 . V_81 [ 7 ] = ( V_92 . V_97 . V_100 . V_81 [ 3 ] >> 32 ) ; V_104 . V_81 [ 6 ] = V_92 . V_97 . V_100 . V_81 [ 3 ] ;
case 3 : V_104 . V_81 [ 5 ] = ( V_92 . V_97 . V_100 . V_81 [ 2 ] >> 32 ) ; V_104 . V_81 [ 4 ] = V_92 . V_97 . V_100 . V_81 [ 2 ] ;
case 2 : V_104 . V_81 [ 3 ] = ( V_92 . V_97 . V_100 . V_81 [ 1 ] >> 32 ) ; V_104 . V_81 [ 2 ] = V_92 . V_97 . V_100 . V_81 [ 1 ] ;
case 1 : V_104 . V_81 [ 1 ] = ( V_92 . V_97 . V_100 . V_81 [ 0 ] >> 32 ) ; V_104 . V_81 [ 0 ] = V_92 . V_97 . V_100 . V_81 [ 0 ] ;
}
V_77 = F_20 ( F_52 ( V_92 . V_97 . V_96 ) , & V_89 -> V_96 ) ;
V_77 |= F_56 ( & V_89 -> V_100 , & V_104 , sizeof( T_5 ) ) ;
V_77 |= F_53 ( V_92 . V_97 . V_99 , & V_89 -> V_99 ) ;
V_77 |= F_53 ( F_52 ( V_92 . V_97 . V_98 ) , & V_89 -> V_98 ) ;
if ( V_77 )
V_77 = - V_79 ;
}
return V_77 ;
}
T_1 long F_57 ( void T_4 * V_105 , T_2 V_106 ,
const char T_4 * V_107 )
{
return F_58 ( V_105 , V_106 , V_107 ) ;
}
T_1 long F_59 ( const char T_4 * V_108 ,
unsigned int V_109 )
{
return F_60 ( V_108 , V_109 ) ;
}
T_1 long F_57 ( const char T_4 * V_108 ,
struct V_110 T_4 * V_111 )
{
return - V_20 ;
}
T_1 long F_59 ( const char T_4 * V_108 )
{
return - V_20 ;
}
T_1 T_11 F_61 ( unsigned int V_25 ,
char T_4 * V_112 ,
T_6 V_113 ,
unsigned long V_114 ,
unsigned long V_115 )
{
return F_62 ( V_25 , V_112 , V_113 , ( V_114 << 32 ) | V_115 ) ;
}
T_1 T_11 F_63 ( unsigned int V_25 ,
char T_4 * V_112 ,
T_6 V_113 ,
unsigned long V_114 ,
unsigned long V_115 )
{
return F_64 ( V_25 , V_112 , V_113 , ( V_114 << 32 ) | V_115 ) ;
}
T_1 long F_65 ( int V_25 ,
unsigned long V_116 ,
unsigned long V_117 ,
T_6 V_113 )
{
return F_66 ( V_25 , ( V_116 << 32 ) | V_117 , V_113 ) ;
}
long F_67 ( int V_25 ,
unsigned long V_116 ,
unsigned long V_117 ,
T_6 V_106 , int V_118 )
{
return F_68 ( V_25 , ( V_116 << 32 ) | V_117 , V_106 , V_118 ) ;
}
long F_69 ( int V_25 ,
unsigned long V_116 , unsigned long V_117 ,
unsigned long V_119 , unsigned long V_120 ,
int V_118 )
{
return F_68 ( V_25 ,
( V_116 << 32 ) | V_117 ,
( V_119 << 32 ) | V_120 ,
V_118 ) ;
}
T_1 long F_70 ( const char T_4 * V_65 ,
int V_109 , int V_35 )
{
return F_71 ( V_121 , V_65 , V_109 , V_35 ) ;
}
long F_72 ( unsigned long V_122 ,
unsigned long V_123 ,
char T_4 * V_124 , T_12 V_106 )
{
return F_73 ( ( V_122 << 32 ) | V_123 ,
V_124 , V_106 ) ;
}
long F_74 ( int V_25 , unsigned long V_125 , unsigned long V_126 , unsigned long V_127 , unsigned long V_128 , int V_109 )
{
return F_75 ( V_25 ,
( V_125 << 32 ) | V_126 ,
( V_127 << 32 ) | V_128 ,
V_109 ) ;
}
T_1 long F_76 ( int V_25 , int V_35 , T_2 V_116 , T_2 V_117 ,
T_2 V_119 , T_2 V_120 )
{
return F_77 ( V_25 , V_35 , ( ( V_129 ) V_116 << 32 ) | V_117 ,
( ( V_129 ) V_119 << 32 ) | V_120 ) ;
}
