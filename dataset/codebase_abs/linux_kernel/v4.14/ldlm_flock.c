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
V_13 , V_11 , V_12 ) ;
F_5 ( F_6 ( & V_2 -> V_14 ) ) ;
F_7 ( & V_2 -> V_15 ) ;
if ( V_12 == V_16 ) {
V_2 -> V_17 |= V_18 | V_19 ;
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
const struct V_39 V_40 = { } ;
F_12 ( V_41 ,
L_2 ,
* V_12 , V_3 -> V_4 . V_5 . V_6 ,
V_3 -> V_4 . V_5 . V_42 , V_11 ,
V_20 -> V_4 . V_5 . V_8 ,
V_20 -> V_4 . V_5 . V_9 ) ;
* V_23 = V_43 ;
V_20 -> V_44 = NULL ;
V_45:
if ( ( * V_12 == V_16 ) || ( V_11 == V_36 ) ) {
F_13 (tmp, &res->lr_granted) {
V_2 = F_14 ( V_31 , struct V_1 ,
V_15 ) ;
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
V_15 ) ;
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
V_2 = F_14 ( V_32 , struct V_1 , V_15 ) ;
if ( ! F_1 ( V_2 , V_3 ) )
break;
if ( V_2 -> V_47 == V_11 ) {
if ( ( V_3 -> V_4 . V_5 . V_8 >
( V_2 -> V_4 . V_5 . V_9 + 1 ) ) &&
( V_2 -> V_4 . V_5 . V_9 != V_57 ) )
continue;
if ( ( V_3 -> V_4 . V_5 . V_9 <
( V_2 -> V_4 . V_5 . V_8 - 1 ) ) &&
( V_2 -> V_4 . V_5 . V_8 != 0 ) )
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
if ( F_22 ( V_33 ) ) {
F_3 ( V_20 , V_2 -> V_47 ,
* V_12 ) ;
* V_23 = F_23 ( V_33 ) ;
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
V_33 -> V_61 = V_2 -> V_61 ;
if ( V_2 -> V_7 ) {
V_33 -> V_7 = F_24 ( V_2 -> V_7 ,
V_33 ) ;
if ( V_33 -> V_7 -> V_62 &&
F_6 ( & V_33 -> V_63 ) )
F_25 ( V_33 -> V_7 -> V_62 ,
& V_33 -> V_64 ,
& V_33 -> V_63 ) ;
}
if ( * V_12 == V_16 )
F_26 ( V_33 ,
V_2 -> V_47 ) ;
F_17 ( V_27 , V_32 , V_33 ) ;
F_27 ( V_33 ) ;
break;
}
if ( V_38 == 0 && V_33 )
F_9 ( V_33 ) ;
V_20 -> V_47 = V_20 -> V_34 ;
if ( ! V_35 ) {
F_7 ( & V_20 -> V_15 ) ;
F_17 ( V_27 , V_32 , V_20 ) ;
}
if ( * V_12 != V_16 ) {
F_28 ( L_3 ) ;
F_29 () ;
}
if ( V_35 )
F_3 ( V_20 , V_11 , * V_12 ) ;
F_30 ( V_65 , V_27 ) ;
return V_55 ;
}
static void
F_31 ( void * V_66 )
{
struct V_1 * V_2 ;
V_2 = ( (struct V_67 * ) V_66 ) -> V_68 ;
F_21 ( V_2 ) ;
F_32 ( V_2 ) ;
F_19 ( V_2 ) ;
}
int
F_33 ( struct V_1 * V_2 , T_1 V_12 , void * V_66 )
{
struct V_69 * V_70 = V_2 -> V_71 ;
struct V_72 * V_73 ;
struct V_74 * V_75 = NULL ;
struct V_67 V_76 ;
struct V_77 V_78 ;
enum V_22 V_23 ;
int V_79 = 0 ;
F_34 ( V_80 , 4 ) ;
if ( F_35 ( V_81 ) ) {
F_21 ( V_2 ) ;
V_2 -> V_17 |= V_82 ;
F_19 ( V_2 ) ;
F_34 ( V_81 , 4 ) ;
}
F_12 ( V_41 , L_4 ,
V_12 , V_66 , V_70 ) ;
F_5 ( V_12 != V_16 ) ;
if ( V_12 & V_83 )
goto V_84;
if ( ! ( V_12 & V_85 ) ) {
if ( ! V_66 )
goto V_84;
F_36 ( & V_2 -> V_86 ) ;
return 0 ;
}
F_4 ( V_2 , L_5 ) ;
V_76 . V_68 = V_2 ;
V_73 = F_37 ( V_2 -> V_61 ) ;
if ( V_73 )
V_75 = V_73 -> V_87 . V_88 . V_89 ;
if ( V_75 ) {
F_38 ( & V_75 -> V_90 ) ;
V_76 . V_91 = V_75 -> V_92 ;
F_39 ( & V_75 -> V_90 ) ;
}
V_78 = F_40 ( 0 , NULL , F_31 , & V_76 ) ;
V_79 = F_41 ( V_2 -> V_86 , F_42 ( V_2 ) , & V_78 ) ;
if ( V_79 ) {
F_4 ( V_2 , L_6 ,
V_79 ) ;
return V_79 ;
}
V_84:
F_34 ( V_93 , 10 ) ;
if ( F_35 ( V_94 ) ) {
F_21 ( V_2 ) ;
V_2 -> V_17 |= V_95 | V_19 ;
F_19 ( V_2 ) ;
F_34 ( V_94 , 4 ) ;
}
if ( F_35 ( V_96 ) ) {
F_21 ( V_2 ) ;
V_2 -> V_17 |= V_82 |
V_95 | V_19 ;
F_19 ( V_2 ) ;
F_34 ( V_96 , 4 ) ;
}
F_21 ( V_2 ) ;
if ( F_43 ( V_2 ) ) {
F_19 ( V_2 ) ;
F_4 ( V_2 , L_7 ) ;
return - V_97 ;
}
F_44 ( V_2 ) ;
if ( F_45 ( V_2 ) || F_46 ( V_2 ) ) {
int V_11 ;
if ( V_12 & V_51 )
F_5 ( F_47 ( V_2 ) ) ;
if ( F_47 ( V_2 ) || F_46 ( V_2 ) )
V_11 = V_70 -> V_98 ;
else
V_11 = V_2 -> V_47 ;
if ( F_46 ( V_2 ) ) {
F_4 ( V_2 , L_8 ) ;
V_79 = - V_99 ;
}
F_3 ( V_2 , V_11 , V_16 ) ;
F_19 ( V_2 ) ;
F_36 ( & V_2 -> V_86 ) ;
return V_79 ? : - V_97 ;
}
F_4 ( V_2 , L_9 ) ;
if ( V_12 & V_51 ) {
F_5 ( F_47 ( V_2 ) ) ;
F_3 ( V_2 , V_70 -> V_98 , V_16 ) ;
switch ( V_2 -> V_47 ) {
case V_100 :
V_70 -> V_98 = V_101 ;
break;
case V_102 :
V_70 -> V_98 = V_103 ;
break;
default:
V_70 -> V_98 = V_104 ;
}
V_70 -> V_105 = - ( V_106 ) V_2 -> V_4 . V_5 . V_42 ;
V_70 -> V_107 = ( V_108 ) V_2 -> V_4 . V_5 . V_8 ;
V_70 -> V_109 = ( V_108 ) V_2 -> V_4 . V_5 . V_9 ;
} else {
T_1 V_110 = V_16 ;
F_10 ( V_2 , & V_110 , 1 , & V_23 , NULL ) ;
}
F_19 ( V_2 ) ;
return V_79 ;
}
void F_48 ( const union V_111 * V_112 ,
union V_113 * V_114 )
{
V_114 -> V_5 . V_8 = V_112 -> V_5 . V_115 ;
V_114 -> V_5 . V_9 = V_112 -> V_5 . V_116 ;
V_114 -> V_5 . V_42 = V_112 -> V_5 . V_117 ;
V_114 -> V_5 . V_6 = V_112 -> V_5 . V_118 ;
}
void F_49 ( const union V_113 * V_114 ,
union V_111 * V_112 )
{
memset ( V_112 , 0 , sizeof( * V_112 ) ) ;
V_112 -> V_5 . V_115 = V_114 -> V_5 . V_8 ;
V_112 -> V_5 . V_116 = V_114 -> V_5 . V_9 ;
V_112 -> V_5 . V_117 = V_114 -> V_5 . V_42 ;
V_112 -> V_5 . V_118 = V_114 -> V_5 . V_6 ;
}
