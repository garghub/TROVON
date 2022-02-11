static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 . V_4 , V_5 ) ;
F_3 ( V_6 , & V_2 -> V_3 . V_4 ,
F_4 ( 10000 ) ) ;
}
static void F_5 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
V_10 = F_6 ( V_8 , struct V_9 , V_11 ) ;
F_7 ( V_10 , V_12 ) ;
}
static void F_8 ( struct V_9 * V_10 )
{
F_9 ( & V_10 -> V_11 , F_5 ) ;
}
static bool F_10 ( struct V_9 * V_10 )
{
return F_11 ( V_10 -> V_13 ,
V_14 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
bool (* F_13)( struct V_9 * ) )
{
T_1 * V_15 ;
struct V_9 * V_10 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
T_2 V_20 ;
if ( ! V_2 -> V_3 . V_21 )
return;
for ( V_20 = 0 ; V_20 < V_2 -> V_3 . V_21 -> V_22 ; V_20 ++ ) {
V_19 = & V_2 -> V_3 . V_21 -> V_23 [ V_20 ] ;
V_15 = & V_2 -> V_3 . V_21 -> V_24 [ V_20 ] ;
F_14 ( V_15 ) ;
F_15 (dat_entry, node_tmp, head,
hash_entry) {
if ( F_13 && ! F_13 ( V_10 ) )
continue;
F_16 ( & V_10 -> V_25 ) ;
F_8 ( V_10 ) ;
}
F_17 ( V_15 ) ;
}
}
static void V_5 ( struct V_26 * V_4 )
{
struct V_27 * V_27 ;
struct V_28 * V_29 ;
struct V_1 * V_2 ;
V_27 = F_18 ( V_4 ) ;
V_29 = F_6 ( V_27 , struct V_28 , V_4 ) ;
V_2 = F_6 ( V_29 , struct V_1 , V_3 ) ;
F_12 ( V_2 , F_10 ) ;
F_1 ( V_2 ) ;
}
static bool F_19 ( const struct V_16 * V_30 , const void * V_31 )
{
const void * V_32 = F_6 ( V_30 , struct V_9 ,
V_25 ) ;
return memcmp ( V_32 , V_31 , sizeof( V_33 ) ) == 0 ;
}
static T_3 * F_20 ( struct V_34 * V_35 , int V_36 )
{
T_3 * V_37 ;
V_37 = ( T_3 * ) ( V_35 -> V_38 + V_36 ) ;
V_37 += V_39 + sizeof( struct V_40 ) ;
return V_37 ;
}
static V_33 F_21 ( struct V_34 * V_35 , int V_36 )
{
return * ( V_33 * ) ( F_20 ( V_35 , V_36 ) + V_41 ) ;
}
static T_3 * F_22 ( struct V_34 * V_35 , int V_36 )
{
return F_20 ( V_35 , V_36 ) + V_41 + 4 ;
}
static V_33 F_23 ( struct V_34 * V_35 , int V_36 )
{
return * ( V_33 * ) ( F_20 ( V_35 , V_36 ) + V_41 * 2 + 4 ) ;
}
static T_2 F_24 ( const void * V_38 , T_2 V_22 )
{
T_2 V_21 = 0 ;
const struct V_9 * V_3 = V_38 ;
const unsigned char * V_42 ;
T_2 V_20 ;
V_42 = ( const unsigned char * ) & V_3 -> V_43 ;
for ( V_20 = 0 ; V_20 < sizeof( V_3 -> V_43 ) ; V_20 ++ ) {
V_21 += V_42 [ V_20 ] ;
V_21 += ( V_21 << 10 ) ;
V_21 ^= ( V_21 >> 6 ) ;
}
V_42 = ( const unsigned char * ) & V_3 -> V_44 ;
for ( V_20 = 0 ; V_20 < sizeof( V_3 -> V_44 ) ; V_20 ++ ) {
V_21 += V_42 [ V_20 ] ;
V_21 += ( V_21 << 10 ) ;
V_21 ^= ( V_21 >> 6 ) ;
}
V_21 += ( V_21 << 3 ) ;
V_21 ^= ( V_21 >> 11 ) ;
V_21 += ( V_21 << 15 ) ;
return V_21 % V_22 ;
}
static struct V_9 *
F_25 ( struct V_1 * V_2 , V_33 V_43 ,
unsigned short V_44 )
{
struct V_18 * V_19 ;
struct V_9 V_45 , * V_10 , * V_46 = NULL ;
struct V_47 * V_21 = V_2 -> V_3 . V_21 ;
T_2 V_48 ;
if ( ! V_21 )
return NULL ;
V_45 . V_43 = V_43 ;
V_45 . V_44 = V_44 ;
V_48 = F_24 ( & V_45 , V_21 -> V_22 ) ;
V_19 = & V_21 -> V_23 [ V_48 ] ;
F_26 () ;
F_27 (dat_entry, head, hash_entry) {
if ( V_10 -> V_43 != V_43 )
continue;
if ( ! F_28 ( & V_10 -> V_11 ) )
continue;
V_46 = V_10 ;
break;
}
F_29 () ;
return V_46 ;
}
static void F_30 ( struct V_1 * V_2 , V_33 V_43 ,
T_3 * V_49 , unsigned short V_44 )
{
struct V_9 * V_10 ;
int V_50 ;
V_10 = F_25 ( V_2 , V_43 , V_44 ) ;
if ( V_10 ) {
if ( ! F_31 ( V_10 -> V_49 , V_49 ) )
F_32 ( V_10 -> V_49 , V_49 ) ;
V_10 -> V_13 = V_51 ;
F_33 ( V_52 , V_2 ,
L_1 ,
& V_10 -> V_43 , V_10 -> V_49 ,
F_34 ( V_44 ) ) ;
goto V_53;
}
V_10 = F_35 ( sizeof( * V_10 ) , V_54 ) ;
if ( ! V_10 )
goto V_53;
V_10 -> V_43 = V_43 ;
V_10 -> V_44 = V_44 ;
F_32 ( V_10 -> V_49 , V_49 ) ;
V_10 -> V_13 = V_51 ;
F_36 ( & V_10 -> V_11 ) ;
F_37 ( & V_10 -> V_11 ) ;
V_50 = F_38 ( V_2 -> V_3 . V_21 , F_19 ,
F_24 , V_10 ,
& V_10 -> V_25 ) ;
if ( F_39 ( V_50 != 0 ) ) {
F_8 ( V_10 ) ;
goto V_53;
}
F_33 ( V_52 , V_2 , L_2 ,
& V_10 -> V_43 , V_10 -> V_49 , F_34 ( V_44 ) ) ;
V_53:
if ( V_10 )
F_8 ( V_10 ) ;
}
static void F_40 ( struct V_1 * V_2 , struct V_34 * V_35 ,
int V_36 , char * V_55 )
{
struct V_56 * V_57 ;
struct V_58 * V_59 ;
T_3 * V_60 ;
V_33 V_61 , V_62 ;
if ( V_55 )
F_33 ( V_52 , V_2 , L_3 , V_55 ) ;
V_61 = F_21 ( V_35 , V_36 ) ;
V_62 = F_23 ( V_35 , V_36 ) ;
F_33 ( V_52 , V_2 ,
L_4 ,
F_20 ( V_35 , V_36 ) , & V_61 ,
F_22 ( V_35 , V_36 ) , & V_62 ) ;
if ( V_36 == 0 )
return;
V_57 = (struct V_56 * ) V_35 -> V_38 ;
switch ( V_57 -> V_63 . V_64 ) {
case V_65 :
F_33 ( V_52 , V_2 ,
L_5 ) ;
break;
case V_66 :
F_33 ( V_52 , V_2 ,
L_6 ,
V_57 -> V_67 ) ;
switch ( V_57 -> V_68 ) {
case V_69 :
F_33 ( V_52 , V_2 , L_7 ) ;
break;
case V_70 :
F_33 ( V_52 , V_2 , L_8 ) ;
break;
case V_71 :
F_33 ( V_52 , V_2 ,
L_9 ) ;
break;
case V_72 :
F_33 ( V_52 , V_2 , L_10 ) ;
break;
default:
F_33 ( V_52 , V_2 , L_11 ,
V_57 -> V_63 . V_64 ) ;
}
break;
case V_73 :
V_59 = (struct V_58 * ) V_57 ;
V_60 = V_59 -> V_74 ;
F_33 ( V_52 , V_2 ,
L_12 ,
V_60 ) ;
break;
default:
F_33 ( V_52 , V_2 ,
L_13 ,
V_57 -> V_63 . V_64 ) ;
}
}
static void F_40 ( struct V_1 * V_2 , struct V_34 * V_35 ,
int V_36 , char * V_55 )
{
}
static bool F_41 ( struct V_75 * V_76 ,
int V_77 , T_4 V_78 ,
T_4 V_79 ,
T_4 V_80 ,
struct V_81 * V_82 ,
struct V_81 * V_83 )
{
bool V_84 = false ;
int V_85 ;
if ( ! F_42 ( V_86 , & V_82 -> V_87 ) )
goto V_53;
for ( V_85 = 0 ; V_85 < V_77 ; V_85 ++ )
if ( V_76 [ V_85 ] . V_88 == V_82 )
break;
if ( V_85 < V_77 )
goto V_53;
if ( V_78 > V_80 )
goto V_53;
if ( V_78 < V_79 )
goto V_53;
if ( ( V_78 == V_79 ) && V_83 &&
( F_31 ( V_82 -> V_74 , V_83 -> V_74 ) > 0 ) )
goto V_53;
V_84 = true ;
V_53:
return V_84 ;
}
static void F_43 ( struct V_1 * V_2 ,
struct V_75 * V_89 ,
int V_77 , T_4 V_90 ,
T_4 * V_80 )
{
T_4 V_79 = 0 ;
T_4 V_78 = 0 ;
struct V_81 * V_88 , * V_83 = NULL ;
struct V_47 * V_21 = V_2 -> V_91 ;
struct V_18 * V_19 ;
int V_20 ;
V_89 [ V_77 ] . type = V_92 ;
for ( V_20 = 0 ; V_20 < V_21 -> V_22 ; V_20 ++ ) {
V_19 = & V_21 -> V_23 [ V_20 ] ;
F_26 () ;
F_27 (orig_node, head, hash_entry) {
V_78 = V_93 - V_88 -> V_94 +
V_90 ;
if ( ! F_41 ( V_89 , V_77 ,
V_78 , V_79 ,
* V_80 , V_88 ,
V_83 ) )
continue;
if ( ! F_28 ( & V_88 -> V_11 ) )
continue;
V_79 = V_78 ;
if ( V_83 )
F_44 ( V_83 ) ;
V_83 = V_88 ;
}
F_29 () ;
}
if ( V_83 ) {
V_89 [ V_77 ] . type = V_95 ;
V_89 [ V_77 ] . V_88 = V_83 ;
F_33 ( V_52 , V_2 ,
L_14 ,
V_77 , V_83 -> V_74 , V_83 -> V_94 ,
V_79 ) ;
}
* V_80 = V_79 ;
}
static struct V_75 *
F_45 ( struct V_1 * V_2 , V_33 V_62 ,
unsigned short V_44 )
{
int V_77 ;
T_4 V_80 = V_93 , V_90 ;
struct V_75 * V_76 ;
struct V_9 V_3 ;
if ( ! V_2 -> V_91 )
return NULL ;
V_76 = F_46 ( V_96 , sizeof( * V_76 ) ,
V_54 ) ;
if ( ! V_76 )
return NULL ;
V_3 . V_43 = V_62 ;
V_3 . V_44 = V_44 ;
V_90 = ( T_4 ) F_24 ( & V_3 ,
V_93 ) ;
F_33 ( V_52 , V_2 ,
L_15 , & V_62 ,
V_90 ) ;
for ( V_77 = 0 ; V_77 < V_96 ; V_77 ++ )
F_43 ( V_2 , V_76 , V_77 , V_90 ,
& V_80 ) ;
return V_76 ;
}
static bool F_47 ( struct V_1 * V_2 ,
struct V_34 * V_35 , V_33 V_43 ,
unsigned short V_44 , int V_97 )
{
int V_20 ;
bool V_84 = false ;
int V_98 ;
struct V_99 * V_100 = NULL ;
struct V_34 * V_101 ;
struct V_75 * V_102 ;
V_102 = F_45 ( V_2 , V_43 , V_44 ) ;
if ( ! V_102 )
goto V_53;
F_33 ( V_52 , V_2 , L_16 , & V_43 ) ;
for ( V_20 = 0 ; V_20 < V_96 ; V_20 ++ ) {
if ( V_102 [ V_20 ] . type == V_92 )
continue;
V_100 = F_48 ( V_102 [ V_20 ] . V_88 ,
V_103 ) ;
if ( ! V_100 )
goto V_104;
V_101 = F_49 ( V_35 , V_54 ) ;
if ( ! F_50 ( V_2 , V_101 ,
V_102 [ V_20 ] . V_88 ,
V_97 ) ) {
F_51 ( V_101 ) ;
goto V_105;
}
V_98 = F_52 ( V_101 , V_100 ) ;
if ( V_98 == V_106 ) {
switch ( V_97 ) {
case V_70 :
F_53 ( V_2 ,
V_107 ) ;
break;
case V_69 :
F_53 ( V_2 ,
V_108 ) ;
break;
}
V_84 = true ;
}
V_105:
F_54 ( V_100 ) ;
V_104:
F_44 ( V_102 [ V_20 ] . V_88 ) ;
}
V_53:
F_55 ( V_102 ) ;
return V_84 ;
}
static void F_56 ( struct V_1 * V_2 )
{
char V_109 ;
V_109 = F_57 ( & V_2 -> V_110 ) ;
switch ( V_109 ) {
case 0 :
F_58 ( V_2 , V_111 , 1 ) ;
break;
case 1 :
F_59 ( V_2 , V_111 , 1 ,
NULL , 0 ) ;
break;
}
}
void F_60 ( struct V_112 * V_113 )
{
struct V_1 * V_2 = F_61 ( V_113 ) ;
F_56 ( V_2 ) ;
}
static void F_62 ( struct V_1 * V_2 ,
struct V_81 * V_74 ,
T_3 V_114 ,
void * V_115 , T_5 V_116 )
{
if ( V_114 & V_117 )
F_63 ( V_86 , & V_74 -> V_87 ) ;
else
F_64 ( V_86 , & V_74 -> V_87 ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 . V_21 )
return;
F_12 ( V_2 , NULL ) ;
F_66 ( V_2 -> V_3 . V_21 ) ;
V_2 -> V_3 . V_21 = NULL ;
}
int F_67 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_21 )
return 0 ;
V_2 -> V_3 . V_21 = F_68 ( 1024 ) ;
if ( ! V_2 -> V_3 . V_21 )
return - V_118 ;
F_1 ( V_2 ) ;
F_69 ( V_2 , F_62 ,
NULL , V_111 , 1 ,
V_117 ) ;
F_56 ( V_2 ) ;
return 0 ;
}
void F_70 ( struct V_1 * V_2 )
{
F_58 ( V_2 , V_111 , 1 ) ;
F_71 ( V_2 , V_111 , 1 ) ;
F_72 ( & V_2 -> V_3 . V_4 ) ;
F_65 ( V_2 ) ;
}
int F_73 ( struct V_119 * V_120 , void * V_121 )
{
struct V_112 * V_113 = (struct V_112 * ) V_120 -> V_122 ;
struct V_1 * V_2 = F_61 ( V_113 ) ;
struct V_47 * V_21 = V_2 -> V_3 . V_21 ;
struct V_9 * V_10 ;
struct V_123 * V_124 ;
struct V_18 * V_19 ;
unsigned long V_125 ;
int V_126 , V_127 , V_128 ;
T_2 V_20 ;
V_124 = F_74 ( V_120 ) ;
if ( ! V_124 )
goto V_53;
F_75 ( V_120 , L_17 , V_113 -> V_129 ) ;
F_76 ( V_120 ,
L_18 ) ;
for ( V_20 = 0 ; V_20 < V_21 -> V_22 ; V_20 ++ ) {
V_19 = & V_21 -> V_23 [ V_20 ] ;
F_26 () ;
F_27 (dat_entry, head, hash_entry) {
V_125 = V_51 - V_10 -> V_13 ;
V_126 = F_77 ( V_125 ) ;
V_128 = V_126 / 60000 ;
V_126 = V_126 % 60000 ;
V_127 = V_126 / 1000 ;
F_75 ( V_120 , L_19 ,
& V_10 -> V_43 , V_10 -> V_49 ,
F_34 ( V_10 -> V_44 ) ,
V_128 , V_127 ) ;
}
F_29 () ;
}
V_53:
if ( V_124 )
F_78 ( V_124 ) ;
return 0 ;
}
static T_5 F_79 ( struct V_1 * V_2 ,
struct V_34 * V_35 , int V_36 )
{
struct V_40 * V_40 ;
struct V_130 * V_130 ;
V_33 V_61 , V_62 ;
T_3 * V_131 , * V_132 ;
T_5 type = 0 ;
if ( F_39 ( ! F_80 ( V_35 , V_36 + V_39 ) ) )
goto V_53;
V_130 = (struct V_130 * ) ( V_35 -> V_38 + V_36 ) ;
if ( V_130 -> V_133 != F_81 ( V_134 ) )
goto V_53;
if ( F_39 ( ! F_80 ( V_35 , V_36 + V_39 +
F_82 ( V_35 -> V_135 ) ) ) )
goto V_53;
V_40 = (struct V_40 * ) ( V_35 -> V_38 + V_36 + V_39 ) ;
if ( V_40 -> V_136 != F_81 ( V_137 ) )
goto V_53;
if ( V_40 -> V_138 != F_81 ( V_139 ) )
goto V_53;
if ( V_40 -> V_140 != V_41 )
goto V_53;
if ( V_40 -> V_141 != 4 )
goto V_53;
V_61 = F_21 ( V_35 , V_36 ) ;
V_62 = F_23 ( V_35 , V_36 ) ;
if ( F_83 ( V_61 ) || F_84 ( V_61 ) ||
F_83 ( V_62 ) || F_84 ( V_62 ) ||
F_85 ( V_61 ) || F_86 ( V_61 ) ||
F_85 ( V_62 ) || F_86 ( V_62 ) )
goto V_53;
V_131 = F_20 ( V_35 , V_36 ) ;
if ( F_87 ( V_131 ) || F_88 ( V_131 ) )
goto V_53;
if ( V_40 -> V_142 != F_81 ( V_143 ) ) {
V_132 = F_22 ( V_35 , V_36 ) ;
if ( F_87 ( V_132 ) ||
F_88 ( V_132 ) )
goto V_53;
}
type = F_89 ( V_40 -> V_142 ) ;
V_53:
return type ;
}
static unsigned short F_90 ( struct V_34 * V_35 , int * V_36 )
{
unsigned short V_44 ;
V_44 = F_91 ( V_35 , * V_36 ) ;
if ( V_44 & V_144 )
* V_36 += V_145 ;
return V_44 ;
}
static struct V_34 *
F_92 ( struct V_1 * V_2 , V_33 V_61 ,
V_33 V_62 , T_3 * V_131 , T_3 * V_132 ,
unsigned short V_44 )
{
struct V_34 * V_35 ;
V_35 = F_93 ( V_146 , V_134 , V_62 , V_2 -> V_147 ,
V_61 , V_132 , V_131 , V_132 ) ;
if ( ! V_35 )
return NULL ;
F_94 ( V_35 ) ;
if ( V_44 & V_144 )
V_35 = F_95 ( V_35 , F_81 ( V_148 ) ,
V_44 & V_149 ) ;
return V_35 ;
}
bool F_96 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
T_5 type = 0 ;
V_33 V_62 , V_61 ;
T_3 * V_131 ;
bool V_84 = false ;
struct V_9 * V_10 = NULL ;
struct V_34 * V_150 ;
int V_36 = 0 ;
unsigned short V_44 ;
if ( ! F_57 ( & V_2 -> V_110 ) )
goto V_53;
V_44 = F_90 ( V_35 , & V_36 ) ;
type = F_79 ( V_2 , V_35 , V_36 ) ;
if ( type != V_143 )
goto V_53;
F_40 ( V_2 , V_35 , V_36 , L_20 ) ;
V_61 = F_21 ( V_35 , V_36 ) ;
V_131 = F_20 ( V_35 , V_36 ) ;
V_62 = F_23 ( V_35 , V_36 ) ;
F_30 ( V_2 , V_61 , V_131 , V_44 ) ;
V_10 = F_25 ( V_2 , V_62 , V_44 ) ;
if ( V_10 ) {
if ( F_97 ( V_2 , V_10 -> V_49 , V_44 ) ) {
V_84 = true ;
goto V_53;
}
V_150 = F_92 ( V_2 , V_62 , V_61 ,
V_10 -> V_49 ,
V_131 , V_44 ) ;
if ( ! V_150 )
goto V_53;
V_150 -> V_151 = F_98 ( V_150 ,
V_2 -> V_147 ) ;
V_2 -> V_152 . V_153 ++ ;
V_2 -> V_152 . V_154 += V_35 -> V_155 + V_39 + V_36 ;
V_2 -> V_147 -> V_156 = V_51 ;
F_99 ( V_150 ) ;
F_33 ( V_52 , V_2 , L_21 ) ;
V_84 = true ;
} else {
V_84 = F_47 ( V_2 , V_35 , V_62 , V_44 ,
V_70 ) ;
}
V_53:
if ( V_10 )
F_8 ( V_10 ) ;
return V_84 ;
}
bool F_100 ( struct V_1 * V_2 ,
struct V_34 * V_35 , int V_36 )
{
T_5 type ;
V_33 V_61 , V_62 ;
T_3 * V_131 ;
struct V_34 * V_150 ;
struct V_9 * V_10 = NULL ;
bool V_84 = false ;
unsigned short V_44 ;
int V_157 ;
if ( ! F_57 ( & V_2 -> V_110 ) )
goto V_53;
V_44 = F_90 ( V_35 , & V_36 ) ;
type = F_79 ( V_2 , V_35 , V_36 ) ;
if ( type != V_143 )
goto V_53;
V_131 = F_20 ( V_35 , V_36 ) ;
V_61 = F_21 ( V_35 , V_36 ) ;
V_62 = F_23 ( V_35 , V_36 ) ;
F_40 ( V_2 , V_35 , V_36 , L_22 ) ;
F_30 ( V_2 , V_61 , V_131 , V_44 ) ;
V_10 = F_25 ( V_2 , V_62 , V_44 ) ;
if ( ! V_10 )
goto V_53;
V_150 = F_92 ( V_2 , V_62 , V_61 ,
V_10 -> V_49 , V_131 , V_44 ) ;
if ( ! V_150 )
goto V_53;
if ( V_36 == sizeof( struct V_56 ) )
V_157 = F_101 ( V_2 , V_150 ,
V_71 ,
NULL , V_44 ) ;
else
V_157 = F_102 ( V_2 , V_150 , NULL , V_44 ) ;
if ( V_157 != V_158 ) {
F_53 ( V_2 , V_159 ) ;
V_84 = true ;
}
V_53:
if ( V_10 )
F_8 ( V_10 ) ;
if ( V_84 )
F_51 ( V_35 ) ;
return V_84 ;
}
void F_103 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
T_5 type ;
V_33 V_61 , V_62 ;
T_3 * V_131 , * V_132 ;
int V_36 = 0 ;
unsigned short V_44 ;
if ( ! F_57 ( & V_2 -> V_110 ) )
return;
V_44 = F_90 ( V_35 , & V_36 ) ;
type = F_79 ( V_2 , V_35 , V_36 ) ;
if ( type != V_146 )
return;
F_40 ( V_2 , V_35 , V_36 , L_23 ) ;
V_131 = F_20 ( V_35 , V_36 ) ;
V_61 = F_21 ( V_35 , V_36 ) ;
V_132 = F_22 ( V_35 , V_36 ) ;
V_62 = F_23 ( V_35 , V_36 ) ;
F_30 ( V_2 , V_61 , V_131 , V_44 ) ;
F_30 ( V_2 , V_62 , V_132 , V_44 ) ;
F_47 ( V_2 , V_35 , V_61 , V_44 , V_69 ) ;
F_47 ( V_2 , V_35 , V_62 , V_44 , V_69 ) ;
}
bool F_104 ( struct V_1 * V_2 ,
struct V_34 * V_35 , int V_36 )
{
T_5 type ;
V_33 V_61 , V_62 ;
T_3 * V_131 , * V_132 ;
bool V_160 = false ;
unsigned short V_44 ;
if ( ! F_57 ( & V_2 -> V_110 ) )
goto V_53;
V_44 = F_90 ( V_35 , & V_36 ) ;
type = F_79 ( V_2 , V_35 , V_36 ) ;
if ( type != V_146 )
goto V_53;
F_40 ( V_2 , V_35 , V_36 , L_24 ) ;
V_131 = F_20 ( V_35 , V_36 ) ;
V_61 = F_21 ( V_35 , V_36 ) ;
V_132 = F_22 ( V_35 , V_36 ) ;
V_62 = F_23 ( V_35 , V_36 ) ;
F_30 ( V_2 , V_61 , V_131 , V_44 ) ;
F_30 ( V_2 , V_62 , V_132 , V_44 ) ;
V_160 = ! F_97 ( V_2 , V_132 , V_44 ) ;
V_160 |= F_97 ( V_2 , V_131 , V_44 ) ;
V_53:
if ( V_160 )
F_51 ( V_35 ) ;
return V_160 ;
}
bool F_105 ( struct V_1 * V_2 ,
struct V_161 * V_162 )
{
T_5 type ;
V_33 V_62 ;
struct V_9 * V_10 = NULL ;
bool V_84 = false ;
int V_36 = sizeof( struct V_58 ) ;
unsigned short V_44 ;
if ( ! F_57 ( & V_2 -> V_110 ) )
goto V_53;
if ( V_162 -> V_163 )
goto V_53;
V_44 = F_90 ( V_162 -> V_35 , & V_36 ) ;
type = F_79 ( V_2 , V_162 -> V_35 , V_36 ) ;
if ( type != V_143 )
goto V_53;
V_62 = F_23 ( V_162 -> V_35 , V_36 ) ;
V_10 = F_25 ( V_2 , V_62 , V_44 ) ;
if ( ! V_10 ) {
F_33 ( V_52 , V_2 ,
L_25 , & V_62 ) ;
goto V_53;
}
F_33 ( V_52 , V_2 ,
L_26 , & V_62 ) ;
V_84 = true ;
V_53:
if ( V_10 )
F_8 ( V_10 ) ;
return V_84 ;
}
