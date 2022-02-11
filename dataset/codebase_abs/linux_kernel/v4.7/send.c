void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
unsigned long V_6 ;
if ( V_2 -> V_7 ) {
V_4 = V_2 -> V_7 ;
V_2 -> V_7 = NULL ;
F_2 ( V_4 ) ;
F_3 ( V_4 ) ;
}
V_2 -> V_8 = 0 ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 0 ;
V_2 -> V_11 = 0 ;
V_2 -> V_12 = 0 ;
V_2 -> V_13 = 0 ;
V_2 -> V_14 = 0 ;
V_2 -> V_15 = V_16 ;
V_2 -> V_17 = V_18 ;
F_4 ( & V_2 -> V_19 , V_6 ) ;
F_5 (rm, tmp, &conn->c_retrans, m_conn_item) {
F_6 ( V_20 , & V_4 -> V_21 ) ;
F_6 ( V_22 , & V_4 -> V_21 ) ;
}
F_7 ( & V_2 -> V_23 , & V_2 -> V_24 ) ;
F_8 ( & V_2 -> V_19 , V_6 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
return F_10 ( V_25 , & V_2 -> V_26 ) == 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_12 ( V_25 , & V_2 -> V_26 ) ;
F_13 () ;
if ( F_14 ( & V_2 -> V_27 ) )
F_15 ( & V_2 -> V_27 ) ;
}
int F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned long V_6 ;
unsigned int V_5 ;
struct V_28 * V_29 ;
int V_30 = 0 ;
F_17 ( V_31 ) ;
int V_32 ;
unsigned long V_33 = 0 ;
V_34:
V_32 = 0 ;
if ( ! F_9 ( V_2 ) ) {
F_18 ( V_35 ) ;
V_30 = - V_36 ;
goto V_37;
}
V_2 -> V_38 ++ ;
V_33 = V_2 -> V_38 ;
if ( ! F_19 ( V_2 ) ) {
F_11 ( V_2 ) ;
V_30 = 0 ;
goto V_37;
}
if ( V_2 -> V_39 -> V_40 )
V_2 -> V_39 -> V_40 ( V_2 ) ;
while ( 1 ) {
V_4 = V_2 -> V_7 ;
if ( ! V_4 && F_20 ( 0 , & V_2 -> V_14 ) ) {
V_4 = F_21 ( V_2 ) ;
if ( F_22 ( V_4 ) ) {
V_30 = F_23 ( V_4 ) ;
break;
}
V_4 -> V_41 . V_42 = 1 ;
V_2 -> V_7 = V_4 ;
}
if ( ! V_4 ) {
unsigned int V_43 ;
V_32 ++ ;
if ( V_32 >= V_44 )
goto V_45;
F_4 ( & V_2 -> V_19 , V_6 ) ;
if ( ! F_24 ( & V_2 -> V_24 ) ) {
V_4 = F_25 ( V_2 -> V_24 . V_46 ,
struct V_3 ,
V_47 ) ;
F_26 ( V_4 ) ;
F_27 ( & V_4 -> V_47 , & V_2 -> V_23 ) ;
}
F_8 ( & V_2 -> V_19 , V_6 ) ;
if ( ! V_4 )
break;
if ( V_4 -> V_48 . V_42 &&
F_28 ( V_22 , & V_4 -> V_21 ) ) {
F_4 ( & V_2 -> V_19 , V_6 ) ;
if ( F_20 ( V_49 , & V_4 -> V_21 ) )
F_29 ( & V_4 -> V_47 , & V_31 ) ;
F_8 ( & V_2 -> V_19 , V_6 ) ;
continue;
}
V_43 = F_30 ( V_4 -> V_50 . V_51 . V_52 ) ;
if ( V_2 -> V_15 == 0 ||
V_2 -> V_17 < V_43 ) {
F_31 ( V_20 , & V_4 -> V_21 ) ;
V_2 -> V_15 = V_16 ;
V_2 -> V_17 = V_18 ;
F_18 ( V_53 ) ;
} else {
V_2 -> V_17 -= V_43 ;
V_2 -> V_15 -- ;
}
V_2 -> V_7 = V_4 ;
}
if ( V_4 -> V_48 . V_42 && ! V_2 -> V_12 ) {
V_4 -> V_54 = & V_4 -> V_48 ;
F_6 ( V_55 , & V_4 -> V_21 ) ;
V_30 = V_2 -> V_39 -> V_56 ( V_2 , & V_4 -> V_48 ) ;
if ( V_30 ) {
F_12 ( V_55 , & V_4 -> V_21 ) ;
F_32 ( & V_4 -> V_57 ) ;
break;
}
V_2 -> V_12 = 1 ;
}
if ( V_4 -> V_58 . V_42 && ! V_2 -> V_11 ) {
V_4 -> V_54 = & V_4 -> V_58 ;
F_6 ( V_55 , & V_4 -> V_21 ) ;
V_30 = V_2 -> V_39 -> V_59 ( V_2 , & V_4 -> V_58 ) ;
if ( V_30 ) {
F_12 ( V_55 , & V_4 -> V_21 ) ;
F_32 ( & V_4 -> V_57 ) ;
break;
}
V_2 -> V_11 = 1 ;
}
if ( V_4 -> V_41 . V_60 == 0 ) {
int V_61 ;
int V_62 = 1 ;
V_61 = ( V_4 -> V_58 . V_42 || V_4 -> V_48 . V_42 ) ;
if ( V_4 -> V_58 . V_42 && ! V_4 -> V_58 . V_63 )
V_62 = 0 ;
if ( V_4 -> V_48 . V_42 && ! V_4 -> V_48 . V_63 )
V_62 = 0 ;
if ( V_61 && V_62
&& ! V_4 -> V_64 )
V_4 -> V_41 . V_42 = 0 ;
}
if ( V_4 -> V_41 . V_42 && ! V_2 -> V_13 ) {
V_4 -> V_54 = & V_4 -> V_41 ;
V_30 = V_2 -> V_39 -> V_65 ( V_2 , V_4 ,
V_2 -> V_9 ,
V_2 -> V_8 ,
V_2 -> V_10 ) ;
if ( V_30 <= 0 )
break;
if ( V_2 -> V_9 < sizeof( struct V_66 ) ) {
V_5 = F_33 ( int , V_30 ,
sizeof( struct V_66 ) -
V_2 -> V_9 ) ;
V_2 -> V_9 += V_5 ;
V_30 -= V_5 ;
}
V_29 = & V_4 -> V_41 . V_67 [ V_2 -> V_8 ] ;
while ( V_30 ) {
V_5 = F_33 ( int , V_30 , V_29 -> V_68 -
V_2 -> V_10 ) ;
V_2 -> V_10 += V_5 ;
V_30 -= V_5 ;
if ( V_2 -> V_10 == V_29 -> V_68 ) {
V_2 -> V_10 = 0 ;
V_29 ++ ;
V_2 -> V_8 ++ ;
F_34 ( V_30 != 0 &&
V_2 -> V_8 == V_4 -> V_41 . V_60 ) ;
}
}
if ( V_2 -> V_9 == sizeof( struct V_66 ) &&
( V_2 -> V_8 == V_4 -> V_41 . V_60 ) )
V_2 -> V_13 = 1 ;
}
if ( ! V_4 -> V_41 . V_42 || V_2 -> V_13 ) {
V_2 -> V_7 = NULL ;
V_2 -> V_8 = 0 ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 0 ;
V_2 -> V_12 = 0 ;
V_2 -> V_11 = 0 ;
V_2 -> V_13 = 0 ;
F_3 ( V_4 ) ;
}
}
V_45:
if ( V_2 -> V_39 -> V_69 )
V_2 -> V_39 -> V_69 ( V_2 ) ;
F_11 ( V_2 ) ;
if ( ! F_24 ( & V_31 ) ) {
F_35 (rm, &to_be_dropped, m_conn_item)
F_3 ( V_4 ) ;
F_36 ( & V_31 , V_70 ) ;
}
if ( V_30 == 0 ) {
F_37 () ;
if ( ( F_28 ( 0 , & V_2 -> V_14 ) ||
! F_24 ( & V_2 -> V_24 ) ) &&
V_33 == V_2 -> V_38 ) {
F_18 ( V_71 ) ;
if ( V_32 < V_44 )
goto V_34;
F_38 ( V_72 , & V_2 -> V_73 , 1 ) ;
}
}
V_37:
return V_30 ;
}
static void F_39 ( struct V_74 * V_75 , struct V_3 * V_4 )
{
T_1 V_43 = F_40 ( V_4 -> V_50 . V_51 . V_52 ) ;
F_41 ( & V_75 -> V_76 ) ;
F_34 ( V_75 -> V_77 < V_43 ) ;
V_75 -> V_77 -= V_43 ;
if ( V_75 -> V_77 == 0 )
F_18 ( V_78 ) ;
}
static inline int F_42 ( struct V_3 * V_4 , T_2 V_79 ,
T_3 V_80 )
{
if ( V_80 )
return V_80 ( V_4 , V_79 ) ;
return F_43 ( V_4 -> V_50 . V_51 . V_81 ) <= V_79 ;
}
void F_44 ( struct V_3 * V_4 , int V_82 )
{
struct V_74 * V_75 = NULL ;
struct V_83 * V_84 ;
struct V_85 * V_86 ;
unsigned long V_6 ;
F_4 ( & V_4 -> V_87 , V_6 ) ;
V_84 = & V_4 -> V_48 ;
if ( F_28 ( V_88 , & V_4 -> V_21 ) &&
V_84 -> V_42 && V_84 -> V_89 && V_84 -> V_90 ) {
V_86 = V_84 -> V_90 ;
V_75 = V_4 -> V_91 ;
F_45 ( F_46 ( V_75 ) ) ;
V_86 -> V_92 = V_82 ;
F_47 ( & V_75 -> V_76 ) ;
F_48 ( & V_86 -> V_93 , & V_75 -> V_94 ) ;
F_49 ( & V_75 -> V_76 ) ;
V_84 -> V_90 = NULL ;
}
F_8 ( & V_4 -> V_87 , V_6 ) ;
if ( V_75 ) {
F_50 ( V_75 ) ;
F_51 ( F_46 ( V_75 ) ) ;
}
}
void F_52 ( struct V_3 * V_4 , int V_82 )
{
struct V_74 * V_75 = NULL ;
struct V_95 * V_96 ;
struct V_85 * V_86 ;
unsigned long V_6 ;
F_4 ( & V_4 -> V_87 , V_6 ) ;
V_96 = & V_4 -> V_58 ;
if ( F_28 ( V_88 , & V_4 -> V_21 )
&& V_96 -> V_42 && V_96 -> V_89 && V_96 -> V_90 ) {
V_86 = V_96 -> V_90 ;
V_75 = V_4 -> V_91 ;
F_45 ( F_46 ( V_75 ) ) ;
V_86 -> V_92 = V_82 ;
F_47 ( & V_75 -> V_76 ) ;
F_48 ( & V_86 -> V_93 , & V_75 -> V_94 ) ;
F_49 ( & V_75 -> V_76 ) ;
V_96 -> V_90 = NULL ;
}
F_8 ( & V_4 -> V_87 , V_6 ) ;
if ( V_75 ) {
F_50 ( V_75 ) ;
F_51 ( F_46 ( V_75 ) ) ;
}
}
static inline void
F_53 ( struct V_74 * V_75 , struct V_3 * V_4 , int V_82 )
{
struct V_83 * V_84 ;
struct V_95 * V_96 ;
V_84 = & V_4 -> V_48 ;
if ( V_84 -> V_42 && V_84 -> V_89 && V_84 -> V_90 ) {
V_84 -> V_90 -> V_92 = V_82 ;
F_48 ( & V_84 -> V_90 -> V_93 , & V_75 -> V_94 ) ;
V_84 -> V_90 = NULL ;
}
V_96 = & V_4 -> V_58 ;
if ( V_96 -> V_42 && V_96 -> V_89 && V_96 -> V_90 ) {
V_96 -> V_90 -> V_92 = V_82 ;
F_48 ( & V_96 -> V_90 -> V_93 , & V_75 -> V_94 ) ;
V_96 -> V_90 = NULL ;
}
}
struct V_3 * F_54 ( struct V_1 * V_2 ,
struct V_83 * V_97 )
{
struct V_3 * V_4 , * V_5 , * V_98 = NULL ;
unsigned long V_6 ;
F_4 ( & V_2 -> V_19 , V_6 ) ;
F_5 (rm, tmp, &conn->c_retrans, m_conn_item) {
if ( & V_4 -> V_48 == V_97 ) {
F_55 ( & V_4 -> V_99 ) ;
V_98 = V_4 ;
goto V_37;
}
}
F_5 (rm, tmp, &conn->c_send_queue, m_conn_item) {
if ( & V_4 -> V_48 == V_97 ) {
F_55 ( & V_4 -> V_99 ) ;
V_98 = V_4 ;
break;
}
}
V_37:
F_8 ( & V_2 -> V_19 , V_6 ) ;
return V_98 ;
}
static void F_36 ( struct V_100 * V_101 , int V_82 )
{
unsigned long V_6 ;
struct V_74 * V_75 = NULL ;
struct V_3 * V_4 ;
while ( ! F_24 ( V_101 ) ) {
int V_102 = 0 ;
V_4 = F_25 ( V_101 -> V_46 , struct V_3 ,
V_47 ) ;
F_56 ( & V_4 -> V_47 ) ;
F_4 ( & V_4 -> V_87 , V_6 ) ;
if ( ! F_28 ( V_88 , & V_4 -> V_21 ) )
goto V_103;
if ( V_75 != V_4 -> V_91 ) {
if ( V_75 ) {
F_50 ( V_75 ) ;
F_51 ( F_46 ( V_75 ) ) ;
}
V_75 = V_4 -> V_91 ;
if ( V_75 )
F_45 ( F_46 ( V_75 ) ) ;
}
if ( ! V_75 )
goto V_103;
F_47 ( & V_75 -> V_76 ) ;
if ( F_20 ( V_88 , & V_4 -> V_21 ) ) {
struct V_83 * V_84 = & V_4 -> V_48 ;
struct V_85 * V_86 ;
F_56 ( & V_4 -> V_104 ) ;
F_39 ( V_75 , V_4 ) ;
if ( V_84 -> V_42 && V_84 -> V_90 &&
( V_84 -> V_89 || ( V_84 -> V_105 && V_82 ) ) ) {
V_86 = V_84 -> V_90 ;
F_48 ( & V_86 -> V_93 ,
& V_75 -> V_94 ) ;
if ( ! V_86 -> V_92 )
V_86 -> V_92 = V_82 ;
V_4 -> V_48 . V_90 = NULL ;
}
V_102 = 1 ;
V_4 -> V_91 = NULL ;
}
F_49 ( & V_75 -> V_76 ) ;
V_103:
F_8 ( & V_4 -> V_87 , V_6 ) ;
F_3 ( V_4 ) ;
if ( V_102 )
F_3 ( V_4 ) ;
}
if ( V_75 ) {
F_50 ( V_75 ) ;
F_51 ( F_46 ( V_75 ) ) ;
}
}
void F_57 ( struct V_1 * V_2 , T_2 V_79 ,
T_3 V_80 )
{
struct V_3 * V_4 , * V_5 ;
unsigned long V_6 ;
F_17 ( V_106 ) ;
F_4 ( & V_2 -> V_19 , V_6 ) ;
F_5 (rm, tmp, &conn->c_retrans, m_conn_item) {
if ( ! F_42 ( V_4 , V_79 , V_80 ) )
break;
F_29 ( & V_4 -> V_47 , & V_106 ) ;
F_12 ( V_49 , & V_4 -> V_21 ) ;
}
if ( ! F_24 ( & V_106 ) )
F_13 () ;
F_8 ( & V_2 -> V_19 , V_6 ) ;
F_36 ( & V_106 , V_107 ) ;
}
void F_58 ( struct V_74 * V_75 , struct V_108 * V_109 )
{
struct V_3 * V_4 , * V_5 ;
struct V_1 * V_2 ;
unsigned long V_6 ;
F_17 ( V_106 ) ;
F_4 ( & V_75 -> V_76 , V_6 ) ;
F_5 (rm, tmp, &rs->rs_send_queue, m_sock_item) {
if ( V_109 && ( V_109 -> V_110 . V_111 != V_4 -> V_112 ||
V_109 -> V_113 != V_4 -> V_50 . V_51 . V_114 ) )
continue;
F_29 ( & V_4 -> V_104 , & V_106 ) ;
F_39 ( V_75 , V_4 ) ;
F_12 ( V_88 , & V_4 -> V_21 ) ;
}
F_13 () ;
F_8 ( & V_75 -> V_76 , V_6 ) ;
if ( F_24 ( & V_106 ) )
return;
F_35 (rm, &list, m_sock_item) {
V_2 = V_4 -> V_50 . V_115 ;
F_4 ( & V_2 -> V_19 , V_6 ) ;
if ( ! F_20 ( V_49 , & V_4 -> V_21 ) ) {
F_8 ( & V_2 -> V_19 , V_6 ) ;
F_4 ( & V_4 -> V_87 , V_6 ) ;
V_4 -> V_91 = NULL ;
F_8 ( & V_4 -> V_87 , V_6 ) ;
continue;
}
F_56 ( & V_4 -> V_47 ) ;
F_8 ( & V_2 -> V_19 , V_6 ) ;
F_4 ( & V_4 -> V_87 , V_6 ) ;
F_47 ( & V_75 -> V_76 ) ;
F_53 ( V_75 , V_4 , V_116 ) ;
F_49 ( & V_75 -> V_76 ) ;
V_4 -> V_91 = NULL ;
F_8 ( & V_4 -> V_87 , V_6 ) ;
F_3 ( V_4 ) ;
}
F_50 ( V_75 ) ;
while ( ! F_24 ( & V_106 ) ) {
V_4 = F_25 ( V_106 . V_46 , struct V_3 , V_104 ) ;
F_56 ( & V_4 -> V_104 ) ;
F_59 ( V_4 ) ;
F_4 ( & V_4 -> V_87 , V_6 ) ;
F_47 ( & V_75 -> V_76 ) ;
F_53 ( V_75 , V_4 , V_116 ) ;
F_49 ( & V_75 -> V_76 ) ;
V_4 -> V_91 = NULL ;
F_8 ( & V_4 -> V_87 , V_6 ) ;
F_3 ( V_4 ) ;
}
}
static int F_60 ( struct V_74 * V_75 , struct V_1 * V_2 ,
struct V_3 * V_4 , T_4 V_117 ,
T_4 V_118 , int * V_119 )
{
unsigned long V_6 ;
T_1 V_43 ;
if ( * V_119 )
goto V_37;
V_43 = F_40 ( V_4 -> V_50 . V_51 . V_52 ) ;
F_4 ( & V_75 -> V_76 , V_6 ) ;
if ( V_75 -> V_77 < F_61 ( V_75 ) ) {
V_75 -> V_77 += V_43 ;
if ( V_75 -> V_77 >= F_61 ( V_75 ) / 2 )
F_31 ( V_20 , & V_4 -> V_21 ) ;
F_48 ( & V_4 -> V_104 , & V_75 -> V_120 ) ;
F_6 ( V_88 , & V_4 -> V_21 ) ;
F_26 ( V_4 ) ;
V_4 -> V_91 = V_75 ;
F_62 ( & V_4 -> V_50 . V_51 , V_117 , V_118 , 0 ) ;
V_4 -> V_50 . V_115 = V_2 ;
F_26 ( V_4 ) ;
F_47 ( & V_2 -> V_19 ) ;
V_4 -> V_50 . V_51 . V_81 = F_63 ( V_2 -> V_121 ++ ) ;
F_48 ( & V_4 -> V_47 , & V_2 -> V_24 ) ;
F_6 ( V_49 , & V_4 -> V_21 ) ;
F_49 ( & V_2 -> V_19 ) ;
F_64 ( L_1 ,
V_4 , V_43 , V_75 , V_75 -> V_77 ,
( unsigned long long ) F_43 ( V_4 -> V_50 . V_51 . V_81 ) ) ;
* V_119 = 1 ;
}
F_8 ( & V_75 -> V_76 , V_6 ) ;
V_37:
return * V_119 ;
}
static int F_65 ( struct V_122 * V_123 , int V_124 )
{
struct V_125 * V_126 ;
int V_127 = 0 ;
int V_128 = 0 ;
int V_129 ;
F_66 (cmsg, msg) {
if ( ! F_67 ( V_123 , V_126 ) )
return - V_130 ;
if ( V_126 -> V_131 != V_132 )
continue;
switch ( V_126 -> V_133 ) {
case V_134 :
V_128 |= 1 ;
V_129 = F_68 ( F_69 ( V_126 ) ) ;
if ( V_129 < 0 )
return V_129 ;
V_127 += V_129 ;
break;
case V_135 :
case V_136 :
V_128 |= 2 ;
break;
case V_137 :
case V_138 :
case V_139 :
case V_140 :
V_128 |= 1 ;
V_127 += sizeof( struct V_28 ) ;
break;
default:
return - V_130 ;
}
}
V_127 += ceil ( V_124 , V_141 ) * sizeof( struct V_28 ) ;
if ( V_128 == 3 )
return - V_130 ;
return V_127 ;
}
static int F_70 ( struct V_74 * V_75 , struct V_3 * V_4 ,
struct V_122 * V_123 , int * V_142 )
{
struct V_125 * V_126 ;
int V_30 = 0 ;
F_66 (cmsg, msg) {
if ( ! F_67 ( V_123 , V_126 ) )
return - V_130 ;
if ( V_126 -> V_131 != V_132 )
continue;
switch ( V_126 -> V_133 ) {
case V_134 :
V_30 = F_71 ( V_75 , V_4 , V_126 ) ;
break;
case V_135 :
V_30 = F_72 ( V_75 , V_4 , V_126 ) ;
break;
case V_136 :
V_30 = F_73 ( V_75 , V_4 , V_126 ) ;
if ( ! V_30 )
* V_142 = 1 ;
break;
case V_137 :
case V_138 :
case V_139 :
case V_140 :
V_30 = F_74 ( V_75 , V_4 , V_126 ) ;
break;
default:
return - V_130 ;
}
if ( V_30 )
break;
}
return V_30 ;
}
int F_75 ( struct V_143 * V_144 , struct V_122 * V_123 , T_5 V_145 )
{
struct V_144 * V_146 = V_144 -> V_146 ;
struct V_74 * V_75 = F_76 ( V_146 ) ;
F_77 ( struct V_108 * , V_147 , V_123 -> V_148 ) ;
T_6 V_149 ;
T_4 V_118 ;
struct V_3 * V_4 = NULL ;
struct V_1 * V_2 ;
int V_30 = 0 ;
int V_119 = 0 , V_142 = 0 ;
int V_150 = V_123 -> V_151 & V_152 ;
long V_153 = F_78 ( V_146 , V_150 ) ;
if ( V_123 -> V_151 & ~ ( V_152 | V_154 ) ) {
V_30 = - V_155 ;
goto V_37;
}
if ( V_123 -> V_156 ) {
if ( V_123 -> V_156 < sizeof( * V_147 ) || V_147 -> V_157 != V_158 ) {
V_30 = - V_130 ;
goto V_37;
}
V_149 = V_147 -> V_110 . V_111 ;
V_118 = V_147 -> V_113 ;
} else {
F_79 ( V_146 ) ;
V_149 = V_75 -> V_159 ;
V_118 = V_75 -> V_160 ;
F_80 ( V_146 ) ;
}
F_79 ( V_146 ) ;
if ( V_149 == 0 || V_75 -> V_161 == 0 ) {
F_80 ( V_146 ) ;
V_30 = - V_162 ;
goto V_37;
}
F_80 ( V_146 ) ;
if ( V_145 > F_61 ( V_75 ) ) {
V_30 = - V_163 ;
goto V_37;
}
V_30 = F_65 ( V_123 , V_145 ) ;
if ( V_30 < 0 )
goto V_37;
V_4 = F_81 ( V_30 , V_164 ) ;
if ( ! V_4 ) {
V_30 = - V_36 ;
goto V_37;
}
if ( V_145 ) {
V_4 -> V_41 . V_67 = F_82 ( V_4 , ceil ( V_145 , V_141 ) ) ;
if ( ! V_4 -> V_41 . V_67 ) {
V_30 = - V_36 ;
goto V_37;
}
V_30 = F_83 ( V_4 , & V_123 -> V_165 ) ;
if ( V_30 )
goto V_37;
}
V_4 -> V_41 . V_42 = 1 ;
V_4 -> V_112 = V_149 ;
if ( V_75 -> V_166 && V_75 -> V_166 -> V_167 == V_149 )
V_2 = V_75 -> V_166 ;
else {
V_2 = F_84 ( F_85 ( V_144 -> V_146 ) ,
V_75 -> V_161 , V_149 ,
V_75 -> V_168 ,
V_144 -> V_146 -> V_169 ) ;
if ( F_22 ( V_2 ) ) {
V_30 = F_23 ( V_2 ) ;
goto V_37;
}
V_75 -> V_166 = V_2 ;
}
V_30 = F_70 ( V_75 , V_4 , V_123 , & V_142 ) ;
if ( V_30 )
goto V_37;
if ( V_4 -> V_48 . V_42 && ! V_2 -> V_39 -> V_56 ) {
F_86 ( V_170 L_2 ,
& V_4 -> V_48 , V_2 -> V_39 -> V_56 ) ;
V_30 = - V_155 ;
goto V_37;
}
if ( V_4 -> V_58 . V_42 && ! V_2 -> V_39 -> V_59 ) {
F_86 ( V_170 L_3 ,
& V_4 -> V_58 , V_2 -> V_39 -> V_59 ) ;
V_30 = - V_155 ;
goto V_37;
}
F_87 ( V_2 ) ;
V_30 = F_88 ( V_2 -> V_171 , V_118 , V_150 , V_75 ) ;
if ( V_30 ) {
V_75 -> V_172 = 1 ;
goto V_37;
}
while ( ! F_60 ( V_75 , V_2 , V_4 , V_75 -> V_173 ,
V_118 , & V_119 ) ) {
F_18 ( V_174 ) ;
if ( V_150 ) {
V_30 = - V_175 ;
goto V_37;
}
V_153 = F_89 ( * F_90 ( V_146 ) ,
F_60 ( V_75 , V_2 , V_4 ,
V_75 -> V_173 ,
V_118 ,
& V_119 ) ,
V_153 ) ;
F_64 ( L_4 , V_119 , V_153 ) ;
if ( V_153 > 0 || V_153 == V_176 )
continue;
V_30 = V_153 ;
if ( V_30 == 0 )
V_30 = - V_177 ;
goto V_37;
}
F_18 ( V_178 ) ;
V_30 = F_16 ( V_2 ) ;
if ( V_30 == - V_36 || V_30 == - V_175 )
F_38 ( V_72 , & V_2 -> V_73 , 1 ) ;
F_3 ( V_4 ) ;
return V_145 ;
V_37:
if ( V_142 )
F_91 ( V_75 , F_92 ( V_4 -> V_64 ) , 1 ) ;
if ( V_4 )
F_3 ( V_4 ) ;
return V_30 ;
}
int
F_93 ( struct V_1 * V_2 , T_4 V_118 )
{
struct V_3 * V_4 ;
unsigned long V_6 ;
int V_30 = 0 ;
V_4 = F_81 ( 0 , V_179 ) ;
if ( ! V_4 ) {
V_30 = - V_36 ;
goto V_37;
}
V_4 -> V_112 = V_2 -> V_167 ;
V_4 -> V_41 . V_42 = 1 ;
F_87 ( V_2 ) ;
V_30 = F_88 ( V_2 -> V_171 , V_118 , 1 , NULL ) ;
if ( V_30 )
goto V_37;
F_4 ( & V_2 -> V_19 , V_6 ) ;
F_48 ( & V_4 -> V_47 , & V_2 -> V_24 ) ;
F_6 ( V_49 , & V_4 -> V_21 ) ;
F_26 ( V_4 ) ;
V_4 -> V_50 . V_115 = V_2 ;
F_62 ( & V_4 -> V_50 . V_51 , 0 , V_118 ,
V_2 -> V_121 ) ;
V_2 -> V_121 ++ ;
F_8 ( & V_2 -> V_19 , V_6 ) ;
F_18 ( V_178 ) ;
F_18 ( V_180 ) ;
F_38 ( V_72 , & V_2 -> V_73 , 1 ) ;
F_3 ( V_4 ) ;
return 0 ;
V_37:
if ( V_4 )
F_3 ( V_4 ) ;
return V_30 ;
}
