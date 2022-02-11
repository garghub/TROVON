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
if ( V_2 -> V_77 != 31 && V_2 -> V_66 > V_67 )
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
void F_82 ( struct V_1 * V_2 )
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
F_6 ( V_2 , V_191 ) ;
F_31 ( V_2 ) ;
if ( ! F_121 ( V_40 , & V_2 -> V_41 ) ) {
F_122 ( & V_2 -> V_241 ) ;
F_32 ( V_2 ) ;
return 0 ;
}
F_117 ( & V_2 -> V_232 ) ;
F_117 ( & V_2 -> V_234 ) ;
if ( V_2 -> V_242 > 0 ) {
F_120 ( & V_2 -> V_243 ) ;
V_2 -> V_242 = 0 ;
F_114 ( V_244 , & V_2 -> V_76 ) ;
}
if ( F_121 ( V_245 , & V_2 -> V_76 ) )
F_120 ( & V_2 -> V_246 ) ;
F_123 ( & V_2 -> V_247 ) ;
F_8 ( V_2 ) ;
F_82 ( V_2 ) ;
F_124 ( V_2 ) ;
F_9 ( V_2 ) ;
F_1 ( V_2 , V_248 ) ;
if ( V_2 -> V_237 )
V_2 -> V_237 ( V_2 ) ;
F_118 ( & V_2 -> V_235 ) ;
F_113 ( & V_2 -> V_224 , 1 ) ;
if ( ! F_30 ( V_229 , & V_2 -> V_41 ) &&
F_30 ( V_53 , & V_2 -> V_54 ) ) {
F_34 ( V_225 , & V_2 -> V_41 ) ;
F_27 ( V_2 , F_33 , 0 , V_249 ) ;
F_114 ( V_225 , & V_2 -> V_41 ) ;
}
F_117 ( & V_2 -> V_233 ) ;
F_118 ( & V_2 -> V_236 ) ;
F_118 ( & V_2 -> V_235 ) ;
F_118 ( & V_2 -> V_250 ) ;
if ( V_2 -> V_238 ) {
F_122 ( & V_2 -> V_241 ) ;
F_14 ( V_2 -> V_238 ) ;
V_2 -> V_238 = NULL ;
}
F_14 ( V_2 -> V_20 ) ;
V_2 -> V_20 = NULL ;
V_2 -> V_239 ( V_2 ) ;
V_2 -> V_41 = 0 ;
V_2 -> V_76 &= ~ V_251 ;
if ( ! F_121 ( V_252 , & V_2 -> V_76 ) &&
F_115 ( V_2 ) ) {
F_8 ( V_2 ) ;
F_116 ( V_2 , 0 ) ;
F_9 ( V_2 ) ;
}
V_2 -> V_253 = 0 ;
memset ( V_2 -> V_91 , 0 , sizeof( V_2 -> V_91 ) ) ;
memset ( V_2 -> V_173 , 0 , sizeof( V_2 -> V_173 ) ) ;
F_32 ( V_2 ) ;
F_108 ( V_2 ) ;
return 0 ;
}
int F_125 ( T_10 V_217 )
{
struct V_1 * V_2 ;
int V_11 ;
V_2 = F_74 ( V_217 ) ;
if ( ! V_2 )
return - V_191 ;
if ( F_121 ( V_252 , & V_2 -> V_76 ) )
F_120 ( & V_2 -> V_240 ) ;
V_11 = F_119 ( V_2 ) ;
F_108 ( V_2 ) ;
return V_11 ;
}
int F_126 ( T_10 V_217 )
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
F_124 ( V_2 ) ;
F_9 ( V_2 ) ;
if ( V_2 -> V_237 )
V_2 -> V_237 ( V_2 ) ;
F_113 ( & V_2 -> V_224 , 1 ) ;
V_2 -> V_254 = 0 ; V_2 -> V_255 = 0 ; V_2 -> V_256 = 0 ;
if ( ! F_30 ( V_229 , & V_2 -> V_41 ) )
V_39 = F_27 ( V_2 , F_33 , 0 , V_121 ) ;
V_194:
F_32 ( V_2 ) ;
F_108 ( V_2 ) ;
return V_39 ;
}
int F_127 ( T_10 V_217 )
{
struct V_1 * V_2 ;
int V_39 = 0 ;
V_2 = F_74 ( V_217 ) ;
if ( ! V_2 )
return - V_191 ;
memset ( & V_2 -> V_257 , 0 , sizeof( struct V_258 ) ) ;
F_108 ( V_2 ) ;
return V_39 ;
}
int F_128 ( unsigned int V_259 , void T_8 * V_184 )
{
struct V_1 * V_2 ;
struct V_260 V_261 ;
int V_11 = 0 ;
if ( F_101 ( & V_261 , V_184 , sizeof( V_261 ) ) )
return - V_189 ;
V_2 = F_74 ( V_261 . V_190 ) ;
if ( ! V_2 )
return - V_191 ;
switch ( V_259 ) {
case V_262 :
V_11 = F_29 ( V_2 , F_71 , V_261 . V_263 ,
V_121 ) ;
break;
case V_264 :
if ( ! F_129 ( V_2 ) ) {
V_11 = - V_265 ;
break;
}
if ( ! F_30 ( V_266 , & V_2 -> V_41 ) ) {
V_11 = F_29 ( V_2 , F_71 , V_261 . V_263 ,
V_121 ) ;
if ( V_11 )
break;
}
V_11 = F_29 ( V_2 , F_72 , V_261 . V_263 ,
V_121 ) ;
break;
case V_267 :
V_11 = F_29 ( V_2 , F_70 , V_261 . V_263 ,
V_121 ) ;
break;
case V_268 :
V_11 = F_29 ( V_2 , F_73 , V_261 . V_263 ,
V_121 ) ;
break;
case V_269 :
V_2 -> V_270 = ( ( T_10 ) V_261 . V_263 ) &
( V_271 | V_272 ) ;
break;
case V_273 :
V_2 -> V_274 = ( T_10 ) V_261 . V_263 ;
break;
case V_275 :
V_2 -> V_276 = * ( ( T_10 * ) & V_261 . V_263 + 1 ) ;
V_2 -> V_277 = * ( ( T_10 * ) & V_261 . V_263 + 0 ) ;
break;
case V_278 :
V_2 -> V_279 = * ( ( T_10 * ) & V_261 . V_263 + 1 ) ;
V_2 -> V_280 = * ( ( T_10 * ) & V_261 . V_263 + 0 ) ;
break;
default:
V_11 = - V_281 ;
break;
}
F_108 ( V_2 ) ;
return V_11 ;
}
int F_130 ( void T_8 * V_184 )
{
struct V_1 * V_2 ;
struct V_282 * V_283 ;
struct V_260 * V_261 ;
int V_142 = 0 , V_284 , V_11 ;
T_10 V_285 ;
if ( F_131 ( V_285 , ( T_10 T_8 * ) V_184 ) )
return - V_189 ;
if ( ! V_285 || V_285 > ( V_286 * 2 ) / sizeof( * V_261 ) )
return - V_281 ;
V_284 = sizeof( * V_283 ) + V_285 * sizeof( * V_261 ) ;
V_283 = F_95 ( V_284 , V_195 ) ;
if ( ! V_283 )
return - V_196 ;
V_261 = V_283 -> V_287 ;
F_75 ( & V_129 ) ;
F_76 (hdev, &hci_dev_list, list) {
if ( F_121 ( V_252 , & V_2 -> V_76 ) )
F_120 ( & V_2 -> V_240 ) ;
if ( ! F_30 ( V_288 , & V_2 -> V_76 ) )
F_34 ( V_289 , & V_2 -> V_76 ) ;
( V_261 + V_142 ) -> V_190 = V_2 -> V_130 ;
( V_261 + V_142 ) -> V_263 = V_2 -> V_41 ;
if ( ++ V_142 >= V_285 )
break;
}
F_78 ( & V_129 ) ;
V_283 -> V_285 = V_142 ;
V_284 = sizeof( * V_283 ) + V_142 * sizeof( * V_261 ) ;
V_11 = F_107 ( V_184 , V_283 , V_284 ) ;
F_85 ( V_283 ) ;
return V_11 ? - V_189 : 0 ;
}
int F_132 ( void T_8 * V_184 )
{
struct V_1 * V_2 ;
struct V_290 V_291 ;
int V_11 = 0 ;
if ( F_101 ( & V_291 , V_184 , sizeof( V_291 ) ) )
return - V_189 ;
V_2 = F_74 ( V_291 . V_190 ) ;
if ( ! V_2 )
return - V_191 ;
if ( F_121 ( V_252 , & V_2 -> V_76 ) )
F_123 ( & V_2 -> V_240 ) ;
if ( ! F_30 ( V_288 , & V_2 -> V_76 ) )
F_34 ( V_289 , & V_2 -> V_76 ) ;
strcpy ( V_291 . V_5 , V_2 -> V_5 ) ;
V_291 . V_115 = V_2 -> V_115 ;
V_291 . type = ( V_2 -> V_292 & 0x0f ) | ( V_2 -> V_55 << 4 ) ;
V_291 . V_41 = V_2 -> V_41 ;
V_291 . V_274 = V_2 -> V_274 ;
if ( F_42 ( V_2 ) ) {
V_291 . V_276 = V_2 -> V_276 ;
V_291 . V_277 = V_2 -> V_277 ;
V_291 . V_279 = V_2 -> V_279 ;
V_291 . V_280 = V_2 -> V_280 ;
} else {
V_291 . V_276 = V_2 -> V_293 ;
V_291 . V_277 = V_2 -> V_294 ;
V_291 . V_279 = 0 ;
V_291 . V_280 = 0 ;
}
V_291 . V_101 = V_2 -> V_101 ;
V_291 . V_270 = V_2 -> V_270 ;
memcpy ( & V_291 . V_257 , & V_2 -> V_257 , sizeof( V_291 . V_257 ) ) ;
memcpy ( & V_291 . V_295 , & V_2 -> V_295 , sizeof( V_291 . V_295 ) ) ;
if ( F_107 ( V_184 , & V_291 , sizeof( V_291 ) ) )
V_11 = - V_189 ;
F_108 ( V_2 ) ;
return V_11 ;
}
static int F_133 ( void * V_24 , bool V_296 )
{
struct V_1 * V_2 = V_24 ;
F_4 ( L_21 , V_2 , V_2 -> V_5 , V_296 ) ;
if ( ! V_296 )
return 0 ;
F_119 ( V_2 ) ;
return 0 ;
}
static void F_134 ( struct V_297 * V_298 )
{
struct V_1 * V_2 = F_135 ( V_298 , struct V_1 , V_299 ) ;
int V_11 ;
F_4 ( L_7 , V_2 -> V_5 ) ;
V_11 = F_111 ( V_2 -> V_130 ) ;
if ( V_11 < 0 ) {
F_136 ( V_2 , V_11 ) ;
return;
}
if ( F_30 ( V_252 , & V_2 -> V_76 ) )
F_137 ( V_2 -> V_300 , & V_2 -> V_240 ,
V_301 ) ;
if ( F_121 ( V_227 , & V_2 -> V_76 ) )
F_138 ( V_2 ) ;
}
static void F_139 ( struct V_297 * V_298 )
{
struct V_1 * V_2 = F_135 ( V_298 , struct V_1 ,
V_240 . V_298 ) ;
F_4 ( L_7 , V_2 -> V_5 ) ;
F_119 ( V_2 ) ;
}
static void F_140 ( struct V_297 * V_298 )
{
struct V_1 * V_2 ;
T_1 V_122 = V_302 ;
V_2 = F_135 ( V_298 , struct V_1 , V_243 . V_298 ) ;
F_4 ( L_7 , V_2 -> V_5 ) ;
F_8 ( V_2 ) ;
F_141 ( V_2 , V_123 , sizeof( V_122 ) , & V_122 ) ;
V_2 -> V_242 = 0 ;
F_9 ( V_2 ) ;
}
int F_142 ( struct V_1 * V_2 )
{
struct V_303 * V_304 , * V_305 ;
F_83 (uuid, tmp, &hdev->uuids, list) {
F_84 ( & V_304 -> V_151 ) ;
F_85 ( V_304 ) ;
}
return 0 ;
}
int F_143 ( struct V_1 * V_2 )
{
struct V_149 * V_112 , * V_142 ;
F_144 (p, n, &hdev->link_keys) {
struct V_306 * V_307 ;
V_307 = F_145 ( V_112 , struct V_306 , V_151 ) ;
F_84 ( V_112 ) ;
F_85 ( V_307 ) ;
}
return 0 ;
}
int F_146 ( struct V_1 * V_2 )
{
struct V_308 * V_309 , * V_305 ;
F_83 (k, tmp, &hdev->long_term_keys, list) {
F_84 ( & V_309 -> V_151 ) ;
F_85 ( V_309 ) ;
}
return 0 ;
}
struct V_306 * F_147 ( struct V_1 * V_2 , T_7 * V_115 )
{
struct V_306 * V_309 ;
F_76 (k, &hdev->link_keys, list)
if ( F_88 ( V_115 , & V_309 -> V_115 ) == 0 )
return V_309 ;
return NULL ;
}
static bool F_148 ( struct V_1 * V_2 , struct V_310 * V_311 ,
T_1 V_312 , T_1 V_313 )
{
if ( V_312 < 0x03 )
return true ;
if ( V_312 == V_314 )
return false ;
if ( V_312 == V_315 && V_313 == 0xff )
return false ;
if ( ! V_311 )
return true ;
if ( V_311 -> V_316 > 0x01 && V_311 -> V_317 > 0x01 )
return true ;
if ( V_311 -> V_316 == 0x02 || V_311 -> V_316 == 0x03 )
return true ;
if ( V_311 -> V_317 == 0x02 || V_311 -> V_317 == 0x03 )
return true ;
return false ;
}
struct V_308 * F_149 ( struct V_1 * V_2 , T_5 V_318 , T_1 rand [ 8 ] )
{
struct V_308 * V_309 ;
F_76 (k, &hdev->long_term_keys, list) {
if ( V_309 -> V_318 != V_318 ||
memcmp ( rand , V_309 -> rand , sizeof( V_309 -> rand ) ) )
continue;
return V_309 ;
}
return NULL ;
}
struct V_308 * F_150 ( struct V_1 * V_2 , T_7 * V_115 ,
T_1 V_319 )
{
struct V_308 * V_309 ;
F_76 (k, &hdev->long_term_keys, list)
if ( V_319 == V_309 -> V_320 &&
F_88 ( V_115 , & V_309 -> V_115 ) == 0 )
return V_309 ;
return NULL ;
}
int F_151 ( struct V_1 * V_2 , struct V_310 * V_311 , int V_321 ,
T_7 * V_115 , T_1 * V_322 , T_1 type , T_1 V_323 )
{
struct V_306 * V_307 , * V_324 ;
T_1 V_313 ;
bool V_325 ;
V_324 = F_147 ( V_2 , V_115 ) ;
if ( V_324 ) {
V_313 = V_324 -> type ;
V_307 = V_324 ;
} else {
V_313 = V_311 ? V_311 -> V_312 : 0xff ;
V_307 = F_95 ( sizeof( * V_307 ) , V_160 ) ;
if ( ! V_307 )
return - V_196 ;
F_92 ( & V_307 -> V_151 , & V_2 -> V_326 ) ;
}
F_4 ( L_22 , V_2 -> V_5 , V_115 , type ) ;
if ( type == V_315 &&
( ! V_311 || V_311 -> V_317 == 0xff ) && V_313 == 0xff ) {
type = V_327 ;
if ( V_311 )
V_311 -> V_312 = type ;
}
F_67 ( & V_307 -> V_115 , V_115 ) ;
memcpy ( V_307 -> V_322 , V_322 , V_328 ) ;
V_307 -> V_323 = V_323 ;
if ( type == V_315 )
V_307 -> type = V_313 ;
else
V_307 -> type = type ;
if ( ! V_321 )
return 0 ;
V_325 = F_148 ( V_2 , V_311 , type , V_313 ) ;
F_152 ( V_2 , V_307 , V_325 ) ;
if ( V_311 )
V_311 -> V_329 = ! V_325 ;
return 0 ;
}
int F_153 ( struct V_1 * V_2 , T_7 * V_115 , T_1 V_319 , T_1 type ,
int V_321 , T_1 V_330 , T_1 V_331 [ 16 ] , T_1 V_332 , T_5
V_318 , T_1 rand [ 8 ] )
{
struct V_308 * V_307 , * V_324 ;
if ( ! ( type & V_333 ) && ! ( type & V_334 ) )
return 0 ;
V_324 = F_150 ( V_2 , V_115 , V_319 ) ;
if ( V_324 )
V_307 = V_324 ;
else {
V_307 = F_95 ( sizeof( * V_307 ) , V_160 ) ;
if ( ! V_307 )
return - V_196 ;
F_92 ( & V_307 -> V_151 , & V_2 -> V_335 ) ;
}
F_67 ( & V_307 -> V_115 , V_115 ) ;
V_307 -> V_320 = V_319 ;
memcpy ( V_307 -> V_322 , V_331 , sizeof( V_307 -> V_322 ) ) ;
V_307 -> V_330 = V_330 ;
V_307 -> V_318 = V_318 ;
V_307 -> V_332 = V_332 ;
V_307 -> type = type ;
memcpy ( V_307 -> rand , rand , sizeof( V_307 -> rand ) ) ;
if ( ! V_321 )
return 0 ;
if ( type & V_334 )
F_154 ( V_2 , V_307 , 1 ) ;
return 0 ;
}
int F_155 ( struct V_1 * V_2 , T_7 * V_115 )
{
struct V_306 * V_307 ;
V_307 = F_147 ( V_2 , V_115 ) ;
if ( ! V_307 )
return - V_336 ;
F_4 ( L_23 , V_2 -> V_5 , V_115 ) ;
F_84 ( & V_307 -> V_151 ) ;
F_85 ( V_307 ) ;
return 0 ;
}
int F_156 ( struct V_1 * V_2 , T_7 * V_115 )
{
struct V_308 * V_309 , * V_305 ;
F_83 (k, tmp, &hdev->long_term_keys, list) {
if ( F_88 ( V_115 , & V_309 -> V_115 ) )
continue;
F_4 ( L_23 , V_2 -> V_5 , V_115 ) ;
F_84 ( & V_309 -> V_151 ) ;
F_85 ( V_309 ) ;
}
return 0 ;
}
static void F_157 ( unsigned long V_184 )
{
struct V_1 * V_2 = ( void * ) V_184 ;
if ( V_2 -> V_238 ) {
struct V_337 * V_338 = ( void * ) V_2 -> V_238 -> V_24 ;
T_2 V_14 = F_13 ( V_338 -> V_14 ) ;
F_11 ( L_24 , V_2 -> V_5 , V_14 ) ;
} else {
F_11 ( L_25 , V_2 -> V_5 ) ;
}
F_113 ( & V_2 -> V_224 , 1 ) ;
F_158 ( V_2 -> V_339 , & V_2 -> V_233 ) ;
}
struct V_340 * F_159 ( struct V_1 * V_2 ,
T_7 * V_115 )
{
struct V_340 * V_24 ;
F_76 (data, &hdev->remote_oob_data, list)
if ( F_88 ( V_115 , & V_24 -> V_115 ) == 0 )
return V_24 ;
return NULL ;
}
int F_94 ( struct V_1 * V_2 , T_7 * V_115 )
{
struct V_340 * V_24 ;
V_24 = F_159 ( V_2 , V_115 ) ;
if ( ! V_24 )
return - V_336 ;
F_4 ( L_23 , V_2 -> V_5 , V_115 ) ;
F_84 ( & V_24 -> V_151 ) ;
F_85 ( V_24 ) ;
return 0 ;
}
int F_160 ( struct V_1 * V_2 )
{
struct V_340 * V_24 , * V_142 ;
F_83 (data, n, &hdev->remote_oob_data, list) {
F_84 ( & V_24 -> V_151 ) ;
F_85 ( V_24 ) ;
}
return 0 ;
}
int F_161 ( struct V_1 * V_2 , T_7 * V_115 , T_1 * V_341 ,
T_1 * V_342 )
{
struct V_340 * V_24 ;
V_24 = F_159 ( V_2 , V_115 ) ;
if ( ! V_24 ) {
V_24 = F_106 ( sizeof( * V_24 ) , V_160 ) ;
if ( ! V_24 )
return - V_196 ;
F_67 ( & V_24 -> V_115 , V_115 ) ;
F_92 ( & V_24 -> V_151 , & V_2 -> V_343 ) ;
}
memcpy ( V_24 -> V_341 , V_341 , sizeof( V_24 -> V_341 ) ) ;
memcpy ( V_24 -> V_342 , V_342 , sizeof( V_24 -> V_342 ) ) ;
F_4 ( L_26 , V_2 -> V_5 , V_115 ) ;
return 0 ;
}
struct V_344 * F_162 ( struct V_1 * V_2 , T_7 * V_115 )
{
struct V_344 * V_345 ;
F_76 (b, &hdev->blacklist, list)
if ( F_88 ( V_115 , & V_345 -> V_115 ) == 0 )
return V_345 ;
return NULL ;
}
int F_163 ( struct V_1 * V_2 )
{
struct V_149 * V_112 , * V_142 ;
F_144 (p, n, &hdev->blacklist) {
struct V_344 * V_345 ;
V_345 = F_145 ( V_112 , struct V_344 , V_151 ) ;
F_84 ( V_112 ) ;
F_85 ( V_345 ) ;
}
return 0 ;
}
int F_164 ( struct V_1 * V_2 , T_7 * V_115 , T_1 type )
{
struct V_344 * V_346 ;
if ( F_88 ( V_115 , V_116 ) == 0 )
return - V_347 ;
if ( F_162 ( V_2 , V_115 ) )
return - V_348 ;
V_346 = F_95 ( sizeof( struct V_344 ) , V_195 ) ;
if ( ! V_346 )
return - V_196 ;
F_67 ( & V_346 -> V_115 , V_115 ) ;
F_92 ( & V_346 -> V_151 , & V_2 -> V_349 ) ;
return F_165 ( V_2 , V_115 , type ) ;
}
int F_166 ( struct V_1 * V_2 , T_7 * V_115 , T_1 type )
{
struct V_344 * V_346 ;
if ( F_88 ( V_115 , V_116 ) == 0 )
return F_163 ( V_2 ) ;
V_346 = F_162 ( V_2 , V_115 ) ;
if ( ! V_346 )
return - V_336 ;
F_84 ( & V_346 -> V_151 ) ;
F_85 ( V_346 ) ;
return F_167 ( V_2 , V_115 , type ) ;
}
static void F_168 ( struct V_1 * V_2 , T_1 V_350 )
{
if ( V_350 ) {
F_11 ( L_27 , V_350 ) ;
F_8 ( V_2 ) ;
F_80 ( V_2 , V_137 ) ;
F_9 ( V_2 ) ;
return;
}
}
static void F_169 ( struct V_1 * V_2 , T_1 V_350 )
{
T_1 V_179 [ 3 ] = { 0x33 , 0x8b , 0x9e } ;
struct V_33 V_34 ;
struct V_177 V_90 ;
int V_11 ;
if ( V_350 ) {
F_11 ( L_28 , V_350 ) ;
return;
}
switch ( V_2 -> V_133 . type ) {
case V_351 :
F_8 ( V_2 ) ;
F_80 ( V_2 , V_137 ) ;
F_9 ( V_2 ) ;
break;
case V_352 :
F_17 ( & V_34 , V_2 ) ;
memset ( & V_90 , 0 , sizeof( V_90 ) ) ;
memcpy ( & V_90 . V_179 , V_179 , sizeof( V_90 . V_179 ) ) ;
V_90 . V_180 = V_353 ;
F_35 ( & V_34 , V_182 , sizeof( V_90 ) , & V_90 ) ;
F_8 ( V_2 ) ;
F_82 ( V_2 ) ;
V_11 = F_19 ( & V_34 , F_168 ) ;
if ( V_11 ) {
F_11 ( L_29 , V_11 ) ;
F_80 ( V_2 , V_137 ) ;
}
F_9 ( V_2 ) ;
break;
}
}
static void F_170 ( struct V_297 * V_298 )
{
struct V_1 * V_2 = F_135 ( V_298 , struct V_1 ,
V_247 . V_298 ) ;
struct V_354 V_90 ;
struct V_33 V_34 ;
int V_11 ;
F_4 ( L_7 , V_2 -> V_5 ) ;
F_17 ( & V_34 , V_2 ) ;
memset ( & V_90 , 0 , sizeof( V_90 ) ) ;
V_90 . V_98 = V_355 ;
F_35 ( & V_34 , V_356 , sizeof( V_90 ) , & V_90 ) ;
V_11 = F_19 ( & V_34 , F_169 ) ;
if ( V_11 )
F_11 ( L_30 , V_11 ) ;
}
struct V_1 * F_171 ( void )
{
struct V_1 * V_2 ;
V_2 = F_95 ( sizeof( struct V_1 ) , V_195 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_274 = ( V_357 | V_358 | V_359 ) ;
V_2 -> V_360 = ( V_361 ) ;
V_2 -> V_270 = ( V_272 ) ;
V_2 -> V_362 = 0x03 ;
V_2 -> V_363 = V_206 ;
V_2 -> V_205 = V_206 ;
V_2 -> V_364 = 800 ;
V_2 -> V_365 = 80 ;
F_172 ( & V_2 -> V_366 ) ;
F_172 ( & V_2 -> V_367 ) ;
F_86 ( & V_2 -> V_368 ) ;
F_86 ( & V_2 -> V_349 ) ;
F_86 ( & V_2 -> V_369 ) ;
F_86 ( & V_2 -> V_326 ) ;
F_86 ( & V_2 -> V_335 ) ;
F_86 ( & V_2 -> V_343 ) ;
F_86 ( & V_2 -> V_370 . V_151 ) ;
F_173 ( & V_2 -> V_234 , V_371 ) ;
F_173 ( & V_2 -> V_233 , V_372 ) ;
F_173 ( & V_2 -> V_232 , V_373 ) ;
F_173 ( & V_2 -> V_299 , F_134 ) ;
F_174 ( & V_2 -> V_240 , F_139 ) ;
F_174 ( & V_2 -> V_243 , F_140 ) ;
F_174 ( & V_2 -> V_247 , F_170 ) ;
F_175 ( & V_2 -> V_236 ) ;
F_175 ( & V_2 -> V_235 ) ;
F_175 ( & V_2 -> V_250 ) ;
F_176 ( & V_2 -> V_10 ) ;
F_177 ( & V_2 -> V_241 , F_157 , ( unsigned long ) V_2 ) ;
F_178 ( V_2 ) ;
F_179 ( V_2 ) ;
return V_2 ;
}
void F_180 ( struct V_1 * V_2 )
{
F_181 ( & V_2 -> V_217 ) ;
}
int F_182 ( struct V_1 * V_2 )
{
int V_130 , error ;
if ( ! V_2 -> V_222 || ! V_2 -> V_239 )
return - V_281 ;
switch ( V_2 -> V_55 ) {
case V_56 :
V_130 = F_183 ( & V_374 , 0 , 0 , V_195 ) ;
break;
case V_57 :
V_130 = F_183 ( & V_374 , 1 , 0 , V_195 ) ;
break;
default:
return - V_281 ;
}
if ( V_130 < 0 )
return V_130 ;
sprintf ( V_2 -> V_5 , L_31 , V_130 ) ;
V_2 -> V_130 = V_130 ;
F_4 ( L_32 , V_2 , V_2 -> V_5 , V_2 -> V_292 ) ;
V_2 -> V_339 = F_184 ( L_7 , V_375 | V_376 |
V_377 , 1 , V_2 -> V_5 ) ;
if ( ! V_2 -> V_339 ) {
error = - V_196 ;
goto V_11;
}
V_2 -> V_300 = F_184 ( L_7 , V_375 | V_376 |
V_377 , 1 , V_2 -> V_5 ) ;
if ( ! V_2 -> V_300 ) {
F_185 ( V_2 -> V_339 ) ;
error = - V_196 ;
goto V_11;
}
error = F_186 ( V_2 ) ;
if ( error < 0 )
goto V_378;
V_2 -> V_219 = F_187 ( V_2 -> V_5 , & V_2 -> V_217 ,
V_379 , & V_380 ,
V_2 ) ;
if ( V_2 -> V_219 ) {
if ( F_188 ( V_2 -> V_219 ) < 0 ) {
F_189 ( V_2 -> V_219 ) ;
V_2 -> V_219 = NULL ;
}
}
F_34 ( V_227 , & V_2 -> V_76 ) ;
if ( V_2 -> V_55 != V_57 )
F_34 ( V_252 , & V_2 -> V_76 ) ;
F_190 ( & V_129 ) ;
F_92 ( & V_2 -> V_151 , & V_381 ) ;
F_191 ( & V_129 ) ;
F_1 ( V_2 , V_382 ) ;
F_77 ( V_2 ) ;
F_158 ( V_2 -> V_300 , & V_2 -> V_299 ) ;
return V_130 ;
V_378:
F_185 ( V_2 -> V_339 ) ;
F_185 ( V_2 -> V_300 ) ;
V_11:
F_192 ( & V_374 , V_2 -> V_130 ) ;
return error ;
}
void F_193 ( struct V_1 * V_2 )
{
int V_383 , V_130 ;
F_4 ( L_32 , V_2 , V_2 -> V_5 , V_2 -> V_292 ) ;
F_34 ( V_218 , & V_2 -> V_76 ) ;
V_130 = V_2 -> V_130 ;
F_190 ( & V_129 ) ;
F_84 ( & V_2 -> V_151 ) ;
F_191 ( & V_129 ) ;
F_119 ( V_2 ) ;
for ( V_383 = 0 ; V_383 < V_384 ; V_383 ++ )
F_14 ( V_2 -> V_385 [ V_383 ] ) ;
F_194 ( & V_2 -> V_299 ) ;
if ( ! F_30 ( V_225 , & V_2 -> V_41 ) &&
! F_30 ( V_227 , & V_2 -> V_76 ) ) {
F_8 ( V_2 ) ;
F_195 ( V_2 ) ;
F_9 ( V_2 ) ;
}
F_196 ( ! F_197 ( & V_2 -> V_368 ) ) ;
F_1 ( V_2 , V_386 ) ;
if ( V_2 -> V_219 ) {
F_198 ( V_2 -> V_219 ) ;
F_189 ( V_2 -> V_219 ) ;
}
F_199 ( V_2 ) ;
F_185 ( V_2 -> V_339 ) ;
F_185 ( V_2 -> V_300 ) ;
F_8 ( V_2 ) ;
F_163 ( V_2 ) ;
F_142 ( V_2 ) ;
F_143 ( V_2 ) ;
F_146 ( V_2 ) ;
F_160 ( V_2 ) ;
F_9 ( V_2 ) ;
F_108 ( V_2 ) ;
F_192 ( & V_374 , V_130 ) ;
}
int F_200 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_387 ) ;
return 0 ;
}
int F_201 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_388 ) ;
return 0 ;
}
int F_202 ( struct V_13 * V_19 )
{
struct V_1 * V_2 = (struct V_1 * ) V_19 -> V_217 ;
if ( ! V_2 || ( ! F_30 ( V_40 , & V_2 -> V_41 )
&& ! F_30 ( V_225 , & V_2 -> V_41 ) ) ) {
F_14 ( V_19 ) ;
return - V_389 ;
}
F_203 ( V_19 ) -> V_390 = 1 ;
F_204 ( V_19 ) ;
F_205 ( & V_2 -> V_236 , V_19 ) ;
F_158 ( V_2 -> V_339 , & V_2 -> V_234 ) ;
return 0 ;
}
static int F_206 ( struct V_1 * V_2 , int type , void * V_24 ,
int V_391 , T_6 V_127 )
{
int V_22 = 0 ;
int V_392 = 0 ;
int V_393 = V_391 ;
struct V_13 * V_19 ;
struct V_394 * V_395 ;
if ( ( type < V_396 || type > V_397 ) ||
V_127 >= V_384 )
return - V_398 ;
V_19 = V_2 -> V_385 [ V_127 ] ;
if ( ! V_19 ) {
switch ( type ) {
case V_396 :
V_22 = V_399 ;
V_392 = V_400 ;
break;
case V_397 :
V_22 = V_401 ;
V_392 = V_25 ;
break;
case V_402 :
V_22 = V_403 ;
V_392 = V_404 ;
break;
}
V_19 = F_207 ( V_22 , V_160 ) ;
if ( ! V_19 )
return - V_196 ;
V_395 = ( void * ) V_19 -> V_405 ;
V_395 -> V_406 = V_392 ;
V_395 -> V_274 = type ;
V_19 -> V_217 = ( void * ) V_2 ;
V_2 -> V_385 [ V_127 ] = V_19 ;
}
while ( V_391 ) {
V_395 = ( void * ) V_19 -> V_405 ;
V_22 = F_208 ( V_407 , V_395 -> V_406 , V_391 ) ;
memcpy ( F_209 ( V_19 , V_22 ) , V_24 , V_22 ) ;
V_391 -= V_22 ;
V_24 += V_22 ;
V_395 -> V_406 -= V_22 ;
V_393 = V_391 ;
switch ( type ) {
case V_397 :
if ( V_19 -> V_22 == V_25 ) {
struct V_17 * V_408 = V_17 ( V_19 ) ;
V_395 -> V_406 = V_408 -> V_28 ;
if ( F_210 ( V_19 ) < V_395 -> V_406 ) {
F_14 ( V_19 ) ;
V_2 -> V_385 [ V_127 ] = NULL ;
return - V_196 ;
}
}
break;
case V_396 :
if ( V_19 -> V_22 == V_400 ) {
struct V_409 * V_408 = V_409 ( V_19 ) ;
V_395 -> V_406 = F_13 ( V_408 -> V_410 ) ;
if ( F_210 ( V_19 ) < V_395 -> V_406 ) {
F_14 ( V_19 ) ;
V_2 -> V_385 [ V_127 ] = NULL ;
return - V_196 ;
}
}
break;
case V_402 :
if ( V_19 -> V_22 == V_404 ) {
struct V_411 * V_408 = V_411 ( V_19 ) ;
V_395 -> V_406 = V_408 -> V_410 ;
if ( F_210 ( V_19 ) < V_395 -> V_406 ) {
F_14 ( V_19 ) ;
V_2 -> V_385 [ V_127 ] = NULL ;
return - V_196 ;
}
}
break;
}
if ( V_395 -> V_406 == 0 ) {
F_203 ( V_19 ) -> V_274 = type ;
F_202 ( V_19 ) ;
V_2 -> V_385 [ V_127 ] = NULL ;
return V_393 ;
}
}
return V_393 ;
}
int F_211 ( struct V_1 * V_2 , int type , void * V_24 , int V_391 )
{
int V_412 = 0 ;
if ( type < V_396 || type > V_397 )
return - V_398 ;
while ( V_391 ) {
V_412 = F_206 ( V_2 , type , V_24 , V_391 , type - 1 ) ;
if ( V_412 < 0 )
return V_412 ;
V_24 += ( V_391 - V_412 ) ;
V_391 = V_412 ;
}
return V_412 ;
}
int F_212 ( struct V_1 * V_2 , void * V_24 , int V_391 )
{
int type ;
int V_412 = 0 ;
while ( V_391 ) {
struct V_13 * V_19 = V_2 -> V_385 [ V_413 ] ;
if ( ! V_19 ) {
struct { char type ; } * V_414 ;
V_414 = V_24 ;
type = V_414 -> type ;
V_24 ++ ;
V_391 -- ;
} else
type = F_203 ( V_19 ) -> V_274 ;
V_412 = F_206 ( V_2 , type , V_24 , V_391 ,
V_413 ) ;
if ( V_412 < 0 )
return V_412 ;
V_24 += ( V_391 - V_412 ) ;
V_391 = V_412 ;
}
return V_412 ;
}
int F_213 ( struct V_415 * V_405 )
{
F_4 ( L_33 , V_405 , V_405 -> V_5 ) ;
F_190 ( & V_416 ) ;
F_92 ( & V_405 -> V_151 , & V_417 ) ;
F_191 ( & V_416 ) ;
return 0 ;
}
int F_214 ( struct V_415 * V_405 )
{
F_4 ( L_33 , V_405 , V_405 -> V_5 ) ;
F_190 ( & V_416 ) ;
F_84 ( & V_405 -> V_151 ) ;
F_191 ( & V_416 ) ;
return 0 ;
}
static int F_215 ( struct V_13 * V_19 )
{
struct V_1 * V_2 = (struct V_1 * ) V_19 -> V_217 ;
if ( ! V_2 ) {
F_14 ( V_19 ) ;
return - V_191 ;
}
F_4 ( L_34 , V_2 -> V_5 , F_203 ( V_19 ) -> V_274 , V_19 -> V_22 ) ;
F_204 ( V_19 ) ;
F_216 ( V_2 , V_19 ) ;
if ( F_217 ( & V_2 -> V_418 ) ) {
F_218 ( V_2 , V_19 ) ;
}
F_219 ( V_19 ) ;
return V_2 -> V_419 ( V_19 ) ;
}
void F_17 ( struct V_33 * V_34 , struct V_1 * V_2 )
{
F_175 ( & V_34 -> V_235 ) ;
V_34 -> V_2 = V_2 ;
V_34 -> V_11 = 0 ;
}
int F_19 ( struct V_33 * V_34 , T_11 V_420 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_13 * V_19 ;
unsigned long V_41 ;
F_4 ( L_35 , F_220 ( & V_34 -> V_235 ) ) ;
if ( V_34 -> V_11 ) {
F_118 ( & V_34 -> V_235 ) ;
return V_34 -> V_11 ;
}
if ( F_221 ( & V_34 -> V_235 ) )
return - V_21 ;
V_19 = F_222 ( & V_34 -> V_235 ) ;
F_203 ( V_19 ) -> V_34 . V_420 = V_420 ;
F_223 ( & V_2 -> V_235 . V_366 , V_41 ) ;
F_224 ( & V_34 -> V_235 , & V_2 -> V_235 ) ;
F_225 ( & V_2 -> V_235 . V_366 , V_41 ) ;
F_158 ( V_2 -> V_339 , & V_2 -> V_233 ) ;
return 0 ;
}
static struct V_13 * F_226 ( struct V_1 * V_2 , T_2 V_14 ,
T_3 V_28 , const void * V_29 )
{
int V_22 = V_421 + V_28 ;
struct V_337 * V_18 ;
struct V_13 * V_19 ;
V_19 = F_207 ( V_22 , V_160 ) ;
if ( ! V_19 )
return NULL ;
V_18 = (struct V_337 * ) F_209 ( V_19 , V_421 ) ;
V_18 -> V_14 = F_62 ( V_14 ) ;
V_18 -> V_28 = V_28 ;
if ( V_28 )
memcpy ( F_209 ( V_19 , V_28 ) , V_29 , V_28 ) ;
F_4 ( L_36 , V_19 -> V_22 ) ;
F_203 ( V_19 ) -> V_274 = V_422 ;
V_19 -> V_217 = ( void * ) V_2 ;
return V_19 ;
}
int F_141 ( struct V_1 * V_2 , T_10 V_14 , T_4 V_28 ,
const void * V_29 )
{
struct V_13 * V_19 ;
F_4 ( L_37 , V_2 -> V_5 , V_14 , V_28 ) ;
V_19 = F_226 ( V_2 , V_14 , V_28 , V_29 ) ;
if ( ! V_19 ) {
F_11 ( L_38 , V_2 -> V_5 ) ;
return - V_196 ;
}
F_203 ( V_19 ) -> V_34 . V_423 = true ;
F_205 ( & V_2 -> V_235 , V_19 ) ;
F_158 ( V_2 -> V_339 , & V_2 -> V_233 ) ;
return 0 ;
}
void F_18 ( struct V_33 * V_34 , T_2 V_14 , T_3 V_28 ,
const void * V_29 , T_1 V_3 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_13 * V_19 ;
F_4 ( L_37 , V_2 -> V_5 , V_14 , V_28 ) ;
if ( V_34 -> V_11 )
return;
V_19 = F_226 ( V_2 , V_14 , V_28 , V_29 ) ;
if ( ! V_19 ) {
F_11 ( L_39 ,
V_2 -> V_5 , V_14 ) ;
V_34 -> V_11 = - V_196 ;
return;
}
if ( F_221 ( & V_34 -> V_235 ) )
F_203 ( V_19 ) -> V_34 . V_423 = true ;
F_203 ( V_19 ) -> V_34 . V_3 = V_3 ;
F_205 ( & V_34 -> V_235 , V_19 ) ;
}
void F_35 ( struct V_33 * V_34 , T_2 V_14 , T_3 V_28 ,
const void * V_29 )
{
F_18 ( V_34 , V_14 , V_28 , V_29 , 0 ) ;
}
void * F_227 ( struct V_1 * V_2 , T_10 V_14 )
{
struct V_337 * V_18 ;
if ( ! V_2 -> V_238 )
return NULL ;
V_18 = ( void * ) V_2 -> V_238 -> V_24 ;
if ( V_18 -> V_14 != F_62 ( V_14 ) )
return NULL ;
F_4 ( L_40 , V_2 -> V_5 , V_14 ) ;
return V_2 -> V_238 -> V_24 + V_421 ;
}
static void F_228 ( struct V_13 * V_19 , T_10 V_424 , T_10 V_41 )
{
struct V_409 * V_18 ;
int V_22 = V_19 -> V_22 ;
F_229 ( V_19 , V_400 ) ;
F_230 ( V_19 ) ;
V_18 = (struct V_409 * ) F_231 ( V_19 ) ;
V_18 -> V_424 = F_62 ( F_232 ( V_424 , V_41 ) ) ;
V_18 -> V_410 = F_62 ( V_22 ) ;
}
static void F_233 ( struct V_425 * V_426 , struct V_427 * V_428 ,
struct V_13 * V_19 , T_10 V_41 )
{
struct V_310 * V_311 = V_426 -> V_311 ;
struct V_1 * V_2 = V_311 -> V_2 ;
struct V_13 * V_151 ;
V_19 -> V_22 = F_234 ( V_19 ) ;
V_19 -> V_429 = 0 ;
F_203 ( V_19 ) -> V_274 = V_396 ;
switch ( V_2 -> V_55 ) {
case V_56 :
F_228 ( V_19 , V_311 -> V_424 , V_41 ) ;
break;
case V_57 :
F_228 ( V_19 , V_426 -> V_424 , V_41 ) ;
break;
default:
F_11 ( L_41 , V_2 -> V_5 , V_2 -> V_55 ) ;
return;
}
V_151 = F_235 ( V_19 ) -> V_430 ;
if ( ! V_151 ) {
F_4 ( L_42 , V_2 -> V_5 , V_19 , V_19 -> V_22 ) ;
F_205 ( V_428 , V_19 ) ;
} else {
F_4 ( L_43 , V_2 -> V_5 , V_19 , V_19 -> V_22 ) ;
F_235 ( V_19 ) -> V_430 = NULL ;
F_236 ( & V_428 -> V_366 ) ;
F_237 ( V_428 , V_19 ) ;
V_41 &= ~ V_431 ;
V_41 |= V_432 ;
do {
V_19 = V_151 ; V_151 = V_151 -> V_433 ;
V_19 -> V_217 = ( void * ) V_2 ;
F_203 ( V_19 ) -> V_274 = V_396 ;
F_228 ( V_19 , V_311 -> V_424 , V_41 ) ;
F_4 ( L_43 , V_2 -> V_5 , V_19 , V_19 -> V_22 ) ;
F_237 ( V_428 , V_19 ) ;
} while ( V_151 );
F_238 ( & V_428 -> V_366 ) ;
}
}
void F_239 ( struct V_425 * V_426 , struct V_13 * V_19 , T_10 V_41 )
{
struct V_1 * V_2 = V_426 -> V_311 -> V_2 ;
F_4 ( L_44 , V_2 -> V_5 , V_426 , V_41 ) ;
V_19 -> V_217 = ( void * ) V_2 ;
F_233 ( V_426 , & V_426 -> V_434 , V_19 , V_41 ) ;
F_158 ( V_2 -> V_339 , & V_2 -> V_232 ) ;
}
void F_240 ( struct V_310 * V_311 , struct V_13 * V_19 )
{
struct V_1 * V_2 = V_311 -> V_2 ;
struct V_411 V_18 ;
F_4 ( L_45 , V_2 -> V_5 , V_19 -> V_22 ) ;
V_18 . V_424 = F_62 ( V_311 -> V_424 ) ;
V_18 . V_410 = V_19 -> V_22 ;
F_229 ( V_19 , V_404 ) ;
F_230 ( V_19 ) ;
memcpy ( F_231 ( V_19 ) , & V_18 , V_404 ) ;
V_19 -> V_217 = ( void * ) V_2 ;
F_203 ( V_19 ) -> V_274 = V_402 ;
F_205 ( & V_311 -> V_434 , V_19 ) ;
F_158 ( V_2 -> V_339 , & V_2 -> V_232 ) ;
}
static struct V_310 * F_241 ( struct V_1 * V_2 , T_6 type ,
int * V_435 )
{
struct V_436 * V_408 = & V_2 -> V_370 ;
struct V_310 * V_311 = NULL , * V_437 ;
unsigned int V_165 = 0 , V_438 = ~ 0 ;
F_242 () ;
F_243 (c, &h->list, list) {
if ( V_437 -> type != type || F_221 ( & V_437 -> V_434 ) )
continue;
if ( V_437 -> V_134 != V_439 && V_437 -> V_134 != V_440 )
continue;
V_165 ++ ;
if ( V_437 -> V_338 < V_438 ) {
V_438 = V_437 -> V_338 ;
V_311 = V_437 ;
}
if ( F_244 ( V_2 , type ) == V_165 )
break;
}
F_245 () ;
if ( V_311 ) {
int V_441 , V_442 ;
switch ( V_311 -> type ) {
case V_443 :
V_441 = V_2 -> V_254 ;
break;
case V_444 :
case V_445 :
V_441 = V_2 -> V_255 ;
break;
case V_446 :
V_441 = V_2 -> V_293 ? V_2 -> V_256 : V_2 -> V_254 ;
break;
default:
V_441 = 0 ;
F_11 ( L_46 ) ;
}
V_442 = V_441 / V_165 ;
* V_435 = V_442 ? V_442 : 1 ;
} else
* V_435 = 0 ;
F_4 ( L_47 , V_311 , * V_435 ) ;
return V_311 ;
}
static void F_246 ( struct V_1 * V_2 , T_6 type )
{
struct V_436 * V_408 = & V_2 -> V_370 ;
struct V_310 * V_437 ;
F_11 ( L_48 , V_2 -> V_5 ) ;
F_242 () ;
F_243 (c, &h->list, list) {
if ( V_437 -> type == type && V_437 -> V_338 ) {
F_11 ( L_49 ,
V_2 -> V_5 , & V_437 -> V_447 ) ;
F_247 ( V_437 , V_448 ) ;
}
}
F_245 () ;
}
static struct V_425 * F_248 ( struct V_1 * V_2 , T_6 type ,
int * V_435 )
{
struct V_436 * V_408 = & V_2 -> V_370 ;
struct V_425 * V_426 = NULL ;
unsigned int V_165 = 0 , V_438 = ~ 0 , V_449 = 0 ;
struct V_310 * V_311 ;
int V_441 , V_442 , V_450 = 0 ;
F_4 ( L_7 , V_2 -> V_5 ) ;
F_242 () ;
F_243 (conn, &h->list, list) {
struct V_425 * V_305 ;
if ( V_311 -> type != type )
continue;
if ( V_311 -> V_134 != V_439 && V_311 -> V_134 != V_440 )
continue;
V_450 ++ ;
F_243 (tmp, &conn->chan_list, list) {
struct V_13 * V_19 ;
if ( F_221 ( & V_305 -> V_434 ) )
continue;
V_19 = F_249 ( & V_305 -> V_434 ) ;
if ( V_19 -> V_451 < V_449 )
continue;
if ( V_19 -> V_451 > V_449 ) {
V_165 = 0 ;
V_438 = ~ 0 ;
V_449 = V_19 -> V_451 ;
}
V_165 ++ ;
if ( V_311 -> V_338 < V_438 ) {
V_438 = V_311 -> V_338 ;
V_426 = V_305 ;
}
}
if ( F_244 ( V_2 , type ) == V_450 )
break;
}
F_245 () ;
if ( ! V_426 )
return NULL ;
switch ( V_426 -> V_311 -> type ) {
case V_443 :
V_441 = V_2 -> V_254 ;
break;
case V_452 :
V_441 = V_2 -> V_453 ;
break;
case V_444 :
case V_445 :
V_441 = V_2 -> V_255 ;
break;
case V_446 :
V_441 = V_2 -> V_293 ? V_2 -> V_256 : V_2 -> V_254 ;
break;
default:
V_441 = 0 ;
F_11 ( L_46 ) ;
}
V_442 = V_441 / V_165 ;
* V_435 = V_442 ? V_442 : 1 ;
F_4 ( L_50 , V_426 , * V_435 ) ;
return V_426 ;
}
static void F_250 ( struct V_1 * V_2 , T_6 type )
{
struct V_436 * V_408 = & V_2 -> V_370 ;
struct V_310 * V_311 ;
int V_165 = 0 ;
F_4 ( L_7 , V_2 -> V_5 ) ;
F_242 () ;
F_243 (conn, &h->list, list) {
struct V_425 * V_426 ;
if ( V_311 -> type != type )
continue;
if ( V_311 -> V_134 != V_439 && V_311 -> V_134 != V_440 )
continue;
V_165 ++ ;
F_243 (chan, &conn->chan_list, list) {
struct V_13 * V_19 ;
if ( V_426 -> V_338 ) {
V_426 -> V_338 = 0 ;
continue;
}
if ( F_221 ( & V_426 -> V_434 ) )
continue;
V_19 = F_249 ( & V_426 -> V_434 ) ;
if ( V_19 -> V_451 >= V_454 - 1 )
continue;
V_19 -> V_451 = V_454 - 1 ;
F_4 ( L_51 , V_426 , V_19 ,
V_19 -> V_451 ) ;
}
if ( F_244 ( V_2 , type ) == V_165 )
break;
}
F_245 () ;
}
static inline int F_251 ( struct V_1 * V_2 , struct V_13 * V_19 )
{
return F_252 ( V_19 -> V_22 - V_400 , V_2 -> V_455 ) ;
}
static void F_253 ( struct V_1 * V_2 , unsigned int V_441 )
{
if ( ! F_30 ( V_229 , & V_2 -> V_41 ) ) {
if ( ! V_441 && F_254 ( V_164 , V_2 -> V_456 +
V_457 ) )
F_246 ( V_2 , V_443 ) ;
}
}
static void F_255 ( struct V_1 * V_2 )
{
unsigned int V_441 = V_2 -> V_254 ;
struct V_425 * V_426 ;
struct V_13 * V_19 ;
int V_435 ;
F_253 ( V_2 , V_441 ) ;
while ( V_2 -> V_254 &&
( V_426 = F_248 ( V_2 , V_443 , & V_435 ) ) ) {
T_3 V_451 = ( F_249 ( & V_426 -> V_434 ) ) -> V_451 ;
while ( V_435 -- && ( V_19 = F_249 ( & V_426 -> V_434 ) ) ) {
F_4 ( L_52 , V_426 , V_19 ,
V_19 -> V_22 , V_19 -> V_451 ) ;
if ( V_19 -> V_451 < V_451 )
break;
V_19 = F_256 ( & V_426 -> V_434 ) ;
F_257 ( V_426 -> V_311 ,
F_203 ( V_19 ) -> V_458 ) ;
F_215 ( V_19 ) ;
V_2 -> V_456 = V_164 ;
V_2 -> V_254 -- ;
V_426 -> V_338 ++ ;
V_426 -> V_311 -> V_338 ++ ;
}
}
if ( V_441 != V_2 -> V_254 )
F_250 ( V_2 , V_443 ) ;
}
static void F_258 ( struct V_1 * V_2 )
{
unsigned int V_441 = V_2 -> V_453 ;
struct V_425 * V_426 ;
struct V_13 * V_19 ;
int V_435 ;
T_1 type ;
F_253 ( V_2 , V_441 ) ;
F_4 ( L_7 , V_2 -> V_5 ) ;
if ( V_2 -> V_55 == V_57 )
type = V_452 ;
else
type = V_443 ;
while ( V_2 -> V_453 > 0 &&
( V_426 = F_248 ( V_2 , type , & V_435 ) ) ) {
T_3 V_451 = ( F_249 ( & V_426 -> V_434 ) ) -> V_451 ;
while ( V_435 > 0 && ( V_19 = F_249 ( & V_426 -> V_434 ) ) ) {
int V_459 ;
F_4 ( L_52 , V_426 , V_19 ,
V_19 -> V_22 , V_19 -> V_451 ) ;
if ( V_19 -> V_451 < V_451 )
break;
V_19 = F_256 ( & V_426 -> V_434 ) ;
V_459 = F_251 ( V_2 , V_19 ) ;
if ( V_459 > V_2 -> V_453 )
return;
F_257 ( V_426 -> V_311 ,
F_203 ( V_19 ) -> V_458 ) ;
F_215 ( V_19 ) ;
V_2 -> V_456 = V_164 ;
V_2 -> V_453 -= V_459 ;
V_435 -= V_459 ;
V_426 -> V_338 += V_459 ;
V_426 -> V_311 -> V_338 += V_459 ;
}
}
if ( V_441 != V_2 -> V_453 )
F_250 ( V_2 , type ) ;
}
static void F_259 ( struct V_1 * V_2 )
{
F_4 ( L_7 , V_2 -> V_5 ) ;
if ( ! F_244 ( V_2 , V_443 ) && V_2 -> V_55 == V_56 )
return;
if ( ! F_244 ( V_2 , V_452 ) && V_2 -> V_55 == V_57 )
return;
switch ( V_2 -> V_45 ) {
case V_46 :
F_255 ( V_2 ) ;
break;
case V_50 :
F_258 ( V_2 ) ;
break;
}
}
static void F_260 ( struct V_1 * V_2 )
{
struct V_310 * V_311 ;
struct V_13 * V_19 ;
int V_435 ;
F_4 ( L_7 , V_2 -> V_5 ) ;
if ( ! F_244 ( V_2 , V_444 ) )
return;
while ( V_2 -> V_255 && ( V_311 = F_241 ( V_2 , V_444 , & V_435 ) ) ) {
while ( V_435 -- && ( V_19 = F_256 ( & V_311 -> V_434 ) ) ) {
F_4 ( L_53 , V_19 , V_19 -> V_22 ) ;
F_215 ( V_19 ) ;
V_311 -> V_338 ++ ;
if ( V_311 -> V_338 == ~ 0 )
V_311 -> V_338 = 0 ;
}
}
}
static void F_261 ( struct V_1 * V_2 )
{
struct V_310 * V_311 ;
struct V_13 * V_19 ;
int V_435 ;
F_4 ( L_7 , V_2 -> V_5 ) ;
if ( ! F_244 ( V_2 , V_445 ) )
return;
while ( V_2 -> V_255 && ( V_311 = F_241 ( V_2 , V_445 ,
& V_435 ) ) ) {
while ( V_435 -- && ( V_19 = F_256 ( & V_311 -> V_434 ) ) ) {
F_4 ( L_53 , V_19 , V_19 -> V_22 ) ;
F_215 ( V_19 ) ;
V_311 -> V_338 ++ ;
if ( V_311 -> V_338 == ~ 0 )
V_311 -> V_338 = 0 ;
}
}
}
static void F_262 ( struct V_1 * V_2 )
{
struct V_425 * V_426 ;
struct V_13 * V_19 ;
int V_435 , V_441 , V_305 ;
F_4 ( L_7 , V_2 -> V_5 ) ;
if ( ! F_244 ( V_2 , V_446 ) )
return;
if ( ! F_30 ( V_229 , & V_2 -> V_41 ) ) {
if ( ! V_2 -> V_256 && V_2 -> V_294 &&
F_254 ( V_164 , V_2 -> V_460 + V_461 * 45 ) )
F_246 ( V_2 , V_446 ) ;
}
V_441 = V_2 -> V_294 ? V_2 -> V_256 : V_2 -> V_254 ;
V_305 = V_441 ;
while ( V_441 && ( V_426 = F_248 ( V_2 , V_446 , & V_435 ) ) ) {
T_3 V_451 = ( F_249 ( & V_426 -> V_434 ) ) -> V_451 ;
while ( V_435 -- && ( V_19 = F_249 ( & V_426 -> V_434 ) ) ) {
F_4 ( L_52 , V_426 , V_19 ,
V_19 -> V_22 , V_19 -> V_451 ) ;
if ( V_19 -> V_451 < V_451 )
break;
V_19 = F_256 ( & V_426 -> V_434 ) ;
F_215 ( V_19 ) ;
V_2 -> V_460 = V_164 ;
V_441 -- ;
V_426 -> V_338 ++ ;
V_426 -> V_311 -> V_338 ++ ;
}
}
if ( V_2 -> V_294 )
V_2 -> V_256 = V_441 ;
else
V_2 -> V_254 = V_441 ;
if ( V_441 != V_305 )
F_250 ( V_2 , V_446 ) ;
}
static void V_373 ( struct V_297 * V_298 )
{
struct V_1 * V_2 = F_135 ( V_298 , struct V_1 , V_232 ) ;
struct V_13 * V_19 ;
F_4 ( L_54 , V_2 -> V_5 , V_2 -> V_254 ,
V_2 -> V_255 , V_2 -> V_256 ) ;
F_259 ( V_2 ) ;
F_260 ( V_2 ) ;
F_261 ( V_2 ) ;
F_262 ( V_2 ) ;
while ( ( V_19 = F_256 ( & V_2 -> V_250 ) ) )
F_215 ( V_19 ) ;
}
static void F_263 ( struct V_1 * V_2 , struct V_13 * V_19 )
{
struct V_409 * V_18 = ( void * ) V_19 -> V_24 ;
struct V_310 * V_311 ;
T_10 V_424 , V_41 ;
F_12 ( V_19 , V_400 ) ;
V_424 = F_13 ( V_18 -> V_424 ) ;
V_41 = F_264 ( V_424 ) ;
V_424 = F_265 ( V_424 ) ;
F_4 ( L_55 , V_2 -> V_5 , V_19 -> V_22 ,
V_424 , V_41 ) ;
V_2 -> V_257 . V_462 ++ ;
F_8 ( V_2 ) ;
V_311 = F_266 ( V_2 , V_424 ) ;
F_9 ( V_2 ) ;
if ( V_311 ) {
F_257 ( V_311 , V_463 ) ;
F_267 ( V_311 , V_19 , V_41 ) ;
return;
} else {
F_11 ( L_56 ,
V_2 -> V_5 , V_424 ) ;
}
F_14 ( V_19 ) ;
}
static void F_268 ( struct V_1 * V_2 , struct V_13 * V_19 )
{
struct V_411 * V_18 = ( void * ) V_19 -> V_24 ;
struct V_310 * V_311 ;
T_10 V_424 ;
F_12 ( V_19 , V_404 ) ;
V_424 = F_13 ( V_18 -> V_424 ) ;
F_4 ( L_57 , V_2 -> V_5 , V_19 -> V_22 , V_424 ) ;
V_2 -> V_257 . V_464 ++ ;
F_8 ( V_2 ) ;
V_311 = F_266 ( V_2 , V_424 ) ;
F_9 ( V_2 ) ;
if ( V_311 ) {
F_269 ( V_311 , V_19 ) ;
return;
} else {
F_11 ( L_58 ,
V_2 -> V_5 , V_424 ) ;
}
F_14 ( V_19 ) ;
}
static bool F_270 ( struct V_1 * V_2 )
{
struct V_13 * V_19 ;
V_19 = F_249 ( & V_2 -> V_235 ) ;
if ( ! V_19 )
return true ;
return F_203 ( V_19 ) -> V_34 . V_423 ;
}
static void F_271 ( struct V_1 * V_2 )
{
struct V_337 * V_338 ;
struct V_13 * V_19 ;
T_2 V_14 ;
if ( ! V_2 -> V_238 )
return;
V_338 = ( void * ) V_2 -> V_238 -> V_24 ;
V_14 = F_13 ( V_338 -> V_14 ) ;
if ( V_14 == V_44 )
return;
V_19 = F_272 ( V_2 -> V_238 , V_195 ) ;
if ( ! V_19 )
return;
F_273 ( & V_2 -> V_235 , V_19 ) ;
F_158 ( V_2 -> V_339 , & V_2 -> V_233 ) ;
}
void F_274 ( struct V_1 * V_2 , T_2 V_14 , T_1 V_350 )
{
T_11 V_465 = NULL ;
struct V_13 * V_19 ;
unsigned long V_41 ;
F_4 ( L_59 , V_14 , V_350 ) ;
if ( ! F_227 ( V_2 , V_14 ) ) {
if ( F_30 ( V_225 , & V_2 -> V_41 ) && V_14 == V_44 )
F_271 ( V_2 ) ;
return;
}
if ( ! V_350 && ! F_270 ( V_2 ) )
return;
if ( V_2 -> V_238 ) {
V_465 = F_203 ( V_2 -> V_238 ) -> V_34 . V_420 ;
if ( V_465 ) {
F_203 ( V_2 -> V_238 ) -> V_34 . V_420 = NULL ;
goto V_466;
}
}
F_223 ( & V_2 -> V_235 . V_366 , V_41 ) ;
while ( ( V_19 = F_275 ( & V_2 -> V_235 ) ) ) {
if ( F_203 ( V_19 ) -> V_34 . V_423 ) {
F_276 ( & V_2 -> V_235 , V_19 ) ;
break;
}
V_465 = F_203 ( V_19 ) -> V_34 . V_420 ;
F_14 ( V_19 ) ;
}
F_225 ( & V_2 -> V_235 . V_366 , V_41 ) ;
V_466:
if ( V_465 )
V_465 ( V_2 , V_350 ) ;
}
static void V_371 ( struct V_297 * V_298 )
{
struct V_1 * V_2 = F_135 ( V_298 , struct V_1 , V_234 ) ;
struct V_13 * V_19 ;
F_4 ( L_7 , V_2 -> V_5 ) ;
while ( ( V_19 = F_256 ( & V_2 -> V_236 ) ) ) {
F_216 ( V_2 , V_19 ) ;
if ( F_217 ( & V_2 -> V_418 ) ) {
F_218 ( V_2 , V_19 ) ;
}
if ( F_30 ( V_229 , & V_2 -> V_41 ) ) {
F_14 ( V_19 ) ;
continue;
}
if ( F_30 ( V_225 , & V_2 -> V_41 ) ) {
switch ( F_203 ( V_19 ) -> V_274 ) {
case V_396 :
case V_402 :
F_14 ( V_19 ) ;
continue;
}
}
switch ( F_203 ( V_19 ) -> V_274 ) {
case V_397 :
F_4 ( L_60 , V_2 -> V_5 ) ;
F_277 ( V_2 , V_19 ) ;
break;
case V_396 :
F_4 ( L_61 , V_2 -> V_5 ) ;
F_263 ( V_2 , V_19 ) ;
break;
case V_402 :
F_4 ( L_62 , V_2 -> V_5 ) ;
F_268 ( V_2 , V_19 ) ;
break;
default:
F_14 ( V_19 ) ;
break;
}
}
}
static void V_372 ( struct V_297 * V_298 )
{
struct V_1 * V_2 = F_135 ( V_298 , struct V_1 , V_233 ) ;
struct V_13 * V_19 ;
F_4 ( L_63 , V_2 -> V_5 ,
F_217 ( & V_2 -> V_224 ) , F_220 ( & V_2 -> V_235 ) ) ;
if ( F_217 ( & V_2 -> V_224 ) ) {
V_19 = F_256 ( & V_2 -> V_235 ) ;
if ( ! V_19 )
return;
F_14 ( V_2 -> V_238 ) ;
V_2 -> V_238 = F_272 ( V_19 , V_160 ) ;
if ( V_2 -> V_238 ) {
F_278 ( & V_2 -> V_224 ) ;
F_215 ( V_19 ) ;
if ( F_30 ( V_43 , & V_2 -> V_41 ) )
F_279 ( & V_2 -> V_241 ) ;
else
F_280 ( & V_2 -> V_241 ,
V_164 + V_249 ) ;
} else {
F_273 ( & V_2 -> V_235 , V_19 ) ;
F_158 ( V_2 -> V_339 , & V_2 -> V_233 ) ;
}
}
}
T_1 F_281 ( T_1 V_320 )
{
switch ( V_320 ) {
case V_467 :
return V_468 ;
default:
return V_469 ;
}
}
