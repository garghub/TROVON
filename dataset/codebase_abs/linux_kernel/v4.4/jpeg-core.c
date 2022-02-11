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
F_65 ( V_138 -> V_139 , V_140 L_1 ,
sizeof( V_138 -> V_139 ) ) ;
F_65 ( V_138 -> V_141 , V_140 L_1 ,
sizeof( V_138 -> V_141 ) ) ;
} else {
F_65 ( V_138 -> V_139 , V_140 L_2 ,
sizeof( V_138 -> V_139 ) ) ;
F_65 ( V_138 -> V_141 , V_140 L_2 ,
sizeof( V_138 -> V_141 ) ) ;
}
V_138 -> V_142 [ 0 ] = 0 ;
V_138 -> V_143 = V_144 | V_145 ;
V_138 -> V_146 = V_138 -> V_143 | V_147 ;
return 0 ;
}
static int F_66 ( struct V_86 * V_148 , int V_76 ,
struct V_149 * V_150 , T_1 type )
{
int V_2 , V_151 = 0 ;
for ( V_2 = 0 ; V_2 < V_76 ; ++ V_2 ) {
if ( V_148 [ V_2 ] . V_152 & type ) {
if ( V_151 == V_150 -> V_153 )
break;
++ V_151 ;
}
}
if ( V_2 >= V_76 )
return - V_4 ;
F_65 ( V_150 -> V_154 , V_148 [ V_2 ] . V_155 , sizeof( V_150 -> V_154 ) ) ;
V_150 -> V_156 = V_148 [ V_2 ] . V_1 ;
return 0 ;
}
static int F_67 ( struct V_83 * V_83 , void * V_136 ,
struct V_149 * V_150 )
{
struct V_9 * V_10 = F_6 ( V_136 ) ;
if ( V_10 -> V_96 == V_97 )
return F_66 ( V_148 , V_157 , V_150 ,
V_158 ) ;
return F_66 ( V_148 , V_157 , V_150 ,
V_159 ) ;
}
static int F_68 ( struct V_83 * V_83 , void * V_136 ,
struct V_149 * V_150 )
{
struct V_9 * V_10 = F_6 ( V_136 ) ;
if ( V_10 -> V_96 == V_97 )
return F_66 ( V_148 , V_157 , V_150 ,
V_160 ) ;
return F_66 ( V_148 , V_157 , V_150 ,
V_161 ) ;
}
static struct V_113 * F_69 ( struct V_9 * V_10 ,
enum V_162 type )
{
if ( type == V_163 )
return & V_10 -> V_73 ;
if ( type == V_164 )
return & V_10 -> V_109 ;
return NULL ;
}
static int F_70 ( struct V_83 * V_83 , void * V_136 , struct V_165 * V_150 )
{
struct V_166 * V_167 ;
struct V_113 * V_168 = NULL ;
struct V_169 * V_170 = & V_150 -> V_108 . V_170 ;
struct V_9 * V_171 = F_6 ( V_136 ) ;
V_167 = F_71 ( V_171 -> V_24 . V_65 , V_150 -> type ) ;
if ( ! V_167 )
return - V_4 ;
if ( V_150 -> type == V_164 &&
V_171 -> V_96 == V_102 && ! V_171 -> V_172 )
return - V_4 ;
V_168 = F_69 ( V_171 , V_150 -> type ) ;
F_72 ( V_168 == NULL ) ;
V_170 -> V_120 = V_168 -> V_133 ;
V_170 -> V_119 = V_168 -> V_134 ;
V_170 -> V_173 = V_174 ;
V_170 -> V_156 = V_168 -> V_108 -> V_1 ;
V_170 -> V_175 = 0 ;
if ( V_168 -> V_108 -> V_1 != V_100 ) {
T_1 V_176 = V_168 -> V_133 ;
if ( V_168 -> V_108 -> V_177 == 1 )
V_176 = ( V_176 * V_168 -> V_108 -> V_178 ) >> 3 ;
V_170 -> V_175 = V_176 ;
}
V_170 -> V_179 = V_168 -> V_71 ;
return 0 ;
}
static struct V_86 * F_50 ( struct V_9 * V_10 ,
T_1 V_156 , unsigned int V_180 )
{
unsigned int V_181 , V_182 ;
if ( V_10 -> V_96 == V_97 )
V_182 = ( V_180 == V_99 ) ?
V_160 :
V_158 ;
else
V_182 = ( V_180 == V_99 ) ?
V_161 :
V_159 ;
for ( V_181 = 0 ; V_181 < F_2 ( V_148 ) ; V_181 ++ ) {
struct V_86 * V_108 = & V_148 [ V_181 ] ;
if ( V_108 -> V_1 == V_156 &&
V_108 -> V_152 & V_182 &&
V_108 -> V_152 & V_10 -> V_25 -> V_26 -> V_183 ) {
return V_108 ;
}
}
return NULL ;
}
static void F_73 ( struct V_9 * V_10 ,
T_1 * V_133 , unsigned int V_184 , unsigned int V_185 ,
unsigned int V_186 ,
T_1 * V_134 , unsigned int V_187 , unsigned int V_188 ,
unsigned int V_189 )
{
int V_120 , V_119 , V_190 , V_191 ;
V_120 = * V_133 ;
V_119 = * V_134 ;
V_190 = 1 << V_186 ;
V_191 = 1 << V_189 ;
if ( V_10 -> V_25 -> V_26 -> V_192 ) {
if ( V_190 == 4 && ( ( V_120 & 3 ) == 1 ) ) {
V_185 = V_120 ;
V_188 = V_119 ;
}
}
F_74 ( V_133 , V_184 , V_185 , V_186 , V_134 , V_187 , V_188 , V_189 , 0 ) ;
if ( * V_133 < V_120 && ( * V_133 + V_190 ) < V_185 )
* V_133 += V_190 ;
if ( * V_134 < V_119 && ( * V_134 + V_191 ) < V_188 )
* V_134 += V_191 ;
}
static int F_75 ( struct V_165 * V_150 , struct V_86 * V_108 ,
struct V_9 * V_10 , int V_193 )
{
struct V_169 * V_170 = & V_150 -> V_108 . V_170 ;
if ( V_170 -> V_173 == V_194 )
V_170 -> V_173 = V_174 ;
else if ( V_170 -> V_173 != V_174 )
return - V_4 ;
if ( V_193 == V_99 )
F_73 ( V_10 , & V_170 -> V_120 , V_195 ,
V_196 , 0 ,
& V_170 -> V_119 , V_197 ,
V_198 , 0 ) ;
else
F_73 ( V_10 , & V_170 -> V_120 , V_195 ,
V_196 , V_108 -> V_199 ,
& V_170 -> V_119 , V_197 ,
V_198 , V_108 -> V_200 ) ;
if ( V_108 -> V_1 == V_100 ) {
if ( V_170 -> V_179 <= 0 )
V_170 -> V_179 = V_201 ;
V_170 -> V_175 = 0 ;
} else {
T_1 V_176 = V_170 -> V_175 ;
if ( V_108 -> V_177 > 1 && V_176 < V_170 -> V_120 )
V_176 = V_170 -> V_120 ;
if ( V_108 -> V_177 == 1 &&
( V_176 << 3 ) / V_108 -> V_178 < V_170 -> V_120 )
V_176 = ( V_170 -> V_120 * V_108 -> V_178 ) >> 3 ;
V_170 -> V_175 = V_176 ;
V_170 -> V_179 = ( V_170 -> V_120 * V_170 -> V_119 * V_108 -> V_178 ) >> 3 ;
}
return 0 ;
}
static int F_76 ( struct V_83 * V_83 , void * V_136 ,
struct V_165 * V_150 )
{
struct V_9 * V_10 = F_6 ( V_136 ) ;
struct V_169 * V_170 = & V_150 -> V_108 . V_170 ;
struct V_86 * V_108 ;
int V_89 ;
V_108 = F_50 ( V_10 , V_150 -> V_108 . V_170 . V_156 ,
V_101 ) ;
if ( ! V_108 ) {
F_77 ( & V_10 -> V_25 -> V_202 ,
L_3 ,
V_150 -> V_108 . V_170 . V_156 ) ;
return - V_4 ;
}
if ( ! V_10 -> V_25 -> V_26 -> V_203 || V_10 -> V_96 != V_102 )
goto exit;
if ( ( V_108 -> V_152 & V_204 ) &&
( V_108 -> V_12 < V_10 -> V_12 ) ) {
V_89 = F_3 ( V_10 -> V_12 ,
V_108 -> V_1 ,
& V_170 -> V_156 ,
V_10 ) ;
if ( V_89 < 0 )
V_170 -> V_156 = V_14 ;
V_108 = F_50 ( V_10 , V_170 -> V_156 ,
V_101 ) ;
}
if ( V_10 -> V_12 == V_15 &&
( V_10 -> V_73 . V_133 & 1 ) &&
( V_170 -> V_156 == V_205 ||
V_170 -> V_156 == V_206 ||
V_170 -> V_156 == V_207 ) ) {
V_170 -> V_156 = V_98 ;
V_108 = F_50 ( V_10 , V_170 -> V_156 ,
V_101 ) ;
}
exit:
return F_75 ( V_150 , V_108 , V_10 , V_101 ) ;
}
static int F_78 ( struct V_83 * V_83 , void * V_136 ,
struct V_165 * V_150 )
{
struct V_9 * V_10 = F_6 ( V_136 ) ;
struct V_86 * V_108 ;
V_108 = F_50 ( V_10 , V_150 -> V_108 . V_170 . V_156 ,
V_99 ) ;
if ( ! V_108 ) {
F_77 ( & V_10 -> V_25 -> V_202 ,
L_3 ,
V_150 -> V_108 . V_170 . V_156 ) ;
return - V_4 ;
}
return F_75 ( V_150 , V_108 , V_10 , V_99 ) ;
}
static int F_79 ( struct V_9 * V_10 ,
struct V_165 * V_150 ,
int V_208 )
{
struct V_169 * V_170 = & V_150 -> V_108 . V_170 ;
T_1 V_209 = V_150 -> V_108 . V_170 . V_156 ;
int V_133 = V_170 -> V_120 , V_134 = V_170 -> V_119 , V_210 ;
if ( V_209 == V_211 ||
V_209 == V_212 ||
V_209 == V_213 ||
V_209 == V_205 ||
V_209 == V_206 ||
V_209 == V_207 )
V_210 = 4 ;
else
V_210 = 1 ;
F_73 ( V_10 , & V_133 , V_195 ,
V_196 , V_210 ,
& V_134 , V_197 ,
V_198 , V_210 ) ;
return V_133 * V_134 * V_208 >> 3 ;
}
static int F_80 ( struct V_9 * V_171 , struct V_165 * V_150 )
{
struct V_166 * V_167 ;
struct V_113 * V_168 = NULL ;
struct V_169 * V_170 = & V_150 -> V_108 . V_170 ;
struct V_19 * V_214 ;
struct V_215 V_216 ;
unsigned int V_217 ;
V_167 = F_71 ( V_171 -> V_24 . V_65 , V_150 -> type ) ;
if ( ! V_167 )
return - V_4 ;
V_168 = F_69 ( V_171 , V_150 -> type ) ;
F_72 ( V_168 == NULL ) ;
if ( F_81 ( V_167 ) ) {
F_77 ( & V_171 -> V_25 -> V_202 , L_4 , V_218 ) ;
return - V_219 ;
}
V_217 = F_82 ( V_150 -> type ) ?
V_99 : V_101 ;
V_168 -> V_108 = F_50 ( V_171 , V_170 -> V_156 , V_217 ) ;
V_168 -> V_133 = V_170 -> V_120 ;
V_168 -> V_134 = V_170 -> V_119 ;
if ( V_168 -> V_108 -> V_1 != V_100 ) {
if ( V_171 -> V_25 -> V_26 -> V_203 &&
V_217 == V_99 && V_171 -> V_96 == V_97 )
V_168 -> V_71 = F_79 ( V_171 ,
V_150 ,
V_168 -> V_108 -> V_178 ) ;
else
V_168 -> V_71 = V_168 -> V_133 * V_168 -> V_134 *
V_168 -> V_108 -> V_178 >> 3 ;
} else {
V_168 -> V_71 = V_170 -> V_179 ;
}
if ( V_217 == V_99 ) {
V_214 = F_83 ( & V_171 -> V_22 ,
V_220 ) ;
if ( V_214 )
F_84 ( V_214 , V_168 -> V_108 -> V_12 ) ;
V_171 -> V_221 = false ;
}
if ( ! V_171 -> V_221 &&
( ( V_171 -> V_96 == V_102 && V_217 == V_101 ) ||
( V_171 -> V_96 == V_97 && V_217 == V_99 ) ) ) {
V_171 -> V_222 . V_120 = V_170 -> V_120 ;
V_171 -> V_222 . V_119 = V_170 -> V_119 ;
}
if ( V_171 -> V_96 == V_102 &&
V_217 == V_101 &&
V_171 -> V_25 -> V_26 -> V_192 &&
V_170 -> V_156 == V_207 &&
V_171 -> V_104 > 2 ) {
V_216 . V_120 = V_171 -> V_73 . V_133 / 2 ;
V_216 . V_119 = V_171 -> V_73 . V_134 / 2 ;
F_85 ( V_171 , & V_216 ) ;
}
return 0 ;
}
static int F_86 ( struct V_83 * V_83 , void * V_136 ,
struct V_165 * V_150 )
{
int V_89 ;
V_89 = F_76 ( V_83 , V_136 , V_150 ) ;
if ( V_89 )
return V_89 ;
return F_80 ( F_6 ( V_136 ) , V_150 ) ;
}
static int F_87 ( struct V_83 * V_83 , void * V_136 ,
struct V_165 * V_150 )
{
int V_89 ;
V_89 = F_78 ( V_83 , V_136 , V_150 ) ;
if ( V_89 )
return V_89 ;
return F_80 ( F_6 ( V_136 ) , V_150 ) ;
}
static int F_85 ( struct V_9 * V_10 ,
struct V_215 * V_223 )
{
int V_224 , V_225 , V_104 , V_226 , V_2 ;
V_224 = V_10 -> V_73 . V_133 / V_223 -> V_120 ;
V_225 = V_10 -> V_73 . V_134 / V_223 -> V_119 ;
V_104 = V_224 > V_225 ? V_224 : V_225 ;
V_104 = F_88 ( V_104 , 1 , 8 ) ;
for ( V_2 = 0 ; V_2 <= 3 ; ++ V_2 ) {
V_226 = 1 << V_2 ;
if ( V_104 <= V_226 ) {
V_10 -> V_104 = V_226 ;
break;
}
}
V_223 -> V_120 = F_89 ( V_10 -> V_73 . V_133 / V_10 -> V_104 , 2 ) ;
V_223 -> V_119 = F_89 ( V_10 -> V_73 . V_134 / V_10 -> V_104 , 2 ) ;
V_10 -> V_222 . V_120 = V_223 -> V_120 ;
V_10 -> V_222 . V_119 = V_223 -> V_119 ;
V_10 -> V_222 . V_227 = 0 ;
V_10 -> V_222 . V_228 = 0 ;
V_10 -> V_221 = true ;
return 0 ;
}
static int F_90 ( struct V_215 * V_229 , struct V_215 * V_230 )
{
if ( V_229 -> V_227 < V_230 -> V_227 || V_229 -> V_228 < V_230 -> V_228 )
return 0 ;
if ( V_229 -> V_227 + V_229 -> V_120 > V_230 -> V_227 + V_230 -> V_120 )
return 0 ;
if ( V_229 -> V_228 + V_229 -> V_119 > V_230 -> V_228 + V_230 -> V_119 )
return 0 ;
return 1 ;
}
static int F_91 ( struct V_9 * V_10 ,
struct V_215 * V_223 )
{
struct V_215 V_231 ;
int V_190 , V_191 ;
switch ( V_10 -> V_109 . V_108 -> V_1 ) {
case V_205 :
case V_206 :
V_190 = 1 ;
V_191 = 2 ;
break;
case V_207 :
V_190 = 2 ;
V_191 = 2 ;
break;
default:
V_190 = 1 ;
V_191 = 1 ;
break;
}
V_231 . V_228 = 0 ;
V_231 . V_227 = 0 ;
V_231 . V_120 = V_10 -> V_73 . V_133 ;
V_231 . V_119 = V_10 -> V_73 . V_134 ;
V_223 -> V_120 = F_89 ( V_223 -> V_120 , V_190 ) ;
V_223 -> V_119 = F_89 ( V_223 -> V_119 , V_191 ) ;
V_223 -> V_227 = F_89 ( V_223 -> V_227 , 2 ) ;
V_223 -> V_228 = F_89 ( V_223 -> V_228 , 2 ) ;
if ( ! F_90 ( V_223 , & V_231 ) )
return - V_4 ;
V_10 -> V_222 . V_227 = V_223 -> V_227 ;
V_10 -> V_222 . V_228 = V_223 -> V_228 ;
V_10 -> V_222 . V_120 = V_223 -> V_120 ;
V_10 -> V_222 . V_119 = V_223 -> V_119 ;
V_10 -> V_221 = true ;
return 0 ;
}
static int F_92 ( struct V_83 * V_83 , void * V_136 ,
struct V_232 * V_233 )
{
struct V_9 * V_10 = F_6 ( V_136 ) ;
if ( V_233 -> type != V_163 &&
V_233 -> type != V_164 )
return - V_4 ;
switch ( V_233 -> V_234 ) {
case V_235 :
case V_236 :
case V_237 :
case V_238 :
V_233 -> V_223 . V_120 = V_10 -> V_73 . V_133 ;
V_233 -> V_223 . V_119 = V_10 -> V_73 . V_134 ;
V_233 -> V_223 . V_227 = 0 ;
V_233 -> V_223 . V_228 = 0 ;
break;
case V_239 :
case V_240 :
case V_241 :
V_233 -> V_223 . V_120 = V_10 -> V_222 . V_120 ;
V_233 -> V_223 . V_119 = V_10 -> V_222 . V_119 ;
V_233 -> V_223 . V_227 = V_10 -> V_222 . V_227 ;
V_233 -> V_223 . V_228 = V_10 -> V_222 . V_228 ;
break;
default:
return - V_4 ;
}
return 0 ;
}
static int F_93 ( struct V_83 * V_83 , void * V_24 ,
struct V_232 * V_233 )
{
struct V_9 * V_10 = F_6 ( V_83 -> V_94 ) ;
struct V_215 * V_242 = & V_233 -> V_223 ;
int V_89 = - V_4 ;
if ( V_233 -> type != V_164 )
return - V_4 ;
if ( V_233 -> V_234 == V_239 ) {
if ( V_10 -> V_96 != V_102 )
return - V_4 ;
if ( V_10 -> V_25 -> V_26 -> V_192 )
V_89 = F_85 ( V_10 , V_242 ) ;
} else if ( V_233 -> V_234 == V_235 ) {
if ( V_10 -> V_96 != V_97 )
return - V_4 ;
if ( V_10 -> V_25 -> V_26 -> V_192 )
V_89 = F_91 ( V_10 , V_242 ) ;
}
return V_89 ;
}
static int F_94 ( struct V_19 * V_243 )
{
struct V_9 * V_10 = F_4 ( V_243 ) ;
struct V_62 * V_25 = V_10 -> V_25 ;
unsigned long V_152 ;
switch ( V_243 -> V_60 ) {
case V_220 :
F_95 ( & V_25 -> V_244 , V_152 ) ;
V_243 -> V_245 = F_7 ( V_10 ) ;
F_96 ( & V_25 -> V_244 , V_152 ) ;
break;
}
return 0 ;
}
static int F_97 ( struct V_9 * V_10 , int * V_246 )
{
switch ( V_10 -> V_25 -> V_26 -> V_27 ) {
case V_28 :
return 0 ;
case V_29 :
case V_30 :
if ( V_10 -> V_73 . V_108 -> V_1 == V_211 )
* V_246 = 0 ;
break;
case V_33 :
if ( V_10 -> V_73 . V_108 -> V_1 != V_14 &&
* V_246 == V_13 )
return - V_4 ;
break;
}
if ( V_10 -> V_73 . V_108 -> V_12 > * V_246 )
* V_246 = V_10 -> V_73 . V_108 -> V_12 ;
return 0 ;
}
static int F_98 ( struct V_19 * V_243 )
{
struct V_9 * V_10 = F_4 ( V_243 ) ;
unsigned long V_152 ;
int V_89 = 0 ;
F_95 ( & V_10 -> V_25 -> V_244 , V_152 ) ;
if ( V_243 -> V_60 == V_220 )
V_89 = F_97 ( V_10 , & V_243 -> V_245 ) ;
F_96 ( & V_10 -> V_25 -> V_244 , V_152 ) ;
return V_89 ;
}
static int F_99 ( struct V_19 * V_243 )
{
struct V_9 * V_10 = F_4 ( V_243 ) ;
unsigned long V_152 ;
F_95 ( & V_10 -> V_25 -> V_244 , V_152 ) ;
switch ( V_243 -> V_60 ) {
case V_247 :
V_10 -> V_248 = V_243 -> V_245 ;
break;
case V_249 :
V_10 -> V_250 = V_243 -> V_245 ;
break;
case V_220 :
V_10 -> V_12 = V_243 -> V_245 ;
break;
}
F_96 ( & V_10 -> V_25 -> V_244 , V_152 ) ;
return 0 ;
}
static int F_54 ( struct V_9 * V_10 )
{
unsigned int V_251 = ~ 0x27 ;
struct V_19 * V_243 ;
int V_89 ;
F_100 ( & V_10 -> V_22 , 3 ) ;
if ( V_10 -> V_96 == V_97 ) {
F_101 ( & V_10 -> V_22 , & V_252 ,
V_247 ,
0 , 3 , 1 , V_253 ) ;
F_101 ( & V_10 -> V_22 , & V_252 ,
V_249 ,
0 , 3 , 0xffff , 0 ) ;
if ( V_10 -> V_25 -> V_26 -> V_27 == V_28 )
V_251 = ~ 0x06 ;
}
V_243 = F_102 ( & V_10 -> V_22 , & V_252 ,
V_220 ,
V_13 , V_251 ,
V_17 ) ;
if ( V_10 -> V_22 . error ) {
V_89 = V_10 -> V_22 . error ;
goto V_254;
}
if ( V_10 -> V_96 == V_102 )
V_243 -> V_152 |= V_255 |
V_256 ;
V_89 = F_103 ( & V_10 -> V_22 ) ;
if ( V_89 < 0 )
goto V_254;
return V_89 ;
V_254:
F_62 ( & V_10 -> V_22 ) ;
return V_89 ;
}
static void F_104 ( void * V_136 )
{
struct V_9 * V_10 = V_136 ;
struct V_62 * V_25 = V_10 -> V_25 ;
struct V_63 * V_257 , * V_258 ;
unsigned long V_259 , V_260 , V_152 ;
F_95 ( & V_10 -> V_25 -> V_244 , V_152 ) ;
V_257 = F_32 ( V_10 -> V_24 . V_65 ) ;
V_258 = F_105 ( V_10 -> V_24 . V_65 ) ;
V_259 = F_106 ( V_257 , 0 ) ;
V_260 = F_106 ( V_258 , 0 ) ;
F_107 ( V_25 -> V_36 ) ;
F_108 ( V_25 -> V_36 ) ;
F_109 ( V_25 -> V_36 , V_10 -> V_96 ) ;
if ( V_10 -> V_96 == V_97 ) {
if ( V_10 -> V_73 . V_108 -> V_1 == V_98 )
F_110 ( V_25 -> V_36 ,
V_261 ) ;
else
F_110 ( V_25 -> V_36 ,
V_262 ) ;
F_111 ( V_25 -> V_36 , V_10 -> V_12 ) ;
F_112 ( V_25 -> V_36 , V_10 -> V_250 ) ;
F_113 ( V_25 -> V_36 , V_10 -> V_73 . V_133 ) ;
F_114 ( V_25 -> V_36 , V_10 -> V_73 . V_134 ) ;
F_115 ( V_25 -> V_36 , V_259 ) ;
F_116 ( V_25 -> V_36 , V_260 ) ;
F_117 ( V_25 -> V_36 , V_10 -> V_109 . V_71 ) ;
F_118 ( V_25 -> V_36 , 1 , 1 , V_263 ) ;
F_118 ( V_25 -> V_36 , 1 , 2 , V_264 ) ;
F_118 ( V_25 -> V_36 , 1 , 3 , V_265 ) ;
F_118 ( V_25 -> V_36 , 2 , 1 , V_266 ) ;
F_118 ( V_25 -> V_36 , 2 , 2 , V_267 ) ;
F_118 ( V_25 -> V_36 , 2 , 3 , V_268 ) ;
F_118 ( V_25 -> V_36 , 3 , 1 , V_269 ) ;
F_118 ( V_25 -> V_36 , 3 , 2 , V_270 ) ;
F_118 ( V_25 -> V_36 , 3 , 3 , V_271 ) ;
F_11 ( V_25 -> V_36 , V_10 -> V_248 ) ;
F_13 ( V_25 -> V_36 , V_10 -> V_248 ) ;
F_119 ( V_25 -> V_36 , 1 , 0 ) ;
F_119 ( V_25 -> V_36 , 2 , 1 ) ;
F_119 ( V_25 -> V_36 , 3 , 1 ) ;
F_120 ( V_25 -> V_36 , 1 ) ;
F_121 ( V_25 -> V_36 , 1 ) ;
F_120 ( V_25 -> V_36 , 2 ) ;
F_121 ( V_25 -> V_36 , 2 ) ;
F_120 ( V_25 -> V_36 , 3 ) ;
F_121 ( V_25 -> V_36 , 3 ) ;
} else {
F_122 ( V_25 -> V_36 , true ) ;
F_123 ( V_25 -> V_36 , true ) ;
F_124 ( V_25 -> V_36 , true ) ;
if ( V_10 -> V_109 . V_108 -> V_1 == V_103 )
F_125 ( V_25 -> V_36 , V_272 ) ;
else
F_125 ( V_25 -> V_36 , V_273 ) ;
F_116 ( V_25 -> V_36 , V_259 ) ;
F_115 ( V_25 -> V_36 , V_260 ) ;
}
F_126 ( V_25 -> V_36 ) ;
F_96 ( & V_10 -> V_25 -> V_244 , V_152 ) ;
}
static void F_127 ( struct V_9 * V_10 )
{
struct V_62 * V_25 = V_10 -> V_25 ;
struct V_86 * V_108 ;
struct V_63 * V_64 ;
struct V_274 V_275 = {} ;
T_1 V_276 , V_277 = 0 ;
V_275 . V_278 = 0 ;
V_275 . V_279 = 0 ;
V_276 = V_10 -> V_109 . V_133 * V_10 -> V_109 . V_134 ;
if ( V_10 -> V_96 == V_97 ) {
V_64 = F_32 ( V_10 -> V_24 . V_65 ) ;
V_108 = V_10 -> V_73 . V_108 ;
if ( V_10 -> V_73 . V_133 % 2 && V_108 -> V_199 > 0 )
V_277 = V_10 -> V_73 . V_134 ;
} else {
V_108 = V_10 -> V_109 . V_108 ;
V_64 = F_105 ( V_10 -> V_24 . V_65 ) ;
}
V_275 . V_280 = F_106 ( V_64 , 0 ) ;
if ( V_108 -> V_177 == 2 ) {
V_275 . V_278 = V_275 . V_280 + V_276 - V_277 ;
} else if ( V_108 -> V_177 == 3 ) {
V_275 . V_278 = V_275 . V_280 + V_276 ;
if ( V_108 -> V_1 == V_207 )
V_275 . V_279 = V_275 . V_278 + V_276 / 4 ;
else
V_275 . V_279 = V_275 . V_278 + V_276 / 2 ;
}
F_128 ( V_25 -> V_36 , & V_275 ) ;
}
static void F_129 ( struct V_9 * V_10 )
{
struct V_62 * V_25 = V_10 -> V_25 ;
struct V_63 * V_64 ;
unsigned int V_275 = 0 ;
if ( V_10 -> V_96 == V_97 )
V_64 = F_105 ( V_10 -> V_24 . V_65 ) ;
else
V_64 = F_32 ( V_10 -> V_24 . V_65 ) ;
V_275 = F_106 ( V_64 , 0 ) ;
if ( V_25 -> V_26 -> V_27 == V_34 &&
V_10 -> V_96 == V_102 )
V_275 += V_10 -> V_73 . V_74 ;
F_130 ( V_25 -> V_36 , V_275 ) ;
}
static inline void F_131 ( void T_2 * V_50 ,
unsigned int V_281 )
{
F_132 ( V_50 , V_281 , V_33 ) ;
}
static inline void F_133 ( void T_2 * V_50 ,
unsigned int V_281 )
{
F_132 ( V_50 , V_281 , V_34 ) ;
}
static inline void F_134 ( void T_2 * V_50 ,
unsigned int V_87 )
{
F_135 ( V_50 , V_87 , V_33 ) ;
}
static inline void F_136 ( void T_2 * V_50 ,
unsigned int V_87 )
{
F_135 ( V_50 , V_87 , V_34 ) ;
}
static void F_137 ( void * V_136 )
{
struct V_9 * V_10 = V_136 ;
struct V_62 * V_25 = V_10 -> V_25 ;
unsigned int V_282 ;
unsigned long V_152 ;
F_95 ( & V_25 -> V_244 , V_152 ) ;
if ( V_10 -> V_96 == V_97 ) {
F_138 ( V_25 -> V_36 ) ;
F_139 ( V_25 -> V_36 , V_25 -> V_26 -> V_27 ) ;
F_140 ( V_25 -> V_36 , 1 ) ;
F_27 ( V_25 -> V_36 ) ;
F_24 ( V_25 -> V_36 , V_10 -> V_248 ) ;
F_26 ( V_25 -> V_36 , V_10 -> V_248 ) ;
F_141 ( V_25 -> V_36 ,
V_10 -> V_248 ) ;
F_142 ( V_25 -> V_36 , V_10 -> V_109 . V_133 ,
V_10 -> V_109 . V_134 ) ;
if ( V_10 -> V_25 -> V_26 -> V_27 == V_33 ) {
F_134 ( V_25 -> V_36 ,
V_10 -> V_12 ) ;
F_131 ( V_25 -> V_36 ,
V_10 -> V_73 . V_108 -> V_1 ) ;
} else {
F_136 ( V_25 -> V_36 ,
V_10 -> V_12 ) ;
F_133 ( V_25 -> V_36 ,
V_10 -> V_73 . V_108 -> V_1 ) ;
}
F_127 ( V_10 ) ;
F_129 ( V_10 ) ;
F_143 ( V_25 -> V_36 ,
V_10 -> V_73 . V_108 -> V_1 ) ;
} else {
F_138 ( V_25 -> V_36 ) ;
F_139 ( V_25 -> V_36 ,
V_25 -> V_26 -> V_27 ) ;
F_127 ( V_10 ) ;
F_129 ( V_10 ) ;
if ( V_25 -> V_26 -> V_27 == V_34 ) {
F_37 ( V_10 ) ;
F_31 ( V_10 ) ;
F_42 ( V_10 ) ;
F_38 ( V_10 ) ;
F_140 ( V_25 -> V_36 , 1 ) ;
F_142 ( V_25 -> V_36 , V_10 -> V_109 . V_133 ,
V_10 -> V_109 . V_134 ) ;
F_136 ( V_25 -> V_36 ,
V_10 -> V_12 ) ;
F_133 ( V_25 -> V_36 ,
V_10 -> V_109 . V_108 -> V_1 ) ;
V_282 = F_144 ( V_10 -> V_73 . V_71 , 16 ) ;
} else {
F_131 ( V_25 -> V_36 ,
V_10 -> V_109 . V_108 -> V_1 ) ;
V_282 = F_144 ( V_10 -> V_73 . V_71 , 32 ) ;
}
F_145 ( V_25 -> V_36 , V_282 ) ;
}
F_146 ( V_25 -> V_36 , V_10 -> V_96 ) ;
F_96 ( & V_25 -> V_244 , V_152 ) ;
}
static void F_147 ( struct V_9 * V_10 )
{
struct V_62 * V_25 = V_10 -> V_25 ;
struct V_86 * V_108 ;
struct V_63 * V_64 ;
struct V_274 V_275 = {} ;
T_1 V_276 ;
V_276 = V_10 -> V_109 . V_133 * V_10 -> V_109 . V_134 ;
if ( V_10 -> V_96 == V_97 ) {
V_64 = F_32 ( V_10 -> V_24 . V_65 ) ;
V_108 = V_10 -> V_73 . V_108 ;
} else {
V_64 = F_105 ( V_10 -> V_24 . V_65 ) ;
V_108 = V_10 -> V_109 . V_108 ;
}
V_275 . V_280 = F_106 ( V_64 , 0 ) ;
if ( V_108 -> V_177 == 2 ) {
V_275 . V_278 = V_275 . V_280 + V_276 ;
} else if ( V_108 -> V_177 == 3 ) {
V_275 . V_278 = V_275 . V_280 + V_276 ;
if ( V_108 -> V_1 == V_207 )
V_275 . V_279 = V_275 . V_278 + V_276 / 4 ;
else
V_275 . V_279 = V_275 . V_278 + V_276 / 2 ;
}
F_148 ( V_25 -> V_36 , & V_275 ) ;
}
static void F_149 ( struct V_9 * V_10 )
{
struct V_62 * V_25 = V_10 -> V_25 ;
struct V_63 * V_64 ;
unsigned int V_275 = 0 ;
if ( V_10 -> V_96 == V_97 )
V_64 = F_105 ( V_10 -> V_24 . V_65 ) ;
else
V_64 = F_32 ( V_10 -> V_24 . V_65 ) ;
V_275 = F_106 ( V_64 , 0 ) ;
F_150 ( V_25 -> V_36 , V_275 ) ;
}
static void F_151 ( void * V_136 )
{
struct V_9 * V_10 = V_136 ;
struct V_62 * V_25 = V_10 -> V_25 ;
unsigned long V_152 ;
F_95 ( & V_10 -> V_25 -> V_244 , V_152 ) ;
F_152 ( V_25 -> V_36 ) ;
F_153 ( V_25 -> V_36 ) ;
F_154 ( V_25 -> V_36 ) ;
F_155 ( V_25 -> V_36 ) ;
F_156 ( V_25 -> V_36 , V_10 -> V_96 ) ;
if ( V_10 -> V_96 == V_97 ) {
F_157 ( V_25 -> V_36 ,
V_10 -> V_73 . V_108 -> V_1 ) ;
F_158 ( V_25 -> V_36 , V_10 -> V_250 ) ;
F_11 ( V_25 -> V_36 , V_10 -> V_248 ) ;
F_13 ( V_25 -> V_36 , V_10 -> V_248 ) ;
F_159 ( V_25 -> V_36 , 1 , 0 ) ;
F_159 ( V_25 -> V_36 , 2 , 1 ) ;
F_159 ( V_25 -> V_36 , 3 , 1 ) ;
if ( V_25 -> V_26 -> V_283 ) {
F_15 ( V_25 -> V_36 ) ;
F_17 ( V_25 -> V_36 ) ;
F_19 ( V_25 -> V_36 ) ;
F_21 ( V_25 -> V_36 ) ;
}
F_160 ( V_25 -> V_36 , 1 ) ;
F_161 ( V_25 -> V_36 , 1 ) ;
F_160 ( V_25 -> V_36 , 2 ) ;
F_161 ( V_25 -> V_36 , 2 ) ;
F_160 ( V_25 -> V_36 , 3 ) ;
F_161 ( V_25 -> V_36 , 3 ) ;
F_162 ( V_25 -> V_36 , V_10 -> V_222 . V_120 ) ;
F_163 ( V_25 -> V_36 , V_10 -> V_222 . V_119 ) ;
F_164 ( V_25 -> V_36 , V_10 -> V_73 . V_108 -> V_1 ,
V_10 -> V_73 . V_133 ) ;
F_165 ( V_25 -> V_36 , V_10 -> V_222 . V_227 ,
V_10 -> V_222 . V_228 ) ;
F_147 ( V_10 ) ;
F_149 ( V_10 ) ;
F_166 ( V_25 -> V_36 , V_10 -> V_12 ) ;
F_167 ( V_25 -> V_36 , V_10 -> V_109 . V_71 ) ;
if ( V_10 -> V_73 . V_108 -> V_1 == V_98 ||
V_10 -> V_73 . V_108 -> V_1 == V_284 ||
V_10 -> V_73 . V_108 -> V_1 == V_211 )
F_168 ( V_25 -> V_36 , true ) ;
} else {
F_147 ( V_10 ) ;
F_149 ( V_10 ) ;
F_164 ( V_25 -> V_36 , V_10 -> V_109 . V_108 -> V_1 ,
V_10 -> V_109 . V_133 ) ;
F_165 ( V_25 -> V_36 , 0 , 0 ) ;
F_169 ( V_25 -> V_36 ,
V_10 -> V_104 ) ;
F_170 ( V_25 -> V_36 , V_10 -> V_73 . V_71 ) ;
F_171 ( V_25 -> V_36 ,
V_10 -> V_109 . V_108 -> V_1 ) ;
}
F_172 ( V_25 -> V_36 ) ;
F_173 ( V_25 -> V_36 , V_10 -> V_96 ) ;
F_174 ( V_25 -> V_36 , V_285 ) ;
V_25 -> V_286 = 0 ;
F_175 ( V_25 -> V_36 ) ;
F_96 ( & V_10 -> V_25 -> V_244 , V_152 ) ;
}
static int F_176 ( void * V_136 )
{
struct V_9 * V_10 = V_136 ;
if ( V_10 -> V_96 == V_102 )
return V_10 -> V_172 ;
return 1 ;
}
static void F_177 ( void * V_136 )
{
}
static int F_178 ( struct V_166 * V_167 ,
const void * V_287 ,
unsigned int * V_288 , unsigned int * V_289 ,
unsigned int V_290 [] , void * V_291 [] )
{
struct V_9 * V_10 = F_179 ( V_167 ) ;
struct V_113 * V_168 = NULL ;
unsigned int V_71 , V_292 = * V_288 ;
V_168 = F_69 ( V_10 , V_167 -> type ) ;
F_72 ( V_168 == NULL ) ;
V_71 = V_168 -> V_71 ;
if ( V_10 -> V_96 == V_102 )
V_292 = 1 ;
* V_288 = V_292 ;
* V_289 = 1 ;
V_290 [ 0 ] = V_71 ;
V_291 [ 0 ] = V_10 -> V_25 -> V_293 ;
return 0 ;
}
static int F_180 ( struct V_63 * V_64 )
{
struct V_9 * V_10 = F_179 ( V_64 -> V_166 ) ;
struct V_113 * V_168 = NULL ;
V_168 = F_69 ( V_10 , V_64 -> V_166 -> type ) ;
F_72 ( V_168 == NULL ) ;
if ( F_181 ( V_64 , 0 ) < V_168 -> V_71 ) {
F_182 ( L_5 ,
V_218 , F_181 ( V_64 , 0 ) ,
( long ) V_168 -> V_71 ) ;
return - V_4 ;
}
F_183 ( V_64 , 0 , V_168 -> V_71 ) ;
return 0 ;
}
static void F_184 ( struct V_63 * V_64 )
{
struct V_294 * V_295 = F_185 ( V_64 ) ;
struct V_9 * V_10 = F_179 ( V_64 -> V_166 ) ;
if ( V_10 -> V_96 == V_102 &&
V_64 -> V_166 -> type == V_163 ) {
struct V_113 V_296 , * V_168 ;
V_10 -> V_172 = F_63 ( & V_296 ,
( unsigned long ) F_33 ( V_64 , 0 ) ,
F_186 ( ( unsigned long ) V_10 -> V_73 . V_71 ,
F_187 ( V_64 , 0 ) ) , V_10 ) ;
if ( ! V_10 -> V_172 ) {
F_188 ( V_64 , V_297 ) ;
return;
}
V_168 = & V_10 -> V_73 ;
V_168 -> V_133 = V_296 . V_133 ;
V_168 -> V_134 = V_296 . V_134 ;
V_168 -> V_74 = V_296 . V_74 ;
memcpy ( V_168 -> V_78 . V_79 , V_296 . V_78 . V_79 ,
sizeof( V_296 . V_78 . V_79 ) ) ;
memcpy ( V_168 -> V_78 . V_39 , V_296 . V_78 . V_39 , sizeof( V_296 . V_78 . V_39 ) ) ;
V_168 -> V_78 . V_76 = V_296 . V_78 . V_76 ;
memcpy ( V_168 -> V_82 . V_79 , V_296 . V_82 . V_79 ,
sizeof( V_296 . V_82 . V_79 ) ) ;
memcpy ( V_168 -> V_82 . V_39 , V_296 . V_82 . V_39 , sizeof( V_296 . V_82 . V_39 ) ) ;
V_168 -> V_82 . V_76 = V_296 . V_82 . V_76 ;
V_168 -> V_81 = V_296 . V_81 ;
V_168 -> V_80 = V_296 . V_80 ;
V_168 = & V_10 -> V_109 ;
V_168 -> V_133 = V_296 . V_133 ;
V_168 -> V_134 = V_296 . V_134 ;
}
F_189 ( V_10 -> V_24 . V_65 , V_295 ) ;
}
static int F_190 ( struct V_166 * V_298 , unsigned int V_292 )
{
struct V_9 * V_10 = F_179 ( V_298 ) ;
int V_89 ;
V_89 = F_191 ( V_10 -> V_25 -> V_299 ) ;
return V_89 > 0 ? 0 : V_89 ;
}
static void F_192 ( struct V_166 * V_298 )
{
struct V_9 * V_10 = F_179 ( V_298 ) ;
F_193 ( V_10 -> V_25 -> V_299 ) ;
}
static int V_107 ( void * V_136 , struct V_166 * V_300 ,
struct V_166 * V_301 )
{
struct V_9 * V_10 = V_136 ;
int V_89 ;
V_300 -> type = V_163 ;
V_300 -> V_302 = V_303 | V_304 ;
V_300 -> V_305 = V_10 ;
V_300 -> V_306 = sizeof( struct V_307 ) ;
V_300 -> V_308 = & V_309 ;
V_300 -> V_310 = & V_311 ;
V_300 -> V_312 = V_313 ;
V_300 -> V_92 = & V_10 -> V_25 -> V_92 ;
V_89 = F_194 ( V_300 ) ;
if ( V_89 )
return V_89 ;
V_301 -> type = V_164 ;
V_301 -> V_302 = V_303 | V_304 ;
V_301 -> V_305 = V_10 ;
V_301 -> V_306 = sizeof( struct V_307 ) ;
V_301 -> V_308 = & V_309 ;
V_301 -> V_310 = & V_311 ;
V_301 -> V_312 = V_313 ;
V_301 -> V_92 = & V_10 -> V_25 -> V_92 ;
return F_194 ( V_301 ) ;
}
static T_3 F_195 ( int V_314 , void * V_315 )
{
struct V_62 * V_25 = V_315 ;
struct V_9 * V_316 ;
struct V_294 * V_257 , * V_258 ;
unsigned long V_317 = 0 ;
enum V_318 V_319 = V_320 ;
bool V_321 = false ;
bool V_322 = false ;
bool V_323 = false ;
F_196 ( & V_25 -> V_244 ) ;
V_316 = F_197 ( V_25 -> V_106 ) ;
V_257 = F_198 ( V_316 -> V_24 . V_65 ) ;
V_258 = F_199 ( V_316 -> V_24 . V_65 ) ;
if ( V_316 -> V_96 == V_97 )
V_321 = F_200 ( V_25 -> V_36 ) ;
V_322 = F_201 ( V_25 -> V_36 ) ;
V_323 = F_202 ( V_25 -> V_36 ) ;
if ( V_316 -> V_96 == V_102 )
V_323 = V_323 &&
F_203 ( V_25 -> V_36 ) ;
if ( V_321 ) {
V_319 = V_297 ;
F_204 ( V_25 -> V_36 ) ;
} else if ( V_322 ) {
V_319 = V_297 ;
F_205 ( V_25 -> V_36 ) ;
} else if ( ! V_323 ) {
V_319 = V_297 ;
} else {
V_317 = F_206 ( V_25 -> V_36 ) ;
}
V_258 -> V_324 = V_257 -> V_324 ;
V_258 -> V_325 = V_257 -> V_325 ;
V_258 -> V_152 &= ~ V_326 ;
V_258 -> V_152 |=
V_257 -> V_152 & V_326 ;
F_207 ( V_257 , V_319 ) ;
if ( V_316 -> V_96 == V_97 )
F_183 ( & V_258 -> V_327 , 0 , V_317 ) ;
F_207 ( V_258 , V_319 ) ;
F_208 ( V_25 -> V_106 , V_316 -> V_24 . V_65 ) ;
V_316 -> V_12 = F_209 ( V_25 -> V_36 ) ;
F_210 ( & V_25 -> V_244 ) ;
F_211 ( V_25 -> V_36 ) ;
return V_328 ;
}
static T_3 F_212 ( int V_314 , void * V_136 )
{
unsigned int V_329 ;
struct V_294 * V_330 , * V_331 ;
struct V_62 * V_25 = V_136 ;
struct V_9 * V_316 ;
unsigned long V_317 = 0 ;
F_196 ( & V_25 -> V_244 ) ;
V_316 = F_197 ( V_25 -> V_106 ) ;
V_330 = F_198 ( V_316 -> V_24 . V_65 ) ;
V_331 = F_199 ( V_316 -> V_24 . V_65 ) ;
V_329 = F_213 ( V_25 -> V_36 ) ;
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
V_317 = F_214 ( V_25 -> V_36 ) ;
F_183 ( & V_331 -> V_327 ,
0 , V_317 ) ;
}
F_207 ( V_330 , V_320 ) ;
F_207 ( V_331 , V_320 ) ;
} else {
F_207 ( V_330 , V_297 ) ;
F_207 ( V_331 , V_297 ) ;
}
F_208 ( V_25 -> V_106 , V_316 -> V_24 . V_65 ) ;
if ( V_25 -> V_26 -> V_27 == V_33 )
V_316 -> V_12 = F_215 ( V_25 -> V_36 ) ;
F_210 ( & V_25 -> V_244 ) ;
return V_328 ;
}
static T_3 F_216 ( int V_314 , void * V_315 )
{
struct V_62 * V_25 = V_315 ;
struct V_9 * V_316 ;
struct V_294 * V_257 , * V_258 ;
unsigned long V_317 = 0 ;
enum V_318 V_319 = V_320 ;
bool V_339 = false ;
T_1 V_286 ;
F_196 ( & V_25 -> V_244 ) ;
V_286 = F_217 ( V_25 -> V_36 ) ;
if ( V_286 & V_340 ) {
F_218 ( V_25 -> V_36 ) ;
V_339 = true ;
F_219 ( V_25 -> V_299 , L_6 ) ;
}
V_286 = F_220 ( V_25 -> V_36 ) ;
F_221 ( V_25 -> V_36 , V_286 ) ;
V_25 -> V_286 |= V_286 ;
V_316 = F_197 ( V_25 -> V_106 ) ;
if ( ! V_316 )
goto V_341;
if ( ( V_286 & V_342 ) &&
( V_316 -> V_96 == V_102 ) ) {
F_222 ( V_25 -> V_36 ) ;
goto V_341;
}
if ( V_25 -> V_286 & ( V_343 |
V_344 |
V_345 |
V_346 ) )
V_317 = F_223 ( V_25 -> V_36 ) ;
else if ( V_339 )
V_319 = V_297 ;
else
goto V_341;
V_257 = F_198 ( V_316 -> V_24 . V_65 ) ;
V_258 = F_199 ( V_316 -> V_24 . V_65 ) ;
V_258 -> V_324 = V_257 -> V_324 ;
V_258 -> V_325 = V_257 -> V_325 ;
F_207 ( V_257 , V_319 ) ;
if ( V_316 -> V_96 == V_97 )
F_183 ( & V_258 -> V_327 , 0 , V_317 ) ;
F_207 ( V_258 , V_319 ) ;
F_208 ( V_25 -> V_106 , V_316 -> V_24 . V_65 ) ;
V_316 -> V_12 =
F_224 ( V_25 -> V_36 ) ;
V_341:
F_210 ( & V_25 -> V_244 ) ;
return V_328 ;
}
static int F_225 ( struct V_347 * V_348 )
{
struct V_62 * V_25 ;
struct V_349 * V_350 ;
int V_2 , V_89 ;
V_25 = F_226 ( & V_348 -> V_299 , sizeof( struct V_62 ) , V_90 ) ;
if ( ! V_25 )
return - V_91 ;
V_25 -> V_26 = F_227 ( & V_348 -> V_299 ) ;
F_228 ( & V_25 -> V_92 ) ;
F_229 ( & V_25 -> V_244 ) ;
V_25 -> V_299 = & V_348 -> V_299 ;
V_350 = F_230 ( V_348 , V_351 , 0 ) ;
V_25 -> V_36 = F_231 ( & V_348 -> V_299 , V_350 ) ;
if ( F_52 ( V_25 -> V_36 ) )
return F_53 ( V_25 -> V_36 ) ;
V_25 -> V_314 = V_89 = F_232 ( V_348 , 0 ) ;
if ( V_89 < 0 ) {
F_219 ( & V_348 -> V_299 , L_7 ) ;
return V_89 ;
}
V_89 = F_233 ( & V_348 -> V_299 , V_25 -> V_314 , V_25 -> V_26 -> V_352 ,
0 , F_234 ( & V_348 -> V_299 ) , V_25 ) ;
if ( V_89 ) {
F_219 ( & V_348 -> V_299 , L_8 , V_25 -> V_314 ) ;
return V_89 ;
}
for ( V_2 = 0 ; V_2 < V_25 -> V_26 -> V_353 ; V_2 ++ ) {
V_25 -> V_354 [ V_2 ] = F_235 ( & V_348 -> V_299 ,
V_25 -> V_26 -> V_355 [ V_2 ] ) ;
if ( F_52 ( V_25 -> V_354 [ V_2 ] ) ) {
F_219 ( & V_348 -> V_299 , L_9 ,
V_25 -> V_26 -> V_355 [ V_2 ] ) ;
return F_53 ( V_25 -> V_354 [ V_2 ] ) ;
}
}
V_89 = F_236 ( & V_348 -> V_299 , & V_25 -> V_202 ) ;
if ( V_89 ) {
F_219 ( & V_348 -> V_299 , L_10 ) ;
return V_89 ;
}
V_25 -> V_106 = F_237 ( V_25 -> V_26 -> V_356 ) ;
if ( F_52 ( V_25 -> V_106 ) ) {
F_77 ( & V_25 -> V_202 , L_11 ) ;
V_89 = F_53 ( V_25 -> V_106 ) ;
goto V_357;
}
V_25 -> V_293 = F_238 ( & V_348 -> V_299 ) ;
if ( F_52 ( V_25 -> V_293 ) ) {
F_77 ( & V_25 -> V_202 , L_12 ) ;
V_89 = F_53 ( V_25 -> V_293 ) ;
goto V_358;
}
V_25 -> V_95 = F_239 () ;
if ( ! V_25 -> V_95 ) {
F_77 ( & V_25 -> V_202 , L_13 ) ;
V_89 = - V_91 ;
goto V_359;
}
snprintf ( V_25 -> V_95 -> V_155 , sizeof( V_25 -> V_95 -> V_155 ) ,
L_14 , V_140 ) ;
V_25 -> V_95 -> V_360 = & V_361 ;
V_25 -> V_95 -> V_362 = & V_363 ;
V_25 -> V_95 -> V_364 = - 1 ;
V_25 -> V_95 -> V_365 = V_366 ;
V_25 -> V_95 -> V_92 = & V_25 -> V_92 ;
V_25 -> V_95 -> V_202 = & V_25 -> V_202 ;
V_25 -> V_95 -> V_367 = V_368 ;
V_89 = F_240 ( V_25 -> V_95 , V_369 , - 1 ) ;
if ( V_89 ) {
F_77 ( & V_25 -> V_202 , L_15 ) ;
V_366 ( V_25 -> V_95 ) ;
goto V_359;
}
F_241 ( V_25 -> V_95 , V_25 ) ;
F_242 ( & V_25 -> V_202 ,
L_16 ,
V_25 -> V_95 -> V_151 ) ;
V_25 -> V_370 = F_239 () ;
if ( ! V_25 -> V_370 ) {
F_77 ( & V_25 -> V_202 , L_13 ) ;
V_89 = - V_91 ;
goto V_371;
}
snprintf ( V_25 -> V_370 -> V_155 , sizeof( V_25 -> V_370 -> V_155 ) ,
L_17 , V_140 ) ;
V_25 -> V_370 -> V_360 = & V_361 ;
V_25 -> V_370 -> V_362 = & V_363 ;
V_25 -> V_370 -> V_364 = - 1 ;
V_25 -> V_370 -> V_365 = V_366 ;
V_25 -> V_370 -> V_92 = & V_25 -> V_92 ;
V_25 -> V_370 -> V_202 = & V_25 -> V_202 ;
V_25 -> V_370 -> V_367 = V_368 ;
V_89 = F_240 ( V_25 -> V_370 , V_369 , - 1 ) ;
if ( V_89 ) {
F_77 ( & V_25 -> V_202 , L_15 ) ;
V_366 ( V_25 -> V_370 ) ;
goto V_371;
}
F_241 ( V_25 -> V_370 , V_25 ) ;
F_242 ( & V_25 -> V_202 ,
L_18 ,
V_25 -> V_370 -> V_151 ) ;
F_243 ( V_348 , V_25 ) ;
F_244 ( & V_348 -> V_299 ) ;
F_242 ( & V_25 -> V_202 , L_19 ) ;
return 0 ;
V_371:
F_245 ( V_25 -> V_95 ) ;
V_359:
F_246 ( V_25 -> V_293 ) ;
V_358:
F_247 ( V_25 -> V_106 ) ;
V_357:
F_248 ( & V_25 -> V_202 ) ;
return V_89 ;
}
static int F_249 ( struct V_347 * V_348 )
{
struct V_62 * V_25 = F_250 ( V_348 ) ;
int V_2 ;
F_251 ( V_25 -> V_299 ) ;
F_245 ( V_25 -> V_370 ) ;
F_245 ( V_25 -> V_95 ) ;
F_246 ( V_25 -> V_293 ) ;
F_247 ( V_25 -> V_106 ) ;
F_248 ( & V_25 -> V_202 ) ;
if ( ! F_252 ( & V_348 -> V_299 ) ) {
for ( V_2 = V_25 -> V_26 -> V_353 - 1 ; V_2 >= 0 ; V_2 -- )
F_253 ( V_25 -> V_354 [ V_2 ] ) ;
}
return 0 ;
}
static int F_254 ( struct V_372 * V_299 )
{
struct V_62 * V_25 = F_255 ( V_299 ) ;
int V_2 ;
for ( V_2 = V_25 -> V_26 -> V_353 - 1 ; V_2 >= 0 ; V_2 -- )
F_253 ( V_25 -> V_354 [ V_2 ] ) ;
return 0 ;
}
static int F_256 ( struct V_372 * V_299 )
{
struct V_62 * V_25 = F_255 ( V_299 ) ;
unsigned long V_152 ;
int V_2 , V_89 ;
for ( V_2 = 0 ; V_2 < V_25 -> V_26 -> V_353 ; V_2 ++ ) {
V_89 = F_257 ( V_25 -> V_354 [ V_2 ] ) ;
if ( V_89 ) {
while ( -- V_2 > 0 )
F_253 ( V_25 -> V_354 [ V_2 ] ) ;
return V_89 ;
}
}
F_95 ( & V_25 -> V_244 , V_152 ) ;
if ( ! V_25 -> V_26 -> V_283 ) {
F_15 ( V_25 -> V_36 ) ;
F_17 ( V_25 -> V_36 ) ;
F_19 ( V_25 -> V_36 ) ;
F_21 ( V_25 -> V_36 ) ;
}
F_96 ( & V_25 -> V_244 , V_152 ) ;
return 0 ;
}
static int F_258 ( struct V_372 * V_299 )
{
if ( F_259 ( V_299 ) )
return 0 ;
return F_254 ( V_299 ) ;
}
static int F_260 ( struct V_372 * V_299 )
{
if ( F_259 ( V_299 ) )
return 0 ;
return F_256 ( V_299 ) ;
}
static void * F_227 ( struct V_372 * V_299 )
{
struct V_373 * V_374 = NULL ;
const struct V_375 * V_376 ;
if ( ! F_261 ( V_377 ) || ! V_299 -> V_378 )
return & V_379 ;
V_376 = F_262 ( V_380 , V_299 -> V_378 ) ;
if ( V_376 )
V_374 = (struct V_373 * ) V_376 -> V_72 ;
return V_374 ;
}
