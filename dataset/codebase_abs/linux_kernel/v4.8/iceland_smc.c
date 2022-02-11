static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
T_1 V_5 ;
if ( V_3 & 3 )
return - V_6 ;
if ( ( V_3 + 3 ) > V_4 )
return - V_6 ;
F_2 ( V_7 , V_3 ) ;
V_5 = F_3 ( V_8 ) ;
V_5 = F_4 ( V_5 , V_9 , V_10 , 0 ) ;
F_2 ( V_8 , V_5 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
T_1 V_11 ,
const T_2 * V_12 ,
T_1 V_13 , T_1 V_4 )
{
T_1 V_14 ;
T_1 V_15 , V_16 ;
int V_17 = 0 ;
T_1 V_18 ;
unsigned long V_19 ;
if ( V_11 & 3 )
return - V_6 ;
if ( ( V_11 + V_13 ) > V_4 )
return - V_6 ;
V_14 = V_11 ;
F_6 ( & V_2 -> V_20 , V_19 ) ;
while ( V_13 >= 4 ) {
V_15 = ( V_12 [ 0 ] << 24 ) + ( V_12 [ 1 ] << 16 ) + ( V_12 [ 2 ] << 8 ) + V_12 [ 3 ] ;
V_17 = F_1 ( V_2 , V_14 , V_4 ) ;
if ( V_17 )
goto V_21;
F_2 ( V_22 , V_15 ) ;
V_12 += 4 ;
V_13 -= 4 ;
V_14 += 4 ;
}
if ( 0 != V_13 ) {
V_15 = 0 ;
V_17 = F_1 ( V_2 , V_14 , V_4 ) ;
if ( V_17 )
goto V_21;
V_16 = F_3 ( V_22 ) ;
V_18 = 8 * ( 4 - V_13 ) ;
while ( V_13 > 0 ) {
V_15 = ( V_15 << 8 ) + * V_12 ++ ;
V_13 -- ;
}
V_15 <<= V_18 ;
V_15 |= ( V_16 & ~ ( ( ~ 0UL ) << V_18 ) ) ;
V_17 = F_1 ( V_2 , V_14 , V_4 ) ;
if ( V_17 )
goto V_21;
F_2 ( V_22 , V_15 ) ;
}
V_21:
F_7 ( & V_2 -> V_20 , V_19 ) ;
return V_17 ;
}
void F_8 ( struct V_1 * V_2 )
{
T_1 V_5 = F_9 ( V_23 ) ;
V_5 = F_4 ( V_5 , V_24 , V_25 , 0 ) ;
F_10 ( V_23 , V_5 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
T_1 V_5 = F_9 ( V_23 ) ;
V_5 = F_4 ( V_5 , V_24 , V_25 , 1 ) ;
F_10 ( V_23 , V_5 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
static unsigned char V_15 [] = { 0xE0 , 0x00 , 0x80 , 0x40 } ;
F_5 ( V_2 , 0x0 , V_15 , 4 , sizeof( V_15 ) + 1 ) ;
return 0 ;
}
void F_13 ( struct V_1 * V_2 )
{
T_1 V_5 = F_9 ( V_26 ) ;
V_5 = F_4 ( V_5 , V_27 , V_28 , 1 ) ;
F_10 ( V_26 , V_5 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
T_1 V_5 = F_9 ( V_26 ) ;
V_5 = F_4 ( V_5 , V_27 , V_28 , 0 ) ;
F_10 ( V_26 , V_5 ) ;
}
static bool F_15 ( struct V_1 * V_2 )
{
T_1 V_5 = F_9 ( V_26 ) ;
V_5 = F_16 ( V_5 , V_27 , V_28 ) ;
return ( ( 0 == V_5 ) && ( 0x20100 <= F_9 ( V_29 ) ) ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_30 ;
T_1 V_5 ;
for ( V_30 = 0 ; V_30 < V_2 -> V_31 ; V_30 ++ ) {
V_5 = F_3 ( V_32 ) ;
if ( F_16 ( V_5 , V_33 , V_34 ) )
break;
F_18 ( 1 ) ;
}
if ( V_30 == V_2 -> V_31 )
return - V_6 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , T_3 V_35 )
{
if ( ! F_15 ( V_2 ) )
return - V_6 ;
if ( F_17 ( V_2 ) ) {
F_20 ( L_1 ) ;
return - V_6 ;
}
F_2 ( V_36 , V_35 ) ;
if ( F_17 ( V_2 ) ) {
F_20 ( L_2 ) ;
return - V_6 ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
T_3 V_35 )
{
if ( ! F_15 ( V_2 ) )
return - V_6 ;
if ( F_17 ( V_2 ) ) {
F_20 ( L_1 ) ;
return - V_6 ;
}
F_2 ( V_36 , V_35 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
T_3 V_35 ,
T_1 V_37 )
{
F_2 ( V_38 , V_37 ) ;
return F_19 ( V_2 , V_35 ) ;
}
static int F_23 (
struct V_1 * V_2 ,
T_3 V_35 , T_1 V_37 )
{
F_2 ( V_38 , V_37 ) ;
return F_21 ( V_2 , V_35 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
const struct V_39 * V_40 ;
T_1 V_41 ;
T_1 V_42 ;
const T_2 * V_12 ;
T_1 V_5 ;
T_1 V_13 ;
T_1 V_15 ;
unsigned long V_19 ;
int V_30 ;
if ( ! V_2 -> V_43 . V_44 )
return - V_6 ;
if ( V_2 -> V_45 . V_46 )
return 0 ;
V_40 = ( const struct V_39 * ) V_2 -> V_43 . V_44 -> V_15 ;
F_25 ( & V_40 -> V_47 ) ;
V_2 -> V_43 . V_48 = F_26 ( V_40 -> V_47 . V_49 ) ;
V_41 = F_26 ( V_40 -> V_47 . V_50 ) ;
V_42 = F_26 ( V_40 -> V_51 ) ;
V_12 = ( const T_2 * )
( V_2 -> V_43 . V_44 -> V_15 + F_26 ( V_40 -> V_47 . V_52 ) ) ;
if ( V_41 & 3 ) {
F_20 ( L_3 ) ;
return - V_6 ;
}
if ( V_41 > V_53 ) {
F_20 ( L_4 ) ;
return - V_6 ;
}
for ( V_30 = 0 ; V_30 < V_2 -> V_31 ; V_30 ++ ) {
V_5 = F_9 ( V_54 ) ;
if ( F_16 ( V_5 , V_55 , V_56 ) == 0 )
break;
F_18 ( 1 ) ;
}
V_5 = F_9 ( V_57 ) ;
F_10 ( V_57 , V_5 | 1 ) ;
F_13 ( V_2 ) ;
F_11 ( V_2 ) ;
F_6 ( & V_2 -> V_20 , V_19 ) ;
F_2 ( V_7 , V_42 ) ;
V_5 = F_3 ( V_8 ) ;
V_5 = F_4 ( V_5 , V_9 , V_10 , 1 ) ;
F_2 ( V_8 , V_5 ) ;
V_13 = V_41 ;
while ( V_13 >= 4 ) {
V_15 = ( V_12 [ 0 ] << 24 ) + ( V_12 [ 1 ] << 16 ) + ( V_12 [ 2 ] << 8 ) + V_12 [ 3 ] ;
F_2 ( V_22 , V_15 ) ;
V_12 += 4 ;
V_13 -= 4 ;
}
V_5 = F_3 ( V_8 ) ;
V_5 = F_4 ( V_5 , V_9 , V_10 , 0 ) ;
F_2 ( V_8 , V_5 ) ;
F_7 ( & V_2 -> V_20 , V_19 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_30 ;
T_1 V_5 ;
F_12 ( V_2 ) ;
F_14 ( V_2 ) ;
F_8 ( V_2 ) ;
for ( V_30 = 0 ; V_30 < V_2 -> V_31 ; V_30 ++ ) {
V_5 = F_9 ( V_58 ) ;
if ( F_16 ( V_5 , V_59 , V_60 ) == 1 )
break;
F_18 ( 1 ) ;
}
return 0 ;
}
static enum V_61 F_28 ( T_1 V_62 )
{
switch ( V_62 ) {
case V_63 :
return V_64 ;
case V_65 :
return V_66 ;
case V_67 :
return V_68 ;
case V_69 :
return V_70 ;
case V_71 :
return V_72 ;
case V_73 :
case V_74 :
return V_75 ;
case V_76 :
return V_77 ;
case V_78 :
return V_79 ;
default:
F_20 ( L_5 ) ;
return V_80 ;
}
}
static T_1 F_29 ( T_1 V_62 )
{
switch ( V_62 ) {
case V_64 :
return V_81 ;
case V_66 :
return V_82 ;
case V_68 :
return V_83 ;
case V_70 :
return V_84 ;
case V_72 :
return V_85 ;
case V_75 :
return V_86 | V_87 ;
case V_77 :
return V_86 ;
case V_79 :
return V_88 ;
default:
F_20 ( L_5 ) ;
return 0 ;
}
}
static int F_30 ( struct V_1 * V_2 ,
T_1 V_62 ,
struct V_89 * V_90 )
{
enum V_61 V_91 = F_28 ( V_62 ) ;
struct V_92 * V_93 = & V_2 -> V_94 . V_93 [ V_91 ] ;
const struct V_95 * V_47 = NULL ;
T_4 V_96 ;
T_1 V_97 ;
if ( V_93 -> V_44 == NULL )
return - V_6 ;
V_96 = V_93 -> V_98 ;
V_47 = ( const struct V_95 * ) V_93 -> V_44 -> V_15 ;
V_97 = F_26 ( V_47 -> V_47 . V_50 ) ;
V_90 -> V_99 = ( V_100 ) F_26 ( V_47 -> V_47 . V_49 ) ;
V_90 -> V_91 = ( V_100 ) V_62 ;
V_90 -> V_101 = F_31 ( V_96 ) ;
V_90 -> V_102 = F_32 ( V_96 ) ;
V_90 -> V_103 = 0 ;
V_90 -> V_104 = 0 ;
V_90 -> V_105 = V_97 ;
V_90 -> V_106 = 0 ;
V_90 -> V_19 = 0 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_107 * V_108 = (struct V_107 * ) V_2 -> V_109 . V_110 ;
struct V_111 * V_112 ;
T_1 V_113 ;
V_112 = (struct V_111 * ) V_108 -> V_47 ;
V_112 -> V_114 = 0 ;
V_112 -> V_115 = 1 ;
if ( ! V_2 -> V_94 . V_116 )
return 0 ;
if ( F_30 ( V_2 , V_78 ,
& V_112 -> V_90 [ V_112 -> V_114 ++ ] ) ) {
F_20 ( L_6 ) ;
return - V_6 ;
}
if ( F_30 ( V_2 , V_67 ,
& V_112 -> V_90 [ V_112 -> V_114 ++ ] ) ) {
F_20 ( L_7 ) ;
return - V_6 ;
}
if ( F_30 ( V_2 , V_69 ,
& V_112 -> V_90 [ V_112 -> V_114 ++ ] ) ) {
F_20 ( L_8 ) ;
return - V_6 ;
}
if ( F_30 ( V_2 , V_71 ,
& V_112 -> V_90 [ V_112 -> V_114 ++ ] ) ) {
F_20 ( L_9 ) ;
return - V_6 ;
}
if ( F_30 ( V_2 , V_73 ,
& V_112 -> V_90 [ V_112 -> V_114 ++ ] ) ) {
F_20 ( L_10 ) ;
return - V_6 ;
}
if ( F_30 ( V_2 , V_74 ,
& V_112 -> V_90 [ V_112 -> V_114 ++ ] ) ) {
F_20 ( L_11 ) ;
return - V_6 ;
}
if ( F_30 ( V_2 , V_63 ,
& V_112 -> V_90 [ V_112 -> V_114 ++ ] ) ) {
F_20 ( L_12 ) ;
return - V_6 ;
}
if ( F_30 ( V_2 , V_65 ,
& V_112 -> V_90 [ V_112 -> V_114 ++ ] ) ) {
F_20 ( L_13 ) ;
return - V_6 ;
}
F_22 ( V_2 , V_117 , V_108 -> V_118 ) ;
F_22 ( V_2 , V_119 , V_108 -> V_120 ) ;
V_113 = V_88 |
V_81 |
V_82 |
V_83 |
V_85 |
V_84 |
V_86 |
V_87 ;
if ( F_23 ( V_2 , V_121 , V_113 ) ) {
F_20 ( L_14 ) ;
return - V_6 ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
T_1 V_62 )
{
T_1 V_122 = F_29 ( V_62 ) ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_2 -> V_31 ; V_30 ++ ) {
if ( V_122 == ( F_9 ( V_123 ) & V_122 ) )
break;
F_18 ( 1 ) ;
}
if ( V_30 == V_2 -> V_31 ) {
F_20 ( L_15 ) ;
return - V_6 ;
}
return 0 ;
}
int F_35 ( struct V_1 * V_2 )
{
int V_17 ;
V_17 = F_24 ( V_2 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_27 ( V_2 ) ;
if ( V_17 )
return V_17 ;
return F_33 ( V_2 ) ;
}
int F_36 ( struct V_1 * V_2 )
{
struct V_107 * V_108 ;
T_1 V_124 = ( ( sizeof( struct V_111 ) / 4096 ) + 1 ) * 4096 ;
struct V_125 * * V_126 = & V_2 -> V_109 . V_126 ;
T_4 V_98 ;
void * V_127 ;
int V_128 ;
V_108 = F_37 ( sizeof( struct V_107 ) , V_129 ) ;
if ( NULL == V_108 )
return - V_130 ;
if ( V_2 -> V_94 . V_116 )
F_38 ( V_2 ) ;
V_2 -> V_109 . V_110 = V_108 ;
V_2 -> V_109 . V_131 = 0 ;
V_128 = F_39 ( V_2 , V_124 , V_132 ,
true , V_133 ,
V_134 ,
NULL , NULL , V_126 ) ;
if ( V_128 ) {
F_20 ( L_16 ) ;
return - V_130 ;
}
V_128 = F_40 ( V_2 -> V_109 . V_126 , false ) ;
if ( V_128 ) {
F_41 ( & V_2 -> V_109 . V_126 ) ;
F_20 ( L_17 ) ;
return - V_6 ;
}
V_128 = F_42 ( V_2 -> V_109 . V_126 , V_133 , & V_98 ) ;
if ( V_128 ) {
F_43 ( V_2 -> V_109 . V_126 ) ;
F_41 ( & V_2 -> V_109 . V_126 ) ;
F_20 ( L_18 ) ;
return - V_6 ;
}
V_128 = F_44 ( * V_126 , & V_127 ) ;
if ( V_128 ) {
F_43 ( V_2 -> V_109 . V_126 ) ;
F_41 ( & V_2 -> V_109 . V_126 ) ;
F_20 ( L_19 ) ;
return - V_6 ;
}
F_43 ( V_2 -> V_109 . V_126 ) ;
V_108 -> V_120 = F_32 ( V_98 ) ;
V_108 -> V_118 = F_31 ( V_98 ) ;
V_108 -> V_47 = V_127 ;
V_2 -> V_109 . V_135 = & V_136 ;
return 0 ;
}
int F_45 ( struct V_1 * V_2 )
{
F_41 ( & V_2 -> V_109 . V_126 ) ;
F_46 ( V_2 -> V_109 . V_110 ) ;
V_2 -> V_109 . V_110 = NULL ;
if ( V_2 -> V_94 . V_137 )
F_47 ( V_2 ) ;
return 0 ;
}
