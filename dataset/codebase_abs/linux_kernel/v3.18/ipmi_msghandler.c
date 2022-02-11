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
F_39 ( V_14 ) ;
} else {
V_95 = - V_100 ;
}
return V_95 ;
}
static int F_40 ( T_1 V_14 ,
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
F_41 ( & ( V_14 -> V_104 ) , V_103 ) ;
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
F_42 ( & ( V_14 -> V_104 ) , V_103 ) ;
return V_95 ;
}
static int F_43 ( T_1 V_14 ,
long V_105 )
{
int V_95 = - V_102 ;
unsigned long V_103 ;
unsigned char V_93 ;
unsigned long V_94 ;
F_44 ( V_105 , V_93 , V_94 ) ;
F_41 ( & ( V_14 -> V_104 ) , V_103 ) ;
if ( ( V_14 -> V_27 [ V_93 ] . V_28 )
&& ( V_14 -> V_27 [ V_93 ] . V_94 == V_94 ) ) {
struct V_27 * V_106 = & ( V_14 -> V_27 [ V_93 ] ) ;
V_106 -> V_90 = V_106 -> V_98 ;
V_95 = 0 ;
}
F_42 ( & ( V_14 -> V_104 ) , V_103 ) ;
return V_95 ;
}
static int F_45 ( T_1 V_14 ,
long V_105 ,
unsigned int V_83 )
{
int V_95 = - V_102 ;
unsigned long V_103 ;
unsigned char V_93 ;
unsigned long V_94 ;
struct V_9 * V_10 = NULL ;
F_44 ( V_105 , V_93 , V_94 ) ;
F_41 ( & ( V_14 -> V_104 ) , V_103 ) ;
if ( ( V_14 -> V_27 [ V_93 ] . V_28 )
&& ( V_14 -> V_27 [ V_93 ] . V_94 == V_94 ) ) {
struct V_27 * V_106 = & ( V_14 -> V_27 [ V_93 ] ) ;
V_106 -> V_28 = 0 ;
V_10 = V_106 -> V_29 ;
V_95 = 0 ;
}
F_42 ( & ( V_14 -> V_104 ) , V_103 ) ;
if ( V_10 )
F_36 ( V_10 , V_83 ) ;
return V_95 ;
}
int F_46 ( unsigned int V_107 ,
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
V_95 = F_47 () ;
if ( V_95 )
return V_95 ;
if ( ! V_110 )
return - V_102 ;
}
V_109 = F_22 ( sizeof( * V_109 ) , V_43 ) ;
if ( ! V_109 )
return - V_48 ;
F_12 ( & V_41 ) ;
F_48 (intf, &ipmi_interfaces, link) {
if ( V_14 -> V_42 == V_107 )
goto V_111;
}
V_95 = - V_72 ;
goto V_112;
V_111:
F_23 ( & V_14 -> V_33 ) ;
F_49 ( & V_109 -> V_33 ) ;
V_109 -> V_80 = V_80 ;
V_109 -> V_82 = V_82 ;
V_109 -> V_14 = V_14 ;
V_109 -> V_113 = false ;
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
V_109 -> V_118 = true ;
F_41 ( & V_14 -> V_104 , V_103 ) ;
F_50 ( & V_109 -> V_12 , & V_14 -> V_119 ) ;
F_42 ( & V_14 -> V_104 , V_103 ) ;
if ( V_80 -> V_120 ) {
if ( F_51 ( & V_14 -> V_121 ) == 1 )
F_39 ( V_14 ) ;
}
* V_75 = V_109 ;
return 0 ;
V_115:
F_26 ( & V_14 -> V_33 , F_17 ) ;
V_112:
F_15 ( & V_41 ) ;
F_16 ( V_109 ) ;
return V_95 ;
}
int F_52 ( int V_107 , struct V_122 * V_89 )
{
int V_95 = 0 ;
T_1 V_14 ;
struct V_123 * V_114 ;
F_12 ( & V_41 ) ;
F_48 (intf, &ipmi_interfaces, link) {
if ( V_14 -> V_42 == V_107 )
goto V_111;
}
V_95 = - V_72 ;
F_15 ( & V_41 ) ;
return V_95 ;
V_111:
V_114 = V_14 -> V_114 ;
V_95 = - V_124 ;
if ( V_114 -> V_125 )
V_95 = V_114 -> V_125 ( V_14 -> V_117 , V_89 ) ;
F_15 ( & V_41 ) ;
return V_95 ;
}
static void F_53 ( struct V_30 * V_31 )
{
T_2 V_75 = F_18 ( V_31 , struct V_126 , V_33 ) ;
F_16 ( V_75 ) ;
}
int F_54 ( T_2 V_75 )
{
T_1 V_14 = V_75 -> V_14 ;
int V_15 ;
unsigned long V_103 ;
struct V_16 * V_17 ;
struct V_16 * V_127 = NULL ;
V_75 -> V_118 = false ;
if ( V_75 -> V_80 -> V_120 )
F_55 ( & V_14 -> V_121 ) ;
if ( V_75 -> V_113 )
F_55 ( & V_14 -> V_121 ) ;
F_41 ( & V_14 -> V_104 , V_103 ) ;
F_56 ( & V_75 -> V_12 ) ;
for ( V_15 = 0 ; V_15 < V_26 ; V_15 ++ ) {
if ( V_14 -> V_27 [ V_15 ] . V_28
&& ( V_14 -> V_27 [ V_15 ] . V_29 -> V_75 == V_75 ) ) {
V_14 -> V_27 [ V_15 ] . V_28 = 0 ;
F_7 ( V_14 -> V_27 [ V_15 ] . V_29 ) ;
}
}
F_42 ( & V_14 -> V_104 , V_103 ) ;
F_12 ( & V_14 -> V_23 ) ;
F_48 (rcvr, &intf->cmd_rcvrs, link) {
if ( V_17 -> V_75 == V_75 ) {
F_56 ( & V_17 -> V_12 ) ;
V_17 -> V_128 = V_127 ;
V_127 = V_17 ;
}
}
F_15 ( & V_14 -> V_23 ) ;
V_25 () ;
while ( V_127 ) {
V_17 = V_127 ;
V_127 = V_17 -> V_128 ;
F_16 ( V_17 ) ;
}
F_12 ( & V_41 ) ;
if ( V_14 -> V_114 ) {
F_30 ( V_14 -> V_114 -> V_52 ) ;
if ( V_14 -> V_114 -> V_129 )
V_14 -> V_114 -> V_129 ( V_14 -> V_117 ) ;
}
F_15 ( & V_41 ) ;
F_26 ( & V_14 -> V_33 , F_17 ) ;
F_26 ( & V_75 -> V_33 , F_53 ) ;
return 0 ;
}
void F_57 ( T_2 V_75 ,
unsigned char * V_130 ,
unsigned char * V_131 )
{
* V_130 = V_75 -> V_14 -> V_132 ;
* V_131 = V_75 -> V_14 -> V_133 ;
}
int F_58 ( T_2 V_75 ,
unsigned int V_55 ,
unsigned char V_134 )
{
if ( V_55 >= V_74 )
return - V_72 ;
V_75 -> V_14 -> V_135 [ V_55 ] . V_134 = V_134 ;
return 0 ;
}
int F_59 ( T_2 V_75 ,
unsigned int V_55 ,
unsigned char * V_134 )
{
if ( V_55 >= V_74 )
return - V_72 ;
* V_134 = V_75 -> V_14 -> V_135 [ V_55 ] . V_134 ;
return 0 ;
}
int F_60 ( T_2 V_75 ,
unsigned int V_55 ,
unsigned char V_136 )
{
if ( V_55 >= V_74 )
return - V_72 ;
V_75 -> V_14 -> V_135 [ V_55 ] . V_60 = V_136 & 0x3 ;
return 0 ;
}
int F_61 ( T_2 V_75 ,
unsigned int V_55 ,
unsigned char * V_134 )
{
if ( V_55 >= V_74 )
return - V_72 ;
* V_134 = V_75 -> V_14 -> V_135 [ V_55 ] . V_60 ;
return 0 ;
}
int F_62 ( T_2 V_75 )
{
int V_137 ;
unsigned long V_103 ;
F_41 ( & V_75 -> V_14 -> V_138 , V_103 ) ;
V_137 = V_75 -> V_14 -> V_139 ;
F_42 ( & V_75 -> V_14 -> V_138 , V_103 ) ;
return V_137 ;
}
static void F_63 ( T_1 V_14 )
{
if ( V_14 -> V_114 -> V_140 )
V_14 -> V_114 -> V_140 (
V_14 -> V_117 , V_14 -> V_141 ) ;
}
int F_64 ( T_2 V_75 , int V_137 )
{
int V_95 = 0 ;
unsigned long V_103 ;
T_1 V_14 = V_75 -> V_14 ;
F_41 ( & V_14 -> V_138 , V_103 ) ;
if ( V_14 -> V_139 != V_137 ) {
switch ( V_137 ) {
case V_142 :
V_14 -> V_141
= ( V_14 -> V_143 > 0 ) ;
break;
case V_144 :
V_14 -> V_141 = false ;
break;
case V_145 :
V_14 -> V_141 = true ;
break;
default:
V_95 = - V_72 ;
goto V_146;
}
V_14 -> V_139 = V_137 ;
F_63 ( V_14 ) ;
}
V_146:
F_42 ( & V_14 -> V_138 , V_103 ) ;
return V_95 ;
}
int F_65 ( T_2 V_75 , bool V_147 )
{
unsigned long V_103 ;
T_1 V_14 = V_75 -> V_14 ;
struct V_9 * V_10 , * V_11 ;
struct V_7 V_148 ;
F_13 ( & V_148 ) ;
F_41 ( & V_14 -> V_149 , V_103 ) ;
if ( V_75 -> V_113 == V_147 )
goto V_150;
V_75 -> V_113 = V_147 ;
if ( V_147 ) {
if ( F_51 ( & V_14 -> V_121 ) == 1 )
F_39 ( V_14 ) ;
} else {
F_55 ( & V_14 -> V_121 ) ;
}
if ( V_14 -> V_151 )
goto V_150;
while ( V_75 -> V_113 && ! F_66 ( & V_14 -> V_22 ) ) {
F_5 (msg, msg2, &intf->waiting_events, link)
F_67 ( & V_10 -> V_12 , & V_148 ) ;
V_14 -> V_152 = 0 ;
if ( V_14 -> V_153 ) {
F_68 (KERN_WARNING PFX L_1
L_2 ) ;
V_14 -> V_153 = 0 ;
}
V_14 -> V_151 = 1 ;
F_42 ( & V_14 -> V_149 , V_103 ) ;
F_5 (msg, msg2, &msgs, link) {
V_10 -> V_75 = V_75 ;
F_23 ( & V_75 -> V_33 ) ;
F_34 ( V_10 ) ;
}
F_41 ( & V_14 -> V_149 , V_103 ) ;
V_14 -> V_151 = 0 ;
}
V_150:
F_42 ( & V_14 -> V_149 , V_103 ) ;
return 0 ;
}
static struct V_16 * F_69 ( T_1 V_14 ,
unsigned char V_87 ,
unsigned char V_101 ,
unsigned char V_154 )
{
struct V_16 * V_17 ;
F_48 (rcvr, &intf->cmd_rcvrs, link) {
if ( ( V_17 -> V_87 == V_87 ) && ( V_17 -> V_101 == V_101 )
&& ( V_17 -> V_155 & ( 1 << V_154 ) ) )
return V_17 ;
}
return NULL ;
}
static int F_70 ( T_1 V_14 ,
unsigned char V_87 ,
unsigned char V_101 ,
unsigned int V_155 )
{
struct V_16 * V_17 ;
F_48 (rcvr, &intf->cmd_rcvrs, link) {
if ( ( V_17 -> V_87 == V_87 ) && ( V_17 -> V_101 == V_101 )
&& ( V_17 -> V_155 & V_155 ) )
return 0 ;
}
return 1 ;
}
int F_71 ( T_2 V_75 ,
unsigned char V_87 ,
unsigned char V_101 ,
unsigned int V_155 )
{
T_1 V_14 = V_75 -> V_14 ;
struct V_16 * V_17 ;
int V_95 = 0 ;
V_17 = F_22 ( sizeof( * V_17 ) , V_43 ) ;
if ( ! V_17 )
return - V_48 ;
V_17 -> V_101 = V_101 ;
V_17 -> V_87 = V_87 ;
V_17 -> V_155 = V_155 ;
V_17 -> V_75 = V_75 ;
F_12 ( & V_14 -> V_23 ) ;
if ( ! F_70 ( V_14 , V_87 , V_101 , V_155 ) ) {
V_95 = - V_156 ;
goto V_146;
}
if ( F_51 ( & V_14 -> V_121 ) == 1 )
F_39 ( V_14 ) ;
F_50 ( & V_17 -> V_12 , & V_14 -> V_24 ) ;
V_146:
F_15 ( & V_14 -> V_23 ) ;
if ( V_95 )
F_16 ( V_17 ) ;
return V_95 ;
}
int F_72 ( T_2 V_75 ,
unsigned char V_87 ,
unsigned char V_101 ,
unsigned int V_155 )
{
T_1 V_14 = V_75 -> V_14 ;
struct V_16 * V_17 ;
struct V_16 * V_127 = NULL ;
int V_15 , V_95 = - V_157 ;
F_12 ( & V_14 -> V_23 ) ;
for ( V_15 = 0 ; V_15 < V_158 ; V_15 ++ ) {
if ( ( ( 1 << V_15 ) & V_155 ) == 0 )
continue;
V_17 = F_69 ( V_14 , V_87 , V_101 , V_15 ) ;
if ( V_17 == NULL )
continue;
if ( V_17 -> V_75 == V_75 ) {
V_95 = 0 ;
V_17 -> V_155 &= ~ V_155 ;
if ( V_17 -> V_155 == 0 ) {
F_56 ( & V_17 -> V_12 ) ;
V_17 -> V_128 = V_127 ;
V_127 = V_17 ;
}
}
}
F_15 ( & V_14 -> V_23 ) ;
V_25 () ;
while ( V_127 ) {
F_55 ( & V_14 -> V_121 ) ;
V_17 = V_127 ;
V_127 = V_17 -> V_128 ;
F_16 ( V_17 ) ;
}
return V_95 ;
}
static unsigned char
F_73 ( unsigned char * V_89 , int V_159 )
{
unsigned char V_160 = 0 ;
for (; V_159 > 0 ; V_159 -- , V_89 ++ )
V_160 += * V_89 ;
return - V_160 ;
}
static inline void F_74 ( struct V_13 * V_161 ,
struct V_162 * V_10 ,
struct V_61 * V_163 ,
long V_105 ,
unsigned char V_164 ,
int V_92 ,
unsigned char V_165 ,
unsigned char V_166 )
{
int V_15 = V_92 ;
V_161 -> V_89 [ 0 ] = ( V_167 << 2 ) ;
V_161 -> V_89 [ 1 ] = V_168 ;
V_161 -> V_89 [ 2 ] = V_163 -> V_55 ;
if ( V_92 )
V_161 -> V_89 [ 3 ] = 0 ;
V_161 -> V_89 [ V_15 + 3 ] = V_163 -> V_64 ;
V_161 -> V_89 [ V_15 + 4 ] = ( V_10 -> V_87 << 2 ) | ( V_163 -> V_60 & 0x3 ) ;
V_161 -> V_89 [ V_15 + 5 ] = F_73 ( & ( V_161 -> V_89 [ V_15 + 3 ] ) , 2 ) ;
V_161 -> V_89 [ V_15 + 6 ] = V_165 ;
V_161 -> V_89 [ V_15 + 7 ] = ( V_164 << 2 ) | V_166 ;
V_161 -> V_89 [ V_15 + 8 ] = V_10 -> V_101 ;
if ( V_10 -> V_88 > 0 )
memcpy ( & ( V_161 -> V_89 [ V_15 + 9 ] ) , V_10 -> V_89 ,
V_10 -> V_88 ) ;
V_161 -> V_169 = V_10 -> V_88 + 9 ;
V_161 -> V_89 [ V_15 + V_161 -> V_169 ]
= F_73 ( & ( V_161 -> V_89 [ V_15 + 6 ] ) ,
V_161 -> V_169 - 6 ) ;
V_161 -> V_169 += 1 + V_15 ;
V_161 -> V_105 = V_105 ;
}
static inline void F_75 ( struct V_13 * V_161 ,
struct V_162 * V_10 ,
struct V_65 * V_170 ,
long V_105 ,
unsigned char V_164 ,
unsigned char V_166 )
{
V_161 -> V_89 [ 0 ] = ( V_167 << 2 ) ;
V_161 -> V_89 [ 1 ] = V_168 ;
V_161 -> V_89 [ 2 ] = V_170 -> V_55 ;
V_161 -> V_89 [ 3 ] = V_170 -> V_70 ;
V_161 -> V_89 [ 4 ] = V_170 -> V_68 ;
V_161 -> V_89 [ 5 ] = ( V_10 -> V_87 << 2 ) | ( V_170 -> V_60 & 0x3 ) ;
V_161 -> V_89 [ 6 ] = F_73 ( & ( V_161 -> V_89 [ 4 ] ) , 2 ) ;
V_161 -> V_89 [ 7 ] = V_170 -> V_69 ;
V_161 -> V_89 [ 8 ] = ( V_164 << 2 ) | V_166 ;
V_161 -> V_89 [ 9 ] = V_10 -> V_101 ;
if ( V_10 -> V_88 > 0 )
memcpy ( & ( V_161 -> V_89 [ 10 ] ) , V_10 -> V_89 ,
V_10 -> V_88 ) ;
V_161 -> V_169 = V_10 -> V_88 + 10 ;
V_161 -> V_89 [ V_161 -> V_169 ]
= F_73 ( & ( V_161 -> V_89 [ 7 ] ) ,
V_161 -> V_169 - 7 ) ;
V_161 -> V_169 += 1 ;
V_161 -> V_105 = V_105 ;
}
static int F_76 ( T_2 V_75 ,
T_1 V_14 ,
struct V_1 * V_2 ,
long V_105 ,
struct V_162 * V_10 ,
void * V_76 ,
void * V_171 ,
struct V_9 * V_172 ,
int V_173 ,
unsigned char V_165 ,
unsigned char V_166 ,
int V_91 ,
unsigned int V_174 )
{
int V_95 = 0 ;
struct V_13 * V_161 ;
struct V_9 * V_29 ;
unsigned long V_103 ;
struct V_123 * V_114 ;
if ( V_172 )
V_29 = V_172 ;
else {
V_29 = F_77 () ;
if ( V_29 == NULL )
return - V_48 ;
}
V_29 -> V_76 = V_76 ;
if ( V_171 )
V_161 = (struct V_13 * ) V_171 ;
else {
V_161 = F_78 () ;
if ( V_161 == NULL ) {
F_7 ( V_29 ) ;
return - V_48 ;
}
}
F_79 () ;
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
struct V_57 * V_175 ;
if ( V_10 -> V_87 & 1 ) {
V_95 = - V_72 ;
goto V_44;
}
V_175 = (struct V_57 * ) V_2 ;
if ( V_175 -> V_60 > 3 ) {
F_35 ( V_14 , V_176 ) ;
V_95 = - V_72 ;
goto V_44;
}
memcpy ( & V_29 -> V_2 , V_175 , sizeof( * V_175 ) ) ;
if ( ( V_10 -> V_87 == V_167 )
&& ( ( V_10 -> V_101 == V_168 )
|| ( V_10 -> V_101 == V_177 )
|| ( V_10 -> V_101 == V_178 ) ) ) {
F_35 ( V_14 , V_176 ) ;
V_95 = - V_72 ;
goto V_44;
}
if ( ( ( V_10 -> V_87 == V_167 )
&& ( ( V_10 -> V_101 == V_179 )
|| ( V_10 -> V_101 == V_180 ) ) )
|| ( V_10 -> V_87 == V_181 ) ) {
F_41 ( & V_14 -> V_138 , V_103 ) ;
V_14 -> V_143
= V_182 ;
if ( ! V_14 -> V_139
&& ! V_14 -> V_141 ) {
V_14 -> V_141 = true ;
F_63 ( V_14 ) ;
}
F_42 ( & V_14 -> V_138 ,
V_103 ) ;
}
if ( ( V_10 -> V_88 + 2 ) > V_183 ) {
F_35 ( V_14 , V_176 ) ;
V_95 = - V_184 ;
goto V_44;
}
V_161 -> V_89 [ 0 ] = ( V_10 -> V_87 << 2 ) | ( V_175 -> V_60 & 0x3 ) ;
V_161 -> V_89 [ 1 ] = V_10 -> V_101 ;
V_161 -> V_105 = V_105 ;
V_161 -> V_185 = V_29 ;
if ( V_10 -> V_88 > 0 )
memcpy ( & ( V_161 -> V_89 [ 2 ] ) , V_10 -> V_89 , V_10 -> V_88 ) ;
V_161 -> V_169 = V_10 -> V_88 + 2 ;
F_35 ( V_14 , V_186 ) ;
} else if ( F_2 ( V_2 ) || F_3 ( V_2 ) ) {
struct V_61 * V_163 ;
unsigned char V_164 ;
long V_94 ;
int V_92 = 0 ;
if ( V_2 -> V_55 >= V_74 ) {
F_35 ( V_14 , V_176 ) ;
V_95 = - V_72 ;
goto V_44;
}
if ( V_14 -> V_135 [ V_2 -> V_55 ] . V_187
!= V_188 ) {
F_35 ( V_14 , V_176 ) ;
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
if ( V_174 == 0 )
V_174 = 1000 ;
if ( ( V_10 -> V_88 + 10 + V_92 ) > V_183 ) {
F_35 ( V_14 , V_176 ) ;
V_95 = - V_184 ;
goto V_44;
}
V_163 = (struct V_61 * ) V_2 ;
if ( V_163 -> V_60 > 3 ) {
F_35 ( V_14 , V_176 ) ;
V_95 = - V_72 ;
goto V_44;
}
memcpy ( & V_29 -> V_2 , V_163 , sizeof( * V_163 ) ) ;
if ( V_29 -> V_10 . V_87 & 0x1 ) {
F_35 ( V_14 , V_189 ) ;
F_74 ( V_161 , V_10 , V_163 , V_105 ,
V_105 , V_92 ,
V_165 , V_166 ) ;
V_161 -> V_185 = V_29 ;
} else {
F_41 ( & ( V_14 -> V_104 ) , V_103 ) ;
V_95 = F_37 ( V_14 ,
V_29 ,
V_174 ,
V_91 ,
V_92 ,
& V_164 ,
& V_94 ) ;
if ( V_95 ) {
F_42 ( & ( V_14 -> V_104 ) ,
V_103 ) ;
goto V_44;
}
F_35 ( V_14 , V_190 ) ;
F_74 ( V_161 , V_10 , V_163 ,
F_80 ( V_164 , V_94 ) ,
V_164 , V_92 ,
V_165 , V_166 ) ;
memcpy ( V_29 -> V_86 , V_161 -> V_89 ,
V_161 -> V_169 ) ;
V_29 -> V_10 . V_89 = V_29 -> V_86 ;
V_29 -> V_10 . V_88 = V_161 -> V_169 ;
F_42 ( & ( V_14 -> V_104 ) , V_103 ) ;
}
} else if ( F_1 ( V_2 ) ) {
struct V_65 * V_170 ;
unsigned char V_164 ;
long V_94 ;
if ( V_2 -> V_55 >= V_74 ) {
F_35 ( V_14 , V_176 ) ;
V_95 = - V_72 ;
goto V_44;
}
if ( ( V_14 -> V_135 [ V_2 -> V_55 ] . V_187
!= V_191 )
&& ( V_14 -> V_135 [ V_2 -> V_55 ] . V_187
!= V_192 ) ) {
F_35 ( V_14 , V_176 ) ;
V_95 = - V_72 ;
goto V_44;
}
V_91 = 4 ;
if ( V_174 == 0 )
V_174 = 1000 ;
if ( ( V_10 -> V_88 + 12 ) > V_183 ) {
F_35 ( V_14 , V_176 ) ;
V_95 = - V_184 ;
goto V_44;
}
V_170 = (struct V_65 * ) V_2 ;
if ( V_170 -> V_60 > 3 ) {
F_35 ( V_14 , V_176 ) ;
V_95 = - V_72 ;
goto V_44;
}
memcpy ( & V_29 -> V_2 , V_170 , sizeof( * V_170 ) ) ;
if ( V_29 -> V_10 . V_87 & 0x1 ) {
F_35 ( V_14 , V_193 ) ;
F_75 ( V_161 , V_10 , V_170 , V_105 ,
V_105 , V_166 ) ;
V_161 -> V_185 = V_29 ;
} else {
F_41 ( & ( V_14 -> V_104 ) , V_103 ) ;
V_95 = F_37 ( V_14 ,
V_29 ,
V_174 ,
V_91 ,
0 ,
& V_164 ,
& V_94 ) ;
if ( V_95 ) {
F_42 ( & ( V_14 -> V_104 ) ,
V_103 ) ;
goto V_44;
}
F_35 ( V_14 , V_194 ) ;
F_75 ( V_161 , V_10 , V_170 ,
F_80 ( V_164 , V_94 ) ,
V_164 , V_166 ) ;
memcpy ( V_29 -> V_86 , V_161 -> V_89 ,
V_161 -> V_169 ) ;
V_29 -> V_10 . V_89 = V_29 -> V_86 ;
V_29 -> V_10 . V_88 = V_161 -> V_169 ;
F_42 ( & ( V_14 -> V_104 ) , V_103 ) ;
}
} else {
F_35 ( V_14 , V_176 ) ;
V_95 = - V_72 ;
goto V_44;
}
#ifdef F_81
{
int V_195 ;
for ( V_195 = 0 ; V_195 < V_161 -> V_169 ; V_195 ++ )
F_68 ( L_3 , V_161 -> V_89 [ V_195 ] ) ;
F_68 ( L_4 ) ;
}
#endif
V_114 -> V_196 ( V_14 -> V_117 , V_161 , V_173 ) ;
F_82 () ;
return 0 ;
V_44:
F_82 () ;
F_9 ( V_161 ) ;
F_7 ( V_29 ) ;
return V_95 ;
}
static int F_83 ( T_1 V_14 ,
struct V_1 * V_2 ,
unsigned char * V_197 ,
unsigned char * V_60 )
{
if ( V_2 -> V_55 >= V_74 )
return - V_72 ;
* V_60 = V_14 -> V_135 [ V_2 -> V_55 ] . V_60 ;
* V_197 = V_14 -> V_135 [ V_2 -> V_55 ] . V_134 ;
return 0 ;
}
int F_84 ( T_2 V_75 ,
struct V_1 * V_2 ,
long V_105 ,
struct V_162 * V_10 ,
void * V_76 ,
int V_173 ,
int V_91 ,
unsigned int V_174 )
{
unsigned char V_197 = 0 , V_60 = 0 ;
int V_95 ;
if ( ! V_75 )
return - V_72 ;
V_95 = F_83 ( V_75 -> V_14 , V_2 , & V_197 , & V_60 ) ;
if ( V_95 )
return V_95 ;
return F_76 ( V_75 ,
V_75 -> V_14 ,
V_2 ,
V_105 ,
V_10 ,
V_76 ,
NULL , NULL ,
V_173 ,
V_197 ,
V_60 ,
V_91 ,
V_174 ) ;
}
int F_85 ( T_2 V_75 ,
struct V_1 * V_2 ,
long V_105 ,
struct V_162 * V_10 ,
void * V_76 ,
void * V_171 ,
struct V_9 * V_172 ,
int V_173 )
{
unsigned char V_197 = 0 , V_60 = 0 ;
int V_95 ;
if ( ! V_75 )
return - V_72 ;
V_95 = F_83 ( V_75 -> V_14 , V_2 , & V_197 , & V_60 ) ;
if ( V_95 )
return V_95 ;
return F_76 ( V_75 ,
V_75 -> V_14 ,
V_2 ,
V_105 ,
V_10 ,
V_76 ,
V_171 ,
V_172 ,
V_173 ,
V_197 ,
V_60 ,
- 1 , 0 ) ;
}
static int F_86 ( struct V_198 * V_195 , void * V_199 )
{
T_1 V_14 = V_195 -> V_200 ;
int V_15 ;
F_87 ( V_195 , L_5 , V_14 -> V_135 [ 0 ] . V_134 ) ;
for ( V_15 = 1 ; V_15 < V_74 ; V_15 ++ )
F_87 ( V_195 , L_6 , V_14 -> V_135 [ V_15 ] . V_134 ) ;
return F_88 ( V_195 , '\n' ) ;
}
static int F_89 ( struct V_201 * V_201 , struct V_202 * V_202 )
{
return F_90 ( V_202 , F_86 , F_91 ( V_201 ) ) ;
}
static int F_92 ( struct V_198 * V_195 , void * V_199 )
{
T_1 V_14 = V_195 -> V_200 ;
return F_87 ( V_195 , L_7 ,
V_132 ( & V_14 -> V_203 -> V_204 ) ,
V_133 ( & V_14 -> V_203 -> V_204 ) ) ;
}
static int F_93 ( struct V_201 * V_201 , struct V_202 * V_202 )
{
return F_90 ( V_202 , F_92 , F_91 ( V_201 ) ) ;
}
static int F_94 ( struct V_198 * V_195 , void * V_199 )
{
T_1 V_14 = V_195 -> V_200 ;
F_87 ( V_195 , L_8 ,
F_95 ( V_14 , V_176 ) ) ;
F_87 ( V_195 , L_9 ,
F_95 ( V_14 , V_186 ) ) ;
F_87 ( V_195 , L_10 ,
F_95 ( V_14 , V_78 ) ) ;
F_87 ( V_195 , L_11 ,
F_95 ( V_14 , V_79 ) ) ;
F_87 ( V_195 , L_12 ,
F_95 ( V_14 , V_190 ) ) ;
F_87 ( V_195 , L_13 ,
F_95 ( V_14 , V_205 ) ) ;
F_87 ( V_195 , L_14 ,
F_95 ( V_14 , V_206 ) ) ;
F_87 ( V_195 , L_15 ,
F_95 ( V_14 , V_207 ) ) ;
F_87 ( V_195 , L_16 ,
F_95 ( V_14 , V_208 ) ) ;
F_87 ( V_195 , L_17 ,
F_95 ( V_14 , V_189 ) ) ;
F_87 ( V_195 , L_18 ,
F_95 ( V_14 , V_209 ) ) ;
F_87 ( V_195 , L_19 ,
F_95 ( V_14 , V_210 ) ) ;
F_87 ( V_195 , L_20 ,
F_95 ( V_14 , V_211 ) ) ;
F_87 ( V_195 , L_21 ,
F_95 ( V_14 , V_194 ) ) ;
F_87 ( V_195 , L_22 ,
F_95 ( V_14 , V_212 ) ) ;
F_87 ( V_195 , L_23 ,
F_95 ( V_14 , V_213 ) ) ;
F_87 ( V_195 , L_24 ,
F_95 ( V_14 , V_214 ) ) ;
F_87 ( V_195 , L_25 ,
F_95 ( V_14 , V_193 ) ) ;
F_87 ( V_195 , L_26 ,
F_95 ( V_14 , V_215 ) ) ;
F_87 ( V_195 , L_27 ,
F_95 ( V_14 , V_216 ) ) ;
F_87 ( V_195 , L_28 ,
F_95 ( V_14 , V_217 ) ) ;
F_87 ( V_195 , L_29 ,
F_95 ( V_14 , V_218 ) ) ;
F_87 ( V_195 , L_30 ,
F_95 ( V_14 , V_219 ) ) ;
F_87 ( V_195 , L_31 ,
F_95 ( V_14 , V_220 ) ) ;
F_87 ( V_195 , L_32 ,
F_95 ( V_14 , V_221 ) ) ;
F_87 ( V_195 , L_33 ,
F_95 ( V_14 , V_222 ) ) ;
F_87 ( V_195 , L_34 ,
F_95 ( V_14 , V_223 ) ) ;
F_87 ( V_195 , L_35 ,
F_95 ( V_14 , V_224 ) ) ;
return 0 ;
}
static int F_96 ( struct V_201 * V_201 , struct V_202 * V_202 )
{
return F_90 ( V_202 , F_94 , F_91 ( V_201 ) ) ;
}
int F_97 ( T_1 V_225 , char * V_226 ,
const struct V_227 * V_228 ,
void * V_89 )
{
int V_95 = 0 ;
#ifdef F_98
struct V_229 * V_202 ;
struct V_230 * V_231 ;
V_231 = F_22 ( sizeof( * V_231 ) , V_43 ) ;
if ( ! V_231 )
return - V_48 ;
V_231 -> V_226 = F_99 ( V_226 , V_43 ) ;
if ( ! V_231 -> V_226 ) {
F_16 ( V_231 ) ;
return - V_48 ;
}
V_202 = F_100 ( V_226 , 0 , V_225 -> V_232 , V_228 , V_89 ) ;
if ( ! V_202 ) {
F_16 ( V_231 -> V_226 ) ;
F_16 ( V_231 ) ;
V_95 = - V_48 ;
} else {
F_12 ( & V_225 -> V_233 ) ;
V_231 -> V_128 = V_225 -> V_234 ;
V_225 -> V_234 = V_231 ;
F_15 ( & V_225 -> V_233 ) ;
}
#endif
return V_95 ;
}
static int F_101 ( T_1 V_225 , int V_235 )
{
int V_95 = 0 ;
#ifdef F_98
sprintf ( V_225 -> V_236 , L_36 , V_235 ) ;
V_225 -> V_232 = F_102 ( V_225 -> V_236 , V_237 ) ;
if ( ! V_225 -> V_232 )
V_95 = - V_48 ;
if ( V_95 == 0 )
V_95 = F_97 ( V_225 , L_37 ,
& V_238 ,
V_225 ) ;
if ( V_95 == 0 )
V_95 = F_97 ( V_225 , L_38 ,
& V_239 ,
V_225 ) ;
if ( V_95 == 0 )
V_95 = F_97 ( V_225 , L_39 ,
& V_240 ,
V_225 ) ;
#endif
return V_95 ;
}
static void F_103 ( T_1 V_225 )
{
#ifdef F_98
struct V_230 * V_231 ;
F_12 ( & V_225 -> V_233 ) ;
while ( V_225 -> V_234 ) {
V_231 = V_225 -> V_234 ;
V_225 -> V_234 = V_231 -> V_128 ;
F_104 ( V_231 -> V_226 , V_225 -> V_232 ) ;
F_16 ( V_231 -> V_226 ) ;
F_16 ( V_231 ) ;
}
F_15 ( & V_225 -> V_233 ) ;
F_104 ( V_225 -> V_236 , V_237 ) ;
#endif
}
static int F_105 ( struct V_49 * V_50 , void * V_89 )
{
unsigned char * V_204 = V_89 ;
struct V_241 * V_203 = F_106 ( V_50 ) ;
return memcmp ( V_203 -> V_242 , V_204 , 16 ) == 0 ;
}
static struct V_241 * F_107 ( struct V_243 * V_244 ,
unsigned char * V_242 )
{
struct V_49 * V_50 ;
V_50 = F_108 ( V_244 , NULL , V_242 , F_105 ) ;
if ( V_50 )
return F_106 ( V_50 ) ;
else
return NULL ;
}
static int F_109 ( struct V_49 * V_50 , void * V_89 )
{
struct V_245 * V_204 = V_89 ;
struct V_241 * V_203 = F_106 ( V_50 ) ;
return ( V_203 -> V_204 . V_246 == V_204 -> V_246
&& V_203 -> V_204 . V_247 == V_204 -> V_247 ) ;
}
static struct V_241 * F_110 (
struct V_243 * V_244 ,
unsigned int V_246 , unsigned char V_247 )
{
struct V_245 V_204 = {
. V_246 = V_246 ,
. V_247 = V_247 ,
} ;
struct V_49 * V_50 ;
V_50 = F_108 ( V_244 , NULL , & V_204 , F_109 ) ;
if ( V_50 )
return F_106 ( V_50 ) ;
else
return NULL ;
}
static T_3 F_111 ( struct V_49 * V_50 ,
struct V_248 * V_249 ,
char * V_250 )
{
struct V_241 * V_203 = F_106 ( V_50 ) ;
return snprintf ( V_250 , 10 , L_40 , V_203 -> V_204 . V_247 ) ;
}
static T_3 F_112 ( struct V_49 * V_50 ,
struct V_248 * V_249 ,
char * V_250 )
{
struct V_241 * V_203 = F_106 ( V_50 ) ;
return snprintf ( V_250 , 10 , L_40 ,
( V_203 -> V_204 . V_251 & 0x80 ) >> 7 ) ;
}
static T_3 F_113 ( struct V_49 * V_50 , struct V_248 * V_249 ,
char * V_250 )
{
struct V_241 * V_203 = F_106 ( V_50 ) ;
return snprintf ( V_250 , 20 , L_40 ,
V_203 -> V_204 . V_251 & 0x0F ) ;
}
static T_3 F_114 ( struct V_49 * V_50 ,
struct V_248 * V_249 ,
char * V_250 )
{
struct V_241 * V_203 = F_106 ( V_50 ) ;
return snprintf ( V_250 , 20 , L_41 , V_203 -> V_204 . V_252 ,
V_203 -> V_204 . V_253 ) ;
}
static T_3 F_115 ( struct V_49 * V_50 ,
struct V_248 * V_249 ,
char * V_250 )
{
struct V_241 * V_203 = F_106 ( V_50 ) ;
return snprintf ( V_250 , 20 , L_7 ,
V_132 ( & V_203 -> V_204 ) ,
V_133 ( & V_203 -> V_204 ) ) ;
}
static T_3 F_116 ( struct V_49 * V_50 ,
struct V_248 * V_249 ,
char * V_250 )
{
struct V_241 * V_203 = F_106 ( V_50 ) ;
return snprintf ( V_250 , 10 , L_42 ,
V_203 -> V_204 . V_254 ) ;
}
static T_3 F_117 ( struct V_49 * V_50 ,
struct V_248 * V_249 ,
char * V_250 )
{
struct V_241 * V_203 = F_106 ( V_50 ) ;
return snprintf ( V_250 , 20 , L_43 , V_203 -> V_204 . V_255 ) ;
}
static T_3 F_118 ( struct V_49 * V_50 ,
struct V_248 * V_249 ,
char * V_250 )
{
struct V_241 * V_203 = F_106 ( V_50 ) ;
return snprintf ( V_250 , 10 , L_44 , V_203 -> V_204 . V_246 ) ;
}
static T_3 F_119 ( struct V_49 * V_50 ,
struct V_248 * V_249 ,
char * V_250 )
{
struct V_241 * V_203 = F_106 ( V_50 ) ;
return snprintf ( V_250 , 21 , L_45 ,
V_203 -> V_204 . V_256 [ 3 ] ,
V_203 -> V_204 . V_256 [ 2 ] ,
V_203 -> V_204 . V_256 [ 1 ] ,
V_203 -> V_204 . V_256 [ 0 ] ) ;
}
static T_3 F_120 ( struct V_49 * V_50 , struct V_248 * V_249 ,
char * V_250 )
{
struct V_241 * V_203 = F_106 ( V_50 ) ;
return snprintf ( V_250 , 100 , L_46 ,
( long long ) V_203 -> V_242 [ 0 ] ,
( long long ) V_203 -> V_242 [ 8 ] ) ;
}
static void F_121 ( struct V_241 * V_203 )
{
if ( ! V_203 -> V_50 )
return;
F_122 ( & V_203 -> V_50 -> V_50 ,
& V_203 -> V_257 ) ;
F_122 ( & V_203 -> V_50 -> V_50 ,
& V_203 -> V_258 ) ;
F_122 ( & V_203 -> V_50 -> V_50 ,
& V_203 -> V_259 ) ;
F_122 ( & V_203 -> V_50 -> V_50 ,
& V_203 -> V_260 ) ;
F_122 ( & V_203 -> V_50 -> V_50 ,
& V_203 -> V_261 ) ;
F_122 ( & V_203 -> V_50 -> V_50 ,
& V_203 -> V_262 ) ;
F_122 ( & V_203 -> V_50 -> V_50 ,
& V_203 -> V_263 ) ;
F_122 ( & V_203 -> V_50 -> V_50 ,
& V_203 -> V_264 ) ;
if ( V_203 -> V_204 . V_265 )
F_122 ( & V_203 -> V_50 -> V_50 ,
& V_203 -> V_266 ) ;
if ( V_203 -> V_267 )
F_122 ( & V_203 -> V_50 -> V_50 ,
& V_203 -> V_268 ) ;
}
static void
F_123 ( struct V_30 * V_31 )
{
struct V_241 * V_203 ;
V_203 = F_18 ( V_31 , struct V_241 , V_33 ) ;
F_121 ( V_203 ) ;
F_124 ( V_203 -> V_50 ) ;
F_16 ( V_203 ) ;
}
static void F_125 ( T_1 V_14 )
{
struct V_241 * V_203 = V_14 -> V_203 ;
if ( V_14 -> V_269 ) {
F_126 ( & V_14 -> V_47 -> V_270 , V_14 -> V_269 ) ;
F_16 ( V_14 -> V_269 ) ;
V_14 -> V_269 = NULL ;
}
if ( V_14 -> V_271 ) {
F_126 ( & V_203 -> V_50 -> V_50 . V_270 , V_14 -> V_271 ) ;
F_16 ( V_14 -> V_271 ) ;
V_14 -> V_271 = NULL ;
}
F_12 ( & V_272 ) ;
F_26 ( & V_203 -> V_33 , F_123 ) ;
V_14 -> V_203 = NULL ;
F_15 ( & V_272 ) ;
}
static int F_127 ( struct V_241 * V_203 )
{
int V_83 ;
V_203 -> V_257 . V_249 . V_226 = L_47 ;
V_203 -> V_257 . V_249 . V_137 = V_273 ;
V_203 -> V_257 . V_274 = F_111 ;
F_128 ( & V_203 -> V_257 . V_249 ) ;
V_203 -> V_258 . V_249 . V_226 = L_48 ;
V_203 -> V_258 . V_249 . V_137 = V_273 ;
V_203 -> V_258 . V_274 = F_112 ;
F_128 ( & V_203 -> V_258 . V_249 ) ;
V_203 -> V_259 . V_249 . V_226 = L_49 ;
V_203 -> V_259 . V_249 . V_137 = V_273 ;
V_203 -> V_259 . V_274 = F_113 ;
F_128 ( & V_203 -> V_259 . V_249 ) ;
V_203 -> V_260 . V_249 . V_226 = L_50 ;
V_203 -> V_260 . V_249 . V_137 = V_273 ;
V_203 -> V_260 . V_274 = F_114 ;
F_128 ( & V_203 -> V_260 . V_249 ) ;
V_203 -> V_261 . V_249 . V_226 = L_51 ;
V_203 -> V_261 . V_249 . V_137 = V_273 ;
V_203 -> V_261 . V_274 = F_115 ;
F_128 ( & V_203 -> V_261 . V_249 ) ;
V_203 -> V_262 . V_249 . V_226 = L_52 ;
V_203 -> V_262 . V_249 . V_137 = V_273 ;
V_203 -> V_262 . V_274 = F_116 ;
F_128 ( & V_203 -> V_262 . V_249 ) ;
V_203 -> V_263 . V_249 . V_226 = L_53 ;
V_203 -> V_263 . V_249 . V_137 = V_273 ;
V_203 -> V_263 . V_274 = F_117 ;
F_128 ( & V_203 -> V_263 . V_249 ) ;
V_203 -> V_264 . V_249 . V_226 = L_54 ;
V_203 -> V_264 . V_249 . V_137 = V_273 ;
V_203 -> V_264 . V_274 = F_118 ;
F_128 ( & V_203 -> V_264 . V_249 ) ;
V_203 -> V_268 . V_249 . V_226 = L_55 ;
V_203 -> V_268 . V_249 . V_137 = V_273 ;
V_203 -> V_268 . V_274 = F_120 ;
F_128 ( & V_203 -> V_268 . V_249 ) ;
V_203 -> V_266 . V_249 . V_226 = L_56 ;
V_203 -> V_266 . V_249 . V_137 = V_273 ;
V_203 -> V_266 . V_274 = F_119 ;
F_128 ( & V_203 -> V_266 . V_249 ) ;
V_83 = F_129 ( & V_203 -> V_50 -> V_50 ,
& V_203 -> V_257 ) ;
if ( V_83 )
goto V_150;
V_83 = F_129 ( & V_203 -> V_50 -> V_50 ,
& V_203 -> V_258 ) ;
if ( V_83 )
goto V_275;
V_83 = F_129 ( & V_203 -> V_50 -> V_50 ,
& V_203 -> V_259 ) ;
if ( V_83 )
goto V_276;
V_83 = F_129 ( & V_203 -> V_50 -> V_50 ,
& V_203 -> V_260 ) ;
if ( V_83 )
goto V_277;
V_83 = F_129 ( & V_203 -> V_50 -> V_50 ,
& V_203 -> V_261 ) ;
if ( V_83 )
goto V_278;
V_83 = F_129 ( & V_203 -> V_50 -> V_50 ,
& V_203 -> V_262 ) ;
if ( V_83 )
goto V_279;
V_83 = F_129 ( & V_203 -> V_50 -> V_50 ,
& V_203 -> V_263 ) ;
if ( V_83 )
goto V_280;
V_83 = F_129 ( & V_203 -> V_50 -> V_50 ,
& V_203 -> V_264 ) ;
if ( V_83 )
goto V_281;
if ( V_203 -> V_204 . V_265 ) {
V_83 = F_129 ( & V_203 -> V_50 -> V_50 ,
& V_203 -> V_266 ) ;
if ( V_83 )
goto V_282;
}
if ( V_203 -> V_267 ) {
V_83 = F_129 ( & V_203 -> V_50 -> V_50 ,
& V_203 -> V_268 ) ;
if ( V_83 )
goto V_283;
}
return 0 ;
V_283:
if ( V_203 -> V_204 . V_265 )
F_122 ( & V_203 -> V_50 -> V_50 ,
& V_203 -> V_266 ) ;
V_282:
F_122 ( & V_203 -> V_50 -> V_50 ,
& V_203 -> V_264 ) ;
V_281:
F_122 ( & V_203 -> V_50 -> V_50 ,
& V_203 -> V_263 ) ;
V_280:
F_122 ( & V_203 -> V_50 -> V_50 ,
& V_203 -> V_262 ) ;
V_279:
F_122 ( & V_203 -> V_50 -> V_50 ,
& V_203 -> V_261 ) ;
V_278:
F_122 ( & V_203 -> V_50 -> V_50 ,
& V_203 -> V_260 ) ;
V_277:
F_122 ( & V_203 -> V_50 -> V_50 ,
& V_203 -> V_259 ) ;
V_276:
F_122 ( & V_203 -> V_50 -> V_50 ,
& V_203 -> V_258 ) ;
V_275:
F_122 ( & V_203 -> V_50 -> V_50 ,
& V_203 -> V_257 ) ;
V_150:
return V_83 ;
}
static int F_130 ( T_1 V_14 , int V_284 ,
const char * V_269 )
{
int V_95 ;
struct V_241 * V_203 = V_14 -> V_203 ;
struct V_241 * V_285 ;
int V_159 ;
char V_286 [ 1 ] ;
F_12 ( & V_272 ) ;
if ( V_203 -> V_267 )
V_285 = F_107 ( & V_287 . V_288 , V_203 -> V_242 ) ;
else
V_285 = F_110 ( & V_287 . V_288 ,
V_203 -> V_204 . V_246 ,
V_203 -> V_204 . V_247 ) ;
if ( V_285 ) {
F_16 ( V_203 ) ;
V_14 -> V_203 = V_285 ;
V_203 = V_285 ;
F_23 ( & V_203 -> V_33 ) ;
F_15 ( & V_272 ) ;
F_68 ( V_289
L_57
L_58 ,
V_203 -> V_204 . V_255 ,
V_203 -> V_204 . V_246 ,
V_203 -> V_204 . V_247 ) ;
} else {
char V_226 [ 14 ] ;
unsigned char V_290 = V_203 -> V_204 . V_247 ;
int V_291 = 0 ;
snprintf ( V_226 , sizeof( V_226 ) ,
L_59 , V_203 -> V_204 . V_246 ) ;
while ( F_110 ( & V_287 . V_288 ,
V_203 -> V_204 . V_246 ,
V_203 -> V_204 . V_247 ) ) {
if ( ! V_291 ) {
F_68 (KERN_WARNING PFX
L_60
L_61
L_62
L_63
L_64
L_65 ,
bmc->id.product_id, bmc->id.device_id) ;
V_291 = 1 ;
}
V_203 -> V_204 . V_247 ++ ;
if ( V_203 -> V_204 . V_247 == V_290 ) {
F_68 (KERN_ERR PFX
L_66 ) ;
break;
}
}
V_203 -> V_50 = F_131 ( V_226 , V_203 -> V_204 . V_247 ) ;
if ( ! V_203 -> V_50 ) {
F_15 ( & V_272 ) ;
F_68 ( V_292
L_67
L_68 ) ;
return - V_48 ;
}
V_203 -> V_50 -> V_50 . V_288 = & V_287 . V_288 ;
F_132 ( & V_203 -> V_50 -> V_50 , V_203 ) ;
F_49 ( & V_203 -> V_33 ) ;
V_95 = F_133 ( V_203 -> V_50 ) ;
F_15 ( & V_272 ) ;
if ( V_95 ) {
F_134 ( V_203 -> V_50 ) ;
V_203 -> V_50 = NULL ;
F_68 ( V_292
L_67
L_69 ,
V_95 ) ;
return V_95 ;
}
V_95 = F_127 ( V_203 ) ;
if ( V_95 ) {
F_12 ( & V_272 ) ;
F_124 ( V_203 -> V_50 ) ;
F_15 ( & V_272 ) ;
return V_95 ;
}
F_135 ( V_14 -> V_47 , L_70
L_71 ,
V_203 -> V_204 . V_255 ,
V_203 -> V_204 . V_246 ,
V_203 -> V_204 . V_247 ) ;
}
V_14 -> V_269 = F_99 ( V_269 , V_43 ) ;
if ( ! V_14 -> V_269 ) {
V_95 = - V_48 ;
F_68 ( V_292
L_72 ,
V_95 ) ;
goto V_44;
}
V_95 = F_136 ( & V_14 -> V_47 -> V_270 ,
& V_203 -> V_50 -> V_50 . V_270 , V_14 -> V_269 ) ;
if ( V_95 ) {
F_16 ( V_14 -> V_269 ) ;
V_14 -> V_269 = NULL ;
F_68 ( V_292
L_73 ,
V_95 ) ;
goto V_44;
}
V_159 = snprintf ( V_286 , 0 , L_74 , V_284 ) ;
V_14 -> V_271 = F_22 ( V_159 + 1 , V_43 ) ;
if ( ! V_14 -> V_271 ) {
F_16 ( V_14 -> V_269 ) ;
V_14 -> V_269 = NULL ;
V_95 = - V_48 ;
F_68 ( V_292
L_75 ,
V_95 ) ;
goto V_44;
}
snprintf ( V_14 -> V_271 , V_159 + 1 , L_74 , V_284 ) ;
V_95 = F_136 ( & V_203 -> V_50 -> V_50 . V_270 , & V_14 -> V_47 -> V_270 ,
V_14 -> V_271 ) ;
if ( V_95 ) {
F_16 ( V_14 -> V_269 ) ;
V_14 -> V_269 = NULL ;
F_16 ( V_14 -> V_271 ) ;
V_14 -> V_271 = NULL ;
F_68 ( V_292
L_67
L_76 ,
V_95 ) ;
goto V_44;
}
return 0 ;
V_44:
F_125 ( V_14 ) ;
return V_95 ;
}
static int
F_137 ( T_1 V_14 , int V_154 )
{
struct V_162 V_10 ;
struct V_57 V_293 ;
V_293 . V_3 = V_56 ;
V_293 . V_55 = V_73 ;
V_293 . V_60 = 0 ;
V_10 . V_87 = V_167 ;
V_10 . V_101 = V_294 ;
V_10 . V_89 = NULL ;
V_10 . V_88 = 0 ;
return F_76 ( NULL ,
V_14 ,
(struct V_1 * ) & V_293 ,
0 ,
& V_10 ,
V_14 ,
NULL ,
NULL ,
0 ,
V_14 -> V_135 [ 0 ] . V_134 ,
V_14 -> V_135 [ 0 ] . V_60 ,
- 1 , 0 ) ;
}
static void
F_138 ( T_1 V_14 , struct V_9 * V_10 )
{
if ( ( V_10 -> V_2 . V_3 != V_56 )
|| ( V_10 -> V_10 . V_87 != V_295 )
|| ( V_10 -> V_10 . V_101 != V_294 ) )
return;
if ( V_10 -> V_10 . V_89 [ 0 ] != 0 ) {
V_14 -> V_203 -> V_267 = 0 ;
goto V_150;
}
if ( V_10 -> V_10 . V_88 < 17 ) {
V_14 -> V_203 -> V_267 = 0 ;
F_68 (KERN_WARNING PFX
L_77
L_78
L_79 ,
msg->msg.data_len) ;
goto V_150;
}
memcpy ( V_14 -> V_203 -> V_242 , V_10 -> V_10 . V_89 , 16 ) ;
V_14 -> V_203 -> V_267 = 1 ;
V_150:
F_139 ( & V_14 -> V_296 ) ;
}
static void
F_140 ( T_1 V_14 )
{
int V_95 ;
V_14 -> V_203 -> V_267 = 0x2 ;
V_14 -> V_77 = F_138 ;
V_95 = F_137 ( V_14 , 0 ) ;
if ( V_95 )
V_14 -> V_203 -> V_267 = 0 ;
F_141 ( V_14 -> V_296 , V_14 -> V_203 -> V_267 != 2 ) ;
V_14 -> V_77 = NULL ;
}
static int
F_142 ( T_1 V_14 , int V_154 )
{
struct V_162 V_10 ;
unsigned char V_89 [ 1 ] ;
struct V_57 V_293 ;
V_293 . V_3 = V_56 ;
V_293 . V_55 = V_73 ;
V_293 . V_60 = 0 ;
V_10 . V_87 = V_167 ;
V_10 . V_101 = V_297 ;
V_10 . V_89 = V_89 ;
V_10 . V_88 = 1 ;
V_89 [ 0 ] = V_154 ;
return F_76 ( NULL ,
V_14 ,
(struct V_1 * ) & V_293 ,
0 ,
& V_10 ,
V_14 ,
NULL ,
NULL ,
0 ,
V_14 -> V_135 [ 0 ] . V_134 ,
V_14 -> V_135 [ 0 ] . V_60 ,
- 1 , 0 ) ;
}
static void
F_143 ( T_1 V_14 , struct V_9 * V_10 )
{
int V_95 = 0 ;
int V_154 ;
if ( ( V_10 -> V_2 . V_3 == V_56 )
&& ( V_10 -> V_10 . V_87 == V_295 )
&& ( V_10 -> V_10 . V_101 == V_297 ) ) {
if ( V_10 -> V_10 . V_89 [ 0 ] != 0 ) {
if ( V_10 -> V_10 . V_89 [ 0 ] == V_298 ) {
V_14 -> V_135 [ 0 ] . V_187
= V_188 ;
V_14 -> V_135 [ 0 ] . V_299
= V_300 ;
V_14 -> V_301 = V_74 ;
F_139 ( & V_14 -> V_296 ) ;
goto V_150;
}
goto V_302;
}
if ( V_10 -> V_10 . V_88 < 4 ) {
goto V_302;
}
V_154 = V_14 -> V_301 ;
V_14 -> V_135 [ V_154 ] . V_187 = V_10 -> V_10 . V_89 [ 2 ] & 0x7f ;
V_14 -> V_135 [ V_154 ] . V_299 = V_10 -> V_10 . V_89 [ 3 ] & 0x1f ;
V_302:
V_14 -> V_301 ++ ;
if ( V_14 -> V_301 >= V_74 )
F_139 ( & V_14 -> V_296 ) ;
else
V_95 = F_142 ( V_14 , V_14 -> V_301 ) ;
if ( V_95 ) {
F_68 (KERN_WARNING PFX
L_80
L_81 , intf->curr_channel, rv) ;
V_14 -> V_301 = V_74 ;
F_139 ( & V_14 -> V_296 ) ;
}
}
V_150:
return;
}
static void F_144 ( T_1 V_14 )
{
if ( V_14 -> V_114 -> V_303 )
V_14 -> V_114 -> V_303 ( V_14 -> V_117 ) ;
F_145 ( V_14 ) ;
}
void F_146 ( T_2 V_75 )
{
F_144 ( V_75 -> V_14 ) ;
}
int F_147 ( struct V_123 * V_114 ,
void * V_117 ,
struct V_304 * V_247 ,
struct V_49 * V_47 ,
const char * V_269 ,
unsigned char V_64 )
{
int V_15 , V_305 ;
int V_95 ;
T_1 V_14 ;
T_1 V_306 ;
struct V_7 * V_12 ;
if ( ! V_110 ) {
V_95 = F_47 () ;
if ( V_95 )
return V_95 ;
if ( ! V_110 )
return - V_102 ;
}
V_14 = F_148 ( sizeof( * V_14 ) , V_43 ) ;
if ( ! V_14 )
return - V_48 ;
V_14 -> V_132 = V_132 ( V_247 ) ;
V_14 -> V_133 = V_133 ( V_247 ) ;
V_14 -> V_203 = F_148 ( sizeof( * V_14 -> V_203 ) , V_43 ) ;
if ( ! V_14 -> V_203 ) {
F_16 ( V_14 ) ;
return - V_48 ;
}
V_14 -> V_42 = - 1 ;
F_49 ( & V_14 -> V_33 ) ;
V_14 -> V_203 -> V_204 = * V_247 ;
V_14 -> V_47 = V_47 ;
for ( V_305 = 0 ; V_305 < V_74 ; V_305 ++ ) {
V_14 -> V_135 [ V_305 ] . V_134 = V_307 ;
V_14 -> V_135 [ V_305 ] . V_60 = 2 ;
}
if ( V_64 != 0 )
V_14 -> V_135 [ 0 ] . V_134 = V_64 ;
F_13 ( & V_14 -> V_119 ) ;
V_14 -> V_114 = V_114 ;
V_14 -> V_117 = V_117 ;
F_149 ( & V_14 -> V_104 ) ;
for ( V_305 = 0 ; V_305 < V_26 ; V_305 ++ ) {
V_14 -> V_27 [ V_305 ] . V_28 = 0 ;
V_14 -> V_27 [ V_305 ] . V_94 = 0 ;
}
V_14 -> V_96 = 0 ;
#ifdef F_98
F_150 ( & V_14 -> V_233 ) ;
#endif
F_149 ( & V_14 -> V_308 ) ;
F_13 ( & V_14 -> V_21 ) ;
F_151 ( & V_14 -> V_20 ,
V_309 ,
( unsigned long ) V_14 ) ;
F_152 ( & V_14 -> V_310 , 0 ) ;
F_149 ( & V_14 -> V_149 ) ;
F_152 ( & V_14 -> V_121 , 0 ) ;
V_14 -> V_311 = V_312 ;
F_13 ( & V_14 -> V_22 ) ;
V_14 -> V_152 = 0 ;
F_150 ( & V_14 -> V_23 ) ;
F_149 ( & V_14 -> V_138 ) ;
F_13 ( & V_14 -> V_24 ) ;
F_153 ( & V_14 -> V_296 ) ;
for ( V_15 = 0 ; V_15 < V_313 ; V_15 ++ )
F_152 ( & V_14 -> V_314 [ V_15 ] , 0 ) ;
V_14 -> V_232 = NULL ;
F_12 ( & V_40 ) ;
F_12 ( & V_41 ) ;
V_15 = 0 ;
V_12 = & V_315 ;
F_48 (tintf, &ipmi_interfaces, link) {
if ( V_306 -> V_42 != V_15 ) {
V_12 = & V_306 -> V_12 ;
break;
}
V_15 ++ ;
}
if ( V_15 == 0 )
F_50 ( & V_14 -> V_12 , & V_315 ) ;
else
F_154 ( & V_14 -> V_12 , V_12 ) ;
V_95 = V_114 -> V_316 ( V_117 , V_14 ) ;
if ( V_95 )
goto V_150;
F_140 ( V_14 ) ;
if ( ( V_14 -> V_132 > 1 )
|| ( ( V_14 -> V_132 == 1 )
&& ( V_14 -> V_133 >= 5 ) ) ) {
V_14 -> V_77 = F_143 ;
V_14 -> V_301 = 0 ;
V_95 = F_142 ( V_14 , 0 ) ;
if ( V_95 ) {
F_68 (KERN_WARNING PFX
L_80
L_82 , rv) ;
goto V_150;
}
F_141 ( V_14 -> V_296 ,
V_14 -> V_301 >= V_74 ) ;
V_14 -> V_77 = NULL ;
} else {
V_14 -> V_135 [ 0 ] . V_187 = V_188 ;
V_14 -> V_135 [ 0 ] . V_299 = V_300 ;
V_14 -> V_301 = V_74 ;
}
if ( V_95 == 0 )
V_95 = F_101 ( V_14 , V_15 ) ;
V_95 = F_130 ( V_14 , V_15 , V_269 ) ;
V_150:
if ( V_95 ) {
if ( V_14 -> V_232 )
F_103 ( V_14 ) ;
V_14 -> V_114 = NULL ;
F_56 ( & V_14 -> V_12 ) ;
F_15 ( & V_41 ) ;
F_15 ( & V_40 ) ;
V_25 () ;
F_26 ( & V_14 -> V_33 , F_17 ) ;
} else {
F_155 () ;
V_14 -> V_42 = V_15 ;
F_15 ( & V_41 ) ;
F_28 ( V_15 , V_14 -> V_47 ) ;
F_15 ( & V_40 ) ;
}
return V_95 ;
}
static void F_156 ( T_1 V_14 )
{
int V_15 ;
struct V_27 * V_106 ;
for ( V_15 = 0 ; V_15 < V_26 ; V_15 ++ ) {
V_106 = & ( V_14 -> V_27 [ V_15 ] ) ;
if ( ! V_106 -> V_28 )
continue;
F_36 ( V_106 -> V_29 , V_317 ) ;
}
}
int F_157 ( T_1 V_14 )
{
struct V_34 * V_51 ;
int V_42 = V_14 -> V_42 ;
F_125 ( V_14 ) ;
F_12 ( & V_40 ) ;
F_12 ( & V_41 ) ;
V_14 -> V_42 = - 1 ;
V_14 -> V_114 = NULL ;
F_56 ( & V_14 -> V_12 ) ;
F_15 ( & V_41 ) ;
V_25 () ;
F_156 ( V_14 ) ;
F_103 ( V_14 ) ;
F_21 (w, &smi_watchers, link)
V_51 -> V_318 ( V_42 ) ;
F_15 ( & V_40 ) ;
F_26 ( & V_14 -> V_33 , F_17 ) ;
return 0 ;
}
static int F_158 ( T_1 V_14 ,
struct V_13 * V_10 )
{
struct V_61 V_163 ;
struct V_9 * V_29 ;
if ( V_10 -> V_319 < 11 ) {
F_35 ( V_14 , V_210 ) ;
return 0 ;
}
if ( V_10 -> V_320 [ 2 ] != 0 ) {
return 0 ;
}
V_163 . V_3 = V_5 ;
V_163 . V_64 = V_10 -> V_320 [ 6 ] ;
V_163 . V_55 = V_10 -> V_320 [ 3 ] & 0x0f ;
V_163 . V_60 = V_10 -> V_320 [ 7 ] & 3 ;
if ( F_40 ( V_14 ,
V_10 -> V_320 [ 7 ] >> 2 ,
V_10 -> V_320 [ 3 ] & 0x0f ,
V_10 -> V_320 [ 8 ] ,
( V_10 -> V_320 [ 4 ] >> 2 ) & ( ~ 1 ) ,
(struct V_1 * ) & ( V_163 ) ,
& V_29 ) ) {
F_35 ( V_14 , V_211 ) ;
return 0 ;
}
memcpy ( V_29 -> V_86 ,
& ( V_10 -> V_320 [ 9 ] ) ,
V_10 -> V_319 - 9 ) ;
V_29 -> V_10 . V_87 = V_10 -> V_320 [ 4 ] >> 2 ;
V_29 -> V_10 . V_89 = V_29 -> V_86 ;
V_29 -> V_10 . V_88 = V_10 -> V_319 - 10 ;
V_29 -> V_84 = V_85 ;
F_35 ( V_14 , V_209 ) ;
F_34 ( V_29 ) ;
return 0 ;
}
static int F_159 ( T_1 V_14 ,
struct V_13 * V_10 )
{
struct V_16 * V_17 ;
int V_95 = 0 ;
unsigned char V_87 ;
unsigned char V_101 ;
unsigned char V_154 ;
T_2 V_75 = NULL ;
struct V_61 * V_163 ;
struct V_9 * V_29 ;
struct V_123 * V_114 ;
if ( V_10 -> V_319 < 10 ) {
F_35 ( V_14 , V_219 ) ;
return 0 ;
}
if ( V_10 -> V_320 [ 2 ] != 0 ) {
return 0 ;
}
V_87 = V_10 -> V_320 [ 4 ] >> 2 ;
V_101 = V_10 -> V_320 [ 8 ] ;
V_154 = V_10 -> V_320 [ 3 ] & 0xf ;
F_79 () ;
V_17 = F_69 ( V_14 , V_87 , V_101 , V_154 ) ;
if ( V_17 ) {
V_75 = V_17 -> V_75 ;
F_23 ( & V_75 -> V_33 ) ;
} else
V_75 = NULL ;
F_82 () ;
if ( V_75 == NULL ) {
F_35 ( V_14 , V_220 ) ;
V_10 -> V_89 [ 0 ] = ( V_167 << 2 ) ;
V_10 -> V_89 [ 1 ] = V_168 ;
V_10 -> V_89 [ 2 ] = V_10 -> V_320 [ 3 ] ;
V_10 -> V_89 [ 3 ] = V_10 -> V_320 [ 6 ] ;
V_10 -> V_89 [ 4 ] = ( ( V_87 + 1 ) << 2 ) | ( V_10 -> V_320 [ 7 ] & 0x3 ) ;
V_10 -> V_89 [ 5 ] = F_73 ( & ( V_10 -> V_89 [ 3 ] ) , 2 ) ;
V_10 -> V_89 [ 6 ] = V_14 -> V_135 [ V_10 -> V_320 [ 3 ] & 0xf ] . V_134 ;
V_10 -> V_89 [ 7 ] = ( V_10 -> V_320 [ 7 ] & 0xfc ) | ( V_10 -> V_320 [ 4 ] & 0x3 ) ;
V_10 -> V_89 [ 8 ] = V_10 -> V_320 [ 8 ] ;
V_10 -> V_89 [ 9 ] = V_321 ;
V_10 -> V_89 [ 10 ] = F_73 ( & ( V_10 -> V_89 [ 6 ] ) , 4 ) ;
V_10 -> V_169 = 11 ;
#ifdef F_81
{
int V_195 ;
F_68 ( L_83 ) ;
for ( V_195 = 0 ; V_195 < V_10 -> V_169 ; V_195 ++ )
F_68 ( L_3 , V_10 -> V_89 [ V_195 ] ) ;
F_68 ( L_4 ) ;
}
#endif
F_79 () ;
V_114 = V_14 -> V_114 ;
if ( V_114 ) {
V_114 -> V_196 ( V_14 -> V_117 , V_10 , 0 ) ;
V_95 = - 1 ;
}
F_82 () ;
} else {
F_35 ( V_14 , V_218 ) ;
V_29 = F_77 () ;
if ( ! V_29 ) {
V_95 = 1 ;
F_26 ( & V_75 -> V_33 , F_53 ) ;
} else {
V_163 = (struct V_61 * ) & V_29 -> V_2 ;
V_163 -> V_3 = V_5 ;
V_163 -> V_64 = V_10 -> V_320 [ 6 ] ;
V_163 -> V_60 = V_10 -> V_320 [ 7 ] & 3 ;
V_163 -> V_55 = V_10 -> V_320 [ 3 ] & 0xf ;
V_29 -> V_75 = V_75 ;
V_29 -> V_84 = V_322 ;
V_29 -> V_105 = V_10 -> V_320 [ 7 ] >> 2 ;
V_29 -> V_10 . V_87 = V_10 -> V_320 [ 4 ] >> 2 ;
V_29 -> V_10 . V_101 = V_10 -> V_320 [ 8 ] ;
V_29 -> V_10 . V_89 = V_29 -> V_86 ;
V_29 -> V_10 . V_88 = V_10 -> V_319 - 10 ;
memcpy ( V_29 -> V_86 ,
& ( V_10 -> V_320 [ 9 ] ) ,
V_10 -> V_319 - 10 ) ;
F_34 ( V_29 ) ;
}
}
return V_95 ;
}
static int F_160 ( T_1 V_14 ,
struct V_13 * V_10 )
{
struct V_65 V_170 ;
struct V_9 * V_29 ;
if ( V_10 -> V_319 < 13 ) {
F_35 ( V_14 , V_216 ) ;
return 0 ;
}
if ( V_10 -> V_320 [ 2 ] != 0 ) {
return 0 ;
}
V_170 . V_3 = V_4 ;
V_170 . V_70 = V_10 -> V_320 [ 4 ] ;
V_170 . V_68 = V_10 -> V_320 [ 8 ] ;
V_170 . V_69 = V_10 -> V_320 [ 5 ] ;
V_170 . V_55 = V_10 -> V_320 [ 3 ] & 0x0f ;
V_170 . V_323 = V_10 -> V_320 [ 3 ] >> 4 ;
V_170 . V_60 = V_10 -> V_320 [ 9 ] & 3 ;
if ( F_40 ( V_14 ,
V_10 -> V_320 [ 9 ] >> 2 ,
V_10 -> V_320 [ 3 ] & 0x0f ,
V_10 -> V_320 [ 10 ] ,
( V_10 -> V_320 [ 6 ] >> 2 ) & ( ~ 1 ) ,
(struct V_1 * ) & ( V_170 ) ,
& V_29 ) ) {
F_35 ( V_14 , V_217 ) ;
return 0 ;
}
memcpy ( V_29 -> V_86 ,
& ( V_10 -> V_320 [ 11 ] ) ,
V_10 -> V_319 - 11 ) ;
V_29 -> V_10 . V_87 = V_10 -> V_320 [ 6 ] >> 2 ;
V_29 -> V_10 . V_89 = V_29 -> V_86 ;
V_29 -> V_10 . V_88 = V_10 -> V_319 - 12 ;
V_29 -> V_84 = V_85 ;
F_35 ( V_14 , V_215 ) ;
F_34 ( V_29 ) ;
return 0 ;
}
static int F_161 ( T_1 V_14 ,
struct V_13 * V_10 )
{
struct V_16 * V_17 ;
int V_95 = 0 ;
unsigned char V_87 ;
unsigned char V_101 ;
unsigned char V_154 ;
T_2 V_75 = NULL ;
struct V_65 * V_170 ;
struct V_9 * V_29 ;
if ( V_10 -> V_319 < 12 ) {
F_35 ( V_14 , V_219 ) ;
return 0 ;
}
if ( V_10 -> V_320 [ 2 ] != 0 ) {
return 0 ;
}
V_87 = V_10 -> V_320 [ 6 ] >> 2 ;
V_101 = V_10 -> V_320 [ 10 ] ;
V_154 = V_10 -> V_320 [ 3 ] & 0xf ;
F_79 () ;
V_17 = F_69 ( V_14 , V_87 , V_101 , V_154 ) ;
if ( V_17 ) {
V_75 = V_17 -> V_75 ;
F_23 ( & V_75 -> V_33 ) ;
} else
V_75 = NULL ;
F_82 () ;
if ( V_75 == NULL ) {
F_35 ( V_14 , V_220 ) ;
V_95 = 0 ;
} else {
F_35 ( V_14 , V_218 ) ;
V_29 = F_77 () ;
if ( ! V_29 ) {
V_95 = 1 ;
F_26 ( & V_75 -> V_33 , F_53 ) ;
} else {
V_170 = (struct V_65 * ) & V_29 -> V_2 ;
V_170 -> V_3 = V_4 ;
V_170 -> V_70 = V_10 -> V_320 [ 4 ] ;
V_170 -> V_68 = V_10 -> V_320 [ 8 ] ;
V_170 -> V_69 = V_10 -> V_320 [ 5 ] ;
V_170 -> V_60 = V_10 -> V_320 [ 9 ] & 3 ;
V_170 -> V_55 = V_10 -> V_320 [ 3 ] & 0xf ;
V_170 -> V_323 = V_10 -> V_320 [ 3 ] >> 4 ;
V_29 -> V_75 = V_75 ;
V_29 -> V_84 = V_322 ;
V_29 -> V_105 = V_10 -> V_320 [ 9 ] >> 2 ;
V_29 -> V_10 . V_87 = V_10 -> V_320 [ 6 ] >> 2 ;
V_29 -> V_10 . V_101 = V_10 -> V_320 [ 10 ] ;
V_29 -> V_10 . V_89 = V_29 -> V_86 ;
V_29 -> V_10 . V_88 = V_10 -> V_319 - 12 ;
memcpy ( V_29 -> V_86 ,
& ( V_10 -> V_320 [ 11 ] ) ,
V_10 -> V_319 - 12 ) ;
F_34 ( V_29 ) ;
}
}
return V_95 ;
}
static int F_162 ( T_1 V_14 ,
struct V_13 * V_10 )
{
struct V_16 * V_17 ;
int V_95 = 0 ;
unsigned char V_87 ;
unsigned char V_101 ;
unsigned char V_154 ;
T_2 V_75 = NULL ;
struct V_57 * V_175 ;
struct V_9 * V_29 ;
if ( V_10 -> V_319 < 4 ) {
F_35 ( V_14 , V_219 ) ;
return 0 ;
}
if ( V_10 -> V_320 [ 2 ] != 0 ) {
return 0 ;
}
V_87 = V_10 -> V_320 [ 0 ] >> 2 ;
V_101 = V_10 -> V_320 [ 1 ] ;
V_154 = V_10 -> V_320 [ 3 ] & 0xf ;
F_79 () ;
V_17 = F_69 ( V_14 , V_87 , V_101 , V_154 ) ;
if ( V_17 ) {
V_75 = V_17 -> V_75 ;
F_23 ( & V_75 -> V_33 ) ;
} else
V_75 = NULL ;
F_82 () ;
if ( V_75 == NULL ) {
F_35 ( V_14 , V_220 ) ;
V_95 = 0 ;
} else {
F_35 ( V_14 , V_218 ) ;
V_29 = F_77 () ;
if ( ! V_29 ) {
V_95 = 1 ;
F_26 ( & V_75 -> V_33 , F_53 ) ;
} else {
V_175 = ( (struct V_57 * )
& ( V_29 -> V_2 ) ) ;
V_175 -> V_3 = V_56 ;
V_175 -> V_55 = V_73 ;
V_175 -> V_60 = V_10 -> V_320 [ 0 ] & 3 ;
V_29 -> V_75 = V_75 ;
V_29 -> V_76 = NULL ;
V_29 -> V_84 = V_324 ;
V_29 -> V_10 . V_87 = V_10 -> V_320 [ 0 ] >> 2 ;
V_29 -> V_10 . V_101 = V_10 -> V_320 [ 1 ] ;
V_29 -> V_10 . V_89 = V_29 -> V_86 ;
V_29 -> V_10 . V_88 = V_10 -> V_319 - 4 ;
memcpy ( V_29 -> V_86 ,
& ( V_10 -> V_320 [ 4 ] ) ,
V_10 -> V_319 - 4 ) ;
F_34 ( V_29 ) ;
}
}
return V_95 ;
}
static void F_163 ( struct V_9 * V_29 ,
struct V_13 * V_10 )
{
struct V_57 * V_175 ;
V_29 -> V_105 = 0 ;
V_175 = (struct V_57 * ) & ( V_29 -> V_2 ) ;
V_175 -> V_3 = V_56 ;
V_175 -> V_55 = V_73 ;
V_175 -> V_60 = V_10 -> V_320 [ 0 ] & 3 ;
V_29 -> V_84 = V_325 ;
V_29 -> V_10 . V_87 = V_10 -> V_320 [ 0 ] >> 2 ;
V_29 -> V_10 . V_101 = V_10 -> V_320 [ 1 ] ;
memcpy ( V_29 -> V_86 , & ( V_10 -> V_320 [ 3 ] ) , V_10 -> V_319 - 3 ) ;
V_29 -> V_10 . V_89 = V_29 -> V_86 ;
V_29 -> V_10 . V_88 = V_10 -> V_319 - 3 ;
}
static int F_164 ( T_1 V_14 ,
struct V_13 * V_10 )
{
struct V_9 * V_29 , * V_326 ;
struct V_7 V_148 ;
T_2 V_75 ;
int V_95 = 0 ;
int V_327 = 0 ;
unsigned long V_103 ;
if ( V_10 -> V_319 < 19 ) {
F_35 ( V_14 , V_221 ) ;
return 0 ;
}
if ( V_10 -> V_320 [ 2 ] != 0 ) {
return 0 ;
}
F_13 ( & V_148 ) ;
F_41 ( & V_14 -> V_149 , V_103 ) ;
F_35 ( V_14 , V_222 ) ;
F_79 () ;
F_48 (user, &intf->users, link) {
if ( ! V_75 -> V_113 )
continue;
V_29 = F_77 () ;
if ( ! V_29 ) {
F_82 () ;
F_5 (recv_msg, recv_msg2, &msgs,
link) {
F_6 ( & V_29 -> V_12 ) ;
F_7 ( V_29 ) ;
}
V_95 = 1 ;
goto V_150;
}
V_327 ++ ;
F_163 ( V_29 , V_10 ) ;
V_29 -> V_75 = V_75 ;
F_23 ( & V_75 -> V_33 ) ;
F_24 ( & ( V_29 -> V_12 ) , & V_148 ) ;
}
F_82 () ;
if ( V_327 ) {
F_5 (recv_msg, recv_msg2, &msgs, link) {
F_6 ( & V_29 -> V_12 ) ;
F_34 ( V_29 ) ;
}
} else if ( V_14 -> V_152 < V_328 ) {
V_29 = F_77 () ;
if ( ! V_29 ) {
V_95 = 1 ;
goto V_150;
}
F_163 ( V_29 , V_10 ) ;
F_24 ( & ( V_29 -> V_12 ) , & ( V_14 -> V_22 ) ) ;
V_14 -> V_152 ++ ;
} else if ( ! V_14 -> V_153 ) {
F_68 (KERN_WARNING PFX L_84
L_85 ) ;
V_14 -> V_153 = 1 ;
}
V_150:
F_42 ( & ( V_14 -> V_149 ) , V_103 ) ;
return V_95 ;
}
static int F_165 ( T_1 V_14 ,
struct V_13 * V_10 )
{
struct V_9 * V_29 ;
struct V_126 * V_75 ;
V_29 = (struct V_9 * ) V_10 -> V_185 ;
if ( V_29 == NULL ) {
F_68 ( V_329
L_86
L_87
L_88
L_89 ) ;
return 0 ;
}
V_75 = V_29 -> V_75 ;
if ( V_75 && ! V_75 -> V_118 ) {
F_35 ( V_14 , V_79 ) ;
F_7 ( V_29 ) ;
} else {
struct V_57 * V_175 ;
F_35 ( V_14 , V_78 ) ;
V_29 -> V_84 = V_85 ;
V_29 -> V_105 = V_10 -> V_105 ;
V_175 = ( (struct V_57 * )
& ( V_29 -> V_2 ) ) ;
V_175 -> V_3 = V_56 ;
V_175 -> V_55 = V_73 ;
V_175 -> V_60 = V_10 -> V_320 [ 0 ] & 3 ;
V_29 -> V_10 . V_87 = V_10 -> V_320 [ 0 ] >> 2 ;
V_29 -> V_10 . V_101 = V_10 -> V_320 [ 1 ] ;
memcpy ( V_29 -> V_86 ,
& ( V_10 -> V_320 [ 2 ] ) ,
V_10 -> V_319 - 2 ) ;
V_29 -> V_10 . V_89 = V_29 -> V_86 ;
V_29 -> V_10 . V_88 = V_10 -> V_319 - 2 ;
F_34 ( V_29 ) ;
}
return 0 ;
}
static int F_166 ( T_1 V_14 ,
struct V_13 * V_10 )
{
int V_330 ;
int V_154 ;
#ifdef F_81
int V_195 ;
F_68 ( L_90 ) ;
for ( V_195 = 0 ; V_195 < V_10 -> V_319 ; V_195 ++ )
F_68 ( L_3 , V_10 -> V_320 [ V_195 ] ) ;
F_68 ( L_4 ) ;
#endif
if ( V_10 -> V_319 < 2 ) {
F_68 (KERN_WARNING PFX L_91
L_92 ,
(msg->data[0] >> 2) | 1 , msg->data[1], msg->rsp_size) ;
V_10 -> V_320 [ 0 ] = V_10 -> V_89 [ 0 ] | ( 1 << 2 ) ;
V_10 -> V_320 [ 1 ] = V_10 -> V_89 [ 1 ] ;
V_10 -> V_320 [ 2 ] = V_317 ;
V_10 -> V_319 = 3 ;
} else if ( ( ( V_10 -> V_320 [ 0 ] >> 2 ) != ( ( V_10 -> V_89 [ 0 ] >> 2 ) | 1 ) )
|| ( V_10 -> V_320 [ 1 ] != V_10 -> V_89 [ 1 ] ) ) {
F_68 (KERN_WARNING PFX L_93
L_94 ,
(msg->data[0] >> 2) | 1 , msg->data[1],
msg->rsp[0] >> 2 , msg->rsp[1]) ;
V_10 -> V_320 [ 0 ] = V_10 -> V_89 [ 0 ] | ( 1 << 2 ) ;
V_10 -> V_320 [ 1 ] = V_10 -> V_89 [ 1 ] ;
V_10 -> V_320 [ 2 ] = V_317 ;
V_10 -> V_319 = 3 ;
}
if ( ( V_10 -> V_320 [ 0 ] == ( ( V_167 | 1 ) << 2 ) )
&& ( V_10 -> V_320 [ 1 ] == V_168 )
&& ( V_10 -> V_185 != NULL ) ) {
struct V_9 * V_29 = V_10 -> V_185 ;
V_330 = 0 ;
if ( V_10 -> V_319 < 2 )
goto V_150;
V_154 = V_10 -> V_89 [ 2 ] & 0x0f ;
if ( V_154 >= V_74 )
goto V_150;
if ( ! V_29 )
goto V_150;
if ( ! V_29 -> V_75 || ! V_29 -> V_75 -> V_118 )
goto V_150;
V_29 -> V_84 = V_331 ;
V_29 -> V_10 . V_89 = V_29 -> V_86 ;
V_29 -> V_10 . V_88 = 1 ;
V_29 -> V_86 [ 0 ] = V_10 -> V_320 [ 2 ] ;
F_34 ( V_29 ) ;
} else if ( ( V_10 -> V_320 [ 0 ] == ( ( V_167 | 1 ) << 2 ) )
&& ( V_10 -> V_320 [ 1 ] == V_177 ) ) {
V_154 = V_10 -> V_320 [ 3 ] & 0xf ;
if ( V_154 >= V_74 ) {
V_330 = 0 ;
goto V_150;
}
if ( V_14 -> V_301 < V_74 ) {
V_330 = 0 ;
goto V_150;
}
switch ( V_14 -> V_135 [ V_154 ] . V_187 ) {
case V_188 :
if ( V_10 -> V_320 [ 4 ] & 0x04 ) {
V_330 = F_158 ( V_14 , V_10 ) ;
} else {
V_330 = F_159 ( V_14 , V_10 ) ;
}
break;
case V_191 :
case V_192 :
if ( V_10 -> V_320 [ 6 ] & 0x04 ) {
V_330 = F_160 ( V_14 , V_10 ) ;
} else {
V_330 = F_161 ( V_14 , V_10 ) ;
}
break;
default:
if ( ( V_14 -> V_135 [ V_154 ] . V_187
>= V_332 )
&& ( V_14 -> V_135 [ V_154 ] . V_187
<= V_333 ) ) {
V_330 = F_162 ( V_14 , V_10 ) ;
} else {
V_330 = 0 ;
}
}
} else if ( ( V_10 -> V_320 [ 0 ] == ( ( V_167 | 1 ) << 2 ) )
&& ( V_10 -> V_320 [ 1 ] == V_178 ) ) {
V_330 = F_164 ( V_14 , V_10 ) ;
} else {
V_330 = F_165 ( V_14 , V_10 ) ;
}
V_150:
return V_330 ;
}
static void F_145 ( T_1 V_14 )
{
struct V_13 * V_161 ;
unsigned long V_103 = 0 ;
int V_95 ;
int V_334 = V_14 -> V_334 ;
if ( ! V_334 )
F_41 ( & V_14 -> V_308 , V_103 ) ;
while ( ! F_66 ( & V_14 -> V_21 ) ) {
V_161 = F_167 ( V_14 -> V_21 . V_128 ,
struct V_13 , V_12 ) ;
F_6 ( & V_161 -> V_12 ) ;
if ( ! V_334 )
F_42 ( & V_14 -> V_308 , V_103 ) ;
V_95 = F_166 ( V_14 , V_161 ) ;
if ( ! V_334 )
F_41 ( & V_14 -> V_308 , V_103 ) ;
if ( V_95 == 0 ) {
F_9 ( V_161 ) ;
} else if ( V_95 < 0 ) {
} else {
F_25 ( & V_161 -> V_12 , & V_14 -> V_21 ) ;
break;
}
}
if ( ! V_334 )
F_42 ( & V_14 -> V_308 , V_103 ) ;
if ( F_168 ( & V_14 -> V_310 , - 1 , 0 ) ) {
T_2 V_75 ;
F_79 () ;
F_48 (user, &intf->users, link) {
if ( V_75 -> V_80 -> V_120 )
V_75 -> V_80 -> V_120 (
V_75 -> V_82 ) ;
}
F_82 () ;
}
}
static void V_309 ( unsigned long V_147 )
{
F_145 ( ( T_1 ) V_147 ) ;
}
void F_169 ( T_1 V_14 ,
struct V_13 * V_10 )
{
unsigned long V_103 = 0 ;
int V_334 ;
if ( ( V_10 -> V_169 >= 2 )
&& ( V_10 -> V_89 [ 0 ] == ( V_167 << 2 ) )
&& ( V_10 -> V_89 [ 1 ] == V_168 )
&& ( V_10 -> V_185 == NULL ) ) {
if ( ( V_10 -> V_319 >= 3 ) && ( V_10 -> V_320 [ 2 ] != 0 )
&& ( V_10 -> V_320 [ 2 ] != V_335 )
&& ( V_10 -> V_320 [ 2 ] != V_336 )
&& ( V_10 -> V_320 [ 2 ] != V_337 )
&& ( V_10 -> V_320 [ 2 ] != V_338 ) ) {
int V_154 = V_10 -> V_320 [ 3 ] & 0xf ;
if ( V_154 >= V_74 )
;
else if ( ( V_14 -> V_135 [ V_154 ] . V_187
== V_191 )
|| ( V_14 -> V_135 [ V_154 ] . V_187
== V_192 ) )
F_35 ( V_14 , V_212 ) ;
else
F_35 ( V_14 , V_205 ) ;
F_45 ( V_14 , V_10 -> V_105 , V_10 -> V_320 [ 2 ] ) ;
} else
F_43 ( V_14 , V_10 -> V_105 ) ;
F_9 ( V_10 ) ;
goto V_150;
}
V_334 = V_14 -> V_334 ;
if ( ! V_334 )
F_41 ( & V_14 -> V_308 , V_103 ) ;
F_24 ( & V_10 -> V_12 , & V_14 -> V_21 ) ;
if ( ! V_334 )
F_42 ( & V_14 -> V_308 , V_103 ) ;
F_170 ( & V_14 -> V_20 ) ;
V_150:
return;
}
void F_171 ( T_1 V_14 )
{
F_152 ( & V_14 -> V_310 , 1 ) ;
F_170 ( & V_14 -> V_20 ) ;
}
static struct V_13 *
F_172 ( T_1 V_14 , struct V_9 * V_29 ,
unsigned char V_93 , long V_94 )
{
struct V_13 * V_161 = F_78 () ;
if ( ! V_161 )
return NULL ;
memcpy ( V_161 -> V_89 , V_29 -> V_10 . V_89 , V_29 -> V_10 . V_88 ) ;
V_161 -> V_169 = V_29 -> V_10 . V_88 ;
V_161 -> V_105 = F_80 ( V_93 , V_94 ) ;
#ifdef F_81
{
int V_195 ;
F_68 ( L_95 ) ;
for ( V_195 = 0 ; V_195 < V_161 -> V_169 ; V_195 ++ )
F_68 ( L_3 , V_161 -> V_89 [ V_195 ] ) ;
F_68 ( L_4 ) ;
}
#endif
return V_161 ;
}
static void F_173 ( T_1 V_14 , struct V_27 * V_106 ,
struct V_7 * V_339 , long V_340 ,
int V_341 , unsigned long * V_103 ,
unsigned int * V_21 )
{
struct V_9 * V_10 ;
struct V_123 * V_114 ;
if ( V_14 -> V_42 == - 1 )
return;
if ( ! V_106 -> V_28 )
return;
V_106 -> V_90 -= V_340 ;
if ( V_106 -> V_90 > 0 ) {
( * V_21 ) ++ ;
return;
}
if ( V_106 -> V_99 == 0 ) {
V_106 -> V_28 = 0 ;
V_10 = V_106 -> V_29 ;
F_24 ( & V_10 -> V_12 , V_339 ) ;
if ( V_106 -> V_92 )
F_35 ( V_14 , V_208 ) ;
else if ( F_1 ( & V_106 -> V_29 -> V_2 ) )
F_35 ( V_14 , V_214 ) ;
else
F_35 ( V_14 , V_207 ) ;
} else {
struct V_13 * V_161 ;
( * V_21 ) ++ ;
V_106 -> V_90 = V_97 ;
V_106 -> V_99 -- ;
V_161 = F_172 ( V_14 , V_106 -> V_29 , V_341 ,
V_106 -> V_94 ) ;
if ( ! V_161 ) {
if ( F_1 ( & V_106 -> V_29 -> V_2 ) )
F_35 ( V_14 ,
V_223 ) ;
else
F_35 ( V_14 ,
V_224 ) ;
return;
}
F_42 ( & V_14 -> V_104 , * V_103 ) ;
V_114 = V_14 -> V_114 ;
if ( V_114 ) {
if ( F_1 ( & V_106 -> V_29 -> V_2 ) )
F_35 ( V_14 ,
V_213 ) ;
else
F_35 ( V_14 ,
V_206 ) ;
V_14 -> V_114 -> V_196 ( V_14 -> V_117 ,
V_161 , 0 ) ;
} else
F_9 ( V_161 ) ;
F_41 ( & V_14 -> V_104 , * V_103 ) ;
}
}
static unsigned int F_174 ( T_1 V_14 , long V_340 )
{
struct V_7 V_339 ;
struct V_9 * V_10 , * V_11 ;
unsigned long V_103 ;
int V_15 ;
unsigned int V_21 = 0 ;
F_13 ( & V_339 ) ;
F_41 ( & V_14 -> V_104 , V_103 ) ;
for ( V_15 = 0 ; V_15 < V_26 ; V_15 ++ )
F_173 ( V_14 , & ( V_14 -> V_27 [ V_15 ] ) ,
& V_339 , V_340 , V_15 ,
& V_103 , & V_21 ) ;
F_42 ( & V_14 -> V_104 , V_103 ) ;
F_5 (msg, msg2, &timeouts, link)
F_36 ( V_10 , V_342 ) ;
if ( V_14 -> V_143 > 0 ) {
F_41 ( & V_14 -> V_138 , V_103 ) ;
if ( V_14 -> V_143 > 0 ) {
V_14 -> V_143
-= V_340 ;
if ( ! V_14 -> V_139
&& ( V_14 -> V_143 <= 0 ) ) {
V_14 -> V_141 = false ;
F_63 ( V_14 ) ;
}
}
F_42 ( & V_14 -> V_138 ,
V_103 ) ;
}
F_170 ( & V_14 -> V_20 ) ;
return V_21 ;
}
static void F_175 ( T_1 V_14 )
{
struct V_123 * V_114 ;
if ( V_14 -> V_141 )
return;
V_114 = V_14 -> V_114 ;
if ( V_114 )
V_114 -> V_343 ( V_14 -> V_117 ) ;
}
static void F_176 ( unsigned long V_89 )
{
T_1 V_14 ;
int V_344 = 0 ;
if ( F_177 ( & V_345 ) )
return;
F_79 () ;
F_48 (intf, &ipmi_interfaces, link) {
int V_346 = 0 ;
if ( F_177 ( & V_14 -> V_121 ) ) {
V_14 -> V_311 -- ;
if ( V_14 -> V_311 == 0 ) {
F_175 ( V_14 ) ;
V_14 -> V_311 = V_312 ;
}
V_346 ++ ;
}
V_346 += F_174 ( V_14 , V_347 ) ;
V_346 = ! ! V_346 ;
if ( V_346 != V_14 -> V_348 &&
V_14 -> V_114 -> V_349 )
V_14 -> V_114 -> V_349 ( V_14 -> V_117 , V_346 ) ;
V_14 -> V_348 = V_346 ;
V_344 += V_346 ;
}
F_82 () ;
if ( V_344 )
F_178 ( & V_350 , V_351 + V_352 ) ;
}
static void F_39 ( T_1 V_14 )
{
if ( ! F_179 ( & V_350 ) )
F_178 ( & V_350 , V_351 + V_352 ) ;
}
static void F_180 ( struct V_13 * V_10 )
{
F_55 ( & V_353 ) ;
F_16 ( V_10 ) ;
}
struct V_13 * F_78 ( void )
{
struct V_13 * V_95 ;
V_95 = F_22 ( sizeof( struct V_13 ) , V_354 ) ;
if ( V_95 ) {
V_95 -> V_355 = F_180 ;
V_95 -> V_185 = NULL ;
F_181 ( & V_353 ) ;
}
return V_95 ;
}
static void F_182 ( struct V_9 * V_10 )
{
F_55 ( & V_356 ) ;
F_16 ( V_10 ) ;
}
static struct V_9 * F_77 ( void )
{
struct V_9 * V_95 ;
V_95 = F_22 ( sizeof( struct V_9 ) , V_354 ) ;
if ( V_95 ) {
V_95 -> V_75 = NULL ;
V_95 -> V_355 = F_182 ;
F_181 ( & V_356 ) ;
}
return V_95 ;
}
void F_7 ( struct V_9 * V_10 )
{
if ( V_10 -> V_75 )
F_26 ( & V_10 -> V_75 -> V_33 , F_53 ) ;
V_10 -> V_355 ( V_10 ) ;
}
static void F_183 ( struct V_13 * V_10 )
{
F_55 ( & V_357 ) ;
}
static void F_184 ( struct V_9 * V_10 )
{
F_55 ( & V_357 ) ;
}
static void F_185 ( T_1 V_14 ,
struct V_1 * V_2 ,
struct V_162 * V_10 )
{
struct V_13 V_161 ;
struct V_9 V_29 ;
int V_95 ;
V_161 . V_355 = F_183 ;
V_29 . V_355 = F_184 ;
F_186 ( 2 , & V_357 ) ;
V_95 = F_76 ( NULL ,
V_14 ,
V_2 ,
0 ,
V_10 ,
V_14 ,
& V_161 ,
& V_29 ,
0 ,
V_14 -> V_135 [ 0 ] . V_134 ,
V_14 -> V_135 [ 0 ] . V_60 ,
0 , 1 ) ;
if ( V_95 )
F_187 ( 2 , & V_357 ) ;
while ( F_177 ( & V_357 ) != 0 )
F_144 ( V_14 ) ;
}
static void F_188 ( T_1 V_14 , struct V_9 * V_10 )
{
if ( ( V_10 -> V_2 . V_3 == V_56 )
&& ( V_10 -> V_10 . V_87 == V_358 )
&& ( V_10 -> V_10 . V_101 == V_359 )
&& ( V_10 -> V_10 . V_89 [ 0 ] == V_360 ) ) {
V_14 -> V_361 = V_10 -> V_10 . V_89 [ 1 ] ;
V_14 -> V_362 = V_10 -> V_10 . V_89 [ 2 ] & 0x3 ;
}
}
static void F_189 ( T_1 V_14 , struct V_9 * V_10 )
{
if ( ( V_10 -> V_2 . V_3 == V_56 )
&& ( V_10 -> V_10 . V_87 == V_295 )
&& ( V_10 -> V_10 . V_101 == V_363 )
&& ( V_10 -> V_10 . V_89 [ 0 ] == V_360 ) ) {
V_14 -> V_364 = ( V_10 -> V_10 . V_89 [ 6 ] >> 2 ) & 1 ;
V_14 -> V_365 = ( V_10 -> V_10 . V_89 [ 6 ] >> 5 ) & 1 ;
}
}
static void F_190 ( char * V_366 )
{
struct V_162 V_10 ;
T_1 V_14 ;
unsigned char V_89 [ 16 ] ;
struct V_57 * V_293 ;
struct V_1 V_2 ;
V_293 = (struct V_57 * ) & V_2 ;
V_293 -> V_3 = V_56 ;
V_293 -> V_55 = V_73 ;
V_293 -> V_60 = 0 ;
V_10 . V_87 = 0x04 ;
V_10 . V_101 = 2 ;
V_10 . V_89 = V_89 ;
V_10 . V_88 = 8 ;
V_89 [ 0 ] = 0x41 ;
V_89 [ 1 ] = 0x03 ;
V_89 [ 2 ] = 0x20 ;
V_89 [ 4 ] = 0x6f ;
V_89 [ 5 ] = 0xa1 ;
if ( V_366 ) {
V_89 [ 3 ] = V_366 [ 0 ] ;
V_89 [ 6 ] = V_366 [ 1 ] ;
V_89 [ 7 ] = V_366 [ 2 ] ;
}
F_48 (intf, &ipmi_interfaces, link) {
if ( ! V_14 -> V_114 )
continue;
V_14 -> V_334 = 1 ;
V_14 -> V_114 -> V_367 ( V_14 -> V_117 , 1 ) ;
F_185 ( V_14 , & V_2 , & V_10 ) ;
}
#ifdef F_191
if ( ! V_366 )
return;
F_48 (intf, &ipmi_interfaces, link) {
char * V_368 = V_366 ;
struct V_61 * V_369 ;
int V_305 ;
if ( V_14 -> V_42 == - 1 )
continue;
F_192 () ;
V_14 -> V_364 = 0 ;
V_14 -> V_365 = 0 ;
V_14 -> V_361 = 0 ;
V_10 . V_87 = V_167 ;
V_10 . V_101 = V_363 ;
V_10 . V_89 = NULL ;
V_10 . V_88 = 0 ;
V_14 -> V_77 = F_189 ;
F_185 ( V_14 , & V_2 , & V_10 ) ;
if ( V_14 -> V_365 ) {
V_10 . V_87 = V_370 ;
V_10 . V_101 = V_359 ;
V_10 . V_89 = NULL ;
V_10 . V_88 = 0 ;
V_14 -> V_77 = F_188 ;
F_185 ( V_14 , & V_2 , & V_10 ) ;
}
V_14 -> V_77 = NULL ;
if ( ( ( V_14 -> V_361 & 1 ) == 0 )
&& ( V_14 -> V_361 != 0 )
&& ( V_14 -> V_361 != V_14 -> V_135 [ 0 ] . V_134 ) ) {
V_369 = (struct V_61 * ) & V_2 ;
V_369 -> V_3 = V_5 ;
V_369 -> V_55 = 0 ;
V_369 -> V_60 = V_14 -> V_362 ;
V_369 -> V_64 = V_14 -> V_361 ;
} else if ( V_14 -> V_364 ) {
V_293 = (struct V_57 * ) & V_2 ;
V_293 -> V_3 = V_56 ;
V_293 -> V_55 = V_73 ;
V_293 -> V_60 = 0 ;
} else
continue;
V_10 . V_87 = V_371 ;
V_10 . V_101 = V_372 ;
V_10 . V_89 = V_89 ;
V_10 . V_88 = 16 ;
V_305 = 0 ;
while ( * V_368 ) {
int V_159 = strlen ( V_368 ) ;
if ( V_159 > 11 )
V_159 = 11 ;
V_89 [ 0 ] = 0 ;
V_89 [ 1 ] = 0 ;
V_89 [ 2 ] = 0xf0 ;
V_89 [ 3 ] = V_14 -> V_135 [ 0 ] . V_134 ;
V_89 [ 4 ] = V_305 ++ ;
strncpy ( V_89 + 5 , V_368 , 11 ) ;
V_368 += V_159 ;
F_185 ( V_14 , & V_2 , & V_10 ) ;
}
}
#endif
}
static int F_193 ( struct V_373 * V_374 ,
unsigned long V_375 ,
void * V_376 )
{
T_1 V_14 ;
if ( V_377 )
return V_378 ;
V_377 = 1 ;
F_48 (intf, &ipmi_interfaces, link) {
if ( ! V_14 -> V_114 )
continue;
V_14 -> V_334 = 1 ;
V_14 -> V_114 -> V_367 ( V_14 -> V_117 , 1 ) ;
}
#ifdef F_194
F_190 ( V_376 ) ;
#endif
return V_378 ;
}
static int F_47 ( void )
{
int V_95 ;
if ( V_110 )
return 0 ;
V_95 = F_195 ( & V_287 . V_288 ) ;
if ( V_95 ) {
F_68 (KERN_ERR PFX L_96 ) ;
return V_95 ;
}
F_68 ( V_289 L_97
V_379 L_4 ) ;
#ifdef F_98
V_237 = F_102 ( L_98 , NULL ) ;
if ( ! V_237 ) {
F_68 (KERN_ERR PFX L_99 ) ;
return - V_48 ;
}
#endif
F_196 ( & V_350 , F_176 , 0 ) ;
F_178 ( & V_350 , V_351 + V_352 ) ;
F_197 ( & V_380 , & V_381 ) ;
V_110 = 1 ;
return 0 ;
}
static int T_4 F_198 ( void )
{
F_47 () ;
return 0 ;
}
static void T_5 F_199 ( void )
{
int V_382 ;
if ( ! V_110 )
return;
F_200 ( & V_380 , & V_381 ) ;
F_181 ( & V_345 ) ;
F_201 ( & V_350 ) ;
#ifdef F_98
F_202 ( V_237 ) ;
#endif
F_203 ( & V_287 . V_288 ) ;
V_110 = 0 ;
V_382 = F_177 ( & V_353 ) ;
if ( V_382 != 0 )
F_68 (KERN_WARNING PFX L_100 ,
count) ;
V_382 = F_177 ( & V_356 ) ;
if ( V_382 != 0 )
F_68 (KERN_WARNING PFX L_101 ,
count) ;
}
