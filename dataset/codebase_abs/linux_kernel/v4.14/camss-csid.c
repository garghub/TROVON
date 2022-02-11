static const struct V_1 * F_1 ( T_1 V_2 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ )
if ( V_2 == V_4 [ V_3 ] . V_2 )
return & V_4 [ V_3 ] ;
F_3 ( 1 , L_1 ) ;
return & V_4 [ 0 ] ;
}
static T_2 F_4 ( int V_5 , void * V_6 )
{
struct V_7 * V_8 = V_6 ;
T_1 V_9 ;
V_9 = F_5 ( V_8 -> V_10 + V_11 ) ;
F_6 ( V_9 , V_8 -> V_10 + V_12 ) ;
if ( ( V_9 >> 11 ) & 0x1 )
F_7 ( & V_8 -> V_13 ) ;
return V_14 ;
}
static int F_8 ( struct V_7 * V_8 )
{
struct V_15 * V_6 = F_9 ( V_8 , V_8 -> V_16 ) ;
T_1 V_17 ;
int V_3 , V_18 ;
int V_19 ;
V_19 = F_10 ( & V_8 -> V_20 . V_21 , & V_17 ) ;
if ( V_19 )
V_17 = 0 ;
for ( V_3 = 0 ; V_3 < V_8 -> V_22 ; V_3 ++ ) {
struct V_23 * clock = & V_8 -> clock [ V_3 ] ;
if ( ! strcmp ( clock -> V_24 , L_2 ) ||
! strcmp ( clock -> V_24 , L_3 ) ) {
T_3 V_25 = F_1 (
V_8 -> V_26 [ V_27 ] . V_2 ) -> V_25 ;
T_3 V_28 = V_8 -> V_29 . V_30 ;
T_4 V_31 = V_17 * V_25 / ( 2 * V_28 * 4 ) ;
long V_32 ;
F_11 ( & V_31 ) ;
for ( V_18 = 0 ; V_18 < clock -> V_33 ; V_18 ++ )
if ( V_31 < clock -> V_34 [ V_18 ] )
break;
if ( V_18 == clock -> V_33 ) {
F_12 ( V_6 ,
L_4 ) ;
return - V_35 ;
}
if ( V_31 == 0 )
V_18 = clock -> V_33 - 1 ;
V_32 = F_13 ( clock -> V_36 , clock -> V_34 [ V_18 ] ) ;
if ( V_32 < 0 ) {
F_12 ( V_6 , L_5 ,
V_32 ) ;
return - V_35 ;
}
V_19 = F_14 ( clock -> V_36 , V_32 ) ;
if ( V_19 < 0 ) {
F_12 ( V_6 , L_6 , V_19 ) ;
return V_19 ;
}
}
}
return 0 ;
}
static int F_15 ( struct V_7 * V_8 )
{
unsigned long time ;
F_16 ( & V_8 -> V_13 ) ;
F_6 ( 0x7fff , V_8 -> V_10 + V_37 ) ;
time = F_17 ( & V_8 -> V_13 ,
F_18 ( V_38 ) ) ;
if ( ! time ) {
F_12 ( F_9 ( V_8 , V_8 -> V_16 ) ,
L_7 ) ;
return - V_39 ;
}
return 0 ;
}
static int F_19 ( struct V_40 * V_41 , int V_42 )
{
struct V_7 * V_8 = F_20 ( V_41 ) ;
struct V_15 * V_6 = F_9 ( V_8 , V_8 -> V_16 ) ;
int V_19 ;
if ( V_42 ) {
T_1 V_43 ;
V_19 = F_21 ( V_8 -> V_44 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_8 ( V_8 ) ;
if ( V_19 < 0 ) {
F_22 ( V_8 -> V_44 ) ;
return V_19 ;
}
V_19 = F_23 ( V_8 -> V_22 , V_8 -> clock , V_6 ) ;
if ( V_19 < 0 ) {
F_22 ( V_8 -> V_44 ) ;
return V_19 ;
}
F_24 ( V_8 -> V_5 ) ;
V_19 = F_15 ( V_8 ) ;
if ( V_19 < 0 ) {
F_25 ( V_8 -> V_5 ) ;
F_26 ( V_8 -> V_22 , V_8 -> clock ) ;
F_22 ( V_8 -> V_44 ) ;
return V_19 ;
}
V_43 = F_5 ( V_8 -> V_10 + V_45 ) ;
F_27 ( V_6 , L_8 , V_43 ) ;
} else {
F_25 ( V_8 -> V_5 ) ;
F_26 ( V_8 -> V_22 , V_8 -> clock ) ;
V_19 = F_22 ( V_8 -> V_44 ) ;
}
return V_19 ;
}
static int F_28 ( struct V_40 * V_41 , int V_46 )
{
struct V_7 * V_8 = F_20 ( V_41 ) ;
struct V_47 * V_48 = & V_8 -> V_49 ;
T_1 V_50 ;
if ( V_46 ) {
T_3 V_51 = 0 ;
T_3 V_52 = V_51 * 4 ;
T_3 V_53 , V_54 , V_55 ;
int V_19 ;
V_19 = F_29 ( & V_8 -> V_56 ) ;
if ( V_19 < 0 ) {
F_12 ( F_9 ( V_8 , V_8 -> V_16 ) ,
L_9 , V_19 ) ;
return V_19 ;
}
if ( ! V_48 -> V_57 &&
! F_30 ( & V_8 -> V_58 [ V_59 ] ) )
return - V_60 ;
V_53 = F_1 ( V_8 -> V_26 [ V_61 ] . V_2 ) ->
V_62 ;
if ( V_48 -> V_57 ) {
struct V_63 * V_64 =
& V_8 -> V_26 [ V_61 ] ;
T_3 V_25 = F_1 ( V_64 -> V_2 ) -> V_25 ;
T_3 V_65 = F_1 ( V_64 -> V_2 ) -> V_65 ;
T_1 V_66 = V_64 -> V_67 * V_25 * V_65 / 8 ;
T_1 V_68 = V_64 -> V_69 ;
V_50 = ( ( V_70 & 0xff ) << 24 ) |
( ( V_71 & 0x7ff ) << 13 ) ;
F_6 ( V_50 , V_8 -> V_10 + V_72 ) ;
V_50 = ( ( V_66 & 0x1fff ) << 16 ) |
( V_68 & 0x1fff ) ;
F_6 ( V_50 , V_8 -> V_10 +
F_31 ( 0 ) ) ;
V_50 = V_53 ;
F_6 ( V_50 , V_8 -> V_10 +
F_32 ( 0 ) ) ;
V_50 = V_48 -> V_73 ;
F_6 ( V_50 , V_8 -> V_10 +
F_33 ( 0 ) ) ;
} else {
struct V_74 * V_29 = & V_8 -> V_29 ;
V_50 = V_29 -> V_30 - 1 ;
V_50 |= V_29 -> V_75 << 4 ;
F_6 ( V_50 ,
V_8 -> V_10 + V_76 ) ;
V_50 = V_29 -> V_77 << 17 ;
V_50 |= 0x9 ;
F_6 ( V_50 ,
V_8 -> V_10 + V_78 ) ;
}
V_54 = ( V_52 % 4 ) * 8 ;
V_55 = F_1 ( V_8 -> V_26 [ V_59 ] . V_2 ) ->
V_79 ;
V_50 = F_5 ( V_8 -> V_10 + F_34 ( V_51 ) ) ;
V_50 &= ~ ( 0xff << V_54 ) ;
V_50 |= V_53 << V_54 ;
F_6 ( V_50 , V_8 -> V_10 + F_34 ( V_51 ) ) ;
V_50 = ( V_55 << 4 ) | 0x3 ;
F_6 ( V_50 , V_8 -> V_10 + F_35 ( V_52 ) ) ;
if ( V_48 -> V_57 ) {
V_50 = V_80 ;
F_6 ( V_50 , V_8 -> V_10 + V_81 ) ;
}
} else {
if ( V_48 -> V_57 ) {
V_50 = V_82 ;
F_6 ( V_50 , V_8 -> V_10 + V_81 ) ;
}
}
return 0 ;
}
static struct V_63 *
F_36 ( struct V_7 * V_8 ,
struct V_83 * V_84 ,
unsigned int V_85 ,
enum V_86 V_87 )
{
if ( V_87 == V_88 )
return F_37 ( & V_8 -> V_20 , V_84 , V_85 ) ;
return & V_8 -> V_26 [ V_85 ] ;
}
static void F_38 ( struct V_7 * V_8 ,
struct V_83 * V_84 ,
unsigned int V_85 ,
struct V_63 * V_26 ,
enum V_86 V_87 )
{
unsigned int V_3 ;
switch ( V_85 ) {
case V_59 :
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ )
if ( V_26 -> V_2 == V_4 [ V_3 ] . V_2 )
break;
if ( V_3 >= F_2 ( V_4 ) )
V_26 -> V_2 = V_89 ;
V_26 -> V_67 = F_39 ( T_1 , V_26 -> V_67 , 1 , 8191 ) ;
V_26 -> V_69 = F_39 ( T_1 , V_26 -> V_69 , 1 , 8191 ) ;
V_26 -> V_90 = V_91 ;
V_26 -> V_92 = V_93 ;
break;
case V_61 :
if ( V_8 -> V_94 -> V_95 . V_50 == 0 ) {
struct V_63 V_96 ;
V_96 = * F_36 ( V_8 , V_84 ,
V_59 , V_87 ) ;
* V_26 = V_96 ;
} else {
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ )
if ( V_4 [ V_3 ] . V_2 == V_26 -> V_2 )
break;
if ( V_3 >= F_2 ( V_4 ) )
V_26 -> V_2 = V_89 ;
V_26 -> V_67 = F_39 ( T_1 , V_26 -> V_67 , 1 , 8191 ) ;
V_26 -> V_69 = F_39 ( T_1 , V_26 -> V_69 , 1 , 8191 ) ;
V_26 -> V_90 = V_91 ;
}
break;
}
V_26 -> V_92 = V_93 ;
}
static int F_40 ( struct V_40 * V_41 ,
struct V_83 * V_84 ,
struct V_97 * V_2 )
{
struct V_7 * V_8 = F_20 ( V_41 ) ;
struct V_63 * V_96 ;
if ( V_2 -> V_85 == V_59 ) {
if ( V_2 -> V_98 >= F_2 ( V_4 ) )
return - V_35 ;
V_2 -> V_2 = V_4 [ V_2 -> V_98 ] . V_2 ;
} else {
if ( V_8 -> V_94 -> V_95 . V_50 == 0 ) {
if ( V_2 -> V_98 > 0 )
return - V_35 ;
V_96 = F_36 ( V_8 , V_84 , V_59 ,
V_2 -> V_87 ) ;
V_2 -> V_2 = V_96 -> V_2 ;
} else {
if ( V_2 -> V_98 >= F_2 ( V_4 ) )
return - V_35 ;
V_2 -> V_2 = V_4 [ V_2 -> V_98 ] . V_2 ;
}
}
return 0 ;
}
static int F_41 ( struct V_40 * V_41 ,
struct V_83 * V_84 ,
struct V_99 * V_100 )
{
struct V_7 * V_8 = F_20 ( V_41 ) ;
struct V_63 V_96 ;
if ( V_100 -> V_98 != 0 )
return - V_35 ;
V_96 . V_2 = V_100 -> V_2 ;
V_96 . V_67 = 1 ;
V_96 . V_69 = 1 ;
F_38 ( V_8 , V_84 , V_100 -> V_85 , & V_96 , V_100 -> V_87 ) ;
V_100 -> V_101 = V_96 . V_67 ;
V_100 -> V_102 = V_96 . V_69 ;
if ( V_96 . V_2 != V_100 -> V_2 )
return - V_35 ;
V_96 . V_2 = V_100 -> V_2 ;
V_96 . V_67 = - 1 ;
V_96 . V_69 = - 1 ;
F_38 ( V_8 , V_84 , V_100 -> V_85 , & V_96 , V_100 -> V_87 ) ;
V_100 -> V_103 = V_96 . V_67 ;
V_100 -> V_104 = V_96 . V_69 ;
return 0 ;
}
static int F_42 ( struct V_40 * V_41 ,
struct V_83 * V_84 ,
struct V_105 * V_26 )
{
struct V_7 * V_8 = F_20 ( V_41 ) ;
struct V_63 * V_96 ;
V_96 = F_36 ( V_8 , V_84 , V_26 -> V_85 , V_26 -> V_87 ) ;
if ( V_96 == NULL )
return - V_35 ;
V_26 -> V_96 = * V_96 ;
return 0 ;
}
static int F_43 ( struct V_40 * V_41 ,
struct V_83 * V_84 ,
struct V_105 * V_26 )
{
struct V_7 * V_8 = F_20 ( V_41 ) ;
struct V_63 * V_96 ;
V_96 = F_36 ( V_8 , V_84 , V_26 -> V_85 , V_26 -> V_87 ) ;
if ( V_96 == NULL )
return - V_35 ;
F_38 ( V_8 , V_84 , V_26 -> V_85 , & V_26 -> V_96 , V_26 -> V_87 ) ;
* V_96 = V_26 -> V_96 ;
if ( V_26 -> V_85 == V_59 ) {
V_96 = F_36 ( V_8 , V_84 , V_61 ,
V_26 -> V_87 ) ;
* V_96 = V_26 -> V_96 ;
F_38 ( V_8 , V_84 , V_61 , V_96 ,
V_26 -> V_87 ) ;
}
return 0 ;
}
static int F_44 ( struct V_40 * V_41 , struct V_106 * V_107 )
{
struct V_105 V_96 = {
. V_85 = V_59 ,
. V_87 = V_107 ? V_88 :
V_108 ,
. V_96 = {
. V_2 = V_89 ,
. V_67 = 1920 ,
. V_69 = 1080
}
} ;
return F_43 ( V_41 , V_107 ? V_107 -> V_85 : NULL , & V_96 ) ;
}
static int F_45 ( struct V_7 * V_8 , T_5 V_9 )
{
struct V_47 * V_48 = & V_8 -> V_49 ;
if ( V_9 && F_30 ( & V_8 -> V_58 [ V_59 ] ) )
return - V_109 ;
V_48 -> V_57 = ! ! V_9 ;
switch ( V_9 ) {
case 1 :
V_48 -> V_73 = V_110 ;
break;
case 2 :
V_48 -> V_73 = V_111 ;
break;
case 3 :
V_48 -> V_73 = V_112 ;
break;
case 4 :
V_48 -> V_73 = V_113 ;
break;
case 5 :
V_48 -> V_73 = V_114 ;
break;
}
return 0 ;
}
static int F_46 ( struct V_115 * V_116 )
{
struct V_7 * V_8 = F_47 ( V_116 -> V_117 ,
struct V_7 , V_56 ) ;
int V_19 = - V_35 ;
switch ( V_116 -> V_16 ) {
case V_118 :
V_19 = F_45 ( V_8 , V_116 -> V_50 ) ;
break;
}
return V_19 ;
}
int F_48 ( struct V_7 * V_8 ,
const struct V_119 * V_120 , T_3 V_16 )
{
struct V_15 * V_6 = F_9 ( V_8 , V_16 ) ;
struct V_121 * V_122 = F_49 ( V_6 ) ;
struct V_123 * V_124 ;
int V_3 , V_18 ;
int V_19 ;
V_8 -> V_16 = V_16 ;
V_124 = F_50 ( V_122 , V_125 , V_120 -> V_126 [ 0 ] ) ;
V_8 -> V_10 = F_51 ( V_6 , V_124 ) ;
if ( F_52 ( V_8 -> V_10 ) ) {
F_12 ( V_6 , L_10 ) ;
return F_53 ( V_8 -> V_10 ) ;
}
V_124 = F_50 ( V_122 , V_127 ,
V_120 -> V_128 [ 0 ] ) ;
if ( ! V_124 ) {
F_12 ( V_6 , L_11 ) ;
return - V_35 ;
}
V_8 -> V_5 = V_124 -> V_129 ;
snprintf ( V_8 -> V_130 , sizeof( V_8 -> V_130 ) , L_12 ,
F_54 ( V_6 ) , V_131 , V_8 -> V_16 ) ;
V_19 = F_55 ( V_6 , V_8 -> V_5 , F_4 ,
V_132 , V_8 -> V_130 , V_8 ) ;
if ( V_19 < 0 ) {
F_12 ( V_6 , L_13 , V_19 ) ;
return V_19 ;
}
F_25 ( V_8 -> V_5 ) ;
V_8 -> V_22 = 0 ;
while ( V_120 -> clock [ V_8 -> V_22 ] )
V_8 -> V_22 ++ ;
V_8 -> clock = F_56 ( V_6 , V_8 -> V_22 * sizeof( * V_8 -> clock ) ,
V_133 ) ;
if ( ! V_8 -> clock )
return - V_134 ;
for ( V_3 = 0 ; V_3 < V_8 -> V_22 ; V_3 ++ ) {
struct V_23 * clock = & V_8 -> clock [ V_3 ] ;
clock -> V_36 = F_57 ( V_6 , V_120 -> clock [ V_3 ] ) ;
if ( F_52 ( clock -> V_36 ) )
return F_53 ( clock -> V_36 ) ;
clock -> V_24 = V_120 -> clock [ V_3 ] ;
clock -> V_33 = 0 ;
while ( V_120 -> V_135 [ V_3 ] [ clock -> V_33 ] )
clock -> V_33 ++ ;
if ( ! clock -> V_33 ) {
clock -> V_34 = NULL ;
continue;
}
clock -> V_34 = F_56 ( V_6 , clock -> V_33 *
sizeof( * clock -> V_34 ) , V_133 ) ;
if ( ! clock -> V_34 )
return - V_134 ;
for ( V_18 = 0 ; V_18 < clock -> V_33 ; V_18 ++ )
clock -> V_34 [ V_18 ] = V_120 -> V_135 [ V_3 ] [ V_18 ] ;
}
V_8 -> V_44 = F_58 ( V_6 , V_120 -> V_136 [ 0 ] ) ;
if ( F_52 ( V_8 -> V_44 ) ) {
F_12 ( V_6 , L_14 ) ;
return F_53 ( V_8 -> V_44 ) ;
}
F_59 ( & V_8 -> V_13 ) ;
return 0 ;
}
void F_60 ( struct V_137 * V_21 , T_3 * V_16 )
{
struct V_40 * V_41 = F_61 ( V_21 ) ;
struct V_7 * V_8 = F_20 ( V_41 ) ;
* V_16 = V_8 -> V_16 ;
}
static T_1 F_62 ( struct V_138 * V_139 )
{
T_1 V_75 = 0 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_139 -> V_140 ; V_3 ++ )
V_75 |= V_139 -> V_141 [ V_3 ] . V_142 << ( V_3 * 4 ) ;
return V_75 ;
}
static int F_63 ( struct V_137 * V_21 ,
const struct V_143 * V_144 ,
const struct V_143 * V_145 , T_1 V_146 )
{
if ( V_146 & V_147 )
if ( F_30 ( V_144 ) )
return - V_109 ;
if ( ( V_144 -> V_146 & V_148 ) &&
( V_146 & V_147 ) ) {
struct V_40 * V_41 ;
struct V_7 * V_8 ;
struct V_149 * V_150 ;
struct V_138 * V_139 ;
struct V_105 V_96 = { 0 } ;
V_41 = F_61 ( V_21 ) ;
V_8 = F_20 ( V_41 ) ;
if ( V_8 -> V_94 -> V_95 . V_50 != 0 )
return - V_109 ;
V_41 = F_61 ( V_145 -> V_21 ) ;
V_150 = F_20 ( V_41 ) ;
if ( ! V_150 -> V_84 . V_151 )
return - V_152 ;
V_8 -> V_29 . V_77 = V_150 -> V_16 ;
V_139 = & V_150 -> V_84 . V_151 -> V_139 ;
V_8 -> V_29 . V_30 = V_139 -> V_140 ;
V_8 -> V_29 . V_75 = F_62 ( V_139 ) ;
V_96 . V_85 = V_61 ;
V_96 . V_87 = V_108 ;
F_43 ( & V_8 -> V_20 , NULL , & V_96 ) ;
}
return 0 ;
}
int F_64 ( struct V_7 * V_8 ,
struct V_153 * V_154 )
{
struct V_40 * V_41 = & V_8 -> V_20 ;
struct V_143 * V_58 = V_8 -> V_58 ;
struct V_15 * V_6 = F_9 ( V_8 , V_8 -> V_16 ) ;
int V_19 ;
F_65 ( V_41 , & V_155 ) ;
V_41 -> V_156 = & V_157 ;
V_41 -> V_146 |= V_158 ;
snprintf ( V_41 -> V_24 , F_2 ( V_41 -> V_24 ) , L_15 ,
V_131 , V_8 -> V_16 ) ;
F_66 ( V_41 , V_8 ) ;
V_19 = F_67 ( & V_8 -> V_56 , 1 ) ;
if ( V_19 < 0 ) {
F_12 ( V_6 , L_16 , V_19 ) ;
return V_19 ;
}
V_8 -> V_94 = F_68 ( & V_8 -> V_56 ,
& V_159 , V_118 ,
F_2 ( V_160 ) - 1 , 0 , 0 ,
V_160 ) ;
if ( V_8 -> V_56 . error ) {
F_12 ( V_6 , L_17 , V_8 -> V_56 . error ) ;
V_19 = V_8 -> V_56 . error ;
goto V_161;
}
V_8 -> V_20 . V_162 = & V_8 -> V_56 ;
V_19 = F_44 ( V_41 , NULL ) ;
if ( V_19 < 0 ) {
F_12 ( V_6 , L_18 , V_19 ) ;
goto V_161;
}
V_58 [ V_59 ] . V_146 = V_148 ;
V_58 [ V_61 ] . V_146 = V_163 ;
V_41 -> V_21 . V_164 = V_165 ;
V_41 -> V_21 . V_166 = & V_167 ;
V_19 = F_69 ( & V_41 -> V_21 , V_168 , V_58 ) ;
if ( V_19 < 0 ) {
F_12 ( V_6 , L_19 , V_19 ) ;
goto V_161;
}
V_19 = F_70 ( V_154 , V_41 ) ;
if ( V_19 < 0 ) {
F_12 ( V_6 , L_20 , V_19 ) ;
goto V_169;
}
return 0 ;
V_169:
F_71 ( & V_41 -> V_21 ) ;
V_161:
F_72 ( & V_8 -> V_56 ) ;
return V_19 ;
}
void F_73 ( struct V_7 * V_8 )
{
F_74 ( & V_8 -> V_20 ) ;
F_71 ( & V_8 -> V_20 . V_21 ) ;
F_72 ( & V_8 -> V_56 ) ;
}
