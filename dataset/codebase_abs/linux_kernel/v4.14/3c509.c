static int F_1 ( T_1 * V_1 )
{
short V_2 = 0xff ;
int V_3 ;
F_2 ( 0x00 , V_4 ) ;
F_2 ( 0x00 , V_4 ) ;
for ( V_3 = 0 ; V_3 < 255 ; V_3 ++ ) {
F_2 ( V_2 , V_4 ) ;
V_2 <<= 1 ;
V_2 = V_2 & 0x100 ? V_2 ^ 0xcf : V_2 ;
}
if ( V_5 == 0 )
F_2 ( 0xd0 , V_4 ) ;
else
F_2 ( 0xd8 , V_4 ) ;
if ( F_3 ( 7 ) != 0x6d50 )
return 1 ;
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ )
V_1 [ V_3 ] = F_4 ( F_3 ( V_3 ) ) ;
#ifdef F_5
if ( ! V_6 ) {
for ( V_3 = 0 ; V_3 < V_7 ; V_3 ++ ) {
struct V_8 * V_9 = F_6 ( V_10 [ V_3 ] ) ;
if ( V_9 -> type == V_11 &&
F_7 ( ( V_12 * ) V_1 , V_10 [ V_3 ] -> V_13 ) ) {
if ( V_14 > 3 )
F_8 ( L_1 ,
V_1 [ 0 ] & 0xff , V_1 [ 0 ] >> 8 ,
V_1 [ 1 ] & 0xff , V_1 [ 1 ] >> 8 ,
V_1 [ 2 ] & 0xff , V_1 [ 2 ] >> 8 ) ;
F_2 ( 0xd0 + ++ V_5 , V_4 ) ;
return 2 ;
}
}
}
#endif
return 0 ;
}
static void F_9 ( struct V_15 * V_16 , T_1 * V_1 , int V_17 ,
int V_18 , int V_19 , enum V_20 type )
{
struct V_8 * V_9 = F_6 ( V_16 ) ;
memcpy ( V_16 -> V_13 , V_1 , V_21 ) ;
V_16 -> V_22 = V_17 ;
V_16 -> V_18 = V_18 ;
V_16 -> V_19 = V_19 ;
V_9 -> type = type ;
}
static int F_10 ( struct V_23 * V_24 , unsigned int V_25 )
{
struct V_15 * V_16 ;
int V_17 , V_26 , V_19 , V_27 ;
unsigned int V_28 ;
T_1 V_1 [ 3 ] ;
while ( ( V_27 = F_1 ( V_1 ) ) == 2 )
;
if ( V_27 == 1 )
return 0 ;
V_28 = F_3 ( 8 ) ;
V_19 = V_28 >> 14 ;
V_17 = 0x200 + ( ( V_28 & 0x1f ) << 4 ) ;
if ( V_18 [ V_7 ] > 1 && V_18 [ V_7 ] < 16 )
V_26 = V_18 [ V_7 ] ;
else
V_26 = F_3 ( 9 ) >> 12 ;
V_16 = F_11 ( sizeof( struct V_8 ) ) ;
if ( ! V_16 )
return - V_29 ;
F_12 ( V_16 , V_24 ) ;
F_13 ( V_16 ) ;
if ( ! F_14 ( V_17 , V_30 , L_2 ) ) {
F_15 ( V_16 ) ;
return 0 ;
}
F_2 ( 0xd0 + ++ V_5 , V_4 ) ;
F_2 ( ( V_17 >> 4 ) | 0xe0 , V_4 ) ;
F_16 ( 0 ) ;
if ( F_17 ( V_17 ) != 0x6d50 ) {
F_15 ( V_16 ) ;
return 0 ;
}
F_18 ( 0x0f00 , V_17 + V_31 ) ;
F_9 ( V_16 , V_1 , V_17 , V_26 , V_19 , V_32 ) ;
F_19 ( V_24 , V_16 ) ;
if ( F_20 ( V_16 ) ) {
F_15 ( V_16 ) ;
return 0 ;
}
V_10 [ V_7 ++ ] = V_16 ;
return 1 ;
}
static int F_21 ( struct V_23 * V_24 ,
unsigned int V_25 )
{
F_22 ( V_24 ) ;
F_19 ( V_24 , NULL ) ;
return 0 ;
}
static int F_23 ( struct V_23 * V_16 , unsigned int V_33 ,
T_2 V_34 )
{
V_5 = 0 ;
return F_24 ( V_16 , V_34 ) ;
}
static int F_25 ( struct V_23 * V_16 , unsigned int V_33 )
{
struct V_15 * V_25 = F_26 ( V_16 ) ;
int V_17 = V_25 -> V_22 , V_27 ;
T_1 V_1 [ 3 ] ;
while ( ( V_27 = F_1 ( V_1 ) ) == 2 )
;
if ( V_27 == 1 )
return 0 ;
F_2 ( 0xd0 + ++ V_5 , V_4 ) ;
F_2 ( ( V_17 >> 4 ) | 0xe0 , V_4 ) ;
F_16 ( 0 ) ;
if ( F_17 ( V_17 ) != 0x6d50 )
return 1 ;
F_18 ( 0x0f00 , V_17 + V_31 ) ;
return F_27 ( V_16 ) ;
}
static int F_28 ( struct V_35 * V_24 , const struct V_36 * V_37 )
{
short V_3 ;
int V_17 , V_18 , V_19 ;
T_1 V_1 [ 3 ] ;
struct V_15 * V_16 = NULL ;
int V_27 ;
V_17 = F_29 ( V_24 , 0 ) ;
if ( ! F_14 ( V_17 , V_30 , L_3 ) )
return - V_38 ;
V_18 = F_30 ( V_24 , 0 ) ;
F_16 ( 0 ) ;
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ )
V_1 [ V_3 ] = F_4 ( F_31 ( V_17 , V_3 ) ) ;
V_19 = F_31 ( V_17 , 8 ) >> 14 ;
V_16 = F_11 ( sizeof( struct V_8 ) ) ;
if ( ! V_16 ) {
F_32 ( V_17 , V_30 ) ;
return - V_29 ;
}
F_12 ( V_16 , & V_24 -> V_16 ) ;
F_13 ( V_16 ) ;
F_9 ( V_16 , V_1 , V_17 , V_18 , V_19 , V_11 ) ;
F_33 ( V_24 , V_16 ) ;
V_27 = F_20 ( V_16 ) ;
if ( V_27 ) {
F_33 ( V_24 , NULL ) ;
F_15 ( V_16 ) ;
return V_27 ;
}
V_10 [ V_7 ++ ] = V_16 ;
return 0 ;
}
static void F_34 ( struct V_35 * V_24 )
{
F_35 ( F_36 ( V_24 ) ) ;
F_33 ( V_24 , NULL ) ;
}
static int F_37 ( struct V_35 * V_24 , T_2 V_34 )
{
return F_24 ( & V_24 -> V_16 , V_34 ) ;
}
static int F_38 ( struct V_35 * V_24 )
{
return F_27 ( & V_24 -> V_16 ) ;
}
static int F_20 ( struct V_15 * V_16 )
{
struct V_8 * V_9 = F_6 ( V_16 ) ;
int V_27 ;
const char * V_39 [] = { L_4 , L_5 , L_6 , L_7 } ;
F_39 ( & V_9 -> V_40 ) ;
if ( V_16 -> V_41 & 0x05 ) {
V_16 -> V_19 = ( V_16 -> V_41 & 0x0f ) ;
} else {
V_16 -> V_19 |= ( V_16 -> V_41 & 0x08 ) ;
}
V_16 -> V_42 = & V_42 ;
V_16 -> V_43 = V_44 ;
V_16 -> V_45 = & V_45 ;
V_27 = F_40 ( V_16 ) ;
if ( V_27 ) {
F_41 ( L_8 ,
V_16 -> V_22 , V_16 -> V_18 ) ;
F_32 ( V_16 -> V_22 , V_30 ) ;
return V_27 ;
}
F_42 ( L_9 ,
V_16 -> V_46 , V_16 -> V_22 , V_39 [ ( V_16 -> V_19 & 0x03 ) ] ,
V_16 -> V_13 , V_16 -> V_18 ) ;
if ( V_14 > 0 )
F_42 ( L_10 , V_47 ) ;
return 0 ;
}
static void F_35 ( struct V_15 * V_16 )
{
F_43 ( V_16 ) ;
F_32 ( V_16 -> V_22 , V_30 ) ;
F_15 ( V_16 ) ;
}
static int F_44 ( struct V_23 * V_23 )
{
short V_3 ;
int V_17 , V_18 , V_19 ;
T_1 V_1 [ 3 ] ;
struct V_15 * V_16 = NULL ;
struct V_48 * V_49 ;
int V_27 ;
V_49 = F_45 ( V_23 ) ;
V_17 = V_49 -> V_22 ;
if ( ! F_14 ( V_17 , V_30 , L_11 ) )
return - V_38 ;
F_18 ( V_50 | 0 , V_17 + 0xC80 + V_51 ) ;
V_18 = F_17 ( V_17 + V_31 ) >> 12 ;
V_19 = F_17 ( V_17 + 6 ) >> 14 ;
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ )
V_1 [ V_3 ] = F_4 ( F_31 ( V_17 , V_3 ) ) ;
F_31 ( V_17 , 3 ) ;
V_16 = F_11 ( sizeof ( struct V_8 ) ) ;
if ( V_16 == NULL ) {
F_32 ( V_17 , V_30 ) ;
return - V_29 ;
}
F_12 ( V_16 , V_23 ) ;
F_13 ( V_16 ) ;
F_9 ( V_16 , V_1 , V_17 , V_18 , V_19 , V_52 ) ;
F_46 ( V_49 , V_16 ) ;
V_27 = F_20 ( V_16 ) ;
if ( V_27 ) {
F_46 ( V_49 , NULL ) ;
F_15 ( V_16 ) ;
return V_27 ;
}
V_10 [ V_7 ++ ] = V_16 ;
return 0 ;
}
static int F_22 ( struct V_23 * V_23 )
{
struct V_15 * V_16 ;
V_16 = F_26 ( V_23 ) ;
F_35 ( V_16 ) ;
return 0 ;
}
static T_3 F_31 ( int V_17 , int V_53 )
{
F_18 ( V_54 + V_53 , V_17 + 10 ) ;
F_47 ( 2 ) ;
return F_17 ( V_17 + 12 ) ;
}
static T_3 F_3 ( int V_53 )
{
int V_55 , V_56 = 0 ;
F_2 ( V_54 + V_53 , V_4 ) ;
F_47 ( 4 ) ;
for ( V_55 = 15 ; V_55 >= 0 ; V_55 -- )
V_56 = ( V_56 << 1 ) + ( F_48 ( V_4 ) & 0x01 ) ;
if ( V_14 > 3 )
F_8 ( L_12 , V_53 , V_56 ) ;
return V_56 ;
}
static int
F_49 ( struct V_15 * V_16 )
{
int V_17 = V_16 -> V_22 ;
int V_3 ;
F_18 ( V_57 , V_17 + V_51 ) ;
F_18 ( V_58 , V_17 + V_51 ) ;
F_18 ( V_59 | 0x00 , V_17 + V_51 ) ;
V_3 = F_50 ( V_16 -> V_18 , V_60 , 0 , V_16 -> V_46 , V_16 ) ;
if ( V_3 )
return V_3 ;
F_16 ( 0 ) ;
if ( V_14 > 3 )
F_8 ( L_13 , V_16 -> V_46 ,
V_16 -> V_18 , V_17 + V_61 , F_17 ( V_17 + V_61 ) ) ;
F_51 ( V_16 ) ;
if ( V_14 > 3 )
F_8 ( L_14 ,
V_16 -> V_46 , V_16 -> V_18 , F_17 ( V_17 + V_61 ) ) ;
return 0 ;
}
static void
F_52 ( struct V_15 * V_16 )
{
int V_17 = V_16 -> V_22 ;
F_53 ( L_15 ,
V_16 -> V_46 , F_48 ( V_17 + V_62 ) , F_17 ( V_17 + V_61 ) ,
F_17 ( V_17 + V_63 ) ) ;
V_16 -> V_64 . V_65 ++ ;
F_54 ( V_16 ) ;
F_18 ( V_57 , V_17 + V_51 ) ;
F_18 ( V_66 , V_17 + V_51 ) ;
F_55 ( V_16 ) ;
}
static T_4
F_56 ( struct V_67 * V_68 , struct V_15 * V_16 )
{
struct V_8 * V_9 = F_6 ( V_16 ) ;
int V_17 = V_16 -> V_22 ;
unsigned long V_69 ;
F_57 ( V_16 ) ;
V_16 -> V_64 . V_70 += V_68 -> V_71 ;
if ( V_14 > 4 ) {
F_8 ( L_16 ,
V_16 -> V_46 , V_68 -> V_71 , F_17 ( V_17 + V_61 ) ) ;
}
F_58 ( & V_9 -> V_40 , V_69 ) ;
F_18 ( V_68 -> V_71 , V_17 + V_72 ) ;
F_18 ( 0x00 , V_17 + V_72 ) ;
F_59 ( V_17 + V_72 , V_68 -> V_73 , ( V_68 -> V_71 + 3 ) >> 2 ) ;
if ( F_17 ( V_17 + V_63 ) > 1536 )
F_60 ( V_16 ) ;
else
F_18 ( V_74 + 1536 , V_17 + V_51 ) ;
F_61 ( & V_9 -> V_40 , V_69 ) ;
F_62 ( V_68 ) ;
{
short V_75 ;
int V_3 = 4 ;
while ( -- V_3 > 0 && ( V_75 = F_48 ( V_17 + V_62 ) ) > 0 ) {
if ( V_75 & 0x38 ) V_16 -> V_64 . V_76 ++ ;
if ( V_75 & 0x30 ) F_18 ( V_57 , V_17 + V_51 ) ;
if ( V_75 & 0x3C ) F_18 ( V_66 , V_17 + V_51 ) ;
F_2 ( 0x00 , V_17 + V_62 ) ;
}
}
return V_77 ;
}
static T_5
V_60 ( int V_18 , void * V_78 )
{
struct V_15 * V_16 = V_78 ;
struct V_8 * V_9 ;
int V_17 , V_79 ;
int V_3 = V_80 ;
V_9 = F_6 ( V_16 ) ;
F_63 ( & V_9 -> V_40 ) ;
V_17 = V_16 -> V_22 ;
if ( V_14 > 4 ) {
V_79 = F_17 ( V_17 + V_61 ) ;
F_8 ( L_17 , V_16 -> V_46 , V_79 ) ;
}
while ( ( V_79 = F_17 ( V_17 + V_61 ) ) &
( V_81 | V_82 | V_83 ) ) {
if ( V_79 & V_82 )
F_64 ( V_16 ) ;
if ( V_79 & V_84 ) {
if ( V_14 > 5 )
F_8 ( L_18 ) ;
F_18 ( V_85 | V_84 , V_17 + V_51 ) ;
F_55 ( V_16 ) ;
}
if ( V_79 & ( V_86 | V_87 | V_83 | V_88 ) ) {
if ( V_79 & V_83 )
F_65 ( V_16 ) ;
if ( V_79 & V_87 ) {
F_64 ( V_16 ) ;
F_18 ( V_85 | V_87 , V_17 + V_51 ) ;
}
if ( V_79 & V_88 ) {
short V_75 ;
int V_3 = 4 ;
while ( -- V_3 > 0 && ( V_75 = F_48 ( V_17 + V_62 ) ) > 0 ) {
if ( V_75 & 0x38 ) V_16 -> V_64 . V_76 ++ ;
if ( V_75 & 0x30 ) F_18 ( V_57 , V_17 + V_51 ) ;
if ( V_75 & 0x3C ) F_18 ( V_66 , V_17 + V_51 ) ;
F_2 ( 0x00 , V_17 + V_62 ) ;
}
}
if ( V_79 & V_86 ) {
F_18 ( V_58 , V_17 + V_51 ) ;
F_18 ( V_89 | V_90 | V_91
| ( V_16 -> V_69 & V_92 ? V_93 : 0 )
| ( V_16 -> V_69 & V_94 ? V_95 : 0 ) ,
V_17 + V_51 ) ;
F_18 ( V_96 , V_17 + V_51 ) ;
F_18 ( V_85 | V_86 , V_17 + V_51 ) ;
}
}
if ( -- V_3 < 0 ) {
F_41 ( L_19 ,
V_16 -> V_46 , V_79 ) ;
F_18 ( V_85 | 0xFF , V_17 + V_51 ) ;
break;
}
F_18 ( V_85 | V_97 | V_81 , V_17 + V_51 ) ;
}
if ( V_14 > 4 ) {
F_8 ( L_20 , V_16 -> V_46 ,
F_17 ( V_17 + V_61 ) ) ;
}
F_66 ( & V_9 -> V_40 ) ;
return V_98 ;
}
static void F_67 ( struct V_15 * V_16 )
{
F_68 ( V_16 -> V_18 ) ;
V_60 ( V_16 -> V_18 , V_16 ) ;
F_69 ( V_16 -> V_18 ) ;
}
static struct V_99 *
F_70 ( struct V_15 * V_16 )
{
struct V_8 * V_9 = F_6 ( V_16 ) ;
unsigned long V_69 ;
F_58 ( & V_9 -> V_40 , V_69 ) ;
F_65 ( V_16 ) ;
F_61 ( & V_9 -> V_40 , V_69 ) ;
return & V_16 -> V_64 ;
}
static void F_65 ( struct V_15 * V_16 )
{
int V_17 = V_16 -> V_22 ;
if ( V_14 > 5 )
F_8 ( L_21 ) ;
F_18 ( V_100 , V_17 + V_51 ) ;
F_16 ( 6 ) ;
V_16 -> V_64 . V_101 += F_48 ( V_17 + 0 ) ;
V_16 -> V_64 . V_102 += F_48 ( V_17 + 1 ) ;
F_48 ( V_17 + 2 ) ;
V_16 -> V_64 . V_103 += F_48 ( V_17 + 3 ) ;
V_16 -> V_64 . V_104 += F_48 ( V_17 + 4 ) ;
V_16 -> V_64 . V_105 += F_48 ( V_17 + 5 ) ;
V_16 -> V_64 . V_106 += F_48 ( V_17 + 6 ) ;
F_48 ( V_17 + 7 ) ;
F_48 ( V_17 + 8 ) ;
F_17 ( V_17 + 10 ) ;
F_17 ( V_17 + 12 ) ;
F_16 ( 1 ) ;
F_18 ( V_107 , V_17 + V_51 ) ;
}
static int
F_64 ( struct V_15 * V_16 )
{
int V_17 = V_16 -> V_22 ;
short V_108 ;
if ( V_14 > 5 )
F_8 ( L_22 ,
F_17 ( V_17 + V_61 ) , F_17 ( V_17 + V_109 ) ) ;
while ( ( V_108 = F_17 ( V_17 + V_109 ) ) > 0 ) {
if ( V_108 & 0x4000 ) {
short error = V_108 & 0x3800 ;
F_18 ( V_110 , V_17 + V_51 ) ;
V_16 -> V_64 . V_111 ++ ;
switch ( error ) {
case 0x0000 : V_16 -> V_64 . V_112 ++ ; break;
case 0x0800 : V_16 -> V_64 . V_113 ++ ; break;
case 0x1000 : V_16 -> V_64 . V_114 ++ ; break;
case 0x1800 : V_16 -> V_64 . V_113 ++ ; break;
case 0x2000 : V_16 -> V_64 . V_114 ++ ; break;
case 0x2800 : V_16 -> V_64 . V_115 ++ ; break;
}
} else {
short V_116 = V_108 & 0x7ff ;
struct V_67 * V_68 ;
V_68 = F_71 ( V_16 , V_116 + 5 ) ;
if ( V_14 > 4 )
F_8 ( L_23 ,
V_116 , V_108 ) ;
if ( V_68 != NULL ) {
F_72 ( V_68 , 2 ) ;
F_73 ( V_17 + V_117 , F_74 ( V_68 , V_116 ) ,
( V_116 + 3 ) >> 2 ) ;
F_18 ( V_110 , V_17 + V_51 ) ;
V_68 -> V_118 = F_75 ( V_68 , V_16 ) ;
F_76 ( V_68 ) ;
V_16 -> V_64 . V_119 += V_116 ;
V_16 -> V_64 . V_120 ++ ;
continue;
}
F_18 ( V_110 , V_17 + V_51 ) ;
V_16 -> V_64 . V_121 ++ ;
if ( V_14 )
F_8 ( L_24 ,
V_16 -> V_46 , V_116 ) ;
}
F_17 ( V_17 + V_61 ) ;
while ( F_17 ( V_17 + V_61 ) & 0x1000 )
F_8 ( L_25 ,
F_17 ( V_17 + V_61 ) ) ;
}
return 0 ;
}
static void
F_77 ( struct V_15 * V_16 )
{
unsigned long V_69 ;
struct V_8 * V_9 = F_6 ( V_16 ) ;
int V_17 = V_16 -> V_22 ;
int V_122 = F_78 ( V_16 ) ;
if ( V_14 > 1 ) {
static int V_123 ;
if ( V_123 != V_122 ) {
V_123 = V_122 ;
F_8 ( L_26 ,
V_16 -> V_46 , V_122 ) ;
}
}
F_58 ( & V_9 -> V_40 , V_69 ) ;
if ( V_16 -> V_69 & V_94 ) {
F_18 ( V_89 | V_90 | V_93 | V_91 | V_95 ,
V_17 + V_51 ) ;
}
else if ( V_122 || ( V_16 -> V_69 & V_92 ) ) {
F_18 ( V_89 | V_90 | V_93 | V_91 , V_17 + V_51 ) ;
}
else
F_18 ( V_89 | V_90 | V_91 , V_17 + V_51 ) ;
F_61 ( & V_9 -> V_40 , V_69 ) ;
}
static int
F_79 ( struct V_15 * V_16 )
{
int V_17 = V_16 -> V_22 ;
struct V_8 * V_9 = F_6 ( V_16 ) ;
if ( V_14 > 2 )
F_8 ( L_27 , V_16 -> V_46 ) ;
F_80 ( V_16 ) ;
F_81 ( V_16 -> V_18 , V_16 ) ;
F_16 ( 0 ) ;
if ( V_9 -> type != V_52 ) {
F_18 ( 0x0f00 , V_17 + V_31 ) ;
}
return 0 ;
}
static int
F_82 ( struct V_15 * V_16 )
{
int V_17 = V_16 -> V_22 ;
T_6 V_124 ;
F_16 ( 4 ) ;
V_124 = F_17 ( V_17 + V_125 ) ;
F_16 ( 1 ) ;
return V_124 & ( 1 << 11 ) ;
}
static void
F_83 ( struct V_15 * V_16 , struct V_126 * V_127 )
{
T_6 V_124 ;
int V_17 = V_16 -> V_22 ;
T_7 V_128 ;
F_16 ( 0 ) ;
V_124 = F_17 ( V_17 + V_129 ) ;
switch ( V_124 >> 14 ) {
case 0 :
V_127 -> V_130 . V_131 = V_132 ;
break;
case 1 :
V_127 -> V_130 . V_131 = V_133 ;
break;
case 3 :
V_127 -> V_130 . V_131 = V_134 ;
default:
break;
}
V_127 -> V_130 . V_135 = V_136 ;
V_128 = 0 ;
V_124 = F_17 ( V_17 + V_137 ) ;
if ( V_124 & ( 1 << 13 ) )
V_128 |= V_138 ;
if ( V_124 & ( 1 << 12 ) )
V_128 |= V_139 ;
if ( V_124 & ( 1 << 9 ) ) {
V_128 |= V_140 | V_141 |
V_142 ;
F_16 ( 4 ) ;
V_124 = F_17 ( V_17 + V_143 ) ;
if ( V_124 & V_144 )
V_127 -> V_130 . V_135 = V_145 ;
}
F_84 ( V_127 -> V_146 . V_128 ,
V_128 ) ;
V_127 -> V_130 . V_147 = V_148 ;
F_16 ( 1 ) ;
}
static int
F_85 ( struct V_15 * V_16 ,
const struct V_126 * V_127 )
{
T_6 V_124 ;
int V_17 = V_16 -> V_22 ;
if ( V_127 -> V_130 . V_147 != V_148 )
return - V_149 ;
if ( ( V_127 -> V_130 . V_135 != V_136 ) &&
( V_127 -> V_130 . V_135 != V_145 ) )
return - V_149 ;
F_16 ( 0 ) ;
V_124 = F_17 ( V_17 + V_129 ) ;
switch ( V_127 -> V_130 . V_131 ) {
case V_132 :
V_124 &= ~ ( 3 << 14 ) ;
V_16 -> V_19 = 0 ;
break;
case V_133 :
V_124 |= ( 1 << 14 ) ;
V_16 -> V_19 = 1 ;
break;
case V_134 :
V_124 |= ( 3 << 14 ) ;
V_16 -> V_19 = 3 ;
break;
default:
return - V_149 ;
}
F_18 ( V_124 , V_17 + V_129 ) ;
if ( V_16 -> V_19 == 3 ) {
V_124 = F_17 ( V_17 + V_129 ) ;
if ( V_124 & ( 3 << 14 ) ) {
F_18 ( V_150 , V_17 + V_51 ) ;
F_86 ( 800 ) ;
} else
return - V_151 ;
}
F_16 ( 4 ) ;
V_124 = F_17 ( V_17 + V_143 ) ;
if ( V_127 -> V_130 . V_135 == V_145 )
V_124 |= V_144 ;
else
V_124 &= ~ V_144 ;
F_18 ( V_124 , V_17 + V_143 ) ;
F_16 ( 1 ) ;
return 0 ;
}
static void F_87 ( struct V_15 * V_16 , struct V_152 * V_153 )
{
F_88 ( V_153 -> V_154 , V_155 , sizeof( V_153 -> V_154 ) ) ;
F_88 ( V_153 -> V_47 , V_156 , sizeof( V_153 -> V_47 ) ) ;
}
static int F_89 ( struct V_15 * V_16 ,
struct V_126 * V_127 )
{
struct V_8 * V_9 = F_6 ( V_16 ) ;
F_90 ( & V_9 -> V_40 ) ;
F_83 ( V_16 , V_127 ) ;
F_91 ( & V_9 -> V_40 ) ;
return 0 ;
}
static int F_92 ( struct V_15 * V_16 ,
const struct V_126 * V_127 )
{
struct V_8 * V_9 = F_6 ( V_16 ) ;
int V_157 ;
F_90 ( & V_9 -> V_40 ) ;
V_157 = F_85 ( V_16 , V_127 ) ;
F_91 ( & V_9 -> V_40 ) ;
return V_157 ;
}
static T_7 F_93 ( struct V_15 * V_16 )
{
struct V_8 * V_9 = F_6 ( V_16 ) ;
T_7 V_157 ;
F_90 ( & V_9 -> V_40 ) ;
V_157 = F_82 ( V_16 ) ;
F_91 ( & V_9 -> V_40 ) ;
return V_157 ;
}
static T_7 F_94 ( struct V_15 * V_16 )
{
return V_14 ;
}
static void F_95 ( struct V_15 * V_16 , T_7 V_158 )
{
V_14 = V_158 ;
}
static void
F_80 ( struct V_15 * V_16 )
{
int V_17 = V_16 -> V_22 ;
F_57 ( V_16 ) ;
F_18 ( V_100 , V_17 + V_51 ) ;
F_18 ( V_159 , V_17 + V_51 ) ;
F_18 ( V_160 , V_17 + V_51 ) ;
if ( V_16 -> V_19 == 3 )
F_18 ( V_161 , V_17 + V_51 ) ;
else if ( V_16 -> V_19 == 0 ) {
F_16 ( 4 ) ;
F_18 ( F_17 ( V_17 + V_125 ) & ~ V_162 , V_17 + V_125 ) ;
}
F_18 ( V_163 | 0x0000 , V_17 + V_51 ) ;
F_65 ( V_16 ) ;
}
static void
F_51 ( struct V_15 * V_16 )
{
int V_3 , V_164 , V_165 ;
int V_17 = V_16 -> V_22 ;
F_18 ( 0x0001 , V_17 + 4 ) ;
F_18 ( ( V_16 -> V_18 << 12 ) | 0x0f00 , V_17 + V_31 ) ;
F_16 ( 2 ) ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ )
F_2 ( V_16 -> V_13 [ V_3 ] , V_17 + V_3 ) ;
if ( ( V_16 -> V_19 & 0x03 ) == 3 )
F_18 ( V_150 , V_17 + V_51 ) ;
else if ( ( V_16 -> V_19 & 0x03 ) == 0 ) {
F_16 ( 0 ) ;
V_164 = ( F_31 ( V_17 , 0x14 ) & 0x400f ) |
( F_31 ( V_17 , 0x0d ) & 0xBff0 ) ;
F_16 ( 4 ) ;
V_165 = F_17 ( V_17 + V_143 ) ;
V_165 = ( V_165 | V_144 ) ;
F_42 ( L_28 , V_16 -> V_46 ) ;
switch ( V_16 -> V_19 & 0x0c ) {
case 12 :
if ( V_164 & 0x000f ) {
F_96 ( L_29 ) ;
break;
}
case 8 :
if ( ( V_164 & 0x000f ) && ( V_164 & 0x8000 ) ) {
F_96 ( L_30 ) ;
break;
}
default:
F_96 ( L_31 ) ;
V_165 = ( V_165 & ~ V_144 ) ;
}
F_18 ( V_165 , V_17 + V_143 ) ;
F_96 ( L_32 , V_16 -> V_19 , V_164 ) ;
if ( V_14 > 3 )
F_8 ( L_33 , V_16 -> V_46 , V_165 ) ;
F_18 ( F_17 ( V_17 + V_125 ) | V_162 , V_17 + V_125 ) ;
}
F_18 ( V_100 , V_17 + V_51 ) ;
F_16 ( 6 ) ;
for ( V_3 = 0 ; V_3 < 9 ; V_3 ++ )
F_48 ( V_17 + V_3 ) ;
F_17 ( V_17 + 10 ) ;
F_17 ( V_17 + 12 ) ;
F_16 ( 1 ) ;
F_18 ( V_89 | V_90 | V_91 , V_17 + V_51 ) ;
F_18 ( V_107 , V_17 + V_51 ) ;
F_18 ( V_96 , V_17 + V_51 ) ;
F_18 ( V_66 , V_17 + V_51 ) ;
F_18 ( V_59 | 0xff , V_17 + V_51 ) ;
F_18 ( V_85 | V_81 | V_84 | V_87 | V_97 ,
V_17 + V_51 ) ;
F_18 ( V_163 | V_81 | V_84 | V_88 | V_82 | V_83 ,
V_17 + V_51 ) ;
F_60 ( V_16 ) ;
}
static int
F_24 ( struct V_23 * V_24 , T_2 V_34 )
{
unsigned long V_69 ;
struct V_15 * V_16 ;
struct V_8 * V_9 ;
int V_17 ;
V_16 = F_26 ( V_24 ) ;
V_9 = F_6 ( V_16 ) ;
V_17 = V_16 -> V_22 ;
F_58 ( & V_9 -> V_40 , V_69 ) ;
if ( F_97 ( V_16 ) )
F_98 ( V_16 ) ;
F_80 ( V_16 ) ;
F_18 ( V_166 , V_17 + V_51 ) ;
F_61 ( & V_9 -> V_40 , V_69 ) ;
return 0 ;
}
static int
F_27 ( struct V_23 * V_24 )
{
unsigned long V_69 ;
struct V_15 * V_16 ;
struct V_8 * V_9 ;
int V_17 ;
V_16 = F_26 ( V_24 ) ;
V_9 = F_6 ( V_16 ) ;
V_17 = V_16 -> V_22 ;
F_58 ( & V_9 -> V_40 , V_69 ) ;
F_18 ( V_167 , V_17 + V_51 ) ;
F_16 ( 0 ) ;
F_51 ( V_16 ) ;
if ( F_97 ( V_16 ) )
F_99 ( V_16 ) ;
F_61 ( & V_9 -> V_40 , V_69 ) ;
return 0 ;
}
static int T_8 F_100 ( void )
{
int V_157 = 0 ;
if ( V_168 >= 0 )
V_14 = V_168 ;
#ifdef F_5
if ( ! V_6 ) {
V_157 = F_101 ( & V_169 ) ;
if ( ! V_157 )
V_170 = 1 ;
}
#endif
for ( V_4 = 0x110 ; V_4 < 0x200 ; V_4 += 0x10 ) {
if ( ! F_14 ( V_4 , 1 , L_34 ) )
continue;
F_2 ( 0x00 , V_4 ) ;
F_2 ( 0xff , V_4 ) ;
if ( F_48 ( V_4 ) & 0x01 )
break;
else
F_32 ( V_4 , 1 ) ;
}
if ( V_4 >= 0x200 ) {
V_4 = 0 ;
F_41 ( L_35 ) ;
} else {
V_157 = F_102 ( & V_171 , V_172 ) ;
if ( ! V_157 )
V_173 = 1 ;
}
#ifdef F_103
V_157 = F_104 ( & V_174 ) ;
if ( ! V_157 )
V_175 = 1 ;
#endif
#ifdef F_5
if ( V_170 )
V_157 = 0 ;
#endif
if ( V_173 )
V_157 = 0 ;
#ifdef F_103
if ( V_175 )
V_157 = 0 ;
#endif
return V_157 ;
}
static void T_9 F_105 ( void )
{
#ifdef F_5
if ( V_170 )
F_106 ( & V_169 ) ;
#endif
if ( V_173 )
F_107 ( & V_171 ) ;
if ( V_4 )
F_32 ( V_4 , 1 ) ;
#ifdef F_103
if ( V_175 )
F_108 ( & V_174 ) ;
#endif
}
