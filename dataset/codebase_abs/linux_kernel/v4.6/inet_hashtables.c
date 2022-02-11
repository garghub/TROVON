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
struct V_7 * V_8 , * V_64 ;
struct V_65 * V_32 ;
unsigned int V_66 = F_39 ( V_1 , V_48 ) ;
struct V_67 * V_68 = & V_37 -> V_69 [ V_66 ] ;
int V_51 , V_70 , V_71 = 0 , V_72 = 0 ;
bool V_73 = true ;
T_1 V_74 = 0 ;
F_40 () ;
V_75:
V_64 = NULL ;
V_70 = 0 ;
F_41 (sk, node, &ilb->head) {
V_51 = F_35 ( V_8 , V_1 , V_48 , V_49 , V_50 ) ;
if ( V_51 > V_70 ) {
V_64 = V_8 ;
V_70 = V_51 ;
V_72 = V_8 -> V_76 ;
if ( V_72 ) {
V_74 = F_1 ( V_1 , V_49 , V_48 ,
V_62 , V_63 ) ;
if ( V_73 ) {
struct V_7 * V_77 ;
V_77 = F_42 ( V_8 , V_74 ,
V_60 , V_61 ) ;
if ( V_77 ) {
V_64 = V_77 ;
goto V_78;
}
}
V_71 = 1 ;
}
} else if ( V_51 == V_70 && V_72 ) {
V_71 ++ ;
if ( F_43 ( V_74 , V_71 ) == 0 )
V_64 = V_8 ;
V_74 = F_44 ( V_74 ) ;
}
}
if ( F_45 ( V_32 ) != V_66 + V_79 )
goto V_75;
if ( V_64 ) {
V_78:
if ( F_32 ( ! F_46 ( & V_64 -> V_80 ) ) )
V_64 = NULL ;
else if ( F_32 ( F_35 ( V_64 , V_1 , V_48 , V_49 ,
V_50 ) < V_70 ) ) {
F_47 ( V_64 ) ;
V_73 = false ;
goto V_75;
}
}
F_48 () ;
return V_64 ;
}
void F_49 ( struct V_7 * V_8 )
{
if ( ! F_50 ( & V_8 -> V_80 ) )
return;
if ( V_8 -> V_81 == V_82 )
F_51 ( F_52 ( V_8 ) ) ;
else if ( V_8 -> V_81 == V_83 )
F_53 ( F_54 ( V_8 ) ) ;
else
F_55 ( V_8 ) ;
}
void F_56 ( struct V_59 * V_60 )
{
F_49 ( V_60 -> V_8 ) ;
}
struct V_7 * F_57 ( struct V_1 * V_1 ,
struct V_36 * V_37 ,
const T_2 V_62 , const T_4 V_63 ,
const T_2 V_49 , const T_6 V_48 ,
const int V_50 )
{
F_58 ( V_84 , V_62 , V_49 ) ;
const T_7 V_85 = F_59 ( V_63 , V_48 ) ;
struct V_7 * V_8 ;
const struct V_65 * V_32 ;
unsigned int V_66 = F_1 ( V_1 , V_49 , V_48 , V_62 , V_63 ) ;
unsigned int V_86 = V_66 & V_37 -> V_87 ;
struct V_88 * V_22 = & V_37 -> V_89 [ V_86 ] ;
F_40 () ;
V_75:
F_41 (sk, node, &head->chain) {
if ( V_8 -> V_90 != V_66 )
continue;
if ( F_60 ( F_61 ( V_8 , V_1 , V_84 ,
V_62 , V_49 , V_85 , V_50 ) ) ) {
if ( F_32 ( ! F_46 ( & V_8 -> V_80 ) ) )
goto V_91;
if ( F_32 ( ! F_61 ( V_8 , V_1 , V_84 ,
V_62 , V_49 , V_85 , V_50 ) ) ) {
F_49 ( V_8 ) ;
goto V_75;
}
goto V_78;
}
}
if ( F_45 ( V_32 ) != V_86 )
goto V_75;
V_91:
V_8 = NULL ;
V_78:
F_48 () ;
return V_8 ;
}
static int F_62 ( struct V_92 * V_93 ,
struct V_7 * V_8 , T_3 V_3 ,
struct V_94 * * V_95 )
{
struct V_36 * V_96 = V_93 -> V_37 ;
struct V_52 * V_53 = F_20 ( V_8 ) ;
T_2 V_49 = V_53 -> V_55 ;
T_2 V_62 = V_53 -> V_97 ;
int V_50 = V_8 -> V_57 ;
F_58 ( V_84 , V_62 , V_49 ) ;
const T_7 V_85 = F_59 ( V_53 -> V_98 , V_3 ) ;
struct V_1 * V_1 = F_9 ( V_8 ) ;
unsigned int V_66 = F_1 ( V_1 , V_49 , V_3 ,
V_62 , V_53 -> V_98 ) ;
struct V_88 * V_22 = V_88 ( V_96 , V_66 ) ;
T_8 * V_42 = F_63 ( V_96 , V_66 ) ;
struct V_7 * V_77 ;
const struct V_65 * V_32 ;
struct V_94 * V_99 = NULL ;
F_25 ( V_42 ) ;
F_64 (sk2, node, &head->chain) {
if ( V_77 -> V_90 != V_66 )
continue;
if ( F_60 ( F_61 ( V_77 , V_1 , V_84 ,
V_62 , V_49 , V_85 , V_50 ) ) ) {
if ( V_77 -> V_81 == V_82 ) {
V_99 = F_52 ( V_77 ) ;
if ( F_65 ( V_8 , V_77 , V_95 ) )
break;
}
goto V_100;
}
}
V_53 -> V_34 = V_3 ;
V_53 -> V_101 = F_66 ( V_3 ) ;
V_8 -> V_90 = V_66 ;
F_67 ( ! F_68 ( V_8 ) ) ;
F_69 ( V_8 , & V_22 -> V_33 ) ;
if ( V_99 ) {
F_70 ( (struct V_7 * ) V_99 ) ;
F_71 ( V_1 , V_102 ) ;
}
F_27 ( V_42 ) ;
F_72 ( F_9 ( V_8 ) , V_8 -> V_38 , 1 ) ;
if ( V_95 ) {
* V_95 = V_99 ;
} else if ( V_99 ) {
F_73 ( V_99 ) ;
}
return 0 ;
V_100:
F_27 ( V_42 ) ;
return - V_103 ;
}
static T_1 F_74 ( const struct V_7 * V_8 )
{
const struct V_52 * V_53 = F_20 ( V_8 ) ;
return F_75 ( V_53 -> V_55 ,
V_53 -> V_97 ,
V_53 -> V_98 ) ;
}
bool F_76 ( struct V_7 * V_8 , struct V_7 * V_104 )
{
struct V_36 * V_37 = V_8 -> V_38 -> V_39 . V_37 ;
struct V_105 * V_106 ;
struct V_88 * V_22 ;
T_8 * V_42 ;
bool V_107 = true ;
F_77 ( ! F_68 ( V_8 ) ) ;
V_8 -> V_90 = F_5 ( V_8 ) ;
V_22 = V_88 ( V_37 , V_8 -> V_90 ) ;
V_106 = & V_22 -> V_33 ;
V_42 = F_63 ( V_37 , V_8 -> V_90 ) ;
F_25 ( V_42 ) ;
if ( V_104 ) {
F_77 ( V_8 -> V_90 != V_104 -> V_90 ) ;
V_107 = F_70 ( V_104 ) ;
}
if ( V_107 )
F_69 ( V_8 , V_106 ) ;
F_27 ( V_42 ) ;
return V_107 ;
}
bool F_78 ( struct V_7 * V_8 , struct V_7 * V_104 )
{
bool V_108 = F_76 ( V_8 , V_104 ) ;
if ( V_108 ) {
F_72 ( F_9 ( V_8 ) , V_8 -> V_38 , 1 ) ;
} else {
F_79 ( V_8 -> V_38 -> V_109 ) ;
V_8 -> V_81 = V_110 ;
F_80 ( V_8 , V_111 ) ;
F_81 ( V_8 ) ;
}
return V_108 ;
}
static int F_82 ( struct V_7 * V_8 ,
struct V_67 * V_68 ,
int (* F_83)( const struct V_7 * V_112 ,
const struct V_7 * V_77 ,
bool V_113 ) )
{
struct V_18 * V_24 = F_22 ( V_8 ) -> V_35 ;
struct V_7 * V_77 ;
struct V_65 * V_32 ;
T_9 V_114 = F_84 ( V_8 ) ;
F_41 (sk2, node, &ilb->head) {
if ( V_77 != V_8 &&
V_77 -> V_10 == V_8 -> V_10 &&
F_36 ( V_77 ) == F_36 ( V_8 ) &&
V_77 -> V_57 == V_8 -> V_57 &&
F_22 ( V_77 ) -> V_35 == V_24 &&
V_77 -> V_76 && F_85 ( V_114 , F_84 ( V_77 ) ) &&
F_83 ( V_8 , V_77 , false ) )
return F_86 ( V_8 , V_77 ) ;
}
if ( ! F_87 ( V_8 -> V_115 ) )
return F_88 ( V_8 ) ;
return 0 ;
}
int F_89 ( struct V_7 * V_8 , struct V_7 * V_104 ,
int (* F_83)( const struct V_7 * V_112 ,
const struct V_7 * V_77 ,
bool V_113 ) )
{
struct V_36 * V_37 = V_8 -> V_38 -> V_39 . V_37 ;
struct V_67 * V_68 ;
int V_116 = 0 ;
if ( V_8 -> V_81 != V_117 ) {
F_78 ( V_8 , V_104 ) ;
return 0 ;
}
F_67 ( ! F_68 ( V_8 ) ) ;
V_68 = & V_37 -> V_69 [ F_90 ( V_8 ) ] ;
F_25 ( & V_68 -> V_42 ) ;
if ( V_8 -> V_76 ) {
V_116 = F_82 ( V_8 , V_68 , F_83 ) ;
if ( V_116 )
goto V_118;
}
F_69 ( V_8 , & V_68 -> V_22 ) ;
F_72 ( F_9 ( V_8 ) , V_8 -> V_38 , 1 ) ;
V_118:
F_27 ( & V_68 -> V_42 ) ;
return V_116 ;
}
int F_91 ( struct V_7 * V_8 )
{
int V_116 = 0 ;
if ( V_8 -> V_81 != V_110 ) {
F_29 () ;
V_116 = F_89 ( V_8 , NULL , V_119 ) ;
F_30 () ;
}
return V_116 ;
}
void F_92 ( struct V_7 * V_8 )
{
struct V_36 * V_37 = V_8 -> V_38 -> V_39 . V_37 ;
T_8 * V_42 ;
int V_120 ;
if ( F_68 ( V_8 ) )
return;
if ( V_8 -> V_81 == V_117 )
V_42 = & V_37 -> V_69 [ F_90 ( V_8 ) ] . V_42 ;
else
V_42 = F_63 ( V_37 , V_8 -> V_90 ) ;
F_93 ( V_42 ) ;
if ( F_87 ( V_8 -> V_115 ) )
F_94 ( V_8 ) ;
V_120 = F_95 ( V_8 ) ;
if ( V_120 )
F_72 ( F_9 ( V_8 ) , V_8 -> V_38 , - 1 ) ;
F_96 ( V_42 ) ;
}
int F_97 ( struct V_92 * V_93 ,
struct V_7 * V_8 , T_1 V_121 ,
int (* F_98)( struct V_92 * ,
struct V_7 * , T_3 , struct V_94 * * ) )
{
struct V_36 * V_96 = V_93 -> V_37 ;
struct V_94 * V_99 = NULL ;
struct V_21 * V_22 ;
int V_27 = F_20 ( V_8 ) -> V_34 ;
struct V_1 * V_1 = F_9 ( V_8 ) ;
struct V_18 * V_24 ;
T_1 V_122 , V_123 ;
int V_107 , V_124 , V_125 , V_126 ;
static T_1 V_127 ;
if ( V_27 ) {
V_22 = & V_96 -> V_40 [ F_24 ( V_1 , V_27 ,
V_96 -> V_41 ) ] ;
V_24 = F_22 ( V_8 ) -> V_35 ;
F_93 ( & V_22 -> V_42 ) ;
if ( F_99 ( & V_24 -> V_31 ) == V_8 && ! V_8 -> V_128 . V_129 ) {
F_78 ( V_8 , NULL ) ;
F_96 ( & V_22 -> V_42 ) ;
return 0 ;
}
F_27 ( & V_22 -> V_42 ) ;
V_107 = F_98 ( V_93 , V_8 , V_27 , NULL ) ;
F_30 () ;
return V_107 ;
}
F_100 ( V_1 , & V_125 , & V_126 ) ;
V_126 ++ ;
V_122 = V_126 - V_125 ;
if ( F_60 ( V_122 > 1 ) )
V_122 &= ~ 1U ;
V_123 = ( V_127 + V_121 ) % V_122 ;
V_123 &= ~ 1U ;
V_130:
V_27 = V_125 + V_123 ;
for ( V_124 = 0 ; V_124 < V_122 ; V_124 += 2 , V_27 += 2 ) {
if ( F_32 ( V_27 >= V_126 ) )
V_27 -= V_122 ;
if ( F_101 ( V_1 , V_27 ) )
continue;
V_22 = & V_96 -> V_40 [ F_24 ( V_1 , V_27 ,
V_96 -> V_41 ) ] ;
F_93 ( & V_22 -> V_42 ) ;
F_33 (tb, &head->chain) {
if ( F_34 ( V_26 ( V_24 ) , V_1 ) && V_24 -> V_27 == V_27 ) {
if ( V_24 -> V_28 >= 0 ||
V_24 -> V_29 >= 0 )
goto V_131;
F_67 ( F_16 ( & V_24 -> V_31 ) ) ;
if ( ! F_98 ( V_93 , V_8 ,
V_27 , & V_99 ) )
goto V_108;
goto V_131;
}
}
V_24 = F_10 ( V_96 -> V_43 ,
V_1 , V_22 , V_27 ) ;
if ( ! V_24 ) {
F_96 ( & V_22 -> V_42 ) ;
return - V_47 ;
}
V_24 -> V_28 = - 1 ;
V_24 -> V_29 = - 1 ;
goto V_108;
V_131:
F_96 ( & V_22 -> V_42 ) ;
F_102 () ;
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
F_103 ( V_99 , V_96 ) ;
F_27 ( & V_22 -> V_42 ) ;
if ( V_99 )
F_73 ( V_99 ) ;
F_30 () ;
return 0 ;
}
int F_104 ( struct V_92 * V_93 ,
struct V_7 * V_8 )
{
T_1 V_121 = 0 ;
if ( ! F_20 ( V_8 ) -> V_34 )
V_121 = F_74 ( V_8 ) ;
return F_97 ( V_93 , V_8 , V_121 ,
F_62 ) ;
}
void F_105 ( struct V_36 * V_39 )
{
int V_124 ;
for ( V_124 = 0 ; V_124 < V_132 ; V_124 ++ ) {
F_106 ( & V_39 -> V_69 [ V_124 ] . V_42 ) ;
F_107 ( & V_39 -> V_69 [ V_124 ] . V_22 ,
V_124 + V_79 ) ;
}
}
int F_108 ( struct V_36 * V_37 )
{
unsigned int V_133 = sizeof( T_8 ) ;
unsigned int V_124 , V_134 = 1 ;
if ( V_133 != 0 ) {
V_134 = F_109 ( 2U * V_135 / V_133 , 1U ) ;
V_134 = F_110 ( V_134 * F_111 () ) ;
V_134 = F_112 ( V_134 , V_37 -> V_87 + 1 ) ;
V_37 -> V_136 = F_113 ( V_134 , V_133 ,
V_137 | V_138 ) ;
if ( ! V_37 -> V_136 )
V_37 -> V_136 = F_114 ( V_134 * V_133 ) ;
if ( ! V_37 -> V_136 )
return - V_47 ;
for ( V_124 = 0 ; V_124 < V_134 ; V_124 ++ )
F_106 ( & V_37 -> V_136 [ V_124 ] ) ;
}
V_37 -> V_139 = V_134 - 1 ;
return 0 ;
}
