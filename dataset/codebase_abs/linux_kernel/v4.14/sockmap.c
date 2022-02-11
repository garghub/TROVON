static inline struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return F_2 ( V_3 ) ;
}
static inline void F_3 ( struct V_4 * V_5 )
{
F_4 ( V_5 ) -> V_6 . V_7 = V_5 -> V_8 + F_5 ( V_5 ) ;
}
static int F_6 ( struct V_1 * V_9 , struct V_4 * V_5 )
{
struct V_10 * V_11 = F_7 ( V_9 -> V_12 ) ;
int V_13 ;
if ( F_8 ( ! V_11 ) )
return V_14 ;
F_9 ( V_5 ) ;
F_4 ( V_5 ) -> V_6 . V_15 = NULL ;
V_5 -> V_3 = V_9 -> V_2 ;
F_3 ( V_5 ) ;
F_10 () ;
V_13 = (* V_11 -> V_16 )( V_5 , V_11 -> V_17 ) ;
F_11 () ;
V_5 -> V_3 = NULL ;
return V_13 == V_18 ?
( F_4 ( V_5 ) -> V_6 . V_15 ? V_19 : V_20 ) :
V_14 ;
}
static void F_12 ( struct V_1 * V_9 , struct V_4 * V_5 )
{
struct V_2 * V_3 ;
int V_13 ;
V_13 = F_6 ( V_9 , V_5 ) ;
switch ( V_13 ) {
case V_19 :
V_3 = F_13 ( V_5 ) ;
if ( F_14 ( V_3 ) ) {
struct V_1 * V_21 = F_1 ( V_3 ) ;
if ( F_14 ( V_21 &&
F_15 ( V_22 , & V_21 -> V_23 ) &&
! F_16 ( V_3 , V_24 ) &&
F_17 ( V_3 ) ) ) {
F_18 ( V_5 , V_3 ) ;
F_19 ( & V_21 -> V_25 , V_5 ) ;
F_20 ( & V_21 -> V_26 ) ;
break;
}
}
case V_14 :
default:
F_21 ( V_5 ) ;
}
}
static void F_22 ( struct V_1 * V_9 , int V_27 )
{
struct V_2 * V_3 = V_9 -> V_2 ;
V_3 -> V_28 = V_27 ;
V_3 -> V_29 ( V_3 ) ;
}
static void F_23 ( struct V_2 * V_3 )
{
struct V_30 * V_31 , * V_32 ;
struct V_1 * V_9 ;
struct V_33 * V_34 ;
struct V_2 * V_35 ;
F_24 () ;
switch ( V_3 -> V_36 ) {
case V_37 :
case V_38 :
case V_39 :
break;
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
break;
case V_46 :
V_9 = F_1 ( V_3 ) ;
if ( F_8 ( ! V_9 ) )
break;
F_25 ( & V_3 -> V_47 ) ;
F_26 (e, tmp, &psock->maps, list) {
V_35 = F_27 ( V_31 -> V_48 , V_3 , NULL ) ;
if ( V_35 == V_3 ) {
F_28 ( & V_31 -> V_49 ) ;
F_29 ( V_9 , V_3 ) ;
}
}
F_30 ( & V_3 -> V_47 ) ;
break;
default:
V_9 = F_1 ( V_3 ) ;
if ( F_8 ( ! V_9 ) )
break;
F_22 ( V_9 , V_50 ) ;
break;
}
V_34 = F_31 ( V_3 -> V_51 ) ;
if ( F_32 ( V_34 ) )
F_33 ( & V_34 -> V_52 ) ;
F_34 () ;
}
static void F_35 ( struct V_53 * V_54 ,
struct V_4 * V_5 )
{
struct V_1 * V_9 ;
F_24 () ;
V_9 = F_36 ( V_54 , struct V_1 , V_54 ) ;
F_12 ( V_9 , V_5 ) ;
F_34 () ;
}
static void F_37 ( struct V_2 * V_3 )
{
struct V_1 * V_9 ;
F_24 () ;
V_9 = F_1 ( V_3 ) ;
if ( F_14 ( V_9 ) ) {
F_25 ( & V_3 -> V_47 ) ;
F_38 ( & V_9 -> V_54 ) ;
F_30 ( & V_3 -> V_47 ) ;
}
F_34 () ;
}
static void F_39 ( struct V_55 * V_56 )
{
struct V_1 * V_9 ;
struct V_4 * V_5 ;
int V_57 , V_58 , V_59 ;
V_9 = F_36 ( V_56 , struct V_1 , V_26 ) ;
F_40 ( V_9 -> V_2 ) ;
if ( V_9 -> V_60 ) {
V_5 = V_9 -> V_60 ;
V_57 = V_9 -> V_61 ;
V_58 = V_9 -> V_62 ;
V_9 -> V_60 = NULL ;
goto V_63;
}
while ( ( V_5 = F_41 ( & V_9 -> V_25 ) ) ) {
V_57 = V_5 -> V_64 ;
V_58 = 0 ;
V_63:
do {
if ( F_14 ( V_9 -> V_2 -> V_65 ) )
V_59 = F_42 ( V_9 -> V_2 ,
V_5 , V_58 , V_57 ) ;
else
V_59 = - V_66 ;
if ( V_59 <= 0 ) {
if ( V_59 == - V_67 ) {
V_9 -> V_60 = V_5 ;
V_9 -> V_61 = V_57 ;
V_9 -> V_62 = V_58 ;
goto V_68;
}
F_22 ( V_9 , V_59 ? - V_59 : V_50 ) ;
F_43 ( V_22 , & V_9 -> V_23 ) ;
F_21 ( V_5 ) ;
goto V_68;
}
V_57 -= V_59 ;
V_58 += V_59 ;
} while ( V_57 );
F_21 ( V_5 ) ;
}
V_68:
F_44 ( V_9 -> V_2 ) ;
}
static void F_45 ( struct V_2 * V_3 )
{
struct V_1 * V_9 ;
F_24 () ;
V_9 = F_1 ( V_3 ) ;
if ( F_14 ( V_9 && F_15 ( V_22 , & V_9 -> V_23 ) ) )
F_20 ( & V_9 -> V_26 ) ;
F_34 () ;
}
static void F_46 ( struct V_1 * V_9 , struct V_2 * V_3 )
{
if ( ! V_9 -> V_69 )
return;
V_3 -> V_70 = V_9 -> V_71 ;
V_3 -> V_72 = V_9 -> V_73 ;
V_3 -> V_74 = V_9 -> V_75 ;
V_9 -> V_71 = NULL ;
V_9 -> V_73 = NULL ;
V_9 -> V_75 = NULL ;
F_47 ( & V_9 -> V_54 ) ;
V_9 -> V_69 = false ;
}
static void F_48 ( struct V_76 * V_77 )
{
struct V_1 * V_9 = F_36 ( V_77 ,
struct V_1 , V_77 ) ;
F_20 ( & V_9 -> V_78 ) ;
}
static void F_29 ( struct V_1 * V_9 , struct V_2 * V_2 )
{
V_9 -> V_79 -- ;
if ( V_9 -> V_79 )
return;
F_46 ( V_9 , V_2 ) ;
F_43 ( V_22 , & V_9 -> V_23 ) ;
F_49 ( V_2 , NULL ) ;
F_50 ( & V_9 -> V_77 , F_48 ) ;
}
static int F_51 ( struct V_53 * V_54 ,
struct V_4 * V_5 )
{
struct V_1 * V_9 ;
struct V_10 * V_11 ;
int V_13 ;
F_24 () ;
V_9 = F_36 ( V_54 , struct V_1 , V_54 ) ;
V_11 = F_7 ( V_9 -> V_80 ) ;
if ( F_8 ( ! V_11 ) ) {
F_34 () ;
return V_5 -> V_64 ;
}
V_5 -> V_3 = V_9 -> V_2 ;
F_3 ( V_5 ) ;
V_13 = (* V_11 -> V_16 )( V_5 , V_11 -> V_17 ) ;
V_5 -> V_3 = NULL ;
F_34 () ;
return V_13 ;
}
static int F_52 ( struct V_53 * V_54 , int V_27 )
{
return V_27 ;
}
static int F_53 ( struct V_1 * V_9 ,
struct V_2 * V_3 )
{
static const struct V_81 V_82 = {
. V_83 = F_35 ,
. V_84 = F_51 ,
. V_85 = F_52 ,
} ;
return F_54 ( & V_9 -> V_54 , V_3 , & V_82 ) ;
}
static void F_55 ( struct V_1 * V_9 ,
struct V_86 * V_87 ,
struct V_10 * V_88 ,
struct V_10 * V_89 )
{
struct V_10 * V_90 , * V_91 ;
V_90 = F_56 ( & V_9 -> V_80 , V_89 ) ;
V_91 = F_56 ( & V_9 -> V_12 , V_88 ) ;
if ( V_91 )
F_57 ( V_91 ) ;
if ( V_90 )
F_57 ( V_90 ) ;
}
static void F_58 ( struct V_1 * V_9 , struct V_2 * V_3 )
{
if ( V_3 -> V_70 == F_37 )
return;
V_9 -> V_71 = V_3 -> V_70 ;
V_9 -> V_73 = V_3 -> V_72 ;
V_9 -> V_75 = V_3 -> V_74 ;
V_3 -> V_70 = F_37 ;
V_3 -> V_72 = F_45 ;
V_3 -> V_74 = F_23 ;
V_9 -> V_69 = true ;
}
static void F_59 ( struct V_86 * V_87 )
{
F_60 ( V_87 -> V_92 ) ;
F_61 ( V_87 ) ;
}
static void F_62 ( struct V_55 * V_56 )
{
struct V_30 * V_31 , * V_32 ;
struct V_1 * V_9 ;
V_9 = F_36 ( V_56 , struct V_1 , V_78 ) ;
if ( V_9 -> V_69 )
F_63 ( & V_9 -> V_54 ) ;
F_64 ( & V_9 -> V_26 ) ;
F_65 ( & V_9 -> V_25 ) ;
if ( V_9 -> V_80 )
F_57 ( V_9 -> V_80 ) ;
if ( V_9 -> V_12 )
F_57 ( V_9 -> V_12 ) ;
F_26 (e, tmp, &psock->maps, list) {
F_28 ( & V_31 -> V_49 ) ;
F_61 ( V_31 ) ;
}
F_66 ( V_9 -> V_2 ) ;
F_61 ( V_9 ) ;
}
static struct V_1 * F_67 ( struct V_2 * V_2 ,
struct V_86 * V_87 )
{
struct V_1 * V_9 ;
V_9 = F_68 ( sizeof( struct V_1 ) ,
V_93 | V_94 ,
V_87 -> V_15 . V_95 ) ;
if ( ! V_9 )
return F_69 ( - V_96 ) ;
V_9 -> V_2 = V_2 ;
F_70 ( & V_9 -> V_25 ) ;
F_71 ( & V_9 -> V_26 , F_39 ) ;
F_71 ( & V_9 -> V_78 , F_62 ) ;
F_72 ( & V_9 -> V_97 ) ;
V_9 -> V_79 = 1 ;
F_49 ( V_2 , V_9 ) ;
F_73 ( V_2 ) ;
return V_9 ;
}
static struct V_98 * F_74 ( union V_99 * V_100 )
{
struct V_86 * V_87 ;
int V_27 = - V_66 ;
T_1 V_101 ;
if ( ! F_75 ( V_102 ) )
return F_69 ( - V_103 ) ;
if ( V_100 -> V_104 == 0 || V_100 -> V_105 != 4 ||
V_100 -> V_106 != 4 || V_100 -> V_107 & ~ V_108 )
return F_69 ( - V_66 ) ;
if ( V_100 -> V_106 > V_109 )
return F_69 ( - V_110 ) ;
V_87 = F_76 ( sizeof( * V_87 ) , V_111 ) ;
if ( ! V_87 )
return F_69 ( - V_96 ) ;
V_87 -> V_15 . V_112 = V_100 -> V_112 ;
V_87 -> V_15 . V_105 = V_100 -> V_105 ;
V_87 -> V_15 . V_106 = V_100 -> V_106 ;
V_87 -> V_15 . V_104 = V_100 -> V_104 ;
V_87 -> V_15 . V_107 = V_100 -> V_107 ;
V_87 -> V_15 . V_95 = F_77 ( V_100 ) ;
V_101 = ( T_1 ) V_87 -> V_15 . V_104 * sizeof( struct V_2 * ) ;
if ( V_101 >= V_113 - V_114 )
goto V_115;
V_87 -> V_15 . V_116 = F_78 ( V_101 , V_114 ) >> V_117 ;
V_27 = F_79 ( V_87 -> V_15 . V_116 ) ;
if ( V_27 )
goto V_115;
V_27 = - V_96 ;
V_87 -> V_92 = F_80 ( V_87 -> V_15 . V_104 *
sizeof( struct V_2 * ) ,
V_87 -> V_15 . V_95 ) ;
if ( ! V_87 -> V_92 )
goto V_115;
return & V_87 -> V_15 ;
V_115:
F_61 ( V_87 ) ;
return F_69 ( V_27 ) ;
}
static void F_81 ( struct V_1 * V_9 , struct V_2 * * V_48 )
{
struct V_30 * V_31 , * V_32 ;
F_26 (e, tmp, &psock->maps, list) {
if ( V_31 -> V_48 == V_48 ) {
F_28 ( & V_31 -> V_49 ) ;
break;
}
}
}
static void F_82 ( struct V_98 * V_15 )
{
struct V_86 * V_87 = F_36 ( V_15 , struct V_86 , V_15 ) ;
int V_118 ;
F_83 () ;
F_24 () ;
for ( V_118 = 0 ; V_118 < V_87 -> V_15 . V_104 ; V_118 ++ ) {
struct V_1 * V_9 ;
struct V_2 * V_2 ;
V_2 = F_56 ( & V_87 -> V_92 [ V_118 ] , NULL ) ;
if ( ! V_2 )
continue;
F_25 ( & V_2 -> V_47 ) ;
V_9 = F_1 ( V_2 ) ;
F_81 ( V_9 , & V_87 -> V_92 [ V_118 ] ) ;
F_29 ( V_9 , V_2 ) ;
F_30 ( & V_2 -> V_47 ) ;
}
F_34 () ;
if ( V_87 -> V_12 )
F_57 ( V_87 -> V_12 ) ;
if ( V_87 -> V_80 )
F_57 ( V_87 -> V_80 ) ;
F_59 ( V_87 ) ;
}
static int F_84 ( struct V_98 * V_15 , void * V_119 , void * V_120 )
{
struct V_86 * V_87 = F_36 ( V_15 , struct V_86 , V_15 ) ;
T_2 V_118 = V_119 ? * ( T_2 * ) V_119 : V_113 ;
T_2 * V_121 = ( T_2 * ) V_120 ;
if ( V_118 >= V_87 -> V_15 . V_104 ) {
* V_121 = 0 ;
return 0 ;
}
if ( V_118 == V_87 -> V_15 . V_104 - 1 )
return - V_122 ;
* V_121 = V_118 + 1 ;
return 0 ;
}
struct V_2 * F_85 ( struct V_98 * V_15 , T_2 V_119 )
{
struct V_86 * V_87 = F_36 ( V_15 , struct V_86 , V_15 ) ;
if ( V_119 >= V_15 -> V_104 )
return NULL ;
return F_7 ( V_87 -> V_92 [ V_119 ] ) ;
}
static int F_86 ( struct V_98 * V_15 , void * V_119 )
{
struct V_86 * V_87 = F_36 ( V_15 , struct V_86 , V_15 ) ;
struct V_1 * V_9 ;
int V_123 = * ( T_2 * ) V_119 ;
struct V_2 * V_2 ;
if ( V_123 >= V_15 -> V_104 )
return - V_66 ;
V_2 = F_56 ( & V_87 -> V_92 [ V_123 ] , NULL ) ;
if ( ! V_2 )
return - V_66 ;
F_25 ( & V_2 -> V_47 ) ;
V_9 = F_1 ( V_2 ) ;
if ( ! V_9 )
goto V_68;
if ( V_9 -> V_80 )
F_46 ( V_9 , V_2 ) ;
F_81 ( V_9 , & V_87 -> V_92 [ V_123 ] ) ;
F_29 ( V_9 , V_2 ) ;
V_68:
F_30 ( & V_2 -> V_47 ) ;
return 0 ;
}
static int F_87 ( struct V_124 * V_125 ,
struct V_98 * V_15 ,
void * V_119 , T_1 V_126 )
{
struct V_86 * V_87 = F_36 ( V_15 , struct V_86 , V_15 ) ;
struct V_30 * V_31 = NULL ;
struct V_10 * V_88 , * V_89 ;
struct V_2 * V_127 , * V_2 ;
struct V_1 * V_9 ;
T_2 V_118 = * ( T_2 * ) V_119 ;
int V_27 ;
if ( F_8 ( V_126 > V_128 ) )
return - V_66 ;
if ( F_8 ( V_118 >= V_87 -> V_15 . V_104 ) )
return - V_110 ;
V_2 = F_7 ( V_87 -> V_92 [ V_118 ] ) ;
if ( V_126 == V_128 && ! V_2 )
return - V_122 ;
else if ( V_126 == V_129 && V_2 )
return - V_130 ;
V_2 = V_125 -> V_3 ;
V_88 = F_7 ( V_87 -> V_12 ) ;
V_89 = F_7 ( V_87 -> V_80 ) ;
if ( V_89 && V_88 ) {
V_88 = F_88 ( V_87 -> V_12 ) ;
if ( F_89 ( V_88 ) )
return F_90 ( V_88 ) ;
V_89 = F_88 ( V_87 -> V_80 ) ;
if ( F_89 ( V_89 ) ) {
F_57 ( V_88 ) ;
return F_90 ( V_89 ) ;
}
}
F_25 ( & V_2 -> V_47 ) ;
V_9 = F_1 ( V_2 ) ;
if ( V_9 ) {
if ( F_7 ( V_9 -> V_80 ) && V_89 ) {
V_27 = - V_131 ;
goto V_132;
}
V_9 -> V_79 ++ ;
} else {
V_9 = F_67 ( V_2 , V_87 ) ;
if ( F_89 ( V_9 ) ) {
V_27 = F_90 ( V_9 ) ;
goto V_132;
}
F_91 ( V_22 , & V_9 -> V_23 ) ;
}
V_31 = F_76 ( sizeof( * V_31 ) , V_93 | V_94 ) ;
if ( ! V_31 ) {
V_27 = - V_96 ;
goto V_132;
}
V_31 -> V_48 = & V_87 -> V_92 [ V_118 ] ;
if ( V_89 && V_88 && ! V_9 -> V_69 ) {
V_27 = F_53 ( V_9 , V_2 ) ;
if ( V_27 )
goto V_133;
F_55 ( V_9 , V_87 , V_88 , V_89 ) ;
F_58 ( V_9 , V_2 ) ;
}
F_92 ( & V_31 -> V_49 , & V_9 -> V_97 ) ;
F_30 ( & V_2 -> V_47 ) ;
V_127 = F_56 ( & V_87 -> V_92 [ V_118 ] , V_2 ) ;
if ( V_127 ) {
struct V_1 * V_134 = F_1 ( V_127 ) ;
F_25 ( & V_127 -> V_47 ) ;
if ( V_127 != V_2 && V_89 )
F_46 ( V_134 , V_127 ) ;
F_81 ( V_134 , & V_87 -> V_92 [ V_118 ] ) ;
F_29 ( V_134 , V_127 ) ;
F_30 ( & V_127 -> V_47 ) ;
}
return 0 ;
V_133:
F_29 ( V_9 , V_2 ) ;
V_132:
if ( V_88 )
F_57 ( V_88 ) ;
if ( V_89 )
F_57 ( V_89 ) ;
F_30 ( & V_2 -> V_47 ) ;
F_61 ( V_31 ) ;
return V_27 ;
}
int F_93 ( struct V_98 * V_15 , struct V_10 * V_11 , T_2 type )
{
struct V_86 * V_87 = F_36 ( V_15 , struct V_86 , V_15 ) ;
struct V_10 * V_135 ;
if ( F_8 ( V_15 -> V_112 != V_136 ) )
return - V_66 ;
switch ( type ) {
case V_137 :
V_135 = F_56 ( & V_87 -> V_80 , V_11 ) ;
break;
case V_138 :
V_135 = F_56 ( & V_87 -> V_12 , V_11 ) ;
break;
default:
return - V_139 ;
}
if ( V_135 )
F_57 ( V_135 ) ;
return 0 ;
}
static void * F_94 ( struct V_98 * V_15 , void * V_119 )
{
return NULL ;
}
static int F_95 ( struct V_98 * V_15 ,
void * V_119 , void * V_140 , T_1 V_126 )
{
struct V_124 V_125 ;
T_2 V_141 = * ( T_2 * ) V_140 ;
struct V_142 * V_142 ;
int V_27 ;
V_142 = F_96 ( V_141 , & V_27 ) ;
if ( ! V_142 )
return V_27 ;
V_125 . V_3 = V_142 -> V_3 ;
if ( ! V_125 . V_3 ) {
F_97 ( V_142 -> V_143 ) ;
return - V_66 ;
}
if ( V_125 . V_3 -> V_144 != V_145 ||
V_125 . V_3 -> V_146 != V_147 ) {
F_97 ( V_142 -> V_143 ) ;
return - V_139 ;
}
V_27 = F_87 ( & V_125 , V_15 , V_119 , V_126 ) ;
F_97 ( V_142 -> V_143 ) ;
return V_27 ;
}
