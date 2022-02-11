static inline int
F_1 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
return ( ( V_3 -> V_4 . V_5 . V_6 ==
V_2 -> V_4 . V_5 . V_6 ) &&
( V_3 -> V_7 == V_2 -> V_7 ) ) ;
}
static inline int
F_2 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
return ( ( V_3 -> V_4 . V_5 . V_8 <=
V_2 -> V_4 . V_5 . V_9 ) &&
( V_3 -> V_4 . V_5 . V_9 >=
V_2 -> V_4 . V_5 . V_8 ) ) ;
}
static inline void F_3 ( struct V_1 * V_10 ,
struct V_1 * V_2 )
{
if ( V_10 -> V_7 == NULL )
return;
F_4 ( F_5 ( & V_10 -> V_11 ) ) ;
V_10 -> V_4 . V_5 . V_12 =
V_2 -> V_4 . V_5 . V_6 ;
V_10 -> V_4 . V_5 . V_13 =
V_2 -> V_7 ;
V_10 -> V_4 . V_5 . V_14 = 0 ;
F_6 ( V_10 -> V_7 -> V_15 ,
& V_10 -> V_4 . V_5 . V_6 ,
& V_10 -> V_11 ) ;
}
static inline void F_7 ( struct V_1 * V_10 )
{
if ( V_10 -> V_7 == NULL )
return;
F_8 ( V_10 -> V_16 ) ;
if ( V_10 -> V_7 -> V_15 != NULL &&
! F_5 ( & V_10 -> V_11 ) )
F_9 ( V_10 -> V_7 -> V_15 ,
& V_10 -> V_4 . V_5 . V_6 ,
& V_10 -> V_11 ) ;
}
static inline void
F_10 ( struct V_1 * V_2 , T_1 V_17 , T_2 V_18 )
{
F_11 ( V_2 , L_1 ,
V_17 , V_18 ) ;
F_4 ( F_5 ( & V_2 -> V_11 ) ) ;
F_12 ( & V_2 -> V_19 ) ;
if ( V_18 == V_20 &&
! ( V_2 -> V_21 & V_22 ) ) {
V_2 -> V_21 |= V_23 | V_24 ;
F_13 ( V_2 , V_17 ) ;
}
F_14 ( V_2 ) ;
}
static int
F_15 ( struct V_1 * V_10 , struct V_1 * V_25 )
{
struct V_26 * V_27 = V_10 -> V_7 ;
struct V_26 * V_28 = V_25 -> V_7 ;
T_2 V_29 = V_10 -> V_4 . V_5 . V_6 ;
T_2 V_30 = V_25 -> V_4 . V_5 . V_6 ;
if ( V_27 == NULL )
return 0 ;
F_16 ( V_28 ) ;
while ( 1 ) {
struct V_26 * V_31 ;
struct V_1 * V_2 = NULL ;
struct V_32 * V_33 ;
if ( V_28 -> V_15 != NULL )
V_2 = F_17 ( V_28 -> V_15 ,
& V_30 ) ;
if ( V_2 == NULL )
break;
F_4 ( V_10 != V_2 ) ;
V_33 = & V_2 -> V_4 . V_5 ;
F_4 ( V_33 -> V_6 == V_30 ) ;
V_30 = V_33 -> V_12 ;
V_31 = F_16 ( V_33 -> V_13 ) ;
F_18 ( V_28 ) ;
F_19 ( V_28 -> V_15 , & V_2 -> V_11 ) ;
V_28 = V_31 ;
if ( V_30 == V_29 && V_28 == V_27 ) {
F_18 ( V_28 ) ;
return 1 ;
}
}
F_18 ( V_28 ) ;
return 0 ;
}
int
F_20 ( struct V_1 * V_10 , T_2 * V_18 , int V_34 ,
T_3 * V_35 , struct V_36 * V_37 )
{
struct V_38 * V_39 = V_10 -> V_16 ;
struct V_40 * V_41 = F_21 ( V_39 ) ;
struct V_36 * V_42 ;
struct V_36 * V_43 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_1 * V_3 = V_10 ;
struct V_1 * V_44 = NULL ;
T_1 V_17 = V_10 -> V_45 ;
int V_46 = F_22 ( V_41 ) ;
int V_47 = ( V_17 == V_48 ) ;
int V_49 = 0 ;
int V_50 = 0 ;
const struct V_51 V_52 = { NULL } ;
F_23 ( V_53 , L_2 V_54 L_3
V_54 L_4 V_54 L_5 , * V_18 ,
V_3 -> V_4 . V_5 . V_6 ,
V_3 -> V_4 . V_5 . V_55 , V_17 ,
V_10 -> V_4 . V_5 . V_8 ,
V_10 -> V_4 . V_5 . V_9 ) ;
* V_35 = V_56 ;
if ( V_46 ) {
V_10 -> V_57 = NULL ;
} else {
V_10 -> V_57 = V_58 ;
}
V_59:
if ( ( * V_18 == V_20 ) || ( V_17 == V_48 ) ) {
F_24 (tmp, &res->lr_granted) {
V_2 = F_25 ( V_42 , struct V_1 ,
V_19 ) ;
if ( F_1 ( V_2 , V_10 ) ) {
V_43 = V_42 ;
break;
}
}
} else {
F_26 ( V_17 ) ;
F_24 (tmp, &res->lr_granted) {
V_2 = F_25 ( V_42 , struct V_1 ,
V_19 ) ;
if ( F_1 ( V_2 , V_10 ) ) {
if ( ! V_43 )
V_43 = V_42 ;
continue;
}
if ( F_27 ( V_2 -> V_60 , V_17 ) )
continue;
if ( ! F_2 ( V_2 , V_10 ) )
continue;
if ( ! V_34 )
return V_61 ;
if ( * V_18 & V_62 ) {
F_10 ( V_10 , V_17 , * V_18 ) ;
* V_35 = - V_63 ;
return V_64 ;
}
if ( * V_18 & V_65 ) {
F_10 ( V_10 , V_17 , * V_18 ) ;
V_10 -> V_45 = V_2 -> V_60 ;
V_10 -> V_4 . V_5 . V_55 =
V_2 -> V_4 . V_5 . V_55 ;
V_10 -> V_4 . V_5 . V_8 =
V_2 -> V_4 . V_5 . V_8 ;
V_10 -> V_4 . V_5 . V_9 =
V_2 -> V_4 . V_5 . V_9 ;
* V_18 |= V_66 ;
return V_64 ;
}
F_3 ( V_10 , V_2 ) ;
if ( F_15 ( V_10 , V_2 ) ) {
F_7 ( V_10 ) ;
F_10 ( V_10 , V_17 , * V_18 ) ;
* V_35 = - V_67 ;
return V_64 ;
}
F_28 ( V_39 , & V_39 -> V_68 , V_10 ) ;
* V_18 |= V_69 ;
return V_64 ;
}
}
if ( * V_18 & V_65 ) {
F_10 ( V_10 , V_17 , * V_18 ) ;
V_10 -> V_45 = V_48 ;
* V_18 |= V_66 ;
return V_64 ;
}
F_7 ( V_10 ) ;
if ( ! V_43 )
V_43 = & V_39 -> V_70 ;
F_29 (ownlocks, tmp, &res->lr_granted) {
V_2 = F_25 ( V_43 , struct V_1 , V_19 ) ;
if ( ! F_1 ( V_2 , V_3 ) )
break;
if ( V_2 -> V_60 == V_17 ) {
if ( ( V_3 -> V_4 . V_5 . V_8 >
( V_2 -> V_4 . V_5 . V_9 + 1 ) )
&& ( V_2 -> V_4 . V_5 . V_9 !=
V_71 ) )
continue;
if ( ( V_3 -> V_4 . V_5 . V_9 <
( V_2 -> V_4 . V_5 . V_8 - 1 ) )
&& ( V_2 -> V_4 . V_5 . V_8 != 0 ) )
break;
if ( V_3 -> V_4 . V_5 . V_8 <
V_2 -> V_4 . V_5 . V_8 ) {
V_2 -> V_4 . V_5 . V_8 =
V_3 -> V_4 . V_5 . V_8 ;
} else {
V_3 -> V_4 . V_5 . V_8 =
V_2 -> V_4 . V_5 . V_8 ;
}
if ( V_3 -> V_4 . V_5 . V_9 >
V_2 -> V_4 . V_5 . V_9 ) {
V_2 -> V_4 . V_5 . V_9 =
V_3 -> V_4 . V_5 . V_9 ;
} else {
V_3 -> V_4 . V_5 . V_9 =
V_2 -> V_4 . V_5 . V_9 ;
}
if ( V_47 ) {
F_10 ( V_2 , V_17 , * V_18 ) ;
} else {
V_3 = V_2 ;
V_47 = 1 ;
}
continue;
}
if ( V_3 -> V_4 . V_5 . V_8 >
V_2 -> V_4 . V_5 . V_9 )
continue;
if ( V_3 -> V_4 . V_5 . V_9 <
V_2 -> V_4 . V_5 . V_8 )
break;
++ V_49 ;
if ( V_3 -> V_4 . V_5 . V_8 <=
V_2 -> V_4 . V_5 . V_8 ) {
if ( V_3 -> V_4 . V_5 . V_9 <
V_2 -> V_4 . V_5 . V_9 ) {
V_2 -> V_4 . V_5 . V_8 =
V_3 -> V_4 . V_5 . V_9 + 1 ;
break;
}
F_10 ( V_2 , V_2 -> V_45 , * V_18 ) ;
continue;
}
if ( V_3 -> V_4 . V_5 . V_9 >=
V_2 -> V_4 . V_5 . V_9 ) {
V_2 -> V_4 . V_5 . V_9 =
V_3 -> V_4 . V_5 . V_8 - 1 ;
continue;
}
if ( ! V_44 ) {
F_30 ( V_10 ) ;
V_44 = F_31 ( V_41 , & V_39 -> V_72 , V_73 ,
V_2 -> V_60 , & V_52 ,
NULL , 0 , V_74 ) ;
F_32 ( V_10 ) ;
if ( ! V_44 ) {
F_10 ( V_10 , V_2 -> V_60 ,
* V_18 ) ;
* V_35 = - V_75 ;
return V_64 ;
}
goto V_59;
}
V_50 = 1 ;
V_44 -> V_60 = V_2 -> V_60 ;
V_44 -> V_4 . V_5 . V_55 =
V_3 -> V_4 . V_5 . V_55 ;
V_44 -> V_4 . V_5 . V_6 =
V_3 -> V_4 . V_5 . V_6 ;
V_44 -> V_4 . V_5 . V_8 =
V_2 -> V_4 . V_5 . V_8 ;
V_44 -> V_4 . V_5 . V_9 =
V_3 -> V_4 . V_5 . V_8 - 1 ;
V_2 -> V_4 . V_5 . V_8 =
V_3 -> V_4 . V_5 . V_9 + 1 ;
V_44 -> V_76 = V_2 -> V_76 ;
if ( V_2 -> V_7 != NULL ) {
V_44 -> V_7 = F_33 ( V_2 -> V_7 , V_44 ) ;
if ( V_44 -> V_7 -> V_77 &&
F_5 ( & V_44 -> V_78 ) )
F_6 ( V_44 -> V_7 -> V_77 ,
& V_44 -> V_79 ,
& V_44 -> V_78 ) ;
}
if ( * V_18 == V_20 )
F_34 ( V_44 ,
V_2 -> V_60 ) ;
F_28 ( V_39 , V_43 , V_44 ) ;
F_35 ( V_44 ) ;
break;
}
if ( V_50 == 0 && V_44 != NULL )
F_14 ( V_44 ) ;
V_10 -> V_60 = V_10 -> V_45 ;
if ( ! V_47 ) {
F_12 ( & V_10 -> V_19 ) ;
F_28 ( V_39 , V_43 , V_10 ) ;
}
if ( * V_18 != V_20 ) {
F_36 ( L_6 ) ;
F_37 () ;
}
if ( V_47 )
F_10 ( V_10 , V_17 , * V_18 ) ;
F_38 ( V_80 , V_39 ) ;
return V_61 ;
}
static void
F_39 ( void * V_81 )
{
struct V_1 * V_2 ;
V_2 = ( (struct V_82 * ) V_81 ) -> V_83 ;
F_32 ( V_2 ) ;
F_7 ( V_2 ) ;
V_2 -> V_21 |= V_24 ;
F_30 ( V_2 ) ;
}
int
F_40 ( struct V_1 * V_2 , T_2 V_18 , void * V_81 )
{
struct V_84 * V_85 = V_2 -> V_86 ;
struct V_87 * V_88 ;
struct V_89 * V_90 = NULL ;
struct V_82 V_91 ;
struct V_92 V_93 ;
T_3 V_35 ;
int V_94 = 0 ;
F_23 ( V_53 , L_7 ,
V_18 , V_81 , V_85 ) ;
if ( ( V_2 -> V_21 & ( V_22 | V_23 ) ) ==
( V_22 | V_23 ) ) {
if ( V_2 -> V_45 == V_2 -> V_60 &&
V_2 -> V_60 != V_48 &&
NULL == V_81 )
F_41 ( V_2 , V_2 -> V_45 ) ;
F_42 ( & V_2 -> V_95 ) ;
return 0 ;
}
F_4 ( V_18 != V_20 ) ;
if ( ! ( V_18 & ( V_96 | V_69 |
V_97 ) ) ) {
if ( NULL == V_81 )
goto V_98;
F_42 ( & V_2 -> V_95 ) ;
return 0 ;
}
F_11 ( V_2 , L_8
L_9 ) ;
V_91 . V_83 = V_2 ;
V_88 = F_43 ( V_2 -> V_76 ) ;
if ( NULL != V_88 )
V_90 = V_88 -> V_99 . V_100 . V_101 ;
if ( NULL != V_90 ) {
F_44 ( & V_90 -> V_102 ) ;
V_91 . V_103 = V_90 -> V_104 ;
F_45 ( & V_90 -> V_102 ) ;
}
V_93 = F_46 ( 0 , NULL , F_39 , & V_91 ) ;
V_94 = F_47 ( V_2 -> V_95 , F_48 ( V_2 ) , & V_93 ) ;
if ( V_94 ) {
F_11 ( V_2 , L_10 ,
V_94 ) ;
return V_94 ;
}
V_98:
F_49 ( V_105 , 10 ) ;
if ( V_2 -> V_21 & V_106 ) {
F_11 ( V_2 , L_11 ) ;
return 0 ;
}
if ( V_2 -> V_21 & V_22 ) {
F_11 ( V_2 , L_12 ) ;
return - V_107 ;
}
if ( V_94 ) {
F_11 ( V_2 , L_10 ,
V_94 ) ;
return V_94 ;
}
F_11 ( V_2 , L_13 ) ;
F_32 ( V_2 ) ;
F_7 ( V_2 ) ;
F_12 ( & V_2 -> V_19 ) ;
if ( V_18 & V_65 ) {
F_10 ( V_2 , V_85 -> V_108 , V_20 ) ;
switch ( V_2 -> V_60 ) {
case V_109 :
V_85 -> V_108 = V_110 ;
break;
case V_111 :
V_85 -> V_108 = V_112 ;
break;
default:
V_85 -> V_108 = V_113 ;
}
V_85 -> V_114 = ( V_115 ) V_2 -> V_4 . V_5 . V_55 ;
V_85 -> V_116 = ( V_117 ) V_2 -> V_4 . V_5 . V_8 ;
V_85 -> V_118 = ( V_117 ) V_2 -> V_4 . V_5 . V_9 ;
} else {
T_2 V_119 = V_20 ;
F_20 ( V_2 , & V_119 , 1 , & V_35 , NULL ) ;
}
F_30 ( V_2 ) ;
return 0 ;
}
int V_58 ( struct V_1 * V_2 , struct V_120 * V_121 ,
void * V_81 , int V_122 )
{
F_4 ( V_2 ) ;
F_4 ( V_122 == V_123 ) ;
F_32 ( V_2 ) ;
F_7 ( V_2 ) ;
F_30 ( V_2 ) ;
return 0 ;
}
void F_50 ( const T_4 * V_124 ,
T_5 * V_125 )
{
memset ( V_125 , 0 , sizeof( * V_125 ) ) ;
V_125 -> V_5 . V_8 = V_124 -> V_5 . V_126 ;
V_125 -> V_5 . V_9 = V_124 -> V_5 . V_127 ;
V_125 -> V_5 . V_55 = V_124 -> V_5 . V_128 ;
V_125 -> V_5 . V_6 = V_124 -> V_5 . V_128 ;
}
void F_51 ( const T_4 * V_124 ,
T_5 * V_125 )
{
memset ( V_125 , 0 , sizeof( * V_125 ) ) ;
V_125 -> V_5 . V_8 = V_124 -> V_5 . V_126 ;
V_125 -> V_5 . V_9 = V_124 -> V_5 . V_127 ;
V_125 -> V_5 . V_55 = V_124 -> V_5 . V_128 ;
V_125 -> V_5 . V_6 = V_124 -> V_5 . V_129 ;
}
void F_52 ( const T_5 * V_125 ,
T_4 * V_124 )
{
memset ( V_124 , 0 , sizeof( * V_124 ) ) ;
V_124 -> V_5 . V_126 = V_125 -> V_5 . V_8 ;
V_124 -> V_5 . V_127 = V_125 -> V_5 . V_9 ;
V_124 -> V_5 . V_128 = V_125 -> V_5 . V_55 ;
V_124 -> V_5 . V_129 = V_125 -> V_5 . V_6 ;
}
static unsigned
F_53 ( struct V_130 * V_131 , const void * V_132 , unsigned V_133 )
{
return F_54 ( * ( T_2 * ) V_132 , V_133 ) ;
}
static void *
F_55 ( struct V_134 * V_135 )
{
struct V_1 * V_2 ;
V_2 = F_56 ( V_135 , struct V_1 , V_11 ) ;
return & V_2 -> V_4 . V_5 . V_6 ;
}
static int
F_57 ( const void * V_132 , struct V_134 * V_135 )
{
return ! memcmp ( F_55 ( V_135 ) , V_132 , sizeof( T_2 ) ) ;
}
static void *
F_58 ( struct V_134 * V_135 )
{
return F_56 ( V_135 , struct V_1 , V_11 ) ;
}
static void
F_59 ( struct V_130 * V_131 , struct V_134 * V_135 )
{
struct V_1 * V_2 ;
struct V_32 * V_33 ;
V_2 = F_56 ( V_135 , struct V_1 , V_11 ) ;
F_60 ( V_2 ) ;
V_33 = & V_2 -> V_4 . V_5 ;
F_4 ( V_33 -> V_13 != NULL ) ;
F_16 ( V_33 -> V_13 ) ;
V_33 -> V_14 ++ ;
}
static void
F_61 ( struct V_130 * V_131 , struct V_134 * V_135 )
{
struct V_1 * V_2 ;
struct V_32 * V_33 ;
V_2 = F_56 ( V_135 , struct V_1 , V_11 ) ;
F_35 ( V_2 ) ;
V_33 = & V_2 -> V_4 . V_5 ;
F_4 ( V_33 -> V_13 != NULL ) ;
F_18 ( V_33 -> V_13 ) ;
if ( -- V_33 -> V_14 == 0 ) {
V_33 -> V_12 = 0 ;
V_33 -> V_13 = NULL ;
}
}
int F_62 ( struct V_26 * exp )
{
if ( strcmp ( exp -> V_136 -> V_137 -> V_138 , V_139 ) != 0 )
return 0 ;
exp -> V_15 =
F_63 ( F_64 ( & exp -> V_140 ) ,
V_141 ,
V_142 ,
V_143 , 0 ,
V_144 , V_145 ,
& V_146 ,
V_147 | V_148 ) ;
if ( ! exp -> V_15 )
return - V_149 ;
return 0 ;
}
void F_65 ( struct V_26 * exp )
{
if ( exp -> V_15 ) {
F_66 ( exp -> V_15 ) ;
exp -> V_15 = NULL ;
}
}
