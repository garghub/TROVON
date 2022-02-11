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
} else if ( ! V_84 ) {
T_2 V_79 = V_14 -> V_79 ;
V_79 -> V_85 -> V_86 ( V_14 , V_79 -> V_87 ) ;
}
}
static void
F_37 ( struct V_13 * V_14 , int V_88 )
{
V_14 -> V_89 = V_90 ;
V_14 -> V_91 [ 0 ] = V_88 ;
V_14 -> V_14 . V_92 |= 1 ;
V_14 -> V_14 . V_93 = 1 ;
V_14 -> V_14 . V_94 = V_14 -> V_91 ;
F_35 ( V_14 ) ;
}
static int F_38 ( T_1 V_18 ,
struct V_13 * V_33 ,
unsigned long V_95 ,
int V_96 ,
int V_97 ,
unsigned char * V_98 ,
long * V_99 )
{
int V_100 = 0 ;
unsigned int V_19 ;
for ( V_19 = V_18 -> V_101 ; ( V_19 + 1 ) % V_30 != V_18 -> V_101 ;
V_19 = ( V_19 + 1 ) % V_30 ) {
if ( ! V_18 -> V_31 [ V_19 ] . V_32 )
break;
}
if ( ! V_18 -> V_31 [ V_19 ] . V_32 ) {
V_18 -> V_31 [ V_19 ] . V_33 = V_33 ;
V_18 -> V_31 [ V_19 ] . V_95 = V_102 ;
V_18 -> V_31 [ V_19 ] . V_103 = V_95 ;
V_18 -> V_31 [ V_19 ] . V_104 = V_96 ;
V_18 -> V_31 [ V_19 ] . V_97 = V_97 ;
V_18 -> V_31 [ V_19 ] . V_32 = 1 ;
V_18 -> V_31 [ V_19 ] . V_99 = F_39 ( V_18 -> V_31 [ V_19 ] . V_99 ) ;
* V_98 = V_19 ;
* V_99 = V_18 -> V_31 [ V_19 ] . V_99 ;
V_18 -> V_101 = ( V_19 + 1 ) % V_30 ;
F_40 ( V_18 ) ;
} else {
V_100 = - V_105 ;
}
return V_100 ;
}
static int F_41 ( T_1 V_18 ,
unsigned char V_98 ,
short V_59 ,
unsigned char V_106 ,
unsigned char V_92 ,
struct V_5 * V_6 ,
struct V_13 * * V_33 )
{
int V_100 = - V_107 ;
unsigned long V_108 ;
if ( V_98 >= V_30 )
return - V_76 ;
F_42 ( & ( V_18 -> V_109 ) , V_108 ) ;
if ( V_18 -> V_31 [ V_98 ] . V_32 ) {
struct V_13 * V_14 = V_18 -> V_31 [ V_98 ] . V_33 ;
if ( ( V_14 -> V_6 . V_59 == V_59 ) && ( V_14 -> V_14 . V_106 == V_106 )
&& ( V_14 -> V_14 . V_92 == V_92 )
&& ( F_32 ( V_6 , & ( V_14 -> V_6 ) ) ) ) {
* V_33 = V_14 ;
V_18 -> V_31 [ V_98 ] . V_32 = 0 ;
V_100 = 0 ;
}
}
F_43 ( & ( V_18 -> V_109 ) , V_108 ) ;
return V_100 ;
}
static int F_44 ( T_1 V_18 ,
long V_110 )
{
int V_100 = - V_107 ;
unsigned long V_108 ;
unsigned char V_98 ;
unsigned long V_99 ;
F_45 ( V_110 , V_98 , V_99 ) ;
F_42 ( & ( V_18 -> V_109 ) , V_108 ) ;
if ( ( V_18 -> V_31 [ V_98 ] . V_32 )
&& ( V_18 -> V_31 [ V_98 ] . V_99 == V_99 ) ) {
struct V_31 * V_111 = & ( V_18 -> V_31 [ V_98 ] ) ;
V_111 -> V_95 = V_111 -> V_103 ;
V_100 = 0 ;
}
F_43 ( & ( V_18 -> V_109 ) , V_108 ) ;
return V_100 ;
}
static int F_46 ( T_1 V_18 ,
long V_110 ,
unsigned int V_88 )
{
int V_100 = - V_107 ;
unsigned long V_108 ;
unsigned char V_98 ;
unsigned long V_99 ;
struct V_13 * V_14 = NULL ;
F_45 ( V_110 , V_98 , V_99 ) ;
F_42 ( & ( V_18 -> V_109 ) , V_108 ) ;
if ( ( V_18 -> V_31 [ V_98 ] . V_32 )
&& ( V_18 -> V_31 [ V_98 ] . V_99 == V_99 ) ) {
struct V_31 * V_111 = & ( V_18 -> V_31 [ V_98 ] ) ;
V_111 -> V_32 = 0 ;
V_14 = V_111 -> V_33 ;
V_100 = 0 ;
}
F_43 ( & ( V_18 -> V_109 ) , V_108 ) ;
if ( V_14 )
F_37 ( V_14 , V_88 ) ;
return V_100 ;
}
int F_47 ( unsigned int V_112 ,
struct V_113 * V_85 ,
void * V_87 ,
T_2 * V_79 )
{
unsigned long V_108 ;
T_2 V_114 ;
int V_100 = 0 ;
T_1 V_18 ;
if ( V_85 == NULL )
return - V_76 ;
if ( ! V_115 ) {
V_100 = F_48 () ;
if ( V_100 )
return V_100 ;
if ( ! V_115 )
return - V_107 ;
}
V_114 = F_23 ( sizeof( * V_114 ) , V_47 ) ;
if ( ! V_114 )
return - V_52 ;
F_13 ( & V_45 ) ;
F_49 (intf, &ipmi_interfaces, link) {
if ( V_18 -> V_46 == V_112 )
goto V_116;
}
V_100 = - V_76 ;
goto V_117;
V_116:
F_24 ( & V_18 -> V_37 ) ;
F_50 ( & V_114 -> V_37 ) ;
V_114 -> V_85 = V_85 ;
V_114 -> V_87 = V_87 ;
V_114 -> V_18 = V_18 ;
V_114 -> V_118 = false ;
if ( ! F_30 ( V_18 -> V_119 -> V_56 ) ) {
V_100 = - V_107 ;
goto V_120;
}
if ( V_18 -> V_119 -> V_121 ) {
V_100 = V_18 -> V_119 -> V_121 ( V_18 -> V_122 ) ;
if ( V_100 ) {
F_31 ( V_18 -> V_119 -> V_56 ) ;
goto V_120;
}
}
F_16 ( & V_45 ) ;
V_114 -> V_123 = true ;
F_42 ( & V_18 -> V_109 , V_108 ) ;
F_51 ( & V_114 -> V_16 , & V_18 -> V_124 ) ;
F_43 ( & V_18 -> V_109 , V_108 ) ;
if ( V_85 -> V_125 ) {
if ( F_52 ( & V_18 -> V_126 ) == 1 )
F_40 ( V_18 ) ;
}
* V_79 = V_114 ;
return 0 ;
V_120:
F_27 ( & V_18 -> V_37 , F_18 ) ;
V_117:
F_16 ( & V_45 ) ;
F_17 ( V_114 ) ;
return V_100 ;
}
int F_53 ( int V_112 , struct V_127 * V_94 )
{
int V_100 = 0 ;
T_1 V_18 ;
const struct V_128 * V_119 ;
F_13 ( & V_45 ) ;
F_49 (intf, &ipmi_interfaces, link) {
if ( V_18 -> V_46 == V_112 )
goto V_116;
}
V_100 = - V_76 ;
F_16 ( & V_45 ) ;
return V_100 ;
V_116:
V_119 = V_18 -> V_119 ;
V_100 = - V_129 ;
if ( V_119 -> V_130 )
V_100 = V_119 -> V_130 ( V_18 -> V_122 , V_94 ) ;
F_16 ( & V_45 ) ;
return V_100 ;
}
static void F_54 ( struct V_34 * V_35 )
{
T_2 V_79 = F_19 ( V_35 , struct V_131 , V_37 ) ;
F_17 ( V_79 ) ;
}
int F_55 ( T_2 V_79 )
{
T_1 V_18 = V_79 -> V_18 ;
int V_19 ;
unsigned long V_108 ;
struct V_20 * V_21 ;
struct V_20 * V_132 = NULL ;
V_79 -> V_123 = false ;
if ( V_79 -> V_85 -> V_125 )
F_56 ( & V_18 -> V_126 ) ;
if ( V_79 -> V_118 )
F_56 ( & V_18 -> V_126 ) ;
F_42 ( & V_18 -> V_109 , V_108 ) ;
F_57 ( & V_79 -> V_16 ) ;
for ( V_19 = 0 ; V_19 < V_30 ; V_19 ++ ) {
if ( V_18 -> V_31 [ V_19 ] . V_32
&& ( V_18 -> V_31 [ V_19 ] . V_33 -> V_79 == V_79 ) ) {
V_18 -> V_31 [ V_19 ] . V_32 = 0 ;
F_8 ( V_18 -> V_31 [ V_19 ] . V_33 ) ;
}
}
F_43 ( & V_18 -> V_109 , V_108 ) ;
F_13 ( & V_18 -> V_27 ) ;
F_49 (rcvr, &intf->cmd_rcvrs, link) {
if ( V_21 -> V_79 == V_79 ) {
F_57 ( & V_21 -> V_16 ) ;
V_21 -> V_133 = V_132 ;
V_132 = V_21 ;
}
}
F_16 ( & V_18 -> V_27 ) ;
V_29 () ;
while ( V_132 ) {
V_21 = V_132 ;
V_132 = V_21 -> V_133 ;
F_17 ( V_21 ) ;
}
F_13 ( & V_45 ) ;
if ( V_18 -> V_119 ) {
F_31 ( V_18 -> V_119 -> V_56 ) ;
if ( V_18 -> V_119 -> V_134 )
V_18 -> V_119 -> V_134 ( V_18 -> V_122 ) ;
}
F_16 ( & V_45 ) ;
F_27 ( & V_18 -> V_37 , F_18 ) ;
F_27 ( & V_79 -> V_37 , F_54 ) ;
return 0 ;
}
void F_58 ( T_2 V_79 ,
unsigned char * V_135 ,
unsigned char * V_136 )
{
* V_135 = V_79 -> V_18 -> V_137 ;
* V_136 = V_79 -> V_18 -> V_138 ;
}
int F_59 ( T_2 V_79 ,
unsigned int V_59 ,
unsigned char V_139 )
{
if ( V_59 >= V_78 )
return - V_76 ;
V_79 -> V_18 -> V_140 [ V_59 ] . V_139 = V_139 ;
return 0 ;
}
int F_60 ( T_2 V_79 ,
unsigned int V_59 ,
unsigned char * V_139 )
{
if ( V_59 >= V_78 )
return - V_76 ;
* V_139 = V_79 -> V_18 -> V_140 [ V_59 ] . V_139 ;
return 0 ;
}
int F_61 ( T_2 V_79 ,
unsigned int V_59 ,
unsigned char V_141 )
{
if ( V_59 >= V_78 )
return - V_76 ;
V_79 -> V_18 -> V_140 [ V_59 ] . V_64 = V_141 & 0x3 ;
return 0 ;
}
int F_62 ( T_2 V_79 ,
unsigned int V_59 ,
unsigned char * V_139 )
{
if ( V_59 >= V_78 )
return - V_76 ;
* V_139 = V_79 -> V_18 -> V_140 [ V_59 ] . V_64 ;
return 0 ;
}
int F_63 ( T_2 V_79 )
{
int V_142 ;
unsigned long V_108 ;
F_42 ( & V_79 -> V_18 -> V_143 , V_108 ) ;
V_142 = V_79 -> V_18 -> V_144 ;
F_43 ( & V_79 -> V_18 -> V_143 , V_108 ) ;
return V_142 ;
}
static void F_64 ( T_1 V_18 )
{
if ( V_18 -> V_119 -> V_145 )
V_18 -> V_119 -> V_145 (
V_18 -> V_122 , V_18 -> V_146 ) ;
}
int F_65 ( T_2 V_79 , int V_142 )
{
int V_100 = 0 ;
unsigned long V_108 ;
T_1 V_18 = V_79 -> V_18 ;
F_42 ( & V_18 -> V_143 , V_108 ) ;
if ( V_18 -> V_144 != V_142 ) {
switch ( V_142 ) {
case V_147 :
V_18 -> V_146
= ( V_18 -> V_148 > 0 ) ;
break;
case V_149 :
V_18 -> V_146 = false ;
break;
case V_150 :
V_18 -> V_146 = true ;
break;
default:
V_100 = - V_76 ;
goto V_151;
}
V_18 -> V_144 = V_142 ;
F_64 ( V_18 ) ;
}
V_151:
F_43 ( & V_18 -> V_143 , V_108 ) ;
return V_100 ;
}
int F_66 ( T_2 V_79 , bool V_152 )
{
unsigned long V_108 ;
T_1 V_18 = V_79 -> V_18 ;
struct V_13 * V_14 , * V_15 ;
struct V_11 V_153 ;
F_14 ( & V_153 ) ;
F_42 ( & V_18 -> V_154 , V_108 ) ;
if ( V_79 -> V_118 == V_152 )
goto V_155;
V_79 -> V_118 = V_152 ;
if ( V_152 ) {
if ( F_52 ( & V_18 -> V_126 ) == 1 )
F_40 ( V_18 ) ;
} else {
F_56 ( & V_18 -> V_126 ) ;
}
if ( V_18 -> V_156 )
goto V_155;
while ( V_79 -> V_118 && ! F_67 ( & V_18 -> V_26 ) ) {
F_6 (msg, msg2, &intf->waiting_events, link)
F_68 ( & V_14 -> V_16 , & V_153 ) ;
V_18 -> V_157 = 0 ;
if ( V_18 -> V_158 ) {
F_69 (KERN_WARNING PFX L_1
L_2 ) ;
V_18 -> V_158 = 0 ;
}
V_18 -> V_156 = 1 ;
F_43 ( & V_18 -> V_154 , V_108 ) ;
F_6 (msg, msg2, &msgs, link) {
V_14 -> V_79 = V_79 ;
F_24 ( & V_79 -> V_37 ) ;
F_35 ( V_14 ) ;
}
F_42 ( & V_18 -> V_154 , V_108 ) ;
V_18 -> V_156 = 0 ;
}
V_155:
F_43 ( & V_18 -> V_154 , V_108 ) ;
return 0 ;
}
static struct V_20 * F_70 ( T_1 V_18 ,
unsigned char V_92 ,
unsigned char V_106 ,
unsigned char V_159 )
{
struct V_20 * V_21 ;
F_49 (rcvr, &intf->cmd_rcvrs, link) {
if ( ( V_21 -> V_92 == V_92 ) && ( V_21 -> V_106 == V_106 )
&& ( V_21 -> V_160 & ( 1 << V_159 ) ) )
return V_21 ;
}
return NULL ;
}
static int F_71 ( T_1 V_18 ,
unsigned char V_92 ,
unsigned char V_106 ,
unsigned int V_160 )
{
struct V_20 * V_21 ;
F_49 (rcvr, &intf->cmd_rcvrs, link) {
if ( ( V_21 -> V_92 == V_92 ) && ( V_21 -> V_106 == V_106 )
&& ( V_21 -> V_160 & V_160 ) )
return 0 ;
}
return 1 ;
}
int F_72 ( T_2 V_79 ,
unsigned char V_92 ,
unsigned char V_106 ,
unsigned int V_160 )
{
T_1 V_18 = V_79 -> V_18 ;
struct V_20 * V_21 ;
int V_100 = 0 ;
V_21 = F_23 ( sizeof( * V_21 ) , V_47 ) ;
if ( ! V_21 )
return - V_52 ;
V_21 -> V_106 = V_106 ;
V_21 -> V_92 = V_92 ;
V_21 -> V_160 = V_160 ;
V_21 -> V_79 = V_79 ;
F_13 ( & V_18 -> V_27 ) ;
if ( ! F_71 ( V_18 , V_92 , V_106 , V_160 ) ) {
V_100 = - V_161 ;
goto V_151;
}
if ( F_52 ( & V_18 -> V_126 ) == 1 )
F_40 ( V_18 ) ;
F_51 ( & V_21 -> V_16 , & V_18 -> V_28 ) ;
V_151:
F_16 ( & V_18 -> V_27 ) ;
if ( V_100 )
F_17 ( V_21 ) ;
return V_100 ;
}
int F_73 ( T_2 V_79 ,
unsigned char V_92 ,
unsigned char V_106 ,
unsigned int V_160 )
{
T_1 V_18 = V_79 -> V_18 ;
struct V_20 * V_21 ;
struct V_20 * V_132 = NULL ;
int V_19 , V_100 = - V_162 ;
F_13 ( & V_18 -> V_27 ) ;
for ( V_19 = 0 ; V_19 < V_163 ; V_19 ++ ) {
if ( ( ( 1 << V_19 ) & V_160 ) == 0 )
continue;
V_21 = F_70 ( V_18 , V_92 , V_106 , V_19 ) ;
if ( V_21 == NULL )
continue;
if ( V_21 -> V_79 == V_79 ) {
V_100 = 0 ;
V_21 -> V_160 &= ~ V_160 ;
if ( V_21 -> V_160 == 0 ) {
F_57 ( & V_21 -> V_16 ) ;
V_21 -> V_133 = V_132 ;
V_132 = V_21 ;
}
}
}
F_16 ( & V_18 -> V_27 ) ;
V_29 () ;
while ( V_132 ) {
F_56 ( & V_18 -> V_126 ) ;
V_21 = V_132 ;
V_132 = V_21 -> V_133 ;
F_17 ( V_21 ) ;
}
return V_100 ;
}
static unsigned char
F_74 ( unsigned char * V_94 , int V_164 )
{
unsigned char V_165 = 0 ;
for (; V_164 > 0 ; V_164 -- , V_94 ++ )
V_165 += * V_94 ;
return - V_165 ;
}
static inline void F_75 ( struct V_17 * V_166 ,
struct V_167 * V_14 ,
struct V_65 * V_168 ,
long V_110 ,
unsigned char V_169 ,
int V_97 ,
unsigned char V_170 ,
unsigned char V_171 )
{
int V_19 = V_97 ;
V_166 -> V_94 [ 0 ] = ( V_172 << 2 ) ;
V_166 -> V_94 [ 1 ] = V_173 ;
V_166 -> V_94 [ 2 ] = V_168 -> V_59 ;
if ( V_97 )
V_166 -> V_94 [ 3 ] = 0 ;
V_166 -> V_94 [ V_19 + 3 ] = V_168 -> V_68 ;
V_166 -> V_94 [ V_19 + 4 ] = ( V_14 -> V_92 << 2 ) | ( V_168 -> V_64 & 0x3 ) ;
V_166 -> V_94 [ V_19 + 5 ] = F_74 ( & ( V_166 -> V_94 [ V_19 + 3 ] ) , 2 ) ;
V_166 -> V_94 [ V_19 + 6 ] = V_170 ;
V_166 -> V_94 [ V_19 + 7 ] = ( V_169 << 2 ) | V_171 ;
V_166 -> V_94 [ V_19 + 8 ] = V_14 -> V_106 ;
if ( V_14 -> V_93 > 0 )
memcpy ( & ( V_166 -> V_94 [ V_19 + 9 ] ) , V_14 -> V_94 ,
V_14 -> V_93 ) ;
V_166 -> V_174 = V_14 -> V_93 + 9 ;
V_166 -> V_94 [ V_19 + V_166 -> V_174 ]
= F_74 ( & ( V_166 -> V_94 [ V_19 + 6 ] ) ,
V_166 -> V_174 - 6 ) ;
V_166 -> V_174 += 1 + V_19 ;
V_166 -> V_110 = V_110 ;
}
static inline void F_76 ( struct V_17 * V_166 ,
struct V_167 * V_14 ,
struct V_69 * V_175 ,
long V_110 ,
unsigned char V_169 ,
unsigned char V_171 )
{
V_166 -> V_94 [ 0 ] = ( V_172 << 2 ) ;
V_166 -> V_94 [ 1 ] = V_173 ;
V_166 -> V_94 [ 2 ] = V_175 -> V_59 ;
V_166 -> V_94 [ 3 ] = V_175 -> V_74 ;
V_166 -> V_94 [ 4 ] = V_175 -> V_72 ;
V_166 -> V_94 [ 5 ] = ( V_14 -> V_92 << 2 ) | ( V_175 -> V_64 & 0x3 ) ;
V_166 -> V_94 [ 6 ] = F_74 ( & ( V_166 -> V_94 [ 4 ] ) , 2 ) ;
V_166 -> V_94 [ 7 ] = V_175 -> V_73 ;
V_166 -> V_94 [ 8 ] = ( V_169 << 2 ) | V_171 ;
V_166 -> V_94 [ 9 ] = V_14 -> V_106 ;
if ( V_14 -> V_93 > 0 )
memcpy ( & ( V_166 -> V_94 [ 10 ] ) , V_14 -> V_94 ,
V_14 -> V_93 ) ;
V_166 -> V_174 = V_14 -> V_93 + 10 ;
V_166 -> V_94 [ V_166 -> V_174 ]
= F_74 ( & ( V_166 -> V_94 [ 7 ] ) ,
V_166 -> V_174 - 7 ) ;
V_166 -> V_174 += 1 ;
V_166 -> V_110 = V_110 ;
}
static struct V_17 * F_77 ( T_1 V_18 ,
struct V_17 * V_166 ,
int V_176 )
{
if ( V_18 -> V_177 ) {
if ( V_176 > 0 )
F_25 ( & V_166 -> V_16 , & V_18 -> V_178 ) ;
else
F_25 ( & V_166 -> V_16 , & V_18 -> V_179 ) ;
V_166 = NULL ;
} else {
V_18 -> V_177 = V_166 ;
}
return V_166 ;
}
static void F_78 ( T_1 V_18 , const struct V_128 * V_119 ,
struct V_17 * V_166 , int V_176 )
{
int V_180 = V_18 -> V_180 ;
if ( V_180 ) {
V_166 = F_77 ( V_18 , V_166 , V_176 ) ;
} else {
unsigned long V_108 ;
F_42 ( & V_18 -> V_181 , V_108 ) ;
V_166 = F_77 ( V_18 , V_166 , V_176 ) ;
F_43 ( & V_18 -> V_181 , V_108 ) ;
}
if ( V_166 )
V_119 -> V_182 ( V_18 -> V_122 , V_166 ) ;
}
static int F_79 ( T_2 V_79 ,
T_1 V_18 ,
struct V_5 * V_6 ,
long V_110 ,
struct V_167 * V_14 ,
void * V_80 ,
void * V_183 ,
struct V_13 * V_184 ,
int V_176 ,
unsigned char V_170 ,
unsigned char V_171 ,
int V_96 ,
unsigned int V_185 )
{
int V_100 = 0 ;
struct V_17 * V_166 ;
struct V_13 * V_33 ;
unsigned long V_108 ;
if ( V_184 )
V_33 = V_184 ;
else {
V_33 = F_80 () ;
if ( V_33 == NULL )
return - V_52 ;
}
V_33 -> V_80 = V_80 ;
if ( V_183 )
V_166 = (struct V_17 * ) V_183 ;
else {
V_166 = F_81 () ;
if ( V_166 == NULL ) {
F_8 ( V_33 ) ;
return - V_52 ;
}
}
F_82 () ;
if ( V_18 -> V_186 ) {
V_100 = - V_107 ;
goto V_48;
}
V_33 -> V_79 = V_79 ;
if ( V_79 )
F_24 ( & V_79 -> V_37 ) ;
V_33 -> V_110 = V_110 ;
V_33 -> V_14 = * V_14 ;
if ( V_6 -> V_7 == V_60 ) {
struct V_61 * V_187 ;
if ( V_14 -> V_92 & 1 ) {
V_100 = - V_76 ;
goto V_48;
}
V_187 = (struct V_61 * ) V_6 ;
if ( V_187 -> V_64 > 3 ) {
F_36 ( V_18 , V_188 ) ;
V_100 = - V_76 ;
goto V_48;
}
memcpy ( & V_33 -> V_6 , V_187 , sizeof( * V_187 ) ) ;
if ( ( V_14 -> V_92 == V_172 )
&& ( ( V_14 -> V_106 == V_173 )
|| ( V_14 -> V_106 == V_189 )
|| ( V_14 -> V_106 == V_190 ) ) ) {
F_36 ( V_18 , V_188 ) ;
V_100 = - V_76 ;
goto V_48;
}
if ( ( ( V_14 -> V_92 == V_172 )
&& ( ( V_14 -> V_106 == V_191 )
|| ( V_14 -> V_106 == V_192 ) ) )
|| ( V_14 -> V_92 == V_193 ) ) {
F_42 ( & V_18 -> V_143 , V_108 ) ;
V_18 -> V_148
= V_194 ;
if ( ! V_18 -> V_144
&& ! V_18 -> V_146 ) {
V_18 -> V_146 = true ;
F_64 ( V_18 ) ;
}
F_43 ( & V_18 -> V_143 ,
V_108 ) ;
}
if ( ( V_14 -> V_93 + 2 ) > V_195 ) {
F_36 ( V_18 , V_188 ) ;
V_100 = - V_196 ;
goto V_48;
}
V_166 -> V_94 [ 0 ] = ( V_14 -> V_92 << 2 ) | ( V_187 -> V_64 & 0x3 ) ;
V_166 -> V_94 [ 1 ] = V_14 -> V_106 ;
V_166 -> V_110 = V_110 ;
V_166 -> V_197 = V_33 ;
if ( V_14 -> V_93 > 0 )
memcpy ( & ( V_166 -> V_94 [ 2 ] ) , V_14 -> V_94 , V_14 -> V_93 ) ;
V_166 -> V_174 = V_14 -> V_93 + 2 ;
F_36 ( V_18 , V_198 ) ;
} else if ( F_3 ( V_6 ) || F_4 ( V_6 ) ) {
struct V_65 * V_168 ;
unsigned char V_169 ;
long V_99 ;
int V_97 = 0 ;
if ( V_6 -> V_59 >= V_78 ) {
F_36 ( V_18 , V_188 ) ;
V_100 = - V_76 ;
goto V_48;
}
if ( V_18 -> V_140 [ V_6 -> V_59 ] . V_199
!= V_200 ) {
F_36 ( V_18 , V_188 ) ;
V_100 = - V_76 ;
goto V_48;
}
if ( V_96 < 0 ) {
if ( V_6 -> V_7 == V_10 )
V_96 = 0 ;
else
V_96 = 4 ;
}
if ( V_6 -> V_7 == V_10 ) {
V_6 -> V_7 = V_9 ;
V_97 = 1 ;
}
if ( V_185 == 0 )
V_185 = 1000 ;
if ( ( V_14 -> V_93 + 10 + V_97 ) > V_195 ) {
F_36 ( V_18 , V_188 ) ;
V_100 = - V_196 ;
goto V_48;
}
V_168 = (struct V_65 * ) V_6 ;
if ( V_168 -> V_64 > 3 ) {
F_36 ( V_18 , V_188 ) ;
V_100 = - V_76 ;
goto V_48;
}
memcpy ( & V_33 -> V_6 , V_168 , sizeof( * V_168 ) ) ;
if ( V_33 -> V_14 . V_92 & 0x1 ) {
F_36 ( V_18 , V_201 ) ;
F_75 ( V_166 , V_14 , V_168 , V_110 ,
V_110 , V_97 ,
V_170 , V_171 ) ;
V_166 -> V_197 = V_33 ;
} else {
F_42 ( & ( V_18 -> V_109 ) , V_108 ) ;
V_100 = F_38 ( V_18 ,
V_33 ,
V_185 ,
V_96 ,
V_97 ,
& V_169 ,
& V_99 ) ;
if ( V_100 ) {
F_43 ( & ( V_18 -> V_109 ) ,
V_108 ) ;
goto V_48;
}
F_36 ( V_18 , V_202 ) ;
F_75 ( V_166 , V_14 , V_168 ,
F_83 ( V_169 , V_99 ) ,
V_169 , V_97 ,
V_170 , V_171 ) ;
memcpy ( V_33 -> V_91 , V_166 -> V_94 ,
V_166 -> V_174 ) ;
V_33 -> V_14 . V_94 = V_33 -> V_91 ;
V_33 -> V_14 . V_93 = V_166 -> V_174 ;
F_43 ( & ( V_18 -> V_109 ) , V_108 ) ;
}
} else if ( F_2 ( V_6 ) ) {
struct V_69 * V_175 ;
unsigned char V_169 ;
long V_99 ;
if ( V_6 -> V_59 >= V_78 ) {
F_36 ( V_18 , V_188 ) ;
V_100 = - V_76 ;
goto V_48;
}
if ( ( V_18 -> V_140 [ V_6 -> V_59 ] . V_199
!= V_203 )
&& ( V_18 -> V_140 [ V_6 -> V_59 ] . V_199
!= V_204 ) ) {
F_36 ( V_18 , V_188 ) ;
V_100 = - V_76 ;
goto V_48;
}
V_96 = 4 ;
if ( V_185 == 0 )
V_185 = 1000 ;
if ( ( V_14 -> V_93 + 12 ) > V_195 ) {
F_36 ( V_18 , V_188 ) ;
V_100 = - V_196 ;
goto V_48;
}
V_175 = (struct V_69 * ) V_6 ;
if ( V_175 -> V_64 > 3 ) {
F_36 ( V_18 , V_188 ) ;
V_100 = - V_76 ;
goto V_48;
}
memcpy ( & V_33 -> V_6 , V_175 , sizeof( * V_175 ) ) ;
if ( V_33 -> V_14 . V_92 & 0x1 ) {
F_36 ( V_18 , V_205 ) ;
F_76 ( V_166 , V_14 , V_175 , V_110 ,
V_110 , V_171 ) ;
V_166 -> V_197 = V_33 ;
} else {
F_42 ( & ( V_18 -> V_109 ) , V_108 ) ;
V_100 = F_38 ( V_18 ,
V_33 ,
V_185 ,
V_96 ,
0 ,
& V_169 ,
& V_99 ) ;
if ( V_100 ) {
F_43 ( & ( V_18 -> V_109 ) ,
V_108 ) ;
goto V_48;
}
F_36 ( V_18 , V_206 ) ;
F_76 ( V_166 , V_14 , V_175 ,
F_83 ( V_169 , V_99 ) ,
V_169 , V_171 ) ;
memcpy ( V_33 -> V_91 , V_166 -> V_94 ,
V_166 -> V_174 ) ;
V_33 -> V_14 . V_94 = V_33 -> V_91 ;
V_33 -> V_14 . V_93 = V_166 -> V_174 ;
F_43 ( & ( V_18 -> V_109 ) , V_108 ) ;
}
} else {
F_36 ( V_18 , V_188 ) ;
V_100 = - V_76 ;
goto V_48;
}
#ifdef F_84
{
int V_207 ;
for ( V_207 = 0 ; V_207 < V_166 -> V_174 ; V_207 ++ )
F_69 ( L_3 , V_166 -> V_94 [ V_207 ] ) ;
F_69 ( L_4 ) ;
}
#endif
F_78 ( V_18 , V_18 -> V_119 , V_166 , V_176 ) ;
F_85 () ;
return 0 ;
V_48:
F_85 () ;
F_10 ( V_166 ) ;
F_8 ( V_33 ) ;
return V_100 ;
}
static int F_86 ( T_1 V_18 ,
struct V_5 * V_6 ,
unsigned char * V_208 ,
unsigned char * V_64 )
{
if ( V_6 -> V_59 >= V_78 )
return - V_76 ;
* V_64 = V_18 -> V_140 [ V_6 -> V_59 ] . V_64 ;
* V_208 = V_18 -> V_140 [ V_6 -> V_59 ] . V_139 ;
return 0 ;
}
int F_87 ( T_2 V_79 ,
struct V_5 * V_6 ,
long V_110 ,
struct V_167 * V_14 ,
void * V_80 ,
int V_176 ,
int V_96 ,
unsigned int V_185 )
{
unsigned char V_208 = 0 , V_64 = 0 ;
int V_100 ;
if ( ! V_79 )
return - V_76 ;
V_100 = F_86 ( V_79 -> V_18 , V_6 , & V_208 , & V_64 ) ;
if ( V_100 )
return V_100 ;
return F_79 ( V_79 ,
V_79 -> V_18 ,
V_6 ,
V_110 ,
V_14 ,
V_80 ,
NULL , NULL ,
V_176 ,
V_208 ,
V_64 ,
V_96 ,
V_185 ) ;
}
int F_88 ( T_2 V_79 ,
struct V_5 * V_6 ,
long V_110 ,
struct V_167 * V_14 ,
void * V_80 ,
void * V_183 ,
struct V_13 * V_184 ,
int V_176 )
{
unsigned char V_208 = 0 , V_64 = 0 ;
int V_100 ;
if ( ! V_79 )
return - V_76 ;
V_100 = F_86 ( V_79 -> V_18 , V_6 , & V_208 , & V_64 ) ;
if ( V_100 )
return V_100 ;
return F_79 ( V_79 ,
V_79 -> V_18 ,
V_6 ,
V_110 ,
V_14 ,
V_80 ,
V_183 ,
V_184 ,
V_176 ,
V_208 ,
V_64 ,
- 1 , 0 ) ;
}
static int F_89 ( struct V_209 * V_207 , void * V_210 )
{
T_1 V_18 = V_207 -> V_211 ;
int V_19 ;
F_90 ( V_207 , L_5 , V_18 -> V_140 [ 0 ] . V_139 ) ;
for ( V_19 = 1 ; V_19 < V_78 ; V_19 ++ )
F_90 ( V_207 , L_6 , V_18 -> V_140 [ V_19 ] . V_139 ) ;
F_91 ( V_207 , '\n' ) ;
return 0 ;
}
static int F_92 ( struct V_212 * V_212 , struct V_213 * V_213 )
{
return F_93 ( V_213 , F_89 , F_94 ( V_212 ) ) ;
}
static int F_95 ( struct V_209 * V_207 , void * V_210 )
{
T_1 V_18 = V_207 -> V_211 ;
F_90 ( V_207 , L_7 ,
V_137 ( & V_18 -> V_214 -> V_215 ) ,
V_138 ( & V_18 -> V_214 -> V_215 ) ) ;
return 0 ;
}
static int F_96 ( struct V_212 * V_212 , struct V_213 * V_213 )
{
return F_93 ( V_213 , F_95 , F_94 ( V_212 ) ) ;
}
static int F_97 ( struct V_209 * V_207 , void * V_210 )
{
T_1 V_18 = V_207 -> V_211 ;
F_90 ( V_207 , L_8 ,
F_98 ( V_18 , V_188 ) ) ;
F_90 ( V_207 , L_9 ,
F_98 ( V_18 , V_198 ) ) ;
F_90 ( V_207 , L_10 ,
F_98 ( V_18 , V_82 ) ) ;
F_90 ( V_207 , L_11 ,
F_98 ( V_18 , V_83 ) ) ;
F_90 ( V_207 , L_12 ,
F_98 ( V_18 , V_202 ) ) ;
F_90 ( V_207 , L_13 ,
F_98 ( V_18 , V_216 ) ) ;
F_90 ( V_207 , L_14 ,
F_98 ( V_18 , V_217 ) ) ;
F_90 ( V_207 , L_15 ,
F_98 ( V_18 , V_218 ) ) ;
F_90 ( V_207 , L_16 ,
F_98 ( V_18 , V_219 ) ) ;
F_90 ( V_207 , L_17 ,
F_98 ( V_18 , V_201 ) ) ;
F_90 ( V_207 , L_18 ,
F_98 ( V_18 , V_220 ) ) ;
F_90 ( V_207 , L_19 ,
F_98 ( V_18 , V_221 ) ) ;
F_90 ( V_207 , L_20 ,
F_98 ( V_18 , V_222 ) ) ;
F_90 ( V_207 , L_21 ,
F_98 ( V_18 , V_206 ) ) ;
F_90 ( V_207 , L_22 ,
F_98 ( V_18 , V_223 ) ) ;
F_90 ( V_207 , L_23 ,
F_98 ( V_18 , V_224 ) ) ;
F_90 ( V_207 , L_24 ,
F_98 ( V_18 , V_225 ) ) ;
F_90 ( V_207 , L_25 ,
F_98 ( V_18 , V_205 ) ) ;
F_90 ( V_207 , L_26 ,
F_98 ( V_18 , V_226 ) ) ;
F_90 ( V_207 , L_27 ,
F_98 ( V_18 , V_227 ) ) ;
F_90 ( V_207 , L_28 ,
F_98 ( V_18 , V_228 ) ) ;
F_90 ( V_207 , L_29 ,
F_98 ( V_18 , V_229 ) ) ;
F_90 ( V_207 , L_30 ,
F_98 ( V_18 , V_230 ) ) ;
F_90 ( V_207 , L_31 ,
F_98 ( V_18 , V_231 ) ) ;
F_90 ( V_207 , L_32 ,
F_98 ( V_18 , V_232 ) ) ;
F_90 ( V_207 , L_33 ,
F_98 ( V_18 , V_233 ) ) ;
F_90 ( V_207 , L_34 ,
F_98 ( V_18 , V_234 ) ) ;
F_90 ( V_207 , L_35 ,
F_98 ( V_18 , V_235 ) ) ;
return 0 ;
}
static int F_99 ( struct V_212 * V_212 , struct V_213 * V_213 )
{
return F_93 ( V_213 , F_97 , F_94 ( V_212 ) ) ;
}
int F_100 ( T_1 V_236 , char * V_237 ,
const struct V_238 * V_239 ,
void * V_94 )
{
int V_100 = 0 ;
#ifdef F_101
struct V_240 * V_213 ;
struct V_241 * V_242 ;
V_242 = F_23 ( sizeof( * V_242 ) , V_47 ) ;
if ( ! V_242 )
return - V_52 ;
V_242 -> V_237 = F_102 ( V_237 , V_47 ) ;
if ( ! V_242 -> V_237 ) {
F_17 ( V_242 ) ;
return - V_52 ;
}
V_213 = F_103 ( V_237 , 0 , V_236 -> V_243 , V_239 , V_94 ) ;
if ( ! V_213 ) {
F_17 ( V_242 -> V_237 ) ;
F_17 ( V_242 ) ;
V_100 = - V_52 ;
} else {
F_13 ( & V_236 -> V_244 ) ;
V_242 -> V_133 = V_236 -> V_245 ;
V_236 -> V_245 = V_242 ;
F_16 ( & V_236 -> V_244 ) ;
}
#endif
return V_100 ;
}
static int F_104 ( T_1 V_236 , int V_246 )
{
int V_100 = 0 ;
#ifdef F_101
sprintf ( V_236 -> V_247 , L_36 , V_246 ) ;
V_236 -> V_243 = F_105 ( V_236 -> V_247 , V_248 ) ;
if ( ! V_236 -> V_243 )
V_100 = - V_52 ;
if ( V_100 == 0 )
V_100 = F_100 ( V_236 , L_37 ,
& V_249 ,
V_236 ) ;
if ( V_100 == 0 )
V_100 = F_100 ( V_236 , L_38 ,
& V_250 ,
V_236 ) ;
if ( V_100 == 0 )
V_100 = F_100 ( V_236 , L_39 ,
& V_251 ,
V_236 ) ;
#endif
return V_100 ;
}
static void F_106 ( T_1 V_236 )
{
#ifdef F_101
struct V_241 * V_242 ;
F_13 ( & V_236 -> V_244 ) ;
while ( V_236 -> V_245 ) {
V_242 = V_236 -> V_245 ;
V_236 -> V_245 = V_242 -> V_133 ;
F_107 ( V_242 -> V_237 , V_236 -> V_243 ) ;
F_17 ( V_242 -> V_237 ) ;
F_17 ( V_242 ) ;
}
F_16 ( & V_236 -> V_244 ) ;
F_107 ( V_236 -> V_247 , V_248 ) ;
#endif
}
static int F_108 ( struct V_53 * V_54 , void * V_94 )
{
unsigned char * V_215 = V_94 ;
struct V_252 * V_214 = F_109 ( V_54 ) ;
return memcmp ( V_214 -> V_253 , V_215 , 16 ) == 0 ;
}
static struct V_252 * F_110 ( struct V_254 * V_255 ,
unsigned char * V_253 )
{
struct V_53 * V_54 ;
V_54 = F_111 ( V_255 , NULL , V_253 , F_108 ) ;
if ( V_54 )
return F_109 ( V_54 ) ;
else
return NULL ;
}
static int F_112 ( struct V_53 * V_54 , void * V_94 )
{
struct V_256 * V_215 = V_94 ;
struct V_252 * V_214 = F_109 ( V_54 ) ;
return ( V_214 -> V_215 . V_257 == V_215 -> V_257
&& V_214 -> V_215 . V_258 == V_215 -> V_258 ) ;
}
static struct V_252 * F_113 (
struct V_254 * V_255 ,
unsigned int V_257 , unsigned char V_258 )
{
struct V_256 V_215 = {
. V_257 = V_257 ,
. V_258 = V_258 ,
} ;
struct V_53 * V_54 ;
V_54 = F_111 ( V_255 , NULL , & V_215 , F_112 ) ;
if ( V_54 )
return F_109 ( V_54 ) ;
else
return NULL ;
}
static T_3 F_114 ( struct V_53 * V_54 ,
struct V_259 * V_260 ,
char * V_261 )
{
struct V_252 * V_214 = F_109 ( V_54 ) ;
return snprintf ( V_261 , 10 , L_40 , V_214 -> V_215 . V_258 ) ;
}
static T_3 F_115 ( struct V_53 * V_54 ,
struct V_259 * V_260 ,
char * V_261 )
{
struct V_252 * V_214 = F_109 ( V_54 ) ;
return snprintf ( V_261 , 10 , L_40 ,
( V_214 -> V_215 . V_262 & 0x80 ) >> 7 ) ;
}
static T_3 F_116 ( struct V_53 * V_54 , struct V_259 * V_260 ,
char * V_261 )
{
struct V_252 * V_214 = F_109 ( V_54 ) ;
return snprintf ( V_261 , 20 , L_40 ,
V_214 -> V_215 . V_262 & 0x0F ) ;
}
static T_3 F_117 ( struct V_53 * V_54 ,
struct V_259 * V_260 ,
char * V_261 )
{
struct V_252 * V_214 = F_109 ( V_54 ) ;
return snprintf ( V_261 , 20 , L_41 , V_214 -> V_215 . V_263 ,
V_214 -> V_215 . V_264 ) ;
}
static T_3 F_118 ( struct V_53 * V_54 ,
struct V_259 * V_260 ,
char * V_261 )
{
struct V_252 * V_214 = F_109 ( V_54 ) ;
return snprintf ( V_261 , 20 , L_7 ,
V_137 ( & V_214 -> V_215 ) ,
V_138 ( & V_214 -> V_215 ) ) ;
}
static T_3 F_119 ( struct V_53 * V_54 ,
struct V_259 * V_260 ,
char * V_261 )
{
struct V_252 * V_214 = F_109 ( V_54 ) ;
return snprintf ( V_261 , 10 , L_42 ,
V_214 -> V_215 . V_265 ) ;
}
static T_3 F_120 ( struct V_53 * V_54 ,
struct V_259 * V_260 ,
char * V_261 )
{
struct V_252 * V_214 = F_109 ( V_54 ) ;
return snprintf ( V_261 , 20 , L_43 , V_214 -> V_215 . V_266 ) ;
}
static T_3 F_121 ( struct V_53 * V_54 ,
struct V_259 * V_260 ,
char * V_261 )
{
struct V_252 * V_214 = F_109 ( V_54 ) ;
return snprintf ( V_261 , 10 , L_44 , V_214 -> V_215 . V_257 ) ;
}
static T_3 F_122 ( struct V_53 * V_54 ,
struct V_259 * V_260 ,
char * V_261 )
{
struct V_252 * V_214 = F_109 ( V_54 ) ;
return snprintf ( V_261 , 21 , L_45 ,
V_214 -> V_215 . V_267 [ 3 ] ,
V_214 -> V_215 . V_267 [ 2 ] ,
V_214 -> V_215 . V_267 [ 1 ] ,
V_214 -> V_215 . V_267 [ 0 ] ) ;
}
static T_3 F_123 ( struct V_53 * V_54 , struct V_259 * V_260 ,
char * V_261 )
{
struct V_252 * V_214 = F_109 ( V_54 ) ;
return snprintf ( V_261 , 100 , L_46 ,
( long long ) V_214 -> V_253 [ 0 ] ,
( long long ) V_214 -> V_253 [ 8 ] ) ;
}
static T_4 F_124 ( struct V_268 * V_269 ,
struct V_270 * V_260 , int V_271 )
{
struct V_53 * V_54 = F_125 ( V_269 ) ;
struct V_252 * V_214 = F_109 ( V_54 ) ;
T_4 V_142 = V_260 -> V_142 ;
if ( V_260 == & V_272 . V_260 )
return V_214 -> V_215 . V_273 ? V_142 : 0 ;
if ( V_260 == & V_274 . V_260 )
return V_214 -> V_275 ? V_142 : 0 ;
return V_142 ;
}
static void
F_126 ( struct V_53 * V_54 )
{
F_17 ( F_109 ( V_54 ) ) ;
}
static void
F_127 ( struct V_34 * V_35 )
{
struct V_252 * V_214 = F_19 ( V_35 , struct V_252 , V_276 ) ;
F_128 ( & V_214 -> V_277 ) ;
}
static void F_129 ( T_1 V_18 )
{
struct V_252 * V_214 = V_18 -> V_214 ;
F_130 ( & V_18 -> V_51 -> V_269 , L_47 ) ;
if ( V_18 -> V_278 ) {
F_130 ( & V_214 -> V_277 . V_54 . V_269 , V_18 -> V_278 ) ;
F_17 ( V_18 -> V_278 ) ;
V_18 -> V_278 = NULL ;
}
F_13 ( & V_279 ) ;
F_27 ( & V_214 -> V_276 , F_127 ) ;
V_18 -> V_214 = NULL ;
F_16 ( & V_279 ) ;
}
static int F_131 ( T_1 V_18 , int V_280 )
{
int V_100 ;
struct V_252 * V_214 = V_18 -> V_214 ;
struct V_252 * V_281 ;
F_13 ( & V_279 ) ;
if ( V_214 -> V_275 )
V_281 = F_110 ( & V_282 . V_283 , V_214 -> V_253 ) ;
else
V_281 = F_113 ( & V_282 . V_283 ,
V_214 -> V_215 . V_257 ,
V_214 -> V_215 . V_258 ) ;
if ( V_281 ) {
F_17 ( V_214 ) ;
V_18 -> V_214 = V_281 ;
V_214 = V_281 ;
F_24 ( & V_214 -> V_276 ) ;
F_16 ( & V_279 ) ;
F_69 ( V_284
L_48
L_49 ,
V_214 -> V_215 . V_266 ,
V_214 -> V_215 . V_257 ,
V_214 -> V_215 . V_258 ) ;
} else {
unsigned char V_285 = V_214 -> V_215 . V_258 ;
int V_286 = 0 ;
snprintf ( V_214 -> V_237 , sizeof( V_214 -> V_237 ) ,
L_50 , V_214 -> V_215 . V_257 ) ;
V_214 -> V_277 . V_237 = V_214 -> V_237 ;
while ( F_113 ( & V_282 . V_283 ,
V_214 -> V_215 . V_257 ,
V_214 -> V_215 . V_258 ) ) {
if ( ! V_286 ) {
F_69 (KERN_WARNING PFX
L_51
L_52
L_53
L_54
L_55
L_56 ,
bmc->id.product_id, bmc->id.device_id) ;
V_286 = 1 ;
}
V_214 -> V_215 . V_258 ++ ;
if ( V_214 -> V_215 . V_258 == V_285 ) {
F_69 (KERN_ERR PFX
L_57 ) ;
break;
}
}
V_214 -> V_277 . V_54 . V_283 = & V_282 . V_283 ;
V_214 -> V_277 . V_215 = V_214 -> V_215 . V_258 ;
V_214 -> V_277 . V_54 . V_287 = F_126 ;
V_214 -> V_277 . V_54 . type = & V_288 ;
F_50 ( & V_214 -> V_276 ) ;
V_100 = F_132 ( & V_214 -> V_277 ) ;
F_16 ( & V_279 ) ;
if ( V_100 ) {
F_133 ( & V_214 -> V_277 . V_54 ) ;
F_69 ( V_289
L_58
L_59 ,
V_100 ) ;
return V_100 ;
}
F_134 ( V_18 -> V_51 , L_60
L_61 ,
V_214 -> V_215 . V_266 ,
V_214 -> V_215 . V_257 ,
V_214 -> V_215 . V_258 ) ;
}
V_100 = F_135 ( & V_18 -> V_51 -> V_269 , & V_214 -> V_277 . V_54 . V_269 , L_47 ) ;
if ( V_100 ) {
F_69 ( V_289
L_62 ,
V_100 ) ;
goto V_48;
}
V_18 -> V_278 = F_136 ( V_47 , L_63 , V_280 ) ;
if ( ! V_18 -> V_278 ) {
V_100 = - V_52 ;
F_69 ( V_289
L_64 ,
V_100 ) ;
goto V_48;
}
V_100 = F_135 ( & V_214 -> V_277 . V_54 . V_269 , & V_18 -> V_51 -> V_269 ,
V_18 -> V_278 ) ;
if ( V_100 ) {
F_17 ( V_18 -> V_278 ) ;
V_18 -> V_278 = NULL ;
F_69 ( V_289
L_58
L_65 ,
V_100 ) ;
goto V_48;
}
return 0 ;
V_48:
F_129 ( V_18 ) ;
return V_100 ;
}
static int
F_137 ( T_1 V_18 , int V_159 )
{
struct V_167 V_14 ;
struct V_61 V_290 ;
V_290 . V_7 = V_60 ;
V_290 . V_59 = V_77 ;
V_290 . V_64 = 0 ;
V_14 . V_92 = V_172 ;
V_14 . V_106 = V_291 ;
V_14 . V_94 = NULL ;
V_14 . V_93 = 0 ;
return F_79 ( NULL ,
V_18 ,
(struct V_5 * ) & V_290 ,
0 ,
& V_14 ,
V_18 ,
NULL ,
NULL ,
0 ,
V_18 -> V_140 [ 0 ] . V_139 ,
V_18 -> V_140 [ 0 ] . V_64 ,
- 1 , 0 ) ;
}
static void
F_138 ( T_1 V_18 , struct V_13 * V_14 )
{
if ( ( V_14 -> V_6 . V_7 != V_60 )
|| ( V_14 -> V_14 . V_92 != V_292 )
|| ( V_14 -> V_14 . V_106 != V_291 ) )
return;
if ( V_14 -> V_14 . V_94 [ 0 ] != 0 ) {
V_18 -> V_214 -> V_275 = 0 ;
goto V_155;
}
if ( V_14 -> V_14 . V_93 < 17 ) {
V_18 -> V_214 -> V_275 = 0 ;
F_69 (KERN_WARNING PFX
L_66
L_67
L_68 ,
msg->msg.data_len) ;
goto V_155;
}
memcpy ( V_18 -> V_214 -> V_253 , V_14 -> V_14 . V_94 , 16 ) ;
V_18 -> V_214 -> V_275 = 1 ;
V_155:
F_139 ( & V_18 -> V_293 ) ;
}
static void
F_140 ( T_1 V_18 )
{
int V_100 ;
V_18 -> V_214 -> V_275 = 0x2 ;
V_18 -> V_81 = F_138 ;
V_100 = F_137 ( V_18 , 0 ) ;
if ( V_100 )
V_18 -> V_214 -> V_275 = 0 ;
F_141 ( V_18 -> V_293 , V_18 -> V_214 -> V_275 != 2 ) ;
V_18 -> V_81 = NULL ;
}
static int
F_142 ( T_1 V_18 , int V_159 )
{
struct V_167 V_14 ;
unsigned char V_94 [ 1 ] ;
struct V_61 V_290 ;
V_290 . V_7 = V_60 ;
V_290 . V_59 = V_77 ;
V_290 . V_64 = 0 ;
V_14 . V_92 = V_172 ;
V_14 . V_106 = V_294 ;
V_14 . V_94 = V_94 ;
V_14 . V_93 = 1 ;
V_94 [ 0 ] = V_159 ;
return F_79 ( NULL ,
V_18 ,
(struct V_5 * ) & V_290 ,
0 ,
& V_14 ,
V_18 ,
NULL ,
NULL ,
0 ,
V_18 -> V_140 [ 0 ] . V_139 ,
V_18 -> V_140 [ 0 ] . V_64 ,
- 1 , 0 ) ;
}
static void
F_143 ( T_1 V_18 , struct V_13 * V_14 )
{
int V_100 = 0 ;
int V_159 ;
if ( ( V_14 -> V_6 . V_7 == V_60 )
&& ( V_14 -> V_14 . V_92 == V_292 )
&& ( V_14 -> V_14 . V_106 == V_294 ) ) {
if ( V_14 -> V_14 . V_94 [ 0 ] != 0 ) {
if ( V_14 -> V_14 . V_94 [ 0 ] == V_295 ) {
V_18 -> V_140 [ 0 ] . V_199
= V_200 ;
V_18 -> V_140 [ 0 ] . V_296
= V_297 ;
V_18 -> V_298 = V_78 ;
F_139 ( & V_18 -> V_293 ) ;
goto V_155;
}
goto V_299;
}
if ( V_14 -> V_14 . V_93 < 4 ) {
goto V_299;
}
V_159 = V_18 -> V_298 ;
V_18 -> V_140 [ V_159 ] . V_199 = V_14 -> V_14 . V_94 [ 2 ] & 0x7f ;
V_18 -> V_140 [ V_159 ] . V_296 = V_14 -> V_14 . V_94 [ 3 ] & 0x1f ;
V_299:
V_18 -> V_298 ++ ;
if ( V_18 -> V_298 >= V_78 )
F_139 ( & V_18 -> V_293 ) ;
else
V_100 = F_142 ( V_18 , V_18 -> V_298 ) ;
if ( V_100 ) {
F_69 (KERN_WARNING PFX
L_69
L_70 , intf->curr_channel, rv) ;
V_18 -> V_298 = V_78 ;
F_139 ( & V_18 -> V_293 ) ;
}
}
V_155:
return;
}
static void F_144 ( T_1 V_18 )
{
if ( V_18 -> V_119 -> V_300 )
V_18 -> V_119 -> V_300 ( V_18 -> V_122 ) ;
F_145 ( V_18 ) ;
}
void F_146 ( T_2 V_79 )
{
F_144 ( V_79 -> V_18 ) ;
}
int F_147 ( const struct V_128 * V_119 ,
void * V_122 ,
struct V_301 * V_258 ,
struct V_53 * V_51 ,
unsigned char V_68 )
{
int V_19 , V_302 ;
int V_100 ;
T_1 V_18 ;
T_1 V_303 ;
struct V_11 * V_16 ;
if ( ! V_115 ) {
V_100 = F_48 () ;
if ( V_100 )
return V_100 ;
if ( ! V_115 )
return - V_107 ;
}
V_18 = F_148 ( sizeof( * V_18 ) , V_47 ) ;
if ( ! V_18 )
return - V_52 ;
V_18 -> V_137 = V_137 ( V_258 ) ;
V_18 -> V_138 = V_138 ( V_258 ) ;
V_18 -> V_214 = F_148 ( sizeof( * V_18 -> V_214 ) , V_47 ) ;
if ( ! V_18 -> V_214 ) {
F_17 ( V_18 ) ;
return - V_52 ;
}
V_18 -> V_46 = - 1 ;
F_50 ( & V_18 -> V_37 ) ;
V_18 -> V_214 -> V_215 = * V_258 ;
V_18 -> V_51 = V_51 ;
for ( V_302 = 0 ; V_302 < V_78 ; V_302 ++ ) {
V_18 -> V_140 [ V_302 ] . V_139 = V_304 ;
V_18 -> V_140 [ V_302 ] . V_64 = 2 ;
}
if ( V_68 != 0 )
V_18 -> V_140 [ 0 ] . V_139 = V_68 ;
F_14 ( & V_18 -> V_124 ) ;
V_18 -> V_119 = V_119 ;
V_18 -> V_122 = V_122 ;
F_149 ( & V_18 -> V_109 ) ;
for ( V_302 = 0 ; V_302 < V_30 ; V_302 ++ ) {
V_18 -> V_31 [ V_302 ] . V_32 = 0 ;
V_18 -> V_31 [ V_302 ] . V_99 = 0 ;
}
V_18 -> V_101 = 0 ;
#ifdef F_101
F_150 ( & V_18 -> V_244 ) ;
#endif
F_149 ( & V_18 -> V_305 ) ;
F_14 ( & V_18 -> V_25 ) ;
F_151 ( & V_18 -> V_24 ,
V_306 ,
( unsigned long ) V_18 ) ;
F_152 ( & V_18 -> V_307 , 0 ) ;
F_149 ( & V_18 -> V_181 ) ;
F_14 ( & V_18 -> V_179 ) ;
F_14 ( & V_18 -> V_178 ) ;
F_149 ( & V_18 -> V_154 ) ;
F_152 ( & V_18 -> V_126 , 0 ) ;
V_18 -> V_308 = V_309 ;
F_14 ( & V_18 -> V_26 ) ;
V_18 -> V_157 = 0 ;
F_150 ( & V_18 -> V_27 ) ;
F_149 ( & V_18 -> V_143 ) ;
F_14 ( & V_18 -> V_28 ) ;
F_153 ( & V_18 -> V_293 ) ;
for ( V_19 = 0 ; V_19 < V_310 ; V_19 ++ )
F_152 ( & V_18 -> V_311 [ V_19 ] , 0 ) ;
V_18 -> V_243 = NULL ;
F_13 ( & V_44 ) ;
F_13 ( & V_45 ) ;
V_19 = 0 ;
V_16 = & V_312 ;
F_49 (tintf, &ipmi_interfaces, link) {
if ( V_303 -> V_46 != V_19 ) {
V_16 = & V_303 -> V_16 ;
break;
}
V_19 ++ ;
}
if ( V_19 == 0 )
F_51 ( & V_18 -> V_16 , & V_312 ) ;
else
F_154 ( & V_18 -> V_16 , V_16 ) ;
V_100 = V_119 -> V_313 ( V_122 , V_18 ) ;
if ( V_100 )
goto V_155;
F_140 ( V_18 ) ;
if ( ( V_18 -> V_137 > 1 )
|| ( ( V_18 -> V_137 == 1 )
&& ( V_18 -> V_138 >= 5 ) ) ) {
V_18 -> V_81 = F_143 ;
V_18 -> V_298 = 0 ;
V_100 = F_142 ( V_18 , 0 ) ;
if ( V_100 ) {
F_69 (KERN_WARNING PFX
L_69
L_71 , rv) ;
goto V_155;
}
F_141 ( V_18 -> V_293 ,
V_18 -> V_298 >= V_78 ) ;
V_18 -> V_81 = NULL ;
} else {
V_18 -> V_140 [ 0 ] . V_199 = V_200 ;
V_18 -> V_140 [ 0 ] . V_296 = V_297 ;
V_18 -> V_298 = V_78 ;
}
if ( V_100 == 0 )
V_100 = F_104 ( V_18 , V_19 ) ;
V_100 = F_131 ( V_18 , V_19 ) ;
V_155:
if ( V_100 ) {
if ( V_18 -> V_243 )
F_106 ( V_18 ) ;
V_18 -> V_119 = NULL ;
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
return V_100 ;
}
static void F_156 ( T_1 V_18 ,
struct V_17 * V_14 ,
unsigned char V_88 )
{
V_14 -> V_314 [ 0 ] = V_14 -> V_94 [ 0 ] | 4 ;
V_14 -> V_314 [ 1 ] = V_14 -> V_94 [ 1 ] ;
V_14 -> V_314 [ 2 ] = V_88 ;
V_14 -> V_315 = 3 ;
F_157 ( V_18 , V_14 ) ;
}
static void F_158 ( T_1 V_18 )
{
int V_19 ;
struct V_31 * V_111 ;
struct V_17 * V_14 ;
struct V_11 * V_242 ;
struct V_11 V_316 ;
F_14 ( & V_316 ) ;
F_159 ( & V_18 -> V_178 , & V_316 ) ;
F_159 ( & V_18 -> V_179 , & V_316 ) ;
while ( V_18 -> V_177 && ! F_67 ( & V_18 -> V_25 ) ) {
F_160 ( 1 ) ;
}
while ( ! F_67 ( & V_316 ) ) {
V_242 = V_316 . V_133 ;
F_7 ( V_242 ) ;
V_14 = F_161 ( V_242 , struct V_17 , V_16 ) ;
F_156 ( V_18 , V_14 , V_317 ) ;
}
for ( V_19 = 0 ; V_19 < V_30 ; V_19 ++ ) {
V_111 = & ( V_18 -> V_31 [ V_19 ] ) ;
if ( ! V_111 -> V_32 )
continue;
F_37 ( V_111 -> V_33 , V_317 ) ;
}
}
int F_162 ( T_1 V_18 )
{
struct V_38 * V_55 ;
int V_46 = V_18 -> V_46 ;
T_2 V_79 ;
F_129 ( V_18 ) ;
F_13 ( & V_44 ) ;
F_13 ( & V_45 ) ;
V_18 -> V_46 = - 1 ;
V_18 -> V_186 = true ;
F_57 ( & V_18 -> V_16 ) ;
F_16 ( & V_45 ) ;
V_29 () ;
F_158 ( V_18 ) ;
F_13 ( & V_45 ) ;
F_82 () ;
F_49 (user, &intf->users, link) {
F_31 ( V_18 -> V_119 -> V_56 ) ;
if ( V_18 -> V_119 -> V_134 )
V_18 -> V_119 -> V_134 ( V_18 -> V_122 ) ;
}
F_85 () ;
V_18 -> V_119 = NULL ;
F_16 ( & V_45 ) ;
F_106 ( V_18 ) ;
F_22 (w, &smi_watchers, link)
V_55 -> V_318 ( V_46 ) ;
F_16 ( & V_44 ) ;
F_27 ( & V_18 -> V_37 , F_18 ) ;
return 0 ;
}
static int F_163 ( T_1 V_18 ,
struct V_17 * V_14 )
{
struct V_65 V_168 ;
struct V_13 * V_33 ;
if ( V_14 -> V_315 < 11 ) {
F_36 ( V_18 , V_221 ) ;
return 0 ;
}
if ( V_14 -> V_314 [ 2 ] != 0 ) {
return 0 ;
}
V_168 . V_7 = V_9 ;
V_168 . V_68 = V_14 -> V_314 [ 6 ] ;
V_168 . V_59 = V_14 -> V_314 [ 3 ] & 0x0f ;
V_168 . V_64 = V_14 -> V_314 [ 7 ] & 3 ;
if ( F_41 ( V_18 ,
V_14 -> V_314 [ 7 ] >> 2 ,
V_14 -> V_314 [ 3 ] & 0x0f ,
V_14 -> V_314 [ 8 ] ,
( V_14 -> V_314 [ 4 ] >> 2 ) & ( ~ 1 ) ,
(struct V_5 * ) & ( V_168 ) ,
& V_33 ) ) {
F_36 ( V_18 , V_222 ) ;
return 0 ;
}
memcpy ( V_33 -> V_91 ,
& ( V_14 -> V_314 [ 9 ] ) ,
V_14 -> V_315 - 9 ) ;
V_33 -> V_14 . V_92 = V_14 -> V_314 [ 4 ] >> 2 ;
V_33 -> V_14 . V_94 = V_33 -> V_91 ;
V_33 -> V_14 . V_93 = V_14 -> V_315 - 10 ;
V_33 -> V_89 = V_90 ;
F_36 ( V_18 , V_220 ) ;
F_35 ( V_33 ) ;
return 0 ;
}
static int F_164 ( T_1 V_18 ,
struct V_17 * V_14 )
{
struct V_20 * V_21 ;
int V_100 = 0 ;
unsigned char V_92 ;
unsigned char V_106 ;
unsigned char V_159 ;
T_2 V_79 = NULL ;
struct V_65 * V_168 ;
struct V_13 * V_33 ;
if ( V_14 -> V_315 < 10 ) {
F_36 ( V_18 , V_230 ) ;
return 0 ;
}
if ( V_14 -> V_314 [ 2 ] != 0 ) {
return 0 ;
}
V_92 = V_14 -> V_314 [ 4 ] >> 2 ;
V_106 = V_14 -> V_314 [ 8 ] ;
V_159 = V_14 -> V_314 [ 3 ] & 0xf ;
F_82 () ;
V_21 = F_70 ( V_18 , V_92 , V_106 , V_159 ) ;
if ( V_21 ) {
V_79 = V_21 -> V_79 ;
F_24 ( & V_79 -> V_37 ) ;
} else
V_79 = NULL ;
F_85 () ;
if ( V_79 == NULL ) {
F_36 ( V_18 , V_231 ) ;
V_14 -> V_94 [ 0 ] = ( V_172 << 2 ) ;
V_14 -> V_94 [ 1 ] = V_173 ;
V_14 -> V_94 [ 2 ] = V_14 -> V_314 [ 3 ] ;
V_14 -> V_94 [ 3 ] = V_14 -> V_314 [ 6 ] ;
V_14 -> V_94 [ 4 ] = ( ( V_92 + 1 ) << 2 ) | ( V_14 -> V_314 [ 7 ] & 0x3 ) ;
V_14 -> V_94 [ 5 ] = F_74 ( & ( V_14 -> V_94 [ 3 ] ) , 2 ) ;
V_14 -> V_94 [ 6 ] = V_18 -> V_140 [ V_14 -> V_314 [ 3 ] & 0xf ] . V_139 ;
V_14 -> V_94 [ 7 ] = ( V_14 -> V_314 [ 7 ] & 0xfc ) | ( V_14 -> V_314 [ 4 ] & 0x3 ) ;
V_14 -> V_94 [ 8 ] = V_14 -> V_314 [ 8 ] ;
V_14 -> V_94 [ 9 ] = V_319 ;
V_14 -> V_94 [ 10 ] = F_74 ( & ( V_14 -> V_94 [ 6 ] ) , 4 ) ;
V_14 -> V_174 = 11 ;
#ifdef F_84
{
int V_207 ;
F_69 ( L_72 ) ;
for ( V_207 = 0 ; V_207 < V_14 -> V_174 ; V_207 ++ )
F_69 ( L_3 , V_14 -> V_94 [ V_207 ] ) ;
F_69 ( L_4 ) ;
}
#endif
F_82 () ;
if ( ! V_18 -> V_186 ) {
F_78 ( V_18 , V_18 -> V_119 , V_14 , 0 ) ;
V_100 = - 1 ;
}
F_85 () ;
} else {
F_36 ( V_18 , V_229 ) ;
V_33 = F_80 () ;
if ( ! V_33 ) {
V_100 = 1 ;
F_27 ( & V_79 -> V_37 , F_54 ) ;
} else {
V_168 = (struct V_65 * ) & V_33 -> V_6 ;
V_168 -> V_7 = V_9 ;
V_168 -> V_68 = V_14 -> V_314 [ 6 ] ;
V_168 -> V_64 = V_14 -> V_314 [ 7 ] & 3 ;
V_168 -> V_59 = V_14 -> V_314 [ 3 ] & 0xf ;
V_33 -> V_79 = V_79 ;
V_33 -> V_89 = V_320 ;
V_33 -> V_110 = V_14 -> V_314 [ 7 ] >> 2 ;
V_33 -> V_14 . V_92 = V_14 -> V_314 [ 4 ] >> 2 ;
V_33 -> V_14 . V_106 = V_14 -> V_314 [ 8 ] ;
V_33 -> V_14 . V_94 = V_33 -> V_91 ;
V_33 -> V_14 . V_93 = V_14 -> V_315 - 10 ;
memcpy ( V_33 -> V_91 ,
& ( V_14 -> V_314 [ 9 ] ) ,
V_14 -> V_315 - 10 ) ;
F_35 ( V_33 ) ;
}
}
return V_100 ;
}
static int F_165 ( T_1 V_18 ,
struct V_17 * V_14 )
{
struct V_69 V_175 ;
struct V_13 * V_33 ;
if ( V_14 -> V_315 < 13 ) {
F_36 ( V_18 , V_227 ) ;
return 0 ;
}
if ( V_14 -> V_314 [ 2 ] != 0 ) {
return 0 ;
}
V_175 . V_7 = V_8 ;
V_175 . V_74 = V_14 -> V_314 [ 4 ] ;
V_175 . V_72 = V_14 -> V_314 [ 8 ] ;
V_175 . V_73 = V_14 -> V_314 [ 5 ] ;
V_175 . V_59 = V_14 -> V_314 [ 3 ] & 0x0f ;
V_175 . V_321 = V_14 -> V_314 [ 3 ] >> 4 ;
V_175 . V_64 = V_14 -> V_314 [ 9 ] & 3 ;
if ( F_41 ( V_18 ,
V_14 -> V_314 [ 9 ] >> 2 ,
V_14 -> V_314 [ 3 ] & 0x0f ,
V_14 -> V_314 [ 10 ] ,
( V_14 -> V_314 [ 6 ] >> 2 ) & ( ~ 1 ) ,
(struct V_5 * ) & ( V_175 ) ,
& V_33 ) ) {
F_36 ( V_18 , V_228 ) ;
return 0 ;
}
memcpy ( V_33 -> V_91 ,
& ( V_14 -> V_314 [ 11 ] ) ,
V_14 -> V_315 - 11 ) ;
V_33 -> V_14 . V_92 = V_14 -> V_314 [ 6 ] >> 2 ;
V_33 -> V_14 . V_94 = V_33 -> V_91 ;
V_33 -> V_14 . V_93 = V_14 -> V_315 - 12 ;
V_33 -> V_89 = V_90 ;
F_36 ( V_18 , V_226 ) ;
F_35 ( V_33 ) ;
return 0 ;
}
static int F_166 ( T_1 V_18 ,
struct V_17 * V_14 )
{
struct V_20 * V_21 ;
int V_100 = 0 ;
unsigned char V_92 ;
unsigned char V_106 ;
unsigned char V_159 ;
T_2 V_79 = NULL ;
struct V_69 * V_175 ;
struct V_13 * V_33 ;
if ( V_14 -> V_315 < 12 ) {
F_36 ( V_18 , V_230 ) ;
return 0 ;
}
if ( V_14 -> V_314 [ 2 ] != 0 ) {
return 0 ;
}
V_92 = V_14 -> V_314 [ 6 ] >> 2 ;
V_106 = V_14 -> V_314 [ 10 ] ;
V_159 = V_14 -> V_314 [ 3 ] & 0xf ;
F_82 () ;
V_21 = F_70 ( V_18 , V_92 , V_106 , V_159 ) ;
if ( V_21 ) {
V_79 = V_21 -> V_79 ;
F_24 ( & V_79 -> V_37 ) ;
} else
V_79 = NULL ;
F_85 () ;
if ( V_79 == NULL ) {
F_36 ( V_18 , V_231 ) ;
V_100 = 0 ;
} else {
F_36 ( V_18 , V_229 ) ;
V_33 = F_80 () ;
if ( ! V_33 ) {
V_100 = 1 ;
F_27 ( & V_79 -> V_37 , F_54 ) ;
} else {
V_175 = (struct V_69 * ) & V_33 -> V_6 ;
V_175 -> V_7 = V_8 ;
V_175 -> V_74 = V_14 -> V_314 [ 4 ] ;
V_175 -> V_72 = V_14 -> V_314 [ 8 ] ;
V_175 -> V_73 = V_14 -> V_314 [ 5 ] ;
V_175 -> V_64 = V_14 -> V_314 [ 9 ] & 3 ;
V_175 -> V_59 = V_14 -> V_314 [ 3 ] & 0xf ;
V_175 -> V_321 = V_14 -> V_314 [ 3 ] >> 4 ;
V_33 -> V_79 = V_79 ;
V_33 -> V_89 = V_320 ;
V_33 -> V_110 = V_14 -> V_314 [ 9 ] >> 2 ;
V_33 -> V_14 . V_92 = V_14 -> V_314 [ 6 ] >> 2 ;
V_33 -> V_14 . V_106 = V_14 -> V_314 [ 10 ] ;
V_33 -> V_14 . V_94 = V_33 -> V_91 ;
V_33 -> V_14 . V_93 = V_14 -> V_315 - 12 ;
memcpy ( V_33 -> V_91 ,
& ( V_14 -> V_314 [ 11 ] ) ,
V_14 -> V_315 - 12 ) ;
F_35 ( V_33 ) ;
}
}
return V_100 ;
}
static int F_167 ( T_1 V_18 ,
struct V_17 * V_14 )
{
struct V_20 * V_21 ;
int V_100 = 0 ;
unsigned char V_92 ;
unsigned char V_106 ;
unsigned char V_159 ;
T_2 V_79 = NULL ;
struct V_61 * V_187 ;
struct V_13 * V_33 ;
if ( V_14 -> V_315 < 4 ) {
F_36 ( V_18 , V_230 ) ;
return 0 ;
}
if ( V_14 -> V_314 [ 2 ] != 0 ) {
return 0 ;
}
V_92 = V_14 -> V_314 [ 0 ] >> 2 ;
V_106 = V_14 -> V_314 [ 1 ] ;
V_159 = V_14 -> V_314 [ 3 ] & 0xf ;
F_82 () ;
V_21 = F_70 ( V_18 , V_92 , V_106 , V_159 ) ;
if ( V_21 ) {
V_79 = V_21 -> V_79 ;
F_24 ( & V_79 -> V_37 ) ;
} else
V_79 = NULL ;
F_85 () ;
if ( V_79 == NULL ) {
F_36 ( V_18 , V_231 ) ;
V_100 = 0 ;
} else {
F_36 ( V_18 , V_229 ) ;
V_33 = F_80 () ;
if ( ! V_33 ) {
V_100 = 1 ;
F_27 ( & V_79 -> V_37 , F_54 ) ;
} else {
V_187 = ( (struct V_61 * )
& ( V_33 -> V_6 ) ) ;
V_187 -> V_7 = V_60 ;
V_187 -> V_59 = V_77 ;
V_187 -> V_64 = V_14 -> V_314 [ 0 ] & 3 ;
V_33 -> V_79 = V_79 ;
V_33 -> V_80 = NULL ;
V_33 -> V_89 = V_322 ;
V_33 -> V_14 . V_92 = V_14 -> V_314 [ 0 ] >> 2 ;
V_33 -> V_14 . V_106 = V_14 -> V_314 [ 1 ] ;
V_33 -> V_14 . V_94 = V_33 -> V_91 ;
V_33 -> V_14 . V_93 = V_14 -> V_315 - 4 ;
memcpy ( V_33 -> V_91 ,
& ( V_14 -> V_314 [ 4 ] ) ,
V_14 -> V_315 - 4 ) ;
F_35 ( V_33 ) ;
}
}
return V_100 ;
}
static void F_168 ( struct V_13 * V_33 ,
struct V_17 * V_14 )
{
struct V_61 * V_187 ;
V_33 -> V_110 = 0 ;
V_187 = (struct V_61 * ) & ( V_33 -> V_6 ) ;
V_187 -> V_7 = V_60 ;
V_187 -> V_59 = V_77 ;
V_187 -> V_64 = V_14 -> V_314 [ 0 ] & 3 ;
V_33 -> V_89 = V_323 ;
V_33 -> V_14 . V_92 = V_14 -> V_314 [ 0 ] >> 2 ;
V_33 -> V_14 . V_106 = V_14 -> V_314 [ 1 ] ;
memcpy ( V_33 -> V_91 , & ( V_14 -> V_314 [ 3 ] ) , V_14 -> V_315 - 3 ) ;
V_33 -> V_14 . V_94 = V_33 -> V_91 ;
V_33 -> V_14 . V_93 = V_14 -> V_315 - 3 ;
}
static int F_169 ( T_1 V_18 ,
struct V_17 * V_14 )
{
struct V_13 * V_33 , * V_324 ;
struct V_11 V_153 ;
T_2 V_79 ;
int V_100 = 0 ;
int V_325 = 0 ;
unsigned long V_108 ;
if ( V_14 -> V_315 < 19 ) {
F_36 ( V_18 , V_232 ) ;
return 0 ;
}
if ( V_14 -> V_314 [ 2 ] != 0 ) {
return 0 ;
}
F_14 ( & V_153 ) ;
F_42 ( & V_18 -> V_154 , V_108 ) ;
F_36 ( V_18 , V_233 ) ;
F_82 () ;
F_49 (user, &intf->users, link) {
if ( ! V_79 -> V_118 )
continue;
V_33 = F_80 () ;
if ( ! V_33 ) {
F_85 () ;
F_6 (recv_msg, recv_msg2, &msgs,
link) {
F_7 ( & V_33 -> V_16 ) ;
F_8 ( V_33 ) ;
}
V_100 = 1 ;
goto V_155;
}
V_325 ++ ;
F_168 ( V_33 , V_14 ) ;
V_33 -> V_79 = V_79 ;
F_24 ( & V_79 -> V_37 ) ;
F_25 ( & ( V_33 -> V_16 ) , & V_153 ) ;
}
F_85 () ;
if ( V_325 ) {
F_6 (recv_msg, recv_msg2, &msgs, link) {
F_7 ( & V_33 -> V_16 ) ;
F_35 ( V_33 ) ;
}
} else if ( V_18 -> V_157 < V_326 ) {
V_33 = F_80 () ;
if ( ! V_33 ) {
V_100 = 1 ;
goto V_155;
}
F_168 ( V_33 , V_14 ) ;
F_25 ( & ( V_33 -> V_16 ) , & ( V_18 -> V_26 ) ) ;
V_18 -> V_157 ++ ;
} else if ( ! V_18 -> V_158 ) {
F_69 (KERN_WARNING PFX L_73
L_74 ) ;
V_18 -> V_158 = 1 ;
}
V_155:
F_43 ( & ( V_18 -> V_154 ) , V_108 ) ;
return V_100 ;
}
static int F_170 ( T_1 V_18 ,
struct V_17 * V_14 )
{
struct V_13 * V_33 ;
struct V_131 * V_79 ;
V_33 = (struct V_13 * ) V_14 -> V_197 ;
if ( V_33 == NULL ) {
F_69 ( V_327
L_75
L_76
L_77
L_78 ) ;
return 0 ;
}
V_79 = V_33 -> V_79 ;
if ( V_79 && ! V_79 -> V_123 ) {
F_36 ( V_18 , V_83 ) ;
F_8 ( V_33 ) ;
} else {
struct V_61 * V_187 ;
F_36 ( V_18 , V_82 ) ;
V_33 -> V_89 = V_90 ;
V_33 -> V_110 = V_14 -> V_110 ;
V_187 = ( (struct V_61 * )
& ( V_33 -> V_6 ) ) ;
V_187 -> V_7 = V_60 ;
V_187 -> V_59 = V_77 ;
V_187 -> V_64 = V_14 -> V_314 [ 0 ] & 3 ;
V_33 -> V_14 . V_92 = V_14 -> V_314 [ 0 ] >> 2 ;
V_33 -> V_14 . V_106 = V_14 -> V_314 [ 1 ] ;
memcpy ( V_33 -> V_91 ,
& ( V_14 -> V_314 [ 2 ] ) ,
V_14 -> V_315 - 2 ) ;
V_33 -> V_14 . V_94 = V_33 -> V_91 ;
V_33 -> V_14 . V_93 = V_14 -> V_315 - 2 ;
F_35 ( V_33 ) ;
}
return 0 ;
}
static int F_157 ( T_1 V_18 ,
struct V_17 * V_14 )
{
int V_328 ;
int V_159 ;
#ifdef F_84
int V_207 ;
F_69 ( L_79 ) ;
for ( V_207 = 0 ; V_207 < V_14 -> V_315 ; V_207 ++ )
F_69 ( L_3 , V_14 -> V_314 [ V_207 ] ) ;
F_69 ( L_4 ) ;
#endif
if ( V_14 -> V_315 < 2 ) {
F_69 (KERN_WARNING PFX L_80
L_81 ,
(msg->data[0] >> 2) | 1 , msg->data[1], msg->rsp_size) ;
V_14 -> V_314 [ 0 ] = V_14 -> V_94 [ 0 ] | ( 1 << 2 ) ;
V_14 -> V_314 [ 1 ] = V_14 -> V_94 [ 1 ] ;
V_14 -> V_314 [ 2 ] = V_317 ;
V_14 -> V_315 = 3 ;
} else if ( ( ( V_14 -> V_314 [ 0 ] >> 2 ) != ( ( V_14 -> V_94 [ 0 ] >> 2 ) | 1 ) )
|| ( V_14 -> V_314 [ 1 ] != V_14 -> V_94 [ 1 ] ) ) {
F_69 (KERN_WARNING PFX L_82
L_83 ,
(msg->data[0] >> 2) | 1 , msg->data[1],
msg->rsp[0] >> 2 , msg->rsp[1]) ;
V_14 -> V_314 [ 0 ] = V_14 -> V_94 [ 0 ] | ( 1 << 2 ) ;
V_14 -> V_314 [ 1 ] = V_14 -> V_94 [ 1 ] ;
V_14 -> V_314 [ 2 ] = V_317 ;
V_14 -> V_315 = 3 ;
}
if ( ( V_14 -> V_314 [ 0 ] == ( ( V_172 | 1 ) << 2 ) )
&& ( V_14 -> V_314 [ 1 ] == V_173 )
&& ( V_14 -> V_197 != NULL ) ) {
struct V_13 * V_33 = V_14 -> V_197 ;
V_328 = 0 ;
if ( V_14 -> V_315 < 2 )
goto V_155;
V_159 = V_14 -> V_94 [ 2 ] & 0x0f ;
if ( V_159 >= V_78 )
goto V_155;
if ( ! V_33 )
goto V_155;
if ( ! V_33 -> V_79 || ! V_33 -> V_79 -> V_123 )
goto V_155;
V_33 -> V_89 = V_329 ;
V_33 -> V_14 . V_94 = V_33 -> V_91 ;
V_33 -> V_14 . V_93 = 1 ;
V_33 -> V_91 [ 0 ] = V_14 -> V_314 [ 2 ] ;
F_35 ( V_33 ) ;
} else if ( ( V_14 -> V_314 [ 0 ] == ( ( V_172 | 1 ) << 2 ) )
&& ( V_14 -> V_314 [ 1 ] == V_189 ) ) {
V_159 = V_14 -> V_314 [ 3 ] & 0xf ;
if ( V_159 >= V_78 ) {
V_328 = 0 ;
goto V_155;
}
if ( V_18 -> V_298 < V_78 ) {
V_328 = 0 ;
goto V_155;
}
switch ( V_18 -> V_140 [ V_159 ] . V_199 ) {
case V_200 :
if ( V_14 -> V_314 [ 4 ] & 0x04 ) {
V_328 = F_163 ( V_18 , V_14 ) ;
} else {
V_328 = F_164 ( V_18 , V_14 ) ;
}
break;
case V_203 :
case V_204 :
if ( V_14 -> V_314 [ 6 ] & 0x04 ) {
V_328 = F_165 ( V_18 , V_14 ) ;
} else {
V_328 = F_166 ( V_18 , V_14 ) ;
}
break;
default:
if ( ( V_18 -> V_140 [ V_159 ] . V_199
>= V_330 )
&& ( V_18 -> V_140 [ V_159 ] . V_199
<= V_331 ) ) {
V_328 = F_167 ( V_18 , V_14 ) ;
} else {
V_328 = 0 ;
}
}
} else if ( ( V_14 -> V_314 [ 0 ] == ( ( V_172 | 1 ) << 2 ) )
&& ( V_14 -> V_314 [ 1 ] == V_190 ) ) {
V_328 = F_169 ( V_18 , V_14 ) ;
} else {
V_328 = F_170 ( V_18 , V_14 ) ;
}
V_155:
return V_328 ;
}
static void F_145 ( T_1 V_18 )
{
struct V_17 * V_166 ;
unsigned long V_108 = 0 ;
int V_100 ;
int V_180 = V_18 -> V_180 ;
if ( ! V_180 )
F_42 ( & V_18 -> V_305 , V_108 ) ;
while ( ! F_67 ( & V_18 -> V_25 ) ) {
V_166 = F_161 ( V_18 -> V_25 . V_133 ,
struct V_17 , V_16 ) ;
if ( ! V_180 )
F_43 ( & V_18 -> V_305 ,
V_108 ) ;
V_100 = F_157 ( V_18 , V_166 ) ;
if ( ! V_180 )
F_42 ( & V_18 -> V_305 , V_108 ) ;
if ( V_100 > 0 ) {
break;
} else {
F_7 ( & V_166 -> V_16 ) ;
if ( V_100 == 0 )
F_10 ( V_166 ) ;
}
}
if ( ! V_180 )
F_43 ( & V_18 -> V_305 , V_108 ) ;
if ( F_171 ( & V_18 -> V_307 , - 1 , 0 ) ) {
T_2 V_79 ;
F_82 () ;
F_49 (user, &intf->users, link) {
if ( V_79 -> V_85 -> V_125 )
V_79 -> V_85 -> V_125 (
V_79 -> V_87 ) ;
}
F_85 () ;
}
}
static void V_306 ( unsigned long V_152 )
{
unsigned long V_108 = 0 ;
T_1 V_18 = ( T_1 ) V_152 ;
int V_180 = V_18 -> V_180 ;
struct V_17 * V_332 = NULL ;
if ( ! V_180 )
F_42 ( & V_18 -> V_181 , V_108 ) ;
if ( V_18 -> V_177 == NULL && ! V_18 -> V_186 ) {
struct V_11 * V_242 = NULL ;
if ( ! F_67 ( & V_18 -> V_178 ) )
V_242 = V_18 -> V_178 . V_133 ;
else if ( ! F_67 ( & V_18 -> V_179 ) )
V_242 = V_18 -> V_179 . V_133 ;
if ( V_242 ) {
F_7 ( V_242 ) ;
V_332 = F_161 ( V_242 , struct V_17 , V_16 ) ;
V_18 -> V_177 = V_332 ;
}
}
if ( ! V_180 )
F_43 ( & V_18 -> V_181 , V_108 ) ;
if ( V_332 )
V_18 -> V_119 -> V_182 ( V_18 -> V_122 , V_332 ) ;
F_145 ( V_18 ) ;
}
void F_172 ( T_1 V_18 ,
struct V_17 * V_14 )
{
unsigned long V_108 = 0 ;
int V_180 = V_18 -> V_180 ;
if ( ( V_14 -> V_174 >= 2 )
&& ( V_14 -> V_94 [ 0 ] == ( V_172 << 2 ) )
&& ( V_14 -> V_94 [ 1 ] == V_173 )
&& ( V_14 -> V_197 == NULL ) ) {
if ( V_18 -> V_186 )
goto V_333;
if ( ( V_14 -> V_315 >= 3 ) && ( V_14 -> V_314 [ 2 ] != 0 )
&& ( V_14 -> V_314 [ 2 ] != V_334 )
&& ( V_14 -> V_314 [ 2 ] != V_335 )
&& ( V_14 -> V_314 [ 2 ] != V_336 )
&& ( V_14 -> V_314 [ 2 ] != V_337 ) ) {
int V_159 = V_14 -> V_314 [ 3 ] & 0xf ;
if ( V_159 >= V_78 )
;
else if ( ( V_18 -> V_140 [ V_159 ] . V_199
== V_203 )
|| ( V_18 -> V_140 [ V_159 ] . V_199
== V_204 ) )
F_36 ( V_18 , V_223 ) ;
else
F_36 ( V_18 , V_216 ) ;
F_46 ( V_18 , V_14 -> V_110 , V_14 -> V_314 [ 2 ] ) ;
} else
F_44 ( V_18 , V_14 -> V_110 ) ;
V_333:
F_10 ( V_14 ) ;
} else {
if ( ! V_180 )
F_42 ( & V_18 -> V_305 , V_108 ) ;
F_25 ( & V_14 -> V_16 , & V_18 -> V_25 ) ;
if ( ! V_180 )
F_43 ( & V_18 -> V_305 ,
V_108 ) ;
}
if ( ! V_180 )
F_42 ( & V_18 -> V_181 , V_108 ) ;
if ( V_14 == V_18 -> V_177 )
V_18 -> V_177 = NULL ;
if ( ! V_180 )
F_43 ( & V_18 -> V_181 , V_108 ) ;
if ( V_180 )
V_306 ( ( unsigned long ) V_18 ) ;
else
F_173 ( & V_18 -> V_24 ) ;
}
void F_174 ( T_1 V_18 )
{
if ( V_18 -> V_186 )
return;
F_152 ( & V_18 -> V_307 , 1 ) ;
F_173 ( & V_18 -> V_24 ) ;
}
static struct V_17 *
F_175 ( T_1 V_18 , struct V_13 * V_33 ,
unsigned char V_98 , long V_99 )
{
struct V_17 * V_166 = F_81 () ;
if ( ! V_166 )
return NULL ;
memcpy ( V_166 -> V_94 , V_33 -> V_14 . V_94 , V_33 -> V_14 . V_93 ) ;
V_166 -> V_174 = V_33 -> V_14 . V_93 ;
V_166 -> V_110 = F_83 ( V_98 , V_99 ) ;
#ifdef F_84
{
int V_207 ;
F_69 ( L_84 ) ;
for ( V_207 = 0 ; V_207 < V_166 -> V_174 ; V_207 ++ )
F_69 ( L_3 , V_166 -> V_94 [ V_207 ] ) ;
F_69 ( L_4 ) ;
}
#endif
return V_166 ;
}
static void F_176 ( T_1 V_18 , struct V_31 * V_111 ,
struct V_11 * V_338 , long V_339 ,
int V_340 , unsigned long * V_108 ,
unsigned int * V_341 )
{
struct V_13 * V_14 ;
const struct V_128 * V_119 ;
if ( V_18 -> V_186 )
return;
if ( ! V_111 -> V_32 )
return;
V_111 -> V_95 -= V_339 ;
if ( V_111 -> V_95 > 0 ) {
( * V_341 ) ++ ;
return;
}
if ( V_111 -> V_104 == 0 ) {
V_111 -> V_32 = 0 ;
V_14 = V_111 -> V_33 ;
F_25 ( & V_14 -> V_16 , V_338 ) ;
if ( V_111 -> V_97 )
F_36 ( V_18 , V_219 ) ;
else if ( F_2 ( & V_111 -> V_33 -> V_6 ) )
F_36 ( V_18 , V_225 ) ;
else
F_36 ( V_18 , V_218 ) ;
} else {
struct V_17 * V_166 ;
( * V_341 ) ++ ;
V_111 -> V_95 = V_102 ;
V_111 -> V_104 -- ;
V_166 = F_175 ( V_18 , V_111 -> V_33 , V_340 ,
V_111 -> V_99 ) ;
if ( ! V_166 ) {
if ( F_2 ( & V_111 -> V_33 -> V_6 ) )
F_36 ( V_18 ,
V_234 ) ;
else
F_36 ( V_18 ,
V_235 ) ;
return;
}
F_43 ( & V_18 -> V_109 , * V_108 ) ;
V_119 = V_18 -> V_119 ;
if ( V_119 ) {
if ( F_2 ( & V_111 -> V_33 -> V_6 ) )
F_36 ( V_18 ,
V_224 ) ;
else
F_36 ( V_18 ,
V_217 ) ;
F_78 ( V_18 , V_119 , V_166 , 0 ) ;
} else
F_10 ( V_166 ) ;
F_42 ( & V_18 -> V_109 , * V_108 ) ;
}
}
static unsigned int F_177 ( T_1 V_18 , long V_339 )
{
struct V_11 V_338 ;
struct V_13 * V_14 , * V_15 ;
unsigned long V_108 ;
int V_19 ;
unsigned int V_341 = 0 ;
F_14 ( & V_338 ) ;
F_42 ( & V_18 -> V_109 , V_108 ) ;
for ( V_19 = 0 ; V_19 < V_30 ; V_19 ++ )
F_176 ( V_18 , & ( V_18 -> V_31 [ V_19 ] ) ,
& V_338 , V_339 , V_19 ,
& V_108 , & V_341 ) ;
F_43 ( & V_18 -> V_109 , V_108 ) ;
F_6 (msg, msg2, &timeouts, link)
F_37 ( V_14 , V_342 ) ;
if ( V_18 -> V_148 > 0 ) {
F_42 ( & V_18 -> V_143 , V_108 ) ;
if ( V_18 -> V_148 > 0 ) {
V_18 -> V_148
-= V_339 ;
if ( ! V_18 -> V_144
&& ( V_18 -> V_148 <= 0 ) ) {
V_18 -> V_146 = false ;
F_64 ( V_18 ) ;
}
}
F_43 ( & V_18 -> V_143 ,
V_108 ) ;
}
F_173 ( & V_18 -> V_24 ) ;
return V_341 ;
}
static void F_178 ( T_1 V_18 )
{
if ( V_18 -> V_146 )
return;
if ( ! V_18 -> V_186 )
V_18 -> V_119 -> V_343 ( V_18 -> V_122 ) ;
}
static void F_179 ( unsigned long V_94 )
{
T_1 V_18 ;
int V_344 = 0 ;
if ( F_180 ( & V_345 ) )
return;
F_82 () ;
F_49 (intf, &ipmi_interfaces, link) {
int V_346 = 0 ;
if ( F_180 ( & V_18 -> V_126 ) ) {
V_18 -> V_308 -- ;
if ( V_18 -> V_308 == 0 ) {
F_178 ( V_18 ) ;
V_18 -> V_308 = V_309 ;
}
V_346 ++ ;
}
V_346 += F_177 ( V_18 , V_347 ) ;
V_346 = ! ! V_346 ;
if ( V_346 != V_18 -> V_348 &&
V_18 -> V_119 -> V_349 )
V_18 -> V_119 -> V_349 ( V_18 -> V_122 , V_346 ) ;
V_18 -> V_348 = V_346 ;
V_344 += V_346 ;
}
F_85 () ;
if ( V_344 )
F_181 ( & V_350 , V_351 + V_352 ) ;
}
static void F_40 ( T_1 V_18 )
{
if ( ! F_182 ( & V_350 ) )
F_181 ( & V_350 , V_351 + V_352 ) ;
}
static void F_183 ( struct V_17 * V_14 )
{
F_56 ( & V_353 ) ;
F_17 ( V_14 ) ;
}
struct V_17 * F_81 ( void )
{
struct V_17 * V_100 ;
V_100 = F_23 ( sizeof( struct V_17 ) , V_354 ) ;
if ( V_100 ) {
V_100 -> V_355 = F_183 ;
V_100 -> V_197 = NULL ;
F_184 ( & V_353 ) ;
}
return V_100 ;
}
static void F_185 ( struct V_13 * V_14 )
{
F_56 ( & V_356 ) ;
F_17 ( V_14 ) ;
}
static struct V_13 * F_80 ( void )
{
struct V_13 * V_100 ;
V_100 = F_23 ( sizeof( struct V_13 ) , V_354 ) ;
if ( V_100 ) {
V_100 -> V_79 = NULL ;
V_100 -> V_355 = F_185 ;
F_184 ( & V_356 ) ;
}
return V_100 ;
}
void F_8 ( struct V_13 * V_14 )
{
if ( V_14 -> V_79 )
F_27 ( & V_14 -> V_79 -> V_37 , F_54 ) ;
V_14 -> V_355 ( V_14 ) ;
}
static void F_186 ( struct V_17 * V_14 )
{
F_56 ( & V_357 ) ;
}
static void F_187 ( struct V_13 * V_14 )
{
F_56 ( & V_357 ) ;
}
static void F_188 ( T_1 V_18 ,
struct V_5 * V_6 ,
struct V_167 * V_14 )
{
struct V_17 V_166 ;
struct V_13 V_33 ;
int V_100 ;
V_166 . V_355 = F_186 ;
V_33 . V_355 = F_187 ;
F_189 ( 2 , & V_357 ) ;
V_100 = F_79 ( NULL ,
V_18 ,
V_6 ,
0 ,
V_14 ,
V_18 ,
& V_166 ,
& V_33 ,
0 ,
V_18 -> V_140 [ 0 ] . V_139 ,
V_18 -> V_140 [ 0 ] . V_64 ,
0 , 1 ) ;
if ( V_100 )
F_190 ( 2 , & V_357 ) ;
else if ( V_18 -> V_119 -> V_358 )
V_18 -> V_119 -> V_358 ( V_18 -> V_122 ) ;
while ( F_180 ( & V_357 ) != 0 )
F_144 ( V_18 ) ;
}
static void F_191 ( T_1 V_18 , struct V_13 * V_14 )
{
if ( ( V_14 -> V_6 . V_7 == V_60 )
&& ( V_14 -> V_14 . V_92 == V_359 )
&& ( V_14 -> V_14 . V_106 == V_360 )
&& ( V_14 -> V_14 . V_94 [ 0 ] == V_361 ) ) {
V_18 -> V_362 = V_14 -> V_14 . V_94 [ 1 ] ;
V_18 -> V_363 = V_14 -> V_14 . V_94 [ 2 ] & 0x3 ;
}
}
static void F_192 ( T_1 V_18 , struct V_13 * V_14 )
{
if ( ( V_14 -> V_6 . V_7 == V_60 )
&& ( V_14 -> V_14 . V_92 == V_292 )
&& ( V_14 -> V_14 . V_106 == V_364 )
&& ( V_14 -> V_14 . V_94 [ 0 ] == V_361 ) ) {
V_18 -> V_365 = ( V_14 -> V_14 . V_94 [ 6 ] >> 2 ) & 1 ;
V_18 -> V_366 = ( V_14 -> V_14 . V_94 [ 6 ] >> 5 ) & 1 ;
}
}
static void F_193 ( char * V_367 )
{
struct V_167 V_14 ;
T_1 V_18 ;
unsigned char V_94 [ 16 ] ;
struct V_61 * V_290 ;
struct V_5 V_6 ;
V_290 = (struct V_61 * ) & V_6 ;
V_290 -> V_7 = V_60 ;
V_290 -> V_59 = V_77 ;
V_290 -> V_64 = 0 ;
V_14 . V_92 = 0x04 ;
V_14 . V_106 = 2 ;
V_14 . V_94 = V_94 ;
V_14 . V_93 = 8 ;
V_94 [ 0 ] = 0x41 ;
V_94 [ 1 ] = 0x03 ;
V_94 [ 2 ] = 0x20 ;
V_94 [ 4 ] = 0x6f ;
V_94 [ 5 ] = 0xa1 ;
if ( V_367 ) {
V_94 [ 3 ] = V_367 [ 0 ] ;
V_94 [ 6 ] = V_367 [ 1 ] ;
V_94 [ 7 ] = V_367 [ 2 ] ;
}
F_49 (intf, &ipmi_interfaces, link) {
if ( ! V_18 -> V_119 )
continue;
F_188 ( V_18 , & V_6 , & V_14 ) ;
}
#ifdef F_194
if ( ! V_367 )
return;
F_49 (intf, &ipmi_interfaces, link) {
char * V_368 = V_367 ;
struct V_65 * V_369 ;
int V_302 ;
if ( V_18 -> V_46 == - 1 )
continue;
F_195 () ;
V_18 -> V_365 = 0 ;
V_18 -> V_366 = 0 ;
V_18 -> V_362 = 0 ;
V_14 . V_92 = V_172 ;
V_14 . V_106 = V_364 ;
V_14 . V_94 = NULL ;
V_14 . V_93 = 0 ;
V_18 -> V_81 = F_192 ;
F_188 ( V_18 , & V_6 , & V_14 ) ;
if ( V_18 -> V_366 ) {
V_14 . V_92 = V_370 ;
V_14 . V_106 = V_360 ;
V_14 . V_94 = NULL ;
V_14 . V_93 = 0 ;
V_18 -> V_81 = F_191 ;
F_188 ( V_18 , & V_6 , & V_14 ) ;
}
V_18 -> V_81 = NULL ;
if ( ( ( V_18 -> V_362 & 1 ) == 0 )
&& ( V_18 -> V_362 != 0 )
&& ( V_18 -> V_362 != V_18 -> V_140 [ 0 ] . V_139 ) ) {
V_369 = (struct V_65 * ) & V_6 ;
V_369 -> V_7 = V_9 ;
V_369 -> V_59 = 0 ;
V_369 -> V_64 = V_18 -> V_363 ;
V_369 -> V_68 = V_18 -> V_362 ;
} else if ( V_18 -> V_365 ) {
V_290 = (struct V_61 * ) & V_6 ;
V_290 -> V_7 = V_60 ;
V_290 -> V_59 = V_77 ;
V_290 -> V_64 = 0 ;
} else
continue;
V_14 . V_92 = V_371 ;
V_14 . V_106 = V_372 ;
V_14 . V_94 = V_94 ;
V_14 . V_93 = 16 ;
V_302 = 0 ;
while ( * V_368 ) {
int V_164 = strlen ( V_368 ) ;
if ( V_164 > 11 )
V_164 = 11 ;
V_94 [ 0 ] = 0 ;
V_94 [ 1 ] = 0 ;
V_94 [ 2 ] = 0xf0 ;
V_94 [ 3 ] = V_18 -> V_140 [ 0 ] . V_139 ;
V_94 [ 4 ] = V_302 ++ ;
strncpy ( V_94 + 5 , V_368 , 11 ) ;
V_368 += V_164 ;
F_188 ( V_18 , & V_6 , & V_14 ) ;
}
}
#endif
}
static int F_196 ( struct V_373 * V_374 ,
unsigned long V_375 ,
void * V_376 )
{
T_1 V_18 ;
if ( V_377 )
return V_378 ;
V_377 = 1 ;
F_49 (intf, &ipmi_interfaces, link) {
if ( ! V_18 -> V_119 )
continue;
if ( ! F_197 ( & V_18 -> V_181 ) ) {
F_14 ( & V_18 -> V_179 ) ;
F_14 ( & V_18 -> V_178 ) ;
} else
F_198 ( & V_18 -> V_181 ) ;
if ( ! F_197 ( & V_18 -> V_305 ) )
F_14 ( & V_18 -> V_25 ) ;
else
F_198 ( & V_18 -> V_305 ) ;
V_18 -> V_180 = 1 ;
V_18 -> V_119 -> V_379 ( V_18 -> V_122 , 1 ) ;
}
#ifdef F_199
F_193 ( V_376 ) ;
#endif
return V_378 ;
}
static int F_48 ( void )
{
int V_100 ;
if ( V_115 )
return 0 ;
V_100 = F_200 ( & V_282 . V_283 ) ;
if ( V_100 ) {
F_69 (KERN_ERR PFX L_85 ) ;
return V_100 ;
}
F_69 ( V_284 L_86
V_380 L_4 ) ;
#ifdef F_101
V_248 = F_105 ( L_87 , NULL ) ;
if ( ! V_248 ) {
F_69 (KERN_ERR PFX L_88 ) ;
F_201 ( & V_282 . V_283 ) ;
return - V_52 ;
}
#endif
F_202 ( & V_350 , F_179 , 0 ) ;
F_181 ( & V_350 , V_351 + V_352 ) ;
F_203 ( & V_381 , & V_382 ) ;
V_115 = 1 ;
return 0 ;
}
static int T_5 F_204 ( void )
{
F_48 () ;
return 0 ;
}
static void T_6 F_205 ( void )
{
int V_383 ;
if ( ! V_115 )
return;
F_206 ( & V_381 , & V_382 ) ;
F_184 ( & V_345 ) ;
F_207 ( & V_350 ) ;
#ifdef F_101
F_208 ( V_248 ) ;
#endif
F_201 ( & V_282 . V_283 ) ;
V_115 = 0 ;
V_383 = F_180 ( & V_353 ) ;
if ( V_383 != 0 )
F_69 (KERN_WARNING PFX L_89 ,
count) ;
V_383 = F_180 ( & V_356 ) ;
if ( V_383 != 0 )
F_69 (KERN_WARNING PFX L_90 ,
count) ;
}
