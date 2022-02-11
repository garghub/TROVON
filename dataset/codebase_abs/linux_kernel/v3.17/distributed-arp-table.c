static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 . V_4 , V_5 ) ;
F_3 ( V_6 , & V_2 -> V_3 . V_4 ,
F_4 ( 10000 ) ) ;
}
static void F_5 ( struct V_7 * V_8 )
{
if ( F_6 ( & V_8 -> V_9 ) )
F_7 ( V_8 , V_10 ) ;
}
static bool F_8 ( struct V_7 * V_8 )
{
return F_9 ( V_8 -> V_11 ,
V_12 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
bool (* F_11)( struct V_7 * ) )
{
T_1 * V_13 ;
struct V_7 * V_8 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
T_2 V_18 ;
if ( ! V_2 -> V_3 . V_19 )
return;
for ( V_18 = 0 ; V_18 < V_2 -> V_3 . V_19 -> V_20 ; V_18 ++ ) {
V_17 = & V_2 -> V_3 . V_19 -> V_21 [ V_18 ] ;
V_13 = & V_2 -> V_3 . V_19 -> V_22 [ V_18 ] ;
F_12 ( V_13 ) ;
F_13 (dat_entry, node_tmp, head,
hash_entry) {
if ( F_11 && ! F_11 ( V_8 ) )
continue;
F_14 ( & V_8 -> V_23 ) ;
F_5 ( V_8 ) ;
}
F_15 ( V_13 ) ;
}
}
static void V_5 ( struct V_24 * V_4 )
{
struct V_25 * V_25 ;
struct V_26 * V_27 ;
struct V_1 * V_2 ;
V_25 = F_16 ( V_4 , struct V_25 , V_4 ) ;
V_27 = F_16 ( V_25 , struct V_26 , V_4 ) ;
V_2 = F_16 ( V_27 , struct V_1 , V_3 ) ;
F_10 ( V_2 , F_8 ) ;
F_1 ( V_2 ) ;
}
static int F_17 ( const struct V_14 * V_28 , const void * V_29 )
{
const void * V_30 = F_16 ( V_28 , struct V_7 ,
V_23 ) ;
return memcmp ( V_30 , V_29 , sizeof( V_31 ) ) == 0 ? 1 : 0 ;
}
static T_3 * F_18 ( struct V_32 * V_33 , int V_34 )
{
T_3 * V_35 ;
V_35 = ( T_3 * ) ( V_33 -> V_36 + V_34 ) ;
V_35 += V_37 + sizeof( struct V_38 ) ;
return V_35 ;
}
static V_31 F_19 ( struct V_32 * V_33 , int V_34 )
{
return * ( V_31 * ) ( F_18 ( V_33 , V_34 ) + V_39 ) ;
}
static T_3 * F_20 ( struct V_32 * V_33 , int V_34 )
{
return F_18 ( V_33 , V_34 ) + V_39 + 4 ;
}
static V_31 F_21 ( struct V_32 * V_33 , int V_34 )
{
return * ( V_31 * ) ( F_18 ( V_33 , V_34 ) + V_39 * 2 + 4 ) ;
}
static T_2 F_22 ( const void * V_36 , T_2 V_20 )
{
T_2 V_19 = 0 ;
const struct V_7 * V_3 = V_36 ;
V_19 = F_23 ( V_19 , & V_3 -> V_40 , sizeof( V_3 -> V_40 ) ) ;
V_19 = F_23 ( V_19 , & V_3 -> V_41 , sizeof( V_3 -> V_41 ) ) ;
V_19 += ( V_19 << 3 ) ;
V_19 ^= ( V_19 >> 11 ) ;
V_19 += ( V_19 << 15 ) ;
return V_19 % V_20 ;
}
static struct V_7 *
F_24 ( struct V_1 * V_2 , V_31 V_40 ,
unsigned short V_41 )
{
struct V_16 * V_17 ;
struct V_7 V_42 , * V_8 , * V_43 = NULL ;
struct V_44 * V_19 = V_2 -> V_3 . V_19 ;
T_2 V_45 ;
if ( ! V_19 )
return NULL ;
V_42 . V_40 = V_40 ;
V_42 . V_41 = V_41 ;
V_45 = F_22 ( & V_42 , V_19 -> V_20 ) ;
V_17 = & V_19 -> V_21 [ V_45 ] ;
F_25 () ;
F_26 (dat_entry, head, hash_entry) {
if ( V_8 -> V_40 != V_40 )
continue;
if ( ! F_27 ( & V_8 -> V_9 ) )
continue;
V_43 = V_8 ;
break;
}
F_28 () ;
return V_43 ;
}
static void F_29 ( struct V_1 * V_2 , V_31 V_40 ,
T_3 * V_46 , unsigned short V_41 )
{
struct V_7 * V_8 ;
int V_47 ;
V_8 = F_24 ( V_2 , V_40 , V_41 ) ;
if ( V_8 ) {
if ( ! F_30 ( V_8 -> V_46 , V_46 ) )
F_31 ( V_8 -> V_46 , V_46 ) ;
V_8 -> V_11 = V_48 ;
F_32 ( V_49 , V_2 ,
L_1 ,
& V_8 -> V_40 , V_8 -> V_46 ,
F_33 ( V_41 ) ) ;
goto V_50;
}
V_8 = F_34 ( sizeof( * V_8 ) , V_51 ) ;
if ( ! V_8 )
goto V_50;
V_8 -> V_40 = V_40 ;
V_8 -> V_41 = V_41 ;
F_31 ( V_8 -> V_46 , V_46 ) ;
V_8 -> V_11 = V_48 ;
F_35 ( & V_8 -> V_9 , 2 ) ;
V_47 = F_36 ( V_2 -> V_3 . V_19 , F_17 ,
F_22 , V_8 ,
& V_8 -> V_23 ) ;
if ( F_37 ( V_47 != 0 ) ) {
F_5 ( V_8 ) ;
goto V_50;
}
F_32 ( V_49 , V_2 , L_2 ,
& V_8 -> V_40 , V_8 -> V_46 , F_33 ( V_41 ) ) ;
V_50:
if ( V_8 )
F_5 ( V_8 ) ;
}
static void F_38 ( struct V_1 * V_2 , struct V_32 * V_33 ,
T_4 type , int V_34 , char * V_52 )
{
struct V_53 * V_54 ;
struct V_55 * V_56 ;
T_3 * V_57 ;
V_31 V_58 , V_59 ;
if ( V_52 )
F_32 ( V_49 , V_2 , L_3 , V_52 ) ;
V_58 = F_19 ( V_33 , V_34 ) ;
V_59 = F_21 ( V_33 , V_34 ) ;
F_32 ( V_49 , V_2 ,
L_4 ,
F_18 ( V_33 , V_34 ) , & V_58 ,
F_20 ( V_33 , V_34 ) , & V_59 ) ;
if ( V_34 == 0 )
return;
V_54 = (struct V_53 * ) V_33 -> V_36 ;
switch ( V_54 -> V_60 . V_61 ) {
case V_62 :
F_32 ( V_49 , V_2 ,
L_5 ) ;
break;
case V_63 :
F_32 ( V_49 , V_2 ,
L_6 ,
V_54 -> V_64 ) ;
switch ( V_54 -> V_65 ) {
case V_66 :
F_32 ( V_49 , V_2 , L_7 ) ;
break;
case V_67 :
F_32 ( V_49 , V_2 , L_8 ) ;
break;
case V_68 :
F_32 ( V_49 , V_2 ,
L_9 ) ;
break;
case V_69 :
F_32 ( V_49 , V_2 , L_10 ) ;
break;
default:
F_32 ( V_49 , V_2 , L_11 ,
V_54 -> V_60 . V_61 ) ;
}
break;
case V_70 :
V_56 = (struct V_55 * ) V_54 ;
V_57 = V_56 -> V_71 ;
F_32 ( V_49 , V_2 ,
L_12 ,
V_57 ) ;
break;
default:
F_32 ( V_49 , V_2 ,
L_13 ,
V_54 -> V_60 . V_61 ) ;
}
}
static void F_38 ( struct V_1 * V_2 , struct V_32 * V_33 ,
T_4 type , int V_34 , char * V_52 )
{
}
static bool F_39 ( struct V_72 * V_73 ,
int V_74 , T_5 V_75 ,
T_5 V_76 ,
T_5 V_77 ,
struct V_78 * V_79 ,
struct V_78 * V_80 )
{
bool V_81 = false ;
int V_82 ;
if ( ! ( V_79 -> V_83 & V_84 ) )
goto V_50;
for ( V_82 = 0 ; V_82 < V_74 ; V_82 ++ )
if ( V_73 [ V_82 ] . V_85 == V_79 )
break;
if ( V_82 < V_74 )
goto V_50;
if ( V_75 > V_77 )
goto V_50;
if ( V_75 < V_76 )
goto V_50;
if ( ( V_75 == V_76 ) && V_80 &&
( F_30 ( V_79 -> V_71 , V_80 -> V_71 ) > 0 ) )
goto V_50;
V_81 = true ;
V_50:
return V_81 ;
}
static void F_40 ( struct V_1 * V_2 ,
struct V_72 * V_86 ,
int V_74 , T_5 V_87 ,
T_5 * V_77 )
{
T_5 V_76 = 0 , V_75 = 0 ;
struct V_78 * V_85 , * V_80 = NULL ;
struct V_44 * V_19 = V_2 -> V_88 ;
struct V_16 * V_17 ;
int V_18 ;
V_86 [ V_74 ] . type = V_89 ;
for ( V_18 = 0 ; V_18 < V_19 -> V_20 ; V_18 ++ ) {
V_17 = & V_19 -> V_21 [ V_18 ] ;
F_25 () ;
F_26 (orig_node, head, hash_entry) {
V_75 = V_90 - V_85 -> V_91 +
V_87 ;
if ( ! F_39 ( V_86 , V_74 ,
V_75 , V_76 ,
* V_77 , V_85 ,
V_80 ) )
continue;
if ( ! F_27 ( & V_85 -> V_9 ) )
continue;
V_76 = V_75 ;
if ( V_80 )
F_41 ( V_80 ) ;
V_80 = V_85 ;
}
F_28 () ;
}
if ( V_80 ) {
V_86 [ V_74 ] . type = V_92 ;
V_86 [ V_74 ] . V_85 = V_80 ;
F_32 ( V_49 , V_2 ,
L_14 ,
V_74 , V_80 -> V_71 , V_80 -> V_91 ,
V_76 ) ;
}
* V_77 = V_76 ;
}
static struct V_72 *
F_42 ( struct V_1 * V_2 , V_31 V_59 )
{
int V_74 ;
T_5 V_77 = V_90 , V_87 ;
struct V_72 * V_73 ;
if ( ! V_2 -> V_88 )
return NULL ;
V_73 = F_43 ( V_93 , sizeof( * V_73 ) ,
V_51 ) ;
if ( ! V_73 )
return NULL ;
V_87 = ( T_5 ) F_22 ( & V_59 ,
V_90 ) ;
F_32 ( V_49 , V_2 ,
L_15 , & V_59 ,
V_87 ) ;
for ( V_74 = 0 ; V_74 < V_93 ; V_74 ++ )
F_40 ( V_2 , V_73 , V_74 , V_87 ,
& V_77 ) ;
return V_73 ;
}
static bool F_44 ( struct V_1 * V_2 ,
struct V_32 * V_33 , V_31 V_40 ,
int V_94 )
{
int V_18 ;
bool V_81 = false ;
int V_95 ;
struct V_96 * V_97 = NULL ;
struct V_32 * V_98 ;
struct V_72 * V_99 ;
V_99 = F_42 ( V_2 , V_40 ) ;
if ( ! V_99 )
goto V_50;
F_32 ( V_49 , V_2 , L_16 , & V_40 ) ;
for ( V_18 = 0 ; V_18 < V_93 ; V_18 ++ ) {
if ( V_99 [ V_18 ] . type == V_89 )
continue;
V_97 = F_45 ( V_99 [ V_18 ] . V_85 ,
V_100 ) ;
if ( ! V_97 )
goto V_101;
V_98 = F_46 ( V_33 , V_51 ) ;
if ( ! F_47 ( V_2 , V_98 ,
V_99 [ V_18 ] . V_85 ,
V_94 ) ) {
F_48 ( V_98 ) ;
goto V_102;
}
V_95 = F_49 ( V_98 ,
V_97 -> V_103 ,
V_97 -> V_35 ) ;
if ( V_95 == V_104 ) {
switch ( V_94 ) {
case V_67 :
F_50 ( V_2 ,
V_105 ) ;
break;
case V_66 :
F_50 ( V_2 ,
V_106 ) ;
break;
}
V_81 = true ;
}
V_102:
F_51 ( V_97 ) ;
V_101:
F_41 ( V_99 [ V_18 ] . V_85 ) ;
}
V_50:
F_52 ( V_99 ) ;
return V_81 ;
}
static void F_53 ( struct V_1 * V_2 )
{
char V_107 ;
V_107 = F_54 ( & V_2 -> V_108 ) ;
switch ( V_107 ) {
case 0 :
F_55 ( V_2 , V_109 , 1 ) ;
break;
case 1 :
F_56 ( V_2 , V_109 , 1 ,
NULL , 0 ) ;
break;
}
}
void F_57 ( struct V_110 * V_111 )
{
struct V_1 * V_2 = F_58 ( V_111 ) ;
F_53 ( V_2 ) ;
}
static void F_59 ( struct V_1 * V_2 ,
struct V_78 * V_71 ,
T_3 V_112 ,
void * V_113 ,
T_4 V_114 )
{
if ( V_112 & V_115 )
V_71 -> V_83 &= ~ V_84 ;
else
V_71 -> V_83 |= V_84 ;
}
static void F_60 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 . V_19 )
return;
F_10 ( V_2 , NULL ) ;
F_61 ( V_2 -> V_3 . V_19 ) ;
V_2 -> V_3 . V_19 = NULL ;
}
int F_62 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_19 )
return 0 ;
V_2 -> V_3 . V_19 = F_63 ( 1024 ) ;
if ( ! V_2 -> V_3 . V_19 )
return - V_116 ;
F_1 ( V_2 ) ;
F_64 ( V_2 , F_59 ,
NULL , V_109 , 1 ,
V_115 ) ;
F_53 ( V_2 ) ;
return 0 ;
}
void F_65 ( struct V_1 * V_2 )
{
F_55 ( V_2 , V_109 , 1 ) ;
F_66 ( V_2 , V_109 , 1 ) ;
F_67 ( & V_2 -> V_3 . V_4 ) ;
F_60 ( V_2 ) ;
}
int F_68 ( struct V_117 * V_118 , void * V_119 )
{
struct V_110 * V_111 = (struct V_110 * ) V_118 -> V_120 ;
struct V_1 * V_2 = F_58 ( V_111 ) ;
struct V_44 * V_19 = V_2 -> V_3 . V_19 ;
struct V_7 * V_8 ;
struct V_121 * V_122 ;
struct V_16 * V_17 ;
unsigned long V_123 ;
int V_124 , V_125 , V_126 ;
T_2 V_18 ;
V_122 = F_69 ( V_118 ) ;
if ( ! V_122 )
goto V_50;
F_70 ( V_118 , L_17 , V_111 -> V_127 ) ;
F_70 ( V_118 , L_18 , L_19 ,
L_20 , L_21 , L_22 ) ;
for ( V_18 = 0 ; V_18 < V_19 -> V_20 ; V_18 ++ ) {
V_17 = & V_19 -> V_21 [ V_18 ] ;
F_25 () ;
F_26 (dat_entry, head, hash_entry) {
V_123 = V_48 - V_8 -> V_11 ;
V_124 = F_71 ( V_123 ) ;
V_126 = V_124 / 60000 ;
V_124 = V_124 % 60000 ;
V_125 = V_124 / 1000 ;
F_70 ( V_118 , L_23 ,
& V_8 -> V_40 , V_8 -> V_46 ,
F_33 ( V_8 -> V_41 ) ,
V_126 , V_125 ) ;
}
F_28 () ;
}
V_50:
if ( V_122 )
F_72 ( V_122 ) ;
return 0 ;
}
static T_4 F_73 ( struct V_1 * V_2 ,
struct V_32 * V_33 , int V_34 )
{
struct V_38 * V_38 ;
struct V_128 * V_128 ;
V_31 V_58 , V_59 ;
T_3 * V_129 , * V_130 ;
T_4 type = 0 ;
if ( F_37 ( ! F_74 ( V_33 , V_34 + V_37 ) ) )
goto V_50;
V_128 = (struct V_128 * ) ( V_33 -> V_36 + V_34 ) ;
if ( V_128 -> V_131 != F_75 ( V_132 ) )
goto V_50;
if ( F_37 ( ! F_74 ( V_33 , V_34 + V_37 +
F_76 ( V_33 -> V_133 ) ) ) )
goto V_50;
V_38 = (struct V_38 * ) ( V_33 -> V_36 + V_34 + V_37 ) ;
if ( V_38 -> V_134 != F_75 ( V_135 ) )
goto V_50;
if ( V_38 -> V_136 != F_75 ( V_137 ) )
goto V_50;
if ( V_38 -> V_138 != V_39 )
goto V_50;
if ( V_38 -> V_139 != 4 )
goto V_50;
V_58 = F_19 ( V_33 , V_34 ) ;
V_59 = F_21 ( V_33 , V_34 ) ;
if ( F_77 ( V_58 ) || F_78 ( V_58 ) ||
F_77 ( V_59 ) || F_78 ( V_59 ) ||
F_79 ( V_58 ) || F_80 ( V_58 ) ||
F_79 ( V_59 ) || F_80 ( V_59 ) )
goto V_50;
V_129 = F_18 ( V_33 , V_34 ) ;
if ( F_81 ( V_129 ) || F_82 ( V_129 ) )
goto V_50;
if ( V_38 -> V_140 != F_75 ( V_141 ) ) {
V_130 = F_20 ( V_33 , V_34 ) ;
if ( F_81 ( V_130 ) ||
F_82 ( V_130 ) )
goto V_50;
}
type = F_83 ( V_38 -> V_140 ) ;
V_50:
return type ;
}
static unsigned short F_84 ( struct V_32 * V_33 , int * V_34 )
{
unsigned short V_41 ;
V_41 = F_85 ( V_33 , * V_34 ) ;
if ( V_41 & V_142 )
* V_34 += V_143 ;
return V_41 ;
}
bool F_86 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
T_4 type = 0 ;
V_31 V_59 , V_58 ;
T_3 * V_129 ;
bool V_81 = false ;
struct V_7 * V_8 = NULL ;
struct V_32 * V_144 ;
int V_34 = 0 ;
unsigned short V_41 ;
if ( ! F_54 ( & V_2 -> V_108 ) )
goto V_50;
V_41 = F_84 ( V_33 , & V_34 ) ;
type = F_73 ( V_2 , V_33 , V_34 ) ;
if ( type != V_141 )
goto V_50;
F_38 ( V_2 , V_33 , type , V_34 ,
L_24 ) ;
V_58 = F_19 ( V_33 , V_34 ) ;
V_129 = F_18 ( V_33 , V_34 ) ;
V_59 = F_21 ( V_33 , V_34 ) ;
F_29 ( V_2 , V_58 , V_129 , V_41 ) ;
V_8 = F_24 ( V_2 , V_59 , V_41 ) ;
if ( V_8 ) {
if ( F_87 ( V_2 , V_8 -> V_46 , V_41 ) ) {
V_81 = true ;
goto V_50;
}
V_144 = F_88 ( V_145 , V_132 , V_58 ,
V_2 -> V_146 , V_59 , V_129 ,
V_8 -> V_46 , V_129 ) ;
if ( ! V_144 )
goto V_50;
if ( V_41 & V_142 )
V_144 = F_89 ( V_144 , F_75 ( V_147 ) ,
V_41 & V_148 ) ;
F_90 ( V_144 ) ;
V_144 -> V_149 = F_91 ( V_144 ,
V_2 -> V_146 ) ;
V_2 -> V_150 . V_151 ++ ;
V_2 -> V_150 . V_152 += V_33 -> V_153 + V_37 + V_34 ;
V_2 -> V_146 -> V_154 = V_48 ;
F_92 ( V_144 ) ;
F_32 ( V_49 , V_2 , L_25 ) ;
V_81 = true ;
} else {
V_81 = F_44 ( V_2 , V_33 , V_59 ,
V_67 ) ;
}
V_50:
if ( V_8 )
F_5 ( V_8 ) ;
return V_81 ;
}
bool F_93 ( struct V_1 * V_2 ,
struct V_32 * V_33 , int V_34 )
{
T_4 type ;
V_31 V_58 , V_59 ;
T_3 * V_129 ;
struct V_32 * V_144 ;
struct V_7 * V_8 = NULL ;
bool V_81 = false ;
unsigned short V_41 ;
int V_155 ;
if ( ! F_54 ( & V_2 -> V_108 ) )
goto V_50;
V_41 = F_84 ( V_33 , & V_34 ) ;
type = F_73 ( V_2 , V_33 , V_34 ) ;
if ( type != V_141 )
goto V_50;
V_129 = F_18 ( V_33 , V_34 ) ;
V_58 = F_19 ( V_33 , V_34 ) ;
V_59 = F_21 ( V_33 , V_34 ) ;
F_38 ( V_2 , V_33 , type , V_34 ,
L_26 ) ;
F_29 ( V_2 , V_58 , V_129 , V_41 ) ;
V_8 = F_24 ( V_2 , V_59 , V_41 ) ;
if ( ! V_8 )
goto V_50;
V_144 = F_88 ( V_145 , V_132 , V_58 ,
V_2 -> V_146 , V_59 , V_129 ,
V_8 -> V_46 , V_129 ) ;
if ( ! V_144 )
goto V_50;
F_90 ( V_144 ) ;
if ( V_41 & V_142 )
V_144 = F_89 ( V_144 , F_75 ( V_147 ) ,
V_41 & V_148 ) ;
if ( V_34 == sizeof( struct V_53 ) )
V_155 = F_94 ( V_2 , V_144 ,
V_68 ,
NULL , V_41 ) ;
else
V_155 = F_95 ( V_2 , V_144 , NULL , V_41 ) ;
if ( V_155 != V_156 ) {
F_50 ( V_2 , V_157 ) ;
V_81 = true ;
}
V_50:
if ( V_8 )
F_5 ( V_8 ) ;
if ( V_81 )
F_48 ( V_33 ) ;
return V_81 ;
}
void F_96 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
T_4 type ;
V_31 V_58 , V_59 ;
T_3 * V_129 , * V_130 ;
int V_34 = 0 ;
unsigned short V_41 ;
if ( ! F_54 ( & V_2 -> V_108 ) )
return;
V_41 = F_84 ( V_33 , & V_34 ) ;
type = F_73 ( V_2 , V_33 , V_34 ) ;
if ( type != V_145 )
return;
F_38 ( V_2 , V_33 , type , V_34 ,
L_27 ) ;
V_129 = F_18 ( V_33 , V_34 ) ;
V_58 = F_19 ( V_33 , V_34 ) ;
V_130 = F_20 ( V_33 , V_34 ) ;
V_59 = F_21 ( V_33 , V_34 ) ;
F_29 ( V_2 , V_58 , V_129 , V_41 ) ;
F_29 ( V_2 , V_59 , V_130 , V_41 ) ;
F_44 ( V_2 , V_33 , V_58 , V_66 ) ;
F_44 ( V_2 , V_33 , V_59 , V_66 ) ;
}
bool F_97 ( struct V_1 * V_2 ,
struct V_32 * V_33 , int V_34 )
{
T_4 type ;
V_31 V_58 , V_59 ;
T_3 * V_129 , * V_130 ;
bool V_81 = false ;
unsigned short V_41 ;
if ( ! F_54 ( & V_2 -> V_108 ) )
goto V_50;
V_41 = F_84 ( V_33 , & V_34 ) ;
type = F_73 ( V_2 , V_33 , V_34 ) ;
if ( type != V_145 )
goto V_50;
F_38 ( V_2 , V_33 , type , V_34 ,
L_28 ) ;
V_129 = F_18 ( V_33 , V_34 ) ;
V_58 = F_19 ( V_33 , V_34 ) ;
V_130 = F_20 ( V_33 , V_34 ) ;
V_59 = F_21 ( V_33 , V_34 ) ;
F_29 ( V_2 , V_58 , V_129 , V_41 ) ;
F_29 ( V_2 , V_59 , V_130 , V_41 ) ;
V_81 = ! F_87 ( V_2 , V_130 , V_41 ) ;
V_50:
if ( V_81 )
F_48 ( V_33 ) ;
return V_81 ;
}
bool F_98 ( struct V_1 * V_2 ,
struct V_158 * V_159 )
{
T_4 type ;
V_31 V_59 ;
struct V_7 * V_8 = NULL ;
bool V_81 = false ;
int V_34 = sizeof( struct V_55 ) ;
unsigned short V_41 ;
if ( ! F_54 ( & V_2 -> V_108 ) )
goto V_50;
if ( V_159 -> V_160 )
goto V_50;
V_41 = F_84 ( V_159 -> V_33 , & V_34 ) ;
type = F_73 ( V_2 , V_159 -> V_33 , V_34 ) ;
if ( type != V_141 )
goto V_50;
V_59 = F_21 ( V_159 -> V_33 , V_34 ) ;
V_8 = F_24 ( V_2 , V_59 , V_41 ) ;
if ( ! V_8 ) {
F_32 ( V_49 , V_2 ,
L_29 , & V_59 ) ;
goto V_50;
}
F_32 ( V_49 , V_2 ,
L_30 , & V_59 ) ;
V_81 = true ;
V_50:
if ( V_8 )
F_5 ( V_8 ) ;
return V_81 ;
}
