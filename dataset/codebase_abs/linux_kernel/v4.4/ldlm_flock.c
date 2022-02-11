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
static inline void
F_3 ( struct V_1 * V_2 , T_1 V_10 , T_2 V_11 )
{
F_4 ( V_2 , L_1 ,
V_10 , V_11 ) ;
F_5 ( F_6 ( & V_2 -> V_12 ) ) ;
F_7 ( & V_2 -> V_13 ) ;
if ( V_11 == V_14 &&
! ( V_2 -> V_15 & V_16 ) ) {
V_2 -> V_15 |= V_17 | V_18 ;
F_8 ( V_2 , V_10 ) ;
}
F_9 ( V_2 ) ;
}
static int F_10 ( struct V_1 * V_19 , T_2 * V_11 ,
int V_20 , T_3 * V_21 ,
struct V_22 * V_23 )
{
struct V_24 * V_25 = V_19 -> V_26 ;
struct V_27 * V_28 = F_11 ( V_25 ) ;
struct V_22 * V_29 ;
struct V_22 * V_30 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_1 * V_3 = V_19 ;
struct V_1 * V_31 = NULL ;
T_1 V_10 = V_19 -> V_32 ;
int V_33 = ( V_10 == V_34 ) ;
int V_35 = 0 ;
int V_36 = 0 ;
const struct V_37 V_38 = { NULL } ;
F_12 ( V_39 ,
L_2 ,
* V_11 , V_3 -> V_4 . V_5 . V_6 ,
V_3 -> V_4 . V_5 . V_40 , V_10 ,
V_19 -> V_4 . V_5 . V_8 ,
V_19 -> V_4 . V_5 . V_9 ) ;
* V_21 = V_41 ;
V_19 -> V_42 = NULL ;
V_43:
if ( ( * V_11 == V_14 ) || ( V_10 == V_34 ) ) {
F_13 (tmp, &res->lr_granted) {
V_2 = F_14 ( V_29 , struct V_1 ,
V_13 ) ;
if ( F_1 ( V_2 , V_19 ) ) {
V_30 = V_29 ;
break;
}
}
} else {
int V_44 = 0 ;
F_15 ( V_10 ) ;
F_13 (tmp, &res->lr_granted) {
V_2 = F_14 ( V_29 , struct V_1 ,
V_13 ) ;
if ( F_1 ( V_2 , V_19 ) ) {
if ( ! V_30 )
V_30 = V_29 ;
continue;
}
if ( F_16 ( V_2 -> V_45 , V_10 ) )
continue;
if ( ! F_2 ( V_2 , V_19 ) )
continue;
if ( ! V_20 ) {
V_44 = 1 ;
continue;
}
if ( * V_11 & V_46 ) {
F_3 ( V_19 , V_10 , * V_11 ) ;
* V_21 = - V_47 ;
return V_48 ;
}
if ( * V_11 & V_49 ) {
F_3 ( V_19 , V_10 , * V_11 ) ;
V_19 -> V_32 = V_2 -> V_45 ;
V_19 -> V_4 . V_5 . V_40 =
V_2 -> V_4 . V_5 . V_40 ;
V_19 -> V_4 . V_5 . V_8 =
V_2 -> V_4 . V_5 . V_8 ;
V_19 -> V_4 . V_5 . V_9 =
V_2 -> V_4 . V_5 . V_9 ;
* V_11 |= V_50 ;
return V_48 ;
}
F_17 ( V_25 , & V_25 -> V_51 , V_19 ) ;
* V_11 |= V_52 ;
return V_48 ;
}
if ( V_44 )
return V_53 ;
}
if ( * V_11 & V_49 ) {
F_3 ( V_19 , V_10 , * V_11 ) ;
V_19 -> V_32 = V_34 ;
* V_11 |= V_50 ;
return V_48 ;
}
if ( ! V_30 )
V_30 = & V_25 -> V_54 ;
F_18 (ownlocks, tmp, &res->lr_granted) {
V_2 = F_14 ( V_30 , struct V_1 , V_13 ) ;
if ( ! F_1 ( V_2 , V_3 ) )
break;
if ( V_2 -> V_45 == V_10 ) {
if ( ( V_3 -> V_4 . V_5 . V_8 >
( V_2 -> V_4 . V_5 . V_9 + 1 ) )
&& ( V_2 -> V_4 . V_5 . V_9 !=
V_55 ) )
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
if ( V_33 ) {
F_3 ( V_2 , V_10 , * V_11 ) ;
} else {
V_3 = V_2 ;
V_33 = 1 ;
}
continue;
}
if ( V_3 -> V_4 . V_5 . V_8 >
V_2 -> V_4 . V_5 . V_9 )
continue;
if ( V_3 -> V_4 . V_5 . V_9 <
V_2 -> V_4 . V_5 . V_8 )
break;
++ V_35 ;
if ( V_3 -> V_4 . V_5 . V_8 <=
V_2 -> V_4 . V_5 . V_8 ) {
if ( V_3 -> V_4 . V_5 . V_9 <
V_2 -> V_4 . V_5 . V_9 ) {
V_2 -> V_4 . V_5 . V_8 =
V_3 -> V_4 . V_5 . V_9 + 1 ;
break;
}
F_3 ( V_2 , V_2 -> V_32 , * V_11 ) ;
continue;
}
if ( V_3 -> V_4 . V_5 . V_9 >=
V_2 -> V_4 . V_5 . V_9 ) {
V_2 -> V_4 . V_5 . V_9 =
V_3 -> V_4 . V_5 . V_8 - 1 ;
continue;
}
if ( ! V_31 ) {
F_19 ( V_19 ) ;
V_31 = F_20 ( V_28 , & V_25 -> V_56 , V_57 ,
V_2 -> V_45 , & V_38 ,
NULL , 0 , V_58 ) ;
F_21 ( V_19 ) ;
if ( ! V_31 ) {
F_3 ( V_19 , V_2 -> V_45 ,
* V_11 ) ;
* V_21 = - V_59 ;
return V_48 ;
}
goto V_43;
}
V_36 = 1 ;
V_31 -> V_45 = V_2 -> V_45 ;
V_31 -> V_4 . V_5 . V_40 =
V_3 -> V_4 . V_5 . V_40 ;
V_31 -> V_4 . V_5 . V_6 =
V_3 -> V_4 . V_5 . V_6 ;
V_31 -> V_4 . V_5 . V_8 =
V_2 -> V_4 . V_5 . V_8 ;
V_31 -> V_4 . V_5 . V_9 =
V_3 -> V_4 . V_5 . V_8 - 1 ;
V_2 -> V_4 . V_5 . V_8 =
V_3 -> V_4 . V_5 . V_9 + 1 ;
V_31 -> V_60 = V_2 -> V_60 ;
if ( V_2 -> V_7 != NULL ) {
V_31 -> V_7 = F_22 ( V_2 -> V_7 ,
V_31 ) ;
if ( V_31 -> V_7 -> V_61 &&
F_6 ( & V_31 -> V_62 ) )
F_23 ( V_31 -> V_7 -> V_61 ,
& V_31 -> V_63 ,
& V_31 -> V_62 ) ;
}
if ( * V_11 == V_14 )
F_24 ( V_31 ,
V_2 -> V_45 ) ;
F_17 ( V_25 , V_30 , V_31 ) ;
F_25 ( V_31 ) ;
break;
}
if ( V_36 == 0 && V_31 != NULL )
F_9 ( V_31 ) ;
V_19 -> V_45 = V_19 -> V_32 ;
if ( ! V_33 ) {
F_7 ( & V_19 -> V_13 ) ;
F_17 ( V_25 , V_30 , V_19 ) ;
}
if ( * V_11 != V_14 ) {
F_26 ( L_3 ) ;
F_27 () ;
}
if ( V_33 )
F_3 ( V_19 , V_10 , * V_11 ) ;
F_28 ( V_64 , V_25 ) ;
return V_53 ;
}
static void
F_29 ( void * V_65 )
{
struct V_1 * V_2 ;
V_2 = ( (struct V_66 * ) V_65 ) -> V_67 ;
F_21 ( V_2 ) ;
V_2 -> V_15 |= V_18 ;
F_19 ( V_2 ) ;
}
int
F_30 ( struct V_1 * V_2 , T_2 V_11 , void * V_65 )
{
struct V_68 * V_69 = V_2 -> V_70 ;
struct V_71 * V_72 ;
struct V_73 * V_74 = NULL ;
struct V_66 V_75 ;
struct V_76 V_77 ;
T_3 V_21 ;
int V_78 = 0 ;
F_12 ( V_39 , L_4 ,
V_11 , V_65 , V_69 ) ;
if ( ( V_2 -> V_15 & ( V_16 | V_17 ) ) ==
( V_16 | V_17 ) ) {
if ( V_2 -> V_32 == V_2 -> V_45 &&
V_2 -> V_45 != V_34 &&
V_65 == NULL )
F_31 ( V_2 , V_2 -> V_32 ) ;
F_32 ( & V_2 -> V_79 ) ;
return 0 ;
}
F_5 ( V_11 != V_14 ) ;
if ( ! ( V_11 & ( V_80 | V_52 |
V_81 ) ) ) {
if ( V_65 == NULL )
goto V_82;
F_32 ( & V_2 -> V_79 ) ;
return 0 ;
}
F_4 ( V_2 , L_5 ) ;
V_75 . V_67 = V_2 ;
V_72 = F_33 ( V_2 -> V_60 ) ;
if ( V_72 != NULL )
V_74 = V_72 -> V_83 . V_84 . V_85 ;
if ( V_74 != NULL ) {
F_34 ( & V_74 -> V_86 ) ;
V_75 . V_87 = V_74 -> V_88 ;
F_35 ( & V_74 -> V_86 ) ;
}
V_77 = F_36 ( 0 , NULL , F_29 , & V_75 ) ;
V_78 = F_37 ( V_2 -> V_79 , F_38 ( V_2 ) , & V_77 ) ;
if ( V_78 ) {
F_4 ( V_2 , L_6 ,
V_78 ) ;
return V_78 ;
}
V_82:
F_39 ( V_89 , 10 ) ;
if ( V_2 -> V_15 & V_90 ) {
F_4 ( V_2 , L_7 ) ;
return 0 ;
}
if ( V_2 -> V_15 & V_16 ) {
F_4 ( V_2 , L_8 ) ;
return - V_91 ;
}
if ( V_78 ) {
F_4 ( V_2 , L_6 ,
V_78 ) ;
return V_78 ;
}
F_4 ( V_2 , L_9 ) ;
F_21 ( V_2 ) ;
F_7 ( & V_2 -> V_13 ) ;
if ( V_2 -> V_15 & V_92 ) {
F_4 ( V_2 , L_10 ) ;
V_78 = - V_93 ;
} else if ( V_11 & V_49 ) {
F_3 ( V_2 , V_69 -> V_94 , V_14 ) ;
switch ( V_2 -> V_45 ) {
case V_95 :
V_69 -> V_94 = V_96 ;
break;
case V_97 :
V_69 -> V_94 = V_98 ;
break;
default:
V_69 -> V_94 = V_99 ;
}
V_69 -> V_100 = ( V_101 ) V_2 -> V_4 . V_5 . V_40 ;
V_69 -> V_102 = ( V_103 ) V_2 -> V_4 . V_5 . V_8 ;
V_69 -> V_104 = ( V_103 ) V_2 -> V_4 . V_5 . V_9 ;
} else {
T_2 V_105 = V_14 ;
F_10 ( V_2 , & V_105 , 1 , & V_21 , NULL ) ;
}
F_19 ( V_2 ) ;
return V_78 ;
}
void F_40 ( const T_4 * V_106 ,
T_5 * V_107 )
{
memset ( V_107 , 0 , sizeof( * V_107 ) ) ;
V_107 -> V_5 . V_8 = V_106 -> V_5 . V_108 ;
V_107 -> V_5 . V_9 = V_106 -> V_5 . V_109 ;
V_107 -> V_5 . V_40 = V_106 -> V_5 . V_110 ;
V_107 -> V_5 . V_6 = V_106 -> V_5 . V_110 ;
}
void F_41 ( const T_4 * V_106 ,
T_5 * V_107 )
{
memset ( V_107 , 0 , sizeof( * V_107 ) ) ;
V_107 -> V_5 . V_8 = V_106 -> V_5 . V_108 ;
V_107 -> V_5 . V_9 = V_106 -> V_5 . V_109 ;
V_107 -> V_5 . V_40 = V_106 -> V_5 . V_110 ;
V_107 -> V_5 . V_6 = V_106 -> V_5 . V_111 ;
}
void F_42 ( const T_5 * V_107 ,
T_4 * V_106 )
{
memset ( V_106 , 0 , sizeof( * V_106 ) ) ;
V_106 -> V_5 . V_108 = V_107 -> V_5 . V_8 ;
V_106 -> V_5 . V_109 = V_107 -> V_5 . V_9 ;
V_106 -> V_5 . V_110 = V_107 -> V_5 . V_40 ;
V_106 -> V_5 . V_111 = V_107 -> V_5 . V_6 ;
}
