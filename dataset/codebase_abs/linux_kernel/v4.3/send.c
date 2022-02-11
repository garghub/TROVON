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
if ( V_32 >= 1024 )
goto V_44;
F_4 ( & V_2 -> V_19 , V_6 ) ;
if ( ! F_24 ( & V_2 -> V_24 ) ) {
V_4 = F_25 ( V_2 -> V_24 . V_45 ,
struct V_3 ,
V_46 ) ;
F_26 ( V_4 ) ;
F_27 ( & V_4 -> V_46 , & V_2 -> V_23 ) ;
}
F_8 ( & V_2 -> V_19 , V_6 ) ;
if ( ! V_4 )
break;
if ( V_4 -> V_47 . V_42 &&
F_28 ( V_22 , & V_4 -> V_21 ) ) {
F_4 ( & V_2 -> V_19 , V_6 ) ;
if ( F_20 ( V_48 , & V_4 -> V_21 ) )
F_29 ( & V_4 -> V_46 , & V_31 ) ;
F_8 ( & V_2 -> V_19 , V_6 ) ;
continue;
}
V_43 = F_30 ( V_4 -> V_49 . V_50 . V_51 ) ;
if ( V_2 -> V_15 == 0 ||
V_2 -> V_17 < V_43 ) {
F_31 ( V_20 , & V_4 -> V_21 ) ;
V_2 -> V_15 = V_16 ;
V_2 -> V_17 = V_18 ;
F_18 ( V_52 ) ;
} else {
V_2 -> V_17 -= V_43 ;
V_2 -> V_15 -- ;
}
V_2 -> V_7 = V_4 ;
}
if ( V_4 -> V_47 . V_42 && ! V_2 -> V_12 ) {
V_4 -> V_53 = & V_4 -> V_47 ;
F_6 ( V_54 , & V_4 -> V_21 ) ;
V_30 = V_2 -> V_39 -> V_55 ( V_2 , & V_4 -> V_47 ) ;
if ( V_30 ) {
F_12 ( V_54 , & V_4 -> V_21 ) ;
F_32 ( & V_4 -> V_56 ) ;
break;
}
V_2 -> V_12 = 1 ;
}
if ( V_4 -> V_57 . V_42 && ! V_2 -> V_11 ) {
V_4 -> V_53 = & V_4 -> V_57 ;
F_6 ( V_54 , & V_4 -> V_21 ) ;
V_30 = V_2 -> V_39 -> V_58 ( V_2 , & V_4 -> V_57 ) ;
if ( V_30 ) {
F_12 ( V_54 , & V_4 -> V_21 ) ;
F_32 ( & V_4 -> V_56 ) ;
break;
}
V_2 -> V_11 = 1 ;
}
if ( V_4 -> V_41 . V_59 == 0 ) {
int V_60 ;
int V_61 = 1 ;
V_60 = ( V_4 -> V_57 . V_42 || V_4 -> V_47 . V_42 ) ;
if ( V_4 -> V_57 . V_42 && ! V_4 -> V_57 . V_62 )
V_61 = 0 ;
if ( V_4 -> V_47 . V_42 && ! V_4 -> V_47 . V_62 )
V_61 = 0 ;
if ( V_60 && V_61
&& ! V_4 -> V_63 )
V_4 -> V_41 . V_42 = 0 ;
}
if ( V_4 -> V_41 . V_42 && ! V_2 -> V_13 ) {
V_4 -> V_53 = & V_4 -> V_41 ;
V_30 = V_2 -> V_39 -> V_64 ( V_2 , V_4 ,
V_2 -> V_9 ,
V_2 -> V_8 ,
V_2 -> V_10 ) ;
if ( V_30 <= 0 )
break;
if ( V_2 -> V_9 < sizeof( struct V_65 ) ) {
V_5 = F_33 ( int , V_30 ,
sizeof( struct V_65 ) -
V_2 -> V_9 ) ;
V_2 -> V_9 += V_5 ;
V_30 -= V_5 ;
}
V_29 = & V_4 -> V_41 . V_66 [ V_2 -> V_8 ] ;
while ( V_30 ) {
V_5 = F_33 ( int , V_30 , V_29 -> V_67 -
V_2 -> V_10 ) ;
V_2 -> V_10 += V_5 ;
V_30 -= V_5 ;
if ( V_2 -> V_10 == V_29 -> V_67 ) {
V_2 -> V_10 = 0 ;
V_29 ++ ;
V_2 -> V_8 ++ ;
F_34 ( V_30 != 0 &&
V_2 -> V_8 == V_4 -> V_41 . V_59 ) ;
}
}
if ( V_2 -> V_9 == sizeof( struct V_65 ) &&
( V_2 -> V_8 == V_4 -> V_41 . V_59 ) )
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
V_44:
if ( V_2 -> V_39 -> V_68 )
V_2 -> V_39 -> V_68 ( V_2 ) ;
F_11 ( V_2 ) ;
if ( ! F_24 ( & V_31 ) ) {
F_35 (rm, &to_be_dropped, m_conn_item)
F_3 ( V_4 ) ;
F_36 ( & V_31 , V_69 ) ;
}
if ( V_30 == 0 ) {
F_37 () ;
if ( ( F_28 ( 0 , & V_2 -> V_14 ) ||
! F_24 ( & V_2 -> V_24 ) ) &&
V_33 == V_2 -> V_38 ) {
F_18 ( V_70 ) ;
goto V_34;
}
}
V_37:
return V_30 ;
}
static void F_38 ( struct V_71 * V_72 , struct V_3 * V_4 )
{
T_1 V_43 = F_39 ( V_4 -> V_49 . V_50 . V_51 ) ;
F_40 ( & V_72 -> V_73 ) ;
F_34 ( V_72 -> V_74 < V_43 ) ;
V_72 -> V_74 -= V_43 ;
if ( V_72 -> V_74 == 0 )
F_18 ( V_75 ) ;
}
static inline int F_41 ( struct V_3 * V_4 , T_2 V_76 ,
T_3 V_77 )
{
if ( V_77 )
return V_77 ( V_4 , V_76 ) ;
return F_42 ( V_4 -> V_49 . V_50 . V_78 ) <= V_76 ;
}
void F_43 ( struct V_3 * V_4 , int V_79 )
{
struct V_71 * V_72 = NULL ;
struct V_80 * V_81 ;
struct V_82 * V_83 ;
unsigned long V_6 ;
F_4 ( & V_4 -> V_84 , V_6 ) ;
V_81 = & V_4 -> V_47 ;
if ( F_28 ( V_85 , & V_4 -> V_21 ) &&
V_81 -> V_42 && V_81 -> V_86 && V_81 -> V_87 ) {
V_83 = V_81 -> V_87 ;
V_72 = V_4 -> V_88 ;
F_44 ( F_45 ( V_72 ) ) ;
V_83 -> V_89 = V_79 ;
F_46 ( & V_72 -> V_73 ) ;
F_47 ( & V_83 -> V_90 , & V_72 -> V_91 ) ;
F_48 ( & V_72 -> V_73 ) ;
V_81 -> V_87 = NULL ;
}
F_8 ( & V_4 -> V_84 , V_6 ) ;
if ( V_72 ) {
F_49 ( V_72 ) ;
F_50 ( F_45 ( V_72 ) ) ;
}
}
void F_51 ( struct V_3 * V_4 , int V_79 )
{
struct V_71 * V_72 = NULL ;
struct V_92 * V_93 ;
struct V_82 * V_83 ;
unsigned long V_6 ;
F_4 ( & V_4 -> V_84 , V_6 ) ;
V_93 = & V_4 -> V_57 ;
if ( F_28 ( V_85 , & V_4 -> V_21 )
&& V_93 -> V_42 && V_93 -> V_86 && V_93 -> V_87 ) {
V_83 = V_93 -> V_87 ;
V_72 = V_4 -> V_88 ;
F_44 ( F_45 ( V_72 ) ) ;
V_83 -> V_89 = V_79 ;
F_46 ( & V_72 -> V_73 ) ;
F_47 ( & V_83 -> V_90 , & V_72 -> V_91 ) ;
F_48 ( & V_72 -> V_73 ) ;
V_93 -> V_87 = NULL ;
}
F_8 ( & V_4 -> V_84 , V_6 ) ;
if ( V_72 ) {
F_49 ( V_72 ) ;
F_50 ( F_45 ( V_72 ) ) ;
}
}
static inline void
F_52 ( struct V_71 * V_72 , struct V_3 * V_4 , int V_79 )
{
struct V_80 * V_81 ;
struct V_92 * V_93 ;
V_81 = & V_4 -> V_47 ;
if ( V_81 -> V_42 && V_81 -> V_86 && V_81 -> V_87 ) {
V_81 -> V_87 -> V_89 = V_79 ;
F_47 ( & V_81 -> V_87 -> V_90 , & V_72 -> V_91 ) ;
V_81 -> V_87 = NULL ;
}
V_93 = & V_4 -> V_57 ;
if ( V_93 -> V_42 && V_93 -> V_86 && V_93 -> V_87 ) {
V_93 -> V_87 -> V_89 = V_79 ;
F_47 ( & V_93 -> V_87 -> V_90 , & V_72 -> V_91 ) ;
V_93 -> V_87 = NULL ;
}
}
struct V_3 * F_53 ( struct V_1 * V_2 ,
struct V_80 * V_94 )
{
struct V_3 * V_4 , * V_5 , * V_95 = NULL ;
unsigned long V_6 ;
F_4 ( & V_2 -> V_19 , V_6 ) ;
F_5 (rm, tmp, &conn->c_retrans, m_conn_item) {
if ( & V_4 -> V_47 == V_94 ) {
F_54 ( & V_4 -> V_96 ) ;
V_95 = V_4 ;
goto V_37;
}
}
F_5 (rm, tmp, &conn->c_send_queue, m_conn_item) {
if ( & V_4 -> V_47 == V_94 ) {
F_54 ( & V_4 -> V_96 ) ;
V_95 = V_4 ;
break;
}
}
V_37:
F_8 ( & V_2 -> V_19 , V_6 ) ;
return V_95 ;
}
static void F_36 ( struct V_97 * V_98 , int V_79 )
{
unsigned long V_6 ;
struct V_71 * V_72 = NULL ;
struct V_3 * V_4 ;
while ( ! F_24 ( V_98 ) ) {
int V_99 = 0 ;
V_4 = F_25 ( V_98 -> V_45 , struct V_3 ,
V_46 ) ;
F_55 ( & V_4 -> V_46 ) ;
F_4 ( & V_4 -> V_84 , V_6 ) ;
if ( ! F_28 ( V_85 , & V_4 -> V_21 ) )
goto V_100;
if ( V_72 != V_4 -> V_88 ) {
if ( V_72 ) {
F_49 ( V_72 ) ;
F_50 ( F_45 ( V_72 ) ) ;
}
V_72 = V_4 -> V_88 ;
if ( V_72 )
F_44 ( F_45 ( V_72 ) ) ;
}
if ( ! V_72 )
goto V_100;
F_46 ( & V_72 -> V_73 ) ;
if ( F_20 ( V_85 , & V_4 -> V_21 ) ) {
struct V_80 * V_81 = & V_4 -> V_47 ;
struct V_82 * V_83 ;
F_55 ( & V_4 -> V_101 ) ;
F_38 ( V_72 , V_4 ) ;
if ( V_81 -> V_42 && V_81 -> V_87 &&
( V_81 -> V_86 || ( V_81 -> V_102 && V_79 ) ) ) {
V_83 = V_81 -> V_87 ;
F_47 ( & V_83 -> V_90 ,
& V_72 -> V_91 ) ;
if ( ! V_83 -> V_89 )
V_83 -> V_89 = V_79 ;
V_4 -> V_47 . V_87 = NULL ;
}
V_99 = 1 ;
V_4 -> V_88 = NULL ;
}
F_48 ( & V_72 -> V_73 ) ;
V_100:
F_8 ( & V_4 -> V_84 , V_6 ) ;
F_3 ( V_4 ) ;
if ( V_99 )
F_3 ( V_4 ) ;
}
if ( V_72 ) {
F_49 ( V_72 ) ;
F_50 ( F_45 ( V_72 ) ) ;
}
}
void F_56 ( struct V_1 * V_2 , T_2 V_76 ,
T_3 V_77 )
{
struct V_3 * V_4 , * V_5 ;
unsigned long V_6 ;
F_17 ( V_103 ) ;
F_4 ( & V_2 -> V_19 , V_6 ) ;
F_5 (rm, tmp, &conn->c_retrans, m_conn_item) {
if ( ! F_41 ( V_4 , V_76 , V_77 ) )
break;
F_29 ( & V_4 -> V_46 , & V_103 ) ;
F_12 ( V_48 , & V_4 -> V_21 ) ;
}
if ( ! F_24 ( & V_103 ) )
F_13 () ;
F_8 ( & V_2 -> V_19 , V_6 ) ;
F_36 ( & V_103 , V_104 ) ;
}
void F_57 ( struct V_71 * V_72 , struct V_105 * V_106 )
{
struct V_3 * V_4 , * V_5 ;
struct V_1 * V_2 ;
unsigned long V_6 ;
F_17 ( V_103 ) ;
F_4 ( & V_72 -> V_73 , V_6 ) ;
F_5 (rm, tmp, &rs->rs_send_queue, m_sock_item) {
if ( V_106 && ( V_106 -> V_107 . V_108 != V_4 -> V_109 ||
V_106 -> V_110 != V_4 -> V_49 . V_50 . V_111 ) )
continue;
F_29 ( & V_4 -> V_101 , & V_103 ) ;
F_38 ( V_72 , V_4 ) ;
F_12 ( V_85 , & V_4 -> V_21 ) ;
}
F_13 () ;
F_8 ( & V_72 -> V_73 , V_6 ) ;
if ( F_24 ( & V_103 ) )
return;
F_35 (rm, &list, m_sock_item) {
V_2 = V_4 -> V_49 . V_112 ;
F_4 ( & V_2 -> V_19 , V_6 ) ;
if ( ! F_20 ( V_48 , & V_4 -> V_21 ) ) {
F_8 ( & V_2 -> V_19 , V_6 ) ;
F_4 ( & V_4 -> V_84 , V_6 ) ;
V_4 -> V_88 = NULL ;
F_8 ( & V_4 -> V_84 , V_6 ) ;
continue;
}
F_55 ( & V_4 -> V_46 ) ;
F_8 ( & V_2 -> V_19 , V_6 ) ;
F_4 ( & V_4 -> V_84 , V_6 ) ;
F_46 ( & V_72 -> V_73 ) ;
F_52 ( V_72 , V_4 , V_113 ) ;
F_48 ( & V_72 -> V_73 ) ;
V_4 -> V_88 = NULL ;
F_8 ( & V_4 -> V_84 , V_6 ) ;
F_3 ( V_4 ) ;
}
F_49 ( V_72 ) ;
while ( ! F_24 ( & V_103 ) ) {
V_4 = F_25 ( V_103 . V_45 , struct V_3 , V_101 ) ;
F_55 ( & V_4 -> V_101 ) ;
F_58 ( V_4 ) ;
F_4 ( & V_4 -> V_84 , V_6 ) ;
F_46 ( & V_72 -> V_73 ) ;
F_52 ( V_72 , V_4 , V_113 ) ;
F_48 ( & V_72 -> V_73 ) ;
V_4 -> V_88 = NULL ;
F_8 ( & V_4 -> V_84 , V_6 ) ;
F_3 ( V_4 ) ;
}
}
static int F_59 ( struct V_71 * V_72 , struct V_1 * V_2 ,
struct V_3 * V_4 , T_4 V_114 ,
T_4 V_115 , int * V_116 )
{
unsigned long V_6 ;
T_1 V_43 ;
if ( * V_116 )
goto V_37;
V_43 = F_39 ( V_4 -> V_49 . V_50 . V_51 ) ;
F_4 ( & V_72 -> V_73 , V_6 ) ;
if ( V_72 -> V_74 < F_60 ( V_72 ) ) {
V_72 -> V_74 += V_43 ;
if ( V_72 -> V_74 >= F_60 ( V_72 ) / 2 )
F_31 ( V_20 , & V_4 -> V_21 ) ;
F_47 ( & V_4 -> V_101 , & V_72 -> V_117 ) ;
F_6 ( V_85 , & V_4 -> V_21 ) ;
F_26 ( V_4 ) ;
V_4 -> V_88 = V_72 ;
F_61 ( & V_4 -> V_49 . V_50 , V_114 , V_115 , 0 ) ;
V_4 -> V_49 . V_112 = V_2 ;
F_26 ( V_4 ) ;
F_46 ( & V_2 -> V_19 ) ;
V_4 -> V_49 . V_50 . V_78 = F_62 ( V_2 -> V_118 ++ ) ;
F_47 ( & V_4 -> V_46 , & V_2 -> V_24 ) ;
F_6 ( V_48 , & V_4 -> V_21 ) ;
F_48 ( & V_2 -> V_19 ) ;
F_63 ( L_1 ,
V_4 , V_43 , V_72 , V_72 -> V_74 ,
( unsigned long long ) F_42 ( V_4 -> V_49 . V_50 . V_78 ) ) ;
* V_116 = 1 ;
}
F_8 ( & V_72 -> V_73 , V_6 ) ;
V_37:
return * V_116 ;
}
static int F_64 ( struct V_119 * V_120 , int V_121 )
{
struct V_122 * V_123 ;
int V_124 = 0 ;
int V_125 = 0 ;
int V_126 ;
F_65 (cmsg, msg) {
if ( ! F_66 ( V_120 , V_123 ) )
return - V_127 ;
if ( V_123 -> V_128 != V_129 )
continue;
switch ( V_123 -> V_130 ) {
case V_131 :
V_125 |= 1 ;
V_126 = F_67 ( F_68 ( V_123 ) ) ;
if ( V_126 < 0 )
return V_126 ;
V_124 += V_126 ;
break;
case V_132 :
case V_133 :
V_125 |= 2 ;
break;
case V_134 :
case V_135 :
case V_136 :
case V_137 :
V_125 |= 1 ;
V_124 += sizeof( struct V_28 ) ;
break;
default:
return - V_127 ;
}
}
V_124 += ceil ( V_121 , V_138 ) * sizeof( struct V_28 ) ;
if ( V_125 == 3 )
return - V_127 ;
return V_124 ;
}
static int F_69 ( struct V_71 * V_72 , struct V_3 * V_4 ,
struct V_119 * V_120 , int * V_139 )
{
struct V_122 * V_123 ;
int V_30 = 0 ;
F_65 (cmsg, msg) {
if ( ! F_66 ( V_120 , V_123 ) )
return - V_127 ;
if ( V_123 -> V_128 != V_129 )
continue;
switch ( V_123 -> V_130 ) {
case V_131 :
V_30 = F_70 ( V_72 , V_4 , V_123 ) ;
break;
case V_132 :
V_30 = F_71 ( V_72 , V_4 , V_123 ) ;
break;
case V_133 :
V_30 = F_72 ( V_72 , V_4 , V_123 ) ;
if ( ! V_30 )
* V_139 = 1 ;
break;
case V_134 :
case V_135 :
case V_136 :
case V_137 :
V_30 = F_73 ( V_72 , V_4 , V_123 ) ;
break;
default:
return - V_127 ;
}
if ( V_30 )
break;
}
return V_30 ;
}
int F_74 ( struct V_140 * V_141 , struct V_119 * V_120 , T_5 V_142 )
{
struct V_141 * V_143 = V_141 -> V_143 ;
struct V_71 * V_72 = F_75 ( V_143 ) ;
F_76 ( struct V_105 * , V_144 , V_120 -> V_145 ) ;
T_6 V_146 ;
T_4 V_115 ;
struct V_3 * V_4 = NULL ;
struct V_1 * V_2 ;
int V_30 = 0 ;
int V_116 = 0 , V_139 = 0 ;
int V_147 = V_120 -> V_148 & V_149 ;
long V_150 = F_77 ( V_143 , V_147 ) ;
if ( V_120 -> V_148 & ~ ( V_149 | V_151 ) ) {
V_30 = - V_152 ;
goto V_37;
}
if ( V_120 -> V_153 ) {
if ( V_120 -> V_153 < sizeof( * V_144 ) || V_144 -> V_154 != V_155 ) {
V_30 = - V_127 ;
goto V_37;
}
V_146 = V_144 -> V_107 . V_108 ;
V_115 = V_144 -> V_110 ;
} else {
F_78 ( V_143 ) ;
V_146 = V_72 -> V_156 ;
V_115 = V_72 -> V_157 ;
F_79 ( V_143 ) ;
}
if ( V_146 == 0 || V_72 -> V_158 == 0 ) {
V_30 = - V_159 ;
goto V_37;
}
if ( V_142 > F_60 ( V_72 ) ) {
V_30 = - V_160 ;
goto V_37;
}
V_30 = F_64 ( V_120 , V_142 ) ;
if ( V_30 < 0 )
goto V_37;
V_4 = F_80 ( V_30 , V_161 ) ;
if ( ! V_4 ) {
V_30 = - V_36 ;
goto V_37;
}
if ( V_142 ) {
V_4 -> V_41 . V_66 = F_81 ( V_4 , ceil ( V_142 , V_138 ) ) ;
if ( ! V_4 -> V_41 . V_66 ) {
V_30 = - V_36 ;
goto V_37;
}
V_30 = F_82 ( V_4 , & V_120 -> V_162 ) ;
if ( V_30 )
goto V_37;
}
V_4 -> V_41 . V_42 = 1 ;
V_4 -> V_109 = V_146 ;
if ( V_72 -> V_163 && V_72 -> V_163 -> V_164 == V_146 )
V_2 = V_72 -> V_163 ;
else {
V_2 = F_83 ( F_84 ( V_141 -> V_143 ) ,
V_72 -> V_158 , V_146 ,
V_72 -> V_165 ,
V_141 -> V_143 -> V_166 ) ;
if ( F_22 ( V_2 ) ) {
V_30 = F_23 ( V_2 ) ;
goto V_37;
}
V_72 -> V_163 = V_2 ;
}
V_30 = F_69 ( V_72 , V_4 , V_120 , & V_139 ) ;
if ( V_30 )
goto V_37;
if ( V_4 -> V_47 . V_42 && ! V_2 -> V_39 -> V_55 ) {
F_85 ( V_167 L_2 ,
& V_4 -> V_47 , V_2 -> V_39 -> V_55 ) ;
V_30 = - V_152 ;
goto V_37;
}
if ( V_4 -> V_57 . V_42 && ! V_2 -> V_39 -> V_58 ) {
F_85 ( V_167 L_3 ,
& V_4 -> V_57 , V_2 -> V_39 -> V_58 ) ;
V_30 = - V_152 ;
goto V_37;
}
F_86 ( V_2 ) ;
V_30 = F_87 ( V_2 -> V_168 , V_115 , V_147 , V_72 ) ;
if ( V_30 ) {
V_72 -> V_169 = 1 ;
goto V_37;
}
while ( ! F_59 ( V_72 , V_2 , V_4 , V_72 -> V_170 ,
V_115 , & V_116 ) ) {
F_18 ( V_171 ) ;
if ( V_147 ) {
V_30 = - V_172 ;
goto V_37;
}
V_150 = F_88 ( * F_89 ( V_143 ) ,
F_59 ( V_72 , V_2 , V_4 ,
V_72 -> V_170 ,
V_115 ,
& V_116 ) ,
V_150 ) ;
F_63 ( L_4 , V_116 , V_150 ) ;
if ( V_150 > 0 || V_150 == V_173 )
continue;
V_30 = V_150 ;
if ( V_30 == 0 )
V_30 = - V_174 ;
goto V_37;
}
F_18 ( V_175 ) ;
if ( ! F_28 ( V_176 , & V_2 -> V_26 ) )
F_16 ( V_2 ) ;
F_3 ( V_4 ) ;
return V_142 ;
V_37:
if ( V_139 )
F_90 ( V_72 , F_91 ( V_4 -> V_63 ) , 1 ) ;
if ( V_4 )
F_3 ( V_4 ) ;
return V_30 ;
}
int
F_92 ( struct V_1 * V_2 , T_4 V_115 )
{
struct V_3 * V_4 ;
unsigned long V_6 ;
int V_30 = 0 ;
V_4 = F_80 ( 0 , V_177 ) ;
if ( ! V_4 ) {
V_30 = - V_36 ;
goto V_37;
}
V_4 -> V_109 = V_2 -> V_164 ;
V_4 -> V_41 . V_42 = 1 ;
F_86 ( V_2 ) ;
V_30 = F_87 ( V_2 -> V_168 , V_115 , 1 , NULL ) ;
if ( V_30 )
goto V_37;
F_4 ( & V_2 -> V_19 , V_6 ) ;
F_47 ( & V_4 -> V_46 , & V_2 -> V_24 ) ;
F_6 ( V_48 , & V_4 -> V_21 ) ;
F_26 ( V_4 ) ;
V_4 -> V_49 . V_112 = V_2 ;
F_61 ( & V_4 -> V_49 . V_50 , 0 , V_115 ,
V_2 -> V_118 ) ;
V_2 -> V_118 ++ ;
F_8 ( & V_2 -> V_19 , V_6 ) ;
F_18 ( V_175 ) ;
F_18 ( V_178 ) ;
if ( ! F_28 ( V_176 , & V_2 -> V_26 ) )
F_93 ( V_179 , & V_2 -> V_180 , 0 ) ;
F_3 ( V_4 ) ;
return 0 ;
V_37:
if ( V_4 )
F_3 ( V_4 ) ;
return V_30 ;
}
