static void F_1 ( void )
{
V_1 . V_2 = V_3 ;
}
static void F_2 ( unsigned V_4 )
{
V_1 . V_5 += ( V_3 - V_2 ) ;
V_1 . V_6 += V_4 + 2 ;
F_3 () ;
}
static void F_4 ( unsigned V_4 )
{
V_1 . V_7 += ( V_3 - V_2 ) ;
V_1 . V_8 += V_4 + 2 ;
F_3 () ;
}
static void F_3 ( void )
{
unsigned long V_9 = V_3 - V_1 . V_10 ;
if ( V_9 >= V_11 ) {
int V_12 = ( V_1 . V_10 == 0 ) ;
V_1 . V_10 = V_3 ;
if ( ! V_12 )
F_5 (KERN_INFO IPWIRELESS_PCCARD_NAME
L_1 ,
jiffies_to_usecs(since),
timing_stats.read_bytes,
jiffies_to_usecs(timing_stats.read_time),
timing_stats.write_bytes,
jiffies_to_usecs(timing_stats.write_time)) ;
V_1 . V_5 = 0 ;
V_1 . V_7 = 0 ;
V_1 . V_6 = 0 ;
V_1 . V_8 = 0 ;
}
}
static void F_1 ( void ) { }
static void F_2 ( unsigned V_4 ) { }
static void F_4 ( unsigned V_4 ) { }
static char * F_6 ( const unsigned char * V_13 , unsigned V_4 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 ;
if ( V_4 == 0 )
return L_2 ;
if ( V_15 -> V_16 & V_17 ) {
switch ( V_15 -> V_18 ) {
case V_19 : return L_3 ;
case V_20 : return L_4 ;
case V_21 : return L_5 ;
default: return L_6 ;
}
} else
return L_2 ;
}
static void F_7 ( const char * type , const unsigned char * V_22 ,
unsigned V_4 )
{
char V_23 [ 56 ] ;
sprintf ( V_23 , V_24 L_7 ,
type , F_6 ( V_22 , V_4 ) ) ;
F_8 ( V_23 , 0 , ( void * ) V_22 ,
V_4 < V_25 ? V_4 : V_25 ) ;
}
static void F_9 ( unsigned char * V_22 )
{
#ifdef F_10
unsigned char V_26 = * V_22 , V_27 = 0 ;
V_27 |= V_26 & 0xc0 >> 6 ;
V_27 |= V_26 & 0x38 >> 1 ;
V_27 |= V_26 & 0x07 << 5 ;
* V_22 = V_27 & 0xff ;
#endif
}
static void F_11 ( unsigned char * V_22 )
{
#ifdef F_10
unsigned char V_26 = * V_22 , V_27 = 0 ;
V_27 |= V_26 & 0xe0 >> 5 ;
V_27 |= V_26 & 0x1c << 1 ;
V_27 |= V_26 & 0x03 << 6 ;
* V_22 = V_27 & 0xff ;
#endif
}
static void F_12 ( struct V_28 * V_29 , unsigned char * V_22 ,
unsigned V_4 )
{
unsigned V_30 ;
unsigned long V_31 ;
F_1 () ;
F_13 ( V_4 > V_29 -> V_32 ) ;
if ( V_33 )
F_7 ( L_8 , V_22 , V_4 ) ;
F_14 ( & V_29 -> V_34 , V_31 ) ;
V_29 -> V_35 = 0 ;
F_9 ( V_22 ) ;
if ( V_29 -> V_36 == V_37 ) {
F_15 ( ( unsigned short ) V_4 , V_29 -> V_38 + V_39 ) ;
for ( V_30 = 0 ; V_30 < V_4 ; V_30 += 2 ) {
unsigned short V_40 = V_22 [ V_30 ] ;
T_1 V_41 ;
if ( V_30 + 1 < V_4 )
V_40 |= V_22 [ V_30 + 1 ] << 8 ;
V_41 = F_16 ( V_40 ) ;
F_15 ( V_41 , V_29 -> V_38 + V_39 ) ;
}
F_15 ( V_42 , V_29 -> V_38 + V_43 ) ;
} else if ( V_29 -> V_36 == V_44 ) {
F_15 ( ( unsigned short ) V_4 , V_29 -> V_38 ) ;
for ( V_30 = 0 ; V_30 < V_4 ; V_30 += 2 ) {
unsigned short V_40 = V_22 [ V_30 ] ;
T_1 V_41 ;
if ( V_30 + 1 < V_4 )
V_40 |= V_22 [ V_30 + 1 ] << 8 ;
V_41 = F_16 ( V_40 ) ;
F_15 ( V_41 , V_29 -> V_38 ) ;
}
while ( ( V_30 & 3 ) != 2 ) {
F_15 ( ( unsigned short ) 0xDEAD , V_29 -> V_38 ) ;
V_30 += 2 ;
}
F_17 ( V_45 , & V_29 -> V_46 -> V_47 ) ;
}
F_18 ( & V_29 -> V_34 , V_31 ) ;
F_4 ( V_4 ) ;
}
static void F_19 ( struct V_28 * V_29 , struct V_48 * V_49 )
{
unsigned short V_50 ;
unsigned short V_51 = V_49 -> V_4 - V_49 -> V_52 ;
unsigned short V_53 ;
union V_54 V_55 ;
V_53 =
( V_49 -> V_56 == 0 )
? V_57
: V_58 ;
V_50 = V_29 -> V_32 - V_53 ;
if ( V_51 < V_50 )
V_50 = V_51 ;
V_55 . V_59 . V_18 = V_49 -> V_18 ;
V_55 . V_59 . V_60 = V_49 -> V_61 ;
V_55 . V_59 . V_16 = 0 ;
if ( V_49 -> V_56 == 0 ) {
V_55 . V_59 . V_16 |= V_17 ;
V_55 . V_59 . V_62 = ( unsigned char ) V_49 -> V_4 ;
V_55 . V_59 . V_63 =
( unsigned char ) ( V_49 -> V_4 >> 8 ) ;
}
memcpy ( V_55 . V_64 + V_53 ,
( ( unsigned char * ) V_49 ) + sizeof( struct V_48 ) +
V_49 -> V_52 , V_50 ) ;
V_49 -> V_52 += V_50 ;
V_49 -> V_56 ++ ;
if ( V_49 -> V_52 == V_49 -> V_4 )
V_55 . V_59 . V_16 |= V_65 ;
F_12 ( V_29 , V_55 . V_64 , V_53 + V_50 ) ;
if ( V_49 -> V_52 < V_49 -> V_4 ) {
unsigned long V_31 ;
F_14 ( & V_29 -> V_34 , V_31 ) ;
F_20 ( & V_49 -> V_66 , & V_29 -> V_67 [ 0 ] ) ;
V_29 -> V_68 ++ ;
F_18 ( & V_29 -> V_34 , V_31 ) ;
} else {
if ( V_49 -> V_69 )
V_49 -> V_69 ( V_49 -> V_70 ,
V_49 -> V_4 ) ;
F_21 ( V_49 ) ;
}
}
static void F_22 ( struct V_28 * V_29 )
{
unsigned long V_31 ;
F_14 ( & V_29 -> V_34 , V_31 ) ;
if ( V_29 -> V_36 == V_37 ) {
F_15 ( V_71 , V_29 -> V_38 + V_43 ) ;
F_15 ( V_72 , V_29 -> V_38 + V_43 ) ;
F_15 ( V_73 | V_74 , V_29 -> V_38 + V_75 ) ;
} else {
unsigned short V_76 = F_23 ( & V_29 -> V_77 -> V_78 ) ;
V_76 |= 1 ;
F_17 ( V_76 , & V_29 -> V_77 -> V_78 ) ;
}
F_18 ( & V_29 -> V_34 , V_31 ) ;
}
static struct V_79 * F_24 ( struct V_28 * V_29 ,
struct V_79 * V_49 ,
int V_80 )
{
if ( ! V_49 ) {
unsigned long V_31 ;
F_14 ( & V_29 -> V_34 , V_31 ) ;
if ( ! F_25 ( & V_29 -> V_81 ) ) {
V_49 = F_26 ( & V_29 -> V_81 ,
struct V_79 , V_66 ) ;
V_29 -> V_82 -- ;
F_18 ( & V_29 -> V_34 , V_31 ) ;
F_27 ( & V_49 -> V_66 ) ;
} else {
const int V_83 =
F_28 ( V_29 -> V_84 ) + 2 ;
int V_85 ;
F_18 ( & V_29 -> V_34 , V_31 ) ;
V_85 =
( V_80 > V_83
? V_80
: V_83 ) ;
V_49 = F_29 ( sizeof( struct V_79 )
+ V_85 , V_86 ) ;
if ( ! V_49 )
return NULL ;
V_49 -> V_87 = V_85 ;
}
V_49 -> V_4 = 0 ;
}
if ( V_49 -> V_4 + V_80 > V_49 -> V_87 ) {
struct V_79 * V_88 = V_49 ;
V_49 = F_29 ( sizeof( struct V_79 ) +
V_88 -> V_4 + V_80 ,
V_86 ) ;
if ( ! V_49 ) {
F_21 ( V_88 ) ;
return NULL ;
}
memcpy ( V_49 , V_88 ,
sizeof( struct V_79 )
+ V_88 -> V_4 ) ;
V_49 -> V_87 = V_88 -> V_4 + V_80 ;
F_21 ( V_88 ) ;
}
return V_49 ;
}
static void F_30 ( struct V_28 * V_29 , struct V_79 * V_49 )
{
if ( V_29 -> V_82 > 6 )
F_21 ( V_49 ) ;
else {
V_29 -> V_82 ++ ;
F_20 ( & V_49 -> V_66 , & V_29 -> V_81 ) ;
}
}
static void F_31 ( struct V_28 * V_29 ,
unsigned int V_18 ,
unsigned int V_60 ,
const unsigned char * V_22 , int V_4 ,
int V_89 )
{
unsigned int V_90 = V_60 - 1 ;
struct V_79 * V_49 = NULL ;
unsigned long V_31 ;
if ( V_90 >= V_91 ) {
F_5 (KERN_INFO IPWIRELESS_PCCARD_NAME
L_9 , address) ;
return;
}
if ( V_18 == V_19 ) {
struct V_79 * * V_92 =
& V_29 -> V_93 [ V_90 ] ;
( * V_92 ) = F_24 ( V_29 , * V_92 , V_4 ) ;
if ( ! ( * V_92 ) ) {
F_5 (KERN_ERR IPWIRELESS_PCCARD_NAME
L_10 ) ;
return;
}
( * V_92 ) -> V_18 = V_18 ;
( * V_92 ) -> V_90 = V_90 ;
memcpy ( ( unsigned char * ) ( * V_92 ) +
sizeof( struct V_79 )
+ ( * V_92 ) -> V_4 , V_22 , V_4 ) ;
( * V_92 ) -> V_4 += V_4 ;
if ( V_89 ) {
V_49 = * V_92 ;
* V_92 = NULL ;
F_14 ( & V_29 -> V_34 , V_31 ) ;
V_29 -> V_94 += V_49 -> V_4 ;
F_18 ( & V_29 -> V_34 , V_31 ) ;
}
} else {
V_49 = F_24 ( V_29 , NULL , V_4 ) ;
if ( ! V_49 ) {
F_5 (KERN_ERR IPWIRELESS_PCCARD_NAME
L_11 ) ;
return;
}
V_49 -> V_18 = V_18 ;
V_49 -> V_90 = V_90 ;
memcpy ( ( unsigned char * ) V_49 + sizeof( struct V_79 ) ,
V_22 , V_4 ) ;
V_49 -> V_4 = V_4 ;
}
if ( V_49 ) {
F_14 ( & V_29 -> V_34 , V_31 ) ;
F_32 ( & V_49 -> V_66 , & V_29 -> V_95 ) ;
V_29 -> V_96 =
( V_29 -> V_94 >= V_97 ) ;
F_18 ( & V_29 -> V_34 , V_31 ) ;
F_33 ( & V_29 -> V_98 ) ;
}
}
static void F_34 ( struct V_99 * V_98 )
{
struct V_28 * V_29 =
F_35 ( V_98 , struct V_28 , V_98 ) ;
unsigned long V_31 ;
F_14 ( & V_29 -> V_34 , V_31 ) ;
while ( ! F_25 ( & V_29 -> V_95 ) ) {
struct V_79 * V_49 =
F_26 ( & V_29 -> V_95 ,
struct V_79 , V_66 ) ;
if ( V_29 -> V_100 )
break;
F_27 ( & V_49 -> V_66 ) ;
if ( V_49 -> V_18 == V_19 ) {
if ( V_29 -> V_84 != NULL ) {
F_18 ( & V_29 -> V_34 , V_31 ) ;
F_36 (
V_29 -> V_84 ,
V_49 -> V_90 ,
( unsigned char * ) V_49
+ sizeof( struct V_79 ) ,
V_49 -> V_4 ) ;
F_14 ( & V_29 -> V_34 , V_31 ) ;
}
V_29 -> V_94 -= V_49 -> V_4 ;
} else {
F_37 ( V_29 , V_49 -> V_90 ,
( unsigned char * ) V_49
+ sizeof( struct V_79 ) ,
V_49 -> V_4 ) ;
}
F_30 ( V_29 , V_49 ) ;
V_29 -> V_96 =
V_29 -> V_94 >= V_97 ;
if ( V_29 -> V_100 )
break;
}
F_18 ( & V_29 -> V_34 , V_31 ) ;
}
static void F_37 ( struct V_28 * V_29 ,
unsigned int V_90 ,
const unsigned char * V_22 , int V_101 )
{
const struct V_102 * V_103 =
( const struct V_102 * ) V_22 ;
unsigned int V_104 ;
if ( V_101 != sizeof( struct V_102 ) ) {
F_5 (KERN_INFO IPWIRELESS_PCCARD_NAME
L_12 ,
len) ;
return;
}
switch ( V_103 -> V_105 ) {
case V_106 :
V_104 = V_107 ;
break;
case V_108 :
V_104 = V_109 ;
break;
case V_110 :
V_104 = V_111 ;
break;
case V_112 :
V_104 = V_113 ;
break;
default:
V_104 = 0 ;
}
if ( V_104 != 0 ) {
if ( V_103 -> V_114 )
V_29 -> V_115 [ V_90 ] |= V_104 ;
else
V_29 -> V_115 [ V_90 ] &= ~ V_104 ;
if ( V_29 -> V_84 )
F_38 (
V_29 -> V_84 ,
V_90 ,
V_29 -> V_115 [ V_90 ] ,
V_104 ) ;
}
}
static void F_39 ( struct V_28 * V_29 ,
const union V_54 * V_49 ,
unsigned short V_101 )
{
unsigned int V_18 = V_49 -> V_15 . V_18 ;
unsigned int V_60 = V_49 -> V_15 . V_60 ;
unsigned int V_116 ;
const unsigned char * V_22 ;
unsigned int V_117 ;
int V_89 = V_49 -> V_15 . V_16 & V_65 ;
if ( V_49 -> V_15 . V_16 & V_17 )
V_116 = V_57 ;
else
V_116 = V_58 ;
V_22 = V_49 -> V_64 + V_116 ;
V_117 = V_101 - V_116 ;
switch ( V_18 ) {
case V_19 :
case V_20 :
F_31 ( V_29 , V_18 , V_60 , V_22 , V_117 ,
V_89 ) ;
break;
case V_21 :
F_40 ( V_29 , V_60 , V_22 , V_117 ,
V_89 ) ;
break;
}
}
static void F_41 ( struct V_28 * V_29 )
{
if ( V_29 -> V_36 == V_37 )
F_15 ( V_118 , V_29 -> V_38 + V_43 ) ;
else
F_17 ( V_119 ,
& V_29 -> V_46 -> V_120 ) ;
}
static void F_42 ( struct V_28 * V_29 )
{
unsigned V_101 ;
unsigned V_30 ;
unsigned char V_55 [ V_121 ] ;
F_1 () ;
if ( V_29 -> V_36 == V_37 ) {
V_101 = F_43 ( V_29 -> V_38 + V_122 ) ;
if ( V_101 > V_29 -> V_32 ) {
F_5 (KERN_INFO IPWIRELESS_PCCARD_NAME
L_13 , len) ;
F_15 ( V_118 | V_71 , V_29 -> V_38 + V_43 ) ;
return;
}
for ( V_30 = 0 ; V_30 < V_101 ; V_30 += 2 ) {
T_1 V_41 = F_43 ( V_29 -> V_38 + V_122 ) ;
unsigned short V_22 = F_44 ( V_41 ) ;
V_55 [ V_30 ] = ( unsigned char ) V_22 ;
V_55 [ V_30 + 1 ] = ( unsigned char ) ( V_22 >> 8 ) ;
}
} else {
V_101 = F_43 ( V_29 -> V_38 ) ;
if ( V_101 > V_29 -> V_32 ) {
F_5 (KERN_INFO IPWIRELESS_PCCARD_NAME
L_13 , len) ;
F_17 ( V_119 ,
& V_29 -> V_46 -> V_120 ) ;
return;
}
for ( V_30 = 0 ; V_30 < V_101 ; V_30 += 2 ) {
T_1 V_41 = F_43 ( V_29 -> V_38 ) ;
unsigned short V_22 = F_44 ( V_41 ) ;
V_55 [ V_30 ] = ( unsigned char ) V_22 ;
V_55 [ V_30 + 1 ] = ( unsigned char ) ( V_22 >> 8 ) ;
}
while ( ( V_30 & 3 ) != 2 ) {
F_43 ( V_29 -> V_38 ) ;
V_30 += 2 ;
}
}
F_41 ( V_29 ) ;
F_11 ( V_55 ) ;
if ( V_33 )
F_7 ( L_14 , V_55 , V_101 ) ;
F_39 ( V_29 , (union V_54 * ) V_55 , V_101 ) ;
F_2 ( V_101 ) ;
}
static int F_45 ( struct V_28 * V_29 )
{
return ( V_29 -> V_123 || V_29 -> V_124
? V_125 + 1 : V_126 ) ;
}
static int F_46 ( struct V_28 * V_29 )
{
int V_127 = 0 ;
unsigned long V_31 ;
F_14 ( & V_29 -> V_34 , V_31 ) ;
while ( V_29 -> V_128 && ! V_29 -> V_96 ) {
V_127 = 1 ;
V_29 -> V_128 -- ;
F_18 ( & V_29 -> V_34 , V_31 ) ;
F_42 ( V_29 ) ;
F_14 ( & V_29 -> V_34 , V_31 ) ;
}
F_18 ( & V_29 -> V_34 , V_31 ) ;
return V_127 ;
}
static int F_47 ( struct V_28 * V_29 , int V_129 )
{
int V_130 = 0 ;
unsigned long V_31 ;
F_14 ( & V_29 -> V_34 , V_31 ) ;
if ( V_29 -> V_68 && V_29 -> V_35 ) {
int V_131 ;
struct V_48 * V_49 = NULL ;
for ( V_131 = 0 ; V_131 < V_129 ; V_131 ++ ) {
if ( ! F_25 ( & V_29 -> V_67 [ V_131 ] ) ) {
V_49 = F_26 (
& V_29 -> V_67 [ V_131 ] ,
struct V_48 ,
V_66 ) ;
V_29 -> V_68 -- ;
F_27 ( & V_49 -> V_66 ) ;
break;
}
}
if ( ! V_49 ) {
V_29 -> V_68 = 0 ;
F_18 ( & V_29 -> V_34 , V_31 ) ;
return 0 ;
}
F_18 ( & V_29 -> V_34 , V_31 ) ;
F_19 ( V_29 , V_49 ) ;
F_14 ( & V_29 -> V_34 , V_31 ) ;
for ( V_131 = 0 ; V_131 < V_129 ; V_131 ++ )
if ( ! F_25 ( & V_29 -> V_67 [ V_131 ] ) ) {
V_130 = 1 ;
break;
}
if ( ! V_130 )
V_29 -> V_68 = 0 ;
}
F_18 ( & V_29 -> V_34 , V_31 ) ;
return V_130 ;
}
static void F_48 ( unsigned long V_132 )
{
struct V_28 * V_29 = (struct V_28 * ) V_132 ;
unsigned long V_31 ;
F_14 ( & V_29 -> V_34 , V_31 ) ;
if ( V_29 -> V_100 ) {
F_18 ( & V_29 -> V_34 , V_31 ) ;
return;
}
if ( V_29 -> V_123 == 1 ) {
V_29 -> V_123 = 2 ;
F_18 ( & V_29 -> V_34 , V_31 ) ;
F_22 ( V_29 ) ;
F_49 ( V_29 ) ;
F_47 ( V_29 , V_125 + 1 ) ;
F_46 ( V_29 ) ;
} else {
int V_129 = F_45 ( V_29 ) ;
int V_133 ;
F_18 ( & V_29 -> V_34 , V_31 ) ;
do {
V_133 = F_47 ( V_29 , V_129 ) ;
V_133 |= F_46 ( V_29 ) ;
} while ( V_133 );
}
}
static int F_50 ( struct V_28 * V_29 )
{
if ( V_29 -> V_36 == V_37 )
return F_43 ( V_29 -> V_38 + V_134 ) != 0xFFFF ;
else
return F_51 ( & V_29 -> V_46 -> V_135 ) ==
V_136 ;
}
static T_2 F_52 ( int V_137 ,
struct V_28 * V_29 )
{
unsigned short V_138 ;
V_138 = F_43 ( V_29 -> V_38 + V_134 ) ;
if ( V_138 == 0xFFFF )
return V_139 ;
else if ( V_138 != 0 ) {
unsigned short V_140 = 0 ;
unsigned long V_31 ;
if ( V_138 & V_141 ) {
V_140 |= V_141 ;
F_14 ( & V_29 -> V_34 , V_31 ) ;
V_29 -> V_35 = 1 ;
F_18 ( & V_29 -> V_34 , V_31 ) ;
}
if ( V_138 & V_142 ) {
V_140 |= V_142 ;
F_14 ( & V_29 -> V_34 , V_31 ) ;
V_29 -> V_128 ++ ;
F_18 ( & V_29 -> V_34 , V_31 ) ;
}
if ( V_140 != 0 ) {
F_15 ( V_140 , V_29 -> V_38 + V_134 ) ;
F_53 ( & V_29 -> V_143 ) ;
}
return V_144 ;
}
return V_139 ;
}
static void F_54 ( struct V_28 * V_29 )
{
unsigned short V_76 = F_23 ( & V_29 -> V_77 -> V_78 ) ;
V_76 &= 0xfffd ;
F_17 ( V_76 , & V_29 -> V_77 -> V_78 ) ;
}
static T_2 F_55 ( int V_137 ,
struct V_28 * V_29 )
{
int V_145 = 0 ;
int V_146 = 0 ;
int V_147 = 0 ;
int V_148 ;
unsigned long V_31 ;
do {
unsigned short V_149 = F_23 ( V_29 -> V_150 ) ;
unsigned short V_151 ;
unsigned short V_152 =
F_23 ( & V_29 -> V_46 -> V_153 ) ;
V_148 = 0 ;
if ( ! ( V_149 & V_154 ) && ! ( V_152 & V_155 ) ) {
if ( V_29 -> V_150 == & V_29 -> V_46 -> V_156 ) {
V_149 = F_23 ( & V_29 -> V_46 -> V_157 ) ;
if ( V_149 & V_154 ) {
F_5 (KERN_INFO IPWIRELESS_PCCARD_NAME
L_15 ) ;
V_29 -> V_150 =
& V_29 -> V_46 -> V_157 ;
} else {
return V_139 ;
}
} else
return V_139 ;
}
if ( ! F_50 ( V_29 ) ) {
F_54 ( V_29 ) ;
return V_144 ;
}
V_151 = V_149 & ( unsigned short ) 0xff00 ;
if ( V_149 & V_154 ) {
F_17 ( V_151 , V_29 -> V_150 ) ;
if ( V_29 -> V_158 ) {
if ( V_151 != V_29 -> V_159 ) {
V_29 -> V_159 = V_151 ;
F_14 ( & V_29 -> V_34 , V_31 ) ;
V_29 -> V_128 ++ ;
F_18 ( & V_29 -> V_34 , V_31 ) ;
V_146 = 1 ;
} else
V_147 = 1 ;
} else {
if ( V_151 != 0 ) {
V_29 -> V_158 = 1 ;
F_5 (KERN_DEBUG IPWIRELESS_PCCARD_NAME
L_16 ) ;
F_14 ( & V_29 -> V_34 , V_31 ) ;
V_29 -> V_128 ++ ;
F_18 ( & V_29 -> V_34 , V_31 ) ;
}
V_146 = 1 ;
}
}
if ( V_152 & V_155 ) {
F_17 ( 0 , & V_29 -> V_46 -> V_153 ) ;
F_14 ( & V_29 -> V_34 , V_31 ) ;
V_29 -> V_35 = 1 ;
F_18 ( & V_29 -> V_34 , V_31 ) ;
V_145 = 1 ;
}
if ( V_145 )
F_17 ( V_119 ,
& V_29 -> V_46 -> V_120 ) ;
F_54 ( V_29 ) ;
if ( V_145 || V_146 )
F_53 ( & V_29 -> V_143 ) ;
else if ( ! V_147 ) {
if ( V_29 -> V_150 == & V_29 -> V_46 -> V_156 ) {
if ( V_29 -> V_158 )
F_5 (KERN_WARNING IPWIRELESS_PCCARD_NAME
L_17 ) ;
else {
F_5 (KERN_WARNING IPWIRELESS_PCCARD_NAME
L_18 ) ;
V_29 -> V_150 =
& V_29 -> V_46 -> V_157 ;
V_148 = 1 ;
}
} else
F_5 (KERN_WARNING IPWIRELESS_PCCARD_NAME
L_19 ) ;
}
} while ( V_148 == 1 );
return V_144 ;
}
T_2 F_56 ( int V_137 , void * V_160 )
{
struct V_161 * V_162 = V_160 ;
if ( V_162 -> V_163 -> V_36 == V_37 )
return F_52 ( V_137 , V_162 -> V_163 ) ;
else
return F_55 ( V_137 , V_162 -> V_163 ) ;
}
static void F_57 ( struct V_28 * V_29 )
{
int V_129 ;
unsigned long V_31 ;
F_14 ( & V_29 -> V_34 , V_31 ) ;
V_129 = F_45 ( V_29 ) ;
F_18 ( & V_29 -> V_34 , V_31 ) ;
while ( F_47 ( V_29 , V_129 ) ) ;
}
static void F_58 ( struct V_28 * V_29 , int V_131 ,
struct V_48 * V_49 )
{
unsigned long V_31 ;
F_14 ( & V_29 -> V_34 , V_31 ) ;
F_32 ( & V_49 -> V_66 , & V_29 -> V_67 [ V_131 ] ) ;
V_29 -> V_68 ++ ;
F_18 ( & V_29 -> V_34 , V_31 ) ;
F_57 ( V_29 ) ;
}
static void * F_59 ( int V_164 ,
unsigned char V_61 ,
unsigned char V_18 )
{
struct V_48 * V_49 = F_60 (
sizeof( struct V_48 ) + V_164 ,
V_86 ) ;
if ( ! V_49 )
return NULL ;
F_61 ( & V_49 -> V_66 ) ;
V_49 -> V_61 = V_61 ;
V_49 -> V_18 = V_18 ;
V_49 -> V_4 = V_164 ;
return V_49 ;
}
static void * F_62 ( int V_53 ,
unsigned char V_61 ,
unsigned char V_18 ,
unsigned char V_105 )
{
struct V_165 * V_49 = F_60 ( V_53 , V_86 ) ;
if ( ! V_49 )
return NULL ;
F_61 ( & V_49 -> V_166 . V_66 ) ;
V_49 -> V_166 . V_61 = V_61 ;
V_49 -> V_166 . V_18 = V_18 ;
V_49 -> V_166 . V_4 = V_53 - sizeof( struct V_48 ) ;
V_49 -> V_103 . V_105 = V_105 ;
return V_49 ;
}
int F_63 ( struct V_28 * V_29 , unsigned int V_90 ,
const unsigned char * V_22 , unsigned int V_4 ,
void (* F_64) ( void * V_167 , unsigned int V_4 ) ,
void * V_70 )
{
struct V_48 * V_49 ;
V_49 = F_59 ( V_4 , ( V_90 + 1 ) ,
V_19 ) ;
if ( ! V_49 )
return - V_168 ;
V_49 -> V_69 = F_64 ;
V_49 -> V_70 = V_70 ;
memcpy ( ( unsigned char * ) V_49 + sizeof( struct V_48 ) , V_22 ,
V_4 ) ;
F_58 ( V_29 , V_169 , V_49 ) ;
return 0 ;
}
static int F_65 ( struct V_28 * V_29 , int V_170 ,
unsigned int V_90 , int line , int V_171 )
{
struct V_165 * V_49 ;
int V_172 = V_20 ;
if ( V_170 == V_125 )
V_172 = V_21 ;
V_49 = F_62 ( sizeof( struct V_165 ) ,
( V_90 + 1 ) , V_172 , line ) ;
if ( ! V_49 )
return - V_168 ;
V_49 -> V_166 . V_4 = sizeof( struct V_102 ) ;
V_49 -> V_103 . V_114 = ( V_171 == 0 ? 0 : 1 ) ;
F_58 ( V_29 , V_170 , & V_49 -> V_166 ) ;
return 0 ;
}
static int F_66 ( struct V_28 * V_29 , int V_131 ,
unsigned int V_90 , int V_171 )
{
if ( V_171 != 0 )
V_29 -> V_115 [ V_90 ] |= V_173 ;
else
V_29 -> V_115 [ V_90 ] &= ~ V_173 ;
return F_65 ( V_29 , V_131 , V_90 , V_174 , V_171 ) ;
}
static int F_67 ( struct V_28 * V_29 , int V_131 ,
unsigned int V_90 , int V_171 )
{
if ( V_171 != 0 )
V_29 -> V_115 [ V_90 ] |= V_175 ;
else
V_29 -> V_115 [ V_90 ] &= ~ V_175 ;
return F_65 ( V_29 , V_131 , V_90 , V_176 , V_171 ) ;
}
int F_68 ( struct V_28 * V_29 , unsigned int V_90 ,
int V_171 )
{
return F_66 ( V_29 , V_177 , V_90 , V_171 ) ;
}
int F_69 ( struct V_28 * V_29 , unsigned int V_90 ,
int V_171 )
{
return F_67 ( V_29 , V_177 , V_90 , V_171 ) ;
}
static void F_70 ( struct V_28 * V_29 )
{
struct V_178 * V_179 ;
struct V_180 * V_181 ;
struct V_182 * V_183 ;
struct V_184 * V_185 ;
int V_186 ;
unsigned int V_90 ;
for ( V_186 = 1 ; V_186 <= V_91 ; V_186 ++ ) {
V_179 = F_62 (
sizeof( struct V_178 ) ,
V_187 ,
V_21 ,
V_188 ) ;
if ( ! V_179 )
goto V_189;
V_179 -> V_166 . V_4 = sizeof( struct V_190 ) ;
V_179 -> V_103 . V_191 = V_186 ;
V_179 -> V_103 . V_192 = V_169 ;
V_179 -> V_103 . V_193 = V_177 ;
F_58 ( V_29 , V_125 , & V_179 -> V_166 ) ;
}
V_181 = F_62 (
sizeof( struct V_180 ) ,
V_187 ,
V_21 ,
V_194 ) ;
if ( ! V_181 )
goto V_189;
V_181 -> V_166 . V_4 = sizeof( struct V_195 ) ;
F_58 ( V_29 , V_125 , & V_181 -> V_166 ) ;
for ( V_186 = 1 ; V_186 <= V_91 ; V_186 ++ ) {
V_183 = F_62 (
sizeof( struct V_182 ) ,
V_187 ,
V_21 ,
V_196 ) ;
if ( ! V_183 )
goto V_189;
V_183 -> V_166 . V_4 = sizeof( struct V_197 ) ;
V_183 -> V_103 . V_191 = V_186 ;
F_58 ( V_29 , V_125 , & V_183 -> V_166 ) ;
}
for ( V_90 = 0 ;
V_90 < V_91 ; V_90 ++ ) {
int V_27 ;
V_27 = F_66 ( V_29 , V_125 , V_90 ,
( V_29 -> V_115 [ V_90 ] &
V_173 ) != 0 ) ;
if ( V_27 ) {
F_5 (KERN_ERR IPWIRELESS_PCCARD_NAME
L_20 , ret) ;
return;
}
F_67 ( V_29 , V_125 , V_90 ,
( V_29 -> V_115 [ V_90 ] &
V_175 ) != 0 ) ;
if ( V_27 ) {
F_5 (KERN_ERR IPWIRELESS_PCCARD_NAME
L_21 , ret) ;
return;
}
}
V_185 = F_62 ( sizeof( struct V_184 ) ,
V_187 ,
V_21 ,
V_198 ) ;
if ( ! V_185 )
goto V_189;
V_185 -> V_166 . V_4 = sizeof( struct V_199 ) ;
V_185 -> V_103 . V_200 = V_201 ;
V_185 -> V_103 . V_202 = V_203 ;
V_185 -> V_103 . V_204 = V_205 ;
F_58 ( V_29 , V_125 , & V_185 -> V_166 ) ;
V_29 -> V_123 = 0 ;
return;
V_189:
F_5 (KERN_ERR IPWIRELESS_PCCARD_NAME
L_22 ) ;
V_29 -> V_123 = - 1 ;
}
static void F_71 ( struct V_28 * V_29 ,
unsigned char V_206 )
{
F_72 ( & V_29 -> V_207 ) ;
V_29 -> V_124 = 0 ;
F_5 (KERN_INFO IPWIRELESS_PCCARD_NAME L_23 ) ;
if ( V_206 == V_208 )
F_70 ( V_29 ) ;
else
F_5 (KERN_ERR IPWIRELESS_PCCARD_NAME
L_24 ,
(unsigned int) vers_no) ;
}
static void F_49 ( struct V_28 * V_29 )
{
struct V_209 * V_210 ;
V_210 = F_62 (
sizeof( struct V_209 ) ,
V_187 , V_21 ,
V_211 ) ;
V_210 -> V_166 . V_4 = sizeof( struct V_212 ) ;
F_58 ( V_29 , V_125 , & V_210 -> V_166 ) ;
}
static void F_40 ( struct V_28 * V_29 ,
unsigned int V_60 ,
const unsigned char * V_22 , int V_101 ,
int V_89 )
{
const union V_213 * V_214 = ( const union V_213 * ) V_22 ;
if ( V_60 != V_187 ) {
F_5 (KERN_INFO IPWIRELESS_PCCARD_NAME
L_25 , address) ;
return;
}
switch ( V_214 -> V_105 ) {
case V_215 :
if ( V_29 -> V_123 )
F_71 ( V_29 ,
V_214 -> V_216 . V_217 ) ;
break;
case V_196 :
if ( V_33 ) {
unsigned int V_90 = V_214 -> V_218 . V_191 - 1 ;
F_5 (KERN_INFO IPWIRELESS_PCCARD_NAME
L_26 ,
channel_idx) ;
}
break;
case V_219 :
if ( V_33 )
F_5 (KERN_DEBUG IPWIRELESS_PCCARD_NAME
L_27 ) ;
break;
case V_220 :
if ( V_29 -> V_123 )
F_5 (KERN_DEBUG IPWIRELESS_PCCARD_NAME
L_28 ) ;
else {
struct V_221 * V_49 ;
F_5 (KERN_DEBUG IPWIRELESS_PCCARD_NAME
L_29 ) ;
V_49 = F_62 (
sizeof( struct V_221 ) ,
V_187 , V_21 ,
V_222 ) ;
V_49 -> V_166 . V_4 =
sizeof( struct V_223 ) ;
F_58 ( V_29 , V_125 , & V_49 -> V_166 ) ;
if ( V_29 -> V_224 )
V_29 -> V_224 ( V_29 -> V_225 ) ;
}
break;
default:
F_5 (KERN_INFO IPWIRELESS_PCCARD_NAME
L_30 ,
(unsigned int) rx_msg->sig_no) ;
}
}
static void F_73 ( struct V_28 * V_29 )
{
unsigned int V_138 ;
if ( V_29 -> V_36 == V_37 ) {
F_15 ( 0 , V_29 -> V_38 + V_75 ) ;
V_138 = F_43 ( V_29 -> V_38 + V_134 ) ;
if ( V_138 & V_141 )
F_15 ( V_141 , V_29 -> V_38 + V_134 ) ;
if ( V_138 & V_142 )
F_15 ( V_142 , V_29 -> V_38 + V_134 ) ;
F_74 ( V_29 -> V_137 ) ;
}
}
struct V_28 * F_75 ( void )
{
int V_30 ;
struct V_28 * V_29 =
F_60 ( sizeof( struct V_28 ) , V_226 ) ;
if ( ! V_29 )
return NULL ;
V_29 -> V_137 = - 1 ;
V_29 -> V_124 = 1 ;
V_29 -> V_35 = 1 ;
V_29 -> V_94 = 0 ;
V_29 -> V_82 = 0 ;
V_29 -> V_159 = ( unsigned short ) 0xffff ;
for ( V_30 = 0 ; V_30 < V_126 ; V_30 ++ )
F_61 ( & V_29 -> V_67 [ V_30 ] ) ;
F_61 ( & V_29 -> V_95 ) ;
F_61 ( & V_29 -> V_81 ) ;
F_76 ( & V_29 -> V_34 ) ;
F_77 ( & V_29 -> V_143 , F_48 , ( unsigned long ) V_29 ) ;
F_78 ( & V_29 -> V_98 , F_34 ) ;
V_207 ( & V_29 -> V_207 , V_227 ,
( unsigned long ) V_29 ) ;
return V_29 ;
}
void F_79 ( struct V_28 * V_29 ,
unsigned int V_38 ,
void T_3 * V_228 ,
void T_3 * V_229 ,
int V_230 ,
void (* V_224) ( void * V_22 ) ,
void * V_225 )
{
if ( V_29 -> V_231 ) {
V_29 -> V_231 = 0 ;
F_80 ( V_29 -> V_137 ) ;
}
V_29 -> V_38 = V_38 ;
V_29 -> V_36 = ( V_230 ? V_44 : V_37 ) ;
V_29 -> V_32 = ( V_29 -> V_36 == V_37 ? V_232 : V_233 ) ;
V_29 -> V_77 = (struct V_234 T_3 * )
( ( unsigned short T_3 * ) V_228 + 0x200 ) ;
V_29 -> V_46 = (struct V_235 T_3 * ) V_229 ;
V_29 -> V_150 = & V_29 -> V_46 -> V_156 ;
V_29 -> V_224 = V_224 ;
V_29 -> V_225 = V_225 ;
}
void F_81 ( struct V_28 * V_29 )
{
V_29 -> V_124 = 1 ;
V_29 -> V_236 = 0 ;
F_5 (KERN_INFO IPWIRELESS_PCCARD_NAME
L_31 ) ;
V_227 ( ( unsigned long ) V_29 ) ;
}
static void V_227 ( unsigned long V_22 )
{
struct V_28 * V_29 = (struct V_28 * ) V_22 ;
V_29 -> V_236 ++ ;
if ( V_29 -> V_236 == V_237 &&
V_29 -> V_36 == V_44 &&
V_29 -> V_150 == & V_29 -> V_46 -> V_156 ) {
F_5 (KERN_INFO IPWIRELESS_PCCARD_NAME
L_32 ) ;
V_29 -> V_150 = & V_29 -> V_46 -> V_157 ;
V_29 -> V_236 = 0 ;
}
if ( V_29 -> V_236 == V_237 ) {
F_5 (KERN_INFO IPWIRELESS_PCCARD_NAME
L_33 ) ;
V_29 -> V_124 = 0 ;
} else {
if ( F_50 ( V_29 ) ) {
unsigned long V_31 ;
F_14 ( & V_29 -> V_34 , V_31 ) ;
V_29 -> V_123 = 1 ;
V_29 -> V_35 = 1 ;
F_18 ( & V_29 -> V_34 , V_31 ) ;
F_53 ( & V_29 -> V_143 ) ;
}
F_82 ( & V_29 -> V_207 ,
V_3 + F_83 ( V_238 ) ) ;
}
}
void F_84 ( struct V_28 * V_29 )
{
if ( ! V_29 -> V_100 ) {
V_29 -> V_100 = 1 ;
F_72 ( & V_29 -> V_207 ) ;
F_73 ( V_29 ) ;
}
}
void F_85 ( struct V_28 * V_29 )
{
int V_30 ;
struct V_79 * V_239 , * V_240 ;
struct V_48 * V_241 , * V_242 ;
F_84 ( V_29 ) ;
F_86 ( & V_29 -> V_98 ) ;
for ( V_30 = 0 ; V_30 < V_91 ; V_30 ++ )
F_21 ( V_29 -> V_93 [ V_30 ] ) ;
for ( V_30 = 0 ; V_30 < V_126 ; V_30 ++ )
F_87 (tp, tq, &hw->tx_queue[i], queue) {
F_27 ( & V_241 -> V_66 ) ;
F_21 ( V_241 ) ;
}
F_87 (rp, rq, &hw->rx_queue, queue) {
F_27 ( & V_239 -> V_66 ) ;
F_21 ( V_239 ) ;
}
F_87 (rp, rq, &hw->rx_pool, queue) {
F_27 ( & V_239 -> V_66 ) ;
F_21 ( V_239 ) ;
}
F_21 ( V_29 ) ;
}
void F_88 ( struct V_28 * V_29 ,
struct V_243 * V_84 )
{
V_29 -> V_84 = V_84 ;
}
