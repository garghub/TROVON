static int F_1 ( char * V_1 )
{
int V_2 ;
int V_3 ;
if ( V_1 [ - 1 ] != ';' )
return 0 ;
V_3 = F_2 ( V_1 , 10 , & V_2 ) ;
if ( V_3 )
return 0 ;
if ( V_2 < 1 || V_2 > 65535 )
return - 1 ;
return V_2 ;
}
void F_3 ( struct V_4 * V_5 )
{
unsigned char * V_6 [ V_7 + 1 ] ;
int V_8 ;
int V_9 , V_10 ;
const struct V_11 * V_12 ;
const struct V_13 * V_14 ;
int V_15 ;
unsigned long V_16 ;
unsigned V_17 , V_18 , V_19 ;
struct V_20 * V_21 ;
int V_22 ;
int V_23 ;
int abort ;
T_1 V_24 ;
int V_2 ;
int V_25 ;
V_24 = V_5 -> V_26 ;
if ( ! V_24 ) {
F_4 ( V_27 , L_1 , V_5 -> V_28 [ V_24 ] ) ;
return;
}
V_5 -> V_28 [ V_24 ] = 0 ;
V_6 [ 0 ] = V_5 -> V_28 ;
V_8 = 1 ;
if ( V_5 -> V_29 . V_30 ) {
V_5 -> V_29 . V_30 = 0 ;
V_25 = 1 ;
V_2 = 0 ;
} else {
for ( V_9 = 0 ; V_9 < V_24 ; V_9 ++ )
switch ( V_5 -> V_28 [ V_9 ] ) {
case ';' :
case ',' :
case '=' :
if ( V_8 > V_7 ) {
F_5 ( V_5 -> V_31 ,
L_2 ) ;
V_8 -- ;
}
V_6 [ V_8 ++ ] = V_5 -> V_28 + V_9 + 1 ;
}
V_25 = 0 ;
V_2 = V_8 > 1 ? F_1 ( V_6 [ V_8 - 1 ] ) : 0 ;
if ( V_2 < 0 ) {
F_6 ( V_5 , & V_5 -> V_29 , V_32 ,
NULL , 0 , NULL ) ;
return;
}
for ( V_10 = 1 ; V_10 < V_8 ; ++ V_10 )
V_6 [ V_10 ] [ - 1 ] = 0 ;
F_4 ( V_33 , L_3 , V_6 [ 0 ] ) ;
if ( V_2 ) {
-- V_8 ;
F_4 ( V_33 , L_4 , V_6 [ V_8 ] ) ;
}
F_4 ( V_33 , L_5 , V_8 - 1 ) ;
for ( V_10 = 1 ; V_10 < V_8 ; V_10 ++ )
F_4 ( V_33 , L_6 , V_10 , V_6 [ V_10 ] ) ;
}
F_7 ( & V_5 -> V_34 , V_16 ) ;
V_19 = V_5 -> V_35 ;
V_18 = V_5 -> V_36 ;
abort = 1 ;
V_15 = 0 ;
while ( V_15 < V_8 ) {
V_17 = ( V_18 + 1 ) % V_37 ;
if ( F_8 ( V_17 == V_19 ) ) {
F_9 ( V_5 -> V_31 , L_7 ) ;
break;
}
V_21 = V_5 -> V_38 + V_18 ;
V_21 -> V_29 = NULL ;
V_21 -> V_2 = V_2 ;
V_21 -> V_39 = NULL ;
V_21 -> V_40 = NULL ;
V_18 = V_17 ;
if ( V_25 ) {
V_22 = V_41 ;
V_23 = V_42 ;
} else {
for ( V_12 = V_43 ; V_12 -> V_44 ; ++ V_12 )
if ( ! strcmp ( V_6 [ V_15 ] , V_12 -> V_44 ) )
break;
if ( ! V_12 -> V_44 ) {
V_21 -> type = V_45 ;
F_4 ( V_33 ,
L_8 ,
V_6 [ V_15 ] ) ;
break;
}
V_22 = V_12 -> V_22 ;
V_23 = V_12 -> type ;
++ V_15 ;
}
V_21 -> type = V_22 ;
switch ( V_23 ) {
case V_46 :
break;
case V_47 :
if ( ! V_2 ) {
F_9 ( V_5 -> V_31 ,
L_9 ) ;
V_21 -> type = V_32 ;
abort = 1 ;
} else {
V_21 -> V_2 = 0 ;
V_21 -> V_48 = V_2 ;
abort = 0 ;
}
break;
case V_49 :
if ( V_15 >= V_8 ) {
V_21 -> V_48 = V_50 ;
break;
}
for ( V_14 = V_51 ; V_14 -> V_52 ; ++ V_14 )
if ( ! strcmp ( V_6 [ V_15 ] , V_14 -> V_52 ) )
break;
V_21 -> V_48 = V_14 -> V_53 ;
if ( ! V_14 -> V_52 )
F_5 ( V_5 -> V_31 ,
L_10 ,
V_54 , V_6 [ V_15 ] ) ;
++ V_15 ;
break;
case V_42 :
if ( V_15 < V_8 ) {
V_21 -> V_39 = F_10 ( V_6 [ V_15 ] , V_55 ) ;
if ( ! V_21 -> V_39 )
F_9 ( V_5 -> V_31 , L_11 ) ;
++ V_15 ;
}
F_4 ( V_33 , L_12 ,
V_21 -> V_39 ? ( char * ) V_21 -> V_39 : L_13 ) ;
break;
case V_56 :
V_21 -> V_48 = - 1 ;
if ( V_15 + 1 < V_8 ) {
T_2 type , V_57 ;
V_9 = F_11 ( V_6 [ V_15 ++ ] , 16 , & type ) ;
V_10 = F_11 ( V_6 [ V_15 ++ ] , 16 , & V_57 ) ;
if ( V_9 == 0 && V_10 == 0 )
V_21 -> V_48 = ( type << 8 ) | V_57 ;
} else
V_15 = V_8 - 1 ;
break;
case V_58 :
if ( V_15 >= V_8 ||
F_2 ( V_6 [ V_15 ++ ] , 10 , & V_21 -> V_48 ) )
V_21 -> V_48 = - 1 ;
F_4 ( V_33 , L_14 , V_21 -> V_48 ) ;
break;
}
if ( V_22 == V_59 )
V_5 -> V_60 = V_21 -> V_48 ;
if ( abort )
break;
}
V_5 -> V_36 = V_18 ;
F_12 ( & V_5 -> V_34 , V_16 ) ;
if ( V_15 != V_8 )
F_4 ( V_33 ,
L_15 ,
V_15 , V_8 ) ;
}
static void F_13 ( struct V_61 * * V_62 )
{
unsigned long V_16 ;
struct V_63 * V_64 = ( * V_62 ) -> V_64 ;
struct V_4 * V_5 = ( * V_62 ) -> V_5 ;
F_7 ( & V_5 -> V_65 , V_16 ) ;
++ ( * V_62 ) -> V_66 ;
if ( ! V_5 -> V_67 ) {
V_5 -> V_29 . V_68 |= V_69 ;
F_4 ( V_33 , L_16 ) ;
V_5 -> V_70 = 1 ;
}
F_12 ( & V_5 -> V_65 , V_16 ) ;
if ( V_64 ) {
V_5 -> V_71 -> V_72 ( V_64 ) ;
if ( V_64 -> V_73 & ( V_74 | V_75 ) ) {
V_64 -> V_73 &= ~ ( V_74 | V_75 ) ;
F_14 ( V_64 ) ;
}
} else {
F_7 ( & V_5 -> V_65 , V_16 ) ;
F_15 ( & ( * V_62 ) -> V_76 ) ;
F_16 ( * V_62 ) ;
* V_62 = NULL ;
F_12 ( & V_5 -> V_65 , V_16 ) ;
}
}
static inline struct V_61 * F_17 ( struct V_4 * V_5 ,
int V_2 )
{
unsigned long V_16 ;
int V_9 ;
struct V_61 * V_77 ;
for ( V_9 = 0 ; V_9 < V_5 -> V_78 ; ++ V_9 )
if ( F_18 ( V_5 -> V_64 + V_9 ) ) {
V_77 = & V_5 -> V_64 [ V_9 ] . V_29 ;
V_77 -> V_2 = V_2 ;
return V_77 ;
}
F_7 ( & V_5 -> V_65 , V_16 ) ;
V_77 = F_19 ( sizeof( struct V_61 ) , V_55 ) ;
if ( V_77 ) {
F_20 ( V_77 , NULL , V_5 , V_2 ) ;
F_21 ( & V_77 -> V_76 , & V_5 -> V_79 ) ;
}
F_12 ( & V_5 -> V_65 , V_16 ) ;
return V_77 ;
}
static void F_22 ( struct V_4 * V_5 , int V_80 )
{
int V_9 ;
struct V_61 * V_29 ;
V_5 -> V_29 . V_68 &= ~ V_81 ;
V_5 -> V_80 = V_80 ;
V_5 -> V_82 = V_83 ;
F_23 ( V_5 ) ;
for ( V_9 = 0 ; V_9 < V_5 -> V_78 ; ++ V_9 ) {
V_29 = & V_5 -> V_64 [ V_9 ] . V_29 ;
if ( V_29 -> V_68 & V_84 ) {
V_29 -> V_68 &= ~ V_84 ;
V_29 -> V_68 |= V_85 ;
V_5 -> V_70 = 1 ;
}
}
}
static void F_24 ( struct V_4 * V_5 , int V_86 )
{
if ( V_5 -> V_29 . V_68 & V_81 ) {
F_4 ( V_33 , L_17 ) ;
return;
}
V_5 -> V_82 = V_86 ;
V_5 -> V_80 = V_87 ;
F_25 ( V_5 ) ;
V_5 -> V_29 . V_68 |= V_81 ;
F_4 ( V_33 , L_18 ) ;
V_5 -> V_70 = 1 ;
}
static void F_26 ( struct V_4 * V_5 , const char * V_88 , int V_2 ,
int V_60 , T_3 V_89 )
{
struct V_90 * V_91 ;
T_1 V_92 ;
V_92 = strlen ( V_88 ) + 12 ;
V_91 = F_19 ( sizeof( struct V_90 ) + V_92 , V_89 ) ;
if ( ! V_91 ) {
F_9 ( V_5 -> V_31 , L_19 , V_54 ) ;
return;
}
if ( V_2 > 0 && V_2 <= 65535 )
V_91 -> V_24 = snprintf ( V_91 -> V_93 , V_92 ,
V_60 ? L_20 : L_21 ,
V_2 , V_88 ) ;
else
V_91 -> V_24 = snprintf ( V_91 -> V_93 , V_92 ,
V_60 ? L_22 : L_23 ,
V_88 ) ;
V_91 -> V_94 = 0 ;
V_91 -> V_17 = NULL ;
V_91 -> V_95 = NULL ;
V_5 -> V_71 -> V_96 ( V_5 , V_91 ) ;
}
static struct V_61 * F_27 ( struct V_4 * V_5 , int V_2 )
{
struct V_61 * V_29 ;
int V_9 ;
unsigned long V_16 ;
if ( V_2 == 0 )
return & V_5 -> V_29 ;
for ( V_9 = 0 ; V_9 < V_5 -> V_78 ; ++ V_9 )
if ( V_2 == V_5 -> V_64 [ V_9 ] . V_29 . V_2 )
return & V_5 -> V_64 [ V_9 ] . V_29 ;
F_7 ( & V_5 -> V_65 , V_16 ) ;
F_28 (at_state, &cs->temp_at_states, list)
if ( V_2 == V_29 -> V_2 ) {
F_12 ( & V_5 -> V_65 , V_16 ) ;
return V_29 ;
}
F_12 ( & V_5 -> V_65 , V_16 ) ;
return NULL ;
}
static void F_29 ( struct V_63 * V_64 )
{
if ( V_64 -> V_73 & V_97 ) {
V_64 -> V_73 &= ~ V_97 ;
F_30 ( V_64 ) ;
}
if ( V_64 -> V_73 & ( V_74 | V_75 ) ) {
V_64 -> V_73 &= ~ ( V_74 | V_75 ) ;
F_14 ( V_64 ) ;
}
F_31 ( V_64 ) ;
F_32 ( V_64 ) ;
}
static void F_33 ( struct V_63 * V_64 )
{
if ( V_64 -> V_73 & V_97 ) {
F_34 ( V_64 -> V_5 -> V_31 , L_24 ,
V_54 ) ;
return;
}
V_64 -> V_73 |= V_97 ;
F_35 ( V_64 ) ;
}
static void F_36 ( struct V_61 * V_29 , void * V_98 ,
unsigned V_66 )
{
struct V_63 * V_64 = V_29 -> V_64 ;
struct V_4 * V_5 = V_29 -> V_5 ;
char * * V_99 = V_98 ;
unsigned long V_16 ;
int V_9 ;
V_64 -> V_73 |= V_75 ;
F_7 ( & V_5 -> V_65 , V_16 ) ;
if ( V_29 -> V_66 != V_66 ) {
F_12 ( & V_5 -> V_65 , V_16 ) ;
goto error;
}
F_12 ( & V_5 -> V_65 , V_16 ) ;
for ( V_9 = 0 ; V_9 < V_100 ; ++ V_9 ) {
F_16 ( V_64 -> V_99 [ V_9 ] ) ;
V_64 -> V_99 [ V_9 ] = V_99 [ V_9 ] ;
}
V_29 -> V_68 |= V_84 ;
F_4 ( V_33 , L_25 ) ;
V_5 -> V_70 = 1 ;
return;
error:
for ( V_9 = 0 ; V_9 < V_100 ; ++ V_9 ) {
F_16 ( V_99 [ V_9 ] ) ;
V_99 [ V_9 ] = NULL ;
}
V_29 -> V_68 |= V_85 ;
F_4 ( V_33 , L_26 ) ;
V_5 -> V_70 = 1 ;
return;
}
static void F_37 ( struct V_61 * V_29 )
{
struct V_4 * V_5 = V_29 -> V_5 ;
struct V_63 * V_64 = V_29 -> V_64 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_100 ; ++ V_9 ) {
F_16 ( V_64 -> V_99 [ V_9 ] ) ;
V_64 -> V_99 [ V_9 ] = NULL ;
}
V_64 -> V_99 [ V_101 ] = F_19 ( 9 , V_55 ) ;
V_64 -> V_99 [ V_102 ] = F_19 ( 9 , V_55 ) ;
if ( ! V_64 -> V_99 [ V_101 ] || ! V_64 -> V_99 [ V_102 ] ) {
F_9 ( V_29 -> V_5 -> V_31 , L_11 ) ;
V_29 -> V_68 |= V_103 ;
F_4 ( V_33 , L_27 ) ;
V_5 -> V_70 = 1 ;
return;
}
snprintf ( V_64 -> V_99 [ V_101 ] , 9 , L_28 , V_64 -> V_104 ) ;
snprintf ( V_64 -> V_99 [ V_102 ] , 9 , L_29 , V_64 -> V_105 + 1 ) ;
V_29 -> V_68 |= V_106 ;
F_4 ( V_33 , L_30 ) ;
V_5 -> V_70 = 1 ;
}
static void F_38 ( struct V_4 * V_5 )
{
F_23 ( V_5 ) ;
if ( V_5 -> V_82 != V_107 )
F_24 ( V_5 , V_108 ) ;
V_5 -> V_109 = 1 ;
F_39 ( V_5 ) ;
V_5 -> V_110 = 0 ;
F_40 ( & V_5 -> V_111 ) ;
}
static void F_41 ( struct V_4 * V_5 )
{
if ( V_5 -> V_82 != V_107 ) {
V_5 -> V_82 = V_83 ;
V_5 -> V_80 = V_87 ;
}
if ( V_5 -> V_109 ) {
V_5 -> V_109 = 0 ;
F_42 ( V_5 ) ;
}
V_5 -> V_112 = - V_113 ;
V_5 -> V_110 = 0 ;
F_40 ( & V_5 -> V_111 ) ;
}
static void F_43 ( struct V_4 * V_5 )
{
F_25 ( V_5 ) ;
if ( V_5 -> V_82 == V_114 ) {
V_5 -> V_82 = V_115 ;
V_5 -> V_29 . V_68 |= V_116 ;
F_4 ( V_33 , L_31 ) ;
V_5 -> V_70 = 1 ;
} else
F_41 ( V_5 ) ;
}
static void F_44 ( struct V_4 * V_5 )
{
unsigned long V_16 ;
F_7 ( & V_5 -> V_65 , V_16 ) ;
V_5 -> V_117 = 0 ;
F_12 ( & V_5 -> V_65 , V_16 ) ;
F_43 ( V_5 ) ;
}
static int F_45 ( struct V_4 * V_5 , int V_105 )
{
int V_9 ;
if ( -- V_5 -> V_118 <= 0 )
return 0 ;
for ( V_9 = 0 ; V_9 < V_5 -> V_78 ; ++ V_9 )
if ( V_5 -> V_64 [ V_9 ] . V_29 . V_2 > 0 )
return 0 ;
if ( V_105 < 0 )
F_5 ( V_5 -> V_31 ,
L_32 ) ;
else {
F_5 ( V_5 -> V_31 ,
L_33 ) ;
V_5 -> V_64 [ V_105 ] . V_29 . V_68 |= V_84 ;
}
F_24 ( V_5 , V_108 ) ;
return 1 ;
}
static int F_46 ( struct V_4 * V_5 ,
struct V_61 * V_119 )
{
unsigned long V_16 ;
unsigned V_105 ;
struct V_61 * V_29 ;
int V_120 = 0 ;
F_7 ( & V_5 -> V_65 , V_16 ) ;
if ( V_119 == & V_5 -> V_29 )
goto exit;
F_28 (at_state, &cs->temp_at_states, list)
if ( V_29 == V_119 )
goto exit;
for ( V_105 = 0 ; V_105 < V_5 -> V_78 ; ++ V_105 )
if ( & V_5 -> V_64 [ V_105 ] . V_29 == V_119 )
goto exit;
V_120 = 1 ;
exit:
F_12 ( & V_5 -> V_65 , V_16 ) ;
return V_120 ;
}
static void F_47 ( struct V_4 * V_5 , struct V_63 * V_64 ,
struct V_61 * * V_121 )
{
int V_120 ;
struct V_61 * V_29 = * V_121 ;
V_120 = F_48 ( V_29 ) ;
switch ( V_120 ) {
case V_122 :
break;
default:
F_9 ( V_5 -> V_31 , L_34 , V_120 ) ;
case V_123 :
case V_124 :
V_29 -> V_68 |= V_103 ;
V_5 -> V_70 = 1 ;
break;
}
}
static int F_49 ( struct V_4 * V_5 )
{
int V_80 ;
int V_9 ;
switch ( V_5 -> V_82 ) {
case V_83 :
case V_114 :
if ( V_5 -> V_125 || ! F_50 ( & V_5 -> V_79 ) ||
V_5 -> V_29 . V_68 )
return - V_126 ;
for ( V_9 = 0 ; V_9 < V_5 -> V_78 ; ++ V_9 )
if ( V_5 -> V_64 [ V_9 ] . V_29 . V_68 )
return - V_126 ;
if ( ! F_51 ( V_5 ) )
return - V_126 ;
break;
case V_107 :
break;
default:
return - V_126 ;
}
V_80 = V_5 -> V_80 ;
V_5 -> V_82 = V_107 ;
V_5 -> V_80 = V_87 ;
return V_80 ;
}
static int F_52 ( struct V_4 * V_5 )
{
if ( V_5 -> V_82 != V_107 )
return - V_127 ;
V_5 -> V_82 = V_83 ;
V_5 -> V_80 = V_87 ;
F_23 ( V_5 ) ;
if ( V_5 -> V_117 )
F_24 ( V_5 , V_108 ) ;
return 0 ;
}
static void F_53 ( int V_128 , struct V_4 * V_5 ,
struct V_63 * V_64 ,
struct V_61 * * V_121 , char * * V_129 ,
int * V_130 , int * V_131 ,
struct V_20 * V_132 )
{
struct V_61 * V_29 = * V_121 ;
struct V_61 * V_133 ;
unsigned long V_16 ;
int V_105 ;
unsigned char * V_1 , * V_134 ;
int V_9 ;
unsigned long V_135 ;
switch ( V_128 ) {
case V_136 :
break;
case V_137 :
V_29 -> V_110 = 1 ;
break;
case V_138 :
V_5 -> V_29 . V_68 &= ~ V_81 ;
V_5 -> V_125 = V_139 ;
V_5 -> V_80 = V_140 ;
F_7 ( & V_5 -> V_65 , V_16 ) ;
if ( ! V_5 -> V_67 ) {
F_12 ( & V_5 -> V_65 , V_16 ) ;
F_23 ( V_5 ) ;
V_5 -> V_82 = V_114 ;
break;
}
F_12 ( & V_5 -> V_65 , V_16 ) ;
V_5 -> V_29 . V_68 |= V_141 ;
F_4 ( V_33 , L_35 ) ;
V_5 -> V_70 = 1 ;
break;
case V_142 :
F_5 ( V_5 -> V_31 , L_36 ) ;
V_5 -> V_60 = 0 ;
F_22 ( V_5 , V_87 ) ;
V_5 -> V_125 = V_139 ;
break;
case V_143 :
F_22 ( V_5 , V_144 ) ;
V_5 -> V_125 = V_139 ;
break;
case V_145 :
V_5 -> V_60 = 1 ;
V_5 -> V_146 [ 0 ] . V_147 &=
~ ( V_148 | V_149 ) ;
break;
case V_150 :
V_5 -> V_60 = 0 ;
V_5 -> V_146 [ 0 ] . V_147 =
( V_5 -> V_146 [ 0 ] . V_147 & ~ V_149 )
| V_148 ;
break;
case V_151 :
if ( V_5 -> V_82 == V_108 || V_5 -> V_82 == V_152 ) {
F_23 ( V_5 ) ;
V_5 -> V_82 = V_114 ;
}
V_5 -> V_80 = V_153 ;
V_5 -> V_125 = V_139 ;
break;
case V_154 :
V_5 -> V_80 = V_140 ;
V_5 -> V_125 = V_139 ;
break;
case V_155 :
V_5 -> V_125 = V_139 ;
if ( V_5 -> V_82 == V_108 || V_5 -> V_82 == V_152 ) {
F_22 ( V_5 , V_87 ) ;
break;
}
if ( ! F_45 ( V_5 , - 1 ) )
F_24 ( V_5 , V_152 ) ;
break;
case V_156 :
V_5 -> V_125 = V_139 ;
F_24 ( V_5 , V_152 ) ;
break;
case V_157 :
if ( V_5 -> V_117 ) {
struct V_90 * V_91 ;
V_91 = F_19 ( sizeof( struct V_90 ) + 3 , V_55 ) ;
if ( ! V_91 ) {
F_9 ( V_5 -> V_31 , L_19 ,
V_54 ) ;
return;
}
memcpy ( V_91 -> V_93 , L_37 , 3 ) ;
V_91 -> V_24 = 3 ;
V_91 -> V_94 = 0 ;
V_91 -> V_17 = NULL ;
V_91 -> V_95 = NULL ;
V_5 -> V_71 -> V_96 ( V_5 , V_91 ) ;
}
break;
case V_158 :
V_133 = F_17 ( V_5 , V_132 -> V_48 ) ;
if ( ! V_133 ) {
F_5 ( V_5 -> V_31 ,
L_38 ) ;
break;
}
V_133 -> V_159 = 700 ;
for ( V_9 = 0 ; V_9 < V_160 ; ++ V_9 ) {
F_16 ( V_133 -> V_161 [ V_9 ] ) ;
V_133 -> V_161 [ V_9 ] = NULL ;
}
V_133 -> V_162 [ V_163 ] = - 1 ;
F_7 ( & V_5 -> V_65 , V_16 ) ;
V_133 -> V_164 = V_165 ;
V_133 -> V_166 = 1 ;
F_12 ( & V_5 -> V_65 , V_16 ) ;
break;
case V_167 :
F_47 ( V_5 , V_64 , V_121 ) ;
break;
case V_168 :
F_5 ( V_5 -> V_31 , L_39 ) ;
case V_169 :
case V_170 :
V_5 -> V_125 = V_139 ;
F_41 ( V_5 ) ;
break;
case V_171 :
if ( V_5 -> V_172 ) {
V_29 -> V_68 |= V_173 ;
V_5 -> V_70 = 1 ;
break;
}
V_64 -> V_73 |= V_74 ;
F_54 ( V_64 ) ;
V_5 -> V_71 -> V_174 ( V_64 ) ;
break;
case V_175 :
V_5 -> V_125 = V_139 ;
V_64 = V_5 -> V_64 + V_5 -> V_176 ;
V_64 -> V_73 |= V_74 ;
F_54 ( V_64 ) ;
V_5 -> V_71 -> V_174 ( V_64 ) ;
break;
case V_177 :
V_29 -> V_162 [ V_178 ] = V_179 ;
case V_180 :
V_5 -> V_125 = V_139 ;
V_29 -> V_2 = - 1 ;
if ( V_64 && V_5 -> V_172 && V_5 -> V_60 ) {
V_29 -> V_68 |= V_181 ;
V_5 -> V_70 = 1 ;
} else
F_13 ( V_121 ) ;
break;
case V_182 :
V_29 -> V_162 [ V_183 ] = 0 ;
V_5 -> V_60 = 0 ;
case V_184 :
V_5 -> V_125 = V_139 ;
V_133 = & V_5 -> V_64 [ V_5 -> V_176 ] . V_29 ;
F_13 ( & V_133 ) ;
break;
case V_185 :
V_5 -> V_125 = V_139 ;
F_5 ( V_5 -> V_31 , L_40 ) ;
V_29 -> V_2 = - 1 ;
if ( V_64 && V_5 -> V_172 )
V_29 -> V_68 |= V_181 ;
else
F_13 ( V_121 ) ;
F_24 ( V_5 , V_152 ) ;
break;
case V_186 :
V_5 -> V_125 = V_139 ;
F_5 ( V_5 -> V_31 , L_41 ) ;
V_133 = & V_5 -> V_64 [ V_5 -> V_176 ] . V_29 ;
F_13 ( & V_133 ) ;
F_24 ( V_5 , V_152 ) ;
break;
case V_187 :
V_5 -> V_125 = V_139 ;
F_5 ( V_5 -> V_31 ,
L_42 ) ;
V_105 = V_5 -> V_176 ;
V_5 -> V_64 [ V_105 ] . V_29 . V_68 |= V_103 ;
V_5 -> V_70 = 1 ;
break;
case V_188 :
V_5 -> V_125 = V_139 ;
V_105 = V_5 -> V_176 ;
if ( V_132 -> V_48 > 0 && V_132 -> V_48 <= 65535 ) {
V_5 -> V_64 [ V_105 ] . V_29 . V_2 = V_132 -> V_48 ;
V_5 -> V_64 [ V_105 ] . V_29 . V_68 |=
V_189 ;
V_5 -> V_70 = 1 ;
break;
}
case V_190 :
V_5 -> V_125 = V_139 ;
V_105 = V_5 -> V_176 ;
if ( ! F_45 ( V_5 , V_105 ) ) {
F_5 ( V_5 -> V_31 ,
L_43 ) ;
V_133 = & V_5 -> V_64 [ V_105 ] . V_29 ;
F_13 ( & V_133 ) ;
}
break;
case V_191 :
V_5 -> V_125 = V_139 ;
V_133 = & V_5 -> V_64 [ V_5 -> V_176 ] . V_29 ;
F_13 ( & V_133 ) ;
break;
case V_192 :
case V_193 :
V_5 -> V_125 = V_139 ;
break;
case V_194 :
F_13 ( V_121 ) ;
break;
case V_195 :
V_5 -> V_125 = V_139 ;
V_29 -> V_68 |= V_103 ;
V_5 -> V_70 = 1 ;
break;
case V_196 :
case V_197 :
case V_198 :
V_29 -> V_68 |= V_103 ;
V_5 -> V_70 = 1 ;
break;
case V_199 :
V_29 -> V_30 = 1 ;
break;
case V_200 :
if ( ! V_132 -> V_39 ) {
* V_130 = 1 ;
* V_131 = V_201 ;
break;
}
V_1 = V_132 -> V_39 ;
if ( ! strcmp ( V_1 , L_44 ) ) {
* V_130 = 1 ;
* V_131 = V_201 ;
break;
}
for ( V_9 = 0 ; V_9 < 4 ; ++ V_9 ) {
V_135 = F_55 ( V_1 , ( char * * ) & V_134 , 10 ) ;
if ( V_135 > V_202 || V_134 == V_1 )
break;
if ( V_9 == 3 ) {
if ( * V_134 )
break;
} else if ( * V_134 != '.' )
break;
else
V_1 = V_134 + 1 ;
V_5 -> V_203 [ V_9 ] = V_135 ;
}
if ( V_9 != 4 ) {
* V_130 = 1 ;
* V_131 = V_201 ;
break;
}
V_5 -> V_204 = 0 ;
break;
case V_205 :
if ( V_5 -> V_204 == 0 ) {
V_5 -> V_204 = 1 ;
F_4 ( V_33 ,
L_45 ,
V_5 -> V_203 [ 0 ] , V_5 -> V_203 [ 1 ] ,
V_5 -> V_203 [ 2 ] , V_5 -> V_203 [ 3 ] ) ;
break;
}
case V_206 :
V_5 -> V_204 = - 1 ;
F_9 ( V_5 -> V_31 , L_46 ) ;
break;
case V_207 :
F_4 ( V_208 , L_47 ,
V_54 , V_29 -> V_159 ) ;
V_5 -> V_125 = V_139 ;
break;
case V_209 :
F_4 ( V_208 , L_48 ,
V_54 , V_132 -> type , V_29 -> V_159 ) ;
break;
case V_210 :
F_5 ( V_5 -> V_31 , L_49 ,
V_54 , V_132 -> type , V_29 -> V_159 ) ;
break;
case V_211 :
F_5 ( V_5 -> V_31 , L_50 ,
V_132 -> V_48 , V_29 -> V_159 ) ;
break;
case V_212 :
F_36 ( V_29 , V_132 -> V_39 , V_132 -> V_48 ) ;
break;
case V_213 :
F_37 ( V_29 ) ;
break;
case V_214 :
V_29 -> V_68 |= V_103 ;
F_4 ( V_33 , L_27 ) ;
V_5 -> V_70 = 1 ;
break;
case V_215 :
F_44 ( V_5 ) ;
break;
case V_216 :
F_38 ( V_5 ) ;
break;
case V_217 :
V_5 -> V_112 = V_132 -> V_48 ? F_49 ( V_5 ) : F_52 ( V_5 ) ;
V_5 -> V_110 = 0 ;
F_40 ( & V_5 -> V_111 ) ;
break;
case V_218 :
if ( V_132 -> V_48 != 0 )
V_5 -> V_112 = - V_127 ;
else if ( V_5 -> V_204 != 1 ) {
V_5 -> V_112 = - V_219 ;
} else {
memcpy ( V_132 -> V_40 , V_5 -> V_203 , sizeof V_5 -> V_203 ) ;
V_5 -> V_112 = 0 ;
}
V_5 -> V_110 = 0 ;
F_40 ( & V_5 -> V_111 ) ;
break;
case V_220 :
F_7 ( & V_5 -> V_65 , V_16 ) ;
if ( V_132 -> V_48 != V_5 -> V_67 ) {
V_5 -> V_67 = V_132 -> V_48 ;
if ( V_132 -> V_48 ) {
V_5 -> V_29 . V_68 |= V_141 ;
F_4 ( V_33 , L_35 ) ;
} else {
V_5 -> V_29 . V_68 |= V_69 ;
F_4 ( V_33 , L_16 ) ;
}
V_5 -> V_70 = 1 ;
}
F_12 ( & V_5 -> V_65 , V_16 ) ;
V_5 -> V_110 = 0 ;
F_40 ( & V_5 -> V_111 ) ;
break;
case V_221 :
F_29 ( V_64 ) ;
break;
case V_222 :
F_33 ( V_64 ) ;
break;
case V_223 :
F_43 ( V_5 ) ;
break;
default:
if ( V_128 >= V_224 && V_128 < V_224 + V_100 ) {
* V_129 = V_29 -> V_64 -> V_99 [ V_128 - V_224 ] ;
if ( ! * V_129 ) {
* V_130 = 1 ;
* V_131 = V_225 ;
}
} else
F_9 ( V_5 -> V_31 , L_51 , V_54 , V_128 ) ;
}
}
static void F_56 ( struct V_4 * V_5 , struct V_20 * V_132 )
{
struct V_63 * V_64 ;
char * V_226 = NULL ;
struct V_227 * V_228 ;
int V_229 ;
int V_230 = 0 ;
int V_22 = V_201 ;
int V_231 ;
struct V_61 * V_29 ;
int V_232 ;
int V_233 ;
unsigned long V_16 ;
if ( V_132 -> V_2 >= 0 ) {
V_29 = F_27 ( V_5 , V_132 -> V_2 ) ;
if ( ! V_29 ) {
F_4 ( V_33 , L_52 ,
V_132 -> type , V_132 -> V_2 ) ;
F_6 ( V_5 , & V_5 -> V_29 , V_234 ,
NULL , 0 , NULL ) ;
return;
}
} else {
V_29 = V_132 -> V_29 ;
if ( F_46 ( V_5 , V_29 ) ) {
F_4 ( V_33 , L_53 ,
V_29 ) ;
return;
}
}
F_4 ( V_33 , L_54 ,
V_29 -> V_159 , V_132 -> type ) ;
V_64 = V_29 -> V_64 ;
V_231 = V_29 -> V_2 ;
V_228 = V_29 -> V_235 ;
F_7 ( & V_5 -> V_65 , V_16 ) ;
if ( V_132 -> type == V_236 ) {
if ( V_132 -> V_48 != V_29 -> V_237
|| ! V_29 -> V_166 ) {
V_132 -> type = V_45 ;
F_4 ( V_33 , L_55 ) ;
} else if ( ! V_29 -> V_110 )
F_4 ( V_33 , L_56 ) ;
else
F_4 ( V_33 , L_57 ) ;
}
F_12 ( & V_5 -> V_65 , V_16 ) ;
if ( V_132 -> type >= V_238 && V_132 -> type < V_238 + V_239 ) {
V_232 = V_132 -> type - V_238 ;
V_29 -> V_162 [ V_232 ] = V_132 -> V_48 ;
} else if ( V_132 -> type >= V_240 && V_132 -> type < V_240 + V_160 ) {
V_232 = V_132 -> type - V_240 ;
F_16 ( V_29 -> V_161 [ V_232 ] ) ;
V_29 -> V_161 [ V_232 ] = V_132 -> V_39 ;
V_132 -> V_39 = NULL ;
}
if ( V_132 -> type == V_236 || V_132 -> type == V_41 )
V_29 -> V_30 = 0 ;
for (; ; V_228 ++ ) {
V_229 = V_228 -> V_22 ;
if ( V_229 == V_241 ) {
F_5 ( V_5 -> V_31 , L_58
L_59 ,
V_54 , V_132 -> type , V_29 -> V_159 ) ;
return;
}
if ( ( V_229 == V_242 || V_229 == V_132 -> type )
&& ( ( int ) V_29 -> V_159 >= V_228 -> V_243 )
&& ( V_228 -> V_244 < 0
|| ( int ) V_29 -> V_159 <= V_228 -> V_244 )
&& ( V_228 -> V_48 < 0 || V_228 -> V_48 == V_132 -> V_48 ) )
break;
}
V_226 = V_228 -> V_245 ;
V_29 -> V_110 = 0 ;
for ( V_233 = 0 ; V_233 < V_246 ; ++ V_233 ) {
F_53 ( V_228 -> V_128 [ V_233 ] , V_5 , V_64 , & V_29 , & V_226 ,
& V_230 , & V_22 , V_132 ) ;
if ( ! V_29 )
break;
}
if ( V_29 ) {
if ( V_228 -> V_247 >= 0 )
V_29 -> V_159 = V_228 -> V_247 ;
if ( V_230 ) {
F_7 ( & V_5 -> V_65 , V_16 ) ;
V_29 -> V_164 = 0 ;
V_29 -> V_166 = 0 ;
F_12 ( & V_5 -> V_65 , V_16 ) ;
F_6 ( V_5 , V_29 , V_22 ,
NULL , 0 , NULL ) ;
} else {
if ( V_226 ) {
if ( V_5 -> V_117 )
F_26 ( V_5 , V_226 ,
V_231 , V_5 -> V_60 ,
V_55 ) ;
else
F_6 ( V_5 , V_29 ,
V_248 ,
NULL , 0 , NULL ) ;
}
F_7 ( & V_5 -> V_65 , V_16 ) ;
if ( ! V_228 -> V_249 ) {
V_29 -> V_164 = 0 ;
V_29 -> V_166 = 0 ;
} else if ( V_228 -> V_249 > 0 ) {
V_29 -> V_164 = V_228 -> V_249 * 10 ;
V_29 -> V_166 = 1 ;
++ V_29 -> V_237 ;
}
F_12 ( & V_5 -> V_65 , V_16 ) ;
}
}
}
static void F_57 ( struct V_4 * V_5 ,
struct V_61 * V_29 , int V_250 )
{
V_5 -> V_125 = V_250 ;
F_6 ( V_5 , V_29 , V_251 , NULL , V_250 , NULL ) ;
}
static void F_58 ( struct V_4 * V_5 )
{
struct V_61 * V_29 = NULL ;
struct V_63 * V_64 ;
int V_9 ;
int V_250 ;
unsigned long V_16 ;
V_5 -> V_70 = 0 ;
if ( V_5 -> V_125 ) {
F_4 ( V_33 , L_60 ) ;
return;
}
F_4 ( V_33 , L_61 ) ;
V_250 = V_139 ;
if ( V_5 -> V_29 . V_68 & V_116 ) {
V_5 -> V_29 . V_68 &= ~ V_141 ;
for ( V_9 = 0 ; V_9 < V_5 -> V_78 ; ++ V_9 ) {
V_64 = V_5 -> V_64 + V_9 ;
V_29 = & V_64 -> V_29 ;
V_29 -> V_68 &=
~ ( V_173 | V_106 | V_189 ) ;
if ( V_29 -> V_2 > 0 )
V_29 -> V_68 |= V_103 ;
if ( V_29 -> V_68 & V_84 ) {
V_29 -> V_68 |= V_85 ;
V_29 -> V_68 &= ~ V_84 ;
}
}
}
if ( V_5 -> V_29 . V_68 & V_81 ) {
V_5 -> V_29 . V_68 &= ~ V_141 ;
for ( V_9 = 0 ; V_9 < V_5 -> V_78 ; ++ V_9 ) {
V_64 = V_5 -> V_64 + V_9 ;
V_29 = & V_64 -> V_29 ;
V_29 -> V_68 &=
~ ( V_173 | V_106 | V_189 ) ;
if ( V_29 -> V_2 > 0 )
V_29 -> V_68 |= V_103 ;
if ( V_5 -> V_82 == V_152 ) {
if ( V_29 -> V_68 & V_84 ) {
V_29 -> V_68 |= V_85 ;
V_29 -> V_68 &= ~ V_84 ;
}
}
}
}
F_7 ( & V_5 -> V_65 , V_16 ) ;
if ( V_5 -> V_29 . V_68 == V_69
&& ! V_5 -> V_67
&& F_50 ( & V_5 -> V_79 )
&& V_5 -> V_80 == V_153 ) {
V_250 = V_252 ;
V_29 = & V_5 -> V_29 ;
for ( V_9 = 0 ; V_9 < V_5 -> V_78 ; ++ V_9 ) {
V_64 = V_5 -> V_64 + V_9 ;
if ( V_64 -> V_29 . V_68 ||
V_64 -> V_29 . V_2 > 0 ) {
V_250 = V_139 ;
break;
}
}
}
F_12 ( & V_5 -> V_65 , V_16 ) ;
V_5 -> V_29 . V_68 &= ~ V_69 ;
if ( V_250 != V_139 ) {
F_57 ( V_5 , V_29 , V_250 ) ;
return;
}
for ( V_9 = 0 ; V_9 < V_5 -> V_78 ; ++ V_9 ) {
V_64 = V_5 -> V_64 + V_9 ;
if ( V_64 -> V_29 . V_68 & V_103 ) {
V_64 -> V_29 . V_68 &= ~ V_103 ;
if ( V_64 -> V_29 . V_68 & V_84 ) {
V_64 -> V_29 . V_68 |= V_85 ;
V_64 -> V_29 . V_68 &= ~ V_84 ;
} else {
F_57 ( V_5 , & V_64 -> V_29 , V_253 ) ;
return;
}
}
if ( V_64 -> V_29 . V_68 & V_85 ) {
V_64 -> V_29 . V_68 &= ~ V_85 ;
V_5 -> V_176 = V_64 -> V_105 ;
F_57 ( V_5 , & V_5 -> V_29 , V_254 ) ;
return;
} else if ( V_64 -> V_29 . V_68 & V_181 ) {
V_64 -> V_29 . V_68 &= ~ V_181 ;
V_5 -> V_176 = V_64 -> V_105 ;
F_57 ( V_5 , & V_5 -> V_29 , V_255 ) ;
return;
}
}
F_28 (at_state, &cs->temp_at_states, list)
if ( V_29 -> V_68 & V_103 ) {
V_29 -> V_68 &= ~ V_103 ;
F_57 ( V_5 , V_29 , V_253 ) ;
return;
}
if ( V_5 -> V_29 . V_68 & V_81 ) {
V_5 -> V_29 . V_68 &= ~ V_81 ;
V_5 -> V_60 = 0 ;
V_5 -> V_146 -> V_147 = V_148 ;
F_57 ( V_5 , & V_5 -> V_29 , V_256 ) ;
return;
}
if ( V_5 -> V_29 . V_68 & V_116 ) {
V_5 -> V_29 . V_68 &= ~ V_116 ;
F_57 ( V_5 , & V_5 -> V_29 , V_257 ) ;
return;
}
if ( V_5 -> V_29 . V_68 & V_141 ) {
V_5 -> V_29 . V_68 &= ~ V_141 ;
if ( V_5 -> V_80 == V_140 ) {
V_5 -> V_118 = 1 ;
F_57 ( V_5 , & V_5 -> V_29 , V_258 ) ;
return;
}
}
for ( V_9 = 0 ; V_9 < V_5 -> V_78 ; ++ V_9 ) {
V_64 = V_5 -> V_64 + V_9 ;
if ( V_64 -> V_29 . V_68 & V_173 ) {
V_64 -> V_29 . V_68 &= ~ V_173 ;
V_5 -> V_176 = V_64 -> V_105 ;
F_57 ( V_5 , & V_5 -> V_29 , V_259 ) ;
return;
}
if ( V_64 -> V_29 . V_68 & V_106 ) {
V_64 -> V_29 . V_68 &= ~ V_106 ;
F_57 ( V_5 , & V_64 -> V_29 , V_260 ) ;
return;
}
if ( V_64 -> V_29 . V_68 & V_189 ) {
V_64 -> V_29 . V_68 &= ~ V_189 ;
F_57 ( V_5 , & V_64 -> V_29 , V_261 ) ;
return;
}
if ( V_64 -> V_29 . V_68 & V_84 ) {
switch ( V_5 -> V_80 ) {
case V_140 :
V_5 -> V_29 . V_68 |= V_141 ;
F_4 ( V_33 , L_35 ) ;
V_5 -> V_70 = 1 ;
return;
case V_87 :
F_24 ( V_5 , V_108 ) ;
return;
}
V_64 -> V_29 . V_68 &= ~ V_84 ;
V_5 -> V_176 = V_64 -> V_105 ;
V_5 -> V_118 = 2 ;
F_57 ( V_5 , & V_5 -> V_29 , V_262 ) ;
return;
}
}
}
static void F_59 ( struct V_4 * V_5 )
{
struct V_20 * V_132 ;
unsigned V_19 , V_18 ;
int V_9 ;
int V_263 = 0 ;
int V_264 ;
unsigned long V_16 ;
F_7 ( & V_5 -> V_34 , V_16 ) ;
V_19 = V_5 -> V_35 ;
for ( V_9 = 0 ; V_9 < 2 * V_37 ; ++ V_9 ) {
V_18 = V_5 -> V_36 ;
if ( V_18 == V_19 ) {
if ( ! V_263 && ! V_5 -> V_70 )
break;
V_263 = 0 ;
F_12 ( & V_5 -> V_34 , V_16 ) ;
F_58 ( V_5 ) ;
F_7 ( & V_5 -> V_34 , V_16 ) ;
V_18 = V_5 -> V_36 ;
if ( V_18 == V_19 ) {
if ( ! V_5 -> V_70 )
break;
continue;
}
}
V_132 = V_5 -> V_38 + V_19 ;
V_264 = V_5 -> V_125 != V_139 ;
F_12 ( & V_5 -> V_34 , V_16 ) ;
F_56 ( V_5 , V_132 ) ;
F_7 ( & V_5 -> V_34 , V_16 ) ;
F_16 ( V_132 -> V_39 ) ;
V_132 -> V_39 = NULL ;
if ( V_264 && V_5 -> V_125 == V_139 )
V_263 = 1 ;
V_19 = ( V_19 + 1 ) % V_37 ;
V_5 -> V_35 = V_19 ;
}
F_12 ( & V_5 -> V_34 , V_16 ) ;
if ( V_9 == 2 * V_37 ) {
F_9 ( V_5 -> V_31 ,
L_62 ) ;
}
}
void F_60 ( unsigned long V_98 )
{
struct V_4 * V_5 = (struct V_4 * ) V_98 ;
if ( V_5 -> V_146 -> V_19 != V_5 -> V_146 -> V_18 ) {
F_4 ( V_265 , L_63 ) ;
V_5 -> V_71 -> V_266 ( V_5 -> V_146 ) ;
}
F_59 ( V_5 ) ;
}
