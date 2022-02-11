static inline struct V_1 * V_1 ( struct V_2 * V_3 )
{
return F_1 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_2 ( struct V_1 * V_4 , T_1 V_5 )
{
if ( F_3 ( ! ( V_6 &
( V_7 | V_8 ) ) ) )
return;
if ( ! ( V_6 & V_7 ) &&
! ( V_5 & V_9 ) )
return;
F_4 ( V_4 -> V_3 . V_10 ,
L_1 , V_5 ,
V_5 & V_11 ? L_2 : L_3 ,
V_5 & V_12 ? L_4 : L_3 ,
V_5 & V_13 ? L_5 : L_3 ,
V_5 & V_14 ? L_6 : L_3 ,
V_5 & V_15 ? L_7 : L_3 ,
V_5 & V_16 ? L_8 : L_3 ,
V_5 & V_17 ? L_9 : L_3 ,
V_5 & V_18 ? L_10 : L_3 ,
V_5 & V_19 ? L_11 : L_3 ,
V_5 & V_20 ? L_12 : L_3 ,
V_5 & V_21 ? L_13 : L_3 ,
V_5 & V_22 ? L_14 : L_3 ,
V_5 & V_23 ? L_15 : L_3 ,
V_5 & V_9 ? L_16 : L_3 ,
V_5 & ~ ( V_11 | V_12 |
V_13 | V_14 |
V_15 | V_16 |
V_17 | V_18 |
V_19 | V_20 |
V_21 |
V_22 | V_9 )
? L_17 : L_3 ) ;
}
static char F_5 ( T_1 * V_24 , int V_25 )
{
return V_26 [ * V_24 >> V_25 & 3 ] ;
}
static void F_6 ( struct V_1 * V_4 , int V_27 , int V_28 )
{
T_1 * V_24 ;
if ( F_3 ( ! ( V_6 & V_29 ) ) )
return;
F_4 ( V_4 -> V_3 . V_10 ,
L_18 ,
V_28 , V_27 , V_4 -> V_30 ) ;
for ( V_24 = V_4 -> V_31 ; V_28 -- ; ++ V_24 )
if ( ( * V_24 & 1 << 23 ) == 0 )
F_4 ( V_4 -> V_3 . V_10 ,
L_19
L_20 ,
* V_24 , * V_24 >> 24 & 63 , F_5 ( V_24 , 6 ) , F_5 ( V_24 , 4 ) , F_5 ( V_24 , 2 ) ,
V_32 [ * V_24 >> 14 & 3 ] , * V_24 >> 16 & 63 ,
V_33 [ * V_24 >> 8 & 7 ] , * V_24 >> 22 & 1 ? L_21 : L_3 ,
* V_24 >> 11 & 1 ? L_22 : L_3 , * V_24 & 2 ? L_23 : L_3 ) ;
else
F_4 ( V_4 -> V_3 . V_10 ,
L_24 ,
* V_24 , * V_24 >> 24 & 63 ,
F_5 ( V_24 , 16 ) , F_5 ( V_24 , 14 ) , F_5 ( V_24 , 12 ) , F_5 ( V_24 , 10 ) ,
F_5 ( V_24 , 8 ) , F_5 ( V_24 , 6 ) , F_5 ( V_24 , 4 ) , F_5 ( V_24 , 2 ) ) ;
}
static void F_7 ( struct V_1 * V_4 ,
char V_34 , int V_32 , T_1 * V_35 , int V_5 )
{
int V_36 = V_35 [ 0 ] >> 4 & 0xf ;
char V_37 [ 12 ] ;
if ( F_3 ( ! ( V_6 & V_38 ) ) )
return;
if ( F_8 ( V_5 >= F_9 ( V_39 ) ) )
V_5 = 0x1f ;
if ( V_5 == V_40 ) {
F_4 ( V_4 -> V_3 . V_10 ,
L_25 ,
V_34 , ( V_35 [ 2 ] >> 16 ) & 0xff ) ;
return;
}
switch ( V_36 ) {
case 0x0 : case 0x6 : case 0x8 :
snprintf ( V_37 , sizeof( V_37 ) , L_26 ,
F_10 ( ( V_41 V_42 ) V_35 [ 3 ] ) ) ;
break;
case 0x1 : case 0x5 : case 0x7 : case 0x9 : case 0xb :
snprintf ( V_37 , sizeof( V_37 ) , L_27 ,
V_35 [ 3 ] >> 16 , V_35 [ 3 ] & 0xffff ) ;
break;
default:
V_37 [ 0 ] = '\0' ;
}
switch ( V_36 ) {
case 0xa :
F_4 ( V_4 -> V_3 . V_10 ,
L_28 ,
V_34 , V_39 [ V_5 ] , V_43 [ V_36 ] ) ;
break;
case 0xe :
F_4 ( V_4 -> V_3 . V_10 ,
L_29 ,
V_34 , V_39 [ V_5 ] , V_35 [ 1 ] , V_35 [ 2 ] ) ;
break;
case 0x0 : case 0x1 : case 0x4 : case 0x5 : case 0x9 :
F_4 ( V_4 -> V_3 . V_10 ,
L_30
L_31
L_32 ,
V_34 , V_32 , V_35 [ 0 ] >> 10 & 0x3f ,
V_35 [ 1 ] >> 16 , V_35 [ 0 ] >> 16 , V_39 [ V_5 ] ,
V_43 [ V_36 ] , V_35 [ 1 ] & 0xffff , V_35 [ 2 ] , V_37 ) ;
break;
default:
F_4 ( V_4 -> V_3 . V_10 ,
L_30
L_31
L_33 ,
V_34 , V_32 , V_35 [ 0 ] >> 10 & 0x3f ,
V_35 [ 1 ] >> 16 , V_35 [ 0 ] >> 16 , V_39 [ V_5 ] ,
V_43 [ V_36 ] , V_37 ) ;
}
}
static inline void F_11 ( const struct V_1 * V_4 , int V_44 , T_1 V_45 )
{
F_12 ( V_45 , V_4 -> V_46 + V_44 ) ;
}
static inline T_1 F_13 ( const struct V_1 * V_4 , int V_44 )
{
return F_14 ( V_4 -> V_46 + V_44 ) ;
}
static inline void F_15 ( const struct V_1 * V_4 )
{
F_13 ( V_4 , V_47 ) ;
}
static int F_16 ( struct V_1 * V_4 , int V_48 )
{
T_1 V_49 ;
int V_50 ;
F_11 ( V_4 , V_51 , F_17 ( V_48 ) ) ;
for ( V_50 = 0 ; V_50 < 3 + 100 ; V_50 ++ ) {
V_49 = F_13 ( V_4 , V_51 ) ;
if ( ! ~ V_49 )
return - V_52 ;
if ( V_49 & V_53 )
return F_18 ( V_49 ) ;
if ( V_50 >= 3 )
F_19 ( 1 ) ;
}
F_20 ( V_4 -> V_3 . V_10 , L_34 ) ;
return - V_54 ;
}
static int F_21 ( const struct V_1 * V_4 , int V_48 , T_1 V_49 )
{
int V_50 ;
F_11 ( V_4 , V_51 ,
F_22 ( V_48 , V_49 ) ) ;
for ( V_50 = 0 ; V_50 < 3 + 100 ; V_50 ++ ) {
V_49 = F_13 ( V_4 , V_51 ) ;
if ( ! ~ V_49 )
return - V_52 ;
if ( ! ( V_49 & V_55 ) )
return 0 ;
if ( V_50 >= 3 )
F_19 ( 1 ) ;
}
F_20 ( V_4 -> V_3 . V_10 , L_35 ) ;
return - V_54 ;
}
static int F_23 ( struct V_1 * V_4 , int V_48 ,
int V_56 , int V_57 )
{
int V_58 = F_16 ( V_4 , V_48 ) ;
if ( V_58 < 0 )
return V_58 ;
if ( V_48 == 5 )
V_56 |= V_59 ;
return F_21 ( V_4 , V_48 , ( V_58 & ~ V_56 ) | V_57 ) ;
}
static int F_24 ( struct V_1 * V_4 , int V_60 , int V_48 )
{
int V_58 ;
V_58 = F_23 ( V_4 , 7 , V_61 , V_60 << 5 ) ;
if ( V_58 < 0 )
return V_58 ;
return F_16 ( V_4 , V_48 ) ;
}
static int F_25 ( struct V_2 * V_3 , int V_48 )
{
struct V_1 * V_4 = V_1 ( V_3 ) ;
int V_58 ;
F_26 ( & V_4 -> V_62 ) ;
V_58 = F_16 ( V_4 , V_48 ) ;
F_27 ( & V_4 -> V_62 ) ;
return V_58 ;
}
static int F_28 ( struct V_2 * V_3 , int V_48 ,
int V_56 , int V_57 )
{
struct V_1 * V_4 = V_1 ( V_3 ) ;
int V_58 ;
F_26 ( & V_4 -> V_62 ) ;
V_58 = F_23 ( V_4 , V_48 , V_56 , V_57 ) ;
F_27 ( & V_4 -> V_62 ) ;
return V_58 ;
}
static inline T_2 F_29 ( struct V_63 * V_64 , unsigned int V_50 )
{
return F_30 ( V_64 -> V_65 [ V_50 ] ) ;
}
static void F_31 ( struct V_63 * V_64 , unsigned int V_66 )
{
struct V_67 * V_68 ;
V_68 = & V_64 -> V_69 [ V_66 ] ;
V_68 -> V_70 &= F_32 ( ~ 0xf ) ;
V_68 -> V_71 = F_33 ( V_72 ) ;
V_68 -> V_73 = 0 ;
F_34 () ;
V_68 = & V_64 -> V_69 [ V_64 -> V_74 ] ;
V_68 -> V_70 |= F_32 ( 1 ) ;
V_64 -> V_74 = V_66 ;
F_11 ( V_64 -> V_4 , F_35 ( V_64 -> V_75 ) , V_76 ) ;
}
static void F_36 ( struct V_63 * V_64 )
{
unsigned int V_50 ;
if ( V_64 -> V_77 )
F_37 ( V_64 -> V_77 , V_78 + V_79 ) ;
for ( V_50 = 0 ; V_50 < V_78 ; V_50 ++ )
if ( V_64 -> V_65 [ V_50 ] ) {
F_38 ( V_64 -> V_4 -> V_3 . V_10 ,
F_29 ( V_64 , V_50 ) ,
V_72 , V_80 ) ;
F_39 ( V_64 -> V_65 [ V_50 ] ) ;
}
}
static void F_40 ( struct V_63 * V_64 , const char * V_81 )
{
struct V_1 * V_4 = V_64 -> V_4 ;
if ( F_13 ( V_4 , F_41 ( V_64 -> V_75 ) ) & V_82 ) {
F_11 ( V_4 , F_41 ( V_64 -> V_75 ) , V_82 ) ;
F_15 ( V_4 ) ;
F_20 ( V_4 -> V_3 . V_10 , L_36 ,
V_81 ) ;
}
}
static inline unsigned int F_42 ( unsigned int V_66 )
{
return ( V_66 + 1 ) % V_78 ;
}
static inline unsigned int F_43 ( unsigned int V_66 )
{
return ( V_66 - 1 + V_78 ) % V_78 ;
}
static inline unsigned int F_44 ( struct V_63 * V_64 )
{
return F_42 ( V_64 -> V_74 ) ;
}
static unsigned int F_45 ( struct V_63 * V_64 ,
unsigned int * V_83 )
{
unsigned int V_50 , V_84 , V_85 = V_64 -> V_74 ;
T_3 V_71 , V_86 ;
V_50 = F_44 ( V_64 ) ;
V_71 = F_46 ( V_64 -> V_69 [ V_50 ] . V_71 ) ;
while ( V_50 != V_85 && V_71 == 0 ) {
V_84 = F_42 ( V_50 ) ;
F_47 () ;
V_86 = F_46 (
V_64 -> V_69 [ V_84 ] . V_71 ) ;
if ( V_86 == F_33 ( V_72 ) ) {
if ( V_87 > V_72 && V_50 != V_85 ) {
V_84 = F_42 ( V_84 ) ;
F_47 () ;
V_86 = F_46 (
V_64 -> V_69 [ V_84 ] . V_71 ) ;
if ( V_86 != F_33 ( V_72 ) )
goto V_88;
}
break;
}
V_88:
V_50 = V_84 ;
V_71 = V_86 ;
}
F_47 () ;
* V_83 = V_72 - F_48 ( V_71 ) ;
if ( * V_83 > V_72 ) {
* V_83 = 0 ;
F_40 ( V_64 , L_37 ) ;
}
return V_50 ;
}
static void F_49 ( struct V_63 * V_64 ,
unsigned int V_89 ,
unsigned int V_90 )
{
unsigned int V_50 ;
V_50 = F_44 ( V_64 ) ;
while ( V_50 != V_89 ) {
F_50 ( V_64 -> V_4 -> V_3 . V_10 ,
F_29 ( V_64 , V_50 ) ,
V_72 , V_80 ) ;
V_50 = F_42 ( V_50 ) ;
}
if ( V_90 > 0 )
F_50 ( V_64 -> V_4 -> V_3 . V_10 ,
F_29 ( V_64 , V_50 ) ,
V_90 , V_80 ) ;
}
static T_4 * F_51 ( struct V_63 * V_64 , T_4 * V_77 )
{
struct V_1 * V_4 = V_64 -> V_4 ;
struct V_91 V_92 ;
T_1 V_93 , V_94 , V_36 ;
int V_5 ;
V_92 . V_35 [ 0 ] = F_52 ( V_77 [ 0 ] ) ;
V_92 . V_35 [ 1 ] = F_52 ( V_77 [ 1 ] ) ;
V_92 . V_35 [ 2 ] = F_52 ( V_77 [ 2 ] ) ;
V_36 = ( V_92 . V_35 [ 0 ] >> 4 ) & 0x0f ;
switch ( V_36 ) {
case V_95 :
case V_96 :
V_92 . V_35 [ 3 ] = ( V_41 V_97 ) V_77 [ 3 ] ;
V_92 . V_98 = 16 ;
V_92 . V_99 = 0 ;
break;
case V_100 :
V_92 . V_35 [ 3 ] = F_52 ( V_77 [ 3 ] ) ;
V_92 . V_98 = 16 ;
V_92 . V_99 = 0 ;
break;
case V_101 :
case V_102 :
case V_103 :
case V_104 :
V_92 . V_35 [ 3 ] = F_52 ( V_77 [ 3 ] ) ;
V_92 . V_98 = 16 ;
V_92 . V_99 = V_92 . V_35 [ 3 ] >> 16 ;
if ( V_92 . V_99 > V_105 ) {
F_40 ( V_64 , L_38 ) ;
return NULL ;
}
break;
case V_106 :
case V_107 :
case V_108 :
V_92 . V_98 = 12 ;
V_92 . V_99 = 0 ;
break;
default:
F_40 ( V_64 , L_39 ) ;
return NULL ;
}
V_92 . V_109 = ( void * ) V_77 + V_92 . V_98 ;
V_94 = ( V_92 . V_98 + V_92 . V_99 + 3 ) / 4 ;
V_93 = F_52 ( V_77 [ V_94 ] ) ;
V_5 = ( V_93 >> 16 ) & 0x1f ;
V_92 . V_110 = V_5 - 16 ;
V_92 . V_32 = ( V_93 >> 21 ) & 0x7 ;
V_92 . V_111 = V_93 & 0xffff ;
V_92 . V_27 = V_4 -> V_112 ;
F_7 ( V_4 , 'R' , V_92 . V_32 , V_92 . V_35 , V_5 ) ;
if ( V_5 == V_113 &&
( V_92 . V_35 [ 0 ] & 0xff ) == ( V_114 << 4 ) )
V_92 . V_110 = V_115 ;
if ( V_5 == V_40 ) {
if ( ! ( V_4 -> V_116 & V_117 ) )
V_4 -> V_112 = ( V_92 . V_35 [ 2 ] >> 16 ) & 0xff ;
} else if ( V_64 == & V_4 -> V_118 ) {
F_53 ( & V_4 -> V_3 , & V_92 ) ;
} else {
F_54 ( & V_4 -> V_3 , & V_92 ) ;
}
return V_77 + V_94 + 1 ;
}
static void * F_55 ( struct V_63 * V_64 , void * V_92 , void * V_119 )
{
void * V_120 ;
while ( V_92 < V_119 ) {
V_120 = F_51 ( V_64 , V_92 ) ;
if ( ! V_120 )
return V_92 ;
V_92 = V_120 ;
}
return V_92 ;
}
static void F_56 ( struct V_63 * V_64 , unsigned int V_121 )
{
unsigned int V_50 ;
V_50 = F_44 ( V_64 ) ;
while ( V_50 != V_121 ) {
F_57 ( V_64 -> V_4 -> V_3 . V_10 ,
F_29 ( V_64 , V_50 ) ,
V_72 , V_80 ) ;
F_31 ( V_64 , V_50 ) ;
V_50 = F_42 ( V_50 ) ;
}
}
static void F_58 ( unsigned long V_45 )
{
struct V_63 * V_64 = (struct V_63 * ) V_45 ;
unsigned int V_89 , V_90 ;
void * V_92 , * V_119 ;
V_92 = V_64 -> V_122 ;
if ( ! V_92 )
return;
V_89 = F_45 ( V_64 ,
& V_90 ) ;
F_49 ( V_64 , V_89 , V_90 ) ;
V_119 = V_64 -> V_77 + V_89 * V_72 + V_90 ;
if ( V_89 < F_44 ( V_64 ) ) {
void * V_123 = V_64 -> V_77 + V_78 * V_72 ;
V_92 = F_55 ( V_64 , V_92 , V_123 ) ;
if ( V_92 < V_123 )
goto error;
V_92 -= V_78 * V_72 ;
}
V_92 = F_55 ( V_64 , V_92 , V_119 ) ;
if ( V_92 != V_119 ) {
if ( V_92 > V_119 )
F_40 ( V_64 , L_40 ) ;
goto error;
}
V_64 -> V_122 = V_92 ;
F_56 ( V_64 , V_89 ) ;
return;
error:
V_64 -> V_122 = NULL ;
}
static int F_59 ( struct V_63 * V_64 , struct V_1 * V_4 ,
unsigned int V_124 , T_1 V_75 )
{
unsigned int V_50 ;
T_2 V_125 ;
struct V_60 * V_65 [ V_78 + V_79 ] ;
struct V_67 * V_68 ;
V_64 -> V_75 = V_75 ;
V_64 -> V_4 = V_4 ;
F_60 ( & V_64 -> V_126 , F_58 , ( unsigned long ) V_64 ) ;
for ( V_50 = 0 ; V_50 < V_78 ; V_50 ++ ) {
V_64 -> V_65 [ V_50 ] = F_61 ( V_127 | V_128 ) ;
if ( ! V_64 -> V_65 [ V_50 ] )
goto V_129;
V_125 = F_62 ( V_4 -> V_3 . V_10 , V_64 -> V_65 [ V_50 ] ,
0 , V_72 , V_80 ) ;
if ( F_63 ( V_4 -> V_3 . V_10 , V_125 ) ) {
F_39 ( V_64 -> V_65 [ V_50 ] ) ;
V_64 -> V_65 [ V_50 ] = NULL ;
goto V_129;
}
F_64 ( V_64 -> V_65 [ V_50 ] , V_125 ) ;
}
for ( V_50 = 0 ; V_50 < V_78 ; V_50 ++ )
V_65 [ V_50 ] = V_64 -> V_65 [ V_50 ] ;
for ( V_50 = 0 ; V_50 < V_79 ; V_50 ++ )
V_65 [ V_78 + V_50 ] = V_64 -> V_65 [ V_50 ] ;
V_64 -> V_77 = F_65 ( V_65 , V_78 + V_79 ,
- 1 , V_130 ) ;
if ( ! V_64 -> V_77 )
goto V_129;
V_64 -> V_69 = V_4 -> V_131 + V_124 ;
V_64 -> V_132 = V_4 -> V_133 + V_124 ;
for ( V_50 = 0 ; V_50 < V_78 ; V_50 ++ ) {
V_68 = & V_64 -> V_69 [ V_50 ] ;
V_68 -> V_134 = F_33 ( V_72 ) ;
V_68 -> V_135 = F_33 ( V_136 |
V_137 |
V_138 ) ;
V_68 -> V_139 = F_32 ( F_29 ( V_64 , V_50 ) ) ;
V_68 -> V_70 = F_32 ( V_64 -> V_132 +
F_42 ( V_50 ) * sizeof( struct V_67 ) ) ;
}
return 0 ;
V_129:
F_36 ( V_64 ) ;
return - V_140 ;
}
static void F_66 ( struct V_63 * V_64 )
{
unsigned int V_50 ;
for ( V_50 = 0 ; V_50 < V_78 ; V_50 ++ )
F_31 ( V_64 , V_50 ) ;
V_64 -> V_122 = V_64 -> V_77 ;
F_11 ( V_64 -> V_4 , F_67 ( V_64 -> V_75 ) , V_64 -> V_132 | 1 ) ;
F_11 ( V_64 -> V_4 , F_35 ( V_64 -> V_75 ) , V_82 ) ;
}
static struct V_67 * F_68 ( struct V_67 * V_68 , int V_141 )
{
T_3 V_142 ;
V_142 = V_68 -> V_135 & F_33 ( V_138 ) ;
if ( V_141 == 2 && V_142 == F_33 ( V_138 ) )
return V_68 ;
else
return V_68 + V_141 - 1 ;
}
static void F_69 ( unsigned long V_45 )
{
struct V_143 * V_64 = (struct V_143 * ) V_45 ;
struct V_67 * V_68 , * V_85 ;
T_1 V_144 ;
int V_141 ;
struct V_145 * V_146 ;
V_146 = F_70 ( V_64 -> V_147 . V_120 ,
struct V_145 , V_148 ) ;
V_85 = V_64 -> V_85 ;
while ( V_85 -> V_70 != 0 ) {
struct V_145 * V_149 = V_146 ;
V_144 = F_71 ( V_85 -> V_70 ) ;
V_141 = V_144 & 0xf ;
V_144 &= ~ 0xf ;
V_64 -> V_150 = V_144 ;
if ( V_144 < V_146 -> V_151 ||
V_144 >= V_146 -> V_151 + V_146 -> V_152 )
V_146 = F_70 ( V_146 -> V_148 . V_120 ,
struct V_145 , V_148 ) ;
V_68 = V_146 -> V_77 + ( V_144 - V_146 -> V_151 ) / sizeof( * V_68 ) ;
V_85 = F_68 ( V_68 , V_141 ) ;
if ( ! V_64 -> V_153 ( V_64 , V_68 , V_85 ) )
break;
if ( V_149 != V_146 ) {
unsigned long V_154 ;
V_149 -> V_152 = 0 ;
F_72 ( & V_64 -> V_4 -> V_155 , V_154 ) ;
F_73 ( & V_149 -> V_148 , & V_64 -> V_147 ) ;
F_74 ( & V_64 -> V_4 -> V_155 , V_154 ) ;
}
V_64 -> V_85 = V_85 ;
}
}
static int F_75 ( struct V_143 * V_64 )
{
struct V_145 * V_146 ;
T_2 V_156 ( V_157 ) ;
int V_44 ;
if ( V_64 -> V_158 >= 16 * 1024 * 1024 )
return - V_140 ;
V_146 = F_76 ( V_64 -> V_4 -> V_3 . V_10 , V_72 ,
& V_157 , V_159 ) ;
if ( ! V_146 )
return - V_140 ;
V_44 = ( void * ) & V_146 -> V_77 - ( void * ) V_146 ;
V_146 -> V_160 = V_72 - V_44 ;
V_146 -> V_151 = V_157 + V_44 ;
V_146 -> V_152 = 0 ;
F_77 ( & V_146 -> V_148 , & V_64 -> V_147 ) ;
V_64 -> V_158 += V_72 ;
return 0 ;
}
static int F_78 ( struct V_143 * V_64 , struct V_1 * V_4 ,
T_1 V_75 , T_5 V_153 )
{
V_64 -> V_4 = V_4 ;
V_64 -> V_75 = V_75 ;
V_64 -> V_158 = 0 ;
F_79 ( & V_64 -> V_147 ) ;
if ( F_75 ( V_64 ) < 0 )
return - V_140 ;
V_64 -> V_161 = F_70 ( V_64 -> V_147 . V_120 ,
struct V_145 , V_148 ) ;
F_60 ( & V_64 -> V_126 , F_69 , ( unsigned long ) V_64 ) ;
V_64 -> V_153 = V_153 ;
memset ( V_64 -> V_161 -> V_77 , 0 , sizeof( * V_64 -> V_161 -> V_77 ) ) ;
V_64 -> V_161 -> V_77 -> V_135 = F_33 ( V_162 ) ;
V_64 -> V_161 -> V_77 -> V_73 = F_33 ( 0x8011 ) ;
V_64 -> V_161 -> V_152 += sizeof( * V_64 -> V_161 -> V_77 ) ;
V_64 -> V_85 = V_64 -> V_161 -> V_77 ;
V_64 -> V_163 = V_64 -> V_161 -> V_77 ;
return 0 ;
}
static void F_80 ( struct V_143 * V_64 )
{
struct V_2 * V_3 = & V_64 -> V_4 -> V_3 ;
struct V_145 * V_146 , * V_164 ;
F_81 (desc, tmp, &ctx->buffer_list, list)
F_82 ( V_3 -> V_10 , V_72 , V_146 ,
V_146 -> V_151 -
( ( void * ) & V_146 -> V_77 - ( void * ) V_146 ) ) ;
}
static struct V_67 * F_83 ( struct V_143 * V_64 ,
int V_141 , T_2 * V_165 )
{
struct V_67 * V_68 = NULL ;
struct V_145 * V_146 = V_64 -> V_161 ;
if ( V_141 * sizeof( * V_68 ) > V_146 -> V_160 )
return NULL ;
if ( V_141 * sizeof( * V_68 ) > V_146 -> V_160 - V_146 -> V_152 ) {
if ( V_146 -> V_148 . V_120 == & V_64 -> V_147 ) {
if ( F_75 ( V_64 ) < 0 )
return NULL ;
}
V_146 = F_70 ( V_146 -> V_148 . V_120 ,
struct V_145 , V_148 ) ;
V_64 -> V_161 = V_146 ;
}
V_68 = V_146 -> V_77 + V_146 -> V_152 / sizeof( * V_68 ) ;
memset ( V_68 , 0 , V_141 * sizeof( * V_68 ) ) ;
* V_165 = V_146 -> V_151 + V_146 -> V_152 ;
return V_68 ;
}
static void F_84 ( struct V_143 * V_64 , T_1 V_166 )
{
struct V_1 * V_4 = V_64 -> V_4 ;
F_11 ( V_4 , F_67 ( V_64 -> V_75 ) ,
F_71 ( V_64 -> V_85 -> V_70 ) ) ;
F_11 ( V_4 , F_41 ( V_64 -> V_75 ) , ~ 0 ) ;
F_11 ( V_4 , F_35 ( V_64 -> V_75 ) , V_82 | V_166 ) ;
V_64 -> V_167 = true ;
F_15 ( V_4 ) ;
}
static void F_85 ( struct V_143 * V_64 ,
struct V_67 * V_68 , int V_141 , int V_166 )
{
T_2 V_165 ;
struct V_145 * V_146 = V_64 -> V_161 ;
V_165 = V_146 -> V_151 + ( V_68 - V_146 -> V_77 ) * sizeof( * V_68 ) ;
V_146 -> V_152 += ( V_141 + V_166 ) * sizeof( * V_68 ) ;
F_34 () ;
V_64 -> V_163 -> V_70 = F_32 ( V_165 | V_141 ) ;
V_64 -> V_163 = F_68 ( V_68 , V_141 ) ;
}
static void F_86 ( struct V_143 * V_64 )
{
struct V_1 * V_4 = V_64 -> V_4 ;
T_1 V_168 ;
int V_50 ;
F_11 ( V_4 , F_41 ( V_64 -> V_75 ) , V_82 ) ;
V_64 -> V_167 = false ;
for ( V_50 = 0 ; V_50 < 1000 ; V_50 ++ ) {
V_168 = F_13 ( V_4 , F_35 ( V_64 -> V_75 ) ) ;
if ( ( V_168 & V_169 ) == 0 )
return;
if ( V_50 )
F_87 ( 10 ) ;
}
F_20 ( V_4 -> V_3 . V_10 , L_41 , V_168 ) ;
}
static int F_88 ( struct V_143 * V_64 ,
struct V_91 * V_170 )
{
struct V_1 * V_4 = V_64 -> V_4 ;
T_2 V_165 , V_156 ( V_171 ) ;
struct V_172 * V_172 ;
struct V_67 * V_68 , * V_85 ;
T_4 * V_35 ;
int V_141 , V_36 ;
V_68 = F_83 ( V_64 , 4 , & V_165 ) ;
if ( V_68 == NULL ) {
V_170 -> V_110 = V_173 ;
return - 1 ;
}
V_68 [ 0 ] . V_135 = F_33 ( V_174 ) ;
V_68 [ 0 ] . V_71 = F_33 ( V_170 -> V_111 ) ;
V_36 = ( V_170 -> V_35 [ 0 ] >> 4 ) & 0x0f ;
V_35 = ( T_4 * ) & V_68 [ 1 ] ;
switch ( V_36 ) {
case V_95 :
case V_101 :
case V_106 :
case V_107 :
case V_100 :
case V_96 :
case V_102 :
case V_103 :
case V_104 :
V_35 [ 0 ] = F_32 ( ( V_170 -> V_35 [ 0 ] & 0xffff ) |
( V_170 -> V_32 << 16 ) ) ;
V_35 [ 1 ] = F_32 ( ( V_170 -> V_35 [ 1 ] & 0xffff ) |
( V_170 -> V_35 [ 0 ] & 0xffff0000 ) ) ;
V_35 [ 2 ] = F_32 ( V_170 -> V_35 [ 2 ] ) ;
if ( F_89 ( V_36 ) )
V_35 [ 3 ] = F_32 ( V_170 -> V_35 [ 3 ] ) ;
else
V_35 [ 3 ] = ( V_41 T_4 ) V_170 -> V_35 [ 3 ] ;
V_68 [ 0 ] . V_134 = F_33 ( V_170 -> V_98 ) ;
break;
case V_175 :
V_35 [ 0 ] = F_32 ( ( V_114 << 4 ) |
( V_170 -> V_32 << 16 ) ) ;
V_35 [ 1 ] = F_32 ( V_170 -> V_35 [ 1 ] ) ;
V_35 [ 2 ] = F_32 ( V_170 -> V_35 [ 2 ] ) ;
V_68 [ 0 ] . V_134 = F_33 ( 12 ) ;
if ( F_90 ( & V_170 -> V_35 [ 1 ] ) )
V_68 [ 0 ] . V_135 |= F_33 ( V_176 ) ;
break;
case V_177 :
V_35 [ 0 ] = F_32 ( ( V_170 -> V_35 [ 0 ] & 0xffff ) |
( V_170 -> V_32 << 16 ) ) ;
V_35 [ 1 ] = F_32 ( V_170 -> V_35 [ 0 ] & 0xffff0000 ) ;
V_68 [ 0 ] . V_134 = F_33 ( 8 ) ;
break;
default:
V_170 -> V_110 = V_173 ;
return - 1 ;
}
F_91 ( sizeof( struct V_172 ) > sizeof( struct V_67 ) ) ;
V_172 = (struct V_172 * ) & V_68 [ 3 ] ;
V_172 -> V_170 = V_170 ;
V_170 -> V_172 = V_172 ;
if ( V_170 -> V_99 > 0 ) {
if ( V_170 -> V_99 > sizeof( V_172 -> V_178 ) ) {
V_171 = F_92 ( V_4 -> V_3 . V_10 ,
V_170 -> V_109 ,
V_170 -> V_99 ,
V_179 ) ;
if ( F_63 ( V_4 -> V_3 . V_10 , V_171 ) ) {
V_170 -> V_110 = V_173 ;
return - 1 ;
}
V_170 -> V_171 = V_171 ;
V_170 -> V_180 = true ;
} else {
memcpy ( V_172 -> V_178 , V_170 -> V_109 ,
V_170 -> V_99 ) ;
V_171 = V_165 + 3 * sizeof( * V_68 ) ;
}
V_68 [ 2 ] . V_134 = F_33 ( V_170 -> V_99 ) ;
V_68 [ 2 ] . V_139 = F_32 ( V_171 ) ;
V_85 = & V_68 [ 2 ] ;
V_141 = 3 ;
} else {
V_85 = & V_68 [ 0 ] ;
V_141 = 2 ;
}
V_85 -> V_135 |= F_33 ( V_162 |
V_181 |
V_138 ) ;
if ( V_4 -> V_27 != V_170 -> V_27 ) {
if ( V_170 -> V_180 )
F_93 ( V_4 -> V_3 . V_10 , V_171 ,
V_170 -> V_99 , V_179 ) ;
V_170 -> V_110 = V_182 ;
return - 1 ;
}
F_85 ( V_64 , V_68 , V_141 , 4 - V_141 ) ;
if ( V_64 -> V_167 )
F_11 ( V_4 , F_35 ( V_64 -> V_75 ) , V_76 ) ;
else
F_84 ( V_64 , 0 ) ;
return 0 ;
}
static void F_94 ( struct V_143 * V_64 )
{
F_95 ( & V_64 -> V_126 ) ;
V_64 -> V_183 = true ;
F_69 ( ( unsigned long ) V_64 ) ;
V_64 -> V_183 = false ;
F_96 ( & V_64 -> V_126 ) ;
}
static int F_97 ( struct V_143 * V_143 ,
struct V_67 * V_68 ,
struct V_67 * V_85 )
{
struct V_172 * V_172 ;
struct V_91 * V_170 ;
struct V_1 * V_4 = V_143 -> V_4 ;
int V_5 ;
if ( V_85 -> V_73 == 0 && ! V_143 -> V_183 )
return 0 ;
V_172 = (struct V_172 * ) & V_68 [ 3 ] ;
V_170 = V_172 -> V_170 ;
if ( V_170 == NULL )
return 1 ;
if ( V_170 -> V_180 )
F_93 ( V_4 -> V_3 . V_10 , V_170 -> V_171 ,
V_170 -> V_99 , V_179 ) ;
V_5 = F_48 ( V_85 -> V_73 ) & 0x1f ;
V_170 -> V_111 = F_48 ( V_85 -> V_71 ) ;
F_7 ( V_4 , 'T' , V_170 -> V_32 , V_170 -> V_35 , V_5 ) ;
switch ( V_5 ) {
case V_184 :
V_170 -> V_110 = V_185 ;
break;
case V_186 :
V_170 -> V_110 = V_182 ;
break;
case V_187 :
if ( V_143 -> V_183 )
V_170 -> V_110 = V_182 ;
else {
V_170 -> V_110 = V_188 ;
}
break;
case V_115 + 0x10 :
case V_189 + 0x10 :
case V_190 + 0x10 :
case V_191 + 0x10 :
case V_192 + 0x10 :
case V_193 + 0x10 :
case V_194 + 0x10 :
V_170 -> V_110 = V_5 - 0x10 ;
break;
case V_113 :
if ( V_143 -> V_183 ) {
V_170 -> V_110 = V_182 ;
break;
}
default:
V_170 -> V_110 = V_173 ;
break;
}
V_170 -> V_153 ( V_170 , & V_4 -> V_3 , V_170 -> V_110 ) ;
return 1 ;
}
static void F_98 ( struct V_1 * V_4 ,
struct V_91 * V_170 , T_1 V_195 )
{
struct V_91 V_196 ;
int V_36 , V_94 , V_50 ;
V_36 = F_99 ( V_170 -> V_35 [ 0 ] ) ;
if ( F_89 ( V_36 ) )
V_94 = F_100 ( V_170 -> V_35 [ 3 ] ) ;
else
V_94 = 4 ;
V_50 = V_195 - V_197 ;
if ( V_50 + V_94 > V_198 ) {
F_101 ( & V_196 , V_170 -> V_35 ,
V_199 , NULL , 0 ) ;
} else if ( ! F_102 ( V_36 ) ) {
F_101 ( & V_196 , V_170 -> V_35 ,
V_200 , NULL , 0 ) ;
} else {
F_101 ( & V_196 , V_170 -> V_35 , V_201 ,
( void * ) V_4 -> V_202 + V_50 , V_94 ) ;
}
F_54 ( & V_4 -> V_3 , & V_196 ) ;
}
static void F_103 ( struct V_1 * V_4 ,
struct V_91 * V_170 , T_1 V_195 )
{
struct V_91 V_196 ;
int V_36 , V_94 , V_203 , V_204 , V_205 ;
V_42 * V_109 , V_206 ;
T_1 V_207 , V_208 ;
V_36 = F_99 ( V_170 -> V_35 [ 0 ] ) ;
V_94 = F_100 ( V_170 -> V_35 [ 3 ] ) ;
V_109 = V_170 -> V_109 ;
V_203 = F_104 ( V_170 -> V_35 [ 3 ] ) ;
if ( V_36 == V_103 &&
V_203 == V_209 && V_94 == 8 ) {
V_207 = F_10 ( V_109 [ 0 ] ) ;
V_208 = F_10 ( V_109 [ 1 ] ) ;
} else if ( V_36 == V_107 ) {
V_207 = 0 ;
V_208 = 0 ;
} else {
F_101 ( & V_196 , V_170 -> V_35 ,
V_200 , NULL , 0 ) ;
goto V_210;
}
V_204 = ( V_195 - V_211 ) / 4 ;
F_11 ( V_4 , V_212 , V_208 ) ;
F_11 ( V_4 , V_213 , V_207 ) ;
F_11 ( V_4 , V_214 , V_204 ) ;
for ( V_205 = 0 ; V_205 < 20 ; V_205 ++ )
if ( F_13 ( V_4 , V_214 ) & 0x80000000 ) {
V_206 = F_105 ( F_13 ( V_4 ,
V_212 ) ) ;
F_101 ( & V_196 , V_170 -> V_35 ,
V_201 ,
& V_206 , sizeof( V_206 ) ) ;
goto V_210;
}
F_20 ( V_4 -> V_3 . V_10 , L_42 ) ;
F_101 ( & V_196 , V_170 -> V_35 , V_215 , NULL , 0 ) ;
V_210:
F_54 ( & V_4 -> V_3 , & V_196 ) ;
}
static void F_106 ( struct V_143 * V_64 , struct V_91 * V_170 )
{
T_6 V_44 , V_195 ;
if ( V_64 == & V_64 -> V_4 -> V_216 ) {
V_170 -> V_110 = V_189 ;
V_170 -> V_153 ( V_170 , & V_64 -> V_4 -> V_3 , V_170 -> V_110 ) ;
}
V_44 =
( ( unsigned long long )
F_107 ( V_170 -> V_35 [ 1 ] ) << 32 ) |
V_170 -> V_35 [ 2 ] ;
V_195 = V_44 - V_217 ;
if ( V_195 >= V_197 && V_195 < V_218 )
F_98 ( V_64 -> V_4 , V_170 , V_195 ) ;
else switch ( V_195 ) {
case V_211 :
case V_219 :
case V_220 :
case V_221 :
F_103 ( V_64 -> V_4 , V_170 , V_195 ) ;
break;
default:
if ( V_64 == & V_64 -> V_4 -> V_216 )
F_53 ( & V_64 -> V_4 -> V_3 , V_170 ) ;
else
F_54 ( & V_64 -> V_4 -> V_3 , V_170 ) ;
break;
}
if ( V_64 == & V_64 -> V_4 -> V_222 ) {
V_170 -> V_110 = V_115 ;
V_170 -> V_153 ( V_170 , & V_64 -> V_4 -> V_3 , V_170 -> V_110 ) ;
}
}
static void F_108 ( struct V_143 * V_64 , struct V_91 * V_170 )
{
unsigned long V_154 ;
int V_58 ;
F_72 ( & V_64 -> V_4 -> V_155 , V_154 ) ;
if ( F_109 ( V_170 -> V_35 [ 0 ] ) == V_64 -> V_4 -> V_30 &&
V_64 -> V_4 -> V_27 == V_170 -> V_27 ) {
F_74 ( & V_64 -> V_4 -> V_155 , V_154 ) ;
F_106 ( V_64 , V_170 ) ;
return;
}
V_58 = F_88 ( V_64 , V_170 ) ;
F_74 ( & V_64 -> V_4 -> V_155 , V_154 ) ;
if ( V_58 < 0 )
V_170 -> V_153 ( V_170 , & V_64 -> V_4 -> V_3 , V_170 -> V_110 ) ;
}
static void F_110 ( struct V_1 * V_4 ,
const char * V_223 , unsigned int V_75 )
{
T_1 V_224 ;
V_224 = F_13 ( V_4 , F_35 ( V_75 ) ) ;
if ( V_224 & V_225 )
F_20 ( V_4 -> V_3 . V_10 ,
L_43 ,
V_223 , V_39 [ V_224 & 0x1f ] ) ;
}
static void F_111 ( struct V_1 * V_4 )
{
unsigned int V_50 ;
char V_223 [ 8 ] ;
F_110 ( V_4 , L_44 , V_226 ) ;
F_110 ( V_4 , L_45 , V_227 ) ;
F_110 ( V_4 , L_46 , V_228 ) ;
F_110 ( V_4 , L_47 , V_229 ) ;
for ( V_50 = 0 ; V_50 < 32 ; ++ V_50 ) {
if ( ! ( V_4 -> V_230 & ( 1 << V_50 ) ) )
continue;
sprintf ( V_223 , L_48 , V_50 ) ;
F_110 ( V_4 , V_223 , F_112 ( V_50 ) ) ;
}
for ( V_50 = 0 ; V_50 < 32 ; ++ V_50 ) {
if ( ! ( V_4 -> V_231 & ( 1 << V_50 ) ) )
continue;
sprintf ( V_223 , L_49 , V_50 ) ;
F_110 ( V_4 , V_223 , F_113 ( V_50 ) ) ;
}
}
static T_1 F_114 ( T_1 V_232 )
{
T_1 V_233 ;
V_233 = V_232 & 0xfff ;
V_233 += 3072 * ( ( V_232 >> 12 ) & 0x1fff ) ;
V_233 += ( 3072 * 8000 ) * ( V_232 >> 25 ) ;
return V_233 ;
}
static T_1 F_115 ( struct V_1 * V_4 )
{
T_1 V_234 , V_235 , V_236 ;
T_1 V_237 , V_238 , V_239 ;
T_7 V_240 , V_241 ;
int V_50 ;
V_236 = F_13 ( V_4 , V_242 ) ;
if ( V_4 -> V_116 & V_243 ) {
V_50 = 0 ;
V_235 = V_236 ;
V_236 = F_13 ( V_4 , V_242 ) ;
do {
V_234 = V_235 ;
V_235 = V_236 ;
V_236 = F_13 ( V_4 , V_242 ) ;
V_237 = F_114 ( V_234 ) ;
V_238 = F_114 ( V_235 ) ;
V_239 = F_114 ( V_236 ) ;
V_240 = V_238 - V_237 ;
V_241 = V_239 - V_238 ;
} while ( ( V_240 <= 0 || V_241 <= 0 ||
V_240 / V_241 >= 2 || V_241 / V_240 >= 2 )
&& V_50 ++ < 20 );
}
return V_236 ;
}
static T_1 F_116 ( struct V_1 * V_4 )
{
T_1 V_244 = F_115 ( V_4 ) >> 25 ;
if ( ( V_4 -> V_245 & 0x40 ) != ( V_244 & 0x40 ) )
V_4 -> V_245 += 0x40 ;
return V_4 -> V_245 | V_244 ;
}
static int F_117 ( struct V_1 * V_4 , int V_246 )
{
int V_168 ;
F_26 ( & V_4 -> V_62 ) ;
V_168 = F_21 ( V_4 , 7 , V_246 ) ;
if ( V_168 >= 0 )
V_168 = F_16 ( V_4 , 8 ) ;
F_27 ( & V_4 -> V_62 ) ;
if ( V_168 < 0 )
return V_168 ;
switch ( V_168 & 0x0f ) {
case 0x06 :
return 2 ;
case 0x0e :
return 3 ;
}
return 1 ;
}
static int F_118 ( struct V_1 * V_4 , T_1 V_247 ,
int V_28 )
{
int V_50 ;
T_1 V_248 ;
for ( V_50 = 0 ; V_50 < V_28 ; V_50 ++ ) {
V_248 = V_4 -> V_31 [ V_50 ] ;
if ( ( V_247 & 0xff000000 ) == ( V_248 & 0xff000000 ) )
return - 1 ;
if ( ( V_247 & 0xff000000 ) < ( V_248 & 0xff000000 ) )
return V_50 ;
}
return V_50 ;
}
static int F_119 ( struct V_1 * V_4 , int V_28 )
{
int V_168 , V_50 , V_249 , V_93 ;
T_1 V_247 = 0x8040c800 ;
V_168 = F_13 ( V_4 , V_250 ) ;
if ( ! ( V_168 & V_251 ) ) {
F_4 ( V_4 -> V_3 . V_10 ,
L_50 ) ;
return - V_54 ;
}
V_247 |= ( ( V_168 & 0x3f ) << 24 ) ;
V_168 = F_25 ( & V_4 -> V_3 , 4 ) ;
if ( V_168 < 0 )
return V_168 ;
V_247 |= ( ( V_168 & 0x07 ) << 8 ) ;
V_168 = F_25 ( & V_4 -> V_3 , 1 ) ;
if ( V_168 < 0 )
return V_168 ;
V_247 |= ( ( V_168 & 0x3f ) << 16 ) ;
for ( V_50 = 0 ; V_50 < 3 ; V_50 ++ ) {
V_93 = F_117 ( V_4 , V_50 ) ;
if ( V_93 < 0 )
return V_93 ;
V_247 |= ( ( V_93 & 0x3 ) << ( 6 - ( V_50 * 2 ) ) ) ;
}
V_249 = F_118 ( V_4 , V_247 , V_28 ) ;
if ( V_249 >= 0 ) {
memmove ( & ( V_4 -> V_31 [ V_249 + 1 ] ) ,
& ( V_4 -> V_31 [ V_249 ] ) ,
( V_28 - V_249 ) * sizeof( * V_4 -> V_31 ) ) ;
V_4 -> V_31 [ V_249 ] = V_247 ;
V_28 ++ ;
}
return V_28 ;
}
static void F_120 ( struct V_252 * V_253 )
{
struct V_1 * V_4 =
F_1 ( V_253 , struct V_1 , F_120 ) ;
int V_28 , V_50 , V_254 , V_168 ;
int V_27 , V_255 ;
unsigned long V_154 ;
void * V_256 = NULL ;
T_2 V_257 = 0 ;
bool V_258 ;
V_168 = F_13 ( V_4 , V_250 ) ;
if ( ! ( V_168 & V_251 ) ) {
F_4 ( V_4 -> V_3 . V_10 ,
L_50 ) ;
return;
}
if ( ( V_168 & V_259 ) == 63 ) {
F_4 ( V_4 -> V_3 . V_10 , L_51 ) ;
return;
}
V_4 -> V_30 = V_168 & ( V_260 |
V_259 ) ;
V_258 = ( V_168 & V_261 ) != 0 ;
if ( ! ( V_4 -> V_262 && V_258 ) )
F_11 ( V_4 , V_263 ,
V_264 ) ;
V_4 -> V_262 = V_258 ;
V_168 = F_13 ( V_4 , V_265 ) ;
if ( V_168 & V_266 ) {
F_4 ( V_4 -> V_3 . V_10 , L_52 ) ;
return;
}
V_28 = ( V_168 >> 3 ) & 0xff ;
if ( V_28 > 252 ) {
F_4 ( V_4 -> V_3 . V_10 , L_52 ) ;
return;
}
V_27 = ( F_52 ( V_4 -> V_267 [ 0 ] ) >> 16 ) & 0xff ;
F_47 () ;
for ( V_50 = 1 , V_254 = 0 ; V_254 < V_28 ; V_50 += 2 , V_254 ++ ) {
if ( V_4 -> V_267 [ V_50 ] != ~ V_4 -> V_267 [ V_50 + 1 ] ) {
if ( F_52 ( V_4 -> V_267 [ V_50 ] )
== 0xffff008f ) {
F_4 ( V_4 -> V_3 . V_10 ,
L_53 ) ;
V_28 = V_254 ;
break;
} else {
F_4 ( V_4 -> V_3 . V_10 ,
L_52 ) ;
return;
}
}
V_4 -> V_31 [ V_254 ] =
F_52 ( V_4 -> V_267 [ V_50 ] ) ;
}
if ( V_4 -> V_116 & V_268 ) {
V_28 = F_119 ( V_4 , V_28 ) ;
if ( V_28 < 0 ) {
F_4 ( V_4 -> V_3 . V_10 ,
L_54 ) ;
return;
}
}
if ( V_28 == 0 ) {
F_4 ( V_4 -> V_3 . V_10 , L_52 ) ;
return;
}
F_47 () ;
V_255 = ( F_13 ( V_4 , V_265 ) >> 16 ) & 0xff ;
if ( V_255 != V_27 ) {
F_4 ( V_4 -> V_3 . V_10 ,
L_55 ) ;
return;
}
F_72 ( & V_4 -> V_155 , V_154 ) ;
V_4 -> V_27 = - 1 ;
F_86 ( & V_4 -> V_216 ) ;
F_86 ( & V_4 -> V_222 ) ;
F_74 ( & V_4 -> V_155 , V_154 ) ;
F_94 ( & V_4 -> V_216 ) ;
F_94 ( & V_4 -> V_222 ) ;
F_72 ( & V_4 -> V_155 , V_154 ) ;
V_4 -> V_27 = V_27 ;
F_11 ( V_4 , V_269 , V_9 ) ;
if ( V_4 -> V_116 & V_117 )
V_4 -> V_112 = V_27 ;
if ( V_4 -> V_270 != NULL ) {
if ( V_4 -> V_270 != V_4 -> V_202 ) {
V_256 = V_4 -> V_202 ;
V_257 = V_4 -> V_271 ;
}
V_4 -> V_202 = V_4 -> V_270 ;
V_4 -> V_271 = V_4 -> V_272 ;
V_4 -> V_270 = NULL ;
F_11 ( V_4 , V_273 ,
F_10 ( V_4 -> V_202 [ 2 ] ) ) ;
V_4 -> V_202 [ 0 ] = V_4 -> V_274 ;
F_11 ( V_4 , V_275 ,
F_10 ( V_4 -> V_274 ) ) ;
}
#ifdef F_121
F_11 ( V_4 , V_276 , ~ 0 ) ;
F_11 ( V_4 , V_277 , ~ 0 ) ;
#endif
F_74 ( & V_4 -> V_155 , V_154 ) ;
if ( V_256 )
F_82 ( V_4 -> V_3 . V_10 , V_198 ,
V_256 , V_257 ) ;
F_6 ( V_4 , V_27 , V_28 ) ;
F_122 ( & V_4 -> V_3 , V_4 -> V_30 , V_27 ,
V_28 , V_4 -> V_31 ,
V_4 -> V_278 ) ;
V_4 -> V_278 = false ;
}
static T_8 F_123 ( int V_279 , void * V_45 )
{
struct V_1 * V_4 = V_45 ;
T_1 V_280 , V_281 ;
int V_50 ;
V_280 = F_13 ( V_4 , V_269 ) ;
if ( ! V_280 || ! ~ V_280 )
return V_282 ;
F_11 ( V_4 , V_269 ,
V_280 & ~ ( V_9 | V_18 ) ) ;
F_2 ( V_4 , V_280 ) ;
if ( V_280 & V_11 )
F_124 ( V_283 , & V_4 -> F_120 ) ;
if ( V_280 & V_12 )
F_125 ( & V_4 -> V_118 . V_126 ) ;
if ( V_280 & V_13 )
F_125 ( & V_4 -> V_284 . V_126 ) ;
if ( V_280 & V_14 )
F_125 ( & V_4 -> V_216 . V_126 ) ;
if ( V_280 & V_15 )
F_125 ( & V_4 -> V_222 . V_126 ) ;
if ( V_280 & V_16 ) {
V_281 = F_13 ( V_4 , V_285 ) ;
F_11 ( V_4 , V_285 , V_281 ) ;
while ( V_281 ) {
V_50 = F_126 ( V_281 ) - 1 ;
F_125 (
& V_4 -> V_286 [ V_50 ] . V_143 . V_126 ) ;
V_281 &= ~ ( 1 << V_50 ) ;
}
}
if ( V_280 & V_17 ) {
V_281 = F_13 ( V_4 , V_287 ) ;
F_11 ( V_4 , V_287 , V_281 ) ;
while ( V_281 ) {
V_50 = F_126 ( V_281 ) - 1 ;
F_125 (
& V_4 -> V_288 [ V_50 ] . V_143 . V_126 ) ;
V_281 &= ~ ( 1 << V_50 ) ;
}
}
if ( F_8 ( V_280 & V_22 ) )
F_20 ( V_4 -> V_3 . V_10 , L_56 ) ;
if ( F_8 ( V_280 & V_18 ) ) {
F_13 ( V_4 , V_289 ) ;
F_13 ( V_4 , V_290 ) ;
F_11 ( V_4 , V_269 ,
V_18 ) ;
if ( F_127 () )
F_20 ( V_4 -> V_3 . V_10 , L_57 ) ;
}
if ( F_8 ( V_280 & V_19 ) ) {
if ( F_127 () )
F_4 ( V_4 -> V_3 . V_10 ,
L_58 ) ;
F_11 ( V_4 , V_263 ,
V_264 ) ;
}
if ( F_8 ( V_280 & V_21 ) ) {
if ( F_127 () )
F_4 ( V_4 -> V_3 . V_10 ,
L_59 ) ;
}
if ( F_8 ( V_280 & V_23 ) )
F_111 ( V_4 ) ;
if ( V_280 & V_20 ) {
F_128 ( & V_4 -> V_155 ) ;
F_116 ( V_4 ) ;
F_129 ( & V_4 -> V_155 ) ;
} else
F_15 ( V_4 ) ;
return V_291 ;
}
static int F_130 ( struct V_1 * V_4 )
{
T_1 V_49 ;
int V_50 ;
F_11 ( V_4 , V_292 , V_293 ) ;
for ( V_50 = 0 ; V_50 < 500 ; V_50 ++ ) {
V_49 = F_13 ( V_4 , V_292 ) ;
if ( ! ~ V_49 )
return - V_52 ;
if ( ! ( V_49 & V_293 ) )
return 0 ;
F_19 ( 1 ) ;
}
return - V_54 ;
}
static void F_131 ( V_42 * V_294 , const V_42 * V_295 , T_9 V_94 )
{
T_9 V_296 = V_94 * 4 ;
memcpy ( V_294 , V_295 , V_296 ) ;
if ( V_296 < V_198 )
memset ( & V_294 [ V_94 ] , 0 , V_198 - V_296 ) ;
}
static int F_132 ( struct V_1 * V_4 )
{
bool V_297 ;
int V_58 , V_298 , V_299 , V_44 ;
if ( ! ( F_13 ( V_4 , V_292 ) &
V_300 ) )
return 0 ;
V_297 = false ;
V_58 = F_16 ( V_4 , 2 ) ;
if ( V_58 < 0 )
return V_58 ;
if ( ( V_58 & V_301 ) == V_301 ) {
V_58 = F_24 ( V_4 , 1 , 8 ) ;
if ( V_58 < 0 )
return V_58 ;
if ( V_58 >= 1 )
V_297 = true ;
}
if ( V_4 -> V_116 & V_302 )
V_297 = false ;
if ( V_297 ) {
V_298 = 0 ;
V_299 = V_303 | V_304 ;
} else {
V_298 = V_303 | V_304 ;
V_299 = 0 ;
}
V_58 = F_23 ( V_4 , 5 , V_298 , V_299 ) ;
if ( V_58 < 0 )
return V_58 ;
if ( V_297 )
V_44 = V_292 ;
else
V_44 = V_305 ;
F_11 ( V_4 , V_44 , V_306 ) ;
F_11 ( V_4 , V_305 ,
V_300 ) ;
return 0 ;
}
static int F_133 ( struct V_1 * V_4 )
{
static const T_10 V_307 [] = { 0x08 , 0x00 , 0x28 , 0x83 , 0x30 , 0x05 , } ;
int V_168 , V_50 ;
V_168 = F_16 ( V_4 , 2 ) ;
if ( V_168 < 0 )
return V_168 ;
if ( ( V_168 & V_301 ) != V_301 )
return 0 ;
for ( V_50 = F_9 ( V_307 ) - 1 ; V_50 >= 0 ; V_50 -- ) {
V_168 = F_24 ( V_4 , 1 , V_50 + 10 ) ;
if ( V_168 < 0 )
return V_168 ;
if ( V_168 != V_307 [ V_50 ] )
return 0 ;
}
return 1 ;
}
static int F_134 ( struct V_2 * V_3 ,
const V_42 * V_202 , T_9 V_94 )
{
struct V_1 * V_4 = V_1 ( V_3 ) ;
struct V_308 * V_309 = F_135 ( V_3 -> V_10 ) ;
T_1 V_310 , V_311 , V_312 , V_313 ;
int V_50 , V_58 ;
if ( F_130 ( V_4 ) ) {
F_20 ( V_3 -> V_10 , L_60 ) ;
return - V_54 ;
}
F_11 ( V_4 , V_292 ,
V_314 |
V_315 ) ;
F_15 ( V_4 ) ;
for ( V_310 = 0 , V_50 = 0 ; ! V_310 && V_50 < 3 ; V_50 ++ ) {
F_19 ( 50 ) ;
V_310 = F_13 ( V_4 , V_292 ) &
V_314 ;
}
if ( ! V_310 ) {
F_20 ( V_3 -> V_10 , L_61 ) ;
return - V_316 ;
}
if ( V_4 -> V_116 & V_268 ) {
V_58 = F_133 ( V_4 ) ;
if ( V_58 < 0 )
return V_58 ;
if ( V_58 )
F_4 ( V_3 -> V_10 , L_62 ) ;
else
V_4 -> V_116 &= ~ V_268 ;
}
F_11 ( V_4 , V_305 ,
V_317 ) ;
F_11 ( V_4 , V_318 , V_4 -> V_319 ) ;
F_11 ( V_4 , V_263 ,
V_320 |
V_264 ) ;
F_11 ( V_4 , V_321 ,
V_322 |
( V_323 << 4 ) |
( V_324 << 8 ) |
( 200 << 16 ) ) ;
V_311 = F_136 ( F_137 () ) ;
F_11 ( V_4 , V_242 , V_311 << 25 ) ;
V_4 -> V_245 = V_311 & ~ 0x3f ;
V_312 = F_13 ( V_4 , V_47 ) & 0x00ff00ff ;
if ( V_312 >= V_325 ) {
F_11 ( V_4 , V_326 ,
0xfffffffe ) ;
V_3 -> V_327 = true ;
}
F_11 ( V_4 , V_328 , 0x3f ) ;
V_4 -> V_329 = F_13 ( V_4 , V_328 ) & 0x3f ;
F_11 ( V_4 , V_328 , 0 ) ;
V_3 -> V_330 = V_4 -> V_329 != 0 ;
F_11 ( V_4 , V_331 , 0x00010000 ) ;
F_11 ( V_4 , V_269 , ~ 0 ) ;
F_11 ( V_4 , V_332 , ~ 0 ) ;
V_58 = F_132 ( V_4 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_28 ( V_3 , 4 , 0 , V_333 | V_334 ) ;
if ( V_58 < 0 )
return V_58 ;
if ( V_202 ) {
V_4 -> V_270 =
F_76 ( V_4 -> V_3 . V_10 , V_198 ,
& V_4 -> V_272 ,
V_127 ) ;
if ( V_4 -> V_270 == NULL )
return - V_140 ;
F_131 ( V_4 -> V_270 , V_202 , V_94 ) ;
} else {
V_4 -> V_270 = V_4 -> V_202 ;
V_4 -> V_272 = V_4 -> V_271 ;
}
V_4 -> V_274 = V_4 -> V_270 [ 0 ] ;
V_4 -> V_270 [ 0 ] = 0 ;
F_11 ( V_4 , V_275 , 0 ) ;
F_11 ( V_4 , V_273 ,
F_10 ( V_4 -> V_270 [ 2 ] ) ) ;
F_11 ( V_4 , V_335 , V_4 -> V_272 ) ;
F_11 ( V_4 , V_336 , 0x80000000 ) ;
if ( ! ( V_4 -> V_116 & V_337 ) )
F_138 ( V_309 ) ;
if ( F_139 ( V_309 -> V_279 , F_123 ,
F_140 ( V_309 ) ? 0 : V_338 ,
V_339 , V_4 ) ) {
F_20 ( V_3 -> V_10 , L_63 ,
V_309 -> V_279 ) ;
F_141 ( V_309 ) ;
if ( V_202 ) {
F_82 ( V_4 -> V_3 . V_10 , V_198 ,
V_4 -> V_270 ,
V_4 -> V_272 ) ;
V_4 -> V_270 = NULL ;
}
return - V_316 ;
}
V_313 = V_14 | V_15 |
V_12 | V_13 |
V_17 | V_16 |
V_18 |
V_11 |
V_22 |
V_20 |
V_21 |
V_23 |
V_19 |
V_340 ;
if ( V_6 & V_8 )
V_313 |= V_9 ;
F_11 ( V_4 , V_341 , V_313 ) ;
F_11 ( V_4 , V_292 ,
V_342 |
V_343 ) ;
F_11 ( V_4 , V_263 ,
V_344 |
V_345 ) ;
F_66 ( & V_4 -> V_118 ) ;
F_66 ( & V_4 -> V_284 ) ;
F_15 ( V_4 ) ;
F_142 ( & V_4 -> V_3 , false , true ) ;
return 0 ;
}
static int F_143 ( struct V_2 * V_3 ,
const V_42 * V_202 , T_9 V_94 )
{
struct V_1 * V_4 ;
unsigned long V_154 ;
V_42 * V_270 ;
T_2 V_156 ( V_272 ) ;
V_4 = V_1 ( V_3 ) ;
V_270 =
F_76 ( V_4 -> V_3 . V_10 , V_198 ,
& V_272 , V_127 ) ;
if ( V_270 == NULL )
return - V_140 ;
F_72 ( & V_4 -> V_155 , V_154 ) ;
if ( V_4 -> V_270 == NULL ) {
V_4 -> V_270 = V_270 ;
V_4 -> V_272 = V_272 ;
V_270 = NULL ;
}
F_131 ( V_4 -> V_270 , V_202 , V_94 ) ;
V_4 -> V_274 = V_202 [ 0 ] ;
V_4 -> V_270 [ 0 ] = 0 ;
F_11 ( V_4 , V_335 , V_4 -> V_272 ) ;
F_74 ( & V_4 -> V_155 , V_154 ) ;
if ( V_270 != NULL )
F_82 ( V_4 -> V_3 . V_10 , V_198 ,
V_270 , V_272 ) ;
F_142 ( & V_4 -> V_3 , true , true ) ;
return 0 ;
}
static void F_144 ( struct V_2 * V_3 , struct V_91 * V_170 )
{
struct V_1 * V_4 = V_1 ( V_3 ) ;
F_108 ( & V_4 -> V_216 , V_170 ) ;
}
static void F_145 ( struct V_2 * V_3 , struct V_91 * V_170 )
{
struct V_1 * V_4 = V_1 ( V_3 ) ;
F_108 ( & V_4 -> V_222 , V_170 ) ;
}
static int F_146 ( struct V_2 * V_3 , struct V_91 * V_170 )
{
struct V_1 * V_4 = V_1 ( V_3 ) ;
struct V_143 * V_64 = & V_4 -> V_216 ;
struct V_172 * V_172 = V_170 -> V_172 ;
int V_58 = - V_346 ;
F_95 ( & V_64 -> V_126 ) ;
if ( V_170 -> V_110 != 0 )
goto V_210;
if ( V_170 -> V_180 )
F_93 ( V_4 -> V_3 . V_10 , V_170 -> V_171 ,
V_170 -> V_99 , V_179 ) ;
F_7 ( V_4 , 'T' , V_170 -> V_32 , V_170 -> V_35 , 0x20 ) ;
V_172 -> V_170 = NULL ;
V_170 -> V_110 = V_185 ;
V_170 -> V_153 ( V_170 , & V_4 -> V_3 , V_170 -> V_110 ) ;
V_58 = 0 ;
V_210:
F_96 ( & V_64 -> V_126 ) ;
return V_58 ;
}
static int F_147 ( struct V_2 * V_3 ,
int V_30 , int V_27 )
{
#ifdef F_121
return 0 ;
#else
struct V_1 * V_4 = V_1 ( V_3 ) ;
unsigned long V_154 ;
int V_347 , V_58 = 0 ;
F_72 ( & V_4 -> V_155 , V_154 ) ;
if ( V_4 -> V_27 != V_27 ) {
V_58 = - V_348 ;
goto V_210;
}
V_347 = ( V_30 & 0xffc0 ) == V_349 ? V_30 & 0x3f : 63 ;
if ( V_347 < 32 )
F_11 ( V_4 , V_277 , 1 << V_347 ) ;
else
F_11 ( V_4 , V_276 , 1 << ( V_347 - 32 ) ) ;
F_15 ( V_4 ) ;
V_210:
F_74 ( & V_4 -> V_155 , V_154 ) ;
return V_58 ;
#endif
}
static T_1 F_148 ( struct V_2 * V_3 , int V_350 )
{
struct V_1 * V_4 = V_1 ( V_3 ) ;
unsigned long V_154 ;
T_1 V_351 ;
switch ( V_350 ) {
case V_352 :
case V_353 :
if ( V_4 -> V_262 &&
( F_13 ( V_4 , V_263 ) &
V_264 ) )
V_351 = V_354 ;
else
V_351 = 0 ;
if ( V_4 -> V_278 )
V_351 |= V_355 ;
return V_351 ;
case V_356 :
return F_13 ( V_4 , V_250 ) << 16 ;
case V_357 :
return F_115 ( V_4 ) ;
case V_358 :
F_72 ( & V_4 -> V_155 , V_154 ) ;
V_351 = F_116 ( V_4 ) ;
F_74 ( & V_4 -> V_155 , V_154 ) ;
return V_351 ;
case V_359 :
V_351 = F_13 ( V_4 , V_321 ) ;
return ( V_351 >> 4 ) & 0x0ffff00f ;
case V_360 :
return ( F_13 ( V_4 , V_328 ) & 0x3f ) |
( V_4 -> V_329 << 8 ) ;
default:
F_149 ( 1 ) ;
return 0 ;
}
}
static void F_150 ( struct V_2 * V_3 , int V_350 , T_1 V_351 )
{
struct V_1 * V_4 = V_1 ( V_3 ) ;
unsigned long V_154 ;
switch ( V_350 ) {
case V_352 :
if ( ( V_351 & V_354 ) && V_4 -> V_262 ) {
F_11 ( V_4 , V_361 ,
V_264 ) ;
F_15 ( V_4 ) ;
}
if ( V_351 & V_355 )
V_4 -> V_278 = false ;
break;
case V_353 :
if ( ( V_351 & V_354 ) && V_4 -> V_262 ) {
F_11 ( V_4 , V_263 ,
V_264 ) ;
F_15 ( V_4 ) ;
}
if ( V_351 & V_355 )
V_4 -> V_278 = true ;
break;
case V_356 :
F_11 ( V_4 , V_250 , V_351 >> 16 ) ;
F_15 ( V_4 ) ;
break;
case V_357 :
F_11 ( V_4 , V_242 , V_351 ) ;
F_11 ( V_4 , V_362 ,
V_21 ) ;
F_15 ( V_4 ) ;
break;
case V_358 :
F_72 ( & V_4 -> V_155 , V_154 ) ;
V_4 -> V_245 = ( V_4 -> V_245 & 0x7f ) | ( V_351 & ~ 0x7f ) ;
F_74 ( & V_4 -> V_155 , V_154 ) ;
break;
case V_359 :
V_351 = ( V_351 & 0xf ) | ( ( V_351 & 0xf ) << 4 ) |
( ( V_351 & 0xf ) << 8 ) | ( ( V_351 & 0x0ffff000 ) << 4 ) ;
F_11 ( V_4 , V_321 , V_351 ) ;
F_15 ( V_4 ) ;
break;
case V_360 :
F_11 ( V_4 , V_328 , V_351 & 0x3f ) ;
F_15 ( V_4 ) ;
break;
default:
F_149 ( 1 ) ;
break;
}
}
static void F_151 ( struct V_363 * V_64 )
{
V_64 -> V_364 . V_153 . V_365 ( & V_64 -> V_364 , V_64 -> V_366 ,
V_64 -> V_98 , V_64 -> V_35 ,
V_64 -> V_364 . V_367 ) ;
V_64 -> V_98 = 0 ;
}
static void F_152 ( struct V_363 * V_64 , const T_1 * V_368 )
{
T_1 * V_369 ;
if ( V_64 -> V_98 + V_64 -> V_364 . V_370 > V_72 )
F_151 ( V_64 ) ;
V_369 = V_64 -> V_35 + V_64 -> V_98 ;
V_64 -> V_366 = ( V_371 ) F_71 ( ( V_41 T_4 ) V_368 [ 0 ] ) ;
if ( V_64 -> V_364 . V_370 > 0 )
V_369 [ 0 ] = F_153 ( V_368 [ 1 ] ) ;
if ( V_64 -> V_364 . V_370 > 4 )
V_369 [ 1 ] = F_153 ( V_368 [ 0 ] ) ;
if ( V_64 -> V_364 . V_370 > 8 )
memcpy ( & V_369 [ 2 ] , & V_368 [ 2 ] , V_64 -> V_364 . V_370 - 8 ) ;
V_64 -> V_98 += V_64 -> V_364 . V_370 ;
}
static int F_154 ( struct V_143 * V_143 ,
struct V_67 * V_68 ,
struct V_67 * V_85 )
{
struct V_363 * V_64 =
F_1 ( V_143 , struct V_363 , V_143 ) ;
struct V_67 * V_372 ;
T_1 V_373 ;
for ( V_372 = V_68 ; V_372 <= V_85 ; V_372 ++ )
if ( V_372 -> V_73 )
break;
if ( V_372 > V_85 )
return 0 ;
while ( ! ( V_68 -> V_135 & F_33 ( V_138 ) ) ) {
V_68 ++ ;
V_373 = F_71 ( V_68 -> V_139 ) ;
F_155 ( V_143 -> V_4 -> V_3 . V_10 ,
V_373 & V_374 ,
V_373 & ~ V_374 ,
F_48 ( V_68 -> V_134 ) ,
V_80 ) ;
}
F_152 ( V_64 , ( T_1 * ) ( V_85 + 1 ) ) ;
if ( V_85 -> V_135 & F_33 ( V_181 ) )
F_151 ( V_64 ) ;
return 1 ;
}
static int F_156 ( struct V_143 * V_143 ,
struct V_67 * V_68 ,
struct V_67 * V_85 )
{
struct V_363 * V_64 =
F_1 ( V_143 , struct V_363 , V_143 ) ;
unsigned int V_134 , V_71 , V_375 ;
T_1 V_373 ;
V_134 = F_48 ( V_85 -> V_134 ) ;
V_71 = F_48 ( F_46 ( V_85 -> V_71 ) ) ;
V_375 = V_134 - V_71 ;
V_373 = F_71 ( V_85 -> V_139 ) ;
if ( V_375 > 0 ) {
V_64 -> V_376 = V_373 ;
V_64 -> V_377 = V_375 ;
}
if ( V_71 != 0 )
return 0 ;
F_155 ( V_143 -> V_4 -> V_3 . V_10 ,
V_373 & V_374 ,
V_373 & ~ V_374 ,
V_375 , V_80 ) ;
if ( V_85 -> V_135 & F_33 ( V_181 ) ) {
V_64 -> V_364 . V_153 . V_378 ( & V_64 -> V_364 ,
V_373 + V_375 ,
V_64 -> V_364 . V_367 ) ;
V_64 -> V_377 = 0 ;
}
return 1 ;
}
static void F_157 ( struct V_363 * V_64 )
{
F_155 ( V_64 -> V_143 . V_4 -> V_3 . V_10 ,
V_64 -> V_376 & V_374 ,
V_64 -> V_376 & ~ V_374 ,
V_64 -> V_377 , V_80 ) ;
V_64 -> V_364 . V_153 . V_378 ( & V_64 -> V_364 ,
V_64 -> V_376 + V_64 -> V_377 ,
V_64 -> V_364 . V_367 ) ;
V_64 -> V_377 = 0 ;
}
static inline void F_158 ( struct V_143 * V_143 ,
struct V_67 * V_372 )
{
T_3 V_135 ;
T_1 V_373 ;
if ( V_372 -> V_135 & F_33 ( V_138 ) )
return;
V_372 += 2 ;
if ( ( F_71 ( V_372 -> V_139 ) & V_374 ) ==
( V_143 -> V_150 & V_374 ) ) {
if ( V_372 -> V_135 & F_33 ( V_138 ) )
return;
V_372 ++ ;
}
do {
V_373 = F_71 ( V_372 -> V_139 ) ;
F_155 ( V_143 -> V_4 -> V_3 . V_10 ,
V_373 & V_374 ,
V_373 & ~ V_374 ,
F_48 ( V_372 -> V_134 ) ,
V_179 ) ;
V_135 = V_372 -> V_135 ;
V_372 ++ ;
} while ( ! ( V_135 & F_33 ( V_138 ) ) );
}
static int F_159 ( struct V_143 * V_143 ,
struct V_67 * V_68 ,
struct V_67 * V_85 )
{
struct V_363 * V_64 =
F_1 ( V_143 , struct V_363 , V_143 ) ;
struct V_67 * V_372 ;
V_42 * V_369 ;
for ( V_372 = V_68 ; V_372 <= V_85 ; V_372 ++ )
if ( V_372 -> V_73 )
break;
if ( V_372 > V_85 )
return 0 ;
F_158 ( V_143 , V_68 ) ;
if ( V_64 -> V_98 + 4 > V_72 )
F_151 ( V_64 ) ;
V_369 = V_64 -> V_35 + V_64 -> V_98 ;
V_64 -> V_366 = F_48 ( V_85 -> V_71 ) ;
* V_369 = F_105 ( ( F_48 ( V_372 -> V_73 ) << 16 ) |
F_48 ( V_372 -> V_71 ) ) ;
V_64 -> V_98 += 4 ;
if ( V_85 -> V_135 & F_33 ( V_181 ) )
F_151 ( V_64 ) ;
return 1 ;
}
static void F_160 ( struct V_1 * V_4 , T_6 V_379 )
{
T_1 V_380 = V_379 >> 32 , V_381 = V_379 ;
F_11 ( V_4 , V_382 , ~ V_380 ) ;
F_11 ( V_4 , V_383 , ~ V_381 ) ;
F_11 ( V_4 , V_384 , V_380 ) ;
F_11 ( V_4 , V_385 , V_381 ) ;
F_161 () ;
V_4 -> V_386 = V_379 ;
}
static struct V_387 * F_162 ( struct V_2 * V_3 ,
int type , int V_388 , T_9 V_370 )
{
struct V_1 * V_4 = V_1 ( V_3 ) ;
struct V_363 * V_156 ( V_64 ) ;
T_5 V_156 ( V_153 ) ;
T_6 * V_156 ( V_379 ) ;
T_1 * V_156 ( V_389 ) , V_156 ( V_75 ) ;
unsigned long V_154 ;
int V_66 , V_58 = - V_54 ;
F_72 ( & V_4 -> V_155 , V_154 ) ;
switch ( type ) {
case V_390 :
V_389 = & V_4 -> V_391 ;
V_153 = F_159 ;
V_66 = F_126 ( * V_389 ) - 1 ;
if ( V_66 >= 0 ) {
* V_389 &= ~ ( 1 << V_66 ) ;
V_75 = F_112 ( V_66 ) ;
V_64 = & V_4 -> V_288 [ V_66 ] ;
}
break;
case V_392 :
V_379 = & V_4 -> V_393 ;
V_389 = & V_4 -> V_394 ;
V_153 = F_154 ;
V_66 = * V_379 & 1ULL << V_388 ? F_126 ( * V_389 ) - 1 : - 1 ;
if ( V_66 >= 0 ) {
* V_379 &= ~ ( 1ULL << V_388 ) ;
* V_389 &= ~ ( 1 << V_66 ) ;
V_75 = F_113 ( V_66 ) ;
V_64 = & V_4 -> V_286 [ V_66 ] ;
}
break;
case V_395 :
V_389 = & V_4 -> V_394 ;
V_153 = F_156 ;
V_66 = ! V_4 -> V_396 ? F_126 ( * V_389 ) - 1 : - 1 ;
if ( V_66 >= 0 ) {
V_4 -> V_396 = true ;
* V_389 &= ~ ( 1 << V_66 ) ;
V_75 = F_113 ( V_66 ) ;
V_64 = & V_4 -> V_286 [ V_66 ] ;
}
break;
default:
V_66 = - 1 ;
V_58 = - V_397 ;
}
F_74 ( & V_4 -> V_155 , V_154 ) ;
if ( V_66 < 0 )
return F_163 ( V_58 ) ;
memset ( V_64 , 0 , sizeof( * V_64 ) ) ;
V_64 -> V_98 = 0 ;
V_64 -> V_35 = ( void * ) F_164 ( V_127 ) ;
if ( V_64 -> V_35 == NULL ) {
V_58 = - V_140 ;
goto V_210;
}
V_58 = F_78 ( & V_64 -> V_143 , V_4 , V_75 , V_153 ) ;
if ( V_58 < 0 )
goto V_398;
if ( type == V_395 ) {
F_160 ( V_4 , 0 ) ;
V_64 -> V_377 = 0 ;
}
return & V_64 -> V_364 ;
V_398:
F_165 ( ( unsigned long ) V_64 -> V_35 ) ;
V_210:
F_72 ( & V_4 -> V_155 , V_154 ) ;
switch ( type ) {
case V_392 :
* V_379 |= 1ULL << V_388 ;
break;
case V_395 :
V_4 -> V_396 = false ;
break;
}
* V_389 |= 1 << V_66 ;
F_74 ( & V_4 -> V_155 , V_154 ) ;
return F_163 ( V_58 ) ;
}
static int F_166 ( struct V_387 * V_364 ,
T_7 V_399 , T_1 V_400 , T_1 V_401 )
{
struct V_363 * V_64 = F_1 ( V_364 , struct V_363 , V_364 ) ;
struct V_1 * V_4 = V_64 -> V_143 . V_4 ;
T_1 V_135 = V_402 , V_403 ;
int V_66 ;
if ( V_64 -> V_143 . V_85 -> V_70 == 0 )
return - V_404 ;
switch ( V_64 -> V_364 . type ) {
case V_390 :
V_66 = V_64 - V_4 -> V_288 ;
V_403 = 0 ;
if ( V_399 >= 0 )
V_403 = V_405 |
( V_399 & 0x7fff ) << 16 ;
F_11 ( V_4 , V_287 , 1 << V_66 ) ;
F_11 ( V_4 , V_406 , 1 << V_66 ) ;
F_84 ( & V_64 -> V_143 , V_403 ) ;
break;
case V_395 :
V_135 |= V_407 | V_408 ;
case V_392 :
V_66 = V_64 - V_4 -> V_286 ;
V_403 = ( V_401 << 28 ) | ( V_400 << 8 ) | V_64 -> V_364 . V_388 ;
if ( V_399 >= 0 ) {
V_403 |= ( V_399 & 0x07fff ) << 12 ;
V_135 |= V_409 ;
}
F_11 ( V_4 , V_285 , 1 << V_66 ) ;
F_11 ( V_4 , V_410 , 1 << V_66 ) ;
F_11 ( V_4 , F_167 ( V_64 -> V_143 . V_75 ) , V_403 ) ;
F_84 ( & V_64 -> V_143 , V_135 ) ;
V_64 -> V_400 = V_400 ;
V_64 -> V_401 = V_401 ;
break;
}
return 0 ;
}
static int F_168 ( struct V_387 * V_364 )
{
struct V_1 * V_4 = V_1 ( V_364 -> V_3 ) ;
struct V_363 * V_64 = F_1 ( V_364 , struct V_363 , V_364 ) ;
int V_66 ;
switch ( V_64 -> V_364 . type ) {
case V_390 :
V_66 = V_64 - V_4 -> V_288 ;
F_11 ( V_4 , V_411 , 1 << V_66 ) ;
break;
case V_392 :
case V_395 :
V_66 = V_64 - V_4 -> V_286 ;
F_11 ( V_4 , V_412 , 1 << V_66 ) ;
break;
}
F_15 ( V_4 ) ;
F_86 ( & V_64 -> V_143 ) ;
F_169 ( & V_64 -> V_143 . V_126 ) ;
return 0 ;
}
static void F_170 ( struct V_387 * V_364 )
{
struct V_1 * V_4 = V_1 ( V_364 -> V_3 ) ;
struct V_363 * V_64 = F_1 ( V_364 , struct V_363 , V_364 ) ;
unsigned long V_154 ;
int V_66 ;
F_168 ( V_364 ) ;
F_80 ( & V_64 -> V_143 ) ;
F_165 ( ( unsigned long ) V_64 -> V_35 ) ;
F_72 ( & V_4 -> V_155 , V_154 ) ;
switch ( V_364 -> type ) {
case V_390 :
V_66 = V_64 - V_4 -> V_288 ;
V_4 -> V_391 |= 1 << V_66 ;
break;
case V_392 :
V_66 = V_64 - V_4 -> V_286 ;
V_4 -> V_394 |= 1 << V_66 ;
V_4 -> V_393 |= 1ULL << V_364 -> V_388 ;
break;
case V_395 :
V_66 = V_64 - V_4 -> V_286 ;
V_4 -> V_394 |= 1 << V_66 ;
V_4 -> V_393 |= V_4 -> V_386 ;
V_4 -> V_386 = 0 ;
V_4 -> V_396 = false ;
break;
}
F_74 ( & V_4 -> V_155 , V_154 ) ;
}
static int F_171 ( struct V_387 * V_364 , T_6 * V_379 )
{
struct V_1 * V_4 = V_1 ( V_364 -> V_3 ) ;
unsigned long V_154 ;
int V_58 ;
switch ( V_364 -> type ) {
case V_395 :
F_72 ( & V_4 -> V_155 , V_154 ) ;
if ( ~ V_4 -> V_393 & ~ V_4 -> V_386 & * V_379 ) {
* V_379 = V_4 -> V_393 ;
V_58 = - V_54 ;
} else {
F_160 ( V_4 , * V_379 ) ;
V_58 = 0 ;
}
F_74 ( & V_4 -> V_155 , V_154 ) ;
break;
default:
V_58 = - V_413 ;
}
return V_58 ;
}
static void F_172 ( struct V_1 * V_4 )
{
int V_50 ;
struct V_363 * V_64 ;
for ( V_50 = 0 ; V_50 < V_4 -> V_414 ; V_50 ++ ) {
V_64 = & V_4 -> V_286 [ V_50 ] ;
if ( V_64 -> V_143 . V_167 )
F_166 ( & V_64 -> V_364 , 0 , V_64 -> V_400 , V_64 -> V_401 ) ;
}
for ( V_50 = 0 ; V_50 < V_4 -> V_415 ; V_50 ++ ) {
V_64 = & V_4 -> V_288 [ V_50 ] ;
if ( V_64 -> V_143 . V_167 )
F_166 ( & V_64 -> V_364 , 0 , V_64 -> V_400 , V_64 -> V_401 ) ;
}
}
static int F_173 ( struct V_363 * V_64 ,
struct V_416 * V_170 ,
struct V_417 * V_77 ,
unsigned long V_109 )
{
struct V_67 * V_68 , * V_85 , * V_372 ;
struct V_416 * V_92 ;
T_4 * V_35 ;
T_2 V_165 , V_418 ;
T_1 V_141 , V_419 , V_420 , V_279 ;
T_1 V_421 , V_422 , V_423 ;
int V_60 , V_424 , V_50 , V_94 , V_44 ;
V_92 = V_170 ;
V_421 = V_109 ;
if ( V_92 -> V_425 )
V_141 = 1 ;
else
V_141 = 2 ;
if ( V_92 -> V_98 > 0 )
V_141 ++ ;
V_424 = F_174 ( V_421 + V_92 -> V_99 ) >> V_426 ;
if ( V_92 -> V_99 > 0 )
V_420 = V_424 - ( V_421 >> V_426 ) ;
else
V_420 = 0 ;
V_141 += V_420 ;
V_419 = F_175 ( V_92 -> V_98 , sizeof( * V_68 ) ) ;
V_68 = F_83 ( & V_64 -> V_143 , V_141 + V_419 , & V_165 ) ;
if ( V_68 == NULL )
return - V_140 ;
if ( ! V_92 -> V_425 ) {
V_68 [ 0 ] . V_135 = F_33 ( V_174 ) ;
V_68 [ 0 ] . V_134 = F_33 ( 8 ) ;
V_68 [ 0 ] . V_70 = F_32 ( V_165 | V_141 ) ;
V_35 = ( T_4 * ) & V_68 [ 1 ] ;
V_35 [ 0 ] = F_32 ( F_176 ( V_92 -> V_427 ) |
F_177 ( V_92 -> V_428 ) |
F_178 ( V_177 ) |
F_179 ( V_64 -> V_364 . V_388 ) |
F_180 ( V_64 -> V_364 . V_32 ) ) ;
V_35 [ 1 ] =
F_32 ( F_181 ( V_92 -> V_98 +
V_92 -> V_99 ) ) ;
}
if ( V_92 -> V_98 > 0 ) {
V_68 [ 2 ] . V_134 = F_33 ( V_92 -> V_98 ) ;
V_68 [ 2 ] . V_139 = F_32 ( V_165 + V_141 * sizeof( * V_68 ) ) ;
memcpy ( & V_68 [ V_141 ] , V_92 -> V_35 , V_92 -> V_98 ) ;
}
V_372 = V_68 + V_141 - V_420 ;
V_422 = V_421 + V_92 -> V_99 ;
for ( V_50 = 0 ; V_50 < V_420 ; V_50 ++ ) {
V_60 = V_421 >> V_426 ;
V_44 = V_421 & ~ V_374 ;
V_423 = ( V_60 + 1 ) << V_426 ;
V_94 =
F_182 ( V_423 , V_422 ) - V_421 ;
V_372 [ V_50 ] . V_134 = F_33 ( V_94 ) ;
V_418 = F_30 ( V_77 -> V_65 [ V_60 ] ) ;
V_372 [ V_50 ] . V_139 = F_32 ( V_418 + V_44 ) ;
F_183 ( V_64 -> V_143 . V_4 -> V_3 . V_10 ,
V_418 , V_44 , V_94 ,
V_179 ) ;
V_421 += V_94 ;
}
if ( V_92 -> V_429 )
V_279 = V_181 ;
else
V_279 = V_430 ;
V_85 = V_141 == 2 ? V_68 : V_68 + V_141 - 1 ;
V_85 -> V_135 |= F_33 ( V_162 |
V_137 |
V_138 |
V_279 ) ;
F_85 ( & V_64 -> V_143 , V_68 , V_141 , V_419 ) ;
return 0 ;
}
static int F_184 ( struct V_363 * V_64 ,
struct V_416 * V_170 ,
struct V_417 * V_77 ,
unsigned long V_109 )
{
struct V_10 * V_10 = V_64 -> V_143 . V_4 -> V_3 . V_10 ;
struct V_67 * V_68 , * V_372 ;
T_2 V_165 , V_418 ;
T_1 V_141 , V_419 , V_431 ;
int V_50 , V_254 , V_94 ;
int V_60 , V_44 , V_432 , V_370 , V_433 ;
V_432 = V_170 -> V_98 / V_64 -> V_364 . V_370 ;
V_370 = F_185 ( V_64 -> V_364 . V_370 , ( T_9 ) 8 ) ;
V_419 = F_175 ( V_370 , sizeof( * V_68 ) ) ;
V_60 = V_109 >> V_426 ;
V_44 = V_109 & ~ V_374 ;
V_433 = V_170 -> V_99 / V_432 ;
for ( V_50 = 0 ; V_50 < V_432 ; V_50 ++ ) {
V_141 = F_175 ( V_433 + V_44 , V_72 ) + 1 ;
V_68 = F_83 ( & V_64 -> V_143 ,
V_141 + V_419 , & V_165 ) ;
if ( V_68 == NULL )
return - V_140 ;
V_68 -> V_135 = F_33 ( V_137 |
V_136 ) ;
if ( V_170 -> V_425 && V_50 == 0 )
V_68 -> V_135 |= F_33 ( V_434 ) ;
V_68 -> V_134 = F_33 ( V_370 ) ;
V_68 -> V_71 = V_68 -> V_134 ;
V_68 -> V_73 = 0 ;
V_68 -> V_139 = F_32 ( V_165 + ( V_141 * sizeof( * V_68 ) ) ) ;
V_431 = V_433 ;
V_372 = V_68 ;
for ( V_254 = 1 ; V_254 < V_141 ; V_254 ++ ) {
V_372 ++ ;
V_372 -> V_135 = F_33 ( V_137 |
V_136 ) ;
if ( V_44 + V_431 < V_72 )
V_94 = V_431 ;
else
V_94 = V_72 - V_44 ;
V_372 -> V_134 = F_33 ( V_94 ) ;
V_372 -> V_71 = V_372 -> V_134 ;
V_372 -> V_73 = 0 ;
V_418 = F_30 ( V_77 -> V_65 [ V_60 ] ) ;
V_372 -> V_139 = F_32 ( V_418 + V_44 ) ;
F_183 ( V_10 , V_418 ,
V_44 , V_94 ,
V_80 ) ;
V_44 = ( V_44 + V_94 ) & ~ V_374 ;
V_431 -= V_94 ;
if ( V_44 == 0 )
V_60 ++ ;
}
V_372 -> V_135 = F_33 ( V_137 |
V_435 |
V_138 ) ;
if ( V_170 -> V_429 && V_50 == V_432 - 1 )
V_372 -> V_135 |= F_33 ( V_181 ) ;
F_85 ( & V_64 -> V_143 , V_68 , V_141 , V_419 ) ;
}
return 0 ;
}
static int F_186 ( struct V_363 * V_64 ,
struct V_416 * V_170 ,
struct V_417 * V_77 ,
unsigned long V_109 )
{
struct V_67 * V_68 ;
T_2 V_165 , V_418 ;
int V_60 , V_44 , V_431 , V_141 , V_50 , V_94 ;
V_60 = V_109 >> V_426 ;
V_44 = V_109 & ~ V_374 ;
V_431 = V_170 -> V_99 ;
V_141 = F_175 ( V_44 + V_431 , V_72 ) ;
if ( F_149 ( V_44 & 3 || V_431 & 3 || V_60 + V_141 > V_77 -> V_436 ) )
return - V_437 ;
for ( V_50 = 0 ; V_50 < V_141 ; V_50 ++ ) {
V_68 = F_83 ( & V_64 -> V_143 , 1 , & V_165 ) ;
if ( V_68 == NULL )
return - V_140 ;
V_68 -> V_135 = F_33 ( V_136 |
V_138 ) ;
if ( V_170 -> V_425 && V_50 == 0 )
V_68 -> V_135 |= F_33 ( V_434 ) ;
if ( V_170 -> V_429 && V_50 == V_141 - 1 )
V_68 -> V_135 |= F_33 ( V_181 ) ;
if ( V_44 + V_431 < V_72 )
V_94 = V_431 ;
else
V_94 = V_72 - V_44 ;
V_68 -> V_134 = F_33 ( V_94 ) ;
V_68 -> V_71 = V_68 -> V_134 ;
V_68 -> V_73 = 0 ;
V_418 = F_30 ( V_77 -> V_65 [ V_60 ] ) ;
V_68 -> V_139 = F_32 ( V_418 + V_44 ) ;
F_183 ( V_64 -> V_143 . V_4 -> V_3 . V_10 ,
V_418 , V_44 , V_94 ,
V_80 ) ;
V_431 -= V_94 ;
V_44 = 0 ;
V_60 ++ ;
F_85 ( & V_64 -> V_143 , V_68 , 1 , 0 ) ;
}
return 0 ;
}
static int F_187 ( struct V_387 * V_364 ,
struct V_416 * V_170 ,
struct V_417 * V_77 ,
unsigned long V_109 )
{
struct V_363 * V_64 = F_1 ( V_364 , struct V_363 , V_364 ) ;
unsigned long V_154 ;
int V_58 = - V_397 ;
F_72 ( & V_64 -> V_143 . V_4 -> V_155 , V_154 ) ;
switch ( V_364 -> type ) {
case V_390 :
V_58 = F_173 ( V_64 , V_170 , V_77 , V_109 ) ;
break;
case V_392 :
V_58 = F_184 ( V_64 , V_170 , V_77 , V_109 ) ;
break;
case V_395 :
V_58 = F_186 ( V_64 , V_170 , V_77 , V_109 ) ;
break;
}
F_74 ( & V_64 -> V_143 . V_4 -> V_155 , V_154 ) ;
return V_58 ;
}
static void F_188 ( struct V_387 * V_364 )
{
struct V_143 * V_64 =
& F_1 ( V_364 , struct V_363 , V_364 ) -> V_143 ;
F_11 ( V_64 -> V_4 , F_35 ( V_64 -> V_75 ) , V_76 ) ;
}
static int F_189 ( struct V_387 * V_364 )
{
struct V_363 * V_64 = F_1 ( V_364 , struct V_363 , V_364 ) ;
int V_58 = 0 ;
F_95 ( & V_64 -> V_143 . V_126 ) ;
if ( ! F_190 ( 0 , & V_64 -> V_438 ) ) {
F_69 ( ( unsigned long ) & V_64 -> V_143 ) ;
switch ( V_364 -> type ) {
case V_390 :
case V_392 :
if ( V_64 -> V_98 != 0 )
F_151 ( V_64 ) ;
break;
case V_395 :
if ( V_64 -> V_377 != 0 )
F_157 ( V_64 ) ;
break;
default:
V_58 = - V_397 ;
}
F_191 ( 0 , & V_64 -> V_438 ) ;
F_192 () ;
}
F_96 ( & V_64 -> V_143 . V_126 ) ;
return V_58 ;
}
static void F_193 ( struct V_308 * V_309 )
{
if ( F_194 ( V_439 ) ) {
struct V_440 * V_441 = F_195 ( V_309 ) ;
if ( V_441 ) {
F_196 ( V_442 , V_441 , 0 , 1 ) ;
F_196 ( V_443 , V_441 , 0 , 1 ) ;
}
}
}
static void F_197 ( struct V_308 * V_309 )
{
if ( F_194 ( V_439 ) ) {
struct V_440 * V_441 = F_195 ( V_309 ) ;
if ( V_441 ) {
F_196 ( V_443 , V_441 , 0 , 0 ) ;
F_196 ( V_442 , V_441 , 0 , 0 ) ;
}
}
}
static inline void F_193 ( struct V_308 * V_309 ) {}
static inline void F_197 ( struct V_308 * V_309 ) {}
static int T_11 F_198 ( struct V_308 * V_309 ,
const struct V_444 * V_445 )
{
struct V_1 * V_4 ;
T_1 V_446 , V_447 , V_448 , V_312 ;
T_6 V_449 ;
int V_50 , V_450 ;
T_9 V_296 ;
if ( V_309 -> V_451 == V_452 ) {
F_20 ( & V_309 -> V_309 , L_64 ) ;
return - V_397 ;
}
V_4 = F_199 ( sizeof( * V_4 ) , V_127 ) ;
if ( V_4 == NULL ) {
V_450 = - V_140 ;
goto V_453;
}
F_200 ( & V_4 -> V_3 , & V_454 , & V_309 -> V_309 ) ;
F_193 ( V_309 ) ;
V_450 = F_201 ( V_309 ) ;
if ( V_450 ) {
F_20 ( & V_309 -> V_309 , L_65 ) ;
goto V_455;
}
F_202 ( V_309 ) ;
F_203 ( V_309 , V_456 , 0 ) ;
F_204 ( V_309 , V_4 ) ;
F_205 ( & V_4 -> V_155 ) ;
F_206 ( & V_4 -> V_62 ) ;
F_207 ( & V_4 -> F_120 , F_120 ) ;
V_450 = F_208 ( V_309 , 0 , V_339 ) ;
if ( V_450 ) {
F_20 ( & V_309 -> V_309 , L_66 ) ;
goto V_457;
}
V_4 -> V_46 = F_209 ( V_309 , 0 , V_458 ) ;
if ( V_4 -> V_46 == NULL ) {
F_20 ( & V_309 -> V_309 , L_67 ) ;
V_450 = - V_459 ;
goto V_460;
}
for ( V_50 = 0 ; V_50 < F_9 ( V_461 ) ; V_50 ++ )
if ( ( V_461 [ V_50 ] . V_451 == V_309 -> V_451 ) &&
( V_461 [ V_50 ] . V_10 == ( unsigned short ) V_462 ||
V_461 [ V_50 ] . V_10 == V_309 -> V_10 ) &&
( V_461 [ V_50 ] . V_463 == ( unsigned short ) V_462 ||
V_461 [ V_50 ] . V_463 >= V_309 -> V_463 ) ) {
V_4 -> V_116 = V_461 [ V_50 ] . V_154 ;
break;
}
if ( V_464 )
V_4 -> V_116 = V_464 ;
F_91 ( V_78 * sizeof( struct V_67 ) > V_72 / 4 ) ;
F_91 ( V_465 > V_72 / 2 ) ;
V_4 -> V_131 = F_76 ( V_4 -> V_3 . V_10 ,
V_72 ,
& V_4 -> V_133 ,
V_127 ) ;
if ( ! V_4 -> V_131 ) {
V_450 = - V_140 ;
goto V_466;
}
V_450 = F_59 ( & V_4 -> V_118 , V_4 , 0 ,
V_467 ) ;
if ( V_450 < 0 )
goto V_468;
V_450 = F_59 ( & V_4 -> V_284 , V_4 , V_72 / 4 ,
V_469 ) ;
if ( V_450 < 0 )
goto V_470;
V_450 = F_78 ( & V_4 -> V_216 , V_4 ,
V_471 , F_97 ) ;
if ( V_450 < 0 )
goto V_472;
V_450 = F_78 ( & V_4 -> V_222 , V_4 ,
V_473 , F_97 ) ;
if ( V_450 < 0 )
goto V_474;
F_11 ( V_4 , V_410 , ~ 0 ) ;
V_4 -> V_393 = ~ 0ULL ;
V_4 -> V_231 = F_13 ( V_4 , V_410 ) ;
F_11 ( V_4 , V_412 , ~ 0 ) ;
V_4 -> V_394 = V_4 -> V_231 ;
V_4 -> V_414 = F_210 ( V_4 -> V_394 ) ;
V_296 = sizeof( struct V_363 ) * V_4 -> V_414 ;
V_4 -> V_286 = F_199 ( V_296 , V_127 ) ;
F_11 ( V_4 , V_406 , ~ 0 ) ;
V_4 -> V_230 = F_13 ( V_4 , V_406 ) ;
F_11 ( V_4 , V_411 , ~ 0 ) ;
V_4 -> V_391 = V_4 -> V_230 ;
V_4 -> V_415 = F_210 ( V_4 -> V_391 ) ;
V_296 = sizeof( struct V_363 ) * V_4 -> V_415 ;
V_4 -> V_288 = F_199 ( V_296 , V_127 ) ;
if ( V_4 -> V_288 == NULL || V_4 -> V_286 == NULL ) {
V_450 = - V_140 ;
goto V_475;
}
V_4 -> V_267 = V_4 -> V_131 + V_72 / 2 ;
V_4 -> V_319 = V_4 -> V_133 + V_72 / 2 ;
V_446 = F_13 ( V_4 , V_273 ) ;
V_447 = ( V_446 >> 12 ) & 0xf ;
V_448 = V_446 & 0x7 ;
V_449 = ( ( T_6 ) F_13 ( V_4 , V_476 ) << 32 ) |
F_13 ( V_4 , V_477 ) ;
V_450 = F_211 ( & V_4 -> V_3 , V_447 , V_448 , V_449 ) ;
if ( V_450 )
goto V_475;
V_312 = F_13 ( V_4 , V_47 ) & 0x00ff00ff ;
F_4 ( & V_309 -> V_309 ,
L_68
L_69 ,
V_312 >> 16 , V_312 & 0xff , V_4 -> V_3 . V_66 ,
V_4 -> V_414 , V_4 -> V_415 , V_4 -> V_116 ) ;
return 0 ;
V_475:
F_212 ( V_4 -> V_286 ) ;
F_212 ( V_4 -> V_288 ) ;
F_80 ( & V_4 -> V_222 ) ;
V_474:
F_80 ( & V_4 -> V_216 ) ;
V_472:
F_36 ( & V_4 -> V_284 ) ;
V_470:
F_36 ( & V_4 -> V_118 ) ;
V_468:
F_82 ( V_4 -> V_3 . V_10 , V_72 ,
V_4 -> V_131 , V_4 -> V_133 ) ;
V_466:
F_213 ( V_309 , V_4 -> V_46 ) ;
V_460:
F_214 ( V_309 , 0 ) ;
V_457:
F_215 ( V_309 ) ;
V_455:
F_212 ( V_4 ) ;
F_197 ( V_309 ) ;
V_453:
if ( V_450 == - V_140 )
F_20 ( & V_309 -> V_309 , L_70 ) ;
return V_450 ;
}
static void F_216 ( struct V_308 * V_309 )
{
struct V_1 * V_4 ;
V_4 = F_217 ( V_309 ) ;
F_11 ( V_4 , V_332 , ~ 0 ) ;
F_15 ( V_4 ) ;
F_218 ( & V_4 -> F_120 ) ;
F_219 ( & V_4 -> V_3 ) ;
F_130 ( V_4 ) ;
F_220 ( V_309 -> V_279 , V_4 ) ;
if ( V_4 -> V_270 && V_4 -> V_270 != V_4 -> V_202 )
F_82 ( V_4 -> V_3 . V_10 , V_198 ,
V_4 -> V_270 , V_4 -> V_272 ) ;
if ( V_4 -> V_202 )
F_82 ( V_4 -> V_3 . V_10 , V_198 ,
V_4 -> V_202 , V_4 -> V_271 ) ;
F_36 ( & V_4 -> V_118 ) ;
F_36 ( & V_4 -> V_284 ) ;
F_82 ( V_4 -> V_3 . V_10 , V_72 ,
V_4 -> V_131 , V_4 -> V_133 ) ;
F_80 ( & V_4 -> V_216 ) ;
F_80 ( & V_4 -> V_222 ) ;
F_212 ( V_4 -> V_288 ) ;
F_212 ( V_4 -> V_286 ) ;
F_141 ( V_309 ) ;
F_213 ( V_309 , V_4 -> V_46 ) ;
F_214 ( V_309 , 0 ) ;
F_215 ( V_309 ) ;
F_212 ( V_4 ) ;
F_197 ( V_309 ) ;
F_4 ( & V_309 -> V_309 , L_71 ) ;
}
static int F_221 ( struct V_308 * V_309 , T_12 V_478 )
{
struct V_1 * V_4 = F_217 ( V_309 ) ;
int V_450 ;
F_130 ( V_4 ) ;
F_220 ( V_309 -> V_279 , V_4 ) ;
F_141 ( V_309 ) ;
V_450 = F_222 ( V_309 ) ;
if ( V_450 ) {
F_20 ( & V_309 -> V_309 , L_72 ) ;
return V_450 ;
}
V_450 = F_223 ( V_309 , F_224 ( V_309 , V_478 ) ) ;
if ( V_450 )
F_20 ( & V_309 -> V_309 , L_73 , V_450 ) ;
F_197 ( V_309 ) ;
return 0 ;
}
static int F_225 ( struct V_308 * V_309 )
{
struct V_1 * V_4 = F_217 ( V_309 ) ;
int V_450 ;
F_193 ( V_309 ) ;
F_223 ( V_309 , V_479 ) ;
F_226 ( V_309 ) ;
V_450 = F_201 ( V_309 ) ;
if ( V_450 ) {
F_20 ( & V_309 -> V_309 , L_74 ) ;
return V_450 ;
}
if ( ! F_13 ( V_4 , V_477 ) &&
! F_13 ( V_4 , V_476 ) ) {
F_11 ( V_4 , V_477 , ( T_1 ) V_4 -> V_3 . V_449 ) ;
F_11 ( V_4 , V_476 , ( T_1 ) ( V_4 -> V_3 . V_449 >> 32 ) ) ;
}
V_450 = F_134 ( & V_4 -> V_3 , NULL , 0 ) ;
if ( V_450 )
return V_450 ;
F_172 ( V_4 ) ;
return 0 ;
}
static int T_13 F_227 ( void )
{
return F_228 ( & V_480 ) ;
}
static void T_14 F_229 ( void )
{
F_230 ( & V_480 ) ;
}
