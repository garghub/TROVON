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
F_11 ( & V_14 -> V_20 ) ;
F_8 ( & V_14 -> V_21 ) ;
F_4 ( & V_14 -> V_22 ) ;
F_12 ( & V_14 -> V_23 ) ;
F_13 ( & V_19 ) ;
F_14 ( & V_14 -> V_24 , & V_19 , V_25 ) ;
F_15 ( & V_14 -> V_23 ) ;
F_5 (rcvr, rcvr2, &list, link)
F_16 ( V_17 ) ;
for ( V_15 = 0 ; V_15 < V_26 ; V_15 ++ ) {
if ( ( V_14 -> V_27 [ V_15 ] . V_28 )
&& ( V_14 -> V_27 [ V_15 ] . V_29 ) )
F_7 ( V_14 -> V_27 [ V_15 ] . V_29 ) ;
}
}
static void F_17 ( struct V_30 * V_31 )
{
T_1 V_14 = F_18 ( V_31 , struct V_32 , V_33 ) ;
F_10 ( V_14 ) ;
F_16 ( V_14 ) ;
}
int F_19 ( struct V_34 * V_35 )
{
T_1 V_14 ;
F_20 ( V_36 ) ;
struct V_37 * V_38 , * V_39 ;
F_12 ( & V_40 ) ;
F_12 ( & V_41 ) ;
F_21 (intf, &ipmi_interfaces, link) {
if ( V_14 -> V_42 == - 1 )
continue;
V_38 = F_22 ( sizeof( * V_38 ) , V_43 ) ;
if ( ! V_38 )
goto V_44;
F_23 ( & V_14 -> V_33 ) ;
V_38 -> V_14 = V_14 ;
V_38 -> V_42 = V_14 -> V_42 ;
F_24 ( & V_38 -> V_12 , & V_36 ) ;
}
F_25 ( & V_35 -> V_12 , & V_45 ) ;
F_15 ( & V_41 ) ;
F_5 (e, e2, &to_deliver, link) {
F_6 ( & V_38 -> V_12 ) ;
V_35 -> V_46 ( V_38 -> V_42 , V_38 -> V_14 -> V_47 ) ;
F_26 ( & V_38 -> V_14 -> V_33 , F_17 ) ;
F_16 ( V_38 ) ;
}
F_15 ( & V_40 ) ;
return 0 ;
V_44:
F_15 ( & V_41 ) ;
F_15 ( & V_40 ) ;
F_5 (e, e2, &to_deliver, link) {
F_6 ( & V_38 -> V_12 ) ;
F_26 ( & V_38 -> V_14 -> V_33 , F_17 ) ;
F_16 ( V_38 ) ;
}
return - V_48 ;
}
int F_27 ( struct V_34 * V_35 )
{
F_12 ( & V_40 ) ;
F_6 ( & ( V_35 -> V_12 ) ) ;
F_15 ( & V_40 ) ;
return 0 ;
}
static void
F_28 ( int V_15 , struct V_49 * V_50 )
{
struct V_34 * V_51 ;
F_21 (w, &smi_watchers, link) {
if ( F_29 ( V_51 -> V_52 ) ) {
V_51 -> V_46 ( V_15 , V_50 ) ;
F_30 ( V_51 -> V_52 ) ;
}
}
}
static int
F_31 ( struct V_1 * V_53 , struct V_1 * V_54 )
{
if ( V_53 -> V_3 != V_54 -> V_3 )
return 0 ;
if ( V_53 -> V_55 != V_54 -> V_55 )
return 0 ;
if ( V_53 -> V_3 == V_56 ) {
struct V_57 * V_58
= (struct V_57 * ) V_53 ;
struct V_57 * V_59
= (struct V_57 * ) V_54 ;
return ( V_58 -> V_60 == V_59 -> V_60 ) ;
}
if ( F_2 ( V_53 ) || F_3 ( V_53 ) ) {
struct V_61 * V_62
= (struct V_61 * ) V_53 ;
struct V_61 * V_63
= (struct V_61 * ) V_54 ;
return ( ( V_62 -> V_64 == V_63 -> V_64 )
&& ( V_62 -> V_60 == V_63 -> V_60 ) ) ;
}
if ( F_1 ( V_53 ) ) {
struct V_65 * V_66
= (struct V_65 * ) V_53 ;
struct V_65 * V_67
= (struct V_65 * ) V_54 ;
return ( ( V_66 -> V_68 == V_67 -> V_68 )
&& ( V_66 -> V_69 == V_67 -> V_69 )
&& ( V_66 -> V_70
== V_67 -> V_70 )
&& ( V_66 -> V_60 == V_67 -> V_60 ) ) ;
}
return 1 ;
}
int F_32 ( struct V_1 * V_2 , int V_71 )
{
if ( V_71 < sizeof( struct V_57 ) )
return - V_72 ;
if ( V_2 -> V_3 == V_56 ) {
if ( V_2 -> V_55 != V_73 )
return - V_72 ;
return 0 ;
}
if ( ( V_2 -> V_55 == V_73 )
|| ( V_2 -> V_55 >= V_74 )
|| ( V_2 -> V_55 < 0 ) )
return - V_72 ;
if ( F_2 ( V_2 ) || F_3 ( V_2 ) ) {
if ( V_71 < sizeof( struct V_61 ) )
return - V_72 ;
return 0 ;
}
if ( F_1 ( V_2 ) ) {
if ( V_71 < sizeof( struct V_65 ) )
return - V_72 ;
return 0 ;
}
return - V_72 ;
}
unsigned int F_33 ( int V_3 )
{
if ( V_3 == V_56 )
return sizeof( struct V_57 ) ;
if ( ( V_3 == V_5 )
|| ( V_3 == V_6 ) )
return sizeof( struct V_61 ) ;
if ( V_3 == V_4 )
return sizeof( struct V_65 ) ;
return 0 ;
}
static void F_34 ( struct V_9 * V_10 )
{
if ( ! V_10 -> V_75 ) {
T_1 V_14 = V_10 -> V_76 ;
if ( V_14 -> V_77 ) {
V_14 -> V_77 ( V_14 , V_10 ) ;
F_35 ( V_14 , V_78 ) ;
} else {
F_35 ( V_14 , V_79 ) ;
}
F_7 ( V_10 ) ;
} else {
T_2 V_75 = V_10 -> V_75 ;
V_75 -> V_80 -> V_81 ( V_10 , V_75 -> V_82 ) ;
}
}
static void
F_36 ( struct V_9 * V_10 , int V_83 )
{
V_10 -> V_84 = V_85 ;
V_10 -> V_86 [ 0 ] = V_83 ;
V_10 -> V_10 . V_87 |= 1 ;
V_10 -> V_10 . V_88 = 1 ;
V_10 -> V_10 . V_89 = V_10 -> V_86 ;
F_34 ( V_10 ) ;
}
static int F_37 ( T_1 V_14 ,
struct V_9 * V_29 ,
unsigned long V_90 ,
int V_91 ,
int V_92 ,
unsigned char * V_93 ,
long * V_94 )
{
int V_95 = 0 ;
unsigned int V_15 ;
for ( V_15 = V_14 -> V_96 ; ( V_15 + 1 ) % V_26 != V_14 -> V_96 ;
V_15 = ( V_15 + 1 ) % V_26 ) {
if ( ! V_14 -> V_27 [ V_15 ] . V_28 )
break;
}
if ( ! V_14 -> V_27 [ V_15 ] . V_28 ) {
V_14 -> V_27 [ V_15 ] . V_29 = V_29 ;
V_14 -> V_27 [ V_15 ] . V_90 = V_97 ;
V_14 -> V_27 [ V_15 ] . V_98 = V_90 ;
V_14 -> V_27 [ V_15 ] . V_99 = V_91 ;
V_14 -> V_27 [ V_15 ] . V_92 = V_92 ;
V_14 -> V_27 [ V_15 ] . V_28 = 1 ;
V_14 -> V_27 [ V_15 ] . V_94 = F_38 ( V_14 -> V_27 [ V_15 ] . V_94 ) ;
* V_93 = V_15 ;
* V_94 = V_14 -> V_27 [ V_15 ] . V_94 ;
V_14 -> V_96 = ( V_15 + 1 ) % V_26 ;
} else {
V_95 = - V_100 ;
}
return V_95 ;
}
static int F_39 ( T_1 V_14 ,
unsigned char V_93 ,
short V_55 ,
unsigned char V_101 ,
unsigned char V_87 ,
struct V_1 * V_2 ,
struct V_9 * * V_29 )
{
int V_95 = - V_102 ;
unsigned long V_103 ;
if ( V_93 >= V_26 )
return - V_72 ;
F_40 ( & ( V_14 -> V_104 ) , V_103 ) ;
if ( V_14 -> V_27 [ V_93 ] . V_28 ) {
struct V_9 * V_10 = V_14 -> V_27 [ V_93 ] . V_29 ;
if ( ( V_10 -> V_2 . V_55 == V_55 ) && ( V_10 -> V_10 . V_101 == V_101 )
&& ( V_10 -> V_10 . V_87 == V_87 )
&& ( F_31 ( V_2 , & ( V_10 -> V_2 ) ) ) ) {
* V_29 = V_10 ;
V_14 -> V_27 [ V_93 ] . V_28 = 0 ;
V_95 = 0 ;
}
}
F_41 ( & ( V_14 -> V_104 ) , V_103 ) ;
return V_95 ;
}
static int F_42 ( T_1 V_14 ,
long V_105 )
{
int V_95 = - V_102 ;
unsigned long V_103 ;
unsigned char V_93 ;
unsigned long V_94 ;
F_43 ( V_105 , V_93 , V_94 ) ;
F_40 ( & ( V_14 -> V_104 ) , V_103 ) ;
if ( ( V_14 -> V_27 [ V_93 ] . V_28 )
&& ( V_14 -> V_27 [ V_93 ] . V_94 == V_94 ) ) {
struct V_27 * V_106 = & ( V_14 -> V_27 [ V_93 ] ) ;
V_106 -> V_90 = V_106 -> V_98 ;
V_95 = 0 ;
}
F_41 ( & ( V_14 -> V_104 ) , V_103 ) ;
return V_95 ;
}
static int F_44 ( T_1 V_14 ,
long V_105 ,
unsigned int V_83 )
{
int V_95 = - V_102 ;
unsigned long V_103 ;
unsigned char V_93 ;
unsigned long V_94 ;
struct V_9 * V_10 = NULL ;
F_43 ( V_105 , V_93 , V_94 ) ;
F_40 ( & ( V_14 -> V_104 ) , V_103 ) ;
if ( ( V_14 -> V_27 [ V_93 ] . V_28 )
&& ( V_14 -> V_27 [ V_93 ] . V_94 == V_94 ) ) {
struct V_27 * V_106 = & ( V_14 -> V_27 [ V_93 ] ) ;
V_106 -> V_28 = 0 ;
V_10 = V_106 -> V_29 ;
V_95 = 0 ;
}
F_41 ( & ( V_14 -> V_104 ) , V_103 ) ;
if ( V_10 )
F_36 ( V_10 , V_83 ) ;
return V_95 ;
}
int F_45 ( unsigned int V_107 ,
struct V_108 * V_80 ,
void * V_82 ,
T_2 * V_75 )
{
unsigned long V_103 ;
T_2 V_109 ;
int V_95 = 0 ;
T_1 V_14 ;
if ( V_80 == NULL )
return - V_72 ;
if ( ! V_110 ) {
V_95 = F_46 () ;
if ( V_95 )
return V_95 ;
if ( ! V_110 )
return - V_102 ;
}
V_109 = F_22 ( sizeof( * V_109 ) , V_43 ) ;
if ( ! V_109 )
return - V_48 ;
F_12 ( & V_41 ) ;
F_47 (intf, &ipmi_interfaces, link) {
if ( V_14 -> V_42 == V_107 )
goto V_111;
}
V_95 = - V_72 ;
goto V_112;
V_111:
F_23 ( & V_14 -> V_33 ) ;
F_48 ( & V_109 -> V_33 ) ;
V_109 -> V_80 = V_80 ;
V_109 -> V_82 = V_82 ;
V_109 -> V_14 = V_14 ;
V_109 -> V_113 = 0 ;
if ( ! F_29 ( V_14 -> V_114 -> V_52 ) ) {
V_95 = - V_102 ;
goto V_115;
}
if ( V_14 -> V_114 -> V_116 ) {
V_95 = V_14 -> V_114 -> V_116 ( V_14 -> V_117 ) ;
if ( V_95 ) {
F_30 ( V_14 -> V_114 -> V_52 ) ;
goto V_115;
}
}
F_15 ( & V_41 ) ;
V_109 -> V_118 = 1 ;
F_40 ( & V_14 -> V_104 , V_103 ) ;
F_49 ( & V_109 -> V_12 , & V_14 -> V_119 ) ;
F_41 ( & V_14 -> V_104 , V_103 ) ;
* V_75 = V_109 ;
return 0 ;
V_115:
F_26 ( & V_14 -> V_33 , F_17 ) ;
V_112:
F_15 ( & V_41 ) ;
F_16 ( V_109 ) ;
return V_95 ;
}
int F_50 ( int V_107 , struct V_120 * V_89 )
{
int V_95 = 0 ;
T_1 V_14 ;
struct V_121 * V_114 ;
F_12 ( & V_41 ) ;
F_47 (intf, &ipmi_interfaces, link) {
if ( V_14 -> V_42 == V_107 )
goto V_111;
}
V_95 = - V_72 ;
F_15 ( & V_41 ) ;
return V_95 ;
V_111:
V_114 = V_14 -> V_114 ;
V_95 = - V_122 ;
if ( V_114 -> V_123 )
V_95 = V_114 -> V_123 ( V_14 -> V_117 , V_89 ) ;
F_15 ( & V_41 ) ;
return V_95 ;
}
static void F_51 ( struct V_30 * V_31 )
{
T_2 V_75 = F_18 ( V_31 , struct V_124 , V_33 ) ;
F_16 ( V_75 ) ;
}
int F_52 ( T_2 V_75 )
{
T_1 V_14 = V_75 -> V_14 ;
int V_15 ;
unsigned long V_103 ;
struct V_16 * V_17 ;
struct V_16 * V_125 = NULL ;
V_75 -> V_118 = 0 ;
F_40 ( & V_14 -> V_104 , V_103 ) ;
F_53 ( & V_75 -> V_12 ) ;
for ( V_15 = 0 ; V_15 < V_26 ; V_15 ++ ) {
if ( V_14 -> V_27 [ V_15 ] . V_28
&& ( V_14 -> V_27 [ V_15 ] . V_29 -> V_75 == V_75 ) ) {
V_14 -> V_27 [ V_15 ] . V_28 = 0 ;
F_7 ( V_14 -> V_27 [ V_15 ] . V_29 ) ;
}
}
F_41 ( & V_14 -> V_104 , V_103 ) ;
F_12 ( & V_14 -> V_23 ) ;
F_47 (rcvr, &intf->cmd_rcvrs, link) {
if ( V_17 -> V_75 == V_75 ) {
F_53 ( & V_17 -> V_12 ) ;
V_17 -> V_126 = V_125 ;
V_125 = V_17 ;
}
}
F_15 ( & V_14 -> V_23 ) ;
V_25 () ;
while ( V_125 ) {
V_17 = V_125 ;
V_125 = V_17 -> V_126 ;
F_16 ( V_17 ) ;
}
F_12 ( & V_41 ) ;
if ( V_14 -> V_114 ) {
F_30 ( V_14 -> V_114 -> V_52 ) ;
if ( V_14 -> V_114 -> V_127 )
V_14 -> V_114 -> V_127 ( V_14 -> V_117 ) ;
}
F_15 ( & V_41 ) ;
F_26 ( & V_14 -> V_33 , F_17 ) ;
F_26 ( & V_75 -> V_33 , F_51 ) ;
return 0 ;
}
void F_54 ( T_2 V_75 ,
unsigned char * V_128 ,
unsigned char * V_129 )
{
* V_128 = V_75 -> V_14 -> V_130 ;
* V_129 = V_75 -> V_14 -> V_131 ;
}
int F_55 ( T_2 V_75 ,
unsigned int V_55 ,
unsigned char V_132 )
{
if ( V_55 >= V_74 )
return - V_72 ;
V_75 -> V_14 -> V_133 [ V_55 ] . V_132 = V_132 ;
return 0 ;
}
int F_56 ( T_2 V_75 ,
unsigned int V_55 ,
unsigned char * V_132 )
{
if ( V_55 >= V_74 )
return - V_72 ;
* V_132 = V_75 -> V_14 -> V_133 [ V_55 ] . V_132 ;
return 0 ;
}
int F_57 ( T_2 V_75 ,
unsigned int V_55 ,
unsigned char V_134 )
{
if ( V_55 >= V_74 )
return - V_72 ;
V_75 -> V_14 -> V_133 [ V_55 ] . V_60 = V_134 & 0x3 ;
return 0 ;
}
int F_58 ( T_2 V_75 ,
unsigned int V_55 ,
unsigned char * V_132 )
{
if ( V_55 >= V_74 )
return - V_72 ;
* V_132 = V_75 -> V_14 -> V_133 [ V_55 ] . V_60 ;
return 0 ;
}
int F_59 ( T_2 V_75 )
{
int V_135 ;
unsigned long V_103 ;
F_40 ( & V_75 -> V_14 -> V_136 , V_103 ) ;
V_135 = V_75 -> V_14 -> V_137 ;
F_41 ( & V_75 -> V_14 -> V_136 , V_103 ) ;
return V_135 ;
}
static void F_60 ( T_1 V_14 )
{
if ( V_14 -> V_114 -> V_138 )
V_14 -> V_114 -> V_138 (
V_14 -> V_117 , V_14 -> V_139 ) ;
}
int F_61 ( T_2 V_75 , int V_135 )
{
int V_95 = 0 ;
unsigned long V_103 ;
T_1 V_14 = V_75 -> V_14 ;
F_40 ( & V_14 -> V_136 , V_103 ) ;
if ( V_14 -> V_137 != V_135 ) {
switch ( V_135 ) {
case V_140 :
V_14 -> V_137 = V_135 ;
V_14 -> V_139
= ( V_14 -> V_141 > 0 ) ;
break;
case V_142 :
V_14 -> V_137 = V_135 ;
V_14 -> V_139 = 0 ;
break;
case V_143 :
V_14 -> V_137 = V_135 ;
V_14 -> V_139 = 1 ;
break;
default:
V_95 = - V_72 ;
goto V_144;
}
F_60 ( V_14 ) ;
}
V_144:
F_41 ( & V_14 -> V_136 , V_103 ) ;
return V_95 ;
}
int F_62 ( T_2 V_75 , int V_145 )
{
unsigned long V_103 ;
T_1 V_14 = V_75 -> V_14 ;
struct V_9 * V_10 , * V_11 ;
struct V_7 V_146 ;
F_13 ( & V_146 ) ;
F_40 ( & V_14 -> V_147 , V_103 ) ;
V_75 -> V_113 = V_145 ;
if ( V_14 -> V_148 )
goto V_149;
while ( V_75 -> V_113 && ! F_63 ( & V_14 -> V_22 ) ) {
F_5 (msg, msg2, &intf->waiting_events, link)
F_64 ( & V_10 -> V_12 , & V_146 ) ;
V_14 -> V_150 = 0 ;
if ( V_14 -> V_151 ) {
F_65 (KERN_WARNING PFX L_1
L_2 ) ;
V_14 -> V_151 = 0 ;
}
V_14 -> V_148 = 1 ;
F_41 ( & V_14 -> V_147 , V_103 ) ;
F_5 (msg, msg2, &msgs, link) {
V_10 -> V_75 = V_75 ;
F_23 ( & V_75 -> V_33 ) ;
F_34 ( V_10 ) ;
}
F_40 ( & V_14 -> V_147 , V_103 ) ;
V_14 -> V_148 = 0 ;
}
V_149:
F_41 ( & V_14 -> V_147 , V_103 ) ;
return 0 ;
}
static struct V_16 * F_66 ( T_1 V_14 ,
unsigned char V_87 ,
unsigned char V_101 ,
unsigned char V_152 )
{
struct V_16 * V_17 ;
F_47 (rcvr, &intf->cmd_rcvrs, link) {
if ( ( V_17 -> V_87 == V_87 ) && ( V_17 -> V_101 == V_101 )
&& ( V_17 -> V_153 & ( 1 << V_152 ) ) )
return V_17 ;
}
return NULL ;
}
static int F_67 ( T_1 V_14 ,
unsigned char V_87 ,
unsigned char V_101 ,
unsigned int V_153 )
{
struct V_16 * V_17 ;
F_47 (rcvr, &intf->cmd_rcvrs, link) {
if ( ( V_17 -> V_87 == V_87 ) && ( V_17 -> V_101 == V_101 )
&& ( V_17 -> V_153 & V_153 ) )
return 0 ;
}
return 1 ;
}
int F_68 ( T_2 V_75 ,
unsigned char V_87 ,
unsigned char V_101 ,
unsigned int V_153 )
{
T_1 V_14 = V_75 -> V_14 ;
struct V_16 * V_17 ;
int V_95 = 0 ;
V_17 = F_22 ( sizeof( * V_17 ) , V_43 ) ;
if ( ! V_17 )
return - V_48 ;
V_17 -> V_101 = V_101 ;
V_17 -> V_87 = V_87 ;
V_17 -> V_153 = V_153 ;
V_17 -> V_75 = V_75 ;
F_12 ( & V_14 -> V_23 ) ;
if ( ! F_67 ( V_14 , V_87 , V_101 , V_153 ) ) {
V_95 = - V_154 ;
goto V_144;
}
F_49 ( & V_17 -> V_12 , & V_14 -> V_24 ) ;
V_144:
F_15 ( & V_14 -> V_23 ) ;
if ( V_95 )
F_16 ( V_17 ) ;
return V_95 ;
}
int F_69 ( T_2 V_75 ,
unsigned char V_87 ,
unsigned char V_101 ,
unsigned int V_153 )
{
T_1 V_14 = V_75 -> V_14 ;
struct V_16 * V_17 ;
struct V_16 * V_125 = NULL ;
int V_15 , V_95 = - V_155 ;
F_12 ( & V_14 -> V_23 ) ;
for ( V_15 = 0 ; V_15 < V_156 ; V_15 ++ ) {
if ( ( ( 1 << V_15 ) & V_153 ) == 0 )
continue;
V_17 = F_66 ( V_14 , V_87 , V_101 , V_15 ) ;
if ( V_17 == NULL )
continue;
if ( V_17 -> V_75 == V_75 ) {
V_95 = 0 ;
V_17 -> V_153 &= ~ V_153 ;
if ( V_17 -> V_153 == 0 ) {
F_53 ( & V_17 -> V_12 ) ;
V_17 -> V_126 = V_125 ;
V_125 = V_17 ;
}
}
}
F_15 ( & V_14 -> V_23 ) ;
V_25 () ;
while ( V_125 ) {
V_17 = V_125 ;
V_125 = V_17 -> V_126 ;
F_16 ( V_17 ) ;
}
return V_95 ;
}
static unsigned char
F_70 ( unsigned char * V_89 , int V_157 )
{
unsigned char V_158 = 0 ;
for (; V_157 > 0 ; V_157 -- , V_89 ++ )
V_158 += * V_89 ;
return - V_158 ;
}
static inline void F_71 ( struct V_13 * V_159 ,
struct V_160 * V_10 ,
struct V_61 * V_161 ,
long V_105 ,
unsigned char V_162 ,
int V_92 ,
unsigned char V_163 ,
unsigned char V_164 )
{
int V_15 = V_92 ;
V_159 -> V_89 [ 0 ] = ( V_165 << 2 ) ;
V_159 -> V_89 [ 1 ] = V_166 ;
V_159 -> V_89 [ 2 ] = V_161 -> V_55 ;
if ( V_92 )
V_159 -> V_89 [ 3 ] = 0 ;
V_159 -> V_89 [ V_15 + 3 ] = V_161 -> V_64 ;
V_159 -> V_89 [ V_15 + 4 ] = ( V_10 -> V_87 << 2 ) | ( V_161 -> V_60 & 0x3 ) ;
V_159 -> V_89 [ V_15 + 5 ] = F_70 ( & ( V_159 -> V_89 [ V_15 + 3 ] ) , 2 ) ;
V_159 -> V_89 [ V_15 + 6 ] = V_163 ;
V_159 -> V_89 [ V_15 + 7 ] = ( V_162 << 2 ) | V_164 ;
V_159 -> V_89 [ V_15 + 8 ] = V_10 -> V_101 ;
if ( V_10 -> V_88 > 0 )
memcpy ( & ( V_159 -> V_89 [ V_15 + 9 ] ) , V_10 -> V_89 ,
V_10 -> V_88 ) ;
V_159 -> V_167 = V_10 -> V_88 + 9 ;
V_159 -> V_89 [ V_15 + V_159 -> V_167 ]
= F_70 ( & ( V_159 -> V_89 [ V_15 + 6 ] ) ,
V_159 -> V_167 - 6 ) ;
V_159 -> V_167 += 1 + V_15 ;
V_159 -> V_105 = V_105 ;
}
static inline void F_72 ( struct V_13 * V_159 ,
struct V_160 * V_10 ,
struct V_65 * V_168 ,
long V_105 ,
unsigned char V_162 ,
unsigned char V_164 )
{
V_159 -> V_89 [ 0 ] = ( V_165 << 2 ) ;
V_159 -> V_89 [ 1 ] = V_166 ;
V_159 -> V_89 [ 2 ] = V_168 -> V_55 ;
V_159 -> V_89 [ 3 ] = V_168 -> V_70 ;
V_159 -> V_89 [ 4 ] = V_168 -> V_68 ;
V_159 -> V_89 [ 5 ] = ( V_10 -> V_87 << 2 ) | ( V_168 -> V_60 & 0x3 ) ;
V_159 -> V_89 [ 6 ] = F_70 ( & ( V_159 -> V_89 [ 4 ] ) , 2 ) ;
V_159 -> V_89 [ 7 ] = V_168 -> V_69 ;
V_159 -> V_89 [ 8 ] = ( V_162 << 2 ) | V_164 ;
V_159 -> V_89 [ 9 ] = V_10 -> V_101 ;
if ( V_10 -> V_88 > 0 )
memcpy ( & ( V_159 -> V_89 [ 10 ] ) , V_10 -> V_89 ,
V_10 -> V_88 ) ;
V_159 -> V_167 = V_10 -> V_88 + 10 ;
V_159 -> V_89 [ V_159 -> V_167 ]
= F_70 ( & ( V_159 -> V_89 [ 7 ] ) ,
V_159 -> V_167 - 7 ) ;
V_159 -> V_167 += 1 ;
V_159 -> V_105 = V_105 ;
}
static int F_73 ( T_2 V_75 ,
T_1 V_14 ,
struct V_1 * V_2 ,
long V_105 ,
struct V_160 * V_10 ,
void * V_76 ,
void * V_169 ,
struct V_9 * V_170 ,
int V_171 ,
unsigned char V_163 ,
unsigned char V_164 ,
int V_91 ,
unsigned int V_172 )
{
int V_95 = 0 ;
struct V_13 * V_159 ;
struct V_9 * V_29 ;
unsigned long V_103 ;
struct V_121 * V_114 ;
if ( V_170 )
V_29 = V_170 ;
else {
V_29 = F_74 () ;
if ( V_29 == NULL )
return - V_48 ;
}
V_29 -> V_76 = V_76 ;
if ( V_169 )
V_159 = (struct V_13 * ) V_169 ;
else {
V_159 = F_75 () ;
if ( V_159 == NULL ) {
F_7 ( V_29 ) ;
return - V_48 ;
}
}
F_76 () ;
V_114 = V_14 -> V_114 ;
if ( ! V_114 ) {
V_95 = - V_102 ;
goto V_44;
}
V_29 -> V_75 = V_75 ;
if ( V_75 )
F_23 ( & V_75 -> V_33 ) ;
V_29 -> V_105 = V_105 ;
V_29 -> V_10 = * V_10 ;
if ( V_2 -> V_3 == V_56 ) {
struct V_57 * V_173 ;
if ( V_10 -> V_87 & 1 ) {
V_95 = - V_72 ;
goto V_44;
}
V_173 = (struct V_57 * ) V_2 ;
if ( V_173 -> V_60 > 3 ) {
F_35 ( V_14 , V_174 ) ;
V_95 = - V_72 ;
goto V_44;
}
memcpy ( & V_29 -> V_2 , V_173 , sizeof( * V_173 ) ) ;
if ( ( V_10 -> V_87 == V_165 )
&& ( ( V_10 -> V_101 == V_166 )
|| ( V_10 -> V_101 == V_175 )
|| ( V_10 -> V_101 == V_176 ) ) ) {
F_35 ( V_14 , V_174 ) ;
V_95 = - V_72 ;
goto V_44;
}
if ( ( ( V_10 -> V_87 == V_165 )
&& ( ( V_10 -> V_101 == V_177 )
|| ( V_10 -> V_101 == V_178 ) ) )
|| ( V_10 -> V_87 == V_179 ) ) {
F_40 ( & V_14 -> V_136 , V_103 ) ;
V_14 -> V_141
= V_180 ;
if ( ! V_14 -> V_137
&& ! V_14 -> V_139 ) {
V_14 -> V_139 = 1 ;
F_60 ( V_14 ) ;
}
F_41 ( & V_14 -> V_136 ,
V_103 ) ;
}
if ( ( V_10 -> V_88 + 2 ) > V_181 ) {
F_35 ( V_14 , V_174 ) ;
V_95 = - V_182 ;
goto V_44;
}
V_159 -> V_89 [ 0 ] = ( V_10 -> V_87 << 2 ) | ( V_173 -> V_60 & 0x3 ) ;
V_159 -> V_89 [ 1 ] = V_10 -> V_101 ;
V_159 -> V_105 = V_105 ;
V_159 -> V_183 = V_29 ;
if ( V_10 -> V_88 > 0 )
memcpy ( & ( V_159 -> V_89 [ 2 ] ) , V_10 -> V_89 , V_10 -> V_88 ) ;
V_159 -> V_167 = V_10 -> V_88 + 2 ;
F_35 ( V_14 , V_184 ) ;
} else if ( F_2 ( V_2 ) || F_3 ( V_2 ) ) {
struct V_61 * V_161 ;
unsigned char V_162 ;
long V_94 ;
int V_92 = 0 ;
if ( V_2 -> V_55 >= V_74 ) {
F_35 ( V_14 , V_174 ) ;
V_95 = - V_72 ;
goto V_44;
}
if ( V_14 -> V_133 [ V_2 -> V_55 ] . V_185
!= V_186 ) {
F_35 ( V_14 , V_174 ) ;
V_95 = - V_72 ;
goto V_44;
}
if ( V_91 < 0 ) {
if ( V_2 -> V_3 == V_6 )
V_91 = 0 ;
else
V_91 = 4 ;
}
if ( V_2 -> V_3 == V_6 ) {
V_2 -> V_3 = V_5 ;
V_92 = 1 ;
}
if ( V_172 == 0 )
V_172 = 1000 ;
if ( ( V_10 -> V_88 + 10 + V_92 ) > V_181 ) {
F_35 ( V_14 , V_174 ) ;
V_95 = - V_182 ;
goto V_44;
}
V_161 = (struct V_61 * ) V_2 ;
if ( V_161 -> V_60 > 3 ) {
F_35 ( V_14 , V_174 ) ;
V_95 = - V_72 ;
goto V_44;
}
memcpy ( & V_29 -> V_2 , V_161 , sizeof( * V_161 ) ) ;
if ( V_29 -> V_10 . V_87 & 0x1 ) {
F_35 ( V_14 , V_187 ) ;
F_71 ( V_159 , V_10 , V_161 , V_105 ,
V_105 , V_92 ,
V_163 , V_164 ) ;
V_159 -> V_183 = V_29 ;
} else {
F_40 ( & ( V_14 -> V_104 ) , V_103 ) ;
V_95 = F_37 ( V_14 ,
V_29 ,
V_172 ,
V_91 ,
V_92 ,
& V_162 ,
& V_94 ) ;
if ( V_95 ) {
F_41 ( & ( V_14 -> V_104 ) ,
V_103 ) ;
goto V_44;
}
F_35 ( V_14 , V_188 ) ;
F_71 ( V_159 , V_10 , V_161 ,
F_77 ( V_162 , V_94 ) ,
V_162 , V_92 ,
V_163 , V_164 ) ;
memcpy ( V_29 -> V_86 , V_159 -> V_89 ,
V_159 -> V_167 ) ;
V_29 -> V_10 . V_89 = V_29 -> V_86 ;
V_29 -> V_10 . V_88 = V_159 -> V_167 ;
F_41 ( & ( V_14 -> V_104 ) , V_103 ) ;
}
} else if ( F_1 ( V_2 ) ) {
struct V_65 * V_168 ;
unsigned char V_162 ;
long V_94 ;
if ( V_2 -> V_55 >= V_74 ) {
F_35 ( V_14 , V_174 ) ;
V_95 = - V_72 ;
goto V_44;
}
if ( ( V_14 -> V_133 [ V_2 -> V_55 ] . V_185
!= V_189 )
&& ( V_14 -> V_133 [ V_2 -> V_55 ] . V_185
!= V_190 ) ) {
F_35 ( V_14 , V_174 ) ;
V_95 = - V_72 ;
goto V_44;
}
V_91 = 4 ;
if ( V_172 == 0 )
V_172 = 1000 ;
if ( ( V_10 -> V_88 + 12 ) > V_181 ) {
F_35 ( V_14 , V_174 ) ;
V_95 = - V_182 ;
goto V_44;
}
V_168 = (struct V_65 * ) V_2 ;
if ( V_168 -> V_60 > 3 ) {
F_35 ( V_14 , V_174 ) ;
V_95 = - V_72 ;
goto V_44;
}
memcpy ( & V_29 -> V_2 , V_168 , sizeof( * V_168 ) ) ;
if ( V_29 -> V_10 . V_87 & 0x1 ) {
F_35 ( V_14 , V_191 ) ;
F_72 ( V_159 , V_10 , V_168 , V_105 ,
V_105 , V_164 ) ;
V_159 -> V_183 = V_29 ;
} else {
F_40 ( & ( V_14 -> V_104 ) , V_103 ) ;
V_95 = F_37 ( V_14 ,
V_29 ,
V_172 ,
V_91 ,
0 ,
& V_162 ,
& V_94 ) ;
if ( V_95 ) {
F_41 ( & ( V_14 -> V_104 ) ,
V_103 ) ;
goto V_44;
}
F_35 ( V_14 , V_192 ) ;
F_72 ( V_159 , V_10 , V_168 ,
F_77 ( V_162 , V_94 ) ,
V_162 , V_164 ) ;
memcpy ( V_29 -> V_86 , V_159 -> V_89 ,
V_159 -> V_167 ) ;
V_29 -> V_10 . V_89 = V_29 -> V_86 ;
V_29 -> V_10 . V_88 = V_159 -> V_167 ;
F_41 ( & ( V_14 -> V_104 ) , V_103 ) ;
}
} else {
F_35 ( V_14 , V_174 ) ;
V_95 = - V_72 ;
goto V_44;
}
#ifdef F_78
{
int V_193 ;
for ( V_193 = 0 ; V_193 < V_159 -> V_167 ; V_193 ++ )
F_65 ( L_3 , V_159 -> V_89 [ V_193 ] ) ;
F_65 ( L_4 ) ;
}
#endif
V_114 -> V_194 ( V_14 -> V_117 , V_159 , V_171 ) ;
F_79 () ;
return 0 ;
V_44:
F_79 () ;
F_9 ( V_159 ) ;
F_7 ( V_29 ) ;
return V_95 ;
}
static int F_80 ( T_1 V_14 ,
struct V_1 * V_2 ,
unsigned char * V_195 ,
unsigned char * V_60 )
{
if ( V_2 -> V_55 >= V_74 )
return - V_72 ;
* V_60 = V_14 -> V_133 [ V_2 -> V_55 ] . V_60 ;
* V_195 = V_14 -> V_133 [ V_2 -> V_55 ] . V_132 ;
return 0 ;
}
int F_81 ( T_2 V_75 ,
struct V_1 * V_2 ,
long V_105 ,
struct V_160 * V_10 ,
void * V_76 ,
int V_171 ,
int V_91 ,
unsigned int V_172 )
{
unsigned char V_195 = 0 , V_60 = 0 ;
int V_95 ;
if ( ! V_75 )
return - V_72 ;
V_95 = F_80 ( V_75 -> V_14 , V_2 , & V_195 , & V_60 ) ;
if ( V_95 )
return V_95 ;
return F_73 ( V_75 ,
V_75 -> V_14 ,
V_2 ,
V_105 ,
V_10 ,
V_76 ,
NULL , NULL ,
V_171 ,
V_195 ,
V_60 ,
V_91 ,
V_172 ) ;
}
int F_82 ( T_2 V_75 ,
struct V_1 * V_2 ,
long V_105 ,
struct V_160 * V_10 ,
void * V_76 ,
void * V_169 ,
struct V_9 * V_170 ,
int V_171 )
{
unsigned char V_195 = 0 , V_60 = 0 ;
int V_95 ;
if ( ! V_75 )
return - V_72 ;
V_95 = F_80 ( V_75 -> V_14 , V_2 , & V_195 , & V_60 ) ;
if ( V_95 )
return V_95 ;
return F_73 ( V_75 ,
V_75 -> V_14 ,
V_2 ,
V_105 ,
V_10 ,
V_76 ,
V_169 ,
V_170 ,
V_171 ,
V_195 ,
V_60 ,
- 1 , 0 ) ;
}
static int F_83 ( struct V_196 * V_193 , void * V_197 )
{
T_1 V_14 = V_193 -> V_198 ;
int V_15 ;
F_84 ( V_193 , L_5 , V_14 -> V_133 [ 0 ] . V_132 ) ;
for ( V_15 = 1 ; V_15 < V_74 ; V_15 ++ )
F_84 ( V_193 , L_6 , V_14 -> V_133 [ V_15 ] . V_132 ) ;
return F_85 ( V_193 , '\n' ) ;
}
static int F_86 ( struct V_199 * V_199 , struct V_200 * V_200 )
{
return F_87 ( V_200 , F_83 , F_88 ( V_199 ) ) ;
}
static int F_89 ( struct V_196 * V_193 , void * V_197 )
{
T_1 V_14 = V_193 -> V_198 ;
return F_84 ( V_193 , L_7 ,
V_130 ( & V_14 -> V_201 -> V_202 ) ,
V_131 ( & V_14 -> V_201 -> V_202 ) ) ;
}
static int F_90 ( struct V_199 * V_199 , struct V_200 * V_200 )
{
return F_87 ( V_200 , F_89 , F_88 ( V_199 ) ) ;
}
static int F_91 ( struct V_196 * V_193 , void * V_197 )
{
T_1 V_14 = V_193 -> V_198 ;
F_84 ( V_193 , L_8 ,
F_92 ( V_14 , V_174 ) ) ;
F_84 ( V_193 , L_9 ,
F_92 ( V_14 , V_184 ) ) ;
F_84 ( V_193 , L_10 ,
F_92 ( V_14 , V_78 ) ) ;
F_84 ( V_193 , L_11 ,
F_92 ( V_14 , V_79 ) ) ;
F_84 ( V_193 , L_12 ,
F_92 ( V_14 , V_188 ) ) ;
F_84 ( V_193 , L_13 ,
F_92 ( V_14 , V_203 ) ) ;
F_84 ( V_193 , L_14 ,
F_92 ( V_14 , V_204 ) ) ;
F_84 ( V_193 , L_15 ,
F_92 ( V_14 , V_205 ) ) ;
F_84 ( V_193 , L_16 ,
F_92 ( V_14 , V_206 ) ) ;
F_84 ( V_193 , L_17 ,
F_92 ( V_14 , V_187 ) ) ;
F_84 ( V_193 , L_18 ,
F_92 ( V_14 , V_207 ) ) ;
F_84 ( V_193 , L_19 ,
F_92 ( V_14 , V_208 ) ) ;
F_84 ( V_193 , L_20 ,
F_92 ( V_14 , V_209 ) ) ;
F_84 ( V_193 , L_21 ,
F_92 ( V_14 , V_192 ) ) ;
F_84 ( V_193 , L_22 ,
F_92 ( V_14 , V_210 ) ) ;
F_84 ( V_193 , L_23 ,
F_92 ( V_14 , V_211 ) ) ;
F_84 ( V_193 , L_24 ,
F_92 ( V_14 , V_212 ) ) ;
F_84 ( V_193 , L_25 ,
F_92 ( V_14 , V_191 ) ) ;
F_84 ( V_193 , L_26 ,
F_92 ( V_14 , V_213 ) ) ;
F_84 ( V_193 , L_27 ,
F_92 ( V_14 , V_214 ) ) ;
F_84 ( V_193 , L_28 ,
F_92 ( V_14 , V_215 ) ) ;
F_84 ( V_193 , L_29 ,
F_92 ( V_14 , V_216 ) ) ;
F_84 ( V_193 , L_30 ,
F_92 ( V_14 , V_217 ) ) ;
F_84 ( V_193 , L_31 ,
F_92 ( V_14 , V_218 ) ) ;
F_84 ( V_193 , L_32 ,
F_92 ( V_14 , V_219 ) ) ;
F_84 ( V_193 , L_33 ,
F_92 ( V_14 , V_220 ) ) ;
F_84 ( V_193 , L_34 ,
F_92 ( V_14 , V_221 ) ) ;
F_84 ( V_193 , L_35 ,
F_92 ( V_14 , V_222 ) ) ;
return 0 ;
}
static int F_93 ( struct V_199 * V_199 , struct V_200 * V_200 )
{
return F_87 ( V_200 , F_91 , F_88 ( V_199 ) ) ;
}
int F_94 ( T_1 V_223 , char * V_224 ,
const struct V_225 * V_226 ,
void * V_89 )
{
int V_95 = 0 ;
#ifdef F_95
struct V_227 * V_200 ;
struct V_228 * V_229 ;
V_229 = F_22 ( sizeof( * V_229 ) , V_43 ) ;
if ( ! V_229 )
return - V_48 ;
V_229 -> V_224 = F_96 ( V_224 , V_43 ) ;
if ( ! V_229 -> V_224 ) {
F_16 ( V_229 ) ;
return - V_48 ;
}
V_200 = F_97 ( V_224 , 0 , V_223 -> V_230 , V_226 , V_89 ) ;
if ( ! V_200 ) {
F_16 ( V_229 -> V_224 ) ;
F_16 ( V_229 ) ;
V_95 = - V_48 ;
} else {
F_12 ( & V_223 -> V_231 ) ;
V_229 -> V_126 = V_223 -> V_232 ;
V_223 -> V_232 = V_229 ;
F_15 ( & V_223 -> V_231 ) ;
}
#endif
return V_95 ;
}
static int F_98 ( T_1 V_223 , int V_233 )
{
int V_95 = 0 ;
#ifdef F_95
sprintf ( V_223 -> V_234 , L_36 , V_233 ) ;
V_223 -> V_230 = F_99 ( V_223 -> V_234 , V_235 ) ;
if ( ! V_223 -> V_230 )
V_95 = - V_48 ;
if ( V_95 == 0 )
V_95 = F_94 ( V_223 , L_37 ,
& V_236 ,
V_223 ) ;
if ( V_95 == 0 )
V_95 = F_94 ( V_223 , L_38 ,
& V_237 ,
V_223 ) ;
if ( V_95 == 0 )
V_95 = F_94 ( V_223 , L_39 ,
& V_238 ,
V_223 ) ;
#endif
return V_95 ;
}
static void F_100 ( T_1 V_223 )
{
#ifdef F_95
struct V_228 * V_229 ;
F_12 ( & V_223 -> V_231 ) ;
while ( V_223 -> V_232 ) {
V_229 = V_223 -> V_232 ;
V_223 -> V_232 = V_229 -> V_126 ;
F_101 ( V_229 -> V_224 , V_223 -> V_230 ) ;
F_16 ( V_229 -> V_224 ) ;
F_16 ( V_229 ) ;
}
F_15 ( & V_223 -> V_231 ) ;
F_101 ( V_223 -> V_234 , V_235 ) ;
#endif
}
static int F_102 ( struct V_49 * V_50 , void * V_89 )
{
unsigned char * V_202 = V_89 ;
struct V_239 * V_201 = F_103 ( V_50 ) ;
return memcmp ( V_201 -> V_240 , V_202 , 16 ) == 0 ;
}
static struct V_239 * F_104 ( struct V_241 * V_242 ,
unsigned char * V_240 )
{
struct V_49 * V_50 ;
V_50 = F_105 ( V_242 , NULL , V_240 , F_102 ) ;
if ( V_50 )
return F_103 ( V_50 ) ;
else
return NULL ;
}
static int F_106 ( struct V_49 * V_50 , void * V_89 )
{
struct V_243 * V_202 = V_89 ;
struct V_239 * V_201 = F_103 ( V_50 ) ;
return ( V_201 -> V_202 . V_244 == V_202 -> V_244
&& V_201 -> V_202 . V_245 == V_202 -> V_245 ) ;
}
static struct V_239 * F_107 (
struct V_241 * V_242 ,
unsigned int V_244 , unsigned char V_245 )
{
struct V_243 V_202 = {
. V_244 = V_244 ,
. V_245 = V_245 ,
} ;
struct V_49 * V_50 ;
V_50 = F_105 ( V_242 , NULL , & V_202 , F_106 ) ;
if ( V_50 )
return F_103 ( V_50 ) ;
else
return NULL ;
}
static T_3 F_108 ( struct V_49 * V_50 ,
struct V_246 * V_247 ,
char * V_248 )
{
struct V_239 * V_201 = F_103 ( V_50 ) ;
return snprintf ( V_248 , 10 , L_40 , V_201 -> V_202 . V_245 ) ;
}
static T_3 F_109 ( struct V_49 * V_50 ,
struct V_246 * V_247 ,
char * V_248 )
{
struct V_239 * V_201 = F_103 ( V_50 ) ;
return snprintf ( V_248 , 10 , L_40 ,
( V_201 -> V_202 . V_249 & 0x80 ) >> 7 ) ;
}
static T_3 F_110 ( struct V_49 * V_50 , struct V_246 * V_247 ,
char * V_248 )
{
struct V_239 * V_201 = F_103 ( V_50 ) ;
return snprintf ( V_248 , 20 , L_40 ,
V_201 -> V_202 . V_249 & 0x0F ) ;
}
static T_3 F_111 ( struct V_49 * V_50 ,
struct V_246 * V_247 ,
char * V_248 )
{
struct V_239 * V_201 = F_103 ( V_50 ) ;
return snprintf ( V_248 , 20 , L_41 , V_201 -> V_202 . V_250 ,
V_201 -> V_202 . V_251 ) ;
}
static T_3 F_112 ( struct V_49 * V_50 ,
struct V_246 * V_247 ,
char * V_248 )
{
struct V_239 * V_201 = F_103 ( V_50 ) ;
return snprintf ( V_248 , 20 , L_7 ,
V_130 ( & V_201 -> V_202 ) ,
V_131 ( & V_201 -> V_202 ) ) ;
}
static T_3 F_113 ( struct V_49 * V_50 ,
struct V_246 * V_247 ,
char * V_248 )
{
struct V_239 * V_201 = F_103 ( V_50 ) ;
return snprintf ( V_248 , 10 , L_42 ,
V_201 -> V_202 . V_252 ) ;
}
static T_3 F_114 ( struct V_49 * V_50 ,
struct V_246 * V_247 ,
char * V_248 )
{
struct V_239 * V_201 = F_103 ( V_50 ) ;
return snprintf ( V_248 , 20 , L_43 , V_201 -> V_202 . V_253 ) ;
}
static T_3 F_115 ( struct V_49 * V_50 ,
struct V_246 * V_247 ,
char * V_248 )
{
struct V_239 * V_201 = F_103 ( V_50 ) ;
return snprintf ( V_248 , 10 , L_44 , V_201 -> V_202 . V_244 ) ;
}
static T_3 F_116 ( struct V_49 * V_50 ,
struct V_246 * V_247 ,
char * V_248 )
{
struct V_239 * V_201 = F_103 ( V_50 ) ;
return snprintf ( V_248 , 21 , L_45 ,
V_201 -> V_202 . V_254 [ 3 ] ,
V_201 -> V_202 . V_254 [ 2 ] ,
V_201 -> V_202 . V_254 [ 1 ] ,
V_201 -> V_202 . V_254 [ 0 ] ) ;
}
static T_3 F_117 ( struct V_49 * V_50 , struct V_246 * V_247 ,
char * V_248 )
{
struct V_239 * V_201 = F_103 ( V_50 ) ;
return snprintf ( V_248 , 100 , L_46 ,
( long long ) V_201 -> V_240 [ 0 ] ,
( long long ) V_201 -> V_240 [ 8 ] ) ;
}
static void F_118 ( struct V_239 * V_201 )
{
if ( ! V_201 -> V_50 )
return;
F_119 ( & V_201 -> V_50 -> V_50 ,
& V_201 -> V_255 ) ;
F_119 ( & V_201 -> V_50 -> V_50 ,
& V_201 -> V_256 ) ;
F_119 ( & V_201 -> V_50 -> V_50 ,
& V_201 -> V_257 ) ;
F_119 ( & V_201 -> V_50 -> V_50 ,
& V_201 -> V_258 ) ;
F_119 ( & V_201 -> V_50 -> V_50 ,
& V_201 -> V_259 ) ;
F_119 ( & V_201 -> V_50 -> V_50 ,
& V_201 -> V_260 ) ;
F_119 ( & V_201 -> V_50 -> V_50 ,
& V_201 -> V_261 ) ;
F_119 ( & V_201 -> V_50 -> V_50 ,
& V_201 -> V_262 ) ;
if ( V_201 -> V_202 . V_263 )
F_119 ( & V_201 -> V_50 -> V_50 ,
& V_201 -> V_264 ) ;
if ( V_201 -> V_265 )
F_119 ( & V_201 -> V_50 -> V_50 ,
& V_201 -> V_266 ) ;
}
static void
F_120 ( struct V_30 * V_31 )
{
struct V_239 * V_201 ;
V_201 = F_18 ( V_31 , struct V_239 , V_33 ) ;
F_118 ( V_201 ) ;
F_121 ( V_201 -> V_50 ) ;
F_16 ( V_201 ) ;
}
static void F_122 ( T_1 V_14 )
{
struct V_239 * V_201 = V_14 -> V_201 ;
if ( V_14 -> V_267 ) {
F_123 ( & V_14 -> V_47 -> V_268 , V_14 -> V_267 ) ;
F_16 ( V_14 -> V_267 ) ;
V_14 -> V_267 = NULL ;
}
if ( V_14 -> V_269 ) {
F_123 ( & V_201 -> V_50 -> V_50 . V_268 , V_14 -> V_269 ) ;
F_16 ( V_14 -> V_269 ) ;
V_14 -> V_269 = NULL ;
}
F_12 ( & V_270 ) ;
F_26 ( & V_201 -> V_33 , F_120 ) ;
V_14 -> V_201 = NULL ;
F_15 ( & V_270 ) ;
}
static int F_124 ( struct V_239 * V_201 )
{
int V_83 ;
V_201 -> V_255 . V_247 . V_224 = L_47 ;
V_201 -> V_255 . V_247 . V_135 = V_271 ;
V_201 -> V_255 . V_272 = F_108 ;
F_125 ( & V_201 -> V_255 . V_247 ) ;
V_201 -> V_256 . V_247 . V_224 = L_48 ;
V_201 -> V_256 . V_247 . V_135 = V_271 ;
V_201 -> V_256 . V_272 = F_109 ;
F_125 ( & V_201 -> V_256 . V_247 ) ;
V_201 -> V_257 . V_247 . V_224 = L_49 ;
V_201 -> V_257 . V_247 . V_135 = V_271 ;
V_201 -> V_257 . V_272 = F_110 ;
F_125 ( & V_201 -> V_257 . V_247 ) ;
V_201 -> V_258 . V_247 . V_224 = L_50 ;
V_201 -> V_258 . V_247 . V_135 = V_271 ;
V_201 -> V_258 . V_272 = F_111 ;
F_125 ( & V_201 -> V_258 . V_247 ) ;
V_201 -> V_259 . V_247 . V_224 = L_51 ;
V_201 -> V_259 . V_247 . V_135 = V_271 ;
V_201 -> V_259 . V_272 = F_112 ;
F_125 ( & V_201 -> V_259 . V_247 ) ;
V_201 -> V_260 . V_247 . V_224 = L_52 ;
V_201 -> V_260 . V_247 . V_135 = V_271 ;
V_201 -> V_260 . V_272 = F_113 ;
F_125 ( & V_201 -> V_260 . V_247 ) ;
V_201 -> V_261 . V_247 . V_224 = L_53 ;
V_201 -> V_261 . V_247 . V_135 = V_271 ;
V_201 -> V_261 . V_272 = F_114 ;
F_125 ( & V_201 -> V_261 . V_247 ) ;
V_201 -> V_262 . V_247 . V_224 = L_54 ;
V_201 -> V_262 . V_247 . V_135 = V_271 ;
V_201 -> V_262 . V_272 = F_115 ;
F_125 ( & V_201 -> V_262 . V_247 ) ;
V_201 -> V_266 . V_247 . V_224 = L_55 ;
V_201 -> V_266 . V_247 . V_135 = V_271 ;
V_201 -> V_266 . V_272 = F_117 ;
F_125 ( & V_201 -> V_266 . V_247 ) ;
V_201 -> V_264 . V_247 . V_224 = L_56 ;
V_201 -> V_264 . V_247 . V_135 = V_271 ;
V_201 -> V_264 . V_272 = F_116 ;
F_125 ( & V_201 -> V_264 . V_247 ) ;
V_83 = F_126 ( & V_201 -> V_50 -> V_50 ,
& V_201 -> V_255 ) ;
if ( V_83 )
goto V_149;
V_83 = F_126 ( & V_201 -> V_50 -> V_50 ,
& V_201 -> V_256 ) ;
if ( V_83 )
goto V_273;
V_83 = F_126 ( & V_201 -> V_50 -> V_50 ,
& V_201 -> V_257 ) ;
if ( V_83 )
goto V_274;
V_83 = F_126 ( & V_201 -> V_50 -> V_50 ,
& V_201 -> V_258 ) ;
if ( V_83 )
goto V_275;
V_83 = F_126 ( & V_201 -> V_50 -> V_50 ,
& V_201 -> V_259 ) ;
if ( V_83 )
goto V_276;
V_83 = F_126 ( & V_201 -> V_50 -> V_50 ,
& V_201 -> V_260 ) ;
if ( V_83 )
goto V_277;
V_83 = F_126 ( & V_201 -> V_50 -> V_50 ,
& V_201 -> V_261 ) ;
if ( V_83 )
goto V_278;
V_83 = F_126 ( & V_201 -> V_50 -> V_50 ,
& V_201 -> V_262 ) ;
if ( V_83 )
goto V_279;
if ( V_201 -> V_202 . V_263 ) {
V_83 = F_126 ( & V_201 -> V_50 -> V_50 ,
& V_201 -> V_264 ) ;
if ( V_83 )
goto V_280;
}
if ( V_201 -> V_265 ) {
V_83 = F_126 ( & V_201 -> V_50 -> V_50 ,
& V_201 -> V_266 ) ;
if ( V_83 )
goto V_281;
}
return 0 ;
V_281:
if ( V_201 -> V_202 . V_263 )
F_119 ( & V_201 -> V_50 -> V_50 ,
& V_201 -> V_264 ) ;
V_280:
F_119 ( & V_201 -> V_50 -> V_50 ,
& V_201 -> V_262 ) ;
V_279:
F_119 ( & V_201 -> V_50 -> V_50 ,
& V_201 -> V_261 ) ;
V_278:
F_119 ( & V_201 -> V_50 -> V_50 ,
& V_201 -> V_260 ) ;
V_277:
F_119 ( & V_201 -> V_50 -> V_50 ,
& V_201 -> V_259 ) ;
V_276:
F_119 ( & V_201 -> V_50 -> V_50 ,
& V_201 -> V_258 ) ;
V_275:
F_119 ( & V_201 -> V_50 -> V_50 ,
& V_201 -> V_257 ) ;
V_274:
F_119 ( & V_201 -> V_50 -> V_50 ,
& V_201 -> V_256 ) ;
V_273:
F_119 ( & V_201 -> V_50 -> V_50 ,
& V_201 -> V_255 ) ;
V_149:
return V_83 ;
}
static int F_127 ( T_1 V_14 , int V_282 ,
const char * V_267 )
{
int V_95 ;
struct V_239 * V_201 = V_14 -> V_201 ;
struct V_239 * V_283 ;
int V_157 ;
char V_284 [ 1 ] ;
F_12 ( & V_270 ) ;
if ( V_201 -> V_265 )
V_283 = F_104 ( & V_285 . V_286 , V_201 -> V_240 ) ;
else
V_283 = F_107 ( & V_285 . V_286 ,
V_201 -> V_202 . V_244 ,
V_201 -> V_202 . V_245 ) ;
if ( V_283 ) {
F_16 ( V_201 ) ;
V_14 -> V_201 = V_283 ;
V_201 = V_283 ;
F_23 ( & V_201 -> V_33 ) ;
F_15 ( & V_270 ) ;
F_65 ( V_287
L_57
L_58 ,
V_201 -> V_202 . V_253 ,
V_201 -> V_202 . V_244 ,
V_201 -> V_202 . V_245 ) ;
} else {
char V_224 [ 14 ] ;
unsigned char V_288 = V_201 -> V_202 . V_245 ;
int V_289 = 0 ;
snprintf ( V_224 , sizeof( V_224 ) ,
L_59 , V_201 -> V_202 . V_244 ) ;
while ( F_107 ( & V_285 . V_286 ,
V_201 -> V_202 . V_244 ,
V_201 -> V_202 . V_245 ) ) {
if ( ! V_289 ) {
F_65 (KERN_WARNING PFX
L_60
L_61
L_62
L_63
L_64
L_65 ,
bmc->id.product_id, bmc->id.device_id) ;
V_289 = 1 ;
}
V_201 -> V_202 . V_245 ++ ;
if ( V_201 -> V_202 . V_245 == V_288 ) {
F_65 (KERN_ERR PFX
L_66 ) ;
break;
}
}
V_201 -> V_50 = F_128 ( V_224 , V_201 -> V_202 . V_245 ) ;
if ( ! V_201 -> V_50 ) {
F_15 ( & V_270 ) ;
F_65 ( V_290
L_67
L_68 ) ;
return - V_48 ;
}
V_201 -> V_50 -> V_50 . V_286 = & V_285 . V_286 ;
F_129 ( & V_201 -> V_50 -> V_50 , V_201 ) ;
F_48 ( & V_201 -> V_33 ) ;
V_95 = F_130 ( V_201 -> V_50 ) ;
F_15 ( & V_270 ) ;
if ( V_95 ) {
F_131 ( V_201 -> V_50 ) ;
V_201 -> V_50 = NULL ;
F_65 ( V_290
L_67
L_69 ,
V_95 ) ;
return V_95 ;
}
V_95 = F_124 ( V_201 ) ;
if ( V_95 ) {
F_12 ( & V_270 ) ;
F_121 ( V_201 -> V_50 ) ;
F_15 ( & V_270 ) ;
return V_95 ;
}
F_132 ( V_14 -> V_47 , L_70
L_71 ,
V_201 -> V_202 . V_253 ,
V_201 -> V_202 . V_244 ,
V_201 -> V_202 . V_245 ) ;
}
V_14 -> V_267 = F_96 ( V_267 , V_43 ) ;
if ( ! V_14 -> V_267 ) {
V_95 = - V_48 ;
F_65 ( V_290
L_72 ,
V_95 ) ;
goto V_44;
}
V_95 = F_133 ( & V_14 -> V_47 -> V_268 ,
& V_201 -> V_50 -> V_50 . V_268 , V_14 -> V_267 ) ;
if ( V_95 ) {
F_16 ( V_14 -> V_267 ) ;
V_14 -> V_267 = NULL ;
F_65 ( V_290
L_73 ,
V_95 ) ;
goto V_44;
}
V_157 = snprintf ( V_284 , 0 , L_74 , V_282 ) ;
V_14 -> V_269 = F_22 ( V_157 + 1 , V_43 ) ;
if ( ! V_14 -> V_269 ) {
F_16 ( V_14 -> V_267 ) ;
V_14 -> V_267 = NULL ;
V_95 = - V_48 ;
F_65 ( V_290
L_75 ,
V_95 ) ;
goto V_44;
}
snprintf ( V_14 -> V_269 , V_157 + 1 , L_74 , V_282 ) ;
V_95 = F_133 ( & V_201 -> V_50 -> V_50 . V_268 , & V_14 -> V_47 -> V_268 ,
V_14 -> V_269 ) ;
if ( V_95 ) {
F_16 ( V_14 -> V_267 ) ;
V_14 -> V_267 = NULL ;
F_16 ( V_14 -> V_269 ) ;
V_14 -> V_269 = NULL ;
F_65 ( V_290
L_67
L_76 ,
V_95 ) ;
goto V_44;
}
return 0 ;
V_44:
F_122 ( V_14 ) ;
return V_95 ;
}
static int
F_134 ( T_1 V_14 , int V_152 )
{
struct V_160 V_10 ;
struct V_57 V_291 ;
V_291 . V_3 = V_56 ;
V_291 . V_55 = V_73 ;
V_291 . V_60 = 0 ;
V_10 . V_87 = V_165 ;
V_10 . V_101 = V_292 ;
V_10 . V_89 = NULL ;
V_10 . V_88 = 0 ;
return F_73 ( NULL ,
V_14 ,
(struct V_1 * ) & V_291 ,
0 ,
& V_10 ,
V_14 ,
NULL ,
NULL ,
0 ,
V_14 -> V_133 [ 0 ] . V_132 ,
V_14 -> V_133 [ 0 ] . V_60 ,
- 1 , 0 ) ;
}
static void
F_135 ( T_1 V_14 , struct V_9 * V_10 )
{
if ( ( V_10 -> V_2 . V_3 != V_56 )
|| ( V_10 -> V_10 . V_87 != V_293 )
|| ( V_10 -> V_10 . V_101 != V_292 ) )
return;
if ( V_10 -> V_10 . V_89 [ 0 ] != 0 ) {
V_14 -> V_201 -> V_265 = 0 ;
goto V_149;
}
if ( V_10 -> V_10 . V_88 < 17 ) {
V_14 -> V_201 -> V_265 = 0 ;
F_65 (KERN_WARNING PFX
L_77
L_78
L_79 ,
msg->msg.data_len) ;
goto V_149;
}
memcpy ( V_14 -> V_201 -> V_240 , V_10 -> V_10 . V_89 , 16 ) ;
V_14 -> V_201 -> V_265 = 1 ;
V_149:
F_136 ( & V_14 -> V_294 ) ;
}
static void
F_137 ( T_1 V_14 )
{
int V_95 ;
V_14 -> V_201 -> V_265 = 0x2 ;
V_14 -> V_77 = F_135 ;
V_95 = F_134 ( V_14 , 0 ) ;
if ( V_95 )
V_14 -> V_201 -> V_265 = 0 ;
F_138 ( V_14 -> V_294 , V_14 -> V_201 -> V_265 != 2 ) ;
V_14 -> V_77 = NULL ;
}
static int
F_139 ( T_1 V_14 , int V_152 )
{
struct V_160 V_10 ;
unsigned char V_89 [ 1 ] ;
struct V_57 V_291 ;
V_291 . V_3 = V_56 ;
V_291 . V_55 = V_73 ;
V_291 . V_60 = 0 ;
V_10 . V_87 = V_165 ;
V_10 . V_101 = V_295 ;
V_10 . V_89 = V_89 ;
V_10 . V_88 = 1 ;
V_89 [ 0 ] = V_152 ;
return F_73 ( NULL ,
V_14 ,
(struct V_1 * ) & V_291 ,
0 ,
& V_10 ,
V_14 ,
NULL ,
NULL ,
0 ,
V_14 -> V_133 [ 0 ] . V_132 ,
V_14 -> V_133 [ 0 ] . V_60 ,
- 1 , 0 ) ;
}
static void
F_140 ( T_1 V_14 , struct V_9 * V_10 )
{
int V_95 = 0 ;
int V_152 ;
if ( ( V_10 -> V_2 . V_3 == V_56 )
&& ( V_10 -> V_10 . V_87 == V_293 )
&& ( V_10 -> V_10 . V_101 == V_295 ) ) {
if ( V_10 -> V_10 . V_89 [ 0 ] != 0 ) {
if ( V_10 -> V_10 . V_89 [ 0 ] == V_296 ) {
V_14 -> V_133 [ 0 ] . V_185
= V_186 ;
V_14 -> V_133 [ 0 ] . V_297
= V_298 ;
V_95 = - V_122 ;
V_14 -> V_299 = V_74 ;
F_136 ( & V_14 -> V_294 ) ;
goto V_149;
}
goto V_300;
}
if ( V_10 -> V_10 . V_88 < 4 ) {
goto V_300;
}
V_152 = V_14 -> V_299 ;
V_14 -> V_133 [ V_152 ] . V_185 = V_10 -> V_10 . V_89 [ 2 ] & 0x7f ;
V_14 -> V_133 [ V_152 ] . V_297 = V_10 -> V_10 . V_89 [ 3 ] & 0x1f ;
V_300:
V_14 -> V_299 ++ ;
if ( V_14 -> V_299 >= V_74 )
F_136 ( & V_14 -> V_294 ) ;
else
V_95 = F_139 ( V_14 , V_14 -> V_299 ) ;
if ( V_95 ) {
V_14 -> V_299 = V_74 ;
F_136 ( & V_14 -> V_294 ) ;
F_65 (KERN_WARNING PFX
L_80 ,
rv) ;
}
}
V_149:
return;
}
static void F_141 ( T_1 V_14 )
{
if ( V_14 -> V_114 -> V_301 )
V_14 -> V_114 -> V_301 ( V_14 -> V_117 ) ;
F_142 ( V_14 ) ;
}
void F_143 ( T_2 V_75 )
{
F_141 ( V_75 -> V_14 ) ;
}
int F_144 ( struct V_121 * V_114 ,
void * V_117 ,
struct V_302 * V_245 ,
struct V_49 * V_47 ,
const char * V_267 ,
unsigned char V_64 )
{
int V_15 , V_303 ;
int V_95 ;
T_1 V_14 ;
T_1 V_304 ;
struct V_7 * V_12 ;
if ( ! V_110 ) {
V_95 = F_46 () ;
if ( V_95 )
return V_95 ;
if ( ! V_110 )
return - V_102 ;
}
V_14 = F_145 ( sizeof( * V_14 ) , V_43 ) ;
if ( ! V_14 )
return - V_48 ;
V_14 -> V_130 = V_130 ( V_245 ) ;
V_14 -> V_131 = V_131 ( V_245 ) ;
V_14 -> V_201 = F_145 ( sizeof( * V_14 -> V_201 ) , V_43 ) ;
if ( ! V_14 -> V_201 ) {
F_16 ( V_14 ) ;
return - V_48 ;
}
V_14 -> V_42 = - 1 ;
F_48 ( & V_14 -> V_33 ) ;
V_14 -> V_201 -> V_202 = * V_245 ;
V_14 -> V_47 = V_47 ;
for ( V_303 = 0 ; V_303 < V_74 ; V_303 ++ ) {
V_14 -> V_133 [ V_303 ] . V_132 = V_305 ;
V_14 -> V_133 [ V_303 ] . V_60 = 2 ;
}
if ( V_64 != 0 )
V_14 -> V_133 [ 0 ] . V_132 = V_64 ;
F_13 ( & V_14 -> V_119 ) ;
V_14 -> V_114 = V_114 ;
V_14 -> V_117 = V_117 ;
F_146 ( & V_14 -> V_104 ) ;
for ( V_303 = 0 ; V_303 < V_26 ; V_303 ++ ) {
V_14 -> V_27 [ V_303 ] . V_28 = 0 ;
V_14 -> V_27 [ V_303 ] . V_94 = 0 ;
}
V_14 -> V_96 = 0 ;
#ifdef F_95
F_147 ( & V_14 -> V_231 ) ;
#endif
F_146 ( & V_14 -> V_306 ) ;
F_13 ( & V_14 -> V_21 ) ;
F_148 ( & V_14 -> V_20 ,
V_307 ,
( unsigned long ) V_14 ) ;
F_149 ( & V_14 -> V_308 , 0 ) ;
F_146 ( & V_14 -> V_147 ) ;
F_13 ( & V_14 -> V_22 ) ;
V_14 -> V_150 = 0 ;
F_147 ( & V_14 -> V_23 ) ;
F_146 ( & V_14 -> V_136 ) ;
F_13 ( & V_14 -> V_24 ) ;
F_150 ( & V_14 -> V_294 ) ;
for ( V_15 = 0 ; V_15 < V_309 ; V_15 ++ )
F_149 ( & V_14 -> V_310 [ V_15 ] , 0 ) ;
V_14 -> V_230 = NULL ;
F_12 ( & V_40 ) ;
F_12 ( & V_41 ) ;
V_15 = 0 ;
V_12 = & V_311 ;
F_47 (tintf, &ipmi_interfaces, link) {
if ( V_304 -> V_42 != V_15 ) {
V_12 = & V_304 -> V_12 ;
break;
}
V_15 ++ ;
}
if ( V_15 == 0 )
F_49 ( & V_14 -> V_12 , & V_311 ) ;
else
F_151 ( & V_14 -> V_12 , V_12 ) ;
V_95 = V_114 -> V_312 ( V_117 , V_14 ) ;
if ( V_95 )
goto V_149;
F_137 ( V_14 ) ;
if ( ( V_14 -> V_130 > 1 )
|| ( ( V_14 -> V_130 == 1 )
&& ( V_14 -> V_131 >= 5 ) ) ) {
V_14 -> V_77 = F_140 ;
V_14 -> V_299 = 0 ;
V_95 = F_139 ( V_14 , 0 ) ;
if ( V_95 )
goto V_149;
F_138 ( V_14 -> V_294 ,
V_14 -> V_299 >= V_74 ) ;
V_14 -> V_77 = NULL ;
} else {
V_14 -> V_133 [ 0 ] . V_185 = V_186 ;
V_14 -> V_133 [ 0 ] . V_297 = V_298 ;
V_14 -> V_299 = V_74 ;
}
if ( V_95 == 0 )
V_95 = F_98 ( V_14 , V_15 ) ;
V_95 = F_127 ( V_14 , V_15 , V_267 ) ;
V_149:
if ( V_95 ) {
if ( V_14 -> V_230 )
F_100 ( V_14 ) ;
V_14 -> V_114 = NULL ;
F_53 ( & V_14 -> V_12 ) ;
F_15 ( & V_41 ) ;
F_15 ( & V_40 ) ;
V_25 () ;
F_26 ( & V_14 -> V_33 , F_17 ) ;
} else {
F_152 () ;
V_14 -> V_42 = V_15 ;
F_15 ( & V_41 ) ;
F_28 ( V_15 , V_14 -> V_47 ) ;
F_15 ( & V_40 ) ;
}
return V_95 ;
}
static void F_153 ( T_1 V_14 )
{
int V_15 ;
struct V_27 * V_106 ;
for ( V_15 = 0 ; V_15 < V_26 ; V_15 ++ ) {
V_106 = & ( V_14 -> V_27 [ V_15 ] ) ;
if ( ! V_106 -> V_28 )
continue;
F_36 ( V_106 -> V_29 , V_313 ) ;
}
}
int F_154 ( T_1 V_14 )
{
struct V_34 * V_51 ;
int V_42 = V_14 -> V_42 ;
F_122 ( V_14 ) ;
F_12 ( & V_40 ) ;
F_12 ( & V_41 ) ;
V_14 -> V_42 = - 1 ;
V_14 -> V_114 = NULL ;
F_53 ( & V_14 -> V_12 ) ;
F_15 ( & V_41 ) ;
V_25 () ;
F_153 ( V_14 ) ;
F_100 ( V_14 ) ;
F_21 (w, &smi_watchers, link)
V_51 -> V_314 ( V_42 ) ;
F_15 ( & V_40 ) ;
F_26 ( & V_14 -> V_33 , F_17 ) ;
return 0 ;
}
static int F_155 ( T_1 V_14 ,
struct V_13 * V_10 )
{
struct V_61 V_161 ;
struct V_9 * V_29 ;
if ( V_10 -> V_315 < 11 ) {
F_35 ( V_14 , V_208 ) ;
return 0 ;
}
if ( V_10 -> V_316 [ 2 ] != 0 ) {
return 0 ;
}
V_161 . V_3 = V_5 ;
V_161 . V_64 = V_10 -> V_316 [ 6 ] ;
V_161 . V_55 = V_10 -> V_316 [ 3 ] & 0x0f ;
V_161 . V_60 = V_10 -> V_316 [ 7 ] & 3 ;
if ( F_39 ( V_14 ,
V_10 -> V_316 [ 7 ] >> 2 ,
V_10 -> V_316 [ 3 ] & 0x0f ,
V_10 -> V_316 [ 8 ] ,
( V_10 -> V_316 [ 4 ] >> 2 ) & ( ~ 1 ) ,
(struct V_1 * ) & ( V_161 ) ,
& V_29 ) ) {
F_35 ( V_14 , V_209 ) ;
return 0 ;
}
memcpy ( V_29 -> V_86 ,
& ( V_10 -> V_316 [ 9 ] ) ,
V_10 -> V_315 - 9 ) ;
V_29 -> V_10 . V_87 = V_10 -> V_316 [ 4 ] >> 2 ;
V_29 -> V_10 . V_89 = V_29 -> V_86 ;
V_29 -> V_10 . V_88 = V_10 -> V_315 - 10 ;
V_29 -> V_84 = V_85 ;
F_35 ( V_14 , V_207 ) ;
F_34 ( V_29 ) ;
return 0 ;
}
static int F_156 ( T_1 V_14 ,
struct V_13 * V_10 )
{
struct V_16 * V_17 ;
int V_95 = 0 ;
unsigned char V_87 ;
unsigned char V_101 ;
unsigned char V_152 ;
T_2 V_75 = NULL ;
struct V_61 * V_161 ;
struct V_9 * V_29 ;
struct V_121 * V_114 ;
if ( V_10 -> V_315 < 10 ) {
F_35 ( V_14 , V_217 ) ;
return 0 ;
}
if ( V_10 -> V_316 [ 2 ] != 0 ) {
return 0 ;
}
V_87 = V_10 -> V_316 [ 4 ] >> 2 ;
V_101 = V_10 -> V_316 [ 8 ] ;
V_152 = V_10 -> V_316 [ 3 ] & 0xf ;
F_76 () ;
V_17 = F_66 ( V_14 , V_87 , V_101 , V_152 ) ;
if ( V_17 ) {
V_75 = V_17 -> V_75 ;
F_23 ( & V_75 -> V_33 ) ;
} else
V_75 = NULL ;
F_79 () ;
if ( V_75 == NULL ) {
F_35 ( V_14 , V_218 ) ;
V_10 -> V_89 [ 0 ] = ( V_165 << 2 ) ;
V_10 -> V_89 [ 1 ] = V_166 ;
V_10 -> V_89 [ 2 ] = V_10 -> V_316 [ 3 ] ;
V_10 -> V_89 [ 3 ] = V_10 -> V_316 [ 6 ] ;
V_10 -> V_89 [ 4 ] = ( ( V_87 + 1 ) << 2 ) | ( V_10 -> V_316 [ 7 ] & 0x3 ) ;
V_10 -> V_89 [ 5 ] = F_70 ( & ( V_10 -> V_89 [ 3 ] ) , 2 ) ;
V_10 -> V_89 [ 6 ] = V_14 -> V_133 [ V_10 -> V_316 [ 3 ] & 0xf ] . V_132 ;
V_10 -> V_89 [ 7 ] = ( V_10 -> V_316 [ 7 ] & 0xfc ) | ( V_10 -> V_316 [ 4 ] & 0x3 ) ;
V_10 -> V_89 [ 8 ] = V_10 -> V_316 [ 8 ] ;
V_10 -> V_89 [ 9 ] = V_317 ;
V_10 -> V_89 [ 10 ] = F_70 ( & ( V_10 -> V_89 [ 6 ] ) , 4 ) ;
V_10 -> V_167 = 11 ;
#ifdef F_78
{
int V_193 ;
F_65 ( L_81 ) ;
for ( V_193 = 0 ; V_193 < V_10 -> V_167 ; V_193 ++ )
F_65 ( L_3 , V_10 -> V_89 [ V_193 ] ) ;
F_65 ( L_4 ) ;
}
#endif
F_76 () ;
V_114 = V_14 -> V_114 ;
if ( V_114 ) {
V_114 -> V_194 ( V_14 -> V_117 , V_10 , 0 ) ;
V_95 = - 1 ;
}
F_79 () ;
} else {
F_35 ( V_14 , V_216 ) ;
V_29 = F_74 () ;
if ( ! V_29 ) {
V_95 = 1 ;
F_26 ( & V_75 -> V_33 , F_51 ) ;
} else {
V_161 = (struct V_61 * ) & V_29 -> V_2 ;
V_161 -> V_3 = V_5 ;
V_161 -> V_64 = V_10 -> V_316 [ 6 ] ;
V_161 -> V_60 = V_10 -> V_316 [ 7 ] & 3 ;
V_161 -> V_55 = V_10 -> V_316 [ 3 ] & 0xf ;
V_29 -> V_75 = V_75 ;
V_29 -> V_84 = V_318 ;
V_29 -> V_105 = V_10 -> V_316 [ 7 ] >> 2 ;
V_29 -> V_10 . V_87 = V_10 -> V_316 [ 4 ] >> 2 ;
V_29 -> V_10 . V_101 = V_10 -> V_316 [ 8 ] ;
V_29 -> V_10 . V_89 = V_29 -> V_86 ;
V_29 -> V_10 . V_88 = V_10 -> V_315 - 10 ;
memcpy ( V_29 -> V_86 ,
& ( V_10 -> V_316 [ 9 ] ) ,
V_10 -> V_315 - 10 ) ;
F_34 ( V_29 ) ;
}
}
return V_95 ;
}
static int F_157 ( T_1 V_14 ,
struct V_13 * V_10 )
{
struct V_65 V_168 ;
struct V_9 * V_29 ;
if ( V_10 -> V_315 < 13 ) {
F_35 ( V_14 , V_214 ) ;
return 0 ;
}
if ( V_10 -> V_316 [ 2 ] != 0 ) {
return 0 ;
}
V_168 . V_3 = V_4 ;
V_168 . V_70 = V_10 -> V_316 [ 4 ] ;
V_168 . V_68 = V_10 -> V_316 [ 8 ] ;
V_168 . V_69 = V_10 -> V_316 [ 5 ] ;
V_168 . V_55 = V_10 -> V_316 [ 3 ] & 0x0f ;
V_168 . V_319 = V_10 -> V_316 [ 3 ] >> 4 ;
V_168 . V_60 = V_10 -> V_316 [ 9 ] & 3 ;
if ( F_39 ( V_14 ,
V_10 -> V_316 [ 9 ] >> 2 ,
V_10 -> V_316 [ 3 ] & 0x0f ,
V_10 -> V_316 [ 10 ] ,
( V_10 -> V_316 [ 6 ] >> 2 ) & ( ~ 1 ) ,
(struct V_1 * ) & ( V_168 ) ,
& V_29 ) ) {
F_35 ( V_14 , V_215 ) ;
return 0 ;
}
memcpy ( V_29 -> V_86 ,
& ( V_10 -> V_316 [ 11 ] ) ,
V_10 -> V_315 - 11 ) ;
V_29 -> V_10 . V_87 = V_10 -> V_316 [ 6 ] >> 2 ;
V_29 -> V_10 . V_89 = V_29 -> V_86 ;
V_29 -> V_10 . V_88 = V_10 -> V_315 - 12 ;
V_29 -> V_84 = V_85 ;
F_35 ( V_14 , V_213 ) ;
F_34 ( V_29 ) ;
return 0 ;
}
static int F_158 ( T_1 V_14 ,
struct V_13 * V_10 )
{
struct V_16 * V_17 ;
int V_95 = 0 ;
unsigned char V_87 ;
unsigned char V_101 ;
unsigned char V_152 ;
T_2 V_75 = NULL ;
struct V_65 * V_168 ;
struct V_9 * V_29 ;
if ( V_10 -> V_315 < 12 ) {
F_35 ( V_14 , V_217 ) ;
return 0 ;
}
if ( V_10 -> V_316 [ 2 ] != 0 ) {
return 0 ;
}
V_87 = V_10 -> V_316 [ 6 ] >> 2 ;
V_101 = V_10 -> V_316 [ 10 ] ;
V_152 = V_10 -> V_316 [ 3 ] & 0xf ;
F_76 () ;
V_17 = F_66 ( V_14 , V_87 , V_101 , V_152 ) ;
if ( V_17 ) {
V_75 = V_17 -> V_75 ;
F_23 ( & V_75 -> V_33 ) ;
} else
V_75 = NULL ;
F_79 () ;
if ( V_75 == NULL ) {
F_35 ( V_14 , V_218 ) ;
V_95 = 0 ;
} else {
F_35 ( V_14 , V_216 ) ;
V_29 = F_74 () ;
if ( ! V_29 ) {
V_95 = 1 ;
F_26 ( & V_75 -> V_33 , F_51 ) ;
} else {
V_168 = (struct V_65 * ) & V_29 -> V_2 ;
V_168 -> V_3 = V_4 ;
V_168 -> V_70 = V_10 -> V_316 [ 4 ] ;
V_168 -> V_68 = V_10 -> V_316 [ 8 ] ;
V_168 -> V_69 = V_10 -> V_316 [ 5 ] ;
V_168 -> V_60 = V_10 -> V_316 [ 9 ] & 3 ;
V_168 -> V_55 = V_10 -> V_316 [ 3 ] & 0xf ;
V_168 -> V_319 = V_10 -> V_316 [ 3 ] >> 4 ;
V_29 -> V_75 = V_75 ;
V_29 -> V_84 = V_318 ;
V_29 -> V_105 = V_10 -> V_316 [ 9 ] >> 2 ;
V_29 -> V_10 . V_87 = V_10 -> V_316 [ 6 ] >> 2 ;
V_29 -> V_10 . V_101 = V_10 -> V_316 [ 10 ] ;
V_29 -> V_10 . V_89 = V_29 -> V_86 ;
V_29 -> V_10 . V_88 = V_10 -> V_315 - 12 ;
memcpy ( V_29 -> V_86 ,
& ( V_10 -> V_316 [ 11 ] ) ,
V_10 -> V_315 - 12 ) ;
F_34 ( V_29 ) ;
}
}
return V_95 ;
}
static int F_159 ( T_1 V_14 ,
struct V_13 * V_10 )
{
struct V_16 * V_17 ;
int V_95 = 0 ;
unsigned char V_87 ;
unsigned char V_101 ;
unsigned char V_152 ;
T_2 V_75 = NULL ;
struct V_57 * V_173 ;
struct V_9 * V_29 ;
if ( V_10 -> V_315 < 4 ) {
F_35 ( V_14 , V_217 ) ;
return 0 ;
}
if ( V_10 -> V_316 [ 2 ] != 0 ) {
return 0 ;
}
V_87 = V_10 -> V_316 [ 0 ] >> 2 ;
V_101 = V_10 -> V_316 [ 1 ] ;
V_152 = V_10 -> V_316 [ 3 ] & 0xf ;
F_76 () ;
V_17 = F_66 ( V_14 , V_87 , V_101 , V_152 ) ;
if ( V_17 ) {
V_75 = V_17 -> V_75 ;
F_23 ( & V_75 -> V_33 ) ;
} else
V_75 = NULL ;
F_79 () ;
if ( V_75 == NULL ) {
F_35 ( V_14 , V_218 ) ;
V_95 = 0 ;
} else {
F_35 ( V_14 , V_216 ) ;
V_29 = F_74 () ;
if ( ! V_29 ) {
V_95 = 1 ;
F_26 ( & V_75 -> V_33 , F_51 ) ;
} else {
V_173 = ( (struct V_57 * )
& ( V_29 -> V_2 ) ) ;
V_173 -> V_3 = V_56 ;
V_173 -> V_55 = V_73 ;
V_173 -> V_60 = V_10 -> V_316 [ 0 ] & 3 ;
V_29 -> V_75 = V_75 ;
V_29 -> V_76 = NULL ;
V_29 -> V_84 = V_320 ;
V_29 -> V_10 . V_87 = V_10 -> V_316 [ 0 ] >> 2 ;
V_29 -> V_10 . V_101 = V_10 -> V_316 [ 1 ] ;
V_29 -> V_10 . V_89 = V_29 -> V_86 ;
V_29 -> V_10 . V_88 = V_10 -> V_315 - 4 ;
memcpy ( V_29 -> V_86 ,
& ( V_10 -> V_316 [ 4 ] ) ,
V_10 -> V_315 - 4 ) ;
F_34 ( V_29 ) ;
}
}
return V_95 ;
}
static void F_160 ( struct V_9 * V_29 ,
struct V_13 * V_10 )
{
struct V_57 * V_173 ;
V_29 -> V_105 = 0 ;
V_173 = (struct V_57 * ) & ( V_29 -> V_2 ) ;
V_173 -> V_3 = V_56 ;
V_173 -> V_55 = V_73 ;
V_173 -> V_60 = V_10 -> V_316 [ 0 ] & 3 ;
V_29 -> V_84 = V_321 ;
V_29 -> V_10 . V_87 = V_10 -> V_316 [ 0 ] >> 2 ;
V_29 -> V_10 . V_101 = V_10 -> V_316 [ 1 ] ;
memcpy ( V_29 -> V_86 , & ( V_10 -> V_316 [ 3 ] ) , V_10 -> V_315 - 3 ) ;
V_29 -> V_10 . V_89 = V_29 -> V_86 ;
V_29 -> V_10 . V_88 = V_10 -> V_315 - 3 ;
}
static int F_161 ( T_1 V_14 ,
struct V_13 * V_10 )
{
struct V_9 * V_29 , * V_322 ;
struct V_7 V_146 ;
T_2 V_75 ;
int V_95 = 0 ;
int V_323 = 0 ;
unsigned long V_103 ;
if ( V_10 -> V_315 < 19 ) {
F_35 ( V_14 , V_219 ) ;
return 0 ;
}
if ( V_10 -> V_316 [ 2 ] != 0 ) {
return 0 ;
}
F_13 ( & V_146 ) ;
F_40 ( & V_14 -> V_147 , V_103 ) ;
F_35 ( V_14 , V_220 ) ;
F_76 () ;
F_47 (user, &intf->users, link) {
if ( ! V_75 -> V_113 )
continue;
V_29 = F_74 () ;
if ( ! V_29 ) {
F_79 () ;
F_5 (recv_msg, recv_msg2, &msgs,
link) {
F_6 ( & V_29 -> V_12 ) ;
F_7 ( V_29 ) ;
}
V_95 = 1 ;
goto V_149;
}
V_323 ++ ;
F_160 ( V_29 , V_10 ) ;
V_29 -> V_75 = V_75 ;
F_23 ( & V_75 -> V_33 ) ;
F_24 ( & ( V_29 -> V_12 ) , & V_146 ) ;
}
F_79 () ;
if ( V_323 ) {
F_5 (recv_msg, recv_msg2, &msgs, link) {
F_6 ( & V_29 -> V_12 ) ;
F_34 ( V_29 ) ;
}
} else if ( V_14 -> V_150 < V_324 ) {
V_29 = F_74 () ;
if ( ! V_29 ) {
V_95 = 1 ;
goto V_149;
}
F_160 ( V_29 , V_10 ) ;
F_24 ( & ( V_29 -> V_12 ) , & ( V_14 -> V_22 ) ) ;
V_14 -> V_150 ++ ;
} else if ( ! V_14 -> V_151 ) {
F_65 (KERN_WARNING PFX L_82
L_83 ) ;
V_14 -> V_151 = 1 ;
}
V_149:
F_41 ( & ( V_14 -> V_147 ) , V_103 ) ;
return V_95 ;
}
static int F_162 ( T_1 V_14 ,
struct V_13 * V_10 )
{
struct V_9 * V_29 ;
struct V_124 * V_75 ;
V_29 = (struct V_9 * ) V_10 -> V_183 ;
if ( V_29 == NULL ) {
F_65 ( V_325
L_84
L_85
L_86
L_87 ) ;
return 0 ;
}
V_75 = V_29 -> V_75 ;
if ( V_75 && ! V_75 -> V_118 ) {
F_35 ( V_14 , V_79 ) ;
F_7 ( V_29 ) ;
} else {
struct V_57 * V_173 ;
F_35 ( V_14 , V_78 ) ;
V_29 -> V_84 = V_85 ;
V_29 -> V_105 = V_10 -> V_105 ;
V_173 = ( (struct V_57 * )
& ( V_29 -> V_2 ) ) ;
V_173 -> V_3 = V_56 ;
V_173 -> V_55 = V_73 ;
V_173 -> V_60 = V_10 -> V_316 [ 0 ] & 3 ;
V_29 -> V_10 . V_87 = V_10 -> V_316 [ 0 ] >> 2 ;
V_29 -> V_10 . V_101 = V_10 -> V_316 [ 1 ] ;
memcpy ( V_29 -> V_86 ,
& ( V_10 -> V_316 [ 2 ] ) ,
V_10 -> V_315 - 2 ) ;
V_29 -> V_10 . V_89 = V_29 -> V_86 ;
V_29 -> V_10 . V_88 = V_10 -> V_315 - 2 ;
F_34 ( V_29 ) ;
}
return 0 ;
}
static int F_163 ( T_1 V_14 ,
struct V_13 * V_10 )
{
int V_326 ;
int V_152 ;
#ifdef F_78
int V_193 ;
F_65 ( L_88 ) ;
for ( V_193 = 0 ; V_193 < V_10 -> V_315 ; V_193 ++ )
F_65 ( L_3 , V_10 -> V_316 [ V_193 ] ) ;
F_65 ( L_4 ) ;
#endif
if ( V_10 -> V_315 < 2 ) {
F_65 (KERN_WARNING PFX L_89
L_90 ,
(msg->data[0] >> 2) | 1 , msg->data[1], msg->rsp_size) ;
V_10 -> V_316 [ 0 ] = V_10 -> V_89 [ 0 ] | ( 1 << 2 ) ;
V_10 -> V_316 [ 1 ] = V_10 -> V_89 [ 1 ] ;
V_10 -> V_316 [ 2 ] = V_313 ;
V_10 -> V_315 = 3 ;
} else if ( ( ( V_10 -> V_316 [ 0 ] >> 2 ) != ( ( V_10 -> V_89 [ 0 ] >> 2 ) | 1 ) )
|| ( V_10 -> V_316 [ 1 ] != V_10 -> V_89 [ 1 ] ) ) {
F_65 (KERN_WARNING PFX L_91
L_92 ,
(msg->data[0] >> 2) | 1 , msg->data[1],
msg->rsp[0] >> 2 , msg->rsp[1]) ;
V_10 -> V_316 [ 0 ] = V_10 -> V_89 [ 0 ] | ( 1 << 2 ) ;
V_10 -> V_316 [ 1 ] = V_10 -> V_89 [ 1 ] ;
V_10 -> V_316 [ 2 ] = V_313 ;
V_10 -> V_315 = 3 ;
}
if ( ( V_10 -> V_316 [ 0 ] == ( ( V_165 | 1 ) << 2 ) )
&& ( V_10 -> V_316 [ 1 ] == V_166 )
&& ( V_10 -> V_183 != NULL ) ) {
struct V_9 * V_29 = V_10 -> V_183 ;
V_326 = 0 ;
if ( V_10 -> V_315 < 2 )
goto V_149;
V_152 = V_10 -> V_89 [ 2 ] & 0x0f ;
if ( V_152 >= V_74 )
goto V_149;
if ( ! V_29 )
goto V_149;
if ( ! V_29 -> V_75 || ! V_29 -> V_75 -> V_118 )
goto V_149;
V_29 -> V_84 = V_327 ;
V_29 -> V_10 . V_89 = V_29 -> V_86 ;
V_29 -> V_10 . V_88 = 1 ;
V_29 -> V_86 [ 0 ] = V_10 -> V_316 [ 2 ] ;
F_34 ( V_29 ) ;
} else if ( ( V_10 -> V_316 [ 0 ] == ( ( V_165 | 1 ) << 2 ) )
&& ( V_10 -> V_316 [ 1 ] == V_175 ) ) {
V_152 = V_10 -> V_316 [ 3 ] & 0xf ;
if ( V_152 >= V_74 ) {
V_326 = 0 ;
goto V_149;
}
if ( V_14 -> V_299 < V_74 ) {
V_326 = 0 ;
goto V_149;
}
switch ( V_14 -> V_133 [ V_152 ] . V_185 ) {
case V_186 :
if ( V_10 -> V_316 [ 4 ] & 0x04 ) {
V_326 = F_155 ( V_14 , V_10 ) ;
} else {
V_326 = F_156 ( V_14 , V_10 ) ;
}
break;
case V_189 :
case V_190 :
if ( V_10 -> V_316 [ 6 ] & 0x04 ) {
V_326 = F_157 ( V_14 , V_10 ) ;
} else {
V_326 = F_158 ( V_14 , V_10 ) ;
}
break;
default:
if ( ( V_14 -> V_133 [ V_152 ] . V_185
>= V_328 )
&& ( V_14 -> V_133 [ V_152 ] . V_185
<= V_329 ) ) {
V_326 = F_159 ( V_14 , V_10 ) ;
} else {
V_326 = 0 ;
}
}
} else if ( ( V_10 -> V_316 [ 0 ] == ( ( V_165 | 1 ) << 2 ) )
&& ( V_10 -> V_316 [ 1 ] == V_176 ) ) {
V_326 = F_161 ( V_14 , V_10 ) ;
} else {
V_326 = F_162 ( V_14 , V_10 ) ;
}
V_149:
return V_326 ;
}
static void F_142 ( T_1 V_14 )
{
struct V_13 * V_159 ;
unsigned long V_103 = 0 ;
int V_95 ;
int V_330 = V_14 -> V_330 ;
if ( ! V_330 )
F_40 ( & V_14 -> V_306 , V_103 ) ;
while ( ! F_63 ( & V_14 -> V_21 ) ) {
V_159 = F_164 ( V_14 -> V_21 . V_126 ,
struct V_13 , V_12 ) ;
F_6 ( & V_159 -> V_12 ) ;
if ( ! V_330 )
F_41 ( & V_14 -> V_306 , V_103 ) ;
V_95 = F_163 ( V_14 , V_159 ) ;
if ( ! V_330 )
F_40 ( & V_14 -> V_306 , V_103 ) ;
if ( V_95 == 0 ) {
F_9 ( V_159 ) ;
} else if ( V_95 < 0 ) {
} else {
F_25 ( & V_159 -> V_12 , & V_14 -> V_21 ) ;
break;
}
}
if ( ! V_330 )
F_41 ( & V_14 -> V_306 , V_103 ) ;
if ( F_165 ( & V_14 -> V_308 , - 1 , 0 ) ) {
T_2 V_75 ;
F_76 () ;
F_47 (user, &intf->users, link) {
if ( V_75 -> V_80 -> V_331 )
V_75 -> V_80 -> V_331 (
V_75 -> V_82 ) ;
}
F_79 () ;
}
}
static void V_307 ( unsigned long V_145 )
{
F_142 ( ( T_1 ) V_145 ) ;
}
void F_166 ( T_1 V_14 ,
struct V_13 * V_10 )
{
unsigned long V_103 = 0 ;
int V_330 ;
if ( ( V_10 -> V_167 >= 2 )
&& ( V_10 -> V_89 [ 0 ] == ( V_165 << 2 ) )
&& ( V_10 -> V_89 [ 1 ] == V_166 )
&& ( V_10 -> V_183 == NULL ) ) {
if ( ( V_10 -> V_315 >= 3 ) && ( V_10 -> V_316 [ 2 ] != 0 )
&& ( V_10 -> V_316 [ 2 ] != V_332 )
&& ( V_10 -> V_316 [ 2 ] != V_333 )
&& ( V_10 -> V_316 [ 2 ] != V_334 )
&& ( V_10 -> V_316 [ 2 ] != V_335 ) ) {
int V_152 = V_10 -> V_316 [ 3 ] & 0xf ;
if ( V_152 >= V_74 )
;
else if ( ( V_14 -> V_133 [ V_152 ] . V_185
== V_189 )
|| ( V_14 -> V_133 [ V_152 ] . V_185
== V_190 ) )
F_35 ( V_14 , V_210 ) ;
else
F_35 ( V_14 , V_203 ) ;
F_44 ( V_14 , V_10 -> V_105 , V_10 -> V_316 [ 2 ] ) ;
} else
F_42 ( V_14 , V_10 -> V_105 ) ;
F_9 ( V_10 ) ;
goto V_149;
}
V_330 = V_14 -> V_330 ;
if ( ! V_330 )
F_40 ( & V_14 -> V_306 , V_103 ) ;
F_24 ( & V_10 -> V_12 , & V_14 -> V_21 ) ;
if ( ! V_330 )
F_41 ( & V_14 -> V_306 , V_103 ) ;
F_167 ( & V_14 -> V_20 ) ;
V_149:
return;
}
void F_168 ( T_1 V_14 )
{
F_149 ( & V_14 -> V_308 , 1 ) ;
F_167 ( & V_14 -> V_20 ) ;
}
static struct V_13 *
F_169 ( T_1 V_14 , struct V_9 * V_29 ,
unsigned char V_93 , long V_94 )
{
struct V_13 * V_159 = F_75 () ;
if ( ! V_159 )
return NULL ;
memcpy ( V_159 -> V_89 , V_29 -> V_10 . V_89 , V_29 -> V_10 . V_88 ) ;
V_159 -> V_167 = V_29 -> V_10 . V_88 ;
V_159 -> V_105 = F_77 ( V_93 , V_94 ) ;
#ifdef F_78
{
int V_193 ;
F_65 ( L_93 ) ;
for ( V_193 = 0 ; V_193 < V_159 -> V_167 ; V_193 ++ )
F_65 ( L_3 , V_159 -> V_89 [ V_193 ] ) ;
F_65 ( L_4 ) ;
}
#endif
return V_159 ;
}
static void F_170 ( T_1 V_14 , struct V_27 * V_106 ,
struct V_7 * V_336 , long V_337 ,
int V_338 , unsigned long * V_103 )
{
struct V_9 * V_10 ;
struct V_121 * V_114 ;
if ( V_14 -> V_42 == - 1 )
return;
if ( ! V_106 -> V_28 )
return;
V_106 -> V_90 -= V_337 ;
if ( V_106 -> V_90 > 0 )
return;
if ( V_106 -> V_99 == 0 ) {
V_106 -> V_28 = 0 ;
V_10 = V_106 -> V_29 ;
F_24 ( & V_10 -> V_12 , V_336 ) ;
if ( V_106 -> V_92 )
F_35 ( V_14 , V_206 ) ;
else if ( F_1 ( & V_106 -> V_29 -> V_2 ) )
F_35 ( V_14 , V_212 ) ;
else
F_35 ( V_14 , V_205 ) ;
} else {
struct V_13 * V_159 ;
V_106 -> V_90 = V_97 ;
V_106 -> V_99 -- ;
V_159 = F_169 ( V_14 , V_106 -> V_29 , V_338 ,
V_106 -> V_94 ) ;
if ( ! V_159 ) {
if ( F_1 ( & V_106 -> V_29 -> V_2 ) )
F_35 ( V_14 ,
V_221 ) ;
else
F_35 ( V_14 ,
V_222 ) ;
return;
}
F_41 ( & V_14 -> V_104 , * V_103 ) ;
V_114 = V_14 -> V_114 ;
if ( V_114 ) {
if ( F_1 ( & V_106 -> V_29 -> V_2 ) )
F_35 ( V_14 ,
V_211 ) ;
else
F_35 ( V_14 ,
V_204 ) ;
V_14 -> V_114 -> V_194 ( V_14 -> V_117 ,
V_159 , 0 ) ;
} else
F_9 ( V_159 ) ;
F_40 ( & V_14 -> V_104 , * V_103 ) ;
}
}
static void F_171 ( long V_337 )
{
T_1 V_14 ;
struct V_7 V_336 ;
struct V_9 * V_10 , * V_11 ;
unsigned long V_103 ;
int V_15 ;
F_76 () ;
F_47 (intf, &ipmi_interfaces, link) {
F_167 ( & V_14 -> V_20 ) ;
F_13 ( & V_336 ) ;
F_40 ( & V_14 -> V_104 , V_103 ) ;
for ( V_15 = 0 ; V_15 < V_26 ; V_15 ++ )
F_170 ( V_14 , & ( V_14 -> V_27 [ V_15 ] ) ,
& V_336 , V_337 , V_15 ,
& V_103 ) ;
F_41 ( & V_14 -> V_104 , V_103 ) ;
F_5 (msg, msg2, &timeouts, link)
F_36 ( V_10 , V_339 ) ;
if ( V_14 -> V_141 > 0 ) {
F_40 ( & V_14 -> V_136 , V_103 ) ;
if ( V_14 -> V_141 > 0 ) {
V_14 -> V_141
-= V_337 ;
if ( ! V_14 -> V_137
&& ( V_14 -> V_141 <= 0 ) ) {
V_14 -> V_139 = 0 ;
F_60 ( V_14 ) ;
}
}
F_41 ( & V_14 -> V_136 ,
V_103 ) ;
}
}
F_79 () ;
}
static void F_172 ( void )
{
T_1 V_14 ;
struct V_121 * V_114 ;
F_76 () ;
F_47 (intf, &ipmi_interfaces, link) {
if ( V_14 -> V_139 )
continue;
V_114 = V_14 -> V_114 ;
if ( V_114 )
V_114 -> V_340 ( V_14 -> V_117 ) ;
}
F_79 () ;
}
static void F_173 ( unsigned long V_89 )
{
if ( F_174 ( & V_341 ) )
return;
V_342 -- ;
if ( V_342 == 0 ) {
F_172 () ;
V_342 = V_343 ;
}
F_171 ( V_344 ) ;
F_175 ( & V_345 , V_346 + V_347 ) ;
}
static void F_176 ( struct V_13 * V_10 )
{
F_177 ( & V_348 ) ;
F_16 ( V_10 ) ;
}
struct V_13 * F_75 ( void )
{
struct V_13 * V_95 ;
V_95 = F_22 ( sizeof( struct V_13 ) , V_349 ) ;
if ( V_95 ) {
V_95 -> V_350 = F_176 ;
V_95 -> V_183 = NULL ;
F_178 ( & V_348 ) ;
}
return V_95 ;
}
static void F_179 ( struct V_9 * V_10 )
{
F_177 ( & V_351 ) ;
F_16 ( V_10 ) ;
}
static struct V_9 * F_74 ( void )
{
struct V_9 * V_95 ;
V_95 = F_22 ( sizeof( struct V_9 ) , V_349 ) ;
if ( V_95 ) {
V_95 -> V_75 = NULL ;
V_95 -> V_350 = F_179 ;
F_178 ( & V_351 ) ;
}
return V_95 ;
}
void F_7 ( struct V_9 * V_10 )
{
if ( V_10 -> V_75 )
F_26 ( & V_10 -> V_75 -> V_33 , F_51 ) ;
V_10 -> V_350 ( V_10 ) ;
}
static void F_180 ( struct V_13 * V_10 )
{
F_177 ( & V_352 ) ;
}
static void F_181 ( struct V_9 * V_10 )
{
F_177 ( & V_352 ) ;
}
static void F_182 ( T_1 V_14 ,
struct V_1 * V_2 ,
struct V_160 * V_10 )
{
struct V_13 V_159 ;
struct V_9 V_29 ;
int V_95 ;
V_159 . V_350 = F_180 ;
V_29 . V_350 = F_181 ;
F_183 ( 2 , & V_352 ) ;
V_95 = F_73 ( NULL ,
V_14 ,
V_2 ,
0 ,
V_10 ,
V_14 ,
& V_159 ,
& V_29 ,
0 ,
V_14 -> V_133 [ 0 ] . V_132 ,
V_14 -> V_133 [ 0 ] . V_60 ,
0 , 1 ) ;
if ( V_95 )
F_184 ( 2 , & V_352 ) ;
while ( F_174 ( & V_352 ) != 0 )
F_141 ( V_14 ) ;
}
static void F_185 ( T_1 V_14 , struct V_9 * V_10 )
{
if ( ( V_10 -> V_2 . V_3 == V_56 )
&& ( V_10 -> V_10 . V_87 == V_353 )
&& ( V_10 -> V_10 . V_101 == V_354 )
&& ( V_10 -> V_10 . V_89 [ 0 ] == V_355 ) ) {
V_14 -> V_356 = V_10 -> V_10 . V_89 [ 1 ] ;
V_14 -> V_357 = V_10 -> V_10 . V_89 [ 2 ] & 0x3 ;
}
}
static void F_186 ( T_1 V_14 , struct V_9 * V_10 )
{
if ( ( V_10 -> V_2 . V_3 == V_56 )
&& ( V_10 -> V_10 . V_87 == V_293 )
&& ( V_10 -> V_10 . V_101 == V_358 )
&& ( V_10 -> V_10 . V_89 [ 0 ] == V_355 ) ) {
V_14 -> V_359 = ( V_10 -> V_10 . V_89 [ 6 ] >> 2 ) & 1 ;
V_14 -> V_360 = ( V_10 -> V_10 . V_89 [ 6 ] >> 5 ) & 1 ;
}
}
static void F_187 ( char * V_361 )
{
struct V_160 V_10 ;
T_1 V_14 ;
unsigned char V_89 [ 16 ] ;
struct V_57 * V_291 ;
struct V_1 V_2 ;
V_291 = (struct V_57 * ) & V_2 ;
V_291 -> V_3 = V_56 ;
V_291 -> V_55 = V_73 ;
V_291 -> V_60 = 0 ;
V_10 . V_87 = 0x04 ;
V_10 . V_101 = 2 ;
V_10 . V_89 = V_89 ;
V_10 . V_88 = 8 ;
V_89 [ 0 ] = 0x41 ;
V_89 [ 1 ] = 0x03 ;
V_89 [ 2 ] = 0x20 ;
V_89 [ 4 ] = 0x6f ;
V_89 [ 5 ] = 0xa1 ;
if ( V_361 ) {
V_89 [ 3 ] = V_361 [ 0 ] ;
V_89 [ 6 ] = V_361 [ 1 ] ;
V_89 [ 7 ] = V_361 [ 2 ] ;
}
F_47 (intf, &ipmi_interfaces, link) {
if ( ! V_14 -> V_114 )
continue;
V_14 -> V_330 = 1 ;
V_14 -> V_114 -> V_362 ( V_14 -> V_117 , 1 ) ;
F_182 ( V_14 , & V_2 , & V_10 ) ;
}
#ifdef F_188
if ( ! V_361 )
return;
F_47 (intf, &ipmi_interfaces, link) {
char * V_363 = V_361 ;
struct V_61 * V_364 ;
int V_303 ;
if ( V_14 -> V_42 == - 1 )
continue;
F_189 () ;
V_14 -> V_359 = 0 ;
V_14 -> V_360 = 0 ;
V_14 -> V_356 = 0 ;
V_10 . V_87 = V_165 ;
V_10 . V_101 = V_358 ;
V_10 . V_89 = NULL ;
V_10 . V_88 = 0 ;
V_14 -> V_77 = F_186 ;
F_182 ( V_14 , & V_2 , & V_10 ) ;
if ( V_14 -> V_360 ) {
V_10 . V_87 = V_365 ;
V_10 . V_101 = V_354 ;
V_10 . V_89 = NULL ;
V_10 . V_88 = 0 ;
V_14 -> V_77 = F_185 ;
F_182 ( V_14 , & V_2 , & V_10 ) ;
}
V_14 -> V_77 = NULL ;
if ( ( ( V_14 -> V_356 & 1 ) == 0 )
&& ( V_14 -> V_356 != 0 )
&& ( V_14 -> V_356 != V_14 -> V_133 [ 0 ] . V_132 ) ) {
V_364 = (struct V_61 * ) & V_2 ;
V_364 -> V_3 = V_5 ;
V_364 -> V_55 = 0 ;
V_364 -> V_60 = V_14 -> V_357 ;
V_364 -> V_64 = V_14 -> V_356 ;
} else if ( V_14 -> V_359 ) {
V_291 = (struct V_57 * ) & V_2 ;
V_291 -> V_3 = V_56 ;
V_291 -> V_55 = V_73 ;
V_291 -> V_60 = 0 ;
} else
continue;
V_10 . V_87 = V_366 ;
V_10 . V_101 = V_367 ;
V_10 . V_89 = V_89 ;
V_10 . V_88 = 16 ;
V_303 = 0 ;
while ( * V_363 ) {
int V_157 = strlen ( V_363 ) ;
if ( V_157 > 11 )
V_157 = 11 ;
V_89 [ 0 ] = 0 ;
V_89 [ 1 ] = 0 ;
V_89 [ 2 ] = 0xf0 ;
V_89 [ 3 ] = V_14 -> V_133 [ 0 ] . V_132 ;
V_89 [ 4 ] = V_303 ++ ;
strncpy ( V_89 + 5 , V_363 , 11 ) ;
V_363 += V_157 ;
F_182 ( V_14 , & V_2 , & V_10 ) ;
}
}
#endif
}
static int F_190 ( struct V_368 * V_369 ,
unsigned long V_370 ,
void * V_371 )
{
T_1 V_14 ;
if ( V_372 )
return V_373 ;
V_372 = 1 ;
F_47 (intf, &ipmi_interfaces, link) {
if ( ! V_14 -> V_114 )
continue;
V_14 -> V_330 = 1 ;
V_14 -> V_114 -> V_362 ( V_14 -> V_117 , 1 ) ;
}
#ifdef F_191
F_187 ( V_371 ) ;
#endif
return V_373 ;
}
static int F_46 ( void )
{
int V_95 ;
if ( V_110 )
return 0 ;
V_95 = F_192 ( & V_285 . V_286 ) ;
if ( V_95 ) {
F_65 (KERN_ERR PFX L_94 ) ;
return V_95 ;
}
F_65 ( V_287 L_95
V_374 L_4 ) ;
#ifdef F_95
V_235 = F_99 ( L_96 , NULL ) ;
if ( ! V_235 ) {
F_65 (KERN_ERR PFX L_97 ) ;
return - V_48 ;
}
#endif
F_193 ( & V_345 , F_173 , 0 ) ;
F_175 ( & V_345 , V_346 + V_347 ) ;
F_194 ( & V_375 , & V_376 ) ;
V_110 = 1 ;
return 0 ;
}
static int T_4 F_195 ( void )
{
F_46 () ;
return 0 ;
}
static void T_5 F_196 ( void )
{
int V_377 ;
if ( ! V_110 )
return;
F_197 ( & V_375 , & V_376 ) ;
F_178 ( & V_341 ) ;
F_198 ( & V_345 ) ;
#ifdef F_95
F_199 ( V_235 ) ;
#endif
F_200 ( & V_285 . V_286 ) ;
V_110 = 0 ;
V_377 = F_174 ( & V_348 ) ;
if ( V_377 != 0 )
F_65 (KERN_WARNING PFX L_98 ,
count) ;
V_377 = F_174 ( & V_351 ) ;
if ( V_377 != 0 )
F_65 (KERN_WARNING PFX L_99 ,
count) ;
}
