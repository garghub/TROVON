static const char * F_1 ( struct V_1 * V_1 )
{
return L_1 ;
}
static const char * F_2 ( struct V_1 * V_1 )
{
return L_2 ;
}
static bool F_3 ( struct V_1 * V_1 )
{
return F_4 ( F_5 ( V_1 ) ) ;
}
static bool F_6 ( struct V_1 * V_1 )
{
if ( F_3 ( V_1 ) )
return false ;
F_7 ( F_5 ( V_1 ) ) ;
return true ;
}
static signed long F_8 ( struct V_1 * V_1 ,
bool V_2 ,
signed long V_3 )
{
T_1 V_4 , * V_5 ;
int V_6 ;
if ( V_3 != V_7 ) {
V_4 = F_9 ( V_3 ) ;
V_5 = & V_4 ;
} else {
V_5 = NULL ;
}
V_6 = F_10 ( F_5 ( V_1 ) ,
V_2 , V_5 ,
V_8 ) ;
if ( V_6 == - V_9 )
return 0 ;
if ( V_6 < 0 )
return V_6 ;
if ( V_3 != V_7 )
V_3 = F_11 ( V_4 ) ;
return V_3 ;
}
static void F_12 ( struct V_1 * V_1 , char * V_10 , int V_11 )
{
snprintf ( V_10 , V_11 , L_3 , V_1 -> V_12 ) ;
}
static void F_13 ( struct V_1 * V_1 , char * V_10 ,
int V_11 )
{
snprintf ( V_10 , V_11 , L_3 ,
F_14 ( F_5 ( V_1 ) -> V_13 ) ) ;
}
static void F_15 ( struct V_1 * V_1 )
{
struct V_14 * V_15 = F_5 ( V_1 ) ;
F_16 ( V_15 -> V_16 -> V_17 , V_15 ) ;
}
int F_17 ( struct V_14 * V_15 ,
struct V_18 * V_19 )
{
struct V_20 * V_21 ;
struct V_22 * V_23 ;
F_18 ( ! V_15 || ! V_19 || V_15 -> V_23 ) ;
if ( ! V_15 || ! V_19 )
return - V_24 ;
if ( V_15 -> V_23 )
return - V_24 ;
V_21 = V_15 -> V_16 ;
V_23 = V_19 -> V_25 ;
F_19 ( & V_23 -> V_26 . V_27 ) ;
V_15 -> V_23 = V_23 ;
F_20 ( & V_15 -> V_28 , & V_23 -> V_26 . V_29 ) ;
F_21 ( & V_23 -> V_26 . V_27 ) ;
return 0 ;
}
static inline void
F_22 ( struct V_14 * V_30 )
{
struct V_22 * V_23 = V_30 -> V_23 ;
if ( ! V_23 )
return;
F_19 ( & V_23 -> V_26 . V_27 ) ;
F_23 ( & V_30 -> V_28 ) ;
V_30 -> V_23 = NULL ;
F_21 ( & V_23 -> V_26 . V_27 ) ;
}
void F_24 ( struct V_31 * V_32 ,
struct V_14 * V_30 )
{
}
static void F_25 ( struct V_14 * V_30 )
{
struct V_31 * V_32 , * V_33 ;
F_26 ( V_30 ) ;
F_23 ( & V_30 -> V_34 ) ;
F_23 ( & V_30 -> V_35 ) ;
V_30 -> V_36 -> V_37 = V_30 -> V_38 ;
F_27 (active, next, &request->active_list, link) {
F_28 ( V_33 ) ;
F_29 ( & V_32 -> V_34 ) ;
F_30 ( V_32 -> V_30 , NULL ) ;
V_32 -> V_39 ( V_32 , V_30 ) ;
}
F_22 ( V_30 ) ;
if ( V_30 -> V_40 ) {
if ( V_16 . V_41 )
F_31 ( V_30 -> V_40 ,
V_30 -> V_13 ) ;
}
F_32 ( V_30 -> V_42 ) ;
F_33 ( V_30 ) ;
}
void F_34 ( struct V_14 * V_15 )
{
struct V_43 * V_13 = V_15 -> V_13 ;
struct V_14 * V_44 ;
F_35 ( & V_15 -> V_16 -> V_45 . V_46 ) ;
F_36 ( F_37 ( & V_15 -> V_34 ) ) ;
do {
V_44 = F_38 ( & V_13 -> V_29 ,
F_39 ( * V_44 ) , V_34 ) ;
F_25 ( V_44 ) ;
} while ( V_44 != V_15 );
}
static int F_40 ( struct V_20 * V_47 )
{
struct V_48 * error = & V_47 -> V_49 ;
if ( F_41 ( error ) )
return - V_50 ;
if ( F_42 ( error ) ) {
if ( ! V_47 -> V_26 . V_2 )
return - V_50 ;
return - V_51 ;
}
return 0 ;
}
static int F_43 ( struct V_20 * V_47 , T_2 V_12 )
{
struct V_43 * V_13 ;
int V_6 ;
F_44 (engine, dev_priv) {
V_6 = F_45 ( V_13 ,
V_52 |
V_53 ) ;
if ( V_6 )
return V_6 ;
}
F_46 ( V_47 ) ;
if ( ! F_47 ( V_12 , V_47 -> V_54 ) ) {
while ( F_48 ( V_47 ) ||
F_49 ( V_47 ) )
F_50 () ;
}
F_44 (engine, dev_priv)
F_51 ( V_13 , V_12 ) ;
return 0 ;
}
int F_52 ( struct V_55 * V_56 , T_2 V_12 )
{
struct V_20 * V_47 = F_53 ( V_56 ) ;
int V_6 ;
if ( V_12 == 0 )
return - V_24 ;
V_6 = F_43 ( V_47 , V_12 - 1 ) ;
if ( V_6 )
return V_6 ;
V_47 -> V_54 = V_12 ;
return 0 ;
}
static int F_54 ( struct V_20 * V_47 , T_2 * V_12 )
{
if ( F_55 ( V_47 -> V_54 == 0 ) ) {
int V_6 ;
V_6 = F_43 ( V_47 , 0 ) ;
if ( V_6 )
return V_6 ;
V_47 -> V_54 = 1 ;
}
* V_12 = V_47 -> V_54 ++ ;
return 0 ;
}
static int T_3
F_56 ( struct V_57 * V_1 , enum V_58 V_59 )
{
struct V_14 * V_30 =
F_57 ( V_1 , F_39 ( * V_30 ) , V_60 ) ;
switch ( V_59 ) {
case V_61 :
V_30 -> V_13 -> V_62 = V_30 -> V_1 . V_12 ;
V_30 -> V_13 -> V_63 ( V_30 ) ;
break;
case V_64 :
break;
}
return V_65 ;
}
struct V_14 *
F_58 ( struct V_43 * V_13 ,
struct V_66 * V_42 )
{
struct V_20 * V_47 = V_13 -> V_16 ;
struct V_14 * V_15 ;
T_2 V_12 ;
int V_6 ;
V_6 = F_40 ( V_47 ) ;
if ( V_6 )
return F_59 ( V_6 ) ;
V_15 = F_60 ( & V_13 -> V_29 ,
F_39 ( * V_15 ) , V_34 ) ;
if ( V_15 && F_4 ( V_15 ) )
F_25 ( V_15 ) ;
V_15 = F_61 ( V_47 -> V_17 , V_67 ) ;
if ( ! V_15 )
return F_59 ( - V_68 ) ;
V_6 = F_54 ( V_47 , & V_12 ) ;
if ( V_6 )
goto V_69;
F_62 ( & V_15 -> V_27 ) ;
F_63 ( & V_15 -> V_1 ,
& V_70 ,
& V_15 -> V_27 ,
V_13 -> V_71 ,
V_12 ) ;
F_64 ( & V_15 -> V_60 , F_56 ) ;
F_29 ( & V_15 -> V_72 ) ;
V_15 -> V_16 = V_47 ;
V_15 -> V_13 = V_13 ;
V_15 -> V_42 = F_65 ( V_42 ) ;
V_15 -> V_40 = NULL ;
V_15 -> V_23 = NULL ;
V_15 -> V_73 = NULL ;
V_15 -> V_74 = V_75 ;
if ( V_16 . V_41 )
V_6 = F_66 ( V_15 ) ;
else
V_6 = F_67 ( V_15 ) ;
if ( V_6 )
goto V_76;
V_15 -> V_77 = V_15 -> V_36 -> V_78 ;
return V_15 ;
V_76:
F_32 ( V_42 ) ;
V_69:
F_16 ( V_47 -> V_17 , V_15 ) ;
return F_59 ( V_6 ) ;
}
static int
F_68 ( struct V_14 * V_79 ,
struct V_14 * V_80 )
{
int V_81 , V_6 ;
F_36 ( V_79 == V_80 ) ;
if ( V_79 -> V_13 == V_80 -> V_13 )
return 0 ;
V_81 = F_69 ( V_80 -> V_13 , V_79 -> V_13 ) ;
if ( V_80 -> V_1 . V_12 <= V_80 -> V_13 -> V_82 . V_83 [ V_81 ] )
return 0 ;
F_70 ( V_79 , V_80 ) ;
if ( ! V_16 . V_84 ) {
if ( ! F_71 ( V_80 , V_85 , 2 ) ) {
V_6 = F_72 ( & V_79 -> V_60 ,
& V_80 -> V_1 , 0 ,
V_67 ) ;
if ( V_6 < 0 )
return V_6 ;
}
} else {
V_6 = V_79 -> V_13 -> V_82 . V_86 ( V_79 , V_80 ) ;
if ( V_6 )
return V_6 ;
}
V_80 -> V_13 -> V_82 . V_83 [ V_81 ] = V_80 -> V_1 . V_12 ;
return 0 ;
}
int
F_73 ( struct V_14 * V_79 ,
struct V_87 * V_88 ,
bool V_89 )
{
struct V_31 * V_32 ;
unsigned long V_90 ;
int V_81 ;
if ( V_89 ) {
V_90 = F_74 ( V_88 ) ;
V_32 = V_88 -> V_91 ;
} else {
V_90 = 1 ;
V_32 = & V_88 -> V_92 ;
}
F_75 (active_mask, idx) {
struct V_14 * V_30 ;
int V_6 ;
V_30 = F_76 ( & V_32 [ V_81 ] ,
& V_88 -> V_93 . V_56 -> V_46 ) ;
if ( ! V_30 )
continue;
V_6 = F_68 ( V_79 , V_30 ) ;
if ( V_6 )
return V_6 ;
}
return 0 ;
}
static void F_77 ( const struct V_43 * V_13 )
{
struct V_20 * V_47 = V_13 -> V_16 ;
V_47 -> V_94 . V_95 |= F_78 ( V_13 ) ;
if ( V_47 -> V_94 . V_96 )
return;
F_79 ( V_47 ) ;
V_47 -> V_94 . V_96 = true ;
F_80 ( V_47 ) ;
F_81 ( V_47 ) ;
if ( F_82 ( V_47 ) >= 6 )
F_83 ( V_47 ) ;
F_84 ( V_47 -> V_97 ,
& V_47 -> V_94 . V_98 ,
F_85 ( V_99 ) ) ;
}
void F_86 ( struct V_14 * V_30 , bool V_100 )
{
struct V_43 * V_13 = V_30 -> V_13 ;
struct V_101 * V_36 = V_30 -> V_36 ;
struct V_14 * V_102 ;
T_2 V_103 ;
T_2 V_104 ;
int V_6 ;
F_87 ( V_30 ) ;
V_103 = V_36 -> V_78 ;
V_104 = V_30 -> V_74 ;
V_30 -> V_74 = 0 ;
if ( V_100 ) {
V_6 = V_13 -> V_105 ( V_30 , V_106 ) ;
F_88 ( V_6 , L_4 , V_6 ) ;
}
V_30 -> V_38 = V_36 -> V_78 ;
V_6 = V_13 -> V_107 ( V_30 ) ;
F_88 ( V_6 , L_5 , V_13 -> V_108 , V_6 ) ;
V_6 = V_36 -> V_78 - V_103 ;
if ( V_6 < 0 )
V_6 += V_36 -> V_11 ;
F_89 ( V_6 > V_104 ,
L_6
L_7 ,
V_104 , V_6 ) ;
V_102 = F_90 ( & V_13 -> V_109 ,
& V_30 -> V_16 -> V_45 . V_46 ) ;
if ( V_102 )
F_91 ( & V_30 -> V_60 , & V_102 -> V_60 ,
& V_30 -> V_110 ) ;
V_30 -> V_111 = V_112 ;
V_30 -> V_113 = V_13 -> V_114 ;
V_13 -> V_114 = V_30 -> V_1 . V_12 ;
F_92 ( & V_13 -> V_109 , V_30 ) ;
F_20 ( & V_30 -> V_34 , & V_13 -> V_29 ) ;
F_20 ( & V_30 -> V_35 , & V_36 -> V_29 ) ;
F_77 ( V_13 ) ;
F_93 () ;
F_94 ( & V_30 -> V_60 ) ;
F_95 () ;
}
static void F_96 ( T_4 * V_115 , T_5 * V_116 )
{
unsigned long V_117 ;
F_97 ( & V_115 -> V_27 , V_117 ) ;
if ( F_37 ( & V_116 -> V_118 ) )
F_98 ( V_115 , V_116 ) ;
F_99 ( & V_115 -> V_27 , V_117 ) ;
}
static unsigned long F_100 ( unsigned int * V_119 )
{
unsigned long V_120 ;
* V_119 = F_101 () ;
V_120 = F_102 () >> 10 ;
F_103 () ;
return V_120 ;
}
static bool F_104 ( unsigned long V_5 , unsigned int V_119 )
{
unsigned int V_121 ;
if ( F_105 ( F_100 ( & V_121 ) , V_5 ) )
return true ;
return V_121 != V_119 ;
}
bool F_106 ( const struct V_14 * V_15 ,
int V_59 , unsigned long V_122 )
{
unsigned int V_119 ;
V_122 += F_100 ( & V_119 ) ;
do {
if ( F_4 ( V_15 ) )
return true ;
if ( F_107 ( V_59 , V_123 ) )
break;
if ( F_104 ( V_122 , V_119 ) )
break;
F_108 () ;
} while ( ! F_109 () );
return false ;
}
int F_10 ( struct V_14 * V_15 ,
unsigned int V_117 ,
T_1 * V_5 ,
struct V_124 * V_125 )
{
const int V_59 = V_117 & V_52 ?
V_85 : V_126 ;
F_110 ( V_127 ) ;
struct V_128 V_116 ;
unsigned long V_129 ;
int V_6 = 0 ;
F_111 () ;
#if F_112 ( V_130 )
F_36 ( ! ! F_113 ( & V_15 -> V_16 -> V_45 . V_46 ) !=
! ! ( V_117 & V_53 ) ) ;
#endif
if ( F_4 ( V_15 ) )
return 0 ;
V_129 = V_7 ;
if ( V_5 ) {
if ( F_18 ( * V_5 < 0 ) )
return - V_24 ;
if ( * V_5 == 0 )
return - V_9 ;
V_129 = F_114 ( * V_5 ) ;
* V_5 += F_115 () ;
}
F_116 ( V_15 ) ;
if ( F_117 ( V_125 ) && F_82 ( V_15 -> V_16 ) >= 6 )
F_118 ( V_15 -> V_16 , V_125 , V_15 -> V_111 ) ;
if ( F_71 ( V_15 , V_59 , 5 ) )
goto V_131;
F_119 ( V_59 ) ;
if ( V_117 & V_53 )
F_120 ( & V_15 -> V_16 -> V_49 . V_132 , & V_127 ) ;
F_121 ( & V_116 , V_15 -> V_1 . V_12 ) ;
if ( F_122 ( V_15 -> V_13 , & V_116 ) )
goto V_133;
for (; ; ) {
if ( F_107 ( V_59 , V_123 ) ) {
V_6 = - V_134 ;
break;
}
V_129 = F_123 ( V_129 ) ;
if ( V_129 == 0 ) {
V_6 = - V_9 ;
break;
}
if ( F_124 ( & V_116 ) )
break;
F_119 ( V_59 ) ;
V_133:
if ( F_125 ( V_15 ) )
break;
if ( V_117 & V_53 &&
F_42 ( & V_15 -> V_16 -> V_49 ) ) {
F_126 ( V_135 ) ;
F_127 ( V_15 -> V_16 ) ;
F_96 ( & V_15 -> V_16 -> V_49 . V_132 ,
& V_127 ) ;
continue;
}
if ( F_71 ( V_15 , V_59 , 2 ) )
break;
}
F_128 ( V_15 -> V_13 , & V_116 ) ;
if ( V_117 & V_53 )
F_129 ( & V_15 -> V_16 -> V_49 . V_132 , & V_127 ) ;
F_126 ( V_135 ) ;
V_131:
F_130 ( V_15 ) ;
if ( V_5 ) {
* V_5 -= F_115 () ;
if ( * V_5 < 0 )
* V_5 = 0 ;
if ( V_6 == - V_9 && * V_5 < F_131 ( 1 ) * 1000 )
* V_5 = 0 ;
}
if ( F_132 ( V_125 ) &&
V_15 -> V_1 . V_12 == V_15 -> V_13 -> V_62 ) {
F_19 ( & V_15 -> V_16 -> V_125 . V_136 ) ;
F_133 ( & V_125 -> V_34 ) ;
F_21 ( & V_15 -> V_16 -> V_125 . V_136 ) ;
}
return V_6 ;
}
static bool F_134 ( struct V_43 * V_13 )
{
struct V_14 * V_30 , * V_33 ;
F_27 (request, next, &engine->request_list, link) {
if ( ! F_4 ( V_30 ) )
return false ;
F_25 ( V_30 ) ;
}
return true ;
}
void F_46 ( struct V_20 * V_47 )
{
struct V_43 * V_13 ;
unsigned int V_44 ;
F_35 ( & V_47 -> V_45 . V_46 ) ;
if ( V_47 -> V_94 . V_95 == 0 )
return;
F_36 ( ! V_47 -> V_94 . V_96 ) ;
F_135 (engine, dev_priv, dev_priv->gt.active_engines, tmp)
if ( F_134 ( V_13 ) )
V_47 -> V_94 . V_95 &= ~ F_78 ( V_13 ) ;
if ( V_47 -> V_94 . V_95 == 0 )
F_84 ( V_47 -> V_97 ,
& V_47 -> V_94 . V_137 ,
F_136 ( 100 ) ) ;
}
