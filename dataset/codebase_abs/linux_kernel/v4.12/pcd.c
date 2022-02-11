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
V_5 -> V_12 = V_12 ;
V_5 -> V_23 = & V_5 -> V_24 ;
V_5 -> V_25 = 0 ;
V_5 -> V_26 = 0 ;
V_5 -> V_27 = 1 ;
V_5 -> V_28 = ( * V_29 [ V_16 ] ) [ V_30 ] ;
if ( ( * V_29 [ V_16 ] ) [ V_31 ] )
V_17 ++ ;
V_5 -> V_32 = & V_5 -> V_10 . V_32 [ 0 ] ;
snprintf ( V_5 -> V_32 , sizeof( V_5 -> V_10 . V_32 ) , L_1 , V_32 , V_16 ) ;
V_5 -> V_10 . V_33 = & V_34 ;
V_5 -> V_10 . V_35 = V_5 ;
V_5 -> V_10 . V_36 = 0 ;
V_5 -> V_10 . V_37 = 1 ;
V_5 -> V_10 . V_38 = 0 ;
V_12 -> V_39 = V_39 ;
V_12 -> V_40 = V_16 ;
strcpy ( V_12 -> V_41 , V_5 -> V_32 ) ;
V_12 -> V_42 = & V_43 ;
V_12 -> V_44 = V_45 ;
}
}
static int F_15 ( struct V_46 * V_47 , int V_48 )
{
struct V_4 * V_5 = V_47 -> V_35 ;
if ( ! V_5 -> V_25 )
return - V_49 ;
return 0 ;
}
static void F_16 ( struct V_46 * V_47 )
{
}
static inline int F_17 ( struct V_4 * V_5 )
{
return F_18 ( V_5 -> V_23 , 1 , 6 ) ;
}
static inline int F_19 ( struct V_4 * V_5 , int V_50 )
{
return F_18 ( V_5 -> V_23 , 0 , V_50 ) ;
}
static inline void F_20 ( struct V_4 * V_5 , int V_50 , int V_51 )
{
F_21 ( V_5 -> V_23 , 0 , V_50 , V_51 ) ;
}
static int F_22 ( struct V_4 * V_5 , int V_52 , int V_53 , char * V_54 , char * V_55 )
{
int V_56 , V_57 , V_58 , V_59 , V_60 ;
V_56 = 0 ;
while ( ( ( ( V_57 = F_17 ( V_5 ) ) & V_52 ) || ( V_53 && ( ! ( V_57 & V_53 ) ) ) )
&& ( V_56 ++ < V_61 ) )
F_23 ( V_62 ) ;
if ( ( V_57 & ( V_63 & V_53 ) ) || ( V_56 > V_61 ) ) {
V_59 = F_19 ( V_5 , 7 ) ;
V_58 = F_19 ( V_5 , 1 ) ;
V_60 = F_19 ( V_5 , 2 ) ;
if ( V_56 > V_61 )
V_58 |= 0x100 ;
if ( V_54 )
F_24 ( L_2
L_3 ,
V_5 -> V_32 , V_54 , V_55 , V_57 , V_59 , V_58 , V_56 , V_60 ) ;
return ( V_59 << 8 ) + V_57 ;
}
return 0 ;
}
static int F_25 ( struct V_4 * V_5 , char * V_13 , int V_64 , char * V_54 )
{
F_26 ( V_5 -> V_23 ) ;
F_20 ( V_5 , 6 , 0xa0 + 0x10 * V_5 -> V_28 ) ;
if ( F_22 ( V_5 , V_65 | V_66 , 0 , V_54 , L_4 ) ) {
F_27 ( V_5 -> V_23 ) ;
return - 1 ;
}
F_20 ( V_5 , 4 , V_64 % 256 ) ;
F_20 ( V_5 , 5 , V_64 / 256 ) ;
F_20 ( V_5 , 7 , 0xa0 ) ;
if ( F_22 ( V_5 , V_65 , V_66 , V_54 , L_5 ) ) {
F_27 ( V_5 -> V_23 ) ;
return - 1 ;
}
if ( F_19 ( V_5 , 2 ) != 1 ) {
F_24 ( L_6 , V_5 -> V_32 , V_54 ) ;
F_27 ( V_5 -> V_23 ) ;
return - 1 ;
}
F_28 ( V_5 -> V_23 , V_13 , 12 ) ;
return 0 ;
}
static int F_29 ( struct V_4 * V_5 , char * V_67 , char * V_54 )
{
int V_57 , V_68 , V_60 , V_69 , V_70 , V_56 ;
V_57 = - 1 ;
V_70 = 0 ;
V_56 = 0 ;
if ( ! F_22 ( V_5 , V_65 , V_66 | V_71 | V_63 ,
V_54 , L_7 ) ) {
V_57 = 0 ;
while ( F_19 ( V_5 , 7 ) & V_66 ) {
V_68 = F_19 ( V_5 , 4 ) + 256 * F_19 ( V_5 , 5 ) ;
V_69 = ( V_68 + 3 ) & 0xfffc ;
V_60 = F_19 ( V_5 , 2 ) & 3 ;
if ( ( V_60 == 2 ) && ( V_69 > 0 ) && ( V_56 == 0 ) ) {
F_30 ( V_5 -> V_23 , V_67 , V_69 ) ;
if ( V_72 > 1 )
F_24 ( L_8 ,
V_5 -> V_32 , V_54 , V_69 ) ;
V_57 = 0 ;
V_56 ++ ;
} else {
if ( V_72 > 1 )
F_24
( L_9 ,
V_5 -> V_32 , V_54 , V_60 , V_68 , V_70 ) ;
if ( V_72 < 2 )
F_31 (
L_10 ,
V_5 -> V_32 ) ;
F_32 ( 1 ) ;
}
if ( V_70 ++ > V_73 ) {
F_24 ( L_11 , V_5 -> V_32 ) ;
break;
}
if ( F_22
( V_5 , V_65 , V_66 | V_71 | V_63 , V_54 ,
L_7 ) ) {
V_57 = - 1 ;
break;
}
}
}
F_27 ( V_5 -> V_23 ) ;
return V_57 ;
}
static void F_33 ( struct V_4 * V_5 , char * V_54 )
{
char V_74 [ 12 ] = { 0x03 , 0 , 0 , 0 , 16 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
char V_67 [ 16 ] ;
int V_57 , V_75 ;
V_57 = F_25 ( V_5 , V_74 , 16 , L_12 ) ;
F_32 ( 1 ) ;
if ( ! V_57 )
F_29 ( V_5 , V_67 , L_12 ) ;
V_5 -> V_26 = - 1 ;
V_75 = 2 ;
if ( ! V_57 ) {
if ( V_54 )
F_24 ( L_13 ,
V_5 -> V_32 , V_54 , V_67 [ 2 ] & 0xf , V_67 [ 12 ] , V_67 [ 13 ] ) ;
V_75 = V_67 [ 2 ] & 0xf ;
V_5 -> V_26 =
V_75 | ( ( V_67 [ 12 ] & 0xff ) << 8 ) | ( ( V_67 [ 13 ] & 0xff ) << 16 ) ;
}
if ( ( V_75 == 2 ) || ( V_75 == 6 ) )
V_5 -> V_27 = 1 ;
}
static int F_34 ( struct V_4 * V_5 , char * V_13 , int V_64 , char * V_67 , char * V_54 )
{
int V_57 ;
V_57 = F_25 ( V_5 , V_13 , V_64 , V_54 ) ;
F_32 ( 1 ) ;
if ( ! V_57 )
V_57 = F_29 ( V_5 , V_67 , V_54 ) ;
if ( V_57 )
F_33 ( V_5 , V_54 ) ;
return V_57 ;
}
static int F_35 ( struct V_46 * V_47 , struct V_76 * V_77 )
{
return F_34 ( V_47 -> V_35 , V_77 -> V_13 , V_77 -> V_78 , V_77 -> V_79 ,
L_14 ) ;
}
static unsigned int F_36 ( struct V_46 * V_47 ,
unsigned int V_15 , int V_80 )
{
struct V_4 * V_5 = V_47 -> V_35 ;
int V_81 = V_5 -> V_27 ;
if ( V_81 )
V_5 -> V_27 = 0 ;
return V_81 ? V_82 : 0 ;
}
static int F_37 ( struct V_46 * V_47 , int V_83 )
{
char V_84 [ 12 ] = { 0x1e , 0 , 0 , 0 , V_83 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
return F_34 ( V_47 -> V_35 , V_84 , 0 , V_85 ,
V_83 ? L_15 : L_16 ) ;
}
static int F_38 ( struct V_46 * V_47 , int V_86 )
{
char V_87 [ 12 ] = { 0x1b , 0 , 0 , 0 , 3 - V_86 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
return F_34 ( V_47 -> V_35 , V_87 , 0 , V_85 ,
V_86 ? L_17 : L_18 ) ;
}
static void F_39 ( int V_88 )
{
F_40 ( V_88 ) ;
}
static int F_41 ( struct V_4 * V_5 )
{
int V_89 , V_70 , V_90 ;
int V_91 [ 5 ] = { 1 , 1 , 1 , 0x14 , 0xeb } ;
F_26 ( V_5 -> V_23 ) ;
F_20 ( V_5 , 6 , 0xa0 + 0x10 * V_5 -> V_28 ) ;
F_20 ( V_5 , 7 , 8 ) ;
F_39 ( 20 * V_92 / 1000 ) ;
V_70 = 0 ;
while ( ( V_70 ++ < V_93 ) && ( F_17 ( V_5 ) & V_65 ) )
F_39 ( V_92 / 10 ) ;
V_90 = 1 ;
for ( V_89 = 0 ; V_89 < 5 ; V_89 ++ )
V_90 &= ( F_19 ( V_5 , V_89 + 1 ) == V_91 [ V_89 ] ) ;
if ( V_72 ) {
F_24 ( L_19 , V_5 -> V_32 , V_70 ) ;
for ( V_89 = 0 ; V_89 < 5 ; V_89 ++ )
F_24 ( L_20 , F_19 ( V_5 , V_89 + 1 ) ) ;
if ( ! V_90 )
F_24 ( L_21 ) ;
F_24 ( L_22 ) ;
}
F_27 ( V_5 -> V_23 ) ;
return V_90 - 1 ;
}
static int F_42 ( struct V_46 * V_47 )
{
return F_41 ( V_47 -> V_35 ) ;
}
static int F_43 ( struct V_4 * V_5 , int V_94 )
{
char V_95 [ 12 ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
int V_70 , V_60 ;
V_70 = 0 ;
while ( V_70 < V_94 ) {
V_5 -> V_26 = 0 ;
F_34 ( V_5 , V_95 , 0 , NULL , F_44 ( L_23 ) ) ;
V_60 = V_5 -> V_26 ;
if ( ! V_60 )
return 0 ;
if ( ! ( ( ( V_60 & 0xffff ) == 0x0402 ) || ( ( V_60 & 0xff ) == 6 ) ) )
return V_60 ;
V_70 ++ ;
F_39 ( V_92 ) ;
}
return 0x000020 ;
}
static int F_45 ( struct V_46 * V_47 , int V_80 )
{
char V_96 [ 12 ] = { 0x25 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
struct V_4 * V_5 = V_47 -> V_35 ;
if ( F_43 ( V_5 , V_97 ) )
return V_98 ;
if ( F_34 ( V_5 , V_96 , 8 , V_85 , F_44 ( L_24 ) ) )
return V_99 ;
return V_100 ;
}
static int F_46 ( struct V_4 * V_5 , char * V_101 )
{
int V_70 , V_59 ;
char V_102 [ 12 ] = { 0x12 , 0 , 0 , 0 , 36 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
V_103 = - 1 ;
V_59 = F_34 ( V_5 , V_102 , 36 , V_104 , L_25 ) ;
if ( V_59 )
return - 1 ;
if ( ( V_104 [ 0 ] & 0x1f ) != 5 ) {
if ( V_72 )
F_24 ( L_26 ,
V_5 -> V_32 , V_5 -> V_28 ? L_27 : L_28 ) ;
return - 1 ;
}
memcpy ( V_101 , V_104 + 16 , 16 ) ;
V_101 [ 16 ] = 0 ;
V_70 = 16 ;
while ( ( V_70 >= 0 ) && ( V_101 [ V_70 ] <= 0x20 ) ) {
V_101 [ V_70 ] = 0 ;
V_70 -- ;
}
F_24 ( L_29 , V_5 -> V_32 , V_5 -> V_28 ? L_27 : L_28 , V_101 ) ;
return 0 ;
}
static int F_47 ( struct V_4 * V_5 , int V_105 , char * V_101 )
{
if ( V_105 == - 1 ) {
for ( V_5 -> V_28 = 0 ; V_5 -> V_28 <= 1 ; V_5 -> V_28 ++ )
if ( ! F_41 ( V_5 ) && ! F_46 ( V_5 , V_101 ) )
return 0 ;
} else {
V_5 -> V_28 = V_105 ;
if ( ! F_41 ( V_5 ) && ! F_46 ( V_5 , V_101 ) )
return 0 ;
}
return - 1 ;
}
static void F_48 ( void )
{
int V_16 , V_57 ;
char V_79 [ 32 ] ;
char V_13 [ 12 ] = { 0x5a , 1 << 3 , 0x2a , 0 , 0 , 0 , 0 , 18 , 0 , 0 , 0 , 0 } ;
struct V_4 * V_5 ;
for ( V_16 = 0 , V_5 = V_18 ; V_16 < V_19 ; V_16 ++ , V_5 ++ ) {
if ( ! V_5 -> V_25 )
continue;
V_57 = F_34 ( V_5 , V_13 , 18 , V_79 , L_30 ) ;
if ( V_57 )
continue;
if ( ( V_79 [ 11 ] & 1 ) == 0 )
V_5 -> V_10 . V_38 |= V_106 ;
if ( ( V_79 [ 11 ] & 2 ) == 0 )
V_5 -> V_10 . V_38 |= V_107 ;
if ( ( V_79 [ 12 ] & 1 ) == 0 )
V_5 -> V_10 . V_38 |= V_108 ;
if ( ( V_79 [ 14 ] & 1 ) == 0 )
V_5 -> V_10 . V_38 |= V_109 ;
if ( ( V_79 [ 14 ] & 8 ) == 0 )
V_5 -> V_10 . V_38 |= V_110 ;
if ( ( V_79 [ 14 ] >> 6 ) == 0 )
V_5 -> V_10 . V_38 |= V_111 ;
}
}
static int F_49 ( void )
{
char V_101 [ 18 ] ;
int V_70 , V_16 ;
struct V_4 * V_5 ;
F_24 ( L_31 ,
V_32 , V_32 , V_112 , V_39 , V_113 ) ;
V_114 = F_50 ( V_32 ) ;
if ( ! V_114 ) {
F_51 ( L_32 , V_32 ) ;
return - 1 ;
}
V_70 = 0 ;
if ( V_17 == 0 ) {
V_5 = V_18 ;
if ( F_52 ( V_5 -> V_23 , 1 , - 1 , - 1 , - 1 , - 1 , - 1 , V_104 ,
V_115 , V_72 , V_5 -> V_32 ) ) {
if ( ! F_47 ( V_5 , - 1 , V_101 ) && V_5 -> V_12 ) {
V_5 -> V_25 = 1 ;
V_70 ++ ;
} else
F_53 ( V_5 -> V_23 ) ;
}
} else {
for ( V_16 = 0 , V_5 = V_18 ; V_16 < V_19 ; V_16 ++ , V_5 ++ ) {
int * V_116 = * V_29 [ V_16 ] ;
if ( ! V_116 [ V_31 ] )
continue;
if ( ! F_52 ( V_5 -> V_23 , 0 , V_116 [ V_31 ] , V_116 [ V_117 ] ,
V_116 [ V_118 ] , V_116 [ V_119 ] , V_116 [ V_120 ] ,
V_104 , V_115 , V_72 , V_5 -> V_32 ) )
continue;
if ( ! F_47 ( V_5 , V_116 [ V_30 ] , V_101 ) && V_5 -> V_12 ) {
V_5 -> V_25 = 1 ;
V_70 ++ ;
} else
F_53 ( V_5 -> V_23 ) ;
}
}
if ( V_70 )
return 0 ;
F_24 ( L_33 , V_32 ) ;
for ( V_16 = 0 , V_5 = V_18 ; V_16 < V_19 ; V_16 ++ , V_5 ++ )
F_14 ( V_5 -> V_12 ) ;
F_54 ( V_114 ) ;
return - 1 ;
}
static int F_55 ( void )
{
struct V_4 * V_5 ;
struct V_121 * V_122 ;
int V_123 = V_124 ;
do {
V_5 = & V_18 [ V_124 ] ;
V_122 = V_5 -> V_25 ? V_5 -> V_12 -> V_20 : NULL ;
if ( ++ V_124 == V_19 )
V_124 = 0 ;
if ( V_122 ) {
V_125 = F_56 ( V_122 ) ;
if ( V_125 )
break;
}
} while ( V_124 != V_123 );
return V_125 != NULL ;
}
static void F_57 ( void )
{
if ( V_126 )
return;
while ( 1 ) {
if ( ! V_125 && ! F_55 () )
return;
if ( F_58 ( V_125 ) == V_127 ) {
struct V_4 * V_5 = V_125 -> V_128 -> V_7 ;
if ( V_5 != V_129 )
V_103 = - 1 ;
V_129 = V_5 ;
V_130 = F_59 ( V_125 ) ;
V_131 = F_60 ( V_125 ) ;
V_132 = F_61 ( V_125 -> V_133 ) ;
V_126 = 1 ;
F_62 ( V_134 , NULL , 0 , V_113 ) ;
return;
} else {
F_63 ( V_125 , - V_135 ) ;
V_125 = NULL ;
}
}
}
static void V_21 ( struct V_121 * V_122 )
{
F_57 () ;
}
static inline void F_64 ( int V_136 )
{
unsigned long V_137 ;
F_65 ( & V_22 , V_137 ) ;
if ( ! F_66 ( V_125 , V_136 ) )
V_125 = NULL ;
V_126 = 0 ;
F_57 () ;
F_67 ( & V_22 , V_137 ) ;
}
static int F_68 ( void )
{
return ( ( ( F_17 ( V_129 ) & ( V_65 | V_66 ) ) == V_66 ) ) ;
}
static void F_69 ( void )
{
while ( V_131 && ( V_130 / 4 == V_103 ) ) {
int V_138 = ( V_130 % 4 ) * 512 ;
memcpy ( V_132 , V_104 + V_138 , 512 ) ;
V_131 -- ;
V_132 += 512 ;
V_130 ++ ;
}
}
static void F_70 ( void )
{
int V_139 , V_89 ;
char V_140 [ 12 ] = { 0xa8 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 } ;
V_103 = V_130 / 4 ;
V_139 = V_103 ;
for ( V_89 = 0 ; V_89 < 4 ; V_89 ++ ) {
V_140 [ 5 - V_89 ] = V_139 & 0xff ;
V_139 = V_139 >> 8 ;
}
if ( F_25 ( V_129 , V_140 , 2048 , L_34 ) ) {
V_103 = - 1 ;
F_64 ( - V_135 ) ;
return;
}
F_32 ( 1 ) ;
F_62 ( V_141 , F_68 , V_73 , V_113 ) ;
}
static void V_134 ( void )
{
V_126 = 1 ;
V_142 = 0 ;
F_69 () ;
if ( ! V_131 ) {
F_64 ( 0 ) ;
return;
}
F_71 ( V_129 -> V_23 , F_70 ) ;
}
static void V_141 ( void )
{
unsigned long V_137 ;
if ( F_29 ( V_129 , V_104 , L_34 ) ) {
if ( V_142 < V_143 ) {
F_32 ( 1 ) ;
V_142 ++ ;
F_71 ( V_129 -> V_23 , F_70 ) ;
return;
}
V_103 = - 1 ;
F_64 ( - V_135 ) ;
return;
}
V_134 () ;
F_65 ( & V_22 , V_137 ) ;
F_57 () ;
F_67 ( & V_22 , V_137 ) ;
}
static int F_72 ( struct V_46 * V_47 , unsigned int V_13 , void * V_14 )
{
struct V_4 * V_5 = V_47 -> V_35 ;
switch ( V_13 ) {
case V_144 :
{
char V_13 [ 12 ] =
{ V_145 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 12 ,
0 , 0 , 0 } ;
struct V_146 * V_147 =
(struct V_146 * ) V_14 ;
char V_79 [ 32 ] ;
int V_57 ;
V_57 = F_34 ( V_5 , V_13 , 12 , V_79 , L_35 ) ;
V_147 -> V_148 = V_79 [ 2 ] ;
V_147 -> V_149 = V_79 [ 3 ] ;
return V_57 ? - V_135 : 0 ;
}
case V_150 :
{
char V_13 [ 12 ] =
{ V_145 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 12 ,
0 , 0 , 0 } ;
struct V_151 * V_152 =
(struct V_151 * ) V_14 ;
unsigned char V_79 [ 32 ] ;
int V_57 ;
V_13 [ 1 ] =
( V_152 -> V_153 == V_154 ? 0x02 : 0 ) ;
V_13 [ 6 ] = V_152 -> V_155 ;
V_57 = F_34 ( V_5 , V_13 , 12 , V_79 , L_36 ) ;
V_152 -> V_156 = V_79 [ 5 ] & 0xf ;
V_152 -> V_157 = V_79 [ 5 ] >> 4 ;
V_152 -> V_158 =
( V_152 -> V_156 & 0x04 ) ? 1 : 0 ;
if ( V_152 -> V_153 == V_154 ) {
V_152 -> V_159 . V_160 . V_161 = V_79 [ 9 ] ;
V_152 -> V_159 . V_160 . V_162 = V_79 [ 10 ] ;
V_152 -> V_159 . V_160 . V_163 = V_79 [ 11 ] ;
} else
V_152 -> V_159 . V_164 =
( ( ( ( ( V_79 [ 8 ] << 8 ) + V_79 [ 9 ] ) << 8 )
+ V_79 [ 10 ] ) << 8 ) + V_79 [ 11 ] ;
return V_57 ? - V_135 : 0 ;
}
default:
return - V_165 ;
}
}
static int F_73 ( struct V_46 * V_47 , struct V_166 * V_167 )
{
char V_13 [ 12 ] =
{ V_168 , 0 , 0x40 , 2 , 0 , 0 , 0 , 0 , 24 , 0 , 0 , 0 } ;
char V_79 [ 32 ] ;
if ( F_34 ( V_47 -> V_35 , V_13 , 24 , V_79 , L_37 ) )
return - V_135 ;
memcpy ( V_167 -> V_169 , V_79 + 9 , 13 ) ;
V_167 -> V_169 [ 13 ] = 0 ;
return 0 ;
}
static int T_2 F_74 ( void )
{
struct V_4 * V_5 ;
int V_16 ;
if ( V_170 )
return - V_171 ;
F_11 () ;
if ( F_49 () )
return - V_49 ;
F_48 () ;
if ( F_75 ( V_39 , V_32 ) ) {
for ( V_16 = 0 , V_5 = V_18 ; V_16 < V_19 ; V_16 ++ , V_5 ++ )
F_14 ( V_5 -> V_12 ) ;
return - V_172 ;
}
for ( V_16 = 0 , V_5 = V_18 ; V_16 < V_19 ; V_16 ++ , V_5 ++ ) {
if ( V_5 -> V_25 ) {
F_76 ( & V_5 -> V_10 ) ;
V_5 -> V_12 -> V_7 = V_5 ;
F_77 ( V_5 -> V_12 ) ;
}
}
return 0 ;
}
static void T_3 F_78 ( void )
{
struct V_4 * V_5 ;
int V_16 ;
for ( V_16 = 0 , V_5 = V_18 ; V_16 < V_19 ; V_16 ++ , V_5 ++ ) {
if ( V_5 -> V_25 ) {
F_79 ( V_5 -> V_12 ) ;
F_53 ( V_5 -> V_23 ) ;
F_80 ( & V_5 -> V_10 ) ;
}
F_81 ( V_5 -> V_12 -> V_20 ) ;
F_14 ( V_5 -> V_12 ) ;
}
F_82 ( V_39 , V_32 ) ;
F_54 ( V_114 ) ;
}
