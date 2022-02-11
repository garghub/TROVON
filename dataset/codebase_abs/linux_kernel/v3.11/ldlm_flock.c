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
V_20 ;
F_13 ( V_2 , L_1 ,
V_18 , V_19 ) ;
F_6 ( F_7 ( & V_2 -> V_13 ) ) ;
F_14 ( & V_2 -> V_21 ) ;
if ( V_19 == V_22 &&
! ( V_2 -> V_23 & V_24 ) ) {
V_2 -> V_23 |= V_25 | V_26 ;
F_15 ( V_2 , V_18 ) ;
}
F_16 ( V_2 ) ;
EXIT ;
}
static int
F_17 ( struct V_1 * V_10 , struct V_1 * V_27 )
{
struct V_28 * V_29 = V_10 -> V_7 ;
struct V_28 * V_30 = V_27 -> V_7 ;
T_2 V_31 = V_10 -> V_4 . V_5 . V_6 ;
T_2 V_32 = V_27 -> V_4 . V_5 . V_6 ;
if ( V_29 == NULL )
return 0 ;
F_18 ( V_30 ) ;
while ( 1 ) {
struct V_28 * V_33 ;
struct V_1 * V_2 = NULL ;
struct V_34 * V_35 ;
if ( V_30 -> V_12 != NULL )
V_2 = F_19 ( V_30 -> V_12 ,
& V_32 ) ;
if ( V_2 == NULL )
break;
V_35 = & V_2 -> V_4 . V_5 ;
F_6 ( V_35 -> V_6 == V_32 ) ;
V_32 = V_35 -> V_14 ;
V_33 = F_18 ( V_35 -> V_15 ) ;
F_20 ( V_30 ) ;
F_21 ( V_30 -> V_12 , & V_2 -> V_13 ) ;
V_30 = V_33 ;
if ( V_32 == V_31 && V_30 == V_29 ) {
F_20 ( V_30 ) ;
return 1 ;
}
}
F_20 ( V_30 ) ;
return 0 ;
}
int
F_22 ( struct V_1 * V_10 , T_2 * V_19 , int V_36 ,
T_3 * V_37 , struct V_38 * V_39 )
{
struct V_40 * V_41 = V_10 -> V_17 ;
struct V_42 * V_43 = F_23 ( V_41 ) ;
struct V_38 * V_44 ;
struct V_38 * V_45 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_1 * V_3 = V_10 ;
struct V_1 * V_46 = NULL ;
T_1 V_18 = V_10 -> V_47 ;
int V_48 = F_24 ( V_43 ) ;
int V_49 = ( V_18 == V_50 ) ;
int V_51 = 0 ;
int V_52 = 0 ;
const struct V_53 V_54 = { NULL } ;
int V_11 ;
V_20 ;
F_25 ( V_55 , L_2 V_56 L_3
V_56 L_4 V_56 L_5 , * V_19 ,
V_3 -> V_4 . V_5 . V_6 ,
V_3 -> V_4 . V_5 . V_57 , V_18 ,
V_10 -> V_4 . V_5 . V_8 ,
V_10 -> V_4 . V_5 . V_9 ) ;
* V_37 = V_58 ;
if ( V_48 ) {
V_10 -> V_59 = NULL ;
} else {
V_10 -> V_59 = V_60 ;
}
V_61:
if ( ( * V_19 == V_22 ) || ( V_18 == V_50 ) ) {
F_26 (tmp, &res->lr_granted) {
V_2 = F_27 ( V_44 , struct V_1 ,
V_21 ) ;
if ( F_1 ( V_2 , V_10 ) ) {
V_45 = V_44 ;
break;
}
}
} else {
F_28 ( V_18 ) ;
F_26 (tmp, &res->lr_granted) {
V_2 = F_27 ( V_44 , struct V_1 ,
V_21 ) ;
if ( F_1 ( V_2 , V_10 ) ) {
if ( ! V_45 )
V_45 = V_44 ;
continue;
}
if ( F_29 ( V_2 -> V_62 , V_18 ) )
continue;
if ( ! F_2 ( V_2 , V_10 ) )
continue;
if ( ! V_36 )
RETURN ( V_63 ) ;
if ( * V_19 & V_64 ) {
F_12 ( V_10 , V_18 , * V_19 ) ;
* V_37 = - V_65 ;
RETURN ( V_66 ) ;
}
if ( * V_19 & V_67 ) {
F_12 ( V_10 , V_18 , * V_19 ) ;
V_10 -> V_47 = V_2 -> V_62 ;
V_10 -> V_4 . V_5 . V_57 =
V_2 -> V_4 . V_5 . V_57 ;
V_10 -> V_4 . V_5 . V_8 =
V_2 -> V_4 . V_5 . V_8 ;
V_10 -> V_4 . V_5 . V_9 =
V_2 -> V_4 . V_5 . V_9 ;
* V_19 |= V_68 ;
RETURN ( V_66 ) ;
}
if ( F_17 ( V_10 , V_2 ) ) {
F_12 ( V_10 , V_18 , * V_19 ) ;
* V_37 = - V_69 ;
RETURN ( V_66 ) ;
}
V_11 = F_3 ( V_10 , V_2 ) ;
if ( V_11 ) {
F_12 ( V_10 , V_18 , * V_19 ) ;
* V_37 = V_11 ;
RETURN ( V_66 ) ;
}
F_30 ( V_41 , & V_41 -> V_70 , V_10 ) ;
* V_19 |= V_71 ;
RETURN ( V_66 ) ;
}
}
if ( * V_19 & V_67 ) {
F_12 ( V_10 , V_18 , * V_19 ) ;
V_10 -> V_47 = V_50 ;
* V_19 |= V_68 ;
RETURN ( V_66 ) ;
}
F_9 ( V_10 ) ;
if ( ! V_45 )
V_45 = & V_41 -> V_72 ;
F_31 (ownlocks, tmp, &res->lr_granted) {
V_2 = F_27 ( V_45 , struct V_1 , V_21 ) ;
if ( ! F_1 ( V_2 , V_3 ) )
break;
if ( V_2 -> V_62 == V_18 ) {
if ( ( V_3 -> V_4 . V_5 . V_8 >
( V_2 -> V_4 . V_5 . V_9 + 1 ) )
&& ( V_2 -> V_4 . V_5 . V_9 !=
V_73 ) )
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
if ( V_49 ) {
F_12 ( V_2 , V_18 , * V_19 ) ;
} else {
V_3 = V_2 ;
V_49 = 1 ;
}
continue;
}
if ( V_3 -> V_4 . V_5 . V_8 >
V_2 -> V_4 . V_5 . V_9 )
continue;
if ( V_3 -> V_4 . V_5 . V_9 <
V_2 -> V_4 . V_5 . V_8 )
break;
++ V_51 ;
if ( V_3 -> V_4 . V_5 . V_8 <=
V_2 -> V_4 . V_5 . V_8 ) {
if ( V_3 -> V_4 . V_5 . V_9 <
V_2 -> V_4 . V_5 . V_9 ) {
V_2 -> V_4 . V_5 . V_8 =
V_3 -> V_4 . V_5 . V_9 + 1 ;
break;
}
F_12 ( V_2 , V_2 -> V_47 , * V_19 ) ;
continue;
}
if ( V_3 -> V_4 . V_5 . V_9 >=
V_2 -> V_4 . V_5 . V_9 ) {
V_2 -> V_4 . V_5 . V_9 =
V_3 -> V_4 . V_5 . V_8 - 1 ;
continue;
}
if ( ! V_46 ) {
F_32 ( V_10 ) ;
V_46 = F_33 ( V_43 , & V_41 -> V_74 , V_75 ,
V_2 -> V_62 , & V_54 ,
NULL , 0 , V_76 ) ;
F_34 ( V_10 ) ;
if ( ! V_46 ) {
F_12 ( V_10 , V_2 -> V_62 ,
* V_19 ) ;
* V_37 = - V_77 ;
RETURN ( V_66 ) ;
}
goto V_61;
}
V_52 = 1 ;
V_46 -> V_62 = V_2 -> V_62 ;
V_46 -> V_4 . V_5 . V_57 =
V_3 -> V_4 . V_5 . V_57 ;
V_46 -> V_4 . V_5 . V_6 =
V_3 -> V_4 . V_5 . V_6 ;
V_46 -> V_4 . V_5 . V_8 =
V_2 -> V_4 . V_5 . V_8 ;
V_46 -> V_4 . V_5 . V_9 =
V_3 -> V_4 . V_5 . V_8 - 1 ;
V_2 -> V_4 . V_5 . V_8 =
V_3 -> V_4 . V_5 . V_9 + 1 ;
V_46 -> V_78 = V_2 -> V_78 ;
if ( V_2 -> V_7 != NULL ) {
V_46 -> V_7 = F_35 ( V_2 -> V_7 , V_46 ) ;
if ( V_46 -> V_7 -> V_79 &&
F_7 ( & V_46 -> V_80 ) )
F_8 ( V_46 -> V_7 -> V_79 ,
& V_46 -> V_81 ,
& V_46 -> V_80 ) ;
}
if ( * V_19 == V_22 )
F_36 ( V_46 ,
V_2 -> V_62 ) ;
F_30 ( V_41 , V_45 , V_46 ) ;
F_37 ( V_46 ) ;
break;
}
if ( V_52 == 0 && V_46 != NULL )
F_16 ( V_46 ) ;
V_10 -> V_62 = V_10 -> V_47 ;
if ( ! V_49 ) {
F_14 ( & V_10 -> V_21 ) ;
F_30 ( V_41 , V_45 , V_10 ) ;
}
if ( * V_19 != V_22 ) {
F_38 ( L_6 ) ;
F_39 () ;
}
if ( V_49 )
F_12 ( V_10 , V_18 , * V_19 ) ;
F_40 ( V_82 , V_41 ) ;
RETURN ( V_63 ) ;
}
static void
F_41 ( void * V_83 )
{
struct V_1 * V_2 ;
V_20 ;
V_2 = ( (struct V_84 * ) V_83 ) -> V_85 ;
F_34 ( V_2 ) ;
F_9 ( V_2 ) ;
V_2 -> V_23 |= V_26 ;
F_32 ( V_2 ) ;
EXIT ;
}
int
F_42 ( struct V_1 * V_2 , T_2 V_19 , void * V_83 )
{
struct V_86 * V_87 = V_2 -> V_88 ;
struct V_89 * V_90 ;
struct V_91 * V_92 = NULL ;
struct V_84 V_93 ;
struct V_94 V_95 ;
T_3 V_37 ;
int V_11 = 0 ;
V_20 ;
F_25 ( V_55 , L_7 ,
V_19 , V_83 , V_87 ) ;
if ( ( V_2 -> V_23 & ( V_24 | V_25 ) ) ==
( V_24 | V_25 ) ) {
if ( V_2 -> V_47 == V_2 -> V_62 &&
V_2 -> V_62 != V_50 &&
NULL == V_83 )
F_43 ( V_2 , V_2 -> V_47 ) ;
F_44 ( & V_2 -> V_96 ) ;
RETURN ( 0 ) ;
}
F_6 ( V_19 != V_22 ) ;
if ( ! ( V_19 & ( V_97 | V_71 |
V_98 ) ) ) {
if ( NULL == V_83 )
goto V_99;
F_44 ( & V_2 -> V_96 ) ;
RETURN ( 0 ) ;
}
F_13 ( V_2 , L_8
L_9 ) ;
V_93 . V_85 = V_2 ;
V_90 = F_45 ( V_2 -> V_78 ) ;
if ( NULL != V_90 )
V_92 = V_90 -> V_100 . V_101 . V_102 ;
if ( NULL != V_92 ) {
F_46 ( & V_92 -> V_103 ) ;
V_93 . V_104 = V_92 -> V_105 ;
F_47 ( & V_92 -> V_103 ) ;
}
V_95 = F_48 ( 0 , NULL , F_41 , & V_93 ) ;
V_11 = F_49 ( V_2 -> V_96 , F_50 ( V_2 ) , & V_95 ) ;
if ( V_11 ) {
F_13 ( V_2 , L_10 ,
V_11 ) ;
RETURN ( V_11 ) ;
}
V_99:
F_51 ( V_106 , 10 ) ;
if ( V_2 -> V_107 ) {
F_13 ( V_2 , L_11 ) ;
RETURN ( 0 ) ;
}
if ( V_2 -> V_23 & V_24 ) {
F_13 ( V_2 , L_12 ) ;
RETURN ( - V_108 ) ;
}
if ( V_11 ) {
F_13 ( V_2 , L_10 ,
V_11 ) ;
RETURN ( V_11 ) ;
}
F_13 ( V_2 , L_13 ) ;
F_34 ( V_2 ) ;
F_9 ( V_2 ) ;
F_14 ( & V_2 -> V_21 ) ;
if ( V_19 & V_67 ) {
F_12 ( V_2 , F_52 ( V_87 ) ,
V_22 ) ;
switch ( V_2 -> V_62 ) {
case V_109 :
F_53 ( V_87 , V_110 ) ;
break;
case V_111 :
F_53 ( V_87 , V_112 ) ;
break;
default:
F_53 ( V_87 , V_113 ) ;
}
F_54 ( V_87 , ( V_114 ) V_2 -> V_4 . V_5 . V_57 ) ;
F_55 ( V_87 ,
( V_115 ) V_2 -> V_4 . V_5 . V_8 ) ;
F_56 ( V_87 ,
( V_115 ) V_2 -> V_4 . V_5 . V_9 ) ;
} else {
T_2 V_116 = V_22 ;
F_22 ( V_2 , & V_116 , 1 , & V_37 , NULL ) ;
}
F_32 ( V_2 ) ;
RETURN ( 0 ) ;
}
int V_60 ( struct V_1 * V_2 , struct V_117 * V_118 ,
void * V_83 , int V_119 )
{
V_20 ;
F_6 ( V_2 ) ;
F_6 ( V_119 == V_120 ) ;
F_34 ( V_2 ) ;
F_9 ( V_2 ) ;
F_32 ( V_2 ) ;
RETURN ( 0 ) ;
}
void F_57 ( const T_4 * V_121 ,
T_5 * V_122 )
{
memset ( V_122 , 0 , sizeof( * V_122 ) ) ;
V_122 -> V_5 . V_8 = V_121 -> V_5 . V_123 ;
V_122 -> V_5 . V_9 = V_121 -> V_5 . V_124 ;
V_122 -> V_5 . V_57 = V_121 -> V_5 . V_125 ;
V_122 -> V_5 . V_6 = V_121 -> V_5 . V_125 ;
}
void F_58 ( const T_4 * V_121 ,
T_5 * V_122 )
{
memset ( V_122 , 0 , sizeof( * V_122 ) ) ;
V_122 -> V_5 . V_8 = V_121 -> V_5 . V_123 ;
V_122 -> V_5 . V_9 = V_121 -> V_5 . V_124 ;
V_122 -> V_5 . V_57 = V_121 -> V_5 . V_125 ;
V_122 -> V_5 . V_6 = V_121 -> V_5 . V_126 ;
}
void F_59 ( const T_5 * V_122 ,
T_4 * V_121 )
{
memset ( V_121 , 0 , sizeof( * V_121 ) ) ;
V_121 -> V_5 . V_123 = V_122 -> V_5 . V_8 ;
V_121 -> V_5 . V_124 = V_122 -> V_5 . V_9 ;
V_121 -> V_5 . V_125 = V_122 -> V_5 . V_57 ;
V_121 -> V_5 . V_126 = V_122 -> V_5 . V_6 ;
}
static unsigned
F_60 ( T_6 * V_127 , const void * V_128 , unsigned V_129 )
{
return F_61 ( * ( T_2 * ) V_128 , V_129 ) ;
}
static void *
F_62 ( struct V_130 * V_131 )
{
struct V_1 * V_2 ;
V_2 = F_63 ( V_131 , struct V_1 , V_13 ) ;
return & V_2 -> V_4 . V_5 . V_6 ;
}
static int
F_64 ( const void * V_128 , struct V_130 * V_131 )
{
return ! memcmp ( F_62 ( V_131 ) , V_128 , sizeof( T_2 ) ) ;
}
static void *
F_65 ( struct V_130 * V_131 )
{
return F_63 ( V_131 , struct V_1 , V_13 ) ;
}
static void
F_66 ( T_6 * V_127 , struct V_130 * V_131 )
{
struct V_1 * V_2 ;
struct V_34 * V_35 ;
V_2 = F_63 ( V_131 , struct V_1 , V_13 ) ;
F_67 ( V_2 ) ;
V_35 = & V_2 -> V_4 . V_5 ;
F_6 ( V_35 -> V_15 != NULL ) ;
F_18 ( V_35 -> V_15 ) ;
V_35 -> V_16 ++ ;
}
static void
F_68 ( T_6 * V_127 , struct V_130 * V_131 )
{
struct V_1 * V_2 ;
struct V_34 * V_35 ;
V_2 = F_63 ( V_131 , struct V_1 , V_13 ) ;
F_37 ( V_2 ) ;
V_35 = & V_2 -> V_4 . V_5 ;
F_6 ( V_35 -> V_15 != NULL ) ;
F_20 ( V_35 -> V_15 ) ;
if ( -- V_35 -> V_16 == 0 ) {
V_35 -> V_14 = 0 ;
V_35 -> V_15 = NULL ;
}
}
int F_5 ( struct V_28 * exp )
{
exp -> V_12 =
F_69 ( F_70 ( & exp -> V_132 ) ,
V_133 ,
V_134 ,
V_135 , 0 ,
V_136 , V_137 ,
& V_138 ,
V_139 | V_140 ) ;
if ( ! exp -> V_12 )
RETURN ( - V_141 ) ;
RETURN ( 0 ) ;
}
void F_71 ( struct V_28 * exp )
{
V_20 ;
if ( exp -> V_12 ) {
F_72 ( exp -> V_12 ) ;
exp -> V_12 = NULL ;
}
EXIT ;
}
