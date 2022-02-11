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
return ( memcmp ( V_30 , V_29 , sizeof( V_31 ) ) == 0 ? 1 : 0 ) ;
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
const unsigned char * V_40 = V_36 ;
T_2 V_19 = 0 ;
T_4 V_18 ;
for ( V_18 = 0 ; V_18 < 4 ; V_18 ++ ) {
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
F_23 ( struct V_1 * V_2 , V_31 V_41 )
{
struct V_16 * V_17 ;
struct V_7 * V_8 , * V_42 = NULL ;
struct V_43 * V_19 = V_2 -> V_3 . V_19 ;
T_2 V_44 ;
if ( ! V_19 )
return NULL ;
V_44 = F_22 ( & V_41 , V_19 -> V_20 ) ;
V_17 = & V_19 -> V_21 [ V_44 ] ;
F_24 () ;
F_25 (dat_entry, head, hash_entry) {
if ( V_8 -> V_41 != V_41 )
continue;
if ( ! F_26 ( & V_8 -> V_9 ) )
continue;
V_42 = V_8 ;
break;
}
F_27 () ;
return V_42 ;
}
static void F_28 ( struct V_1 * V_2 , V_31 V_41 ,
T_3 * V_45 )
{
struct V_7 * V_8 ;
int V_46 ;
V_8 = F_23 ( V_2 , V_41 ) ;
if ( V_8 ) {
if ( ! F_29 ( V_8 -> V_45 , V_45 ) )
memcpy ( V_8 -> V_45 , V_45 , V_39 ) ;
V_8 -> V_11 = V_47 ;
F_30 ( V_48 , V_2 ,
L_1 , & V_8 -> V_41 ,
V_8 -> V_45 ) ;
goto V_49;
}
V_8 = F_31 ( sizeof( * V_8 ) , V_50 ) ;
if ( ! V_8 )
goto V_49;
V_8 -> V_41 = V_41 ;
memcpy ( V_8 -> V_45 , V_45 , V_39 ) ;
V_8 -> V_11 = V_47 ;
F_32 ( & V_8 -> V_9 , 2 ) ;
V_46 = F_33 ( V_2 -> V_3 . V_19 , F_17 ,
F_22 , & V_8 -> V_41 ,
& V_8 -> V_23 ) ;
if ( F_34 ( V_46 != 0 ) ) {
F_5 ( V_8 ) ;
goto V_49;
}
F_30 ( V_48 , V_2 , L_2 ,
& V_8 -> V_41 , V_8 -> V_45 ) ;
V_49:
if ( V_8 )
F_5 ( V_8 ) ;
}
static void F_35 ( struct V_1 * V_2 , struct V_32 * V_33 ,
T_5 type , int V_34 , char * V_51 )
{
struct V_52 * V_53 ;
struct V_54 * V_55 ;
T_3 * V_56 ;
V_31 V_57 , V_58 ;
if ( V_51 )
F_30 ( V_48 , V_2 , L_3 , V_51 ) ;
V_57 = F_19 ( V_33 , V_34 ) ;
V_58 = F_21 ( V_33 , V_34 ) ;
F_30 ( V_48 , V_2 ,
L_4 ,
F_18 ( V_33 , V_34 ) , & V_57 ,
F_20 ( V_33 , V_34 ) , & V_58 ) ;
if ( V_34 == 0 )
return;
V_53 = (struct V_52 * ) V_33 -> V_36 ;
switch ( V_53 -> V_59 . V_60 . V_61 ) {
case V_62 :
F_30 ( V_48 , V_2 ,
L_5 ) ;
break;
case V_63 :
F_30 ( V_48 , V_2 ,
L_6 ,
V_53 -> V_64 ) ;
switch ( V_53 -> V_65 ) {
case V_66 :
F_30 ( V_48 , V_2 , L_7 ) ;
break;
case V_67 :
F_30 ( V_48 , V_2 , L_8 ) ;
break;
case V_68 :
F_30 ( V_48 , V_2 ,
L_9 ) ;
break;
case V_69 :
F_30 ( V_48 , V_2 , L_10 ) ;
break;
default:
F_30 ( V_48 , V_2 , L_11 ,
V_53 -> V_59 . V_60 . V_61 ) ;
}
break;
case V_70 :
V_55 = (struct V_54 * ) V_53 ;
V_56 = V_55 -> V_71 ;
F_30 ( V_48 , V_2 ,
L_12 ,
V_56 ) ;
break;
default:
F_30 ( V_48 , V_2 ,
L_13 ,
V_53 -> V_59 . V_60 . V_61 ) ;
}
}
static void F_35 ( struct V_1 * V_2 , struct V_32 * V_33 ,
T_5 type , int V_34 , char * V_51 )
{
}
static bool F_36 ( struct V_72 * V_73 ,
int V_74 , T_6 V_75 ,
T_6 V_76 ,
T_6 V_77 ,
struct V_78 * V_79 ,
struct V_78 * V_80 )
{
bool V_81 = false ;
int V_82 ;
for ( V_82 = 0 ; V_82 < V_74 ; V_82 ++ )
if ( V_73 [ V_82 ] . V_83 == V_79 )
break;
if ( V_82 < V_74 )
goto V_49;
if ( V_75 > V_77 )
goto V_49;
if ( V_75 < V_76 )
goto V_49;
if ( ( V_75 == V_76 ) && V_80 &&
( F_29 ( V_79 -> V_71 , V_80 -> V_71 ) > 0 ) )
goto V_49;
V_81 = true ;
V_49:
return V_81 ;
}
static void F_37 ( struct V_1 * V_2 ,
struct V_72 * V_84 ,
int V_74 , T_6 V_85 ,
T_6 * V_77 )
{
T_6 V_76 = 0 , V_75 = 0 ;
struct V_78 * V_83 , * V_80 = NULL ;
struct V_43 * V_19 = V_2 -> V_86 ;
struct V_16 * V_17 ;
int V_18 ;
V_84 [ V_74 ] . type = V_87 ;
for ( V_18 = 0 ; V_18 < V_19 -> V_20 ; V_18 ++ ) {
V_17 = & V_19 -> V_21 [ V_18 ] ;
F_24 () ;
F_25 (orig_node, head, hash_entry) {
V_75 = V_88 - V_83 -> V_89 +
V_85 ;
if ( ! F_36 ( V_84 , V_74 ,
V_75 , V_76 ,
* V_77 , V_83 ,
V_80 ) )
continue;
if ( ! F_26 ( & V_83 -> V_9 ) )
continue;
V_76 = V_75 ;
if ( V_80 )
F_38 ( V_80 ) ;
V_80 = V_83 ;
}
F_27 () ;
}
if ( V_80 ) {
V_84 [ V_74 ] . type = V_90 ;
V_84 [ V_74 ] . V_83 = V_80 ;
F_30 ( V_48 , V_2 ,
L_14 ,
V_74 , V_80 -> V_71 , V_80 -> V_89 ,
V_76 ) ;
}
* V_77 = V_76 ;
}
static struct V_72 *
F_39 ( struct V_1 * V_2 , V_31 V_58 )
{
int V_74 ;
T_6 V_77 = V_88 , V_85 ;
struct V_72 * V_73 ;
if ( ! V_2 -> V_86 )
return NULL ;
V_73 = F_31 ( V_91 * sizeof( * V_73 ) , V_50 ) ;
if ( ! V_73 )
return NULL ;
V_85 = ( T_6 ) F_22 ( & V_58 ,
V_88 ) ;
F_30 ( V_48 , V_2 ,
L_15 , & V_58 ,
V_85 ) ;
for ( V_74 = 0 ; V_74 < V_91 ; V_74 ++ )
F_37 ( V_2 , V_73 , V_74 , V_85 ,
& V_77 ) ;
return V_73 ;
}
static bool F_40 ( struct V_1 * V_2 ,
struct V_32 * V_33 , V_31 V_41 ,
int V_92 )
{
int V_18 ;
bool V_81 = false ;
int V_93 ;
struct V_94 * V_95 = NULL ;
struct V_32 * V_96 ;
struct V_72 * V_97 ;
V_97 = F_39 ( V_2 , V_41 ) ;
if ( ! V_97 )
goto V_49;
F_30 ( V_48 , V_2 , L_16 , & V_41 ) ;
for ( V_18 = 0 ; V_18 < V_91 ; V_18 ++ ) {
if ( V_97 [ V_18 ] . type == V_87 )
continue;
V_95 = F_41 ( V_97 [ V_18 ] . V_83 ) ;
if ( ! V_95 )
goto V_98;
V_96 = F_42 ( V_33 , V_50 ) ;
if ( ! F_43 ( V_2 , V_96 ,
V_97 [ V_18 ] . V_83 ,
V_92 ) ) {
F_44 ( V_96 ) ;
goto V_99;
}
V_93 = F_45 ( V_96 ,
V_95 -> V_100 ,
V_95 -> V_35 ) ;
if ( V_93 == V_101 ) {
switch ( V_92 ) {
case V_67 :
F_46 ( V_2 ,
V_102 ) ;
break;
case V_66 :
F_46 ( V_2 ,
V_103 ) ;
break;
}
V_81 = true ;
}
V_99:
F_47 ( V_95 ) ;
V_98:
F_38 ( V_97 [ V_18 ] . V_83 ) ;
}
V_49:
F_48 ( V_97 ) ;
return V_81 ;
}
static void F_49 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 . V_19 )
return;
F_10 ( V_2 , NULL ) ;
F_50 ( V_2 -> V_3 . V_19 ) ;
V_2 -> V_3 . V_19 = NULL ;
}
int F_51 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_19 )
return 0 ;
V_2 -> V_3 . V_19 = F_52 ( 1024 ) ;
if ( ! V_2 -> V_3 . V_19 )
return - V_104 ;
F_1 ( V_2 ) ;
return 0 ;
}
void F_53 ( struct V_1 * V_2 )
{
F_54 ( & V_2 -> V_3 . V_4 ) ;
F_49 ( V_2 ) ;
}
int F_55 ( struct V_105 * V_106 , void * V_107 )
{
struct V_108 * V_109 = (struct V_108 * ) V_106 -> V_110 ;
struct V_1 * V_2 = F_56 ( V_109 ) ;
struct V_43 * V_19 = V_2 -> V_3 . V_19 ;
struct V_7 * V_8 ;
struct V_111 * V_112 ;
struct V_16 * V_17 ;
unsigned long V_113 ;
int V_114 , V_115 , V_116 ;
T_2 V_18 ;
V_112 = F_57 ( V_106 ) ;
if ( ! V_112 )
goto V_49;
F_58 ( V_106 , L_17 , V_109 -> V_117 ) ;
F_58 ( V_106 , L_18 , L_19 , L_20 ,
L_21 ) ;
for ( V_18 = 0 ; V_18 < V_19 -> V_20 ; V_18 ++ ) {
V_17 = & V_19 -> V_21 [ V_18 ] ;
F_24 () ;
F_25 (dat_entry, head, hash_entry) {
V_113 = V_47 - V_8 -> V_11 ;
V_114 = F_59 ( V_113 ) ;
V_116 = V_114 / 60000 ;
V_114 = V_114 % 60000 ;
V_115 = V_114 / 1000 ;
F_58 ( V_106 , L_22 ,
& V_8 -> V_41 , V_8 -> V_45 ,
V_116 , V_115 ) ;
}
F_27 () ;
}
V_49:
if ( V_112 )
F_60 ( V_112 ) ;
return 0 ;
}
static T_5 F_61 ( struct V_1 * V_2 ,
struct V_32 * V_33 , int V_34 )
{
struct V_38 * V_38 ;
struct V_118 * V_118 ;
V_31 V_57 , V_58 ;
T_3 * V_119 , * V_120 ;
T_5 type = 0 ;
if ( F_34 ( ! F_62 ( V_33 , V_34 + V_37 ) ) )
goto V_49;
V_118 = (struct V_118 * ) ( V_33 -> V_36 + V_34 ) ;
if ( V_118 -> V_121 != F_63 ( V_122 ) )
goto V_49;
if ( F_34 ( ! F_62 ( V_33 , V_34 + V_37 +
F_64 ( V_33 -> V_123 ) ) ) )
goto V_49;
V_38 = (struct V_38 * ) ( V_33 -> V_36 + V_34 + V_37 ) ;
if ( V_38 -> V_124 != F_63 ( V_125 ) )
goto V_49;
if ( V_38 -> V_126 != F_63 ( V_127 ) )
goto V_49;
if ( V_38 -> V_128 != V_39 )
goto V_49;
if ( V_38 -> V_129 != 4 )
goto V_49;
V_57 = F_19 ( V_33 , V_34 ) ;
V_58 = F_21 ( V_33 , V_34 ) ;
if ( F_65 ( V_57 ) || F_66 ( V_57 ) ||
F_65 ( V_58 ) || F_66 ( V_58 ) ||
F_67 ( V_57 ) || F_68 ( V_57 ) ||
F_67 ( V_58 ) || F_68 ( V_58 ) )
goto V_49;
V_119 = F_18 ( V_33 , V_34 ) ;
if ( F_69 ( V_119 ) || F_70 ( V_119 ) )
goto V_49;
if ( V_38 -> V_130 != F_63 ( V_131 ) ) {
V_120 = F_20 ( V_33 , V_34 ) ;
if ( F_69 ( V_120 ) ||
F_70 ( V_120 ) )
goto V_49;
}
type = F_71 ( V_38 -> V_130 ) ;
V_49:
return type ;
}
bool F_72 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
T_5 type = 0 ;
V_31 V_58 , V_57 ;
T_3 * V_119 ;
bool V_81 = false ;
struct V_7 * V_8 = NULL ;
struct V_32 * V_132 ;
struct V_111 * V_112 = NULL ;
if ( ! F_73 ( & V_2 -> V_133 ) )
goto V_49;
type = F_61 ( V_2 , V_33 , 0 ) ;
if ( type != V_131 )
goto V_49;
F_35 ( V_2 , V_33 , type , 0 , L_23 ) ;
V_57 = F_19 ( V_33 , 0 ) ;
V_119 = F_18 ( V_33 , 0 ) ;
V_58 = F_21 ( V_33 , 0 ) ;
F_28 ( V_2 , V_57 , V_119 ) ;
V_8 = F_23 ( V_2 , V_58 ) ;
if ( V_8 ) {
V_112 = F_74 ( V_2 ) ;
if ( ! V_112 )
goto V_49;
V_132 = F_75 ( V_134 , V_122 , V_57 ,
V_112 -> V_135 , V_58 , V_119 ,
V_8 -> V_45 , V_119 ) ;
if ( ! V_132 )
goto V_49;
F_76 ( V_132 ) ;
V_132 -> V_136 = F_77 ( V_132 ,
V_112 -> V_135 ) ;
V_2 -> V_137 . V_138 ++ ;
V_2 -> V_137 . V_139 += V_33 -> V_140 + V_37 ;
V_112 -> V_135 -> V_141 = V_47 ;
F_78 ( V_132 ) ;
F_30 ( V_48 , V_2 , L_24 ) ;
V_81 = true ;
} else {
V_81 = F_40 ( V_2 , V_33 , V_58 ,
V_67 ) ;
}
V_49:
if ( V_8 )
F_5 ( V_8 ) ;
if ( V_112 )
F_60 ( V_112 ) ;
return V_81 ;
}
bool F_79 ( struct V_1 * V_2 ,
struct V_32 * V_33 , int V_34 )
{
T_5 type ;
V_31 V_57 , V_58 ;
T_3 * V_119 ;
struct V_32 * V_132 ;
struct V_111 * V_112 = NULL ;
struct V_7 * V_8 = NULL ;
bool V_81 = false ;
int V_142 ;
if ( ! F_73 ( & V_2 -> V_133 ) )
goto V_49;
type = F_61 ( V_2 , V_33 , V_34 ) ;
if ( type != V_131 )
goto V_49;
V_119 = F_18 ( V_33 , V_34 ) ;
V_57 = F_19 ( V_33 , V_34 ) ;
V_58 = F_21 ( V_33 , V_34 ) ;
F_35 ( V_2 , V_33 , type , V_34 ,
L_25 ) ;
F_28 ( V_2 , V_57 , V_119 ) ;
V_8 = F_23 ( V_2 , V_58 ) ;
if ( ! V_8 )
goto V_49;
V_112 = F_74 ( V_2 ) ;
if ( ! V_112 )
goto V_49;
V_132 = F_75 ( V_134 , V_122 , V_57 ,
V_112 -> V_135 , V_58 , V_119 ,
V_8 -> V_45 , V_119 ) ;
if ( ! V_132 )
goto V_49;
if ( V_34 == sizeof( struct V_52 ) )
V_142 = F_80 ( V_2 , V_132 ,
V_68 ) ;
else
V_142 = F_81 ( V_2 , V_132 ) ;
if ( ! V_142 ) {
F_46 ( V_2 , V_143 ) ;
V_81 = true ;
}
V_49:
if ( V_8 )
F_5 ( V_8 ) ;
if ( V_112 )
F_60 ( V_112 ) ;
if ( V_81 )
F_44 ( V_33 ) ;
return V_81 ;
}
void F_82 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
T_5 type ;
V_31 V_57 , V_58 ;
T_3 * V_119 , * V_120 ;
if ( ! F_73 ( & V_2 -> V_133 ) )
return;
type = F_61 ( V_2 , V_33 , 0 ) ;
if ( type != V_134 )
return;
F_35 ( V_2 , V_33 , type , 0 , L_26 ) ;
V_119 = F_18 ( V_33 , 0 ) ;
V_57 = F_19 ( V_33 , 0 ) ;
V_120 = F_20 ( V_33 , 0 ) ;
V_58 = F_21 ( V_33 , 0 ) ;
F_28 ( V_2 , V_57 , V_119 ) ;
F_28 ( V_2 , V_58 , V_120 ) ;
F_40 ( V_2 , V_33 , V_57 , V_66 ) ;
F_40 ( V_2 , V_33 , V_58 , V_66 ) ;
}
bool F_83 ( struct V_1 * V_2 ,
struct V_32 * V_33 , int V_34 )
{
T_5 type ;
V_31 V_57 , V_58 ;
T_3 * V_119 , * V_120 ;
bool V_81 = false ;
if ( ! F_73 ( & V_2 -> V_133 ) )
goto V_49;
type = F_61 ( V_2 , V_33 , V_34 ) ;
if ( type != V_134 )
goto V_49;
F_35 ( V_2 , V_33 , type , V_34 ,
L_27 ) ;
V_119 = F_18 ( V_33 , V_34 ) ;
V_57 = F_19 ( V_33 , V_34 ) ;
V_120 = F_20 ( V_33 , V_34 ) ;
V_58 = F_21 ( V_33 , V_34 ) ;
F_28 ( V_2 , V_57 , V_119 ) ;
F_28 ( V_2 , V_58 , V_120 ) ;
V_81 = ! F_84 ( V_2 , V_120 ) ;
V_49:
if ( V_81 )
F_44 ( V_33 ) ;
return V_81 ;
}
bool F_85 ( struct V_1 * V_2 ,
struct V_144 * V_145 )
{
T_5 type ;
V_31 V_58 ;
struct V_7 * V_8 = NULL ;
bool V_81 = false ;
const T_4 V_146 = sizeof( struct V_54 ) ;
if ( ! F_73 ( & V_2 -> V_133 ) )
goto V_49;
if ( V_145 -> V_147 )
goto V_49;
type = F_61 ( V_2 , V_145 -> V_33 , V_146 ) ;
if ( type != V_131 )
goto V_49;
V_58 = F_21 ( V_145 -> V_33 , V_146 ) ;
V_8 = F_23 ( V_2 , V_58 ) ;
if ( ! V_8 ) {
F_30 ( V_48 , V_2 ,
L_28 , & V_58 ) ;
goto V_49;
}
F_30 ( V_48 , V_2 ,
L_29 , & V_58 ) ;
V_81 = true ;
V_49:
if ( V_8 )
F_5 ( V_8 ) ;
return V_81 ;
}
