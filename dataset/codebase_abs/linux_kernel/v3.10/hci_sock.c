static inline int F_1 ( int V_1 , void * V_2 )
{
return * ( ( V_3 * ) V_2 + ( V_1 >> 5 ) ) & ( ( V_3 ) 1 << ( V_1 & 31 ) ) ;
}
void F_2 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
struct V_8 * V_9 ;
struct V_6 * V_10 = NULL ;
F_3 ( L_1 , V_5 , V_7 -> V_11 ) ;
F_4 ( & V_12 . V_13 ) ;
F_5 (sk, &hci_sk_list.head) {
struct V_14 * V_15 ;
struct V_6 * V_16 ;
if ( V_9 -> V_17 != V_18 || F_6 ( V_9 ) -> V_5 != V_5 )
continue;
if ( V_7 -> V_9 == V_9 )
continue;
if ( F_6 ( V_9 ) -> V_19 != V_20 )
continue;
V_15 = & F_6 ( V_9 ) -> V_21 ;
if ( ! F_7 ( ( F_8 ( V_7 ) -> V_22 == V_23 ) ?
0 : ( F_8 ( V_7 ) -> V_22 & V_24 ) ,
& V_15 -> V_25 ) )
continue;
if ( F_8 ( V_7 ) -> V_22 == V_26 ) {
int V_27 = ( * ( V_28 * ) V_7 -> V_29 & V_30 ) ;
if ( ! F_1 ( V_27 , & V_15 -> V_31 ) )
continue;
if ( V_15 -> V_32 &&
( ( V_27 == V_33 &&
V_15 -> V_32 !=
F_9 ( ( V_34 * ) ( V_7 -> V_29 + 3 ) ) ) ||
( V_27 == V_35 &&
V_15 -> V_32 !=
F_9 ( ( V_34 * ) ( V_7 -> V_29 + 4 ) ) ) ) )
continue;
}
if ( ! V_10 ) {
V_10 = F_10 ( V_7 , 1 , V_36 ) ;
if ( ! V_10 )
continue;
memcpy ( F_11 ( V_10 , 1 ) , & F_8 ( V_7 ) -> V_22 , 1 ) ;
}
V_16 = F_12 ( V_10 , V_36 ) ;
if ( ! V_16 )
continue;
if ( F_13 ( V_9 , V_16 ) )
F_14 ( V_16 ) ;
}
F_15 ( & V_12 . V_13 ) ;
F_14 ( V_10 ) ;
}
void F_16 ( struct V_6 * V_7 , struct V_8 * V_37 )
{
struct V_8 * V_9 ;
F_3 ( L_2 , V_7 -> V_11 ) ;
F_4 ( & V_12 . V_13 ) ;
F_5 (sk, &hci_sk_list.head) {
struct V_6 * V_16 ;
if ( V_9 == V_37 )
continue;
if ( V_9 -> V_17 != V_18 )
continue;
if ( F_6 ( V_9 ) -> V_19 != V_38 )
continue;
V_16 = F_12 ( V_7 , V_36 ) ;
if ( ! V_16 )
continue;
if ( F_13 ( V_9 , V_16 ) )
F_14 ( V_16 ) ;
}
F_15 ( & V_12 . V_13 ) ;
}
void F_17 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
struct V_8 * V_9 ;
struct V_6 * V_10 = NULL ;
V_34 V_32 ;
if ( ! F_18 ( & V_39 ) )
return;
F_3 ( L_1 , V_5 , V_7 -> V_11 ) ;
switch ( F_8 ( V_7 ) -> V_22 ) {
case V_40 :
V_32 = F_19 ( V_41 ) ;
break;
case V_26 :
V_32 = F_19 ( V_42 ) ;
break;
case V_43 :
if ( F_8 ( V_7 ) -> V_44 )
V_32 = F_19 ( V_45 ) ;
else
V_32 = F_19 ( V_46 ) ;
break;
case V_47 :
if ( F_8 ( V_7 ) -> V_44 )
V_32 = F_19 ( V_48 ) ;
else
V_32 = F_19 ( V_49 ) ;
break;
default:
return;
}
F_4 ( & V_12 . V_13 ) ;
F_5 (sk, &hci_sk_list.head) {
struct V_6 * V_16 ;
if ( V_9 -> V_17 != V_18 )
continue;
if ( F_6 ( V_9 ) -> V_19 != V_50 )
continue;
if ( ! V_10 ) {
struct V_51 * V_52 ;
V_10 = F_10 ( V_7 , V_53 ,
V_36 ) ;
if ( ! V_10 )
continue;
V_52 = ( void * ) F_11 ( V_10 , V_53 ) ;
V_52 -> V_32 = V_32 ;
V_52 -> V_54 = F_20 ( V_5 -> V_55 ) ;
V_52 -> V_11 = F_20 ( V_7 -> V_11 ) ;
}
V_16 = F_12 ( V_10 , V_36 ) ;
if ( ! V_16 )
continue;
if ( F_13 ( V_9 , V_16 ) )
F_14 ( V_16 ) ;
}
F_15 ( & V_12 . V_13 ) ;
F_14 ( V_10 ) ;
}
static void F_21 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
F_3 ( L_2 , V_7 -> V_11 ) ;
F_4 ( & V_12 . V_13 ) ;
F_5 (sk, &hci_sk_list.head) {
struct V_6 * V_16 ;
if ( V_9 -> V_17 != V_18 )
continue;
if ( F_6 ( V_9 ) -> V_19 != V_50 )
continue;
V_16 = F_12 ( V_7 , V_36 ) ;
if ( ! V_16 )
continue;
if ( F_13 ( V_9 , V_16 ) )
F_14 ( V_16 ) ;
}
F_15 ( & V_12 . V_13 ) ;
}
static struct V_6 * F_22 ( struct V_4 * V_5 , int V_56 )
{
struct V_51 * V_52 ;
struct V_57 * V_58 ;
struct V_6 * V_7 ;
V_34 V_32 ;
switch ( V_56 ) {
case V_59 :
V_7 = F_23 ( V_60 , V_36 ) ;
if ( ! V_7 )
return NULL ;
V_58 = ( void * ) F_24 ( V_7 , V_60 ) ;
V_58 -> type = V_5 -> V_61 ;
V_58 -> V_62 = V_5 -> V_62 ;
F_25 ( & V_58 -> V_63 , & V_5 -> V_63 ) ;
memcpy ( V_58 -> V_64 , V_5 -> V_64 , 8 ) ;
V_32 = F_19 ( V_65 ) ;
break;
case V_66 :
V_7 = F_23 ( 0 , V_36 ) ;
if ( ! V_7 )
return NULL ;
V_32 = F_19 ( V_67 ) ;
break;
default:
return NULL ;
}
F_26 ( V_7 ) ;
V_52 = ( void * ) F_11 ( V_7 , V_53 ) ;
V_52 -> V_32 = V_32 ;
V_52 -> V_54 = F_20 ( V_5 -> V_55 ) ;
V_52 -> V_11 = F_20 ( V_7 -> V_11 - V_53 ) ;
return V_7 ;
}
static void F_27 ( struct V_8 * V_9 )
{
struct V_4 * V_5 ;
F_4 ( & V_68 ) ;
F_28 (hdev, &hci_dev_list, list) {
struct V_6 * V_7 ;
V_7 = F_22 ( V_5 , V_59 ) ;
if ( ! V_7 )
continue;
if ( F_13 ( V_9 , V_7 ) )
F_14 ( V_7 ) ;
}
F_15 ( & V_68 ) ;
}
static void F_29 ( struct V_4 * V_5 , int type , int V_69 , void * V_29 )
{
struct V_70 * V_52 ;
struct V_71 * V_72 ;
struct V_6 * V_7 ;
V_7 = F_23 ( V_73 + sizeof( * V_72 ) + V_69 , V_36 ) ;
if ( ! V_7 )
return;
V_52 = ( void * ) F_24 ( V_7 , V_73 ) ;
V_52 -> V_27 = V_74 ;
V_52 -> V_75 = sizeof( * V_72 ) + V_69 ;
V_72 = ( void * ) F_24 ( V_7 , sizeof( * V_72 ) + V_69 ) ;
V_72 -> type = type ;
memcpy ( V_72 -> V_29 , V_29 , V_69 ) ;
F_8 ( V_7 ) -> V_44 = 1 ;
F_26 ( V_7 ) ;
F_8 ( V_7 ) -> V_22 = V_26 ;
V_7 -> V_76 = ( void * ) V_5 ;
F_2 ( V_5 , V_7 ) ;
F_14 ( V_7 ) ;
}
void F_30 ( struct V_4 * V_5 , int V_56 )
{
struct V_77 V_72 ;
F_3 ( L_3 , V_5 -> V_64 , V_56 ) ;
if ( F_18 ( & V_39 ) ) {
struct V_6 * V_7 ;
V_7 = F_22 ( V_5 , V_56 ) ;
if ( V_7 ) {
F_21 ( V_7 ) ;
F_14 ( V_7 ) ;
}
}
V_72 . V_56 = V_56 ;
V_72 . V_78 = V_5 -> V_55 ;
F_29 ( NULL , V_79 , sizeof( V_72 ) , & V_72 ) ;
if ( V_56 == V_66 ) {
struct V_8 * V_9 ;
F_4 ( & V_12 . V_13 ) ;
F_5 (sk, &hci_sk_list.head) {
F_31 ( V_9 ) ;
if ( F_6 ( V_9 ) -> V_5 == V_5 ) {
F_6 ( V_9 ) -> V_5 = NULL ;
V_9 -> V_80 = V_81 ;
V_9 -> V_17 = V_82 ;
V_9 -> V_83 ( V_9 ) ;
F_32 ( V_5 ) ;
}
F_33 ( V_9 ) ;
}
F_15 ( & V_12 . V_13 ) ;
}
}
static int F_34 ( struct V_84 * V_8 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_4 * V_5 ;
F_3 ( L_4 , V_8 , V_9 ) ;
if ( ! V_9 )
return 0 ;
V_5 = F_6 ( V_9 ) -> V_5 ;
if ( F_6 ( V_9 ) -> V_19 == V_50 )
F_35 ( & V_39 ) ;
F_36 ( & V_12 , V_9 ) ;
if ( V_5 ) {
F_35 ( & V_5 -> V_85 ) ;
F_32 ( V_5 ) ;
}
F_37 ( V_9 ) ;
F_38 ( & V_9 -> V_86 ) ;
F_38 ( & V_9 -> V_87 ) ;
F_39 ( V_9 ) ;
return 0 ;
}
static int F_40 ( struct V_4 * V_5 , void T_1 * V_88 )
{
T_2 V_63 ;
int V_89 ;
if ( F_41 ( & V_63 , V_88 , sizeof( V_63 ) ) )
return - V_90 ;
F_42 ( V_5 ) ;
V_89 = F_43 ( V_5 , & V_63 , 0 ) ;
F_44 ( V_5 ) ;
return V_89 ;
}
static int F_45 ( struct V_4 * V_5 , void T_1 * V_88 )
{
T_2 V_63 ;
int V_89 ;
if ( F_41 ( & V_63 , V_88 , sizeof( V_63 ) ) )
return - V_90 ;
F_42 ( V_5 ) ;
V_89 = F_46 ( V_5 , & V_63 , 0 ) ;
F_44 ( V_5 ) ;
return V_89 ;
}
static int F_47 ( struct V_8 * V_9 , unsigned int V_91 ,
unsigned long V_88 )
{
struct V_4 * V_5 = F_6 ( V_9 ) -> V_5 ;
if ( ! V_5 )
return - V_92 ;
switch ( V_91 ) {
case V_93 :
if ( ! F_48 ( V_94 ) )
return - V_95 ;
if ( F_7 ( V_96 , & V_5 -> V_97 ) )
return - V_95 ;
if ( V_88 )
F_49 ( V_98 , & V_5 -> V_99 ) ;
else
F_50 ( V_98 , & V_5 -> V_99 ) ;
return 0 ;
case V_100 :
return F_51 ( V_5 , ( void T_1 * ) V_88 ) ;
case V_101 :
return F_52 ( V_5 , ( void T_1 * ) V_88 ) ;
case V_102 :
if ( ! F_48 ( V_94 ) )
return - V_95 ;
return F_40 ( V_5 , ( void T_1 * ) V_88 ) ;
case V_103 :
if ( ! F_48 ( V_94 ) )
return - V_95 ;
return F_45 ( V_5 , ( void T_1 * ) V_88 ) ;
default:
if ( V_5 -> V_104 )
return V_5 -> V_104 ( V_5 , V_91 , V_88 ) ;
return - V_105 ;
}
}
static int F_53 ( struct V_84 * V_8 , unsigned int V_91 ,
unsigned long V_88 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
void T_1 * V_106 = ( void T_1 * ) V_88 ;
int V_89 ;
F_3 ( L_5 , V_91 , V_88 ) ;
switch ( V_91 ) {
case V_107 :
return F_54 ( V_106 ) ;
case V_108 :
return F_55 ( V_106 ) ;
case V_109 :
return F_56 ( V_106 ) ;
case V_110 :
if ( ! F_48 ( V_94 ) )
return - V_95 ;
return F_57 ( V_88 ) ;
case V_111 :
if ( ! F_48 ( V_94 ) )
return - V_95 ;
return F_58 ( V_88 ) ;
case V_112 :
if ( ! F_48 ( V_94 ) )
return - V_95 ;
return F_59 ( V_88 ) ;
case V_113 :
if ( ! F_48 ( V_94 ) )
return - V_95 ;
return F_60 ( V_88 ) ;
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
if ( ! F_48 ( V_94 ) )
return - V_95 ;
return F_61 ( V_91 , V_106 ) ;
case V_122 :
return F_62 ( V_106 ) ;
default:
F_63 ( V_9 ) ;
V_89 = F_47 ( V_9 , V_91 , V_88 ) ;
F_64 ( V_9 ) ;
return V_89 ;
}
}
static int F_65 ( struct V_84 * V_8 , struct V_123 * V_2 ,
int V_124 )
{
struct V_125 V_126 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_4 * V_5 = NULL ;
int V_11 , V_89 = 0 ;
F_3 ( L_4 , V_8 , V_9 ) ;
if ( ! V_2 )
return - V_105 ;
memset ( & V_126 , 0 , sizeof( V_126 ) ) ;
V_11 = F_66 (unsigned int, sizeof(haddr), addr_len) ;
memcpy ( & V_126 , V_2 , V_11 ) ;
if ( V_126 . V_127 != V_128 )
return - V_105 ;
F_63 ( V_9 ) ;
if ( V_9 -> V_17 == V_18 ) {
V_89 = - V_129 ;
goto V_130;
}
switch ( V_126 . V_131 ) {
case V_20 :
if ( F_6 ( V_9 ) -> V_5 ) {
V_89 = - V_129 ;
goto V_130;
}
if ( V_126 . V_4 != V_132 ) {
V_5 = F_67 ( V_126 . V_4 ) ;
if ( ! V_5 ) {
V_89 = - V_133 ;
goto V_130;
}
F_68 ( & V_5 -> V_85 ) ;
}
F_6 ( V_9 ) -> V_5 = V_5 ;
break;
case V_38 :
if ( V_126 . V_4 != V_132 ) {
V_89 = - V_105 ;
goto V_130;
}
if ( ! F_48 ( V_94 ) ) {
V_89 = - V_95 ;
goto V_130;
}
break;
case V_50 :
if ( V_126 . V_4 != V_132 ) {
V_89 = - V_105 ;
goto V_130;
}
if ( ! F_48 ( V_134 ) ) {
V_89 = - V_95 ;
goto V_130;
}
F_27 ( V_9 ) ;
F_68 ( & V_39 ) ;
break;
default:
V_89 = - V_105 ;
goto V_130;
}
F_6 ( V_9 ) -> V_19 = V_126 . V_131 ;
V_9 -> V_17 = V_18 ;
V_130:
F_64 ( V_9 ) ;
return V_89 ;
}
static int F_69 ( struct V_84 * V_8 , struct V_123 * V_2 ,
int * V_124 , int V_135 )
{
struct V_125 * V_126 = (struct V_125 * ) V_2 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_4 * V_5 = F_6 ( V_9 ) -> V_5 ;
F_3 ( L_4 , V_8 , V_9 ) ;
if ( ! V_5 )
return - V_92 ;
F_63 ( V_9 ) ;
* V_124 = sizeof( * V_126 ) ;
V_126 -> V_127 = V_128 ;
V_126 -> V_4 = V_5 -> V_55 ;
V_126 -> V_131 = 0 ;
F_64 ( V_9 ) ;
return 0 ;
}
static void F_70 ( struct V_8 * V_9 , struct V_136 * V_137 ,
struct V_6 * V_7 )
{
V_3 V_138 = F_6 ( V_9 ) -> V_139 ;
if ( V_138 & V_140 ) {
int V_44 = F_8 ( V_7 ) -> V_44 ;
F_71 ( V_137 , V_141 , V_140 , sizeof( V_44 ) ,
& V_44 ) ;
}
if ( V_138 & V_142 ) {
#ifdef F_72
struct V_143 V_144 ;
#endif
struct V_145 V_146 ;
void * V_29 ;
int V_11 ;
F_73 ( V_7 , & V_146 ) ;
V_29 = & V_146 ;
V_11 = sizeof( V_146 ) ;
#ifdef F_72
if ( ! V_147 &&
( V_137 -> V_148 & V_149 ) ) {
V_144 . V_150 = V_146 . V_150 ;
V_144 . V_151 = V_146 . V_151 ;
V_29 = & V_144 ;
V_11 = sizeof( V_144 ) ;
}
#endif
F_71 ( V_137 , V_141 , V_142 , V_11 , V_29 ) ;
}
}
static int F_74 ( struct V_152 * V_153 , struct V_84 * V_8 ,
struct V_136 * V_137 , T_3 V_11 , int V_99 )
{
int V_154 = V_99 & V_155 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 ;
int V_156 , V_89 ;
F_3 ( L_6 , V_8 , V_9 ) ;
if ( V_99 & ( V_157 ) )
return - V_158 ;
if ( V_9 -> V_17 == V_159 )
return 0 ;
V_7 = F_75 ( V_9 , V_99 , V_154 , & V_89 ) ;
if ( ! V_7 )
return V_89 ;
V_137 -> V_160 = 0 ;
V_156 = V_7 -> V_11 ;
if ( V_11 < V_156 ) {
V_137 -> V_148 |= V_161 ;
V_156 = V_11 ;
}
F_76 ( V_7 ) ;
V_89 = F_77 ( V_7 , 0 , V_137 -> V_162 , V_156 ) ;
switch ( F_6 ( V_9 ) -> V_19 ) {
case V_20 :
F_70 ( V_9 , V_137 , V_7 ) ;
break;
case V_38 :
case V_50 :
F_78 ( V_137 , V_9 , V_7 ) ;
break;
}
F_79 ( V_9 , V_7 ) ;
return V_89 ? : V_156 ;
}
static int F_80 ( struct V_152 * V_153 , struct V_84 * V_8 ,
struct V_136 * V_137 , T_3 V_11 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_89 ;
F_3 ( L_4 , V_8 , V_9 ) ;
if ( V_137 -> V_148 & V_157 )
return - V_158 ;
if ( V_137 -> V_148 & ~ ( V_155 | V_163 | V_164 ) )
return - V_105 ;
if ( V_11 < 4 || V_11 > V_165 )
return - V_105 ;
F_63 ( V_9 ) ;
switch ( F_6 ( V_9 ) -> V_19 ) {
case V_20 :
break;
case V_38 :
V_89 = F_81 ( V_9 , V_137 , V_11 ) ;
goto V_130;
case V_50 :
V_89 = - V_158 ;
goto V_130;
default:
V_89 = - V_105 ;
goto V_130;
}
V_5 = F_6 ( V_9 ) -> V_5 ;
if ( ! V_5 ) {
V_89 = - V_92 ;
goto V_130;
}
if ( ! F_7 ( V_166 , & V_5 -> V_99 ) ) {
V_89 = - V_167 ;
goto V_130;
}
V_7 = F_82 ( V_9 , V_11 , V_137 -> V_148 & V_155 , & V_89 ) ;
if ( ! V_7 )
goto V_130;
if ( F_83 ( F_24 ( V_7 , V_11 ) , V_137 -> V_162 , V_11 ) ) {
V_89 = - V_90 ;
goto V_168;
}
F_8 ( V_7 ) -> V_22 = * ( ( unsigned char * ) V_7 -> V_29 ) ;
F_84 ( V_7 , 1 ) ;
V_7 -> V_76 = ( void * ) V_5 ;
if ( F_8 ( V_7 ) -> V_22 == V_40 ) {
T_4 V_32 = F_85 ( V_7 -> V_29 ) ;
T_4 V_169 = F_86 ( V_32 ) ;
T_4 V_170 = F_87 ( V_32 ) ;
if ( ( ( V_169 > V_171 ) ||
! F_1 ( V_170 & V_172 ,
& V_173 . V_174 [ V_169 ] ) ) &&
! F_48 ( V_134 ) ) {
V_89 = - V_95 ;
goto V_168;
}
if ( F_7 ( V_98 , & V_5 -> V_99 ) || ( V_169 == 0x3f ) ) {
F_88 ( & V_5 -> V_175 , V_7 ) ;
F_89 ( V_5 -> V_176 , & V_5 -> V_177 ) ;
} else {
F_8 ( V_7 ) -> V_178 . V_179 = true ;
F_88 ( & V_5 -> V_180 , V_7 ) ;
F_89 ( V_5 -> V_176 , & V_5 -> V_181 ) ;
}
} else {
if ( ! F_48 ( V_134 ) ) {
V_89 = - V_95 ;
goto V_168;
}
F_88 ( & V_5 -> V_175 , V_7 ) ;
F_89 ( V_5 -> V_176 , & V_5 -> V_177 ) ;
}
V_89 = V_11 ;
V_130:
F_64 ( V_9 ) ;
return V_89 ;
V_168:
F_14 ( V_7 ) ;
goto V_130;
}
static int F_90 ( struct V_84 * V_8 , int V_182 , int V_183 ,
char T_1 * V_184 , unsigned int V_11 )
{
struct V_185 V_186 = { . V_32 = 0 } ;
struct V_8 * V_9 = V_8 -> V_9 ;
int V_89 = 0 , V_187 = 0 ;
F_3 ( L_7 , V_9 , V_183 ) ;
F_63 ( V_9 ) ;
if ( F_6 ( V_9 ) -> V_19 != V_20 ) {
V_89 = - V_105 ;
goto V_130;
}
switch ( V_183 ) {
case V_188 :
if ( F_91 ( V_187 , ( int T_1 * ) V_184 ) ) {
V_89 = - V_90 ;
break;
}
if ( V_187 )
F_6 ( V_9 ) -> V_139 |= V_140 ;
else
F_6 ( V_9 ) -> V_139 &= ~ V_140 ;
break;
case V_189 :
if ( F_91 ( V_187 , ( int T_1 * ) V_184 ) ) {
V_89 = - V_90 ;
break;
}
if ( V_187 )
F_6 ( V_9 ) -> V_139 |= V_142 ;
else
F_6 ( V_9 ) -> V_139 &= ~ V_142 ;
break;
case V_190 :
{
struct V_14 * V_191 = & F_6 ( V_9 ) -> V_21 ;
V_186 . V_25 = V_191 -> V_25 ;
V_186 . V_32 = V_191 -> V_32 ;
V_186 . V_31 [ 0 ] = * ( ( V_192 * ) V_191 -> V_31 + 0 ) ;
V_186 . V_31 [ 1 ] = * ( ( V_192 * ) V_191 -> V_31 + 1 ) ;
}
V_11 = F_66 (unsigned int, len, sizeof(uf)) ;
if ( F_41 ( & V_186 , V_184 , V_11 ) ) {
V_89 = - V_90 ;
break;
}
if ( ! F_48 ( V_134 ) ) {
V_186 . V_25 &= V_173 . V_25 ;
V_186 . V_31 [ 0 ] &= * ( ( V_192 * ) V_173 . V_31 + 0 ) ;
V_186 . V_31 [ 1 ] &= * ( ( V_192 * ) V_173 . V_31 + 1 ) ;
}
{
struct V_14 * V_191 = & F_6 ( V_9 ) -> V_21 ;
V_191 -> V_25 = V_186 . V_25 ;
V_191 -> V_32 = V_186 . V_32 ;
* ( ( V_192 * ) V_191 -> V_31 + 0 ) = V_186 . V_31 [ 0 ] ;
* ( ( V_192 * ) V_191 -> V_31 + 1 ) = V_186 . V_31 [ 1 ] ;
}
break;
default:
V_89 = - V_193 ;
break;
}
V_130:
F_64 ( V_9 ) ;
return V_89 ;
}
static int F_92 ( struct V_84 * V_8 , int V_182 , int V_183 ,
char T_1 * V_184 , int T_1 * V_194 )
{
struct V_185 V_186 ;
struct V_8 * V_9 = V_8 -> V_9 ;
int V_11 , V_187 , V_89 = 0 ;
F_3 ( L_7 , V_9 , V_183 ) ;
if ( F_91 ( V_11 , V_194 ) )
return - V_90 ;
F_63 ( V_9 ) ;
if ( F_6 ( V_9 ) -> V_19 != V_20 ) {
V_89 = - V_105 ;
goto V_130;
}
switch ( V_183 ) {
case V_188 :
if ( F_6 ( V_9 ) -> V_139 & V_140 )
V_187 = 1 ;
else
V_187 = 0 ;
if ( F_93 ( V_187 , V_184 ) )
V_89 = - V_90 ;
break;
case V_189 :
if ( F_6 ( V_9 ) -> V_139 & V_142 )
V_187 = 1 ;
else
V_187 = 0 ;
if ( F_93 ( V_187 , V_184 ) )
V_89 = - V_90 ;
break;
case V_190 :
{
struct V_14 * V_191 = & F_6 ( V_9 ) -> V_21 ;
memset ( & V_186 , 0 , sizeof( V_186 ) ) ;
V_186 . V_25 = V_191 -> V_25 ;
V_186 . V_32 = V_191 -> V_32 ;
V_186 . V_31 [ 0 ] = * ( ( V_192 * ) V_191 -> V_31 + 0 ) ;
V_186 . V_31 [ 1 ] = * ( ( V_192 * ) V_191 -> V_31 + 1 ) ;
}
V_11 = F_66 (unsigned int, len, sizeof(uf)) ;
if ( F_94 ( V_184 , & V_186 , V_11 ) )
V_89 = - V_90 ;
break;
default:
V_89 = - V_193 ;
break;
}
V_130:
F_64 ( V_9 ) ;
return V_89 ;
}
static int F_95 ( struct V_195 * V_195 , struct V_84 * V_8 , int V_196 ,
int V_197 )
{
struct V_8 * V_9 ;
F_3 ( L_8 , V_8 ) ;
if ( V_8 -> type != V_198 )
return - V_199 ;
V_8 -> V_200 = & V_201 ;
V_9 = F_96 ( V_195 , V_202 , V_36 , & V_203 ) ;
if ( ! V_9 )
return - V_204 ;
F_97 ( V_8 , V_9 ) ;
F_98 ( V_9 , V_205 ) ;
V_9 -> V_206 = V_196 ;
V_8 -> V_207 = V_208 ;
V_9 -> V_17 = V_82 ;
F_99 ( & V_12 , V_9 ) ;
return 0 ;
}
int T_5 F_100 ( void )
{
int V_89 ;
V_89 = F_101 ( & V_203 , 0 ) ;
if ( V_89 < 0 )
return V_89 ;
V_89 = F_102 ( V_209 , & V_210 ) ;
if ( V_89 < 0 ) {
F_103 ( L_9 ) ;
goto error;
}
V_89 = F_104 ( & V_211 , L_10 , & V_12 , NULL ) ;
if ( V_89 < 0 ) {
F_103 ( L_11 ) ;
F_105 ( V_209 ) ;
goto error;
}
F_106 ( L_12 ) ;
return 0 ;
error:
F_107 ( & V_203 ) ;
return V_89 ;
}
void F_108 ( void )
{
F_109 ( & V_211 , L_10 ) ;
F_105 ( V_209 ) ;
F_107 ( & V_203 ) ;
}
