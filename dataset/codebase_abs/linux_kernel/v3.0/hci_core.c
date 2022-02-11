int F_1 ( struct V_1 * V_2 )
{
return F_2 ( & V_3 , V_2 ) ;
}
int F_3 ( struct V_1 * V_2 )
{
return F_4 ( & V_3 , V_2 ) ;
}
static void F_5 ( struct V_4 * V_5 , int V_6 )
{
F_6 ( & V_3 , V_6 , V_5 ) ;
}
void F_7 ( struct V_4 * V_5 , T_1 V_7 , int V_8 )
{
F_8 ( L_1 , V_5 -> V_9 , V_7 , V_8 ) ;
if ( F_9 ( V_10 , & V_5 -> V_11 ) && V_5 -> V_12 != V_7 )
return;
if ( V_5 -> V_13 == V_14 ) {
V_5 -> V_15 = V_8 ;
V_5 -> V_13 = V_16 ;
F_10 ( & V_5 -> V_17 ) ;
}
}
static void F_11 ( struct V_4 * V_5 , int V_18 )
{
F_8 ( L_2 , V_5 -> V_9 , V_18 ) ;
if ( V_5 -> V_13 == V_14 ) {
V_5 -> V_15 = V_18 ;
V_5 -> V_13 = V_19 ;
F_10 ( & V_5 -> V_17 ) ;
}
}
static int F_12 ( struct V_4 * V_5 , void (* F_13)( struct V_4 * V_5 , unsigned long V_20 ) ,
unsigned long V_20 , T_2 V_21 )
{
F_14 ( V_22 , V_23 ) ;
int V_18 = 0 ;
F_8 ( L_3 , V_5 -> V_9 ) ;
V_5 -> V_13 = V_14 ;
F_15 ( & V_5 -> V_17 , & V_22 ) ;
F_16 ( V_24 ) ;
F_13 ( V_5 , V_20 ) ;
F_17 ( V_21 ) ;
F_18 ( & V_5 -> V_17 , & V_22 ) ;
if ( F_19 ( V_23 ) )
return - V_25 ;
switch ( V_5 -> V_13 ) {
case V_16 :
V_18 = - F_20 ( V_5 -> V_15 ) ;
break;
case V_19 :
V_18 = - V_5 -> V_15 ;
break;
default:
V_18 = - V_26 ;
break;
}
V_5 -> V_13 = V_5 -> V_15 = 0 ;
F_8 ( L_4 , V_5 -> V_9 , V_18 ) ;
return V_18 ;
}
static inline int F_21 ( struct V_4 * V_5 , void (* F_13)( struct V_4 * V_5 , unsigned long V_20 ) ,
unsigned long V_20 , T_2 V_21 )
{
int V_27 ;
if ( ! F_9 ( V_28 , & V_5 -> V_11 ) )
return - V_29 ;
F_22 ( V_5 ) ;
V_27 = F_12 ( V_5 , F_13 , V_20 , V_21 ) ;
F_23 ( V_5 ) ;
return V_27 ;
}
static void F_24 ( struct V_4 * V_5 , unsigned long V_20 )
{
F_8 ( L_5 , V_5 -> V_9 , V_20 ) ;
F_25 ( V_30 , & V_5 -> V_11 ) ;
F_26 ( V_5 , V_31 , 0 , NULL ) ;
}
static void F_27 ( struct V_4 * V_5 , unsigned long V_20 )
{
struct V_32 V_33 ;
struct V_34 * V_35 ;
T_3 V_36 ;
T_4 V_37 ;
F_8 ( L_5 , V_5 -> V_9 , V_20 ) ;
while ( ( V_35 = F_28 ( & V_5 -> V_38 ) ) ) {
F_29 ( V_35 ) -> V_39 = V_40 ;
V_35 -> V_41 = ( void * ) V_5 ;
F_30 ( & V_5 -> V_42 , V_35 ) ;
F_31 ( & V_5 -> V_43 ) ;
}
F_32 ( & V_5 -> V_38 ) ;
if ( ! F_9 ( V_44 , & V_5 -> V_45 ) ) {
F_25 ( V_30 , & V_5 -> V_11 ) ;
F_26 ( V_5 , V_31 , 0 , NULL ) ;
}
F_26 ( V_5 , V_46 , 0 , NULL ) ;
F_26 ( V_5 , V_47 , 0 , NULL ) ;
F_26 ( V_5 , V_48 , 0 , NULL ) ;
#if 0
{
struct hci_cp_host_buffer_size cp;
cp.acl_mtu = cpu_to_le16(HCI_MAX_ACL_SIZE);
cp.sco_mtu = HCI_MAX_SCO_SIZE;
cp.acl_max_pkt = cpu_to_le16(0xffff);
cp.sco_max_pkt = cpu_to_le16(0xffff);
hci_send_cmd(hdev, HCI_OP_HOST_BUFFER_SIZE, sizeof(cp), &cp);
}
#endif
F_26 ( V_5 , V_49 , 0 , NULL ) ;
F_26 ( V_5 , V_50 , 0 , NULL ) ;
F_26 ( V_5 , V_51 , 0 , NULL ) ;
F_26 ( V_5 , V_52 , 0 , NULL ) ;
V_37 = V_53 ;
F_26 ( V_5 , V_54 , 1 , & V_37 ) ;
V_36 = F_33 ( 0x7d00 ) ;
F_26 ( V_5 , V_55 , 2 , & V_36 ) ;
F_34 ( & V_33 . V_56 , V_57 ) ;
V_33 . V_58 = 1 ;
F_26 ( V_5 , V_59 , sizeof( V_33 ) , & V_33 ) ;
}
static void F_35 ( struct V_4 * V_5 , unsigned long V_20 )
{
F_8 ( L_6 , V_5 -> V_9 ) ;
F_26 ( V_5 , V_60 , 0 , NULL ) ;
}
static void F_36 ( struct V_4 * V_5 , unsigned long V_20 )
{
T_4 V_61 = V_20 ;
F_8 ( L_7 , V_5 -> V_9 , V_61 ) ;
F_26 ( V_5 , V_62 , 1 , & V_61 ) ;
}
static void F_37 ( struct V_4 * V_5 , unsigned long V_20 )
{
T_4 V_63 = V_20 ;
F_8 ( L_7 , V_5 -> V_9 , V_63 ) ;
F_26 ( V_5 , V_64 , 1 , & V_63 ) ;
}
static void F_38 ( struct V_4 * V_5 , unsigned long V_20 )
{
T_4 V_65 = V_20 ;
F_8 ( L_7 , V_5 -> V_9 , V_65 ) ;
F_26 ( V_5 , V_66 , 1 , & V_65 ) ;
}
static void F_39 ( struct V_4 * V_5 , unsigned long V_20 )
{
T_3 V_67 = F_33 ( V_20 ) ;
F_8 ( L_7 , V_5 -> V_9 , V_67 ) ;
F_26 ( V_5 , V_68 , 2 , & V_67 ) ;
}
struct V_4 * F_40 ( int V_69 )
{
struct V_4 * V_5 = NULL ;
struct V_70 * V_71 ;
F_8 ( L_8 , V_69 ) ;
if ( V_69 < 0 )
return NULL ;
F_41 ( & V_72 ) ;
F_42 (p, &hci_dev_list) {
struct V_4 * V_73 = F_43 ( V_71 , struct V_4 , V_74 ) ;
if ( V_73 -> V_75 == V_69 ) {
V_5 = F_44 ( V_73 ) ;
break;
}
}
F_45 ( & V_72 ) ;
return V_5 ;
}
static void F_46 ( struct V_4 * V_5 )
{
struct V_76 * V_77 = & V_5 -> V_78 ;
struct V_79 * V_80 = V_77 -> V_74 , * V_81 ;
F_8 ( L_9 , V_77 ) ;
V_77 -> V_74 = NULL ;
while ( ( V_81 = V_80 ) ) {
V_80 = V_81 -> V_80 ;
F_47 ( V_81 ) ;
}
}
struct V_79 * F_48 ( struct V_4 * V_5 , T_5 * V_56 )
{
struct V_76 * V_77 = & V_5 -> V_78 ;
struct V_79 * V_81 ;
F_8 ( L_10 , V_77 , F_49 ( V_56 ) ) ;
for ( V_81 = V_77 -> V_74 ; V_81 ; V_81 = V_81 -> V_80 )
if ( ! F_50 ( & V_81 -> V_82 . V_56 , V_56 ) )
break;
return V_81 ;
}
void F_51 ( struct V_4 * V_5 , struct V_83 * V_82 )
{
struct V_76 * V_77 = & V_5 -> V_78 ;
struct V_79 * V_84 ;
F_8 ( L_10 , V_77 , F_49 ( & V_82 -> V_56 ) ) ;
V_84 = F_48 ( V_5 , & V_82 -> V_56 ) ;
if ( ! V_84 ) {
V_84 = F_52 ( sizeof( struct V_79 ) , V_85 ) ;
if ( ! V_84 )
return;
V_84 -> V_80 = V_77 -> V_74 ;
V_77 -> V_74 = V_84 ;
}
memcpy ( & V_84 -> V_82 , V_82 , sizeof( * V_82 ) ) ;
V_84 -> V_86 = V_87 ;
V_77 -> V_86 = V_87 ;
}
static int F_53 ( struct V_4 * V_5 , int V_88 , T_4 * V_89 )
{
struct V_76 * V_77 = & V_5 -> V_78 ;
struct V_90 * V_91 = (struct V_90 * ) V_89 ;
struct V_79 * V_81 ;
int V_92 = 0 ;
for ( V_81 = V_77 -> V_74 ; V_81 && V_92 < V_88 ; V_81 = V_81 -> V_80 , V_92 ++ ) {
struct V_83 * V_82 = & V_81 -> V_82 ;
F_34 ( & V_91 -> V_56 , & V_82 -> V_56 ) ;
V_91 -> V_93 = V_82 -> V_93 ;
V_91 -> V_94 = V_82 -> V_94 ;
V_91 -> V_95 = V_82 -> V_95 ;
memcpy ( V_91 -> V_96 , V_82 -> V_96 , 3 ) ;
V_91 -> V_97 = V_82 -> V_97 ;
V_91 ++ ;
}
F_8 ( L_11 , V_77 , V_92 ) ;
return V_92 ;
}
static void F_54 ( struct V_4 * V_5 , unsigned long V_20 )
{
struct V_98 * V_99 = (struct V_98 * ) V_20 ;
struct V_100 V_33 ;
F_8 ( L_6 , V_5 -> V_9 ) ;
if ( F_9 ( V_101 , & V_5 -> V_11 ) )
return;
memcpy ( & V_33 . V_102 , & V_99 -> V_102 , 3 ) ;
V_33 . V_103 = V_99 -> V_103 ;
V_33 . V_104 = V_99 -> V_104 ;
F_26 ( V_5 , V_105 , sizeof( V_33 ) , & V_33 ) ;
}
int F_55 ( void T_6 * V_106 )
{
T_4 T_6 * V_107 = V_106 ;
struct V_98 V_99 ;
struct V_4 * V_5 ;
int V_18 = 0 , V_108 = 0 , V_109 ;
long V_110 ;
T_4 * V_89 ;
if ( F_56 ( & V_99 , V_107 , sizeof( V_99 ) ) )
return - V_111 ;
V_5 = F_40 ( V_99 . V_112 ) ;
if ( ! V_5 )
return - V_113 ;
F_57 ( V_5 ) ;
if ( F_58 ( V_5 ) > V_114 ||
F_59 ( V_5 ) ||
V_99 . V_11 & V_115 ) {
F_46 ( V_5 ) ;
V_108 = 1 ;
}
F_60 ( V_5 ) ;
V_110 = V_99 . V_103 * F_61 ( 2000 ) ;
if ( V_108 ) {
V_18 = F_21 ( V_5 , F_54 , ( unsigned long ) & V_99 , V_110 ) ;
if ( V_18 < 0 )
goto V_116;
}
V_109 = ( V_99 . V_104 == 0 ) ? 255 : V_99 . V_104 ;
V_89 = F_62 ( sizeof( struct V_90 ) * V_109 , V_117 ) ;
if ( ! V_89 ) {
V_18 = - V_118 ;
goto V_116;
}
F_57 ( V_5 ) ;
V_99 . V_104 = F_53 ( V_5 , V_109 , V_89 ) ;
F_60 ( V_5 ) ;
F_8 ( L_12 , V_99 . V_104 ) ;
if ( ! F_63 ( V_107 , & V_99 , sizeof( V_99 ) ) ) {
V_107 += sizeof( V_99 ) ;
if ( F_63 ( V_107 , V_89 , sizeof( struct V_90 ) *
V_99 . V_104 ) )
V_18 = - V_111 ;
} else
V_18 = - V_111 ;
F_47 ( V_89 ) ;
V_116:
F_64 ( V_5 ) ;
return V_18 ;
}
int F_65 ( T_1 V_41 )
{
struct V_4 * V_5 ;
int V_27 = 0 ;
V_5 = F_40 ( V_41 ) ;
if ( ! V_5 )
return - V_113 ;
F_8 ( L_13 , V_5 -> V_9 , V_5 ) ;
F_22 ( V_5 ) ;
if ( V_5 -> V_119 && F_66 ( V_5 -> V_119 ) ) {
V_27 = - V_120 ;
goto V_116;
}
if ( F_9 ( V_28 , & V_5 -> V_11 ) ) {
V_27 = - V_121 ;
goto V_116;
}
if ( F_9 ( V_122 , & V_5 -> V_45 ) )
F_25 ( V_123 , & V_5 -> V_11 ) ;
if ( V_5 -> V_124 != V_125 )
F_25 ( V_123 , & V_5 -> V_11 ) ;
if ( V_5 -> V_126 ( V_5 ) ) {
V_27 = - V_127 ;
goto V_116;
}
if ( ! F_9 ( V_123 , & V_5 -> V_11 ) ) {
F_67 ( & V_5 -> V_128 , 1 ) ;
F_25 ( V_10 , & V_5 -> V_11 ) ;
V_5 -> V_12 = 0 ;
V_27 = F_12 ( V_5 , F_27 , 0 ,
F_61 ( V_129 ) ) ;
if ( F_68 ( V_5 ) )
V_27 = F_12 ( V_5 , F_35 , 0 ,
F_61 ( V_129 ) ) ;
F_69 ( V_10 , & V_5 -> V_11 ) ;
}
if ( ! V_27 ) {
F_44 ( V_5 ) ;
F_25 ( V_28 , & V_5 -> V_11 ) ;
F_5 ( V_5 , V_130 ) ;
if ( ! F_9 ( V_131 , & V_5 -> V_11 ) )
F_70 ( V_5 -> V_75 , 1 ) ;
} else {
F_71 ( & V_5 -> V_132 ) ;
F_71 ( & V_5 -> V_133 ) ;
F_71 ( & V_5 -> V_43 ) ;
F_32 ( & V_5 -> V_42 ) ;
F_32 ( & V_5 -> V_134 ) ;
if ( V_5 -> V_135 )
V_5 -> V_135 ( V_5 ) ;
if ( V_5 -> V_136 ) {
F_72 ( V_5 -> V_136 ) ;
V_5 -> V_136 = NULL ;
}
V_5 -> V_137 ( V_5 ) ;
V_5 -> V_11 = 0 ;
}
V_116:
F_23 ( V_5 ) ;
F_64 ( V_5 ) ;
return V_27 ;
}
static int F_73 ( struct V_4 * V_5 )
{
F_8 ( L_13 , V_5 -> V_9 , V_5 ) ;
F_11 ( V_5 , V_113 ) ;
F_22 ( V_5 ) ;
if ( ! F_74 ( V_28 , & V_5 -> V_11 ) ) {
F_75 ( & V_5 -> V_138 ) ;
F_23 ( V_5 ) ;
return 0 ;
}
F_71 ( & V_5 -> V_132 ) ;
F_71 ( & V_5 -> V_133 ) ;
F_57 ( V_5 ) ;
F_46 ( V_5 ) ;
F_76 ( V_5 ) ;
F_60 ( V_5 ) ;
F_5 ( V_5 , V_139 ) ;
if ( V_5 -> V_135 )
V_5 -> V_135 ( V_5 ) ;
F_32 ( & V_5 -> V_42 ) ;
F_67 ( & V_5 -> V_128 , 1 ) ;
if ( ! F_9 ( V_123 , & V_5 -> V_11 ) ) {
F_25 ( V_10 , & V_5 -> V_11 ) ;
F_12 ( V_5 , F_24 , 0 ,
F_61 ( 250 ) ) ;
F_69 ( V_10 , & V_5 -> V_11 ) ;
}
F_71 ( & V_5 -> V_43 ) ;
F_32 ( & V_5 -> V_134 ) ;
F_32 ( & V_5 -> V_42 ) ;
F_32 ( & V_5 -> V_140 ) ;
if ( V_5 -> V_136 ) {
F_75 ( & V_5 -> V_138 ) ;
F_72 ( V_5 -> V_136 ) ;
V_5 -> V_136 = NULL ;
}
V_5 -> V_137 ( V_5 ) ;
F_70 ( V_5 -> V_75 , 0 ) ;
V_5 -> V_11 = 0 ;
F_23 ( V_5 ) ;
F_64 ( V_5 ) ;
return 0 ;
}
int F_77 ( T_1 V_41 )
{
struct V_4 * V_5 ;
int V_18 ;
V_5 = F_40 ( V_41 ) ;
if ( ! V_5 )
return - V_113 ;
V_18 = F_73 ( V_5 ) ;
F_64 ( V_5 ) ;
return V_18 ;
}
int F_78 ( T_1 V_41 )
{
struct V_4 * V_5 ;
int V_27 = 0 ;
V_5 = F_40 ( V_41 ) ;
if ( ! V_5 )
return - V_113 ;
F_22 ( V_5 ) ;
F_79 ( & V_5 -> V_133 ) ;
if ( ! F_9 ( V_28 , & V_5 -> V_11 ) )
goto V_116;
F_32 ( & V_5 -> V_134 ) ;
F_32 ( & V_5 -> V_42 ) ;
F_57 ( V_5 ) ;
F_46 ( V_5 ) ;
F_76 ( V_5 ) ;
F_60 ( V_5 ) ;
if ( V_5 -> V_135 )
V_5 -> V_135 ( V_5 ) ;
F_67 ( & V_5 -> V_128 , 1 ) ;
V_5 -> V_141 = 0 ; V_5 -> V_142 = 0 ; V_5 -> V_143 = 0 ;
if ( ! F_9 ( V_123 , & V_5 -> V_11 ) )
V_27 = F_12 ( V_5 , F_24 , 0 ,
F_61 ( V_129 ) ) ;
V_116:
F_80 ( & V_5 -> V_133 ) ;
F_23 ( V_5 ) ;
F_64 ( V_5 ) ;
return V_27 ;
}
int F_81 ( T_1 V_41 )
{
struct V_4 * V_5 ;
int V_27 = 0 ;
V_5 = F_40 ( V_41 ) ;
if ( ! V_5 )
return - V_113 ;
memset ( & V_5 -> V_144 , 0 , sizeof( struct V_145 ) ) ;
F_64 ( V_5 ) ;
return V_27 ;
}
int F_82 ( unsigned int V_7 , void T_6 * V_106 )
{
struct V_4 * V_5 ;
struct V_146 V_147 ;
int V_18 = 0 ;
if ( F_56 ( & V_147 , V_106 , sizeof( V_147 ) ) )
return - V_111 ;
V_5 = F_40 ( V_147 . V_112 ) ;
if ( ! V_5 )
return - V_113 ;
switch ( V_7 ) {
case V_148 :
V_18 = F_21 ( V_5 , F_37 , V_147 . V_149 ,
F_61 ( V_129 ) ) ;
break;
case V_150 :
if ( ! F_83 ( V_5 ) ) {
V_18 = - V_151 ;
break;
}
if ( ! F_9 ( V_152 , & V_5 -> V_11 ) ) {
V_18 = F_21 ( V_5 , F_37 , V_147 . V_149 ,
F_61 ( V_129 ) ) ;
if ( V_18 )
break;
}
V_18 = F_21 ( V_5 , F_38 , V_147 . V_149 ,
F_61 ( V_129 ) ) ;
break;
case V_153 :
V_18 = F_21 ( V_5 , F_36 , V_147 . V_149 ,
F_61 ( V_129 ) ) ;
break;
case V_154 :
V_18 = F_21 ( V_5 , F_39 , V_147 . V_149 ,
F_61 ( V_129 ) ) ;
break;
case V_155 :
V_5 -> V_156 = ( ( T_1 ) V_147 . V_149 ) &
( V_157 | V_158 ) ;
break;
case V_159 :
V_5 -> V_39 = ( T_1 ) V_147 . V_149 ;
break;
case V_160 :
V_5 -> V_161 = * ( ( T_1 * ) & V_147 . V_149 + 1 ) ;
V_5 -> V_162 = * ( ( T_1 * ) & V_147 . V_149 + 0 ) ;
break;
case V_163 :
V_5 -> V_164 = * ( ( T_1 * ) & V_147 . V_149 + 1 ) ;
V_5 -> V_165 = * ( ( T_1 * ) & V_147 . V_149 + 0 ) ;
break;
default:
V_18 = - V_166 ;
break;
}
F_64 ( V_5 ) ;
return V_18 ;
}
int F_84 ( void T_6 * V_106 )
{
struct V_167 * V_168 ;
struct V_146 * V_147 ;
struct V_70 * V_71 ;
int V_169 = 0 , V_170 , V_18 ;
T_1 V_171 ;
if ( F_85 ( V_171 , ( T_1 T_6 * ) V_106 ) )
return - V_111 ;
if ( ! V_171 || V_171 > ( V_172 * 2 ) / sizeof( * V_147 ) )
return - V_166 ;
V_170 = sizeof( * V_168 ) + V_171 * sizeof( * V_147 ) ;
V_168 = F_52 ( V_170 , V_117 ) ;
if ( ! V_168 )
return - V_118 ;
V_147 = V_168 -> V_173 ;
F_86 ( & V_72 ) ;
F_42 (p, &hci_dev_list) {
struct V_4 * V_5 ;
V_5 = F_43 ( V_71 , struct V_4 , V_74 ) ;
F_87 ( V_5 ) ;
if ( ! F_9 ( V_174 , & V_5 -> V_11 ) )
F_25 ( V_175 , & V_5 -> V_11 ) ;
( V_147 + V_169 ) -> V_112 = V_5 -> V_75 ;
( V_147 + V_169 ) -> V_149 = V_5 -> V_11 ;
if ( ++ V_169 >= V_171 )
break;
}
F_88 ( & V_72 ) ;
V_168 -> V_171 = V_169 ;
V_170 = sizeof( * V_168 ) + V_169 * sizeof( * V_147 ) ;
V_18 = F_63 ( V_106 , V_168 , V_170 ) ;
F_47 ( V_168 ) ;
return V_18 ? - V_111 : 0 ;
}
int F_89 ( void T_6 * V_106 )
{
struct V_4 * V_5 ;
struct V_176 V_177 ;
int V_18 = 0 ;
if ( F_56 ( & V_177 , V_106 , sizeof( V_177 ) ) )
return - V_111 ;
V_5 = F_40 ( V_177 . V_112 ) ;
if ( ! V_5 )
return - V_113 ;
F_87 ( V_5 ) ;
if ( ! F_9 ( V_174 , & V_5 -> V_11 ) )
F_25 ( V_175 , & V_5 -> V_11 ) ;
strcpy ( V_177 . V_9 , V_5 -> V_9 ) ;
V_177 . V_56 = V_5 -> V_56 ;
V_177 . type = ( V_5 -> V_178 & 0x0f ) | ( V_5 -> V_124 << 4 ) ;
V_177 . V_11 = V_5 -> V_11 ;
V_177 . V_39 = V_5 -> V_39 ;
V_177 . V_161 = V_5 -> V_161 ;
V_177 . V_162 = V_5 -> V_162 ;
V_177 . V_164 = V_5 -> V_164 ;
V_177 . V_165 = V_5 -> V_165 ;
V_177 . V_179 = V_5 -> V_179 ;
V_177 . V_156 = V_5 -> V_156 ;
memcpy ( & V_177 . V_144 , & V_5 -> V_144 , sizeof( V_177 . V_144 ) ) ;
memcpy ( & V_177 . V_180 , & V_5 -> V_180 , sizeof( V_177 . V_180 ) ) ;
if ( F_63 ( V_106 , & V_177 , sizeof( V_177 ) ) )
V_18 = - V_111 ;
F_64 ( V_5 ) ;
return V_18 ;
}
static int F_90 ( void * V_82 , bool V_181 )
{
struct V_4 * V_5 = V_82 ;
F_8 ( L_14 , V_5 , V_5 -> V_9 , V_181 ) ;
if ( ! V_181 )
return 0 ;
F_73 ( V_5 ) ;
return 0 ;
}
struct V_4 * F_91 ( void )
{
struct V_4 * V_5 ;
V_5 = F_52 ( sizeof( struct V_4 ) , V_117 ) ;
if ( ! V_5 )
return NULL ;
F_92 ( & V_5 -> V_38 ) ;
return V_5 ;
}
void F_93 ( struct V_4 * V_5 )
{
F_32 ( & V_5 -> V_38 ) ;
F_94 ( & V_5 -> V_41 ) ;
}
static void F_95 ( struct V_182 * V_183 )
{
struct V_4 * V_5 = F_96 ( V_183 , struct V_4 , V_184 ) ;
F_8 ( L_6 , V_5 -> V_9 ) ;
if ( F_65 ( V_5 -> V_75 ) < 0 )
return;
if ( F_9 ( V_185 , & V_5 -> V_11 ) )
F_97 ( & V_5 -> V_186 ,
V_87 + F_61 ( V_187 ) ) ;
if ( F_74 ( V_131 , & V_5 -> V_11 ) )
F_98 ( V_5 -> V_75 ) ;
}
static void F_99 ( struct V_182 * V_183 )
{
struct V_4 * V_5 = F_96 ( V_183 , struct V_4 , V_188 ) ;
F_8 ( L_6 , V_5 -> V_9 ) ;
F_77 ( V_5 -> V_75 ) ;
}
static void F_100 ( unsigned long V_82 )
{
struct V_4 * V_5 = (struct V_4 * ) V_82 ;
F_8 ( L_6 , V_5 -> V_9 ) ;
F_69 ( V_185 , & V_5 -> V_11 ) ;
F_101 ( V_5 -> V_189 , & V_5 -> V_188 ) ;
}
void F_87 ( struct V_4 * V_5 )
{
F_8 ( L_6 , V_5 -> V_9 ) ;
F_69 ( V_185 , & V_5 -> V_11 ) ;
F_102 ( & V_5 -> V_186 ) ;
}
int F_103 ( struct V_4 * V_5 )
{
struct V_70 * V_71 , * V_169 ;
F_104 (p, n, &hdev->uuids) {
struct V_190 * V_191 ;
V_191 = F_43 ( V_71 , struct V_190 , V_74 ) ;
F_105 ( V_71 ) ;
F_47 ( V_191 ) ;
}
return 0 ;
}
int F_106 ( struct V_4 * V_5 )
{
struct V_70 * V_71 , * V_169 ;
F_104 (p, n, &hdev->link_keys) {
struct V_192 * V_193 ;
V_193 = F_43 ( V_71 , struct V_192 , V_74 ) ;
F_105 ( V_71 ) ;
F_47 ( V_193 ) ;
}
return 0 ;
}
struct V_192 * F_107 ( struct V_4 * V_5 , T_5 * V_56 )
{
struct V_70 * V_71 ;
F_42 (p, &hdev->link_keys) {
struct V_192 * V_194 ;
V_194 = F_43 ( V_71 , struct V_192 , V_74 ) ;
if ( F_50 ( V_56 , & V_194 -> V_56 ) == 0 )
return V_194 ;
}
return NULL ;
}
static int F_108 ( struct V_4 * V_5 , struct V_195 * V_196 ,
T_7 V_197 , T_7 V_198 )
{
if ( V_197 < 0x03 )
return 1 ;
if ( V_197 == V_199 )
return 0 ;
if ( V_197 == V_200 && V_198 == 0xff )
return 0 ;
if ( ! V_196 )
return 1 ;
if ( V_196 -> V_201 > 0x01 && V_196 -> V_202 > 0x01 )
return 1 ;
if ( V_196 -> V_201 == 0x02 || V_196 -> V_201 == 0x03 )
return 1 ;
if ( V_196 -> V_202 == 0x02 || V_196 -> V_202 == 0x03 )
return 1 ;
return 0 ;
}
int F_109 ( struct V_4 * V_5 , struct V_195 * V_196 , int V_203 ,
T_5 * V_56 , T_7 * V_204 , T_7 type , T_7 V_205 )
{
struct V_192 * V_193 , * V_206 ;
T_7 V_198 , V_207 ;
V_206 = F_107 ( V_5 , V_56 ) ;
if ( V_206 ) {
V_198 = V_206 -> type ;
V_193 = V_206 ;
} else {
V_198 = V_196 ? V_196 -> V_197 : 0xff ;
V_193 = F_52 ( sizeof( * V_193 ) , V_85 ) ;
if ( ! V_193 )
return - V_118 ;
F_110 ( & V_193 -> V_74 , & V_5 -> V_208 ) ;
}
F_8 ( L_15 , V_5 -> V_9 , F_49 ( V_56 ) , type ) ;
if ( type == V_200 &&
( ! V_196 || V_196 -> V_202 == 0xff ) &&
V_198 == 0xff ) {
type = V_209 ;
if ( V_196 )
V_196 -> V_197 = type ;
}
F_34 ( & V_193 -> V_56 , V_56 ) ;
memcpy ( V_193 -> V_204 , V_204 , 16 ) ;
V_193 -> V_205 = V_205 ;
if ( type == V_200 )
V_193 -> type = V_198 ;
else
V_193 -> type = type ;
if ( ! V_203 )
return 0 ;
V_207 = F_108 ( V_5 , V_196 , type , V_198 ) ;
F_111 ( V_5 -> V_75 , V_193 , V_207 ) ;
if ( ! V_207 ) {
F_105 ( & V_193 -> V_74 ) ;
F_47 ( V_193 ) ;
}
return 0 ;
}
int F_112 ( struct V_4 * V_5 , T_5 * V_56 )
{
struct V_192 * V_193 ;
V_193 = F_107 ( V_5 , V_56 ) ;
if ( ! V_193 )
return - V_210 ;
F_8 ( L_16 , V_5 -> V_9 , F_49 ( V_56 ) ) ;
F_105 ( & V_193 -> V_74 ) ;
F_47 ( V_193 ) ;
return 0 ;
}
static void F_113 ( unsigned long V_106 )
{
struct V_4 * V_5 = ( void * ) V_106 ;
F_114 ( L_17 , V_5 -> V_9 ) ;
F_67 ( & V_5 -> V_128 , 1 ) ;
F_69 ( V_30 , & V_5 -> V_11 ) ;
F_31 ( & V_5 -> V_43 ) ;
}
struct V_211 * F_115 ( struct V_4 * V_5 ,
T_5 * V_56 )
{
struct V_211 * V_82 ;
F_116 (data, &hdev->remote_oob_data, list)
if ( F_50 ( V_56 , & V_82 -> V_56 ) == 0 )
return V_82 ;
return NULL ;
}
int F_117 ( struct V_4 * V_5 , T_5 * V_56 )
{
struct V_211 * V_82 ;
V_82 = F_115 ( V_5 , V_56 ) ;
if ( ! V_82 )
return - V_210 ;
F_8 ( L_16 , V_5 -> V_9 , F_49 ( V_56 ) ) ;
F_105 ( & V_82 -> V_74 ) ;
F_47 ( V_82 ) ;
return 0 ;
}
int F_118 ( struct V_4 * V_5 )
{
struct V_211 * V_82 , * V_169 ;
F_119 (data, n, &hdev->remote_oob_data, list) {
F_105 ( & V_82 -> V_74 ) ;
F_47 ( V_82 ) ;
}
return 0 ;
}
int F_120 ( struct V_4 * V_5 , T_5 * V_56 , T_7 * V_212 ,
T_7 * V_213 )
{
struct V_211 * V_82 ;
V_82 = F_115 ( V_5 , V_56 ) ;
if ( ! V_82 ) {
V_82 = F_62 ( sizeof( * V_82 ) , V_85 ) ;
if ( ! V_82 )
return - V_118 ;
F_34 ( & V_82 -> V_56 , V_56 ) ;
F_110 ( & V_82 -> V_74 , & V_5 -> V_214 ) ;
}
memcpy ( V_82 -> V_212 , V_212 , sizeof( V_82 -> V_212 ) ) ;
memcpy ( V_82 -> V_213 , V_213 , sizeof( V_82 -> V_213 ) ) ;
F_8 ( L_18 , V_5 -> V_9 , F_49 ( V_56 ) ) ;
return 0 ;
}
int F_121 ( struct V_4 * V_5 )
{
struct V_70 * V_215 = & V_216 , * V_71 ;
int V_217 , V_75 = 0 ;
F_8 ( L_19 , V_5 , V_5 -> V_9 ,
V_5 -> V_178 , V_5 -> V_218 ) ;
if ( ! V_5 -> V_126 || ! V_5 -> V_137 || ! V_5 -> V_219 )
return - V_166 ;
F_122 ( & V_72 ) ;
F_42 (p, &hci_dev_list) {
if ( F_43 ( V_71 , struct V_4 , V_74 ) -> V_75 != V_75 )
break;
V_215 = V_71 ; V_75 ++ ;
}
sprintf ( V_5 -> V_9 , L_20 , V_75 ) ;
V_5 -> V_75 = V_75 ;
F_110 ( & V_5 -> V_74 , V_215 ) ;
F_67 ( & V_5 -> V_220 , 1 ) ;
F_123 ( & V_5 -> V_221 ) ;
V_5 -> V_11 = 0 ;
V_5 -> V_39 = ( V_222 | V_223 | V_224 ) ;
V_5 -> V_225 = ( V_226 ) ;
V_5 -> V_156 = ( V_158 ) ;
V_5 -> V_227 = 0x03 ;
V_5 -> V_228 = 0 ;
V_5 -> V_229 = 800 ;
V_5 -> V_230 = 80 ;
F_124 ( & V_5 -> V_43 , V_231 , ( unsigned long ) V_5 ) ;
F_124 ( & V_5 -> V_132 , V_232 , ( unsigned long ) V_5 ) ;
F_124 ( & V_5 -> V_133 , V_233 , ( unsigned long ) V_5 ) ;
F_92 ( & V_5 -> V_134 ) ;
F_92 ( & V_5 -> V_42 ) ;
F_92 ( & V_5 -> V_140 ) ;
F_125 ( & V_5 -> V_138 , F_113 , ( unsigned long ) V_5 ) ;
for ( V_217 = 0 ; V_217 < V_234 ; V_217 ++ )
V_5 -> V_235 [ V_217 ] = NULL ;
F_126 ( & V_5 -> V_17 ) ;
F_127 ( & V_5 -> V_236 ) ;
F_128 ( V_5 ) ;
F_129 ( V_5 ) ;
F_130 ( & V_5 -> V_237 ) ;
F_130 ( & V_5 -> V_238 ) ;
F_130 ( & V_5 -> V_208 ) ;
F_130 ( & V_5 -> V_214 ) ;
F_131 ( & V_5 -> V_184 , F_95 ) ;
F_131 ( & V_5 -> V_188 , F_99 ) ;
F_125 ( & V_5 -> V_186 , F_100 , ( unsigned long ) V_5 ) ;
memset ( & V_5 -> V_144 , 0 , sizeof( struct V_145 ) ) ;
F_67 ( & V_5 -> V_239 , 0 ) ;
F_132 ( & V_72 ) ;
V_5 -> V_189 = F_133 ( V_5 -> V_9 ) ;
if ( ! V_5 -> V_189 )
goto V_240;
F_134 ( V_5 ) ;
V_5 -> V_119 = F_135 ( V_5 -> V_9 , & V_5 -> V_41 ,
V_241 , & V_242 , V_5 ) ;
if ( V_5 -> V_119 ) {
if ( F_136 ( V_5 -> V_119 ) < 0 ) {
F_137 ( V_5 -> V_119 ) ;
V_5 -> V_119 = NULL ;
}
}
F_25 ( V_185 , & V_5 -> V_11 ) ;
F_25 ( V_131 , & V_5 -> V_11 ) ;
F_101 ( V_5 -> V_189 , & V_5 -> V_184 ) ;
F_5 ( V_5 , V_243 ) ;
return V_75 ;
V_240:
F_122 ( & V_72 ) ;
F_105 ( & V_5 -> V_74 ) ;
F_132 ( & V_72 ) ;
return - V_118 ;
}
int F_138 ( struct V_4 * V_5 )
{
int V_217 ;
F_8 ( L_21 , V_5 , V_5 -> V_9 , V_5 -> V_178 ) ;
F_122 ( & V_72 ) ;
F_105 ( & V_5 -> V_74 ) ;
F_132 ( & V_72 ) ;
F_73 ( V_5 ) ;
for ( V_217 = 0 ; V_217 < V_234 ; V_217 ++ )
F_72 ( V_5 -> V_235 [ V_217 ] ) ;
if ( ! F_9 ( V_10 , & V_5 -> V_11 ) &&
! F_9 ( V_131 , & V_5 -> V_11 ) )
F_139 ( V_5 -> V_75 ) ;
F_5 ( V_5 , V_244 ) ;
if ( V_5 -> V_119 ) {
F_140 ( V_5 -> V_119 ) ;
F_137 ( V_5 -> V_119 ) ;
}
F_141 ( V_5 ) ;
F_87 ( V_5 ) ;
F_142 ( V_5 -> V_189 ) ;
F_57 ( V_5 ) ;
F_143 ( V_5 ) ;
F_103 ( V_5 ) ;
F_106 ( V_5 ) ;
F_118 ( V_5 ) ;
F_60 ( V_5 ) ;
F_144 ( V_5 ) ;
return 0 ;
}
int F_145 ( struct V_4 * V_5 )
{
F_5 ( V_5 , V_245 ) ;
return 0 ;
}
int F_146 ( struct V_4 * V_5 )
{
F_5 ( V_5 , V_246 ) ;
return 0 ;
}
int F_147 ( struct V_34 * V_35 )
{
struct V_4 * V_5 = (struct V_4 * ) V_35 -> V_41 ;
if ( ! V_5 || ( ! F_9 ( V_28 , & V_5 -> V_11 )
&& ! F_9 ( V_10 , & V_5 -> V_11 ) ) ) {
F_72 ( V_35 ) ;
return - V_247 ;
}
F_29 ( V_35 ) -> V_248 = 1 ;
F_148 ( V_35 ) ;
F_30 ( & V_5 -> V_134 , V_35 ) ;
F_31 ( & V_5 -> V_132 ) ;
return 0 ;
}
static int F_149 ( struct V_4 * V_5 , int type , void * V_82 ,
int V_249 , T_4 V_69 )
{
int V_250 = 0 ;
int V_251 = 0 ;
int V_252 = V_249 ;
struct V_34 * V_35 ;
struct V_253 * V_254 ;
if ( ( type < V_255 || type > V_256 ) ||
V_69 >= V_234 )
return - V_257 ;
V_35 = V_5 -> V_235 [ V_69 ] ;
if ( ! V_35 ) {
switch ( type ) {
case V_255 :
V_250 = V_258 ;
V_251 = V_259 ;
break;
case V_256 :
V_250 = V_260 ;
V_251 = V_261 ;
break;
case V_262 :
V_250 = V_263 ;
V_251 = V_264 ;
break;
}
V_35 = F_150 ( V_250 , V_85 ) ;
if ( ! V_35 )
return - V_118 ;
V_254 = ( void * ) V_35 -> V_265 ;
V_254 -> V_266 = V_251 ;
V_254 -> V_39 = type ;
V_35 -> V_41 = ( void * ) V_5 ;
V_5 -> V_235 [ V_69 ] = V_35 ;
}
while ( V_249 ) {
V_254 = ( void * ) V_35 -> V_265 ;
V_250 = F_151 ( V_254 -> V_266 , ( T_1 ) V_249 ) ;
memcpy ( F_152 ( V_35 , V_250 ) , V_82 , V_250 ) ;
V_249 -= V_250 ;
V_82 += V_250 ;
V_254 -> V_266 -= V_250 ;
V_252 = V_249 ;
switch ( type ) {
case V_256 :
if ( V_35 -> V_250 == V_261 ) {
struct V_267 * V_268 = V_267 ( V_35 ) ;
V_254 -> V_266 = V_268 -> V_269 ;
if ( F_153 ( V_35 ) < V_254 -> V_266 ) {
F_72 ( V_35 ) ;
V_5 -> V_235 [ V_69 ] = NULL ;
return - V_118 ;
}
}
break;
case V_255 :
if ( V_35 -> V_250 == V_259 ) {
struct V_270 * V_268 = V_270 ( V_35 ) ;
V_254 -> V_266 = F_154 ( V_268 -> V_271 ) ;
if ( F_153 ( V_35 ) < V_254 -> V_266 ) {
F_72 ( V_35 ) ;
V_5 -> V_235 [ V_69 ] = NULL ;
return - V_118 ;
}
}
break;
case V_262 :
if ( V_35 -> V_250 == V_264 ) {
struct V_272 * V_268 = V_272 ( V_35 ) ;
V_254 -> V_266 = V_268 -> V_271 ;
if ( F_153 ( V_35 ) < V_254 -> V_266 ) {
F_72 ( V_35 ) ;
V_5 -> V_235 [ V_69 ] = NULL ;
return - V_118 ;
}
}
break;
}
if ( V_254 -> V_266 == 0 ) {
F_29 ( V_35 ) -> V_39 = type ;
F_147 ( V_35 ) ;
V_5 -> V_235 [ V_69 ] = NULL ;
return V_252 ;
}
}
return V_252 ;
}
int F_155 ( struct V_4 * V_5 , int type , void * V_82 , int V_249 )
{
int V_273 = 0 ;
if ( type < V_255 || type > V_256 )
return - V_257 ;
while ( V_249 ) {
V_273 = F_149 ( V_5 , type , V_82 , V_249 , type - 1 ) ;
if ( V_273 < 0 )
return V_273 ;
V_82 += ( V_249 - V_273 ) ;
V_249 = V_273 ;
} ;
return V_273 ;
}
int F_156 ( struct V_4 * V_5 , void * V_82 , int V_249 )
{
int type ;
int V_273 = 0 ;
while ( V_249 ) {
struct V_34 * V_35 = V_5 -> V_235 [ V_274 ] ;
if ( ! V_35 ) {
struct { char type ; } * V_275 ;
V_275 = V_82 ;
type = V_275 -> type ;
V_82 ++ ;
V_249 -- ;
} else
type = F_29 ( V_35 ) -> V_39 ;
V_273 = F_149 ( V_5 , type , V_82 , V_249 ,
V_274 ) ;
if ( V_273 < 0 )
return V_273 ;
V_82 += ( V_249 - V_273 ) ;
V_249 = V_273 ;
} ;
return V_273 ;
}
int F_157 ( struct V_276 * V_277 )
{
int V_18 = 0 ;
F_8 ( L_22 , V_277 , V_277 -> V_9 , V_277 -> V_75 ) ;
if ( V_277 -> V_75 >= V_278 )
return - V_166 ;
F_122 ( & V_279 ) ;
if ( ! V_276 [ V_277 -> V_75 ] )
V_276 [ V_277 -> V_75 ] = V_277 ;
else
V_18 = - V_280 ;
F_132 ( & V_279 ) ;
return V_18 ;
}
int F_158 ( struct V_276 * V_277 )
{
int V_18 = 0 ;
F_8 ( L_22 , V_277 , V_277 -> V_9 , V_277 -> V_75 ) ;
if ( V_277 -> V_75 >= V_278 )
return - V_166 ;
F_122 ( & V_279 ) ;
if ( V_276 [ V_277 -> V_75 ] )
V_276 [ V_277 -> V_75 ] = NULL ;
else
V_18 = - V_210 ;
F_132 ( & V_279 ) ;
return V_18 ;
}
int F_159 ( struct V_281 * V_265 )
{
F_8 ( L_23 , V_265 , V_265 -> V_9 ) ;
F_122 ( & V_282 ) ;
F_110 ( & V_265 -> V_74 , & V_283 ) ;
F_132 ( & V_282 ) ;
return 0 ;
}
int F_160 ( struct V_281 * V_265 )
{
F_8 ( L_23 , V_265 , V_265 -> V_9 ) ;
F_122 ( & V_282 ) ;
F_105 ( & V_265 -> V_74 ) ;
F_132 ( & V_282 ) ;
return 0 ;
}
static int F_161 ( struct V_34 * V_35 )
{
struct V_4 * V_5 = (struct V_4 * ) V_35 -> V_41 ;
if ( ! V_5 ) {
F_72 ( V_35 ) ;
return - V_113 ;
}
F_8 ( L_24 , V_5 -> V_9 , F_29 ( V_35 ) -> V_39 , V_35 -> V_250 ) ;
if ( F_162 ( & V_5 -> V_239 ) ) {
F_148 ( V_35 ) ;
F_163 ( V_5 , V_35 , NULL ) ;
}
F_164 ( V_35 ) ;
return V_5 -> V_284 ( V_35 ) ;
}
int F_26 ( struct V_4 * V_5 , T_1 V_285 , T_2 V_269 , void * V_36 )
{
int V_250 = V_286 + V_269 ;
struct V_287 * V_288 ;
struct V_34 * V_35 ;
F_8 ( L_25 , V_5 -> V_9 , V_285 , V_269 ) ;
V_35 = F_150 ( V_250 , V_85 ) ;
if ( ! V_35 ) {
F_114 ( L_26 , V_5 -> V_9 ) ;
return - V_118 ;
}
V_288 = (struct V_287 * ) F_152 ( V_35 , V_286 ) ;
V_288 -> V_285 = F_33 ( V_285 ) ;
V_288 -> V_269 = V_269 ;
if ( V_269 )
memcpy ( F_152 ( V_35 , V_269 ) , V_36 , V_269 ) ;
F_8 ( L_27 , V_35 -> V_250 ) ;
F_29 ( V_35 ) -> V_39 = V_40 ;
V_35 -> V_41 = ( void * ) V_5 ;
if ( F_9 ( V_10 , & V_5 -> V_11 ) )
V_5 -> V_12 = V_285 ;
F_30 ( & V_5 -> V_42 , V_35 ) ;
F_31 ( & V_5 -> V_43 ) ;
return 0 ;
}
void * F_165 ( struct V_4 * V_5 , T_1 V_285 )
{
struct V_287 * V_288 ;
if ( ! V_5 -> V_136 )
return NULL ;
V_288 = ( void * ) V_5 -> V_136 -> V_82 ;
if ( V_288 -> V_285 != F_33 ( V_285 ) )
return NULL ;
F_8 ( L_28 , V_5 -> V_9 , V_285 ) ;
return V_5 -> V_136 -> V_82 + V_286 ;
}
static void F_166 ( struct V_34 * V_35 , T_1 V_289 , T_1 V_11 )
{
struct V_270 * V_288 ;
int V_250 = V_35 -> V_250 ;
F_167 ( V_35 , V_259 ) ;
F_168 ( V_35 ) ;
V_288 = (struct V_270 * ) F_169 ( V_35 ) ;
V_288 -> V_289 = F_33 ( F_170 ( V_289 , V_11 ) ) ;
V_288 -> V_271 = F_33 ( V_250 ) ;
}
void F_171 ( struct V_195 * V_196 , struct V_34 * V_35 , T_1 V_11 )
{
struct V_4 * V_5 = V_196 -> V_5 ;
struct V_34 * V_74 ;
F_8 ( L_29 , V_5 -> V_9 , V_196 , V_11 ) ;
V_35 -> V_41 = ( void * ) V_5 ;
F_29 ( V_35 ) -> V_39 = V_255 ;
F_166 ( V_35 , V_196 -> V_289 , V_11 ) ;
V_74 = F_172 ( V_35 ) -> V_290 ;
if ( ! V_74 ) {
F_8 ( L_30 , V_5 -> V_9 , V_35 , V_35 -> V_250 ) ;
F_30 ( & V_196 -> V_291 , V_35 ) ;
} else {
F_8 ( L_31 , V_5 -> V_9 , V_35 , V_35 -> V_250 ) ;
F_172 ( V_35 ) -> V_290 = NULL ;
F_173 ( & V_196 -> V_291 . V_221 ) ;
F_174 ( & V_196 -> V_291 , V_35 ) ;
V_11 &= ~ V_292 ;
V_11 |= V_293 ;
do {
V_35 = V_74 ; V_74 = V_74 -> V_80 ;
V_35 -> V_41 = ( void * ) V_5 ;
F_29 ( V_35 ) -> V_39 = V_255 ;
F_166 ( V_35 , V_196 -> V_289 , V_11 ) ;
F_8 ( L_31 , V_5 -> V_9 , V_35 , V_35 -> V_250 ) ;
F_174 ( & V_196 -> V_291 , V_35 ) ;
} while ( V_74 );
F_175 ( & V_196 -> V_291 . V_221 ) ;
}
F_31 ( & V_5 -> V_133 ) ;
}
void F_176 ( struct V_195 * V_196 , struct V_34 * V_35 )
{
struct V_4 * V_5 = V_196 -> V_5 ;
struct V_272 V_288 ;
F_8 ( L_32 , V_5 -> V_9 , V_35 -> V_250 ) ;
V_288 . V_289 = F_33 ( V_196 -> V_289 ) ;
V_288 . V_271 = V_35 -> V_250 ;
F_167 ( V_35 , V_264 ) ;
F_168 ( V_35 ) ;
memcpy ( F_169 ( V_35 ) , & V_288 , V_264 ) ;
V_35 -> V_41 = ( void * ) V_5 ;
F_29 ( V_35 ) -> V_39 = V_262 ;
F_30 ( & V_196 -> V_291 , V_35 ) ;
F_31 ( & V_5 -> V_133 ) ;
}
static inline struct V_195 * F_177 ( struct V_4 * V_5 , T_4 type , int * V_294 )
{
struct V_295 * V_268 = & V_5 -> V_296 ;
struct V_195 * V_196 = NULL ;
int V_88 = 0 , F_151 = ~ 0 ;
struct V_70 * V_71 ;
F_42 (p, &h->list) {
struct V_195 * V_297 ;
V_297 = F_43 ( V_71 , struct V_195 , V_74 ) ;
if ( V_297 -> type != type || F_178 ( & V_297 -> V_291 ) )
continue;
if ( V_297 -> V_298 != V_299 && V_297 -> V_298 != V_300 )
continue;
V_88 ++ ;
if ( V_297 -> V_301 < F_151 ) {
F_151 = V_297 -> V_301 ;
V_196 = V_297 ;
}
}
if ( V_196 ) {
int V_302 , V_303 ;
switch ( V_196 -> type ) {
case V_304 :
V_302 = V_5 -> V_141 ;
break;
case V_305 :
case V_306 :
V_302 = V_5 -> V_142 ;
break;
case V_307 :
V_302 = V_5 -> V_308 ? V_5 -> V_143 : V_5 -> V_141 ;
break;
default:
V_302 = 0 ;
F_114 ( L_33 ) ;
}
V_303 = V_302 / V_88 ;
* V_294 = V_303 ? V_303 : 1 ;
} else
* V_294 = 0 ;
F_8 ( L_34 , V_196 , * V_294 ) ;
return V_196 ;
}
static inline void F_179 ( struct V_4 * V_5 , T_4 type )
{
struct V_295 * V_268 = & V_5 -> V_296 ;
struct V_70 * V_71 ;
struct V_195 * V_297 ;
F_114 ( L_35 , V_5 -> V_9 ) ;
F_42 (p, &h->list) {
V_297 = F_43 ( V_71 , struct V_195 , V_74 ) ;
if ( V_297 -> type == type && V_297 -> V_301 ) {
F_114 ( L_36 ,
V_5 -> V_9 , F_49 ( & V_297 -> V_309 ) ) ;
F_180 ( V_297 , 0x13 ) ;
}
}
}
static inline void F_181 ( struct V_4 * V_5 )
{
struct V_195 * V_196 ;
struct V_34 * V_35 ;
int V_294 ;
F_8 ( L_6 , V_5 -> V_9 ) ;
if ( ! F_9 ( V_123 , & V_5 -> V_11 ) ) {
if ( ! V_5 -> V_141 && F_182 ( V_87 , V_5 -> V_310 + V_311 * 45 ) )
F_179 ( V_5 , V_304 ) ;
}
while ( V_5 -> V_141 && ( V_196 = F_177 ( V_5 , V_304 , & V_294 ) ) ) {
while ( V_294 -- && ( V_35 = F_28 ( & V_196 -> V_291 ) ) ) {
F_8 ( L_37 , V_35 , V_35 -> V_250 ) ;
F_183 ( V_196 ) ;
F_161 ( V_35 ) ;
V_5 -> V_310 = V_87 ;
V_5 -> V_141 -- ;
V_196 -> V_301 ++ ;
}
}
}
static inline void F_184 ( struct V_4 * V_5 )
{
struct V_195 * V_196 ;
struct V_34 * V_35 ;
int V_294 ;
F_8 ( L_6 , V_5 -> V_9 ) ;
while ( V_5 -> V_142 && ( V_196 = F_177 ( V_5 , V_305 , & V_294 ) ) ) {
while ( V_294 -- && ( V_35 = F_28 ( & V_196 -> V_291 ) ) ) {
F_8 ( L_37 , V_35 , V_35 -> V_250 ) ;
F_161 ( V_35 ) ;
V_196 -> V_301 ++ ;
if ( V_196 -> V_301 == ~ 0 )
V_196 -> V_301 = 0 ;
}
}
}
static inline void F_185 ( struct V_4 * V_5 )
{
struct V_195 * V_196 ;
struct V_34 * V_35 ;
int V_294 ;
F_8 ( L_6 , V_5 -> V_9 ) ;
while ( V_5 -> V_142 && ( V_196 = F_177 ( V_5 , V_306 , & V_294 ) ) ) {
while ( V_294 -- && ( V_35 = F_28 ( & V_196 -> V_291 ) ) ) {
F_8 ( L_37 , V_35 , V_35 -> V_250 ) ;
F_161 ( V_35 ) ;
V_196 -> V_301 ++ ;
if ( V_196 -> V_301 == ~ 0 )
V_196 -> V_301 = 0 ;
}
}
}
static inline void F_186 ( struct V_4 * V_5 )
{
struct V_195 * V_196 ;
struct V_34 * V_35 ;
int V_294 , V_302 ;
F_8 ( L_6 , V_5 -> V_9 ) ;
if ( ! F_9 ( V_123 , & V_5 -> V_11 ) ) {
if ( ! V_5 -> V_143 && V_5 -> V_312 &&
F_182 ( V_87 , V_5 -> V_313 + V_311 * 45 ) )
F_179 ( V_5 , V_307 ) ;
}
V_302 = V_5 -> V_312 ? V_5 -> V_143 : V_5 -> V_141 ;
while ( V_302 && ( V_196 = F_177 ( V_5 , V_307 , & V_294 ) ) ) {
while ( V_294 -- && ( V_35 = F_28 ( & V_196 -> V_291 ) ) ) {
F_8 ( L_37 , V_35 , V_35 -> V_250 ) ;
F_161 ( V_35 ) ;
V_5 -> V_313 = V_87 ;
V_302 -- ;
V_196 -> V_301 ++ ;
}
}
if ( V_5 -> V_312 )
V_5 -> V_143 = V_302 ;
else
V_5 -> V_141 = V_302 ;
}
static void V_233 ( unsigned long V_106 )
{
struct V_4 * V_5 = (struct V_4 * ) V_106 ;
struct V_34 * V_35 ;
F_41 ( & V_279 ) ;
F_8 ( L_38 , V_5 -> V_9 , V_5 -> V_141 ,
V_5 -> V_142 , V_5 -> V_143 ) ;
F_181 ( V_5 ) ;
F_184 ( V_5 ) ;
F_185 ( V_5 ) ;
F_186 ( V_5 ) ;
while ( ( V_35 = F_28 ( & V_5 -> V_140 ) ) )
F_161 ( V_35 ) ;
F_45 ( & V_279 ) ;
}
static inline void F_187 ( struct V_4 * V_5 , struct V_34 * V_35 )
{
struct V_270 * V_288 = ( void * ) V_35 -> V_82 ;
struct V_195 * V_196 ;
T_1 V_289 , V_11 ;
F_188 ( V_35 , V_259 ) ;
V_289 = F_154 ( V_288 -> V_289 ) ;
V_11 = F_189 ( V_289 ) ;
V_289 = F_190 ( V_289 ) ;
F_8 ( L_39 , V_5 -> V_9 , V_35 -> V_250 , V_289 , V_11 ) ;
V_5 -> V_144 . V_314 ++ ;
F_191 ( V_5 ) ;
V_196 = F_192 ( V_5 , V_289 ) ;
F_193 ( V_5 ) ;
if ( V_196 ) {
register struct V_276 * V_277 ;
F_183 ( V_196 ) ;
V_277 = V_276 [ V_315 ] ;
if ( V_277 && V_277 -> V_316 ) {
V_277 -> V_316 ( V_196 , V_35 , V_11 ) ;
return;
}
} else {
F_114 ( L_40 ,
V_5 -> V_9 , V_289 ) ;
}
F_72 ( V_35 ) ;
}
static inline void F_194 ( struct V_4 * V_5 , struct V_34 * V_35 )
{
struct V_272 * V_288 = ( void * ) V_35 -> V_82 ;
struct V_195 * V_196 ;
T_1 V_289 ;
F_188 ( V_35 , V_264 ) ;
V_289 = F_154 ( V_288 -> V_289 ) ;
F_8 ( L_41 , V_5 -> V_9 , V_35 -> V_250 , V_289 ) ;
V_5 -> V_144 . V_317 ++ ;
F_191 ( V_5 ) ;
V_196 = F_192 ( V_5 , V_289 ) ;
F_193 ( V_5 ) ;
if ( V_196 ) {
register struct V_276 * V_277 ;
V_277 = V_276 [ V_318 ] ;
if ( V_277 && V_277 -> V_319 ) {
V_277 -> V_319 ( V_196 , V_35 ) ;
return;
}
} else {
F_114 ( L_42 ,
V_5 -> V_9 , V_289 ) ;
}
F_72 ( V_35 ) ;
}
static void V_232 ( unsigned long V_106 )
{
struct V_4 * V_5 = (struct V_4 * ) V_106 ;
struct V_34 * V_35 ;
F_8 ( L_6 , V_5 -> V_9 ) ;
F_41 ( & V_279 ) ;
while ( ( V_35 = F_28 ( & V_5 -> V_134 ) ) ) {
if ( F_162 ( & V_5 -> V_239 ) ) {
F_163 ( V_5 , V_35 , NULL ) ;
}
if ( F_9 ( V_123 , & V_5 -> V_11 ) ) {
F_72 ( V_35 ) ;
continue;
}
if ( F_9 ( V_10 , & V_5 -> V_11 ) ) {
switch ( F_29 ( V_35 ) -> V_39 ) {
case V_255 :
case V_262 :
F_72 ( V_35 ) ;
continue;
}
}
switch ( F_29 ( V_35 ) -> V_39 ) {
case V_256 :
F_195 ( V_5 , V_35 ) ;
break;
case V_255 :
F_8 ( L_43 , V_5 -> V_9 ) ;
F_187 ( V_5 , V_35 ) ;
break;
case V_262 :
F_8 ( L_44 , V_5 -> V_9 ) ;
F_194 ( V_5 , V_35 ) ;
break;
default:
F_72 ( V_35 ) ;
break;
}
}
F_45 ( & V_279 ) ;
}
static void V_231 ( unsigned long V_106 )
{
struct V_4 * V_5 = (struct V_4 * ) V_106 ;
struct V_34 * V_35 ;
F_8 ( L_45 , V_5 -> V_9 , F_162 ( & V_5 -> V_128 ) ) ;
if ( F_162 ( & V_5 -> V_128 ) ) {
V_35 = F_28 ( & V_5 -> V_42 ) ;
if ( ! V_35 )
return;
F_72 ( V_5 -> V_136 ) ;
V_5 -> V_136 = F_196 ( V_35 , V_85 ) ;
if ( V_5 -> V_136 ) {
F_197 ( & V_5 -> V_128 ) ;
F_161 ( V_35 ) ;
F_97 ( & V_5 -> V_138 ,
V_87 + F_61 ( V_320 ) ) ;
} else {
F_198 ( & V_5 -> V_42 , V_35 ) ;
F_31 ( & V_5 -> V_43 ) ;
}
}
}
