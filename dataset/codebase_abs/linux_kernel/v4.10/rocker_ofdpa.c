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
static void * F_10 ( struct V_15 * V_16 , int V_13 ,
T_3 V_17 )
{
struct V_18 * V_19 = NULL ;
T_4 V_20 = ( V_13 & V_14 ) ?
V_21 : V_22 ;
if ( ! V_16 ) {
V_19 = F_11 ( V_17 + sizeof( * V_19 ) , V_20 ) ;
} else if ( F_12 ( V_16 ) ) {
V_19 = F_11 ( V_17 + sizeof( * V_19 ) , V_20 ) ;
if ( ! V_19 )
return NULL ;
F_13 ( V_16 , V_19 , V_23 , V_19 ) ;
} else {
V_19 = F_14 ( V_16 ) ;
}
return V_19 ? V_19 + 1 : NULL ;
}
static void * F_15 ( struct V_15 * V_16 , int V_13 ,
T_3 V_17 )
{
return F_10 ( V_16 , V_13 , V_17 ) ;
}
static void * F_16 ( struct V_15 * V_16 , int V_13 ,
T_3 V_24 , T_3 V_17 )
{
return F_10 ( V_16 , V_13 , V_24 * V_17 ) ;
}
static void F_17 ( struct V_15 * V_16 , const void * V_25 )
{
struct V_18 * V_19 ;
if ( F_12 ( V_16 ) )
return;
V_19 = (struct V_18 * ) V_25 - 1 ;
V_23 ( V_19 ) ;
}
static int
F_18 ( struct V_26 * V_27 ,
const struct V_28 * V_29 )
{
if ( F_19 ( V_27 , V_30 ,
V_29 -> V_31 . V_32 . V_33 ) )
return - V_34 ;
if ( F_19 ( V_27 , V_35 ,
V_29 -> V_31 . V_32 . V_36 ) )
return - V_34 ;
if ( F_20 ( V_27 , V_37 ,
V_29 -> V_31 . V_32 . V_38 ) )
return - V_34 ;
return 0 ;
}
static int
F_21 ( struct V_26 * V_27 ,
const struct V_28 * V_29 )
{
if ( F_19 ( V_27 , V_30 ,
V_29 -> V_31 . V_39 . V_33 ) )
return - V_34 ;
if ( F_22 ( V_27 , V_40 ,
V_29 -> V_31 . V_39 . V_1 ) )
return - V_34 ;
if ( F_22 ( V_27 , V_41 ,
V_29 -> V_31 . V_39 . V_42 ) )
return - V_34 ;
if ( F_20 ( V_27 , V_37 ,
V_29 -> V_31 . V_39 . V_38 ) )
return - V_34 ;
if ( V_29 -> V_31 . V_39 . V_43 &&
F_22 ( V_27 , V_44 ,
V_29 -> V_31 . V_39 . V_45 ) )
return - V_34 ;
return 0 ;
}
static int
F_23 ( struct V_26 * V_27 ,
const struct V_28 * V_29 )
{
if ( F_19 ( V_27 , V_30 ,
V_29 -> V_31 . V_46 . V_33 ) )
return - V_34 ;
if ( F_19 ( V_27 , V_35 ,
V_29 -> V_31 . V_46 . V_36 ) )
return - V_34 ;
if ( F_22 ( V_27 , V_47 ,
V_29 -> V_31 . V_46 . V_48 ) )
return - V_34 ;
if ( F_24 ( V_27 , V_49 ,
V_50 , V_29 -> V_31 . V_46 . V_51 ) )
return - V_34 ;
if ( F_24 ( V_27 , V_52 ,
V_50 , V_29 -> V_31 . V_46 . V_53 ) )
return - V_34 ;
if ( F_22 ( V_27 , V_40 ,
V_29 -> V_31 . V_46 . V_1 ) )
return - V_34 ;
if ( F_22 ( V_27 , V_41 ,
V_29 -> V_31 . V_46 . V_42 ) )
return - V_34 ;
if ( F_20 ( V_27 , V_37 ,
V_29 -> V_31 . V_46 . V_38 ) )
return - V_34 ;
if ( V_29 -> V_31 . V_46 . V_54 &&
F_25 ( V_27 , V_55 ,
V_29 -> V_31 . V_46 . V_54 ) )
return - V_34 ;
return 0 ;
}
static int
F_26 ( struct V_26 * V_27 ,
const struct V_28 * V_29 )
{
if ( F_22 ( V_27 , V_47 ,
V_29 -> V_31 . V_56 . V_48 ) )
return - V_34 ;
if ( F_27 ( V_27 , V_57 ,
V_29 -> V_31 . V_56 . V_58 ) )
return - V_34 ;
if ( F_27 ( V_27 , V_59 ,
V_29 -> V_31 . V_56 . V_60 ) )
return - V_34 ;
if ( F_20 ( V_27 , V_37 ,
V_29 -> V_31 . V_56 . V_38 ) )
return - V_34 ;
if ( F_19 ( V_27 , V_61 ,
V_29 -> V_31 . V_56 . V_62 ) )
return - V_34 ;
return 0 ;
}
static int
F_28 ( struct V_26 * V_27 ,
const struct V_28 * V_29 )
{
if ( V_29 -> V_31 . V_63 . V_64 &&
F_24 ( V_27 , V_49 ,
V_50 , V_29 -> V_31 . V_63 . V_51 ) )
return - V_34 ;
if ( V_29 -> V_31 . V_63 . V_65 &&
F_24 ( V_27 , V_52 ,
V_50 , V_29 -> V_31 . V_63 . V_53 ) )
return - V_34 ;
if ( V_29 -> V_31 . V_63 . V_1 &&
F_22 ( V_27 , V_40 ,
V_29 -> V_31 . V_63 . V_1 ) )
return - V_34 ;
if ( V_29 -> V_31 . V_63 . V_66 &&
F_19 ( V_27 , V_67 ,
V_29 -> V_31 . V_63 . V_66 ) )
return - V_34 ;
if ( F_20 ( V_27 , V_37 ,
V_29 -> V_31 . V_63 . V_38 ) )
return - V_34 ;
if ( F_19 ( V_27 , V_61 ,
V_29 -> V_31 . V_63 . V_62 ) )
return - V_34 ;
if ( V_29 -> V_31 . V_63 . V_54 &&
F_25 ( V_27 , V_55 ,
V_29 -> V_31 . V_63 . V_54 ) )
return - V_34 ;
return 0 ;
}
static int
F_29 ( struct V_26 * V_27 ,
const struct V_28 * V_29 )
{
if ( F_19 ( V_27 , V_30 ,
V_29 -> V_31 . V_68 . V_33 ) )
return - V_34 ;
if ( F_19 ( V_27 , V_35 ,
V_29 -> V_31 . V_68 . V_36 ) )
return - V_34 ;
if ( F_24 ( V_27 , V_69 ,
V_50 , V_29 -> V_31 . V_68 . V_70 ) )
return - V_34 ;
if ( F_24 ( V_27 , V_71 ,
V_50 , V_29 -> V_31 . V_68 . V_72 ) )
return - V_34 ;
if ( F_24 ( V_27 , V_49 ,
V_50 , V_29 -> V_31 . V_68 . V_51 ) )
return - V_34 ;
if ( F_24 ( V_27 , V_52 ,
V_50 , V_29 -> V_31 . V_68 . V_53 ) )
return - V_34 ;
if ( F_22 ( V_27 , V_47 ,
V_29 -> V_31 . V_68 . V_48 ) )
return - V_34 ;
if ( F_22 ( V_27 , V_40 ,
V_29 -> V_31 . V_68 . V_1 ) )
return - V_34 ;
if ( F_22 ( V_27 , V_41 ,
V_29 -> V_31 . V_68 . V_42 ) )
return - V_34 ;
switch ( F_2 ( V_29 -> V_31 . V_68 . V_48 ) ) {
case V_73 :
case V_74 :
if ( F_25 ( V_27 , V_75 ,
V_29 -> V_31 . V_68 . V_76 ) )
return - V_34 ;
if ( F_25 ( V_27 ,
V_77 ,
V_29 -> V_31 . V_68 . V_78 ) )
return - V_34 ;
if ( F_25 ( V_27 , V_79 ,
V_29 -> V_31 . V_68 . V_80 & 0x3f ) )
return - V_34 ;
if ( F_25 ( V_27 ,
V_81 ,
V_29 -> V_31 . V_68 . V_82 & 0x3f ) )
return - V_34 ;
if ( F_25 ( V_27 , V_83 ,
( V_29 -> V_31 . V_68 . V_80 & 0xc0 ) >> 6 ) )
return - V_34 ;
if ( F_25 ( V_27 ,
V_84 ,
( V_29 -> V_31 . V_68 . V_82 & 0xc0 ) >> 6 ) )
return - V_34 ;
break;
}
if ( V_29 -> V_31 . V_68 . V_62 != V_85 &&
F_19 ( V_27 , V_61 ,
V_29 -> V_31 . V_68 . V_62 ) )
return - V_34 ;
return 0 ;
}
static int F_30 ( const struct V_86 * V_86 ,
struct V_26 * V_27 ,
void * V_87 )
{
const struct V_28 * V_29 = V_87 ;
struct V_88 * V_89 ;
int V_90 = 0 ;
if ( F_20 ( V_27 , V_91 , V_29 -> V_92 ) )
return - V_34 ;
V_89 = F_31 ( V_27 , V_93 ) ;
if ( ! V_89 )
return - V_34 ;
if ( F_20 ( V_27 , V_94 ,
V_29 -> V_31 . V_95 ) )
return - V_34 ;
if ( F_19 ( V_27 , V_96 ,
V_29 -> V_31 . V_97 ) )
return - V_34 ;
if ( F_19 ( V_27 , V_98 , 0 ) )
return - V_34 ;
if ( F_32 ( V_27 , V_99 ,
V_29 -> V_100 ) )
return - V_34 ;
switch ( V_29 -> V_31 . V_95 ) {
case V_101 :
V_90 = F_18 ( V_27 , V_29 ) ;
break;
case V_102 :
V_90 = F_21 ( V_27 , V_29 ) ;
break;
case V_103 :
V_90 = F_23 ( V_27 , V_29 ) ;
break;
case V_104 :
V_90 = F_26 ( V_27 , V_29 ) ;
break;
case V_105 :
V_90 = F_28 ( V_27 , V_29 ) ;
break;
case V_106 :
V_90 = F_29 ( V_27 , V_29 ) ;
break;
default:
V_90 = - V_107 ;
break;
}
if ( V_90 )
return V_90 ;
F_33 ( V_27 , V_89 ) ;
return 0 ;
}
static int F_34 ( const struct V_86 * V_86 ,
struct V_26 * V_27 ,
void * V_87 )
{
const struct V_28 * V_29 = V_87 ;
struct V_88 * V_89 ;
if ( F_20 ( V_27 , V_91 , V_29 -> V_92 ) )
return - V_34 ;
V_89 = F_31 ( V_27 , V_93 ) ;
if ( ! V_89 )
return - V_34 ;
if ( F_32 ( V_27 , V_99 ,
V_29 -> V_100 ) )
return - V_34 ;
F_33 ( V_27 , V_89 ) ;
return 0 ;
}
static int
F_35 ( struct V_26 * V_27 ,
struct V_108 * V_29 )
{
if ( F_19 ( V_27 , V_109 ,
F_36 ( V_29 -> V_62 ) ) )
return - V_34 ;
if ( F_25 ( V_27 , V_110 ,
V_29 -> V_111 . V_8 ) )
return - V_34 ;
return 0 ;
}
static int
F_37 ( struct V_26 * V_27 ,
const struct V_108 * V_29 )
{
if ( F_19 ( V_27 , V_112 ,
V_29 -> V_113 . V_62 ) )
return - V_34 ;
if ( ! F_38 ( V_29 -> V_113 . V_70 ) &&
F_24 ( V_27 , V_69 ,
V_50 , V_29 -> V_113 . V_70 ) )
return - V_34 ;
if ( ! F_38 ( V_29 -> V_113 . V_51 ) &&
F_24 ( V_27 , V_49 ,
V_50 , V_29 -> V_113 . V_51 ) )
return - V_34 ;
if ( V_29 -> V_113 . V_1 &&
F_22 ( V_27 , V_40 ,
V_29 -> V_113 . V_1 ) )
return - V_34 ;
return 0 ;
}
static int
F_39 ( struct V_26 * V_27 ,
const struct V_108 * V_29 )
{
int V_114 ;
struct V_88 * V_115 ;
if ( F_20 ( V_27 , V_116 ,
V_29 -> V_117 ) )
return - V_34 ;
V_115 = F_31 ( V_27 ,
V_118 ) ;
if ( ! V_115 )
return - V_34 ;
for ( V_114 = 0 ; V_114 < V_29 -> V_117 ; V_114 ++ )
if ( F_19 ( V_27 , V_114 + 1 , V_29 -> V_115 [ V_114 ] ) )
return - V_34 ;
F_33 ( V_27 , V_115 ) ;
return 0 ;
}
static int
F_40 ( struct V_26 * V_27 ,
const struct V_108 * V_29 )
{
if ( ! F_38 ( V_29 -> V_119 . V_70 ) &&
F_24 ( V_27 , V_69 ,
V_50 , V_29 -> V_119 . V_70 ) )
return - V_34 ;
if ( ! F_38 ( V_29 -> V_119 . V_51 ) &&
F_24 ( V_27 , V_49 ,
V_50 , V_29 -> V_119 . V_51 ) )
return - V_34 ;
if ( V_29 -> V_119 . V_1 &&
F_22 ( V_27 , V_40 ,
V_29 -> V_119 . V_1 ) )
return - V_34 ;
if ( F_25 ( V_27 , V_120 ,
V_29 -> V_119 . V_121 ) )
return - V_34 ;
if ( F_19 ( V_27 , V_112 ,
V_29 -> V_119 . V_62 ) )
return - V_34 ;
return 0 ;
}
static int F_41 ( const struct V_86 * V_86 ,
struct V_26 * V_27 ,
void * V_87 )
{
struct V_108 * V_29 = V_87 ;
struct V_88 * V_89 ;
int V_90 = 0 ;
if ( F_20 ( V_27 , V_91 , V_29 -> V_92 ) )
return - V_34 ;
V_89 = F_31 ( V_27 , V_93 ) ;
if ( ! V_89 )
return - V_34 ;
if ( F_19 ( V_27 , V_61 ,
V_29 -> V_62 ) )
return - V_34 ;
switch ( F_42 ( V_29 -> V_62 ) ) {
case V_122 :
V_90 = F_35 ( V_27 , V_29 ) ;
break;
case V_123 :
V_90 = F_37 ( V_27 , V_29 ) ;
break;
case V_124 :
case V_125 :
V_90 = F_39 ( V_27 , V_29 ) ;
break;
case V_126 :
V_90 = F_40 ( V_27 , V_29 ) ;
break;
default:
V_90 = - V_107 ;
break;
}
if ( V_90 )
return V_90 ;
F_33 ( V_27 , V_89 ) ;
return 0 ;
}
static int F_43 ( const struct V_86 * V_86 ,
struct V_26 * V_27 ,
void * V_87 )
{
const struct V_108 * V_29 = V_87 ;
struct V_88 * V_89 ;
if ( F_20 ( V_27 , V_91 , V_29 -> V_92 ) )
return - V_34 ;
V_89 = F_31 ( V_27 , V_93 ) ;
if ( ! V_89 )
return - V_34 ;
if ( F_19 ( V_27 , V_61 ,
V_29 -> V_62 ) )
return - V_34 ;
F_33 ( V_27 , V_89 ) ;
return 0 ;
}
static struct V_28 *
F_44 ( const struct V_127 * V_127 ,
const struct V_28 * V_128 )
{
struct V_28 * V_129 ;
T_3 V_130 = V_128 -> V_130 ? V_128 -> V_130 : sizeof( V_129 -> V_31 ) ;
F_45 (ofdpa->flow_tbl, found,
entry, match->key_crc32) {
if ( memcmp ( & V_129 -> V_31 , & V_128 -> V_31 , V_130 ) == 0 )
return V_129 ;
}
return NULL ;
}
static int F_46 ( struct V_6 * V_6 ,
struct V_15 * V_16 , int V_13 ,
struct V_28 * V_128 )
{
struct V_127 * V_127 = V_6 -> V_127 ;
struct V_28 * V_129 ;
T_3 V_130 = V_128 -> V_130 ? V_128 -> V_130 : sizeof( V_129 -> V_31 ) ;
unsigned long V_131 ;
V_128 -> V_132 = F_47 ( ~ 0 , & V_128 -> V_31 , V_130 ) ;
F_48 ( & V_127 -> V_133 , V_131 ) ;
V_129 = F_44 ( V_127 , V_128 ) ;
if ( V_129 ) {
V_128 -> V_100 = V_129 -> V_100 ;
if ( ! F_12 ( V_16 ) )
F_49 ( & V_129 -> V_29 ) ;
F_17 ( V_16 , V_129 ) ;
V_129 = V_128 ;
V_129 -> V_92 = V_134 ;
} else {
V_129 = V_128 ;
V_129 -> V_100 = V_127 -> V_135 ++ ;
V_129 -> V_92 = V_136 ;
}
if ( ! F_12 ( V_16 ) )
F_50 ( V_127 -> V_137 , & V_129 -> V_29 , V_129 -> V_132 ) ;
F_51 ( & V_127 -> V_133 , V_131 ) ;
if ( ! F_12 ( V_16 ) )
return F_52 ( V_6 -> V_86 ,
F_9 ( V_13 ) ,
F_30 ,
V_129 , NULL , NULL ) ;
return 0 ;
}
static int F_53 ( struct V_6 * V_6 ,
struct V_15 * V_16 , int V_13 ,
struct V_28 * V_128 )
{
struct V_127 * V_127 = V_6 -> V_127 ;
struct V_28 * V_129 ;
T_3 V_130 = V_128 -> V_130 ? V_128 -> V_130 : sizeof( V_129 -> V_31 ) ;
unsigned long V_131 ;
int V_90 = 0 ;
V_128 -> V_132 = F_47 ( ~ 0 , & V_128 -> V_31 , V_130 ) ;
F_48 ( & V_127 -> V_133 , V_131 ) ;
V_129 = F_44 ( V_127 , V_128 ) ;
if ( V_129 ) {
if ( ! F_12 ( V_16 ) )
F_49 ( & V_129 -> V_29 ) ;
V_129 -> V_92 = V_138 ;
}
F_51 ( & V_127 -> V_133 , V_131 ) ;
F_17 ( V_16 , V_128 ) ;
if ( V_129 ) {
if ( ! F_12 ( V_16 ) )
V_90 = F_52 ( V_6 -> V_86 ,
F_9 ( V_13 ) ,
F_34 ,
V_129 , NULL , NULL ) ;
F_17 ( V_16 , V_129 ) ;
}
return V_90 ;
}
static int F_54 ( struct V_6 * V_6 ,
struct V_15 * V_16 , int V_13 ,
struct V_28 * V_29 )
{
if ( V_13 & V_139 )
return F_53 ( V_6 , V_16 , V_13 , V_29 ) ;
else
return F_46 ( V_6 , V_16 , V_13 , V_29 ) ;
}
static int F_55 ( struct V_6 * V_6 ,
struct V_15 * V_16 , int V_13 ,
T_5 V_33 , T_5 V_36 ,
enum V_140 V_38 )
{
struct V_28 * V_29 ;
V_29 = F_15 ( V_16 , V_13 , sizeof( * V_29 ) ) ;
if ( ! V_29 )
return - V_141 ;
V_29 -> V_31 . V_97 = V_142 ;
V_29 -> V_31 . V_95 = V_101 ;
V_29 -> V_31 . V_32 . V_33 = V_33 ;
V_29 -> V_31 . V_32 . V_36 = V_36 ;
V_29 -> V_31 . V_32 . V_38 = V_38 ;
return F_54 ( V_6 , V_16 , V_13 , V_29 ) ;
}
static int F_56 ( struct V_6 * V_6 ,
struct V_15 * V_16 , int V_13 ,
T_5 V_33 , T_1 V_1 ,
T_1 V_42 ,
enum V_140 V_38 ,
bool V_43 , T_1 V_45 )
{
struct V_28 * V_29 ;
V_29 = F_15 ( V_16 , V_13 , sizeof( * V_29 ) ) ;
if ( ! V_29 )
return - V_141 ;
V_29 -> V_31 . V_97 = V_143 ;
V_29 -> V_31 . V_95 = V_102 ;
V_29 -> V_31 . V_39 . V_33 = V_33 ;
V_29 -> V_31 . V_39 . V_1 = V_1 ;
V_29 -> V_31 . V_39 . V_42 = V_42 ;
V_29 -> V_31 . V_39 . V_38 = V_38 ;
V_29 -> V_31 . V_39 . V_43 = V_43 ;
V_29 -> V_31 . V_39 . V_45 = V_45 ;
return F_54 ( V_6 , V_16 , V_13 , V_29 ) ;
}
static int F_57 ( struct V_6 * V_6 ,
struct V_15 * V_16 ,
T_5 V_33 , T_5 V_36 ,
T_1 V_48 , const T_6 * V_51 ,
const T_6 * V_53 , T_1 V_1 ,
T_1 V_42 , bool V_54 ,
int V_13 )
{
struct V_28 * V_29 ;
V_29 = F_15 ( V_16 , V_13 , sizeof( * V_29 ) ) ;
if ( ! V_29 )
return - V_141 ;
if ( F_58 ( V_51 ) ) {
V_29 -> V_31 . V_97 = V_144 ;
V_29 -> V_31 . V_46 . V_38 =
V_145 ;
} else {
V_29 -> V_31 . V_97 = V_146 ;
V_29 -> V_31 . V_46 . V_38 =
V_104 ;
}
V_29 -> V_31 . V_95 = V_103 ;
V_29 -> V_31 . V_46 . V_33 = V_33 ;
V_29 -> V_31 . V_46 . V_36 = V_36 ;
V_29 -> V_31 . V_46 . V_48 = V_48 ;
F_59 ( V_29 -> V_31 . V_46 . V_51 , V_51 ) ;
F_59 ( V_29 -> V_31 . V_46 . V_53 , V_53 ) ;
V_29 -> V_31 . V_46 . V_1 = V_1 ;
V_29 -> V_31 . V_46 . V_42 = V_42 ;
V_29 -> V_31 . V_46 . V_54 = V_54 ;
return F_54 ( V_6 , V_16 , V_13 , V_29 ) ;
}
static int F_60 ( struct V_6 * V_6 ,
struct V_15 * V_16 , int V_13 ,
const T_6 * V_51 , const T_6 * V_53 ,
T_1 V_1 , T_5 V_66 ,
enum V_140 V_38 ,
T_5 V_62 , bool V_54 )
{
struct V_28 * V_29 ;
T_5 V_97 ;
bool V_147 = ! ! V_1 ;
bool V_148 = ! V_51 || ( V_51 && V_53 ) ;
bool V_149 = false ;
V_29 = F_15 ( V_16 , V_13 , sizeof( * V_29 ) ) ;
if ( ! V_29 )
return - V_141 ;
V_29 -> V_31 . V_95 = V_105 ;
if ( V_51 ) {
V_29 -> V_31 . V_63 . V_64 = 1 ;
F_59 ( V_29 -> V_31 . V_63 . V_51 , V_51 ) ;
}
if ( V_53 ) {
V_29 -> V_31 . V_63 . V_65 = 1 ;
F_59 ( V_29 -> V_31 . V_63 . V_53 , V_53 ) ;
if ( ! F_61 ( V_53 , V_150 ) )
V_149 = true ;
}
V_97 = V_151 ;
if ( V_147 && V_148 && V_149 )
V_97 = V_152 ;
else if ( V_147 && V_148 && ! V_149 )
V_97 = V_153 ;
else if ( V_147 && ! V_148 )
V_97 = V_154 ;
else if ( ! V_147 && V_148 && V_149 )
V_97 = V_155 ;
else if ( ! V_147 && V_148 && ! V_149 )
V_97 = V_156 ;
else if ( ! V_147 && ! V_148 )
V_97 = V_157 ;
V_29 -> V_31 . V_97 = V_97 ;
V_29 -> V_31 . V_63 . V_1 = V_1 ;
V_29 -> V_31 . V_63 . V_66 = V_66 ;
V_29 -> V_31 . V_63 . V_38 = V_38 ;
V_29 -> V_31 . V_63 . V_62 = V_62 ;
V_29 -> V_31 . V_63 . V_54 = V_54 ;
return F_54 ( V_6 , V_16 , V_13 , V_29 ) ;
}
static int F_62 ( struct V_6 * V_6 ,
struct V_15 * V_16 ,
T_1 V_48 , T_7 V_158 ,
T_7 V_159 , T_5 V_97 ,
enum V_140 V_38 ,
T_5 V_62 , struct V_160 * V_161 ,
int V_13 )
{
struct V_28 * V_29 ;
V_29 = F_15 ( V_16 , V_13 , sizeof( * V_29 ) ) ;
if ( ! V_29 )
return - V_141 ;
V_29 -> V_31 . V_95 = V_104 ;
V_29 -> V_31 . V_97 = V_97 ;
V_29 -> V_31 . V_56 . V_48 = V_48 ;
V_29 -> V_31 . V_56 . V_58 = V_158 ;
V_29 -> V_31 . V_56 . V_60 = V_159 ;
V_29 -> V_31 . V_56 . V_38 = V_38 ;
V_29 -> V_31 . V_56 . V_62 = V_62 ;
V_29 -> V_130 = F_63 ( struct V_162 ,
V_56 . V_62 ) ;
V_29 -> V_161 = V_161 ;
return F_54 ( V_6 , V_16 , V_13 , V_29 ) ;
}
static int F_64 ( struct V_6 * V_6 ,
struct V_15 * V_16 , int V_13 ,
T_5 V_33 , T_5 V_36 ,
const T_6 * V_70 , const T_6 * V_72 ,
const T_6 * V_51 , const T_6 * V_53 ,
T_1 V_48 , T_1 V_1 ,
T_1 V_42 , T_6 V_76 ,
T_6 V_78 , T_6 V_80 , T_6 V_82 ,
T_5 V_62 )
{
T_5 V_97 ;
struct V_28 * V_29 ;
V_29 = F_15 ( V_16 , V_13 , sizeof( * V_29 ) ) ;
if ( ! V_29 )
return - V_141 ;
V_97 = V_163 ;
if ( V_51 && V_53 ) {
if ( F_61 ( V_53 , V_164 ) )
V_97 = V_165 ;
else if ( F_65 ( V_51 ) )
V_97 = V_166 ;
}
V_29 -> V_31 . V_97 = V_97 ;
V_29 -> V_31 . V_95 = V_106 ;
V_29 -> V_31 . V_68 . V_33 = V_33 ;
V_29 -> V_31 . V_68 . V_36 = V_36 ;
if ( V_70 )
F_59 ( V_29 -> V_31 . V_68 . V_70 , V_70 ) ;
if ( V_72 )
F_59 ( V_29 -> V_31 . V_68 . V_72 , V_72 ) ;
if ( V_51 )
F_59 ( V_29 -> V_31 . V_68 . V_51 , V_51 ) ;
if ( V_53 )
F_59 ( V_29 -> V_31 . V_68 . V_53 , V_53 ) ;
V_29 -> V_31 . V_68 . V_48 = V_48 ;
V_29 -> V_31 . V_68 . V_1 = V_1 ;
V_29 -> V_31 . V_68 . V_42 = V_42 ;
V_29 -> V_31 . V_68 . V_76 = V_76 ;
V_29 -> V_31 . V_68 . V_78 = V_78 ;
V_29 -> V_31 . V_68 . V_80 = V_80 ;
V_29 -> V_31 . V_68 . V_82 = V_82 ;
V_29 -> V_31 . V_68 . V_62 = V_62 ;
return F_54 ( V_6 , V_16 , V_13 , V_29 ) ;
}
static struct V_108 *
F_66 ( const struct V_127 * V_127 ,
const struct V_108 * V_128 )
{
struct V_108 * V_129 ;
F_45 (ofdpa->group_tbl, found,
entry, match->group_id) {
if ( V_129 -> V_62 == V_128 -> V_62 )
return V_129 ;
}
return NULL ;
}
static void F_67 ( struct V_15 * V_16 ,
struct V_108 * V_29 )
{
switch ( F_42 ( V_29 -> V_62 ) ) {
case V_124 :
case V_125 :
F_17 ( V_16 , V_29 -> V_115 ) ;
break;
default:
break;
}
F_17 ( V_16 , V_29 ) ;
}
static int F_68 ( struct V_6 * V_6 ,
struct V_15 * V_16 , int V_13 ,
struct V_108 * V_128 )
{
struct V_127 * V_127 = V_6 -> V_127 ;
struct V_108 * V_129 ;
unsigned long V_131 ;
F_48 ( & V_127 -> V_167 , V_131 ) ;
V_129 = F_66 ( V_127 , V_128 ) ;
if ( V_129 ) {
if ( ! F_12 ( V_16 ) )
F_49 ( & V_129 -> V_29 ) ;
F_67 ( V_16 , V_129 ) ;
V_129 = V_128 ;
V_129 -> V_92 = V_168 ;
} else {
V_129 = V_128 ;
V_129 -> V_92 = V_169 ;
}
if ( ! F_12 ( V_16 ) )
F_50 ( V_127 -> V_170 , & V_129 -> V_29 , V_129 -> V_62 ) ;
F_51 ( & V_127 -> V_167 , V_131 ) ;
if ( ! F_12 ( V_16 ) )
return F_52 ( V_6 -> V_86 ,
F_9 ( V_13 ) ,
F_41 ,
V_129 , NULL , NULL ) ;
return 0 ;
}
static int F_69 ( struct V_6 * V_6 ,
struct V_15 * V_16 , int V_13 ,
struct V_108 * V_128 )
{
struct V_127 * V_127 = V_6 -> V_127 ;
struct V_108 * V_129 ;
unsigned long V_131 ;
int V_90 = 0 ;
F_48 ( & V_127 -> V_167 , V_131 ) ;
V_129 = F_66 ( V_127 , V_128 ) ;
if ( V_129 ) {
if ( ! F_12 ( V_16 ) )
F_49 ( & V_129 -> V_29 ) ;
V_129 -> V_92 = V_171 ;
}
F_51 ( & V_127 -> V_167 , V_131 ) ;
F_67 ( V_16 , V_128 ) ;
if ( V_129 ) {
if ( ! F_12 ( V_16 ) )
V_90 = F_52 ( V_6 -> V_86 ,
F_9 ( V_13 ) ,
F_43 ,
V_129 , NULL , NULL ) ;
F_67 ( V_16 , V_129 ) ;
}
return V_90 ;
}
static int F_70 ( struct V_6 * V_6 ,
struct V_15 * V_16 , int V_13 ,
struct V_108 * V_29 )
{
if ( V_13 & V_139 )
return F_69 ( V_6 , V_16 , V_13 , V_29 ) ;
else
return F_68 ( V_6 , V_16 , V_13 , V_29 ) ;
}
static int F_71 ( struct V_6 * V_6 ,
struct V_15 * V_16 , int V_13 ,
T_1 V_1 , T_5 V_172 ,
int V_8 )
{
struct V_108 * V_29 ;
V_29 = F_15 ( V_16 , V_13 , sizeof( * V_29 ) ) ;
if ( ! V_29 )
return - V_141 ;
V_29 -> V_62 = F_72 ( V_1 , V_172 ) ;
V_29 -> V_111 . V_8 = V_8 ;
return F_70 ( V_6 , V_16 , V_13 , V_29 ) ;
}
static int F_73 ( struct V_6 * V_6 ,
struct V_15 * V_16 ,
int V_13 , T_6 V_117 ,
const T_5 * V_115 , T_5 V_62 )
{
struct V_108 * V_29 ;
V_29 = F_15 ( V_16 , V_13 , sizeof( * V_29 ) ) ;
if ( ! V_29 )
return - V_141 ;
V_29 -> V_62 = V_62 ;
V_29 -> V_117 = V_117 ;
V_29 -> V_115 = F_16 ( V_16 , V_13 ,
V_117 , sizeof( T_5 ) ) ;
if ( ! V_29 -> V_115 ) {
F_17 ( V_16 , V_29 ) ;
return - V_141 ;
}
memcpy ( V_29 -> V_115 , V_115 , V_117 * sizeof( T_5 ) ) ;
return F_70 ( V_6 , V_16 , V_13 , V_29 ) ;
}
static int F_74 ( struct V_6 * V_6 ,
struct V_15 * V_16 , int V_13 ,
T_1 V_1 , T_6 V_117 ,
const T_5 * V_115 , T_5 V_62 )
{
return F_73 ( V_6 , V_16 , V_13 ,
V_117 , V_115 ,
V_62 ) ;
}
static int F_75 ( struct V_6 * V_6 ,
struct V_15 * V_16 , int V_13 ,
T_5 V_173 , const T_6 * V_174 , const T_6 * V_175 ,
T_1 V_1 , bool V_121 , T_5 V_176 )
{
struct V_108 * V_29 ;
V_29 = F_15 ( V_16 , V_13 , sizeof( * V_29 ) ) ;
if ( ! V_29 )
return - V_141 ;
V_29 -> V_62 = F_76 ( V_173 ) ;
if ( V_174 )
F_59 ( V_29 -> V_119 . V_70 , V_174 ) ;
if ( V_175 )
F_59 ( V_29 -> V_119 . V_51 , V_175 ) ;
V_29 -> V_119 . V_1 = V_1 ;
V_29 -> V_119 . V_121 = V_121 ;
V_29 -> V_119 . V_62 = F_72 ( V_1 , V_176 ) ;
return F_70 ( V_6 , V_16 , V_13 , V_29 ) ;
}
static struct V_177 *
F_77 ( const struct V_127 * V_127 , T_7 V_178 )
{
struct V_177 * V_129 ;
F_45 (ofdpa->neigh_tbl, found,
entry, be32_to_cpu(ip_addr))
if ( V_129 -> V_178 == V_178 )
return V_129 ;
return NULL ;
}
static void F_78 ( struct V_127 * V_127 ,
struct V_15 * V_16 ,
struct V_177 * V_29 )
{
if ( ! F_79 ( V_16 ) )
V_29 -> V_173 = V_127 -> V_179 ++ ;
if ( F_12 ( V_16 ) )
return;
V_29 -> V_180 ++ ;
F_50 ( V_127 -> V_181 , & V_29 -> V_29 ,
F_80 ( V_29 -> V_178 ) ) ;
}
static void F_81 ( struct V_15 * V_16 ,
struct V_177 * V_29 )
{
if ( F_12 ( V_16 ) )
return;
if ( -- V_29 -> V_180 == 0 ) {
F_49 ( & V_29 -> V_29 ) ;
F_17 ( V_16 , V_29 ) ;
}
}
static void F_82 ( struct V_177 * V_29 ,
struct V_15 * V_16 ,
const T_6 * V_51 , bool V_121 )
{
if ( V_51 ) {
F_59 ( V_29 -> V_51 , V_51 ) ;
V_29 -> V_121 = V_121 ;
} else if ( ! F_12 ( V_16 ) ) {
V_29 -> V_180 ++ ;
}
}
static int F_83 ( struct V_6 * V_6 ,
struct V_15 * V_16 ,
int V_13 , T_7 V_178 , const T_6 * V_51 )
{
struct V_127 * V_127 = V_6 -> V_127 ;
struct V_177 * V_29 ;
struct V_177 * V_129 ;
unsigned long V_131 ;
T_1 V_48 = F_4 ( V_73 ) ;
enum V_140 V_38 =
V_106 ;
T_5 V_62 ;
T_5 V_97 = 0 ;
bool V_182 = ! ( V_13 & V_139 ) ;
bool V_183 ;
bool V_184 ;
int V_90 = 0 ;
V_29 = F_15 ( V_16 , V_13 , sizeof( * V_29 ) ) ;
if ( ! V_29 )
return - V_141 ;
F_48 ( & V_127 -> V_185 , V_131 ) ;
V_129 = F_77 ( V_127 , V_178 ) ;
V_183 = V_129 && V_182 ;
V_184 = V_129 && ! V_182 ;
V_182 = ! V_129 && V_182 ;
if ( V_182 ) {
V_29 -> V_178 = V_178 ;
V_29 -> V_186 = V_6 -> V_186 ;
F_59 ( V_29 -> V_51 , V_51 ) ;
V_29 -> V_121 = true ;
F_78 ( V_127 , V_16 , V_29 ) ;
} else if ( V_184 ) {
memcpy ( V_29 , V_129 , sizeof( * V_29 ) ) ;
F_81 ( V_16 , V_129 ) ;
} else if ( V_183 ) {
F_82 ( V_129 , V_16 , V_51 , true ) ;
memcpy ( V_29 , V_129 , sizeof( * V_29 ) ) ;
} else {
V_90 = - V_187 ;
}
F_51 ( & V_127 -> V_185 , V_131 ) ;
if ( V_90 )
goto V_188;
V_90 = F_75 ( V_6 , V_16 , V_13 ,
V_29 -> V_173 ,
V_6 -> V_186 -> V_189 ,
V_29 -> V_51 ,
V_6 -> V_9 ,
V_29 -> V_121 ,
V_6 -> V_176 ) ;
if ( V_90 ) {
F_84 ( V_6 -> V_186 , L_3 ,
V_90 , V_29 -> V_173 ) ;
goto V_188;
}
if ( V_182 || V_184 ) {
V_62 = F_76 ( V_29 -> V_173 ) ;
V_90 = F_62 ( V_6 , V_16 ,
V_48 , V_178 ,
F_85 ( 32 ) ,
V_97 , V_38 ,
V_62 , NULL , V_13 ) ;
if ( V_90 )
F_84 ( V_6 -> V_186 , L_4 ,
V_90 , & V_29 -> V_178 , V_62 ) ;
}
V_188:
if ( ! V_182 )
F_17 ( V_16 , V_29 ) ;
return V_90 ;
}
static int F_86 ( struct V_6 * V_6 ,
struct V_15 * V_16 ,
T_7 V_178 )
{
struct V_190 * V_186 = V_6 -> V_186 ;
struct V_191 * V_24 = F_87 ( V_186 , ( V_192 T_5 ) V_178 ) ;
int V_90 = 0 ;
if ( ! V_24 ) {
V_24 = F_88 ( & V_193 , & V_178 , V_186 ) ;
if ( F_89 ( V_24 ) )
return F_90 ( V_24 ) ;
}
if ( V_24 -> V_194 & V_195 )
V_90 = F_83 ( V_6 , V_16 , 0 ,
V_178 , V_24 -> V_196 ) ;
else
F_91 ( V_24 , NULL ) ;
F_92 ( V_24 ) ;
return V_90 ;
}
static int F_93 ( struct V_6 * V_6 ,
struct V_15 * V_16 , int V_13 ,
T_7 V_178 , T_5 * V_173 )
{
struct V_127 * V_127 = V_6 -> V_127 ;
struct V_177 * V_29 ;
struct V_177 * V_129 ;
unsigned long V_131 ;
bool V_182 = ! ( V_13 & V_139 ) ;
bool V_183 ;
bool V_184 ;
bool V_197 = true ;
int V_90 = 0 ;
V_29 = F_15 ( V_16 , V_13 , sizeof( * V_29 ) ) ;
if ( ! V_29 )
return - V_141 ;
F_48 ( & V_127 -> V_185 , V_131 ) ;
V_129 = F_77 ( V_127 , V_178 ) ;
V_183 = V_129 && V_182 ;
V_184 = V_129 && ! V_182 ;
V_182 = ! V_129 && V_182 ;
if ( V_182 ) {
V_29 -> V_178 = V_178 ;
V_29 -> V_186 = V_6 -> V_186 ;
F_78 ( V_127 , V_16 , V_29 ) ;
* V_173 = V_29 -> V_173 ;
V_197 = false ;
} else if ( V_184 ) {
F_81 ( V_16 , V_129 ) ;
* V_173 = V_129 -> V_173 ;
} else if ( V_183 ) {
F_82 ( V_129 , V_16 , NULL , false ) ;
V_197 = ! F_38 ( V_129 -> V_51 ) ;
* V_173 = V_129 -> V_173 ;
} else {
V_90 = - V_187 ;
}
F_51 ( & V_127 -> V_185 , V_131 ) ;
if ( ! V_182 )
F_17 ( V_16 , V_29 ) ;
if ( V_90 )
return V_90 ;
if ( ! V_197 )
V_90 = F_86 ( V_6 , V_16 , V_178 ) ;
return V_90 ;
}
static struct V_6 * F_94 ( const struct V_127 * V_127 ,
int V_198 )
{
struct V_86 * V_86 ;
V_86 = V_127 -> V_199 -> V_200 [ V_198 ] ;
return V_86 ? V_86 -> V_201 : NULL ;
}
static int F_95 ( struct V_6 * V_6 ,
struct V_15 * V_16 ,
int V_13 , T_1 V_1 )
{
struct V_6 * V_202 ;
const struct V_127 * V_127 = V_6 -> V_127 ;
unsigned int V_203 = V_127 -> V_199 -> V_203 ;
T_5 V_62 = F_96 ( V_1 , 0 ) ;
T_5 * V_115 ;
T_6 V_117 = 0 ;
int V_90 = 0 ;
int V_114 ;
V_115 = F_16 ( V_16 , V_13 , V_203 , sizeof( T_5 ) ) ;
if ( ! V_115 )
return - V_141 ;
for ( V_114 = 0 ; V_114 < V_203 ; V_114 ++ ) {
V_202 = F_94 ( V_127 , V_114 ) ;
if ( ! V_202 )
continue;
if ( ! F_7 ( V_202 ) )
continue;
if ( F_97 ( F_2 ( V_1 ) , V_202 -> V_204 ) ) {
V_115 [ V_117 ++ ] =
F_72 ( V_1 , V_202 -> V_176 ) ;
}
}
if ( V_117 == 0 )
goto V_205;
V_90 = F_74 ( V_6 , V_16 , V_13 , V_1 ,
V_117 , V_115 , V_62 ) ;
if ( V_90 )
F_84 ( V_6 -> V_186 , L_5 , V_90 ) ;
V_205:
F_17 ( V_16 , V_115 ) ;
return V_90 ;
}
static int F_98 ( struct V_6 * V_6 ,
struct V_15 * V_16 , int V_13 ,
T_1 V_1 , bool V_8 )
{
const struct V_127 * V_127 = V_6 -> V_127 ;
unsigned int V_203 = V_127 -> V_199 -> V_203 ;
struct V_6 * V_202 ;
bool V_182 = ! ( V_13 & V_139 ) ;
T_5 V_172 ;
int V_206 = 0 ;
int V_90 ;
int V_114 ;
if ( V_6 -> V_207 == V_208 ||
V_6 -> V_207 == V_209 ) {
V_172 = V_6 -> V_176 ;
V_90 = F_71 ( V_6 , V_16 , V_13 ,
V_1 , V_172 , V_8 ) ;
if ( V_90 ) {
F_84 ( V_6 -> V_186 , L_6 ,
V_90 , V_172 ) ;
return V_90 ;
}
}
for ( V_114 = 0 ; V_114 < V_203 ; V_114 ++ ) {
V_202 = F_94 ( V_127 , V_114 ) ;
if ( V_202 && F_97 ( F_2 ( V_1 ) , V_202 -> V_204 ) )
V_206 ++ ;
}
if ( ( ! V_182 || V_206 != 1 ) && ( V_182 || V_206 != 0 ) )
return 0 ;
V_172 = 0 ;
V_90 = F_71 ( V_6 , V_16 , V_13 ,
V_1 , V_172 , V_8 ) ;
if ( V_90 ) {
F_84 ( V_6 -> V_186 , L_7 , V_90 ) ;
return V_90 ;
}
return 0 ;
}
static int F_99 ( struct V_6 * V_6 ,
struct V_15 * V_16 , int V_13 ,
const struct V_210 * V_211 , T_1 V_1 )
{
T_5 V_33 = V_6 -> V_176 ;
T_5 V_36 = 0xffffffff ;
T_5 V_172 = 0 ;
const T_6 * V_70 = NULL ;
const T_6 * V_72 = NULL ;
T_1 V_42 = F_4 ( 0xffff ) ;
T_6 V_76 = 0 ;
T_6 V_78 = 0 ;
T_6 V_80 = 0 ;
T_6 V_82 = 0 ;
T_5 V_62 = F_72 ( V_1 , V_172 ) ;
int V_90 ;
V_90 = F_64 ( V_6 , V_16 , V_13 ,
V_33 , V_36 ,
V_70 , V_72 ,
V_211 -> V_51 , V_211 -> V_53 ,
V_211 -> V_48 ,
V_1 , V_42 ,
V_76 , V_78 ,
V_80 , V_82 ,
V_62 ) ;
if ( V_90 )
F_84 ( V_6 -> V_186 , L_8 , V_90 ) ;
return V_90 ;
}
static int F_100 ( struct V_6 * V_6 ,
struct V_15 * V_16 ,
int V_13 ,
const struct V_210 * V_211 ,
T_1 V_1 )
{
enum V_140 V_38 =
V_106 ;
T_5 V_62 = F_96 ( V_1 , 0 ) ;
T_5 V_66 = 0 ;
int V_90 ;
if ( ! F_7 ( V_6 ) )
return 0 ;
V_90 = F_60 ( V_6 , V_16 , V_13 ,
V_211 -> V_51 , V_211 -> V_53 ,
V_1 , V_66 ,
V_38 , V_62 , V_211 -> V_54 ) ;
if ( V_90 )
F_84 ( V_6 -> V_186 , L_9 , V_90 ) ;
return V_90 ;
}
static int F_101 ( struct V_6 * V_6 ,
struct V_15 * V_16 , int V_13 ,
const struct V_210 * V_211 , T_1 V_1 )
{
T_5 V_36 = 0xffffffff ;
T_1 V_42 = F_4 ( 0xffff ) ;
int V_90 ;
if ( F_2 ( V_1 ) == 0 )
V_1 = V_6 -> V_9 ;
V_90 = F_57 ( V_6 , V_16 ,
V_6 -> V_176 , V_36 ,
V_211 -> V_48 , V_211 -> V_51 ,
V_211 -> V_53 , V_1 ,
V_42 , V_211 -> V_54 ,
V_13 ) ;
if ( V_90 )
F_84 ( V_6 -> V_186 , L_10 , V_90 ) ;
return V_90 ;
}
static int F_102 ( struct V_6 * V_6 ,
struct V_15 * V_16 , int V_13 ,
const struct V_210 * V_211 , T_1 V_1 )
{
if ( V_211 -> V_68 )
return F_99 ( V_6 , V_16 , V_13 ,
V_211 , V_1 ) ;
if ( V_211 -> V_63 )
return F_100 ( V_6 , V_16 , V_13 ,
V_211 , V_1 ) ;
if ( V_211 -> V_212 )
return F_101 ( V_6 , V_16 , V_13 ,
V_211 , V_1 ) ;
return - V_213 ;
}
static int F_103 ( struct V_6 * V_6 ,
struct V_15 * V_16 , int V_13 ,
T_1 V_1 )
{
int V_90 = 0 ;
int V_114 ;
for ( V_114 = 0 ; V_114 < V_214 ; V_114 ++ ) {
if ( V_6 -> V_215 [ V_114 ] ) {
V_90 = F_102 ( V_6 , V_16 , V_13 ,
& V_216 [ V_114 ] , V_1 ) ;
if ( V_90 )
return V_90 ;
}
}
return V_90 ;
}
static int F_104 ( struct V_6 * V_6 ,
struct V_15 * V_16 , int V_13 ,
const struct V_210 * V_211 )
{
T_2 V_7 ;
int V_90 = 0 ;
for ( V_7 = 1 ; V_7 < V_217 ; V_7 ++ ) {
if ( ! F_97 ( V_7 , V_6 -> V_204 ) )
continue;
V_90 = F_102 ( V_6 , V_16 , V_13 ,
V_211 , F_4 ( V_7 ) ) ;
if ( V_90 )
break;
}
return V_90 ;
}
static int F_105 ( struct V_6 * V_6 ,
struct V_15 * V_16 , int V_13 , T_2 V_7 )
{
enum V_140 V_38 =
V_103 ;
T_5 V_33 = V_6 -> V_176 ;
T_1 V_1 = F_4 ( V_7 ) ;
T_1 V_42 = F_4 ( 0xffff ) ;
T_1 V_9 ;
bool V_43 ;
bool V_182 = ! ( V_13 & V_139 ) ;
int V_90 ;
V_9 = F_3 ( V_6 , V_7 , & V_43 ) ;
if ( V_182 &&
F_97 ( F_2 ( V_9 ) , V_6 -> V_204 ) )
return 0 ;
else if ( ! V_182 &&
! F_97 ( F_2 ( V_9 ) , V_6 -> V_204 ) )
return 0 ;
F_106 ( F_2 ( V_9 ) , V_6 -> V_204 ) ;
if ( V_182 ) {
V_90 = F_103 ( V_6 , V_16 , V_13 ,
V_9 ) ;
if ( V_90 ) {
F_84 ( V_6 -> V_186 , L_11 , V_90 ) ;
goto V_188;
}
}
V_90 = F_98 ( V_6 , V_16 , V_13 ,
V_9 , V_43 ) ;
if ( V_90 ) {
F_84 ( V_6 -> V_186 , L_12 , V_90 ) ;
goto V_188;
}
V_90 = F_95 ( V_6 , V_16 , V_13 ,
V_9 ) ;
if ( V_90 ) {
F_84 ( V_6 -> V_186 , L_5 , V_90 ) ;
goto V_188;
}
V_90 = F_56 ( V_6 , V_16 , V_13 ,
V_33 , V_1 , V_42 ,
V_38 , V_43 , V_9 ) ;
if ( V_90 )
F_84 ( V_6 -> V_186 , L_13 , V_90 ) ;
V_188:
if ( F_12 ( V_16 ) )
F_106 ( F_2 ( V_9 ) , V_6 -> V_204 ) ;
return V_90 ;
}
static int F_107 ( struct V_6 * V_6 ,
struct V_15 * V_16 , int V_13 )
{
enum V_140 V_38 ;
T_5 V_33 ;
T_5 V_36 ;
int V_90 ;
V_33 = 0 ;
V_36 = 0xffff0000 ;
V_38 = V_102 ;
V_90 = F_55 ( V_6 , V_16 , V_13 ,
V_33 , V_36 ,
V_38 ) ;
if ( V_90 )
F_84 ( V_6 -> V_186 , L_14 , V_90 ) ;
return V_90 ;
}
static void F_108 ( struct V_218 * V_219 )
{
const struct V_220 * V_221 =
F_109 ( V_219 , struct V_220 , V_219 ) ;
bool V_184 = ( V_221 -> V_13 & V_139 ) ;
bool V_222 = ( V_221 -> V_13 & V_223 ) ;
struct V_224 V_225 ;
V_225 . V_226 = V_221 -> V_226 ;
V_225 . V_7 = V_221 -> V_7 ;
F_110 () ;
if ( V_222 && V_184 )
F_111 ( V_227 ,
V_221 -> V_6 -> V_186 , & V_225 . V_225 ) ;
else if ( V_222 && ! V_184 )
F_111 ( V_228 ,
V_221 -> V_6 -> V_186 , & V_225 . V_225 ) ;
F_112 () ;
F_17 ( V_221 -> V_16 , V_219 ) ;
}
static int F_113 ( struct V_6 * V_6 ,
struct V_15 * V_16 , int V_13 ,
const T_6 * V_226 , T_1 V_1 )
{
struct V_220 * V_221 ;
enum V_140 V_38 =
V_106 ;
T_5 V_172 = V_6 -> V_176 ;
T_5 V_66 = 0 ;
T_5 V_62 = V_85 ;
bool V_229 = ! ! ( V_6 -> V_230 & V_231 ) ;
bool V_54 = false ;
int V_90 ;
if ( F_7 ( V_6 ) )
V_62 = F_72 ( V_1 , V_172 ) ;
if ( ! ( V_13 & V_232 ) ) {
V_90 = F_60 ( V_6 , V_16 , V_13 , V_226 ,
NULL , V_1 , V_66 , V_38 ,
V_62 , V_54 ) ;
if ( V_90 )
return V_90 ;
}
if ( ! V_229 )
return 0 ;
if ( ! F_7 ( V_6 ) )
return 0 ;
V_221 = F_15 ( V_16 , V_13 , sizeof( * V_221 ) ) ;
if ( ! V_221 )
return - V_141 ;
F_114 ( & V_221 -> V_219 , F_108 ) ;
V_221 -> V_6 = V_6 ;
V_221 -> V_16 = V_16 ;
V_221 -> V_13 = V_13 ;
F_59 ( V_221 -> V_226 , V_226 ) ;
V_221 -> V_7 = F_5 ( V_6 , V_1 ) ;
if ( F_12 ( V_16 ) )
F_17 ( V_16 , V_221 ) ;
else
F_115 ( & V_221 -> V_219 ) ;
return 0 ;
}
static struct V_233 *
F_116 ( const struct V_127 * V_127 ,
const struct V_233 * V_128 )
{
struct V_233 * V_129 ;
F_45 (ofdpa->fdb_tbl, found, entry, match->key_crc32)
if ( memcmp ( & V_129 -> V_31 , & V_128 -> V_31 , sizeof( V_129 -> V_31 ) ) == 0 )
return V_129 ;
return NULL ;
}
static int F_117 ( struct V_6 * V_6 ,
struct V_15 * V_16 ,
const unsigned char * V_226 ,
T_1 V_1 , int V_13 )
{
struct V_127 * V_127 = V_6 -> V_127 ;
struct V_233 * V_234 ;
struct V_233 * V_129 ;
bool V_184 = ( V_13 & V_139 ) ;
unsigned long V_131 ;
V_234 = F_15 ( V_16 , V_13 , sizeof( * V_234 ) ) ;
if ( ! V_234 )
return - V_141 ;
V_234 -> V_222 = ( V_13 & V_223 ) ;
V_234 -> V_235 = V_236 ;
V_234 -> V_31 . V_6 = V_6 ;
F_59 ( V_234 -> V_31 . V_226 , V_226 ) ;
V_234 -> V_31 . V_1 = V_1 ;
V_234 -> V_132 = F_47 ( ~ 0 , & V_234 -> V_31 , sizeof( V_234 -> V_31 ) ) ;
F_48 ( & V_127 -> V_237 , V_131 ) ;
V_129 = F_116 ( V_127 , V_234 ) ;
if ( V_129 ) {
V_129 -> V_235 = V_236 ;
if ( V_184 ) {
F_17 ( V_16 , V_234 ) ;
if ( ! F_12 ( V_16 ) )
F_49 ( & V_129 -> V_29 ) ;
}
} else if ( ! V_184 ) {
if ( ! F_12 ( V_16 ) )
F_50 ( V_127 -> V_238 , & V_234 -> V_29 ,
V_234 -> V_132 ) ;
}
F_51 ( & V_127 -> V_237 , V_131 ) ;
if ( ! V_129 != ! V_184 ) {
F_17 ( V_16 , V_234 ) ;
if ( ! V_129 && V_184 )
return 0 ;
V_13 |= V_232 ;
}
return F_113 ( V_6 , V_16 , V_13 , V_226 , V_1 ) ;
}
static int F_118 ( struct V_6 * V_6 ,
struct V_15 * V_16 , int V_13 )
{
struct V_127 * V_127 = V_6 -> V_127 ;
struct V_233 * V_129 ;
unsigned long V_131 ;
struct V_239 * V_240 ;
int V_241 ;
int V_90 = 0 ;
if ( V_6 -> V_207 == V_208 ||
V_6 -> V_207 == V_209 )
return 0 ;
V_13 |= V_14 | V_139 ;
F_48 ( & V_127 -> V_237 , V_131 ) ;
F_119 (ofdpa->fdb_tbl, bkt, tmp, found, entry) {
if ( V_129 -> V_31 . V_6 != V_6 )
continue;
if ( ! V_129 -> V_222 )
continue;
V_90 = F_113 ( V_6 , V_16 , V_13 ,
V_129 -> V_31 . V_226 ,
V_129 -> V_31 . V_1 ) ;
if ( V_90 )
goto V_188;
if ( ! F_12 ( V_16 ) )
F_49 ( & V_129 -> V_29 ) ;
}
V_188:
F_51 ( & V_127 -> V_237 , V_131 ) ;
return V_90 ;
}
static void F_120 ( unsigned long V_242 )
{
struct V_127 * V_127 = (struct V_127 * ) V_242 ;
struct V_6 * V_6 ;
struct V_233 * V_29 ;
struct V_239 * V_240 ;
unsigned long V_243 = V_236 + V_127 -> V_244 ;
unsigned long V_245 ;
unsigned long V_131 ;
int V_13 = V_14 | V_139 |
V_223 ;
int V_241 ;
F_48 ( & V_127 -> V_237 , V_131 ) ;
F_119 (ofdpa->fdb_tbl, bkt, tmp, entry, entry) {
if ( ! V_29 -> V_222 )
continue;
V_6 = V_29 -> V_31 . V_6 ;
V_245 = V_29 -> V_235 + V_6 -> V_244 ;
if ( F_121 ( V_245 , V_236 ) ) {
F_113 ( V_6 , NULL ,
V_13 , V_29 -> V_31 . V_226 ,
V_29 -> V_31 . V_1 ) ;
F_49 ( & V_29 -> V_29 ) ;
} else if ( F_122 ( V_245 , V_243 ) ) {
V_243 = V_245 ;
}
}
F_51 ( & V_127 -> V_237 , V_131 ) ;
F_123 ( & V_127 -> V_246 , F_124 ( V_243 ) ) ;
}
static int F_125 ( struct V_6 * V_6 ,
struct V_15 * V_16 , int V_13 ,
T_1 V_1 )
{
T_5 V_36 = 0xffffffff ;
T_1 V_48 ;
const T_6 * V_247 = V_150 ;
T_1 V_42 = F_4 ( 0xffff ) ;
bool V_54 = false ;
int V_90 ;
if ( F_2 ( V_1 ) == 0 )
V_1 = V_6 -> V_9 ;
V_48 = F_4 ( V_73 ) ;
V_90 = F_57 ( V_6 , V_16 ,
V_6 -> V_176 , V_36 ,
V_48 , V_6 -> V_186 -> V_189 ,
V_247 , V_1 , V_42 ,
V_54 , V_13 ) ;
if ( V_90 )
return V_90 ;
V_48 = F_4 ( V_74 ) ;
V_90 = F_57 ( V_6 , V_16 ,
V_6 -> V_176 , V_36 ,
V_48 , V_6 -> V_186 -> V_189 ,
V_247 , V_1 , V_42 ,
V_54 , V_13 ) ;
return V_90 ;
}
static int F_126 ( struct V_6 * V_6 ,
struct V_15 * V_16 , int V_13 )
{
bool V_8 ;
T_5 V_172 ;
T_1 V_1 ;
T_2 V_7 ;
int V_90 ;
if ( V_6 -> V_207 != V_208 &&
V_6 -> V_207 != V_209 )
V_13 |= V_139 ;
V_172 = V_6 -> V_176 ;
for ( V_7 = 1 ; V_7 < V_217 ; V_7 ++ ) {
if ( ! F_97 ( V_7 , V_6 -> V_204 ) )
continue;
V_1 = F_4 ( V_7 ) ;
V_8 = F_1 ( V_1 ) ;
V_90 = F_71 ( V_6 , V_16 , V_13 ,
V_1 , V_172 , V_8 ) ;
if ( V_90 ) {
F_84 ( V_6 -> V_186 , L_6 ,
V_90 , V_172 ) ;
return V_90 ;
}
}
return 0 ;
}
static int F_127 ( struct V_6 * V_6 ,
struct V_15 * V_16 ,
int V_13 , T_6 V_248 )
{
bool V_249 [ V_214 ] = { 0 , } ;
bool V_250 [ V_214 ] ;
T_6 V_251 ( V_252 ) ;
int V_90 ;
int V_114 ;
if ( F_12 ( V_16 ) ) {
memcpy ( V_250 , V_6 -> V_215 , sizeof( V_250 ) ) ;
V_252 = V_6 -> V_207 ;
}
if ( V_6 -> V_207 == V_248 )
return 0 ;
V_6 -> V_207 = V_248 ;
switch ( V_248 ) {
case V_253 :
break;
case V_254 :
case V_255 :
V_249 [ V_256 ] = true ;
break;
case V_208 :
case V_209 :
if ( ! F_8 ( V_6 ) )
V_249 [ V_256 ] = true ;
V_249 [ V_257 ] = true ;
V_249 [ V_258 ] = true ;
if ( F_7 ( V_6 ) )
V_249 [ V_259 ] = true ;
else if ( F_8 ( V_6 ) )
V_249 [ V_260 ] = true ;
else
V_249 [ V_261 ] = true ;
break;
}
for ( V_114 = 0 ; V_114 < V_214 ; V_114 ++ ) {
if ( V_249 [ V_114 ] != V_6 -> V_215 [ V_114 ] ) {
int V_262 = V_13 |
( V_249 [ V_114 ] ? 0 : V_139 ) ;
V_90 = F_104 ( V_6 , V_16 , V_262 ,
& V_216 [ V_114 ] ) ;
if ( V_90 )
goto V_188;
V_6 -> V_215 [ V_114 ] = V_249 [ V_114 ] ;
}
}
V_90 = F_118 ( V_6 , V_16 , V_13 ) ;
if ( V_90 )
goto V_188;
V_90 = F_126 ( V_6 , V_16 , V_13 ) ;
V_188:
if ( F_12 ( V_16 ) ) {
memcpy ( V_6 -> V_215 , V_250 , sizeof( V_250 ) ) ;
V_6 -> V_207 = V_252 ;
}
return V_90 ;
}
static int F_128 ( struct V_6 * V_6 , int V_13 )
{
if ( F_7 ( V_6 ) )
return 0 ;
return F_127 ( V_6 , NULL , V_13 ,
V_209 ) ;
}
static int F_129 ( struct V_6 * V_6 , int V_13 )
{
if ( F_7 ( V_6 ) )
return 0 ;
return F_127 ( V_6 , NULL , V_13 ,
V_253 ) ;
}
static int F_130 ( struct V_6 * V_6 ,
struct V_15 * V_16 ,
T_2 V_7 , T_2 V_13 )
{
int V_90 ;
V_90 = F_105 ( V_6 , V_16 , 0 , V_7 ) ;
if ( V_90 )
return V_90 ;
V_90 = F_125 ( V_6 , V_16 , 0 , F_4 ( V_7 ) ) ;
if ( V_90 )
F_105 ( V_6 , V_16 ,
V_139 , V_7 ) ;
return V_90 ;
}
static int F_131 ( struct V_6 * V_6 ,
T_2 V_7 , T_2 V_13 )
{
int V_90 ;
V_90 = F_125 ( V_6 , NULL ,
V_139 , F_4 ( V_7 ) ) ;
if ( V_90 )
return V_90 ;
return F_105 ( V_6 , NULL ,
V_139 , V_7 ) ;
}
static struct V_263 *
F_132 ( const struct V_127 * V_127 , int V_264 )
{
struct V_263 * V_129 ;
F_45 (ofdpa->internal_vlan_tbl, found,
entry, ifindex) {
if ( V_129 -> V_264 == V_264 )
return V_129 ;
}
return NULL ;
}
static T_1 F_133 ( struct V_6 * V_6 ,
int V_264 )
{
struct V_127 * V_127 = V_6 -> V_127 ;
struct V_263 * V_29 ;
struct V_263 * V_129 ;
unsigned long V_131 ;
int V_114 ;
V_29 = F_11 ( sizeof( * V_29 ) , V_22 ) ;
if ( ! V_29 )
return 0 ;
V_29 -> V_264 = V_264 ;
F_48 ( & V_127 -> V_265 , V_131 ) ;
V_129 = F_132 ( V_127 , V_264 ) ;
if ( V_129 ) {
V_23 ( V_29 ) ;
goto V_129;
}
V_129 = V_29 ;
F_50 ( V_127 -> V_266 , & V_129 -> V_29 , V_129 -> V_264 ) ;
for ( V_114 = 0 ; V_114 < V_267 ; V_114 ++ ) {
if ( F_134 ( V_114 , V_127 -> V_268 ) )
continue;
V_129 -> V_1 = F_4 ( V_3 + V_114 ) ;
goto V_129;
}
F_84 ( V_6 -> V_186 , L_15 ) ;
V_129:
V_129 -> V_180 ++ ;
F_51 ( & V_127 -> V_265 , V_131 ) ;
return V_129 -> V_1 ;
}
static int F_135 ( struct V_6 * V_6 ,
struct V_15 * V_16 , T_7 V_158 ,
int V_269 , struct V_160 * V_161 ,
T_5 V_270 , int V_13 )
{
const struct V_271 * V_272 ;
T_1 V_48 = F_4 ( V_73 ) ;
T_7 V_159 = F_85 ( V_269 ) ;
T_1 V_9 = V_6 -> V_9 ;
T_5 V_97 = V_161 -> V_273 ;
enum V_140 V_38 =
V_106 ;
T_5 V_62 ;
bool V_274 ;
bool V_275 ;
T_5 V_173 ;
int V_90 ;
V_272 = V_161 -> V_271 ;
V_274 = ( V_161 -> V_276 == V_6 -> V_186 ) ;
V_275 = ! ! V_272 -> V_277 ;
if ( V_275 && V_274 ) {
V_90 = F_93 ( V_6 , V_16 , V_13 ,
V_272 -> V_277 , & V_173 ) ;
if ( V_90 )
return V_90 ;
V_62 = F_76 ( V_173 ) ;
} else {
V_62 = F_72 ( V_9 , 0 ) ;
}
V_90 = F_62 ( V_6 , V_16 , V_48 , V_158 ,
V_159 , V_97 , V_38 ,
V_62 , V_161 , V_13 ) ;
if ( V_90 )
F_84 ( V_6 -> V_186 , L_16 ,
V_90 , & V_158 ) ;
return V_90 ;
}
static void
F_136 ( const struct V_6 * V_6 ,
int V_264 )
{
struct V_127 * V_127 = V_6 -> V_127 ;
struct V_263 * V_129 ;
unsigned long V_131 ;
unsigned long V_278 ;
F_48 ( & V_127 -> V_265 , V_131 ) ;
V_129 = F_132 ( V_127 , V_264 ) ;
if ( ! V_129 ) {
F_84 ( V_6 -> V_186 ,
L_17 ,
V_264 ) ;
goto V_279;
}
if ( -- V_129 -> V_180 <= 0 ) {
V_278 = F_2 ( V_129 -> V_1 ) - V_3 ;
F_137 ( V_278 , V_127 -> V_268 ) ;
F_49 ( & V_129 -> V_29 ) ;
V_23 ( V_129 ) ;
}
V_279:
F_51 ( & V_127 -> V_265 , V_131 ) ;
}
static int F_138 ( struct V_199 * V_199 )
{
struct V_127 * V_127 = V_199 -> V_201 ;
V_127 -> V_199 = V_199 ;
F_139 ( V_127 -> V_137 ) ;
F_140 ( & V_127 -> V_133 ) ;
F_139 ( V_127 -> V_170 ) ;
F_140 ( & V_127 -> V_167 ) ;
F_139 ( V_127 -> V_238 ) ;
F_140 ( & V_127 -> V_237 ) ;
F_139 ( V_127 -> V_266 ) ;
F_140 ( & V_127 -> V_265 ) ;
F_139 ( V_127 -> V_181 ) ;
F_140 ( & V_127 -> V_185 ) ;
F_141 ( & V_127 -> V_246 , F_120 ,
( unsigned long ) V_127 ) ;
F_123 ( & V_127 -> V_246 , V_236 ) ;
V_127 -> V_244 = V_280 ;
return 0 ;
}
static void F_142 ( struct V_199 * V_199 )
{
struct V_127 * V_127 = V_199 -> V_201 ;
unsigned long V_13 ;
struct V_28 * V_281 ;
struct V_108 * V_282 ;
struct V_233 * V_283 ;
struct V_263 * V_284 ;
struct V_177 * V_285 ;
struct V_239 * V_240 ;
int V_241 ;
F_143 ( & V_127 -> V_246 ) ;
F_144 ( V_199 -> V_286 ) ;
F_48 ( & V_127 -> V_133 , V_13 ) ;
F_119 (ofdpa->flow_tbl, bkt, tmp, flow_entry, entry)
F_49 ( & V_281 -> V_29 ) ;
F_51 ( & V_127 -> V_133 , V_13 ) ;
F_48 ( & V_127 -> V_167 , V_13 ) ;
F_119 (ofdpa->group_tbl, bkt, tmp, group_entry, entry)
F_49 ( & V_282 -> V_29 ) ;
F_51 ( & V_127 -> V_167 , V_13 ) ;
F_48 ( & V_127 -> V_237 , V_13 ) ;
F_119 (ofdpa->fdb_tbl, bkt, tmp, fdb_entry, entry)
F_49 ( & V_283 -> V_29 ) ;
F_51 ( & V_127 -> V_237 , V_13 ) ;
F_48 ( & V_127 -> V_265 , V_13 ) ;
F_119 (ofdpa->internal_vlan_tbl, bkt,
tmp, internal_vlan_entry, entry)
F_49 ( & V_284 -> V_29 ) ;
F_51 ( & V_127 -> V_265 , V_13 ) ;
F_48 ( & V_127 -> V_185 , V_13 ) ;
F_119 (ofdpa->neigh_tbl, bkt, tmp, neigh_entry, entry)
F_49 ( & V_285 -> V_29 ) ;
F_51 ( & V_127 -> V_185 , V_13 ) ;
}
static int F_145 ( struct V_86 * V_86 )
{
struct V_6 * V_6 = V_86 -> V_201 ;
V_6 -> V_127 = V_86 -> V_199 -> V_201 ;
V_6 -> V_86 = V_86 ;
V_6 -> V_186 = V_86 -> V_186 ;
V_6 -> V_176 = V_86 -> V_176 ;
V_6 -> V_230 = V_287 | V_231 ;
V_6 -> V_244 = V_280 ;
return 0 ;
}
static int F_146 ( struct V_86 * V_86 )
{
struct V_6 * V_6 = V_86 -> V_201 ;
int V_90 ;
F_147 ( V_86 ,
! ! ( V_6 -> V_230 & V_287 ) ) ;
V_90 = F_107 ( V_6 , NULL , 0 ) ;
if ( V_90 ) {
F_84 ( V_6 -> V_186 , L_18 ) ;
return V_90 ;
}
V_6 -> V_9 =
F_133 ( V_6 ,
V_6 -> V_186 -> V_264 ) ;
V_90 = F_130 ( V_6 , NULL , V_288 , 0 ) ;
if ( V_90 ) {
F_84 ( V_6 -> V_186 , L_19 ) ;
goto V_289;
}
return 0 ;
V_289:
F_107 ( V_6 , NULL , V_139 ) ;
return V_90 ;
}
static void F_148 ( struct V_86 * V_86 )
{
struct V_6 * V_6 = V_86 -> V_201 ;
F_107 ( V_6 , NULL , V_139 ) ;
}
static int F_149 ( struct V_86 * V_86 )
{
struct V_6 * V_6 = V_86 -> V_201 ;
return F_128 ( V_6 , 0 ) ;
}
static void F_150 ( struct V_86 * V_86 )
{
struct V_6 * V_6 = V_86 -> V_201 ;
F_129 ( V_6 , V_14 ) ;
}
static int F_151 ( struct V_86 * V_86 ,
T_6 V_248 ,
struct V_15 * V_16 )
{
struct V_6 * V_6 = V_86 -> V_201 ;
return F_127 ( V_6 , V_16 , 0 , V_248 ) ;
}
static int F_152 ( struct V_86 * V_86 ,
unsigned long V_230 ,
struct V_15 * V_16 )
{
struct V_6 * V_6 = V_86 -> V_201 ;
unsigned long V_290 ;
int V_90 = 0 ;
V_290 = V_6 -> V_230 ;
V_6 -> V_230 = V_230 ;
if ( ( V_290 ^ V_6 -> V_230 ) & V_287 &&
! F_12 ( V_16 ) )
V_90 = F_147 ( V_6 -> V_86 ,
! ! ( V_6 -> V_230 & V_287 ) ) ;
if ( F_12 ( V_16 ) )
V_6 -> V_230 = V_290 ;
return V_90 ;
}
static int
F_153 ( const struct V_86 * V_86 ,
unsigned long * V_291 )
{
const struct V_6 * V_6 = V_86 -> V_201 ;
* V_291 = V_6 -> V_230 ;
return 0 ;
}
static int
F_154 ( struct V_86 * V_86 ,
T_5 V_244 ,
struct V_15 * V_16 )
{
struct V_6 * V_6 = V_86 -> V_201 ;
struct V_127 * V_127 = V_6 -> V_127 ;
if ( ! F_12 ( V_16 ) ) {
V_6 -> V_244 = F_155 ( V_244 ) ;
if ( V_6 -> V_244 < V_127 -> V_244 )
V_127 -> V_244 = V_6 -> V_244 ;
F_123 ( & V_6 -> V_127 -> V_246 , V_236 ) ;
}
return 0 ;
}
static int F_156 ( struct V_86 * V_86 ,
const struct V_292 * V_39 ,
struct V_15 * V_16 )
{
struct V_6 * V_6 = V_86 -> V_201 ;
T_2 V_7 ;
int V_90 ;
for ( V_7 = V_39 -> V_293 ; V_7 <= V_39 -> V_294 ; V_7 ++ ) {
V_90 = F_130 ( V_6 , V_16 , V_7 , V_39 -> V_13 ) ;
if ( V_90 )
return V_90 ;
}
return 0 ;
}
static int F_157 ( struct V_86 * V_86 ,
const struct V_292 * V_39 )
{
struct V_6 * V_6 = V_86 -> V_201 ;
T_2 V_7 ;
int V_90 ;
for ( V_7 = V_39 -> V_293 ; V_7 <= V_39 -> V_294 ; V_7 ++ ) {
V_90 = F_131 ( V_6 , V_7 , V_39 -> V_13 ) ;
if ( V_90 )
return V_90 ;
}
return 0 ;
}
static int F_158 ( const struct V_86 * V_86 ,
struct V_292 * V_39 ,
T_8 * V_295 )
{
const struct V_6 * V_6 = V_86 -> V_201 ;
T_2 V_7 ;
int V_90 = 0 ;
for ( V_7 = 1 ; V_7 < V_217 ; V_7 ++ ) {
if ( ! F_97 ( V_7 , V_6 -> V_204 ) )
continue;
V_39 -> V_13 = 0 ;
if ( F_1 ( F_4 ( V_7 ) ) )
V_39 -> V_13 |= V_296 ;
V_39 -> V_293 = V_39 -> V_294 = V_7 ;
V_90 = V_295 ( & V_39 -> V_297 ) ;
if ( V_90 )
break;
}
return V_90 ;
}
static int F_159 ( struct V_86 * V_86 ,
const struct V_298 * V_234 ,
struct V_15 * V_16 )
{
struct V_6 * V_6 = V_86 -> V_201 ;
T_1 V_1 = F_3 ( V_6 , V_234 -> V_7 , NULL ) ;
if ( ! F_7 ( V_6 ) )
return - V_299 ;
return F_117 ( V_6 , V_16 , V_234 -> V_226 , V_1 , 0 ) ;
}
static int F_160 ( struct V_86 * V_86 ,
const struct V_298 * V_234 )
{
struct V_6 * V_6 = V_86 -> V_201 ;
T_1 V_1 = F_3 ( V_6 , V_234 -> V_7 , NULL ) ;
int V_13 = V_139 ;
if ( ! F_7 ( V_6 ) )
return - V_299 ;
return F_117 ( V_6 , NULL , V_234 -> V_226 , V_1 , V_13 ) ;
}
static int F_161 ( const struct V_86 * V_86 ,
struct V_298 * V_234 ,
T_8 * V_295 )
{
const struct V_6 * V_6 = V_86 -> V_201 ;
struct V_127 * V_127 = V_6 -> V_127 ;
struct V_233 * V_129 ;
struct V_239 * V_240 ;
unsigned long V_131 ;
int V_241 ;
int V_90 = 0 ;
F_48 ( & V_127 -> V_237 , V_131 ) ;
F_119 (ofdpa->fdb_tbl, bkt, tmp, found, entry) {
if ( V_129 -> V_31 . V_6 != V_6 )
continue;
F_59 ( V_234 -> V_226 , V_129 -> V_31 . V_226 ) ;
V_234 -> V_300 = V_301 ;
V_234 -> V_7 = F_5 ( V_6 ,
V_129 -> V_31 . V_1 ) ;
V_90 = V_295 ( & V_234 -> V_297 ) ;
if ( V_90 )
break;
}
F_51 ( & V_127 -> V_237 , V_131 ) ;
return V_90 ;
}
static int F_162 ( struct V_6 * V_6 ,
struct V_190 * V_63 )
{
int V_90 ;
V_90 = F_131 ( V_6 , V_288 , 0 ) ;
if ( V_90 )
return V_90 ;
F_136 ( V_6 ,
V_6 -> V_186 -> V_264 ) ;
V_6 -> V_9 =
F_133 ( V_6 , V_63 -> V_264 ) ;
V_6 -> V_11 = V_63 ;
return F_130 ( V_6 , NULL , V_288 , 0 ) ;
}
static int F_163 ( struct V_6 * V_6 )
{
int V_90 ;
V_90 = F_131 ( V_6 , V_288 , 0 ) ;
if ( V_90 )
return V_90 ;
F_136 ( V_6 ,
V_6 -> V_11 -> V_264 ) ;
V_6 -> V_9 =
F_133 ( V_6 ,
V_6 -> V_186 -> V_264 ) ;
V_6 -> V_11 = NULL ;
V_90 = F_130 ( V_6 , NULL , V_288 , 0 ) ;
if ( V_90 )
return V_90 ;
if ( V_6 -> V_186 -> V_13 & V_302 )
V_90 = F_128 ( V_6 , 0 ) ;
return V_90 ;
}
static int F_164 ( struct V_6 * V_6 ,
struct V_190 * V_303 )
{
int V_90 ;
V_6 -> V_11 = V_303 ;
V_90 = F_129 ( V_6 , 0 ) ;
if ( V_90 )
return V_90 ;
V_90 = F_128 ( V_6 , 0 ) ;
return V_90 ;
}
static int F_165 ( struct V_86 * V_86 ,
struct V_190 * V_303 )
{
struct V_6 * V_6 = V_86 -> V_201 ;
int V_90 = 0 ;
if ( F_166 ( V_303 ) )
V_90 = F_162 ( V_6 , V_303 ) ;
else if ( F_167 ( V_303 ) )
V_90 = F_164 ( V_6 , V_303 ) ;
return V_90 ;
}
static int F_168 ( struct V_86 * V_86 ,
struct V_190 * V_303 )
{
struct V_6 * V_6 = V_86 -> V_201 ;
int V_90 = 0 ;
if ( F_7 ( V_6 ) )
V_90 = F_163 ( V_6 ) ;
else if ( F_8 ( V_6 ) )
V_90 = F_164 ( V_6 , NULL ) ;
return V_90 ;
}
static int F_169 ( struct V_86 * V_86 ,
struct V_191 * V_24 )
{
struct V_6 * V_6 = V_86 -> V_201 ;
int V_13 = ( V_24 -> V_194 & V_195 ? 0 : V_139 ) |
V_14 ;
T_7 V_178 = * ( T_7 * ) V_24 -> V_304 ;
return F_83 ( V_6 , NULL , V_13 , V_178 , V_24 -> V_196 ) ;
}
static int F_170 ( struct V_86 * V_86 ,
struct V_191 * V_24 )
{
struct V_6 * V_6 = V_86 -> V_201 ;
int V_13 = V_139 | V_14 ;
T_7 V_178 = * ( T_7 * ) V_24 -> V_304 ;
return F_83 ( V_6 , NULL , V_13 , V_178 , V_24 -> V_196 ) ;
}
static int F_171 ( struct V_86 * V_86 ,
const unsigned char * V_226 ,
T_1 V_1 )
{
struct V_6 * V_6 = V_86 -> V_201 ;
int V_13 = V_14 | V_223 ;
if ( V_6 -> V_207 != V_208 &&
V_6 -> V_207 != V_209 )
return 0 ;
return F_117 ( V_6 , NULL , V_226 , V_1 , V_13 ) ;
}
static struct V_6 * F_172 ( struct V_190 * V_186 ,
struct V_199 * V_199 )
{
struct V_86 * V_86 ;
V_86 = F_173 ( V_186 , V_199 ) ;
return V_86 ? V_86 -> V_201 : NULL ;
}
static int F_174 ( struct V_199 * V_199 ,
const struct V_305 * V_306 )
{
struct V_127 * V_127 = V_199 -> V_201 ;
struct V_6 * V_6 ;
int V_90 ;
if ( V_127 -> V_307 )
return 0 ;
V_6 = F_172 ( V_306 -> V_161 -> V_276 , V_199 ) ;
if ( ! V_6 )
return 0 ;
V_90 = F_135 ( V_6 , NULL , F_175 ( V_306 -> V_158 ) ,
V_306 -> V_269 , V_306 -> V_161 ,
V_306 -> V_270 , 0 ) ;
if ( V_90 )
return V_90 ;
F_176 ( V_306 -> V_161 ) ;
return 0 ;
}
static int F_177 ( struct V_199 * V_199 ,
const struct V_305 * V_306 )
{
struct V_127 * V_127 = V_199 -> V_201 ;
struct V_6 * V_6 ;
if ( V_127 -> V_307 )
return 0 ;
V_6 = F_172 ( V_306 -> V_161 -> V_276 , V_199 ) ;
if ( ! V_6 )
return 0 ;
F_178 ( V_306 -> V_161 ) ;
return F_135 ( V_6 , NULL , F_175 ( V_306 -> V_158 ) ,
V_306 -> V_269 , V_306 -> V_161 ,
V_306 -> V_270 , V_139 ) ;
}
static void F_179 ( struct V_199 * V_199 )
{
struct V_127 * V_127 = V_199 -> V_201 ;
struct V_6 * V_6 ;
struct V_28 * V_281 ;
struct V_239 * V_240 ;
unsigned long V_13 ;
int V_241 ;
if ( V_127 -> V_307 )
return;
F_48 ( & V_127 -> V_133 , V_13 ) ;
F_119 (ofdpa->flow_tbl, bkt, tmp, flow_entry, entry) {
if ( V_281 -> V_31 . V_95 !=
V_104 )
continue;
V_6 = F_172 ( V_281 -> V_161 -> V_276 ,
V_199 ) ;
if ( ! V_6 )
continue;
F_178 ( V_281 -> V_161 ) ;
F_53 ( V_6 , NULL , V_139 ,
V_281 ) ;
}
F_51 ( & V_127 -> V_133 , V_13 ) ;
V_127 -> V_307 = true ;
}
