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
if ( F_11 ( V_9 ) -> V_15 == V_16 )
V_12 = 0 ;
else
V_12 = F_11 ( V_9 ) -> V_15 & V_17 ;
if ( ! F_7 ( V_12 , & V_11 -> V_18 ) )
return true ;
if ( F_11 ( V_9 ) -> V_15 != V_19 )
return false ;
V_13 = ( * ( V_20 * ) V_9 -> V_21 & V_22 ) ;
if ( ! F_9 ( V_13 , & V_11 -> V_23 ) )
return true ;
if ( ! V_11 -> V_24 )
return false ;
if ( V_13 == V_25 &&
V_11 -> V_24 != F_12 ( ( V_26 * ) ( V_9 -> V_21 + 3 ) ) )
return true ;
if ( V_13 == V_27 &&
V_11 -> V_24 != F_12 ( ( V_26 * ) ( V_9 -> V_21 + 4 ) ) )
return true ;
return false ;
}
void F_13 ( struct V_28 * V_29 , struct V_8 * V_9 )
{
struct V_1 * V_2 ;
struct V_8 * V_30 = NULL ;
F_14 ( L_1 , V_29 , V_9 -> V_31 ) ;
F_15 ( & V_32 . V_33 ) ;
F_16 (sk, &hci_sk_list.head) {
struct V_8 * V_34 ;
if ( V_2 -> V_35 != V_36 || F_3 ( V_2 ) -> V_29 != V_29 )
continue;
if ( V_9 -> V_2 == V_2 )
continue;
if ( F_3 ( V_2 ) -> V_5 == V_37 ) {
if ( F_10 ( V_2 , V_9 ) )
continue;
} else if ( F_3 ( V_2 ) -> V_5 == V_38 ) {
if ( ! F_11 ( V_9 ) -> V_39 )
continue;
if ( F_11 ( V_9 ) -> V_15 != V_19 &&
F_11 ( V_9 ) -> V_15 != V_40 &&
F_11 ( V_9 ) -> V_15 != V_41 )
continue;
} else {
continue;
}
if ( ! V_30 ) {
V_30 = F_17 ( V_9 , 1 , V_42 , true ) ;
if ( ! V_30 )
continue;
memcpy ( F_18 ( V_30 , 1 ) , & F_11 ( V_9 ) -> V_15 , 1 ) ;
}
V_34 = F_19 ( V_30 , V_42 ) ;
if ( ! V_34 )
continue;
if ( F_20 ( V_2 , V_34 ) )
F_21 ( V_34 ) ;
}
F_22 ( & V_32 . V_33 ) ;
F_21 ( V_30 ) ;
}
void F_23 ( unsigned short V_5 , struct V_8 * V_9 ,
int V_43 , struct V_1 * V_44 )
{
struct V_1 * V_2 ;
F_14 ( L_2 , V_5 , V_9 -> V_31 ) ;
F_15 ( & V_32 . V_33 ) ;
F_16 (sk, &hci_sk_list.head) {
struct V_8 * V_34 ;
if ( ! F_6 ( V_2 , V_43 ) )
continue;
if ( V_2 == V_44 )
continue;
if ( V_2 -> V_35 != V_36 )
continue;
if ( F_3 ( V_2 ) -> V_5 != V_5 )
continue;
V_34 = F_19 ( V_9 , V_42 ) ;
if ( ! V_34 )
continue;
if ( F_20 ( V_2 , V_34 ) )
F_21 ( V_34 ) ;
}
F_22 ( & V_32 . V_33 ) ;
}
void F_24 ( struct V_28 * V_29 , struct V_8 * V_9 )
{
struct V_8 * V_30 = NULL ;
struct V_45 * V_46 ;
V_26 V_24 ;
if ( ! F_25 ( & V_47 ) )
return;
F_14 ( L_1 , V_29 , V_9 -> V_31 ) ;
switch ( F_11 ( V_9 ) -> V_15 ) {
case V_48 :
V_24 = F_26 ( V_49 ) ;
break;
case V_19 :
V_24 = F_26 ( V_50 ) ;
break;
case V_40 :
if ( F_11 ( V_9 ) -> V_39 )
V_24 = F_26 ( V_51 ) ;
else
V_24 = F_26 ( V_52 ) ;
break;
case V_41 :
if ( F_11 ( V_9 ) -> V_39 )
V_24 = F_26 ( V_53 ) ;
else
V_24 = F_26 ( V_54 ) ;
break;
default:
return;
}
V_30 = F_17 ( V_9 , V_55 , V_42 , true ) ;
if ( ! V_30 )
return;
V_46 = ( void * ) F_18 ( V_30 , V_55 ) ;
V_46 -> V_24 = V_24 ;
V_46 -> V_56 = F_26 ( V_29 -> V_57 ) ;
V_46 -> V_31 = F_26 ( V_9 -> V_31 ) ;
F_23 ( V_58 , V_30 ,
V_59 , NULL ) ;
F_21 ( V_30 ) ;
}
static struct V_8 * F_27 ( struct V_28 * V_29 , int V_60 )
{
struct V_45 * V_46 ;
struct V_61 * V_62 ;
struct V_8 * V_9 ;
V_26 V_24 ;
switch ( V_60 ) {
case V_63 :
V_9 = F_28 ( V_64 , V_42 ) ;
if ( ! V_9 )
return NULL ;
V_62 = ( void * ) F_29 ( V_9 , V_64 ) ;
V_62 -> type = V_29 -> V_65 ;
V_62 -> V_66 = V_29 -> V_66 ;
F_30 ( & V_62 -> V_67 , & V_29 -> V_67 ) ;
memcpy ( V_62 -> V_68 , V_29 -> V_68 , 8 ) ;
V_24 = F_26 ( V_69 ) ;
break;
case V_70 :
V_9 = F_28 ( 0 , V_42 ) ;
if ( ! V_9 )
return NULL ;
V_24 = F_26 ( V_71 ) ;
break;
default:
return NULL ;
}
F_31 ( V_9 ) ;
V_46 = ( void * ) F_18 ( V_9 , V_55 ) ;
V_46 -> V_24 = V_24 ;
V_46 -> V_56 = F_26 ( V_29 -> V_57 ) ;
V_46 -> V_31 = F_26 ( V_9 -> V_31 - V_55 ) ;
return V_9 ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_28 * V_29 ;
F_15 ( & V_72 ) ;
F_33 (hdev, &hci_dev_list, list) {
struct V_8 * V_9 ;
V_9 = F_27 ( V_29 , V_63 ) ;
if ( ! V_9 )
continue;
if ( F_20 ( V_2 , V_9 ) )
F_21 ( V_9 ) ;
}
F_22 ( & V_72 ) ;
}
static void F_34 ( struct V_28 * V_29 , int type , int V_73 , void * V_21 )
{
struct V_74 * V_46 ;
struct V_75 * V_76 ;
struct V_8 * V_9 ;
V_9 = F_28 ( V_77 + sizeof( * V_76 ) + V_73 , V_42 ) ;
if ( ! V_9 )
return;
V_46 = ( void * ) F_29 ( V_9 , V_77 ) ;
V_46 -> V_78 = V_79 ;
V_46 -> V_80 = sizeof( * V_76 ) + V_73 ;
V_76 = ( void * ) F_29 ( V_9 , sizeof( * V_76 ) + V_73 ) ;
V_76 -> type = type ;
memcpy ( V_76 -> V_21 , V_21 , V_73 ) ;
F_11 ( V_9 ) -> V_39 = 1 ;
F_31 ( V_9 ) ;
F_11 ( V_9 ) -> V_15 = V_19 ;
F_13 ( V_29 , V_9 ) ;
F_21 ( V_9 ) ;
}
void F_35 ( struct V_28 * V_29 , int V_60 )
{
struct V_81 V_76 ;
F_14 ( L_3 , V_29 -> V_68 , V_60 ) ;
if ( F_25 ( & V_47 ) ) {
struct V_8 * V_9 ;
V_9 = F_27 ( V_29 , V_60 ) ;
if ( V_9 ) {
F_23 ( V_58 , V_9 ,
V_59 , NULL ) ;
F_21 ( V_9 ) ;
}
}
V_76 . V_60 = V_60 ;
V_76 . V_82 = V_29 -> V_57 ;
F_34 ( NULL , V_83 , sizeof( V_76 ) , & V_76 ) ;
if ( V_60 == V_70 ) {
struct V_1 * V_2 ;
F_15 ( & V_32 . V_33 ) ;
F_16 (sk, &hci_sk_list.head) {
F_36 ( V_2 ) ;
if ( F_3 ( V_2 ) -> V_29 == V_29 ) {
F_3 ( V_2 ) -> V_29 = NULL ;
V_2 -> V_84 = V_85 ;
V_2 -> V_35 = V_86 ;
V_2 -> V_87 ( V_2 ) ;
F_37 ( V_29 ) ;
}
F_38 ( V_2 ) ;
}
F_22 ( & V_32 . V_33 ) ;
}
}
static struct V_88 * F_39 ( unsigned short V_5 )
{
struct V_88 * V_89 ;
F_33 (c, &mgmt_chan_list, list) {
if ( V_89 -> V_5 == V_5 )
return V_89 ;
}
return NULL ;
}
static struct V_88 * F_40 ( unsigned short V_5 )
{
struct V_88 * V_89 ;
F_41 ( & V_90 ) ;
V_89 = F_39 ( V_5 ) ;
F_42 ( & V_90 ) ;
return V_89 ;
}
int F_43 ( struct V_88 * V_89 )
{
if ( V_89 -> V_5 < V_91 )
return - V_92 ;
F_41 ( & V_90 ) ;
if ( F_39 ( V_89 -> V_5 ) ) {
F_42 ( & V_90 ) ;
return - V_93 ;
}
F_44 ( & V_89 -> V_94 , & V_95 ) ;
F_42 ( & V_90 ) ;
return 0 ;
}
void F_45 ( struct V_88 * V_89 )
{
F_41 ( & V_90 ) ;
F_46 ( & V_89 -> V_94 ) ;
F_42 ( & V_90 ) ;
}
static int F_47 ( struct V_96 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_28 * V_29 ;
F_14 ( L_4 , V_1 , V_2 ) ;
if ( ! V_2 )
return 0 ;
V_29 = F_3 ( V_2 ) -> V_29 ;
if ( F_3 ( V_2 ) -> V_5 == V_58 )
F_48 ( & V_47 ) ;
F_49 ( & V_32 , V_2 ) ;
if ( V_29 ) {
if ( F_3 ( V_2 ) -> V_5 == V_38 ) {
F_50 ( V_29 ) ;
F_51 ( V_29 , V_97 ) ;
F_52 ( V_29 -> V_57 ) ;
}
F_48 ( & V_29 -> V_98 ) ;
F_37 ( V_29 ) ;
}
F_53 ( V_2 ) ;
F_54 ( & V_2 -> V_99 ) ;
F_54 ( & V_2 -> V_100 ) ;
F_55 ( V_2 ) ;
return 0 ;
}
static int F_56 ( struct V_28 * V_29 , void T_1 * V_101 )
{
T_2 V_67 ;
int V_102 ;
if ( F_57 ( & V_67 , V_101 , sizeof( V_67 ) ) )
return - V_103 ;
F_58 ( V_29 ) ;
V_102 = F_59 ( & V_29 -> V_104 , & V_67 , V_105 ) ;
F_60 ( V_29 ) ;
return V_102 ;
}
static int F_61 ( struct V_28 * V_29 , void T_1 * V_101 )
{
T_2 V_67 ;
int V_102 ;
if ( F_57 ( & V_67 , V_101 , sizeof( V_67 ) ) )
return - V_103 ;
F_58 ( V_29 ) ;
V_102 = F_62 ( & V_29 -> V_104 , & V_67 , V_105 ) ;
F_60 ( V_29 ) ;
return V_102 ;
}
static int F_63 ( struct V_1 * V_2 , unsigned int V_106 ,
unsigned long V_101 )
{
struct V_28 * V_29 = F_3 ( V_2 ) -> V_29 ;
if ( ! V_29 )
return - V_107 ;
if ( F_64 ( V_29 , V_97 ) )
return - V_108 ;
if ( F_64 ( V_29 , V_109 ) )
return - V_110 ;
if ( V_29 -> V_65 != V_111 )
return - V_110 ;
switch ( V_106 ) {
case V_112 :
if ( ! F_65 ( V_113 ) )
return - V_114 ;
return - V_110 ;
case V_115 :
return F_66 ( V_29 , ( void T_1 * ) V_101 ) ;
case V_116 :
return F_67 ( V_29 , ( void T_1 * ) V_101 ) ;
case V_117 :
if ( ! F_65 ( V_113 ) )
return - V_114 ;
return F_56 ( V_29 , ( void T_1 * ) V_101 ) ;
case V_118 :
if ( ! F_65 ( V_113 ) )
return - V_114 ;
return F_61 ( V_29 , ( void T_1 * ) V_101 ) ;
}
return - V_119 ;
}
static int F_68 ( struct V_96 * V_1 , unsigned int V_106 ,
unsigned long V_101 )
{
void T_1 * V_120 = ( void T_1 * ) V_101 ;
struct V_1 * V_2 = V_1 -> V_2 ;
int V_102 ;
F_14 ( L_5 , V_106 , V_101 ) ;
F_69 ( V_2 ) ;
if ( F_3 ( V_2 ) -> V_5 != V_37 ) {
V_102 = - V_107 ;
goto V_121;
}
F_70 ( V_2 ) ;
switch ( V_106 ) {
case V_122 :
return F_71 ( V_120 ) ;
case V_123 :
return F_72 ( V_120 ) ;
case V_124 :
return F_73 ( V_120 ) ;
case V_125 :
if ( ! F_65 ( V_113 ) )
return - V_114 ;
return F_74 ( V_101 ) ;
case V_126 :
if ( ! F_65 ( V_113 ) )
return - V_114 ;
return F_52 ( V_101 ) ;
case V_127 :
if ( ! F_65 ( V_113 ) )
return - V_114 ;
return F_75 ( V_101 ) ;
case V_128 :
if ( ! F_65 ( V_113 ) )
return - V_114 ;
return F_76 ( V_101 ) ;
case V_129 :
case V_130 :
case V_131 :
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_136 :
if ( ! F_65 ( V_113 ) )
return - V_114 ;
return F_77 ( V_106 , V_120 ) ;
case V_137 :
return F_78 ( V_120 ) ;
}
F_69 ( V_2 ) ;
V_102 = F_63 ( V_2 , V_106 , V_101 ) ;
V_121:
F_70 ( V_2 ) ;
return V_102 ;
}
static int F_79 ( struct V_96 * V_1 , struct V_138 * V_6 ,
int V_139 )
{
struct V_140 V_141 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_28 * V_29 = NULL ;
int V_31 , V_102 = 0 ;
F_14 ( L_4 , V_1 , V_2 ) ;
if ( ! V_6 )
return - V_92 ;
memset ( & V_141 , 0 , sizeof( V_141 ) ) ;
V_31 = F_80 (unsigned int, sizeof(haddr), addr_len) ;
memcpy ( & V_141 , V_6 , V_31 ) ;
if ( V_141 . V_142 != V_143 )
return - V_92 ;
F_69 ( V_2 ) ;
if ( V_2 -> V_35 == V_36 ) {
V_102 = - V_93 ;
goto V_121;
}
switch ( V_141 . V_144 ) {
case V_37 :
if ( F_3 ( V_2 ) -> V_29 ) {
V_102 = - V_93 ;
goto V_121;
}
if ( V_141 . V_28 != V_145 ) {
V_29 = F_81 ( V_141 . V_28 ) ;
if ( ! V_29 ) {
V_102 = - V_146 ;
goto V_121;
}
F_82 ( & V_29 -> V_98 ) ;
}
F_3 ( V_2 ) -> V_29 = V_29 ;
break;
case V_38 :
if ( F_3 ( V_2 ) -> V_29 ) {
V_102 = - V_93 ;
goto V_121;
}
if ( V_141 . V_28 == V_145 ) {
V_102 = - V_92 ;
goto V_121;
}
if ( ! F_65 ( V_113 ) ) {
V_102 = - V_114 ;
goto V_121;
}
V_29 = F_81 ( V_141 . V_28 ) ;
if ( ! V_29 ) {
V_102 = - V_146 ;
goto V_121;
}
if ( F_7 ( V_147 , & V_29 -> V_4 ) ||
F_7 ( V_148 , & V_29 -> V_4 ) ||
F_64 ( V_29 , V_149 ) ||
F_64 ( V_29 , V_150 ) ) {
V_102 = - V_108 ;
F_37 ( V_29 ) ;
goto V_121;
}
if ( F_83 ( V_29 , V_97 ) ) {
V_102 = - V_151 ;
F_37 ( V_29 ) ;
goto V_121;
}
F_84 ( V_29 ) ;
V_102 = F_74 ( V_29 -> V_57 ) ;
if ( V_102 ) {
F_51 ( V_29 , V_97 ) ;
F_50 ( V_29 ) ;
F_37 ( V_29 ) ;
goto V_121;
}
F_82 ( & V_29 -> V_98 ) ;
F_3 ( V_2 ) -> V_29 = V_29 ;
break;
case V_58 :
if ( V_141 . V_28 != V_145 ) {
V_102 = - V_92 ;
goto V_121;
}
if ( ! F_65 ( V_152 ) ) {
V_102 = - V_114 ;
goto V_121;
}
F_1 ( V_2 , V_59 ) ;
F_32 ( V_2 ) ;
F_82 ( & V_47 ) ;
break;
default:
if ( ! F_40 ( V_141 . V_144 ) ) {
V_102 = - V_92 ;
goto V_121;
}
if ( V_141 . V_28 != V_145 ) {
V_102 = - V_92 ;
goto V_121;
}
if ( F_65 ( V_113 ) )
F_1 ( V_2 , V_59 ) ;
if ( V_141 . V_144 == V_91 ) {
F_1 ( V_2 , V_153 ) ;
F_1 ( V_2 , V_154 ) ;
F_1 ( V_2 , V_155 ) ;
}
break;
}
F_3 ( V_2 ) -> V_5 = V_141 . V_144 ;
V_2 -> V_35 = V_36 ;
V_121:
F_70 ( V_2 ) ;
return V_102 ;
}
static int F_85 ( struct V_96 * V_1 , struct V_138 * V_6 ,
int * V_139 , int V_156 )
{
struct V_140 * V_141 = (struct V_140 * ) V_6 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_28 * V_29 ;
int V_102 = 0 ;
F_14 ( L_4 , V_1 , V_2 ) ;
if ( V_156 )
return - V_110 ;
F_69 ( V_2 ) ;
V_29 = F_3 ( V_2 ) -> V_29 ;
if ( ! V_29 ) {
V_102 = - V_107 ;
goto V_121;
}
* V_139 = sizeof( * V_141 ) ;
V_141 -> V_142 = V_143 ;
V_141 -> V_28 = V_29 -> V_57 ;
V_141 -> V_144 = F_3 ( V_2 ) -> V_5 ;
V_121:
F_70 ( V_2 ) ;
return V_102 ;
}
static void F_86 ( struct V_1 * V_2 , struct V_157 * V_158 ,
struct V_8 * V_9 )
{
V_7 V_159 = F_3 ( V_2 ) -> V_160 ;
if ( V_159 & V_161 ) {
int V_39 = F_11 ( V_9 ) -> V_39 ;
F_87 ( V_158 , V_162 , V_161 , sizeof( V_39 ) ,
& V_39 ) ;
}
if ( V_159 & V_163 ) {
#ifdef F_88
struct V_164 V_165 ;
#endif
struct V_166 V_167 ;
void * V_21 ;
int V_31 ;
F_89 ( V_9 , & V_167 ) ;
V_21 = & V_167 ;
V_31 = sizeof( V_167 ) ;
#ifdef F_88
if ( ! V_168 &&
( V_158 -> V_169 & V_170 ) ) {
V_165 . V_171 = V_167 . V_171 ;
V_165 . V_172 = V_167 . V_172 ;
V_21 = & V_165 ;
V_31 = sizeof( V_165 ) ;
}
#endif
F_87 ( V_158 , V_162 , V_163 , V_31 , V_21 ) ;
}
}
static int F_90 ( struct V_96 * V_1 , struct V_157 * V_158 , T_3 V_31 ,
int V_4 )
{
int V_173 = V_4 & V_174 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_8 * V_9 ;
int V_175 , V_102 ;
F_14 ( L_6 , V_1 , V_2 ) ;
if ( V_4 & ( V_176 ) )
return - V_110 ;
if ( V_2 -> V_35 == V_177 )
return 0 ;
V_9 = F_91 ( V_2 , V_4 , V_173 , & V_102 ) ;
if ( ! V_9 )
return V_102 ;
V_175 = V_9 -> V_31 ;
if ( V_31 < V_175 ) {
V_158 -> V_169 |= V_178 ;
V_175 = V_31 ;
}
F_92 ( V_9 ) ;
V_102 = F_93 ( V_9 , 0 , V_158 , V_175 ) ;
switch ( F_3 ( V_2 ) -> V_5 ) {
case V_37 :
F_86 ( V_2 , V_158 , V_9 ) ;
break;
case V_38 :
case V_58 :
F_94 ( V_158 , V_2 , V_9 ) ;
break;
default:
if ( F_40 ( F_3 ( V_2 ) -> V_5 ) )
F_94 ( V_158 , V_2 , V_9 ) ;
break;
}
F_95 ( V_2 , V_9 ) ;
return V_102 ? : V_175 ;
}
static int F_96 ( struct V_88 * V_179 , struct V_1 * V_2 ,
struct V_157 * V_158 , T_3 V_180 )
{
void * V_181 ;
T_4 * V_182 ;
struct V_183 * V_46 ;
T_5 V_24 , V_56 , V_31 ;
struct V_28 * V_29 = NULL ;
const struct V_184 * V_185 ;
bool V_186 , V_187 ;
int V_102 ;
F_14 ( L_7 , V_180 ) ;
if ( V_180 < sizeof( * V_46 ) )
return - V_92 ;
V_181 = F_97 ( V_180 , V_188 ) ;
if ( ! V_181 )
return - V_189 ;
if ( F_98 ( V_181 , V_158 , V_180 ) ) {
V_102 = - V_103 ;
goto V_121;
}
V_46 = V_181 ;
V_24 = F_99 ( V_46 -> V_24 ) ;
V_56 = F_99 ( V_46 -> V_56 ) ;
V_31 = F_99 ( V_46 -> V_31 ) ;
if ( V_31 != V_180 - sizeof( * V_46 ) ) {
V_102 = - V_92 ;
goto V_121;
}
if ( V_24 >= V_179 -> V_190 ||
V_179 -> V_191 [ V_24 ] . V_192 == NULL ) {
F_14 ( L_8 , V_24 ) ;
V_102 = F_100 ( V_2 , V_56 , V_24 ,
V_193 ) ;
goto V_121;
}
V_185 = & V_179 -> V_191 [ V_24 ] ;
if ( ! F_6 ( V_2 , V_59 ) &&
! ( V_185 -> V_4 & V_194 ) ) {
V_102 = F_100 ( V_2 , V_56 , V_24 ,
V_195 ) ;
goto V_121;
}
if ( V_56 != V_196 ) {
V_29 = F_81 ( V_56 ) ;
if ( ! V_29 ) {
V_102 = F_100 ( V_2 , V_56 , V_24 ,
V_197 ) ;
goto V_121;
}
if ( F_64 ( V_29 , V_149 ) ||
F_64 ( V_29 , V_150 ) ||
F_64 ( V_29 , V_97 ) ) {
V_102 = F_100 ( V_2 , V_56 , V_24 ,
V_197 ) ;
goto V_121;
}
if ( F_64 ( V_29 , V_109 ) &&
! ( V_185 -> V_4 & V_198 ) ) {
V_102 = F_100 ( V_2 , V_56 , V_24 ,
V_197 ) ;
goto V_121;
}
}
V_187 = ( V_185 -> V_4 & V_199 ) ;
if ( V_187 != ! V_29 ) {
V_102 = F_100 ( V_2 , V_56 , V_24 ,
V_197 ) ;
goto V_121;
}
V_186 = ( V_185 -> V_4 & V_200 ) ;
if ( ( V_186 && V_31 < V_185 -> V_201 ) ||
( ! V_186 && V_31 != V_185 -> V_201 ) ) {
V_102 = F_100 ( V_2 , V_56 , V_24 ,
V_202 ) ;
goto V_121;
}
if ( V_29 && V_179 -> V_203 )
V_179 -> V_203 ( V_2 , V_29 ) ;
V_182 = V_181 + sizeof( * V_46 ) ;
V_102 = V_185 -> V_192 ( V_2 , V_29 , V_182 , V_31 ) ;
if ( V_102 < 0 )
goto V_121;
V_102 = V_180 ;
V_121:
if ( V_29 )
F_37 ( V_29 ) ;
F_101 ( V_181 ) ;
return V_102 ;
}
static int F_102 ( struct V_96 * V_1 , struct V_157 * V_158 ,
T_3 V_31 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_88 * V_179 ;
struct V_28 * V_29 ;
struct V_8 * V_9 ;
int V_102 ;
F_14 ( L_4 , V_1 , V_2 ) ;
if ( V_158 -> V_169 & V_176 )
return - V_110 ;
if ( V_158 -> V_169 & ~ ( V_174 | V_204 | V_205 ) )
return - V_92 ;
if ( V_31 < 4 || V_31 > V_206 )
return - V_92 ;
F_69 ( V_2 ) ;
switch ( F_3 ( V_2 ) -> V_5 ) {
case V_37 :
case V_38 :
break;
case V_58 :
V_102 = - V_110 ;
goto V_121;
default:
F_41 ( & V_90 ) ;
V_179 = F_39 ( F_3 ( V_2 ) -> V_5 ) ;
if ( V_179 )
V_102 = F_96 ( V_179 , V_2 , V_158 , V_31 ) ;
else
V_102 = - V_92 ;
F_42 ( & V_90 ) ;
goto V_121;
}
V_29 = F_3 ( V_2 ) -> V_29 ;
if ( ! V_29 ) {
V_102 = - V_107 ;
goto V_121;
}
if ( ! F_7 ( V_147 , & V_29 -> V_4 ) ) {
V_102 = - V_207 ;
goto V_121;
}
V_9 = F_103 ( V_2 , V_31 , V_158 -> V_169 & V_174 , & V_102 ) ;
if ( ! V_9 )
goto V_121;
if ( F_98 ( F_29 ( V_9 , V_31 ) , V_158 , V_31 ) ) {
V_102 = - V_103 ;
goto V_208;
}
F_11 ( V_9 ) -> V_15 = * ( ( unsigned char * ) V_9 -> V_21 ) ;
F_104 ( V_9 , 1 ) ;
if ( F_3 ( V_2 ) -> V_5 == V_38 ) {
if ( F_11 ( V_9 ) -> V_15 != V_48 &&
F_11 ( V_9 ) -> V_15 != V_40 &&
F_11 ( V_9 ) -> V_15 != V_41 ) {
V_102 = - V_92 ;
goto V_208;
}
F_105 ( & V_29 -> V_209 , V_9 ) ;
F_106 ( V_29 -> V_210 , & V_29 -> V_211 ) ;
} else if ( F_11 ( V_9 ) -> V_15 == V_48 ) {
T_5 V_24 = F_107 ( V_9 -> V_21 ) ;
T_5 V_212 = F_108 ( V_24 ) ;
T_5 V_213 = F_109 ( V_24 ) ;
if ( ( ( V_212 > V_214 ) ||
! F_9 ( V_213 & V_215 ,
& V_216 . V_217 [ V_212 ] ) ) &&
! F_65 ( V_152 ) ) {
V_102 = - V_114 ;
goto V_208;
}
if ( V_212 == 0x3f ) {
F_105 ( & V_29 -> V_209 , V_9 ) ;
F_106 ( V_29 -> V_210 , & V_29 -> V_211 ) ;
} else {
F_11 ( V_9 ) -> V_218 . V_219 = true ;
F_105 ( & V_29 -> V_220 , V_9 ) ;
F_106 ( V_29 -> V_210 , & V_29 -> V_221 ) ;
}
} else {
if ( ! F_65 ( V_152 ) ) {
V_102 = - V_114 ;
goto V_208;
}
F_105 ( & V_29 -> V_209 , V_9 ) ;
F_106 ( V_29 -> V_210 , & V_29 -> V_211 ) ;
}
V_102 = V_31 ;
V_121:
F_70 ( V_2 ) ;
return V_102 ;
V_208:
F_21 ( V_9 ) ;
goto V_121;
}
static int F_110 ( struct V_96 * V_1 , int V_222 , int V_223 ,
char T_1 * V_224 , unsigned int V_31 )
{
struct V_225 V_226 = { . V_24 = 0 } ;
struct V_1 * V_2 = V_1 -> V_2 ;
int V_102 = 0 , V_227 = 0 ;
F_14 ( L_9 , V_2 , V_223 ) ;
F_69 ( V_2 ) ;
if ( F_3 ( V_2 ) -> V_5 != V_37 ) {
V_102 = - V_107 ;
goto V_121;
}
switch ( V_223 ) {
case V_228 :
if ( F_111 ( V_227 , ( int T_1 * ) V_224 ) ) {
V_102 = - V_103 ;
break;
}
if ( V_227 )
F_3 ( V_2 ) -> V_160 |= V_161 ;
else
F_3 ( V_2 ) -> V_160 &= ~ V_161 ;
break;
case V_229 :
if ( F_111 ( V_227 , ( int T_1 * ) V_224 ) ) {
V_102 = - V_103 ;
break;
}
if ( V_227 )
F_3 ( V_2 ) -> V_160 |= V_163 ;
else
F_3 ( V_2 ) -> V_160 &= ~ V_163 ;
break;
case V_230 :
{
struct V_10 * V_231 = & F_3 ( V_2 ) -> V_14 ;
V_226 . V_18 = V_231 -> V_18 ;
V_226 . V_24 = V_231 -> V_24 ;
V_226 . V_23 [ 0 ] = * ( ( V_232 * ) V_231 -> V_23 + 0 ) ;
V_226 . V_23 [ 1 ] = * ( ( V_232 * ) V_231 -> V_23 + 1 ) ;
}
V_31 = F_80 (unsigned int, len, sizeof(uf)) ;
if ( F_57 ( & V_226 , V_224 , V_31 ) ) {
V_102 = - V_103 ;
break;
}
if ( ! F_65 ( V_152 ) ) {
V_226 . V_18 &= V_216 . V_18 ;
V_226 . V_23 [ 0 ] &= * ( ( V_232 * ) V_216 . V_23 + 0 ) ;
V_226 . V_23 [ 1 ] &= * ( ( V_232 * ) V_216 . V_23 + 1 ) ;
}
{
struct V_10 * V_231 = & F_3 ( V_2 ) -> V_14 ;
V_231 -> V_18 = V_226 . V_18 ;
V_231 -> V_24 = V_226 . V_24 ;
* ( ( V_232 * ) V_231 -> V_23 + 0 ) = V_226 . V_23 [ 0 ] ;
* ( ( V_232 * ) V_231 -> V_23 + 1 ) = V_226 . V_23 [ 1 ] ;
}
break;
default:
V_102 = - V_233 ;
break;
}
V_121:
F_70 ( V_2 ) ;
return V_102 ;
}
static int F_112 ( struct V_96 * V_1 , int V_222 , int V_223 ,
char T_1 * V_224 , int T_1 * V_234 )
{
struct V_225 V_226 ;
struct V_1 * V_2 = V_1 -> V_2 ;
int V_31 , V_227 , V_102 = 0 ;
F_14 ( L_9 , V_2 , V_223 ) ;
if ( F_111 ( V_31 , V_234 ) )
return - V_103 ;
F_69 ( V_2 ) ;
if ( F_3 ( V_2 ) -> V_5 != V_37 ) {
V_102 = - V_107 ;
goto V_121;
}
switch ( V_223 ) {
case V_228 :
if ( F_3 ( V_2 ) -> V_160 & V_161 )
V_227 = 1 ;
else
V_227 = 0 ;
if ( F_113 ( V_227 , V_224 ) )
V_102 = - V_103 ;
break;
case V_229 :
if ( F_3 ( V_2 ) -> V_160 & V_163 )
V_227 = 1 ;
else
V_227 = 0 ;
if ( F_113 ( V_227 , V_224 ) )
V_102 = - V_103 ;
break;
case V_230 :
{
struct V_10 * V_231 = & F_3 ( V_2 ) -> V_14 ;
memset ( & V_226 , 0 , sizeof( V_226 ) ) ;
V_226 . V_18 = V_231 -> V_18 ;
V_226 . V_24 = V_231 -> V_24 ;
V_226 . V_23 [ 0 ] = * ( ( V_232 * ) V_231 -> V_23 + 0 ) ;
V_226 . V_23 [ 1 ] = * ( ( V_232 * ) V_231 -> V_23 + 1 ) ;
}
V_31 = F_80 (unsigned int, len, sizeof(uf)) ;
if ( F_114 ( V_224 , & V_226 , V_31 ) )
V_102 = - V_103 ;
break;
default:
V_102 = - V_233 ;
break;
}
V_121:
F_70 ( V_2 ) ;
return V_102 ;
}
static int F_115 ( struct V_235 * V_235 , struct V_96 * V_1 , int V_236 ,
int V_237 )
{
struct V_1 * V_2 ;
F_14 ( L_10 , V_1 ) ;
if ( V_1 -> type != V_238 )
return - V_239 ;
V_1 -> V_240 = & V_241 ;
V_2 = F_116 ( V_235 , V_242 , V_42 , & V_243 ) ;
if ( ! V_2 )
return - V_189 ;
F_117 ( V_1 , V_2 ) ;
F_118 ( V_2 , V_244 ) ;
V_2 -> V_245 = V_236 ;
V_1 -> V_246 = V_247 ;
V_2 -> V_35 = V_86 ;
F_119 ( & V_32 , V_2 ) ;
return 0 ;
}
int T_6 F_120 ( void )
{
int V_102 ;
F_121 ( sizeof( struct V_140 ) > sizeof( struct V_138 ) ) ;
V_102 = F_122 ( & V_243 , 0 ) ;
if ( V_102 < 0 )
return V_102 ;
V_102 = F_123 ( V_248 , & V_249 ) ;
if ( V_102 < 0 ) {
F_124 ( L_11 ) ;
goto error;
}
V_102 = F_125 ( & V_250 , L_12 , & V_32 , NULL ) ;
if ( V_102 < 0 ) {
F_124 ( L_13 ) ;
F_126 ( V_248 ) ;
goto error;
}
F_127 ( L_14 ) ;
return 0 ;
error:
F_128 ( & V_243 ) ;
return V_102 ;
}
void F_129 ( void )
{
F_130 ( & V_250 , L_12 ) ;
F_126 ( V_248 ) ;
F_128 ( & V_243 ) ;
}
