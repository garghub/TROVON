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
V_32:
if ( ! F_9 ( V_2 ) ) {
F_18 ( V_33 ) ;
V_30 = - V_34 ;
goto V_35;
}
if ( ! F_19 ( V_2 ) ) {
F_11 ( V_2 ) ;
V_30 = 0 ;
goto V_35;
}
if ( V_2 -> V_36 -> V_37 )
V_2 -> V_36 -> V_37 ( V_2 ) ;
while ( 1 ) {
V_4 = V_2 -> V_7 ;
if ( ! V_4 && F_20 ( 0 , & V_2 -> V_14 ) ) {
V_4 = F_21 ( V_2 ) ;
if ( F_22 ( V_4 ) ) {
V_30 = F_23 ( V_4 ) ;
break;
}
V_4 -> V_38 . V_39 = 1 ;
V_2 -> V_7 = V_4 ;
}
if ( ! V_4 ) {
unsigned int V_40 ;
F_4 ( & V_2 -> V_19 , V_6 ) ;
if ( ! F_24 ( & V_2 -> V_24 ) ) {
V_4 = F_25 ( V_2 -> V_24 . V_41 ,
struct V_3 ,
V_42 ) ;
F_26 ( V_4 ) ;
F_27 ( & V_4 -> V_42 , & V_2 -> V_23 ) ;
}
F_8 ( & V_2 -> V_19 , V_6 ) ;
if ( ! V_4 )
break;
if ( V_4 -> V_43 . V_39 &&
F_28 ( V_22 , & V_4 -> V_21 ) ) {
F_4 ( & V_2 -> V_19 , V_6 ) ;
if ( F_20 ( V_44 , & V_4 -> V_21 ) )
F_29 ( & V_4 -> V_42 , & V_31 ) ;
F_8 ( & V_2 -> V_19 , V_6 ) ;
continue;
}
V_40 = F_30 ( V_4 -> V_45 . V_46 . V_47 ) ;
if ( V_2 -> V_15 == 0 ||
V_2 -> V_17 < V_40 ) {
F_31 ( V_20 , & V_4 -> V_21 ) ;
V_2 -> V_15 = V_16 ;
V_2 -> V_17 = V_18 ;
F_18 ( V_48 ) ;
} else {
V_2 -> V_17 -= V_40 ;
V_2 -> V_15 -- ;
}
V_2 -> V_7 = V_4 ;
}
if ( V_4 -> V_43 . V_39 && ! V_2 -> V_12 ) {
V_4 -> V_49 = & V_4 -> V_43 ;
V_30 = V_2 -> V_36 -> V_50 ( V_2 , & V_4 -> V_43 ) ;
if ( V_30 )
break;
V_2 -> V_12 = 1 ;
F_6 ( V_51 , & V_4 -> V_21 ) ;
}
if ( V_4 -> V_52 . V_39 && ! V_2 -> V_11 ) {
V_4 -> V_49 = & V_4 -> V_52 ;
V_30 = V_2 -> V_36 -> V_53 ( V_2 , & V_4 -> V_52 ) ;
if ( V_30 )
break;
V_2 -> V_11 = 1 ;
F_6 ( V_51 , & V_4 -> V_21 ) ;
}
if ( V_4 -> V_38 . V_54 == 0 ) {
int V_55 ;
int V_56 = 1 ;
V_55 = ( V_4 -> V_52 . V_39 || V_4 -> V_43 . V_39 ) ;
if ( V_4 -> V_52 . V_39 && ! V_4 -> V_52 . V_57 )
V_56 = 0 ;
if ( V_4 -> V_43 . V_39 && ! V_4 -> V_43 . V_57 )
V_56 = 0 ;
if ( V_55 && V_56
&& ! V_4 -> V_58 )
V_4 -> V_38 . V_39 = 0 ;
}
if ( V_4 -> V_38 . V_39 && ! V_2 -> V_13 ) {
V_4 -> V_49 = & V_4 -> V_38 ;
V_30 = V_2 -> V_36 -> V_59 ( V_2 , V_4 ,
V_2 -> V_9 ,
V_2 -> V_8 ,
V_2 -> V_10 ) ;
if ( V_30 <= 0 )
break;
if ( V_2 -> V_9 < sizeof( struct V_60 ) ) {
V_5 = F_32 ( int , V_30 ,
sizeof( struct V_60 ) -
V_2 -> V_9 ) ;
V_2 -> V_9 += V_5 ;
V_30 -= V_5 ;
}
V_29 = & V_4 -> V_38 . V_61 [ V_2 -> V_8 ] ;
while ( V_30 ) {
V_5 = F_32 ( int , V_30 , V_29 -> V_62 -
V_2 -> V_10 ) ;
V_2 -> V_10 += V_5 ;
V_30 -= V_5 ;
if ( V_2 -> V_10 == V_29 -> V_62 ) {
V_2 -> V_10 = 0 ;
V_29 ++ ;
V_2 -> V_8 ++ ;
F_33 ( V_30 != 0 &&
V_2 -> V_8 == V_4 -> V_38 . V_54 ) ;
}
}
if ( V_2 -> V_9 == sizeof( struct V_60 ) &&
( V_2 -> V_8 == V_4 -> V_38 . V_54 ) )
V_2 -> V_13 = 1 ;
}
if ( ! V_4 -> V_38 . V_39 || V_2 -> V_13 ) {
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
if ( V_2 -> V_36 -> V_63 )
V_2 -> V_36 -> V_63 ( V_2 ) ;
F_11 ( V_2 ) ;
if ( ! F_24 ( & V_31 ) ) {
F_34 (rm, &to_be_dropped, m_conn_item)
F_3 ( V_4 ) ;
F_35 ( & V_31 , V_64 ) ;
}
if ( V_30 == 0 ) {
F_36 () ;
if ( ! F_24 ( & V_2 -> V_24 ) ) {
F_18 ( V_65 ) ;
goto V_32;
}
}
V_35:
return V_30 ;
}
static void F_37 ( struct V_66 * V_67 , struct V_3 * V_4 )
{
T_1 V_40 = F_38 ( V_4 -> V_45 . V_46 . V_47 ) ;
F_39 ( & V_67 -> V_68 ) ;
F_33 ( V_67 -> V_69 < V_40 ) ;
V_67 -> V_69 -= V_40 ;
if ( V_67 -> V_69 == 0 )
F_18 ( V_70 ) ;
}
static inline int F_40 ( struct V_3 * V_4 , T_2 V_71 ,
T_3 V_72 )
{
if ( V_72 )
return V_72 ( V_4 , V_71 ) ;
return F_41 ( V_4 -> V_45 . V_46 . V_73 ) <= V_71 ;
}
void F_42 ( struct V_3 * V_4 , int V_74 )
{
struct V_66 * V_67 = NULL ;
struct V_75 * V_76 ;
struct V_77 * V_78 ;
unsigned long V_6 ;
F_4 ( & V_4 -> V_79 , V_6 ) ;
V_76 = & V_4 -> V_43 ;
if ( F_28 ( V_80 , & V_4 -> V_21 ) &&
V_76 -> V_39 && V_76 -> V_81 && V_76 -> V_82 ) {
V_78 = V_76 -> V_82 ;
V_67 = V_4 -> V_83 ;
F_43 ( F_44 ( V_67 ) ) ;
V_78 -> V_84 = V_74 ;
F_45 ( & V_67 -> V_68 ) ;
F_46 ( & V_78 -> V_85 , & V_67 -> V_86 ) ;
F_47 ( & V_67 -> V_68 ) ;
V_76 -> V_82 = NULL ;
}
F_8 ( & V_4 -> V_79 , V_6 ) ;
if ( V_67 ) {
F_48 ( V_67 ) ;
F_49 ( F_44 ( V_67 ) ) ;
}
}
void F_50 ( struct V_3 * V_4 , int V_74 )
{
struct V_66 * V_67 = NULL ;
struct V_87 * V_88 ;
struct V_77 * V_78 ;
unsigned long V_6 ;
F_4 ( & V_4 -> V_79 , V_6 ) ;
V_88 = & V_4 -> V_52 ;
if ( F_28 ( V_80 , & V_4 -> V_21 )
&& V_88 -> V_39 && V_88 -> V_81 && V_88 -> V_82 ) {
V_78 = V_88 -> V_82 ;
V_67 = V_4 -> V_83 ;
F_43 ( F_44 ( V_67 ) ) ;
V_78 -> V_84 = V_74 ;
F_45 ( & V_67 -> V_68 ) ;
F_46 ( & V_78 -> V_85 , & V_67 -> V_86 ) ;
F_47 ( & V_67 -> V_68 ) ;
V_88 -> V_82 = NULL ;
}
F_8 ( & V_4 -> V_79 , V_6 ) ;
if ( V_67 ) {
F_48 ( V_67 ) ;
F_49 ( F_44 ( V_67 ) ) ;
}
}
static inline void
F_51 ( struct V_66 * V_67 , struct V_3 * V_4 , int V_74 )
{
struct V_75 * V_76 ;
struct V_87 * V_88 ;
V_76 = & V_4 -> V_43 ;
if ( V_76 -> V_39 && V_76 -> V_81 && V_76 -> V_82 ) {
V_76 -> V_82 -> V_84 = V_74 ;
F_46 ( & V_76 -> V_82 -> V_85 , & V_67 -> V_86 ) ;
V_76 -> V_82 = NULL ;
}
V_88 = & V_4 -> V_52 ;
if ( V_88 -> V_39 && V_88 -> V_81 && V_88 -> V_82 ) {
V_88 -> V_82 -> V_84 = V_74 ;
F_46 ( & V_88 -> V_82 -> V_85 , & V_67 -> V_86 ) ;
V_88 -> V_82 = NULL ;
}
}
struct V_3 * F_52 ( struct V_1 * V_2 ,
struct V_75 * V_89 )
{
struct V_3 * V_4 , * V_5 , * V_90 = NULL ;
unsigned long V_6 ;
F_4 ( & V_2 -> V_19 , V_6 ) ;
F_5 (rm, tmp, &conn->c_retrans, m_conn_item) {
if ( & V_4 -> V_43 == V_89 ) {
F_53 ( & V_4 -> V_91 ) ;
V_90 = V_4 ;
goto V_35;
}
}
F_5 (rm, tmp, &conn->c_send_queue, m_conn_item) {
if ( & V_4 -> V_43 == V_89 ) {
F_53 ( & V_4 -> V_91 ) ;
V_90 = V_4 ;
break;
}
}
V_35:
F_8 ( & V_2 -> V_19 , V_6 ) ;
return V_90 ;
}
static void F_35 ( struct V_92 * V_93 , int V_74 )
{
unsigned long V_6 ;
struct V_66 * V_67 = NULL ;
struct V_3 * V_4 ;
while ( ! F_24 ( V_93 ) ) {
int V_94 = 0 ;
V_4 = F_25 ( V_93 -> V_41 , struct V_3 ,
V_42 ) ;
F_54 ( & V_4 -> V_42 ) ;
F_4 ( & V_4 -> V_79 , V_6 ) ;
if ( ! F_28 ( V_80 , & V_4 -> V_21 ) )
goto V_95;
if ( V_67 != V_4 -> V_83 ) {
if ( V_67 ) {
F_48 ( V_67 ) ;
F_49 ( F_44 ( V_67 ) ) ;
}
V_67 = V_4 -> V_83 ;
F_43 ( F_44 ( V_67 ) ) ;
}
F_45 ( & V_67 -> V_68 ) ;
if ( F_20 ( V_80 , & V_4 -> V_21 ) ) {
struct V_75 * V_76 = & V_4 -> V_43 ;
struct V_77 * V_78 ;
F_54 ( & V_4 -> V_96 ) ;
F_37 ( V_67 , V_4 ) ;
if ( V_76 -> V_39 && V_76 -> V_82 &&
( V_76 -> V_81 || ( V_76 -> V_97 && V_74 ) ) ) {
V_78 = V_76 -> V_82 ;
F_46 ( & V_78 -> V_85 ,
& V_67 -> V_86 ) ;
if ( ! V_78 -> V_84 )
V_78 -> V_84 = V_74 ;
V_4 -> V_43 . V_82 = NULL ;
}
V_94 = 1 ;
V_4 -> V_83 = NULL ;
}
F_47 ( & V_67 -> V_68 ) ;
V_95:
F_8 ( & V_4 -> V_79 , V_6 ) ;
F_3 ( V_4 ) ;
if ( V_94 )
F_3 ( V_4 ) ;
}
if ( V_67 ) {
F_48 ( V_67 ) ;
F_49 ( F_44 ( V_67 ) ) ;
}
}
void F_55 ( struct V_1 * V_2 , T_2 V_71 ,
T_3 V_72 )
{
struct V_3 * V_4 , * V_5 ;
unsigned long V_6 ;
F_17 ( V_98 ) ;
F_4 ( & V_2 -> V_19 , V_6 ) ;
F_5 (rm, tmp, &conn->c_retrans, m_conn_item) {
if ( ! F_40 ( V_4 , V_71 , V_72 ) )
break;
F_29 ( & V_4 -> V_42 , & V_98 ) ;
F_12 ( V_44 , & V_4 -> V_21 ) ;
}
if ( ! F_24 ( & V_98 ) )
F_13 () ;
F_8 ( & V_2 -> V_19 , V_6 ) ;
F_35 ( & V_98 , V_99 ) ;
}
void F_56 ( struct V_66 * V_67 , struct V_100 * V_101 )
{
struct V_3 * V_4 , * V_5 ;
struct V_1 * V_2 ;
unsigned long V_6 ;
F_17 ( V_98 ) ;
F_4 ( & V_67 -> V_68 , V_6 ) ;
F_5 (rm, tmp, &rs->rs_send_queue, m_sock_item) {
if ( V_101 && ( V_101 -> V_102 . V_103 != V_4 -> V_104 ||
V_101 -> V_105 != V_4 -> V_45 . V_46 . V_106 ) )
continue;
F_29 ( & V_4 -> V_96 , & V_98 ) ;
F_37 ( V_67 , V_4 ) ;
F_12 ( V_80 , & V_4 -> V_21 ) ;
}
F_13 () ;
F_8 ( & V_67 -> V_68 , V_6 ) ;
if ( F_24 ( & V_98 ) )
return;
F_34 (rm, &list, m_sock_item) {
V_2 = V_4 -> V_45 . V_107 ;
F_4 ( & V_2 -> V_19 , V_6 ) ;
if ( ! F_20 ( V_44 , & V_4 -> V_21 ) ) {
F_8 ( & V_2 -> V_19 , V_6 ) ;
continue;
}
F_54 ( & V_4 -> V_42 ) ;
F_8 ( & V_2 -> V_19 , V_6 ) ;
F_4 ( & V_4 -> V_79 , V_6 ) ;
F_45 ( & V_67 -> V_68 ) ;
F_51 ( V_67 , V_4 , V_108 ) ;
F_47 ( & V_67 -> V_68 ) ;
V_4 -> V_83 = NULL ;
F_8 ( & V_4 -> V_79 , V_6 ) ;
F_3 ( V_4 ) ;
}
F_48 ( V_67 ) ;
while ( ! F_24 ( & V_98 ) ) {
V_4 = F_25 ( V_98 . V_41 , struct V_3 , V_96 ) ;
F_54 ( & V_4 -> V_96 ) ;
F_57 ( V_4 ) ;
F_3 ( V_4 ) ;
}
}
static int F_58 ( struct V_66 * V_67 , struct V_1 * V_2 ,
struct V_3 * V_4 , T_4 V_109 ,
T_4 V_110 , int * V_111 )
{
unsigned long V_6 ;
T_1 V_40 ;
if ( * V_111 )
goto V_35;
V_40 = F_38 ( V_4 -> V_45 . V_46 . V_47 ) ;
F_4 ( & V_67 -> V_68 , V_6 ) ;
if ( V_67 -> V_69 < F_59 ( V_67 ) ) {
V_67 -> V_69 += V_40 ;
if ( V_67 -> V_69 >= F_59 ( V_67 ) / 2 )
F_31 ( V_20 , & V_4 -> V_21 ) ;
F_46 ( & V_4 -> V_96 , & V_67 -> V_112 ) ;
F_6 ( V_80 , & V_4 -> V_21 ) ;
F_26 ( V_4 ) ;
V_4 -> V_83 = V_67 ;
F_60 ( & V_4 -> V_45 . V_46 , V_109 , V_110 , 0 ) ;
V_4 -> V_45 . V_107 = V_2 ;
F_26 ( V_4 ) ;
F_45 ( & V_2 -> V_19 ) ;
V_4 -> V_45 . V_46 . V_73 = F_61 ( V_2 -> V_113 ++ ) ;
F_46 ( & V_4 -> V_42 , & V_2 -> V_24 ) ;
F_6 ( V_44 , & V_4 -> V_21 ) ;
F_47 ( & V_2 -> V_19 ) ;
F_62 ( L_1 ,
V_4 , V_40 , V_67 , V_67 -> V_69 ,
( unsigned long long ) F_41 ( V_4 -> V_45 . V_46 . V_73 ) ) ;
* V_111 = 1 ;
}
F_8 ( & V_67 -> V_68 , V_6 ) ;
V_35:
return * V_111 ;
}
static int F_63 ( struct V_114 * V_115 , int V_116 )
{
struct V_117 * V_118 ;
int V_119 = 0 ;
int V_120 = 0 ;
int V_121 ;
for ( V_118 = F_64 ( V_115 ) ; V_118 ; V_118 = F_65 ( V_115 , V_118 ) ) {
if ( ! F_66 ( V_115 , V_118 ) )
return - V_122 ;
if ( V_118 -> V_123 != V_124 )
continue;
switch ( V_118 -> V_125 ) {
case V_126 :
V_120 |= 1 ;
V_121 = F_67 ( F_68 ( V_118 ) ) ;
if ( V_121 < 0 )
return V_121 ;
V_119 += V_121 ;
break;
case V_127 :
case V_128 :
V_120 |= 2 ;
break;
case V_129 :
case V_130 :
case V_131 :
case V_132 :
V_120 |= 1 ;
V_119 += sizeof( struct V_28 ) ;
break;
default:
return - V_122 ;
}
}
V_119 += ceil ( V_116 , V_133 ) * sizeof( struct V_28 ) ;
if ( V_120 == 3 )
return - V_122 ;
return V_119 ;
}
static int F_69 ( struct V_66 * V_67 , struct V_3 * V_4 ,
struct V_114 * V_115 , int * V_134 )
{
struct V_117 * V_118 ;
int V_30 = 0 ;
for ( V_118 = F_64 ( V_115 ) ; V_118 ; V_118 = F_65 ( V_115 , V_118 ) ) {
if ( ! F_66 ( V_115 , V_118 ) )
return - V_122 ;
if ( V_118 -> V_123 != V_124 )
continue;
switch ( V_118 -> V_125 ) {
case V_126 :
V_30 = F_70 ( V_67 , V_4 , V_118 ) ;
break;
case V_127 :
V_30 = F_71 ( V_67 , V_4 , V_118 ) ;
break;
case V_128 :
V_30 = F_72 ( V_67 , V_4 , V_118 ) ;
if ( ! V_30 )
* V_134 = 1 ;
break;
case V_129 :
case V_130 :
case V_131 :
case V_132 :
V_30 = F_73 ( V_67 , V_4 , V_118 ) ;
break;
default:
return - V_122 ;
}
if ( V_30 )
break;
}
return V_30 ;
}
int F_74 ( struct V_135 * V_136 , struct V_137 * V_138 , struct V_114 * V_115 ,
T_5 V_139 )
{
struct V_138 * V_140 = V_138 -> V_140 ;
struct V_66 * V_67 = F_75 ( V_140 ) ;
struct V_100 * V_141 = (struct V_100 * ) V_115 -> V_142 ;
T_6 V_143 ;
T_4 V_110 ;
struct V_3 * V_4 = NULL ;
struct V_1 * V_2 ;
int V_30 = 0 ;
int V_111 = 0 , V_134 = 0 ;
int V_144 = V_115 -> V_145 & V_146 ;
long V_147 = F_76 ( V_140 , V_144 ) ;
if ( V_115 -> V_145 & ~ ( V_146 | V_148 ) ) {
V_30 = - V_149 ;
goto V_35;
}
if ( V_115 -> V_150 ) {
if ( V_115 -> V_150 < sizeof( * V_141 ) || V_141 -> V_151 != V_152 ) {
V_30 = - V_122 ;
goto V_35;
}
V_143 = V_141 -> V_102 . V_103 ;
V_110 = V_141 -> V_105 ;
} else {
F_77 ( V_140 ) ;
V_143 = V_67 -> V_153 ;
V_110 = V_67 -> V_154 ;
F_78 ( V_140 ) ;
}
if ( V_143 == 0 || V_67 -> V_155 == 0 ) {
V_30 = - V_156 ;
goto V_35;
}
V_30 = F_63 ( V_115 , V_139 ) ;
if ( V_30 < 0 )
goto V_35;
V_4 = F_79 ( V_30 , V_157 ) ;
if ( ! V_4 ) {
V_30 = - V_34 ;
goto V_35;
}
if ( V_139 ) {
V_4 -> V_38 . V_61 = F_80 ( V_4 , ceil ( V_139 , V_133 ) ) ;
if ( ! V_4 -> V_38 . V_61 ) {
V_30 = - V_34 ;
goto V_35;
}
V_30 = F_81 ( V_4 , V_115 -> V_158 , V_139 ) ;
if ( V_30 )
goto V_35;
}
V_4 -> V_38 . V_39 = 1 ;
V_4 -> V_104 = V_143 ;
if ( V_67 -> V_159 && V_67 -> V_159 -> V_160 == V_143 )
V_2 = V_67 -> V_159 ;
else {
V_2 = F_82 ( V_67 -> V_155 , V_143 ,
V_67 -> V_161 ,
V_138 -> V_140 -> V_162 ) ;
if ( F_22 ( V_2 ) ) {
V_30 = F_23 ( V_2 ) ;
goto V_35;
}
V_67 -> V_159 = V_2 ;
}
V_30 = F_69 ( V_67 , V_4 , V_115 , & V_134 ) ;
if ( V_30 )
goto V_35;
if ( V_4 -> V_43 . V_39 && ! V_2 -> V_36 -> V_50 ) {
F_83 ( V_163 L_2 ,
& V_4 -> V_43 , V_2 -> V_36 -> V_50 ) ;
V_30 = - V_149 ;
goto V_35;
}
if ( V_4 -> V_52 . V_39 && ! V_2 -> V_36 -> V_53 ) {
F_83 ( V_163 L_3 ,
& V_4 -> V_52 , V_2 -> V_36 -> V_53 ) ;
V_30 = - V_149 ;
goto V_35;
}
F_84 ( V_2 ) ;
V_30 = F_85 ( V_2 -> V_164 , V_110 , V_144 , V_67 ) ;
if ( V_30 ) {
V_67 -> V_165 = 1 ;
goto V_35;
}
while ( ! F_58 ( V_67 , V_2 , V_4 , V_67 -> V_166 ,
V_110 , & V_111 ) ) {
F_18 ( V_167 ) ;
if ( V_139 > F_59 ( V_67 ) ) {
V_30 = - V_168 ;
goto V_35;
}
if ( V_144 ) {
V_30 = - V_169 ;
goto V_35;
}
V_147 = F_86 ( * F_87 ( V_140 ) ,
F_58 ( V_67 , V_2 , V_4 ,
V_67 -> V_166 ,
V_110 ,
& V_111 ) ,
V_147 ) ;
F_62 ( L_4 , V_111 , V_147 ) ;
if ( V_147 > 0 || V_147 == V_170 )
continue;
V_30 = V_147 ;
if ( V_30 == 0 )
V_30 = - V_171 ;
goto V_35;
}
F_18 ( V_172 ) ;
if ( ! F_28 ( V_173 , & V_2 -> V_26 ) )
F_16 ( V_2 ) ;
F_3 ( V_4 ) ;
return V_139 ;
V_35:
if ( V_134 )
F_88 ( V_67 , F_89 ( V_4 -> V_58 ) , 1 ) ;
if ( V_4 )
F_3 ( V_4 ) ;
return V_30 ;
}
int
F_90 ( struct V_1 * V_2 , T_4 V_110 )
{
struct V_3 * V_4 ;
unsigned long V_6 ;
int V_30 = 0 ;
V_4 = F_79 ( 0 , V_174 ) ;
if ( ! V_4 ) {
V_30 = - V_34 ;
goto V_35;
}
V_4 -> V_104 = V_2 -> V_160 ;
V_4 -> V_38 . V_39 = 1 ;
F_84 ( V_2 ) ;
V_30 = F_85 ( V_2 -> V_164 , V_110 , 1 , NULL ) ;
if ( V_30 )
goto V_35;
F_4 ( & V_2 -> V_19 , V_6 ) ;
F_46 ( & V_4 -> V_42 , & V_2 -> V_24 ) ;
F_6 ( V_44 , & V_4 -> V_21 ) ;
F_26 ( V_4 ) ;
V_4 -> V_45 . V_107 = V_2 ;
F_60 ( & V_4 -> V_45 . V_46 , 0 , V_110 ,
V_2 -> V_113 ) ;
V_2 -> V_113 ++ ;
F_8 ( & V_2 -> V_19 , V_6 ) ;
F_18 ( V_172 ) ;
F_18 ( V_175 ) ;
if ( ! F_28 ( V_173 , & V_2 -> V_26 ) )
F_91 ( V_176 , & V_2 -> V_177 , 0 ) ;
F_3 ( V_4 ) ;
return 0 ;
V_35:
if ( V_4 )
F_3 ( V_4 ) ;
return V_30 ;
}
