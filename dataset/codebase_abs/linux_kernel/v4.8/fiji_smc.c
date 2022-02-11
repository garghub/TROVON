static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
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
static int F_5 ( struct V_1 * V_2 , T_1 V_11 , const T_2 * V_12 , T_1 V_13 , T_1 V_4 )
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
static int F_8 ( struct V_1 * V_2 )
{
static unsigned char V_15 [] = { 0xE0 , 0x00 , 0x80 , 0x40 } ;
F_5 ( V_2 , 0x0 , V_15 , 4 , sizeof( V_15 ) + 1 ) ;
return 0 ;
}
static bool F_9 ( struct V_1 * V_2 )
{
T_1 V_5 = F_10 ( V_23 ) ;
V_5 = F_11 ( V_5 , V_24 , V_25 ) ;
return ( ( 0 == V_5 ) && ( 0x20100 <= F_10 ( V_26 ) ) ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_27 ;
T_1 V_5 ;
for ( V_27 = 0 ; V_27 < V_2 -> V_28 ; V_27 ++ ) {
V_5 = F_3 ( V_29 ) ;
if ( F_11 ( V_5 , V_30 , V_31 ) )
break;
F_13 ( 1 ) ;
}
if ( V_27 == V_2 -> V_28 )
return - V_6 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
if ( F_12 ( V_2 ) ) {
F_15 ( L_1 ) ;
return - V_6 ;
}
F_2 ( V_32 , 0x20000 ) ;
F_2 ( V_33 , V_34 ) ;
if ( F_12 ( V_2 ) ) {
F_15 ( L_2 ) ;
return - V_6 ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , T_3 V_35 )
{
if ( ! F_9 ( V_2 ) )
{
return - V_6 ;
}
if ( F_12 ( V_2 ) ) {
F_15 ( L_1 ) ;
return - V_6 ;
}
F_2 ( V_33 , V_35 ) ;
if ( F_12 ( V_2 ) ) {
F_15 ( L_2 ) ;
return - V_6 ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
T_3 V_35 )
{
if ( F_12 ( V_2 ) ) {
F_15 ( L_1 ) ;
return - V_6 ;
}
F_2 ( V_33 , V_35 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
T_3 V_35 ,
T_1 V_36 )
{
if ( ! F_9 ( V_2 ) )
return - V_6 ;
if ( F_12 ( V_2 ) ) {
F_15 ( L_1 ) ;
return - V_6 ;
}
F_2 ( V_32 , V_36 ) ;
return F_16 ( V_2 , V_35 ) ;
}
static int F_19 (
struct V_1 * V_2 ,
T_3 V_35 , T_1 V_36 )
{
if ( F_12 ( V_2 ) ) {
F_15 ( L_1 ) ;
return - V_6 ;
}
F_2 ( V_32 , V_36 ) ;
return F_17 ( V_2 , V_35 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
const struct V_37 * V_38 ;
T_1 V_39 ;
T_1 V_40 ;
const T_2 * V_12 ;
T_1 V_5 ;
T_1 V_13 ;
T_1 * V_15 ;
unsigned long V_19 ;
if ( ! V_2 -> V_41 . V_42 )
return - V_6 ;
if ( V_2 -> V_43 . V_44 )
return 0 ;
V_38 = ( const struct V_37 * ) V_2 -> V_41 . V_42 -> V_15 ;
F_21 ( & V_38 -> V_45 ) ;
V_2 -> V_41 . V_46 = F_22 ( V_38 -> V_45 . V_47 ) ;
V_39 = F_22 ( V_38 -> V_45 . V_48 ) ;
V_40 = F_22 ( V_38 -> V_49 ) ;
V_12 = ( const T_2 * )
( V_2 -> V_41 . V_42 -> V_15 + F_22 ( V_38 -> V_45 . V_50 ) ) ;
if ( V_39 & 3 ) {
F_15 ( L_3 ) ;
return - V_6 ;
}
if ( V_39 > V_51 ) {
F_15 ( L_4 ) ;
return - V_6 ;
}
F_6 ( & V_2 -> V_20 , V_19 ) ;
F_2 ( V_7 , V_40 ) ;
V_5 = F_3 ( V_8 ) ;
V_5 = F_4 ( V_5 , V_9 , V_10 , 1 ) ;
F_2 ( V_8 , V_5 ) ;
V_13 = V_39 ;
V_15 = ( T_1 * ) V_12 ;
for (; V_13 >= 4 ; V_15 ++ , V_13 -= 4 )
F_2 ( V_22 , V_15 [ 0 ] ) ;
V_5 = F_3 ( V_8 ) ;
V_5 = F_4 ( V_5 , V_9 , V_10 , 0 ) ;
F_2 ( V_8 , V_5 ) ;
F_7 ( & V_2 -> V_20 , V_19 ) ;
return 0 ;
}
static enum V_52 F_23 ( T_1 V_53 )
{
switch ( V_53 ) {
case V_54 :
return V_55 ;
case V_56 :
return V_57 ;
case V_58 :
return V_59 ;
case V_60 :
return V_61 ;
case V_62 :
return V_63 ;
case V_64 :
case V_65 :
case V_66 :
return V_67 ;
case V_68 :
return V_69 ;
default:
F_15 ( L_5 ) ;
return V_70 ;
}
}
static int F_24 ( struct V_1 * V_2 ,
T_1 V_53 ,
struct V_71 * V_72 )
{
enum V_52 V_73 = F_23 ( V_53 ) ;
struct V_74 * V_75 = & V_2 -> V_76 . V_75 [ V_73 ] ;
const struct V_77 * V_45 = NULL ;
T_4 V_78 ;
T_1 V_79 ;
if ( V_75 -> V_42 == NULL )
return - V_6 ;
V_78 = V_75 -> V_80 ;
V_45 = ( const struct V_77 * ) V_75 -> V_42 -> V_15 ;
V_79 = F_22 ( V_45 -> V_45 . V_48 ) ;
if ( ( V_53 == V_65 ) ||
( V_53 == V_66 ) ) {
V_78 += F_22 ( V_45 -> V_81 ) << 2 ;
V_79 = F_22 ( V_45 -> V_82 ) << 2 ;
}
V_72 -> V_83 = ( V_84 ) F_22 ( V_45 -> V_45 . V_47 ) ;
V_72 -> V_73 = ( V_84 ) V_53 ;
V_72 -> V_85 = F_25 ( V_78 ) ;
V_72 -> V_86 = F_26 ( V_78 ) ;
V_72 -> V_87 = 0 ;
V_72 -> V_88 = 0 ;
V_72 -> V_89 = V_79 ;
V_72 -> V_90 = 0 ;
if ( V_53 == V_68 )
V_72 -> V_19 = 1 ;
else
V_72 -> V_19 = 0 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_91 * V_92 = (struct V_91 * ) V_2 -> V_93 . V_94 ;
struct V_95 * V_96 ;
T_1 V_97 ;
F_28 ( V_98 , 0 ) ;
F_18 ( V_2 , V_99 , V_92 -> V_100 ) ;
F_18 ( V_2 , V_101 , V_92 -> V_102 ) ;
V_96 = (struct V_95 * ) V_92 -> V_45 ;
V_96 -> V_103 = 0 ;
V_96 -> V_104 = 1 ;
if ( ! V_2 -> V_76 . V_105 )
return 0 ;
if ( F_24 ( V_2 , V_68 ,
& V_96 -> V_72 [ V_96 -> V_103 ++ ] ) ) {
F_15 ( L_6 ) ;
return - V_6 ;
}
if ( F_24 ( V_2 , V_58 ,
& V_96 -> V_72 [ V_96 -> V_103 ++ ] ) ) {
F_15 ( L_7 ) ;
return - V_6 ;
}
if ( F_24 ( V_2 , V_60 ,
& V_96 -> V_72 [ V_96 -> V_103 ++ ] ) ) {
F_15 ( L_8 ) ;
return - V_6 ;
}
if ( F_24 ( V_2 , V_62 ,
& V_96 -> V_72 [ V_96 -> V_103 ++ ] ) ) {
F_15 ( L_9 ) ;
return - V_6 ;
}
if ( F_24 ( V_2 , V_64 ,
& V_96 -> V_72 [ V_96 -> V_103 ++ ] ) ) {
F_15 ( L_10 ) ;
return - V_6 ;
}
if ( F_24 ( V_2 , V_65 ,
& V_96 -> V_72 [ V_96 -> V_103 ++ ] ) ) {
F_15 ( L_11 ) ;
return - V_6 ;
}
if ( F_24 ( V_2 , V_66 ,
& V_96 -> V_72 [ V_96 -> V_103 ++ ] ) ) {
F_15 ( L_12 ) ;
return - V_6 ;
}
if ( F_24 ( V_2 , V_54 ,
& V_96 -> V_72 [ V_96 -> V_103 ++ ] ) ) {
F_15 ( L_13 ) ;
return - V_6 ;
}
if ( F_24 ( V_2 , V_56 ,
& V_96 -> V_72 [ V_96 -> V_103 ++ ] ) ) {
F_15 ( L_14 ) ;
return - V_6 ;
}
F_18 ( V_2 , V_106 , V_92 -> V_107 ) ;
F_18 ( V_2 , V_108 , V_92 -> V_109 ) ;
V_97 = V_110 |
V_111 |
V_112 |
V_113 |
V_114 |
V_115 |
V_116 ;
if ( F_19 ( V_2 , V_117 , V_97 ) ) {
F_15 ( L_15 ) ;
return - V_6 ;
}
return 0 ;
}
static T_1 F_29 ( T_1 V_53 )
{
switch ( V_53 ) {
case V_55 :
return V_111 ;
case V_57 :
return V_112 ;
case V_59 :
return V_113 ;
case V_61 :
return V_115 ;
case V_63 :
return V_114 ;
case V_67 :
return V_116 ;
case V_118 :
return V_116 ;
case V_69 :
return V_110 ;
default:
F_15 ( L_5 ) ;
return 0 ;
}
}
static int F_30 ( struct V_1 * V_2 ,
T_1 V_53 )
{
T_1 V_119 = F_29 ( V_53 ) ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_2 -> V_28 ; V_27 ++ ) {
if ( V_119 == ( F_10 ( V_98 ) & V_119 ) )
break;
F_13 ( 1 ) ;
}
if ( V_27 == V_2 -> V_28 ) {
F_15 ( L_16 ) ;
return - V_6 ;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
int V_17 ;
T_1 V_5 ;
int V_27 ;
V_5 = F_10 ( V_120 ) ;
V_5 = F_4 ( V_5 , V_121 , V_122 , 1 ) ;
F_28 ( V_120 , V_5 ) ;
V_17 = F_20 ( V_2 ) ;
if ( V_17 )
return V_17 ;
F_28 ( V_123 , 0 ) ;
V_5 = F_10 ( V_23 ) ;
V_5 = F_4 ( V_5 , V_24 , V_25 , 0 ) ;
F_28 ( V_23 , V_5 ) ;
V_5 = F_10 ( V_120 ) ;
V_5 = F_4 ( V_5 , V_121 , V_122 , 0 ) ;
F_28 ( V_120 , V_5 ) ;
V_5 = F_10 ( V_124 ) ;
V_5 = F_4 ( V_5 , V_125 , V_126 , 1 ) ;
F_28 ( V_124 , V_5 ) ;
F_28 ( V_127 , 0 ) ;
for ( V_27 = 0 ; V_27 < V_2 -> V_28 ; V_27 ++ ) {
V_5 = F_10 ( V_128 ) ;
if ( F_11 ( V_5 , V_129 , V_130 ) )
break;
F_13 ( 1 ) ;
}
if ( V_27 == V_2 -> V_28 ) {
F_15 ( L_17 ) ;
return - V_6 ;
}
F_14 ( V_2 ) ;
F_32 ( L_18 ) ;
for ( V_27 = 0 ; V_27 < V_2 -> V_28 ; V_27 ++ ) {
V_5 = F_10 ( V_123 ) ;
if ( F_11 ( V_5 , V_131 , V_132 ) )
break;
F_13 ( 1 ) ;
}
if ( V_27 == V_2 -> V_28 ) {
F_15 ( L_19 ) ;
return - V_6 ;
}
V_5 = F_10 ( V_123 ) ;
if ( ! F_11 ( V_5 , V_131 , V_133 ) ) {
F_15 ( L_20 ) ;
return - V_6 ;
}
F_32 ( L_21 ) ;
for ( V_27 = 0 ; V_27 < V_2 -> V_28 ; V_27 ++ ) {
V_5 = F_10 ( V_127 ) ;
if( F_11 ( V_5 , V_134 , V_130 ) )
break;
F_13 ( 1 ) ;
}
if ( V_27 == V_2 -> V_28 ) {
F_15 ( L_22 ) ;
return - V_6 ;
}
F_32 ( L_23 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_27 , V_17 ;
T_1 V_5 ;
for ( V_27 = 0 ; V_27 < V_2 -> V_28 ; V_27 ++ ) {
V_5 = F_10 ( V_128 ) ;
V_5 = F_11 ( V_5 , V_129 , V_135 ) ;
if ( V_5 )
break;
F_13 ( 1 ) ;
}
if ( V_27 == V_2 -> V_28 ) {
F_15 ( L_24 ) ;
return - V_6 ;
}
F_28 ( V_127 , 0 ) ;
V_5 = F_10 ( V_120 ) ;
V_5 = F_4 ( V_5 , V_121 , V_122 , 1 ) ;
F_28 ( V_120 , V_5 ) ;
V_17 = F_20 ( V_2 ) ;
if ( V_17 )
return V_17 ;
F_8 ( V_2 ) ;
V_5 = F_10 ( V_23 ) ;
V_5 = F_4 ( V_5 , V_24 , V_25 , 0 ) ;
F_28 ( V_23 , V_5 ) ;
V_5 = F_10 ( V_120 ) ;
V_5 = F_4 ( V_5 , V_121 , V_122 , 0 ) ;
F_28 ( V_120 , V_5 ) ;
for ( V_27 = 0 ; V_27 < V_2 -> V_28 ; V_27 ++ ) {
V_5 = F_10 ( V_127 ) ;
if ( F_11 ( V_5 , V_134 , V_130 ) )
break;
F_13 ( 1 ) ;
}
if ( V_27 == V_2 -> V_28 ) {
F_15 ( L_25 ) ;
return - V_6 ;
}
return 0 ;
}
int F_34 ( struct V_1 * V_2 )
{
int V_17 ;
T_1 V_5 ;
if ( ! F_9 ( V_2 ) ) {
V_5 = F_10 ( V_136 ) ;
if ( ! F_11 ( V_5 , V_137 , V_138 ) ) {
F_32 ( L_26 ) ;
V_17 = F_33 ( V_2 ) ;
if ( V_17 )
return V_17 ;
} else {
F_32 ( L_27 ) ;
V_17 = F_31 ( V_2 ) ;
if ( V_17 )
return V_17 ;
}
}
return F_27 ( V_2 ) ;
}
int F_35 ( struct V_1 * V_2 )
{
struct V_91 * V_92 ;
T_1 V_139 = ( ( sizeof( struct V_95 ) / 4096 ) + 1 ) * 4096 ;
T_1 V_140 = 200 * 4096 ;
struct V_141 * * V_142 = & V_2 -> V_93 . V_142 ;
struct V_141 * * V_143 = & V_2 -> V_93 . V_143 ;
T_4 V_80 ;
void * V_144 ;
void * V_145 ;
int V_146 ;
V_92 = F_36 ( sizeof( struct V_91 ) , V_147 ) ;
if ( NULL == V_92 )
return - V_148 ;
if ( V_2 -> V_76 . V_105 )
F_37 ( V_2 ) ;
V_2 -> V_93 . V_94 = V_92 ;
V_2 -> V_93 . V_149 = 0 ;
V_146 = F_38 ( V_2 , V_139 , V_150 ,
true , V_151 ,
V_152 ,
NULL , NULL , V_142 ) ;
if ( V_146 ) {
F_15 ( L_28 ) ;
return - V_148 ;
}
V_146 = F_38 ( V_2 , V_140 , V_150 ,
true , V_151 ,
V_152 ,
NULL , NULL , V_143 ) ;
if ( V_146 ) {
F_15 ( L_29 ) ;
return - V_148 ;
}
V_146 = F_39 ( V_2 -> V_93 . V_142 , false ) ;
if ( V_146 ) {
F_40 ( & V_2 -> V_93 . V_142 ) ;
F_15 ( L_30 ) ;
return - V_6 ;
}
V_146 = F_41 ( V_2 -> V_93 . V_142 , V_151 , & V_80 ) ;
if ( V_146 ) {
F_42 ( V_2 -> V_93 . V_142 ) ;
F_40 ( & V_2 -> V_93 . V_142 ) ;
F_15 ( L_31 ) ;
return - V_6 ;
}
V_146 = F_43 ( * V_142 , & V_144 ) ;
if ( V_146 ) {
F_42 ( V_2 -> V_93 . V_142 ) ;
F_40 ( & V_2 -> V_93 . V_142 ) ;
F_15 ( L_32 ) ;
return - V_6 ;
}
F_42 ( V_2 -> V_93 . V_142 ) ;
V_92 -> V_109 = F_26 ( V_80 ) ;
V_92 -> V_107 = F_25 ( V_80 ) ;
V_92 -> V_45 = V_144 ;
V_146 = F_39 ( V_2 -> V_93 . V_143 , false ) ;
if ( V_146 ) {
F_40 ( & V_2 -> V_93 . V_143 ) ;
F_40 ( & V_2 -> V_93 . V_142 ) ;
F_15 ( L_33 ) ;
return - V_6 ;
}
V_146 = F_41 ( V_2 -> V_93 . V_143 , V_151 , & V_80 ) ;
if ( V_146 ) {
F_42 ( V_2 -> V_93 . V_143 ) ;
F_40 ( & V_2 -> V_93 . V_143 ) ;
F_40 ( & V_2 -> V_93 . V_142 ) ;
F_15 ( L_34 ) ;
return - V_6 ;
}
V_146 = F_43 ( * V_143 , & V_145 ) ;
if ( V_146 ) {
F_42 ( V_2 -> V_93 . V_143 ) ;
F_40 ( & V_2 -> V_93 . V_143 ) ;
F_40 ( & V_2 -> V_93 . V_142 ) ;
F_15 ( L_35 ) ;
return - V_6 ;
}
F_42 ( V_2 -> V_93 . V_143 ) ;
V_92 -> V_102 = F_26 ( V_80 ) ;
V_92 -> V_100 = F_25 ( V_80 ) ;
V_2 -> V_93 . V_153 = & V_154 ;
return 0 ;
}
int F_44 ( struct V_1 * V_2 )
{
F_40 ( & V_2 -> V_93 . V_142 ) ;
F_40 ( & V_2 -> V_93 . V_143 ) ;
F_45 ( V_2 -> V_93 . V_94 ) ;
V_2 -> V_93 . V_94 = NULL ;
if ( V_2 -> V_76 . V_155 )
F_46 ( V_2 ) ;
return 0 ;
}
