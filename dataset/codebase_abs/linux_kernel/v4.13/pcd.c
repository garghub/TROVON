static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
int V_8 ;
F_2 ( & V_9 ) ;
V_8 = F_3 ( & V_5 -> V_10 , V_2 , V_3 ) ;
F_4 ( & V_9 ) ;
return V_8 ;
}
static void F_5 ( struct V_11 * V_12 , T_1 V_3 )
{
struct V_4 * V_5 = V_12 -> V_7 ;
F_2 ( & V_9 ) ;
F_6 ( & V_5 -> V_10 , V_3 ) ;
F_4 ( & V_9 ) ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned V_13 , unsigned long V_14 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
int V_8 ;
F_2 ( & V_9 ) ;
V_8 = F_8 ( & V_5 -> V_10 , V_2 , V_3 , V_13 , V_14 ) ;
F_4 ( & V_9 ) ;
return V_8 ;
}
static unsigned int F_9 ( struct V_11 * V_12 ,
unsigned int V_15 )
{
struct V_4 * V_5 = V_12 -> V_7 ;
return F_10 ( & V_5 -> V_10 , V_15 ) ;
}
static void F_11 ( void )
{
struct V_4 * V_5 ;
int V_16 ;
V_17 = 0 ;
for ( V_16 = 0 , V_5 = V_18 ; V_16 < V_19 ; V_16 ++ , V_5 ++ ) {
struct V_11 * V_12 = F_12 ( 1 ) ;
if ( ! V_12 )
continue;
V_12 -> V_20 = F_13 ( V_21 , & V_22 ) ;
if ( ! V_12 -> V_20 ) {
F_14 ( V_12 ) ;
continue;
}
F_15 ( V_12 -> V_20 , V_23 ) ;
V_5 -> V_12 = V_12 ;
V_5 -> V_24 = & V_5 -> V_25 ;
V_5 -> V_26 = 0 ;
V_5 -> V_27 = 0 ;
V_5 -> V_28 = 1 ;
V_5 -> V_29 = ( * V_30 [ V_16 ] ) [ V_31 ] ;
if ( ( * V_30 [ V_16 ] ) [ V_32 ] )
V_17 ++ ;
V_5 -> V_33 = & V_5 -> V_10 . V_33 [ 0 ] ;
snprintf ( V_5 -> V_33 , sizeof( V_5 -> V_10 . V_33 ) , L_1 , V_33 , V_16 ) ;
V_5 -> V_10 . V_34 = & V_35 ;
V_5 -> V_10 . V_36 = V_5 ;
V_5 -> V_10 . V_37 = 0 ;
V_5 -> V_10 . V_38 = 1 ;
V_5 -> V_10 . V_39 = 0 ;
V_12 -> V_40 = V_40 ;
V_12 -> V_41 = V_16 ;
strcpy ( V_12 -> V_42 , V_5 -> V_33 ) ;
V_12 -> V_43 = & V_44 ;
V_12 -> V_45 = V_46 ;
}
}
static int F_16 ( struct V_47 * V_48 , int V_49 )
{
struct V_4 * V_5 = V_48 -> V_36 ;
if ( ! V_5 -> V_26 )
return - V_50 ;
return 0 ;
}
static void F_17 ( struct V_47 * V_48 )
{
}
static inline int F_18 ( struct V_4 * V_5 )
{
return F_19 ( V_5 -> V_24 , 1 , 6 ) ;
}
static inline int F_20 ( struct V_4 * V_5 , int V_51 )
{
return F_19 ( V_5 -> V_24 , 0 , V_51 ) ;
}
static inline void F_21 ( struct V_4 * V_5 , int V_51 , int V_52 )
{
F_22 ( V_5 -> V_24 , 0 , V_51 , V_52 ) ;
}
static int F_23 ( struct V_4 * V_5 , int V_53 , int V_54 , char * V_55 , char * V_56 )
{
int V_57 , V_58 , V_59 , V_60 , V_61 ;
V_57 = 0 ;
while ( ( ( ( V_58 = F_18 ( V_5 ) ) & V_53 ) || ( V_54 && ( ! ( V_58 & V_54 ) ) ) )
&& ( V_57 ++ < V_62 ) )
F_24 ( V_63 ) ;
if ( ( V_58 & ( V_64 & V_54 ) ) || ( V_57 > V_62 ) ) {
V_60 = F_20 ( V_5 , 7 ) ;
V_59 = F_20 ( V_5 , 1 ) ;
V_61 = F_20 ( V_5 , 2 ) ;
if ( V_57 > V_62 )
V_59 |= 0x100 ;
if ( V_55 )
F_25 ( L_2
L_3 ,
V_5 -> V_33 , V_55 , V_56 , V_58 , V_60 , V_59 , V_57 , V_61 ) ;
return ( V_60 << 8 ) + V_58 ;
}
return 0 ;
}
static int F_26 ( struct V_4 * V_5 , char * V_13 , int V_65 , char * V_55 )
{
F_27 ( V_5 -> V_24 ) ;
F_21 ( V_5 , 6 , 0xa0 + 0x10 * V_5 -> V_29 ) ;
if ( F_23 ( V_5 , V_66 | V_67 , 0 , V_55 , L_4 ) ) {
F_28 ( V_5 -> V_24 ) ;
return - 1 ;
}
F_21 ( V_5 , 4 , V_65 % 256 ) ;
F_21 ( V_5 , 5 , V_65 / 256 ) ;
F_21 ( V_5 , 7 , 0xa0 ) ;
if ( F_23 ( V_5 , V_66 , V_67 , V_55 , L_5 ) ) {
F_28 ( V_5 -> V_24 ) ;
return - 1 ;
}
if ( F_20 ( V_5 , 2 ) != 1 ) {
F_25 ( L_6 , V_5 -> V_33 , V_55 ) ;
F_28 ( V_5 -> V_24 ) ;
return - 1 ;
}
F_29 ( V_5 -> V_24 , V_13 , 12 ) ;
return 0 ;
}
static int F_30 ( struct V_4 * V_5 , char * V_68 , char * V_55 )
{
int V_58 , V_69 , V_61 , V_70 , V_71 , V_57 ;
V_58 = - 1 ;
V_71 = 0 ;
V_57 = 0 ;
if ( ! F_23 ( V_5 , V_66 , V_67 | V_72 | V_64 ,
V_55 , L_7 ) ) {
V_58 = 0 ;
while ( F_20 ( V_5 , 7 ) & V_67 ) {
V_69 = F_20 ( V_5 , 4 ) + 256 * F_20 ( V_5 , 5 ) ;
V_70 = ( V_69 + 3 ) & 0xfffc ;
V_61 = F_20 ( V_5 , 2 ) & 3 ;
if ( ( V_61 == 2 ) && ( V_70 > 0 ) && ( V_57 == 0 ) ) {
F_31 ( V_5 -> V_24 , V_68 , V_70 ) ;
if ( V_73 > 1 )
F_25 ( L_8 ,
V_5 -> V_33 , V_55 , V_70 ) ;
V_58 = 0 ;
V_57 ++ ;
} else {
if ( V_73 > 1 )
F_25
( L_9 ,
V_5 -> V_33 , V_55 , V_61 , V_69 , V_71 ) ;
if ( V_73 < 2 )
F_32 (
L_10 ,
V_5 -> V_33 ) ;
F_33 ( 1 ) ;
}
if ( V_71 ++ > V_74 ) {
F_25 ( L_11 , V_5 -> V_33 ) ;
break;
}
if ( F_23
( V_5 , V_66 , V_67 | V_72 | V_64 , V_55 ,
L_7 ) ) {
V_58 = - 1 ;
break;
}
}
}
F_28 ( V_5 -> V_24 ) ;
return V_58 ;
}
static void F_34 ( struct V_4 * V_5 , char * V_55 )
{
char V_75 [ 12 ] = { 0x03 , 0 , 0 , 0 , 16 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
char V_68 [ 16 ] ;
int V_58 , V_76 ;
V_58 = F_26 ( V_5 , V_75 , 16 , L_12 ) ;
F_33 ( 1 ) ;
if ( ! V_58 )
F_30 ( V_5 , V_68 , L_12 ) ;
V_5 -> V_27 = - 1 ;
V_76 = 2 ;
if ( ! V_58 ) {
if ( V_55 )
F_25 ( L_13 ,
V_5 -> V_33 , V_55 , V_68 [ 2 ] & 0xf , V_68 [ 12 ] , V_68 [ 13 ] ) ;
V_76 = V_68 [ 2 ] & 0xf ;
V_5 -> V_27 =
V_76 | ( ( V_68 [ 12 ] & 0xff ) << 8 ) | ( ( V_68 [ 13 ] & 0xff ) << 16 ) ;
}
if ( ( V_76 == 2 ) || ( V_76 == 6 ) )
V_5 -> V_28 = 1 ;
}
static int F_35 ( struct V_4 * V_5 , char * V_13 , int V_65 , char * V_68 , char * V_55 )
{
int V_58 ;
V_58 = F_26 ( V_5 , V_13 , V_65 , V_55 ) ;
F_33 ( 1 ) ;
if ( ! V_58 )
V_58 = F_30 ( V_5 , V_68 , V_55 ) ;
if ( V_58 )
F_34 ( V_5 , V_55 ) ;
return V_58 ;
}
static int F_36 ( struct V_47 * V_48 , struct V_77 * V_78 )
{
return F_35 ( V_48 -> V_36 , V_78 -> V_13 , V_78 -> V_79 , V_78 -> V_80 ,
L_14 ) ;
}
static unsigned int F_37 ( struct V_47 * V_48 ,
unsigned int V_15 , int V_81 )
{
struct V_4 * V_5 = V_48 -> V_36 ;
int V_82 = V_5 -> V_28 ;
if ( V_82 )
V_5 -> V_28 = 0 ;
return V_82 ? V_83 : 0 ;
}
static int F_38 ( struct V_47 * V_48 , int V_84 )
{
char V_85 [ 12 ] = { 0x1e , 0 , 0 , 0 , V_84 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
return F_35 ( V_48 -> V_36 , V_85 , 0 , V_86 ,
V_84 ? L_15 : L_16 ) ;
}
static int F_39 ( struct V_47 * V_48 , int V_87 )
{
char V_88 [ 12 ] = { 0x1b , 0 , 0 , 0 , 3 - V_87 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
return F_35 ( V_48 -> V_36 , V_88 , 0 , V_86 ,
V_87 ? L_17 : L_18 ) ;
}
static void F_40 ( int V_89 )
{
F_41 ( V_89 ) ;
}
static int F_42 ( struct V_4 * V_5 )
{
int V_90 , V_71 , V_91 ;
int V_92 [ 5 ] = { 1 , 1 , 1 , 0x14 , 0xeb } ;
F_27 ( V_5 -> V_24 ) ;
F_21 ( V_5 , 6 , 0xa0 + 0x10 * V_5 -> V_29 ) ;
F_21 ( V_5 , 7 , 8 ) ;
F_40 ( 20 * V_93 / 1000 ) ;
V_71 = 0 ;
while ( ( V_71 ++ < V_94 ) && ( F_18 ( V_5 ) & V_66 ) )
F_40 ( V_93 / 10 ) ;
V_91 = 1 ;
for ( V_90 = 0 ; V_90 < 5 ; V_90 ++ )
V_91 &= ( F_20 ( V_5 , V_90 + 1 ) == V_92 [ V_90 ] ) ;
if ( V_73 ) {
F_25 ( L_19 , V_5 -> V_33 , V_71 ) ;
for ( V_90 = 0 ; V_90 < 5 ; V_90 ++ )
F_25 ( L_20 , F_20 ( V_5 , V_90 + 1 ) ) ;
if ( ! V_91 )
F_25 ( L_21 ) ;
F_25 ( L_22 ) ;
}
F_28 ( V_5 -> V_24 ) ;
return V_91 - 1 ;
}
static int F_43 ( struct V_47 * V_48 )
{
return F_42 ( V_48 -> V_36 ) ;
}
static int F_44 ( struct V_4 * V_5 , int V_95 )
{
char V_96 [ 12 ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
int V_71 , V_61 ;
V_71 = 0 ;
while ( V_71 < V_95 ) {
V_5 -> V_27 = 0 ;
F_35 ( V_5 , V_96 , 0 , NULL , F_45 ( L_23 ) ) ;
V_61 = V_5 -> V_27 ;
if ( ! V_61 )
return 0 ;
if ( ! ( ( ( V_61 & 0xffff ) == 0x0402 ) || ( ( V_61 & 0xff ) == 6 ) ) )
return V_61 ;
V_71 ++ ;
F_40 ( V_93 ) ;
}
return 0x000020 ;
}
static int F_46 ( struct V_47 * V_48 , int V_81 )
{
char V_97 [ 12 ] = { 0x25 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
struct V_4 * V_5 = V_48 -> V_36 ;
if ( F_44 ( V_5 , V_98 ) )
return V_99 ;
if ( F_35 ( V_5 , V_97 , 8 , V_86 , F_45 ( L_24 ) ) )
return V_100 ;
return V_101 ;
}
static int F_47 ( struct V_4 * V_5 , char * V_102 )
{
int V_71 , V_60 ;
char V_103 [ 12 ] = { 0x12 , 0 , 0 , 0 , 36 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
V_104 = - 1 ;
V_60 = F_35 ( V_5 , V_103 , 36 , V_105 , L_25 ) ;
if ( V_60 )
return - 1 ;
if ( ( V_105 [ 0 ] & 0x1f ) != 5 ) {
if ( V_73 )
F_25 ( L_26 ,
V_5 -> V_33 , V_5 -> V_29 ? L_27 : L_28 ) ;
return - 1 ;
}
memcpy ( V_102 , V_105 + 16 , 16 ) ;
V_102 [ 16 ] = 0 ;
V_71 = 16 ;
while ( ( V_71 >= 0 ) && ( V_102 [ V_71 ] <= 0x20 ) ) {
V_102 [ V_71 ] = 0 ;
V_71 -- ;
}
F_25 ( L_29 , V_5 -> V_33 , V_5 -> V_29 ? L_27 : L_28 , V_102 ) ;
return 0 ;
}
static int F_48 ( struct V_4 * V_5 , int V_106 , char * V_102 )
{
if ( V_106 == - 1 ) {
for ( V_5 -> V_29 = 0 ; V_5 -> V_29 <= 1 ; V_5 -> V_29 ++ )
if ( ! F_42 ( V_5 ) && ! F_47 ( V_5 , V_102 ) )
return 0 ;
} else {
V_5 -> V_29 = V_106 ;
if ( ! F_42 ( V_5 ) && ! F_47 ( V_5 , V_102 ) )
return 0 ;
}
return - 1 ;
}
static void F_49 ( void )
{
int V_16 , V_58 ;
char V_80 [ 32 ] ;
char V_13 [ 12 ] = { 0x5a , 1 << 3 , 0x2a , 0 , 0 , 0 , 0 , 18 , 0 , 0 , 0 , 0 } ;
struct V_4 * V_5 ;
for ( V_16 = 0 , V_5 = V_18 ; V_16 < V_19 ; V_16 ++ , V_5 ++ ) {
if ( ! V_5 -> V_26 )
continue;
V_58 = F_35 ( V_5 , V_13 , 18 , V_80 , L_30 ) ;
if ( V_58 )
continue;
if ( ( V_80 [ 11 ] & 1 ) == 0 )
V_5 -> V_10 . V_39 |= V_107 ;
if ( ( V_80 [ 11 ] & 2 ) == 0 )
V_5 -> V_10 . V_39 |= V_108 ;
if ( ( V_80 [ 12 ] & 1 ) == 0 )
V_5 -> V_10 . V_39 |= V_109 ;
if ( ( V_80 [ 14 ] & 1 ) == 0 )
V_5 -> V_10 . V_39 |= V_110 ;
if ( ( V_80 [ 14 ] & 8 ) == 0 )
V_5 -> V_10 . V_39 |= V_111 ;
if ( ( V_80 [ 14 ] >> 6 ) == 0 )
V_5 -> V_10 . V_39 |= V_112 ;
}
}
static int F_50 ( void )
{
char V_102 [ 18 ] ;
int V_71 , V_16 ;
struct V_4 * V_5 ;
F_25 ( L_31 ,
V_33 , V_33 , V_113 , V_40 , V_114 ) ;
V_115 = F_51 ( V_33 ) ;
if ( ! V_115 ) {
F_52 ( L_32 , V_33 ) ;
return - 1 ;
}
V_71 = 0 ;
if ( V_17 == 0 ) {
V_5 = V_18 ;
if ( F_53 ( V_5 -> V_24 , 1 , - 1 , - 1 , - 1 , - 1 , - 1 , V_105 ,
V_116 , V_73 , V_5 -> V_33 ) ) {
if ( ! F_48 ( V_5 , - 1 , V_102 ) && V_5 -> V_12 ) {
V_5 -> V_26 = 1 ;
V_71 ++ ;
} else
F_54 ( V_5 -> V_24 ) ;
}
} else {
for ( V_16 = 0 , V_5 = V_18 ; V_16 < V_19 ; V_16 ++ , V_5 ++ ) {
int * V_117 = * V_30 [ V_16 ] ;
if ( ! V_117 [ V_32 ] )
continue;
if ( ! F_53 ( V_5 -> V_24 , 0 , V_117 [ V_32 ] , V_117 [ V_118 ] ,
V_117 [ V_119 ] , V_117 [ V_120 ] , V_117 [ V_121 ] ,
V_105 , V_116 , V_73 , V_5 -> V_33 ) )
continue;
if ( ! F_48 ( V_5 , V_117 [ V_31 ] , V_102 ) && V_5 -> V_12 ) {
V_5 -> V_26 = 1 ;
V_71 ++ ;
} else
F_54 ( V_5 -> V_24 ) ;
}
}
if ( V_71 )
return 0 ;
F_25 ( L_33 , V_33 ) ;
for ( V_16 = 0 , V_5 = V_18 ; V_16 < V_19 ; V_16 ++ , V_5 ++ )
F_14 ( V_5 -> V_12 ) ;
F_55 ( V_115 ) ;
return - 1 ;
}
static int F_56 ( void )
{
struct V_4 * V_5 ;
struct V_122 * V_123 ;
int V_124 = V_125 ;
do {
V_5 = & V_18 [ V_125 ] ;
V_123 = V_5 -> V_26 ? V_5 -> V_12 -> V_20 : NULL ;
if ( ++ V_125 == V_19 )
V_125 = 0 ;
if ( V_123 ) {
V_126 = F_57 ( V_123 ) ;
if ( V_126 )
break;
}
} while ( V_125 != V_124 );
return V_126 != NULL ;
}
static void F_58 ( void )
{
if ( V_127 )
return;
while ( 1 ) {
if ( ! V_126 && ! F_56 () )
return;
if ( F_59 ( V_126 ) == V_128 ) {
struct V_4 * V_5 = V_126 -> V_129 -> V_7 ;
if ( V_5 != V_130 )
V_104 = - 1 ;
V_130 = V_5 ;
V_131 = F_60 ( V_126 ) ;
V_132 = F_61 ( V_126 ) ;
V_133 = F_62 ( V_126 -> V_134 ) ;
V_127 = 1 ;
F_63 ( V_135 , NULL , 0 , V_114 ) ;
return;
} else {
F_64 ( V_126 , V_136 ) ;
V_126 = NULL ;
}
}
}
static void V_21 ( struct V_122 * V_123 )
{
F_58 () ;
}
static inline void F_65 ( T_2 V_137 )
{
unsigned long V_138 ;
F_66 ( & V_22 , V_138 ) ;
if ( ! F_67 ( V_126 , V_137 ) )
V_126 = NULL ;
V_127 = 0 ;
F_58 () ;
F_68 ( & V_22 , V_138 ) ;
}
static int F_69 ( void )
{
return ( ( ( F_18 ( V_130 ) & ( V_66 | V_67 ) ) == V_67 ) ) ;
}
static void F_70 ( void )
{
while ( V_132 && ( V_131 / 4 == V_104 ) ) {
int V_139 = ( V_131 % 4 ) * 512 ;
memcpy ( V_133 , V_105 + V_139 , 512 ) ;
V_132 -- ;
V_133 += 512 ;
V_131 ++ ;
}
}
static void F_71 ( void )
{
int V_140 , V_90 ;
char V_141 [ 12 ] = { 0xa8 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 } ;
V_104 = V_131 / 4 ;
V_140 = V_104 ;
for ( V_90 = 0 ; V_90 < 4 ; V_90 ++ ) {
V_141 [ 5 - V_90 ] = V_140 & 0xff ;
V_140 = V_140 >> 8 ;
}
if ( F_26 ( V_130 , V_141 , 2048 , L_34 ) ) {
V_104 = - 1 ;
F_65 ( V_136 ) ;
return;
}
F_33 ( 1 ) ;
F_63 ( V_142 , F_69 , V_74 , V_114 ) ;
}
static void V_135 ( void )
{
V_127 = 1 ;
V_143 = 0 ;
F_70 () ;
if ( ! V_132 ) {
F_65 ( 0 ) ;
return;
}
F_72 ( V_130 -> V_24 , F_71 ) ;
}
static void V_142 ( void )
{
unsigned long V_138 ;
if ( F_30 ( V_130 , V_105 , L_34 ) ) {
if ( V_143 < V_144 ) {
F_33 ( 1 ) ;
V_143 ++ ;
F_72 ( V_130 -> V_24 , F_71 ) ;
return;
}
V_104 = - 1 ;
F_65 ( V_136 ) ;
return;
}
V_135 () ;
F_66 ( & V_22 , V_138 ) ;
F_58 () ;
F_68 ( & V_22 , V_138 ) ;
}
static int F_73 ( struct V_47 * V_48 , unsigned int V_13 , void * V_14 )
{
struct V_4 * V_5 = V_48 -> V_36 ;
switch ( V_13 ) {
case V_145 :
{
char V_13 [ 12 ] =
{ V_146 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 12 ,
0 , 0 , 0 } ;
struct V_147 * V_148 =
(struct V_147 * ) V_14 ;
char V_80 [ 32 ] ;
int V_58 ;
V_58 = F_35 ( V_5 , V_13 , 12 , V_80 , L_35 ) ;
V_148 -> V_149 = V_80 [ 2 ] ;
V_148 -> V_150 = V_80 [ 3 ] ;
return V_58 ? - V_151 : 0 ;
}
case V_152 :
{
char V_13 [ 12 ] =
{ V_146 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 12 ,
0 , 0 , 0 } ;
struct V_153 * V_154 =
(struct V_153 * ) V_14 ;
unsigned char V_80 [ 32 ] ;
int V_58 ;
V_13 [ 1 ] =
( V_154 -> V_155 == V_156 ? 0x02 : 0 ) ;
V_13 [ 6 ] = V_154 -> V_157 ;
V_58 = F_35 ( V_5 , V_13 , 12 , V_80 , L_36 ) ;
V_154 -> V_158 = V_80 [ 5 ] & 0xf ;
V_154 -> V_159 = V_80 [ 5 ] >> 4 ;
V_154 -> V_160 =
( V_154 -> V_158 & 0x04 ) ? 1 : 0 ;
if ( V_154 -> V_155 == V_156 ) {
V_154 -> V_161 . V_162 . V_163 = V_80 [ 9 ] ;
V_154 -> V_161 . V_162 . V_164 = V_80 [ 10 ] ;
V_154 -> V_161 . V_162 . V_165 = V_80 [ 11 ] ;
} else
V_154 -> V_161 . V_166 =
( ( ( ( ( V_80 [ 8 ] << 8 ) + V_80 [ 9 ] ) << 8 )
+ V_80 [ 10 ] ) << 8 ) + V_80 [ 11 ] ;
return V_58 ? - V_151 : 0 ;
}
default:
return - V_167 ;
}
}
static int F_74 ( struct V_47 * V_48 , struct V_168 * V_169 )
{
char V_13 [ 12 ] =
{ V_170 , 0 , 0x40 , 2 , 0 , 0 , 0 , 0 , 24 , 0 , 0 , 0 } ;
char V_80 [ 32 ] ;
if ( F_35 ( V_48 -> V_36 , V_13 , 24 , V_80 , L_37 ) )
return - V_151 ;
memcpy ( V_169 -> V_171 , V_80 + 9 , 13 ) ;
V_169 -> V_171 [ 13 ] = 0 ;
return 0 ;
}
static int T_3 F_75 ( void )
{
struct V_4 * V_5 ;
int V_16 ;
if ( V_172 )
return - V_173 ;
F_11 () ;
if ( F_50 () )
return - V_50 ;
F_49 () ;
if ( F_76 ( V_40 , V_33 ) ) {
for ( V_16 = 0 , V_5 = V_18 ; V_16 < V_19 ; V_16 ++ , V_5 ++ )
F_14 ( V_5 -> V_12 ) ;
return - V_174 ;
}
for ( V_16 = 0 , V_5 = V_18 ; V_16 < V_19 ; V_16 ++ , V_5 ++ ) {
if ( V_5 -> V_26 ) {
F_77 ( & V_5 -> V_10 ) ;
V_5 -> V_12 -> V_7 = V_5 ;
F_78 ( V_5 -> V_12 ) ;
}
}
return 0 ;
}
static void T_4 F_79 ( void )
{
struct V_4 * V_5 ;
int V_16 ;
for ( V_16 = 0 , V_5 = V_18 ; V_16 < V_19 ; V_16 ++ , V_5 ++ ) {
if ( V_5 -> V_26 ) {
F_80 ( V_5 -> V_12 ) ;
F_54 ( V_5 -> V_24 ) ;
F_81 ( & V_5 -> V_10 ) ;
}
F_82 ( V_5 -> V_12 -> V_20 ) ;
F_14 ( V_5 -> V_12 ) ;
}
F_83 ( V_40 , V_33 ) ;
F_55 ( V_115 ) ;
}
