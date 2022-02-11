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
const int V_50 )
{
int V_51 = - 1 ;
struct V_52 * V_53 = F_20 ( V_8 ) ;
if ( F_34 ( F_9 ( V_8 ) , V_1 ) && V_53 -> V_34 == V_48 &&
! F_36 ( V_8 ) ) {
T_2 V_54 = V_53 -> V_55 ;
V_51 = V_8 -> V_10 == V_56 ? 2 : 1 ;
if ( V_54 ) {
if ( V_54 != V_49 )
return - 1 ;
V_51 += 4 ;
}
if ( V_8 -> V_57 ) {
if ( V_8 -> V_57 != V_50 )
return - 1 ;
V_51 += 4 ;
}
if ( V_8 -> V_58 == F_37 () )
V_51 ++ ;
}
return V_51 ;
}
struct V_7 * F_38 ( struct V_1 * V_1 ,
struct V_36 * V_37 ,
struct V_59 * V_60 , int V_61 ,
const T_2 V_62 , T_4 V_63 ,
const T_2 V_49 , const unsigned short V_48 ,
const int V_50 )
{
unsigned int V_64 = F_39 ( V_1 , V_48 ) ;
struct V_65 * V_66 = & V_37 -> V_67 [ V_64 ] ;
int V_51 , V_68 = 0 , V_69 = 0 , V_70 = 0 ;
struct V_7 * V_8 , * V_71 = NULL ;
T_1 V_72 = 0 ;
F_40 (sk, &ilb->head) {
V_51 = F_35 ( V_8 , V_1 , V_48 , V_49 , V_50 ) ;
if ( V_51 > V_68 ) {
V_70 = V_8 -> V_73 ;
if ( V_70 ) {
V_72 = F_1 ( V_1 , V_49 , V_48 ,
V_62 , V_63 ) ;
V_71 = F_41 ( V_8 , V_72 ,
V_60 , V_61 ) ;
if ( V_71 )
return V_71 ;
V_69 = 1 ;
}
V_71 = V_8 ;
V_68 = V_51 ;
} else if ( V_51 == V_68 && V_70 ) {
V_69 ++ ;
if ( F_42 ( V_72 , V_69 ) == 0 )
V_71 = V_8 ;
V_72 = F_43 ( V_72 ) ;
}
}
return V_71 ;
}
void F_44 ( struct V_7 * V_8 )
{
if ( ! F_45 ( & V_8 -> V_74 ) )
return;
if ( V_8 -> V_75 == V_76 )
F_46 ( F_47 ( V_8 ) ) ;
else if ( V_8 -> V_75 == V_77 )
F_48 ( F_49 ( V_8 ) ) ;
else
F_50 ( V_8 ) ;
}
void F_51 ( struct V_59 * V_60 )
{
F_44 ( V_60 -> V_8 ) ;
}
struct V_7 * F_52 ( struct V_1 * V_1 ,
struct V_36 * V_37 ,
const T_2 V_62 , const T_4 V_63 ,
const T_2 V_49 , const T_6 V_48 ,
const int V_50 )
{
F_53 ( V_78 , V_62 , V_49 ) ;
const T_7 V_79 = F_54 ( V_63 , V_48 ) ;
struct V_7 * V_8 ;
const struct V_80 * V_32 ;
unsigned int V_64 = F_1 ( V_1 , V_49 , V_48 , V_62 , V_63 ) ;
unsigned int V_81 = V_64 & V_37 -> V_82 ;
struct V_83 * V_22 = & V_37 -> V_84 [ V_81 ] ;
V_85:
F_55 (sk, node, &head->chain) {
if ( V_8 -> V_86 != V_64 )
continue;
if ( F_56 ( F_57 ( V_8 , V_1 , V_78 ,
V_62 , V_49 , V_79 , V_50 ) ) ) {
if ( F_32 ( ! F_58 ( & V_8 -> V_74 ) ) )
goto V_87;
if ( F_32 ( ! F_57 ( V_8 , V_1 , V_78 ,
V_62 , V_49 , V_79 , V_50 ) ) ) {
F_44 ( V_8 ) ;
goto V_85;
}
goto V_88;
}
}
if ( F_59 ( V_32 ) != V_81 )
goto V_85;
V_87:
V_8 = NULL ;
V_88:
return V_8 ;
}
static int F_60 ( struct V_89 * V_90 ,
struct V_7 * V_8 , T_3 V_3 ,
struct V_91 * * V_92 )
{
struct V_36 * V_93 = V_90 -> V_37 ;
struct V_52 * V_53 = F_20 ( V_8 ) ;
T_2 V_49 = V_53 -> V_55 ;
T_2 V_62 = V_53 -> V_94 ;
int V_50 = V_8 -> V_57 ;
F_53 ( V_78 , V_62 , V_49 ) ;
const T_7 V_79 = F_54 ( V_53 -> V_95 , V_3 ) ;
struct V_1 * V_1 = F_9 ( V_8 ) ;
unsigned int V_64 = F_1 ( V_1 , V_49 , V_3 ,
V_62 , V_53 -> V_95 ) ;
struct V_83 * V_22 = V_83 ( V_93 , V_64 ) ;
T_8 * V_42 = F_61 ( V_93 , V_64 ) ;
struct V_7 * V_96 ;
const struct V_80 * V_32 ;
struct V_91 * V_97 = NULL ;
F_25 ( V_42 ) ;
F_62 (sk2, node, &head->chain) {
if ( V_96 -> V_86 != V_64 )
continue;
if ( F_56 ( F_57 ( V_96 , V_1 , V_78 ,
V_62 , V_49 , V_79 , V_50 ) ) ) {
if ( V_96 -> V_75 == V_76 ) {
V_97 = F_47 ( V_96 ) ;
if ( F_63 ( V_8 , V_96 , V_92 ) )
break;
}
goto V_98;
}
}
V_53 -> V_34 = V_3 ;
V_53 -> V_99 = F_64 ( V_3 ) ;
V_8 -> V_86 = V_64 ;
F_65 ( ! F_66 ( V_8 ) ) ;
F_67 ( V_8 , & V_22 -> V_33 ) ;
if ( V_97 ) {
F_68 ( (struct V_7 * ) V_97 ) ;
F_69 ( V_1 , V_100 ) ;
}
F_27 ( V_42 ) ;
F_70 ( F_9 ( V_8 ) , V_8 -> V_38 , 1 ) ;
if ( V_92 ) {
* V_92 = V_97 ;
} else if ( V_97 ) {
F_71 ( V_97 ) ;
}
return 0 ;
V_98:
F_27 ( V_42 ) ;
return - V_101 ;
}
static T_1 F_72 ( const struct V_7 * V_8 )
{
const struct V_52 * V_53 = F_20 ( V_8 ) ;
return F_73 ( V_53 -> V_55 ,
V_53 -> V_94 ,
V_53 -> V_95 ) ;
}
bool F_74 ( struct V_7 * V_8 , struct V_7 * V_102 )
{
struct V_36 * V_37 = V_8 -> V_38 -> V_39 . V_37 ;
struct V_103 * V_104 ;
struct V_83 * V_22 ;
T_8 * V_42 ;
bool V_105 = true ;
F_75 ( ! F_66 ( V_8 ) ) ;
V_8 -> V_86 = F_5 ( V_8 ) ;
V_22 = V_83 ( V_37 , V_8 -> V_86 ) ;
V_104 = & V_22 -> V_33 ;
V_42 = F_61 ( V_37 , V_8 -> V_86 ) ;
F_25 ( V_42 ) ;
if ( V_102 ) {
F_75 ( V_8 -> V_86 != V_102 -> V_86 ) ;
V_105 = F_68 ( V_102 ) ;
}
if ( V_105 )
F_67 ( V_8 , V_104 ) ;
F_27 ( V_42 ) ;
return V_105 ;
}
bool F_76 ( struct V_7 * V_8 , struct V_7 * V_102 )
{
bool V_106 = F_74 ( V_8 , V_102 ) ;
if ( V_106 ) {
F_70 ( F_9 ( V_8 ) , V_8 -> V_38 , 1 ) ;
} else {
F_77 ( V_8 -> V_38 -> V_107 ) ;
V_8 -> V_75 = V_108 ;
F_78 ( V_8 , V_109 ) ;
F_79 ( V_8 ) ;
}
return V_106 ;
}
static int F_80 ( struct V_7 * V_8 ,
struct V_65 * V_66 ,
int (* F_81)( const struct V_7 * V_110 ,
const struct V_7 * V_96 ,
bool V_111 ) )
{
struct V_18 * V_24 = F_22 ( V_8 ) -> V_35 ;
struct V_7 * V_96 ;
T_9 V_112 = F_82 ( V_8 ) ;
F_40 (sk2, &ilb->head) {
if ( V_96 != V_8 &&
V_96 -> V_10 == V_8 -> V_10 &&
F_36 ( V_96 ) == F_36 ( V_8 ) &&
V_96 -> V_57 == V_8 -> V_57 &&
F_22 ( V_96 ) -> V_35 == V_24 &&
V_96 -> V_73 && F_83 ( V_112 , F_82 ( V_96 ) ) &&
F_81 ( V_8 , V_96 , false ) )
return F_84 ( V_8 , V_96 ) ;
}
if ( ! F_85 ( V_8 -> V_113 ) )
return F_86 ( V_8 ) ;
return 0 ;
}
int F_87 ( struct V_7 * V_8 , struct V_7 * V_102 ,
int (* F_81)( const struct V_7 * V_110 ,
const struct V_7 * V_96 ,
bool V_111 ) )
{
struct V_36 * V_37 = V_8 -> V_38 -> V_39 . V_37 ;
struct V_65 * V_66 ;
int V_114 = 0 ;
if ( V_8 -> V_75 != V_115 ) {
F_76 ( V_8 , V_102 ) ;
return 0 ;
}
F_65 ( ! F_66 ( V_8 ) ) ;
V_66 = & V_37 -> V_67 [ F_88 ( V_8 ) ] ;
F_25 ( & V_66 -> V_42 ) ;
if ( V_8 -> V_73 ) {
V_114 = F_80 ( V_8 , V_66 , F_81 ) ;
if ( V_114 )
goto V_116;
}
if ( F_6 ( V_9 ) && V_8 -> V_73 &&
V_8 -> V_10 == V_11 )
F_89 ( & V_8 -> V_117 , & V_66 -> V_22 ) ;
else
F_90 ( & V_8 -> V_117 , & V_66 -> V_22 ) ;
F_78 ( V_8 , V_118 ) ;
F_70 ( F_9 ( V_8 ) , V_8 -> V_38 , 1 ) ;
V_116:
F_27 ( & V_66 -> V_42 ) ;
return V_114 ;
}
int F_91 ( struct V_7 * V_8 )
{
int V_114 = 0 ;
if ( V_8 -> V_75 != V_108 ) {
F_29 () ;
V_114 = F_87 ( V_8 , NULL , V_119 ) ;
F_30 () ;
}
return V_114 ;
}
void F_92 ( struct V_7 * V_8 )
{
struct V_36 * V_37 = V_8 -> V_38 -> V_39 . V_37 ;
T_8 * V_42 ;
bool V_120 = false ;
int V_121 ;
if ( F_66 ( V_8 ) )
return;
if ( V_8 -> V_75 == V_115 ) {
V_42 = & V_37 -> V_67 [ F_88 ( V_8 ) ] . V_42 ;
V_120 = true ;
} else {
V_42 = F_61 ( V_37 , V_8 -> V_86 ) ;
}
F_93 ( V_42 ) ;
if ( F_85 ( V_8 -> V_113 ) )
F_94 ( V_8 ) ;
if ( V_120 )
V_121 = F_95 ( V_8 ) ;
else
V_121 = F_96 ( V_8 ) ;
if ( V_121 )
F_70 ( F_9 ( V_8 ) , V_8 -> V_38 , - 1 ) ;
F_97 ( V_42 ) ;
}
int F_98 ( struct V_89 * V_90 ,
struct V_7 * V_8 , T_1 V_122 ,
int (* F_99)( struct V_89 * ,
struct V_7 * , T_3 , struct V_91 * * ) )
{
struct V_36 * V_93 = V_90 -> V_37 ;
struct V_91 * V_97 = NULL ;
struct V_21 * V_22 ;
int V_27 = F_20 ( V_8 ) -> V_34 ;
struct V_1 * V_1 = F_9 ( V_8 ) ;
struct V_18 * V_24 ;
T_1 V_123 , V_124 ;
int V_105 , V_125 , V_126 , V_127 ;
static T_1 V_128 ;
if ( V_27 ) {
V_22 = & V_93 -> V_40 [ F_24 ( V_1 , V_27 ,
V_93 -> V_41 ) ] ;
V_24 = F_22 ( V_8 ) -> V_35 ;
F_93 ( & V_22 -> V_42 ) ;
if ( F_100 ( & V_24 -> V_31 ) == V_8 && ! V_8 -> V_129 . V_130 ) {
F_76 ( V_8 , NULL ) ;
F_97 ( & V_22 -> V_42 ) ;
return 0 ;
}
F_27 ( & V_22 -> V_42 ) ;
V_105 = F_99 ( V_90 , V_8 , V_27 , NULL ) ;
F_30 () ;
return V_105 ;
}
F_101 ( V_1 , & V_126 , & V_127 ) ;
V_127 ++ ;
V_123 = V_127 - V_126 ;
if ( F_56 ( V_123 > 1 ) )
V_123 &= ~ 1U ;
V_124 = ( V_128 + V_122 ) % V_123 ;
V_124 &= ~ 1U ;
V_131:
V_27 = V_126 + V_124 ;
for ( V_125 = 0 ; V_125 < V_123 ; V_125 += 2 , V_27 += 2 ) {
if ( F_32 ( V_27 >= V_127 ) )
V_27 -= V_123 ;
if ( F_102 ( V_1 , V_27 ) )
continue;
V_22 = & V_93 -> V_40 [ F_24 ( V_1 , V_27 ,
V_93 -> V_41 ) ] ;
F_93 ( & V_22 -> V_42 ) ;
F_33 (tb, &head->chain) {
if ( F_34 ( V_26 ( V_24 ) , V_1 ) && V_24 -> V_27 == V_27 ) {
if ( V_24 -> V_28 >= 0 ||
V_24 -> V_29 >= 0 )
goto V_132;
F_65 ( F_16 ( & V_24 -> V_31 ) ) ;
if ( ! F_99 ( V_90 , V_8 ,
V_27 , & V_97 ) )
goto V_106;
goto V_132;
}
}
V_24 = F_10 ( V_93 -> V_43 ,
V_1 , V_22 , V_27 ) ;
if ( ! V_24 ) {
F_97 ( & V_22 -> V_42 ) ;
return - V_47 ;
}
V_24 -> V_28 = - 1 ;
V_24 -> V_29 = - 1 ;
goto V_106;
V_132:
F_97 ( & V_22 -> V_42 ) ;
F_103 () ;
}
V_124 ++ ;
if ( ( V_124 & 1 ) && V_123 > 1 )
goto V_131;
return - V_101 ;
V_106:
V_128 += V_125 + 2 ;
F_19 ( V_8 , V_24 , V_27 ) ;
if ( F_66 ( V_8 ) ) {
F_20 ( V_8 ) -> V_99 = F_64 ( V_27 ) ;
F_76 ( V_8 , (struct V_7 * ) V_97 ) ;
}
if ( V_97 )
F_104 ( V_97 , V_93 ) ;
F_27 ( & V_22 -> V_42 ) ;
if ( V_97 )
F_71 ( V_97 ) ;
F_30 () ;
return 0 ;
}
int F_105 ( struct V_89 * V_90 ,
struct V_7 * V_8 )
{
T_1 V_122 = 0 ;
if ( ! F_20 ( V_8 ) -> V_34 )
V_122 = F_72 ( V_8 ) ;
return F_98 ( V_90 , V_8 , V_122 ,
F_60 ) ;
}
void F_106 ( struct V_36 * V_39 )
{
int V_125 ;
for ( V_125 = 0 ; V_125 < V_133 ; V_125 ++ ) {
F_107 ( & V_39 -> V_67 [ V_125 ] . V_42 ) ;
F_13 ( & V_39 -> V_67 [ V_125 ] . V_22 ) ;
}
}
int F_108 ( struct V_36 * V_37 )
{
unsigned int V_134 = sizeof( T_8 ) ;
unsigned int V_125 , V_135 = 1 ;
if ( V_134 != 0 ) {
V_135 = F_109 ( 2U * V_136 / V_134 , 1U ) ;
V_135 = F_110 ( V_135 * F_111 () ) ;
V_135 = F_112 ( V_135 , V_37 -> V_82 + 1 ) ;
V_37 -> V_137 = F_113 ( V_135 , V_134 ,
V_138 | V_139 ) ;
if ( ! V_37 -> V_137 )
V_37 -> V_137 = F_114 ( V_135 * V_134 ) ;
if ( ! V_37 -> V_137 )
return - V_47 ;
for ( V_125 = 0 ; V_125 < V_135 ; V_125 ++ )
F_107 ( & V_37 -> V_137 [ V_125 ] ) ;
}
V_37 -> V_140 = V_135 - 1 ;
return 0 ;
}
