static T_1 F_1 ( const struct V_1 * V_1 , const T_2 V_2 ,
const T_3 V_3 , const T_2 V_4 ,
const T_4 V_5 )
{
static T_1 T_5 V_6 ;
F_2 ( & T_5 , sizeof( T_5 ) ) ;
return F_3 ( V_2 , V_3 , V_4 , V_5 ,
T_5 + F_4 ( V_1 ) ) ;
}
T_1 F_5 ( const struct V_7 * V_8 )
{
#if F_6 ( V_9 )
if ( V_8 -> V_10 == V_11 &&
! F_7 ( & V_8 -> V_12 ) )
return F_8 ( F_9 ( V_8 ) ,
& V_8 -> V_13 , V_8 -> V_14 ,
& V_8 -> V_12 , V_8 -> V_15 ) ;
#endif
return F_1 ( F_9 ( V_8 ) ,
V_8 -> V_16 , V_8 -> V_14 ,
V_8 -> V_17 , V_8 -> V_15 ) ;
}
struct V_18 * F_10 ( struct V_19 * V_20 ,
struct V_1 * V_1 ,
struct V_21 * V_22 ,
const unsigned short V_23 )
{
struct V_18 * V_24 = F_11 ( V_20 , V_25 ) ;
if ( V_24 ) {
F_12 ( & V_24 -> V_26 , V_1 ) ;
V_24 -> V_27 = V_23 ;
V_24 -> V_28 = 0 ;
V_24 -> V_29 = 0 ;
V_24 -> V_30 = 0 ;
F_13 ( & V_24 -> V_31 ) ;
F_14 ( & V_24 -> V_32 , & V_22 -> V_33 ) ;
}
return V_24 ;
}
void F_15 ( struct V_19 * V_20 , struct V_18 * V_24 )
{
if ( F_16 ( & V_24 -> V_31 ) ) {
F_17 ( & V_24 -> V_32 ) ;
F_18 ( V_20 , V_24 ) ;
}
}
void F_19 ( struct V_7 * V_8 , struct V_18 * V_24 ,
const unsigned short V_23 )
{
F_20 ( V_8 ) -> V_34 = V_23 ;
F_21 ( V_8 , & V_24 -> V_31 ) ;
V_24 -> V_30 ++ ;
F_22 ( V_8 ) -> V_35 = V_24 ;
}
static void F_23 ( struct V_7 * V_8 )
{
struct V_36 * V_37 = V_8 -> V_38 -> V_39 . V_37 ;
const int V_40 = F_24 ( F_9 ( V_8 ) , F_20 ( V_8 ) -> V_34 ,
V_37 -> V_41 ) ;
struct V_21 * V_22 = & V_37 -> V_40 [ V_40 ] ;
struct V_18 * V_24 ;
F_25 ( & V_22 -> V_42 ) ;
V_24 = F_22 ( V_8 ) -> V_35 ;
F_26 ( V_8 ) ;
V_24 -> V_30 -- ;
F_22 ( V_8 ) -> V_35 = NULL ;
F_20 ( V_8 ) -> V_34 = 0 ;
F_15 ( V_37 -> V_43 , V_24 ) ;
F_27 ( & V_22 -> V_42 ) ;
}
void F_28 ( struct V_7 * V_8 )
{
F_29 () ;
F_23 ( V_8 ) ;
F_30 () ;
}
int F_31 ( const struct V_7 * V_8 , struct V_7 * V_44 )
{
struct V_36 * V_45 = V_8 -> V_38 -> V_39 . V_37 ;
unsigned short V_27 = F_20 ( V_44 ) -> V_34 ;
const int V_40 = F_24 ( F_9 ( V_8 ) , V_27 ,
V_45 -> V_41 ) ;
struct V_21 * V_22 = & V_45 -> V_40 [ V_40 ] ;
struct V_18 * V_24 ;
F_25 ( & V_22 -> V_42 ) ;
V_24 = F_22 ( V_8 ) -> V_35 ;
if ( F_32 ( ! V_24 ) ) {
F_27 ( & V_22 -> V_42 ) ;
return - V_46 ;
}
if ( V_24 -> V_27 != V_27 ) {
F_33 (tb, &head->chain) {
if ( F_34 ( V_26 ( V_24 ) , F_9 ( V_8 ) ) &&
V_24 -> V_27 == V_27 )
break;
}
if ( ! V_24 ) {
V_24 = F_10 ( V_45 -> V_43 ,
F_9 ( V_8 ) , V_22 , V_27 ) ;
if ( ! V_24 ) {
F_27 ( & V_22 -> V_42 ) ;
return - V_47 ;
}
}
}
F_19 ( V_44 , V_24 , V_27 ) ;
F_27 ( & V_22 -> V_42 ) ;
return 0 ;
}
static inline int F_35 ( struct V_7 * V_8 , struct V_1 * V_1 ,
const unsigned short V_48 , const T_2 V_49 ,
const int V_50 , bool V_51 )
{
int V_52 = - 1 ;
struct V_53 * V_54 = F_20 ( V_8 ) ;
if ( F_34 ( F_9 ( V_8 ) , V_1 ) && V_54 -> V_34 == V_48 &&
! F_36 ( V_8 ) ) {
T_2 V_55 = V_54 -> V_56 ;
V_52 = V_8 -> V_10 == V_57 ? 2 : 1 ;
if ( V_55 ) {
if ( V_55 != V_49 )
return - 1 ;
V_52 += 4 ;
}
if ( V_8 -> V_58 || V_51 ) {
if ( V_8 -> V_58 != V_50 )
return - 1 ;
V_52 += 4 ;
}
if ( V_8 -> V_59 == F_37 () )
V_52 ++ ;
}
return V_52 ;
}
struct V_7 * F_38 ( struct V_1 * V_1 ,
struct V_36 * V_37 ,
struct V_60 * V_61 , int V_62 ,
const T_2 V_63 , T_4 V_64 ,
const T_2 V_49 , const unsigned short V_48 ,
const int V_50 )
{
unsigned int V_65 = F_39 ( V_1 , V_48 ) ;
struct V_66 * V_67 = & V_37 -> V_68 [ V_65 ] ;
int V_52 , V_69 = 0 , V_70 = 0 , V_71 = 0 ;
bool V_51 = F_40 ( V_1 , V_61 ) ;
struct V_7 * V_8 , * V_72 = NULL ;
T_1 V_73 = 0 ;
F_41 (sk, &ilb->head) {
V_52 = F_35 ( V_8 , V_1 , V_48 , V_49 , V_50 , V_51 ) ;
if ( V_52 > V_69 ) {
V_71 = V_8 -> V_74 ;
if ( V_71 ) {
V_73 = F_1 ( V_1 , V_49 , V_48 ,
V_63 , V_64 ) ;
V_72 = F_42 ( V_8 , V_73 ,
V_61 , V_62 ) ;
if ( V_72 )
return V_72 ;
V_70 = 1 ;
}
V_72 = V_8 ;
V_69 = V_52 ;
} else if ( V_52 == V_69 && V_71 ) {
V_70 ++ ;
if ( F_43 ( V_73 , V_70 ) == 0 )
V_72 = V_8 ;
V_73 = F_44 ( V_73 ) ;
}
}
return V_72 ;
}
void F_45 ( struct V_7 * V_8 )
{
if ( ! F_46 ( & V_8 -> V_75 ) )
return;
if ( V_8 -> V_76 == V_77 )
F_47 ( F_48 ( V_8 ) ) ;
else if ( V_8 -> V_76 == V_78 )
F_49 ( F_50 ( V_8 ) ) ;
else
F_51 ( V_8 ) ;
}
void F_52 ( struct V_60 * V_61 )
{
F_45 ( V_61 -> V_8 ) ;
}
struct V_7 * F_53 ( struct V_1 * V_1 ,
struct V_36 * V_37 ,
const T_2 V_63 , const T_4 V_64 ,
const T_2 V_49 , const T_6 V_48 ,
const int V_50 )
{
F_54 ( V_79 , V_63 , V_49 ) ;
const T_7 V_80 = F_55 ( V_64 , V_48 ) ;
struct V_7 * V_8 ;
const struct V_81 * V_32 ;
unsigned int V_65 = F_1 ( V_1 , V_49 , V_48 , V_63 , V_64 ) ;
unsigned int V_82 = V_65 & V_37 -> V_83 ;
struct V_84 * V_22 = & V_37 -> V_85 [ V_82 ] ;
V_86:
F_56 (sk, node, &head->chain) {
if ( V_8 -> V_87 != V_65 )
continue;
if ( F_57 ( F_58 ( V_8 , V_1 , V_79 ,
V_63 , V_49 , V_80 , V_50 ) ) ) {
if ( F_32 ( ! F_59 ( & V_8 -> V_75 ) ) )
goto V_88;
if ( F_32 ( ! F_58 ( V_8 , V_1 , V_79 ,
V_63 , V_49 , V_80 , V_50 ) ) ) {
F_45 ( V_8 ) ;
goto V_86;
}
goto V_89;
}
}
if ( F_60 ( V_32 ) != V_82 )
goto V_86;
V_88:
V_8 = NULL ;
V_89:
return V_8 ;
}
static int F_61 ( struct V_90 * V_91 ,
struct V_7 * V_8 , T_3 V_3 ,
struct V_92 * * V_93 )
{
struct V_36 * V_94 = V_91 -> V_37 ;
struct V_53 * V_54 = F_20 ( V_8 ) ;
T_2 V_49 = V_54 -> V_56 ;
T_2 V_63 = V_54 -> V_95 ;
int V_50 = V_8 -> V_58 ;
F_54 ( V_79 , V_63 , V_49 ) ;
const T_7 V_80 = F_55 ( V_54 -> V_96 , V_3 ) ;
struct V_1 * V_1 = F_9 ( V_8 ) ;
unsigned int V_65 = F_1 ( V_1 , V_49 , V_3 ,
V_63 , V_54 -> V_96 ) ;
struct V_84 * V_22 = V_84 ( V_94 , V_65 ) ;
T_8 * V_42 = F_62 ( V_94 , V_65 ) ;
struct V_7 * V_97 ;
const struct V_81 * V_32 ;
struct V_92 * V_98 = NULL ;
F_25 ( V_42 ) ;
F_63 (sk2, node, &head->chain) {
if ( V_97 -> V_87 != V_65 )
continue;
if ( F_57 ( F_58 ( V_97 , V_1 , V_79 ,
V_63 , V_49 , V_80 , V_50 ) ) ) {
if ( V_97 -> V_76 == V_77 ) {
V_98 = F_48 ( V_97 ) ;
if ( F_64 ( V_8 , V_97 , V_93 ) )
break;
}
goto V_99;
}
}
V_54 -> V_34 = V_3 ;
V_54 -> V_100 = F_65 ( V_3 ) ;
V_8 -> V_87 = V_65 ;
F_66 ( ! F_67 ( V_8 ) ) ;
F_68 ( V_8 , & V_22 -> V_33 ) ;
if ( V_98 ) {
F_69 ( (struct V_7 * ) V_98 ) ;
F_70 ( V_1 , V_101 ) ;
}
F_27 ( V_42 ) ;
F_71 ( F_9 ( V_8 ) , V_8 -> V_38 , 1 ) ;
if ( V_93 ) {
* V_93 = V_98 ;
} else if ( V_98 ) {
F_72 ( V_98 ) ;
}
return 0 ;
V_99:
F_27 ( V_42 ) ;
return - V_102 ;
}
static T_1 F_73 ( const struct V_7 * V_8 )
{
const struct V_53 * V_54 = F_20 ( V_8 ) ;
return F_74 ( V_54 -> V_56 ,
V_54 -> V_95 ,
V_54 -> V_96 ) ;
}
bool F_75 ( struct V_7 * V_8 , struct V_7 * V_103 )
{
struct V_36 * V_37 = V_8 -> V_38 -> V_39 . V_37 ;
struct V_104 * V_105 ;
struct V_84 * V_22 ;
T_8 * V_42 ;
bool V_106 = true ;
F_76 ( ! F_67 ( V_8 ) ) ;
V_8 -> V_87 = F_5 ( V_8 ) ;
V_22 = V_84 ( V_37 , V_8 -> V_87 ) ;
V_105 = & V_22 -> V_33 ;
V_42 = F_62 ( V_37 , V_8 -> V_87 ) ;
F_25 ( V_42 ) ;
if ( V_103 ) {
F_76 ( V_8 -> V_87 != V_103 -> V_87 ) ;
V_106 = F_69 ( V_103 ) ;
}
if ( V_106 )
F_68 ( V_8 , V_105 ) ;
F_27 ( V_42 ) ;
return V_106 ;
}
bool F_77 ( struct V_7 * V_8 , struct V_7 * V_103 )
{
bool V_107 = F_75 ( V_8 , V_103 ) ;
if ( V_107 ) {
F_71 ( F_9 ( V_8 ) , V_8 -> V_38 , 1 ) ;
} else {
F_78 ( V_8 -> V_38 -> V_108 ) ;
V_8 -> V_76 = V_109 ;
F_79 ( V_8 , V_110 ) ;
F_80 ( V_8 ) ;
}
return V_107 ;
}
static int F_81 ( struct V_7 * V_8 ,
struct V_66 * V_67 ,
int (* F_82)( const struct V_7 * V_111 ,
const struct V_7 * V_97 ,
bool V_112 ) )
{
struct V_18 * V_24 = F_22 ( V_8 ) -> V_35 ;
struct V_7 * V_97 ;
T_9 V_113 = F_83 ( V_8 ) ;
F_41 (sk2, &ilb->head) {
if ( V_97 != V_8 &&
V_97 -> V_10 == V_8 -> V_10 &&
F_36 ( V_97 ) == F_36 ( V_8 ) &&
V_97 -> V_58 == V_8 -> V_58 &&
F_22 ( V_97 ) -> V_35 == V_24 &&
V_97 -> V_74 && F_84 ( V_113 , F_83 ( V_97 ) ) &&
F_82 ( V_8 , V_97 , false ) )
return F_85 ( V_8 , V_97 ) ;
}
if ( ! F_86 ( V_8 -> V_114 ) )
return F_87 ( V_8 ) ;
return 0 ;
}
int F_88 ( struct V_7 * V_8 , struct V_7 * V_103 ,
int (* F_82)( const struct V_7 * V_111 ,
const struct V_7 * V_97 ,
bool V_112 ) )
{
struct V_36 * V_37 = V_8 -> V_38 -> V_39 . V_37 ;
struct V_66 * V_67 ;
int V_115 = 0 ;
if ( V_8 -> V_76 != V_116 ) {
F_77 ( V_8 , V_103 ) ;
return 0 ;
}
F_66 ( ! F_67 ( V_8 ) ) ;
V_67 = & V_37 -> V_68 [ F_89 ( V_8 ) ] ;
F_25 ( & V_67 -> V_42 ) ;
if ( V_8 -> V_74 ) {
V_115 = F_81 ( V_8 , V_67 , F_82 ) ;
if ( V_115 )
goto V_117;
}
if ( F_6 ( V_9 ) && V_8 -> V_74 &&
V_8 -> V_10 == V_11 )
F_90 ( & V_8 -> V_118 , & V_67 -> V_22 ) ;
else
F_91 ( & V_8 -> V_118 , & V_67 -> V_22 ) ;
F_79 ( V_8 , V_119 ) ;
F_71 ( F_9 ( V_8 ) , V_8 -> V_38 , 1 ) ;
V_117:
F_27 ( & V_67 -> V_42 ) ;
return V_115 ;
}
int F_92 ( struct V_7 * V_8 )
{
int V_115 = 0 ;
if ( V_8 -> V_76 != V_109 ) {
F_29 () ;
V_115 = F_88 ( V_8 , NULL , V_120 ) ;
F_30 () ;
}
return V_115 ;
}
void F_93 ( struct V_7 * V_8 )
{
struct V_36 * V_37 = V_8 -> V_38 -> V_39 . V_37 ;
T_8 * V_42 ;
bool V_121 = false ;
int V_122 ;
if ( F_67 ( V_8 ) )
return;
if ( V_8 -> V_76 == V_116 ) {
V_42 = & V_37 -> V_68 [ F_89 ( V_8 ) ] . V_42 ;
V_121 = true ;
} else {
V_42 = F_62 ( V_37 , V_8 -> V_87 ) ;
}
F_94 ( V_42 ) ;
if ( F_86 ( V_8 -> V_114 ) )
F_95 ( V_8 ) ;
if ( V_121 )
V_122 = F_96 ( V_8 ) ;
else
V_122 = F_97 ( V_8 ) ;
if ( V_122 )
F_71 ( F_9 ( V_8 ) , V_8 -> V_38 , - 1 ) ;
F_98 ( V_42 ) ;
}
int F_99 ( struct V_90 * V_91 ,
struct V_7 * V_8 , T_1 V_123 ,
int (* F_100)( struct V_90 * ,
struct V_7 * , T_3 , struct V_92 * * ) )
{
struct V_36 * V_94 = V_91 -> V_37 ;
struct V_92 * V_98 = NULL ;
struct V_21 * V_22 ;
int V_27 = F_20 ( V_8 ) -> V_34 ;
struct V_1 * V_1 = F_9 ( V_8 ) ;
struct V_18 * V_24 ;
T_1 V_124 , V_125 ;
int V_106 , V_126 , V_127 , V_128 ;
static T_1 V_129 ;
if ( V_27 ) {
V_22 = & V_94 -> V_40 [ F_24 ( V_1 , V_27 ,
V_94 -> V_41 ) ] ;
V_24 = F_22 ( V_8 ) -> V_35 ;
F_94 ( & V_22 -> V_42 ) ;
if ( F_101 ( & V_24 -> V_31 ) == V_8 && ! V_8 -> V_130 . V_131 ) {
F_77 ( V_8 , NULL ) ;
F_98 ( & V_22 -> V_42 ) ;
return 0 ;
}
F_27 ( & V_22 -> V_42 ) ;
V_106 = F_100 ( V_91 , V_8 , V_27 , NULL ) ;
F_30 () ;
return V_106 ;
}
F_102 ( V_1 , & V_127 , & V_128 ) ;
V_128 ++ ;
V_124 = V_128 - V_127 ;
if ( F_57 ( V_124 > 1 ) )
V_124 &= ~ 1U ;
V_125 = ( V_129 + V_123 ) % V_124 ;
V_125 &= ~ 1U ;
V_132:
V_27 = V_127 + V_125 ;
for ( V_126 = 0 ; V_126 < V_124 ; V_126 += 2 , V_27 += 2 ) {
if ( F_32 ( V_27 >= V_128 ) )
V_27 -= V_124 ;
if ( F_103 ( V_1 , V_27 ) )
continue;
V_22 = & V_94 -> V_40 [ F_24 ( V_1 , V_27 ,
V_94 -> V_41 ) ] ;
F_94 ( & V_22 -> V_42 ) ;
F_33 (tb, &head->chain) {
if ( F_34 ( V_26 ( V_24 ) , V_1 ) && V_24 -> V_27 == V_27 ) {
if ( V_24 -> V_28 >= 0 ||
V_24 -> V_29 >= 0 )
goto V_133;
F_66 ( F_16 ( & V_24 -> V_31 ) ) ;
if ( ! F_100 ( V_91 , V_8 ,
V_27 , & V_98 ) )
goto V_107;
goto V_133;
}
}
V_24 = F_10 ( V_94 -> V_43 ,
V_1 , V_22 , V_27 ) ;
if ( ! V_24 ) {
F_98 ( & V_22 -> V_42 ) ;
return - V_47 ;
}
V_24 -> V_28 = - 1 ;
V_24 -> V_29 = - 1 ;
goto V_107;
V_133:
F_98 ( & V_22 -> V_42 ) ;
F_104 () ;
}
V_125 ++ ;
if ( ( V_125 & 1 ) && V_124 > 1 )
goto V_132;
return - V_102 ;
V_107:
V_129 += V_126 + 2 ;
F_19 ( V_8 , V_24 , V_27 ) ;
if ( F_67 ( V_8 ) ) {
F_20 ( V_8 ) -> V_100 = F_65 ( V_27 ) ;
F_77 ( V_8 , (struct V_7 * ) V_98 ) ;
}
if ( V_98 )
F_105 ( V_98 , V_94 ) ;
F_27 ( & V_22 -> V_42 ) ;
if ( V_98 )
F_72 ( V_98 ) ;
F_30 () ;
return 0 ;
}
int F_106 ( struct V_90 * V_91 ,
struct V_7 * V_8 )
{
T_1 V_123 = 0 ;
if ( ! F_20 ( V_8 ) -> V_34 )
V_123 = F_73 ( V_8 ) ;
return F_99 ( V_91 , V_8 , V_123 ,
F_61 ) ;
}
void F_107 ( struct V_36 * V_39 )
{
int V_126 ;
for ( V_126 = 0 ; V_126 < V_134 ; V_126 ++ ) {
F_108 ( & V_39 -> V_68 [ V_126 ] . V_42 ) ;
F_13 ( & V_39 -> V_68 [ V_126 ] . V_22 ) ;
}
}
int F_109 ( struct V_36 * V_37 )
{
unsigned int V_135 = sizeof( T_8 ) ;
unsigned int V_126 , V_136 = 1 ;
if ( V_135 != 0 ) {
V_136 = F_110 ( 2U * V_137 / V_135 , 1U ) ;
V_136 = F_111 ( V_136 * F_112 () ) ;
V_136 = F_113 ( V_136 , V_37 -> V_83 + 1 ) ;
V_37 -> V_138 = F_114 ( V_136 , V_135 ,
V_139 | V_140 ) ;
if ( ! V_37 -> V_138 )
V_37 -> V_138 = F_115 ( V_136 * V_135 ) ;
if ( ! V_37 -> V_138 )
return - V_47 ;
for ( V_126 = 0 ; V_126 < V_136 ; V_126 ++ )
F_108 ( & V_37 -> V_138 [ V_126 ] ) ;
}
V_37 -> V_141 = V_136 - 1 ;
return 0 ;
}
