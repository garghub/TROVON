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
V_30 = V_2 -> V_39 -> V_54 ( V_2 , & V_4 -> V_47 ) ;
if ( V_30 )
break;
V_2 -> V_12 = 1 ;
F_6 ( V_55 , & V_4 -> V_21 ) ;
}
if ( V_4 -> V_56 . V_42 && ! V_2 -> V_11 ) {
V_4 -> V_53 = & V_4 -> V_56 ;
V_30 = V_2 -> V_39 -> V_57 ( V_2 , & V_4 -> V_56 ) ;
if ( V_30 )
break;
V_2 -> V_11 = 1 ;
F_6 ( V_55 , & V_4 -> V_21 ) ;
}
if ( V_4 -> V_41 . V_58 == 0 ) {
int V_59 ;
int V_60 = 1 ;
V_59 = ( V_4 -> V_56 . V_42 || V_4 -> V_47 . V_42 ) ;
if ( V_4 -> V_56 . V_42 && ! V_4 -> V_56 . V_61 )
V_60 = 0 ;
if ( V_4 -> V_47 . V_42 && ! V_4 -> V_47 . V_61 )
V_60 = 0 ;
if ( V_59 && V_60
&& ! V_4 -> V_62 )
V_4 -> V_41 . V_42 = 0 ;
}
if ( V_4 -> V_41 . V_42 && ! V_2 -> V_13 ) {
V_4 -> V_53 = & V_4 -> V_41 ;
V_30 = V_2 -> V_39 -> V_63 ( V_2 , V_4 ,
V_2 -> V_9 ,
V_2 -> V_8 ,
V_2 -> V_10 ) ;
if ( V_30 <= 0 )
break;
if ( V_2 -> V_9 < sizeof( struct V_64 ) ) {
V_5 = F_32 ( int , V_30 ,
sizeof( struct V_64 ) -
V_2 -> V_9 ) ;
V_2 -> V_9 += V_5 ;
V_30 -= V_5 ;
}
V_29 = & V_4 -> V_41 . V_65 [ V_2 -> V_8 ] ;
while ( V_30 ) {
V_5 = F_32 ( int , V_30 , V_29 -> V_66 -
V_2 -> V_10 ) ;
V_2 -> V_10 += V_5 ;
V_30 -= V_5 ;
if ( V_2 -> V_10 == V_29 -> V_66 ) {
V_2 -> V_10 = 0 ;
V_29 ++ ;
V_2 -> V_8 ++ ;
F_33 ( V_30 != 0 &&
V_2 -> V_8 == V_4 -> V_41 . V_58 ) ;
}
}
if ( V_2 -> V_9 == sizeof( struct V_64 ) &&
( V_2 -> V_8 == V_4 -> V_41 . V_58 ) )
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
if ( V_2 -> V_39 -> V_67 )
V_2 -> V_39 -> V_67 ( V_2 ) ;
F_11 ( V_2 ) ;
if ( ! F_24 ( & V_31 ) ) {
F_34 (rm, &to_be_dropped, m_conn_item)
F_3 ( V_4 ) ;
F_35 ( & V_31 , V_68 ) ;
}
if ( V_30 == 0 ) {
F_36 () ;
if ( ! F_24 ( & V_2 -> V_24 ) &&
V_33 == V_2 -> V_38 ) {
F_18 ( V_69 ) ;
goto V_34;
}
}
V_37:
return V_30 ;
}
static void F_37 ( struct V_70 * V_71 , struct V_3 * V_4 )
{
T_1 V_43 = F_38 ( V_4 -> V_49 . V_50 . V_51 ) ;
F_39 ( & V_71 -> V_72 ) ;
F_33 ( V_71 -> V_73 < V_43 ) ;
V_71 -> V_73 -= V_43 ;
if ( V_71 -> V_73 == 0 )
F_18 ( V_74 ) ;
}
static inline int F_40 ( struct V_3 * V_4 , T_2 V_75 ,
T_3 V_76 )
{
if ( V_76 )
return V_76 ( V_4 , V_75 ) ;
return F_41 ( V_4 -> V_49 . V_50 . V_77 ) <= V_75 ;
}
void F_42 ( struct V_3 * V_4 , int V_78 )
{
struct V_70 * V_71 = NULL ;
struct V_79 * V_80 ;
struct V_81 * V_82 ;
unsigned long V_6 ;
F_4 ( & V_4 -> V_83 , V_6 ) ;
V_80 = & V_4 -> V_47 ;
if ( F_28 ( V_84 , & V_4 -> V_21 ) &&
V_80 -> V_42 && V_80 -> V_85 && V_80 -> V_86 ) {
V_82 = V_80 -> V_86 ;
V_71 = V_4 -> V_87 ;
F_43 ( F_44 ( V_71 ) ) ;
V_82 -> V_88 = V_78 ;
F_45 ( & V_71 -> V_72 ) ;
F_46 ( & V_82 -> V_89 , & V_71 -> V_90 ) ;
F_47 ( & V_71 -> V_72 ) ;
V_80 -> V_86 = NULL ;
}
F_8 ( & V_4 -> V_83 , V_6 ) ;
if ( V_71 ) {
F_48 ( V_71 ) ;
F_49 ( F_44 ( V_71 ) ) ;
}
}
void F_50 ( struct V_3 * V_4 , int V_78 )
{
struct V_70 * V_71 = NULL ;
struct V_91 * V_92 ;
struct V_81 * V_82 ;
unsigned long V_6 ;
F_4 ( & V_4 -> V_83 , V_6 ) ;
V_92 = & V_4 -> V_56 ;
if ( F_28 ( V_84 , & V_4 -> V_21 )
&& V_92 -> V_42 && V_92 -> V_85 && V_92 -> V_86 ) {
V_82 = V_92 -> V_86 ;
V_71 = V_4 -> V_87 ;
F_43 ( F_44 ( V_71 ) ) ;
V_82 -> V_88 = V_78 ;
F_45 ( & V_71 -> V_72 ) ;
F_46 ( & V_82 -> V_89 , & V_71 -> V_90 ) ;
F_47 ( & V_71 -> V_72 ) ;
V_92 -> V_86 = NULL ;
}
F_8 ( & V_4 -> V_83 , V_6 ) ;
if ( V_71 ) {
F_48 ( V_71 ) ;
F_49 ( F_44 ( V_71 ) ) ;
}
}
static inline void
F_51 ( struct V_70 * V_71 , struct V_3 * V_4 , int V_78 )
{
struct V_79 * V_80 ;
struct V_91 * V_92 ;
V_80 = & V_4 -> V_47 ;
if ( V_80 -> V_42 && V_80 -> V_85 && V_80 -> V_86 ) {
V_80 -> V_86 -> V_88 = V_78 ;
F_46 ( & V_80 -> V_86 -> V_89 , & V_71 -> V_90 ) ;
V_80 -> V_86 = NULL ;
}
V_92 = & V_4 -> V_56 ;
if ( V_92 -> V_42 && V_92 -> V_85 && V_92 -> V_86 ) {
V_92 -> V_86 -> V_88 = V_78 ;
F_46 ( & V_92 -> V_86 -> V_89 , & V_71 -> V_90 ) ;
V_92 -> V_86 = NULL ;
}
}
struct V_3 * F_52 ( struct V_1 * V_2 ,
struct V_79 * V_93 )
{
struct V_3 * V_4 , * V_5 , * V_94 = NULL ;
unsigned long V_6 ;
F_4 ( & V_2 -> V_19 , V_6 ) ;
F_5 (rm, tmp, &conn->c_retrans, m_conn_item) {
if ( & V_4 -> V_47 == V_93 ) {
F_53 ( & V_4 -> V_95 ) ;
V_94 = V_4 ;
goto V_37;
}
}
F_5 (rm, tmp, &conn->c_send_queue, m_conn_item) {
if ( & V_4 -> V_47 == V_93 ) {
F_53 ( & V_4 -> V_95 ) ;
V_94 = V_4 ;
break;
}
}
V_37:
F_8 ( & V_2 -> V_19 , V_6 ) ;
return V_94 ;
}
static void F_35 ( struct V_96 * V_97 , int V_78 )
{
unsigned long V_6 ;
struct V_70 * V_71 = NULL ;
struct V_3 * V_4 ;
while ( ! F_24 ( V_97 ) ) {
int V_98 = 0 ;
V_4 = F_25 ( V_97 -> V_45 , struct V_3 ,
V_46 ) ;
F_54 ( & V_4 -> V_46 ) ;
F_4 ( & V_4 -> V_83 , V_6 ) ;
if ( ! F_28 ( V_84 , & V_4 -> V_21 ) )
goto V_99;
if ( V_71 != V_4 -> V_87 ) {
if ( V_71 ) {
F_48 ( V_71 ) ;
F_49 ( F_44 ( V_71 ) ) ;
}
V_71 = V_4 -> V_87 ;
if ( V_71 )
F_43 ( F_44 ( V_71 ) ) ;
}
if ( ! V_71 )
goto V_99;
F_45 ( & V_71 -> V_72 ) ;
if ( F_20 ( V_84 , & V_4 -> V_21 ) ) {
struct V_79 * V_80 = & V_4 -> V_47 ;
struct V_81 * V_82 ;
F_54 ( & V_4 -> V_100 ) ;
F_37 ( V_71 , V_4 ) ;
if ( V_80 -> V_42 && V_80 -> V_86 &&
( V_80 -> V_85 || ( V_80 -> V_101 && V_78 ) ) ) {
V_82 = V_80 -> V_86 ;
F_46 ( & V_82 -> V_89 ,
& V_71 -> V_90 ) ;
if ( ! V_82 -> V_88 )
V_82 -> V_88 = V_78 ;
V_4 -> V_47 . V_86 = NULL ;
}
V_98 = 1 ;
V_4 -> V_87 = NULL ;
}
F_47 ( & V_71 -> V_72 ) ;
V_99:
F_8 ( & V_4 -> V_83 , V_6 ) ;
F_3 ( V_4 ) ;
if ( V_98 )
F_3 ( V_4 ) ;
}
if ( V_71 ) {
F_48 ( V_71 ) ;
F_49 ( F_44 ( V_71 ) ) ;
}
}
void F_55 ( struct V_1 * V_2 , T_2 V_75 ,
T_3 V_76 )
{
struct V_3 * V_4 , * V_5 ;
unsigned long V_6 ;
F_17 ( V_102 ) ;
F_4 ( & V_2 -> V_19 , V_6 ) ;
F_5 (rm, tmp, &conn->c_retrans, m_conn_item) {
if ( ! F_40 ( V_4 , V_75 , V_76 ) )
break;
F_29 ( & V_4 -> V_46 , & V_102 ) ;
F_12 ( V_48 , & V_4 -> V_21 ) ;
}
if ( ! F_24 ( & V_102 ) )
F_13 () ;
F_8 ( & V_2 -> V_19 , V_6 ) ;
F_35 ( & V_102 , V_103 ) ;
}
void F_56 ( struct V_70 * V_71 , struct V_104 * V_105 )
{
struct V_3 * V_4 , * V_5 ;
struct V_1 * V_2 ;
unsigned long V_6 ;
F_17 ( V_102 ) ;
F_4 ( & V_71 -> V_72 , V_6 ) ;
F_5 (rm, tmp, &rs->rs_send_queue, m_sock_item) {
if ( V_105 && ( V_105 -> V_106 . V_107 != V_4 -> V_108 ||
V_105 -> V_109 != V_4 -> V_49 . V_50 . V_110 ) )
continue;
F_29 ( & V_4 -> V_100 , & V_102 ) ;
F_37 ( V_71 , V_4 ) ;
F_12 ( V_84 , & V_4 -> V_21 ) ;
}
F_13 () ;
F_8 ( & V_71 -> V_72 , V_6 ) ;
if ( F_24 ( & V_102 ) )
return;
F_34 (rm, &list, m_sock_item) {
V_2 = V_4 -> V_49 . V_111 ;
F_4 ( & V_2 -> V_19 , V_6 ) ;
if ( ! F_20 ( V_48 , & V_4 -> V_21 ) ) {
F_8 ( & V_2 -> V_19 , V_6 ) ;
F_4 ( & V_4 -> V_83 , V_6 ) ;
V_4 -> V_87 = NULL ;
F_8 ( & V_4 -> V_83 , V_6 ) ;
continue;
}
F_54 ( & V_4 -> V_46 ) ;
F_8 ( & V_2 -> V_19 , V_6 ) ;
F_4 ( & V_4 -> V_83 , V_6 ) ;
F_45 ( & V_71 -> V_72 ) ;
F_51 ( V_71 , V_4 , V_112 ) ;
F_47 ( & V_71 -> V_72 ) ;
V_4 -> V_87 = NULL ;
F_8 ( & V_4 -> V_83 , V_6 ) ;
F_3 ( V_4 ) ;
}
F_48 ( V_71 ) ;
while ( ! F_24 ( & V_102 ) ) {
V_4 = F_25 ( V_102 . V_45 , struct V_3 , V_100 ) ;
F_54 ( & V_4 -> V_100 ) ;
F_57 ( V_4 ) ;
F_3 ( V_4 ) ;
}
}
static int F_58 ( struct V_70 * V_71 , struct V_1 * V_2 ,
struct V_3 * V_4 , T_4 V_113 ,
T_4 V_114 , int * V_115 )
{
unsigned long V_6 ;
T_1 V_43 ;
if ( * V_115 )
goto V_37;
V_43 = F_38 ( V_4 -> V_49 . V_50 . V_51 ) ;
F_4 ( & V_71 -> V_72 , V_6 ) ;
if ( V_71 -> V_73 < F_59 ( V_71 ) ) {
V_71 -> V_73 += V_43 ;
if ( V_71 -> V_73 >= F_59 ( V_71 ) / 2 )
F_31 ( V_20 , & V_4 -> V_21 ) ;
F_46 ( & V_4 -> V_100 , & V_71 -> V_116 ) ;
F_6 ( V_84 , & V_4 -> V_21 ) ;
F_26 ( V_4 ) ;
V_4 -> V_87 = V_71 ;
F_60 ( & V_4 -> V_49 . V_50 , V_113 , V_114 , 0 ) ;
V_4 -> V_49 . V_111 = V_2 ;
F_26 ( V_4 ) ;
F_45 ( & V_2 -> V_19 ) ;
V_4 -> V_49 . V_50 . V_77 = F_61 ( V_2 -> V_117 ++ ) ;
F_46 ( & V_4 -> V_46 , & V_2 -> V_24 ) ;
F_6 ( V_48 , & V_4 -> V_21 ) ;
F_47 ( & V_2 -> V_19 ) ;
F_62 ( L_1 ,
V_4 , V_43 , V_71 , V_71 -> V_73 ,
( unsigned long long ) F_41 ( V_4 -> V_49 . V_50 . V_77 ) ) ;
* V_115 = 1 ;
}
F_8 ( & V_71 -> V_72 , V_6 ) ;
V_37:
return * V_115 ;
}
static int F_63 ( struct V_118 * V_119 , int V_120 )
{
struct V_121 * V_122 ;
int V_123 = 0 ;
int V_124 = 0 ;
int V_125 ;
F_64 (cmsg, msg) {
if ( ! F_65 ( V_119 , V_122 ) )
return - V_126 ;
if ( V_122 -> V_127 != V_128 )
continue;
switch ( V_122 -> V_129 ) {
case V_130 :
V_124 |= 1 ;
V_125 = F_66 ( F_67 ( V_122 ) ) ;
if ( V_125 < 0 )
return V_125 ;
V_123 += V_125 ;
break;
case V_131 :
case V_132 :
V_124 |= 2 ;
break;
case V_133 :
case V_134 :
case V_135 :
case V_136 :
V_124 |= 1 ;
V_123 += sizeof( struct V_28 ) ;
break;
default:
return - V_126 ;
}
}
V_123 += ceil ( V_120 , V_137 ) * sizeof( struct V_28 ) ;
if ( V_124 == 3 )
return - V_126 ;
return V_123 ;
}
static int F_68 ( struct V_70 * V_71 , struct V_3 * V_4 ,
struct V_118 * V_119 , int * V_138 )
{
struct V_121 * V_122 ;
int V_30 = 0 ;
F_64 (cmsg, msg) {
if ( ! F_65 ( V_119 , V_122 ) )
return - V_126 ;
if ( V_122 -> V_127 != V_128 )
continue;
switch ( V_122 -> V_129 ) {
case V_130 :
V_30 = F_69 ( V_71 , V_4 , V_122 ) ;
break;
case V_131 :
V_30 = F_70 ( V_71 , V_4 , V_122 ) ;
break;
case V_132 :
V_30 = F_71 ( V_71 , V_4 , V_122 ) ;
if ( ! V_30 )
* V_138 = 1 ;
break;
case V_133 :
case V_134 :
case V_135 :
case V_136 :
V_30 = F_72 ( V_71 , V_4 , V_122 ) ;
break;
default:
return - V_126 ;
}
if ( V_30 )
break;
}
return V_30 ;
}
int F_73 ( struct V_139 * V_140 , struct V_118 * V_119 , T_5 V_141 )
{
struct V_140 * V_142 = V_140 -> V_142 ;
struct V_70 * V_71 = F_74 ( V_142 ) ;
F_75 ( struct V_104 * , V_143 , V_119 -> V_144 ) ;
T_6 V_145 ;
T_4 V_114 ;
struct V_3 * V_4 = NULL ;
struct V_1 * V_2 ;
int V_30 = 0 ;
int V_115 = 0 , V_138 = 0 ;
int V_146 = V_119 -> V_147 & V_148 ;
long V_149 = F_76 ( V_142 , V_146 ) ;
if ( V_119 -> V_147 & ~ ( V_148 | V_150 ) ) {
V_30 = - V_151 ;
goto V_37;
}
if ( V_119 -> V_152 ) {
if ( V_119 -> V_152 < sizeof( * V_143 ) || V_143 -> V_153 != V_154 ) {
V_30 = - V_126 ;
goto V_37;
}
V_145 = V_143 -> V_106 . V_107 ;
V_114 = V_143 -> V_109 ;
} else {
F_77 ( V_142 ) ;
V_145 = V_71 -> V_155 ;
V_114 = V_71 -> V_156 ;
F_78 ( V_142 ) ;
}
if ( V_145 == 0 || V_71 -> V_157 == 0 ) {
V_30 = - V_158 ;
goto V_37;
}
V_30 = F_63 ( V_119 , V_141 ) ;
if ( V_30 < 0 )
goto V_37;
V_4 = F_79 ( V_30 , V_159 ) ;
if ( ! V_4 ) {
V_30 = - V_36 ;
goto V_37;
}
if ( V_141 ) {
V_4 -> V_41 . V_65 = F_80 ( V_4 , ceil ( V_141 , V_137 ) ) ;
if ( ! V_4 -> V_41 . V_65 ) {
V_30 = - V_36 ;
goto V_37;
}
V_30 = F_81 ( V_4 , & V_119 -> V_160 ) ;
if ( V_30 )
goto V_37;
}
V_4 -> V_41 . V_42 = 1 ;
V_4 -> V_108 = V_145 ;
if ( V_71 -> V_161 && V_71 -> V_161 -> V_162 == V_145 )
V_2 = V_71 -> V_161 ;
else {
V_2 = F_82 ( V_71 -> V_157 , V_145 ,
V_71 -> V_163 ,
V_140 -> V_142 -> V_164 ) ;
if ( F_22 ( V_2 ) ) {
V_30 = F_23 ( V_2 ) ;
goto V_37;
}
V_71 -> V_161 = V_2 ;
}
V_30 = F_68 ( V_71 , V_4 , V_119 , & V_138 ) ;
if ( V_30 )
goto V_37;
if ( V_4 -> V_47 . V_42 && ! V_2 -> V_39 -> V_54 ) {
F_83 ( V_165 L_2 ,
& V_4 -> V_47 , V_2 -> V_39 -> V_54 ) ;
V_30 = - V_151 ;
goto V_37;
}
if ( V_4 -> V_56 . V_42 && ! V_2 -> V_39 -> V_57 ) {
F_83 ( V_165 L_3 ,
& V_4 -> V_56 , V_2 -> V_39 -> V_57 ) ;
V_30 = - V_151 ;
goto V_37;
}
F_84 ( V_2 ) ;
V_30 = F_85 ( V_2 -> V_166 , V_114 , V_146 , V_71 ) ;
if ( V_30 ) {
V_71 -> V_167 = 1 ;
goto V_37;
}
while ( ! F_58 ( V_71 , V_2 , V_4 , V_71 -> V_168 ,
V_114 , & V_115 ) ) {
F_18 ( V_169 ) ;
if ( V_141 > F_59 ( V_71 ) ) {
V_30 = - V_170 ;
goto V_37;
}
if ( V_146 ) {
V_30 = - V_171 ;
goto V_37;
}
V_149 = F_86 ( * F_87 ( V_142 ) ,
F_58 ( V_71 , V_2 , V_4 ,
V_71 -> V_168 ,
V_114 ,
& V_115 ) ,
V_149 ) ;
F_62 ( L_4 , V_115 , V_149 ) ;
if ( V_149 > 0 || V_149 == V_172 )
continue;
V_30 = V_149 ;
if ( V_30 == 0 )
V_30 = - V_173 ;
goto V_37;
}
F_18 ( V_174 ) ;
if ( ! F_28 ( V_175 , & V_2 -> V_26 ) )
F_16 ( V_2 ) ;
F_3 ( V_4 ) ;
return V_141 ;
V_37:
if ( V_138 )
F_88 ( V_71 , F_89 ( V_4 -> V_62 ) , 1 ) ;
if ( V_4 )
F_3 ( V_4 ) ;
return V_30 ;
}
int
F_90 ( struct V_1 * V_2 , T_4 V_114 )
{
struct V_3 * V_4 ;
unsigned long V_6 ;
int V_30 = 0 ;
V_4 = F_79 ( 0 , V_176 ) ;
if ( ! V_4 ) {
V_30 = - V_36 ;
goto V_37;
}
V_4 -> V_108 = V_2 -> V_162 ;
V_4 -> V_41 . V_42 = 1 ;
F_84 ( V_2 ) ;
V_30 = F_85 ( V_2 -> V_166 , V_114 , 1 , NULL ) ;
if ( V_30 )
goto V_37;
F_4 ( & V_2 -> V_19 , V_6 ) ;
F_46 ( & V_4 -> V_46 , & V_2 -> V_24 ) ;
F_6 ( V_48 , & V_4 -> V_21 ) ;
F_26 ( V_4 ) ;
V_4 -> V_49 . V_111 = V_2 ;
F_60 ( & V_4 -> V_49 . V_50 , 0 , V_114 ,
V_2 -> V_117 ) ;
V_2 -> V_117 ++ ;
F_8 ( & V_2 -> V_19 , V_6 ) ;
F_18 ( V_174 ) ;
F_18 ( V_177 ) ;
if ( ! F_28 ( V_175 , & V_2 -> V_26 ) )
F_91 ( V_178 , & V_2 -> V_179 , 0 ) ;
F_3 ( V_4 ) ;
return 0 ;
V_37:
if ( V_4 )
F_3 ( V_4 ) ;
return V_30 ;
}
