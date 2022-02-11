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
const unsigned char * V_40 ;
T_2 V_18 ;
V_40 = ( const unsigned char * ) & V_3 -> V_41 ;
for ( V_18 = 0 ; V_18 < sizeof( V_3 -> V_41 ) ; V_18 ++ ) {
V_19 += V_40 [ V_18 ] ;
V_19 += ( V_19 << 10 ) ;
V_19 ^= ( V_19 >> 6 ) ;
}
V_40 = ( const unsigned char * ) & V_3 -> V_42 ;
for ( V_18 = 0 ; V_18 < sizeof( V_3 -> V_42 ) ; V_18 ++ ) {
V_19 += V_40 [ V_18 ] ;
V_19 += ( V_19 << 10 ) ;
V_19 ^= ( V_19 >> 6 ) ;
}
V_19 += ( V_19 << 3 ) ;
V_19 ^= ( V_19 >> 11 ) ;
V_19 += ( V_19 << 15 ) ;
return V_19 % V_20 ;
}
static struct V_7 *
F_23 ( struct V_1 * V_2 , V_31 V_41 ,
unsigned short V_42 )
{
struct V_16 * V_17 ;
struct V_7 V_43 , * V_8 , * V_44 = NULL ;
struct V_45 * V_19 = V_2 -> V_3 . V_19 ;
T_2 V_46 ;
if ( ! V_19 )
return NULL ;
V_43 . V_41 = V_41 ;
V_43 . V_42 = V_42 ;
V_46 = F_22 ( & V_43 , V_19 -> V_20 ) ;
V_17 = & V_19 -> V_21 [ V_46 ] ;
F_24 () ;
F_25 (dat_entry, head, hash_entry) {
if ( V_8 -> V_41 != V_41 )
continue;
if ( ! F_26 ( & V_8 -> V_9 ) )
continue;
V_44 = V_8 ;
break;
}
F_27 () ;
return V_44 ;
}
static void F_28 ( struct V_1 * V_2 , V_31 V_41 ,
T_3 * V_47 , unsigned short V_42 )
{
struct V_7 * V_8 ;
int V_48 ;
V_8 = F_23 ( V_2 , V_41 , V_42 ) ;
if ( V_8 ) {
if ( ! F_29 ( V_8 -> V_47 , V_47 ) )
F_30 ( V_8 -> V_47 , V_47 ) ;
V_8 -> V_11 = V_49 ;
F_31 ( V_50 , V_2 ,
L_1 ,
& V_8 -> V_41 , V_8 -> V_47 ,
F_32 ( V_42 ) ) ;
goto V_51;
}
V_8 = F_33 ( sizeof( * V_8 ) , V_52 ) ;
if ( ! V_8 )
goto V_51;
V_8 -> V_41 = V_41 ;
V_8 -> V_42 = V_42 ;
F_30 ( V_8 -> V_47 , V_47 ) ;
V_8 -> V_11 = V_49 ;
F_34 ( & V_8 -> V_9 , 2 ) ;
V_48 = F_35 ( V_2 -> V_3 . V_19 , F_17 ,
F_22 , V_8 ,
& V_8 -> V_23 ) ;
if ( F_36 ( V_48 != 0 ) ) {
F_5 ( V_8 ) ;
goto V_51;
}
F_31 ( V_50 , V_2 , L_2 ,
& V_8 -> V_41 , V_8 -> V_47 , F_32 ( V_42 ) ) ;
V_51:
if ( V_8 )
F_5 ( V_8 ) ;
}
static void F_37 ( struct V_1 * V_2 , struct V_32 * V_33 ,
T_4 type , int V_34 , char * V_53 )
{
struct V_54 * V_55 ;
struct V_56 * V_57 ;
T_3 * V_58 ;
V_31 V_59 , V_60 ;
if ( V_53 )
F_31 ( V_50 , V_2 , L_3 , V_53 ) ;
V_59 = F_19 ( V_33 , V_34 ) ;
V_60 = F_21 ( V_33 , V_34 ) ;
F_31 ( V_50 , V_2 ,
L_4 ,
F_18 ( V_33 , V_34 ) , & V_59 ,
F_20 ( V_33 , V_34 ) , & V_60 ) ;
if ( V_34 == 0 )
return;
V_55 = (struct V_54 * ) V_33 -> V_36 ;
switch ( V_55 -> V_61 . V_62 ) {
case V_63 :
F_31 ( V_50 , V_2 ,
L_5 ) ;
break;
case V_64 :
F_31 ( V_50 , V_2 ,
L_6 ,
V_55 -> V_65 ) ;
switch ( V_55 -> V_66 ) {
case V_67 :
F_31 ( V_50 , V_2 , L_7 ) ;
break;
case V_68 :
F_31 ( V_50 , V_2 , L_8 ) ;
break;
case V_69 :
F_31 ( V_50 , V_2 ,
L_9 ) ;
break;
case V_70 :
F_31 ( V_50 , V_2 , L_10 ) ;
break;
default:
F_31 ( V_50 , V_2 , L_11 ,
V_55 -> V_61 . V_62 ) ;
}
break;
case V_71 :
V_57 = (struct V_56 * ) V_55 ;
V_58 = V_57 -> V_72 ;
F_31 ( V_50 , V_2 ,
L_12 ,
V_58 ) ;
break;
default:
F_31 ( V_50 , V_2 ,
L_13 ,
V_55 -> V_61 . V_62 ) ;
}
}
static void F_37 ( struct V_1 * V_2 , struct V_32 * V_33 ,
T_4 type , int V_34 , char * V_53 )
{
}
static bool F_38 ( struct V_73 * V_74 ,
int V_75 , T_5 V_76 ,
T_5 V_77 ,
T_5 V_78 ,
struct V_79 * V_80 ,
struct V_79 * V_81 )
{
bool V_82 = false ;
int V_83 ;
if ( ! ( V_80 -> V_84 & V_85 ) )
goto V_51;
for ( V_83 = 0 ; V_83 < V_75 ; V_83 ++ )
if ( V_74 [ V_83 ] . V_86 == V_80 )
break;
if ( V_83 < V_75 )
goto V_51;
if ( V_76 > V_78 )
goto V_51;
if ( V_76 < V_77 )
goto V_51;
if ( ( V_76 == V_77 ) && V_81 &&
( F_29 ( V_80 -> V_72 , V_81 -> V_72 ) > 0 ) )
goto V_51;
V_82 = true ;
V_51:
return V_82 ;
}
static void F_39 ( struct V_1 * V_2 ,
struct V_73 * V_87 ,
int V_75 , T_5 V_88 ,
T_5 * V_78 )
{
T_5 V_77 = 0 , V_76 = 0 ;
struct V_79 * V_86 , * V_81 = NULL ;
struct V_45 * V_19 = V_2 -> V_89 ;
struct V_16 * V_17 ;
int V_18 ;
V_87 [ V_75 ] . type = V_90 ;
for ( V_18 = 0 ; V_18 < V_19 -> V_20 ; V_18 ++ ) {
V_17 = & V_19 -> V_21 [ V_18 ] ;
F_24 () ;
F_25 (orig_node, head, hash_entry) {
V_76 = V_91 - V_86 -> V_92 +
V_88 ;
if ( ! F_38 ( V_87 , V_75 ,
V_76 , V_77 ,
* V_78 , V_86 ,
V_81 ) )
continue;
if ( ! F_26 ( & V_86 -> V_9 ) )
continue;
V_77 = V_76 ;
if ( V_81 )
F_40 ( V_81 ) ;
V_81 = V_86 ;
}
F_27 () ;
}
if ( V_81 ) {
V_87 [ V_75 ] . type = V_93 ;
V_87 [ V_75 ] . V_86 = V_81 ;
F_31 ( V_50 , V_2 ,
L_14 ,
V_75 , V_81 -> V_72 , V_81 -> V_92 ,
V_77 ) ;
}
* V_78 = V_77 ;
}
static struct V_73 *
F_41 ( struct V_1 * V_2 , V_31 V_60 )
{
int V_75 ;
T_5 V_78 = V_91 , V_88 ;
struct V_73 * V_74 ;
if ( ! V_2 -> V_89 )
return NULL ;
V_74 = F_42 ( V_94 , sizeof( * V_74 ) ,
V_52 ) ;
if ( ! V_74 )
return NULL ;
V_88 = ( T_5 ) F_22 ( & V_60 ,
V_91 ) ;
F_31 ( V_50 , V_2 ,
L_15 , & V_60 ,
V_88 ) ;
for ( V_75 = 0 ; V_75 < V_94 ; V_75 ++ )
F_39 ( V_2 , V_74 , V_75 , V_88 ,
& V_78 ) ;
return V_74 ;
}
static bool F_43 ( struct V_1 * V_2 ,
struct V_32 * V_33 , V_31 V_41 ,
int V_95 )
{
int V_18 ;
bool V_82 = false ;
int V_96 ;
struct V_97 * V_98 = NULL ;
struct V_32 * V_99 ;
struct V_73 * V_100 ;
V_100 = F_41 ( V_2 , V_41 ) ;
if ( ! V_100 )
goto V_51;
F_31 ( V_50 , V_2 , L_16 , & V_41 ) ;
for ( V_18 = 0 ; V_18 < V_94 ; V_18 ++ ) {
if ( V_100 [ V_18 ] . type == V_90 )
continue;
V_98 = F_44 ( V_100 [ V_18 ] . V_86 ,
V_101 ) ;
if ( ! V_98 )
goto V_102;
V_99 = F_45 ( V_33 , V_52 ) ;
if ( ! F_46 ( V_2 , V_99 ,
V_100 [ V_18 ] . V_86 ,
V_95 ) ) {
F_47 ( V_99 ) ;
goto V_103;
}
V_96 = F_48 ( V_99 ,
V_98 -> V_104 ,
V_98 -> V_35 ) ;
if ( V_96 == V_105 ) {
switch ( V_95 ) {
case V_68 :
F_49 ( V_2 ,
V_106 ) ;
break;
case V_67 :
F_49 ( V_2 ,
V_107 ) ;
break;
}
V_82 = true ;
}
V_103:
F_50 ( V_98 ) ;
V_102:
F_40 ( V_100 [ V_18 ] . V_86 ) ;
}
V_51:
F_51 ( V_100 ) ;
return V_82 ;
}
static void F_52 ( struct V_1 * V_2 )
{
char V_108 ;
V_108 = F_53 ( & V_2 -> V_109 ) ;
switch ( V_108 ) {
case 0 :
F_54 ( V_2 , V_110 , 1 ) ;
break;
case 1 :
F_55 ( V_2 , V_110 , 1 ,
NULL , 0 ) ;
break;
}
}
void F_56 ( struct V_111 * V_112 )
{
struct V_1 * V_2 = F_57 ( V_112 ) ;
F_52 ( V_2 ) ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_79 * V_72 ,
T_3 V_113 ,
void * V_114 ,
T_4 V_115 )
{
if ( V_113 & V_116 )
V_72 -> V_84 &= ~ V_85 ;
else
V_72 -> V_84 |= V_85 ;
}
static void F_59 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 . V_19 )
return;
F_10 ( V_2 , NULL ) ;
F_60 ( V_2 -> V_3 . V_19 ) ;
V_2 -> V_3 . V_19 = NULL ;
}
int F_61 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_19 )
return 0 ;
V_2 -> V_3 . V_19 = F_62 ( 1024 ) ;
if ( ! V_2 -> V_3 . V_19 )
return - V_117 ;
F_1 ( V_2 ) ;
F_63 ( V_2 , F_58 ,
NULL , V_110 , 1 ,
V_116 ) ;
F_52 ( V_2 ) ;
return 0 ;
}
void F_64 ( struct V_1 * V_2 )
{
F_54 ( V_2 , V_110 , 1 ) ;
F_65 ( V_2 , V_110 , 1 ) ;
F_66 ( & V_2 -> V_3 . V_4 ) ;
F_59 ( V_2 ) ;
}
int F_67 ( struct V_118 * V_119 , void * V_120 )
{
struct V_111 * V_112 = (struct V_111 * ) V_119 -> V_121 ;
struct V_1 * V_2 = F_57 ( V_112 ) ;
struct V_45 * V_19 = V_2 -> V_3 . V_19 ;
struct V_7 * V_8 ;
struct V_122 * V_123 ;
struct V_16 * V_17 ;
unsigned long V_124 ;
int V_125 , V_126 , V_127 ;
T_2 V_18 ;
V_123 = F_68 ( V_119 ) ;
if ( ! V_123 )
goto V_51;
F_69 ( V_119 , L_17 , V_112 -> V_128 ) ;
F_69 ( V_119 , L_18 , L_19 ,
L_20 , L_21 , L_22 ) ;
for ( V_18 = 0 ; V_18 < V_19 -> V_20 ; V_18 ++ ) {
V_17 = & V_19 -> V_21 [ V_18 ] ;
F_24 () ;
F_25 (dat_entry, head, hash_entry) {
V_124 = V_49 - V_8 -> V_11 ;
V_125 = F_70 ( V_124 ) ;
V_127 = V_125 / 60000 ;
V_125 = V_125 % 60000 ;
V_126 = V_125 / 1000 ;
F_69 ( V_119 , L_23 ,
& V_8 -> V_41 , V_8 -> V_47 ,
F_32 ( V_8 -> V_42 ) ,
V_127 , V_126 ) ;
}
F_27 () ;
}
V_51:
if ( V_123 )
F_71 ( V_123 ) ;
return 0 ;
}
static T_4 F_72 ( struct V_1 * V_2 ,
struct V_32 * V_33 , int V_34 )
{
struct V_38 * V_38 ;
struct V_129 * V_129 ;
V_31 V_59 , V_60 ;
T_3 * V_130 , * V_131 ;
T_4 type = 0 ;
if ( F_36 ( ! F_73 ( V_33 , V_34 + V_37 ) ) )
goto V_51;
V_129 = (struct V_129 * ) ( V_33 -> V_36 + V_34 ) ;
if ( V_129 -> V_132 != F_74 ( V_133 ) )
goto V_51;
if ( F_36 ( ! F_73 ( V_33 , V_34 + V_37 +
F_75 ( V_33 -> V_134 ) ) ) )
goto V_51;
V_38 = (struct V_38 * ) ( V_33 -> V_36 + V_34 + V_37 ) ;
if ( V_38 -> V_135 != F_74 ( V_136 ) )
goto V_51;
if ( V_38 -> V_137 != F_74 ( V_138 ) )
goto V_51;
if ( V_38 -> V_139 != V_39 )
goto V_51;
if ( V_38 -> V_140 != 4 )
goto V_51;
V_59 = F_19 ( V_33 , V_34 ) ;
V_60 = F_21 ( V_33 , V_34 ) ;
if ( F_76 ( V_59 ) || F_77 ( V_59 ) ||
F_76 ( V_60 ) || F_77 ( V_60 ) ||
F_78 ( V_59 ) || F_79 ( V_59 ) ||
F_78 ( V_60 ) || F_79 ( V_60 ) )
goto V_51;
V_130 = F_18 ( V_33 , V_34 ) ;
if ( F_80 ( V_130 ) || F_81 ( V_130 ) )
goto V_51;
if ( V_38 -> V_141 != F_74 ( V_142 ) ) {
V_131 = F_20 ( V_33 , V_34 ) ;
if ( F_80 ( V_131 ) ||
F_81 ( V_131 ) )
goto V_51;
}
type = F_82 ( V_38 -> V_141 ) ;
V_51:
return type ;
}
static unsigned short F_83 ( struct V_32 * V_33 , int * V_34 )
{
unsigned short V_42 ;
V_42 = F_84 ( V_33 , * V_34 ) ;
if ( V_42 & V_143 )
* V_34 += V_144 ;
return V_42 ;
}
bool F_85 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
T_4 type = 0 ;
V_31 V_60 , V_59 ;
T_3 * V_130 ;
bool V_82 = false ;
struct V_7 * V_8 = NULL ;
struct V_32 * V_145 ;
int V_34 = 0 ;
unsigned short V_42 ;
if ( ! F_53 ( & V_2 -> V_109 ) )
goto V_51;
V_42 = F_83 ( V_33 , & V_34 ) ;
type = F_72 ( V_2 , V_33 , V_34 ) ;
if ( type != V_142 )
goto V_51;
F_37 ( V_2 , V_33 , type , V_34 ,
L_24 ) ;
V_59 = F_19 ( V_33 , V_34 ) ;
V_130 = F_18 ( V_33 , V_34 ) ;
V_60 = F_21 ( V_33 , V_34 ) ;
F_28 ( V_2 , V_59 , V_130 , V_42 ) ;
V_8 = F_23 ( V_2 , V_60 , V_42 ) ;
if ( V_8 ) {
if ( F_86 ( V_2 , V_8 -> V_47 , V_42 ) ) {
V_82 = true ;
goto V_51;
}
V_145 = F_87 ( V_146 , V_133 , V_59 ,
V_2 -> V_147 , V_60 , V_130 ,
V_8 -> V_47 , V_130 ) ;
if ( ! V_145 )
goto V_51;
if ( V_42 & V_143 )
V_145 = F_88 ( V_145 , F_74 ( V_148 ) ,
V_42 & V_149 ) ;
F_89 ( V_145 ) ;
V_145 -> V_150 = F_90 ( V_145 ,
V_2 -> V_147 ) ;
V_2 -> V_151 . V_152 ++ ;
V_2 -> V_151 . V_153 += V_33 -> V_154 + V_37 + V_34 ;
V_2 -> V_147 -> V_155 = V_49 ;
F_91 ( V_145 ) ;
F_31 ( V_50 , V_2 , L_25 ) ;
V_82 = true ;
} else {
V_82 = F_43 ( V_2 , V_33 , V_60 ,
V_68 ) ;
}
V_51:
if ( V_8 )
F_5 ( V_8 ) ;
return V_82 ;
}
bool F_92 ( struct V_1 * V_2 ,
struct V_32 * V_33 , int V_34 )
{
T_4 type ;
V_31 V_59 , V_60 ;
T_3 * V_130 ;
struct V_32 * V_145 ;
struct V_7 * V_8 = NULL ;
bool V_82 = false ;
unsigned short V_42 ;
int V_156 ;
if ( ! F_53 ( & V_2 -> V_109 ) )
goto V_51;
V_42 = F_83 ( V_33 , & V_34 ) ;
type = F_72 ( V_2 , V_33 , V_34 ) ;
if ( type != V_142 )
goto V_51;
V_130 = F_18 ( V_33 , V_34 ) ;
V_59 = F_19 ( V_33 , V_34 ) ;
V_60 = F_21 ( V_33 , V_34 ) ;
F_37 ( V_2 , V_33 , type , V_34 ,
L_26 ) ;
F_28 ( V_2 , V_59 , V_130 , V_42 ) ;
V_8 = F_23 ( V_2 , V_60 , V_42 ) ;
if ( ! V_8 )
goto V_51;
V_145 = F_87 ( V_146 , V_133 , V_59 ,
V_2 -> V_147 , V_60 , V_130 ,
V_8 -> V_47 , V_130 ) ;
if ( ! V_145 )
goto V_51;
F_89 ( V_145 ) ;
if ( V_42 & V_143 )
V_145 = F_88 ( V_145 , F_74 ( V_148 ) ,
V_42 & V_149 ) ;
if ( V_34 == sizeof( struct V_54 ) )
V_156 = F_93 ( V_2 , V_145 ,
V_69 ,
NULL , V_42 ) ;
else
V_156 = F_94 ( V_2 , V_145 , NULL , V_42 ) ;
if ( V_156 != V_157 ) {
F_49 ( V_2 , V_158 ) ;
V_82 = true ;
}
V_51:
if ( V_8 )
F_5 ( V_8 ) ;
if ( V_82 )
F_47 ( V_33 ) ;
return V_82 ;
}
void F_95 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
T_4 type ;
V_31 V_59 , V_60 ;
T_3 * V_130 , * V_131 ;
int V_34 = 0 ;
unsigned short V_42 ;
if ( ! F_53 ( & V_2 -> V_109 ) )
return;
V_42 = F_83 ( V_33 , & V_34 ) ;
type = F_72 ( V_2 , V_33 , V_34 ) ;
if ( type != V_146 )
return;
F_37 ( V_2 , V_33 , type , V_34 ,
L_27 ) ;
V_130 = F_18 ( V_33 , V_34 ) ;
V_59 = F_19 ( V_33 , V_34 ) ;
V_131 = F_20 ( V_33 , V_34 ) ;
V_60 = F_21 ( V_33 , V_34 ) ;
F_28 ( V_2 , V_59 , V_130 , V_42 ) ;
F_28 ( V_2 , V_60 , V_131 , V_42 ) ;
F_43 ( V_2 , V_33 , V_59 , V_67 ) ;
F_43 ( V_2 , V_33 , V_60 , V_67 ) ;
}
bool F_96 ( struct V_1 * V_2 ,
struct V_32 * V_33 , int V_34 )
{
T_4 type ;
V_31 V_59 , V_60 ;
T_3 * V_130 , * V_131 ;
bool V_159 = false ;
unsigned short V_42 ;
if ( ! F_53 ( & V_2 -> V_109 ) )
goto V_51;
V_42 = F_83 ( V_33 , & V_34 ) ;
type = F_72 ( V_2 , V_33 , V_34 ) ;
if ( type != V_146 )
goto V_51;
F_37 ( V_2 , V_33 , type , V_34 ,
L_28 ) ;
V_130 = F_18 ( V_33 , V_34 ) ;
V_59 = F_19 ( V_33 , V_34 ) ;
V_131 = F_20 ( V_33 , V_34 ) ;
V_60 = F_21 ( V_33 , V_34 ) ;
F_28 ( V_2 , V_59 , V_130 , V_42 ) ;
F_28 ( V_2 , V_60 , V_131 , V_42 ) ;
V_159 = ! F_86 ( V_2 , V_131 , V_42 ) ;
V_159 |= F_86 ( V_2 , V_130 , V_42 ) ;
V_51:
if ( V_159 )
F_47 ( V_33 ) ;
return V_159 ;
}
bool F_97 ( struct V_1 * V_2 ,
struct V_160 * V_161 )
{
T_4 type ;
V_31 V_60 ;
struct V_7 * V_8 = NULL ;
bool V_82 = false ;
int V_34 = sizeof( struct V_56 ) ;
unsigned short V_42 ;
if ( ! F_53 ( & V_2 -> V_109 ) )
goto V_51;
if ( V_161 -> V_162 )
goto V_51;
V_42 = F_83 ( V_161 -> V_33 , & V_34 ) ;
type = F_72 ( V_2 , V_161 -> V_33 , V_34 ) ;
if ( type != V_142 )
goto V_51;
V_60 = F_21 ( V_161 -> V_33 , V_34 ) ;
V_8 = F_23 ( V_2 , V_60 , V_42 ) ;
if ( ! V_8 ) {
F_31 ( V_50 , V_2 ,
L_29 , & V_60 ) ;
goto V_51;
}
F_31 ( V_50 , V_2 ,
L_30 , & V_60 ) ;
V_82 = true ;
V_51:
if ( V_8 )
F_5 ( V_8 ) ;
return V_82 ;
}
