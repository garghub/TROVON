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
V_28 = F_11 ( V_7 , 1 , V_41 , true ) ;
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
V_41 , true ) ;
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
return - V_100 ;
case V_104 :
return F_52 ( V_27 , ( void T_1 * ) V_92 ) ;
case V_105 :
return F_53 ( V_27 , ( void T_1 * ) V_92 ) ;
case V_106 :
if ( ! F_51 ( V_102 ) )
return - V_103 ;
return F_43 ( V_27 , ( void T_1 * ) V_92 ) ;
case V_107 :
if ( ! F_51 ( V_102 ) )
return - V_103 ;
return F_48 ( V_27 , ( void T_1 * ) V_92 ) ;
}
return - V_108 ;
}
static int F_54 ( struct V_86 * V_4 , unsigned int V_96 ,
unsigned long V_92 )
{
void T_1 * V_109 = ( void T_1 * ) V_92 ;
struct V_4 * V_5 = V_4 -> V_5 ;
int V_93 ;
F_8 ( L_5 , V_96 , V_92 ) ;
F_55 ( V_5 ) ;
if ( F_3 ( V_5 ) -> V_35 != V_36 ) {
V_93 = - V_97 ;
goto V_110;
}
F_56 ( V_5 ) ;
switch ( V_96 ) {
case V_111 :
return F_57 ( V_109 ) ;
case V_112 :
return F_58 ( V_109 ) ;
case V_113 :
return F_59 ( V_109 ) ;
case V_114 :
if ( ! F_51 ( V_102 ) )
return - V_103 ;
return F_60 ( V_92 ) ;
case V_115 :
if ( ! F_51 ( V_102 ) )
return - V_103 ;
return F_39 ( V_92 ) ;
case V_116 :
if ( ! F_51 ( V_102 ) )
return - V_103 ;
return F_61 ( V_92 ) ;
case V_117 :
if ( ! F_51 ( V_102 ) )
return - V_103 ;
return F_62 ( V_92 ) ;
case V_118 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
if ( ! F_51 ( V_102 ) )
return - V_103 ;
return F_63 ( V_96 , V_109 ) ;
case V_126 :
return F_64 ( V_109 ) ;
}
F_55 ( V_5 ) ;
V_93 = F_50 ( V_5 , V_96 , V_92 ) ;
V_110:
F_56 ( V_5 ) ;
return V_93 ;
}
static int F_65 ( struct V_86 * V_4 , struct V_127 * V_2 ,
int V_128 )
{
struct V_129 V_130 ;
struct V_4 * V_5 = V_4 -> V_5 ;
struct V_26 * V_27 = NULL ;
int V_29 , V_93 = 0 ;
F_8 ( L_4 , V_4 , V_5 ) ;
if ( ! V_2 )
return - V_131 ;
memset ( & V_130 , 0 , sizeof( V_130 ) ) ;
V_29 = F_66 (unsigned int, sizeof(haddr), addr_len) ;
memcpy ( & V_130 , V_2 , V_29 ) ;
if ( V_130 . V_132 != V_133 )
return - V_131 ;
F_55 ( V_5 ) ;
if ( V_5 -> V_33 == V_34 ) {
V_93 = - V_134 ;
goto V_110;
}
switch ( V_130 . V_135 ) {
case V_36 :
if ( F_3 ( V_5 ) -> V_27 ) {
V_93 = - V_134 ;
goto V_110;
}
if ( V_130 . V_26 != V_136 ) {
V_27 = F_67 ( V_130 . V_26 ) ;
if ( ! V_27 ) {
V_93 = - V_137 ;
goto V_110;
}
F_68 ( & V_27 -> V_89 ) ;
}
F_3 ( V_5 ) -> V_27 = V_27 ;
break;
case V_37 :
if ( F_3 ( V_5 ) -> V_27 ) {
V_93 = - V_134 ;
goto V_110;
}
if ( V_130 . V_26 == V_136 ) {
V_93 = - V_131 ;
goto V_110;
}
if ( ! F_51 ( V_102 ) ) {
V_93 = - V_103 ;
goto V_110;
}
V_27 = F_67 ( V_130 . V_26 ) ;
if ( ! V_27 ) {
V_93 = - V_137 ;
goto V_110;
}
if ( F_5 ( V_138 , & V_27 -> V_139 ) ||
F_5 ( V_140 , & V_27 -> V_139 ) ||
F_5 ( V_141 , & V_27 -> V_88 ) ) {
V_93 = - V_98 ;
F_32 ( V_27 ) ;
goto V_110;
}
if ( F_69 ( V_87 , & V_27 -> V_88 ) ) {
V_93 = - V_142 ;
F_32 ( V_27 ) ;
goto V_110;
}
F_70 ( V_27 ) ;
V_93 = F_60 ( V_27 -> V_57 ) ;
if ( V_93 ) {
F_38 ( V_87 , & V_27 -> V_88 ) ;
F_37 ( V_27 ) ;
F_32 ( V_27 ) ;
goto V_110;
}
F_68 ( & V_27 -> V_89 ) ;
F_3 ( V_5 ) -> V_27 = V_27 ;
break;
case V_43 :
if ( V_130 . V_26 != V_136 ) {
V_93 = - V_131 ;
goto V_110;
}
if ( ! F_51 ( V_102 ) ) {
V_93 = - V_103 ;
goto V_110;
}
break;
case V_52 :
if ( V_130 . V_26 != V_136 ) {
V_93 = - V_131 ;
goto V_110;
}
if ( ! F_51 ( V_143 ) ) {
V_93 = - V_103 ;
goto V_110;
}
F_27 ( V_5 ) ;
F_68 ( & V_44 ) ;
break;
default:
V_93 = - V_131 ;
goto V_110;
}
F_3 ( V_5 ) -> V_35 = V_130 . V_135 ;
V_5 -> V_33 = V_34 ;
V_110:
F_56 ( V_5 ) ;
return V_93 ;
}
static int F_71 ( struct V_86 * V_4 , struct V_127 * V_2 ,
int * V_128 , int V_144 )
{
struct V_129 * V_130 = (struct V_129 * ) V_2 ;
struct V_4 * V_5 = V_4 -> V_5 ;
struct V_26 * V_27 ;
int V_93 = 0 ;
F_8 ( L_4 , V_4 , V_5 ) ;
if ( V_144 )
return - V_100 ;
F_55 ( V_5 ) ;
V_27 = F_3 ( V_5 ) -> V_27 ;
if ( ! V_27 ) {
V_93 = - V_97 ;
goto V_110;
}
* V_128 = sizeof( * V_130 ) ;
V_130 -> V_132 = V_133 ;
V_130 -> V_26 = V_27 -> V_57 ;
V_130 -> V_135 = F_3 ( V_5 ) -> V_35 ;
V_110:
F_56 ( V_5 ) ;
return V_93 ;
}
static void F_72 ( struct V_4 * V_5 , struct V_145 * V_146 ,
struct V_6 * V_7 )
{
V_3 V_147 = F_3 ( V_5 ) -> V_148 ;
if ( V_147 & V_149 ) {
int V_38 = F_4 ( V_7 ) -> V_38 ;
F_73 ( V_146 , V_150 , V_149 , sizeof( V_38 ) ,
& V_38 ) ;
}
if ( V_147 & V_151 ) {
#ifdef F_74
struct V_152 V_153 ;
#endif
struct V_154 V_155 ;
void * V_19 ;
int V_29 ;
F_75 ( V_7 , & V_155 ) ;
V_19 = & V_155 ;
V_29 = sizeof( V_155 ) ;
#ifdef F_74
if ( ! V_156 &&
( V_146 -> V_157 & V_158 ) ) {
V_153 . V_159 = V_155 . V_159 ;
V_153 . V_160 = V_155 . V_160 ;
V_19 = & V_153 ;
V_29 = sizeof( V_153 ) ;
}
#endif
F_73 ( V_146 , V_150 , V_151 , V_29 , V_19 ) ;
}
}
static int F_76 ( struct V_161 * V_162 , struct V_86 * V_4 ,
struct V_145 * V_146 , T_3 V_29 , int V_139 )
{
int V_163 = V_139 & V_164 ;
struct V_4 * V_5 = V_4 -> V_5 ;
struct V_6 * V_7 ;
int V_165 , V_93 ;
F_8 ( L_6 , V_4 , V_5 ) ;
if ( V_139 & ( V_166 ) )
return - V_100 ;
if ( V_5 -> V_33 == V_167 )
return 0 ;
V_7 = F_77 ( V_5 , V_139 , V_163 , & V_93 ) ;
if ( ! V_7 )
return V_93 ;
V_165 = V_7 -> V_29 ;
if ( V_29 < V_165 ) {
V_146 -> V_157 |= V_168 ;
V_165 = V_29 ;
}
F_78 ( V_7 ) ;
V_93 = F_79 ( V_7 , 0 , V_146 -> V_169 , V_165 ) ;
switch ( F_3 ( V_5 ) -> V_35 ) {
case V_36 :
F_72 ( V_5 , V_146 , V_7 ) ;
break;
case V_37 :
case V_43 :
case V_52 :
F_80 ( V_146 , V_5 , V_7 ) ;
break;
}
F_81 ( V_5 , V_7 ) ;
return V_93 ? : V_165 ;
}
static int F_82 ( struct V_161 * V_162 , struct V_86 * V_4 ,
struct V_145 * V_146 , T_3 V_29 )
{
struct V_4 * V_5 = V_4 -> V_5 ;
struct V_26 * V_27 ;
struct V_6 * V_7 ;
int V_93 ;
F_8 ( L_4 , V_4 , V_5 ) ;
if ( V_146 -> V_157 & V_166 )
return - V_100 ;
if ( V_146 -> V_157 & ~ ( V_164 | V_170 | V_171 ) )
return - V_131 ;
if ( V_29 < 4 || V_29 > V_172 )
return - V_131 ;
F_55 ( V_5 ) ;
switch ( F_3 ( V_5 ) -> V_35 ) {
case V_36 :
case V_37 :
break;
case V_43 :
V_93 = F_83 ( V_5 , V_146 , V_29 ) ;
goto V_110;
case V_52 :
V_93 = - V_100 ;
goto V_110;
default:
V_93 = - V_131 ;
goto V_110;
}
V_27 = F_3 ( V_5 ) -> V_27 ;
if ( ! V_27 ) {
V_93 = - V_97 ;
goto V_110;
}
if ( ! F_5 ( V_138 , & V_27 -> V_139 ) ) {
V_93 = - V_173 ;
goto V_110;
}
V_7 = F_84 ( V_5 , V_29 , V_146 -> V_157 & V_164 , & V_93 ) ;
if ( ! V_7 )
goto V_110;
if ( F_85 ( F_24 ( V_7 , V_29 ) , V_146 -> V_169 , V_29 ) ) {
V_93 = - V_94 ;
goto V_174;
}
F_4 ( V_7 ) -> V_13 = * ( ( unsigned char * ) V_7 -> V_19 ) ;
F_86 ( V_7 , 1 ) ;
if ( F_3 ( V_5 ) -> V_35 == V_37 ) {
if ( F_4 ( V_7 ) -> V_13 != V_45 &&
F_4 ( V_7 ) -> V_13 != V_39 &&
F_4 ( V_7 ) -> V_13 != V_40 ) {
V_93 = - V_131 ;
goto V_174;
}
F_87 ( & V_27 -> V_175 , V_7 ) ;
F_88 ( V_27 -> V_176 , & V_27 -> V_177 ) ;
} else if ( F_4 ( V_7 ) -> V_13 == V_45 ) {
T_4 V_22 = F_89 ( V_7 -> V_19 ) ;
T_4 V_178 = F_90 ( V_22 ) ;
T_4 V_179 = F_91 ( V_22 ) ;
if ( ( ( V_178 > V_180 ) ||
! F_1 ( V_179 & V_181 ,
& V_182 . V_183 [ V_178 ] ) ) &&
! F_51 ( V_143 ) ) {
V_93 = - V_103 ;
goto V_174;
}
if ( F_5 ( V_184 , & V_27 -> V_139 ) || ( V_178 == 0x3f ) ) {
F_87 ( & V_27 -> V_175 , V_7 ) ;
F_88 ( V_27 -> V_176 , & V_27 -> V_177 ) ;
} else {
F_4 ( V_7 ) -> V_185 . V_186 = true ;
F_87 ( & V_27 -> V_187 , V_7 ) ;
F_88 ( V_27 -> V_176 , & V_27 -> V_188 ) ;
}
} else {
if ( ! F_51 ( V_143 ) ) {
V_93 = - V_103 ;
goto V_174;
}
F_87 ( & V_27 -> V_175 , V_7 ) ;
F_88 ( V_27 -> V_176 , & V_27 -> V_177 ) ;
}
V_93 = V_29 ;
V_110:
F_56 ( V_5 ) ;
return V_93 ;
V_174:
F_15 ( V_7 ) ;
goto V_110;
}
static int F_92 ( struct V_86 * V_4 , int V_189 , int V_190 ,
char T_1 * V_191 , unsigned int V_29 )
{
struct V_192 V_193 = { . V_22 = 0 } ;
struct V_4 * V_5 = V_4 -> V_5 ;
int V_93 = 0 , V_194 = 0 ;
F_8 ( L_7 , V_5 , V_190 ) ;
F_55 ( V_5 ) ;
if ( F_3 ( V_5 ) -> V_35 != V_36 ) {
V_93 = - V_97 ;
goto V_110;
}
switch ( V_190 ) {
case V_195 :
if ( F_93 ( V_194 , ( int T_1 * ) V_191 ) ) {
V_93 = - V_94 ;
break;
}
if ( V_194 )
F_3 ( V_5 ) -> V_148 |= V_149 ;
else
F_3 ( V_5 ) -> V_148 &= ~ V_149 ;
break;
case V_196 :
if ( F_93 ( V_194 , ( int T_1 * ) V_191 ) ) {
V_93 = - V_94 ;
break;
}
if ( V_194 )
F_3 ( V_5 ) -> V_148 |= V_151 ;
else
F_3 ( V_5 ) -> V_148 &= ~ V_151 ;
break;
case V_197 :
{
struct V_8 * V_198 = & F_3 ( V_5 ) -> V_12 ;
V_193 . V_16 = V_198 -> V_16 ;
V_193 . V_22 = V_198 -> V_22 ;
V_193 . V_21 [ 0 ] = * ( ( V_199 * ) V_198 -> V_21 + 0 ) ;
V_193 . V_21 [ 1 ] = * ( ( V_199 * ) V_198 -> V_21 + 1 ) ;
}
V_29 = F_66 (unsigned int, len, sizeof(uf)) ;
if ( F_44 ( & V_193 , V_191 , V_29 ) ) {
V_93 = - V_94 ;
break;
}
if ( ! F_51 ( V_143 ) ) {
V_193 . V_16 &= V_182 . V_16 ;
V_193 . V_21 [ 0 ] &= * ( ( V_199 * ) V_182 . V_21 + 0 ) ;
V_193 . V_21 [ 1 ] &= * ( ( V_199 * ) V_182 . V_21 + 1 ) ;
}
{
struct V_8 * V_198 = & F_3 ( V_5 ) -> V_12 ;
V_198 -> V_16 = V_193 . V_16 ;
V_198 -> V_22 = V_193 . V_22 ;
* ( ( V_199 * ) V_198 -> V_21 + 0 ) = V_193 . V_21 [ 0 ] ;
* ( ( V_199 * ) V_198 -> V_21 + 1 ) = V_193 . V_21 [ 1 ] ;
}
break;
default:
V_93 = - V_200 ;
break;
}
V_110:
F_56 ( V_5 ) ;
return V_93 ;
}
static int F_94 ( struct V_86 * V_4 , int V_189 , int V_190 ,
char T_1 * V_191 , int T_1 * V_201 )
{
struct V_192 V_193 ;
struct V_4 * V_5 = V_4 -> V_5 ;
int V_29 , V_194 , V_93 = 0 ;
F_8 ( L_7 , V_5 , V_190 ) ;
if ( F_93 ( V_29 , V_201 ) )
return - V_94 ;
F_55 ( V_5 ) ;
if ( F_3 ( V_5 ) -> V_35 != V_36 ) {
V_93 = - V_97 ;
goto V_110;
}
switch ( V_190 ) {
case V_195 :
if ( F_3 ( V_5 ) -> V_148 & V_149 )
V_194 = 1 ;
else
V_194 = 0 ;
if ( F_95 ( V_194 , V_191 ) )
V_93 = - V_94 ;
break;
case V_196 :
if ( F_3 ( V_5 ) -> V_148 & V_151 )
V_194 = 1 ;
else
V_194 = 0 ;
if ( F_95 ( V_194 , V_191 ) )
V_93 = - V_94 ;
break;
case V_197 :
{
struct V_8 * V_198 = & F_3 ( V_5 ) -> V_12 ;
memset ( & V_193 , 0 , sizeof( V_193 ) ) ;
V_193 . V_16 = V_198 -> V_16 ;
V_193 . V_22 = V_198 -> V_22 ;
V_193 . V_21 [ 0 ] = * ( ( V_199 * ) V_198 -> V_21 + 0 ) ;
V_193 . V_21 [ 1 ] = * ( ( V_199 * ) V_198 -> V_21 + 1 ) ;
}
V_29 = F_66 (unsigned int, len, sizeof(uf)) ;
if ( F_96 ( V_191 , & V_193 , V_29 ) )
V_93 = - V_94 ;
break;
default:
V_93 = - V_200 ;
break;
}
V_110:
F_56 ( V_5 ) ;
return V_93 ;
}
static int F_97 ( struct V_202 * V_202 , struct V_86 * V_4 , int V_203 ,
int V_204 )
{
struct V_4 * V_5 ;
F_8 ( L_8 , V_4 ) ;
if ( V_4 -> type != V_205 )
return - V_206 ;
V_4 -> V_207 = & V_208 ;
V_5 = F_98 ( V_202 , V_209 , V_41 , & V_210 ) ;
if ( ! V_5 )
return - V_211 ;
F_99 ( V_4 , V_5 ) ;
F_100 ( V_5 , V_212 ) ;
V_5 -> V_213 = V_203 ;
V_4 -> V_214 = V_215 ;
V_5 -> V_33 = V_84 ;
F_101 ( & V_30 , V_5 ) ;
return 0 ;
}
int T_5 F_102 ( void )
{
int V_93 ;
V_93 = F_103 ( & V_210 , 0 ) ;
if ( V_93 < 0 )
return V_93 ;
V_93 = F_104 ( V_216 , & V_217 ) ;
if ( V_93 < 0 ) {
F_105 ( L_9 ) ;
goto error;
}
V_93 = F_106 ( & V_218 , L_10 , & V_30 , NULL ) ;
if ( V_93 < 0 ) {
F_105 ( L_11 ) ;
F_107 ( V_216 ) ;
goto error;
}
F_108 ( L_12 ) ;
return 0 ;
error:
F_109 ( & V_210 ) ;
return V_93 ;
}
void F_110 ( void )
{
F_111 ( & V_218 , L_10 ) ;
F_107 ( V_216 ) ;
F_109 ( & V_210 ) ;
}
