static int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_4 ;
}
static int F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_5 ;
}
static int F_3 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_6 ;
}
static void F_4 ( struct V_7 * V_8 )
{
struct V_9 * V_10 , * V_11 ;
F_5 (msg, msg2, q, link) {
F_6 ( & V_10 -> V_12 ) ;
F_7 ( V_10 ) ;
}
}
static void F_8 ( struct V_7 * V_8 )
{
struct V_13 * V_10 , * V_11 ;
F_5 (msg, msg2, q, link) {
F_6 ( & V_10 -> V_12 ) ;
F_9 ( V_10 ) ;
}
}
static void F_10 ( T_1 V_14 )
{
int V_15 ;
struct V_16 * V_17 , * V_18 ;
struct V_7 V_19 ;
F_8 ( & V_14 -> V_20 ) ;
F_4 ( & V_14 -> V_21 ) ;
F_11 ( & V_14 -> V_22 ) ;
F_12 ( & V_19 ) ;
F_13 ( & V_14 -> V_23 , & V_19 , V_24 ) ;
F_14 ( & V_14 -> V_22 ) ;
F_5 (rcvr, rcvr2, &list, link)
F_15 ( V_17 ) ;
for ( V_15 = 0 ; V_15 < V_25 ; V_15 ++ ) {
if ( ( V_14 -> V_26 [ V_15 ] . V_27 )
&& ( V_14 -> V_26 [ V_15 ] . V_28 ) )
F_7 ( V_14 -> V_26 [ V_15 ] . V_28 ) ;
}
}
static void F_16 ( struct V_29 * V_30 )
{
T_1 V_14 = F_17 ( V_30 , struct V_31 , V_32 ) ;
F_10 ( V_14 ) ;
F_15 ( V_14 ) ;
}
int F_18 ( struct V_33 * V_34 )
{
T_1 V_14 ;
F_19 ( V_35 ) ;
struct V_36 * V_37 , * V_38 ;
F_11 ( & V_39 ) ;
F_11 ( & V_40 ) ;
F_20 (intf, &ipmi_interfaces, link) {
if ( V_14 -> V_41 == - 1 )
continue;
V_37 = F_21 ( sizeof( * V_37 ) , V_42 ) ;
if ( ! V_37 )
goto V_43;
F_22 ( & V_14 -> V_32 ) ;
V_37 -> V_14 = V_14 ;
V_37 -> V_41 = V_14 -> V_41 ;
F_23 ( & V_37 -> V_12 , & V_35 ) ;
}
F_24 ( & V_34 -> V_12 , & V_44 ) ;
F_14 ( & V_40 ) ;
F_5 (e, e2, &to_deliver, link) {
F_6 ( & V_37 -> V_12 ) ;
V_34 -> V_45 ( V_37 -> V_41 , V_37 -> V_14 -> V_46 ) ;
F_25 ( & V_37 -> V_14 -> V_32 , F_16 ) ;
F_15 ( V_37 ) ;
}
F_14 ( & V_39 ) ;
return 0 ;
V_43:
F_14 ( & V_40 ) ;
F_14 ( & V_39 ) ;
F_5 (e, e2, &to_deliver, link) {
F_6 ( & V_37 -> V_12 ) ;
F_25 ( & V_37 -> V_14 -> V_32 , F_16 ) ;
F_15 ( V_37 ) ;
}
return - V_47 ;
}
int F_26 ( struct V_33 * V_34 )
{
F_11 ( & V_39 ) ;
F_6 ( & ( V_34 -> V_12 ) ) ;
F_14 ( & V_39 ) ;
return 0 ;
}
static void
F_27 ( int V_15 , struct V_48 * V_49 )
{
struct V_33 * V_50 ;
F_20 (w, &smi_watchers, link) {
if ( F_28 ( V_50 -> V_51 ) ) {
V_50 -> V_45 ( V_15 , V_49 ) ;
F_29 ( V_50 -> V_51 ) ;
}
}
}
static int
F_30 ( struct V_1 * V_52 , struct V_1 * V_53 )
{
if ( V_52 -> V_3 != V_53 -> V_3 )
return 0 ;
if ( V_52 -> V_54 != V_53 -> V_54 )
return 0 ;
if ( V_52 -> V_3 == V_55 ) {
struct V_56 * V_57
= (struct V_56 * ) V_52 ;
struct V_56 * V_58
= (struct V_56 * ) V_53 ;
return ( V_57 -> V_59 == V_58 -> V_59 ) ;
}
if ( F_2 ( V_52 ) || F_3 ( V_52 ) ) {
struct V_60 * V_61
= (struct V_60 * ) V_52 ;
struct V_60 * V_62
= (struct V_60 * ) V_53 ;
return ( ( V_61 -> V_63 == V_62 -> V_63 )
&& ( V_61 -> V_59 == V_62 -> V_59 ) ) ;
}
if ( F_1 ( V_52 ) ) {
struct V_64 * V_65
= (struct V_64 * ) V_52 ;
struct V_64 * V_66
= (struct V_64 * ) V_53 ;
return ( ( V_65 -> V_67 == V_66 -> V_67 )
&& ( V_65 -> V_68 == V_66 -> V_68 )
&& ( V_65 -> V_69
== V_66 -> V_69 )
&& ( V_65 -> V_59 == V_66 -> V_59 ) ) ;
}
return 1 ;
}
int F_31 ( struct V_1 * V_2 , int V_70 )
{
if ( V_70 < sizeof( struct V_56 ) )
return - V_71 ;
if ( V_2 -> V_3 == V_55 ) {
if ( V_2 -> V_54 != V_72 )
return - V_71 ;
return 0 ;
}
if ( ( V_2 -> V_54 == V_72 )
|| ( V_2 -> V_54 >= V_73 )
|| ( V_2 -> V_54 < 0 ) )
return - V_71 ;
if ( F_2 ( V_2 ) || F_3 ( V_2 ) ) {
if ( V_70 < sizeof( struct V_60 ) )
return - V_71 ;
return 0 ;
}
if ( F_1 ( V_2 ) ) {
if ( V_70 < sizeof( struct V_64 ) )
return - V_71 ;
return 0 ;
}
return - V_71 ;
}
unsigned int F_32 ( int V_3 )
{
if ( V_3 == V_55 )
return sizeof( struct V_56 ) ;
if ( ( V_3 == V_5 )
|| ( V_3 == V_6 ) )
return sizeof( struct V_60 ) ;
if ( V_3 == V_4 )
return sizeof( struct V_64 ) ;
return 0 ;
}
static void F_33 ( struct V_9 * V_10 )
{
if ( ! V_10 -> V_74 ) {
T_1 V_14 = V_10 -> V_75 ;
if ( V_14 -> V_76 ) {
V_14 -> V_76 ( V_14 , V_10 ) ;
F_34 ( V_14 , V_77 ) ;
} else {
F_34 ( V_14 , V_78 ) ;
}
F_7 ( V_10 ) ;
} else {
T_2 V_74 = V_10 -> V_74 ;
V_74 -> V_79 -> V_80 ( V_10 , V_74 -> V_81 ) ;
}
}
static void
F_35 ( struct V_9 * V_10 , int V_82 )
{
V_10 -> V_83 = V_84 ;
V_10 -> V_85 [ 0 ] = V_82 ;
V_10 -> V_10 . V_86 |= 1 ;
V_10 -> V_10 . V_87 = 1 ;
V_10 -> V_10 . V_88 = V_10 -> V_85 ;
F_33 ( V_10 ) ;
}
static int F_36 ( T_1 V_14 ,
struct V_9 * V_28 ,
unsigned long V_89 ,
int V_90 ,
int V_91 ,
unsigned char * V_92 ,
long * V_93 )
{
int V_94 = 0 ;
unsigned int V_15 ;
for ( V_15 = V_14 -> V_95 ; ( V_15 + 1 ) % V_25 != V_14 -> V_95 ;
V_15 = ( V_15 + 1 ) % V_25 ) {
if ( ! V_14 -> V_26 [ V_15 ] . V_27 )
break;
}
if ( ! V_14 -> V_26 [ V_15 ] . V_27 ) {
V_14 -> V_26 [ V_15 ] . V_28 = V_28 ;
V_14 -> V_26 [ V_15 ] . V_89 = V_96 ;
V_14 -> V_26 [ V_15 ] . V_97 = V_89 ;
V_14 -> V_26 [ V_15 ] . V_98 = V_90 ;
V_14 -> V_26 [ V_15 ] . V_91 = V_91 ;
V_14 -> V_26 [ V_15 ] . V_27 = 1 ;
V_14 -> V_26 [ V_15 ] . V_93 = F_37 ( V_14 -> V_26 [ V_15 ] . V_93 ) ;
* V_92 = V_15 ;
* V_93 = V_14 -> V_26 [ V_15 ] . V_93 ;
V_14 -> V_95 = ( V_15 + 1 ) % V_25 ;
} else {
V_94 = - V_99 ;
}
return V_94 ;
}
static int F_38 ( T_1 V_14 ,
unsigned char V_92 ,
short V_54 ,
unsigned char V_100 ,
unsigned char V_86 ,
struct V_1 * V_2 ,
struct V_9 * * V_28 )
{
int V_94 = - V_101 ;
unsigned long V_102 ;
if ( V_92 >= V_25 )
return - V_71 ;
F_39 ( & ( V_14 -> V_103 ) , V_102 ) ;
if ( V_14 -> V_26 [ V_92 ] . V_27 ) {
struct V_9 * V_10 = V_14 -> V_26 [ V_92 ] . V_28 ;
if ( ( V_10 -> V_2 . V_54 == V_54 ) && ( V_10 -> V_10 . V_100 == V_100 )
&& ( V_10 -> V_10 . V_86 == V_86 )
&& ( F_30 ( V_2 , & ( V_10 -> V_2 ) ) ) ) {
* V_28 = V_10 ;
V_14 -> V_26 [ V_92 ] . V_27 = 0 ;
V_94 = 0 ;
}
}
F_40 ( & ( V_14 -> V_103 ) , V_102 ) ;
return V_94 ;
}
static int F_41 ( T_1 V_14 ,
long V_104 )
{
int V_94 = - V_101 ;
unsigned long V_102 ;
unsigned char V_92 ;
unsigned long V_93 ;
F_42 ( V_104 , V_92 , V_93 ) ;
F_39 ( & ( V_14 -> V_103 ) , V_102 ) ;
if ( ( V_14 -> V_26 [ V_92 ] . V_27 )
&& ( V_14 -> V_26 [ V_92 ] . V_93 == V_93 ) ) {
struct V_26 * V_105 = & ( V_14 -> V_26 [ V_92 ] ) ;
V_105 -> V_89 = V_105 -> V_97 ;
V_94 = 0 ;
}
F_40 ( & ( V_14 -> V_103 ) , V_102 ) ;
return V_94 ;
}
static int F_43 ( T_1 V_14 ,
long V_104 ,
unsigned int V_82 )
{
int V_94 = - V_101 ;
unsigned long V_102 ;
unsigned char V_92 ;
unsigned long V_93 ;
struct V_9 * V_10 = NULL ;
F_42 ( V_104 , V_92 , V_93 ) ;
F_39 ( & ( V_14 -> V_103 ) , V_102 ) ;
if ( ( V_14 -> V_26 [ V_92 ] . V_27 )
&& ( V_14 -> V_26 [ V_92 ] . V_93 == V_93 ) ) {
struct V_26 * V_105 = & ( V_14 -> V_26 [ V_92 ] ) ;
V_105 -> V_27 = 0 ;
V_10 = V_105 -> V_28 ;
V_94 = 0 ;
}
F_40 ( & ( V_14 -> V_103 ) , V_102 ) ;
if ( V_10 )
F_35 ( V_10 , V_82 ) ;
return V_94 ;
}
int F_44 ( unsigned int V_106 ,
struct V_107 * V_79 ,
void * V_81 ,
T_2 * V_74 )
{
unsigned long V_102 ;
T_2 V_108 ;
int V_94 = 0 ;
T_1 V_14 ;
if ( V_79 == NULL )
return - V_71 ;
if ( ! V_109 ) {
V_94 = F_45 () ;
if ( V_94 )
return V_94 ;
if ( ! V_109 )
return - V_101 ;
}
V_108 = F_21 ( sizeof( * V_108 ) , V_42 ) ;
if ( ! V_108 )
return - V_47 ;
F_11 ( & V_40 ) ;
F_46 (intf, &ipmi_interfaces, link) {
if ( V_14 -> V_41 == V_106 )
goto V_110;
}
V_94 = - V_71 ;
goto V_111;
V_110:
F_22 ( & V_14 -> V_32 ) ;
F_47 ( & V_108 -> V_32 ) ;
V_108 -> V_79 = V_79 ;
V_108 -> V_81 = V_81 ;
V_108 -> V_14 = V_14 ;
V_108 -> V_112 = 0 ;
if ( ! F_28 ( V_14 -> V_113 -> V_51 ) ) {
V_94 = - V_101 ;
goto V_114;
}
if ( V_14 -> V_113 -> V_115 ) {
V_94 = V_14 -> V_113 -> V_115 ( V_14 -> V_116 ) ;
if ( V_94 ) {
F_29 ( V_14 -> V_113 -> V_51 ) ;
goto V_114;
}
}
F_14 ( & V_40 ) ;
V_108 -> V_117 = 1 ;
F_39 ( & V_14 -> V_103 , V_102 ) ;
F_48 ( & V_108 -> V_12 , & V_14 -> V_118 ) ;
F_40 ( & V_14 -> V_103 , V_102 ) ;
* V_74 = V_108 ;
return 0 ;
V_114:
F_25 ( & V_14 -> V_32 , F_16 ) ;
V_111:
F_14 ( & V_40 ) ;
F_15 ( V_108 ) ;
return V_94 ;
}
int F_49 ( int V_106 , struct V_119 * V_88 )
{
int V_94 = 0 ;
T_1 V_14 ;
struct V_120 * V_113 ;
F_11 ( & V_40 ) ;
F_46 (intf, &ipmi_interfaces, link) {
if ( V_14 -> V_41 == V_106 )
goto V_110;
}
V_94 = - V_71 ;
F_14 ( & V_40 ) ;
return V_94 ;
V_110:
V_113 = V_14 -> V_113 ;
V_94 = - V_121 ;
if ( V_113 -> V_122 )
V_94 = V_113 -> V_122 ( V_14 -> V_116 , V_88 ) ;
F_14 ( & V_40 ) ;
return V_94 ;
}
static void F_50 ( struct V_29 * V_30 )
{
T_2 V_74 = F_17 ( V_30 , struct V_123 , V_32 ) ;
F_15 ( V_74 ) ;
}
int F_51 ( T_2 V_74 )
{
T_1 V_14 = V_74 -> V_14 ;
int V_15 ;
unsigned long V_102 ;
struct V_16 * V_17 ;
struct V_16 * V_124 = NULL ;
V_74 -> V_117 = 0 ;
F_39 ( & V_14 -> V_103 , V_102 ) ;
F_52 ( & V_74 -> V_12 ) ;
for ( V_15 = 0 ; V_15 < V_25 ; V_15 ++ ) {
if ( V_14 -> V_26 [ V_15 ] . V_27
&& ( V_14 -> V_26 [ V_15 ] . V_28 -> V_74 == V_74 ) ) {
V_14 -> V_26 [ V_15 ] . V_27 = 0 ;
F_7 ( V_14 -> V_26 [ V_15 ] . V_28 ) ;
}
}
F_40 ( & V_14 -> V_103 , V_102 ) ;
F_11 ( & V_14 -> V_22 ) ;
F_46 (rcvr, &intf->cmd_rcvrs, link) {
if ( V_17 -> V_74 == V_74 ) {
F_52 ( & V_17 -> V_12 ) ;
V_17 -> V_125 = V_124 ;
V_124 = V_17 ;
}
}
F_14 ( & V_14 -> V_22 ) ;
V_24 () ;
while ( V_124 ) {
V_17 = V_124 ;
V_124 = V_17 -> V_125 ;
F_15 ( V_17 ) ;
}
F_11 ( & V_40 ) ;
if ( V_14 -> V_113 ) {
F_29 ( V_14 -> V_113 -> V_51 ) ;
if ( V_14 -> V_113 -> V_126 )
V_14 -> V_113 -> V_126 ( V_14 -> V_116 ) ;
}
F_14 ( & V_40 ) ;
F_25 ( & V_14 -> V_32 , F_16 ) ;
F_25 ( & V_74 -> V_32 , F_50 ) ;
return 0 ;
}
void F_53 ( T_2 V_74 ,
unsigned char * V_127 ,
unsigned char * V_128 )
{
* V_127 = V_74 -> V_14 -> V_129 ;
* V_128 = V_74 -> V_14 -> V_130 ;
}
int F_54 ( T_2 V_74 ,
unsigned int V_54 ,
unsigned char V_131 )
{
if ( V_54 >= V_73 )
return - V_71 ;
V_74 -> V_14 -> V_132 [ V_54 ] . V_131 = V_131 ;
return 0 ;
}
int F_55 ( T_2 V_74 ,
unsigned int V_54 ,
unsigned char * V_131 )
{
if ( V_54 >= V_73 )
return - V_71 ;
* V_131 = V_74 -> V_14 -> V_132 [ V_54 ] . V_131 ;
return 0 ;
}
int F_56 ( T_2 V_74 ,
unsigned int V_54 ,
unsigned char V_133 )
{
if ( V_54 >= V_73 )
return - V_71 ;
V_74 -> V_14 -> V_132 [ V_54 ] . V_59 = V_133 & 0x3 ;
return 0 ;
}
int F_57 ( T_2 V_74 ,
unsigned int V_54 ,
unsigned char * V_131 )
{
if ( V_54 >= V_73 )
return - V_71 ;
* V_131 = V_74 -> V_14 -> V_132 [ V_54 ] . V_59 ;
return 0 ;
}
int F_58 ( T_2 V_74 )
{
int V_134 ;
unsigned long V_102 ;
F_39 ( & V_74 -> V_14 -> V_135 , V_102 ) ;
V_134 = V_74 -> V_14 -> V_136 ;
F_40 ( & V_74 -> V_14 -> V_135 , V_102 ) ;
return V_134 ;
}
static void F_59 ( T_1 V_14 )
{
if ( V_14 -> V_113 -> V_137 )
V_14 -> V_113 -> V_137 (
V_14 -> V_116 , V_14 -> V_138 ) ;
}
int F_60 ( T_2 V_74 , int V_134 )
{
int V_94 = 0 ;
unsigned long V_102 ;
T_1 V_14 = V_74 -> V_14 ;
F_39 ( & V_14 -> V_135 , V_102 ) ;
if ( V_14 -> V_136 != V_134 ) {
switch ( V_134 ) {
case V_139 :
V_14 -> V_136 = V_134 ;
V_14 -> V_138
= ( V_14 -> V_140 > 0 ) ;
break;
case V_141 :
V_14 -> V_136 = V_134 ;
V_14 -> V_138 = 0 ;
break;
case V_142 :
V_14 -> V_136 = V_134 ;
V_14 -> V_138 = 1 ;
break;
default:
V_94 = - V_71 ;
goto V_143;
}
F_59 ( V_14 ) ;
}
V_143:
F_40 ( & V_14 -> V_135 , V_102 ) ;
return V_94 ;
}
int F_61 ( T_2 V_74 , int V_144 )
{
unsigned long V_102 ;
T_1 V_14 = V_74 -> V_14 ;
struct V_9 * V_10 , * V_11 ;
struct V_7 V_145 ;
F_12 ( & V_145 ) ;
F_39 ( & V_14 -> V_146 , V_102 ) ;
V_74 -> V_112 = V_144 ;
if ( V_14 -> V_147 )
goto V_148;
while ( V_74 -> V_112 && ! F_62 ( & V_14 -> V_21 ) ) {
F_5 (msg, msg2, &intf->waiting_events, link)
F_63 ( & V_10 -> V_12 , & V_145 ) ;
V_14 -> V_149 = 0 ;
if ( V_14 -> V_150 ) {
F_64 (KERN_WARNING PFX L_1
L_2 ) ;
V_14 -> V_150 = 0 ;
}
V_14 -> V_147 = 1 ;
F_40 ( & V_14 -> V_146 , V_102 ) ;
F_5 (msg, msg2, &msgs, link) {
V_10 -> V_74 = V_74 ;
F_22 ( & V_74 -> V_32 ) ;
F_33 ( V_10 ) ;
}
F_39 ( & V_14 -> V_146 , V_102 ) ;
V_14 -> V_147 = 0 ;
}
V_148:
F_40 ( & V_14 -> V_146 , V_102 ) ;
return 0 ;
}
static struct V_16 * F_65 ( T_1 V_14 ,
unsigned char V_86 ,
unsigned char V_100 ,
unsigned char V_151 )
{
struct V_16 * V_17 ;
F_46 (rcvr, &intf->cmd_rcvrs, link) {
if ( ( V_17 -> V_86 == V_86 ) && ( V_17 -> V_100 == V_100 )
&& ( V_17 -> V_152 & ( 1 << V_151 ) ) )
return V_17 ;
}
return NULL ;
}
static int F_66 ( T_1 V_14 ,
unsigned char V_86 ,
unsigned char V_100 ,
unsigned int V_152 )
{
struct V_16 * V_17 ;
F_46 (rcvr, &intf->cmd_rcvrs, link) {
if ( ( V_17 -> V_86 == V_86 ) && ( V_17 -> V_100 == V_100 )
&& ( V_17 -> V_152 & V_152 ) )
return 0 ;
}
return 1 ;
}
int F_67 ( T_2 V_74 ,
unsigned char V_86 ,
unsigned char V_100 ,
unsigned int V_152 )
{
T_1 V_14 = V_74 -> V_14 ;
struct V_16 * V_17 ;
int V_94 = 0 ;
V_17 = F_21 ( sizeof( * V_17 ) , V_42 ) ;
if ( ! V_17 )
return - V_47 ;
V_17 -> V_100 = V_100 ;
V_17 -> V_86 = V_86 ;
V_17 -> V_152 = V_152 ;
V_17 -> V_74 = V_74 ;
F_11 ( & V_14 -> V_22 ) ;
if ( ! F_66 ( V_14 , V_86 , V_100 , V_152 ) ) {
V_94 = - V_153 ;
goto V_143;
}
F_48 ( & V_17 -> V_12 , & V_14 -> V_23 ) ;
V_143:
F_14 ( & V_14 -> V_22 ) ;
if ( V_94 )
F_15 ( V_17 ) ;
return V_94 ;
}
int F_68 ( T_2 V_74 ,
unsigned char V_86 ,
unsigned char V_100 ,
unsigned int V_152 )
{
T_1 V_14 = V_74 -> V_14 ;
struct V_16 * V_17 ;
struct V_16 * V_124 = NULL ;
int V_15 , V_94 = - V_154 ;
F_11 ( & V_14 -> V_22 ) ;
for ( V_15 = 0 ; V_15 < V_155 ; V_15 ++ ) {
if ( ( ( 1 << V_15 ) & V_152 ) == 0 )
continue;
V_17 = F_65 ( V_14 , V_86 , V_100 , V_15 ) ;
if ( V_17 == NULL )
continue;
if ( V_17 -> V_74 == V_74 ) {
V_94 = 0 ;
V_17 -> V_152 &= ~ V_152 ;
if ( V_17 -> V_152 == 0 ) {
F_52 ( & V_17 -> V_12 ) ;
V_17 -> V_125 = V_124 ;
V_124 = V_17 ;
}
}
}
F_14 ( & V_14 -> V_22 ) ;
V_24 () ;
while ( V_124 ) {
V_17 = V_124 ;
V_124 = V_17 -> V_125 ;
F_15 ( V_17 ) ;
}
return V_94 ;
}
static unsigned char
F_69 ( unsigned char * V_88 , int V_156 )
{
unsigned char V_157 = 0 ;
for (; V_156 > 0 ; V_156 -- , V_88 ++ )
V_157 += * V_88 ;
return - V_157 ;
}
static inline void F_70 ( struct V_13 * V_158 ,
struct V_159 * V_10 ,
struct V_60 * V_160 ,
long V_104 ,
unsigned char V_161 ,
int V_91 ,
unsigned char V_162 ,
unsigned char V_163 )
{
int V_15 = V_91 ;
V_158 -> V_88 [ 0 ] = ( V_164 << 2 ) ;
V_158 -> V_88 [ 1 ] = V_165 ;
V_158 -> V_88 [ 2 ] = V_160 -> V_54 ;
if ( V_91 )
V_158 -> V_88 [ 3 ] = 0 ;
V_158 -> V_88 [ V_15 + 3 ] = V_160 -> V_63 ;
V_158 -> V_88 [ V_15 + 4 ] = ( V_10 -> V_86 << 2 ) | ( V_160 -> V_59 & 0x3 ) ;
V_158 -> V_88 [ V_15 + 5 ] = F_69 ( & ( V_158 -> V_88 [ V_15 + 3 ] ) , 2 ) ;
V_158 -> V_88 [ V_15 + 6 ] = V_162 ;
V_158 -> V_88 [ V_15 + 7 ] = ( V_161 << 2 ) | V_163 ;
V_158 -> V_88 [ V_15 + 8 ] = V_10 -> V_100 ;
if ( V_10 -> V_87 > 0 )
memcpy ( & ( V_158 -> V_88 [ V_15 + 9 ] ) , V_10 -> V_88 ,
V_10 -> V_87 ) ;
V_158 -> V_166 = V_10 -> V_87 + 9 ;
V_158 -> V_88 [ V_15 + V_158 -> V_166 ]
= F_69 ( & ( V_158 -> V_88 [ V_15 + 6 ] ) ,
V_158 -> V_166 - 6 ) ;
V_158 -> V_166 += 1 + V_15 ;
V_158 -> V_104 = V_104 ;
}
static inline void F_71 ( struct V_13 * V_158 ,
struct V_159 * V_10 ,
struct V_64 * V_167 ,
long V_104 ,
unsigned char V_161 ,
unsigned char V_163 )
{
V_158 -> V_88 [ 0 ] = ( V_164 << 2 ) ;
V_158 -> V_88 [ 1 ] = V_165 ;
V_158 -> V_88 [ 2 ] = V_167 -> V_54 ;
V_158 -> V_88 [ 3 ] = V_167 -> V_69 ;
V_158 -> V_88 [ 4 ] = V_167 -> V_67 ;
V_158 -> V_88 [ 5 ] = ( V_10 -> V_86 << 2 ) | ( V_167 -> V_59 & 0x3 ) ;
V_158 -> V_88 [ 6 ] = F_69 ( & ( V_158 -> V_88 [ 4 ] ) , 2 ) ;
V_158 -> V_88 [ 7 ] = V_167 -> V_68 ;
V_158 -> V_88 [ 8 ] = ( V_161 << 2 ) | V_163 ;
V_158 -> V_88 [ 9 ] = V_10 -> V_100 ;
if ( V_10 -> V_87 > 0 )
memcpy ( & ( V_158 -> V_88 [ 10 ] ) , V_10 -> V_88 ,
V_10 -> V_87 ) ;
V_158 -> V_166 = V_10 -> V_87 + 10 ;
V_158 -> V_88 [ V_158 -> V_166 ]
= F_69 ( & ( V_158 -> V_88 [ 7 ] ) ,
V_158 -> V_166 - 7 ) ;
V_158 -> V_166 += 1 ;
V_158 -> V_104 = V_104 ;
}
static int F_72 ( T_2 V_74 ,
T_1 V_14 ,
struct V_1 * V_2 ,
long V_104 ,
struct V_159 * V_10 ,
void * V_75 ,
void * V_168 ,
struct V_9 * V_169 ,
int V_170 ,
unsigned char V_162 ,
unsigned char V_163 ,
int V_90 ,
unsigned int V_171 )
{
int V_94 = 0 ;
struct V_13 * V_158 ;
struct V_9 * V_28 ;
unsigned long V_102 ;
struct V_120 * V_113 ;
if ( V_169 )
V_28 = V_169 ;
else {
V_28 = F_73 () ;
if ( V_28 == NULL )
return - V_47 ;
}
V_28 -> V_75 = V_75 ;
if ( V_168 )
V_158 = (struct V_13 * ) V_168 ;
else {
V_158 = F_74 () ;
if ( V_158 == NULL ) {
F_7 ( V_28 ) ;
return - V_47 ;
}
}
F_75 () ;
V_113 = V_14 -> V_113 ;
if ( ! V_113 ) {
V_94 = - V_101 ;
goto V_43;
}
V_28 -> V_74 = V_74 ;
if ( V_74 )
F_22 ( & V_74 -> V_32 ) ;
V_28 -> V_104 = V_104 ;
V_28 -> V_10 = * V_10 ;
if ( V_2 -> V_3 == V_55 ) {
struct V_56 * V_172 ;
if ( V_10 -> V_86 & 1 ) {
V_94 = - V_71 ;
goto V_43;
}
V_172 = (struct V_56 * ) V_2 ;
if ( V_172 -> V_59 > 3 ) {
F_34 ( V_14 , V_173 ) ;
V_94 = - V_71 ;
goto V_43;
}
memcpy ( & V_28 -> V_2 , V_172 , sizeof( * V_172 ) ) ;
if ( ( V_10 -> V_86 == V_164 )
&& ( ( V_10 -> V_100 == V_165 )
|| ( V_10 -> V_100 == V_174 )
|| ( V_10 -> V_100 == V_175 ) ) ) {
F_34 ( V_14 , V_173 ) ;
V_94 = - V_71 ;
goto V_43;
}
if ( ( ( V_10 -> V_86 == V_164 )
&& ( ( V_10 -> V_100 == V_176 )
|| ( V_10 -> V_100 == V_177 ) ) )
|| ( V_10 -> V_86 == V_178 ) ) {
F_39 ( & V_14 -> V_135 , V_102 ) ;
V_14 -> V_140
= V_179 ;
if ( ! V_14 -> V_136
&& ! V_14 -> V_138 ) {
V_14 -> V_138 = 1 ;
F_59 ( V_14 ) ;
}
F_40 ( & V_14 -> V_135 ,
V_102 ) ;
}
if ( ( V_10 -> V_87 + 2 ) > V_180 ) {
F_34 ( V_14 , V_173 ) ;
V_94 = - V_181 ;
goto V_43;
}
V_158 -> V_88 [ 0 ] = ( V_10 -> V_86 << 2 ) | ( V_172 -> V_59 & 0x3 ) ;
V_158 -> V_88 [ 1 ] = V_10 -> V_100 ;
V_158 -> V_104 = V_104 ;
V_158 -> V_182 = V_28 ;
if ( V_10 -> V_87 > 0 )
memcpy ( & ( V_158 -> V_88 [ 2 ] ) , V_10 -> V_88 , V_10 -> V_87 ) ;
V_158 -> V_166 = V_10 -> V_87 + 2 ;
F_34 ( V_14 , V_183 ) ;
} else if ( F_2 ( V_2 ) || F_3 ( V_2 ) ) {
struct V_60 * V_160 ;
unsigned char V_161 ;
long V_93 ;
int V_91 = 0 ;
if ( V_2 -> V_54 >= V_73 ) {
F_34 ( V_14 , V_173 ) ;
V_94 = - V_71 ;
goto V_43;
}
if ( V_14 -> V_132 [ V_2 -> V_54 ] . V_184
!= V_185 ) {
F_34 ( V_14 , V_173 ) ;
V_94 = - V_71 ;
goto V_43;
}
if ( V_90 < 0 ) {
if ( V_2 -> V_3 == V_6 )
V_90 = 0 ;
else
V_90 = 4 ;
}
if ( V_2 -> V_3 == V_6 ) {
V_2 -> V_3 = V_5 ;
V_91 = 1 ;
}
if ( V_171 == 0 )
V_171 = 1000 ;
if ( ( V_10 -> V_87 + 10 + V_91 ) > V_180 ) {
F_34 ( V_14 , V_173 ) ;
V_94 = - V_181 ;
goto V_43;
}
V_160 = (struct V_60 * ) V_2 ;
if ( V_160 -> V_59 > 3 ) {
F_34 ( V_14 , V_173 ) ;
V_94 = - V_71 ;
goto V_43;
}
memcpy ( & V_28 -> V_2 , V_160 , sizeof( * V_160 ) ) ;
if ( V_28 -> V_10 . V_86 & 0x1 ) {
F_34 ( V_14 , V_186 ) ;
F_70 ( V_158 , V_10 , V_160 , V_104 ,
V_104 , V_91 ,
V_162 , V_163 ) ;
V_158 -> V_182 = V_28 ;
} else {
F_39 ( & ( V_14 -> V_103 ) , V_102 ) ;
V_94 = F_36 ( V_14 ,
V_28 ,
V_171 ,
V_90 ,
V_91 ,
& V_161 ,
& V_93 ) ;
if ( V_94 ) {
F_40 ( & ( V_14 -> V_103 ) ,
V_102 ) ;
goto V_43;
}
F_34 ( V_14 , V_187 ) ;
F_70 ( V_158 , V_10 , V_160 ,
F_76 ( V_161 , V_93 ) ,
V_161 , V_91 ,
V_162 , V_163 ) ;
memcpy ( V_28 -> V_85 , V_158 -> V_88 ,
V_158 -> V_166 ) ;
V_28 -> V_10 . V_88 = V_28 -> V_85 ;
V_28 -> V_10 . V_87 = V_158 -> V_166 ;
F_40 ( & ( V_14 -> V_103 ) , V_102 ) ;
}
} else if ( F_1 ( V_2 ) ) {
struct V_64 * V_167 ;
unsigned char V_161 ;
long V_93 ;
if ( V_2 -> V_54 >= V_73 ) {
F_34 ( V_14 , V_173 ) ;
V_94 = - V_71 ;
goto V_43;
}
if ( ( V_14 -> V_132 [ V_2 -> V_54 ] . V_184
!= V_188 )
&& ( V_14 -> V_132 [ V_2 -> V_54 ] . V_184
!= V_189 ) ) {
F_34 ( V_14 , V_173 ) ;
V_94 = - V_71 ;
goto V_43;
}
V_90 = 4 ;
if ( V_171 == 0 )
V_171 = 1000 ;
if ( ( V_10 -> V_87 + 12 ) > V_180 ) {
F_34 ( V_14 , V_173 ) ;
V_94 = - V_181 ;
goto V_43;
}
V_167 = (struct V_64 * ) V_2 ;
if ( V_167 -> V_59 > 3 ) {
F_34 ( V_14 , V_173 ) ;
V_94 = - V_71 ;
goto V_43;
}
memcpy ( & V_28 -> V_2 , V_167 , sizeof( * V_167 ) ) ;
if ( V_28 -> V_10 . V_86 & 0x1 ) {
F_34 ( V_14 , V_190 ) ;
F_71 ( V_158 , V_10 , V_167 , V_104 ,
V_104 , V_163 ) ;
V_158 -> V_182 = V_28 ;
} else {
F_39 ( & ( V_14 -> V_103 ) , V_102 ) ;
V_94 = F_36 ( V_14 ,
V_28 ,
V_171 ,
V_90 ,
0 ,
& V_161 ,
& V_93 ) ;
if ( V_94 ) {
F_40 ( & ( V_14 -> V_103 ) ,
V_102 ) ;
goto V_43;
}
F_34 ( V_14 , V_191 ) ;
F_71 ( V_158 , V_10 , V_167 ,
F_76 ( V_161 , V_93 ) ,
V_161 , V_163 ) ;
memcpy ( V_28 -> V_85 , V_158 -> V_88 ,
V_158 -> V_166 ) ;
V_28 -> V_10 . V_88 = V_28 -> V_85 ;
V_28 -> V_10 . V_87 = V_158 -> V_166 ;
F_40 ( & ( V_14 -> V_103 ) , V_102 ) ;
}
} else {
F_34 ( V_14 , V_173 ) ;
V_94 = - V_71 ;
goto V_43;
}
#ifdef F_77
{
int V_192 ;
for ( V_192 = 0 ; V_192 < V_158 -> V_166 ; V_192 ++ )
F_64 ( L_3 , V_158 -> V_88 [ V_192 ] ) ;
F_64 ( L_4 ) ;
}
#endif
V_113 -> V_193 ( V_14 -> V_116 , V_158 , V_170 ) ;
F_78 () ;
return 0 ;
V_43:
F_78 () ;
F_9 ( V_158 ) ;
F_7 ( V_28 ) ;
return V_94 ;
}
static int F_79 ( T_1 V_14 ,
struct V_1 * V_2 ,
unsigned char * V_194 ,
unsigned char * V_59 )
{
if ( V_2 -> V_54 >= V_73 )
return - V_71 ;
* V_59 = V_14 -> V_132 [ V_2 -> V_54 ] . V_59 ;
* V_194 = V_14 -> V_132 [ V_2 -> V_54 ] . V_131 ;
return 0 ;
}
int F_80 ( T_2 V_74 ,
struct V_1 * V_2 ,
long V_104 ,
struct V_159 * V_10 ,
void * V_75 ,
int V_170 ,
int V_90 ,
unsigned int V_171 )
{
unsigned char V_194 , V_59 ;
int V_94 ;
if ( ! V_74 )
return - V_71 ;
V_94 = F_79 ( V_74 -> V_14 , V_2 , & V_194 , & V_59 ) ;
if ( V_94 )
return V_94 ;
return F_72 ( V_74 ,
V_74 -> V_14 ,
V_2 ,
V_104 ,
V_10 ,
V_75 ,
NULL , NULL ,
V_170 ,
V_194 ,
V_59 ,
V_90 ,
V_171 ) ;
}
int F_81 ( T_2 V_74 ,
struct V_1 * V_2 ,
long V_104 ,
struct V_159 * V_10 ,
void * V_75 ,
void * V_168 ,
struct V_9 * V_169 ,
int V_170 )
{
unsigned char V_194 , V_59 ;
int V_94 ;
if ( ! V_74 )
return - V_71 ;
V_94 = F_79 ( V_74 -> V_14 , V_2 , & V_194 , & V_59 ) ;
if ( V_94 )
return V_94 ;
return F_72 ( V_74 ,
V_74 -> V_14 ,
V_2 ,
V_104 ,
V_10 ,
V_75 ,
V_168 ,
V_169 ,
V_170 ,
V_194 ,
V_59 ,
- 1 , 0 ) ;
}
static int F_82 ( struct V_195 * V_192 , void * V_196 )
{
T_1 V_14 = V_192 -> V_197 ;
int V_15 ;
F_83 ( V_192 , L_5 , V_14 -> V_132 [ 0 ] . V_131 ) ;
for ( V_15 = 1 ; V_15 < V_73 ; V_15 ++ )
F_83 ( V_192 , L_6 , V_14 -> V_132 [ V_15 ] . V_131 ) ;
return F_84 ( V_192 , '\n' ) ;
}
static int F_85 ( struct V_198 * V_198 , struct V_199 * V_199 )
{
return F_86 ( V_199 , F_82 , F_87 ( V_198 ) -> V_88 ) ;
}
static int F_88 ( struct V_195 * V_192 , void * V_196 )
{
T_1 V_14 = V_192 -> V_197 ;
return F_83 ( V_192 , L_7 ,
V_129 ( & V_14 -> V_200 -> V_201 ) ,
V_130 ( & V_14 -> V_200 -> V_201 ) ) ;
}
static int F_89 ( struct V_198 * V_198 , struct V_199 * V_199 )
{
return F_86 ( V_199 , F_88 , F_87 ( V_198 ) -> V_88 ) ;
}
static int F_90 ( struct V_195 * V_192 , void * V_196 )
{
T_1 V_14 = V_192 -> V_197 ;
F_83 ( V_192 , L_8 ,
F_91 ( V_14 , V_173 ) ) ;
F_83 ( V_192 , L_9 ,
F_91 ( V_14 , V_183 ) ) ;
F_83 ( V_192 , L_10 ,
F_91 ( V_14 , V_77 ) ) ;
F_83 ( V_192 , L_11 ,
F_91 ( V_14 , V_78 ) ) ;
F_83 ( V_192 , L_12 ,
F_91 ( V_14 , V_187 ) ) ;
F_83 ( V_192 , L_13 ,
F_91 ( V_14 , V_202 ) ) ;
F_83 ( V_192 , L_14 ,
F_91 ( V_14 , V_203 ) ) ;
F_83 ( V_192 , L_15 ,
F_91 ( V_14 , V_204 ) ) ;
F_83 ( V_192 , L_16 ,
F_91 ( V_14 , V_205 ) ) ;
F_83 ( V_192 , L_17 ,
F_91 ( V_14 , V_186 ) ) ;
F_83 ( V_192 , L_18 ,
F_91 ( V_14 , V_206 ) ) ;
F_83 ( V_192 , L_19 ,
F_91 ( V_14 , V_207 ) ) ;
F_83 ( V_192 , L_20 ,
F_91 ( V_14 , V_208 ) ) ;
F_83 ( V_192 , L_21 ,
F_91 ( V_14 , V_191 ) ) ;
F_83 ( V_192 , L_22 ,
F_91 ( V_14 , V_209 ) ) ;
F_83 ( V_192 , L_23 ,
F_91 ( V_14 , V_210 ) ) ;
F_83 ( V_192 , L_24 ,
F_91 ( V_14 , V_211 ) ) ;
F_83 ( V_192 , L_25 ,
F_91 ( V_14 , V_190 ) ) ;
F_83 ( V_192 , L_26 ,
F_91 ( V_14 , V_212 ) ) ;
F_83 ( V_192 , L_27 ,
F_91 ( V_14 , V_213 ) ) ;
F_83 ( V_192 , L_28 ,
F_91 ( V_14 , V_214 ) ) ;
F_83 ( V_192 , L_29 ,
F_91 ( V_14 , V_215 ) ) ;
F_83 ( V_192 , L_30 ,
F_91 ( V_14 , V_216 ) ) ;
F_83 ( V_192 , L_31 ,
F_91 ( V_14 , V_217 ) ) ;
F_83 ( V_192 , L_32 ,
F_91 ( V_14 , V_218 ) ) ;
F_83 ( V_192 , L_33 ,
F_91 ( V_14 , V_219 ) ) ;
F_83 ( V_192 , L_34 ,
F_91 ( V_14 , V_220 ) ) ;
F_83 ( V_192 , L_35 ,
F_91 ( V_14 , V_221 ) ) ;
return 0 ;
}
static int F_92 ( struct V_198 * V_198 , struct V_199 * V_199 )
{
return F_86 ( V_199 , F_90 , F_87 ( V_198 ) -> V_88 ) ;
}
int F_93 ( T_1 V_222 , char * V_223 ,
const struct V_224 * V_225 ,
void * V_88 )
{
int V_94 = 0 ;
#ifdef F_94
struct V_226 * V_199 ;
struct V_227 * V_228 ;
V_228 = F_21 ( sizeof( * V_228 ) , V_42 ) ;
if ( ! V_228 )
return - V_47 ;
V_228 -> V_223 = F_21 ( strlen ( V_223 ) + 1 , V_42 ) ;
if ( ! V_228 -> V_223 ) {
F_15 ( V_228 ) ;
return - V_47 ;
}
strcpy ( V_228 -> V_223 , V_223 ) ;
V_199 = F_95 ( V_223 , 0 , V_222 -> V_229 , V_225 , V_88 ) ;
if ( ! V_199 ) {
F_15 ( V_228 -> V_223 ) ;
F_15 ( V_228 ) ;
V_94 = - V_47 ;
} else {
F_11 ( & V_222 -> V_230 ) ;
V_228 -> V_125 = V_222 -> V_231 ;
V_222 -> V_231 = V_228 ;
F_14 ( & V_222 -> V_230 ) ;
}
#endif
return V_94 ;
}
static int F_96 ( T_1 V_222 , int V_232 )
{
int V_94 = 0 ;
#ifdef F_94
sprintf ( V_222 -> V_233 , L_36 , V_232 ) ;
V_222 -> V_229 = F_97 ( V_222 -> V_233 , V_234 ) ;
if ( ! V_222 -> V_229 )
V_94 = - V_47 ;
if ( V_94 == 0 )
V_94 = F_93 ( V_222 , L_37 ,
& V_235 ,
V_222 ) ;
if ( V_94 == 0 )
V_94 = F_93 ( V_222 , L_38 ,
& V_236 ,
V_222 ) ;
if ( V_94 == 0 )
V_94 = F_93 ( V_222 , L_39 ,
& V_237 ,
V_222 ) ;
#endif
return V_94 ;
}
static void F_98 ( T_1 V_222 )
{
#ifdef F_94
struct V_227 * V_228 ;
F_11 ( & V_222 -> V_230 ) ;
while ( V_222 -> V_231 ) {
V_228 = V_222 -> V_231 ;
V_222 -> V_231 = V_228 -> V_125 ;
F_99 ( V_228 -> V_223 , V_222 -> V_229 ) ;
F_15 ( V_228 -> V_223 ) ;
F_15 ( V_228 ) ;
}
F_14 ( & V_222 -> V_230 ) ;
F_99 ( V_222 -> V_233 , V_234 ) ;
#endif
}
static int F_100 ( struct V_48 * V_49 , void * V_88 )
{
unsigned char * V_201 = V_88 ;
struct V_238 * V_200 = F_101 ( V_49 ) ;
return memcmp ( V_200 -> V_239 , V_201 , 16 ) == 0 ;
}
static struct V_238 * F_102 ( struct V_240 * V_241 ,
unsigned char * V_239 )
{
struct V_48 * V_49 ;
V_49 = F_103 ( V_241 , NULL , V_239 , F_100 ) ;
if ( V_49 )
return F_101 ( V_49 ) ;
else
return NULL ;
}
static int F_104 ( struct V_48 * V_49 , void * V_88 )
{
struct V_242 * V_201 = V_88 ;
struct V_238 * V_200 = F_101 ( V_49 ) ;
return ( V_200 -> V_201 . V_243 == V_201 -> V_243
&& V_200 -> V_201 . V_244 == V_201 -> V_244 ) ;
}
static struct V_238 * F_105 (
struct V_240 * V_241 ,
unsigned int V_243 , unsigned char V_244 )
{
struct V_242 V_201 = {
. V_243 = V_243 ,
. V_244 = V_244 ,
} ;
struct V_48 * V_49 ;
V_49 = F_103 ( V_241 , NULL , & V_201 , F_104 ) ;
if ( V_49 )
return F_101 ( V_49 ) ;
else
return NULL ;
}
static T_3 F_106 ( struct V_48 * V_49 ,
struct V_245 * V_246 ,
char * V_247 )
{
struct V_238 * V_200 = F_101 ( V_49 ) ;
return snprintf ( V_247 , 10 , L_40 , V_200 -> V_201 . V_244 ) ;
}
static T_3 F_107 ( struct V_48 * V_49 ,
struct V_245 * V_246 ,
char * V_247 )
{
struct V_238 * V_200 = F_101 ( V_49 ) ;
return snprintf ( V_247 , 10 , L_40 ,
( V_200 -> V_201 . V_248 & 0x80 ) >> 7 ) ;
}
static T_3 F_108 ( struct V_48 * V_49 , struct V_245 * V_246 ,
char * V_247 )
{
struct V_238 * V_200 = F_101 ( V_49 ) ;
return snprintf ( V_247 , 20 , L_40 ,
V_200 -> V_201 . V_248 & 0x0F ) ;
}
static T_3 F_109 ( struct V_48 * V_49 ,
struct V_245 * V_246 ,
char * V_247 )
{
struct V_238 * V_200 = F_101 ( V_49 ) ;
return snprintf ( V_247 , 20 , L_41 , V_200 -> V_201 . V_249 ,
V_200 -> V_201 . V_250 ) ;
}
static T_3 F_110 ( struct V_48 * V_49 ,
struct V_245 * V_246 ,
char * V_247 )
{
struct V_238 * V_200 = F_101 ( V_49 ) ;
return snprintf ( V_247 , 20 , L_7 ,
V_129 ( & V_200 -> V_201 ) ,
V_130 ( & V_200 -> V_201 ) ) ;
}
static T_3 F_111 ( struct V_48 * V_49 ,
struct V_245 * V_246 ,
char * V_247 )
{
struct V_238 * V_200 = F_101 ( V_49 ) ;
return snprintf ( V_247 , 10 , L_42 ,
V_200 -> V_201 . V_251 ) ;
}
static T_3 F_112 ( struct V_48 * V_49 ,
struct V_245 * V_246 ,
char * V_247 )
{
struct V_238 * V_200 = F_101 ( V_49 ) ;
return snprintf ( V_247 , 20 , L_43 , V_200 -> V_201 . V_252 ) ;
}
static T_3 F_113 ( struct V_48 * V_49 ,
struct V_245 * V_246 ,
char * V_247 )
{
struct V_238 * V_200 = F_101 ( V_49 ) ;
return snprintf ( V_247 , 10 , L_44 , V_200 -> V_201 . V_243 ) ;
}
static T_3 F_114 ( struct V_48 * V_49 ,
struct V_245 * V_246 ,
char * V_247 )
{
struct V_238 * V_200 = F_101 ( V_49 ) ;
return snprintf ( V_247 , 21 , L_45 ,
V_200 -> V_201 . V_253 [ 3 ] ,
V_200 -> V_201 . V_253 [ 2 ] ,
V_200 -> V_201 . V_253 [ 1 ] ,
V_200 -> V_201 . V_253 [ 0 ] ) ;
}
static T_3 F_115 ( struct V_48 * V_49 , struct V_245 * V_246 ,
char * V_247 )
{
struct V_238 * V_200 = F_101 ( V_49 ) ;
return snprintf ( V_247 , 100 , L_46 ,
( long long ) V_200 -> V_239 [ 0 ] ,
( long long ) V_200 -> V_239 [ 8 ] ) ;
}
static void F_116 ( struct V_238 * V_200 )
{
if ( ! V_200 -> V_49 )
return;
F_117 ( & V_200 -> V_49 -> V_49 ,
& V_200 -> V_254 ) ;
F_117 ( & V_200 -> V_49 -> V_49 ,
& V_200 -> V_255 ) ;
F_117 ( & V_200 -> V_49 -> V_49 ,
& V_200 -> V_256 ) ;
F_117 ( & V_200 -> V_49 -> V_49 ,
& V_200 -> V_257 ) ;
F_117 ( & V_200 -> V_49 -> V_49 ,
& V_200 -> V_258 ) ;
F_117 ( & V_200 -> V_49 -> V_49 ,
& V_200 -> V_259 ) ;
F_117 ( & V_200 -> V_49 -> V_49 ,
& V_200 -> V_260 ) ;
F_117 ( & V_200 -> V_49 -> V_49 ,
& V_200 -> V_261 ) ;
if ( V_200 -> V_201 . V_262 )
F_117 ( & V_200 -> V_49 -> V_49 ,
& V_200 -> V_263 ) ;
if ( V_200 -> V_264 )
F_117 ( & V_200 -> V_49 -> V_49 ,
& V_200 -> V_265 ) ;
}
static void
F_118 ( struct V_29 * V_30 )
{
struct V_238 * V_200 ;
V_200 = F_17 ( V_30 , struct V_238 , V_32 ) ;
F_116 ( V_200 ) ;
F_119 ( V_200 -> V_49 ) ;
F_15 ( V_200 ) ;
}
static void F_120 ( T_1 V_14 )
{
struct V_238 * V_200 = V_14 -> V_200 ;
if ( V_14 -> V_266 ) {
F_121 ( & V_14 -> V_46 -> V_267 , V_14 -> V_266 ) ;
F_15 ( V_14 -> V_266 ) ;
V_14 -> V_266 = NULL ;
}
if ( V_14 -> V_268 ) {
F_121 ( & V_200 -> V_49 -> V_49 . V_267 , V_14 -> V_268 ) ;
F_15 ( V_14 -> V_268 ) ;
V_14 -> V_268 = NULL ;
}
F_11 ( & V_269 ) ;
F_25 ( & V_200 -> V_32 , F_118 ) ;
V_14 -> V_200 = NULL ;
F_14 ( & V_269 ) ;
}
static int F_122 ( struct V_238 * V_200 )
{
int V_82 ;
V_200 -> V_254 . V_246 . V_223 = L_47 ;
V_200 -> V_254 . V_246 . V_134 = V_270 ;
V_200 -> V_254 . V_271 = F_106 ;
F_123 ( & V_200 -> V_254 . V_246 ) ;
V_200 -> V_255 . V_246 . V_223 = L_48 ;
V_200 -> V_255 . V_246 . V_134 = V_270 ;
V_200 -> V_255 . V_271 = F_107 ;
F_123 ( & V_200 -> V_255 . V_246 ) ;
V_200 -> V_256 . V_246 . V_223 = L_49 ;
V_200 -> V_256 . V_246 . V_134 = V_270 ;
V_200 -> V_256 . V_271 = F_108 ;
F_123 ( & V_200 -> V_256 . V_246 ) ;
V_200 -> V_257 . V_246 . V_223 = L_50 ;
V_200 -> V_257 . V_246 . V_134 = V_270 ;
V_200 -> V_257 . V_271 = F_109 ;
F_123 ( & V_200 -> V_257 . V_246 ) ;
V_200 -> V_258 . V_246 . V_223 = L_51 ;
V_200 -> V_258 . V_246 . V_134 = V_270 ;
V_200 -> V_258 . V_271 = F_110 ;
F_123 ( & V_200 -> V_258 . V_246 ) ;
V_200 -> V_259 . V_246 . V_223 = L_52 ;
V_200 -> V_259 . V_246 . V_134 = V_270 ;
V_200 -> V_259 . V_271 = F_111 ;
F_123 ( & V_200 -> V_259 . V_246 ) ;
V_200 -> V_260 . V_246 . V_223 = L_53 ;
V_200 -> V_260 . V_246 . V_134 = V_270 ;
V_200 -> V_260 . V_271 = F_112 ;
F_123 ( & V_200 -> V_260 . V_246 ) ;
V_200 -> V_261 . V_246 . V_223 = L_54 ;
V_200 -> V_261 . V_246 . V_134 = V_270 ;
V_200 -> V_261 . V_271 = F_113 ;
F_123 ( & V_200 -> V_261 . V_246 ) ;
V_200 -> V_265 . V_246 . V_223 = L_55 ;
V_200 -> V_265 . V_246 . V_134 = V_270 ;
V_200 -> V_265 . V_271 = F_115 ;
F_123 ( & V_200 -> V_265 . V_246 ) ;
V_200 -> V_263 . V_246 . V_223 = L_56 ;
V_200 -> V_263 . V_246 . V_134 = V_270 ;
V_200 -> V_263 . V_271 = F_114 ;
F_123 ( & V_200 -> V_263 . V_246 ) ;
V_82 = F_124 ( & V_200 -> V_49 -> V_49 ,
& V_200 -> V_254 ) ;
if ( V_82 )
goto V_148;
V_82 = F_124 ( & V_200 -> V_49 -> V_49 ,
& V_200 -> V_255 ) ;
if ( V_82 )
goto V_272;
V_82 = F_124 ( & V_200 -> V_49 -> V_49 ,
& V_200 -> V_256 ) ;
if ( V_82 )
goto V_273;
V_82 = F_124 ( & V_200 -> V_49 -> V_49 ,
& V_200 -> V_257 ) ;
if ( V_82 )
goto V_274;
V_82 = F_124 ( & V_200 -> V_49 -> V_49 ,
& V_200 -> V_258 ) ;
if ( V_82 )
goto V_275;
V_82 = F_124 ( & V_200 -> V_49 -> V_49 ,
& V_200 -> V_259 ) ;
if ( V_82 )
goto V_276;
V_82 = F_124 ( & V_200 -> V_49 -> V_49 ,
& V_200 -> V_260 ) ;
if ( V_82 )
goto V_277;
V_82 = F_124 ( & V_200 -> V_49 -> V_49 ,
& V_200 -> V_261 ) ;
if ( V_82 )
goto V_278;
if ( V_200 -> V_201 . V_262 ) {
V_82 = F_124 ( & V_200 -> V_49 -> V_49 ,
& V_200 -> V_263 ) ;
if ( V_82 )
goto V_279;
}
if ( V_200 -> V_264 ) {
V_82 = F_124 ( & V_200 -> V_49 -> V_49 ,
& V_200 -> V_265 ) ;
if ( V_82 )
goto V_280;
}
return 0 ;
V_280:
if ( V_200 -> V_201 . V_262 )
F_117 ( & V_200 -> V_49 -> V_49 ,
& V_200 -> V_263 ) ;
V_279:
F_117 ( & V_200 -> V_49 -> V_49 ,
& V_200 -> V_261 ) ;
V_278:
F_117 ( & V_200 -> V_49 -> V_49 ,
& V_200 -> V_260 ) ;
V_277:
F_117 ( & V_200 -> V_49 -> V_49 ,
& V_200 -> V_259 ) ;
V_276:
F_117 ( & V_200 -> V_49 -> V_49 ,
& V_200 -> V_258 ) ;
V_275:
F_117 ( & V_200 -> V_49 -> V_49 ,
& V_200 -> V_257 ) ;
V_274:
F_117 ( & V_200 -> V_49 -> V_49 ,
& V_200 -> V_256 ) ;
V_273:
F_117 ( & V_200 -> V_49 -> V_49 ,
& V_200 -> V_255 ) ;
V_272:
F_117 ( & V_200 -> V_49 -> V_49 ,
& V_200 -> V_254 ) ;
V_148:
return V_82 ;
}
static int F_125 ( T_1 V_14 , int V_281 ,
const char * V_266 )
{
int V_94 ;
struct V_238 * V_200 = V_14 -> V_200 ;
struct V_238 * V_282 ;
int V_156 ;
char V_283 [ 1 ] ;
F_11 ( & V_269 ) ;
if ( V_200 -> V_264 )
V_282 = F_102 ( & V_284 . V_285 , V_200 -> V_239 ) ;
else
V_282 = F_105 ( & V_284 . V_285 ,
V_200 -> V_201 . V_243 ,
V_200 -> V_201 . V_244 ) ;
if ( V_282 ) {
F_15 ( V_200 ) ;
V_14 -> V_200 = V_282 ;
V_200 = V_282 ;
F_22 ( & V_200 -> V_32 ) ;
F_14 ( & V_269 ) ;
F_64 ( V_286
L_57
L_58 ,
V_200 -> V_201 . V_252 ,
V_200 -> V_201 . V_243 ,
V_200 -> V_201 . V_244 ) ;
} else {
char V_223 [ 14 ] ;
unsigned char V_287 = V_200 -> V_201 . V_244 ;
int V_288 = 0 ;
snprintf ( V_223 , sizeof( V_223 ) ,
L_59 , V_200 -> V_201 . V_243 ) ;
while ( F_105 ( & V_284 . V_285 ,
V_200 -> V_201 . V_243 ,
V_200 -> V_201 . V_244 ) ) {
if ( ! V_288 ) {
F_64 (KERN_WARNING PFX
L_60
L_61
L_62
L_63
L_64
L_65 ,
bmc->id.product_id, bmc->id.device_id) ;
V_288 = 1 ;
}
V_200 -> V_201 . V_244 ++ ;
if ( V_200 -> V_201 . V_244 == V_287 ) {
F_64 (KERN_ERR PFX
L_66 ) ;
break;
}
}
V_200 -> V_49 = F_126 ( V_223 , V_200 -> V_201 . V_244 ) ;
if ( ! V_200 -> V_49 ) {
F_14 ( & V_269 ) ;
F_64 ( V_289
L_67
L_68 ) ;
return - V_47 ;
}
V_200 -> V_49 -> V_49 . V_285 = & V_284 . V_285 ;
F_127 ( & V_200 -> V_49 -> V_49 , V_200 ) ;
F_47 ( & V_200 -> V_32 ) ;
V_94 = F_128 ( V_200 -> V_49 ) ;
F_14 ( & V_269 ) ;
if ( V_94 ) {
F_129 ( V_200 -> V_49 ) ;
V_200 -> V_49 = NULL ;
F_64 ( V_289
L_67
L_69 ,
V_94 ) ;
return V_94 ;
}
V_94 = F_122 ( V_200 ) ;
if ( V_94 ) {
F_11 ( & V_269 ) ;
F_119 ( V_200 -> V_49 ) ;
F_14 ( & V_269 ) ;
return V_94 ;
}
F_130 ( V_14 -> V_46 , L_70
L_71 ,
V_200 -> V_201 . V_252 ,
V_200 -> V_201 . V_243 ,
V_200 -> V_201 . V_244 ) ;
}
V_14 -> V_266 = F_131 ( V_266 , V_42 ) ;
if ( ! V_14 -> V_266 ) {
V_94 = - V_47 ;
F_64 ( V_289
L_72 ,
V_94 ) ;
goto V_43;
}
V_94 = F_132 ( & V_14 -> V_46 -> V_267 ,
& V_200 -> V_49 -> V_49 . V_267 , V_14 -> V_266 ) ;
if ( V_94 ) {
F_15 ( V_14 -> V_266 ) ;
V_14 -> V_266 = NULL ;
F_64 ( V_289
L_73 ,
V_94 ) ;
goto V_43;
}
V_156 = snprintf ( V_283 , 0 , L_74 , V_281 ) ;
V_14 -> V_268 = F_21 ( V_156 + 1 , V_42 ) ;
if ( ! V_14 -> V_268 ) {
F_15 ( V_14 -> V_266 ) ;
V_14 -> V_266 = NULL ;
V_94 = - V_47 ;
F_64 ( V_289
L_75 ,
V_94 ) ;
goto V_43;
}
snprintf ( V_14 -> V_268 , V_156 + 1 , L_74 , V_281 ) ;
V_94 = F_132 ( & V_200 -> V_49 -> V_49 . V_267 , & V_14 -> V_46 -> V_267 ,
V_14 -> V_268 ) ;
if ( V_94 ) {
F_15 ( V_14 -> V_266 ) ;
V_14 -> V_266 = NULL ;
F_15 ( V_14 -> V_268 ) ;
V_14 -> V_268 = NULL ;
F_64 ( V_289
L_67
L_76 ,
V_94 ) ;
goto V_43;
}
return 0 ;
V_43:
F_120 ( V_14 ) ;
return V_94 ;
}
static int
F_133 ( T_1 V_14 , int V_151 )
{
struct V_159 V_10 ;
struct V_56 V_290 ;
V_290 . V_3 = V_55 ;
V_290 . V_54 = V_72 ;
V_290 . V_59 = 0 ;
V_10 . V_86 = V_164 ;
V_10 . V_100 = V_291 ;
V_10 . V_88 = NULL ;
V_10 . V_87 = 0 ;
return F_72 ( NULL ,
V_14 ,
(struct V_1 * ) & V_290 ,
0 ,
& V_10 ,
V_14 ,
NULL ,
NULL ,
0 ,
V_14 -> V_132 [ 0 ] . V_131 ,
V_14 -> V_132 [ 0 ] . V_59 ,
- 1 , 0 ) ;
}
static void
F_134 ( T_1 V_14 , struct V_9 * V_10 )
{
if ( ( V_10 -> V_2 . V_3 != V_55 )
|| ( V_10 -> V_10 . V_86 != V_292 )
|| ( V_10 -> V_10 . V_100 != V_291 ) )
return;
if ( V_10 -> V_10 . V_88 [ 0 ] != 0 ) {
V_14 -> V_200 -> V_264 = 0 ;
goto V_148;
}
if ( V_10 -> V_10 . V_87 < 17 ) {
V_14 -> V_200 -> V_264 = 0 ;
F_64 (KERN_WARNING PFX
L_77
L_78
L_79 ,
msg->msg.data_len) ;
goto V_148;
}
memcpy ( V_14 -> V_200 -> V_239 , V_10 -> V_10 . V_88 , 16 ) ;
V_14 -> V_200 -> V_264 = 1 ;
V_148:
F_135 ( & V_14 -> V_293 ) ;
}
static void
F_136 ( T_1 V_14 )
{
int V_94 ;
V_14 -> V_200 -> V_264 = 0x2 ;
V_14 -> V_76 = F_134 ;
V_94 = F_133 ( V_14 , 0 ) ;
if ( V_94 )
V_14 -> V_200 -> V_264 = 0 ;
F_137 ( V_14 -> V_293 , V_14 -> V_200 -> V_264 != 2 ) ;
V_14 -> V_76 = NULL ;
}
static int
F_138 ( T_1 V_14 , int V_151 )
{
struct V_159 V_10 ;
unsigned char V_88 [ 1 ] ;
struct V_56 V_290 ;
V_290 . V_3 = V_55 ;
V_290 . V_54 = V_72 ;
V_290 . V_59 = 0 ;
V_10 . V_86 = V_164 ;
V_10 . V_100 = V_294 ;
V_10 . V_88 = V_88 ;
V_10 . V_87 = 1 ;
V_88 [ 0 ] = V_151 ;
return F_72 ( NULL ,
V_14 ,
(struct V_1 * ) & V_290 ,
0 ,
& V_10 ,
V_14 ,
NULL ,
NULL ,
0 ,
V_14 -> V_132 [ 0 ] . V_131 ,
V_14 -> V_132 [ 0 ] . V_59 ,
- 1 , 0 ) ;
}
static void
F_139 ( T_1 V_14 , struct V_9 * V_10 )
{
int V_94 = 0 ;
int V_151 ;
if ( ( V_10 -> V_2 . V_3 == V_55 )
&& ( V_10 -> V_10 . V_86 == V_292 )
&& ( V_10 -> V_10 . V_100 == V_294 ) ) {
if ( V_10 -> V_10 . V_88 [ 0 ] != 0 ) {
if ( V_10 -> V_10 . V_88 [ 0 ] == V_295 ) {
V_14 -> V_132 [ 0 ] . V_184
= V_185 ;
V_14 -> V_132 [ 0 ] . V_296
= V_297 ;
V_94 = - V_121 ;
V_14 -> V_298 = V_73 ;
F_135 ( & V_14 -> V_293 ) ;
goto V_148;
}
goto V_299;
}
if ( V_10 -> V_10 . V_87 < 4 ) {
goto V_299;
}
V_151 = V_14 -> V_298 ;
V_14 -> V_132 [ V_151 ] . V_184 = V_10 -> V_10 . V_88 [ 2 ] & 0x7f ;
V_14 -> V_132 [ V_151 ] . V_296 = V_10 -> V_10 . V_88 [ 3 ] & 0x1f ;
V_299:
V_14 -> V_298 ++ ;
if ( V_14 -> V_298 >= V_73 )
F_135 ( & V_14 -> V_293 ) ;
else
V_94 = F_138 ( V_14 , V_14 -> V_298 ) ;
if ( V_94 ) {
V_14 -> V_298 = V_73 ;
F_135 ( & V_14 -> V_293 ) ;
F_64 (KERN_WARNING PFX
L_80 ,
rv) ;
}
}
V_148:
return;
}
void F_140 ( T_2 V_74 )
{
T_1 V_14 = V_74 -> V_14 ;
if ( V_14 -> V_113 -> V_300 )
V_14 -> V_113 -> V_300 ( V_14 -> V_116 ) ;
}
int F_141 ( struct V_120 * V_113 ,
void * V_116 ,
struct V_301 * V_244 ,
struct V_48 * V_46 ,
const char * V_266 ,
unsigned char V_63 )
{
int V_15 , V_302 ;
int V_94 ;
T_1 V_14 ;
T_1 V_303 ;
struct V_7 * V_12 ;
if ( ! V_109 ) {
V_94 = F_45 () ;
if ( V_94 )
return V_94 ;
if ( ! V_109 )
return - V_101 ;
}
V_14 = F_142 ( sizeof( * V_14 ) , V_42 ) ;
if ( ! V_14 )
return - V_47 ;
V_14 -> V_129 = V_129 ( V_244 ) ;
V_14 -> V_130 = V_130 ( V_244 ) ;
V_14 -> V_200 = F_142 ( sizeof( * V_14 -> V_200 ) , V_42 ) ;
if ( ! V_14 -> V_200 ) {
F_15 ( V_14 ) ;
return - V_47 ;
}
V_14 -> V_41 = - 1 ;
F_47 ( & V_14 -> V_32 ) ;
V_14 -> V_200 -> V_201 = * V_244 ;
V_14 -> V_46 = V_46 ;
for ( V_302 = 0 ; V_302 < V_73 ; V_302 ++ ) {
V_14 -> V_132 [ V_302 ] . V_131 = V_304 ;
V_14 -> V_132 [ V_302 ] . V_59 = 2 ;
}
if ( V_63 != 0 )
V_14 -> V_132 [ 0 ] . V_131 = V_63 ;
F_12 ( & V_14 -> V_118 ) ;
V_14 -> V_113 = V_113 ;
V_14 -> V_116 = V_116 ;
F_143 ( & V_14 -> V_103 ) ;
for ( V_302 = 0 ; V_302 < V_25 ; V_302 ++ ) {
V_14 -> V_26 [ V_302 ] . V_27 = 0 ;
V_14 -> V_26 [ V_302 ] . V_93 = 0 ;
}
V_14 -> V_95 = 0 ;
#ifdef F_94
F_144 ( & V_14 -> V_230 ) ;
#endif
F_143 ( & V_14 -> V_305 ) ;
F_12 ( & V_14 -> V_20 ) ;
F_143 ( & V_14 -> V_146 ) ;
F_12 ( & V_14 -> V_21 ) ;
V_14 -> V_149 = 0 ;
F_144 ( & V_14 -> V_22 ) ;
F_143 ( & V_14 -> V_135 ) ;
F_12 ( & V_14 -> V_23 ) ;
F_145 ( & V_14 -> V_293 ) ;
for ( V_15 = 0 ; V_15 < V_306 ; V_15 ++ )
F_146 ( & V_14 -> V_307 [ V_15 ] , 0 ) ;
V_14 -> V_229 = NULL ;
F_11 ( & V_39 ) ;
F_11 ( & V_40 ) ;
V_15 = 0 ;
V_12 = & V_308 ;
F_46 (tintf, &ipmi_interfaces, link) {
if ( V_303 -> V_41 != V_15 ) {
V_12 = & V_303 -> V_12 ;
break;
}
V_15 ++ ;
}
if ( V_15 == 0 )
F_48 ( & V_14 -> V_12 , & V_308 ) ;
else
F_147 ( & V_14 -> V_12 , V_12 ) ;
V_94 = V_113 -> V_309 ( V_116 , V_14 ) ;
if ( V_94 )
goto V_148;
F_136 ( V_14 ) ;
if ( ( V_14 -> V_129 > 1 )
|| ( ( V_14 -> V_129 == 1 )
&& ( V_14 -> V_130 >= 5 ) ) ) {
V_14 -> V_76 = F_139 ;
V_14 -> V_298 = 0 ;
V_94 = F_138 ( V_14 , 0 ) ;
if ( V_94 )
goto V_148;
F_137 ( V_14 -> V_293 ,
V_14 -> V_298 >= V_73 ) ;
V_14 -> V_76 = NULL ;
} else {
V_14 -> V_132 [ 0 ] . V_184 = V_185 ;
V_14 -> V_132 [ 0 ] . V_296 = V_297 ;
V_14 -> V_298 = V_73 ;
}
if ( V_94 == 0 )
V_94 = F_96 ( V_14 , V_15 ) ;
V_94 = F_125 ( V_14 , V_15 , V_266 ) ;
V_148:
if ( V_94 ) {
if ( V_14 -> V_229 )
F_98 ( V_14 ) ;
V_14 -> V_113 = NULL ;
F_52 ( & V_14 -> V_12 ) ;
F_14 ( & V_40 ) ;
F_14 ( & V_39 ) ;
V_24 () ;
F_25 ( & V_14 -> V_32 , F_16 ) ;
} else {
F_148 () ;
V_14 -> V_41 = V_15 ;
F_14 ( & V_40 ) ;
F_27 ( V_15 , V_14 -> V_46 ) ;
F_14 ( & V_39 ) ;
}
return V_94 ;
}
static void F_149 ( T_1 V_14 )
{
int V_15 ;
struct V_26 * V_105 ;
for ( V_15 = 0 ; V_15 < V_25 ; V_15 ++ ) {
V_105 = & ( V_14 -> V_26 [ V_15 ] ) ;
if ( ! V_105 -> V_27 )
continue;
F_35 ( V_105 -> V_28 , V_310 ) ;
}
}
int F_150 ( T_1 V_14 )
{
struct V_33 * V_50 ;
int V_41 = V_14 -> V_41 ;
F_120 ( V_14 ) ;
F_11 ( & V_39 ) ;
F_11 ( & V_40 ) ;
V_14 -> V_41 = - 1 ;
V_14 -> V_113 = NULL ;
F_52 ( & V_14 -> V_12 ) ;
F_14 ( & V_40 ) ;
V_24 () ;
F_149 ( V_14 ) ;
F_98 ( V_14 ) ;
F_20 (w, &smi_watchers, link)
V_50 -> V_311 ( V_41 ) ;
F_14 ( & V_39 ) ;
F_25 ( & V_14 -> V_32 , F_16 ) ;
return 0 ;
}
static int F_151 ( T_1 V_14 ,
struct V_13 * V_10 )
{
struct V_60 V_160 ;
struct V_9 * V_28 ;
if ( V_10 -> V_312 < 11 ) {
F_34 ( V_14 , V_207 ) ;
return 0 ;
}
if ( V_10 -> V_313 [ 2 ] != 0 ) {
return 0 ;
}
V_160 . V_3 = V_5 ;
V_160 . V_63 = V_10 -> V_313 [ 6 ] ;
V_160 . V_54 = V_10 -> V_313 [ 3 ] & 0x0f ;
V_160 . V_59 = V_10 -> V_313 [ 7 ] & 3 ;
if ( F_38 ( V_14 ,
V_10 -> V_313 [ 7 ] >> 2 ,
V_10 -> V_313 [ 3 ] & 0x0f ,
V_10 -> V_313 [ 8 ] ,
( V_10 -> V_313 [ 4 ] >> 2 ) & ( ~ 1 ) ,
(struct V_1 * ) & ( V_160 ) ,
& V_28 ) ) {
F_34 ( V_14 , V_208 ) ;
return 0 ;
}
memcpy ( V_28 -> V_85 ,
& ( V_10 -> V_313 [ 9 ] ) ,
V_10 -> V_312 - 9 ) ;
V_28 -> V_10 . V_86 = V_10 -> V_313 [ 4 ] >> 2 ;
V_28 -> V_10 . V_88 = V_28 -> V_85 ;
V_28 -> V_10 . V_87 = V_10 -> V_312 - 10 ;
V_28 -> V_83 = V_84 ;
F_34 ( V_14 , V_206 ) ;
F_33 ( V_28 ) ;
return 0 ;
}
static int F_152 ( T_1 V_14 ,
struct V_13 * V_10 )
{
struct V_16 * V_17 ;
int V_94 = 0 ;
unsigned char V_86 ;
unsigned char V_100 ;
unsigned char V_151 ;
T_2 V_74 = NULL ;
struct V_60 * V_160 ;
struct V_9 * V_28 ;
struct V_120 * V_113 ;
if ( V_10 -> V_312 < 10 ) {
F_34 ( V_14 , V_216 ) ;
return 0 ;
}
if ( V_10 -> V_313 [ 2 ] != 0 ) {
return 0 ;
}
V_86 = V_10 -> V_313 [ 4 ] >> 2 ;
V_100 = V_10 -> V_313 [ 8 ] ;
V_151 = V_10 -> V_313 [ 3 ] & 0xf ;
F_75 () ;
V_17 = F_65 ( V_14 , V_86 , V_100 , V_151 ) ;
if ( V_17 ) {
V_74 = V_17 -> V_74 ;
F_22 ( & V_74 -> V_32 ) ;
} else
V_74 = NULL ;
F_78 () ;
if ( V_74 == NULL ) {
F_34 ( V_14 , V_217 ) ;
V_10 -> V_88 [ 0 ] = ( V_164 << 2 ) ;
V_10 -> V_88 [ 1 ] = V_165 ;
V_10 -> V_88 [ 2 ] = V_10 -> V_313 [ 3 ] ;
V_10 -> V_88 [ 3 ] = V_10 -> V_313 [ 6 ] ;
V_10 -> V_88 [ 4 ] = ( ( V_86 + 1 ) << 2 ) | ( V_10 -> V_313 [ 7 ] & 0x3 ) ;
V_10 -> V_88 [ 5 ] = F_69 ( & ( V_10 -> V_88 [ 3 ] ) , 2 ) ;
V_10 -> V_88 [ 6 ] = V_14 -> V_132 [ V_10 -> V_313 [ 3 ] & 0xf ] . V_131 ;
V_10 -> V_88 [ 7 ] = ( V_10 -> V_313 [ 7 ] & 0xfc ) | ( V_10 -> V_313 [ 4 ] & 0x3 ) ;
V_10 -> V_88 [ 8 ] = V_10 -> V_313 [ 8 ] ;
V_10 -> V_88 [ 9 ] = V_314 ;
V_10 -> V_88 [ 10 ] = F_69 ( & ( V_10 -> V_88 [ 6 ] ) , 4 ) ;
V_10 -> V_166 = 11 ;
#ifdef F_77
{
int V_192 ;
F_64 ( L_81 ) ;
for ( V_192 = 0 ; V_192 < V_10 -> V_166 ; V_192 ++ )
F_64 ( L_3 , V_10 -> V_88 [ V_192 ] ) ;
F_64 ( L_4 ) ;
}
#endif
F_75 () ;
V_113 = V_14 -> V_113 ;
if ( V_113 ) {
V_113 -> V_193 ( V_14 -> V_116 , V_10 , 0 ) ;
V_94 = - 1 ;
}
F_78 () ;
} else {
F_34 ( V_14 , V_215 ) ;
V_28 = F_73 () ;
if ( ! V_28 ) {
V_94 = 1 ;
F_25 ( & V_74 -> V_32 , F_50 ) ;
} else {
V_160 = (struct V_60 * ) & V_28 -> V_2 ;
V_160 -> V_3 = V_5 ;
V_160 -> V_63 = V_10 -> V_313 [ 6 ] ;
V_160 -> V_59 = V_10 -> V_313 [ 7 ] & 3 ;
V_160 -> V_54 = V_10 -> V_313 [ 3 ] & 0xf ;
V_28 -> V_74 = V_74 ;
V_28 -> V_83 = V_315 ;
V_28 -> V_104 = V_10 -> V_313 [ 7 ] >> 2 ;
V_28 -> V_10 . V_86 = V_10 -> V_313 [ 4 ] >> 2 ;
V_28 -> V_10 . V_100 = V_10 -> V_313 [ 8 ] ;
V_28 -> V_10 . V_88 = V_28 -> V_85 ;
V_28 -> V_10 . V_87 = V_10 -> V_312 - 10 ;
memcpy ( V_28 -> V_85 ,
& ( V_10 -> V_313 [ 9 ] ) ,
V_10 -> V_312 - 10 ) ;
F_33 ( V_28 ) ;
}
}
return V_94 ;
}
static int F_153 ( T_1 V_14 ,
struct V_13 * V_10 )
{
struct V_64 V_167 ;
struct V_9 * V_28 ;
if ( V_10 -> V_312 < 13 ) {
F_34 ( V_14 , V_213 ) ;
return 0 ;
}
if ( V_10 -> V_313 [ 2 ] != 0 ) {
return 0 ;
}
V_167 . V_3 = V_4 ;
V_167 . V_69 = V_10 -> V_313 [ 4 ] ;
V_167 . V_67 = V_10 -> V_313 [ 8 ] ;
V_167 . V_68 = V_10 -> V_313 [ 5 ] ;
V_167 . V_54 = V_10 -> V_313 [ 3 ] & 0x0f ;
V_167 . V_316 = V_10 -> V_313 [ 3 ] >> 4 ;
V_167 . V_59 = V_10 -> V_313 [ 9 ] & 3 ;
if ( F_38 ( V_14 ,
V_10 -> V_313 [ 9 ] >> 2 ,
V_10 -> V_313 [ 3 ] & 0x0f ,
V_10 -> V_313 [ 10 ] ,
( V_10 -> V_313 [ 6 ] >> 2 ) & ( ~ 1 ) ,
(struct V_1 * ) & ( V_167 ) ,
& V_28 ) ) {
F_34 ( V_14 , V_214 ) ;
return 0 ;
}
memcpy ( V_28 -> V_85 ,
& ( V_10 -> V_313 [ 11 ] ) ,
V_10 -> V_312 - 11 ) ;
V_28 -> V_10 . V_86 = V_10 -> V_313 [ 6 ] >> 2 ;
V_28 -> V_10 . V_88 = V_28 -> V_85 ;
V_28 -> V_10 . V_87 = V_10 -> V_312 - 12 ;
V_28 -> V_83 = V_84 ;
F_34 ( V_14 , V_212 ) ;
F_33 ( V_28 ) ;
return 0 ;
}
static int F_154 ( T_1 V_14 ,
struct V_13 * V_10 )
{
struct V_16 * V_17 ;
int V_94 = 0 ;
unsigned char V_86 ;
unsigned char V_100 ;
unsigned char V_151 ;
T_2 V_74 = NULL ;
struct V_64 * V_167 ;
struct V_9 * V_28 ;
if ( V_10 -> V_312 < 12 ) {
F_34 ( V_14 , V_216 ) ;
return 0 ;
}
if ( V_10 -> V_313 [ 2 ] != 0 ) {
return 0 ;
}
V_86 = V_10 -> V_313 [ 6 ] >> 2 ;
V_100 = V_10 -> V_313 [ 10 ] ;
V_151 = V_10 -> V_313 [ 3 ] & 0xf ;
F_75 () ;
V_17 = F_65 ( V_14 , V_86 , V_100 , V_151 ) ;
if ( V_17 ) {
V_74 = V_17 -> V_74 ;
F_22 ( & V_74 -> V_32 ) ;
} else
V_74 = NULL ;
F_78 () ;
if ( V_74 == NULL ) {
F_34 ( V_14 , V_217 ) ;
V_94 = 0 ;
} else {
F_34 ( V_14 , V_215 ) ;
V_28 = F_73 () ;
if ( ! V_28 ) {
V_94 = 1 ;
F_25 ( & V_74 -> V_32 , F_50 ) ;
} else {
V_167 = (struct V_64 * ) & V_28 -> V_2 ;
V_167 -> V_3 = V_4 ;
V_167 -> V_69 = V_10 -> V_313 [ 4 ] ;
V_167 -> V_67 = V_10 -> V_313 [ 8 ] ;
V_167 -> V_68 = V_10 -> V_313 [ 5 ] ;
V_167 -> V_59 = V_10 -> V_313 [ 9 ] & 3 ;
V_167 -> V_54 = V_10 -> V_313 [ 3 ] & 0xf ;
V_167 -> V_316 = V_10 -> V_313 [ 3 ] >> 4 ;
V_28 -> V_74 = V_74 ;
V_28 -> V_83 = V_315 ;
V_28 -> V_104 = V_10 -> V_313 [ 9 ] >> 2 ;
V_28 -> V_10 . V_86 = V_10 -> V_313 [ 6 ] >> 2 ;
V_28 -> V_10 . V_100 = V_10 -> V_313 [ 10 ] ;
V_28 -> V_10 . V_88 = V_28 -> V_85 ;
V_28 -> V_10 . V_87 = V_10 -> V_312 - 12 ;
memcpy ( V_28 -> V_85 ,
& ( V_10 -> V_313 [ 11 ] ) ,
V_10 -> V_312 - 12 ) ;
F_33 ( V_28 ) ;
}
}
return V_94 ;
}
static int F_155 ( T_1 V_14 ,
struct V_13 * V_10 )
{
struct V_16 * V_17 ;
int V_94 = 0 ;
unsigned char V_86 ;
unsigned char V_100 ;
unsigned char V_151 ;
T_2 V_74 = NULL ;
struct V_56 * V_172 ;
struct V_9 * V_28 ;
if ( V_10 -> V_312 < 4 ) {
F_34 ( V_14 , V_216 ) ;
return 0 ;
}
if ( V_10 -> V_313 [ 2 ] != 0 ) {
return 0 ;
}
V_86 = V_10 -> V_313 [ 0 ] >> 2 ;
V_100 = V_10 -> V_313 [ 1 ] ;
V_151 = V_10 -> V_313 [ 3 ] & 0xf ;
F_75 () ;
V_17 = F_65 ( V_14 , V_86 , V_100 , V_151 ) ;
if ( V_17 ) {
V_74 = V_17 -> V_74 ;
F_22 ( & V_74 -> V_32 ) ;
} else
V_74 = NULL ;
F_78 () ;
if ( V_74 == NULL ) {
F_34 ( V_14 , V_217 ) ;
V_94 = 0 ;
} else {
F_34 ( V_14 , V_215 ) ;
V_28 = F_73 () ;
if ( ! V_28 ) {
V_94 = 1 ;
F_25 ( & V_74 -> V_32 , F_50 ) ;
} else {
V_172 = ( (struct V_56 * )
& ( V_28 -> V_2 ) ) ;
V_172 -> V_3 = V_55 ;
V_172 -> V_54 = V_72 ;
V_172 -> V_59 = V_10 -> V_313 [ 0 ] & 3 ;
V_28 -> V_74 = V_74 ;
V_28 -> V_75 = NULL ;
V_28 -> V_83 = V_317 ;
V_28 -> V_10 . V_86 = V_10 -> V_313 [ 0 ] >> 2 ;
V_28 -> V_10 . V_100 = V_10 -> V_313 [ 1 ] ;
V_28 -> V_10 . V_88 = V_28 -> V_85 ;
V_28 -> V_10 . V_87 = V_10 -> V_312 - 4 ;
memcpy ( V_28 -> V_85 ,
& ( V_10 -> V_313 [ 4 ] ) ,
V_10 -> V_312 - 4 ) ;
F_33 ( V_28 ) ;
}
}
return V_94 ;
}
static void F_156 ( struct V_9 * V_28 ,
struct V_13 * V_10 )
{
struct V_56 * V_172 ;
V_28 -> V_104 = 0 ;
V_172 = (struct V_56 * ) & ( V_28 -> V_2 ) ;
V_172 -> V_3 = V_55 ;
V_172 -> V_54 = V_72 ;
V_172 -> V_59 = V_10 -> V_313 [ 0 ] & 3 ;
V_28 -> V_83 = V_318 ;
V_28 -> V_10 . V_86 = V_10 -> V_313 [ 0 ] >> 2 ;
V_28 -> V_10 . V_100 = V_10 -> V_313 [ 1 ] ;
memcpy ( V_28 -> V_85 , & ( V_10 -> V_313 [ 3 ] ) , V_10 -> V_312 - 3 ) ;
V_28 -> V_10 . V_88 = V_28 -> V_85 ;
V_28 -> V_10 . V_87 = V_10 -> V_312 - 3 ;
}
static int F_157 ( T_1 V_14 ,
struct V_13 * V_10 )
{
struct V_9 * V_28 , * V_319 ;
struct V_7 V_145 ;
T_2 V_74 ;
int V_94 = 0 ;
int V_320 = 0 ;
unsigned long V_102 ;
if ( V_10 -> V_312 < 19 ) {
F_34 ( V_14 , V_218 ) ;
return 0 ;
}
if ( V_10 -> V_313 [ 2 ] != 0 ) {
return 0 ;
}
F_12 ( & V_145 ) ;
F_39 ( & V_14 -> V_146 , V_102 ) ;
F_34 ( V_14 , V_219 ) ;
F_75 () ;
F_46 (user, &intf->users, link) {
if ( ! V_74 -> V_112 )
continue;
V_28 = F_73 () ;
if ( ! V_28 ) {
F_78 () ;
F_5 (recv_msg, recv_msg2, &msgs,
link) {
F_6 ( & V_28 -> V_12 ) ;
F_7 ( V_28 ) ;
}
V_94 = 1 ;
goto V_148;
}
V_320 ++ ;
F_156 ( V_28 , V_10 ) ;
V_28 -> V_74 = V_74 ;
F_22 ( & V_74 -> V_32 ) ;
F_23 ( & ( V_28 -> V_12 ) , & V_145 ) ;
}
F_78 () ;
if ( V_320 ) {
F_5 (recv_msg, recv_msg2, &msgs, link) {
F_6 ( & V_28 -> V_12 ) ;
F_33 ( V_28 ) ;
}
} else if ( V_14 -> V_149 < V_321 ) {
V_28 = F_73 () ;
if ( ! V_28 ) {
V_94 = 1 ;
goto V_148;
}
F_156 ( V_28 , V_10 ) ;
F_23 ( & ( V_28 -> V_12 ) , & ( V_14 -> V_21 ) ) ;
V_14 -> V_149 ++ ;
} else if ( ! V_14 -> V_150 ) {
F_64 (KERN_WARNING PFX L_82
L_83 ) ;
V_14 -> V_150 = 1 ;
}
V_148:
F_40 ( & ( V_14 -> V_146 ) , V_102 ) ;
return V_94 ;
}
static int F_158 ( T_1 V_14 ,
struct V_13 * V_10 )
{
struct V_9 * V_28 ;
struct V_123 * V_74 ;
V_28 = (struct V_9 * ) V_10 -> V_182 ;
if ( V_28 == NULL ) {
F_64 ( V_322
L_84
L_85
L_86
L_87 ) ;
return 0 ;
}
V_74 = V_28 -> V_74 ;
if ( V_74 && ! V_74 -> V_117 ) {
F_34 ( V_14 , V_78 ) ;
F_7 ( V_28 ) ;
} else {
struct V_56 * V_172 ;
F_34 ( V_14 , V_77 ) ;
V_28 -> V_83 = V_84 ;
V_28 -> V_104 = V_10 -> V_104 ;
V_172 = ( (struct V_56 * )
& ( V_28 -> V_2 ) ) ;
V_172 -> V_3 = V_55 ;
V_172 -> V_54 = V_72 ;
V_172 -> V_59 = V_10 -> V_313 [ 0 ] & 3 ;
V_28 -> V_10 . V_86 = V_10 -> V_313 [ 0 ] >> 2 ;
V_28 -> V_10 . V_100 = V_10 -> V_313 [ 1 ] ;
memcpy ( V_28 -> V_85 ,
& ( V_10 -> V_313 [ 2 ] ) ,
V_10 -> V_312 - 2 ) ;
V_28 -> V_10 . V_88 = V_28 -> V_85 ;
V_28 -> V_10 . V_87 = V_10 -> V_312 - 2 ;
F_33 ( V_28 ) ;
}
return 0 ;
}
static int F_159 ( T_1 V_14 ,
struct V_13 * V_10 )
{
int V_323 ;
int V_151 ;
#ifdef F_77
int V_192 ;
F_64 ( L_88 ) ;
for ( V_192 = 0 ; V_192 < V_10 -> V_312 ; V_192 ++ )
F_64 ( L_3 , V_10 -> V_313 [ V_192 ] ) ;
F_64 ( L_4 ) ;
#endif
if ( V_10 -> V_312 < 2 ) {
F_64 (KERN_WARNING PFX L_89
L_90 ,
(msg->data[0] >> 2) | 1 , msg->data[1], msg->rsp_size) ;
V_10 -> V_313 [ 0 ] = V_10 -> V_88 [ 0 ] | ( 1 << 2 ) ;
V_10 -> V_313 [ 1 ] = V_10 -> V_88 [ 1 ] ;
V_10 -> V_313 [ 2 ] = V_310 ;
V_10 -> V_312 = 3 ;
} else if ( ( ( V_10 -> V_313 [ 0 ] >> 2 ) != ( ( V_10 -> V_88 [ 0 ] >> 2 ) | 1 ) )
|| ( V_10 -> V_313 [ 1 ] != V_10 -> V_88 [ 1 ] ) ) {
F_64 (KERN_WARNING PFX L_91
L_92 ,
(msg->data[0] >> 2) | 1 , msg->data[1],
msg->rsp[0] >> 2 , msg->rsp[1]) ;
V_10 -> V_313 [ 0 ] = V_10 -> V_88 [ 0 ] | ( 1 << 2 ) ;
V_10 -> V_313 [ 1 ] = V_10 -> V_88 [ 1 ] ;
V_10 -> V_313 [ 2 ] = V_310 ;
V_10 -> V_312 = 3 ;
}
if ( ( V_10 -> V_313 [ 0 ] == ( ( V_164 | 1 ) << 2 ) )
&& ( V_10 -> V_313 [ 1 ] == V_165 )
&& ( V_10 -> V_182 != NULL ) ) {
struct V_9 * V_28 = V_10 -> V_182 ;
V_323 = 0 ;
if ( V_10 -> V_312 < 2 )
goto V_148;
V_151 = V_10 -> V_88 [ 2 ] & 0x0f ;
if ( V_151 >= V_73 )
goto V_148;
if ( ! V_28 )
goto V_148;
if ( ! V_28 -> V_74 || ! V_28 -> V_74 -> V_117 )
goto V_148;
V_28 -> V_83 = V_324 ;
V_28 -> V_10 . V_88 = V_28 -> V_85 ;
V_28 -> V_10 . V_87 = 1 ;
V_28 -> V_85 [ 0 ] = V_10 -> V_313 [ 2 ] ;
F_33 ( V_28 ) ;
} else if ( ( V_10 -> V_313 [ 0 ] == ( ( V_164 | 1 ) << 2 ) )
&& ( V_10 -> V_313 [ 1 ] == V_174 ) ) {
V_151 = V_10 -> V_313 [ 3 ] & 0xf ;
if ( V_151 >= V_73 ) {
V_323 = 0 ;
goto V_148;
}
if ( V_14 -> V_298 < V_73 ) {
V_323 = 0 ;
goto V_148;
}
switch ( V_14 -> V_132 [ V_151 ] . V_184 ) {
case V_185 :
if ( V_10 -> V_313 [ 4 ] & 0x04 ) {
V_323 = F_151 ( V_14 , V_10 ) ;
} else {
V_323 = F_152 ( V_14 , V_10 ) ;
}
break;
case V_188 :
case V_189 :
if ( V_10 -> V_313 [ 6 ] & 0x04 ) {
V_323 = F_153 ( V_14 , V_10 ) ;
} else {
V_323 = F_154 ( V_14 , V_10 ) ;
}
break;
default:
if ( ( V_14 -> V_132 [ V_151 ] . V_184
>= V_325 )
&& ( V_14 -> V_132 [ V_151 ] . V_184
<= V_326 ) ) {
V_323 = F_155 ( V_14 , V_10 ) ;
} else {
V_323 = 0 ;
}
}
} else if ( ( V_10 -> V_313 [ 0 ] == ( ( V_164 | 1 ) << 2 ) )
&& ( V_10 -> V_313 [ 1 ] == V_175 ) ) {
V_323 = F_157 ( V_14 , V_10 ) ;
} else {
V_323 = F_158 ( V_14 , V_10 ) ;
}
V_148:
return V_323 ;
}
void F_160 ( T_1 V_14 ,
struct V_13 * V_10 )
{
unsigned long V_102 = 0 ;
int V_94 ;
int V_327 ;
if ( ( V_10 -> V_166 >= 2 )
&& ( V_10 -> V_88 [ 0 ] == ( V_164 << 2 ) )
&& ( V_10 -> V_88 [ 1 ] == V_165 )
&& ( V_10 -> V_182 == NULL ) ) {
if ( ( V_10 -> V_312 >= 3 ) && ( V_10 -> V_313 [ 2 ] != 0 )
&& ( V_10 -> V_313 [ 2 ] != V_328 )
&& ( V_10 -> V_313 [ 2 ] != V_329 )
&& ( V_10 -> V_313 [ 2 ] != V_330 )
&& ( V_10 -> V_313 [ 2 ] != V_331 ) ) {
int V_151 = V_10 -> V_313 [ 3 ] & 0xf ;
if ( V_151 >= V_73 )
;
else if ( ( V_14 -> V_132 [ V_151 ] . V_184
== V_188 )
|| ( V_14 -> V_132 [ V_151 ] . V_184
== V_189 ) )
F_34 ( V_14 , V_209 ) ;
else
F_34 ( V_14 , V_202 ) ;
F_43 ( V_14 , V_10 -> V_104 , V_10 -> V_313 [ 2 ] ) ;
} else
F_41 ( V_14 , V_10 -> V_104 ) ;
F_9 ( V_10 ) ;
goto V_148;
}
V_327 = V_14 -> V_327 ;
if ( ! V_327 )
F_39 ( & V_14 -> V_305 , V_102 ) ;
if ( ! F_62 ( & V_14 -> V_20 ) ) {
F_23 ( & V_10 -> V_12 , & V_14 -> V_20 ) ;
if ( ! V_327 )
F_40 ( & V_14 -> V_305 , V_102 ) ;
goto V_148;
}
if ( ! V_327 )
F_40 ( & V_14 -> V_305 , V_102 ) ;
V_94 = F_159 ( V_14 , V_10 ) ;
if ( V_94 > 0 ) {
V_327 = V_14 -> V_327 ;
if ( ! V_327 )
F_39 ( & V_14 -> V_305 , V_102 ) ;
F_23 ( & V_10 -> V_12 , & V_14 -> V_20 ) ;
if ( ! V_327 )
F_40 ( & V_14 -> V_305 , V_102 ) ;
} else if ( V_94 == 0 ) {
F_9 ( V_10 ) ;
}
V_148:
return;
}
void F_161 ( T_1 V_14 )
{
T_2 V_74 ;
F_75 () ;
F_46 (user, &intf->users, link) {
if ( ! V_74 -> V_79 -> V_332 )
continue;
V_74 -> V_79 -> V_332 ( V_74 -> V_81 ) ;
}
F_78 () ;
}
static struct V_13 *
F_162 ( T_1 V_14 , struct V_9 * V_28 ,
unsigned char V_92 , long V_93 )
{
struct V_13 * V_158 = F_74 () ;
if ( ! V_158 )
return NULL ;
memcpy ( V_158 -> V_88 , V_28 -> V_10 . V_88 , V_28 -> V_10 . V_87 ) ;
V_158 -> V_166 = V_28 -> V_10 . V_87 ;
V_158 -> V_104 = F_76 ( V_92 , V_93 ) ;
#ifdef F_77
{
int V_192 ;
F_64 ( L_93 ) ;
for ( V_192 = 0 ; V_192 < V_158 -> V_166 ; V_192 ++ )
F_64 ( L_3 , V_158 -> V_88 [ V_192 ] ) ;
F_64 ( L_4 ) ;
}
#endif
return V_158 ;
}
static void F_163 ( T_1 V_14 , struct V_26 * V_105 ,
struct V_7 * V_333 , long V_334 ,
int V_335 , unsigned long * V_102 )
{
struct V_9 * V_10 ;
struct V_120 * V_113 ;
if ( V_14 -> V_41 == - 1 )
return;
if ( ! V_105 -> V_27 )
return;
V_105 -> V_89 -= V_334 ;
if ( V_105 -> V_89 > 0 )
return;
if ( V_105 -> V_98 == 0 ) {
V_105 -> V_27 = 0 ;
V_10 = V_105 -> V_28 ;
F_23 ( & V_10 -> V_12 , V_333 ) ;
if ( V_105 -> V_91 )
F_34 ( V_14 , V_205 ) ;
else if ( F_1 ( & V_105 -> V_28 -> V_2 ) )
F_34 ( V_14 , V_211 ) ;
else
F_34 ( V_14 , V_204 ) ;
} else {
struct V_13 * V_158 ;
V_105 -> V_89 = V_96 ;
V_105 -> V_98 -- ;
V_158 = F_162 ( V_14 , V_105 -> V_28 , V_335 ,
V_105 -> V_93 ) ;
if ( ! V_158 ) {
if ( F_1 ( & V_105 -> V_28 -> V_2 ) )
F_34 ( V_14 ,
V_220 ) ;
else
F_34 ( V_14 ,
V_221 ) ;
return;
}
F_40 ( & V_14 -> V_103 , * V_102 ) ;
V_113 = V_14 -> V_113 ;
if ( V_113 ) {
if ( F_1 ( & V_105 -> V_28 -> V_2 ) )
F_34 ( V_14 ,
V_210 ) ;
else
F_34 ( V_14 ,
V_203 ) ;
V_14 -> V_113 -> V_193 ( V_14 -> V_116 ,
V_158 , 0 ) ;
} else
F_9 ( V_158 ) ;
F_39 ( & V_14 -> V_103 , * V_102 ) ;
}
}
static void F_164 ( long V_334 )
{
T_1 V_14 ;
struct V_7 V_333 ;
struct V_9 * V_10 , * V_11 ;
struct V_13 * V_158 , * V_336 ;
unsigned long V_102 ;
int V_15 ;
F_75 () ;
F_46 (intf, &ipmi_interfaces, link) {
F_39 ( & V_14 -> V_305 , V_102 ) ;
F_5 (smi_msg, smi_msg2,
&intf->waiting_msgs, link) {
if ( ! F_159 ( V_14 , V_158 ) ) {
F_6 ( & V_158 -> V_12 ) ;
F_9 ( V_158 ) ;
} else {
break;
}
}
F_40 ( & V_14 -> V_305 , V_102 ) ;
F_12 ( & V_333 ) ;
F_39 ( & V_14 -> V_103 , V_102 ) ;
for ( V_15 = 0 ; V_15 < V_25 ; V_15 ++ )
F_163 ( V_14 , & ( V_14 -> V_26 [ V_15 ] ) ,
& V_333 , V_334 , V_15 ,
& V_102 ) ;
F_40 ( & V_14 -> V_103 , V_102 ) ;
F_5 (msg, msg2, &timeouts, link)
F_35 ( V_10 , V_337 ) ;
if ( V_14 -> V_140 > 0 ) {
F_39 ( & V_14 -> V_135 , V_102 ) ;
if ( V_14 -> V_140 > 0 ) {
V_14 -> V_140
-= V_334 ;
if ( ! V_14 -> V_136
&& ( V_14 -> V_140 <= 0 ) ) {
V_14 -> V_138 = 0 ;
F_59 ( V_14 ) ;
}
}
F_40 ( & V_14 -> V_135 ,
V_102 ) ;
}
}
F_78 () ;
}
static void F_165 ( void )
{
T_1 V_14 ;
struct V_120 * V_113 ;
F_75 () ;
F_46 (intf, &ipmi_interfaces, link) {
if ( V_14 -> V_138 )
continue;
V_113 = V_14 -> V_113 ;
if ( V_113 )
V_113 -> V_338 ( V_14 -> V_116 ) ;
}
F_78 () ;
}
static void F_166 ( unsigned long V_88 )
{
if ( F_167 ( & V_339 ) )
return;
V_340 -- ;
if ( V_340 == 0 ) {
F_165 () ;
V_340 = V_341 ;
}
F_164 ( V_342 ) ;
F_168 ( & V_343 , V_344 + V_345 ) ;
}
static void F_169 ( struct V_13 * V_10 )
{
F_170 ( & V_346 ) ;
F_15 ( V_10 ) ;
}
struct V_13 * F_74 ( void )
{
struct V_13 * V_94 ;
V_94 = F_21 ( sizeof( struct V_13 ) , V_347 ) ;
if ( V_94 ) {
V_94 -> V_348 = F_169 ;
V_94 -> V_182 = NULL ;
F_171 ( & V_346 ) ;
}
return V_94 ;
}
static void F_172 ( struct V_9 * V_10 )
{
F_170 ( & V_349 ) ;
F_15 ( V_10 ) ;
}
static struct V_9 * F_73 ( void )
{
struct V_9 * V_94 ;
V_94 = F_21 ( sizeof( struct V_9 ) , V_347 ) ;
if ( V_94 ) {
V_94 -> V_74 = NULL ;
V_94 -> V_348 = F_172 ;
F_171 ( & V_349 ) ;
}
return V_94 ;
}
void F_7 ( struct V_9 * V_10 )
{
if ( V_10 -> V_74 )
F_25 ( & V_10 -> V_74 -> V_32 , F_50 ) ;
V_10 -> V_348 ( V_10 ) ;
}
static void F_173 ( struct V_13 * V_10 )
{
}
static void F_174 ( struct V_9 * V_10 )
{
}
static void F_175 ( T_1 V_14 , struct V_9 * V_10 )
{
if ( ( V_10 -> V_2 . V_3 == V_55 )
&& ( V_10 -> V_10 . V_86 == V_350 )
&& ( V_10 -> V_10 . V_100 == V_351 )
&& ( V_10 -> V_10 . V_88 [ 0 ] == V_352 ) ) {
V_14 -> V_353 = V_10 -> V_10 . V_88 [ 1 ] ;
V_14 -> V_354 = V_10 -> V_10 . V_88 [ 2 ] & 0x3 ;
}
}
static void F_176 ( T_1 V_14 , struct V_9 * V_10 )
{
if ( ( V_10 -> V_2 . V_3 == V_55 )
&& ( V_10 -> V_10 . V_86 == V_292 )
&& ( V_10 -> V_10 . V_100 == V_355 )
&& ( V_10 -> V_10 . V_88 [ 0 ] == V_352 ) ) {
V_14 -> V_356 = ( V_10 -> V_10 . V_88 [ 6 ] >> 2 ) & 1 ;
V_14 -> V_357 = ( V_10 -> V_10 . V_88 [ 6 ] >> 5 ) & 1 ;
}
}
static void F_177 ( char * V_358 )
{
struct V_159 V_10 ;
T_1 V_14 ;
unsigned char V_88 [ 16 ] ;
struct V_56 * V_290 ;
struct V_1 V_2 ;
struct V_13 V_158 ;
struct V_9 V_28 ;
V_290 = (struct V_56 * ) & V_2 ;
V_290 -> V_3 = V_55 ;
V_290 -> V_54 = V_72 ;
V_290 -> V_59 = 0 ;
V_10 . V_86 = 0x04 ;
V_10 . V_100 = 2 ;
V_10 . V_88 = V_88 ;
V_10 . V_87 = 8 ;
V_88 [ 0 ] = 0x41 ;
V_88 [ 1 ] = 0x03 ;
V_88 [ 2 ] = 0x20 ;
V_88 [ 4 ] = 0x6f ;
V_88 [ 5 ] = 0xa1 ;
if ( V_358 ) {
V_88 [ 3 ] = V_358 [ 0 ] ;
V_88 [ 6 ] = V_358 [ 1 ] ;
V_88 [ 7 ] = V_358 [ 2 ] ;
}
V_158 . V_348 = F_173 ;
V_28 . V_348 = F_174 ;
F_46 (intf, &ipmi_interfaces, link) {
if ( ! V_14 -> V_113 )
continue;
V_14 -> V_327 = 1 ;
V_14 -> V_113 -> V_359 ( V_14 -> V_116 , 1 ) ;
F_72 ( NULL ,
V_14 ,
& V_2 ,
0 ,
& V_10 ,
V_14 ,
& V_158 ,
& V_28 ,
0 ,
V_14 -> V_132 [ 0 ] . V_131 ,
V_14 -> V_132 [ 0 ] . V_59 ,
0 , 1 ) ;
}
#ifdef F_178
if ( ! V_358 )
return;
F_46 (intf, &ipmi_interfaces, link) {
char * V_360 = V_358 ;
struct V_60 * V_361 ;
int V_302 ;
if ( V_14 -> V_41 == - 1 )
continue;
F_179 () ;
V_14 -> V_356 = 0 ;
V_14 -> V_357 = 0 ;
V_14 -> V_353 = 0 ;
V_10 . V_86 = V_164 ;
V_10 . V_100 = V_355 ;
V_10 . V_88 = NULL ;
V_10 . V_87 = 0 ;
V_14 -> V_76 = F_176 ;
F_72 ( NULL ,
V_14 ,
& V_2 ,
0 ,
& V_10 ,
V_14 ,
& V_158 ,
& V_28 ,
0 ,
V_14 -> V_132 [ 0 ] . V_131 ,
V_14 -> V_132 [ 0 ] . V_59 ,
0 , 1 ) ;
if ( V_14 -> V_357 ) {
V_10 . V_86 = V_362 ;
V_10 . V_100 = V_351 ;
V_10 . V_88 = NULL ;
V_10 . V_87 = 0 ;
V_14 -> V_76 = F_175 ;
F_72 ( NULL ,
V_14 ,
& V_2 ,
0 ,
& V_10 ,
V_14 ,
& V_158 ,
& V_28 ,
0 ,
V_14 -> V_132 [ 0 ] . V_131 ,
V_14 -> V_132 [ 0 ] . V_59 ,
0 , 1 ) ;
}
V_14 -> V_76 = NULL ;
if ( ( ( V_14 -> V_353 & 1 ) == 0 )
&& ( V_14 -> V_353 != 0 )
&& ( V_14 -> V_353 != V_14 -> V_132 [ 0 ] . V_131 ) ) {
V_361 = (struct V_60 * ) & V_2 ;
V_361 -> V_3 = V_5 ;
V_361 -> V_54 = 0 ;
V_361 -> V_59 = V_14 -> V_354 ;
V_361 -> V_63 = V_14 -> V_353 ;
} else if ( V_14 -> V_356 ) {
V_290 = (struct V_56 * ) & V_2 ;
V_290 -> V_3 = V_55 ;
V_290 -> V_54 = V_72 ;
V_290 -> V_59 = 0 ;
} else
continue;
V_10 . V_86 = V_363 ;
V_10 . V_100 = V_364 ;
V_10 . V_88 = V_88 ;
V_10 . V_87 = 16 ;
V_302 = 0 ;
while ( * V_360 ) {
int V_156 = strlen ( V_360 ) ;
if ( V_156 > 11 )
V_156 = 11 ;
V_88 [ 0 ] = 0 ;
V_88 [ 1 ] = 0 ;
V_88 [ 2 ] = 0xf0 ;
V_88 [ 3 ] = V_14 -> V_132 [ 0 ] . V_131 ;
V_88 [ 4 ] = V_302 ++ ;
strncpy ( V_88 + 5 , V_360 , 11 ) ;
V_360 += V_156 ;
F_72 ( NULL ,
V_14 ,
& V_2 ,
0 ,
& V_10 ,
V_14 ,
& V_158 ,
& V_28 ,
0 ,
V_14 -> V_132 [ 0 ] . V_131 ,
V_14 -> V_132 [ 0 ] . V_59 ,
0 , 1 ) ;
}
}
#endif
}
static int F_180 ( struct V_365 * V_366 ,
unsigned long V_367 ,
void * V_368 )
{
T_1 V_14 ;
if ( V_369 )
return V_370 ;
V_369 = 1 ;
F_46 (intf, &ipmi_interfaces, link) {
if ( ! V_14 -> V_113 )
continue;
V_14 -> V_327 = 1 ;
V_14 -> V_113 -> V_359 ( V_14 -> V_116 , 1 ) ;
}
#ifdef F_181
F_177 ( V_368 ) ;
#endif
return V_370 ;
}
static int F_45 ( void )
{
int V_94 ;
if ( V_109 )
return 0 ;
V_94 = F_182 ( & V_284 . V_285 ) ;
if ( V_94 ) {
F_64 (KERN_ERR PFX L_94 ) ;
return V_94 ;
}
F_64 ( V_286 L_95
V_371 L_4 ) ;
#ifdef F_94
V_234 = F_97 ( L_96 , NULL ) ;
if ( ! V_234 ) {
F_64 (KERN_ERR PFX L_97 ) ;
return - V_47 ;
}
#endif
F_183 ( & V_343 , F_166 , 0 ) ;
F_168 ( & V_343 , V_344 + V_345 ) ;
F_184 ( & V_372 , & V_373 ) ;
V_109 = 1 ;
return 0 ;
}
static int T_4 F_185 ( void )
{
F_45 () ;
return 0 ;
}
static void T_5 F_186 ( void )
{
int V_374 ;
if ( ! V_109 )
return;
F_187 ( & V_372 , & V_373 ) ;
F_171 ( & V_339 ) ;
F_188 ( & V_343 ) ;
#ifdef F_94
F_99 ( V_234 -> V_223 , NULL ) ;
#endif
F_189 ( & V_284 . V_285 ) ;
V_109 = 0 ;
V_374 = F_167 ( & V_346 ) ;
if ( V_374 != 0 )
F_64 (KERN_WARNING PFX L_98 ,
count) ;
V_374 = F_167 ( & V_349 ) ;
if ( V_374 != 0 )
F_64 (KERN_WARNING PFX L_99 ,
count) ;
}
