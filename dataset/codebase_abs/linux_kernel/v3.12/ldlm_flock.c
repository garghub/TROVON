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
static inline int F_3 ( struct V_1 * V_10 ,
struct V_1 * V_2 )
{
int V_11 = 0 ;
if ( V_10 -> V_7 == NULL )
return 0 ;
if ( F_4 ( V_10 -> V_7 -> V_12 == NULL ) ) {
V_11 = F_5 ( V_10 -> V_7 ) ;
if ( V_11 )
goto error;
}
F_6 ( F_7 ( & V_10 -> V_13 ) ) ;
V_10 -> V_4 . V_5 . V_14 =
V_2 -> V_4 . V_5 . V_6 ;
V_10 -> V_4 . V_5 . V_15 =
V_2 -> V_7 ;
V_10 -> V_4 . V_5 . V_16 = 0 ;
F_8 ( V_10 -> V_7 -> V_12 ,
& V_10 -> V_4 . V_5 . V_6 ,
& V_10 -> V_13 ) ;
error:
return V_11 ;
}
static inline void F_9 ( struct V_1 * V_10 )
{
if ( V_10 -> V_7 == NULL )
return;
F_10 ( V_10 -> V_17 ) ;
if ( V_10 -> V_7 -> V_12 != NULL &&
! F_7 ( & V_10 -> V_13 ) )
F_11 ( V_10 -> V_7 -> V_12 ,
& V_10 -> V_4 . V_5 . V_6 ,
& V_10 -> V_13 ) ;
}
static inline void
F_12 ( struct V_1 * V_2 , T_1 V_18 , T_2 V_19 )
{
F_13 ( V_2 , L_1 ,
V_18 , V_19 ) ;
F_6 ( F_7 ( & V_2 -> V_13 ) ) ;
F_14 ( & V_2 -> V_20 ) ;
if ( V_19 == V_21 &&
! ( V_2 -> V_22 & V_23 ) ) {
V_2 -> V_22 |= V_24 | V_25 ;
F_15 ( V_2 , V_18 ) ;
}
F_16 ( V_2 ) ;
}
static int
F_17 ( struct V_1 * V_10 , struct V_1 * V_26 )
{
struct V_27 * V_28 = V_10 -> V_7 ;
struct V_27 * V_29 = V_26 -> V_7 ;
T_2 V_30 = V_10 -> V_4 . V_5 . V_6 ;
T_2 V_31 = V_26 -> V_4 . V_5 . V_6 ;
if ( V_28 == NULL )
return 0 ;
F_18 ( V_29 ) ;
while ( 1 ) {
struct V_27 * V_32 ;
struct V_1 * V_2 = NULL ;
struct V_33 * V_34 ;
if ( V_29 -> V_12 != NULL )
V_2 = F_19 ( V_29 -> V_12 ,
& V_31 ) ;
if ( V_2 == NULL )
break;
F_6 ( V_10 != V_2 ) ;
V_34 = & V_2 -> V_4 . V_5 ;
F_6 ( V_34 -> V_6 == V_31 ) ;
V_31 = V_34 -> V_14 ;
V_32 = F_18 ( V_34 -> V_15 ) ;
F_20 ( V_29 ) ;
F_21 ( V_29 -> V_12 , & V_2 -> V_13 ) ;
V_29 = V_32 ;
if ( V_31 == V_30 && V_29 == V_28 ) {
F_20 ( V_29 ) ;
return 1 ;
}
}
F_20 ( V_29 ) ;
return 0 ;
}
int
F_22 ( struct V_1 * V_10 , T_2 * V_19 , int V_35 ,
T_3 * V_36 , struct V_37 * V_38 )
{
struct V_39 * V_40 = V_10 -> V_17 ;
struct V_41 * V_42 = F_23 ( V_40 ) ;
struct V_37 * V_43 ;
struct V_37 * V_44 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_1 * V_3 = V_10 ;
struct V_1 * V_45 = NULL ;
T_1 V_18 = V_10 -> V_46 ;
int V_47 = F_24 ( V_42 ) ;
int V_48 = ( V_18 == V_49 ) ;
int V_50 = 0 ;
int V_51 = 0 ;
const struct V_52 V_53 = { NULL } ;
int V_11 ;
F_25 ( V_54 , L_2 V_55 L_3
V_55 L_4 V_55 L_5 , * V_19 ,
V_3 -> V_4 . V_5 . V_6 ,
V_3 -> V_4 . V_5 . V_56 , V_18 ,
V_10 -> V_4 . V_5 . V_8 ,
V_10 -> V_4 . V_5 . V_9 ) ;
* V_36 = V_57 ;
if ( V_47 ) {
V_10 -> V_58 = NULL ;
} else {
V_10 -> V_58 = V_59 ;
}
V_60:
if ( ( * V_19 == V_21 ) || ( V_18 == V_49 ) ) {
F_26 (tmp, &res->lr_granted) {
V_2 = F_27 ( V_43 , struct V_1 ,
V_20 ) ;
if ( F_1 ( V_2 , V_10 ) ) {
V_44 = V_43 ;
break;
}
}
} else {
F_28 ( V_18 ) ;
F_26 (tmp, &res->lr_granted) {
V_2 = F_27 ( V_43 , struct V_1 ,
V_20 ) ;
if ( F_1 ( V_2 , V_10 ) ) {
if ( ! V_44 )
V_44 = V_43 ;
continue;
}
if ( F_29 ( V_2 -> V_61 , V_18 ) )
continue;
if ( ! F_2 ( V_2 , V_10 ) )
continue;
if ( ! V_35 )
return V_62 ;
if ( * V_19 & V_63 ) {
F_12 ( V_10 , V_18 , * V_19 ) ;
* V_36 = - V_64 ;
return V_65 ;
}
if ( * V_19 & V_66 ) {
F_12 ( V_10 , V_18 , * V_19 ) ;
V_10 -> V_46 = V_2 -> V_61 ;
V_10 -> V_4 . V_5 . V_56 =
V_2 -> V_4 . V_5 . V_56 ;
V_10 -> V_4 . V_5 . V_8 =
V_2 -> V_4 . V_5 . V_8 ;
V_10 -> V_4 . V_5 . V_9 =
V_2 -> V_4 . V_5 . V_9 ;
* V_19 |= V_67 ;
return V_65 ;
}
V_11 = F_3 ( V_10 , V_2 ) ;
if ( V_11 ) {
F_12 ( V_10 , V_18 , * V_19 ) ;
* V_36 = V_11 ;
return V_65 ;
}
if ( F_17 ( V_10 , V_2 ) ) {
F_9 ( V_10 ) ;
F_12 ( V_10 , V_18 , * V_19 ) ;
* V_36 = - V_68 ;
return V_65 ;
}
F_30 ( V_40 , & V_40 -> V_69 , V_10 ) ;
* V_19 |= V_70 ;
return V_65 ;
}
}
if ( * V_19 & V_66 ) {
F_12 ( V_10 , V_18 , * V_19 ) ;
V_10 -> V_46 = V_49 ;
* V_19 |= V_67 ;
return V_65 ;
}
F_9 ( V_10 ) ;
if ( ! V_44 )
V_44 = & V_40 -> V_71 ;
F_31 (ownlocks, tmp, &res->lr_granted) {
V_2 = F_27 ( V_44 , struct V_1 , V_20 ) ;
if ( ! F_1 ( V_2 , V_3 ) )
break;
if ( V_2 -> V_61 == V_18 ) {
if ( ( V_3 -> V_4 . V_5 . V_8 >
( V_2 -> V_4 . V_5 . V_9 + 1 ) )
&& ( V_2 -> V_4 . V_5 . V_9 !=
V_72 ) )
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
if ( V_48 ) {
F_12 ( V_2 , V_18 , * V_19 ) ;
} else {
V_3 = V_2 ;
V_48 = 1 ;
}
continue;
}
if ( V_3 -> V_4 . V_5 . V_8 >
V_2 -> V_4 . V_5 . V_9 )
continue;
if ( V_3 -> V_4 . V_5 . V_9 <
V_2 -> V_4 . V_5 . V_8 )
break;
++ V_50 ;
if ( V_3 -> V_4 . V_5 . V_8 <=
V_2 -> V_4 . V_5 . V_8 ) {
if ( V_3 -> V_4 . V_5 . V_9 <
V_2 -> V_4 . V_5 . V_9 ) {
V_2 -> V_4 . V_5 . V_8 =
V_3 -> V_4 . V_5 . V_9 + 1 ;
break;
}
F_12 ( V_2 , V_2 -> V_46 , * V_19 ) ;
continue;
}
if ( V_3 -> V_4 . V_5 . V_9 >=
V_2 -> V_4 . V_5 . V_9 ) {
V_2 -> V_4 . V_5 . V_9 =
V_3 -> V_4 . V_5 . V_8 - 1 ;
continue;
}
if ( ! V_45 ) {
F_32 ( V_10 ) ;
V_45 = F_33 ( V_42 , & V_40 -> V_73 , V_74 ,
V_2 -> V_61 , & V_53 ,
NULL , 0 , V_75 ) ;
F_34 ( V_10 ) ;
if ( ! V_45 ) {
F_12 ( V_10 , V_2 -> V_61 ,
* V_19 ) ;
* V_36 = - V_76 ;
return V_65 ;
}
goto V_60;
}
V_51 = 1 ;
V_45 -> V_61 = V_2 -> V_61 ;
V_45 -> V_4 . V_5 . V_56 =
V_3 -> V_4 . V_5 . V_56 ;
V_45 -> V_4 . V_5 . V_6 =
V_3 -> V_4 . V_5 . V_6 ;
V_45 -> V_4 . V_5 . V_8 =
V_2 -> V_4 . V_5 . V_8 ;
V_45 -> V_4 . V_5 . V_9 =
V_3 -> V_4 . V_5 . V_8 - 1 ;
V_2 -> V_4 . V_5 . V_8 =
V_3 -> V_4 . V_5 . V_9 + 1 ;
V_45 -> V_77 = V_2 -> V_77 ;
if ( V_2 -> V_7 != NULL ) {
V_45 -> V_7 = F_35 ( V_2 -> V_7 , V_45 ) ;
if ( V_45 -> V_7 -> V_78 &&
F_7 ( & V_45 -> V_79 ) )
F_8 ( V_45 -> V_7 -> V_78 ,
& V_45 -> V_80 ,
& V_45 -> V_79 ) ;
}
if ( * V_19 == V_21 )
F_36 ( V_45 ,
V_2 -> V_61 ) ;
F_30 ( V_40 , V_44 , V_45 ) ;
F_37 ( V_45 ) ;
break;
}
if ( V_51 == 0 && V_45 != NULL )
F_16 ( V_45 ) ;
V_10 -> V_61 = V_10 -> V_46 ;
if ( ! V_48 ) {
F_14 ( & V_10 -> V_20 ) ;
F_30 ( V_40 , V_44 , V_10 ) ;
}
if ( * V_19 != V_21 ) {
F_38 ( L_6 ) ;
F_39 () ;
}
if ( V_48 )
F_12 ( V_10 , V_18 , * V_19 ) ;
F_40 ( V_81 , V_40 ) ;
return V_62 ;
}
static void
F_41 ( void * V_82 )
{
struct V_1 * V_2 ;
V_2 = ( (struct V_83 * ) V_82 ) -> V_84 ;
F_34 ( V_2 ) ;
F_9 ( V_2 ) ;
V_2 -> V_22 |= V_25 ;
F_32 ( V_2 ) ;
}
int
F_42 ( struct V_1 * V_2 , T_2 V_19 , void * V_82 )
{
struct V_85 * V_86 = V_2 -> V_87 ;
struct V_88 * V_89 ;
struct V_90 * V_91 = NULL ;
struct V_83 V_92 ;
struct V_93 V_94 ;
T_3 V_36 ;
int V_11 = 0 ;
F_25 ( V_54 , L_7 ,
V_19 , V_82 , V_86 ) ;
if ( ( V_2 -> V_22 & ( V_23 | V_24 ) ) ==
( V_23 | V_24 ) ) {
if ( V_2 -> V_46 == V_2 -> V_61 &&
V_2 -> V_61 != V_49 &&
NULL == V_82 )
F_43 ( V_2 , V_2 -> V_46 ) ;
F_44 ( & V_2 -> V_95 ) ;
return 0 ;
}
F_6 ( V_19 != V_21 ) ;
if ( ! ( V_19 & ( V_96 | V_70 |
V_97 ) ) ) {
if ( NULL == V_82 )
goto V_98;
F_44 ( & V_2 -> V_95 ) ;
return 0 ;
}
F_13 ( V_2 , L_8
L_9 ) ;
V_92 . V_84 = V_2 ;
V_89 = F_45 ( V_2 -> V_77 ) ;
if ( NULL != V_89 )
V_91 = V_89 -> V_99 . V_100 . V_101 ;
if ( NULL != V_91 ) {
F_46 ( & V_91 -> V_102 ) ;
V_92 . V_103 = V_91 -> V_104 ;
F_47 ( & V_91 -> V_102 ) ;
}
V_94 = F_48 ( 0 , NULL , F_41 , & V_92 ) ;
V_11 = F_49 ( V_2 -> V_95 , F_50 ( V_2 ) , & V_94 ) ;
if ( V_11 ) {
F_13 ( V_2 , L_10 ,
V_11 ) ;
return V_11 ;
}
V_98:
F_51 ( V_105 , 10 ) ;
if ( V_2 -> V_22 & V_106 ) {
F_13 ( V_2 , L_11 ) ;
return 0 ;
}
if ( V_2 -> V_22 & V_23 ) {
F_13 ( V_2 , L_12 ) ;
return - V_107 ;
}
if ( V_11 ) {
F_13 ( V_2 , L_10 ,
V_11 ) ;
return V_11 ;
}
F_13 ( V_2 , L_13 ) ;
F_34 ( V_2 ) ;
F_9 ( V_2 ) ;
F_14 ( & V_2 -> V_20 ) ;
if ( V_19 & V_66 ) {
F_12 ( V_2 , F_52 ( V_86 ) ,
V_21 ) ;
switch ( V_2 -> V_61 ) {
case V_108 :
F_53 ( V_86 , V_109 ) ;
break;
case V_110 :
F_53 ( V_86 , V_111 ) ;
break;
default:
F_53 ( V_86 , V_112 ) ;
}
F_54 ( V_86 , ( V_113 ) V_2 -> V_4 . V_5 . V_56 ) ;
F_55 ( V_86 ,
( V_114 ) V_2 -> V_4 . V_5 . V_8 ) ;
F_56 ( V_86 ,
( V_114 ) V_2 -> V_4 . V_5 . V_9 ) ;
} else {
T_2 V_115 = V_21 ;
F_22 ( V_2 , & V_115 , 1 , & V_36 , NULL ) ;
}
F_32 ( V_2 ) ;
return 0 ;
}
int V_59 ( struct V_1 * V_2 , struct V_116 * V_117 ,
void * V_82 , int V_118 )
{
F_6 ( V_2 ) ;
F_6 ( V_118 == V_119 ) ;
F_34 ( V_2 ) ;
F_9 ( V_2 ) ;
F_32 ( V_2 ) ;
return 0 ;
}
void F_57 ( const T_4 * V_120 ,
T_5 * V_121 )
{
memset ( V_121 , 0 , sizeof( * V_121 ) ) ;
V_121 -> V_5 . V_8 = V_120 -> V_5 . V_122 ;
V_121 -> V_5 . V_9 = V_120 -> V_5 . V_123 ;
V_121 -> V_5 . V_56 = V_120 -> V_5 . V_124 ;
V_121 -> V_5 . V_6 = V_120 -> V_5 . V_124 ;
}
void F_58 ( const T_4 * V_120 ,
T_5 * V_121 )
{
memset ( V_121 , 0 , sizeof( * V_121 ) ) ;
V_121 -> V_5 . V_8 = V_120 -> V_5 . V_122 ;
V_121 -> V_5 . V_9 = V_120 -> V_5 . V_123 ;
V_121 -> V_5 . V_56 = V_120 -> V_5 . V_124 ;
V_121 -> V_5 . V_6 = V_120 -> V_5 . V_125 ;
}
void F_59 ( const T_5 * V_121 ,
T_4 * V_120 )
{
memset ( V_120 , 0 , sizeof( * V_120 ) ) ;
V_120 -> V_5 . V_122 = V_121 -> V_5 . V_8 ;
V_120 -> V_5 . V_123 = V_121 -> V_5 . V_9 ;
V_120 -> V_5 . V_124 = V_121 -> V_5 . V_56 ;
V_120 -> V_5 . V_125 = V_121 -> V_5 . V_6 ;
}
static unsigned
F_60 ( T_6 * V_126 , const void * V_127 , unsigned V_128 )
{
return F_61 ( * ( T_2 * ) V_127 , V_128 ) ;
}
static void *
F_62 ( struct V_129 * V_130 )
{
struct V_1 * V_2 ;
V_2 = F_63 ( V_130 , struct V_1 , V_13 ) ;
return & V_2 -> V_4 . V_5 . V_6 ;
}
static int
F_64 ( const void * V_127 , struct V_129 * V_130 )
{
return ! memcmp ( F_62 ( V_130 ) , V_127 , sizeof( T_2 ) ) ;
}
static void *
F_65 ( struct V_129 * V_130 )
{
return F_63 ( V_130 , struct V_1 , V_13 ) ;
}
static void
F_66 ( T_6 * V_126 , struct V_129 * V_130 )
{
struct V_1 * V_2 ;
struct V_33 * V_34 ;
V_2 = F_63 ( V_130 , struct V_1 , V_13 ) ;
F_67 ( V_2 ) ;
V_34 = & V_2 -> V_4 . V_5 ;
F_6 ( V_34 -> V_15 != NULL ) ;
F_18 ( V_34 -> V_15 ) ;
V_34 -> V_16 ++ ;
}
static void
F_68 ( T_6 * V_126 , struct V_129 * V_130 )
{
struct V_1 * V_2 ;
struct V_33 * V_34 ;
V_2 = F_63 ( V_130 , struct V_1 , V_13 ) ;
F_37 ( V_2 ) ;
V_34 = & V_2 -> V_4 . V_5 ;
F_6 ( V_34 -> V_15 != NULL ) ;
F_20 ( V_34 -> V_15 ) ;
if ( -- V_34 -> V_16 == 0 ) {
V_34 -> V_14 = 0 ;
V_34 -> V_15 = NULL ;
}
}
int F_5 ( struct V_27 * exp )
{
exp -> V_12 =
F_69 ( F_70 ( & exp -> V_131 ) ,
V_132 ,
V_133 ,
V_134 , 0 ,
V_135 , V_136 ,
& V_137 ,
V_138 | V_139 ) ;
if ( ! exp -> V_12 )
return - V_140 ;
return 0 ;
}
void F_71 ( struct V_27 * exp )
{
if ( exp -> V_12 ) {
F_72 ( exp -> V_12 ) ;
exp -> V_12 = NULL ;
}
}
