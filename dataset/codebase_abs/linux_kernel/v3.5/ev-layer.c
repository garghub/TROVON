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
if ( F_18 ( V_5 -> V_64 + V_9 ) >= 0 ) {
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
return - V_119 ;
for ( V_9 = 0 ; V_9 < V_5 -> V_78 ; ++ V_9 )
if ( V_5 -> V_64 [ V_9 ] . V_29 . V_2 > 0 )
return - V_120 ;
if ( V_105 < 0 )
F_5 ( V_5 -> V_31 ,
L_32 ) ;
else {
F_5 ( V_5 -> V_31 ,
L_33 ) ;
V_5 -> V_64 [ V_105 ] . V_29 . V_68 |= V_84 ;
}
F_24 ( V_5 , V_108 ) ;
return 0 ;
}
static int F_46 ( struct V_4 * V_5 ,
struct V_61 * V_121 )
{
unsigned long V_16 ;
unsigned V_105 ;
struct V_61 * V_29 ;
int V_122 = 0 ;
F_7 ( & V_5 -> V_65 , V_16 ) ;
if ( V_121 == & V_5 -> V_29 )
goto exit;
F_28 (at_state, &cs->temp_at_states, list)
if ( V_29 == V_121 )
goto exit;
for ( V_105 = 0 ; V_105 < V_5 -> V_78 ; ++ V_105 )
if ( & V_5 -> V_64 [ V_105 ] . V_29 == V_121 )
goto exit;
V_122 = 1 ;
exit:
F_12 ( & V_5 -> V_65 , V_16 ) ;
return V_122 ;
}
static void F_47 ( struct V_4 * V_5 , struct V_63 * V_64 ,
struct V_61 * * V_123 )
{
int V_122 ;
struct V_61 * V_29 = * V_123 ;
V_122 = F_48 ( V_29 ) ;
switch ( V_122 ) {
case V_124 :
break;
default:
F_9 ( V_5 -> V_31 , L_34 , V_122 ) ;
case V_125 :
case V_126 :
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
if ( V_5 -> V_127 || ! F_50 ( & V_5 -> V_79 ) ||
V_5 -> V_29 . V_68 )
return - V_120 ;
for ( V_9 = 0 ; V_9 < V_5 -> V_78 ; ++ V_9 )
if ( V_5 -> V_64 [ V_9 ] . V_29 . V_68 )
return - V_120 ;
if ( F_51 ( V_5 ) < 0 )
return - V_120 ;
break;
case V_107 :
break;
default:
return - V_120 ;
}
V_80 = V_5 -> V_80 ;
V_5 -> V_82 = V_107 ;
V_5 -> V_80 = V_87 ;
return V_80 ;
}
static int F_52 ( struct V_4 * V_5 )
{
if ( V_5 -> V_82 != V_107 )
return - V_128 ;
V_5 -> V_82 = V_83 ;
V_5 -> V_80 = V_87 ;
F_23 ( V_5 ) ;
if ( V_5 -> V_117 )
F_24 ( V_5 , V_108 ) ;
return 0 ;
}
static void F_53 ( int V_129 , struct V_4 * V_5 ,
struct V_63 * V_64 ,
struct V_61 * * V_123 , char * * V_130 ,
int * V_131 , int * V_132 ,
struct V_20 * V_133 )
{
struct V_61 * V_29 = * V_123 ;
struct V_61 * V_134 ;
unsigned long V_16 ;
int V_105 ;
unsigned char * V_1 , * V_135 ;
int V_9 ;
unsigned long V_136 ;
switch ( V_129 ) {
case V_137 :
break;
case V_138 :
V_29 -> V_110 = 1 ;
break;
case V_139 :
V_5 -> V_29 . V_68 &= ~ V_81 ;
V_5 -> V_127 = V_140 ;
V_5 -> V_80 = V_141 ;
F_7 ( & V_5 -> V_65 , V_16 ) ;
if ( ! V_5 -> V_67 ) {
F_12 ( & V_5 -> V_65 , V_16 ) ;
F_23 ( V_5 ) ;
V_5 -> V_82 = V_114 ;
break;
}
F_12 ( & V_5 -> V_65 , V_16 ) ;
V_5 -> V_29 . V_68 |= V_142 ;
F_4 ( V_33 , L_35 ) ;
V_5 -> V_70 = 1 ;
break;
case V_143 :
F_5 ( V_5 -> V_31 , L_36 ) ;
V_5 -> V_60 = 0 ;
F_22 ( V_5 , V_87 ) ;
V_5 -> V_127 = V_140 ;
break;
case V_144 :
F_22 ( V_5 , V_145 ) ;
V_5 -> V_127 = V_140 ;
break;
case V_146 :
V_5 -> V_60 = 1 ;
V_5 -> V_147 [ 0 ] . V_148 &=
~ ( V_149 | V_150 ) ;
break;
case V_151 :
V_5 -> V_60 = 0 ;
V_5 -> V_147 [ 0 ] . V_148 =
( V_5 -> V_147 [ 0 ] . V_148 & ~ V_150 )
| V_149 ;
break;
case V_152 :
if ( V_5 -> V_82 == V_108 || V_5 -> V_82 == V_153 ) {
F_23 ( V_5 ) ;
V_5 -> V_82 = V_114 ;
}
V_5 -> V_80 = V_154 ;
V_5 -> V_127 = V_140 ;
break;
case V_155 :
V_5 -> V_80 = V_141 ;
V_5 -> V_127 = V_140 ;
break;
case V_156 :
V_5 -> V_127 = V_140 ;
if ( V_5 -> V_82 == V_108 || V_5 -> V_82 == V_153 ) {
F_22 ( V_5 , V_87 ) ;
break;
}
if ( F_45 ( V_5 , - 1 ) < 0 )
F_24 ( V_5 , V_153 ) ;
break;
case V_157 :
V_5 -> V_127 = V_140 ;
F_24 ( V_5 , V_153 ) ;
break;
case V_158 :
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
case V_159 :
V_134 = F_17 ( V_5 , V_133 -> V_48 ) ;
if ( ! V_134 ) {
F_5 ( V_5 -> V_31 ,
L_38 ) ;
break;
}
V_134 -> V_160 = 700 ;
for ( V_9 = 0 ; V_9 < V_161 ; ++ V_9 ) {
F_16 ( V_134 -> V_162 [ V_9 ] ) ;
V_134 -> V_162 [ V_9 ] = NULL ;
}
V_134 -> V_163 [ V_164 ] = - 1 ;
F_7 ( & V_5 -> V_65 , V_16 ) ;
V_134 -> V_165 = V_166 ;
V_134 -> V_167 = 1 ;
F_12 ( & V_5 -> V_65 , V_16 ) ;
break;
case V_168 :
F_47 ( V_5 , V_64 , V_123 ) ;
break;
case V_169 :
F_5 ( V_5 -> V_31 , L_39 ) ;
case V_170 :
case V_171 :
V_5 -> V_127 = V_140 ;
F_41 ( V_5 ) ;
break;
case V_172 :
if ( V_5 -> V_173 ) {
V_29 -> V_68 |= V_174 ;
V_5 -> V_70 = 1 ;
break;
}
V_64 -> V_73 |= V_74 ;
F_54 ( V_64 ) ;
V_5 -> V_71 -> V_175 ( V_64 ) ;
break;
case V_176 :
V_5 -> V_127 = V_140 ;
V_64 = V_5 -> V_64 + V_5 -> V_177 ;
V_64 -> V_73 |= V_74 ;
F_54 ( V_64 ) ;
V_5 -> V_71 -> V_175 ( V_64 ) ;
break;
case V_178 :
V_29 -> V_163 [ V_179 ] = V_180 ;
case V_181 :
V_5 -> V_127 = V_140 ;
V_29 -> V_2 = - 1 ;
if ( V_64 && V_5 -> V_173 && V_5 -> V_60 ) {
V_29 -> V_68 |= V_182 ;
V_5 -> V_70 = 1 ;
} else
F_13 ( V_123 ) ;
break;
case V_183 :
V_29 -> V_163 [ V_184 ] = 0 ;
V_5 -> V_60 = 0 ;
case V_185 :
V_5 -> V_127 = V_140 ;
V_134 = & V_5 -> V_64 [ V_5 -> V_177 ] . V_29 ;
F_13 ( & V_134 ) ;
break;
case V_186 :
V_5 -> V_127 = V_140 ;
F_5 ( V_5 -> V_31 , L_40 ) ;
V_29 -> V_2 = - 1 ;
if ( V_64 && V_5 -> V_173 )
V_29 -> V_68 |= V_182 ;
else
F_13 ( V_123 ) ;
F_24 ( V_5 , V_153 ) ;
break;
case V_187 :
V_5 -> V_127 = V_140 ;
F_5 ( V_5 -> V_31 , L_41 ) ;
V_134 = & V_5 -> V_64 [ V_5 -> V_177 ] . V_29 ;
F_13 ( & V_134 ) ;
F_24 ( V_5 , V_153 ) ;
break;
case V_188 :
V_5 -> V_127 = V_140 ;
F_5 ( V_5 -> V_31 ,
L_42 ) ;
V_105 = V_5 -> V_177 ;
V_5 -> V_64 [ V_105 ] . V_29 . V_68 |= V_103 ;
V_5 -> V_70 = 1 ;
break;
case V_189 :
V_5 -> V_127 = V_140 ;
V_105 = V_5 -> V_177 ;
if ( V_133 -> V_48 > 0 && V_133 -> V_48 <= 65535 ) {
V_5 -> V_64 [ V_105 ] . V_29 . V_2 = V_133 -> V_48 ;
V_5 -> V_64 [ V_105 ] . V_29 . V_68 |=
V_190 ;
V_5 -> V_70 = 1 ;
break;
}
case V_191 :
V_5 -> V_127 = V_140 ;
V_105 = V_5 -> V_177 ;
if ( F_45 ( V_5 , V_105 ) < 0 ) {
F_5 ( V_5 -> V_31 ,
L_43 ) ;
V_134 = & V_5 -> V_64 [ V_105 ] . V_29 ;
F_13 ( & V_134 ) ;
}
break;
case V_192 :
V_5 -> V_127 = V_140 ;
V_134 = & V_5 -> V_64 [ V_5 -> V_177 ] . V_29 ;
F_13 ( & V_134 ) ;
break;
case V_193 :
case V_194 :
V_5 -> V_127 = V_140 ;
break;
case V_195 :
F_13 ( V_123 ) ;
break;
case V_196 :
V_5 -> V_127 = V_140 ;
V_29 -> V_68 |= V_103 ;
V_5 -> V_70 = 1 ;
break;
case V_197 :
case V_198 :
case V_199 :
V_29 -> V_68 |= V_103 ;
V_5 -> V_70 = 1 ;
break;
case V_200 :
V_29 -> V_30 = 1 ;
break;
case V_201 :
if ( ! V_133 -> V_39 ) {
* V_131 = 1 ;
* V_132 = V_202 ;
break;
}
V_1 = V_133 -> V_39 ;
if ( ! strcmp ( V_1 , L_44 ) ) {
* V_131 = 1 ;
* V_132 = V_45 ;
break;
}
for ( V_9 = 0 ; V_9 < 4 ; ++ V_9 ) {
V_136 = F_55 ( V_1 , ( char * * ) & V_135 , 10 ) ;
if ( V_136 > V_203 || V_135 == V_1 )
break;
if ( V_9 == 3 ) {
if ( * V_135 )
break;
} else if ( * V_135 != '.' )
break;
else
V_1 = V_135 + 1 ;
V_5 -> V_204 [ V_9 ] = V_136 ;
}
if ( V_9 != 4 ) {
* V_131 = 1 ;
* V_132 = V_202 ;
break;
}
V_5 -> V_205 = 0 ;
break;
case V_206 :
if ( V_5 -> V_205 == 0 ) {
V_5 -> V_205 = 1 ;
F_4 ( V_33 ,
L_45 ,
V_5 -> V_204 [ 0 ] , V_5 -> V_204 [ 1 ] ,
V_5 -> V_204 [ 2 ] , V_5 -> V_204 [ 3 ] ) ;
break;
}
case V_207 :
V_5 -> V_205 = - 1 ;
F_9 ( V_5 -> V_31 , L_46 ) ;
break;
case V_208 :
F_4 ( V_209 , L_47 ,
V_54 , V_29 -> V_160 ) ;
V_5 -> V_127 = V_140 ;
break;
case V_210 :
F_4 ( V_209 , L_48 ,
V_54 , V_133 -> type , V_29 -> V_160 ) ;
break;
case V_211 :
F_5 ( V_5 -> V_31 , L_49 ,
V_54 , V_133 -> type , V_29 -> V_160 ) ;
break;
case V_212 :
F_5 ( V_5 -> V_31 , L_50 ,
V_133 -> V_48 , V_29 -> V_160 ) ;
break;
case V_213 :
F_36 ( V_29 , V_133 -> V_39 , V_133 -> V_48 ) ;
break;
case V_214 :
F_37 ( V_29 ) ;
break;
case V_215 :
V_29 -> V_68 |= V_103 ;
F_4 ( V_33 , L_27 ) ;
V_5 -> V_70 = 1 ;
break;
case V_216 :
F_44 ( V_5 ) ;
break;
case V_217 :
F_38 ( V_5 ) ;
break;
case V_218 :
V_5 -> V_112 = V_133 -> V_48 ? F_49 ( V_5 ) : F_52 ( V_5 ) ;
V_5 -> V_110 = 0 ;
F_40 ( & V_5 -> V_111 ) ;
break;
case V_219 :
if ( V_133 -> V_48 != 0 )
V_5 -> V_112 = - V_128 ;
else if ( V_5 -> V_205 != 1 ) {
V_5 -> V_112 = - V_220 ;
} else {
memcpy ( V_133 -> V_40 , V_5 -> V_204 , sizeof V_5 -> V_204 ) ;
V_5 -> V_112 = 0 ;
}
V_5 -> V_110 = 0 ;
F_40 ( & V_5 -> V_111 ) ;
break;
case V_221 :
F_7 ( & V_5 -> V_65 , V_16 ) ;
if ( V_133 -> V_48 != V_5 -> V_67 ) {
V_5 -> V_67 = V_133 -> V_48 ;
if ( V_133 -> V_48 ) {
V_5 -> V_29 . V_68 |= V_142 ;
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
case V_222 :
F_29 ( V_64 ) ;
break;
case V_223 :
F_33 ( V_64 ) ;
break;
case V_224 :
F_43 ( V_5 ) ;
break;
default:
if ( V_129 >= V_225 && V_129 < V_225 + V_100 ) {
* V_130 = V_29 -> V_64 -> V_99 [ V_129 - V_225 ] ;
if ( ! * V_130 ) {
* V_131 = 1 ;
* V_132 = V_226 ;
}
} else
F_9 ( V_5 -> V_31 , L_51 , V_54 , V_129 ) ;
}
}
static void F_56 ( struct V_4 * V_5 , struct V_20 * V_133 )
{
struct V_63 * V_64 ;
char * V_227 = NULL ;
struct V_228 * V_229 ;
int V_230 ;
int V_231 = 0 ;
int V_22 = V_202 ;
int V_232 ;
struct V_61 * V_29 ;
int V_233 ;
int V_234 ;
unsigned long V_16 ;
if ( V_133 -> V_2 >= 0 ) {
V_29 = F_27 ( V_5 , V_133 -> V_2 ) ;
if ( ! V_29 ) {
F_4 ( V_33 , L_52 ,
V_133 -> type , V_133 -> V_2 ) ;
F_6 ( V_5 , & V_5 -> V_29 , V_235 ,
NULL , 0 , NULL ) ;
return;
}
} else {
V_29 = V_133 -> V_29 ;
if ( F_46 ( V_5 , V_29 ) ) {
F_4 ( V_33 , L_53 ,
V_29 ) ;
return;
}
}
F_4 ( V_33 , L_54 ,
V_29 -> V_160 , V_133 -> type ) ;
V_64 = V_29 -> V_64 ;
V_232 = V_29 -> V_2 ;
V_229 = V_29 -> V_236 ;
F_7 ( & V_5 -> V_65 , V_16 ) ;
if ( V_133 -> type == V_237 ) {
if ( V_133 -> V_48 != V_29 -> V_238
|| ! V_29 -> V_167 ) {
V_133 -> type = V_45 ;
F_4 ( V_33 , L_55 ) ;
} else if ( ! V_29 -> V_110 )
F_4 ( V_33 , L_56 ) ;
else
F_4 ( V_33 , L_57 ) ;
}
F_12 ( & V_5 -> V_65 , V_16 ) ;
if ( V_133 -> type >= V_239 && V_133 -> type < V_239 + V_240 ) {
V_233 = V_133 -> type - V_239 ;
V_29 -> V_163 [ V_233 ] = V_133 -> V_48 ;
} else if ( V_133 -> type >= V_241 && V_133 -> type < V_241 + V_161 ) {
V_233 = V_133 -> type - V_241 ;
F_16 ( V_29 -> V_162 [ V_233 ] ) ;
V_29 -> V_162 [ V_233 ] = V_133 -> V_39 ;
V_133 -> V_39 = NULL ;
}
if ( V_133 -> type == V_237 || V_133 -> type == V_41 )
V_29 -> V_30 = 0 ;
for (; ; V_229 ++ ) {
V_230 = V_229 -> V_22 ;
if ( V_230 == V_242 ) {
F_5 ( V_5 -> V_31 , L_58
L_59 ,
V_54 , V_133 -> type , V_29 -> V_160 ) ;
return;
}
if ( ( V_230 == V_243 || V_230 == V_133 -> type )
&& ( ( int ) V_29 -> V_160 >= V_229 -> V_244 )
&& ( V_229 -> V_245 < 0
|| ( int ) V_29 -> V_160 <= V_229 -> V_245 )
&& ( V_229 -> V_48 < 0 || V_229 -> V_48 == V_133 -> V_48 ) )
break;
}
V_227 = V_229 -> V_246 ;
V_29 -> V_110 = 0 ;
for ( V_234 = 0 ; V_234 < V_247 ; ++ V_234 ) {
F_53 ( V_229 -> V_129 [ V_234 ] , V_5 , V_64 , & V_29 , & V_227 ,
& V_231 , & V_22 , V_133 ) ;
if ( ! V_29 )
break;
}
if ( V_29 ) {
if ( V_229 -> V_248 >= 0 )
V_29 -> V_160 = V_229 -> V_248 ;
if ( V_231 ) {
F_7 ( & V_5 -> V_65 , V_16 ) ;
V_29 -> V_165 = 0 ;
V_29 -> V_167 = 0 ;
F_12 ( & V_5 -> V_65 , V_16 ) ;
F_6 ( V_5 , V_29 , V_22 ,
NULL , 0 , NULL ) ;
} else {
if ( V_227 ) {
if ( V_5 -> V_117 )
F_26 ( V_5 , V_227 ,
V_232 , V_5 -> V_60 ,
V_55 ) ;
else
F_6 ( V_5 , V_29 ,
V_249 ,
NULL , 0 , NULL ) ;
}
F_7 ( & V_5 -> V_65 , V_16 ) ;
if ( ! V_229 -> V_250 ) {
V_29 -> V_165 = 0 ;
V_29 -> V_167 = 0 ;
} else if ( V_229 -> V_250 > 0 ) {
V_29 -> V_165 = V_229 -> V_250 * 10 ;
V_29 -> V_167 = 1 ;
++ V_29 -> V_238 ;
}
F_12 ( & V_5 -> V_65 , V_16 ) ;
}
}
}
static void F_57 ( struct V_4 * V_5 ,
struct V_61 * V_29 , int V_251 )
{
V_5 -> V_127 = V_251 ;
F_6 ( V_5 , V_29 , V_252 , NULL , V_251 , NULL ) ;
}
static void F_58 ( struct V_4 * V_5 )
{
struct V_61 * V_29 = NULL ;
struct V_63 * V_64 ;
int V_9 ;
int V_251 ;
unsigned long V_16 ;
V_5 -> V_70 = 0 ;
if ( V_5 -> V_127 ) {
F_4 ( V_33 , L_60 ) ;
return;
}
F_4 ( V_33 , L_61 ) ;
V_251 = V_140 ;
if ( V_5 -> V_29 . V_68 & V_116 ) {
V_5 -> V_29 . V_68 &= ~ V_142 ;
for ( V_9 = 0 ; V_9 < V_5 -> V_78 ; ++ V_9 ) {
V_64 = V_5 -> V_64 + V_9 ;
V_29 = & V_64 -> V_29 ;
V_29 -> V_68 &=
~ ( V_174 | V_106 | V_190 ) ;
if ( V_29 -> V_2 > 0 )
V_29 -> V_68 |= V_103 ;
if ( V_29 -> V_68 & V_84 ) {
V_29 -> V_68 |= V_85 ;
V_29 -> V_68 &= ~ V_84 ;
}
}
}
if ( V_5 -> V_29 . V_68 & V_81 ) {
V_5 -> V_29 . V_68 &= ~ V_142 ;
for ( V_9 = 0 ; V_9 < V_5 -> V_78 ; ++ V_9 ) {
V_64 = V_5 -> V_64 + V_9 ;
V_29 = & V_64 -> V_29 ;
V_29 -> V_68 &=
~ ( V_174 | V_106 | V_190 ) ;
if ( V_29 -> V_2 > 0 )
V_29 -> V_68 |= V_103 ;
if ( V_5 -> V_82 == V_153 ) {
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
&& V_5 -> V_80 == V_154 ) {
V_251 = V_253 ;
V_29 = & V_5 -> V_29 ;
for ( V_9 = 0 ; V_9 < V_5 -> V_78 ; ++ V_9 ) {
V_64 = V_5 -> V_64 + V_9 ;
if ( V_64 -> V_29 . V_68 ||
V_64 -> V_29 . V_2 > 0 ) {
V_251 = V_140 ;
break;
}
}
}
F_12 ( & V_5 -> V_65 , V_16 ) ;
V_5 -> V_29 . V_68 &= ~ V_69 ;
if ( V_251 != V_140 ) {
F_57 ( V_5 , V_29 , V_251 ) ;
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
F_57 ( V_5 , & V_64 -> V_29 , V_254 ) ;
return;
}
}
if ( V_64 -> V_29 . V_68 & V_85 ) {
V_64 -> V_29 . V_68 &= ~ V_85 ;
V_5 -> V_177 = V_64 -> V_105 ;
F_57 ( V_5 , & V_5 -> V_29 , V_255 ) ;
return;
} else if ( V_64 -> V_29 . V_68 & V_182 ) {
V_64 -> V_29 . V_68 &= ~ V_182 ;
V_5 -> V_177 = V_64 -> V_105 ;
F_57 ( V_5 , & V_5 -> V_29 , V_256 ) ;
return;
}
}
F_28 (at_state, &cs->temp_at_states, list)
if ( V_29 -> V_68 & V_103 ) {
V_29 -> V_68 &= ~ V_103 ;
F_57 ( V_5 , V_29 , V_254 ) ;
return;
}
if ( V_5 -> V_29 . V_68 & V_81 ) {
V_5 -> V_29 . V_68 &= ~ V_81 ;
V_5 -> V_60 = 0 ;
V_5 -> V_147 -> V_148 = V_149 ;
F_57 ( V_5 , & V_5 -> V_29 , V_257 ) ;
return;
}
if ( V_5 -> V_29 . V_68 & V_116 ) {
V_5 -> V_29 . V_68 &= ~ V_116 ;
F_57 ( V_5 , & V_5 -> V_29 , V_258 ) ;
return;
}
if ( V_5 -> V_29 . V_68 & V_142 ) {
V_5 -> V_29 . V_68 &= ~ V_142 ;
if ( V_5 -> V_80 == V_141 ) {
V_5 -> V_118 = 1 ;
F_57 ( V_5 , & V_5 -> V_29 , V_259 ) ;
return;
}
}
for ( V_9 = 0 ; V_9 < V_5 -> V_78 ; ++ V_9 ) {
V_64 = V_5 -> V_64 + V_9 ;
if ( V_64 -> V_29 . V_68 & V_174 ) {
V_64 -> V_29 . V_68 &= ~ V_174 ;
V_5 -> V_177 = V_64 -> V_105 ;
F_57 ( V_5 , & V_5 -> V_29 , V_260 ) ;
return;
}
if ( V_64 -> V_29 . V_68 & V_106 ) {
V_64 -> V_29 . V_68 &= ~ V_106 ;
F_57 ( V_5 , & V_64 -> V_29 , V_261 ) ;
return;
}
if ( V_64 -> V_29 . V_68 & V_190 ) {
V_64 -> V_29 . V_68 &= ~ V_190 ;
F_57 ( V_5 , & V_64 -> V_29 , V_262 ) ;
return;
}
if ( V_64 -> V_29 . V_68 & V_84 ) {
switch ( V_5 -> V_80 ) {
case V_141 :
V_5 -> V_29 . V_68 |= V_142 ;
F_4 ( V_33 , L_35 ) ;
V_5 -> V_70 = 1 ;
return;
case V_87 :
F_24 ( V_5 , V_108 ) ;
return;
}
V_64 -> V_29 . V_68 &= ~ V_84 ;
V_5 -> V_177 = V_64 -> V_105 ;
V_5 -> V_118 = 2 ;
F_57 ( V_5 , & V_5 -> V_29 , V_263 ) ;
return;
}
}
}
static void F_59 ( struct V_4 * V_5 )
{
struct V_20 * V_133 ;
unsigned V_19 , V_18 ;
int V_9 ;
int V_264 = 0 ;
int V_265 ;
unsigned long V_16 ;
F_7 ( & V_5 -> V_34 , V_16 ) ;
V_19 = V_5 -> V_35 ;
for ( V_9 = 0 ; V_9 < 2 * V_37 ; ++ V_9 ) {
V_18 = V_5 -> V_36 ;
if ( V_18 == V_19 ) {
if ( ! V_264 && ! V_5 -> V_70 )
break;
V_264 = 0 ;
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
V_133 = V_5 -> V_38 + V_19 ;
V_265 = V_5 -> V_127 != V_140 ;
F_12 ( & V_5 -> V_34 , V_16 ) ;
F_56 ( V_5 , V_133 ) ;
F_7 ( & V_5 -> V_34 , V_16 ) ;
F_16 ( V_133 -> V_39 ) ;
V_133 -> V_39 = NULL ;
if ( V_265 && V_5 -> V_127 == V_140 )
V_264 = 1 ;
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
if ( V_5 -> V_147 -> V_19 != V_5 -> V_147 -> V_18 ) {
F_4 ( V_266 , L_63 ) ;
V_5 -> V_71 -> V_267 ( V_5 -> V_147 ) ;
}
F_59 ( V_5 ) ;
}
