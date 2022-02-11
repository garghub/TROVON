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
static void F_20 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
F_21 ( V_36 , L_2 , V_2 ) ;
if ( ( F_22 ( V_2 -> V_7 ) &
V_37 ) == 0 ) {
F_23 (
L_3 ) ;
} else {
F_4 ( V_2 -> V_38 ) ;
F_4 ( ( V_2 -> V_21 & V_39 ) == 0 ) ;
V_2 -> V_21 |= V_39 | V_40 |
V_41 ;
F_7 ( V_2 ) ;
F_24 ( V_2 ) ;
F_25 ( V_2 , NULL , V_35 ) ;
}
}
int
F_26 ( struct V_1 * V_10 , T_2 * V_18 , int V_42 ,
T_3 * V_43 , struct V_34 * V_35 )
{
struct V_44 * V_45 = V_10 -> V_16 ;
struct V_46 * V_47 = F_27 ( V_45 ) ;
struct V_34 * V_48 ;
struct V_34 * V_49 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_1 * V_3 = V_10 ;
struct V_1 * V_50 = NULL ;
T_1 V_17 = V_10 -> V_51 ;
int V_52 = F_28 ( V_47 ) ;
int V_53 = ( V_17 == V_54 ) ;
int V_55 = 0 ;
int V_56 = 0 ;
const struct V_57 V_58 = { NULL } ;
F_21 ( V_59 , L_4 ,
* V_18 , V_3 -> V_4 . V_5 . V_6 ,
V_3 -> V_4 . V_5 . V_60 , V_17 ,
V_10 -> V_4 . V_5 . V_8 ,
V_10 -> V_4 . V_5 . V_9 ) ;
* V_43 = V_61 ;
if ( V_52 ) {
V_10 -> V_62 = NULL ;
} else {
V_10 -> V_62 = V_63 ;
}
V_64:
if ( ( * V_18 == V_20 ) || ( V_17 == V_54 ) ) {
F_29 (tmp, &res->lr_granted) {
V_2 = F_30 ( V_48 , struct V_1 ,
V_19 ) ;
if ( F_1 ( V_2 , V_10 ) ) {
V_49 = V_48 ;
break;
}
}
} else {
int V_65 = 0 ;
F_31 ( V_17 ) ;
F_29 (tmp, &res->lr_granted) {
V_2 = F_30 ( V_48 , struct V_1 ,
V_19 ) ;
if ( F_1 ( V_2 , V_10 ) ) {
if ( ! V_49 )
V_49 = V_48 ;
continue;
}
if ( F_32 ( V_2 -> V_66 , V_17 ) )
continue;
if ( ! F_2 ( V_2 , V_10 ) )
continue;
if ( ! V_42 ) {
V_65 = 1 ;
if ( F_15 ( V_10 , V_2 ) ) {
F_20 ( V_10 ,
V_35 ) ;
return V_67 ;
}
continue;
}
if ( * V_18 & V_68 ) {
F_10 ( V_10 , V_17 , * V_18 ) ;
* V_43 = - V_69 ;
return V_70 ;
}
if ( * V_18 & V_71 ) {
F_10 ( V_10 , V_17 , * V_18 ) ;
V_10 -> V_51 = V_2 -> V_66 ;
V_10 -> V_4 . V_5 . V_60 =
V_2 -> V_4 . V_5 . V_60 ;
V_10 -> V_4 . V_5 . V_8 =
V_2 -> V_4 . V_5 . V_8 ;
V_10 -> V_4 . V_5 . V_9 =
V_2 -> V_4 . V_5 . V_9 ;
* V_18 |= V_72 ;
return V_70 ;
}
F_3 ( V_10 , V_2 ) ;
if ( F_15 ( V_10 , V_2 ) ) {
F_7 ( V_10 ) ;
F_10 ( V_10 , V_17 , * V_18 ) ;
* V_43 = - V_73 ;
return V_70 ;
}
F_33 ( V_45 , & V_45 -> V_74 , V_10 ) ;
* V_18 |= V_75 ;
return V_70 ;
}
if ( V_65 )
return V_67 ;
}
if ( * V_18 & V_71 ) {
F_10 ( V_10 , V_17 , * V_18 ) ;
V_10 -> V_51 = V_54 ;
* V_18 |= V_72 ;
return V_70 ;
}
F_7 ( V_10 ) ;
if ( ! V_49 )
V_49 = & V_45 -> V_76 ;
F_34 (ownlocks, tmp, &res->lr_granted) {
V_2 = F_30 ( V_49 , struct V_1 , V_19 ) ;
if ( ! F_1 ( V_2 , V_3 ) )
break;
if ( V_2 -> V_66 == V_17 ) {
if ( ( V_3 -> V_4 . V_5 . V_8 >
( V_2 -> V_4 . V_5 . V_9 + 1 ) )
&& ( V_2 -> V_4 . V_5 . V_9 !=
V_77 ) )
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
if ( V_53 ) {
F_10 ( V_2 , V_17 , * V_18 ) ;
} else {
V_3 = V_2 ;
V_53 = 1 ;
}
continue;
}
if ( V_3 -> V_4 . V_5 . V_8 >
V_2 -> V_4 . V_5 . V_9 )
continue;
if ( V_3 -> V_4 . V_5 . V_9 <
V_2 -> V_4 . V_5 . V_8 )
break;
++ V_55 ;
if ( V_3 -> V_4 . V_5 . V_8 <=
V_2 -> V_4 . V_5 . V_8 ) {
if ( V_3 -> V_4 . V_5 . V_9 <
V_2 -> V_4 . V_5 . V_9 ) {
V_2 -> V_4 . V_5 . V_8 =
V_3 -> V_4 . V_5 . V_9 + 1 ;
break;
}
F_10 ( V_2 , V_2 -> V_51 , * V_18 ) ;
continue;
}
if ( V_3 -> V_4 . V_5 . V_9 >=
V_2 -> V_4 . V_5 . V_9 ) {
V_2 -> V_4 . V_5 . V_9 =
V_3 -> V_4 . V_5 . V_8 - 1 ;
continue;
}
if ( ! V_50 ) {
F_35 ( V_10 ) ;
V_50 = F_36 ( V_47 , & V_45 -> V_78 , V_79 ,
V_2 -> V_66 , & V_58 ,
NULL , 0 , V_80 ) ;
F_37 ( V_10 ) ;
if ( ! V_50 ) {
F_10 ( V_10 , V_2 -> V_66 ,
* V_18 ) ;
* V_43 = - V_81 ;
return V_70 ;
}
goto V_64;
}
V_56 = 1 ;
V_50 -> V_66 = V_2 -> V_66 ;
V_50 -> V_4 . V_5 . V_60 =
V_3 -> V_4 . V_5 . V_60 ;
V_50 -> V_4 . V_5 . V_6 =
V_3 -> V_4 . V_5 . V_6 ;
V_50 -> V_4 . V_5 . V_8 =
V_2 -> V_4 . V_5 . V_8 ;
V_50 -> V_4 . V_5 . V_9 =
V_3 -> V_4 . V_5 . V_8 - 1 ;
V_2 -> V_4 . V_5 . V_8 =
V_3 -> V_4 . V_5 . V_9 + 1 ;
V_50 -> V_82 = V_2 -> V_82 ;
if ( V_2 -> V_7 != NULL ) {
V_50 -> V_7 = F_38 ( V_2 -> V_7 , V_50 ) ;
if ( V_50 -> V_7 -> V_83 &&
F_5 ( & V_50 -> V_84 ) )
F_6 ( V_50 -> V_7 -> V_83 ,
& V_50 -> V_85 ,
& V_50 -> V_84 ) ;
}
if ( * V_18 == V_20 )
F_39 ( V_50 ,
V_2 -> V_66 ) ;
F_33 ( V_45 , V_49 , V_50 ) ;
F_40 ( V_50 ) ;
break;
}
if ( V_56 == 0 && V_50 != NULL )
F_14 ( V_50 ) ;
V_10 -> V_66 = V_10 -> V_51 ;
if ( ! V_53 ) {
F_12 ( & V_10 -> V_19 ) ;
F_33 ( V_45 , V_49 , V_10 ) ;
}
if ( * V_18 != V_20 ) {
F_23 ( L_5 ) ;
F_41 () ;
}
if ( V_53 )
F_10 ( V_10 , V_17 , * V_18 ) ;
F_42 ( V_36 , V_45 ) ;
return V_67 ;
}
static void
F_43 ( void * V_86 )
{
struct V_1 * V_2 ;
V_2 = ( (struct V_87 * ) V_86 ) -> V_88 ;
F_37 ( V_2 ) ;
F_7 ( V_2 ) ;
V_2 -> V_21 |= V_24 ;
F_35 ( V_2 ) ;
}
int
F_44 ( struct V_1 * V_2 , T_2 V_18 , void * V_86 )
{
struct V_89 * V_90 = V_2 -> V_91 ;
struct V_92 * V_93 ;
struct V_94 * V_95 = NULL ;
struct V_87 V_96 ;
struct V_97 V_98 ;
T_3 V_43 ;
int V_99 = 0 ;
F_21 ( V_59 , L_6 ,
V_18 , V_86 , V_90 ) ;
if ( ( V_2 -> V_21 & ( V_22 | V_23 ) ) ==
( V_22 | V_23 ) ) {
if ( V_2 -> V_51 == V_2 -> V_66 &&
V_2 -> V_66 != V_54 &&
NULL == V_86 )
F_45 ( V_2 , V_2 -> V_51 ) ;
F_46 ( & V_2 -> V_100 ) ;
return 0 ;
}
F_4 ( V_18 != V_20 ) ;
if ( ! ( V_18 & ( V_101 | V_75 |
V_102 ) ) ) {
if ( NULL == V_86 )
goto V_103;
F_46 ( & V_2 -> V_100 ) ;
return 0 ;
}
F_11 ( V_2 , L_7
L_8 ) ;
V_96 . V_88 = V_2 ;
V_93 = F_47 ( V_2 -> V_82 ) ;
if ( NULL != V_93 )
V_95 = V_93 -> V_104 . V_105 . V_106 ;
if ( NULL != V_95 ) {
F_48 ( & V_95 -> V_107 ) ;
V_96 . V_108 = V_95 -> V_109 ;
F_49 ( & V_95 -> V_107 ) ;
}
V_98 = F_50 ( 0 , NULL , F_43 , & V_96 ) ;
V_99 = F_51 ( V_2 -> V_100 , F_52 ( V_2 ) , & V_98 ) ;
if ( V_99 ) {
F_11 ( V_2 , L_9 ,
V_99 ) ;
return V_99 ;
}
V_103:
F_53 ( V_110 , 10 ) ;
if ( V_2 -> V_21 & V_111 ) {
F_11 ( V_2 , L_10 ) ;
return 0 ;
}
if ( V_2 -> V_21 & V_22 ) {
F_11 ( V_2 , L_11 ) ;
return - V_112 ;
}
if ( V_99 ) {
F_11 ( V_2 , L_9 ,
V_99 ) ;
return V_99 ;
}
F_11 ( V_2 , L_12 ) ;
F_37 ( V_2 ) ;
F_7 ( V_2 ) ;
F_12 ( & V_2 -> V_19 ) ;
if ( V_2 -> V_21 & V_41 ) {
F_11 ( V_2 , L_13 ) ;
V_99 = - V_73 ;
} else if ( V_18 & V_71 ) {
F_10 ( V_2 , V_90 -> V_113 , V_20 ) ;
switch ( V_2 -> V_66 ) {
case V_114 :
V_90 -> V_113 = V_115 ;
break;
case V_116 :
V_90 -> V_113 = V_117 ;
break;
default:
V_90 -> V_113 = V_118 ;
}
V_90 -> V_119 = ( V_120 ) V_2 -> V_4 . V_5 . V_60 ;
V_90 -> V_121 = ( V_122 ) V_2 -> V_4 . V_5 . V_8 ;
V_90 -> V_123 = ( V_122 ) V_2 -> V_4 . V_5 . V_9 ;
} else {
T_2 V_124 = V_20 ;
F_26 ( V_2 , & V_124 , 1 , & V_43 , NULL ) ;
}
F_35 ( V_2 ) ;
return V_99 ;
}
int V_63 ( struct V_1 * V_2 , struct V_125 * V_126 ,
void * V_86 , int V_127 )
{
F_4 ( V_2 ) ;
F_4 ( V_127 == V_128 ) ;
F_37 ( V_2 ) ;
F_7 ( V_2 ) ;
F_35 ( V_2 ) ;
return 0 ;
}
void F_54 ( const T_4 * V_129 ,
T_5 * V_130 )
{
memset ( V_130 , 0 , sizeof( * V_130 ) ) ;
V_130 -> V_5 . V_8 = V_129 -> V_5 . V_131 ;
V_130 -> V_5 . V_9 = V_129 -> V_5 . V_132 ;
V_130 -> V_5 . V_60 = V_129 -> V_5 . V_133 ;
V_130 -> V_5 . V_6 = V_129 -> V_5 . V_133 ;
}
void F_55 ( const T_4 * V_129 ,
T_5 * V_130 )
{
memset ( V_130 , 0 , sizeof( * V_130 ) ) ;
V_130 -> V_5 . V_8 = V_129 -> V_5 . V_131 ;
V_130 -> V_5 . V_9 = V_129 -> V_5 . V_132 ;
V_130 -> V_5 . V_60 = V_129 -> V_5 . V_133 ;
V_130 -> V_5 . V_6 = V_129 -> V_5 . V_134 ;
}
void F_56 ( const T_5 * V_130 ,
T_4 * V_129 )
{
memset ( V_129 , 0 , sizeof( * V_129 ) ) ;
V_129 -> V_5 . V_131 = V_130 -> V_5 . V_8 ;
V_129 -> V_5 . V_132 = V_130 -> V_5 . V_9 ;
V_129 -> V_5 . V_133 = V_130 -> V_5 . V_60 ;
V_129 -> V_5 . V_134 = V_130 -> V_5 . V_6 ;
}
static unsigned
F_57 ( struct V_135 * V_136 , const void * V_137 , unsigned V_138 )
{
return F_58 ( * ( T_2 * ) V_137 , V_138 ) ;
}
static void *
F_59 ( struct V_139 * V_140 )
{
struct V_1 * V_2 ;
V_2 = F_60 ( V_140 , struct V_1 , V_11 ) ;
return & V_2 -> V_4 . V_5 . V_6 ;
}
static int
F_61 ( const void * V_137 , struct V_139 * V_140 )
{
return ! memcmp ( F_59 ( V_140 ) , V_137 , sizeof( T_2 ) ) ;
}
static void *
F_62 ( struct V_139 * V_140 )
{
return F_60 ( V_140 , struct V_1 , V_11 ) ;
}
static void
F_63 ( struct V_135 * V_136 , struct V_139 * V_140 )
{
struct V_1 * V_2 ;
struct V_32 * V_33 ;
V_2 = F_60 ( V_140 , struct V_1 , V_11 ) ;
F_64 ( V_2 ) ;
V_33 = & V_2 -> V_4 . V_5 ;
F_4 ( V_33 -> V_13 != NULL ) ;
F_16 ( V_33 -> V_13 ) ;
V_33 -> V_14 ++ ;
}
static void
F_65 ( struct V_135 * V_136 , struct V_139 * V_140 )
{
struct V_1 * V_2 ;
struct V_32 * V_33 ;
V_2 = F_60 ( V_140 , struct V_1 , V_11 ) ;
F_40 ( V_2 ) ;
V_33 = & V_2 -> V_4 . V_5 ;
F_4 ( V_33 -> V_13 != NULL ) ;
F_18 ( V_33 -> V_13 ) ;
if ( -- V_33 -> V_14 == 0 ) {
V_33 -> V_12 = 0 ;
V_33 -> V_13 = NULL ;
}
}
int F_66 ( struct V_26 * exp )
{
if ( strcmp ( exp -> V_141 -> V_142 -> V_143 , V_144 ) != 0 )
return 0 ;
exp -> V_15 =
F_67 ( F_68 ( & exp -> V_145 ) ,
V_146 ,
V_147 ,
V_148 , 0 ,
V_149 , V_150 ,
& V_151 ,
V_152 | V_153 ) ;
if ( ! exp -> V_15 )
return - V_154 ;
return 0 ;
}
void F_69 ( struct V_26 * exp )
{
if ( exp -> V_15 ) {
F_70 ( exp -> V_15 ) ;
exp -> V_15 = NULL ;
}
}
