static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = 0x0 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_5 -> V_6 ) {
case V_7 :
V_3 = 0x2 ;
break;
case V_8 :
V_3 = 0x1 ;
break;
case V_9 :
V_3 = 0x0 ;
break;
default:
F_3 ( L_1 ) ;
V_3 = 0x1 ;
break;
}
F_4 ( V_2 , V_3 , V_10 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_11 )
F_4 ( V_2 , F_6 ( V_2 , V_12 ) | V_13 , V_12 ) ;
else
F_4 ( V_2 , F_6 ( V_2 , V_12 ) & ~ V_13 , V_12 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_14 = V_15 ;
#if F_8 ( V_16 )
V_14 |= V_17 ;
#endif
switch ( V_5 -> V_18 ) {
case 10 :
F_4 ( V_2 , F_6 ( V_2 , V_12 ) & ~ V_14 , V_12 ) ;
break;
case 100 :
F_4 ( V_2 , F_6 ( V_2 , V_12 ) | V_14 , V_12 ) ;
break;
default:
break;
}
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_11 )
F_4 ( V_2 , F_6 ( V_2 , V_12 ) | V_13 , V_12 ) ;
else
F_4 ( V_2 , F_6 ( V_2 , V_12 ) & ~ V_13 , V_12 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_5 -> V_18 ) {
case 10 :
F_4 ( V_2 , 0 , V_19 ) ;
break;
case 100 :
F_4 ( V_2 , 1 , V_19 ) ;
break;
default:
break;
}
}
static void F_9 ( struct V_1 * V_2 )
{
int V_20 ;
unsigned long V_21 [ 2 ] , V_22 [ 2 ] ;
for ( V_20 = 0 ; V_20 < 2 ; V_20 ++ ) {
V_22 [ V_20 ] = F_10 ( ( void * ) F_11 ( V_20 ) ) ;
V_21 [ V_20 ] = F_10 ( ( void * ) F_12 ( V_20 ) ) ;
}
F_13 ( V_23 , ( void * ) ( V_24 + 0x1800 ) ) ;
F_14 ( 1 ) ;
for ( V_20 = 0 ; V_20 < 2 ; V_20 ++ ) {
F_13 ( V_22 [ V_20 ] , ( void * ) F_11 ( V_20 ) ) ;
F_13 ( V_21 [ V_20 ] , ( void * ) F_12 ( V_20 ) ) ;
}
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_25 = 0 ;
if ( F_16 ( V_5 ) ) {
F_4 ( V_2 , 0x03 , V_26 ) ;
F_4 ( V_2 , F_6 ( V_2 , V_27 ) | V_28 ,
V_27 ) ;
V_25 = F_17 ( V_2 ) ;
if ( V_25 )
goto V_29;
F_4 ( V_2 , 0x0 , V_30 ) ;
F_4 ( V_2 , 0x0 , V_31 ) ;
F_4 ( V_2 , 0x0 , V_32 ) ;
F_4 ( V_2 , 0x0 , V_33 ) ;
F_4 ( V_2 , 0x0 , V_34 ) ;
F_4 ( V_2 , 0x0 , V_35 ) ;
F_4 ( V_2 , 0x0 , V_36 ) ;
F_4 ( V_2 , 0x0 , V_37 ) ;
} else {
F_4 ( V_2 , F_6 ( V_2 , V_27 ) | V_38 ,
V_27 ) ;
F_14 ( 3 ) ;
F_4 ( V_2 , F_6 ( V_2 , V_27 ) & ~ V_38 ,
V_27 ) ;
}
V_29:
return V_25 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_11 )
F_4 ( V_2 , F_6 ( V_2 , V_12 ) | V_13 , V_12 ) ;
else
F_4 ( V_2 , F_6 ( V_2 , V_12 ) & ~ V_13 , V_12 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_5 -> V_18 ) {
case 10 :
F_4 ( V_2 , 0x00000000 , V_39 ) ;
break;
case 100 :
F_4 ( V_2 , 0x00000010 , V_39 ) ;
break;
case 1000 :
F_4 ( V_2 , 0x00000020 , V_39 ) ;
break;
default:
break;
}
}
static struct V_40 * F_20 ( struct V_4 * V_5 )
{
if ( F_16 ( V_5 ) )
return & V_41 ;
else
return & V_42 ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_22 ( V_5 , V_23 , V_43 ) ;
F_14 ( 1 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_11 )
F_4 ( V_2 , F_6 ( V_2 , V_12 ) | V_13 , V_12 ) ;
else
F_4 ( V_2 , F_6 ( V_2 , V_12 ) & ~ V_13 , V_12 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_5 -> V_18 ) {
case 10 :
F_4 ( V_2 , V_44 , V_39 ) ;
break;
case 100 :
F_4 ( V_2 , V_45 , V_39 ) ;
break;
case 1000 :
F_4 ( V_2 , V_46 , V_39 ) ;
break;
default:
break;
}
}
static int F_15 ( struct V_1 * V_2 )
{
int V_25 = 0 ;
F_4 ( V_2 , V_47 , V_26 ) ;
F_4 ( V_2 , F_6 ( V_2 , V_27 ) | V_28 , V_27 ) ;
V_25 = F_17 ( V_2 ) ;
if ( V_25 )
goto V_29;
F_4 ( V_2 , 0x0 , V_30 ) ;
F_4 ( V_2 , 0x0 , V_31 ) ;
F_4 ( V_2 , 0x0 , V_32 ) ;
F_4 ( V_2 , 0x0 , V_33 ) ;
F_4 ( V_2 , 0x0 , V_34 ) ;
F_4 ( V_2 , 0x0 , V_35 ) ;
F_4 ( V_2 , 0x0 , V_36 ) ;
F_4 ( V_2 , 0x0 , V_37 ) ;
F_23 ( V_2 ) ;
if ( V_42 . V_48 )
F_1 ( V_2 ) ;
V_29:
return V_25 ;
}
static void F_23 ( struct V_1 * V_2 )
{
if ( V_42 . V_49 )
F_4 ( V_2 , 0x0 , V_50 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_22 ( V_5 , V_23 , V_43 ) ;
F_14 ( 1 ) ;
F_1 ( V_2 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_25 = 0 ;
F_4 ( V_2 , V_47 , V_26 ) ;
F_4 ( V_2 , F_6 ( V_2 , V_27 ) | V_28 , V_27 ) ;
V_25 = F_17 ( V_2 ) ;
if ( V_25 )
goto V_29;
F_4 ( V_2 , 0x0 , V_30 ) ;
F_4 ( V_2 , 0x0 , V_31 ) ;
F_4 ( V_2 , 0x0 , V_32 ) ;
F_4 ( V_2 , 0x0 , V_33 ) ;
F_4 ( V_2 , 0x0 , V_34 ) ;
F_4 ( V_2 , 0x0 , V_35 ) ;
F_4 ( V_2 , 0x0 , V_36 ) ;
F_4 ( V_2 , 0x0 , V_37 ) ;
V_29:
return V_25 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_11 )
F_4 ( V_2 , F_6 ( V_2 , V_12 ) | V_13 , V_12 ) ;
else
F_4 ( V_2 , F_6 ( V_2 , V_12 ) & ~ V_13 , V_12 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_5 -> V_18 ) {
case 10 :
F_4 ( V_2 , V_44 , V_39 ) ;
break;
case 100 :
F_4 ( V_2 , V_45 , V_39 ) ;
break;
case 1000 :
F_4 ( V_2 , V_46 , V_39 ) ;
break;
default:
break;
}
}
static void F_24 ( struct V_40 * V_51 )
{
if ( ! V_51 -> V_52 )
V_51 -> V_52 = V_53 ;
if ( ! V_51 -> V_54 )
V_51 -> V_54 = V_55 ;
if ( ! V_51 -> V_56 )
V_51 -> V_56 = V_57 | \
V_58 ;
if ( ! V_51 -> V_59 )
V_51 -> V_59 = V_60 ;
if ( ! V_51 -> V_61 )
V_51 -> V_61 = V_62 ;
if ( ! V_51 -> V_63 )
V_51 -> V_63 = V_64 ;
if ( ! V_51 -> V_65 )
V_51 -> V_65 = V_66 ;
if ( ! V_51 -> V_67 )
V_51 -> V_67 = V_68 ;
}
static int F_15 ( struct V_1 * V_2 )
{
F_4 ( V_2 , F_6 ( V_2 , V_27 ) | V_38 , V_27 ) ;
F_14 ( 3 ) ;
F_4 ( V_2 , F_6 ( V_2 , V_27 ) & ~ V_38 , V_27 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_25 = 0 ;
int V_69 = 100 ;
while ( V_69 > 0 ) {
if ( ! ( F_6 ( V_2 , V_27 ) & 0x3 ) )
break;
F_14 ( 1 ) ;
V_69 -- ;
}
if ( V_69 < 0 ) {
F_25 ( V_70 L_2 ) ;
V_25 = - V_71 ;
}
return V_25 ;
}
static void F_26 ( struct V_72 * V_73 )
{
int V_74 ;
V_74 = V_75 - ( ( T_1 ) V_73 -> V_76 & ( V_75 - 1 ) ) ;
if ( V_74 )
F_27 ( V_73 , V_74 ) ;
}
static void F_26 ( struct V_72 * V_73 )
{
F_27 ( V_73 , V_77 ) ;
}
static inline T_2 F_28 ( struct V_4 * V_5 , T_1 V_78 )
{
switch ( V_5 -> V_79 ) {
case V_80 :
return F_29 ( V_78 ) ;
case V_81 :
return F_30 ( V_78 ) ;
}
return V_78 ;
}
static inline T_2 F_31 ( struct V_4 * V_5 , T_1 V_78 )
{
switch ( V_5 -> V_79 ) {
case V_80 :
return F_32 ( V_78 ) ;
case V_81 :
return F_33 ( V_78 ) ;
}
return V_78 ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_4 ( V_2 ,
( V_2 -> V_82 [ 0 ] << 24 ) | ( V_2 -> V_82 [ 1 ] << 16 ) |
( V_2 -> V_82 [ 2 ] << 8 ) | ( V_2 -> V_82 [ 3 ] ) , V_83 ) ;
F_4 ( V_2 ,
( V_2 -> V_82 [ 4 ] << 8 ) | ( V_2 -> V_82 [ 5 ] ) , V_84 ) ;
}
static void F_35 ( struct V_1 * V_2 , unsigned char * V_85 )
{
if ( V_85 [ 0 ] || V_85 [ 1 ] || V_85 [ 2 ] || V_85 [ 3 ] || V_85 [ 4 ] || V_85 [ 5 ] ) {
memcpy ( V_2 -> V_82 , V_85 , 6 ) ;
} else {
V_2 -> V_82 [ 0 ] = ( F_6 ( V_2 , V_83 ) >> 24 ) ;
V_2 -> V_82 [ 1 ] = ( F_6 ( V_2 , V_83 ) >> 16 ) & 0xFF ;
V_2 -> V_82 [ 2 ] = ( F_6 ( V_2 , V_83 ) >> 8 ) & 0xFF ;
V_2 -> V_82 [ 3 ] = ( F_6 ( V_2 , V_83 ) & 0xFF ) ;
V_2 -> V_82 [ 4 ] = ( F_6 ( V_2 , V_84 ) >> 8 ) & 0xFF ;
V_2 -> V_82 [ 5 ] = ( F_6 ( V_2 , V_84 ) & 0xFF ) ;
}
}
static int F_16 ( struct V_4 * V_5 )
{
if ( V_5 -> V_86 == V_87 )
return 1 ;
else
return 0 ;
}
static unsigned long F_36 ( struct V_4 * V_5 )
{
if ( F_16 ( V_5 ) )
return V_88 ;
else
return V_89 ;
}
static void F_37 ( void * V_90 , T_1 V_91 )
{
F_13 ( F_10 ( V_90 ) | V_91 , V_90 ) ;
}
static void F_38 ( void * V_90 , T_1 V_91 )
{
F_13 ( ( F_10 ( V_90 ) & ~ V_91 ) , V_90 ) ;
}
static int F_39 ( void * V_90 , T_1 V_91 )
{
return ( F_10 ( V_90 ) & V_91 ) != 0 ;
}
static void F_40 ( struct V_92 * V_93 , int V_94 )
{
struct V_95 * V_96 = F_41 ( V_93 , struct V_95 , V_93 ) ;
if ( V_96 -> V_97 )
V_96 -> V_97 ( V_96 -> V_90 ) ;
if ( V_94 )
F_37 ( V_96 -> V_90 , V_96 -> V_98 ) ;
else
F_38 ( V_96 -> V_90 , V_96 -> V_98 ) ;
}
static void F_42 ( struct V_92 * V_93 , int V_94 )
{
struct V_95 * V_96 = F_41 ( V_93 , struct V_95 , V_93 ) ;
if ( V_96 -> V_97 )
V_96 -> V_97 ( V_96 -> V_90 ) ;
if ( V_94 )
F_37 ( V_96 -> V_90 , V_96 -> V_99 ) ;
else
F_38 ( V_96 -> V_90 , V_96 -> V_99 ) ;
}
static int F_43 ( struct V_92 * V_93 )
{
struct V_95 * V_96 = F_41 ( V_93 , struct V_95 , V_93 ) ;
if ( V_96 -> V_97 )
V_96 -> V_97 ( V_96 -> V_90 ) ;
return F_39 ( V_96 -> V_90 , V_96 -> V_100 ) ;
}
static void F_44 ( struct V_92 * V_93 , int V_94 )
{
struct V_95 * V_96 = F_41 ( V_93 , struct V_95 , V_93 ) ;
if ( V_96 -> V_97 )
V_96 -> V_97 ( V_96 -> V_90 ) ;
if ( V_94 )
F_37 ( V_96 -> V_90 , V_96 -> V_101 ) ;
else
F_38 ( V_96 -> V_90 , V_96 -> V_101 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_20 ;
if ( V_5 -> V_102 ) {
for ( V_20 = 0 ; V_20 < V_5 -> V_103 ; V_20 ++ ) {
if ( V_5 -> V_102 [ V_20 ] )
F_46 ( V_5 -> V_102 [ V_20 ] ) ;
}
}
F_47 ( V_5 -> V_102 ) ;
V_5 -> V_102 = NULL ;
if ( V_5 -> V_104 ) {
for ( V_20 = 0 ; V_20 < V_5 -> V_105 ; V_20 ++ ) {
if ( V_5 -> V_104 [ V_20 ] )
F_46 ( V_5 -> V_104 [ V_20 ] ) ;
}
}
F_47 ( V_5 -> V_104 ) ;
V_5 -> V_104 = NULL ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_20 ;
struct V_72 * V_73 ;
struct V_106 * V_107 = NULL ;
struct V_108 * V_109 = NULL ;
int V_110 = sizeof( * V_107 ) * V_5 -> V_103 ;
int V_111 = sizeof( * V_109 ) * V_5 -> V_105 ;
V_5 -> V_112 = V_5 -> V_113 = 0 ;
V_5 -> V_114 = V_5 -> V_115 = 0 ;
memset ( V_5 -> V_116 , 0 , V_110 ) ;
for ( V_20 = 0 ; V_20 < V_5 -> V_103 ; V_20 ++ ) {
V_5 -> V_102 [ V_20 ] = NULL ;
V_73 = F_49 ( V_2 , V_5 -> V_117 ) ;
V_5 -> V_102 [ V_20 ] = V_73 ;
if ( V_73 == NULL )
break;
F_50 ( & V_2 -> V_118 , V_73 -> V_76 , V_5 -> V_117 ,
V_119 ) ;
F_26 ( V_73 ) ;
V_107 = & V_5 -> V_116 [ V_20 ] ;
V_107 -> V_90 = F_51 ( F_52 ( V_73 -> V_76 , 4 ) ) ;
V_107 -> V_120 = F_28 ( V_5 , V_121 | V_122 ) ;
V_107 -> V_123 = F_53 ( V_5 -> V_117 , 16 ) ;
if ( V_20 == 0 ) {
F_4 ( V_2 , V_5 -> V_124 , V_34 ) ;
if ( F_16 ( V_5 ) )
F_4 ( V_2 , V_5 -> V_124 , V_35 ) ;
}
}
V_5 -> V_114 = ( T_1 ) ( V_20 - V_5 -> V_103 ) ;
V_107 -> V_120 |= F_28 ( V_5 , V_125 ) ;
memset ( V_5 -> V_126 , 0 , V_111 ) ;
for ( V_20 = 0 ; V_20 < V_5 -> V_105 ; V_20 ++ ) {
V_5 -> V_104 [ V_20 ] = NULL ;
V_109 = & V_5 -> V_126 [ V_20 ] ;
V_109 -> V_120 = F_28 ( V_5 , V_127 ) ;
V_109 -> V_123 = 0 ;
if ( V_20 == 0 ) {
F_4 ( V_2 , V_5 -> V_128 , V_30 ) ;
if ( F_16 ( V_5 ) )
F_4 ( V_2 , V_5 -> V_128 , V_31 ) ;
}
}
V_109 -> V_120 |= F_28 ( V_5 , V_129 ) ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_110 , V_111 , V_25 = 0 ;
V_5 -> V_117 = ( V_2 -> V_130 <= 1492 ? V_131 :
( ( ( V_2 -> V_130 + 26 + 7 ) & ~ 7 ) + 2 + 16 ) ) ;
if ( V_5 -> V_51 -> V_132 )
V_5 -> V_117 += V_133 ;
V_5 -> V_102 = F_55 ( V_5 -> V_103 ,
sizeof( * V_5 -> V_102 ) , V_134 ) ;
if ( ! V_5 -> V_102 ) {
V_25 = - V_135 ;
return V_25 ;
}
V_5 -> V_104 = F_55 ( V_5 -> V_105 ,
sizeof( * V_5 -> V_104 ) , V_134 ) ;
if ( ! V_5 -> V_104 ) {
V_25 = - V_135 ;
goto V_136;
}
V_110 = sizeof( struct V_106 ) * V_5 -> V_103 ;
V_5 -> V_116 = F_56 ( NULL , V_110 , & V_5 -> V_124 ,
V_134 ) ;
if ( ! V_5 -> V_116 ) {
F_57 ( & V_2 -> V_118 , L_3 ,
V_110 ) ;
V_25 = - V_135 ;
goto V_137;
}
V_5 -> V_114 = 0 ;
V_111 = sizeof( struct V_108 ) * V_5 -> V_105 ;
V_5 -> V_126 = F_56 ( NULL , V_111 , & V_5 -> V_128 ,
V_134 ) ;
if ( ! V_5 -> V_126 ) {
F_57 ( & V_2 -> V_118 , L_4 ,
V_111 ) ;
V_25 = - V_135 ;
goto V_137;
}
return V_25 ;
V_137:
F_58 ( NULL , V_110 , V_5 -> V_116 , V_5 -> V_124 ) ;
V_136:
F_45 ( V_2 ) ;
V_5 -> V_126 = NULL ;
V_5 -> V_116 = NULL ;
return V_25 ;
}
static void F_59 ( struct V_4 * V_5 )
{
int V_138 ;
if ( V_5 -> V_116 ) {
V_138 = sizeof( struct V_106 ) * V_5 -> V_103 ;
F_58 ( NULL , V_138 , V_5 -> V_116 ,
V_5 -> V_124 ) ;
V_5 -> V_116 = NULL ;
}
if ( V_5 -> V_126 ) {
V_138 = sizeof( struct V_108 ) * V_5 -> V_105 ;
F_58 ( NULL , V_138 , V_5 -> V_126 ,
V_5 -> V_128 ) ;
V_5 -> V_126 = NULL ;
}
}
static int F_60 ( struct V_1 * V_2 , bool V_139 )
{
int V_25 = 0 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_140 ;
V_25 = F_15 ( V_2 ) ;
if ( V_25 )
goto V_29;
F_48 ( V_2 ) ;
if ( V_5 -> V_51 -> V_132 )
F_4 ( V_2 , V_5 -> V_51 -> V_141 , V_142 ) ;
F_4 ( V_2 , 0 , V_143 ) ;
#if F_8 ( V_144 )
if ( V_5 -> V_51 -> V_145 )
F_4 ( V_2 , V_146 , V_27 ) ;
else
#endif
F_4 ( V_2 , 0 , V_27 ) ;
F_4 ( V_2 , V_5 -> V_51 -> V_59 , V_147 ) ;
F_4 ( V_2 , 0 , V_148 ) ;
F_4 ( V_2 , V_5 -> V_51 -> V_61 , V_149 ) ;
F_4 ( V_2 , V_150 | V_151 | V_152 , V_153 ) ;
if ( V_5 -> V_51 -> V_154 )
F_4 ( V_2 , 0x800 , V_155 ) ;
F_4 ( V_2 , V_5 -> V_51 -> V_56 , V_156 ) ;
if ( ! V_5 -> V_51 -> V_157 )
F_4 ( V_2 , 0 , V_158 ) ;
F_4 ( V_2 , V_2 -> V_130 + V_159 + V_160 + V_161 ,
V_162 ) ;
F_4 ( V_2 , F_6 ( V_2 , V_163 ) , V_163 ) ;
if ( V_139 )
F_4 ( V_2 , V_5 -> V_51 -> V_164 , V_143 ) ;
V_140 = ( F_6 ( V_2 , V_12 ) & V_13 ) |
V_165 | ( V_5 -> V_11 ? V_13 : 0 ) | V_166 | V_167 ;
F_4 ( V_2 , V_140 , V_12 ) ;
if ( V_5 -> V_51 -> V_168 )
V_5 -> V_51 -> V_168 ( V_2 ) ;
F_4 ( V_2 , V_5 -> V_51 -> V_52 , V_169 ) ;
if ( V_139 )
F_4 ( V_2 , V_5 -> V_51 -> V_54 , V_170 ) ;
F_34 ( V_2 ) ;
if ( V_5 -> V_51 -> V_171 )
F_4 ( V_2 , V_172 , V_173 ) ;
if ( V_5 -> V_51 -> V_174 )
F_4 ( V_2 , V_175 , V_176 ) ;
if ( V_5 -> V_51 -> V_177 )
F_4 ( V_2 , V_178 , V_179 ) ;
if ( V_139 ) {
F_4 ( V_2 , V_180 , V_181 ) ;
F_61 ( V_2 ) ;
}
V_29:
return V_25 ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_108 * V_109 ;
int V_182 = 0 ;
int V_183 = 0 ;
for (; V_5 -> V_113 - V_5 -> V_115 > 0 ; V_5 -> V_115 ++ ) {
V_183 = V_5 -> V_115 % V_5 -> V_105 ;
V_109 = & V_5 -> V_126 [ V_183 ] ;
if ( V_109 -> V_120 & F_28 ( V_5 , V_184 ) )
break;
if ( V_5 -> V_104 [ V_183 ] ) {
F_63 ( & V_2 -> V_118 , V_109 -> V_90 ,
V_109 -> V_123 , V_185 ) ;
F_64 ( V_5 -> V_104 [ V_183 ] ) ;
V_5 -> V_104 [ V_183 ] = NULL ;
V_182 ++ ;
}
V_109 -> V_120 = F_28 ( V_5 , V_127 ) ;
if ( V_183 >= V_5 -> V_105 - 1 )
V_109 -> V_120 |= F_28 ( V_5 , V_129 ) ;
V_2 -> V_186 . V_187 ++ ;
V_2 -> V_186 . V_188 += V_109 -> V_123 ;
}
return V_182 ;
}
static int F_65 ( struct V_1 * V_2 , T_1 V_189 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_106 * V_107 ;
int V_183 = V_5 -> V_112 % V_5 -> V_103 ;
int V_190 = ( V_5 -> V_114 + V_5 -> V_103 ) - V_5 -> V_112 ;
struct V_72 * V_73 ;
T_3 V_191 = 0 ;
T_1 V_192 ;
V_107 = & V_5 -> V_116 [ V_183 ] ;
while ( ! ( V_107 -> V_120 & F_28 ( V_5 , V_121 ) ) ) {
V_192 = F_31 ( V_5 , V_107 -> V_120 ) ;
V_191 = V_107 -> V_193 ;
#if F_8 ( V_194 )
V_192 >>= 16 ;
#endif
if ( -- V_190 < 0 )
break;
if ( ! ( V_192 & V_195 ) )
V_2 -> V_186 . V_196 ++ ;
if ( V_192 & ( V_197 | V_198 | V_199 | V_200 |
V_201 | V_202 | V_203 ) ) {
V_2 -> V_186 . V_204 ++ ;
if ( V_192 & V_197 )
V_2 -> V_186 . V_205 ++ ;
if ( V_192 & V_198 )
V_2 -> V_186 . V_206 ++ ;
if ( V_192 & V_199 )
V_2 -> V_186 . V_196 ++ ;
if ( V_192 & V_200 )
V_2 -> V_186 . V_196 ++ ;
if ( V_192 & V_202 )
V_2 -> V_186 . V_207 ++ ;
if ( V_192 & V_203 )
V_2 -> V_186 . V_208 ++ ;
} else {
if ( ! V_5 -> V_51 -> V_145 )
F_66 (
F_67 ( F_53 ( V_107 -> V_90 , 4 ) ) ,
V_191 + 2 ) ;
V_73 = V_5 -> V_102 [ V_183 ] ;
V_5 -> V_102 [ V_183 ] = NULL ;
if ( V_5 -> V_51 -> V_132 )
F_27 ( V_73 , V_133 ) ;
F_68 ( V_73 , V_191 ) ;
V_73 -> V_209 = F_69 ( V_73 , V_2 ) ;
F_70 ( V_73 ) ;
V_2 -> V_186 . V_210 ++ ;
V_2 -> V_186 . V_211 += V_191 ;
}
V_107 -> V_120 |= F_28 ( V_5 , V_121 ) ;
V_183 = ( ++ V_5 -> V_112 ) % V_5 -> V_103 ;
V_107 = & V_5 -> V_116 [ V_183 ] ;
}
for (; V_5 -> V_112 - V_5 -> V_114 > 0 ; V_5 -> V_114 ++ ) {
V_183 = V_5 -> V_114 % V_5 -> V_103 ;
V_107 = & V_5 -> V_116 [ V_183 ] ;
V_107 -> V_123 = F_53 ( V_5 -> V_117 , 16 ) ;
if ( V_5 -> V_102 [ V_183 ] == NULL ) {
V_73 = F_49 ( V_2 , V_5 -> V_117 ) ;
V_5 -> V_102 [ V_183 ] = V_73 ;
if ( V_73 == NULL )
break;
F_50 ( & V_2 -> V_118 , V_73 -> V_76 , V_5 -> V_117 ,
V_119 ) ;
F_26 ( V_73 ) ;
F_71 ( V_73 ) ;
V_107 -> V_90 = F_51 ( F_52 ( V_73 -> V_76 , 4 ) ) ;
}
if ( V_183 >= V_5 -> V_103 - 1 )
V_107 -> V_120 |=
F_28 ( V_5 , V_121 | V_122 | V_125 ) ;
else
V_107 -> V_120 |=
F_28 ( V_5 , V_121 | V_122 ) ;
}
if ( ! ( F_6 ( V_2 , V_181 ) & V_180 ) ) {
if ( V_189 & V_212 )
V_5 -> V_112 = V_5 -> V_114 =
( F_6 ( V_2 , V_35 ) -
F_6 ( V_2 , V_34 ) ) >> 4 ;
F_4 ( V_2 , V_180 , V_181 ) ;
}
return 0 ;
}
static void F_72 ( struct V_1 * V_2 )
{
F_4 ( V_2 , F_6 ( V_2 , V_12 ) &
~ ( V_167 | V_166 ) , V_12 ) ;
}
static void F_73 ( struct V_1 * V_2 )
{
F_4 ( V_2 , F_6 ( V_2 , V_12 ) |
( V_167 | V_166 ) , V_12 ) ;
}
static void F_74 ( struct V_1 * V_2 , int V_189 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_213 ;
T_1 V_214 ;
T_1 V_215 ;
if ( V_189 & V_216 ) {
V_213 = F_6 ( V_2 , V_169 ) ;
F_4 ( V_2 , V_213 , V_169 ) ;
if ( V_213 & V_217 )
V_2 -> V_186 . V_218 ++ ;
if ( V_213 & V_219 ) {
if ( V_5 -> V_51 -> V_220 || V_5 -> V_221 ) {
goto V_222;
} else {
V_214 = ( F_6 ( V_2 , V_223 ) ) ;
if ( V_5 -> V_224 )
V_214 = ~ V_214 ;
}
if ( ! ( V_214 & V_225 ) )
F_72 ( V_2 ) ;
else {
F_4 ( V_2 , F_6 ( V_2 , V_143 ) &
~ V_226 , V_143 ) ;
F_4 ( V_2 , F_6 ( V_2 , V_169 ) ,
V_169 ) ;
F_4 ( V_2 , F_6 ( V_2 , V_143 ) |
V_226 , V_143 ) ;
F_73 ( V_2 ) ;
}
}
}
V_222:
if ( V_189 & V_227 ) {
if ( V_189 & V_228 )
V_2 -> V_186 . V_229 ++ ;
if ( F_75 ( V_5 ) )
F_57 ( & V_2 -> V_118 , L_5 ) ;
}
if ( V_189 & V_230 ) {
if ( V_189 & V_231 ) {
V_2 -> V_186 . V_206 ++ ;
if ( F_76 ( V_5 ) )
F_57 ( & V_2 -> V_118 , L_6 ) ;
}
}
if ( V_189 & V_232 ) {
V_2 -> V_186 . V_233 ++ ;
if ( F_75 ( V_5 ) )
F_57 ( & V_2 -> V_118 , L_7 ) ;
}
if ( V_189 & V_234 ) {
V_2 -> V_186 . V_233 ++ ;
if ( F_75 ( V_5 ) )
F_57 ( & V_2 -> V_118 , L_8 ) ;
}
if ( V_189 & V_212 ) {
V_2 -> V_186 . V_208 ++ ;
if ( F_76 ( V_5 ) )
F_57 ( & V_2 -> V_118 , L_9 ) ;
}
if ( V_189 & V_235 ) {
V_2 -> V_186 . V_236 ++ ;
if ( F_76 ( V_5 ) )
F_57 ( & V_2 -> V_118 , L_10 ) ;
}
if ( ! V_5 -> V_51 -> V_237 && ( V_189 & V_238 ) ) {
V_2 -> V_186 . V_233 ++ ;
if ( F_75 ( V_5 ) )
F_57 ( & V_2 -> V_118 , L_11 ) ;
}
V_215 = V_227 | V_228 | V_238 | V_232 | V_234 ;
if ( V_5 -> V_51 -> V_237 )
V_215 &= ~ V_238 ;
if ( V_189 & V_215 ) {
T_1 V_239 = F_6 ( V_2 , V_240 ) ;
F_57 ( & V_2 -> V_118 , L_12 ,
V_189 , V_5 -> V_113 ) ;
F_57 ( & V_2 -> V_118 , L_13 ,
V_5 -> V_115 , ( T_1 ) V_2 -> V_241 , V_239 ) ;
F_62 ( V_2 ) ;
if ( V_239 ^ F_36 ( V_5 ) ) {
F_4 ( V_2 , F_36 ( V_5 ) , V_240 ) ;
}
F_77 ( V_2 ) ;
}
}
static T_4 F_78 ( int V_242 , void * V_243 )
{
struct V_1 * V_2 = V_243 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_40 * V_51 = V_5 -> V_51 ;
T_4 V_25 = V_244 ;
unsigned long V_189 ;
F_79 ( & V_5 -> V_245 ) ;
V_189 = F_6 ( V_2 , V_163 ) ;
V_189 &= F_6 ( V_2 , V_143 ) | V_226 ;
if ( V_189 & ( V_246 | V_247 | V_248 |
V_249 | V_250 | V_251 | V_252 |
V_51 -> V_63 | V_51 -> V_65 ) ) {
F_4 ( V_2 , V_189 , V_163 ) ;
V_25 = V_253 ;
} else
goto V_254;
if ( V_189 & ( V_246 |
V_247 |
V_248 |
V_249 |
V_250 |
V_251 |
V_252 ) ) {
F_65 ( V_2 , V_189 ) ;
}
if ( V_189 & V_51 -> V_63 ) {
F_62 ( V_2 ) ;
F_77 ( V_2 ) ;
}
if ( V_189 & V_51 -> V_65 )
F_74 ( V_2 , V_189 ) ;
V_254:
F_80 ( & V_5 -> V_245 ) ;
return V_25 ;
}
static void F_81 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_255 * V_256 = V_5 -> V_256 ;
int V_257 = 0 ;
if ( V_256 -> V_258 ) {
if ( V_256 -> V_11 != V_5 -> V_11 ) {
V_257 = 1 ;
V_5 -> V_11 = V_256 -> V_11 ;
if ( V_5 -> V_51 -> V_259 )
V_5 -> V_51 -> V_259 ( V_2 ) ;
}
if ( V_256 -> V_18 != V_5 -> V_18 ) {
V_257 = 1 ;
V_5 -> V_18 = V_256 -> V_18 ;
if ( V_5 -> V_51 -> V_168 )
V_5 -> V_51 -> V_168 ( V_2 ) ;
}
if ( ! V_5 -> V_258 ) {
F_4 ( V_2 ,
( F_6 ( V_2 , V_12 ) & ~ V_260 ) , V_12 ) ;
V_257 = 1 ;
V_5 -> V_258 = V_256 -> V_258 ;
if ( V_5 -> V_51 -> V_220 || V_5 -> V_221 )
F_73 ( V_2 ) ;
}
} else if ( V_5 -> V_258 ) {
V_257 = 1 ;
V_5 -> V_258 = 0 ;
V_5 -> V_18 = 0 ;
V_5 -> V_11 = - 1 ;
if ( V_5 -> V_51 -> V_220 || V_5 -> V_221 )
F_72 ( V_2 ) ;
}
if ( V_257 && F_82 ( V_5 ) )
F_83 ( V_256 ) ;
}
static int F_84 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
char V_261 [ V_262 + 3 ] ;
struct V_255 * V_256 = NULL ;
snprintf ( V_261 , sizeof( V_261 ) , V_263 ,
V_5 -> V_264 -> V_265 , V_5 -> V_261 ) ;
V_5 -> V_258 = 0 ;
V_5 -> V_18 = 0 ;
V_5 -> V_11 = - 1 ;
V_256 = F_85 ( V_2 , V_261 , F_81 ,
V_5 -> V_6 ) ;
if ( F_86 ( V_256 ) ) {
F_57 ( & V_2 -> V_118 , L_14 ) ;
return F_87 ( V_256 ) ;
}
F_88 ( & V_2 -> V_118 , L_15 ,
V_256 -> V_90 , V_256 -> V_266 -> V_267 ) ;
V_5 -> V_256 = V_256 ;
return 0 ;
}
static int F_89 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_25 ;
V_25 = F_84 ( V_2 ) ;
if ( V_25 )
return V_25 ;
F_90 ( V_5 -> V_256 , V_268 , V_269 ) ;
F_91 ( V_5 -> V_256 ) ;
return 0 ;
}
static int F_92 ( struct V_1 * V_2 ,
struct V_270 * V_271 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_272 ;
int V_25 ;
F_93 ( & V_5 -> V_245 , V_272 ) ;
V_25 = F_94 ( V_5 -> V_256 , V_271 ) ;
F_95 ( & V_5 -> V_245 , V_272 ) ;
return V_25 ;
}
static int F_96 ( struct V_1 * V_2 ,
struct V_270 * V_271 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_272 ;
int V_25 ;
F_93 ( & V_5 -> V_245 , V_272 ) ;
F_72 ( V_2 ) ;
V_25 = F_97 ( V_5 -> V_256 , V_271 ) ;
if ( V_25 )
goto V_273;
if ( V_271 -> V_11 == V_274 )
V_5 -> V_11 = 1 ;
else
V_5 -> V_11 = 0 ;
if ( V_5 -> V_51 -> V_259 )
V_5 -> V_51 -> V_259 ( V_2 ) ;
V_273:
F_14 ( 1 ) ;
F_73 ( V_2 ) ;
F_95 ( & V_5 -> V_245 , V_272 ) ;
return V_25 ;
}
static int F_98 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_272 ;
int V_25 ;
F_93 ( & V_5 -> V_245 , V_272 ) ;
V_25 = F_99 ( V_5 -> V_256 ) ;
F_95 ( & V_5 -> V_245 , V_272 ) ;
return V_25 ;
}
static T_1 F_100 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_275 ;
}
static void F_101 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_275 = V_3 ;
}
static int F_102 ( struct V_1 * V_243 , int V_276 )
{
switch ( V_276 ) {
case V_277 :
return V_278 ;
default:
return - V_279 ;
}
}
static void F_103 ( struct V_1 * V_2 ,
struct V_280 * V_186 , T_5 * V_76 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_20 = 0 ;
V_76 [ V_20 ++ ] = V_5 -> V_112 ;
V_76 [ V_20 ++ ] = V_5 -> V_113 ;
V_76 [ V_20 ++ ] = V_5 -> V_114 ;
V_76 [ V_20 ++ ] = V_5 -> V_115 ;
}
static void F_104 ( struct V_1 * V_2 , T_1 V_281 , T_6 * V_76 )
{
switch ( V_281 ) {
case V_277 :
memcpy ( V_76 , * V_282 ,
sizeof( V_282 ) ) ;
break;
}
}
static void F_105 ( struct V_1 * V_2 ,
struct V_283 * V_284 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_284 -> V_285 = V_286 ;
V_284 -> V_287 = V_288 ;
V_284 -> V_289 = V_5 -> V_103 ;
V_284 -> V_290 = V_5 -> V_105 ;
}
static int F_106 ( struct V_1 * V_2 ,
struct V_283 * V_284 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_25 ;
if ( V_284 -> V_290 > V_288 ||
V_284 -> V_289 > V_286 ||
V_284 -> V_290 < V_291 ||
V_284 -> V_289 < V_292 )
return - V_293 ;
if ( V_284 -> V_294 || V_284 -> V_295 )
return - V_293 ;
if ( F_107 ( V_2 ) ) {
F_108 ( V_2 ) ;
F_4 ( V_2 , 0x0000 , V_143 ) ;
F_4 ( V_2 , 0 , V_240 ) ;
F_4 ( V_2 , 0 , V_181 ) ;
F_109 ( V_2 -> V_242 ) ;
}
F_45 ( V_2 ) ;
F_59 ( V_5 ) ;
V_5 -> V_103 = V_284 -> V_289 ;
V_5 -> V_105 = V_284 -> V_290 ;
V_25 = F_54 ( V_2 ) ;
if ( V_25 < 0 ) {
F_57 ( & V_2 -> V_118 , L_16 , V_296 ) ;
return V_25 ;
}
V_25 = F_60 ( V_2 , false ) ;
if ( V_25 < 0 ) {
F_57 ( & V_2 -> V_118 , L_17 , V_296 ) ;
return V_25 ;
}
if ( F_107 ( V_2 ) ) {
F_4 ( V_2 , V_5 -> V_51 -> V_164 , V_143 ) ;
F_4 ( V_2 , V_180 , V_181 ) ;
F_77 ( V_2 ) ;
}
return 0 ;
}
static int F_110 ( struct V_1 * V_2 )
{
int V_25 = 0 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_111 ( & V_5 -> V_297 -> V_118 ) ;
V_25 = F_112 ( V_2 -> V_242 , F_78 ,
#if F_8 ( V_298 ) || \
F_8 ( V_299 ) || \
F_8 ( V_300 )
V_301 ,
#else
0 ,
#endif
V_2 -> V_267 , V_2 ) ;
if ( V_25 ) {
F_57 ( & V_2 -> V_118 , L_18 ) ;
return V_25 ;
}
V_25 = F_54 ( V_2 ) ;
if ( V_25 )
goto V_302;
V_25 = F_60 ( V_2 , true ) ;
if ( V_25 )
goto V_302;
V_25 = F_89 ( V_2 ) ;
if ( V_25 )
goto V_302;
return V_25 ;
V_302:
F_113 ( V_2 -> V_242 , V_2 ) ;
F_114 ( & V_5 -> V_297 -> V_118 ) ;
return V_25 ;
}
static void F_115 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_106 * V_107 ;
int V_20 ;
F_116 ( V_2 ) ;
if ( F_117 ( V_5 ) )
F_57 ( & V_2 -> V_118 , L_19
L_20 , V_2 -> V_267 , ( int ) F_6 ( V_2 , V_163 ) ) ;
V_2 -> V_186 . V_303 ++ ;
for ( V_20 = 0 ; V_20 < V_5 -> V_103 ; V_20 ++ ) {
V_107 = & V_5 -> V_116 [ V_20 ] ;
V_107 -> V_120 = 0 ;
V_107 -> V_90 = 0xBADF00D0 ;
if ( V_5 -> V_102 [ V_20 ] )
F_46 ( V_5 -> V_102 [ V_20 ] ) ;
V_5 -> V_102 [ V_20 ] = NULL ;
}
for ( V_20 = 0 ; V_20 < V_5 -> V_105 ; V_20 ++ ) {
if ( V_5 -> V_104 [ V_20 ] )
F_46 ( V_5 -> V_104 [ V_20 ] ) ;
V_5 -> V_104 [ V_20 ] = NULL ;
}
F_60 ( V_2 , true ) ;
}
static int F_118 ( struct V_72 * V_73 , struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_108 * V_109 ;
T_1 V_183 ;
unsigned long V_272 ;
F_93 ( & V_5 -> V_245 , V_272 ) ;
if ( ( V_5 -> V_113 - V_5 -> V_115 ) >= ( V_5 -> V_105 - 4 ) ) {
if ( ! F_62 ( V_2 ) ) {
if ( F_119 ( V_5 ) )
F_120 ( & V_2 -> V_118 , L_21 ) ;
F_116 ( V_2 ) ;
F_95 ( & V_5 -> V_245 , V_272 ) ;
return V_304 ;
}
}
F_95 ( & V_5 -> V_245 , V_272 ) ;
V_183 = V_5 -> V_113 % V_5 -> V_105 ;
V_5 -> V_104 [ V_183 ] = V_73 ;
V_109 = & V_5 -> V_126 [ V_183 ] ;
if ( ! V_5 -> V_51 -> V_145 )
F_66 ( F_67 ( F_53 ( V_109 -> V_90 , 4 ) ) ,
V_73 -> V_305 + 2 ) ;
V_109 -> V_90 = F_50 ( & V_2 -> V_118 , V_73 -> V_76 , V_73 -> V_305 ,
V_185 ) ;
if ( V_73 -> V_305 < V_306 )
V_109 -> V_123 = V_306 ;
else
V_109 -> V_123 = V_73 -> V_305 ;
if ( V_183 >= V_5 -> V_105 - 1 )
V_109 -> V_120 |= F_28 ( V_5 , V_184 | V_129 ) ;
else
V_109 -> V_120 |= F_28 ( V_5 , V_184 ) ;
V_5 -> V_113 ++ ;
if ( ! ( F_6 ( V_2 , V_240 ) & F_36 ( V_5 ) ) )
F_4 ( V_2 , F_36 ( V_5 ) , V_240 ) ;
return V_307 ;
}
static int F_121 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_116 ( V_2 ) ;
F_4 ( V_2 , 0x0000 , V_143 ) ;
F_4 ( V_2 , 0 , V_240 ) ;
F_4 ( V_2 , 0 , V_181 ) ;
if ( V_5 -> V_256 ) {
F_122 ( V_5 -> V_256 ) ;
F_123 ( V_5 -> V_256 ) ;
}
F_113 ( V_2 -> V_242 , V_2 ) ;
F_45 ( V_2 ) ;
F_59 ( V_5 ) ;
F_114 ( & V_5 -> V_297 -> V_118 ) ;
return 0 ;
}
static struct V_308 * F_124 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_111 ( & V_5 -> V_297 -> V_118 ) ;
V_2 -> V_186 . V_309 += F_6 ( V_2 , V_310 ) ;
F_4 ( V_2 , 0 , V_310 ) ;
V_2 -> V_186 . V_311 += F_6 ( V_2 , V_312 ) ;
F_4 ( V_2 , 0 , V_312 ) ;
V_2 -> V_186 . V_218 += F_6 ( V_2 , V_313 ) ;
F_4 ( V_2 , 0 , V_313 ) ;
if ( F_16 ( V_5 ) ) {
V_2 -> V_186 . V_218 += F_6 ( V_2 , V_314 ) ;
F_4 ( V_2 , 0 , V_314 ) ;
V_2 -> V_186 . V_218 += F_6 ( V_2 , V_315 ) ;
F_4 ( V_2 , 0 , V_315 ) ;
} else {
V_2 -> V_186 . V_218 += F_6 ( V_2 , V_316 ) ;
F_4 ( V_2 , 0 , V_316 ) ;
}
F_114 ( & V_5 -> V_297 -> V_118 ) ;
return & V_2 -> V_186 ;
}
static int F_125 ( struct V_1 * V_2 , struct V_317 * V_318 ,
int V_319 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_255 * V_256 = V_5 -> V_256 ;
if ( ! F_107 ( V_2 ) )
return - V_293 ;
if ( ! V_256 )
return - V_320 ;
return F_126 ( V_256 , V_318 , V_319 ) ;
}
static void * F_127 ( struct V_4 * V_5 ,
int V_183 )
{
return F_128 ( V_5 , V_321 ) + ( V_183 / 8 * 4 ) ;
}
static T_1 F_129 ( int V_183 )
{
return 0x0f << ( 28 - ( ( V_183 % 8 ) * 4 ) ) ;
}
static T_1 F_130 ( struct V_4 * V_5 , int V_183 )
{
return ( 0x08 >> ( V_5 -> V_322 << 1 ) ) << ( 28 - ( ( V_183 % 8 ) * 4 ) ) ;
}
static void F_131 ( struct V_1 * V_2 ,
int V_183 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_323 ;
void * V_86 ;
V_86 = F_127 ( V_5 , V_183 ) ;
V_323 = F_10 ( V_86 ) ;
F_13 ( V_323 | F_130 ( V_5 , V_183 ) , V_86 ) ;
}
static bool F_132 ( struct V_1 * V_2 ,
int V_183 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_324 , V_325 , V_323 ;
void * V_86 ;
V_86 = F_127 ( V_5 , V_183 ) ;
V_324 = F_129 ( V_183 ) ;
V_325 = F_130 ( V_5 , V_183 ) & ~ V_324 ;
V_323 = F_10 ( V_86 ) ;
F_13 ( V_323 & ~ V_324 , V_86 ) ;
return V_323 & V_325 ;
}
static int F_133 ( struct V_1 * V_2 )
{
int V_326 = V_327 * 100 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
while ( ( F_134 ( V_5 , V_328 ) & V_329 ) ) {
F_135 ( 10 ) ;
V_326 -- ;
if ( V_326 <= 0 ) {
F_57 ( & V_2 -> V_118 , L_22 , V_296 ) ;
return - V_71 ;
}
}
return 0 ;
}
static int F_136 ( struct V_1 * V_2 , void * V_330 ,
const T_6 * V_90 )
{
T_1 V_140 ;
V_140 = V_90 [ 0 ] << 24 | V_90 [ 1 ] << 16 | V_90 [ 2 ] << 8 | V_90 [ 3 ] ;
F_13 ( V_140 , V_330 ) ;
if ( F_133 ( V_2 ) < 0 )
return - V_331 ;
V_140 = V_90 [ 4 ] << 8 | V_90 [ 5 ] ;
F_13 ( V_140 , V_330 + 4 ) ;
if ( F_133 ( V_2 ) < 0 )
return - V_331 ;
return 0 ;
}
static void F_137 ( void * V_330 , T_6 * V_90 )
{
T_1 V_140 ;
V_140 = F_10 ( V_330 ) ;
V_90 [ 0 ] = ( V_140 >> 24 ) & 0xff ;
V_90 [ 1 ] = ( V_140 >> 16 ) & 0xff ;
V_90 [ 2 ] = ( V_140 >> 8 ) & 0xff ;
V_90 [ 3 ] = V_140 & 0xff ;
V_140 = F_10 ( V_330 + 4 ) ;
V_90 [ 4 ] = ( V_140 >> 8 ) & 0xff ;
V_90 [ 5 ] = V_140 & 0xff ;
}
static int F_138 ( struct V_1 * V_2 , const T_6 * V_90 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
void * V_86 = F_128 ( V_5 , V_332 ) ;
int V_20 ;
T_6 V_333 [ V_334 ] ;
for ( V_20 = 0 ; V_20 < V_335 ; V_20 ++ , V_86 += 8 ) {
F_137 ( V_86 , V_333 ) ;
if ( memcmp ( V_90 , V_333 , V_334 ) == 0 )
return V_20 ;
}
return - V_336 ;
}
static int F_139 ( struct V_1 * V_2 )
{
T_6 V_337 [ V_334 ] ;
int V_183 ;
memset ( V_337 , 0 , sizeof( V_337 ) ) ;
V_183 = F_138 ( V_2 , V_337 ) ;
return ( V_183 < 0 ) ? - V_135 : V_183 ;
}
static int F_140 ( struct V_1 * V_2 ,
int V_183 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
void * V_86 = F_128 ( V_5 , V_332 ) ;
int V_25 ;
T_6 V_337 [ V_334 ] ;
F_22 ( V_5 , F_134 ( V_5 , V_338 ) &
~ ( 1 << ( 31 - V_183 ) ) , V_338 ) ;
memset ( V_337 , 0 , sizeof( V_337 ) ) ;
V_25 = F_136 ( V_2 , V_86 + V_183 * 8 , V_337 ) ;
if ( V_25 < 0 )
return V_25 ;
return 0 ;
}
static int F_141 ( struct V_1 * V_2 , const T_6 * V_90 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
void * V_86 = F_128 ( V_5 , V_332 ) ;
int V_20 , V_25 ;
if ( ! V_5 -> V_51 -> V_339 )
return 0 ;
V_20 = F_138 ( V_2 , V_90 ) ;
if ( V_20 < 0 ) {
V_20 = F_139 ( V_2 ) ;
if ( V_20 < 0 )
return - V_135 ;
V_25 = F_136 ( V_2 , V_86 + V_20 * 8 , V_90 ) ;
if ( V_25 < 0 )
return V_25 ;
F_22 ( V_5 , F_134 ( V_5 , V_338 ) |
( 1 << ( 31 - V_20 ) ) , V_338 ) ;
}
F_131 ( V_2 , V_20 ) ;
return 0 ;
}
static int F_142 ( struct V_1 * V_2 , const T_6 * V_90 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_20 , V_25 ;
if ( ! V_5 -> V_51 -> V_339 )
return 0 ;
V_20 = F_138 ( V_2 , V_90 ) ;
if ( V_20 ) {
if ( F_132 ( V_2 , V_20 ) )
goto V_340;
V_25 = F_140 ( V_2 , V_20 ) ;
if ( V_25 < 0 )
return V_25 ;
}
V_340:
return 0 ;
}
static int F_143 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_20 , V_25 ;
if ( F_144 ( ! V_5 -> V_51 -> V_339 ) )
return 0 ;
for ( V_20 = 0 ; V_20 < V_335 ; V_20 ++ ) {
if ( F_132 ( V_2 , V_20 ) )
continue;
V_25 = F_140 ( V_2 , V_20 ) ;
if ( V_25 < 0 )
return V_25 ;
}
return 0 ;
}
static void F_145 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_6 V_90 [ V_334 ] ;
void * V_86 = F_128 ( V_5 , V_332 ) ;
int V_20 ;
if ( F_144 ( ! V_5 -> V_51 -> V_339 ) )
return;
for ( V_20 = 0 ; V_20 < V_335 ; V_20 ++ , V_86 += 8 ) {
F_137 ( V_86 , V_90 ) ;
if ( F_146 ( V_90 ) )
F_142 ( V_2 , V_90 ) ;
}
}
static void F_147 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_341 ;
int V_342 = 0 ;
unsigned long V_272 ;
F_93 ( & V_5 -> V_245 , V_272 ) ;
V_341 = ( F_6 ( V_2 , V_12 ) & ~ V_343 ) | V_344 ;
if ( ! ( V_2 -> V_272 & V_345 ) ) {
F_145 ( V_2 ) ;
V_342 = 1 ;
}
if ( V_2 -> V_272 & V_346 ) {
F_145 ( V_2 ) ;
V_341 &= ~ V_344 ;
V_342 = 1 ;
}
if ( V_2 -> V_272 & V_347 ) {
F_143 ( V_2 ) ;
V_341 = ( V_341 & ~ V_344 ) | V_343 ;
} else if ( V_5 -> V_51 -> V_339 ) {
struct V_348 * V_349 ;
F_148 (ha, ndev) {
if ( V_342 && F_146 ( V_349 -> V_90 ) )
continue;
if ( F_141 ( V_2 , V_349 -> V_90 ) < 0 ) {
if ( ! V_342 ) {
F_145 ( V_2 ) ;
V_341 &= ~ V_344 ;
V_342 = 1 ;
}
}
}
} else {
V_341 = ( V_341 & ~ V_343 ) | V_344 ;
}
F_4 ( V_2 , V_341 , V_12 ) ;
F_95 ( & V_5 -> V_245 , V_272 ) ;
}
static int F_149 ( struct V_4 * V_5 )
{
if ( ! V_5 -> V_322 )
return V_350 ;
else
return V_351 ;
}
static int F_150 ( struct V_1 * V_2 , T_3 V_352 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_353 = F_149 ( V_5 ) ;
if ( F_144 ( ! V_5 -> V_51 -> V_339 ) )
return - V_354 ;
if ( ! V_352 )
return 0 ;
V_5 -> V_355 ++ ;
if ( V_5 -> V_355 > 1 ) {
F_22 ( V_5 , 0 , V_353 ) ;
return 0 ;
}
F_22 ( V_5 , V_356 | ( V_352 & V_357 ) ,
V_353 ) ;
return 0 ;
}
static int F_151 ( struct V_1 * V_2 , T_3 V_352 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_353 = F_149 ( V_5 ) ;
if ( F_144 ( ! V_5 -> V_51 -> V_339 ) )
return - V_354 ;
if ( ! V_352 )
return 0 ;
V_5 -> V_355 -- ;
F_22 ( V_5 , 0 , V_353 ) ;
return 0 ;
}
static void F_152 ( struct V_4 * V_5 )
{
F_22 ( V_5 , 0 , V_358 ) ;
F_22 ( V_5 , 0 , V_359 ) ;
F_22 ( V_5 , 0 , V_360 ) ;
F_22 ( V_5 , 0xc , V_361 ) ;
F_22 ( V_5 , 0xc , V_362 ) ;
F_22 ( V_5 , 0 , V_363 ) ;
F_22 ( V_5 , 0 , V_364 ) ;
F_22 ( V_5 , 0 , V_365 ) ;
F_22 ( V_5 , 0 , V_366 ) ;
F_22 ( V_5 , V_367 | V_368 , V_369 ) ;
if ( F_16 ( V_5 ) ) {
F_22 ( V_5 , 0 , V_370 ) ;
F_22 ( V_5 , 0 , V_371 ) ;
} else {
F_22 ( V_5 , 0 , V_372 ) ;
F_22 ( V_5 , 0 , V_373 ) ;
}
F_22 ( V_5 , 0 , V_374 ) ;
F_22 ( V_5 , 0 , V_375 ) ;
F_22 ( V_5 , 0 , V_338 ) ;
F_22 ( V_5 , 0 , V_321 ) ;
F_22 ( V_5 , 0 , V_376 ) ;
F_22 ( V_5 , 0 , V_377 ) ;
F_22 ( V_5 , 0 , V_378 ) ;
}
static int F_153 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_264 * V_379 = F_154 ( & V_2 -> V_118 ) ;
F_155 ( V_379 ) ;
F_156 ( & V_2 -> V_118 , NULL ) ;
F_47 ( V_379 -> V_242 ) ;
F_157 ( V_379 ) ;
F_47 ( V_5 -> V_96 ) ;
return 0 ;
}
static int F_158 ( struct V_1 * V_2 , int V_265 ,
struct V_380 * V_381 )
{
int V_25 , V_20 ;
struct V_95 * V_96 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_96 = F_159 ( sizeof( struct V_95 ) , V_134 ) ;
if ( ! V_96 ) {
V_25 = - V_135 ;
goto V_29;
}
V_96 -> V_90 = V_5 -> V_90 + V_5 -> V_86 [ V_382 ] ;
V_96 -> V_97 = V_381 -> V_383 ;
V_96 -> V_100 = 0x08 ;
V_96 -> V_99 = 0x04 ;
V_96 -> V_98 = 0x02 ;
V_96 -> V_101 = 0x01 ;
V_96 -> V_93 . V_384 = & V_385 ;
V_5 -> V_96 = V_96 ;
V_5 -> V_264 = F_160 ( & V_96 -> V_93 ) ;
if ( ! V_5 -> V_264 ) {
V_25 = - V_135 ;
goto V_386;
}
V_5 -> V_264 -> V_267 = L_23 ;
V_5 -> V_264 -> V_387 = & V_2 -> V_118 ;
snprintf ( V_5 -> V_264 -> V_265 , V_262 , L_24 ,
V_5 -> V_297 -> V_267 , V_265 ) ;
V_5 -> V_264 -> V_242 = F_161 ( sizeof( int ) * V_388 , V_134 ) ;
if ( ! V_5 -> V_264 -> V_242 ) {
V_25 = - V_135 ;
goto V_389;
}
for ( V_20 = 0 ; V_20 < V_388 ; V_20 ++ )
V_5 -> V_264 -> V_242 [ V_20 ] = V_390 ;
V_25 = F_162 ( V_5 -> V_264 ) ;
if ( V_25 )
goto V_302;
F_156 ( & V_2 -> V_118 , V_5 -> V_264 ) ;
return 0 ;
V_302:
F_47 ( V_5 -> V_264 -> V_242 ) ;
V_389:
F_157 ( V_5 -> V_264 ) ;
V_386:
F_47 ( V_96 ) ;
V_29:
return V_25 ;
}
static const T_3 * F_163 ( int V_391 )
{
const T_3 * V_86 = NULL ;
switch ( V_391 ) {
case V_392 :
V_86 = V_87 ;
break;
case V_393 :
V_86 = V_394 ;
break;
case V_395 :
V_86 = V_396 ;
break;
default:
F_25 ( V_70 L_25 , V_391 ) ;
break;
}
return V_86 ;
}
static int F_164 ( struct V_397 * V_297 )
{
int V_25 , V_398 = 0 ;
struct V_399 * V_400 ;
struct V_1 * V_2 = NULL ;
struct V_4 * V_5 = NULL ;
struct V_380 * V_381 ;
V_400 = F_165 ( V_297 , V_401 , 0 ) ;
if ( F_144 ( V_400 == NULL ) ) {
F_57 ( & V_297 -> V_118 , L_26 ) ;
V_25 = - V_293 ;
goto V_29;
}
V_2 = F_166 ( sizeof( struct V_4 ) ) ;
if ( ! V_2 ) {
V_25 = - V_135 ;
goto V_29;
}
V_2 -> V_402 = V_400 -> V_139 ;
V_398 = V_297 -> V_265 ;
if ( V_398 < 0 )
V_398 = 0 ;
V_2 -> V_403 = - 1 ;
V_25 = F_167 ( V_297 , 0 ) ;
if ( V_25 < 0 ) {
V_25 = - V_320 ;
goto V_404;
}
V_2 -> V_242 = V_25 ;
F_168 ( V_2 , & V_297 -> V_118 ) ;
F_169 ( V_2 ) ;
V_5 = F_2 ( V_2 ) ;
V_5 -> V_105 = V_405 ;
V_5 -> V_103 = V_406 ;
V_5 -> V_90 = F_170 ( V_400 -> V_139 , F_171 ( V_400 ) ) ;
if ( V_5 -> V_90 == NULL ) {
V_25 = - V_135 ;
F_57 ( & V_297 -> V_118 , L_27 ) ;
goto V_404;
}
F_172 ( & V_5 -> V_245 ) ;
V_5 -> V_297 = V_297 ;
F_173 ( & V_297 -> V_118 ) ;
F_174 ( & V_297 -> V_118 ) ;
V_381 = (struct V_380 * ) ( V_297 -> V_118 . V_407 ) ;
V_5 -> V_261 = V_381 -> V_408 ;
V_5 -> V_6 = V_381 -> V_6 ;
V_5 -> V_79 = V_381 -> V_79 ;
V_5 -> V_221 = V_381 -> V_221 ;
V_5 -> V_224 = V_381 -> V_224 ;
V_5 -> V_86 = F_163 ( V_381 -> V_391 ) ;
#if F_8 ( V_409 )
V_5 -> V_51 = F_20 ( V_5 ) ;
#else
V_5 -> V_51 = & V_42 ;
#endif
F_24 ( V_5 -> V_51 ) ;
V_2 -> V_410 = & V_411 ;
F_175 ( V_2 , & V_412 ) ;
V_2 -> V_413 = V_414 ;
V_5 -> V_275 = V_415 ;
F_35 ( V_2 , V_381 -> V_416 ) ;
if ( V_5 -> V_51 -> V_339 ) {
struct V_399 * V_417 ;
V_417 = F_165 ( V_297 , V_401 , 1 ) ;
if ( ! V_417 ) {
F_57 ( & V_297 -> V_118 , L_28 ) ;
V_25 = - V_320 ;
goto V_404;
}
V_5 -> V_418 = F_170 ( V_417 -> V_139 ,
F_171 ( V_417 ) ) ;
if ( V_5 -> V_418 == NULL ) {
V_25 = - V_135 ;
F_57 ( & V_297 -> V_118 , L_29 ) ;
goto V_404;
}
V_5 -> V_322 = V_398 % 2 ;
V_2 -> V_419 = V_420 ;
}
if ( ! V_398 || V_381 -> V_421 ) {
if ( V_5 -> V_51 -> V_422 )
V_5 -> V_51 -> V_422 ( V_2 ) ;
if ( V_5 -> V_51 -> V_339 ) {
F_152 ( V_5 ) ;
}
}
V_25 = F_176 ( V_2 ) ;
if ( V_25 )
goto V_404;
V_25 = F_158 ( V_2 , V_297 -> V_265 , V_381 ) ;
if ( V_25 )
goto V_423;
F_177 ( L_30 ,
( T_1 ) V_2 -> V_402 , V_2 -> V_82 , V_2 -> V_242 ) ;
F_178 ( V_297 , V_2 ) ;
return V_25 ;
V_423:
F_179 ( V_2 ) ;
V_404:
if ( V_5 && V_5 -> V_90 )
F_180 ( V_5 -> V_90 ) ;
if ( V_5 && V_5 -> V_418 )
F_180 ( V_5 -> V_418 ) ;
if ( V_2 )
F_181 ( V_2 ) ;
V_29:
return V_25 ;
}
static int F_182 ( struct V_397 * V_297 )
{
struct V_1 * V_2 = F_183 ( V_297 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_51 -> V_339 )
F_180 ( V_5 -> V_418 ) ;
F_153 ( V_2 ) ;
F_179 ( V_2 ) ;
F_184 ( & V_297 -> V_118 ) ;
F_180 ( V_5 -> V_90 ) ;
F_181 ( V_2 ) ;
F_178 ( V_297 , NULL ) ;
return 0 ;
}
static int F_185 ( struct V_424 * V_118 )
{
return 0 ;
}
