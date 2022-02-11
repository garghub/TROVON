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
F_38 ( V_63 -> V_76 ) ;
for ( V_49 = 0 ; V_49 < V_77 ; V_49 ++ )
if ( V_63 -> V_64 [ V_49 ] ) {
F_39 ( V_63 -> V_4 -> V_3 . V_78 ,
F_30 ( V_63 , V_49 ) ,
V_71 , V_79 ) ;
F_40 ( V_63 -> V_64 [ V_49 ] ) ;
}
}
static void F_41 ( struct V_62 * V_63 , const char * V_80 )
{
struct V_1 * V_4 = V_63 -> V_4 ;
if ( F_13 ( V_4 , F_42 ( V_63 -> V_74 ) ) & V_81 ) {
F_11 ( V_4 , F_42 ( V_63 -> V_74 ) , V_81 ) ;
F_15 ( V_4 ) ;
F_20 ( V_4 , L_33 , V_80 ) ;
}
}
static inline unsigned int F_43 ( unsigned int V_65 )
{
return ( V_65 + 1 ) % V_77 ;
}
static inline unsigned int F_44 ( struct V_62 * V_63 )
{
return F_43 ( V_63 -> V_73 ) ;
}
static unsigned int F_45 ( struct V_62 * V_63 ,
unsigned int * V_82 )
{
unsigned int V_49 , V_83 , V_84 = V_63 -> V_73 ;
T_3 V_70 , V_85 ;
V_49 = F_44 ( V_63 ) ;
V_70 = F_46 ( V_63 -> V_68 [ V_49 ] . V_70 ) ;
while ( V_49 != V_84 && V_70 == 0 ) {
V_83 = F_43 ( V_49 ) ;
F_47 () ;
V_85 = F_46 (
V_63 -> V_68 [ V_83 ] . V_70 ) ;
if ( V_85 == F_34 ( V_71 ) ) {
if ( V_86 > V_71 && V_49 != V_84 ) {
V_83 = F_43 ( V_83 ) ;
F_47 () ;
V_85 = F_46 (
V_63 -> V_68 [ V_83 ] . V_70 ) ;
if ( V_85 != F_34 ( V_71 ) )
goto V_87;
}
break;
}
V_87:
V_49 = V_83 ;
V_70 = V_85 ;
}
F_47 () ;
* V_82 = V_71 - F_48 ( V_70 ) ;
if ( * V_82 > V_71 ) {
* V_82 = 0 ;
F_41 ( V_63 , L_34 ) ;
}
return V_49 ;
}
static void F_49 ( struct V_62 * V_63 ,
unsigned int V_88 ,
unsigned int V_89 )
{
unsigned int V_49 ;
V_49 = F_44 ( V_63 ) ;
while ( V_49 != V_88 ) {
F_50 ( V_63 -> V_4 -> V_3 . V_78 ,
F_30 ( V_63 , V_49 ) ,
V_71 , V_79 ) ;
V_49 = F_43 ( V_49 ) ;
}
if ( V_89 > 0 )
F_50 ( V_63 -> V_4 -> V_3 . V_78 ,
F_30 ( V_63 , V_49 ) ,
V_89 , V_79 ) ;
}
static T_4 * F_51 ( struct V_62 * V_63 , T_4 * V_76 )
{
struct V_1 * V_4 = V_63 -> V_4 ;
struct V_90 V_91 ;
T_1 V_92 , V_93 , V_35 ;
int V_5 ;
V_91 . V_34 [ 0 ] = F_52 ( V_76 [ 0 ] ) ;
V_91 . V_34 [ 1 ] = F_52 ( V_76 [ 1 ] ) ;
V_91 . V_34 [ 2 ] = F_52 ( V_76 [ 2 ] ) ;
V_35 = ( V_91 . V_34 [ 0 ] >> 4 ) & 0x0f ;
switch ( V_35 ) {
case V_94 :
case V_95 :
V_91 . V_34 [ 3 ] = ( V_40 V_96 ) V_76 [ 3 ] ;
V_91 . V_97 = 16 ;
V_91 . V_98 = 0 ;
break;
case V_99 :
V_91 . V_34 [ 3 ] = F_52 ( V_76 [ 3 ] ) ;
V_91 . V_97 = 16 ;
V_91 . V_98 = 0 ;
break;
case V_100 :
case V_101 :
case V_102 :
case V_103 :
V_91 . V_34 [ 3 ] = F_52 ( V_76 [ 3 ] ) ;
V_91 . V_97 = 16 ;
V_91 . V_98 = V_91 . V_34 [ 3 ] >> 16 ;
if ( V_91 . V_98 > V_104 ) {
F_41 ( V_63 , L_35 ) ;
return NULL ;
}
break;
case V_105 :
case V_106 :
case V_107 :
V_91 . V_97 = 12 ;
V_91 . V_98 = 0 ;
break;
default:
F_41 ( V_63 , L_36 ) ;
return NULL ;
}
V_91 . V_108 = ( void * ) V_76 + V_91 . V_97 ;
V_93 = ( V_91 . V_97 + V_91 . V_98 + 3 ) / 4 ;
V_92 = F_52 ( V_76 [ V_93 ] ) ;
V_5 = ( V_92 >> 16 ) & 0x1f ;
V_91 . V_109 = V_5 - 16 ;
V_91 . V_31 = ( V_92 >> 21 ) & 0x7 ;
V_91 . V_110 = V_92 & 0xffff ;
V_91 . V_26 = V_4 -> V_111 ;
F_7 ( V_4 , 'R' , V_91 . V_31 , V_91 . V_34 , V_5 ) ;
if ( V_5 == V_112 &&
( V_91 . V_34 [ 0 ] & 0xff ) == ( V_113 << 4 ) )
V_91 . V_109 = V_114 ;
if ( V_5 == V_39 ) {
if ( ! ( V_4 -> V_115 & V_116 ) )
V_4 -> V_111 = ( V_91 . V_34 [ 2 ] >> 16 ) & 0xff ;
} else if ( V_63 == & V_4 -> V_117 ) {
F_53 ( & V_4 -> V_3 , & V_91 ) ;
} else {
F_54 ( & V_4 -> V_3 , & V_91 ) ;
}
return V_76 + V_93 + 1 ;
}
static void * F_55 ( struct V_62 * V_63 , void * V_91 , void * V_118 )
{
void * V_119 ;
while ( V_91 < V_118 ) {
V_119 = F_51 ( V_63 , V_91 ) ;
if ( ! V_119 )
return V_91 ;
V_91 = V_119 ;
}
return V_91 ;
}
static void F_56 ( struct V_62 * V_63 , unsigned int V_120 )
{
unsigned int V_49 ;
V_49 = F_44 ( V_63 ) ;
while ( V_49 != V_120 ) {
F_57 ( V_63 -> V_4 -> V_3 . V_78 ,
F_30 ( V_63 , V_49 ) ,
V_71 , V_79 ) ;
F_32 ( V_63 , V_49 ) ;
V_49 = F_43 ( V_49 ) ;
}
}
static void F_58 ( unsigned long V_44 )
{
struct V_62 * V_63 = (struct V_62 * ) V_44 ;
unsigned int V_88 , V_89 ;
void * V_91 , * V_118 ;
V_91 = V_63 -> V_121 ;
if ( ! V_91 )
return;
V_88 = F_45 ( V_63 ,
& V_89 ) ;
F_49 ( V_63 , V_88 , V_89 ) ;
V_118 = V_63 -> V_76 + V_88 * V_71 + V_89 ;
if ( V_88 < F_44 ( V_63 ) ) {
void * V_122 = V_63 -> V_76 + V_77 * V_71 ;
V_91 = F_55 ( V_63 , V_91 , V_122 ) ;
if ( V_91 < V_122 )
goto error;
V_91 -= V_77 * V_71 ;
}
V_91 = F_55 ( V_63 , V_91 , V_118 ) ;
if ( V_91 != V_118 ) {
if ( V_91 > V_118 )
F_41 ( V_63 , L_37 ) ;
goto error;
}
V_63 -> V_121 = V_91 ;
F_56 ( V_63 , V_88 ) ;
return;
error:
V_63 -> V_121 = NULL ;
}
static int F_59 ( struct V_62 * V_63 , struct V_1 * V_4 ,
unsigned int V_123 , T_1 V_74 )
{
unsigned int V_49 ;
T_2 V_124 ;
struct V_59 * V_64 [ V_77 + V_125 ] ;
struct V_66 * V_67 ;
V_63 -> V_74 = V_74 ;
V_63 -> V_4 = V_4 ;
F_60 ( & V_63 -> V_126 , F_58 , ( unsigned long ) V_63 ) ;
for ( V_49 = 0 ; V_49 < V_77 ; V_49 ++ ) {
V_63 -> V_64 [ V_49 ] = F_61 ( V_127 | V_128 ) ;
if ( ! V_63 -> V_64 [ V_49 ] )
goto V_129;
V_124 = F_62 ( V_4 -> V_3 . V_78 , V_63 -> V_64 [ V_49 ] ,
0 , V_71 , V_79 ) ;
if ( F_63 ( V_4 -> V_3 . V_78 , V_124 ) ) {
F_40 ( V_63 -> V_64 [ V_49 ] ) ;
V_63 -> V_64 [ V_49 ] = NULL ;
goto V_129;
}
F_64 ( V_63 -> V_64 [ V_49 ] , V_124 ) ;
}
for ( V_49 = 0 ; V_49 < V_77 ; V_49 ++ )
V_64 [ V_49 ] = V_63 -> V_64 [ V_49 ] ;
for ( V_49 = 0 ; V_49 < V_125 ; V_49 ++ )
V_64 [ V_77 + V_49 ] = V_63 -> V_64 [ V_49 ] ;
V_63 -> V_76 = F_65 ( V_64 , F_9 ( V_64 ) , V_130 , V_131 ) ;
if ( ! V_63 -> V_76 )
goto V_129;
V_63 -> V_68 = V_4 -> V_132 + V_123 ;
V_63 -> V_133 = V_4 -> V_134 + V_123 ;
for ( V_49 = 0 ; V_49 < V_77 ; V_49 ++ ) {
V_67 = & V_63 -> V_68 [ V_49 ] ;
V_67 -> V_135 = F_34 ( V_71 ) ;
V_67 -> V_136 = F_34 ( V_137 |
V_138 |
V_139 ) ;
V_67 -> V_140 = F_33 ( F_30 ( V_63 , V_49 ) ) ;
V_67 -> V_69 = F_33 ( V_63 -> V_133 +
F_43 ( V_49 ) * sizeof( struct V_66 ) ) ;
}
return 0 ;
V_129:
F_37 ( V_63 ) ;
return - V_141 ;
}
static void F_66 ( struct V_62 * V_63 )
{
unsigned int V_49 ;
for ( V_49 = 0 ; V_49 < V_77 ; V_49 ++ )
F_32 ( V_63 , V_49 ) ;
V_63 -> V_121 = V_63 -> V_76 ;
F_11 ( V_63 -> V_4 , F_67 ( V_63 -> V_74 ) , V_63 -> V_133 | 1 ) ;
F_11 ( V_63 -> V_4 , F_36 ( V_63 -> V_74 ) , V_81 ) ;
}
static struct V_66 * F_68 ( struct V_66 * V_67 , int V_142 )
{
T_3 V_143 ;
V_143 = V_67 -> V_136 & F_34 ( V_139 ) ;
if ( V_142 == 2 && V_143 == F_34 ( V_139 ) )
return V_67 ;
else
return V_67 + V_142 - 1 ;
}
static void F_69 ( unsigned long V_44 )
{
struct V_144 * V_63 = (struct V_144 * ) V_44 ;
struct V_66 * V_67 , * V_84 ;
T_1 V_145 ;
int V_142 ;
struct V_146 * V_147 ;
V_147 = F_70 ( V_63 -> V_148 . V_119 ,
struct V_146 , V_149 ) ;
V_84 = V_63 -> V_84 ;
while ( V_84 -> V_69 != 0 ) {
struct V_146 * V_150 = V_147 ;
V_145 = F_71 ( V_84 -> V_69 ) ;
V_142 = V_145 & 0xf ;
V_145 &= ~ 0xf ;
V_63 -> V_151 = V_145 ;
if ( V_145 < V_147 -> V_152 ||
V_145 >= V_147 -> V_152 + V_147 -> V_153 )
V_147 = F_70 ( V_147 -> V_149 . V_119 ,
struct V_146 , V_149 ) ;
V_67 = V_147 -> V_76 + ( V_145 - V_147 -> V_152 ) / sizeof( * V_67 ) ;
V_84 = F_68 ( V_67 , V_142 ) ;
if ( ! V_63 -> V_154 ( V_63 , V_67 , V_84 ) )
break;
if ( V_150 != V_147 ) {
unsigned long V_155 ;
V_150 -> V_153 = 0 ;
F_72 ( & V_63 -> V_4 -> V_156 , V_155 ) ;
F_73 ( & V_150 -> V_149 , & V_63 -> V_148 ) ;
F_74 ( & V_63 -> V_4 -> V_156 , V_155 ) ;
}
V_63 -> V_84 = V_84 ;
}
}
static int F_75 ( struct V_144 * V_63 )
{
struct V_146 * V_147 ;
T_2 V_157 ( V_158 ) ;
int V_43 ;
if ( V_63 -> V_159 >= 16 * 1024 * 1024 )
return - V_141 ;
V_147 = F_76 ( V_63 -> V_4 -> V_3 . V_78 , V_71 ,
& V_158 , V_160 ) ;
if ( ! V_147 )
return - V_141 ;
V_43 = ( void * ) & V_147 -> V_76 - ( void * ) V_147 ;
V_147 -> V_161 = V_71 - V_43 ;
V_147 -> V_152 = V_158 + V_43 ;
V_147 -> V_153 = 0 ;
F_77 ( & V_147 -> V_149 , & V_63 -> V_148 ) ;
V_63 -> V_159 += V_71 ;
return 0 ;
}
static int F_78 ( struct V_144 * V_63 , struct V_1 * V_4 ,
T_1 V_74 , T_5 V_154 )
{
V_63 -> V_4 = V_4 ;
V_63 -> V_74 = V_74 ;
V_63 -> V_159 = 0 ;
F_79 ( & V_63 -> V_148 ) ;
if ( F_75 ( V_63 ) < 0 )
return - V_141 ;
V_63 -> V_162 = F_70 ( V_63 -> V_148 . V_119 ,
struct V_146 , V_149 ) ;
F_60 ( & V_63 -> V_126 , F_69 , ( unsigned long ) V_63 ) ;
V_63 -> V_154 = V_154 ;
memset ( V_63 -> V_162 -> V_76 , 0 , sizeof( * V_63 -> V_162 -> V_76 ) ) ;
V_63 -> V_162 -> V_76 -> V_136 = F_34 ( V_163 ) ;
V_63 -> V_162 -> V_76 -> V_72 = F_34 ( 0x8011 ) ;
V_63 -> V_162 -> V_153 += sizeof( * V_63 -> V_162 -> V_76 ) ;
V_63 -> V_84 = V_63 -> V_162 -> V_76 ;
V_63 -> V_164 = V_63 -> V_162 -> V_76 ;
V_63 -> V_165 = 1 ;
return 0 ;
}
static void F_80 ( struct V_144 * V_63 )
{
struct V_2 * V_3 = & V_63 -> V_4 -> V_3 ;
struct V_146 * V_147 , * V_166 ;
F_81 (desc, tmp, &ctx->buffer_list, list)
F_82 ( V_3 -> V_78 , V_71 , V_147 ,
V_147 -> V_152 -
( ( void * ) & V_147 -> V_76 - ( void * ) V_147 ) ) ;
}
static struct V_66 * F_83 ( struct V_144 * V_63 ,
int V_142 , T_2 * V_167 )
{
struct V_66 * V_67 = NULL ;
struct V_146 * V_147 = V_63 -> V_162 ;
if ( V_142 * sizeof( * V_67 ) > V_147 -> V_161 )
return NULL ;
if ( V_142 * sizeof( * V_67 ) > V_147 -> V_161 - V_147 -> V_153 ) {
if ( V_147 -> V_149 . V_119 == & V_63 -> V_148 ) {
if ( F_75 ( V_63 ) < 0 )
return NULL ;
}
V_147 = F_70 ( V_147 -> V_149 . V_119 ,
struct V_146 , V_149 ) ;
V_63 -> V_162 = V_147 ;
}
V_67 = V_147 -> V_76 + V_147 -> V_153 / sizeof( * V_67 ) ;
memset ( V_67 , 0 , V_142 * sizeof( * V_67 ) ) ;
* V_167 = V_147 -> V_152 + V_147 -> V_153 ;
return V_67 ;
}
static void F_84 ( struct V_144 * V_63 , T_1 V_168 )
{
struct V_1 * V_4 = V_63 -> V_4 ;
F_11 ( V_4 , F_67 ( V_63 -> V_74 ) ,
F_71 ( V_63 -> V_84 -> V_69 ) ) ;
F_11 ( V_4 , F_42 ( V_63 -> V_74 ) , ~ 0 ) ;
F_11 ( V_4 , F_36 ( V_63 -> V_74 ) , V_81 | V_168 ) ;
V_63 -> V_169 = true ;
F_15 ( V_4 ) ;
}
static void F_85 ( struct V_144 * V_63 ,
struct V_66 * V_67 , int V_142 , int V_168 )
{
T_2 V_167 ;
struct V_146 * V_147 = V_63 -> V_162 ;
struct V_66 * V_170 ;
V_167 = V_147 -> V_152 + ( V_67 - V_147 -> V_76 ) * sizeof( * V_67 ) ;
V_147 -> V_153 += ( V_142 + V_168 ) * sizeof( * V_67 ) ;
F_35 () ;
V_170 = F_68 ( V_63 -> V_164 , V_63 -> V_165 ) ;
V_170 -> V_69 = F_33 ( V_167 | V_142 ) ;
if ( F_8 ( V_63 -> V_4 -> V_115 & V_171 ) &&
V_170 != V_63 -> V_164 &&
( V_63 -> V_164 -> V_136 & F_34 ( V_172 ) ) ==
F_34 ( V_137 ) ) {
V_63 -> V_164 -> V_69 = F_33 ( V_167 | V_142 ) ;
}
V_63 -> V_164 = V_67 ;
V_63 -> V_165 = V_142 ;
}
static void F_86 ( struct V_144 * V_63 )
{
struct V_1 * V_4 = V_63 -> V_4 ;
T_1 V_173 ;
int V_49 ;
F_11 ( V_4 , F_42 ( V_63 -> V_74 ) , V_81 ) ;
V_63 -> V_169 = false ;
for ( V_49 = 0 ; V_49 < 1000 ; V_49 ++ ) {
V_173 = F_13 ( V_4 , F_36 ( V_63 -> V_74 ) ) ;
if ( ( V_173 & V_174 ) == 0 )
return;
if ( V_49 )
F_87 ( 10 ) ;
}
F_20 ( V_4 , L_38 , V_173 ) ;
}
static int F_88 ( struct V_144 * V_63 ,
struct V_90 * V_175 )
{
struct V_1 * V_4 = V_63 -> V_4 ;
T_2 V_167 , V_157 ( V_176 ) ;
struct V_177 * V_177 ;
struct V_66 * V_67 , * V_84 ;
T_4 * V_34 ;
int V_142 , V_35 ;
V_67 = F_83 ( V_63 , 4 , & V_167 ) ;
if ( V_67 == NULL ) {
V_175 -> V_109 = V_178 ;
return - 1 ;
}
V_67 [ 0 ] . V_136 = F_34 ( V_179 ) ;
V_67 [ 0 ] . V_70 = F_34 ( V_175 -> V_110 ) ;
V_35 = ( V_175 -> V_34 [ 0 ] >> 4 ) & 0x0f ;
V_34 = ( T_4 * ) & V_67 [ 1 ] ;
switch ( V_35 ) {
case V_94 :
case V_100 :
case V_105 :
case V_106 :
case V_99 :
case V_95 :
case V_101 :
case V_102 :
case V_103 :
V_34 [ 0 ] = F_33 ( ( V_175 -> V_34 [ 0 ] & 0xffff ) |
( V_175 -> V_31 << 16 ) ) ;
V_34 [ 1 ] = F_33 ( ( V_175 -> V_34 [ 1 ] & 0xffff ) |
( V_175 -> V_34 [ 0 ] & 0xffff0000 ) ) ;
V_34 [ 2 ] = F_33 ( V_175 -> V_34 [ 2 ] ) ;
if ( F_89 ( V_35 ) )
V_34 [ 3 ] = F_33 ( V_175 -> V_34 [ 3 ] ) ;
else
V_34 [ 3 ] = ( V_40 T_4 ) V_175 -> V_34 [ 3 ] ;
V_67 [ 0 ] . V_135 = F_34 ( V_175 -> V_97 ) ;
break;
case V_180 :
V_34 [ 0 ] = F_33 ( ( V_113 << 4 ) |
( V_175 -> V_31 << 16 ) ) ;
V_34 [ 1 ] = F_33 ( V_175 -> V_34 [ 1 ] ) ;
V_34 [ 2 ] = F_33 ( V_175 -> V_34 [ 2 ] ) ;
V_67 [ 0 ] . V_135 = F_34 ( 12 ) ;
if ( F_90 ( & V_175 -> V_34 [ 1 ] ) )
V_67 [ 0 ] . V_136 |= F_34 ( V_181 ) ;
break;
case V_182 :
V_34 [ 0 ] = F_33 ( ( V_175 -> V_34 [ 0 ] & 0xffff ) |
( V_175 -> V_31 << 16 ) ) ;
V_34 [ 1 ] = F_33 ( V_175 -> V_34 [ 0 ] & 0xffff0000 ) ;
V_67 [ 0 ] . V_135 = F_34 ( 8 ) ;
break;
default:
V_175 -> V_109 = V_178 ;
return - 1 ;
}
F_91 ( sizeof( struct V_177 ) > sizeof( struct V_66 ) ) ;
V_177 = (struct V_177 * ) & V_67 [ 3 ] ;
V_177 -> V_175 = V_175 ;
V_175 -> V_177 = V_177 ;
if ( V_175 -> V_98 > 0 ) {
if ( V_175 -> V_98 > sizeof( V_177 -> V_183 ) ) {
V_176 = F_92 ( V_4 -> V_3 . V_78 ,
V_175 -> V_108 ,
V_175 -> V_98 ,
V_184 ) ;
if ( F_63 ( V_4 -> V_3 . V_78 , V_176 ) ) {
V_175 -> V_109 = V_178 ;
return - 1 ;
}
V_175 -> V_176 = V_176 ;
V_175 -> V_185 = true ;
} else {
memcpy ( V_177 -> V_183 , V_175 -> V_108 ,
V_175 -> V_98 ) ;
V_176 = V_167 + 3 * sizeof( * V_67 ) ;
}
V_67 [ 2 ] . V_135 = F_34 ( V_175 -> V_98 ) ;
V_67 [ 2 ] . V_140 = F_33 ( V_176 ) ;
V_84 = & V_67 [ 2 ] ;
V_142 = 3 ;
} else {
V_84 = & V_67 [ 0 ] ;
V_142 = 2 ;
}
V_84 -> V_136 |= F_34 ( V_163 |
V_186 |
V_139 ) ;
if ( V_4 -> V_26 != V_175 -> V_26 ) {
if ( V_175 -> V_185 )
F_93 ( V_4 -> V_3 . V_78 , V_176 ,
V_175 -> V_98 , V_184 ) ;
V_175 -> V_109 = V_187 ;
return - 1 ;
}
F_85 ( V_63 , V_67 , V_142 , 4 - V_142 ) ;
if ( V_63 -> V_169 )
F_11 ( V_4 , F_36 ( V_63 -> V_74 ) , V_75 ) ;
else
F_84 ( V_63 , 0 ) ;
return 0 ;
}
static void F_94 ( struct V_144 * V_63 )
{
F_95 ( & V_63 -> V_126 ) ;
V_63 -> V_188 = true ;
F_69 ( ( unsigned long ) V_63 ) ;
V_63 -> V_188 = false ;
F_96 ( & V_63 -> V_126 ) ;
}
static int F_97 ( struct V_144 * V_144 ,
struct V_66 * V_67 ,
struct V_66 * V_84 )
{
struct V_177 * V_177 ;
struct V_90 * V_175 ;
struct V_1 * V_4 = V_144 -> V_4 ;
int V_5 ;
if ( V_84 -> V_72 == 0 && ! V_144 -> V_188 )
return 0 ;
V_177 = (struct V_177 * ) & V_67 [ 3 ] ;
V_175 = V_177 -> V_175 ;
if ( V_175 == NULL )
return 1 ;
if ( V_175 -> V_185 )
F_93 ( V_4 -> V_3 . V_78 , V_175 -> V_176 ,
V_175 -> V_98 , V_184 ) ;
V_5 = F_48 ( V_84 -> V_72 ) & 0x1f ;
V_175 -> V_110 = F_48 ( V_84 -> V_70 ) ;
F_7 ( V_4 , 'T' , V_175 -> V_31 , V_175 -> V_34 , V_5 ) ;
switch ( V_5 ) {
case V_189 :
V_175 -> V_109 = V_190 ;
break;
case V_191 :
V_175 -> V_109 = V_187 ;
break;
case V_192 :
if ( V_144 -> V_188 )
V_175 -> V_109 = V_187 ;
else {
V_175 -> V_109 = V_193 ;
}
break;
case V_114 + 0x10 :
case V_194 + 0x10 :
case V_195 + 0x10 :
case V_196 + 0x10 :
case V_197 + 0x10 :
case V_198 + 0x10 :
case V_199 + 0x10 :
V_175 -> V_109 = V_5 - 0x10 ;
break;
case V_112 :
if ( V_144 -> V_188 ) {
V_175 -> V_109 = V_187 ;
break;
}
default:
V_175 -> V_109 = V_178 ;
break;
}
V_175 -> V_154 ( V_175 , & V_4 -> V_3 , V_175 -> V_109 ) ;
return 1 ;
}
static void F_98 ( struct V_1 * V_4 ,
struct V_90 * V_175 , T_1 V_200 )
{
struct V_90 V_201 ;
int V_35 , V_93 , V_49 ;
V_35 = F_99 ( V_175 -> V_34 [ 0 ] ) ;
if ( F_89 ( V_35 ) )
V_93 = F_100 ( V_175 -> V_34 [ 3 ] ) ;
else
V_93 = 4 ;
V_49 = V_200 - V_202 ;
if ( V_49 + V_93 > V_203 ) {
F_101 ( & V_201 , V_175 -> V_34 ,
V_204 , NULL , 0 ) ;
} else if ( ! F_102 ( V_35 ) ) {
F_101 ( & V_201 , V_175 -> V_34 ,
V_205 , NULL , 0 ) ;
} else {
F_101 ( & V_201 , V_175 -> V_34 , V_206 ,
( void * ) V_4 -> V_207 + V_49 , V_93 ) ;
}
F_54 ( & V_4 -> V_3 , & V_201 ) ;
}
static void F_103 ( struct V_1 * V_4 ,
struct V_90 * V_175 , T_1 V_200 )
{
struct V_90 V_201 ;
int V_35 , V_93 , V_208 , V_209 , V_210 ;
V_41 * V_108 , V_211 ;
T_1 V_212 , V_213 ;
V_35 = F_99 ( V_175 -> V_34 [ 0 ] ) ;
V_93 = F_100 ( V_175 -> V_34 [ 3 ] ) ;
V_108 = V_175 -> V_108 ;
V_208 = F_104 ( V_175 -> V_34 [ 3 ] ) ;
if ( V_35 == V_102 &&
V_208 == V_214 && V_93 == 8 ) {
V_212 = F_10 ( V_108 [ 0 ] ) ;
V_213 = F_10 ( V_108 [ 1 ] ) ;
} else if ( V_35 == V_106 ) {
V_212 = 0 ;
V_213 = 0 ;
} else {
F_101 ( & V_201 , V_175 -> V_34 ,
V_205 , NULL , 0 ) ;
goto V_215;
}
V_209 = ( V_200 - V_216 ) / 4 ;
F_11 ( V_4 , V_217 , V_213 ) ;
F_11 ( V_4 , V_218 , V_212 ) ;
F_11 ( V_4 , V_219 , V_209 ) ;
for ( V_210 = 0 ; V_210 < 20 ; V_210 ++ )
if ( F_13 ( V_4 , V_219 ) & 0x80000000 ) {
V_211 = F_105 ( F_13 ( V_4 ,
V_217 ) ) ;
F_101 ( & V_201 , V_175 -> V_34 ,
V_206 ,
& V_211 , sizeof( V_211 ) ) ;
goto V_215;
}
F_20 ( V_4 , L_39 ) ;
F_101 ( & V_201 , V_175 -> V_34 , V_220 , NULL , 0 ) ;
V_215:
F_54 ( & V_4 -> V_3 , & V_201 ) ;
}
static void F_106 ( struct V_144 * V_63 , struct V_90 * V_175 )
{
T_6 V_43 , V_200 ;
if ( V_63 == & V_63 -> V_4 -> V_221 ) {
V_175 -> V_109 = V_194 ;
V_175 -> V_154 ( V_175 , & V_63 -> V_4 -> V_3 , V_175 -> V_109 ) ;
}
V_43 =
( ( unsigned long long )
F_107 ( V_175 -> V_34 [ 1 ] ) << 32 ) |
V_175 -> V_34 [ 2 ] ;
V_200 = V_43 - V_222 ;
if ( V_200 >= V_202 && V_200 < V_223 )
F_98 ( V_63 -> V_4 , V_175 , V_200 ) ;
else switch ( V_200 ) {
case V_216 :
case V_224 :
case V_225 :
case V_226 :
F_103 ( V_63 -> V_4 , V_175 , V_200 ) ;
break;
default:
if ( V_63 == & V_63 -> V_4 -> V_221 )
F_53 ( & V_63 -> V_4 -> V_3 , V_175 ) ;
else
F_54 ( & V_63 -> V_4 -> V_3 , V_175 ) ;
break;
}
if ( V_63 == & V_63 -> V_4 -> V_227 ) {
V_175 -> V_109 = V_114 ;
V_175 -> V_154 ( V_175 , & V_63 -> V_4 -> V_3 , V_175 -> V_109 ) ;
}
}
static void F_108 ( struct V_144 * V_63 , struct V_90 * V_175 )
{
unsigned long V_155 ;
int V_57 ;
F_72 ( & V_63 -> V_4 -> V_156 , V_155 ) ;
if ( F_109 ( V_175 -> V_34 [ 0 ] ) == V_63 -> V_4 -> V_29 &&
V_63 -> V_4 -> V_26 == V_175 -> V_26 ) {
F_74 ( & V_63 -> V_4 -> V_156 , V_155 ) ;
F_106 ( V_63 , V_175 ) ;
return;
}
V_57 = F_88 ( V_63 , V_175 ) ;
F_74 ( & V_63 -> V_4 -> V_156 , V_155 ) ;
if ( V_57 < 0 )
V_175 -> V_154 ( V_175 , & V_63 -> V_4 -> V_3 , V_175 -> V_109 ) ;
}
static void F_110 ( struct V_1 * V_4 ,
const char * V_228 , unsigned int V_74 )
{
T_1 V_229 ;
V_229 = F_13 ( V_4 , F_36 ( V_74 ) ) ;
if ( V_229 & V_230 )
F_20 ( V_4 , L_40 ,
V_228 , V_38 [ V_229 & 0x1f ] ) ;
}
static void F_111 ( struct V_1 * V_4 )
{
unsigned int V_49 ;
char V_228 [ 8 ] ;
F_110 ( V_4 , L_41 , V_231 ) ;
F_110 ( V_4 , L_42 , V_232 ) ;
F_110 ( V_4 , L_43 , V_233 ) ;
F_110 ( V_4 , L_44 , V_234 ) ;
for ( V_49 = 0 ; V_49 < 32 ; ++ V_49 ) {
if ( ! ( V_4 -> V_235 & ( 1 << V_49 ) ) )
continue;
sprintf ( V_228 , L_45 , V_49 ) ;
F_110 ( V_4 , V_228 , F_112 ( V_49 ) ) ;
}
for ( V_49 = 0 ; V_49 < 32 ; ++ V_49 ) {
if ( ! ( V_4 -> V_236 & ( 1 << V_49 ) ) )
continue;
sprintf ( V_228 , L_46 , V_49 ) ;
F_110 ( V_4 , V_228 , F_113 ( V_49 ) ) ;
}
}
static T_1 F_114 ( T_1 V_237 )
{
T_1 V_238 ;
V_238 = V_237 & 0xfff ;
V_238 += 3072 * ( ( V_237 >> 12 ) & 0x1fff ) ;
V_238 += ( 3072 * 8000 ) * ( V_237 >> 25 ) ;
return V_238 ;
}
static T_1 F_115 ( struct V_1 * V_4 )
{
T_1 V_239 , V_240 , V_241 ;
T_1 V_242 , V_243 , V_244 ;
T_7 V_245 , V_246 ;
int V_49 ;
V_241 = F_13 ( V_4 , V_247 ) ;
if ( V_4 -> V_115 & V_248 ) {
V_49 = 0 ;
V_240 = V_241 ;
V_241 = F_13 ( V_4 , V_247 ) ;
do {
V_239 = V_240 ;
V_240 = V_241 ;
V_241 = F_13 ( V_4 , V_247 ) ;
V_242 = F_114 ( V_239 ) ;
V_243 = F_114 ( V_240 ) ;
V_244 = F_114 ( V_241 ) ;
V_245 = V_243 - V_242 ;
V_246 = V_244 - V_243 ;
} while ( ( V_245 <= 0 || V_246 <= 0 ||
V_245 / V_246 >= 2 || V_246 / V_245 >= 2 )
&& V_49 ++ < 20 );
}
return V_241 ;
}
static T_1 F_116 ( struct V_1 * V_4 )
{
T_1 V_249 = F_115 ( V_4 ) >> 25 ;
if ( F_8 ( ! V_4 -> V_250 ) ) {
F_11 ( V_4 , V_251 , V_19 ) ;
V_4 -> V_252 = ( F_117 ( F_118 () ) & ~ 0x7f ) |
( V_249 & 0x40 ) ;
V_4 -> V_250 = true ;
}
if ( ( V_4 -> V_252 & 0x40 ) != ( V_249 & 0x40 ) )
V_4 -> V_252 += 0x40 ;
return V_4 -> V_252 | V_249 ;
}
static int F_119 ( struct V_1 * V_4 , int V_253 )
{
int V_173 ;
F_27 ( & V_4 -> V_61 ) ;
V_173 = F_22 ( V_4 , 7 , V_253 ) ;
if ( V_173 >= 0 )
V_173 = F_16 ( V_4 , 8 ) ;
F_28 ( & V_4 -> V_61 ) ;
if ( V_173 < 0 )
return V_173 ;
switch ( V_173 & 0x0f ) {
case 0x06 :
return 2 ;
case 0x0e :
return 3 ;
}
return 1 ;
}
static int F_120 ( struct V_1 * V_4 , T_1 V_254 ,
int V_27 )
{
int V_49 ;
T_1 V_255 ;
for ( V_49 = 0 ; V_49 < V_27 ; V_49 ++ ) {
V_255 = V_4 -> V_30 [ V_49 ] ;
if ( ( V_254 & 0xff000000 ) == ( V_255 & 0xff000000 ) )
return - 1 ;
if ( ( V_254 & 0xff000000 ) < ( V_255 & 0xff000000 ) )
return V_49 ;
}
return V_49 ;
}
static int F_121 ( struct V_1 * V_4 )
{
int V_173 ;
int V_57 = 0 ;
F_27 ( & V_4 -> V_61 ) ;
V_173 = F_22 ( V_4 , 7 , 0xe0 ) ;
if ( V_173 >= 0 ) {
V_173 = F_16 ( V_4 , 8 ) ;
V_173 |= 0x40 ;
V_173 = F_22 ( V_4 , 8 , V_173 ) ;
if ( V_173 >= 0 ) {
V_173 = F_16 ( V_4 , 12 ) ;
if ( V_173 >= 0 ) {
if ( ( V_173 & 0x08 ) == 0x08 ) {
V_57 = 0x2 ;
}
}
}
}
F_28 ( & V_4 -> V_61 ) ;
return V_57 ;
}
static int F_122 ( struct V_1 * V_4 , int V_27 )
{
int V_173 , V_49 , V_256 , V_92 ;
T_1 V_254 = 0x8040c800 ;
V_173 = F_13 ( V_4 , V_257 ) ;
if ( ! ( V_173 & V_258 ) ) {
F_4 ( V_4 ,
L_47 ) ;
return - V_53 ;
}
V_254 |= ( ( V_173 & 0x3f ) << 24 ) ;
V_173 = F_26 ( & V_4 -> V_3 , 4 ) ;
if ( V_173 < 0 )
return V_173 ;
V_254 |= ( ( V_173 & 0x07 ) << 8 ) ;
V_173 = F_26 ( & V_4 -> V_3 , 1 ) ;
if ( V_173 < 0 )
return V_173 ;
V_254 |= ( ( V_173 & 0x3f ) << 16 ) ;
for ( V_49 = 0 ; V_49 < 3 ; V_49 ++ ) {
V_92 = F_119 ( V_4 , V_49 ) ;
if ( V_92 < 0 )
return V_92 ;
V_254 |= ( ( V_92 & 0x3 ) << ( 6 - ( V_49 * 2 ) ) ) ;
}
V_254 |= F_121 ( V_4 ) ;
V_256 = F_120 ( V_4 , V_254 , V_27 ) ;
if ( V_256 >= 0 ) {
memmove ( & ( V_4 -> V_30 [ V_256 + 1 ] ) ,
& ( V_4 -> V_30 [ V_256 ] ) ,
( V_27 - V_256 ) * sizeof( * V_4 -> V_30 ) ) ;
V_4 -> V_30 [ V_256 ] = V_254 ;
V_27 ++ ;
}
return V_27 ;
}
static void F_123 ( struct V_259 * V_260 )
{
struct V_1 * V_4 =
F_1 ( V_260 , struct V_1 , F_123 ) ;
int V_27 , V_26 , V_261 , V_49 , V_262 ;
T_1 V_173 ;
void * V_263 = NULL ;
T_2 V_264 = 0 ;
bool V_265 ;
V_173 = F_13 ( V_4 , V_257 ) ;
if ( ! ( V_173 & V_258 ) ) {
F_4 ( V_4 ,
L_47 ) ;
return;
}
if ( ( V_173 & V_266 ) == 63 ) {
F_4 ( V_4 , L_48 ) ;
return;
}
V_4 -> V_29 = V_173 & ( V_267 |
V_266 ) ;
V_265 = ( V_173 & V_268 ) != 0 ;
if ( ! ( V_4 -> V_269 && V_265 ) )
F_11 ( V_4 , V_270 ,
V_271 ) ;
V_4 -> V_269 = V_265 ;
V_173 = F_13 ( V_4 , V_272 ) ;
if ( V_173 & V_273 ) {
F_4 ( V_4 , L_49 ) ;
return;
}
V_27 = ( V_173 >> 3 ) & 0xff ;
if ( V_27 > 252 ) {
F_4 ( V_4 , L_50 , V_173 ) ;
return;
}
V_26 = ( F_52 ( V_4 -> V_254 [ 0 ] ) >> 16 ) & 0xff ;
F_47 () ;
for ( V_49 = 1 , V_262 = 0 ; V_262 < V_27 ; V_49 += 2 , V_262 ++ ) {
T_1 V_274 = F_52 ( V_4 -> V_254 [ V_49 ] ) ;
T_1 V_275 = F_52 ( V_4 -> V_254 [ V_49 + 1 ] ) ;
if ( V_274 != ~ V_275 ) {
if ( V_274 == 0xffff008f ) {
F_4 ( V_4 , L_51 ) ;
V_27 = V_262 ;
break;
}
F_4 ( V_4 , L_52 ,
V_262 , V_27 , V_274 , V_275 ) ;
return;
}
V_4 -> V_30 [ V_262 ] = V_274 ;
}
if ( V_4 -> V_115 & V_276 ) {
V_27 = F_122 ( V_4 , V_27 ) ;
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
F_47 () ;
V_261 = ( F_13 ( V_4 , V_272 ) >> 16 ) & 0xff ;
if ( V_261 != V_26 ) {
F_4 ( V_4 , L_55 ) ;
return;
}
F_124 ( & V_4 -> V_156 ) ;
V_4 -> V_26 = - 1 ;
F_86 ( & V_4 -> V_221 ) ;
F_86 ( & V_4 -> V_227 ) ;
F_125 ( & V_4 -> V_156 ) ;
F_94 ( & V_4 -> V_221 ) ;
F_94 ( & V_4 -> V_227 ) ;
F_124 ( & V_4 -> V_156 ) ;
V_4 -> V_26 = V_26 ;
F_11 ( V_4 , V_277 , V_9 ) ;
if ( V_4 -> V_115 & V_116 )
V_4 -> V_111 = V_26 ;
if ( V_4 -> V_278 != NULL ) {
if ( V_4 -> V_278 != V_4 -> V_207 ) {
V_263 = V_4 -> V_207 ;
V_264 = V_4 -> V_279 ;
}
V_4 -> V_207 = V_4 -> V_278 ;
V_4 -> V_279 = V_4 -> V_280 ;
V_4 -> V_278 = NULL ;
F_11 ( V_4 , V_281 ,
F_10 ( V_4 -> V_207 [ 2 ] ) ) ;
V_4 -> V_207 [ 0 ] = V_4 -> V_282 ;
F_11 ( V_4 , V_283 ,
F_10 ( V_4 -> V_282 ) ) ;
}
if ( V_284 ) {
F_11 ( V_4 , V_285 , ~ 0 ) ;
F_11 ( V_4 , V_286 , ~ 0 ) ;
}
F_125 ( & V_4 -> V_156 ) ;
if ( V_263 )
F_82 ( V_4 -> V_3 . V_78 , V_203 ,
V_263 , V_264 ) ;
F_6 ( V_4 , V_26 , V_27 ) ;
F_126 ( & V_4 -> V_3 , V_4 -> V_29 , V_26 ,
V_27 , V_4 -> V_30 ,
V_4 -> V_287 ) ;
V_4 -> V_287 = false ;
}
static T_8 F_127 ( int V_288 , void * V_44 )
{
struct V_1 * V_4 = V_44 ;
T_1 V_289 , V_290 ;
int V_49 ;
V_289 = F_13 ( V_4 , V_277 ) ;
if ( ! V_289 || ! ~ V_289 )
return V_291 ;
F_11 ( V_4 , V_277 ,
V_289 & ~ ( V_9 | V_17 ) ) ;
F_2 ( V_4 , V_289 ) ;
if ( V_289 & V_10 )
F_128 ( V_292 , & V_4 -> F_123 ) ;
if ( V_289 & V_11 )
F_129 ( & V_4 -> V_117 . V_126 ) ;
if ( V_289 & V_12 )
F_129 ( & V_4 -> V_293 . V_126 ) ;
if ( V_289 & V_13 )
F_129 ( & V_4 -> V_221 . V_126 ) ;
if ( V_289 & V_14 )
F_129 ( & V_4 -> V_227 . V_126 ) ;
if ( V_289 & V_15 ) {
V_290 = F_13 ( V_4 , V_294 ) ;
F_11 ( V_4 , V_294 , V_290 ) ;
while ( V_290 ) {
V_49 = F_130 ( V_290 ) - 1 ;
F_129 (
& V_4 -> V_295 [ V_49 ] . V_144 . V_126 ) ;
V_290 &= ~ ( 1 << V_49 ) ;
}
}
if ( V_289 & V_16 ) {
V_290 = F_13 ( V_4 , V_296 ) ;
F_11 ( V_4 , V_296 , V_290 ) ;
while ( V_290 ) {
V_49 = F_130 ( V_290 ) - 1 ;
F_129 (
& V_4 -> V_297 [ V_49 ] . V_144 . V_126 ) ;
V_290 &= ~ ( 1 << V_49 ) ;
}
}
if ( F_8 ( V_289 & V_21 ) )
F_20 ( V_4 , L_56 ) ;
if ( F_8 ( V_289 & V_17 ) ) {
F_13 ( V_4 , V_298 ) ;
F_13 ( V_4 , V_299 ) ;
F_11 ( V_4 , V_277 ,
V_17 ) ;
if ( F_131 () )
F_20 ( V_4 , L_57 ) ;
}
if ( F_8 ( V_289 & V_18 ) ) {
if ( F_131 () )
F_4 ( V_4 , L_58 ) ;
F_11 ( V_4 , V_270 ,
V_271 ) ;
}
if ( F_8 ( V_289 & V_20 ) ) {
if ( F_131 () )
F_4 ( V_4 , L_59 ) ;
}
if ( F_8 ( V_289 & V_22 ) )
F_111 ( V_4 ) ;
if ( V_289 & V_19 ) {
F_132 ( & V_4 -> V_156 ) ;
F_116 ( V_4 ) ;
F_133 ( & V_4 -> V_156 ) ;
} else
F_15 ( V_4 ) ;
return V_300 ;
}
static int F_134 ( struct V_1 * V_4 )
{
T_1 V_48 ;
int V_49 ;
F_11 ( V_4 , V_301 , V_302 ) ;
for ( V_49 = 0 ; V_49 < 500 ; V_49 ++ ) {
V_48 = F_13 ( V_4 , V_301 ) ;
if ( ! ~ V_48 )
return - V_51 ;
if ( ! ( V_48 & V_302 ) )
return 0 ;
F_19 ( 1 ) ;
}
return - V_53 ;
}
static void F_135 ( V_41 * V_303 , const V_41 * V_304 , T_9 V_93 )
{
T_9 V_305 = V_93 * 4 ;
memcpy ( V_303 , V_304 , V_305 ) ;
if ( V_305 < V_203 )
memset ( & V_303 [ V_93 ] , 0 , V_203 - V_305 ) ;
}
static int F_136 ( struct V_1 * V_4 )
{
bool V_306 ;
int V_57 , V_307 , V_308 , V_43 ;
if ( ! ( F_13 ( V_4 , V_301 ) &
V_309 ) )
return 0 ;
V_306 = false ;
V_57 = F_16 ( V_4 , 2 ) ;
if ( V_57 < 0 )
return V_57 ;
if ( ( V_57 & V_310 ) == V_310 ) {
V_57 = F_25 ( V_4 , 1 , 8 ) ;
if ( V_57 < 0 )
return V_57 ;
if ( V_57 >= 1 )
V_306 = true ;
}
if ( V_4 -> V_115 & V_311 )
V_306 = false ;
if ( V_306 ) {
V_307 = 0 ;
V_308 = V_312 | V_313 ;
} else {
V_307 = V_312 | V_313 ;
V_308 = 0 ;
}
V_57 = F_24 ( V_4 , 5 , V_307 , V_308 ) ;
if ( V_57 < 0 )
return V_57 ;
if ( V_306 )
V_43 = V_301 ;
else
V_43 = V_314 ;
F_11 ( V_4 , V_43 , V_315 ) ;
F_11 ( V_4 , V_314 ,
V_309 ) ;
return 0 ;
}
static int F_137 ( struct V_1 * V_4 )
{
static const T_10 V_274 [] = { 0x08 , 0x00 , 0x28 , 0x83 , 0x30 , 0x05 , } ;
int V_173 , V_49 ;
V_173 = F_16 ( V_4 , 2 ) ;
if ( V_173 < 0 )
return V_173 ;
if ( ( V_173 & V_310 ) != V_310 )
return 0 ;
for ( V_49 = F_9 ( V_274 ) - 1 ; V_49 >= 0 ; V_49 -- ) {
V_173 = F_25 ( V_4 , 1 , V_49 + 10 ) ;
if ( V_173 < 0 )
return V_173 ;
if ( V_173 != V_274 [ V_49 ] )
return 0 ;
}
return 1 ;
}
static int F_138 ( struct V_2 * V_3 ,
const V_41 * V_207 , T_9 V_93 )
{
struct V_1 * V_4 = V_1 ( V_3 ) ;
T_1 V_316 , V_317 , V_318 ;
int V_49 , V_57 ;
V_57 = F_134 ( V_4 ) ;
if ( V_57 < 0 ) {
F_20 ( V_4 , L_60 ) ;
return V_57 ;
}
F_11 ( V_4 , V_301 ,
V_319 |
V_320 ) ;
F_15 ( V_4 ) ;
for ( V_316 = 0 , V_49 = 0 ; ! V_316 && V_49 < 3 ; V_49 ++ ) {
F_19 ( 50 ) ;
V_316 = F_13 ( V_4 , V_301 ) &
V_319 ;
}
if ( ! V_316 ) {
F_20 ( V_4 , L_61 ) ;
return - V_321 ;
}
if ( V_4 -> V_115 & V_276 ) {
V_57 = F_137 ( V_4 ) ;
if ( V_57 < 0 )
return V_57 ;
if ( V_57 )
F_4 ( V_4 , L_62 ) ;
else
V_4 -> V_115 &= ~ V_276 ;
}
F_11 ( V_4 , V_314 ,
V_322 ) ;
F_11 ( V_4 , V_323 , V_4 -> V_324 ) ;
F_11 ( V_4 , V_270 ,
V_325 |
V_271 ) ;
F_11 ( V_4 , V_326 ,
V_327 |
( V_328 << 4 ) |
( V_329 << 8 ) |
( 200 << 16 ) ) ;
V_4 -> V_250 = false ;
for ( V_49 = 0 ; V_49 < 32 ; V_49 ++ )
if ( V_4 -> V_236 & ( 1 << V_49 ) )
F_11 ( V_4 , F_139 ( V_49 ) ,
V_330 ) ;
V_317 = F_13 ( V_4 , V_46 ) & 0x00ff00ff ;
if ( V_317 >= V_331 ) {
F_11 ( V_4 , V_332 ,
0xfffffffe ) ;
V_3 -> V_333 = true ;
}
F_11 ( V_4 , V_334 , 0x3f ) ;
V_4 -> V_335 = F_13 ( V_4 , V_334 ) & 0x3f ;
F_11 ( V_4 , V_334 , 0 ) ;
V_3 -> V_336 = V_4 -> V_335 != 0 ;
F_11 ( V_4 , V_337 , V_338 >> 16 ) ;
F_11 ( V_4 , V_277 , ~ 0 ) ;
F_11 ( V_4 , V_339 , ~ 0 ) ;
V_57 = F_136 ( V_4 ) ;
if ( V_57 < 0 )
return V_57 ;
V_57 = F_29 ( V_3 , 4 , 0 , V_340 | V_341 ) ;
if ( V_57 < 0 )
return V_57 ;
if ( V_207 ) {
V_4 -> V_278 =
F_76 ( V_4 -> V_3 . V_78 , V_203 ,
& V_4 -> V_280 ,
V_127 ) ;
if ( V_4 -> V_278 == NULL )
return - V_141 ;
F_135 ( V_4 -> V_278 , V_207 , V_93 ) ;
} else {
V_4 -> V_278 = V_4 -> V_207 ;
V_4 -> V_280 = V_4 -> V_279 ;
}
V_4 -> V_282 = V_4 -> V_278 [ 0 ] ;
V_4 -> V_278 [ 0 ] = 0 ;
F_11 ( V_4 , V_283 , 0 ) ;
F_11 ( V_4 , V_281 ,
F_10 ( V_4 -> V_278 [ 2 ] ) ) ;
F_11 ( V_4 , V_342 , V_4 -> V_280 ) ;
F_11 ( V_4 , V_343 , 0x80000000 ) ;
V_318 = V_13 | V_14 |
V_11 | V_12 |
V_16 | V_15 |
V_17 |
V_10 |
V_21 |
V_20 |
V_22 |
V_18 |
V_344 ;
if ( V_6 & V_8 )
V_318 |= V_9 ;
F_11 ( V_4 , V_251 , V_318 ) ;
F_11 ( V_4 , V_301 ,
V_345 |
V_346 ) ;
F_11 ( V_4 , V_270 ,
V_347 |
V_348 ) ;
F_66 ( & V_4 -> V_117 ) ;
F_66 ( & V_4 -> V_293 ) ;
F_15 ( V_4 ) ;
F_140 ( & V_4 -> V_3 , false , true ) ;
return 0 ;
}
static int F_141 ( struct V_2 * V_3 ,
const V_41 * V_207 , T_9 V_93 )
{
struct V_1 * V_4 ;
V_41 * V_278 ;
T_2 V_157 ( V_280 ) ;
V_4 = V_1 ( V_3 ) ;
V_278 =
F_76 ( V_4 -> V_3 . V_78 , V_203 ,
& V_280 , V_127 ) ;
if ( V_278 == NULL )
return - V_141 ;
F_124 ( & V_4 -> V_156 ) ;
if ( V_4 -> V_278 == NULL ) {
V_4 -> V_278 = V_278 ;
V_4 -> V_280 = V_280 ;
V_278 = NULL ;
}
F_135 ( V_4 -> V_278 , V_207 , V_93 ) ;
V_4 -> V_282 = V_207 [ 0 ] ;
V_4 -> V_278 [ 0 ] = 0 ;
F_11 ( V_4 , V_342 , V_4 -> V_280 ) ;
F_125 ( & V_4 -> V_156 ) ;
if ( V_278 != NULL )
F_82 ( V_4 -> V_3 . V_78 , V_203 ,
V_278 , V_280 ) ;
F_140 ( & V_4 -> V_3 , true , true ) ;
return 0 ;
}
static void F_142 ( struct V_2 * V_3 , struct V_90 * V_175 )
{
struct V_1 * V_4 = V_1 ( V_3 ) ;
F_108 ( & V_4 -> V_221 , V_175 ) ;
}
static void F_143 ( struct V_2 * V_3 , struct V_90 * V_175 )
{
struct V_1 * V_4 = V_1 ( V_3 ) ;
F_108 ( & V_4 -> V_227 , V_175 ) ;
}
static int F_144 ( struct V_2 * V_3 , struct V_90 * V_175 )
{
struct V_1 * V_4 = V_1 ( V_3 ) ;
struct V_144 * V_63 = & V_4 -> V_221 ;
struct V_177 * V_177 = V_175 -> V_177 ;
int V_57 = - V_349 ;
F_95 ( & V_63 -> V_126 ) ;
if ( V_175 -> V_109 != 0 )
goto V_215;
if ( V_175 -> V_185 )
F_93 ( V_4 -> V_3 . V_78 , V_175 -> V_176 ,
V_175 -> V_98 , V_184 ) ;
F_7 ( V_4 , 'T' , V_175 -> V_31 , V_175 -> V_34 , 0x20 ) ;
V_177 -> V_175 = NULL ;
V_175 -> V_109 = V_190 ;
V_175 -> V_154 ( V_175 , & V_4 -> V_3 , V_175 -> V_109 ) ;
V_57 = 0 ;
V_215:
F_96 ( & V_63 -> V_126 ) ;
return V_57 ;
}
static int F_145 ( struct V_2 * V_3 ,
int V_29 , int V_26 )
{
struct V_1 * V_4 = V_1 ( V_3 ) ;
unsigned long V_155 ;
int V_350 , V_57 = 0 ;
if ( V_284 )
return 0 ;
F_72 ( & V_4 -> V_156 , V_155 ) ;
if ( V_4 -> V_26 != V_26 ) {
V_57 = - V_351 ;
goto V_215;
}
V_350 = ( V_29 & 0xffc0 ) == V_352 ? V_29 & 0x3f : 63 ;
if ( V_350 < 32 )
F_11 ( V_4 , V_286 , 1 << V_350 ) ;
else
F_11 ( V_4 , V_285 , 1 << ( V_350 - 32 ) ) ;
F_15 ( V_4 ) ;
V_215:
F_74 ( & V_4 -> V_156 , V_155 ) ;
return V_57 ;
}
static T_1 F_146 ( struct V_2 * V_3 , int V_353 )
{
struct V_1 * V_4 = V_1 ( V_3 ) ;
unsigned long V_155 ;
T_1 V_354 ;
switch ( V_353 ) {
case V_355 :
case V_356 :
if ( V_4 -> V_269 &&
( F_13 ( V_4 , V_270 ) &
V_271 ) )
V_354 = V_357 ;
else
V_354 = 0 ;
if ( V_4 -> V_287 )
V_354 |= V_358 ;
return V_354 ;
case V_359 :
return F_13 ( V_4 , V_257 ) << 16 ;
case V_360 :
return F_115 ( V_4 ) ;
case V_361 :
F_72 ( & V_4 -> V_156 , V_155 ) ;
V_354 = F_116 ( V_4 ) ;
F_74 ( & V_4 -> V_156 , V_155 ) ;
return V_354 ;
case V_362 :
V_354 = F_13 ( V_4 , V_326 ) ;
return ( V_354 >> 4 ) & 0x0ffff00f ;
case V_363 :
return ( F_13 ( V_4 , V_334 ) & 0x3f ) |
( V_4 -> V_335 << 8 ) ;
default:
F_147 ( 1 ) ;
return 0 ;
}
}
static void F_148 ( struct V_2 * V_3 , int V_353 , T_1 V_354 )
{
struct V_1 * V_4 = V_1 ( V_3 ) ;
unsigned long V_155 ;
switch ( V_353 ) {
case V_355 :
if ( ( V_354 & V_357 ) && V_4 -> V_269 ) {
F_11 ( V_4 , V_364 ,
V_271 ) ;
F_15 ( V_4 ) ;
}
if ( V_354 & V_358 )
V_4 -> V_287 = false ;
break;
case V_356 :
if ( ( V_354 & V_357 ) && V_4 -> V_269 ) {
F_11 ( V_4 , V_270 ,
V_271 ) ;
F_15 ( V_4 ) ;
}
if ( V_354 & V_358 )
V_4 -> V_287 = true ;
break;
case V_359 :
F_11 ( V_4 , V_257 , V_354 >> 16 ) ;
F_15 ( V_4 ) ;
break;
case V_360 :
F_11 ( V_4 , V_247 , V_354 ) ;
F_11 ( V_4 , V_365 ,
V_20 ) ;
F_15 ( V_4 ) ;
break;
case V_361 :
F_72 ( & V_4 -> V_156 , V_155 ) ;
V_4 -> V_252 = ( F_116 ( V_4 ) & 0x40 ) |
( V_354 & ~ 0x7f ) ;
F_74 ( & V_4 -> V_156 , V_155 ) ;
break;
case V_362 :
V_354 = ( V_354 & 0xf ) | ( ( V_354 & 0xf ) << 4 ) |
( ( V_354 & 0xf ) << 8 ) | ( ( V_354 & 0x0ffff000 ) << 4 ) ;
F_11 ( V_4 , V_326 , V_354 ) ;
F_15 ( V_4 ) ;
break;
case V_363 :
F_11 ( V_4 , V_334 , V_354 & 0x3f ) ;
F_15 ( V_4 ) ;
break;
default:
F_147 ( 1 ) ;
break;
}
}
static void F_149 ( struct V_366 * V_63 )
{
V_63 -> V_367 . V_154 . V_368 ( & V_63 -> V_367 , V_63 -> V_369 ,
V_63 -> V_97 , V_63 -> V_34 ,
V_63 -> V_367 . V_370 ) ;
V_63 -> V_97 = 0 ;
}
static void F_150 ( struct V_366 * V_63 , const T_1 * V_371 )
{
T_1 * V_372 ;
if ( V_63 -> V_97 + V_63 -> V_367 . V_373 > V_71 ) {
if ( V_63 -> V_367 . V_374 )
return;
F_149 ( V_63 ) ;
}
V_372 = V_63 -> V_34 + V_63 -> V_97 ;
V_63 -> V_369 = ( V_375 ) F_71 ( ( V_40 T_4 ) V_371 [ 0 ] ) ;
if ( V_63 -> V_367 . V_373 > 0 )
V_372 [ 0 ] = F_151 ( V_371 [ 1 ] ) ;
if ( V_63 -> V_367 . V_373 > 4 )
V_372 [ 1 ] = F_151 ( V_371 [ 0 ] ) ;
if ( V_63 -> V_367 . V_373 > 8 )
memcpy ( & V_372 [ 2 ] , & V_371 [ 2 ] , V_63 -> V_367 . V_373 - 8 ) ;
V_63 -> V_97 += V_63 -> V_367 . V_373 ;
}
static int F_152 ( struct V_144 * V_144 ,
struct V_66 * V_67 ,
struct V_66 * V_84 )
{
struct V_366 * V_63 =
F_1 ( V_144 , struct V_366 , V_144 ) ;
struct V_66 * V_376 ;
T_1 V_377 ;
for ( V_376 = V_67 ; V_376 <= V_84 ; V_376 ++ )
if ( V_376 -> V_72 )
break;
if ( V_376 > V_84 )
return 0 ;
while ( ! ( V_67 -> V_136 & F_34 ( V_139 ) ) ) {
V_67 ++ ;
V_377 = F_71 ( V_67 -> V_140 ) ;
F_153 ( V_144 -> V_4 -> V_3 . V_78 ,
V_377 & V_378 ,
V_377 & ~ V_378 ,
F_48 ( V_67 -> V_135 ) ,
V_79 ) ;
}
F_150 ( V_63 , ( T_1 * ) ( V_84 + 1 ) ) ;
if ( V_84 -> V_136 & F_34 ( V_186 ) )
F_149 ( V_63 ) ;
return 1 ;
}
static int F_154 ( struct V_144 * V_144 ,
struct V_66 * V_67 ,
struct V_66 * V_84 )
{
struct V_366 * V_63 =
F_1 ( V_144 , struct V_366 , V_144 ) ;
unsigned int V_135 , V_70 , V_379 ;
T_1 V_377 ;
V_135 = F_48 ( V_84 -> V_135 ) ;
V_70 = F_48 ( F_46 ( V_84 -> V_70 ) ) ;
V_379 = V_135 - V_70 ;
V_377 = F_71 ( V_84 -> V_140 ) ;
if ( V_379 > 0 ) {
V_63 -> V_380 = V_377 ;
V_63 -> V_381 = V_379 ;
}
if ( V_70 != 0 )
return 0 ;
F_153 ( V_144 -> V_4 -> V_3 . V_78 ,
V_377 & V_378 ,
V_377 & ~ V_378 ,
V_379 , V_79 ) ;
if ( V_84 -> V_136 & F_34 ( V_186 ) ) {
V_63 -> V_367 . V_154 . V_382 ( & V_63 -> V_367 ,
V_377 + V_379 ,
V_63 -> V_367 . V_370 ) ;
V_63 -> V_381 = 0 ;
}
return 1 ;
}
static void F_155 ( struct V_366 * V_63 )
{
F_153 ( V_63 -> V_144 . V_4 -> V_3 . V_78 ,
V_63 -> V_380 & V_378 ,
V_63 -> V_380 & ~ V_378 ,
V_63 -> V_381 , V_79 ) ;
V_63 -> V_367 . V_154 . V_382 ( & V_63 -> V_367 ,
V_63 -> V_380 + V_63 -> V_381 ,
V_63 -> V_367 . V_370 ) ;
V_63 -> V_381 = 0 ;
}
static inline void F_156 ( struct V_144 * V_144 ,
struct V_66 * V_376 )
{
T_3 V_136 ;
T_1 V_377 ;
if ( V_376 -> V_136 & F_34 ( V_139 ) )
return;
V_376 += 2 ;
if ( ( F_71 ( V_376 -> V_140 ) & V_378 ) ==
( V_144 -> V_151 & V_378 ) ) {
if ( V_376 -> V_136 & F_34 ( V_139 ) )
return;
V_376 ++ ;
}
do {
V_377 = F_71 ( V_376 -> V_140 ) ;
F_153 ( V_144 -> V_4 -> V_3 . V_78 ,
V_377 & V_378 ,
V_377 & ~ V_378 ,
F_48 ( V_376 -> V_135 ) ,
V_184 ) ;
V_136 = V_376 -> V_136 ;
V_376 ++ ;
} while ( ! ( V_136 & F_34 ( V_139 ) ) );
}
static int F_157 ( struct V_144 * V_144 ,
struct V_66 * V_67 ,
struct V_66 * V_84 )
{
struct V_366 * V_63 =
F_1 ( V_144 , struct V_366 , V_144 ) ;
struct V_66 * V_376 ;
V_41 * V_372 ;
for ( V_376 = V_67 ; V_376 <= V_84 ; V_376 ++ )
if ( V_376 -> V_72 )
break;
if ( V_376 > V_84 )
return 0 ;
F_156 ( V_144 , V_67 ) ;
if ( V_63 -> V_97 + 4 > V_71 ) {
if ( V_63 -> V_367 . V_374 )
return 1 ;
F_149 ( V_63 ) ;
}
V_372 = V_63 -> V_34 + V_63 -> V_97 ;
V_63 -> V_369 = F_48 ( V_84 -> V_70 ) ;
* V_372 = F_105 ( ( F_48 ( V_376 -> V_72 ) << 16 ) |
F_48 ( V_376 -> V_70 ) ) ;
V_63 -> V_97 += 4 ;
if ( V_84 -> V_136 & F_34 ( V_186 ) )
F_149 ( V_63 ) ;
return 1 ;
}
static void F_158 ( struct V_1 * V_4 , T_6 V_383 )
{
T_1 V_384 = V_383 >> 32 , V_385 = V_383 ;
F_11 ( V_4 , V_386 , ~ V_384 ) ;
F_11 ( V_4 , V_387 , ~ V_385 ) ;
F_11 ( V_4 , V_388 , V_384 ) ;
F_11 ( V_4 , V_389 , V_385 ) ;
F_159 () ;
V_4 -> V_390 = V_383 ;
}
static struct V_391 * F_160 ( struct V_2 * V_3 ,
int type , int V_392 , T_9 V_373 )
{
struct V_1 * V_4 = V_1 ( V_3 ) ;
struct V_366 * V_157 ( V_63 ) ;
T_5 V_157 ( V_154 ) ;
T_6 * V_157 ( V_383 ) ;
T_1 * V_157 ( V_393 ) , V_157 ( V_74 ) ;
int V_65 , V_57 = - V_53 ;
F_124 ( & V_4 -> V_156 ) ;
switch ( type ) {
case V_394 :
V_393 = & V_4 -> V_395 ;
V_154 = F_157 ;
V_65 = F_130 ( * V_393 ) - 1 ;
if ( V_65 >= 0 ) {
* V_393 &= ~ ( 1 << V_65 ) ;
V_74 = F_112 ( V_65 ) ;
V_63 = & V_4 -> V_297 [ V_65 ] ;
}
break;
case V_396 :
V_383 = & V_4 -> V_397 ;
V_393 = & V_4 -> V_398 ;
V_154 = F_152 ;
V_65 = * V_383 & 1ULL << V_392 ? F_130 ( * V_393 ) - 1 : - 1 ;
if ( V_65 >= 0 ) {
* V_383 &= ~ ( 1ULL << V_392 ) ;
* V_393 &= ~ ( 1 << V_65 ) ;
V_74 = F_113 ( V_65 ) ;
V_63 = & V_4 -> V_295 [ V_65 ] ;
}
break;
case V_399 :
V_393 = & V_4 -> V_398 ;
V_154 = F_154 ;
V_65 = ! V_4 -> V_400 ? F_130 ( * V_393 ) - 1 : - 1 ;
if ( V_65 >= 0 ) {
V_4 -> V_400 = true ;
* V_393 &= ~ ( 1 << V_65 ) ;
V_74 = F_113 ( V_65 ) ;
V_63 = & V_4 -> V_295 [ V_65 ] ;
}
break;
default:
V_65 = - 1 ;
V_57 = - V_401 ;
}
F_125 ( & V_4 -> V_156 ) ;
if ( V_65 < 0 )
return F_161 ( V_57 ) ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_63 -> V_97 = 0 ;
V_63 -> V_34 = ( void * ) F_162 ( V_127 ) ;
if ( V_63 -> V_34 == NULL ) {
V_57 = - V_141 ;
goto V_215;
}
V_57 = F_78 ( & V_63 -> V_144 , V_4 , V_74 , V_154 ) ;
if ( V_57 < 0 )
goto V_402;
if ( type == V_399 ) {
F_158 ( V_4 , 0 ) ;
V_63 -> V_381 = 0 ;
}
return & V_63 -> V_367 ;
V_402:
F_163 ( ( unsigned long ) V_63 -> V_34 ) ;
V_215:
F_124 ( & V_4 -> V_156 ) ;
switch ( type ) {
case V_396 :
* V_383 |= 1ULL << V_392 ;
break;
case V_399 :
V_4 -> V_400 = false ;
break;
}
* V_393 |= 1 << V_65 ;
F_125 ( & V_4 -> V_156 ) ;
return F_161 ( V_57 ) ;
}
static int F_164 ( struct V_391 * V_367 ,
T_7 V_403 , T_1 V_404 , T_1 V_405 )
{
struct V_366 * V_63 = F_1 ( V_367 , struct V_366 , V_367 ) ;
struct V_1 * V_4 = V_63 -> V_144 . V_4 ;
T_1 V_136 = V_406 , V_407 ;
int V_65 ;
if ( V_63 -> V_144 . V_84 -> V_69 == 0 )
return - V_408 ;
switch ( V_63 -> V_367 . type ) {
case V_394 :
V_65 = V_63 - V_4 -> V_297 ;
V_407 = 0 ;
if ( V_403 >= 0 )
V_407 = V_409 |
( V_403 & 0x7fff ) << 16 ;
F_11 ( V_4 , V_296 , 1 << V_65 ) ;
F_11 ( V_4 , V_410 , 1 << V_65 ) ;
F_84 ( & V_63 -> V_144 , V_407 ) ;
break;
case V_399 :
V_136 |= V_411 | V_330 ;
case V_396 :
V_65 = V_63 - V_4 -> V_295 ;
V_407 = ( V_405 << 28 ) | ( V_404 << 8 ) | V_63 -> V_367 . V_392 ;
if ( V_403 >= 0 ) {
V_407 |= ( V_403 & 0x07fff ) << 12 ;
V_136 |= V_412 ;
}
F_11 ( V_4 , V_294 , 1 << V_65 ) ;
F_11 ( V_4 , V_413 , 1 << V_65 ) ;
F_11 ( V_4 , F_165 ( V_63 -> V_144 . V_74 ) , V_407 ) ;
F_84 ( & V_63 -> V_144 , V_136 ) ;
V_63 -> V_404 = V_404 ;
V_63 -> V_405 = V_405 ;
break;
}
return 0 ;
}
static int F_166 ( struct V_391 * V_367 )
{
struct V_1 * V_4 = V_1 ( V_367 -> V_3 ) ;
struct V_366 * V_63 = F_1 ( V_367 , struct V_366 , V_367 ) ;
int V_65 ;
switch ( V_63 -> V_367 . type ) {
case V_394 :
V_65 = V_63 - V_4 -> V_297 ;
F_11 ( V_4 , V_414 , 1 << V_65 ) ;
break;
case V_396 :
case V_399 :
V_65 = V_63 - V_4 -> V_295 ;
F_11 ( V_4 , V_415 , 1 << V_65 ) ;
break;
}
F_15 ( V_4 ) ;
F_86 ( & V_63 -> V_144 ) ;
F_167 ( & V_63 -> V_144 . V_126 ) ;
return 0 ;
}
static void F_168 ( struct V_391 * V_367 )
{
struct V_1 * V_4 = V_1 ( V_367 -> V_3 ) ;
struct V_366 * V_63 = F_1 ( V_367 , struct V_366 , V_367 ) ;
unsigned long V_155 ;
int V_65 ;
F_166 ( V_367 ) ;
F_80 ( & V_63 -> V_144 ) ;
F_163 ( ( unsigned long ) V_63 -> V_34 ) ;
F_72 ( & V_4 -> V_156 , V_155 ) ;
switch ( V_367 -> type ) {
case V_394 :
V_65 = V_63 - V_4 -> V_297 ;
V_4 -> V_395 |= 1 << V_65 ;
break;
case V_396 :
V_65 = V_63 - V_4 -> V_295 ;
V_4 -> V_398 |= 1 << V_65 ;
V_4 -> V_397 |= 1ULL << V_367 -> V_392 ;
break;
case V_399 :
V_65 = V_63 - V_4 -> V_295 ;
V_4 -> V_398 |= 1 << V_65 ;
V_4 -> V_397 |= V_4 -> V_390 ;
V_4 -> V_390 = 0 ;
V_4 -> V_400 = false ;
break;
}
F_74 ( & V_4 -> V_156 , V_155 ) ;
}
static int F_169 ( struct V_391 * V_367 , T_6 * V_383 )
{
struct V_1 * V_4 = V_1 ( V_367 -> V_3 ) ;
unsigned long V_155 ;
int V_57 ;
switch ( V_367 -> type ) {
case V_399 :
F_72 ( & V_4 -> V_156 , V_155 ) ;
if ( ~ V_4 -> V_397 & ~ V_4 -> V_390 & * V_383 ) {
* V_383 = V_4 -> V_397 ;
V_57 = - V_53 ;
} else {
F_158 ( V_4 , * V_383 ) ;
V_57 = 0 ;
}
F_74 ( & V_4 -> V_156 , V_155 ) ;
break;
default:
V_57 = - V_416 ;
}
return V_57 ;
}
static void F_170 ( struct V_1 * V_4 )
{
int V_49 ;
struct V_366 * V_63 ;
for ( V_49 = 0 ; V_49 < V_4 -> V_417 ; V_49 ++ ) {
V_63 = & V_4 -> V_295 [ V_49 ] ;
if ( V_63 -> V_144 . V_169 )
F_164 ( & V_63 -> V_367 , 0 , V_63 -> V_404 , V_63 -> V_405 ) ;
}
for ( V_49 = 0 ; V_49 < V_4 -> V_418 ; V_49 ++ ) {
V_63 = & V_4 -> V_297 [ V_49 ] ;
if ( V_63 -> V_144 . V_169 )
F_164 ( & V_63 -> V_367 , 0 , V_63 -> V_404 , V_63 -> V_405 ) ;
}
}
static int F_171 ( struct V_366 * V_63 ,
struct V_419 * V_175 ,
struct V_420 * V_76 ,
unsigned long V_108 )
{
struct V_66 * V_67 , * V_84 , * V_376 ;
struct V_419 * V_91 ;
T_4 * V_34 ;
T_2 V_167 , V_421 ;
T_1 V_142 , V_422 , V_423 , V_288 ;
T_1 V_424 , V_425 , V_426 ;
int V_59 , V_427 , V_49 , V_93 , V_43 ;
V_91 = V_175 ;
V_424 = V_108 ;
if ( V_91 -> V_428 )
V_142 = 1 ;
else
V_142 = 2 ;
if ( V_91 -> V_97 > 0 )
V_142 ++ ;
V_427 = F_172 ( V_424 + V_91 -> V_98 ) >> V_429 ;
if ( V_91 -> V_98 > 0 )
V_423 = V_427 - ( V_424 >> V_429 ) ;
else
V_423 = 0 ;
V_142 += V_423 ;
V_422 = F_173 ( V_91 -> V_97 , sizeof( * V_67 ) ) ;
V_67 = F_83 ( & V_63 -> V_144 , V_142 + V_422 , & V_167 ) ;
if ( V_67 == NULL )
return - V_141 ;
if ( ! V_91 -> V_428 ) {
V_67 [ 0 ] . V_136 = F_34 ( V_179 ) ;
V_67 [ 0 ] . V_135 = F_34 ( 8 ) ;
V_67 [ 0 ] . V_69 = F_33 ( V_167 | V_142 ) ;
V_34 = ( T_4 * ) & V_67 [ 1 ] ;
V_34 [ 0 ] = F_33 ( F_174 ( V_91 -> V_430 ) |
F_175 ( V_91 -> V_431 ) |
F_176 ( V_182 ) |
F_177 ( V_63 -> V_367 . V_392 ) |
F_178 ( V_63 -> V_367 . V_31 ) ) ;
V_34 [ 1 ] =
F_33 ( F_179 ( V_91 -> V_97 +
V_91 -> V_98 ) ) ;
}
if ( V_91 -> V_97 > 0 ) {
V_67 [ 2 ] . V_135 = F_34 ( V_91 -> V_97 ) ;
V_67 [ 2 ] . V_140 = F_33 ( V_167 + V_142 * sizeof( * V_67 ) ) ;
memcpy ( & V_67 [ V_142 ] , V_91 -> V_34 , V_91 -> V_97 ) ;
}
V_376 = V_67 + V_142 - V_423 ;
V_425 = V_424 + V_91 -> V_98 ;
for ( V_49 = 0 ; V_49 < V_423 ; V_49 ++ ) {
V_59 = V_424 >> V_429 ;
V_43 = V_424 & ~ V_378 ;
V_426 = ( V_59 + 1 ) << V_429 ;
V_93 =
F_180 ( V_426 , V_425 ) - V_424 ;
V_376 [ V_49 ] . V_135 = F_34 ( V_93 ) ;
V_421 = F_31 ( V_76 -> V_64 [ V_59 ] ) ;
V_376 [ V_49 ] . V_140 = F_33 ( V_421 + V_43 ) ;
F_181 ( V_63 -> V_144 . V_4 -> V_3 . V_78 ,
V_421 , V_43 , V_93 ,
V_184 ) ;
V_424 += V_93 ;
}
if ( V_91 -> V_432 )
V_288 = V_186 ;
else
V_288 = V_433 ;
V_84 = V_142 == 2 ? V_67 : V_67 + V_142 - 1 ;
V_84 -> V_136 |= F_34 ( V_163 |
V_138 |
V_139 |
V_288 ) ;
F_85 ( & V_63 -> V_144 , V_67 , V_142 , V_422 ) ;
return 0 ;
}
static int F_182 ( struct V_366 * V_63 ,
struct V_419 * V_175 ,
struct V_420 * V_76 ,
unsigned long V_108 )
{
struct V_78 * V_78 = V_63 -> V_144 . V_4 -> V_3 . V_78 ;
struct V_66 * V_67 , * V_376 ;
T_2 V_167 , V_421 ;
T_1 V_142 , V_422 , V_434 ;
int V_49 , V_262 , V_93 ;
int V_59 , V_43 , V_435 , V_373 , V_436 ;
V_435 = V_175 -> V_97 / V_63 -> V_367 . V_373 ;
V_373 = F_183 ( V_63 -> V_367 . V_373 , ( T_9 ) 8 ) ;
V_422 = F_173 ( V_373 , sizeof( * V_67 ) ) ;
V_59 = V_108 >> V_429 ;
V_43 = V_108 & ~ V_378 ;
V_436 = V_175 -> V_98 / V_435 ;
for ( V_49 = 0 ; V_49 < V_435 ; V_49 ++ ) {
V_142 = F_173 ( V_436 + V_43 , V_71 ) + 1 ;
V_67 = F_83 ( & V_63 -> V_144 ,
V_142 + V_422 , & V_167 ) ;
if ( V_67 == NULL )
return - V_141 ;
V_67 -> V_136 = F_34 ( V_138 |
V_137 ) ;
if ( V_175 -> V_428 && V_49 == 0 )
V_67 -> V_136 |= F_34 ( V_437 ) ;
V_67 -> V_135 = F_34 ( V_373 ) ;
V_67 -> V_70 = V_67 -> V_135 ;
V_67 -> V_72 = 0 ;
V_67 -> V_140 = F_33 ( V_167 + ( V_142 * sizeof( * V_67 ) ) ) ;
V_434 = V_436 ;
V_376 = V_67 ;
for ( V_262 = 1 ; V_262 < V_142 ; V_262 ++ ) {
V_376 ++ ;
V_376 -> V_136 = F_34 ( V_138 |
V_137 ) ;
if ( V_43 + V_434 < V_71 )
V_93 = V_434 ;
else
V_93 = V_71 - V_43 ;
V_376 -> V_135 = F_34 ( V_93 ) ;
V_376 -> V_70 = V_376 -> V_135 ;
V_376 -> V_72 = 0 ;
V_421 = F_31 ( V_76 -> V_64 [ V_59 ] ) ;
V_376 -> V_140 = F_33 ( V_421 + V_43 ) ;
F_181 ( V_78 , V_421 ,
V_43 , V_93 ,
V_79 ) ;
V_43 = ( V_43 + V_93 ) & ~ V_378 ;
V_434 -= V_93 ;
if ( V_43 == 0 )
V_59 ++ ;
}
V_376 -> V_136 = F_34 ( V_138 |
V_438 |
V_139 ) ;
if ( V_175 -> V_432 && V_49 == V_435 - 1 )
V_376 -> V_136 |= F_34 ( V_186 ) ;
F_85 ( & V_63 -> V_144 , V_67 , V_142 , V_422 ) ;
}
return 0 ;
}
static int F_184 ( struct V_366 * V_63 ,
struct V_419 * V_175 ,
struct V_420 * V_76 ,
unsigned long V_108 )
{
struct V_66 * V_67 ;
T_2 V_167 , V_421 ;
int V_59 , V_43 , V_434 , V_142 , V_49 , V_93 ;
V_59 = V_108 >> V_429 ;
V_43 = V_108 & ~ V_378 ;
V_434 = V_175 -> V_98 ;
V_142 = F_173 ( V_43 + V_434 , V_71 ) ;
if ( F_147 ( V_43 & 3 || V_434 & 3 || V_59 + V_142 > V_76 -> V_439 ) )
return - V_440 ;
for ( V_49 = 0 ; V_49 < V_142 ; V_49 ++ ) {
V_67 = F_83 ( & V_63 -> V_144 , 1 , & V_167 ) ;
if ( V_67 == NULL )
return - V_141 ;
V_67 -> V_136 = F_34 ( V_137 |
V_139 ) ;
if ( V_175 -> V_428 && V_49 == 0 )
V_67 -> V_136 |= F_34 ( V_437 ) ;
if ( V_175 -> V_432 && V_49 == V_142 - 1 )
V_67 -> V_136 |= F_34 ( V_186 ) ;
if ( V_43 + V_434 < V_71 )
V_93 = V_434 ;
else
V_93 = V_71 - V_43 ;
V_67 -> V_135 = F_34 ( V_93 ) ;
V_67 -> V_70 = V_67 -> V_135 ;
V_67 -> V_72 = 0 ;
V_421 = F_31 ( V_76 -> V_64 [ V_59 ] ) ;
V_67 -> V_140 = F_33 ( V_421 + V_43 ) ;
F_181 ( V_63 -> V_144 . V_4 -> V_3 . V_78 ,
V_421 , V_43 , V_93 ,
V_79 ) ;
V_434 -= V_93 ;
V_43 = 0 ;
V_59 ++ ;
F_85 ( & V_63 -> V_144 , V_67 , 1 , 0 ) ;
}
return 0 ;
}
static int F_185 ( struct V_391 * V_367 ,
struct V_419 * V_175 ,
struct V_420 * V_76 ,
unsigned long V_108 )
{
struct V_366 * V_63 = F_1 ( V_367 , struct V_366 , V_367 ) ;
unsigned long V_155 ;
int V_57 = - V_401 ;
F_72 ( & V_63 -> V_144 . V_4 -> V_156 , V_155 ) ;
switch ( V_367 -> type ) {
case V_394 :
V_57 = F_171 ( V_63 , V_175 , V_76 , V_108 ) ;
break;
case V_396 :
V_57 = F_182 ( V_63 , V_175 , V_76 , V_108 ) ;
break;
case V_399 :
V_57 = F_184 ( V_63 , V_175 , V_76 , V_108 ) ;
break;
}
F_74 ( & V_63 -> V_144 . V_4 -> V_156 , V_155 ) ;
return V_57 ;
}
static void F_186 ( struct V_391 * V_367 )
{
struct V_144 * V_63 =
& F_1 ( V_367 , struct V_366 , V_367 ) -> V_144 ;
F_11 ( V_63 -> V_4 , F_36 ( V_63 -> V_74 ) , V_75 ) ;
}
static int F_187 ( struct V_391 * V_367 )
{
struct V_366 * V_63 = F_1 ( V_367 , struct V_366 , V_367 ) ;
int V_57 = 0 ;
F_95 ( & V_63 -> V_144 . V_126 ) ;
if ( ! F_188 ( 0 , & V_63 -> V_441 ) ) {
F_69 ( ( unsigned long ) & V_63 -> V_144 ) ;
switch ( V_367 -> type ) {
case V_394 :
case V_396 :
if ( V_63 -> V_97 != 0 )
F_149 ( V_63 ) ;
break;
case V_399 :
if ( V_63 -> V_381 != 0 )
F_155 ( V_63 ) ;
break;
default:
V_57 = - V_401 ;
}
F_189 ( 0 , & V_63 -> V_441 ) ;
F_190 () ;
}
F_96 ( & V_63 -> V_144 . V_126 ) ;
return V_57 ;
}
static void F_191 ( struct V_442 * V_443 )
{
if ( F_192 ( V_444 ) ) {
struct V_445 * V_446 = F_193 ( V_443 ) ;
if ( V_446 ) {
F_194 ( V_447 , V_446 , 0 , 1 ) ;
F_194 ( V_448 , V_446 , 0 , 1 ) ;
}
}
}
static void F_195 ( struct V_442 * V_443 )
{
if ( F_192 ( V_444 ) ) {
struct V_445 * V_446 = F_193 ( V_443 ) ;
if ( V_446 ) {
F_194 ( V_448 , V_446 , 0 , 0 ) ;
F_194 ( V_447 , V_446 , 0 , 0 ) ;
}
}
}
static inline void F_191 ( struct V_442 * V_443 ) {}
static inline void F_195 ( struct V_442 * V_443 ) {}
static int F_196 ( struct V_442 * V_443 ,
const struct V_449 * V_450 )
{
struct V_1 * V_4 ;
T_1 V_451 , V_452 , V_453 , V_317 ;
T_6 V_454 ;
int V_49 , V_455 ;
T_9 V_305 ;
if ( V_443 -> V_456 == V_457 ) {
F_197 ( & V_443 -> V_443 , L_63 ) ;
return - V_401 ;
}
V_4 = F_198 ( sizeof( * V_4 ) , V_127 ) ;
if ( V_4 == NULL ) {
V_455 = - V_141 ;
goto V_458;
}
F_199 ( & V_4 -> V_3 , & V_459 , & V_443 -> V_443 ) ;
F_191 ( V_443 ) ;
V_455 = F_200 ( V_443 ) ;
if ( V_455 ) {
F_197 ( & V_443 -> V_443 , L_64 ) ;
goto V_460;
}
F_201 ( V_443 ) ;
F_202 ( V_443 , V_461 , 0 ) ;
F_203 ( V_443 , V_4 ) ;
F_204 ( & V_4 -> V_156 ) ;
F_205 ( & V_4 -> V_61 ) ;
F_206 ( & V_4 -> F_123 , F_123 ) ;
if ( ! ( F_207 ( V_443 , 0 ) & V_462 ) ||
F_208 ( V_443 , 0 ) < V_463 ) {
F_20 ( V_4 , L_65 ) ;
V_455 = - V_464 ;
goto V_465;
}
V_455 = F_209 ( V_443 , 0 , V_466 ) ;
if ( V_455 ) {
F_20 ( V_4 , L_66 ) ;
goto V_465;
}
V_4 -> V_45 = F_210 ( V_443 , 0 , V_463 ) ;
if ( V_4 -> V_45 == NULL ) {
F_20 ( V_4 , L_67 ) ;
V_455 = - V_464 ;
goto V_467;
}
for ( V_49 = 0 ; V_49 < F_9 ( V_468 ) ; V_49 ++ )
if ( ( V_468 [ V_49 ] . V_456 == V_443 -> V_456 ) &&
( V_468 [ V_49 ] . V_78 == ( unsigned short ) V_469 ||
V_468 [ V_49 ] . V_78 == V_443 -> V_78 ) &&
( V_468 [ V_49 ] . V_470 == ( unsigned short ) V_469 ||
V_468 [ V_49 ] . V_470 >= V_443 -> V_470 ) ) {
V_4 -> V_115 = V_468 [ V_49 ] . V_155 ;
break;
}
if ( V_471 )
V_4 -> V_115 = V_471 ;
F_91 ( V_77 * sizeof( struct V_66 ) > V_71 / 4 ) ;
F_91 ( V_472 > V_71 / 2 ) ;
V_4 -> V_132 = F_76 ( V_4 -> V_3 . V_78 ,
V_71 ,
& V_4 -> V_134 ,
V_127 ) ;
if ( ! V_4 -> V_132 ) {
V_455 = - V_141 ;
goto V_473;
}
V_455 = F_59 ( & V_4 -> V_117 , V_4 , 0 ,
V_474 ) ;
if ( V_455 < 0 )
goto V_475;
V_455 = F_59 ( & V_4 -> V_293 , V_4 , V_71 / 4 ,
V_476 ) ;
if ( V_455 < 0 )
goto V_477;
V_455 = F_78 ( & V_4 -> V_221 , V_4 ,
V_478 , F_97 ) ;
if ( V_455 < 0 )
goto V_479;
V_455 = F_78 ( & V_4 -> V_227 , V_4 ,
V_480 , F_97 ) ;
if ( V_455 < 0 )
goto V_481;
F_11 ( V_4 , V_413 , ~ 0 ) ;
V_4 -> V_397 = ~ 0ULL ;
V_4 -> V_236 = F_13 ( V_4 , V_413 ) ;
F_11 ( V_4 , V_415 , ~ 0 ) ;
V_4 -> V_398 = V_4 -> V_236 ;
V_4 -> V_417 = F_211 ( V_4 -> V_398 ) ;
V_305 = sizeof( struct V_366 ) * V_4 -> V_417 ;
V_4 -> V_295 = F_198 ( V_305 , V_127 ) ;
F_11 ( V_4 , V_410 , ~ 0 ) ;
V_4 -> V_235 = F_13 ( V_4 , V_410 ) ;
if ( ! V_4 -> V_235 ) {
F_4 ( V_4 , L_68 ) ;
V_4 -> V_235 = 0xf ;
}
F_11 ( V_4 , V_414 , ~ 0 ) ;
V_4 -> V_395 = V_4 -> V_235 ;
V_4 -> V_418 = F_211 ( V_4 -> V_395 ) ;
V_305 = sizeof( struct V_366 ) * V_4 -> V_418 ;
V_4 -> V_297 = F_198 ( V_305 , V_127 ) ;
if ( V_4 -> V_297 == NULL || V_4 -> V_295 == NULL ) {
V_455 = - V_141 ;
goto V_482;
}
V_4 -> V_254 = V_4 -> V_132 + V_71 / 2 ;
V_4 -> V_324 = V_4 -> V_134 + V_71 / 2 ;
V_451 = F_13 ( V_4 , V_281 ) ;
V_452 = ( V_451 >> 12 ) & 0xf ;
V_453 = V_451 & 0x7 ;
V_454 = ( ( T_6 ) F_13 ( V_4 , V_483 ) << 32 ) |
F_13 ( V_4 , V_484 ) ;
if ( ! ( V_4 -> V_115 & V_485 ) )
F_212 ( V_443 ) ;
if ( F_213 ( V_443 -> V_288 , F_127 ,
F_214 ( V_443 ) ? 0 : V_486 ,
V_466 , V_4 ) ) {
F_20 ( V_4 , L_69 , V_443 -> V_288 ) ;
V_455 = - V_321 ;
goto V_487;
}
V_455 = F_215 ( & V_4 -> V_3 , V_452 , V_453 , V_454 ) ;
if ( V_455 )
goto V_488;
V_317 = F_13 ( V_4 , V_46 ) & 0x00ff00ff ;
F_4 ( V_4 ,
L_70
L_71 ,
V_317 >> 16 , V_317 & 0xff , V_4 -> V_3 . V_65 ,
V_4 -> V_417 , V_4 -> V_418 , V_4 -> V_115 ,
F_13 ( V_4 , V_337 ) ?
L_72 : L_3 ) ;
return 0 ;
V_488:
F_216 ( V_443 -> V_288 , V_4 ) ;
V_487:
F_217 ( V_443 ) ;
V_482:
F_218 ( V_4 -> V_295 ) ;
F_218 ( V_4 -> V_297 ) ;
F_80 ( & V_4 -> V_227 ) ;
V_481:
F_80 ( & V_4 -> V_221 ) ;
V_479:
F_37 ( & V_4 -> V_293 ) ;
V_477:
F_37 ( & V_4 -> V_117 ) ;
V_475:
F_82 ( V_4 -> V_3 . V_78 , V_71 ,
V_4 -> V_132 , V_4 -> V_134 ) ;
V_473:
F_219 ( V_443 , V_4 -> V_45 ) ;
V_467:
F_220 ( V_443 , 0 ) ;
V_465:
F_221 ( V_443 ) ;
V_460:
F_218 ( V_4 ) ;
F_195 ( V_443 ) ;
V_458:
return V_455 ;
}
static void F_222 ( struct V_442 * V_443 )
{
struct V_1 * V_4 = F_223 ( V_443 ) ;
if ( F_13 ( V_4 , V_301 ) & V_319 ) {
F_11 ( V_4 , V_339 , ~ 0 ) ;
F_15 ( V_4 ) ;
}
F_224 ( & V_4 -> F_123 ) ;
F_225 ( & V_4 -> V_3 ) ;
F_134 ( V_4 ) ;
F_216 ( V_443 -> V_288 , V_4 ) ;
if ( V_4 -> V_278 && V_4 -> V_278 != V_4 -> V_207 )
F_82 ( V_4 -> V_3 . V_78 , V_203 ,
V_4 -> V_278 , V_4 -> V_280 ) ;
if ( V_4 -> V_207 )
F_82 ( V_4 -> V_3 . V_78 , V_203 ,
V_4 -> V_207 , V_4 -> V_279 ) ;
F_37 ( & V_4 -> V_117 ) ;
F_37 ( & V_4 -> V_293 ) ;
F_82 ( V_4 -> V_3 . V_78 , V_71 ,
V_4 -> V_132 , V_4 -> V_134 ) ;
F_80 ( & V_4 -> V_221 ) ;
F_80 ( & V_4 -> V_227 ) ;
F_218 ( V_4 -> V_297 ) ;
F_218 ( V_4 -> V_295 ) ;
F_217 ( V_443 ) ;
F_219 ( V_443 , V_4 -> V_45 ) ;
F_220 ( V_443 , 0 ) ;
F_221 ( V_443 ) ;
F_218 ( V_4 ) ;
F_195 ( V_443 ) ;
F_226 ( & V_443 -> V_443 , L_73 ) ;
}
static int F_227 ( struct V_442 * V_443 , T_11 V_489 )
{
struct V_1 * V_4 = F_223 ( V_443 ) ;
int V_455 ;
F_134 ( V_4 ) ;
V_455 = F_228 ( V_443 ) ;
if ( V_455 ) {
F_20 ( V_4 , L_74 ) ;
return V_455 ;
}
V_455 = F_229 ( V_443 , F_230 ( V_443 , V_489 ) ) ;
if ( V_455 )
F_20 ( V_4 , L_75 , V_455 ) ;
F_195 ( V_443 ) ;
return 0 ;
}
static int F_231 ( struct V_442 * V_443 )
{
struct V_1 * V_4 = F_223 ( V_443 ) ;
int V_455 ;
F_191 ( V_443 ) ;
F_229 ( V_443 , V_490 ) ;
F_232 ( V_443 ) ;
V_455 = F_200 ( V_443 ) ;
if ( V_455 ) {
F_20 ( V_4 , L_76 ) ;
return V_455 ;
}
if ( ! F_13 ( V_4 , V_484 ) &&
! F_13 ( V_4 , V_483 ) ) {
F_11 ( V_4 , V_484 , ( T_1 ) V_4 -> V_3 . V_454 ) ;
F_11 ( V_4 , V_483 , ( T_1 ) ( V_4 -> V_3 . V_454 >> 32 ) ) ;
}
V_455 = F_138 ( & V_4 -> V_3 , NULL , 0 ) ;
if ( V_455 )
return V_455 ;
F_170 ( V_4 ) ;
return 0 ;
}
static int T_12 F_233 ( void )
{
V_292 = F_234 ( V_491 , V_492 , 0 ) ;
if ( ! V_292 )
return - V_141 ;
return F_235 ( & V_493 ) ;
}
static void T_13 F_236 ( void )
{
F_237 ( & V_493 ) ;
F_238 ( V_292 ) ;
}
