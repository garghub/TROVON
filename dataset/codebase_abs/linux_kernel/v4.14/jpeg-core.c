static int F_1 ( T_1 V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; ++ V_2 ) {
if ( V_3 [ V_2 ] == V_1 )
return V_2 ;
}
return - V_4 ;
}
static int F_3 (
enum V_5 V_6 ,
T_1 V_7 ,
T_1 * V_8 ,
struct V_9 * V_10 )
{
int V_11 ;
if ( V_10 -> V_12 != V_13 ) {
V_11 =
F_1 ( V_7 ) ;
if ( V_11 < 0 )
return - V_4 ;
}
switch ( V_10 -> V_12 ) {
case V_13 :
* V_8 = V_14 ;
break;
case V_15 :
if ( V_11 >
F_2 ( V_16 ) - 1 )
return - V_4 ;
* V_8 = V_16 [ V_11 ] ;
break;
case V_17 :
if ( V_11 >
F_2 ( V_18 ) - 1 )
return - V_4 ;
* V_8 = V_18 [ V_11 ] ;
break;
default:
* V_8 = V_14 ;
break;
}
return 0 ;
}
static inline struct V_9 * F_4 ( struct V_19 * V_20 )
{
return F_5 ( V_20 -> V_21 , struct V_9 , V_22 ) ;
}
static inline struct V_9 * F_6 ( struct V_23 * V_24 )
{
return F_5 ( V_24 , struct V_9 , V_24 ) ;
}
static int F_7 ( struct V_9 * V_10 )
{
switch ( V_10 -> V_25 -> V_26 -> V_27 ) {
case V_28 :
F_8 ( V_10 -> V_12 > 3 ) ;
if ( V_10 -> V_12 > 2 )
return V_13 ;
return V_10 -> V_12 ;
case V_29 :
case V_30 :
F_8 ( V_10 -> V_12 > 6 ) ;
if ( V_10 -> V_12 > 3 )
return V_31 ;
return V_32 [ V_10 -> V_12 ] ;
case V_33 :
F_8 ( V_10 -> V_12 > 3 ) ;
if ( V_10 -> V_12 > 2 )
return V_15 ;
return V_34 [ V_10 -> V_12 ] ;
case V_35 :
return V_10 -> V_12 ;
default:
F_8 ( V_10 -> V_12 > 3 ) ;
return V_13 ;
}
}
static inline void F_9 ( void T_2 * V_36 ,
const unsigned char * V_37 ,
unsigned long V_38 , int V_39 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_39 ; V_2 ++ )
F_10 ( ( unsigned int ) V_37 [ V_2 ] , V_36 + V_38 + ( V_2 * 0x04 ) ) ;
}
static inline void F_11 ( void T_2 * V_36 , int V_40 )
{
F_9 ( V_36 , V_41 [ V_40 ] ,
F_12 ( 0 ) ,
F_2 ( V_41 [ V_40 ] ) ) ;
}
static inline void F_13 ( void T_2 * V_36 , int V_40 )
{
F_9 ( V_36 , V_42 [ V_40 ] ,
F_12 ( 1 ) ,
F_2 ( V_42 [ V_40 ] ) ) ;
}
static inline void F_14 ( void T_2 * V_36 ,
const unsigned char * V_43 ,
unsigned long V_38 , int V_39 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_39 ; V_2 ++ )
F_10 ( ( unsigned int ) V_43 [ V_2 ] , V_36 + V_38 + ( V_2 * 0x04 ) ) ;
}
static inline void F_15 ( void T_2 * V_36 )
{
F_14 ( V_36 , V_44 , F_16 ( 0 ) ,
F_2 ( V_44 ) ) ;
}
static inline void F_17 ( void T_2 * V_36 )
{
F_14 ( V_36 , V_45 , F_18 ( 0 ) ,
F_2 ( V_45 ) ) ;
}
static inline void F_19 ( void T_2 * V_36 )
{
F_14 ( V_36 , V_46 , F_20 ( 0 ) ,
F_2 ( V_46 ) ) ;
}
static inline void F_21 ( void T_2 * V_36 )
{
F_14 ( V_36 , V_47 , F_22 ( 0 ) ,
F_2 ( V_47 ) ) ;
}
static inline void F_23 ( void T_2 * V_36 ,
const unsigned char * V_48 ,
unsigned long V_38 , int V_39 )
{
int V_2 ;
unsigned int V_49 ;
for ( V_2 = 0 ; V_2 < V_39 ; V_2 += 4 ) {
V_49 = V_48 [ V_2 ] |
( V_48 [ V_2 + 1 ] << 8 ) |
( V_48 [ V_2 + 2 ] << 16 ) |
( V_48 [ V_2 + 3 ] << 24 ) ;
F_10 ( V_49 , V_36 + V_38 + V_2 ) ;
}
}
static inline void F_24 ( void T_2 * V_36 , int V_40 )
{
F_23 ( V_36 , V_41 [ V_40 ] ,
F_25 ( 0 ) ,
F_2 ( V_41 [ V_40 ] ) ) ;
}
static inline void F_26 ( void T_2 * V_36 , int V_40 )
{
F_23 ( V_36 , V_42 [ V_40 ] ,
F_25 ( 1 ) ,
F_2 ( V_42 [ V_40 ] ) ) ;
}
static void F_27 ( void T_2 * V_50 )
{
F_23 ( V_50 , V_44 , V_51 ,
F_2 ( V_44 ) ) ;
F_23 ( V_50 , V_44 , V_52 ,
F_2 ( V_44 ) ) ;
F_23 ( V_50 , V_45 , V_53 ,
F_2 ( V_45 ) ) ;
F_23 ( V_50 , V_45 , V_54 ,
F_2 ( V_45 ) ) ;
F_23 ( V_50 , V_46 , V_55 ,
F_2 ( V_46 ) ) ;
F_23 ( V_50 , V_46 , V_56 ,
F_2 ( V_46 ) ) ;
F_23 ( V_50 , V_47 , V_57 ,
F_2 ( V_47 ) ) ;
F_23 ( V_50 , V_47 , V_58 ,
F_2 ( V_47 ) ) ;
}
static inline int F_28 ( int V_59 , int V_60 , bool V_61 )
{
if ( V_59 ) {
if ( V_60 )
return V_61 ? V_56 :
V_58 ;
return V_61 ? V_55 : V_57 ;
}
if ( V_60 )
return V_61 ? V_52 : V_54 ;
return V_61 ? V_51 : V_53 ;
}
static inline int F_29 ( int V_59 , int V_60 )
{
return F_28 ( V_59 , V_60 , true ) ;
}
static inline int F_30 ( int V_59 , int V_60 )
{
return F_28 ( V_59 , V_60 , false ) ;
}
static void F_31 ( struct V_9 * V_10 )
{
struct V_62 * V_25 = V_10 -> V_25 ;
struct V_63 * V_64 = F_32 ( V_10 -> V_24 . V_65 ) ;
struct V_66 V_67 ;
unsigned int V_68 ;
int V_20 , V_69 , V_70 ;
V_67 . V_71 = 2 ;
V_67 . V_72 =
( unsigned long ) F_33 ( V_64 , 0 ) + V_10 -> V_73 . V_74 + 2 ;
V_67 . V_75 = 0 ;
V_68 = 0 ;
if ( F_34 ( & V_67 , & V_68 ) )
return;
V_67 . V_71 = ( long ) V_68 - 2 ;
V_67 . V_72 += 2 ;
V_67 . V_75 = 0 ;
V_70 = F_35 ( & V_67 ) ;
if ( V_70 == - 1 )
return;
while ( V_70 -- ) {
V_20 = F_35 ( & V_67 ) ;
if ( V_20 == - 1 )
return;
V_69 = F_35 ( & V_67 ) ;
if ( V_69 == - 1 )
return;
F_36 ( V_25 -> V_36 , V_20 ,
( ( ( V_69 >> 4 ) & 0x1 ) << 1 ) | ( V_69 & 0x1 ) ) ;
}
}
static void F_37 ( struct V_9 * V_10 )
{
struct V_62 * V_25 = V_10 -> V_25 ;
struct V_63 * V_64 = F_32 ( V_10 -> V_24 . V_65 ) ;
struct V_66 V_67 ;
unsigned int V_68 ;
int V_20 , V_2 , V_76 , V_77 ;
for ( V_77 = 0 ; V_77 < V_10 -> V_73 . V_78 . V_76 ; ++ V_77 ) {
V_67 . V_71 = V_10 -> V_73 . V_78 . V_39 [ V_77 ] ;
V_67 . V_72 = ( unsigned long ) F_33 ( V_64 , 0 ) +
V_10 -> V_73 . V_78 . V_79 [ V_77 ] ;
V_67 . V_75 = 0 ;
V_68 = 0 ;
while ( V_67 . V_75 < V_67 . V_71 ) {
char V_60 , V_59 ;
V_20 = F_35 ( & V_67 ) ;
if ( V_20 == - 1 )
return;
V_60 = V_20 & 0xf ;
V_59 = ( V_20 >> 4 ) & 0xf ;
V_76 = 0 ;
for ( V_2 = 0 ; V_2 < 16 ; ++ V_2 ) {
V_20 = F_35 ( & V_67 ) ;
if ( V_20 == - 1 )
return;
V_68 |= V_20 << ( ( V_2 % 4 ) * 8 ) ;
if ( ( V_2 + 1 ) % 4 == 0 ) {
F_10 ( V_68 , V_25 -> V_36 +
F_29 ( V_59 , V_60 ) +
( V_2 / 4 ) * 4 ) ;
V_68 = 0 ;
}
V_76 += V_20 ;
}
V_68 = 0 ;
for ( V_2 = 0 ; V_2 < V_76 ; ++ V_2 ) {
V_20 = F_35 ( & V_67 ) ;
if ( V_20 == - 1 )
return;
V_68 |= V_20 << ( ( V_2 % 4 ) * 8 ) ;
if ( ( V_2 + 1 ) % 4 == 0 ) {
F_10 ( V_68 , V_25 -> V_36 +
F_30 ( V_59 , V_60 ) +
( V_2 / 4 ) * 4 ) ;
V_68 = 0 ;
}
}
if ( V_2 % 4 ) {
F_10 ( V_68 , V_25 -> V_36 +
F_30 ( V_59 , V_60 ) + ( V_2 / 4 ) * 4 ) ;
}
V_68 = 0 ;
}
}
}
static void F_38 ( struct V_9 * V_10 )
{
struct V_62 * V_25 = V_10 -> V_25 ;
struct V_63 * V_64 = F_32 ( V_10 -> V_24 . V_65 ) ;
struct V_66 V_67 ;
int V_20 , V_69 , V_70 ;
V_67 . V_71 = V_10 -> V_73 . V_80 ;
V_67 . V_72 =
( unsigned long ) F_33 ( V_64 , 0 ) + V_10 -> V_73 . V_81 ;
V_67 . V_75 = 0 ;
F_39 ( & V_67 , 5 ) ;
V_70 = F_35 ( & V_67 ) ;
if ( V_70 == - 1 )
return;
F_40 ( V_25 -> V_36 , V_70 ) ;
while ( V_70 -- ) {
V_20 = F_35 ( & V_67 ) ;
if ( V_20 == - 1 )
return;
F_39 ( & V_67 , 1 ) ;
V_69 = F_35 ( & V_67 ) ;
if ( V_69 == - 1 )
return;
F_41 ( V_25 -> V_36 , V_20 , V_69 ) ;
}
}
static void F_42 ( struct V_9 * V_10 )
{
struct V_62 * V_25 = V_10 -> V_25 ;
struct V_63 * V_64 = F_32 ( V_10 -> V_24 . V_65 ) ;
struct V_66 V_67 ;
unsigned int V_68 ;
int V_20 , V_2 , V_77 ;
for ( V_77 = 0 ; V_77 < V_10 -> V_73 . V_82 . V_76 ; ++ V_77 ) {
V_67 . V_71 = V_10 -> V_73 . V_82 . V_39 [ V_77 ] ;
V_67 . V_72 = ( unsigned long ) F_33 ( V_64 , 0 ) +
V_10 -> V_73 . V_82 . V_79 [ V_77 ] ;
V_67 . V_75 = 0 ;
V_68 = 0 ;
while ( V_67 . V_71 - V_67 . V_75 >= 65 ) {
char V_60 ;
V_20 = F_35 ( & V_67 ) ;
if ( V_20 == - 1 )
return;
V_60 = V_20 & 0xf ;
if ( ( V_20 >> 4 ) & 0xf )
return;
for ( V_2 = 0 ; V_2 < 64 ; ++ V_2 ) {
V_20 = F_35 ( & V_67 ) ;
if ( V_20 == - 1 )
return;
V_68 |= V_20 << ( ( V_2 % 4 ) * 8 ) ;
if ( ( V_2 + 1 ) % 4 == 0 ) {
F_10 ( V_68 , V_25 -> V_36 +
F_25 ( V_60 ) + ( V_2 / 4 ) * 4 ) ;
V_68 = 0 ;
}
}
V_68 = 0 ;
}
}
}
static int F_43 ( struct V_83 * V_83 )
{
struct V_62 * V_25 = F_44 ( V_83 ) ;
struct V_84 * V_85 = F_45 ( V_83 ) ;
struct V_9 * V_10 ;
struct V_86 * V_87 , * V_88 ;
int V_89 = 0 ;
V_10 = F_46 ( sizeof( * V_10 ) , V_90 ) ;
if ( ! V_10 )
return - V_91 ;
if ( F_47 ( & V_25 -> V_92 ) ) {
V_89 = - V_93 ;
goto free;
}
F_48 ( & V_10 -> V_24 , V_85 ) ;
V_10 -> V_24 . V_22 = & V_10 -> V_22 ;
V_83 -> V_94 = & V_10 -> V_24 ;
F_49 ( & V_10 -> V_24 ) ;
V_10 -> V_25 = V_25 ;
if ( V_85 == V_25 -> V_95 ) {
V_10 -> V_96 = V_97 ;
V_87 = F_50 ( V_10 , V_98 ,
V_99 ) ;
V_88 = F_50 ( V_10 , V_100 ,
V_101 ) ;
} else {
V_10 -> V_96 = V_102 ;
V_87 = F_50 ( V_10 , V_100 ,
V_99 ) ;
V_88 = F_50 ( V_10 , V_103 ,
V_101 ) ;
V_10 -> V_104 = V_105 ;
}
V_10 -> V_24 . V_65 = F_51 ( V_25 -> V_106 , V_10 , V_107 ) ;
if ( F_52 ( V_10 -> V_24 . V_65 ) ) {
V_89 = F_53 ( V_10 -> V_24 . V_65 ) ;
goto error;
}
V_10 -> V_73 . V_108 = V_87 ;
V_10 -> V_109 . V_108 = V_88 ;
V_89 = F_54 ( V_10 ) ;
if ( V_89 < 0 )
goto error;
F_55 ( & V_25 -> V_92 ) ;
return 0 ;
error:
F_56 ( & V_10 -> V_24 ) ;
F_57 ( & V_10 -> V_24 ) ;
F_55 ( & V_25 -> V_92 ) ;
free:
F_58 ( V_10 ) ;
return V_89 ;
}
static int F_59 ( struct V_83 * V_83 )
{
struct V_62 * V_25 = F_44 ( V_83 ) ;
struct V_9 * V_10 = F_6 ( V_83 -> V_94 ) ;
F_60 ( & V_25 -> V_92 ) ;
F_61 ( V_10 -> V_24 . V_65 ) ;
F_62 ( & V_10 -> V_22 ) ;
F_56 ( & V_10 -> V_24 ) ;
F_57 ( & V_10 -> V_24 ) ;
F_58 ( V_10 ) ;
F_55 ( & V_25 -> V_92 ) ;
return 0 ;
}
static int F_35 ( struct V_66 * V_110 )
{
if ( V_110 -> V_75 >= V_110 -> V_71 )
return - 1 ;
return ( ( unsigned char * ) V_110 -> V_72 ) [ V_110 -> V_75 ++ ] ;
}
static int F_34 ( struct V_66 * V_110 , unsigned int * V_68 )
{
unsigned int V_111 ;
int V_112 ;
V_112 = F_35 ( V_110 ) ;
if ( V_112 == - 1 )
return - 1 ;
V_111 = V_112 << 8 ;
V_112 = F_35 ( V_110 ) ;
if ( V_112 == - 1 )
return - 1 ;
* V_68 = ( unsigned int ) V_112 | V_111 ;
return 0 ;
}
static void F_39 ( struct V_66 * V_110 , long V_39 )
{
if ( V_39 <= 0 )
return;
while ( V_39 -- )
F_35 ( V_110 ) ;
}
static bool F_63 ( struct V_9 * V_10 ,
unsigned int V_12 )
{
unsigned int V_27 ;
switch ( V_12 ) {
case 0x11 :
V_10 -> V_12 = V_113 ;
break;
case 0x21 :
V_10 -> V_12 = V_17 ;
break;
case 0x22 :
V_10 -> V_12 = V_15 ;
break;
case 0x33 :
V_10 -> V_12 = V_13 ;
break;
case 0x41 :
V_27 = V_10 -> V_25 -> V_26 -> V_27 ;
if ( V_27 != V_29 &&
V_27 != V_30 &&
V_27 != V_35 )
return false ;
V_10 -> V_12 = V_31 ;
break;
default:
return false ;
}
return true ;
}
static bool F_64 ( struct V_114 * V_115 ,
unsigned long V_116 , unsigned long V_71 ,
struct V_9 * V_10 )
{
int V_20 , V_70 = 0 , V_117 , V_118 = 0 , V_119 = 0 ;
unsigned int V_120 = 0 , V_121 = 0 , V_68 , V_12 = 0 ;
unsigned int V_74 = 0 , V_81 = 0 , V_80 = 0 ;
unsigned int V_78 [ V_122 ] , V_123 [ V_122 ] ;
unsigned int V_82 [ V_122 ] , V_124 [ V_122 ] ;
long V_125 ;
struct V_66 V_67 ;
V_67 . V_71 = V_71 ;
V_67 . V_72 = V_116 ;
V_67 . V_75 = 0 ;
V_117 = 1 ;
while ( V_117 || ! V_74 ) {
V_20 = F_35 ( & V_67 ) ;
if ( V_20 == - 1 )
return false ;
if ( V_20 != 0xff )
continue;
do
V_20 = F_35 ( & V_67 ) ;
while ( V_20 == 0xff );
if ( V_20 == - 1 )
return false ;
if ( V_20 == 0 )
continue;
V_125 = 0 ;
switch ( V_20 ) {
case V_126 :
if ( F_34 ( & V_67 , & V_68 ) )
break;
V_125 = ( long ) V_68 - 2 ;
if ( ! V_125 )
return false ;
V_81 = V_67 . V_75 ;
V_80 = V_125 ;
if ( F_35 ( & V_67 ) == - 1 )
break;
if ( F_34 ( & V_67 , & V_120 ) )
break;
if ( F_34 ( & V_67 , & V_121 ) )
break;
V_70 = F_35 ( & V_67 ) ;
if ( V_70 == - 1 )
break;
if ( V_70 == 1 ) {
V_12 = 0x33 ;
} else {
F_39 ( & V_67 , 1 ) ;
V_12 = F_35 ( & V_67 ) ;
F_39 ( & V_67 , 1 ) ;
}
if ( V_70 > 3 )
return false ;
F_39 ( & V_67 , V_70 * 2 ) ;
V_117 = 0 ;
break;
case V_127 :
if ( F_34 ( & V_67 , & V_68 ) )
break;
V_125 = ( long ) V_68 - 2 ;
if ( ! V_125 )
return false ;
if ( V_119 >= V_122 )
return false ;
V_82 [ V_119 ] = V_67 . V_75 ;
V_124 [ V_119 ++ ] = V_125 ;
F_39 ( & V_67 , V_125 ) ;
break;
case V_128 :
if ( F_34 ( & V_67 , & V_68 ) )
break;
V_125 = ( long ) V_68 - 2 ;
if ( ! V_125 )
return false ;
if ( V_118 >= V_122 )
return false ;
V_78 [ V_118 ] = V_67 . V_75 ;
V_123 [ V_118 ++ ] = V_125 ;
F_39 ( & V_67 , V_125 ) ;
break;
case V_129 :
V_74 = V_67 . V_75 - 2 ;
break;
case V_130 ... V_130 + 7 :
case V_131 :
case V_132 :
case V_133 :
break;
default:
if ( F_34 ( & V_67 , & V_68 ) )
break;
V_125 = ( long ) V_68 - 2 ;
F_39 ( & V_67 , V_125 ) ;
break;
}
}
if ( V_117 || ! V_74 || ! F_63 ( V_10 , V_12 ) )
return false ;
V_115 -> V_134 = V_121 ;
V_115 -> V_135 = V_120 ;
V_115 -> V_74 = V_74 ;
V_115 -> V_78 . V_76 = V_118 ;
while ( V_118 -- ) {
V_115 -> V_78 . V_79 [ V_118 ] = V_78 [ V_118 ] ;
V_115 -> V_78 . V_39 [ V_118 ] = V_123 [ V_118 ] ;
}
V_115 -> V_82 . V_76 = V_119 ;
while ( V_119 -- ) {
V_115 -> V_82 . V_79 [ V_119 ] = V_82 [ V_119 ] ;
V_115 -> V_82 . V_39 [ V_119 ] = V_124 [ V_119 ] ;
}
V_115 -> V_81 = V_81 ;
V_115 -> V_80 = V_80 ;
V_115 -> V_70 = V_70 ;
return true ;
}
static int F_65 ( struct V_83 * V_83 , void * V_136 ,
struct V_137 * V_138 )
{
struct V_9 * V_10 = F_6 ( V_136 ) ;
if ( V_10 -> V_96 == V_97 ) {
F_66 ( V_138 -> V_139 , V_140 ,
sizeof( V_138 -> V_139 ) ) ;
F_66 ( V_138 -> V_141 , V_140 L_1 ,
sizeof( V_138 -> V_141 ) ) ;
} else {
F_66 ( V_138 -> V_139 , V_140 ,
sizeof( V_138 -> V_139 ) ) ;
F_66 ( V_138 -> V_141 , V_140 L_2 ,
sizeof( V_138 -> V_141 ) ) ;
}
snprintf ( V_138 -> V_142 , sizeof( V_138 -> V_142 ) , L_3 ,
F_67 ( V_10 -> V_25 -> V_143 ) ) ;
V_138 -> V_144 = V_145 | V_146 ;
V_138 -> V_147 = V_138 -> V_144 | V_148 ;
return 0 ;
}
static int F_68 ( struct V_86 * V_149 , int V_76 ,
struct V_150 * V_151 , T_1 type )
{
int V_2 , V_152 = 0 ;
for ( V_2 = 0 ; V_2 < V_76 ; ++ V_2 ) {
if ( V_149 [ V_2 ] . V_153 & type ) {
if ( V_152 == V_151 -> V_154 )
break;
++ V_152 ;
}
}
if ( V_2 >= V_76 )
return - V_4 ;
F_66 ( V_151 -> V_155 , V_149 [ V_2 ] . V_156 , sizeof( V_151 -> V_155 ) ) ;
V_151 -> V_157 = V_149 [ V_2 ] . V_1 ;
return 0 ;
}
static int F_69 ( struct V_83 * V_83 , void * V_136 ,
struct V_150 * V_151 )
{
struct V_9 * V_10 = F_6 ( V_136 ) ;
if ( V_10 -> V_96 == V_97 )
return F_68 ( V_149 , V_158 , V_151 ,
V_159 ) ;
return F_68 ( V_149 , V_158 , V_151 ,
V_160 ) ;
}
static int F_70 ( struct V_83 * V_83 , void * V_136 ,
struct V_150 * V_151 )
{
struct V_9 * V_10 = F_6 ( V_136 ) ;
if ( V_10 -> V_96 == V_97 )
return F_68 ( V_149 , V_158 , V_151 ,
V_161 ) ;
return F_68 ( V_149 , V_158 , V_151 ,
V_162 ) ;
}
static struct V_114 * F_71 ( struct V_9 * V_10 ,
enum V_163 type )
{
if ( type == V_164 )
return & V_10 -> V_73 ;
if ( type == V_165 )
return & V_10 -> V_109 ;
return NULL ;
}
static int F_72 ( struct V_83 * V_83 , void * V_136 , struct V_166 * V_151 )
{
struct V_167 * V_168 ;
struct V_114 * V_169 = NULL ;
struct V_170 * V_171 = & V_151 -> V_108 . V_171 ;
struct V_9 * V_172 = F_6 ( V_136 ) ;
V_168 = F_73 ( V_172 -> V_24 . V_65 , V_151 -> type ) ;
if ( ! V_168 )
return - V_4 ;
if ( V_151 -> type == V_165 &&
V_172 -> V_96 == V_102 && ! V_172 -> V_173 )
return - V_4 ;
V_169 = F_71 ( V_172 , V_151 -> type ) ;
F_74 ( V_169 == NULL ) ;
V_171 -> V_121 = V_169 -> V_134 ;
V_171 -> V_120 = V_169 -> V_135 ;
V_171 -> V_174 = V_175 ;
V_171 -> V_157 = V_169 -> V_108 -> V_1 ;
V_171 -> V_176 = 0 ;
if ( V_169 -> V_108 -> V_1 != V_100 ) {
T_1 V_177 = V_169 -> V_134 ;
if ( V_169 -> V_108 -> V_178 == 1 )
V_177 = ( V_177 * V_169 -> V_108 -> V_179 ) >> 3 ;
V_171 -> V_176 = V_177 ;
}
V_171 -> V_180 = V_169 -> V_71 ;
return 0 ;
}
static struct V_86 * F_50 ( struct V_9 * V_10 ,
T_1 V_157 , unsigned int V_181 )
{
unsigned int V_182 , V_183 ;
if ( V_10 -> V_96 == V_97 )
V_183 = ( V_181 == V_99 ) ?
V_161 :
V_159 ;
else
V_183 = ( V_181 == V_99 ) ?
V_162 :
V_160 ;
for ( V_182 = 0 ; V_182 < F_2 ( V_149 ) ; V_182 ++ ) {
struct V_86 * V_108 = & V_149 [ V_182 ] ;
if ( V_108 -> V_1 == V_157 &&
V_108 -> V_153 & V_183 &&
V_108 -> V_153 & V_10 -> V_25 -> V_26 -> V_184 ) {
return V_108 ;
}
}
return NULL ;
}
static void F_75 ( struct V_9 * V_10 ,
T_1 * V_134 , unsigned int V_185 , unsigned int V_186 ,
unsigned int V_187 ,
T_1 * V_135 , unsigned int V_188 , unsigned int V_189 ,
unsigned int V_190 )
{
int V_121 , V_120 , V_191 , V_192 ;
V_121 = * V_134 ;
V_120 = * V_135 ;
V_191 = 1 << V_187 ;
V_192 = 1 << V_190 ;
if ( V_10 -> V_25 -> V_26 -> V_193 ) {
if ( V_191 == 4 && ( ( V_121 & 3 ) == 1 ) ) {
V_186 = V_121 ;
V_189 = V_120 ;
}
}
F_76 ( V_134 , V_185 , V_186 , V_187 , V_135 , V_188 , V_189 , V_190 , 0 ) ;
if ( * V_134 < V_121 && ( * V_134 + V_191 ) < V_186 )
* V_134 += V_191 ;
if ( * V_135 < V_120 && ( * V_135 + V_192 ) < V_189 )
* V_135 += V_192 ;
}
static int F_77 ( struct V_166 * V_151 , struct V_86 * V_108 ,
struct V_9 * V_10 , int V_194 )
{
struct V_170 * V_171 = & V_151 -> V_108 . V_171 ;
if ( V_171 -> V_174 == V_195 )
V_171 -> V_174 = V_175 ;
else if ( V_171 -> V_174 != V_175 )
return - V_4 ;
if ( V_194 == V_99 )
F_75 ( V_10 , & V_171 -> V_121 , V_196 ,
V_197 , 0 ,
& V_171 -> V_120 , V_198 ,
V_199 , 0 ) ;
else
F_75 ( V_10 , & V_171 -> V_121 , V_196 ,
V_197 , V_108 -> V_200 ,
& V_171 -> V_120 , V_198 ,
V_199 , V_108 -> V_201 ) ;
if ( V_108 -> V_1 == V_100 ) {
if ( V_171 -> V_180 <= 0 )
V_171 -> V_180 = V_202 ;
V_171 -> V_176 = 0 ;
} else {
T_1 V_177 = V_171 -> V_176 ;
if ( V_108 -> V_178 > 1 && V_177 < V_171 -> V_121 )
V_177 = V_171 -> V_121 ;
if ( V_108 -> V_178 == 1 &&
( V_177 << 3 ) / V_108 -> V_179 < V_171 -> V_121 )
V_177 = ( V_171 -> V_121 * V_108 -> V_179 ) >> 3 ;
V_171 -> V_176 = V_177 ;
V_171 -> V_180 = ( V_171 -> V_121 * V_171 -> V_120 * V_108 -> V_179 ) >> 3 ;
}
return 0 ;
}
static int F_78 ( struct V_83 * V_83 , void * V_136 ,
struct V_166 * V_151 )
{
struct V_9 * V_10 = F_6 ( V_136 ) ;
struct V_170 * V_171 = & V_151 -> V_108 . V_171 ;
struct V_86 * V_108 ;
int V_89 ;
V_108 = F_50 ( V_10 , V_151 -> V_108 . V_171 . V_157 ,
V_101 ) ;
if ( ! V_108 ) {
F_79 ( & V_10 -> V_25 -> V_203 ,
L_4 ,
V_151 -> V_108 . V_171 . V_157 ) ;
return - V_4 ;
}
if ( ! V_10 -> V_25 -> V_26 -> V_204 || V_10 -> V_96 != V_102 )
goto exit;
if ( ( V_108 -> V_153 & V_205 ) &&
( V_108 -> V_12 < V_10 -> V_12 ) ) {
V_89 = F_3 ( V_10 -> V_12 ,
V_108 -> V_1 ,
& V_171 -> V_157 ,
V_10 ) ;
if ( V_89 < 0 )
V_171 -> V_157 = V_14 ;
V_108 = F_50 ( V_10 , V_171 -> V_157 ,
V_101 ) ;
}
if ( V_10 -> V_12 == V_15 &&
( V_10 -> V_73 . V_134 & 1 ) &&
( V_171 -> V_157 == V_206 ||
V_171 -> V_157 == V_207 ||
V_171 -> V_157 == V_208 ) ) {
V_171 -> V_157 = V_98 ;
V_108 = F_50 ( V_10 , V_171 -> V_157 ,
V_101 ) ;
}
exit:
return F_77 ( V_151 , V_108 , V_10 , V_101 ) ;
}
static int F_80 ( struct V_83 * V_83 , void * V_136 ,
struct V_166 * V_151 )
{
struct V_9 * V_10 = F_6 ( V_136 ) ;
struct V_86 * V_108 ;
V_108 = F_50 ( V_10 , V_151 -> V_108 . V_171 . V_157 ,
V_99 ) ;
if ( ! V_108 ) {
F_79 ( & V_10 -> V_25 -> V_203 ,
L_4 ,
V_151 -> V_108 . V_171 . V_157 ) ;
return - V_4 ;
}
return F_77 ( V_151 , V_108 , V_10 , V_99 ) ;
}
static int F_81 ( struct V_9 * V_10 ,
struct V_166 * V_151 ,
int V_209 )
{
struct V_170 * V_171 = & V_151 -> V_108 . V_171 ;
T_1 V_210 = V_151 -> V_108 . V_171 . V_157 ;
int V_134 = V_171 -> V_121 , V_135 = V_171 -> V_120 , V_211 ;
int V_212 = 0 ;
if ( V_210 == V_213 ||
V_210 == V_98 ||
V_210 == V_214 ||
V_210 == V_215 ||
V_210 == V_206 ||
V_210 == V_207 ||
V_210 == V_208 )
V_211 = 4 ;
else
V_211 = 1 ;
F_75 ( V_10 , & V_134 , V_196 ,
V_197 , V_211 ,
& V_135 , V_198 ,
V_199 , V_211 ) ;
if ( V_10 -> V_25 -> V_26 -> V_27 == V_33 )
V_212 = V_202 ;
return ( V_134 * V_135 * V_209 >> 3 ) + V_212 ;
}
static int F_82 ( struct V_9 * V_172 , struct V_166 * V_151 )
{
struct V_167 * V_168 ;
struct V_114 * V_169 = NULL ;
struct V_170 * V_171 = & V_151 -> V_108 . V_171 ;
struct V_19 * V_216 ;
struct V_217 V_218 ;
unsigned int V_219 ;
V_168 = F_73 ( V_172 -> V_24 . V_65 , V_151 -> type ) ;
if ( ! V_168 )
return - V_4 ;
V_169 = F_71 ( V_172 , V_151 -> type ) ;
F_74 ( V_169 == NULL ) ;
if ( F_83 ( V_168 ) ) {
F_79 ( & V_172 -> V_25 -> V_203 , L_5 , V_220 ) ;
return - V_221 ;
}
V_219 = F_84 ( V_151 -> type ) ?
V_99 : V_101 ;
V_169 -> V_108 = F_50 ( V_172 , V_171 -> V_157 , V_219 ) ;
if ( V_172 -> V_96 == V_97 ||
( V_172 -> V_96 == V_102 &&
V_169 -> V_108 -> V_1 != V_100 ) ) {
V_169 -> V_134 = V_171 -> V_121 ;
V_169 -> V_135 = V_171 -> V_120 ;
}
if ( V_169 -> V_108 -> V_1 != V_100 ) {
if ( V_172 -> V_25 -> V_26 -> V_204 &&
V_219 == V_99 && V_172 -> V_96 == V_97 )
V_169 -> V_71 = F_81 ( V_172 ,
V_151 ,
V_169 -> V_108 -> V_179 ) ;
else
V_169 -> V_71 = V_169 -> V_134 * V_169 -> V_135 *
V_169 -> V_108 -> V_179 >> 3 ;
} else {
V_169 -> V_71 = V_171 -> V_180 ;
}
if ( V_219 == V_99 ) {
V_216 = F_85 ( & V_172 -> V_22 ,
V_222 ) ;
if ( V_216 )
F_86 ( V_216 , V_169 -> V_108 -> V_12 ) ;
V_172 -> V_223 = false ;
}
if ( ! V_172 -> V_223 &&
( ( V_172 -> V_96 == V_102 && V_219 == V_101 ) ||
( V_172 -> V_96 == V_97 && V_219 == V_99 ) ) ) {
V_172 -> V_224 . V_121 = V_171 -> V_121 ;
V_172 -> V_224 . V_120 = V_171 -> V_120 ;
}
if ( V_172 -> V_96 == V_102 &&
V_219 == V_101 &&
V_172 -> V_25 -> V_26 -> V_193 &&
V_171 -> V_157 == V_208 &&
V_172 -> V_104 > 2 ) {
V_218 . V_121 = V_172 -> V_73 . V_134 / 2 ;
V_218 . V_120 = V_172 -> V_73 . V_135 / 2 ;
F_87 ( V_172 , & V_218 ) ;
}
return 0 ;
}
static int F_88 ( struct V_83 * V_83 , void * V_136 ,
struct V_166 * V_151 )
{
int V_89 ;
V_89 = F_78 ( V_83 , V_136 , V_151 ) ;
if ( V_89 )
return V_89 ;
return F_82 ( F_6 ( V_136 ) , V_151 ) ;
}
static int F_89 ( struct V_83 * V_83 , void * V_136 ,
struct V_166 * V_151 )
{
int V_89 ;
V_89 = F_80 ( V_83 , V_136 , V_151 ) ;
if ( V_89 )
return V_89 ;
return F_82 ( F_6 ( V_136 ) , V_151 ) ;
}
static int F_90 ( struct V_23 * V_24 ,
const struct V_225 * V_226 )
{
if ( V_226 -> type == V_227 )
return F_91 ( V_24 , V_226 ) ;
return - V_4 ;
}
static int F_87 ( struct V_9 * V_10 ,
struct V_217 * V_228 )
{
int V_229 , V_230 , V_104 , V_231 , V_2 ;
V_229 = V_10 -> V_73 . V_134 / V_228 -> V_121 ;
V_230 = V_10 -> V_73 . V_135 / V_228 -> V_120 ;
V_104 = V_229 > V_230 ? V_229 : V_230 ;
V_104 = F_92 ( V_104 , 1 , 8 ) ;
for ( V_2 = 0 ; V_2 <= 3 ; ++ V_2 ) {
V_231 = 1 << V_2 ;
if ( V_104 <= V_231 ) {
V_10 -> V_104 = V_231 ;
break;
}
}
V_228 -> V_121 = F_93 ( V_10 -> V_73 . V_134 / V_10 -> V_104 , 2 ) ;
V_228 -> V_120 = F_93 ( V_10 -> V_73 . V_135 / V_10 -> V_104 , 2 ) ;
V_10 -> V_224 . V_121 = V_228 -> V_121 ;
V_10 -> V_224 . V_120 = V_228 -> V_120 ;
V_10 -> V_224 . V_232 = 0 ;
V_10 -> V_224 . V_233 = 0 ;
V_10 -> V_223 = true ;
return 0 ;
}
static int F_94 ( struct V_217 * V_234 , struct V_217 * V_235 )
{
if ( V_234 -> V_232 < V_235 -> V_232 || V_234 -> V_233 < V_235 -> V_233 )
return 0 ;
if ( V_234 -> V_232 + V_234 -> V_121 > V_235 -> V_232 + V_235 -> V_121 )
return 0 ;
if ( V_234 -> V_233 + V_234 -> V_120 > V_235 -> V_233 + V_235 -> V_120 )
return 0 ;
return 1 ;
}
static int F_95 ( struct V_9 * V_10 ,
struct V_217 * V_228 )
{
struct V_217 V_236 ;
int V_191 , V_192 ;
switch ( V_10 -> V_109 . V_108 -> V_1 ) {
case V_206 :
case V_207 :
V_191 = 1 ;
V_192 = 2 ;
break;
case V_208 :
V_191 = 2 ;
V_192 = 2 ;
break;
default:
V_191 = 1 ;
V_192 = 1 ;
break;
}
V_236 . V_233 = 0 ;
V_236 . V_232 = 0 ;
V_236 . V_121 = V_10 -> V_73 . V_134 ;
V_236 . V_120 = V_10 -> V_73 . V_135 ;
V_228 -> V_121 = F_93 ( V_228 -> V_121 , V_191 ) ;
V_228 -> V_120 = F_93 ( V_228 -> V_120 , V_192 ) ;
V_228 -> V_232 = F_93 ( V_228 -> V_232 , 2 ) ;
V_228 -> V_233 = F_93 ( V_228 -> V_233 , 2 ) ;
if ( ! F_94 ( V_228 , & V_236 ) )
return - V_4 ;
V_10 -> V_224 . V_232 = V_228 -> V_232 ;
V_10 -> V_224 . V_233 = V_228 -> V_233 ;
V_10 -> V_224 . V_121 = V_228 -> V_121 ;
V_10 -> V_224 . V_120 = V_228 -> V_120 ;
V_10 -> V_223 = true ;
return 0 ;
}
static int F_96 ( struct V_83 * V_83 , void * V_136 ,
struct V_237 * V_238 )
{
struct V_9 * V_10 = F_6 ( V_136 ) ;
if ( V_238 -> type != V_164 &&
V_238 -> type != V_165 )
return - V_4 ;
switch ( V_238 -> V_239 ) {
case V_240 :
case V_241 :
case V_242 :
case V_243 :
V_238 -> V_228 . V_121 = V_10 -> V_73 . V_134 ;
V_238 -> V_228 . V_120 = V_10 -> V_73 . V_135 ;
V_238 -> V_228 . V_232 = 0 ;
V_238 -> V_228 . V_233 = 0 ;
break;
case V_244 :
case V_245 :
case V_246 :
V_238 -> V_228 . V_121 = V_10 -> V_224 . V_121 ;
V_238 -> V_228 . V_120 = V_10 -> V_224 . V_120 ;
V_238 -> V_228 . V_232 = V_10 -> V_224 . V_232 ;
V_238 -> V_228 . V_233 = V_10 -> V_224 . V_233 ;
break;
default:
return - V_4 ;
}
return 0 ;
}
static int F_97 ( struct V_83 * V_83 , void * V_24 ,
struct V_237 * V_238 )
{
struct V_9 * V_10 = F_6 ( V_83 -> V_94 ) ;
struct V_217 * V_247 = & V_238 -> V_228 ;
int V_89 = - V_4 ;
if ( V_238 -> type != V_165 )
return - V_4 ;
if ( V_238 -> V_239 == V_244 ) {
if ( V_10 -> V_96 != V_102 )
return - V_4 ;
if ( V_10 -> V_25 -> V_26 -> V_193 )
V_89 = F_87 ( V_10 , V_247 ) ;
} else if ( V_238 -> V_239 == V_240 ) {
if ( V_10 -> V_96 != V_97 )
return - V_4 ;
if ( V_10 -> V_25 -> V_26 -> V_193 )
V_89 = F_95 ( V_10 , V_247 ) ;
}
return V_89 ;
}
static int F_98 ( struct V_19 * V_248 )
{
struct V_9 * V_10 = F_4 ( V_248 ) ;
struct V_62 * V_25 = V_10 -> V_25 ;
unsigned long V_153 ;
switch ( V_248 -> V_60 ) {
case V_222 :
F_99 ( & V_25 -> V_249 , V_153 ) ;
V_248 -> V_250 = F_7 ( V_10 ) ;
F_100 ( & V_25 -> V_249 , V_153 ) ;
break;
}
return 0 ;
}
static int F_101 ( struct V_9 * V_10 , int * V_251 )
{
switch ( V_10 -> V_25 -> V_26 -> V_27 ) {
case V_28 :
return 0 ;
case V_29 :
case V_30 :
if ( V_10 -> V_73 . V_108 -> V_1 == V_213 )
* V_251 = 0 ;
break;
case V_33 :
if ( V_10 -> V_73 . V_108 -> V_1 != V_14 &&
* V_251 == V_13 )
return - V_4 ;
break;
}
if ( V_10 -> V_73 . V_108 -> V_12 > * V_251 )
* V_251 = V_10 -> V_73 . V_108 -> V_12 ;
return 0 ;
}
static int F_102 ( struct V_19 * V_248 )
{
struct V_9 * V_10 = F_4 ( V_248 ) ;
unsigned long V_153 ;
int V_89 = 0 ;
F_99 ( & V_10 -> V_25 -> V_249 , V_153 ) ;
if ( V_248 -> V_60 == V_222 )
V_89 = F_101 ( V_10 , & V_248 -> V_250 ) ;
F_100 ( & V_10 -> V_25 -> V_249 , V_153 ) ;
return V_89 ;
}
static int F_103 ( struct V_19 * V_248 )
{
struct V_9 * V_10 = F_4 ( V_248 ) ;
unsigned long V_153 ;
F_99 ( & V_10 -> V_25 -> V_249 , V_153 ) ;
switch ( V_248 -> V_60 ) {
case V_252 :
V_10 -> V_253 = V_248 -> V_250 ;
break;
case V_254 :
V_10 -> V_255 = V_248 -> V_250 ;
break;
case V_222 :
V_10 -> V_12 = V_248 -> V_250 ;
break;
}
F_100 ( & V_10 -> V_25 -> V_249 , V_153 ) ;
return 0 ;
}
static int F_54 ( struct V_9 * V_10 )
{
unsigned int V_256 = ~ 0x27 ;
struct V_19 * V_248 ;
int V_89 ;
F_104 ( & V_10 -> V_22 , 3 ) ;
if ( V_10 -> V_96 == V_97 ) {
F_105 ( & V_10 -> V_22 , & V_257 ,
V_252 ,
0 , 3 , 1 , V_258 ) ;
F_105 ( & V_10 -> V_22 , & V_257 ,
V_254 ,
0 , 3 , 0xffff , 0 ) ;
if ( V_10 -> V_25 -> V_26 -> V_27 == V_28 )
V_256 = ~ 0x06 ;
}
V_248 = F_106 ( & V_10 -> V_22 , & V_257 ,
V_222 ,
V_13 , V_256 ,
V_17 ) ;
if ( V_10 -> V_22 . error ) {
V_89 = V_10 -> V_22 . error ;
goto V_259;
}
if ( V_10 -> V_96 == V_102 )
V_248 -> V_153 |= V_260 |
V_261 ;
V_89 = F_107 ( & V_10 -> V_22 ) ;
if ( V_89 < 0 )
goto V_259;
return V_89 ;
V_259:
F_62 ( & V_10 -> V_22 ) ;
return V_89 ;
}
static void F_108 ( void * V_136 )
{
struct V_9 * V_10 = V_136 ;
struct V_62 * V_25 = V_10 -> V_25 ;
struct V_63 * V_262 , * V_263 ;
unsigned long V_264 , V_265 , V_153 ;
F_99 ( & V_10 -> V_25 -> V_249 , V_153 ) ;
V_262 = F_32 ( V_10 -> V_24 . V_65 ) ;
V_263 = F_109 ( V_10 -> V_24 . V_65 ) ;
V_264 = F_110 ( V_262 , 0 ) ;
V_265 = F_110 ( V_263 , 0 ) ;
F_111 ( V_25 -> V_36 ) ;
F_112 ( V_25 -> V_36 ) ;
F_113 ( V_25 -> V_36 , V_10 -> V_96 ) ;
if ( V_10 -> V_96 == V_97 ) {
if ( V_10 -> V_73 . V_108 -> V_1 == V_98 )
F_114 ( V_25 -> V_36 ,
V_266 ) ;
else
F_114 ( V_25 -> V_36 ,
V_267 ) ;
F_115 ( V_25 -> V_36 , V_10 -> V_12 ) ;
F_116 ( V_25 -> V_36 , V_10 -> V_255 ) ;
F_117 ( V_25 -> V_36 , V_10 -> V_73 . V_134 ) ;
F_118 ( V_25 -> V_36 , V_10 -> V_73 . V_135 ) ;
F_119 ( V_25 -> V_36 , V_264 ) ;
F_120 ( V_25 -> V_36 , V_265 ) ;
F_121 ( V_25 -> V_36 , V_10 -> V_109 . V_71 ) ;
F_122 ( V_25 -> V_36 , 1 , 1 , V_268 ) ;
F_122 ( V_25 -> V_36 , 1 , 2 , V_269 ) ;
F_122 ( V_25 -> V_36 , 1 , 3 , V_270 ) ;
F_122 ( V_25 -> V_36 , 2 , 1 , V_271 ) ;
F_122 ( V_25 -> V_36 , 2 , 2 , V_272 ) ;
F_122 ( V_25 -> V_36 , 2 , 3 , V_273 ) ;
F_122 ( V_25 -> V_36 , 3 , 1 , V_274 ) ;
F_122 ( V_25 -> V_36 , 3 , 2 , V_275 ) ;
F_122 ( V_25 -> V_36 , 3 , 3 , V_276 ) ;
F_11 ( V_25 -> V_36 , V_10 -> V_253 ) ;
F_13 ( V_25 -> V_36 , V_10 -> V_253 ) ;
F_123 ( V_25 -> V_36 , 1 , 0 ) ;
F_123 ( V_25 -> V_36 , 2 , 1 ) ;
F_123 ( V_25 -> V_36 , 3 , 1 ) ;
F_124 ( V_25 -> V_36 , 1 ) ;
F_125 ( V_25 -> V_36 , 1 ) ;
F_124 ( V_25 -> V_36 , 2 ) ;
F_125 ( V_25 -> V_36 , 2 ) ;
F_124 ( V_25 -> V_36 , 3 ) ;
F_125 ( V_25 -> V_36 , 3 ) ;
} else {
F_126 ( V_25 -> V_36 , true ) ;
F_127 ( V_25 -> V_36 , true ) ;
F_128 ( V_25 -> V_36 , true ) ;
if ( V_10 -> V_109 . V_108 -> V_1 == V_103 )
F_129 ( V_25 -> V_36 , V_277 ) ;
else
F_129 ( V_25 -> V_36 , V_278 ) ;
F_120 ( V_25 -> V_36 , V_264 ) ;
F_119 ( V_25 -> V_36 , V_265 ) ;
}
F_130 ( V_25 -> V_36 ) ;
F_100 ( & V_10 -> V_25 -> V_249 , V_153 ) ;
}
static void F_131 ( struct V_9 * V_10 )
{
struct V_62 * V_25 = V_10 -> V_25 ;
struct V_86 * V_108 ;
struct V_63 * V_64 ;
struct V_279 V_280 = {} ;
T_1 V_281 , V_282 = 0 ;
V_280 . V_283 = 0 ;
V_280 . V_284 = 0 ;
V_281 = V_10 -> V_109 . V_134 * V_10 -> V_109 . V_135 ;
if ( V_10 -> V_96 == V_97 ) {
V_64 = F_32 ( V_10 -> V_24 . V_65 ) ;
V_108 = V_10 -> V_73 . V_108 ;
if ( V_10 -> V_73 . V_134 % 2 && V_108 -> V_200 > 0 )
V_282 = V_10 -> V_73 . V_135 ;
} else {
V_108 = V_10 -> V_109 . V_108 ;
V_64 = F_109 ( V_10 -> V_24 . V_65 ) ;
}
V_280 . V_285 = F_110 ( V_64 , 0 ) ;
if ( V_108 -> V_178 == 2 ) {
V_280 . V_283 = V_280 . V_285 + V_281 - V_282 ;
} else if ( V_108 -> V_178 == 3 ) {
V_280 . V_283 = V_280 . V_285 + V_281 ;
if ( V_108 -> V_1 == V_208 )
V_280 . V_284 = V_280 . V_283 + V_281 / 4 ;
else
V_280 . V_284 = V_280 . V_283 + V_281 / 2 ;
}
F_132 ( V_25 -> V_36 , & V_280 ) ;
}
static void F_133 ( struct V_9 * V_10 )
{
struct V_62 * V_25 = V_10 -> V_25 ;
struct V_63 * V_64 ;
unsigned int V_280 = 0 ;
if ( V_10 -> V_96 == V_97 )
V_64 = F_109 ( V_10 -> V_24 . V_65 ) ;
else
V_64 = F_32 ( V_10 -> V_24 . V_65 ) ;
V_280 = F_110 ( V_64 , 0 ) ;
if ( V_25 -> V_26 -> V_27 == V_35 &&
V_10 -> V_96 == V_102 )
V_280 += V_10 -> V_73 . V_74 ;
F_134 ( V_25 -> V_36 , V_280 ) ;
}
static inline void F_135 ( void T_2 * V_50 ,
unsigned int V_286 )
{
F_136 ( V_50 , V_286 , V_33 ) ;
}
static inline void F_137 ( void T_2 * V_50 ,
unsigned int V_286 )
{
F_136 ( V_50 , V_286 , V_35 ) ;
}
static inline void F_138 ( void T_2 * V_50 ,
unsigned int V_87 )
{
F_139 ( V_50 , V_87 , V_33 ) ;
}
static inline void F_140 ( void T_2 * V_50 ,
unsigned int V_87 )
{
F_139 ( V_50 , V_87 , V_35 ) ;
}
static void F_141 ( void * V_136 )
{
struct V_9 * V_10 = V_136 ;
struct V_62 * V_25 = V_10 -> V_25 ;
unsigned int V_287 ;
unsigned long V_153 ;
F_99 ( & V_25 -> V_249 , V_153 ) ;
if ( V_10 -> V_96 == V_97 ) {
F_142 ( V_25 -> V_36 ) ;
F_143 ( V_25 -> V_36 , V_25 -> V_26 -> V_27 ) ;
F_144 ( V_25 -> V_36 , 1 ) ;
F_27 ( V_25 -> V_36 ) ;
F_24 ( V_25 -> V_36 , V_10 -> V_253 ) ;
F_26 ( V_25 -> V_36 , V_10 -> V_253 ) ;
F_145 ( V_25 -> V_36 ,
V_10 -> V_253 ) ;
F_146 ( V_25 -> V_36 , V_10 -> V_109 . V_134 ,
V_10 -> V_109 . V_135 ) ;
if ( V_10 -> V_25 -> V_26 -> V_27 == V_33 ) {
F_138 ( V_25 -> V_36 ,
V_10 -> V_12 ) ;
F_135 ( V_25 -> V_36 ,
V_10 -> V_73 . V_108 -> V_1 ) ;
} else {
F_140 ( V_25 -> V_36 ,
V_10 -> V_12 ) ;
F_137 ( V_25 -> V_36 ,
V_10 -> V_73 . V_108 -> V_1 ) ;
}
F_131 ( V_10 ) ;
F_133 ( V_10 ) ;
F_147 ( V_25 -> V_36 ,
V_10 -> V_73 . V_108 -> V_1 ) ;
} else {
F_142 ( V_25 -> V_36 ) ;
F_143 ( V_25 -> V_36 ,
V_25 -> V_26 -> V_27 ) ;
F_131 ( V_10 ) ;
F_133 ( V_10 ) ;
if ( V_25 -> V_26 -> V_27 == V_35 ) {
F_37 ( V_10 ) ;
F_31 ( V_10 ) ;
F_42 ( V_10 ) ;
F_38 ( V_10 ) ;
F_144 ( V_25 -> V_36 , 1 ) ;
F_146 ( V_25 -> V_36 , V_10 -> V_109 . V_134 ,
V_10 -> V_109 . V_135 ) ;
F_140 ( V_25 -> V_36 ,
V_10 -> V_12 ) ;
F_137 ( V_25 -> V_36 ,
V_10 -> V_109 . V_108 -> V_1 ) ;
V_287 = F_148 ( V_10 -> V_73 . V_71 , 16 ) ;
} else {
F_135 ( V_25 -> V_36 ,
V_10 -> V_109 . V_108 -> V_1 ) ;
V_287 = F_148 ( V_10 -> V_73 . V_71 , 32 ) ;
}
F_149 ( V_25 -> V_36 , V_287 ) ;
}
F_150 ( V_25 -> V_36 , 1 ) ;
F_151 ( V_25 -> V_36 , V_10 -> V_96 ) ;
F_100 ( & V_25 -> V_249 , V_153 ) ;
}
static void F_152 ( struct V_9 * V_10 )
{
struct V_62 * V_25 = V_10 -> V_25 ;
struct V_86 * V_108 ;
struct V_63 * V_64 ;
struct V_279 V_280 = {} ;
T_1 V_281 ;
V_281 = V_10 -> V_109 . V_134 * V_10 -> V_109 . V_135 ;
if ( V_10 -> V_96 == V_97 ) {
V_64 = F_32 ( V_10 -> V_24 . V_65 ) ;
V_108 = V_10 -> V_73 . V_108 ;
} else {
V_64 = F_109 ( V_10 -> V_24 . V_65 ) ;
V_108 = V_10 -> V_109 . V_108 ;
}
V_280 . V_285 = F_110 ( V_64 , 0 ) ;
if ( V_108 -> V_178 == 2 ) {
V_280 . V_283 = V_280 . V_285 + V_281 ;
} else if ( V_108 -> V_178 == 3 ) {
V_280 . V_283 = V_280 . V_285 + V_281 ;
if ( V_108 -> V_1 == V_208 )
V_280 . V_284 = V_280 . V_283 + V_281 / 4 ;
else
V_280 . V_284 = V_280 . V_283 + V_281 / 2 ;
}
F_153 ( V_25 -> V_36 , & V_280 ) ;
}
static void F_154 ( struct V_9 * V_10 )
{
struct V_62 * V_25 = V_10 -> V_25 ;
struct V_63 * V_64 ;
unsigned int V_280 = 0 ;
if ( V_10 -> V_96 == V_97 )
V_64 = F_109 ( V_10 -> V_24 . V_65 ) ;
else
V_64 = F_32 ( V_10 -> V_24 . V_65 ) ;
V_280 = F_110 ( V_64 , 0 ) ;
F_155 ( V_25 -> V_36 , V_280 ) ;
}
static void F_156 ( void * V_136 )
{
struct V_9 * V_10 = V_136 ;
struct V_62 * V_25 = V_10 -> V_25 ;
unsigned long V_153 ;
F_99 ( & V_10 -> V_25 -> V_249 , V_153 ) ;
F_157 ( V_25 -> V_36 ) ;
F_158 ( V_25 -> V_36 ) ;
F_159 ( V_25 -> V_36 ) ;
F_160 ( V_25 -> V_36 ) ;
F_161 ( V_25 -> V_36 , V_10 -> V_96 ) ;
if ( V_10 -> V_96 == V_97 ) {
F_162 ( V_25 -> V_36 ,
V_10 -> V_73 . V_108 -> V_1 ) ;
F_163 ( V_25 -> V_36 , V_10 -> V_255 ) ;
F_11 ( V_25 -> V_36 , V_10 -> V_253 ) ;
F_13 ( V_25 -> V_36 , V_10 -> V_253 ) ;
F_164 ( V_25 -> V_36 , 1 , 0 ) ;
F_164 ( V_25 -> V_36 , 2 , 1 ) ;
F_164 ( V_25 -> V_36 , 3 , 1 ) ;
if ( V_25 -> V_26 -> V_288 ) {
F_15 ( V_25 -> V_36 ) ;
F_17 ( V_25 -> V_36 ) ;
F_19 ( V_25 -> V_36 ) ;
F_21 ( V_25 -> V_36 ) ;
}
F_165 ( V_25 -> V_36 , 1 ) ;
F_166 ( V_25 -> V_36 , 1 ) ;
F_165 ( V_25 -> V_36 , 2 ) ;
F_166 ( V_25 -> V_36 , 2 ) ;
F_165 ( V_25 -> V_36 , 3 ) ;
F_166 ( V_25 -> V_36 , 3 ) ;
F_167 ( V_25 -> V_36 , V_10 -> V_224 . V_121 ) ;
F_168 ( V_25 -> V_36 , V_10 -> V_224 . V_120 ) ;
F_169 ( V_25 -> V_36 , V_10 -> V_73 . V_108 -> V_1 ,
V_10 -> V_73 . V_134 ) ;
F_170 ( V_25 -> V_36 , V_10 -> V_224 . V_232 ,
V_10 -> V_224 . V_233 ) ;
F_152 ( V_10 ) ;
F_154 ( V_10 ) ;
F_171 ( V_25 -> V_36 , V_10 -> V_12 ) ;
F_172 ( V_25 -> V_36 , V_10 -> V_109 . V_71 ) ;
if ( V_10 -> V_73 . V_108 -> V_1 == V_98 ||
V_10 -> V_73 . V_108 -> V_1 == V_289 ||
V_10 -> V_73 . V_108 -> V_1 == V_213 )
F_173 ( V_25 -> V_36 , true ) ;
} else {
F_152 ( V_10 ) ;
F_154 ( V_10 ) ;
F_169 ( V_25 -> V_36 , V_10 -> V_109 . V_108 -> V_1 ,
V_10 -> V_109 . V_134 ) ;
F_170 ( V_25 -> V_36 , 0 , 0 ) ;
F_174 ( V_25 -> V_36 ,
V_10 -> V_104 ) ;
F_175 ( V_25 -> V_36 , V_10 -> V_73 . V_71 ) ;
F_176 ( V_25 -> V_36 ,
V_10 -> V_109 . V_108 -> V_1 ) ;
}
F_177 ( V_25 -> V_36 ) ;
F_178 ( V_25 -> V_36 , V_10 -> V_96 ) ;
F_179 ( V_25 -> V_36 , V_290 ) ;
V_25 -> V_291 = 0 ;
F_180 ( V_25 -> V_36 ) ;
F_100 ( & V_10 -> V_25 -> V_249 , V_153 ) ;
}
static int F_181 ( void * V_136 )
{
struct V_9 * V_10 = V_136 ;
if ( V_10 -> V_96 == V_102 ) {
if ( V_10 -> V_292 == V_293 )
return 0 ;
return V_10 -> V_173 ;
}
return 1 ;
}
static void F_182 ( void * V_136 )
{
}
static int F_183 ( struct V_167 * V_168 ,
unsigned int * V_294 , unsigned int * V_295 ,
unsigned int V_296 [] , struct V_297 * V_298 [] )
{
struct V_9 * V_10 = F_184 ( V_168 ) ;
struct V_114 * V_169 = NULL ;
unsigned int V_71 , V_299 = * V_294 ;
V_169 = F_71 ( V_10 , V_168 -> type ) ;
F_74 ( V_169 == NULL ) ;
V_71 = V_169 -> V_71 ;
if ( V_10 -> V_96 == V_102 )
V_299 = 1 ;
* V_294 = V_299 ;
* V_295 = 1 ;
V_296 [ 0 ] = V_71 ;
return 0 ;
}
static int F_185 ( struct V_63 * V_64 )
{
struct V_9 * V_10 = F_184 ( V_64 -> V_167 ) ;
struct V_114 * V_169 = NULL ;
V_169 = F_71 ( V_10 , V_64 -> V_167 -> type ) ;
F_74 ( V_169 == NULL ) ;
if ( F_186 ( V_64 , 0 ) < V_169 -> V_71 ) {
F_187 ( L_6 ,
V_220 , F_186 ( V_64 , 0 ) ,
( long ) V_169 -> V_71 ) ;
return - V_4 ;
}
F_188 ( V_64 , 0 , V_169 -> V_71 ) ;
return 0 ;
}
static void F_189 ( struct V_9 * V_10 )
{
struct V_114 * V_169 = & V_10 -> V_109 ;
V_169 -> V_134 = V_10 -> V_73 . V_134 ;
V_169 -> V_135 = V_10 -> V_73 . V_135 ;
F_75 ( V_10 , & V_169 -> V_134 , V_196 ,
V_197 , V_169 -> V_108 -> V_200 ,
& V_169 -> V_135 , V_198 ,
V_199 , V_169 -> V_108 -> V_201 ) ;
V_169 -> V_71 = V_169 -> V_134 * V_169 -> V_135 * V_169 -> V_108 -> V_179 >> 3 ;
}
static void F_190 ( struct V_63 * V_64 )
{
struct V_300 * V_301 = F_191 ( V_64 ) ;
struct V_9 * V_10 = F_184 ( V_64 -> V_167 ) ;
if ( V_10 -> V_96 == V_102 &&
V_64 -> V_167 -> type == V_164 ) {
static const struct V_302 V_303 = {
. type = V_227 ,
. V_304 . V_305 . V_306 = V_307 ,
} ;
struct V_167 * V_308 ;
T_1 V_309 ;
T_1 V_310 ;
V_308 = F_73 ( V_10 -> V_24 . V_65 ,
V_165 ) ;
V_309 = V_10 -> V_73 . V_134 ;
V_310 = V_10 -> V_73 . V_135 ;
V_10 -> V_173 = F_64 ( & V_10 -> V_73 ,
( unsigned long ) F_33 ( V_64 , 0 ) ,
F_192 ( ( unsigned long ) V_10 -> V_73 . V_71 ,
F_193 ( V_64 , 0 ) ) , V_10 ) ;
if ( ! V_10 -> V_173 ) {
F_194 ( V_64 , V_311 ) ;
return;
}
if ( V_10 -> V_73 . V_134 != V_309 || V_10 -> V_73 . V_135 != V_310 ) {
F_195 ( & V_10 -> V_24 , & V_303 ) ;
if ( F_196 ( V_308 ) )
V_10 -> V_292 = V_293 ;
else
F_189 ( V_10 ) ;
}
}
F_197 ( V_10 -> V_24 . V_65 , V_301 ) ;
}
static int F_198 ( struct V_167 * V_312 , unsigned int V_299 )
{
struct V_9 * V_10 = F_184 ( V_312 ) ;
int V_89 ;
V_89 = F_199 ( V_10 -> V_25 -> V_143 ) ;
return V_89 > 0 ? 0 : V_89 ;
}
static void F_200 ( struct V_167 * V_312 )
{
struct V_9 * V_10 = F_184 ( V_312 ) ;
if ( V_10 -> V_292 == V_293 &&
V_312 -> type == V_165 ) {
F_189 ( V_10 ) ;
V_10 -> V_292 = V_313 ;
}
F_201 ( V_10 -> V_25 -> V_143 ) ;
}
static int V_107 ( void * V_136 , struct V_167 * V_314 ,
struct V_167 * V_308 )
{
struct V_9 * V_10 = V_136 ;
int V_89 ;
V_314 -> type = V_164 ;
V_314 -> V_315 = V_316 | V_317 ;
V_314 -> V_318 = V_10 ;
V_314 -> V_319 = sizeof( struct V_320 ) ;
V_314 -> V_321 = & V_322 ;
V_314 -> V_323 = & V_324 ;
V_314 -> V_325 = V_326 ;
V_314 -> V_92 = & V_10 -> V_25 -> V_92 ;
V_314 -> V_143 = V_10 -> V_25 -> V_143 ;
V_89 = F_202 ( V_314 ) ;
if ( V_89 )
return V_89 ;
V_308 -> type = V_165 ;
V_308 -> V_315 = V_316 | V_317 ;
V_308 -> V_318 = V_10 ;
V_308 -> V_319 = sizeof( struct V_320 ) ;
V_308 -> V_321 = & V_322 ;
V_308 -> V_323 = & V_324 ;
V_308 -> V_325 = V_326 ;
V_308 -> V_92 = & V_10 -> V_25 -> V_92 ;
V_308 -> V_143 = V_10 -> V_25 -> V_143 ;
return F_202 ( V_308 ) ;
}
static T_3 F_203 ( int V_327 , void * V_328 )
{
struct V_62 * V_25 = V_328 ;
struct V_9 * V_329 ;
struct V_300 * V_262 , * V_263 ;
unsigned long V_330 = 0 ;
enum V_331 V_292 = V_332 ;
bool V_333 = false ;
bool V_334 = false ;
bool V_335 = false ;
F_204 ( & V_25 -> V_249 ) ;
V_329 = F_205 ( V_25 -> V_106 ) ;
V_262 = F_206 ( V_329 -> V_24 . V_65 ) ;
V_263 = F_207 ( V_329 -> V_24 . V_65 ) ;
if ( V_329 -> V_96 == V_97 )
V_333 = F_208 ( V_25 -> V_36 ) ;
V_334 = F_209 ( V_25 -> V_36 ) ;
V_335 = F_210 ( V_25 -> V_36 ) ;
if ( V_329 -> V_96 == V_102 )
V_335 = V_335 &&
F_211 ( V_25 -> V_36 ) ;
if ( V_333 ) {
V_292 = V_311 ;
F_212 ( V_25 -> V_36 ) ;
} else if ( V_334 ) {
V_292 = V_311 ;
F_213 ( V_25 -> V_36 ) ;
} else if ( ! V_335 ) {
V_292 = V_311 ;
} else {
V_330 = F_214 ( V_25 -> V_36 ) ;
}
V_263 -> V_336 = V_262 -> V_336 ;
V_263 -> V_337 . V_338 = V_262 -> V_337 . V_338 ;
V_263 -> V_153 &= ~ V_339 ;
V_263 -> V_153 |=
V_262 -> V_153 & V_339 ;
F_215 ( V_262 , V_292 ) ;
if ( V_329 -> V_96 == V_97 )
F_188 ( & V_263 -> V_337 , 0 , V_330 ) ;
F_215 ( V_263 , V_292 ) ;
V_329 -> V_12 = F_216 ( V_25 -> V_36 ) ;
F_217 ( & V_25 -> V_249 ) ;
F_218 ( V_25 -> V_36 ) ;
F_219 ( V_25 -> V_106 , V_329 -> V_24 . V_65 ) ;
return V_340 ;
}
static T_3 F_220 ( int V_327 , void * V_136 )
{
unsigned int V_341 ;
struct V_300 * V_342 , * V_343 ;
struct V_62 * V_25 = V_136 ;
struct V_9 * V_329 ;
unsigned long V_330 = 0 ;
F_204 ( & V_25 -> V_249 ) ;
F_150 ( V_25 -> V_36 , 0 ) ;
V_329 = F_205 ( V_25 -> V_106 ) ;
V_342 = F_206 ( V_329 -> V_24 . V_65 ) ;
V_343 = F_207 ( V_329 -> V_24 . V_65 ) ;
V_341 = F_221 ( V_25 -> V_36 ) ;
if ( V_341 ) {
switch ( V_341 & 0x1f ) {
case 0x1 :
V_25 -> V_344 = V_345 ;
break;
case 0x2 :
V_25 -> V_344 = V_346 ;
break;
case 0x4 :
V_25 -> V_344 = V_347 ;
break;
case 0x8 :
V_25 -> V_344 = V_348 ;
break;
case 0x10 :
V_25 -> V_344 = V_349 ;
break;
default:
V_25 -> V_344 = V_350 ;
break;
}
} else {
V_25 -> V_344 = V_350 ;
}
if ( V_25 -> V_344 == V_346 ) {
if ( V_329 -> V_96 == V_97 ) {
V_330 = F_222 ( V_25 -> V_36 ) ;
F_188 ( & V_343 -> V_337 ,
0 , V_330 ) ;
}
F_215 ( V_342 , V_332 ) ;
F_215 ( V_343 , V_332 ) ;
} else {
F_215 ( V_342 , V_311 ) ;
F_215 ( V_343 , V_311 ) ;
}
if ( V_25 -> V_26 -> V_27 == V_33 )
V_329 -> V_12 = F_223 ( V_25 -> V_36 ) ;
F_151 ( V_25 -> V_36 , V_351 ) ;
F_217 ( & V_25 -> V_249 ) ;
F_219 ( V_25 -> V_106 , V_329 -> V_24 . V_65 ) ;
return V_340 ;
}
static T_3 F_224 ( int V_327 , void * V_328 )
{
struct V_62 * V_25 = V_328 ;
struct V_9 * V_329 ;
struct V_300 * V_262 , * V_263 ;
unsigned long V_330 = 0 ;
enum V_331 V_292 = V_332 ;
bool V_352 = false ;
bool V_353 = false ;
T_1 V_291 ;
F_204 ( & V_25 -> V_249 ) ;
V_291 = F_225 ( V_25 -> V_36 ) ;
if ( V_291 & V_354 ) {
F_226 ( V_25 -> V_36 ) ;
V_352 = true ;
F_227 ( V_25 -> V_143 , L_7 ) ;
}
V_291 = F_228 ( V_25 -> V_36 ) ;
F_229 ( V_25 -> V_36 , V_291 ) ;
V_25 -> V_291 |= V_291 ;
if ( V_25 -> V_26 -> V_27 == V_30 &&
V_291 & V_355 ) {
V_353 = true ;
F_227 ( V_25 -> V_143 , L_8 ) ;
}
V_329 = F_205 ( V_25 -> V_106 ) ;
if ( ! V_329 )
goto V_356;
if ( ( V_291 & V_357 ) &&
( V_329 -> V_96 == V_102 ) ) {
F_230 ( V_25 -> V_36 ) ;
goto V_356;
}
if ( V_25 -> V_291 & ( V_358 |
V_359 |
V_360 |
V_361 ) )
V_330 = F_231 ( V_25 -> V_36 ) ;
else if ( V_352 || V_353 )
V_292 = V_311 ;
else
goto V_356;
V_262 = F_206 ( V_329 -> V_24 . V_65 ) ;
V_263 = F_207 ( V_329 -> V_24 . V_65 ) ;
V_263 -> V_336 = V_262 -> V_336 ;
V_263 -> V_337 . V_338 = V_262 -> V_337 . V_338 ;
F_215 ( V_262 , V_292 ) ;
if ( V_329 -> V_96 == V_97 )
F_188 ( & V_263 -> V_337 , 0 , V_330 ) ;
F_215 ( V_263 , V_292 ) ;
V_329 -> V_12 =
F_232 ( V_25 -> V_36 ) ;
F_217 ( & V_25 -> V_249 ) ;
F_219 ( V_25 -> V_106 , V_329 -> V_24 . V_65 ) ;
return V_340 ;
V_356:
F_217 ( & V_25 -> V_249 ) ;
return V_340 ;
}
static int F_233 ( struct V_362 * V_363 )
{
struct V_62 * V_25 ;
struct V_364 * V_365 ;
int V_2 , V_89 ;
V_25 = F_234 ( & V_363 -> V_143 , sizeof( struct V_62 ) , V_90 ) ;
if ( ! V_25 )
return - V_91 ;
V_25 -> V_26 = F_235 ( & V_363 -> V_143 ) ;
F_236 ( & V_25 -> V_92 ) ;
F_237 ( & V_25 -> V_249 ) ;
V_25 -> V_143 = & V_363 -> V_143 ;
V_365 = F_238 ( V_363 , V_366 , 0 ) ;
V_25 -> V_36 = F_239 ( & V_363 -> V_143 , V_365 ) ;
if ( F_52 ( V_25 -> V_36 ) )
return F_53 ( V_25 -> V_36 ) ;
V_25 -> V_327 = V_89 = F_240 ( V_363 , 0 ) ;
if ( V_89 < 0 ) {
F_227 ( & V_363 -> V_143 , L_9 ) ;
return V_89 ;
}
V_89 = F_241 ( & V_363 -> V_143 , V_25 -> V_327 , V_25 -> V_26 -> V_367 ,
0 , F_67 ( & V_363 -> V_143 ) , V_25 ) ;
if ( V_89 ) {
F_227 ( & V_363 -> V_143 , L_10 , V_25 -> V_327 ) ;
return V_89 ;
}
for ( V_2 = 0 ; V_2 < V_25 -> V_26 -> V_368 ; V_2 ++ ) {
V_25 -> V_369 [ V_2 ] = F_242 ( & V_363 -> V_143 ,
V_25 -> V_26 -> V_370 [ V_2 ] ) ;
if ( F_52 ( V_25 -> V_369 [ V_2 ] ) ) {
F_227 ( & V_363 -> V_143 , L_11 ,
V_25 -> V_26 -> V_370 [ V_2 ] ) ;
return F_53 ( V_25 -> V_369 [ V_2 ] ) ;
}
}
V_89 = F_243 ( & V_363 -> V_143 , & V_25 -> V_203 ) ;
if ( V_89 ) {
F_227 ( & V_363 -> V_143 , L_12 ) ;
return V_89 ;
}
V_25 -> V_106 = F_244 ( V_25 -> V_26 -> V_371 ) ;
if ( F_52 ( V_25 -> V_106 ) ) {
F_79 ( & V_25 -> V_203 , L_13 ) ;
V_89 = F_53 ( V_25 -> V_106 ) ;
goto V_372;
}
F_245 ( & V_363 -> V_143 , F_246 ( 32 ) ) ;
V_25 -> V_95 = F_247 () ;
if ( ! V_25 -> V_95 ) {
F_79 ( & V_25 -> V_203 , L_14 ) ;
V_89 = - V_91 ;
goto V_373;
}
snprintf ( V_25 -> V_95 -> V_156 , sizeof( V_25 -> V_95 -> V_156 ) ,
L_15 , V_140 ) ;
V_25 -> V_95 -> V_374 = & V_375 ;
V_25 -> V_95 -> V_376 = & V_377 ;
V_25 -> V_95 -> V_378 = - 1 ;
V_25 -> V_95 -> V_379 = V_380 ;
V_25 -> V_95 -> V_92 = & V_25 -> V_92 ;
V_25 -> V_95 -> V_203 = & V_25 -> V_203 ;
V_25 -> V_95 -> V_381 = V_382 ;
V_89 = F_248 ( V_25 -> V_95 , V_383 , - 1 ) ;
if ( V_89 ) {
F_79 ( & V_25 -> V_203 , L_16 ) ;
V_380 ( V_25 -> V_95 ) ;
goto V_373;
}
F_249 ( V_25 -> V_95 , V_25 ) ;
F_250 ( & V_25 -> V_203 ,
L_17 ,
V_25 -> V_95 -> V_152 ) ;
V_25 -> V_384 = F_247 () ;
if ( ! V_25 -> V_384 ) {
F_79 ( & V_25 -> V_203 , L_14 ) ;
V_89 = - V_91 ;
goto V_385;
}
snprintf ( V_25 -> V_384 -> V_156 , sizeof( V_25 -> V_384 -> V_156 ) ,
L_18 , V_140 ) ;
V_25 -> V_384 -> V_374 = & V_375 ;
V_25 -> V_384 -> V_376 = & V_377 ;
V_25 -> V_384 -> V_378 = - 1 ;
V_25 -> V_384 -> V_379 = V_380 ;
V_25 -> V_384 -> V_92 = & V_25 -> V_92 ;
V_25 -> V_384 -> V_203 = & V_25 -> V_203 ;
V_25 -> V_384 -> V_381 = V_382 ;
V_89 = F_248 ( V_25 -> V_384 , V_383 , - 1 ) ;
if ( V_89 ) {
F_79 ( & V_25 -> V_203 , L_16 ) ;
V_380 ( V_25 -> V_384 ) ;
goto V_385;
}
F_249 ( V_25 -> V_384 , V_25 ) ;
F_250 ( & V_25 -> V_203 ,
L_19 ,
V_25 -> V_384 -> V_152 ) ;
F_251 ( V_363 , V_25 ) ;
F_252 ( & V_363 -> V_143 ) ;
F_250 ( & V_25 -> V_203 , L_20 ) ;
return 0 ;
V_385:
F_253 ( V_25 -> V_95 ) ;
V_373:
F_254 ( V_25 -> V_106 ) ;
V_372:
F_255 ( & V_25 -> V_203 ) ;
return V_89 ;
}
static int F_256 ( struct V_362 * V_363 )
{
struct V_62 * V_25 = F_257 ( V_363 ) ;
int V_2 ;
F_258 ( V_25 -> V_143 ) ;
F_253 ( V_25 -> V_384 ) ;
F_253 ( V_25 -> V_95 ) ;
F_259 ( & V_363 -> V_143 ) ;
F_254 ( V_25 -> V_106 ) ;
F_255 ( & V_25 -> V_203 ) ;
if ( ! F_260 ( & V_363 -> V_143 ) ) {
for ( V_2 = V_25 -> V_26 -> V_368 - 1 ; V_2 >= 0 ; V_2 -- )
F_261 ( V_25 -> V_369 [ V_2 ] ) ;
}
return 0 ;
}
static int F_262 ( struct V_297 * V_143 )
{
struct V_62 * V_25 = F_263 ( V_143 ) ;
int V_2 ;
for ( V_2 = V_25 -> V_26 -> V_368 - 1 ; V_2 >= 0 ; V_2 -- )
F_261 ( V_25 -> V_369 [ V_2 ] ) ;
return 0 ;
}
static int F_264 ( struct V_297 * V_143 )
{
struct V_62 * V_25 = F_263 ( V_143 ) ;
unsigned long V_153 ;
int V_2 , V_89 ;
for ( V_2 = 0 ; V_2 < V_25 -> V_26 -> V_368 ; V_2 ++ ) {
V_89 = F_265 ( V_25 -> V_369 [ V_2 ] ) ;
if ( V_89 ) {
while ( -- V_2 > 0 )
F_261 ( V_25 -> V_369 [ V_2 ] ) ;
return V_89 ;
}
}
F_99 ( & V_25 -> V_249 , V_153 ) ;
if ( ! V_25 -> V_26 -> V_288 ) {
F_15 ( V_25 -> V_36 ) ;
F_17 ( V_25 -> V_36 ) ;
F_19 ( V_25 -> V_36 ) ;
F_21 ( V_25 -> V_36 ) ;
}
F_100 ( & V_25 -> V_249 , V_153 ) ;
return 0 ;
}
static void * F_235 ( struct V_297 * V_143 )
{
struct V_386 * V_387 = NULL ;
const struct V_388 * V_389 ;
if ( ! F_266 ( V_390 ) || ! V_143 -> V_391 )
return & V_392 ;
V_389 = F_267 ( V_393 , V_143 -> V_391 ) ;
if ( V_389 )
V_387 = (struct V_386 * ) V_389 -> V_72 ;
return V_387 ;
}
