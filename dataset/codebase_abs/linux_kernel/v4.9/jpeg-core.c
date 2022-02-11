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
F_8 ( V_10 -> V_12 > 3 ) ;
switch ( V_10 -> V_25 -> V_26 -> V_27 ) {
case V_28 :
if ( V_10 -> V_12 > 2 )
return V_13 ;
return V_10 -> V_12 ;
case V_29 :
case V_30 :
if ( V_10 -> V_12 > 3 )
return V_31 ;
return V_32 [ V_10 -> V_12 ] ;
case V_33 :
case V_34 :
if ( V_10 -> V_12 > 2 )
return V_15 ;
return V_35 [ V_10 -> V_12 ] ;
default:
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
static bool F_63 ( struct V_113 * V_114 ,
unsigned long V_115 , unsigned long V_71 ,
struct V_9 * V_10 )
{
int V_20 , V_70 = 0 , V_116 , V_117 = 0 , V_118 = 0 ;
unsigned int V_119 , V_120 , V_68 , V_12 = 0 , V_74 = 0 , V_81 = 0 ,
V_80 = 0 ;
unsigned int V_78 [ V_121 ] , V_122 [ V_121 ] ,
V_82 [ V_121 ] , V_123 [ V_121 ] ;
long V_124 ;
struct V_66 V_67 ;
V_67 . V_71 = V_71 ;
V_67 . V_72 = V_115 ;
V_67 . V_75 = 0 ;
V_116 = 1 ;
while ( V_116 || ! V_74 ) {
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
V_124 = 0 ;
switch ( V_20 ) {
case V_125 :
if ( F_34 ( & V_67 , & V_68 ) )
break;
V_124 = ( long ) V_68 - 2 ;
if ( ! V_124 )
return false ;
V_81 = V_67 . V_75 ;
V_80 = V_124 ;
if ( F_35 ( & V_67 ) == - 1 )
break;
if ( F_34 ( & V_67 , & V_119 ) )
break;
if ( F_34 ( & V_67 , & V_120 ) )
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
V_116 = 0 ;
break;
case V_126 :
if ( F_34 ( & V_67 , & V_68 ) )
break;
V_124 = ( long ) V_68 - 2 ;
if ( ! V_124 )
return false ;
if ( V_118 >= V_121 )
return false ;
V_82 [ V_118 ] = V_67 . V_75 ;
V_123 [ V_118 ++ ] = V_124 ;
F_39 ( & V_67 , V_124 ) ;
break;
case V_127 :
if ( F_34 ( & V_67 , & V_68 ) )
break;
V_124 = ( long ) V_68 - 2 ;
if ( ! V_124 )
return false ;
if ( V_117 >= V_121 )
return false ;
V_78 [ V_117 ] = V_67 . V_75 ;
V_122 [ V_117 ++ ] = V_124 ;
F_39 ( & V_67 , V_124 ) ;
break;
case V_128 :
V_74 = V_67 . V_75 - 2 ;
break;
case V_129 ... V_129 + 7 :
case V_130 :
case V_131 :
case V_132 :
break;
default:
if ( F_34 ( & V_67 , & V_68 ) )
break;
V_124 = ( long ) V_68 - 2 ;
F_39 ( & V_67 , V_124 ) ;
break;
}
}
V_114 -> V_133 = V_120 ;
V_114 -> V_134 = V_119 ;
V_114 -> V_74 = V_74 ;
V_114 -> V_78 . V_76 = V_117 ;
while ( V_117 -- ) {
V_114 -> V_78 . V_79 [ V_117 ] = V_78 [ V_117 ] ;
V_114 -> V_78 . V_39 [ V_117 ] = V_122 [ V_117 ] ;
}
V_114 -> V_82 . V_76 = V_118 ;
while ( V_118 -- ) {
V_114 -> V_82 . V_79 [ V_118 ] = V_82 [ V_118 ] ;
V_114 -> V_82 . V_39 [ V_118 ] = V_123 [ V_118 ] ;
}
V_114 -> V_81 = V_81 ;
V_114 -> V_80 = V_80 ;
V_114 -> V_71 = V_114 -> V_70 = V_70 ;
switch ( V_12 ) {
case 0x11 :
V_10 -> V_12 = V_135 ;
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
default:
return false ;
}
return ! V_116 && V_74 ;
}
static int F_64 ( struct V_83 * V_83 , void * V_136 ,
struct V_137 * V_138 )
{
struct V_9 * V_10 = F_6 ( V_136 ) ;
if ( V_10 -> V_96 == V_97 ) {
F_65 ( V_138 -> V_139 , V_140 ,
sizeof( V_138 -> V_139 ) ) ;
F_65 ( V_138 -> V_141 , V_140 L_1 ,
sizeof( V_138 -> V_141 ) ) ;
} else {
F_65 ( V_138 -> V_139 , V_140 ,
sizeof( V_138 -> V_139 ) ) ;
F_65 ( V_138 -> V_141 , V_140 L_2 ,
sizeof( V_138 -> V_141 ) ) ;
}
snprintf ( V_138 -> V_142 , sizeof( V_138 -> V_142 ) , L_3 ,
F_66 ( V_10 -> V_25 -> V_143 ) ) ;
V_138 -> V_144 = V_145 | V_146 ;
V_138 -> V_147 = V_138 -> V_144 | V_148 ;
return 0 ;
}
static int F_67 ( struct V_86 * V_149 , int V_76 ,
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
F_65 ( V_151 -> V_155 , V_149 [ V_2 ] . V_156 , sizeof( V_151 -> V_155 ) ) ;
V_151 -> V_157 = V_149 [ V_2 ] . V_1 ;
return 0 ;
}
static int F_68 ( struct V_83 * V_83 , void * V_136 ,
struct V_150 * V_151 )
{
struct V_9 * V_10 = F_6 ( V_136 ) ;
if ( V_10 -> V_96 == V_97 )
return F_67 ( V_149 , V_158 , V_151 ,
V_159 ) ;
return F_67 ( V_149 , V_158 , V_151 ,
V_160 ) ;
}
static int F_69 ( struct V_83 * V_83 , void * V_136 ,
struct V_150 * V_151 )
{
struct V_9 * V_10 = F_6 ( V_136 ) ;
if ( V_10 -> V_96 == V_97 )
return F_67 ( V_149 , V_158 , V_151 ,
V_161 ) ;
return F_67 ( V_149 , V_158 , V_151 ,
V_162 ) ;
}
static struct V_113 * F_70 ( struct V_9 * V_10 ,
enum V_163 type )
{
if ( type == V_164 )
return & V_10 -> V_73 ;
if ( type == V_165 )
return & V_10 -> V_109 ;
return NULL ;
}
static int F_71 ( struct V_83 * V_83 , void * V_136 , struct V_166 * V_151 )
{
struct V_167 * V_168 ;
struct V_113 * V_169 = NULL ;
struct V_170 * V_171 = & V_151 -> V_108 . V_171 ;
struct V_9 * V_172 = F_6 ( V_136 ) ;
V_168 = F_72 ( V_172 -> V_24 . V_65 , V_151 -> type ) ;
if ( ! V_168 )
return - V_4 ;
if ( V_151 -> type == V_165 &&
V_172 -> V_96 == V_102 && ! V_172 -> V_173 )
return - V_4 ;
V_169 = F_70 ( V_172 , V_151 -> type ) ;
F_73 ( V_169 == NULL ) ;
V_171 -> V_120 = V_169 -> V_133 ;
V_171 -> V_119 = V_169 -> V_134 ;
V_171 -> V_174 = V_175 ;
V_171 -> V_157 = V_169 -> V_108 -> V_1 ;
V_171 -> V_176 = 0 ;
if ( V_169 -> V_108 -> V_1 != V_100 ) {
T_1 V_177 = V_169 -> V_133 ;
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
static void F_74 ( struct V_9 * V_10 ,
T_1 * V_133 , unsigned int V_185 , unsigned int V_186 ,
unsigned int V_187 ,
T_1 * V_134 , unsigned int V_188 , unsigned int V_189 ,
unsigned int V_190 )
{
int V_120 , V_119 , V_191 , V_192 ;
V_120 = * V_133 ;
V_119 = * V_134 ;
V_191 = 1 << V_187 ;
V_192 = 1 << V_190 ;
if ( V_10 -> V_25 -> V_26 -> V_193 ) {
if ( V_191 == 4 && ( ( V_120 & 3 ) == 1 ) ) {
V_186 = V_120 ;
V_189 = V_119 ;
}
}
F_75 ( V_133 , V_185 , V_186 , V_187 , V_134 , V_188 , V_189 , V_190 , 0 ) ;
if ( * V_133 < V_120 && ( * V_133 + V_191 ) < V_186 )
* V_133 += V_191 ;
if ( * V_134 < V_119 && ( * V_134 + V_192 ) < V_189 )
* V_134 += V_192 ;
}
static int F_76 ( struct V_166 * V_151 , struct V_86 * V_108 ,
struct V_9 * V_10 , int V_194 )
{
struct V_170 * V_171 = & V_151 -> V_108 . V_171 ;
if ( V_171 -> V_174 == V_195 )
V_171 -> V_174 = V_175 ;
else if ( V_171 -> V_174 != V_175 )
return - V_4 ;
if ( V_194 == V_99 )
F_74 ( V_10 , & V_171 -> V_120 , V_196 ,
V_197 , 0 ,
& V_171 -> V_119 , V_198 ,
V_199 , 0 ) ;
else
F_74 ( V_10 , & V_171 -> V_120 , V_196 ,
V_197 , V_108 -> V_200 ,
& V_171 -> V_119 , V_198 ,
V_199 , V_108 -> V_201 ) ;
if ( V_108 -> V_1 == V_100 ) {
if ( V_171 -> V_180 <= 0 )
V_171 -> V_180 = V_202 ;
V_171 -> V_176 = 0 ;
} else {
T_1 V_177 = V_171 -> V_176 ;
if ( V_108 -> V_178 > 1 && V_177 < V_171 -> V_120 )
V_177 = V_171 -> V_120 ;
if ( V_108 -> V_178 == 1 &&
( V_177 << 3 ) / V_108 -> V_179 < V_171 -> V_120 )
V_177 = ( V_171 -> V_120 * V_108 -> V_179 ) >> 3 ;
V_171 -> V_176 = V_177 ;
V_171 -> V_180 = ( V_171 -> V_120 * V_171 -> V_119 * V_108 -> V_179 ) >> 3 ;
}
return 0 ;
}
static int F_77 ( struct V_83 * V_83 , void * V_136 ,
struct V_166 * V_151 )
{
struct V_9 * V_10 = F_6 ( V_136 ) ;
struct V_170 * V_171 = & V_151 -> V_108 . V_171 ;
struct V_86 * V_108 ;
int V_89 ;
V_108 = F_50 ( V_10 , V_151 -> V_108 . V_171 . V_157 ,
V_101 ) ;
if ( ! V_108 ) {
F_78 ( & V_10 -> V_25 -> V_203 ,
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
( V_10 -> V_73 . V_133 & 1 ) &&
( V_171 -> V_157 == V_206 ||
V_171 -> V_157 == V_207 ||
V_171 -> V_157 == V_208 ) ) {
V_171 -> V_157 = V_98 ;
V_108 = F_50 ( V_10 , V_171 -> V_157 ,
V_101 ) ;
}
exit:
return F_76 ( V_151 , V_108 , V_10 , V_101 ) ;
}
static int F_79 ( struct V_83 * V_83 , void * V_136 ,
struct V_166 * V_151 )
{
struct V_9 * V_10 = F_6 ( V_136 ) ;
struct V_86 * V_108 ;
V_108 = F_50 ( V_10 , V_151 -> V_108 . V_171 . V_157 ,
V_99 ) ;
if ( ! V_108 ) {
F_78 ( & V_10 -> V_25 -> V_203 ,
L_4 ,
V_151 -> V_108 . V_171 . V_157 ) ;
return - V_4 ;
}
return F_76 ( V_151 , V_108 , V_10 , V_99 ) ;
}
static int F_80 ( struct V_9 * V_10 ,
struct V_166 * V_151 ,
int V_209 )
{
struct V_170 * V_171 = & V_151 -> V_108 . V_171 ;
T_1 V_210 = V_151 -> V_108 . V_171 . V_157 ;
int V_133 = V_171 -> V_120 , V_134 = V_171 -> V_119 , V_211 ;
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
F_74 ( V_10 , & V_133 , V_196 ,
V_197 , V_211 ,
& V_134 , V_198 ,
V_199 , V_211 ) ;
if ( V_10 -> V_25 -> V_26 -> V_27 == V_33 )
V_212 = V_202 ;
return ( V_133 * V_134 * V_209 >> 3 ) + V_212 ;
}
static int F_81 ( struct V_9 * V_172 , struct V_166 * V_151 )
{
struct V_167 * V_168 ;
struct V_113 * V_169 = NULL ;
struct V_170 * V_171 = & V_151 -> V_108 . V_171 ;
struct V_19 * V_216 ;
struct V_217 V_218 ;
unsigned int V_219 ;
V_168 = F_72 ( V_172 -> V_24 . V_65 , V_151 -> type ) ;
if ( ! V_168 )
return - V_4 ;
V_169 = F_70 ( V_172 , V_151 -> type ) ;
F_73 ( V_169 == NULL ) ;
if ( F_82 ( V_168 ) ) {
F_78 ( & V_172 -> V_25 -> V_203 , L_5 , V_220 ) ;
return - V_221 ;
}
V_219 = F_83 ( V_151 -> type ) ?
V_99 : V_101 ;
V_169 -> V_108 = F_50 ( V_172 , V_171 -> V_157 , V_219 ) ;
V_169 -> V_133 = V_171 -> V_120 ;
V_169 -> V_134 = V_171 -> V_119 ;
if ( V_169 -> V_108 -> V_1 != V_100 ) {
if ( V_172 -> V_25 -> V_26 -> V_204 &&
V_219 == V_99 && V_172 -> V_96 == V_97 )
V_169 -> V_71 = F_80 ( V_172 ,
V_151 ,
V_169 -> V_108 -> V_179 ) ;
else
V_169 -> V_71 = V_169 -> V_133 * V_169 -> V_134 *
V_169 -> V_108 -> V_179 >> 3 ;
} else {
V_169 -> V_71 = V_171 -> V_180 ;
}
if ( V_219 == V_99 ) {
V_216 = F_84 ( & V_172 -> V_22 ,
V_222 ) ;
if ( V_216 )
F_85 ( V_216 , V_169 -> V_108 -> V_12 ) ;
V_172 -> V_223 = false ;
}
if ( ! V_172 -> V_223 &&
( ( V_172 -> V_96 == V_102 && V_219 == V_101 ) ||
( V_172 -> V_96 == V_97 && V_219 == V_99 ) ) ) {
V_172 -> V_224 . V_120 = V_171 -> V_120 ;
V_172 -> V_224 . V_119 = V_171 -> V_119 ;
}
if ( V_172 -> V_96 == V_102 &&
V_219 == V_101 &&
V_172 -> V_25 -> V_26 -> V_193 &&
V_171 -> V_157 == V_208 &&
V_172 -> V_104 > 2 ) {
V_218 . V_120 = V_172 -> V_73 . V_133 / 2 ;
V_218 . V_119 = V_172 -> V_73 . V_134 / 2 ;
F_86 ( V_172 , & V_218 ) ;
}
return 0 ;
}
static int F_87 ( struct V_83 * V_83 , void * V_136 ,
struct V_166 * V_151 )
{
int V_89 ;
V_89 = F_77 ( V_83 , V_136 , V_151 ) ;
if ( V_89 )
return V_89 ;
return F_81 ( F_6 ( V_136 ) , V_151 ) ;
}
static int F_88 ( struct V_83 * V_83 , void * V_136 ,
struct V_166 * V_151 )
{
int V_89 ;
V_89 = F_79 ( V_83 , V_136 , V_151 ) ;
if ( V_89 )
return V_89 ;
return F_81 ( F_6 ( V_136 ) , V_151 ) ;
}
static int F_86 ( struct V_9 * V_10 ,
struct V_217 * V_225 )
{
int V_226 , V_227 , V_104 , V_228 , V_2 ;
V_226 = V_10 -> V_73 . V_133 / V_225 -> V_120 ;
V_227 = V_10 -> V_73 . V_134 / V_225 -> V_119 ;
V_104 = V_226 > V_227 ? V_226 : V_227 ;
V_104 = F_89 ( V_104 , 1 , 8 ) ;
for ( V_2 = 0 ; V_2 <= 3 ; ++ V_2 ) {
V_228 = 1 << V_2 ;
if ( V_104 <= V_228 ) {
V_10 -> V_104 = V_228 ;
break;
}
}
V_225 -> V_120 = F_90 ( V_10 -> V_73 . V_133 / V_10 -> V_104 , 2 ) ;
V_225 -> V_119 = F_90 ( V_10 -> V_73 . V_134 / V_10 -> V_104 , 2 ) ;
V_10 -> V_224 . V_120 = V_225 -> V_120 ;
V_10 -> V_224 . V_119 = V_225 -> V_119 ;
V_10 -> V_224 . V_229 = 0 ;
V_10 -> V_224 . V_230 = 0 ;
V_10 -> V_223 = true ;
return 0 ;
}
static int F_91 ( struct V_217 * V_231 , struct V_217 * V_232 )
{
if ( V_231 -> V_229 < V_232 -> V_229 || V_231 -> V_230 < V_232 -> V_230 )
return 0 ;
if ( V_231 -> V_229 + V_231 -> V_120 > V_232 -> V_229 + V_232 -> V_120 )
return 0 ;
if ( V_231 -> V_230 + V_231 -> V_119 > V_232 -> V_230 + V_232 -> V_119 )
return 0 ;
return 1 ;
}
static int F_92 ( struct V_9 * V_10 ,
struct V_217 * V_225 )
{
struct V_217 V_233 ;
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
V_233 . V_230 = 0 ;
V_233 . V_229 = 0 ;
V_233 . V_120 = V_10 -> V_73 . V_133 ;
V_233 . V_119 = V_10 -> V_73 . V_134 ;
V_225 -> V_120 = F_90 ( V_225 -> V_120 , V_191 ) ;
V_225 -> V_119 = F_90 ( V_225 -> V_119 , V_192 ) ;
V_225 -> V_229 = F_90 ( V_225 -> V_229 , 2 ) ;
V_225 -> V_230 = F_90 ( V_225 -> V_230 , 2 ) ;
if ( ! F_91 ( V_225 , & V_233 ) )
return - V_4 ;
V_10 -> V_224 . V_229 = V_225 -> V_229 ;
V_10 -> V_224 . V_230 = V_225 -> V_230 ;
V_10 -> V_224 . V_120 = V_225 -> V_120 ;
V_10 -> V_224 . V_119 = V_225 -> V_119 ;
V_10 -> V_223 = true ;
return 0 ;
}
static int F_93 ( struct V_83 * V_83 , void * V_136 ,
struct V_234 * V_235 )
{
struct V_9 * V_10 = F_6 ( V_136 ) ;
if ( V_235 -> type != V_164 &&
V_235 -> type != V_165 )
return - V_4 ;
switch ( V_235 -> V_236 ) {
case V_237 :
case V_238 :
case V_239 :
case V_240 :
V_235 -> V_225 . V_120 = V_10 -> V_73 . V_133 ;
V_235 -> V_225 . V_119 = V_10 -> V_73 . V_134 ;
V_235 -> V_225 . V_229 = 0 ;
V_235 -> V_225 . V_230 = 0 ;
break;
case V_241 :
case V_242 :
case V_243 :
V_235 -> V_225 . V_120 = V_10 -> V_224 . V_120 ;
V_235 -> V_225 . V_119 = V_10 -> V_224 . V_119 ;
V_235 -> V_225 . V_229 = V_10 -> V_224 . V_229 ;
V_235 -> V_225 . V_230 = V_10 -> V_224 . V_230 ;
break;
default:
return - V_4 ;
}
return 0 ;
}
static int F_94 ( struct V_83 * V_83 , void * V_24 ,
struct V_234 * V_235 )
{
struct V_9 * V_10 = F_6 ( V_83 -> V_94 ) ;
struct V_217 * V_244 = & V_235 -> V_225 ;
int V_89 = - V_4 ;
if ( V_235 -> type != V_165 )
return - V_4 ;
if ( V_235 -> V_236 == V_241 ) {
if ( V_10 -> V_96 != V_102 )
return - V_4 ;
if ( V_10 -> V_25 -> V_26 -> V_193 )
V_89 = F_86 ( V_10 , V_244 ) ;
} else if ( V_235 -> V_236 == V_237 ) {
if ( V_10 -> V_96 != V_97 )
return - V_4 ;
if ( V_10 -> V_25 -> V_26 -> V_193 )
V_89 = F_92 ( V_10 , V_244 ) ;
}
return V_89 ;
}
static int F_95 ( struct V_19 * V_245 )
{
struct V_9 * V_10 = F_4 ( V_245 ) ;
struct V_62 * V_25 = V_10 -> V_25 ;
unsigned long V_153 ;
switch ( V_245 -> V_60 ) {
case V_222 :
F_96 ( & V_25 -> V_246 , V_153 ) ;
V_245 -> V_247 = F_7 ( V_10 ) ;
F_97 ( & V_25 -> V_246 , V_153 ) ;
break;
}
return 0 ;
}
static int F_98 ( struct V_9 * V_10 , int * V_248 )
{
switch ( V_10 -> V_25 -> V_26 -> V_27 ) {
case V_28 :
return 0 ;
case V_29 :
case V_30 :
if ( V_10 -> V_73 . V_108 -> V_1 == V_213 )
* V_248 = 0 ;
break;
case V_33 :
if ( V_10 -> V_73 . V_108 -> V_1 != V_14 &&
* V_248 == V_13 )
return - V_4 ;
break;
}
if ( V_10 -> V_73 . V_108 -> V_12 > * V_248 )
* V_248 = V_10 -> V_73 . V_108 -> V_12 ;
return 0 ;
}
static int F_99 ( struct V_19 * V_245 )
{
struct V_9 * V_10 = F_4 ( V_245 ) ;
unsigned long V_153 ;
int V_89 = 0 ;
F_96 ( & V_10 -> V_25 -> V_246 , V_153 ) ;
if ( V_245 -> V_60 == V_222 )
V_89 = F_98 ( V_10 , & V_245 -> V_247 ) ;
F_97 ( & V_10 -> V_25 -> V_246 , V_153 ) ;
return V_89 ;
}
static int F_100 ( struct V_19 * V_245 )
{
struct V_9 * V_10 = F_4 ( V_245 ) ;
unsigned long V_153 ;
F_96 ( & V_10 -> V_25 -> V_246 , V_153 ) ;
switch ( V_245 -> V_60 ) {
case V_249 :
V_10 -> V_250 = V_245 -> V_247 ;
break;
case V_251 :
V_10 -> V_252 = V_245 -> V_247 ;
break;
case V_222 :
V_10 -> V_12 = V_245 -> V_247 ;
break;
}
F_97 ( & V_10 -> V_25 -> V_246 , V_153 ) ;
return 0 ;
}
static int F_54 ( struct V_9 * V_10 )
{
unsigned int V_253 = ~ 0x27 ;
struct V_19 * V_245 ;
int V_89 ;
F_101 ( & V_10 -> V_22 , 3 ) ;
if ( V_10 -> V_96 == V_97 ) {
F_102 ( & V_10 -> V_22 , & V_254 ,
V_249 ,
0 , 3 , 1 , V_255 ) ;
F_102 ( & V_10 -> V_22 , & V_254 ,
V_251 ,
0 , 3 , 0xffff , 0 ) ;
if ( V_10 -> V_25 -> V_26 -> V_27 == V_28 )
V_253 = ~ 0x06 ;
}
V_245 = F_103 ( & V_10 -> V_22 , & V_254 ,
V_222 ,
V_13 , V_253 ,
V_17 ) ;
if ( V_10 -> V_22 . error ) {
V_89 = V_10 -> V_22 . error ;
goto V_256;
}
if ( V_10 -> V_96 == V_102 )
V_245 -> V_153 |= V_257 |
V_258 ;
V_89 = F_104 ( & V_10 -> V_22 ) ;
if ( V_89 < 0 )
goto V_256;
return V_89 ;
V_256:
F_62 ( & V_10 -> V_22 ) ;
return V_89 ;
}
static void F_105 ( void * V_136 )
{
struct V_9 * V_10 = V_136 ;
struct V_62 * V_25 = V_10 -> V_25 ;
struct V_63 * V_259 , * V_260 ;
unsigned long V_261 , V_262 , V_153 ;
F_96 ( & V_10 -> V_25 -> V_246 , V_153 ) ;
V_259 = F_32 ( V_10 -> V_24 . V_65 ) ;
V_260 = F_106 ( V_10 -> V_24 . V_65 ) ;
V_261 = F_107 ( V_259 , 0 ) ;
V_262 = F_107 ( V_260 , 0 ) ;
F_108 ( V_25 -> V_36 ) ;
F_109 ( V_25 -> V_36 ) ;
F_110 ( V_25 -> V_36 , V_10 -> V_96 ) ;
if ( V_10 -> V_96 == V_97 ) {
if ( V_10 -> V_73 . V_108 -> V_1 == V_98 )
F_111 ( V_25 -> V_36 ,
V_263 ) ;
else
F_111 ( V_25 -> V_36 ,
V_264 ) ;
F_112 ( V_25 -> V_36 , V_10 -> V_12 ) ;
F_113 ( V_25 -> V_36 , V_10 -> V_252 ) ;
F_114 ( V_25 -> V_36 , V_10 -> V_73 . V_133 ) ;
F_115 ( V_25 -> V_36 , V_10 -> V_73 . V_134 ) ;
F_116 ( V_25 -> V_36 , V_261 ) ;
F_117 ( V_25 -> V_36 , V_262 ) ;
F_118 ( V_25 -> V_36 , V_10 -> V_109 . V_71 ) ;
F_119 ( V_25 -> V_36 , 1 , 1 , V_265 ) ;
F_119 ( V_25 -> V_36 , 1 , 2 , V_266 ) ;
F_119 ( V_25 -> V_36 , 1 , 3 , V_267 ) ;
F_119 ( V_25 -> V_36 , 2 , 1 , V_268 ) ;
F_119 ( V_25 -> V_36 , 2 , 2 , V_269 ) ;
F_119 ( V_25 -> V_36 , 2 , 3 , V_270 ) ;
F_119 ( V_25 -> V_36 , 3 , 1 , V_271 ) ;
F_119 ( V_25 -> V_36 , 3 , 2 , V_272 ) ;
F_119 ( V_25 -> V_36 , 3 , 3 , V_273 ) ;
F_11 ( V_25 -> V_36 , V_10 -> V_250 ) ;
F_13 ( V_25 -> V_36 , V_10 -> V_250 ) ;
F_120 ( V_25 -> V_36 , 1 , 0 ) ;
F_120 ( V_25 -> V_36 , 2 , 1 ) ;
F_120 ( V_25 -> V_36 , 3 , 1 ) ;
F_121 ( V_25 -> V_36 , 1 ) ;
F_122 ( V_25 -> V_36 , 1 ) ;
F_121 ( V_25 -> V_36 , 2 ) ;
F_122 ( V_25 -> V_36 , 2 ) ;
F_121 ( V_25 -> V_36 , 3 ) ;
F_122 ( V_25 -> V_36 , 3 ) ;
} else {
F_123 ( V_25 -> V_36 , true ) ;
F_124 ( V_25 -> V_36 , true ) ;
F_125 ( V_25 -> V_36 , true ) ;
if ( V_10 -> V_109 . V_108 -> V_1 == V_103 )
F_126 ( V_25 -> V_36 , V_274 ) ;
else
F_126 ( V_25 -> V_36 , V_275 ) ;
F_117 ( V_25 -> V_36 , V_261 ) ;
F_116 ( V_25 -> V_36 , V_262 ) ;
}
F_127 ( V_25 -> V_36 ) ;
F_97 ( & V_10 -> V_25 -> V_246 , V_153 ) ;
}
static void F_128 ( struct V_9 * V_10 )
{
struct V_62 * V_25 = V_10 -> V_25 ;
struct V_86 * V_108 ;
struct V_63 * V_64 ;
struct V_276 V_277 = {} ;
T_1 V_278 , V_279 = 0 ;
V_277 . V_280 = 0 ;
V_277 . V_281 = 0 ;
V_278 = V_10 -> V_109 . V_133 * V_10 -> V_109 . V_134 ;
if ( V_10 -> V_96 == V_97 ) {
V_64 = F_32 ( V_10 -> V_24 . V_65 ) ;
V_108 = V_10 -> V_73 . V_108 ;
if ( V_10 -> V_73 . V_133 % 2 && V_108 -> V_200 > 0 )
V_279 = V_10 -> V_73 . V_134 ;
} else {
V_108 = V_10 -> V_109 . V_108 ;
V_64 = F_106 ( V_10 -> V_24 . V_65 ) ;
}
V_277 . V_282 = F_107 ( V_64 , 0 ) ;
if ( V_108 -> V_178 == 2 ) {
V_277 . V_280 = V_277 . V_282 + V_278 - V_279 ;
} else if ( V_108 -> V_178 == 3 ) {
V_277 . V_280 = V_277 . V_282 + V_278 ;
if ( V_108 -> V_1 == V_208 )
V_277 . V_281 = V_277 . V_280 + V_278 / 4 ;
else
V_277 . V_281 = V_277 . V_280 + V_278 / 2 ;
}
F_129 ( V_25 -> V_36 , & V_277 ) ;
}
static void F_130 ( struct V_9 * V_10 )
{
struct V_62 * V_25 = V_10 -> V_25 ;
struct V_63 * V_64 ;
unsigned int V_277 = 0 ;
if ( V_10 -> V_96 == V_97 )
V_64 = F_106 ( V_10 -> V_24 . V_65 ) ;
else
V_64 = F_32 ( V_10 -> V_24 . V_65 ) ;
V_277 = F_107 ( V_64 , 0 ) ;
if ( V_25 -> V_26 -> V_27 == V_34 &&
V_10 -> V_96 == V_102 )
V_277 += V_10 -> V_73 . V_74 ;
F_131 ( V_25 -> V_36 , V_277 ) ;
}
static inline void F_132 ( void T_2 * V_50 ,
unsigned int V_283 )
{
F_133 ( V_50 , V_283 , V_33 ) ;
}
static inline void F_134 ( void T_2 * V_50 ,
unsigned int V_283 )
{
F_133 ( V_50 , V_283 , V_34 ) ;
}
static inline void F_135 ( void T_2 * V_50 ,
unsigned int V_87 )
{
F_136 ( V_50 , V_87 , V_33 ) ;
}
static inline void F_137 ( void T_2 * V_50 ,
unsigned int V_87 )
{
F_136 ( V_50 , V_87 , V_34 ) ;
}
static void F_138 ( void * V_136 )
{
struct V_9 * V_10 = V_136 ;
struct V_62 * V_25 = V_10 -> V_25 ;
unsigned int V_284 ;
unsigned long V_153 ;
F_96 ( & V_25 -> V_246 , V_153 ) ;
if ( V_10 -> V_96 == V_97 ) {
F_139 ( V_25 -> V_36 ) ;
F_140 ( V_25 -> V_36 , V_25 -> V_26 -> V_27 ) ;
F_141 ( V_25 -> V_36 , 1 ) ;
F_27 ( V_25 -> V_36 ) ;
F_24 ( V_25 -> V_36 , V_10 -> V_250 ) ;
F_26 ( V_25 -> V_36 , V_10 -> V_250 ) ;
F_142 ( V_25 -> V_36 ,
V_10 -> V_250 ) ;
F_143 ( V_25 -> V_36 , V_10 -> V_109 . V_133 ,
V_10 -> V_109 . V_134 ) ;
if ( V_10 -> V_25 -> V_26 -> V_27 == V_33 ) {
F_135 ( V_25 -> V_36 ,
V_10 -> V_12 ) ;
F_132 ( V_25 -> V_36 ,
V_10 -> V_73 . V_108 -> V_1 ) ;
} else {
F_137 ( V_25 -> V_36 ,
V_10 -> V_12 ) ;
F_134 ( V_25 -> V_36 ,
V_10 -> V_73 . V_108 -> V_1 ) ;
}
F_128 ( V_10 ) ;
F_130 ( V_10 ) ;
F_144 ( V_25 -> V_36 ,
V_10 -> V_73 . V_108 -> V_1 ) ;
} else {
F_139 ( V_25 -> V_36 ) ;
F_140 ( V_25 -> V_36 ,
V_25 -> V_26 -> V_27 ) ;
F_128 ( V_10 ) ;
F_130 ( V_10 ) ;
if ( V_25 -> V_26 -> V_27 == V_34 ) {
F_37 ( V_10 ) ;
F_31 ( V_10 ) ;
F_42 ( V_10 ) ;
F_38 ( V_10 ) ;
F_141 ( V_25 -> V_36 , 1 ) ;
F_143 ( V_25 -> V_36 , V_10 -> V_109 . V_133 ,
V_10 -> V_109 . V_134 ) ;
F_137 ( V_25 -> V_36 ,
V_10 -> V_12 ) ;
F_134 ( V_25 -> V_36 ,
V_10 -> V_109 . V_108 -> V_1 ) ;
V_284 = F_145 ( V_10 -> V_73 . V_71 , 16 ) ;
} else {
F_132 ( V_25 -> V_36 ,
V_10 -> V_109 . V_108 -> V_1 ) ;
V_284 = F_145 ( V_10 -> V_73 . V_71 , 32 ) ;
}
F_146 ( V_25 -> V_36 , V_284 ) ;
}
F_147 ( V_25 -> V_36 , V_10 -> V_96 ) ;
F_97 ( & V_25 -> V_246 , V_153 ) ;
}
static void F_148 ( struct V_9 * V_10 )
{
struct V_62 * V_25 = V_10 -> V_25 ;
struct V_86 * V_108 ;
struct V_63 * V_64 ;
struct V_276 V_277 = {} ;
T_1 V_278 ;
V_278 = V_10 -> V_109 . V_133 * V_10 -> V_109 . V_134 ;
if ( V_10 -> V_96 == V_97 ) {
V_64 = F_32 ( V_10 -> V_24 . V_65 ) ;
V_108 = V_10 -> V_73 . V_108 ;
} else {
V_64 = F_106 ( V_10 -> V_24 . V_65 ) ;
V_108 = V_10 -> V_109 . V_108 ;
}
V_277 . V_282 = F_107 ( V_64 , 0 ) ;
if ( V_108 -> V_178 == 2 ) {
V_277 . V_280 = V_277 . V_282 + V_278 ;
} else if ( V_108 -> V_178 == 3 ) {
V_277 . V_280 = V_277 . V_282 + V_278 ;
if ( V_108 -> V_1 == V_208 )
V_277 . V_281 = V_277 . V_280 + V_278 / 4 ;
else
V_277 . V_281 = V_277 . V_280 + V_278 / 2 ;
}
F_149 ( V_25 -> V_36 , & V_277 ) ;
}
static void F_150 ( struct V_9 * V_10 )
{
struct V_62 * V_25 = V_10 -> V_25 ;
struct V_63 * V_64 ;
unsigned int V_277 = 0 ;
if ( V_10 -> V_96 == V_97 )
V_64 = F_106 ( V_10 -> V_24 . V_65 ) ;
else
V_64 = F_32 ( V_10 -> V_24 . V_65 ) ;
V_277 = F_107 ( V_64 , 0 ) ;
F_151 ( V_25 -> V_36 , V_277 ) ;
}
static void F_152 ( void * V_136 )
{
struct V_9 * V_10 = V_136 ;
struct V_62 * V_25 = V_10 -> V_25 ;
unsigned long V_153 ;
F_96 ( & V_10 -> V_25 -> V_246 , V_153 ) ;
F_153 ( V_25 -> V_36 ) ;
F_154 ( V_25 -> V_36 ) ;
F_155 ( V_25 -> V_36 ) ;
F_156 ( V_25 -> V_36 ) ;
F_157 ( V_25 -> V_36 , V_10 -> V_96 ) ;
if ( V_10 -> V_96 == V_97 ) {
F_158 ( V_25 -> V_36 ,
V_10 -> V_73 . V_108 -> V_1 ) ;
F_159 ( V_25 -> V_36 , V_10 -> V_252 ) ;
F_11 ( V_25 -> V_36 , V_10 -> V_250 ) ;
F_13 ( V_25 -> V_36 , V_10 -> V_250 ) ;
F_160 ( V_25 -> V_36 , 1 , 0 ) ;
F_160 ( V_25 -> V_36 , 2 , 1 ) ;
F_160 ( V_25 -> V_36 , 3 , 1 ) ;
if ( V_25 -> V_26 -> V_285 ) {
F_15 ( V_25 -> V_36 ) ;
F_17 ( V_25 -> V_36 ) ;
F_19 ( V_25 -> V_36 ) ;
F_21 ( V_25 -> V_36 ) ;
}
F_161 ( V_25 -> V_36 , 1 ) ;
F_162 ( V_25 -> V_36 , 1 ) ;
F_161 ( V_25 -> V_36 , 2 ) ;
F_162 ( V_25 -> V_36 , 2 ) ;
F_161 ( V_25 -> V_36 , 3 ) ;
F_162 ( V_25 -> V_36 , 3 ) ;
F_163 ( V_25 -> V_36 , V_10 -> V_224 . V_120 ) ;
F_164 ( V_25 -> V_36 , V_10 -> V_224 . V_119 ) ;
F_165 ( V_25 -> V_36 , V_10 -> V_73 . V_108 -> V_1 ,
V_10 -> V_73 . V_133 ) ;
F_166 ( V_25 -> V_36 , V_10 -> V_224 . V_229 ,
V_10 -> V_224 . V_230 ) ;
F_148 ( V_10 ) ;
F_150 ( V_10 ) ;
F_167 ( V_25 -> V_36 , V_10 -> V_12 ) ;
F_168 ( V_25 -> V_36 , V_10 -> V_109 . V_71 ) ;
if ( V_10 -> V_73 . V_108 -> V_1 == V_98 ||
V_10 -> V_73 . V_108 -> V_1 == V_286 ||
V_10 -> V_73 . V_108 -> V_1 == V_213 )
F_169 ( V_25 -> V_36 , true ) ;
} else {
F_148 ( V_10 ) ;
F_150 ( V_10 ) ;
F_165 ( V_25 -> V_36 , V_10 -> V_109 . V_108 -> V_1 ,
V_10 -> V_109 . V_133 ) ;
F_166 ( V_25 -> V_36 , 0 , 0 ) ;
F_170 ( V_25 -> V_36 ,
V_10 -> V_104 ) ;
F_171 ( V_25 -> V_36 , V_10 -> V_73 . V_71 ) ;
F_172 ( V_25 -> V_36 ,
V_10 -> V_109 . V_108 -> V_1 ) ;
}
F_173 ( V_25 -> V_36 ) ;
F_174 ( V_25 -> V_36 , V_10 -> V_96 ) ;
F_175 ( V_25 -> V_36 , V_287 ) ;
V_25 -> V_288 = 0 ;
F_176 ( V_25 -> V_36 ) ;
F_97 ( & V_10 -> V_25 -> V_246 , V_153 ) ;
}
static int F_177 ( void * V_136 )
{
struct V_9 * V_10 = V_136 ;
if ( V_10 -> V_96 == V_102 )
return V_10 -> V_173 ;
return 1 ;
}
static void F_178 ( void * V_136 )
{
}
static int F_179 ( struct V_167 * V_168 ,
unsigned int * V_289 , unsigned int * V_290 ,
unsigned int V_291 [] , struct V_292 * V_293 [] )
{
struct V_9 * V_10 = F_180 ( V_168 ) ;
struct V_113 * V_169 = NULL ;
unsigned int V_71 , V_294 = * V_289 ;
V_169 = F_70 ( V_10 , V_168 -> type ) ;
F_73 ( V_169 == NULL ) ;
V_71 = V_169 -> V_71 ;
if ( V_10 -> V_96 == V_102 )
V_294 = 1 ;
* V_289 = V_294 ;
* V_290 = 1 ;
V_291 [ 0 ] = V_71 ;
return 0 ;
}
static int F_181 ( struct V_63 * V_64 )
{
struct V_9 * V_10 = F_180 ( V_64 -> V_167 ) ;
struct V_113 * V_169 = NULL ;
V_169 = F_70 ( V_10 , V_64 -> V_167 -> type ) ;
F_73 ( V_169 == NULL ) ;
if ( F_182 ( V_64 , 0 ) < V_169 -> V_71 ) {
F_183 ( L_6 ,
V_220 , F_182 ( V_64 , 0 ) ,
( long ) V_169 -> V_71 ) ;
return - V_4 ;
}
F_184 ( V_64 , 0 , V_169 -> V_71 ) ;
return 0 ;
}
static void F_185 ( struct V_63 * V_64 )
{
struct V_295 * V_296 = F_186 ( V_64 ) ;
struct V_9 * V_10 = F_180 ( V_64 -> V_167 ) ;
if ( V_10 -> V_96 == V_102 &&
V_64 -> V_167 -> type == V_164 ) {
struct V_113 V_297 , * V_169 ;
V_10 -> V_173 = F_63 ( & V_297 ,
( unsigned long ) F_33 ( V_64 , 0 ) ,
F_187 ( ( unsigned long ) V_10 -> V_73 . V_71 ,
F_188 ( V_64 , 0 ) ) , V_10 ) ;
if ( ! V_10 -> V_173 ) {
F_189 ( V_64 , V_298 ) ;
return;
}
V_169 = & V_10 -> V_73 ;
V_169 -> V_133 = V_297 . V_133 ;
V_169 -> V_134 = V_297 . V_134 ;
V_169 -> V_74 = V_297 . V_74 ;
memcpy ( V_169 -> V_78 . V_79 , V_297 . V_78 . V_79 ,
sizeof( V_297 . V_78 . V_79 ) ) ;
memcpy ( V_169 -> V_78 . V_39 , V_297 . V_78 . V_39 , sizeof( V_297 . V_78 . V_39 ) ) ;
V_169 -> V_78 . V_76 = V_297 . V_78 . V_76 ;
memcpy ( V_169 -> V_82 . V_79 , V_297 . V_82 . V_79 ,
sizeof( V_297 . V_82 . V_79 ) ) ;
memcpy ( V_169 -> V_82 . V_39 , V_297 . V_82 . V_39 , sizeof( V_297 . V_82 . V_39 ) ) ;
V_169 -> V_82 . V_76 = V_297 . V_82 . V_76 ;
V_169 -> V_81 = V_297 . V_81 ;
V_169 -> V_80 = V_297 . V_80 ;
V_169 = & V_10 -> V_109 ;
V_169 -> V_133 = V_297 . V_133 ;
V_169 -> V_134 = V_297 . V_134 ;
}
F_190 ( V_10 -> V_24 . V_65 , V_296 ) ;
}
static int F_191 ( struct V_167 * V_299 , unsigned int V_294 )
{
struct V_9 * V_10 = F_180 ( V_299 ) ;
int V_89 ;
V_89 = F_192 ( V_10 -> V_25 -> V_143 ) ;
return V_89 > 0 ? 0 : V_89 ;
}
static void F_193 ( struct V_167 * V_299 )
{
struct V_9 * V_10 = F_180 ( V_299 ) ;
F_194 ( V_10 -> V_25 -> V_143 ) ;
}
static int V_107 ( void * V_136 , struct V_167 * V_300 ,
struct V_167 * V_301 )
{
struct V_9 * V_10 = V_136 ;
int V_89 ;
V_300 -> type = V_164 ;
V_300 -> V_302 = V_303 | V_304 ;
V_300 -> V_305 = V_10 ;
V_300 -> V_306 = sizeof( struct V_307 ) ;
V_300 -> V_308 = & V_309 ;
V_300 -> V_310 = & V_311 ;
V_300 -> V_312 = V_313 ;
V_300 -> V_92 = & V_10 -> V_25 -> V_92 ;
V_300 -> V_143 = V_10 -> V_25 -> V_143 ;
V_89 = F_195 ( V_300 ) ;
if ( V_89 )
return V_89 ;
V_301 -> type = V_165 ;
V_301 -> V_302 = V_303 | V_304 ;
V_301 -> V_305 = V_10 ;
V_301 -> V_306 = sizeof( struct V_307 ) ;
V_301 -> V_308 = & V_309 ;
V_301 -> V_310 = & V_311 ;
V_301 -> V_312 = V_313 ;
V_301 -> V_92 = & V_10 -> V_25 -> V_92 ;
V_301 -> V_143 = V_10 -> V_25 -> V_143 ;
return F_195 ( V_301 ) ;
}
static T_3 F_196 ( int V_314 , void * V_315 )
{
struct V_62 * V_25 = V_315 ;
struct V_9 * V_316 ;
struct V_295 * V_259 , * V_260 ;
unsigned long V_317 = 0 ;
enum V_318 V_319 = V_320 ;
bool V_321 = false ;
bool V_322 = false ;
bool V_323 = false ;
F_197 ( & V_25 -> V_246 ) ;
V_316 = F_198 ( V_25 -> V_106 ) ;
V_259 = F_199 ( V_316 -> V_24 . V_65 ) ;
V_260 = F_200 ( V_316 -> V_24 . V_65 ) ;
if ( V_316 -> V_96 == V_97 )
V_321 = F_201 ( V_25 -> V_36 ) ;
V_322 = F_202 ( V_25 -> V_36 ) ;
V_323 = F_203 ( V_25 -> V_36 ) ;
if ( V_316 -> V_96 == V_102 )
V_323 = V_323 &&
F_204 ( V_25 -> V_36 ) ;
if ( V_321 ) {
V_319 = V_298 ;
F_205 ( V_25 -> V_36 ) ;
} else if ( V_322 ) {
V_319 = V_298 ;
F_206 ( V_25 -> V_36 ) ;
} else if ( ! V_323 ) {
V_319 = V_298 ;
} else {
V_317 = F_207 ( V_25 -> V_36 ) ;
}
V_260 -> V_324 = V_259 -> V_324 ;
V_260 -> V_325 . V_326 = V_259 -> V_325 . V_326 ;
V_260 -> V_153 &= ~ V_327 ;
V_260 -> V_153 |=
V_259 -> V_153 & V_327 ;
F_208 ( V_259 , V_319 ) ;
if ( V_316 -> V_96 == V_97 )
F_184 ( & V_260 -> V_325 , 0 , V_317 ) ;
F_208 ( V_260 , V_319 ) ;
F_209 ( V_25 -> V_106 , V_316 -> V_24 . V_65 ) ;
V_316 -> V_12 = F_210 ( V_25 -> V_36 ) ;
F_211 ( & V_25 -> V_246 ) ;
F_212 ( V_25 -> V_36 ) ;
return V_328 ;
}
static T_3 F_213 ( int V_314 , void * V_136 )
{
unsigned int V_329 ;
struct V_295 * V_330 , * V_331 ;
struct V_62 * V_25 = V_136 ;
struct V_9 * V_316 ;
unsigned long V_317 = 0 ;
F_197 ( & V_25 -> V_246 ) ;
V_316 = F_198 ( V_25 -> V_106 ) ;
V_330 = F_199 ( V_316 -> V_24 . V_65 ) ;
V_331 = F_200 ( V_316 -> V_24 . V_65 ) ;
V_329 = F_214 ( V_25 -> V_36 ) ;
if ( V_329 ) {
switch ( V_329 & 0x1f ) {
case 0x1 :
V_25 -> V_332 = V_333 ;
break;
case 0x2 :
V_25 -> V_332 = V_334 ;
break;
case 0x4 :
V_25 -> V_332 = V_335 ;
break;
case 0x8 :
V_25 -> V_332 = V_336 ;
break;
case 0x10 :
V_25 -> V_332 = V_337 ;
break;
default:
V_25 -> V_332 = V_338 ;
break;
}
} else {
V_25 -> V_332 = V_338 ;
}
if ( V_25 -> V_332 == V_334 ) {
if ( V_316 -> V_96 == V_97 ) {
V_317 = F_215 ( V_25 -> V_36 ) ;
F_184 ( & V_331 -> V_325 ,
0 , V_317 ) ;
}
F_208 ( V_330 , V_320 ) ;
F_208 ( V_331 , V_320 ) ;
} else {
F_208 ( V_330 , V_298 ) ;
F_208 ( V_331 , V_298 ) ;
}
F_209 ( V_25 -> V_106 , V_316 -> V_24 . V_65 ) ;
if ( V_25 -> V_26 -> V_27 == V_33 )
V_316 -> V_12 = F_216 ( V_25 -> V_36 ) ;
F_211 ( & V_25 -> V_246 ) ;
return V_328 ;
}
static T_3 F_217 ( int V_314 , void * V_315 )
{
struct V_62 * V_25 = V_315 ;
struct V_9 * V_316 ;
struct V_295 * V_259 , * V_260 ;
unsigned long V_317 = 0 ;
enum V_318 V_319 = V_320 ;
bool V_339 = false ;
T_1 V_288 ;
F_197 ( & V_25 -> V_246 ) ;
V_288 = F_218 ( V_25 -> V_36 ) ;
if ( V_288 & V_340 ) {
F_219 ( V_25 -> V_36 ) ;
V_339 = true ;
F_220 ( V_25 -> V_143 , L_7 ) ;
}
V_288 = F_221 ( V_25 -> V_36 ) ;
F_222 ( V_25 -> V_36 , V_288 ) ;
V_25 -> V_288 |= V_288 ;
V_316 = F_198 ( V_25 -> V_106 ) ;
if ( ! V_316 )
goto V_341;
if ( ( V_288 & V_342 ) &&
( V_316 -> V_96 == V_102 ) ) {
F_223 ( V_25 -> V_36 ) ;
goto V_341;
}
if ( V_25 -> V_288 & ( V_343 |
V_344 |
V_345 |
V_346 ) )
V_317 = F_224 ( V_25 -> V_36 ) ;
else if ( V_339 )
V_319 = V_298 ;
else
goto V_341;
V_259 = F_199 ( V_316 -> V_24 . V_65 ) ;
V_260 = F_200 ( V_316 -> V_24 . V_65 ) ;
V_260 -> V_324 = V_259 -> V_324 ;
V_260 -> V_325 . V_326 = V_259 -> V_325 . V_326 ;
F_208 ( V_259 , V_319 ) ;
if ( V_316 -> V_96 == V_97 )
F_184 ( & V_260 -> V_325 , 0 , V_317 ) ;
F_208 ( V_260 , V_319 ) ;
F_209 ( V_25 -> V_106 , V_316 -> V_24 . V_65 ) ;
V_316 -> V_12 =
F_225 ( V_25 -> V_36 ) ;
V_341:
F_211 ( & V_25 -> V_246 ) ;
return V_328 ;
}
static int F_226 ( struct V_347 * V_348 )
{
struct V_62 * V_25 ;
struct V_349 * V_350 ;
int V_2 , V_89 ;
V_25 = F_227 ( & V_348 -> V_143 , sizeof( struct V_62 ) , V_90 ) ;
if ( ! V_25 )
return - V_91 ;
V_25 -> V_26 = F_228 ( & V_348 -> V_143 ) ;
F_229 ( & V_25 -> V_92 ) ;
F_230 ( & V_25 -> V_246 ) ;
V_25 -> V_143 = & V_348 -> V_143 ;
V_350 = F_231 ( V_348 , V_351 , 0 ) ;
V_25 -> V_36 = F_232 ( & V_348 -> V_143 , V_350 ) ;
if ( F_52 ( V_25 -> V_36 ) )
return F_53 ( V_25 -> V_36 ) ;
V_25 -> V_314 = V_89 = F_233 ( V_348 , 0 ) ;
if ( V_89 < 0 ) {
F_220 ( & V_348 -> V_143 , L_8 ) ;
return V_89 ;
}
V_89 = F_234 ( & V_348 -> V_143 , V_25 -> V_314 , V_25 -> V_26 -> V_352 ,
0 , F_66 ( & V_348 -> V_143 ) , V_25 ) ;
if ( V_89 ) {
F_220 ( & V_348 -> V_143 , L_9 , V_25 -> V_314 ) ;
return V_89 ;
}
for ( V_2 = 0 ; V_2 < V_25 -> V_26 -> V_353 ; V_2 ++ ) {
V_25 -> V_354 [ V_2 ] = F_235 ( & V_348 -> V_143 ,
V_25 -> V_26 -> V_355 [ V_2 ] ) ;
if ( F_52 ( V_25 -> V_354 [ V_2 ] ) ) {
F_220 ( & V_348 -> V_143 , L_10 ,
V_25 -> V_26 -> V_355 [ V_2 ] ) ;
return F_53 ( V_25 -> V_354 [ V_2 ] ) ;
}
}
V_89 = F_236 ( & V_348 -> V_143 , & V_25 -> V_203 ) ;
if ( V_89 ) {
F_220 ( & V_348 -> V_143 , L_11 ) ;
return V_89 ;
}
V_25 -> V_106 = F_237 ( V_25 -> V_26 -> V_356 ) ;
if ( F_52 ( V_25 -> V_106 ) ) {
F_78 ( & V_25 -> V_203 , L_12 ) ;
V_89 = F_53 ( V_25 -> V_106 ) ;
goto V_357;
}
F_238 ( & V_348 -> V_143 , F_239 ( 32 ) ) ;
V_25 -> V_95 = F_240 () ;
if ( ! V_25 -> V_95 ) {
F_78 ( & V_25 -> V_203 , L_13 ) ;
V_89 = - V_91 ;
goto V_358;
}
snprintf ( V_25 -> V_95 -> V_156 , sizeof( V_25 -> V_95 -> V_156 ) ,
L_14 , V_140 ) ;
V_25 -> V_95 -> V_359 = & V_360 ;
V_25 -> V_95 -> V_361 = & V_362 ;
V_25 -> V_95 -> V_363 = - 1 ;
V_25 -> V_95 -> V_364 = V_365 ;
V_25 -> V_95 -> V_92 = & V_25 -> V_92 ;
V_25 -> V_95 -> V_203 = & V_25 -> V_203 ;
V_25 -> V_95 -> V_366 = V_367 ;
V_89 = F_241 ( V_25 -> V_95 , V_368 , - 1 ) ;
if ( V_89 ) {
F_78 ( & V_25 -> V_203 , L_15 ) ;
V_365 ( V_25 -> V_95 ) ;
goto V_358;
}
F_242 ( V_25 -> V_95 , V_25 ) ;
F_243 ( & V_25 -> V_203 ,
L_16 ,
V_25 -> V_95 -> V_152 ) ;
V_25 -> V_369 = F_240 () ;
if ( ! V_25 -> V_369 ) {
F_78 ( & V_25 -> V_203 , L_13 ) ;
V_89 = - V_91 ;
goto V_370;
}
snprintf ( V_25 -> V_369 -> V_156 , sizeof( V_25 -> V_369 -> V_156 ) ,
L_17 , V_140 ) ;
V_25 -> V_369 -> V_359 = & V_360 ;
V_25 -> V_369 -> V_361 = & V_362 ;
V_25 -> V_369 -> V_363 = - 1 ;
V_25 -> V_369 -> V_364 = V_365 ;
V_25 -> V_369 -> V_92 = & V_25 -> V_92 ;
V_25 -> V_369 -> V_203 = & V_25 -> V_203 ;
V_25 -> V_369 -> V_366 = V_367 ;
V_89 = F_241 ( V_25 -> V_369 , V_368 , - 1 ) ;
if ( V_89 ) {
F_78 ( & V_25 -> V_203 , L_15 ) ;
V_365 ( V_25 -> V_369 ) ;
goto V_370;
}
F_242 ( V_25 -> V_369 , V_25 ) ;
F_243 ( & V_25 -> V_203 ,
L_18 ,
V_25 -> V_369 -> V_152 ) ;
F_244 ( V_348 , V_25 ) ;
F_245 ( & V_348 -> V_143 ) ;
F_243 ( & V_25 -> V_203 , L_19 ) ;
return 0 ;
V_370:
F_246 ( V_25 -> V_95 ) ;
V_358:
F_247 ( V_25 -> V_106 ) ;
V_357:
F_248 ( & V_25 -> V_203 ) ;
return V_89 ;
}
static int F_249 ( struct V_347 * V_348 )
{
struct V_62 * V_25 = F_250 ( V_348 ) ;
int V_2 ;
F_251 ( V_25 -> V_143 ) ;
F_246 ( V_25 -> V_369 ) ;
F_246 ( V_25 -> V_95 ) ;
F_252 ( & V_348 -> V_143 ) ;
F_247 ( V_25 -> V_106 ) ;
F_248 ( & V_25 -> V_203 ) ;
if ( ! F_253 ( & V_348 -> V_143 ) ) {
for ( V_2 = V_25 -> V_26 -> V_353 - 1 ; V_2 >= 0 ; V_2 -- )
F_254 ( V_25 -> V_354 [ V_2 ] ) ;
}
return 0 ;
}
static int F_255 ( struct V_292 * V_143 )
{
struct V_62 * V_25 = F_256 ( V_143 ) ;
int V_2 ;
for ( V_2 = V_25 -> V_26 -> V_353 - 1 ; V_2 >= 0 ; V_2 -- )
F_254 ( V_25 -> V_354 [ V_2 ] ) ;
return 0 ;
}
static int F_257 ( struct V_292 * V_143 )
{
struct V_62 * V_25 = F_256 ( V_143 ) ;
unsigned long V_153 ;
int V_2 , V_89 ;
for ( V_2 = 0 ; V_2 < V_25 -> V_26 -> V_353 ; V_2 ++ ) {
V_89 = F_258 ( V_25 -> V_354 [ V_2 ] ) ;
if ( V_89 ) {
while ( -- V_2 > 0 )
F_254 ( V_25 -> V_354 [ V_2 ] ) ;
return V_89 ;
}
}
F_96 ( & V_25 -> V_246 , V_153 ) ;
if ( ! V_25 -> V_26 -> V_285 ) {
F_15 ( V_25 -> V_36 ) ;
F_17 ( V_25 -> V_36 ) ;
F_19 ( V_25 -> V_36 ) ;
F_21 ( V_25 -> V_36 ) ;
}
F_97 ( & V_25 -> V_246 , V_153 ) ;
return 0 ;
}
static void * F_228 ( struct V_292 * V_143 )
{
struct V_371 * V_372 = NULL ;
const struct V_373 * V_374 ;
if ( ! F_259 ( V_375 ) || ! V_143 -> V_376 )
return & V_377 ;
V_374 = F_260 ( V_378 , V_143 -> V_376 ) ;
if ( V_374 )
V_372 = (struct V_371 * ) V_374 -> V_72 ;
return V_372 ;
}
