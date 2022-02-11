static void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_2 , V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_4 )
{
F_4 ( L_1 , V_2 -> V_5 , V_4 ) ;
if ( V_2 -> V_6 == V_7 ) {
V_2 -> V_8 = V_4 ;
V_2 -> V_6 = V_9 ;
F_5 ( & V_2 -> V_10 ) ;
}
}
static void F_6 ( struct V_1 * V_2 , int V_11 )
{
F_4 ( L_2 , V_2 -> V_5 , V_11 ) ;
if ( V_2 -> V_6 == V_7 ) {
V_2 -> V_8 = V_11 ;
V_2 -> V_6 = V_12 ;
F_5 ( & V_2 -> V_10 ) ;
}
}
static struct V_13 * F_7 ( struct V_1 * V_2 , T_2 V_14 ,
T_1 V_3 )
{
struct V_15 * V_16 ;
struct V_17 * V_18 ;
struct V_13 * V_19 ;
F_8 ( V_2 ) ;
V_19 = V_2 -> V_20 ;
V_2 -> V_20 = NULL ;
F_9 ( V_2 ) ;
if ( ! V_19 )
return F_10 ( - V_21 ) ;
if ( V_19 -> V_22 < sizeof( * V_18 ) ) {
F_11 ( L_3 ) ;
goto V_23;
}
V_18 = ( void * ) V_19 -> V_24 ;
F_12 ( V_19 , V_25 ) ;
if ( V_3 ) {
if ( V_18 -> V_26 != V_3 )
goto V_23;
return V_19 ;
}
if ( V_18 -> V_26 != V_27 ) {
F_4 ( L_4 , V_18 -> V_26 ) ;
goto V_23;
}
if ( V_19 -> V_22 < sizeof( * V_16 ) ) {
F_11 ( L_5 ) ;
goto V_23;
}
V_16 = ( void * ) V_19 -> V_24 ;
F_12 ( V_19 , sizeof( * V_16 ) ) ;
if ( V_14 == F_13 ( V_16 -> V_14 ) )
return V_19 ;
F_4 ( L_6 , V_14 ,
F_13 ( V_16 -> V_14 ) ) ;
V_23:
F_14 ( V_19 ) ;
return F_10 ( - V_21 ) ;
}
struct V_13 * F_15 ( struct V_1 * V_2 , T_2 V_14 , T_3 V_28 ,
const void * V_29 , T_1 V_3 , T_3 V_30 )
{
F_16 ( V_31 , V_32 ) ;
struct V_33 V_34 ;
int V_11 = 0 ;
F_4 ( L_7 , V_2 -> V_5 ) ;
F_17 ( & V_34 , V_2 ) ;
F_18 ( & V_34 , V_14 , V_28 , V_29 , V_3 ) ;
V_2 -> V_6 = V_7 ;
V_11 = F_19 ( & V_34 , F_3 ) ;
if ( V_11 < 0 )
return F_10 ( V_11 ) ;
F_20 ( & V_2 -> V_10 , & V_31 ) ;
F_21 ( V_35 ) ;
F_22 ( V_30 ) ;
F_23 ( & V_2 -> V_10 , & V_31 ) ;
if ( F_24 ( V_32 ) )
return F_10 ( - V_36 ) ;
switch ( V_2 -> V_6 ) {
case V_9 :
V_11 = - F_25 ( V_2 -> V_8 ) ;
break;
case V_12 :
V_11 = - V_2 -> V_8 ;
break;
default:
V_11 = - V_37 ;
break;
}
V_2 -> V_6 = V_2 -> V_8 = 0 ;
F_4 ( L_8 , V_2 -> V_5 , V_11 ) ;
if ( V_11 < 0 )
return F_10 ( V_11 ) ;
return F_7 ( V_2 , V_14 , V_3 ) ;
}
struct V_13 * F_26 ( struct V_1 * V_2 , T_2 V_14 , T_3 V_28 ,
const void * V_29 , T_3 V_30 )
{
return F_15 ( V_2 , V_14 , V_28 , V_29 , 0 , V_30 ) ;
}
static int F_27 ( struct V_1 * V_2 ,
void (* F_28)( struct V_33 * V_34 ,
unsigned long V_38 ) ,
unsigned long V_38 , T_4 V_30 )
{
struct V_33 V_34 ;
F_16 ( V_31 , V_32 ) ;
int V_11 = 0 ;
F_4 ( L_9 , V_2 -> V_5 ) ;
F_17 ( & V_34 , V_2 ) ;
V_2 -> V_6 = V_7 ;
F_28 ( & V_34 , V_38 ) ;
V_11 = F_19 ( & V_34 , F_3 ) ;
if ( V_11 < 0 ) {
V_2 -> V_6 = 0 ;
if ( V_11 == - V_21 )
return 0 ;
return V_11 ;
}
F_20 ( & V_2 -> V_10 , & V_31 ) ;
F_21 ( V_35 ) ;
F_22 ( V_30 ) ;
F_23 ( & V_2 -> V_10 , & V_31 ) ;
if ( F_24 ( V_32 ) )
return - V_36 ;
switch ( V_2 -> V_6 ) {
case V_9 :
V_11 = - F_25 ( V_2 -> V_8 ) ;
break;
case V_12 :
V_11 = - V_2 -> V_8 ;
break;
default:
V_11 = - V_37 ;
break;
}
V_2 -> V_6 = V_2 -> V_8 = 0 ;
F_4 ( L_8 , V_2 -> V_5 , V_11 ) ;
return V_11 ;
}
static int F_29 ( struct V_1 * V_2 ,
void (* V_34)( struct V_33 * V_34 ,
unsigned long V_38 ) ,
unsigned long V_38 , T_4 V_30 )
{
int V_39 ;
if ( ! F_30 ( V_40 , & V_2 -> V_41 ) )
return - V_42 ;
F_31 ( V_2 ) ;
V_39 = F_27 ( V_2 , V_34 , V_38 , V_30 ) ;
F_32 ( V_2 ) ;
return V_39 ;
}
static void F_33 ( struct V_33 * V_34 , unsigned long V_38 )
{
F_4 ( L_10 , V_34 -> V_2 -> V_5 , V_38 ) ;
F_34 ( V_43 , & V_34 -> V_2 -> V_41 ) ;
F_35 ( V_34 , V_44 , 0 , NULL ) ;
}
static void F_36 ( struct V_33 * V_34 )
{
V_34 -> V_2 -> V_45 = V_46 ;
F_35 ( V_34 , V_47 , 0 , NULL ) ;
F_35 ( V_34 , V_48 , 0 , NULL ) ;
F_35 ( V_34 , V_49 , 0 , NULL ) ;
}
static void F_37 ( struct V_33 * V_34 )
{
V_34 -> V_2 -> V_45 = V_50 ;
F_35 ( V_34 , V_48 , 0 , NULL ) ;
F_35 ( V_34 , V_51 , 0 , NULL ) ;
F_35 ( V_34 , V_52 , 0 , NULL ) ;
}
static void F_38 ( struct V_33 * V_34 , unsigned long V_38 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
F_4 ( L_10 , V_2 -> V_5 , V_38 ) ;
if ( ! F_30 ( V_53 , & V_2 -> V_54 ) )
F_33 ( V_34 , 0 ) ;
switch ( V_2 -> V_55 ) {
case V_56 :
F_36 ( V_34 ) ;
break;
case V_57 :
F_37 ( V_34 ) ;
break;
default:
F_11 ( L_11 , V_2 -> V_55 ) ;
break;
}
}
static void F_39 ( struct V_33 * V_34 )
{
T_5 V_29 ;
T_6 V_58 ;
F_35 ( V_34 , V_59 , 0 , NULL ) ;
F_35 ( V_34 , V_60 , 0 , NULL ) ;
F_35 ( V_34 , V_61 , 0 , NULL ) ;
F_35 ( V_34 , V_62 , 0 , NULL ) ;
V_58 = V_63 ;
F_35 ( V_34 , V_64 , 1 , & V_58 ) ;
V_29 = F_40 ( 0x7d00 ) ;
F_35 ( V_34 , V_65 , 2 , & V_29 ) ;
if ( V_34 -> V_2 -> V_66 > V_67 ) {
F_35 ( V_34 , V_68 , 0 , NULL ) ;
F_35 ( V_34 , V_69 , 0 , NULL ) ;
}
}
static void F_41 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
F_35 ( V_34 , V_70 , 0 , NULL ) ;
F_35 ( V_34 , V_71 , 0 , NULL ) ;
F_35 ( V_34 , V_72 , 0 , NULL ) ;
F_35 ( V_34 , V_73 , 0 , NULL ) ;
F_35 ( V_34 , V_74 , 0 , NULL ) ;
if ( ! F_42 ( V_2 ) )
F_34 ( V_75 , & V_2 -> V_76 ) ;
}
static T_1 F_43 ( struct V_1 * V_2 )
{
if ( F_44 ( V_2 ) )
return 0x02 ;
if ( F_45 ( V_2 ) )
return 0x01 ;
if ( V_2 -> V_77 == 11 && V_2 -> V_78 == 0x00 &&
V_2 -> V_79 == 0x0757 )
return 0x01 ;
if ( V_2 -> V_77 == 15 ) {
if ( V_2 -> V_78 == 0x03 && V_2 -> V_79 == 0x6963 )
return 0x01 ;
if ( V_2 -> V_78 == 0x09 && V_2 -> V_79 == 0x6963 )
return 0x01 ;
if ( V_2 -> V_78 == 0x00 && V_2 -> V_79 == 0x6965 )
return 0x01 ;
}
if ( V_2 -> V_77 == 31 && V_2 -> V_78 == 0x2005 &&
V_2 -> V_79 == 0x1805 )
return 0x01 ;
return 0x00 ;
}
static void F_46 ( struct V_33 * V_34 )
{
T_1 V_80 ;
V_80 = F_43 ( V_34 -> V_2 ) ;
F_35 ( V_34 , V_81 , 1 , & V_80 ) ;
}
static void F_47 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
T_1 V_82 [ 8 ] = { 0xff , 0xff , 0xfb , 0xff , 0x00 , 0x00 , 0x00 , 0x00 } ;
if ( V_2 -> V_66 < V_83 )
return;
if ( F_42 ( V_2 ) ) {
V_82 [ 4 ] |= 0x01 ;
V_82 [ 4 ] |= 0x02 ;
V_82 [ 4 ] |= 0x04 ;
V_82 [ 5 ] |= 0x08 ;
V_82 [ 5 ] |= 0x10 ;
}
if ( F_45 ( V_2 ) )
V_82 [ 4 ] |= 0x02 ;
if ( F_48 ( V_2 ) )
V_82 [ 5 ] |= 0x20 ;
if ( F_49 ( V_2 ) )
V_82 [ 5 ] |= 0x80 ;
if ( F_44 ( V_2 ) )
V_82 [ 5 ] |= 0x40 ;
if ( F_50 ( V_2 ) )
V_82 [ 7 ] |= 0x01 ;
if ( F_51 ( V_2 ) )
V_82 [ 6 ] |= 0x80 ;
if ( F_52 ( V_2 ) ) {
V_82 [ 6 ] |= 0x01 ;
V_82 [ 6 ] |= 0x02 ;
V_82 [ 6 ] |= 0x04 ;
V_82 [ 6 ] |= 0x08 ;
V_82 [ 6 ] |= 0x10 ;
V_82 [ 6 ] |= 0x20 ;
V_82 [ 7 ] |= 0x04 ;
V_82 [ 7 ] |= 0x08 ;
V_82 [ 7 ] |= 0x10 ;
}
if ( F_53 ( V_2 ) )
V_82 [ 7 ] |= 0x20 ;
F_35 ( V_34 , V_84 , sizeof( V_82 ) , V_82 ) ;
if ( F_53 ( V_2 ) ) {
memset ( V_82 , 0 , sizeof( V_82 ) ) ;
V_82 [ 0 ] = 0x1f ;
F_35 ( V_34 , V_85 ,
sizeof( V_82 ) , V_82 ) ;
}
}
static void F_54 ( struct V_33 * V_34 , unsigned long V_38 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
if ( F_42 ( V_2 ) )
F_39 ( V_34 ) ;
if ( F_53 ( V_2 ) )
F_41 ( V_34 ) ;
F_47 ( V_34 ) ;
if ( V_2 -> V_66 > V_67 )
F_35 ( V_34 , V_86 , 0 , NULL ) ;
if ( F_52 ( V_2 ) ) {
if ( F_30 ( V_87 , & V_2 -> V_76 ) ) {
T_1 V_80 = 0x01 ;
F_35 ( V_34 , V_88 ,
sizeof( V_80 ) , & V_80 ) ;
} else {
struct V_89 V_90 ;
memset ( V_2 -> V_91 , 0 , sizeof( V_2 -> V_91 ) ) ;
memset ( & V_90 , 0 , sizeof( V_90 ) ) ;
F_35 ( V_34 , V_92 , sizeof( V_90 ) , & V_90 ) ;
}
}
if ( F_45 ( V_2 ) )
F_46 ( V_34 ) ;
if ( F_55 ( V_2 ) )
F_35 ( V_34 , V_93 , 0 , NULL ) ;
if ( F_56 ( V_2 ) ) {
struct V_94 V_90 ;
V_90 . V_95 = 0x01 ;
F_35 ( V_34 , V_96 ,
sizeof( V_90 ) , & V_90 ) ;
}
if ( F_30 ( V_97 , & V_2 -> V_76 ) ) {
T_1 V_98 = 1 ;
F_35 ( V_34 , V_99 , sizeof( V_98 ) ,
& V_98 ) ;
}
}
static void F_57 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_100 V_90 ;
T_2 V_101 = 0 ;
if ( F_58 ( V_2 ) )
V_101 |= V_102 ;
if ( F_59 ( V_2 ) )
V_101 |= V_103 ;
if ( F_60 ( V_2 ) )
V_101 |= V_104 ;
if ( F_61 ( V_2 ) )
V_101 |= V_105 ;
V_90 . V_106 = F_62 ( V_101 ) ;
F_35 ( V_34 , V_107 , sizeof( V_90 ) , & V_90 ) ;
}
static void F_63 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_108 V_90 ;
if ( ! F_42 ( V_2 ) )
return;
memset ( & V_90 , 0 , sizeof( V_90 ) ) ;
if ( F_30 ( V_75 , & V_2 -> V_76 ) ) {
V_90 . V_109 = 0x01 ;
V_90 . V_110 = F_64 ( V_2 ) ;
}
if ( V_90 . V_109 != F_65 ( V_2 ) )
F_35 ( V_34 , V_111 , sizeof( V_90 ) ,
& V_90 ) ;
}
static void F_66 ( struct V_33 * V_34 , unsigned long V_38 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
T_1 V_112 ;
if ( V_2 -> V_113 [ 6 ] & 0x80 ) {
struct V_114 V_90 ;
F_67 ( & V_90 . V_115 , V_116 ) ;
V_90 . V_117 = 0x01 ;
F_35 ( V_34 , V_118 ,
sizeof( V_90 ) , & V_90 ) ;
}
if ( V_2 -> V_113 [ 5 ] & 0x10 )
F_57 ( V_34 ) ;
if ( F_53 ( V_2 ) ) {
F_63 ( V_34 ) ;
F_68 ( V_34 ) ;
}
for ( V_112 = 2 ; V_112 < V_119 && V_112 <= V_2 -> V_120 ; V_112 ++ ) {
struct V_94 V_90 ;
V_90 . V_95 = V_112 ;
F_35 ( V_34 , V_96 ,
sizeof( V_90 ) , & V_90 ) ;
}
}
static int F_69 ( struct V_1 * V_2 )
{
int V_11 ;
V_11 = F_27 ( V_2 , F_38 , 0 , V_121 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_2 -> V_55 != V_56 )
return 0 ;
V_11 = F_27 ( V_2 , F_54 , 0 , V_121 ) ;
if ( V_11 < 0 )
return V_11 ;
return F_27 ( V_2 , F_66 , 0 , V_121 ) ;
}
static void F_70 ( struct V_33 * V_34 , unsigned long V_38 )
{
T_6 V_122 = V_38 ;
F_4 ( L_12 , V_34 -> V_2 -> V_5 , V_122 ) ;
F_35 ( V_34 , V_123 , 1 , & V_122 ) ;
}
static void F_71 ( struct V_33 * V_34 , unsigned long V_38 )
{
T_6 V_124 = V_38 ;
F_4 ( L_12 , V_34 -> V_2 -> V_5 , V_124 ) ;
F_35 ( V_34 , V_99 , 1 , & V_124 ) ;
}
static void F_72 ( struct V_33 * V_34 , unsigned long V_38 )
{
T_6 V_125 = V_38 ;
F_4 ( L_12 , V_34 -> V_2 -> V_5 , V_125 ) ;
F_35 ( V_34 , V_126 , 1 , & V_125 ) ;
}
static void F_73 ( struct V_33 * V_34 , unsigned long V_38 )
{
T_5 V_106 = F_62 ( V_38 ) ;
F_4 ( L_12 , V_34 -> V_2 -> V_5 , V_106 ) ;
F_35 ( V_34 , V_107 , 2 , & V_106 ) ;
}
struct V_1 * F_74 ( int V_127 )
{
struct V_1 * V_2 = NULL , * V_128 ;
F_4 ( L_13 , V_127 ) ;
if ( V_127 < 0 )
return NULL ;
F_75 ( & V_129 ) ;
F_76 (d, &hci_dev_list, list) {
if ( V_128 -> V_130 == V_127 ) {
V_2 = F_77 ( V_128 ) ;
break;
}
}
F_78 ( & V_129 ) ;
return V_2 ;
}
bool F_79 ( struct V_1 * V_2 )
{
struct V_131 * V_132 = & V_2 -> V_133 ;
switch ( V_132 -> V_134 ) {
case V_135 :
case V_136 :
return true ;
default:
return false ;
}
}
void F_80 ( struct V_1 * V_2 , int V_134 )
{
F_4 ( L_14 , V_2 -> V_5 , V_2 -> V_133 . V_134 , V_134 ) ;
if ( V_2 -> V_133 . V_134 == V_134 )
return;
switch ( V_134 ) {
case V_137 :
if ( V_2 -> V_133 . V_134 != V_138 )
F_81 ( V_2 , 0 ) ;
break;
case V_138 :
break;
case V_135 :
F_81 ( V_2 , 1 ) ;
break;
case V_136 :
break;
case V_139 :
break;
}
V_2 -> V_133 . V_134 = V_134 ;
}
static void F_82 ( struct V_1 * V_2 )
{
struct V_131 * V_140 = & V_2 -> V_133 ;
struct V_141 * V_112 , * V_142 ;
F_83 (p, n, &cache->all, all) {
F_84 ( & V_112 -> V_143 ) ;
F_85 ( V_112 ) ;
}
F_86 ( & V_140 -> V_144 ) ;
F_86 ( & V_140 -> V_145 ) ;
}
struct V_141 * F_87 ( struct V_1 * V_2 ,
T_7 * V_115 )
{
struct V_131 * V_140 = & V_2 -> V_133 ;
struct V_141 * V_146 ;
F_4 ( L_15 , V_140 , V_115 ) ;
F_76 (e, &cache->all, all) {
if ( ! F_88 ( & V_146 -> V_24 . V_115 , V_115 ) )
return V_146 ;
}
return NULL ;
}
struct V_141 * F_89 ( struct V_1 * V_2 ,
T_7 * V_115 )
{
struct V_131 * V_140 = & V_2 -> V_133 ;
struct V_141 * V_146 ;
F_4 ( L_15 , V_140 , V_115 ) ;
F_76 (e, &cache->unknown, list) {
if ( ! F_88 ( & V_146 -> V_24 . V_115 , V_115 ) )
return V_146 ;
}
return NULL ;
}
struct V_141 * F_90 ( struct V_1 * V_2 ,
T_7 * V_115 ,
int V_134 )
{
struct V_131 * V_140 = & V_2 -> V_133 ;
struct V_141 * V_146 ;
F_4 ( L_16 , V_140 , V_115 , V_134 ) ;
F_76 (e, &cache->resolve, list) {
if ( ! F_88 ( V_115 , V_116 ) && V_146 -> V_147 == V_134 )
return V_146 ;
if ( ! F_88 ( & V_146 -> V_24 . V_115 , V_115 ) )
return V_146 ;
}
return NULL ;
}
void F_91 ( struct V_1 * V_2 ,
struct V_141 * V_148 )
{
struct V_131 * V_140 = & V_2 -> V_133 ;
struct V_149 * V_150 = & V_140 -> V_145 ;
struct V_141 * V_112 ;
F_84 ( & V_148 -> V_151 ) ;
F_76 (p, &cache->resolve, list) {
if ( V_112 -> V_147 != V_152 &&
abs ( V_112 -> V_24 . V_153 ) >= abs ( V_148 -> V_24 . V_153 ) )
break;
V_150 = & V_112 -> V_151 ;
}
F_92 ( & V_148 -> V_151 , V_150 ) ;
}
bool F_93 ( struct V_1 * V_2 , struct V_154 * V_24 ,
bool V_155 , bool * V_156 )
{
struct V_131 * V_140 = & V_2 -> V_133 ;
struct V_141 * V_148 ;
F_4 ( L_15 , V_140 , & V_24 -> V_115 ) ;
F_94 ( V_2 , & V_24 -> V_115 ) ;
if ( V_156 )
* V_156 = V_24 -> V_157 ;
V_148 = F_87 ( V_2 , & V_24 -> V_115 ) ;
if ( V_148 ) {
if ( V_148 -> V_24 . V_157 && V_156 )
* V_156 = true ;
if ( V_148 -> V_147 == V_158 &&
V_24 -> V_153 != V_148 -> V_24 . V_153 ) {
V_148 -> V_24 . V_153 = V_24 -> V_153 ;
F_91 ( V_2 , V_148 ) ;
}
goto V_159;
}
V_148 = F_95 ( sizeof( struct V_141 ) , V_160 ) ;
if ( ! V_148 )
return false ;
F_92 ( & V_148 -> V_143 , & V_140 -> V_143 ) ;
if ( V_155 ) {
V_148 -> V_147 = V_161 ;
} else {
V_148 -> V_147 = V_162 ;
F_92 ( & V_148 -> V_151 , & V_140 -> V_144 ) ;
}
V_159:
if ( V_155 && V_148 -> V_147 != V_161 &&
V_148 -> V_147 != V_152 ) {
V_148 -> V_147 = V_161 ;
F_84 ( & V_148 -> V_151 ) ;
}
memcpy ( & V_148 -> V_24 , V_24 , sizeof( * V_24 ) ) ;
V_148 -> V_163 = V_164 ;
V_140 -> V_163 = V_164 ;
if ( V_148 -> V_147 == V_162 )
return false ;
return true ;
}
static int F_96 ( struct V_1 * V_2 , int V_165 , T_6 * V_166 )
{
struct V_131 * V_140 = & V_2 -> V_133 ;
struct V_167 * V_168 = (struct V_167 * ) V_166 ;
struct V_141 * V_146 ;
int V_169 = 0 ;
F_76 (e, &cache->all, all) {
struct V_154 * V_24 = & V_146 -> V_24 ;
if ( V_169 >= V_165 )
break;
F_67 ( & V_168 -> V_115 , & V_24 -> V_115 ) ;
V_168 -> V_170 = V_24 -> V_170 ;
V_168 -> V_171 = V_24 -> V_171 ;
V_168 -> V_172 = V_24 -> V_172 ;
memcpy ( V_168 -> V_173 , V_24 -> V_173 , 3 ) ;
V_168 -> V_174 = V_24 -> V_174 ;
V_168 ++ ;
V_169 ++ ;
}
F_4 ( L_17 , V_140 , V_169 ) ;
return V_169 ;
}
static void F_97 ( struct V_33 * V_34 , unsigned long V_38 )
{
struct V_175 * V_176 = (struct V_175 * ) V_38 ;
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_177 V_90 ;
F_4 ( L_7 , V_2 -> V_5 ) ;
if ( F_30 ( V_178 , & V_2 -> V_41 ) )
return;
memcpy ( & V_90 . V_179 , & V_176 -> V_179 , 3 ) ;
V_90 . V_180 = V_176 -> V_180 ;
V_90 . V_181 = V_176 -> V_181 ;
F_35 ( V_34 , V_182 , sizeof( V_90 ) , & V_90 ) ;
}
static int F_98 ( void * V_183 )
{
F_99 () ;
return F_24 ( V_32 ) ;
}
int F_100 ( void T_8 * V_184 )
{
T_6 T_8 * V_185 = V_184 ;
struct V_175 V_176 ;
struct V_1 * V_2 ;
int V_11 = 0 , V_186 = 0 , V_187 ;
long V_188 ;
T_6 * V_166 ;
if ( F_101 ( & V_176 , V_185 , sizeof( V_176 ) ) )
return - V_189 ;
V_2 = F_74 ( V_176 . V_190 ) ;
if ( ! V_2 )
return - V_191 ;
F_8 ( V_2 ) ;
if ( F_102 ( V_2 ) > V_192 ||
F_103 ( V_2 ) || V_176 . V_41 & V_193 ) {
F_82 ( V_2 ) ;
V_186 = 1 ;
}
F_9 ( V_2 ) ;
V_188 = V_176 . V_180 * F_104 ( 2000 ) ;
if ( V_186 ) {
V_11 = F_29 ( V_2 , F_97 , ( unsigned long ) & V_176 ,
V_188 ) ;
if ( V_11 < 0 )
goto V_194;
if ( F_105 ( & V_2 -> V_41 , V_178 , F_98 ,
V_35 ) )
return - V_36 ;
}
V_187 = ( V_176 . V_181 == 0 ) ? 255 : V_176 . V_181 ;
V_166 = F_106 ( sizeof( struct V_167 ) * V_187 , V_195 ) ;
if ( ! V_166 ) {
V_11 = - V_196 ;
goto V_194;
}
F_8 ( V_2 ) ;
V_176 . V_181 = F_96 ( V_2 , V_187 , V_166 ) ;
F_9 ( V_2 ) ;
F_4 ( L_18 , V_176 . V_181 ) ;
if ( ! F_107 ( V_185 , & V_176 , sizeof( V_176 ) ) ) {
V_185 += sizeof( V_176 ) ;
if ( F_107 ( V_185 , V_166 , sizeof( struct V_167 ) *
V_176 . V_181 ) )
V_11 = - V_189 ;
} else
V_11 = - V_189 ;
F_85 ( V_166 ) ;
V_194:
F_108 ( V_2 ) ;
return V_11 ;
}
static T_1 F_109 ( struct V_1 * V_2 , T_1 * V_185 )
{
T_1 V_197 = 0 , V_41 = 0 ;
T_9 V_198 ;
if ( F_30 ( V_199 , & V_2 -> V_76 ) )
V_41 |= V_200 ;
if ( ! F_42 ( V_2 ) )
V_41 |= V_201 ;
if ( F_64 ( V_2 ) )
V_41 |= V_202 ;
if ( F_110 ( V_2 ) )
V_41 |= V_203 ;
if ( V_41 ) {
F_4 ( L_19 , V_41 ) ;
V_185 [ 0 ] = 2 ;
V_185 [ 1 ] = V_204 ;
V_185 [ 2 ] = V_41 ;
V_197 += 3 ;
V_185 += 3 ;
}
if ( V_2 -> V_205 != V_206 ) {
V_185 [ 0 ] = 2 ;
V_185 [ 1 ] = V_207 ;
V_185 [ 2 ] = ( T_1 ) V_2 -> V_205 ;
V_197 += 3 ;
V_185 += 3 ;
}
V_198 = strlen ( V_2 -> V_208 ) ;
if ( V_198 > 0 ) {
T_9 V_209 = V_210 - V_197 - 2 ;
if ( V_198 > V_209 ) {
V_198 = V_209 ;
V_185 [ 1 ] = V_211 ;
} else
V_185 [ 1 ] = V_212 ;
V_185 [ 0 ] = V_198 + 1 ;
memcpy ( V_185 + 2 , V_2 -> V_208 , V_198 ) ;
V_197 += ( V_198 + 2 ) ;
V_185 += ( V_198 + 2 ) ;
}
return V_197 ;
}
void F_68 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_213 V_90 ;
T_1 V_22 ;
if ( ! F_53 ( V_2 ) )
return;
memset ( & V_90 , 0 , sizeof( V_90 ) ) ;
V_22 = F_109 ( V_2 , V_90 . V_24 ) ;
if ( V_2 -> V_214 == V_22 &&
memcmp ( V_90 . V_24 , V_2 -> V_215 , V_22 ) == 0 )
return;
memcpy ( V_2 -> V_215 , V_90 . V_24 , sizeof( V_90 . V_24 ) ) ;
V_2 -> V_214 = V_22 ;
V_90 . V_180 = V_22 ;
F_35 ( V_34 , V_216 , sizeof( V_90 ) , & V_90 ) ;
}
int F_111 ( T_10 V_217 )
{
struct V_1 * V_2 ;
int V_39 = 0 ;
V_2 = F_74 ( V_217 ) ;
if ( ! V_2 )
return - V_191 ;
F_4 ( L_20 , V_2 -> V_5 , V_2 ) ;
F_31 ( V_2 ) ;
if ( F_30 ( V_218 , & V_2 -> V_76 ) ) {
V_39 = - V_191 ;
goto V_194;
}
if ( V_2 -> V_219 && F_112 ( V_2 -> V_219 ) ) {
V_39 = - V_220 ;
goto V_194;
}
if ( F_30 ( V_40 , & V_2 -> V_41 ) ) {
V_39 = - V_221 ;
goto V_194;
}
if ( V_2 -> V_222 ( V_2 ) ) {
V_39 = - V_223 ;
goto V_194;
}
F_113 ( & V_2 -> V_224 , 1 ) ;
F_34 ( V_225 , & V_2 -> V_41 ) ;
if ( V_2 -> V_226 && F_30 ( V_227 , & V_2 -> V_76 ) )
V_39 = V_2 -> V_226 ( V_2 ) ;
if ( ! V_39 ) {
if ( V_2 -> V_55 != V_56 && ! V_228 )
F_34 ( V_229 , & V_2 -> V_41 ) ;
if ( F_30 ( V_230 , & V_2 -> V_54 ) )
F_34 ( V_229 , & V_2 -> V_41 ) ;
if ( ! F_30 ( V_229 , & V_2 -> V_41 ) )
V_39 = F_69 ( V_2 ) ;
}
F_114 ( V_225 , & V_2 -> V_41 ) ;
if ( ! V_39 ) {
F_77 ( V_2 ) ;
F_34 ( V_40 , & V_2 -> V_41 ) ;
F_1 ( V_2 , V_231 ) ;
if ( ! F_30 ( V_227 , & V_2 -> V_76 ) &&
F_115 ( V_2 ) ) {
F_8 ( V_2 ) ;
F_116 ( V_2 , 1 ) ;
F_9 ( V_2 ) ;
}
} else {
F_117 ( & V_2 -> V_232 ) ;
F_117 ( & V_2 -> V_233 ) ;
F_117 ( & V_2 -> V_234 ) ;
F_118 ( & V_2 -> V_235 ) ;
F_118 ( & V_2 -> V_236 ) ;
if ( V_2 -> V_237 )
V_2 -> V_237 ( V_2 ) ;
if ( V_2 -> V_238 ) {
F_14 ( V_2 -> V_238 ) ;
V_2 -> V_238 = NULL ;
}
V_2 -> V_239 ( V_2 ) ;
V_2 -> V_41 = 0 ;
}
V_194:
F_32 ( V_2 ) ;
F_108 ( V_2 ) ;
return V_39 ;
}
static int F_119 ( struct V_1 * V_2 )
{
F_4 ( L_20 , V_2 -> V_5 , V_2 ) ;
F_120 ( & V_2 -> V_240 ) ;
F_121 ( & V_2 -> V_241 ) ;
F_6 ( V_2 , V_191 ) ;
F_31 ( V_2 ) ;
if ( ! F_122 ( V_40 , & V_2 -> V_41 ) ) {
F_123 ( & V_2 -> V_242 ) ;
F_32 ( V_2 ) ;
return 0 ;
}
F_117 ( & V_2 -> V_232 ) ;
F_117 ( & V_2 -> V_234 ) ;
if ( V_2 -> V_243 > 0 ) {
F_121 ( & V_2 -> V_244 ) ;
V_2 -> V_243 = 0 ;
F_114 ( V_245 , & V_2 -> V_76 ) ;
}
if ( F_122 ( V_246 , & V_2 -> V_76 ) )
F_121 ( & V_2 -> V_247 ) ;
F_124 ( & V_2 -> V_248 ) ;
F_8 ( V_2 ) ;
F_82 ( V_2 ) ;
F_125 ( V_2 ) ;
F_9 ( V_2 ) ;
F_1 ( V_2 , V_249 ) ;
if ( V_2 -> V_237 )
V_2 -> V_237 ( V_2 ) ;
F_118 ( & V_2 -> V_235 ) ;
F_113 ( & V_2 -> V_224 , 1 ) ;
if ( ! F_30 ( V_229 , & V_2 -> V_41 ) &&
F_30 ( V_53 , & V_2 -> V_54 ) ) {
F_34 ( V_225 , & V_2 -> V_41 ) ;
F_27 ( V_2 , F_33 , 0 , V_250 ) ;
F_114 ( V_225 , & V_2 -> V_41 ) ;
}
F_117 ( & V_2 -> V_233 ) ;
F_118 ( & V_2 -> V_236 ) ;
F_118 ( & V_2 -> V_235 ) ;
F_118 ( & V_2 -> V_251 ) ;
if ( V_2 -> V_238 ) {
F_123 ( & V_2 -> V_242 ) ;
F_14 ( V_2 -> V_238 ) ;
V_2 -> V_238 = NULL ;
}
F_14 ( V_2 -> V_20 ) ;
V_2 -> V_20 = NULL ;
V_2 -> V_239 ( V_2 ) ;
V_2 -> V_41 = 0 ;
V_2 -> V_76 &= ~ V_252 ;
if ( ! F_122 ( V_253 , & V_2 -> V_76 ) &&
F_115 ( V_2 ) ) {
F_8 ( V_2 ) ;
F_116 ( V_2 , 0 ) ;
F_9 ( V_2 ) ;
}
V_2 -> V_254 = 0 ;
memset ( V_2 -> V_91 , 0 , sizeof( V_2 -> V_91 ) ) ;
memset ( V_2 -> V_173 , 0 , sizeof( V_2 -> V_173 ) ) ;
F_32 ( V_2 ) ;
F_108 ( V_2 ) ;
return 0 ;
}
int F_126 ( T_10 V_217 )
{
struct V_1 * V_2 ;
int V_11 ;
V_2 = F_74 ( V_217 ) ;
if ( ! V_2 )
return - V_191 ;
if ( F_122 ( V_253 , & V_2 -> V_76 ) )
F_121 ( & V_2 -> V_241 ) ;
V_11 = F_119 ( V_2 ) ;
F_108 ( V_2 ) ;
return V_11 ;
}
int F_127 ( T_10 V_217 )
{
struct V_1 * V_2 ;
int V_39 = 0 ;
V_2 = F_74 ( V_217 ) ;
if ( ! V_2 )
return - V_191 ;
F_31 ( V_2 ) ;
if ( ! F_30 ( V_40 , & V_2 -> V_41 ) )
goto V_194;
F_118 ( & V_2 -> V_236 ) ;
F_118 ( & V_2 -> V_235 ) ;
F_8 ( V_2 ) ;
F_82 ( V_2 ) ;
F_125 ( V_2 ) ;
F_9 ( V_2 ) ;
if ( V_2 -> V_237 )
V_2 -> V_237 ( V_2 ) ;
F_113 ( & V_2 -> V_224 , 1 ) ;
V_2 -> V_255 = 0 ; V_2 -> V_256 = 0 ; V_2 -> V_257 = 0 ;
if ( ! F_30 ( V_229 , & V_2 -> V_41 ) )
V_39 = F_27 ( V_2 , F_33 , 0 , V_121 ) ;
V_194:
F_32 ( V_2 ) ;
F_108 ( V_2 ) ;
return V_39 ;
}
int F_128 ( T_10 V_217 )
{
struct V_1 * V_2 ;
int V_39 = 0 ;
V_2 = F_74 ( V_217 ) ;
if ( ! V_2 )
return - V_191 ;
memset ( & V_2 -> V_258 , 0 , sizeof( struct V_259 ) ) ;
F_108 ( V_2 ) ;
return V_39 ;
}
int F_129 ( unsigned int V_260 , void T_8 * V_184 )
{
struct V_1 * V_2 ;
struct V_261 V_262 ;
int V_11 = 0 ;
if ( F_101 ( & V_262 , V_184 , sizeof( V_262 ) ) )
return - V_189 ;
V_2 = F_74 ( V_262 . V_190 ) ;
if ( ! V_2 )
return - V_191 ;
switch ( V_260 ) {
case V_263 :
V_11 = F_29 ( V_2 , F_71 , V_262 . V_264 ,
V_121 ) ;
break;
case V_265 :
if ( ! F_130 ( V_2 ) ) {
V_11 = - V_266 ;
break;
}
if ( ! F_30 ( V_267 , & V_2 -> V_41 ) ) {
V_11 = F_29 ( V_2 , F_71 , V_262 . V_264 ,
V_121 ) ;
if ( V_11 )
break;
}
V_11 = F_29 ( V_2 , F_72 , V_262 . V_264 ,
V_121 ) ;
break;
case V_268 :
V_11 = F_29 ( V_2 , F_70 , V_262 . V_264 ,
V_121 ) ;
break;
case V_269 :
V_11 = F_29 ( V_2 , F_73 , V_262 . V_264 ,
V_121 ) ;
break;
case V_270 :
V_2 -> V_271 = ( ( T_10 ) V_262 . V_264 ) &
( V_272 | V_273 ) ;
break;
case V_274 :
V_2 -> V_275 = ( T_10 ) V_262 . V_264 ;
break;
case V_276 :
V_2 -> V_277 = * ( ( T_10 * ) & V_262 . V_264 + 1 ) ;
V_2 -> V_278 = * ( ( T_10 * ) & V_262 . V_264 + 0 ) ;
break;
case V_279 :
V_2 -> V_280 = * ( ( T_10 * ) & V_262 . V_264 + 1 ) ;
V_2 -> V_281 = * ( ( T_10 * ) & V_262 . V_264 + 0 ) ;
break;
default:
V_11 = - V_282 ;
break;
}
F_108 ( V_2 ) ;
return V_11 ;
}
int F_131 ( void T_8 * V_184 )
{
struct V_1 * V_2 ;
struct V_283 * V_284 ;
struct V_261 * V_262 ;
int V_142 = 0 , V_285 , V_11 ;
T_10 V_286 ;
if ( F_132 ( V_286 , ( T_10 T_8 * ) V_184 ) )
return - V_189 ;
if ( ! V_286 || V_286 > ( V_287 * 2 ) / sizeof( * V_262 ) )
return - V_282 ;
V_285 = sizeof( * V_284 ) + V_286 * sizeof( * V_262 ) ;
V_284 = F_95 ( V_285 , V_195 ) ;
if ( ! V_284 )
return - V_196 ;
V_262 = V_284 -> V_288 ;
F_75 ( & V_129 ) ;
F_76 (hdev, &hci_dev_list, list) {
if ( F_122 ( V_253 , & V_2 -> V_76 ) )
F_121 ( & V_2 -> V_241 ) ;
if ( ! F_30 ( V_289 , & V_2 -> V_76 ) )
F_34 ( V_290 , & V_2 -> V_76 ) ;
( V_262 + V_142 ) -> V_190 = V_2 -> V_130 ;
( V_262 + V_142 ) -> V_264 = V_2 -> V_41 ;
if ( ++ V_142 >= V_286 )
break;
}
F_78 ( & V_129 ) ;
V_284 -> V_286 = V_142 ;
V_285 = sizeof( * V_284 ) + V_142 * sizeof( * V_262 ) ;
V_11 = F_107 ( V_184 , V_284 , V_285 ) ;
F_85 ( V_284 ) ;
return V_11 ? - V_189 : 0 ;
}
int F_133 ( void T_8 * V_184 )
{
struct V_1 * V_2 ;
struct V_291 V_292 ;
int V_11 = 0 ;
if ( F_101 ( & V_292 , V_184 , sizeof( V_292 ) ) )
return - V_189 ;
V_2 = F_74 ( V_292 . V_190 ) ;
if ( ! V_2 )
return - V_191 ;
if ( F_122 ( V_253 , & V_2 -> V_76 ) )
F_124 ( & V_2 -> V_241 ) ;
if ( ! F_30 ( V_289 , & V_2 -> V_76 ) )
F_34 ( V_290 , & V_2 -> V_76 ) ;
strcpy ( V_292 . V_5 , V_2 -> V_5 ) ;
V_292 . V_115 = V_2 -> V_115 ;
V_292 . type = ( V_2 -> V_293 & 0x0f ) | ( V_2 -> V_55 << 4 ) ;
V_292 . V_41 = V_2 -> V_41 ;
V_292 . V_275 = V_2 -> V_275 ;
if ( F_42 ( V_2 ) ) {
V_292 . V_277 = V_2 -> V_277 ;
V_292 . V_278 = V_2 -> V_278 ;
V_292 . V_280 = V_2 -> V_280 ;
V_292 . V_281 = V_2 -> V_281 ;
} else {
V_292 . V_277 = V_2 -> V_294 ;
V_292 . V_278 = V_2 -> V_295 ;
V_292 . V_280 = 0 ;
V_292 . V_281 = 0 ;
}
V_292 . V_101 = V_2 -> V_101 ;
V_292 . V_271 = V_2 -> V_271 ;
memcpy ( & V_292 . V_258 , & V_2 -> V_258 , sizeof( V_292 . V_258 ) ) ;
memcpy ( & V_292 . V_296 , & V_2 -> V_296 , sizeof( V_292 . V_296 ) ) ;
if ( F_107 ( V_184 , & V_292 , sizeof( V_292 ) ) )
V_11 = - V_189 ;
F_108 ( V_2 ) ;
return V_11 ;
}
static int F_134 ( void * V_24 , bool V_297 )
{
struct V_1 * V_2 = V_24 ;
F_4 ( L_21 , V_2 , V_2 -> V_5 , V_297 ) ;
if ( ! V_297 )
return 0 ;
F_119 ( V_2 ) ;
return 0 ;
}
static void F_135 ( struct V_298 * V_299 )
{
struct V_1 * V_2 = F_136 ( V_299 , struct V_1 , V_300 ) ;
int V_11 ;
F_4 ( L_7 , V_2 -> V_5 ) ;
V_11 = F_111 ( V_2 -> V_130 ) ;
if ( V_11 < 0 ) {
F_137 ( V_2 , V_11 ) ;
return;
}
if ( F_30 ( V_253 , & V_2 -> V_76 ) )
F_138 ( V_2 -> V_301 , & V_2 -> V_241 ,
V_302 ) ;
if ( F_122 ( V_227 , & V_2 -> V_76 ) )
F_139 ( V_2 ) ;
}
static void F_140 ( struct V_298 * V_299 )
{
struct V_1 * V_2 = F_136 ( V_299 , struct V_1 ,
V_241 . V_299 ) ;
F_4 ( L_7 , V_2 -> V_5 ) ;
F_119 ( V_2 ) ;
}
static void F_141 ( struct V_298 * V_299 )
{
struct V_1 * V_2 ;
T_1 V_122 = V_303 ;
V_2 = F_136 ( V_299 , struct V_1 , V_244 . V_299 ) ;
F_4 ( L_7 , V_2 -> V_5 ) ;
F_8 ( V_2 ) ;
F_142 ( V_2 , V_123 , sizeof( V_122 ) , & V_122 ) ;
V_2 -> V_243 = 0 ;
F_9 ( V_2 ) ;
}
int F_143 ( struct V_1 * V_2 )
{
struct V_304 * V_305 , * V_306 ;
F_83 (uuid, tmp, &hdev->uuids, list) {
F_84 ( & V_305 -> V_151 ) ;
F_85 ( V_305 ) ;
}
return 0 ;
}
int F_144 ( struct V_1 * V_2 )
{
struct V_149 * V_112 , * V_142 ;
F_145 (p, n, &hdev->link_keys) {
struct V_307 * V_308 ;
V_308 = F_146 ( V_112 , struct V_307 , V_151 ) ;
F_84 ( V_112 ) ;
F_85 ( V_308 ) ;
}
return 0 ;
}
int F_147 ( struct V_1 * V_2 )
{
struct V_309 * V_310 , * V_306 ;
F_83 (k, tmp, &hdev->long_term_keys, list) {
F_84 ( & V_310 -> V_151 ) ;
F_85 ( V_310 ) ;
}
return 0 ;
}
struct V_307 * F_148 ( struct V_1 * V_2 , T_7 * V_115 )
{
struct V_307 * V_310 ;
F_76 (k, &hdev->link_keys, list)
if ( F_88 ( V_115 , & V_310 -> V_115 ) == 0 )
return V_310 ;
return NULL ;
}
static bool F_149 ( struct V_1 * V_2 , struct V_311 * V_312 ,
T_1 V_313 , T_1 V_314 )
{
if ( V_313 < 0x03 )
return true ;
if ( V_313 == V_315 )
return false ;
if ( V_313 == V_316 && V_314 == 0xff )
return false ;
if ( ! V_312 )
return true ;
if ( V_312 -> V_317 > 0x01 && V_312 -> V_318 > 0x01 )
return true ;
if ( V_312 -> V_317 == 0x02 || V_312 -> V_317 == 0x03 )
return true ;
if ( V_312 -> V_318 == 0x02 || V_312 -> V_318 == 0x03 )
return true ;
return false ;
}
struct V_309 * F_150 ( struct V_1 * V_2 , T_5 V_319 , T_1 rand [ 8 ] )
{
struct V_309 * V_310 ;
F_76 (k, &hdev->long_term_keys, list) {
if ( V_310 -> V_319 != V_319 ||
memcmp ( rand , V_310 -> rand , sizeof( V_310 -> rand ) ) )
continue;
return V_310 ;
}
return NULL ;
}
struct V_309 * F_151 ( struct V_1 * V_2 , T_7 * V_115 ,
T_1 V_320 )
{
struct V_309 * V_310 ;
F_76 (k, &hdev->long_term_keys, list)
if ( V_320 == V_310 -> V_321 &&
F_88 ( V_115 , & V_310 -> V_115 ) == 0 )
return V_310 ;
return NULL ;
}
int F_152 ( struct V_1 * V_2 , struct V_311 * V_312 , int V_322 ,
T_7 * V_115 , T_1 * V_323 , T_1 type , T_1 V_324 )
{
struct V_307 * V_308 , * V_325 ;
T_1 V_314 ;
bool V_326 ;
V_325 = F_148 ( V_2 , V_115 ) ;
if ( V_325 ) {
V_314 = V_325 -> type ;
V_308 = V_325 ;
} else {
V_314 = V_312 ? V_312 -> V_313 : 0xff ;
V_308 = F_95 ( sizeof( * V_308 ) , V_160 ) ;
if ( ! V_308 )
return - V_196 ;
F_92 ( & V_308 -> V_151 , & V_2 -> V_327 ) ;
}
F_4 ( L_22 , V_2 -> V_5 , V_115 , type ) ;
if ( type == V_316 &&
( ! V_312 || V_312 -> V_318 == 0xff ) && V_314 == 0xff ) {
type = V_328 ;
if ( V_312 )
V_312 -> V_313 = type ;
}
F_67 ( & V_308 -> V_115 , V_115 ) ;
memcpy ( V_308 -> V_323 , V_323 , V_329 ) ;
V_308 -> V_324 = V_324 ;
if ( type == V_316 )
V_308 -> type = V_314 ;
else
V_308 -> type = type ;
if ( ! V_322 )
return 0 ;
V_326 = F_149 ( V_2 , V_312 , type , V_314 ) ;
F_153 ( V_2 , V_308 , V_326 ) ;
if ( V_312 )
V_312 -> V_330 = ! V_326 ;
return 0 ;
}
int F_154 ( struct V_1 * V_2 , T_7 * V_115 , T_1 V_320 , T_1 type ,
int V_322 , T_1 V_331 , T_1 V_332 [ 16 ] , T_1 V_333 , T_5
V_319 , T_1 rand [ 8 ] )
{
struct V_309 * V_308 , * V_325 ;
if ( ! ( type & V_334 ) && ! ( type & V_335 ) )
return 0 ;
V_325 = F_151 ( V_2 , V_115 , V_320 ) ;
if ( V_325 )
V_308 = V_325 ;
else {
V_308 = F_95 ( sizeof( * V_308 ) , V_160 ) ;
if ( ! V_308 )
return - V_196 ;
F_92 ( & V_308 -> V_151 , & V_2 -> V_336 ) ;
}
F_67 ( & V_308 -> V_115 , V_115 ) ;
V_308 -> V_321 = V_320 ;
memcpy ( V_308 -> V_323 , V_332 , sizeof( V_308 -> V_323 ) ) ;
V_308 -> V_331 = V_331 ;
V_308 -> V_319 = V_319 ;
V_308 -> V_333 = V_333 ;
V_308 -> type = type ;
memcpy ( V_308 -> rand , rand , sizeof( V_308 -> rand ) ) ;
if ( ! V_322 )
return 0 ;
if ( type & V_335 )
F_155 ( V_2 , V_308 , 1 ) ;
return 0 ;
}
int F_156 ( struct V_1 * V_2 , T_7 * V_115 )
{
struct V_307 * V_308 ;
V_308 = F_148 ( V_2 , V_115 ) ;
if ( ! V_308 )
return - V_337 ;
F_4 ( L_23 , V_2 -> V_5 , V_115 ) ;
F_84 ( & V_308 -> V_151 ) ;
F_85 ( V_308 ) ;
return 0 ;
}
int F_157 ( struct V_1 * V_2 , T_7 * V_115 )
{
struct V_309 * V_310 , * V_306 ;
F_83 (k, tmp, &hdev->long_term_keys, list) {
if ( F_88 ( V_115 , & V_310 -> V_115 ) )
continue;
F_4 ( L_23 , V_2 -> V_5 , V_115 ) ;
F_84 ( & V_310 -> V_151 ) ;
F_85 ( V_310 ) ;
}
return 0 ;
}
static void F_158 ( unsigned long V_184 )
{
struct V_1 * V_2 = ( void * ) V_184 ;
if ( V_2 -> V_238 ) {
struct V_338 * V_339 = ( void * ) V_2 -> V_238 -> V_24 ;
T_2 V_14 = F_13 ( V_339 -> V_14 ) ;
F_11 ( L_24 , V_2 -> V_5 , V_14 ) ;
} else {
F_11 ( L_25 , V_2 -> V_5 ) ;
}
F_113 ( & V_2 -> V_224 , 1 ) ;
F_159 ( V_2 -> V_340 , & V_2 -> V_233 ) ;
}
struct V_341 * F_160 ( struct V_1 * V_2 ,
T_7 * V_115 )
{
struct V_341 * V_24 ;
F_76 (data, &hdev->remote_oob_data, list)
if ( F_88 ( V_115 , & V_24 -> V_115 ) == 0 )
return V_24 ;
return NULL ;
}
int F_94 ( struct V_1 * V_2 , T_7 * V_115 )
{
struct V_341 * V_24 ;
V_24 = F_160 ( V_2 , V_115 ) ;
if ( ! V_24 )
return - V_337 ;
F_4 ( L_23 , V_2 -> V_5 , V_115 ) ;
F_84 ( & V_24 -> V_151 ) ;
F_85 ( V_24 ) ;
return 0 ;
}
int F_161 ( struct V_1 * V_2 )
{
struct V_341 * V_24 , * V_142 ;
F_83 (data, n, &hdev->remote_oob_data, list) {
F_84 ( & V_24 -> V_151 ) ;
F_85 ( V_24 ) ;
}
return 0 ;
}
int F_162 ( struct V_1 * V_2 , T_7 * V_115 , T_1 * V_342 ,
T_1 * V_343 )
{
struct V_341 * V_24 ;
V_24 = F_160 ( V_2 , V_115 ) ;
if ( ! V_24 ) {
V_24 = F_106 ( sizeof( * V_24 ) , V_160 ) ;
if ( ! V_24 )
return - V_196 ;
F_67 ( & V_24 -> V_115 , V_115 ) ;
F_92 ( & V_24 -> V_151 , & V_2 -> V_344 ) ;
}
memcpy ( V_24 -> V_342 , V_342 , sizeof( V_24 -> V_342 ) ) ;
memcpy ( V_24 -> V_343 , V_343 , sizeof( V_24 -> V_343 ) ) ;
F_4 ( L_26 , V_2 -> V_5 , V_115 ) ;
return 0 ;
}
struct V_345 * F_163 ( struct V_1 * V_2 , T_7 * V_115 )
{
struct V_345 * V_346 ;
F_76 (b, &hdev->blacklist, list)
if ( F_88 ( V_115 , & V_346 -> V_115 ) == 0 )
return V_346 ;
return NULL ;
}
int F_164 ( struct V_1 * V_2 )
{
struct V_149 * V_112 , * V_142 ;
F_145 (p, n, &hdev->blacklist) {
struct V_345 * V_346 ;
V_346 = F_146 ( V_112 , struct V_345 , V_151 ) ;
F_84 ( V_112 ) ;
F_85 ( V_346 ) ;
}
return 0 ;
}
int F_165 ( struct V_1 * V_2 , T_7 * V_115 , T_1 type )
{
struct V_345 * V_347 ;
if ( F_88 ( V_115 , V_116 ) == 0 )
return - V_348 ;
if ( F_163 ( V_2 , V_115 ) )
return - V_349 ;
V_347 = F_95 ( sizeof( struct V_345 ) , V_195 ) ;
if ( ! V_347 )
return - V_196 ;
F_67 ( & V_347 -> V_115 , V_115 ) ;
F_92 ( & V_347 -> V_151 , & V_2 -> V_350 ) ;
return F_166 ( V_2 , V_115 , type ) ;
}
int F_167 ( struct V_1 * V_2 , T_7 * V_115 , T_1 type )
{
struct V_345 * V_347 ;
if ( F_88 ( V_115 , V_116 ) == 0 )
return F_164 ( V_2 ) ;
V_347 = F_163 ( V_2 , V_115 ) ;
if ( ! V_347 )
return - V_337 ;
F_84 ( & V_347 -> V_151 ) ;
F_85 ( V_347 ) ;
return F_168 ( V_2 , V_115 , type ) ;
}
static void F_169 ( struct V_33 * V_34 , unsigned long V_38 )
{
struct V_351 * V_29 = (struct V_351 * ) V_38 ;
struct V_352 V_90 ;
memset ( & V_90 , 0 , sizeof( V_90 ) ) ;
V_90 . type = V_29 -> type ;
V_90 . V_353 = F_62 ( V_29 -> V_353 ) ;
V_90 . V_354 = F_62 ( V_29 -> V_354 ) ;
F_35 ( V_34 , V_355 , sizeof( V_90 ) , & V_90 ) ;
}
static void F_170 ( struct V_33 * V_34 , unsigned long V_38 )
{
struct V_356 V_90 ;
memset ( & V_90 , 0 , sizeof( V_90 ) ) ;
V_90 . V_98 = V_357 ;
V_90 . V_358 = V_359 ;
F_35 ( V_34 , V_360 , sizeof( V_90 ) , & V_90 ) ;
}
static int F_171 ( struct V_1 * V_2 , T_1 type , T_2 V_353 ,
T_2 V_354 , int V_30 )
{
long V_188 = F_104 ( 3000 ) ;
struct V_351 V_29 ;
int V_11 ;
F_4 ( L_7 , V_2 -> V_5 ) ;
if ( F_30 ( V_361 , & V_2 -> V_76 ) )
return - V_362 ;
V_29 . type = type ;
V_29 . V_353 = V_353 ;
V_29 . V_354 = V_354 ;
F_31 ( V_2 ) ;
V_11 = F_27 ( V_2 , F_169 , ( unsigned long ) & V_29 ,
V_188 ) ;
if ( ! V_11 )
V_11 = F_27 ( V_2 , F_170 , 0 , V_188 ) ;
F_32 ( V_2 ) ;
if ( V_11 < 0 )
return V_11 ;
F_138 ( V_2 -> V_340 , & V_2 -> V_248 ,
V_30 ) ;
return 0 ;
}
int F_172 ( struct V_1 * V_2 )
{
F_4 ( L_7 , V_2 -> V_5 ) ;
if ( ! F_30 ( V_361 , & V_2 -> V_76 ) )
return - V_221 ;
if ( F_121 ( & V_2 -> V_248 ) ) {
struct V_356 V_90 ;
memset ( & V_90 , 0 , sizeof( V_90 ) ) ;
F_142 ( V_2 , V_360 , sizeof( V_90 ) , & V_90 ) ;
}
return 0 ;
}
static void F_173 ( struct V_298 * V_299 )
{
struct V_1 * V_2 = F_136 ( V_299 , struct V_1 ,
V_248 . V_299 ) ;
struct V_356 V_90 ;
F_4 ( L_7 , V_2 -> V_5 ) ;
memset ( & V_90 , 0 , sizeof( V_90 ) ) ;
F_142 ( V_2 , V_360 , sizeof( V_90 ) , & V_90 ) ;
}
static void F_174 ( struct V_298 * V_299 )
{
struct V_1 * V_2 = F_136 ( V_299 , struct V_1 , V_240 ) ;
struct V_351 * V_29 = & V_2 -> V_351 ;
F_4 ( L_7 , V_2 -> V_5 ) ;
F_171 ( V_2 , V_29 -> type , V_29 -> V_353 , V_29 -> V_354 ,
V_29 -> V_30 ) ;
}
int F_175 ( struct V_1 * V_2 , T_1 type , T_2 V_353 , T_2 V_354 ,
int V_30 )
{
struct V_351 * V_29 = & V_2 -> V_351 ;
F_4 ( L_7 , V_2 -> V_5 ) ;
if ( F_30 ( V_199 , & V_2 -> V_76 ) )
return - V_363 ;
if ( F_176 ( & V_2 -> V_240 ) )
return - V_362 ;
V_29 -> type = type ;
V_29 -> V_353 = V_353 ;
V_29 -> V_354 = V_354 ;
V_29 -> V_30 = V_30 ;
F_159 ( V_364 , & V_2 -> V_240 ) ;
return 0 ;
}
struct V_1 * F_177 ( void )
{
struct V_1 * V_2 ;
V_2 = F_95 ( sizeof( struct V_1 ) , V_195 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_275 = ( V_365 | V_366 | V_367 ) ;
V_2 -> V_368 = ( V_369 ) ;
V_2 -> V_271 = ( V_273 ) ;
V_2 -> V_370 = 0x03 ;
V_2 -> V_371 = V_206 ;
V_2 -> V_205 = V_206 ;
V_2 -> V_372 = 800 ;
V_2 -> V_373 = 80 ;
F_178 ( & V_2 -> V_374 ) ;
F_178 ( & V_2 -> V_375 ) ;
F_86 ( & V_2 -> V_376 ) ;
F_86 ( & V_2 -> V_350 ) ;
F_86 ( & V_2 -> V_377 ) ;
F_86 ( & V_2 -> V_327 ) ;
F_86 ( & V_2 -> V_336 ) ;
F_86 ( & V_2 -> V_344 ) ;
F_86 ( & V_2 -> V_378 . V_151 ) ;
F_179 ( & V_2 -> V_234 , V_379 ) ;
F_179 ( & V_2 -> V_233 , V_380 ) ;
F_179 ( & V_2 -> V_232 , V_381 ) ;
F_179 ( & V_2 -> V_300 , F_135 ) ;
F_179 ( & V_2 -> V_240 , F_174 ) ;
F_180 ( & V_2 -> V_241 , F_140 ) ;
F_180 ( & V_2 -> V_244 , F_141 ) ;
F_180 ( & V_2 -> V_248 , F_173 ) ;
F_181 ( & V_2 -> V_236 ) ;
F_181 ( & V_2 -> V_235 ) ;
F_181 ( & V_2 -> V_251 ) ;
F_182 ( & V_2 -> V_10 ) ;
F_183 ( & V_2 -> V_242 , F_158 , ( unsigned long ) V_2 ) ;
F_184 ( V_2 ) ;
F_185 ( V_2 ) ;
return V_2 ;
}
void F_186 ( struct V_1 * V_2 )
{
F_187 ( & V_2 -> V_217 ) ;
}
int F_188 ( struct V_1 * V_2 )
{
int V_130 , error ;
if ( ! V_2 -> V_222 || ! V_2 -> V_239 )
return - V_282 ;
switch ( V_2 -> V_55 ) {
case V_56 :
V_130 = F_189 ( & V_382 , 0 , 0 , V_195 ) ;
break;
case V_57 :
V_130 = F_189 ( & V_382 , 1 , 0 , V_195 ) ;
break;
default:
return - V_282 ;
}
if ( V_130 < 0 )
return V_130 ;
sprintf ( V_2 -> V_5 , L_27 , V_130 ) ;
V_2 -> V_130 = V_130 ;
F_4 ( L_28 , V_2 , V_2 -> V_5 , V_2 -> V_293 ) ;
F_190 ( & V_129 ) ;
F_92 ( & V_2 -> V_151 , & V_383 ) ;
F_191 ( & V_129 ) ;
V_2 -> V_340 = F_192 ( V_2 -> V_5 , V_384 | V_385 |
V_386 , 1 ) ;
if ( ! V_2 -> V_340 ) {
error = - V_196 ;
goto V_11;
}
V_2 -> V_301 = F_192 ( V_2 -> V_5 ,
V_384 | V_385 |
V_386 , 1 ) ;
if ( ! V_2 -> V_301 ) {
F_193 ( V_2 -> V_340 ) ;
error = - V_196 ;
goto V_11;
}
error = F_194 ( V_2 ) ;
if ( error < 0 )
goto V_387;
V_2 -> V_219 = F_195 ( V_2 -> V_5 , & V_2 -> V_217 ,
V_388 , & V_389 ,
V_2 ) ;
if ( V_2 -> V_219 ) {
if ( F_196 ( V_2 -> V_219 ) < 0 ) {
F_197 ( V_2 -> V_219 ) ;
V_2 -> V_219 = NULL ;
}
}
F_34 ( V_227 , & V_2 -> V_76 ) ;
if ( V_2 -> V_55 != V_57 )
F_34 ( V_253 , & V_2 -> V_76 ) ;
F_1 ( V_2 , V_390 ) ;
F_77 ( V_2 ) ;
F_159 ( V_2 -> V_301 , & V_2 -> V_300 ) ;
return V_130 ;
V_387:
F_193 ( V_2 -> V_340 ) ;
F_193 ( V_2 -> V_301 ) ;
V_11:
F_198 ( & V_382 , V_2 -> V_130 ) ;
F_190 ( & V_129 ) ;
F_84 ( & V_2 -> V_151 ) ;
F_191 ( & V_129 ) ;
return error ;
}
void F_199 ( struct V_1 * V_2 )
{
int V_391 , V_130 ;
F_4 ( L_28 , V_2 , V_2 -> V_5 , V_2 -> V_293 ) ;
F_34 ( V_218 , & V_2 -> V_76 ) ;
V_130 = V_2 -> V_130 ;
F_190 ( & V_129 ) ;
F_84 ( & V_2 -> V_151 ) ;
F_191 ( & V_129 ) ;
F_119 ( V_2 ) ;
for ( V_391 = 0 ; V_391 < V_392 ; V_391 ++ )
F_14 ( V_2 -> V_393 [ V_391 ] ) ;
F_120 ( & V_2 -> V_300 ) ;
if ( ! F_30 ( V_225 , & V_2 -> V_41 ) &&
! F_30 ( V_227 , & V_2 -> V_76 ) ) {
F_8 ( V_2 ) ;
F_200 ( V_2 ) ;
F_9 ( V_2 ) ;
}
F_201 ( ! F_202 ( & V_2 -> V_376 ) ) ;
F_1 ( V_2 , V_394 ) ;
if ( V_2 -> V_219 ) {
F_203 ( V_2 -> V_219 ) ;
F_197 ( V_2 -> V_219 ) ;
}
F_204 ( V_2 ) ;
F_193 ( V_2 -> V_340 ) ;
F_193 ( V_2 -> V_301 ) ;
F_8 ( V_2 ) ;
F_164 ( V_2 ) ;
F_143 ( V_2 ) ;
F_144 ( V_2 ) ;
F_147 ( V_2 ) ;
F_161 ( V_2 ) ;
F_9 ( V_2 ) ;
F_108 ( V_2 ) ;
F_198 ( & V_382 , V_130 ) ;
}
int F_205 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_395 ) ;
return 0 ;
}
int F_206 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_396 ) ;
return 0 ;
}
int F_207 ( struct V_13 * V_19 )
{
struct V_1 * V_2 = (struct V_1 * ) V_19 -> V_217 ;
if ( ! V_2 || ( ! F_30 ( V_40 , & V_2 -> V_41 )
&& ! F_30 ( V_225 , & V_2 -> V_41 ) ) ) {
F_14 ( V_19 ) ;
return - V_397 ;
}
F_208 ( V_19 ) -> V_398 = 1 ;
F_209 ( V_19 ) ;
F_210 ( & V_2 -> V_236 , V_19 ) ;
F_159 ( V_2 -> V_340 , & V_2 -> V_234 ) ;
return 0 ;
}
static int F_211 ( struct V_1 * V_2 , int type , void * V_24 ,
int V_399 , T_6 V_127 )
{
int V_22 = 0 ;
int V_400 = 0 ;
int V_401 = V_399 ;
struct V_13 * V_19 ;
struct V_402 * V_403 ;
if ( ( type < V_404 || type > V_405 ) ||
V_127 >= V_392 )
return - V_406 ;
V_19 = V_2 -> V_393 [ V_127 ] ;
if ( ! V_19 ) {
switch ( type ) {
case V_404 :
V_22 = V_407 ;
V_400 = V_408 ;
break;
case V_405 :
V_22 = V_409 ;
V_400 = V_25 ;
break;
case V_410 :
V_22 = V_411 ;
V_400 = V_412 ;
break;
}
V_19 = F_212 ( V_22 , V_160 ) ;
if ( ! V_19 )
return - V_196 ;
V_403 = ( void * ) V_19 -> V_413 ;
V_403 -> V_414 = V_400 ;
V_403 -> V_275 = type ;
V_19 -> V_217 = ( void * ) V_2 ;
V_2 -> V_393 [ V_127 ] = V_19 ;
}
while ( V_399 ) {
V_403 = ( void * ) V_19 -> V_413 ;
V_22 = F_213 ( V_415 , V_403 -> V_414 , V_399 ) ;
memcpy ( F_214 ( V_19 , V_22 ) , V_24 , V_22 ) ;
V_399 -= V_22 ;
V_24 += V_22 ;
V_403 -> V_414 -= V_22 ;
V_401 = V_399 ;
switch ( type ) {
case V_405 :
if ( V_19 -> V_22 == V_25 ) {
struct V_17 * V_416 = V_17 ( V_19 ) ;
V_403 -> V_414 = V_416 -> V_28 ;
if ( F_215 ( V_19 ) < V_403 -> V_414 ) {
F_14 ( V_19 ) ;
V_2 -> V_393 [ V_127 ] = NULL ;
return - V_196 ;
}
}
break;
case V_404 :
if ( V_19 -> V_22 == V_408 ) {
struct V_417 * V_416 = V_417 ( V_19 ) ;
V_403 -> V_414 = F_13 ( V_416 -> V_418 ) ;
if ( F_215 ( V_19 ) < V_403 -> V_414 ) {
F_14 ( V_19 ) ;
V_2 -> V_393 [ V_127 ] = NULL ;
return - V_196 ;
}
}
break;
case V_410 :
if ( V_19 -> V_22 == V_412 ) {
struct V_419 * V_416 = V_419 ( V_19 ) ;
V_403 -> V_414 = V_416 -> V_418 ;
if ( F_215 ( V_19 ) < V_403 -> V_414 ) {
F_14 ( V_19 ) ;
V_2 -> V_393 [ V_127 ] = NULL ;
return - V_196 ;
}
}
break;
}
if ( V_403 -> V_414 == 0 ) {
F_208 ( V_19 ) -> V_275 = type ;
F_207 ( V_19 ) ;
V_2 -> V_393 [ V_127 ] = NULL ;
return V_401 ;
}
}
return V_401 ;
}
int F_216 ( struct V_1 * V_2 , int type , void * V_24 , int V_399 )
{
int V_420 = 0 ;
if ( type < V_404 || type > V_405 )
return - V_406 ;
while ( V_399 ) {
V_420 = F_211 ( V_2 , type , V_24 , V_399 , type - 1 ) ;
if ( V_420 < 0 )
return V_420 ;
V_24 += ( V_399 - V_420 ) ;
V_399 = V_420 ;
}
return V_420 ;
}
int F_217 ( struct V_1 * V_2 , void * V_24 , int V_399 )
{
int type ;
int V_420 = 0 ;
while ( V_399 ) {
struct V_13 * V_19 = V_2 -> V_393 [ V_421 ] ;
if ( ! V_19 ) {
struct { char type ; } * V_422 ;
V_422 = V_24 ;
type = V_422 -> type ;
V_24 ++ ;
V_399 -- ;
} else
type = F_208 ( V_19 ) -> V_275 ;
V_420 = F_211 ( V_2 , type , V_24 , V_399 ,
V_421 ) ;
if ( V_420 < 0 )
return V_420 ;
V_24 += ( V_399 - V_420 ) ;
V_399 = V_420 ;
}
return V_420 ;
}
int F_218 ( struct V_423 * V_413 )
{
F_4 ( L_29 , V_413 , V_413 -> V_5 ) ;
F_190 ( & V_424 ) ;
F_92 ( & V_413 -> V_151 , & V_425 ) ;
F_191 ( & V_424 ) ;
return 0 ;
}
int F_219 ( struct V_423 * V_413 )
{
F_4 ( L_29 , V_413 , V_413 -> V_5 ) ;
F_190 ( & V_424 ) ;
F_84 ( & V_413 -> V_151 ) ;
F_191 ( & V_424 ) ;
return 0 ;
}
static int F_220 ( struct V_13 * V_19 )
{
struct V_1 * V_2 = (struct V_1 * ) V_19 -> V_217 ;
if ( ! V_2 ) {
F_14 ( V_19 ) ;
return - V_191 ;
}
F_4 ( L_30 , V_2 -> V_5 , F_208 ( V_19 ) -> V_275 , V_19 -> V_22 ) ;
F_209 ( V_19 ) ;
F_221 ( V_2 , V_19 ) ;
if ( F_222 ( & V_2 -> V_426 ) ) {
F_223 ( V_2 , V_19 ) ;
}
F_224 ( V_19 ) ;
return V_2 -> V_427 ( V_19 ) ;
}
void F_17 ( struct V_33 * V_34 , struct V_1 * V_2 )
{
F_181 ( & V_34 -> V_235 ) ;
V_34 -> V_2 = V_2 ;
V_34 -> V_11 = 0 ;
}
int F_19 ( struct V_33 * V_34 , T_11 V_428 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_13 * V_19 ;
unsigned long V_41 ;
F_4 ( L_31 , F_225 ( & V_34 -> V_235 ) ) ;
if ( V_34 -> V_11 ) {
F_118 ( & V_34 -> V_235 ) ;
return V_34 -> V_11 ;
}
if ( F_226 ( & V_34 -> V_235 ) )
return - V_21 ;
V_19 = F_227 ( & V_34 -> V_235 ) ;
F_208 ( V_19 ) -> V_34 . V_428 = V_428 ;
F_228 ( & V_2 -> V_235 . V_374 , V_41 ) ;
F_229 ( & V_34 -> V_235 , & V_2 -> V_235 ) ;
F_230 ( & V_2 -> V_235 . V_374 , V_41 ) ;
F_159 ( V_2 -> V_340 , & V_2 -> V_233 ) ;
return 0 ;
}
static struct V_13 * F_231 ( struct V_1 * V_2 , T_2 V_14 ,
T_3 V_28 , const void * V_29 )
{
int V_22 = V_429 + V_28 ;
struct V_338 * V_18 ;
struct V_13 * V_19 ;
V_19 = F_212 ( V_22 , V_160 ) ;
if ( ! V_19 )
return NULL ;
V_18 = (struct V_338 * ) F_214 ( V_19 , V_429 ) ;
V_18 -> V_14 = F_62 ( V_14 ) ;
V_18 -> V_28 = V_28 ;
if ( V_28 )
memcpy ( F_214 ( V_19 , V_28 ) , V_29 , V_28 ) ;
F_4 ( L_32 , V_19 -> V_22 ) ;
F_208 ( V_19 ) -> V_275 = V_430 ;
V_19 -> V_217 = ( void * ) V_2 ;
return V_19 ;
}
int F_142 ( struct V_1 * V_2 , T_10 V_14 , T_4 V_28 ,
const void * V_29 )
{
struct V_13 * V_19 ;
F_4 ( L_33 , V_2 -> V_5 , V_14 , V_28 ) ;
V_19 = F_231 ( V_2 , V_14 , V_28 , V_29 ) ;
if ( ! V_19 ) {
F_11 ( L_34 , V_2 -> V_5 ) ;
return - V_196 ;
}
F_208 ( V_19 ) -> V_34 . V_431 = true ;
F_210 ( & V_2 -> V_235 , V_19 ) ;
F_159 ( V_2 -> V_340 , & V_2 -> V_233 ) ;
return 0 ;
}
void F_18 ( struct V_33 * V_34 , T_2 V_14 , T_3 V_28 ,
const void * V_29 , T_1 V_3 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_13 * V_19 ;
F_4 ( L_33 , V_2 -> V_5 , V_14 , V_28 ) ;
if ( V_34 -> V_11 )
return;
V_19 = F_231 ( V_2 , V_14 , V_28 , V_29 ) ;
if ( ! V_19 ) {
F_11 ( L_35 ,
V_2 -> V_5 , V_14 ) ;
V_34 -> V_11 = - V_196 ;
return;
}
if ( F_226 ( & V_34 -> V_235 ) )
F_208 ( V_19 ) -> V_34 . V_431 = true ;
F_208 ( V_19 ) -> V_34 . V_3 = V_3 ;
F_210 ( & V_34 -> V_235 , V_19 ) ;
}
void F_35 ( struct V_33 * V_34 , T_2 V_14 , T_3 V_28 ,
const void * V_29 )
{
F_18 ( V_34 , V_14 , V_28 , V_29 , 0 ) ;
}
void * F_232 ( struct V_1 * V_2 , T_10 V_14 )
{
struct V_338 * V_18 ;
if ( ! V_2 -> V_238 )
return NULL ;
V_18 = ( void * ) V_2 -> V_238 -> V_24 ;
if ( V_18 -> V_14 != F_62 ( V_14 ) )
return NULL ;
F_4 ( L_36 , V_2 -> V_5 , V_14 ) ;
return V_2 -> V_238 -> V_24 + V_429 ;
}
static void F_233 ( struct V_13 * V_19 , T_10 V_432 , T_10 V_41 )
{
struct V_417 * V_18 ;
int V_22 = V_19 -> V_22 ;
F_234 ( V_19 , V_408 ) ;
F_235 ( V_19 ) ;
V_18 = (struct V_417 * ) F_236 ( V_19 ) ;
V_18 -> V_432 = F_62 ( F_237 ( V_432 , V_41 ) ) ;
V_18 -> V_418 = F_62 ( V_22 ) ;
}
static void F_238 ( struct V_433 * V_434 , struct V_435 * V_436 ,
struct V_13 * V_19 , T_10 V_41 )
{
struct V_311 * V_312 = V_434 -> V_312 ;
struct V_1 * V_2 = V_312 -> V_2 ;
struct V_13 * V_151 ;
V_19 -> V_22 = F_239 ( V_19 ) ;
V_19 -> V_437 = 0 ;
F_208 ( V_19 ) -> V_275 = V_404 ;
switch ( V_2 -> V_55 ) {
case V_56 :
F_233 ( V_19 , V_312 -> V_432 , V_41 ) ;
break;
case V_57 :
F_233 ( V_19 , V_434 -> V_432 , V_41 ) ;
break;
default:
F_11 ( L_37 , V_2 -> V_5 , V_2 -> V_55 ) ;
return;
}
V_151 = F_240 ( V_19 ) -> V_438 ;
if ( ! V_151 ) {
F_4 ( L_38 , V_2 -> V_5 , V_19 , V_19 -> V_22 ) ;
F_210 ( V_436 , V_19 ) ;
} else {
F_4 ( L_39 , V_2 -> V_5 , V_19 , V_19 -> V_22 ) ;
F_240 ( V_19 ) -> V_438 = NULL ;
F_241 ( & V_436 -> V_374 ) ;
F_242 ( V_436 , V_19 ) ;
V_41 &= ~ V_439 ;
V_41 |= V_440 ;
do {
V_19 = V_151 ; V_151 = V_151 -> V_441 ;
V_19 -> V_217 = ( void * ) V_2 ;
F_208 ( V_19 ) -> V_275 = V_404 ;
F_233 ( V_19 , V_312 -> V_432 , V_41 ) ;
F_4 ( L_39 , V_2 -> V_5 , V_19 , V_19 -> V_22 ) ;
F_242 ( V_436 , V_19 ) ;
} while ( V_151 );
F_243 ( & V_436 -> V_374 ) ;
}
}
void F_244 ( struct V_433 * V_434 , struct V_13 * V_19 , T_10 V_41 )
{
struct V_1 * V_2 = V_434 -> V_312 -> V_2 ;
F_4 ( L_40 , V_2 -> V_5 , V_434 , V_41 ) ;
V_19 -> V_217 = ( void * ) V_2 ;
F_238 ( V_434 , & V_434 -> V_442 , V_19 , V_41 ) ;
F_159 ( V_2 -> V_340 , & V_2 -> V_232 ) ;
}
void F_245 ( struct V_311 * V_312 , struct V_13 * V_19 )
{
struct V_1 * V_2 = V_312 -> V_2 ;
struct V_419 V_18 ;
F_4 ( L_41 , V_2 -> V_5 , V_19 -> V_22 ) ;
V_18 . V_432 = F_62 ( V_312 -> V_432 ) ;
V_18 . V_418 = V_19 -> V_22 ;
F_234 ( V_19 , V_412 ) ;
F_235 ( V_19 ) ;
memcpy ( F_236 ( V_19 ) , & V_18 , V_412 ) ;
V_19 -> V_217 = ( void * ) V_2 ;
F_208 ( V_19 ) -> V_275 = V_410 ;
F_210 ( & V_312 -> V_442 , V_19 ) ;
F_159 ( V_2 -> V_340 , & V_2 -> V_232 ) ;
}
static struct V_311 * F_246 ( struct V_1 * V_2 , T_6 type ,
int * V_443 )
{
struct V_444 * V_416 = & V_2 -> V_378 ;
struct V_311 * V_312 = NULL , * V_445 ;
unsigned int V_165 = 0 , V_446 = ~ 0 ;
F_247 () ;
F_248 (c, &h->list, list) {
if ( V_445 -> type != type || F_226 ( & V_445 -> V_442 ) )
continue;
if ( V_445 -> V_134 != V_447 && V_445 -> V_134 != V_448 )
continue;
V_165 ++ ;
if ( V_445 -> V_339 < V_446 ) {
V_446 = V_445 -> V_339 ;
V_312 = V_445 ;
}
if ( F_249 ( V_2 , type ) == V_165 )
break;
}
F_250 () ;
if ( V_312 ) {
int V_449 , V_450 ;
switch ( V_312 -> type ) {
case V_451 :
V_449 = V_2 -> V_255 ;
break;
case V_452 :
case V_453 :
V_449 = V_2 -> V_256 ;
break;
case V_454 :
V_449 = V_2 -> V_294 ? V_2 -> V_257 : V_2 -> V_255 ;
break;
default:
V_449 = 0 ;
F_11 ( L_42 ) ;
}
V_450 = V_449 / V_165 ;
* V_443 = V_450 ? V_450 : 1 ;
} else
* V_443 = 0 ;
F_4 ( L_43 , V_312 , * V_443 ) ;
return V_312 ;
}
static void F_251 ( struct V_1 * V_2 , T_6 type )
{
struct V_444 * V_416 = & V_2 -> V_378 ;
struct V_311 * V_445 ;
F_11 ( L_44 , V_2 -> V_5 ) ;
F_247 () ;
F_248 (c, &h->list, list) {
if ( V_445 -> type == type && V_445 -> V_339 ) {
F_11 ( L_45 ,
V_2 -> V_5 , & V_445 -> V_455 ) ;
F_252 ( V_445 , V_456 ) ;
}
}
F_250 () ;
}
static struct V_433 * F_253 ( struct V_1 * V_2 , T_6 type ,
int * V_443 )
{
struct V_444 * V_416 = & V_2 -> V_378 ;
struct V_433 * V_434 = NULL ;
unsigned int V_165 = 0 , V_446 = ~ 0 , V_457 = 0 ;
struct V_311 * V_312 ;
int V_449 , V_450 , V_458 = 0 ;
F_4 ( L_7 , V_2 -> V_5 ) ;
F_247 () ;
F_248 (conn, &h->list, list) {
struct V_433 * V_306 ;
if ( V_312 -> type != type )
continue;
if ( V_312 -> V_134 != V_447 && V_312 -> V_134 != V_448 )
continue;
V_458 ++ ;
F_248 (tmp, &conn->chan_list, list) {
struct V_13 * V_19 ;
if ( F_226 ( & V_306 -> V_442 ) )
continue;
V_19 = F_254 ( & V_306 -> V_442 ) ;
if ( V_19 -> V_459 < V_457 )
continue;
if ( V_19 -> V_459 > V_457 ) {
V_165 = 0 ;
V_446 = ~ 0 ;
V_457 = V_19 -> V_459 ;
}
V_165 ++ ;
if ( V_312 -> V_339 < V_446 ) {
V_446 = V_312 -> V_339 ;
V_434 = V_306 ;
}
}
if ( F_249 ( V_2 , type ) == V_458 )
break;
}
F_250 () ;
if ( ! V_434 )
return NULL ;
switch ( V_434 -> V_312 -> type ) {
case V_451 :
V_449 = V_2 -> V_255 ;
break;
case V_460 :
V_449 = V_2 -> V_461 ;
break;
case V_452 :
case V_453 :
V_449 = V_2 -> V_256 ;
break;
case V_454 :
V_449 = V_2 -> V_294 ? V_2 -> V_257 : V_2 -> V_255 ;
break;
default:
V_449 = 0 ;
F_11 ( L_42 ) ;
}
V_450 = V_449 / V_165 ;
* V_443 = V_450 ? V_450 : 1 ;
F_4 ( L_46 , V_434 , * V_443 ) ;
return V_434 ;
}
static void F_255 ( struct V_1 * V_2 , T_6 type )
{
struct V_444 * V_416 = & V_2 -> V_378 ;
struct V_311 * V_312 ;
int V_165 = 0 ;
F_4 ( L_7 , V_2 -> V_5 ) ;
F_247 () ;
F_248 (conn, &h->list, list) {
struct V_433 * V_434 ;
if ( V_312 -> type != type )
continue;
if ( V_312 -> V_134 != V_447 && V_312 -> V_134 != V_448 )
continue;
V_165 ++ ;
F_248 (chan, &conn->chan_list, list) {
struct V_13 * V_19 ;
if ( V_434 -> V_339 ) {
V_434 -> V_339 = 0 ;
continue;
}
if ( F_226 ( & V_434 -> V_442 ) )
continue;
V_19 = F_254 ( & V_434 -> V_442 ) ;
if ( V_19 -> V_459 >= V_462 - 1 )
continue;
V_19 -> V_459 = V_462 - 1 ;
F_4 ( L_47 , V_434 , V_19 ,
V_19 -> V_459 ) ;
}
if ( F_249 ( V_2 , type ) == V_165 )
break;
}
F_250 () ;
}
static inline int F_256 ( struct V_1 * V_2 , struct V_13 * V_19 )
{
return F_257 ( V_19 -> V_22 - V_408 , V_2 -> V_463 ) ;
}
static void F_258 ( struct V_1 * V_2 , unsigned int V_449 )
{
if ( ! F_30 ( V_229 , & V_2 -> V_41 ) ) {
if ( ! V_449 && F_259 ( V_164 , V_2 -> V_464 +
V_465 ) )
F_251 ( V_2 , V_451 ) ;
}
}
static void F_260 ( struct V_1 * V_2 )
{
unsigned int V_449 = V_2 -> V_255 ;
struct V_433 * V_434 ;
struct V_13 * V_19 ;
int V_443 ;
F_258 ( V_2 , V_449 ) ;
while ( V_2 -> V_255 &&
( V_434 = F_253 ( V_2 , V_451 , & V_443 ) ) ) {
T_3 V_459 = ( F_254 ( & V_434 -> V_442 ) ) -> V_459 ;
while ( V_443 -- && ( V_19 = F_254 ( & V_434 -> V_442 ) ) ) {
F_4 ( L_48 , V_434 , V_19 ,
V_19 -> V_22 , V_19 -> V_459 ) ;
if ( V_19 -> V_459 < V_459 )
break;
V_19 = F_261 ( & V_434 -> V_442 ) ;
F_262 ( V_434 -> V_312 ,
F_208 ( V_19 ) -> V_466 ) ;
F_220 ( V_19 ) ;
V_2 -> V_464 = V_164 ;
V_2 -> V_255 -- ;
V_434 -> V_339 ++ ;
V_434 -> V_312 -> V_339 ++ ;
}
}
if ( V_449 != V_2 -> V_255 )
F_255 ( V_2 , V_451 ) ;
}
static void F_263 ( struct V_1 * V_2 )
{
unsigned int V_449 = V_2 -> V_461 ;
struct V_433 * V_434 ;
struct V_13 * V_19 ;
int V_443 ;
T_1 type ;
F_258 ( V_2 , V_449 ) ;
F_4 ( L_7 , V_2 -> V_5 ) ;
if ( V_2 -> V_55 == V_57 )
type = V_460 ;
else
type = V_451 ;
while ( V_2 -> V_461 > 0 &&
( V_434 = F_253 ( V_2 , type , & V_443 ) ) ) {
T_3 V_459 = ( F_254 ( & V_434 -> V_442 ) ) -> V_459 ;
while ( V_443 > 0 && ( V_19 = F_254 ( & V_434 -> V_442 ) ) ) {
int V_467 ;
F_4 ( L_48 , V_434 , V_19 ,
V_19 -> V_22 , V_19 -> V_459 ) ;
if ( V_19 -> V_459 < V_459 )
break;
V_19 = F_261 ( & V_434 -> V_442 ) ;
V_467 = F_256 ( V_2 , V_19 ) ;
if ( V_467 > V_2 -> V_461 )
return;
F_262 ( V_434 -> V_312 ,
F_208 ( V_19 ) -> V_466 ) ;
F_220 ( V_19 ) ;
V_2 -> V_464 = V_164 ;
V_2 -> V_461 -= V_467 ;
V_443 -= V_467 ;
V_434 -> V_339 += V_467 ;
V_434 -> V_312 -> V_339 += V_467 ;
}
}
if ( V_449 != V_2 -> V_461 )
F_255 ( V_2 , type ) ;
}
static void F_264 ( struct V_1 * V_2 )
{
F_4 ( L_7 , V_2 -> V_5 ) ;
if ( ! F_249 ( V_2 , V_451 ) && V_2 -> V_55 == V_56 )
return;
if ( ! F_249 ( V_2 , V_460 ) && V_2 -> V_55 == V_57 )
return;
switch ( V_2 -> V_45 ) {
case V_46 :
F_260 ( V_2 ) ;
break;
case V_50 :
F_263 ( V_2 ) ;
break;
}
}
static void F_265 ( struct V_1 * V_2 )
{
struct V_311 * V_312 ;
struct V_13 * V_19 ;
int V_443 ;
F_4 ( L_7 , V_2 -> V_5 ) ;
if ( ! F_249 ( V_2 , V_452 ) )
return;
while ( V_2 -> V_256 && ( V_312 = F_246 ( V_2 , V_452 , & V_443 ) ) ) {
while ( V_443 -- && ( V_19 = F_261 ( & V_312 -> V_442 ) ) ) {
F_4 ( L_49 , V_19 , V_19 -> V_22 ) ;
F_220 ( V_19 ) ;
V_312 -> V_339 ++ ;
if ( V_312 -> V_339 == ~ 0 )
V_312 -> V_339 = 0 ;
}
}
}
static void F_266 ( struct V_1 * V_2 )
{
struct V_311 * V_312 ;
struct V_13 * V_19 ;
int V_443 ;
F_4 ( L_7 , V_2 -> V_5 ) ;
if ( ! F_249 ( V_2 , V_453 ) )
return;
while ( V_2 -> V_256 && ( V_312 = F_246 ( V_2 , V_453 ,
& V_443 ) ) ) {
while ( V_443 -- && ( V_19 = F_261 ( & V_312 -> V_442 ) ) ) {
F_4 ( L_49 , V_19 , V_19 -> V_22 ) ;
F_220 ( V_19 ) ;
V_312 -> V_339 ++ ;
if ( V_312 -> V_339 == ~ 0 )
V_312 -> V_339 = 0 ;
}
}
}
static void F_267 ( struct V_1 * V_2 )
{
struct V_433 * V_434 ;
struct V_13 * V_19 ;
int V_443 , V_449 , V_306 ;
F_4 ( L_7 , V_2 -> V_5 ) ;
if ( ! F_249 ( V_2 , V_454 ) )
return;
if ( ! F_30 ( V_229 , & V_2 -> V_41 ) ) {
if ( ! V_2 -> V_257 && V_2 -> V_295 &&
F_259 ( V_164 , V_2 -> V_468 + V_469 * 45 ) )
F_251 ( V_2 , V_454 ) ;
}
V_449 = V_2 -> V_295 ? V_2 -> V_257 : V_2 -> V_255 ;
V_306 = V_449 ;
while ( V_449 && ( V_434 = F_253 ( V_2 , V_454 , & V_443 ) ) ) {
T_3 V_459 = ( F_254 ( & V_434 -> V_442 ) ) -> V_459 ;
while ( V_443 -- && ( V_19 = F_254 ( & V_434 -> V_442 ) ) ) {
F_4 ( L_48 , V_434 , V_19 ,
V_19 -> V_22 , V_19 -> V_459 ) ;
if ( V_19 -> V_459 < V_459 )
break;
V_19 = F_261 ( & V_434 -> V_442 ) ;
F_220 ( V_19 ) ;
V_2 -> V_468 = V_164 ;
V_449 -- ;
V_434 -> V_339 ++ ;
V_434 -> V_312 -> V_339 ++ ;
}
}
if ( V_2 -> V_295 )
V_2 -> V_257 = V_449 ;
else
V_2 -> V_255 = V_449 ;
if ( V_449 != V_306 )
F_255 ( V_2 , V_454 ) ;
}
static void V_381 ( struct V_298 * V_299 )
{
struct V_1 * V_2 = F_136 ( V_299 , struct V_1 , V_232 ) ;
struct V_13 * V_19 ;
F_4 ( L_50 , V_2 -> V_5 , V_2 -> V_255 ,
V_2 -> V_256 , V_2 -> V_257 ) ;
F_264 ( V_2 ) ;
F_265 ( V_2 ) ;
F_266 ( V_2 ) ;
F_267 ( V_2 ) ;
while ( ( V_19 = F_261 ( & V_2 -> V_251 ) ) )
F_220 ( V_19 ) ;
}
static void F_268 ( struct V_1 * V_2 , struct V_13 * V_19 )
{
struct V_417 * V_18 = ( void * ) V_19 -> V_24 ;
struct V_311 * V_312 ;
T_10 V_432 , V_41 ;
F_12 ( V_19 , V_408 ) ;
V_432 = F_13 ( V_18 -> V_432 ) ;
V_41 = F_269 ( V_432 ) ;
V_432 = F_270 ( V_432 ) ;
F_4 ( L_51 , V_2 -> V_5 , V_19 -> V_22 ,
V_432 , V_41 ) ;
V_2 -> V_258 . V_470 ++ ;
F_8 ( V_2 ) ;
V_312 = F_271 ( V_2 , V_432 ) ;
F_9 ( V_2 ) ;
if ( V_312 ) {
F_262 ( V_312 , V_471 ) ;
F_272 ( V_312 , V_19 , V_41 ) ;
return;
} else {
F_11 ( L_52 ,
V_2 -> V_5 , V_432 ) ;
}
F_14 ( V_19 ) ;
}
static void F_273 ( struct V_1 * V_2 , struct V_13 * V_19 )
{
struct V_419 * V_18 = ( void * ) V_19 -> V_24 ;
struct V_311 * V_312 ;
T_10 V_432 ;
F_12 ( V_19 , V_412 ) ;
V_432 = F_13 ( V_18 -> V_432 ) ;
F_4 ( L_53 , V_2 -> V_5 , V_19 -> V_22 , V_432 ) ;
V_2 -> V_258 . V_472 ++ ;
F_8 ( V_2 ) ;
V_312 = F_271 ( V_2 , V_432 ) ;
F_9 ( V_2 ) ;
if ( V_312 ) {
F_274 ( V_312 , V_19 ) ;
return;
} else {
F_11 ( L_54 ,
V_2 -> V_5 , V_432 ) ;
}
F_14 ( V_19 ) ;
}
static bool F_275 ( struct V_1 * V_2 )
{
struct V_13 * V_19 ;
V_19 = F_254 ( & V_2 -> V_235 ) ;
if ( ! V_19 )
return true ;
return F_208 ( V_19 ) -> V_34 . V_431 ;
}
static void F_276 ( struct V_1 * V_2 )
{
struct V_338 * V_339 ;
struct V_13 * V_19 ;
T_2 V_14 ;
if ( ! V_2 -> V_238 )
return;
V_339 = ( void * ) V_2 -> V_238 -> V_24 ;
V_14 = F_13 ( V_339 -> V_14 ) ;
if ( V_14 == V_44 )
return;
V_19 = F_277 ( V_2 -> V_238 , V_195 ) ;
if ( ! V_19 )
return;
F_278 ( & V_2 -> V_235 , V_19 ) ;
F_159 ( V_2 -> V_340 , & V_2 -> V_233 ) ;
}
void F_279 ( struct V_1 * V_2 , T_2 V_14 , T_1 V_473 )
{
T_11 V_474 = NULL ;
struct V_13 * V_19 ;
unsigned long V_41 ;
F_4 ( L_55 , V_14 , V_473 ) ;
if ( ! F_232 ( V_2 , V_14 ) ) {
if ( F_30 ( V_225 , & V_2 -> V_41 ) && V_14 == V_44 )
F_276 ( V_2 ) ;
return;
}
if ( ! V_473 && ! F_275 ( V_2 ) )
return;
if ( V_2 -> V_238 ) {
V_474 = F_208 ( V_2 -> V_238 ) -> V_34 . V_428 ;
if ( V_474 )
goto V_475;
}
F_228 ( & V_2 -> V_235 . V_374 , V_41 ) ;
while ( ( V_19 = F_280 ( & V_2 -> V_235 ) ) ) {
if ( F_208 ( V_19 ) -> V_34 . V_431 ) {
F_281 ( & V_2 -> V_235 , V_19 ) ;
break;
}
V_474 = F_208 ( V_19 ) -> V_34 . V_428 ;
F_14 ( V_19 ) ;
}
F_230 ( & V_2 -> V_235 . V_374 , V_41 ) ;
V_475:
if ( V_474 )
V_474 ( V_2 , V_473 ) ;
}
static void V_379 ( struct V_298 * V_299 )
{
struct V_1 * V_2 = F_136 ( V_299 , struct V_1 , V_234 ) ;
struct V_13 * V_19 ;
F_4 ( L_7 , V_2 -> V_5 ) ;
while ( ( V_19 = F_261 ( & V_2 -> V_236 ) ) ) {
F_221 ( V_2 , V_19 ) ;
if ( F_222 ( & V_2 -> V_426 ) ) {
F_223 ( V_2 , V_19 ) ;
}
if ( F_30 ( V_229 , & V_2 -> V_41 ) ) {
F_14 ( V_19 ) ;
continue;
}
if ( F_30 ( V_225 , & V_2 -> V_41 ) ) {
switch ( F_208 ( V_19 ) -> V_275 ) {
case V_404 :
case V_410 :
F_14 ( V_19 ) ;
continue;
}
}
switch ( F_208 ( V_19 ) -> V_275 ) {
case V_405 :
F_4 ( L_56 , V_2 -> V_5 ) ;
F_282 ( V_2 , V_19 ) ;
break;
case V_404 :
F_4 ( L_57 , V_2 -> V_5 ) ;
F_268 ( V_2 , V_19 ) ;
break;
case V_410 :
F_4 ( L_58 , V_2 -> V_5 ) ;
F_273 ( V_2 , V_19 ) ;
break;
default:
F_14 ( V_19 ) ;
break;
}
}
}
static void V_380 ( struct V_298 * V_299 )
{
struct V_1 * V_2 = F_136 ( V_299 , struct V_1 , V_233 ) ;
struct V_13 * V_19 ;
F_4 ( L_59 , V_2 -> V_5 ,
F_222 ( & V_2 -> V_224 ) , F_225 ( & V_2 -> V_235 ) ) ;
if ( F_222 ( & V_2 -> V_224 ) ) {
V_19 = F_261 ( & V_2 -> V_235 ) ;
if ( ! V_19 )
return;
F_14 ( V_2 -> V_238 ) ;
V_2 -> V_238 = F_277 ( V_19 , V_160 ) ;
if ( V_2 -> V_238 ) {
F_283 ( & V_2 -> V_224 ) ;
F_220 ( V_19 ) ;
if ( F_30 ( V_43 , & V_2 -> V_41 ) )
F_284 ( & V_2 -> V_242 ) ;
else
F_285 ( & V_2 -> V_242 ,
V_164 + V_250 ) ;
} else {
F_278 ( & V_2 -> V_235 , V_19 ) ;
F_159 ( V_2 -> V_340 , & V_2 -> V_233 ) ;
}
}
}
int F_286 ( struct V_1 * V_2 , T_1 V_180 )
{
T_1 V_179 [ 3 ] = { 0x33 , 0x8b , 0x9e } ;
struct V_177 V_90 ;
F_4 ( L_7 , V_2 -> V_5 ) ;
if ( F_30 ( V_178 , & V_2 -> V_41 ) )
return - V_362 ;
F_82 ( V_2 ) ;
memset ( & V_90 , 0 , sizeof( V_90 ) ) ;
memcpy ( & V_90 . V_179 , V_179 , sizeof( V_90 . V_179 ) ) ;
V_90 . V_180 = V_180 ;
return F_142 ( V_2 , V_182 , sizeof( V_90 ) , & V_90 ) ;
}
int F_287 ( struct V_1 * V_2 )
{
F_4 ( L_7 , V_2 -> V_5 ) ;
if ( ! F_30 ( V_178 , & V_2 -> V_41 ) )
return - V_221 ;
return F_142 ( V_2 , V_476 , 0 , NULL ) ;
}
T_1 F_288 ( T_1 V_321 )
{
switch ( V_321 ) {
case V_477 :
return V_478 ;
default:
return V_479 ;
}
}
