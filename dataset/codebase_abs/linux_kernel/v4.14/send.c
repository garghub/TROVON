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
V_2 -> V_14 -> V_15 = 0 ;
V_2 -> V_16 = V_17 ;
V_2 -> V_18 = V_19 ;
F_4 ( & V_2 -> V_20 , V_6 ) ;
F_5 (rm, tmp, &cp->cp_retrans, m_conn_item) {
F_6 ( V_21 , & V_4 -> V_22 ) ;
F_6 ( V_23 , & V_4 -> V_22 ) ;
}
F_7 ( & V_2 -> V_24 , & V_2 -> V_25 ) ;
F_8 ( & V_2 -> V_20 , V_6 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
return F_10 ( V_26 , & V_2 -> V_27 ) == 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_12 ( V_26 , & V_2 -> V_27 ) ;
F_13 () ;
if ( F_14 ( & V_2 -> V_28 ) )
F_15 ( & V_2 -> V_28 ) ;
}
int F_16 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = V_2 -> V_14 ;
struct V_3 * V_4 ;
unsigned long V_6 ;
unsigned int V_5 ;
struct V_31 * V_32 ;
int V_33 = 0 ;
F_17 ( V_34 ) ;
int V_35 ;
unsigned long V_36 = 0 ;
V_37:
V_35 = 0 ;
if ( ! F_9 ( V_2 ) ) {
F_18 ( V_38 ) ;
V_33 = - V_39 ;
goto V_40;
}
V_36 = F_19 ( V_2 -> V_41 ) + 1 ;
F_20 ( V_2 -> V_41 , V_36 ) ;
if ( ! F_21 ( V_2 ) ) {
F_11 ( V_2 ) ;
V_33 = 0 ;
goto V_40;
}
if ( V_30 -> V_42 -> V_43 )
V_30 -> V_42 -> V_43 ( V_2 ) ;
while ( 1 ) {
V_4 = V_2 -> V_7 ;
if ( ! V_4 && F_22 ( 0 , & V_30 -> V_15 ) ) {
V_4 = F_23 ( V_30 ) ;
if ( F_24 ( V_4 ) ) {
V_33 = F_25 ( V_4 ) ;
break;
}
V_4 -> V_44 . V_45 = 1 ;
V_4 -> V_46 . V_47 = V_2 ;
V_4 -> V_46 . V_48 = V_2 -> V_14 ;
V_2 -> V_7 = V_4 ;
}
if ( ! V_4 ) {
unsigned int V_49 ;
V_35 ++ ;
if ( V_35 >= V_50 )
goto V_51;
F_4 ( & V_2 -> V_20 , V_6 ) ;
if ( ! F_26 ( & V_2 -> V_25 ) ) {
V_4 = F_27 ( V_2 -> V_25 . V_52 ,
struct V_3 ,
V_53 ) ;
F_28 ( V_4 ) ;
F_29 ( & V_4 -> V_53 ,
& V_2 -> V_24 ) ;
}
F_8 ( & V_2 -> V_20 , V_6 ) ;
if ( ! V_4 )
break;
if ( F_30 ( V_54 , & V_4 -> V_22 ) ||
( V_4 -> V_55 . V_45 &&
F_30 ( V_23 , & V_4 -> V_22 ) ) ) {
F_4 ( & V_2 -> V_20 , V_6 ) ;
if ( F_22 ( V_56 , & V_4 -> V_22 ) )
F_31 ( & V_4 -> V_53 , & V_34 ) ;
F_8 ( & V_2 -> V_20 , V_6 ) ;
continue;
}
V_49 = F_32 ( V_4 -> V_46 . V_57 . V_58 ) ;
if ( V_2 -> V_16 == 0 ||
V_2 -> V_18 < V_49 ) {
F_6 ( V_21 , & V_4 -> V_22 ) ;
V_2 -> V_16 =
V_17 ;
V_2 -> V_18 =
V_19 ;
F_18 ( V_59 ) ;
} else {
V_2 -> V_18 -= V_49 ;
V_2 -> V_16 -- ;
}
V_2 -> V_7 = V_4 ;
}
if ( V_4 -> V_55 . V_45 && ! V_2 -> V_12 ) {
V_4 -> V_60 = & V_4 -> V_55 ;
F_6 ( V_61 , & V_4 -> V_22 ) ;
V_33 = V_30 -> V_42 -> V_62 ( V_30 , & V_4 -> V_55 ) ;
if ( V_33 ) {
F_12 ( V_61 , & V_4 -> V_22 ) ;
F_33 ( & V_4 -> V_63 ) ;
break;
}
V_2 -> V_12 = 1 ;
}
if ( V_4 -> V_64 . V_45 && ! V_2 -> V_11 ) {
V_4 -> V_60 = & V_4 -> V_64 ;
F_6 ( V_61 , & V_4 -> V_22 ) ;
V_33 = V_30 -> V_42 -> V_65 ( V_30 , & V_4 -> V_64 ) ;
if ( V_33 ) {
F_12 ( V_61 , & V_4 -> V_22 ) ;
F_33 ( & V_4 -> V_63 ) ;
break;
}
V_2 -> V_11 = 1 ;
}
if ( V_4 -> V_44 . V_66 == 0 ) {
int V_67 ;
int V_68 = 1 ;
V_67 = ( V_4 -> V_64 . V_45 || V_4 -> V_55 . V_45 ) ;
if ( V_4 -> V_64 . V_45 && ! V_4 -> V_64 . V_69 )
V_68 = 0 ;
if ( V_4 -> V_55 . V_45 && ! V_4 -> V_55 . V_69 )
V_68 = 0 ;
if ( V_67 && V_68
&& ! V_4 -> V_70 )
V_4 -> V_44 . V_45 = 0 ;
}
if ( V_4 -> V_44 . V_45 && ! V_2 -> V_13 ) {
V_4 -> V_60 = & V_4 -> V_44 ;
V_33 = V_30 -> V_42 -> V_71 ( V_30 , V_4 ,
V_2 -> V_9 ,
V_2 -> V_8 ,
V_2 -> V_10 ) ;
if ( V_33 <= 0 )
break;
if ( V_2 -> V_9 < sizeof( struct V_72 ) ) {
V_5 = F_34 ( int , V_33 ,
sizeof( struct V_72 ) -
V_2 -> V_9 ) ;
V_2 -> V_9 += V_5 ;
V_33 -= V_5 ;
}
V_32 = & V_4 -> V_44 . V_73 [ V_2 -> V_8 ] ;
while ( V_33 ) {
V_5 = F_34 ( int , V_33 , V_32 -> V_74 -
V_2 -> V_10 ) ;
V_2 -> V_10 += V_5 ;
V_33 -= V_5 ;
if ( V_2 -> V_10 == V_32 -> V_74 ) {
V_2 -> V_10 = 0 ;
V_32 ++ ;
V_2 -> V_8 ++ ;
F_35 ( V_33 != 0 && V_2 -> V_8 ==
V_4 -> V_44 . V_66 ) ;
}
}
if ( V_2 -> V_9 == sizeof( struct V_72 ) &&
( V_2 -> V_8 == V_4 -> V_44 . V_66 ) )
V_2 -> V_13 = 1 ;
}
if ( ! V_4 -> V_44 . V_45 || V_2 -> V_13 ) {
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
V_51:
if ( V_30 -> V_42 -> V_75 )
V_30 -> V_42 -> V_75 ( V_2 ) ;
F_11 ( V_2 ) ;
if ( ! F_26 ( & V_34 ) ) {
F_36 (rm, &to_be_dropped, m_conn_item)
F_3 ( V_4 ) ;
F_37 ( & V_34 , V_76 ) ;
}
if ( V_33 == 0 ) {
bool V_77 ;
F_38 () ;
V_77 = V_36 != F_19 ( V_2 -> V_41 ) ;
if ( ( F_30 ( 0 , & V_30 -> V_15 ) ||
! F_26 ( & V_2 -> V_25 ) ) && ! V_77 ) {
if ( V_35 < V_50 )
goto V_37;
F_39 ( V_78 , & V_2 -> V_79 , 1 ) ;
} else if ( V_77 ) {
F_18 ( V_80 ) ;
}
}
V_40:
return V_33 ;
}
static void F_40 ( struct V_81 * V_82 , struct V_3 * V_4 )
{
T_1 V_49 = F_41 ( V_4 -> V_46 . V_57 . V_58 ) ;
F_42 ( & V_82 -> V_83 ) ;
F_35 ( V_82 -> V_84 < V_49 ) ;
V_82 -> V_84 -= V_49 ;
if ( V_82 -> V_84 == 0 )
F_18 ( V_85 ) ;
}
static inline int F_43 ( struct V_3 * V_4 , T_2 V_86 ,
T_3 V_87 )
{
if ( V_87 )
return V_87 ( V_4 , V_86 ) ;
return F_44 ( V_4 -> V_46 . V_57 . V_88 ) <= V_86 ;
}
void F_45 ( struct V_3 * V_4 , int V_89 )
{
struct V_81 * V_82 = NULL ;
struct V_90 * V_91 ;
struct V_92 * V_93 ;
unsigned long V_6 ;
unsigned int V_94 = 0 ;
F_4 ( & V_4 -> V_95 , V_6 ) ;
V_94 = V_4 -> V_55 . V_96 | V_4 -> V_44 . V_96 ;
V_91 = & V_4 -> V_55 ;
if ( F_30 ( V_97 , & V_4 -> V_22 ) &&
V_91 -> V_45 && V_94 && V_91 -> V_98 ) {
V_93 = V_91 -> V_98 ;
V_82 = V_4 -> V_99 ;
F_46 ( F_47 ( V_82 ) ) ;
V_93 -> V_100 = V_89 ;
F_48 ( & V_82 -> V_83 ) ;
F_49 ( & V_93 -> V_101 , & V_82 -> V_102 ) ;
F_50 ( & V_82 -> V_83 ) ;
V_91 -> V_98 = NULL ;
}
F_8 ( & V_4 -> V_95 , V_6 ) ;
if ( V_82 ) {
F_51 ( V_82 ) ;
F_52 ( F_47 ( V_82 ) ) ;
}
}
void F_53 ( struct V_3 * V_4 , int V_89 )
{
struct V_81 * V_82 = NULL ;
struct V_103 * V_104 ;
struct V_92 * V_93 ;
unsigned long V_6 ;
F_4 ( & V_4 -> V_95 , V_6 ) ;
V_104 = & V_4 -> V_64 ;
if ( F_30 ( V_97 , & V_4 -> V_22 )
&& V_104 -> V_45 && V_104 -> V_96 && V_104 -> V_98 ) {
V_93 = V_104 -> V_98 ;
V_82 = V_4 -> V_99 ;
F_46 ( F_47 ( V_82 ) ) ;
V_93 -> V_100 = V_89 ;
F_48 ( & V_82 -> V_83 ) ;
F_49 ( & V_93 -> V_101 , & V_82 -> V_102 ) ;
F_50 ( & V_82 -> V_83 ) ;
V_104 -> V_98 = NULL ;
}
F_8 ( & V_4 -> V_95 , V_6 ) ;
if ( V_82 ) {
F_51 ( V_82 ) ;
F_52 ( F_47 ( V_82 ) ) ;
}
}
static inline void
F_54 ( struct V_81 * V_82 , struct V_3 * V_4 , int V_89 )
{
struct V_90 * V_91 ;
struct V_103 * V_104 ;
V_91 = & V_4 -> V_55 ;
if ( V_91 -> V_45 && V_91 -> V_96 && V_91 -> V_98 ) {
V_91 -> V_98 -> V_100 = V_89 ;
F_49 ( & V_91 -> V_98 -> V_101 , & V_82 -> V_102 ) ;
V_91 -> V_98 = NULL ;
}
V_104 = & V_4 -> V_64 ;
if ( V_104 -> V_45 && V_104 -> V_96 && V_104 -> V_98 ) {
V_104 -> V_98 -> V_100 = V_89 ;
F_49 ( & V_104 -> V_98 -> V_101 , & V_82 -> V_102 ) ;
V_104 -> V_98 = NULL ;
}
}
static void F_37 ( struct V_105 * V_106 , int V_89 )
{
unsigned long V_6 ;
struct V_81 * V_82 = NULL ;
struct V_3 * V_4 ;
while ( ! F_26 ( V_106 ) ) {
int V_107 = 0 ;
V_4 = F_27 ( V_106 -> V_52 , struct V_3 ,
V_53 ) ;
F_55 ( & V_4 -> V_53 ) ;
F_4 ( & V_4 -> V_95 , V_6 ) ;
if ( ! F_30 ( V_97 , & V_4 -> V_22 ) )
goto V_108;
if ( V_82 != V_4 -> V_99 ) {
if ( V_82 ) {
F_51 ( V_82 ) ;
F_52 ( F_47 ( V_82 ) ) ;
}
V_82 = V_4 -> V_99 ;
if ( V_82 )
F_46 ( F_47 ( V_82 ) ) ;
}
if ( ! V_82 )
goto V_108;
F_48 ( & V_82 -> V_83 ) ;
if ( F_22 ( V_97 , & V_4 -> V_22 ) ) {
struct V_90 * V_91 = & V_4 -> V_55 ;
struct V_92 * V_93 ;
F_55 ( & V_4 -> V_109 ) ;
F_40 ( V_82 , V_4 ) ;
if ( V_91 -> V_45 && V_91 -> V_98 &&
( V_91 -> V_96 || ( V_91 -> V_110 && V_89 ) ) ) {
V_93 = V_91 -> V_98 ;
F_49 ( & V_93 -> V_101 ,
& V_82 -> V_102 ) ;
if ( ! V_93 -> V_100 )
V_93 -> V_100 = V_89 ;
V_4 -> V_55 . V_98 = NULL ;
}
V_107 = 1 ;
V_4 -> V_99 = NULL ;
}
F_50 ( & V_82 -> V_83 ) ;
V_108:
F_8 ( & V_4 -> V_95 , V_6 ) ;
F_3 ( V_4 ) ;
if ( V_107 )
F_3 ( V_4 ) ;
}
if ( V_82 ) {
F_51 ( V_82 ) ;
F_52 ( F_47 ( V_82 ) ) ;
}
}
void F_56 ( struct V_1 * V_2 , T_2 V_86 ,
T_3 V_87 )
{
struct V_3 * V_4 , * V_5 ;
unsigned long V_6 ;
F_17 ( V_111 ) ;
F_4 ( & V_2 -> V_20 , V_6 ) ;
F_5 (rm, tmp, &cp->cp_retrans, m_conn_item) {
if ( ! F_43 ( V_4 , V_86 , V_87 ) )
break;
F_31 ( & V_4 -> V_53 , & V_111 ) ;
F_12 ( V_56 , & V_4 -> V_22 ) ;
}
if ( ! F_26 ( & V_111 ) )
F_13 () ;
F_8 ( & V_2 -> V_20 , V_6 ) ;
F_37 ( & V_111 , V_112 ) ;
}
void F_57 ( struct V_29 * V_30 , T_2 V_86 ,
T_3 V_87 )
{
F_58 ( V_30 -> V_42 -> V_113 ) ;
F_56 ( & V_30 -> V_114 [ 0 ] , V_86 , V_87 ) ;
}
void F_59 ( struct V_81 * V_82 , struct V_115 * V_116 )
{
struct V_3 * V_4 , * V_5 ;
struct V_29 * V_30 ;
struct V_1 * V_2 ;
unsigned long V_6 ;
F_17 ( V_111 ) ;
F_4 ( & V_82 -> V_83 , V_6 ) ;
F_5 (rm, tmp, &rs->rs_send_queue, m_sock_item) {
if ( V_116 && ( V_116 -> V_117 . V_118 != V_4 -> V_119 ||
V_116 -> V_120 != V_4 -> V_46 . V_57 . V_121 ) )
continue;
F_31 ( & V_4 -> V_109 , & V_111 ) ;
F_40 ( V_82 , V_4 ) ;
F_12 ( V_97 , & V_4 -> V_22 ) ;
}
F_13 () ;
F_8 ( & V_82 -> V_83 , V_6 ) ;
if ( F_26 ( & V_111 ) )
return;
F_36 (rm, &list, m_sock_item) {
V_30 = V_4 -> V_46 . V_48 ;
if ( V_30 -> V_42 -> V_113 )
V_2 = V_4 -> V_46 . V_47 ;
else
V_2 = & V_30 -> V_114 [ 0 ] ;
F_4 ( & V_2 -> V_20 , V_6 ) ;
if ( ! F_22 ( V_56 , & V_4 -> V_22 ) ) {
F_8 ( & V_2 -> V_20 , V_6 ) ;
F_4 ( & V_4 -> V_95 , V_6 ) ;
V_4 -> V_99 = NULL ;
F_8 ( & V_4 -> V_95 , V_6 ) ;
continue;
}
F_55 ( & V_4 -> V_53 ) ;
F_8 ( & V_2 -> V_20 , V_6 ) ;
F_4 ( & V_4 -> V_95 , V_6 ) ;
F_48 ( & V_82 -> V_83 ) ;
F_54 ( V_82 , V_4 , V_122 ) ;
F_50 ( & V_82 -> V_83 ) ;
V_4 -> V_99 = NULL ;
F_8 ( & V_4 -> V_95 , V_6 ) ;
F_3 ( V_4 ) ;
}
F_51 ( V_82 ) ;
while ( ! F_26 ( & V_111 ) ) {
V_4 = F_27 ( V_111 . V_52 , struct V_3 , V_109 ) ;
F_55 ( & V_4 -> V_109 ) ;
F_60 ( V_4 ) ;
F_4 ( & V_4 -> V_95 , V_6 ) ;
F_48 ( & V_82 -> V_83 ) ;
F_54 ( V_82 , V_4 , V_122 ) ;
F_50 ( & V_82 -> V_83 ) ;
V_4 -> V_99 = NULL ;
F_8 ( & V_4 -> V_95 , V_6 ) ;
F_3 ( V_4 ) ;
}
}
static int F_61 ( struct V_81 * V_82 , struct V_29 * V_30 ,
struct V_1 * V_2 ,
struct V_3 * V_4 , T_4 V_123 ,
T_4 V_124 , int * V_125 )
{
unsigned long V_6 ;
T_1 V_49 ;
if ( * V_125 )
goto V_40;
V_49 = F_41 ( V_4 -> V_46 . V_57 . V_58 ) ;
F_4 ( & V_82 -> V_83 , V_6 ) ;
if ( V_82 -> V_84 < F_62 ( V_82 ) ) {
V_82 -> V_84 += V_49 ;
if ( V_82 -> V_84 >= F_62 ( V_82 ) / 2 )
F_6 ( V_21 , & V_4 -> V_22 ) ;
F_49 ( & V_4 -> V_109 , & V_82 -> V_126 ) ;
F_6 ( V_97 , & V_4 -> V_22 ) ;
F_28 ( V_4 ) ;
V_4 -> V_99 = V_82 ;
F_63 ( & V_4 -> V_46 . V_57 , V_123 , V_124 , 0 ) ;
V_4 -> V_46 . V_48 = V_30 ;
V_4 -> V_46 . V_47 = V_2 ;
F_28 ( V_4 ) ;
F_48 ( & V_2 -> V_20 ) ;
V_4 -> V_46 . V_57 . V_88 = F_64 ( V_2 -> V_127 ++ ) ;
F_49 ( & V_4 -> V_53 , & V_2 -> V_25 ) ;
F_6 ( V_56 , & V_4 -> V_22 ) ;
F_50 ( & V_2 -> V_20 ) ;
F_65 ( L_1 ,
V_4 , V_49 , V_82 , V_82 -> V_84 ,
( unsigned long long ) F_44 ( V_4 -> V_46 . V_57 . V_88 ) ) ;
* V_125 = 1 ;
}
F_8 ( & V_82 -> V_83 , V_6 ) ;
V_40:
return * V_125 ;
}
static int F_66 ( struct V_128 * V_129 , int V_130 )
{
struct V_131 * V_132 ;
int V_133 = 0 ;
int V_134 = 0 ;
int V_135 ;
F_67 (cmsg, msg) {
if ( ! F_68 ( V_129 , V_132 ) )
return - V_136 ;
if ( V_132 -> V_137 != V_138 )
continue;
switch ( V_132 -> V_139 ) {
case V_140 :
V_134 |= 1 ;
V_135 = F_69 ( F_70 ( V_132 ) ) ;
if ( V_135 < 0 )
return V_135 ;
V_133 += V_135 ;
break;
case V_141 :
case V_142 :
V_134 |= 2 ;
break;
case V_143 :
case V_144 :
case V_145 :
case V_146 :
V_134 |= 1 ;
V_133 += sizeof( struct V_31 ) ;
break;
default:
return - V_136 ;
}
}
V_133 += ceil ( V_130 , V_147 ) * sizeof( struct V_31 ) ;
if ( V_134 == 3 )
return - V_136 ;
return V_133 ;
}
static int F_71 ( struct V_81 * V_82 , struct V_3 * V_4 ,
struct V_128 * V_129 , int * V_148 )
{
struct V_131 * V_132 ;
int V_33 = 0 ;
F_67 (cmsg, msg) {
if ( ! F_68 ( V_129 , V_132 ) )
return - V_136 ;
if ( V_132 -> V_137 != V_138 )
continue;
switch ( V_132 -> V_139 ) {
case V_140 :
V_33 = F_72 ( V_82 , V_4 , V_132 ) ;
break;
case V_141 :
V_33 = F_73 ( V_82 , V_4 , V_132 ) ;
break;
case V_142 :
V_33 = F_74 ( V_82 , V_4 , V_132 ) ;
if ( ! V_33 )
* V_148 = 1 ;
else if ( V_33 == - V_149 )
V_33 = - V_150 ;
break;
case V_143 :
case V_144 :
case V_145 :
case V_146 :
V_33 = F_75 ( V_82 , V_4 , V_132 ) ;
break;
default:
return - V_136 ;
}
if ( V_33 )
break;
}
return V_33 ;
}
static int F_76 ( struct V_81 * V_82 , struct V_29 * V_30 )
{
int V_151 ;
if ( V_30 -> V_152 == 0 )
V_151 = F_77 ( V_82 , V_153 ) ;
else
V_151 = F_77 ( V_82 , V_30 -> V_152 ) ;
if ( V_30 -> V_152 == 0 && V_151 != 0 ) {
F_78 ( V_30 , 0 ) ;
if ( V_30 -> V_152 == 0 ) {
F_79 ( V_30 -> V_154 ,
( V_30 -> V_152 != 0 ) ) ;
}
if ( V_30 -> V_152 == 1 )
V_151 = 0 ;
}
return V_151 ;
}
static int F_80 ( struct V_128 * V_129 , T_5 * V_155 )
{
struct V_156 * args ;
struct V_131 * V_132 ;
F_67 (cmsg, msg) {
if ( ! F_68 ( V_129 , V_132 ) )
return - V_136 ;
if ( V_132 -> V_137 != V_138 )
continue;
if ( V_132 -> V_139 == V_140 ) {
args = F_70 ( V_132 ) ;
* V_155 += args -> V_157 . V_158 ;
}
}
return 0 ;
}
int F_81 ( struct V_159 * V_160 , struct V_128 * V_129 , T_5 V_161 )
{
struct V_160 * V_162 = V_160 -> V_162 ;
struct V_81 * V_82 = F_82 ( V_162 ) ;
F_83 ( struct V_115 * , V_163 , V_129 -> V_164 ) ;
T_6 V_165 ;
T_4 V_124 ;
struct V_3 * V_4 = NULL ;
struct V_29 * V_30 ;
int V_33 = 0 ;
int V_125 = 0 , V_148 = 0 ;
int V_166 = V_129 -> V_167 & V_168 ;
long V_169 = F_84 ( V_162 , V_166 ) ;
struct V_1 * V_170 ;
T_5 V_171 = V_161 , V_172 = 0 ;
if ( V_129 -> V_167 & ~ ( V_168 | V_173 ) ) {
V_33 = - V_174 ;
goto V_40;
}
if ( V_129 -> V_175 ) {
if ( V_129 -> V_175 < sizeof( * V_163 ) || V_163 -> V_176 != V_177 ) {
V_33 = - V_136 ;
goto V_40;
}
V_165 = V_163 -> V_117 . V_118 ;
V_124 = V_163 -> V_120 ;
} else {
F_85 ( V_162 ) ;
V_165 = V_82 -> V_178 ;
V_124 = V_82 -> V_179 ;
F_86 ( V_162 ) ;
}
F_85 ( V_162 ) ;
if ( V_165 == 0 || V_82 -> V_180 == 0 ) {
F_86 ( V_162 ) ;
V_33 = - V_181 ;
goto V_40;
}
F_86 ( V_162 ) ;
V_33 = F_80 ( V_129 , & V_172 ) ;
if ( V_33 )
goto V_40;
V_171 += V_172 ;
if ( F_87 ( T_5 , V_161 , V_172 ) > V_182 ) {
V_33 = - V_183 ;
goto V_40;
}
if ( V_161 > F_62 ( V_82 ) ) {
V_33 = - V_183 ;
goto V_40;
}
V_33 = F_66 ( V_129 , V_161 ) ;
if ( V_33 < 0 )
goto V_40;
V_4 = F_88 ( V_33 , V_184 ) ;
if ( ! V_4 ) {
V_33 = - V_39 ;
goto V_40;
}
if ( V_161 ) {
V_4 -> V_44 . V_73 = F_89 ( V_4 , ceil ( V_161 , V_147 ) ) ;
if ( ! V_4 -> V_44 . V_73 ) {
V_33 = - V_39 ;
goto V_40;
}
V_33 = F_90 ( V_4 , & V_129 -> V_185 ) ;
if ( V_33 )
goto V_40;
}
V_4 -> V_44 . V_45 = 1 ;
V_4 -> V_119 = V_165 ;
if ( V_82 -> V_186 && V_82 -> V_186 -> V_187 == V_165 )
V_30 = V_82 -> V_186 ;
else {
V_30 = F_91 ( F_92 ( V_160 -> V_162 ) ,
V_82 -> V_180 , V_165 ,
V_82 -> V_188 ,
V_160 -> V_162 -> V_189 ) ;
if ( F_24 ( V_30 ) ) {
V_33 = F_25 ( V_30 ) ;
goto V_40;
}
V_82 -> V_186 = V_30 ;
}
V_33 = F_71 ( V_82 , V_4 , V_129 , & V_148 ) ;
if ( V_33 ) {
if ( V_33 == - V_150 )
F_93 ( V_30 ) ;
goto V_40;
}
if ( V_4 -> V_55 . V_45 && ! V_30 -> V_42 -> V_62 ) {
F_94 ( V_190 L_2 ,
& V_4 -> V_55 , V_30 -> V_42 -> V_62 ) ;
V_33 = - V_174 ;
goto V_40;
}
if ( V_4 -> V_64 . V_45 && ! V_30 -> V_42 -> V_65 ) {
F_94 ( V_190 L_3 ,
& V_4 -> V_64 , V_30 -> V_42 -> V_65 ) ;
V_33 = - V_174 ;
goto V_40;
}
if ( V_30 -> V_42 -> V_113 )
V_170 = & V_30 -> V_114 [ F_76 ( V_82 , V_30 ) ] ;
else
V_170 = & V_30 -> V_114 [ 0 ] ;
F_95 ( V_170 ) ;
V_33 = F_96 ( V_30 -> V_191 , V_124 , V_166 , V_82 ) ;
if ( V_33 ) {
V_82 -> V_192 = 1 ;
goto V_40;
}
while ( ! F_61 ( V_82 , V_30 , V_170 , V_4 , V_82 -> V_193 ,
V_124 , & V_125 ) ) {
F_18 ( V_194 ) ;
if ( V_166 ) {
V_33 = - V_150 ;
goto V_40;
}
V_169 = F_97 ( * F_98 ( V_162 ) ,
F_61 ( V_82 , V_30 , V_170 , V_4 ,
V_82 -> V_193 ,
V_124 ,
& V_125 ) ,
V_169 ) ;
F_65 ( L_4 , V_125 , V_169 ) ;
if ( V_169 > 0 || V_169 == V_195 )
continue;
V_33 = V_169 ;
if ( V_33 == 0 )
V_33 = - V_196 ;
goto V_40;
}
F_18 ( V_197 ) ;
V_33 = F_16 ( V_170 ) ;
if ( V_33 == - V_39 || V_33 == - V_150 )
F_39 ( V_78 , & V_170 -> V_79 , 1 ) ;
F_3 ( V_4 ) ;
return V_161 ;
V_40:
if ( V_148 )
F_99 ( V_82 , F_100 ( V_4 -> V_70 ) , 1 ) ;
if ( V_4 )
F_3 ( V_4 ) ;
return V_33 ;
}
static int
F_101 ( struct V_1 * V_2 , T_4 V_123 ,
T_4 V_124 , T_7 V_198 )
{
struct V_3 * V_4 ;
unsigned long V_6 ;
int V_33 = 0 ;
V_4 = F_88 ( 0 , V_199 ) ;
if ( ! V_4 ) {
V_33 = - V_39 ;
goto V_40;
}
V_4 -> V_119 = V_2 -> V_14 -> V_187 ;
V_4 -> V_44 . V_45 = 1 ;
F_95 ( V_2 ) ;
V_33 = F_96 ( V_2 -> V_14 -> V_191 , V_124 , 1 , NULL ) ;
if ( V_33 )
goto V_40;
F_4 ( & V_2 -> V_20 , V_6 ) ;
F_49 ( & V_4 -> V_53 , & V_2 -> V_25 ) ;
F_6 ( V_56 , & V_4 -> V_22 ) ;
F_28 ( V_4 ) ;
V_4 -> V_46 . V_48 = V_2 -> V_14 ;
V_4 -> V_46 . V_47 = V_2 ;
F_63 ( & V_4 -> V_46 . V_57 , V_123 , V_124 ,
V_2 -> V_127 ) ;
V_4 -> V_46 . V_57 . V_198 |= V_198 ;
V_2 -> V_127 ++ ;
if ( F_102 ( F_103 ( V_123 ) , F_103 ( V_124 ) ) &&
V_2 -> V_14 -> V_42 -> V_113 ) {
T_8 V_200 = F_104 ( V_153 ) ;
T_1 V_201 = F_105 ( V_2 -> V_14 -> V_202 ) ;
F_106 ( & V_4 -> V_46 . V_57 ,
V_203 , & V_200 ,
sizeof( V_200 ) ) ;
F_106 ( & V_4 -> V_46 . V_57 ,
V_204 ,
& V_201 ,
sizeof( T_1 ) ) ;
}
F_8 ( & V_2 -> V_20 , V_6 ) ;
F_18 ( V_197 ) ;
F_18 ( V_205 ) ;
F_39 ( V_78 , & V_2 -> V_79 , 1 ) ;
F_3 ( V_4 ) ;
return 0 ;
V_40:
if ( V_4 )
F_3 ( V_4 ) ;
return V_33 ;
}
int
F_107 ( struct V_1 * V_2 , T_4 V_124 )
{
return F_101 ( V_2 , 0 , V_124 , 0 ) ;
}
void
F_78 ( struct V_29 * V_30 , int V_206 )
{
unsigned long V_6 ;
struct V_1 * V_2 = & V_30 -> V_114 [ V_206 ] ;
F_4 ( & V_2 -> V_20 , V_6 ) ;
if ( V_30 -> V_207 ) {
F_8 ( & V_2 -> V_20 , V_6 ) ;
return;
}
V_30 -> V_207 = 1 ;
F_8 ( & V_2 -> V_20 , V_6 ) ;
F_101 ( V_2 , F_104 ( V_208 ) , 0 , 0 ) ;
}
