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
F_4 ( V_4 , L_1 , V_5 ,
V_5 & V_10 ? L_2 : L_3 ,
V_5 & V_11 ? L_4 : L_3 ,
V_5 & V_12 ? L_5 : L_3 ,
V_5 & V_13 ? L_6 : L_3 ,
V_5 & V_14 ? L_7 : L_3 ,
V_5 & V_15 ? L_8 : L_3 ,
V_5 & V_16 ? L_9 : L_3 ,
V_5 & V_17 ? L_10 : L_3 ,
V_5 & V_18 ? L_11 : L_3 ,
V_5 & V_19 ? L_12 : L_3 ,
V_5 & V_20 ? L_13 : L_3 ,
V_5 & V_21 ? L_14 : L_3 ,
V_5 & V_22 ? L_15 : L_3 ,
V_5 & V_9 ? L_16 : L_3 ,
V_5 & ~ ( V_10 | V_11 |
V_12 | V_13 |
V_14 | V_15 |
V_16 | V_17 |
V_18 | V_19 |
V_20 |
V_21 | V_9 )
? L_17 : L_3 ) ;
}
static char F_5 ( T_1 * V_23 , int V_24 )
{
return V_25 [ * V_23 >> V_24 & 3 ] ;
}
static void F_6 ( struct V_1 * V_4 , int V_26 , int V_27 )
{
T_1 * V_23 ;
if ( F_3 ( ! ( V_6 & V_28 ) ) )
return;
F_4 ( V_4 , L_18 ,
V_27 , V_26 , V_4 -> V_29 ) ;
for ( V_23 = V_4 -> V_30 ; V_27 -- ; ++ V_23 )
if ( ( * V_23 & 1 << 23 ) == 0 )
F_4 ( V_4 ,
L_19 ,
* V_23 , * V_23 >> 24 & 63 , F_5 ( V_23 , 6 ) , F_5 ( V_23 , 4 ) , F_5 ( V_23 , 2 ) ,
V_31 [ * V_23 >> 14 & 3 ] , * V_23 >> 16 & 63 ,
V_32 [ * V_23 >> 8 & 7 ] , * V_23 >> 22 & 1 ? L_20 : L_3 ,
* V_23 >> 11 & 1 ? L_21 : L_3 , * V_23 & 2 ? L_22 : L_3 ) ;
else
F_4 ( V_4 ,
L_23 ,
* V_23 , * V_23 >> 24 & 63 ,
F_5 ( V_23 , 16 ) , F_5 ( V_23 , 14 ) , F_5 ( V_23 , 12 ) , F_5 ( V_23 , 10 ) ,
F_5 ( V_23 , 8 ) , F_5 ( V_23 , 6 ) , F_5 ( V_23 , 4 ) , F_5 ( V_23 , 2 ) ) ;
}
static void F_7 ( struct V_1 * V_4 ,
char V_33 , int V_31 , T_1 * V_34 , int V_5 )
{
int V_35 = V_34 [ 0 ] >> 4 & 0xf ;
char V_36 [ 12 ] ;
if ( F_3 ( ! ( V_6 & V_37 ) ) )
return;
if ( F_8 ( V_5 >= F_9 ( V_38 ) ) )
V_5 = 0x1f ;
if ( V_5 == V_39 ) {
F_4 ( V_4 , L_24 ,
V_33 , ( V_34 [ 2 ] >> 16 ) & 0xff ) ;
return;
}
switch ( V_35 ) {
case 0x0 : case 0x6 : case 0x8 :
snprintf ( V_36 , sizeof( V_36 ) , L_25 ,
F_10 ( ( V_40 V_41 ) V_34 [ 3 ] ) ) ;
break;
case 0x1 : case 0x5 : case 0x7 : case 0x9 : case 0xb :
snprintf ( V_36 , sizeof( V_36 ) , L_26 ,
V_34 [ 3 ] >> 16 , V_34 [ 3 ] & 0xffff ) ;
break;
default:
V_36 [ 0 ] = '\0' ;
}
switch ( V_35 ) {
case 0xa :
F_4 ( V_4 , L_27 ,
V_33 , V_38 [ V_5 ] , V_42 [ V_35 ] ) ;
break;
case 0xe :
F_4 ( V_4 , L_28 ,
V_33 , V_38 [ V_5 ] , V_34 [ 1 ] , V_34 [ 2 ] ) ;
break;
case 0x0 : case 0x1 : case 0x4 : case 0x5 : case 0x9 :
F_4 ( V_4 ,
L_29 ,
V_33 , V_31 , V_34 [ 0 ] >> 10 & 0x3f ,
V_34 [ 1 ] >> 16 , V_34 [ 0 ] >> 16 , V_38 [ V_5 ] ,
V_42 [ V_35 ] , V_34 [ 1 ] & 0xffff , V_34 [ 2 ] , V_36 ) ;
break;
default:
F_4 ( V_4 ,
L_30 ,
V_33 , V_31 , V_34 [ 0 ] >> 10 & 0x3f ,
V_34 [ 1 ] >> 16 , V_34 [ 0 ] >> 16 , V_38 [ V_5 ] ,
V_42 [ V_35 ] , V_36 ) ;
}
}
static inline void F_11 ( const struct V_1 * V_4 , int V_43 , T_1 V_44 )
{
F_12 ( V_44 , V_4 -> V_45 + V_43 ) ;
}
static inline T_1 F_13 ( const struct V_1 * V_4 , int V_43 )
{
return F_14 ( V_4 -> V_45 + V_43 ) ;
}
static inline void F_15 ( const struct V_1 * V_4 )
{
F_13 ( V_4 , V_46 ) ;
}
static int F_16 ( struct V_1 * V_4 , int V_47 )
{
T_1 V_48 ;
int V_49 ;
F_11 ( V_4 , V_50 , F_17 ( V_47 ) ) ;
for ( V_49 = 0 ; V_49 < 3 + 100 ; V_49 ++ ) {
V_48 = F_13 ( V_4 , V_50 ) ;
if ( ! ~ V_48 )
return - V_51 ;
if ( V_48 & V_52 )
return F_18 ( V_48 ) ;
if ( V_49 >= 3 )
F_19 ( 1 ) ;
}
F_20 ( V_4 , L_31 , V_47 ) ;
F_21 () ;
return - V_53 ;
}
static int F_22 ( const struct V_1 * V_4 , int V_47 , T_1 V_48 )
{
int V_49 ;
F_11 ( V_4 , V_50 ,
F_23 ( V_47 , V_48 ) ) ;
for ( V_49 = 0 ; V_49 < 3 + 100 ; V_49 ++ ) {
V_48 = F_13 ( V_4 , V_50 ) ;
if ( ! ~ V_48 )
return - V_51 ;
if ( ! ( V_48 & V_54 ) )
return 0 ;
if ( V_49 >= 3 )
F_19 ( 1 ) ;
}
F_20 ( V_4 , L_32 , V_47 , V_48 ) ;
F_21 () ;
return - V_53 ;
}
static int F_24 ( struct V_1 * V_4 , int V_47 ,
int V_55 , int V_56 )
{
int V_57 = F_16 ( V_4 , V_47 ) ;
if ( V_57 < 0 )
return V_57 ;
if ( V_47 == 5 )
V_55 |= V_58 ;
return F_22 ( V_4 , V_47 , ( V_57 & ~ V_55 ) | V_56 ) ;
}
static int F_25 ( struct V_1 * V_4 , int V_59 , int V_47 )
{
int V_57 ;
V_57 = F_24 ( V_4 , 7 , V_60 , V_59 << 5 ) ;
if ( V_57 < 0 )
return V_57 ;
return F_16 ( V_4 , V_47 ) ;
}
static int F_26 ( struct V_2 * V_3 , int V_47 )
{
struct V_1 * V_4 = V_1 ( V_3 ) ;
int V_57 ;
F_27 ( & V_4 -> V_61 ) ;
V_57 = F_16 ( V_4 , V_47 ) ;
F_28 ( & V_4 -> V_61 ) ;
return V_57 ;
}
static int F_29 ( struct V_2 * V_3 , int V_47 ,
int V_55 , int V_56 )
{
struct V_1 * V_4 = V_1 ( V_3 ) ;
int V_57 ;
F_27 ( & V_4 -> V_61 ) ;
V_57 = F_24 ( V_4 , V_47 , V_55 , V_56 ) ;
F_28 ( & V_4 -> V_61 ) ;
return V_57 ;
}
static inline T_2 F_30 ( struct V_62 * V_63 , unsigned int V_49 )
{
return F_31 ( V_63 -> V_64 [ V_49 ] ) ;
}
static void F_32 ( struct V_62 * V_63 , unsigned int V_65 )
{
struct V_66 * V_67 ;
V_67 = & V_63 -> V_68 [ V_65 ] ;
V_67 -> V_69 &= F_33 ( ~ 0xf ) ;
V_67 -> V_70 = F_34 ( V_71 ) ;
V_67 -> V_72 = 0 ;
F_35 () ;
V_67 = & V_63 -> V_68 [ V_63 -> V_73 ] ;
V_67 -> V_69 |= F_33 ( 1 ) ;
V_63 -> V_73 = V_65 ;
F_11 ( V_63 -> V_4 , F_36 ( V_63 -> V_74 ) , V_75 ) ;
}
static void F_37 ( struct V_62 * V_63 )
{
unsigned int V_49 ;
if ( V_63 -> V_76 )
F_38 ( V_63 -> V_76 , V_77 + V_78 ) ;
for ( V_49 = 0 ; V_49 < V_77 ; V_49 ++ )
if ( V_63 -> V_64 [ V_49 ] ) {
F_39 ( V_63 -> V_4 -> V_3 . V_79 ,
F_30 ( V_63 , V_49 ) ,
V_71 , V_80 ) ;
F_40 ( V_63 -> V_64 [ V_49 ] ) ;
}
}
static void F_41 ( struct V_62 * V_63 , const char * V_81 )
{
struct V_1 * V_4 = V_63 -> V_4 ;
if ( F_13 ( V_4 , F_42 ( V_63 -> V_74 ) ) & V_82 ) {
F_11 ( V_4 , F_42 ( V_63 -> V_74 ) , V_82 ) ;
F_15 ( V_4 ) ;
F_20 ( V_4 , L_33 , V_81 ) ;
}
}
static inline unsigned int F_43 ( unsigned int V_65 )
{
return ( V_65 + 1 ) % V_77 ;
}
static inline unsigned int F_44 ( unsigned int V_65 )
{
return ( V_65 - 1 + V_77 ) % V_77 ;
}
static inline unsigned int F_45 ( struct V_62 * V_63 )
{
return F_43 ( V_63 -> V_73 ) ;
}
static unsigned int F_46 ( struct V_62 * V_63 ,
unsigned int * V_83 )
{
unsigned int V_49 , V_84 , V_85 = V_63 -> V_73 ;
T_3 V_70 , V_86 ;
V_49 = F_45 ( V_63 ) ;
V_70 = F_47 ( V_63 -> V_68 [ V_49 ] . V_70 ) ;
while ( V_49 != V_85 && V_70 == 0 ) {
V_84 = F_43 ( V_49 ) ;
F_48 () ;
V_86 = F_47 (
V_63 -> V_68 [ V_84 ] . V_70 ) ;
if ( V_86 == F_34 ( V_71 ) ) {
if ( V_87 > V_71 && V_49 != V_85 ) {
V_84 = F_43 ( V_84 ) ;
F_48 () ;
V_86 = F_47 (
V_63 -> V_68 [ V_84 ] . V_70 ) ;
if ( V_86 != F_34 ( V_71 ) )
goto V_88;
}
break;
}
V_88:
V_49 = V_84 ;
V_70 = V_86 ;
}
F_48 () ;
* V_83 = V_71 - F_49 ( V_70 ) ;
if ( * V_83 > V_71 ) {
* V_83 = 0 ;
F_41 ( V_63 , L_34 ) ;
}
return V_49 ;
}
static void F_50 ( struct V_62 * V_63 ,
unsigned int V_89 ,
unsigned int V_90 )
{
unsigned int V_49 ;
V_49 = F_45 ( V_63 ) ;
while ( V_49 != V_89 ) {
F_51 ( V_63 -> V_4 -> V_3 . V_79 ,
F_30 ( V_63 , V_49 ) ,
V_71 , V_80 ) ;
V_49 = F_43 ( V_49 ) ;
}
if ( V_90 > 0 )
F_51 ( V_63 -> V_4 -> V_3 . V_79 ,
F_30 ( V_63 , V_49 ) ,
V_90 , V_80 ) ;
}
static T_4 * F_52 ( struct V_62 * V_63 , T_4 * V_76 )
{
struct V_1 * V_4 = V_63 -> V_4 ;
struct V_91 V_92 ;
T_1 V_93 , V_94 , V_35 ;
int V_5 ;
V_92 . V_34 [ 0 ] = F_53 ( V_76 [ 0 ] ) ;
V_92 . V_34 [ 1 ] = F_53 ( V_76 [ 1 ] ) ;
V_92 . V_34 [ 2 ] = F_53 ( V_76 [ 2 ] ) ;
V_35 = ( V_92 . V_34 [ 0 ] >> 4 ) & 0x0f ;
switch ( V_35 ) {
case V_95 :
case V_96 :
V_92 . V_34 [ 3 ] = ( V_40 V_97 ) V_76 [ 3 ] ;
V_92 . V_98 = 16 ;
V_92 . V_99 = 0 ;
break;
case V_100 :
V_92 . V_34 [ 3 ] = F_53 ( V_76 [ 3 ] ) ;
V_92 . V_98 = 16 ;
V_92 . V_99 = 0 ;
break;
case V_101 :
case V_102 :
case V_103 :
case V_104 :
V_92 . V_34 [ 3 ] = F_53 ( V_76 [ 3 ] ) ;
V_92 . V_98 = 16 ;
V_92 . V_99 = V_92 . V_34 [ 3 ] >> 16 ;
if ( V_92 . V_99 > V_105 ) {
F_41 ( V_63 , L_35 ) ;
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
F_41 ( V_63 , L_36 ) ;
return NULL ;
}
V_92 . V_109 = ( void * ) V_76 + V_92 . V_98 ;
V_94 = ( V_92 . V_98 + V_92 . V_99 + 3 ) / 4 ;
V_93 = F_53 ( V_76 [ V_94 ] ) ;
V_5 = ( V_93 >> 16 ) & 0x1f ;
V_92 . V_110 = V_5 - 16 ;
V_92 . V_31 = ( V_93 >> 21 ) & 0x7 ;
V_92 . V_111 = V_93 & 0xffff ;
V_92 . V_26 = V_4 -> V_112 ;
F_7 ( V_4 , 'R' , V_92 . V_31 , V_92 . V_34 , V_5 ) ;
if ( V_5 == V_113 &&
( V_92 . V_34 [ 0 ] & 0xff ) == ( V_114 << 4 ) )
V_92 . V_110 = V_115 ;
if ( V_5 == V_39 ) {
if ( ! ( V_4 -> V_116 & V_117 ) )
V_4 -> V_112 = ( V_92 . V_34 [ 2 ] >> 16 ) & 0xff ;
} else if ( V_63 == & V_4 -> V_118 ) {
F_54 ( & V_4 -> V_3 , & V_92 ) ;
} else {
F_55 ( & V_4 -> V_3 , & V_92 ) ;
}
return V_76 + V_94 + 1 ;
}
static void * F_56 ( struct V_62 * V_63 , void * V_92 , void * V_119 )
{
void * V_120 ;
while ( V_92 < V_119 ) {
V_120 = F_52 ( V_63 , V_92 ) ;
if ( ! V_120 )
return V_92 ;
V_92 = V_120 ;
}
return V_92 ;
}
static void F_57 ( struct V_62 * V_63 , unsigned int V_121 )
{
unsigned int V_49 ;
V_49 = F_45 ( V_63 ) ;
while ( V_49 != V_121 ) {
F_58 ( V_63 -> V_4 -> V_3 . V_79 ,
F_30 ( V_63 , V_49 ) ,
V_71 , V_80 ) ;
F_32 ( V_63 , V_49 ) ;
V_49 = F_43 ( V_49 ) ;
}
}
static void F_59 ( unsigned long V_44 )
{
struct V_62 * V_63 = (struct V_62 * ) V_44 ;
unsigned int V_89 , V_90 ;
void * V_92 , * V_119 ;
V_92 = V_63 -> V_122 ;
if ( ! V_92 )
return;
V_89 = F_46 ( V_63 ,
& V_90 ) ;
F_50 ( V_63 , V_89 , V_90 ) ;
V_119 = V_63 -> V_76 + V_89 * V_71 + V_90 ;
if ( V_89 < F_45 ( V_63 ) ) {
void * V_123 = V_63 -> V_76 + V_77 * V_71 ;
V_92 = F_56 ( V_63 , V_92 , V_123 ) ;
if ( V_92 < V_123 )
goto error;
V_92 -= V_77 * V_71 ;
}
V_92 = F_56 ( V_63 , V_92 , V_119 ) ;
if ( V_92 != V_119 ) {
if ( V_92 > V_119 )
F_41 ( V_63 , L_37 ) ;
goto error;
}
V_63 -> V_122 = V_92 ;
F_57 ( V_63 , V_89 ) ;
return;
error:
V_63 -> V_122 = NULL ;
}
static int F_60 ( struct V_62 * V_63 , struct V_1 * V_4 ,
unsigned int V_124 , T_1 V_74 )
{
unsigned int V_49 ;
T_2 V_125 ;
struct V_59 * V_64 [ V_77 + V_78 ] ;
struct V_66 * V_67 ;
V_63 -> V_74 = V_74 ;
V_63 -> V_4 = V_4 ;
F_61 ( & V_63 -> V_126 , F_59 , ( unsigned long ) V_63 ) ;
for ( V_49 = 0 ; V_49 < V_77 ; V_49 ++ ) {
V_63 -> V_64 [ V_49 ] = F_62 ( V_127 | V_128 ) ;
if ( ! V_63 -> V_64 [ V_49 ] )
goto V_129;
V_125 = F_63 ( V_4 -> V_3 . V_79 , V_63 -> V_64 [ V_49 ] ,
0 , V_71 , V_80 ) ;
if ( F_64 ( V_4 -> V_3 . V_79 , V_125 ) ) {
F_40 ( V_63 -> V_64 [ V_49 ] ) ;
V_63 -> V_64 [ V_49 ] = NULL ;
goto V_129;
}
F_65 ( V_63 -> V_64 [ V_49 ] , V_125 ) ;
}
for ( V_49 = 0 ; V_49 < V_77 ; V_49 ++ )
V_64 [ V_49 ] = V_63 -> V_64 [ V_49 ] ;
for ( V_49 = 0 ; V_49 < V_78 ; V_49 ++ )
V_64 [ V_77 + V_49 ] = V_63 -> V_64 [ V_49 ] ;
V_63 -> V_76 = F_66 ( V_64 , V_77 + V_78 ,
- 1 , V_130 ) ;
if ( ! V_63 -> V_76 )
goto V_129;
V_63 -> V_68 = V_4 -> V_131 + V_124 ;
V_63 -> V_132 = V_4 -> V_133 + V_124 ;
for ( V_49 = 0 ; V_49 < V_77 ; V_49 ++ ) {
V_67 = & V_63 -> V_68 [ V_49 ] ;
V_67 -> V_134 = F_34 ( V_71 ) ;
V_67 -> V_135 = F_34 ( V_136 |
V_137 |
V_138 ) ;
V_67 -> V_139 = F_33 ( F_30 ( V_63 , V_49 ) ) ;
V_67 -> V_69 = F_33 ( V_63 -> V_132 +
F_43 ( V_49 ) * sizeof( struct V_66 ) ) ;
}
return 0 ;
V_129:
F_37 ( V_63 ) ;
return - V_140 ;
}
static void F_67 ( struct V_62 * V_63 )
{
unsigned int V_49 ;
for ( V_49 = 0 ; V_49 < V_77 ; V_49 ++ )
F_32 ( V_63 , V_49 ) ;
V_63 -> V_122 = V_63 -> V_76 ;
F_11 ( V_63 -> V_4 , F_68 ( V_63 -> V_74 ) , V_63 -> V_132 | 1 ) ;
F_11 ( V_63 -> V_4 , F_36 ( V_63 -> V_74 ) , V_82 ) ;
}
static struct V_66 * F_69 ( struct V_66 * V_67 , int V_141 )
{
T_3 V_142 ;
V_142 = V_67 -> V_135 & F_34 ( V_138 ) ;
if ( V_141 == 2 && V_142 == F_34 ( V_138 ) )
return V_67 ;
else
return V_67 + V_141 - 1 ;
}
static void F_70 ( unsigned long V_44 )
{
struct V_143 * V_63 = (struct V_143 * ) V_44 ;
struct V_66 * V_67 , * V_85 ;
T_1 V_144 ;
int V_141 ;
struct V_145 * V_146 ;
V_146 = F_71 ( V_63 -> V_147 . V_120 ,
struct V_145 , V_148 ) ;
V_85 = V_63 -> V_85 ;
while ( V_85 -> V_69 != 0 ) {
struct V_145 * V_149 = V_146 ;
V_144 = F_72 ( V_85 -> V_69 ) ;
V_141 = V_144 & 0xf ;
V_144 &= ~ 0xf ;
V_63 -> V_150 = V_144 ;
if ( V_144 < V_146 -> V_151 ||
V_144 >= V_146 -> V_151 + V_146 -> V_152 )
V_146 = F_71 ( V_146 -> V_148 . V_120 ,
struct V_145 , V_148 ) ;
V_67 = V_146 -> V_76 + ( V_144 - V_146 -> V_151 ) / sizeof( * V_67 ) ;
V_85 = F_69 ( V_67 , V_141 ) ;
if ( ! V_63 -> V_153 ( V_63 , V_67 , V_85 ) )
break;
if ( V_149 != V_146 ) {
unsigned long V_154 ;
V_149 -> V_152 = 0 ;
F_73 ( & V_63 -> V_4 -> V_155 , V_154 ) ;
F_74 ( & V_149 -> V_148 , & V_63 -> V_147 ) ;
F_75 ( & V_63 -> V_4 -> V_155 , V_154 ) ;
}
V_63 -> V_85 = V_85 ;
}
}
static int F_76 ( struct V_143 * V_63 )
{
struct V_145 * V_146 ;
T_2 V_156 ( V_157 ) ;
int V_43 ;
if ( V_63 -> V_158 >= 16 * 1024 * 1024 )
return - V_140 ;
V_146 = F_77 ( V_63 -> V_4 -> V_3 . V_79 , V_71 ,
& V_157 , V_159 ) ;
if ( ! V_146 )
return - V_140 ;
V_43 = ( void * ) & V_146 -> V_76 - ( void * ) V_146 ;
V_146 -> V_160 = V_71 - V_43 ;
V_146 -> V_151 = V_157 + V_43 ;
V_146 -> V_152 = 0 ;
F_78 ( & V_146 -> V_148 , & V_63 -> V_147 ) ;
V_63 -> V_158 += V_71 ;
return 0 ;
}
static int F_79 ( struct V_143 * V_63 , struct V_1 * V_4 ,
T_1 V_74 , T_5 V_153 )
{
V_63 -> V_4 = V_4 ;
V_63 -> V_74 = V_74 ;
V_63 -> V_158 = 0 ;
F_80 ( & V_63 -> V_147 ) ;
if ( F_76 ( V_63 ) < 0 )
return - V_140 ;
V_63 -> V_161 = F_71 ( V_63 -> V_147 . V_120 ,
struct V_145 , V_148 ) ;
F_61 ( & V_63 -> V_126 , F_70 , ( unsigned long ) V_63 ) ;
V_63 -> V_153 = V_153 ;
memset ( V_63 -> V_161 -> V_76 , 0 , sizeof( * V_63 -> V_161 -> V_76 ) ) ;
V_63 -> V_161 -> V_76 -> V_135 = F_34 ( V_162 ) ;
V_63 -> V_161 -> V_76 -> V_72 = F_34 ( 0x8011 ) ;
V_63 -> V_161 -> V_152 += sizeof( * V_63 -> V_161 -> V_76 ) ;
V_63 -> V_85 = V_63 -> V_161 -> V_76 ;
V_63 -> V_163 = V_63 -> V_161 -> V_76 ;
V_63 -> V_164 = 1 ;
return 0 ;
}
static void F_81 ( struct V_143 * V_63 )
{
struct V_2 * V_3 = & V_63 -> V_4 -> V_3 ;
struct V_145 * V_146 , * V_165 ;
F_82 (desc, tmp, &ctx->buffer_list, list)
F_83 ( V_3 -> V_79 , V_71 , V_146 ,
V_146 -> V_151 -
( ( void * ) & V_146 -> V_76 - ( void * ) V_146 ) ) ;
}
static struct V_66 * F_84 ( struct V_143 * V_63 ,
int V_141 , T_2 * V_166 )
{
struct V_66 * V_67 = NULL ;
struct V_145 * V_146 = V_63 -> V_161 ;
if ( V_141 * sizeof( * V_67 ) > V_146 -> V_160 )
return NULL ;
if ( V_141 * sizeof( * V_67 ) > V_146 -> V_160 - V_146 -> V_152 ) {
if ( V_146 -> V_148 . V_120 == & V_63 -> V_147 ) {
if ( F_76 ( V_63 ) < 0 )
return NULL ;
}
V_146 = F_71 ( V_146 -> V_148 . V_120 ,
struct V_145 , V_148 ) ;
V_63 -> V_161 = V_146 ;
}
V_67 = V_146 -> V_76 + V_146 -> V_152 / sizeof( * V_67 ) ;
memset ( V_67 , 0 , V_141 * sizeof( * V_67 ) ) ;
* V_166 = V_146 -> V_151 + V_146 -> V_152 ;
return V_67 ;
}
static void F_85 ( struct V_143 * V_63 , T_1 V_167 )
{
struct V_1 * V_4 = V_63 -> V_4 ;
F_11 ( V_4 , F_68 ( V_63 -> V_74 ) ,
F_72 ( V_63 -> V_85 -> V_69 ) ) ;
F_11 ( V_4 , F_42 ( V_63 -> V_74 ) , ~ 0 ) ;
F_11 ( V_4 , F_36 ( V_63 -> V_74 ) , V_82 | V_167 ) ;
V_63 -> V_168 = true ;
F_15 ( V_4 ) ;
}
static void F_86 ( struct V_143 * V_63 ,
struct V_66 * V_67 , int V_141 , int V_167 )
{
T_2 V_166 ;
struct V_145 * V_146 = V_63 -> V_161 ;
struct V_66 * V_169 ;
V_166 = V_146 -> V_151 + ( V_67 - V_146 -> V_76 ) * sizeof( * V_67 ) ;
V_146 -> V_152 += ( V_141 + V_167 ) * sizeof( * V_67 ) ;
F_35 () ;
V_169 = F_69 ( V_63 -> V_163 , V_63 -> V_164 ) ;
V_169 -> V_69 = F_33 ( V_166 | V_141 ) ;
if ( F_8 ( V_63 -> V_4 -> V_116 & V_170 ) &&
V_169 != V_63 -> V_163 &&
( V_63 -> V_163 -> V_135 & F_34 ( V_171 ) ) ==
F_34 ( V_136 ) ) {
V_63 -> V_163 -> V_69 = F_33 ( V_166 | V_141 ) ;
}
V_63 -> V_163 = V_67 ;
V_63 -> V_164 = V_141 ;
}
static void F_87 ( struct V_143 * V_63 )
{
struct V_1 * V_4 = V_63 -> V_4 ;
T_1 V_172 ;
int V_49 ;
F_11 ( V_4 , F_42 ( V_63 -> V_74 ) , V_82 ) ;
V_63 -> V_168 = false ;
for ( V_49 = 0 ; V_49 < 1000 ; V_49 ++ ) {
V_172 = F_13 ( V_4 , F_36 ( V_63 -> V_74 ) ) ;
if ( ( V_172 & V_173 ) == 0 )
return;
if ( V_49 )
F_88 ( 10 ) ;
}
F_20 ( V_4 , L_38 , V_172 ) ;
}
static int F_89 ( struct V_143 * V_63 ,
struct V_91 * V_174 )
{
struct V_1 * V_4 = V_63 -> V_4 ;
T_2 V_166 , V_156 ( V_175 ) ;
struct V_176 * V_176 ;
struct V_66 * V_67 , * V_85 ;
T_4 * V_34 ;
int V_141 , V_35 ;
V_67 = F_84 ( V_63 , 4 , & V_166 ) ;
if ( V_67 == NULL ) {
V_174 -> V_110 = V_177 ;
return - 1 ;
}
V_67 [ 0 ] . V_135 = F_34 ( V_178 ) ;
V_67 [ 0 ] . V_70 = F_34 ( V_174 -> V_111 ) ;
V_35 = ( V_174 -> V_34 [ 0 ] >> 4 ) & 0x0f ;
V_34 = ( T_4 * ) & V_67 [ 1 ] ;
switch ( V_35 ) {
case V_95 :
case V_101 :
case V_106 :
case V_107 :
case V_100 :
case V_96 :
case V_102 :
case V_103 :
case V_104 :
V_34 [ 0 ] = F_33 ( ( V_174 -> V_34 [ 0 ] & 0xffff ) |
( V_174 -> V_31 << 16 ) ) ;
V_34 [ 1 ] = F_33 ( ( V_174 -> V_34 [ 1 ] & 0xffff ) |
( V_174 -> V_34 [ 0 ] & 0xffff0000 ) ) ;
V_34 [ 2 ] = F_33 ( V_174 -> V_34 [ 2 ] ) ;
if ( F_90 ( V_35 ) )
V_34 [ 3 ] = F_33 ( V_174 -> V_34 [ 3 ] ) ;
else
V_34 [ 3 ] = ( V_40 T_4 ) V_174 -> V_34 [ 3 ] ;
V_67 [ 0 ] . V_134 = F_34 ( V_174 -> V_98 ) ;
break;
case V_179 :
V_34 [ 0 ] = F_33 ( ( V_114 << 4 ) |
( V_174 -> V_31 << 16 ) ) ;
V_34 [ 1 ] = F_33 ( V_174 -> V_34 [ 1 ] ) ;
V_34 [ 2 ] = F_33 ( V_174 -> V_34 [ 2 ] ) ;
V_67 [ 0 ] . V_134 = F_34 ( 12 ) ;
if ( F_91 ( & V_174 -> V_34 [ 1 ] ) )
V_67 [ 0 ] . V_135 |= F_34 ( V_180 ) ;
break;
case V_181 :
V_34 [ 0 ] = F_33 ( ( V_174 -> V_34 [ 0 ] & 0xffff ) |
( V_174 -> V_31 << 16 ) ) ;
V_34 [ 1 ] = F_33 ( V_174 -> V_34 [ 0 ] & 0xffff0000 ) ;
V_67 [ 0 ] . V_134 = F_34 ( 8 ) ;
break;
default:
V_174 -> V_110 = V_177 ;
return - 1 ;
}
F_92 ( sizeof( struct V_176 ) > sizeof( struct V_66 ) ) ;
V_176 = (struct V_176 * ) & V_67 [ 3 ] ;
V_176 -> V_174 = V_174 ;
V_174 -> V_176 = V_176 ;
if ( V_174 -> V_99 > 0 ) {
if ( V_174 -> V_99 > sizeof( V_176 -> V_182 ) ) {
V_175 = F_93 ( V_4 -> V_3 . V_79 ,
V_174 -> V_109 ,
V_174 -> V_99 ,
V_183 ) ;
if ( F_64 ( V_4 -> V_3 . V_79 , V_175 ) ) {
V_174 -> V_110 = V_177 ;
return - 1 ;
}
V_174 -> V_175 = V_175 ;
V_174 -> V_184 = true ;
} else {
memcpy ( V_176 -> V_182 , V_174 -> V_109 ,
V_174 -> V_99 ) ;
V_175 = V_166 + 3 * sizeof( * V_67 ) ;
}
V_67 [ 2 ] . V_134 = F_34 ( V_174 -> V_99 ) ;
V_67 [ 2 ] . V_139 = F_33 ( V_175 ) ;
V_85 = & V_67 [ 2 ] ;
V_141 = 3 ;
} else {
V_85 = & V_67 [ 0 ] ;
V_141 = 2 ;
}
V_85 -> V_135 |= F_34 ( V_162 |
V_185 |
V_138 ) ;
if ( V_4 -> V_26 != V_174 -> V_26 ) {
if ( V_174 -> V_184 )
F_94 ( V_4 -> V_3 . V_79 , V_175 ,
V_174 -> V_99 , V_183 ) ;
V_174 -> V_110 = V_186 ;
return - 1 ;
}
F_86 ( V_63 , V_67 , V_141 , 4 - V_141 ) ;
if ( V_63 -> V_168 )
F_11 ( V_4 , F_36 ( V_63 -> V_74 ) , V_75 ) ;
else
F_85 ( V_63 , 0 ) ;
return 0 ;
}
static void F_95 ( struct V_143 * V_63 )
{
F_96 ( & V_63 -> V_126 ) ;
V_63 -> V_187 = true ;
F_70 ( ( unsigned long ) V_63 ) ;
V_63 -> V_187 = false ;
F_97 ( & V_63 -> V_126 ) ;
}
static int F_98 ( struct V_143 * V_143 ,
struct V_66 * V_67 ,
struct V_66 * V_85 )
{
struct V_176 * V_176 ;
struct V_91 * V_174 ;
struct V_1 * V_4 = V_143 -> V_4 ;
int V_5 ;
if ( V_85 -> V_72 == 0 && ! V_143 -> V_187 )
return 0 ;
V_176 = (struct V_176 * ) & V_67 [ 3 ] ;
V_174 = V_176 -> V_174 ;
if ( V_174 == NULL )
return 1 ;
if ( V_174 -> V_184 )
F_94 ( V_4 -> V_3 . V_79 , V_174 -> V_175 ,
V_174 -> V_99 , V_183 ) ;
V_5 = F_49 ( V_85 -> V_72 ) & 0x1f ;
V_174 -> V_111 = F_49 ( V_85 -> V_70 ) ;
F_7 ( V_4 , 'T' , V_174 -> V_31 , V_174 -> V_34 , V_5 ) ;
switch ( V_5 ) {
case V_188 :
V_174 -> V_110 = V_189 ;
break;
case V_190 :
V_174 -> V_110 = V_186 ;
break;
case V_191 :
if ( V_143 -> V_187 )
V_174 -> V_110 = V_186 ;
else {
V_174 -> V_110 = V_192 ;
}
break;
case V_115 + 0x10 :
case V_193 + 0x10 :
case V_194 + 0x10 :
case V_195 + 0x10 :
case V_196 + 0x10 :
case V_197 + 0x10 :
case V_198 + 0x10 :
V_174 -> V_110 = V_5 - 0x10 ;
break;
case V_113 :
if ( V_143 -> V_187 ) {
V_174 -> V_110 = V_186 ;
break;
}
default:
V_174 -> V_110 = V_177 ;
break;
}
V_174 -> V_153 ( V_174 , & V_4 -> V_3 , V_174 -> V_110 ) ;
return 1 ;
}
static void F_99 ( struct V_1 * V_4 ,
struct V_91 * V_174 , T_1 V_199 )
{
struct V_91 V_200 ;
int V_35 , V_94 , V_49 ;
V_35 = F_100 ( V_174 -> V_34 [ 0 ] ) ;
if ( F_90 ( V_35 ) )
V_94 = F_101 ( V_174 -> V_34 [ 3 ] ) ;
else
V_94 = 4 ;
V_49 = V_199 - V_201 ;
if ( V_49 + V_94 > V_202 ) {
F_102 ( & V_200 , V_174 -> V_34 ,
V_203 , NULL , 0 ) ;
} else if ( ! F_103 ( V_35 ) ) {
F_102 ( & V_200 , V_174 -> V_34 ,
V_204 , NULL , 0 ) ;
} else {
F_102 ( & V_200 , V_174 -> V_34 , V_205 ,
( void * ) V_4 -> V_206 + V_49 , V_94 ) ;
}
F_55 ( & V_4 -> V_3 , & V_200 ) ;
}
static void F_104 ( struct V_1 * V_4 ,
struct V_91 * V_174 , T_1 V_199 )
{
struct V_91 V_200 ;
int V_35 , V_94 , V_207 , V_208 , V_209 ;
V_41 * V_109 , V_210 ;
T_1 V_211 , V_212 ;
V_35 = F_100 ( V_174 -> V_34 [ 0 ] ) ;
V_94 = F_101 ( V_174 -> V_34 [ 3 ] ) ;
V_109 = V_174 -> V_109 ;
V_207 = F_105 ( V_174 -> V_34 [ 3 ] ) ;
if ( V_35 == V_103 &&
V_207 == V_213 && V_94 == 8 ) {
V_211 = F_10 ( V_109 [ 0 ] ) ;
V_212 = F_10 ( V_109 [ 1 ] ) ;
} else if ( V_35 == V_107 ) {
V_211 = 0 ;
V_212 = 0 ;
} else {
F_102 ( & V_200 , V_174 -> V_34 ,
V_204 , NULL , 0 ) ;
goto V_214;
}
V_208 = ( V_199 - V_215 ) / 4 ;
F_11 ( V_4 , V_216 , V_212 ) ;
F_11 ( V_4 , V_217 , V_211 ) ;
F_11 ( V_4 , V_218 , V_208 ) ;
for ( V_209 = 0 ; V_209 < 20 ; V_209 ++ )
if ( F_13 ( V_4 , V_218 ) & 0x80000000 ) {
V_210 = F_106 ( F_13 ( V_4 ,
V_216 ) ) ;
F_102 ( & V_200 , V_174 -> V_34 ,
V_205 ,
& V_210 , sizeof( V_210 ) ) ;
goto V_214;
}
F_20 ( V_4 , L_39 ) ;
F_102 ( & V_200 , V_174 -> V_34 , V_219 , NULL , 0 ) ;
V_214:
F_55 ( & V_4 -> V_3 , & V_200 ) ;
}
static void F_107 ( struct V_143 * V_63 , struct V_91 * V_174 )
{
T_6 V_43 , V_199 ;
if ( V_63 == & V_63 -> V_4 -> V_220 ) {
V_174 -> V_110 = V_193 ;
V_174 -> V_153 ( V_174 , & V_63 -> V_4 -> V_3 , V_174 -> V_110 ) ;
}
V_43 =
( ( unsigned long long )
F_108 ( V_174 -> V_34 [ 1 ] ) << 32 ) |
V_174 -> V_34 [ 2 ] ;
V_199 = V_43 - V_221 ;
if ( V_199 >= V_201 && V_199 < V_222 )
F_99 ( V_63 -> V_4 , V_174 , V_199 ) ;
else switch ( V_199 ) {
case V_215 :
case V_223 :
case V_224 :
case V_225 :
F_104 ( V_63 -> V_4 , V_174 , V_199 ) ;
break;
default:
if ( V_63 == & V_63 -> V_4 -> V_220 )
F_54 ( & V_63 -> V_4 -> V_3 , V_174 ) ;
else
F_55 ( & V_63 -> V_4 -> V_3 , V_174 ) ;
break;
}
if ( V_63 == & V_63 -> V_4 -> V_226 ) {
V_174 -> V_110 = V_115 ;
V_174 -> V_153 ( V_174 , & V_63 -> V_4 -> V_3 , V_174 -> V_110 ) ;
}
}
static void F_109 ( struct V_143 * V_63 , struct V_91 * V_174 )
{
unsigned long V_154 ;
int V_57 ;
F_73 ( & V_63 -> V_4 -> V_155 , V_154 ) ;
if ( F_110 ( V_174 -> V_34 [ 0 ] ) == V_63 -> V_4 -> V_29 &&
V_63 -> V_4 -> V_26 == V_174 -> V_26 ) {
F_75 ( & V_63 -> V_4 -> V_155 , V_154 ) ;
F_107 ( V_63 , V_174 ) ;
return;
}
V_57 = F_89 ( V_63 , V_174 ) ;
F_75 ( & V_63 -> V_4 -> V_155 , V_154 ) ;
if ( V_57 < 0 )
V_174 -> V_153 ( V_174 , & V_63 -> V_4 -> V_3 , V_174 -> V_110 ) ;
}
static void F_111 ( struct V_1 * V_4 ,
const char * V_227 , unsigned int V_74 )
{
T_1 V_228 ;
V_228 = F_13 ( V_4 , F_36 ( V_74 ) ) ;
if ( V_228 & V_229 )
F_20 ( V_4 , L_40 ,
V_227 , V_38 [ V_228 & 0x1f ] ) ;
}
static void F_112 ( struct V_1 * V_4 )
{
unsigned int V_49 ;
char V_227 [ 8 ] ;
F_111 ( V_4 , L_41 , V_230 ) ;
F_111 ( V_4 , L_42 , V_231 ) ;
F_111 ( V_4 , L_43 , V_232 ) ;
F_111 ( V_4 , L_44 , V_233 ) ;
for ( V_49 = 0 ; V_49 < 32 ; ++ V_49 ) {
if ( ! ( V_4 -> V_234 & ( 1 << V_49 ) ) )
continue;
sprintf ( V_227 , L_45 , V_49 ) ;
F_111 ( V_4 , V_227 , F_113 ( V_49 ) ) ;
}
for ( V_49 = 0 ; V_49 < 32 ; ++ V_49 ) {
if ( ! ( V_4 -> V_235 & ( 1 << V_49 ) ) )
continue;
sprintf ( V_227 , L_46 , V_49 ) ;
F_111 ( V_4 , V_227 , F_114 ( V_49 ) ) ;
}
}
static T_1 F_115 ( T_1 V_236 )
{
T_1 V_237 ;
V_237 = V_236 & 0xfff ;
V_237 += 3072 * ( ( V_236 >> 12 ) & 0x1fff ) ;
V_237 += ( 3072 * 8000 ) * ( V_236 >> 25 ) ;
return V_237 ;
}
static T_1 F_116 ( struct V_1 * V_4 )
{
T_1 V_238 , V_239 , V_240 ;
T_1 V_241 , V_242 , V_243 ;
T_7 V_244 , V_245 ;
int V_49 ;
V_240 = F_13 ( V_4 , V_246 ) ;
if ( V_4 -> V_116 & V_247 ) {
V_49 = 0 ;
V_239 = V_240 ;
V_240 = F_13 ( V_4 , V_246 ) ;
do {
V_238 = V_239 ;
V_239 = V_240 ;
V_240 = F_13 ( V_4 , V_246 ) ;
V_241 = F_115 ( V_238 ) ;
V_242 = F_115 ( V_239 ) ;
V_243 = F_115 ( V_240 ) ;
V_244 = V_242 - V_241 ;
V_245 = V_243 - V_242 ;
} while ( ( V_244 <= 0 || V_245 <= 0 ||
V_244 / V_245 >= 2 || V_245 / V_244 >= 2 )
&& V_49 ++ < 20 );
}
return V_240 ;
}
static T_1 F_117 ( struct V_1 * V_4 )
{
T_1 V_248 = F_116 ( V_4 ) >> 25 ;
if ( F_8 ( ! V_4 -> V_249 ) ) {
F_11 ( V_4 , V_250 , V_19 ) ;
V_4 -> V_251 = ( F_118 ( F_119 () ) & ~ 0x7f ) |
( V_248 & 0x40 ) ;
V_4 -> V_249 = true ;
}
if ( ( V_4 -> V_251 & 0x40 ) != ( V_248 & 0x40 ) )
V_4 -> V_251 += 0x40 ;
return V_4 -> V_251 | V_248 ;
}
static int F_120 ( struct V_1 * V_4 , int V_252 )
{
int V_172 ;
F_27 ( & V_4 -> V_61 ) ;
V_172 = F_22 ( V_4 , 7 , V_252 ) ;
if ( V_172 >= 0 )
V_172 = F_16 ( V_4 , 8 ) ;
F_28 ( & V_4 -> V_61 ) ;
if ( V_172 < 0 )
return V_172 ;
switch ( V_172 & 0x0f ) {
case 0x06 :
return 2 ;
case 0x0e :
return 3 ;
}
return 1 ;
}
static int F_121 ( struct V_1 * V_4 , T_1 V_253 ,
int V_27 )
{
int V_49 ;
T_1 V_254 ;
for ( V_49 = 0 ; V_49 < V_27 ; V_49 ++ ) {
V_254 = V_4 -> V_30 [ V_49 ] ;
if ( ( V_253 & 0xff000000 ) == ( V_254 & 0xff000000 ) )
return - 1 ;
if ( ( V_253 & 0xff000000 ) < ( V_254 & 0xff000000 ) )
return V_49 ;
}
return V_49 ;
}
static int F_122 ( struct V_1 * V_4 )
{
int V_172 ;
int V_57 = 0 ;
F_27 ( & V_4 -> V_61 ) ;
V_172 = F_22 ( V_4 , 7 , 0xe0 ) ;
if ( V_172 >= 0 ) {
V_172 = F_16 ( V_4 , 8 ) ;
V_172 |= 0x40 ;
V_172 = F_22 ( V_4 , 8 , V_172 ) ;
if ( V_172 >= 0 ) {
V_172 = F_16 ( V_4 , 12 ) ;
if ( V_172 >= 0 ) {
if ( ( V_172 & 0x08 ) == 0x08 ) {
V_57 = 0x2 ;
}
}
}
}
F_28 ( & V_4 -> V_61 ) ;
return V_57 ;
}
static int F_123 ( struct V_1 * V_4 , int V_27 )
{
int V_172 , V_49 , V_255 , V_93 ;
T_1 V_253 = 0x8040c800 ;
V_172 = F_13 ( V_4 , V_256 ) ;
if ( ! ( V_172 & V_257 ) ) {
F_4 ( V_4 ,
L_47 ) ;
return - V_53 ;
}
V_253 |= ( ( V_172 & 0x3f ) << 24 ) ;
V_172 = F_26 ( & V_4 -> V_3 , 4 ) ;
if ( V_172 < 0 )
return V_172 ;
V_253 |= ( ( V_172 & 0x07 ) << 8 ) ;
V_172 = F_26 ( & V_4 -> V_3 , 1 ) ;
if ( V_172 < 0 )
return V_172 ;
V_253 |= ( ( V_172 & 0x3f ) << 16 ) ;
for ( V_49 = 0 ; V_49 < 3 ; V_49 ++ ) {
V_93 = F_120 ( V_4 , V_49 ) ;
if ( V_93 < 0 )
return V_93 ;
V_253 |= ( ( V_93 & 0x3 ) << ( 6 - ( V_49 * 2 ) ) ) ;
}
V_253 |= F_122 ( V_4 ) ;
V_255 = F_121 ( V_4 , V_253 , V_27 ) ;
if ( V_255 >= 0 ) {
memmove ( & ( V_4 -> V_30 [ V_255 + 1 ] ) ,
& ( V_4 -> V_30 [ V_255 ] ) ,
( V_27 - V_255 ) * sizeof( * V_4 -> V_30 ) ) ;
V_4 -> V_30 [ V_255 ] = V_253 ;
V_27 ++ ;
}
return V_27 ;
}
static void F_124 ( struct V_258 * V_259 )
{
struct V_1 * V_4 =
F_1 ( V_259 , struct V_1 , F_124 ) ;
int V_27 , V_26 , V_260 , V_49 , V_261 ;
T_1 V_172 ;
void * V_262 = NULL ;
T_2 V_263 = 0 ;
bool V_264 ;
V_172 = F_13 ( V_4 , V_256 ) ;
if ( ! ( V_172 & V_257 ) ) {
F_4 ( V_4 ,
L_47 ) ;
return;
}
if ( ( V_172 & V_265 ) == 63 ) {
F_4 ( V_4 , L_48 ) ;
return;
}
V_4 -> V_29 = V_172 & ( V_266 |
V_265 ) ;
V_264 = ( V_172 & V_267 ) != 0 ;
if ( ! ( V_4 -> V_268 && V_264 ) )
F_11 ( V_4 , V_269 ,
V_270 ) ;
V_4 -> V_268 = V_264 ;
V_172 = F_13 ( V_4 , V_271 ) ;
if ( V_172 & V_272 ) {
F_4 ( V_4 , L_49 ) ;
return;
}
V_27 = ( V_172 >> 3 ) & 0xff ;
if ( V_27 > 252 ) {
F_4 ( V_4 , L_50 , V_172 ) ;
return;
}
V_26 = ( F_53 ( V_4 -> V_253 [ 0 ] ) >> 16 ) & 0xff ;
F_48 () ;
for ( V_49 = 1 , V_261 = 0 ; V_261 < V_27 ; V_49 += 2 , V_261 ++ ) {
T_1 V_273 = F_53 ( V_4 -> V_253 [ V_49 ] ) ;
T_1 V_274 = F_53 ( V_4 -> V_253 [ V_49 + 1 ] ) ;
if ( V_273 != ~ V_274 ) {
if ( V_273 == 0xffff008f ) {
F_4 ( V_4 , L_51 ) ;
V_27 = V_261 ;
break;
}
F_4 ( V_4 , L_52 ,
V_261 , V_27 , V_273 , V_274 ) ;
return;
}
V_4 -> V_30 [ V_261 ] = V_273 ;
}
if ( V_4 -> V_116 & V_275 ) {
V_27 = F_123 ( V_4 , V_27 ) ;
if ( V_27 < 0 ) {
F_4 ( V_4 ,
L_53 ) ;
return;
}
}
if ( V_27 == 0 ) {
F_4 ( V_4 , L_54 ) ;
return;
}
F_48 () ;
V_260 = ( F_13 ( V_4 , V_271 ) >> 16 ) & 0xff ;
if ( V_260 != V_26 ) {
F_4 ( V_4 , L_55 ) ;
return;
}
F_125 ( & V_4 -> V_155 ) ;
V_4 -> V_26 = - 1 ;
F_87 ( & V_4 -> V_220 ) ;
F_87 ( & V_4 -> V_226 ) ;
F_126 ( & V_4 -> V_155 ) ;
F_95 ( & V_4 -> V_220 ) ;
F_95 ( & V_4 -> V_226 ) ;
F_125 ( & V_4 -> V_155 ) ;
V_4 -> V_26 = V_26 ;
F_11 ( V_4 , V_276 , V_9 ) ;
if ( V_4 -> V_116 & V_117 )
V_4 -> V_112 = V_26 ;
if ( V_4 -> V_277 != NULL ) {
if ( V_4 -> V_277 != V_4 -> V_206 ) {
V_262 = V_4 -> V_206 ;
V_263 = V_4 -> V_278 ;
}
V_4 -> V_206 = V_4 -> V_277 ;
V_4 -> V_278 = V_4 -> V_279 ;
V_4 -> V_277 = NULL ;
F_11 ( V_4 , V_280 ,
F_10 ( V_4 -> V_206 [ 2 ] ) ) ;
V_4 -> V_206 [ 0 ] = V_4 -> V_281 ;
F_11 ( V_4 , V_282 ,
F_10 ( V_4 -> V_281 ) ) ;
}
#ifdef F_127
F_11 ( V_4 , V_283 , ~ 0 ) ;
F_11 ( V_4 , V_284 , ~ 0 ) ;
#endif
F_126 ( & V_4 -> V_155 ) ;
if ( V_262 )
F_83 ( V_4 -> V_3 . V_79 , V_202 ,
V_262 , V_263 ) ;
F_6 ( V_4 , V_26 , V_27 ) ;
F_128 ( & V_4 -> V_3 , V_4 -> V_29 , V_26 ,
V_27 , V_4 -> V_30 ,
V_4 -> V_285 ) ;
V_4 -> V_285 = false ;
}
static T_8 F_129 ( int V_286 , void * V_44 )
{
struct V_1 * V_4 = V_44 ;
T_1 V_287 , V_288 ;
int V_49 ;
V_287 = F_13 ( V_4 , V_276 ) ;
if ( ! V_287 || ! ~ V_287 )
return V_289 ;
F_11 ( V_4 , V_276 ,
V_287 & ~ ( V_9 | V_17 ) ) ;
F_2 ( V_4 , V_287 ) ;
if ( V_287 & V_10 )
F_130 ( V_290 , & V_4 -> F_124 ) ;
if ( V_287 & V_11 )
F_131 ( & V_4 -> V_118 . V_126 ) ;
if ( V_287 & V_12 )
F_131 ( & V_4 -> V_291 . V_126 ) ;
if ( V_287 & V_13 )
F_131 ( & V_4 -> V_220 . V_126 ) ;
if ( V_287 & V_14 )
F_131 ( & V_4 -> V_226 . V_126 ) ;
if ( V_287 & V_15 ) {
V_288 = F_13 ( V_4 , V_292 ) ;
F_11 ( V_4 , V_292 , V_288 ) ;
while ( V_288 ) {
V_49 = F_132 ( V_288 ) - 1 ;
F_131 (
& V_4 -> V_293 [ V_49 ] . V_143 . V_126 ) ;
V_288 &= ~ ( 1 << V_49 ) ;
}
}
if ( V_287 & V_16 ) {
V_288 = F_13 ( V_4 , V_294 ) ;
F_11 ( V_4 , V_294 , V_288 ) ;
while ( V_288 ) {
V_49 = F_132 ( V_288 ) - 1 ;
F_131 (
& V_4 -> V_295 [ V_49 ] . V_143 . V_126 ) ;
V_288 &= ~ ( 1 << V_49 ) ;
}
}
if ( F_8 ( V_287 & V_21 ) )
F_20 ( V_4 , L_56 ) ;
if ( F_8 ( V_287 & V_17 ) ) {
F_13 ( V_4 , V_296 ) ;
F_13 ( V_4 , V_297 ) ;
F_11 ( V_4 , V_276 ,
V_17 ) ;
if ( F_133 () )
F_20 ( V_4 , L_57 ) ;
}
if ( F_8 ( V_287 & V_18 ) ) {
if ( F_133 () )
F_4 ( V_4 , L_58 ) ;
F_11 ( V_4 , V_269 ,
V_270 ) ;
}
if ( F_8 ( V_287 & V_20 ) ) {
if ( F_133 () )
F_4 ( V_4 , L_59 ) ;
}
if ( F_8 ( V_287 & V_22 ) )
F_112 ( V_4 ) ;
if ( V_287 & V_19 ) {
F_134 ( & V_4 -> V_155 ) ;
F_117 ( V_4 ) ;
F_135 ( & V_4 -> V_155 ) ;
} else
F_15 ( V_4 ) ;
return V_298 ;
}
static int F_136 ( struct V_1 * V_4 )
{
T_1 V_48 ;
int V_49 ;
F_11 ( V_4 , V_299 , V_300 ) ;
for ( V_49 = 0 ; V_49 < 500 ; V_49 ++ ) {
V_48 = F_13 ( V_4 , V_299 ) ;
if ( ! ~ V_48 )
return - V_51 ;
if ( ! ( V_48 & V_300 ) )
return 0 ;
F_19 ( 1 ) ;
}
return - V_53 ;
}
static void F_137 ( V_41 * V_301 , const V_41 * V_302 , T_9 V_94 )
{
T_9 V_303 = V_94 * 4 ;
memcpy ( V_301 , V_302 , V_303 ) ;
if ( V_303 < V_202 )
memset ( & V_301 [ V_94 ] , 0 , V_202 - V_303 ) ;
}
static int F_138 ( struct V_1 * V_4 )
{
bool V_304 ;
int V_57 , V_305 , V_306 , V_43 ;
if ( ! ( F_13 ( V_4 , V_299 ) &
V_307 ) )
return 0 ;
V_304 = false ;
V_57 = F_16 ( V_4 , 2 ) ;
if ( V_57 < 0 )
return V_57 ;
if ( ( V_57 & V_308 ) == V_308 ) {
V_57 = F_25 ( V_4 , 1 , 8 ) ;
if ( V_57 < 0 )
return V_57 ;
if ( V_57 >= 1 )
V_304 = true ;
}
if ( V_4 -> V_116 & V_309 )
V_304 = false ;
if ( V_304 ) {
V_305 = 0 ;
V_306 = V_310 | V_311 ;
} else {
V_305 = V_310 | V_311 ;
V_306 = 0 ;
}
V_57 = F_24 ( V_4 , 5 , V_305 , V_306 ) ;
if ( V_57 < 0 )
return V_57 ;
if ( V_304 )
V_43 = V_299 ;
else
V_43 = V_312 ;
F_11 ( V_4 , V_43 , V_313 ) ;
F_11 ( V_4 , V_312 ,
V_307 ) ;
return 0 ;
}
static int F_139 ( struct V_1 * V_4 )
{
static const T_10 V_273 [] = { 0x08 , 0x00 , 0x28 , 0x83 , 0x30 , 0x05 , } ;
int V_172 , V_49 ;
V_172 = F_16 ( V_4 , 2 ) ;
if ( V_172 < 0 )
return V_172 ;
if ( ( V_172 & V_308 ) != V_308 )
return 0 ;
for ( V_49 = F_9 ( V_273 ) - 1 ; V_49 >= 0 ; V_49 -- ) {
V_172 = F_25 ( V_4 , 1 , V_49 + 10 ) ;
if ( V_172 < 0 )
return V_172 ;
if ( V_172 != V_273 [ V_49 ] )
return 0 ;
}
return 1 ;
}
static int F_140 ( struct V_2 * V_3 ,
const V_41 * V_206 , T_9 V_94 )
{
struct V_1 * V_4 = V_1 ( V_3 ) ;
T_1 V_314 , V_315 , V_316 ;
int V_49 , V_57 ;
if ( F_136 ( V_4 ) ) {
F_20 ( V_4 , L_60 ) ;
return - V_53 ;
}
F_11 ( V_4 , V_299 ,
V_317 |
V_318 ) ;
F_15 ( V_4 ) ;
if ( ! ( V_4 -> V_116 & V_319 ) )
F_19 ( 50 ) ;
for ( V_314 = 0 , V_49 = 0 ; ! V_314 && V_49 < 150 ; V_49 ++ ) {
F_19 ( 1 ) ;
V_314 = F_13 ( V_4 , V_299 ) &
V_317 ;
}
if ( ! V_314 ) {
F_20 ( V_4 , L_61 ) ;
return - V_320 ;
}
if ( V_4 -> V_116 & V_275 ) {
V_57 = F_139 ( V_4 ) ;
if ( V_57 < 0 )
return V_57 ;
if ( V_57 )
F_4 ( V_4 , L_62 ) ;
else
V_4 -> V_116 &= ~ V_275 ;
}
F_11 ( V_4 , V_312 ,
V_321 ) ;
F_11 ( V_4 , V_322 , V_4 -> V_323 ) ;
F_11 ( V_4 , V_269 ,
V_324 |
V_270 ) ;
F_11 ( V_4 , V_325 ,
V_326 |
( V_327 << 4 ) |
( V_328 << 8 ) |
( 200 << 16 ) ) ;
V_4 -> V_249 = false ;
for ( V_49 = 0 ; V_49 < 32 ; V_49 ++ )
if ( V_4 -> V_235 & ( 1 << V_49 ) )
F_11 ( V_4 , F_141 ( V_49 ) ,
V_329 ) ;
V_315 = F_13 ( V_4 , V_46 ) & 0x00ff00ff ;
if ( V_315 >= V_330 ) {
F_11 ( V_4 , V_331 ,
0xfffffffe ) ;
V_3 -> V_332 = true ;
}
F_11 ( V_4 , V_333 , 0x3f ) ;
V_4 -> V_334 = F_13 ( V_4 , V_333 ) & 0x3f ;
F_11 ( V_4 , V_333 , 0 ) ;
V_3 -> V_335 = V_4 -> V_334 != 0 ;
F_11 ( V_4 , V_336 , 0x00010000 ) ;
F_11 ( V_4 , V_276 , ~ 0 ) ;
F_11 ( V_4 , V_337 , ~ 0 ) ;
V_57 = F_138 ( V_4 ) ;
if ( V_57 < 0 )
return V_57 ;
V_57 = F_29 ( V_3 , 4 , 0 , V_338 | V_339 ) ;
if ( V_57 < 0 )
return V_57 ;
if ( V_206 ) {
V_4 -> V_277 =
F_77 ( V_4 -> V_3 . V_79 , V_202 ,
& V_4 -> V_279 ,
V_127 ) ;
if ( V_4 -> V_277 == NULL )
return - V_140 ;
F_137 ( V_4 -> V_277 , V_206 , V_94 ) ;
} else {
V_4 -> V_277 = V_4 -> V_206 ;
V_4 -> V_279 = V_4 -> V_278 ;
}
V_4 -> V_281 = V_4 -> V_277 [ 0 ] ;
V_4 -> V_277 [ 0 ] = 0 ;
F_11 ( V_4 , V_282 , 0 ) ;
F_11 ( V_4 , V_280 ,
F_10 ( V_4 -> V_277 [ 2 ] ) ) ;
F_11 ( V_4 , V_340 , V_4 -> V_279 ) ;
F_11 ( V_4 , V_341 , 0x80000000 ) ;
V_316 = V_13 | V_14 |
V_11 | V_12 |
V_16 | V_15 |
V_17 |
V_10 |
V_21 |
V_20 |
V_22 |
V_18 |
V_342 ;
if ( V_6 & V_8 )
V_316 |= V_9 ;
F_11 ( V_4 , V_250 , V_316 ) ;
F_11 ( V_4 , V_299 ,
V_343 |
V_344 ) ;
F_11 ( V_4 , V_269 ,
V_345 |
V_346 ) ;
F_67 ( & V_4 -> V_118 ) ;
F_67 ( & V_4 -> V_291 ) ;
F_15 ( V_4 ) ;
F_142 ( & V_4 -> V_3 , false , true ) ;
return 0 ;
}
static int F_143 ( struct V_2 * V_3 ,
const V_41 * V_206 , T_9 V_94 )
{
struct V_1 * V_4 ;
V_41 * V_277 ;
T_2 V_156 ( V_279 ) ;
V_4 = V_1 ( V_3 ) ;
V_277 =
F_77 ( V_4 -> V_3 . V_79 , V_202 ,
& V_279 , V_127 ) ;
if ( V_277 == NULL )
return - V_140 ;
F_125 ( & V_4 -> V_155 ) ;
if ( V_4 -> V_277 == NULL ) {
V_4 -> V_277 = V_277 ;
V_4 -> V_279 = V_279 ;
V_277 = NULL ;
}
F_137 ( V_4 -> V_277 , V_206 , V_94 ) ;
V_4 -> V_281 = V_206 [ 0 ] ;
V_4 -> V_277 [ 0 ] = 0 ;
F_11 ( V_4 , V_340 , V_4 -> V_279 ) ;
F_126 ( & V_4 -> V_155 ) ;
if ( V_277 != NULL )
F_83 ( V_4 -> V_3 . V_79 , V_202 ,
V_277 , V_279 ) ;
F_142 ( & V_4 -> V_3 , true , true ) ;
return 0 ;
}
static void F_144 ( struct V_2 * V_3 , struct V_91 * V_174 )
{
struct V_1 * V_4 = V_1 ( V_3 ) ;
F_109 ( & V_4 -> V_220 , V_174 ) ;
}
static void F_145 ( struct V_2 * V_3 , struct V_91 * V_174 )
{
struct V_1 * V_4 = V_1 ( V_3 ) ;
F_109 ( & V_4 -> V_226 , V_174 ) ;
}
static int F_146 ( struct V_2 * V_3 , struct V_91 * V_174 )
{
struct V_1 * V_4 = V_1 ( V_3 ) ;
struct V_143 * V_63 = & V_4 -> V_220 ;
struct V_176 * V_176 = V_174 -> V_176 ;
int V_57 = - V_347 ;
F_96 ( & V_63 -> V_126 ) ;
if ( V_174 -> V_110 != 0 )
goto V_214;
if ( V_174 -> V_184 )
F_94 ( V_4 -> V_3 . V_79 , V_174 -> V_175 ,
V_174 -> V_99 , V_183 ) ;
F_7 ( V_4 , 'T' , V_174 -> V_31 , V_174 -> V_34 , 0x20 ) ;
V_176 -> V_174 = NULL ;
V_174 -> V_110 = V_189 ;
V_174 -> V_153 ( V_174 , & V_4 -> V_3 , V_174 -> V_110 ) ;
V_57 = 0 ;
V_214:
F_97 ( & V_63 -> V_126 ) ;
return V_57 ;
}
static int F_147 ( struct V_2 * V_3 ,
int V_29 , int V_26 )
{
#ifdef F_127
return 0 ;
#else
struct V_1 * V_4 = V_1 ( V_3 ) ;
unsigned long V_154 ;
int V_348 , V_57 = 0 ;
F_73 ( & V_4 -> V_155 , V_154 ) ;
if ( V_4 -> V_26 != V_26 ) {
V_57 = - V_349 ;
goto V_214;
}
V_348 = ( V_29 & 0xffc0 ) == V_350 ? V_29 & 0x3f : 63 ;
if ( V_348 < 32 )
F_11 ( V_4 , V_284 , 1 << V_348 ) ;
else
F_11 ( V_4 , V_283 , 1 << ( V_348 - 32 ) ) ;
F_15 ( V_4 ) ;
V_214:
F_75 ( & V_4 -> V_155 , V_154 ) ;
return V_57 ;
#endif
}
static T_1 F_148 ( struct V_2 * V_3 , int V_351 )
{
struct V_1 * V_4 = V_1 ( V_3 ) ;
unsigned long V_154 ;
T_1 V_352 ;
switch ( V_351 ) {
case V_353 :
case V_354 :
if ( V_4 -> V_268 &&
( F_13 ( V_4 , V_269 ) &
V_270 ) )
V_352 = V_355 ;
else
V_352 = 0 ;
if ( V_4 -> V_285 )
V_352 |= V_356 ;
return V_352 ;
case V_357 :
return F_13 ( V_4 , V_256 ) << 16 ;
case V_358 :
return F_116 ( V_4 ) ;
case V_359 :
F_73 ( & V_4 -> V_155 , V_154 ) ;
V_352 = F_117 ( V_4 ) ;
F_75 ( & V_4 -> V_155 , V_154 ) ;
return V_352 ;
case V_360 :
V_352 = F_13 ( V_4 , V_325 ) ;
return ( V_352 >> 4 ) & 0x0ffff00f ;
case V_361 :
return ( F_13 ( V_4 , V_333 ) & 0x3f ) |
( V_4 -> V_334 << 8 ) ;
default:
F_149 ( 1 ) ;
return 0 ;
}
}
static void F_150 ( struct V_2 * V_3 , int V_351 , T_1 V_352 )
{
struct V_1 * V_4 = V_1 ( V_3 ) ;
unsigned long V_154 ;
switch ( V_351 ) {
case V_353 :
if ( ( V_352 & V_355 ) && V_4 -> V_268 ) {
F_11 ( V_4 , V_362 ,
V_270 ) ;
F_15 ( V_4 ) ;
}
if ( V_352 & V_356 )
V_4 -> V_285 = false ;
break;
case V_354 :
if ( ( V_352 & V_355 ) && V_4 -> V_268 ) {
F_11 ( V_4 , V_269 ,
V_270 ) ;
F_15 ( V_4 ) ;
}
if ( V_352 & V_356 )
V_4 -> V_285 = true ;
break;
case V_357 :
F_11 ( V_4 , V_256 , V_352 >> 16 ) ;
F_15 ( V_4 ) ;
break;
case V_358 :
F_11 ( V_4 , V_246 , V_352 ) ;
F_11 ( V_4 , V_363 ,
V_20 ) ;
F_15 ( V_4 ) ;
break;
case V_359 :
F_73 ( & V_4 -> V_155 , V_154 ) ;
V_4 -> V_251 = ( F_117 ( V_4 ) & 0x40 ) |
( V_352 & ~ 0x7f ) ;
F_75 ( & V_4 -> V_155 , V_154 ) ;
break;
case V_360 :
V_352 = ( V_352 & 0xf ) | ( ( V_352 & 0xf ) << 4 ) |
( ( V_352 & 0xf ) << 8 ) | ( ( V_352 & 0x0ffff000 ) << 4 ) ;
F_11 ( V_4 , V_325 , V_352 ) ;
F_15 ( V_4 ) ;
break;
case V_361 :
F_11 ( V_4 , V_333 , V_352 & 0x3f ) ;
F_15 ( V_4 ) ;
break;
default:
F_149 ( 1 ) ;
break;
}
}
static void F_151 ( struct V_364 * V_63 )
{
V_63 -> V_365 . V_153 . V_366 ( & V_63 -> V_365 , V_63 -> V_367 ,
V_63 -> V_98 , V_63 -> V_34 ,
V_63 -> V_365 . V_368 ) ;
V_63 -> V_98 = 0 ;
}
static void F_152 ( struct V_364 * V_63 , const T_1 * V_369 )
{
T_1 * V_370 ;
if ( V_63 -> V_98 + V_63 -> V_365 . V_371 > V_71 ) {
if ( V_63 -> V_365 . V_372 )
return;
F_151 ( V_63 ) ;
}
V_370 = V_63 -> V_34 + V_63 -> V_98 ;
V_63 -> V_367 = ( V_373 ) F_72 ( ( V_40 T_4 ) V_369 [ 0 ] ) ;
if ( V_63 -> V_365 . V_371 > 0 )
V_370 [ 0 ] = F_153 ( V_369 [ 1 ] ) ;
if ( V_63 -> V_365 . V_371 > 4 )
V_370 [ 1 ] = F_153 ( V_369 [ 0 ] ) ;
if ( V_63 -> V_365 . V_371 > 8 )
memcpy ( & V_370 [ 2 ] , & V_369 [ 2 ] , V_63 -> V_365 . V_371 - 8 ) ;
V_63 -> V_98 += V_63 -> V_365 . V_371 ;
}
static int F_154 ( struct V_143 * V_143 ,
struct V_66 * V_67 ,
struct V_66 * V_85 )
{
struct V_364 * V_63 =
F_1 ( V_143 , struct V_364 , V_143 ) ;
struct V_66 * V_374 ;
T_1 V_375 ;
for ( V_374 = V_67 ; V_374 <= V_85 ; V_374 ++ )
if ( V_374 -> V_72 )
break;
if ( V_374 > V_85 )
return 0 ;
while ( ! ( V_67 -> V_135 & F_34 ( V_138 ) ) ) {
V_67 ++ ;
V_375 = F_72 ( V_67 -> V_139 ) ;
F_155 ( V_143 -> V_4 -> V_3 . V_79 ,
V_375 & V_376 ,
V_375 & ~ V_376 ,
F_49 ( V_67 -> V_134 ) ,
V_80 ) ;
}
F_152 ( V_63 , ( T_1 * ) ( V_85 + 1 ) ) ;
if ( V_85 -> V_135 & F_34 ( V_185 ) )
F_151 ( V_63 ) ;
return 1 ;
}
static int F_156 ( struct V_143 * V_143 ,
struct V_66 * V_67 ,
struct V_66 * V_85 )
{
struct V_364 * V_63 =
F_1 ( V_143 , struct V_364 , V_143 ) ;
unsigned int V_134 , V_70 , V_377 ;
T_1 V_375 ;
V_134 = F_49 ( V_85 -> V_134 ) ;
V_70 = F_49 ( F_47 ( V_85 -> V_70 ) ) ;
V_377 = V_134 - V_70 ;
V_375 = F_72 ( V_85 -> V_139 ) ;
if ( V_377 > 0 ) {
V_63 -> V_378 = V_375 ;
V_63 -> V_379 = V_377 ;
}
if ( V_70 != 0 )
return 0 ;
F_155 ( V_143 -> V_4 -> V_3 . V_79 ,
V_375 & V_376 ,
V_375 & ~ V_376 ,
V_377 , V_80 ) ;
if ( V_85 -> V_135 & F_34 ( V_185 ) ) {
V_63 -> V_365 . V_153 . V_380 ( & V_63 -> V_365 ,
V_375 + V_377 ,
V_63 -> V_365 . V_368 ) ;
V_63 -> V_379 = 0 ;
}
return 1 ;
}
static void F_157 ( struct V_364 * V_63 )
{
F_155 ( V_63 -> V_143 . V_4 -> V_3 . V_79 ,
V_63 -> V_378 & V_376 ,
V_63 -> V_378 & ~ V_376 ,
V_63 -> V_379 , V_80 ) ;
V_63 -> V_365 . V_153 . V_380 ( & V_63 -> V_365 ,
V_63 -> V_378 + V_63 -> V_379 ,
V_63 -> V_365 . V_368 ) ;
V_63 -> V_379 = 0 ;
}
static inline void F_158 ( struct V_143 * V_143 ,
struct V_66 * V_374 )
{
T_3 V_135 ;
T_1 V_375 ;
if ( V_374 -> V_135 & F_34 ( V_138 ) )
return;
V_374 += 2 ;
if ( ( F_72 ( V_374 -> V_139 ) & V_376 ) ==
( V_143 -> V_150 & V_376 ) ) {
if ( V_374 -> V_135 & F_34 ( V_138 ) )
return;
V_374 ++ ;
}
do {
V_375 = F_72 ( V_374 -> V_139 ) ;
F_155 ( V_143 -> V_4 -> V_3 . V_79 ,
V_375 & V_376 ,
V_375 & ~ V_376 ,
F_49 ( V_374 -> V_134 ) ,
V_183 ) ;
V_135 = V_374 -> V_135 ;
V_374 ++ ;
} while ( ! ( V_135 & F_34 ( V_138 ) ) );
}
static int F_159 ( struct V_143 * V_143 ,
struct V_66 * V_67 ,
struct V_66 * V_85 )
{
struct V_364 * V_63 =
F_1 ( V_143 , struct V_364 , V_143 ) ;
struct V_66 * V_374 ;
V_41 * V_370 ;
for ( V_374 = V_67 ; V_374 <= V_85 ; V_374 ++ )
if ( V_374 -> V_72 )
break;
if ( V_374 > V_85 )
return 0 ;
F_158 ( V_143 , V_67 ) ;
if ( V_63 -> V_98 + 4 > V_71 ) {
if ( V_63 -> V_365 . V_372 )
return 1 ;
F_151 ( V_63 ) ;
}
V_370 = V_63 -> V_34 + V_63 -> V_98 ;
V_63 -> V_367 = F_49 ( V_85 -> V_70 ) ;
* V_370 = F_106 ( ( F_49 ( V_374 -> V_72 ) << 16 ) |
F_49 ( V_374 -> V_70 ) ) ;
V_63 -> V_98 += 4 ;
if ( V_85 -> V_135 & F_34 ( V_185 ) )
F_151 ( V_63 ) ;
return 1 ;
}
static void F_160 ( struct V_1 * V_4 , T_6 V_381 )
{
T_1 V_382 = V_381 >> 32 , V_383 = V_381 ;
F_11 ( V_4 , V_384 , ~ V_382 ) ;
F_11 ( V_4 , V_385 , ~ V_383 ) ;
F_11 ( V_4 , V_386 , V_382 ) ;
F_11 ( V_4 , V_387 , V_383 ) ;
F_161 () ;
V_4 -> V_388 = V_381 ;
}
static struct V_389 * F_162 ( struct V_2 * V_3 ,
int type , int V_390 , T_9 V_371 )
{
struct V_1 * V_4 = V_1 ( V_3 ) ;
struct V_364 * V_156 ( V_63 ) ;
T_5 V_156 ( V_153 ) ;
T_6 * V_156 ( V_381 ) ;
T_1 * V_156 ( V_391 ) , V_156 ( V_74 ) ;
int V_65 , V_57 = - V_53 ;
F_125 ( & V_4 -> V_155 ) ;
switch ( type ) {
case V_392 :
V_391 = & V_4 -> V_393 ;
V_153 = F_159 ;
V_65 = F_132 ( * V_391 ) - 1 ;
if ( V_65 >= 0 ) {
* V_391 &= ~ ( 1 << V_65 ) ;
V_74 = F_113 ( V_65 ) ;
V_63 = & V_4 -> V_295 [ V_65 ] ;
}
break;
case V_394 :
V_381 = & V_4 -> V_395 ;
V_391 = & V_4 -> V_396 ;
V_153 = F_154 ;
V_65 = * V_381 & 1ULL << V_390 ? F_132 ( * V_391 ) - 1 : - 1 ;
if ( V_65 >= 0 ) {
* V_381 &= ~ ( 1ULL << V_390 ) ;
* V_391 &= ~ ( 1 << V_65 ) ;
V_74 = F_114 ( V_65 ) ;
V_63 = & V_4 -> V_293 [ V_65 ] ;
}
break;
case V_397 :
V_391 = & V_4 -> V_396 ;
V_153 = F_156 ;
V_65 = ! V_4 -> V_398 ? F_132 ( * V_391 ) - 1 : - 1 ;
if ( V_65 >= 0 ) {
V_4 -> V_398 = true ;
* V_391 &= ~ ( 1 << V_65 ) ;
V_74 = F_114 ( V_65 ) ;
V_63 = & V_4 -> V_293 [ V_65 ] ;
}
break;
default:
V_65 = - 1 ;
V_57 = - V_399 ;
}
F_126 ( & V_4 -> V_155 ) ;
if ( V_65 < 0 )
return F_163 ( V_57 ) ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_63 -> V_98 = 0 ;
V_63 -> V_34 = ( void * ) F_164 ( V_127 ) ;
if ( V_63 -> V_34 == NULL ) {
V_57 = - V_140 ;
goto V_214;
}
V_57 = F_79 ( & V_63 -> V_143 , V_4 , V_74 , V_153 ) ;
if ( V_57 < 0 )
goto V_400;
if ( type == V_397 ) {
F_160 ( V_4 , 0 ) ;
V_63 -> V_379 = 0 ;
}
return & V_63 -> V_365 ;
V_400:
F_165 ( ( unsigned long ) V_63 -> V_34 ) ;
V_214:
F_125 ( & V_4 -> V_155 ) ;
switch ( type ) {
case V_394 :
* V_381 |= 1ULL << V_390 ;
break;
case V_397 :
V_4 -> V_398 = false ;
break;
}
* V_391 |= 1 << V_65 ;
F_126 ( & V_4 -> V_155 ) ;
return F_163 ( V_57 ) ;
}
static int F_166 ( struct V_389 * V_365 ,
T_7 V_401 , T_1 V_402 , T_1 V_403 )
{
struct V_364 * V_63 = F_1 ( V_365 , struct V_364 , V_365 ) ;
struct V_1 * V_4 = V_63 -> V_143 . V_4 ;
T_1 V_135 = V_404 , V_405 ;
int V_65 ;
if ( V_63 -> V_143 . V_85 -> V_69 == 0 )
return - V_406 ;
switch ( V_63 -> V_365 . type ) {
case V_392 :
V_65 = V_63 - V_4 -> V_295 ;
V_405 = 0 ;
if ( V_401 >= 0 )
V_405 = V_407 |
( V_401 & 0x7fff ) << 16 ;
F_11 ( V_4 , V_294 , 1 << V_65 ) ;
F_11 ( V_4 , V_408 , 1 << V_65 ) ;
F_85 ( & V_63 -> V_143 , V_405 ) ;
break;
case V_397 :
V_135 |= V_409 | V_329 ;
case V_394 :
V_65 = V_63 - V_4 -> V_293 ;
V_405 = ( V_403 << 28 ) | ( V_402 << 8 ) | V_63 -> V_365 . V_390 ;
if ( V_401 >= 0 ) {
V_405 |= ( V_401 & 0x07fff ) << 12 ;
V_135 |= V_410 ;
}
F_11 ( V_4 , V_292 , 1 << V_65 ) ;
F_11 ( V_4 , V_411 , 1 << V_65 ) ;
F_11 ( V_4 , F_167 ( V_63 -> V_143 . V_74 ) , V_405 ) ;
F_85 ( & V_63 -> V_143 , V_135 ) ;
V_63 -> V_402 = V_402 ;
V_63 -> V_403 = V_403 ;
break;
}
return 0 ;
}
static int F_168 ( struct V_389 * V_365 )
{
struct V_1 * V_4 = V_1 ( V_365 -> V_3 ) ;
struct V_364 * V_63 = F_1 ( V_365 , struct V_364 , V_365 ) ;
int V_65 ;
switch ( V_63 -> V_365 . type ) {
case V_392 :
V_65 = V_63 - V_4 -> V_295 ;
F_11 ( V_4 , V_412 , 1 << V_65 ) ;
break;
case V_394 :
case V_397 :
V_65 = V_63 - V_4 -> V_293 ;
F_11 ( V_4 , V_413 , 1 << V_65 ) ;
break;
}
F_15 ( V_4 ) ;
F_87 ( & V_63 -> V_143 ) ;
F_169 ( & V_63 -> V_143 . V_126 ) ;
return 0 ;
}
static void F_170 ( struct V_389 * V_365 )
{
struct V_1 * V_4 = V_1 ( V_365 -> V_3 ) ;
struct V_364 * V_63 = F_1 ( V_365 , struct V_364 , V_365 ) ;
unsigned long V_154 ;
int V_65 ;
F_168 ( V_365 ) ;
F_81 ( & V_63 -> V_143 ) ;
F_165 ( ( unsigned long ) V_63 -> V_34 ) ;
F_73 ( & V_4 -> V_155 , V_154 ) ;
switch ( V_365 -> type ) {
case V_392 :
V_65 = V_63 - V_4 -> V_295 ;
V_4 -> V_393 |= 1 << V_65 ;
break;
case V_394 :
V_65 = V_63 - V_4 -> V_293 ;
V_4 -> V_396 |= 1 << V_65 ;
V_4 -> V_395 |= 1ULL << V_365 -> V_390 ;
break;
case V_397 :
V_65 = V_63 - V_4 -> V_293 ;
V_4 -> V_396 |= 1 << V_65 ;
V_4 -> V_395 |= V_4 -> V_388 ;
V_4 -> V_388 = 0 ;
V_4 -> V_398 = false ;
break;
}
F_75 ( & V_4 -> V_155 , V_154 ) ;
}
static int F_171 ( struct V_389 * V_365 , T_6 * V_381 )
{
struct V_1 * V_4 = V_1 ( V_365 -> V_3 ) ;
unsigned long V_154 ;
int V_57 ;
switch ( V_365 -> type ) {
case V_397 :
F_73 ( & V_4 -> V_155 , V_154 ) ;
if ( ~ V_4 -> V_395 & ~ V_4 -> V_388 & * V_381 ) {
* V_381 = V_4 -> V_395 ;
V_57 = - V_53 ;
} else {
F_160 ( V_4 , * V_381 ) ;
V_57 = 0 ;
}
F_75 ( & V_4 -> V_155 , V_154 ) ;
break;
default:
V_57 = - V_414 ;
}
return V_57 ;
}
static void F_172 ( struct V_1 * V_4 )
{
int V_49 ;
struct V_364 * V_63 ;
for ( V_49 = 0 ; V_49 < V_4 -> V_415 ; V_49 ++ ) {
V_63 = & V_4 -> V_293 [ V_49 ] ;
if ( V_63 -> V_143 . V_168 )
F_166 ( & V_63 -> V_365 , 0 , V_63 -> V_402 , V_63 -> V_403 ) ;
}
for ( V_49 = 0 ; V_49 < V_4 -> V_416 ; V_49 ++ ) {
V_63 = & V_4 -> V_295 [ V_49 ] ;
if ( V_63 -> V_143 . V_168 )
F_166 ( & V_63 -> V_365 , 0 , V_63 -> V_402 , V_63 -> V_403 ) ;
}
}
static int F_173 ( struct V_364 * V_63 ,
struct V_417 * V_174 ,
struct V_418 * V_76 ,
unsigned long V_109 )
{
struct V_66 * V_67 , * V_85 , * V_374 ;
struct V_417 * V_92 ;
T_4 * V_34 ;
T_2 V_166 , V_419 ;
T_1 V_141 , V_420 , V_421 , V_286 ;
T_1 V_422 , V_423 , V_424 ;
int V_59 , V_425 , V_49 , V_94 , V_43 ;
V_92 = V_174 ;
V_422 = V_109 ;
if ( V_92 -> V_426 )
V_141 = 1 ;
else
V_141 = 2 ;
if ( V_92 -> V_98 > 0 )
V_141 ++ ;
V_425 = F_174 ( V_422 + V_92 -> V_99 ) >> V_427 ;
if ( V_92 -> V_99 > 0 )
V_421 = V_425 - ( V_422 >> V_427 ) ;
else
V_421 = 0 ;
V_141 += V_421 ;
V_420 = F_175 ( V_92 -> V_98 , sizeof( * V_67 ) ) ;
V_67 = F_84 ( & V_63 -> V_143 , V_141 + V_420 , & V_166 ) ;
if ( V_67 == NULL )
return - V_140 ;
if ( ! V_92 -> V_426 ) {
V_67 [ 0 ] . V_135 = F_34 ( V_178 ) ;
V_67 [ 0 ] . V_134 = F_34 ( 8 ) ;
V_67 [ 0 ] . V_69 = F_33 ( V_166 | V_141 ) ;
V_34 = ( T_4 * ) & V_67 [ 1 ] ;
V_34 [ 0 ] = F_33 ( F_176 ( V_92 -> V_428 ) |
F_177 ( V_92 -> V_429 ) |
F_178 ( V_181 ) |
F_179 ( V_63 -> V_365 . V_390 ) |
F_180 ( V_63 -> V_365 . V_31 ) ) ;
V_34 [ 1 ] =
F_33 ( F_181 ( V_92 -> V_98 +
V_92 -> V_99 ) ) ;
}
if ( V_92 -> V_98 > 0 ) {
V_67 [ 2 ] . V_134 = F_34 ( V_92 -> V_98 ) ;
V_67 [ 2 ] . V_139 = F_33 ( V_166 + V_141 * sizeof( * V_67 ) ) ;
memcpy ( & V_67 [ V_141 ] , V_92 -> V_34 , V_92 -> V_98 ) ;
}
V_374 = V_67 + V_141 - V_421 ;
V_423 = V_422 + V_92 -> V_99 ;
for ( V_49 = 0 ; V_49 < V_421 ; V_49 ++ ) {
V_59 = V_422 >> V_427 ;
V_43 = V_422 & ~ V_376 ;
V_424 = ( V_59 + 1 ) << V_427 ;
V_94 =
F_182 ( V_424 , V_423 ) - V_422 ;
V_374 [ V_49 ] . V_134 = F_34 ( V_94 ) ;
V_419 = F_31 ( V_76 -> V_64 [ V_59 ] ) ;
V_374 [ V_49 ] . V_139 = F_33 ( V_419 + V_43 ) ;
F_183 ( V_63 -> V_143 . V_4 -> V_3 . V_79 ,
V_419 , V_43 , V_94 ,
V_183 ) ;
V_422 += V_94 ;
}
if ( V_92 -> V_430 )
V_286 = V_185 ;
else
V_286 = V_431 ;
V_85 = V_141 == 2 ? V_67 : V_67 + V_141 - 1 ;
V_85 -> V_135 |= F_34 ( V_162 |
V_137 |
V_138 |
V_286 ) ;
F_86 ( & V_63 -> V_143 , V_67 , V_141 , V_420 ) ;
return 0 ;
}
static int F_184 ( struct V_364 * V_63 ,
struct V_417 * V_174 ,
struct V_418 * V_76 ,
unsigned long V_109 )
{
struct V_79 * V_79 = V_63 -> V_143 . V_4 -> V_3 . V_79 ;
struct V_66 * V_67 , * V_374 ;
T_2 V_166 , V_419 ;
T_1 V_141 , V_420 , V_432 ;
int V_49 , V_261 , V_94 ;
int V_59 , V_43 , V_433 , V_371 , V_434 ;
V_433 = V_174 -> V_98 / V_63 -> V_365 . V_371 ;
V_371 = F_185 ( V_63 -> V_365 . V_371 , ( T_9 ) 8 ) ;
V_420 = F_175 ( V_371 , sizeof( * V_67 ) ) ;
V_59 = V_109 >> V_427 ;
V_43 = V_109 & ~ V_376 ;
V_434 = V_174 -> V_99 / V_433 ;
for ( V_49 = 0 ; V_49 < V_433 ; V_49 ++ ) {
V_141 = F_175 ( V_434 + V_43 , V_71 ) + 1 ;
V_67 = F_84 ( & V_63 -> V_143 ,
V_141 + V_420 , & V_166 ) ;
if ( V_67 == NULL )
return - V_140 ;
V_67 -> V_135 = F_34 ( V_137 |
V_136 ) ;
if ( V_174 -> V_426 && V_49 == 0 )
V_67 -> V_135 |= F_34 ( V_435 ) ;
V_67 -> V_134 = F_34 ( V_371 ) ;
V_67 -> V_70 = V_67 -> V_134 ;
V_67 -> V_72 = 0 ;
V_67 -> V_139 = F_33 ( V_166 + ( V_141 * sizeof( * V_67 ) ) ) ;
V_432 = V_434 ;
V_374 = V_67 ;
for ( V_261 = 1 ; V_261 < V_141 ; V_261 ++ ) {
V_374 ++ ;
V_374 -> V_135 = F_34 ( V_137 |
V_136 ) ;
if ( V_43 + V_432 < V_71 )
V_94 = V_432 ;
else
V_94 = V_71 - V_43 ;
V_374 -> V_134 = F_34 ( V_94 ) ;
V_374 -> V_70 = V_374 -> V_134 ;
V_374 -> V_72 = 0 ;
V_419 = F_31 ( V_76 -> V_64 [ V_59 ] ) ;
V_374 -> V_139 = F_33 ( V_419 + V_43 ) ;
F_183 ( V_79 , V_419 ,
V_43 , V_94 ,
V_80 ) ;
V_43 = ( V_43 + V_94 ) & ~ V_376 ;
V_432 -= V_94 ;
if ( V_43 == 0 )
V_59 ++ ;
}
V_374 -> V_135 = F_34 ( V_137 |
V_436 |
V_138 ) ;
if ( V_174 -> V_430 && V_49 == V_433 - 1 )
V_374 -> V_135 |= F_34 ( V_185 ) ;
F_86 ( & V_63 -> V_143 , V_67 , V_141 , V_420 ) ;
}
return 0 ;
}
static int F_186 ( struct V_364 * V_63 ,
struct V_417 * V_174 ,
struct V_418 * V_76 ,
unsigned long V_109 )
{
struct V_66 * V_67 ;
T_2 V_166 , V_419 ;
int V_59 , V_43 , V_432 , V_141 , V_49 , V_94 ;
V_59 = V_109 >> V_427 ;
V_43 = V_109 & ~ V_376 ;
V_432 = V_174 -> V_99 ;
V_141 = F_175 ( V_43 + V_432 , V_71 ) ;
if ( F_149 ( V_43 & 3 || V_432 & 3 || V_59 + V_141 > V_76 -> V_437 ) )
return - V_438 ;
for ( V_49 = 0 ; V_49 < V_141 ; V_49 ++ ) {
V_67 = F_84 ( & V_63 -> V_143 , 1 , & V_166 ) ;
if ( V_67 == NULL )
return - V_140 ;
V_67 -> V_135 = F_34 ( V_136 |
V_138 ) ;
if ( V_174 -> V_426 && V_49 == 0 )
V_67 -> V_135 |= F_34 ( V_435 ) ;
if ( V_174 -> V_430 && V_49 == V_141 - 1 )
V_67 -> V_135 |= F_34 ( V_185 ) ;
if ( V_43 + V_432 < V_71 )
V_94 = V_432 ;
else
V_94 = V_71 - V_43 ;
V_67 -> V_134 = F_34 ( V_94 ) ;
V_67 -> V_70 = V_67 -> V_134 ;
V_67 -> V_72 = 0 ;
V_419 = F_31 ( V_76 -> V_64 [ V_59 ] ) ;
V_67 -> V_139 = F_33 ( V_419 + V_43 ) ;
F_183 ( V_63 -> V_143 . V_4 -> V_3 . V_79 ,
V_419 , V_43 , V_94 ,
V_80 ) ;
V_432 -= V_94 ;
V_43 = 0 ;
V_59 ++ ;
F_86 ( & V_63 -> V_143 , V_67 , 1 , 0 ) ;
}
return 0 ;
}
static int F_187 ( struct V_389 * V_365 ,
struct V_417 * V_174 ,
struct V_418 * V_76 ,
unsigned long V_109 )
{
struct V_364 * V_63 = F_1 ( V_365 , struct V_364 , V_365 ) ;
unsigned long V_154 ;
int V_57 = - V_399 ;
F_73 ( & V_63 -> V_143 . V_4 -> V_155 , V_154 ) ;
switch ( V_365 -> type ) {
case V_392 :
V_57 = F_173 ( V_63 , V_174 , V_76 , V_109 ) ;
break;
case V_394 :
V_57 = F_184 ( V_63 , V_174 , V_76 , V_109 ) ;
break;
case V_397 :
V_57 = F_186 ( V_63 , V_174 , V_76 , V_109 ) ;
break;
}
F_75 ( & V_63 -> V_143 . V_4 -> V_155 , V_154 ) ;
return V_57 ;
}
static void F_188 ( struct V_389 * V_365 )
{
struct V_143 * V_63 =
& F_1 ( V_365 , struct V_364 , V_365 ) -> V_143 ;
F_11 ( V_63 -> V_4 , F_36 ( V_63 -> V_74 ) , V_75 ) ;
}
static int F_189 ( struct V_389 * V_365 )
{
struct V_364 * V_63 = F_1 ( V_365 , struct V_364 , V_365 ) ;
int V_57 = 0 ;
F_96 ( & V_63 -> V_143 . V_126 ) ;
if ( ! F_190 ( 0 , & V_63 -> V_439 ) ) {
F_70 ( ( unsigned long ) & V_63 -> V_143 ) ;
switch ( V_365 -> type ) {
case V_392 :
case V_394 :
if ( V_63 -> V_98 != 0 )
F_151 ( V_63 ) ;
break;
case V_397 :
if ( V_63 -> V_379 != 0 )
F_157 ( V_63 ) ;
break;
default:
V_57 = - V_399 ;
}
F_191 ( 0 , & V_63 -> V_439 ) ;
F_192 () ;
}
F_97 ( & V_63 -> V_143 . V_126 ) ;
return V_57 ;
}
static void F_193 ( struct V_440 * V_441 )
{
if ( F_194 ( V_442 ) ) {
struct V_443 * V_444 = F_195 ( V_441 ) ;
if ( V_444 ) {
F_196 ( V_445 , V_444 , 0 , 1 ) ;
F_196 ( V_446 , V_444 , 0 , 1 ) ;
}
}
}
static void F_197 ( struct V_440 * V_441 )
{
if ( F_194 ( V_442 ) ) {
struct V_443 * V_444 = F_195 ( V_441 ) ;
if ( V_444 ) {
F_196 ( V_446 , V_444 , 0 , 0 ) ;
F_196 ( V_445 , V_444 , 0 , 0 ) ;
}
}
}
static inline void F_193 ( struct V_440 * V_441 ) {}
static inline void F_197 ( struct V_440 * V_441 ) {}
static int F_198 ( struct V_440 * V_441 ,
const struct V_447 * V_448 )
{
struct V_1 * V_4 ;
T_1 V_449 , V_450 , V_451 , V_315 ;
T_6 V_452 ;
int V_49 , V_453 ;
T_9 V_303 ;
if ( V_441 -> V_454 == V_455 ) {
F_199 ( & V_441 -> V_441 , L_63 ) ;
return - V_399 ;
}
V_4 = F_200 ( sizeof( * V_4 ) , V_127 ) ;
if ( V_4 == NULL ) {
V_453 = - V_140 ;
goto V_456;
}
F_201 ( & V_4 -> V_3 , & V_457 , & V_441 -> V_441 ) ;
F_193 ( V_441 ) ;
V_453 = F_202 ( V_441 ) ;
if ( V_453 ) {
F_199 ( & V_441 -> V_441 , L_64 ) ;
goto V_458;
}
F_203 ( V_441 ) ;
F_204 ( V_441 , V_459 , 0 ) ;
F_205 ( V_441 , V_4 ) ;
F_206 ( & V_4 -> V_155 ) ;
F_207 ( & V_4 -> V_61 ) ;
F_208 ( & V_4 -> F_124 , F_124 ) ;
if ( ! ( F_209 ( V_441 , 0 ) & V_460 ) ||
F_210 ( V_441 , 0 ) < V_461 ) {
F_20 ( V_4 , L_65 ) ;
V_453 = - V_462 ;
goto V_463;
}
V_453 = F_211 ( V_441 , 0 , V_464 ) ;
if ( V_453 ) {
F_20 ( V_4 , L_66 ) ;
goto V_463;
}
V_4 -> V_45 = F_212 ( V_441 , 0 , V_461 ) ;
if ( V_4 -> V_45 == NULL ) {
F_20 ( V_4 , L_67 ) ;
V_453 = - V_462 ;
goto V_465;
}
for ( V_49 = 0 ; V_49 < F_9 ( V_466 ) ; V_49 ++ )
if ( ( V_466 [ V_49 ] . V_454 == V_441 -> V_454 ) &&
( V_466 [ V_49 ] . V_79 == ( unsigned short ) V_467 ||
V_466 [ V_49 ] . V_79 == V_441 -> V_79 ) &&
( V_466 [ V_49 ] . V_468 == ( unsigned short ) V_467 ||
V_466 [ V_49 ] . V_468 >= V_441 -> V_468 ) ) {
V_4 -> V_116 = V_466 [ V_49 ] . V_154 ;
break;
}
if ( V_469 )
V_4 -> V_116 = V_469 ;
F_92 ( V_77 * sizeof( struct V_66 ) > V_71 / 4 ) ;
F_92 ( V_470 > V_71 / 2 ) ;
V_4 -> V_131 = F_77 ( V_4 -> V_3 . V_79 ,
V_71 ,
& V_4 -> V_133 ,
V_127 ) ;
if ( ! V_4 -> V_131 ) {
V_453 = - V_140 ;
goto V_471;
}
V_453 = F_60 ( & V_4 -> V_118 , V_4 , 0 ,
V_472 ) ;
if ( V_453 < 0 )
goto V_473;
V_453 = F_60 ( & V_4 -> V_291 , V_4 , V_71 / 4 ,
V_474 ) ;
if ( V_453 < 0 )
goto V_475;
V_453 = F_79 ( & V_4 -> V_220 , V_4 ,
V_476 , F_98 ) ;
if ( V_453 < 0 )
goto V_477;
V_453 = F_79 ( & V_4 -> V_226 , V_4 ,
V_478 , F_98 ) ;
if ( V_453 < 0 )
goto V_479;
F_11 ( V_4 , V_411 , ~ 0 ) ;
V_4 -> V_395 = ~ 0ULL ;
V_4 -> V_235 = F_13 ( V_4 , V_411 ) ;
F_11 ( V_4 , V_413 , ~ 0 ) ;
V_4 -> V_396 = V_4 -> V_235 ;
V_4 -> V_415 = F_213 ( V_4 -> V_396 ) ;
V_303 = sizeof( struct V_364 ) * V_4 -> V_415 ;
V_4 -> V_293 = F_200 ( V_303 , V_127 ) ;
F_11 ( V_4 , V_408 , ~ 0 ) ;
V_4 -> V_234 = F_13 ( V_4 , V_408 ) ;
F_11 ( V_4 , V_412 , ~ 0 ) ;
V_4 -> V_393 = V_4 -> V_234 ;
V_4 -> V_416 = F_213 ( V_4 -> V_393 ) ;
V_303 = sizeof( struct V_364 ) * V_4 -> V_416 ;
V_4 -> V_295 = F_200 ( V_303 , V_127 ) ;
if ( V_4 -> V_295 == NULL || V_4 -> V_293 == NULL ) {
V_453 = - V_140 ;
goto V_480;
}
V_4 -> V_253 = V_4 -> V_131 + V_71 / 2 ;
V_4 -> V_323 = V_4 -> V_133 + V_71 / 2 ;
V_449 = F_13 ( V_4 , V_280 ) ;
V_450 = ( V_449 >> 12 ) & 0xf ;
V_451 = V_449 & 0x7 ;
V_452 = ( ( T_6 ) F_13 ( V_4 , V_481 ) << 32 ) |
F_13 ( V_4 , V_482 ) ;
if ( ! ( V_4 -> V_116 & V_483 ) )
F_214 ( V_441 ) ;
if ( F_215 ( V_441 -> V_286 , F_129 ,
F_216 ( V_441 ) ? 0 : V_484 ,
V_464 , V_4 ) ) {
F_20 ( V_4 , L_68 , V_441 -> V_286 ) ;
V_453 = - V_320 ;
goto V_485;
}
V_453 = F_217 ( & V_4 -> V_3 , V_450 , V_451 , V_452 ) ;
if ( V_453 )
goto V_486;
V_315 = F_13 ( V_4 , V_46 ) & 0x00ff00ff ;
F_4 ( V_4 ,
L_69
L_70 ,
V_315 >> 16 , V_315 & 0xff , V_4 -> V_3 . V_65 ,
V_4 -> V_415 , V_4 -> V_416 , V_4 -> V_116 ) ;
return 0 ;
V_486:
F_218 ( V_441 -> V_286 , V_4 ) ;
V_485:
F_219 ( V_441 ) ;
V_480:
F_220 ( V_4 -> V_293 ) ;
F_220 ( V_4 -> V_295 ) ;
F_81 ( & V_4 -> V_226 ) ;
V_479:
F_81 ( & V_4 -> V_220 ) ;
V_477:
F_37 ( & V_4 -> V_291 ) ;
V_475:
F_37 ( & V_4 -> V_118 ) ;
V_473:
F_83 ( V_4 -> V_3 . V_79 , V_71 ,
V_4 -> V_131 , V_4 -> V_133 ) ;
V_471:
F_221 ( V_441 , V_4 -> V_45 ) ;
V_465:
F_222 ( V_441 , 0 ) ;
V_463:
F_223 ( V_441 ) ;
V_458:
F_220 ( V_4 ) ;
F_197 ( V_441 ) ;
V_456:
return V_453 ;
}
static void F_224 ( struct V_440 * V_441 )
{
struct V_1 * V_4 = F_225 ( V_441 ) ;
if ( F_13 ( V_4 , V_299 ) & V_317 ) {
F_11 ( V_4 , V_337 , ~ 0 ) ;
F_15 ( V_4 ) ;
}
F_226 ( & V_4 -> F_124 ) ;
F_227 ( & V_4 -> V_3 ) ;
F_136 ( V_4 ) ;
F_218 ( V_441 -> V_286 , V_4 ) ;
if ( V_4 -> V_277 && V_4 -> V_277 != V_4 -> V_206 )
F_83 ( V_4 -> V_3 . V_79 , V_202 ,
V_4 -> V_277 , V_4 -> V_279 ) ;
if ( V_4 -> V_206 )
F_83 ( V_4 -> V_3 . V_79 , V_202 ,
V_4 -> V_206 , V_4 -> V_278 ) ;
F_37 ( & V_4 -> V_118 ) ;
F_37 ( & V_4 -> V_291 ) ;
F_83 ( V_4 -> V_3 . V_79 , V_71 ,
V_4 -> V_131 , V_4 -> V_133 ) ;
F_81 ( & V_4 -> V_220 ) ;
F_81 ( & V_4 -> V_226 ) ;
F_220 ( V_4 -> V_295 ) ;
F_220 ( V_4 -> V_293 ) ;
F_219 ( V_441 ) ;
F_221 ( V_441 , V_4 -> V_45 ) ;
F_222 ( V_441 , 0 ) ;
F_223 ( V_441 ) ;
F_220 ( V_4 ) ;
F_197 ( V_441 ) ;
F_228 ( & V_441 -> V_441 , L_71 ) ;
}
static int F_229 ( struct V_440 * V_441 , T_11 V_487 )
{
struct V_1 * V_4 = F_225 ( V_441 ) ;
int V_453 ;
F_136 ( V_4 ) ;
V_453 = F_230 ( V_441 ) ;
if ( V_453 ) {
F_20 ( V_4 , L_72 ) ;
return V_453 ;
}
V_453 = F_231 ( V_441 , F_232 ( V_441 , V_487 ) ) ;
if ( V_453 )
F_20 ( V_4 , L_73 , V_453 ) ;
F_197 ( V_441 ) ;
return 0 ;
}
static int F_233 ( struct V_440 * V_441 )
{
struct V_1 * V_4 = F_225 ( V_441 ) ;
int V_453 ;
F_193 ( V_441 ) ;
F_231 ( V_441 , V_488 ) ;
F_234 ( V_441 ) ;
V_453 = F_202 ( V_441 ) ;
if ( V_453 ) {
F_20 ( V_4 , L_74 ) ;
return V_453 ;
}
if ( ! F_13 ( V_4 , V_482 ) &&
! F_13 ( V_4 , V_481 ) ) {
F_11 ( V_4 , V_482 , ( T_1 ) V_4 -> V_3 . V_452 ) ;
F_11 ( V_4 , V_481 , ( T_1 ) ( V_4 -> V_3 . V_452 >> 32 ) ) ;
}
V_453 = F_140 ( & V_4 -> V_3 , NULL , 0 ) ;
if ( V_453 )
return V_453 ;
F_172 ( V_4 ) ;
return 0 ;
}
static int T_12 F_235 ( void )
{
V_290 = F_236 ( V_489 , V_490 , 0 ) ;
if ( ! V_290 )
return - V_140 ;
return F_237 ( & V_491 ) ;
}
static void T_13 F_238 ( void )
{
F_239 ( & V_491 ) ;
F_240 ( V_290 ) ;
}
