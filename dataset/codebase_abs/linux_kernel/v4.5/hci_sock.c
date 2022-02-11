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
V_12 = F_11 ( V_9 ) & V_15 ;
if ( ! F_7 ( V_12 , & V_11 -> V_16 ) )
return true ;
if ( F_11 ( V_9 ) != V_17 )
return false ;
V_13 = ( * ( V_18 * ) V_9 -> V_19 & V_20 ) ;
if ( ! F_9 ( V_13 , & V_11 -> V_21 ) )
return true ;
if ( ! V_11 -> V_22 )
return false ;
if ( V_13 == V_23 &&
V_11 -> V_22 != F_12 ( ( V_24 * ) ( V_9 -> V_19 + 3 ) ) )
return true ;
if ( V_13 == V_25 &&
V_11 -> V_22 != F_12 ( ( V_24 * ) ( V_9 -> V_19 + 4 ) ) )
return true ;
return false ;
}
void F_13 ( struct V_26 * V_27 , struct V_8 * V_9 )
{
struct V_1 * V_2 ;
struct V_8 * V_28 = NULL ;
F_14 ( L_1 , V_27 , V_9 -> V_29 ) ;
F_15 ( & V_30 . V_31 ) ;
F_16 (sk, &hci_sk_list.head) {
struct V_8 * V_32 ;
if ( V_2 -> V_33 != V_34 || F_3 ( V_2 ) -> V_27 != V_27 )
continue;
if ( V_9 -> V_2 == V_2 )
continue;
if ( F_3 ( V_2 ) -> V_5 == V_35 ) {
if ( F_11 ( V_9 ) != V_36 &&
F_11 ( V_9 ) != V_17 &&
F_11 ( V_9 ) != V_37 &&
F_11 ( V_9 ) != V_38 )
continue;
if ( F_10 ( V_2 , V_9 ) )
continue;
} else if ( F_3 ( V_2 ) -> V_5 == V_39 ) {
if ( ! F_17 ( V_9 ) -> V_40 )
continue;
if ( F_11 ( V_9 ) != V_17 &&
F_11 ( V_9 ) != V_37 &&
F_11 ( V_9 ) != V_38 )
continue;
} else {
continue;
}
if ( ! V_28 ) {
V_28 = F_18 ( V_9 , 1 , V_41 , true ) ;
if ( ! V_28 )
continue;
memcpy ( F_19 ( V_28 , 1 ) , & F_11 ( V_9 ) , 1 ) ;
}
V_32 = F_20 ( V_28 , V_41 ) ;
if ( ! V_32 )
continue;
if ( F_21 ( V_2 , V_32 ) )
F_22 ( V_32 ) ;
}
F_23 ( & V_30 . V_31 ) ;
F_22 ( V_28 ) ;
}
void F_24 ( unsigned short V_5 , struct V_8 * V_9 ,
int V_42 , struct V_1 * V_43 )
{
struct V_1 * V_2 ;
F_14 ( L_2 , V_5 , V_9 -> V_29 ) ;
F_15 ( & V_30 . V_31 ) ;
F_16 (sk, &hci_sk_list.head) {
struct V_8 * V_32 ;
if ( ! F_6 ( V_2 , V_42 ) )
continue;
if ( V_2 == V_43 )
continue;
if ( V_2 -> V_33 != V_34 )
continue;
if ( F_3 ( V_2 ) -> V_5 != V_5 )
continue;
V_32 = F_20 ( V_9 , V_41 ) ;
if ( ! V_32 )
continue;
if ( F_21 ( V_2 , V_32 ) )
F_22 ( V_32 ) ;
}
F_23 ( & V_30 . V_31 ) ;
}
void F_25 ( struct V_26 * V_27 , struct V_8 * V_9 )
{
struct V_8 * V_28 = NULL ;
struct V_44 * V_45 ;
V_24 V_22 ;
if ( ! F_26 ( & V_46 ) )
return;
F_14 ( L_1 , V_27 , V_9 -> V_29 ) ;
switch ( F_11 ( V_9 ) ) {
case V_36 :
V_22 = F_27 ( V_47 ) ;
break;
case V_17 :
V_22 = F_27 ( V_48 ) ;
break;
case V_37 :
if ( F_17 ( V_9 ) -> V_40 )
V_22 = F_27 ( V_49 ) ;
else
V_22 = F_27 ( V_50 ) ;
break;
case V_38 :
if ( F_17 ( V_9 ) -> V_40 )
V_22 = F_27 ( V_51 ) ;
else
V_22 = F_27 ( V_52 ) ;
break;
case V_53 :
V_22 = F_27 ( V_54 ) ;
break;
default:
return;
}
V_28 = F_18 ( V_9 , V_55 , V_41 , true ) ;
if ( ! V_28 )
return;
V_45 = ( void * ) F_19 ( V_28 , V_55 ) ;
V_45 -> V_22 = V_22 ;
V_45 -> V_56 = F_27 ( V_27 -> V_57 ) ;
V_45 -> V_29 = F_27 ( V_9 -> V_29 ) ;
F_24 ( V_58 , V_28 ,
V_59 , NULL ) ;
F_22 ( V_28 ) ;
}
static struct V_8 * F_28 ( struct V_26 * V_27 , int V_60 )
{
struct V_44 * V_45 ;
struct V_61 * V_62 ;
struct V_63 * V_64 ;
struct V_8 * V_9 ;
V_24 V_22 ;
switch ( V_60 ) {
case V_65 :
V_9 = F_29 ( V_66 , V_41 ) ;
if ( ! V_9 )
return NULL ;
V_62 = ( void * ) F_30 ( V_9 , V_66 ) ;
V_62 -> type = V_27 -> V_67 ;
V_62 -> V_68 = V_27 -> V_68 ;
F_31 ( & V_62 -> V_69 , & V_27 -> V_69 ) ;
memcpy ( V_62 -> V_70 , V_27 -> V_70 , 8 ) ;
V_22 = F_27 ( V_71 ) ;
break;
case V_72 :
V_9 = F_29 ( 0 , V_41 ) ;
if ( ! V_9 )
return NULL ;
V_22 = F_27 ( V_73 ) ;
break;
case V_74 :
if ( V_27 -> V_75 == 0xffff )
return NULL ;
case V_76 :
V_9 = F_29 ( V_77 , V_41 ) ;
if ( ! V_9 )
return NULL ;
V_64 = ( void * ) F_30 ( V_9 , V_77 ) ;
F_31 ( & V_64 -> V_69 , & V_27 -> V_69 ) ;
V_64 -> V_75 = F_27 ( V_27 -> V_75 ) ;
V_22 = F_27 ( V_78 ) ;
break;
case V_79 :
V_9 = F_29 ( 0 , V_41 ) ;
if ( ! V_9 )
return NULL ;
V_22 = F_27 ( V_80 ) ;
break;
case V_81 :
V_9 = F_29 ( 0 , V_41 ) ;
if ( ! V_9 )
return NULL ;
V_22 = F_27 ( V_82 ) ;
break;
default:
return NULL ;
}
F_32 ( V_9 ) ;
V_45 = ( void * ) F_19 ( V_9 , V_55 ) ;
V_45 -> V_22 = V_22 ;
V_45 -> V_56 = F_27 ( V_27 -> V_57 ) ;
V_45 -> V_29 = F_27 ( V_9 -> V_29 - V_55 ) ;
return V_9 ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_26 * V_27 ;
F_15 ( & V_83 ) ;
F_34 (hdev, &hci_dev_list, list) {
struct V_8 * V_9 ;
V_9 = F_28 ( V_27 , V_65 ) ;
if ( ! V_9 )
continue;
if ( F_21 ( V_2 , V_9 ) )
F_22 ( V_9 ) ;
if ( ! F_7 ( V_84 , & V_27 -> V_4 ) )
continue;
V_9 = F_28 ( V_27 , V_79 ) ;
if ( ! V_9 )
continue;
if ( F_21 ( V_2 , V_9 ) )
F_22 ( V_9 ) ;
if ( F_7 ( V_85 , & V_27 -> V_4 ) )
V_9 = F_28 ( V_27 , V_76 ) ;
else if ( F_35 ( V_27 , V_86 ) )
V_9 = F_28 ( V_27 , V_74 ) ;
else
V_9 = NULL ;
if ( V_9 ) {
if ( F_21 ( V_2 , V_9 ) )
F_22 ( V_9 ) ;
}
}
F_23 ( & V_83 ) ;
}
static void F_36 ( struct V_26 * V_27 , int type , int V_87 , void * V_19 )
{
struct V_88 * V_45 ;
struct V_89 * V_90 ;
struct V_8 * V_9 ;
V_9 = F_29 ( V_91 + sizeof( * V_90 ) + V_87 , V_41 ) ;
if ( ! V_9 )
return;
V_45 = ( void * ) F_30 ( V_9 , V_91 ) ;
V_45 -> V_92 = V_93 ;
V_45 -> V_94 = sizeof( * V_90 ) + V_87 ;
V_90 = ( void * ) F_30 ( V_9 , sizeof( * V_90 ) + V_87 ) ;
V_90 -> type = type ;
memcpy ( V_90 -> V_19 , V_19 , V_87 ) ;
F_17 ( V_9 ) -> V_40 = 1 ;
F_32 ( V_9 ) ;
F_11 ( V_9 ) = V_17 ;
F_13 ( V_27 , V_9 ) ;
F_22 ( V_9 ) ;
}
void F_37 ( struct V_26 * V_27 , int V_60 )
{
F_14 ( L_3 , V_27 -> V_70 , V_60 ) ;
if ( F_26 ( & V_46 ) ) {
struct V_8 * V_9 ;
V_9 = F_28 ( V_27 , V_60 ) ;
if ( V_9 ) {
F_24 ( V_58 , V_9 ,
V_59 , NULL ) ;
F_22 ( V_9 ) ;
}
}
if ( V_60 <= V_95 ) {
struct V_96 V_90 ;
V_90 . V_60 = V_60 ;
V_90 . V_97 = V_27 -> V_57 ;
F_36 ( NULL , V_98 , sizeof( V_90 ) , & V_90 ) ;
}
if ( V_60 == V_72 ) {
struct V_1 * V_2 ;
F_15 ( & V_30 . V_31 ) ;
F_16 (sk, &hci_sk_list.head) {
F_38 ( V_2 ) ;
if ( F_3 ( V_2 ) -> V_27 == V_27 ) {
F_3 ( V_2 ) -> V_27 = NULL ;
V_2 -> V_99 = V_100 ;
V_2 -> V_33 = V_101 ;
V_2 -> V_102 ( V_2 ) ;
F_39 ( V_27 ) ;
}
F_40 ( V_2 ) ;
}
F_23 ( & V_30 . V_31 ) ;
}
}
static struct V_103 * F_41 ( unsigned short V_5 )
{
struct V_103 * V_104 ;
F_34 (c, &mgmt_chan_list, list) {
if ( V_104 -> V_5 == V_5 )
return V_104 ;
}
return NULL ;
}
static struct V_103 * F_42 ( unsigned short V_5 )
{
struct V_103 * V_104 ;
F_43 ( & V_105 ) ;
V_104 = F_41 ( V_5 ) ;
F_44 ( & V_105 ) ;
return V_104 ;
}
int F_45 ( struct V_103 * V_104 )
{
if ( V_104 -> V_5 < V_106 )
return - V_107 ;
F_43 ( & V_105 ) ;
if ( F_41 ( V_104 -> V_5 ) ) {
F_44 ( & V_105 ) ;
return - V_108 ;
}
F_46 ( & V_104 -> V_109 , & V_110 ) ;
F_44 ( & V_105 ) ;
return 0 ;
}
void F_47 ( struct V_103 * V_104 )
{
F_43 ( & V_105 ) ;
F_48 ( & V_104 -> V_109 ) ;
F_44 ( & V_105 ) ;
}
static int F_49 ( struct V_111 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_26 * V_27 ;
F_14 ( L_4 , V_1 , V_2 ) ;
if ( ! V_2 )
return 0 ;
V_27 = F_3 ( V_2 ) -> V_27 ;
if ( F_3 ( V_2 ) -> V_5 == V_58 )
F_50 ( & V_46 ) ;
F_51 ( & V_30 , V_2 ) ;
if ( V_27 ) {
if ( F_3 ( V_2 ) -> V_5 == V_39 ) {
F_52 ( V_27 ) ;
F_53 ( V_27 , V_112 ) ;
F_54 ( V_27 ) ;
}
F_50 ( & V_27 -> V_113 ) ;
F_39 ( V_27 ) ;
}
F_55 ( V_2 ) ;
F_56 ( & V_2 -> V_114 ) ;
F_56 ( & V_2 -> V_115 ) ;
F_57 ( V_2 ) ;
return 0 ;
}
static int F_58 ( struct V_26 * V_27 , void T_1 * V_116 )
{
T_2 V_69 ;
int V_117 ;
if ( F_59 ( & V_69 , V_116 , sizeof( V_69 ) ) )
return - V_118 ;
F_60 ( V_27 ) ;
V_117 = F_61 ( & V_27 -> V_119 , & V_69 , V_120 ) ;
F_62 ( V_27 ) ;
return V_117 ;
}
static int F_63 ( struct V_26 * V_27 , void T_1 * V_116 )
{
T_2 V_69 ;
int V_117 ;
if ( F_59 ( & V_69 , V_116 , sizeof( V_69 ) ) )
return - V_118 ;
F_60 ( V_27 ) ;
V_117 = F_64 ( & V_27 -> V_119 , & V_69 , V_120 ) ;
F_62 ( V_27 ) ;
return V_117 ;
}
static int F_65 ( struct V_1 * V_2 , unsigned int V_121 ,
unsigned long V_116 )
{
struct V_26 * V_27 = F_3 ( V_2 ) -> V_27 ;
if ( ! V_27 )
return - V_122 ;
if ( F_35 ( V_27 , V_112 ) )
return - V_123 ;
if ( F_35 ( V_27 , V_124 ) )
return - V_125 ;
if ( V_27 -> V_67 != V_126 )
return - V_125 ;
switch ( V_121 ) {
case V_127 :
if ( ! F_66 ( V_128 ) )
return - V_129 ;
return - V_125 ;
case V_130 :
return F_67 ( V_27 , ( void T_1 * ) V_116 ) ;
case V_131 :
return F_68 ( V_27 , ( void T_1 * ) V_116 ) ;
case V_132 :
if ( ! F_66 ( V_128 ) )
return - V_129 ;
return F_58 ( V_27 , ( void T_1 * ) V_116 ) ;
case V_133 :
if ( ! F_66 ( V_128 ) )
return - V_129 ;
return F_63 ( V_27 , ( void T_1 * ) V_116 ) ;
}
return - V_134 ;
}
static int F_69 ( struct V_111 * V_1 , unsigned int V_121 ,
unsigned long V_116 )
{
void T_1 * V_135 = ( void T_1 * ) V_116 ;
struct V_1 * V_2 = V_1 -> V_2 ;
int V_117 ;
F_14 ( L_5 , V_121 , V_116 ) ;
F_70 ( V_2 ) ;
if ( F_3 ( V_2 ) -> V_5 != V_35 ) {
V_117 = - V_122 ;
goto V_136;
}
F_71 ( V_2 ) ;
switch ( V_121 ) {
case V_137 :
return F_72 ( V_135 ) ;
case V_138 :
return F_73 ( V_135 ) ;
case V_139 :
return F_74 ( V_135 ) ;
case V_140 :
if ( ! F_66 ( V_128 ) )
return - V_129 ;
return F_75 ( V_116 ) ;
case V_141 :
if ( ! F_66 ( V_128 ) )
return - V_129 ;
return F_76 ( V_116 ) ;
case V_142 :
if ( ! F_66 ( V_128 ) )
return - V_129 ;
return F_77 ( V_116 ) ;
case V_143 :
if ( ! F_66 ( V_128 ) )
return - V_129 ;
return F_78 ( V_116 ) ;
case V_144 :
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
if ( ! F_66 ( V_128 ) )
return - V_129 ;
return F_79 ( V_121 , V_135 ) ;
case V_152 :
return F_80 ( V_135 ) ;
}
F_70 ( V_2 ) ;
V_117 = F_65 ( V_2 , V_121 , V_116 ) ;
V_136:
F_71 ( V_2 ) ;
return V_117 ;
}
static int F_81 ( struct V_111 * V_1 , struct V_153 * V_6 ,
int V_154 )
{
struct V_155 V_156 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_26 * V_27 = NULL ;
int V_29 , V_117 = 0 ;
F_14 ( L_4 , V_1 , V_2 ) ;
if ( ! V_6 )
return - V_107 ;
memset ( & V_156 , 0 , sizeof( V_156 ) ) ;
V_29 = F_82 (unsigned int, sizeof(haddr), addr_len) ;
memcpy ( & V_156 , V_6 , V_29 ) ;
if ( V_156 . V_157 != V_158 )
return - V_107 ;
F_70 ( V_2 ) ;
if ( V_2 -> V_33 == V_34 ) {
V_117 = - V_108 ;
goto V_136;
}
switch ( V_156 . V_159 ) {
case V_35 :
if ( F_3 ( V_2 ) -> V_27 ) {
V_117 = - V_108 ;
goto V_136;
}
if ( V_156 . V_26 != V_160 ) {
V_27 = F_83 ( V_156 . V_26 ) ;
if ( ! V_27 ) {
V_117 = - V_161 ;
goto V_136;
}
F_84 ( & V_27 -> V_113 ) ;
}
F_3 ( V_2 ) -> V_27 = V_27 ;
break;
case V_39 :
if ( F_3 ( V_2 ) -> V_27 ) {
V_117 = - V_108 ;
goto V_136;
}
if ( V_156 . V_26 == V_160 ) {
V_117 = - V_107 ;
goto V_136;
}
if ( ! F_66 ( V_128 ) ) {
V_117 = - V_129 ;
goto V_136;
}
V_27 = F_83 ( V_156 . V_26 ) ;
if ( ! V_27 ) {
V_117 = - V_161 ;
goto V_136;
}
if ( F_7 ( V_162 , & V_27 -> V_4 ) ||
F_35 ( V_27 , V_86 ) ||
F_35 ( V_27 , V_163 ) ||
( ! F_35 ( V_27 , V_164 ) &&
F_7 ( V_85 , & V_27 -> V_4 ) ) ) {
V_117 = - V_123 ;
F_39 ( V_27 ) ;
goto V_136;
}
if ( F_85 ( V_27 , V_112 ) ) {
V_117 = - V_165 ;
F_39 ( V_27 ) ;
goto V_136;
}
F_86 ( V_27 ) ;
V_117 = F_75 ( V_27 -> V_57 ) ;
if ( V_117 ) {
if ( V_117 == - V_108 ) {
V_117 = 0 ;
} else {
F_53 ( V_27 , V_112 ) ;
F_54 ( V_27 ) ;
F_39 ( V_27 ) ;
goto V_136;
}
}
F_84 ( & V_27 -> V_113 ) ;
F_3 ( V_2 ) -> V_27 = V_27 ;
break;
case V_58 :
if ( V_156 . V_26 != V_160 ) {
V_117 = - V_107 ;
goto V_136;
}
if ( ! F_66 ( V_166 ) ) {
V_117 = - V_129 ;
goto V_136;
}
F_1 ( V_2 , V_59 ) ;
F_87 ( V_2 , L_6 ,
F_88 () -> V_167 ,
F_88 () -> V_168 ) ;
F_87 ( V_2 , L_7 ,
V_169 ) ;
F_33 ( V_2 ) ;
F_84 ( & V_46 ) ;
break;
case V_170 :
if ( V_156 . V_26 != V_160 ) {
V_117 = - V_107 ;
goto V_136;
}
if ( ! F_66 ( V_128 ) ) {
V_117 = - V_129 ;
goto V_136;
}
break;
default:
if ( ! F_42 ( V_156 . V_159 ) ) {
V_117 = - V_107 ;
goto V_136;
}
if ( V_156 . V_26 != V_160 ) {
V_117 = - V_107 ;
goto V_136;
}
if ( F_66 ( V_128 ) )
F_1 ( V_2 , V_59 ) ;
if ( V_156 . V_159 == V_106 ) {
F_1 ( V_2 , V_171 ) ;
F_1 ( V_2 , V_172 ) ;
F_1 ( V_2 , V_173 ) ;
}
break;
}
F_3 ( V_2 ) -> V_5 = V_156 . V_159 ;
V_2 -> V_33 = V_34 ;
V_136:
F_71 ( V_2 ) ;
return V_117 ;
}
static int F_89 ( struct V_111 * V_1 , struct V_153 * V_6 ,
int * V_154 , int V_174 )
{
struct V_155 * V_156 = (struct V_155 * ) V_6 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_26 * V_27 ;
int V_117 = 0 ;
F_14 ( L_4 , V_1 , V_2 ) ;
if ( V_174 )
return - V_125 ;
F_70 ( V_2 ) ;
V_27 = F_3 ( V_2 ) -> V_27 ;
if ( ! V_27 ) {
V_117 = - V_122 ;
goto V_136;
}
* V_154 = sizeof( * V_156 ) ;
V_156 -> V_157 = V_158 ;
V_156 -> V_26 = V_27 -> V_57 ;
V_156 -> V_159 = F_3 ( V_2 ) -> V_5 ;
V_136:
F_71 ( V_2 ) ;
return V_117 ;
}
static void F_90 ( struct V_1 * V_2 , struct V_175 * V_176 ,
struct V_8 * V_9 )
{
V_7 V_177 = F_3 ( V_2 ) -> V_178 ;
if ( V_177 & V_179 ) {
int V_40 = F_17 ( V_9 ) -> V_40 ;
F_91 ( V_176 , V_180 , V_179 , sizeof( V_40 ) ,
& V_40 ) ;
}
if ( V_177 & V_181 ) {
#ifdef F_92
struct V_182 V_183 ;
#endif
struct V_184 V_185 ;
void * V_19 ;
int V_29 ;
F_93 ( V_9 , & V_185 ) ;
V_19 = & V_185 ;
V_29 = sizeof( V_185 ) ;
#ifdef F_92
if ( ! V_186 &&
( V_176 -> V_187 & V_188 ) ) {
V_183 . V_189 = V_185 . V_189 ;
V_183 . V_190 = V_185 . V_190 ;
V_19 = & V_183 ;
V_29 = sizeof( V_183 ) ;
}
#endif
F_91 ( V_176 , V_180 , V_181 , V_29 , V_19 ) ;
}
}
static int F_94 ( struct V_111 * V_1 , struct V_175 * V_176 ,
T_3 V_29 , int V_4 )
{
int V_191 = V_4 & V_192 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_8 * V_9 ;
int V_193 , V_117 ;
F_14 ( L_8 , V_1 , V_2 ) ;
if ( V_4 & V_194 )
return - V_125 ;
if ( F_3 ( V_2 ) -> V_5 == V_170 )
return - V_125 ;
if ( V_2 -> V_33 == V_195 )
return 0 ;
V_9 = F_95 ( V_2 , V_4 , V_191 , & V_117 ) ;
if ( ! V_9 )
return V_117 ;
V_193 = V_9 -> V_29 ;
if ( V_29 < V_193 ) {
V_176 -> V_187 |= V_196 ;
V_193 = V_29 ;
}
F_96 ( V_9 ) ;
V_117 = F_97 ( V_9 , 0 , V_176 , V_193 ) ;
switch ( F_3 ( V_2 ) -> V_5 ) {
case V_35 :
F_90 ( V_2 , V_176 , V_9 ) ;
break;
case V_39 :
case V_58 :
F_98 ( V_176 , V_2 , V_9 ) ;
break;
default:
if ( F_42 ( F_3 ( V_2 ) -> V_5 ) )
F_98 ( V_176 , V_2 , V_9 ) ;
break;
}
F_99 ( V_2 , V_9 ) ;
return V_117 ? : V_193 ;
}
static int F_100 ( struct V_103 * V_197 , struct V_1 * V_2 ,
struct V_175 * V_176 , T_3 V_198 )
{
void * V_199 ;
T_4 * V_200 ;
struct V_201 * V_45 ;
T_5 V_22 , V_56 , V_29 ;
struct V_26 * V_27 = NULL ;
const struct V_202 * V_203 ;
bool V_204 , V_205 ;
int V_117 ;
F_14 ( L_9 , V_198 ) ;
if ( V_198 < sizeof( * V_45 ) )
return - V_107 ;
V_199 = F_101 ( V_198 , V_206 ) ;
if ( ! V_199 )
return - V_207 ;
if ( F_102 ( V_199 , V_176 , V_198 ) ) {
V_117 = - V_118 ;
goto V_136;
}
V_45 = V_199 ;
V_22 = F_103 ( V_45 -> V_22 ) ;
V_56 = F_103 ( V_45 -> V_56 ) ;
V_29 = F_103 ( V_45 -> V_29 ) ;
if ( V_29 != V_198 - sizeof( * V_45 ) ) {
V_117 = - V_107 ;
goto V_136;
}
if ( V_22 >= V_197 -> V_208 ||
V_197 -> V_209 [ V_22 ] . V_210 == NULL ) {
F_14 ( L_10 , V_22 ) ;
V_117 = F_104 ( V_2 , V_56 , V_22 ,
V_211 ) ;
goto V_136;
}
V_203 = & V_197 -> V_209 [ V_22 ] ;
if ( ! F_6 ( V_2 , V_59 ) &&
! ( V_203 -> V_4 & V_212 ) ) {
V_117 = F_104 ( V_2 , V_56 , V_22 ,
V_213 ) ;
goto V_136;
}
if ( V_56 != V_214 ) {
V_27 = F_83 ( V_56 ) ;
if ( ! V_27 ) {
V_117 = F_104 ( V_2 , V_56 , V_22 ,
V_215 ) ;
goto V_136;
}
if ( F_35 ( V_27 , V_86 ) ||
F_35 ( V_27 , V_163 ) ||
F_35 ( V_27 , V_112 ) ) {
V_117 = F_104 ( V_2 , V_56 , V_22 ,
V_215 ) ;
goto V_136;
}
if ( F_35 ( V_27 , V_124 ) &&
! ( V_203 -> V_4 & V_216 ) ) {
V_117 = F_104 ( V_2 , V_56 , V_22 ,
V_215 ) ;
goto V_136;
}
}
V_205 = ( V_203 -> V_4 & V_217 ) ;
if ( V_205 != ! V_27 ) {
V_117 = F_104 ( V_2 , V_56 , V_22 ,
V_215 ) ;
goto V_136;
}
V_204 = ( V_203 -> V_4 & V_218 ) ;
if ( ( V_204 && V_29 < V_203 -> V_219 ) ||
( ! V_204 && V_29 != V_203 -> V_219 ) ) {
V_117 = F_104 ( V_2 , V_56 , V_22 ,
V_220 ) ;
goto V_136;
}
if ( V_27 && V_197 -> V_221 )
V_197 -> V_221 ( V_2 , V_27 ) ;
V_200 = V_199 + sizeof( * V_45 ) ;
V_117 = V_203 -> V_210 ( V_2 , V_27 , V_200 , V_29 ) ;
if ( V_117 < 0 )
goto V_136;
V_117 = V_198 ;
V_136:
if ( V_27 )
F_39 ( V_27 ) ;
F_105 ( V_199 ) ;
return V_117 ;
}
static int F_106 ( struct V_1 * V_2 , struct V_175 * V_176 , int V_29 )
{
struct V_44 * V_45 ;
struct V_8 * V_9 ;
struct V_26 * V_27 ;
T_5 V_56 ;
int V_117 ;
if ( V_29 < sizeof( * V_45 ) + 3 )
return - V_107 ;
V_9 = F_107 ( V_2 , V_29 , V_176 -> V_187 & V_192 , & V_117 ) ;
if ( ! V_9 )
return V_117 ;
if ( F_102 ( F_30 ( V_9 , V_29 ) , V_176 , V_29 ) ) {
V_117 = - V_118 ;
goto V_222;
}
V_45 = ( void * ) V_9 -> V_19 ;
if ( F_103 ( V_45 -> V_29 ) != V_29 - sizeof( * V_45 ) ) {
V_117 = - V_107 ;
goto V_222;
}
if ( F_103 ( V_45 -> V_22 ) == 0x0000 ) {
V_18 V_223 = V_9 -> V_19 [ sizeof( * V_45 ) ] ;
V_18 V_224 = V_9 -> V_19 [ sizeof( * V_45 ) + 1 ] ;
if ( V_223 > 7 || V_9 -> V_19 [ V_29 - 1 ] != 0x00 ||
V_224 > V_29 - sizeof( * V_45 ) - 3 ||
V_9 -> V_19 [ sizeof( * V_45 ) + V_224 + 1 ] != 0x00 ) {
V_117 = - V_107 ;
goto V_222;
}
} else {
V_117 = - V_107 ;
goto V_222;
}
V_56 = F_103 ( V_45 -> V_56 ) ;
if ( V_56 != V_214 ) {
V_27 = F_83 ( V_56 ) ;
if ( ! V_27 ) {
V_117 = - V_161 ;
goto V_222;
}
} else {
V_27 = NULL ;
}
V_45 -> V_22 = F_27 ( V_225 ) ;
F_24 ( V_58 , V_9 , V_59 , NULL ) ;
V_117 = V_29 ;
if ( V_27 )
F_39 ( V_27 ) ;
V_222:
F_22 ( V_9 ) ;
return V_117 ;
}
static int F_108 ( struct V_111 * V_1 , struct V_175 * V_176 ,
T_3 V_29 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_103 * V_197 ;
struct V_26 * V_27 ;
struct V_8 * V_9 ;
int V_117 ;
F_14 ( L_4 , V_1 , V_2 ) ;
if ( V_176 -> V_187 & V_194 )
return - V_125 ;
if ( V_176 -> V_187 & ~ ( V_192 | V_226 | V_227 ) )
return - V_107 ;
if ( V_29 < 4 || V_29 > V_228 )
return - V_107 ;
F_70 ( V_2 ) ;
switch ( F_3 ( V_2 ) -> V_5 ) {
case V_35 :
case V_39 :
break;
case V_58 :
V_117 = - V_125 ;
goto V_136;
case V_170 :
V_117 = F_106 ( V_2 , V_176 , V_29 ) ;
goto V_136;
default:
F_43 ( & V_105 ) ;
V_197 = F_41 ( F_3 ( V_2 ) -> V_5 ) ;
if ( V_197 )
V_117 = F_100 ( V_197 , V_2 , V_176 , V_29 ) ;
else
V_117 = - V_107 ;
F_44 ( & V_105 ) ;
goto V_136;
}
V_27 = F_3 ( V_2 ) -> V_27 ;
if ( ! V_27 ) {
V_117 = - V_122 ;
goto V_136;
}
if ( ! F_7 ( V_85 , & V_27 -> V_4 ) ) {
V_117 = - V_229 ;
goto V_136;
}
V_9 = F_107 ( V_2 , V_29 , V_176 -> V_187 & V_192 , & V_117 ) ;
if ( ! V_9 )
goto V_136;
if ( F_102 ( F_30 ( V_9 , V_29 ) , V_176 , V_29 ) ) {
V_117 = - V_118 ;
goto V_222;
}
F_11 ( V_9 ) = V_9 -> V_19 [ 0 ] ;
F_109 ( V_9 , 1 ) ;
if ( F_3 ( V_2 ) -> V_5 == V_39 ) {
if ( F_11 ( V_9 ) != V_36 &&
F_11 ( V_9 ) != V_37 &&
F_11 ( V_9 ) != V_38 ) {
V_117 = - V_107 ;
goto V_222;
}
F_110 ( & V_27 -> V_230 , V_9 ) ;
F_111 ( V_27 -> V_231 , & V_27 -> V_232 ) ;
} else if ( F_11 ( V_9 ) == V_36 ) {
T_5 V_22 = F_112 ( V_9 -> V_19 ) ;
T_5 V_233 = F_113 ( V_22 ) ;
T_5 V_234 = F_114 ( V_22 ) ;
if ( ( ( V_233 > V_235 ) ||
! F_9 ( V_234 & V_236 ,
& V_237 . V_238 [ V_233 ] ) ) &&
! F_66 ( V_166 ) ) {
V_117 = - V_129 ;
goto V_222;
}
F_115 ( V_9 ) = V_22 ;
if ( V_233 == 0x3f ) {
F_110 ( & V_27 -> V_230 , V_9 ) ;
F_111 ( V_27 -> V_231 , & V_27 -> V_232 ) ;
} else {
F_17 ( V_9 ) -> V_239 . V_240 |= V_241 ;
F_110 ( & V_27 -> V_242 , V_9 ) ;
F_111 ( V_27 -> V_231 , & V_27 -> V_243 ) ;
}
} else {
if ( ! F_66 ( V_166 ) ) {
V_117 = - V_129 ;
goto V_222;
}
if ( F_11 ( V_9 ) != V_37 &&
F_11 ( V_9 ) != V_38 ) {
V_117 = - V_107 ;
goto V_222;
}
F_110 ( & V_27 -> V_230 , V_9 ) ;
F_111 ( V_27 -> V_231 , & V_27 -> V_232 ) ;
}
V_117 = V_29 ;
V_136:
F_71 ( V_2 ) ;
return V_117 ;
V_222:
F_22 ( V_9 ) ;
goto V_136;
}
static int F_116 ( struct V_111 * V_1 , int V_244 , int V_245 ,
char T_1 * V_246 , unsigned int V_29 )
{
struct V_247 V_248 = { . V_22 = 0 } ;
struct V_1 * V_2 = V_1 -> V_2 ;
int V_117 = 0 , V_249 = 0 ;
F_14 ( L_11 , V_2 , V_245 ) ;
F_70 ( V_2 ) ;
if ( F_3 ( V_2 ) -> V_5 != V_35 ) {
V_117 = - V_122 ;
goto V_136;
}
switch ( V_245 ) {
case V_250 :
if ( F_117 ( V_249 , ( int T_1 * ) V_246 ) ) {
V_117 = - V_118 ;
break;
}
if ( V_249 )
F_3 ( V_2 ) -> V_178 |= V_179 ;
else
F_3 ( V_2 ) -> V_178 &= ~ V_179 ;
break;
case V_251 :
if ( F_117 ( V_249 , ( int T_1 * ) V_246 ) ) {
V_117 = - V_118 ;
break;
}
if ( V_249 )
F_3 ( V_2 ) -> V_178 |= V_181 ;
else
F_3 ( V_2 ) -> V_178 &= ~ V_181 ;
break;
case V_252 :
{
struct V_10 * V_253 = & F_3 ( V_2 ) -> V_14 ;
V_248 . V_16 = V_253 -> V_16 ;
V_248 . V_22 = V_253 -> V_22 ;
V_248 . V_21 [ 0 ] = * ( ( V_254 * ) V_253 -> V_21 + 0 ) ;
V_248 . V_21 [ 1 ] = * ( ( V_254 * ) V_253 -> V_21 + 1 ) ;
}
V_29 = F_82 (unsigned int, len, sizeof(uf)) ;
if ( F_59 ( & V_248 , V_246 , V_29 ) ) {
V_117 = - V_118 ;
break;
}
if ( ! F_66 ( V_166 ) ) {
V_248 . V_16 &= V_237 . V_16 ;
V_248 . V_21 [ 0 ] &= * ( ( V_254 * ) V_237 . V_21 + 0 ) ;
V_248 . V_21 [ 1 ] &= * ( ( V_254 * ) V_237 . V_21 + 1 ) ;
}
{
struct V_10 * V_253 = & F_3 ( V_2 ) -> V_14 ;
V_253 -> V_16 = V_248 . V_16 ;
V_253 -> V_22 = V_248 . V_22 ;
* ( ( V_254 * ) V_253 -> V_21 + 0 ) = V_248 . V_21 [ 0 ] ;
* ( ( V_254 * ) V_253 -> V_21 + 1 ) = V_248 . V_21 [ 1 ] ;
}
break;
default:
V_117 = - V_255 ;
break;
}
V_136:
F_71 ( V_2 ) ;
return V_117 ;
}
static int F_118 ( struct V_111 * V_1 , int V_244 , int V_245 ,
char T_1 * V_246 , int T_1 * V_256 )
{
struct V_247 V_248 ;
struct V_1 * V_2 = V_1 -> V_2 ;
int V_29 , V_249 , V_117 = 0 ;
F_14 ( L_11 , V_2 , V_245 ) ;
if ( F_117 ( V_29 , V_256 ) )
return - V_118 ;
F_70 ( V_2 ) ;
if ( F_3 ( V_2 ) -> V_5 != V_35 ) {
V_117 = - V_122 ;
goto V_136;
}
switch ( V_245 ) {
case V_250 :
if ( F_3 ( V_2 ) -> V_178 & V_179 )
V_249 = 1 ;
else
V_249 = 0 ;
if ( F_119 ( V_249 , V_246 ) )
V_117 = - V_118 ;
break;
case V_251 :
if ( F_3 ( V_2 ) -> V_178 & V_181 )
V_249 = 1 ;
else
V_249 = 0 ;
if ( F_119 ( V_249 , V_246 ) )
V_117 = - V_118 ;
break;
case V_252 :
{
struct V_10 * V_253 = & F_3 ( V_2 ) -> V_14 ;
memset ( & V_248 , 0 , sizeof( V_248 ) ) ;
V_248 . V_16 = V_253 -> V_16 ;
V_248 . V_22 = V_253 -> V_22 ;
V_248 . V_21 [ 0 ] = * ( ( V_254 * ) V_253 -> V_21 + 0 ) ;
V_248 . V_21 [ 1 ] = * ( ( V_254 * ) V_253 -> V_21 + 1 ) ;
}
V_29 = F_82 (unsigned int, len, sizeof(uf)) ;
if ( F_120 ( V_246 , & V_248 , V_29 ) )
V_117 = - V_118 ;
break;
default:
V_117 = - V_255 ;
break;
}
V_136:
F_71 ( V_2 ) ;
return V_117 ;
}
static int F_121 ( struct V_257 * V_257 , struct V_111 * V_1 , int V_258 ,
int V_259 )
{
struct V_1 * V_2 ;
F_14 ( L_12 , V_1 ) ;
if ( V_1 -> type != V_260 )
return - V_261 ;
V_1 -> V_262 = & V_263 ;
V_2 = F_122 ( V_257 , V_264 , V_41 , & V_265 , V_259 ) ;
if ( ! V_2 )
return - V_207 ;
F_123 ( V_1 , V_2 ) ;
F_124 ( V_2 , V_266 ) ;
V_2 -> V_267 = V_258 ;
V_1 -> V_268 = V_269 ;
V_2 -> V_33 = V_101 ;
F_125 ( & V_30 , V_2 ) ;
return 0 ;
}
int T_6 F_126 ( void )
{
int V_117 ;
F_127 ( sizeof( struct V_155 ) > sizeof( struct V_153 ) ) ;
V_117 = F_128 ( & V_265 , 0 ) ;
if ( V_117 < 0 )
return V_117 ;
V_117 = F_129 ( V_270 , & V_271 ) ;
if ( V_117 < 0 ) {
F_130 ( L_13 ) ;
goto error;
}
V_117 = F_131 ( & V_272 , L_14 , & V_30 , NULL ) ;
if ( V_117 < 0 ) {
F_130 ( L_15 ) ;
F_132 ( V_270 ) ;
goto error;
}
F_133 ( L_16 ) ;
return 0 ;
error:
F_134 ( & V_265 ) ;
return V_117 ;
}
void F_135 ( void )
{
F_136 ( & V_272 , L_14 ) ;
F_132 ( V_270 ) ;
F_134 ( & V_265 ) ;
}
