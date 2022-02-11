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
F_3 ( struct V_1 * V_2 , enum V_10 V_11 , T_1 V_12 )
{
F_4 ( V_2 , L_1 ,
V_11 , V_12 ) ;
F_5 ( F_6 ( & V_2 -> V_13 ) ) ;
F_7 ( & V_2 -> V_14 ) ;
if ( V_12 == V_15 &&
! ( V_2 -> V_16 & V_17 ) ) {
V_2 -> V_16 |= V_18 | V_19 ;
F_8 ( V_2 , V_11 ) ;
}
F_9 ( V_2 ) ;
}
static int F_10 ( struct V_1 * V_20 , T_1 * V_12 ,
int V_21 , enum V_22 * V_23 ,
struct V_24 * V_25 )
{
struct V_26 * V_27 = V_20 -> V_28 ;
struct V_29 * V_30 = F_11 ( V_27 ) ;
struct V_24 * V_31 ;
struct V_24 * V_32 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_1 * V_3 = V_20 ;
struct V_1 * V_33 = NULL ;
enum V_10 V_11 = V_20 -> V_34 ;
int V_35 = ( V_11 == V_36 ) ;
int V_37 = 0 ;
int V_38 = 0 ;
const struct V_39 V_40 = { NULL } ;
F_12 ( V_41 ,
L_2 ,
* V_12 , V_3 -> V_4 . V_5 . V_6 ,
V_3 -> V_4 . V_5 . V_42 , V_11 ,
V_20 -> V_4 . V_5 . V_8 ,
V_20 -> V_4 . V_5 . V_9 ) ;
* V_23 = V_43 ;
V_20 -> V_44 = NULL ;
V_45:
if ( ( * V_12 == V_15 ) || ( V_11 == V_36 ) ) {
F_13 (tmp, &res->lr_granted) {
V_2 = F_14 ( V_31 , struct V_1 ,
V_14 ) ;
if ( F_1 ( V_2 , V_20 ) ) {
V_32 = V_31 ;
break;
}
}
} else {
int V_46 = 0 ;
F_15 ( V_11 ) ;
F_13 (tmp, &res->lr_granted) {
V_2 = F_14 ( V_31 , struct V_1 ,
V_14 ) ;
if ( F_1 ( V_2 , V_20 ) ) {
if ( ! V_32 )
V_32 = V_31 ;
continue;
}
if ( F_16 ( V_2 -> V_47 , V_11 ) )
continue;
if ( ! F_2 ( V_2 , V_20 ) )
continue;
if ( ! V_21 ) {
V_46 = 1 ;
continue;
}
if ( * V_12 & V_48 ) {
F_3 ( V_20 , V_11 , * V_12 ) ;
* V_23 = - V_49 ;
return V_50 ;
}
if ( * V_12 & V_51 ) {
F_3 ( V_20 , V_11 , * V_12 ) ;
V_20 -> V_34 = V_2 -> V_47 ;
V_20 -> V_4 . V_5 . V_42 =
V_2 -> V_4 . V_5 . V_42 ;
V_20 -> V_4 . V_5 . V_8 =
V_2 -> V_4 . V_5 . V_8 ;
V_20 -> V_4 . V_5 . V_9 =
V_2 -> V_4 . V_5 . V_9 ;
* V_12 |= V_52 ;
return V_50 ;
}
F_17 ( V_27 , & V_27 -> V_53 , V_20 ) ;
* V_12 |= V_54 ;
return V_50 ;
}
if ( V_46 )
return V_55 ;
}
if ( * V_12 & V_51 ) {
F_3 ( V_20 , V_11 , * V_12 ) ;
V_20 -> V_34 = V_36 ;
* V_12 |= V_52 ;
return V_50 ;
}
if ( ! V_32 )
V_32 = & V_27 -> V_56 ;
F_18 (ownlocks, tmp, &res->lr_granted) {
V_2 = F_14 ( V_32 , struct V_1 , V_14 ) ;
if ( ! F_1 ( V_2 , V_3 ) )
break;
if ( V_2 -> V_47 == V_11 ) {
if ( ( V_3 -> V_4 . V_5 . V_8 >
( V_2 -> V_4 . V_5 . V_9 + 1 ) )
&& ( V_2 -> V_4 . V_5 . V_9 !=
V_57 ) )
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
if ( V_35 ) {
F_3 ( V_2 , V_11 , * V_12 ) ;
} else {
V_3 = V_2 ;
V_35 = 1 ;
}
continue;
}
if ( V_3 -> V_4 . V_5 . V_8 >
V_2 -> V_4 . V_5 . V_9 )
continue;
if ( V_3 -> V_4 . V_5 . V_9 <
V_2 -> V_4 . V_5 . V_8 )
break;
++ V_37 ;
if ( V_3 -> V_4 . V_5 . V_8 <=
V_2 -> V_4 . V_5 . V_8 ) {
if ( V_3 -> V_4 . V_5 . V_9 <
V_2 -> V_4 . V_5 . V_9 ) {
V_2 -> V_4 . V_5 . V_8 =
V_3 -> V_4 . V_5 . V_9 + 1 ;
break;
}
F_3 ( V_2 , V_2 -> V_34 , * V_12 ) ;
continue;
}
if ( V_3 -> V_4 . V_5 . V_9 >=
V_2 -> V_4 . V_5 . V_9 ) {
V_2 -> V_4 . V_5 . V_9 =
V_3 -> V_4 . V_5 . V_8 - 1 ;
continue;
}
if ( ! V_33 ) {
F_19 ( V_20 ) ;
V_33 = F_20 ( V_30 , & V_27 -> V_58 , V_59 ,
V_2 -> V_47 , & V_40 ,
NULL , 0 , V_60 ) ;
F_21 ( V_20 ) ;
if ( ! V_33 ) {
F_3 ( V_20 , V_2 -> V_47 ,
* V_12 ) ;
* V_23 = - V_61 ;
return V_50 ;
}
goto V_45;
}
V_38 = 1 ;
V_33 -> V_47 = V_2 -> V_47 ;
V_33 -> V_4 . V_5 . V_42 =
V_3 -> V_4 . V_5 . V_42 ;
V_33 -> V_4 . V_5 . V_6 =
V_3 -> V_4 . V_5 . V_6 ;
V_33 -> V_4 . V_5 . V_8 =
V_2 -> V_4 . V_5 . V_8 ;
V_33 -> V_4 . V_5 . V_9 =
V_3 -> V_4 . V_5 . V_8 - 1 ;
V_2 -> V_4 . V_5 . V_8 =
V_3 -> V_4 . V_5 . V_9 + 1 ;
V_33 -> V_62 = V_2 -> V_62 ;
if ( V_2 -> V_7 ) {
V_33 -> V_7 = F_22 ( V_2 -> V_7 ,
V_33 ) ;
if ( V_33 -> V_7 -> V_63 &&
F_6 ( & V_33 -> V_64 ) )
F_23 ( V_33 -> V_7 -> V_63 ,
& V_33 -> V_65 ,
& V_33 -> V_64 ) ;
}
if ( * V_12 == V_15 )
F_24 ( V_33 ,
V_2 -> V_47 ) ;
F_17 ( V_27 , V_32 , V_33 ) ;
F_25 ( V_33 ) ;
break;
}
if ( V_38 == 0 && V_33 )
F_9 ( V_33 ) ;
V_20 -> V_47 = V_20 -> V_34 ;
if ( ! V_35 ) {
F_7 ( & V_20 -> V_14 ) ;
F_17 ( V_27 , V_32 , V_20 ) ;
}
if ( * V_12 != V_15 ) {
F_26 ( L_3 ) ;
F_27 () ;
}
if ( V_35 )
F_3 ( V_20 , V_11 , * V_12 ) ;
F_28 ( V_66 , V_27 ) ;
return V_55 ;
}
static void
F_29 ( void * V_67 )
{
struct V_1 * V_2 ;
V_2 = ( (struct V_68 * ) V_67 ) -> V_69 ;
F_21 ( V_2 ) ;
V_2 -> V_16 |= V_19 ;
F_19 ( V_2 ) ;
}
int
F_30 ( struct V_1 * V_2 , T_1 V_12 , void * V_67 )
{
struct V_70 * V_71 = V_2 -> V_72 ;
struct V_73 * V_74 ;
struct V_75 * V_76 = NULL ;
struct V_68 V_77 ;
struct V_78 V_79 ;
enum V_22 V_23 ;
int V_80 = 0 ;
F_12 ( V_41 , L_4 ,
V_12 , V_67 , V_71 ) ;
if ( ( V_2 -> V_16 & ( V_17 | V_18 ) ) ==
( V_17 | V_18 ) ) {
if ( V_2 -> V_34 == V_2 -> V_47 &&
V_2 -> V_47 != V_36 && ! V_67 )
F_31 ( V_2 , V_2 -> V_34 ) ;
F_32 ( & V_2 -> V_81 ) ;
return 0 ;
}
F_5 ( V_12 != V_15 ) ;
if ( ! ( V_12 & ( V_82 | V_54 |
V_83 ) ) ) {
if ( ! V_67 )
goto V_84;
F_32 ( & V_2 -> V_81 ) ;
return 0 ;
}
F_4 ( V_2 , L_5 ) ;
V_77 . V_69 = V_2 ;
V_74 = F_33 ( V_2 -> V_62 ) ;
if ( V_74 )
V_76 = V_74 -> V_85 . V_86 . V_87 ;
if ( V_76 ) {
F_34 ( & V_76 -> V_88 ) ;
V_77 . V_89 = V_76 -> V_90 ;
F_35 ( & V_76 -> V_88 ) ;
}
V_79 = F_36 ( 0 , NULL , F_29 , & V_77 ) ;
V_80 = F_37 ( V_2 -> V_81 , F_38 ( V_2 ) , & V_79 ) ;
if ( V_80 ) {
F_4 ( V_2 , L_6 ,
V_80 ) ;
return V_80 ;
}
V_84:
F_39 ( V_91 , 10 ) ;
if ( V_2 -> V_16 & V_92 ) {
F_4 ( V_2 , L_7 ) ;
return 0 ;
}
if ( V_2 -> V_16 & V_17 ) {
F_4 ( V_2 , L_8 ) ;
return - V_93 ;
}
if ( V_80 ) {
F_4 ( V_2 , L_6 ,
V_80 ) ;
return V_80 ;
}
F_4 ( V_2 , L_9 ) ;
F_21 ( V_2 ) ;
F_7 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_16 & V_94 ) {
F_4 ( V_2 , L_10 ) ;
V_80 = - V_95 ;
} else if ( V_12 & V_51 ) {
F_3 ( V_2 , V_71 -> V_96 , V_15 ) ;
switch ( V_2 -> V_47 ) {
case V_97 :
V_71 -> V_96 = V_98 ;
break;
case V_99 :
V_71 -> V_96 = V_100 ;
break;
default:
V_71 -> V_96 = V_101 ;
}
V_71 -> V_102 = ( V_103 ) V_2 -> V_4 . V_5 . V_42 ;
V_71 -> V_104 = ( V_105 ) V_2 -> V_4 . V_5 . V_8 ;
V_71 -> V_106 = ( V_105 ) V_2 -> V_4 . V_5 . V_9 ;
} else {
T_1 V_107 = V_15 ;
F_10 ( V_2 , & V_107 , 1 , & V_23 , NULL ) ;
}
F_19 ( V_2 ) ;
return V_80 ;
}
void F_40 ( const T_2 * V_108 ,
T_3 * V_109 )
{
memset ( V_109 , 0 , sizeof( * V_109 ) ) ;
V_109 -> V_5 . V_8 = V_108 -> V_5 . V_110 ;
V_109 -> V_5 . V_9 = V_108 -> V_5 . V_111 ;
V_109 -> V_5 . V_42 = V_108 -> V_5 . V_112 ;
V_109 -> V_5 . V_6 = V_108 -> V_5 . V_112 ;
}
void F_41 ( const T_2 * V_108 ,
T_3 * V_109 )
{
memset ( V_109 , 0 , sizeof( * V_109 ) ) ;
V_109 -> V_5 . V_8 = V_108 -> V_5 . V_110 ;
V_109 -> V_5 . V_9 = V_108 -> V_5 . V_111 ;
V_109 -> V_5 . V_42 = V_108 -> V_5 . V_112 ;
V_109 -> V_5 . V_6 = V_108 -> V_5 . V_113 ;
}
void F_42 ( const T_3 * V_109 ,
T_2 * V_108 )
{
memset ( V_108 , 0 , sizeof( * V_108 ) ) ;
V_108 -> V_5 . V_110 = V_109 -> V_5 . V_8 ;
V_108 -> V_5 . V_111 = V_109 -> V_5 . V_9 ;
V_108 -> V_5 . V_112 = V_109 -> V_5 . V_42 ;
V_108 -> V_5 . V_113 = V_109 -> V_5 . V_6 ;
}
