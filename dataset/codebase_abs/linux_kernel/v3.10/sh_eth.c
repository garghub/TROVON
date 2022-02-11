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
switch ( V_5 -> V_14 ) {
case 10 :
F_4 ( V_2 , F_6 ( V_2 , V_12 ) & ~ V_15 , V_12 ) ;
break;
case 100 :
F_4 ( V_2 , F_6 ( V_2 , V_12 ) | V_15 , V_12 ) ;
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
switch ( V_5 -> V_14 ) {
case 10 :
F_4 ( V_2 , F_6 ( V_2 , V_12 ) & ~ V_16 , V_12 ) ;
break;
case 100 :
F_4 ( V_2 , F_6 ( V_2 , V_12 ) | V_16 , V_12 ) ;
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
switch ( V_5 -> V_14 ) {
case 10 :
F_4 ( V_2 , 0 , V_17 ) ;
break;
case 100 :
F_4 ( V_2 , 1 , V_17 ) ;
break;
default:
break;
}
}
static void F_8 ( struct V_1 * V_2 )
{
int V_18 ;
unsigned long V_19 [ 2 ] , V_20 [ 2 ] ;
for ( V_18 = 0 ; V_18 < 2 ; V_18 ++ ) {
V_20 [ V_18 ] = F_9 ( ( void * ) F_10 ( V_18 ) ) ;
V_19 [ V_18 ] = F_9 ( ( void * ) F_11 ( V_18 ) ) ;
}
F_12 ( V_21 , ( void * ) ( V_22 + 0x1800 ) ) ;
F_13 ( 1 ) ;
for ( V_18 = 0 ; V_18 < 2 ; V_18 ++ ) {
F_12 ( V_20 [ V_18 ] , ( void * ) F_10 ( V_18 ) ) ;
F_12 ( V_19 [ V_18 ] , ( void * ) F_11 ( V_18 ) ) ;
}
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_23 = 0 ;
if ( F_15 ( V_5 ) ) {
F_4 ( V_2 , 0x03 , V_24 ) ;
F_4 ( V_2 , F_6 ( V_2 , V_25 ) | V_26 ,
V_25 ) ;
V_23 = F_16 ( V_2 ) ;
if ( V_23 )
goto V_27;
F_4 ( V_2 , 0x0 , V_28 ) ;
F_4 ( V_2 , 0x0 , V_29 ) ;
F_4 ( V_2 , 0x0 , V_30 ) ;
F_4 ( V_2 , 0x0 , V_31 ) ;
F_4 ( V_2 , 0x0 , V_32 ) ;
F_4 ( V_2 , 0x0 , V_33 ) ;
F_4 ( V_2 , 0x0 , V_34 ) ;
F_4 ( V_2 , 0x0 , V_35 ) ;
} else {
F_4 ( V_2 , F_6 ( V_2 , V_25 ) | V_36 ,
V_25 ) ;
F_13 ( 3 ) ;
F_4 ( V_2 , F_6 ( V_2 , V_25 ) & ~ V_36 ,
V_25 ) ;
}
V_27:
return V_23 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_11 )
F_4 ( V_2 , F_6 ( V_2 , V_12 ) | V_13 , V_12 ) ;
else
F_4 ( V_2 , F_6 ( V_2 , V_12 ) & ~ V_13 , V_12 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_5 -> V_14 ) {
case 10 :
F_4 ( V_2 , 0x00000000 , V_37 ) ;
break;
case 100 :
F_4 ( V_2 , 0x00000010 , V_37 ) ;
break;
case 1000 :
F_4 ( V_2 , 0x00000020 , V_37 ) ;
break;
default:
break;
}
}
static struct V_38 * F_19 ( struct V_4 * V_5 )
{
if ( F_15 ( V_5 ) )
return & V_39 ;
else
return & V_40 ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_21 ( V_5 , V_21 , V_41 ) ;
F_13 ( 1 ) ;
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
switch ( V_5 -> V_14 ) {
case 10 :
F_4 ( V_2 , V_42 , V_37 ) ;
break;
case 100 :
F_4 ( V_2 , V_43 , V_37 ) ;
break;
case 1000 :
F_4 ( V_2 , V_44 , V_37 ) ;
break;
default:
break;
}
}
static int F_14 ( struct V_1 * V_2 )
{
int V_23 = 0 ;
F_4 ( V_2 , V_45 , V_24 ) ;
F_4 ( V_2 , F_6 ( V_2 , V_25 ) | V_26 , V_25 ) ;
V_23 = F_16 ( V_2 ) ;
if ( V_23 )
goto V_27;
F_4 ( V_2 , 0x0 , V_28 ) ;
F_4 ( V_2 , 0x0 , V_29 ) ;
F_4 ( V_2 , 0x0 , V_30 ) ;
F_4 ( V_2 , 0x0 , V_31 ) ;
F_4 ( V_2 , 0x0 , V_32 ) ;
F_4 ( V_2 , 0x0 , V_33 ) ;
F_4 ( V_2 , 0x0 , V_34 ) ;
F_4 ( V_2 , 0x0 , V_35 ) ;
F_22 ( V_2 ) ;
if ( V_40 . V_46 )
F_1 ( V_2 ) ;
V_27:
return V_23 ;
}
static void F_22 ( struct V_1 * V_2 )
{
if ( V_40 . V_47 )
F_4 ( V_2 , 0x0 , V_48 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_21 ( V_5 , V_21 , V_41 ) ;
F_13 ( 1 ) ;
F_1 ( V_2 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_23 = 0 ;
F_4 ( V_2 , V_45 , V_24 ) ;
F_4 ( V_2 , F_6 ( V_2 , V_25 ) | V_26 , V_25 ) ;
V_23 = F_16 ( V_2 ) ;
if ( V_23 )
goto V_27;
F_4 ( V_2 , 0x0 , V_28 ) ;
F_4 ( V_2 , 0x0 , V_29 ) ;
F_4 ( V_2 , 0x0 , V_30 ) ;
F_4 ( V_2 , 0x0 , V_31 ) ;
F_4 ( V_2 , 0x0 , V_32 ) ;
F_4 ( V_2 , 0x0 , V_33 ) ;
F_4 ( V_2 , 0x0 , V_34 ) ;
F_4 ( V_2 , 0x0 , V_35 ) ;
V_27:
return V_23 ;
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
switch ( V_5 -> V_14 ) {
case 10 :
F_4 ( V_2 , V_42 , V_37 ) ;
break;
case 100 :
F_4 ( V_2 , V_43 , V_37 ) ;
break;
case 1000 :
F_4 ( V_2 , V_44 , V_37 ) ;
break;
default:
break;
}
}
static void F_23 ( struct V_38 * V_49 )
{
if ( ! V_49 -> V_50 )
V_49 -> V_50 = V_51 ;
if ( ! V_49 -> V_52 )
V_49 -> V_52 = V_53 ;
if ( ! V_49 -> V_54 )
V_49 -> V_54 = V_55 | \
V_56 ;
if ( ! V_49 -> V_57 )
V_49 -> V_57 = V_58 ;
if ( ! V_49 -> V_59 )
V_49 -> V_59 = V_60 ;
if ( ! V_49 -> V_61 )
V_49 -> V_61 = V_62 ;
if ( ! V_49 -> V_63 )
V_49 -> V_63 = V_64 ;
if ( ! V_49 -> V_65 )
V_49 -> V_65 = V_66 ;
}
static int F_14 ( struct V_1 * V_2 )
{
F_4 ( V_2 , F_6 ( V_2 , V_25 ) | V_36 , V_25 ) ;
F_13 ( 3 ) ;
F_4 ( V_2 , F_6 ( V_2 , V_25 ) & ~ V_36 , V_25 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_23 = 0 ;
int V_67 = 100 ;
while ( V_67 > 0 ) {
if ( ! ( F_6 ( V_2 , V_25 ) & 0x3 ) )
break;
F_13 ( 1 ) ;
V_67 -- ;
}
if ( V_67 <= 0 ) {
F_24 ( L_2 ) ;
V_23 = - V_68 ;
}
return V_23 ;
}
static void F_25 ( struct V_69 * V_70 )
{
int V_71 ;
V_71 = V_72 - ( ( T_1 ) V_70 -> V_73 & ( V_72 - 1 ) ) ;
if ( V_71 )
F_26 ( V_70 , V_71 ) ;
}
static void F_25 ( struct V_69 * V_70 )
{
F_26 ( V_70 , V_74 ) ;
}
static inline T_2 F_27 ( struct V_4 * V_5 , T_1 V_75 )
{
switch ( V_5 -> V_76 ) {
case V_77 :
return F_28 ( V_75 ) ;
case V_78 :
return F_29 ( V_75 ) ;
}
return V_75 ;
}
static inline T_2 F_30 ( struct V_4 * V_5 , T_1 V_75 )
{
switch ( V_5 -> V_76 ) {
case V_77 :
return F_31 ( V_75 ) ;
case V_78 :
return F_32 ( V_75 ) ;
}
return V_75 ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_4 ( V_2 ,
( V_2 -> V_79 [ 0 ] << 24 ) | ( V_2 -> V_79 [ 1 ] << 16 ) |
( V_2 -> V_79 [ 2 ] << 8 ) | ( V_2 -> V_79 [ 3 ] ) , V_80 ) ;
F_4 ( V_2 ,
( V_2 -> V_79 [ 4 ] << 8 ) | ( V_2 -> V_79 [ 5 ] ) , V_81 ) ;
}
static void F_34 ( struct V_1 * V_2 , unsigned char * V_82 )
{
if ( V_82 [ 0 ] || V_82 [ 1 ] || V_82 [ 2 ] || V_82 [ 3 ] || V_82 [ 4 ] || V_82 [ 5 ] ) {
memcpy ( V_2 -> V_79 , V_82 , 6 ) ;
} else {
V_2 -> V_79 [ 0 ] = ( F_6 ( V_2 , V_80 ) >> 24 ) ;
V_2 -> V_79 [ 1 ] = ( F_6 ( V_2 , V_80 ) >> 16 ) & 0xFF ;
V_2 -> V_79 [ 2 ] = ( F_6 ( V_2 , V_80 ) >> 8 ) & 0xFF ;
V_2 -> V_79 [ 3 ] = ( F_6 ( V_2 , V_80 ) & 0xFF ) ;
V_2 -> V_79 [ 4 ] = ( F_6 ( V_2 , V_81 ) >> 8 ) & 0xFF ;
V_2 -> V_79 [ 5 ] = ( F_6 ( V_2 , V_81 ) & 0xFF ) ;
}
}
static int F_15 ( struct V_4 * V_5 )
{
if ( V_5 -> V_83 == V_84 )
return 1 ;
else
return 0 ;
}
static unsigned long F_35 ( struct V_4 * V_5 )
{
if ( F_15 ( V_5 ) )
return V_85 ;
else
return V_86 ;
}
static void F_36 ( void * V_87 , T_1 V_88 )
{
F_12 ( F_9 ( V_87 ) | V_88 , V_87 ) ;
}
static void F_37 ( void * V_87 , T_1 V_88 )
{
F_12 ( ( F_9 ( V_87 ) & ~ V_88 ) , V_87 ) ;
}
static int F_38 ( void * V_87 , T_1 V_88 )
{
return ( F_9 ( V_87 ) & V_88 ) != 0 ;
}
static void F_39 ( struct V_89 * V_90 , int V_91 )
{
struct V_92 * V_93 = F_40 ( V_90 , struct V_92 , V_90 ) ;
if ( V_93 -> V_94 )
V_93 -> V_94 ( V_93 -> V_87 ) ;
if ( V_91 )
F_36 ( V_93 -> V_87 , V_93 -> V_95 ) ;
else
F_37 ( V_93 -> V_87 , V_93 -> V_95 ) ;
}
static void F_41 ( struct V_89 * V_90 , int V_91 )
{
struct V_92 * V_93 = F_40 ( V_90 , struct V_92 , V_90 ) ;
if ( V_93 -> V_94 )
V_93 -> V_94 ( V_93 -> V_87 ) ;
if ( V_91 )
F_36 ( V_93 -> V_87 , V_93 -> V_96 ) ;
else
F_37 ( V_93 -> V_87 , V_93 -> V_96 ) ;
}
static int F_42 ( struct V_89 * V_90 )
{
struct V_92 * V_93 = F_40 ( V_90 , struct V_92 , V_90 ) ;
if ( V_93 -> V_94 )
V_93 -> V_94 ( V_93 -> V_87 ) ;
return F_38 ( V_93 -> V_87 , V_93 -> V_97 ) ;
}
static void F_43 ( struct V_89 * V_90 , int V_91 )
{
struct V_92 * V_93 = F_40 ( V_90 , struct V_92 , V_90 ) ;
if ( V_93 -> V_94 )
V_93 -> V_94 ( V_93 -> V_87 ) ;
if ( V_91 )
F_36 ( V_93 -> V_87 , V_93 -> V_98 ) ;
else
F_37 ( V_93 -> V_87 , V_93 -> V_98 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_18 ;
if ( V_5 -> V_99 ) {
for ( V_18 = 0 ; V_18 < V_5 -> V_100 ; V_18 ++ ) {
if ( V_5 -> V_99 [ V_18 ] )
F_45 ( V_5 -> V_99 [ V_18 ] ) ;
}
}
F_46 ( V_5 -> V_99 ) ;
V_5 -> V_99 = NULL ;
if ( V_5 -> V_101 ) {
for ( V_18 = 0 ; V_18 < V_5 -> V_102 ; V_18 ++ ) {
if ( V_5 -> V_101 [ V_18 ] )
F_45 ( V_5 -> V_101 [ V_18 ] ) ;
}
}
F_46 ( V_5 -> V_101 ) ;
V_5 -> V_101 = NULL ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_18 ;
struct V_69 * V_70 ;
struct V_103 * V_104 = NULL ;
struct V_105 * V_106 = NULL ;
int V_107 = sizeof( * V_104 ) * V_5 -> V_100 ;
int V_108 = sizeof( * V_106 ) * V_5 -> V_102 ;
V_5 -> V_109 = V_5 -> V_110 = 0 ;
V_5 -> V_111 = V_5 -> V_112 = 0 ;
memset ( V_5 -> V_113 , 0 , V_107 ) ;
for ( V_18 = 0 ; V_18 < V_5 -> V_100 ; V_18 ++ ) {
V_5 -> V_99 [ V_18 ] = NULL ;
V_70 = F_48 ( V_2 , V_5 -> V_114 ) ;
V_5 -> V_99 [ V_18 ] = V_70 ;
if ( V_70 == NULL )
break;
F_49 ( & V_2 -> V_115 , V_70 -> V_73 , V_5 -> V_114 ,
V_116 ) ;
F_25 ( V_70 ) ;
V_104 = & V_5 -> V_113 [ V_18 ] ;
V_104 -> V_87 = F_50 ( F_51 ( V_70 -> V_73 , 4 ) ) ;
V_104 -> V_117 = F_27 ( V_5 , V_118 | V_119 ) ;
V_104 -> V_120 = F_52 ( V_5 -> V_114 , 16 ) ;
if ( V_18 == 0 ) {
F_4 ( V_2 , V_5 -> V_121 , V_32 ) ;
if ( F_15 ( V_5 ) )
F_4 ( V_2 , V_5 -> V_121 , V_33 ) ;
}
}
V_5 -> V_111 = ( T_1 ) ( V_18 - V_5 -> V_100 ) ;
V_104 -> V_117 |= F_27 ( V_5 , V_122 ) ;
memset ( V_5 -> V_123 , 0 , V_108 ) ;
for ( V_18 = 0 ; V_18 < V_5 -> V_102 ; V_18 ++ ) {
V_5 -> V_101 [ V_18 ] = NULL ;
V_106 = & V_5 -> V_123 [ V_18 ] ;
V_106 -> V_117 = F_27 ( V_5 , V_124 ) ;
V_106 -> V_120 = 0 ;
if ( V_18 == 0 ) {
F_4 ( V_2 , V_5 -> V_125 , V_28 ) ;
if ( F_15 ( V_5 ) )
F_4 ( V_2 , V_5 -> V_125 , V_29 ) ;
}
}
V_106 -> V_117 |= F_27 ( V_5 , V_126 ) ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_107 , V_108 , V_23 = 0 ;
V_5 -> V_114 = ( V_2 -> V_127 <= 1492 ? V_128 :
( ( ( V_2 -> V_127 + 26 + 7 ) & ~ 7 ) + 2 + 16 ) ) ;
if ( V_5 -> V_49 -> V_129 )
V_5 -> V_114 += V_130 ;
V_5 -> V_99 = F_54 ( V_5 -> V_100 ,
sizeof( * V_5 -> V_99 ) , V_131 ) ;
if ( ! V_5 -> V_99 ) {
V_23 = - V_132 ;
return V_23 ;
}
V_5 -> V_101 = F_54 ( V_5 -> V_102 ,
sizeof( * V_5 -> V_101 ) , V_131 ) ;
if ( ! V_5 -> V_101 ) {
V_23 = - V_132 ;
goto V_133;
}
V_107 = sizeof( struct V_103 ) * V_5 -> V_100 ;
V_5 -> V_113 = F_55 ( NULL , V_107 , & V_5 -> V_121 ,
V_131 ) ;
if ( ! V_5 -> V_113 ) {
V_23 = - V_132 ;
goto V_134;
}
V_5 -> V_111 = 0 ;
V_108 = sizeof( struct V_105 ) * V_5 -> V_102 ;
V_5 -> V_123 = F_55 ( NULL , V_108 , & V_5 -> V_125 ,
V_131 ) ;
if ( ! V_5 -> V_123 ) {
V_23 = - V_132 ;
goto V_134;
}
return V_23 ;
V_134:
F_56 ( NULL , V_107 , V_5 -> V_113 , V_5 -> V_121 ) ;
V_133:
F_44 ( V_2 ) ;
V_5 -> V_123 = NULL ;
V_5 -> V_113 = NULL ;
return V_23 ;
}
static void F_57 ( struct V_4 * V_5 )
{
int V_135 ;
if ( V_5 -> V_113 ) {
V_135 = sizeof( struct V_103 ) * V_5 -> V_100 ;
F_56 ( NULL , V_135 , V_5 -> V_113 ,
V_5 -> V_121 ) ;
V_5 -> V_113 = NULL ;
}
if ( V_5 -> V_123 ) {
V_135 = sizeof( struct V_105 ) * V_5 -> V_102 ;
F_56 ( NULL , V_135 , V_5 -> V_123 ,
V_5 -> V_125 ) ;
V_5 -> V_123 = NULL ;
}
}
static int F_58 ( struct V_1 * V_2 , bool V_136 )
{
int V_23 = 0 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_137 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 )
goto V_27;
F_47 ( V_2 ) ;
if ( V_5 -> V_49 -> V_129 )
F_4 ( V_2 , V_5 -> V_49 -> V_138 , V_139 ) ;
F_4 ( V_2 , 0 , V_140 ) ;
#if F_59 ( V_141 )
if ( V_5 -> V_49 -> V_142 )
F_4 ( V_2 , V_143 , V_25 ) ;
else
#endif
F_4 ( V_2 , 0 , V_25 ) ;
F_4 ( V_2 , V_5 -> V_49 -> V_57 , V_144 ) ;
F_4 ( V_2 , 0 , V_145 ) ;
F_4 ( V_2 , V_5 -> V_49 -> V_59 , V_146 ) ;
F_4 ( V_2 , V_147 | V_148 | V_149 , V_150 ) ;
if ( V_5 -> V_49 -> V_151 )
F_4 ( V_2 , 0x800 , V_152 ) ;
F_4 ( V_2 , V_5 -> V_49 -> V_54 , V_153 ) ;
if ( ! V_5 -> V_49 -> V_154 )
F_4 ( V_2 , 0 , V_155 ) ;
F_4 ( V_2 , V_2 -> V_127 + V_156 + V_157 + V_158 ,
V_159 ) ;
F_4 ( V_2 , F_6 ( V_2 , V_160 ) , V_160 ) ;
if ( V_136 )
F_4 ( V_2 , V_5 -> V_49 -> V_161 , V_140 ) ;
V_137 = ( F_6 ( V_2 , V_12 ) & V_13 ) |
V_162 | ( V_5 -> V_11 ? V_13 : 0 ) | V_163 | V_164 ;
F_4 ( V_2 , V_137 , V_12 ) ;
if ( V_5 -> V_49 -> V_165 )
V_5 -> V_49 -> V_165 ( V_2 ) ;
F_4 ( V_2 , V_5 -> V_49 -> V_50 , V_166 ) ;
if ( V_136 )
F_4 ( V_2 , V_5 -> V_49 -> V_52 , V_167 ) ;
F_33 ( V_2 ) ;
if ( V_5 -> V_49 -> V_168 )
F_4 ( V_2 , V_169 , V_170 ) ;
if ( V_5 -> V_49 -> V_171 )
F_4 ( V_2 , V_172 , V_173 ) ;
if ( V_5 -> V_49 -> V_174 )
F_4 ( V_2 , V_175 , V_176 ) ;
if ( V_136 ) {
F_4 ( V_2 , V_177 , V_178 ) ;
F_60 ( V_2 ) ;
}
V_27:
return V_23 ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_105 * V_106 ;
int V_179 = 0 ;
int V_180 = 0 ;
for (; V_5 -> V_110 - V_5 -> V_112 > 0 ; V_5 -> V_112 ++ ) {
V_180 = V_5 -> V_112 % V_5 -> V_102 ;
V_106 = & V_5 -> V_123 [ V_180 ] ;
if ( V_106 -> V_117 & F_27 ( V_5 , V_181 ) )
break;
if ( V_5 -> V_101 [ V_180 ] ) {
F_62 ( & V_2 -> V_115 , V_106 -> V_87 ,
V_106 -> V_120 , V_182 ) ;
F_63 ( V_5 -> V_101 [ V_180 ] ) ;
V_5 -> V_101 [ V_180 ] = NULL ;
V_179 ++ ;
}
V_106 -> V_117 = F_27 ( V_5 , V_124 ) ;
if ( V_180 >= V_5 -> V_102 - 1 )
V_106 -> V_117 |= F_27 ( V_5 , V_126 ) ;
V_2 -> V_183 . V_184 ++ ;
V_2 -> V_183 . V_185 += V_106 -> V_120 ;
}
return V_179 ;
}
static int F_64 ( struct V_1 * V_2 , T_1 V_186 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_103 * V_104 ;
int V_180 = V_5 -> V_109 % V_5 -> V_100 ;
int V_187 = ( V_5 -> V_111 + V_5 -> V_100 ) - V_5 -> V_109 ;
struct V_69 * V_70 ;
T_3 V_188 = 0 ;
T_1 V_189 ;
V_104 = & V_5 -> V_113 [ V_180 ] ;
while ( ! ( V_104 -> V_117 & F_27 ( V_5 , V_118 ) ) ) {
V_189 = F_30 ( V_5 , V_104 -> V_117 ) ;
V_188 = V_104 -> V_190 ;
if ( -- V_187 < 0 )
break;
if ( ! ( V_189 & V_191 ) )
V_2 -> V_183 . V_192 ++ ;
#if F_59 ( V_193 )
V_189 >>= 16 ;
#endif
if ( V_189 & ( V_194 | V_195 | V_196 | V_197 |
V_198 | V_199 | V_200 ) ) {
V_2 -> V_183 . V_201 ++ ;
if ( V_189 & V_194 )
V_2 -> V_183 . V_202 ++ ;
if ( V_189 & V_195 )
V_2 -> V_183 . V_203 ++ ;
if ( V_189 & V_196 )
V_2 -> V_183 . V_192 ++ ;
if ( V_189 & V_197 )
V_2 -> V_183 . V_192 ++ ;
if ( V_189 & V_199 )
V_2 -> V_183 . V_204 ++ ;
if ( V_189 & V_200 )
V_2 -> V_183 . V_205 ++ ;
} else {
if ( ! V_5 -> V_49 -> V_142 )
F_65 (
F_66 ( F_52 ( V_104 -> V_87 , 4 ) ) ,
V_188 + 2 ) ;
V_70 = V_5 -> V_99 [ V_180 ] ;
V_5 -> V_99 [ V_180 ] = NULL ;
if ( V_5 -> V_49 -> V_129 )
F_26 ( V_70 , V_130 ) ;
F_67 ( V_70 , V_188 ) ;
V_70 -> V_206 = F_68 ( V_70 , V_2 ) ;
F_69 ( V_70 ) ;
V_2 -> V_183 . V_207 ++ ;
V_2 -> V_183 . V_208 += V_188 ;
}
V_104 -> V_117 |= F_27 ( V_5 , V_118 ) ;
V_180 = ( ++ V_5 -> V_109 ) % V_5 -> V_100 ;
V_104 = & V_5 -> V_113 [ V_180 ] ;
}
for (; V_5 -> V_109 - V_5 -> V_111 > 0 ; V_5 -> V_111 ++ ) {
V_180 = V_5 -> V_111 % V_5 -> V_100 ;
V_104 = & V_5 -> V_113 [ V_180 ] ;
V_104 -> V_120 = F_52 ( V_5 -> V_114 , 16 ) ;
if ( V_5 -> V_99 [ V_180 ] == NULL ) {
V_70 = F_48 ( V_2 , V_5 -> V_114 ) ;
V_5 -> V_99 [ V_180 ] = V_70 ;
if ( V_70 == NULL )
break;
F_49 ( & V_2 -> V_115 , V_70 -> V_73 , V_5 -> V_114 ,
V_116 ) ;
F_25 ( V_70 ) ;
F_70 ( V_70 ) ;
V_104 -> V_87 = F_50 ( F_51 ( V_70 -> V_73 , 4 ) ) ;
}
if ( V_180 >= V_5 -> V_100 - 1 )
V_104 -> V_117 |=
F_27 ( V_5 , V_118 | V_119 | V_122 ) ;
else
V_104 -> V_117 |=
F_27 ( V_5 , V_118 | V_119 ) ;
}
if ( ! ( F_6 ( V_2 , V_178 ) & V_177 ) ) {
if ( V_186 & V_209 )
V_5 -> V_109 = V_5 -> V_111 =
( F_6 ( V_2 , V_33 ) -
F_6 ( V_2 , V_32 ) ) >> 4 ;
F_4 ( V_2 , V_177 , V_178 ) ;
}
return 0 ;
}
static void F_71 ( struct V_1 * V_2 )
{
F_4 ( V_2 , F_6 ( V_2 , V_12 ) &
~ ( V_164 | V_163 ) , V_12 ) ;
}
static void F_72 ( struct V_1 * V_2 )
{
F_4 ( V_2 , F_6 ( V_2 , V_12 ) |
( V_164 | V_163 ) , V_12 ) ;
}
static void F_73 ( struct V_1 * V_2 , int V_186 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_210 ;
T_1 V_211 ;
T_1 V_212 ;
if ( V_186 & V_213 ) {
V_210 = F_6 ( V_2 , V_166 ) ;
F_4 ( V_2 , V_210 , V_166 ) ;
if ( V_210 & V_214 )
V_2 -> V_183 . V_215 ++ ;
if ( V_210 & V_216 ) {
if ( V_5 -> V_49 -> V_217 || V_5 -> V_218 ) {
goto V_219;
} else {
V_211 = ( F_6 ( V_2 , V_220 ) ) ;
if ( V_5 -> V_221 )
V_211 = ~ V_211 ;
}
if ( ! ( V_211 & V_222 ) )
F_71 ( V_2 ) ;
else {
F_4 ( V_2 , F_6 ( V_2 , V_140 ) &
~ V_223 , V_140 ) ;
F_4 ( V_2 , F_6 ( V_2 , V_166 ) ,
V_166 ) ;
F_4 ( V_2 , F_6 ( V_2 , V_140 ) |
V_223 , V_140 ) ;
F_72 ( V_2 ) ;
}
}
}
V_219:
if ( V_186 & V_224 ) {
if ( V_186 & V_225 ) {
V_2 -> V_183 . V_226 ++ ;
if ( F_74 ( V_5 ) )
F_75 ( & V_2 -> V_115 , L_3 ) ;
}
}
if ( V_186 & V_227 ) {
if ( V_186 & V_228 ) {
V_2 -> V_183 . V_203 ++ ;
if ( F_76 ( V_5 ) )
F_75 ( & V_2 -> V_115 , L_4 ) ;
}
}
if ( V_186 & V_229 ) {
V_2 -> V_183 . V_230 ++ ;
if ( F_74 ( V_5 ) )
F_75 ( & V_2 -> V_115 , L_5 ) ;
}
if ( V_186 & V_231 ) {
V_2 -> V_183 . V_230 ++ ;
if ( F_74 ( V_5 ) )
F_75 ( & V_2 -> V_115 , L_6 ) ;
}
if ( V_186 & V_209 ) {
V_2 -> V_183 . V_205 ++ ;
if ( F_76 ( V_5 ) )
F_75 ( & V_2 -> V_115 , L_7 ) ;
}
if ( V_186 & V_232 ) {
V_2 -> V_183 . V_233 ++ ;
if ( F_76 ( V_5 ) )
F_75 ( & V_2 -> V_115 , L_8 ) ;
}
if ( ! V_5 -> V_49 -> V_234 && ( V_186 & V_235 ) ) {
V_2 -> V_183 . V_230 ++ ;
if ( F_74 ( V_5 ) )
F_75 ( & V_2 -> V_115 , L_9 ) ;
}
V_212 = V_224 | V_225 | V_235 | V_229 | V_231 ;
if ( V_5 -> V_49 -> V_234 )
V_212 &= ~ V_235 ;
if ( V_186 & V_212 ) {
T_1 V_236 = F_6 ( V_2 , V_237 ) ;
F_75 ( & V_2 -> V_115 , L_10 ,
V_186 , V_5 -> V_110 ) ;
F_75 ( & V_2 -> V_115 , L_11 ,
V_5 -> V_112 , ( T_1 ) V_2 -> V_238 , V_236 ) ;
F_61 ( V_2 ) ;
if ( V_236 ^ F_35 ( V_5 ) ) {
F_4 ( V_2 , F_35 ( V_5 ) , V_237 ) ;
}
F_77 ( V_2 ) ;
}
}
static T_4 F_78 ( int V_239 , void * V_240 )
{
struct V_1 * V_2 = V_240 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_38 * V_49 = V_5 -> V_49 ;
T_4 V_23 = V_241 ;
unsigned long V_186 ;
F_79 ( & V_5 -> V_242 ) ;
V_186 = F_6 ( V_2 , V_160 ) ;
V_186 &= F_6 ( V_2 , V_140 ) | V_223 ;
if ( V_186 & ( V_243 | V_244 | V_245 |
V_246 | V_247 | V_248 | V_249 |
V_49 -> V_61 | V_49 -> V_63 ) ) {
F_4 ( V_2 , V_186 , V_160 ) ;
V_23 = V_250 ;
} else
goto V_251;
if ( V_186 & ( V_243 |
V_244 |
V_245 |
V_246 |
V_247 |
V_248 |
V_249 ) ) {
F_64 ( V_2 , V_186 ) ;
}
if ( V_186 & V_49 -> V_61 ) {
F_61 ( V_2 ) ;
F_77 ( V_2 ) ;
}
if ( V_186 & V_49 -> V_63 )
F_73 ( V_2 , V_186 ) ;
V_251:
F_80 ( & V_5 -> V_242 ) ;
return V_23 ;
}
static void F_81 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_252 * V_253 = V_5 -> V_253 ;
int V_254 = 0 ;
if ( V_253 -> V_255 ) {
if ( V_253 -> V_11 != V_5 -> V_11 ) {
V_254 = 1 ;
V_5 -> V_11 = V_253 -> V_11 ;
if ( V_5 -> V_49 -> V_256 )
V_5 -> V_49 -> V_256 ( V_2 ) ;
}
if ( V_253 -> V_14 != V_5 -> V_14 ) {
V_254 = 1 ;
V_5 -> V_14 = V_253 -> V_14 ;
if ( V_5 -> V_49 -> V_165 )
V_5 -> V_49 -> V_165 ( V_2 ) ;
}
if ( ! V_5 -> V_255 ) {
F_4 ( V_2 ,
( F_6 ( V_2 , V_12 ) & ~ V_257 ) , V_12 ) ;
V_254 = 1 ;
V_5 -> V_255 = V_253 -> V_255 ;
if ( V_5 -> V_49 -> V_217 || V_5 -> V_218 )
F_72 ( V_2 ) ;
}
} else if ( V_5 -> V_255 ) {
V_254 = 1 ;
V_5 -> V_255 = 0 ;
V_5 -> V_14 = 0 ;
V_5 -> V_11 = - 1 ;
if ( V_5 -> V_49 -> V_217 || V_5 -> V_218 )
F_71 ( V_2 ) ;
}
if ( V_254 && F_82 ( V_5 ) )
F_83 ( V_253 ) ;
}
static int F_84 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
char V_258 [ V_259 + 3 ] ;
struct V_252 * V_253 = NULL ;
snprintf ( V_258 , sizeof( V_258 ) , V_260 ,
V_5 -> V_261 -> V_262 , V_5 -> V_258 ) ;
V_5 -> V_255 = 0 ;
V_5 -> V_14 = 0 ;
V_5 -> V_11 = - 1 ;
V_253 = F_85 ( V_2 , V_258 , F_81 ,
V_5 -> V_6 ) ;
if ( F_86 ( V_253 ) ) {
F_75 ( & V_2 -> V_115 , L_12 ) ;
return F_87 ( V_253 ) ;
}
F_88 ( & V_2 -> V_115 , L_13 ,
V_253 -> V_87 , V_253 -> V_263 -> V_264 ) ;
V_5 -> V_253 = V_253 ;
return 0 ;
}
static int F_89 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_23 ;
V_23 = F_84 ( V_2 ) ;
if ( V_23 )
return V_23 ;
F_90 ( V_5 -> V_253 , V_265 , V_266 ) ;
F_91 ( V_5 -> V_253 ) ;
return 0 ;
}
static int F_92 ( struct V_1 * V_2 ,
struct V_267 * V_268 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_269 ;
int V_23 ;
F_93 ( & V_5 -> V_242 , V_269 ) ;
V_23 = F_94 ( V_5 -> V_253 , V_268 ) ;
F_95 ( & V_5 -> V_242 , V_269 ) ;
return V_23 ;
}
static int F_96 ( struct V_1 * V_2 ,
struct V_267 * V_268 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_269 ;
int V_23 ;
F_93 ( & V_5 -> V_242 , V_269 ) ;
F_71 ( V_2 ) ;
V_23 = F_97 ( V_5 -> V_253 , V_268 ) ;
if ( V_23 )
goto V_270;
if ( V_268 -> V_11 == V_271 )
V_5 -> V_11 = 1 ;
else
V_5 -> V_11 = 0 ;
if ( V_5 -> V_49 -> V_256 )
V_5 -> V_49 -> V_256 ( V_2 ) ;
V_270:
F_13 ( 1 ) ;
F_72 ( V_2 ) ;
F_95 ( & V_5 -> V_242 , V_269 ) ;
return V_23 ;
}
static int F_98 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_269 ;
int V_23 ;
F_93 ( & V_5 -> V_242 , V_269 ) ;
V_23 = F_99 ( V_5 -> V_253 ) ;
F_95 ( & V_5 -> V_242 , V_269 ) ;
return V_23 ;
}
static T_1 F_100 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_272 ;
}
static void F_101 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_272 = V_3 ;
}
static int F_102 ( struct V_1 * V_240 , int V_273 )
{
switch ( V_273 ) {
case V_274 :
return V_275 ;
default:
return - V_276 ;
}
}
static void F_103 ( struct V_1 * V_2 ,
struct V_277 * V_183 , T_5 * V_73 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_18 = 0 ;
V_73 [ V_18 ++ ] = V_5 -> V_109 ;
V_73 [ V_18 ++ ] = V_5 -> V_110 ;
V_73 [ V_18 ++ ] = V_5 -> V_111 ;
V_73 [ V_18 ++ ] = V_5 -> V_112 ;
}
static void F_104 ( struct V_1 * V_2 , T_1 V_278 , T_6 * V_73 )
{
switch ( V_278 ) {
case V_274 :
memcpy ( V_73 , * V_279 ,
sizeof( V_279 ) ) ;
break;
}
}
static void F_105 ( struct V_1 * V_2 ,
struct V_280 * V_281 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_281 -> V_282 = V_283 ;
V_281 -> V_284 = V_285 ;
V_281 -> V_286 = V_5 -> V_100 ;
V_281 -> V_287 = V_5 -> V_102 ;
}
static int F_106 ( struct V_1 * V_2 ,
struct V_280 * V_281 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_23 ;
if ( V_281 -> V_287 > V_285 ||
V_281 -> V_286 > V_283 ||
V_281 -> V_287 < V_288 ||
V_281 -> V_286 < V_289 )
return - V_290 ;
if ( V_281 -> V_291 || V_281 -> V_292 )
return - V_290 ;
if ( F_107 ( V_2 ) ) {
F_108 ( V_2 ) ;
F_4 ( V_2 , 0x0000 , V_140 ) ;
F_4 ( V_2 , 0 , V_237 ) ;
F_4 ( V_2 , 0 , V_178 ) ;
F_109 ( V_2 -> V_239 ) ;
}
F_44 ( V_2 ) ;
F_57 ( V_5 ) ;
V_5 -> V_100 = V_281 -> V_286 ;
V_5 -> V_102 = V_281 -> V_287 ;
V_23 = F_53 ( V_2 ) ;
if ( V_23 < 0 ) {
F_75 ( & V_2 -> V_115 , L_14 , V_293 ) ;
return V_23 ;
}
V_23 = F_58 ( V_2 , false ) ;
if ( V_23 < 0 ) {
F_75 ( & V_2 -> V_115 , L_15 , V_293 ) ;
return V_23 ;
}
if ( F_107 ( V_2 ) ) {
F_4 ( V_2 , V_5 -> V_49 -> V_161 , V_140 ) ;
F_4 ( V_2 , V_177 , V_178 ) ;
F_77 ( V_2 ) ;
}
return 0 ;
}
static int F_110 ( struct V_1 * V_2 )
{
int V_23 = 0 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_111 ( & V_5 -> V_294 -> V_115 ) ;
V_23 = F_112 ( V_2 -> V_239 , F_78 ,
#if F_59 ( V_295 ) || \
F_59 ( V_296 ) || \
F_59 ( V_297 )
V_298 ,
#else
0 ,
#endif
V_2 -> V_264 , V_2 ) ;
if ( V_23 ) {
F_75 ( & V_2 -> V_115 , L_16 ) ;
return V_23 ;
}
V_23 = F_53 ( V_2 ) ;
if ( V_23 )
goto V_299;
V_23 = F_58 ( V_2 , true ) ;
if ( V_23 )
goto V_299;
V_23 = F_89 ( V_2 ) ;
if ( V_23 )
goto V_299;
return V_23 ;
V_299:
F_113 ( V_2 -> V_239 , V_2 ) ;
F_114 ( & V_5 -> V_294 -> V_115 ) ;
return V_23 ;
}
static void F_115 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_103 * V_104 ;
int V_18 ;
F_116 ( V_2 ) ;
if ( F_117 ( V_5 ) )
F_75 ( & V_2 -> V_115 , L_17
L_18 , V_2 -> V_264 , ( int ) F_6 ( V_2 , V_160 ) ) ;
V_2 -> V_183 . V_300 ++ ;
for ( V_18 = 0 ; V_18 < V_5 -> V_100 ; V_18 ++ ) {
V_104 = & V_5 -> V_113 [ V_18 ] ;
V_104 -> V_117 = 0 ;
V_104 -> V_87 = 0xBADF00D0 ;
if ( V_5 -> V_99 [ V_18 ] )
F_45 ( V_5 -> V_99 [ V_18 ] ) ;
V_5 -> V_99 [ V_18 ] = NULL ;
}
for ( V_18 = 0 ; V_18 < V_5 -> V_102 ; V_18 ++ ) {
if ( V_5 -> V_101 [ V_18 ] )
F_45 ( V_5 -> V_101 [ V_18 ] ) ;
V_5 -> V_101 [ V_18 ] = NULL ;
}
F_58 ( V_2 , true ) ;
}
static int F_118 ( struct V_69 * V_70 , struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_105 * V_106 ;
T_1 V_180 ;
unsigned long V_269 ;
F_93 ( & V_5 -> V_242 , V_269 ) ;
if ( ( V_5 -> V_110 - V_5 -> V_112 ) >= ( V_5 -> V_102 - 4 ) ) {
if ( ! F_61 ( V_2 ) ) {
if ( F_119 ( V_5 ) )
F_120 ( & V_2 -> V_115 , L_19 ) ;
F_116 ( V_2 ) ;
F_95 ( & V_5 -> V_242 , V_269 ) ;
return V_301 ;
}
}
F_95 ( & V_5 -> V_242 , V_269 ) ;
V_180 = V_5 -> V_110 % V_5 -> V_102 ;
V_5 -> V_101 [ V_180 ] = V_70 ;
V_106 = & V_5 -> V_123 [ V_180 ] ;
if ( ! V_5 -> V_49 -> V_142 )
F_65 ( F_66 ( F_52 ( V_106 -> V_87 , 4 ) ) ,
V_70 -> V_302 + 2 ) ;
V_106 -> V_87 = F_49 ( & V_2 -> V_115 , V_70 -> V_73 , V_70 -> V_302 ,
V_182 ) ;
if ( V_70 -> V_302 < V_303 )
V_106 -> V_120 = V_303 ;
else
V_106 -> V_120 = V_70 -> V_302 ;
if ( V_180 >= V_5 -> V_102 - 1 )
V_106 -> V_117 |= F_27 ( V_5 , V_181 | V_126 ) ;
else
V_106 -> V_117 |= F_27 ( V_5 , V_181 ) ;
V_5 -> V_110 ++ ;
if ( ! ( F_6 ( V_2 , V_237 ) & F_35 ( V_5 ) ) )
F_4 ( V_2 , F_35 ( V_5 ) , V_237 ) ;
return V_304 ;
}
static int F_121 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_116 ( V_2 ) ;
F_4 ( V_2 , 0x0000 , V_140 ) ;
F_4 ( V_2 , 0 , V_237 ) ;
F_4 ( V_2 , 0 , V_178 ) ;
if ( V_5 -> V_253 ) {
F_122 ( V_5 -> V_253 ) ;
F_123 ( V_5 -> V_253 ) ;
}
F_113 ( V_2 -> V_239 , V_2 ) ;
F_44 ( V_2 ) ;
F_57 ( V_5 ) ;
F_114 ( & V_5 -> V_294 -> V_115 ) ;
return 0 ;
}
static struct V_305 * F_124 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_111 ( & V_5 -> V_294 -> V_115 ) ;
V_2 -> V_183 . V_306 += F_6 ( V_2 , V_307 ) ;
F_4 ( V_2 , 0 , V_307 ) ;
V_2 -> V_183 . V_308 += F_6 ( V_2 , V_309 ) ;
F_4 ( V_2 , 0 , V_309 ) ;
V_2 -> V_183 . V_215 += F_6 ( V_2 , V_310 ) ;
F_4 ( V_2 , 0 , V_310 ) ;
if ( F_15 ( V_5 ) ) {
V_2 -> V_183 . V_215 += F_6 ( V_2 , V_311 ) ;
F_4 ( V_2 , 0 , V_311 ) ;
V_2 -> V_183 . V_215 += F_6 ( V_2 , V_312 ) ;
F_4 ( V_2 , 0 , V_312 ) ;
} else {
V_2 -> V_183 . V_215 += F_6 ( V_2 , V_313 ) ;
F_4 ( V_2 , 0 , V_313 ) ;
}
F_114 ( & V_5 -> V_294 -> V_115 ) ;
return & V_2 -> V_183 ;
}
static int F_125 ( struct V_1 * V_2 , struct V_314 * V_315 ,
int V_316 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_252 * V_253 = V_5 -> V_253 ;
if ( ! F_107 ( V_2 ) )
return - V_290 ;
if ( ! V_253 )
return - V_317 ;
return F_126 ( V_253 , V_315 , V_316 ) ;
}
static void * F_127 ( struct V_4 * V_5 ,
int V_180 )
{
return F_128 ( V_5 , V_318 ) + ( V_180 / 8 * 4 ) ;
}
static T_1 F_129 ( int V_180 )
{
return 0x0f << ( 28 - ( ( V_180 % 8 ) * 4 ) ) ;
}
static T_1 F_130 ( struct V_4 * V_5 , int V_180 )
{
return ( 0x08 >> ( V_5 -> V_319 << 1 ) ) << ( 28 - ( ( V_180 % 8 ) * 4 ) ) ;
}
static void F_131 ( struct V_1 * V_2 ,
int V_180 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_320 ;
void * V_83 ;
V_83 = F_127 ( V_5 , V_180 ) ;
V_320 = F_9 ( V_83 ) ;
F_12 ( V_320 | F_130 ( V_5 , V_180 ) , V_83 ) ;
}
static bool F_132 ( struct V_1 * V_2 ,
int V_180 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_321 , V_322 , V_320 ;
void * V_83 ;
V_83 = F_127 ( V_5 , V_180 ) ;
V_321 = F_129 ( V_180 ) ;
V_322 = F_130 ( V_5 , V_180 ) & ~ V_321 ;
V_320 = F_9 ( V_83 ) ;
F_12 ( V_320 & ~ V_321 , V_83 ) ;
return V_320 & V_322 ;
}
static int F_133 ( struct V_1 * V_2 )
{
int V_323 = V_324 * 100 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
while ( ( F_134 ( V_5 , V_325 ) & V_326 ) ) {
F_135 ( 10 ) ;
V_323 -- ;
if ( V_323 <= 0 ) {
F_75 ( & V_2 -> V_115 , L_20 , V_293 ) ;
return - V_68 ;
}
}
return 0 ;
}
static int F_136 ( struct V_1 * V_2 , void * V_327 ,
const T_6 * V_87 )
{
T_1 V_137 ;
V_137 = V_87 [ 0 ] << 24 | V_87 [ 1 ] << 16 | V_87 [ 2 ] << 8 | V_87 [ 3 ] ;
F_12 ( V_137 , V_327 ) ;
if ( F_133 ( V_2 ) < 0 )
return - V_328 ;
V_137 = V_87 [ 4 ] << 8 | V_87 [ 5 ] ;
F_12 ( V_137 , V_327 + 4 ) ;
if ( F_133 ( V_2 ) < 0 )
return - V_328 ;
return 0 ;
}
static void F_137 ( void * V_327 , T_6 * V_87 )
{
T_1 V_137 ;
V_137 = F_9 ( V_327 ) ;
V_87 [ 0 ] = ( V_137 >> 24 ) & 0xff ;
V_87 [ 1 ] = ( V_137 >> 16 ) & 0xff ;
V_87 [ 2 ] = ( V_137 >> 8 ) & 0xff ;
V_87 [ 3 ] = V_137 & 0xff ;
V_137 = F_9 ( V_327 + 4 ) ;
V_87 [ 4 ] = ( V_137 >> 8 ) & 0xff ;
V_87 [ 5 ] = V_137 & 0xff ;
}
static int F_138 ( struct V_1 * V_2 , const T_6 * V_87 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
void * V_83 = F_128 ( V_5 , V_329 ) ;
int V_18 ;
T_6 V_330 [ V_331 ] ;
for ( V_18 = 0 ; V_18 < V_332 ; V_18 ++ , V_83 += 8 ) {
F_137 ( V_83 , V_330 ) ;
if ( memcmp ( V_87 , V_330 , V_331 ) == 0 )
return V_18 ;
}
return - V_333 ;
}
static int F_139 ( struct V_1 * V_2 )
{
T_6 V_334 [ V_331 ] ;
int V_180 ;
memset ( V_334 , 0 , sizeof( V_334 ) ) ;
V_180 = F_138 ( V_2 , V_334 ) ;
return ( V_180 < 0 ) ? - V_132 : V_180 ;
}
static int F_140 ( struct V_1 * V_2 ,
int V_180 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
void * V_83 = F_128 ( V_5 , V_329 ) ;
int V_23 ;
T_6 V_334 [ V_331 ] ;
F_21 ( V_5 , F_134 ( V_5 , V_335 ) &
~ ( 1 << ( 31 - V_180 ) ) , V_335 ) ;
memset ( V_334 , 0 , sizeof( V_334 ) ) ;
V_23 = F_136 ( V_2 , V_83 + V_180 * 8 , V_334 ) ;
if ( V_23 < 0 )
return V_23 ;
return 0 ;
}
static int F_141 ( struct V_1 * V_2 , const T_6 * V_87 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
void * V_83 = F_128 ( V_5 , V_329 ) ;
int V_18 , V_23 ;
if ( ! V_5 -> V_49 -> V_336 )
return 0 ;
V_18 = F_138 ( V_2 , V_87 ) ;
if ( V_18 < 0 ) {
V_18 = F_139 ( V_2 ) ;
if ( V_18 < 0 )
return - V_132 ;
V_23 = F_136 ( V_2 , V_83 + V_18 * 8 , V_87 ) ;
if ( V_23 < 0 )
return V_23 ;
F_21 ( V_5 , F_134 ( V_5 , V_335 ) |
( 1 << ( 31 - V_18 ) ) , V_335 ) ;
}
F_131 ( V_2 , V_18 ) ;
return 0 ;
}
static int F_142 ( struct V_1 * V_2 , const T_6 * V_87 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_18 , V_23 ;
if ( ! V_5 -> V_49 -> V_336 )
return 0 ;
V_18 = F_138 ( V_2 , V_87 ) ;
if ( V_18 ) {
if ( F_132 ( V_2 , V_18 ) )
goto V_337;
V_23 = F_140 ( V_2 , V_18 ) ;
if ( V_23 < 0 )
return V_23 ;
}
V_337:
return 0 ;
}
static int F_143 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_18 , V_23 ;
if ( F_144 ( ! V_5 -> V_49 -> V_336 ) )
return 0 ;
for ( V_18 = 0 ; V_18 < V_332 ; V_18 ++ ) {
if ( F_132 ( V_2 , V_18 ) )
continue;
V_23 = F_140 ( V_2 , V_18 ) ;
if ( V_23 < 0 )
return V_23 ;
}
return 0 ;
}
static void F_145 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_6 V_87 [ V_331 ] ;
void * V_83 = F_128 ( V_5 , V_329 ) ;
int V_18 ;
if ( F_144 ( ! V_5 -> V_49 -> V_336 ) )
return;
for ( V_18 = 0 ; V_18 < V_332 ; V_18 ++ , V_83 += 8 ) {
F_137 ( V_83 , V_87 ) ;
if ( F_146 ( V_87 ) )
F_142 ( V_2 , V_87 ) ;
}
}
static void F_147 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_338 ;
int V_339 = 0 ;
unsigned long V_269 ;
F_93 ( & V_5 -> V_242 , V_269 ) ;
V_338 = ( F_6 ( V_2 , V_12 ) & ~ V_340 ) | V_341 ;
if ( ! ( V_2 -> V_269 & V_342 ) ) {
F_145 ( V_2 ) ;
V_339 = 1 ;
}
if ( V_2 -> V_269 & V_343 ) {
F_145 ( V_2 ) ;
V_338 &= ~ V_341 ;
V_339 = 1 ;
}
if ( V_2 -> V_269 & V_344 ) {
F_143 ( V_2 ) ;
V_338 = ( V_338 & ~ V_341 ) | V_340 ;
} else if ( V_5 -> V_49 -> V_336 ) {
struct V_345 * V_346 ;
F_148 (ha, ndev) {
if ( V_339 && F_146 ( V_346 -> V_87 ) )
continue;
if ( F_141 ( V_2 , V_346 -> V_87 ) < 0 ) {
if ( ! V_339 ) {
F_145 ( V_2 ) ;
V_338 &= ~ V_341 ;
V_339 = 1 ;
}
}
}
} else {
V_338 = ( V_338 & ~ V_340 ) | V_341 ;
}
F_4 ( V_2 , V_338 , V_12 ) ;
F_95 ( & V_5 -> V_242 , V_269 ) ;
}
static int F_149 ( struct V_4 * V_5 )
{
if ( ! V_5 -> V_319 )
return V_347 ;
else
return V_348 ;
}
static int F_150 ( struct V_1 * V_2 ,
T_7 V_349 , T_3 V_350 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_351 = F_149 ( V_5 ) ;
if ( F_144 ( ! V_5 -> V_49 -> V_336 ) )
return - V_352 ;
if ( ! V_350 )
return 0 ;
V_5 -> V_353 ++ ;
if ( V_5 -> V_353 > 1 ) {
F_21 ( V_5 , 0 , V_351 ) ;
return 0 ;
}
F_21 ( V_5 , V_354 | ( V_350 & V_355 ) ,
V_351 ) ;
return 0 ;
}
static int F_151 ( struct V_1 * V_2 ,
T_7 V_349 , T_3 V_350 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_351 = F_149 ( V_5 ) ;
if ( F_144 ( ! V_5 -> V_49 -> V_336 ) )
return - V_352 ;
if ( ! V_350 )
return 0 ;
V_5 -> V_353 -- ;
F_21 ( V_5 , 0 , V_351 ) ;
return 0 ;
}
static void F_152 ( struct V_4 * V_5 )
{
F_21 ( V_5 , 0 , V_356 ) ;
F_21 ( V_5 , 0 , V_357 ) ;
F_21 ( V_5 , 0 , V_358 ) ;
F_21 ( V_5 , 0xc , V_359 ) ;
F_21 ( V_5 , 0xc , V_360 ) ;
F_21 ( V_5 , 0 , V_361 ) ;
F_21 ( V_5 , 0 , V_362 ) ;
F_21 ( V_5 , 0 , V_363 ) ;
F_21 ( V_5 , 0 , V_364 ) ;
F_21 ( V_5 , V_365 | V_366 , V_367 ) ;
if ( F_15 ( V_5 ) ) {
F_21 ( V_5 , 0 , V_368 ) ;
F_21 ( V_5 , 0 , V_369 ) ;
} else {
F_21 ( V_5 , 0 , V_370 ) ;
F_21 ( V_5 , 0 , V_371 ) ;
}
F_21 ( V_5 , 0 , V_372 ) ;
F_21 ( V_5 , 0 , V_373 ) ;
F_21 ( V_5 , 0 , V_335 ) ;
F_21 ( V_5 , 0 , V_318 ) ;
F_21 ( V_5 , 0 , V_374 ) ;
F_21 ( V_5 , 0 , V_375 ) ;
F_21 ( V_5 , 0 , V_376 ) ;
}
static int F_153 ( struct V_1 * V_2 )
{
struct V_261 * V_377 = F_154 ( & V_2 -> V_115 ) ;
F_155 ( V_377 ) ;
F_156 ( & V_2 -> V_115 , NULL ) ;
F_157 ( V_377 ) ;
return 0 ;
}
static int F_158 ( struct V_1 * V_2 , int V_262 ,
struct V_378 * V_379 )
{
int V_23 , V_18 ;
struct V_92 * V_93 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_93 = F_159 ( & V_2 -> V_115 , sizeof( struct V_92 ) ,
V_131 ) ;
if ( ! V_93 ) {
V_23 = - V_132 ;
goto V_27;
}
V_93 -> V_87 = V_5 -> V_87 + V_5 -> V_83 [ V_380 ] ;
V_93 -> V_94 = V_379 -> V_381 ;
V_93 -> V_97 = V_382 ;
V_93 -> V_96 = V_383 ;
V_93 -> V_95 = V_384 ;
V_93 -> V_98 = V_385 ;
V_93 -> V_90 . V_386 = & V_387 ;
V_5 -> V_261 = F_160 ( & V_93 -> V_90 ) ;
if ( ! V_5 -> V_261 ) {
V_23 = - V_132 ;
goto V_27;
}
V_5 -> V_261 -> V_264 = L_21 ;
V_5 -> V_261 -> V_388 = & V_2 -> V_115 ;
snprintf ( V_5 -> V_261 -> V_262 , V_259 , L_22 ,
V_5 -> V_294 -> V_264 , V_262 ) ;
V_5 -> V_261 -> V_239 = F_159 ( & V_2 -> V_115 ,
sizeof( int ) * V_389 ,
V_131 ) ;
if ( ! V_5 -> V_261 -> V_239 ) {
V_23 = - V_132 ;
goto V_390;
}
for ( V_18 = 0 ; V_18 < V_389 ; V_18 ++ )
V_5 -> V_261 -> V_239 [ V_18 ] = V_391 ;
V_23 = F_161 ( V_5 -> V_261 ) ;
if ( V_23 )
goto V_390;
F_156 ( & V_2 -> V_115 , V_5 -> V_261 ) ;
return 0 ;
V_390:
F_157 ( V_5 -> V_261 ) ;
V_27:
return V_23 ;
}
static const T_3 * F_162 ( int V_392 )
{
const T_3 * V_83 = NULL ;
switch ( V_392 ) {
case V_393 :
V_83 = V_84 ;
break;
case V_394 :
V_83 = V_395 ;
break;
case V_396 :
V_83 = V_397 ;
break;
case V_398 :
V_83 = V_399 ;
break;
default:
F_24 ( L_23 , V_392 ) ;
break;
}
return V_83 ;
}
static int F_163 ( struct V_400 * V_294 )
{
int V_23 , V_401 = 0 ;
struct V_402 * V_403 ;
struct V_1 * V_2 = NULL ;
struct V_4 * V_5 = NULL ;
struct V_378 * V_379 = V_294 -> V_115 . V_404 ;
V_403 = F_164 ( V_294 , V_405 , 0 ) ;
if ( F_144 ( V_403 == NULL ) ) {
F_75 ( & V_294 -> V_115 , L_24 ) ;
V_23 = - V_290 ;
goto V_27;
}
V_2 = F_165 ( sizeof( struct V_4 ) ) ;
if ( ! V_2 ) {
V_23 = - V_132 ;
goto V_27;
}
V_2 -> V_406 = V_403 -> V_136 ;
V_401 = V_294 -> V_262 ;
if ( V_401 < 0 )
V_401 = 0 ;
V_2 -> V_407 = - 1 ;
V_23 = F_166 ( V_294 , 0 ) ;
if ( V_23 < 0 ) {
V_23 = - V_317 ;
goto V_408;
}
V_2 -> V_239 = V_23 ;
F_167 ( V_2 , & V_294 -> V_115 ) ;
F_168 ( V_2 ) ;
V_5 = F_2 ( V_2 ) ;
V_5 -> V_102 = V_409 ;
V_5 -> V_100 = V_410 ;
V_5 -> V_87 = F_169 ( & V_294 -> V_115 , V_403 ) ;
if ( F_86 ( V_5 -> V_87 ) ) {
V_23 = F_87 ( V_5 -> V_87 ) ;
goto V_408;
}
F_170 ( & V_5 -> V_242 ) ;
V_5 -> V_294 = V_294 ;
F_171 ( & V_294 -> V_115 ) ;
F_172 ( & V_294 -> V_115 ) ;
V_5 -> V_258 = V_379 -> V_411 ;
V_5 -> V_6 = V_379 -> V_6 ;
V_5 -> V_76 = V_379 -> V_76 ;
V_5 -> V_218 = V_379 -> V_218 ;
V_5 -> V_221 = V_379 -> V_221 ;
V_5 -> V_83 = F_162 ( V_379 -> V_392 ) ;
#if F_59 ( V_412 )
V_5 -> V_49 = F_19 ( V_5 ) ;
#else
V_5 -> V_49 = & V_40 ;
#endif
F_23 ( V_5 -> V_49 ) ;
V_2 -> V_413 = & V_414 ;
F_173 ( V_2 , & V_415 ) ;
V_2 -> V_416 = V_417 ;
V_5 -> V_272 = V_418 ;
F_34 ( V_2 , V_379 -> V_419 ) ;
if ( ! F_174 ( V_2 -> V_79 ) ) {
F_120 ( & V_294 -> V_115 ,
L_25 ) ;
F_175 ( V_2 ) ;
}
if ( V_5 -> V_49 -> V_336 ) {
struct V_402 * V_420 ;
V_420 = F_164 ( V_294 , V_405 , 1 ) ;
V_5 -> V_421 = F_169 ( & V_294 -> V_115 , V_420 ) ;
if ( F_86 ( V_5 -> V_421 ) ) {
V_23 = F_87 ( V_5 -> V_421 ) ;
goto V_408;
}
V_5 -> V_319 = V_401 % 2 ;
V_2 -> V_422 = V_423 ;
}
if ( ! V_401 || V_379 -> V_424 ) {
if ( V_5 -> V_49 -> V_425 )
V_5 -> V_49 -> V_425 ( V_2 ) ;
if ( V_5 -> V_49 -> V_336 ) {
F_152 ( V_5 ) ;
}
}
V_23 = F_176 ( V_2 ) ;
if ( V_23 )
goto V_408;
V_23 = F_158 ( V_2 , V_294 -> V_262 , V_379 ) ;
if ( V_23 )
goto V_426;
F_177 ( L_26 ,
( T_1 ) V_2 -> V_406 , V_2 -> V_79 , V_2 -> V_239 ) ;
F_178 ( V_294 , V_2 ) ;
return V_23 ;
V_426:
F_179 ( V_2 ) ;
V_408:
if ( V_2 )
F_180 ( V_2 ) ;
V_27:
return V_23 ;
}
static int F_181 ( struct V_400 * V_294 )
{
struct V_1 * V_2 = F_182 ( V_294 ) ;
F_153 ( V_2 ) ;
F_179 ( V_2 ) ;
F_183 ( & V_294 -> V_115 ) ;
F_180 ( V_2 ) ;
F_178 ( V_294 , NULL ) ;
return 0 ;
}
static int F_184 ( struct V_427 * V_115 )
{
return 0 ;
}
