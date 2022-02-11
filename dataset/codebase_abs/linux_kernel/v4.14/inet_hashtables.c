static T_1 F_1 ( const struct V_1 * V_1 , const T_2 V_2 ,
const T_3 V_3 , const T_2 V_4 ,
const T_4 V_5 )
{
static T_1 T_5 V_6 ;
F_2 ( & T_5 , sizeof( T_5 ) ) ;
return F_3 ( V_2 , V_3 , V_4 , V_5 ,
T_5 + F_4 ( V_1 ) ) ;
}
static T_1 F_5 ( const struct V_7 * V_8 )
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
F_13 ( & V_24 -> V_30 ) ;
F_14 ( & V_24 -> V_31 , & V_22 -> V_32 ) ;
}
return V_24 ;
}
void F_15 ( struct V_19 * V_20 , struct V_18 * V_24 )
{
if ( F_16 ( & V_24 -> V_30 ) ) {
F_17 ( & V_24 -> V_31 ) ;
F_18 ( V_20 , V_24 ) ;
}
}
void F_19 ( struct V_7 * V_8 , struct V_18 * V_24 ,
const unsigned short V_23 )
{
F_20 ( V_8 ) -> V_33 = V_23 ;
F_21 ( V_8 , & V_24 -> V_30 ) ;
F_22 ( V_8 ) -> V_34 = V_24 ;
}
static void F_23 ( struct V_7 * V_8 )
{
struct V_35 * V_36 = V_8 -> V_37 -> V_38 . V_36 ;
const int V_39 = F_24 ( F_9 ( V_8 ) , F_20 ( V_8 ) -> V_33 ,
V_36 -> V_40 ) ;
struct V_21 * V_22 = & V_36 -> V_39 [ V_39 ] ;
struct V_18 * V_24 ;
F_25 ( & V_22 -> V_41 ) ;
V_24 = F_22 ( V_8 ) -> V_34 ;
F_26 ( V_8 ) ;
F_22 ( V_8 ) -> V_34 = NULL ;
F_20 ( V_8 ) -> V_33 = 0 ;
F_15 ( V_36 -> V_42 , V_24 ) ;
F_27 ( & V_22 -> V_41 ) ;
}
void F_28 ( struct V_7 * V_8 )
{
F_29 () ;
F_23 ( V_8 ) ;
F_30 () ;
}
int F_31 ( const struct V_7 * V_8 , struct V_7 * V_43 )
{
struct V_35 * V_44 = V_8 -> V_37 -> V_38 . V_36 ;
unsigned short V_27 = F_20 ( V_43 ) -> V_33 ;
const int V_39 = F_24 ( F_9 ( V_8 ) , V_27 ,
V_44 -> V_40 ) ;
struct V_21 * V_22 = & V_44 -> V_39 [ V_39 ] ;
struct V_18 * V_24 ;
F_25 ( & V_22 -> V_41 ) ;
V_24 = F_22 ( V_8 ) -> V_34 ;
if ( F_32 ( ! V_24 ) ) {
F_27 ( & V_22 -> V_41 ) ;
return - V_45 ;
}
if ( V_24 -> V_27 != V_27 ) {
F_33 (tb, &head->chain) {
if ( F_34 ( V_26 ( V_24 ) , F_9 ( V_8 ) ) &&
V_24 -> V_27 == V_27 )
break;
}
if ( ! V_24 ) {
V_24 = F_10 ( V_44 -> V_42 ,
F_9 ( V_8 ) , V_22 , V_27 ) ;
if ( ! V_24 ) {
F_27 ( & V_22 -> V_41 ) ;
return - V_46 ;
}
}
}
F_19 ( V_43 , V_24 , V_27 ) ;
F_27 ( & V_22 -> V_41 ) ;
return 0 ;
}
static inline int F_35 ( struct V_7 * V_8 , struct V_1 * V_1 ,
const unsigned short V_47 , const T_2 V_48 ,
const int V_49 , const int V_50 , bool V_51 )
{
int V_52 = - 1 ;
struct V_53 * V_54 = F_20 ( V_8 ) ;
if ( F_34 ( F_9 ( V_8 ) , V_1 ) && V_54 -> V_33 == V_47 &&
! F_36 ( V_8 ) ) {
T_2 V_55 = V_54 -> V_56 ;
V_52 = V_8 -> V_10 == V_57 ? 2 : 1 ;
if ( V_55 ) {
if ( V_55 != V_48 )
return - 1 ;
V_52 += 4 ;
}
if ( V_8 -> V_58 || V_51 ) {
bool V_59 = ( V_8 -> V_58 == V_49 ||
V_8 -> V_58 == V_50 ) ;
if ( V_51 && ! V_59 )
return - 1 ;
if ( V_8 -> V_58 && V_59 )
V_52 += 4 ;
}
if ( V_8 -> V_60 == F_37 () )
V_52 ++ ;
}
return V_52 ;
}
struct V_7 * F_38 ( struct V_1 * V_1 ,
struct V_35 * V_36 ,
struct V_61 * V_62 , int V_63 ,
const T_2 V_64 , T_4 V_65 ,
const T_2 V_48 , const unsigned short V_47 ,
const int V_49 , const int V_50 )
{
unsigned int V_66 = F_39 ( V_1 , V_47 ) ;
struct V_67 * V_68 = & V_36 -> V_69 [ V_66 ] ;
int V_52 , V_70 = 0 , V_71 = 0 , V_72 = 0 ;
bool V_51 = F_40 ( V_1 , V_62 ) ;
struct V_7 * V_8 , * V_73 = NULL ;
T_1 V_74 = 0 ;
F_41 (sk, &ilb->head) {
V_52 = F_35 ( V_8 , V_1 , V_47 , V_48 ,
V_49 , V_50 , V_51 ) ;
if ( V_52 > V_70 ) {
V_72 = V_8 -> V_75 ;
if ( V_72 ) {
V_74 = F_1 ( V_1 , V_48 , V_47 ,
V_64 , V_65 ) ;
V_73 = F_42 ( V_8 , V_74 ,
V_62 , V_63 ) ;
if ( V_73 )
return V_73 ;
V_71 = 1 ;
}
V_73 = V_8 ;
V_70 = V_52 ;
} else if ( V_52 == V_70 && V_72 ) {
V_71 ++ ;
if ( F_43 ( V_74 , V_71 ) == 0 )
V_73 = V_8 ;
V_74 = F_44 ( V_74 ) ;
}
}
return V_73 ;
}
void F_45 ( struct V_7 * V_8 )
{
if ( ! F_46 ( & V_8 -> V_76 ) )
return;
if ( V_8 -> V_77 == V_78 )
F_47 ( F_48 ( V_8 ) ) ;
else if ( V_8 -> V_77 == V_79 )
F_49 ( F_50 ( V_8 ) ) ;
else
F_51 ( V_8 ) ;
}
void F_52 ( struct V_61 * V_62 )
{
F_45 ( V_62 -> V_8 ) ;
}
struct V_7 * F_53 ( struct V_1 * V_1 ,
struct V_35 * V_36 ,
const T_2 V_64 , const T_4 V_65 ,
const T_2 V_48 , const T_6 V_47 ,
const int V_49 , const int V_50 )
{
F_54 ( V_80 , V_64 , V_48 ) ;
const T_7 V_81 = F_55 ( V_65 , V_47 ) ;
struct V_7 * V_8 ;
const struct V_82 * V_31 ;
unsigned int V_66 = F_1 ( V_1 , V_48 , V_47 , V_64 , V_65 ) ;
unsigned int V_83 = V_66 & V_36 -> V_84 ;
struct V_85 * V_22 = & V_36 -> V_86 [ V_83 ] ;
V_87:
F_56 (sk, node, &head->chain) {
if ( V_8 -> V_88 != V_66 )
continue;
if ( F_57 ( F_58 ( V_8 , V_1 , V_80 ,
V_64 , V_48 , V_81 , V_49 , V_50 ) ) ) {
if ( F_32 ( ! F_59 ( & V_8 -> V_76 ) ) )
goto V_89;
if ( F_32 ( ! F_58 ( V_8 , V_1 , V_80 ,
V_64 , V_48 , V_81 ,
V_49 , V_50 ) ) ) {
F_45 ( V_8 ) ;
goto V_87;
}
goto V_90;
}
}
if ( F_60 ( V_31 ) != V_83 )
goto V_87;
V_89:
V_8 = NULL ;
V_90:
return V_8 ;
}
static int F_61 ( struct V_91 * V_92 ,
struct V_7 * V_8 , T_3 V_3 ,
struct V_93 * * V_94 )
{
struct V_35 * V_95 = V_92 -> V_36 ;
struct V_53 * V_54 = F_20 ( V_8 ) ;
T_2 V_48 = V_54 -> V_56 ;
T_2 V_64 = V_54 -> V_96 ;
int V_49 = V_8 -> V_58 ;
struct V_1 * V_1 = F_9 ( V_8 ) ;
int V_50 = F_62 ( V_1 , V_49 ) ;
F_54 ( V_80 , V_64 , V_48 ) ;
const T_7 V_81 = F_55 ( V_54 -> V_97 , V_3 ) ;
unsigned int V_66 = F_1 ( V_1 , V_48 , V_3 ,
V_64 , V_54 -> V_97 ) ;
struct V_85 * V_22 = V_85 ( V_95 , V_66 ) ;
T_8 * V_41 = F_63 ( V_95 , V_66 ) ;
struct V_7 * V_98 ;
const struct V_82 * V_31 ;
struct V_93 * V_99 = NULL ;
F_25 ( V_41 ) ;
F_64 (sk2, node, &head->chain) {
if ( V_98 -> V_88 != V_66 )
continue;
if ( F_57 ( F_58 ( V_98 , V_1 , V_80 ,
V_64 , V_48 , V_81 , V_49 , V_50 ) ) ) {
if ( V_98 -> V_77 == V_78 ) {
V_99 = F_48 ( V_98 ) ;
if ( F_65 ( V_8 , V_98 , V_94 ) )
break;
}
goto V_100;
}
}
V_54 -> V_33 = V_3 ;
V_54 -> V_101 = F_66 ( V_3 ) ;
V_8 -> V_88 = V_66 ;
F_67 ( ! F_68 ( V_8 ) ) ;
F_69 ( V_8 , & V_22 -> V_32 ) ;
if ( V_99 ) {
F_70 ( (struct V_7 * ) V_99 ) ;
F_71 ( V_1 , V_102 ) ;
}
F_27 ( V_41 ) ;
F_72 ( F_9 ( V_8 ) , V_8 -> V_37 , 1 ) ;
if ( V_94 ) {
* V_94 = V_99 ;
} else if ( V_99 ) {
F_73 ( V_99 ) ;
}
return 0 ;
V_100:
F_27 ( V_41 ) ;
return - V_103 ;
}
static T_1 F_74 ( const struct V_7 * V_8 )
{
const struct V_53 * V_54 = F_20 ( V_8 ) ;
return F_75 ( V_54 -> V_56 ,
V_54 -> V_96 ,
V_54 -> V_97 ) ;
}
bool F_76 ( struct V_7 * V_8 , struct V_7 * V_104 )
{
struct V_35 * V_36 = V_8 -> V_37 -> V_38 . V_36 ;
struct V_105 * V_106 ;
struct V_85 * V_22 ;
T_8 * V_41 ;
bool V_107 = true ;
F_77 ( ! F_68 ( V_8 ) ) ;
V_8 -> V_88 = F_5 ( V_8 ) ;
V_22 = V_85 ( V_36 , V_8 -> V_88 ) ;
V_106 = & V_22 -> V_32 ;
V_41 = F_63 ( V_36 , V_8 -> V_88 ) ;
F_25 ( V_41 ) ;
if ( V_104 ) {
F_77 ( V_8 -> V_88 != V_104 -> V_88 ) ;
V_107 = F_70 ( V_104 ) ;
}
if ( V_107 )
F_69 ( V_8 , V_106 ) ;
F_27 ( V_41 ) ;
return V_107 ;
}
bool F_78 ( struct V_7 * V_8 , struct V_7 * V_104 )
{
bool V_108 = F_76 ( V_8 , V_104 ) ;
if ( V_108 ) {
F_72 ( F_9 ( V_8 ) , V_8 -> V_37 , 1 ) ;
} else {
F_79 ( V_8 -> V_37 -> V_109 ) ;
V_8 -> V_77 = V_110 ;
F_80 ( V_8 , V_111 ) ;
F_81 ( V_8 ) ;
}
return V_108 ;
}
static int F_82 ( struct V_7 * V_8 ,
struct V_67 * V_68 )
{
struct V_18 * V_24 = F_22 ( V_8 ) -> V_34 ;
struct V_7 * V_98 ;
T_9 V_112 = F_83 ( V_8 ) ;
F_41 (sk2, &ilb->head) {
if ( V_98 != V_8 &&
V_98 -> V_10 == V_8 -> V_10 &&
F_36 ( V_98 ) == F_36 ( V_8 ) &&
V_98 -> V_58 == V_8 -> V_58 &&
F_22 ( V_98 ) -> V_34 == V_24 &&
V_98 -> V_75 && F_84 ( V_112 , F_83 ( V_98 ) ) &&
F_85 ( V_8 , V_98 , false ) )
return F_86 ( V_8 , V_98 ) ;
}
return F_87 ( V_8 ) ;
}
int F_88 ( struct V_7 * V_8 , struct V_7 * V_104 )
{
struct V_35 * V_36 = V_8 -> V_37 -> V_38 . V_36 ;
struct V_67 * V_68 ;
int V_113 = 0 ;
if ( V_8 -> V_77 != V_114 ) {
F_78 ( V_8 , V_104 ) ;
return 0 ;
}
F_67 ( ! F_68 ( V_8 ) ) ;
V_68 = & V_36 -> V_69 [ F_89 ( V_8 ) ] ;
F_25 ( & V_68 -> V_41 ) ;
if ( V_8 -> V_75 ) {
V_113 = F_82 ( V_8 , V_68 ) ;
if ( V_113 )
goto V_115;
}
if ( F_6 ( V_9 ) && V_8 -> V_75 &&
V_8 -> V_10 == V_11 )
F_90 ( & V_8 -> V_116 , & V_68 -> V_22 ) ;
else
F_91 ( & V_8 -> V_116 , & V_68 -> V_22 ) ;
F_80 ( V_8 , V_117 ) ;
F_72 ( F_9 ( V_8 ) , V_8 -> V_37 , 1 ) ;
V_115:
F_27 ( & V_68 -> V_41 ) ;
return V_113 ;
}
int F_92 ( struct V_7 * V_8 )
{
int V_113 = 0 ;
if ( V_8 -> V_77 != V_110 ) {
F_29 () ;
V_113 = F_88 ( V_8 , NULL ) ;
F_30 () ;
}
return V_113 ;
}
void F_93 ( struct V_7 * V_8 )
{
struct V_35 * V_36 = V_8 -> V_37 -> V_38 . V_36 ;
T_8 * V_41 ;
bool V_118 = false ;
int V_119 ;
if ( F_68 ( V_8 ) )
return;
if ( V_8 -> V_77 == V_114 ) {
V_41 = & V_36 -> V_69 [ F_89 ( V_8 ) ] . V_41 ;
V_118 = true ;
} else {
V_41 = F_63 ( V_36 , V_8 -> V_88 ) ;
}
F_94 ( V_41 ) ;
if ( F_95 ( V_8 -> V_120 ) )
F_96 ( V_8 ) ;
if ( V_118 )
V_119 = F_97 ( V_8 ) ;
else
V_119 = F_98 ( V_8 ) ;
if ( V_119 )
F_72 ( F_9 ( V_8 ) , V_8 -> V_37 , - 1 ) ;
F_99 ( V_41 ) ;
}
int F_100 ( struct V_91 * V_92 ,
struct V_7 * V_8 , T_1 V_121 ,
int (* F_101)( struct V_91 * ,
struct V_7 * , T_3 , struct V_93 * * ) )
{
struct V_35 * V_95 = V_92 -> V_36 ;
struct V_93 * V_99 = NULL ;
struct V_21 * V_22 ;
int V_27 = F_20 ( V_8 ) -> V_33 ;
struct V_1 * V_1 = F_9 ( V_8 ) ;
struct V_18 * V_24 ;
T_1 V_122 , V_123 ;
int V_107 , V_124 , V_125 , V_126 ;
static T_1 V_127 ;
if ( V_27 ) {
V_22 = & V_95 -> V_39 [ F_24 ( V_1 , V_27 ,
V_95 -> V_40 ) ] ;
V_24 = F_22 ( V_8 ) -> V_34 ;
F_94 ( & V_22 -> V_41 ) ;
if ( F_102 ( & V_24 -> V_30 ) == V_8 && ! V_8 -> V_128 . V_129 ) {
F_78 ( V_8 , NULL ) ;
F_99 ( & V_22 -> V_41 ) ;
return 0 ;
}
F_27 ( & V_22 -> V_41 ) ;
V_107 = F_101 ( V_92 , V_8 , V_27 , NULL ) ;
F_30 () ;
return V_107 ;
}
F_103 ( V_1 , & V_125 , & V_126 ) ;
V_126 ++ ;
V_122 = V_126 - V_125 ;
if ( F_57 ( V_122 > 1 ) )
V_122 &= ~ 1U ;
V_123 = ( V_127 + V_121 ) % V_122 ;
V_123 &= ~ 1U ;
V_130:
V_27 = V_125 + V_123 ;
for ( V_124 = 0 ; V_124 < V_122 ; V_124 += 2 , V_27 += 2 ) {
if ( F_32 ( V_27 >= V_126 ) )
V_27 -= V_122 ;
if ( F_104 ( V_1 , V_27 ) )
continue;
V_22 = & V_95 -> V_39 [ F_24 ( V_1 , V_27 ,
V_95 -> V_40 ) ] ;
F_94 ( & V_22 -> V_41 ) ;
F_33 (tb, &head->chain) {
if ( F_34 ( V_26 ( V_24 ) , V_1 ) && V_24 -> V_27 == V_27 ) {
if ( V_24 -> V_28 >= 0 ||
V_24 -> V_29 >= 0 )
goto V_131;
F_67 ( F_16 ( & V_24 -> V_30 ) ) ;
if ( ! F_101 ( V_92 , V_8 ,
V_27 , & V_99 ) )
goto V_108;
goto V_131;
}
}
V_24 = F_10 ( V_95 -> V_42 ,
V_1 , V_22 , V_27 ) ;
if ( ! V_24 ) {
F_99 ( & V_22 -> V_41 ) ;
return - V_46 ;
}
V_24 -> V_28 = - 1 ;
V_24 -> V_29 = - 1 ;
goto V_108;
V_131:
F_99 ( & V_22 -> V_41 ) ;
F_105 () ;
}
V_123 ++ ;
if ( ( V_123 & 1 ) && V_122 > 1 )
goto V_130;
return - V_103 ;
V_108:
V_127 += V_124 + 2 ;
F_19 ( V_8 , V_24 , V_27 ) ;
if ( F_68 ( V_8 ) ) {
F_20 ( V_8 ) -> V_101 = F_66 ( V_27 ) ;
F_78 ( V_8 , (struct V_7 * ) V_99 ) ;
}
if ( V_99 )
F_106 ( V_99 , V_95 ) ;
F_27 ( & V_22 -> V_41 ) ;
if ( V_99 )
F_73 ( V_99 ) ;
F_30 () ;
return 0 ;
}
int F_107 ( struct V_91 * V_92 ,
struct V_7 * V_8 )
{
T_1 V_121 = 0 ;
if ( ! F_20 ( V_8 ) -> V_33 )
V_121 = F_74 ( V_8 ) ;
return F_100 ( V_92 , V_8 , V_121 ,
F_61 ) ;
}
void F_108 ( struct V_35 * V_38 )
{
int V_124 ;
for ( V_124 = 0 ; V_124 < V_132 ; V_124 ++ ) {
F_109 ( & V_38 -> V_69 [ V_124 ] . V_41 ) ;
F_13 ( & V_38 -> V_69 [ V_124 ] . V_22 ) ;
}
}
int F_110 ( struct V_35 * V_36 )
{
unsigned int V_133 = sizeof( T_8 ) ;
unsigned int V_124 , V_134 = 1 ;
if ( V_133 != 0 ) {
V_134 = F_111 ( 2U * V_135 / V_133 , 1U ) ;
V_134 = F_112 ( V_134 * F_113 () ) ;
V_134 = F_114 ( V_134 , V_36 -> V_84 + 1 ) ;
V_36 -> V_136 = F_115 ( V_134 , V_133 , V_137 ) ;
if ( ! V_36 -> V_136 )
return - V_46 ;
for ( V_124 = 0 ; V_124 < V_134 ; V_124 ++ )
F_109 ( & V_36 -> V_136 [ V_124 ] ) ;
}
V_36 -> V_138 = V_134 - 1 ;
return 0 ;
}
