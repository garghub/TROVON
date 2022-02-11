static inline int F_1 ( int V_1 , void * V_2 )
{
return * ( ( V_3 * ) V_2 + ( V_1 >> 5 ) ) & ( ( V_3 ) 1 << ( V_1 & 31 ) ) ;
}
void F_2 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
struct V_6 * V_12 = NULL ;
F_3 ( L_1 , V_5 , V_7 -> V_13 ) ;
F_4 ( & V_14 . V_15 ) ;
F_5 (sk, node, &hci_sk_list.head) {
struct V_16 * V_17 ;
struct V_6 * V_18 ;
if ( V_9 -> V_19 != V_20 || F_6 ( V_9 ) -> V_5 != V_5 )
continue;
if ( V_7 -> V_9 == V_9 )
continue;
if ( F_6 ( V_9 ) -> V_21 != V_22 )
continue;
V_17 = & F_6 ( V_9 ) -> V_23 ;
if ( ! F_7 ( ( F_8 ( V_7 ) -> V_24 == V_25 ) ?
0 : ( F_8 ( V_7 ) -> V_24 & V_26 ) ,
& V_17 -> V_27 ) )
continue;
if ( F_8 ( V_7 ) -> V_24 == V_28 ) {
int V_29 = ( * ( V_30 * ) V_7 -> V_31 & V_32 ) ;
if ( ! F_1 ( V_29 , & V_17 -> V_33 ) )
continue;
if ( V_17 -> V_34 &&
( ( V_29 == V_35 &&
V_17 -> V_34 !=
F_9 ( ( V_36 * ) ( V_7 -> V_31 + 3 ) ) ) ||
( V_29 == V_37 &&
V_17 -> V_34 !=
F_9 ( ( V_36 * ) ( V_7 -> V_31 + 4 ) ) ) ) )
continue;
}
if ( ! V_12 ) {
V_12 = F_10 ( V_7 , 1 , V_38 ) ;
if ( ! V_12 )
continue;
memcpy ( F_11 ( V_12 , 1 ) , & F_8 ( V_7 ) -> V_24 , 1 ) ;
}
V_18 = F_12 ( V_12 , V_38 ) ;
if ( ! V_18 )
continue;
if ( F_13 ( V_9 , V_18 ) )
F_14 ( V_18 ) ;
}
F_15 ( & V_14 . V_15 ) ;
F_14 ( V_12 ) ;
}
void F_16 ( struct V_6 * V_7 , struct V_8 * V_39 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
F_3 ( L_2 , V_7 -> V_13 ) ;
F_4 ( & V_14 . V_15 ) ;
F_5 (sk, node, &hci_sk_list.head) {
struct V_6 * V_18 ;
if ( V_9 == V_39 )
continue;
if ( V_9 -> V_19 != V_20 )
continue;
if ( F_6 ( V_9 ) -> V_21 != V_40 )
continue;
V_18 = F_12 ( V_7 , V_38 ) ;
if ( ! V_18 )
continue;
if ( F_13 ( V_9 , V_18 ) )
F_14 ( V_18 ) ;
}
F_15 ( & V_14 . V_15 ) ;
}
void F_17 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
struct V_6 * V_12 = NULL ;
V_36 V_34 ;
if ( ! F_18 ( & V_41 ) )
return;
F_3 ( L_1 , V_5 , V_7 -> V_13 ) ;
switch ( F_8 ( V_7 ) -> V_24 ) {
case V_42 :
V_34 = F_19 ( V_43 ) ;
break;
case V_28 :
V_34 = F_19 ( V_44 ) ;
break;
case V_45 :
if ( F_8 ( V_7 ) -> V_46 )
V_34 = F_19 ( V_47 ) ;
else
V_34 = F_19 ( V_48 ) ;
break;
case V_49 :
if ( F_8 ( V_7 ) -> V_46 )
V_34 = F_19 ( V_50 ) ;
else
V_34 = F_19 ( V_51 ) ;
break;
default:
return;
}
F_4 ( & V_14 . V_15 ) ;
F_5 (sk, node, &hci_sk_list.head) {
struct V_6 * V_18 ;
if ( V_9 -> V_19 != V_20 )
continue;
if ( F_6 ( V_9 ) -> V_21 != V_52 )
continue;
if ( ! V_12 ) {
struct V_53 * V_54 ;
V_12 = F_10 ( V_7 , V_55 ,
V_38 ) ;
if ( ! V_12 )
continue;
V_54 = ( void * ) F_11 ( V_12 , V_55 ) ;
V_54 -> V_34 = V_34 ;
V_54 -> V_56 = F_20 ( V_5 -> V_57 ) ;
V_54 -> V_13 = F_20 ( V_7 -> V_13 ) ;
}
V_18 = F_12 ( V_12 , V_38 ) ;
if ( ! V_18 )
continue;
if ( F_13 ( V_9 , V_18 ) )
F_14 ( V_18 ) ;
}
F_15 ( & V_14 . V_15 ) ;
F_14 ( V_12 ) ;
}
static void F_21 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
F_3 ( L_2 , V_7 -> V_13 ) ;
F_4 ( & V_14 . V_15 ) ;
F_5 (sk, node, &hci_sk_list.head) {
struct V_6 * V_18 ;
if ( V_9 -> V_19 != V_20 )
continue;
if ( F_6 ( V_9 ) -> V_21 != V_52 )
continue;
V_18 = F_12 ( V_7 , V_38 ) ;
if ( ! V_18 )
continue;
if ( F_13 ( V_9 , V_18 ) )
F_14 ( V_18 ) ;
}
F_15 ( & V_14 . V_15 ) ;
}
static struct V_6 * F_22 ( struct V_4 * V_5 , int V_58 )
{
struct V_53 * V_54 ;
struct V_59 * V_60 ;
struct V_6 * V_7 ;
V_36 V_34 ;
switch ( V_58 ) {
case V_61 :
V_7 = F_23 ( V_62 , V_38 ) ;
if ( ! V_7 )
return NULL ;
V_60 = ( void * ) F_24 ( V_7 , V_62 ) ;
V_60 -> type = V_5 -> V_63 ;
V_60 -> V_64 = V_5 -> V_64 ;
F_25 ( & V_60 -> V_65 , & V_5 -> V_65 ) ;
memcpy ( V_60 -> V_66 , V_5 -> V_66 , 8 ) ;
V_34 = F_19 ( V_67 ) ;
break;
case V_68 :
V_7 = F_23 ( 0 , V_38 ) ;
if ( ! V_7 )
return NULL ;
V_34 = F_19 ( V_69 ) ;
break;
default:
return NULL ;
}
F_26 ( V_7 ) ;
V_54 = ( void * ) F_11 ( V_7 , V_55 ) ;
V_54 -> V_34 = V_34 ;
V_54 -> V_56 = F_20 ( V_5 -> V_57 ) ;
V_54 -> V_13 = F_20 ( V_7 -> V_13 - V_55 ) ;
return V_7 ;
}
static void F_27 ( struct V_8 * V_9 )
{
struct V_4 * V_5 ;
F_4 ( & V_70 ) ;
F_28 (hdev, &hci_dev_list, list) {
struct V_6 * V_7 ;
V_7 = F_22 ( V_5 , V_61 ) ;
if ( ! V_7 )
continue;
if ( F_13 ( V_9 , V_7 ) )
F_14 ( V_7 ) ;
}
F_15 ( & V_70 ) ;
}
static void F_29 ( struct V_4 * V_5 , int type , int V_71 , void * V_31 )
{
struct V_72 * V_54 ;
struct V_73 * V_74 ;
struct V_6 * V_7 ;
V_7 = F_23 ( V_75 + sizeof( * V_74 ) + V_71 , V_38 ) ;
if ( ! V_7 )
return;
V_54 = ( void * ) F_24 ( V_7 , V_75 ) ;
V_54 -> V_29 = V_76 ;
V_54 -> V_77 = sizeof( * V_74 ) + V_71 ;
V_74 = ( void * ) F_24 ( V_7 , sizeof( * V_74 ) + V_71 ) ;
V_74 -> type = type ;
memcpy ( V_74 -> V_31 , V_31 , V_71 ) ;
F_8 ( V_7 ) -> V_46 = 1 ;
F_26 ( V_7 ) ;
F_8 ( V_7 ) -> V_24 = V_28 ;
V_7 -> V_78 = ( void * ) V_5 ;
F_2 ( V_5 , V_7 ) ;
F_14 ( V_7 ) ;
}
void F_30 ( struct V_4 * V_5 , int V_58 )
{
struct V_79 V_74 ;
F_3 ( L_3 , V_5 -> V_66 , V_58 ) ;
if ( F_18 ( & V_41 ) ) {
struct V_6 * V_7 ;
V_7 = F_22 ( V_5 , V_58 ) ;
if ( V_7 ) {
F_21 ( V_7 ) ;
F_14 ( V_7 ) ;
}
}
V_74 . V_58 = V_58 ;
V_74 . V_80 = V_5 -> V_57 ;
F_29 ( NULL , V_81 , sizeof( V_74 ) , & V_74 ) ;
if ( V_58 == V_68 ) {
struct V_8 * V_9 ;
struct V_10 * V_11 ;
F_4 ( & V_14 . V_15 ) ;
F_5 (sk, node, &hci_sk_list.head) {
F_31 ( V_9 ) ;
if ( F_6 ( V_9 ) -> V_5 == V_5 ) {
F_6 ( V_9 ) -> V_5 = NULL ;
V_9 -> V_82 = V_83 ;
V_9 -> V_19 = V_84 ;
V_9 -> V_85 ( V_9 ) ;
F_32 ( V_5 ) ;
}
F_33 ( V_9 ) ;
}
F_15 ( & V_14 . V_15 ) ;
}
}
static int F_34 ( struct V_86 * V_8 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_4 * V_5 ;
F_3 ( L_4 , V_8 , V_9 ) ;
if ( ! V_9 )
return 0 ;
V_5 = F_6 ( V_9 ) -> V_5 ;
if ( F_6 ( V_9 ) -> V_21 == V_52 )
F_35 ( & V_41 ) ;
F_36 ( & V_14 , V_9 ) ;
if ( V_5 ) {
F_35 ( & V_5 -> V_87 ) ;
F_32 ( V_5 ) ;
}
F_37 ( V_9 ) ;
F_38 ( & V_9 -> V_88 ) ;
F_38 ( & V_9 -> V_89 ) ;
F_39 ( V_9 ) ;
return 0 ;
}
static int F_40 ( struct V_4 * V_5 , void T_1 * V_90 )
{
T_2 V_65 ;
int V_91 ;
if ( F_41 ( & V_65 , V_90 , sizeof( V_65 ) ) )
return - V_92 ;
F_42 ( V_5 ) ;
V_91 = F_43 ( V_5 , & V_65 , 0 ) ;
F_44 ( V_5 ) ;
return V_91 ;
}
static int F_45 ( struct V_4 * V_5 , void T_1 * V_90 )
{
T_2 V_65 ;
int V_91 ;
if ( F_41 ( & V_65 , V_90 , sizeof( V_65 ) ) )
return - V_92 ;
F_42 ( V_5 ) ;
V_91 = F_46 ( V_5 , & V_65 , 0 ) ;
F_44 ( V_5 ) ;
return V_91 ;
}
static int F_47 ( struct V_8 * V_9 , unsigned int V_93 ,
unsigned long V_90 )
{
struct V_4 * V_5 = F_6 ( V_9 ) -> V_5 ;
if ( ! V_5 )
return - V_94 ;
switch ( V_93 ) {
case V_95 :
if ( ! F_48 ( V_96 ) )
return - V_97 ;
if ( F_7 ( V_98 , & V_5 -> V_99 ) )
return - V_97 ;
if ( V_90 )
F_49 ( V_100 , & V_5 -> V_101 ) ;
else
F_50 ( V_100 , & V_5 -> V_101 ) ;
return 0 ;
case V_102 :
return F_51 ( V_5 , ( void T_1 * ) V_90 ) ;
case V_103 :
return F_52 ( V_5 , ( void T_1 * ) V_90 ) ;
case V_104 :
if ( ! F_48 ( V_96 ) )
return - V_97 ;
return F_40 ( V_5 , ( void T_1 * ) V_90 ) ;
case V_105 :
if ( ! F_48 ( V_96 ) )
return - V_97 ;
return F_45 ( V_5 , ( void T_1 * ) V_90 ) ;
default:
if ( V_5 -> V_106 )
return V_5 -> V_106 ( V_5 , V_93 , V_90 ) ;
return - V_107 ;
}
}
static int F_53 ( struct V_86 * V_8 , unsigned int V_93 ,
unsigned long V_90 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
void T_1 * V_108 = ( void T_1 * ) V_90 ;
int V_91 ;
F_3 ( L_5 , V_93 , V_90 ) ;
switch ( V_93 ) {
case V_109 :
return F_54 ( V_108 ) ;
case V_110 :
return F_55 ( V_108 ) ;
case V_111 :
return F_56 ( V_108 ) ;
case V_112 :
if ( ! F_48 ( V_96 ) )
return - V_97 ;
return F_57 ( V_90 ) ;
case V_113 :
if ( ! F_48 ( V_96 ) )
return - V_97 ;
return F_58 ( V_90 ) ;
case V_114 :
if ( ! F_48 ( V_96 ) )
return - V_97 ;
return F_59 ( V_90 ) ;
case V_115 :
if ( ! F_48 ( V_96 ) )
return - V_97 ;
return F_60 ( V_90 ) ;
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
if ( ! F_48 ( V_96 ) )
return - V_97 ;
return F_61 ( V_93 , V_108 ) ;
case V_124 :
return F_62 ( V_108 ) ;
default:
F_63 ( V_9 ) ;
V_91 = F_47 ( V_9 , V_93 , V_90 ) ;
F_64 ( V_9 ) ;
return V_91 ;
}
}
static int F_65 ( struct V_86 * V_8 , struct V_125 * V_2 ,
int V_126 )
{
struct V_127 V_128 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_4 * V_5 = NULL ;
int V_13 , V_91 = 0 ;
F_3 ( L_4 , V_8 , V_9 ) ;
if ( ! V_2 )
return - V_107 ;
memset ( & V_128 , 0 , sizeof( V_128 ) ) ;
V_13 = F_66 (unsigned int, sizeof(haddr), addr_len) ;
memcpy ( & V_128 , V_2 , V_13 ) ;
if ( V_128 . V_129 != V_130 )
return - V_107 ;
F_63 ( V_9 ) ;
if ( V_9 -> V_19 == V_20 ) {
V_91 = - V_131 ;
goto V_132;
}
switch ( V_128 . V_133 ) {
case V_22 :
if ( F_6 ( V_9 ) -> V_5 ) {
V_91 = - V_131 ;
goto V_132;
}
if ( V_128 . V_4 != V_134 ) {
V_5 = F_67 ( V_128 . V_4 ) ;
if ( ! V_5 ) {
V_91 = - V_135 ;
goto V_132;
}
F_68 ( & V_5 -> V_87 ) ;
}
F_6 ( V_9 ) -> V_5 = V_5 ;
break;
case V_40 :
if ( V_128 . V_4 != V_134 ) {
V_91 = - V_107 ;
goto V_132;
}
if ( ! F_48 ( V_96 ) ) {
V_91 = - V_97 ;
goto V_132;
}
break;
case V_52 :
if ( V_128 . V_4 != V_134 ) {
V_91 = - V_107 ;
goto V_132;
}
if ( ! F_48 ( V_136 ) ) {
V_91 = - V_97 ;
goto V_132;
}
F_27 ( V_9 ) ;
F_68 ( & V_41 ) ;
break;
default:
V_91 = - V_107 ;
goto V_132;
}
F_6 ( V_9 ) -> V_21 = V_128 . V_133 ;
V_9 -> V_19 = V_20 ;
V_132:
F_64 ( V_9 ) ;
return V_91 ;
}
static int F_69 ( struct V_86 * V_8 , struct V_125 * V_2 ,
int * V_126 , int V_137 )
{
struct V_127 * V_128 = (struct V_127 * ) V_2 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_4 * V_5 = F_6 ( V_9 ) -> V_5 ;
F_3 ( L_4 , V_8 , V_9 ) ;
if ( ! V_5 )
return - V_94 ;
F_63 ( V_9 ) ;
* V_126 = sizeof( * V_128 ) ;
V_128 -> V_129 = V_130 ;
V_128 -> V_4 = V_5 -> V_57 ;
V_128 -> V_133 = 0 ;
F_64 ( V_9 ) ;
return 0 ;
}
static void F_70 ( struct V_8 * V_9 , struct V_138 * V_139 ,
struct V_6 * V_7 )
{
V_3 V_140 = F_6 ( V_9 ) -> V_141 ;
if ( V_140 & V_142 ) {
int V_46 = F_8 ( V_7 ) -> V_46 ;
F_71 ( V_139 , V_143 , V_142 , sizeof( V_46 ) ,
& V_46 ) ;
}
if ( V_140 & V_144 ) {
#ifdef F_72
struct V_145 V_146 ;
#endif
struct V_147 V_148 ;
void * V_31 ;
int V_13 ;
F_73 ( V_7 , & V_148 ) ;
V_31 = & V_148 ;
V_13 = sizeof( V_148 ) ;
#ifdef F_72
if ( ! V_149 &&
( V_139 -> V_150 & V_151 ) ) {
V_146 . V_152 = V_148 . V_152 ;
V_146 . V_153 = V_148 . V_153 ;
V_31 = & V_146 ;
V_13 = sizeof( V_146 ) ;
}
#endif
F_71 ( V_139 , V_143 , V_144 , V_13 , V_31 ) ;
}
}
static int F_74 ( struct V_154 * V_155 , struct V_86 * V_8 ,
struct V_138 * V_139 , T_3 V_13 , int V_101 )
{
int V_156 = V_101 & V_157 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 ;
int V_158 , V_91 ;
F_3 ( L_6 , V_8 , V_9 ) ;
if ( V_101 & ( V_159 ) )
return - V_160 ;
if ( V_9 -> V_19 == V_161 )
return 0 ;
V_7 = F_75 ( V_9 , V_101 , V_156 , & V_91 ) ;
if ( ! V_7 )
return V_91 ;
V_139 -> V_162 = 0 ;
V_158 = V_7 -> V_13 ;
if ( V_13 < V_158 ) {
V_139 -> V_150 |= V_163 ;
V_158 = V_13 ;
}
F_76 ( V_7 ) ;
V_91 = F_77 ( V_7 , 0 , V_139 -> V_164 , V_158 ) ;
switch ( F_6 ( V_9 ) -> V_21 ) {
case V_22 :
F_70 ( V_9 , V_139 , V_7 ) ;
break;
case V_40 :
case V_52 :
F_78 ( V_139 , V_9 , V_7 ) ;
break;
}
F_79 ( V_9 , V_7 ) ;
return V_91 ? : V_158 ;
}
static int F_80 ( struct V_154 * V_155 , struct V_86 * V_8 ,
struct V_138 * V_139 , T_3 V_13 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_91 ;
F_3 ( L_4 , V_8 , V_9 ) ;
if ( V_139 -> V_150 & V_159 )
return - V_160 ;
if ( V_139 -> V_150 & ~ ( V_157 | V_165 | V_166 ) )
return - V_107 ;
if ( V_13 < 4 || V_13 > V_167 )
return - V_107 ;
F_63 ( V_9 ) ;
switch ( F_6 ( V_9 ) -> V_21 ) {
case V_22 :
break;
case V_40 :
V_91 = F_81 ( V_9 , V_139 , V_13 ) ;
goto V_132;
case V_52 :
V_91 = - V_160 ;
goto V_132;
default:
V_91 = - V_107 ;
goto V_132;
}
V_5 = F_6 ( V_9 ) -> V_5 ;
if ( ! V_5 ) {
V_91 = - V_94 ;
goto V_132;
}
if ( ! F_7 ( V_168 , & V_5 -> V_101 ) ) {
V_91 = - V_169 ;
goto V_132;
}
V_7 = F_82 ( V_9 , V_13 , V_139 -> V_150 & V_157 , & V_91 ) ;
if ( ! V_7 )
goto V_132;
if ( F_83 ( F_24 ( V_7 , V_13 ) , V_139 -> V_164 , V_13 ) ) {
V_91 = - V_92 ;
goto V_170;
}
F_8 ( V_7 ) -> V_24 = * ( ( unsigned char * ) V_7 -> V_31 ) ;
F_84 ( V_7 , 1 ) ;
V_7 -> V_78 = ( void * ) V_5 ;
if ( F_8 ( V_7 ) -> V_24 == V_42 ) {
T_4 V_34 = F_85 ( V_7 -> V_31 ) ;
T_4 V_171 = F_86 ( V_34 ) ;
T_4 V_172 = F_87 ( V_34 ) ;
if ( ( ( V_171 > V_173 ) ||
! F_1 ( V_172 & V_174 ,
& V_175 . V_176 [ V_171 ] ) ) &&
! F_48 ( V_136 ) ) {
V_91 = - V_97 ;
goto V_170;
}
if ( F_7 ( V_100 , & V_5 -> V_101 ) || ( V_171 == 0x3f ) ) {
F_88 ( & V_5 -> V_177 , V_7 ) ;
F_89 ( V_5 -> V_178 , & V_5 -> V_179 ) ;
} else {
F_88 ( & V_5 -> V_180 , V_7 ) ;
F_89 ( V_5 -> V_178 , & V_5 -> V_181 ) ;
}
} else {
if ( ! F_48 ( V_136 ) ) {
V_91 = - V_97 ;
goto V_170;
}
F_88 ( & V_5 -> V_177 , V_7 ) ;
F_89 ( V_5 -> V_178 , & V_5 -> V_179 ) ;
}
V_91 = V_13 ;
V_132:
F_64 ( V_9 ) ;
return V_91 ;
V_170:
F_14 ( V_7 ) ;
goto V_132;
}
static int F_90 ( struct V_86 * V_8 , int V_182 , int V_183 ,
char T_1 * V_184 , unsigned int V_13 )
{
struct V_185 V_186 = { . V_34 = 0 } ;
struct V_8 * V_9 = V_8 -> V_9 ;
int V_91 = 0 , V_187 = 0 ;
F_3 ( L_7 , V_9 , V_183 ) ;
F_63 ( V_9 ) ;
if ( F_6 ( V_9 ) -> V_21 != V_22 ) {
V_91 = - V_107 ;
goto V_132;
}
switch ( V_183 ) {
case V_188 :
if ( F_91 ( V_187 , ( int T_1 * ) V_184 ) ) {
V_91 = - V_92 ;
break;
}
if ( V_187 )
F_6 ( V_9 ) -> V_141 |= V_142 ;
else
F_6 ( V_9 ) -> V_141 &= ~ V_142 ;
break;
case V_189 :
if ( F_91 ( V_187 , ( int T_1 * ) V_184 ) ) {
V_91 = - V_92 ;
break;
}
if ( V_187 )
F_6 ( V_9 ) -> V_141 |= V_144 ;
else
F_6 ( V_9 ) -> V_141 &= ~ V_144 ;
break;
case V_190 :
{
struct V_16 * V_191 = & F_6 ( V_9 ) -> V_23 ;
V_186 . V_27 = V_191 -> V_27 ;
V_186 . V_34 = V_191 -> V_34 ;
V_186 . V_33 [ 0 ] = * ( ( V_192 * ) V_191 -> V_33 + 0 ) ;
V_186 . V_33 [ 1 ] = * ( ( V_192 * ) V_191 -> V_33 + 1 ) ;
}
V_13 = F_66 (unsigned int, len, sizeof(uf)) ;
if ( F_41 ( & V_186 , V_184 , V_13 ) ) {
V_91 = - V_92 ;
break;
}
if ( ! F_48 ( V_136 ) ) {
V_186 . V_27 &= V_175 . V_27 ;
V_186 . V_33 [ 0 ] &= * ( ( V_192 * ) V_175 . V_33 + 0 ) ;
V_186 . V_33 [ 1 ] &= * ( ( V_192 * ) V_175 . V_33 + 1 ) ;
}
{
struct V_16 * V_191 = & F_6 ( V_9 ) -> V_23 ;
V_191 -> V_27 = V_186 . V_27 ;
V_191 -> V_34 = V_186 . V_34 ;
* ( ( V_192 * ) V_191 -> V_33 + 0 ) = V_186 . V_33 [ 0 ] ;
* ( ( V_192 * ) V_191 -> V_33 + 1 ) = V_186 . V_33 [ 1 ] ;
}
break;
default:
V_91 = - V_193 ;
break;
}
V_132:
F_64 ( V_9 ) ;
return V_91 ;
}
static int F_92 ( struct V_86 * V_8 , int V_182 , int V_183 ,
char T_1 * V_184 , int T_1 * V_194 )
{
struct V_185 V_186 ;
struct V_8 * V_9 = V_8 -> V_9 ;
int V_13 , V_187 , V_91 = 0 ;
F_3 ( L_7 , V_9 , V_183 ) ;
if ( F_91 ( V_13 , V_194 ) )
return - V_92 ;
F_63 ( V_9 ) ;
if ( F_6 ( V_9 ) -> V_21 != V_22 ) {
V_91 = - V_107 ;
goto V_132;
}
switch ( V_183 ) {
case V_188 :
if ( F_6 ( V_9 ) -> V_141 & V_142 )
V_187 = 1 ;
else
V_187 = 0 ;
if ( F_93 ( V_187 , V_184 ) )
V_91 = - V_92 ;
break;
case V_189 :
if ( F_6 ( V_9 ) -> V_141 & V_144 )
V_187 = 1 ;
else
V_187 = 0 ;
if ( F_93 ( V_187 , V_184 ) )
V_91 = - V_92 ;
break;
case V_190 :
{
struct V_16 * V_191 = & F_6 ( V_9 ) -> V_23 ;
memset ( & V_186 , 0 , sizeof( V_186 ) ) ;
V_186 . V_27 = V_191 -> V_27 ;
V_186 . V_34 = V_191 -> V_34 ;
V_186 . V_33 [ 0 ] = * ( ( V_192 * ) V_191 -> V_33 + 0 ) ;
V_186 . V_33 [ 1 ] = * ( ( V_192 * ) V_191 -> V_33 + 1 ) ;
}
V_13 = F_66 (unsigned int, len, sizeof(uf)) ;
if ( F_94 ( V_184 , & V_186 , V_13 ) )
V_91 = - V_92 ;
break;
default:
V_91 = - V_193 ;
break;
}
V_132:
F_64 ( V_9 ) ;
return V_91 ;
}
static int F_95 ( struct V_195 * V_195 , struct V_86 * V_8 , int V_196 ,
int V_197 )
{
struct V_8 * V_9 ;
F_3 ( L_8 , V_8 ) ;
if ( V_8 -> type != V_198 )
return - V_199 ;
V_8 -> V_200 = & V_201 ;
V_9 = F_96 ( V_195 , V_202 , V_38 , & V_203 ) ;
if ( ! V_9 )
return - V_204 ;
F_97 ( V_8 , V_9 ) ;
F_98 ( V_9 , V_205 ) ;
V_9 -> V_206 = V_196 ;
V_8 -> V_207 = V_208 ;
V_9 -> V_19 = V_84 ;
F_99 ( & V_14 , V_9 ) ;
return 0 ;
}
int T_5 F_100 ( void )
{
int V_91 ;
V_91 = F_101 ( & V_203 , 0 ) ;
if ( V_91 < 0 )
return V_91 ;
V_91 = F_102 ( V_209 , & V_210 ) ;
if ( V_91 < 0 )
goto error;
F_103 ( L_9 ) ;
return 0 ;
error:
F_104 ( L_10 ) ;
F_105 ( & V_203 ) ;
return V_91 ;
}
void F_106 ( void )
{
if ( F_107 ( V_209 ) < 0 )
F_104 ( L_11 ) ;
F_105 ( & V_203 ) ;
}
