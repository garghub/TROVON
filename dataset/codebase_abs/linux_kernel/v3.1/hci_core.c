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
struct V_192 * F_109 ( struct V_4 * V_5 , T_3 V_203 , T_7 rand [ 8 ] )
{
struct V_192 * V_194 ;
F_110 (k, &hdev->link_keys, list) {
struct V_204 * V_75 ;
if ( V_194 -> type != V_205 )
continue;
if ( V_194 -> V_206 != sizeof( * V_75 ) )
continue;
V_75 = ( void * ) & V_194 -> V_82 ;
if ( V_75 -> V_203 == V_203 &&
( memcmp ( rand , V_75 -> rand , sizeof( V_75 -> rand ) ) == 0 ) )
return V_194 ;
}
return NULL ;
}
struct V_192 * F_111 ( struct V_4 * V_5 ,
T_5 * V_56 , T_7 type )
{
struct V_192 * V_194 ;
F_110 (k, &hdev->link_keys, list)
if ( V_194 -> type == type && F_50 ( V_56 , & V_194 -> V_56 ) == 0 )
return V_194 ;
return NULL ;
}
int F_112 ( struct V_4 * V_5 , struct V_195 * V_196 , int V_207 ,
T_5 * V_56 , T_7 * V_208 , T_7 type , T_7 V_209 )
{
struct V_192 * V_193 , * V_210 ;
T_7 V_198 , V_211 ;
V_210 = F_107 ( V_5 , V_56 ) ;
if ( V_210 ) {
V_198 = V_210 -> type ;
V_193 = V_210 ;
} else {
V_198 = V_196 ? V_196 -> V_197 : 0xff ;
V_193 = F_52 ( sizeof( * V_193 ) , V_85 ) ;
if ( ! V_193 )
return - V_118 ;
F_113 ( & V_193 -> V_74 , & V_5 -> V_212 ) ;
}
F_8 ( L_15 , V_5 -> V_9 , F_49 ( V_56 ) , type ) ;
if ( type == V_200 &&
( ! V_196 || V_196 -> V_202 == 0xff ) &&
V_198 == 0xff ) {
type = V_213 ;
if ( V_196 )
V_196 -> V_197 = type ;
}
F_34 ( & V_193 -> V_56 , V_56 ) ;
memcpy ( V_193 -> V_208 , V_208 , 16 ) ;
V_193 -> V_209 = V_209 ;
if ( type == V_200 )
V_193 -> type = V_198 ;
else
V_193 -> type = type ;
if ( ! V_207 )
return 0 ;
V_211 = F_108 ( V_5 , V_196 , type , V_198 ) ;
F_114 ( V_5 -> V_75 , V_193 , V_211 ) ;
if ( ! V_211 ) {
F_105 ( & V_193 -> V_74 ) ;
F_47 ( V_193 ) ;
}
return 0 ;
}
int F_115 ( struct V_4 * V_5 , int V_207 , T_5 * V_56 ,
T_7 V_214 , T_3 V_203 , T_7 rand [ 8 ] , T_7 V_215 [ 16 ] )
{
struct V_192 * V_193 , * V_210 ;
struct V_204 * V_75 ;
T_7 V_198 ;
F_8 ( L_16 , V_5 -> V_9 , F_49 ( V_56 ) ) ;
V_210 = F_111 ( V_5 , V_56 , V_205 ) ;
if ( V_210 ) {
V_193 = V_210 ;
V_198 = V_210 -> type ;
} else {
V_193 = F_52 ( sizeof( * V_193 ) + sizeof( * V_75 ) , V_85 ) ;
if ( ! V_193 )
return - V_118 ;
F_113 ( & V_193 -> V_74 , & V_5 -> V_212 ) ;
V_198 = 0xff ;
}
V_193 -> V_206 = sizeof( * V_75 ) ;
F_34 ( & V_193 -> V_56 , V_56 ) ;
memcpy ( V_193 -> V_208 , V_215 , sizeof( V_193 -> V_208 ) ) ;
V_193 -> type = V_205 ;
V_193 -> V_209 = V_214 ;
V_75 = ( void * ) & V_193 -> V_82 ;
V_75 -> V_203 = V_203 ;
memcpy ( V_75 -> rand , rand , sizeof( V_75 -> rand ) ) ;
if ( V_207 )
F_114 ( V_5 -> V_75 , V_193 , V_198 ) ;
return 0 ;
}
int F_116 ( struct V_4 * V_5 , T_5 * V_56 )
{
struct V_192 * V_193 ;
V_193 = F_107 ( V_5 , V_56 ) ;
if ( ! V_193 )
return - V_216 ;
F_8 ( L_17 , V_5 -> V_9 , F_49 ( V_56 ) ) ;
F_105 ( & V_193 -> V_74 ) ;
F_47 ( V_193 ) ;
return 0 ;
}
static void F_117 ( unsigned long V_106 )
{
struct V_4 * V_5 = ( void * ) V_106 ;
F_118 ( L_18 , V_5 -> V_9 ) ;
F_67 ( & V_5 -> V_128 , 1 ) ;
F_31 ( & V_5 -> V_43 ) ;
}
struct V_217 * F_119 ( struct V_4 * V_5 ,
T_5 * V_56 )
{
struct V_217 * V_82 ;
F_110 (data, &hdev->remote_oob_data, list)
if ( F_50 ( V_56 , & V_82 -> V_56 ) == 0 )
return V_82 ;
return NULL ;
}
int F_120 ( struct V_4 * V_5 , T_5 * V_56 )
{
struct V_217 * V_82 ;
V_82 = F_119 ( V_5 , V_56 ) ;
if ( ! V_82 )
return - V_216 ;
F_8 ( L_17 , V_5 -> V_9 , F_49 ( V_56 ) ) ;
F_105 ( & V_82 -> V_74 ) ;
F_47 ( V_82 ) ;
return 0 ;
}
int F_121 ( struct V_4 * V_5 )
{
struct V_217 * V_82 , * V_169 ;
F_122 (data, n, &hdev->remote_oob_data, list) {
F_105 ( & V_82 -> V_74 ) ;
F_47 ( V_82 ) ;
}
return 0 ;
}
int F_123 ( struct V_4 * V_5 , T_5 * V_56 , T_7 * V_218 ,
T_7 * V_219 )
{
struct V_217 * V_82 ;
V_82 = F_119 ( V_5 , V_56 ) ;
if ( ! V_82 ) {
V_82 = F_62 ( sizeof( * V_82 ) , V_85 ) ;
if ( ! V_82 )
return - V_118 ;
F_34 ( & V_82 -> V_56 , V_56 ) ;
F_113 ( & V_82 -> V_74 , & V_5 -> V_220 ) ;
}
memcpy ( V_82 -> V_218 , V_218 , sizeof( V_82 -> V_218 ) ) ;
memcpy ( V_82 -> V_219 , V_219 , sizeof( V_82 -> V_219 ) ) ;
F_8 ( L_19 , V_5 -> V_9 , F_49 ( V_56 ) ) ;
return 0 ;
}
struct V_221 * F_124 ( struct V_4 * V_5 ,
T_5 * V_56 )
{
struct V_70 * V_71 ;
F_42 (p, &hdev->blacklist) {
struct V_221 * V_222 ;
V_222 = F_43 ( V_71 , struct V_221 , V_74 ) ;
if ( F_50 ( V_56 , & V_222 -> V_56 ) == 0 )
return V_222 ;
}
return NULL ;
}
int F_125 ( struct V_4 * V_5 )
{
struct V_70 * V_71 , * V_169 ;
F_104 (p, n, &hdev->blacklist) {
struct V_221 * V_222 ;
V_222 = F_43 ( V_71 , struct V_221 , V_74 ) ;
F_105 ( V_71 ) ;
F_47 ( V_222 ) ;
}
return 0 ;
}
int F_126 ( struct V_4 * V_5 , T_5 * V_56 )
{
struct V_221 * V_223 ;
int V_18 ;
if ( F_50 ( V_56 , V_57 ) == 0 )
return - V_224 ;
F_57 ( V_5 ) ;
if ( F_124 ( V_5 , V_56 ) ) {
V_18 = - V_225 ;
goto V_18;
}
V_223 = F_52 ( sizeof( struct V_221 ) , V_117 ) ;
if ( ! V_223 ) {
V_18 = - V_118 ;
goto V_18;
}
F_34 ( & V_223 -> V_56 , V_56 ) ;
F_113 ( & V_223 -> V_74 , & V_5 -> V_226 ) ;
V_18 = 0 ;
V_18:
F_60 ( V_5 ) ;
return V_18 ;
}
int F_127 ( struct V_4 * V_5 , T_5 * V_56 )
{
struct V_221 * V_223 ;
int V_18 = 0 ;
F_57 ( V_5 ) ;
if ( F_50 ( V_56 , V_57 ) == 0 ) {
F_125 ( V_5 ) ;
goto V_116;
}
V_223 = F_124 ( V_5 , V_56 ) ;
if ( ! V_223 ) {
V_18 = - V_216 ;
goto V_116;
}
F_105 ( & V_223 -> V_74 ) ;
F_47 ( V_223 ) ;
V_116:
F_60 ( V_5 ) ;
return V_18 ;
}
static void F_128 ( unsigned long V_106 )
{
struct V_4 * V_5 = ( void * ) V_106 ;
F_129 ( V_5 ) ;
F_130 ( V_5 ) ;
F_131 ( V_5 ) ;
}
int F_130 ( struct V_4 * V_5 )
{
struct V_227 * V_223 , * V_228 ;
F_122 (entry, tmp, &hdev->adv_entries, list) {
F_105 ( & V_223 -> V_74 ) ;
F_47 ( V_223 ) ;
}
F_8 ( L_20 , V_5 -> V_9 ) ;
return 0 ;
}
struct V_227 * F_132 ( struct V_4 * V_5 , T_5 * V_56 )
{
struct V_227 * V_223 ;
F_110 (entry, &hdev->adv_entries, list)
if ( F_50 ( V_56 , & V_223 -> V_56 ) == 0 )
return V_223 ;
return NULL ;
}
static inline int F_133 ( T_7 V_229 )
{
if ( V_229 == V_230 || V_229 == V_231 )
return 1 ;
return 0 ;
}
int F_134 ( struct V_4 * V_5 ,
struct V_232 * V_233 )
{
struct V_227 * V_223 ;
if ( ! F_133 ( V_233 -> V_229 ) )
return - V_166 ;
if ( F_132 ( V_5 , & V_233 -> V_56 ) )
return 0 ;
V_223 = F_52 ( sizeof( * V_223 ) , V_85 ) ;
if ( ! V_223 )
return - V_118 ;
F_34 ( & V_223 -> V_56 , & V_233 -> V_56 ) ;
V_223 -> V_234 = V_233 -> V_234 ;
F_113 ( & V_223 -> V_74 , & V_5 -> V_235 ) ;
F_8 ( L_21 , V_5 -> V_9 ,
F_49 ( & V_223 -> V_56 ) , V_223 -> V_234 ) ;
return 0 ;
}
int F_135 ( struct V_4 * V_5 )
{
struct V_70 * V_236 = & V_237 , * V_71 ;
int V_238 , V_75 = 0 ;
F_8 ( L_22 , V_5 , V_5 -> V_9 ,
V_5 -> V_178 , V_5 -> V_239 ) ;
if ( ! V_5 -> V_126 || ! V_5 -> V_137 || ! V_5 -> V_240 )
return - V_166 ;
F_136 ( & V_72 ) ;
F_42 (p, &hci_dev_list) {
if ( F_43 ( V_71 , struct V_4 , V_74 ) -> V_75 != V_75 )
break;
V_236 = V_71 ; V_75 ++ ;
}
sprintf ( V_5 -> V_9 , L_23 , V_75 ) ;
V_5 -> V_75 = V_75 ;
F_113 ( & V_5 -> V_74 , V_236 ) ;
F_67 ( & V_5 -> V_241 , 1 ) ;
F_137 ( & V_5 -> V_242 ) ;
V_5 -> V_11 = 0 ;
V_5 -> V_39 = ( V_243 | V_244 | V_245 ) ;
V_5 -> V_246 = ( V_247 ) ;
V_5 -> V_156 = ( V_158 ) ;
V_5 -> V_248 = 0x03 ;
V_5 -> V_249 = 0 ;
V_5 -> V_250 = 800 ;
V_5 -> V_251 = 80 ;
F_138 ( & V_5 -> V_43 , V_252 , ( unsigned long ) V_5 ) ;
F_138 ( & V_5 -> V_132 , V_253 , ( unsigned long ) V_5 ) ;
F_138 ( & V_5 -> V_133 , V_254 , ( unsigned long ) V_5 ) ;
F_92 ( & V_5 -> V_134 ) ;
F_92 ( & V_5 -> V_42 ) ;
F_92 ( & V_5 -> V_140 ) ;
F_139 ( & V_5 -> V_138 , F_117 , ( unsigned long ) V_5 ) ;
for ( V_238 = 0 ; V_238 < V_255 ; V_238 ++ )
V_5 -> V_256 [ V_238 ] = NULL ;
F_140 ( & V_5 -> V_17 ) ;
F_141 ( & V_5 -> V_257 ) ;
F_142 ( V_5 ) ;
F_143 ( V_5 ) ;
F_144 ( & V_5 -> V_226 ) ;
F_144 ( & V_5 -> V_258 ) ;
F_144 ( & V_5 -> V_212 ) ;
F_144 ( & V_5 -> V_220 ) ;
F_144 ( & V_5 -> V_235 ) ;
F_139 ( & V_5 -> V_259 , F_128 ,
( unsigned long ) V_5 ) ;
F_145 ( & V_5 -> V_184 , F_95 ) ;
F_145 ( & V_5 -> V_188 , F_99 ) ;
F_139 ( & V_5 -> V_186 , F_100 , ( unsigned long ) V_5 ) ;
memset ( & V_5 -> V_144 , 0 , sizeof( struct V_145 ) ) ;
F_67 ( & V_5 -> V_260 , 0 ) ;
F_146 ( & V_72 ) ;
V_5 -> V_189 = F_147 ( V_5 -> V_9 ) ;
if ( ! V_5 -> V_189 )
goto V_261;
V_5 -> V_262 = F_148 ( L_24 , 0 , V_263 ) ;
if ( F_149 ( V_5 -> V_262 ) )
F_150 ( L_25 ,
F_151 ( V_5 -> V_262 ) ) ;
F_152 ( V_5 ) ;
V_5 -> V_119 = F_153 ( V_5 -> V_9 , & V_5 -> V_41 ,
V_264 , & V_265 , V_5 ) ;
if ( V_5 -> V_119 ) {
if ( F_154 ( V_5 -> V_119 ) < 0 ) {
F_155 ( V_5 -> V_119 ) ;
V_5 -> V_119 = NULL ;
}
}
F_25 ( V_185 , & V_5 -> V_11 ) ;
F_25 ( V_131 , & V_5 -> V_11 ) ;
F_101 ( V_5 -> V_189 , & V_5 -> V_184 ) ;
F_5 ( V_5 , V_266 ) ;
return V_75 ;
V_261:
F_136 ( & V_72 ) ;
F_105 ( & V_5 -> V_74 ) ;
F_146 ( & V_72 ) ;
return - V_118 ;
}
int F_156 ( struct V_4 * V_5 )
{
int V_238 ;
F_8 ( L_26 , V_5 , V_5 -> V_9 , V_5 -> V_178 ) ;
F_136 ( & V_72 ) ;
F_105 ( & V_5 -> V_74 ) ;
F_146 ( & V_72 ) ;
F_73 ( V_5 ) ;
for ( V_238 = 0 ; V_238 < V_255 ; V_238 ++ )
F_72 ( V_5 -> V_256 [ V_238 ] ) ;
if ( ! F_9 ( V_10 , & V_5 -> V_11 ) &&
! F_9 ( V_131 , & V_5 -> V_11 ) )
F_157 ( V_5 -> V_75 ) ;
if ( ! F_149 ( V_5 -> V_262 ) )
F_158 ( V_5 -> V_262 ) ;
F_5 ( V_5 , V_267 ) ;
if ( V_5 -> V_119 ) {
F_159 ( V_5 -> V_119 ) ;
F_155 ( V_5 -> V_119 ) ;
}
F_160 ( V_5 ) ;
F_87 ( V_5 ) ;
F_102 ( & V_5 -> V_259 ) ;
F_161 ( V_5 -> V_189 ) ;
F_57 ( V_5 ) ;
F_125 ( V_5 ) ;
F_103 ( V_5 ) ;
F_106 ( V_5 ) ;
F_121 ( V_5 ) ;
F_130 ( V_5 ) ;
F_60 ( V_5 ) ;
F_162 ( V_5 ) ;
return 0 ;
}
int F_163 ( struct V_4 * V_5 )
{
F_5 ( V_5 , V_268 ) ;
return 0 ;
}
int F_164 ( struct V_4 * V_5 )
{
F_5 ( V_5 , V_269 ) ;
return 0 ;
}
int F_165 ( struct V_34 * V_35 )
{
struct V_4 * V_5 = (struct V_4 * ) V_35 -> V_41 ;
if ( ! V_5 || ( ! F_9 ( V_28 , & V_5 -> V_11 )
&& ! F_9 ( V_10 , & V_5 -> V_11 ) ) ) {
F_72 ( V_35 ) ;
return - V_270 ;
}
F_29 ( V_35 ) -> V_271 = 1 ;
F_166 ( V_35 ) ;
F_30 ( & V_5 -> V_134 , V_35 ) ;
F_31 ( & V_5 -> V_132 ) ;
return 0 ;
}
static int F_167 ( struct V_4 * V_5 , int type , void * V_82 ,
int V_272 , T_4 V_69 )
{
int V_273 = 0 ;
int V_274 = 0 ;
int V_275 = V_272 ;
struct V_34 * V_35 ;
struct V_276 * V_277 ;
if ( ( type < V_278 || type > V_279 ) ||
V_69 >= V_255 )
return - V_280 ;
V_35 = V_5 -> V_256 [ V_69 ] ;
if ( ! V_35 ) {
switch ( type ) {
case V_278 :
V_273 = V_281 ;
V_274 = V_282 ;
break;
case V_279 :
V_273 = V_283 ;
V_274 = V_284 ;
break;
case V_285 :
V_273 = V_286 ;
V_274 = V_287 ;
break;
}
V_35 = F_168 ( V_273 , V_85 ) ;
if ( ! V_35 )
return - V_118 ;
V_277 = ( void * ) V_35 -> V_288 ;
V_277 -> V_289 = V_274 ;
V_277 -> V_39 = type ;
V_35 -> V_41 = ( void * ) V_5 ;
V_5 -> V_256 [ V_69 ] = V_35 ;
}
while ( V_272 ) {
V_277 = ( void * ) V_35 -> V_288 ;
V_273 = F_169 ( V_277 -> V_289 , ( T_1 ) V_272 ) ;
memcpy ( F_170 ( V_35 , V_273 ) , V_82 , V_273 ) ;
V_272 -= V_273 ;
V_82 += V_273 ;
V_277 -> V_289 -= V_273 ;
V_275 = V_272 ;
switch ( type ) {
case V_279 :
if ( V_35 -> V_273 == V_284 ) {
struct V_290 * V_291 = V_290 ( V_35 ) ;
V_277 -> V_289 = V_291 -> V_292 ;
if ( F_171 ( V_35 ) < V_277 -> V_289 ) {
F_72 ( V_35 ) ;
V_5 -> V_256 [ V_69 ] = NULL ;
return - V_118 ;
}
}
break;
case V_278 :
if ( V_35 -> V_273 == V_282 ) {
struct V_293 * V_291 = V_293 ( V_35 ) ;
V_277 -> V_289 = F_172 ( V_291 -> V_206 ) ;
if ( F_171 ( V_35 ) < V_277 -> V_289 ) {
F_72 ( V_35 ) ;
V_5 -> V_256 [ V_69 ] = NULL ;
return - V_118 ;
}
}
break;
case V_285 :
if ( V_35 -> V_273 == V_287 ) {
struct V_294 * V_291 = V_294 ( V_35 ) ;
V_277 -> V_289 = V_291 -> V_206 ;
if ( F_171 ( V_35 ) < V_277 -> V_289 ) {
F_72 ( V_35 ) ;
V_5 -> V_256 [ V_69 ] = NULL ;
return - V_118 ;
}
}
break;
}
if ( V_277 -> V_289 == 0 ) {
F_29 ( V_35 ) -> V_39 = type ;
F_165 ( V_35 ) ;
V_5 -> V_256 [ V_69 ] = NULL ;
return V_275 ;
}
}
return V_275 ;
}
int F_173 ( struct V_4 * V_5 , int type , void * V_82 , int V_272 )
{
int V_295 = 0 ;
if ( type < V_278 || type > V_279 )
return - V_280 ;
while ( V_272 ) {
V_295 = F_167 ( V_5 , type , V_82 , V_272 , type - 1 ) ;
if ( V_295 < 0 )
return V_295 ;
V_82 += ( V_272 - V_295 ) ;
V_272 = V_295 ;
}
return V_295 ;
}
int F_174 ( struct V_4 * V_5 , void * V_82 , int V_272 )
{
int type ;
int V_295 = 0 ;
while ( V_272 ) {
struct V_34 * V_35 = V_5 -> V_256 [ V_296 ] ;
if ( ! V_35 ) {
struct { char type ; } * V_297 ;
V_297 = V_82 ;
type = V_297 -> type ;
V_82 ++ ;
V_272 -- ;
} else
type = F_29 ( V_35 ) -> V_39 ;
V_295 = F_167 ( V_5 , type , V_82 , V_272 ,
V_296 ) ;
if ( V_295 < 0 )
return V_295 ;
V_82 += ( V_272 - V_295 ) ;
V_272 = V_295 ;
}
return V_295 ;
}
int F_175 ( struct V_298 * V_299 )
{
int V_18 = 0 ;
F_8 ( L_27 , V_299 , V_299 -> V_9 , V_299 -> V_75 ) ;
if ( V_299 -> V_75 >= V_300 )
return - V_166 ;
F_136 ( & V_301 ) ;
if ( ! V_298 [ V_299 -> V_75 ] )
V_298 [ V_299 -> V_75 ] = V_299 ;
else
V_18 = - V_225 ;
F_146 ( & V_301 ) ;
return V_18 ;
}
int F_176 ( struct V_298 * V_299 )
{
int V_18 = 0 ;
F_8 ( L_27 , V_299 , V_299 -> V_9 , V_299 -> V_75 ) ;
if ( V_299 -> V_75 >= V_300 )
return - V_166 ;
F_136 ( & V_301 ) ;
if ( V_298 [ V_299 -> V_75 ] )
V_298 [ V_299 -> V_75 ] = NULL ;
else
V_18 = - V_216 ;
F_146 ( & V_301 ) ;
return V_18 ;
}
int F_177 ( struct V_302 * V_288 )
{
F_8 ( L_28 , V_288 , V_288 -> V_9 ) ;
F_136 ( & V_303 ) ;
F_113 ( & V_288 -> V_74 , & V_304 ) ;
F_146 ( & V_303 ) ;
return 0 ;
}
int F_178 ( struct V_302 * V_288 )
{
F_8 ( L_28 , V_288 , V_288 -> V_9 ) ;
F_136 ( & V_303 ) ;
F_105 ( & V_288 -> V_74 ) ;
F_146 ( & V_303 ) ;
return 0 ;
}
static int F_179 ( struct V_34 * V_35 )
{
struct V_4 * V_5 = (struct V_4 * ) V_35 -> V_41 ;
if ( ! V_5 ) {
F_72 ( V_35 ) ;
return - V_113 ;
}
F_8 ( L_29 , V_5 -> V_9 , F_29 ( V_35 ) -> V_39 , V_35 -> V_273 ) ;
if ( F_180 ( & V_5 -> V_260 ) ) {
F_166 ( V_35 ) ;
F_181 ( V_5 , V_35 , NULL ) ;
}
F_182 ( V_35 ) ;
return V_5 -> V_305 ( V_35 ) ;
}
int F_26 ( struct V_4 * V_5 , T_1 V_306 , T_2 V_292 , void * V_36 )
{
int V_273 = V_307 + V_292 ;
struct V_308 * V_309 ;
struct V_34 * V_35 ;
F_8 ( L_30 , V_5 -> V_9 , V_306 , V_292 ) ;
V_35 = F_168 ( V_273 , V_85 ) ;
if ( ! V_35 ) {
F_118 ( L_31 , V_5 -> V_9 ) ;
return - V_118 ;
}
V_309 = (struct V_308 * ) F_170 ( V_35 , V_307 ) ;
V_309 -> V_306 = F_33 ( V_306 ) ;
V_309 -> V_292 = V_292 ;
if ( V_292 )
memcpy ( F_170 ( V_35 , V_292 ) , V_36 , V_292 ) ;
F_8 ( L_32 , V_35 -> V_273 ) ;
F_29 ( V_35 ) -> V_39 = V_40 ;
V_35 -> V_41 = ( void * ) V_5 ;
if ( F_9 ( V_10 , & V_5 -> V_11 ) )
V_5 -> V_12 = V_306 ;
F_30 ( & V_5 -> V_42 , V_35 ) ;
F_31 ( & V_5 -> V_43 ) ;
return 0 ;
}
void * F_183 ( struct V_4 * V_5 , T_1 V_306 )
{
struct V_308 * V_309 ;
if ( ! V_5 -> V_136 )
return NULL ;
V_309 = ( void * ) V_5 -> V_136 -> V_82 ;
if ( V_309 -> V_306 != F_33 ( V_306 ) )
return NULL ;
F_8 ( L_33 , V_5 -> V_9 , V_306 ) ;
return V_5 -> V_136 -> V_82 + V_307 ;
}
static void F_184 ( struct V_34 * V_35 , T_1 V_310 , T_1 V_11 )
{
struct V_293 * V_309 ;
int V_273 = V_35 -> V_273 ;
F_185 ( V_35 , V_282 ) ;
F_186 ( V_35 ) ;
V_309 = (struct V_293 * ) F_187 ( V_35 ) ;
V_309 -> V_310 = F_33 ( F_188 ( V_310 , V_11 ) ) ;
V_309 -> V_206 = F_33 ( V_273 ) ;
}
void F_189 ( struct V_195 * V_196 , struct V_34 * V_35 , T_1 V_11 )
{
struct V_4 * V_5 = V_196 -> V_5 ;
struct V_34 * V_74 ;
F_8 ( L_34 , V_5 -> V_9 , V_196 , V_11 ) ;
V_35 -> V_41 = ( void * ) V_5 ;
F_29 ( V_35 ) -> V_39 = V_278 ;
F_184 ( V_35 , V_196 -> V_310 , V_11 ) ;
V_74 = F_190 ( V_35 ) -> V_311 ;
if ( ! V_74 ) {
F_8 ( L_35 , V_5 -> V_9 , V_35 , V_35 -> V_273 ) ;
F_30 ( & V_196 -> V_312 , V_35 ) ;
} else {
F_8 ( L_36 , V_5 -> V_9 , V_35 , V_35 -> V_273 ) ;
F_190 ( V_35 ) -> V_311 = NULL ;
F_191 ( & V_196 -> V_312 . V_242 ) ;
F_192 ( & V_196 -> V_312 , V_35 ) ;
V_11 &= ~ V_313 ;
V_11 |= V_314 ;
do {
V_35 = V_74 ; V_74 = V_74 -> V_80 ;
V_35 -> V_41 = ( void * ) V_5 ;
F_29 ( V_35 ) -> V_39 = V_278 ;
F_184 ( V_35 , V_196 -> V_310 , V_11 ) ;
F_8 ( L_36 , V_5 -> V_9 , V_35 , V_35 -> V_273 ) ;
F_192 ( & V_196 -> V_312 , V_35 ) ;
} while ( V_74 );
F_193 ( & V_196 -> V_312 . V_242 ) ;
}
F_31 ( & V_5 -> V_133 ) ;
}
void F_194 ( struct V_195 * V_196 , struct V_34 * V_35 )
{
struct V_4 * V_5 = V_196 -> V_5 ;
struct V_294 V_309 ;
F_8 ( L_37 , V_5 -> V_9 , V_35 -> V_273 ) ;
V_309 . V_310 = F_33 ( V_196 -> V_310 ) ;
V_309 . V_206 = V_35 -> V_273 ;
F_185 ( V_35 , V_287 ) ;
F_186 ( V_35 ) ;
memcpy ( F_187 ( V_35 ) , & V_309 , V_287 ) ;
V_35 -> V_41 = ( void * ) V_5 ;
F_29 ( V_35 ) -> V_39 = V_285 ;
F_30 ( & V_196 -> V_312 , V_35 ) ;
F_31 ( & V_5 -> V_133 ) ;
}
static inline struct V_195 * F_195 ( struct V_4 * V_5 , T_4 type , int * V_315 )
{
struct V_316 * V_291 = & V_5 -> V_317 ;
struct V_195 * V_196 = NULL ;
int V_88 = 0 , F_169 = ~ 0 ;
struct V_70 * V_71 ;
F_42 (p, &h->list) {
struct V_195 * V_318 ;
V_318 = F_43 ( V_71 , struct V_195 , V_74 ) ;
if ( V_318 -> type != type || F_196 ( & V_318 -> V_312 ) )
continue;
if ( V_318 -> V_319 != V_320 && V_318 -> V_319 != V_321 )
continue;
V_88 ++ ;
if ( V_318 -> V_322 < F_169 ) {
F_169 = V_318 -> V_322 ;
V_196 = V_318 ;
}
}
if ( V_196 ) {
int V_323 , V_324 ;
switch ( V_196 -> type ) {
case V_325 :
V_323 = V_5 -> V_141 ;
break;
case V_326 :
case V_327 :
V_323 = V_5 -> V_142 ;
break;
case V_328 :
V_323 = V_5 -> V_329 ? V_5 -> V_143 : V_5 -> V_141 ;
break;
default:
V_323 = 0 ;
F_118 ( L_38 ) ;
}
V_324 = V_323 / V_88 ;
* V_315 = V_324 ? V_324 : 1 ;
} else
* V_315 = 0 ;
F_8 ( L_39 , V_196 , * V_315 ) ;
return V_196 ;
}
static inline void F_197 ( struct V_4 * V_5 , T_4 type )
{
struct V_316 * V_291 = & V_5 -> V_317 ;
struct V_70 * V_71 ;
struct V_195 * V_318 ;
F_118 ( L_40 , V_5 -> V_9 ) ;
F_42 (p, &h->list) {
V_318 = F_43 ( V_71 , struct V_195 , V_74 ) ;
if ( V_318 -> type == type && V_318 -> V_322 ) {
F_118 ( L_41 ,
V_5 -> V_9 , F_49 ( & V_318 -> V_330 ) ) ;
F_198 ( V_318 , 0x13 ) ;
}
}
}
static inline void F_199 ( struct V_4 * V_5 )
{
struct V_195 * V_196 ;
struct V_34 * V_35 ;
int V_315 ;
F_8 ( L_6 , V_5 -> V_9 ) ;
if ( ! F_9 ( V_123 , & V_5 -> V_11 ) ) {
if ( ! V_5 -> V_141 && F_200 ( V_87 , V_5 -> V_331 + V_332 * 45 ) )
F_197 ( V_5 , V_325 ) ;
}
while ( V_5 -> V_141 && ( V_196 = F_195 ( V_5 , V_325 , & V_315 ) ) ) {
while ( V_315 -- && ( V_35 = F_28 ( & V_196 -> V_312 ) ) ) {
F_8 ( L_42 , V_35 , V_35 -> V_273 ) ;
F_201 ( V_196 , F_29 ( V_35 ) -> V_333 ) ;
F_179 ( V_35 ) ;
V_5 -> V_331 = V_87 ;
V_5 -> V_141 -- ;
V_196 -> V_322 ++ ;
}
}
}
static inline void F_202 ( struct V_4 * V_5 )
{
struct V_195 * V_196 ;
struct V_34 * V_35 ;
int V_315 ;
F_8 ( L_6 , V_5 -> V_9 ) ;
while ( V_5 -> V_142 && ( V_196 = F_195 ( V_5 , V_326 , & V_315 ) ) ) {
while ( V_315 -- && ( V_35 = F_28 ( & V_196 -> V_312 ) ) ) {
F_8 ( L_42 , V_35 , V_35 -> V_273 ) ;
F_179 ( V_35 ) ;
V_196 -> V_322 ++ ;
if ( V_196 -> V_322 == ~ 0 )
V_196 -> V_322 = 0 ;
}
}
}
static inline void F_203 ( struct V_4 * V_5 )
{
struct V_195 * V_196 ;
struct V_34 * V_35 ;
int V_315 ;
F_8 ( L_6 , V_5 -> V_9 ) ;
while ( V_5 -> V_142 && ( V_196 = F_195 ( V_5 , V_327 , & V_315 ) ) ) {
while ( V_315 -- && ( V_35 = F_28 ( & V_196 -> V_312 ) ) ) {
F_8 ( L_42 , V_35 , V_35 -> V_273 ) ;
F_179 ( V_35 ) ;
V_196 -> V_322 ++ ;
if ( V_196 -> V_322 == ~ 0 )
V_196 -> V_322 = 0 ;
}
}
}
static inline void F_204 ( struct V_4 * V_5 )
{
struct V_195 * V_196 ;
struct V_34 * V_35 ;
int V_315 , V_323 ;
F_8 ( L_6 , V_5 -> V_9 ) ;
if ( ! F_9 ( V_123 , & V_5 -> V_11 ) ) {
if ( ! V_5 -> V_143 && V_5 -> V_334 &&
F_200 ( V_87 , V_5 -> V_335 + V_332 * 45 ) )
F_197 ( V_5 , V_328 ) ;
}
V_323 = V_5 -> V_334 ? V_5 -> V_143 : V_5 -> V_141 ;
while ( V_323 && ( V_196 = F_195 ( V_5 , V_328 , & V_315 ) ) ) {
while ( V_315 -- && ( V_35 = F_28 ( & V_196 -> V_312 ) ) ) {
F_8 ( L_42 , V_35 , V_35 -> V_273 ) ;
F_179 ( V_35 ) ;
V_5 -> V_335 = V_87 ;
V_323 -- ;
V_196 -> V_322 ++ ;
}
}
if ( V_5 -> V_334 )
V_5 -> V_143 = V_323 ;
else
V_5 -> V_141 = V_323 ;
}
static void V_254 ( unsigned long V_106 )
{
struct V_4 * V_5 = (struct V_4 * ) V_106 ;
struct V_34 * V_35 ;
F_41 ( & V_301 ) ;
F_8 ( L_43 , V_5 -> V_9 , V_5 -> V_141 ,
V_5 -> V_142 , V_5 -> V_143 ) ;
F_199 ( V_5 ) ;
F_202 ( V_5 ) ;
F_203 ( V_5 ) ;
F_204 ( V_5 ) ;
while ( ( V_35 = F_28 ( & V_5 -> V_140 ) ) )
F_179 ( V_35 ) ;
F_45 ( & V_301 ) ;
}
static inline void F_205 ( struct V_4 * V_5 , struct V_34 * V_35 )
{
struct V_293 * V_309 = ( void * ) V_35 -> V_82 ;
struct V_195 * V_196 ;
T_1 V_310 , V_11 ;
F_206 ( V_35 , V_282 ) ;
V_310 = F_172 ( V_309 -> V_310 ) ;
V_11 = F_207 ( V_310 ) ;
V_310 = F_208 ( V_310 ) ;
F_8 ( L_44 , V_5 -> V_9 , V_35 -> V_273 , V_310 , V_11 ) ;
V_5 -> V_144 . V_336 ++ ;
F_129 ( V_5 ) ;
V_196 = F_209 ( V_5 , V_310 ) ;
F_131 ( V_5 ) ;
if ( V_196 ) {
register struct V_298 * V_299 ;
F_201 ( V_196 , F_29 ( V_35 ) -> V_333 ) ;
V_299 = V_298 [ V_337 ] ;
if ( V_299 && V_299 -> V_338 ) {
V_299 -> V_338 ( V_196 , V_35 , V_11 ) ;
return;
}
} else {
F_118 ( L_45 ,
V_5 -> V_9 , V_310 ) ;
}
F_72 ( V_35 ) ;
}
static inline void F_210 ( struct V_4 * V_5 , struct V_34 * V_35 )
{
struct V_294 * V_309 = ( void * ) V_35 -> V_82 ;
struct V_195 * V_196 ;
T_1 V_310 ;
F_206 ( V_35 , V_287 ) ;
V_310 = F_172 ( V_309 -> V_310 ) ;
F_8 ( L_46 , V_5 -> V_9 , V_35 -> V_273 , V_310 ) ;
V_5 -> V_144 . V_339 ++ ;
F_129 ( V_5 ) ;
V_196 = F_209 ( V_5 , V_310 ) ;
F_131 ( V_5 ) ;
if ( V_196 ) {
register struct V_298 * V_299 ;
V_299 = V_298 [ V_340 ] ;
if ( V_299 && V_299 -> V_341 ) {
V_299 -> V_341 ( V_196 , V_35 ) ;
return;
}
} else {
F_118 ( L_47 ,
V_5 -> V_9 , V_310 ) ;
}
F_72 ( V_35 ) ;
}
static void V_253 ( unsigned long V_106 )
{
struct V_4 * V_5 = (struct V_4 * ) V_106 ;
struct V_34 * V_35 ;
F_8 ( L_6 , V_5 -> V_9 ) ;
F_41 ( & V_301 ) ;
while ( ( V_35 = F_28 ( & V_5 -> V_134 ) ) ) {
if ( F_180 ( & V_5 -> V_260 ) ) {
F_181 ( V_5 , V_35 , NULL ) ;
}
if ( F_9 ( V_123 , & V_5 -> V_11 ) ) {
F_72 ( V_35 ) ;
continue;
}
if ( F_9 ( V_10 , & V_5 -> V_11 ) ) {
switch ( F_29 ( V_35 ) -> V_39 ) {
case V_278 :
case V_285 :
F_72 ( V_35 ) ;
continue;
}
}
switch ( F_29 ( V_35 ) -> V_39 ) {
case V_279 :
F_211 ( V_5 , V_35 ) ;
break;
case V_278 :
F_8 ( L_48 , V_5 -> V_9 ) ;
F_205 ( V_5 , V_35 ) ;
break;
case V_285 :
F_8 ( L_49 , V_5 -> V_9 ) ;
F_210 ( V_5 , V_35 ) ;
break;
default:
F_72 ( V_35 ) ;
break;
}
}
F_45 ( & V_301 ) ;
}
static void V_252 ( unsigned long V_106 )
{
struct V_4 * V_5 = (struct V_4 * ) V_106 ;
struct V_34 * V_35 ;
F_8 ( L_50 , V_5 -> V_9 , F_180 ( & V_5 -> V_128 ) ) ;
if ( F_180 ( & V_5 -> V_128 ) ) {
V_35 = F_28 ( & V_5 -> V_42 ) ;
if ( ! V_35 )
return;
F_72 ( V_5 -> V_136 ) ;
V_5 -> V_136 = F_212 ( V_35 , V_85 ) ;
if ( V_5 -> V_136 ) {
F_213 ( & V_5 -> V_128 ) ;
F_179 ( V_35 ) ;
if ( F_9 ( V_30 , & V_5 -> V_11 ) )
F_102 ( & V_5 -> V_138 ) ;
else
F_97 ( & V_5 -> V_138 ,
V_87 + F_61 ( V_342 ) ) ;
} else {
F_214 ( & V_5 -> V_42 , V_35 ) ;
F_31 ( & V_5 -> V_43 ) ;
}
}
}
