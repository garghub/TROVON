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
return - V_6 ; ;
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
V_38 = ( const struct V_37 * ) V_2 -> V_41 . V_42 -> V_15 ;
F_21 ( & V_38 -> V_43 ) ;
V_2 -> V_41 . V_44 = F_22 ( V_38 -> V_43 . V_45 ) ;
V_39 = F_22 ( V_38 -> V_43 . V_46 ) ;
V_40 = F_22 ( V_38 -> V_47 ) ;
V_12 = ( const T_2 * )
( V_2 -> V_41 . V_42 -> V_15 + F_22 ( V_38 -> V_43 . V_48 ) ) ;
if ( V_39 & 3 ) {
F_15 ( L_3 ) ;
return - V_6 ;
}
if ( V_39 > V_49 ) {
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
static enum V_50 F_23 ( T_1 V_51 )
{
switch ( V_51 ) {
case V_52 :
return V_53 ;
case V_54 :
return V_55 ;
case V_56 :
return V_57 ;
case V_58 :
return V_59 ;
case V_60 :
return V_61 ;
case V_62 :
case V_63 :
return V_64 ;
case V_65 :
return V_66 ;
case V_67 :
return V_68 ;
default:
F_15 ( L_5 ) ;
return V_69 ;
}
}
static int F_24 ( struct V_1 * V_2 ,
T_1 V_51 ,
struct V_70 * V_71 )
{
enum V_50 V_72 = F_23 ( V_51 ) ;
struct V_73 * V_74 = & V_2 -> V_75 . V_74 [ V_72 ] ;
const struct V_76 * V_43 = NULL ;
T_4 V_77 ;
T_1 V_78 ;
if ( V_74 -> V_42 == NULL )
return - V_6 ;
V_77 = V_74 -> V_79 ;
V_43 = ( const struct V_76 * ) V_74 -> V_42 -> V_15 ;
V_78 = F_22 ( V_43 -> V_43 . V_46 ) ;
if ( ( V_51 == V_63 ) ||
( V_51 == V_65 ) ) {
V_77 += F_22 ( V_43 -> V_80 ) << 2 ;
V_78 = F_22 ( V_43 -> V_81 ) << 2 ;
}
V_71 -> V_82 = ( V_83 ) F_22 ( V_43 -> V_43 . V_45 ) ;
V_71 -> V_72 = ( V_83 ) V_51 ;
V_71 -> V_84 = F_25 ( V_77 ) ;
V_71 -> V_85 = F_26 ( V_77 ) ;
V_71 -> V_86 = 0 ;
V_71 -> V_87 = 0 ;
V_71 -> V_88 = V_78 ;
V_71 -> V_89 = 0 ;
if ( V_51 == V_67 )
V_71 -> V_19 = 1 ;
else
V_71 -> V_19 = 0 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_90 * V_91 = (struct V_90 * ) V_2 -> V_92 . V_93 ;
struct V_94 * V_95 ;
T_1 V_96 ;
F_28 ( V_97 , 0 ) ;
F_18 ( V_2 , V_98 , V_91 -> V_99 ) ;
F_18 ( V_2 , V_100 , V_91 -> V_101 ) ;
V_95 = (struct V_94 * ) V_91 -> V_43 ;
V_95 -> V_102 = 0 ;
V_95 -> V_103 = 1 ;
if ( ! V_2 -> V_75 . V_104 )
return 0 ;
if ( F_24 ( V_2 , V_67 ,
& V_95 -> V_71 [ V_95 -> V_102 ++ ] ) ) {
F_15 ( L_6 ) ;
return - V_6 ;
}
if ( F_24 ( V_2 , V_56 ,
& V_95 -> V_71 [ V_95 -> V_102 ++ ] ) ) {
F_15 ( L_7 ) ;
return - V_6 ;
}
if ( F_24 ( V_2 , V_58 ,
& V_95 -> V_71 [ V_95 -> V_102 ++ ] ) ) {
F_15 ( L_8 ) ;
return - V_6 ;
}
if ( F_24 ( V_2 , V_60 ,
& V_95 -> V_71 [ V_95 -> V_102 ++ ] ) ) {
F_15 ( L_9 ) ;
return - V_6 ;
}
if ( F_24 ( V_2 , V_62 ,
& V_95 -> V_71 [ V_95 -> V_102 ++ ] ) ) {
F_15 ( L_10 ) ;
return - V_6 ;
}
if ( F_24 ( V_2 , V_63 ,
& V_95 -> V_71 [ V_95 -> V_102 ++ ] ) ) {
F_15 ( L_11 ) ;
return - V_6 ;
}
if ( F_24 ( V_2 , V_65 ,
& V_95 -> V_71 [ V_95 -> V_102 ++ ] ) ) {
F_15 ( L_12 ) ;
return - V_6 ;
}
if ( F_24 ( V_2 , V_52 ,
& V_95 -> V_71 [ V_95 -> V_102 ++ ] ) ) {
F_15 ( L_13 ) ;
return - V_6 ;
}
if ( F_24 ( V_2 , V_54 ,
& V_95 -> V_71 [ V_95 -> V_102 ++ ] ) ) {
F_15 ( L_14 ) ;
return - V_6 ;
}
F_18 ( V_2 , V_105 , V_91 -> V_106 ) ;
F_18 ( V_2 , V_107 , V_91 -> V_108 ) ;
V_96 = V_109 |
V_110 |
V_111 |
V_112 |
V_113 |
V_114 |
V_115 ;
if ( F_19 ( V_2 , V_116 , V_96 ) ) {
F_15 ( L_15 ) ;
return - V_6 ;
}
return 0 ;
}
static T_1 F_29 ( T_1 V_51 )
{
switch ( V_51 ) {
case V_53 :
return V_110 ;
case V_55 :
return V_111 ;
case V_57 :
return V_112 ;
case V_59 :
return V_114 ;
case V_61 :
return V_113 ;
case V_64 :
return V_115 ;
case V_66 :
return V_115 ;
case V_68 :
return V_109 ;
default:
F_15 ( L_5 ) ;
return 0 ;
}
}
static int F_30 ( struct V_1 * V_2 ,
T_1 V_51 )
{
T_1 V_117 = F_29 ( V_51 ) ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_2 -> V_28 ; V_27 ++ ) {
if ( V_117 == ( F_10 ( V_97 ) & V_117 ) )
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
V_5 = F_10 ( V_118 ) ;
V_5 = F_4 ( V_5 , V_119 , V_120 , 1 ) ;
F_28 ( V_118 , V_5 ) ;
V_17 = F_20 ( V_2 ) ;
if ( V_17 )
return V_17 ;
F_28 ( V_121 , 0 ) ;
V_5 = F_10 ( V_23 ) ;
V_5 = F_4 ( V_5 , V_24 , V_25 , 0 ) ;
F_28 ( V_23 , V_5 ) ;
V_5 = F_10 ( V_118 ) ;
V_5 = F_4 ( V_5 , V_119 , V_120 , 0 ) ;
F_28 ( V_118 , V_5 ) ;
V_5 = F_10 ( V_122 ) ;
V_5 = F_4 ( V_5 , V_123 , V_124 , 1 ) ;
F_28 ( V_122 , V_5 ) ;
F_28 ( V_125 , 0 ) ;
for ( V_27 = 0 ; V_27 < V_2 -> V_28 ; V_27 ++ ) {
V_5 = F_10 ( V_126 ) ;
if ( F_11 ( V_5 , V_127 , V_128 ) )
break;
F_13 ( 1 ) ;
}
if ( V_27 == V_2 -> V_28 ) {
F_15 ( L_17 ) ;
return - V_6 ;
}
F_14 ( V_2 ) ;
for ( V_27 = 0 ; V_27 < V_2 -> V_28 ; V_27 ++ ) {
V_5 = F_10 ( V_121 ) ;
if ( F_11 ( V_5 , V_129 , V_130 ) )
break;
F_13 ( 1 ) ;
}
if ( V_27 == V_2 -> V_28 ) {
F_15 ( L_18 ) ;
return - V_6 ;
}
V_5 = F_10 ( V_121 ) ;
if ( ! F_11 ( V_5 , V_129 , V_131 ) ) {
F_15 ( L_19 ) ;
return - V_6 ;
}
for ( V_27 = 0 ; V_27 < V_2 -> V_28 ; V_27 ++ ) {
V_5 = F_10 ( V_125 ) ;
if( F_11 ( V_5 , V_132 , V_128 ) )
break;
F_13 ( 1 ) ;
}
if ( V_27 == V_2 -> V_28 ) {
F_15 ( L_20 ) ;
return - V_6 ;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_27 , V_17 ;
T_1 V_5 ;
for ( V_27 = 0 ; V_27 < V_2 -> V_28 ; V_27 ++ ) {
V_5 = F_10 ( V_126 ) ;
V_5 = F_11 ( V_5 , V_127 , V_133 ) ;
if ( V_5 )
break;
F_13 ( 1 ) ;
}
if ( V_27 == V_2 -> V_28 ) {
F_15 ( L_21 ) ;
return - V_6 ;
}
F_28 ( V_125 , 0 ) ;
V_5 = F_10 ( V_118 ) ;
V_5 = F_4 ( V_5 , V_119 , V_120 , 1 ) ;
F_28 ( V_118 , V_5 ) ;
V_17 = F_20 ( V_2 ) ;
if ( V_17 )
return V_17 ;
F_8 ( V_2 ) ;
V_5 = F_10 ( V_23 ) ;
V_5 = F_4 ( V_5 , V_24 , V_25 , 0 ) ;
F_28 ( V_23 , V_5 ) ;
V_5 = F_10 ( V_118 ) ;
V_5 = F_4 ( V_5 , V_119 , V_120 , 0 ) ;
F_28 ( V_118 , V_5 ) ;
for ( V_27 = 0 ; V_27 < V_2 -> V_28 ; V_27 ++ ) {
V_5 = F_10 ( V_125 ) ;
if ( F_11 ( V_5 , V_132 , V_128 ) )
break;
F_13 ( 1 ) ;
}
if ( V_27 == V_2 -> V_28 ) {
F_15 ( L_22 ) ;
return - V_6 ;
}
return 0 ;
}
int F_33 ( struct V_1 * V_2 )
{
int V_17 ;
T_1 V_5 ;
if ( ! F_9 ( V_2 ) ) {
V_5 = F_10 ( V_134 ) ;
if ( ! F_11 ( V_5 , V_135 , V_136 ) ) {
V_17 = F_32 ( V_2 ) ;
if ( V_17 )
return V_17 ;
} else {
V_17 = F_31 ( V_2 ) ;
if ( V_17 )
return V_17 ;
}
}
return F_27 ( V_2 ) ;
}
int F_34 ( struct V_1 * V_2 )
{
struct V_90 * V_91 ;
T_1 V_137 = ( ( sizeof( struct V_94 ) / 4096 ) + 1 ) * 4096 ;
T_1 V_138 = 200 * 4096 ;
struct V_139 * * V_140 = & V_2 -> V_92 . V_140 ;
struct V_139 * * V_141 = & V_2 -> V_92 . V_141 ;
T_4 V_79 ;
void * V_142 ;
void * V_143 ;
int V_144 ;
V_91 = F_35 ( sizeof( struct V_90 ) , V_145 ) ;
if ( NULL == V_91 )
return - V_146 ;
if ( V_2 -> V_75 . V_104 )
F_36 ( V_2 ) ;
V_2 -> V_92 . V_93 = V_91 ;
V_2 -> V_92 . V_147 = 0 ;
V_144 = F_37 ( V_2 , V_137 , V_148 ,
true , V_149 , 0 , NULL , V_140 ) ;
if ( V_144 ) {
F_15 ( L_23 ) ;
return - V_146 ;
}
V_144 = F_37 ( V_2 , V_138 , V_148 ,
true , V_149 , 0 , NULL , V_141 ) ;
if ( V_144 ) {
F_15 ( L_24 ) ;
return - V_146 ;
}
V_144 = F_38 ( V_2 -> V_92 . V_140 , false ) ;
if ( V_144 ) {
F_39 ( & V_2 -> V_92 . V_140 ) ;
F_15 ( L_25 ) ;
return - V_6 ;
}
V_144 = F_40 ( V_2 -> V_92 . V_140 , V_149 , & V_79 ) ;
if ( V_144 ) {
F_41 ( V_2 -> V_92 . V_140 ) ;
F_39 ( & V_2 -> V_92 . V_140 ) ;
F_15 ( L_26 ) ;
return - V_6 ;
}
V_144 = F_42 ( * V_140 , & V_142 ) ;
if ( V_144 ) {
F_41 ( V_2 -> V_92 . V_140 ) ;
F_39 ( & V_2 -> V_92 . V_140 ) ;
F_15 ( L_27 ) ;
return - V_6 ;
}
F_41 ( V_2 -> V_92 . V_140 ) ;
V_91 -> V_108 = F_26 ( V_79 ) ;
V_91 -> V_106 = F_25 ( V_79 ) ;
V_91 -> V_43 = V_142 ;
V_144 = F_38 ( V_2 -> V_92 . V_141 , false ) ;
if ( V_144 ) {
F_39 ( & V_2 -> V_92 . V_141 ) ;
F_39 ( & V_2 -> V_92 . V_140 ) ;
F_15 ( L_28 ) ;
return - V_6 ;
}
V_144 = F_40 ( V_2 -> V_92 . V_141 , V_149 , & V_79 ) ;
if ( V_144 ) {
F_41 ( V_2 -> V_92 . V_141 ) ;
F_39 ( & V_2 -> V_92 . V_141 ) ;
F_39 ( & V_2 -> V_92 . V_140 ) ;
F_15 ( L_29 ) ;
return - V_6 ;
}
V_144 = F_42 ( * V_141 , & V_143 ) ;
if ( V_144 ) {
F_41 ( V_2 -> V_92 . V_141 ) ;
F_39 ( & V_2 -> V_92 . V_141 ) ;
F_39 ( & V_2 -> V_92 . V_140 ) ;
F_15 ( L_30 ) ;
return - V_6 ;
}
F_41 ( V_2 -> V_92 . V_141 ) ;
V_91 -> V_101 = F_26 ( V_79 ) ;
V_91 -> V_99 = F_25 ( V_79 ) ;
V_2 -> V_92 . V_150 = & V_151 ;
return 0 ;
}
int F_43 ( struct V_1 * V_2 )
{
F_39 ( & V_2 -> V_92 . V_140 ) ;
F_39 ( & V_2 -> V_92 . V_141 ) ;
F_44 ( V_2 -> V_92 . V_93 ) ;
V_2 -> V_92 . V_93 = NULL ;
if ( V_2 -> V_75 . V_152 )
F_45 ( V_2 ) ;
return 0 ;
}
