const char * F_1 ( enum V_1 V_2 )
{
if ( V_2 > V_3 )
V_2 = 0 ;
return V_4 [ V_2 ] ;
}
static int F_2 ( struct V_5 * V_6 )
{
return V_6 -> V_7 == V_8 ;
}
static int F_3 ( struct V_5 * V_6 )
{
return V_6 -> V_7 == V_9 ;
}
static int F_4 ( struct V_5 * V_6 )
{
return V_6 -> V_7 == V_10 ;
}
static void F_5 ( struct V_11 * V_12 )
{
struct V_13 * V_14 , * V_15 ;
F_6 (msg, msg2, q, link) {
F_7 ( & V_14 -> V_16 ) ;
F_8 ( V_14 ) ;
}
}
static void F_9 ( struct V_11 * V_12 )
{
struct V_17 * V_14 , * V_15 ;
F_6 (msg, msg2, q, link) {
F_7 ( & V_14 -> V_16 ) ;
F_10 ( V_14 ) ;
}
}
static void F_11 ( T_1 V_18 )
{
int V_19 ;
struct V_20 * V_21 , * V_22 ;
struct V_11 V_23 ;
F_12 ( & V_18 -> V_24 ) ;
F_9 ( & V_18 -> V_25 ) ;
F_5 ( & V_18 -> V_26 ) ;
F_13 ( & V_18 -> V_27 ) ;
F_14 ( & V_23 ) ;
F_15 ( & V_18 -> V_28 , & V_23 , V_29 ) ;
F_16 ( & V_18 -> V_27 ) ;
F_6 (rcvr, rcvr2, &list, link)
F_17 ( V_21 ) ;
for ( V_19 = 0 ; V_19 < V_30 ; V_19 ++ ) {
if ( ( V_18 -> V_31 [ V_19 ] . V_32 )
&& ( V_18 -> V_31 [ V_19 ] . V_33 ) )
F_8 ( V_18 -> V_31 [ V_19 ] . V_33 ) ;
}
}
static void F_18 ( struct V_34 * V_35 )
{
T_1 V_18 = F_19 ( V_35 , struct V_36 , V_37 ) ;
F_11 ( V_18 ) ;
F_17 ( V_18 ) ;
}
int F_20 ( struct V_38 * V_39 )
{
T_1 V_18 ;
F_21 ( V_40 ) ;
struct V_41 * V_42 , * V_43 ;
F_13 ( & V_44 ) ;
F_13 ( & V_45 ) ;
F_22 (intf, &ipmi_interfaces, link) {
if ( V_18 -> V_46 == - 1 )
continue;
V_42 = F_23 ( sizeof( * V_42 ) , V_47 ) ;
if ( ! V_42 )
goto V_48;
F_24 ( & V_18 -> V_37 ) ;
V_42 -> V_18 = V_18 ;
V_42 -> V_46 = V_18 -> V_46 ;
F_25 ( & V_42 -> V_16 , & V_40 ) ;
}
F_26 ( & V_39 -> V_16 , & V_49 ) ;
F_16 ( & V_45 ) ;
F_6 (e, e2, &to_deliver, link) {
F_7 ( & V_42 -> V_16 ) ;
V_39 -> V_50 ( V_42 -> V_46 , V_42 -> V_18 -> V_51 ) ;
F_27 ( & V_42 -> V_18 -> V_37 , F_18 ) ;
F_17 ( V_42 ) ;
}
F_16 ( & V_44 ) ;
return 0 ;
V_48:
F_16 ( & V_45 ) ;
F_16 ( & V_44 ) ;
F_6 (e, e2, &to_deliver, link) {
F_7 ( & V_42 -> V_16 ) ;
F_27 ( & V_42 -> V_18 -> V_37 , F_18 ) ;
F_17 ( V_42 ) ;
}
return - V_52 ;
}
int F_28 ( struct V_38 * V_39 )
{
F_13 ( & V_44 ) ;
F_7 ( & ( V_39 -> V_16 ) ) ;
F_16 ( & V_44 ) ;
return 0 ;
}
static void
F_29 ( int V_19 , struct V_53 * V_54 )
{
struct V_38 * V_55 ;
F_22 (w, &smi_watchers, link) {
if ( F_30 ( V_55 -> V_56 ) ) {
V_55 -> V_50 ( V_19 , V_54 ) ;
F_31 ( V_55 -> V_56 ) ;
}
}
}
static int
F_32 ( struct V_5 * V_57 , struct V_5 * V_58 )
{
if ( V_57 -> V_7 != V_58 -> V_7 )
return 0 ;
if ( V_57 -> V_59 != V_58 -> V_59 )
return 0 ;
if ( V_57 -> V_7 == V_60 ) {
struct V_61 * V_62
= (struct V_61 * ) V_57 ;
struct V_61 * V_63
= (struct V_61 * ) V_58 ;
return ( V_62 -> V_64 == V_63 -> V_64 ) ;
}
if ( F_3 ( V_57 ) || F_4 ( V_57 ) ) {
struct V_65 * V_66
= (struct V_65 * ) V_57 ;
struct V_65 * V_67
= (struct V_65 * ) V_58 ;
return ( ( V_66 -> V_68 == V_67 -> V_68 )
&& ( V_66 -> V_64 == V_67 -> V_64 ) ) ;
}
if ( F_2 ( V_57 ) ) {
struct V_69 * V_70
= (struct V_69 * ) V_57 ;
struct V_69 * V_71
= (struct V_69 * ) V_58 ;
return ( ( V_70 -> V_72 == V_71 -> V_72 )
&& ( V_70 -> V_73 == V_71 -> V_73 )
&& ( V_70 -> V_74
== V_71 -> V_74 )
&& ( V_70 -> V_64 == V_71 -> V_64 ) ) ;
}
return 1 ;
}
int F_33 ( struct V_5 * V_6 , int V_75 )
{
if ( V_75 < sizeof( struct V_61 ) )
return - V_76 ;
if ( V_6 -> V_7 == V_60 ) {
if ( V_6 -> V_59 != V_77 )
return - V_76 ;
return 0 ;
}
if ( ( V_6 -> V_59 == V_77 )
|| ( V_6 -> V_59 >= V_78 )
|| ( V_6 -> V_59 < 0 ) )
return - V_76 ;
if ( F_3 ( V_6 ) || F_4 ( V_6 ) ) {
if ( V_75 < sizeof( struct V_65 ) )
return - V_76 ;
return 0 ;
}
if ( F_2 ( V_6 ) ) {
if ( V_75 < sizeof( struct V_69 ) )
return - V_76 ;
return 0 ;
}
return - V_76 ;
}
unsigned int F_34 ( int V_7 )
{
if ( V_7 == V_60 )
return sizeof( struct V_61 ) ;
if ( ( V_7 == V_9 )
|| ( V_7 == V_10 ) )
return sizeof( struct V_65 ) ;
if ( V_7 == V_8 )
return sizeof( struct V_69 ) ;
return 0 ;
}
static void F_35 ( struct V_13 * V_14 )
{
if ( ! V_14 -> V_79 ) {
T_1 V_18 = V_14 -> V_80 ;
if ( V_18 -> V_81 ) {
V_18 -> V_81 ( V_18 , V_14 ) ;
F_36 ( V_18 , V_82 ) ;
} else {
F_36 ( V_18 , V_83 ) ;
}
F_8 ( V_14 ) ;
} else {
T_2 V_79 = V_14 -> V_79 ;
V_79 -> V_84 -> V_85 ( V_14 , V_79 -> V_86 ) ;
}
}
static void
F_37 ( struct V_13 * V_14 , int V_87 )
{
V_14 -> V_88 = V_89 ;
V_14 -> V_90 [ 0 ] = V_87 ;
V_14 -> V_14 . V_91 |= 1 ;
V_14 -> V_14 . V_92 = 1 ;
V_14 -> V_14 . V_93 = V_14 -> V_90 ;
F_35 ( V_14 ) ;
}
static int F_38 ( T_1 V_18 ,
struct V_13 * V_33 ,
unsigned long V_94 ,
int V_95 ,
int V_96 ,
unsigned char * V_97 ,
long * V_98 )
{
int V_99 = 0 ;
unsigned int V_19 ;
for ( V_19 = V_18 -> V_100 ; ( V_19 + 1 ) % V_30 != V_18 -> V_100 ;
V_19 = ( V_19 + 1 ) % V_30 ) {
if ( ! V_18 -> V_31 [ V_19 ] . V_32 )
break;
}
if ( ! V_18 -> V_31 [ V_19 ] . V_32 ) {
V_18 -> V_31 [ V_19 ] . V_33 = V_33 ;
V_18 -> V_31 [ V_19 ] . V_94 = V_101 ;
V_18 -> V_31 [ V_19 ] . V_102 = V_94 ;
V_18 -> V_31 [ V_19 ] . V_103 = V_95 ;
V_18 -> V_31 [ V_19 ] . V_96 = V_96 ;
V_18 -> V_31 [ V_19 ] . V_32 = 1 ;
V_18 -> V_31 [ V_19 ] . V_98 = F_39 ( V_18 -> V_31 [ V_19 ] . V_98 ) ;
* V_97 = V_19 ;
* V_98 = V_18 -> V_31 [ V_19 ] . V_98 ;
V_18 -> V_100 = ( V_19 + 1 ) % V_30 ;
F_40 ( V_18 ) ;
} else {
V_99 = - V_104 ;
}
return V_99 ;
}
static int F_41 ( T_1 V_18 ,
unsigned char V_97 ,
short V_59 ,
unsigned char V_105 ,
unsigned char V_91 ,
struct V_5 * V_6 ,
struct V_13 * * V_33 )
{
int V_99 = - V_106 ;
unsigned long V_107 ;
if ( V_97 >= V_30 )
return - V_76 ;
F_42 ( & ( V_18 -> V_108 ) , V_107 ) ;
if ( V_18 -> V_31 [ V_97 ] . V_32 ) {
struct V_13 * V_14 = V_18 -> V_31 [ V_97 ] . V_33 ;
if ( ( V_14 -> V_6 . V_59 == V_59 ) && ( V_14 -> V_14 . V_105 == V_105 )
&& ( V_14 -> V_14 . V_91 == V_91 )
&& ( F_32 ( V_6 , & ( V_14 -> V_6 ) ) ) ) {
* V_33 = V_14 ;
V_18 -> V_31 [ V_97 ] . V_32 = 0 ;
V_99 = 0 ;
}
}
F_43 ( & ( V_18 -> V_108 ) , V_107 ) ;
return V_99 ;
}
static int F_44 ( T_1 V_18 ,
long V_109 )
{
int V_99 = - V_106 ;
unsigned long V_107 ;
unsigned char V_97 ;
unsigned long V_98 ;
F_45 ( V_109 , V_97 , V_98 ) ;
F_42 ( & ( V_18 -> V_108 ) , V_107 ) ;
if ( ( V_18 -> V_31 [ V_97 ] . V_32 )
&& ( V_18 -> V_31 [ V_97 ] . V_98 == V_98 ) ) {
struct V_31 * V_110 = & ( V_18 -> V_31 [ V_97 ] ) ;
V_110 -> V_94 = V_110 -> V_102 ;
V_99 = 0 ;
}
F_43 ( & ( V_18 -> V_108 ) , V_107 ) ;
return V_99 ;
}
static int F_46 ( T_1 V_18 ,
long V_109 ,
unsigned int V_87 )
{
int V_99 = - V_106 ;
unsigned long V_107 ;
unsigned char V_97 ;
unsigned long V_98 ;
struct V_13 * V_14 = NULL ;
F_45 ( V_109 , V_97 , V_98 ) ;
F_42 ( & ( V_18 -> V_108 ) , V_107 ) ;
if ( ( V_18 -> V_31 [ V_97 ] . V_32 )
&& ( V_18 -> V_31 [ V_97 ] . V_98 == V_98 ) ) {
struct V_31 * V_110 = & ( V_18 -> V_31 [ V_97 ] ) ;
V_110 -> V_32 = 0 ;
V_14 = V_110 -> V_33 ;
V_99 = 0 ;
}
F_43 ( & ( V_18 -> V_108 ) , V_107 ) ;
if ( V_14 )
F_37 ( V_14 , V_87 ) ;
return V_99 ;
}
int F_47 ( unsigned int V_111 ,
struct V_112 * V_84 ,
void * V_86 ,
T_2 * V_79 )
{
unsigned long V_107 ;
T_2 V_113 ;
int V_99 = 0 ;
T_1 V_18 ;
if ( V_84 == NULL )
return - V_76 ;
if ( ! V_114 ) {
V_99 = F_48 () ;
if ( V_99 )
return V_99 ;
if ( ! V_114 )
return - V_106 ;
}
V_113 = F_23 ( sizeof( * V_113 ) , V_47 ) ;
if ( ! V_113 )
return - V_52 ;
F_13 ( & V_45 ) ;
F_49 (intf, &ipmi_interfaces, link) {
if ( V_18 -> V_46 == V_111 )
goto V_115;
}
V_99 = - V_76 ;
goto V_116;
V_115:
F_24 ( & V_18 -> V_37 ) ;
F_50 ( & V_113 -> V_37 ) ;
V_113 -> V_84 = V_84 ;
V_113 -> V_86 = V_86 ;
V_113 -> V_18 = V_18 ;
V_113 -> V_117 = false ;
if ( ! F_30 ( V_18 -> V_118 -> V_56 ) ) {
V_99 = - V_106 ;
goto V_119;
}
if ( V_18 -> V_118 -> V_120 ) {
V_99 = V_18 -> V_118 -> V_120 ( V_18 -> V_121 ) ;
if ( V_99 ) {
F_31 ( V_18 -> V_118 -> V_56 ) ;
goto V_119;
}
}
F_16 ( & V_45 ) ;
V_113 -> V_122 = true ;
F_42 ( & V_18 -> V_108 , V_107 ) ;
F_51 ( & V_113 -> V_16 , & V_18 -> V_123 ) ;
F_43 ( & V_18 -> V_108 , V_107 ) ;
if ( V_84 -> V_124 ) {
if ( F_52 ( & V_18 -> V_125 ) == 1 )
F_40 ( V_18 ) ;
}
* V_79 = V_113 ;
return 0 ;
V_119:
F_27 ( & V_18 -> V_37 , F_18 ) ;
V_116:
F_16 ( & V_45 ) ;
F_17 ( V_113 ) ;
return V_99 ;
}
int F_53 ( int V_111 , struct V_126 * V_93 )
{
int V_99 = 0 ;
T_1 V_18 ;
struct V_127 * V_118 ;
F_13 ( & V_45 ) ;
F_49 (intf, &ipmi_interfaces, link) {
if ( V_18 -> V_46 == V_111 )
goto V_115;
}
V_99 = - V_76 ;
F_16 ( & V_45 ) ;
return V_99 ;
V_115:
V_118 = V_18 -> V_118 ;
V_99 = - V_128 ;
if ( V_118 -> V_129 )
V_99 = V_118 -> V_129 ( V_18 -> V_121 , V_93 ) ;
F_16 ( & V_45 ) ;
return V_99 ;
}
static void F_54 ( struct V_34 * V_35 )
{
T_2 V_79 = F_19 ( V_35 , struct V_130 , V_37 ) ;
F_17 ( V_79 ) ;
}
int F_55 ( T_2 V_79 )
{
T_1 V_18 = V_79 -> V_18 ;
int V_19 ;
unsigned long V_107 ;
struct V_20 * V_21 ;
struct V_20 * V_131 = NULL ;
V_79 -> V_122 = false ;
if ( V_79 -> V_84 -> V_124 )
F_56 ( & V_18 -> V_125 ) ;
if ( V_79 -> V_117 )
F_56 ( & V_18 -> V_125 ) ;
F_42 ( & V_18 -> V_108 , V_107 ) ;
F_57 ( & V_79 -> V_16 ) ;
for ( V_19 = 0 ; V_19 < V_30 ; V_19 ++ ) {
if ( V_18 -> V_31 [ V_19 ] . V_32
&& ( V_18 -> V_31 [ V_19 ] . V_33 -> V_79 == V_79 ) ) {
V_18 -> V_31 [ V_19 ] . V_32 = 0 ;
F_8 ( V_18 -> V_31 [ V_19 ] . V_33 ) ;
}
}
F_43 ( & V_18 -> V_108 , V_107 ) ;
F_13 ( & V_18 -> V_27 ) ;
F_49 (rcvr, &intf->cmd_rcvrs, link) {
if ( V_21 -> V_79 == V_79 ) {
F_57 ( & V_21 -> V_16 ) ;
V_21 -> V_132 = V_131 ;
V_131 = V_21 ;
}
}
F_16 ( & V_18 -> V_27 ) ;
V_29 () ;
while ( V_131 ) {
V_21 = V_131 ;
V_131 = V_21 -> V_132 ;
F_17 ( V_21 ) ;
}
F_13 ( & V_45 ) ;
if ( V_18 -> V_118 ) {
F_31 ( V_18 -> V_118 -> V_56 ) ;
if ( V_18 -> V_118 -> V_133 )
V_18 -> V_118 -> V_133 ( V_18 -> V_121 ) ;
}
F_16 ( & V_45 ) ;
F_27 ( & V_18 -> V_37 , F_18 ) ;
F_27 ( & V_79 -> V_37 , F_54 ) ;
return 0 ;
}
void F_58 ( T_2 V_79 ,
unsigned char * V_134 ,
unsigned char * V_135 )
{
* V_134 = V_79 -> V_18 -> V_136 ;
* V_135 = V_79 -> V_18 -> V_137 ;
}
int F_59 ( T_2 V_79 ,
unsigned int V_59 ,
unsigned char V_138 )
{
if ( V_59 >= V_78 )
return - V_76 ;
V_79 -> V_18 -> V_139 [ V_59 ] . V_138 = V_138 ;
return 0 ;
}
int F_60 ( T_2 V_79 ,
unsigned int V_59 ,
unsigned char * V_138 )
{
if ( V_59 >= V_78 )
return - V_76 ;
* V_138 = V_79 -> V_18 -> V_139 [ V_59 ] . V_138 ;
return 0 ;
}
int F_61 ( T_2 V_79 ,
unsigned int V_59 ,
unsigned char V_140 )
{
if ( V_59 >= V_78 )
return - V_76 ;
V_79 -> V_18 -> V_139 [ V_59 ] . V_64 = V_140 & 0x3 ;
return 0 ;
}
int F_62 ( T_2 V_79 ,
unsigned int V_59 ,
unsigned char * V_138 )
{
if ( V_59 >= V_78 )
return - V_76 ;
* V_138 = V_79 -> V_18 -> V_139 [ V_59 ] . V_64 ;
return 0 ;
}
int F_63 ( T_2 V_79 )
{
int V_141 ;
unsigned long V_107 ;
F_42 ( & V_79 -> V_18 -> V_142 , V_107 ) ;
V_141 = V_79 -> V_18 -> V_143 ;
F_43 ( & V_79 -> V_18 -> V_142 , V_107 ) ;
return V_141 ;
}
static void F_64 ( T_1 V_18 )
{
if ( V_18 -> V_118 -> V_144 )
V_18 -> V_118 -> V_144 (
V_18 -> V_121 , V_18 -> V_145 ) ;
}
int F_65 ( T_2 V_79 , int V_141 )
{
int V_99 = 0 ;
unsigned long V_107 ;
T_1 V_18 = V_79 -> V_18 ;
F_42 ( & V_18 -> V_142 , V_107 ) ;
if ( V_18 -> V_143 != V_141 ) {
switch ( V_141 ) {
case V_146 :
V_18 -> V_145
= ( V_18 -> V_147 > 0 ) ;
break;
case V_148 :
V_18 -> V_145 = false ;
break;
case V_149 :
V_18 -> V_145 = true ;
break;
default:
V_99 = - V_76 ;
goto V_150;
}
V_18 -> V_143 = V_141 ;
F_64 ( V_18 ) ;
}
V_150:
F_43 ( & V_18 -> V_142 , V_107 ) ;
return V_99 ;
}
int F_66 ( T_2 V_79 , bool V_151 )
{
unsigned long V_107 ;
T_1 V_18 = V_79 -> V_18 ;
struct V_13 * V_14 , * V_15 ;
struct V_11 V_152 ;
F_14 ( & V_152 ) ;
F_42 ( & V_18 -> V_153 , V_107 ) ;
if ( V_79 -> V_117 == V_151 )
goto V_154;
V_79 -> V_117 = V_151 ;
if ( V_151 ) {
if ( F_52 ( & V_18 -> V_125 ) == 1 )
F_40 ( V_18 ) ;
} else {
F_56 ( & V_18 -> V_125 ) ;
}
if ( V_18 -> V_155 )
goto V_154;
while ( V_79 -> V_117 && ! F_67 ( & V_18 -> V_26 ) ) {
F_6 (msg, msg2, &intf->waiting_events, link)
F_68 ( & V_14 -> V_16 , & V_152 ) ;
V_18 -> V_156 = 0 ;
if ( V_18 -> V_157 ) {
F_69 (KERN_WARNING PFX L_1
L_2 ) ;
V_18 -> V_157 = 0 ;
}
V_18 -> V_155 = 1 ;
F_43 ( & V_18 -> V_153 , V_107 ) ;
F_6 (msg, msg2, &msgs, link) {
V_14 -> V_79 = V_79 ;
F_24 ( & V_79 -> V_37 ) ;
F_35 ( V_14 ) ;
}
F_42 ( & V_18 -> V_153 , V_107 ) ;
V_18 -> V_155 = 0 ;
}
V_154:
F_43 ( & V_18 -> V_153 , V_107 ) ;
return 0 ;
}
static struct V_20 * F_70 ( T_1 V_18 ,
unsigned char V_91 ,
unsigned char V_105 ,
unsigned char V_158 )
{
struct V_20 * V_21 ;
F_49 (rcvr, &intf->cmd_rcvrs, link) {
if ( ( V_21 -> V_91 == V_91 ) && ( V_21 -> V_105 == V_105 )
&& ( V_21 -> V_159 & ( 1 << V_158 ) ) )
return V_21 ;
}
return NULL ;
}
static int F_71 ( T_1 V_18 ,
unsigned char V_91 ,
unsigned char V_105 ,
unsigned int V_159 )
{
struct V_20 * V_21 ;
F_49 (rcvr, &intf->cmd_rcvrs, link) {
if ( ( V_21 -> V_91 == V_91 ) && ( V_21 -> V_105 == V_105 )
&& ( V_21 -> V_159 & V_159 ) )
return 0 ;
}
return 1 ;
}
int F_72 ( T_2 V_79 ,
unsigned char V_91 ,
unsigned char V_105 ,
unsigned int V_159 )
{
T_1 V_18 = V_79 -> V_18 ;
struct V_20 * V_21 ;
int V_99 = 0 ;
V_21 = F_23 ( sizeof( * V_21 ) , V_47 ) ;
if ( ! V_21 )
return - V_52 ;
V_21 -> V_105 = V_105 ;
V_21 -> V_91 = V_91 ;
V_21 -> V_159 = V_159 ;
V_21 -> V_79 = V_79 ;
F_13 ( & V_18 -> V_27 ) ;
if ( ! F_71 ( V_18 , V_91 , V_105 , V_159 ) ) {
V_99 = - V_160 ;
goto V_150;
}
if ( F_52 ( & V_18 -> V_125 ) == 1 )
F_40 ( V_18 ) ;
F_51 ( & V_21 -> V_16 , & V_18 -> V_28 ) ;
V_150:
F_16 ( & V_18 -> V_27 ) ;
if ( V_99 )
F_17 ( V_21 ) ;
return V_99 ;
}
int F_73 ( T_2 V_79 ,
unsigned char V_91 ,
unsigned char V_105 ,
unsigned int V_159 )
{
T_1 V_18 = V_79 -> V_18 ;
struct V_20 * V_21 ;
struct V_20 * V_131 = NULL ;
int V_19 , V_99 = - V_161 ;
F_13 ( & V_18 -> V_27 ) ;
for ( V_19 = 0 ; V_19 < V_162 ; V_19 ++ ) {
if ( ( ( 1 << V_19 ) & V_159 ) == 0 )
continue;
V_21 = F_70 ( V_18 , V_91 , V_105 , V_19 ) ;
if ( V_21 == NULL )
continue;
if ( V_21 -> V_79 == V_79 ) {
V_99 = 0 ;
V_21 -> V_159 &= ~ V_159 ;
if ( V_21 -> V_159 == 0 ) {
F_57 ( & V_21 -> V_16 ) ;
V_21 -> V_132 = V_131 ;
V_131 = V_21 ;
}
}
}
F_16 ( & V_18 -> V_27 ) ;
V_29 () ;
while ( V_131 ) {
F_56 ( & V_18 -> V_125 ) ;
V_21 = V_131 ;
V_131 = V_21 -> V_132 ;
F_17 ( V_21 ) ;
}
return V_99 ;
}
static unsigned char
F_74 ( unsigned char * V_93 , int V_163 )
{
unsigned char V_164 = 0 ;
for (; V_163 > 0 ; V_163 -- , V_93 ++ )
V_164 += * V_93 ;
return - V_164 ;
}
static inline void F_75 ( struct V_17 * V_165 ,
struct V_166 * V_14 ,
struct V_65 * V_167 ,
long V_109 ,
unsigned char V_168 ,
int V_96 ,
unsigned char V_169 ,
unsigned char V_170 )
{
int V_19 = V_96 ;
V_165 -> V_93 [ 0 ] = ( V_171 << 2 ) ;
V_165 -> V_93 [ 1 ] = V_172 ;
V_165 -> V_93 [ 2 ] = V_167 -> V_59 ;
if ( V_96 )
V_165 -> V_93 [ 3 ] = 0 ;
V_165 -> V_93 [ V_19 + 3 ] = V_167 -> V_68 ;
V_165 -> V_93 [ V_19 + 4 ] = ( V_14 -> V_91 << 2 ) | ( V_167 -> V_64 & 0x3 ) ;
V_165 -> V_93 [ V_19 + 5 ] = F_74 ( & ( V_165 -> V_93 [ V_19 + 3 ] ) , 2 ) ;
V_165 -> V_93 [ V_19 + 6 ] = V_169 ;
V_165 -> V_93 [ V_19 + 7 ] = ( V_168 << 2 ) | V_170 ;
V_165 -> V_93 [ V_19 + 8 ] = V_14 -> V_105 ;
if ( V_14 -> V_92 > 0 )
memcpy ( & ( V_165 -> V_93 [ V_19 + 9 ] ) , V_14 -> V_93 ,
V_14 -> V_92 ) ;
V_165 -> V_173 = V_14 -> V_92 + 9 ;
V_165 -> V_93 [ V_19 + V_165 -> V_173 ]
= F_74 ( & ( V_165 -> V_93 [ V_19 + 6 ] ) ,
V_165 -> V_173 - 6 ) ;
V_165 -> V_173 += 1 + V_19 ;
V_165 -> V_109 = V_109 ;
}
static inline void F_76 ( struct V_17 * V_165 ,
struct V_166 * V_14 ,
struct V_69 * V_174 ,
long V_109 ,
unsigned char V_168 ,
unsigned char V_170 )
{
V_165 -> V_93 [ 0 ] = ( V_171 << 2 ) ;
V_165 -> V_93 [ 1 ] = V_172 ;
V_165 -> V_93 [ 2 ] = V_174 -> V_59 ;
V_165 -> V_93 [ 3 ] = V_174 -> V_74 ;
V_165 -> V_93 [ 4 ] = V_174 -> V_72 ;
V_165 -> V_93 [ 5 ] = ( V_14 -> V_91 << 2 ) | ( V_174 -> V_64 & 0x3 ) ;
V_165 -> V_93 [ 6 ] = F_74 ( & ( V_165 -> V_93 [ 4 ] ) , 2 ) ;
V_165 -> V_93 [ 7 ] = V_174 -> V_73 ;
V_165 -> V_93 [ 8 ] = ( V_168 << 2 ) | V_170 ;
V_165 -> V_93 [ 9 ] = V_14 -> V_105 ;
if ( V_14 -> V_92 > 0 )
memcpy ( & ( V_165 -> V_93 [ 10 ] ) , V_14 -> V_93 ,
V_14 -> V_92 ) ;
V_165 -> V_173 = V_14 -> V_92 + 10 ;
V_165 -> V_93 [ V_165 -> V_173 ]
= F_74 ( & ( V_165 -> V_93 [ 7 ] ) ,
V_165 -> V_173 - 7 ) ;
V_165 -> V_173 += 1 ;
V_165 -> V_109 = V_109 ;
}
static void F_77 ( T_1 V_18 , struct V_127 * V_118 ,
struct V_17 * V_165 , int V_175 )
{
int V_176 = V_18 -> V_176 ;
unsigned long V_107 ;
if ( ! V_176 )
F_42 ( & V_18 -> V_177 , V_107 ) ;
if ( V_18 -> V_178 ) {
if ( V_175 > 0 )
F_25 ( & V_165 -> V_16 , & V_18 -> V_179 ) ;
else
F_25 ( & V_165 -> V_16 , & V_18 -> V_180 ) ;
V_165 = NULL ;
} else {
V_18 -> V_178 = V_165 ;
}
if ( ! V_176 )
F_43 ( & V_18 -> V_177 , V_107 ) ;
if ( V_165 )
V_118 -> V_181 ( V_18 -> V_121 , V_165 ) ;
}
static int F_78 ( T_2 V_79 ,
T_1 V_18 ,
struct V_5 * V_6 ,
long V_109 ,
struct V_166 * V_14 ,
void * V_80 ,
void * V_182 ,
struct V_13 * V_183 ,
int V_175 ,
unsigned char V_169 ,
unsigned char V_170 ,
int V_95 ,
unsigned int V_184 )
{
int V_99 = 0 ;
struct V_17 * V_165 ;
struct V_13 * V_33 ;
unsigned long V_107 ;
if ( V_183 )
V_33 = V_183 ;
else {
V_33 = F_79 () ;
if ( V_33 == NULL )
return - V_52 ;
}
V_33 -> V_80 = V_80 ;
if ( V_182 )
V_165 = (struct V_17 * ) V_182 ;
else {
V_165 = F_80 () ;
if ( V_165 == NULL ) {
F_8 ( V_33 ) ;
return - V_52 ;
}
}
F_81 () ;
if ( V_18 -> V_185 ) {
V_99 = - V_106 ;
goto V_48;
}
V_33 -> V_79 = V_79 ;
if ( V_79 )
F_24 ( & V_79 -> V_37 ) ;
V_33 -> V_109 = V_109 ;
V_33 -> V_14 = * V_14 ;
if ( V_6 -> V_7 == V_60 ) {
struct V_61 * V_186 ;
if ( V_14 -> V_91 & 1 ) {
V_99 = - V_76 ;
goto V_48;
}
V_186 = (struct V_61 * ) V_6 ;
if ( V_186 -> V_64 > 3 ) {
F_36 ( V_18 , V_187 ) ;
V_99 = - V_76 ;
goto V_48;
}
memcpy ( & V_33 -> V_6 , V_186 , sizeof( * V_186 ) ) ;
if ( ( V_14 -> V_91 == V_171 )
&& ( ( V_14 -> V_105 == V_172 )
|| ( V_14 -> V_105 == V_188 )
|| ( V_14 -> V_105 == V_189 ) ) ) {
F_36 ( V_18 , V_187 ) ;
V_99 = - V_76 ;
goto V_48;
}
if ( ( ( V_14 -> V_91 == V_171 )
&& ( ( V_14 -> V_105 == V_190 )
|| ( V_14 -> V_105 == V_191 ) ) )
|| ( V_14 -> V_91 == V_192 ) ) {
F_42 ( & V_18 -> V_142 , V_107 ) ;
V_18 -> V_147
= V_193 ;
if ( ! V_18 -> V_143
&& ! V_18 -> V_145 ) {
V_18 -> V_145 = true ;
F_64 ( V_18 ) ;
}
F_43 ( & V_18 -> V_142 ,
V_107 ) ;
}
if ( ( V_14 -> V_92 + 2 ) > V_194 ) {
F_36 ( V_18 , V_187 ) ;
V_99 = - V_195 ;
goto V_48;
}
V_165 -> V_93 [ 0 ] = ( V_14 -> V_91 << 2 ) | ( V_186 -> V_64 & 0x3 ) ;
V_165 -> V_93 [ 1 ] = V_14 -> V_105 ;
V_165 -> V_109 = V_109 ;
V_165 -> V_196 = V_33 ;
if ( V_14 -> V_92 > 0 )
memcpy ( & ( V_165 -> V_93 [ 2 ] ) , V_14 -> V_93 , V_14 -> V_92 ) ;
V_165 -> V_173 = V_14 -> V_92 + 2 ;
F_36 ( V_18 , V_197 ) ;
} else if ( F_3 ( V_6 ) || F_4 ( V_6 ) ) {
struct V_65 * V_167 ;
unsigned char V_168 ;
long V_98 ;
int V_96 = 0 ;
if ( V_6 -> V_59 >= V_78 ) {
F_36 ( V_18 , V_187 ) ;
V_99 = - V_76 ;
goto V_48;
}
if ( V_18 -> V_139 [ V_6 -> V_59 ] . V_198
!= V_199 ) {
F_36 ( V_18 , V_187 ) ;
V_99 = - V_76 ;
goto V_48;
}
if ( V_95 < 0 ) {
if ( V_6 -> V_7 == V_10 )
V_95 = 0 ;
else
V_95 = 4 ;
}
if ( V_6 -> V_7 == V_10 ) {
V_6 -> V_7 = V_9 ;
V_96 = 1 ;
}
if ( V_184 == 0 )
V_184 = 1000 ;
if ( ( V_14 -> V_92 + 10 + V_96 ) > V_194 ) {
F_36 ( V_18 , V_187 ) ;
V_99 = - V_195 ;
goto V_48;
}
V_167 = (struct V_65 * ) V_6 ;
if ( V_167 -> V_64 > 3 ) {
F_36 ( V_18 , V_187 ) ;
V_99 = - V_76 ;
goto V_48;
}
memcpy ( & V_33 -> V_6 , V_167 , sizeof( * V_167 ) ) ;
if ( V_33 -> V_14 . V_91 & 0x1 ) {
F_36 ( V_18 , V_200 ) ;
F_75 ( V_165 , V_14 , V_167 , V_109 ,
V_109 , V_96 ,
V_169 , V_170 ) ;
V_165 -> V_196 = V_33 ;
} else {
F_42 ( & ( V_18 -> V_108 ) , V_107 ) ;
V_99 = F_38 ( V_18 ,
V_33 ,
V_184 ,
V_95 ,
V_96 ,
& V_168 ,
& V_98 ) ;
if ( V_99 ) {
F_43 ( & ( V_18 -> V_108 ) ,
V_107 ) ;
goto V_48;
}
F_36 ( V_18 , V_201 ) ;
F_75 ( V_165 , V_14 , V_167 ,
F_82 ( V_168 , V_98 ) ,
V_168 , V_96 ,
V_169 , V_170 ) ;
memcpy ( V_33 -> V_90 , V_165 -> V_93 ,
V_165 -> V_173 ) ;
V_33 -> V_14 . V_93 = V_33 -> V_90 ;
V_33 -> V_14 . V_92 = V_165 -> V_173 ;
F_43 ( & ( V_18 -> V_108 ) , V_107 ) ;
}
} else if ( F_2 ( V_6 ) ) {
struct V_69 * V_174 ;
unsigned char V_168 ;
long V_98 ;
if ( V_6 -> V_59 >= V_78 ) {
F_36 ( V_18 , V_187 ) ;
V_99 = - V_76 ;
goto V_48;
}
if ( ( V_18 -> V_139 [ V_6 -> V_59 ] . V_198
!= V_202 )
&& ( V_18 -> V_139 [ V_6 -> V_59 ] . V_198
!= V_203 ) ) {
F_36 ( V_18 , V_187 ) ;
V_99 = - V_76 ;
goto V_48;
}
V_95 = 4 ;
if ( V_184 == 0 )
V_184 = 1000 ;
if ( ( V_14 -> V_92 + 12 ) > V_194 ) {
F_36 ( V_18 , V_187 ) ;
V_99 = - V_195 ;
goto V_48;
}
V_174 = (struct V_69 * ) V_6 ;
if ( V_174 -> V_64 > 3 ) {
F_36 ( V_18 , V_187 ) ;
V_99 = - V_76 ;
goto V_48;
}
memcpy ( & V_33 -> V_6 , V_174 , sizeof( * V_174 ) ) ;
if ( V_33 -> V_14 . V_91 & 0x1 ) {
F_36 ( V_18 , V_204 ) ;
F_76 ( V_165 , V_14 , V_174 , V_109 ,
V_109 , V_170 ) ;
V_165 -> V_196 = V_33 ;
} else {
F_42 ( & ( V_18 -> V_108 ) , V_107 ) ;
V_99 = F_38 ( V_18 ,
V_33 ,
V_184 ,
V_95 ,
0 ,
& V_168 ,
& V_98 ) ;
if ( V_99 ) {
F_43 ( & ( V_18 -> V_108 ) ,
V_107 ) ;
goto V_48;
}
F_36 ( V_18 , V_205 ) ;
F_76 ( V_165 , V_14 , V_174 ,
F_82 ( V_168 , V_98 ) ,
V_168 , V_170 ) ;
memcpy ( V_33 -> V_90 , V_165 -> V_93 ,
V_165 -> V_173 ) ;
V_33 -> V_14 . V_93 = V_33 -> V_90 ;
V_33 -> V_14 . V_92 = V_165 -> V_173 ;
F_43 ( & ( V_18 -> V_108 ) , V_107 ) ;
}
} else {
F_36 ( V_18 , V_187 ) ;
V_99 = - V_76 ;
goto V_48;
}
#ifdef F_83
{
int V_206 ;
for ( V_206 = 0 ; V_206 < V_165 -> V_173 ; V_206 ++ )
F_69 ( L_3 , V_165 -> V_93 [ V_206 ] ) ;
F_69 ( L_4 ) ;
}
#endif
F_77 ( V_18 , V_18 -> V_118 , V_165 , V_175 ) ;
F_84 () ;
return 0 ;
V_48:
F_84 () ;
F_10 ( V_165 ) ;
F_8 ( V_33 ) ;
return V_99 ;
}
static int F_85 ( T_1 V_18 ,
struct V_5 * V_6 ,
unsigned char * V_207 ,
unsigned char * V_64 )
{
if ( V_6 -> V_59 >= V_78 )
return - V_76 ;
* V_64 = V_18 -> V_139 [ V_6 -> V_59 ] . V_64 ;
* V_207 = V_18 -> V_139 [ V_6 -> V_59 ] . V_138 ;
return 0 ;
}
int F_86 ( T_2 V_79 ,
struct V_5 * V_6 ,
long V_109 ,
struct V_166 * V_14 ,
void * V_80 ,
int V_175 ,
int V_95 ,
unsigned int V_184 )
{
unsigned char V_207 = 0 , V_64 = 0 ;
int V_99 ;
if ( ! V_79 )
return - V_76 ;
V_99 = F_85 ( V_79 -> V_18 , V_6 , & V_207 , & V_64 ) ;
if ( V_99 )
return V_99 ;
return F_78 ( V_79 ,
V_79 -> V_18 ,
V_6 ,
V_109 ,
V_14 ,
V_80 ,
NULL , NULL ,
V_175 ,
V_207 ,
V_64 ,
V_95 ,
V_184 ) ;
}
int F_87 ( T_2 V_79 ,
struct V_5 * V_6 ,
long V_109 ,
struct V_166 * V_14 ,
void * V_80 ,
void * V_182 ,
struct V_13 * V_183 ,
int V_175 )
{
unsigned char V_207 = 0 , V_64 = 0 ;
int V_99 ;
if ( ! V_79 )
return - V_76 ;
V_99 = F_85 ( V_79 -> V_18 , V_6 , & V_207 , & V_64 ) ;
if ( V_99 )
return V_99 ;
return F_78 ( V_79 ,
V_79 -> V_18 ,
V_6 ,
V_109 ,
V_14 ,
V_80 ,
V_182 ,
V_183 ,
V_175 ,
V_207 ,
V_64 ,
- 1 , 0 ) ;
}
static int F_88 ( struct V_208 * V_206 , void * V_209 )
{
T_1 V_18 = V_206 -> V_210 ;
int V_19 ;
F_89 ( V_206 , L_5 , V_18 -> V_139 [ 0 ] . V_138 ) ;
for ( V_19 = 1 ; V_19 < V_78 ; V_19 ++ )
F_89 ( V_206 , L_6 , V_18 -> V_139 [ V_19 ] . V_138 ) ;
return F_90 ( V_206 , '\n' ) ;
}
static int F_91 ( struct V_211 * V_211 , struct V_212 * V_212 )
{
return F_92 ( V_212 , F_88 , F_93 ( V_211 ) ) ;
}
static int F_94 ( struct V_208 * V_206 , void * V_209 )
{
T_1 V_18 = V_206 -> V_210 ;
return F_89 ( V_206 , L_7 ,
V_136 ( & V_18 -> V_213 -> V_214 ) ,
V_137 ( & V_18 -> V_213 -> V_214 ) ) ;
}
static int F_95 ( struct V_211 * V_211 , struct V_212 * V_212 )
{
return F_92 ( V_212 , F_94 , F_93 ( V_211 ) ) ;
}
static int F_96 ( struct V_208 * V_206 , void * V_209 )
{
T_1 V_18 = V_206 -> V_210 ;
F_89 ( V_206 , L_8 ,
F_97 ( V_18 , V_187 ) ) ;
F_89 ( V_206 , L_9 ,
F_97 ( V_18 , V_197 ) ) ;
F_89 ( V_206 , L_10 ,
F_97 ( V_18 , V_82 ) ) ;
F_89 ( V_206 , L_11 ,
F_97 ( V_18 , V_83 ) ) ;
F_89 ( V_206 , L_12 ,
F_97 ( V_18 , V_201 ) ) ;
F_89 ( V_206 , L_13 ,
F_97 ( V_18 , V_215 ) ) ;
F_89 ( V_206 , L_14 ,
F_97 ( V_18 , V_216 ) ) ;
F_89 ( V_206 , L_15 ,
F_97 ( V_18 , V_217 ) ) ;
F_89 ( V_206 , L_16 ,
F_97 ( V_18 , V_218 ) ) ;
F_89 ( V_206 , L_17 ,
F_97 ( V_18 , V_200 ) ) ;
F_89 ( V_206 , L_18 ,
F_97 ( V_18 , V_219 ) ) ;
F_89 ( V_206 , L_19 ,
F_97 ( V_18 , V_220 ) ) ;
F_89 ( V_206 , L_20 ,
F_97 ( V_18 , V_221 ) ) ;
F_89 ( V_206 , L_21 ,
F_97 ( V_18 , V_205 ) ) ;
F_89 ( V_206 , L_22 ,
F_97 ( V_18 , V_222 ) ) ;
F_89 ( V_206 , L_23 ,
F_97 ( V_18 , V_223 ) ) ;
F_89 ( V_206 , L_24 ,
F_97 ( V_18 , V_224 ) ) ;
F_89 ( V_206 , L_25 ,
F_97 ( V_18 , V_204 ) ) ;
F_89 ( V_206 , L_26 ,
F_97 ( V_18 , V_225 ) ) ;
F_89 ( V_206 , L_27 ,
F_97 ( V_18 , V_226 ) ) ;
F_89 ( V_206 , L_28 ,
F_97 ( V_18 , V_227 ) ) ;
F_89 ( V_206 , L_29 ,
F_97 ( V_18 , V_228 ) ) ;
F_89 ( V_206 , L_30 ,
F_97 ( V_18 , V_229 ) ) ;
F_89 ( V_206 , L_31 ,
F_97 ( V_18 , V_230 ) ) ;
F_89 ( V_206 , L_32 ,
F_97 ( V_18 , V_231 ) ) ;
F_89 ( V_206 , L_33 ,
F_97 ( V_18 , V_232 ) ) ;
F_89 ( V_206 , L_34 ,
F_97 ( V_18 , V_233 ) ) ;
F_89 ( V_206 , L_35 ,
F_97 ( V_18 , V_234 ) ) ;
return 0 ;
}
static int F_98 ( struct V_211 * V_211 , struct V_212 * V_212 )
{
return F_92 ( V_212 , F_96 , F_93 ( V_211 ) ) ;
}
int F_99 ( T_1 V_235 , char * V_236 ,
const struct V_237 * V_238 ,
void * V_93 )
{
int V_99 = 0 ;
#ifdef F_100
struct V_239 * V_212 ;
struct V_240 * V_241 ;
V_241 = F_23 ( sizeof( * V_241 ) , V_47 ) ;
if ( ! V_241 )
return - V_52 ;
V_241 -> V_236 = F_101 ( V_236 , V_47 ) ;
if ( ! V_241 -> V_236 ) {
F_17 ( V_241 ) ;
return - V_52 ;
}
V_212 = F_102 ( V_236 , 0 , V_235 -> V_242 , V_238 , V_93 ) ;
if ( ! V_212 ) {
F_17 ( V_241 -> V_236 ) ;
F_17 ( V_241 ) ;
V_99 = - V_52 ;
} else {
F_13 ( & V_235 -> V_243 ) ;
V_241 -> V_132 = V_235 -> V_244 ;
V_235 -> V_244 = V_241 ;
F_16 ( & V_235 -> V_243 ) ;
}
#endif
return V_99 ;
}
static int F_103 ( T_1 V_235 , int V_245 )
{
int V_99 = 0 ;
#ifdef F_100
sprintf ( V_235 -> V_246 , L_36 , V_245 ) ;
V_235 -> V_242 = F_104 ( V_235 -> V_246 , V_247 ) ;
if ( ! V_235 -> V_242 )
V_99 = - V_52 ;
if ( V_99 == 0 )
V_99 = F_99 ( V_235 , L_37 ,
& V_248 ,
V_235 ) ;
if ( V_99 == 0 )
V_99 = F_99 ( V_235 , L_38 ,
& V_249 ,
V_235 ) ;
if ( V_99 == 0 )
V_99 = F_99 ( V_235 , L_39 ,
& V_250 ,
V_235 ) ;
#endif
return V_99 ;
}
static void F_105 ( T_1 V_235 )
{
#ifdef F_100
struct V_240 * V_241 ;
F_13 ( & V_235 -> V_243 ) ;
while ( V_235 -> V_244 ) {
V_241 = V_235 -> V_244 ;
V_235 -> V_244 = V_241 -> V_132 ;
F_106 ( V_241 -> V_236 , V_235 -> V_242 ) ;
F_17 ( V_241 -> V_236 ) ;
F_17 ( V_241 ) ;
}
F_16 ( & V_235 -> V_243 ) ;
F_106 ( V_235 -> V_246 , V_247 ) ;
#endif
}
static int F_107 ( struct V_53 * V_54 , void * V_93 )
{
unsigned char * V_214 = V_93 ;
struct V_251 * V_213 = F_108 ( V_54 ) ;
return memcmp ( V_213 -> V_252 , V_214 , 16 ) == 0 ;
}
static struct V_251 * F_109 ( struct V_253 * V_254 ,
unsigned char * V_252 )
{
struct V_53 * V_54 ;
V_54 = F_110 ( V_254 , NULL , V_252 , F_107 ) ;
if ( V_54 )
return F_108 ( V_54 ) ;
else
return NULL ;
}
static int F_111 ( struct V_53 * V_54 , void * V_93 )
{
struct V_255 * V_214 = V_93 ;
struct V_251 * V_213 = F_108 ( V_54 ) ;
return ( V_213 -> V_214 . V_256 == V_214 -> V_256
&& V_213 -> V_214 . V_257 == V_214 -> V_257 ) ;
}
static struct V_251 * F_112 (
struct V_253 * V_254 ,
unsigned int V_256 , unsigned char V_257 )
{
struct V_255 V_214 = {
. V_256 = V_256 ,
. V_257 = V_257 ,
} ;
struct V_53 * V_54 ;
V_54 = F_110 ( V_254 , NULL , & V_214 , F_111 ) ;
if ( V_54 )
return F_108 ( V_54 ) ;
else
return NULL ;
}
static T_3 F_113 ( struct V_53 * V_54 ,
struct V_258 * V_259 ,
char * V_260 )
{
struct V_251 * V_213 = F_108 ( V_54 ) ;
return snprintf ( V_260 , 10 , L_40 , V_213 -> V_214 . V_257 ) ;
}
static T_3 F_114 ( struct V_53 * V_54 ,
struct V_258 * V_259 ,
char * V_260 )
{
struct V_251 * V_213 = F_108 ( V_54 ) ;
return snprintf ( V_260 , 10 , L_40 ,
( V_213 -> V_214 . V_261 & 0x80 ) >> 7 ) ;
}
static T_3 F_115 ( struct V_53 * V_54 , struct V_258 * V_259 ,
char * V_260 )
{
struct V_251 * V_213 = F_108 ( V_54 ) ;
return snprintf ( V_260 , 20 , L_40 ,
V_213 -> V_214 . V_261 & 0x0F ) ;
}
static T_3 F_116 ( struct V_53 * V_54 ,
struct V_258 * V_259 ,
char * V_260 )
{
struct V_251 * V_213 = F_108 ( V_54 ) ;
return snprintf ( V_260 , 20 , L_41 , V_213 -> V_214 . V_262 ,
V_213 -> V_214 . V_263 ) ;
}
static T_3 F_117 ( struct V_53 * V_54 ,
struct V_258 * V_259 ,
char * V_260 )
{
struct V_251 * V_213 = F_108 ( V_54 ) ;
return snprintf ( V_260 , 20 , L_7 ,
V_136 ( & V_213 -> V_214 ) ,
V_137 ( & V_213 -> V_214 ) ) ;
}
static T_3 F_118 ( struct V_53 * V_54 ,
struct V_258 * V_259 ,
char * V_260 )
{
struct V_251 * V_213 = F_108 ( V_54 ) ;
return snprintf ( V_260 , 10 , L_42 ,
V_213 -> V_214 . V_264 ) ;
}
static T_3 F_119 ( struct V_53 * V_54 ,
struct V_258 * V_259 ,
char * V_260 )
{
struct V_251 * V_213 = F_108 ( V_54 ) ;
return snprintf ( V_260 , 20 , L_43 , V_213 -> V_214 . V_265 ) ;
}
static T_3 F_120 ( struct V_53 * V_54 ,
struct V_258 * V_259 ,
char * V_260 )
{
struct V_251 * V_213 = F_108 ( V_54 ) ;
return snprintf ( V_260 , 10 , L_44 , V_213 -> V_214 . V_256 ) ;
}
static T_3 F_121 ( struct V_53 * V_54 ,
struct V_258 * V_259 ,
char * V_260 )
{
struct V_251 * V_213 = F_108 ( V_54 ) ;
return snprintf ( V_260 , 21 , L_45 ,
V_213 -> V_214 . V_266 [ 3 ] ,
V_213 -> V_214 . V_266 [ 2 ] ,
V_213 -> V_214 . V_266 [ 1 ] ,
V_213 -> V_214 . V_266 [ 0 ] ) ;
}
static T_3 F_122 ( struct V_53 * V_54 , struct V_258 * V_259 ,
char * V_260 )
{
struct V_251 * V_213 = F_108 ( V_54 ) ;
return snprintf ( V_260 , 100 , L_46 ,
( long long ) V_213 -> V_252 [ 0 ] ,
( long long ) V_213 -> V_252 [ 8 ] ) ;
}
static void
F_123 ( struct V_53 * V_54 )
{
F_17 ( F_108 ( V_54 ) ) ;
}
static void
F_124 ( struct V_34 * V_35 )
{
struct V_251 * V_213 = F_19 ( V_35 , struct V_251 , V_267 ) ;
if ( V_213 -> V_214 . V_268 )
F_125 ( & V_213 -> V_269 . V_54 ,
& V_270 ) ;
if ( V_213 -> V_271 )
F_125 ( & V_213 -> V_269 . V_54 ,
& V_272 ) ;
F_126 ( & V_213 -> V_269 ) ;
}
static void F_127 ( T_1 V_18 )
{
struct V_251 * V_213 = V_18 -> V_213 ;
F_128 ( & V_18 -> V_51 -> V_273 , L_47 ) ;
if ( V_18 -> V_274 ) {
F_128 ( & V_213 -> V_269 . V_54 . V_273 , V_18 -> V_274 ) ;
F_17 ( V_18 -> V_274 ) ;
V_18 -> V_274 = NULL ;
}
F_13 ( & V_275 ) ;
F_27 ( & V_213 -> V_267 , F_124 ) ;
V_18 -> V_213 = NULL ;
F_16 ( & V_275 ) ;
}
static int F_129 ( struct V_251 * V_213 )
{
int V_87 ;
if ( V_213 -> V_214 . V_268 ) {
V_87 = F_130 ( & V_213 -> V_269 . V_54 ,
& V_270 ) ;
if ( V_87 )
goto V_154;
}
if ( V_213 -> V_271 ) {
V_87 = F_130 ( & V_213 -> V_269 . V_54 ,
& V_272 ) ;
if ( V_87 )
goto V_276;
}
return 0 ;
V_276:
if ( V_213 -> V_214 . V_268 )
F_125 ( & V_213 -> V_269 . V_54 ,
& V_270 ) ;
V_154:
return V_87 ;
}
static int F_131 ( T_1 V_18 , int V_277 )
{
int V_99 ;
struct V_251 * V_213 = V_18 -> V_213 ;
struct V_251 * V_278 ;
F_13 ( & V_275 ) ;
if ( V_213 -> V_271 )
V_278 = F_109 ( & V_279 . V_280 , V_213 -> V_252 ) ;
else
V_278 = F_112 ( & V_279 . V_280 ,
V_213 -> V_214 . V_256 ,
V_213 -> V_214 . V_257 ) ;
if ( V_278 ) {
F_17 ( V_213 ) ;
V_18 -> V_213 = V_278 ;
V_213 = V_278 ;
F_24 ( & V_213 -> V_267 ) ;
F_16 ( & V_275 ) ;
F_69 ( V_281
L_48
L_49 ,
V_213 -> V_214 . V_265 ,
V_213 -> V_214 . V_256 ,
V_213 -> V_214 . V_257 ) ;
} else {
unsigned char V_282 = V_213 -> V_214 . V_257 ;
int V_283 = 0 ;
snprintf ( V_213 -> V_236 , sizeof( V_213 -> V_236 ) ,
L_50 , V_213 -> V_214 . V_256 ) ;
V_213 -> V_269 . V_236 = V_213 -> V_236 ;
while ( F_112 ( & V_279 . V_280 ,
V_213 -> V_214 . V_256 ,
V_213 -> V_214 . V_257 ) ) {
if ( ! V_283 ) {
F_69 (KERN_WARNING PFX
L_51
L_52
L_53
L_54
L_55
L_56 ,
bmc->id.product_id, bmc->id.device_id) ;
V_283 = 1 ;
}
V_213 -> V_214 . V_257 ++ ;
if ( V_213 -> V_214 . V_257 == V_282 ) {
F_69 (KERN_ERR PFX
L_57 ) ;
break;
}
}
V_213 -> V_269 . V_54 . V_280 = & V_279 . V_280 ;
V_213 -> V_269 . V_214 = V_213 -> V_214 . V_257 ;
V_213 -> V_269 . V_54 . V_284 = F_123 ;
V_213 -> V_269 . V_54 . type = & V_285 ;
F_50 ( & V_213 -> V_267 ) ;
V_99 = F_132 ( & V_213 -> V_269 ) ;
F_16 ( & V_275 ) ;
if ( V_99 ) {
F_133 ( & V_213 -> V_269 . V_54 ) ;
F_69 ( V_286
L_58
L_59 ,
V_99 ) ;
return V_99 ;
}
V_99 = F_129 ( V_213 ) ;
if ( V_99 ) {
F_13 ( & V_275 ) ;
F_126 ( & V_213 -> V_269 ) ;
F_16 ( & V_275 ) ;
return V_99 ;
}
F_134 ( V_18 -> V_51 , L_60
L_61 ,
V_213 -> V_214 . V_265 ,
V_213 -> V_214 . V_256 ,
V_213 -> V_214 . V_257 ) ;
}
V_99 = F_135 ( & V_18 -> V_51 -> V_273 , & V_213 -> V_269 . V_54 . V_273 , L_47 ) ;
if ( V_99 ) {
F_69 ( V_286
L_62 ,
V_99 ) ;
goto V_48;
}
V_18 -> V_274 = F_136 ( V_47 , L_63 , V_277 ) ;
if ( ! V_18 -> V_274 ) {
V_99 = - V_52 ;
F_69 ( V_286
L_64 ,
V_99 ) ;
goto V_48;
}
V_99 = F_135 ( & V_213 -> V_269 . V_54 . V_273 , & V_18 -> V_51 -> V_273 ,
V_18 -> V_274 ) ;
if ( V_99 ) {
F_17 ( V_18 -> V_274 ) ;
V_18 -> V_274 = NULL ;
F_69 ( V_286
L_58
L_65 ,
V_99 ) ;
goto V_48;
}
return 0 ;
V_48:
F_127 ( V_18 ) ;
return V_99 ;
}
static int
F_137 ( T_1 V_18 , int V_158 )
{
struct V_166 V_14 ;
struct V_61 V_287 ;
V_287 . V_7 = V_60 ;
V_287 . V_59 = V_77 ;
V_287 . V_64 = 0 ;
V_14 . V_91 = V_171 ;
V_14 . V_105 = V_288 ;
V_14 . V_93 = NULL ;
V_14 . V_92 = 0 ;
return F_78 ( NULL ,
V_18 ,
(struct V_5 * ) & V_287 ,
0 ,
& V_14 ,
V_18 ,
NULL ,
NULL ,
0 ,
V_18 -> V_139 [ 0 ] . V_138 ,
V_18 -> V_139 [ 0 ] . V_64 ,
- 1 , 0 ) ;
}
static void
F_138 ( T_1 V_18 , struct V_13 * V_14 )
{
if ( ( V_14 -> V_6 . V_7 != V_60 )
|| ( V_14 -> V_14 . V_91 != V_289 )
|| ( V_14 -> V_14 . V_105 != V_288 ) )
return;
if ( V_14 -> V_14 . V_93 [ 0 ] != 0 ) {
V_18 -> V_213 -> V_271 = 0 ;
goto V_154;
}
if ( V_14 -> V_14 . V_92 < 17 ) {
V_18 -> V_213 -> V_271 = 0 ;
F_69 (KERN_WARNING PFX
L_66
L_67
L_68 ,
msg->msg.data_len) ;
goto V_154;
}
memcpy ( V_18 -> V_213 -> V_252 , V_14 -> V_14 . V_93 , 16 ) ;
V_18 -> V_213 -> V_271 = 1 ;
V_154:
F_139 ( & V_18 -> V_290 ) ;
}
static void
F_140 ( T_1 V_18 )
{
int V_99 ;
V_18 -> V_213 -> V_271 = 0x2 ;
V_18 -> V_81 = F_138 ;
V_99 = F_137 ( V_18 , 0 ) ;
if ( V_99 )
V_18 -> V_213 -> V_271 = 0 ;
F_141 ( V_18 -> V_290 , V_18 -> V_213 -> V_271 != 2 ) ;
V_18 -> V_81 = NULL ;
}
static int
F_142 ( T_1 V_18 , int V_158 )
{
struct V_166 V_14 ;
unsigned char V_93 [ 1 ] ;
struct V_61 V_287 ;
V_287 . V_7 = V_60 ;
V_287 . V_59 = V_77 ;
V_287 . V_64 = 0 ;
V_14 . V_91 = V_171 ;
V_14 . V_105 = V_291 ;
V_14 . V_93 = V_93 ;
V_14 . V_92 = 1 ;
V_93 [ 0 ] = V_158 ;
return F_78 ( NULL ,
V_18 ,
(struct V_5 * ) & V_287 ,
0 ,
& V_14 ,
V_18 ,
NULL ,
NULL ,
0 ,
V_18 -> V_139 [ 0 ] . V_138 ,
V_18 -> V_139 [ 0 ] . V_64 ,
- 1 , 0 ) ;
}
static void
F_143 ( T_1 V_18 , struct V_13 * V_14 )
{
int V_99 = 0 ;
int V_158 ;
if ( ( V_14 -> V_6 . V_7 == V_60 )
&& ( V_14 -> V_14 . V_91 == V_289 )
&& ( V_14 -> V_14 . V_105 == V_291 ) ) {
if ( V_14 -> V_14 . V_93 [ 0 ] != 0 ) {
if ( V_14 -> V_14 . V_93 [ 0 ] == V_292 ) {
V_18 -> V_139 [ 0 ] . V_198
= V_199 ;
V_18 -> V_139 [ 0 ] . V_293
= V_294 ;
V_18 -> V_295 = V_78 ;
F_139 ( & V_18 -> V_290 ) ;
goto V_154;
}
goto V_296;
}
if ( V_14 -> V_14 . V_92 < 4 ) {
goto V_296;
}
V_158 = V_18 -> V_295 ;
V_18 -> V_139 [ V_158 ] . V_198 = V_14 -> V_14 . V_93 [ 2 ] & 0x7f ;
V_18 -> V_139 [ V_158 ] . V_293 = V_14 -> V_14 . V_93 [ 3 ] & 0x1f ;
V_296:
V_18 -> V_295 ++ ;
if ( V_18 -> V_295 >= V_78 )
F_139 ( & V_18 -> V_290 ) ;
else
V_99 = F_142 ( V_18 , V_18 -> V_295 ) ;
if ( V_99 ) {
F_69 (KERN_WARNING PFX
L_69
L_70 , intf->curr_channel, rv) ;
V_18 -> V_295 = V_78 ;
F_139 ( & V_18 -> V_290 ) ;
}
}
V_154:
return;
}
static void F_144 ( T_1 V_18 )
{
if ( V_18 -> V_118 -> V_297 )
V_18 -> V_118 -> V_297 ( V_18 -> V_121 ) ;
F_145 ( V_18 ) ;
}
void F_146 ( T_2 V_79 )
{
F_144 ( V_79 -> V_18 ) ;
}
int F_147 ( struct V_127 * V_118 ,
void * V_121 ,
struct V_298 * V_257 ,
struct V_53 * V_51 ,
unsigned char V_68 )
{
int V_19 , V_299 ;
int V_99 ;
T_1 V_18 ;
T_1 V_300 ;
struct V_11 * V_16 ;
if ( ! V_114 ) {
V_99 = F_48 () ;
if ( V_99 )
return V_99 ;
if ( ! V_114 )
return - V_106 ;
}
V_18 = F_148 ( sizeof( * V_18 ) , V_47 ) ;
if ( ! V_18 )
return - V_52 ;
V_18 -> V_136 = V_136 ( V_257 ) ;
V_18 -> V_137 = V_137 ( V_257 ) ;
V_18 -> V_213 = F_148 ( sizeof( * V_18 -> V_213 ) , V_47 ) ;
if ( ! V_18 -> V_213 ) {
F_17 ( V_18 ) ;
return - V_52 ;
}
V_18 -> V_46 = - 1 ;
F_50 ( & V_18 -> V_37 ) ;
V_18 -> V_213 -> V_214 = * V_257 ;
V_18 -> V_51 = V_51 ;
for ( V_299 = 0 ; V_299 < V_78 ; V_299 ++ ) {
V_18 -> V_139 [ V_299 ] . V_138 = V_301 ;
V_18 -> V_139 [ V_299 ] . V_64 = 2 ;
}
if ( V_68 != 0 )
V_18 -> V_139 [ 0 ] . V_138 = V_68 ;
F_14 ( & V_18 -> V_123 ) ;
V_18 -> V_118 = V_118 ;
V_18 -> V_121 = V_121 ;
F_149 ( & V_18 -> V_108 ) ;
for ( V_299 = 0 ; V_299 < V_30 ; V_299 ++ ) {
V_18 -> V_31 [ V_299 ] . V_32 = 0 ;
V_18 -> V_31 [ V_299 ] . V_98 = 0 ;
}
V_18 -> V_100 = 0 ;
#ifdef F_100
F_150 ( & V_18 -> V_243 ) ;
#endif
F_149 ( & V_18 -> V_302 ) ;
F_14 ( & V_18 -> V_25 ) ;
F_151 ( & V_18 -> V_24 ,
V_303 ,
( unsigned long ) V_18 ) ;
F_152 ( & V_18 -> V_304 , 0 ) ;
F_149 ( & V_18 -> V_177 ) ;
F_14 ( & V_18 -> V_180 ) ;
F_14 ( & V_18 -> V_179 ) ;
F_149 ( & V_18 -> V_153 ) ;
F_152 ( & V_18 -> V_125 , 0 ) ;
V_18 -> V_305 = V_306 ;
F_14 ( & V_18 -> V_26 ) ;
V_18 -> V_156 = 0 ;
F_150 ( & V_18 -> V_27 ) ;
F_149 ( & V_18 -> V_142 ) ;
F_14 ( & V_18 -> V_28 ) ;
F_153 ( & V_18 -> V_290 ) ;
for ( V_19 = 0 ; V_19 < V_307 ; V_19 ++ )
F_152 ( & V_18 -> V_308 [ V_19 ] , 0 ) ;
V_18 -> V_242 = NULL ;
F_13 ( & V_44 ) ;
F_13 ( & V_45 ) ;
V_19 = 0 ;
V_16 = & V_309 ;
F_49 (tintf, &ipmi_interfaces, link) {
if ( V_300 -> V_46 != V_19 ) {
V_16 = & V_300 -> V_16 ;
break;
}
V_19 ++ ;
}
if ( V_19 == 0 )
F_51 ( & V_18 -> V_16 , & V_309 ) ;
else
F_154 ( & V_18 -> V_16 , V_16 ) ;
V_99 = V_118 -> V_310 ( V_121 , V_18 ) ;
if ( V_99 )
goto V_154;
F_140 ( V_18 ) ;
if ( ( V_18 -> V_136 > 1 )
|| ( ( V_18 -> V_136 == 1 )
&& ( V_18 -> V_137 >= 5 ) ) ) {
V_18 -> V_81 = F_143 ;
V_18 -> V_295 = 0 ;
V_99 = F_142 ( V_18 , 0 ) ;
if ( V_99 ) {
F_69 (KERN_WARNING PFX
L_69
L_71 , rv) ;
goto V_154;
}
F_141 ( V_18 -> V_290 ,
V_18 -> V_295 >= V_78 ) ;
V_18 -> V_81 = NULL ;
} else {
V_18 -> V_139 [ 0 ] . V_198 = V_199 ;
V_18 -> V_139 [ 0 ] . V_293 = V_294 ;
V_18 -> V_295 = V_78 ;
}
if ( V_99 == 0 )
V_99 = F_103 ( V_18 , V_19 ) ;
V_99 = F_131 ( V_18 , V_19 ) ;
V_154:
if ( V_99 ) {
if ( V_18 -> V_242 )
F_105 ( V_18 ) ;
V_18 -> V_118 = NULL ;
F_57 ( & V_18 -> V_16 ) ;
F_16 ( & V_45 ) ;
F_16 ( & V_44 ) ;
V_29 () ;
F_27 ( & V_18 -> V_37 , F_18 ) ;
} else {
F_155 () ;
V_18 -> V_46 = V_19 ;
F_16 ( & V_45 ) ;
F_29 ( V_19 , V_18 -> V_51 ) ;
F_16 ( & V_44 ) ;
}
return V_99 ;
}
static void F_156 ( T_1 V_18 ,
struct V_17 * V_14 ,
unsigned char V_87 )
{
V_14 -> V_311 [ 0 ] = V_14 -> V_93 [ 0 ] | 4 ;
V_14 -> V_311 [ 1 ] = V_14 -> V_93 [ 1 ] ;
V_14 -> V_311 [ 2 ] = V_87 ;
V_14 -> V_312 = 3 ;
F_157 ( V_18 , V_14 ) ;
}
static void F_158 ( T_1 V_18 )
{
int V_19 ;
struct V_31 * V_110 ;
struct V_17 * V_14 ;
struct V_11 * V_241 ;
struct V_11 V_313 ;
F_14 ( & V_313 ) ;
F_159 ( & V_18 -> V_179 , & V_313 ) ;
F_159 ( & V_18 -> V_180 , & V_313 ) ;
while ( V_18 -> V_178 && ! F_67 ( & V_18 -> V_25 ) ) {
F_160 ( 1 ) ;
}
while ( ! F_67 ( & V_313 ) ) {
V_241 = V_313 . V_132 ;
F_7 ( V_241 ) ;
V_14 = F_161 ( V_241 , struct V_17 , V_16 ) ;
F_156 ( V_18 , V_14 , V_314 ) ;
}
for ( V_19 = 0 ; V_19 < V_30 ; V_19 ++ ) {
V_110 = & ( V_18 -> V_31 [ V_19 ] ) ;
if ( ! V_110 -> V_32 )
continue;
F_37 ( V_110 -> V_33 , V_314 ) ;
}
}
int F_162 ( T_1 V_18 )
{
struct V_38 * V_55 ;
int V_46 = V_18 -> V_46 ;
T_2 V_79 ;
F_127 ( V_18 ) ;
F_13 ( & V_44 ) ;
F_13 ( & V_45 ) ;
V_18 -> V_46 = - 1 ;
V_18 -> V_185 = true ;
F_57 ( & V_18 -> V_16 ) ;
F_16 ( & V_45 ) ;
V_29 () ;
F_158 ( V_18 ) ;
F_13 ( & V_45 ) ;
F_81 () ;
F_49 (user, &intf->users, link) {
F_31 ( V_18 -> V_118 -> V_56 ) ;
if ( V_18 -> V_118 -> V_133 )
V_18 -> V_118 -> V_133 ( V_18 -> V_121 ) ;
}
F_84 () ;
V_18 -> V_118 = NULL ;
F_16 ( & V_45 ) ;
F_105 ( V_18 ) ;
F_22 (w, &smi_watchers, link)
V_55 -> V_315 ( V_46 ) ;
F_16 ( & V_44 ) ;
F_27 ( & V_18 -> V_37 , F_18 ) ;
return 0 ;
}
static int F_163 ( T_1 V_18 ,
struct V_17 * V_14 )
{
struct V_65 V_167 ;
struct V_13 * V_33 ;
if ( V_14 -> V_312 < 11 ) {
F_36 ( V_18 , V_220 ) ;
return 0 ;
}
if ( V_14 -> V_311 [ 2 ] != 0 ) {
return 0 ;
}
V_167 . V_7 = V_9 ;
V_167 . V_68 = V_14 -> V_311 [ 6 ] ;
V_167 . V_59 = V_14 -> V_311 [ 3 ] & 0x0f ;
V_167 . V_64 = V_14 -> V_311 [ 7 ] & 3 ;
if ( F_41 ( V_18 ,
V_14 -> V_311 [ 7 ] >> 2 ,
V_14 -> V_311 [ 3 ] & 0x0f ,
V_14 -> V_311 [ 8 ] ,
( V_14 -> V_311 [ 4 ] >> 2 ) & ( ~ 1 ) ,
(struct V_5 * ) & ( V_167 ) ,
& V_33 ) ) {
F_36 ( V_18 , V_221 ) ;
return 0 ;
}
memcpy ( V_33 -> V_90 ,
& ( V_14 -> V_311 [ 9 ] ) ,
V_14 -> V_312 - 9 ) ;
V_33 -> V_14 . V_91 = V_14 -> V_311 [ 4 ] >> 2 ;
V_33 -> V_14 . V_93 = V_33 -> V_90 ;
V_33 -> V_14 . V_92 = V_14 -> V_312 - 10 ;
V_33 -> V_88 = V_89 ;
F_36 ( V_18 , V_219 ) ;
F_35 ( V_33 ) ;
return 0 ;
}
static int F_164 ( T_1 V_18 ,
struct V_17 * V_14 )
{
struct V_20 * V_21 ;
int V_99 = 0 ;
unsigned char V_91 ;
unsigned char V_105 ;
unsigned char V_158 ;
T_2 V_79 = NULL ;
struct V_65 * V_167 ;
struct V_13 * V_33 ;
if ( V_14 -> V_312 < 10 ) {
F_36 ( V_18 , V_229 ) ;
return 0 ;
}
if ( V_14 -> V_311 [ 2 ] != 0 ) {
return 0 ;
}
V_91 = V_14 -> V_311 [ 4 ] >> 2 ;
V_105 = V_14 -> V_311 [ 8 ] ;
V_158 = V_14 -> V_311 [ 3 ] & 0xf ;
F_81 () ;
V_21 = F_70 ( V_18 , V_91 , V_105 , V_158 ) ;
if ( V_21 ) {
V_79 = V_21 -> V_79 ;
F_24 ( & V_79 -> V_37 ) ;
} else
V_79 = NULL ;
F_84 () ;
if ( V_79 == NULL ) {
F_36 ( V_18 , V_230 ) ;
V_14 -> V_93 [ 0 ] = ( V_171 << 2 ) ;
V_14 -> V_93 [ 1 ] = V_172 ;
V_14 -> V_93 [ 2 ] = V_14 -> V_311 [ 3 ] ;
V_14 -> V_93 [ 3 ] = V_14 -> V_311 [ 6 ] ;
V_14 -> V_93 [ 4 ] = ( ( V_91 + 1 ) << 2 ) | ( V_14 -> V_311 [ 7 ] & 0x3 ) ;
V_14 -> V_93 [ 5 ] = F_74 ( & ( V_14 -> V_93 [ 3 ] ) , 2 ) ;
V_14 -> V_93 [ 6 ] = V_18 -> V_139 [ V_14 -> V_311 [ 3 ] & 0xf ] . V_138 ;
V_14 -> V_93 [ 7 ] = ( V_14 -> V_311 [ 7 ] & 0xfc ) | ( V_14 -> V_311 [ 4 ] & 0x3 ) ;
V_14 -> V_93 [ 8 ] = V_14 -> V_311 [ 8 ] ;
V_14 -> V_93 [ 9 ] = V_316 ;
V_14 -> V_93 [ 10 ] = F_74 ( & ( V_14 -> V_93 [ 6 ] ) , 4 ) ;
V_14 -> V_173 = 11 ;
#ifdef F_83
{
int V_206 ;
F_69 ( L_72 ) ;
for ( V_206 = 0 ; V_206 < V_14 -> V_173 ; V_206 ++ )
F_69 ( L_3 , V_14 -> V_93 [ V_206 ] ) ;
F_69 ( L_4 ) ;
}
#endif
F_81 () ;
if ( ! V_18 -> V_185 ) {
F_77 ( V_18 , V_18 -> V_118 , V_14 , 0 ) ;
V_99 = - 1 ;
}
F_84 () ;
} else {
F_36 ( V_18 , V_228 ) ;
V_33 = F_79 () ;
if ( ! V_33 ) {
V_99 = 1 ;
F_27 ( & V_79 -> V_37 , F_54 ) ;
} else {
V_167 = (struct V_65 * ) & V_33 -> V_6 ;
V_167 -> V_7 = V_9 ;
V_167 -> V_68 = V_14 -> V_311 [ 6 ] ;
V_167 -> V_64 = V_14 -> V_311 [ 7 ] & 3 ;
V_167 -> V_59 = V_14 -> V_311 [ 3 ] & 0xf ;
V_33 -> V_79 = V_79 ;
V_33 -> V_88 = V_317 ;
V_33 -> V_109 = V_14 -> V_311 [ 7 ] >> 2 ;
V_33 -> V_14 . V_91 = V_14 -> V_311 [ 4 ] >> 2 ;
V_33 -> V_14 . V_105 = V_14 -> V_311 [ 8 ] ;
V_33 -> V_14 . V_93 = V_33 -> V_90 ;
V_33 -> V_14 . V_92 = V_14 -> V_312 - 10 ;
memcpy ( V_33 -> V_90 ,
& ( V_14 -> V_311 [ 9 ] ) ,
V_14 -> V_312 - 10 ) ;
F_35 ( V_33 ) ;
}
}
return V_99 ;
}
static int F_165 ( T_1 V_18 ,
struct V_17 * V_14 )
{
struct V_69 V_174 ;
struct V_13 * V_33 ;
if ( V_14 -> V_312 < 13 ) {
F_36 ( V_18 , V_226 ) ;
return 0 ;
}
if ( V_14 -> V_311 [ 2 ] != 0 ) {
return 0 ;
}
V_174 . V_7 = V_8 ;
V_174 . V_74 = V_14 -> V_311 [ 4 ] ;
V_174 . V_72 = V_14 -> V_311 [ 8 ] ;
V_174 . V_73 = V_14 -> V_311 [ 5 ] ;
V_174 . V_59 = V_14 -> V_311 [ 3 ] & 0x0f ;
V_174 . V_318 = V_14 -> V_311 [ 3 ] >> 4 ;
V_174 . V_64 = V_14 -> V_311 [ 9 ] & 3 ;
if ( F_41 ( V_18 ,
V_14 -> V_311 [ 9 ] >> 2 ,
V_14 -> V_311 [ 3 ] & 0x0f ,
V_14 -> V_311 [ 10 ] ,
( V_14 -> V_311 [ 6 ] >> 2 ) & ( ~ 1 ) ,
(struct V_5 * ) & ( V_174 ) ,
& V_33 ) ) {
F_36 ( V_18 , V_227 ) ;
return 0 ;
}
memcpy ( V_33 -> V_90 ,
& ( V_14 -> V_311 [ 11 ] ) ,
V_14 -> V_312 - 11 ) ;
V_33 -> V_14 . V_91 = V_14 -> V_311 [ 6 ] >> 2 ;
V_33 -> V_14 . V_93 = V_33 -> V_90 ;
V_33 -> V_14 . V_92 = V_14 -> V_312 - 12 ;
V_33 -> V_88 = V_89 ;
F_36 ( V_18 , V_225 ) ;
F_35 ( V_33 ) ;
return 0 ;
}
static int F_166 ( T_1 V_18 ,
struct V_17 * V_14 )
{
struct V_20 * V_21 ;
int V_99 = 0 ;
unsigned char V_91 ;
unsigned char V_105 ;
unsigned char V_158 ;
T_2 V_79 = NULL ;
struct V_69 * V_174 ;
struct V_13 * V_33 ;
if ( V_14 -> V_312 < 12 ) {
F_36 ( V_18 , V_229 ) ;
return 0 ;
}
if ( V_14 -> V_311 [ 2 ] != 0 ) {
return 0 ;
}
V_91 = V_14 -> V_311 [ 6 ] >> 2 ;
V_105 = V_14 -> V_311 [ 10 ] ;
V_158 = V_14 -> V_311 [ 3 ] & 0xf ;
F_81 () ;
V_21 = F_70 ( V_18 , V_91 , V_105 , V_158 ) ;
if ( V_21 ) {
V_79 = V_21 -> V_79 ;
F_24 ( & V_79 -> V_37 ) ;
} else
V_79 = NULL ;
F_84 () ;
if ( V_79 == NULL ) {
F_36 ( V_18 , V_230 ) ;
V_99 = 0 ;
} else {
F_36 ( V_18 , V_228 ) ;
V_33 = F_79 () ;
if ( ! V_33 ) {
V_99 = 1 ;
F_27 ( & V_79 -> V_37 , F_54 ) ;
} else {
V_174 = (struct V_69 * ) & V_33 -> V_6 ;
V_174 -> V_7 = V_8 ;
V_174 -> V_74 = V_14 -> V_311 [ 4 ] ;
V_174 -> V_72 = V_14 -> V_311 [ 8 ] ;
V_174 -> V_73 = V_14 -> V_311 [ 5 ] ;
V_174 -> V_64 = V_14 -> V_311 [ 9 ] & 3 ;
V_174 -> V_59 = V_14 -> V_311 [ 3 ] & 0xf ;
V_174 -> V_318 = V_14 -> V_311 [ 3 ] >> 4 ;
V_33 -> V_79 = V_79 ;
V_33 -> V_88 = V_317 ;
V_33 -> V_109 = V_14 -> V_311 [ 9 ] >> 2 ;
V_33 -> V_14 . V_91 = V_14 -> V_311 [ 6 ] >> 2 ;
V_33 -> V_14 . V_105 = V_14 -> V_311 [ 10 ] ;
V_33 -> V_14 . V_93 = V_33 -> V_90 ;
V_33 -> V_14 . V_92 = V_14 -> V_312 - 12 ;
memcpy ( V_33 -> V_90 ,
& ( V_14 -> V_311 [ 11 ] ) ,
V_14 -> V_312 - 12 ) ;
F_35 ( V_33 ) ;
}
}
return V_99 ;
}
static int F_167 ( T_1 V_18 ,
struct V_17 * V_14 )
{
struct V_20 * V_21 ;
int V_99 = 0 ;
unsigned char V_91 ;
unsigned char V_105 ;
unsigned char V_158 ;
T_2 V_79 = NULL ;
struct V_61 * V_186 ;
struct V_13 * V_33 ;
if ( V_14 -> V_312 < 4 ) {
F_36 ( V_18 , V_229 ) ;
return 0 ;
}
if ( V_14 -> V_311 [ 2 ] != 0 ) {
return 0 ;
}
V_91 = V_14 -> V_311 [ 0 ] >> 2 ;
V_105 = V_14 -> V_311 [ 1 ] ;
V_158 = V_14 -> V_311 [ 3 ] & 0xf ;
F_81 () ;
V_21 = F_70 ( V_18 , V_91 , V_105 , V_158 ) ;
if ( V_21 ) {
V_79 = V_21 -> V_79 ;
F_24 ( & V_79 -> V_37 ) ;
} else
V_79 = NULL ;
F_84 () ;
if ( V_79 == NULL ) {
F_36 ( V_18 , V_230 ) ;
V_99 = 0 ;
} else {
F_36 ( V_18 , V_228 ) ;
V_33 = F_79 () ;
if ( ! V_33 ) {
V_99 = 1 ;
F_27 ( & V_79 -> V_37 , F_54 ) ;
} else {
V_186 = ( (struct V_61 * )
& ( V_33 -> V_6 ) ) ;
V_186 -> V_7 = V_60 ;
V_186 -> V_59 = V_77 ;
V_186 -> V_64 = V_14 -> V_311 [ 0 ] & 3 ;
V_33 -> V_79 = V_79 ;
V_33 -> V_80 = NULL ;
V_33 -> V_88 = V_319 ;
V_33 -> V_14 . V_91 = V_14 -> V_311 [ 0 ] >> 2 ;
V_33 -> V_14 . V_105 = V_14 -> V_311 [ 1 ] ;
V_33 -> V_14 . V_93 = V_33 -> V_90 ;
V_33 -> V_14 . V_92 = V_14 -> V_312 - 4 ;
memcpy ( V_33 -> V_90 ,
& ( V_14 -> V_311 [ 4 ] ) ,
V_14 -> V_312 - 4 ) ;
F_35 ( V_33 ) ;
}
}
return V_99 ;
}
static void F_168 ( struct V_13 * V_33 ,
struct V_17 * V_14 )
{
struct V_61 * V_186 ;
V_33 -> V_109 = 0 ;
V_186 = (struct V_61 * ) & ( V_33 -> V_6 ) ;
V_186 -> V_7 = V_60 ;
V_186 -> V_59 = V_77 ;
V_186 -> V_64 = V_14 -> V_311 [ 0 ] & 3 ;
V_33 -> V_88 = V_320 ;
V_33 -> V_14 . V_91 = V_14 -> V_311 [ 0 ] >> 2 ;
V_33 -> V_14 . V_105 = V_14 -> V_311 [ 1 ] ;
memcpy ( V_33 -> V_90 , & ( V_14 -> V_311 [ 3 ] ) , V_14 -> V_312 - 3 ) ;
V_33 -> V_14 . V_93 = V_33 -> V_90 ;
V_33 -> V_14 . V_92 = V_14 -> V_312 - 3 ;
}
static int F_169 ( T_1 V_18 ,
struct V_17 * V_14 )
{
struct V_13 * V_33 , * V_321 ;
struct V_11 V_152 ;
T_2 V_79 ;
int V_99 = 0 ;
int V_322 = 0 ;
unsigned long V_107 ;
if ( V_14 -> V_312 < 19 ) {
F_36 ( V_18 , V_231 ) ;
return 0 ;
}
if ( V_14 -> V_311 [ 2 ] != 0 ) {
return 0 ;
}
F_14 ( & V_152 ) ;
F_42 ( & V_18 -> V_153 , V_107 ) ;
F_36 ( V_18 , V_232 ) ;
F_81 () ;
F_49 (user, &intf->users, link) {
if ( ! V_79 -> V_117 )
continue;
V_33 = F_79 () ;
if ( ! V_33 ) {
F_84 () ;
F_6 (recv_msg, recv_msg2, &msgs,
link) {
F_7 ( & V_33 -> V_16 ) ;
F_8 ( V_33 ) ;
}
V_99 = 1 ;
goto V_154;
}
V_322 ++ ;
F_168 ( V_33 , V_14 ) ;
V_33 -> V_79 = V_79 ;
F_24 ( & V_79 -> V_37 ) ;
F_25 ( & ( V_33 -> V_16 ) , & V_152 ) ;
}
F_84 () ;
if ( V_322 ) {
F_6 (recv_msg, recv_msg2, &msgs, link) {
F_7 ( & V_33 -> V_16 ) ;
F_35 ( V_33 ) ;
}
} else if ( V_18 -> V_156 < V_323 ) {
V_33 = F_79 () ;
if ( ! V_33 ) {
V_99 = 1 ;
goto V_154;
}
F_168 ( V_33 , V_14 ) ;
F_25 ( & ( V_33 -> V_16 ) , & ( V_18 -> V_26 ) ) ;
V_18 -> V_156 ++ ;
} else if ( ! V_18 -> V_157 ) {
F_69 (KERN_WARNING PFX L_73
L_74 ) ;
V_18 -> V_157 = 1 ;
}
V_154:
F_43 ( & ( V_18 -> V_153 ) , V_107 ) ;
return V_99 ;
}
static int F_170 ( T_1 V_18 ,
struct V_17 * V_14 )
{
struct V_13 * V_33 ;
struct V_130 * V_79 ;
V_33 = (struct V_13 * ) V_14 -> V_196 ;
if ( V_33 == NULL ) {
F_69 ( V_324
L_75
L_76
L_77
L_78 ) ;
return 0 ;
}
V_79 = V_33 -> V_79 ;
if ( V_79 && ! V_79 -> V_122 ) {
F_36 ( V_18 , V_83 ) ;
F_8 ( V_33 ) ;
} else {
struct V_61 * V_186 ;
F_36 ( V_18 , V_82 ) ;
V_33 -> V_88 = V_89 ;
V_33 -> V_109 = V_14 -> V_109 ;
V_186 = ( (struct V_61 * )
& ( V_33 -> V_6 ) ) ;
V_186 -> V_7 = V_60 ;
V_186 -> V_59 = V_77 ;
V_186 -> V_64 = V_14 -> V_311 [ 0 ] & 3 ;
V_33 -> V_14 . V_91 = V_14 -> V_311 [ 0 ] >> 2 ;
V_33 -> V_14 . V_105 = V_14 -> V_311 [ 1 ] ;
memcpy ( V_33 -> V_90 ,
& ( V_14 -> V_311 [ 2 ] ) ,
V_14 -> V_312 - 2 ) ;
V_33 -> V_14 . V_93 = V_33 -> V_90 ;
V_33 -> V_14 . V_92 = V_14 -> V_312 - 2 ;
F_35 ( V_33 ) ;
}
return 0 ;
}
static int F_157 ( T_1 V_18 ,
struct V_17 * V_14 )
{
int V_325 ;
int V_158 ;
#ifdef F_83
int V_206 ;
F_69 ( L_79 ) ;
for ( V_206 = 0 ; V_206 < V_14 -> V_312 ; V_206 ++ )
F_69 ( L_3 , V_14 -> V_311 [ V_206 ] ) ;
F_69 ( L_4 ) ;
#endif
if ( V_14 -> V_312 < 2 ) {
F_69 (KERN_WARNING PFX L_80
L_81 ,
(msg->data[0] >> 2) | 1 , msg->data[1], msg->rsp_size) ;
V_14 -> V_311 [ 0 ] = V_14 -> V_93 [ 0 ] | ( 1 << 2 ) ;
V_14 -> V_311 [ 1 ] = V_14 -> V_93 [ 1 ] ;
V_14 -> V_311 [ 2 ] = V_314 ;
V_14 -> V_312 = 3 ;
} else if ( ( ( V_14 -> V_311 [ 0 ] >> 2 ) != ( ( V_14 -> V_93 [ 0 ] >> 2 ) | 1 ) )
|| ( V_14 -> V_311 [ 1 ] != V_14 -> V_93 [ 1 ] ) ) {
F_69 (KERN_WARNING PFX L_82
L_83 ,
(msg->data[0] >> 2) | 1 , msg->data[1],
msg->rsp[0] >> 2 , msg->rsp[1]) ;
V_14 -> V_311 [ 0 ] = V_14 -> V_93 [ 0 ] | ( 1 << 2 ) ;
V_14 -> V_311 [ 1 ] = V_14 -> V_93 [ 1 ] ;
V_14 -> V_311 [ 2 ] = V_314 ;
V_14 -> V_312 = 3 ;
}
if ( ( V_14 -> V_311 [ 0 ] == ( ( V_171 | 1 ) << 2 ) )
&& ( V_14 -> V_311 [ 1 ] == V_172 )
&& ( V_14 -> V_196 != NULL ) ) {
struct V_13 * V_33 = V_14 -> V_196 ;
V_325 = 0 ;
if ( V_14 -> V_312 < 2 )
goto V_154;
V_158 = V_14 -> V_93 [ 2 ] & 0x0f ;
if ( V_158 >= V_78 )
goto V_154;
if ( ! V_33 )
goto V_154;
if ( ! V_33 -> V_79 || ! V_33 -> V_79 -> V_122 )
goto V_154;
V_33 -> V_88 = V_326 ;
V_33 -> V_14 . V_93 = V_33 -> V_90 ;
V_33 -> V_14 . V_92 = 1 ;
V_33 -> V_90 [ 0 ] = V_14 -> V_311 [ 2 ] ;
F_35 ( V_33 ) ;
} else if ( ( V_14 -> V_311 [ 0 ] == ( ( V_171 | 1 ) << 2 ) )
&& ( V_14 -> V_311 [ 1 ] == V_188 ) ) {
V_158 = V_14 -> V_311 [ 3 ] & 0xf ;
if ( V_158 >= V_78 ) {
V_325 = 0 ;
goto V_154;
}
if ( V_18 -> V_295 < V_78 ) {
V_325 = 0 ;
goto V_154;
}
switch ( V_18 -> V_139 [ V_158 ] . V_198 ) {
case V_199 :
if ( V_14 -> V_311 [ 4 ] & 0x04 ) {
V_325 = F_163 ( V_18 , V_14 ) ;
} else {
V_325 = F_164 ( V_18 , V_14 ) ;
}
break;
case V_202 :
case V_203 :
if ( V_14 -> V_311 [ 6 ] & 0x04 ) {
V_325 = F_165 ( V_18 , V_14 ) ;
} else {
V_325 = F_166 ( V_18 , V_14 ) ;
}
break;
default:
if ( ( V_18 -> V_139 [ V_158 ] . V_198
>= V_327 )
&& ( V_18 -> V_139 [ V_158 ] . V_198
<= V_328 ) ) {
V_325 = F_167 ( V_18 , V_14 ) ;
} else {
V_325 = 0 ;
}
}
} else if ( ( V_14 -> V_311 [ 0 ] == ( ( V_171 | 1 ) << 2 ) )
&& ( V_14 -> V_311 [ 1 ] == V_189 ) ) {
V_325 = F_169 ( V_18 , V_14 ) ;
} else {
V_325 = F_170 ( V_18 , V_14 ) ;
}
V_154:
return V_325 ;
}
static void F_145 ( T_1 V_18 )
{
struct V_17 * V_165 ;
unsigned long V_107 = 0 ;
int V_99 ;
int V_176 = V_18 -> V_176 ;
if ( ! V_176 )
F_42 ( & V_18 -> V_302 , V_107 ) ;
while ( ! F_67 ( & V_18 -> V_25 ) ) {
V_165 = F_161 ( V_18 -> V_25 . V_132 ,
struct V_17 , V_16 ) ;
if ( ! V_176 )
F_43 ( & V_18 -> V_302 ,
V_107 ) ;
V_99 = F_157 ( V_18 , V_165 ) ;
if ( ! V_176 )
F_42 ( & V_18 -> V_302 , V_107 ) ;
if ( V_99 > 0 ) {
break;
} else {
F_7 ( & V_165 -> V_16 ) ;
if ( V_99 == 0 )
F_10 ( V_165 ) ;
}
}
if ( ! V_176 )
F_43 ( & V_18 -> V_302 , V_107 ) ;
if ( F_171 ( & V_18 -> V_304 , - 1 , 0 ) ) {
T_2 V_79 ;
F_81 () ;
F_49 (user, &intf->users, link) {
if ( V_79 -> V_84 -> V_124 )
V_79 -> V_84 -> V_124 (
V_79 -> V_86 ) ;
}
F_84 () ;
}
}
static void V_303 ( unsigned long V_151 )
{
unsigned long V_107 = 0 ;
T_1 V_18 = ( T_1 ) V_151 ;
int V_176 = V_18 -> V_176 ;
struct V_17 * V_329 = NULL ;
if ( ! V_176 )
F_42 ( & V_18 -> V_177 , V_107 ) ;
if ( V_18 -> V_178 == NULL && ! V_18 -> V_185 ) {
struct V_11 * V_241 = NULL ;
if ( ! F_67 ( & V_18 -> V_179 ) )
V_241 = V_18 -> V_179 . V_132 ;
else if ( ! F_67 ( & V_18 -> V_180 ) )
V_241 = V_18 -> V_180 . V_132 ;
if ( V_241 ) {
F_7 ( V_241 ) ;
V_329 = F_161 ( V_241 , struct V_17 , V_16 ) ;
V_18 -> V_178 = V_329 ;
}
}
if ( ! V_176 )
F_43 ( & V_18 -> V_177 , V_107 ) ;
if ( V_329 )
V_18 -> V_118 -> V_181 ( V_18 -> V_121 , V_329 ) ;
F_145 ( V_18 ) ;
}
void F_172 ( T_1 V_18 ,
struct V_17 * V_14 )
{
unsigned long V_107 = 0 ;
int V_176 = V_18 -> V_176 ;
if ( ( V_14 -> V_173 >= 2 )
&& ( V_14 -> V_93 [ 0 ] == ( V_171 << 2 ) )
&& ( V_14 -> V_93 [ 1 ] == V_172 )
&& ( V_14 -> V_196 == NULL ) ) {
if ( V_18 -> V_185 )
goto V_330;
if ( ( V_14 -> V_312 >= 3 ) && ( V_14 -> V_311 [ 2 ] != 0 )
&& ( V_14 -> V_311 [ 2 ] != V_331 )
&& ( V_14 -> V_311 [ 2 ] != V_332 )
&& ( V_14 -> V_311 [ 2 ] != V_333 )
&& ( V_14 -> V_311 [ 2 ] != V_334 ) ) {
int V_158 = V_14 -> V_311 [ 3 ] & 0xf ;
if ( V_158 >= V_78 )
;
else if ( ( V_18 -> V_139 [ V_158 ] . V_198
== V_202 )
|| ( V_18 -> V_139 [ V_158 ] . V_198
== V_203 ) )
F_36 ( V_18 , V_222 ) ;
else
F_36 ( V_18 , V_215 ) ;
F_46 ( V_18 , V_14 -> V_109 , V_14 -> V_311 [ 2 ] ) ;
} else
F_44 ( V_18 , V_14 -> V_109 ) ;
V_330:
F_10 ( V_14 ) ;
} else {
if ( ! V_176 )
F_42 ( & V_18 -> V_302 , V_107 ) ;
F_25 ( & V_14 -> V_16 , & V_18 -> V_25 ) ;
if ( ! V_176 )
F_43 ( & V_18 -> V_302 ,
V_107 ) ;
}
if ( ! V_176 )
F_42 ( & V_18 -> V_177 , V_107 ) ;
if ( V_14 == V_18 -> V_178 )
V_18 -> V_178 = NULL ;
if ( ! V_176 )
F_43 ( & V_18 -> V_177 , V_107 ) ;
if ( V_176 )
V_303 ( ( unsigned long ) V_18 ) ;
else
F_173 ( & V_18 -> V_24 ) ;
}
void F_174 ( T_1 V_18 )
{
if ( V_18 -> V_185 )
return;
F_152 ( & V_18 -> V_304 , 1 ) ;
F_173 ( & V_18 -> V_24 ) ;
}
static struct V_17 *
F_175 ( T_1 V_18 , struct V_13 * V_33 ,
unsigned char V_97 , long V_98 )
{
struct V_17 * V_165 = F_80 () ;
if ( ! V_165 )
return NULL ;
memcpy ( V_165 -> V_93 , V_33 -> V_14 . V_93 , V_33 -> V_14 . V_92 ) ;
V_165 -> V_173 = V_33 -> V_14 . V_92 ;
V_165 -> V_109 = F_82 ( V_97 , V_98 ) ;
#ifdef F_83
{
int V_206 ;
F_69 ( L_84 ) ;
for ( V_206 = 0 ; V_206 < V_165 -> V_173 ; V_206 ++ )
F_69 ( L_3 , V_165 -> V_93 [ V_206 ] ) ;
F_69 ( L_4 ) ;
}
#endif
return V_165 ;
}
static void F_176 ( T_1 V_18 , struct V_31 * V_110 ,
struct V_11 * V_335 , long V_336 ,
int V_337 , unsigned long * V_107 ,
unsigned int * V_338 )
{
struct V_13 * V_14 ;
struct V_127 * V_118 ;
if ( V_18 -> V_185 )
return;
if ( ! V_110 -> V_32 )
return;
V_110 -> V_94 -= V_336 ;
if ( V_110 -> V_94 > 0 ) {
( * V_338 ) ++ ;
return;
}
if ( V_110 -> V_103 == 0 ) {
V_110 -> V_32 = 0 ;
V_14 = V_110 -> V_33 ;
F_25 ( & V_14 -> V_16 , V_335 ) ;
if ( V_110 -> V_96 )
F_36 ( V_18 , V_218 ) ;
else if ( F_2 ( & V_110 -> V_33 -> V_6 ) )
F_36 ( V_18 , V_224 ) ;
else
F_36 ( V_18 , V_217 ) ;
} else {
struct V_17 * V_165 ;
( * V_338 ) ++ ;
V_110 -> V_94 = V_101 ;
V_110 -> V_103 -- ;
V_165 = F_175 ( V_18 , V_110 -> V_33 , V_337 ,
V_110 -> V_98 ) ;
if ( ! V_165 ) {
if ( F_2 ( & V_110 -> V_33 -> V_6 ) )
F_36 ( V_18 ,
V_233 ) ;
else
F_36 ( V_18 ,
V_234 ) ;
return;
}
F_43 ( & V_18 -> V_108 , * V_107 ) ;
V_118 = V_18 -> V_118 ;
if ( V_118 ) {
if ( F_2 ( & V_110 -> V_33 -> V_6 ) )
F_36 ( V_18 ,
V_223 ) ;
else
F_36 ( V_18 ,
V_216 ) ;
F_77 ( V_18 , V_18 -> V_118 , V_165 , 0 ) ;
} else
F_10 ( V_165 ) ;
F_42 ( & V_18 -> V_108 , * V_107 ) ;
}
}
static unsigned int F_177 ( T_1 V_18 , long V_336 )
{
struct V_11 V_335 ;
struct V_13 * V_14 , * V_15 ;
unsigned long V_107 ;
int V_19 ;
unsigned int V_338 = 0 ;
F_14 ( & V_335 ) ;
F_42 ( & V_18 -> V_108 , V_107 ) ;
for ( V_19 = 0 ; V_19 < V_30 ; V_19 ++ )
F_176 ( V_18 , & ( V_18 -> V_31 [ V_19 ] ) ,
& V_335 , V_336 , V_19 ,
& V_107 , & V_338 ) ;
F_43 ( & V_18 -> V_108 , V_107 ) ;
F_6 (msg, msg2, &timeouts, link)
F_37 ( V_14 , V_339 ) ;
if ( V_18 -> V_147 > 0 ) {
F_42 ( & V_18 -> V_142 , V_107 ) ;
if ( V_18 -> V_147 > 0 ) {
V_18 -> V_147
-= V_336 ;
if ( ! V_18 -> V_143
&& ( V_18 -> V_147 <= 0 ) ) {
V_18 -> V_145 = false ;
F_64 ( V_18 ) ;
}
}
F_43 ( & V_18 -> V_142 ,
V_107 ) ;
}
F_173 ( & V_18 -> V_24 ) ;
return V_338 ;
}
static void F_178 ( T_1 V_18 )
{
if ( V_18 -> V_145 )
return;
if ( ! V_18 -> V_185 )
V_18 -> V_118 -> V_340 ( V_18 -> V_121 ) ;
}
static void F_179 ( unsigned long V_93 )
{
T_1 V_18 ;
int V_341 = 0 ;
if ( F_180 ( & V_342 ) )
return;
F_81 () ;
F_49 (intf, &ipmi_interfaces, link) {
int V_343 = 0 ;
if ( F_180 ( & V_18 -> V_125 ) ) {
V_18 -> V_305 -- ;
if ( V_18 -> V_305 == 0 ) {
F_178 ( V_18 ) ;
V_18 -> V_305 = V_306 ;
}
V_343 ++ ;
}
V_343 += F_177 ( V_18 , V_344 ) ;
V_343 = ! ! V_343 ;
if ( V_343 != V_18 -> V_345 &&
V_18 -> V_118 -> V_346 )
V_18 -> V_118 -> V_346 ( V_18 -> V_121 , V_343 ) ;
V_18 -> V_345 = V_343 ;
V_341 += V_343 ;
}
F_84 () ;
if ( V_341 )
F_181 ( & V_347 , V_348 + V_349 ) ;
}
static void F_40 ( T_1 V_18 )
{
if ( ! F_182 ( & V_347 ) )
F_181 ( & V_347 , V_348 + V_349 ) ;
}
static void F_183 ( struct V_17 * V_14 )
{
F_56 ( & V_350 ) ;
F_17 ( V_14 ) ;
}
struct V_17 * F_80 ( void )
{
struct V_17 * V_99 ;
V_99 = F_23 ( sizeof( struct V_17 ) , V_351 ) ;
if ( V_99 ) {
V_99 -> V_352 = F_183 ;
V_99 -> V_196 = NULL ;
F_184 ( & V_350 ) ;
}
return V_99 ;
}
static void F_185 ( struct V_13 * V_14 )
{
F_56 ( & V_353 ) ;
F_17 ( V_14 ) ;
}
static struct V_13 * F_79 ( void )
{
struct V_13 * V_99 ;
V_99 = F_23 ( sizeof( struct V_13 ) , V_351 ) ;
if ( V_99 ) {
V_99 -> V_79 = NULL ;
V_99 -> V_352 = F_185 ;
F_184 ( & V_353 ) ;
}
return V_99 ;
}
void F_8 ( struct V_13 * V_14 )
{
if ( V_14 -> V_79 )
F_27 ( & V_14 -> V_79 -> V_37 , F_54 ) ;
V_14 -> V_352 ( V_14 ) ;
}
static void F_186 ( struct V_17 * V_14 )
{
F_56 ( & V_354 ) ;
}
static void F_187 ( struct V_13 * V_14 )
{
F_56 ( & V_354 ) ;
}
static void F_188 ( T_1 V_18 ,
struct V_5 * V_6 ,
struct V_166 * V_14 )
{
struct V_17 V_165 ;
struct V_13 V_33 ;
int V_99 ;
V_165 . V_352 = F_186 ;
V_33 . V_352 = F_187 ;
F_189 ( 2 , & V_354 ) ;
V_99 = F_78 ( NULL ,
V_18 ,
V_6 ,
0 ,
V_14 ,
V_18 ,
& V_165 ,
& V_33 ,
0 ,
V_18 -> V_139 [ 0 ] . V_138 ,
V_18 -> V_139 [ 0 ] . V_64 ,
0 , 1 ) ;
if ( V_99 )
F_190 ( 2 , & V_354 ) ;
while ( F_180 ( & V_354 ) != 0 )
F_144 ( V_18 ) ;
}
static void F_191 ( T_1 V_18 , struct V_13 * V_14 )
{
if ( ( V_14 -> V_6 . V_7 == V_60 )
&& ( V_14 -> V_14 . V_91 == V_355 )
&& ( V_14 -> V_14 . V_105 == V_356 )
&& ( V_14 -> V_14 . V_93 [ 0 ] == V_357 ) ) {
V_18 -> V_358 = V_14 -> V_14 . V_93 [ 1 ] ;
V_18 -> V_359 = V_14 -> V_14 . V_93 [ 2 ] & 0x3 ;
}
}
static void F_192 ( T_1 V_18 , struct V_13 * V_14 )
{
if ( ( V_14 -> V_6 . V_7 == V_60 )
&& ( V_14 -> V_14 . V_91 == V_289 )
&& ( V_14 -> V_14 . V_105 == V_360 )
&& ( V_14 -> V_14 . V_93 [ 0 ] == V_357 ) ) {
V_18 -> V_361 = ( V_14 -> V_14 . V_93 [ 6 ] >> 2 ) & 1 ;
V_18 -> V_362 = ( V_14 -> V_14 . V_93 [ 6 ] >> 5 ) & 1 ;
}
}
static void F_193 ( char * V_363 )
{
struct V_166 V_14 ;
T_1 V_18 ;
unsigned char V_93 [ 16 ] ;
struct V_61 * V_287 ;
struct V_5 V_6 ;
V_287 = (struct V_61 * ) & V_6 ;
V_287 -> V_7 = V_60 ;
V_287 -> V_59 = V_77 ;
V_287 -> V_64 = 0 ;
V_14 . V_91 = 0x04 ;
V_14 . V_105 = 2 ;
V_14 . V_93 = V_93 ;
V_14 . V_92 = 8 ;
V_93 [ 0 ] = 0x41 ;
V_93 [ 1 ] = 0x03 ;
V_93 [ 2 ] = 0x20 ;
V_93 [ 4 ] = 0x6f ;
V_93 [ 5 ] = 0xa1 ;
if ( V_363 ) {
V_93 [ 3 ] = V_363 [ 0 ] ;
V_93 [ 6 ] = V_363 [ 1 ] ;
V_93 [ 7 ] = V_363 [ 2 ] ;
}
F_49 (intf, &ipmi_interfaces, link) {
if ( ! V_18 -> V_118 )
continue;
V_18 -> V_176 = 1 ;
V_18 -> V_118 -> V_364 ( V_18 -> V_121 , 1 ) ;
F_188 ( V_18 , & V_6 , & V_14 ) ;
}
#ifdef F_194
if ( ! V_363 )
return;
F_49 (intf, &ipmi_interfaces, link) {
char * V_365 = V_363 ;
struct V_65 * V_366 ;
int V_299 ;
if ( V_18 -> V_46 == - 1 )
continue;
F_195 () ;
V_18 -> V_361 = 0 ;
V_18 -> V_362 = 0 ;
V_18 -> V_358 = 0 ;
V_14 . V_91 = V_171 ;
V_14 . V_105 = V_360 ;
V_14 . V_93 = NULL ;
V_14 . V_92 = 0 ;
V_18 -> V_81 = F_192 ;
F_188 ( V_18 , & V_6 , & V_14 ) ;
if ( V_18 -> V_362 ) {
V_14 . V_91 = V_367 ;
V_14 . V_105 = V_356 ;
V_14 . V_93 = NULL ;
V_14 . V_92 = 0 ;
V_18 -> V_81 = F_191 ;
F_188 ( V_18 , & V_6 , & V_14 ) ;
}
V_18 -> V_81 = NULL ;
if ( ( ( V_18 -> V_358 & 1 ) == 0 )
&& ( V_18 -> V_358 != 0 )
&& ( V_18 -> V_358 != V_18 -> V_139 [ 0 ] . V_138 ) ) {
V_366 = (struct V_65 * ) & V_6 ;
V_366 -> V_7 = V_9 ;
V_366 -> V_59 = 0 ;
V_366 -> V_64 = V_18 -> V_359 ;
V_366 -> V_68 = V_18 -> V_358 ;
} else if ( V_18 -> V_361 ) {
V_287 = (struct V_61 * ) & V_6 ;
V_287 -> V_7 = V_60 ;
V_287 -> V_59 = V_77 ;
V_287 -> V_64 = 0 ;
} else
continue;
V_14 . V_91 = V_368 ;
V_14 . V_105 = V_369 ;
V_14 . V_93 = V_93 ;
V_14 . V_92 = 16 ;
V_299 = 0 ;
while ( * V_365 ) {
int V_163 = strlen ( V_365 ) ;
if ( V_163 > 11 )
V_163 = 11 ;
V_93 [ 0 ] = 0 ;
V_93 [ 1 ] = 0 ;
V_93 [ 2 ] = 0xf0 ;
V_93 [ 3 ] = V_18 -> V_139 [ 0 ] . V_138 ;
V_93 [ 4 ] = V_299 ++ ;
strncpy ( V_93 + 5 , V_365 , 11 ) ;
V_365 += V_163 ;
F_188 ( V_18 , & V_6 , & V_14 ) ;
}
}
#endif
}
static int F_196 ( struct V_370 * V_371 ,
unsigned long V_372 ,
void * V_373 )
{
T_1 V_18 ;
if ( V_374 )
return V_375 ;
V_374 = 1 ;
F_49 (intf, &ipmi_interfaces, link) {
if ( ! V_18 -> V_118 )
continue;
V_18 -> V_176 = 1 ;
V_18 -> V_118 -> V_364 ( V_18 -> V_121 , 1 ) ;
}
#ifdef F_197
F_193 ( V_373 ) ;
#endif
return V_375 ;
}
static int F_48 ( void )
{
int V_99 ;
if ( V_114 )
return 0 ;
V_99 = F_198 ( & V_279 . V_280 ) ;
if ( V_99 ) {
F_69 (KERN_ERR PFX L_85 ) ;
return V_99 ;
}
F_69 ( V_281 L_86
V_376 L_4 ) ;
#ifdef F_100
V_247 = F_104 ( L_87 , NULL ) ;
if ( ! V_247 ) {
F_69 (KERN_ERR PFX L_88 ) ;
F_199 ( & V_279 . V_280 ) ;
return - V_52 ;
}
#endif
F_200 ( & V_347 , F_179 , 0 ) ;
F_181 ( & V_347 , V_348 + V_349 ) ;
F_201 ( & V_377 , & V_378 ) ;
V_114 = 1 ;
return 0 ;
}
static int T_4 F_202 ( void )
{
F_48 () ;
return 0 ;
}
static void T_5 F_203 ( void )
{
int V_379 ;
if ( ! V_114 )
return;
F_204 ( & V_377 , & V_378 ) ;
F_184 ( & V_342 ) ;
F_205 ( & V_347 ) ;
#ifdef F_100
F_206 ( V_247 ) ;
#endif
F_199 ( & V_279 . V_280 ) ;
V_114 = 0 ;
V_379 = F_180 ( & V_350 ) ;
if ( V_379 != 0 )
F_69 (KERN_WARNING PFX L_89 ,
count) ;
V_379 = F_180 ( & V_353 ) ;
if ( V_379 != 0 )
F_69 (KERN_WARNING PFX L_90 ,
count) ;
}
