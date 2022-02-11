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
T_5 V_62 , int V_13 )
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
V_29 -> V_130 = F_63 ( struct V_160 ,
V_56 . V_62 ) ;
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
V_97 = V_161 ;
if ( V_51 && V_53 ) {
if ( F_61 ( V_53 , V_162 ) )
V_97 = V_163 ;
else if ( F_65 ( V_51 ) )
V_97 = V_164 ;
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
F_48 ( & V_127 -> V_165 , V_131 ) ;
V_129 = F_66 ( V_127 , V_128 ) ;
if ( V_129 ) {
if ( ! F_12 ( V_16 ) )
F_49 ( & V_129 -> V_29 ) ;
F_67 ( V_16 , V_129 ) ;
V_129 = V_128 ;
V_129 -> V_92 = V_166 ;
} else {
V_129 = V_128 ;
V_129 -> V_92 = V_167 ;
}
if ( ! F_12 ( V_16 ) )
F_50 ( V_127 -> V_168 , & V_129 -> V_29 , V_129 -> V_62 ) ;
F_51 ( & V_127 -> V_165 , V_131 ) ;
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
F_48 ( & V_127 -> V_165 , V_131 ) ;
V_129 = F_66 ( V_127 , V_128 ) ;
if ( V_129 ) {
if ( ! F_12 ( V_16 ) )
F_49 ( & V_129 -> V_29 ) ;
V_129 -> V_92 = V_169 ;
}
F_51 ( & V_127 -> V_165 , V_131 ) ;
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
T_1 V_1 , T_5 V_170 ,
int V_8 )
{
struct V_108 * V_29 ;
V_29 = F_15 ( V_16 , V_13 , sizeof( * V_29 ) ) ;
if ( ! V_29 )
return - V_141 ;
V_29 -> V_62 = F_72 ( V_1 , V_170 ) ;
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
T_5 V_171 , const T_6 * V_172 , const T_6 * V_173 ,
T_1 V_1 , bool V_121 , T_5 V_174 )
{
struct V_108 * V_29 ;
V_29 = F_15 ( V_16 , V_13 , sizeof( * V_29 ) ) ;
if ( ! V_29 )
return - V_141 ;
V_29 -> V_62 = F_76 ( V_171 ) ;
if ( V_172 )
F_59 ( V_29 -> V_119 . V_70 , V_172 ) ;
if ( V_173 )
F_59 ( V_29 -> V_119 . V_51 , V_173 ) ;
V_29 -> V_119 . V_1 = V_1 ;
V_29 -> V_119 . V_121 = V_121 ;
V_29 -> V_119 . V_62 = F_72 ( V_1 , V_174 ) ;
return F_70 ( V_6 , V_16 , V_13 , V_29 ) ;
}
static struct V_175 *
F_77 ( const struct V_127 * V_127 , T_7 V_176 )
{
struct V_175 * V_129 ;
F_45 (ofdpa->neigh_tbl, found,
entry, be32_to_cpu(ip_addr))
if ( V_129 -> V_176 == V_176 )
return V_129 ;
return NULL ;
}
static void F_78 ( struct V_127 * V_127 ,
struct V_15 * V_16 ,
struct V_175 * V_29 )
{
if ( ! F_79 ( V_16 ) )
V_29 -> V_171 = V_127 -> V_177 ++ ;
if ( F_12 ( V_16 ) )
return;
V_29 -> V_178 ++ ;
F_50 ( V_127 -> V_179 , & V_29 -> V_29 ,
F_80 ( V_29 -> V_176 ) ) ;
}
static void F_81 ( struct V_15 * V_16 ,
struct V_175 * V_29 )
{
if ( F_12 ( V_16 ) )
return;
if ( -- V_29 -> V_178 == 0 ) {
F_49 ( & V_29 -> V_29 ) ;
F_17 ( V_16 , V_29 ) ;
}
}
static void F_82 ( struct V_175 * V_29 ,
struct V_15 * V_16 ,
const T_6 * V_51 , bool V_121 )
{
if ( V_51 ) {
F_59 ( V_29 -> V_51 , V_51 ) ;
V_29 -> V_121 = V_121 ;
} else if ( ! F_12 ( V_16 ) ) {
V_29 -> V_178 ++ ;
}
}
static int F_83 ( struct V_6 * V_6 ,
struct V_15 * V_16 ,
int V_13 , T_7 V_176 , const T_6 * V_51 )
{
struct V_127 * V_127 = V_6 -> V_127 ;
struct V_175 * V_29 ;
struct V_175 * V_129 ;
unsigned long V_131 ;
T_1 V_48 = F_4 ( V_73 ) ;
enum V_140 V_38 =
V_106 ;
T_5 V_62 ;
T_5 V_97 = 0 ;
bool V_180 = ! ( V_13 & V_139 ) ;
bool V_181 ;
bool V_182 ;
int V_90 = 0 ;
V_29 = F_15 ( V_16 , V_13 , sizeof( * V_29 ) ) ;
if ( ! V_29 )
return - V_141 ;
F_48 ( & V_127 -> V_183 , V_131 ) ;
V_129 = F_77 ( V_127 , V_176 ) ;
V_181 = V_129 && V_180 ;
V_182 = V_129 && ! V_180 ;
V_180 = ! V_129 && V_180 ;
if ( V_180 ) {
V_29 -> V_176 = V_176 ;
V_29 -> V_184 = V_6 -> V_184 ;
F_59 ( V_29 -> V_51 , V_51 ) ;
V_29 -> V_121 = true ;
F_78 ( V_127 , V_16 , V_29 ) ;
} else if ( V_182 ) {
memcpy ( V_29 , V_129 , sizeof( * V_29 ) ) ;
F_81 ( V_16 , V_129 ) ;
} else if ( V_181 ) {
F_82 ( V_129 , V_16 , V_51 , true ) ;
memcpy ( V_29 , V_129 , sizeof( * V_29 ) ) ;
} else {
V_90 = - V_185 ;
}
F_51 ( & V_127 -> V_183 , V_131 ) ;
if ( V_90 )
goto V_186;
V_90 = F_75 ( V_6 , V_16 , V_13 ,
V_29 -> V_171 ,
V_6 -> V_184 -> V_187 ,
V_29 -> V_51 ,
V_6 -> V_9 ,
V_29 -> V_121 ,
V_6 -> V_174 ) ;
if ( V_90 ) {
F_84 ( V_6 -> V_184 , L_3 ,
V_90 , V_29 -> V_171 ) ;
goto V_186;
}
if ( V_180 || V_182 ) {
V_62 = F_76 ( V_29 -> V_171 ) ;
V_90 = F_62 ( V_6 , V_16 ,
V_48 , V_176 ,
F_85 ( 32 ) ,
V_97 , V_38 ,
V_62 , V_13 ) ;
if ( V_90 )
F_84 ( V_6 -> V_184 , L_4 ,
V_90 , & V_29 -> V_176 , V_62 ) ;
}
V_186:
if ( ! V_180 )
F_17 ( V_16 , V_29 ) ;
return V_90 ;
}
static int F_86 ( struct V_6 * V_6 ,
struct V_15 * V_16 ,
T_7 V_176 )
{
struct V_188 * V_184 = V_6 -> V_184 ;
struct V_189 * V_24 = F_87 ( V_184 , ( V_190 T_5 ) V_176 ) ;
int V_90 = 0 ;
if ( ! V_24 ) {
V_24 = F_88 ( & V_191 , & V_176 , V_184 ) ;
if ( F_89 ( V_24 ) )
return F_90 ( V_24 ) ;
}
if ( V_24 -> V_192 & V_193 )
V_90 = F_83 ( V_6 , V_16 , 0 ,
V_176 , V_24 -> V_194 ) ;
else
F_91 ( V_24 , NULL ) ;
F_92 ( V_24 ) ;
return V_90 ;
}
static int F_93 ( struct V_6 * V_6 ,
struct V_15 * V_16 , int V_13 ,
T_7 V_176 , T_5 * V_171 )
{
struct V_127 * V_127 = V_6 -> V_127 ;
struct V_175 * V_29 ;
struct V_175 * V_129 ;
unsigned long V_131 ;
bool V_180 = ! ( V_13 & V_139 ) ;
bool V_181 ;
bool V_182 ;
bool V_195 = true ;
int V_90 = 0 ;
V_29 = F_15 ( V_16 , V_13 , sizeof( * V_29 ) ) ;
if ( ! V_29 )
return - V_141 ;
F_48 ( & V_127 -> V_183 , V_131 ) ;
V_129 = F_77 ( V_127 , V_176 ) ;
if ( V_129 )
* V_171 = V_129 -> V_171 ;
V_181 = V_129 && V_180 ;
V_182 = V_129 && ! V_180 ;
V_180 = ! V_129 && V_180 ;
if ( V_180 ) {
V_29 -> V_176 = V_176 ;
V_29 -> V_184 = V_6 -> V_184 ;
F_78 ( V_127 , V_16 , V_29 ) ;
* V_171 = V_29 -> V_171 ;
V_195 = false ;
} else if ( V_182 ) {
F_81 ( V_16 , V_129 ) ;
} else if ( V_181 ) {
F_82 ( V_129 , V_16 , NULL , false ) ;
V_195 = ! F_38 ( V_129 -> V_51 ) ;
} else {
V_90 = - V_185 ;
}
F_51 ( & V_127 -> V_183 , V_131 ) ;
if ( ! V_180 )
F_17 ( V_16 , V_29 ) ;
if ( V_90 )
return V_90 ;
if ( ! V_195 )
V_90 = F_86 ( V_6 , V_16 , V_176 ) ;
return V_90 ;
}
static struct V_6 * F_94 ( const struct V_127 * V_127 ,
int V_196 )
{
struct V_86 * V_86 ;
V_86 = V_127 -> V_197 -> V_198 [ V_196 ] ;
return V_86 ? V_86 -> V_199 : NULL ;
}
static int F_95 ( struct V_6 * V_6 ,
struct V_15 * V_16 ,
int V_13 , T_1 V_1 )
{
struct V_6 * V_200 ;
const struct V_127 * V_127 = V_6 -> V_127 ;
unsigned int V_201 = V_127 -> V_197 -> V_201 ;
T_5 V_62 = F_96 ( V_1 , 0 ) ;
T_5 * V_115 ;
T_6 V_117 = 0 ;
int V_90 = 0 ;
int V_114 ;
V_115 = F_16 ( V_16 , V_13 , V_201 , sizeof( T_5 ) ) ;
if ( ! V_115 )
return - V_141 ;
for ( V_114 = 0 ; V_114 < V_201 ; V_114 ++ ) {
V_200 = F_94 ( V_127 , V_114 ) ;
if ( ! V_200 )
continue;
if ( ! F_7 ( V_200 ) )
continue;
if ( F_97 ( F_2 ( V_1 ) , V_200 -> V_202 ) ) {
V_115 [ V_117 ++ ] =
F_72 ( V_1 , V_200 -> V_174 ) ;
}
}
if ( V_117 == 0 )
goto V_203;
V_90 = F_74 ( V_6 , V_16 , V_13 , V_1 ,
V_117 , V_115 , V_62 ) ;
if ( V_90 )
F_84 ( V_6 -> V_184 , L_5 , V_90 ) ;
V_203:
F_17 ( V_16 , V_115 ) ;
return V_90 ;
}
static int F_98 ( struct V_6 * V_6 ,
struct V_15 * V_16 , int V_13 ,
T_1 V_1 , bool V_8 )
{
const struct V_127 * V_127 = V_6 -> V_127 ;
unsigned int V_201 = V_127 -> V_197 -> V_201 ;
struct V_6 * V_200 ;
bool V_180 = ! ( V_13 & V_139 ) ;
T_5 V_170 ;
int V_204 = 0 ;
int V_90 ;
int V_114 ;
if ( V_6 -> V_205 == V_206 ||
V_6 -> V_205 == V_207 ) {
V_170 = V_6 -> V_174 ;
V_90 = F_71 ( V_6 , V_16 , V_13 ,
V_1 , V_170 , V_8 ) ;
if ( V_90 ) {
F_84 ( V_6 -> V_184 , L_6 ,
V_90 , V_170 ) ;
return V_90 ;
}
}
for ( V_114 = 0 ; V_114 < V_201 ; V_114 ++ ) {
V_200 = F_94 ( V_127 , V_114 ) ;
if ( V_200 && F_97 ( F_2 ( V_1 ) , V_200 -> V_202 ) )
V_204 ++ ;
}
if ( ( ! V_180 || V_204 != 1 ) && ( V_180 || V_204 != 0 ) )
return 0 ;
V_170 = 0 ;
V_90 = F_71 ( V_6 , V_16 , V_13 ,
V_1 , V_170 , V_8 ) ;
if ( V_90 ) {
F_84 ( V_6 -> V_184 , L_7 , V_90 ) ;
return V_90 ;
}
return 0 ;
}
static int F_99 ( struct V_6 * V_6 ,
struct V_15 * V_16 , int V_13 ,
const struct V_208 * V_209 , T_1 V_1 )
{
T_5 V_33 = V_6 -> V_174 ;
T_5 V_36 = 0xffffffff ;
T_5 V_170 = 0 ;
const T_6 * V_70 = NULL ;
const T_6 * V_72 = NULL ;
T_1 V_42 = F_4 ( 0xffff ) ;
T_6 V_76 = 0 ;
T_6 V_78 = 0 ;
T_6 V_80 = 0 ;
T_6 V_82 = 0 ;
T_5 V_62 = F_72 ( V_1 , V_170 ) ;
int V_90 ;
V_90 = F_64 ( V_6 , V_16 , V_13 ,
V_33 , V_36 ,
V_70 , V_72 ,
V_209 -> V_51 , V_209 -> V_53 ,
V_209 -> V_48 ,
V_1 , V_42 ,
V_76 , V_78 ,
V_80 , V_82 ,
V_62 ) ;
if ( V_90 )
F_84 ( V_6 -> V_184 , L_8 , V_90 ) ;
return V_90 ;
}
static int F_100 ( struct V_6 * V_6 ,
struct V_15 * V_16 ,
int V_13 ,
const struct V_208 * V_209 ,
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
V_209 -> V_51 , V_209 -> V_53 ,
V_1 , V_66 ,
V_38 , V_62 , V_209 -> V_54 ) ;
if ( V_90 )
F_84 ( V_6 -> V_184 , L_9 , V_90 ) ;
return V_90 ;
}
static int F_101 ( struct V_6 * V_6 ,
struct V_15 * V_16 , int V_13 ,
const struct V_208 * V_209 , T_1 V_1 )
{
T_5 V_36 = 0xffffffff ;
T_1 V_42 = F_4 ( 0xffff ) ;
int V_90 ;
if ( F_2 ( V_1 ) == 0 )
V_1 = V_6 -> V_9 ;
V_90 = F_57 ( V_6 , V_16 ,
V_6 -> V_174 , V_36 ,
V_209 -> V_48 , V_209 -> V_51 ,
V_209 -> V_53 , V_1 ,
V_42 , V_209 -> V_54 ,
V_13 ) ;
if ( V_90 )
F_84 ( V_6 -> V_184 , L_10 , V_90 ) ;
return V_90 ;
}
static int F_102 ( struct V_6 * V_6 ,
struct V_15 * V_16 , int V_13 ,
const struct V_208 * V_209 , T_1 V_1 )
{
if ( V_209 -> V_68 )
return F_99 ( V_6 , V_16 , V_13 ,
V_209 , V_1 ) ;
if ( V_209 -> V_63 )
return F_100 ( V_6 , V_16 , V_13 ,
V_209 , V_1 ) ;
if ( V_209 -> V_210 )
return F_101 ( V_6 , V_16 , V_13 ,
V_209 , V_1 ) ;
return - V_211 ;
}
static int F_103 ( struct V_6 * V_6 ,
struct V_15 * V_16 , int V_13 ,
T_1 V_1 )
{
int V_90 = 0 ;
int V_114 ;
for ( V_114 = 0 ; V_114 < V_212 ; V_114 ++ ) {
if ( V_6 -> V_213 [ V_114 ] ) {
V_90 = F_102 ( V_6 , V_16 , V_13 ,
& V_214 [ V_114 ] , V_1 ) ;
if ( V_90 )
return V_90 ;
}
}
return V_90 ;
}
static int F_104 ( struct V_6 * V_6 ,
struct V_15 * V_16 , int V_13 ,
const struct V_208 * V_209 )
{
T_2 V_7 ;
int V_90 = 0 ;
for ( V_7 = 1 ; V_7 < V_215 ; V_7 ++ ) {
if ( ! F_97 ( V_7 , V_6 -> V_202 ) )
continue;
V_90 = F_102 ( V_6 , V_16 , V_13 ,
V_209 , F_4 ( V_7 ) ) ;
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
T_5 V_33 = V_6 -> V_174 ;
T_1 V_1 = F_4 ( V_7 ) ;
T_1 V_42 = F_4 ( 0xffff ) ;
T_1 V_9 ;
bool V_43 ;
bool V_180 = ! ( V_13 & V_139 ) ;
int V_90 ;
V_9 = F_3 ( V_6 , V_7 , & V_43 ) ;
if ( V_180 &&
F_97 ( F_2 ( V_9 ) , V_6 -> V_202 ) )
return 0 ;
else if ( ! V_180 &&
! F_97 ( F_2 ( V_9 ) , V_6 -> V_202 ) )
return 0 ;
F_106 ( F_2 ( V_9 ) , V_6 -> V_202 ) ;
if ( V_180 ) {
V_90 = F_103 ( V_6 , V_16 , V_13 ,
V_9 ) ;
if ( V_90 ) {
F_84 ( V_6 -> V_184 , L_11 , V_90 ) ;
goto V_186;
}
}
V_90 = F_98 ( V_6 , V_16 , V_13 ,
V_9 , V_43 ) ;
if ( V_90 ) {
F_84 ( V_6 -> V_184 , L_12 , V_90 ) ;
goto V_186;
}
V_90 = F_95 ( V_6 , V_16 , V_13 ,
V_9 ) ;
if ( V_90 ) {
F_84 ( V_6 -> V_184 , L_5 , V_90 ) ;
goto V_186;
}
V_90 = F_56 ( V_6 , V_16 , V_13 ,
V_33 , V_1 , V_42 ,
V_38 , V_43 , V_9 ) ;
if ( V_90 )
F_84 ( V_6 -> V_184 , L_13 , V_90 ) ;
V_186:
if ( F_12 ( V_16 ) )
F_106 ( F_2 ( V_9 ) , V_6 -> V_202 ) ;
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
F_84 ( V_6 -> V_184 , L_14 , V_90 ) ;
return V_90 ;
}
static void F_108 ( struct V_216 * V_217 )
{
const struct V_218 * V_219 =
F_109 ( V_217 , struct V_218 , V_217 ) ;
bool V_182 = ( V_219 -> V_13 & V_139 ) ;
bool V_220 = ( V_219 -> V_13 & V_221 ) ;
struct V_222 V_223 ;
V_223 . V_224 = V_219 -> V_224 ;
V_223 . V_7 = V_219 -> V_7 ;
F_110 () ;
if ( V_220 && V_182 )
F_111 ( V_225 ,
V_219 -> V_6 -> V_184 , & V_223 . V_223 ) ;
else if ( V_220 && ! V_182 )
F_111 ( V_226 ,
V_219 -> V_6 -> V_184 , & V_223 . V_223 ) ;
F_112 () ;
F_17 ( V_219 -> V_16 , V_217 ) ;
}
static int F_113 ( struct V_6 * V_6 ,
struct V_15 * V_16 , int V_13 ,
const T_6 * V_224 , T_1 V_1 )
{
struct V_218 * V_219 ;
enum V_140 V_38 =
V_106 ;
T_5 V_170 = V_6 -> V_174 ;
T_5 V_66 = 0 ;
T_5 V_62 = V_85 ;
bool V_227 = ! ! ( V_6 -> V_228 & V_229 ) ;
bool V_54 = false ;
int V_90 ;
if ( F_7 ( V_6 ) )
V_62 = F_72 ( V_1 , V_170 ) ;
if ( ! ( V_13 & V_230 ) ) {
V_90 = F_60 ( V_6 , V_16 , V_13 , V_224 ,
NULL , V_1 , V_66 , V_38 ,
V_62 , V_54 ) ;
if ( V_90 )
return V_90 ;
}
if ( ! V_227 )
return 0 ;
if ( ! F_7 ( V_6 ) )
return 0 ;
V_219 = F_15 ( V_16 , V_13 , sizeof( * V_219 ) ) ;
if ( ! V_219 )
return - V_141 ;
F_114 ( & V_219 -> V_217 , F_108 ) ;
V_219 -> V_6 = V_6 ;
V_219 -> V_16 = V_16 ;
V_219 -> V_13 = V_13 ;
F_59 ( V_219 -> V_224 , V_224 ) ;
V_219 -> V_7 = F_5 ( V_6 , V_1 ) ;
if ( F_12 ( V_16 ) )
F_17 ( V_16 , V_219 ) ;
else
F_115 ( & V_219 -> V_217 ) ;
return 0 ;
}
static struct V_231 *
F_116 ( const struct V_127 * V_127 ,
const struct V_231 * V_128 )
{
struct V_231 * V_129 ;
F_45 (ofdpa->fdb_tbl, found, entry, match->key_crc32)
if ( memcmp ( & V_129 -> V_31 , & V_128 -> V_31 , sizeof( V_129 -> V_31 ) ) == 0 )
return V_129 ;
return NULL ;
}
static int F_117 ( struct V_6 * V_6 ,
struct V_15 * V_16 ,
const unsigned char * V_224 ,
T_1 V_1 , int V_13 )
{
struct V_127 * V_127 = V_6 -> V_127 ;
struct V_231 * V_232 ;
struct V_231 * V_129 ;
bool V_182 = ( V_13 & V_139 ) ;
unsigned long V_131 ;
V_232 = F_15 ( V_16 , V_13 , sizeof( * V_232 ) ) ;
if ( ! V_232 )
return - V_141 ;
V_232 -> V_220 = ( V_13 & V_221 ) ;
V_232 -> V_233 = V_234 ;
V_232 -> V_31 . V_6 = V_6 ;
F_59 ( V_232 -> V_31 . V_224 , V_224 ) ;
V_232 -> V_31 . V_1 = V_1 ;
V_232 -> V_132 = F_47 ( ~ 0 , & V_232 -> V_31 , sizeof( V_232 -> V_31 ) ) ;
F_48 ( & V_127 -> V_235 , V_131 ) ;
V_129 = F_116 ( V_127 , V_232 ) ;
if ( V_129 ) {
V_129 -> V_233 = V_234 ;
if ( V_182 ) {
F_17 ( V_16 , V_232 ) ;
if ( ! F_12 ( V_16 ) )
F_49 ( & V_129 -> V_29 ) ;
}
} else if ( ! V_182 ) {
if ( ! F_12 ( V_16 ) )
F_50 ( V_127 -> V_236 , & V_232 -> V_29 ,
V_232 -> V_132 ) ;
}
F_51 ( & V_127 -> V_235 , V_131 ) ;
if ( ! V_129 != ! V_182 ) {
F_17 ( V_16 , V_232 ) ;
if ( ! V_129 && V_182 )
return 0 ;
V_13 |= V_230 ;
}
return F_113 ( V_6 , V_16 , V_13 , V_224 , V_1 ) ;
}
static int F_118 ( struct V_6 * V_6 ,
struct V_15 * V_16 , int V_13 )
{
struct V_127 * V_127 = V_6 -> V_127 ;
struct V_231 * V_129 ;
unsigned long V_131 ;
struct V_237 * V_238 ;
int V_239 ;
int V_90 = 0 ;
if ( V_6 -> V_205 == V_206 ||
V_6 -> V_205 == V_207 )
return 0 ;
V_13 |= V_14 | V_139 ;
F_48 ( & V_127 -> V_235 , V_131 ) ;
F_119 (ofdpa->fdb_tbl, bkt, tmp, found, entry) {
if ( V_129 -> V_31 . V_6 != V_6 )
continue;
if ( ! V_129 -> V_220 )
continue;
V_90 = F_113 ( V_6 , V_16 , V_13 ,
V_129 -> V_31 . V_224 ,
V_129 -> V_31 . V_1 ) ;
if ( V_90 )
goto V_186;
if ( ! F_12 ( V_16 ) )
F_49 ( & V_129 -> V_29 ) ;
}
V_186:
F_51 ( & V_127 -> V_235 , V_131 ) ;
return V_90 ;
}
static void F_120 ( unsigned long V_240 )
{
struct V_127 * V_127 = (struct V_127 * ) V_240 ;
struct V_6 * V_6 ;
struct V_231 * V_29 ;
struct V_237 * V_238 ;
unsigned long V_241 = V_234 + V_127 -> V_242 ;
unsigned long V_243 ;
unsigned long V_131 ;
int V_13 = V_14 | V_139 |
V_221 ;
int V_239 ;
F_48 ( & V_127 -> V_235 , V_131 ) ;
F_119 (ofdpa->fdb_tbl, bkt, tmp, entry, entry) {
if ( ! V_29 -> V_220 )
continue;
V_6 = V_29 -> V_31 . V_6 ;
V_243 = V_29 -> V_233 + V_6 -> V_242 ;
if ( F_121 ( V_243 , V_234 ) ) {
F_113 ( V_6 , NULL ,
V_13 , V_29 -> V_31 . V_224 ,
V_29 -> V_31 . V_1 ) ;
F_49 ( & V_29 -> V_29 ) ;
} else if ( F_122 ( V_243 , V_241 ) ) {
V_241 = V_243 ;
}
}
F_51 ( & V_127 -> V_235 , V_131 ) ;
F_123 ( & V_127 -> V_244 , F_124 ( V_241 ) ) ;
}
static int F_125 ( struct V_6 * V_6 ,
struct V_15 * V_16 , int V_13 ,
T_1 V_1 )
{
T_5 V_36 = 0xffffffff ;
T_1 V_48 ;
const T_6 * V_245 = V_150 ;
T_1 V_42 = F_4 ( 0xffff ) ;
bool V_54 = false ;
int V_90 ;
if ( F_2 ( V_1 ) == 0 )
V_1 = V_6 -> V_9 ;
V_48 = F_4 ( V_73 ) ;
V_90 = F_57 ( V_6 , V_16 ,
V_6 -> V_174 , V_36 ,
V_48 , V_6 -> V_184 -> V_187 ,
V_245 , V_1 , V_42 ,
V_54 , V_13 ) ;
if ( V_90 )
return V_90 ;
V_48 = F_4 ( V_74 ) ;
V_90 = F_57 ( V_6 , V_16 ,
V_6 -> V_174 , V_36 ,
V_48 , V_6 -> V_184 -> V_187 ,
V_245 , V_1 , V_42 ,
V_54 , V_13 ) ;
return V_90 ;
}
static int F_126 ( struct V_6 * V_6 ,
struct V_15 * V_16 , int V_13 )
{
bool V_8 ;
T_5 V_170 ;
T_1 V_1 ;
T_2 V_7 ;
int V_90 ;
if ( V_6 -> V_205 != V_206 &&
V_6 -> V_205 != V_207 )
V_13 |= V_139 ;
V_170 = V_6 -> V_174 ;
for ( V_7 = 1 ; V_7 < V_215 ; V_7 ++ ) {
if ( ! F_97 ( V_7 , V_6 -> V_202 ) )
continue;
V_1 = F_4 ( V_7 ) ;
V_8 = F_1 ( V_1 ) ;
V_90 = F_71 ( V_6 , V_16 , V_13 ,
V_1 , V_170 , V_8 ) ;
if ( V_90 ) {
F_84 ( V_6 -> V_184 , L_6 ,
V_90 , V_170 ) ;
return V_90 ;
}
}
return 0 ;
}
static int F_127 ( struct V_6 * V_6 ,
struct V_15 * V_16 ,
int V_13 , T_6 V_246 )
{
bool V_247 [ V_212 ] = { 0 , } ;
bool V_248 [ V_212 ] ;
T_6 V_249 ( V_250 ) ;
int V_90 ;
int V_114 ;
if ( F_12 ( V_16 ) ) {
memcpy ( V_248 , V_6 -> V_213 , sizeof( V_248 ) ) ;
V_250 = V_6 -> V_205 ;
}
if ( V_6 -> V_205 == V_246 )
return 0 ;
V_6 -> V_205 = V_246 ;
switch ( V_246 ) {
case V_251 :
break;
case V_252 :
case V_253 :
V_247 [ V_254 ] = true ;
break;
case V_206 :
case V_207 :
if ( ! F_8 ( V_6 ) )
V_247 [ V_254 ] = true ;
V_247 [ V_255 ] = true ;
V_247 [ V_256 ] = true ;
if ( F_7 ( V_6 ) )
V_247 [ V_257 ] = true ;
else if ( F_8 ( V_6 ) )
V_247 [ V_258 ] = true ;
else
V_247 [ V_259 ] = true ;
break;
}
for ( V_114 = 0 ; V_114 < V_212 ; V_114 ++ ) {
if ( V_247 [ V_114 ] != V_6 -> V_213 [ V_114 ] ) {
int V_260 = V_13 |
( V_247 [ V_114 ] ? 0 : V_139 ) ;
V_90 = F_104 ( V_6 , V_16 , V_260 ,
& V_214 [ V_114 ] ) ;
if ( V_90 )
goto V_186;
V_6 -> V_213 [ V_114 ] = V_247 [ V_114 ] ;
}
}
V_90 = F_118 ( V_6 , V_16 , V_13 ) ;
if ( V_90 )
goto V_186;
V_90 = F_126 ( V_6 , V_16 , V_13 ) ;
V_186:
if ( F_12 ( V_16 ) ) {
memcpy ( V_6 -> V_213 , V_248 , sizeof( V_248 ) ) ;
V_6 -> V_205 = V_250 ;
}
return V_90 ;
}
static int F_128 ( struct V_6 * V_6 , int V_13 )
{
if ( F_7 ( V_6 ) )
return 0 ;
return F_127 ( V_6 , NULL , V_13 ,
V_207 ) ;
}
static int F_129 ( struct V_6 * V_6 , int V_13 )
{
if ( F_7 ( V_6 ) )
return 0 ;
return F_127 ( V_6 , NULL , V_13 ,
V_251 ) ;
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
static struct V_261 *
F_132 ( const struct V_127 * V_127 , int V_262 )
{
struct V_261 * V_129 ;
F_45 (ofdpa->internal_vlan_tbl, found,
entry, ifindex) {
if ( V_129 -> V_262 == V_262 )
return V_129 ;
}
return NULL ;
}
static T_1 F_133 ( struct V_6 * V_6 ,
int V_262 )
{
struct V_127 * V_127 = V_6 -> V_127 ;
struct V_261 * V_29 ;
struct V_261 * V_129 ;
unsigned long V_131 ;
int V_114 ;
V_29 = F_11 ( sizeof( * V_29 ) , V_22 ) ;
if ( ! V_29 )
return 0 ;
V_29 -> V_262 = V_262 ;
F_48 ( & V_127 -> V_263 , V_131 ) ;
V_129 = F_132 ( V_127 , V_262 ) ;
if ( V_129 ) {
V_23 ( V_29 ) ;
goto V_129;
}
V_129 = V_29 ;
F_50 ( V_127 -> V_264 , & V_129 -> V_29 , V_129 -> V_262 ) ;
for ( V_114 = 0 ; V_114 < V_265 ; V_114 ++ ) {
if ( F_134 ( V_114 , V_127 -> V_266 ) )
continue;
V_129 -> V_1 = F_4 ( V_3 + V_114 ) ;
goto V_129;
}
F_84 ( V_6 -> V_184 , L_15 ) ;
V_129:
V_129 -> V_178 ++ ;
F_51 ( & V_127 -> V_263 , V_131 ) ;
return V_129 -> V_1 ;
}
static int F_135 ( struct V_6 * V_6 ,
struct V_15 * V_16 , T_7 V_158 ,
int V_267 , const struct V_268 * V_269 ,
T_5 V_270 , int V_13 )
{
const struct V_271 * V_272 ;
T_1 V_48 = F_4 ( V_73 ) ;
T_7 V_159 = F_85 ( V_267 ) ;
T_1 V_9 = V_6 -> V_9 ;
T_5 V_97 = V_269 -> V_273 ;
enum V_140 V_38 =
V_106 ;
T_5 V_62 ;
bool V_274 ;
bool V_275 ;
T_5 V_171 ;
int V_90 ;
V_272 = V_269 -> V_271 ;
V_274 = ( V_269 -> V_276 == V_6 -> V_184 ) ;
V_275 = ! ! V_272 -> V_277 ;
if ( V_275 && V_274 ) {
V_90 = F_93 ( V_6 , V_16 , V_13 ,
V_272 -> V_277 , & V_171 ) ;
if ( V_90 )
return V_90 ;
V_62 = F_76 ( V_171 ) ;
} else {
V_62 = F_72 ( V_9 , 0 ) ;
}
V_90 = F_62 ( V_6 , V_16 , V_48 , V_158 ,
V_159 , V_97 , V_38 ,
V_62 , V_13 ) ;
if ( V_90 )
F_84 ( V_6 -> V_184 , L_16 ,
V_90 , & V_158 ) ;
return V_90 ;
}
static void
F_136 ( const struct V_6 * V_6 ,
int V_262 )
{
struct V_127 * V_127 = V_6 -> V_127 ;
struct V_261 * V_129 ;
unsigned long V_131 ;
unsigned long V_278 ;
F_48 ( & V_127 -> V_263 , V_131 ) ;
V_129 = F_132 ( V_127 , V_262 ) ;
if ( ! V_129 ) {
F_84 ( V_6 -> V_184 ,
L_17 ,
V_262 ) ;
goto V_279;
}
if ( -- V_129 -> V_178 <= 0 ) {
V_278 = F_2 ( V_129 -> V_1 ) - V_3 ;
F_137 ( V_278 , V_127 -> V_266 ) ;
F_49 ( & V_129 -> V_29 ) ;
V_23 ( V_129 ) ;
}
V_279:
F_51 ( & V_127 -> V_263 , V_131 ) ;
}
static int F_138 ( struct V_197 * V_197 )
{
struct V_127 * V_127 = V_197 -> V_199 ;
V_127 -> V_197 = V_197 ;
F_139 ( V_127 -> V_137 ) ;
F_140 ( & V_127 -> V_133 ) ;
F_139 ( V_127 -> V_168 ) ;
F_140 ( & V_127 -> V_165 ) ;
F_139 ( V_127 -> V_236 ) ;
F_140 ( & V_127 -> V_235 ) ;
F_139 ( V_127 -> V_264 ) ;
F_140 ( & V_127 -> V_263 ) ;
F_139 ( V_127 -> V_179 ) ;
F_140 ( & V_127 -> V_183 ) ;
F_141 ( & V_127 -> V_244 , F_120 ,
( unsigned long ) V_127 ) ;
F_123 ( & V_127 -> V_244 , V_234 ) ;
V_127 -> V_242 = V_280 ;
return 0 ;
}
static void F_142 ( struct V_197 * V_197 )
{
struct V_127 * V_127 = V_197 -> V_199 ;
unsigned long V_13 ;
struct V_28 * V_281 ;
struct V_108 * V_282 ;
struct V_231 * V_283 ;
struct V_261 * V_284 ;
struct V_175 * V_285 ;
struct V_237 * V_238 ;
int V_239 ;
F_143 ( & V_127 -> V_244 ) ;
F_48 ( & V_127 -> V_133 , V_13 ) ;
F_119 (ofdpa->flow_tbl, bkt, tmp, flow_entry, entry)
F_49 ( & V_281 -> V_29 ) ;
F_51 ( & V_127 -> V_133 , V_13 ) ;
F_48 ( & V_127 -> V_165 , V_13 ) ;
F_119 (ofdpa->group_tbl, bkt, tmp, group_entry, entry)
F_49 ( & V_282 -> V_29 ) ;
F_51 ( & V_127 -> V_165 , V_13 ) ;
F_48 ( & V_127 -> V_235 , V_13 ) ;
F_119 (ofdpa->fdb_tbl, bkt, tmp, fdb_entry, entry)
F_49 ( & V_283 -> V_29 ) ;
F_51 ( & V_127 -> V_235 , V_13 ) ;
F_48 ( & V_127 -> V_263 , V_13 ) ;
F_119 (ofdpa->internal_vlan_tbl, bkt,
tmp, internal_vlan_entry, entry)
F_49 ( & V_284 -> V_29 ) ;
F_51 ( & V_127 -> V_263 , V_13 ) ;
F_48 ( & V_127 -> V_183 , V_13 ) ;
F_119 (ofdpa->neigh_tbl, bkt, tmp, neigh_entry, entry)
F_49 ( & V_285 -> V_29 ) ;
F_51 ( & V_127 -> V_183 , V_13 ) ;
}
static int F_144 ( struct V_86 * V_86 )
{
struct V_6 * V_6 = V_86 -> V_199 ;
V_6 -> V_127 = V_86 -> V_197 -> V_199 ;
V_6 -> V_86 = V_86 ;
V_6 -> V_184 = V_86 -> V_184 ;
V_6 -> V_174 = V_86 -> V_174 ;
V_6 -> V_228 = V_286 | V_229 ;
V_6 -> V_242 = V_280 ;
return 0 ;
}
static int F_145 ( struct V_86 * V_86 )
{
struct V_6 * V_6 = V_86 -> V_199 ;
int V_90 ;
F_146 ( V_6 -> V_184 , NULL , false ) ;
F_147 ( V_86 ,
! ! ( V_6 -> V_228 & V_286 ) ) ;
V_90 = F_107 ( V_6 , NULL , 0 ) ;
if ( V_90 ) {
F_84 ( V_6 -> V_184 , L_18 ) ;
return V_90 ;
}
V_6 -> V_9 =
F_133 ( V_6 ,
V_6 -> V_184 -> V_262 ) ;
V_90 = F_130 ( V_6 , NULL , V_287 , 0 ) ;
if ( V_90 ) {
F_84 ( V_6 -> V_184 , L_19 ) ;
goto V_288;
}
return 0 ;
V_288:
F_107 ( V_6 , NULL , V_139 ) ;
return V_90 ;
}
static void F_148 ( struct V_86 * V_86 )
{
struct V_6 * V_6 = V_86 -> V_199 ;
F_107 ( V_6 , NULL , V_139 ) ;
}
static int F_149 ( struct V_86 * V_86 )
{
struct V_6 * V_6 = V_86 -> V_199 ;
return F_128 ( V_6 , 0 ) ;
}
static void F_150 ( struct V_86 * V_86 )
{
struct V_6 * V_6 = V_86 -> V_199 ;
F_129 ( V_6 , V_14 ) ;
}
static int F_151 ( struct V_86 * V_86 ,
T_6 V_246 ,
struct V_15 * V_16 )
{
struct V_6 * V_6 = V_86 -> V_199 ;
return F_127 ( V_6 , V_16 , 0 , V_246 ) ;
}
static int F_152 ( struct V_86 * V_86 ,
unsigned long V_228 ,
struct V_15 * V_16 )
{
struct V_6 * V_6 = V_86 -> V_199 ;
unsigned long V_289 ;
int V_90 = 0 ;
V_289 = V_6 -> V_228 ;
V_6 -> V_228 = V_228 ;
if ( ( V_289 ^ V_6 -> V_228 ) & V_286 &&
! F_12 ( V_16 ) )
V_90 = F_147 ( V_6 -> V_86 ,
! ! ( V_6 -> V_228 & V_286 ) ) ;
if ( F_12 ( V_16 ) )
V_6 -> V_228 = V_289 ;
return V_90 ;
}
static int
F_153 ( const struct V_86 * V_86 ,
unsigned long * V_290 )
{
const struct V_6 * V_6 = V_86 -> V_199 ;
* V_290 = V_6 -> V_228 ;
return 0 ;
}
static int
F_154 ( struct V_86 * V_86 ,
T_5 V_242 ,
struct V_15 * V_16 )
{
struct V_6 * V_6 = V_86 -> V_199 ;
struct V_127 * V_127 = V_6 -> V_127 ;
if ( ! F_12 ( V_16 ) ) {
V_6 -> V_242 = F_155 ( V_242 ) ;
if ( V_6 -> V_242 < V_127 -> V_242 )
V_127 -> V_242 = V_6 -> V_242 ;
F_123 ( & V_6 -> V_127 -> V_244 , V_234 ) ;
}
return 0 ;
}
static int F_156 ( struct V_86 * V_86 ,
const struct V_291 * V_39 ,
struct V_15 * V_16 )
{
struct V_6 * V_6 = V_86 -> V_199 ;
T_2 V_7 ;
int V_90 ;
for ( V_7 = V_39 -> V_292 ; V_7 <= V_39 -> V_293 ; V_7 ++ ) {
V_90 = F_130 ( V_6 , V_16 , V_7 , V_39 -> V_13 ) ;
if ( V_90 )
return V_90 ;
}
return 0 ;
}
static int F_157 ( struct V_86 * V_86 ,
const struct V_291 * V_39 )
{
struct V_6 * V_6 = V_86 -> V_199 ;
T_2 V_7 ;
int V_90 ;
for ( V_7 = V_39 -> V_292 ; V_7 <= V_39 -> V_293 ; V_7 ++ ) {
V_90 = F_131 ( V_6 , V_7 , V_39 -> V_13 ) ;
if ( V_90 )
return V_90 ;
}
return 0 ;
}
static int F_158 ( const struct V_86 * V_86 ,
struct V_291 * V_39 ,
T_8 * V_294 )
{
const struct V_6 * V_6 = V_86 -> V_199 ;
T_2 V_7 ;
int V_90 = 0 ;
for ( V_7 = 1 ; V_7 < V_215 ; V_7 ++ ) {
if ( ! F_97 ( V_7 , V_6 -> V_202 ) )
continue;
V_39 -> V_13 = 0 ;
if ( F_1 ( F_4 ( V_7 ) ) )
V_39 -> V_13 |= V_295 ;
V_39 -> V_292 = V_39 -> V_293 = V_7 ;
V_90 = V_294 ( & V_39 -> V_296 ) ;
if ( V_90 )
break;
}
return V_90 ;
}
static int F_159 ( struct V_86 * V_86 ,
const struct V_297 * V_298 ,
struct V_15 * V_16 )
{
struct V_6 * V_6 = V_86 -> V_199 ;
return F_135 ( V_6 , V_16 ,
F_160 ( V_298 -> V_158 ) , V_298 -> V_267 ,
V_298 -> V_269 , V_298 -> V_270 , 0 ) ;
}
static int F_161 ( struct V_86 * V_86 ,
const struct V_297 * V_298 )
{
struct V_6 * V_6 = V_86 -> V_199 ;
return F_135 ( V_6 , NULL ,
F_160 ( V_298 -> V_158 ) , V_298 -> V_267 ,
V_298 -> V_269 , V_298 -> V_270 ,
V_139 ) ;
}
static int F_162 ( struct V_86 * V_86 ,
const struct V_299 * V_232 ,
struct V_15 * V_16 )
{
struct V_6 * V_6 = V_86 -> V_199 ;
T_1 V_1 = F_3 ( V_6 , V_232 -> V_7 , NULL ) ;
if ( ! F_7 ( V_6 ) )
return - V_300 ;
return F_117 ( V_6 , V_16 , V_232 -> V_224 , V_1 , 0 ) ;
}
static int F_163 ( struct V_86 * V_86 ,
const struct V_299 * V_232 )
{
struct V_6 * V_6 = V_86 -> V_199 ;
T_1 V_1 = F_3 ( V_6 , V_232 -> V_7 , NULL ) ;
int V_13 = V_139 ;
if ( ! F_7 ( V_6 ) )
return - V_300 ;
return F_117 ( V_6 , NULL , V_232 -> V_224 , V_1 , V_13 ) ;
}
static int F_164 ( const struct V_86 * V_86 ,
struct V_299 * V_232 ,
T_8 * V_294 )
{
const struct V_6 * V_6 = V_86 -> V_199 ;
struct V_127 * V_127 = V_6 -> V_127 ;
struct V_231 * V_129 ;
struct V_237 * V_238 ;
unsigned long V_131 ;
int V_239 ;
int V_90 = 0 ;
F_48 ( & V_127 -> V_235 , V_131 ) ;
F_119 (ofdpa->fdb_tbl, bkt, tmp, found, entry) {
if ( V_129 -> V_31 . V_6 != V_6 )
continue;
F_59 ( V_232 -> V_224 , V_129 -> V_31 . V_224 ) ;
V_232 -> V_301 = V_302 ;
V_232 -> V_7 = F_5 ( V_6 ,
V_129 -> V_31 . V_1 ) ;
V_90 = V_294 ( & V_232 -> V_296 ) ;
if ( V_90 )
break;
}
F_51 ( & V_127 -> V_235 , V_131 ) ;
return V_90 ;
}
static int F_165 ( struct V_6 * V_6 ,
struct V_188 * V_63 )
{
int V_90 ;
V_90 = F_131 ( V_6 , V_287 , 0 ) ;
if ( V_90 )
return V_90 ;
F_136 ( V_6 ,
V_6 -> V_184 -> V_262 ) ;
V_6 -> V_9 =
F_133 ( V_6 , V_63 -> V_262 ) ;
V_6 -> V_11 = V_63 ;
F_146 ( V_6 -> V_184 , V_63 , true ) ;
return F_130 ( V_6 , NULL , V_287 , 0 ) ;
}
static int F_166 ( struct V_6 * V_6 )
{
int V_90 ;
V_90 = F_131 ( V_6 , V_287 , 0 ) ;
if ( V_90 )
return V_90 ;
F_136 ( V_6 ,
V_6 -> V_11 -> V_262 ) ;
V_6 -> V_9 =
F_133 ( V_6 ,
V_6 -> V_184 -> V_262 ) ;
F_146 ( V_6 -> V_184 , V_6 -> V_11 ,
false ) ;
V_6 -> V_11 = NULL ;
V_90 = F_130 ( V_6 , NULL , V_287 , 0 ) ;
if ( V_90 )
return V_90 ;
if ( V_6 -> V_184 -> V_13 & V_303 )
V_90 = F_128 ( V_6 , 0 ) ;
return V_90 ;
}
static int F_167 ( struct V_6 * V_6 ,
struct V_188 * V_304 )
{
int V_90 ;
V_6 -> V_11 = V_304 ;
V_90 = F_129 ( V_6 , 0 ) ;
if ( V_90 )
return V_90 ;
V_90 = F_128 ( V_6 , 0 ) ;
return V_90 ;
}
static int F_168 ( struct V_86 * V_86 ,
struct V_188 * V_304 )
{
struct V_6 * V_6 = V_86 -> V_199 ;
int V_90 = 0 ;
if ( F_169 ( V_304 ) )
V_90 = F_165 ( V_6 , V_304 ) ;
else if ( F_170 ( V_304 ) )
V_90 = F_167 ( V_6 , V_304 ) ;
return V_90 ;
}
static int F_171 ( struct V_86 * V_86 ,
struct V_188 * V_304 )
{
struct V_6 * V_6 = V_86 -> V_199 ;
int V_90 = 0 ;
if ( F_7 ( V_6 ) )
V_90 = F_166 ( V_6 ) ;
else if ( F_8 ( V_6 ) )
V_90 = F_167 ( V_6 , NULL ) ;
return V_90 ;
}
static int F_172 ( struct V_86 * V_86 ,
struct V_189 * V_24 )
{
struct V_6 * V_6 = V_86 -> V_199 ;
int V_13 = ( V_24 -> V_192 & V_193 ? 0 : V_139 ) |
V_14 ;
T_7 V_176 = * ( T_7 * ) V_24 -> V_305 ;
return F_83 ( V_6 , NULL , V_13 , V_176 , V_24 -> V_194 ) ;
}
static int F_173 ( struct V_86 * V_86 ,
struct V_189 * V_24 )
{
struct V_6 * V_6 = V_86 -> V_199 ;
int V_13 = V_139 | V_14 ;
T_7 V_176 = * ( T_7 * ) V_24 -> V_305 ;
return F_83 ( V_6 , NULL , V_13 , V_176 , V_24 -> V_194 ) ;
}
static int F_174 ( struct V_86 * V_86 ,
const unsigned char * V_224 ,
T_1 V_1 )
{
struct V_6 * V_6 = V_86 -> V_199 ;
int V_13 = V_14 | V_221 ;
if ( V_6 -> V_205 != V_206 &&
V_6 -> V_205 != V_207 )
return 0 ;
return F_117 ( V_6 , NULL , V_224 , V_1 , V_13 ) ;
}
