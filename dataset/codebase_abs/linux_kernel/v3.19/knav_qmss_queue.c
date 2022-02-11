void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( ! V_2 )
return;
F_2 () ;
F_3 (qh, inst) {
if ( F_4 ( & V_4 -> V_5 ) <= 0 )
continue;
if ( F_5 ( ! V_4 -> V_6 ) )
continue;
F_6 ( & V_4 -> V_7 . V_8 ) ;
V_4 -> V_6 ( V_4 -> V_9 ) ;
}
F_7 () ;
}
static T_1 F_8 ( int V_10 , void * V_11 )
{
struct V_1 * V_2 = V_11 ;
F_1 ( V_2 ) ;
return V_12 ;
}
static int F_9 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
unsigned V_15 = V_2 -> V_16 - V_14 -> V_17 ;
unsigned long V_18 ;
int V_19 = 0 , V_10 ;
if ( V_14 -> V_20 & V_21 ) {
V_10 = V_14 -> V_22 [ V_15 ] . V_10 ;
V_18 = V_14 -> V_22 [ V_15 ] . V_18 ;
V_19 = F_10 ( V_10 , F_8 , 0 ,
V_2 -> V_23 , V_2 ) ;
if ( V_19 )
return V_19 ;
F_11 ( V_10 ) ;
if ( V_18 ) {
V_19 = F_12 ( V_10 , F_13 ( & V_18 ) ) ;
if ( V_19 ) {
F_14 ( V_14 -> V_24 -> V_25 ,
L_1 ) ;
return V_19 ;
}
}
}
return V_19 ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
unsigned V_15 = V_2 -> V_16 - V_2 -> V_14 -> V_17 ;
int V_10 ;
if ( V_14 -> V_20 & V_21 ) {
V_10 = V_14 -> V_22 [ V_15 ] . V_10 ;
F_12 ( V_10 , NULL ) ;
F_16 ( V_10 , V_2 ) ;
}
}
static inline bool F_17 ( struct V_1 * V_2 )
{
return ! F_18 ( & V_2 -> V_26 ) ;
}
static inline bool F_19 ( struct V_1 * V_2 )
{
return V_2 -> V_14 -> V_20 & V_27 ;
}
static inline bool F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_28 ;
F_2 () ;
F_3 (tmp, inst) {
if ( V_28 -> V_20 & V_29 ) {
F_7 () ;
return true ;
}
}
F_7 () ;
return false ;
}
static inline bool F_21 ( struct V_1 * V_2 ,
unsigned type )
{
if ( ( type == V_30 ) &&
( V_2 -> V_14 -> V_20 & V_21 ) ) {
return true ;
} else if ( ( type == V_31 ) &&
( V_2 -> V_14 -> V_20 & V_32 ) ) {
return true ;
} else if ( ( type == V_33 ) &&
! ( V_2 -> V_14 -> V_20 &
( V_32 | V_21 ) ) ) {
return true ;
}
return false ;
}
static inline struct V_1 *
F_22 ( struct V_34 * V_24 , unsigned V_16 )
{
struct V_1 * V_2 ;
int V_35 ;
F_23 (idx, inst, kdev) {
if ( V_2 -> V_16 == V_16 )
return V_2 ;
}
return NULL ;
}
static inline struct V_1 * F_24 ( int V_16 )
{
if ( V_24 -> V_36 <= V_16 &&
V_24 -> V_36 + V_24 -> V_37 > V_16 ) {
V_16 -= V_24 -> V_36 ;
return F_22 ( V_24 , V_16 ) ;
}
return NULL ;
}
static struct V_3 * F_25 ( struct V_1 * V_2 ,
const char * V_38 , unsigned V_20 )
{
struct V_3 * V_4 ;
unsigned V_16 ;
int V_19 = 0 ;
V_4 = F_26 ( V_2 -> V_24 -> V_25 , sizeof( * V_4 ) , V_39 ) ;
if ( ! V_4 )
return F_27 ( - V_40 ) ;
V_4 -> V_20 = V_20 ;
V_4 -> V_2 = V_2 ;
V_16 = V_2 -> V_16 - V_2 -> V_41 -> V_42 ;
V_4 -> V_43 = & V_2 -> V_41 -> V_43 [ V_16 ] ;
V_4 -> V_44 = & V_2 -> V_41 -> V_44 [ V_16 ] ;
V_4 -> V_45 = & V_2 -> V_41 -> V_45 [ V_16 ] ;
if ( ! F_17 ( V_2 ) ) {
struct V_13 * V_14 = V_2 -> V_14 ;
V_2 -> V_38 = F_28 ( V_38 , V_46 , V_39 ) ;
if ( V_14 -> V_47 && V_14 -> V_47 -> V_48 )
V_19 = V_14 -> V_47 -> V_48 ( V_14 , V_2 , V_20 ) ;
if ( V_19 ) {
F_29 ( V_2 -> V_24 -> V_25 , V_4 ) ;
return F_27 ( V_19 ) ;
}
}
F_30 ( & V_4 -> V_49 , & V_2 -> V_26 ) ;
return V_4 ;
}
static struct V_3 *
F_31 ( const char * V_38 , unsigned V_16 , unsigned V_20 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
F_32 ( & V_50 ) ;
V_4 = F_27 ( - V_51 ) ;
V_2 = F_24 ( V_16 ) ;
if ( ! V_2 )
goto V_52;
V_4 = F_27 ( - V_53 ) ;
if ( ! ( V_20 & V_29 ) && F_17 ( V_2 ) )
goto V_52;
V_4 = F_27 ( - V_54 ) ;
if ( ( V_20 & V_29 ) &&
( F_17 ( V_2 ) && ! F_20 ( V_2 ) ) )
goto V_52;
V_4 = F_25 ( V_2 , V_38 , V_20 ) ;
V_52:
F_33 ( & V_50 ) ;
return V_4 ;
}
static struct V_3 * F_34 ( const char * V_38 ,
unsigned type , unsigned V_20 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = F_27 ( - V_55 ) ;
int V_35 ;
F_32 ( & V_50 ) ;
F_23 (idx, inst, kdev) {
if ( F_19 ( V_2 ) )
continue;
if ( ! F_21 ( V_2 , type ) )
continue;
if ( F_17 ( V_2 ) )
continue;
V_4 = F_25 ( V_2 , V_38 , V_20 ) ;
goto V_52;
}
V_52:
F_33 ( & V_50 ) ;
return V_4 ;
}
static void F_35 ( struct V_1 * V_2 , bool V_56 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_14 -> V_47 && V_14 -> V_47 -> V_57 )
V_14 -> V_47 -> V_57 ( V_14 , V_2 , V_56 ) ;
}
static int F_36 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
bool V_58 ;
if ( F_5 ( ! V_4 -> V_6 ) )
return - V_55 ;
V_58 = ( F_37 ( & V_4 -> V_5 ) == 1 ) ;
if ( ! V_58 )
return 0 ;
V_58 = ( F_37 ( & V_2 -> V_59 ) == 1 ) ;
if ( V_58 )
F_35 ( V_2 , true ) ;
return 0 ;
}
static int F_38 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
bool V_60 ;
V_60 = ( F_39 ( & V_4 -> V_5 ) == 0 ) ;
if ( ! V_60 )
return 0 ;
V_60 = ( F_39 ( & V_2 -> V_59 ) == 0 ) ;
if ( V_60 )
F_35 ( V_2 , false ) ;
return 0 ;
}
static int F_40 ( struct V_3 * V_4 ,
struct V_61 * V_62 )
{
T_2 V_63 = V_4 -> V_6 ;
if ( ! V_62 )
return - V_55 ;
if ( ! ( V_4 -> V_2 -> V_14 -> V_20 & ( V_32 | V_21 ) ) )
return - V_64 ;
if ( ! V_62 -> V_65 && V_63 )
F_38 ( V_4 ) ;
V_4 -> V_6 = V_62 -> V_65 ;
V_4 -> V_9 = V_62 -> V_66 ;
if ( V_62 -> V_65 && ! V_63 )
F_36 ( V_4 ) ;
return 0 ;
}
static int F_41 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
bool V_56 )
{
unsigned V_15 ;
if ( V_14 -> V_20 & V_21 ) {
V_15 = V_2 -> V_16 - V_14 -> V_17 ;
if ( V_56 )
F_42 ( V_14 -> V_22 [ V_15 ] . V_10 ) ;
else
F_43 ( V_14 -> V_22 [ V_15 ] . V_10 ) ;
}
return 0 ;
}
static int F_44 ( struct V_13 * V_14 ,
struct V_1 * V_2 , unsigned V_20 )
{
return F_9 ( V_14 , V_2 ) ;
}
static int F_45 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
F_15 ( V_2 ) ;
return 0 ;
}
static int F_46 ( void * V_67 )
{
struct V_3 * V_4 = V_67 ;
struct V_1 * V_2 = V_4 -> V_2 ;
return F_47 ( & V_4 -> V_45 [ 0 ] . V_68 ) +
F_4 ( & V_2 -> V_69 ) ;
}
static void F_48 ( struct V_70 * V_71 ,
struct V_1 * V_2 )
{
struct V_34 * V_24 = V_2 -> V_24 ;
struct V_3 * V_4 ;
if ( ! F_17 ( V_2 ) )
return;
F_49 ( V_71 , L_2 ,
V_24 -> V_36 + V_2 -> V_16 , V_2 -> V_38 ) ;
F_3 (qh, inst) {
F_49 ( V_71 , L_3 , V_4 ) ;
F_49 ( V_71 , L_4 ,
F_4 ( & V_4 -> V_7 . V_72 ) ) ;
F_49 ( V_71 , L_5 ,
F_4 ( & V_4 -> V_7 . V_73 ) ) ;
F_49 ( V_71 , L_6 ,
F_46 ( V_4 ) ) ;
F_49 ( V_71 , L_7 ,
F_4 ( & V_4 -> V_7 . V_8 ) ) ;
F_49 ( V_71 , L_8 ,
F_4 ( & V_4 -> V_7 . V_74 ) ) ;
F_49 ( V_71 , L_9 ,
F_4 ( & V_4 -> V_7 . V_75 ) ) ;
}
}
static int F_50 ( struct V_70 * V_71 , void * V_76 )
{
struct V_1 * V_2 ;
int V_35 ;
F_32 ( & V_50 ) ;
F_49 ( V_71 , L_10 ,
F_51 ( V_24 -> V_25 ) , V_24 -> V_36 ,
V_24 -> V_36 + V_24 -> V_37 - 1 ) ;
F_23 (idx, inst, kdev)
F_48 ( V_71 , V_2 ) ;
F_33 ( & V_50 ) ;
return 0 ;
}
static int F_52 ( struct V_77 * V_77 , struct V_78 * V_78 )
{
return F_53 ( V_78 , F_50 , NULL ) ;
}
static inline int F_54 ( T_3 * T_4 V_79 , unsigned V_80 ,
T_3 V_20 )
{
unsigned long V_81 ;
T_3 V_82 = 0 ;
V_81 = V_83 + F_55 ( V_80 ) ;
while ( F_56 ( V_81 , V_83 ) ) {
V_82 = F_47 ( V_79 ) ;
if ( V_20 )
V_82 &= V_20 ;
if ( ! V_82 )
break;
F_57 () ;
}
return V_82 ? - V_84 : 0 ;
}
static int F_58 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
unsigned V_16 = V_2 -> V_16 - V_2 -> V_41 -> V_42 ;
F_59 ( & V_2 -> V_69 , 0 ) ;
F_60 ( 0 , & V_2 -> V_41 -> V_43 [ V_16 ] . V_85 ) ;
return 0 ;
}
void * F_61 ( const char * V_38 , unsigned V_16 ,
unsigned V_20 )
{
struct V_3 * V_4 = F_27 ( - V_55 ) ;
switch ( V_16 ) {
case V_30 :
case V_31 :
case V_33 :
V_4 = F_34 ( V_38 , V_16 , V_20 ) ;
break;
default:
V_4 = F_31 ( V_38 , V_16 , V_20 ) ;
break;
}
return V_4 ;
}
void F_62 ( void * V_67 )
{
struct V_3 * V_4 = V_67 ;
struct V_1 * V_2 = V_4 -> V_2 ;
while ( F_4 ( & V_4 -> V_5 ) > 0 )
F_38 ( V_4 ) ;
F_32 ( & V_50 ) ;
F_63 ( & V_4 -> V_49 ) ;
F_33 ( & V_50 ) ;
F_64 () ;
if ( ! F_17 ( V_2 ) ) {
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_14 -> V_47 && V_14 -> V_47 -> V_86 )
V_14 -> V_47 -> V_86 ( V_14 , V_2 ) ;
}
F_29 ( V_2 -> V_24 -> V_25 , V_4 ) ;
}
int F_65 ( void * V_67 , enum V_87 V_88 ,
unsigned long V_89 )
{
struct V_3 * V_4 = V_67 ;
struct V_61 * V_62 ;
int V_19 ;
switch ( ( int ) V_88 ) {
case V_90 :
V_19 = V_4 -> V_2 -> V_24 -> V_36 + V_4 -> V_2 -> V_16 ;
break;
case V_91 :
V_19 = F_58 ( V_4 ) ;
break;
case V_92 :
V_62 = ( void * ) V_89 ;
V_19 = F_40 ( V_4 , V_62 ) ;
break;
case V_93 :
V_19 = F_36 ( V_4 ) ;
break;
case V_94 :
V_19 = F_38 ( V_4 ) ;
break;
case V_95 :
V_19 = F_46 ( V_4 ) ;
break;
default:
V_19 = - V_64 ;
break;
}
return V_19 ;
}
int F_66 ( void * V_67 , T_5 V_96 ,
unsigned V_97 , unsigned V_20 )
{
struct V_3 * V_4 = V_67 ;
T_3 V_82 ;
V_82 = ( T_3 ) V_96 | ( ( V_97 / 16 ) - 1 ) ;
F_60 ( V_82 , & V_4 -> V_43 [ 0 ] . V_85 ) ;
F_6 ( & V_4 -> V_7 . V_72 ) ;
return 0 ;
}
T_5 F_67 ( void * V_67 , unsigned * V_97 )
{
struct V_3 * V_4 = V_67 ;
struct V_1 * V_2 = V_4 -> V_2 ;
T_5 V_96 ;
T_3 V_82 , V_35 ;
if ( V_2 -> V_98 ) {
if ( F_68 ( F_39 ( & V_2 -> V_69 ) < 0 ) ) {
F_6 ( & V_2 -> V_69 ) ;
return 0 ;
}
V_35 = F_37 ( & V_2 -> V_99 ) ;
V_35 &= V_100 ;
V_82 = V_2 -> V_98 [ V_35 ] ;
} else {
V_82 = F_47 ( & V_4 -> V_44 [ 0 ] . V_85 ) ;
if ( F_68 ( ! V_82 ) )
return 0 ;
}
V_96 = V_82 & V_101 ;
if ( V_97 )
* V_97 = ( ( V_82 & V_102 ) + 1 ) * 16 ;
F_6 ( & V_4 -> V_7 . V_73 ) ;
return V_96 ;
}
static void F_69 ( struct V_103 * V_104 )
{
struct V_105 * V_106 ;
int V_107 ;
V_106 = V_104 -> V_106 ;
V_104 -> V_108 = V_106 -> V_108 ;
for ( V_107 = 0 ; V_107 < V_104 -> V_109 ; V_107 ++ ) {
int V_110 = V_104 -> V_111 + V_107 ;
T_5 V_112 ;
unsigned V_113 ;
V_112 = V_106 -> V_114 + ( V_106 -> V_108 * V_110 ) ;
V_113 = F_70 ( V_104 -> V_108 , V_115 ) ;
F_71 ( V_104 -> V_25 , V_112 , V_113 ,
V_116 ) ;
F_66 ( V_104 -> V_15 , V_112 , V_113 , 0 ) ;
}
}
static void F_72 ( struct V_103 * V_104 )
{
T_5 V_96 ;
unsigned V_97 ;
void * V_117 ;
int V_107 ;
if ( ! V_104 -> V_15 )
return;
for ( V_107 = 0 ; ; V_107 ++ ) {
V_96 = F_67 ( V_104 -> V_15 , & V_97 ) ;
if ( ! V_96 )
break;
V_117 = F_73 ( V_104 , V_96 ) ;
if ( ! V_117 ) {
F_74 ( V_104 -> V_24 -> V_25 ,
L_11 ) ;
continue;
}
}
F_5 ( V_107 != V_104 -> V_109 ) ;
F_62 ( V_104 -> V_15 ) ;
}
T_5 F_75 ( void * V_118 , void * V_119 )
{
struct V_103 * V_104 = V_118 ;
return V_104 -> V_106 -> V_114 + ( V_119 - V_104 -> V_106 -> V_120 ) ;
}
void * F_73 ( void * V_118 , T_5 V_96 )
{
struct V_103 * V_104 = V_118 ;
return V_104 -> V_106 -> V_120 + ( V_96 - V_104 -> V_106 -> V_114 ) ;
}
void * F_76 ( const char * V_38 ,
int V_109 , int V_121 )
{
struct V_105 * V_122 , * V_106 = NULL ;
struct V_103 * V_104 , * V_123 ;
struct V_124 * V_125 ;
unsigned V_126 ;
bool V_127 ;
int V_19 ;
if ( ! V_24 -> V_25 )
return F_27 ( - V_51 ) ;
V_104 = F_26 ( V_24 -> V_25 , sizeof( * V_104 ) , V_39 ) ;
if ( ! V_104 ) {
F_77 ( V_24 -> V_25 , L_12 ) ;
return F_27 ( - V_40 ) ;
}
F_78 (kdev, reg_itr) {
if ( V_122 -> V_16 != V_121 )
continue;
V_106 = V_122 ;
break;
}
if ( ! V_106 ) {
F_77 ( V_24 -> V_25 , L_13 , V_121 ) ;
V_19 = - V_55 ;
goto V_128;
}
V_104 -> V_15 = F_61 ( V_38 , V_33 , 0 ) ;
if ( F_79 ( V_104 -> V_15 ) ) {
F_77 ( V_24 -> V_25 ,
L_14 ,
V_38 , F_80 ( V_104 -> V_15 ) ) ;
V_19 = F_80 ( V_104 -> V_15 ) ;
goto V_128;
}
V_104 -> V_38 = F_28 ( V_38 , V_46 , V_39 ) ;
V_104 -> V_24 = V_24 ;
V_104 -> V_25 = V_24 -> V_25 ;
F_32 ( & V_50 ) ;
if ( V_109 > ( V_106 -> V_109 - V_106 -> V_129 ) ) {
F_77 ( V_24 -> V_25 , L_15 ,
V_121 , V_38 ) ;
V_19 = - V_40 ;
goto V_130;
}
V_126 = 0 ;
V_127 = false ;
V_125 = & V_106 -> V_131 ;
F_81 (pi, &region->pools, region_inst) {
if ( ( V_123 -> V_111 - V_126 ) >= V_109 ) {
V_127 = true ;
break;
}
V_126 = V_123 -> V_111 + V_123 -> V_109 ;
}
V_125 = & V_123 -> V_132 ;
if ( V_127 ) {
V_104 -> V_106 = V_106 ;
V_104 -> V_109 = V_109 ;
V_104 -> V_111 = V_126 ;
V_106 -> V_129 += V_109 ;
F_82 ( & V_104 -> V_49 , & V_24 -> V_131 ) ;
F_82 ( & V_104 -> V_132 , V_125 ) ;
} else {
F_77 ( V_24 -> V_25 , L_16 ,
V_38 , V_121 ) ;
V_19 = - V_40 ;
goto V_130;
}
F_33 ( & V_50 ) ;
F_69 ( V_104 ) ;
return V_104 ;
V_130:
F_33 ( & V_50 ) ;
V_128:
F_83 ( V_104 -> V_38 ) ;
F_29 ( V_24 -> V_25 , V_104 ) ;
return F_27 ( V_19 ) ;
}
void F_84 ( void * V_118 )
{
struct V_103 * V_104 = V_118 ;
if ( ! V_104 )
return;
if ( ! V_104 -> V_106 )
return;
F_72 ( V_104 ) ;
F_32 ( & V_50 ) ;
V_104 -> V_106 -> V_129 -= V_104 -> V_109 ;
F_85 ( & V_104 -> V_132 ) ;
F_85 ( & V_104 -> V_49 ) ;
F_33 ( & V_50 ) ;
F_83 ( V_104 -> V_38 ) ;
F_29 ( V_24 -> V_25 , V_104 ) ;
}
void * F_86 ( void * V_118 )
{
struct V_103 * V_104 = V_118 ;
T_5 V_96 ;
unsigned V_97 ;
void * V_133 ;
V_96 = F_67 ( V_104 -> V_15 , & V_97 ) ;
if ( F_68 ( ! V_96 ) )
return F_27 ( - V_40 ) ;
V_133 = F_73 ( V_104 , V_96 ) ;
return V_133 ;
}
void F_87 ( void * V_118 , void * V_117 )
{
struct V_103 * V_104 = V_118 ;
T_5 V_96 ;
V_96 = F_75 ( V_104 , V_117 ) ;
F_66 ( V_104 -> V_15 , V_96 , V_104 -> V_106 -> V_108 , 0 ) ;
}
int F_88 ( void * V_118 , void * V_117 , unsigned V_97 ,
T_5 * V_96 , unsigned * V_134 )
{
struct V_103 * V_104 = V_118 ;
* V_96 = F_75 ( V_104 , V_117 ) ;
V_97 = F_89 ( V_97 , V_104 -> V_106 -> V_108 ) ;
V_97 = F_70 ( V_97 , V_115 ) ;
* V_134 = V_97 ;
F_71 ( V_104 -> V_25 , * V_96 , V_97 , V_116 ) ;
F_90 () ;
return 0 ;
}
void * F_91 ( void * V_118 , T_5 V_96 , unsigned V_134 )
{
struct V_103 * V_104 = V_118 ;
unsigned V_135 ;
void * V_117 ;
V_135 = F_89 ( V_134 , V_104 -> V_106 -> V_108 ) ;
V_117 = F_73 ( V_104 , V_96 ) ;
F_92 ( V_104 -> V_25 , V_96 , V_135 , V_136 ) ;
F_93 ( V_117 ) ;
return V_117 ;
}
int F_94 ( void * V_118 )
{
struct V_103 * V_104 = V_118 ;
return F_46 ( V_104 -> V_15 ) ;
}
static void F_95 ( struct V_34 * V_24 ,
struct V_105 * V_106 )
{
unsigned V_137 , V_138 , V_97 ;
struct V_139 T_4 * V_140 ;
struct V_141 * V_41 ;
struct V_103 * V_104 ;
int V_16 = V_106 -> V_16 ;
struct V_142 * V_142 ;
if ( ! V_106 -> V_109 ) {
F_14 ( V_24 -> V_25 , L_17 , V_106 -> V_38 ) ;
return;
}
V_137 = F_96 ( V_106 -> V_109 - 1 ) + 1 ;
if ( V_106 -> V_109 < 32 ) {
V_106 -> V_109 = 0 ;
F_14 ( V_24 -> V_25 , L_18 ,
V_106 -> V_38 ) ;
return;
}
V_97 = V_106 -> V_109 * V_106 -> V_108 ;
V_106 -> V_120 = F_97 ( V_97 , V_39 | V_143 |
V_144 ) ;
if ( ! V_106 -> V_120 ) {
V_106 -> V_109 = 0 ;
F_77 ( V_24 -> V_25 , L_19 ,
V_106 -> V_38 ) ;
return;
}
V_106 -> V_145 = V_106 -> V_120 + V_97 ;
V_142 = F_98 ( V_106 -> V_120 ) ;
V_106 -> V_114 = F_99 ( V_24 -> V_25 , V_142 , 0 , V_97 ,
V_146 ) ;
if ( F_100 ( V_24 -> V_25 , V_106 -> V_114 ) ) {
F_77 ( V_24 -> V_25 , L_20 ,
V_106 -> V_38 ) ;
goto V_147;
}
V_106 -> V_148 = V_106 -> V_114 + V_97 ;
V_104 = F_26 ( V_24 -> V_25 , sizeof( * V_104 ) , V_39 ) ;
if ( ! V_104 ) {
F_77 ( V_24 -> V_25 , L_21 ) ;
goto V_147;
}
V_104 -> V_109 = 0 ;
V_104 -> V_111 = V_106 -> V_109 ;
F_101 ( & V_104 -> V_132 , & V_106 -> V_131 ) ;
F_74 ( V_24 -> V_25 ,
L_22 ,
V_106 -> V_38 , V_16 , V_106 -> V_108 , V_106 -> V_109 ,
V_106 -> V_149 , V_106 -> V_114 , V_106 -> V_148 ,
V_106 -> V_120 , V_106 -> V_145 ) ;
V_138 = ( V_106 -> V_108 / 16 ) - 1 ;
V_137 -= 5 ;
F_102 (kdev, qmgr) {
V_140 = V_41 -> V_150 + V_16 ;
F_60 ( V_106 -> V_114 , & V_140 -> V_151 ) ;
F_60 ( V_106 -> V_149 , & V_140 -> V_152 ) ;
F_60 ( V_138 << 16 | V_137 ,
& V_140 -> V_153 ) ;
}
return;
V_147:
if ( V_106 -> V_114 )
F_103 ( V_24 -> V_25 , V_106 -> V_114 , V_97 ,
V_146 ) ;
if ( V_106 -> V_120 )
F_104 ( V_106 -> V_120 , V_97 ) ;
V_106 -> V_109 = 0 ;
return;
}
static const char * F_105 ( struct V_154 * V_125 )
{
const char * V_38 ;
if ( F_106 ( V_125 , L_23 , & V_38 ) < 0 )
V_38 = V_125 -> V_38 ;
if ( ! V_38 )
V_38 = L_24 ;
return V_38 ;
}
static int F_107 ( struct V_34 * V_24 ,
struct V_154 * V_155 )
{
struct V_156 * V_25 = V_24 -> V_25 ;
struct V_105 * V_106 ;
struct V_154 * V_157 ;
T_3 V_158 [ 2 ] ;
int V_19 ;
F_108 (regions, child) {
V_106 = F_26 ( V_25 , sizeof( * V_106 ) , V_39 ) ;
if ( ! V_106 ) {
F_77 ( V_25 , L_25 ) ;
return - V_40 ;
}
V_106 -> V_38 = F_105 ( V_157 ) ;
F_109 ( V_157 , L_26 , & V_106 -> V_16 ) ;
V_19 = F_110 ( V_157 , L_27 , V_158 , 2 ) ;
if ( ! V_19 ) {
V_106 -> V_109 = V_158 [ 0 ] ;
V_106 -> V_108 = V_158 [ 1 ] ;
} else {
F_77 ( V_25 , L_28 , V_106 -> V_38 ) ;
F_29 ( V_25 , V_106 ) ;
continue;
}
if ( ! F_111 ( V_157 , L_29 , NULL ) ) {
F_77 ( V_25 , L_30 , V_106 -> V_38 ) ;
F_29 ( V_25 , V_106 ) ;
continue;
}
V_19 = F_109 ( V_157 , L_29 ,
& V_106 -> V_149 ) ;
if ( V_19 ) {
F_77 ( V_25 , L_31 ,
V_106 -> V_38 ) ;
F_29 ( V_25 , V_106 ) ;
continue;
}
F_112 ( & V_106 -> V_131 ) ;
F_82 ( & V_106 -> V_49 , & V_24 -> V_155 ) ;
}
if ( F_18 ( & V_24 -> V_155 ) ) {
F_77 ( V_25 , L_32 ) ;
return - V_51 ;
}
F_78 (kdev, region)
F_95 ( V_24 , V_106 ) ;
return 0 ;
}
static int F_113 ( struct V_34 * V_24 ,
const char * V_38 ,
struct V_159 * V_160 )
{
struct V_161 * V_162 = F_114 ( V_24 -> V_25 ) ;
struct V_154 * V_125 = V_162 -> V_25 . V_163 ;
T_3 V_158 [ 2 ] ;
if ( ! F_110 ( V_125 , V_38 , V_158 , 2 ) ) {
if ( V_158 [ 0 ] ) {
V_160 -> V_164 = ( T_5 ) V_158 [ 0 ] ;
V_160 -> V_119 = NULL ;
V_160 -> V_97 = V_158 [ 1 ] ;
} else {
V_160 -> V_97 = V_158 [ 1 ] ;
V_160 -> V_119 = F_115 ( V_24 -> V_25 ,
8 * V_160 -> V_97 , & V_160 -> V_164 ,
V_39 ) ;
if ( ! V_160 -> V_119 ) {
F_77 ( V_24 -> V_25 , L_33 ) ;
return - V_40 ;
}
}
} else {
return - V_51 ;
}
return 0 ;
}
static int F_116 ( struct V_34 * V_24 )
{
struct V_159 * V_160 ;
struct V_141 * V_41 ;
F_102 (kdev, qmgr) {
V_160 = & V_24 -> V_165 [ 0 ] ;
F_74 ( V_24 -> V_25 , L_34 ,
V_160 -> V_164 , V_160 -> V_119 , V_160 -> V_97 ) ;
F_60 ( V_160 -> V_164 , & V_41 -> V_166 -> V_167 ) ;
F_60 ( V_160 -> V_97 , & V_41 -> V_166 -> V_168 ) ;
V_160 ++ ;
if ( ! V_160 -> V_97 )
return 0 ;
F_74 ( V_24 -> V_25 , L_35 ,
V_160 -> V_164 , V_160 -> V_119 , V_160 -> V_97 ) ;
F_60 ( V_160 -> V_164 , & V_41 -> V_166 -> V_169 ) ;
}
return 0 ;
}
static int F_117 ( struct V_34 * V_24 ,
struct V_154 * V_125 )
{
struct V_156 * V_25 = V_24 -> V_25 ;
struct V_13 * V_14 ;
struct V_141 * V_41 ;
T_3 V_158 [ 2 ] , V_170 , V_81 , V_16 , V_110 ;
int V_19 , V_107 ;
V_14 = F_26 ( V_25 , sizeof( * V_14 ) , V_39 ) ;
if ( ! V_14 ) {
F_77 ( V_25 , L_36 ) ;
return - V_40 ;
}
V_14 -> V_24 = V_24 ;
V_14 -> V_38 = F_105 ( V_125 ) ;
V_19 = F_110 ( V_125 , L_37 , V_158 , 2 ) ;
if ( ! V_19 ) {
V_14 -> V_17 = V_158 [ 0 ] - V_24 -> V_36 ;
V_14 -> V_37 = V_158 [ 1 ] ;
} else {
F_77 ( V_25 , L_38 , V_14 -> V_38 ) ;
F_29 ( V_25 , V_14 ) ;
return - V_55 ;
}
for ( V_107 = 0 ; V_107 < V_171 ; V_107 ++ ) {
struct V_172 V_173 ;
if ( F_118 ( V_125 , V_107 , & V_173 ) )
break;
V_14 -> V_22 [ V_107 ] . V_10 = F_119 ( & V_173 ) ;
if ( V_14 -> V_22 [ V_107 ] . V_10 == V_174 )
break;
V_14 -> V_175 ++ ;
if ( V_173 . V_176 == 3 )
V_14 -> V_22 [ V_107 ] . V_18 =
( V_173 . args [ 2 ] & 0x0000ff00 ) >> 8 ;
}
V_14 -> V_175 = F_89 ( V_14 -> V_175 , V_14 -> V_37 ) ;
if ( V_14 -> V_175 )
V_14 -> V_20 |= V_21 ;
if ( F_111 ( V_125 , L_39 , NULL ) )
V_14 -> V_20 |= V_27 ;
if ( F_111 ( V_125 , L_40 , NULL ) ) {
V_19 = F_120 ( V_24 , V_125 , V_14 ) ;
if ( V_19 < 0 ) {
F_29 ( V_25 , V_14 ) ;
return V_19 ;
}
} else {
V_14 -> V_47 = & V_177 ;
}
F_102 (kdev, qmgr) {
V_170 = F_121 ( V_41 -> V_42 , V_14 -> V_17 ) ;
V_81 = F_89 ( V_41 -> V_42 + V_41 -> V_37 ,
V_14 -> V_17 + V_14 -> V_37 ) ;
for ( V_16 = V_170 ; V_16 < V_81 ; V_16 ++ ) {
V_110 = V_16 - V_41 -> V_42 ;
F_60 ( V_178 | 1 ,
& V_41 -> V_45 [ V_110 ] . V_85 ) ;
F_60 ( 0 ,
& V_41 -> V_43 [ V_110 ] . V_85 ) ;
}
}
F_82 ( & V_14 -> V_49 , & V_24 -> V_179 ) ;
F_74 ( V_25 , L_41 ,
V_14 -> V_38 , V_14 -> V_17 ,
V_14 -> V_17 + V_14 -> V_37 - 1 ,
V_14 -> V_175 ,
( V_14 -> V_20 & V_21 ) ? L_42 : L_43 ,
( V_14 -> V_20 & V_27 ) ? L_44 : L_43 ,
( V_14 -> V_20 & V_32 ) ? L_45 : L_43 ) ;
V_24 -> V_180 += V_14 -> V_37 ;
return 0 ;
}
static int F_122 ( struct V_34 * V_24 ,
struct V_154 * V_181 )
{
struct V_154 * type , * V_14 ;
int V_19 ;
F_108 (queue_pools, type) {
F_108 (type, range) {
V_19 = F_117 ( V_24 , V_14 ) ;
}
}
if ( F_18 ( & V_24 -> V_179 ) ) {
F_77 ( V_24 -> V_25 , L_46 ) ;
return - V_51 ;
}
return 0 ;
}
static void F_123 ( struct V_34 * V_24 ,
struct V_13 * V_14 )
{
if ( V_14 -> V_47 && V_14 -> V_47 -> V_182 )
V_14 -> V_47 -> V_182 ( V_14 ) ;
F_85 ( & V_14 -> V_49 ) ;
F_29 ( V_24 -> V_25 , V_14 ) ;
}
static void F_124 ( struct V_34 * V_24 )
{
struct V_13 * V_14 ;
for (; ; ) {
V_14 = F_125 ( V_24 ) ;
if ( ! V_14 )
break;
F_123 ( V_24 , V_14 ) ;
}
}
static void F_126 ( struct V_34 * V_24 )
{
struct V_105 * V_106 ;
struct V_103 * V_104 , * V_28 ;
unsigned V_97 ;
for (; ; ) {
V_106 = F_127 ( V_24 ) ;
if ( ! V_106 )
break;
F_128 (pool, tmp, &region->pools, region_inst)
F_84 ( V_104 ) ;
V_97 = V_106 -> V_145 - V_106 -> V_120 ;
if ( V_97 )
F_104 ( V_106 -> V_120 , V_97 ) ;
F_85 ( & V_106 -> V_49 ) ;
F_29 ( V_24 -> V_25 , V_106 ) ;
}
}
static void T_4 * F_129 ( struct V_34 * V_24 ,
struct V_154 * V_125 , int V_110 )
{
struct V_183 V_184 ;
void T_4 * V_140 ;
int V_19 ;
V_19 = F_130 ( V_125 , V_110 , & V_184 ) ;
if ( V_19 ) {
F_77 ( V_24 -> V_25 , L_47 ,
V_125 -> V_38 , V_110 ) ;
return F_27 ( V_19 ) ;
}
V_140 = F_131 ( V_24 -> V_25 , & V_184 ) ;
if ( F_132 ( V_140 ) )
F_77 ( V_24 -> V_25 , L_48 ,
V_110 , V_125 -> V_38 ) ;
return V_140 ;
}
static int F_133 ( struct V_34 * V_24 ,
struct V_154 * V_185 )
{
struct V_156 * V_25 = V_24 -> V_25 ;
struct V_141 * V_41 ;
struct V_154 * V_157 ;
T_3 V_158 [ 2 ] ;
int V_19 ;
F_108 (qmgrs, child) {
V_41 = F_26 ( V_25 , sizeof( * V_41 ) , V_39 ) ;
if ( ! V_41 ) {
F_77 ( V_25 , L_49 ) ;
return - V_40 ;
}
V_19 = F_110 ( V_157 , L_50 ,
V_158 , 2 ) ;
if ( ! V_19 ) {
V_41 -> V_42 = V_158 [ 0 ] ;
V_41 -> V_37 = V_158 [ 1 ] ;
} else {
F_77 ( V_25 , L_51 ) ;
F_29 ( V_25 , V_41 ) ;
continue;
}
F_134 ( V_25 , L_52 ,
V_41 -> V_42 , V_41 -> V_37 ) ;
V_41 -> V_45 =
F_129 ( V_24 , V_157 ,
V_186 ) ;
V_41 -> V_187 =
F_129 ( V_24 , V_157 ,
V_188 ) ;
V_41 -> V_166 =
F_129 ( V_24 , V_157 ,
V_189 ) ;
V_41 -> V_150 =
F_129 ( V_24 , V_157 ,
V_190 ) ;
V_41 -> V_43 =
F_129 ( V_24 , V_157 ,
V_191 ) ;
V_41 -> V_44 =
F_129 ( V_24 , V_157 ,
V_192 ) ;
if ( F_132 ( V_41 -> V_45 ) || F_132 ( V_41 -> V_187 ) ||
F_132 ( V_41 -> V_166 ) || F_132 ( V_41 -> V_150 ) ||
F_132 ( V_41 -> V_43 ) || F_132 ( V_41 -> V_44 ) ) {
F_77 ( V_25 , L_53 ) ;
if ( ! F_132 ( V_41 -> V_45 ) )
F_135 ( V_25 , V_41 -> V_45 ) ;
if ( ! F_132 ( V_41 -> V_187 ) )
F_135 ( V_25 , V_41 -> V_187 ) ;
if ( ! F_132 ( V_41 -> V_166 ) )
F_135 ( V_25 , V_41 -> V_166 ) ;
if ( ! F_132 ( V_41 -> V_150 ) )
F_135 ( V_25 , V_41 -> V_150 ) ;
if ( ! F_132 ( V_41 -> V_43 ) )
F_135 ( V_25 , V_41 -> V_43 ) ;
if ( ! F_132 ( V_41 -> V_44 ) )
F_135 ( V_25 , V_41 -> V_44 ) ;
F_29 ( V_25 , V_41 ) ;
continue;
}
F_82 ( & V_41 -> V_49 , & V_24 -> V_185 ) ;
F_134 ( V_25 , L_54 ,
V_41 -> V_42 , V_41 -> V_37 ,
V_41 -> V_45 , V_41 -> V_187 ,
V_41 -> V_166 , V_41 -> V_150 ,
V_41 -> V_43 , V_41 -> V_44 ) ;
}
return 0 ;
}
static int F_136 ( struct V_34 * V_24 ,
struct V_154 * V_193 )
{
struct V_156 * V_25 = V_24 -> V_25 ;
struct V_194 * V_195 ;
struct V_154 * V_157 ;
int V_19 ;
F_108 (pdsps, child) {
V_195 = F_26 ( V_25 , sizeof( * V_195 ) , V_39 ) ;
if ( ! V_195 ) {
F_77 ( V_25 , L_55 ) ;
return - V_40 ;
}
V_195 -> V_38 = F_105 ( V_157 ) ;
V_19 = F_106 ( V_157 , L_56 ,
& V_195 -> V_196 ) ;
if ( V_19 < 0 || ! V_195 -> V_196 ) {
F_77 ( V_25 , L_57 ,
V_195 -> V_38 ) ;
F_29 ( V_25 , V_195 ) ;
continue;
}
F_74 ( V_25 , L_58 , V_195 -> V_38 ,
V_195 -> V_196 ) ;
V_195 -> V_197 =
F_129 ( V_24 , V_157 ,
V_198 ) ;
V_195 -> V_140 =
F_129 ( V_24 , V_157 ,
V_199 ) ;
V_195 -> V_200 =
F_129 ( V_24 , V_157 ,
V_201 ) ;
V_195 -> V_202 =
F_129 ( V_24 , V_157 ,
V_203 ) ;
if ( F_132 ( V_195 -> V_202 ) || F_132 ( V_195 -> V_197 ) ||
F_132 ( V_195 -> V_140 ) || F_132 ( V_195 -> V_200 ) ) {
F_77 ( V_25 , L_59 ,
V_195 -> V_38 ) ;
if ( ! F_132 ( V_195 -> V_202 ) )
F_135 ( V_25 , V_195 -> V_202 ) ;
if ( ! F_132 ( V_195 -> V_197 ) )
F_135 ( V_25 , V_195 -> V_197 ) ;
if ( ! F_132 ( V_195 -> V_140 ) )
F_135 ( V_25 , V_195 -> V_140 ) ;
if ( ! F_132 ( V_195 -> V_200 ) )
F_135 ( V_25 , V_195 -> V_200 ) ;
F_29 ( V_25 , V_195 ) ;
continue;
}
F_109 ( V_157 , L_26 , & V_195 -> V_16 ) ;
F_82 ( & V_195 -> V_49 , & V_24 -> V_193 ) ;
F_74 ( V_25 , L_60 ,
V_195 -> V_38 , V_195 -> V_202 , V_195 -> V_197 , V_195 -> V_140 ,
V_195 -> V_200 , V_195 -> V_196 ) ;
}
return 0 ;
}
static int F_137 ( struct V_34 * V_24 ,
struct V_194 * V_195 )
{
T_3 V_82 , V_80 = 1000 ;
int V_19 ;
V_82 = F_47 ( & V_195 -> V_140 -> V_204 ) & ~ V_205 ;
F_60 ( V_82 , & V_195 -> V_140 -> V_204 ) ;
V_19 = F_54 ( & V_195 -> V_140 -> V_204 , V_80 ,
V_206 ) ;
if ( V_19 < 0 ) {
F_77 ( V_24 -> V_25 , L_61 , V_195 -> V_38 ) ;
return V_19 ;
}
return 0 ;
}
static int F_138 ( struct V_34 * V_24 ,
struct V_194 * V_195 )
{
int V_107 , V_19 , V_207 ;
const struct V_196 * V_208 ;
T_3 * V_209 ;
V_19 = F_139 ( & V_208 , V_195 -> V_196 , V_24 -> V_25 ) ;
if ( V_19 ) {
F_77 ( V_24 -> V_25 , L_62 ,
V_195 -> V_196 , V_195 -> V_38 ) ;
return V_19 ;
}
F_60 ( V_195 -> V_16 + 1 , V_195 -> V_202 + 0x18 ) ;
V_209 = ( T_3 * ) V_208 -> V_133 ;
V_207 = ( V_208 -> V_97 + sizeof( T_3 ) - 1 ) / sizeof( T_3 ) ;
for ( V_107 = 0 ; V_107 < V_207 ; V_107 ++ )
F_60 ( F_140 ( V_209 [ V_107 ] ) , V_195 -> V_197 + V_107 ) ;
F_141 ( V_208 ) ;
return 0 ;
}
static int F_142 ( struct V_34 * V_24 ,
struct V_194 * V_195 )
{
T_3 V_82 , V_80 = 1000 ;
int V_19 ;
F_60 ( 0xffffffff , V_195 -> V_202 ) ;
while ( F_47 ( V_195 -> V_202 ) != 0xffffffff )
F_57 () ;
V_82 = F_47 ( & V_195 -> V_140 -> V_204 ) ;
V_82 &= ~ ( V_210 | V_211 ) ;
F_60 ( V_82 , & V_195 -> V_140 -> V_204 ) ;
V_82 = F_47 ( & V_195 -> V_140 -> V_204 ) | V_205 ;
F_60 ( V_82 , & V_195 -> V_140 -> V_204 ) ;
V_19 = F_54 ( V_195 -> V_202 , V_80 , 0 ) ;
if ( V_19 < 0 ) {
F_77 ( V_24 -> V_25 ,
L_63 ,
V_195 -> V_38 ) ;
return V_19 ;
}
return 0 ;
}
static void F_143 ( struct V_34 * V_24 )
{
struct V_194 * V_195 ;
F_144 (kdev, pdsp)
F_137 ( V_24 , V_195 ) ;
}
static int F_145 ( struct V_34 * V_24 )
{
struct V_194 * V_195 ;
int V_19 ;
F_143 ( V_24 ) ;
F_144 (kdev, pdsp) {
V_19 = F_138 ( V_24 , V_195 ) ;
if ( V_19 < 0 )
return V_19 ;
}
F_144 (kdev, pdsp) {
V_19 = F_142 ( V_24 , V_195 ) ;
F_5 ( V_19 ) ;
}
return 0 ;
}
static inline struct V_141 * F_146 ( unsigned V_16 )
{
struct V_141 * V_41 ;
F_102 (kdev, qmgr) {
if ( ( V_16 >= V_41 -> V_42 ) &&
( V_16 < V_41 -> V_42 + V_41 -> V_37 ) )
return V_41 ;
}
return NULL ;
}
static int F_147 ( struct V_34 * V_24 ,
struct V_13 * V_14 ,
struct V_1 * V_2 ,
unsigned V_16 )
{
char V_23 [ V_46 ] ;
V_2 -> V_41 = F_146 ( V_16 ) ;
if ( ! V_2 -> V_41 )
return - 1 ;
F_112 ( & V_2 -> V_26 ) ;
V_2 -> V_24 = V_24 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_212 = - 1 ;
V_2 -> V_16 = V_16 ;
F_148 ( V_23 , sizeof( V_23 ) , L_64 , V_16 ) ;
V_2 -> V_23 = F_28 ( V_23 , sizeof( V_23 ) , V_39 ) ;
if ( V_14 -> V_47 && V_14 -> V_47 -> V_213 )
return V_14 -> V_47 -> V_213 ( V_14 , V_2 ) ;
else
return 0 ;
}
static int F_149 ( struct V_34 * V_24 )
{
struct V_13 * V_14 ;
int V_97 , V_16 , V_214 ;
int V_35 = 0 , V_19 = 0 ;
V_97 = sizeof( struct V_1 ) ;
V_24 -> V_215 = F_150 ( V_97 ) ;
V_97 = ( 1 << V_24 -> V_215 ) * V_24 -> V_180 ;
V_24 -> V_216 = F_26 ( V_24 -> V_25 , V_97 , V_39 ) ;
if ( ! V_24 -> V_216 )
return - V_40 ;
F_151 (kdev, range) {
if ( V_14 -> V_47 && V_14 -> V_47 -> V_217 )
V_14 -> V_47 -> V_217 ( V_14 ) ;
V_214 = V_35 ;
for ( V_16 = V_14 -> V_17 ;
V_16 < V_14 -> V_17 + V_14 -> V_37 ; V_16 ++ , V_35 ++ ) {
V_19 = F_147 ( V_24 , V_14 ,
F_152 ( V_24 , V_35 ) , V_16 ) ;
if ( V_19 < 0 )
return V_19 ;
}
V_14 -> V_218 =
F_152 ( V_24 , V_214 ) ;
}
return 0 ;
}
static int F_153 ( struct V_161 * V_162 )
{
struct V_154 * V_125 = V_162 -> V_25 . V_163 ;
struct V_154 * V_185 , * V_181 , * V_155 , * V_193 ;
struct V_156 * V_25 = & V_162 -> V_25 ;
T_3 V_158 [ 2 ] ;
int V_19 ;
if ( ! V_125 ) {
F_77 ( V_25 , L_65 ) ;
return - V_51 ;
}
V_24 = F_26 ( V_25 , sizeof( struct V_34 ) , V_39 ) ;
if ( ! V_24 ) {
F_77 ( V_25 , L_66 ) ;
return - V_40 ;
}
F_154 ( V_162 , V_24 ) ;
V_24 -> V_25 = V_25 ;
F_112 ( & V_24 -> V_179 ) ;
F_112 ( & V_24 -> V_185 ) ;
F_112 ( & V_24 -> V_131 ) ;
F_112 ( & V_24 -> V_155 ) ;
F_112 ( & V_24 -> V_193 ) ;
F_155 ( & V_162 -> V_25 ) ;
V_19 = F_156 ( & V_162 -> V_25 ) ;
if ( V_19 < 0 ) {
F_77 ( V_25 , L_67 ) ;
return V_19 ;
}
if ( F_110 ( V_125 , L_68 , V_158 , 2 ) ) {
F_77 ( V_25 , L_69 ) ;
V_19 = - V_51 ;
goto V_128;
}
V_24 -> V_36 = V_158 [ 0 ] ;
V_24 -> V_37 = V_158 [ 1 ] ;
V_185 = F_157 ( V_125 , L_70 ) ;
if ( ! V_185 ) {
F_77 ( V_25 , L_71 ) ;
V_19 = - V_51 ;
goto V_128;
}
V_19 = F_133 ( V_24 , V_185 ) ;
F_158 ( V_185 ) ;
if ( V_19 )
goto V_128;
V_193 = F_157 ( V_125 , L_72 ) ;
if ( V_193 ) {
V_19 = F_136 ( V_24 , V_193 ) ;
if ( V_19 )
goto V_128;
V_19 = F_145 ( V_24 ) ;
if ( V_19 )
goto V_128;
}
F_158 ( V_193 ) ;
V_181 = F_157 ( V_125 , L_73 ) ;
if ( ! V_181 ) {
F_77 ( V_25 , L_74 ) ;
V_19 = - V_51 ;
goto V_128;
}
V_19 = F_122 ( V_24 , V_181 ) ;
F_158 ( V_181 ) ;
if ( V_19 )
goto V_128;
V_19 = F_113 ( V_24 , L_75 , & V_24 -> V_165 [ 0 ] ) ;
if ( V_19 ) {
F_77 ( V_24 -> V_25 , L_76 ) ;
goto V_128;
}
V_19 = F_113 ( V_24 , L_77 , & V_24 -> V_165 [ 1 ] ) ;
if ( V_19 ) {
}
V_19 = F_116 ( V_24 ) ;
if ( V_19 )
goto V_128;
V_155 = F_157 ( V_125 , L_78 ) ;
if ( ! V_155 ) {
F_77 ( V_25 , L_79 ) ;
goto V_128;
}
V_19 = F_107 ( V_24 , V_155 ) ;
F_158 ( V_155 ) ;
if ( V_19 )
goto V_128;
V_19 = F_149 ( V_24 ) ;
if ( V_19 < 0 ) {
F_77 ( V_25 , L_80 ) ;
goto V_128;
}
F_159 ( L_81 , V_219 | V_220 , NULL , NULL ,
& V_221 ) ;
return 0 ;
V_128:
F_143 ( V_24 ) ;
F_126 ( V_24 ) ;
F_124 ( V_24 ) ;
F_160 ( & V_162 -> V_25 ) ;
F_161 ( & V_162 -> V_25 ) ;
return V_19 ;
}
static int F_162 ( struct V_161 * V_162 )
{
F_160 ( & V_162 -> V_25 ) ;
F_161 ( & V_162 -> V_25 ) ;
return 0 ;
}
