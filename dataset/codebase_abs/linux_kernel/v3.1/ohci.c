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
if ( V_143 < V_145 -> V_149 ||
V_143 >= V_145 -> V_149 + V_145 -> V_150 )
V_145 = F_70 ( V_145 -> V_147 . V_119 ,
struct V_144 , V_147 ) ;
V_66 = V_145 -> V_75 + ( V_143 - V_145 -> V_149 ) / sizeof( * V_66 ) ;
V_84 = F_68 ( V_66 , V_140 ) ;
if ( ! V_62 -> V_151 ( V_62 , V_66 , V_84 ) )
break;
if ( V_148 != V_145 ) {
unsigned long V_152 ;
V_148 -> V_150 = 0 ;
F_72 ( & V_62 -> V_41 -> V_153 , V_152 ) ;
F_73 ( & V_148 -> V_147 , & V_62 -> V_146 ) ;
F_74 ( & V_62 -> V_41 -> V_153 , V_152 ) ;
}
V_62 -> V_84 = V_84 ;
}
}
static int F_75 ( struct V_142 * V_62 )
{
struct V_144 * V_145 ;
T_2 V_154 ( V_155 ) ;
int V_42 ;
if ( V_62 -> V_156 >= 16 * 1024 * 1024 )
return - V_139 ;
V_145 = F_76 ( V_62 -> V_41 -> V_3 . V_78 , V_70 ,
& V_155 , V_157 ) ;
if ( ! V_145 )
return - V_139 ;
V_42 = ( void * ) & V_145 -> V_75 - ( void * ) V_145 ;
V_145 -> V_158 = V_70 - V_42 ;
V_145 -> V_149 = V_155 + V_42 ;
V_145 -> V_150 = 0 ;
F_77 ( & V_145 -> V_147 , & V_62 -> V_146 ) ;
V_62 -> V_156 += V_70 ;
return 0 ;
}
static int F_78 ( struct V_142 * V_62 , struct V_1 * V_41 ,
T_1 V_73 , T_5 V_151 )
{
V_62 -> V_41 = V_41 ;
V_62 -> V_73 = V_73 ;
V_62 -> V_156 = 0 ;
F_79 ( & V_62 -> V_146 ) ;
if ( F_75 ( V_62 ) < 0 )
return - V_139 ;
V_62 -> V_159 = F_70 ( V_62 -> V_146 . V_119 ,
struct V_144 , V_147 ) ;
F_60 ( & V_62 -> V_125 , F_69 , ( unsigned long ) V_62 ) ;
V_62 -> V_151 = V_151 ;
memset ( V_62 -> V_159 -> V_75 , 0 , sizeof( * V_62 -> V_159 -> V_75 ) ) ;
V_62 -> V_159 -> V_75 -> V_134 = F_33 ( V_160 ) ;
V_62 -> V_159 -> V_75 -> V_71 = F_33 ( 0x8011 ) ;
V_62 -> V_159 -> V_150 += sizeof( * V_62 -> V_159 -> V_75 ) ;
V_62 -> V_84 = V_62 -> V_159 -> V_75 ;
V_62 -> V_161 = V_62 -> V_159 -> V_75 ;
return 0 ;
}
static void F_80 ( struct V_142 * V_62 )
{
struct V_2 * V_3 = & V_62 -> V_41 -> V_3 ;
struct V_144 * V_145 , * V_162 ;
F_81 (desc, tmp, &ctx->buffer_list, list)
F_82 ( V_3 -> V_78 , V_70 , V_145 ,
V_145 -> V_149 -
( ( void * ) & V_145 -> V_75 - ( void * ) V_145 ) ) ;
}
static struct V_65 * F_83 ( struct V_142 * V_62 ,
int V_140 , T_2 * V_163 )
{
struct V_65 * V_66 = NULL ;
struct V_144 * V_145 = V_62 -> V_159 ;
if ( V_140 * sizeof( * V_66 ) > V_145 -> V_158 )
return NULL ;
if ( V_140 * sizeof( * V_66 ) > V_145 -> V_158 - V_145 -> V_150 ) {
if ( V_145 -> V_147 . V_119 == & V_62 -> V_146 ) {
if ( F_75 ( V_62 ) < 0 )
return NULL ;
}
V_145 = F_70 ( V_145 -> V_147 . V_119 ,
struct V_144 , V_147 ) ;
V_62 -> V_159 = V_145 ;
}
V_66 = V_145 -> V_75 + V_145 -> V_150 / sizeof( * V_66 ) ;
memset ( V_66 , 0 , V_140 * sizeof( * V_66 ) ) ;
* V_163 = V_145 -> V_149 + V_145 -> V_150 ;
return V_66 ;
}
static void F_84 ( struct V_142 * V_62 , T_1 V_164 )
{
struct V_1 * V_41 = V_62 -> V_41 ;
F_11 ( V_41 , F_67 ( V_62 -> V_73 ) ,
F_71 ( V_62 -> V_84 -> V_68 ) ) ;
F_11 ( V_41 , F_41 ( V_62 -> V_73 ) , ~ 0 ) ;
F_11 ( V_41 , F_35 ( V_62 -> V_73 ) , V_81 | V_164 ) ;
V_62 -> V_165 = true ;
F_15 ( V_41 ) ;
}
static void F_85 ( struct V_142 * V_62 ,
struct V_65 * V_66 , int V_140 , int V_164 )
{
T_2 V_163 ;
struct V_144 * V_145 = V_62 -> V_159 ;
V_163 = V_145 -> V_149 + ( V_66 - V_145 -> V_75 ) * sizeof( * V_66 ) ;
V_145 -> V_150 += ( V_140 + V_164 ) * sizeof( * V_66 ) ;
F_34 () ;
V_62 -> V_161 -> V_68 = F_32 ( V_163 | V_140 ) ;
V_62 -> V_161 = F_68 ( V_66 , V_140 ) ;
}
static void F_86 ( struct V_142 * V_62 )
{
T_1 V_166 ;
int V_48 ;
F_11 ( V_62 -> V_41 , F_41 ( V_62 -> V_73 ) , V_81 ) ;
V_62 -> V_165 = false ;
for ( V_48 = 0 ; V_48 < 1000 ; V_48 ++ ) {
V_166 = F_13 ( V_62 -> V_41 , F_35 ( V_62 -> V_73 ) ) ;
if ( ( V_166 & V_167 ) == 0 )
return;
if ( V_48 )
F_87 ( 10 ) ;
}
F_20 ( L_41 , V_166 ) ;
}
static int F_88 ( struct V_142 * V_62 ,
struct V_90 * V_168 )
{
struct V_1 * V_41 = V_62 -> V_41 ;
T_2 V_163 , V_154 ( V_169 ) ;
struct V_170 * V_170 ;
struct V_65 * V_66 , * V_84 ;
T_4 * V_32 ;
int V_140 , V_33 ;
V_66 = F_83 ( V_62 , 4 , & V_163 ) ;
if ( V_66 == NULL ) {
V_168 -> V_109 = V_171 ;
return - 1 ;
}
V_66 [ 0 ] . V_134 = F_33 ( V_172 ) ;
V_66 [ 0 ] . V_69 = F_33 ( V_168 -> V_110 ) ;
V_33 = ( V_168 -> V_32 [ 0 ] >> 4 ) & 0x0f ;
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
V_32 [ 0 ] = F_32 ( ( V_168 -> V_32 [ 0 ] & 0xffff ) |
( V_168 -> V_29 << 16 ) ) ;
V_32 [ 1 ] = F_32 ( ( V_168 -> V_32 [ 1 ] & 0xffff ) |
( V_168 -> V_32 [ 0 ] & 0xffff0000 ) ) ;
V_32 [ 2 ] = F_32 ( V_168 -> V_32 [ 2 ] ) ;
if ( F_89 ( V_33 ) )
V_32 [ 3 ] = F_32 ( V_168 -> V_32 [ 3 ] ) ;
else
V_32 [ 3 ] = ( V_38 T_4 ) V_168 -> V_32 [ 3 ] ;
V_66 [ 0 ] . V_133 = F_33 ( V_168 -> V_97 ) ;
break;
case V_173 :
V_32 [ 0 ] = F_32 ( ( V_113 << 4 ) |
( V_168 -> V_29 << 16 ) ) ;
V_32 [ 1 ] = F_32 ( V_168 -> V_32 [ 1 ] ) ;
V_32 [ 2 ] = F_32 ( V_168 -> V_32 [ 2 ] ) ;
V_66 [ 0 ] . V_133 = F_33 ( 12 ) ;
if ( F_90 ( & V_168 -> V_32 [ 1 ] ) )
V_66 [ 0 ] . V_134 |= F_33 ( V_174 ) ;
break;
case V_175 :
V_32 [ 0 ] = F_32 ( ( V_168 -> V_32 [ 0 ] & 0xffff ) |
( V_168 -> V_29 << 16 ) ) ;
V_32 [ 1 ] = F_32 ( V_168 -> V_32 [ 0 ] & 0xffff0000 ) ;
V_66 [ 0 ] . V_133 = F_33 ( 8 ) ;
break;
default:
V_168 -> V_109 = V_171 ;
return - 1 ;
}
F_91 ( sizeof( struct V_170 ) > sizeof( struct V_65 ) ) ;
V_170 = (struct V_170 * ) & V_66 [ 3 ] ;
V_170 -> V_168 = V_168 ;
V_168 -> V_170 = V_170 ;
if ( V_168 -> V_98 > 0 ) {
if ( V_168 -> V_98 > sizeof( V_170 -> V_176 ) ) {
V_169 = F_92 ( V_41 -> V_3 . V_78 ,
V_168 -> V_108 ,
V_168 -> V_98 ,
V_177 ) ;
if ( F_63 ( V_41 -> V_3 . V_78 , V_169 ) ) {
V_168 -> V_109 = V_171 ;
return - 1 ;
}
V_168 -> V_169 = V_169 ;
V_168 -> V_178 = true ;
} else {
memcpy ( V_170 -> V_176 , V_168 -> V_108 ,
V_168 -> V_98 ) ;
V_169 = V_163 + 3 * sizeof( * V_66 ) ;
}
V_66 [ 2 ] . V_133 = F_33 ( V_168 -> V_98 ) ;
V_66 [ 2 ] . V_138 = F_32 ( V_169 ) ;
V_84 = & V_66 [ 2 ] ;
V_140 = 3 ;
} else {
V_84 = & V_66 [ 0 ] ;
V_140 = 2 ;
}
V_84 -> V_134 |= F_33 ( V_160 |
V_179 |
V_137 ) ;
if ( V_41 -> V_26 != V_168 -> V_26 ) {
if ( V_168 -> V_178 )
F_93 ( V_41 -> V_3 . V_78 , V_169 ,
V_168 -> V_98 , V_177 ) ;
V_168 -> V_109 = V_180 ;
return - 1 ;
}
F_85 ( V_62 , V_66 , V_140 , 4 - V_140 ) ;
if ( V_62 -> V_165 )
F_11 ( V_41 , F_35 ( V_62 -> V_73 ) , V_74 ) ;
else
F_84 ( V_62 , 0 ) ;
return 0 ;
}
static void F_94 ( struct V_142 * V_62 )
{
F_95 ( & V_62 -> V_125 ) ;
V_62 -> V_181 = true ;
F_69 ( ( unsigned long ) V_62 ) ;
V_62 -> V_181 = false ;
F_96 ( & V_62 -> V_125 ) ;
}
static int F_97 ( struct V_142 * V_142 ,
struct V_65 * V_66 ,
struct V_65 * V_84 )
{
struct V_170 * V_170 ;
struct V_90 * V_168 ;
struct V_1 * V_41 = V_142 -> V_41 ;
int V_4 ;
if ( V_84 -> V_71 == 0 && ! V_142 -> V_181 )
return 0 ;
V_170 = (struct V_170 * ) & V_66 [ 3 ] ;
V_168 = V_170 -> V_168 ;
if ( V_168 == NULL )
return 1 ;
if ( V_168 -> V_178 )
F_93 ( V_41 -> V_3 . V_78 , V_168 -> V_169 ,
V_168 -> V_98 , V_177 ) ;
V_4 = F_48 ( V_84 -> V_71 ) & 0x1f ;
V_168 -> V_110 = F_48 ( V_84 -> V_69 ) ;
F_7 ( 'T' , V_168 -> V_29 , V_168 -> V_32 , V_4 ) ;
switch ( V_4 ) {
case V_182 :
V_168 -> V_109 = V_183 ;
break;
case V_184 :
V_168 -> V_109 = V_180 ;
break;
case V_185 :
if ( V_142 -> V_181 )
V_168 -> V_109 = V_180 ;
else {
V_168 -> V_109 = V_186 ;
}
break;
case V_114 + 0x10 :
case V_187 + 0x10 :
case V_188 + 0x10 :
case V_189 + 0x10 :
case V_190 + 0x10 :
case V_191 + 0x10 :
case V_192 + 0x10 :
V_168 -> V_109 = V_4 - 0x10 ;
break;
case V_112 :
if ( V_142 -> V_181 ) {
V_168 -> V_109 = V_180 ;
break;
}
default:
V_168 -> V_109 = V_171 ;
break;
}
V_168 -> V_151 ( V_168 , & V_41 -> V_3 , V_168 -> V_109 ) ;
return 1 ;
}
static void F_98 ( struct V_1 * V_41 ,
struct V_90 * V_168 , T_1 V_193 )
{
struct V_90 V_194 ;
int V_33 , V_93 , V_48 ;
V_33 = F_99 ( V_168 -> V_32 [ 0 ] ) ;
if ( F_89 ( V_33 ) )
V_93 = F_100 ( V_168 -> V_32 [ 3 ] ) ;
else
V_93 = 4 ;
V_48 = V_193 - V_195 ;
if ( V_48 + V_93 > V_196 ) {
F_101 ( & V_194 , V_168 -> V_32 ,
V_197 , NULL , 0 ) ;
} else if ( ! F_102 ( V_33 ) ) {
F_101 ( & V_194 , V_168 -> V_32 ,
V_198 , NULL , 0 ) ;
} else {
F_101 ( & V_194 , V_168 -> V_32 , V_199 ,
( void * ) V_41 -> V_200 + V_48 , V_93 ) ;
}
F_54 ( & V_41 -> V_3 , & V_194 ) ;
}
static void F_103 ( struct V_1 * V_41 ,
struct V_90 * V_168 , T_1 V_193 )
{
struct V_90 V_194 ;
int V_33 , V_93 , V_201 , V_202 , V_203 ;
V_39 * V_108 , V_204 ;
T_1 V_205 , V_206 ;
V_33 = F_99 ( V_168 -> V_32 [ 0 ] ) ;
V_93 = F_100 ( V_168 -> V_32 [ 3 ] ) ;
V_108 = V_168 -> V_108 ;
V_201 = F_104 ( V_168 -> V_32 [ 3 ] ) ;
if ( V_33 == V_102 &&
V_201 == V_207 && V_93 == 8 ) {
V_205 = F_10 ( V_108 [ 0 ] ) ;
V_206 = F_10 ( V_108 [ 1 ] ) ;
} else if ( V_33 == V_106 ) {
V_205 = 0 ;
V_206 = 0 ;
} else {
F_101 ( & V_194 , V_168 -> V_32 ,
V_198 , NULL , 0 ) ;
goto V_208;
}
V_202 = ( V_193 - V_209 ) / 4 ;
F_11 ( V_41 , V_210 , V_206 ) ;
F_11 ( V_41 , V_211 , V_205 ) ;
F_11 ( V_41 , V_212 , V_202 ) ;
for ( V_203 = 0 ; V_203 < 20 ; V_203 ++ )
if ( F_13 ( V_41 , V_212 ) & 0x80000000 ) {
V_204 = F_105 ( F_13 ( V_41 ,
V_210 ) ) ;
F_101 ( & V_194 , V_168 -> V_32 ,
V_199 ,
& V_204 , sizeof( V_204 ) ) ;
goto V_208;
}
F_20 ( L_42 ) ;
F_101 ( & V_194 , V_168 -> V_32 , V_213 , NULL , 0 ) ;
V_208:
F_54 ( & V_41 -> V_3 , & V_194 ) ;
}
static void F_106 ( struct V_142 * V_62 , struct V_90 * V_168 )
{
T_6 V_42 , V_193 ;
if ( V_62 == & V_62 -> V_41 -> V_214 ) {
V_168 -> V_109 = V_187 ;
V_168 -> V_151 ( V_168 , & V_62 -> V_41 -> V_3 , V_168 -> V_109 ) ;
}
V_42 =
( ( unsigned long long )
F_107 ( V_168 -> V_32 [ 1 ] ) << 32 ) |
V_168 -> V_32 [ 2 ] ;
V_193 = V_42 - V_215 ;
if ( V_193 >= V_195 && V_193 < V_216 )
F_98 ( V_62 -> V_41 , V_168 , V_193 ) ;
else switch ( V_193 ) {
case V_209 :
case V_217 :
case V_218 :
case V_219 :
F_103 ( V_62 -> V_41 , V_168 , V_193 ) ;
break;
default:
if ( V_62 == & V_62 -> V_41 -> V_214 )
F_53 ( & V_62 -> V_41 -> V_3 , V_168 ) ;
else
F_54 ( & V_62 -> V_41 -> V_3 , V_168 ) ;
break;
}
if ( V_62 == & V_62 -> V_41 -> V_220 ) {
V_168 -> V_109 = V_114 ;
V_168 -> V_151 ( V_168 , & V_62 -> V_41 -> V_3 , V_168 -> V_109 ) ;
}
}
static void F_108 ( struct V_142 * V_62 , struct V_90 * V_168 )
{
unsigned long V_152 ;
int V_56 ;
F_72 ( & V_62 -> V_41 -> V_153 , V_152 ) ;
if ( F_109 ( V_168 -> V_32 [ 0 ] ) == V_62 -> V_41 -> V_25 &&
V_62 -> V_41 -> V_26 == V_168 -> V_26 ) {
F_74 ( & V_62 -> V_41 -> V_153 , V_152 ) ;
F_106 ( V_62 , V_168 ) ;
return;
}
V_56 = F_88 ( V_62 , V_168 ) ;
F_74 ( & V_62 -> V_41 -> V_153 , V_152 ) ;
if ( V_56 < 0 )
V_168 -> V_151 ( V_168 , & V_62 -> V_41 -> V_3 , V_168 -> V_109 ) ;
}
static void F_110 ( struct V_1 * V_41 ,
const char * V_221 , unsigned int V_73 )
{
T_1 V_222 ;
V_222 = F_13 ( V_41 , F_35 ( V_73 ) ) ;
if ( V_222 & V_223 ) {
#ifdef F_111
F_20 ( L_43 ,
V_221 , V_36 [ V_222 & 0x1f ] ) ;
#else
F_20 ( L_44 ,
V_221 , V_222 & 0x1f ) ;
#endif
}
}
static void F_112 ( struct V_1 * V_41 )
{
unsigned int V_48 ;
char V_221 [ 8 ] ;
F_110 ( V_41 , L_45 , V_224 ) ;
F_110 ( V_41 , L_46 , V_225 ) ;
F_110 ( V_41 , L_47 , V_226 ) ;
F_110 ( V_41 , L_48 , V_227 ) ;
for ( V_48 = 0 ; V_48 < 32 ; ++ V_48 ) {
if ( ! ( V_41 -> V_228 & ( 1 << V_48 ) ) )
continue;
sprintf ( V_221 , L_49 , V_48 ) ;
F_110 ( V_41 , V_221 , F_113 ( V_48 ) ) ;
}
for ( V_48 = 0 ; V_48 < 32 ; ++ V_48 ) {
if ( ! ( V_41 -> V_229 & ( 1 << V_48 ) ) )
continue;
sprintf ( V_221 , L_50 , V_48 ) ;
F_110 ( V_41 , V_221 , F_114 ( V_48 ) ) ;
}
}
static T_1 F_115 ( T_1 V_230 )
{
T_1 V_231 ;
V_231 = V_230 & 0xfff ;
V_231 += 3072 * ( ( V_230 >> 12 ) & 0x1fff ) ;
V_231 += ( 3072 * 8000 ) * ( V_230 >> 25 ) ;
return V_231 ;
}
static T_1 F_116 ( struct V_1 * V_41 )
{
T_1 V_232 , V_233 , V_234 ;
T_1 V_235 , V_236 , V_237 ;
T_7 V_238 , V_239 ;
int V_48 ;
V_234 = F_13 ( V_41 , V_240 ) ;
if ( V_41 -> V_115 & V_241 ) {
V_48 = 0 ;
V_233 = V_234 ;
V_234 = F_13 ( V_41 , V_240 ) ;
do {
V_232 = V_233 ;
V_233 = V_234 ;
V_234 = F_13 ( V_41 , V_240 ) ;
V_235 = F_115 ( V_232 ) ;
V_236 = F_115 ( V_233 ) ;
V_237 = F_115 ( V_234 ) ;
V_238 = V_236 - V_235 ;
V_239 = V_237 - V_236 ;
} while ( ( V_238 <= 0 || V_239 <= 0 ||
V_238 / V_239 >= 2 || V_239 / V_238 >= 2 )
&& V_48 ++ < 20 );
}
return V_234 ;
}
static T_1 F_117 ( struct V_1 * V_41 )
{
T_1 V_242 = F_116 ( V_41 ) >> 25 ;
if ( ( V_41 -> V_243 & 0x40 ) != ( V_242 & 0x40 ) )
V_41 -> V_243 += 0x40 ;
return V_41 -> V_243 | V_242 ;
}
static void F_118 ( unsigned long V_43 )
{
struct V_1 * V_41 = (struct V_1 * ) V_43 ;
int V_27 , V_48 , V_244 , V_166 ;
int V_26 , V_245 ;
unsigned long V_152 ;
void * V_246 = NULL ;
T_2 V_247 = 0 ;
bool V_248 ;
V_166 = F_13 ( V_41 , V_249 ) ;
if ( ! ( V_166 & V_250 ) ) {
F_4 ( L_51 ) ;
return;
}
if ( ( V_166 & V_251 ) == 63 ) {
F_4 ( L_52 ) ;
return;
}
V_41 -> V_25 = V_166 & ( V_252 |
V_251 ) ;
V_248 = ( V_166 & V_253 ) != 0 ;
if ( ! ( V_41 -> V_254 && V_248 ) )
F_11 ( V_41 , V_255 ,
V_256 ) ;
V_41 -> V_254 = V_248 ;
V_166 = F_13 ( V_41 , V_257 ) ;
if ( V_166 & V_258 ) {
F_4 ( L_53 ) ;
return;
}
V_27 = ( V_166 >> 3 ) & 0xff ;
if ( V_27 == 0 || V_27 > 252 ) {
F_4 ( L_53 ) ;
return;
}
V_26 = ( F_52 ( V_41 -> V_259 [ 0 ] ) >> 16 ) & 0xff ;
F_47 () ;
for ( V_48 = 1 , V_244 = 0 ; V_244 < V_27 ; V_48 += 2 , V_244 ++ ) {
if ( V_41 -> V_259 [ V_48 ] != ~ V_41 -> V_259 [ V_48 + 1 ] ) {
F_4 ( L_53 ) ;
return;
}
V_41 -> V_260 [ V_244 ] =
F_52 ( V_41 -> V_259 [ V_48 ] ) ;
}
F_47 () ;
V_245 = ( F_13 ( V_41 , V_257 ) >> 16 ) & 0xff ;
if ( V_245 != V_26 ) {
F_4 ( L_54
L_55 ) ;
return;
}
F_72 ( & V_41 -> V_153 , V_152 ) ;
V_41 -> V_26 = - 1 ;
F_86 ( & V_41 -> V_214 ) ;
F_86 ( & V_41 -> V_220 ) ;
F_74 ( & V_41 -> V_153 , V_152 ) ;
F_94 ( & V_41 -> V_214 ) ;
F_94 ( & V_41 -> V_220 ) ;
F_72 ( & V_41 -> V_153 , V_152 ) ;
V_41 -> V_26 = V_26 ;
F_11 ( V_41 , V_261 , V_8 ) ;
if ( V_41 -> V_115 & V_116 )
V_41 -> V_111 = V_26 ;
if ( V_41 -> V_262 != NULL ) {
if ( V_41 -> V_262 != V_41 -> V_200 ) {
V_246 = V_41 -> V_200 ;
V_247 = V_41 -> V_263 ;
}
V_41 -> V_200 = V_41 -> V_262 ;
V_41 -> V_263 = V_41 -> V_264 ;
V_41 -> V_262 = NULL ;
F_11 ( V_41 , V_265 ,
F_10 ( V_41 -> V_200 [ 2 ] ) ) ;
V_41 -> V_200 [ 0 ] = V_41 -> V_266 ;
F_11 ( V_41 , V_267 ,
F_10 ( V_41 -> V_266 ) ) ;
}
#ifdef F_119
F_11 ( V_41 , V_268 , ~ 0 ) ;
F_11 ( V_41 , V_269 , ~ 0 ) ;
#endif
F_74 ( & V_41 -> V_153 , V_152 ) ;
if ( V_246 )
F_82 ( V_41 -> V_3 . V_78 , V_196 ,
V_246 , V_247 ) ;
F_6 ( V_41 -> V_25 , V_26 ,
V_27 , V_41 -> V_260 ) ;
F_120 ( & V_41 -> V_3 , V_41 -> V_25 , V_26 ,
V_27 , V_41 -> V_260 ,
V_41 -> V_270 ) ;
V_41 -> V_270 = false ;
}
static T_8 F_121 ( int V_271 , void * V_43 )
{
struct V_1 * V_41 = V_43 ;
T_1 V_272 , V_273 ;
int V_48 ;
V_272 = F_13 ( V_41 , V_261 ) ;
if ( ! V_272 || ! ~ V_272 )
return V_274 ;
F_11 ( V_41 , V_261 ,
V_272 & ~ ( V_8 | V_16 ) ) ;
F_2 ( V_272 ) ;
if ( V_272 & V_9 )
F_122 ( & V_41 -> F_118 ) ;
if ( V_272 & V_10 )
F_122 ( & V_41 -> V_117 . V_125 ) ;
if ( V_272 & V_11 )
F_122 ( & V_41 -> V_275 . V_125 ) ;
if ( V_272 & V_12 )
F_122 ( & V_41 -> V_214 . V_125 ) ;
if ( V_272 & V_13 )
F_122 ( & V_41 -> V_220 . V_125 ) ;
if ( V_272 & V_14 ) {
V_273 = F_13 ( V_41 , V_276 ) ;
F_11 ( V_41 , V_276 , V_273 ) ;
while ( V_273 ) {
V_48 = F_123 ( V_273 ) - 1 ;
F_122 (
& V_41 -> V_277 [ V_48 ] . V_142 . V_125 ) ;
V_273 &= ~ ( 1 << V_48 ) ;
}
}
if ( V_272 & V_15 ) {
V_273 = F_13 ( V_41 , V_278 ) ;
F_11 ( V_41 , V_278 , V_273 ) ;
while ( V_273 ) {
V_48 = F_123 ( V_273 ) - 1 ;
F_122 (
& V_41 -> V_279 [ V_48 ] . V_142 . V_125 ) ;
V_273 &= ~ ( 1 << V_48 ) ;
}
}
if ( F_8 ( V_272 & V_20 ) )
F_20 ( L_56
L_57 ) ;
if ( F_8 ( V_272 & V_16 ) ) {
F_13 ( V_41 , V_280 ) ;
F_13 ( V_41 , V_281 ) ;
F_11 ( V_41 , V_261 ,
V_16 ) ;
F_20 ( L_58 ) ;
}
if ( F_8 ( V_272 & V_17 ) ) {
if ( F_124 () )
F_4 ( L_59 ) ;
F_11 ( V_41 , V_255 ,
V_256 ) ;
}
if ( F_8 ( V_272 & V_19 ) ) {
if ( F_124 () )
F_4 ( L_60 ) ;
}
if ( F_8 ( V_272 & V_21 ) )
F_112 ( V_41 ) ;
if ( V_272 & V_18 ) {
F_125 ( & V_41 -> V_153 ) ;
F_117 ( V_41 ) ;
F_126 ( & V_41 -> V_153 ) ;
} else
F_15 ( V_41 ) ;
return V_282 ;
}
static int F_127 ( struct V_1 * V_41 )
{
T_1 V_47 ;
int V_48 ;
F_11 ( V_41 , V_283 , V_284 ) ;
for ( V_48 = 0 ; V_48 < 500 ; V_48 ++ ) {
V_47 = F_13 ( V_41 , V_283 ) ;
if ( ! ~ V_47 )
return - V_50 ;
if ( ! ( V_47 & V_284 ) )
return 0 ;
F_19 ( 1 ) ;
}
return - V_52 ;
}
static void F_128 ( V_39 * V_285 , const V_39 * V_286 , T_9 V_93 )
{
T_9 V_287 = V_93 * 4 ;
memcpy ( V_285 , V_286 , V_287 ) ;
if ( V_287 < V_196 )
memset ( & V_285 [ V_93 ] , 0 , V_196 - V_287 ) ;
}
static int F_129 ( struct V_1 * V_41 )
{
bool V_288 ;
int V_56 , V_289 , V_290 , V_42 ;
if ( ! ( F_13 ( V_41 , V_283 ) &
V_291 ) )
return 0 ;
V_288 = false ;
V_56 = F_16 ( V_41 , 2 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( ( V_56 & V_292 ) == V_292 ) {
V_56 = F_24 ( V_41 , 1 , 8 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( V_56 >= 1 )
V_288 = true ;
}
if ( V_41 -> V_115 & V_293 )
V_288 = false ;
if ( V_288 ) {
V_289 = 0 ;
V_290 = V_294 | V_295 ;
} else {
V_289 = V_294 | V_295 ;
V_290 = 0 ;
}
V_56 = F_23 ( V_41 , 5 , V_289 , V_290 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( V_288 )
V_42 = V_283 ;
else
V_42 = V_296 ;
F_11 ( V_41 , V_42 , V_297 ) ;
F_11 ( V_41 , V_296 ,
V_291 ) ;
return 0 ;
}
static int F_130 ( struct V_2 * V_3 ,
const V_39 * V_200 , T_9 V_93 )
{
struct V_1 * V_41 = V_1 ( V_3 ) ;
struct V_298 * V_299 = F_131 ( V_3 -> V_78 ) ;
T_1 V_300 , V_301 , V_302 , V_303 ;
int V_48 , V_56 ;
if ( F_127 ( V_41 ) ) {
F_20 ( L_61 ) ;
return - V_52 ;
}
F_11 ( V_41 , V_283 ,
V_304 |
V_305 ) ;
F_15 ( V_41 ) ;
for ( V_300 = 0 , V_48 = 0 ; ! V_300 && V_48 < 3 ; V_48 ++ ) {
F_19 ( 50 ) ;
V_300 = F_13 ( V_41 , V_283 ) &
V_304 ;
}
if ( ! V_300 ) {
F_20 ( L_62 ) ;
return - V_306 ;
}
F_11 ( V_41 , V_296 ,
V_307 ) ;
F_11 ( V_41 , V_308 , V_41 -> V_309 ) ;
F_11 ( V_41 , V_255 ,
V_310 |
V_256 ) ;
F_11 ( V_41 , V_311 ,
V_312 |
( V_313 << 4 ) |
( V_314 << 8 ) |
( 200 << 16 ) ) ;
V_301 = F_132 ( F_133 () ) ;
F_11 ( V_41 , V_240 , V_301 << 25 ) ;
V_41 -> V_243 = V_301 & ~ 0x3f ;
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
F_11 ( V_41 , V_261 , ~ 0 ) ;
F_11 ( V_41 , V_322 , ~ 0 ) ;
V_56 = F_129 ( V_41 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 = F_28 ( V_3 , 4 , 0 , V_323 | V_324 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( V_200 ) {
V_41 -> V_262 =
F_76 ( V_41 -> V_3 . V_78 , V_196 ,
& V_41 -> V_264 ,
V_126 ) ;
if ( V_41 -> V_262 == NULL )
return - V_139 ;
F_128 ( V_41 -> V_262 , V_200 , V_93 ) ;
} else {
V_41 -> V_262 = V_41 -> V_200 ;
V_41 -> V_264 = V_41 -> V_263 ;
}
V_41 -> V_266 = V_41 -> V_262 [ 0 ] ;
V_41 -> V_262 [ 0 ] = 0 ;
F_11 ( V_41 , V_267 , 0 ) ;
F_11 ( V_41 , V_265 ,
F_10 ( V_41 -> V_262 [ 2 ] ) ) ;
F_11 ( V_41 , V_325 , V_41 -> V_264 ) ;
F_11 ( V_41 , V_326 , 0x80000000 ) ;
if ( ! ( V_41 -> V_115 & V_327 ) )
F_134 ( V_299 ) ;
if ( F_135 ( V_299 -> V_271 , F_121 ,
F_136 ( V_299 ) ? 0 : V_328 ,
V_329 , V_41 ) ) {
F_20 ( L_63 , V_299 -> V_271 ) ;
F_137 ( V_299 ) ;
if ( V_200 ) {
F_82 ( V_41 -> V_3 . V_78 , V_196 ,
V_41 -> V_262 ,
V_41 -> V_264 ) ;
V_41 -> V_262 = NULL ;
}
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
F_11 ( V_41 , V_283 ,
V_332 |
V_333 ) ;
F_11 ( V_41 , V_255 ,
V_334 |
V_335 ) ;
F_66 ( & V_41 -> V_117 ) ;
F_66 ( & V_41 -> V_275 ) ;
F_15 ( V_41 ) ;
F_138 ( & V_41 -> V_3 , false , true ) ;
return 0 ;
}
static int F_139 ( struct V_2 * V_3 ,
const V_39 * V_200 , T_9 V_93 )
{
struct V_1 * V_41 ;
unsigned long V_152 ;
V_39 * V_262 ;
T_2 V_154 ( V_264 ) ;
V_41 = V_1 ( V_3 ) ;
V_262 =
F_76 ( V_41 -> V_3 . V_78 , V_196 ,
& V_264 , V_126 ) ;
if ( V_262 == NULL )
return - V_139 ;
F_72 ( & V_41 -> V_153 , V_152 ) ;
if ( V_41 -> V_262 == NULL ) {
V_41 -> V_262 = V_262 ;
V_41 -> V_264 = V_264 ;
V_262 = NULL ;
}
F_128 ( V_41 -> V_262 , V_200 , V_93 ) ;
V_41 -> V_266 = V_200 [ 0 ] ;
V_41 -> V_262 [ 0 ] = 0 ;
F_11 ( V_41 , V_325 , V_41 -> V_264 ) ;
F_74 ( & V_41 -> V_153 , V_152 ) ;
if ( V_262 != NULL )
F_82 ( V_41 -> V_3 . V_78 , V_196 ,
V_262 , V_264 ) ;
F_138 ( & V_41 -> V_3 , true , true ) ;
return 0 ;
}
static void F_140 ( struct V_2 * V_3 , struct V_90 * V_168 )
{
struct V_1 * V_41 = V_1 ( V_3 ) ;
F_108 ( & V_41 -> V_214 , V_168 ) ;
}
static void F_141 ( struct V_2 * V_3 , struct V_90 * V_168 )
{
struct V_1 * V_41 = V_1 ( V_3 ) ;
F_108 ( & V_41 -> V_220 , V_168 ) ;
}
static int F_142 ( struct V_2 * V_3 , struct V_90 * V_168 )
{
struct V_1 * V_41 = V_1 ( V_3 ) ;
struct V_142 * V_62 = & V_41 -> V_214 ;
struct V_170 * V_170 = V_168 -> V_170 ;
int V_56 = - V_336 ;
F_95 ( & V_62 -> V_125 ) ;
if ( V_168 -> V_109 != 0 )
goto V_208;
if ( V_168 -> V_178 )
F_93 ( V_41 -> V_3 . V_78 , V_168 -> V_169 ,
V_168 -> V_98 , V_177 ) ;
F_7 ( 'T' , V_168 -> V_29 , V_168 -> V_32 , 0x20 ) ;
V_170 -> V_168 = NULL ;
V_168 -> V_109 = V_183 ;
V_168 -> V_151 ( V_168 , & V_41 -> V_3 , V_168 -> V_109 ) ;
V_56 = 0 ;
V_208:
F_96 ( & V_62 -> V_125 ) ;
return V_56 ;
}
static int F_143 ( struct V_2 * V_3 ,
int V_25 , int V_26 )
{
#ifdef F_119
return 0 ;
#else
struct V_1 * V_41 = V_1 ( V_3 ) ;
unsigned long V_152 ;
int V_337 , V_56 = 0 ;
F_72 ( & V_41 -> V_153 , V_152 ) ;
if ( V_41 -> V_26 != V_26 ) {
V_56 = - V_338 ;
goto V_208;
}
V_337 = ( V_25 & 0xffc0 ) == V_339 ? V_25 & 0x3f : 63 ;
if ( V_337 < 32 )
F_11 ( V_41 , V_269 , 1 << V_337 ) ;
else
F_11 ( V_41 , V_268 , 1 << ( V_337 - 32 ) ) ;
F_15 ( V_41 ) ;
V_208:
F_74 ( & V_41 -> V_153 , V_152 ) ;
return V_56 ;
#endif
}
static T_1 F_144 ( struct V_2 * V_3 , int V_340 )
{
struct V_1 * V_41 = V_1 ( V_3 ) ;
unsigned long V_152 ;
T_1 V_341 ;
switch ( V_340 ) {
case V_342 :
case V_343 :
if ( V_41 -> V_254 &&
( F_13 ( V_41 , V_255 ) &
V_256 ) )
V_341 = V_344 ;
else
V_341 = 0 ;
if ( V_41 -> V_270 )
V_341 |= V_345 ;
return V_341 ;
case V_346 :
return F_13 ( V_41 , V_249 ) << 16 ;
case V_347 :
return F_116 ( V_41 ) ;
case V_348 :
F_72 ( & V_41 -> V_153 , V_152 ) ;
V_341 = F_117 ( V_41 ) ;
F_74 ( & V_41 -> V_153 , V_152 ) ;
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
unsigned long V_152 ;
switch ( V_340 ) {
case V_342 :
if ( ( V_341 & V_344 ) && V_41 -> V_254 ) {
F_11 ( V_41 , V_351 ,
V_256 ) ;
F_15 ( V_41 ) ;
}
if ( V_341 & V_345 )
V_41 -> V_270 = false ;
break;
case V_343 :
if ( ( V_341 & V_344 ) && V_41 -> V_254 ) {
F_11 ( V_41 , V_255 ,
V_256 ) ;
F_15 ( V_41 ) ;
}
if ( V_341 & V_345 )
V_41 -> V_270 = true ;
break;
case V_346 :
F_11 ( V_41 , V_249 , V_341 >> 16 ) ;
F_15 ( V_41 ) ;
break;
case V_347 :
F_11 ( V_41 , V_240 , V_341 ) ;
F_11 ( V_41 , V_352 ,
V_19 ) ;
F_15 ( V_41 ) ;
break;
case V_348 :
F_72 ( & V_41 -> V_153 , V_152 ) ;
V_41 -> V_243 = ( V_41 -> V_243 & 0x7f ) | ( V_341 & ~ 0x7f ) ;
F_74 ( & V_41 -> V_153 , V_152 ) ;
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
static void F_147 ( struct V_353 * V_62 , void * V_91 )
{
int V_48 = V_62 -> V_97 ;
if ( V_48 + V_62 -> V_354 . V_355 > V_70 )
return;
if ( V_62 -> V_354 . V_355 > 0 )
* ( T_1 * ) ( V_62 -> V_32 + V_48 ) = F_148 ( * ( T_1 * ) ( V_91 + 4 ) ) ;
if ( V_62 -> V_354 . V_355 > 4 )
* ( T_1 * ) ( V_62 -> V_32 + V_48 + 4 ) = F_148 ( * ( T_1 * ) V_91 ) ;
if ( V_62 -> V_354 . V_355 > 8 )
memcpy ( V_62 -> V_32 + V_48 + 8 , V_91 + 8 , V_62 -> V_354 . V_355 - 8 ) ;
V_62 -> V_97 += V_62 -> V_354 . V_355 ;
}
static int F_149 ( struct V_142 * V_142 ,
struct V_65 * V_66 ,
struct V_65 * V_84 )
{
struct V_353 * V_62 =
F_1 ( V_142 , struct V_353 , V_142 ) ;
struct V_65 * V_356 ;
T_4 * V_357 ;
void * V_91 ;
for ( V_356 = V_66 ; V_356 <= V_84 ; V_356 ++ )
if ( V_356 -> V_71 )
break;
if ( V_356 > V_84 )
return 0 ;
V_91 = V_84 + 1 ;
F_147 ( V_62 , V_91 ) ;
if ( F_48 ( V_84 -> V_134 ) & V_179 ) {
V_357 = ( T_4 * ) V_91 ;
V_62 -> V_354 . V_151 . V_358 ( & V_62 -> V_354 ,
F_71 ( V_357 [ 0 ] ) & 0xffff ,
V_62 -> V_97 , V_62 -> V_32 ,
V_62 -> V_354 . V_359 ) ;
V_62 -> V_97 = 0 ;
}
return 1 ;
}
static int F_150 ( struct V_142 * V_142 ,
struct V_65 * V_66 ,
struct V_65 * V_84 )
{
struct V_353 * V_62 =
F_1 ( V_142 , struct V_353 , V_142 ) ;
if ( ! V_84 -> V_71 )
return 0 ;
if ( F_48 ( V_84 -> V_134 ) & V_179 )
V_62 -> V_354 . V_151 . V_360 ( & V_62 -> V_354 ,
F_71 ( V_84 -> V_138 ) +
F_48 ( V_84 -> V_133 ) -
F_48 ( V_84 -> V_69 ) ,
V_62 -> V_354 . V_359 ) ;
return 1 ;
}
static int F_151 ( struct V_142 * V_142 ,
struct V_65 * V_66 ,
struct V_65 * V_84 )
{
struct V_353 * V_62 =
F_1 ( V_142 , struct V_353 , V_142 ) ;
int V_48 ;
struct V_65 * V_356 ;
for ( V_356 = V_66 ; V_356 <= V_84 ; V_356 ++ )
if ( V_356 -> V_71 )
break;
if ( V_356 > V_84 )
return 0 ;
V_48 = V_62 -> V_97 ;
if ( V_48 + 4 < V_70 ) {
* ( V_39 * ) ( V_62 -> V_32 + V_48 ) = F_105 (
( ( T_1 ) F_48 ( V_356 -> V_71 ) << 16 ) |
F_48 ( V_356 -> V_69 ) ) ;
V_62 -> V_97 += 4 ;
}
if ( F_48 ( V_84 -> V_134 ) & V_179 ) {
V_62 -> V_354 . V_151 . V_358 ( & V_62 -> V_354 , F_48 ( V_84 -> V_69 ) ,
V_62 -> V_97 , V_62 -> V_32 ,
V_62 -> V_354 . V_359 ) ;
V_62 -> V_97 = 0 ;
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
struct V_353 * V_154 ( V_62 ) ;
T_5 V_154 ( V_151 ) ;
T_6 * V_154 ( V_361 ) ;
T_1 * V_154 ( V_371 ) , V_154 ( V_73 ) ;
unsigned long V_152 ;
int V_64 , V_56 = - V_52 ;
F_72 ( & V_41 -> V_153 , V_152 ) ;
switch ( type ) {
case V_372 :
V_371 = & V_41 -> V_373 ;
V_151 = F_151 ;
V_64 = F_123 ( * V_371 ) - 1 ;
if ( V_64 >= 0 ) {
* V_371 &= ~ ( 1 << V_64 ) ;
V_73 = F_113 ( V_64 ) ;
V_62 = & V_41 -> V_279 [ V_64 ] ;
}
break;
case V_374 :
V_361 = & V_41 -> V_375 ;
V_371 = & V_41 -> V_376 ;
V_151 = F_149 ;
V_64 = * V_361 & 1ULL << V_370 ? F_123 ( * V_371 ) - 1 : - 1 ;
if ( V_64 >= 0 ) {
* V_361 &= ~ ( 1ULL << V_370 ) ;
* V_371 &= ~ ( 1 << V_64 ) ;
V_73 = F_114 ( V_64 ) ;
V_62 = & V_41 -> V_277 [ V_64 ] ;
}
break;
case V_377 :
V_371 = & V_41 -> V_376 ;
V_151 = F_150 ;
V_64 = ! V_41 -> V_378 ? F_123 ( * V_371 ) - 1 : - 1 ;
if ( V_64 >= 0 ) {
V_41 -> V_378 = true ;
* V_371 &= ~ ( 1 << V_64 ) ;
V_73 = F_114 ( V_64 ) ;
V_62 = & V_41 -> V_277 [ V_64 ] ;
}
break;
default:
V_64 = - 1 ;
V_56 = - V_379 ;
}
F_74 ( & V_41 -> V_153 , V_152 ) ;
if ( V_64 < 0 )
return F_155 ( V_56 ) ;
memset ( V_62 , 0 , sizeof( * V_62 ) ) ;
V_62 -> V_97 = 0 ;
V_62 -> V_32 = ( void * ) F_156 ( V_126 ) ;
if ( V_62 -> V_32 == NULL ) {
V_56 = - V_139 ;
goto V_208;
}
V_56 = F_78 ( & V_62 -> V_142 , V_41 , V_73 , V_151 ) ;
if ( V_56 < 0 )
goto V_380;
if ( type == V_377 )
F_152 ( V_41 , 0 ) ;
return & V_62 -> V_354 ;
V_380:
F_157 ( ( unsigned long ) V_62 -> V_32 ) ;
V_208:
F_72 ( & V_41 -> V_153 , V_152 ) ;
switch ( type ) {
case V_374 :
* V_361 |= 1ULL << V_370 ;
break;
case V_377 :
V_41 -> V_378 = false ;
break;
}
* V_371 |= 1 << V_64 ;
F_74 ( & V_41 -> V_153 , V_152 ) ;
return F_155 ( V_56 ) ;
}
static int F_158 ( struct V_369 * V_354 ,
T_7 V_381 , T_1 V_382 , T_1 V_383 )
{
struct V_353 * V_62 = F_1 ( V_354 , struct V_353 , V_354 ) ;
struct V_1 * V_41 = V_62 -> V_142 . V_41 ;
T_1 V_134 = V_384 , V_385 ;
int V_64 ;
if ( V_62 -> V_142 . V_84 -> V_68 == 0 )
return - V_386 ;
switch ( V_62 -> V_354 . type ) {
case V_372 :
V_64 = V_62 - V_41 -> V_279 ;
V_385 = 0 ;
if ( V_381 >= 0 )
V_385 = V_387 |
( V_381 & 0x7fff ) << 16 ;
F_11 ( V_41 , V_278 , 1 << V_64 ) ;
F_11 ( V_41 , V_388 , 1 << V_64 ) ;
F_84 ( & V_62 -> V_142 , V_385 ) ;
break;
case V_377 :
V_134 |= V_389 | V_390 ;
case V_374 :
V_64 = V_62 - V_41 -> V_277 ;
V_385 = ( V_383 << 28 ) | ( V_382 << 8 ) | V_62 -> V_354 . V_370 ;
if ( V_381 >= 0 ) {
V_385 |= ( V_381 & 0x07fff ) << 12 ;
V_134 |= V_391 ;
}
F_11 ( V_41 , V_276 , 1 << V_64 ) ;
F_11 ( V_41 , V_392 , 1 << V_64 ) ;
F_11 ( V_41 , F_159 ( V_62 -> V_142 . V_73 ) , V_385 ) ;
F_84 ( & V_62 -> V_142 , V_134 ) ;
V_62 -> V_382 = V_382 ;
V_62 -> V_383 = V_383 ;
break;
}
return 0 ;
}
static int F_160 ( struct V_369 * V_354 )
{
struct V_1 * V_41 = V_1 ( V_354 -> V_3 ) ;
struct V_353 * V_62 = F_1 ( V_354 , struct V_353 , V_354 ) ;
int V_64 ;
switch ( V_62 -> V_354 . type ) {
case V_372 :
V_64 = V_62 - V_41 -> V_279 ;
F_11 ( V_41 , V_393 , 1 << V_64 ) ;
break;
case V_374 :
case V_377 :
V_64 = V_62 - V_41 -> V_277 ;
F_11 ( V_41 , V_394 , 1 << V_64 ) ;
break;
}
F_15 ( V_41 ) ;
F_86 ( & V_62 -> V_142 ) ;
F_161 ( & V_62 -> V_142 . V_125 ) ;
return 0 ;
}
static void F_162 ( struct V_369 * V_354 )
{
struct V_1 * V_41 = V_1 ( V_354 -> V_3 ) ;
struct V_353 * V_62 = F_1 ( V_354 , struct V_353 , V_354 ) ;
unsigned long V_152 ;
int V_64 ;
F_160 ( V_354 ) ;
F_80 ( & V_62 -> V_142 ) ;
F_157 ( ( unsigned long ) V_62 -> V_32 ) ;
F_72 ( & V_41 -> V_153 , V_152 ) ;
switch ( V_354 -> type ) {
case V_372 :
V_64 = V_62 - V_41 -> V_279 ;
V_41 -> V_373 |= 1 << V_64 ;
break;
case V_374 :
V_64 = V_62 - V_41 -> V_277 ;
V_41 -> V_376 |= 1 << V_64 ;
V_41 -> V_375 |= 1ULL << V_354 -> V_370 ;
break;
case V_377 :
V_64 = V_62 - V_41 -> V_277 ;
V_41 -> V_376 |= 1 << V_64 ;
V_41 -> V_375 |= V_41 -> V_368 ;
V_41 -> V_368 = 0 ;
V_41 -> V_378 = false ;
break;
}
F_74 ( & V_41 -> V_153 , V_152 ) ;
}
static int F_163 ( struct V_369 * V_354 , T_6 * V_361 )
{
struct V_1 * V_41 = V_1 ( V_354 -> V_3 ) ;
unsigned long V_152 ;
int V_56 ;
switch ( V_354 -> type ) {
case V_377 :
F_72 ( & V_41 -> V_153 , V_152 ) ;
if ( ~ V_41 -> V_375 & ~ V_41 -> V_368 & * V_361 ) {
* V_361 = V_41 -> V_375 ;
V_56 = - V_52 ;
} else {
F_152 ( V_41 , * V_361 ) ;
V_56 = 0 ;
}
F_74 ( & V_41 -> V_153 , V_152 ) ;
break;
default:
V_56 = - V_395 ;
}
return V_56 ;
}
static void F_164 ( struct V_1 * V_41 )
{
int V_48 ;
struct V_353 * V_62 ;
for ( V_48 = 0 ; V_48 < V_41 -> V_396 ; V_48 ++ ) {
V_62 = & V_41 -> V_277 [ V_48 ] ;
if ( V_62 -> V_142 . V_165 )
F_158 ( & V_62 -> V_354 , 0 , V_62 -> V_382 , V_62 -> V_383 ) ;
}
for ( V_48 = 0 ; V_48 < V_41 -> V_397 ; V_48 ++ ) {
V_62 = & V_41 -> V_279 [ V_48 ] ;
if ( V_62 -> V_142 . V_165 )
F_158 ( & V_62 -> V_354 , 0 , V_62 -> V_382 , V_62 -> V_383 ) ;
}
}
static int F_165 ( struct V_353 * V_62 ,
struct V_398 * V_168 ,
struct V_399 * V_75 ,
unsigned long V_108 )
{
struct V_65 * V_66 , * V_84 , * V_356 ;
struct V_398 * V_91 ;
T_4 * V_32 ;
T_2 V_163 , V_400 ;
T_1 V_140 , V_401 , V_402 , V_271 ;
T_1 V_403 , V_404 , V_405 ;
int V_58 , V_406 , V_48 , V_93 , V_42 ;
V_91 = V_168 ;
V_403 = V_108 ;
if ( V_91 -> V_407 )
V_140 = 1 ;
else
V_140 = 2 ;
if ( V_91 -> V_97 > 0 )
V_140 ++ ;
V_406 = F_166 ( V_403 + V_91 -> V_98 ) >> V_408 ;
if ( V_91 -> V_98 > 0 )
V_402 = V_406 - ( V_403 >> V_408 ) ;
else
V_402 = 0 ;
V_140 += V_402 ;
V_401 = F_167 ( V_91 -> V_97 , sizeof( * V_66 ) ) ;
V_66 = F_83 ( & V_62 -> V_142 , V_140 + V_401 , & V_163 ) ;
if ( V_66 == NULL )
return - V_139 ;
if ( ! V_91 -> V_407 ) {
V_66 [ 0 ] . V_134 = F_33 ( V_172 ) ;
V_66 [ 0 ] . V_133 = F_33 ( 8 ) ;
V_66 [ 0 ] . V_68 = F_32 ( V_163 | V_140 ) ;
V_32 = ( T_4 * ) & V_66 [ 1 ] ;
V_32 [ 0 ] = F_32 ( F_168 ( V_91 -> V_409 ) |
F_169 ( V_91 -> V_410 ) |
F_170 ( V_175 ) |
F_171 ( V_62 -> V_354 . V_370 ) |
F_172 ( V_62 -> V_354 . V_29 ) ) ;
V_32 [ 1 ] =
F_32 ( F_173 ( V_91 -> V_97 +
V_91 -> V_98 ) ) ;
}
if ( V_91 -> V_97 > 0 ) {
V_66 [ 2 ] . V_133 = F_33 ( V_91 -> V_97 ) ;
V_66 [ 2 ] . V_138 = F_32 ( V_163 + V_140 * sizeof( * V_66 ) ) ;
memcpy ( & V_66 [ V_140 ] , V_91 -> V_32 , V_91 -> V_97 ) ;
}
V_356 = V_66 + V_140 - V_402 ;
V_404 = V_403 + V_91 -> V_98 ;
for ( V_48 = 0 ; V_48 < V_402 ; V_48 ++ ) {
V_58 = V_403 >> V_408 ;
V_42 = V_403 & ~ V_411 ;
V_405 = ( V_58 + 1 ) << V_408 ;
V_93 =
F_174 ( V_405 , V_404 ) - V_403 ;
V_356 [ V_48 ] . V_133 = F_33 ( V_93 ) ;
V_400 = F_30 ( V_75 -> V_63 [ V_58 ] ) ;
V_356 [ V_48 ] . V_138 = F_32 ( V_400 + V_42 ) ;
V_403 += V_93 ;
}
if ( V_91 -> V_412 )
V_271 = V_179 ;
else
V_271 = V_413 ;
V_84 = V_140 == 2 ? V_66 : V_66 + V_140 - 1 ;
V_84 -> V_134 |= F_33 ( V_160 |
V_136 |
V_137 |
V_271 ) ;
F_85 ( & V_62 -> V_142 , V_66 , V_140 , V_401 ) ;
return 0 ;
}
static int F_175 ( struct V_353 * V_62 ,
struct V_398 * V_168 ,
struct V_399 * V_75 ,
unsigned long V_108 )
{
struct V_65 * V_66 , * V_356 ;
T_2 V_163 , V_400 ;
T_1 V_140 , V_401 , V_414 ;
int V_48 , V_244 , V_93 ;
int V_58 , V_42 , V_415 , V_355 , V_416 ;
V_415 = V_168 -> V_97 / V_62 -> V_354 . V_355 ;
V_355 = F_176 ( V_62 -> V_354 . V_355 , ( T_9 ) 8 ) ;
V_401 = F_167 ( V_355 , sizeof( * V_66 ) ) ;
V_58 = V_108 >> V_408 ;
V_42 = V_108 & ~ V_411 ;
V_416 = V_168 -> V_98 / V_415 ;
for ( V_48 = 0 ; V_48 < V_415 ; V_48 ++ ) {
V_140 = F_167 ( V_416 + V_42 , V_70 ) + 1 ;
V_66 = F_83 ( & V_62 -> V_142 ,
V_140 + V_401 , & V_163 ) ;
if ( V_66 == NULL )
return - V_139 ;
V_66 -> V_134 = F_33 ( V_136 |
V_135 ) ;
if ( V_168 -> V_407 && V_48 == 0 )
V_66 -> V_134 |= F_33 ( V_417 ) ;
V_66 -> V_133 = F_33 ( V_355 ) ;
V_66 -> V_69 = V_66 -> V_133 ;
V_66 -> V_71 = 0 ;
V_66 -> V_138 = F_32 ( V_163 + ( V_140 * sizeof( * V_66 ) ) ) ;
V_414 = V_416 ;
V_356 = V_66 ;
for ( V_244 = 1 ; V_244 < V_140 ; V_244 ++ ) {
V_356 ++ ;
V_356 -> V_134 = F_33 ( V_136 |
V_135 ) ;
if ( V_42 + V_414 < V_70 )
V_93 = V_414 ;
else
V_93 = V_70 - V_42 ;
V_356 -> V_133 = F_33 ( V_93 ) ;
V_356 -> V_69 = V_356 -> V_133 ;
V_356 -> V_71 = 0 ;
V_400 = F_30 ( V_75 -> V_63 [ V_58 ] ) ;
V_356 -> V_138 = F_32 ( V_400 + V_42 ) ;
V_42 = ( V_42 + V_93 ) & ~ V_411 ;
V_414 -= V_93 ;
if ( V_42 == 0 )
V_58 ++ ;
}
V_356 -> V_134 = F_33 ( V_136 |
V_418 |
V_137 ) ;
if ( V_168 -> V_412 && V_48 == V_415 - 1 )
V_356 -> V_134 |= F_33 ( V_179 ) ;
F_85 ( & V_62 -> V_142 , V_66 , V_140 , V_401 ) ;
}
return 0 ;
}
static int F_177 ( struct V_353 * V_62 ,
struct V_398 * V_168 ,
struct V_399 * V_75 ,
unsigned long V_108 )
{
struct V_65 * V_66 ;
T_2 V_163 , V_400 ;
int V_58 , V_42 , V_414 , V_140 , V_48 , V_93 ;
V_58 = V_108 >> V_408 ;
V_42 = V_108 & ~ V_411 ;
V_414 = V_168 -> V_98 ;
V_140 = F_167 ( V_42 + V_414 , V_70 ) ;
if ( F_145 ( V_42 & 3 || V_414 & 3 || V_58 + V_140 > V_75 -> V_419 ) )
return - V_420 ;
for ( V_48 = 0 ; V_48 < V_140 ; V_48 ++ ) {
V_66 = F_83 ( & V_62 -> V_142 , 1 , & V_163 ) ;
if ( V_66 == NULL )
return - V_139 ;
V_66 -> V_134 = F_33 ( V_135 |
V_137 ) ;
if ( V_168 -> V_407 && V_48 == 0 )
V_66 -> V_134 |= F_33 ( V_417 ) ;
if ( V_168 -> V_412 && V_48 == V_140 - 1 )
V_66 -> V_134 |= F_33 ( V_179 ) ;
if ( V_42 + V_414 < V_70 )
V_93 = V_414 ;
else
V_93 = V_70 - V_42 ;
V_66 -> V_133 = F_33 ( V_93 ) ;
V_66 -> V_69 = V_66 -> V_133 ;
V_66 -> V_71 = 0 ;
V_400 = F_30 ( V_75 -> V_63 [ V_58 ] ) ;
V_66 -> V_138 = F_32 ( V_400 + V_42 ) ;
V_414 -= V_93 ;
V_42 = 0 ;
V_58 ++ ;
F_85 ( & V_62 -> V_142 , V_66 , 1 , 0 ) ;
}
return 0 ;
}
static int F_178 ( struct V_369 * V_354 ,
struct V_398 * V_168 ,
struct V_399 * V_75 ,
unsigned long V_108 )
{
struct V_353 * V_62 = F_1 ( V_354 , struct V_353 , V_354 ) ;
unsigned long V_152 ;
int V_56 = - V_379 ;
F_72 ( & V_62 -> V_142 . V_41 -> V_153 , V_152 ) ;
switch ( V_354 -> type ) {
case V_372 :
V_56 = F_165 ( V_62 , V_168 , V_75 , V_108 ) ;
break;
case V_374 :
V_56 = F_175 ( V_62 , V_168 , V_75 , V_108 ) ;
break;
case V_377 :
V_56 = F_177 ( V_62 , V_168 , V_75 , V_108 ) ;
break;
}
F_74 ( & V_62 -> V_142 . V_41 -> V_153 , V_152 ) ;
return V_56 ;
}
static void F_179 ( struct V_369 * V_354 )
{
struct V_142 * V_62 =
& F_1 ( V_354 , struct V_353 , V_354 ) -> V_142 ;
F_11 ( V_62 -> V_41 , F_35 ( V_62 -> V_73 ) , V_74 ) ;
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
V_41 = F_187 ( sizeof( * V_41 ) , V_126 ) ;
if ( V_41 == NULL ) {
V_432 = - V_139 ;
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
F_193 ( & V_41 -> V_153 ) ;
F_194 ( & V_41 -> V_60 ) ;
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
( V_443 [ V_48 ] . V_78 == ( unsigned short ) V_444 ||
V_443 [ V_48 ] . V_78 == V_299 -> V_78 ) &&
( V_443 [ V_48 ] . V_445 == ( unsigned short ) V_444 ||
V_443 [ V_48 ] . V_445 >= V_299 -> V_445 ) ) {
V_41 -> V_115 = V_443 [ V_48 ] . V_152 ;
break;
}
if ( V_446 )
V_41 -> V_115 = V_446 ;
F_91 ( V_76 * sizeof( struct V_65 ) > V_70 / 4 ) ;
F_91 ( V_447 > V_70 / 2 ) ;
V_41 -> V_130 = F_76 ( V_41 -> V_3 . V_78 ,
V_70 ,
& V_41 -> V_132 ,
V_126 ) ;
if ( ! V_41 -> V_130 ) {
V_432 = - V_139 ;
goto V_448;
}
V_432 = F_59 ( & V_41 -> V_117 , V_41 , 0 ,
V_449 ) ;
if ( V_432 < 0 )
goto V_450;
V_432 = F_59 ( & V_41 -> V_275 , V_41 , V_70 / 4 ,
V_451 ) ;
if ( V_432 < 0 )
goto V_452;
V_432 = F_78 ( & V_41 -> V_214 , V_41 ,
V_453 , F_97 ) ;
if ( V_432 < 0 )
goto V_454;
V_432 = F_78 ( & V_41 -> V_220 , V_41 ,
V_455 , F_97 ) ;
if ( V_432 < 0 )
goto V_456;
F_11 ( V_41 , V_392 , ~ 0 ) ;
V_41 -> V_375 = ~ 0ULL ;
V_41 -> V_229 = F_13 ( V_41 , V_392 ) ;
F_11 ( V_41 , V_394 , ~ 0 ) ;
V_41 -> V_376 = V_41 -> V_229 ;
V_41 -> V_396 = F_197 ( V_41 -> V_376 ) ;
V_287 = sizeof( struct V_353 ) * V_41 -> V_396 ;
V_41 -> V_277 = F_187 ( V_287 , V_126 ) ;
F_11 ( V_41 , V_388 , ~ 0 ) ;
V_41 -> V_228 = F_13 ( V_41 , V_388 ) ;
F_11 ( V_41 , V_393 , ~ 0 ) ;
V_41 -> V_373 = V_41 -> V_228 ;
V_41 -> V_397 = F_197 ( V_41 -> V_373 ) ;
V_287 = sizeof( struct V_353 ) * V_41 -> V_397 ;
V_41 -> V_279 = F_187 ( V_287 , V_126 ) ;
if ( V_41 -> V_279 == NULL || V_41 -> V_277 == NULL ) {
V_432 = - V_139 ;
goto V_457;
}
V_41 -> V_259 = V_41 -> V_130 + V_70 / 2 ;
V_41 -> V_309 = V_41 -> V_132 + V_70 / 2 ;
V_428 = F_13 ( V_41 , V_265 ) ;
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
V_41 -> V_396 , V_41 -> V_397 , V_41 -> V_115 ) ;
return 0 ;
V_457:
F_200 ( V_41 -> V_277 ) ;
F_200 ( V_41 -> V_279 ) ;
F_80 ( & V_41 -> V_220 ) ;
V_456:
F_80 ( & V_41 -> V_214 ) ;
V_454:
F_36 ( & V_41 -> V_275 ) ;
V_452:
F_36 ( & V_41 -> V_117 ) ;
V_450:
F_82 ( V_41 -> V_3 . V_78 , V_70 ,
V_41 -> V_130 , V_41 -> V_132 ) ;
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
if ( V_432 == - V_139 )
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
F_207 ( V_299 -> V_271 , V_41 ) ;
if ( V_41 -> V_262 && V_41 -> V_262 != V_41 -> V_200 )
F_82 ( V_41 -> V_3 . V_78 , V_196 ,
V_41 -> V_262 , V_41 -> V_264 ) ;
if ( V_41 -> V_200 )
F_82 ( V_41 -> V_3 . V_78 , V_196 ,
V_41 -> V_200 , V_41 -> V_263 ) ;
F_36 ( & V_41 -> V_117 ) ;
F_36 ( & V_41 -> V_275 ) ;
F_82 ( V_41 -> V_3 . V_78 , V_70 ,
V_41 -> V_130 , V_41 -> V_132 ) ;
F_80 ( & V_41 -> V_214 ) ;
F_80 ( & V_41 -> V_220 ) ;
F_200 ( V_41 -> V_279 ) ;
F_200 ( V_41 -> V_277 ) ;
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
F_207 ( V_299 -> V_271 , V_41 ) ;
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
