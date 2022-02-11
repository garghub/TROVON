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
T_1 F_9 ( struct V_1 * V_2 )
{
return F_3 ( V_2 ) -> V_6 ;
}
static bool F_10 ( struct V_1 * V_2 )
{
int V_7 = F_3 ( V_2 ) -> V_6 ;
if ( ! V_7 ) {
V_7 = F_11 ( & V_8 , 1 , 0 , V_9 ) ;
if ( V_7 < 0 )
V_7 = 0xffffffff ;
F_3 ( V_2 ) -> V_6 = V_7 ;
F_12 ( F_3 ( V_2 ) -> V_10 , V_11 ) ;
return true ;
}
return false ;
}
static void F_13 ( struct V_1 * V_2 )
{
int V_7 = F_3 ( V_2 ) -> V_6 ;
if ( V_7 ) {
F_3 ( V_2 ) -> V_6 = 0xffffffff ;
F_14 ( & V_8 , V_7 ) ;
}
}
static inline int F_15 ( int V_3 , const void * V_12 )
{
return * ( ( const V_13 * ) V_12 + ( V_3 >> 5 ) ) & ( ( V_13 ) 1 << ( V_3 & 31 ) ) ;
}
static bool F_16 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_16 * V_17 ;
int V_18 , V_19 ;
V_17 = & F_3 ( V_2 ) -> V_20 ;
V_18 = F_17 ( V_15 ) & V_21 ;
if ( ! F_7 ( V_18 , & V_17 -> V_22 ) )
return true ;
if ( F_17 ( V_15 ) != V_23 )
return false ;
V_19 = ( * ( V_24 * ) V_15 -> V_25 & V_26 ) ;
if ( ! F_15 ( V_19 , & V_17 -> V_27 ) )
return true ;
if ( ! V_17 -> V_28 )
return false ;
if ( V_19 == V_29 &&
V_17 -> V_28 != F_18 ( ( V_30 * ) ( V_15 -> V_25 + 3 ) ) )
return true ;
if ( V_19 == V_31 &&
V_17 -> V_28 != F_18 ( ( V_30 * ) ( V_15 -> V_25 + 4 ) ) )
return true ;
return false ;
}
void F_19 ( struct V_32 * V_33 , struct V_14 * V_15 )
{
struct V_1 * V_2 ;
struct V_14 * V_34 = NULL ;
F_20 ( L_1 , V_33 , V_15 -> V_35 ) ;
F_21 ( & V_36 . V_37 ) ;
F_22 (sk, &hci_sk_list.head) {
struct V_14 * V_38 ;
if ( V_2 -> V_39 != V_40 || F_3 ( V_2 ) -> V_33 != V_33 )
continue;
if ( V_15 -> V_2 == V_2 )
continue;
if ( F_3 ( V_2 ) -> V_5 == V_41 ) {
if ( F_17 ( V_15 ) != V_42 &&
F_17 ( V_15 ) != V_23 &&
F_17 ( V_15 ) != V_43 &&
F_17 ( V_15 ) != V_44 )
continue;
if ( F_16 ( V_2 , V_15 ) )
continue;
} else if ( F_3 ( V_2 ) -> V_5 == V_45 ) {
if ( ! F_23 ( V_15 ) -> V_46 )
continue;
if ( F_17 ( V_15 ) != V_23 &&
F_17 ( V_15 ) != V_43 &&
F_17 ( V_15 ) != V_44 )
continue;
} else {
continue;
}
if ( ! V_34 ) {
V_34 = F_24 ( V_15 , 1 , V_47 , true ) ;
if ( ! V_34 )
continue;
memcpy ( F_25 ( V_34 , 1 ) , & F_17 ( V_15 ) , 1 ) ;
}
V_38 = F_26 ( V_34 , V_47 ) ;
if ( ! V_38 )
continue;
if ( F_27 ( V_2 , V_38 ) )
F_28 ( V_38 ) ;
}
F_29 ( & V_36 . V_37 ) ;
F_28 ( V_34 ) ;
}
void F_30 ( unsigned short V_5 , struct V_14 * V_15 ,
int V_48 , struct V_1 * V_49 )
{
struct V_1 * V_2 ;
F_20 ( L_2 , V_5 , V_15 -> V_35 ) ;
F_21 ( & V_36 . V_37 ) ;
F_22 (sk, &hci_sk_list.head) {
struct V_14 * V_38 ;
if ( ! F_6 ( V_2 , V_48 ) )
continue;
if ( V_2 == V_49 )
continue;
if ( V_2 -> V_39 != V_40 )
continue;
if ( F_3 ( V_2 ) -> V_5 != V_5 )
continue;
V_38 = F_26 ( V_15 , V_47 ) ;
if ( ! V_38 )
continue;
if ( F_27 ( V_2 , V_38 ) )
F_28 ( V_38 ) ;
}
F_29 ( & V_36 . V_37 ) ;
}
void F_31 ( struct V_32 * V_33 , struct V_14 * V_15 )
{
struct V_14 * V_34 = NULL ;
struct V_50 * V_51 ;
V_30 V_28 ;
if ( ! F_32 ( & V_52 ) )
return;
F_20 ( L_1 , V_33 , V_15 -> V_35 ) ;
switch ( F_17 ( V_15 ) ) {
case V_42 :
V_28 = F_33 ( V_53 ) ;
break;
case V_23 :
V_28 = F_33 ( V_54 ) ;
break;
case V_43 :
if ( F_23 ( V_15 ) -> V_46 )
V_28 = F_33 ( V_55 ) ;
else
V_28 = F_33 ( V_56 ) ;
break;
case V_44 :
if ( F_23 ( V_15 ) -> V_46 )
V_28 = F_33 ( V_57 ) ;
else
V_28 = F_33 ( V_58 ) ;
break;
case V_59 :
V_28 = F_33 ( V_60 ) ;
break;
default:
return;
}
V_34 = F_24 ( V_15 , V_61 , V_47 , true ) ;
if ( ! V_34 )
return;
V_51 = ( void * ) F_25 ( V_34 , V_61 ) ;
V_51 -> V_28 = V_28 ;
V_51 -> V_62 = F_33 ( V_33 -> V_7 ) ;
V_51 -> V_35 = F_33 ( V_15 -> V_35 ) ;
F_30 ( V_63 , V_34 ,
V_64 , NULL ) ;
F_28 ( V_34 ) ;
}
void F_34 ( struct V_32 * V_33 , T_2 V_65 ,
void * V_25 , T_2 V_66 , T_3 V_67 ,
int V_48 , struct V_1 * V_49 )
{
struct V_1 * V_2 ;
V_30 V_62 ;
if ( V_33 )
V_62 = F_33 ( V_33 -> V_7 ) ;
else
V_62 = F_33 ( V_68 ) ;
F_21 ( & V_36 . V_37 ) ;
F_22 (sk, &hci_sk_list.head) {
struct V_50 * V_51 ;
struct V_14 * V_15 ;
if ( F_3 ( V_2 ) -> V_5 != V_69 )
continue;
if ( ! F_6 ( V_2 , V_48 ) )
continue;
if ( V_2 == V_49 )
continue;
V_15 = F_35 ( 6 + V_66 , V_47 ) ;
if ( ! V_15 )
continue;
F_36 ( F_3 ( V_2 ) -> V_6 , F_37 ( V_15 , 4 ) ) ;
F_38 ( V_65 , F_37 ( V_15 , 2 ) ) ;
if ( V_25 )
memcpy ( F_37 ( V_15 , V_66 ) , V_25 , V_66 ) ;
V_15 -> V_67 = V_67 ;
V_51 = ( void * ) F_25 ( V_15 , V_61 ) ;
V_51 -> V_28 = F_33 ( V_70 ) ;
V_51 -> V_62 = V_62 ;
V_51 -> V_35 = F_33 ( V_15 -> V_35 - V_61 ) ;
F_30 ( V_63 , V_15 ,
V_64 , NULL ) ;
F_28 ( V_15 ) ;
}
F_29 ( & V_36 . V_37 ) ;
}
static struct V_14 * F_39 ( struct V_32 * V_33 , int V_65 )
{
struct V_50 * V_51 ;
struct V_71 * V_72 ;
struct V_73 * V_74 ;
struct V_14 * V_15 ;
V_30 V_28 ;
switch ( V_65 ) {
case V_75 :
V_15 = F_35 ( V_76 , V_47 ) ;
if ( ! V_15 )
return NULL ;
V_72 = ( void * ) F_37 ( V_15 , V_76 ) ;
V_72 -> type = V_33 -> V_77 ;
V_72 -> V_78 = V_33 -> V_78 ;
F_40 ( & V_72 -> V_79 , & V_33 -> V_79 ) ;
memcpy ( V_72 -> V_80 , V_33 -> V_80 , 8 ) ;
V_28 = F_33 ( V_81 ) ;
break;
case V_82 :
V_15 = F_35 ( 0 , V_47 ) ;
if ( ! V_15 )
return NULL ;
V_28 = F_33 ( V_83 ) ;
break;
case V_84 :
if ( V_33 -> V_85 == 0xffff )
return NULL ;
case V_86 :
V_15 = F_35 ( V_87 , V_47 ) ;
if ( ! V_15 )
return NULL ;
V_74 = ( void * ) F_37 ( V_15 , V_87 ) ;
F_40 ( & V_74 -> V_79 , & V_33 -> V_79 ) ;
V_74 -> V_85 = F_33 ( V_33 -> V_85 ) ;
V_28 = F_33 ( V_88 ) ;
break;
case V_89 :
V_15 = F_35 ( 0 , V_47 ) ;
if ( ! V_15 )
return NULL ;
V_28 = F_33 ( V_90 ) ;
break;
case V_91 :
V_15 = F_35 ( 0 , V_47 ) ;
if ( ! V_15 )
return NULL ;
V_28 = F_33 ( V_92 ) ;
break;
default:
return NULL ;
}
F_41 ( V_15 ) ;
V_51 = ( void * ) F_25 ( V_15 , V_61 ) ;
V_51 -> V_28 = V_28 ;
V_51 -> V_62 = F_33 ( V_33 -> V_7 ) ;
V_51 -> V_35 = F_33 ( V_15 -> V_35 - V_61 ) ;
return V_15 ;
}
static struct V_14 * F_42 ( struct V_1 * V_2 )
{
struct V_50 * V_51 ;
struct V_14 * V_15 ;
T_2 V_93 ;
T_4 V_94 [ 3 ] ;
T_1 V_4 ;
if ( ! F_3 ( V_2 ) -> V_6 )
return NULL ;
switch ( F_3 ( V_2 ) -> V_5 ) {
case V_41 :
V_93 = 0x0000 ;
V_94 [ 0 ] = V_95 ;
F_38 ( V_96 , V_94 + 1 ) ;
break;
case V_45 :
V_93 = 0x0001 ;
V_94 [ 0 ] = V_95 ;
F_38 ( V_96 , V_94 + 1 ) ;
break;
case V_69 :
V_93 = 0x0002 ;
F_43 ( V_94 ) ;
break;
default:
return NULL ;
}
V_15 = F_35 ( 14 + V_97 , V_47 ) ;
if ( ! V_15 )
return NULL ;
V_4 = F_6 ( V_2 , V_64 ) ? 0x1 : 0x0 ;
F_36 ( F_3 ( V_2 ) -> V_6 , F_37 ( V_15 , 4 ) ) ;
F_38 ( V_93 , F_37 ( V_15 , 2 ) ) ;
memcpy ( F_37 ( V_15 , sizeof( V_94 ) ) , V_94 , sizeof( V_94 ) ) ;
F_36 ( V_4 , F_37 ( V_15 , 4 ) ) ;
* F_37 ( V_15 , 1 ) = V_97 ;
memcpy ( F_37 ( V_15 , V_97 ) , F_3 ( V_2 ) -> V_10 , V_97 ) ;
F_41 ( V_15 ) ;
V_51 = ( void * ) F_25 ( V_15 , V_61 ) ;
V_51 -> V_28 = F_33 ( V_98 ) ;
if ( F_3 ( V_2 ) -> V_33 )
V_51 -> V_62 = F_33 ( F_3 ( V_2 ) -> V_33 -> V_7 ) ;
else
V_51 -> V_62 = F_33 ( V_99 ) ;
V_51 -> V_35 = F_33 ( V_15 -> V_35 - V_61 ) ;
return V_15 ;
}
static struct V_14 * F_44 ( struct V_1 * V_2 )
{
struct V_50 * V_51 ;
struct V_14 * V_15 ;
if ( ! F_3 ( V_2 ) -> V_6 )
return NULL ;
switch ( F_3 ( V_2 ) -> V_5 ) {
case V_41 :
case V_45 :
case V_69 :
break;
default:
return NULL ;
}
V_15 = F_35 ( 4 , V_47 ) ;
if ( ! V_15 )
return NULL ;
F_36 ( F_3 ( V_2 ) -> V_6 , F_37 ( V_15 , 4 ) ) ;
F_41 ( V_15 ) ;
V_51 = ( void * ) F_25 ( V_15 , V_61 ) ;
V_51 -> V_28 = F_33 ( V_100 ) ;
if ( F_3 ( V_2 ) -> V_33 )
V_51 -> V_62 = F_33 ( F_3 ( V_2 ) -> V_33 -> V_7 ) ;
else
V_51 -> V_62 = F_33 ( V_99 ) ;
V_51 -> V_35 = F_33 ( V_15 -> V_35 - V_61 ) ;
return V_15 ;
}
static struct V_14 * F_45 ( struct V_1 * V_2 , T_2 V_62 ,
T_2 V_28 , T_2 V_35 ,
const void * V_101 )
{
struct V_50 * V_51 ;
struct V_14 * V_15 ;
V_15 = F_35 ( 6 + V_35 , V_47 ) ;
if ( ! V_15 )
return NULL ;
F_36 ( F_3 ( V_2 ) -> V_6 , F_37 ( V_15 , 4 ) ) ;
F_38 ( V_28 , F_37 ( V_15 , 2 ) ) ;
if ( V_101 )
memcpy ( F_37 ( V_15 , V_35 ) , V_101 , V_35 ) ;
F_41 ( V_15 ) ;
V_51 = ( void * ) F_25 ( V_15 , V_61 ) ;
V_51 -> V_28 = F_33 ( V_102 ) ;
V_51 -> V_62 = F_33 ( V_62 ) ;
V_51 -> V_35 = F_33 ( V_15 -> V_35 - V_61 ) ;
return V_15 ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_32 * V_33 ;
F_21 ( & V_103 ) ;
F_47 (hdev, &hci_dev_list, list) {
struct V_14 * V_15 ;
V_15 = F_39 ( V_33 , V_75 ) ;
if ( ! V_15 )
continue;
if ( F_27 ( V_2 , V_15 ) )
F_28 ( V_15 ) ;
if ( ! F_7 ( V_104 , & V_33 -> V_4 ) )
continue;
V_15 = F_39 ( V_33 , V_89 ) ;
if ( ! V_15 )
continue;
if ( F_27 ( V_2 , V_15 ) )
F_28 ( V_15 ) ;
if ( F_7 ( V_105 , & V_33 -> V_4 ) )
V_15 = F_39 ( V_33 , V_86 ) ;
else if ( F_48 ( V_33 , V_106 ) )
V_15 = F_39 ( V_33 , V_84 ) ;
else
V_15 = NULL ;
if ( V_15 ) {
if ( F_27 ( V_2 , V_15 ) )
F_28 ( V_15 ) ;
}
}
F_29 ( & V_103 ) ;
}
static void F_49 ( struct V_1 * V_107 )
{
struct V_1 * V_2 ;
F_21 ( & V_36 . V_37 ) ;
F_22 (sk, &hci_sk_list.head) {
struct V_14 * V_15 ;
V_15 = F_42 ( V_2 ) ;
if ( ! V_15 )
continue;
if ( F_27 ( V_107 , V_15 ) )
F_28 ( V_15 ) ;
}
F_29 ( & V_36 . V_37 ) ;
}
static void F_50 ( struct V_32 * V_33 , int type , int V_108 , void * V_25 )
{
struct V_109 * V_51 ;
struct V_110 * V_111 ;
struct V_14 * V_15 ;
V_15 = F_35 ( V_112 + sizeof( * V_111 ) + V_108 , V_47 ) ;
if ( ! V_15 )
return;
V_51 = ( void * ) F_37 ( V_15 , V_112 ) ;
V_51 -> V_113 = V_114 ;
V_51 -> V_115 = sizeof( * V_111 ) + V_108 ;
V_111 = ( void * ) F_37 ( V_15 , sizeof( * V_111 ) + V_108 ) ;
V_111 -> type = type ;
memcpy ( V_111 -> V_25 , V_25 , V_108 ) ;
F_23 ( V_15 ) -> V_46 = 1 ;
F_41 ( V_15 ) ;
F_17 ( V_15 ) = V_23 ;
F_19 ( V_33 , V_15 ) ;
F_28 ( V_15 ) ;
}
void F_51 ( struct V_32 * V_33 , int V_65 )
{
F_20 ( L_3 , V_33 -> V_80 , V_65 ) ;
if ( F_32 ( & V_52 ) ) {
struct V_14 * V_15 ;
V_15 = F_39 ( V_33 , V_65 ) ;
if ( V_15 ) {
F_30 ( V_63 , V_15 ,
V_64 , NULL ) ;
F_28 ( V_15 ) ;
}
}
if ( V_65 <= V_116 ) {
struct V_117 V_111 ;
V_111 . V_65 = V_65 ;
V_111 . V_118 = V_33 -> V_7 ;
F_50 ( NULL , V_119 , sizeof( V_111 ) , & V_111 ) ;
}
if ( V_65 == V_82 ) {
struct V_1 * V_2 ;
F_21 ( & V_36 . V_37 ) ;
F_22 (sk, &hci_sk_list.head) {
F_52 ( V_2 ) ;
if ( F_3 ( V_2 ) -> V_33 == V_33 ) {
F_3 ( V_2 ) -> V_33 = NULL ;
V_2 -> V_120 = V_121 ;
V_2 -> V_39 = V_122 ;
V_2 -> V_123 ( V_2 ) ;
F_53 ( V_33 ) ;
}
F_54 ( V_2 ) ;
}
F_29 ( & V_36 . V_37 ) ;
}
}
static struct V_124 * F_55 ( unsigned short V_5 )
{
struct V_124 * V_125 ;
F_47 (c, &mgmt_chan_list, list) {
if ( V_125 -> V_5 == V_5 )
return V_125 ;
}
return NULL ;
}
static struct V_124 * F_56 ( unsigned short V_5 )
{
struct V_124 * V_125 ;
F_57 ( & V_126 ) ;
V_125 = F_55 ( V_5 ) ;
F_58 ( & V_126 ) ;
return V_125 ;
}
int F_59 ( struct V_124 * V_125 )
{
if ( V_125 -> V_5 < V_69 )
return - V_127 ;
F_57 ( & V_126 ) ;
if ( F_55 ( V_125 -> V_5 ) ) {
F_58 ( & V_126 ) ;
return - V_128 ;
}
F_60 ( & V_125 -> V_129 , & V_130 ) ;
F_58 ( & V_126 ) ;
return 0 ;
}
void F_61 ( struct V_124 * V_125 )
{
F_57 ( & V_126 ) ;
F_62 ( & V_125 -> V_129 ) ;
F_58 ( & V_126 ) ;
}
static int F_63 ( struct V_131 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_32 * V_33 ;
struct V_14 * V_15 ;
F_20 ( L_4 , V_1 , V_2 ) ;
if ( ! V_2 )
return 0 ;
V_33 = F_3 ( V_2 ) -> V_33 ;
switch ( F_3 ( V_2 ) -> V_5 ) {
case V_63 :
F_64 ( & V_52 ) ;
break;
case V_41 :
case V_45 :
case V_69 :
V_15 = F_44 ( V_2 ) ;
if ( V_15 ) {
F_30 ( V_63 , V_15 ,
V_64 , NULL ) ;
F_28 ( V_15 ) ;
}
F_13 ( V_2 ) ;
break;
}
F_65 ( & V_36 , V_2 ) ;
if ( V_33 ) {
if ( F_3 ( V_2 ) -> V_5 == V_45 ) {
F_66 ( V_33 ) ;
F_67 ( V_33 , V_132 ) ;
F_68 ( V_33 ) ;
}
F_64 ( & V_33 -> V_133 ) ;
F_53 ( V_33 ) ;
}
F_69 ( V_2 ) ;
F_70 ( & V_2 -> V_134 ) ;
F_70 ( & V_2 -> V_135 ) ;
F_71 ( V_2 ) ;
return 0 ;
}
static int F_72 ( struct V_32 * V_33 , void T_5 * V_136 )
{
T_6 V_79 ;
int V_137 ;
if ( F_73 ( & V_79 , V_136 , sizeof( V_79 ) ) )
return - V_138 ;
F_74 ( V_33 ) ;
V_137 = F_75 ( & V_33 -> V_139 , & V_79 , V_140 ) ;
F_76 ( V_33 ) ;
return V_137 ;
}
static int F_77 ( struct V_32 * V_33 , void T_5 * V_136 )
{
T_6 V_79 ;
int V_137 ;
if ( F_73 ( & V_79 , V_136 , sizeof( V_79 ) ) )
return - V_138 ;
F_74 ( V_33 ) ;
V_137 = F_78 ( & V_33 -> V_139 , & V_79 , V_140 ) ;
F_76 ( V_33 ) ;
return V_137 ;
}
static int F_79 ( struct V_1 * V_2 , unsigned int V_141 ,
unsigned long V_136 )
{
struct V_32 * V_33 = F_3 ( V_2 ) -> V_33 ;
if ( ! V_33 )
return - V_142 ;
if ( F_48 ( V_33 , V_132 ) )
return - V_143 ;
if ( F_48 ( V_33 , V_144 ) )
return - V_145 ;
if ( V_33 -> V_77 != V_146 )
return - V_145 ;
switch ( V_141 ) {
case V_147 :
if ( ! F_80 ( V_148 ) )
return - V_149 ;
return - V_145 ;
case V_150 :
return F_81 ( V_33 , ( void T_5 * ) V_136 ) ;
case V_151 :
return F_82 ( V_33 , ( void T_5 * ) V_136 ) ;
case V_152 :
if ( ! F_80 ( V_148 ) )
return - V_149 ;
return F_72 ( V_33 , ( void T_5 * ) V_136 ) ;
case V_153 :
if ( ! F_80 ( V_148 ) )
return - V_149 ;
return F_77 ( V_33 , ( void T_5 * ) V_136 ) ;
}
return - V_154 ;
}
static int F_83 ( struct V_131 * V_1 , unsigned int V_141 ,
unsigned long V_136 )
{
void T_5 * V_155 = ( void T_5 * ) V_136 ;
struct V_1 * V_2 = V_1 -> V_2 ;
int V_137 ;
F_20 ( L_5 , V_141 , V_136 ) ;
F_84 ( V_2 ) ;
if ( F_3 ( V_2 ) -> V_5 != V_41 ) {
V_137 = - V_142 ;
goto V_156;
}
if ( F_10 ( V_2 ) ) {
struct V_14 * V_15 ;
if ( F_80 ( V_148 ) )
F_1 ( V_2 , V_64 ) ;
V_15 = F_42 ( V_2 ) ;
if ( V_15 ) {
F_30 ( V_63 , V_15 ,
V_64 , NULL ) ;
F_28 ( V_15 ) ;
}
}
F_85 ( V_2 ) ;
switch ( V_141 ) {
case V_157 :
return F_86 ( V_155 ) ;
case V_158 :
return F_87 ( V_155 ) ;
case V_159 :
return F_88 ( V_155 ) ;
case V_160 :
if ( ! F_80 ( V_148 ) )
return - V_149 ;
return F_89 ( V_136 ) ;
case V_161 :
if ( ! F_80 ( V_148 ) )
return - V_149 ;
return F_90 ( V_136 ) ;
case V_162 :
if ( ! F_80 ( V_148 ) )
return - V_149 ;
return F_91 ( V_136 ) ;
case V_163 :
if ( ! F_80 ( V_148 ) )
return - V_149 ;
return F_92 ( V_136 ) ;
case V_164 :
case V_165 :
case V_166 :
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
if ( ! F_80 ( V_148 ) )
return - V_149 ;
return F_93 ( V_141 , V_155 ) ;
case V_172 :
return F_94 ( V_155 ) ;
}
F_84 ( V_2 ) ;
V_137 = F_79 ( V_2 , V_141 , V_136 ) ;
V_156:
F_85 ( V_2 ) ;
return V_137 ;
}
static int F_95 ( struct V_131 * V_1 , struct V_173 * V_12 ,
int V_174 )
{
struct V_175 V_176 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_32 * V_33 = NULL ;
struct V_14 * V_15 ;
int V_35 , V_137 = 0 ;
F_20 ( L_4 , V_1 , V_2 ) ;
if ( ! V_12 )
return - V_127 ;
memset ( & V_176 , 0 , sizeof( V_176 ) ) ;
V_35 = F_96 (unsigned int, sizeof(haddr), addr_len) ;
memcpy ( & V_176 , V_12 , V_35 ) ;
if ( V_176 . V_177 != V_178 )
return - V_127 ;
F_84 ( V_2 ) ;
if ( V_2 -> V_39 == V_40 ) {
V_137 = - V_128 ;
goto V_156;
}
switch ( V_176 . V_179 ) {
case V_41 :
if ( F_3 ( V_2 ) -> V_33 ) {
V_137 = - V_128 ;
goto V_156;
}
if ( V_176 . V_32 != V_99 ) {
V_33 = F_97 ( V_176 . V_32 ) ;
if ( ! V_33 ) {
V_137 = - V_180 ;
goto V_156;
}
F_98 ( & V_33 -> V_133 ) ;
}
F_3 ( V_2 ) -> V_5 = V_176 . V_179 ;
if ( ! F_10 ( V_2 ) ) {
V_15 = F_44 ( V_2 ) ;
if ( V_15 ) {
F_30 ( V_63 , V_15 ,
V_64 , NULL ) ;
F_28 ( V_15 ) ;
}
}
if ( F_80 ( V_148 ) )
F_1 ( V_2 , V_64 ) ;
F_3 ( V_2 ) -> V_33 = V_33 ;
V_15 = F_42 ( V_2 ) ;
if ( V_15 ) {
F_30 ( V_63 , V_15 ,
V_64 , NULL ) ;
F_28 ( V_15 ) ;
}
break;
case V_45 :
if ( F_3 ( V_2 ) -> V_33 ) {
V_137 = - V_128 ;
goto V_156;
}
if ( V_176 . V_32 == V_99 ) {
V_137 = - V_127 ;
goto V_156;
}
if ( ! F_80 ( V_148 ) ) {
V_137 = - V_149 ;
goto V_156;
}
V_33 = F_97 ( V_176 . V_32 ) ;
if ( ! V_33 ) {
V_137 = - V_180 ;
goto V_156;
}
if ( F_7 ( V_181 , & V_33 -> V_4 ) ||
F_48 ( V_33 , V_106 ) ||
F_48 ( V_33 , V_182 ) ||
( ! F_48 ( V_33 , V_183 ) &&
F_7 ( V_105 , & V_33 -> V_4 ) ) ) {
V_137 = - V_143 ;
F_53 ( V_33 ) ;
goto V_156;
}
if ( F_99 ( V_33 , V_132 ) ) {
V_137 = - V_184 ;
F_53 ( V_33 ) ;
goto V_156;
}
F_100 ( V_33 ) ;
V_137 = F_89 ( V_33 -> V_7 ) ;
if ( V_137 ) {
if ( V_137 == - V_128 ) {
V_137 = 0 ;
} else {
F_67 ( V_33 , V_132 ) ;
F_68 ( V_33 ) ;
F_53 ( V_33 ) ;
goto V_156;
}
}
F_3 ( V_2 ) -> V_5 = V_176 . V_179 ;
if ( ! F_10 ( V_2 ) ) {
V_15 = F_44 ( V_2 ) ;
if ( V_15 ) {
F_30 ( V_63 , V_15 ,
V_64 , NULL ) ;
F_28 ( V_15 ) ;
}
}
F_1 ( V_2 , V_64 ) ;
F_3 ( V_2 ) -> V_33 = V_33 ;
V_15 = F_42 ( V_2 ) ;
if ( V_15 ) {
F_30 ( V_63 , V_15 ,
V_64 , NULL ) ;
F_28 ( V_15 ) ;
}
F_98 ( & V_33 -> V_133 ) ;
break;
case V_63 :
if ( V_176 . V_32 != V_99 ) {
V_137 = - V_127 ;
goto V_156;
}
if ( ! F_80 ( V_185 ) ) {
V_137 = - V_149 ;
goto V_156;
}
F_3 ( V_2 ) -> V_5 = V_176 . V_179 ;
F_1 ( V_2 , V_64 ) ;
F_101 ( V_2 , L_6 ,
F_102 () -> V_186 ,
F_102 () -> V_187 ) ;
F_101 ( V_2 , L_7 ,
V_95 , V_96 ) ;
F_46 ( V_2 ) ;
F_49 ( V_2 ) ;
F_98 ( & V_52 ) ;
break;
case V_188 :
if ( V_176 . V_32 != V_99 ) {
V_137 = - V_127 ;
goto V_156;
}
if ( ! F_80 ( V_148 ) ) {
V_137 = - V_149 ;
goto V_156;
}
F_3 ( V_2 ) -> V_5 = V_176 . V_179 ;
break;
default:
if ( ! F_56 ( V_176 . V_179 ) ) {
V_137 = - V_127 ;
goto V_156;
}
if ( V_176 . V_32 != V_99 ) {
V_137 = - V_127 ;
goto V_156;
}
if ( F_80 ( V_148 ) )
F_1 ( V_2 , V_64 ) ;
F_3 ( V_2 ) -> V_5 = V_176 . V_179 ;
if ( F_3 ( V_2 ) -> V_5 == V_69 ) {
if ( ! F_10 ( V_2 ) ) {
V_15 = F_44 ( V_2 ) ;
if ( V_15 ) {
F_30 ( V_63 , V_15 ,
V_64 , NULL ) ;
F_28 ( V_15 ) ;
}
}
V_15 = F_42 ( V_2 ) ;
if ( V_15 ) {
F_30 ( V_63 , V_15 ,
V_64 , NULL ) ;
F_28 ( V_15 ) ;
}
F_1 ( V_2 , V_189 ) ;
F_1 ( V_2 , V_190 ) ;
F_1 ( V_2 , V_191 ) ;
F_1 ( V_2 , V_192 ) ;
F_1 ( V_2 , V_193 ) ;
F_1 ( V_2 , V_194 ) ;
}
break;
}
V_2 -> V_39 = V_40 ;
V_156:
F_85 ( V_2 ) ;
return V_137 ;
}
static int F_103 ( struct V_131 * V_1 , struct V_173 * V_12 ,
int * V_174 , int V_195 )
{
struct V_175 * V_176 = (struct V_175 * ) V_12 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_32 * V_33 ;
int V_137 = 0 ;
F_20 ( L_4 , V_1 , V_2 ) ;
if ( V_195 )
return - V_145 ;
F_84 ( V_2 ) ;
V_33 = F_3 ( V_2 ) -> V_33 ;
if ( ! V_33 ) {
V_137 = - V_142 ;
goto V_156;
}
* V_174 = sizeof( * V_176 ) ;
V_176 -> V_177 = V_178 ;
V_176 -> V_32 = V_33 -> V_7 ;
V_176 -> V_179 = F_3 ( V_2 ) -> V_5 ;
V_156:
F_85 ( V_2 ) ;
return V_137 ;
}
static void F_104 ( struct V_1 * V_2 , struct V_196 * V_197 ,
struct V_14 * V_15 )
{
V_13 V_198 = F_3 ( V_2 ) -> V_199 ;
if ( V_198 & V_200 ) {
int V_46 = F_23 ( V_15 ) -> V_46 ;
F_105 ( V_197 , V_201 , V_200 , sizeof( V_46 ) ,
& V_46 ) ;
}
if ( V_198 & V_202 ) {
#ifdef F_106
struct V_203 V_204 ;
#endif
struct V_205 V_206 ;
void * V_25 ;
int V_35 ;
F_107 ( V_15 , & V_206 ) ;
V_25 = & V_206 ;
V_35 = sizeof( V_206 ) ;
#ifdef F_106
if ( ! V_207 &&
( V_197 -> V_208 & V_209 ) ) {
V_204 . V_210 = V_206 . V_210 ;
V_204 . V_211 = V_206 . V_211 ;
V_25 = & V_204 ;
V_35 = sizeof( V_204 ) ;
}
#endif
F_105 ( V_197 , V_201 , V_202 , V_35 , V_25 ) ;
}
}
static int F_108 ( struct V_131 * V_1 , struct V_196 * V_197 ,
T_7 V_35 , int V_4 )
{
int V_212 = V_4 & V_213 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_14 * V_15 ;
int V_214 , V_137 ;
unsigned int V_215 ;
F_20 ( L_8 , V_1 , V_2 ) ;
if ( V_4 & V_216 )
return - V_145 ;
if ( F_3 ( V_2 ) -> V_5 == V_188 )
return - V_145 ;
if ( V_2 -> V_39 == V_217 )
return 0 ;
V_15 = F_109 ( V_2 , V_4 , V_212 , & V_137 ) ;
if ( ! V_15 )
return V_137 ;
V_215 = V_15 -> V_35 ;
V_214 = V_15 -> V_35 ;
if ( V_35 < V_214 ) {
V_197 -> V_208 |= V_218 ;
V_214 = V_35 ;
}
F_110 ( V_15 ) ;
V_137 = F_111 ( V_15 , 0 , V_197 , V_214 ) ;
switch ( F_3 ( V_2 ) -> V_5 ) {
case V_41 :
F_104 ( V_2 , V_197 , V_15 ) ;
break;
case V_45 :
case V_63 :
F_112 ( V_197 , V_2 , V_15 ) ;
break;
default:
if ( F_56 ( F_3 ( V_2 ) -> V_5 ) )
F_112 ( V_197 , V_2 , V_15 ) ;
break;
}
F_113 ( V_2 , V_15 ) ;
if ( V_4 & V_218 )
V_214 = V_215 ;
return V_137 ? : V_214 ;
}
static int F_114 ( struct V_124 * V_219 , struct V_1 * V_2 ,
struct V_196 * V_197 , T_7 V_220 )
{
void * V_101 ;
T_4 * V_221 ;
struct V_222 * V_51 ;
T_2 V_28 , V_62 , V_35 ;
struct V_32 * V_33 = NULL ;
const struct V_223 * V_224 ;
bool V_225 , V_226 ;
int V_137 ;
F_20 ( L_9 , V_220 ) ;
if ( V_220 < sizeof( * V_51 ) )
return - V_127 ;
V_101 = F_115 ( V_220 , V_9 ) ;
if ( ! V_101 )
return - V_227 ;
if ( F_116 ( V_101 , V_197 , V_220 ) ) {
V_137 = - V_138 ;
goto V_156;
}
V_51 = V_101 ;
V_28 = F_117 ( V_51 -> V_28 ) ;
V_62 = F_117 ( V_51 -> V_62 ) ;
V_35 = F_117 ( V_51 -> V_35 ) ;
if ( V_35 != V_220 - sizeof( * V_51 ) ) {
V_137 = - V_127 ;
goto V_156;
}
if ( V_219 -> V_5 == V_69 ) {
struct V_14 * V_15 ;
V_15 = F_45 ( V_2 , V_62 , V_28 , V_35 ,
V_101 + sizeof( * V_51 ) ) ;
if ( V_15 ) {
F_30 ( V_63 , V_15 ,
V_64 , NULL ) ;
F_28 ( V_15 ) ;
}
}
if ( V_28 >= V_219 -> V_228 ||
V_219 -> V_229 [ V_28 ] . V_230 == NULL ) {
F_20 ( L_10 , V_28 ) ;
V_137 = F_118 ( V_2 , V_62 , V_28 ,
V_231 ) ;
goto V_156;
}
V_224 = & V_219 -> V_229 [ V_28 ] ;
if ( ! F_6 ( V_2 , V_64 ) &&
! ( V_224 -> V_4 & V_232 ) ) {
V_137 = F_118 ( V_2 , V_62 , V_28 ,
V_233 ) ;
goto V_156;
}
if ( V_62 != V_68 ) {
V_33 = F_97 ( V_62 ) ;
if ( ! V_33 ) {
V_137 = F_118 ( V_2 , V_62 , V_28 ,
V_234 ) ;
goto V_156;
}
if ( F_48 ( V_33 , V_106 ) ||
F_48 ( V_33 , V_182 ) ||
F_48 ( V_33 , V_132 ) ) {
V_137 = F_118 ( V_2 , V_62 , V_28 ,
V_234 ) ;
goto V_156;
}
if ( F_48 ( V_33 , V_144 ) &&
! ( V_224 -> V_4 & V_235 ) ) {
V_137 = F_118 ( V_2 , V_62 , V_28 ,
V_234 ) ;
goto V_156;
}
}
V_226 = ( V_224 -> V_4 & V_236 ) ;
if ( V_226 != ! V_33 ) {
V_137 = F_118 ( V_2 , V_62 , V_28 ,
V_234 ) ;
goto V_156;
}
V_225 = ( V_224 -> V_4 & V_237 ) ;
if ( ( V_225 && V_35 < V_224 -> V_66 ) ||
( ! V_225 && V_35 != V_224 -> V_66 ) ) {
V_137 = F_118 ( V_2 , V_62 , V_28 ,
V_238 ) ;
goto V_156;
}
if ( V_33 && V_219 -> V_239 )
V_219 -> V_239 ( V_2 , V_33 ) ;
V_221 = V_101 + sizeof( * V_51 ) ;
V_137 = V_224 -> V_230 ( V_2 , V_33 , V_221 , V_35 ) ;
if ( V_137 < 0 )
goto V_156;
V_137 = V_220 ;
V_156:
if ( V_33 )
F_53 ( V_33 ) ;
F_119 ( V_101 ) ;
return V_137 ;
}
static int F_120 ( struct V_1 * V_2 , struct V_196 * V_197 , int V_35 )
{
struct V_50 * V_51 ;
struct V_14 * V_15 ;
struct V_32 * V_33 ;
T_2 V_62 ;
int V_137 ;
if ( V_35 < sizeof( * V_51 ) + 3 )
return - V_127 ;
V_15 = F_121 ( V_2 , V_35 , V_197 -> V_208 & V_213 , & V_137 ) ;
if ( ! V_15 )
return V_137 ;
if ( F_116 ( F_37 ( V_15 , V_35 ) , V_197 , V_35 ) ) {
V_137 = - V_138 ;
goto V_240;
}
V_51 = ( void * ) V_15 -> V_25 ;
if ( F_117 ( V_51 -> V_35 ) != V_35 - sizeof( * V_51 ) ) {
V_137 = - V_127 ;
goto V_240;
}
if ( F_117 ( V_51 -> V_28 ) == 0x0000 ) {
V_24 V_241 = V_15 -> V_25 [ sizeof( * V_51 ) ] ;
V_24 V_242 = V_15 -> V_25 [ sizeof( * V_51 ) + 1 ] ;
if ( V_241 > 7 || V_15 -> V_25 [ V_35 - 1 ] != 0x00 ||
V_242 > V_35 - sizeof( * V_51 ) - 3 ||
V_15 -> V_25 [ sizeof( * V_51 ) + V_242 + 1 ] != 0x00 ) {
V_137 = - V_127 ;
goto V_240;
}
} else {
V_137 = - V_127 ;
goto V_240;
}
V_62 = F_117 ( V_51 -> V_62 ) ;
if ( V_62 != V_68 ) {
V_33 = F_97 ( V_62 ) ;
if ( ! V_33 ) {
V_137 = - V_180 ;
goto V_240;
}
} else {
V_33 = NULL ;
}
V_51 -> V_28 = F_33 ( V_243 ) ;
F_30 ( V_63 , V_15 , V_64 , NULL ) ;
V_137 = V_35 ;
if ( V_33 )
F_53 ( V_33 ) ;
V_240:
F_28 ( V_15 ) ;
return V_137 ;
}
static int F_122 ( struct V_131 * V_1 , struct V_196 * V_197 ,
T_7 V_35 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_124 * V_219 ;
struct V_32 * V_33 ;
struct V_14 * V_15 ;
int V_137 ;
F_20 ( L_4 , V_1 , V_2 ) ;
if ( V_197 -> V_208 & V_216 )
return - V_145 ;
if ( V_197 -> V_208 & ~ ( V_213 | V_244 | V_245 |
V_209 ) )
return - V_127 ;
if ( V_35 < 4 || V_35 > V_246 )
return - V_127 ;
F_84 ( V_2 ) ;
switch ( F_3 ( V_2 ) -> V_5 ) {
case V_41 :
case V_45 :
break;
case V_63 :
V_137 = - V_145 ;
goto V_156;
case V_188 :
V_137 = F_120 ( V_2 , V_197 , V_35 ) ;
goto V_156;
default:
F_57 ( & V_126 ) ;
V_219 = F_55 ( F_3 ( V_2 ) -> V_5 ) ;
if ( V_219 )
V_137 = F_114 ( V_219 , V_2 , V_197 , V_35 ) ;
else
V_137 = - V_127 ;
F_58 ( & V_126 ) ;
goto V_156;
}
V_33 = F_3 ( V_2 ) -> V_33 ;
if ( ! V_33 ) {
V_137 = - V_142 ;
goto V_156;
}
if ( ! F_7 ( V_105 , & V_33 -> V_4 ) ) {
V_137 = - V_247 ;
goto V_156;
}
V_15 = F_121 ( V_2 , V_35 , V_197 -> V_208 & V_213 , & V_137 ) ;
if ( ! V_15 )
goto V_156;
if ( F_116 ( F_37 ( V_15 , V_35 ) , V_197 , V_35 ) ) {
V_137 = - V_138 ;
goto V_240;
}
F_17 ( V_15 ) = V_15 -> V_25 [ 0 ] ;
F_123 ( V_15 , 1 ) ;
if ( F_3 ( V_2 ) -> V_5 == V_45 ) {
if ( F_17 ( V_15 ) != V_42 &&
F_17 ( V_15 ) != V_43 &&
F_17 ( V_15 ) != V_44 ) {
V_137 = - V_127 ;
goto V_240;
}
F_124 ( & V_33 -> V_248 , V_15 ) ;
F_125 ( V_33 -> V_249 , & V_33 -> V_250 ) ;
} else if ( F_17 ( V_15 ) == V_42 ) {
T_2 V_28 = F_126 ( V_15 -> V_25 ) ;
T_2 V_251 = F_127 ( V_28 ) ;
T_2 V_252 = F_128 ( V_28 ) ;
if ( ( ( V_251 > V_253 ) ||
! F_15 ( V_252 & V_254 ,
& V_255 . V_256 [ V_251 ] ) ) &&
! F_80 ( V_185 ) ) {
V_137 = - V_149 ;
goto V_240;
}
F_129 ( V_15 ) = V_28 ;
if ( V_251 == 0x3f ) {
F_124 ( & V_33 -> V_248 , V_15 ) ;
F_125 ( V_33 -> V_249 , & V_33 -> V_250 ) ;
} else {
F_23 ( V_15 ) -> V_257 . V_258 |= V_259 ;
F_124 ( & V_33 -> V_260 , V_15 ) ;
F_125 ( V_33 -> V_249 , & V_33 -> V_261 ) ;
}
} else {
if ( ! F_80 ( V_185 ) ) {
V_137 = - V_149 ;
goto V_240;
}
if ( F_17 ( V_15 ) != V_43 &&
F_17 ( V_15 ) != V_44 ) {
V_137 = - V_127 ;
goto V_240;
}
F_124 ( & V_33 -> V_248 , V_15 ) ;
F_125 ( V_33 -> V_249 , & V_33 -> V_250 ) ;
}
V_137 = V_35 ;
V_156:
F_85 ( V_2 ) ;
return V_137 ;
V_240:
F_28 ( V_15 ) ;
goto V_156;
}
static int F_130 ( struct V_131 * V_1 , int V_262 , int V_263 ,
char T_5 * V_264 , unsigned int V_35 )
{
struct V_265 V_266 = { . V_28 = 0 } ;
struct V_1 * V_2 = V_1 -> V_2 ;
int V_137 = 0 , V_267 = 0 ;
F_20 ( L_11 , V_2 , V_263 ) ;
if ( V_262 != V_201 )
return - V_268 ;
F_84 ( V_2 ) ;
if ( F_3 ( V_2 ) -> V_5 != V_41 ) {
V_137 = - V_142 ;
goto V_156;
}
switch ( V_263 ) {
case V_269 :
if ( F_131 ( V_267 , ( int T_5 * ) V_264 ) ) {
V_137 = - V_138 ;
break;
}
if ( V_267 )
F_3 ( V_2 ) -> V_199 |= V_200 ;
else
F_3 ( V_2 ) -> V_199 &= ~ V_200 ;
break;
case V_270 :
if ( F_131 ( V_267 , ( int T_5 * ) V_264 ) ) {
V_137 = - V_138 ;
break;
}
if ( V_267 )
F_3 ( V_2 ) -> V_199 |= V_202 ;
else
F_3 ( V_2 ) -> V_199 &= ~ V_202 ;
break;
case V_271 :
{
struct V_16 * V_272 = & F_3 ( V_2 ) -> V_20 ;
V_266 . V_22 = V_272 -> V_22 ;
V_266 . V_28 = V_272 -> V_28 ;
V_266 . V_27 [ 0 ] = * ( ( T_1 * ) V_272 -> V_27 + 0 ) ;
V_266 . V_27 [ 1 ] = * ( ( T_1 * ) V_272 -> V_27 + 1 ) ;
}
V_35 = F_96 (unsigned int, len, sizeof(uf)) ;
if ( F_73 ( & V_266 , V_264 , V_35 ) ) {
V_137 = - V_138 ;
break;
}
if ( ! F_80 ( V_185 ) ) {
V_266 . V_22 &= V_255 . V_22 ;
V_266 . V_27 [ 0 ] &= * ( ( T_1 * ) V_255 . V_27 + 0 ) ;
V_266 . V_27 [ 1 ] &= * ( ( T_1 * ) V_255 . V_27 + 1 ) ;
}
{
struct V_16 * V_272 = & F_3 ( V_2 ) -> V_20 ;
V_272 -> V_22 = V_266 . V_22 ;
V_272 -> V_28 = V_266 . V_28 ;
* ( ( T_1 * ) V_272 -> V_27 + 0 ) = V_266 . V_27 [ 0 ] ;
* ( ( T_1 * ) V_272 -> V_27 + 1 ) = V_266 . V_27 [ 1 ] ;
}
break;
default:
V_137 = - V_268 ;
break;
}
V_156:
F_85 ( V_2 ) ;
return V_137 ;
}
static int F_132 ( struct V_131 * V_1 , int V_262 , int V_263 ,
char T_5 * V_264 , int T_5 * V_273 )
{
struct V_265 V_266 ;
struct V_1 * V_2 = V_1 -> V_2 ;
int V_35 , V_267 , V_137 = 0 ;
F_20 ( L_11 , V_2 , V_263 ) ;
if ( V_262 != V_201 )
return - V_268 ;
if ( F_131 ( V_35 , V_273 ) )
return - V_138 ;
F_84 ( V_2 ) ;
if ( F_3 ( V_2 ) -> V_5 != V_41 ) {
V_137 = - V_142 ;
goto V_156;
}
switch ( V_263 ) {
case V_269 :
if ( F_3 ( V_2 ) -> V_199 & V_200 )
V_267 = 1 ;
else
V_267 = 0 ;
if ( F_133 ( V_267 , V_264 ) )
V_137 = - V_138 ;
break;
case V_270 :
if ( F_3 ( V_2 ) -> V_199 & V_202 )
V_267 = 1 ;
else
V_267 = 0 ;
if ( F_133 ( V_267 , V_264 ) )
V_137 = - V_138 ;
break;
case V_271 :
{
struct V_16 * V_272 = & F_3 ( V_2 ) -> V_20 ;
memset ( & V_266 , 0 , sizeof( V_266 ) ) ;
V_266 . V_22 = V_272 -> V_22 ;
V_266 . V_28 = V_272 -> V_28 ;
V_266 . V_27 [ 0 ] = * ( ( T_1 * ) V_272 -> V_27 + 0 ) ;
V_266 . V_27 [ 1 ] = * ( ( T_1 * ) V_272 -> V_27 + 1 ) ;
}
V_35 = F_96 (unsigned int, len, sizeof(uf)) ;
if ( F_134 ( V_264 , & V_266 , V_35 ) )
V_137 = - V_138 ;
break;
default:
V_137 = - V_268 ;
break;
}
V_156:
F_85 ( V_2 ) ;
return V_137 ;
}
static int F_135 ( struct V_274 * V_274 , struct V_131 * V_1 , int V_275 ,
int V_276 )
{
struct V_1 * V_2 ;
F_20 ( L_12 , V_1 ) ;
if ( V_1 -> type != V_277 )
return - V_278 ;
V_1 -> V_279 = & V_280 ;
V_2 = F_136 ( V_274 , V_281 , V_47 , & V_282 , V_276 ) ;
if ( ! V_2 )
return - V_227 ;
F_137 ( V_1 , V_2 ) ;
F_138 ( V_2 , V_283 ) ;
V_2 -> V_284 = V_275 ;
V_1 -> V_285 = V_286 ;
V_2 -> V_39 = V_122 ;
F_139 ( & V_36 , V_2 ) ;
return 0 ;
}
int T_8 F_140 ( void )
{
int V_137 ;
F_141 ( sizeof( struct V_175 ) > sizeof( struct V_173 ) ) ;
V_137 = F_142 ( & V_282 , 0 ) ;
if ( V_137 < 0 )
return V_137 ;
V_137 = F_143 ( V_287 , & V_288 ) ;
if ( V_137 < 0 ) {
F_144 ( L_13 ) ;
goto error;
}
V_137 = F_145 ( & V_289 , L_14 , & V_36 , NULL ) ;
if ( V_137 < 0 ) {
F_144 ( L_15 ) ;
F_146 ( V_287 ) ;
goto error;
}
F_147 ( L_16 ) ;
return 0 ;
error:
F_148 ( & V_282 ) ;
return V_137 ;
}
void F_149 ( void )
{
F_150 ( & V_289 , L_14 ) ;
F_146 ( V_287 ) ;
F_148 ( & V_282 ) ;
}
