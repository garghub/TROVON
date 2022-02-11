static inline struct V_1 * V_1 ( struct V_2 * V_3 )
{
return F_1 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_2 ( T_1 V_4 )
{
if ( F_3 ( ! ( V_5 &
( V_6 | V_7 ) ) ) )
return;
if ( ! ( V_5 & V_6 ) &&
! ( V_4 & V_8 ) )
return;
F_4 ( L_1 , V_4 ,
V_4 & V_9 ? L_2 : L_3 ,
V_4 & V_10 ? L_4 : L_3 ,
V_4 & V_11 ? L_5 : L_3 ,
V_4 & V_12 ? L_6 : L_3 ,
V_4 & V_13 ? L_7 : L_3 ,
V_4 & V_14 ? L_8 : L_3 ,
V_4 & V_15 ? L_9 : L_3 ,
V_4 & V_16 ? L_10 : L_3 ,
V_4 & V_17 ? L_11 : L_3 ,
V_4 & V_18 ? L_12 : L_3 ,
V_4 & V_19 ? L_13 : L_3 ,
V_4 & V_20 ? L_14 : L_3 ,
V_4 & V_21 ? L_15 : L_3 ,
V_4 & V_8 ? L_16 : L_3 ,
V_4 & ~ ( V_9 | V_10 |
V_11 | V_12 |
V_13 | V_14 |
V_15 | V_16 |
V_17 | V_18 |
V_19 |
V_20 | V_8 )
? L_17 : L_3 ) ;
}
static char F_5 ( T_1 * V_22 , int V_23 )
{
return V_24 [ * V_22 >> V_23 & 3 ] ;
}
static void F_6 ( int V_25 , int V_26 , int V_27 , T_1 * V_22 )
{
if ( F_3 ( ! ( V_5 & V_28 ) ) )
return;
F_4 ( L_18 ,
V_27 , V_26 , V_25 ) ;
for (; V_27 -- ; ++ V_22 )
if ( ( * V_22 & 1 << 23 ) == 0 )
F_4 ( L_19
L_20 ,
* V_22 , * V_22 >> 24 & 63 , F_5 ( V_22 , 6 ) , F_5 ( V_22 , 4 ) , F_5 ( V_22 , 2 ) ,
V_29 [ * V_22 >> 14 & 3 ] , * V_22 >> 16 & 63 ,
V_30 [ * V_22 >> 8 & 7 ] , * V_22 >> 22 & 1 ? L_21 : L_3 ,
* V_22 >> 11 & 1 ? L_22 : L_3 , * V_22 & 2 ? L_23 : L_3 ) ;
else
F_4 ( L_24 ,
* V_22 , * V_22 >> 24 & 63 ,
F_5 ( V_22 , 16 ) , F_5 ( V_22 , 14 ) , F_5 ( V_22 , 12 ) , F_5 ( V_22 , 10 ) ,
F_5 ( V_22 , 8 ) , F_5 ( V_22 , 6 ) , F_5 ( V_22 , 4 ) , F_5 ( V_22 , 2 ) ) ;
}
static void F_7 ( char V_31 , int V_29 , T_1 * V_32 , int V_4 )
{
int V_33 = V_32 [ 0 ] >> 4 & 0xf ;
char V_34 [ 12 ] ;
if ( F_3 ( ! ( V_5 & V_35 ) ) )
return;
if ( F_8 ( V_4 >= F_9 ( V_36 ) ) )
V_4 = 0x1f ;
if ( V_4 == V_37 ) {
F_4 ( L_25 ,
V_31 , ( V_32 [ 2 ] >> 16 ) & 0xff ) ;
return;
}
switch ( V_33 ) {
case 0x0 : case 0x6 : case 0x8 :
snprintf ( V_34 , sizeof( V_34 ) , L_26 ,
F_10 ( ( V_38 V_39 ) V_32 [ 3 ] ) ) ;
break;
case 0x1 : case 0x5 : case 0x7 : case 0x9 : case 0xb :
snprintf ( V_34 , sizeof( V_34 ) , L_27 ,
V_32 [ 3 ] >> 16 , V_32 [ 3 ] & 0xffff ) ;
break;
default:
V_34 [ 0 ] = '\0' ;
}
switch ( V_33 ) {
case 0xa :
F_4 ( L_28 , V_31 , V_36 [ V_4 ] , V_40 [ V_33 ] ) ;
break;
case 0xe :
F_4 ( L_29 ,
V_31 , V_36 [ V_4 ] , V_32 [ 1 ] , V_32 [ 2 ] ) ;
break;
case 0x0 : case 0x1 : case 0x4 : case 0x5 : case 0x9 :
F_4 ( L_30
L_31
L_32 ,
V_31 , V_29 , V_32 [ 0 ] >> 10 & 0x3f ,
V_32 [ 1 ] >> 16 , V_32 [ 0 ] >> 16 , V_36 [ V_4 ] ,
V_40 [ V_33 ] , V_32 [ 1 ] & 0xffff , V_32 [ 2 ] , V_34 ) ;
break;
default:
F_4 ( L_30
L_31
L_33 ,
V_31 , V_29 , V_32 [ 0 ] >> 10 & 0x3f ,
V_32 [ 1 ] >> 16 , V_32 [ 0 ] >> 16 , V_36 [ V_4 ] ,
V_40 [ V_33 ] , V_34 ) ;
}
}
static inline void F_2 ( T_1 V_4 ) {}
static inline void F_6 ( int V_25 , int V_26 , int V_27 , T_1 * V_22 ) {}
static inline void F_7 ( char V_31 , int V_29 , T_1 * V_32 , int V_4 ) {}
static inline void F_11 ( const struct V_1 * V_41 , int V_42 , T_1 V_43 )
{
F_12 ( V_43 , V_41 -> V_44 + V_42 ) ;
}
static inline T_1 F_13 ( const struct V_1 * V_41 , int V_42 )
{
return F_14 ( V_41 -> V_44 + V_42 ) ;
}
static inline void F_15 ( const struct V_1 * V_41 )
{
F_13 ( V_41 , V_45 ) ;
}
static int F_16 ( struct V_1 * V_41 , int V_46 )
{
T_1 V_47 ;
int V_48 ;
F_11 ( V_41 , V_49 , F_17 ( V_46 ) ) ;
for ( V_48 = 0 ; V_48 < 3 + 100 ; V_48 ++ ) {
V_47 = F_13 ( V_41 , V_49 ) ;
if ( V_47 & V_50 )
return F_18 ( V_47 ) ;
if ( V_48 >= 3 )
F_19 ( 1 ) ;
}
F_20 ( L_34 ) ;
return - V_51 ;
}
static int F_21 ( const struct V_1 * V_41 , int V_46 , T_1 V_47 )
{
int V_48 ;
F_11 ( V_41 , V_49 ,
F_22 ( V_46 , V_47 ) ) ;
for ( V_48 = 0 ; V_48 < 3 + 100 ; V_48 ++ ) {
V_47 = F_13 ( V_41 , V_49 ) ;
if ( ! ( V_47 & V_52 ) )
return 0 ;
if ( V_48 >= 3 )
F_19 ( 1 ) ;
}
F_20 ( L_35 ) ;
return - V_51 ;
}
static int F_23 ( struct V_1 * V_41 , int V_46 ,
int V_53 , int V_54 )
{
int V_55 = F_16 ( V_41 , V_46 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( V_46 == 5 )
V_53 |= V_56 ;
return F_21 ( V_41 , V_46 , ( V_55 & ~ V_53 ) | V_54 ) ;
}
static int F_24 ( struct V_1 * V_41 , int V_57 , int V_46 )
{
int V_55 ;
V_55 = F_23 ( V_41 , 7 , V_58 , V_57 << 5 ) ;
if ( V_55 < 0 )
return V_55 ;
return F_16 ( V_41 , V_46 ) ;
}
static int F_25 ( struct V_2 * V_3 , int V_46 )
{
struct V_1 * V_41 = V_1 ( V_3 ) ;
int V_55 ;
F_26 ( & V_41 -> V_59 ) ;
V_55 = F_16 ( V_41 , V_46 ) ;
F_27 ( & V_41 -> V_59 ) ;
return V_55 ;
}
static int F_28 ( struct V_2 * V_3 , int V_46 ,
int V_53 , int V_54 )
{
struct V_1 * V_41 = V_1 ( V_3 ) ;
int V_55 ;
F_26 ( & V_41 -> V_59 ) ;
V_55 = F_23 ( V_41 , V_46 , V_53 , V_54 ) ;
F_27 ( & V_41 -> V_59 ) ;
return V_55 ;
}
static inline T_2 F_29 ( struct V_60 * V_61 , unsigned int V_48 )
{
return F_30 ( V_61 -> V_62 [ V_48 ] ) ;
}
static void F_31 ( struct V_60 * V_61 , unsigned int V_63 )
{
struct V_64 * V_65 ;
V_65 = & V_61 -> V_66 [ V_63 ] ;
V_65 -> V_67 &= F_32 ( ~ 0xf ) ;
V_65 -> V_68 = F_33 ( V_69 ) ;
V_65 -> V_70 = 0 ;
F_34 () ;
V_65 = & V_61 -> V_66 [ V_61 -> V_71 ] ;
V_65 -> V_67 |= F_32 ( 1 ) ;
V_61 -> V_71 = V_63 ;
F_11 ( V_61 -> V_41 , F_35 ( V_61 -> V_72 ) , V_73 ) ;
F_15 ( V_61 -> V_41 ) ;
}
static void F_36 ( struct V_60 * V_61 )
{
unsigned int V_48 ;
if ( V_61 -> V_74 )
F_37 ( V_61 -> V_74 , V_75 + V_76 ) ;
for ( V_48 = 0 ; V_48 < V_75 ; V_48 ++ )
if ( V_61 -> V_62 [ V_48 ] ) {
F_38 ( V_61 -> V_41 -> V_3 . V_77 ,
F_29 ( V_61 , V_48 ) ,
V_69 , V_78 ) ;
F_39 ( V_61 -> V_62 [ V_48 ] ) ;
}
}
static void F_40 ( struct V_60 * V_61 , const char * V_79 )
{
if ( F_13 ( V_61 -> V_41 , F_41 ( V_61 -> V_72 ) ) & V_80 ) {
F_11 ( V_61 -> V_41 , F_41 ( V_61 -> V_72 ) , V_80 ) ;
F_15 ( V_61 -> V_41 ) ;
F_20 ( L_36 , V_79 ) ;
}
}
static inline unsigned int F_42 ( unsigned int V_63 )
{
return ( V_63 + 1 ) % V_75 ;
}
static inline unsigned int F_43 ( unsigned int V_63 )
{
return ( V_63 - 1 + V_75 ) % V_75 ;
}
static inline unsigned int F_44 ( struct V_60 * V_61 )
{
return F_42 ( V_61 -> V_71 ) ;
}
static unsigned int F_45 ( struct V_60 * V_61 ,
unsigned int * V_81 )
{
unsigned int V_48 , V_82 , V_83 = V_61 -> V_71 ;
T_3 V_68 , V_84 ;
V_48 = F_44 ( V_61 ) ;
V_68 = F_46 ( V_61 -> V_66 [ V_48 ] . V_68 ) ;
while ( V_48 != V_83 && V_68 == 0 ) {
V_82 = F_42 ( V_48 ) ;
F_47 () ;
V_84 = F_46 (
V_61 -> V_66 [ V_82 ] . V_68 ) ;
if ( V_84 == F_33 ( V_69 ) ) {
if ( V_85 > V_69 && V_48 != V_83 ) {
V_82 = F_42 ( V_82 ) ;
F_47 () ;
V_84 = F_46 (
V_61 -> V_66 [ V_82 ] . V_68 ) ;
if ( V_84 != F_33 ( V_69 ) )
goto V_86;
}
break;
}
V_86:
V_48 = V_82 ;
V_68 = V_84 ;
}
F_47 () ;
* V_81 = V_69 - F_48 ( V_68 ) ;
if ( * V_81 > V_69 ) {
* V_81 = 0 ;
F_40 ( V_61 , L_37 ) ;
}
return V_48 ;
}
static void F_49 ( struct V_60 * V_61 ,
unsigned int V_87 ,
unsigned int V_88 )
{
unsigned int V_48 ;
V_48 = F_44 ( V_61 ) ;
while ( V_48 != V_87 ) {
F_50 ( V_61 -> V_41 -> V_3 . V_77 ,
F_29 ( V_61 , V_48 ) ,
V_69 , V_78 ) ;
V_48 = F_42 ( V_48 ) ;
}
if ( V_88 > 0 )
F_50 ( V_61 -> V_41 -> V_3 . V_77 ,
F_29 ( V_61 , V_48 ) ,
V_88 , V_78 ) ;
}
static T_4 * F_51 ( struct V_60 * V_61 , T_4 * V_74 )
{
struct V_1 * V_41 = V_61 -> V_41 ;
struct V_89 V_90 ;
T_1 V_91 , V_92 , V_33 ;
int V_4 ;
V_90 . V_32 [ 0 ] = F_52 ( V_74 [ 0 ] ) ;
V_90 . V_32 [ 1 ] = F_52 ( V_74 [ 1 ] ) ;
V_90 . V_32 [ 2 ] = F_52 ( V_74 [ 2 ] ) ;
V_33 = ( V_90 . V_32 [ 0 ] >> 4 ) & 0x0f ;
switch ( V_33 ) {
case V_93 :
case V_94 :
V_90 . V_32 [ 3 ] = ( V_38 V_95 ) V_74 [ 3 ] ;
V_90 . V_96 = 16 ;
V_90 . V_97 = 0 ;
break;
case V_98 :
V_90 . V_32 [ 3 ] = F_52 ( V_74 [ 3 ] ) ;
V_90 . V_96 = 16 ;
V_90 . V_97 = 0 ;
break;
case V_99 :
case V_100 :
case V_101 :
case V_102 :
V_90 . V_32 [ 3 ] = F_52 ( V_74 [ 3 ] ) ;
V_90 . V_96 = 16 ;
V_90 . V_97 = V_90 . V_32 [ 3 ] >> 16 ;
if ( V_90 . V_97 > V_103 ) {
F_40 ( V_61 , L_38 ) ;
return NULL ;
}
break;
case V_104 :
case V_105 :
case V_106 :
V_90 . V_96 = 12 ;
V_90 . V_97 = 0 ;
break;
default:
F_40 ( V_61 , L_39 ) ;
return NULL ;
}
V_90 . V_107 = ( void * ) V_74 + V_90 . V_96 ;
V_92 = ( V_90 . V_96 + V_90 . V_97 + 3 ) / 4 ;
V_91 = F_52 ( V_74 [ V_92 ] ) ;
V_4 = ( V_91 >> 16 ) & 0x1f ;
V_90 . V_108 = V_4 - 16 ;
V_90 . V_29 = ( V_91 >> 21 ) & 0x7 ;
V_90 . V_109 = V_91 & 0xffff ;
V_90 . V_26 = V_41 -> V_110 ;
F_7 ( 'R' , V_90 . V_29 , V_90 . V_32 , V_4 ) ;
if ( V_4 == V_111 &&
( V_90 . V_32 [ 0 ] & 0xff ) == ( V_112 << 4 ) )
V_90 . V_108 = V_113 ;
if ( V_4 == V_37 ) {
if ( ! ( V_41 -> V_114 & V_115 ) )
V_41 -> V_110 = ( V_90 . V_32 [ 2 ] >> 16 ) & 0xff ;
} else if ( V_61 == & V_41 -> V_116 ) {
F_53 ( & V_41 -> V_3 , & V_90 ) ;
} else {
F_54 ( & V_41 -> V_3 , & V_90 ) ;
}
return V_74 + V_92 + 1 ;
}
static void * F_55 ( struct V_60 * V_61 , void * V_90 , void * V_117 )
{
void * V_118 ;
while ( V_90 < V_117 ) {
V_118 = F_51 ( V_61 , V_90 ) ;
if ( ! V_118 )
return V_90 ;
V_90 = V_118 ;
}
return V_90 ;
}
static void F_56 ( struct V_60 * V_61 , unsigned int V_119 )
{
unsigned int V_48 ;
V_48 = F_44 ( V_61 ) ;
while ( V_48 != V_119 ) {
F_57 ( V_61 -> V_41 -> V_3 . V_77 ,
F_29 ( V_61 , V_48 ) ,
V_69 , V_78 ) ;
F_31 ( V_61 , V_48 ) ;
V_48 = F_42 ( V_48 ) ;
}
}
static void F_58 ( unsigned long V_43 )
{
struct V_60 * V_61 = (struct V_60 * ) V_43 ;
unsigned int V_87 , V_88 ;
void * V_90 , * V_117 ;
V_90 = V_61 -> V_120 ;
if ( ! V_90 )
return;
V_87 = F_45 ( V_61 ,
& V_88 ) ;
F_49 ( V_61 , V_87 , V_88 ) ;
V_117 = V_61 -> V_74 + V_87 * V_69 + V_88 ;
if ( V_87 < F_44 ( V_61 ) ) {
void * V_121 = V_61 -> V_74 + V_75 * V_69 ;
V_90 = F_55 ( V_61 , V_90 , V_121 ) ;
if ( V_90 < V_121 )
goto error;
V_90 -= V_75 * V_69 ;
}
V_90 = F_55 ( V_61 , V_90 , V_117 ) ;
if ( V_90 != V_117 ) {
if ( V_90 > V_117 )
F_40 ( V_61 , L_40 ) ;
goto error;
}
V_61 -> V_120 = V_90 ;
F_56 ( V_61 , V_87 ) ;
return;
error:
V_61 -> V_120 = NULL ;
}
static int F_59 ( struct V_60 * V_61 , struct V_1 * V_41 ,
unsigned int V_122 , T_1 V_72 )
{
unsigned int V_48 ;
T_2 V_123 ;
struct V_57 * V_62 [ V_75 + V_76 ] ;
struct V_64 * V_65 ;
V_61 -> V_72 = V_72 ;
V_61 -> V_41 = V_41 ;
F_60 ( & V_61 -> V_124 , F_58 , ( unsigned long ) V_61 ) ;
for ( V_48 = 0 ; V_48 < V_75 ; V_48 ++ ) {
V_61 -> V_62 [ V_48 ] = F_61 ( V_125 | V_126 ) ;
if ( ! V_61 -> V_62 [ V_48 ] )
goto V_127;
V_123 = F_62 ( V_41 -> V_3 . V_77 , V_61 -> V_62 [ V_48 ] ,
0 , V_69 , V_78 ) ;
if ( F_63 ( V_41 -> V_3 . V_77 , V_123 ) ) {
F_39 ( V_61 -> V_62 [ V_48 ] ) ;
V_61 -> V_62 [ V_48 ] = NULL ;
goto V_127;
}
F_64 ( V_61 -> V_62 [ V_48 ] , V_123 ) ;
}
for ( V_48 = 0 ; V_48 < V_75 ; V_48 ++ )
V_62 [ V_48 ] = V_61 -> V_62 [ V_48 ] ;
for ( V_48 = 0 ; V_48 < V_76 ; V_48 ++ )
V_62 [ V_75 + V_48 ] = V_61 -> V_62 [ V_48 ] ;
V_61 -> V_74 = F_65 ( V_62 , V_75 + V_76 ,
- 1 , V_128 ) ;
if ( ! V_61 -> V_74 )
goto V_127;
V_61 -> V_66 = V_41 -> V_129 + V_122 ;
V_61 -> V_130 = V_41 -> V_131 + V_122 ;
for ( V_48 = 0 ; V_48 < V_75 ; V_48 ++ ) {
V_65 = & V_61 -> V_66 [ V_48 ] ;
V_65 -> V_132 = F_33 ( V_69 ) ;
V_65 -> V_133 = F_33 ( V_134 |
V_135 |
V_136 ) ;
V_65 -> V_137 = F_32 ( F_29 ( V_61 , V_48 ) ) ;
V_65 -> V_67 = F_32 ( V_61 -> V_130 +
F_42 ( V_48 ) * sizeof( struct V_64 ) ) ;
}
return 0 ;
V_127:
F_36 ( V_61 ) ;
return - V_138 ;
}
static void F_66 ( struct V_60 * V_61 )
{
unsigned int V_48 ;
for ( V_48 = 0 ; V_48 < V_75 ; V_48 ++ )
F_31 ( V_61 , V_48 ) ;
V_61 -> V_120 = V_61 -> V_74 ;
F_11 ( V_61 -> V_41 , F_67 ( V_61 -> V_72 ) , V_61 -> V_130 | 1 ) ;
F_11 ( V_61 -> V_41 , F_35 ( V_61 -> V_72 ) , V_80 ) ;
F_15 ( V_61 -> V_41 ) ;
}
static struct V_64 * F_68 ( struct V_64 * V_65 , int V_139 )
{
T_3 V_140 ;
V_140 = V_65 -> V_133 & F_33 ( V_136 ) ;
if ( V_139 == 2 && V_140 == F_33 ( V_136 ) )
return V_65 ;
else
return V_65 + V_139 - 1 ;
}
static void F_69 ( unsigned long V_43 )
{
struct V_141 * V_61 = (struct V_141 * ) V_43 ;
struct V_64 * V_65 , * V_83 ;
T_1 V_142 ;
int V_139 ;
struct V_143 * V_144 ;
V_144 = F_70 ( V_61 -> V_145 . V_118 ,
struct V_143 , V_146 ) ;
V_83 = V_61 -> V_83 ;
while ( V_83 -> V_67 != 0 ) {
struct V_143 * V_147 = V_144 ;
V_142 = F_71 ( V_83 -> V_67 ) ;
V_139 = V_142 & 0xf ;
V_142 &= ~ 0xf ;
if ( V_142 < V_144 -> V_148 ||
V_142 >= V_144 -> V_148 + V_144 -> V_149 )
V_144 = F_70 ( V_144 -> V_146 . V_118 ,
struct V_143 , V_146 ) ;
V_65 = V_144 -> V_74 + ( V_142 - V_144 -> V_148 ) / sizeof( * V_65 ) ;
V_83 = F_68 ( V_65 , V_139 ) ;
if ( ! V_61 -> V_150 ( V_61 , V_65 , V_83 ) )
break;
if ( V_147 != V_144 ) {
unsigned long V_151 ;
V_147 -> V_149 = 0 ;
F_72 ( & V_61 -> V_41 -> V_152 , V_151 ) ;
F_73 ( & V_147 -> V_146 , & V_61 -> V_145 ) ;
F_74 ( & V_61 -> V_41 -> V_152 , V_151 ) ;
}
V_61 -> V_83 = V_83 ;
}
}
static int F_75 ( struct V_141 * V_61 )
{
struct V_143 * V_144 ;
T_2 V_153 ( V_154 ) ;
int V_42 ;
if ( V_61 -> V_155 >= 16 * 1024 * 1024 )
return - V_138 ;
V_144 = F_76 ( V_61 -> V_41 -> V_3 . V_77 , V_69 ,
& V_154 , V_156 ) ;
if ( ! V_144 )
return - V_138 ;
V_42 = ( void * ) & V_144 -> V_74 - ( void * ) V_144 ;
V_144 -> V_157 = V_69 - V_42 ;
V_144 -> V_148 = V_154 + V_42 ;
V_144 -> V_149 = 0 ;
F_77 ( & V_144 -> V_146 , & V_61 -> V_145 ) ;
V_61 -> V_155 += V_69 ;
return 0 ;
}
static int F_78 ( struct V_141 * V_61 , struct V_1 * V_41 ,
T_1 V_72 , T_5 V_150 )
{
V_61 -> V_41 = V_41 ;
V_61 -> V_72 = V_72 ;
V_61 -> V_155 = 0 ;
F_79 ( & V_61 -> V_145 ) ;
if ( F_75 ( V_61 ) < 0 )
return - V_138 ;
V_61 -> V_158 = F_70 ( V_61 -> V_145 . V_118 ,
struct V_143 , V_146 ) ;
F_60 ( & V_61 -> V_124 , F_69 , ( unsigned long ) V_61 ) ;
V_61 -> V_150 = V_150 ;
memset ( V_61 -> V_158 -> V_74 , 0 , sizeof( * V_61 -> V_158 -> V_74 ) ) ;
V_61 -> V_158 -> V_74 -> V_133 = F_33 ( V_159 ) ;
V_61 -> V_158 -> V_74 -> V_70 = F_33 ( 0x8011 ) ;
V_61 -> V_158 -> V_149 += sizeof( * V_61 -> V_158 -> V_74 ) ;
V_61 -> V_83 = V_61 -> V_158 -> V_74 ;
V_61 -> V_160 = V_61 -> V_158 -> V_74 ;
return 0 ;
}
static void F_80 ( struct V_141 * V_61 )
{
struct V_2 * V_3 = & V_61 -> V_41 -> V_3 ;
struct V_143 * V_144 , * V_161 ;
F_81 (desc, tmp, &ctx->buffer_list, list)
F_82 ( V_3 -> V_77 , V_69 , V_144 ,
V_144 -> V_148 -
( ( void * ) & V_144 -> V_74 - ( void * ) V_144 ) ) ;
}
static struct V_64 * F_83 ( struct V_141 * V_61 ,
int V_139 , T_2 * V_162 )
{
struct V_64 * V_65 = NULL ;
struct V_143 * V_144 = V_61 -> V_158 ;
if ( V_139 * sizeof( * V_65 ) > V_144 -> V_157 )
return NULL ;
if ( V_139 * sizeof( * V_65 ) > V_144 -> V_157 - V_144 -> V_149 ) {
if ( V_144 -> V_146 . V_118 == & V_61 -> V_145 ) {
if ( F_75 ( V_61 ) < 0 )
return NULL ;
}
V_144 = F_70 ( V_144 -> V_146 . V_118 ,
struct V_143 , V_146 ) ;
V_61 -> V_158 = V_144 ;
}
V_65 = V_144 -> V_74 + V_144 -> V_149 / sizeof( * V_65 ) ;
memset ( V_65 , 0 , V_139 * sizeof( * V_65 ) ) ;
* V_162 = V_144 -> V_148 + V_144 -> V_149 ;
return V_65 ;
}
static void F_84 ( struct V_141 * V_61 , T_1 V_163 )
{
struct V_1 * V_41 = V_61 -> V_41 ;
F_11 ( V_41 , F_67 ( V_61 -> V_72 ) ,
F_71 ( V_61 -> V_83 -> V_67 ) ) ;
F_11 ( V_41 , F_41 ( V_61 -> V_72 ) , ~ 0 ) ;
F_11 ( V_41 , F_35 ( V_61 -> V_72 ) , V_80 | V_163 ) ;
V_61 -> V_164 = true ;
F_15 ( V_41 ) ;
}
static void F_85 ( struct V_141 * V_61 ,
struct V_64 * V_65 , int V_139 , int V_163 )
{
T_2 V_162 ;
struct V_143 * V_144 = V_61 -> V_158 ;
V_162 = V_144 -> V_148 + ( V_65 - V_144 -> V_74 ) * sizeof( * V_65 ) ;
V_144 -> V_149 += ( V_139 + V_163 ) * sizeof( * V_65 ) ;
F_34 () ;
V_61 -> V_160 -> V_67 = F_32 ( V_162 | V_139 ) ;
V_61 -> V_160 = F_68 ( V_65 , V_139 ) ;
}
static void F_86 ( struct V_141 * V_61 )
{
T_1 V_165 ;
int V_48 ;
F_11 ( V_61 -> V_41 , F_41 ( V_61 -> V_72 ) , V_80 ) ;
V_61 -> V_164 = false ;
F_15 ( V_61 -> V_41 ) ;
for ( V_48 = 0 ; V_48 < 10 ; V_48 ++ ) {
V_165 = F_13 ( V_61 -> V_41 , F_35 ( V_61 -> V_72 ) ) ;
if ( ( V_165 & V_166 ) == 0 )
return;
F_87 ( 1 ) ;
}
F_20 ( L_41 , V_165 ) ;
}
static int F_88 ( struct V_141 * V_61 ,
struct V_89 * V_167 )
{
struct V_1 * V_41 = V_61 -> V_41 ;
T_2 V_162 , V_153 ( V_168 ) ;
struct V_169 * V_169 ;
struct V_64 * V_65 , * V_83 ;
T_4 * V_32 ;
int V_139 , V_33 ;
V_65 = F_83 ( V_61 , 4 , & V_162 ) ;
if ( V_65 == NULL ) {
V_167 -> V_108 = V_170 ;
return - 1 ;
}
V_65 [ 0 ] . V_133 = F_33 ( V_171 ) ;
V_65 [ 0 ] . V_68 = F_33 ( V_167 -> V_109 ) ;
V_33 = ( V_167 -> V_32 [ 0 ] >> 4 ) & 0x0f ;
V_32 = ( T_4 * ) & V_65 [ 1 ] ;
switch ( V_33 ) {
case V_93 :
case V_99 :
case V_104 :
case V_105 :
case V_98 :
case V_94 :
case V_100 :
case V_101 :
case V_102 :
V_32 [ 0 ] = F_32 ( ( V_167 -> V_32 [ 0 ] & 0xffff ) |
( V_167 -> V_29 << 16 ) ) ;
V_32 [ 1 ] = F_32 ( ( V_167 -> V_32 [ 1 ] & 0xffff ) |
( V_167 -> V_32 [ 0 ] & 0xffff0000 ) ) ;
V_32 [ 2 ] = F_32 ( V_167 -> V_32 [ 2 ] ) ;
if ( F_89 ( V_33 ) )
V_32 [ 3 ] = F_32 ( V_167 -> V_32 [ 3 ] ) ;
else
V_32 [ 3 ] = ( V_38 T_4 ) V_167 -> V_32 [ 3 ] ;
V_65 [ 0 ] . V_132 = F_33 ( V_167 -> V_96 ) ;
break;
case V_172 :
V_32 [ 0 ] = F_32 ( ( V_112 << 4 ) |
( V_167 -> V_29 << 16 ) ) ;
V_32 [ 1 ] = F_32 ( V_167 -> V_32 [ 1 ] ) ;
V_32 [ 2 ] = F_32 ( V_167 -> V_32 [ 2 ] ) ;
V_65 [ 0 ] . V_132 = F_33 ( 12 ) ;
if ( F_90 ( & V_167 -> V_32 [ 1 ] ) )
V_65 [ 0 ] . V_133 |= F_33 ( V_173 ) ;
break;
case V_174 :
V_32 [ 0 ] = F_32 ( ( V_167 -> V_32 [ 0 ] & 0xffff ) |
( V_167 -> V_29 << 16 ) ) ;
V_32 [ 1 ] = F_32 ( V_167 -> V_32 [ 0 ] & 0xffff0000 ) ;
V_65 [ 0 ] . V_132 = F_33 ( 8 ) ;
break;
default:
V_167 -> V_108 = V_170 ;
return - 1 ;
}
F_91 ( sizeof( struct V_169 ) > sizeof( struct V_64 ) ) ;
V_169 = (struct V_169 * ) & V_65 [ 3 ] ;
V_169 -> V_167 = V_167 ;
V_167 -> V_169 = V_169 ;
if ( V_167 -> V_97 > 0 ) {
if ( V_167 -> V_97 > sizeof( V_169 -> V_175 ) ) {
V_168 = F_92 ( V_41 -> V_3 . V_77 ,
V_167 -> V_107 ,
V_167 -> V_97 ,
V_176 ) ;
if ( F_63 ( V_41 -> V_3 . V_77 , V_168 ) ) {
V_167 -> V_108 = V_170 ;
return - 1 ;
}
V_167 -> V_168 = V_168 ;
V_167 -> V_177 = true ;
} else {
memcpy ( V_169 -> V_175 , V_167 -> V_107 ,
V_167 -> V_97 ) ;
V_168 = V_162 + 3 * sizeof( * V_65 ) ;
}
V_65 [ 2 ] . V_132 = F_33 ( V_167 -> V_97 ) ;
V_65 [ 2 ] . V_137 = F_32 ( V_168 ) ;
V_83 = & V_65 [ 2 ] ;
V_139 = 3 ;
} else {
V_83 = & V_65 [ 0 ] ;
V_139 = 2 ;
}
V_83 -> V_133 |= F_33 ( V_159 |
V_178 |
V_136 ) ;
if ( V_41 -> V_26 != V_167 -> V_26 ) {
if ( V_167 -> V_177 )
F_93 ( V_41 -> V_3 . V_77 , V_168 ,
V_167 -> V_97 , V_176 ) ;
V_167 -> V_108 = V_179 ;
return - 1 ;
}
F_85 ( V_61 , V_65 , V_139 , 4 - V_139 ) ;
if ( V_61 -> V_164 ) {
F_11 ( V_41 , F_35 ( V_61 -> V_72 ) , V_73 ) ;
F_15 ( V_41 ) ;
} else {
F_84 ( V_61 , 0 ) ;
}
return 0 ;
}
static void F_94 ( struct V_141 * V_61 )
{
F_95 ( & V_61 -> V_124 ) ;
V_61 -> V_180 = true ;
F_69 ( ( unsigned long ) V_61 ) ;
V_61 -> V_180 = false ;
F_96 ( & V_61 -> V_124 ) ;
}
static int F_97 ( struct V_141 * V_141 ,
struct V_64 * V_65 ,
struct V_64 * V_83 )
{
struct V_169 * V_169 ;
struct V_89 * V_167 ;
struct V_1 * V_41 = V_141 -> V_41 ;
int V_4 ;
if ( V_83 -> V_70 == 0 && ! V_141 -> V_180 )
return 0 ;
V_169 = (struct V_169 * ) & V_65 [ 3 ] ;
V_167 = V_169 -> V_167 ;
if ( V_167 == NULL )
return 1 ;
if ( V_167 -> V_177 )
F_93 ( V_41 -> V_3 . V_77 , V_167 -> V_168 ,
V_167 -> V_97 , V_176 ) ;
V_4 = F_48 ( V_83 -> V_70 ) & 0x1f ;
V_167 -> V_109 = F_48 ( V_83 -> V_68 ) ;
F_7 ( 'T' , V_167 -> V_29 , V_167 -> V_32 , V_4 ) ;
switch ( V_4 ) {
case V_181 :
V_167 -> V_108 = V_182 ;
break;
case V_183 :
V_167 -> V_108 = V_179 ;
break;
case V_184 :
if ( V_141 -> V_180 )
V_167 -> V_108 = V_179 ;
else {
V_167 -> V_108 = V_185 ;
}
break;
case V_113 + 0x10 :
case V_186 + 0x10 :
case V_187 + 0x10 :
case V_188 + 0x10 :
case V_189 + 0x10 :
case V_190 + 0x10 :
case V_191 + 0x10 :
V_167 -> V_108 = V_4 - 0x10 ;
break;
case V_111 :
if ( V_141 -> V_180 ) {
V_167 -> V_108 = V_179 ;
break;
}
default:
V_167 -> V_108 = V_170 ;
break;
}
V_167 -> V_150 ( V_167 , & V_41 -> V_3 , V_167 -> V_108 ) ;
return 1 ;
}
static void F_98 ( struct V_1 * V_41 ,
struct V_89 * V_167 , T_1 V_192 )
{
struct V_89 V_193 ;
int V_33 , V_92 , V_48 ;
V_33 = F_99 ( V_167 -> V_32 [ 0 ] ) ;
if ( F_89 ( V_33 ) )
V_92 = F_100 ( V_167 -> V_32 [ 3 ] ) ;
else
V_92 = 4 ;
V_48 = V_192 - V_194 ;
if ( V_48 + V_92 > V_195 ) {
F_101 ( & V_193 , V_167 -> V_32 ,
V_196 , NULL , 0 ) ;
} else if ( ! F_102 ( V_33 ) ) {
F_101 ( & V_193 , V_167 -> V_32 ,
V_197 , NULL , 0 ) ;
} else {
F_101 ( & V_193 , V_167 -> V_32 , V_198 ,
( void * ) V_41 -> V_199 + V_48 , V_92 ) ;
}
F_54 ( & V_41 -> V_3 , & V_193 ) ;
}
static void F_103 ( struct V_1 * V_41 ,
struct V_89 * V_167 , T_1 V_192 )
{
struct V_89 V_193 ;
int V_33 , V_92 , V_200 , V_201 , V_202 ;
V_39 * V_107 , V_203 ;
T_1 V_204 , V_205 ;
V_33 = F_99 ( V_167 -> V_32 [ 0 ] ) ;
V_92 = F_100 ( V_167 -> V_32 [ 3 ] ) ;
V_107 = V_167 -> V_107 ;
V_200 = F_104 ( V_167 -> V_32 [ 3 ] ) ;
if ( V_33 == V_101 &&
V_200 == V_206 && V_92 == 8 ) {
V_204 = F_10 ( V_107 [ 0 ] ) ;
V_205 = F_10 ( V_107 [ 1 ] ) ;
} else if ( V_33 == V_105 ) {
V_204 = 0 ;
V_205 = 0 ;
} else {
F_101 ( & V_193 , V_167 -> V_32 ,
V_197 , NULL , 0 ) ;
goto V_207;
}
V_201 = ( V_192 - V_208 ) / 4 ;
F_11 ( V_41 , V_209 , V_205 ) ;
F_11 ( V_41 , V_210 , V_204 ) ;
F_11 ( V_41 , V_211 , V_201 ) ;
for ( V_202 = 0 ; V_202 < 20 ; V_202 ++ )
if ( F_13 ( V_41 , V_211 ) & 0x80000000 ) {
V_203 = F_105 ( F_13 ( V_41 ,
V_209 ) ) ;
F_101 ( & V_193 , V_167 -> V_32 ,
V_198 ,
& V_203 , sizeof( V_203 ) ) ;
goto V_207;
}
F_20 ( L_42 ) ;
F_101 ( & V_193 , V_167 -> V_32 , V_212 , NULL , 0 ) ;
V_207:
F_54 ( & V_41 -> V_3 , & V_193 ) ;
}
static void F_106 ( struct V_141 * V_61 , struct V_89 * V_167 )
{
T_6 V_42 , V_192 ;
if ( V_61 == & V_61 -> V_41 -> V_213 ) {
V_167 -> V_108 = V_186 ;
V_167 -> V_150 ( V_167 , & V_61 -> V_41 -> V_3 , V_167 -> V_108 ) ;
}
V_42 =
( ( unsigned long long )
F_107 ( V_167 -> V_32 [ 1 ] ) << 32 ) |
V_167 -> V_32 [ 2 ] ;
V_192 = V_42 - V_214 ;
if ( V_192 >= V_194 && V_192 < V_215 )
F_98 ( V_61 -> V_41 , V_167 , V_192 ) ;
else switch ( V_192 ) {
case V_208 :
case V_216 :
case V_217 :
case V_218 :
F_103 ( V_61 -> V_41 , V_167 , V_192 ) ;
break;
default:
if ( V_61 == & V_61 -> V_41 -> V_213 )
F_53 ( & V_61 -> V_41 -> V_3 , V_167 ) ;
else
F_54 ( & V_61 -> V_41 -> V_3 , V_167 ) ;
break;
}
if ( V_61 == & V_61 -> V_41 -> V_219 ) {
V_167 -> V_108 = V_113 ;
V_167 -> V_150 ( V_167 , & V_61 -> V_41 -> V_3 , V_167 -> V_108 ) ;
}
}
static void F_108 ( struct V_141 * V_61 , struct V_89 * V_167 )
{
unsigned long V_151 ;
int V_55 ;
F_72 ( & V_61 -> V_41 -> V_152 , V_151 ) ;
if ( F_109 ( V_167 -> V_32 [ 0 ] ) == V_61 -> V_41 -> V_25 &&
V_61 -> V_41 -> V_26 == V_167 -> V_26 ) {
F_74 ( & V_61 -> V_41 -> V_152 , V_151 ) ;
F_106 ( V_61 , V_167 ) ;
return;
}
V_55 = F_88 ( V_61 , V_167 ) ;
F_74 ( & V_61 -> V_41 -> V_152 , V_151 ) ;
if ( V_55 < 0 )
V_167 -> V_150 ( V_167 , & V_61 -> V_41 -> V_3 , V_167 -> V_108 ) ;
}
static void F_110 ( struct V_1 * V_41 ,
const char * V_220 , unsigned int V_72 )
{
T_1 V_221 ;
V_221 = F_13 ( V_41 , F_35 ( V_72 ) ) ;
if ( V_221 & V_222 ) {
#ifdef F_111
F_20 ( L_43 ,
V_220 , V_36 [ V_221 & 0x1f ] ) ;
#else
F_20 ( L_44 ,
V_220 , V_221 & 0x1f ) ;
#endif
}
}
static void F_112 ( struct V_1 * V_41 )
{
unsigned int V_48 ;
char V_220 [ 8 ] ;
F_110 ( V_41 , L_45 , V_223 ) ;
F_110 ( V_41 , L_46 , V_224 ) ;
F_110 ( V_41 , L_47 , V_225 ) ;
F_110 ( V_41 , L_48 , V_226 ) ;
for ( V_48 = 0 ; V_48 < 32 ; ++ V_48 ) {
if ( ! ( V_41 -> V_227 & ( 1 << V_48 ) ) )
continue;
sprintf ( V_220 , L_49 , V_48 ) ;
F_110 ( V_41 , V_220 , F_113 ( V_48 ) ) ;
}
for ( V_48 = 0 ; V_48 < 32 ; ++ V_48 ) {
if ( ! ( V_41 -> V_228 & ( 1 << V_48 ) ) )
continue;
sprintf ( V_220 , L_50 , V_48 ) ;
F_110 ( V_41 , V_220 , F_114 ( V_48 ) ) ;
}
}
static T_1 F_115 ( T_1 V_229 )
{
T_1 V_230 ;
V_230 = V_229 & 0xfff ;
V_230 += 3072 * ( ( V_229 >> 12 ) & 0x1fff ) ;
V_230 += ( 3072 * 8000 ) * ( V_229 >> 25 ) ;
return V_230 ;
}
static T_1 F_116 ( struct V_1 * V_41 )
{
T_1 V_231 , V_232 , V_233 ;
T_1 V_234 , V_235 , V_236 ;
T_7 V_237 , V_238 ;
int V_48 ;
V_233 = F_13 ( V_41 , V_239 ) ;
if ( V_41 -> V_114 & V_240 ) {
V_48 = 0 ;
V_232 = V_233 ;
V_233 = F_13 ( V_41 , V_239 ) ;
do {
V_231 = V_232 ;
V_232 = V_233 ;
V_233 = F_13 ( V_41 , V_239 ) ;
V_234 = F_115 ( V_231 ) ;
V_235 = F_115 ( V_232 ) ;
V_236 = F_115 ( V_233 ) ;
V_237 = V_235 - V_234 ;
V_238 = V_236 - V_235 ;
} while ( ( V_237 <= 0 || V_238 <= 0 ||
V_237 / V_238 >= 2 || V_238 / V_237 >= 2 )
&& V_48 ++ < 20 );
}
return V_233 ;
}
static T_1 F_117 ( struct V_1 * V_41 )
{
T_1 V_241 = F_116 ( V_41 ) >> 25 ;
if ( ( V_41 -> V_242 & 0x40 ) != ( V_241 & 0x40 ) )
V_41 -> V_242 += 0x40 ;
return V_41 -> V_242 | V_241 ;
}
static void F_118 ( unsigned long V_43 )
{
struct V_1 * V_41 = (struct V_1 * ) V_43 ;
int V_27 , V_48 , V_243 , V_165 ;
int V_26 , V_244 ;
unsigned long V_151 ;
void * V_245 = NULL ;
T_2 V_246 = 0 ;
bool V_247 ;
V_165 = F_13 ( V_41 , V_248 ) ;
if ( ! ( V_165 & V_249 ) ) {
F_4 ( L_51 ) ;
return;
}
if ( ( V_165 & V_250 ) == 63 ) {
F_4 ( L_52 ) ;
return;
}
V_41 -> V_25 = V_165 & ( V_251 |
V_250 ) ;
V_247 = ( V_165 & V_252 ) != 0 ;
if ( ! ( V_41 -> V_253 && V_247 ) )
F_11 ( V_41 , V_254 ,
V_255 ) ;
V_41 -> V_253 = V_247 ;
V_165 = F_13 ( V_41 , V_256 ) ;
if ( V_165 & V_257 ) {
F_4 ( L_53 ) ;
return;
}
V_27 = ( V_165 >> 3 ) & 0xff ;
if ( V_27 == 0 || V_27 > 252 ) {
F_4 ( L_53 ) ;
return;
}
V_26 = ( F_52 ( V_41 -> V_258 [ 0 ] ) >> 16 ) & 0xff ;
F_47 () ;
for ( V_48 = 1 , V_243 = 0 ; V_243 < V_27 ; V_48 += 2 , V_243 ++ ) {
if ( V_41 -> V_258 [ V_48 ] != ~ V_41 -> V_258 [ V_48 + 1 ] ) {
F_4 ( L_53 ) ;
return;
}
V_41 -> V_259 [ V_243 ] =
F_52 ( V_41 -> V_258 [ V_48 ] ) ;
}
F_47 () ;
V_244 = ( F_13 ( V_41 , V_256 ) >> 16 ) & 0xff ;
if ( V_244 != V_26 ) {
F_4 ( L_54
L_55 ) ;
return;
}
F_72 ( & V_41 -> V_152 , V_151 ) ;
V_41 -> V_26 = - 1 ;
F_86 ( & V_41 -> V_213 ) ;
F_86 ( & V_41 -> V_219 ) ;
F_74 ( & V_41 -> V_152 , V_151 ) ;
F_94 ( & V_41 -> V_213 ) ;
F_94 ( & V_41 -> V_219 ) ;
F_72 ( & V_41 -> V_152 , V_151 ) ;
V_41 -> V_26 = V_26 ;
F_11 ( V_41 , V_260 , V_8 ) ;
if ( V_41 -> V_114 & V_115 )
V_41 -> V_110 = V_26 ;
if ( V_41 -> V_261 != NULL ) {
if ( V_41 -> V_261 != V_41 -> V_199 ) {
V_245 = V_41 -> V_199 ;
V_246 = V_41 -> V_262 ;
}
V_41 -> V_199 = V_41 -> V_261 ;
V_41 -> V_262 = V_41 -> V_263 ;
V_41 -> V_261 = NULL ;
F_11 ( V_41 , V_264 ,
F_10 ( V_41 -> V_199 [ 2 ] ) ) ;
V_41 -> V_199 [ 0 ] = V_41 -> V_265 ;
F_11 ( V_41 , V_266 ,
F_10 ( V_41 -> V_265 ) ) ;
}
#ifdef F_119
F_11 ( V_41 , V_267 , ~ 0 ) ;
F_11 ( V_41 , V_268 , ~ 0 ) ;
#endif
F_74 ( & V_41 -> V_152 , V_151 ) ;
if ( V_245 )
F_82 ( V_41 -> V_3 . V_77 , V_195 ,
V_245 , V_246 ) ;
F_6 ( V_41 -> V_25 , V_26 ,
V_27 , V_41 -> V_259 ) ;
F_120 ( & V_41 -> V_3 , V_41 -> V_25 , V_26 ,
V_27 , V_41 -> V_259 ,
V_41 -> V_269 ) ;
V_41 -> V_269 = false ;
}
static T_8 F_121 ( int V_270 , void * V_43 )
{
struct V_1 * V_41 = V_43 ;
T_1 V_271 , V_272 ;
int V_48 ;
V_271 = F_13 ( V_41 , V_260 ) ;
if ( ! V_271 || ! ~ V_271 )
return V_273 ;
F_11 ( V_41 , V_260 ,
V_271 & ~ ( V_8 | V_16 ) ) ;
F_2 ( V_271 ) ;
if ( V_271 & V_9 )
F_122 ( & V_41 -> F_118 ) ;
if ( V_271 & V_10 )
F_122 ( & V_41 -> V_116 . V_124 ) ;
if ( V_271 & V_11 )
F_122 ( & V_41 -> V_274 . V_124 ) ;
if ( V_271 & V_12 )
F_122 ( & V_41 -> V_213 . V_124 ) ;
if ( V_271 & V_13 )
F_122 ( & V_41 -> V_219 . V_124 ) ;
if ( V_271 & V_14 ) {
V_272 = F_13 ( V_41 , V_275 ) ;
F_11 ( V_41 , V_275 , V_272 ) ;
while ( V_272 ) {
V_48 = F_123 ( V_272 ) - 1 ;
F_122 (
& V_41 -> V_276 [ V_48 ] . V_141 . V_124 ) ;
V_272 &= ~ ( 1 << V_48 ) ;
}
}
if ( V_271 & V_15 ) {
V_272 = F_13 ( V_41 , V_277 ) ;
F_11 ( V_41 , V_277 , V_272 ) ;
while ( V_272 ) {
V_48 = F_123 ( V_272 ) - 1 ;
F_122 (
& V_41 -> V_278 [ V_48 ] . V_141 . V_124 ) ;
V_272 &= ~ ( 1 << V_48 ) ;
}
}
if ( F_8 ( V_271 & V_20 ) )
F_20 ( L_56
L_57 ) ;
if ( F_8 ( V_271 & V_16 ) ) {
F_13 ( V_41 , V_279 ) ;
F_13 ( V_41 , V_280 ) ;
F_11 ( V_41 , V_260 ,
V_16 ) ;
F_20 ( L_58 ) ;
}
if ( F_8 ( V_271 & V_17 ) ) {
if ( F_124 () )
F_4 ( L_59 ) ;
F_11 ( V_41 , V_254 ,
V_255 ) ;
}
if ( F_8 ( V_271 & V_19 ) ) {
if ( F_124 () )
F_4 ( L_60 ) ;
}
if ( F_8 ( V_271 & V_21 ) )
F_112 ( V_41 ) ;
if ( V_271 & V_18 ) {
F_125 ( & V_41 -> V_152 ) ;
F_117 ( V_41 ) ;
F_126 ( & V_41 -> V_152 ) ;
} else
F_15 ( V_41 ) ;
return V_281 ;
}
static int F_127 ( struct V_1 * V_41 )
{
int V_48 ;
F_11 ( V_41 , V_282 , V_283 ) ;
for ( V_48 = 0 ; V_48 < V_284 ; V_48 ++ ) {
if ( ( F_13 ( V_41 , V_282 ) &
V_283 ) == 0 )
return 0 ;
F_19 ( 1 ) ;
}
return - V_51 ;
}
static void F_128 ( V_39 * V_285 , const V_39 * V_286 , T_9 V_92 )
{
T_9 V_287 = V_92 * 4 ;
memcpy ( V_285 , V_286 , V_287 ) ;
if ( V_287 < V_195 )
memset ( & V_285 [ V_92 ] , 0 , V_195 - V_287 ) ;
}
static int F_129 ( struct V_1 * V_41 )
{
bool V_288 ;
int V_55 , V_289 , V_290 , V_42 ;
if ( ! ( F_13 ( V_41 , V_282 ) &
V_291 ) )
return 0 ;
V_288 = false ;
V_55 = F_16 ( V_41 , 2 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( ( V_55 & V_292 ) == V_292 ) {
V_55 = F_24 ( V_41 , 1 , 8 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( V_55 >= 1 )
V_288 = true ;
}
if ( V_41 -> V_114 & V_293 )
V_288 = false ;
if ( V_288 ) {
V_289 = 0 ;
V_290 = V_294 | V_295 ;
} else {
V_289 = V_294 | V_295 ;
V_290 = 0 ;
}
V_55 = F_23 ( V_41 , 5 , V_289 , V_290 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( V_288 )
V_42 = V_282 ;
else
V_42 = V_296 ;
F_11 ( V_41 , V_42 , V_297 ) ;
F_11 ( V_41 , V_296 ,
V_291 ) ;
return 0 ;
}
static int F_130 ( struct V_2 * V_3 ,
const V_39 * V_199 , T_9 V_92 )
{
struct V_1 * V_41 = V_1 ( V_3 ) ;
struct V_298 * V_299 = F_131 ( V_3 -> V_77 ) ;
T_1 V_300 , V_301 , V_302 , V_303 ;
int V_48 , V_55 ;
if ( F_127 ( V_41 ) ) {
F_20 ( L_61 ) ;
return - V_51 ;
}
F_11 ( V_41 , V_282 ,
V_304 |
V_305 ) ;
F_15 ( V_41 ) ;
for ( V_300 = 0 , V_48 = 0 ; ! V_300 && V_48 < 3 ; V_48 ++ ) {
F_19 ( 50 ) ;
V_300 = F_13 ( V_41 , V_282 ) &
V_304 ;
}
if ( ! V_300 ) {
F_20 ( L_62 ) ;
return - V_306 ;
}
F_11 ( V_41 , V_296 ,
V_307 ) ;
F_11 ( V_41 , V_308 , V_41 -> V_309 ) ;
F_11 ( V_41 , V_254 ,
V_310 |
V_255 ) ;
F_11 ( V_41 , V_311 ,
V_312 |
( V_313 << 4 ) |
( V_314 << 8 ) |
( 200 << 16 ) ) ;
V_301 = F_132 ( F_133 () ) ;
F_11 ( V_41 , V_239 , V_301 << 25 ) ;
V_41 -> V_242 = V_301 & ~ 0x3f ;
V_302 = F_13 ( V_41 , V_45 ) & 0x00ff00ff ;
if ( V_302 >= V_315 ) {
F_11 ( V_41 , V_316 ,
0xfffffffe ) ;
V_3 -> V_317 = true ;
}
F_11 ( V_41 , V_318 , 0x3f ) ;
V_41 -> V_319 = F_13 ( V_41 , V_318 ) & 0x3f ;
F_11 ( V_41 , V_318 , 0 ) ;
V_3 -> V_320 = V_41 -> V_319 != 0 ;
F_11 ( V_41 , V_321 , 0x00010000 ) ;
F_11 ( V_41 , V_260 , ~ 0 ) ;
F_11 ( V_41 , V_322 , ~ 0 ) ;
V_55 = F_129 ( V_41 ) ;
if ( V_55 < 0 )
return V_55 ;
V_55 = F_28 ( V_3 , 4 , 0 , V_323 | V_324 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( V_199 ) {
V_41 -> V_261 =
F_76 ( V_41 -> V_3 . V_77 , V_195 ,
& V_41 -> V_263 ,
V_125 ) ;
if ( V_41 -> V_261 == NULL )
return - V_138 ;
F_128 ( V_41 -> V_261 , V_199 , V_92 ) ;
} else {
V_41 -> V_261 = V_41 -> V_199 ;
V_41 -> V_263 = V_41 -> V_262 ;
}
V_41 -> V_265 = V_41 -> V_261 [ 0 ] ;
V_41 -> V_261 [ 0 ] = 0 ;
F_11 ( V_41 , V_266 , 0 ) ;
F_11 ( V_41 , V_264 ,
F_10 ( V_41 -> V_261 [ 2 ] ) ) ;
F_11 ( V_41 , V_325 , V_41 -> V_263 ) ;
F_11 ( V_41 , V_326 , 0x80000000 ) ;
if ( ! ( V_41 -> V_114 & V_327 ) )
F_134 ( V_299 ) ;
if ( F_135 ( V_299 -> V_270 , F_121 ,
F_136 ( V_299 ) ? 0 : V_328 ,
V_329 , V_41 ) ) {
F_20 ( L_63 , V_299 -> V_270 ) ;
F_137 ( V_299 ) ;
F_82 ( V_41 -> V_3 . V_77 , V_195 ,
V_41 -> V_199 , V_41 -> V_262 ) ;
return - V_306 ;
}
V_303 = V_12 | V_13 |
V_10 | V_11 |
V_15 | V_14 |
V_16 |
V_9 |
V_20 |
V_18 |
V_19 |
V_21 |
V_17 |
V_330 ;
if ( V_5 & V_7 )
V_303 |= V_8 ;
F_11 ( V_41 , V_331 , V_303 ) ;
F_11 ( V_41 , V_282 ,
V_332 |
V_333 ) ;
F_11 ( V_41 , V_254 ,
V_334 |
V_335 ) ;
F_66 ( & V_41 -> V_116 ) ;
F_66 ( & V_41 -> V_274 ) ;
F_138 ( & V_41 -> V_3 , false , true ) ;
return 0 ;
}
static int F_139 ( struct V_2 * V_3 ,
const V_39 * V_199 , T_9 V_92 )
{
struct V_1 * V_41 ;
unsigned long V_151 ;
V_39 * V_261 ;
T_2 V_153 ( V_263 ) ;
V_41 = V_1 ( V_3 ) ;
V_261 =
F_76 ( V_41 -> V_3 . V_77 , V_195 ,
& V_263 , V_125 ) ;
if ( V_261 == NULL )
return - V_138 ;
F_72 ( & V_41 -> V_152 , V_151 ) ;
if ( V_41 -> V_261 == NULL ) {
V_41 -> V_261 = V_261 ;
V_41 -> V_263 = V_263 ;
V_261 = NULL ;
}
F_128 ( V_41 -> V_261 , V_199 , V_92 ) ;
V_41 -> V_265 = V_199 [ 0 ] ;
V_41 -> V_261 [ 0 ] = 0 ;
F_11 ( V_41 , V_325 , V_41 -> V_263 ) ;
F_74 ( & V_41 -> V_152 , V_151 ) ;
if ( V_261 != NULL )
F_82 ( V_41 -> V_3 . V_77 , V_195 ,
V_261 , V_263 ) ;
F_138 ( & V_41 -> V_3 , true , true ) ;
return 0 ;
}
static void F_140 ( struct V_2 * V_3 , struct V_89 * V_167 )
{
struct V_1 * V_41 = V_1 ( V_3 ) ;
F_108 ( & V_41 -> V_213 , V_167 ) ;
}
static void F_141 ( struct V_2 * V_3 , struct V_89 * V_167 )
{
struct V_1 * V_41 = V_1 ( V_3 ) ;
F_108 ( & V_41 -> V_219 , V_167 ) ;
}
static int F_142 ( struct V_2 * V_3 , struct V_89 * V_167 )
{
struct V_1 * V_41 = V_1 ( V_3 ) ;
struct V_141 * V_61 = & V_41 -> V_213 ;
struct V_169 * V_169 = V_167 -> V_169 ;
int V_55 = - V_336 ;
F_95 ( & V_61 -> V_124 ) ;
if ( V_167 -> V_108 != 0 )
goto V_207;
if ( V_167 -> V_177 )
F_93 ( V_41 -> V_3 . V_77 , V_167 -> V_168 ,
V_167 -> V_97 , V_176 ) ;
F_7 ( 'T' , V_167 -> V_29 , V_167 -> V_32 , 0x20 ) ;
V_169 -> V_167 = NULL ;
V_167 -> V_108 = V_182 ;
V_167 -> V_150 ( V_167 , & V_41 -> V_3 , V_167 -> V_108 ) ;
V_55 = 0 ;
V_207:
F_96 ( & V_61 -> V_124 ) ;
return V_55 ;
}
static int F_143 ( struct V_2 * V_3 ,
int V_25 , int V_26 )
{
#ifdef F_119
return 0 ;
#else
struct V_1 * V_41 = V_1 ( V_3 ) ;
unsigned long V_151 ;
int V_337 , V_55 = 0 ;
F_72 ( & V_41 -> V_152 , V_151 ) ;
if ( V_41 -> V_26 != V_26 ) {
V_55 = - V_338 ;
goto V_207;
}
V_337 = ( V_25 & 0xffc0 ) == V_339 ? V_25 & 0x3f : 63 ;
if ( V_337 < 32 )
F_11 ( V_41 , V_268 , 1 << V_337 ) ;
else
F_11 ( V_41 , V_267 , 1 << ( V_337 - 32 ) ) ;
F_15 ( V_41 ) ;
V_207:
F_74 ( & V_41 -> V_152 , V_151 ) ;
return V_55 ;
#endif
}
static T_1 F_144 ( struct V_2 * V_3 , int V_340 )
{
struct V_1 * V_41 = V_1 ( V_3 ) ;
unsigned long V_151 ;
T_1 V_341 ;
switch ( V_340 ) {
case V_342 :
case V_343 :
if ( V_41 -> V_253 &&
( F_13 ( V_41 , V_254 ) &
V_255 ) )
V_341 = V_344 ;
else
V_341 = 0 ;
if ( V_41 -> V_269 )
V_341 |= V_345 ;
return V_341 ;
case V_346 :
return F_13 ( V_41 , V_248 ) << 16 ;
case V_347 :
return F_116 ( V_41 ) ;
case V_348 :
F_72 ( & V_41 -> V_152 , V_151 ) ;
V_341 = F_117 ( V_41 ) ;
F_74 ( & V_41 -> V_152 , V_151 ) ;
return V_341 ;
case V_349 :
V_341 = F_13 ( V_41 , V_311 ) ;
return ( V_341 >> 4 ) & 0x0ffff00f ;
case V_350 :
return ( F_13 ( V_41 , V_318 ) & 0x3f ) |
( V_41 -> V_319 << 8 ) ;
default:
F_145 ( 1 ) ;
return 0 ;
}
}
static void F_146 ( struct V_2 * V_3 , int V_340 , T_1 V_341 )
{
struct V_1 * V_41 = V_1 ( V_3 ) ;
unsigned long V_151 ;
switch ( V_340 ) {
case V_342 :
if ( ( V_341 & V_344 ) && V_41 -> V_253 ) {
F_11 ( V_41 , V_351 ,
V_255 ) ;
F_15 ( V_41 ) ;
}
if ( V_341 & V_345 )
V_41 -> V_269 = false ;
break;
case V_343 :
if ( ( V_341 & V_344 ) && V_41 -> V_253 ) {
F_11 ( V_41 , V_254 ,
V_255 ) ;
F_15 ( V_41 ) ;
}
if ( V_341 & V_345 )
V_41 -> V_269 = true ;
break;
case V_346 :
F_11 ( V_41 , V_248 , V_341 >> 16 ) ;
F_15 ( V_41 ) ;
break;
case V_347 :
F_11 ( V_41 , V_239 , V_341 ) ;
F_11 ( V_41 , V_352 ,
V_19 ) ;
F_15 ( V_41 ) ;
break;
case V_348 :
F_72 ( & V_41 -> V_152 , V_151 ) ;
V_41 -> V_242 = ( V_41 -> V_242 & 0x7f ) | ( V_341 & ~ 0x7f ) ;
F_74 ( & V_41 -> V_152 , V_151 ) ;
break;
case V_349 :
V_341 = ( V_341 & 0xf ) | ( ( V_341 & 0xf ) << 4 ) |
( ( V_341 & 0xf ) << 8 ) | ( ( V_341 & 0x0ffff000 ) << 4 ) ;
F_11 ( V_41 , V_311 , V_341 ) ;
F_15 ( V_41 ) ;
break;
case V_350 :
F_11 ( V_41 , V_318 , V_341 & 0x3f ) ;
F_15 ( V_41 ) ;
break;
default:
F_145 ( 1 ) ;
break;
}
}
static void F_147 ( struct V_353 * V_61 , void * V_90 )
{
int V_48 = V_61 -> V_96 ;
if ( V_48 + V_61 -> V_354 . V_355 > V_69 )
return;
if ( V_61 -> V_354 . V_355 > 0 )
* ( T_1 * ) ( V_61 -> V_32 + V_48 ) = F_148 ( * ( T_1 * ) ( V_90 + 4 ) ) ;
if ( V_61 -> V_354 . V_355 > 4 )
* ( T_1 * ) ( V_61 -> V_32 + V_48 + 4 ) = F_148 ( * ( T_1 * ) V_90 ) ;
if ( V_61 -> V_354 . V_355 > 8 )
memcpy ( V_61 -> V_32 + V_48 + 8 , V_90 + 8 , V_61 -> V_354 . V_355 - 8 ) ;
V_61 -> V_96 += V_61 -> V_354 . V_355 ;
}
static int F_149 ( struct V_141 * V_141 ,
struct V_64 * V_65 ,
struct V_64 * V_83 )
{
struct V_353 * V_61 =
F_1 ( V_141 , struct V_353 , V_141 ) ;
struct V_64 * V_356 ;
T_4 * V_357 ;
void * V_90 ;
for ( V_356 = V_65 ; V_356 <= V_83 ; V_356 ++ )
if ( V_356 -> V_70 )
break;
if ( V_356 > V_83 )
return 0 ;
V_90 = V_83 + 1 ;
F_147 ( V_61 , V_90 ) ;
if ( F_48 ( V_83 -> V_133 ) & V_178 ) {
V_357 = ( T_4 * ) V_90 ;
V_61 -> V_354 . V_150 . V_358 ( & V_61 -> V_354 ,
F_71 ( V_357 [ 0 ] ) & 0xffff ,
V_61 -> V_96 , V_61 -> V_32 ,
V_61 -> V_354 . V_359 ) ;
V_61 -> V_96 = 0 ;
}
return 1 ;
}
static int F_150 ( struct V_141 * V_141 ,
struct V_64 * V_65 ,
struct V_64 * V_83 )
{
struct V_353 * V_61 =
F_1 ( V_141 , struct V_353 , V_141 ) ;
if ( ! V_83 -> V_70 )
return 0 ;
if ( F_48 ( V_83 -> V_133 ) & V_178 )
V_61 -> V_354 . V_150 . V_360 ( & V_61 -> V_354 ,
F_71 ( V_83 -> V_137 ) +
F_48 ( V_83 -> V_132 ) -
F_48 ( V_83 -> V_68 ) ,
V_61 -> V_354 . V_359 ) ;
return 1 ;
}
static int F_151 ( struct V_141 * V_141 ,
struct V_64 * V_65 ,
struct V_64 * V_83 )
{
struct V_353 * V_61 =
F_1 ( V_141 , struct V_353 , V_141 ) ;
int V_48 ;
struct V_64 * V_356 ;
for ( V_356 = V_65 ; V_356 <= V_83 ; V_356 ++ )
if ( V_356 -> V_70 )
break;
if ( V_356 > V_83 )
return 0 ;
V_48 = V_61 -> V_96 ;
if ( V_48 + 4 < V_69 ) {
* ( V_39 * ) ( V_61 -> V_32 + V_48 ) = F_105 (
( ( T_1 ) F_48 ( V_356 -> V_70 ) << 16 ) |
F_48 ( V_356 -> V_68 ) ) ;
V_61 -> V_96 += 4 ;
}
if ( F_48 ( V_83 -> V_133 ) & V_178 ) {
V_61 -> V_354 . V_150 . V_358 ( & V_61 -> V_354 , F_48 ( V_83 -> V_68 ) ,
V_61 -> V_96 , V_61 -> V_32 ,
V_61 -> V_354 . V_359 ) ;
V_61 -> V_96 = 0 ;
}
return 1 ;
}
static void F_152 ( struct V_1 * V_41 , T_6 V_361 )
{
T_1 V_362 = V_361 >> 32 , V_363 = V_361 ;
F_11 ( V_41 , V_364 , ~ V_362 ) ;
F_11 ( V_41 , V_365 , ~ V_363 ) ;
F_11 ( V_41 , V_366 , V_362 ) ;
F_11 ( V_41 , V_367 , V_363 ) ;
F_153 () ;
V_41 -> V_368 = V_361 ;
}
static struct V_369 * F_154 ( struct V_2 * V_3 ,
int type , int V_370 , T_9 V_355 )
{
struct V_1 * V_41 = V_1 ( V_3 ) ;
struct V_353 * V_153 ( V_61 ) ;
T_5 V_153 ( V_150 ) ;
T_6 * V_153 ( V_361 ) ;
T_1 * V_153 ( V_371 ) , V_153 ( V_72 ) ;
unsigned long V_151 ;
int V_63 , V_55 = - V_51 ;
F_72 ( & V_41 -> V_152 , V_151 ) ;
switch ( type ) {
case V_372 :
V_371 = & V_41 -> V_373 ;
V_150 = F_151 ;
V_63 = F_123 ( * V_371 ) - 1 ;
if ( V_63 >= 0 ) {
* V_371 &= ~ ( 1 << V_63 ) ;
V_72 = F_113 ( V_63 ) ;
V_61 = & V_41 -> V_278 [ V_63 ] ;
}
break;
case V_374 :
V_361 = & V_41 -> V_375 ;
V_371 = & V_41 -> V_376 ;
V_150 = F_149 ;
V_63 = * V_361 & 1ULL << V_370 ? F_123 ( * V_371 ) - 1 : - 1 ;
if ( V_63 >= 0 ) {
* V_361 &= ~ ( 1ULL << V_370 ) ;
* V_371 &= ~ ( 1 << V_63 ) ;
V_72 = F_114 ( V_63 ) ;
V_61 = & V_41 -> V_276 [ V_63 ] ;
}
break;
case V_377 :
V_371 = & V_41 -> V_376 ;
V_150 = F_150 ;
V_63 = ! V_41 -> V_378 ? F_123 ( * V_371 ) - 1 : - 1 ;
if ( V_63 >= 0 ) {
V_41 -> V_378 = true ;
* V_371 &= ~ ( 1 << V_63 ) ;
V_72 = F_114 ( V_63 ) ;
V_61 = & V_41 -> V_276 [ V_63 ] ;
}
break;
default:
V_63 = - 1 ;
V_55 = - V_379 ;
}
F_74 ( & V_41 -> V_152 , V_151 ) ;
if ( V_63 < 0 )
return F_155 ( V_55 ) ;
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
V_61 -> V_96 = 0 ;
V_61 -> V_32 = ( void * ) F_156 ( V_125 ) ;
if ( V_61 -> V_32 == NULL ) {
V_55 = - V_138 ;
goto V_207;
}
V_55 = F_78 ( & V_61 -> V_141 , V_41 , V_72 , V_150 ) ;
if ( V_55 < 0 )
goto V_380;
if ( type == V_377 )
F_152 ( V_41 , 0 ) ;
return & V_61 -> V_354 ;
V_380:
F_157 ( ( unsigned long ) V_61 -> V_32 ) ;
V_207:
F_72 ( & V_41 -> V_152 , V_151 ) ;
switch ( type ) {
case V_374 :
* V_361 |= 1ULL << V_370 ;
break;
case V_377 :
V_41 -> V_378 = false ;
break;
}
* V_371 |= 1 << V_63 ;
F_74 ( & V_41 -> V_152 , V_151 ) ;
return F_155 ( V_55 ) ;
}
static int F_158 ( struct V_369 * V_354 ,
T_7 V_381 , T_1 V_382 , T_1 V_383 )
{
struct V_353 * V_61 = F_1 ( V_354 , struct V_353 , V_354 ) ;
struct V_1 * V_41 = V_61 -> V_141 . V_41 ;
T_1 V_133 = V_384 , V_385 ;
int V_63 ;
if ( V_61 -> V_141 . V_83 -> V_67 == 0 )
return - V_386 ;
switch ( V_61 -> V_354 . type ) {
case V_372 :
V_63 = V_61 - V_41 -> V_278 ;
V_385 = 0 ;
if ( V_381 >= 0 )
V_385 = V_387 |
( V_381 & 0x7fff ) << 16 ;
F_11 ( V_41 , V_277 , 1 << V_63 ) ;
F_11 ( V_41 , V_388 , 1 << V_63 ) ;
F_84 ( & V_61 -> V_141 , V_385 ) ;
break;
case V_377 :
V_133 |= V_389 | V_390 ;
case V_374 :
V_63 = V_61 - V_41 -> V_276 ;
V_385 = ( V_383 << 28 ) | ( V_382 << 8 ) | V_61 -> V_354 . V_370 ;
if ( V_381 >= 0 ) {
V_385 |= ( V_381 & 0x07fff ) << 12 ;
V_133 |= V_391 ;
}
F_11 ( V_41 , V_275 , 1 << V_63 ) ;
F_11 ( V_41 , V_392 , 1 << V_63 ) ;
F_11 ( V_41 , F_159 ( V_61 -> V_141 . V_72 ) , V_385 ) ;
F_84 ( & V_61 -> V_141 , V_133 ) ;
V_61 -> V_382 = V_382 ;
V_61 -> V_383 = V_383 ;
break;
}
return 0 ;
}
static int F_160 ( struct V_369 * V_354 )
{
struct V_1 * V_41 = V_1 ( V_354 -> V_3 ) ;
struct V_353 * V_61 = F_1 ( V_354 , struct V_353 , V_354 ) ;
int V_63 ;
switch ( V_61 -> V_354 . type ) {
case V_372 :
V_63 = V_61 - V_41 -> V_278 ;
F_11 ( V_41 , V_393 , 1 << V_63 ) ;
break;
case V_374 :
case V_377 :
V_63 = V_61 - V_41 -> V_276 ;
F_11 ( V_41 , V_394 , 1 << V_63 ) ;
break;
}
F_15 ( V_41 ) ;
F_86 ( & V_61 -> V_141 ) ;
F_161 ( & V_61 -> V_141 . V_124 ) ;
return 0 ;
}
static void F_162 ( struct V_369 * V_354 )
{
struct V_1 * V_41 = V_1 ( V_354 -> V_3 ) ;
struct V_353 * V_61 = F_1 ( V_354 , struct V_353 , V_354 ) ;
unsigned long V_151 ;
int V_63 ;
F_160 ( V_354 ) ;
F_80 ( & V_61 -> V_141 ) ;
F_157 ( ( unsigned long ) V_61 -> V_32 ) ;
F_72 ( & V_41 -> V_152 , V_151 ) ;
switch ( V_354 -> type ) {
case V_372 :
V_63 = V_61 - V_41 -> V_278 ;
V_41 -> V_373 |= 1 << V_63 ;
break;
case V_374 :
V_63 = V_61 - V_41 -> V_276 ;
V_41 -> V_376 |= 1 << V_63 ;
V_41 -> V_375 |= 1ULL << V_354 -> V_370 ;
break;
case V_377 :
V_63 = V_61 - V_41 -> V_276 ;
V_41 -> V_376 |= 1 << V_63 ;
V_41 -> V_375 |= V_41 -> V_368 ;
V_41 -> V_368 = 0 ;
V_41 -> V_378 = false ;
break;
}
F_74 ( & V_41 -> V_152 , V_151 ) ;
}
static int F_163 ( struct V_369 * V_354 , T_6 * V_361 )
{
struct V_1 * V_41 = V_1 ( V_354 -> V_3 ) ;
unsigned long V_151 ;
int V_55 ;
switch ( V_354 -> type ) {
case V_377 :
F_72 ( & V_41 -> V_152 , V_151 ) ;
if ( ~ V_41 -> V_375 & ~ V_41 -> V_368 & * V_361 ) {
* V_361 = V_41 -> V_375 ;
V_55 = - V_51 ;
} else {
F_152 ( V_41 , * V_361 ) ;
V_55 = 0 ;
}
F_74 ( & V_41 -> V_152 , V_151 ) ;
break;
default:
V_55 = - V_395 ;
}
return V_55 ;
}
static void F_164 ( struct V_1 * V_41 )
{
int V_48 ;
struct V_353 * V_61 ;
for ( V_48 = 0 ; V_48 < V_41 -> V_396 ; V_48 ++ ) {
V_61 = & V_41 -> V_276 [ V_48 ] ;
if ( V_61 -> V_141 . V_164 )
F_158 ( & V_61 -> V_354 , 0 , V_61 -> V_382 , V_61 -> V_383 ) ;
}
for ( V_48 = 0 ; V_48 < V_41 -> V_397 ; V_48 ++ ) {
V_61 = & V_41 -> V_278 [ V_48 ] ;
if ( V_61 -> V_141 . V_164 )
F_158 ( & V_61 -> V_354 , 0 , V_61 -> V_382 , V_61 -> V_383 ) ;
}
}
static int F_165 ( struct V_353 * V_61 ,
struct V_398 * V_167 ,
struct V_399 * V_74 ,
unsigned long V_107 )
{
struct V_64 * V_65 , * V_83 , * V_356 ;
struct V_398 * V_90 ;
T_4 * V_32 ;
T_2 V_162 , V_400 ;
T_1 V_139 , V_401 , V_402 , V_270 ;
T_1 V_403 , V_404 , V_405 ;
int V_57 , V_406 , V_48 , V_92 , V_42 ;
V_90 = V_167 ;
V_403 = V_107 ;
if ( V_90 -> V_407 )
V_139 = 1 ;
else
V_139 = 2 ;
if ( V_90 -> V_96 > 0 )
V_139 ++ ;
V_406 = F_166 ( V_403 + V_90 -> V_97 ) >> V_408 ;
if ( V_90 -> V_97 > 0 )
V_402 = V_406 - ( V_403 >> V_408 ) ;
else
V_402 = 0 ;
V_139 += V_402 ;
V_401 = F_167 ( V_90 -> V_96 , sizeof( * V_65 ) ) ;
V_65 = F_83 ( & V_61 -> V_141 , V_139 + V_401 , & V_162 ) ;
if ( V_65 == NULL )
return - V_138 ;
if ( ! V_90 -> V_407 ) {
V_65 [ 0 ] . V_133 = F_33 ( V_171 ) ;
V_65 [ 0 ] . V_132 = F_33 ( 8 ) ;
V_65 [ 0 ] . V_67 = F_32 ( V_162 | V_139 ) ;
V_32 = ( T_4 * ) & V_65 [ 1 ] ;
V_32 [ 0 ] = F_32 ( F_168 ( V_90 -> V_409 ) |
F_169 ( V_90 -> V_410 ) |
F_170 ( V_174 ) |
F_171 ( V_61 -> V_354 . V_370 ) |
F_172 ( V_61 -> V_354 . V_29 ) ) ;
V_32 [ 1 ] =
F_32 ( F_173 ( V_90 -> V_96 +
V_90 -> V_97 ) ) ;
}
if ( V_90 -> V_96 > 0 ) {
V_65 [ 2 ] . V_132 = F_33 ( V_90 -> V_96 ) ;
V_65 [ 2 ] . V_137 = F_32 ( V_162 + V_139 * sizeof( * V_65 ) ) ;
memcpy ( & V_65 [ V_139 ] , V_90 -> V_32 , V_90 -> V_96 ) ;
}
V_356 = V_65 + V_139 - V_402 ;
V_404 = V_403 + V_90 -> V_97 ;
for ( V_48 = 0 ; V_48 < V_402 ; V_48 ++ ) {
V_57 = V_403 >> V_408 ;
V_42 = V_403 & ~ V_411 ;
V_405 = ( V_57 + 1 ) << V_408 ;
V_92 =
F_174 ( V_405 , V_404 ) - V_403 ;
V_356 [ V_48 ] . V_132 = F_33 ( V_92 ) ;
V_400 = F_30 ( V_74 -> V_62 [ V_57 ] ) ;
V_356 [ V_48 ] . V_137 = F_32 ( V_400 + V_42 ) ;
V_403 += V_92 ;
}
if ( V_90 -> V_412 )
V_270 = V_178 ;
else
V_270 = V_413 ;
V_83 = V_139 == 2 ? V_65 : V_65 + V_139 - 1 ;
V_83 -> V_133 |= F_33 ( V_159 |
V_135 |
V_136 |
V_270 ) ;
F_85 ( & V_61 -> V_141 , V_65 , V_139 , V_401 ) ;
return 0 ;
}
static int F_175 ( struct V_353 * V_61 ,
struct V_398 * V_167 ,
struct V_399 * V_74 ,
unsigned long V_107 )
{
struct V_64 * V_65 , * V_356 ;
T_2 V_162 , V_400 ;
T_1 V_139 , V_401 , V_414 ;
int V_48 , V_243 , V_92 ;
int V_57 , V_42 , V_415 , V_355 , V_416 ;
V_415 = V_167 -> V_96 / V_61 -> V_354 . V_355 ;
V_355 = F_176 ( V_61 -> V_354 . V_355 , ( T_9 ) 8 ) ;
V_401 = F_167 ( V_355 , sizeof( * V_65 ) ) ;
V_57 = V_107 >> V_408 ;
V_42 = V_107 & ~ V_411 ;
V_416 = V_167 -> V_97 / V_415 ;
for ( V_48 = 0 ; V_48 < V_415 ; V_48 ++ ) {
V_139 = F_167 ( V_416 + V_42 , V_69 ) + 1 ;
V_65 = F_83 ( & V_61 -> V_141 ,
V_139 + V_401 , & V_162 ) ;
if ( V_65 == NULL )
return - V_138 ;
V_65 -> V_133 = F_33 ( V_135 |
V_134 ) ;
if ( V_167 -> V_407 && V_48 == 0 )
V_65 -> V_133 |= F_33 ( V_417 ) ;
V_65 -> V_132 = F_33 ( V_355 ) ;
V_65 -> V_68 = V_65 -> V_132 ;
V_65 -> V_70 = 0 ;
V_65 -> V_137 = F_32 ( V_162 + ( V_139 * sizeof( * V_65 ) ) ) ;
V_414 = V_416 ;
V_356 = V_65 ;
for ( V_243 = 1 ; V_243 < V_139 ; V_243 ++ ) {
V_356 ++ ;
V_356 -> V_133 = F_33 ( V_135 |
V_134 ) ;
if ( V_42 + V_414 < V_69 )
V_92 = V_414 ;
else
V_92 = V_69 - V_42 ;
V_356 -> V_132 = F_33 ( V_92 ) ;
V_356 -> V_68 = V_356 -> V_132 ;
V_356 -> V_70 = 0 ;
V_400 = F_30 ( V_74 -> V_62 [ V_57 ] ) ;
V_356 -> V_137 = F_32 ( V_400 + V_42 ) ;
V_42 = ( V_42 + V_92 ) & ~ V_411 ;
V_414 -= V_92 ;
if ( V_42 == 0 )
V_57 ++ ;
}
V_356 -> V_133 = F_33 ( V_135 |
V_418 |
V_136 ) ;
if ( V_167 -> V_412 && V_48 == V_415 - 1 )
V_356 -> V_133 |= F_33 ( V_178 ) ;
F_85 ( & V_61 -> V_141 , V_65 , V_139 , V_401 ) ;
}
return 0 ;
}
static int F_177 ( struct V_353 * V_61 ,
struct V_398 * V_167 ,
struct V_399 * V_74 ,
unsigned long V_107 )
{
struct V_64 * V_65 ;
T_2 V_162 , V_400 ;
int V_57 , V_42 , V_414 , V_139 , V_48 , V_92 ;
V_57 = V_107 >> V_408 ;
V_42 = V_107 & ~ V_411 ;
V_414 = V_167 -> V_97 ;
V_139 = F_167 ( V_42 + V_414 , V_69 ) ;
if ( F_145 ( V_42 & 3 || V_414 & 3 || V_57 + V_139 > V_74 -> V_419 ) )
return - V_420 ;
for ( V_48 = 0 ; V_48 < V_139 ; V_48 ++ ) {
V_65 = F_83 ( & V_61 -> V_141 , 1 , & V_162 ) ;
if ( V_65 == NULL )
return - V_138 ;
V_65 -> V_133 = F_33 ( V_134 |
V_136 ) ;
if ( V_167 -> V_407 && V_48 == 0 )
V_65 -> V_133 |= F_33 ( V_417 ) ;
if ( V_167 -> V_412 && V_48 == V_139 - 1 )
V_65 -> V_133 |= F_33 ( V_178 ) ;
if ( V_42 + V_414 < V_69 )
V_92 = V_414 ;
else
V_92 = V_69 - V_42 ;
V_65 -> V_132 = F_33 ( V_92 ) ;
V_65 -> V_68 = V_65 -> V_132 ;
V_65 -> V_70 = 0 ;
V_400 = F_30 ( V_74 -> V_62 [ V_57 ] ) ;
V_65 -> V_137 = F_32 ( V_400 + V_42 ) ;
V_414 -= V_92 ;
V_42 = 0 ;
V_57 ++ ;
F_85 ( & V_61 -> V_141 , V_65 , 1 , 0 ) ;
}
return 0 ;
}
static int F_178 ( struct V_369 * V_354 ,
struct V_398 * V_167 ,
struct V_399 * V_74 ,
unsigned long V_107 )
{
struct V_353 * V_61 = F_1 ( V_354 , struct V_353 , V_354 ) ;
unsigned long V_151 ;
int V_55 = - V_379 ;
F_72 ( & V_61 -> V_141 . V_41 -> V_152 , V_151 ) ;
switch ( V_354 -> type ) {
case V_372 :
V_55 = F_165 ( V_61 , V_167 , V_74 , V_107 ) ;
break;
case V_374 :
V_55 = F_175 ( V_61 , V_167 , V_74 , V_107 ) ;
break;
case V_377 :
V_55 = F_177 ( V_61 , V_167 , V_74 , V_107 ) ;
break;
}
F_74 ( & V_61 -> V_141 . V_41 -> V_152 , V_151 ) ;
return V_55 ;
}
static void F_179 ( struct V_369 * V_354 )
{
struct V_141 * V_61 =
& F_1 ( V_354 , struct V_353 , V_354 ) -> V_141 ;
F_11 ( V_61 -> V_41 , F_35 ( V_61 -> V_72 ) , V_73 ) ;
F_15 ( V_61 -> V_41 ) ;
}
static void F_180 ( struct V_298 * V_299 )
{
if ( F_181 ( V_421 ) ) {
struct V_422 * V_423 = F_182 ( V_299 ) ;
if ( V_423 ) {
F_183 ( V_424 , V_423 , 0 , 1 ) ;
F_183 ( V_425 , V_423 , 0 , 1 ) ;
}
}
}
static void F_184 ( struct V_298 * V_299 )
{
if ( F_181 ( V_421 ) ) {
struct V_422 * V_423 = F_182 ( V_299 ) ;
if ( V_423 ) {
F_183 ( V_425 , V_423 , 0 , 0 ) ;
F_183 ( V_424 , V_423 , 0 , 0 ) ;
}
}
}
static inline void F_180 ( struct V_298 * V_299 ) {}
static inline void F_184 ( struct V_298 * V_299 ) {}
static int T_10 F_185 ( struct V_298 * V_299 ,
const struct V_426 * V_427 )
{
struct V_1 * V_41 ;
T_1 V_428 , V_429 , V_430 , V_302 ;
T_6 V_431 ;
int V_48 , V_432 ;
T_9 V_287 ;
if ( V_299 -> V_433 == V_434 ) {
F_186 ( & V_299 -> V_299 , L_64 ) ;
return - V_379 ;
}
V_41 = F_187 ( sizeof( * V_41 ) , V_125 ) ;
if ( V_41 == NULL ) {
V_432 = - V_138 ;
goto V_435;
}
F_188 ( & V_41 -> V_3 , & V_436 , & V_299 -> V_299 ) ;
F_180 ( V_299 ) ;
V_432 = F_189 ( V_299 ) ;
if ( V_432 ) {
F_20 ( L_65 ) ;
goto V_437;
}
F_190 ( V_299 ) ;
F_191 ( V_299 , V_438 , 0 ) ;
F_192 ( V_299 , V_41 ) ;
F_193 ( & V_41 -> V_152 ) ;
F_194 ( & V_41 -> V_59 ) ;
F_60 ( & V_41 -> F_118 ,
F_118 , ( unsigned long ) V_41 ) ;
V_432 = F_195 ( V_299 , 0 , V_329 ) ;
if ( V_432 ) {
F_20 ( L_66 ) ;
goto V_439;
}
V_41 -> V_44 = F_196 ( V_299 , 0 , V_440 ) ;
if ( V_41 -> V_44 == NULL ) {
F_20 ( L_67 ) ;
V_432 = - V_441 ;
goto V_442;
}
for ( V_48 = 0 ; V_48 < F_9 ( V_443 ) ; V_48 ++ )
if ( ( V_443 [ V_48 ] . V_433 == V_299 -> V_433 ) &&
( V_443 [ V_48 ] . V_77 == ( unsigned short ) V_444 ||
V_443 [ V_48 ] . V_77 == V_299 -> V_77 ) &&
( V_443 [ V_48 ] . V_445 == ( unsigned short ) V_444 ||
V_443 [ V_48 ] . V_445 >= V_299 -> V_445 ) ) {
V_41 -> V_114 = V_443 [ V_48 ] . V_151 ;
break;
}
if ( V_446 )
V_41 -> V_114 = V_446 ;
F_91 ( V_75 * sizeof( struct V_64 ) > V_69 / 4 ) ;
F_91 ( V_447 > V_69 / 2 ) ;
V_41 -> V_129 = F_76 ( V_41 -> V_3 . V_77 ,
V_69 ,
& V_41 -> V_131 ,
V_125 ) ;
if ( ! V_41 -> V_129 ) {
V_432 = - V_138 ;
goto V_448;
}
V_432 = F_59 ( & V_41 -> V_116 , V_41 , 0 ,
V_449 ) ;
if ( V_432 < 0 )
goto V_450;
V_432 = F_59 ( & V_41 -> V_274 , V_41 , V_69 / 4 ,
V_451 ) ;
if ( V_432 < 0 )
goto V_452;
V_432 = F_78 ( & V_41 -> V_213 , V_41 ,
V_453 , F_97 ) ;
if ( V_432 < 0 )
goto V_454;
V_432 = F_78 ( & V_41 -> V_219 , V_41 ,
V_455 , F_97 ) ;
if ( V_432 < 0 )
goto V_456;
F_11 ( V_41 , V_392 , ~ 0 ) ;
V_41 -> V_375 = ~ 0ULL ;
V_41 -> V_228 = F_13 ( V_41 , V_392 ) ;
F_11 ( V_41 , V_394 , ~ 0 ) ;
V_41 -> V_376 = V_41 -> V_228 ;
V_41 -> V_396 = F_197 ( V_41 -> V_376 ) ;
V_287 = sizeof( struct V_353 ) * V_41 -> V_396 ;
V_41 -> V_276 = F_187 ( V_287 , V_125 ) ;
F_11 ( V_41 , V_388 , ~ 0 ) ;
V_41 -> V_227 = F_13 ( V_41 , V_388 ) ;
F_11 ( V_41 , V_393 , ~ 0 ) ;
V_41 -> V_373 = V_41 -> V_227 ;
V_41 -> V_397 = F_197 ( V_41 -> V_373 ) ;
V_287 = sizeof( struct V_353 ) * V_41 -> V_397 ;
V_41 -> V_278 = F_187 ( V_287 , V_125 ) ;
if ( V_41 -> V_278 == NULL || V_41 -> V_276 == NULL ) {
V_432 = - V_138 ;
goto V_457;
}
V_41 -> V_258 = V_41 -> V_129 + V_69 / 2 ;
V_41 -> V_309 = V_41 -> V_131 + V_69 / 2 ;
V_428 = F_13 ( V_41 , V_264 ) ;
V_429 = ( V_428 >> 12 ) & 0xf ;
V_430 = V_428 & 0x7 ;
V_431 = ( ( T_6 ) F_13 ( V_41 , V_458 ) << 32 ) |
F_13 ( V_41 , V_459 ) ;
V_432 = F_198 ( & V_41 -> V_3 , V_429 , V_430 , V_431 ) ;
if ( V_432 )
goto V_457;
V_302 = F_13 ( V_41 , V_45 ) & 0x00ff00ff ;
F_4 ( L_68
L_69 ,
F_199 ( & V_299 -> V_299 ) , V_302 >> 16 , V_302 & 0xff ,
V_41 -> V_396 , V_41 -> V_397 , V_41 -> V_114 ) ;
return 0 ;
V_457:
F_200 ( V_41 -> V_276 ) ;
F_200 ( V_41 -> V_278 ) ;
F_80 ( & V_41 -> V_219 ) ;
V_456:
F_80 ( & V_41 -> V_213 ) ;
V_454:
F_36 ( & V_41 -> V_274 ) ;
V_452:
F_36 ( & V_41 -> V_116 ) ;
V_450:
F_82 ( V_41 -> V_3 . V_77 , V_69 ,
V_41 -> V_129 , V_41 -> V_131 ) ;
V_448:
F_201 ( V_299 , V_41 -> V_44 ) ;
V_442:
F_202 ( V_299 , 0 ) ;
V_439:
F_203 ( V_299 ) ;
V_437:
F_200 ( V_41 ) ;
F_184 ( V_299 ) ;
V_435:
if ( V_432 == - V_138 )
F_20 ( L_70 ) ;
return V_432 ;
}
static void F_204 ( struct V_298 * V_299 )
{
struct V_1 * V_41 ;
V_41 = F_205 ( V_299 ) ;
F_11 ( V_41 , V_322 , ~ 0 ) ;
F_15 ( V_41 ) ;
F_206 ( & V_41 -> V_3 ) ;
F_127 ( V_41 ) ;
F_207 ( V_299 -> V_270 , V_41 ) ;
if ( V_41 -> V_261 && V_41 -> V_261 != V_41 -> V_199 )
F_82 ( V_41 -> V_3 . V_77 , V_195 ,
V_41 -> V_261 , V_41 -> V_263 ) ;
if ( V_41 -> V_199 )
F_82 ( V_41 -> V_3 . V_77 , V_195 ,
V_41 -> V_199 , V_41 -> V_262 ) ;
F_36 ( & V_41 -> V_116 ) ;
F_36 ( & V_41 -> V_274 ) ;
F_82 ( V_41 -> V_3 . V_77 , V_69 ,
V_41 -> V_129 , V_41 -> V_131 ) ;
F_80 ( & V_41 -> V_213 ) ;
F_80 ( & V_41 -> V_219 ) ;
F_200 ( V_41 -> V_278 ) ;
F_200 ( V_41 -> V_276 ) ;
F_137 ( V_299 ) ;
F_201 ( V_299 , V_41 -> V_44 ) ;
F_202 ( V_299 , 0 ) ;
F_203 ( V_299 ) ;
F_200 ( V_41 ) ;
F_184 ( V_299 ) ;
F_4 ( L_71 ) ;
}
static int F_208 ( struct V_298 * V_299 , T_11 V_460 )
{
struct V_1 * V_41 = F_205 ( V_299 ) ;
int V_432 ;
F_127 ( V_41 ) ;
F_207 ( V_299 -> V_270 , V_41 ) ;
F_137 ( V_299 ) ;
V_432 = F_209 ( V_299 ) ;
if ( V_432 ) {
F_20 ( L_72 ) ;
return V_432 ;
}
V_432 = F_210 ( V_299 , F_211 ( V_299 , V_460 ) ) ;
if ( V_432 )
F_20 ( L_73 , V_432 ) ;
F_184 ( V_299 ) ;
return 0 ;
}
static int F_212 ( struct V_298 * V_299 )
{
struct V_1 * V_41 = F_205 ( V_299 ) ;
int V_432 ;
F_180 ( V_299 ) ;
F_210 ( V_299 , V_461 ) ;
F_213 ( V_299 ) ;
V_432 = F_189 ( V_299 ) ;
if ( V_432 ) {
F_20 ( L_74 ) ;
return V_432 ;
}
if ( ! F_13 ( V_41 , V_459 ) &&
! F_13 ( V_41 , V_458 ) ) {
F_11 ( V_41 , V_459 , ( T_1 ) V_41 -> V_3 . V_431 ) ;
F_11 ( V_41 , V_458 , ( T_1 ) ( V_41 -> V_3 . V_431 >> 32 ) ) ;
}
V_432 = F_130 ( & V_41 -> V_3 , NULL , 0 ) ;
if ( V_432 )
return V_432 ;
F_164 ( V_41 ) ;
return 0 ;
}
static int T_12 F_214 ( void )
{
return F_215 ( & V_462 ) ;
}
static void T_13 F_216 ( void )
{
F_217 ( & V_462 ) ;
}
