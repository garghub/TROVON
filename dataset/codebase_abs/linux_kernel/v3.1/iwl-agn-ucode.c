static int F_1 ( struct V_1 * V_2 , const char * V_3 ,
struct V_4 * V_5 , T_1 V_6 )
{
T_2 V_7 = V_5 -> V_8 ;
T_1 V_9 = V_5 -> V_10 ;
int V_11 ;
V_2 -> V_12 = 0 ;
F_2 ( V_2 ,
F_3 ( V_13 ) ,
V_14 ) ;
F_2 ( V_2 ,
F_4 ( V_13 ) , V_6 ) ;
F_2 ( V_2 ,
F_5 ( V_13 ) ,
V_7 & V_15 ) ;
F_2 ( V_2 ,
F_6 ( V_13 ) ,
( F_7 ( V_7 )
<< V_16 ) | V_9 ) ;
F_2 ( V_2 ,
F_8 ( V_13 ) ,
1 << V_17 |
1 << V_18 |
V_19 ) ;
F_2 ( V_2 ,
F_3 ( V_13 ) ,
V_20 |
V_21 |
V_22 ) ;
F_9 ( V_2 , L_1 , V_3 ) ;
V_11 = F_10 ( V_2 -> V_23 ,
V_2 -> V_12 , 5 * V_24 ) ;
if ( V_11 == - V_25 ) {
F_11 ( V_2 , L_2
L_3 , V_3 ) ;
return V_11 ;
}
if ( ! V_11 ) {
F_11 ( V_2 , L_4 ,
V_3 ) ;
return - V_26 ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_27 * V_5 )
{
int V_11 = 0 ;
V_11 = F_1 ( V_2 , L_5 , & V_5 -> V_28 ,
V_29 ) ;
if ( V_11 )
return V_11 ;
return F_1 ( V_2 , L_6 , & V_5 -> V_30 ,
V_31 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_32 V_33 ;
T_3 * V_34 =
( T_3 * ) F_14 ( V_2 , V_35 ) ;
F_15 ( & V_33 . V_36 , V_37 ) ;
V_33 . V_38 = F_16 ( V_34 [ 0 ] ) ;
V_33 . V_39 = F_16 ( V_34 [ 1 ] ) ;
return F_17 ( & V_2 -> V_40 [ V_41 ] ,
( V_42 * ) & V_33 , sizeof( V_33 ) ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_43 V_33 ;
T_3 * V_44 =
( T_3 * ) F_14 ( V_2 , V_45 ) ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
F_15 ( & V_33 . V_36 , V_46 ) ;
memcpy ( & V_33 . V_47 , V_44 , sizeof( * V_44 ) ) ;
if ( ! ( V_33 . V_47 ) )
V_33 . V_47 = V_48 ;
F_19 ( V_2 , L_7 ,
F_16 ( V_33 . V_47 ) ) ;
return F_17 ( & V_2 -> V_40 [ V_49 ] ,
( V_42 * ) & V_33 , sizeof( V_33 ) ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_50 V_51 ;
struct V_52 V_33 = {
. V_53 = V_54 ,
. V_10 = { sizeof( struct V_50 ) , } ,
. V_30 = { & V_51 , } ,
} ;
memset ( & V_51 , 0 , sizeof( V_51 ) ) ;
V_51 . V_55 . V_56 . V_57 = V_58 ;
V_51 . V_55 . V_56 . V_59 = V_58 ;
V_51 . V_55 . V_56 . V_60 = V_58 ;
V_51 . V_55 . V_61 =
V_62 ;
return F_21 ( & V_2 -> V_63 , & V_33 ) ;
}
void F_22 ( struct V_1 * V_2 ,
struct V_64 * V_65 )
{
struct V_66 * V_67 = F_23 ( V_65 ) ;
struct V_68 * V_36 = (struct V_68 * ) V_67 -> V_69 . V_70 ;
int V_10 = F_24 ( V_67 -> V_71 ) & V_72 ;
int V_73 ;
V_10 -= 4 ;
switch ( V_36 -> V_74 ) {
case V_75 :
V_73 = V_76 ;
break;
case V_77 :
V_73 = V_78 ;
break;
case V_79 :
V_73 = V_80 ;
break;
case V_81 :
V_73 = V_82 ;
break;
case V_83 :
V_73 = V_84 ;
break;
default:
F_11 ( V_2 , L_8 ,
V_36 -> V_74 ) ;
return;
}
F_17 ( & V_2 -> V_40 [ V_73 ] , V_67 -> V_69 . V_70 , V_10 ) ;
}
int F_25 ( struct V_1 * V_2 )
{
int V_11 ;
if ( V_2 -> V_85 -> V_86 &&
V_2 -> V_85 -> V_86 -> V_87 ) {
V_11 = F_26 ( V_2 , V_88 ,
V_89 ) ;
if ( V_11 )
return V_11 ;
}
V_11 = F_20 ( V_2 ) ;
if ( V_11 )
return V_11 ;
if ( V_2 -> V_85 -> V_90 )
return F_18 ( V_2 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_91 V_92 ;
if ( V_2 -> V_85 -> V_93 -> V_94 ) {
V_92 . V_61 = V_95 ;
V_92 . V_61 |= V_96 ;
memcpy ( V_92 . V_97 , V_98 ,
sizeof( struct V_99 ) *
V_100 ) ;
V_92 . V_61 |= V_101 ;
V_92 . V_61 |= V_102 ;
} else {
memset ( & V_92 , 0 , sizeof( V_92 ) ) ;
}
return F_28 ( & V_2 -> V_63 ,
V_103 , V_104 ,
sizeof( V_92 ) , & V_92 ) ;
}
void F_29 ( struct V_1 * V_2 )
{
struct V_105 V_106 ;
memcpy ( V_106 . V_107 , V_108 ,
sizeof( V_108 ) ) ;
if ( F_28 ( & V_2 -> V_63 ,
V_109 , V_104 ,
sizeof( V_106 ) , & V_106 ) )
F_11 ( V_2 , L_9 ) ;
}
int F_26 ( struct V_1 * V_2 , V_42 V_110 , V_42 type )
{
struct V_111 V_112 ;
int V_11 ;
V_112 . V_110 = V_110 ;
V_112 . type = type ;
V_11 = F_28 ( & V_2 -> V_63 ,
V_113 , V_104 ,
sizeof( V_112 ) , & V_112 ) ;
if ( V_11 )
F_11 ( V_2 , L_10 ) ;
return V_11 ;
}
static int F_30 ( struct V_1 * V_2 )
{
int V_11 ;
F_31 ( & V_2 -> V_63 ) ;
V_11 = F_27 ( V_2 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_13 ( V_2 ) ;
if ( V_11 )
return V_11 ;
return F_32 ( V_2 ) ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_4 * V_4 )
{
T_4 * V_5 = ( T_4 * ) V_4 -> V_114 ;
T_1 V_10 = V_4 -> V_10 ;
T_1 V_115 ;
T_1 V_116 ;
F_9 ( V_2 , L_11 , V_10 ) ;
for ( V_116 = 0 ; V_116 < V_10 ; V_116 += 100 , V_5 += 100 / sizeof( T_1 ) ) {
F_2 ( V_2 , V_117 ,
V_116 + V_29 ) ;
V_115 = F_34 ( V_2 , V_118 ) ;
if ( V_115 != F_24 ( * V_5 ) )
return - V_119 ;
}
return 0 ;
}
static void F_35 ( struct V_1 * V_2 ,
struct V_4 * V_4 )
{
T_4 * V_5 = ( T_4 * ) V_4 -> V_114 ;
T_1 V_10 = V_4 -> V_10 ;
T_1 V_115 ;
T_1 V_120 ;
int V_121 = 0 ;
F_9 ( V_2 , L_11 , V_10 ) ;
F_2 ( V_2 , V_117 ,
V_29 ) ;
for ( V_120 = 0 ;
V_120 < V_10 && V_121 < 20 ;
V_120 += sizeof( T_1 ) , V_5 ++ ) {
V_115 = F_34 ( V_2 , V_118 ) ;
if ( V_115 != F_24 ( * V_5 ) ) {
F_11 ( V_2 , L_12
L_13 ,
V_120 , V_115 , F_24 ( * V_5 ) ) ;
V_121 ++ ;
}
}
}
static int F_36 ( struct V_1 * V_2 , struct V_27 * V_122 )
{
if ( ! F_33 ( V_2 , & V_122 -> V_28 ) ) {
F_9 ( V_2 , L_14 ) ;
return 0 ;
}
F_11 ( V_2 , L_15 ) ;
F_35 ( V_2 , & V_122 -> V_28 ) ;
return - V_119 ;
}
static void F_37 ( struct V_1 * V_2 ,
struct V_66 * V_67 ,
void * V_30 )
{
struct V_123 * V_124 = V_30 ;
struct V_125 * V_126 ;
V_126 = & V_67 -> V_69 . V_127 ;
F_9 ( V_2 , L_16
L_17 ,
V_126 -> V_128 , V_126 -> V_129 ,
V_126 -> V_130 ) ;
V_2 -> V_131 . V_132 =
F_24 ( V_126 -> V_133 ) ;
V_2 -> V_131 . V_134 =
F_24 ( V_126 -> V_135 ) ;
V_124 -> V_136 = V_126 -> V_130 ;
V_124 -> V_137 = V_126 -> V_128 == V_138 ;
}
int F_38 ( struct V_1 * V_2 ,
struct V_27 * V_5 ,
enum V_139 V_140 )
{
struct V_141 V_142 ;
struct V_123 V_124 ;
int V_11 ;
enum V_139 V_143 ;
V_11 = F_39 ( & V_2 -> V_63 ) ;
if ( V_11 )
return V_11 ;
F_40 ( V_2 , & V_142 , V_144 ,
F_37 , & V_124 ) ;
V_143 = V_2 -> V_140 ;
V_2 -> V_140 = V_140 ;
V_11 = F_12 ( V_2 , V_5 ) ;
if ( V_11 ) {
V_2 -> V_140 = V_143 ;
F_41 ( V_2 , & V_142 ) ;
return V_11 ;
}
F_42 ( & V_2 -> V_63 ) ;
V_11 = F_43 ( V_2 , & V_142 , V_145 ) ;
if ( V_11 ) {
V_2 -> V_140 = V_143 ;
return V_11 ;
}
if ( ! V_124 . V_137 ) {
F_11 ( V_2 , L_18 ) ;
V_2 -> V_140 = V_143 ;
return - V_119 ;
}
if ( V_140 != V_146 ) {
V_11 = F_36 ( V_2 , V_5 ) ;
if ( V_11 ) {
V_2 -> V_140 = V_143 ;
return V_11 ;
}
F_44 ( 5 ) ;
}
V_11 = F_30 ( V_2 ) ;
if ( V_11 ) {
F_45 ( V_2 ,
L_19 , V_11 ) ;
V_2 -> V_140 = V_143 ;
return V_11 ;
}
return 0 ;
}
int F_46 ( struct V_1 * V_2 )
{
struct V_141 V_147 ;
int V_11 ;
F_47 ( & V_2 -> V_148 ) ;
if ( ! V_2 -> V_149 . V_28 . V_10 )
return 0 ;
if ( V_2 -> V_140 != V_150 )
return 0 ;
F_40 ( V_2 , & V_147 ,
V_151 ,
NULL , NULL ) ;
V_11 = F_38 ( V_2 , & V_2 -> V_149 ,
V_152 ) ;
if ( V_11 )
goto error;
V_11 = F_25 ( V_2 ) ;
if ( V_11 )
goto error;
V_11 = F_43 ( V_2 , & V_147 , V_153 ) ;
goto V_154;
error:
F_41 ( V_2 , & V_147 ) ;
V_154:
F_48 ( & V_2 -> V_63 ) ;
return V_11 ;
}
