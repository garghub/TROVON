static inline int F_1 ( int V_1 , void * V_2 )
{
return * ( ( V_3 * ) V_2 + ( V_1 >> 5 ) ) & ( ( V_3 ) 1 << ( V_1 & 31 ) ) ;
}
static bool F_2 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
struct V_8 * V_9 ;
int V_10 , V_11 ;
V_9 = & F_3 ( V_5 ) -> V_12 ;
if ( F_4 ( V_7 ) -> V_13 == V_14 )
V_10 = 0 ;
else
V_10 = F_4 ( V_7 ) -> V_13 & V_15 ;
if ( ! F_5 ( V_10 , & V_9 -> V_16 ) )
return true ;
if ( F_4 ( V_7 ) -> V_13 != V_17 )
return false ;
V_11 = ( * ( V_18 * ) V_7 -> V_19 & V_20 ) ;
if ( ! F_1 ( V_11 , & V_9 -> V_21 ) )
return true ;
if ( ! V_9 -> V_22 )
return false ;
if ( V_11 == V_23 &&
V_9 -> V_22 != F_6 ( ( V_24 * ) ( V_7 -> V_19 + 3 ) ) )
return true ;
if ( V_11 == V_25 &&
V_9 -> V_22 != F_6 ( ( V_24 * ) ( V_7 -> V_19 + 4 ) ) )
return true ;
return false ;
}
void F_7 ( struct V_26 * V_27 , struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_6 * V_28 = NULL ;
F_8 ( L_1 , V_27 , V_7 -> V_29 ) ;
F_9 ( & V_30 . V_31 ) ;
F_10 (sk, &hci_sk_list.head) {
struct V_6 * V_32 ;
if ( V_5 -> V_33 != V_34 || F_3 ( V_5 ) -> V_27 != V_27 )
continue;
if ( V_7 -> V_5 == V_5 )
continue;
if ( F_3 ( V_5 ) -> V_35 == V_36 ) {
if ( F_2 ( V_5 , V_7 ) )
continue;
} else if ( F_3 ( V_5 ) -> V_35 == V_37 ) {
if ( ! F_4 ( V_7 ) -> V_38 )
continue;
if ( F_4 ( V_7 ) -> V_13 != V_17 &&
F_4 ( V_7 ) -> V_13 != V_39 &&
F_4 ( V_7 ) -> V_13 != V_40 )
continue;
} else {
continue;
}
if ( ! V_28 ) {
V_28 = F_11 ( V_7 , 1 , V_41 ) ;
if ( ! V_28 )
continue;
memcpy ( F_12 ( V_28 , 1 ) , & F_4 ( V_7 ) -> V_13 , 1 ) ;
}
V_32 = F_13 ( V_28 , V_41 ) ;
if ( ! V_32 )
continue;
if ( F_14 ( V_5 , V_32 ) )
F_15 ( V_32 ) ;
}
F_16 ( & V_30 . V_31 ) ;
F_15 ( V_28 ) ;
}
void F_17 ( struct V_6 * V_7 , struct V_4 * V_42 )
{
struct V_4 * V_5 ;
F_8 ( L_2 , V_7 -> V_29 ) ;
F_9 ( & V_30 . V_31 ) ;
F_10 (sk, &hci_sk_list.head) {
struct V_6 * V_32 ;
if ( V_5 == V_42 )
continue;
if ( V_5 -> V_33 != V_34 )
continue;
if ( F_3 ( V_5 ) -> V_35 != V_43 )
continue;
V_32 = F_13 ( V_7 , V_41 ) ;
if ( ! V_32 )
continue;
if ( F_14 ( V_5 , V_32 ) )
F_15 ( V_32 ) ;
}
F_16 ( & V_30 . V_31 ) ;
}
void F_18 ( struct V_26 * V_27 , struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_6 * V_28 = NULL ;
V_24 V_22 ;
if ( ! F_19 ( & V_44 ) )
return;
F_8 ( L_1 , V_27 , V_7 -> V_29 ) ;
switch ( F_4 ( V_7 ) -> V_13 ) {
case V_45 :
V_22 = F_20 ( V_46 ) ;
break;
case V_17 :
V_22 = F_20 ( V_47 ) ;
break;
case V_39 :
if ( F_4 ( V_7 ) -> V_38 )
V_22 = F_20 ( V_48 ) ;
else
V_22 = F_20 ( V_49 ) ;
break;
case V_40 :
if ( F_4 ( V_7 ) -> V_38 )
V_22 = F_20 ( V_50 ) ;
else
V_22 = F_20 ( V_51 ) ;
break;
default:
return;
}
F_9 ( & V_30 . V_31 ) ;
F_10 (sk, &hci_sk_list.head) {
struct V_6 * V_32 ;
if ( V_5 -> V_33 != V_34 )
continue;
if ( F_3 ( V_5 ) -> V_35 != V_52 )
continue;
if ( ! V_28 ) {
struct V_53 * V_54 ;
V_28 = F_11 ( V_7 , V_55 ,
V_41 ) ;
if ( ! V_28 )
continue;
V_54 = ( void * ) F_12 ( V_28 , V_55 ) ;
V_54 -> V_22 = V_22 ;
V_54 -> V_56 = F_20 ( V_27 -> V_57 ) ;
V_54 -> V_29 = F_20 ( V_7 -> V_29 ) ;
}
V_32 = F_13 ( V_28 , V_41 ) ;
if ( ! V_32 )
continue;
if ( F_14 ( V_5 , V_32 ) )
F_15 ( V_32 ) ;
}
F_16 ( & V_30 . V_31 ) ;
F_15 ( V_28 ) ;
}
static void F_21 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_8 ( L_2 , V_7 -> V_29 ) ;
F_9 ( & V_30 . V_31 ) ;
F_10 (sk, &hci_sk_list.head) {
struct V_6 * V_32 ;
if ( V_5 -> V_33 != V_34 )
continue;
if ( F_3 ( V_5 ) -> V_35 != V_52 )
continue;
V_32 = F_13 ( V_7 , V_41 ) ;
if ( ! V_32 )
continue;
if ( F_14 ( V_5 , V_32 ) )
F_15 ( V_32 ) ;
}
F_16 ( & V_30 . V_31 ) ;
}
static struct V_6 * F_22 ( struct V_26 * V_27 , int V_58 )
{
struct V_53 * V_54 ;
struct V_59 * V_60 ;
struct V_6 * V_7 ;
V_24 V_22 ;
switch ( V_58 ) {
case V_61 :
V_7 = F_23 ( V_62 , V_41 ) ;
if ( ! V_7 )
return NULL ;
V_60 = ( void * ) F_24 ( V_7 , V_62 ) ;
V_60 -> type = V_27 -> V_63 ;
V_60 -> V_64 = V_27 -> V_64 ;
F_25 ( & V_60 -> V_65 , & V_27 -> V_65 ) ;
memcpy ( V_60 -> V_66 , V_27 -> V_66 , 8 ) ;
V_22 = F_20 ( V_67 ) ;
break;
case V_68 :
V_7 = F_23 ( 0 , V_41 ) ;
if ( ! V_7 )
return NULL ;
V_22 = F_20 ( V_69 ) ;
break;
default:
return NULL ;
}
F_26 ( V_7 ) ;
V_54 = ( void * ) F_12 ( V_7 , V_55 ) ;
V_54 -> V_22 = V_22 ;
V_54 -> V_56 = F_20 ( V_27 -> V_57 ) ;
V_54 -> V_29 = F_20 ( V_7 -> V_29 - V_55 ) ;
return V_7 ;
}
static void F_27 ( struct V_4 * V_5 )
{
struct V_26 * V_27 ;
F_9 ( & V_70 ) ;
F_28 (hdev, &hci_dev_list, list) {
struct V_6 * V_7 ;
V_7 = F_22 ( V_27 , V_61 ) ;
if ( ! V_7 )
continue;
if ( F_14 ( V_5 , V_7 ) )
F_15 ( V_7 ) ;
}
F_16 ( & V_70 ) ;
}
static void F_29 ( struct V_26 * V_27 , int type , int V_71 , void * V_19 )
{
struct V_72 * V_54 ;
struct V_73 * V_74 ;
struct V_6 * V_7 ;
V_7 = F_23 ( V_75 + sizeof( * V_74 ) + V_71 , V_41 ) ;
if ( ! V_7 )
return;
V_54 = ( void * ) F_24 ( V_7 , V_75 ) ;
V_54 -> V_76 = V_77 ;
V_54 -> V_78 = sizeof( * V_74 ) + V_71 ;
V_74 = ( void * ) F_24 ( V_7 , sizeof( * V_74 ) + V_71 ) ;
V_74 -> type = type ;
memcpy ( V_74 -> V_19 , V_19 , V_71 ) ;
F_4 ( V_7 ) -> V_38 = 1 ;
F_26 ( V_7 ) ;
F_4 ( V_7 ) -> V_13 = V_17 ;
F_7 ( V_27 , V_7 ) ;
F_15 ( V_7 ) ;
}
void F_30 ( struct V_26 * V_27 , int V_58 )
{
struct V_79 V_74 ;
F_8 ( L_3 , V_27 -> V_66 , V_58 ) ;
if ( F_19 ( & V_44 ) ) {
struct V_6 * V_7 ;
V_7 = F_22 ( V_27 , V_58 ) ;
if ( V_7 ) {
F_21 ( V_7 ) ;
F_15 ( V_7 ) ;
}
}
V_74 . V_58 = V_58 ;
V_74 . V_80 = V_27 -> V_57 ;
F_29 ( NULL , V_81 , sizeof( V_74 ) , & V_74 ) ;
if ( V_58 == V_68 ) {
struct V_4 * V_5 ;
F_9 ( & V_30 . V_31 ) ;
F_10 (sk, &hci_sk_list.head) {
F_31 ( V_5 ) ;
if ( F_3 ( V_5 ) -> V_27 == V_27 ) {
F_3 ( V_5 ) -> V_27 = NULL ;
V_5 -> V_82 = V_83 ;
V_5 -> V_33 = V_84 ;
V_5 -> V_85 ( V_5 ) ;
F_32 ( V_27 ) ;
}
F_33 ( V_5 ) ;
}
F_16 ( & V_30 . V_31 ) ;
}
}
static int F_34 ( struct V_86 * V_4 )
{
struct V_4 * V_5 = V_4 -> V_5 ;
struct V_26 * V_27 ;
F_8 ( L_4 , V_4 , V_5 ) ;
if ( ! V_5 )
return 0 ;
V_27 = F_3 ( V_5 ) -> V_27 ;
if ( F_3 ( V_5 ) -> V_35 == V_52 )
F_35 ( & V_44 ) ;
F_36 ( & V_30 , V_5 ) ;
if ( V_27 ) {
if ( F_3 ( V_5 ) -> V_35 == V_37 ) {
F_37 ( V_27 ) ;
F_38 ( V_87 , & V_27 -> V_88 ) ;
F_39 ( V_27 -> V_57 ) ;
}
F_35 ( & V_27 -> V_89 ) ;
F_32 ( V_27 ) ;
}
F_40 ( V_5 ) ;
F_41 ( & V_5 -> V_90 ) ;
F_41 ( & V_5 -> V_91 ) ;
F_42 ( V_5 ) ;
return 0 ;
}
static int F_43 ( struct V_26 * V_27 , void T_1 * V_92 )
{
T_2 V_65 ;
int V_93 ;
if ( F_44 ( & V_65 , V_92 , sizeof( V_65 ) ) )
return - V_94 ;
F_45 ( V_27 ) ;
V_93 = F_46 ( V_27 , & V_65 , V_95 ) ;
F_47 ( V_27 ) ;
return V_93 ;
}
static int F_48 ( struct V_26 * V_27 , void T_1 * V_92 )
{
T_2 V_65 ;
int V_93 ;
if ( F_44 ( & V_65 , V_92 , sizeof( V_65 ) ) )
return - V_94 ;
F_45 ( V_27 ) ;
V_93 = F_49 ( V_27 , & V_65 , V_95 ) ;
F_47 ( V_27 ) ;
return V_93 ;
}
static int F_50 ( struct V_4 * V_5 , unsigned int V_96 ,
unsigned long V_92 )
{
struct V_26 * V_27 = F_3 ( V_5 ) -> V_27 ;
if ( ! V_27 )
return - V_97 ;
if ( F_5 ( V_87 , & V_27 -> V_88 ) )
return - V_98 ;
if ( V_27 -> V_63 != V_99 )
return - V_100 ;
switch ( V_96 ) {
case V_101 :
if ( ! F_51 ( V_102 ) )
return - V_103 ;
if ( F_5 ( V_104 , & V_27 -> V_105 ) )
return - V_103 ;
if ( V_92 )
F_52 ( V_106 , & V_27 -> V_107 ) ;
else
F_38 ( V_106 , & V_27 -> V_107 ) ;
return 0 ;
case V_108 :
return F_53 ( V_27 , ( void T_1 * ) V_92 ) ;
case V_109 :
return F_54 ( V_27 , ( void T_1 * ) V_92 ) ;
case V_110 :
if ( ! F_51 ( V_102 ) )
return - V_103 ;
return F_43 ( V_27 , ( void T_1 * ) V_92 ) ;
case V_111 :
if ( ! F_51 ( V_102 ) )
return - V_103 ;
return F_48 ( V_27 , ( void T_1 * ) V_92 ) ;
}
return - V_112 ;
}
static int F_55 ( struct V_86 * V_4 , unsigned int V_96 ,
unsigned long V_92 )
{
void T_1 * V_113 = ( void T_1 * ) V_92 ;
struct V_4 * V_5 = V_4 -> V_5 ;
int V_93 ;
F_8 ( L_5 , V_96 , V_92 ) ;
F_56 ( V_5 ) ;
if ( F_3 ( V_5 ) -> V_35 != V_36 ) {
V_93 = - V_97 ;
goto V_114;
}
F_57 ( V_5 ) ;
switch ( V_96 ) {
case V_115 :
return F_58 ( V_113 ) ;
case V_116 :
return F_59 ( V_113 ) ;
case V_117 :
return F_60 ( V_113 ) ;
case V_118 :
if ( ! F_51 ( V_102 ) )
return - V_103 ;
return F_61 ( V_92 ) ;
case V_119 :
if ( ! F_51 ( V_102 ) )
return - V_103 ;
return F_39 ( V_92 ) ;
case V_120 :
if ( ! F_51 ( V_102 ) )
return - V_103 ;
return F_62 ( V_92 ) ;
case V_121 :
if ( ! F_51 ( V_102 ) )
return - V_103 ;
return F_63 ( V_92 ) ;
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_127 :
case V_128 :
case V_129 :
if ( ! F_51 ( V_102 ) )
return - V_103 ;
return F_64 ( V_96 , V_113 ) ;
case V_130 :
return F_65 ( V_113 ) ;
}
F_56 ( V_5 ) ;
V_93 = F_50 ( V_5 , V_96 , V_92 ) ;
V_114:
F_57 ( V_5 ) ;
return V_93 ;
}
static int F_66 ( struct V_86 * V_4 , struct V_131 * V_2 ,
int V_132 )
{
struct V_133 V_134 ;
struct V_4 * V_5 = V_4 -> V_5 ;
struct V_26 * V_27 = NULL ;
int V_29 , V_93 = 0 ;
F_8 ( L_4 , V_4 , V_5 ) ;
if ( ! V_2 )
return - V_135 ;
memset ( & V_134 , 0 , sizeof( V_134 ) ) ;
V_29 = F_67 (unsigned int, sizeof(haddr), addr_len) ;
memcpy ( & V_134 , V_2 , V_29 ) ;
if ( V_134 . V_136 != V_137 )
return - V_135 ;
F_56 ( V_5 ) ;
if ( V_5 -> V_33 == V_34 ) {
V_93 = - V_138 ;
goto V_114;
}
switch ( V_134 . V_139 ) {
case V_36 :
if ( F_3 ( V_5 ) -> V_27 ) {
V_93 = - V_138 ;
goto V_114;
}
if ( V_134 . V_26 != V_140 ) {
V_27 = F_68 ( V_134 . V_26 ) ;
if ( ! V_27 ) {
V_93 = - V_141 ;
goto V_114;
}
F_69 ( & V_27 -> V_89 ) ;
}
F_3 ( V_5 ) -> V_27 = V_27 ;
break;
case V_37 :
if ( F_3 ( V_5 ) -> V_27 ) {
V_93 = - V_138 ;
goto V_114;
}
if ( V_134 . V_26 == V_140 ) {
V_93 = - V_135 ;
goto V_114;
}
if ( ! F_51 ( V_102 ) ) {
V_93 = - V_103 ;
goto V_114;
}
V_27 = F_68 ( V_134 . V_26 ) ;
if ( ! V_27 ) {
V_93 = - V_141 ;
goto V_114;
}
if ( F_5 ( V_142 , & V_27 -> V_107 ) ||
F_5 ( V_143 , & V_27 -> V_107 ) ||
F_5 ( V_144 , & V_27 -> V_88 ) ) {
V_93 = - V_98 ;
F_32 ( V_27 ) ;
goto V_114;
}
if ( F_70 ( V_87 , & V_27 -> V_88 ) ) {
V_93 = - V_145 ;
F_32 ( V_27 ) ;
goto V_114;
}
F_71 ( V_27 ) ;
V_93 = F_61 ( V_27 -> V_57 ) ;
if ( V_93 ) {
F_38 ( V_87 , & V_27 -> V_88 ) ;
F_37 ( V_27 ) ;
F_32 ( V_27 ) ;
goto V_114;
}
F_69 ( & V_27 -> V_89 ) ;
F_3 ( V_5 ) -> V_27 = V_27 ;
break;
case V_43 :
if ( V_134 . V_26 != V_140 ) {
V_93 = - V_135 ;
goto V_114;
}
if ( ! F_51 ( V_102 ) ) {
V_93 = - V_103 ;
goto V_114;
}
break;
case V_52 :
if ( V_134 . V_26 != V_140 ) {
V_93 = - V_135 ;
goto V_114;
}
if ( ! F_51 ( V_146 ) ) {
V_93 = - V_103 ;
goto V_114;
}
F_27 ( V_5 ) ;
F_69 ( & V_44 ) ;
break;
default:
V_93 = - V_135 ;
goto V_114;
}
F_3 ( V_5 ) -> V_35 = V_134 . V_139 ;
V_5 -> V_33 = V_34 ;
V_114:
F_57 ( V_5 ) ;
return V_93 ;
}
static int F_72 ( struct V_86 * V_4 , struct V_131 * V_2 ,
int * V_132 , int V_147 )
{
struct V_133 * V_134 = (struct V_133 * ) V_2 ;
struct V_4 * V_5 = V_4 -> V_5 ;
struct V_26 * V_27 ;
int V_93 = 0 ;
F_8 ( L_4 , V_4 , V_5 ) ;
if ( V_147 )
return - V_100 ;
F_56 ( V_5 ) ;
V_27 = F_3 ( V_5 ) -> V_27 ;
if ( ! V_27 ) {
V_93 = - V_97 ;
goto V_114;
}
* V_132 = sizeof( * V_134 ) ;
V_134 -> V_136 = V_137 ;
V_134 -> V_26 = V_27 -> V_57 ;
V_134 -> V_139 = F_3 ( V_5 ) -> V_35 ;
V_114:
F_57 ( V_5 ) ;
return V_93 ;
}
static void F_73 ( struct V_4 * V_5 , struct V_148 * V_149 ,
struct V_6 * V_7 )
{
V_3 V_150 = F_3 ( V_5 ) -> V_151 ;
if ( V_150 & V_152 ) {
int V_38 = F_4 ( V_7 ) -> V_38 ;
F_74 ( V_149 , V_153 , V_152 , sizeof( V_38 ) ,
& V_38 ) ;
}
if ( V_150 & V_154 ) {
#ifdef F_75
struct V_155 V_156 ;
#endif
struct V_157 V_158 ;
void * V_19 ;
int V_29 ;
F_76 ( V_7 , & V_158 ) ;
V_19 = & V_158 ;
V_29 = sizeof( V_158 ) ;
#ifdef F_75
if ( ! V_159 &&
( V_149 -> V_160 & V_161 ) ) {
V_156 . V_162 = V_158 . V_162 ;
V_156 . V_163 = V_158 . V_163 ;
V_19 = & V_156 ;
V_29 = sizeof( V_156 ) ;
}
#endif
F_74 ( V_149 , V_153 , V_154 , V_29 , V_19 ) ;
}
}
static int F_77 ( struct V_164 * V_165 , struct V_86 * V_4 ,
struct V_148 * V_149 , T_3 V_29 , int V_107 )
{
int V_166 = V_107 & V_167 ;
struct V_4 * V_5 = V_4 -> V_5 ;
struct V_6 * V_7 ;
int V_168 , V_93 ;
F_8 ( L_6 , V_4 , V_5 ) ;
if ( V_107 & ( V_169 ) )
return - V_100 ;
if ( V_5 -> V_33 == V_170 )
return 0 ;
V_7 = F_78 ( V_5 , V_107 , V_166 , & V_93 ) ;
if ( ! V_7 )
return V_93 ;
V_168 = V_7 -> V_29 ;
if ( V_29 < V_168 ) {
V_149 -> V_160 |= V_171 ;
V_168 = V_29 ;
}
F_79 ( V_7 ) ;
V_93 = F_80 ( V_7 , 0 , V_149 -> V_172 , V_168 ) ;
switch ( F_3 ( V_5 ) -> V_35 ) {
case V_36 :
F_73 ( V_5 , V_149 , V_7 ) ;
break;
case V_37 :
case V_43 :
case V_52 :
F_81 ( V_149 , V_5 , V_7 ) ;
break;
}
F_82 ( V_5 , V_7 ) ;
return V_93 ? : V_168 ;
}
static int F_83 ( struct V_164 * V_165 , struct V_86 * V_4 ,
struct V_148 * V_149 , T_3 V_29 )
{
struct V_4 * V_5 = V_4 -> V_5 ;
struct V_26 * V_27 ;
struct V_6 * V_7 ;
int V_93 ;
F_8 ( L_4 , V_4 , V_5 ) ;
if ( V_149 -> V_160 & V_169 )
return - V_100 ;
if ( V_149 -> V_160 & ~ ( V_167 | V_173 | V_174 ) )
return - V_135 ;
if ( V_29 < 4 || V_29 > V_175 )
return - V_135 ;
F_56 ( V_5 ) ;
switch ( F_3 ( V_5 ) -> V_35 ) {
case V_36 :
case V_37 :
break;
case V_43 :
V_93 = F_84 ( V_5 , V_149 , V_29 ) ;
goto V_114;
case V_52 :
V_93 = - V_100 ;
goto V_114;
default:
V_93 = - V_135 ;
goto V_114;
}
V_27 = F_3 ( V_5 ) -> V_27 ;
if ( ! V_27 ) {
V_93 = - V_97 ;
goto V_114;
}
if ( ! F_5 ( V_142 , & V_27 -> V_107 ) ) {
V_93 = - V_176 ;
goto V_114;
}
V_7 = F_85 ( V_5 , V_29 , V_149 -> V_160 & V_167 , & V_93 ) ;
if ( ! V_7 )
goto V_114;
if ( F_86 ( F_24 ( V_7 , V_29 ) , V_149 -> V_172 , V_29 ) ) {
V_93 = - V_94 ;
goto V_177;
}
F_4 ( V_7 ) -> V_13 = * ( ( unsigned char * ) V_7 -> V_19 ) ;
F_87 ( V_7 , 1 ) ;
if ( F_3 ( V_5 ) -> V_35 == V_37 ) {
if ( F_4 ( V_7 ) -> V_13 != V_45 &&
F_4 ( V_7 ) -> V_13 != V_39 &&
F_4 ( V_7 ) -> V_13 != V_40 ) {
V_93 = - V_135 ;
goto V_177;
}
F_88 ( & V_27 -> V_178 , V_7 ) ;
F_89 ( V_27 -> V_179 , & V_27 -> V_180 ) ;
} else if ( F_4 ( V_7 ) -> V_13 == V_45 ) {
T_4 V_22 = F_90 ( V_7 -> V_19 ) ;
T_4 V_181 = F_91 ( V_22 ) ;
T_4 V_182 = F_92 ( V_22 ) ;
if ( ( ( V_181 > V_183 ) ||
! F_1 ( V_182 & V_184 ,
& V_185 . V_186 [ V_181 ] ) ) &&
! F_51 ( V_146 ) ) {
V_93 = - V_103 ;
goto V_177;
}
if ( F_5 ( V_106 , & V_27 -> V_107 ) || ( V_181 == 0x3f ) ) {
F_88 ( & V_27 -> V_178 , V_7 ) ;
F_89 ( V_27 -> V_179 , & V_27 -> V_180 ) ;
} else {
F_4 ( V_7 ) -> V_187 . V_188 = true ;
F_88 ( & V_27 -> V_189 , V_7 ) ;
F_89 ( V_27 -> V_179 , & V_27 -> V_190 ) ;
}
} else {
if ( ! F_51 ( V_146 ) ) {
V_93 = - V_103 ;
goto V_177;
}
F_88 ( & V_27 -> V_178 , V_7 ) ;
F_89 ( V_27 -> V_179 , & V_27 -> V_180 ) ;
}
V_93 = V_29 ;
V_114:
F_57 ( V_5 ) ;
return V_93 ;
V_177:
F_15 ( V_7 ) ;
goto V_114;
}
static int F_93 ( struct V_86 * V_4 , int V_191 , int V_192 ,
char T_1 * V_193 , unsigned int V_29 )
{
struct V_194 V_195 = { . V_22 = 0 } ;
struct V_4 * V_5 = V_4 -> V_5 ;
int V_93 = 0 , V_196 = 0 ;
F_8 ( L_7 , V_5 , V_192 ) ;
F_56 ( V_5 ) ;
if ( F_3 ( V_5 ) -> V_35 != V_36 ) {
V_93 = - V_97 ;
goto V_114;
}
switch ( V_192 ) {
case V_197 :
if ( F_94 ( V_196 , ( int T_1 * ) V_193 ) ) {
V_93 = - V_94 ;
break;
}
if ( V_196 )
F_3 ( V_5 ) -> V_151 |= V_152 ;
else
F_3 ( V_5 ) -> V_151 &= ~ V_152 ;
break;
case V_198 :
if ( F_94 ( V_196 , ( int T_1 * ) V_193 ) ) {
V_93 = - V_94 ;
break;
}
if ( V_196 )
F_3 ( V_5 ) -> V_151 |= V_154 ;
else
F_3 ( V_5 ) -> V_151 &= ~ V_154 ;
break;
case V_199 :
{
struct V_8 * V_200 = & F_3 ( V_5 ) -> V_12 ;
V_195 . V_16 = V_200 -> V_16 ;
V_195 . V_22 = V_200 -> V_22 ;
V_195 . V_21 [ 0 ] = * ( ( V_201 * ) V_200 -> V_21 + 0 ) ;
V_195 . V_21 [ 1 ] = * ( ( V_201 * ) V_200 -> V_21 + 1 ) ;
}
V_29 = F_67 (unsigned int, len, sizeof(uf)) ;
if ( F_44 ( & V_195 , V_193 , V_29 ) ) {
V_93 = - V_94 ;
break;
}
if ( ! F_51 ( V_146 ) ) {
V_195 . V_16 &= V_185 . V_16 ;
V_195 . V_21 [ 0 ] &= * ( ( V_201 * ) V_185 . V_21 + 0 ) ;
V_195 . V_21 [ 1 ] &= * ( ( V_201 * ) V_185 . V_21 + 1 ) ;
}
{
struct V_8 * V_200 = & F_3 ( V_5 ) -> V_12 ;
V_200 -> V_16 = V_195 . V_16 ;
V_200 -> V_22 = V_195 . V_22 ;
* ( ( V_201 * ) V_200 -> V_21 + 0 ) = V_195 . V_21 [ 0 ] ;
* ( ( V_201 * ) V_200 -> V_21 + 1 ) = V_195 . V_21 [ 1 ] ;
}
break;
default:
V_93 = - V_202 ;
break;
}
V_114:
F_57 ( V_5 ) ;
return V_93 ;
}
static int F_95 ( struct V_86 * V_4 , int V_191 , int V_192 ,
char T_1 * V_193 , int T_1 * V_203 )
{
struct V_194 V_195 ;
struct V_4 * V_5 = V_4 -> V_5 ;
int V_29 , V_196 , V_93 = 0 ;
F_8 ( L_7 , V_5 , V_192 ) ;
if ( F_94 ( V_29 , V_203 ) )
return - V_94 ;
F_56 ( V_5 ) ;
if ( F_3 ( V_5 ) -> V_35 != V_36 ) {
V_93 = - V_97 ;
goto V_114;
}
switch ( V_192 ) {
case V_197 :
if ( F_3 ( V_5 ) -> V_151 & V_152 )
V_196 = 1 ;
else
V_196 = 0 ;
if ( F_96 ( V_196 , V_193 ) )
V_93 = - V_94 ;
break;
case V_198 :
if ( F_3 ( V_5 ) -> V_151 & V_154 )
V_196 = 1 ;
else
V_196 = 0 ;
if ( F_96 ( V_196 , V_193 ) )
V_93 = - V_94 ;
break;
case V_199 :
{
struct V_8 * V_200 = & F_3 ( V_5 ) -> V_12 ;
memset ( & V_195 , 0 , sizeof( V_195 ) ) ;
V_195 . V_16 = V_200 -> V_16 ;
V_195 . V_22 = V_200 -> V_22 ;
V_195 . V_21 [ 0 ] = * ( ( V_201 * ) V_200 -> V_21 + 0 ) ;
V_195 . V_21 [ 1 ] = * ( ( V_201 * ) V_200 -> V_21 + 1 ) ;
}
V_29 = F_67 (unsigned int, len, sizeof(uf)) ;
if ( F_97 ( V_193 , & V_195 , V_29 ) )
V_93 = - V_94 ;
break;
default:
V_93 = - V_202 ;
break;
}
V_114:
F_57 ( V_5 ) ;
return V_93 ;
}
static int F_98 ( struct V_204 * V_204 , struct V_86 * V_4 , int V_205 ,
int V_206 )
{
struct V_4 * V_5 ;
F_8 ( L_8 , V_4 ) ;
if ( V_4 -> type != V_207 )
return - V_208 ;
V_4 -> V_209 = & V_210 ;
V_5 = F_99 ( V_204 , V_211 , V_41 , & V_212 ) ;
if ( ! V_5 )
return - V_213 ;
F_100 ( V_4 , V_5 ) ;
F_101 ( V_5 , V_214 ) ;
V_5 -> V_215 = V_205 ;
V_4 -> V_216 = V_217 ;
V_5 -> V_33 = V_84 ;
F_102 ( & V_30 , V_5 ) ;
return 0 ;
}
int T_5 F_103 ( void )
{
int V_93 ;
V_93 = F_104 ( & V_212 , 0 ) ;
if ( V_93 < 0 )
return V_93 ;
V_93 = F_105 ( V_218 , & V_219 ) ;
if ( V_93 < 0 ) {
F_106 ( L_9 ) ;
goto error;
}
V_93 = F_107 ( & V_220 , L_10 , & V_30 , NULL ) ;
if ( V_93 < 0 ) {
F_106 ( L_11 ) ;
F_108 ( V_218 ) ;
goto error;
}
F_109 ( L_12 ) ;
return 0 ;
error:
F_110 ( & V_212 ) ;
return V_93 ;
}
void F_111 ( void )
{
F_112 ( & V_220 , L_10 ) ;
F_108 ( V_218 ) ;
F_110 ( & V_212 ) ;
}
