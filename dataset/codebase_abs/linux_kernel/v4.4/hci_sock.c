void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_3 , & F_3 ( V_2 ) -> V_4 ) ;
}
void F_4 ( struct V_1 * V_2 , int V_3 )
{
F_5 ( V_3 , & F_3 ( V_2 ) -> V_4 ) ;
}
int F_6 ( struct V_1 * V_2 , int V_3 )
{
return F_7 ( V_3 , & F_3 ( V_2 ) -> V_4 ) ;
}
unsigned short F_8 ( struct V_1 * V_2 )
{
return F_3 ( V_2 ) -> V_5 ;
}
static inline int F_9 ( int V_3 , const void * V_6 )
{
return * ( ( const V_7 * ) V_6 + ( V_3 >> 5 ) ) & ( ( V_7 ) 1 << ( V_3 & 31 ) ) ;
}
static bool F_10 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_10 * V_11 ;
int V_12 , V_13 ;
V_11 = & F_3 ( V_2 ) -> V_14 ;
V_12 = F_11 ( V_9 ) -> V_15 & V_16 ;
if ( ! F_7 ( V_12 , & V_11 -> V_17 ) )
return true ;
if ( F_11 ( V_9 ) -> V_15 != V_18 )
return false ;
V_13 = ( * ( V_19 * ) V_9 -> V_20 & V_21 ) ;
if ( ! F_9 ( V_13 , & V_11 -> V_22 ) )
return true ;
if ( ! V_11 -> V_23 )
return false ;
if ( V_13 == V_24 &&
V_11 -> V_23 != F_12 ( ( V_25 * ) ( V_9 -> V_20 + 3 ) ) )
return true ;
if ( V_13 == V_26 &&
V_11 -> V_23 != F_12 ( ( V_25 * ) ( V_9 -> V_20 + 4 ) ) )
return true ;
return false ;
}
void F_13 ( struct V_27 * V_28 , struct V_8 * V_9 )
{
struct V_1 * V_2 ;
struct V_8 * V_29 = NULL ;
F_14 ( L_1 , V_28 , V_9 -> V_30 ) ;
F_15 ( & V_31 . V_32 ) ;
F_16 (sk, &hci_sk_list.head) {
struct V_8 * V_33 ;
if ( V_2 -> V_34 != V_35 || F_3 ( V_2 ) -> V_28 != V_28 )
continue;
if ( V_9 -> V_2 == V_2 )
continue;
if ( F_3 ( V_2 ) -> V_5 == V_36 ) {
if ( F_11 ( V_9 ) -> V_15 != V_37 &&
F_11 ( V_9 ) -> V_15 != V_18 &&
F_11 ( V_9 ) -> V_15 != V_38 &&
F_11 ( V_9 ) -> V_15 != V_39 )
continue;
if ( F_10 ( V_2 , V_9 ) )
continue;
} else if ( F_3 ( V_2 ) -> V_5 == V_40 ) {
if ( ! F_11 ( V_9 ) -> V_41 )
continue;
if ( F_11 ( V_9 ) -> V_15 != V_18 &&
F_11 ( V_9 ) -> V_15 != V_38 &&
F_11 ( V_9 ) -> V_15 != V_39 )
continue;
} else {
continue;
}
if ( ! V_29 ) {
V_29 = F_17 ( V_9 , 1 , V_42 , true ) ;
if ( ! V_29 )
continue;
memcpy ( F_18 ( V_29 , 1 ) , & F_11 ( V_9 ) -> V_15 , 1 ) ;
}
V_33 = F_19 ( V_29 , V_42 ) ;
if ( ! V_33 )
continue;
if ( F_20 ( V_2 , V_33 ) )
F_21 ( V_33 ) ;
}
F_22 ( & V_31 . V_32 ) ;
F_21 ( V_29 ) ;
}
void F_23 ( unsigned short V_5 , struct V_8 * V_9 ,
int V_43 , struct V_1 * V_44 )
{
struct V_1 * V_2 ;
F_14 ( L_2 , V_5 , V_9 -> V_30 ) ;
F_15 ( & V_31 . V_32 ) ;
F_16 (sk, &hci_sk_list.head) {
struct V_8 * V_33 ;
if ( ! F_6 ( V_2 , V_43 ) )
continue;
if ( V_2 == V_44 )
continue;
if ( V_2 -> V_34 != V_35 )
continue;
if ( F_3 ( V_2 ) -> V_5 != V_5 )
continue;
V_33 = F_19 ( V_9 , V_42 ) ;
if ( ! V_33 )
continue;
if ( F_20 ( V_2 , V_33 ) )
F_21 ( V_33 ) ;
}
F_22 ( & V_31 . V_32 ) ;
}
void F_24 ( struct V_27 * V_28 , struct V_8 * V_9 )
{
struct V_8 * V_29 = NULL ;
struct V_45 * V_46 ;
V_25 V_23 ;
if ( ! F_25 ( & V_47 ) )
return;
F_14 ( L_1 , V_28 , V_9 -> V_30 ) ;
switch ( F_11 ( V_9 ) -> V_15 ) {
case V_37 :
V_23 = F_26 ( V_48 ) ;
break;
case V_18 :
V_23 = F_26 ( V_49 ) ;
break;
case V_38 :
if ( F_11 ( V_9 ) -> V_41 )
V_23 = F_26 ( V_50 ) ;
else
V_23 = F_26 ( V_51 ) ;
break;
case V_39 :
if ( F_11 ( V_9 ) -> V_41 )
V_23 = F_26 ( V_52 ) ;
else
V_23 = F_26 ( V_53 ) ;
break;
case V_54 :
V_23 = F_26 ( V_55 ) ;
break;
default:
return;
}
V_29 = F_17 ( V_9 , V_56 , V_42 , true ) ;
if ( ! V_29 )
return;
V_46 = ( void * ) F_18 ( V_29 , V_56 ) ;
V_46 -> V_23 = V_23 ;
V_46 -> V_57 = F_26 ( V_28 -> V_58 ) ;
V_46 -> V_30 = F_26 ( V_9 -> V_30 ) ;
F_23 ( V_59 , V_29 ,
V_60 , NULL ) ;
F_21 ( V_29 ) ;
}
static struct V_8 * F_27 ( struct V_27 * V_28 , int V_61 )
{
struct V_45 * V_46 ;
struct V_62 * V_63 ;
struct V_64 * V_65 ;
struct V_8 * V_9 ;
V_25 V_23 ;
switch ( V_61 ) {
case V_66 :
V_9 = F_28 ( V_67 , V_42 ) ;
if ( ! V_9 )
return NULL ;
V_63 = ( void * ) F_29 ( V_9 , V_67 ) ;
V_63 -> type = V_28 -> V_68 ;
V_63 -> V_69 = V_28 -> V_69 ;
F_30 ( & V_63 -> V_70 , & V_28 -> V_70 ) ;
memcpy ( V_63 -> V_71 , V_28 -> V_71 , 8 ) ;
V_23 = F_26 ( V_72 ) ;
break;
case V_73 :
V_9 = F_28 ( 0 , V_42 ) ;
if ( ! V_9 )
return NULL ;
V_23 = F_26 ( V_74 ) ;
break;
case V_75 :
if ( V_28 -> V_76 == 0xffff )
return NULL ;
case V_77 :
V_9 = F_28 ( V_78 , V_42 ) ;
if ( ! V_9 )
return NULL ;
V_65 = ( void * ) F_29 ( V_9 , V_78 ) ;
F_30 ( & V_65 -> V_70 , & V_28 -> V_70 ) ;
V_65 -> V_76 = F_26 ( V_28 -> V_76 ) ;
V_23 = F_26 ( V_79 ) ;
break;
case V_80 :
V_9 = F_28 ( 0 , V_42 ) ;
if ( ! V_9 )
return NULL ;
V_23 = F_26 ( V_81 ) ;
break;
case V_82 :
V_9 = F_28 ( 0 , V_42 ) ;
if ( ! V_9 )
return NULL ;
V_23 = F_26 ( V_83 ) ;
break;
default:
return NULL ;
}
F_31 ( V_9 ) ;
V_46 = ( void * ) F_18 ( V_9 , V_56 ) ;
V_46 -> V_23 = V_23 ;
V_46 -> V_57 = F_26 ( V_28 -> V_58 ) ;
V_46 -> V_30 = F_26 ( V_9 -> V_30 - V_56 ) ;
return V_9 ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_27 * V_28 ;
F_15 ( & V_84 ) ;
F_33 (hdev, &hci_dev_list, list) {
struct V_8 * V_9 ;
V_9 = F_27 ( V_28 , V_66 ) ;
if ( ! V_9 )
continue;
if ( F_20 ( V_2 , V_9 ) )
F_21 ( V_9 ) ;
if ( ! F_7 ( V_85 , & V_28 -> V_4 ) )
continue;
V_9 = F_27 ( V_28 , V_80 ) ;
if ( ! V_9 )
continue;
if ( F_20 ( V_2 , V_9 ) )
F_21 ( V_9 ) ;
if ( F_7 ( V_86 , & V_28 -> V_4 ) )
V_9 = F_27 ( V_28 , V_77 ) ;
else if ( F_34 ( V_28 , V_87 ) )
V_9 = F_27 ( V_28 , V_75 ) ;
else
V_9 = NULL ;
if ( V_9 ) {
if ( F_20 ( V_2 , V_9 ) )
F_21 ( V_9 ) ;
}
}
F_22 ( & V_84 ) ;
}
static void F_35 ( struct V_27 * V_28 , int type , int V_88 , void * V_20 )
{
struct V_89 * V_46 ;
struct V_90 * V_91 ;
struct V_8 * V_9 ;
V_9 = F_28 ( V_92 + sizeof( * V_91 ) + V_88 , V_42 ) ;
if ( ! V_9 )
return;
V_46 = ( void * ) F_29 ( V_9 , V_92 ) ;
V_46 -> V_93 = V_94 ;
V_46 -> V_95 = sizeof( * V_91 ) + V_88 ;
V_91 = ( void * ) F_29 ( V_9 , sizeof( * V_91 ) + V_88 ) ;
V_91 -> type = type ;
memcpy ( V_91 -> V_20 , V_20 , V_88 ) ;
F_11 ( V_9 ) -> V_41 = 1 ;
F_31 ( V_9 ) ;
F_11 ( V_9 ) -> V_15 = V_18 ;
F_13 ( V_28 , V_9 ) ;
F_21 ( V_9 ) ;
}
void F_36 ( struct V_27 * V_28 , int V_61 )
{
F_14 ( L_3 , V_28 -> V_71 , V_61 ) ;
if ( F_25 ( & V_47 ) ) {
struct V_8 * V_9 ;
V_9 = F_27 ( V_28 , V_61 ) ;
if ( V_9 ) {
F_23 ( V_59 , V_9 ,
V_60 , NULL ) ;
F_21 ( V_9 ) ;
}
}
if ( V_61 <= V_96 ) {
struct V_97 V_91 ;
V_91 . V_61 = V_61 ;
V_91 . V_98 = V_28 -> V_58 ;
F_35 ( NULL , V_99 , sizeof( V_91 ) , & V_91 ) ;
}
if ( V_61 == V_73 ) {
struct V_1 * V_2 ;
F_15 ( & V_31 . V_32 ) ;
F_16 (sk, &hci_sk_list.head) {
F_37 ( V_2 ) ;
if ( F_3 ( V_2 ) -> V_28 == V_28 ) {
F_3 ( V_2 ) -> V_28 = NULL ;
V_2 -> V_100 = V_101 ;
V_2 -> V_34 = V_102 ;
V_2 -> V_103 ( V_2 ) ;
F_38 ( V_28 ) ;
}
F_39 ( V_2 ) ;
}
F_22 ( & V_31 . V_32 ) ;
}
}
static struct V_104 * F_40 ( unsigned short V_5 )
{
struct V_104 * V_105 ;
F_33 (c, &mgmt_chan_list, list) {
if ( V_105 -> V_5 == V_5 )
return V_105 ;
}
return NULL ;
}
static struct V_104 * F_41 ( unsigned short V_5 )
{
struct V_104 * V_105 ;
F_42 ( & V_106 ) ;
V_105 = F_40 ( V_5 ) ;
F_43 ( & V_106 ) ;
return V_105 ;
}
int F_44 ( struct V_104 * V_105 )
{
if ( V_105 -> V_5 < V_107 )
return - V_108 ;
F_42 ( & V_106 ) ;
if ( F_40 ( V_105 -> V_5 ) ) {
F_43 ( & V_106 ) ;
return - V_109 ;
}
F_45 ( & V_105 -> V_110 , & V_111 ) ;
F_43 ( & V_106 ) ;
return 0 ;
}
void F_46 ( struct V_104 * V_105 )
{
F_42 ( & V_106 ) ;
F_47 ( & V_105 -> V_110 ) ;
F_43 ( & V_106 ) ;
}
static int F_48 ( struct V_112 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_27 * V_28 ;
F_14 ( L_4 , V_1 , V_2 ) ;
if ( ! V_2 )
return 0 ;
V_28 = F_3 ( V_2 ) -> V_28 ;
if ( F_3 ( V_2 ) -> V_5 == V_59 )
F_49 ( & V_47 ) ;
F_50 ( & V_31 , V_2 ) ;
if ( V_28 ) {
if ( F_3 ( V_2 ) -> V_5 == V_40 ) {
F_51 ( V_28 ) ;
F_52 ( V_28 , V_113 ) ;
F_53 ( V_28 ) ;
}
F_49 ( & V_28 -> V_114 ) ;
F_38 ( V_28 ) ;
}
F_54 ( V_2 ) ;
F_55 ( & V_2 -> V_115 ) ;
F_55 ( & V_2 -> V_116 ) ;
F_56 ( V_2 ) ;
return 0 ;
}
static int F_57 ( struct V_27 * V_28 , void T_1 * V_117 )
{
T_2 V_70 ;
int V_118 ;
if ( F_58 ( & V_70 , V_117 , sizeof( V_70 ) ) )
return - V_119 ;
F_59 ( V_28 ) ;
V_118 = F_60 ( & V_28 -> V_120 , & V_70 , V_121 ) ;
F_61 ( V_28 ) ;
return V_118 ;
}
static int F_62 ( struct V_27 * V_28 , void T_1 * V_117 )
{
T_2 V_70 ;
int V_118 ;
if ( F_58 ( & V_70 , V_117 , sizeof( V_70 ) ) )
return - V_119 ;
F_59 ( V_28 ) ;
V_118 = F_63 ( & V_28 -> V_120 , & V_70 , V_121 ) ;
F_61 ( V_28 ) ;
return V_118 ;
}
static int F_64 ( struct V_1 * V_2 , unsigned int V_122 ,
unsigned long V_117 )
{
struct V_27 * V_28 = F_3 ( V_2 ) -> V_28 ;
if ( ! V_28 )
return - V_123 ;
if ( F_34 ( V_28 , V_113 ) )
return - V_124 ;
if ( F_34 ( V_28 , V_125 ) )
return - V_126 ;
if ( V_28 -> V_68 != V_127 )
return - V_126 ;
switch ( V_122 ) {
case V_128 :
if ( ! F_65 ( V_129 ) )
return - V_130 ;
return - V_126 ;
case V_131 :
return F_66 ( V_28 , ( void T_1 * ) V_117 ) ;
case V_132 :
return F_67 ( V_28 , ( void T_1 * ) V_117 ) ;
case V_133 :
if ( ! F_65 ( V_129 ) )
return - V_130 ;
return F_57 ( V_28 , ( void T_1 * ) V_117 ) ;
case V_134 :
if ( ! F_65 ( V_129 ) )
return - V_130 ;
return F_62 ( V_28 , ( void T_1 * ) V_117 ) ;
}
return - V_135 ;
}
static int F_68 ( struct V_112 * V_1 , unsigned int V_122 ,
unsigned long V_117 )
{
void T_1 * V_136 = ( void T_1 * ) V_117 ;
struct V_1 * V_2 = V_1 -> V_2 ;
int V_118 ;
F_14 ( L_5 , V_122 , V_117 ) ;
F_69 ( V_2 ) ;
if ( F_3 ( V_2 ) -> V_5 != V_36 ) {
V_118 = - V_123 ;
goto V_137;
}
F_70 ( V_2 ) ;
switch ( V_122 ) {
case V_138 :
return F_71 ( V_136 ) ;
case V_139 :
return F_72 ( V_136 ) ;
case V_140 :
return F_73 ( V_136 ) ;
case V_141 :
if ( ! F_65 ( V_129 ) )
return - V_130 ;
return F_74 ( V_117 ) ;
case V_142 :
if ( ! F_65 ( V_129 ) )
return - V_130 ;
return F_75 ( V_117 ) ;
case V_143 :
if ( ! F_65 ( V_129 ) )
return - V_130 ;
return F_76 ( V_117 ) ;
case V_144 :
if ( ! F_65 ( V_129 ) )
return - V_130 ;
return F_77 ( V_117 ) ;
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_152 :
if ( ! F_65 ( V_129 ) )
return - V_130 ;
return F_78 ( V_122 , V_136 ) ;
case V_153 :
return F_79 ( V_136 ) ;
}
F_69 ( V_2 ) ;
V_118 = F_64 ( V_2 , V_122 , V_117 ) ;
V_137:
F_70 ( V_2 ) ;
return V_118 ;
}
static int F_80 ( struct V_112 * V_1 , struct V_154 * V_6 ,
int V_155 )
{
struct V_156 V_157 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_27 * V_28 = NULL ;
int V_30 , V_118 = 0 ;
F_14 ( L_4 , V_1 , V_2 ) ;
if ( ! V_6 )
return - V_108 ;
memset ( & V_157 , 0 , sizeof( V_157 ) ) ;
V_30 = F_81 (unsigned int, sizeof(haddr), addr_len) ;
memcpy ( & V_157 , V_6 , V_30 ) ;
if ( V_157 . V_158 != V_159 )
return - V_108 ;
F_69 ( V_2 ) ;
if ( V_2 -> V_34 == V_35 ) {
V_118 = - V_109 ;
goto V_137;
}
switch ( V_157 . V_160 ) {
case V_36 :
if ( F_3 ( V_2 ) -> V_28 ) {
V_118 = - V_109 ;
goto V_137;
}
if ( V_157 . V_27 != V_161 ) {
V_28 = F_82 ( V_157 . V_27 ) ;
if ( ! V_28 ) {
V_118 = - V_162 ;
goto V_137;
}
F_83 ( & V_28 -> V_114 ) ;
}
F_3 ( V_2 ) -> V_28 = V_28 ;
break;
case V_40 :
if ( F_3 ( V_2 ) -> V_28 ) {
V_118 = - V_109 ;
goto V_137;
}
if ( V_157 . V_27 == V_161 ) {
V_118 = - V_108 ;
goto V_137;
}
if ( ! F_65 ( V_129 ) ) {
V_118 = - V_130 ;
goto V_137;
}
V_28 = F_82 ( V_157 . V_27 ) ;
if ( ! V_28 ) {
V_118 = - V_162 ;
goto V_137;
}
if ( F_7 ( V_163 , & V_28 -> V_4 ) ||
F_34 ( V_28 , V_87 ) ||
F_34 ( V_28 , V_164 ) ||
( ! F_34 ( V_28 , V_165 ) &&
F_7 ( V_86 , & V_28 -> V_4 ) ) ) {
V_118 = - V_124 ;
F_38 ( V_28 ) ;
goto V_137;
}
if ( F_84 ( V_28 , V_113 ) ) {
V_118 = - V_166 ;
F_38 ( V_28 ) ;
goto V_137;
}
F_85 ( V_28 ) ;
V_118 = F_74 ( V_28 -> V_58 ) ;
if ( V_118 ) {
if ( V_118 == - V_109 ) {
V_118 = 0 ;
} else {
F_52 ( V_28 , V_113 ) ;
F_53 ( V_28 ) ;
F_38 ( V_28 ) ;
goto V_137;
}
}
F_83 ( & V_28 -> V_114 ) ;
F_3 ( V_2 ) -> V_28 = V_28 ;
break;
case V_59 :
if ( V_157 . V_27 != V_161 ) {
V_118 = - V_108 ;
goto V_137;
}
if ( ! F_65 ( V_167 ) ) {
V_118 = - V_130 ;
goto V_137;
}
F_1 ( V_2 , V_60 ) ;
F_32 ( V_2 ) ;
F_83 ( & V_47 ) ;
break;
default:
if ( ! F_41 ( V_157 . V_160 ) ) {
V_118 = - V_108 ;
goto V_137;
}
if ( V_157 . V_27 != V_161 ) {
V_118 = - V_108 ;
goto V_137;
}
if ( F_65 ( V_129 ) )
F_1 ( V_2 , V_60 ) ;
if ( V_157 . V_160 == V_107 ) {
F_1 ( V_2 , V_168 ) ;
F_1 ( V_2 , V_169 ) ;
F_1 ( V_2 , V_170 ) ;
}
break;
}
F_3 ( V_2 ) -> V_5 = V_157 . V_160 ;
V_2 -> V_34 = V_35 ;
V_137:
F_70 ( V_2 ) ;
return V_118 ;
}
static int F_86 ( struct V_112 * V_1 , struct V_154 * V_6 ,
int * V_155 , int V_171 )
{
struct V_156 * V_157 = (struct V_156 * ) V_6 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_27 * V_28 ;
int V_118 = 0 ;
F_14 ( L_4 , V_1 , V_2 ) ;
if ( V_171 )
return - V_126 ;
F_69 ( V_2 ) ;
V_28 = F_3 ( V_2 ) -> V_28 ;
if ( ! V_28 ) {
V_118 = - V_123 ;
goto V_137;
}
* V_155 = sizeof( * V_157 ) ;
V_157 -> V_158 = V_159 ;
V_157 -> V_27 = V_28 -> V_58 ;
V_157 -> V_160 = F_3 ( V_2 ) -> V_5 ;
V_137:
F_70 ( V_2 ) ;
return V_118 ;
}
static void F_87 ( struct V_1 * V_2 , struct V_172 * V_173 ,
struct V_8 * V_9 )
{
V_7 V_174 = F_3 ( V_2 ) -> V_175 ;
if ( V_174 & V_176 ) {
int V_41 = F_11 ( V_9 ) -> V_41 ;
F_88 ( V_173 , V_177 , V_176 , sizeof( V_41 ) ,
& V_41 ) ;
}
if ( V_174 & V_178 ) {
#ifdef F_89
struct V_179 V_180 ;
#endif
struct V_181 V_182 ;
void * V_20 ;
int V_30 ;
F_90 ( V_9 , & V_182 ) ;
V_20 = & V_182 ;
V_30 = sizeof( V_182 ) ;
#ifdef F_89
if ( ! V_183 &&
( V_173 -> V_184 & V_185 ) ) {
V_180 . V_186 = V_182 . V_186 ;
V_180 . V_187 = V_182 . V_187 ;
V_20 = & V_180 ;
V_30 = sizeof( V_180 ) ;
}
#endif
F_88 ( V_173 , V_177 , V_178 , V_30 , V_20 ) ;
}
}
static int F_91 ( struct V_112 * V_1 , struct V_172 * V_173 , T_3 V_30 ,
int V_4 )
{
int V_188 = V_4 & V_189 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_8 * V_9 ;
int V_190 , V_118 ;
F_14 ( L_6 , V_1 , V_2 ) ;
if ( V_4 & V_191 )
return - V_126 ;
if ( V_2 -> V_34 == V_192 )
return 0 ;
V_9 = F_92 ( V_2 , V_4 , V_188 , & V_118 ) ;
if ( ! V_9 )
return V_118 ;
V_190 = V_9 -> V_30 ;
if ( V_30 < V_190 ) {
V_173 -> V_184 |= V_193 ;
V_190 = V_30 ;
}
F_93 ( V_9 ) ;
V_118 = F_94 ( V_9 , 0 , V_173 , V_190 ) ;
switch ( F_3 ( V_2 ) -> V_5 ) {
case V_36 :
F_87 ( V_2 , V_173 , V_9 ) ;
break;
case V_40 :
case V_59 :
F_95 ( V_173 , V_2 , V_9 ) ;
break;
default:
if ( F_41 ( F_3 ( V_2 ) -> V_5 ) )
F_95 ( V_173 , V_2 , V_9 ) ;
break;
}
F_96 ( V_2 , V_9 ) ;
return V_118 ? : V_190 ;
}
static int F_97 ( struct V_104 * V_194 , struct V_1 * V_2 ,
struct V_172 * V_173 , T_3 V_195 )
{
void * V_196 ;
T_4 * V_197 ;
struct V_198 * V_46 ;
T_5 V_23 , V_57 , V_30 ;
struct V_27 * V_28 = NULL ;
const struct V_199 * V_200 ;
bool V_201 , V_202 ;
int V_118 ;
F_14 ( L_7 , V_195 ) ;
if ( V_195 < sizeof( * V_46 ) )
return - V_108 ;
V_196 = F_98 ( V_195 , V_203 ) ;
if ( ! V_196 )
return - V_204 ;
if ( F_99 ( V_196 , V_173 , V_195 ) ) {
V_118 = - V_119 ;
goto V_137;
}
V_46 = V_196 ;
V_23 = F_100 ( V_46 -> V_23 ) ;
V_57 = F_100 ( V_46 -> V_57 ) ;
V_30 = F_100 ( V_46 -> V_30 ) ;
if ( V_30 != V_195 - sizeof( * V_46 ) ) {
V_118 = - V_108 ;
goto V_137;
}
if ( V_23 >= V_194 -> V_205 ||
V_194 -> V_206 [ V_23 ] . V_207 == NULL ) {
F_14 ( L_8 , V_23 ) ;
V_118 = F_101 ( V_2 , V_57 , V_23 ,
V_208 ) ;
goto V_137;
}
V_200 = & V_194 -> V_206 [ V_23 ] ;
if ( ! F_6 ( V_2 , V_60 ) &&
! ( V_200 -> V_4 & V_209 ) ) {
V_118 = F_101 ( V_2 , V_57 , V_23 ,
V_210 ) ;
goto V_137;
}
if ( V_57 != V_211 ) {
V_28 = F_82 ( V_57 ) ;
if ( ! V_28 ) {
V_118 = F_101 ( V_2 , V_57 , V_23 ,
V_212 ) ;
goto V_137;
}
if ( F_34 ( V_28 , V_87 ) ||
F_34 ( V_28 , V_164 ) ||
F_34 ( V_28 , V_113 ) ) {
V_118 = F_101 ( V_2 , V_57 , V_23 ,
V_212 ) ;
goto V_137;
}
if ( F_34 ( V_28 , V_125 ) &&
! ( V_200 -> V_4 & V_213 ) ) {
V_118 = F_101 ( V_2 , V_57 , V_23 ,
V_212 ) ;
goto V_137;
}
}
V_202 = ( V_200 -> V_4 & V_214 ) ;
if ( V_202 != ! V_28 ) {
V_118 = F_101 ( V_2 , V_57 , V_23 ,
V_212 ) ;
goto V_137;
}
V_201 = ( V_200 -> V_4 & V_215 ) ;
if ( ( V_201 && V_30 < V_200 -> V_216 ) ||
( ! V_201 && V_30 != V_200 -> V_216 ) ) {
V_118 = F_101 ( V_2 , V_57 , V_23 ,
V_217 ) ;
goto V_137;
}
if ( V_28 && V_194 -> V_218 )
V_194 -> V_218 ( V_2 , V_28 ) ;
V_197 = V_196 + sizeof( * V_46 ) ;
V_118 = V_200 -> V_207 ( V_2 , V_28 , V_197 , V_30 ) ;
if ( V_118 < 0 )
goto V_137;
V_118 = V_195 ;
V_137:
if ( V_28 )
F_38 ( V_28 ) ;
F_102 ( V_196 ) ;
return V_118 ;
}
static int F_103 ( struct V_112 * V_1 , struct V_172 * V_173 ,
T_3 V_30 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_104 * V_194 ;
struct V_27 * V_28 ;
struct V_8 * V_9 ;
int V_118 ;
F_14 ( L_4 , V_1 , V_2 ) ;
if ( V_173 -> V_184 & V_191 )
return - V_126 ;
if ( V_173 -> V_184 & ~ ( V_189 | V_219 | V_220 ) )
return - V_108 ;
if ( V_30 < 4 || V_30 > V_221 )
return - V_108 ;
F_69 ( V_2 ) ;
switch ( F_3 ( V_2 ) -> V_5 ) {
case V_36 :
case V_40 :
break;
case V_59 :
V_118 = - V_126 ;
goto V_137;
default:
F_42 ( & V_106 ) ;
V_194 = F_40 ( F_3 ( V_2 ) -> V_5 ) ;
if ( V_194 )
V_118 = F_97 ( V_194 , V_2 , V_173 , V_30 ) ;
else
V_118 = - V_108 ;
F_43 ( & V_106 ) ;
goto V_137;
}
V_28 = F_3 ( V_2 ) -> V_28 ;
if ( ! V_28 ) {
V_118 = - V_123 ;
goto V_137;
}
if ( ! F_7 ( V_86 , & V_28 -> V_4 ) ) {
V_118 = - V_222 ;
goto V_137;
}
V_9 = F_104 ( V_2 , V_30 , V_173 -> V_184 & V_189 , & V_118 ) ;
if ( ! V_9 )
goto V_137;
if ( F_99 ( F_29 ( V_9 , V_30 ) , V_173 , V_30 ) ) {
V_118 = - V_119 ;
goto V_223;
}
F_11 ( V_9 ) -> V_15 = * ( ( unsigned char * ) V_9 -> V_20 ) ;
F_105 ( V_9 , 1 ) ;
if ( F_3 ( V_2 ) -> V_5 == V_40 ) {
if ( F_11 ( V_9 ) -> V_15 != V_37 &&
F_11 ( V_9 ) -> V_15 != V_38 &&
F_11 ( V_9 ) -> V_15 != V_39 ) {
V_118 = - V_108 ;
goto V_223;
}
F_106 ( & V_28 -> V_224 , V_9 ) ;
F_107 ( V_28 -> V_225 , & V_28 -> V_226 ) ;
} else if ( F_11 ( V_9 ) -> V_15 == V_37 ) {
T_5 V_23 = F_108 ( V_9 -> V_20 ) ;
T_5 V_227 = F_109 ( V_23 ) ;
T_5 V_228 = F_110 ( V_23 ) ;
if ( ( ( V_227 > V_229 ) ||
! F_9 ( V_228 & V_230 ,
& V_231 . V_232 [ V_227 ] ) ) &&
! F_65 ( V_167 ) ) {
V_118 = - V_130 ;
goto V_223;
}
if ( V_227 == 0x3f ) {
F_106 ( & V_28 -> V_224 , V_9 ) ;
F_107 ( V_28 -> V_225 , & V_28 -> V_226 ) ;
} else {
F_11 ( V_9 ) -> V_233 . V_234 = true ;
F_106 ( & V_28 -> V_235 , V_9 ) ;
F_107 ( V_28 -> V_225 , & V_28 -> V_236 ) ;
}
} else {
if ( ! F_65 ( V_167 ) ) {
V_118 = - V_130 ;
goto V_223;
}
if ( F_11 ( V_9 ) -> V_15 != V_38 &&
F_11 ( V_9 ) -> V_15 != V_39 ) {
V_118 = - V_108 ;
goto V_223;
}
F_106 ( & V_28 -> V_224 , V_9 ) ;
F_107 ( V_28 -> V_225 , & V_28 -> V_226 ) ;
}
V_118 = V_30 ;
V_137:
F_70 ( V_2 ) ;
return V_118 ;
V_223:
F_21 ( V_9 ) ;
goto V_137;
}
static int F_111 ( struct V_112 * V_1 , int V_237 , int V_238 ,
char T_1 * V_239 , unsigned int V_30 )
{
struct V_240 V_241 = { . V_23 = 0 } ;
struct V_1 * V_2 = V_1 -> V_2 ;
int V_118 = 0 , V_242 = 0 ;
F_14 ( L_9 , V_2 , V_238 ) ;
F_69 ( V_2 ) ;
if ( F_3 ( V_2 ) -> V_5 != V_36 ) {
V_118 = - V_123 ;
goto V_137;
}
switch ( V_238 ) {
case V_243 :
if ( F_112 ( V_242 , ( int T_1 * ) V_239 ) ) {
V_118 = - V_119 ;
break;
}
if ( V_242 )
F_3 ( V_2 ) -> V_175 |= V_176 ;
else
F_3 ( V_2 ) -> V_175 &= ~ V_176 ;
break;
case V_244 :
if ( F_112 ( V_242 , ( int T_1 * ) V_239 ) ) {
V_118 = - V_119 ;
break;
}
if ( V_242 )
F_3 ( V_2 ) -> V_175 |= V_178 ;
else
F_3 ( V_2 ) -> V_175 &= ~ V_178 ;
break;
case V_245 :
{
struct V_10 * V_246 = & F_3 ( V_2 ) -> V_14 ;
V_241 . V_17 = V_246 -> V_17 ;
V_241 . V_23 = V_246 -> V_23 ;
V_241 . V_22 [ 0 ] = * ( ( V_247 * ) V_246 -> V_22 + 0 ) ;
V_241 . V_22 [ 1 ] = * ( ( V_247 * ) V_246 -> V_22 + 1 ) ;
}
V_30 = F_81 (unsigned int, len, sizeof(uf)) ;
if ( F_58 ( & V_241 , V_239 , V_30 ) ) {
V_118 = - V_119 ;
break;
}
if ( ! F_65 ( V_167 ) ) {
V_241 . V_17 &= V_231 . V_17 ;
V_241 . V_22 [ 0 ] &= * ( ( V_247 * ) V_231 . V_22 + 0 ) ;
V_241 . V_22 [ 1 ] &= * ( ( V_247 * ) V_231 . V_22 + 1 ) ;
}
{
struct V_10 * V_246 = & F_3 ( V_2 ) -> V_14 ;
V_246 -> V_17 = V_241 . V_17 ;
V_246 -> V_23 = V_241 . V_23 ;
* ( ( V_247 * ) V_246 -> V_22 + 0 ) = V_241 . V_22 [ 0 ] ;
* ( ( V_247 * ) V_246 -> V_22 + 1 ) = V_241 . V_22 [ 1 ] ;
}
break;
default:
V_118 = - V_248 ;
break;
}
V_137:
F_70 ( V_2 ) ;
return V_118 ;
}
static int F_113 ( struct V_112 * V_1 , int V_237 , int V_238 ,
char T_1 * V_239 , int T_1 * V_249 )
{
struct V_240 V_241 ;
struct V_1 * V_2 = V_1 -> V_2 ;
int V_30 , V_242 , V_118 = 0 ;
F_14 ( L_9 , V_2 , V_238 ) ;
if ( F_112 ( V_30 , V_249 ) )
return - V_119 ;
F_69 ( V_2 ) ;
if ( F_3 ( V_2 ) -> V_5 != V_36 ) {
V_118 = - V_123 ;
goto V_137;
}
switch ( V_238 ) {
case V_243 :
if ( F_3 ( V_2 ) -> V_175 & V_176 )
V_242 = 1 ;
else
V_242 = 0 ;
if ( F_114 ( V_242 , V_239 ) )
V_118 = - V_119 ;
break;
case V_244 :
if ( F_3 ( V_2 ) -> V_175 & V_178 )
V_242 = 1 ;
else
V_242 = 0 ;
if ( F_114 ( V_242 , V_239 ) )
V_118 = - V_119 ;
break;
case V_245 :
{
struct V_10 * V_246 = & F_3 ( V_2 ) -> V_14 ;
memset ( & V_241 , 0 , sizeof( V_241 ) ) ;
V_241 . V_17 = V_246 -> V_17 ;
V_241 . V_23 = V_246 -> V_23 ;
V_241 . V_22 [ 0 ] = * ( ( V_247 * ) V_246 -> V_22 + 0 ) ;
V_241 . V_22 [ 1 ] = * ( ( V_247 * ) V_246 -> V_22 + 1 ) ;
}
V_30 = F_81 (unsigned int, len, sizeof(uf)) ;
if ( F_115 ( V_239 , & V_241 , V_30 ) )
V_118 = - V_119 ;
break;
default:
V_118 = - V_248 ;
break;
}
V_137:
F_70 ( V_2 ) ;
return V_118 ;
}
static int F_116 ( struct V_250 * V_250 , struct V_112 * V_1 , int V_251 ,
int V_252 )
{
struct V_1 * V_2 ;
F_14 ( L_10 , V_1 ) ;
if ( V_1 -> type != V_253 )
return - V_254 ;
V_1 -> V_255 = & V_256 ;
V_2 = F_117 ( V_250 , V_257 , V_42 , & V_258 , V_252 ) ;
if ( ! V_2 )
return - V_204 ;
F_118 ( V_1 , V_2 ) ;
F_119 ( V_2 , V_259 ) ;
V_2 -> V_260 = V_251 ;
V_1 -> V_261 = V_262 ;
V_2 -> V_34 = V_102 ;
F_120 ( & V_31 , V_2 ) ;
return 0 ;
}
int T_6 F_121 ( void )
{
int V_118 ;
F_122 ( sizeof( struct V_156 ) > sizeof( struct V_154 ) ) ;
V_118 = F_123 ( & V_258 , 0 ) ;
if ( V_118 < 0 )
return V_118 ;
V_118 = F_124 ( V_263 , & V_264 ) ;
if ( V_118 < 0 ) {
F_125 ( L_11 ) ;
goto error;
}
V_118 = F_126 ( & V_265 , L_12 , & V_31 , NULL ) ;
if ( V_118 < 0 ) {
F_125 ( L_13 ) ;
F_127 ( V_263 ) ;
goto error;
}
F_128 ( L_14 ) ;
return 0 ;
error:
F_129 ( & V_258 ) ;
return V_118 ;
}
void F_130 ( void )
{
F_131 ( & V_265 , L_12 ) ;
F_127 ( V_263 ) ;
F_129 ( & V_258 ) ;
}
