static bool F_1 ( T_1 V_1 )
{
T_2 V_2 = V_3 ;
T_2 V_4 = 0xffe ;
T_2 V_5 = F_2 ( V_1 ) ;
return ( V_5 >= V_2 && V_5 <= V_4 ) ;
}
static T_1 F_3 ( const struct V_6 * V_6 ,
T_2 V_7 , bool * V_8 )
{
T_1 V_1 ;
if ( V_8 )
* V_8 = false ;
V_1 = F_4 ( V_7 ) ;
if ( ! V_1 ) {
V_1 = V_6 -> V_9 ;
if ( V_8 )
* V_8 = true ;
}
return V_1 ;
}
static T_2 F_5 ( const struct V_6 * V_6 ,
T_1 V_1 )
{
if ( F_1 ( V_1 ) )
return 0 ;
return F_2 ( V_1 ) ;
}
static bool F_6 ( const struct V_6 * V_6 ,
const char * V_10 )
{
return V_6 -> V_11 &&
! strcmp ( V_6 -> V_11 -> V_12 -> V_10 , V_10 ) ;
}
static bool F_7 ( const struct V_6 * V_6 )
{
return F_6 ( V_6 , L_1 ) ;
}
static bool F_8 ( const struct V_6 * V_6 )
{
return F_6 ( V_6 , L_2 ) ;
}
static bool F_9 ( int V_13 )
{
return V_13 & V_14 ;
}
static int
F_10 ( struct V_15 * V_16 ,
const struct V_17 * V_18 )
{
if ( F_11 ( V_16 , V_19 ,
V_18 -> V_20 . V_21 . V_22 ) )
return - V_23 ;
if ( F_11 ( V_16 , V_24 ,
V_18 -> V_20 . V_21 . V_25 ) )
return - V_23 ;
if ( F_12 ( V_16 , V_26 ,
V_18 -> V_20 . V_21 . V_27 ) )
return - V_23 ;
return 0 ;
}
static int
F_13 ( struct V_15 * V_16 ,
const struct V_17 * V_18 )
{
if ( F_11 ( V_16 , V_19 ,
V_18 -> V_20 . V_28 . V_22 ) )
return - V_23 ;
if ( F_14 ( V_16 , V_29 ,
V_18 -> V_20 . V_28 . V_1 ) )
return - V_23 ;
if ( F_14 ( V_16 , V_30 ,
V_18 -> V_20 . V_28 . V_31 ) )
return - V_23 ;
if ( F_12 ( V_16 , V_26 ,
V_18 -> V_20 . V_28 . V_27 ) )
return - V_23 ;
if ( V_18 -> V_20 . V_28 . V_32 &&
F_14 ( V_16 , V_33 ,
V_18 -> V_20 . V_28 . V_34 ) )
return - V_23 ;
return 0 ;
}
static int
F_15 ( struct V_15 * V_16 ,
const struct V_17 * V_18 )
{
if ( F_11 ( V_16 , V_19 ,
V_18 -> V_20 . V_35 . V_22 ) )
return - V_23 ;
if ( F_11 ( V_16 , V_24 ,
V_18 -> V_20 . V_35 . V_25 ) )
return - V_23 ;
if ( F_14 ( V_16 , V_36 ,
V_18 -> V_20 . V_35 . V_37 ) )
return - V_23 ;
if ( F_16 ( V_16 , V_38 ,
V_39 , V_18 -> V_20 . V_35 . V_40 ) )
return - V_23 ;
if ( F_16 ( V_16 , V_41 ,
V_39 , V_18 -> V_20 . V_35 . V_42 ) )
return - V_23 ;
if ( F_14 ( V_16 , V_29 ,
V_18 -> V_20 . V_35 . V_1 ) )
return - V_23 ;
if ( F_14 ( V_16 , V_30 ,
V_18 -> V_20 . V_35 . V_31 ) )
return - V_23 ;
if ( F_12 ( V_16 , V_26 ,
V_18 -> V_20 . V_35 . V_27 ) )
return - V_23 ;
if ( V_18 -> V_20 . V_35 . V_43 &&
F_17 ( V_16 , V_44 ,
V_18 -> V_20 . V_35 . V_43 ) )
return - V_23 ;
return 0 ;
}
static int
F_18 ( struct V_15 * V_16 ,
const struct V_17 * V_18 )
{
if ( F_14 ( V_16 , V_36 ,
V_18 -> V_20 . V_45 . V_37 ) )
return - V_23 ;
if ( F_19 ( V_16 , V_46 ,
V_18 -> V_20 . V_45 . V_47 ) )
return - V_23 ;
if ( F_19 ( V_16 , V_48 ,
V_18 -> V_20 . V_45 . V_49 ) )
return - V_23 ;
if ( F_12 ( V_16 , V_26 ,
V_18 -> V_20 . V_45 . V_27 ) )
return - V_23 ;
if ( F_11 ( V_16 , V_50 ,
V_18 -> V_20 . V_45 . V_51 ) )
return - V_23 ;
return 0 ;
}
static int
F_20 ( struct V_15 * V_16 ,
const struct V_17 * V_18 )
{
if ( V_18 -> V_20 . V_52 . V_53 &&
F_16 ( V_16 , V_38 ,
V_39 , V_18 -> V_20 . V_52 . V_40 ) )
return - V_23 ;
if ( V_18 -> V_20 . V_52 . V_54 &&
F_16 ( V_16 , V_41 ,
V_39 , V_18 -> V_20 . V_52 . V_42 ) )
return - V_23 ;
if ( V_18 -> V_20 . V_52 . V_1 &&
F_14 ( V_16 , V_29 ,
V_18 -> V_20 . V_52 . V_1 ) )
return - V_23 ;
if ( V_18 -> V_20 . V_52 . V_55 &&
F_11 ( V_16 , V_56 ,
V_18 -> V_20 . V_52 . V_55 ) )
return - V_23 ;
if ( F_12 ( V_16 , V_26 ,
V_18 -> V_20 . V_52 . V_27 ) )
return - V_23 ;
if ( F_11 ( V_16 , V_50 ,
V_18 -> V_20 . V_52 . V_51 ) )
return - V_23 ;
if ( V_18 -> V_20 . V_52 . V_43 &&
F_17 ( V_16 , V_44 ,
V_18 -> V_20 . V_52 . V_43 ) )
return - V_23 ;
return 0 ;
}
static int
F_21 ( struct V_15 * V_16 ,
const struct V_17 * V_18 )
{
if ( F_11 ( V_16 , V_19 ,
V_18 -> V_20 . V_57 . V_22 ) )
return - V_23 ;
if ( F_11 ( V_16 , V_24 ,
V_18 -> V_20 . V_57 . V_25 ) )
return - V_23 ;
if ( F_16 ( V_16 , V_58 ,
V_39 , V_18 -> V_20 . V_57 . V_59 ) )
return - V_23 ;
if ( F_16 ( V_16 , V_60 ,
V_39 , V_18 -> V_20 . V_57 . V_61 ) )
return - V_23 ;
if ( F_16 ( V_16 , V_38 ,
V_39 , V_18 -> V_20 . V_57 . V_40 ) )
return - V_23 ;
if ( F_16 ( V_16 , V_41 ,
V_39 , V_18 -> V_20 . V_57 . V_42 ) )
return - V_23 ;
if ( F_14 ( V_16 , V_36 ,
V_18 -> V_20 . V_57 . V_37 ) )
return - V_23 ;
if ( F_14 ( V_16 , V_29 ,
V_18 -> V_20 . V_57 . V_1 ) )
return - V_23 ;
if ( F_14 ( V_16 , V_30 ,
V_18 -> V_20 . V_57 . V_31 ) )
return - V_23 ;
switch ( F_2 ( V_18 -> V_20 . V_57 . V_37 ) ) {
case V_62 :
case V_63 :
if ( F_17 ( V_16 , V_64 ,
V_18 -> V_20 . V_57 . V_65 ) )
return - V_23 ;
if ( F_17 ( V_16 ,
V_66 ,
V_18 -> V_20 . V_57 . V_67 ) )
return - V_23 ;
if ( F_17 ( V_16 , V_68 ,
V_18 -> V_20 . V_57 . V_69 & 0x3f ) )
return - V_23 ;
if ( F_17 ( V_16 ,
V_70 ,
V_18 -> V_20 . V_57 . V_71 & 0x3f ) )
return - V_23 ;
if ( F_17 ( V_16 , V_72 ,
( V_18 -> V_20 . V_57 . V_69 & 0xc0 ) >> 6 ) )
return - V_23 ;
if ( F_17 ( V_16 ,
V_73 ,
( V_18 -> V_20 . V_57 . V_71 & 0xc0 ) >> 6 ) )
return - V_23 ;
break;
}
if ( V_18 -> V_20 . V_57 . V_51 != V_74 &&
F_11 ( V_16 , V_50 ,
V_18 -> V_20 . V_57 . V_51 ) )
return - V_23 ;
return 0 ;
}
static int F_22 ( const struct V_75 * V_75 ,
struct V_15 * V_16 ,
void * V_76 )
{
const struct V_17 * V_18 = V_76 ;
struct V_77 * V_78 ;
int V_79 = 0 ;
if ( F_12 ( V_16 , V_80 , V_18 -> V_81 ) )
return - V_23 ;
V_78 = F_23 ( V_16 , V_82 ) ;
if ( ! V_78 )
return - V_23 ;
if ( F_12 ( V_16 , V_83 ,
V_18 -> V_20 . V_84 ) )
return - V_23 ;
if ( F_11 ( V_16 , V_85 ,
V_18 -> V_20 . V_86 ) )
return - V_23 ;
if ( F_11 ( V_16 , V_87 , 0 ) )
return - V_23 ;
if ( F_24 ( V_16 , V_88 ,
V_18 -> V_89 ) )
return - V_23 ;
switch ( V_18 -> V_20 . V_84 ) {
case V_90 :
V_79 = F_10 ( V_16 , V_18 ) ;
break;
case V_91 :
V_79 = F_13 ( V_16 , V_18 ) ;
break;
case V_92 :
V_79 = F_15 ( V_16 , V_18 ) ;
break;
case V_93 :
V_79 = F_18 ( V_16 , V_18 ) ;
break;
case V_94 :
V_79 = F_20 ( V_16 , V_18 ) ;
break;
case V_95 :
V_79 = F_21 ( V_16 , V_18 ) ;
break;
default:
V_79 = - V_96 ;
break;
}
if ( V_79 )
return V_79 ;
F_25 ( V_16 , V_78 ) ;
return 0 ;
}
static int F_26 ( const struct V_75 * V_75 ,
struct V_15 * V_16 ,
void * V_76 )
{
const struct V_17 * V_18 = V_76 ;
struct V_77 * V_78 ;
if ( F_12 ( V_16 , V_80 , V_18 -> V_81 ) )
return - V_23 ;
V_78 = F_23 ( V_16 , V_82 ) ;
if ( ! V_78 )
return - V_23 ;
if ( F_24 ( V_16 , V_88 ,
V_18 -> V_89 ) )
return - V_23 ;
F_25 ( V_16 , V_78 ) ;
return 0 ;
}
static int
F_27 ( struct V_15 * V_16 ,
struct V_97 * V_18 )
{
if ( F_11 ( V_16 , V_98 ,
F_28 ( V_18 -> V_51 ) ) )
return - V_23 ;
if ( F_17 ( V_16 , V_99 ,
V_18 -> V_100 . V_8 ) )
return - V_23 ;
return 0 ;
}
static int
F_29 ( struct V_15 * V_16 ,
const struct V_97 * V_18 )
{
if ( F_11 ( V_16 , V_101 ,
V_18 -> V_102 . V_51 ) )
return - V_23 ;
if ( ! F_30 ( V_18 -> V_102 . V_59 ) &&
F_16 ( V_16 , V_58 ,
V_39 , V_18 -> V_102 . V_59 ) )
return - V_23 ;
if ( ! F_30 ( V_18 -> V_102 . V_40 ) &&
F_16 ( V_16 , V_38 ,
V_39 , V_18 -> V_102 . V_40 ) )
return - V_23 ;
if ( V_18 -> V_102 . V_1 &&
F_14 ( V_16 , V_29 ,
V_18 -> V_102 . V_1 ) )
return - V_23 ;
return 0 ;
}
static int
F_31 ( struct V_15 * V_16 ,
const struct V_97 * V_18 )
{
int V_103 ;
struct V_77 * V_104 ;
if ( F_12 ( V_16 , V_105 ,
V_18 -> V_106 ) )
return - V_23 ;
V_104 = F_23 ( V_16 ,
V_107 ) ;
if ( ! V_104 )
return - V_23 ;
for ( V_103 = 0 ; V_103 < V_18 -> V_106 ; V_103 ++ )
if ( F_11 ( V_16 , V_103 + 1 , V_18 -> V_104 [ V_103 ] ) )
return - V_23 ;
F_25 ( V_16 , V_104 ) ;
return 0 ;
}
static int
F_32 ( struct V_15 * V_16 ,
const struct V_97 * V_18 )
{
if ( ! F_30 ( V_18 -> V_108 . V_59 ) &&
F_16 ( V_16 , V_58 ,
V_39 , V_18 -> V_108 . V_59 ) )
return - V_23 ;
if ( ! F_30 ( V_18 -> V_108 . V_40 ) &&
F_16 ( V_16 , V_38 ,
V_39 , V_18 -> V_108 . V_40 ) )
return - V_23 ;
if ( V_18 -> V_108 . V_1 &&
F_14 ( V_16 , V_29 ,
V_18 -> V_108 . V_1 ) )
return - V_23 ;
if ( F_17 ( V_16 , V_109 ,
V_18 -> V_108 . V_110 ) )
return - V_23 ;
if ( F_11 ( V_16 , V_101 ,
V_18 -> V_108 . V_51 ) )
return - V_23 ;
return 0 ;
}
static int F_33 ( const struct V_75 * V_75 ,
struct V_15 * V_16 ,
void * V_76 )
{
struct V_97 * V_18 = V_76 ;
struct V_77 * V_78 ;
int V_79 = 0 ;
if ( F_12 ( V_16 , V_80 , V_18 -> V_81 ) )
return - V_23 ;
V_78 = F_23 ( V_16 , V_82 ) ;
if ( ! V_78 )
return - V_23 ;
if ( F_11 ( V_16 , V_50 ,
V_18 -> V_51 ) )
return - V_23 ;
switch ( F_34 ( V_18 -> V_51 ) ) {
case V_111 :
V_79 = F_27 ( V_16 , V_18 ) ;
break;
case V_112 :
V_79 = F_29 ( V_16 , V_18 ) ;
break;
case V_113 :
case V_114 :
V_79 = F_31 ( V_16 , V_18 ) ;
break;
case V_115 :
V_79 = F_32 ( V_16 , V_18 ) ;
break;
default:
V_79 = - V_96 ;
break;
}
if ( V_79 )
return V_79 ;
F_25 ( V_16 , V_78 ) ;
return 0 ;
}
static int F_35 ( const struct V_75 * V_75 ,
struct V_15 * V_16 ,
void * V_76 )
{
const struct V_97 * V_18 = V_76 ;
struct V_77 * V_78 ;
if ( F_12 ( V_16 , V_80 , V_18 -> V_81 ) )
return - V_23 ;
V_78 = F_23 ( V_16 , V_82 ) ;
if ( ! V_78 )
return - V_23 ;
if ( F_11 ( V_16 , V_50 ,
V_18 -> V_51 ) )
return - V_23 ;
F_25 ( V_16 , V_78 ) ;
return 0 ;
}
static struct V_17 *
F_36 ( const struct V_116 * V_116 ,
const struct V_17 * V_117 )
{
struct V_17 * V_118 ;
T_3 V_119 = V_117 -> V_119 ? V_117 -> V_119 : sizeof( V_118 -> V_20 ) ;
F_37 (ofdpa->flow_tbl, found,
entry, match->key_crc32) {
if ( memcmp ( & V_118 -> V_20 , & V_117 -> V_20 , V_119 ) == 0 )
return V_118 ;
}
return NULL ;
}
static int F_38 ( struct V_6 * V_6 ,
int V_13 , struct V_17 * V_117 )
{
struct V_116 * V_116 = V_6 -> V_116 ;
struct V_17 * V_118 ;
T_3 V_119 = V_117 -> V_119 ? V_117 -> V_119 : sizeof( V_118 -> V_20 ) ;
unsigned long V_120 ;
V_117 -> V_121 = F_39 ( ~ 0 , & V_117 -> V_20 , V_119 ) ;
F_40 ( & V_116 -> V_122 , V_120 ) ;
V_118 = F_36 ( V_116 , V_117 ) ;
if ( V_118 ) {
V_117 -> V_89 = V_118 -> V_89 ;
F_41 ( & V_118 -> V_18 ) ;
F_42 ( V_118 ) ;
V_118 = V_117 ;
V_118 -> V_81 = V_123 ;
} else {
V_118 = V_117 ;
V_118 -> V_89 = V_116 -> V_124 ++ ;
V_118 -> V_81 = V_125 ;
}
F_43 ( V_116 -> V_126 , & V_118 -> V_18 , V_118 -> V_121 ) ;
F_44 ( & V_116 -> V_122 , V_120 ) ;
return F_45 ( V_6 -> V_75 ,
F_9 ( V_13 ) ,
F_22 ,
V_118 , NULL , NULL ) ;
return 0 ;
}
static int F_46 ( struct V_6 * V_6 ,
int V_13 , struct V_17 * V_117 )
{
struct V_116 * V_116 = V_6 -> V_116 ;
struct V_17 * V_118 ;
T_3 V_119 = V_117 -> V_119 ? V_117 -> V_119 : sizeof( V_118 -> V_20 ) ;
unsigned long V_120 ;
int V_79 = 0 ;
V_117 -> V_121 = F_39 ( ~ 0 , & V_117 -> V_20 , V_119 ) ;
F_40 ( & V_116 -> V_122 , V_120 ) ;
V_118 = F_36 ( V_116 , V_117 ) ;
if ( V_118 ) {
F_41 ( & V_118 -> V_18 ) ;
V_118 -> V_81 = V_127 ;
}
F_44 ( & V_116 -> V_122 , V_120 ) ;
F_42 ( V_117 ) ;
if ( V_118 ) {
V_79 = F_45 ( V_6 -> V_75 ,
F_9 ( V_13 ) ,
F_26 ,
V_118 , NULL , NULL ) ;
F_42 ( V_118 ) ;
}
return V_79 ;
}
static int F_47 ( struct V_6 * V_6 , int V_13 ,
struct V_17 * V_18 )
{
if ( V_13 & V_128 )
return F_46 ( V_6 , V_13 , V_18 ) ;
else
return F_38 ( V_6 , V_13 , V_18 ) ;
}
static int F_48 ( struct V_6 * V_6 , int V_13 ,
T_4 V_22 , T_4 V_25 ,
enum V_129 V_27 )
{
struct V_17 * V_18 ;
V_18 = F_49 ( sizeof( * V_18 ) , V_130 ) ;
if ( ! V_18 )
return - V_131 ;
V_18 -> V_20 . V_86 = V_132 ;
V_18 -> V_20 . V_84 = V_90 ;
V_18 -> V_20 . V_21 . V_22 = V_22 ;
V_18 -> V_20 . V_21 . V_25 = V_25 ;
V_18 -> V_20 . V_21 . V_27 = V_27 ;
return F_47 ( V_6 , V_13 , V_18 ) ;
}
static int F_50 ( struct V_6 * V_6 ,
int V_13 ,
T_4 V_22 , T_1 V_1 ,
T_1 V_31 ,
enum V_129 V_27 ,
bool V_32 , T_1 V_34 )
{
struct V_17 * V_18 ;
V_18 = F_49 ( sizeof( * V_18 ) , V_130 ) ;
if ( ! V_18 )
return - V_131 ;
V_18 -> V_20 . V_86 = V_133 ;
V_18 -> V_20 . V_84 = V_91 ;
V_18 -> V_20 . V_28 . V_22 = V_22 ;
V_18 -> V_20 . V_28 . V_1 = V_1 ;
V_18 -> V_20 . V_28 . V_31 = V_31 ;
V_18 -> V_20 . V_28 . V_27 = V_27 ;
V_18 -> V_20 . V_28 . V_32 = V_32 ;
V_18 -> V_20 . V_28 . V_34 = V_34 ;
return F_47 ( V_6 , V_13 , V_18 ) ;
}
static int F_51 ( struct V_6 * V_6 ,
T_4 V_22 , T_4 V_25 ,
T_1 V_37 , const T_5 * V_40 ,
const T_5 * V_42 , T_1 V_1 ,
T_1 V_31 , bool V_43 ,
int V_13 )
{
struct V_17 * V_18 ;
V_18 = F_49 ( sizeof( * V_18 ) , V_130 ) ;
if ( ! V_18 )
return - V_131 ;
if ( F_52 ( V_40 ) ) {
V_18 -> V_20 . V_86 = V_134 ;
V_18 -> V_20 . V_35 . V_27 =
V_135 ;
} else {
V_18 -> V_20 . V_86 = V_136 ;
V_18 -> V_20 . V_35 . V_27 =
V_93 ;
}
V_18 -> V_20 . V_84 = V_92 ;
V_18 -> V_20 . V_35 . V_22 = V_22 ;
V_18 -> V_20 . V_35 . V_25 = V_25 ;
V_18 -> V_20 . V_35 . V_37 = V_37 ;
F_53 ( V_18 -> V_20 . V_35 . V_40 , V_40 ) ;
F_53 ( V_18 -> V_20 . V_35 . V_42 , V_42 ) ;
V_18 -> V_20 . V_35 . V_1 = V_1 ;
V_18 -> V_20 . V_35 . V_31 = V_31 ;
V_18 -> V_20 . V_35 . V_43 = V_43 ;
return F_47 ( V_6 , V_13 , V_18 ) ;
}
static int F_54 ( struct V_6 * V_6 ,
int V_13 , const T_5 * V_40 ,
const T_5 * V_42 , T_1 V_1 ,
T_4 V_55 ,
enum V_129 V_27 ,
T_4 V_51 , bool V_43 )
{
struct V_17 * V_18 ;
T_4 V_86 ;
bool V_137 = ! ! V_1 ;
bool V_138 = ! V_40 || ( V_40 && V_42 ) ;
bool V_139 = false ;
V_18 = F_49 ( sizeof( * V_18 ) , V_140 ) ;
if ( ! V_18 )
return - V_131 ;
V_18 -> V_20 . V_84 = V_94 ;
if ( V_40 ) {
V_18 -> V_20 . V_52 . V_53 = 1 ;
F_53 ( V_18 -> V_20 . V_52 . V_40 , V_40 ) ;
}
if ( V_42 ) {
V_18 -> V_20 . V_52 . V_54 = 1 ;
F_53 ( V_18 -> V_20 . V_52 . V_42 , V_42 ) ;
if ( ! F_55 ( V_42 , V_141 ) )
V_139 = true ;
}
V_86 = V_142 ;
if ( V_137 && V_138 && V_139 )
V_86 = V_143 ;
else if ( V_137 && V_138 && ! V_139 )
V_86 = V_144 ;
else if ( V_137 && ! V_138 )
V_86 = V_145 ;
else if ( ! V_137 && V_138 && V_139 )
V_86 = V_146 ;
else if ( ! V_137 && V_138 && ! V_139 )
V_86 = V_147 ;
else if ( ! V_137 && ! V_138 )
V_86 = V_148 ;
V_18 -> V_20 . V_86 = V_86 ;
V_18 -> V_20 . V_52 . V_1 = V_1 ;
V_18 -> V_20 . V_52 . V_55 = V_55 ;
V_18 -> V_20 . V_52 . V_27 = V_27 ;
V_18 -> V_20 . V_52 . V_51 = V_51 ;
V_18 -> V_20 . V_52 . V_43 = V_43 ;
return F_47 ( V_6 , V_13 , V_18 ) ;
}
static int F_56 ( struct V_6 * V_6 ,
T_1 V_37 , T_6 V_149 ,
T_6 V_150 , T_4 V_86 ,
enum V_129 V_27 ,
T_4 V_51 , struct V_151 * V_152 ,
int V_13 )
{
struct V_17 * V_18 ;
V_18 = F_49 ( sizeof( * V_18 ) , V_130 ) ;
if ( ! V_18 )
return - V_131 ;
V_18 -> V_20 . V_84 = V_93 ;
V_18 -> V_20 . V_86 = V_86 ;
V_18 -> V_20 . V_45 . V_37 = V_37 ;
V_18 -> V_20 . V_45 . V_47 = V_149 ;
V_18 -> V_20 . V_45 . V_49 = V_150 ;
V_18 -> V_20 . V_45 . V_27 = V_27 ;
V_18 -> V_20 . V_45 . V_51 = V_51 ;
V_18 -> V_119 = F_57 ( struct V_153 ,
V_45 . V_51 ) ;
V_18 -> V_152 = V_152 ;
return F_47 ( V_6 , V_13 , V_18 ) ;
}
static int F_58 ( struct V_6 * V_6 , int V_13 ,
T_4 V_22 , T_4 V_25 ,
const T_5 * V_59 , const T_5 * V_61 ,
const T_5 * V_40 , const T_5 * V_42 ,
T_1 V_37 , T_1 V_1 ,
T_1 V_31 , T_5 V_65 ,
T_5 V_67 , T_5 V_69 , T_5 V_71 ,
T_4 V_51 )
{
T_4 V_86 ;
struct V_17 * V_18 ;
V_18 = F_49 ( sizeof( * V_18 ) , V_130 ) ;
if ( ! V_18 )
return - V_131 ;
V_86 = V_154 ;
if ( V_40 && V_42 ) {
if ( F_55 ( V_42 , V_155 ) )
V_86 = V_156 ;
else if ( F_59 ( V_40 ) )
V_86 = V_157 ;
}
V_18 -> V_20 . V_86 = V_86 ;
V_18 -> V_20 . V_84 = V_95 ;
V_18 -> V_20 . V_57 . V_22 = V_22 ;
V_18 -> V_20 . V_57 . V_25 = V_25 ;
if ( V_59 )
F_53 ( V_18 -> V_20 . V_57 . V_59 , V_59 ) ;
if ( V_61 )
F_53 ( V_18 -> V_20 . V_57 . V_61 , V_61 ) ;
if ( V_40 )
F_53 ( V_18 -> V_20 . V_57 . V_40 , V_40 ) ;
if ( V_42 )
F_53 ( V_18 -> V_20 . V_57 . V_42 , V_42 ) ;
V_18 -> V_20 . V_57 . V_37 = V_37 ;
V_18 -> V_20 . V_57 . V_1 = V_1 ;
V_18 -> V_20 . V_57 . V_31 = V_31 ;
V_18 -> V_20 . V_57 . V_65 = V_65 ;
V_18 -> V_20 . V_57 . V_67 = V_67 ;
V_18 -> V_20 . V_57 . V_69 = V_69 ;
V_18 -> V_20 . V_57 . V_71 = V_71 ;
V_18 -> V_20 . V_57 . V_51 = V_51 ;
return F_47 ( V_6 , V_13 , V_18 ) ;
}
static struct V_97 *
F_60 ( const struct V_116 * V_116 ,
const struct V_97 * V_117 )
{
struct V_97 * V_118 ;
F_37 (ofdpa->group_tbl, found,
entry, match->group_id) {
if ( V_118 -> V_51 == V_117 -> V_51 )
return V_118 ;
}
return NULL ;
}
static void F_61 ( struct V_97 * V_18 )
{
switch ( F_34 ( V_18 -> V_51 ) ) {
case V_113 :
case V_114 :
F_42 ( V_18 -> V_104 ) ;
break;
default:
break;
}
F_42 ( V_18 ) ;
}
static int F_62 ( struct V_6 * V_6 , int V_13 ,
struct V_97 * V_117 )
{
struct V_116 * V_116 = V_6 -> V_116 ;
struct V_97 * V_118 ;
unsigned long V_120 ;
F_40 ( & V_116 -> V_158 , V_120 ) ;
V_118 = F_60 ( V_116 , V_117 ) ;
if ( V_118 ) {
F_41 ( & V_118 -> V_18 ) ;
F_61 ( V_118 ) ;
V_118 = V_117 ;
V_118 -> V_81 = V_159 ;
} else {
V_118 = V_117 ;
V_118 -> V_81 = V_160 ;
}
F_43 ( V_116 -> V_161 , & V_118 -> V_18 , V_118 -> V_51 ) ;
F_44 ( & V_116 -> V_158 , V_120 ) ;
return F_45 ( V_6 -> V_75 ,
F_9 ( V_13 ) ,
F_33 ,
V_118 , NULL , NULL ) ;
}
static int F_63 ( struct V_6 * V_6 , int V_13 ,
struct V_97 * V_117 )
{
struct V_116 * V_116 = V_6 -> V_116 ;
struct V_97 * V_118 ;
unsigned long V_120 ;
int V_79 = 0 ;
F_40 ( & V_116 -> V_158 , V_120 ) ;
V_118 = F_60 ( V_116 , V_117 ) ;
if ( V_118 ) {
F_41 ( & V_118 -> V_18 ) ;
V_118 -> V_81 = V_162 ;
}
F_44 ( & V_116 -> V_158 , V_120 ) ;
F_61 ( V_117 ) ;
if ( V_118 ) {
V_79 = F_45 ( V_6 -> V_75 ,
F_9 ( V_13 ) ,
F_35 ,
V_118 , NULL , NULL ) ;
F_61 ( V_118 ) ;
}
return V_79 ;
}
static int F_64 ( struct V_6 * V_6 , int V_13 ,
struct V_97 * V_18 )
{
if ( V_13 & V_128 )
return F_63 ( V_6 , V_13 , V_18 ) ;
else
return F_62 ( V_6 , V_13 , V_18 ) ;
}
static int F_65 ( struct V_6 * V_6 ,
int V_13 , T_1 V_1 ,
T_4 V_163 , int V_8 )
{
struct V_97 * V_18 ;
V_18 = F_49 ( sizeof( * V_18 ) , V_130 ) ;
if ( ! V_18 )
return - V_131 ;
V_18 -> V_51 = F_66 ( V_1 , V_163 ) ;
V_18 -> V_100 . V_8 = V_8 ;
return F_64 ( V_6 , V_13 , V_18 ) ;
}
static int F_67 ( struct V_6 * V_6 ,
int V_13 , T_5 V_106 ,
const T_4 * V_104 , T_4 V_51 )
{
struct V_97 * V_18 ;
V_18 = F_49 ( sizeof( * V_18 ) , V_130 ) ;
if ( ! V_18 )
return - V_131 ;
V_18 -> V_51 = V_51 ;
V_18 -> V_106 = V_106 ;
V_18 -> V_104 = F_68 ( V_106 , sizeof( T_4 ) , V_130 ) ;
if ( ! V_18 -> V_104 ) {
F_42 ( V_18 ) ;
return - V_131 ;
}
memcpy ( V_18 -> V_104 , V_104 , V_106 * sizeof( T_4 ) ) ;
return F_64 ( V_6 , V_13 , V_18 ) ;
}
static int F_69 ( struct V_6 * V_6 ,
int V_13 , T_1 V_1 ,
T_5 V_106 , const T_4 * V_104 ,
T_4 V_51 )
{
return F_67 ( V_6 , V_13 ,
V_106 , V_104 ,
V_51 ) ;
}
static int F_70 ( struct V_6 * V_6 , int V_13 ,
T_4 V_164 , const T_5 * V_165 , const T_5 * V_166 ,
T_1 V_1 , bool V_110 , T_4 V_167 )
{
struct V_97 * V_18 ;
V_18 = F_49 ( sizeof( * V_18 ) , V_130 ) ;
if ( ! V_18 )
return - V_131 ;
V_18 -> V_51 = F_71 ( V_164 ) ;
if ( V_165 )
F_53 ( V_18 -> V_108 . V_59 , V_165 ) ;
if ( V_166 )
F_53 ( V_18 -> V_108 . V_40 , V_166 ) ;
V_18 -> V_108 . V_1 = V_1 ;
V_18 -> V_108 . V_110 = V_110 ;
V_18 -> V_108 . V_51 = F_66 ( V_1 , V_167 ) ;
return F_64 ( V_6 , V_13 , V_18 ) ;
}
static struct V_168 *
F_72 ( const struct V_116 * V_116 , T_6 V_169 )
{
struct V_168 * V_118 ;
F_37 (ofdpa->neigh_tbl, found,
entry, be32_to_cpu(ip_addr))
if ( V_118 -> V_169 == V_169 )
return V_118 ;
return NULL ;
}
static void F_73 ( struct V_116 * V_116 ,
struct V_168 * V_18 )
{
V_18 -> V_164 = V_116 -> V_170 ++ ;
V_18 -> V_171 ++ ;
F_43 ( V_116 -> V_172 , & V_18 -> V_18 ,
F_74 ( V_18 -> V_169 ) ) ;
}
static void F_75 ( struct V_168 * V_18 )
{
if ( -- V_18 -> V_171 == 0 ) {
F_41 ( & V_18 -> V_18 ) ;
F_42 ( V_18 ) ;
}
}
static void F_76 ( struct V_168 * V_18 ,
const T_5 * V_40 , bool V_110 )
{
if ( V_40 ) {
F_53 ( V_18 -> V_40 , V_40 ) ;
V_18 -> V_110 = V_110 ;
} else {
V_18 -> V_171 ++ ;
}
}
static int F_77 ( struct V_6 * V_6 ,
int V_13 , T_6 V_169 , const T_5 * V_40 )
{
struct V_116 * V_116 = V_6 -> V_116 ;
struct V_168 * V_18 ;
struct V_168 * V_118 ;
unsigned long V_120 ;
T_1 V_37 = F_4 ( V_62 ) ;
enum V_129 V_27 =
V_95 ;
T_4 V_51 ;
T_4 V_86 = 0 ;
bool V_173 = ! ( V_13 & V_128 ) ;
bool V_174 ;
bool V_175 ;
int V_79 = 0 ;
V_18 = F_49 ( sizeof( * V_18 ) , V_130 ) ;
if ( ! V_18 )
return - V_131 ;
F_40 ( & V_116 -> V_176 , V_120 ) ;
V_118 = F_72 ( V_116 , V_169 ) ;
V_174 = V_118 && V_173 ;
V_175 = V_118 && ! V_173 ;
V_173 = ! V_118 && V_173 ;
if ( V_173 ) {
V_18 -> V_169 = V_169 ;
V_18 -> V_177 = V_6 -> V_177 ;
F_53 ( V_18 -> V_40 , V_40 ) ;
V_18 -> V_110 = true ;
F_73 ( V_116 , V_18 ) ;
} else if ( V_175 ) {
memcpy ( V_18 , V_118 , sizeof( * V_18 ) ) ;
F_75 ( V_118 ) ;
} else if ( V_174 ) {
F_76 ( V_118 , V_40 , true ) ;
memcpy ( V_18 , V_118 , sizeof( * V_18 ) ) ;
} else {
V_79 = - V_178 ;
}
F_44 ( & V_116 -> V_176 , V_120 ) ;
if ( V_79 )
goto V_179;
V_79 = F_70 ( V_6 , V_13 ,
V_18 -> V_164 ,
V_6 -> V_177 -> V_180 ,
V_18 -> V_40 ,
V_6 -> V_9 ,
V_18 -> V_110 ,
V_6 -> V_167 ) ;
if ( V_79 ) {
F_78 ( V_6 -> V_177 , L_3 ,
V_79 , V_18 -> V_164 ) ;
goto V_179;
}
if ( V_173 || V_175 ) {
V_51 = F_71 ( V_18 -> V_164 ) ;
V_79 = F_56 ( V_6 ,
V_37 , V_169 ,
F_79 ( 32 ) ,
V_86 , V_27 ,
V_51 , NULL , V_13 ) ;
if ( V_79 )
F_78 ( V_6 -> V_177 , L_4 ,
V_79 , & V_18 -> V_169 , V_51 ) ;
}
V_179:
if ( ! V_173 )
F_42 ( V_18 ) ;
return V_79 ;
}
static int F_80 ( struct V_6 * V_6 ,
T_6 V_169 )
{
struct V_181 * V_177 = V_6 -> V_177 ;
struct V_182 * V_183 = F_81 ( V_177 , ( V_184 T_4 ) V_169 ) ;
int V_79 = 0 ;
if ( ! V_183 ) {
V_183 = F_82 ( & V_185 , & V_169 , V_177 ) ;
if ( F_83 ( V_183 ) )
return F_84 ( V_183 ) ;
}
if ( V_183 -> V_186 & V_187 )
V_79 = F_77 ( V_6 , 0 ,
V_169 , V_183 -> V_188 ) ;
else
F_85 ( V_183 , NULL ) ;
F_86 ( V_183 ) ;
return V_79 ;
}
static int F_87 ( struct V_6 * V_6 ,
int V_13 , T_6 V_169 , T_4 * V_164 )
{
struct V_116 * V_116 = V_6 -> V_116 ;
struct V_168 * V_18 ;
struct V_168 * V_118 ;
unsigned long V_120 ;
bool V_173 = ! ( V_13 & V_128 ) ;
bool V_174 ;
bool V_175 ;
bool V_189 = true ;
int V_79 = 0 ;
V_18 = F_49 ( sizeof( * V_18 ) , V_130 ) ;
if ( ! V_18 )
return - V_131 ;
F_40 ( & V_116 -> V_176 , V_120 ) ;
V_118 = F_72 ( V_116 , V_169 ) ;
V_174 = V_118 && V_173 ;
V_175 = V_118 && ! V_173 ;
V_173 = ! V_118 && V_173 ;
if ( V_173 ) {
V_18 -> V_169 = V_169 ;
V_18 -> V_177 = V_6 -> V_177 ;
F_73 ( V_116 , V_18 ) ;
* V_164 = V_18 -> V_164 ;
V_189 = false ;
} else if ( V_175 ) {
* V_164 = V_118 -> V_164 ;
F_75 ( V_118 ) ;
} else if ( V_174 ) {
F_76 ( V_118 , NULL , false ) ;
V_189 = ! F_30 ( V_118 -> V_40 ) ;
* V_164 = V_118 -> V_164 ;
} else {
V_79 = - V_178 ;
}
F_44 ( & V_116 -> V_176 , V_120 ) ;
if ( ! V_173 )
F_42 ( V_18 ) ;
if ( V_79 )
return V_79 ;
if ( ! V_189 )
V_79 = F_80 ( V_6 , V_169 ) ;
return V_79 ;
}
static struct V_6 * F_88 ( const struct V_116 * V_116 ,
int V_190 )
{
struct V_75 * V_75 ;
V_75 = V_116 -> V_191 -> V_192 [ V_190 ] ;
return V_75 ? V_75 -> V_193 : NULL ;
}
static int F_89 ( struct V_6 * V_6 ,
int V_13 , T_1 V_1 )
{
struct V_6 * V_194 ;
const struct V_116 * V_116 = V_6 -> V_116 ;
unsigned int V_195 = V_116 -> V_191 -> V_195 ;
T_4 V_51 = F_90 ( V_1 , 0 ) ;
T_4 * V_104 ;
T_5 V_106 = 0 ;
int V_79 = 0 ;
int V_103 ;
V_104 = F_68 ( V_195 , sizeof( T_4 ) , V_130 ) ;
if ( ! V_104 )
return - V_131 ;
for ( V_103 = 0 ; V_103 < V_195 ; V_103 ++ ) {
V_194 = F_88 ( V_116 , V_103 ) ;
if ( ! V_194 )
continue;
if ( ! F_7 ( V_194 ) )
continue;
if ( F_91 ( F_2 ( V_1 ) , V_194 -> V_196 ) ) {
V_104 [ V_106 ++ ] =
F_66 ( V_1 , V_194 -> V_167 ) ;
}
}
if ( V_106 == 0 )
goto V_197;
V_79 = F_69 ( V_6 , V_13 , V_1 ,
V_106 , V_104 , V_51 ) ;
if ( V_79 )
F_78 ( V_6 -> V_177 , L_5 , V_79 ) ;
V_197:
F_42 ( V_104 ) ;
return V_79 ;
}
static int F_92 ( struct V_6 * V_6 , int V_13 ,
T_1 V_1 , bool V_8 )
{
const struct V_116 * V_116 = V_6 -> V_116 ;
unsigned int V_195 = V_116 -> V_191 -> V_195 ;
struct V_6 * V_194 ;
bool V_173 = ! ( V_13 & V_128 ) ;
T_4 V_163 ;
int V_198 = 0 ;
int V_79 ;
int V_103 ;
if ( V_6 -> V_199 == V_200 ||
V_6 -> V_199 == V_201 ) {
V_163 = V_6 -> V_167 ;
V_79 = F_65 ( V_6 , V_13 ,
V_1 , V_163 , V_8 ) ;
if ( V_79 ) {
F_78 ( V_6 -> V_177 , L_6 ,
V_79 , V_163 ) ;
return V_79 ;
}
}
for ( V_103 = 0 ; V_103 < V_195 ; V_103 ++ ) {
V_194 = F_88 ( V_116 , V_103 ) ;
if ( V_194 && F_91 ( F_2 ( V_1 ) , V_194 -> V_196 ) )
V_198 ++ ;
}
if ( ( ! V_173 || V_198 != 1 ) && ( V_173 || V_198 != 0 ) )
return 0 ;
V_163 = 0 ;
V_79 = F_65 ( V_6 , V_13 ,
V_1 , V_163 , V_8 ) ;
if ( V_79 ) {
F_78 ( V_6 -> V_177 , L_7 , V_79 ) ;
return V_79 ;
}
return 0 ;
}
static int F_93 ( struct V_6 * V_6 , int V_13 ,
const struct V_202 * V_203 , T_1 V_1 )
{
T_4 V_22 = V_6 -> V_167 ;
T_4 V_25 = 0xffffffff ;
T_4 V_163 = 0 ;
const T_5 * V_59 = NULL ;
const T_5 * V_61 = NULL ;
T_1 V_31 = F_4 ( 0xffff ) ;
T_5 V_65 = 0 ;
T_5 V_67 = 0 ;
T_5 V_69 = 0 ;
T_5 V_71 = 0 ;
T_4 V_51 = F_66 ( V_1 , V_163 ) ;
int V_79 ;
V_79 = F_58 ( V_6 , V_13 ,
V_22 , V_25 ,
V_59 , V_61 ,
V_203 -> V_40 , V_203 -> V_42 ,
V_203 -> V_37 ,
V_1 , V_31 ,
V_65 , V_67 ,
V_69 , V_71 ,
V_51 ) ;
if ( V_79 )
F_78 ( V_6 -> V_177 , L_8 , V_79 ) ;
return V_79 ;
}
static int F_94 ( struct V_6 * V_6 ,
int V_13 , const struct V_202 * V_203 ,
T_1 V_1 )
{
enum V_129 V_27 =
V_95 ;
T_4 V_51 = F_90 ( V_1 , 0 ) ;
T_4 V_55 = 0 ;
int V_79 ;
if ( ! F_7 ( V_6 ) )
return 0 ;
V_79 = F_54 ( V_6 , V_13 ,
V_203 -> V_40 , V_203 -> V_42 ,
V_1 , V_55 ,
V_27 , V_51 , V_203 -> V_43 ) ;
if ( V_79 )
F_78 ( V_6 -> V_177 , L_9 , V_79 ) ;
return V_79 ;
}
static int F_95 ( struct V_6 * V_6 , int V_13 ,
const struct V_202 * V_203 , T_1 V_1 )
{
T_4 V_25 = 0xffffffff ;
T_1 V_31 = F_4 ( 0xffff ) ;
int V_79 ;
if ( F_2 ( V_1 ) == 0 )
V_1 = V_6 -> V_9 ;
V_79 = F_51 ( V_6 , V_6 -> V_167 , V_25 ,
V_203 -> V_37 , V_203 -> V_40 ,
V_203 -> V_42 , V_1 ,
V_31 , V_203 -> V_43 ,
V_13 ) ;
if ( V_79 )
F_78 ( V_6 -> V_177 , L_10 , V_79 ) ;
return V_79 ;
}
static int F_96 ( struct V_6 * V_6 , int V_13 ,
const struct V_202 * V_203 , T_1 V_1 )
{
if ( V_203 -> V_57 )
return F_93 ( V_6 , V_13 ,
V_203 , V_1 ) ;
if ( V_203 -> V_52 )
return F_94 ( V_6 , V_13 ,
V_203 , V_1 ) ;
if ( V_203 -> V_204 )
return F_95 ( V_6 , V_13 ,
V_203 , V_1 ) ;
return - V_205 ;
}
static int F_97 ( struct V_6 * V_6 , int V_13 ,
T_1 V_1 )
{
int V_79 = 0 ;
int V_103 ;
for ( V_103 = 0 ; V_103 < V_206 ; V_103 ++ ) {
if ( V_6 -> V_207 [ V_103 ] ) {
V_79 = F_96 ( V_6 , V_13 ,
& V_208 [ V_103 ] , V_1 ) ;
if ( V_79 )
return V_79 ;
}
}
return V_79 ;
}
static int F_98 ( struct V_6 * V_6 , int V_13 ,
const struct V_202 * V_203 )
{
T_2 V_7 ;
int V_79 = 0 ;
for ( V_7 = 1 ; V_7 < V_209 ; V_7 ++ ) {
if ( ! F_91 ( V_7 , V_6 -> V_196 ) )
continue;
V_79 = F_96 ( V_6 , V_13 ,
V_203 , F_4 ( V_7 ) ) ;
if ( V_79 )
break;
}
return V_79 ;
}
static int F_99 ( struct V_6 * V_6 , int V_13 ,
T_2 V_7 )
{
enum V_129 V_27 =
V_92 ;
T_4 V_22 = V_6 -> V_167 ;
T_1 V_1 = F_4 ( V_7 ) ;
T_1 V_31 = F_4 ( 0xffff ) ;
T_1 V_9 ;
bool V_32 ;
bool V_173 = ! ( V_13 & V_128 ) ;
int V_79 ;
V_9 = F_3 ( V_6 , V_7 , & V_32 ) ;
if ( V_173 &&
F_91 ( F_2 ( V_9 ) , V_6 -> V_196 ) )
return 0 ;
else if ( ! V_173 &&
! F_91 ( F_2 ( V_9 ) , V_6 -> V_196 ) )
return 0 ;
F_100 ( F_2 ( V_9 ) , V_6 -> V_196 ) ;
if ( V_173 ) {
V_79 = F_97 ( V_6 , V_13 ,
V_9 ) ;
if ( V_79 ) {
F_78 ( V_6 -> V_177 , L_11 , V_79 ) ;
goto V_210;
}
}
V_79 = F_92 ( V_6 , V_13 ,
V_9 , V_32 ) ;
if ( V_79 ) {
F_78 ( V_6 -> V_177 , L_12 , V_79 ) ;
goto V_211;
}
V_79 = F_89 ( V_6 , V_13 ,
V_9 ) ;
if ( V_79 ) {
F_78 ( V_6 -> V_177 , L_5 , V_79 ) ;
goto V_212;
}
V_79 = F_50 ( V_6 , V_13 ,
V_22 , V_1 , V_31 ,
V_27 , V_32 , V_9 ) ;
if ( V_79 )
F_78 ( V_6 -> V_177 , L_13 , V_79 ) ;
return 0 ;
V_210:
V_211:
V_212:
F_100 ( F_2 ( V_9 ) , V_6 -> V_196 ) ;
return V_79 ;
}
static int F_101 ( struct V_6 * V_6 , int V_13 )
{
enum V_129 V_27 ;
T_4 V_22 ;
T_4 V_25 ;
int V_79 ;
V_22 = 0 ;
V_25 = 0xffff0000 ;
V_27 = V_91 ;
V_79 = F_48 ( V_6 , V_13 ,
V_22 , V_25 ,
V_27 ) ;
if ( V_79 )
F_78 ( V_6 -> V_177 , L_14 , V_79 ) ;
return V_79 ;
}
static void F_102 ( struct V_213 * V_214 )
{
const struct V_215 * V_216 =
F_103 ( V_214 , struct V_215 , V_214 ) ;
bool V_175 = ( V_216 -> V_13 & V_128 ) ;
bool V_217 = ( V_216 -> V_13 & V_218 ) ;
struct V_219 V_220 ;
V_220 . V_221 = V_216 -> V_221 ;
V_220 . V_7 = V_216 -> V_7 ;
F_104 () ;
if ( V_217 && V_175 )
F_105 ( V_222 ,
V_216 -> V_6 -> V_177 , & V_220 . V_220 ) ;
else if ( V_217 && ! V_175 )
F_105 ( V_223 ,
V_216 -> V_6 -> V_177 , & V_220 . V_220 ) ;
F_106 () ;
F_42 ( V_214 ) ;
}
static int F_107 ( struct V_6 * V_6 ,
int V_13 , const T_5 * V_221 , T_1 V_1 )
{
struct V_215 * V_216 ;
enum V_129 V_27 =
V_95 ;
T_4 V_163 = V_6 -> V_167 ;
T_4 V_55 = 0 ;
T_4 V_51 = V_74 ;
bool V_43 = false ;
int V_79 ;
if ( F_7 ( V_6 ) )
V_51 = F_66 ( V_1 , V_163 ) ;
if ( ! ( V_13 & V_224 ) ) {
V_79 = F_54 ( V_6 , V_13 , V_221 ,
NULL , V_1 , V_55 , V_27 ,
V_51 , V_43 ) ;
if ( V_79 )
return V_79 ;
}
if ( ! F_7 ( V_6 ) )
return 0 ;
V_216 = F_49 ( sizeof( * V_216 ) , V_140 ) ;
if ( ! V_216 )
return - V_131 ;
F_108 ( & V_216 -> V_214 , F_102 ) ;
V_216 -> V_6 = V_6 ;
V_216 -> V_13 = V_13 ;
F_53 ( V_216 -> V_221 , V_221 ) ;
V_216 -> V_7 = F_5 ( V_6 , V_1 ) ;
F_109 ( & V_216 -> V_214 ) ;
return 0 ;
}
static struct V_225 *
F_110 ( const struct V_116 * V_116 ,
const struct V_225 * V_117 )
{
struct V_225 * V_118 ;
F_37 (ofdpa->fdb_tbl, found, entry, match->key_crc32)
if ( memcmp ( & V_118 -> V_20 , & V_117 -> V_20 , sizeof( V_118 -> V_20 ) ) == 0 )
return V_118 ;
return NULL ;
}
static int F_111 ( struct V_6 * V_6 ,
const unsigned char * V_221 ,
T_1 V_1 , int V_13 )
{
struct V_116 * V_116 = V_6 -> V_116 ;
struct V_225 * V_226 ;
struct V_225 * V_118 ;
bool V_175 = ( V_13 & V_128 ) ;
unsigned long V_120 ;
V_226 = F_49 ( sizeof( * V_226 ) , V_130 ) ;
if ( ! V_226 )
return - V_131 ;
V_226 -> V_217 = ( V_13 & V_218 ) ;
V_226 -> V_227 = V_228 ;
V_226 -> V_20 . V_6 = V_6 ;
F_53 ( V_226 -> V_20 . V_221 , V_221 ) ;
V_226 -> V_20 . V_1 = V_1 ;
V_226 -> V_121 = F_39 ( ~ 0 , & V_226 -> V_20 , sizeof( V_226 -> V_20 ) ) ;
F_40 ( & V_116 -> V_229 , V_120 ) ;
V_118 = F_110 ( V_116 , V_226 ) ;
if ( V_118 ) {
V_118 -> V_227 = V_228 ;
if ( V_175 ) {
F_42 ( V_226 ) ;
F_41 ( & V_118 -> V_18 ) ;
}
} else if ( ! V_175 ) {
F_43 ( V_116 -> V_230 , & V_226 -> V_18 ,
V_226 -> V_121 ) ;
}
F_44 ( & V_116 -> V_229 , V_120 ) ;
if ( ! V_118 != ! V_175 ) {
F_42 ( V_226 ) ;
if ( ! V_118 && V_175 )
return 0 ;
V_13 |= V_224 ;
}
return F_107 ( V_6 , V_13 , V_221 , V_1 ) ;
}
static int F_112 ( struct V_6 * V_6 , int V_13 )
{
struct V_116 * V_116 = V_6 -> V_116 ;
struct V_225 * V_118 ;
unsigned long V_120 ;
struct V_231 * V_232 ;
int V_233 ;
int V_79 = 0 ;
if ( V_6 -> V_199 == V_200 ||
V_6 -> V_199 == V_201 )
return 0 ;
V_13 |= V_14 | V_128 ;
F_40 ( & V_116 -> V_229 , V_120 ) ;
F_113 (ofdpa->fdb_tbl, bkt, tmp, found, entry) {
if ( V_118 -> V_20 . V_6 != V_6 )
continue;
if ( ! V_118 -> V_217 )
continue;
V_79 = F_107 ( V_6 , V_13 ,
V_118 -> V_20 . V_221 ,
V_118 -> V_20 . V_1 ) ;
if ( V_79 )
goto V_179;
F_41 ( & V_118 -> V_18 ) ;
}
V_179:
F_44 ( & V_116 -> V_229 , V_120 ) ;
return V_79 ;
}
static void F_114 ( unsigned long V_234 )
{
struct V_116 * V_116 = (struct V_116 * ) V_234 ;
struct V_6 * V_6 ;
struct V_225 * V_18 ;
struct V_231 * V_232 ;
unsigned long V_235 = V_228 + V_116 -> V_236 ;
unsigned long V_237 ;
unsigned long V_120 ;
int V_13 = V_14 | V_128 |
V_218 ;
int V_233 ;
F_40 ( & V_116 -> V_229 , V_120 ) ;
F_113 (ofdpa->fdb_tbl, bkt, tmp, entry, entry) {
if ( ! V_18 -> V_217 )
continue;
V_6 = V_18 -> V_20 . V_6 ;
V_237 = V_18 -> V_227 + V_6 -> V_236 ;
if ( F_115 ( V_237 , V_228 ) ) {
F_107 ( V_6 , V_13 ,
V_18 -> V_20 . V_221 ,
V_18 -> V_20 . V_1 ) ;
F_41 ( & V_18 -> V_18 ) ;
} else if ( F_116 ( V_237 , V_235 ) ) {
V_235 = V_237 ;
}
}
F_44 ( & V_116 -> V_229 , V_120 ) ;
F_117 ( & V_116 -> V_238 , F_118 ( V_235 ) ) ;
}
static int F_119 ( struct V_6 * V_6 ,
int V_13 , T_1 V_1 )
{
T_4 V_25 = 0xffffffff ;
T_1 V_37 ;
const T_5 * V_239 = V_141 ;
T_1 V_31 = F_4 ( 0xffff ) ;
bool V_43 = false ;
int V_79 ;
if ( F_2 ( V_1 ) == 0 )
V_1 = V_6 -> V_9 ;
V_37 = F_4 ( V_62 ) ;
V_79 = F_51 ( V_6 , V_6 -> V_167 ,
V_25 , V_37 ,
V_6 -> V_177 -> V_180 ,
V_239 , V_1 , V_31 ,
V_43 , V_13 ) ;
if ( V_79 )
return V_79 ;
V_37 = F_4 ( V_63 ) ;
V_79 = F_51 ( V_6 , V_6 -> V_167 ,
V_25 , V_37 ,
V_6 -> V_177 -> V_180 ,
V_239 , V_1 , V_31 ,
V_43 , V_13 ) ;
return V_79 ;
}
static int F_120 ( struct V_6 * V_6 , int V_13 )
{
bool V_8 ;
T_4 V_163 ;
T_1 V_1 ;
T_2 V_7 ;
int V_79 ;
if ( V_6 -> V_199 != V_200 &&
V_6 -> V_199 != V_201 )
V_13 |= V_128 ;
V_163 = V_6 -> V_167 ;
for ( V_7 = 1 ; V_7 < V_209 ; V_7 ++ ) {
if ( ! F_91 ( V_7 , V_6 -> V_196 ) )
continue;
V_1 = F_4 ( V_7 ) ;
V_8 = F_1 ( V_1 ) ;
V_79 = F_65 ( V_6 , V_13 ,
V_1 , V_163 , V_8 ) ;
if ( V_79 ) {
F_78 ( V_6 -> V_177 , L_6 ,
V_79 , V_163 ) ;
return V_79 ;
}
}
return 0 ;
}
static int F_121 ( struct V_6 * V_6 ,
int V_13 , T_5 V_240 )
{
bool V_241 [ V_206 ] = { 0 , } ;
bool V_242 [ V_206 ] ;
T_5 V_243 ;
int V_79 ;
int V_103 ;
memcpy ( V_242 , V_6 -> V_207 , sizeof( V_242 ) ) ;
V_243 = V_6 -> V_199 ;
if ( V_6 -> V_199 == V_240 )
return 0 ;
V_6 -> V_199 = V_240 ;
switch ( V_240 ) {
case V_244 :
break;
case V_245 :
case V_246 :
V_241 [ V_247 ] = true ;
break;
case V_200 :
case V_201 :
if ( ! F_8 ( V_6 ) )
V_241 [ V_247 ] = true ;
V_241 [ V_248 ] = true ;
V_241 [ V_249 ] = true ;
if ( F_7 ( V_6 ) )
V_241 [ V_250 ] = true ;
else if ( F_8 ( V_6 ) )
V_241 [ V_251 ] = true ;
else
V_241 [ V_252 ] = true ;
break;
}
for ( V_103 = 0 ; V_103 < V_206 ; V_103 ++ ) {
if ( V_241 [ V_103 ] != V_6 -> V_207 [ V_103 ] ) {
int V_253 = V_13 |
( V_241 [ V_103 ] ? 0 : V_128 ) ;
V_79 = F_98 ( V_6 , V_253 ,
& V_208 [ V_103 ] ) ;
if ( V_79 )
goto V_254;
V_6 -> V_207 [ V_103 ] = V_241 [ V_103 ] ;
}
}
V_79 = F_112 ( V_6 , V_13 ) ;
if ( V_79 )
goto V_255;
V_79 = F_120 ( V_6 , V_13 ) ;
if ( V_79 )
goto V_256;
return 0 ;
V_254:
V_255:
V_256:
memcpy ( V_6 -> V_207 , V_242 , sizeof( V_242 ) ) ;
V_6 -> V_199 = V_243 ;
return V_79 ;
}
static int F_122 ( struct V_6 * V_6 , int V_13 )
{
if ( F_7 ( V_6 ) )
return 0 ;
return F_121 ( V_6 , V_13 ,
V_201 ) ;
}
static int F_123 ( struct V_6 * V_6 , int V_13 )
{
if ( F_7 ( V_6 ) )
return 0 ;
return F_121 ( V_6 , V_13 ,
V_244 ) ;
}
static int F_124 ( struct V_6 * V_6 ,
T_2 V_7 , T_2 V_13 )
{
int V_79 ;
V_79 = F_99 ( V_6 , 0 , V_7 ) ;
if ( V_79 )
return V_79 ;
V_79 = F_119 ( V_6 , 0 , F_4 ( V_7 ) ) ;
if ( V_79 )
F_99 ( V_6 ,
V_128 , V_7 ) ;
return V_79 ;
}
static int F_125 ( struct V_6 * V_6 ,
T_2 V_7 , T_2 V_13 )
{
int V_79 ;
V_79 = F_119 ( V_6 , V_128 ,
F_4 ( V_7 ) ) ;
if ( V_79 )
return V_79 ;
return F_99 ( V_6 , V_128 ,
V_7 ) ;
}
static struct V_257 *
F_126 ( const struct V_116 * V_116 , int V_258 )
{
struct V_257 * V_118 ;
F_37 (ofdpa->internal_vlan_tbl, found,
entry, ifindex) {
if ( V_118 -> V_258 == V_258 )
return V_118 ;
}
return NULL ;
}
static T_1 F_127 ( struct V_6 * V_6 ,
int V_258 )
{
struct V_116 * V_116 = V_6 -> V_116 ;
struct V_257 * V_18 ;
struct V_257 * V_118 ;
unsigned long V_120 ;
int V_103 ;
V_18 = F_49 ( sizeof( * V_18 ) , V_130 ) ;
if ( ! V_18 )
return 0 ;
V_18 -> V_258 = V_258 ;
F_40 ( & V_116 -> V_259 , V_120 ) ;
V_118 = F_126 ( V_116 , V_258 ) ;
if ( V_118 ) {
F_42 ( V_18 ) ;
goto V_118;
}
V_118 = V_18 ;
F_43 ( V_116 -> V_260 , & V_118 -> V_18 , V_118 -> V_258 ) ;
for ( V_103 = 0 ; V_103 < V_261 ; V_103 ++ ) {
if ( F_128 ( V_103 , V_116 -> V_262 ) )
continue;
V_118 -> V_1 = F_4 ( V_3 + V_103 ) ;
goto V_118;
}
F_78 ( V_6 -> V_177 , L_15 ) ;
V_118:
V_118 -> V_171 ++ ;
F_44 ( & V_116 -> V_259 , V_120 ) ;
return V_118 -> V_1 ;
}
static int F_129 ( struct V_6 * V_6 , T_6 V_149 ,
int V_263 , struct V_151 * V_152 , T_4 V_264 ,
int V_13 )
{
const struct V_265 * V_266 ;
T_1 V_37 = F_4 ( V_62 ) ;
T_6 V_150 = F_79 ( V_263 ) ;
T_1 V_9 = V_6 -> V_9 ;
T_4 V_86 = V_152 -> V_267 ;
enum V_129 V_27 =
V_95 ;
T_4 V_51 ;
bool V_268 ;
bool V_269 ;
T_4 V_164 ;
int V_79 ;
V_266 = V_152 -> V_265 ;
V_268 = ( V_152 -> V_270 == V_6 -> V_177 ) ;
V_269 = ! ! V_266 -> V_271 ;
if ( V_269 && V_268 ) {
V_79 = F_87 ( V_6 , V_13 ,
V_266 -> V_271 , & V_164 ) ;
if ( V_79 )
return V_79 ;
V_51 = F_71 ( V_164 ) ;
} else {
V_51 = F_66 ( V_9 , 0 ) ;
}
V_79 = F_56 ( V_6 , V_37 , V_149 ,
V_150 , V_86 , V_27 ,
V_51 , V_152 , V_13 ) ;
if ( V_79 )
F_78 ( V_6 -> V_177 , L_16 ,
V_79 , & V_149 ) ;
return V_79 ;
}
static void
F_130 ( const struct V_6 * V_6 ,
int V_258 )
{
struct V_116 * V_116 = V_6 -> V_116 ;
struct V_257 * V_118 ;
unsigned long V_120 ;
unsigned long V_272 ;
F_40 ( & V_116 -> V_259 , V_120 ) ;
V_118 = F_126 ( V_116 , V_258 ) ;
if ( ! V_118 ) {
F_78 ( V_6 -> V_177 ,
L_17 ,
V_258 ) ;
goto V_273;
}
if ( -- V_118 -> V_171 <= 0 ) {
V_272 = F_2 ( V_118 -> V_1 ) - V_3 ;
F_131 ( V_272 , V_116 -> V_262 ) ;
F_41 ( & V_118 -> V_18 ) ;
F_42 ( V_118 ) ;
}
V_273:
F_44 ( & V_116 -> V_259 , V_120 ) ;
}
static int F_132 ( struct V_191 * V_191 )
{
struct V_116 * V_116 = V_191 -> V_193 ;
V_116 -> V_191 = V_191 ;
F_133 ( V_116 -> V_126 ) ;
F_134 ( & V_116 -> V_122 ) ;
F_133 ( V_116 -> V_161 ) ;
F_134 ( & V_116 -> V_158 ) ;
F_133 ( V_116 -> V_230 ) ;
F_134 ( & V_116 -> V_229 ) ;
F_133 ( V_116 -> V_260 ) ;
F_134 ( & V_116 -> V_259 ) ;
F_133 ( V_116 -> V_172 ) ;
F_134 ( & V_116 -> V_176 ) ;
F_135 ( & V_116 -> V_238 , F_114 ,
( unsigned long ) V_116 ) ;
F_117 ( & V_116 -> V_238 , V_228 ) ;
V_116 -> V_236 = V_274 ;
return 0 ;
}
static void F_136 ( struct V_191 * V_191 )
{
struct V_116 * V_116 = V_191 -> V_193 ;
unsigned long V_13 ;
struct V_17 * V_275 ;
struct V_97 * V_276 ;
struct V_225 * V_277 ;
struct V_257 * V_278 ;
struct V_168 * V_279 ;
struct V_231 * V_232 ;
int V_233 ;
F_137 ( & V_116 -> V_238 ) ;
F_138 ( V_191 -> V_280 ) ;
F_40 ( & V_116 -> V_122 , V_13 ) ;
F_113 (ofdpa->flow_tbl, bkt, tmp, flow_entry, entry)
F_41 ( & V_275 -> V_18 ) ;
F_44 ( & V_116 -> V_122 , V_13 ) ;
F_40 ( & V_116 -> V_158 , V_13 ) ;
F_113 (ofdpa->group_tbl, bkt, tmp, group_entry, entry)
F_41 ( & V_276 -> V_18 ) ;
F_44 ( & V_116 -> V_158 , V_13 ) ;
F_40 ( & V_116 -> V_229 , V_13 ) ;
F_113 (ofdpa->fdb_tbl, bkt, tmp, fdb_entry, entry)
F_41 ( & V_277 -> V_18 ) ;
F_44 ( & V_116 -> V_229 , V_13 ) ;
F_40 ( & V_116 -> V_259 , V_13 ) ;
F_113 (ofdpa->internal_vlan_tbl, bkt,
tmp, internal_vlan_entry, entry)
F_41 ( & V_278 -> V_18 ) ;
F_44 ( & V_116 -> V_259 , V_13 ) ;
F_40 ( & V_116 -> V_176 , V_13 ) ;
F_113 (ofdpa->neigh_tbl, bkt, tmp, neigh_entry, entry)
F_41 ( & V_279 -> V_18 ) ;
F_44 ( & V_116 -> V_176 , V_13 ) ;
}
static int F_139 ( struct V_75 * V_75 )
{
struct V_6 * V_6 = V_75 -> V_193 ;
V_6 -> V_116 = V_75 -> V_191 -> V_193 ;
V_6 -> V_75 = V_75 ;
V_6 -> V_177 = V_75 -> V_177 ;
V_6 -> V_167 = V_75 -> V_167 ;
V_6 -> V_281 = V_282 ;
V_6 -> V_236 = V_274 ;
return 0 ;
}
static int F_140 ( struct V_75 * V_75 )
{
struct V_6 * V_6 = V_75 -> V_193 ;
int V_79 ;
F_141 ( V_75 ,
! ! ( V_6 -> V_281 & V_282 ) ) ;
V_79 = F_101 ( V_6 , 0 ) ;
if ( V_79 ) {
F_78 ( V_6 -> V_177 , L_18 ) ;
return V_79 ;
}
V_6 -> V_9 =
F_127 ( V_6 ,
V_6 -> V_177 -> V_258 ) ;
V_79 = F_124 ( V_6 , V_283 , 0 ) ;
if ( V_79 ) {
F_78 ( V_6 -> V_177 , L_19 ) ;
goto V_284;
}
return 0 ;
V_284:
F_101 ( V_6 , V_128 ) ;
return V_79 ;
}
static void F_142 ( struct V_75 * V_75 )
{
struct V_6 * V_6 = V_75 -> V_193 ;
F_101 ( V_6 , V_128 ) ;
}
static int F_143 ( struct V_75 * V_75 )
{
struct V_6 * V_6 = V_75 -> V_193 ;
return F_122 ( V_6 , 0 ) ;
}
static void F_144 ( struct V_75 * V_75 )
{
struct V_6 * V_6 = V_75 -> V_193 ;
F_123 ( V_6 , V_14 ) ;
}
static int F_145 ( struct V_75 * V_75 ,
T_5 V_240 )
{
struct V_6 * V_6 = V_75 -> V_193 ;
return F_121 ( V_6 , 0 , V_240 ) ;
}
static int F_146 ( struct V_75 * V_75 ,
unsigned long V_281 ,
struct V_285 * V_286 )
{
struct V_6 * V_6 = V_75 -> V_193 ;
unsigned long V_287 ;
int V_79 = 0 ;
V_287 = V_6 -> V_281 ;
V_6 -> V_281 = V_281 ;
if ( ( V_287 ^ V_6 -> V_281 ) & V_282 &&
! F_147 ( V_286 ) )
V_79 = F_141 ( V_6 -> V_75 ,
! ! ( V_6 -> V_281 & V_282 ) ) ;
if ( F_147 ( V_286 ) )
V_6 -> V_281 = V_287 ;
return V_79 ;
}
static int
F_148 ( const struct V_75 * V_75 ,
unsigned long * V_288 )
{
const struct V_6 * V_6 = V_75 -> V_193 ;
* V_288 = V_6 -> V_281 ;
return 0 ;
}
static int
F_149 ( const struct V_75 *
V_75 ,
unsigned long *
V_289 )
{
* V_289 = V_282 ;
return 0 ;
}
static int
F_150 ( struct V_75 * V_75 ,
T_4 V_236 ,
struct V_285 * V_286 )
{
struct V_6 * V_6 = V_75 -> V_193 ;
struct V_116 * V_116 = V_6 -> V_116 ;
if ( ! F_147 ( V_286 ) ) {
V_6 -> V_236 = F_151 ( V_236 ) ;
if ( V_6 -> V_236 < V_116 -> V_236 )
V_116 -> V_236 = V_6 -> V_236 ;
F_117 ( & V_6 -> V_116 -> V_238 , V_228 ) ;
}
return 0 ;
}
static int F_152 ( struct V_75 * V_75 ,
const struct V_290 * V_28 )
{
struct V_6 * V_6 = V_75 -> V_193 ;
T_2 V_7 ;
int V_79 ;
for ( V_7 = V_28 -> V_291 ; V_7 <= V_28 -> V_292 ; V_7 ++ ) {
V_79 = F_124 ( V_6 , V_7 , V_28 -> V_13 ) ;
if ( V_79 )
return V_79 ;
}
return 0 ;
}
static int F_153 ( struct V_75 * V_75 ,
const struct V_290 * V_28 )
{
struct V_6 * V_6 = V_75 -> V_193 ;
T_2 V_7 ;
int V_79 ;
for ( V_7 = V_28 -> V_291 ; V_7 <= V_28 -> V_292 ; V_7 ++ ) {
V_79 = F_125 ( V_6 , V_7 , V_28 -> V_13 ) ;
if ( V_79 )
return V_79 ;
}
return 0 ;
}
static int F_154 ( struct V_75 * V_75 ,
T_2 V_7 , const unsigned char * V_221 )
{
struct V_6 * V_6 = V_75 -> V_193 ;
T_1 V_1 = F_3 ( V_6 , V_7 , NULL ) ;
if ( ! F_7 ( V_6 ) )
return - V_293 ;
return F_111 ( V_6 , V_221 , V_1 , 0 ) ;
}
static int F_155 ( struct V_75 * V_75 ,
T_2 V_7 , const unsigned char * V_221 )
{
struct V_6 * V_6 = V_75 -> V_193 ;
T_1 V_1 = F_3 ( V_6 , V_7 , NULL ) ;
int V_13 = V_128 ;
if ( ! F_7 ( V_6 ) )
return - V_293 ;
return F_111 ( V_6 , V_221 , V_1 , V_13 ) ;
}
static int F_156 ( struct V_6 * V_6 ,
struct V_181 * V_52 )
{
int V_79 ;
V_79 = F_125 ( V_6 , V_283 , 0 ) ;
if ( V_79 )
return V_79 ;
F_130 ( V_6 ,
V_6 -> V_177 -> V_258 ) ;
V_6 -> V_9 =
F_127 ( V_6 , V_52 -> V_258 ) ;
V_6 -> V_11 = V_52 ;
return F_124 ( V_6 , V_283 , 0 ) ;
}
static int F_157 ( struct V_6 * V_6 )
{
int V_79 ;
V_79 = F_125 ( V_6 , V_283 , 0 ) ;
if ( V_79 )
return V_79 ;
F_130 ( V_6 ,
V_6 -> V_11 -> V_258 ) ;
V_6 -> V_9 =
F_127 ( V_6 ,
V_6 -> V_177 -> V_258 ) ;
V_6 -> V_11 = NULL ;
V_79 = F_124 ( V_6 , V_283 , 0 ) ;
if ( V_79 )
return V_79 ;
if ( V_6 -> V_177 -> V_13 & V_294 )
V_79 = F_122 ( V_6 , 0 ) ;
return V_79 ;
}
static int F_158 ( struct V_6 * V_6 ,
struct V_181 * V_295 )
{
int V_79 ;
V_6 -> V_11 = V_295 ;
V_79 = F_123 ( V_6 , 0 ) ;
if ( V_79 )
return V_79 ;
V_79 = F_122 ( V_6 , 0 ) ;
return V_79 ;
}
static int F_159 ( struct V_75 * V_75 ,
struct V_181 * V_295 )
{
struct V_6 * V_6 = V_75 -> V_193 ;
int V_79 = 0 ;
if ( F_160 ( V_295 ) )
V_79 = F_156 ( V_6 , V_295 ) ;
else if ( F_161 ( V_295 ) )
V_79 = F_158 ( V_6 , V_295 ) ;
return V_79 ;
}
static int F_162 ( struct V_75 * V_75 ,
struct V_181 * V_295 )
{
struct V_6 * V_6 = V_75 -> V_193 ;
int V_79 = 0 ;
if ( F_7 ( V_6 ) )
V_79 = F_157 ( V_6 ) ;
else if ( F_8 ( V_6 ) )
V_79 = F_158 ( V_6 , NULL ) ;
return V_79 ;
}
static int F_163 ( struct V_75 * V_75 ,
struct V_182 * V_183 )
{
struct V_6 * V_6 = V_75 -> V_193 ;
int V_13 = ( V_183 -> V_186 & V_187 ? 0 : V_128 ) |
V_14 ;
T_6 V_169 = * ( T_6 * ) V_183 -> V_296 ;
return F_77 ( V_6 , V_13 , V_169 , V_183 -> V_188 ) ;
}
static int F_164 ( struct V_75 * V_75 ,
struct V_182 * V_183 )
{
struct V_6 * V_6 = V_75 -> V_193 ;
int V_13 = V_128 | V_14 ;
T_6 V_169 = * ( T_6 * ) V_183 -> V_296 ;
return F_77 ( V_6 , V_13 , V_169 , V_183 -> V_188 ) ;
}
static int F_165 ( struct V_75 * V_75 ,
const unsigned char * V_221 ,
T_1 V_1 )
{
struct V_6 * V_6 = V_75 -> V_193 ;
int V_13 = V_14 | V_218 ;
if ( V_6 -> V_199 != V_200 &&
V_6 -> V_199 != V_201 )
return 0 ;
return F_111 ( V_6 , V_221 , V_1 , V_13 ) ;
}
static struct V_6 * F_166 ( struct V_181 * V_177 ,
struct V_191 * V_191 )
{
struct V_75 * V_75 ;
V_75 = F_167 ( V_177 , V_191 ) ;
return V_75 ? V_75 -> V_193 : NULL ;
}
static int F_168 ( struct V_191 * V_191 ,
const struct V_297 * V_298 )
{
struct V_116 * V_116 = V_191 -> V_193 ;
struct V_6 * V_6 ;
int V_79 ;
if ( V_116 -> V_299 )
return 0 ;
V_6 = F_166 ( V_298 -> V_152 -> V_270 , V_191 ) ;
if ( ! V_6 )
return 0 ;
V_79 = F_129 ( V_6 , F_169 ( V_298 -> V_149 ) ,
V_298 -> V_263 , V_298 -> V_152 ,
V_298 -> V_264 , 0 ) ;
if ( V_79 )
return V_79 ;
V_298 -> V_152 -> V_265 -> V_300 |= V_301 ;
return 0 ;
}
static int F_170 ( struct V_191 * V_191 ,
const struct V_297 * V_298 )
{
struct V_116 * V_116 = V_191 -> V_193 ;
struct V_6 * V_6 ;
if ( V_116 -> V_299 )
return 0 ;
V_6 = F_166 ( V_298 -> V_152 -> V_270 , V_191 ) ;
if ( ! V_6 )
return 0 ;
V_298 -> V_152 -> V_265 -> V_300 &= ~ V_301 ;
return F_129 ( V_6 , F_169 ( V_298 -> V_149 ) ,
V_298 -> V_263 , V_298 -> V_152 ,
V_298 -> V_264 , V_128 ) ;
}
static void F_171 ( struct V_191 * V_191 )
{
struct V_116 * V_116 = V_191 -> V_193 ;
struct V_6 * V_6 ;
struct V_17 * V_275 ;
struct V_231 * V_232 ;
unsigned long V_13 ;
int V_233 ;
if ( V_116 -> V_299 )
return;
F_40 ( & V_116 -> V_122 , V_13 ) ;
F_113 (ofdpa->flow_tbl, bkt, tmp, flow_entry, entry) {
if ( V_275 -> V_20 . V_84 !=
V_93 )
continue;
V_6 = F_166 ( V_275 -> V_152 -> V_270 ,
V_191 ) ;
if ( ! V_6 )
continue;
V_275 -> V_152 -> V_265 -> V_300 &= ~ V_301 ;
F_46 ( V_6 , V_128 ,
V_275 ) ;
}
F_44 ( & V_116 -> V_122 , V_13 ) ;
V_116 -> V_299 = true ;
}
