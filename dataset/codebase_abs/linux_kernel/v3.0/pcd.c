static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
int V_8 ;
F_2 ( & V_9 ) ;
V_8 = F_3 ( & V_5 -> V_10 , V_2 , V_3 ) ;
F_4 ( & V_9 ) ;
return V_8 ;
}
static int F_5 ( struct V_11 * V_12 , T_1 V_3 )
{
struct V_4 * V_5 = V_12 -> V_7 ;
F_2 ( & V_9 ) ;
F_6 ( & V_5 -> V_10 , V_3 ) ;
F_4 ( & V_9 ) ;
return 0 ;
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
V_5 -> V_12 = V_12 ;
V_5 -> V_20 = & V_5 -> V_21 ;
V_5 -> V_22 = 0 ;
V_5 -> V_23 = 0 ;
V_5 -> V_24 = 1 ;
V_5 -> V_25 = ( * V_26 [ V_16 ] ) [ V_27 ] ;
if ( ( * V_26 [ V_16 ] ) [ V_28 ] )
V_17 ++ ;
V_5 -> V_29 = & V_5 -> V_10 . V_29 [ 0 ] ;
snprintf ( V_5 -> V_29 , sizeof( V_5 -> V_10 . V_29 ) , L_1 , V_29 , V_16 ) ;
V_5 -> V_10 . V_30 = & V_31 ;
V_5 -> V_10 . V_32 = V_5 ;
V_5 -> V_10 . V_33 = 0 ;
V_5 -> V_10 . V_34 = 1 ;
V_5 -> V_10 . V_35 = 0 ;
V_12 -> V_36 = V_36 ;
V_12 -> V_37 = V_16 ;
strcpy ( V_12 -> V_38 , V_5 -> V_29 ) ;
V_12 -> V_39 = & V_40 ;
V_12 -> V_41 = V_42 ;
}
}
static int F_13 ( struct V_43 * V_44 , int V_45 )
{
struct V_4 * V_5 = V_44 -> V_32 ;
if ( ! V_5 -> V_22 )
return - V_46 ;
return 0 ;
}
static void F_14 ( struct V_43 * V_44 )
{
}
static inline int F_15 ( struct V_4 * V_5 )
{
return F_16 ( V_5 -> V_20 , 1 , 6 ) ;
}
static inline int F_17 ( struct V_4 * V_5 , int V_47 )
{
return F_16 ( V_5 -> V_20 , 0 , V_47 ) ;
}
static inline void F_18 ( struct V_4 * V_5 , int V_47 , int V_48 )
{
F_19 ( V_5 -> V_20 , 0 , V_47 , V_48 ) ;
}
static int F_20 ( struct V_4 * V_5 , int V_49 , int V_50 , char * V_51 , char * V_52 )
{
int V_53 , V_54 , V_55 , V_56 , V_57 ;
V_53 = 0 ;
while ( ( ( ( V_54 = F_15 ( V_5 ) ) & V_49 ) || ( V_50 && ( ! ( V_54 & V_50 ) ) ) )
&& ( V_53 ++ < V_58 ) )
F_21 ( V_59 ) ;
if ( ( V_54 & ( V_60 & V_50 ) ) || ( V_53 > V_58 ) ) {
V_56 = F_17 ( V_5 , 7 ) ;
V_55 = F_17 ( V_5 , 1 ) ;
V_57 = F_17 ( V_5 , 2 ) ;
if ( V_53 > V_58 )
V_55 |= 0x100 ;
if ( V_51 )
F_22 ( L_2
L_3 ,
V_5 -> V_29 , V_51 , V_52 , V_54 , V_56 , V_55 , V_53 , V_57 ) ;
return ( V_56 << 8 ) + V_54 ;
}
return 0 ;
}
static int F_23 ( struct V_4 * V_5 , char * V_13 , int V_61 , char * V_51 )
{
F_24 ( V_5 -> V_20 ) ;
F_18 ( V_5 , 6 , 0xa0 + 0x10 * V_5 -> V_25 ) ;
if ( F_20 ( V_5 , V_62 | V_63 , 0 , V_51 , L_4 ) ) {
F_25 ( V_5 -> V_20 ) ;
return - 1 ;
}
F_18 ( V_5 , 4 , V_61 % 256 ) ;
F_18 ( V_5 , 5 , V_61 / 256 ) ;
F_18 ( V_5 , 7 , 0xa0 ) ;
if ( F_20 ( V_5 , V_62 , V_63 , V_51 , L_5 ) ) {
F_25 ( V_5 -> V_20 ) ;
return - 1 ;
}
if ( F_17 ( V_5 , 2 ) != 1 ) {
F_22 ( L_6 , V_5 -> V_29 , V_51 ) ;
F_25 ( V_5 -> V_20 ) ;
return - 1 ;
}
F_26 ( V_5 -> V_20 , V_13 , 12 ) ;
return 0 ;
}
static int F_27 ( struct V_4 * V_5 , char * V_64 , char * V_51 )
{
int V_54 , V_65 , V_57 , V_66 , V_67 , V_53 ;
V_54 = - 1 ;
V_67 = 0 ;
V_53 = 0 ;
if ( ! F_20 ( V_5 , V_62 , V_63 | V_68 | V_60 ,
V_51 , L_7 ) ) {
V_54 = 0 ;
while ( F_17 ( V_5 , 7 ) & V_63 ) {
V_65 = F_17 ( V_5 , 4 ) + 256 * F_17 ( V_5 , 5 ) ;
V_66 = ( V_65 + 3 ) & 0xfffc ;
V_57 = F_17 ( V_5 , 2 ) & 3 ;
if ( ( V_57 == 2 ) && ( V_66 > 0 ) && ( V_53 == 0 ) ) {
F_28 ( V_5 -> V_20 , V_64 , V_66 ) ;
if ( V_69 > 1 )
F_22 ( L_8 ,
V_5 -> V_29 , V_51 , V_66 ) ;
V_54 = 0 ;
V_53 ++ ;
} else {
if ( V_69 > 1 )
F_22
( L_9 ,
V_5 -> V_29 , V_51 , V_57 , V_65 , V_67 ) ;
if ( V_69 < 2 )
F_29 (
L_10 ,
V_5 -> V_29 ) ;
F_30 ( 1 ) ;
}
if ( V_67 ++ > V_70 ) {
F_22 ( L_11 , V_5 -> V_29 ) ;
break;
}
if ( F_20
( V_5 , V_62 , V_63 | V_68 | V_60 , V_51 ,
L_7 ) ) {
V_54 = - 1 ;
break;
}
}
}
F_25 ( V_5 -> V_20 ) ;
return V_54 ;
}
static void F_31 ( struct V_4 * V_5 , char * V_51 )
{
char V_71 [ 12 ] = { 0x03 , 0 , 0 , 0 , 16 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
char V_64 [ 16 ] ;
int V_54 , V_72 ;
V_54 = F_23 ( V_5 , V_71 , 16 , L_12 ) ;
F_30 ( 1 ) ;
if ( ! V_54 )
F_27 ( V_5 , V_64 , L_12 ) ;
V_5 -> V_23 = - 1 ;
V_72 = 2 ;
if ( ! V_54 ) {
if ( V_51 )
F_22 ( L_13 ,
V_5 -> V_29 , V_51 , V_64 [ 2 ] & 0xf , V_64 [ 12 ] , V_64 [ 13 ] ) ;
V_72 = V_64 [ 2 ] & 0xf ;
V_5 -> V_23 =
V_72 | ( ( V_64 [ 12 ] & 0xff ) << 8 ) | ( ( V_64 [ 13 ] & 0xff ) << 16 ) ;
}
if ( ( V_72 == 2 ) || ( V_72 == 6 ) )
V_5 -> V_24 = 1 ;
}
static int F_32 ( struct V_4 * V_5 , char * V_13 , int V_61 , char * V_64 , char * V_51 )
{
int V_54 ;
V_54 = F_23 ( V_5 , V_13 , V_61 , V_51 ) ;
F_30 ( 1 ) ;
if ( ! V_54 )
V_54 = F_27 ( V_5 , V_64 , V_51 ) ;
if ( V_54 )
F_31 ( V_5 , V_51 ) ;
return V_54 ;
}
static int F_33 ( struct V_43 * V_44 , struct V_73 * V_74 )
{
return F_32 ( V_44 -> V_32 , V_74 -> V_13 , V_74 -> V_75 , V_74 -> V_76 ,
L_14 ) ;
}
static unsigned int F_34 ( struct V_43 * V_44 ,
unsigned int V_15 , int V_77 )
{
struct V_4 * V_5 = V_44 -> V_32 ;
int V_78 = V_5 -> V_24 ;
if ( V_78 )
V_5 -> V_24 = 0 ;
return V_78 ? V_79 : 0 ;
}
static int F_35 ( struct V_43 * V_44 , int V_80 )
{
char V_81 [ 12 ] = { 0x1e , 0 , 0 , 0 , V_80 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
return F_32 ( V_44 -> V_32 , V_81 , 0 , V_82 ,
V_80 ? L_15 : L_16 ) ;
}
static int F_36 ( struct V_43 * V_44 , int V_83 )
{
char V_84 [ 12 ] = { 0x1b , 0 , 0 , 0 , 3 - V_83 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
return F_32 ( V_44 -> V_32 , V_84 , 0 , V_82 ,
V_83 ? L_17 : L_18 ) ;
}
static void F_37 ( int V_85 )
{
F_38 ( V_85 ) ;
}
static int F_39 ( struct V_4 * V_5 )
{
int V_86 , V_67 , V_87 ;
int V_88 [ 5 ] = { 1 , 1 , 1 , 0x14 , 0xeb } ;
F_24 ( V_5 -> V_20 ) ;
F_18 ( V_5 , 6 , 0xa0 + 0x10 * V_5 -> V_25 ) ;
F_18 ( V_5 , 7 , 8 ) ;
F_37 ( 20 * V_89 / 1000 ) ;
V_67 = 0 ;
while ( ( V_67 ++ < V_90 ) && ( F_15 ( V_5 ) & V_62 ) )
F_37 ( V_89 / 10 ) ;
V_87 = 1 ;
for ( V_86 = 0 ; V_86 < 5 ; V_86 ++ )
V_87 &= ( F_17 ( V_5 , V_86 + 1 ) == V_88 [ V_86 ] ) ;
if ( V_69 ) {
F_22 ( L_19 , V_5 -> V_29 , V_67 ) ;
for ( V_86 = 0 ; V_86 < 5 ; V_86 ++ )
F_22 ( L_20 , F_17 ( V_5 , V_86 + 1 ) ) ;
if ( ! V_87 )
F_22 ( L_21 ) ;
F_22 ( L_22 ) ;
}
F_25 ( V_5 -> V_20 ) ;
return V_87 - 1 ;
}
static int F_40 ( struct V_43 * V_44 )
{
return F_39 ( V_44 -> V_32 ) ;
}
static int F_41 ( struct V_4 * V_5 , int V_91 )
{
char V_92 [ 12 ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
int V_67 , V_57 ;
V_67 = 0 ;
while ( V_67 < V_91 ) {
V_5 -> V_23 = 0 ;
F_32 ( V_5 , V_92 , 0 , NULL , F_42 ( L_23 ) ) ;
V_57 = V_5 -> V_23 ;
if ( ! V_57 )
return 0 ;
if ( ! ( ( ( V_57 & 0xffff ) == 0x0402 ) || ( ( V_57 & 0xff ) == 6 ) ) )
return V_57 ;
V_67 ++ ;
F_37 ( V_89 ) ;
}
return 0x000020 ;
}
static int F_43 ( struct V_43 * V_44 , int V_77 )
{
char V_93 [ 12 ] = { 0x25 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
struct V_4 * V_5 = V_44 -> V_32 ;
if ( F_41 ( V_5 , V_94 ) )
return V_95 ;
if ( F_32 ( V_5 , V_93 , 8 , V_82 , F_42 ( L_24 ) ) )
return V_96 ;
return V_97 ;
}
static int F_44 ( struct V_4 * V_5 , char * V_98 )
{
int V_67 , V_56 ;
char V_99 [ 12 ] = { 0x12 , 0 , 0 , 0 , 36 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
V_100 = - 1 ;
V_56 = F_32 ( V_5 , V_99 , 36 , V_101 , L_25 ) ;
if ( V_56 )
return - 1 ;
if ( ( V_101 [ 0 ] & 0x1f ) != 5 ) {
if ( V_69 )
F_22 ( L_26 ,
V_5 -> V_29 , V_5 -> V_25 ? L_27 : L_28 ) ;
return - 1 ;
}
memcpy ( V_98 , V_101 + 16 , 16 ) ;
V_98 [ 16 ] = 0 ;
V_67 = 16 ;
while ( ( V_67 >= 0 ) && ( V_98 [ V_67 ] <= 0x20 ) ) {
V_98 [ V_67 ] = 0 ;
V_67 -- ;
}
F_22 ( L_29 , V_5 -> V_29 , V_5 -> V_25 ? L_27 : L_28 , V_98 ) ;
return 0 ;
}
static int F_45 ( struct V_4 * V_5 , int V_102 , char * V_98 )
{
if ( V_102 == - 1 ) {
for ( V_5 -> V_25 = 0 ; V_5 -> V_25 <= 1 ; V_5 -> V_25 ++ )
if ( ! F_39 ( V_5 ) && ! F_44 ( V_5 , V_98 ) )
return 0 ;
} else {
V_5 -> V_25 = V_102 ;
if ( ! F_39 ( V_5 ) && ! F_44 ( V_5 , V_98 ) )
return 0 ;
}
return - 1 ;
}
static void F_46 ( void )
{
int V_16 , V_54 ;
char V_76 [ 32 ] ;
char V_13 [ 12 ] = { 0x5a , 1 << 3 , 0x2a , 0 , 0 , 0 , 0 , 18 , 0 , 0 , 0 , 0 } ;
struct V_4 * V_5 ;
for ( V_16 = 0 , V_5 = V_18 ; V_16 < V_19 ; V_16 ++ , V_5 ++ ) {
if ( ! V_5 -> V_22 )
continue;
V_54 = F_32 ( V_5 , V_13 , 18 , V_76 , L_30 ) ;
if ( V_54 )
continue;
if ( ( V_76 [ 11 ] & 1 ) == 0 )
V_5 -> V_10 . V_35 |= V_103 ;
if ( ( V_76 [ 11 ] & 2 ) == 0 )
V_5 -> V_10 . V_35 |= V_104 ;
if ( ( V_76 [ 12 ] & 1 ) == 0 )
V_5 -> V_10 . V_35 |= V_105 ;
if ( ( V_76 [ 14 ] & 1 ) == 0 )
V_5 -> V_10 . V_35 |= V_106 ;
if ( ( V_76 [ 14 ] & 8 ) == 0 )
V_5 -> V_10 . V_35 |= V_107 ;
if ( ( V_76 [ 14 ] >> 6 ) == 0 )
V_5 -> V_10 . V_35 |= V_108 ;
}
}
static int F_47 ( void )
{
char V_98 [ 18 ] ;
int V_67 , V_16 ;
struct V_4 * V_5 ;
F_22 ( L_31 ,
V_29 , V_29 , V_109 , V_36 , V_110 ) ;
V_67 = 0 ;
if ( V_17 == 0 ) {
V_5 = V_18 ;
if ( F_48 ( V_5 -> V_20 , 1 , - 1 , - 1 , - 1 , - 1 , - 1 , V_101 ,
V_111 , V_69 , V_5 -> V_29 ) ) {
if ( ! F_45 ( V_5 , - 1 , V_98 ) && V_5 -> V_12 ) {
V_5 -> V_22 = 1 ;
V_67 ++ ;
} else
F_49 ( V_5 -> V_20 ) ;
}
} else {
for ( V_16 = 0 , V_5 = V_18 ; V_16 < V_19 ; V_16 ++ , V_5 ++ ) {
int * V_112 = * V_26 [ V_16 ] ;
if ( ! V_112 [ V_28 ] )
continue;
if ( ! F_48 ( V_5 -> V_20 , 0 , V_112 [ V_28 ] , V_112 [ V_113 ] ,
V_112 [ V_114 ] , V_112 [ V_115 ] , V_112 [ V_116 ] ,
V_101 , V_111 , V_69 , V_5 -> V_29 ) )
continue;
if ( ! F_45 ( V_5 , V_112 [ V_27 ] , V_98 ) && V_5 -> V_12 ) {
V_5 -> V_22 = 1 ;
V_67 ++ ;
} else
F_49 ( V_5 -> V_20 ) ;
}
}
if ( V_67 )
return 0 ;
F_22 ( L_32 , V_29 ) ;
for ( V_16 = 0 , V_5 = V_18 ; V_16 < V_19 ; V_16 ++ , V_5 ++ )
F_50 ( V_5 -> V_12 ) ;
return - 1 ;
}
static void F_51 ( struct V_117 * V_118 )
{
if ( V_119 )
return;
while ( 1 ) {
if ( ! V_120 ) {
V_120 = F_52 ( V_118 ) ;
if ( ! V_120 )
return;
}
if ( F_53 ( V_120 ) == V_121 ) {
struct V_4 * V_5 = V_120 -> V_122 -> V_7 ;
if ( V_5 != V_123 )
V_100 = - 1 ;
V_123 = V_5 ;
V_124 = F_54 ( V_120 ) ;
V_125 = F_55 ( V_120 ) ;
V_126 = V_120 -> V_76 ;
V_119 = 1 ;
F_56 ( V_127 , NULL , 0 , V_110 ) ;
return;
} else {
F_57 ( V_120 , - V_128 ) ;
V_120 = NULL ;
}
}
}
static inline void F_58 ( int V_129 )
{
unsigned long V_130 ;
F_59 ( & V_131 , V_130 ) ;
if ( ! F_60 ( V_120 , V_129 ) )
V_120 = NULL ;
V_119 = 0 ;
F_51 ( V_132 ) ;
F_61 ( & V_131 , V_130 ) ;
}
static int F_62 ( void )
{
return ( ( ( F_15 ( V_123 ) & ( V_62 | V_63 ) ) == V_63 ) ) ;
}
static void F_63 ( void )
{
while ( V_125 && ( V_124 / 4 == V_100 ) ) {
int V_133 = ( V_124 % 4 ) * 512 ;
memcpy ( V_126 , V_101 + V_133 , 512 ) ;
V_125 -- ;
V_126 += 512 ;
V_124 ++ ;
}
}
static void F_64 ( void )
{
int V_134 , V_86 ;
char V_135 [ 12 ] = { 0xa8 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 } ;
V_100 = V_124 / 4 ;
V_134 = V_100 ;
for ( V_86 = 0 ; V_86 < 4 ; V_86 ++ ) {
V_135 [ 5 - V_86 ] = V_134 & 0xff ;
V_134 = V_134 >> 8 ;
}
if ( F_23 ( V_123 , V_135 , 2048 , L_33 ) ) {
V_100 = - 1 ;
F_58 ( - V_128 ) ;
return;
}
F_30 ( 1 ) ;
F_56 ( V_136 , F_62 , V_70 , V_110 ) ;
}
static void V_127 ( void )
{
V_119 = 1 ;
V_137 = 0 ;
F_63 () ;
if ( ! V_125 ) {
F_58 ( 0 ) ;
return;
}
F_65 ( V_123 -> V_20 , F_64 ) ;
}
static void V_136 ( void )
{
unsigned long V_130 ;
if ( F_27 ( V_123 , V_101 , L_33 ) ) {
if ( V_137 < V_138 ) {
F_30 ( 1 ) ;
V_137 ++ ;
F_65 ( V_123 -> V_20 , F_64 ) ;
return;
}
V_100 = - 1 ;
F_58 ( - V_128 ) ;
return;
}
V_127 () ;
F_59 ( & V_131 , V_130 ) ;
F_51 ( V_132 ) ;
F_61 ( & V_131 , V_130 ) ;
}
static int F_66 ( struct V_43 * V_44 , unsigned int V_13 , void * V_14 )
{
struct V_4 * V_5 = V_44 -> V_32 ;
switch ( V_13 ) {
case V_139 :
{
char V_13 [ 12 ] =
{ V_140 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 12 ,
0 , 0 , 0 } ;
struct V_141 * V_142 =
(struct V_141 * ) V_14 ;
char V_76 [ 32 ] ;
int V_54 ;
V_54 = F_32 ( V_5 , V_13 , 12 , V_76 , L_34 ) ;
V_142 -> V_143 = V_76 [ 2 ] ;
V_142 -> V_144 = V_76 [ 3 ] ;
return V_54 ? - V_128 : 0 ;
}
case V_145 :
{
char V_13 [ 12 ] =
{ V_140 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 12 ,
0 , 0 , 0 } ;
struct V_146 * V_147 =
(struct V_146 * ) V_14 ;
unsigned char V_76 [ 32 ] ;
int V_54 ;
V_13 [ 1 ] =
( V_147 -> V_148 == V_149 ? 0x02 : 0 ) ;
V_13 [ 6 ] = V_147 -> V_150 ;
V_54 = F_32 ( V_5 , V_13 , 12 , V_76 , L_35 ) ;
V_147 -> V_151 = V_76 [ 5 ] & 0xf ;
V_147 -> V_152 = V_76 [ 5 ] >> 4 ;
V_147 -> V_153 =
( V_147 -> V_151 & 0x04 ) ? 1 : 0 ;
if ( V_147 -> V_148 == V_149 ) {
V_147 -> V_154 . V_155 . V_156 = V_76 [ 9 ] ;
V_147 -> V_154 . V_155 . V_157 = V_76 [ 10 ] ;
V_147 -> V_154 . V_155 . V_158 = V_76 [ 11 ] ;
} else
V_147 -> V_154 . V_159 =
( ( ( ( ( V_76 [ 8 ] << 8 ) + V_76 [ 9 ] ) << 8 )
+ V_76 [ 10 ] ) << 8 ) + V_76 [ 11 ] ;
return V_54 ? - V_128 : 0 ;
}
default:
return - V_160 ;
}
}
static int F_67 ( struct V_43 * V_44 , struct V_161 * V_162 )
{
char V_13 [ 12 ] =
{ V_163 , 0 , 0x40 , 2 , 0 , 0 , 0 , 0 , 24 , 0 , 0 , 0 } ;
char V_76 [ 32 ] ;
if ( F_32 ( V_44 -> V_32 , V_13 , 24 , V_76 , L_36 ) )
return - V_128 ;
memcpy ( V_162 -> V_164 , V_76 + 9 , 13 ) ;
V_162 -> V_164 [ 13 ] = 0 ;
return 0 ;
}
static int T_2 F_68 ( void )
{
struct V_4 * V_5 ;
int V_16 ;
if ( V_165 )
return - V_166 ;
F_11 () ;
if ( F_47 () )
return - V_46 ;
F_46 () ;
if ( F_69 ( V_36 , V_29 ) ) {
for ( V_16 = 0 , V_5 = V_18 ; V_16 < V_19 ; V_16 ++ , V_5 ++ )
F_50 ( V_5 -> V_12 ) ;
return - V_167 ;
}
V_132 = F_70 ( F_51 , & V_131 ) ;
if ( ! V_132 ) {
F_71 ( V_36 , V_29 ) ;
for ( V_16 = 0 , V_5 = V_18 ; V_16 < V_19 ; V_16 ++ , V_5 ++ )
F_50 ( V_5 -> V_12 ) ;
return - V_168 ;
}
for ( V_16 = 0 , V_5 = V_18 ; V_16 < V_19 ; V_16 ++ , V_5 ++ ) {
if ( V_5 -> V_22 ) {
F_72 ( & V_5 -> V_10 ) ;
V_5 -> V_12 -> V_7 = V_5 ;
V_5 -> V_12 -> V_169 = V_132 ;
F_73 ( V_5 -> V_12 ) ;
}
}
return 0 ;
}
static void T_3 F_74 ( void )
{
struct V_4 * V_5 ;
int V_16 ;
for ( V_16 = 0 , V_5 = V_18 ; V_16 < V_19 ; V_16 ++ , V_5 ++ ) {
if ( V_5 -> V_22 ) {
F_75 ( V_5 -> V_12 ) ;
F_49 ( V_5 -> V_20 ) ;
F_76 ( & V_5 -> V_10 ) ;
}
F_50 ( V_5 -> V_12 ) ;
}
F_77 ( V_132 ) ;
F_71 ( V_36 , V_29 ) ;
}
