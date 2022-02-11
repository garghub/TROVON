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
if ( V_12 == V_15 && ! F_8 ( V_2 ) ) {
V_2 -> V_16 |= V_17 | V_18 ;
F_9 ( V_2 , V_11 ) ;
}
F_10 ( V_2 ) ;
}
static int F_11 ( struct V_1 * V_19 , T_1 * V_12 ,
int V_20 , enum V_21 * V_22 ,
struct V_23 * V_24 )
{
struct V_25 * V_26 = V_19 -> V_27 ;
struct V_28 * V_29 = F_12 ( V_26 ) ;
struct V_23 * V_30 ;
struct V_23 * V_31 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_1 * V_3 = V_19 ;
struct V_1 * V_32 = NULL ;
enum V_10 V_11 = V_19 -> V_33 ;
int V_34 = ( V_11 == V_35 ) ;
int V_36 = 0 ;
int V_37 = 0 ;
const struct V_38 V_39 = { NULL } ;
F_13 ( V_40 ,
L_2 ,
* V_12 , V_3 -> V_4 . V_5 . V_6 ,
V_3 -> V_4 . V_5 . V_41 , V_11 ,
V_19 -> V_4 . V_5 . V_8 ,
V_19 -> V_4 . V_5 . V_9 ) ;
* V_22 = V_42 ;
V_19 -> V_43 = NULL ;
V_44:
if ( ( * V_12 == V_15 ) || ( V_11 == V_35 ) ) {
F_14 (tmp, &res->lr_granted) {
V_2 = F_15 ( V_30 , struct V_1 ,
V_14 ) ;
if ( F_1 ( V_2 , V_19 ) ) {
V_31 = V_30 ;
break;
}
}
} else {
int V_45 = 0 ;
F_16 ( V_11 ) ;
F_14 (tmp, &res->lr_granted) {
V_2 = F_15 ( V_30 , struct V_1 ,
V_14 ) ;
if ( F_1 ( V_2 , V_19 ) ) {
if ( ! V_31 )
V_31 = V_30 ;
continue;
}
if ( F_17 ( V_2 -> V_46 , V_11 ) )
continue;
if ( ! F_2 ( V_2 , V_19 ) )
continue;
if ( ! V_20 ) {
V_45 = 1 ;
continue;
}
if ( * V_12 & V_47 ) {
F_3 ( V_19 , V_11 , * V_12 ) ;
* V_22 = - V_48 ;
return V_49 ;
}
if ( * V_12 & V_50 ) {
F_3 ( V_19 , V_11 , * V_12 ) ;
V_19 -> V_33 = V_2 -> V_46 ;
V_19 -> V_4 . V_5 . V_41 =
V_2 -> V_4 . V_5 . V_41 ;
V_19 -> V_4 . V_5 . V_8 =
V_2 -> V_4 . V_5 . V_8 ;
V_19 -> V_4 . V_5 . V_9 =
V_2 -> V_4 . V_5 . V_9 ;
* V_12 |= V_51 ;
return V_49 ;
}
F_18 ( V_26 , & V_26 -> V_52 , V_19 ) ;
* V_12 |= V_53 ;
return V_49 ;
}
if ( V_45 )
return V_54 ;
}
if ( * V_12 & V_50 ) {
F_3 ( V_19 , V_11 , * V_12 ) ;
V_19 -> V_33 = V_35 ;
* V_12 |= V_51 ;
return V_49 ;
}
if ( ! V_31 )
V_31 = & V_26 -> V_55 ;
F_19 (ownlocks, tmp, &res->lr_granted) {
V_2 = F_15 ( V_31 , struct V_1 , V_14 ) ;
if ( ! F_1 ( V_2 , V_3 ) )
break;
if ( V_2 -> V_46 == V_11 ) {
if ( ( V_3 -> V_4 . V_5 . V_8 >
( V_2 -> V_4 . V_5 . V_9 + 1 ) )
&& ( V_2 -> V_4 . V_5 . V_9 !=
V_56 ) )
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
if ( V_34 ) {
F_3 ( V_2 , V_11 , * V_12 ) ;
} else {
V_3 = V_2 ;
V_34 = 1 ;
}
continue;
}
if ( V_3 -> V_4 . V_5 . V_8 >
V_2 -> V_4 . V_5 . V_9 )
continue;
if ( V_3 -> V_4 . V_5 . V_9 <
V_2 -> V_4 . V_5 . V_8 )
break;
++ V_36 ;
if ( V_3 -> V_4 . V_5 . V_8 <=
V_2 -> V_4 . V_5 . V_8 ) {
if ( V_3 -> V_4 . V_5 . V_9 <
V_2 -> V_4 . V_5 . V_9 ) {
V_2 -> V_4 . V_5 . V_8 =
V_3 -> V_4 . V_5 . V_9 + 1 ;
break;
}
F_3 ( V_2 , V_2 -> V_33 , * V_12 ) ;
continue;
}
if ( V_3 -> V_4 . V_5 . V_9 >=
V_2 -> V_4 . V_5 . V_9 ) {
V_2 -> V_4 . V_5 . V_9 =
V_3 -> V_4 . V_5 . V_8 - 1 ;
continue;
}
if ( ! V_32 ) {
F_20 ( V_19 ) ;
V_32 = F_21 ( V_29 , & V_26 -> V_57 , V_58 ,
V_2 -> V_46 , & V_39 ,
NULL , 0 , V_59 ) ;
F_22 ( V_19 ) ;
if ( ! V_32 ) {
F_3 ( V_19 , V_2 -> V_46 ,
* V_12 ) ;
* V_22 = - V_60 ;
return V_49 ;
}
goto V_44;
}
V_37 = 1 ;
V_32 -> V_46 = V_2 -> V_46 ;
V_32 -> V_4 . V_5 . V_41 =
V_3 -> V_4 . V_5 . V_41 ;
V_32 -> V_4 . V_5 . V_6 =
V_3 -> V_4 . V_5 . V_6 ;
V_32 -> V_4 . V_5 . V_8 =
V_2 -> V_4 . V_5 . V_8 ;
V_32 -> V_4 . V_5 . V_9 =
V_3 -> V_4 . V_5 . V_8 - 1 ;
V_2 -> V_4 . V_5 . V_8 =
V_3 -> V_4 . V_5 . V_9 + 1 ;
V_32 -> V_61 = V_2 -> V_61 ;
if ( V_2 -> V_7 ) {
V_32 -> V_7 = F_23 ( V_2 -> V_7 ,
V_32 ) ;
if ( V_32 -> V_7 -> V_62 &&
F_6 ( & V_32 -> V_63 ) )
F_24 ( V_32 -> V_7 -> V_62 ,
& V_32 -> V_64 ,
& V_32 -> V_63 ) ;
}
if ( * V_12 == V_15 )
F_25 ( V_32 ,
V_2 -> V_46 ) ;
F_18 ( V_26 , V_31 , V_32 ) ;
F_26 ( V_32 ) ;
break;
}
if ( V_37 == 0 && V_32 )
F_10 ( V_32 ) ;
V_19 -> V_46 = V_19 -> V_33 ;
if ( ! V_34 ) {
F_7 ( & V_19 -> V_14 ) ;
F_18 ( V_26 , V_31 , V_19 ) ;
}
if ( * V_12 != V_15 ) {
F_27 ( L_3 ) ;
F_28 () ;
}
if ( V_34 )
F_3 ( V_19 , V_11 , * V_12 ) ;
F_29 ( V_65 , V_26 ) ;
return V_54 ;
}
static void
F_30 ( void * V_66 )
{
struct V_1 * V_2 ;
V_2 = ( (struct V_67 * ) V_66 ) -> V_68 ;
F_22 ( V_2 ) ;
F_31 ( V_2 ) ;
F_20 ( V_2 ) ;
}
int
F_32 ( struct V_1 * V_2 , T_1 V_12 , void * V_66 )
{
struct V_69 * V_70 = V_2 -> V_71 ;
struct V_72 * V_73 ;
struct V_74 * V_75 = NULL ;
struct V_67 V_76 ;
struct V_77 V_78 ;
enum V_21 V_22 ;
int V_79 = 0 ;
F_13 ( V_40 , L_4 ,
V_12 , V_66 , V_70 ) ;
if ( ( V_2 -> V_16 & ( V_80 | V_17 ) ) ==
( V_80 | V_17 ) ) {
if ( V_2 -> V_33 == V_2 -> V_46 &&
V_2 -> V_46 != V_35 && ! V_66 )
F_33 ( V_2 , V_2 -> V_33 ) ;
F_34 ( & V_2 -> V_81 ) ;
return 0 ;
}
F_5 ( V_12 != V_15 ) ;
if ( ! ( V_12 & ( V_82 | V_53 |
V_83 ) ) ) {
if ( ! V_66 )
goto V_84;
F_34 ( & V_2 -> V_81 ) ;
return 0 ;
}
F_4 ( V_2 , L_5 ) ;
V_76 . V_68 = V_2 ;
V_73 = F_35 ( V_2 -> V_61 ) ;
if ( V_73 )
V_75 = V_73 -> V_85 . V_86 . V_87 ;
if ( V_75 ) {
F_36 ( & V_75 -> V_88 ) ;
V_76 . V_89 = V_75 -> V_90 ;
F_37 ( & V_75 -> V_88 ) ;
}
V_78 = F_38 ( 0 , NULL , F_30 , & V_76 ) ;
V_79 = F_39 ( V_2 -> V_81 , F_40 ( V_2 ) , & V_78 ) ;
if ( V_79 ) {
F_4 ( V_2 , L_6 ,
V_79 ) ;
return V_79 ;
}
V_84:
F_41 ( V_91 , 10 ) ;
if ( F_8 ( V_2 ) ) {
F_4 ( V_2 , L_7 ) ;
return - V_92 ;
}
F_4 ( V_2 , L_8 ) ;
F_22 ( V_2 ) ;
if ( F_42 ( V_2 ) ) {
F_20 ( V_2 ) ;
F_4 ( V_2 , L_9 ) ;
return 0 ;
}
F_7 ( & V_2 -> V_14 ) ;
if ( F_43 ( V_2 ) ) {
F_4 ( V_2 , L_10 ) ;
V_79 = - V_93 ;
} else if ( V_12 & V_50 ) {
F_3 ( V_2 , V_70 -> V_94 , V_15 ) ;
switch ( V_2 -> V_46 ) {
case V_95 :
V_70 -> V_94 = V_96 ;
break;
case V_97 :
V_70 -> V_94 = V_98 ;
break;
default:
V_70 -> V_94 = V_99 ;
}
V_70 -> V_100 = ( V_101 ) V_2 -> V_4 . V_5 . V_41 ;
V_70 -> V_102 = ( V_103 ) V_2 -> V_4 . V_5 . V_8 ;
V_70 -> V_104 = ( V_103 ) V_2 -> V_4 . V_5 . V_9 ;
} else {
T_1 V_105 = V_15 ;
F_11 ( V_2 , & V_105 , 1 , & V_22 , NULL ) ;
}
F_20 ( V_2 ) ;
return V_79 ;
}
void F_44 ( const T_2 * V_106 ,
T_3 * V_107 )
{
memset ( V_107 , 0 , sizeof( * V_107 ) ) ;
V_107 -> V_5 . V_8 = V_106 -> V_5 . V_108 ;
V_107 -> V_5 . V_9 = V_106 -> V_5 . V_109 ;
V_107 -> V_5 . V_41 = V_106 -> V_5 . V_110 ;
V_107 -> V_5 . V_6 = V_106 -> V_5 . V_110 ;
}
void F_45 ( const T_2 * V_106 ,
T_3 * V_107 )
{
memset ( V_107 , 0 , sizeof( * V_107 ) ) ;
V_107 -> V_5 . V_8 = V_106 -> V_5 . V_108 ;
V_107 -> V_5 . V_9 = V_106 -> V_5 . V_109 ;
V_107 -> V_5 . V_41 = V_106 -> V_5 . V_110 ;
V_107 -> V_5 . V_6 = V_106 -> V_5 . V_111 ;
}
void F_46 ( const T_3 * V_107 ,
T_2 * V_106 )
{
memset ( V_106 , 0 , sizeof( * V_106 ) ) ;
V_106 -> V_5 . V_108 = V_107 -> V_5 . V_8 ;
V_106 -> V_5 . V_109 = V_107 -> V_5 . V_9 ;
V_106 -> V_5 . V_110 = V_107 -> V_5 . V_41 ;
V_106 -> V_5 . V_111 = V_107 -> V_5 . V_6 ;
}
