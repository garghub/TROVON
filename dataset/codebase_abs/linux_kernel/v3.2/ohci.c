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
if ( ! ~ V_47 )
return - V_50 ;
if ( V_47 & V_51 )
return F_18 ( V_47 ) ;
if ( V_48 >= 3 )
F_19 ( 1 ) ;
}
F_20 ( L_34 ) ;
return - V_52 ;
}
static int F_21 ( const struct V_1 * V_41 , int V_46 , T_1 V_47 )
{
int V_48 ;
F_11 ( V_41 , V_49 ,
F_22 ( V_46 , V_47 ) ) ;
for ( V_48 = 0 ; V_48 < 3 + 100 ; V_48 ++ ) {
V_47 = F_13 ( V_41 , V_49 ) ;
if ( ! ~ V_47 )
return - V_50 ;
if ( ! ( V_47 & V_53 ) )
return 0 ;
if ( V_48 >= 3 )
F_19 ( 1 ) ;
}
F_20 ( L_35 ) ;
return - V_52 ;
}
static int F_23 ( struct V_1 * V_41 , int V_46 ,
int V_54 , int V_55 )
{
int V_56 = F_16 ( V_41 , V_46 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( V_46 == 5 )
V_54 |= V_57 ;
return F_21 ( V_41 , V_46 , ( V_56 & ~ V_54 ) | V_55 ) ;
}
static int F_24 ( struct V_1 * V_41 , int V_58 , int V_46 )
{
int V_56 ;
V_56 = F_23 ( V_41 , 7 , V_59 , V_58 << 5 ) ;
if ( V_56 < 0 )
return V_56 ;
return F_16 ( V_41 , V_46 ) ;
}
static int F_25 ( struct V_2 * V_3 , int V_46 )
{
struct V_1 * V_41 = V_1 ( V_3 ) ;
int V_56 ;
F_26 ( & V_41 -> V_60 ) ;
V_56 = F_16 ( V_41 , V_46 ) ;
F_27 ( & V_41 -> V_60 ) ;
return V_56 ;
}
static int F_28 ( struct V_2 * V_3 , int V_46 ,
int V_54 , int V_55 )
{
struct V_1 * V_41 = V_1 ( V_3 ) ;
int V_56 ;
F_26 ( & V_41 -> V_60 ) ;
V_56 = F_23 ( V_41 , V_46 , V_54 , V_55 ) ;
F_27 ( & V_41 -> V_60 ) ;
return V_56 ;
}
static inline T_2 F_29 ( struct V_61 * V_62 , unsigned int V_48 )
{
return F_30 ( V_62 -> V_63 [ V_48 ] ) ;
}
static void F_31 ( struct V_61 * V_62 , unsigned int V_64 )
{
struct V_65 * V_66 ;
V_66 = & V_62 -> V_67 [ V_64 ] ;
V_66 -> V_68 &= F_32 ( ~ 0xf ) ;
V_66 -> V_69 = F_33 ( V_70 ) ;
V_66 -> V_71 = 0 ;
F_34 () ;
V_66 = & V_62 -> V_67 [ V_62 -> V_72 ] ;
V_66 -> V_68 |= F_32 ( 1 ) ;
V_62 -> V_72 = V_64 ;
F_11 ( V_62 -> V_41 , F_35 ( V_62 -> V_73 ) , V_74 ) ;
}
static void F_36 ( struct V_61 * V_62 )
{
unsigned int V_48 ;
if ( V_62 -> V_75 )
F_37 ( V_62 -> V_75 , V_76 + V_77 ) ;
for ( V_48 = 0 ; V_48 < V_76 ; V_48 ++ )
if ( V_62 -> V_63 [ V_48 ] ) {
F_38 ( V_62 -> V_41 -> V_3 . V_78 ,
F_29 ( V_62 , V_48 ) ,
V_70 , V_79 ) ;
F_39 ( V_62 -> V_63 [ V_48 ] ) ;
}
}
static void F_40 ( struct V_61 * V_62 , const char * V_80 )
{
if ( F_13 ( V_62 -> V_41 , F_41 ( V_62 -> V_73 ) ) & V_81 ) {
F_11 ( V_62 -> V_41 , F_41 ( V_62 -> V_73 ) , V_81 ) ;
F_15 ( V_62 -> V_41 ) ;
F_20 ( L_36 , V_80 ) ;
}
}
static inline unsigned int F_42 ( unsigned int V_64 )
{
return ( V_64 + 1 ) % V_76 ;
}
static inline unsigned int F_43 ( unsigned int V_64 )
{
return ( V_64 - 1 + V_76 ) % V_76 ;
}
static inline unsigned int F_44 ( struct V_61 * V_62 )
{
return F_42 ( V_62 -> V_72 ) ;
}
static unsigned int F_45 ( struct V_61 * V_62 ,
unsigned int * V_82 )
{
unsigned int V_48 , V_83 , V_84 = V_62 -> V_72 ;
T_3 V_69 , V_85 ;
V_48 = F_44 ( V_62 ) ;
V_69 = F_46 ( V_62 -> V_67 [ V_48 ] . V_69 ) ;
while ( V_48 != V_84 && V_69 == 0 ) {
V_83 = F_42 ( V_48 ) ;
F_47 () ;
V_85 = F_46 (
V_62 -> V_67 [ V_83 ] . V_69 ) ;
if ( V_85 == F_33 ( V_70 ) ) {
if ( V_86 > V_70 && V_48 != V_84 ) {
V_83 = F_42 ( V_83 ) ;
F_47 () ;
V_85 = F_46 (
V_62 -> V_67 [ V_83 ] . V_69 ) ;
if ( V_85 != F_33 ( V_70 ) )
goto V_87;
}
break;
}
V_87:
V_48 = V_83 ;
V_69 = V_85 ;
}
F_47 () ;
* V_82 = V_70 - F_48 ( V_69 ) ;
if ( * V_82 > V_70 ) {
* V_82 = 0 ;
F_40 ( V_62 , L_37 ) ;
}
return V_48 ;
}
static void F_49 ( struct V_61 * V_62 ,
unsigned int V_88 ,
unsigned int V_89 )
{
unsigned int V_48 ;
V_48 = F_44 ( V_62 ) ;
while ( V_48 != V_88 ) {
F_50 ( V_62 -> V_41 -> V_3 . V_78 ,
F_29 ( V_62 , V_48 ) ,
V_70 , V_79 ) ;
V_48 = F_42 ( V_48 ) ;
}
if ( V_89 > 0 )
F_50 ( V_62 -> V_41 -> V_3 . V_78 ,
F_29 ( V_62 , V_48 ) ,
V_89 , V_79 ) ;
}
static T_4 * F_51 ( struct V_61 * V_62 , T_4 * V_75 )
{
struct V_1 * V_41 = V_62 -> V_41 ;
struct V_90 V_91 ;
T_1 V_92 , V_93 , V_33 ;
int V_4 ;
V_91 . V_32 [ 0 ] = F_52 ( V_75 [ 0 ] ) ;
V_91 . V_32 [ 1 ] = F_52 ( V_75 [ 1 ] ) ;
V_91 . V_32 [ 2 ] = F_52 ( V_75 [ 2 ] ) ;
V_33 = ( V_91 . V_32 [ 0 ] >> 4 ) & 0x0f ;
switch ( V_33 ) {
case V_94 :
case V_95 :
V_91 . V_32 [ 3 ] = ( V_38 V_96 ) V_75 [ 3 ] ;
V_91 . V_97 = 16 ;
V_91 . V_98 = 0 ;
break;
case V_99 :
V_91 . V_32 [ 3 ] = F_52 ( V_75 [ 3 ] ) ;
V_91 . V_97 = 16 ;
V_91 . V_98 = 0 ;
break;
case V_100 :
case V_101 :
case V_102 :
case V_103 :
V_91 . V_32 [ 3 ] = F_52 ( V_75 [ 3 ] ) ;
V_91 . V_97 = 16 ;
V_91 . V_98 = V_91 . V_32 [ 3 ] >> 16 ;
if ( V_91 . V_98 > V_104 ) {
F_40 ( V_62 , L_38 ) ;
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
F_40 ( V_62 , L_39 ) ;
return NULL ;
}
V_91 . V_108 = ( void * ) V_75 + V_91 . V_97 ;
V_93 = ( V_91 . V_97 + V_91 . V_98 + 3 ) / 4 ;
V_92 = F_52 ( V_75 [ V_93 ] ) ;
V_4 = ( V_92 >> 16 ) & 0x1f ;
V_91 . V_109 = V_4 - 16 ;
V_91 . V_29 = ( V_92 >> 21 ) & 0x7 ;
V_91 . V_110 = V_92 & 0xffff ;
V_91 . V_26 = V_41 -> V_111 ;
F_7 ( 'R' , V_91 . V_29 , V_91 . V_32 , V_4 ) ;
if ( V_4 == V_112 &&
( V_91 . V_32 [ 0 ] & 0xff ) == ( V_113 << 4 ) )
V_91 . V_109 = V_114 ;
if ( V_4 == V_37 ) {
if ( ! ( V_41 -> V_115 & V_116 ) )
V_41 -> V_111 = ( V_91 . V_32 [ 2 ] >> 16 ) & 0xff ;
} else if ( V_62 == & V_41 -> V_117 ) {
F_53 ( & V_41 -> V_3 , & V_91 ) ;
} else {
F_54 ( & V_41 -> V_3 , & V_91 ) ;
}
return V_75 + V_93 + 1 ;
}
static void * F_55 ( struct V_61 * V_62 , void * V_91 , void * V_118 )
{
void * V_119 ;
while ( V_91 < V_118 ) {
V_119 = F_51 ( V_62 , V_91 ) ;
if ( ! V_119 )
return V_91 ;
V_91 = V_119 ;
}
return V_91 ;
}
static void F_56 ( struct V_61 * V_62 , unsigned int V_120 )
{
unsigned int V_48 ;
V_48 = F_44 ( V_62 ) ;
while ( V_48 != V_120 ) {
F_57 ( V_62 -> V_41 -> V_3 . V_78 ,
F_29 ( V_62 , V_48 ) ,
V_70 , V_79 ) ;
F_31 ( V_62 , V_48 ) ;
V_48 = F_42 ( V_48 ) ;
}
}
static void F_58 ( unsigned long V_43 )
{
struct V_61 * V_62 = (struct V_61 * ) V_43 ;
unsigned int V_88 , V_89 ;
void * V_91 , * V_118 ;
V_91 = V_62 -> V_121 ;
if ( ! V_91 )
return;
V_88 = F_45 ( V_62 ,
& V_89 ) ;
F_49 ( V_62 , V_88 , V_89 ) ;
V_118 = V_62 -> V_75 + V_88 * V_70 + V_89 ;
if ( V_88 < F_44 ( V_62 ) ) {
void * V_122 = V_62 -> V_75 + V_76 * V_70 ;
V_91 = F_55 ( V_62 , V_91 , V_122 ) ;
if ( V_91 < V_122 )
goto error;
V_91 -= V_76 * V_70 ;
}
V_91 = F_55 ( V_62 , V_91 , V_118 ) ;
if ( V_91 != V_118 ) {
if ( V_91 > V_118 )
F_40 ( V_62 , L_40 ) ;
goto error;
}
V_62 -> V_121 = V_91 ;
F_56 ( V_62 , V_88 ) ;
return;
error:
V_62 -> V_121 = NULL ;
}
static int F_59 ( struct V_61 * V_62 , struct V_1 * V_41 ,
unsigned int V_123 , T_1 V_73 )
{
unsigned int V_48 ;
T_2 V_124 ;
struct V_58 * V_63 [ V_76 + V_77 ] ;
struct V_65 * V_66 ;
V_62 -> V_73 = V_73 ;
V_62 -> V_41 = V_41 ;
F_60 ( & V_62 -> V_125 , F_58 , ( unsigned long ) V_62 ) ;
for ( V_48 = 0 ; V_48 < V_76 ; V_48 ++ ) {
V_62 -> V_63 [ V_48 ] = F_61 ( V_126 | V_127 ) ;
if ( ! V_62 -> V_63 [ V_48 ] )
goto V_128;
V_124 = F_62 ( V_41 -> V_3 . V_78 , V_62 -> V_63 [ V_48 ] ,
0 , V_70 , V_79 ) ;
if ( F_63 ( V_41 -> V_3 . V_78 , V_124 ) ) {
F_39 ( V_62 -> V_63 [ V_48 ] ) ;
V_62 -> V_63 [ V_48 ] = NULL ;
goto V_128;
}
F_64 ( V_62 -> V_63 [ V_48 ] , V_124 ) ;
}
for ( V_48 = 0 ; V_48 < V_76 ; V_48 ++ )
V_63 [ V_48 ] = V_62 -> V_63 [ V_48 ] ;
for ( V_48 = 0 ; V_48 < V_77 ; V_48 ++ )
V_63 [ V_76 + V_48 ] = V_62 -> V_63 [ V_48 ] ;
V_62 -> V_75 = F_65 ( V_63 , V_76 + V_77 ,
- 1 , V_129 ) ;
if ( ! V_62 -> V_75 )
goto V_128;
V_62 -> V_67 = V_41 -> V_130 + V_123 ;
V_62 -> V_131 = V_41 -> V_132 + V_123 ;
for ( V_48 = 0 ; V_48 < V_76 ; V_48 ++ ) {
V_66 = & V_62 -> V_67 [ V_48 ] ;
V_66 -> V_133 = F_33 ( V_70 ) ;
V_66 -> V_134 = F_33 ( V_135 |
V_136 |
V_137 ) ;
V_66 -> V_138 = F_32 ( F_29 ( V_62 , V_48 ) ) ;
V_66 -> V_68 = F_32 ( V_62 -> V_131 +
F_42 ( V_48 ) * sizeof( struct V_65 ) ) ;
}
return 0 ;
V_128:
F_36 ( V_62 ) ;
return - V_139 ;
}
static void F_66 ( struct V_61 * V_62 )
{
unsigned int V_48 ;
for ( V_48 = 0 ; V_48 < V_76 ; V_48 ++ )
F_31 ( V_62 , V_48 ) ;
V_62 -> V_121 = V_62 -> V_75 ;
F_11 ( V_62 -> V_41 , F_67 ( V_62 -> V_73 ) , V_62 -> V_131 | 1 ) ;
F_11 ( V_62 -> V_41 , F_35 ( V_62 -> V_73 ) , V_81 ) ;
}
static struct V_65 * F_68 ( struct V_65 * V_66 , int V_140 )
{
T_3 V_141 ;
V_141 = V_66 -> V_134 & F_33 ( V_137 ) ;
if ( V_140 == 2 && V_141 == F_33 ( V_137 ) )
return V_66 ;
else
return V_66 + V_140 - 1 ;
}
static void F_69 ( unsigned long V_43 )
{
struct V_142 * V_62 = (struct V_142 * ) V_43 ;
struct V_65 * V_66 , * V_84 ;
T_1 V_143 ;
int V_140 ;
struct V_144 * V_145 ;
V_145 = F_70 ( V_62 -> V_146 . V_119 ,
struct V_144 , V_147 ) ;
V_84 = V_62 -> V_84 ;
while ( V_84 -> V_68 != 0 ) {
struct V_144 * V_148 = V_145 ;
V_143 = F_71 ( V_84 -> V_68 ) ;
V_140 = V_143 & 0xf ;
V_143 &= ~ 0xf ;
V_62 -> V_149 = V_143 ;
if ( V_143 < V_145 -> V_150 ||
V_143 >= V_145 -> V_150 + V_145 -> V_151 )
V_145 = F_70 ( V_145 -> V_147 . V_119 ,
struct V_144 , V_147 ) ;
V_66 = V_145 -> V_75 + ( V_143 - V_145 -> V_150 ) / sizeof( * V_66 ) ;
V_84 = F_68 ( V_66 , V_140 ) ;
if ( ! V_62 -> V_152 ( V_62 , V_66 , V_84 ) )
break;
if ( V_148 != V_145 ) {
unsigned long V_153 ;
V_148 -> V_151 = 0 ;
F_72 ( & V_62 -> V_41 -> V_154 , V_153 ) ;
F_73 ( & V_148 -> V_147 , & V_62 -> V_146 ) ;
F_74 ( & V_62 -> V_41 -> V_154 , V_153 ) ;
}
V_62 -> V_84 = V_84 ;
}
}
static int F_75 ( struct V_142 * V_62 )
{
struct V_144 * V_145 ;
T_2 V_155 ( V_156 ) ;
int V_42 ;
if ( V_62 -> V_157 >= 16 * 1024 * 1024 )
return - V_139 ;
V_145 = F_76 ( V_62 -> V_41 -> V_3 . V_78 , V_70 ,
& V_156 , V_158 ) ;
if ( ! V_145 )
return - V_139 ;
V_42 = ( void * ) & V_145 -> V_75 - ( void * ) V_145 ;
V_145 -> V_159 = V_70 - V_42 ;
V_145 -> V_150 = V_156 + V_42 ;
V_145 -> V_151 = 0 ;
F_77 ( & V_145 -> V_147 , & V_62 -> V_146 ) ;
V_62 -> V_157 += V_70 ;
return 0 ;
}
static int F_78 ( struct V_142 * V_62 , struct V_1 * V_41 ,
T_1 V_73 , T_5 V_152 )
{
V_62 -> V_41 = V_41 ;
V_62 -> V_73 = V_73 ;
V_62 -> V_157 = 0 ;
F_79 ( & V_62 -> V_146 ) ;
if ( F_75 ( V_62 ) < 0 )
return - V_139 ;
V_62 -> V_160 = F_70 ( V_62 -> V_146 . V_119 ,
struct V_144 , V_147 ) ;
F_60 ( & V_62 -> V_125 , F_69 , ( unsigned long ) V_62 ) ;
V_62 -> V_152 = V_152 ;
memset ( V_62 -> V_160 -> V_75 , 0 , sizeof( * V_62 -> V_160 -> V_75 ) ) ;
V_62 -> V_160 -> V_75 -> V_134 = F_33 ( V_161 ) ;
V_62 -> V_160 -> V_75 -> V_71 = F_33 ( 0x8011 ) ;
V_62 -> V_160 -> V_151 += sizeof( * V_62 -> V_160 -> V_75 ) ;
V_62 -> V_84 = V_62 -> V_160 -> V_75 ;
V_62 -> V_162 = V_62 -> V_160 -> V_75 ;
return 0 ;
}
static void F_80 ( struct V_142 * V_62 )
{
struct V_2 * V_3 = & V_62 -> V_41 -> V_3 ;
struct V_144 * V_145 , * V_163 ;
F_81 (desc, tmp, &ctx->buffer_list, list)
F_82 ( V_3 -> V_78 , V_70 , V_145 ,
V_145 -> V_150 -
( ( void * ) & V_145 -> V_75 - ( void * ) V_145 ) ) ;
}
static struct V_65 * F_83 ( struct V_142 * V_62 ,
int V_140 , T_2 * V_164 )
{
struct V_65 * V_66 = NULL ;
struct V_144 * V_145 = V_62 -> V_160 ;
if ( V_140 * sizeof( * V_66 ) > V_145 -> V_159 )
return NULL ;
if ( V_140 * sizeof( * V_66 ) > V_145 -> V_159 - V_145 -> V_151 ) {
if ( V_145 -> V_147 . V_119 == & V_62 -> V_146 ) {
if ( F_75 ( V_62 ) < 0 )
return NULL ;
}
V_145 = F_70 ( V_145 -> V_147 . V_119 ,
struct V_144 , V_147 ) ;
V_62 -> V_160 = V_145 ;
}
V_66 = V_145 -> V_75 + V_145 -> V_151 / sizeof( * V_66 ) ;
memset ( V_66 , 0 , V_140 * sizeof( * V_66 ) ) ;
* V_164 = V_145 -> V_150 + V_145 -> V_151 ;
return V_66 ;
}
static void F_84 ( struct V_142 * V_62 , T_1 V_165 )
{
struct V_1 * V_41 = V_62 -> V_41 ;
F_11 ( V_41 , F_67 ( V_62 -> V_73 ) ,
F_71 ( V_62 -> V_84 -> V_68 ) ) ;
F_11 ( V_41 , F_41 ( V_62 -> V_73 ) , ~ 0 ) ;
F_11 ( V_41 , F_35 ( V_62 -> V_73 ) , V_81 | V_165 ) ;
V_62 -> V_166 = true ;
F_15 ( V_41 ) ;
}
static void F_85 ( struct V_142 * V_62 ,
struct V_65 * V_66 , int V_140 , int V_165 )
{
T_2 V_164 ;
struct V_144 * V_145 = V_62 -> V_160 ;
V_164 = V_145 -> V_150 + ( V_66 - V_145 -> V_75 ) * sizeof( * V_66 ) ;
V_145 -> V_151 += ( V_140 + V_165 ) * sizeof( * V_66 ) ;
F_34 () ;
V_62 -> V_162 -> V_68 = F_32 ( V_164 | V_140 ) ;
V_62 -> V_162 = F_68 ( V_66 , V_140 ) ;
}
static void F_86 ( struct V_142 * V_62 )
{
T_1 V_167 ;
int V_48 ;
F_11 ( V_62 -> V_41 , F_41 ( V_62 -> V_73 ) , V_81 ) ;
V_62 -> V_166 = false ;
for ( V_48 = 0 ; V_48 < 1000 ; V_48 ++ ) {
V_167 = F_13 ( V_62 -> V_41 , F_35 ( V_62 -> V_73 ) ) ;
if ( ( V_167 & V_168 ) == 0 )
return;
if ( V_48 )
F_87 ( 10 ) ;
}
F_20 ( L_41 , V_167 ) ;
}
static int F_88 ( struct V_142 * V_62 ,
struct V_90 * V_169 )
{
struct V_1 * V_41 = V_62 -> V_41 ;
T_2 V_164 , V_155 ( V_170 ) ;
struct V_171 * V_171 ;
struct V_65 * V_66 , * V_84 ;
T_4 * V_32 ;
int V_140 , V_33 ;
V_66 = F_83 ( V_62 , 4 , & V_164 ) ;
if ( V_66 == NULL ) {
V_169 -> V_109 = V_172 ;
return - 1 ;
}
V_66 [ 0 ] . V_134 = F_33 ( V_173 ) ;
V_66 [ 0 ] . V_69 = F_33 ( V_169 -> V_110 ) ;
V_33 = ( V_169 -> V_32 [ 0 ] >> 4 ) & 0x0f ;
V_32 = ( T_4 * ) & V_66 [ 1 ] ;
switch ( V_33 ) {
case V_94 :
case V_100 :
case V_105 :
case V_106 :
case V_99 :
case V_95 :
case V_101 :
case V_102 :
case V_103 :
V_32 [ 0 ] = F_32 ( ( V_169 -> V_32 [ 0 ] & 0xffff ) |
( V_169 -> V_29 << 16 ) ) ;
V_32 [ 1 ] = F_32 ( ( V_169 -> V_32 [ 1 ] & 0xffff ) |
( V_169 -> V_32 [ 0 ] & 0xffff0000 ) ) ;
V_32 [ 2 ] = F_32 ( V_169 -> V_32 [ 2 ] ) ;
if ( F_89 ( V_33 ) )
V_32 [ 3 ] = F_32 ( V_169 -> V_32 [ 3 ] ) ;
else
V_32 [ 3 ] = ( V_38 T_4 ) V_169 -> V_32 [ 3 ] ;
V_66 [ 0 ] . V_133 = F_33 ( V_169 -> V_97 ) ;
break;
case V_174 :
V_32 [ 0 ] = F_32 ( ( V_113 << 4 ) |
( V_169 -> V_29 << 16 ) ) ;
V_32 [ 1 ] = F_32 ( V_169 -> V_32 [ 1 ] ) ;
V_32 [ 2 ] = F_32 ( V_169 -> V_32 [ 2 ] ) ;
V_66 [ 0 ] . V_133 = F_33 ( 12 ) ;
if ( F_90 ( & V_169 -> V_32 [ 1 ] ) )
V_66 [ 0 ] . V_134 |= F_33 ( V_175 ) ;
break;
case V_176 :
V_32 [ 0 ] = F_32 ( ( V_169 -> V_32 [ 0 ] & 0xffff ) |
( V_169 -> V_29 << 16 ) ) ;
V_32 [ 1 ] = F_32 ( V_169 -> V_32 [ 0 ] & 0xffff0000 ) ;
V_66 [ 0 ] . V_133 = F_33 ( 8 ) ;
break;
default:
V_169 -> V_109 = V_172 ;
return - 1 ;
}
F_91 ( sizeof( struct V_171 ) > sizeof( struct V_65 ) ) ;
V_171 = (struct V_171 * ) & V_66 [ 3 ] ;
V_171 -> V_169 = V_169 ;
V_169 -> V_171 = V_171 ;
if ( V_169 -> V_98 > 0 ) {
if ( V_169 -> V_98 > sizeof( V_171 -> V_177 ) ) {
V_170 = F_92 ( V_41 -> V_3 . V_78 ,
V_169 -> V_108 ,
V_169 -> V_98 ,
V_178 ) ;
if ( F_63 ( V_41 -> V_3 . V_78 , V_170 ) ) {
V_169 -> V_109 = V_172 ;
return - 1 ;
}
V_169 -> V_170 = V_170 ;
V_169 -> V_179 = true ;
} else {
memcpy ( V_171 -> V_177 , V_169 -> V_108 ,
V_169 -> V_98 ) ;
V_170 = V_164 + 3 * sizeof( * V_66 ) ;
}
V_66 [ 2 ] . V_133 = F_33 ( V_169 -> V_98 ) ;
V_66 [ 2 ] . V_138 = F_32 ( V_170 ) ;
V_84 = & V_66 [ 2 ] ;
V_140 = 3 ;
} else {
V_84 = & V_66 [ 0 ] ;
V_140 = 2 ;
}
V_84 -> V_134 |= F_33 ( V_161 |
V_180 |
V_137 ) ;
if ( V_41 -> V_26 != V_169 -> V_26 ) {
if ( V_169 -> V_179 )
F_93 ( V_41 -> V_3 . V_78 , V_170 ,
V_169 -> V_98 , V_178 ) ;
V_169 -> V_109 = V_181 ;
return - 1 ;
}
F_85 ( V_62 , V_66 , V_140 , 4 - V_140 ) ;
if ( V_62 -> V_166 )
F_11 ( V_41 , F_35 ( V_62 -> V_73 ) , V_74 ) ;
else
F_84 ( V_62 , 0 ) ;
return 0 ;
}
static void F_94 ( struct V_142 * V_62 )
{
F_95 ( & V_62 -> V_125 ) ;
V_62 -> V_182 = true ;
F_69 ( ( unsigned long ) V_62 ) ;
V_62 -> V_182 = false ;
F_96 ( & V_62 -> V_125 ) ;
}
static int F_97 ( struct V_142 * V_142 ,
struct V_65 * V_66 ,
struct V_65 * V_84 )
{
struct V_171 * V_171 ;
struct V_90 * V_169 ;
struct V_1 * V_41 = V_142 -> V_41 ;
int V_4 ;
if ( V_84 -> V_71 == 0 && ! V_142 -> V_182 )
return 0 ;
V_171 = (struct V_171 * ) & V_66 [ 3 ] ;
V_169 = V_171 -> V_169 ;
if ( V_169 == NULL )
return 1 ;
if ( V_169 -> V_179 )
F_93 ( V_41 -> V_3 . V_78 , V_169 -> V_170 ,
V_169 -> V_98 , V_178 ) ;
V_4 = F_48 ( V_84 -> V_71 ) & 0x1f ;
V_169 -> V_110 = F_48 ( V_84 -> V_69 ) ;
F_7 ( 'T' , V_169 -> V_29 , V_169 -> V_32 , V_4 ) ;
switch ( V_4 ) {
case V_183 :
V_169 -> V_109 = V_184 ;
break;
case V_185 :
V_169 -> V_109 = V_181 ;
break;
case V_186 :
if ( V_142 -> V_182 )
V_169 -> V_109 = V_181 ;
else {
V_169 -> V_109 = V_187 ;
}
break;
case V_114 + 0x10 :
case V_188 + 0x10 :
case V_189 + 0x10 :
case V_190 + 0x10 :
case V_191 + 0x10 :
case V_192 + 0x10 :
case V_193 + 0x10 :
V_169 -> V_109 = V_4 - 0x10 ;
break;
case V_112 :
if ( V_142 -> V_182 ) {
V_169 -> V_109 = V_181 ;
break;
}
default:
V_169 -> V_109 = V_172 ;
break;
}
V_169 -> V_152 ( V_169 , & V_41 -> V_3 , V_169 -> V_109 ) ;
return 1 ;
}
static void F_98 ( struct V_1 * V_41 ,
struct V_90 * V_169 , T_1 V_194 )
{
struct V_90 V_195 ;
int V_33 , V_93 , V_48 ;
V_33 = F_99 ( V_169 -> V_32 [ 0 ] ) ;
if ( F_89 ( V_33 ) )
V_93 = F_100 ( V_169 -> V_32 [ 3 ] ) ;
else
V_93 = 4 ;
V_48 = V_194 - V_196 ;
if ( V_48 + V_93 > V_197 ) {
F_101 ( & V_195 , V_169 -> V_32 ,
V_198 , NULL , 0 ) ;
} else if ( ! F_102 ( V_33 ) ) {
F_101 ( & V_195 , V_169 -> V_32 ,
V_199 , NULL , 0 ) ;
} else {
F_101 ( & V_195 , V_169 -> V_32 , V_200 ,
( void * ) V_41 -> V_201 + V_48 , V_93 ) ;
}
F_54 ( & V_41 -> V_3 , & V_195 ) ;
}
static void F_103 ( struct V_1 * V_41 ,
struct V_90 * V_169 , T_1 V_194 )
{
struct V_90 V_195 ;
int V_33 , V_93 , V_202 , V_203 , V_204 ;
V_39 * V_108 , V_205 ;
T_1 V_206 , V_207 ;
V_33 = F_99 ( V_169 -> V_32 [ 0 ] ) ;
V_93 = F_100 ( V_169 -> V_32 [ 3 ] ) ;
V_108 = V_169 -> V_108 ;
V_202 = F_104 ( V_169 -> V_32 [ 3 ] ) ;
if ( V_33 == V_102 &&
V_202 == V_208 && V_93 == 8 ) {
V_206 = F_10 ( V_108 [ 0 ] ) ;
V_207 = F_10 ( V_108 [ 1 ] ) ;
} else if ( V_33 == V_106 ) {
V_206 = 0 ;
V_207 = 0 ;
} else {
F_101 ( & V_195 , V_169 -> V_32 ,
V_199 , NULL , 0 ) ;
goto V_209;
}
V_203 = ( V_194 - V_210 ) / 4 ;
F_11 ( V_41 , V_211 , V_207 ) ;
F_11 ( V_41 , V_212 , V_206 ) ;
F_11 ( V_41 , V_213 , V_203 ) ;
for ( V_204 = 0 ; V_204 < 20 ; V_204 ++ )
if ( F_13 ( V_41 , V_213 ) & 0x80000000 ) {
V_205 = F_105 ( F_13 ( V_41 ,
V_211 ) ) ;
F_101 ( & V_195 , V_169 -> V_32 ,
V_200 ,
& V_205 , sizeof( V_205 ) ) ;
goto V_209;
}
F_20 ( L_42 ) ;
F_101 ( & V_195 , V_169 -> V_32 , V_214 , NULL , 0 ) ;
V_209:
F_54 ( & V_41 -> V_3 , & V_195 ) ;
}
static void F_106 ( struct V_142 * V_62 , struct V_90 * V_169 )
{
T_6 V_42 , V_194 ;
if ( V_62 == & V_62 -> V_41 -> V_215 ) {
V_169 -> V_109 = V_188 ;
V_169 -> V_152 ( V_169 , & V_62 -> V_41 -> V_3 , V_169 -> V_109 ) ;
}
V_42 =
( ( unsigned long long )
F_107 ( V_169 -> V_32 [ 1 ] ) << 32 ) |
V_169 -> V_32 [ 2 ] ;
V_194 = V_42 - V_216 ;
if ( V_194 >= V_196 && V_194 < V_217 )
F_98 ( V_62 -> V_41 , V_169 , V_194 ) ;
else switch ( V_194 ) {
case V_210 :
case V_218 :
case V_219 :
case V_220 :
F_103 ( V_62 -> V_41 , V_169 , V_194 ) ;
break;
default:
if ( V_62 == & V_62 -> V_41 -> V_215 )
F_53 ( & V_62 -> V_41 -> V_3 , V_169 ) ;
else
F_54 ( & V_62 -> V_41 -> V_3 , V_169 ) ;
break;
}
if ( V_62 == & V_62 -> V_41 -> V_221 ) {
V_169 -> V_109 = V_114 ;
V_169 -> V_152 ( V_169 , & V_62 -> V_41 -> V_3 , V_169 -> V_109 ) ;
}
}
static void F_108 ( struct V_142 * V_62 , struct V_90 * V_169 )
{
unsigned long V_153 ;
int V_56 ;
F_72 ( & V_62 -> V_41 -> V_154 , V_153 ) ;
if ( F_109 ( V_169 -> V_32 [ 0 ] ) == V_62 -> V_41 -> V_25 &&
V_62 -> V_41 -> V_26 == V_169 -> V_26 ) {
F_74 ( & V_62 -> V_41 -> V_154 , V_153 ) ;
F_106 ( V_62 , V_169 ) ;
return;
}
V_56 = F_88 ( V_62 , V_169 ) ;
F_74 ( & V_62 -> V_41 -> V_154 , V_153 ) ;
if ( V_56 < 0 )
V_169 -> V_152 ( V_169 , & V_62 -> V_41 -> V_3 , V_169 -> V_109 ) ;
}
static void F_110 ( struct V_1 * V_41 ,
const char * V_222 , unsigned int V_73 )
{
T_1 V_223 ;
V_223 = F_13 ( V_41 , F_35 ( V_73 ) ) ;
if ( V_223 & V_224 ) {
#ifdef F_111
F_20 ( L_43 ,
V_222 , V_36 [ V_223 & 0x1f ] ) ;
#else
F_20 ( L_44 ,
V_222 , V_223 & 0x1f ) ;
#endif
}
}
static void F_112 ( struct V_1 * V_41 )
{
unsigned int V_48 ;
char V_222 [ 8 ] ;
F_110 ( V_41 , L_45 , V_225 ) ;
F_110 ( V_41 , L_46 , V_226 ) ;
F_110 ( V_41 , L_47 , V_227 ) ;
F_110 ( V_41 , L_48 , V_228 ) ;
for ( V_48 = 0 ; V_48 < 32 ; ++ V_48 ) {
if ( ! ( V_41 -> V_229 & ( 1 << V_48 ) ) )
continue;
sprintf ( V_222 , L_49 , V_48 ) ;
F_110 ( V_41 , V_222 , F_113 ( V_48 ) ) ;
}
for ( V_48 = 0 ; V_48 < 32 ; ++ V_48 ) {
if ( ! ( V_41 -> V_230 & ( 1 << V_48 ) ) )
continue;
sprintf ( V_222 , L_50 , V_48 ) ;
F_110 ( V_41 , V_222 , F_114 ( V_48 ) ) ;
}
}
static T_1 F_115 ( T_1 V_231 )
{
T_1 V_232 ;
V_232 = V_231 & 0xfff ;
V_232 += 3072 * ( ( V_231 >> 12 ) & 0x1fff ) ;
V_232 += ( 3072 * 8000 ) * ( V_231 >> 25 ) ;
return V_232 ;
}
static T_1 F_116 ( struct V_1 * V_41 )
{
T_1 V_233 , V_234 , V_235 ;
T_1 V_236 , V_237 , V_238 ;
T_7 V_239 , V_240 ;
int V_48 ;
V_235 = F_13 ( V_41 , V_241 ) ;
if ( V_41 -> V_115 & V_242 ) {
V_48 = 0 ;
V_234 = V_235 ;
V_235 = F_13 ( V_41 , V_241 ) ;
do {
V_233 = V_234 ;
V_234 = V_235 ;
V_235 = F_13 ( V_41 , V_241 ) ;
V_236 = F_115 ( V_233 ) ;
V_237 = F_115 ( V_234 ) ;
V_238 = F_115 ( V_235 ) ;
V_239 = V_237 - V_236 ;
V_240 = V_238 - V_237 ;
} while ( ( V_239 <= 0 || V_240 <= 0 ||
V_239 / V_240 >= 2 || V_240 / V_239 >= 2 )
&& V_48 ++ < 20 );
}
return V_235 ;
}
static T_1 F_117 ( struct V_1 * V_41 )
{
T_1 V_243 = F_116 ( V_41 ) >> 25 ;
if ( ( V_41 -> V_244 & 0x40 ) != ( V_243 & 0x40 ) )
V_41 -> V_244 += 0x40 ;
return V_41 -> V_244 | V_243 ;
}
static int F_118 ( struct V_1 * V_41 , int V_245 )
{
int V_167 ;
F_26 ( & V_41 -> V_60 ) ;
V_167 = F_21 ( V_41 , 7 , V_245 ) ;
if ( V_167 >= 0 )
V_167 = F_16 ( V_41 , 8 ) ;
F_27 ( & V_41 -> V_60 ) ;
if ( V_167 < 0 )
return V_167 ;
switch ( V_167 & 0x0f ) {
case 0x06 :
return 2 ;
case 0x0e :
return 3 ;
}
return 1 ;
}
static int F_119 ( struct V_1 * V_41 , T_1 V_246 ,
int V_27 )
{
int V_48 ;
T_1 V_247 ;
for ( V_48 = 0 ; V_48 < V_27 ; V_48 ++ ) {
V_247 = V_41 -> V_248 [ V_48 ] ;
if ( ( V_246 & 0xff000000 ) == ( V_247 & 0xff000000 ) )
return - 1 ;
if ( ( V_246 & 0xff000000 ) < ( V_247 & 0xff000000 ) )
return V_48 ;
}
return V_48 ;
}
static int F_120 ( struct V_1 * V_41 , int V_27 )
{
int V_167 , V_48 , V_249 , V_92 ;
T_1 V_246 = 0x8040c800 ;
V_167 = F_13 ( V_41 , V_250 ) ;
if ( ! ( V_167 & V_251 ) ) {
F_4 ( L_51 ) ;
return - V_52 ;
}
V_246 |= ( ( V_167 & 0x3f ) << 24 ) ;
V_167 = F_25 ( & V_41 -> V_3 , 4 ) ;
if ( V_167 < 0 )
return V_167 ;
V_246 |= ( ( V_167 & 0x07 ) << 8 ) ;
V_167 = F_25 ( & V_41 -> V_3 , 1 ) ;
if ( V_167 < 0 )
return V_167 ;
V_246 |= ( ( V_167 & 0x3f ) << 16 ) ;
for ( V_48 = 0 ; V_48 < 3 ; V_48 ++ ) {
V_92 = F_118 ( V_41 , V_48 ) ;
if ( V_92 < 0 )
return V_92 ;
V_246 |= ( ( V_92 & 0x3 ) << ( 6 - ( V_48 * 2 ) ) ) ;
}
V_249 = F_119 ( V_41 , V_246 , V_27 ) ;
if ( V_249 >= 0 ) {
memmove ( & ( V_41 -> V_248 [ V_249 + 1 ] ) ,
& ( V_41 -> V_248 [ V_249 ] ) ,
( V_27 - V_249 ) * sizeof( * V_41 -> V_248 ) ) ;
V_41 -> V_248 [ V_249 ] = V_246 ;
V_27 ++ ;
}
return V_27 ;
}
static void F_121 ( struct V_252 * V_253 )
{
struct V_1 * V_41 =
F_1 ( V_253 , struct V_1 , F_121 ) ;
int V_27 , V_48 , V_254 , V_167 ;
int V_26 , V_255 ;
unsigned long V_153 ;
void * V_256 = NULL ;
T_2 V_257 = 0 ;
bool V_258 ;
V_167 = F_13 ( V_41 , V_250 ) ;
if ( ! ( V_167 & V_251 ) ) {
F_4 ( L_51 ) ;
return;
}
if ( ( V_167 & V_259 ) == 63 ) {
F_4 ( L_52 ) ;
return;
}
V_41 -> V_25 = V_167 & ( V_260 |
V_259 ) ;
V_258 = ( V_167 & V_261 ) != 0 ;
if ( ! ( V_41 -> V_262 && V_258 ) )
F_11 ( V_41 , V_263 ,
V_264 ) ;
V_41 -> V_262 = V_258 ;
V_167 = F_13 ( V_41 , V_265 ) ;
if ( V_167 & V_266 ) {
F_4 ( L_53 ) ;
return;
}
V_27 = ( V_167 >> 3 ) & 0xff ;
if ( V_27 > 252 ) {
F_4 ( L_53 ) ;
return;
}
V_26 = ( F_52 ( V_41 -> V_267 [ 0 ] ) >> 16 ) & 0xff ;
F_47 () ;
for ( V_48 = 1 , V_254 = 0 ; V_254 < V_27 ; V_48 += 2 , V_254 ++ ) {
if ( V_41 -> V_267 [ V_48 ] != ~ V_41 -> V_267 [ V_48 + 1 ] ) {
if ( F_52 ( V_41 -> V_267 [ V_48 ] )
== 0xffff008f ) {
F_4 ( L_54 ) ;
V_27 = V_254 ;
break;
} else {
F_4 ( L_53 ) ;
return;
}
}
V_41 -> V_248 [ V_254 ] =
F_52 ( V_41 -> V_267 [ V_48 ] ) ;
}
if ( V_41 -> V_115 & V_268 ) {
V_27 = F_120 ( V_41 , V_27 ) ;
if ( V_27 < 0 ) {
F_4 ( L_55 ) ;
return;
}
}
if ( V_27 == 0 ) {
F_4 ( L_53 ) ;
return;
}
F_47 () ;
V_255 = ( F_13 ( V_41 , V_265 ) >> 16 ) & 0xff ;
if ( V_255 != V_26 ) {
F_4 ( L_56
L_57 ) ;
return;
}
F_72 ( & V_41 -> V_154 , V_153 ) ;
V_41 -> V_26 = - 1 ;
F_86 ( & V_41 -> V_215 ) ;
F_86 ( & V_41 -> V_221 ) ;
F_74 ( & V_41 -> V_154 , V_153 ) ;
F_94 ( & V_41 -> V_215 ) ;
F_94 ( & V_41 -> V_221 ) ;
F_72 ( & V_41 -> V_154 , V_153 ) ;
V_41 -> V_26 = V_26 ;
F_11 ( V_41 , V_269 , V_8 ) ;
if ( V_41 -> V_115 & V_116 )
V_41 -> V_111 = V_26 ;
if ( V_41 -> V_270 != NULL ) {
if ( V_41 -> V_270 != V_41 -> V_201 ) {
V_256 = V_41 -> V_201 ;
V_257 = V_41 -> V_271 ;
}
V_41 -> V_201 = V_41 -> V_270 ;
V_41 -> V_271 = V_41 -> V_272 ;
V_41 -> V_270 = NULL ;
F_11 ( V_41 , V_273 ,
F_10 ( V_41 -> V_201 [ 2 ] ) ) ;
V_41 -> V_201 [ 0 ] = V_41 -> V_274 ;
F_11 ( V_41 , V_275 ,
F_10 ( V_41 -> V_274 ) ) ;
}
#ifdef F_122
F_11 ( V_41 , V_276 , ~ 0 ) ;
F_11 ( V_41 , V_277 , ~ 0 ) ;
#endif
F_74 ( & V_41 -> V_154 , V_153 ) ;
if ( V_256 )
F_82 ( V_41 -> V_3 . V_78 , V_197 ,
V_256 , V_257 ) ;
F_6 ( V_41 -> V_25 , V_26 ,
V_27 , V_41 -> V_248 ) ;
F_123 ( & V_41 -> V_3 , V_41 -> V_25 , V_26 ,
V_27 , V_41 -> V_248 ,
V_41 -> V_278 ) ;
V_41 -> V_278 = false ;
}
static T_8 F_124 ( int V_279 , void * V_43 )
{
struct V_1 * V_41 = V_43 ;
T_1 V_280 , V_281 ;
int V_48 ;
V_280 = F_13 ( V_41 , V_269 ) ;
if ( ! V_280 || ! ~ V_280 )
return V_282 ;
F_11 ( V_41 , V_269 ,
V_280 & ~ ( V_8 | V_16 ) ) ;
F_2 ( V_280 ) ;
if ( V_280 & V_9 )
F_125 ( V_283 , & V_41 -> F_121 ) ;
if ( V_280 & V_10 )
F_126 ( & V_41 -> V_117 . V_125 ) ;
if ( V_280 & V_11 )
F_126 ( & V_41 -> V_284 . V_125 ) ;
if ( V_280 & V_12 )
F_126 ( & V_41 -> V_215 . V_125 ) ;
if ( V_280 & V_13 )
F_126 ( & V_41 -> V_221 . V_125 ) ;
if ( V_280 & V_14 ) {
V_281 = F_13 ( V_41 , V_285 ) ;
F_11 ( V_41 , V_285 , V_281 ) ;
while ( V_281 ) {
V_48 = F_127 ( V_281 ) - 1 ;
F_126 (
& V_41 -> V_286 [ V_48 ] . V_142 . V_125 ) ;
V_281 &= ~ ( 1 << V_48 ) ;
}
}
if ( V_280 & V_15 ) {
V_281 = F_13 ( V_41 , V_287 ) ;
F_11 ( V_41 , V_287 , V_281 ) ;
while ( V_281 ) {
V_48 = F_127 ( V_281 ) - 1 ;
F_126 (
& V_41 -> V_288 [ V_48 ] . V_142 . V_125 ) ;
V_281 &= ~ ( 1 << V_48 ) ;
}
}
if ( F_8 ( V_280 & V_20 ) )
F_20 ( L_58
L_59 ) ;
if ( F_8 ( V_280 & V_16 ) ) {
F_13 ( V_41 , V_289 ) ;
F_13 ( V_41 , V_290 ) ;
F_11 ( V_41 , V_269 ,
V_16 ) ;
if ( F_128 () )
F_20 ( L_60 ) ;
}
if ( F_8 ( V_280 & V_17 ) ) {
if ( F_128 () )
F_4 ( L_61 ) ;
F_11 ( V_41 , V_263 ,
V_264 ) ;
}
if ( F_8 ( V_280 & V_19 ) ) {
if ( F_128 () )
F_4 ( L_62 ) ;
}
if ( F_8 ( V_280 & V_21 ) )
F_112 ( V_41 ) ;
if ( V_280 & V_18 ) {
F_129 ( & V_41 -> V_154 ) ;
F_117 ( V_41 ) ;
F_130 ( & V_41 -> V_154 ) ;
} else
F_15 ( V_41 ) ;
return V_291 ;
}
static int F_131 ( struct V_1 * V_41 )
{
T_1 V_47 ;
int V_48 ;
F_11 ( V_41 , V_292 , V_293 ) ;
for ( V_48 = 0 ; V_48 < 500 ; V_48 ++ ) {
V_47 = F_13 ( V_41 , V_292 ) ;
if ( ! ~ V_47 )
return - V_50 ;
if ( ! ( V_47 & V_293 ) )
return 0 ;
F_19 ( 1 ) ;
}
return - V_52 ;
}
static void F_132 ( V_39 * V_294 , const V_39 * V_295 , T_9 V_93 )
{
T_9 V_296 = V_93 * 4 ;
memcpy ( V_294 , V_295 , V_296 ) ;
if ( V_296 < V_197 )
memset ( & V_294 [ V_93 ] , 0 , V_197 - V_296 ) ;
}
static int F_133 ( struct V_1 * V_41 )
{
bool V_297 ;
int V_56 , V_298 , V_299 , V_42 ;
if ( ! ( F_13 ( V_41 , V_292 ) &
V_300 ) )
return 0 ;
V_297 = false ;
V_56 = F_16 ( V_41 , 2 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( ( V_56 & V_301 ) == V_301 ) {
V_56 = F_24 ( V_41 , 1 , 8 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( V_56 >= 1 )
V_297 = true ;
}
if ( V_41 -> V_115 & V_302 )
V_297 = false ;
if ( V_297 ) {
V_298 = 0 ;
V_299 = V_303 | V_304 ;
} else {
V_298 = V_303 | V_304 ;
V_299 = 0 ;
}
V_56 = F_23 ( V_41 , 5 , V_298 , V_299 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( V_297 )
V_42 = V_292 ;
else
V_42 = V_305 ;
F_11 ( V_41 , V_42 , V_306 ) ;
F_11 ( V_41 , V_305 ,
V_300 ) ;
return 0 ;
}
static int F_134 ( struct V_1 * V_41 )
{
static const T_10 V_307 [] = { 0x08 , 0x00 , 0x28 , 0x83 , 0x30 , 0x05 , } ;
int V_167 , V_48 ;
V_167 = F_16 ( V_41 , 2 ) ;
if ( V_167 < 0 )
return V_167 ;
if ( ( V_167 & V_301 ) != V_301 )
return 0 ;
for ( V_48 = F_9 ( V_307 ) - 1 ; V_48 >= 0 ; V_48 -- ) {
V_167 = F_24 ( V_41 , 1 , V_48 + 10 ) ;
if ( V_167 < 0 )
return V_167 ;
if ( V_167 != V_307 [ V_48 ] )
return 0 ;
}
return 1 ;
}
static int F_135 ( struct V_2 * V_3 ,
const V_39 * V_201 , T_9 V_93 )
{
struct V_1 * V_41 = V_1 ( V_3 ) ;
struct V_308 * V_309 = F_136 ( V_3 -> V_78 ) ;
T_1 V_310 , V_311 , V_312 , V_313 ;
int V_48 , V_56 ;
if ( F_131 ( V_41 ) ) {
F_20 ( L_63 ) ;
return - V_52 ;
}
F_11 ( V_41 , V_292 ,
V_314 |
V_315 ) ;
F_15 ( V_41 ) ;
for ( V_310 = 0 , V_48 = 0 ; ! V_310 && V_48 < 3 ; V_48 ++ ) {
F_19 ( 50 ) ;
V_310 = F_13 ( V_41 , V_292 ) &
V_314 ;
}
if ( ! V_310 ) {
F_20 ( L_64 ) ;
return - V_316 ;
}
if ( V_41 -> V_115 & V_268 ) {
V_56 = F_134 ( V_41 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( V_56 )
F_4 ( L_65 ) ;
else
V_41 -> V_115 &= ~ V_268 ;
}
F_11 ( V_41 , V_305 ,
V_317 ) ;
F_11 ( V_41 , V_318 , V_41 -> V_319 ) ;
F_11 ( V_41 , V_263 ,
V_320 |
V_264 ) ;
F_11 ( V_41 , V_321 ,
V_322 |
( V_323 << 4 ) |
( V_324 << 8 ) |
( 200 << 16 ) ) ;
V_311 = F_137 ( F_138 () ) ;
F_11 ( V_41 , V_241 , V_311 << 25 ) ;
V_41 -> V_244 = V_311 & ~ 0x3f ;
V_312 = F_13 ( V_41 , V_45 ) & 0x00ff00ff ;
if ( V_312 >= V_325 ) {
F_11 ( V_41 , V_326 ,
0xfffffffe ) ;
V_3 -> V_327 = true ;
}
F_11 ( V_41 , V_328 , 0x3f ) ;
V_41 -> V_329 = F_13 ( V_41 , V_328 ) & 0x3f ;
F_11 ( V_41 , V_328 , 0 ) ;
V_3 -> V_330 = V_41 -> V_329 != 0 ;
F_11 ( V_41 , V_331 , 0x00010000 ) ;
F_11 ( V_41 , V_269 , ~ 0 ) ;
F_11 ( V_41 , V_332 , ~ 0 ) ;
V_56 = F_133 ( V_41 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 = F_28 ( V_3 , 4 , 0 , V_333 | V_334 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( V_201 ) {
V_41 -> V_270 =
F_76 ( V_41 -> V_3 . V_78 , V_197 ,
& V_41 -> V_272 ,
V_126 ) ;
if ( V_41 -> V_270 == NULL )
return - V_139 ;
F_132 ( V_41 -> V_270 , V_201 , V_93 ) ;
} else {
V_41 -> V_270 = V_41 -> V_201 ;
V_41 -> V_272 = V_41 -> V_271 ;
}
V_41 -> V_274 = V_41 -> V_270 [ 0 ] ;
V_41 -> V_270 [ 0 ] = 0 ;
F_11 ( V_41 , V_275 , 0 ) ;
F_11 ( V_41 , V_273 ,
F_10 ( V_41 -> V_270 [ 2 ] ) ) ;
F_11 ( V_41 , V_335 , V_41 -> V_272 ) ;
F_11 ( V_41 , V_336 , 0x80000000 ) ;
if ( ! ( V_41 -> V_115 & V_337 ) )
F_139 ( V_309 ) ;
if ( F_140 ( V_309 -> V_279 , F_124 ,
F_141 ( V_309 ) ? 0 : V_338 ,
V_339 , V_41 ) ) {
F_20 ( L_66 , V_309 -> V_279 ) ;
F_142 ( V_309 ) ;
if ( V_201 ) {
F_82 ( V_41 -> V_3 . V_78 , V_197 ,
V_41 -> V_270 ,
V_41 -> V_272 ) ;
V_41 -> V_270 = NULL ;
}
return - V_316 ;
}
V_313 = V_12 | V_13 |
V_10 | V_11 |
V_15 | V_14 |
V_16 |
V_9 |
V_20 |
V_18 |
V_19 |
V_21 |
V_17 |
V_340 ;
if ( V_5 & V_7 )
V_313 |= V_8 ;
F_11 ( V_41 , V_341 , V_313 ) ;
F_11 ( V_41 , V_292 ,
V_342 |
V_343 ) ;
F_11 ( V_41 , V_263 ,
V_344 |
V_345 ) ;
F_66 ( & V_41 -> V_117 ) ;
F_66 ( & V_41 -> V_284 ) ;
F_15 ( V_41 ) ;
F_143 ( & V_41 -> V_3 , false , true ) ;
return 0 ;
}
static int F_144 ( struct V_2 * V_3 ,
const V_39 * V_201 , T_9 V_93 )
{
struct V_1 * V_41 ;
unsigned long V_153 ;
V_39 * V_270 ;
T_2 V_155 ( V_272 ) ;
V_41 = V_1 ( V_3 ) ;
V_270 =
F_76 ( V_41 -> V_3 . V_78 , V_197 ,
& V_272 , V_126 ) ;
if ( V_270 == NULL )
return - V_139 ;
F_72 ( & V_41 -> V_154 , V_153 ) ;
if ( V_41 -> V_270 == NULL ) {
V_41 -> V_270 = V_270 ;
V_41 -> V_272 = V_272 ;
V_270 = NULL ;
}
F_132 ( V_41 -> V_270 , V_201 , V_93 ) ;
V_41 -> V_274 = V_201 [ 0 ] ;
V_41 -> V_270 [ 0 ] = 0 ;
F_11 ( V_41 , V_335 , V_41 -> V_272 ) ;
F_74 ( & V_41 -> V_154 , V_153 ) ;
if ( V_270 != NULL )
F_82 ( V_41 -> V_3 . V_78 , V_197 ,
V_270 , V_272 ) ;
F_143 ( & V_41 -> V_3 , true , true ) ;
return 0 ;
}
static void F_145 ( struct V_2 * V_3 , struct V_90 * V_169 )
{
struct V_1 * V_41 = V_1 ( V_3 ) ;
F_108 ( & V_41 -> V_215 , V_169 ) ;
}
static void F_146 ( struct V_2 * V_3 , struct V_90 * V_169 )
{
struct V_1 * V_41 = V_1 ( V_3 ) ;
F_108 ( & V_41 -> V_221 , V_169 ) ;
}
static int F_147 ( struct V_2 * V_3 , struct V_90 * V_169 )
{
struct V_1 * V_41 = V_1 ( V_3 ) ;
struct V_142 * V_62 = & V_41 -> V_215 ;
struct V_171 * V_171 = V_169 -> V_171 ;
int V_56 = - V_346 ;
F_95 ( & V_62 -> V_125 ) ;
if ( V_169 -> V_109 != 0 )
goto V_209;
if ( V_169 -> V_179 )
F_93 ( V_41 -> V_3 . V_78 , V_169 -> V_170 ,
V_169 -> V_98 , V_178 ) ;
F_7 ( 'T' , V_169 -> V_29 , V_169 -> V_32 , 0x20 ) ;
V_171 -> V_169 = NULL ;
V_169 -> V_109 = V_184 ;
V_169 -> V_152 ( V_169 , & V_41 -> V_3 , V_169 -> V_109 ) ;
V_56 = 0 ;
V_209:
F_96 ( & V_62 -> V_125 ) ;
return V_56 ;
}
static int F_148 ( struct V_2 * V_3 ,
int V_25 , int V_26 )
{
#ifdef F_122
return 0 ;
#else
struct V_1 * V_41 = V_1 ( V_3 ) ;
unsigned long V_153 ;
int V_347 , V_56 = 0 ;
F_72 ( & V_41 -> V_154 , V_153 ) ;
if ( V_41 -> V_26 != V_26 ) {
V_56 = - V_348 ;
goto V_209;
}
V_347 = ( V_25 & 0xffc0 ) == V_349 ? V_25 & 0x3f : 63 ;
if ( V_347 < 32 )
F_11 ( V_41 , V_277 , 1 << V_347 ) ;
else
F_11 ( V_41 , V_276 , 1 << ( V_347 - 32 ) ) ;
F_15 ( V_41 ) ;
V_209:
F_74 ( & V_41 -> V_154 , V_153 ) ;
return V_56 ;
#endif
}
static T_1 F_149 ( struct V_2 * V_3 , int V_350 )
{
struct V_1 * V_41 = V_1 ( V_3 ) ;
unsigned long V_153 ;
T_1 V_351 ;
switch ( V_350 ) {
case V_352 :
case V_353 :
if ( V_41 -> V_262 &&
( F_13 ( V_41 , V_263 ) &
V_264 ) )
V_351 = V_354 ;
else
V_351 = 0 ;
if ( V_41 -> V_278 )
V_351 |= V_355 ;
return V_351 ;
case V_356 :
return F_13 ( V_41 , V_250 ) << 16 ;
case V_357 :
return F_116 ( V_41 ) ;
case V_358 :
F_72 ( & V_41 -> V_154 , V_153 ) ;
V_351 = F_117 ( V_41 ) ;
F_74 ( & V_41 -> V_154 , V_153 ) ;
return V_351 ;
case V_359 :
V_351 = F_13 ( V_41 , V_321 ) ;
return ( V_351 >> 4 ) & 0x0ffff00f ;
case V_360 :
return ( F_13 ( V_41 , V_328 ) & 0x3f ) |
( V_41 -> V_329 << 8 ) ;
default:
F_150 ( 1 ) ;
return 0 ;
}
}
static void F_151 ( struct V_2 * V_3 , int V_350 , T_1 V_351 )
{
struct V_1 * V_41 = V_1 ( V_3 ) ;
unsigned long V_153 ;
switch ( V_350 ) {
case V_352 :
if ( ( V_351 & V_354 ) && V_41 -> V_262 ) {
F_11 ( V_41 , V_361 ,
V_264 ) ;
F_15 ( V_41 ) ;
}
if ( V_351 & V_355 )
V_41 -> V_278 = false ;
break;
case V_353 :
if ( ( V_351 & V_354 ) && V_41 -> V_262 ) {
F_11 ( V_41 , V_263 ,
V_264 ) ;
F_15 ( V_41 ) ;
}
if ( V_351 & V_355 )
V_41 -> V_278 = true ;
break;
case V_356 :
F_11 ( V_41 , V_250 , V_351 >> 16 ) ;
F_15 ( V_41 ) ;
break;
case V_357 :
F_11 ( V_41 , V_241 , V_351 ) ;
F_11 ( V_41 , V_362 ,
V_19 ) ;
F_15 ( V_41 ) ;
break;
case V_358 :
F_72 ( & V_41 -> V_154 , V_153 ) ;
V_41 -> V_244 = ( V_41 -> V_244 & 0x7f ) | ( V_351 & ~ 0x7f ) ;
F_74 ( & V_41 -> V_154 , V_153 ) ;
break;
case V_359 :
V_351 = ( V_351 & 0xf ) | ( ( V_351 & 0xf ) << 4 ) |
( ( V_351 & 0xf ) << 8 ) | ( ( V_351 & 0x0ffff000 ) << 4 ) ;
F_11 ( V_41 , V_321 , V_351 ) ;
F_15 ( V_41 ) ;
break;
case V_360 :
F_11 ( V_41 , V_328 , V_351 & 0x3f ) ;
F_15 ( V_41 ) ;
break;
default:
F_150 ( 1 ) ;
break;
}
}
static void F_152 ( struct V_363 * V_62 , void * V_91 )
{
int V_48 = V_62 -> V_97 ;
if ( V_48 + V_62 -> V_364 . V_365 > V_70 )
return;
if ( V_62 -> V_364 . V_365 > 0 )
* ( T_1 * ) ( V_62 -> V_32 + V_48 ) = F_153 ( * ( T_1 * ) ( V_91 + 4 ) ) ;
if ( V_62 -> V_364 . V_365 > 4 )
* ( T_1 * ) ( V_62 -> V_32 + V_48 + 4 ) = F_153 ( * ( T_1 * ) V_91 ) ;
if ( V_62 -> V_364 . V_365 > 8 )
memcpy ( V_62 -> V_32 + V_48 + 8 , V_91 + 8 , V_62 -> V_364 . V_365 - 8 ) ;
V_62 -> V_97 += V_62 -> V_364 . V_365 ;
}
static int F_154 ( struct V_142 * V_142 ,
struct V_65 * V_66 ,
struct V_65 * V_84 )
{
struct V_363 * V_62 =
F_1 ( V_142 , struct V_363 , V_142 ) ;
struct V_65 * V_366 ;
T_1 V_367 ;
T_4 * V_368 ;
void * V_91 ;
for ( V_366 = V_66 ; V_366 <= V_84 ; V_366 ++ )
if ( V_366 -> V_71 )
break;
if ( V_366 > V_84 )
return 0 ;
while ( ! ( V_66 -> V_134 & F_33 ( V_137 ) ) ) {
V_66 ++ ;
V_367 = F_71 ( V_66 -> V_138 ) ;
F_155 ( V_142 -> V_41 -> V_3 . V_78 ,
V_367 & V_369 ,
V_367 & ~ V_369 ,
F_48 ( V_66 -> V_133 ) ,
V_79 ) ;
}
V_91 = V_84 + 1 ;
F_152 ( V_62 , V_91 ) ;
if ( F_48 ( V_84 -> V_134 ) & V_180 ) {
V_368 = ( T_4 * ) V_91 ;
V_62 -> V_364 . V_152 . V_370 ( & V_62 -> V_364 ,
F_71 ( V_368 [ 0 ] ) & 0xffff ,
V_62 -> V_97 , V_62 -> V_32 ,
V_62 -> V_364 . V_371 ) ;
V_62 -> V_97 = 0 ;
}
return 1 ;
}
static int F_156 ( struct V_142 * V_142 ,
struct V_65 * V_66 ,
struct V_65 * V_84 )
{
struct V_363 * V_62 =
F_1 ( V_142 , struct V_363 , V_142 ) ;
T_1 V_367 ;
if ( ! V_84 -> V_71 )
return 0 ;
V_367 = F_71 ( V_84 -> V_138 ) ;
F_155 ( V_142 -> V_41 -> V_3 . V_78 ,
V_367 & V_369 ,
V_367 & ~ V_369 ,
F_48 ( V_84 -> V_133 ) ,
V_79 ) ;
if ( F_48 ( V_84 -> V_134 ) & V_180 )
V_62 -> V_364 . V_152 . V_372 ( & V_62 -> V_364 ,
F_71 ( V_84 -> V_138 ) +
F_48 ( V_84 -> V_133 ) -
F_48 ( V_84 -> V_69 ) ,
V_62 -> V_364 . V_371 ) ;
return 1 ;
}
static inline void F_157 ( struct V_142 * V_142 ,
struct V_65 * V_366 )
{
T_3 V_134 ;
T_1 V_367 ;
if ( V_366 -> V_134 & F_33 ( V_137 ) )
return;
V_366 += 2 ;
if ( ( F_71 ( V_366 -> V_138 ) & V_369 ) ==
( V_142 -> V_149 & V_369 ) ) {
if ( V_366 -> V_134 & F_33 ( V_137 ) )
return;
V_366 ++ ;
}
do {
V_367 = F_71 ( V_366 -> V_138 ) ;
F_155 ( V_142 -> V_41 -> V_3 . V_78 ,
V_367 & V_369 ,
V_367 & ~ V_369 ,
F_48 ( V_366 -> V_133 ) ,
V_178 ) ;
V_134 = V_366 -> V_134 ;
V_366 ++ ;
} while ( ! ( V_134 & F_33 ( V_137 ) ) );
}
static int F_158 ( struct V_142 * V_142 ,
struct V_65 * V_66 ,
struct V_65 * V_84 )
{
struct V_363 * V_62 =
F_1 ( V_142 , struct V_363 , V_142 ) ;
int V_48 ;
struct V_65 * V_366 ;
for ( V_366 = V_66 ; V_366 <= V_84 ; V_366 ++ )
if ( V_366 -> V_71 )
break;
if ( V_366 > V_84 )
return 0 ;
F_157 ( V_142 , V_66 ) ;
V_48 = V_62 -> V_97 ;
if ( V_48 + 4 < V_70 ) {
* ( V_39 * ) ( V_62 -> V_32 + V_48 ) = F_105 (
( ( T_1 ) F_48 ( V_366 -> V_71 ) << 16 ) |
F_48 ( V_366 -> V_69 ) ) ;
V_62 -> V_97 += 4 ;
}
if ( F_48 ( V_84 -> V_134 ) & V_180 ) {
V_62 -> V_364 . V_152 . V_370 ( & V_62 -> V_364 , F_48 ( V_84 -> V_69 ) ,
V_62 -> V_97 , V_62 -> V_32 ,
V_62 -> V_364 . V_371 ) ;
V_62 -> V_97 = 0 ;
}
return 1 ;
}
static void F_159 ( struct V_1 * V_41 , T_6 V_373 )
{
T_1 V_374 = V_373 >> 32 , V_375 = V_373 ;
F_11 ( V_41 , V_376 , ~ V_374 ) ;
F_11 ( V_41 , V_377 , ~ V_375 ) ;
F_11 ( V_41 , V_378 , V_374 ) ;
F_11 ( V_41 , V_379 , V_375 ) ;
F_160 () ;
V_41 -> V_380 = V_373 ;
}
static struct V_381 * F_161 ( struct V_2 * V_3 ,
int type , int V_382 , T_9 V_365 )
{
struct V_1 * V_41 = V_1 ( V_3 ) ;
struct V_363 * V_155 ( V_62 ) ;
T_5 V_155 ( V_152 ) ;
T_6 * V_155 ( V_373 ) ;
T_1 * V_155 ( V_383 ) , V_155 ( V_73 ) ;
unsigned long V_153 ;
int V_64 , V_56 = - V_52 ;
F_72 ( & V_41 -> V_154 , V_153 ) ;
switch ( type ) {
case V_384 :
V_383 = & V_41 -> V_385 ;
V_152 = F_158 ;
V_64 = F_127 ( * V_383 ) - 1 ;
if ( V_64 >= 0 ) {
* V_383 &= ~ ( 1 << V_64 ) ;
V_73 = F_113 ( V_64 ) ;
V_62 = & V_41 -> V_288 [ V_64 ] ;
}
break;
case V_386 :
V_373 = & V_41 -> V_387 ;
V_383 = & V_41 -> V_388 ;
V_152 = F_154 ;
V_64 = * V_373 & 1ULL << V_382 ? F_127 ( * V_383 ) - 1 : - 1 ;
if ( V_64 >= 0 ) {
* V_373 &= ~ ( 1ULL << V_382 ) ;
* V_383 &= ~ ( 1 << V_64 ) ;
V_73 = F_114 ( V_64 ) ;
V_62 = & V_41 -> V_286 [ V_64 ] ;
}
break;
case V_389 :
V_383 = & V_41 -> V_388 ;
V_152 = F_156 ;
V_64 = ! V_41 -> V_390 ? F_127 ( * V_383 ) - 1 : - 1 ;
if ( V_64 >= 0 ) {
V_41 -> V_390 = true ;
* V_383 &= ~ ( 1 << V_64 ) ;
V_73 = F_114 ( V_64 ) ;
V_62 = & V_41 -> V_286 [ V_64 ] ;
}
break;
default:
V_64 = - 1 ;
V_56 = - V_391 ;
}
F_74 ( & V_41 -> V_154 , V_153 ) ;
if ( V_64 < 0 )
return F_162 ( V_56 ) ;
memset ( V_62 , 0 , sizeof( * V_62 ) ) ;
V_62 -> V_97 = 0 ;
V_62 -> V_32 = ( void * ) F_163 ( V_126 ) ;
if ( V_62 -> V_32 == NULL ) {
V_56 = - V_139 ;
goto V_209;
}
V_56 = F_78 ( & V_62 -> V_142 , V_41 , V_73 , V_152 ) ;
if ( V_56 < 0 )
goto V_392;
if ( type == V_389 )
F_159 ( V_41 , 0 ) ;
return & V_62 -> V_364 ;
V_392:
F_164 ( ( unsigned long ) V_62 -> V_32 ) ;
V_209:
F_72 ( & V_41 -> V_154 , V_153 ) ;
switch ( type ) {
case V_386 :
* V_373 |= 1ULL << V_382 ;
break;
case V_389 :
V_41 -> V_390 = false ;
break;
}
* V_383 |= 1 << V_64 ;
F_74 ( & V_41 -> V_154 , V_153 ) ;
return F_162 ( V_56 ) ;
}
static int F_165 ( struct V_381 * V_364 ,
T_7 V_393 , T_1 V_394 , T_1 V_395 )
{
struct V_363 * V_62 = F_1 ( V_364 , struct V_363 , V_364 ) ;
struct V_1 * V_41 = V_62 -> V_142 . V_41 ;
T_1 V_134 = V_396 , V_397 ;
int V_64 ;
if ( V_62 -> V_142 . V_84 -> V_68 == 0 )
return - V_398 ;
switch ( V_62 -> V_364 . type ) {
case V_384 :
V_64 = V_62 - V_41 -> V_288 ;
V_397 = 0 ;
if ( V_393 >= 0 )
V_397 = V_399 |
( V_393 & 0x7fff ) << 16 ;
F_11 ( V_41 , V_287 , 1 << V_64 ) ;
F_11 ( V_41 , V_400 , 1 << V_64 ) ;
F_84 ( & V_62 -> V_142 , V_397 ) ;
break;
case V_389 :
V_134 |= V_401 | V_402 ;
case V_386 :
V_64 = V_62 - V_41 -> V_286 ;
V_397 = ( V_395 << 28 ) | ( V_394 << 8 ) | V_62 -> V_364 . V_382 ;
if ( V_393 >= 0 ) {
V_397 |= ( V_393 & 0x07fff ) << 12 ;
V_134 |= V_403 ;
}
F_11 ( V_41 , V_285 , 1 << V_64 ) ;
F_11 ( V_41 , V_404 , 1 << V_64 ) ;
F_11 ( V_41 , F_166 ( V_62 -> V_142 . V_73 ) , V_397 ) ;
F_84 ( & V_62 -> V_142 , V_134 ) ;
V_62 -> V_394 = V_394 ;
V_62 -> V_395 = V_395 ;
break;
}
return 0 ;
}
static int F_167 ( struct V_381 * V_364 )
{
struct V_1 * V_41 = V_1 ( V_364 -> V_3 ) ;
struct V_363 * V_62 = F_1 ( V_364 , struct V_363 , V_364 ) ;
int V_64 ;
switch ( V_62 -> V_364 . type ) {
case V_384 :
V_64 = V_62 - V_41 -> V_288 ;
F_11 ( V_41 , V_405 , 1 << V_64 ) ;
break;
case V_386 :
case V_389 :
V_64 = V_62 - V_41 -> V_286 ;
F_11 ( V_41 , V_406 , 1 << V_64 ) ;
break;
}
F_15 ( V_41 ) ;
F_86 ( & V_62 -> V_142 ) ;
F_168 ( & V_62 -> V_142 . V_125 ) ;
return 0 ;
}
static void F_169 ( struct V_381 * V_364 )
{
struct V_1 * V_41 = V_1 ( V_364 -> V_3 ) ;
struct V_363 * V_62 = F_1 ( V_364 , struct V_363 , V_364 ) ;
unsigned long V_153 ;
int V_64 ;
F_167 ( V_364 ) ;
F_80 ( & V_62 -> V_142 ) ;
F_164 ( ( unsigned long ) V_62 -> V_32 ) ;
F_72 ( & V_41 -> V_154 , V_153 ) ;
switch ( V_364 -> type ) {
case V_384 :
V_64 = V_62 - V_41 -> V_288 ;
V_41 -> V_385 |= 1 << V_64 ;
break;
case V_386 :
V_64 = V_62 - V_41 -> V_286 ;
V_41 -> V_388 |= 1 << V_64 ;
V_41 -> V_387 |= 1ULL << V_364 -> V_382 ;
break;
case V_389 :
V_64 = V_62 - V_41 -> V_286 ;
V_41 -> V_388 |= 1 << V_64 ;
V_41 -> V_387 |= V_41 -> V_380 ;
V_41 -> V_380 = 0 ;
V_41 -> V_390 = false ;
break;
}
F_74 ( & V_41 -> V_154 , V_153 ) ;
}
static int F_170 ( struct V_381 * V_364 , T_6 * V_373 )
{
struct V_1 * V_41 = V_1 ( V_364 -> V_3 ) ;
unsigned long V_153 ;
int V_56 ;
switch ( V_364 -> type ) {
case V_389 :
F_72 ( & V_41 -> V_154 , V_153 ) ;
if ( ~ V_41 -> V_387 & ~ V_41 -> V_380 & * V_373 ) {
* V_373 = V_41 -> V_387 ;
V_56 = - V_52 ;
} else {
F_159 ( V_41 , * V_373 ) ;
V_56 = 0 ;
}
F_74 ( & V_41 -> V_154 , V_153 ) ;
break;
default:
V_56 = - V_407 ;
}
return V_56 ;
}
static void F_171 ( struct V_1 * V_41 )
{
int V_48 ;
struct V_363 * V_62 ;
for ( V_48 = 0 ; V_48 < V_41 -> V_408 ; V_48 ++ ) {
V_62 = & V_41 -> V_286 [ V_48 ] ;
if ( V_62 -> V_142 . V_166 )
F_165 ( & V_62 -> V_364 , 0 , V_62 -> V_394 , V_62 -> V_395 ) ;
}
for ( V_48 = 0 ; V_48 < V_41 -> V_409 ; V_48 ++ ) {
V_62 = & V_41 -> V_288 [ V_48 ] ;
if ( V_62 -> V_142 . V_166 )
F_165 ( & V_62 -> V_364 , 0 , V_62 -> V_394 , V_62 -> V_395 ) ;
}
}
static int F_172 ( struct V_363 * V_62 ,
struct V_410 * V_169 ,
struct V_411 * V_75 ,
unsigned long V_108 )
{
struct V_65 * V_66 , * V_84 , * V_366 ;
struct V_410 * V_91 ;
T_4 * V_32 ;
T_2 V_164 , V_412 ;
T_1 V_140 , V_413 , V_414 , V_279 ;
T_1 V_415 , V_416 , V_417 ;
int V_58 , V_418 , V_48 , V_93 , V_42 ;
V_91 = V_169 ;
V_415 = V_108 ;
if ( V_91 -> V_419 )
V_140 = 1 ;
else
V_140 = 2 ;
if ( V_91 -> V_97 > 0 )
V_140 ++ ;
V_418 = F_173 ( V_415 + V_91 -> V_98 ) >> V_420 ;
if ( V_91 -> V_98 > 0 )
V_414 = V_418 - ( V_415 >> V_420 ) ;
else
V_414 = 0 ;
V_140 += V_414 ;
V_413 = F_174 ( V_91 -> V_97 , sizeof( * V_66 ) ) ;
V_66 = F_83 ( & V_62 -> V_142 , V_140 + V_413 , & V_164 ) ;
if ( V_66 == NULL )
return - V_139 ;
if ( ! V_91 -> V_419 ) {
V_66 [ 0 ] . V_134 = F_33 ( V_173 ) ;
V_66 [ 0 ] . V_133 = F_33 ( 8 ) ;
V_66 [ 0 ] . V_68 = F_32 ( V_164 | V_140 ) ;
V_32 = ( T_4 * ) & V_66 [ 1 ] ;
V_32 [ 0 ] = F_32 ( F_175 ( V_91 -> V_421 ) |
F_176 ( V_91 -> V_422 ) |
F_177 ( V_176 ) |
F_178 ( V_62 -> V_364 . V_382 ) |
F_179 ( V_62 -> V_364 . V_29 ) ) ;
V_32 [ 1 ] =
F_32 ( F_180 ( V_91 -> V_97 +
V_91 -> V_98 ) ) ;
}
if ( V_91 -> V_97 > 0 ) {
V_66 [ 2 ] . V_133 = F_33 ( V_91 -> V_97 ) ;
V_66 [ 2 ] . V_138 = F_32 ( V_164 + V_140 * sizeof( * V_66 ) ) ;
memcpy ( & V_66 [ V_140 ] , V_91 -> V_32 , V_91 -> V_97 ) ;
}
V_366 = V_66 + V_140 - V_414 ;
V_416 = V_415 + V_91 -> V_98 ;
for ( V_48 = 0 ; V_48 < V_414 ; V_48 ++ ) {
V_58 = V_415 >> V_420 ;
V_42 = V_415 & ~ V_369 ;
V_417 = ( V_58 + 1 ) << V_420 ;
V_93 =
F_181 ( V_417 , V_416 ) - V_415 ;
V_366 [ V_48 ] . V_133 = F_33 ( V_93 ) ;
V_412 = F_30 ( V_75 -> V_63 [ V_58 ] ) ;
V_366 [ V_48 ] . V_138 = F_32 ( V_412 + V_42 ) ;
F_182 ( V_62 -> V_142 . V_41 -> V_3 . V_78 ,
V_412 , V_42 , V_93 ,
V_178 ) ;
V_415 += V_93 ;
}
if ( V_91 -> V_423 )
V_279 = V_180 ;
else
V_279 = V_424 ;
V_84 = V_140 == 2 ? V_66 : V_66 + V_140 - 1 ;
V_84 -> V_134 |= F_33 ( V_161 |
V_136 |
V_137 |
V_279 ) ;
F_85 ( & V_62 -> V_142 , V_66 , V_140 , V_413 ) ;
return 0 ;
}
static int F_183 ( struct V_363 * V_62 ,
struct V_410 * V_169 ,
struct V_411 * V_75 ,
unsigned long V_108 )
{
struct V_78 * V_78 = V_62 -> V_142 . V_41 -> V_3 . V_78 ;
struct V_65 * V_66 , * V_366 ;
T_2 V_164 , V_412 ;
T_1 V_140 , V_413 , V_425 ;
int V_48 , V_254 , V_93 ;
int V_58 , V_42 , V_426 , V_365 , V_427 ;
V_426 = V_169 -> V_97 / V_62 -> V_364 . V_365 ;
V_365 = F_184 ( V_62 -> V_364 . V_365 , ( T_9 ) 8 ) ;
V_413 = F_174 ( V_365 , sizeof( * V_66 ) ) ;
V_58 = V_108 >> V_420 ;
V_42 = V_108 & ~ V_369 ;
V_427 = V_169 -> V_98 / V_426 ;
for ( V_48 = 0 ; V_48 < V_426 ; V_48 ++ ) {
V_140 = F_174 ( V_427 + V_42 , V_70 ) + 1 ;
V_66 = F_83 ( & V_62 -> V_142 ,
V_140 + V_413 , & V_164 ) ;
if ( V_66 == NULL )
return - V_139 ;
V_66 -> V_134 = F_33 ( V_136 |
V_135 ) ;
if ( V_169 -> V_419 && V_48 == 0 )
V_66 -> V_134 |= F_33 ( V_428 ) ;
V_66 -> V_133 = F_33 ( V_365 ) ;
V_66 -> V_69 = V_66 -> V_133 ;
V_66 -> V_71 = 0 ;
V_66 -> V_138 = F_32 ( V_164 + ( V_140 * sizeof( * V_66 ) ) ) ;
V_425 = V_427 ;
V_366 = V_66 ;
for ( V_254 = 1 ; V_254 < V_140 ; V_254 ++ ) {
V_366 ++ ;
V_366 -> V_134 = F_33 ( V_136 |
V_135 ) ;
if ( V_42 + V_425 < V_70 )
V_93 = V_425 ;
else
V_93 = V_70 - V_42 ;
V_366 -> V_133 = F_33 ( V_93 ) ;
V_366 -> V_69 = V_366 -> V_133 ;
V_366 -> V_71 = 0 ;
V_412 = F_30 ( V_75 -> V_63 [ V_58 ] ) ;
V_366 -> V_138 = F_32 ( V_412 + V_42 ) ;
F_182 ( V_78 , V_412 ,
V_42 , V_93 ,
V_79 ) ;
V_42 = ( V_42 + V_93 ) & ~ V_369 ;
V_425 -= V_93 ;
if ( V_42 == 0 )
V_58 ++ ;
}
V_366 -> V_134 = F_33 ( V_136 |
V_429 |
V_137 ) ;
if ( V_169 -> V_423 && V_48 == V_426 - 1 )
V_366 -> V_134 |= F_33 ( V_180 ) ;
F_85 ( & V_62 -> V_142 , V_66 , V_140 , V_413 ) ;
}
return 0 ;
}
static int F_185 ( struct V_363 * V_62 ,
struct V_410 * V_169 ,
struct V_411 * V_75 ,
unsigned long V_108 )
{
struct V_65 * V_66 ;
T_2 V_164 , V_412 ;
int V_58 , V_42 , V_425 , V_140 , V_48 , V_93 ;
V_58 = V_108 >> V_420 ;
V_42 = V_108 & ~ V_369 ;
V_425 = V_169 -> V_98 ;
V_140 = F_174 ( V_42 + V_425 , V_70 ) ;
if ( F_150 ( V_42 & 3 || V_425 & 3 || V_58 + V_140 > V_75 -> V_430 ) )
return - V_431 ;
for ( V_48 = 0 ; V_48 < V_140 ; V_48 ++ ) {
V_66 = F_83 ( & V_62 -> V_142 , 1 , & V_164 ) ;
if ( V_66 == NULL )
return - V_139 ;
V_66 -> V_134 = F_33 ( V_135 |
V_137 ) ;
if ( V_169 -> V_419 && V_48 == 0 )
V_66 -> V_134 |= F_33 ( V_428 ) ;
if ( V_169 -> V_423 && V_48 == V_140 - 1 )
V_66 -> V_134 |= F_33 ( V_180 ) ;
if ( V_42 + V_425 < V_70 )
V_93 = V_425 ;
else
V_93 = V_70 - V_42 ;
V_66 -> V_133 = F_33 ( V_93 ) ;
V_66 -> V_69 = V_66 -> V_133 ;
V_66 -> V_71 = 0 ;
V_412 = F_30 ( V_75 -> V_63 [ V_58 ] ) ;
V_66 -> V_138 = F_32 ( V_412 + V_42 ) ;
F_182 ( V_62 -> V_142 . V_41 -> V_3 . V_78 ,
V_412 , V_42 , V_93 ,
V_79 ) ;
V_425 -= V_93 ;
V_42 = 0 ;
V_58 ++ ;
F_85 ( & V_62 -> V_142 , V_66 , 1 , 0 ) ;
}
return 0 ;
}
static int F_186 ( struct V_381 * V_364 ,
struct V_410 * V_169 ,
struct V_411 * V_75 ,
unsigned long V_108 )
{
struct V_363 * V_62 = F_1 ( V_364 , struct V_363 , V_364 ) ;
unsigned long V_153 ;
int V_56 = - V_391 ;
F_72 ( & V_62 -> V_142 . V_41 -> V_154 , V_153 ) ;
switch ( V_364 -> type ) {
case V_384 :
V_56 = F_172 ( V_62 , V_169 , V_75 , V_108 ) ;
break;
case V_386 :
V_56 = F_183 ( V_62 , V_169 , V_75 , V_108 ) ;
break;
case V_389 :
V_56 = F_185 ( V_62 , V_169 , V_75 , V_108 ) ;
break;
}
F_74 ( & V_62 -> V_142 . V_41 -> V_154 , V_153 ) ;
return V_56 ;
}
static void F_187 ( struct V_381 * V_364 )
{
struct V_142 * V_62 =
& F_1 ( V_364 , struct V_363 , V_364 ) -> V_142 ;
F_11 ( V_62 -> V_41 , F_35 ( V_62 -> V_73 ) , V_74 ) ;
}
static void F_188 ( struct V_308 * V_309 )
{
if ( F_189 ( V_432 ) ) {
struct V_433 * V_434 = F_190 ( V_309 ) ;
if ( V_434 ) {
F_191 ( V_435 , V_434 , 0 , 1 ) ;
F_191 ( V_436 , V_434 , 0 , 1 ) ;
}
}
}
static void F_192 ( struct V_308 * V_309 )
{
if ( F_189 ( V_432 ) ) {
struct V_433 * V_434 = F_190 ( V_309 ) ;
if ( V_434 ) {
F_191 ( V_436 , V_434 , 0 , 0 ) ;
F_191 ( V_435 , V_434 , 0 , 0 ) ;
}
}
}
static inline void F_188 ( struct V_308 * V_309 ) {}
static inline void F_192 ( struct V_308 * V_309 ) {}
static int T_11 F_193 ( struct V_308 * V_309 ,
const struct V_437 * V_438 )
{
struct V_1 * V_41 ;
T_1 V_439 , V_440 , V_441 , V_312 ;
T_6 V_442 ;
int V_48 , V_443 ;
T_9 V_296 ;
if ( V_309 -> V_444 == V_445 ) {
F_194 ( & V_309 -> V_309 , L_67 ) ;
return - V_391 ;
}
V_41 = F_195 ( sizeof( * V_41 ) , V_126 ) ;
if ( V_41 == NULL ) {
V_443 = - V_139 ;
goto V_446;
}
F_196 ( & V_41 -> V_3 , & V_447 , & V_309 -> V_309 ) ;
F_188 ( V_309 ) ;
V_443 = F_197 ( V_309 ) ;
if ( V_443 ) {
F_20 ( L_68 ) ;
goto V_448;
}
F_198 ( V_309 ) ;
F_199 ( V_309 , V_449 , 0 ) ;
F_200 ( V_309 , V_41 ) ;
F_201 ( & V_41 -> V_154 ) ;
F_202 ( & V_41 -> V_60 ) ;
F_203 ( & V_41 -> F_121 , F_121 ) ;
V_443 = F_204 ( V_309 , 0 , V_339 ) ;
if ( V_443 ) {
F_20 ( L_69 ) ;
goto V_450;
}
V_41 -> V_44 = F_205 ( V_309 , 0 , V_451 ) ;
if ( V_41 -> V_44 == NULL ) {
F_20 ( L_70 ) ;
V_443 = - V_452 ;
goto V_453;
}
for ( V_48 = 0 ; V_48 < F_9 ( V_454 ) ; V_48 ++ )
if ( ( V_454 [ V_48 ] . V_444 == V_309 -> V_444 ) &&
( V_454 [ V_48 ] . V_78 == ( unsigned short ) V_455 ||
V_454 [ V_48 ] . V_78 == V_309 -> V_78 ) &&
( V_454 [ V_48 ] . V_456 == ( unsigned short ) V_455 ||
V_454 [ V_48 ] . V_456 >= V_309 -> V_456 ) ) {
V_41 -> V_115 = V_454 [ V_48 ] . V_153 ;
break;
}
if ( V_457 )
V_41 -> V_115 = V_457 ;
F_91 ( V_76 * sizeof( struct V_65 ) > V_70 / 4 ) ;
F_91 ( V_458 > V_70 / 2 ) ;
V_41 -> V_130 = F_76 ( V_41 -> V_3 . V_78 ,
V_70 ,
& V_41 -> V_132 ,
V_126 ) ;
if ( ! V_41 -> V_130 ) {
V_443 = - V_139 ;
goto V_459;
}
V_443 = F_59 ( & V_41 -> V_117 , V_41 , 0 ,
V_460 ) ;
if ( V_443 < 0 )
goto V_461;
V_443 = F_59 ( & V_41 -> V_284 , V_41 , V_70 / 4 ,
V_462 ) ;
if ( V_443 < 0 )
goto V_463;
V_443 = F_78 ( & V_41 -> V_215 , V_41 ,
V_464 , F_97 ) ;
if ( V_443 < 0 )
goto V_465;
V_443 = F_78 ( & V_41 -> V_221 , V_41 ,
V_466 , F_97 ) ;
if ( V_443 < 0 )
goto V_467;
F_11 ( V_41 , V_404 , ~ 0 ) ;
V_41 -> V_387 = ~ 0ULL ;
V_41 -> V_230 = F_13 ( V_41 , V_404 ) ;
F_11 ( V_41 , V_406 , ~ 0 ) ;
V_41 -> V_388 = V_41 -> V_230 ;
V_41 -> V_408 = F_206 ( V_41 -> V_388 ) ;
V_296 = sizeof( struct V_363 ) * V_41 -> V_408 ;
V_41 -> V_286 = F_195 ( V_296 , V_126 ) ;
F_11 ( V_41 , V_400 , ~ 0 ) ;
V_41 -> V_229 = F_13 ( V_41 , V_400 ) ;
F_11 ( V_41 , V_405 , ~ 0 ) ;
V_41 -> V_385 = V_41 -> V_229 ;
V_41 -> V_409 = F_206 ( V_41 -> V_385 ) ;
V_296 = sizeof( struct V_363 ) * V_41 -> V_409 ;
V_41 -> V_288 = F_195 ( V_296 , V_126 ) ;
if ( V_41 -> V_288 == NULL || V_41 -> V_286 == NULL ) {
V_443 = - V_139 ;
goto V_468;
}
V_41 -> V_267 = V_41 -> V_130 + V_70 / 2 ;
V_41 -> V_319 = V_41 -> V_132 + V_70 / 2 ;
V_439 = F_13 ( V_41 , V_273 ) ;
V_440 = ( V_439 >> 12 ) & 0xf ;
V_441 = V_439 & 0x7 ;
V_442 = ( ( T_6 ) F_13 ( V_41 , V_469 ) << 32 ) |
F_13 ( V_41 , V_470 ) ;
V_443 = F_207 ( & V_41 -> V_3 , V_440 , V_441 , V_442 ) ;
if ( V_443 )
goto V_468;
V_312 = F_13 ( V_41 , V_45 ) & 0x00ff00ff ;
F_4 ( L_71
L_72 ,
F_208 ( & V_309 -> V_309 ) , V_312 >> 16 , V_312 & 0xff ,
V_41 -> V_408 , V_41 -> V_409 , V_41 -> V_115 ) ;
return 0 ;
V_468:
F_209 ( V_41 -> V_286 ) ;
F_209 ( V_41 -> V_288 ) ;
F_80 ( & V_41 -> V_221 ) ;
V_467:
F_80 ( & V_41 -> V_215 ) ;
V_465:
F_36 ( & V_41 -> V_284 ) ;
V_463:
F_36 ( & V_41 -> V_117 ) ;
V_461:
F_82 ( V_41 -> V_3 . V_78 , V_70 ,
V_41 -> V_130 , V_41 -> V_132 ) ;
V_459:
F_210 ( V_309 , V_41 -> V_44 ) ;
V_453:
F_211 ( V_309 , 0 ) ;
V_450:
F_212 ( V_309 ) ;
V_448:
F_209 ( V_41 ) ;
F_192 ( V_309 ) ;
V_446:
if ( V_443 == - V_139 )
F_20 ( L_73 ) ;
return V_443 ;
}
static void F_213 ( struct V_308 * V_309 )
{
struct V_1 * V_41 ;
V_41 = F_214 ( V_309 ) ;
F_11 ( V_41 , V_332 , ~ 0 ) ;
F_15 ( V_41 ) ;
F_215 ( & V_41 -> F_121 ) ;
F_216 ( & V_41 -> V_3 ) ;
F_131 ( V_41 ) ;
F_217 ( V_309 -> V_279 , V_41 ) ;
if ( V_41 -> V_270 && V_41 -> V_270 != V_41 -> V_201 )
F_82 ( V_41 -> V_3 . V_78 , V_197 ,
V_41 -> V_270 , V_41 -> V_272 ) ;
if ( V_41 -> V_201 )
F_82 ( V_41 -> V_3 . V_78 , V_197 ,
V_41 -> V_201 , V_41 -> V_271 ) ;
F_36 ( & V_41 -> V_117 ) ;
F_36 ( & V_41 -> V_284 ) ;
F_82 ( V_41 -> V_3 . V_78 , V_70 ,
V_41 -> V_130 , V_41 -> V_132 ) ;
F_80 ( & V_41 -> V_215 ) ;
F_80 ( & V_41 -> V_221 ) ;
F_209 ( V_41 -> V_288 ) ;
F_209 ( V_41 -> V_286 ) ;
F_142 ( V_309 ) ;
F_210 ( V_309 , V_41 -> V_44 ) ;
F_211 ( V_309 , 0 ) ;
F_212 ( V_309 ) ;
F_209 ( V_41 ) ;
F_192 ( V_309 ) ;
F_4 ( L_74 ) ;
}
static int F_218 ( struct V_308 * V_309 , T_12 V_471 )
{
struct V_1 * V_41 = F_214 ( V_309 ) ;
int V_443 ;
F_131 ( V_41 ) ;
F_217 ( V_309 -> V_279 , V_41 ) ;
F_142 ( V_309 ) ;
V_443 = F_219 ( V_309 ) ;
if ( V_443 ) {
F_20 ( L_75 ) ;
return V_443 ;
}
V_443 = F_220 ( V_309 , F_221 ( V_309 , V_471 ) ) ;
if ( V_443 )
F_20 ( L_76 , V_443 ) ;
F_192 ( V_309 ) ;
return 0 ;
}
static int F_222 ( struct V_308 * V_309 )
{
struct V_1 * V_41 = F_214 ( V_309 ) ;
int V_443 ;
F_188 ( V_309 ) ;
F_220 ( V_309 , V_472 ) ;
F_223 ( V_309 ) ;
V_443 = F_197 ( V_309 ) ;
if ( V_443 ) {
F_20 ( L_77 ) ;
return V_443 ;
}
if ( ! F_13 ( V_41 , V_470 ) &&
! F_13 ( V_41 , V_469 ) ) {
F_11 ( V_41 , V_470 , ( T_1 ) V_41 -> V_3 . V_442 ) ;
F_11 ( V_41 , V_469 , ( T_1 ) ( V_41 -> V_3 . V_442 >> 32 ) ) ;
}
V_443 = F_135 ( & V_41 -> V_3 , NULL , 0 ) ;
if ( V_443 )
return V_443 ;
F_171 ( V_41 ) ;
return 0 ;
}
static int T_13 F_224 ( void )
{
return F_225 ( & V_473 ) ;
}
static void T_14 F_226 ( void )
{
F_227 ( & V_473 ) ;
}
